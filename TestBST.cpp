#include "BST.h"
#include "Date.h"
#include <iostream>
#include <typeinfo>

using namespace std;

void printInt(int &data);
void bstConstructorTest();
//void bstNonDefaultConstructorTest();
void bstDestructorTest();
void bstCopyConstructorTest();
void operatorTest();
void bstInsertTest1();
void bstInsertTest2();
void bstInsertTest3();
void bstSearchTest1();
void bstSearchTest2();
void bstSearchTest3();
void bstInOrderTest1();
void bstInOrderTest2();
void bstInOrderTest3();
void bstPreOrderTest1();
void bstPreOrderTest2();
void bstPreOrderTest3();
void bstPostOrderTest1();
void bstPostOrderTest2();
void bstPostOrderTest3();
void bstDeleteTest();
void bstMaxIntCapacitytest();
void bstMaxFloatCapacitytest();
void bstMaxStringCapacitytest();
void bstTypeTest();
void bstInsertTest4();


int main()
{

    cout << "Testing BST class" << endl;
    bstConstructorTest();
    bstCopyConstructorTest();
    operatorTest();
    bstDestructorTest();
    bstInsertTest1();
    bstInsertTest2();
    bstInsertTest3();
    bstSearchTest1();
    bstSearchTest2();
    bstSearchTest3();
    bstInOrderTest1();
    bstInOrderTest2();
    bstInOrderTest3();
    bstPreOrderTest1();
    bstPreOrderTest2();
    bstPreOrderTest3();
    bstPostOrderTest1();
    bstPostOrderTest2();
    bstPostOrderTest3();
    bstDeleteTest();
    bstInsertTest4();
    bstTypeTest();
    //bstMaxIntCapacitytest();
    bstMaxFloatCapacitytest();
    bstMaxStringCapacitytest();


    return 0;
}

void bstConstructorTest()
{
    cout << "1. Testing BST constructor: ";
    try
    {
        BST<int> bst1;
        if(typeid(bst1) != typeid(BST<int>))
        {
            cout << " -> BST constructor failed" << endl;
        }
        else
        {
            cout << " -> BST constructor passed" << endl;
        }
    }
    catch(...)
    {
        cout << " -> BST constructor failed" << endl;
    }
}

void bstCopyConstructorTest()
{
    cout << "2. Testing BST copy constructor with 5, 10, 15: ";
    try
    {
        BST<int> bst1;
        int num = 5;
        int num2 = 10;
        int num3 = 15;
        bst1.Insert(num);
        bst1.Insert(num2);
        bst1.Insert(num3);

        BST<int> bst2(bst1);
        bst1.DeleteTree();
        if(bst2.Search(num) && bst2.Search(num2) && bst2.Search(num3))
        {
            bst2.InOrder(printInt);
            cout << " -> BST copy constructor passed" << endl;
        }
        else
        {
            cout << " -> BST copy constructor failed" << endl;
        }
    }
    catch(...)
    {
        cout << " -> BST copy constructor failed" << endl;
    }
}

void operatorTest()
{
    cout << "3. Testing BST operator with 5, 10, 15: ";
    try
    {
        BST<int> bst1;
        int num = 5;
        int num2 = 10;
        int num3 = 15;
        bst1.Insert(num);
        bst1.Insert(num2);
        bst1.Insert(num3);

        BST<int> bst2;
        bst2 = bst1;
        bst1.DeleteTree();
        if(bst2.Search(num) && bst2.Search(num2) && bst2.Search(num3))
        {
            bst2.InOrder(printInt);
            cout << " -> BST operator passed" << endl;
        }
        else
        {
            cout << " -> BST operator failed" << endl;
        }
    }
    catch(...)
    {
        cout << " -> BST operator failed" << endl;
    }
}

