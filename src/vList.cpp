#include "../include/libv/vList.hpp"
#include "../include/libv/vNode.hpp"

template <typename _Tval> _vList<_Tval>::_vList(size_type initial_size) {
  if (initial_size == 0) {
    this->size = 0;
    head = nullptr;
    tail = nullptr;
    return;
  }
  auto new_node = _vNode<_Tval>::create_node(value_type{});
  head = new_node;
  tail = new_node;

  for (size_type i = 1; i < initial_size; ++i) {
    push_back(value_type{});
  }
}

template <typename _Tval>
_vList<_Tval>::_vList(size_type initial_size, const value_type &initial_value) {
  if (initial_size == 0) {
    this->size = 0;
    head = nullptr;
    tail = nullptr;
    return;
  }
  auto new_node = _vNode<_Tval>::create_node(initial_value);
  head = new_node;
  tail = new_node;

  for (size_type i = 1; i < initial_size; ++i) {
    push_back(initial_value);
  }
}

template <typename _Tval>
_vList<_Tval>::_vList(size_type initial_size, value_type &&initial_value) {
  if (initial_size == 0) {
    this->size = 0;
    head = nullptr;
    tail = nullptr;
    return;
  }
  auto new_node = _vNode<_Tval>::create_node(std::move(initial_value));
  head = new_node;
  tail = new_node;

  for (size_type i = 1; i < initial_size; ++i) {
    push_back(std::move(initial_value));
  }
}

template <typename _Tval>
_vList<_Tval>::_vList(const init_list_type &init_list) {
  this->size = 0;
  head.reset();
  tail.reset();

  for (auto &value : init_list) {
    push_back(value);
  }
}

template <typename _Tval> _vList<_Tval>::_vList(init_list_type &&init_list) {
  this->size = 0;
  head.reset();
  tail.reset();

  for (auto &value : init_list) {
    push_back(std::move(value));
  }
}

template <typename _Tval> _vList<_Tval>::_vList(const _vList<_Tval> &other) {
  this->size = 0;
  head.reset();
  tail.reset();

  if (other.is_empty()) {
    return;
  }

  auto current = other.head;
  while (current) {
    push_back(current->value);
    current = current->next;
  }
}

template <typename _Tval> _vList<_Tval>::_vList(_vList<_Tval> &&other) {
  this->size = 0;
  this->head = std::move(other.head);
  this->tail = std::move(other.tail);

  other.size = 0;
  other.head.reset();
  other.tail.reset();
}

template <typename _Tval>
void _vList<_Tval>::push_front(const _Tval &value) noexcept {
  auto new_node = _vNode<_Tval>::create_node(value);
  new_node->next = head;
  head = new_node;
  if (tail == nullptr) {
    tail = new_node;
  }
}

template <typename _Tval>
void _vList<_Tval>::push_front(_Tval &&value) noexcept {
  auto new_node = _vNode<_Tval>::create_node(std::move(value));
  new_node->next = head;
  head = new_node;
  if (tail == nullptr) {
    tail = new_node;
  }
}

template <typename _Tval>
void _vList<_Tval>::push_back(const _Tval &value) noexcept {
  auto new_node = _vNode<_Tval>::create_node(value);
  tail->next = new_node;
  tail = new_node;
}

template <typename _Tval>
void _vList<_Tval>::push_back(_Tval &&value) noexcept {
  auto new_node = _vNode<_Tval>::create_node(std::move(value));
  tail->next = new_node;
  tail = new_node;
}

template <typename _Tval> void _vList<_Tval>::pop_front() {
  if (head == nullptr) {
    return;
  }
  auto old_head = head;
  head = head->next;
  _vNode<_Tval>::destroy(old_head);
  if (head == nullptr) {
    tail = nullptr;
  }
  --size;
}

template <typename _Tval> void _vList<_Tval>::pop_back() {
  if (tail == nullptr) {
    return;
  }
  auto old_tail = tail;
  tail = tail->prev;
  _vNode<_Tval>::destroy(old_tail);
  if (tail == nullptr) {
    head = nullptr;
  }
  --size;
}

template <typename _Tval> bool _vList<_Tval>::is_empty() const noexcept {
  return size == 0;
}

template <typename _Tval>
const std::shared_ptr<_vNode<_Tval>> &_vList<_Tval>::get_head() const noexcept {
  return this->head;
}

template <typename _Tval>
const std::weak_ptr<_vNode<_Tval>> &_vList<_Tval>::get_tail() const noexcept {
  return this->tail;
}

template <typename _Tval>
_vList<_Tval> &_vList<_Tval>::operator=(const _vList<value_type> &other) {
  if (this == &other) {
    return *this;
  }
  this->head = nullptr;
  this->tail = nullptr;
  size = 0;

  for (auto node : other) {
    push_back(node->value);
  }
  return *this;
}

template <typename _Tval>
_vList<_Tval> &_vList<_Tval>::operator=(_vList<_Tval> &&other) {
  if (this == &other) {
    return *this;
  }
  this->head = nullptr;
  this->tail = nullptr;
  size = 0;

  for (auto node : other) {
    push_back(std::move(node->value));
  }
  return *this;
}

template <typename _Tval>
_vList<_Tval> &_vList<_Tval>::operator=(const init_list_type &other) {
  this->head = nullptr;
  this->tail = nullptr;
  size = 0;

  for (const auto &value : other) {
    push_back(value);
  }
  return *this;
}

template <typename _Tval>
_vList<_Tval> &_vList<_Tval>::operator=(init_list_type &&other) {
  this->head = nullptr;
  this->tail = nullptr;
  size = 0;

  for (auto &value : other) {
    push_back(std::move(value));
  }
  return *this;
}
