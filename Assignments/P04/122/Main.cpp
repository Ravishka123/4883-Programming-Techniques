
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef struct node{
    int value;
    node * left;
    node * right;
}node;




void Remove(node * tree)
{
    if(tree == nullptr)
        return;

    Remove(tree->left);
    Remove(tree->right);
    delete tree;

    return;
}

int main(void)
{
    string str;
    while(cin >> str){
        node * tree = nullptr;
        bool not_complete = false;

        while(str != "()"){
            bool value_exists = false;
            int value = 0;
            string path;

            for(int i = 0; i < str.size(); ++i)
                if(str[i] >= '0' && str[i] <= '9'){
                    value_exists = true;
                    value = value * 10 + str[i] - '0';
                }
                else if(str[i] == 'L' || str[i] == 'R')
                    path = path + str[i];

            if(tree == nullptr){
                tree = new node;
                tree->value = -1;
                tree->left = nullptr;
                tree->right = nullptr;
            }

            node * tmp = tree;
            for(int i = 0; i < path.size(); ++i)
                if(path[i] == 'L'){
                    if(tmp->left == nullptr){
                        node * leftDir = new node;
                        leftDir->value = -1;
                        leftDir->left = nullptr;
                        leftDir->right = nullptr;

                        tmp->left = leftDir;
                        tmp = leftDir;
                    }
                    else
                        tmp = tmp->left;
                }
                else{
                    if(tmp->right == nullptr){
                        node * rightDir = new node;
                        rightDir->value = -1;
                        rightDir->left = nullptr;
                        rightDir->right = nullptr;

                        tmp->right = rightDir;
                        tmp = rightDir;
                    }
                    else
                        tmp = tmp->right;
                }
            if(value_exists){
                if(tmp->value != -1)
                    not_complete = true;
                tmp->value = value;
            }

            cin >> str;
        }

        vector <int> path;
        queue <node *> Queue;

        Queue.push(tree);

        while(!not_complete && !Queue.empty()){
            node * front = Queue.front();
            Queue.pop();
            if(front->value != -1)
                path.push_back(front->value);
            else
                not_complete = 1;

            if(front->left != nullptr)
                Queue.push(front->left);
            if(front->right != nullptr)
                Queue.push(front->right);
        }

        if(not_complete)
            cout << "not complete" << endl;
        else{
            cout << path[0];
            for(int i = 1; i < path.size(); ++i)
                cout << ' ' << path[i];
            cout << endl;
        }

        Remove(tree);
        tree = nullptr;
    }
    return 0;
}

