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
static int ipv6_get_l4proto(const struct sk_buff *skb, unsigned int nhoff,
unsigned int *dataoff, u_int8_t *protonum)
{
unsigned int extoff = nhoff + sizeof(struct ipv6hdr);
__be16 frag_off;
int protoff;
u8 nexthdr;
if (skb_copy_bits(skb, nhoff + offsetof(struct ipv6hdr, nexthdr),
&nexthdr, sizeof(nexthdr)) != 0) {
pr_debug("ip6_conntrack_core: can't get nexthdr\n");
return -NF_ACCEPT;
}
protoff = ipv6_skip_exthdr(skb, extoff, &nexthdr, &frag_off);
if (protoff < 0 || (frag_off & htons(~0x7)) != 0) {
pr_debug("ip6_conntrack_core: can't find proto in pkt\n");
return -NF_ACCEPT;
}
*dataoff = protoff;
*protonum = nexthdr;
return NF_ACCEPT;
}
static unsigned int ipv6_helper(unsigned int hooknum,
struct sk_buff *skb,
const struct net_device *in,
const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
struct nf_conn *ct;
const struct nf_conn_help *help;
const struct nf_conntrack_helper *helper;
enum ip_conntrack_info ctinfo;
unsigned int ret;
__be16 frag_off;
int protoff;
u8 nexthdr;
ct = nf_ct_get(skb, &ctinfo);
if (!ct || ctinfo == IP_CT_RELATED_REPLY)
return NF_ACCEPT;
help = nfct_help(ct);
if (!help)
return NF_ACCEPT;
helper = rcu_dereference(help->helper);
if (!helper)
return NF_ACCEPT;
nexthdr = ipv6_hdr(skb)->nexthdr;
protoff = ipv6_skip_exthdr(skb, sizeof(struct ipv6hdr), &nexthdr,
&frag_off);
if (protoff < 0 || (frag_off & htons(~0x7)) != 0) {
pr_debug("proto header not found\n");
return NF_ACCEPT;
}
ret = helper->help(skb, protoff, ct, ctinfo);
if (ret != NF_ACCEPT && (ret & NF_VERDICT_MASK) != NF_QUEUE) {
nf_log_packet(NFPROTO_IPV6, hooknum, skb, in, out, NULL,
"nf_ct_%s: dropping packet", helper->name);
}
return ret;
}
static unsigned int ipv6_confirm(unsigned int hooknum,
struct sk_buff *skb,
const struct net_device *in,
const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
struct nf_conn *ct;
enum ip_conntrack_info ctinfo;
unsigned char pnum = ipv6_hdr(skb)->nexthdr;
int protoff;
__be16 frag_off;
ct = nf_ct_get(skb, &ctinfo);
if (!ct || ctinfo == IP_CT_RELATED_REPLY)
goto out;
protoff = ipv6_skip_exthdr(skb, sizeof(struct ipv6hdr), &pnum,
&frag_off);
if (protoff < 0 || (frag_off & htons(~0x7)) != 0) {
pr_debug("proto header not found\n");
goto out;
}
if (test_bit(IPS_SEQ_ADJUST_BIT, &ct->status) &&
!nf_is_loopback_packet(skb)) {
typeof(nf_nat_seq_adjust_hook) seq_adjust;
seq_adjust = rcu_dereference(nf_nat_seq_adjust_hook);
if (!seq_adjust ||
!seq_adjust(skb, ct, ctinfo, protoff)) {
NF_CT_STAT_INC_ATOMIC(nf_ct_net(ct), drop);
return NF_DROP;
}
}
out:
return nf_conntrack_confirm(skb);
}
static unsigned int __ipv6_conntrack_in(struct net *net,
unsigned int hooknum,
struct sk_buff *skb,
const struct net_device *in,
const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
struct sk_buff *reasm = skb->nfct_reasm;
const struct nf_conn_help *help;
struct nf_conn *ct;
enum ip_conntrack_info ctinfo;
if (reasm) {
if (!reasm->nfct) {
unsigned int ret;
ret = nf_conntrack_in(net, PF_INET6, hooknum, reasm);
if (ret != NF_ACCEPT)
return ret;
}
ct = nf_ct_get(reasm, &ctinfo);
if (ct != NULL && !nf_ct_is_untracked(ct)) {
help = nfct_help(ct);
if ((help && help->helper) || !nf_ct_is_confirmed(ct)) {
nf_conntrack_get_reasm(skb);
NF_HOOK_THRESH(NFPROTO_IPV6, hooknum, reasm,
(struct net_device *)in,
(struct net_device *)out,
okfn, NF_IP6_PRI_CONNTRACK + 1);
return NF_DROP_ERR(-ECANCELED);
}
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
return __ipv6_conntrack_in(dev_net(in), hooknum, skb, in, out, okfn);
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
return __ipv6_conntrack_in(dev_net(out), hooknum, skb, in, out, okfn);
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
static int ipv6_net_init(struct net *net)
{
int ret = 0;
ret = nf_conntrack_l4proto_register(net,
&nf_conntrack_l4proto_tcp6);
if (ret < 0) {
printk(KERN_ERR "nf_conntrack_l4proto_tcp6: protocol register failed\n");
goto out;
}
ret = nf_conntrack_l4proto_register(net,
&nf_conntrack_l4proto_udp6);
if (ret < 0) {
printk(KERN_ERR "nf_conntrack_l4proto_udp6: protocol register failed\n");
goto cleanup_tcp6;
}
ret = nf_conntrack_l4proto_register(net,
&nf_conntrack_l4proto_icmpv6);
if (ret < 0) {
printk(KERN_ERR "nf_conntrack_l4proto_icmp6: protocol register failed\n");
goto cleanup_udp6;
}
ret = nf_conntrack_l3proto_register(net,
&nf_conntrack_l3proto_ipv6);
if (ret < 0) {
printk(KERN_ERR "nf_conntrack_l3proto_ipv6: protocol register failed\n");
goto cleanup_icmpv6;
}
return 0;
cleanup_icmpv6:
nf_conntrack_l4proto_unregister(net,
&nf_conntrack_l4proto_icmpv6);
cleanup_udp6:
nf_conntrack_l4proto_unregister(net,
&nf_conntrack_l4proto_udp6);
cleanup_tcp6:
nf_conntrack_l4proto_unregister(net,
&nf_conntrack_l4proto_tcp6);
out:
return ret;
}
static void ipv6_net_exit(struct net *net)
{
nf_conntrack_l3proto_unregister(net,
&nf_conntrack_l3proto_ipv6);
nf_conntrack_l4proto_unregister(net,
&nf_conntrack_l4proto_icmpv6);
nf_conntrack_l4proto_unregister(net,
&nf_conntrack_l4proto_udp6);
nf_conntrack_l4proto_unregister(net,
&nf_conntrack_l4proto_tcp6);
}
static int __init nf_conntrack_l3proto_ipv6_init(void)
{
int ret = 0;
need_conntrack();
nf_defrag_ipv6_enable();
ret = register_pernet_subsys(&ipv6_net_ops);
if (ret < 0)
goto cleanup_pernet;
ret = nf_register_hooks(ipv6_conntrack_ops,
ARRAY_SIZE(ipv6_conntrack_ops));
if (ret < 0) {
pr_err("nf_conntrack_ipv6: can't register pre-routing defrag "
"hook.\n");
goto cleanup_ipv6;
}
return ret;
cleanup_ipv6:
unregister_pernet_subsys(&ipv6_net_ops);
cleanup_pernet:
return ret;
}
static void __exit nf_conntrack_l3proto_ipv6_fini(void)
{
synchronize_net();
nf_unregister_hooks(ipv6_conntrack_ops, ARRAY_SIZE(ipv6_conntrack_ops));
unregister_pernet_subsys(&ipv6_net_ops);
}
