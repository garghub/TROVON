static __always_inline void net_secret_init(void)
{
net_get_random_once(net_secret, sizeof(net_secret));
}
static u32 seq_scale(u32 seq)
{
return seq + (ktime_get_real_ns() >> 6);
}
u32 secure_tcpv6_sequence_number(const __be32 *saddr, const __be32 *daddr,
__be16 sport, __be16 dport, u32 *tsoff)
{
u32 secret[MD5_MESSAGE_BYTES / 4];
u32 hash[MD5_DIGEST_WORDS];
u32 i;
net_secret_init();
memcpy(hash, saddr, 16);
for (i = 0; i < 4; i++)
secret[i] = net_secret[i] + (__force u32)daddr[i];
secret[4] = net_secret[4] +
(((__force u16)sport << 16) + (__force u16)dport);
for (i = 5; i < MD5_MESSAGE_BYTES / 4; i++)
secret[i] = net_secret[i];
md5_transform(hash, secret);
*tsoff = sysctl_tcp_timestamps == 1 ? hash[1] : 0;
return seq_scale(hash[0]);
}
u32 secure_ipv6_port_ephemeral(const __be32 *saddr, const __be32 *daddr,
__be16 dport)
{
u32 secret[MD5_MESSAGE_BYTES / 4];
u32 hash[MD5_DIGEST_WORDS];
u32 i;
net_secret_init();
memcpy(hash, saddr, 16);
for (i = 0; i < 4; i++)
secret[i] = net_secret[i] + (__force u32) daddr[i];
secret[4] = net_secret[4] + (__force u32)dport;
for (i = 5; i < MD5_MESSAGE_BYTES / 4; i++)
secret[i] = net_secret[i];
md5_transform(hash, secret);
return hash[0];
}
u32 secure_tcp_sequence_number(__be32 saddr, __be32 daddr,
__be16 sport, __be16 dport, u32 *tsoff)
{
u32 hash[MD5_DIGEST_WORDS];
net_secret_init();
hash[0] = (__force u32)saddr;
hash[1] = (__force u32)daddr;
hash[2] = ((__force u16)sport << 16) + (__force u16)dport;
hash[3] = net_secret[15];
md5_transform(hash, net_secret);
*tsoff = sysctl_tcp_timestamps == 1 ? hash[1] : 0;
return seq_scale(hash[0]);
}
u32 secure_ipv4_port_ephemeral(__be32 saddr, __be32 daddr, __be16 dport)
{
u32 hash[MD5_DIGEST_WORDS];
net_secret_init();
hash[0] = (__force u32)saddr;
hash[1] = (__force u32)daddr;
hash[2] = (__force u32)dport ^ net_secret[14];
hash[3] = net_secret[15];
md5_transform(hash, net_secret);
return hash[0];
}
u64 secure_dccp_sequence_number(__be32 saddr, __be32 daddr,
__be16 sport, __be16 dport)
{
u32 hash[MD5_DIGEST_WORDS];
u64 seq;
net_secret_init();
hash[0] = (__force u32)saddr;
hash[1] = (__force u32)daddr;
hash[2] = ((__force u16)sport << 16) + (__force u16)dport;
hash[3] = net_secret[15];
md5_transform(hash, net_secret);
seq = hash[0] | (((u64)hash[1]) << 32);
seq += ktime_get_real_ns();
seq &= (1ull << 48) - 1;
return seq;
}
u64 secure_dccpv6_sequence_number(__be32 *saddr, __be32 *daddr,
__be16 sport, __be16 dport)
{
u32 secret[MD5_MESSAGE_BYTES / 4];
u32 hash[MD5_DIGEST_WORDS];
u64 seq;
u32 i;
net_secret_init();
memcpy(hash, saddr, 16);
for (i = 0; i < 4; i++)
secret[i] = net_secret[i] + (__force u32)daddr[i];
secret[4] = net_secret[4] +
(((__force u16)sport << 16) + (__force u16)dport);
for (i = 5; i < MD5_MESSAGE_BYTES / 4; i++)
secret[i] = net_secret[i];
md5_transform(hash, secret);
seq = hash[0] | (((u64)hash[1]) << 32);
seq += ktime_get_real_ns();
seq &= (1ull << 48) - 1;
return seq;
}
