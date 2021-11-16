#pragma once

typedef struct Node Node;

Node* createTree(int key, char* value);

Node* addElement(Node* tree, int key, char* value);

Node* searchInTree(Node* tree, int key);

char* getValueInTree(Node* tree);

Node* leftmostChild(Node* tree);

void deleteValueAndKey(Node* tree);

void deleteElement(Node* tree, int key);

void deleteTree(Node* node);