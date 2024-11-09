#include "a4_birthdayBST.hpp"

BirthdayBSTreeNode* BirthdayBST::insertNode_rec(BirthdayBSTreeNode* node, Birthday* value){
    if(root == nullptr){
        size++;
        root = node;
        return node;
    }
    BirthdayBSTreeNode* currentnode = root;
    while(true){
        if(compareBirthdaysByMD(currentnode->value, value)>0){
            if(currentnode->left == nullptr){
                currentnode->left = node;
                node->parent = currentnode;
                size++;
                return node;
            }else{
                currentnode = currentnode->left;
            }
        }else{
            if(currentnode->right == nullptr){
                currentnode->right = node;
                node->parent = currentnode;
                size++;
                return node;
            }else{
                currentnode = currentnode->right;
            }
        }
    }
    return node;
}




BirthdayBSTreeNode* BirthdayBST:: findNodeByYMDN_rec(BirthdayBSTreeNode* node, short year, short month, short day, string name){
    if (node == nullptr) {
        return nullptr;
    }
    BirthdayBSTreeNode* match_node = findNodeByMD_rec(node, month, day);
    if(match_node != nullptr){
        while(match_node->value->year !=year && node->value->name != name){
          match_node =findNodeByMD_rec(match_node->right, month, day);
          if(match_node == nullptr){
            return nullptr;
            break;
          }
        }
        return node;
    }
    else{
        return nullptr;
    }
}

BirthdayBSTreeNode* BirthdayBST::findNodeByMD_rec(BirthdayBSTreeNode* node, short month, short day) {
    if (node == nullptr) {
        return nullptr;
    }

    if (node->value->month == month && node->value->day == day) {
        return node;
    }

    if (node->value->month < month ||
        (node->value->month == month && node->value->day < day)) {
        return findNodeByMD_rec(node->right, month, day);         
    }

    return findNodeByMD_rec(node->left, month, day);
}  

void BirthdayBST::printAllNodeWithMatchingMD_rec(BirthdayBSTreeNode* node, ostream& os, short month, short day){
    if(findNodeByMD(month,day)==nullptr){
        cout<<"No such birthday on record."<<endl;
        cout<<"=================================================="<<endl;
    }
        BirthdayBSTreeNode* match = findNodeByMD_rec(node, month, day);
        while (match != nullptr && match->value->month==month && match->value->day==day){
            cout << match->value->year << "-" << match->value->month<< "-" << match->value->day << "\n" << match->value->name<<"\n"
            << match->value->knownFor <<endl; 
            cout<<"=================================================="<<endl;
            if(match->right!=nullptr){
                match = findNodeByMD_rec(match->right, month, day);
            }else {
                match = nullptr;
            }
        }
}


void BirthdayBST::inOrderPrint(ostream& os){
    inOrderPrint_rec(root, os);
}

void BirthdayBST:: deleteTree_rec(BirthdayBSTreeNode* node){
    if (node == nullptr) {
        return;
    }
    deleteTree_rec(node->left);
    deleteTree_rec(node->right);
    delete node->value;
    delete node;
}

BirthdayBSTreeNode* BirthdayBST::newNode(Birthday* value){
    BirthdayBSTreeNode* node = new BirthdayBSTreeNode;
    node->value = value;
    node->parent = nullptr;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}



BirthdayBST::BirthdayBST(){
    root = nullptr;
    size = 0;
}


int BirthdayBST::getSize(){
    return size;
}

void BirthdayBST::insertNode(Birthday* value){
    BirthdayBSTreeNode* newnode = newNode(value);
    insertNode_rec(newnode,value);
}



Birthday* BirthdayBST::findNodeByYMDN(short year, short month, short day, string name){
    BirthdayBSTreeNode* node = findNodeByYMDN_rec(root, year, month, day, name);
    if (node == nullptr) {
        cout << "Birthday added." << endl;
        cout<<"=================================================="<<endl;
        return nullptr;
    }
    else {
        cout << "An entry with the same birthday and name already exists. Nothing added." << endl;
        cout<<"=================================================="<<endl;
        if (node->value != nullptr) {
            return node->value;
        }
        else {
            return nullptr;
        }
    }
}

Birthday* BirthdayBST::findNodeByMD(short month, short day){
    BirthdayBSTreeNode* test = findNodeByMD_rec(root, month, day);
    if (test == nullptr) {
        return nullptr;
    }
    return test->value;
}

void BirthdayBST::printAllNodeWithMatchingMD(short month, short day, ostream& os){
    printAllNodeWithMatchingMD_rec(root,os,month,day);
}


void BirthdayBST:: inOrderPrint_rec(BirthdayBSTreeNode* node, ostream& os){
    if(node == nullptr){
        return;
    }
    else{
        inOrderPrint_rec(node->left, os);
         os << node->value->year << "-" << node->value->month<< "-"
        << node->value->day << endl << node->value->name<< endl 
        << node->value->knownFor <<endl; 
         os <<"=================================================="<<endl;
        inOrderPrint_rec(node->right, os);
    }
}


BirthdayBST::~BirthdayBST() {
    deleteTree_rec(root);
}

void BirthdayBST::savefile_rec(BirthdayBSTreeNode* node, std::ofstream& os) {
    if (node == nullptr) {
        return;
    } else {
        savefile_rec(node->left, os);
        os << node->value->year << "-" << node->value->month << "-";
        os << node->value->day << endl << node->value->name << endl;
        os << node->value->knownFor << endl;
        os << "==================================================" << endl;
        savefile_rec(node->right, os);
    }
}

void BirthdayBST::savefile(const string& filename) {
    ifstream file;
    file.open(filename);
    if(!file.is_open()){
        ofstream outfile(filename);
        savefile(filename);
        return;
    }
    ofstream save_file(filename, std::ofstream::trunc);
        savefile_rec(root, save_file);
        save_file.close();
        cout << "Entries saved successfully."<< endl;
        cout << getSize() <<" entries are saved." <<endl;
}
