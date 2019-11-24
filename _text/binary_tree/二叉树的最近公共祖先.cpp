#define _CRT_SECURE_NO_WARNINGS 1

//Letcode��

//ʹ��ջ��¼·���ķ�ʽ
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	void GetPath(TreeNode* root, TreeNode* p, stack<TreeNode*>& pst)
	{
		if (root == NULL)
			return;
		if (root->val != p->val)
		{
			pst.push(root);
			//ȥ���������ֵ
			GetPath(root->left, p, pst);
			//�����û���ҵ�
			if (pst.top() != p && root->left != NULL)
			{
				pst.pop();
				GetPath(root->right, p, pst);
				if (pst.top() != p && root->right != NULL)
					pst.pop();
			}
			else
			{
				GetPath(root->right, p, pst);
				if (pst.top() != p && root->right != NULL)
					pst.pop();
			}
			return;
		}
		else
		{
			pst.push(p);
		}
	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		stack<TreeNode*> pst;
		stack<TreeNode*> qst;
		GetPath(root, p, pst);
		GetPath(root, q, qst);
		while (pst.size() > qst.size())
		{
			pst.pop();
		}
		while (pst.size() < qst.size())
		{
			qst.pop();
		}
		while (((pst.top()->val) != (qst.top()->val)))
		{
			qst.pop();
			pst.pop();
		}
		TreeNode* tmp = pst.top();
		return tmp;
	}
};


//��һ��������
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		//�����ǰ��Ϊ�ջ��ߵ�ǰ��Ϊ p ���� qֱ�ӷ��ظ��ڵ�
		if (!root || root == p || root == q)
			return root;
		//��ȡ���Ľڵ�
		TreeNode *left = lowestCommonAncestor(root->left, p, q);
		//��ȡ�Ҳ�Ľڵ�
		TreeNode *right = lowestCommonAncestor(root->right, p, q);
		//������ڸ��ڵ������ ���ظ�
		if (left && right) return root;
		//���ڸ������� �ڸ���ͬһ�� ������һ��
		return left ? left : right;
	}
};