static __always_inline void net_secret_init(void)
{
net_get_random_once(&ts_secret, sizeof(ts_secret));
net_get_random_once(&net_secret, sizeof(net_secret));
}
static u32 seq_scale(u32 seq)
{
return seq + (ktime_get_real_ns() >> 6);
}
static u32 secure_tcpv6_ts_off(const __be32 *saddr, const __be32 *daddr)
{
const struct {
struct in6_addr saddr;
struct in6_addr daddr;
} __aligned(SIPHASH_ALIGNMENT) combined = {
.saddr = *(struct in6_addr *)saddr,
.daddr = *(struct in6_addr *)daddr,
};
if (sysctl_tcp_timestamps != 1)
return 0;
return siphash(&combined, offsetofend(typeof(combined), daddr),
&ts_secret);
}
u32 secure_tcpv6_sequence_number(const __be32 *saddr, const __be32 *daddr,
__be16 sport, __be16 dport, u32 *tsoff)
{
const struct {
struct in6_addr saddr;
struct in6_addr daddr;
__be16 sport;
__be16 dport;
} __aligned(SIPHASH_ALIGNMENT) combined = {
.saddr = *(struct in6_addr *)saddr,
.daddr = *(struct in6_addr *)daddr,
.sport = sport,
.dport = dport
};
u64 hash;
net_secret_init();
hash = siphash(&combined, offsetofend(typeof(combined), dport),
&net_secret);
*tsoff = secure_tcpv6_ts_off(saddr, daddr);
return seq_scale(hash);
}
u32 secure_ipv6_port_ephemeral(const __be32 *saddr, const __be32 *daddr,
__be16 dport)
{
const struct {
struct in6_addr saddr;
struct in6_addr daddr;
__be16 dport;
} __aligned(SIPHASH_ALIGNMENT) combined = {
.saddr = *(struct in6_addr *)saddr,
.daddr = *(struct in6_addr *)daddr,
.dport = dport
};
net_secret_init();
return siphash(&combined, offsetofend(typeof(combined), dport),
&net_secret);
}
static u32 secure_tcp_ts_off(__be32 saddr, __be32 daddr)
{
if (sysctl_tcp_timestamps != 1)
return 0;
return siphash_2u32((__force u32)saddr, (__force u32)daddr,
&ts_secret);
}
u32 secure_tcp_sequence_number(__be32 saddr, __be32 daddr,
__be16 sport, __be16 dport, u32 *tsoff)
{
u64 hash;
net_secret_init();
hash = siphash_3u32((__force u32)saddr, (__force u32)daddr,
(__force u32)sport << 16 | (__force u32)dport,
&net_secret);
*tsoff = secure_tcp_ts_off(saddr, daddr);
return seq_scale(hash);
}
u32 secure_ipv4_port_ephemeral(__be32 saddr, __be32 daddr, __be16 dport)
{
net_secret_init();
return siphash_3u32((__force u32)saddr, (__force u32)daddr,
(__force u16)dport, &net_secret);
}
u64 secure_dccp_sequence_number(__be32 saddr, __be32 daddr,
__be16 sport, __be16 dport)
{
u64 seq;
net_secret_init();
seq = siphash_3u32((__force u32)saddr, (__force u32)daddr,
(__force u32)sport << 16 | (__force u32)dport,
&net_secret);
seq += ktime_get_real_ns();
seq &= (1ull << 48) - 1;
return seq;
}
u64 secure_dccpv6_sequence_number(__be32 *saddr, __be32 *daddr,
__be16 sport, __be16 dport)
{
const struct {
struct in6_addr saddr;
struct in6_addr daddr;
__be16 sport;
__be16 dport;
} __aligned(SIPHASH_ALIGNMENT) combined = {
.saddr = *(struct in6_addr *)saddr,
.daddr = *(struct in6_addr *)daddr,
.sport = sport,
.dport = dport
};
u64 seq;
net_secret_init();
seq = siphash(&combined, offsetofend(typeof(combined), dport),
&net_secret);
seq += ktime_get_real_ns();
seq &= (1ull << 48) - 1;
return seq;
}
