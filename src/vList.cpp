#include "libv\vList.hpp"
#include "vNode.hpp"

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
    auto new_node = _vNode<_Tval>::create_node(value_type{});
    tail->next = new_node;
    tail = new_node;
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
    auto new_node = _vNode<_Tval>::create_node(initial_value);
    tail->next = new_node;
    tail = new_node;
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
    auto new_node = _vNode<_Tval>::create_node(std::move(initial_value));
    tail->next = new_node;
    tail = new_node;
  }
}

template <typename _Tval>
_vList<_Tval>::_vList(const init_list_type &init_list) {
  if (init_list.empty()) {
    this->size = 0;
    head = nullptr;
    tail = nullptr;
    return;
  }

  auto new_node = _vNode<_Tval>::create_node(init_list.front());
  head = new_node;
  tail = new_node;

  for (auto it = init_list.begin(); it != init_list.end(); ++it) {
    auto new_node = _vNode<_Tval>::create_node(*it);
    tail->next = new_node;
    tail = new_node;
  }
}
