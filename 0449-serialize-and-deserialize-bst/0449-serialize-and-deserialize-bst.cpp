class Codec {
public:

    // Convert tree into string
    string serialize(TreeNode* root) {
        if (!root) return "";

        string out;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (!out.empty())
                out.push_back(',');

            if (curr == nullptr) {
                out.push_back('#');
            } else {
                out += to_string(curr->val);

                q.push(curr->left);
                q.push(curr->right);
            }
        }

        return out;
    }

    // Convert string back into tree
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        stringstream ss(data);
        string val;

        getline(ss, val, ',');
        TreeNode* root = new TreeNode(stoi(val));

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            // Create left child
            if (!getline(ss, val, ','))
                break;

            if (val != "#") {
                curr->left = new TreeNode(stoi(val));
                q.push(curr->left);
            }

            // Create right child
            if (!getline(ss, val, ','))
                break;

            if (val != "#") {
                curr->right = new TreeNode(stoi(val));
                q.push(curr->right);
            }
        }

        return root;
    }
};