// Copyright (c) 2023, the vLib authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#pragma once
#include "vNode.hpp"

template <typename _Tval> struct _vList {
  using value_type = _Tval;
  using size_type = std::size_t;
  using head_ptr = std::shared_ptr<_vNode<value_type>>;
  using tail_ptr = std::weak_ptr<_vNode<value_type>>;
  using init_list_type = std::initializer_list<value_type>;

private:
  head_ptr head;
  tail_ptr tail;
  size_type size;

public:
  _vList() = default;
  _vList(size_type);
  _vList(size_type, const value_type &);
  _vList(size_type, value_type &&);
  _vList(const init_list_type &);
  _vList(init_list_type &&);
  _vList(const _vList<value_type> &);
  _vList(_vList<value_type> &&);
  ~_vList() = default;

  void push_front(const value_type &) noexcept;
  void push_front(value_type &&) noexcept;
  void push_back(const value_type &) noexcept;
  void push_back(value_type &&) noexcept;

  void pop_front();
  void pop_back();
  bool is_empty() const noexcept;
  const head_ptr &get_head() const noexcept;
  const tail_ptr &get_tail() const noexcept;

  _vList &operator=(const _vList<value_type> &);
  _vList &operator=(_vList<value_type> &&);
  _vList &operator=(const init_list_type &);
  _vList &operator=(init_list_type &&);
};
