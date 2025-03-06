#ifndef _NET_OVPN_NET_NETLINK_H_
#define _NET_OVPN_NET_NETLINK_H_

#include <linux/version.h>
#include_next <net/netlink.h>

#if LINUX_VERSION_CODE < KERNEL_VERSION(6, 13, 0)

#ifndef NLA_POLICY_MAX_LEN
#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 10, 0)
#define NLA_POLICY_MAX_LEN(_len) { .type = NLA_BINARY, .len = _len }
#else
#define NLA_POLICY_MAX_LEN(_len) NLA_POLICY_MAX(NLA_BINARY, _len)
#endif
#endif

#endif /* LINUX_VERSION_CODE < KERNEL_VERSION(6, 13, 0) */

#if LINUX_VERSION_CODE < KERNEL_VERSION(6, 7, 0)

static inline int ovpn_nla_put_uint(struct sk_buff *skb, int attrtype,
				    u64 value)
{
	u64 tmp64 = value;
	u32 tmp32 = value;

	if (tmp64 == tmp32)
		return nla_put_u32(skb, attrtype, tmp32);
	return nla_put(skb, attrtype, sizeof(u64), &tmp64);
}

#define nla_put_uint ovpn_nla_put_uint
#define NLA_UINT NLA_U64

#endif /* LINUX_VERSION_CODE < KERNEL_VERSION(6, 7, 0) */

#if LINUX_VERSION_CODE < KERNEL_VERSION(6, 7, 0)

#undef NLA_POLICY_FULL_RANGE
#define NLA_POLICY_FULL_RANGE(tp, _range)                           \
	{                                                           \
		.type = NLA_ENSURE_UINT_OR_BINARY_TYPE(tp),         \
		.validation_type = NLA_VALIDATE_RANGE_PTR,          \
		.range = (struct netlink_range_validation *)_range, \
	}

#endif /* LINUX_VERSION_CODE < KERNEL_VERSION(6, 7, 0) */

#if LINUX_VERSION_CODE < KERNEL_VERSION(6, 1, 0)

#define NLA_BE16 NLA_U16
#define NLA_BE32 NLA_U32

#endif /* LINUX_VERSION_CODE < KERNEL_VERSION(6, 1, 0) */

#endif /* _NET_OVPN_NET_NETLINK_H_ */
