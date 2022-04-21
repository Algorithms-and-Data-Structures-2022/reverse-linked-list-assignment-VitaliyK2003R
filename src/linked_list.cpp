#include "assignment/linked_list.hpp"

#include <utility> // swap

namespace assignment {

  /**
   * Переворачивает связный список, используя три указателя.
   *
   * Сложность
   *    по памяти ~ O(1)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseIterative() {
    if (!IsEmpty()) {
      Node* countNode = front_;
      Node* prevNode= nullptr;
      for (int i = 0; i < size(); i++) {
        Node* nextNode = countNode->next;
        countNode->next = prevNode;
        prevNode = countNode;
        countNode = nextNode;
      }
      Node* change = front_;
      front_ = back_;
      back_ = change;
    }
  }

  /**
   * Переворачивает связный список, используя рекурсию.
   *
   * Сложность
   *    по памяти ~ O(N)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseRecursive() {
    if (!IsEmpty()) {
      Node* countNode = front_;
      Node* exchangeNode = nullptr;
      reverse_recursive_helper(countNode, exchangeNode);
    }
  }

  // вспомогательный метод для реализации рекурсии
  void LinkedList::reverse_recursive_helper(Node*& curr, Node* prev) {
    for (int i = 0; i < size(); i++) {
      Node* nextNode = curr->next;
      curr->next = prev;
      prev = curr;
      curr = nextNode;
    }
    Node* change = front_;
    front_ = back_;
    back_ = change;
  }

}  // namespace assignment
