#include <iostream>
using namespace std;

// structure representing a node
struct Node {
    int val;
    Node* left;
    Node* right;
};

// create a new node 
Node* createNode(int val) {
    Node* newNode = new Node();
    newNode->val = val;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Insert value 
Node* insert(Node* node, int val) {
    if (node == nullptr) return createNode(val);

    if (val < node->val) {
        node->left = insert(node->left, val);
    } else {
        node->right = insert(node->right, val);
    }
    return node;
}

// Search value 
Node* search(Node* node, int val) {
    if (node == nullptr || node->val == val) return node;

    if (val < node->val) return search(node->left, val);

    return search(node->right, val);
}

// Find node with the minimum value in a subtree
Node* minValnode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr) current = current->left;
    return current;
}

// Delete a node 
Node* deleteNode(Node* node, int val) {
    if (node == nullptr) return node;

    if (val < node->val) {
        node->left = deleteNode(node->left, val);
    } else if (val > node->val) {
        node->right = deleteNode(node->right, val);
    } else {
        // Handle node with one or no child
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        Node* temp = minValnode(node->right);
        node->val = temp->val;
        // Remove the in-order successor
        node->right = deleteNode(node->right, temp->val);
    }
    return node;
}

//  in-order traversal
void inOrder(Node* node) {
    if (node == nullptr) return;
    inOrder(node->left);
    cout << node->val << " ";
    inOrder(node->right);
}

//  pre-order traversal 
void preOrder(Node* node) {
    if (node == nullptr) return;
    cout << node->val << " ";
    preOrder(node->left);
    preOrder(node->right);
}

//  post-order traversal 
void postOrder(Node* node) {
    if (node == nullptr) return;
    postOrder(node->left);
    postOrder(node->right);
    cout << node->val << " ";
}

int main() {
    Node* rt = nullptr;
    int choice, val;
    cout<<"-------------Working on Binary Search Tree implementation-------------"<<"\n                     Choose options to work on BST\n";
    while (true) {
    cout<<"\n";
        cout << "1. Insert\n2. Search\n3. Delete\n4. InOrder Traversal\n5. PreOrder Traversal\n6. PostOrder Traversal\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                rt = insert(rt, val);
                break;
            case 2:
                cout << "Enter value to search: ";
                cin >> val;
                if (search(rt, val))
                    cout << "Value found.\n";
                else
                    cout << "Value not found.\n";
                break;
            case 3:
                cout << "Enter value to delete: ";
                cin >> val;
                rt = deleteNode(rt, val);
                cout << "The value is deleted.\n";
                break;
            case 4:
                cout << "InOrder Traversal: ";
                inOrder(rt);
                cout << endl;
                break;
            case 5:
                cout << "PreOrder Traversal: ";
                preOrder(rt);
                cout << endl;
                break;
            case 6:
                cout << "PostOrder Traversal: ";
                postOrder(rt);
                cout << endl;
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
}
