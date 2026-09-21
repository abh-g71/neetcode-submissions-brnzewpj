/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return node;
        unordered_map<Node*,Node*>mp;

        mp[node] = new Node(node->val);

        queue<Node*>q;
        q.push(node);
        

        while(!q.empty()){
            Node* root = q.front();
            q.pop();

            for(auto i : root->neighbors){
                if(mp.find(i) == mp.end()){
                    mp[i] = new Node(i->val);
                    q.push(i);
                }
            
              mp[root]->neighbors.push_back(mp[i]);
            }
        }
        return mp[node];
    }
};
