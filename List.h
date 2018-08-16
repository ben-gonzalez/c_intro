#ifndef LIST_H
#define LIST_H

class Node {
 public:
  Node(int value);
  ~Node();
  int getValue();
  Node* getNext();
  void setNext(Node* next);
  Node* getPrev();
  void setPrev(Node* prev);

 private:
  Node* m_next;
  Node* m_prev;
  int m_value;
};

class List {
 public:
  List();
  ~List();
  void add(int x);
  void remove(int index);
  int get(int index);
  int count();

 private:
  Node* m_head;
  Node* m_tail;
};

#endif
