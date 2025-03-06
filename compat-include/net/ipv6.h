#ifndef _NET_OVPN_NET_IPV6_H_
#define _NET_OVPN_NET_IPV6_H_

#include <linux/version.h>
#include_next <net/ipv6.h>

#if LINUX_VERSION_CODE < KERNEL_VERSION(6, 15, 0)

#define inet6_stream_ops \
	*((struct proto_ops *)kallsyms_lookup_name("inet6_stream_ops"))

#endif /* LINUX_VERSION_CODE < KERNEL_VERSION(6, 15, 0) */

#endif /* _NET_OVPN_NET_IPV6_H_ */
