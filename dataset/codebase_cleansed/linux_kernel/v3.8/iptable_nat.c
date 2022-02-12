static unsigned int alloc_null_binding(struct nf_conn *ct, unsigned int hooknum)
{
struct nf_nat_range range;
range.flags = 0;
pr_debug("Allocating NULL binding for %p (%pI4)\n", ct,
HOOK2MANIP(hooknum) == NF_NAT_MANIP_SRC ?
&ct->tuplehash[IP_CT_DIR_REPLY].tuple.dst.u3.ip :
&ct->tuplehash[IP_CT_DIR_REPLY].tuple.src.u3.ip);
return nf_nat_setup_info(ct, &range, HOOK2MANIP(hooknum));
}
static unsigned int nf_nat_rule_find(struct sk_buff *skb, unsigned int hooknum,
const struct net_device *in,
const struct net_device *out,
struct nf_conn *ct)
{
struct net *net = nf_ct_net(ct);
unsigned int ret;
ret = ipt_do_table(skb, hooknum, in, out, net->ipv4.nat_table);
if (ret == NF_ACCEPT) {
if (!nf_nat_initialized(ct, HOOK2MANIP(hooknum)))
ret = alloc_null_binding(ct, hooknum);
}
return ret;
}
static unsigned int
nf_nat_ipv4_fn(unsigned int hooknum,
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
if (!nf_nat_icmp_reply_translation(skb, ct, ctinfo,
hooknum))
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
} else {
pr_debug("Already setup manip %s for ct %p\n",
maniptype == NF_NAT_MANIP_SRC ? "SRC" : "DST",
ct);
if (nf_nat_oif_changed(hooknum, ctinfo, nat, out))
goto oif_changed;
}
break;
default:
NF_CT_ASSERT(ctinfo == IP_CT_ESTABLISHED ||
ctinfo == IP_CT_ESTABLISHED_REPLY);
if (nf_nat_oif_changed(hooknum, ctinfo, nat, out))
goto oif_changed;
}
return nf_nat_packet(ct, ctinfo, hooknum, skb);
oif_changed:
nf_ct_kill_acct(ct, ctinfo, skb);
return NF_DROP;
}
static unsigned int
nf_nat_ipv4_in(unsigned int hooknum,
struct sk_buff *skb,
const struct net_device *in,
const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
unsigned int ret;
__be32 daddr = ip_hdr(skb)->daddr;
ret = nf_nat_ipv4_fn(hooknum, skb, in, out, okfn);
if (ret != NF_DROP && ret != NF_STOLEN &&
daddr != ip_hdr(skb)->daddr)
skb_dst_drop(skb);
return ret;
}
static unsigned int
nf_nat_ipv4_out(unsigned int hooknum,
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
ret = nf_nat_ipv4_fn(hooknum, skb, in, out, okfn);
#ifdef CONFIG_XFRM
if (ret != NF_DROP && ret != NF_STOLEN &&
!(IPCB(skb)->flags & IPSKB_XFRM_TRANSFORMED) &&
(ct = nf_ct_get(skb, &ctinfo)) != NULL) {
enum ip_conntrack_dir dir = CTINFO2DIR(ctinfo);
if ((ct->tuplehash[dir].tuple.src.u3.ip !=
ct->tuplehash[!dir].tuple.dst.u3.ip) ||
(ct->tuplehash[dir].tuple.dst.protonum != IPPROTO_ICMP &&
ct->tuplehash[dir].tuple.src.u.all !=
ct->tuplehash[!dir].tuple.dst.u.all))
if (nf_xfrm_me_harder(skb, AF_INET) < 0)
ret = NF_DROP;
}
#endif
return ret;
}
static unsigned int
nf_nat_ipv4_local_fn(unsigned int hooknum,
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
ret = nf_nat_ipv4_fn(hooknum, skb, in, out, okfn);
if (ret != NF_DROP && ret != NF_STOLEN &&
(ct = nf_ct_get(skb, &ctinfo)) != NULL) {
enum ip_conntrack_dir dir = CTINFO2DIR(ctinfo);
if (ct->tuplehash[dir].tuple.dst.u3.ip !=
ct->tuplehash[!dir].tuple.src.u3.ip) {
if (ip_route_me_harder(skb, RTN_UNSPEC))
ret = NF_DROP;
}
#ifdef CONFIG_XFRM
else if (!(IPCB(skb)->flags & IPSKB_XFRM_TRANSFORMED) &&
ct->tuplehash[dir].tuple.dst.protonum != IPPROTO_ICMP &&
ct->tuplehash[dir].tuple.dst.u.all !=
ct->tuplehash[!dir].tuple.src.u.all)
if (nf_xfrm_me_harder(skb, AF_INET) < 0)
ret = NF_DROP;
#endif
}
return ret;
}
static int __net_init iptable_nat_net_init(struct net *net)
{
struct ipt_replace *repl;
repl = ipt_alloc_initial_table(&nf_nat_ipv4_table);
if (repl == NULL)
return -ENOMEM;
net->ipv4.nat_table = ipt_register_table(net, &nf_nat_ipv4_table, repl);
kfree(repl);
return PTR_RET(net->ipv4.nat_table);
}
static void __net_exit iptable_nat_net_exit(struct net *net)
{
ipt_unregister_table(net, net->ipv4.nat_table);
}
static int __init iptable_nat_init(void)
{
int err;
err = register_pernet_subsys(&iptable_nat_net_ops);
if (err < 0)
goto err1;
err = nf_register_hooks(nf_nat_ipv4_ops, ARRAY_SIZE(nf_nat_ipv4_ops));
if (err < 0)
goto err2;
return 0;
err2:
unregister_pernet_subsys(&iptable_nat_net_ops);
err1:
return err;
}
static void __exit iptable_nat_exit(void)
{
nf_unregister_hooks(nf_nat_ipv4_ops, ARRAY_SIZE(nf_nat_ipv4_ops));
unregister_pernet_subsys(&iptable_nat_net_ops);
}
