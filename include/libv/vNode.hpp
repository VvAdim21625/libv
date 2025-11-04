// Copyright (c) 2023, the vLib authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#pragma once
#include <memory>

template <typename _Tval> struct _vNode {
  using value_type = _Tval;
  using next_node_pointer = std::shared_ptr<_vNode<value_type>>;
  using prev_node_pointer = std::weak_ptr<_vNode<value_type>>;

private:
  value_type value;
  next_node_pointer next;
  prev_node_pointer prev;

public:
  _vNode() = default;
  _vNode(const value_type &, next_node_pointer = nullptr,
         prev_node_pointer = nullptr);
  _vNode(_Tval &&, next_node_pointer = nullptr, prev_node_pointer = nullptr);
  _vNode(const _vNode<value_type> &) = delete;
  _vNode(_vNode<value_type> &&) = delete;
  ~_vNode() = default;

  static next_node_pointer &create_node(const value_type &);
  static next_node_pointer &create_node(value_type &&);

  void set_value(const value_type &) noexcept;
  void set_value(value_type &&) noexcept;
  void set_next(const next_node_pointer &) noexcept;
  void set_prev(const prev_node_pointer &) noexcept;
  void set_next(next_node_pointer &&) noexcept;
  void set_prev(prev_node_pointer &&) noexcept;

  value_type &get_value() noexcept;
  const value_type &get_value() const noexcept;
  const next_node_pointer &get_next() const noexcept;
  const prev_node_pointer &get_prev() const noexcept;

  bool has_next() const noexcept;
  bool has_prev() const noexcept;

  _vNode &operator=(const _vNode &) noexcept = delete;
  _vNode &operator=(_vNode &&) noexcept = delete;
};
