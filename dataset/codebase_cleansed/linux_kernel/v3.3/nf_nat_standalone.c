static void nat_decode_session(struct sk_buff *skb, struct flowi *fl)
{
struct flowi4 *fl4 = &fl->u.ip4;
const struct nf_conn *ct;
const struct nf_conntrack_tuple *t;
enum ip_conntrack_info ctinfo;
enum ip_conntrack_dir dir;
unsigned long statusbit;
ct = nf_ct_get(skb, &ctinfo);
if (ct == NULL)
return;
dir = CTINFO2DIR(ctinfo);
t = &ct->tuplehash[dir].tuple;
if (dir == IP_CT_DIR_ORIGINAL)
statusbit = IPS_DST_NAT;
else
statusbit = IPS_SRC_NAT;
if (ct->status & statusbit) {
fl4->daddr = t->dst.u3.ip;
if (t->dst.protonum == IPPROTO_TCP ||
t->dst.protonum == IPPROTO_UDP ||
t->dst.protonum == IPPROTO_UDPLITE ||
t->dst.protonum == IPPROTO_DCCP ||
t->dst.protonum == IPPROTO_SCTP)
fl4->fl4_dport = t->dst.u.tcp.port;
}
statusbit ^= IPS_NAT_MASK;
if (ct->status & statusbit) {
fl4->saddr = t->src.u3.ip;
if (t->dst.protonum == IPPROTO_TCP ||
t->dst.protonum == IPPROTO_UDP ||
t->dst.protonum == IPPROTO_UDPLITE ||
t->dst.protonum == IPPROTO_DCCP ||
t->dst.protonum == IPPROTO_SCTP)
fl4->fl4_sport = t->src.u.tcp.port;
}
}
static unsigned int
nf_nat_fn(unsigned int hooknum,
struct sk_buff *skb,
const struct net_device *in,
const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
struct nf_conn *ct;
enum ip_conntrack_info ctinfo;
struct nf_conn_nat *nat;
enum nf_nat_manip_type maniptype = HOOK2MANIP(hooknum);
NF_CT_ASSERT(!ip_is_fragment(ip_hdr(skb)));
ct = nf_ct_get(skb, &ctinfo);
if (!ct)
return NF_ACCEPT;
if (nf_ct_is_untracked(ct))
return NF_ACCEPT;
nat = nfct_nat(ct);
if (!nat) {
if (nf_ct_is_confirmed(ct))
return NF_ACCEPT;
nat = nf_ct_ext_add(ct, NF_CT_EXT_NAT, GFP_ATOMIC);
if (nat == NULL) {
pr_debug("failed to add NAT extension\n");
return NF_ACCEPT;
}
}
switch (ctinfo) {
case IP_CT_RELATED:
case IP_CT_RELATED_REPLY:
if (ip_hdr(skb)->protocol == IPPROTO_ICMP) {
if (!nf_nat_icmp_reply_translation(ct, ctinfo,
hooknum, skb))
return NF_DROP;
else
return NF_ACCEPT;
}
case IP_CT_NEW:
if (!nf_nat_initialized(ct, maniptype)) {
unsigned int ret;
ret = nf_nat_rule_find(skb, hooknum, in, out, ct);
if (ret != NF_ACCEPT)
return ret;
} else
pr_debug("Already setup manip %s for ct %p\n",
maniptype == NF_NAT_MANIP_SRC ? "SRC" : "DST",
ct);
break;
default:
NF_CT_ASSERT(ctinfo == IP_CT_ESTABLISHED ||
ctinfo == IP_CT_ESTABLISHED_REPLY);
}
return nf_nat_packet(ct, ctinfo, hooknum, skb);
}
static unsigned int
nf_nat_in(unsigned int hooknum,
struct sk_buff *skb,
const struct net_device *in,
const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
unsigned int ret;
__be32 daddr = ip_hdr(skb)->daddr;
ret = nf_nat_fn(hooknum, skb, in, out, okfn);
if (ret != NF_DROP && ret != NF_STOLEN &&
daddr != ip_hdr(skb)->daddr)
skb_dst_drop(skb);
return ret;
}
static unsigned int
nf_nat_out(unsigned int hooknum,
struct sk_buff *skb,
const struct net_device *in,
const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
#ifdef CONFIG_XFRM
const struct nf_conn *ct;
enum ip_conntrack_info ctinfo;
#endif
unsigned int ret;
if (skb->len < sizeof(struct iphdr) ||
ip_hdrlen(skb) < sizeof(struct iphdr))
return NF_ACCEPT;
ret = nf_nat_fn(hooknum, skb, in, out, okfn);
#ifdef CONFIG_XFRM
if (ret != NF_DROP && ret != NF_STOLEN &&
(ct = nf_ct_get(skb, &ctinfo)) != NULL) {
enum ip_conntrack_dir dir = CTINFO2DIR(ctinfo);
if ((ct->tuplehash[dir].tuple.src.u3.ip !=
ct->tuplehash[!dir].tuple.dst.u3.ip) ||
(ct->tuplehash[dir].tuple.src.u.all !=
ct->tuplehash[!dir].tuple.dst.u.all)
)
return ip_xfrm_me_harder(skb) == 0 ? ret : NF_DROP;
}
#endif
return ret;
}
static unsigned int
nf_nat_local_fn(unsigned int hooknum,
struct sk_buff *skb,
const struct net_device *in,
const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
const struct nf_conn *ct;
enum ip_conntrack_info ctinfo;
unsigned int ret;
if (skb->len < sizeof(struct iphdr) ||
ip_hdrlen(skb) < sizeof(struct iphdr))
return NF_ACCEPT;
ret = nf_nat_fn(hooknum, skb, in, out, okfn);
if (ret != NF_DROP && ret != NF_STOLEN &&
(ct = nf_ct_get(skb, &ctinfo)) != NULL) {
enum ip_conntrack_dir dir = CTINFO2DIR(ctinfo);
if (ct->tuplehash[dir].tuple.dst.u3.ip !=
ct->tuplehash[!dir].tuple.src.u3.ip) {
if (ip_route_me_harder(skb, RTN_UNSPEC))
ret = NF_DROP;
}
#ifdef CONFIG_XFRM
else if (ct->tuplehash[dir].tuple.dst.u.all !=
ct->tuplehash[!dir].tuple.src.u.all)
if (ip_xfrm_me_harder(skb))
ret = NF_DROP;
#endif
}
return ret;
}
static int __init nf_nat_standalone_init(void)
{
int ret = 0;
need_ipv4_conntrack();
#ifdef CONFIG_XFRM
BUG_ON(ip_nat_decode_session != NULL);
RCU_INIT_POINTER(ip_nat_decode_session, nat_decode_session);
#endif
ret = nf_nat_rule_init();
if (ret < 0) {
pr_err("nf_nat_init: can't setup rules.\n");
goto cleanup_decode_session;
}
ret = nf_register_hooks(nf_nat_ops, ARRAY_SIZE(nf_nat_ops));
if (ret < 0) {
pr_err("nf_nat_init: can't register hooks.\n");
goto cleanup_rule_init;
}
return ret;
cleanup_rule_init:
nf_nat_rule_cleanup();
cleanup_decode_session:
#ifdef CONFIG_XFRM
RCU_INIT_POINTER(ip_nat_decode_session, NULL);
synchronize_net();
#endif
return ret;
}
static void __exit nf_nat_standalone_fini(void)
{
nf_unregister_hooks(nf_nat_ops, ARRAY_SIZE(nf_nat_ops));
nf_nat_rule_cleanup();
#ifdef CONFIG_XFRM
RCU_INIT_POINTER(ip_nat_decode_session, NULL);
synchronize_net();
#endif
}
