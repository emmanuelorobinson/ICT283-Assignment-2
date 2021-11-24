#ifndef BST_H
#define BST_H
#include <iostream>

template <class T>
struct node
{
    T data;
    node* left;
    node* right;
};


template <class T>
class BST
{
public:
    BST()
    {
        root = nullptr;
    }
    ~BST();
    void Insert(T & data);
    void InOrder(void (*out) (T &data));
    void PreOrder(void (*out) (T &data));
    void PostOrder(void (*out) (T &data));
    bool Search(T &data);
    void DeleteTree();
    BST(const BST &newBST);
    BST& operator=(const BST &newBST);
    void CopyTree(node<T>* &newRoot, node<T>* oldRoot);

protected:

private:
    node<T>* root;
    void Insert(node<T>* root, node<T>* temp);
    void InOrder(node<T>* root,void (*out) (T &data));
    void PreOrder(node<T>* root, void (*out) (T &data));
    void PostOrder(node<T>* root, void (*out) (T &data));
    bool Search(node<T>* current, T &data);
    void DeleteTree(node<T>* &root);
};

template <class T>
BST<T>::~BST()
{
    DeleteTree();
}

template <class T>
void BST<T>::Insert(T & data)
{

    node<T>* temp = new node<T>;
    temp->data = data;
    temp->left = temp->right = nullptr;

    if(root == nullptr)
    {
        root = temp;
    }
    else
    {
        Insert(root, temp);
    }
}

template <class T>
void BST<T>::Insert(node<T>* root, node<T>* temp)
{
    if(temp->data < root->data)
    {
        if(root->left == nullptr)
        {
            root->left = temp;
        }
        else
        {
            Insert(root->left, temp);
        }
    }
    else
    {
        if(temp->data > root->data)
        {
            if(root->right == nullptr)
            {
                root->right = temp;
            }
            else
            {
                Insert(root->right, temp);
            }
        }

    }

}

template <class T>
void BST<T>::InOrder(void (*out) (T &data))
{

    if(root != nullptr)
    {
        InOrder(root, out);
    }
}

template <class T>
void BST<T>::InOrder(node<T>* root, void (*out) (T &data))
{
    if(root != nullptr)
    {
        InOrder(root->left, out);
        out(root->data);
        InOrder(root->right, out);
    }

}

template <class T>
void BST<T>::PreOrder(void (*out) (T &data))
{

    if(root != nullptr)
    {
        PreOrder(root, out);
    }
}

template <class T>
void BST<T>::PreOrder(node<T>* root, void (*out) (T &data))
{
    if(root != nullptr)
    {
        out(root->data);
        PreOrder(root->left, out);
        PreOrder(root->right, out);
    }

}

template <class T>
void BST<T>::PostOrder(void (*out) (T &data))
{

    if(root != nullptr)
    {
        PostOrder(root, out);
    }
}

template <class T>
void BST<T>::PostOrder(node<T>* root, void (*out) (T &data))
{
    if(root != nullptr)
    {
        PostOrder(root->left, out);
        PostOrder(root->right, out);
        out(root->data);
    }

}

template <class T>
bool BST<T>::Search(T &data)
{
    if(root != nullptr)
    {
        return Search(root, data);
    }
    else
    {
        return false;
    }
}

template <class T>
bool BST<T>::Search(node<T>* current, T &data)
{
    if(current == nullptr)
    {
        return false;
    }
    else if(current->data == data)
    {
        data = current->data;
        return true;
    }
    else if(data < current->data)
    {
        return Search(current->left, data);
    }
    else
    {
        return Search(current->right, data);
    }
}


template <class T>
void BST<T>::DeleteTree()
{
    if (root != nullptr)
    {
        DeleteTree(root);
    }
}

template <class T>
void BST<T>::DeleteTree(node<T>* &root)
{
    if (root != nullptr)
    {
        DeleteTree(root->left);
        DeleteTree(root->right);
        delete root;
        root = nullptr;
    }
}

template <class T>
//copy constructor recursively
BST<T>::BST(const BST &newBST)
{
    if(newBST.root == nullptr)
    {
        root = nullptr;
    }
    else
    {
        CopyTree(root, newBST.root);
    }
    //CopyTree(root, newBST.root);
}

template <class T>
//copy tree
void BST<T>::CopyTree(node<T>* &newRoot, node<T>* oldRoot)
{
    if(oldRoot != nullptr)
    {
        newRoot = new node<T>;
        newRoot->data = oldRoot->data;
        CopyTree(newRoot->left, oldRoot->left);
        CopyTree(newRoot->right, oldRoot->right);
    }
    else
    {
        newRoot = nullptr;
    }
}


template <class T>
BST<T>& BST<T>::operator=(const BST &newBST)
{
    if(this != &newBST)
    {
        //DeleteTree();
        if (root != nullptr)
        {
            DeleteTree();
        }
        if(newBST.root == nullptr)
        {
            root = nullptr;
        }
        else
        {
            CopyTree(root, newBST.root);
        }
    }
    return *this;
}
#endif // BST_H
