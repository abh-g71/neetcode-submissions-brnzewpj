/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void solve(TreeNode* root){
        if(root == NULL){
            return;
        }
       
        
            TreeNode* temp1 = root->left;
        
            TreeNode* temp2 = root->right;
        
        root->left = root->right;
        root->right = temp1;
        if(root->left){
            solve(root->left);
        }
        if(root->right){
            solve(root->right);
        }

    }
    TreeNode* invertTree(TreeNode* root) {
        solve(root);
        return root;
    }
};
