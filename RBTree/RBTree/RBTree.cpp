#define _CRT_SECURE_NO_WARNINGS

#include<utility>
#include<iostream>
using namespace std;

enum COLOR
{
	BLACK,
	RED
};

template <class K, class V>
struct RBNode
{
	RBNode<K, V>* _left;
	RBNode<K, V>* _right;
	RBNode<K, V>* _parent;
	pair<K, V> _value;
	COLOR _color;

	RBNode(const pair<K,V>& value = pair<K, V>())
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_value(value)
		,_color(RED)
	{}
};

template <class K, class V>
class RBTree
{
public:
	typedef RBNode<K, V> Node;
	typedef Node* pNode;

	RBTree()
	{
		_header = new Node();
		_header->_left = _header;
		_header->_right = _header;
	}

	bool insert(const pair<K, V>& value)
	{
		//�������ڵ�
		if (_header->_parent == nullptr)
		{
			pNode root = new Node(value);
			root->_color = BLACK;
			root->_parent = _header;
			_header->_parent = root;

			_header->_left = root;
			_header->_right = root;
			return true;
		}
		//����λ��
		pNode cur = _header->_parent;
		pNode parent = nullptr;
		while (cur)
		{
			parent = cur;
			//����Keyֵȷ��λ��

			//λ����ͬ����ʧ��
			if (cur->_value.first == value.first)
				return false;
			else if (cur->_value.first > value.first)
				cur = cur->_left;
			else
				cur = cur->_right;
		}

		cur = new Node(value);
		if (parent->_value.first > cur->_value.first)
			parent->_left = cur;
		else
			parent->_right = cur;
		cur->_parent = parent;

		//�����͸���(��ɫ)
		while (cur != _header->_parent && cur->_parent->_color == RED)
		{
			parent = _cur->_parent;
			pNode gfather = parent->_parent;
			//�������ұ�
			if (gfather->_left == parent)
			{
				pNode uncle = gfather->_right;
				if (uncle && uncle->_color == RED)
				{
					parent->_color = uncle->_color = BLACK;
					gfather->_color = RED;
					cur = gfather;
				}
				else 
				{
					if (cur == parent->_right)
					{
						RotateL(parent);
						swap(cur, parent);
					}
					//��Ҫ�������� ��ת���������
					RotateR(gfather);
					gfather->_color = RED;
					parent->_color = BLACK;
					break;
				}
			}
			//���������
			else
			{
				pNode uncle = gfather->_left;
				if (uncle && uncle->_color == RED)
				{
					parent->_color = uncle->_color = BLACK;
					gfather->_color = RED;
					cur = gfather;
				}
				else
				{
					if (cur == parent->_left)
					{
						RotateR(parent);
						swap(cur, parent);
					}
					//��Ҫ��������
					RotateL(gfather);
					gfather->_color = RED;
					parent->_color = BLACK;
					break;
				}
			}
		}

		_header->_parent = BLACK;

		//����_header->_left , _right;
		_header->_left = leftMost();
		_header->_right = rightMost();
	}



	void RotateR(pNode parent)
	{
		pNode subL = parent->_left;
		pNode subLR = subL->_right;

		subL->_right = parent;
		parent->_left = subLR;

		if (subLR)
			subLR->_parent = parent;

		if (parent != _header->_parent)
		{
			pNode gparent = parent->_parent;
			if (gparent->_left == parent)
				gparent->_left = subL;
			else
				gparent->_right = subL;
			subL->_parent = gparent;
		}
		else
		{
			_header->_parent = subL;
			subL->_parent = nullptr;
		}

		parent->_parent = subL;
		
	}


	void RotateL(pNode parent)
	{
		pNode subR = parent->_right;
		pNode subRL = subR->_left;

		subR->_left = parent;
		parent->_right = subRL;

		if (subRL)
			subRL->_parent = parent;

		if (parent != _header->_parent)
		{
			pNode gparent = parent->_parent;
			subR->_parent = gparent;
			if (gparent->_left == parent)
				gparent->_left = subR;
			else
				gparent->_right = subR;
		}
		else
		{
			_header->_parent = subR;
			subR->_parent = nullptr;
		}
		parent->_parent = subR;
	}

	pNode leftMost()
	{
		pNode cur = _header->_parent;
		while (cur && cur->_left != nullptr)
		{
			cur = cur->_left;
		}
		return cur
	}

	pNode rightMost()
	{
		pNode cur = _header->_parent;
		while (cur && cur->_right != nullptr)
		{
			cur = cur->_right;
		}
		return cur
	}

private:
	pNode _header;
};

int main()
{
	return 0;
}