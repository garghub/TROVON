static unsigned int
dscp_tg(struct sk_buff *skb, const struct xt_action_param *par)
{
const struct xt_DSCP_info *dinfo = par->targinfo;
u_int8_t dscp = ipv4_get_dsfield(ip_hdr(skb)) >> XT_DSCP_SHIFT;
if (dscp != dinfo->dscp) {
if (!skb_make_writable(skb, sizeof(struct iphdr)))
return NF_DROP;
ipv4_change_dsfield(ip_hdr(skb), (__u8)(~XT_DSCP_MASK),
dinfo->dscp << XT_DSCP_SHIFT);
}
return XT_CONTINUE;
}
static unsigned int
dscp_tg6(struct sk_buff *skb, const struct xt_action_param *par)
{
const struct xt_DSCP_info *dinfo = par->targinfo;
u_int8_t dscp = ipv6_get_dsfield(ipv6_hdr(skb)) >> XT_DSCP_SHIFT;
if (dscp != dinfo->dscp) {
if (!skb_make_writable(skb, sizeof(struct ipv6hdr)))
return NF_DROP;
ipv6_change_dsfield(ipv6_hdr(skb), (__u8)(~XT_DSCP_MASK),
dinfo->dscp << XT_DSCP_SHIFT);
}
return XT_CONTINUE;
}
static int dscp_tg_check(const struct xt_tgchk_param *par)
{
const struct xt_DSCP_info *info = par->targinfo;
if (info->dscp > XT_DSCP_MAX) {
pr_info("dscp %x out of range\n", info->dscp);
return -EDOM;
}
return 0;
}
static unsigned int
tos_tg(struct sk_buff *skb, const struct xt_action_param *par)
{
const struct xt_tos_target_info *info = par->targinfo;
struct iphdr *iph = ip_hdr(skb);
u_int8_t orig, nv;
orig = ipv4_get_dsfield(iph);
nv = (orig & ~info->tos_mask) ^ info->tos_value;
if (orig != nv) {
if (!skb_make_writable(skb, sizeof(struct iphdr)))
return NF_DROP;
iph = ip_hdr(skb);
ipv4_change_dsfield(iph, 0, nv);
}
return XT_CONTINUE;
}
static unsigned int
tos_tg6(struct sk_buff *skb, const struct xt_action_param *par)
{
const struct xt_tos_target_info *info = par->targinfo;
struct ipv6hdr *iph = ipv6_hdr(skb);
u_int8_t orig, nv;
orig = ipv6_get_dsfield(iph);
nv = (orig & ~info->tos_mask) ^ info->tos_value;
if (orig != nv) {
if (!skb_make_writable(skb, sizeof(struct iphdr)))
return NF_DROP;
iph = ipv6_hdr(skb);
ipv6_change_dsfield(iph, 0, nv);
}
return XT_CONTINUE;
}
static int __init dscp_tg_init(void)
{
return xt_register_targets(dscp_tg_reg, ARRAY_SIZE(dscp_tg_reg));
}
static void __exit dscp_tg_exit(void)
{
xt_unregister_targets(dscp_tg_reg, ARRAY_SIZE(dscp_tg_reg));
}
