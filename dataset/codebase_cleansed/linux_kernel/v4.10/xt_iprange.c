static bool
iprange_mt4(const struct sk_buff *skb, struct xt_action_param *par)
{
const struct xt_iprange_mtinfo *info = par->matchinfo;
const struct iphdr *iph = ip_hdr(skb);
bool m;
if (info->flags & IPRANGE_SRC) {
m = ntohl(iph->saddr) < ntohl(info->src_min.ip);
m |= ntohl(iph->saddr) > ntohl(info->src_max.ip);
m ^= !!(info->flags & IPRANGE_SRC_INV);
if (m) {
pr_debug("src IP %pI4 NOT in range %s%pI4-%pI4\n",
&iph->saddr,
(info->flags & IPRANGE_SRC_INV) ? "(INV) " : "",
&info->src_min.ip,
&info->src_max.ip);
return false;
}
}
if (info->flags & IPRANGE_DST) {
m = ntohl(iph->daddr) < ntohl(info->dst_min.ip);
m |= ntohl(iph->daddr) > ntohl(info->dst_max.ip);
m ^= !!(info->flags & IPRANGE_DST_INV);
if (m) {
pr_debug("dst IP %pI4 NOT in range %s%pI4-%pI4\n",
&iph->daddr,
(info->flags & IPRANGE_DST_INV) ? "(INV) " : "",
&info->dst_min.ip,
&info->dst_max.ip);
return false;
}
}
return true;
}
static inline int
iprange_ipv6_lt(const struct in6_addr *a, const struct in6_addr *b)
{
unsigned int i;
for (i = 0; i < 4; ++i) {
if (a->s6_addr32[i] != b->s6_addr32[i])
return ntohl(a->s6_addr32[i]) < ntohl(b->s6_addr32[i]);
}
return 0;
}
static bool
iprange_mt6(const struct sk_buff *skb, struct xt_action_param *par)
{
const struct xt_iprange_mtinfo *info = par->matchinfo;
const struct ipv6hdr *iph = ipv6_hdr(skb);
bool m;
if (info->flags & IPRANGE_SRC) {
m = iprange_ipv6_lt(&iph->saddr, &info->src_min.in6);
m |= iprange_ipv6_lt(&info->src_max.in6, &iph->saddr);
m ^= !!(info->flags & IPRANGE_SRC_INV);
if (m) {
pr_debug("src IP %pI6 NOT in range %s%pI6-%pI6\n",
&iph->saddr,
(info->flags & IPRANGE_SRC_INV) ? "(INV) " : "",
&info->src_min.in6,
&info->src_max.in6);
return false;
}
}
if (info->flags & IPRANGE_DST) {
m = iprange_ipv6_lt(&iph->daddr, &info->dst_min.in6);
m |= iprange_ipv6_lt(&info->dst_max.in6, &iph->daddr);
m ^= !!(info->flags & IPRANGE_DST_INV);
if (m) {
pr_debug("dst IP %pI6 NOT in range %s%pI6-%pI6\n",
&iph->daddr,
(info->flags & IPRANGE_DST_INV) ? "(INV) " : "",
&info->dst_min.in6,
&info->dst_max.in6);
return false;
}
}
return true;
}
static int __init iprange_mt_init(void)
{
return xt_register_matches(iprange_mt_reg, ARRAY_SIZE(iprange_mt_reg));
}
static void __exit iprange_mt_exit(void)
{
xt_unregister_matches(iprange_mt_reg, ARRAY_SIZE(iprange_mt_reg));
}
