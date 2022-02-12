static int ip6t_npt_checkentry(const struct xt_tgchk_param *par)
{
struct ip6t_npt_tginfo *npt = par->targinfo;
__wsum src_sum = 0, dst_sum = 0;
struct in6_addr pfx;
unsigned int i;
if (npt->src_pfx_len > 64 || npt->dst_pfx_len > 64)
return -EINVAL;
ipv6_addr_prefix(&pfx, &npt->src_pfx.in6, npt->src_pfx_len);
if (!ipv6_addr_equal(&pfx, &npt->src_pfx.in6))
return -EINVAL;
ipv6_addr_prefix(&pfx, &npt->dst_pfx.in6, npt->dst_pfx_len);
if (!ipv6_addr_equal(&pfx, &npt->dst_pfx.in6))
return -EINVAL;
for (i = 0; i < ARRAY_SIZE(npt->src_pfx.in6.s6_addr16); i++) {
src_sum = csum_add(src_sum,
(__force __wsum)npt->src_pfx.in6.s6_addr16[i]);
dst_sum = csum_add(dst_sum,
(__force __wsum)npt->dst_pfx.in6.s6_addr16[i]);
}
npt->adjustment = ~csum_fold(csum_sub(src_sum, dst_sum));
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
mask = htonl((1 << (i - pfx_len + 32)) - 1);
idx = i / 32;
addr->s6_addr32[idx] &= mask;
addr->s6_addr32[idx] |= ~mask & npt->dst_pfx.in6.s6_addr32[idx];
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
sum = ~csum_fold(csum_add(csum_unfold((__force __sum16)addr->s6_addr16[idx]),
csum_unfold(npt->adjustment)));
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
