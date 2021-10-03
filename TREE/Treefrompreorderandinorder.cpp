/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };*/
 
class Solution {
public:
    int search(vector<int>& inorder,int data,int st,int end){
        int i=0;
        for(i=st;i<=end;i++){
            if(inorder[i]==data){
                break;
            }
        }
        return i;
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int st,int end){
        static int ind=0;
        if(st>end){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[ind++]);
        //if(st==end) return root;
        int mid=search(inorder,root->val,st,end);
        root->left=build(preorder,inorder,st,mid-1);
        root->right=build(preorder,inorder,mid+1,end);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder,inorder,0,inorder.size()-1);
    }
};