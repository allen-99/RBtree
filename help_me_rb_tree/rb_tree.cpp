#include <iostream>
using namespace std;
//переопределение цветов
typedef enum { BLACK, RED } nodeColor;

//структура data поля 
typedef struct Data {

    unsigned int mon;
    unsigned int day;
};
//структура узла дерева
typedef struct Node_ {
    struct Node_* left;         /* left child */
    struct Node_* right;        /* right child */
    struct Node_* parent;       /* parent */
    nodeColor color;            /* node color (BLACK, RED) */
    Data data;                     /* data stored in node */
} Node;
//указатель на узео дерева
typedef Node* NodePtr;
//класс дерево
class RB_tree
{
public:

    //добавление узла
    //формальные параметры: day, month - день и месяц добавляемого объекта соответственно
    //входные данные: root - корень дерева + day, month поля
    //выходные данные: дерево с новым узлом
    void insert_t(int day, int month);
    //удаление min элемента справа
    //формальные параметры: нет
    //входные данные: root - корень
    //выходные данные: дерево без min справа элемента
    void remove(int key_day, int key_mon);
    //отчистка всего дерева
    //формальные параметры: нет
    //входные данные: root
    //выходные данные: корень дерева указывающий на NUL
    void delete_tree()
    {
        delete_t(root);
        root = NUL;
    }
    //поиск по data полю элемента
    //формальные параметры: day, month - значение data поля
    //входные данные: root + day,month
    //выходные данные: печать на экран сообщения, либо элемент не найден, либо его значение
    void search(int day, int month);
    //поиск минимального элемента дерева
    //формальные параметры: нет
    //входные данные: root
    //выходные данные: печать на экран сообщения, содержащего data поле нужного узла
    void search_min();
    //конструктор
    RB_tree();
    //деструктор
    ~RB_tree();
    //вывод дерева на экран в прямом порядке
    //формальные параметры: нет
    //входные данные: нет
    //выходные данные: печать на экране дерева в прямом порядке
    void print_PreOder()
    {
        cout << "Прямой обход: " << endl;
        PreOder(this->root);
        cout << endl;
    }
    //вывод дерева на экран в симметричном порядке слева направо
    //формальные параметры: нет
    //входные данные: нет
    //выходные данные: печать на экране дерева в симм. порядке слева
    void print_InOderLeft()
    {
        cout << "Симметричный обход слева: " << endl;
        InOderLeft(this->root);
        cout << endl;
    }
    //вывод дерева на экран в симметричном порядке справа налево
    //формальные параметры: нет
    //входные данные: нет
    //выходные данные: печать на экран дерева в симм. порядке справа
    void print_InOderRight()
    {
        cout << "Симметричный обход справа: " << endl;
        InOderRight(this->root);
        cout << endl;
    }
    //вывод дерева на экран в обратном порядке
    //формальные параметры: нет
    //входные данные: нет
    //выходные данные: печать дерева на экран в обратном порядке
    void print_PostOder()
    {
        cout << "Обратный обход: " << endl;
        PostOder(this->root);
        cout << endl;
    }
    void insert(int key_day, int key_mon);
private:

    //корень дерева
    NodePtr root;
    //"лист" дерева
    NodePtr NUL;
    //балансировка дерева после вставки
    //формальные параметры: указатель на вставленный узел
    //входные данные: дерево, вставленный узел
    //выходные данные: сбалансированное дерево
    void insertFix(NodePtr k);
    //поворот влево
    //формальные параметры: указатель на узел, который нужно повернуть
    //входные данные: дерево, узел
    //выходные данные: дерево с поворотом в одном узле
    void leftRotate(NodePtr x);
    //поворот впрво
    //формальные параметры: указатель на узел, который нужно повернуть
    //входные данные: дерево, узел
    //выходные данные: дерево с поворотом в одном узле
    void rightRotate(NodePtr x);
    //балансировка после удаления
    //формальные параметры: указатель на узел, являющийся потомком удаляемого узла
    //входные данные: дерево, узел
    //выходные данные: сбалансированное дерево
    void deleteFix(NodePtr x);

