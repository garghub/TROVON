static void audit_proto(struct audit_buffer *ab, struct sk_buff *skb,
unsigned int proto, unsigned int offset)
{
switch (proto) {
case IPPROTO_TCP:
case IPPROTO_UDP:
case IPPROTO_UDPLITE: {
const __be16 *pptr;
__be16 _ports[2];
pptr = skb_header_pointer(skb, offset, sizeof(_ports), _ports);
if (pptr == NULL) {
audit_log_format(ab, " truncated=1");
return;
}
audit_log_format(ab, " sport=%hu dport=%hu",
ntohs(pptr[0]), ntohs(pptr[1]));
}
break;
case IPPROTO_ICMP:
case IPPROTO_ICMPV6: {
const u8 *iptr;
u8 _ih[2];
iptr = skb_header_pointer(skb, offset, sizeof(_ih), &_ih);
if (iptr == NULL) {
audit_log_format(ab, " truncated=1");
return;
}
audit_log_format(ab, " icmptype=%hhu icmpcode=%hhu",
iptr[0], iptr[1]);
}
break;
}
}
static void audit_ip4(struct audit_buffer *ab, struct sk_buff *skb)
{
struct iphdr _iph;
const struct iphdr *ih;
ih = skb_header_pointer(skb, 0, sizeof(_iph), &_iph);
if (!ih) {
audit_log_format(ab, " truncated=1");
return;
}
audit_log_format(ab, " saddr=%pI4 daddr=%pI4 ipid=%hu proto=%hhu",
&ih->saddr, &ih->daddr, ntohs(ih->id), ih->protocol);
if (ntohs(ih->frag_off) & IP_OFFSET) {
audit_log_format(ab, " frag=1");
return;
}
audit_proto(ab, skb, ih->protocol, ih->ihl * 4);
}
static void audit_ip6(struct audit_buffer *ab, struct sk_buff *skb)
{
struct ipv6hdr _ip6h;
const struct ipv6hdr *ih;
u8 nexthdr;
__be16 frag_off;
int offset;
ih = skb_header_pointer(skb, skb_network_offset(skb), sizeof(_ip6h), &_ip6h);
if (!ih) {
audit_log_format(ab, " truncated=1");
return;
}
nexthdr = ih->nexthdr;
offset = ipv6_skip_exthdr(skb, skb_network_offset(skb) + sizeof(_ip6h),
&nexthdr, &frag_off);
audit_log_format(ab, " saddr=%pI6c daddr=%pI6c proto=%hhu",
&ih->saddr, &ih->daddr, nexthdr);
if (offset)
audit_proto(ab, skb, nexthdr, offset);
}
static unsigned int
audit_tg(struct sk_buff *skb, const struct xt_action_param *par)
{
const struct xt_audit_info *info = par->targinfo;
struct audit_buffer *ab;
if (audit_enabled == 0)
goto errout;
ab = audit_log_start(NULL, GFP_ATOMIC, AUDIT_NETFILTER_PKT);
if (ab == NULL)
goto errout;
audit_log_format(ab, "action=%hhu hook=%u len=%u inif=%s outif=%s",
info->type, xt_hooknum(par), skb->len,
xt_in(par) ? xt_inname(par) : "?",
xt_out(par) ? xt_outname(par) : "?");
if (skb->mark)
audit_log_format(ab, " mark=%#x", skb->mark);
if (skb->dev && skb->dev->type == ARPHRD_ETHER) {
audit_log_format(ab, " smac=%pM dmac=%pM macproto=0x%04x",
eth_hdr(skb)->h_source, eth_hdr(skb)->h_dest,
ntohs(eth_hdr(skb)->h_proto));
if (xt_family(par) == NFPROTO_BRIDGE) {
switch (eth_hdr(skb)->h_proto) {
case htons(ETH_P_IP):
audit_ip4(ab, skb);
break;
case htons(ETH_P_IPV6):
audit_ip6(ab, skb);
break;
}
}
}
switch (xt_family(par)) {
case NFPROTO_IPV4:
audit_ip4(ab, skb);
break;
case NFPROTO_IPV6:
audit_ip6(ab, skb);
break;
}
#ifdef CONFIG_NETWORK_SECMARK
if (skb->secmark)
audit_log_secctx(ab, skb->secmark);
#endif
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
