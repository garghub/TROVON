static bool ipv6_pkt_to_tuple(const struct sk_buff *skb, unsigned int nhoff,
struct nf_conntrack_tuple *tuple)
{
const u_int32_t *ap;
u_int32_t _addrs[8];
ap = skb_header_pointer(skb, nhoff + offsetof(struct ipv6hdr, saddr),
sizeof(_addrs), _addrs);
if (ap == NULL)
return false;
memcpy(tuple->src.u3.ip6, ap, sizeof(tuple->src.u3.ip6));
memcpy(tuple->dst.u3.ip6, ap + 4, sizeof(tuple->dst.u3.ip6));
return true;
}
static bool ipv6_invert_tuple(struct nf_conntrack_tuple *tuple,
const struct nf_conntrack_tuple *orig)
{
memcpy(tuple->src.u3.ip6, orig->dst.u3.ip6, sizeof(tuple->src.u3.ip6));
memcpy(tuple->dst.u3.ip6, orig->src.u3.ip6, sizeof(tuple->dst.u3.ip6));
return true;
}
static int ipv6_print_tuple(struct seq_file *s,
const struct nf_conntrack_tuple *tuple)
{
return seq_printf(s, "src=%pI6 dst=%pI6 ",
tuple->src.u3.ip6, tuple->dst.u3.ip6);
}
static int nf_ct_ipv6_skip_exthdr(const struct sk_buff *skb, int start,
u8 *nexthdrp, int len)
{
u8 nexthdr = *nexthdrp;
while (ipv6_ext_hdr(nexthdr)) {
struct ipv6_opt_hdr hdr;
int hdrlen;
if (len < (int)sizeof(struct ipv6_opt_hdr))
return -1;
if (nexthdr == NEXTHDR_NONE)
break;
if (nexthdr == NEXTHDR_FRAGMENT)
break;
if (skb_copy_bits(skb, start, &hdr, sizeof(hdr)))
BUG();
if (nexthdr == NEXTHDR_AUTH)
hdrlen = (hdr.hdrlen+2)<<2;
else
hdrlen = ipv6_optlen(&hdr);
nexthdr = hdr.nexthdr;
len -= hdrlen;
start += hdrlen;
}
*nexthdrp = nexthdr;
return start;
}
static int ipv6_get_l4proto(const struct sk_buff *skb, unsigned int nhoff,
unsigned int *dataoff, u_int8_t *protonum)
{
unsigned int extoff = nhoff + sizeof(struct ipv6hdr);
unsigned char pnum;
int protoff;
if (skb_copy_bits(skb, nhoff + offsetof(struct ipv6hdr, nexthdr),
&pnum, sizeof(pnum)) != 0) {
pr_debug("ip6_conntrack_core: can't get nexthdr\n");
return -NF_ACCEPT;
}
protoff = nf_ct_ipv6_skip_exthdr(skb, extoff, &pnum, skb->len - extoff);
if ((protoff < 0) || (protoff > skb->len)) {
pr_debug("ip6_conntrack_core: can't find proto in pkt\n");
return -NF_ACCEPT;
}
*dataoff = protoff;
*protonum = pnum;
return NF_ACCEPT;
}
static unsigned int ipv6_confirm(unsigned int hooknum,
struct sk_buff *skb,
const struct net_device *in,
const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
struct nf_conn *ct;
const struct nf_conn_help *help;
const struct nf_conntrack_helper *helper;
enum ip_conntrack_info ctinfo;
unsigned int ret, protoff;
unsigned int extoff = (u8 *)(ipv6_hdr(skb) + 1) - skb->data;
unsigned char pnum = ipv6_hdr(skb)->nexthdr;
ct = nf_ct_get(skb, &ctinfo);
if (!ct || ctinfo == IP_CT_RELATED_REPLY)
goto out;
help = nfct_help(ct);
if (!help)
goto out;
helper = rcu_dereference(help->helper);
if (!helper)
goto out;
protoff = nf_ct_ipv6_skip_exthdr(skb, extoff, &pnum,
skb->len - extoff);
if (protoff > skb->len || pnum == NEXTHDR_FRAGMENT) {
pr_debug("proto header not found\n");
return NF_ACCEPT;
}
ret = helper->help(skb, protoff, ct, ctinfo);
if (ret != NF_ACCEPT) {
nf_log_packet(NFPROTO_IPV6, hooknum, skb, in, out, NULL,
"nf_ct_%s: dropping packet", helper->name);
return ret;
}
out:
return nf_conntrack_confirm(skb);
}
static unsigned int __ipv6_conntrack_in(struct net *net,
unsigned int hooknum,
struct sk_buff *skb,
int (*okfn)(struct sk_buff *))
{
struct sk_buff *reasm = skb->nfct_reasm;
if (reasm) {
if (!reasm->nfct) {
unsigned int ret;
ret = nf_conntrack_in(net, PF_INET6, hooknum, reasm);
if (ret != NF_ACCEPT)
return ret;
}
nf_conntrack_get(reasm->nfct);
skb->nfct = reasm->nfct;
skb->nfctinfo = reasm->nfctinfo;
return NF_ACCEPT;
}
return nf_conntrack_in(net, PF_INET6, hooknum, skb);
}
static unsigned int ipv6_conntrack_in(unsigned int hooknum,
struct sk_buff *skb,
const struct net_device *in,
const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
return __ipv6_conntrack_in(dev_net(in), hooknum, skb, okfn);
}
static unsigned int ipv6_conntrack_local(unsigned int hooknum,
struct sk_buff *skb,
const struct net_device *in,
const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
if (skb->len < sizeof(struct ipv6hdr)) {
net_notice_ratelimited("ipv6_conntrack_local: packet too short\n");
return NF_ACCEPT;
}
return __ipv6_conntrack_in(dev_net(out), hooknum, skb, okfn);
}
static int ipv6_tuple_to_nlattr(struct sk_buff *skb,
const struct nf_conntrack_tuple *tuple)
{
if (nla_put(skb, CTA_IP_V6_SRC, sizeof(u_int32_t) * 4,
&tuple->src.u3.ip6) ||
nla_put(skb, CTA_IP_V6_DST, sizeof(u_int32_t) * 4,
&tuple->dst.u3.ip6))
goto nla_put_failure;
return 0;
nla_put_failure:
return -1;
}
static int ipv6_nlattr_to_tuple(struct nlattr *tb[],
struct nf_conntrack_tuple *t)
{
if (!tb[CTA_IP_V6_SRC] || !tb[CTA_IP_V6_DST])
return -EINVAL;
memcpy(&t->src.u3.ip6, nla_data(tb[CTA_IP_V6_SRC]),
sizeof(u_int32_t) * 4);
memcpy(&t->dst.u3.ip6, nla_data(tb[CTA_IP_V6_DST]),
sizeof(u_int32_t) * 4);
return 0;
}
static int ipv6_nlattr_tuple_size(void)
{
return nla_policy_len(ipv6_nla_policy, CTA_IP_MAX + 1);
}
static int __init nf_conntrack_l3proto_ipv6_init(void)
{
int ret = 0;
need_conntrack();
nf_defrag_ipv6_enable();
ret = nf_conntrack_l4proto_register(&nf_conntrack_l4proto_tcp6);
if (ret < 0) {
pr_err("nf_conntrack_ipv6: can't register tcp.\n");
return ret;
}
ret = nf_conntrack_l4proto_register(&nf_conntrack_l4proto_udp6);
if (ret < 0) {
pr_err("nf_conntrack_ipv6: can't register udp.\n");
goto cleanup_tcp;
}
ret = nf_conntrack_l4proto_register(&nf_conntrack_l4proto_icmpv6);
if (ret < 0) {
pr_err("nf_conntrack_ipv6: can't register icmpv6.\n");
goto cleanup_udp;
}
ret = nf_conntrack_l3proto_register(&nf_conntrack_l3proto_ipv6);
if (ret < 0) {
pr_err("nf_conntrack_ipv6: can't register ipv6\n");
goto cleanup_icmpv6;
}
ret = nf_register_hooks(ipv6_conntrack_ops,
ARRAY_SIZE(ipv6_conntrack_ops));
if (ret < 0) {
pr_err("nf_conntrack_ipv6: can't register pre-routing defrag "
"hook.\n");
goto cleanup_ipv6;
}
return ret;
cleanup_ipv6:
nf_conntrack_l3proto_unregister(&nf_conntrack_l3proto_ipv6);
cleanup_icmpv6:
nf_conntrack_l4proto_unregister(&nf_conntrack_l4proto_icmpv6);
cleanup_udp:
nf_conntrack_l4proto_unregister(&nf_conntrack_l4proto_udp6);
cleanup_tcp:
nf_conntrack_l4proto_unregister(&nf_conntrack_l4proto_tcp6);
return ret;
}
static void __exit nf_conntrack_l3proto_ipv6_fini(void)
{
synchronize_net();
nf_unregister_hooks(ipv6_conntrack_ops, ARRAY_SIZE(ipv6_conntrack_ops));
nf_conntrack_l3proto_unregister(&nf_conntrack_l3proto_ipv6);
nf_conntrack_l4proto_unregister(&nf_conntrack_l4proto_icmpv6);
nf_conntrack_l4proto_unregister(&nf_conntrack_l4proto_udp6);
nf_conntrack_l4proto_unregister(&nf_conntrack_l4proto_tcp6);
}
