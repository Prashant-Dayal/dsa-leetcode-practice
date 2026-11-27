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
    TreeNode* minVal(TreeNode* node){
        while(node && node->left){
            node=node->left;
        }
        return node;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return root;
        }

        if(root->val < key){
            root->right=deleteNode(root->right,key);
        }else if(root->val > key){
        root->left=deleteNode(root->left,key);
        }
        else{
          if (!root->left) {
                TreeNode* rightChild = root->right;
                delete root;
                return rightChild;
        }
          if (!root->right) {
                TreeNode* leftChild = root->left;
                delete root;
                return leftChild;
        }

        TreeNode* successor = minVal(root->right);
            root->val = successor->val;
            root->right = deleteNode(root->right, successor->val);
    }
    return root;
    }
};