void bstDestructorTest()
{
    cout << "4. Testing BST destructor: ";
    try
    {
        BST<int> bst1;

        int num1 = 4;
        int num2 = 6;
        int num3 = 46;

        bst1.Insert(num1);
        bst1.Insert(num2);
        bst1.Insert(num3);

        bst1.~BST();
        if(typeid(bst1) != typeid(BST<int>) && bst1.Search(num1) && bst1.Search(num2) && bst1.Search(num3))
        {
            cout << " -> BST destructor failed: " << endl;
        }
        else
        {
            cout << " -> BST destructor passed: ";
            bst1.PreOrder(printInt);
            cout << endl;
        }
    }
    catch(...)
    {
        cout << " -> BST destructor failed" << endl;
    }
}

void bstInsertTest1()
{
    try
    {
        BST<int> bst;
        int num = 5;
        int num2 = 10;

        bst.Insert(num);
        bst.Insert(num2);

        cout << "5. BST insert with input 5, 6: ";

        if(bst.Search(num) == true && bst.Search(num2) == true)
        {
            cout << " -> BST insert passed: ";
            bst.InOrder(printInt);
            cout << endl;
        }
        else
        {
            cout << " -> BST insert failed" << endl;
        };
    }
    catch(...)
    {
        cout << " -> BST insert failed" << endl;
    };
}

void bstInsertTest2()
{
    try
    {
        BST<int> bst;
        int num = 0;
        int num2 = 0;

        bst.Insert(num);
        bst.Insert(num2);

        cout << "6. BST insert with input 0, 0: ";

        if (bst.Search(num) == true && bst.Search(num2) == true)
        {
            cout << " -> BST insert passed";
            bst.InOrder(printInt);
            cout << endl;
        }
        else
        {
            cout << " -> BST insert failed" << endl;
        };
    }
    catch(...)
    {
        cout << " -> BST insert failed" << endl;
    };
}

void bstInsertTest3()
{
    try
    {
        BST<int> bst;
        int num = -5;
        int num2 = -10;

        bst.Insert(num);
        bst.Insert(num2);

        cout << "7. BST insert with input -5, -6: ";

        if(bst.Search(num) == true && bst.Search(num2) == true)
        {
            cout << " -> BST insert passed: ";
            bst.InOrder(printInt);
            cout << endl;
        }
        else
        {
            cout << " -> BST insert failed" << endl;
        };
    }
    catch(...)
    {
        cout << " -> BST insert failed" << endl;
    };
}

void bstSearchTest1()
{
    //cout << "Testing BST search" << endl;
    try
    {
        BST<int> bst;
        int num = 5;
        int num2 = 10;

        bst.Insert(num);
        bst.Insert(num2);

        cout << "8. BST search with input 5, 6: ";

        if(bst.Search(num) == true && bst.Search(num2) == true)
        {
            cout << " -> BST search passed" << endl;
        }
        else
        {
            cout << " -> BST search failed" << endl;
        };
    }
    catch(...)
    {
        cout << " -> BST search failed" << endl;
    };
}

void bstSearchTest2()
{
    //cout << "Testing BST search" << endl;
    try
    {
        BST<int> bst;
        int num = 0;
        int num2 = 0;

        bst.Insert(num);
        bst.Insert(num2);

        cout << "9. BST search with input 0, 0: ";

        if(bst.Search(num) == true && bst.Search(num2) == true)
        {
            cout << " -> BST search passed" << endl;
        }
        else
        {
            cout << " -> BST search failed" << endl;
        };
    }
    catch(...)
    {
        cout << " -> BST search failed" << endl;
    };
}

void bstSearchTest3()
{
    //cout << "Testing BST search" << endl;
    try
    {
        BST<int> bst;
        int num = -5;
        int num2 = -10;

        bst.Insert(num);
        bst.Insert(num2);

        cout << "10. BST search with input -5, -6: ";

        if(bst.Search(num) == true && bst.Search(num2) == true)
        {
            cout << " -> BST search passed" << endl;
        }
        else
        {
            cout << " -> BST search failed" << endl;
        };
    }
    catch(...)
    {
        cout << " -> BST search failed" << endl;
    };
}

