#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

Node* connect(Node* root) {
    if (!root) return NULL;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        Node* prev = NULL;

        for (int i = 0; i < size; ++i) {
            Node* current = q.front();
            q.pop();

            if (prev) {
                prev->next = current;
            }
            prev = current;

            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
    }

    return root;
}

void printNextPointers(Node* root) {
    Node* levelStart = root;
    while (levelStart) {
        Node* current = levelStart;
        levelStart = NULL;

        while (current) {
            cout << current->val << " -> ";
            if (!levelStart && (current->left || current->right)) {
                levelStart = current->left ? current->left : current->right;
            }
            current = current->next;
        }
        cout << "NULL" << endl;
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    root = connect(root);

    printNextPointers(root);

    return 0;
}