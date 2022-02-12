static bool ipvs_mt_addrcmp(const union nf_inet_addr *kaddr,
const union nf_inet_addr *uaddr,
const union nf_inet_addr *umask,
unsigned int l3proto)
{
if (l3proto == NFPROTO_IPV4)
return ((kaddr->ip ^ uaddr->ip) & umask->ip) == 0;
#ifdef CONFIG_IP_VS_IPV6
else if (l3proto == NFPROTO_IPV6)
return ipv6_masked_addr_cmp(&kaddr->in6, &umask->in6,
&uaddr->in6) == 0;
#endif
else
return false;
}
static bool
ipvs_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
const struct xt_ipvs_mtinfo *data = par->matchinfo;
struct netns_ipvs *ipvs = net_ipvs(xt_net(par));
const u_int8_t family = xt_family(par);
struct ip_vs_iphdr iph;
struct ip_vs_protocol *pp;
struct ip_vs_conn *cp;
bool match = true;
if (data->bitmask == XT_IPVS_IPVS_PROPERTY) {
match = skb->ipvs_property ^
!!(data->invert & XT_IPVS_IPVS_PROPERTY);
goto out;
}
if (!skb->ipvs_property) {
match = false;
goto out;
}
ip_vs_fill_iph_skb(family, skb, true, &iph);
if (data->bitmask & XT_IPVS_PROTO)
if ((iph.protocol == data->l4proto) ^
!(data->invert & XT_IPVS_PROTO)) {
match = false;
goto out;
}
pp = ip_vs_proto_get(iph.protocol);
if (unlikely(!pp)) {
match = false;
goto out;
}
cp = pp->conn_out_get(ipvs, family, skb, &iph);
if (unlikely(cp == NULL)) {
match = false;
goto out;
}
if (data->bitmask & XT_IPVS_VPORT)
if ((cp->vport == data->vport) ^
!(data->invert & XT_IPVS_VPORT)) {
match = false;
goto out_put_cp;
}
if (data->bitmask & XT_IPVS_VPORTCTL)
if ((cp->control != NULL &&
cp->control->vport == data->vportctl) ^
!(data->invert & XT_IPVS_VPORTCTL)) {
match = false;
goto out_put_cp;
}
if (data->bitmask & XT_IPVS_DIR) {
enum ip_conntrack_info ctinfo;
struct nf_conn *ct = nf_ct_get(skb, &ctinfo);
if (ct == NULL || nf_ct_is_untracked(ct)) {
match = false;
goto out_put_cp;
}
if ((ctinfo >= IP_CT_IS_REPLY) ^
!!(data->invert & XT_IPVS_DIR)) {
match = false;
goto out_put_cp;
}
}
if (data->bitmask & XT_IPVS_METHOD)
if (((cp->flags & IP_VS_CONN_F_FWD_MASK) == data->fwd_method) ^
!(data->invert & XT_IPVS_METHOD)) {
match = false;
goto out_put_cp;
}
if (data->bitmask & XT_IPVS_VADDR) {
if (ipvs_mt_addrcmp(&cp->vaddr, &data->vaddr,
&data->vmask, family) ^
!(data->invert & XT_IPVS_VADDR)) {
match = false;
goto out_put_cp;
}
}
out_put_cp:
__ip_vs_conn_put(cp);
out:
pr_debug("match=%d\n", match);
return match;
}
static int ipvs_mt_check(const struct xt_mtchk_param *par)
{
if (par->family != NFPROTO_IPV4
#ifdef CONFIG_IP_VS_IPV6
&& par->family != NFPROTO_IPV6
#endif
) {
pr_info("protocol family %u not supported\n", par->family);
return -EINVAL;
}
return 0;
}
static int __init ipvs_mt_init(void)
{
return xt_register_match(&xt_ipvs_mt_reg);
}
static void __exit ipvs_mt_exit(void)
{
xt_unregister_match(&xt_ipvs_mt_reg);
}
