//
// socket_option.hpp
// ~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003, 2004 Christopher M. Kohlhoff (chris@kohlhoff.com)
//
// Permission to use, copy, modify, distribute and sell this software and its
// documentation for any purpose is hereby granted without fee, provided that
// the above copyright notice appears in all copies and that both the copyright
// notice and this permission notice appear in supporting documentation. This
// software is provided "as is" without express or implied warranty, and with
// no claim as to its suitability for any purpose.
//

#ifndef ASIO_SOCKET_OPTION_HPP
#define ASIO_SOCKET_OPTION_HPP

#include "asio/detail/push_options.hpp"

#include "asio/detail/socket_types.hpp"

namespace asio {
namespace socket_option {

/// Helper template for implementing flag-based options.
template <int Level, int Name>
class flag
{
public:
  /// Default constructor.
  flag()
    : value_(0)
  {
  }

  /// Construct to be either enabled or disabled.
  flag(bool enabled)
    : value_(enabled ? 1 : 0)
  {
  }

  /// Get the level of the socket option.
  int level() const
  {
    return Level;
  }

  /// Get the name of the socket option.
  int name() const
  {
    return Name;
  }

  /// Set the value of the flag.
  void set(bool enabled)
  {
    value_ = enabled ? 1 : 0;
  }

  /// Get the current value of the flag.
  bool get() const
  {
    return value_;
  }

  /// Get the address of the flag data.
  void* data()
  {
    return &value_;
  }

  /// Get the address of the flag data.
  const void* data() const
  {
    return &value_;
  }

  /// Get the size of the flag data.
  size_t size() const
  {
    return sizeof(value_);
  }

private:
  /// The underlying value of the flag.
  int value_;
};

/// Helper template for implementing integer options.
template <int Level, int Name>
class integer
{
public:
  /// Default constructor.
  integer()
    : value_(0)
  {
  }

  /// Construct with a specific option value.
  integer(int value)
    : value_(value)
  {
  }

  /// Get the level of the socket option.
  int level() const
  {
    return Level;
  }

  /// Get the name of the socket option.
  int name() const
  {
    return Name;
  }

  /// Set the value of the int option.
  void set(int value)
  {
    value_ = value;
  }

  /// Get the current value of the int option.
  int get() const
  {
    return value_;
  }

  /// Get the address of the int data.
  void* data()
  {
    return &value_;
  }

  /// Get the address of the int data.
  const void* data() const
  {
    return &value_;
  }

  /// Get the size of the int data.
  size_t size() const
  {
    return sizeof(value_);
  }

private:
  /// The underlying value of the int option.
  int value_;
};

/// Permit sending of broadcast datagrams.
typedef flag<IPPROTO_TCP, TCP_NODELAY> tcp_no_delay;

/// The receive buffer size for a socket.
typedef integer<SOL_SOCKET, SO_SNDBUF> send_buffer_size;

/// The send buffer size for a socket.
typedef integer<SOL_SOCKET, SO_RCVBUF> recv_buffer_size;

} // namespace socket_option
} // namespace asio

#include "asio/detail/pop_options.hpp"

#endif // ASIO_SOCKET_OPTION_HPP