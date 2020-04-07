#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

template <class T>
struct BSTNode
{
	BSTNode<T>* _left;
	BSTNode<T>* _right;
	T _value;

	BSTNode(const T& value = T())
		:_left(nullptr)
		,_right(nullptr)
		,_value(value)
	{}
};

template <class T>
class BSTree
{
public:
	typedef BSTNode<T> Node;
	typedef Node* pNode;

	pNode find(const T& value)
	{
		pNode cur = _root;
		while (cur)
		{
			if (cur->_value == value)
				return cur;
			else if (cur->_value > value)
				cur = cur->left;
			else
				cur = cur->right;
		}
		return cur;
	}

	bool insert(const T& value)
	{
		if (_root == nullptr)
		{
			_root = new Node(value);
			return true;
		}

		pNode cur = _root;
		pNode parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (cur->_value == value)
				return false;
			else if (cur->_value > value)
				cur = cur->_left;
			else
				cur = cur->_right;
		}
		cur = new Node(value);
		if (parent->_value > value)
			parent->_left = cur;
		else
			parent->_right = cur;
		return true;
	}

	bool erase(const T& value)
	{
		if (_root == nullptr)
			return false;
		pNode cur = _root;
		pNode parent = nullptr;
		while (cur)
		{
			if (cur->_value == value)
				break;
			else if (cur->_value > value)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				parent = cur;
				cur = cur->_right;
			}
		}
		//�жϽڵ��Ƿ����
		if (cur == nullptr)
			return false;
		
		//Ҫɾ����Ԫ�� �����û���κ�Ԫ�ص����
		if (cur->_left == nullptr)
		{
			if (cur != _root)
			{
				//���¸��ڵ�
				if (parent->_left == cur)
					parent->_left = cur->_right;
				else
					parent->_right = cur->_right;
			}
			else
				_root = cur->_right;
		}
		delete cur;
		cur = nullptr;
	}


	void _inOrder(pNode _root)
	{
		if (_root)
		{
			_inOrder(_root->_left);
			cout << _root->_value << " ";
			_inOrder(_root->_right);
		}
	}

	void inOrder()
	{
		_inOrder(_root);
	}

private:
	BSTNode<T>* _root = nullptr;
};

void test()
{
	BSTree<int> bst;
	cout << bst.insert(100) << endl;
	cout << bst.insert(1) << endl;
	cout << bst.insert(2) << endl;
	cout << bst.insert(10) << endl;
	cout << bst.insert(24) << endl;
	cout << bst.insert(4) << endl;
	bst.inOrder();
}
int main()
{
	test();
	return 0;
}