void bstInOrderTest1()
{
    //cout << "Testing BST inOrder" << endl;
    try
    {
        BST<int> bst;
        int num = 5;
        int num2 = 10;
        int num3 = 6;

        bst.Insert(num);
        bst.Insert(num2);
        bst.Insert(num3);

        cout << "11. BST inOrder with input 5, 10, 6: ";

        bst.InOrder(printInt);
        cout << " -> BST inOrder passed" << endl;
    }
    catch(...)
    {
        cout << " -> BST inOrder failed" << endl;
    };
}

void bstInOrderTest2()
{
    //cout << "Testing BST inOrder" << endl;
    try
    {
        BST<int> bst;
        int num = 0;
        int num2 = 0;
        int num3 = 0;

        bst.Insert(num);
        bst.Insert(num2);
        bst.Insert(num3);

        cout << "12. BST inOrder with input 0, 0, 0: ";

        bst.InOrder(printInt);
        cout << " -> BST inOrder passed" << endl;
    }
    catch(...)
    {
        cout << " -> BST inOrder failed" << endl;
    };
}

void bstInOrderTest3()
{
    //cout << "Testing BST inOrder" << endl;
    try
    {
        BST<int> bst;
        int num = -5;
        int num2 = -10;
        int num3 = -6;

        bst.Insert(num);
        bst.Insert(num2);
        bst.Insert(num3);

        cout << "13. BST inOrder with input -5, -10, -6: ";

        bst.InOrder(printInt);
        cout << " -> BST inOrder passed" << endl;
    }
    catch(...)
    {
        cout << " -> BST inOrder failed" << endl;
    };
}

void bstPreOrderTest1()
{
    //cout << "Testing BST preOrder" << endl;
    try
    {
        BST<int> bst;
        int num = 5;
        int num2 = 10;
        int num3 = 6;

        bst.Insert(num);
        bst.Insert(num2);
        bst.Insert(num3);

        cout << "14. BST preOrder with input 5, 10, 6: ";

        bst.PreOrder(printInt);
        cout << " -> BST preOrder passed" << endl;
    }
    catch(...)
    {
        cout << " -> BST preOrder failed" << endl;
    };
}

void bstPreOrderTest2()
{
    //cout << "Testing BST preOrder" << endl;
    try
    {
        BST<int> bst;
        int num = 0;
        int num2 = 0;
        int num3 = 0;

        bst.Insert(num);
        bst.Insert(num2);
        bst.Insert(num3);

        cout << "15. BST preOrder with input 0, 0, 0:";

        bst.PreOrder(printInt);
        cout << " -> BST preOrder passed" << endl;

    }
    catch(...)
    {
        cout << " -> BST preOrder failed" << endl;
    };
}

void bstPreOrderTest3()
{
    //cout << "Testing BST preOrder" << endl;
    try
    {
        BST<int> bst;
        int num = -5;
        int num2 = -10;
        int num3 = -6;

        bst.Insert(num);
        bst.Insert(num2);
        bst.Insert(num3);

        cout << "16. BST preOrder with input -5, -10, -6: ";

        bst.PreOrder(printInt);
        cout << " -> BST preOrder passed" << endl;
    }
    catch(...)
    {
        cout << " -> BST preOrder failed" << endl;
    };
}

void bstPostOrderTest1()
{
    //cout << "Testing BST postOrder" << endl;
    try
    {
        BST<int> bst;
        int num = 5;
        int num2 = 10;
        int num3 = 6;

        bst.Insert(num);
        bst.Insert(num2);
        bst.Insert(num3);

        cout << "17. BST postOrder with input 5, 10, 6: ";

        bst.PostOrder(printInt);
        cout << " -> BST postOrder passed" << endl;

    }
    catch(...)
    {
        cout << " -> BST postOrder failed" << endl;
    };
}

void bstPostOrderTest2()
{
    //cout << "Testing BST postOrder" << endl;
    try
    {
        BST<int> bst;
        int num = 0;
        int num2 = 0;
        int num3 = 0;

        bst.Insert(num);
        bst.Insert(num2);
        bst.Insert(num3);

        cout << "18. BST postOrder with input 0, 0, 0: ";

        bst.PostOrder(printInt);
        cout << " -> BST postOrder passed" << endl;
    }
    catch(...)
    {
        cout << " -> BST postOrder failed" << endl;
    };
}

