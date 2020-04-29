#include "fheap.hpp"
#include "windows.h"

node :: node(int    key) {
    up = nullptr;
    down = nullptr;
    left = this;
    right = this;
    degree = 0;
    mark = 'W';
    node :: key = key;
}

node :: node(node &n)
{
    up = n.up;
    down = n.down;
    left = n.left;
    right = n.right;
    key = n.key;
    mark = n.mark;

}

fheap :: fheap()
{
    min_root = nullptr;
    nodes = 0;
}

std :: ostream& operator<<(std :: ostream& os, node* n)
{
    if (n -> down)
        os << "NODE CHILD: " << n -> down -> key << '\n';
    else
        os << "NODE HAS NO CHILD" << '\n';
    if (n -> right != n)
        os << "NODE RIGHT: " << n -> right -> key << '\n';
    else
        os << "NODE HAS NO RIGHT" << '\n';
    if (n -> left)
        os << "NODE LEFT: " << n -> left -> key << '\n';
    else
        os << "NODE HAS NO LEFT" << '\n';
    if (n -> up)
        os << "NODE PARENT: " << n -> up -> key << '\n';
    else
        os << "NODE HAS NO PARENT" << '\n';
    os << n -> key << '\n';

    return os;
}

void    takeOut(node *n)
{
    (n -> left) -> right = n -> right;
    (n -> right) -> left = n -> left;
}

void    putBetween(node* l, node* c, node* r)
{
    l -> right = c;
    c -> left = l;
    c -> right = r;
    r -> left = c;
}

fheap  merge_(fheap& n, fheap& m)
{
    node* aux;
    if (n.min_root -> key > m.min_root -> key)
    {
        aux = n.min_root -> right;
        while (aux -> right != n.min_root)
            aux = aux -> right;
        aux -> right = m.min_root -> right;
        m.min_root -> right = n.min_root;
        m.nodes += n.nodes;
        return m;
    }
    else
    {
        aux = m.min_root;
        while (aux -> right != m.min_root)
            aux = aux -> right;
        aux -> right = n.min_root -> right;
        n.min_root -> right = m.min_root;
        n.nodes += m.nodes;
        return n;
    }
}

void    fheap :: push(int val)
{
    node* new_node;
    nodes++;
    new_node = new node(val);
    if (min_root != NULL) {
        putBetween(min_root -> left, new_node, min_root);

        if (new_node -> key < min_root -> key)
            min_root = new_node;
    }
    else {
        min_root = new_node;
    }
}

void    fheap :: display()
{
    if (nodes == 0 || min_root == nullptr)
        std :: cout << "The heap is empty\n";
    else {
        node* ptr = min_root -> right;
        std :: cout << "The root nodes are: " << '\n' << " -> ";
        while (ptr != min_root) {
            std :: cout << ptr -> key << " -> ";
            ptr = ptr->right;
        }
        std :: cout << min_root -> key << " -> " << '\n';
        std :: cout << "The heap has " << nodes << " nodes." << '\n';

    }
}

void    fheap :: consolidate()
{
	int deg;
	int aux = (log(nodes)) / (log(2));
	node* m = min_root;
	node* n;
	node* p;
    node** degree_arr = new node*[aux + 1];

	for (int index = 0; index <= aux; index++)
		degree_arr[index] = nullptr;

	do {
		deg = m->degree;
		while (degree_arr[deg] != nullptr) {
			n = degree_arr[deg];
			if (m -> key > n -> key) {
				p = m;
				m = n;
				n = p;
			}

			this -> child_link(n, m);
			degree_arr[deg] = nullptr;
			deg++;
		}
		degree_arr[deg] = m;
		m = m -> right;
	} while (m != min_root);
	min_root = nullptr;
	for (int index = 0; index <= aux; index++) {
		if (degree_arr[index] != nullptr) {
			degree_arr[index] -> left = degree_arr[index];
			degree_arr[index] -> right = degree_arr[index];

			if (min_root != nullptr) {
			    putBetween(min_root -> left, degree_arr[index], min_root);
				if (degree_arr[index] -> key < min_root -> key)
					min_root = degree_arr[index];
			}
			else {
				min_root = degree_arr[index];
			}

            if (degree_arr[index] -> key < min_root -> key)
				min_root = degree_arr[index];
		}
	}

	delete[] degree_arr;
}


