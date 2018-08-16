#include "list.h"
#include <assert.h>
#include <stddef.h>

Node::Node(int value) {
  m_value = value;
}

Node::~Node() {}

int Node::getValue() {
  return this->m_value;
}

Node* Node::getNext() {
  return this->m_next;
}

void Node::setNext(Node* next) {
  this->m_next = next;
}

Node* Node::getPrev() {
  return this->m_prev;
}

void Node::setPrev(Node* prev) {
  this->m_prev = prev;
}

List::List() {
  m_tail = new Node((-1));
  m_head = new Node((-1));
  m_head->setNext(m_tail);
  m_head->setPrev(NULL);
  m_tail->setNext(NULL);
  m_tail->setPrev(m_head);

  assert(m_head->getNext() == m_tail);
  assert(m_tail->getPrev() == m_head);
}

List::~List() {
  for (Node* curr = m_head->getNext(); curr != m_tail;) {
    Node* toDelete = curr;
    curr = curr->getNext();
    assert(curr != NULL);
    delete toDelete;
  }
  delete m_tail;
  delete m_head;
}

void List::add(int x) {
  Node* prev = m_tail->getPrev();
  Node* curr = new Node(x);
  assert(prev != NULL);
  assert(curr != NULL);
  curr->setNext(m_tail);
  curr->setPrev(prev);
  prev->setNext(curr);
  m_tail->setPrev(curr);
}

int List::count() {
  int count = 0;
  for (Node* curr = m_head->getNext(); curr != m_tail; curr = curr->getNext()) {
    assert(curr != NULL);
    count += 1;
  }
  return count;
}

Node* find(Node* head, int offset) {
  Node* curr = head->getNext();
  for (int i = 0; i < offset; i++) {
    assert(curr != NULL);
    curr = curr->getNext();
  }
  return curr;
}

void List::remove(int index) {
  Node* node = find(m_head, index);
  assert(node != NULL);
  assert(node->getPrev() != NULL);
  assert(node->getNext() != NULL);
  node->getPrev()->setNext(node->getNext());
  node->getNext()->setPrev(node->getPrev());
  delete node;
}

int List::get(int index) {
  Node* node = find(m_head, index);
  assert(node != NULL);
  return node->getValue();
}
