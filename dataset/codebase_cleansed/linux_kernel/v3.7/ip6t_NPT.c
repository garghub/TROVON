static __sum16 csum16_complement(__sum16 a)
{
return (__force __sum16)(0xffff - (__force u16)a);
}
static __sum16 csum16_add(__sum16 a, __sum16 b)
{
u16 sum;
sum = (__force u16)a + (__force u16)b;
sum += (__force u16)a < (__force u16)b;
return (__force __sum16)sum;
}
static __sum16 csum16_sub(__sum16 a, __sum16 b)
{
return csum16_add(a, csum16_complement(b));
}
static int ip6t_npt_checkentry(const struct xt_tgchk_param *par)
{
struct ip6t_npt_tginfo *npt = par->targinfo;
__sum16 src_sum = 0, dst_sum = 0;
unsigned int i;
if (npt->src_pfx_len > 64 || npt->dst_pfx_len > 64)
return -EINVAL;
for (i = 0; i < ARRAY_SIZE(npt->src_pfx.in6.s6_addr16); i++) {
src_sum = csum16_add(src_sum,
(__force __sum16)npt->src_pfx.in6.s6_addr16[i]);
dst_sum = csum16_add(dst_sum,
(__force __sum16)npt->dst_pfx.in6.s6_addr16[i]);
}
npt->adjustment = csum16_sub(src_sum, dst_sum);
return 0;
}
static bool ip6t_npt_map_pfx(const struct ip6t_npt_tginfo *npt,
struct in6_addr *addr)
{
unsigned int pfx_len;
unsigned int i, idx;
__be32 mask;
__sum16 sum;
pfx_len = max(npt->src_pfx_len, npt->dst_pfx_len);
for (i = 0; i < pfx_len; i += 32) {
if (pfx_len - i >= 32)
mask = 0;
else
mask = htonl(~((1 << (pfx_len - i)) - 1));
idx = i / 32;
addr->s6_addr32[idx] &= mask;
addr->s6_addr32[idx] |= npt->dst_pfx.in6.s6_addr32[idx];
}
if (pfx_len <= 48)
idx = 3;
else {
for (idx = 4; idx < ARRAY_SIZE(addr->s6_addr16); idx++) {
if ((__force __sum16)addr->s6_addr16[idx] !=
CSUM_MANGLED_0)
break;
}
if (idx == ARRAY_SIZE(addr->s6_addr16))
return false;
}
sum = csum16_add((__force __sum16)addr->s6_addr16[idx],
npt->adjustment);
if (sum == CSUM_MANGLED_0)
sum = 0;
*(__force __sum16 *)&addr->s6_addr16[idx] = sum;
return true;
}
static unsigned int
ip6t_snpt_tg(struct sk_buff *skb, const struct xt_action_param *par)
{
const struct ip6t_npt_tginfo *npt = par->targinfo;
if (!ip6t_npt_map_pfx(npt, &ipv6_hdr(skb)->saddr)) {
icmpv6_send(skb, ICMPV6_PARAMPROB, ICMPV6_HDR_FIELD,
offsetof(struct ipv6hdr, saddr));
return NF_DROP;
}
return XT_CONTINUE;
}
static unsigned int
ip6t_dnpt_tg(struct sk_buff *skb, const struct xt_action_param *par)
{
const struct ip6t_npt_tginfo *npt = par->targinfo;
if (!ip6t_npt_map_pfx(npt, &ipv6_hdr(skb)->daddr)) {
icmpv6_send(skb, ICMPV6_PARAMPROB, ICMPV6_HDR_FIELD,
offsetof(struct ipv6hdr, daddr));
return NF_DROP;
}
return XT_CONTINUE;
}
static int __init ip6t_npt_init(void)
{
return xt_register_targets(ip6t_npt_target_reg,
ARRAY_SIZE(ip6t_npt_target_reg));
}
static void __exit ip6t_npt_exit(void)
{
xt_unregister_targets(ip6t_npt_target_reg,
ARRAY_SIZE(ip6t_npt_target_reg));
}
