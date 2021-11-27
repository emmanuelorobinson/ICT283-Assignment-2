#ifndef BST_H
#define BST_H
#include <iostream>

/** \brief BST.h simulates a Binary Search Tree data structure. It includes methods that allow it to function as a STL BST
 *
 * @author Emmanuel Oghenetega Ejakpomewhe
 *Student ID: 33961412
 * @version 17.12
 * @date 28/11/2021
 * @bug To my knowledge, my program contains no bugs
 */

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

    /** \brief Default constructor for BST class
     *
     * \param
     * \param
     * \return
     *
     */

    BST();

    /** \brief Destructor for BST class. Used to delete BST
     *
     * \param
     * \param
     * \return
     *
     */

    ~BST();

    /** \brief Copy constructor for BST. Copies passed in BST to the BST being initialized
     *
     * \param newBST - Passed in BST which would be copied to the BST being initialized
     * \param
     * \return
     *
     */

    BST(const BST<T> &newBST);

    /** \brief BST overloaded operator. Copies the nodes of one BST to another
     *
     * \param newBST - BST that would be copied into the calling BST
     * \param
     * \return
     *
     */

    BST& operator=(const BST<T> &newBST);

    /** \brief CopyTree is a help function which copes each element of one tree to another
     *
     * \param newRoot - Node in BST which would be filled by oldRoot
     * \param oldRoot - Node which would be copied to newRoot
     * \return
     *
     */

    void CopyTree(node<T>* &newRoot, node<T>* oldRoot);

    /** \brief Insert method used to add data into BST
     *
     * \param data - The data to be added to the BST
     * \param
     * \return
     *
     */

    void Insert(T & data);

    /** \brief Prints out the values of a BST using In Order transversal
     *
     * \param out - function pointer which allows data to be printed out on each step
     * \param data- The data on each level of transversal
     * \return
     *
     */

    void InOrder(void (*out) (T &data));

    /** \brief Prints out the values of a BST using Pre Order transversal
     *
     * \param out - function pointer which allows data to be printed out on each step
     * \param data- The data on each level of transversal
     * \return
     *
     */

    void PreOrder(void (*out) (T &data));

    /** \brief Prints out the values of a BST using Post Order transversal
     *
     * \param out - function pointer which allows data to be printed out on each step
     * \param data- The data on each level of transversal
     * \return
     *
     */

    void PostOrder(void (*out) (T &data));

    /** \brief Searches for data in the BST
     *
     * \param data - The data to be searched for
     * \param
     * \return
     *
     */

    bool Search(T &data);

    /** \brief Deletes the BST
     *
     * \param
     * \param
     * \return
     *
     */

    void DeleteTree();

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
BST<T>::BST()
{
    root = nullptr;
}

template <class T>
BST<T>::~BST()
{
    DeleteTree();
}

template <class T>
//copy constructor recursively
BST<T>::BST(const BST<T> &newBST)
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
BST<T>& BST<T>::operator=(const BST<T> &newBST)
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
#endif // BST_H
