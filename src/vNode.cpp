#include "libv\vNode.hpp"

template <typename _Tval>
_vNode<_Tval>::_vNode(const value_type &new_value, next_node_pointer next,
                      prev_node_pointer prev)
    : value(new_value), next(next), prev(prev) {}

template <typename _Tval>
_vNode<_Tval>::_vNode(value_type &&new_value, next_node_pointer next,
                      prev_node_pointer prev)
    : value(std::move(new_value)), next(next), prev(prev) {}

template <typename _Tval>
std::shared_ptr<_vNode<_Tval>> &
_vNode<_Tval>::create_node(const value_type &value_type) {
  return std::make_shared<_vNode<_Tval>>(value_type);
}

template <typename _Tval>
std::shared_ptr<_vNode<_Tval>> &
_vNode<_Tval>::create_node(value_type &&value_type) {
  return std::make_shared<_vNode<_Tval>>(std::move(value_type));
}

template <typename _Tval>
void _vNode<_Tval>::set_value(const value_type &new_value) noexcept {
  this->value = new_value;
}

template <typename _Tval>
void _vNode<_Tval>::set_value(value_type &&new_value) noexcept {
  this->value = std::move(new_value);
}

template <typename _Tval>
void _vNode<_Tval>::set_next(const next_node_pointer &new_next) noexcept {
  this->next = new_next;
}

template <typename _Tval>
void _vNode<_Tval>::set_prev(const prev_node_pointer &new_prev) noexcept {
  this->prev = new_prev;
}

template <typename _Tval>
void _vNode<_Tval>::set_next(next_node_pointer &&r_new_next) noexcept {
  this->next = std::move(r_new_next);
}

template <typename _Tval>
void _vNode<_Tval>::set_prev(prev_node_pointer &&r_new_prev) noexcept {
  this->prev = std::move(r_new_prev);
}

template <typename _Tval> _Tval &_vNode<_Tval>::get_value() noexcept {
  return this->value;
}

template <typename _Tval>
const _Tval &_vNode<_Tval>::get_value() const noexcept {
  return this->value;
}

template <typename _Tval>
const std::shared_ptr<_vNode<_Tval>> &_vNode<_Tval>::get_next() const noexcept {
  return this->next;
}

template <typename _Tval>
const std::weak_ptr<_vNode<_Tval>> &_vNode<_Tval>::get_prev() const noexcept {
  return this->prev;
}

template <typename _Tval> bool _vNode<_Tval>::has_next() const noexcept {
  return this->next != nullptr;
}

template <typename _Tval> bool _vNode<_Tval>::has_prev() const noexcept {
  return !this->prev.expired();
}