void    fheap :: child_link(node* n, node* m)
{
    takeOut(n);
	if (m -> right == m)
		min_root = m;
	n -> left = n;
	n -> right = n;
	n -> up = m;
	if (m -> down == nullptr)
		m -> down = n;
	putBetween(m -> down -> left, n, m -> down);
	
	if (n -> key < (m -> down) -> key)
		m -> down = n;
	m -> degree++;
}

void    fheap :: cut(node* n, node* p)
{
    if (n == n->right)
		p -> down = nullptr;

	takeOut(n);

	if (n == p->down)
		p->down = n->right;

	p -> degree = p -> degree - 1;
	n -> right = n;
	n -> left = n;
	putBetween(min_root -> left, n, min_root);
	n -> up = nullptr;
	n -> mark = 'B';
}

void    fheap :: cascade_cut(node* temp)
{
	node* n = temp -> up;

	if (n != nullptr) {
		if (temp->mark == 'W') {
			temp->mark = 'B';
		}
		else {
			this -> cut(temp, n);
			this -> cascade_cut(n);
		}
	}
}

void    fheap :: decrease_key(node* found, int val)
{
    node* parent = found -> up;

	if (min_root == nullptr)
		std :: cout << "HEAP-UL ESTE GOL!" << '\n';

	if (found == nullptr)
		std :: cout << "NODUL N-A FOST GASIT IN HEAP" << '\n';

	found -> key = val;

	if (parent != nullptr && found -> key < parent -> key) {
		cut(found, parent);
		cascade_cut(parent);
	}

	if (found -> key < min_root -> key)
		min_root = found;
}

node*    fheap :: find_(node* init, int  val)
{
    node* found = init -> right;
    node* aux = nullptr;

    if (val == init -> key)
        return init;

    if (found == init && found -> down != nullptr)
        aux = find_(found -> down, val);

    if (aux != nullptr)
        return aux;

	while (found != init && found -> key != val)
    {
        if (found -> down != nullptr)
            aux = find_(found -> down, val);

        if (aux != nullptr)
            return aux;

        found = found -> right;
    }

    if (found -> key != val)
        return nullptr;
    else
        return found;
}

void    fheap :: delete_(int val)
{
	if (min_root == nullptr)
		std :: cout << "HEAP-UL ESTE GOL!" << '\n';
	else {
		decrease_key(find_(min_root, val), -1);
		extract_min();
		std :: cout << "VALOAREA A FOST STEARSA!" << '\n';
	}
}


void    fheap :: extract_min()
{
    node*   handle = min_root;
    node*   child = nullptr;
    node*   aux;

    if (min_root != nullptr) {
        if (handle -> down != nullptr) {
            aux = handle -> down;
            do {
                child = aux -> right;

                putBetween(min_root -> left, aux, min_root);

                if (aux -> key < min_root -> key)
                    min_root = aux;
                aux -> up = nullptr;
                aux = child;
            } while (child != handle -> down); 
        }
        takeOut(handle);
        min_root = handle -> right;
        if (handle == handle -> right && handle -> down == nullptr)
            min_root = nullptr;
        else
        {
            min_root = handle -> right;
            consolidate();
        }
        nodes--;
    }
    else
        std :: cout << "The heap is empty." << '\n';
}


/*----------------------------



----------------------------*/

int     main()
{
    /*
    OPERATII:
    1 - inserare valoare AUX
    2 - stergere valoare AUX
    3 - afisare minim
    4 - sterge minim
    */

    std :: ifstream file("input.txt");
    int     op;
    int     aux;
    int     n;
    fheap   fh;

    file >> n;
    for (int index = 0; index < n; ++index)
    {
        std :: cout << "HEAP-UL DUPA OPERATIA " << index + 1;
        file >> op;
        if (op == 1)
        {
            file >> aux;
            std :: cout << " DE INTRODUCERE A VALORII " << aux << ": " << '\n';
            fh.push(aux);
        }
        else if (op == 2)
        {
            file >> aux;
            std :: cout << " DE STERGERE A VALORII " << aux << ": " << '\n';
            std :: cout << fh.find_(fh.getMinRoot(), aux);
            fh.delete_(aux);
        }
        else if (op == 3)
            std :: cout << " AFISARE MINIM: " << fh.min_root -> key << '\n';
        else if (op == 4)
        {
            std :: cout << " DE STERGERE A MINIMULUI " << ": " << '\n';
            fh.extract_min();
        }
        if (op != 3)
            fh.display();
        system ("PAUSE");
    }
    return 0;
}

