#ifndef _NET_OVPN_LINUX_NETLINK_H_
#define _NET_OVPN_LINUX_NETLINK_H_

#include <linux/version.h>
#include_next <linux/netlink.h>

#if LINUX_VERSION_CODE < KERNEL_VERSION(6, 1, 0)

#ifndef NL_REQ_ATTR_CHECK
#define NL_REQ_ATTR_CHECK(extack, nest, tb, type) \
	({                                        \
		struct nlattr **__tb = (tb);      \
		u32 __attr = (type);              \
		!__tb[__attr];                    \
	})
#endif

#endif /* LINUX_VERSION_CODE < KERNEL_VERSION(6, 1, 0) */

#if LINUX_VERSION_CODE < KERNEL_VERSION(6, 2, 0)

#define NETLINK_MAX_FMTMSG_LEN 80

#define NL_SET_ERR_MSG_FMT(extack, fmt, args...)                               \
	do {                                                                   \
		static char __msg[NETLINK_MAX_FMTMSG_LEN];                     \
		struct netlink_ext_ack *__extack = (extack);                   \
                                                                               \
		if (!__extack)                                                 \
			break;                                                 \
		if (snprintf(__msg, NETLINK_MAX_FMTMSG_LEN, "%s" fmt "%s", "", \
			     ##args, "") >= NETLINK_MAX_FMTMSG_LEN)            \
			net_warn_ratelimited("%s" fmt "%s",                    \
					     "truncated extack: ", ##args,     \
					     "\n");                            \
                                                                               \
		__extack->_msg = __msg;                                        \
	} while (0)

#define NL_SET_ERR_MSG_FMT_MOD(extack, fmt, args...) \
	NL_SET_ERR_MSG_FMT((extack), KBUILD_MODNAME ": " fmt, ##args)

#endif /* LINUX_VERSION_CODE < KERNEL_VERSION(6, 2, 0) */

#endif /* _NET_OVPN_LINUX_NETLINK_H_ */