    void rbTransplant(NodePtr u, NodePtr v) {
        if (u->parent == nullptr) {
            root = v;
        }
        else if (u == u->parent->left) {
            u->parent->left = v;
        }
        else {
            u->parent->right = v;
        }
        v->parent = u->parent;
    }
    //нахождение узла с min значением
    //формальные параметры: указатель на нужный узел
    //входные данные: дерево, указатель
    //выходные данные: указатель с min значением data поля
    NodePtr minimum(NodePtr node) {
        while (node->left != NUL) {
            node = node->left;
        }
        return node;
    }
    //удаление всего дерева (использвуется как рекурсия)
    //формальные параметры: указатель на корень
    //входные данные: указатель на корень
    //выходные данные: ничего
    void delete_t(NodePtr root);
    //прямой вывод дерева на экран (использвуется как рекурсия)
    //формальные параметры: указатель на корень
    //входные данные: указатель на корень
    //выходные данные: печать data поля узла
    void PreOder(NodePtr x);
    //симметричный слева вывод дерева на экран (использвуется как рекурсия)
    //формальные параметры: указатель на корень
    //входные данные: указатель на корень
    //выходные данные: печать data поля узла
    void InOderLeft(NodePtr x);
    //симметричный справа вывод дерева на экран (использвуется как рекурсия)
    //формальные параметры: указатель на корень
    //входные данные: указатель на корень
    //выходные данные: печать data поля узла
    void InOderRight(NodePtr x);
    //обратный вывод дерева на экран (использвуется как рекурсия)
    //формальные параметры: указатель на корень
    //входные данные: указатель на корень
    //выходные данные: печать data поля узла
    void PostOder(NodePtr x);

};

    RB_tree::RB_tree()
    {
        NUL = new Node;
        NUL->color = BLACK;
        NUL->data.day = 0;
        NUL->data.mon = 0;
        NUL->left = nullptr;
        NUL->right = nullptr;
        NUL->parent = nullptr;
        root = NUL;
    }
    RB_tree::~RB_tree()
    {
        delete_tree();
        delete root;
    }
    void RB_tree::leftRotate(NodePtr x)
    {
        NodePtr y = x->right;
        x->right = y->left;
        if (y->left != NUL) {
            y->left->parent = x;
        }
        if (y != NUL) y->parent = x->parent;
        if (x->parent == nullptr) {
            this->root = y;
        }
        else if (x == x->parent->left) {
            x->parent->left = y;
        }
        else {
            x->parent->right = y;
        }
        y->left = x;
        if (x != NUL) x->parent = y;
    }
    void RB_tree::rightRotate(NodePtr x) {
        NodePtr y = x->left;
        x->left = y->right;
        if (y->right != NUL) {
            y->right->parent = x;
        }
        if (y != NUL) y->parent = x->parent;
        if (x->parent == nullptr) {
            this->root = y;
        }
        else if (x == x->parent->right) {
            x->parent->right = y;
        }
        else {
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
    }
    void RB_tree::insert_t(int day, int month)
    {
        {
            NodePtr node = new Node;
            node->parent = nullptr;
            node->data.day = day;
            node->data.mon = month;
            node->left = NUL;
            node->right = NUL;
            node->color = RED;

            NodePtr y = nullptr;
            NodePtr x = this->root;

            while (x != NUL) {
                y = x;
                if (node->data.mon < x->data.mon || (node->data.mon == x->data.mon && node->data.day < x->data.day)) {
                    x = x->left;
                }
                else {
                    x = x->right;
                }
            }

            node->parent = y;
            if (y == nullptr) {
                root = node;
            }
            else if (node->data.mon < y->data.mon || (node->data.mon == y->data.mon && node->data.day < y->data.day)) {
                y->left = node;
            }
            else {
                y->right = node;
            }

            if (node->parent == nullptr) {
                node->color = BLACK;
                return;
            }

            if (node->parent->parent == nullptr) {
                return;
            }

            insertFix(node);
        }
    }
    void RB_tree::remove(int key_day, int key_mon)
    {
        NodePtr node = this->root;
        NodePtr z = NUL;
        while (node != NUL)
        {
        if ((key_day == node->data.day) && (key_mon == node->data.mon)) {
            z = node;
        }

        if (/*node->data <= key*/ (node->data.mon < key_mon) || ((key_mon == node->data.mon) && (node->data.day <= key_day))) {
            node = node->right;
        }
        else {
            node = node->left;
        }
        }
    if (z == NUL) {
        cout << "Key not found in the tree" << endl;
        return;
    }

        NodePtr x, y;
        y = node;
        int y_original_color = y->color;
        if (z->left == NUL) {
            x = z->right;
            rbTransplant(z, z->right);
        }
        else if (z->right == NUL) {
            x = z->left;
            rbTransplant(z, z->left);
        }
        else {
            y = minimum(z->right);
            y_original_color = y->color;
            x = y->right;
            if (y->parent == z) {
                x->parent = y;
            }
            else {
                rbTransplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }

            rbTransplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
        delete z;
        if (y_original_color == 0) {
            deleteFix(x);
        }
    }
    void RB_tree::search(int day, int month)
    {
        NodePtr x = this->root;
        while (x != NUL)
        {
            if (x->data.day == day && x->data.mon == month)
            {
                cout << "node found:" << endl;
                cout << x->data.day << "." << x->data.mon << " ";
                if (x->color == BLACK)
                    cout << "(BLACK)";
                else if (x->color == RED)
                    cout << "(RED)";
                cout << endl;
                return;
            }
            if (month < x->data.mon || (month == x->data.mon && day < x->data.day))
                x = x->left;
            else
                x = x->right;
        }
    }
    void RB_tree::search_min()
    {
        NodePtr x = minimum(root);

        cout << "node min found:" << endl;
        cout << x->data.day << "." << x->data.mon << " ";
        if (x->color == BLACK)
            cout << "(BLACK)";
        else if (x->color == RED)
            cout << "(RED)";
        cout << endl;
        return;
    }
    void RB_tree::insertFix(NodePtr k)
    {
        {
            NodePtr u;
            while (k->parent->color == RED) {
                if (k->parent == k->parent->parent->right) {
                    u = k->parent->parent->left;
                    if (u->color == RED) {
                        u->color = BLACK;
                        k->parent->color = BLACK;
                        k->parent->parent->color = RED;
                        k = k->parent->parent;
                    }
                    else {
                        if (k == k->parent->left) {
                            k = k->parent;
                            rightRotate(k);
                        }
                        k->parent->color = BLACK;
                        k->parent->parent->color = RED;
                        leftRotate(k->parent->parent);
                    }
                }
                else {
                    u = k->parent->parent->right;

                    if (u->color == RED) {
                        u->color = BLACK;
                        k->parent->color = BLACK;
                        k->parent->parent->color = RED;
                        k = k->parent->parent;
                    }
                    else {
                        if (k == k->parent->right) {
                            k = k->parent;
                            leftRotate(k);
                        }
                        k->parent->color = BLACK;
                        k->parent->parent->color = RED;
                        rightRotate(k->parent->parent);
                    }
                }
                if (k == root) {
                    break;
                }
            }
            root->color = BLACK;
        }
    }
    void RB_tree::deleteFix(NodePtr x) {
        NodePtr s;
        while (x != root && x->color == BLACK) {
            if (x == x->parent->left) {
                s = x->parent->right;
                if (s->color == RED) {
                    s->color = BLACK;
                    x->parent->color = RED;
                    leftRotate(x->parent);
                    s = x->parent->right;
                }

                if (s->left->color == BLACK && s->right->color == BLACK) {
                    s->color = RED;
                    x = x->parent;
                }
                else {
                    if (s->right->color == BLACK) {
                        s->left->color = BLACK;
                        s->color = RED;
                        rightRotate(s);
                        s = x->parent->right;
                    }

                    s->color = x->parent->color;
                    x->parent->color = BLACK;
                    s->right->color = BLACK;
                    leftRotate(x->parent);
                    x = root;
                }
            }
            else {

                s = x->parent->left;
                if (s->color == RED) {
                    s->color = BLACK;
                    x->parent->color = RED;
                    rightRotate(x->parent);
                    s = x->parent->left;
                }

                if (s->right->color == BLACK && s->left->color == BLACK) {
                    s->color = RED;
                    x = x->parent;
                }
                else {
                    if (s->left->color == BLACK) {
                        s->right->color = BLACK;
                        s->color = RED;
                        leftRotate(s);
                        s = x->parent->left;
                    }

                    s->color = x->parent->color;
                    x->parent->color = BLACK;
                    s->left->color = BLACK;
                    rightRotate(x->parent);
                    x = root;
                }
            }
        }
        x->color = BLACK;
    }
    void RB_tree::delete_t(NodePtr r)
    {
        if (r != NUL)
        {
            RB_tree::delete_t(r->right);
            RB_tree::delete_t(r->left);
            delete r;
        }
    }
    void RB_tree::PreOder(NodePtr x)
    {
        if (x)
        {
            if (x != NUL)
            {
                cout << x->data.day << "." << x->data.mon << "";
                if (x->color == BLACK)
                    cout << "(BLACK) ";
                else if (x->color == RED)
                    cout << "(RED) ";
            }
            PreOder(x->left);
            PreOder(x->right);
        }
    }
    void RB_tree::InOderLeft(NodePtr x)
    {
        if (x)
        {
            InOderLeft(x->left);
            if (x != NUL)
            {
                cout << x->data.day << "." << x->data.mon << "";
                if (x->color == BLACK)
                    cout << "(BLACK) ";
                else if (x->color == RED)
                    cout << "(RED) ";
            }
            InOderLeft(x->right);
        }
    }
    void RB_tree::InOderRight(NodePtr x)
    {
        if (x)
        {
            InOderRight(x->right);
            if (x != NUL)
            {
                cout << x->data.day << "." << x->data.mon << "";
                if (x->color == BLACK)
                    cout << "(BLACK) ";
                else if (x->color == RED)
                    cout << "(RED) ";
            }
            InOderRight(x->left);
        }
    }
    void RB_tree::PostOder(NodePtr x)
    {
        if (x)
        {
            PostOder(x->left);
            PostOder(x->right);
            if (x != NUL)
            {
                cout << x->data.day << "." << x->data.mon << "";
                if (x->color == BLACK)
                    cout << "(BLACK) ";
                else if (x->color == RED)
                    cout << "(RED) ";
            }
        }
    }

    void RB_tree::insert(int key_day, int key_mon)
    {
        NodePtr x = this->root;
        while (x != NUL)
        {
            if (x->data.day == key_day && x->data.mon == key_mon)
            {
                cout << "Ключ "<< key_day << "." << key_mon <<" повторяется" << endl;
                return;
            }
            if (key_mon < x->data.mon || (key_mon == x->data.mon && key_day < x->data.day))
                x = x->left;
            else
                x = x->right;
        }
        insert_t(key_day, key_mon);
    }


    void example_for_delete_1(RB_tree &aa);
    void example_for_delete_2(RB_tree& aa);



int main()
{
    setlocale(LC_ALL, "ru");
    RB_tree aa;
    example_for_delete_1(aa);
    example_for_delete_2(aa);
    return 0;
}



void example_for_delete_1(RB_tree& aa)
{
    cout << "УДАЛЕНИЕ НОМЕР 1" << endl;
    aa.insert(13, 4);
    aa.insert(12,2);
    aa.insert(12, 3);
    aa.insert(14, 4);
    aa.insert(11, 4);
    aa.insert(16, 3);
    aa.insert(10, 2);
    aa.insert(8, 2);
    aa.insert(5, 2);
    aa.insert(11, 1);
    aa.insert(9, 2);
    aa.print_PreOder();
    cout << "УДАЛЕНИЕ 12.02" << endl;
    aa.remove(12, 2);
    aa.print_PreOder();
    cout << "--------------------" << endl;
}

void example_for_delete_2(RB_tree& aa)
{
    aa.insert(11,2);
    aa.insert(12,2);
    aa.insert(13,2);
    aa.insert(14, 2);
    aa.insert(10, 1);
    aa.insert(9, 1);
    aa.insert(8, 1);
    aa.remove(11, 2);

    cout << "УДАЛЕНИЕ НОМЕР 2" << endl;
    aa.print_PreOder();
    cout << "УДАЛЕНИЕ 10.02" << endl;
    aa.remove(10, 2);
    aa.print_PreOder();
    cout << "--------------------" << endl;
    cout << "УДАЛЕНИЕ НОМЕР 3" << endl;
    aa.print_PreOder();
    cout << "УДАЛЕНИЕ 11.01" << endl;
    aa.remove(11, 1);
    aa.print_PreOder();
    cout << "--------------------" << endl;
    cout << "УДАЛЕНИЕ НОМЕР 4" << endl;
    aa.print_PreOder();
    cout << "УДАЛЕНИЕ 12.02" << endl;
    aa.remove(12, 2);
    aa.print_PreOder();
    cout << "--------------------" << endl;
}
