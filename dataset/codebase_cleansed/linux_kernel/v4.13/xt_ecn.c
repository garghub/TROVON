static bool match_tcp(const struct sk_buff *skb, struct xt_action_param *par)
{
const struct xt_ecn_info *einfo = par->matchinfo;
struct tcphdr _tcph;
const struct tcphdr *th;
th = skb_header_pointer(skb, par->thoff, sizeof(_tcph), &_tcph);
if (th == NULL)
return false;
if (einfo->operation & XT_ECN_OP_MATCH_ECE) {
if (einfo->invert & XT_ECN_OP_MATCH_ECE) {
if (th->ece == 1)
return false;
} else {
if (th->ece == 0)
return false;
}
}
if (einfo->operation & XT_ECN_OP_MATCH_CWR) {
if (einfo->invert & XT_ECN_OP_MATCH_CWR) {
if (th->cwr == 1)
return false;
} else {
if (th->cwr == 0)
return false;
}
}
return true;
}
static inline bool match_ip(const struct sk_buff *skb,
const struct xt_ecn_info *einfo)
{
return ((ip_hdr(skb)->tos & XT_ECN_IP_MASK) == einfo->ip_ect) ^
!!(einfo->invert & XT_ECN_OP_MATCH_IP);
}
static bool ecn_mt4(const struct sk_buff *skb, struct xt_action_param *par)
{
const struct xt_ecn_info *info = par->matchinfo;
if (info->operation & XT_ECN_OP_MATCH_IP && !match_ip(skb, info))
return false;
if (info->operation & (XT_ECN_OP_MATCH_ECE | XT_ECN_OP_MATCH_CWR) &&
!match_tcp(skb, par))
return false;
return true;
}
static int ecn_mt_check4(const struct xt_mtchk_param *par)
{
const struct xt_ecn_info *info = par->matchinfo;
const struct ipt_ip *ip = par->entryinfo;
if (info->operation & XT_ECN_OP_MATCH_MASK)
return -EINVAL;
if (info->invert & XT_ECN_OP_MATCH_MASK)
return -EINVAL;
if (info->operation & (XT_ECN_OP_MATCH_ECE | XT_ECN_OP_MATCH_CWR) &&
(ip->proto != IPPROTO_TCP || ip->invflags & IPT_INV_PROTO)) {
pr_info("cannot match TCP bits in rule for non-tcp packets\n");
return -EINVAL;
}
return 0;
}
static inline bool match_ipv6(const struct sk_buff *skb,
const struct xt_ecn_info *einfo)
{
return (((ipv6_hdr(skb)->flow_lbl[0] >> 4) & XT_ECN_IP_MASK) ==
einfo->ip_ect) ^
!!(einfo->invert & XT_ECN_OP_MATCH_IP);
}
static bool ecn_mt6(const struct sk_buff *skb, struct xt_action_param *par)
{
const struct xt_ecn_info *info = par->matchinfo;
if (info->operation & XT_ECN_OP_MATCH_IP && !match_ipv6(skb, info))
return false;
if (info->operation & (XT_ECN_OP_MATCH_ECE | XT_ECN_OP_MATCH_CWR) &&
!match_tcp(skb, par))
return false;
return true;
}
static int ecn_mt_check6(const struct xt_mtchk_param *par)
{
const struct xt_ecn_info *info = par->matchinfo;
const struct ip6t_ip6 *ip = par->entryinfo;
if (info->operation & XT_ECN_OP_MATCH_MASK)
return -EINVAL;
if (info->invert & XT_ECN_OP_MATCH_MASK)
return -EINVAL;
if (info->operation & (XT_ECN_OP_MATCH_ECE | XT_ECN_OP_MATCH_CWR) &&
(ip->proto != IPPROTO_TCP || ip->invflags & IP6T_INV_PROTO)) {
pr_info("cannot match TCP bits in rule for non-tcp packets\n");
return -EINVAL;
}
return 0;
}
static int __init ecn_mt_init(void)
{
return xt_register_matches(ecn_mt_reg, ARRAY_SIZE(ecn_mt_reg));
}
static void __exit ecn_mt_exit(void)
{
xt_unregister_matches(ecn_mt_reg, ARRAY_SIZE(ecn_mt_reg));
}
