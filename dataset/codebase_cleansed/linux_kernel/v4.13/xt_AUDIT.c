static bool audit_ip4(struct audit_buffer *ab, struct sk_buff *skb)
{
struct iphdr _iph;
const struct iphdr *ih;
ih = skb_header_pointer(skb, skb_network_offset(skb), sizeof(_iph), &_iph);
if (!ih)
return false;
audit_log_format(ab, " saddr=%pI4 daddr=%pI4 proto=%hhu",
&ih->saddr, &ih->daddr, ih->protocol);
return true;
}
static bool audit_ip6(struct audit_buffer *ab, struct sk_buff *skb)
{
struct ipv6hdr _ip6h;
const struct ipv6hdr *ih;
u8 nexthdr;
__be16 frag_off;
ih = skb_header_pointer(skb, skb_network_offset(skb), sizeof(_ip6h), &_ip6h);
if (!ih)
return false;
nexthdr = ih->nexthdr;
ipv6_skip_exthdr(skb, skb_network_offset(skb) + sizeof(_ip6h), &nexthdr, &frag_off);
audit_log_format(ab, " saddr=%pI6c daddr=%pI6c proto=%hhu",
&ih->saddr, &ih->daddr, nexthdr);
return true;
}
static unsigned int
audit_tg(struct sk_buff *skb, const struct xt_action_param *par)
{
struct audit_buffer *ab;
int fam = -1;
if (audit_enabled == 0)
goto errout;
ab = audit_log_start(NULL, GFP_ATOMIC, AUDIT_NETFILTER_PKT);
if (ab == NULL)
goto errout;
audit_log_format(ab, "mark=%#x", skb->mark);
switch (xt_family(par)) {
case NFPROTO_BRIDGE:
switch (eth_hdr(skb)->h_proto) {
case htons(ETH_P_IP):
fam = audit_ip4(ab, skb) ? NFPROTO_IPV4 : -1;
break;
case htons(ETH_P_IPV6):
fam = audit_ip6(ab, skb) ? NFPROTO_IPV6 : -1;
break;
}
break;
case NFPROTO_IPV4:
fam = audit_ip4(ab, skb) ? NFPROTO_IPV4 : -1;
break;
case NFPROTO_IPV6:
fam = audit_ip6(ab, skb) ? NFPROTO_IPV6 : -1;
break;
}
if (fam == -1)
audit_log_format(ab, " saddr=? daddr=? proto=-1");
audit_log_end(ab);
errout:
return XT_CONTINUE;
}
static unsigned int
audit_tg_ebt(struct sk_buff *skb, const struct xt_action_param *par)
{
audit_tg(skb, par);
return EBT_CONTINUE;
}
static int audit_tg_check(const struct xt_tgchk_param *par)
{
const struct xt_audit_info *info = par->targinfo;
if (info->type > XT_AUDIT_TYPE_MAX) {
pr_info("Audit type out of range (valid range: 0..%hhu)\n",
XT_AUDIT_TYPE_MAX);
return -ERANGE;
}
return 0;
}
static int __init audit_tg_init(void)
{
return xt_register_targets(audit_tg_reg, ARRAY_SIZE(audit_tg_reg));
}
static void __exit audit_tg_exit(void)
{
xt_unregister_targets(audit_tg_reg, ARRAY_SIZE(audit_tg_reg));
}
