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
Node* minValNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr) current = current->left;
    return current;
}

// Delete a node 
bool deleteNode(Node*& node, int val) {
    if (node == nullptr) return false;

    if (val < node->val) {
        return deleteNode(node->left, val);
    } else if (val > node->val) {
        return deleteNode(node->right, val);
    } else {
        // Handle node with one or no child
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            node = temp;
            return true;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            node = temp;
            return true;
        }
        Node* temp = minValNode(node->right);
        node->val = temp->val;
        return deleteNode(node->right, temp->val);
    }
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
    cout << "-------------Working on Binary Search Tree implementation-------------" << "\n                     Choose options to work on BST\n";
    while (true) {
        cout << "\n";
        cout << "\t\t1. Insert\n\t\t2. Search\n\t\t3. Delete\n\t\t4. InOrder Traversal\n\t\t5. PreOrder Traversal\n\t\t6. PostOrder Traversal\n\t\t7. Exit\n";
        cout << "\tEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\tEnter value to insert: ";
                cin >> val;
                rt = insert(rt, val);
                break;
            case 2:
                cout << "\tEnter value to search: ";
                cin >> val;
                if (search(rt, val))
                    cout << "\tValue found.\n";
                else
                    cout << "\tValue not found.\n";
                break;
            case 3:
                cout << "\tEnter value to delete: ";
                cin >> val;
                if (deleteNode(rt, val))
                    cout << "\tThe value is deleted.\n";
                else
                    cout << "\tValue not found to be deleted.\n";
                break;
            case 4:
                cout << "\tInOrder Traversal: ";
                inOrder(rt);
                cout << endl;
                break;
            case 5:
                cout << "\tPreOrder Traversal: ";
                preOrder(rt);
                cout << endl;
                break;
            case 6:
                cout << "\tPostOrder Traversal: ";
                postOrder(rt);
                cout << endl;
                break;
            case 7:
                return 0;
            default:
                cout << "\n\t\tInvalid choice.........\n";
        }
    }
}
