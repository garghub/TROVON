static inline bool
set_ect_ip(struct sk_buff *skb, const struct ipt_ECN_info *einfo)
{
struct iphdr *iph = ip_hdr(skb);
if ((iph->tos & IPT_ECN_IP_MASK) != (einfo->ip_ect & IPT_ECN_IP_MASK)) {
__u8 oldtos;
if (!skb_make_writable(skb, sizeof(struct iphdr)))
return false;
iph = ip_hdr(skb);
oldtos = iph->tos;
iph->tos &= ~IPT_ECN_IP_MASK;
iph->tos |= (einfo->ip_ect & IPT_ECN_IP_MASK);
csum_replace2(&iph->check, htons(oldtos), htons(iph->tos));
}
return true;
}
static inline bool
set_ect_tcp(struct sk_buff *skb, const struct ipt_ECN_info *einfo)
{
struct tcphdr _tcph, *tcph;
__be16 oldval;
tcph = skb_header_pointer(skb, ip_hdrlen(skb), sizeof(_tcph), &_tcph);
if (!tcph)
return false;
if ((!(einfo->operation & IPT_ECN_OP_SET_ECE) ||
tcph->ece == einfo->proto.tcp.ece) &&
(!(einfo->operation & IPT_ECN_OP_SET_CWR) ||
tcph->cwr == einfo->proto.tcp.cwr))
return true;
if (!skb_make_writable(skb, ip_hdrlen(skb) + sizeof(*tcph)))
return false;
tcph = (void *)ip_hdr(skb) + ip_hdrlen(skb);
oldval = ((__be16 *)tcph)[6];
if (einfo->operation & IPT_ECN_OP_SET_ECE)
tcph->ece = einfo->proto.tcp.ece;
if (einfo->operation & IPT_ECN_OP_SET_CWR)
tcph->cwr = einfo->proto.tcp.cwr;
inet_proto_csum_replace2(&tcph->check, skb,
oldval, ((__be16 *)tcph)[6], 0);
return true;
}
static unsigned int
ecn_tg(struct sk_buff *skb, const struct xt_action_param *par)
{
const struct ipt_ECN_info *einfo = par->targinfo;
if (einfo->operation & IPT_ECN_OP_SET_IP)
if (!set_ect_ip(skb, einfo))
return NF_DROP;
if (einfo->operation & (IPT_ECN_OP_SET_ECE | IPT_ECN_OP_SET_CWR) &&
ip_hdr(skb)->protocol == IPPROTO_TCP)
if (!set_ect_tcp(skb, einfo))
return NF_DROP;
return XT_CONTINUE;
}
static int ecn_tg_check(const struct xt_tgchk_param *par)
{
const struct ipt_ECN_info *einfo = par->targinfo;
const struct ipt_entry *e = par->entryinfo;
if (einfo->operation & IPT_ECN_OP_MASK) {
pr_info("unsupported ECN operation %x\n", einfo->operation);
return -EINVAL;
}
if (einfo->ip_ect & ~IPT_ECN_IP_MASK) {
pr_info("new ECT codepoint %x out of mask\n", einfo->ip_ect);
return -EINVAL;
}
if ((einfo->operation & (IPT_ECN_OP_SET_ECE|IPT_ECN_OP_SET_CWR)) &&
(e->ip.proto != IPPROTO_TCP || (e->ip.invflags & XT_INV_PROTO))) {
pr_info("cannot use TCP operations on a non-tcp rule\n");
return -EINVAL;
}
return 0;
}
static int __init ecn_tg_init(void)
{
return xt_register_target(&ecn_tg_reg);
}
static void __exit ecn_tg_exit(void)
{
xt_unregister_target(&ecn_tg_reg);
}
