static __be32 rpfilter_get_saddr(__be32 addr)
{
if (ipv4_is_multicast(addr) || ipv4_is_lbcast(addr) ||
ipv4_is_zeronet(addr))
return 0;
return addr;
}
static bool rpfilter_lookup_reverse(struct flowi4 *fl4,
const struct net_device *dev, u8 flags)
{
struct fib_result res;
bool dev_match;
struct net *net = dev_net(dev);
int ret __maybe_unused;
if (fib_lookup(net, fl4, &res))
return false;
if (res.type != RTN_UNICAST) {
if (res.type != RTN_LOCAL || !(flags & XT_RPFILTER_ACCEPT_LOCAL))
return false;
}
dev_match = false;
#ifdef CONFIG_IP_ROUTE_MULTIPATH
for (ret = 0; ret < res.fi->fib_nhs; ret++) {
struct fib_nh *nh = &res.fi->fib_nh[ret];
if (nh->nh_dev == dev) {
dev_match = true;
break;
}
}
#else
if (FIB_RES_DEV(res) == dev)
dev_match = true;
#endif
if (dev_match || flags & XT_RPFILTER_LOOSE)
return FIB_RES_NH(res).nh_scope <= RT_SCOPE_HOST;
return dev_match;
}
static bool rpfilter_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
const struct xt_rpfilter_info *info;
const struct iphdr *iph;
struct flowi4 flow;
bool invert;
info = par->matchinfo;
invert = info->flags & XT_RPFILTER_INVERT;
if (par->in->flags & IFF_LOOPBACK)
return true ^ invert;
iph = ip_hdr(skb);
if (ipv4_is_multicast(iph->daddr)) {
if (ipv4_is_zeronet(iph->saddr))
return ipv4_is_local_multicast(iph->daddr) ^ invert;
flow.flowi4_iif = 0;
} else {
flow.flowi4_iif = LOOPBACK_IFINDEX;
}
flow.daddr = iph->saddr;
flow.saddr = rpfilter_get_saddr(iph->daddr);
flow.flowi4_oif = 0;
flow.flowi4_mark = info->flags & XT_RPFILTER_VALID_MARK ? skb->mark : 0;
flow.flowi4_tos = RT_TOS(iph->tos);
flow.flowi4_scope = RT_SCOPE_UNIVERSE;
return rpfilter_lookup_reverse(&flow, par->in, info->flags) ^ invert;
}
static int rpfilter_check(const struct xt_mtchk_param *par)
{
const struct xt_rpfilter_info *info = par->matchinfo;
unsigned int options = ~XT_RPFILTER_OPTION_MASK;
if (info->flags & options) {
pr_info("unknown options encountered");
return -EINVAL;
}
if (strcmp(par->table, "mangle") != 0 &&
strcmp(par->table, "raw") != 0) {
pr_info("match only valid in the \'raw\' "
"or \'mangle\' tables, not \'%s\'.\n", par->table);
return -EINVAL;
}
return 0;
}
static int __init rpfilter_mt_init(void)
{
return xt_register_match(&rpfilter_mt_reg);
}
static void __exit rpfilter_mt_exit(void)
{
xt_unregister_match(&rpfilter_mt_reg);
}