void bstPostOrderTest3()
{
    //cout << "Testing BST postOrder" << endl;
    try
    {
        BST<int> bst;
        int num = -5;
        int num2 = -10;
        int num3 = -6;

        bst.Insert(num);
        bst.Insert(num2);
        bst.Insert(num3);

        cout << "19. BST postOrder with input -5, -10, -6: ";

        bst.PostOrder(printInt);
        cout << " -> BST postOrder passed" << endl;
    }
    catch(...)
    {
        cout << " -> BST postOrder failed" << endl;
    };
}

void bstDeleteTest()
{
    //cout << "Testing BST delete" << endl;
    BST<int> bst;
    int num = 5;
    int num2 = 10;
    int num3 = 6;

    bst.Insert(num);
    bst.Insert(num2);
    bst.Insert(num3);

    cout << "20. BST delete with input 5, 10, 6: ";

    bst.DeleteTree();

    if(bst.Search(num) && bst.Search(num2) && bst.Search(num3))
    {
        cout << " -> BST delete failed" << endl;
    }
    else
    {
        cout << " -> BST delete passed" << endl;
    };
}

void bstMaxIntCapacitytest()
{
    BST<int> bst;

    int count = 1;

    cout << "21. BST Maximum capacity of integer test: ";

    try
    {
        while(true)
        {
            //cout << count << endl;
            bst.Insert(count);
            count++;
        }
    }
    catch(...)
    {
        cout << "passed" << endl;
    }

    cout << count << endl;

}

void bstMaxFloatCapacitytest()
{
    BST<float> bst;

    int count = 0;
    float val = 1.00000001;

    cout << "25. BST Maximum capacity of float test: ";

    try
    {
        while(true)
        {
            bst.Insert(val);
            count++;
        }
    }
    catch(...)
    {
        cout << "passed: ";
    }

    cout << count << endl;

}

void bstMaxStringCapacitytest()
{
    BST<string> bst;

    int count = 0;
    string val = "Yay";

    cout << "26. BST Maximum capacity of string test: ";

    try
    {
        while(true)
        {
            bst.Insert(val);
            count++;
        }
    }
    catch(...)
    {
        cout << "passed" << endl;
    }

    cout << count << endl;

}

void bstTypeTest()
{
    BST<int> intBST;
    BST<float> floatBST;
    BST<string> stringBST;

    cout << "22. BST Type test: ";
    if(typeid(intBST) == typeid(BST<int>))
    {
        cout << "Integer BST passed" << endl;
    }
    else
    {
        cout << "Integer BST failed" << endl;
    }

    cout << "23. BST Type test: ";
    if(typeid(floatBST) == typeid(BST<float>))
    {
        cout << "Float BST passed" << endl;
    }
    else
    {
        cout << "Float BST failed" << endl;
    }

    cout << "24. BST Type test: ";
    if(typeid(stringBST) == typeid(BST<string>))
    {
        cout << "String BST passed" << endl;
    }
    else
    {
        cout << "String BST failed" << endl;
    }
}

void bstInsertTest4()
{
    //cout << "Testing BST insert" << endl;
    try
    {
        BST<Date> bst;
        Date date1(3, 12, 2010);
        Date date2(5, 2, 2000);
        Date date3(3, 3, 2009);


        bst.Insert(date1);
        bst.Insert(date2);
        bst.Insert(date3);

        cout << "21. BST insert with date input:";

        if (bst.Search(date1) && bst.Search(date2) && bst.Search(date3))
        {
            cout << " -> BST insert passed" << endl;
        }
        else
        {
            cout << " -> BST insert failed" << endl;
        }

    }
    catch(...)
    {
        cout << " -> BST insert failed" << endl;
    };
}



void printInt(int &data)
{
    cout << data << ", ";
}
