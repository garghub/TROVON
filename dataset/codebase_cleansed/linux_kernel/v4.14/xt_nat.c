static int xt_nat_checkentry_v0(const struct xt_tgchk_param *par)
{
const struct nf_nat_ipv4_multi_range_compat *mr = par->targinfo;
if (mr->rangesize != 1) {
pr_info("%s: multiple ranges no longer supported\n",
par->target->name);
return -EINVAL;
}
return nf_ct_netns_get(par->net, par->family);
}
static int xt_nat_checkentry(const struct xt_tgchk_param *par)
{
return nf_ct_netns_get(par->net, par->family);
}
static void xt_nat_destroy(const struct xt_tgdtor_param *par)
{
nf_ct_netns_put(par->net, par->family);
}
static void xt_nat_convert_range(struct nf_nat_range *dst,
const struct nf_nat_ipv4_range *src)
{
memset(&dst->min_addr, 0, sizeof(dst->min_addr));
memset(&dst->max_addr, 0, sizeof(dst->max_addr));
dst->flags = src->flags;
dst->min_addr.ip = src->min_ip;
dst->max_addr.ip = src->max_ip;
dst->min_proto = src->min;
dst->max_proto = src->max;
}
static unsigned int
xt_snat_target_v0(struct sk_buff *skb, const struct xt_action_param *par)
{
const struct nf_nat_ipv4_multi_range_compat *mr = par->targinfo;
struct nf_nat_range range;
enum ip_conntrack_info ctinfo;
struct nf_conn *ct;
ct = nf_ct_get(skb, &ctinfo);
WARN_ON(!(ct != NULL &&
(ctinfo == IP_CT_NEW || ctinfo == IP_CT_RELATED ||
ctinfo == IP_CT_RELATED_REPLY)));
xt_nat_convert_range(&range, &mr->range[0]);
return nf_nat_setup_info(ct, &range, NF_NAT_MANIP_SRC);
}
static unsigned int
xt_dnat_target_v0(struct sk_buff *skb, const struct xt_action_param *par)
{
const struct nf_nat_ipv4_multi_range_compat *mr = par->targinfo;
struct nf_nat_range range;
enum ip_conntrack_info ctinfo;
struct nf_conn *ct;
ct = nf_ct_get(skb, &ctinfo);
WARN_ON(!(ct != NULL &&
(ctinfo == IP_CT_NEW || ctinfo == IP_CT_RELATED)));
xt_nat_convert_range(&range, &mr->range[0]);
return nf_nat_setup_info(ct, &range, NF_NAT_MANIP_DST);
}
static unsigned int
xt_snat_target_v1(struct sk_buff *skb, const struct xt_action_param *par)
{
const struct nf_nat_range *range = par->targinfo;
enum ip_conntrack_info ctinfo;
struct nf_conn *ct;
ct = nf_ct_get(skb, &ctinfo);
WARN_ON(!(ct != NULL &&
(ctinfo == IP_CT_NEW || ctinfo == IP_CT_RELATED ||
ctinfo == IP_CT_RELATED_REPLY)));
return nf_nat_setup_info(ct, range, NF_NAT_MANIP_SRC);
}
static unsigned int
xt_dnat_target_v1(struct sk_buff *skb, const struct xt_action_param *par)
{
const struct nf_nat_range *range = par->targinfo;
enum ip_conntrack_info ctinfo;
struct nf_conn *ct;
ct = nf_ct_get(skb, &ctinfo);
WARN_ON(!(ct != NULL &&
(ctinfo == IP_CT_NEW || ctinfo == IP_CT_RELATED)));
return nf_nat_setup_info(ct, range, NF_NAT_MANIP_DST);
}
static int __init xt_nat_init(void)
{
return xt_register_targets(xt_nat_target_reg,
ARRAY_SIZE(xt_nat_target_reg));
}
static void __exit xt_nat_exit(void)
{
xt_unregister_targets(xt_nat_target_reg, ARRAY_SIZE(xt_nat_target_reg));
}
