#ifndef FHEAP_HPP
#define FHEAP_HPP

#include <iostream>
#include <fstream>
#include <cmath>

class node {
    public:
        node* up;
        node* down;
        node* right;
        node* left;
        int     key;
        int     degree;
        char    mark;

        node(int = 0);
        node(node&);
        friend  std :: ostream& operator<<(std :: ostream&, node*);
};

void    takeOut(node*, node*);
void    putBetween(node*, node*, node*);


class fheap {
    public:

        node*   min_root;
        int     nodes;
        fheap();

        void            push(int = 0); 
        void            consolidate();
        void            extract_min(); 
        void            child_link(node*, node *); 
        void            cut(node*, node*);
        void            cascade_cut(node*);
        void            decrease_key(node*, int);
        node*           find_(node*, int);
        void            delete_(int);
        friend  fheap   merge_(fheap& n, fheap& m);


        int     getMin() {
            return min_root -> key;
        };
        node*    getMinRoot() {
            return min_root;
        }
        void    display();


};
#endif // FHEAP_HPP
