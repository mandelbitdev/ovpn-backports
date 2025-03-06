#ifndef _NET_OVPN_LINUX_NETDEVICE_H_
#define _NET_OVPN_LINUX_NETDEVICE_H_

#include <linux/version.h>
#include_next <linux/netdevice.h>

#if LINUX_VERSION_CODE < KERNEL_VERSION(6, 12, 0)

#include <linux/netdev_features.h>
#undef NETIF_F_SG
#define NETIF_F_SG (__NETIF_F(SG) | NETIF_F_LLTX)

#define lltx needs_free_netdev

#endif /* LINUX_VERSION_CODE >= KERNEL_VERSION(6, 12, 0) */

#endif /* _NET_OVPN_LINUX_NETDEVICE_H_ */
