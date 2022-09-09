#include <iostream>
#include <string>
#include <list>

struct node {
    int value;
    int level;
    node* left;
    node* right;
};

int main(int argc, char* argv[]) {
    int levels = 10;
    bool balanced = true;
    if ( argc >= 2 ) {
        levels = std::atoi(argv[1]);
        if ( argc == 3 ) {
            balanced = std::atoi(argv[2])>0;
        }   
    }

    int counter = 0;

    node root {root.value = 0, root.level = 0};

    std::list<node*> nodes_for_next_level = {&root};
    while(true){
        if(nodes_for_next_level.empty()){
            std::cout << "Tree is built" << std::endl;
            break;
        }
        node current_node = *nodes_for_next_level.front();
        nodes_for_next_level.pop_front();
        if (current_node.level == levels) {
            continue;
        }
        current_node.left = new node {.value = ++counter, .level = current_node.level+1};
        current_node.right = new node {.value = ++counter, .level = current_node.level+1};
        nodes_for_next_level.push_back(current_node.left);
        nodes_for_next_level.push_back(current_node.right);
    }
    create_folder(root, ".");

    return 0;
}

void create_folder(node* _node, std::string _path) {
    std::string path = _path + std::string("/folder-") +std::to_string(_node->value);
    std::string command = "mkdir " + path;
    system(command.c_str());
    if (_node->left != nullptr) {
        create_folder(_node->left, path);
    }
    if (_node->right != nullptr) {
        create_folder(_node->right, path);
    }
}
