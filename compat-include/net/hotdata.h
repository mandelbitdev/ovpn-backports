#ifndef _NET_OVPN_NET_HOTDATA_H_
#define _NET_OVPN_NET_HOTDATA_H_

#include <linux/version.h>

#if LINUX_VERSION_CODE < KERNEL_VERSION(6, 9, 0)

#include <linux/netdevice.h>

struct net_hotdata {
	int max_backlog;
};

extern struct net_hotdata net_hotdata;
extern int netdev_max_backlog;

#undef READ_ONCE
#define READ_ONCE(expr) __OVPN_READ_ONCE_HELPER(expr, #expr)

#define __OVPN_READ_ONCE_HELPER(expr, expr_str)                       \
	(__builtin_strcmp(expr_str, "net_hotdata.max_backlog") == 0 ? \
		 (*(typeof(expr) *)&netdev_max_backlog) :             \
		 ({                                                   \
			 compiletime_assert_rwonce_type(expr);        \
			 __READ_ONCE(expr);                           \
		 }))

#else

#include_next <net/hotdata.h>

#endif /* LINUX_VERSION_CODE < KERNEL_VERSION(6, 9, 0) */

#endif /* _NET_OVPN_NET_HOTDATA_H_ */
