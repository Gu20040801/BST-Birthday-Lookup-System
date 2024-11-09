#ifndef A4_BIRTHDAYBST_HPP
#define A4_BIRTHDAYBST_HPP

#include "a4_birthdaylib.hpp"
#include <fstream>
#include <string>
#include <iostream>



typedef struct node {
    Birthday* value;
    struct node* left;
    struct node* right;
    struct node* parent;    
} BirthdayBSTreeNode;

class BirthdayBST {
    private:
        BirthdayBSTreeNode* root;
        int size;       
        BirthdayBSTreeNode* insertNode_rec(BirthdayBSTreeNode* node, Birthday* value);       
        BirthdayBSTreeNode* findNodeByYMDN_rec(BirthdayBSTreeNode* node, short year, short month, short day, string name);
        BirthdayBSTreeNode* findNodeByMD_rec(BirthdayBSTreeNode* node, short month, short day);       
        void printAllNodeWithMatchingMD_rec(BirthdayBSTreeNode* node, ostream& os, short month, short day);
        void inOrderPrint_rec(BirthdayBSTreeNode* node, ostream& os);
        
        
        void deleteTree_rec(BirthdayBSTreeNode* node);
        
        BirthdayBSTreeNode* newNode(Birthday* value);
        void savefile_rec(BirthdayBSTreeNode* node, std::ofstream& os);
    public:
        
        BirthdayBST();
        
        int getSize();
        
        void insertNode(Birthday* value);
        
        
        Birthday* findNodeByYMDN(short year, short month, short day,
                                string name);
        
        Birthday* findNodeByMD(short month, short day);
        
        void printAllNodeWithMatchingMD(short month, short day, ostream& os);
        
        void inOrderPrint(ostream& os);
        
        ~BirthdayBST();
        void savefile(const string& filename);
};


#endif