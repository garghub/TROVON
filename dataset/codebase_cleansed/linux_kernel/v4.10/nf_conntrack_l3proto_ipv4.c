static bool ipv4_pkt_to_tuple(const struct sk_buff *skb, unsigned int nhoff,
struct nf_conntrack_tuple *tuple)
{
const __be32 *ap;
__be32 _addrs[2];
ap = skb_header_pointer(skb, nhoff + offsetof(struct iphdr, saddr),
sizeof(u_int32_t) * 2, _addrs);
if (ap == NULL)
return false;
tuple->src.u3.ip = ap[0];
tuple->dst.u3.ip = ap[1];
return true;
}
static bool ipv4_invert_tuple(struct nf_conntrack_tuple *tuple,
const struct nf_conntrack_tuple *orig)
{
tuple->src.u3.ip = orig->dst.u3.ip;
tuple->dst.u3.ip = orig->src.u3.ip;
return true;
}
static void ipv4_print_tuple(struct seq_file *s,
const struct nf_conntrack_tuple *tuple)
{
seq_printf(s, "src=%pI4 dst=%pI4 ",
&tuple->src.u3.ip, &tuple->dst.u3.ip);
}
static int ipv4_get_l4proto(const struct sk_buff *skb, unsigned int nhoff,
unsigned int *dataoff, u_int8_t *protonum)
{
const struct iphdr *iph;
struct iphdr _iph;
iph = skb_header_pointer(skb, nhoff, sizeof(_iph), &_iph);
if (iph == NULL)
return -NF_ACCEPT;
if (iph->frag_off & htons(IP_OFFSET))
return -NF_ACCEPT;
*dataoff = nhoff + (iph->ihl << 2);
*protonum = iph->protocol;
if (*dataoff > skb->len) {
pr_debug("nf_conntrack_ipv4: bogus IPv4 packet: "
"nhoff %u, ihl %u, skblen %u\n",
nhoff, iph->ihl << 2, skb->len);
return -NF_ACCEPT;
}
return NF_ACCEPT;
}
static unsigned int ipv4_helper(void *priv,
struct sk_buff *skb,
const struct nf_hook_state *state)
{
struct nf_conn *ct;
enum ip_conntrack_info ctinfo;
const struct nf_conn_help *help;
const struct nf_conntrack_helper *helper;
ct = nf_ct_get(skb, &ctinfo);
if (!ct || ctinfo == IP_CT_RELATED_REPLY)
return NF_ACCEPT;
help = nfct_help(ct);
if (!help)
return NF_ACCEPT;
helper = rcu_dereference(help->helper);
if (!helper)
return NF_ACCEPT;
return helper->help(skb, skb_network_offset(skb) + ip_hdrlen(skb),
ct, ctinfo);
}
static unsigned int ipv4_confirm(void *priv,
struct sk_buff *skb,
const struct nf_hook_state *state)
{
struct nf_conn *ct;
enum ip_conntrack_info ctinfo;
ct = nf_ct_get(skb, &ctinfo);
if (!ct || ctinfo == IP_CT_RELATED_REPLY)
goto out;
if (test_bit(IPS_SEQ_ADJUST_BIT, &ct->status) &&
!nf_is_loopback_packet(skb)) {
if (!nf_ct_seq_adjust(skb, ct, ctinfo, ip_hdrlen(skb))) {
NF_CT_STAT_INC_ATOMIC(nf_ct_net(ct), drop);
return NF_DROP;
}
}
out:
return nf_conntrack_confirm(skb);
}
static unsigned int ipv4_conntrack_in(void *priv,
struct sk_buff *skb,
const struct nf_hook_state *state)
{
return nf_conntrack_in(state->net, PF_INET, state->hook, skb);
}
static unsigned int ipv4_conntrack_local(void *priv,
struct sk_buff *skb,
const struct nf_hook_state *state)
{
if (skb->len < sizeof(struct iphdr) ||
ip_hdrlen(skb) < sizeof(struct iphdr))
return NF_ACCEPT;
return nf_conntrack_in(state->net, PF_INET, state->hook, skb);
}
static int
getorigdst(struct sock *sk, int optval, void __user *user, int *len)
{
const struct inet_sock *inet = inet_sk(sk);
const struct nf_conntrack_tuple_hash *h;
struct nf_conntrack_tuple tuple;
memset(&tuple, 0, sizeof(tuple));
tuple.src.u3.ip = inet->inet_rcv_saddr;
tuple.src.u.tcp.port = inet->inet_sport;
tuple.dst.u3.ip = inet->inet_daddr;
tuple.dst.u.tcp.port = inet->inet_dport;
tuple.src.l3num = PF_INET;
tuple.dst.protonum = sk->sk_protocol;
if (sk->sk_protocol != IPPROTO_TCP && sk->sk_protocol != IPPROTO_SCTP) {
pr_debug("SO_ORIGINAL_DST: Not a TCP/SCTP socket\n");
return -ENOPROTOOPT;
}
if ((unsigned int) *len < sizeof(struct sockaddr_in)) {
pr_debug("SO_ORIGINAL_DST: len %d not %Zu\n",
*len, sizeof(struct sockaddr_in));
return -EINVAL;
}
h = nf_conntrack_find_get(sock_net(sk), &nf_ct_zone_dflt, &tuple);
if (h) {
struct sockaddr_in sin;
struct nf_conn *ct = nf_ct_tuplehash_to_ctrack(h);
sin.sin_family = AF_INET;
sin.sin_port = ct->tuplehash[IP_CT_DIR_ORIGINAL]
.tuple.dst.u.tcp.port;
sin.sin_addr.s_addr = ct->tuplehash[IP_CT_DIR_ORIGINAL]
.tuple.dst.u3.ip;
memset(sin.sin_zero, 0, sizeof(sin.sin_zero));
pr_debug("SO_ORIGINAL_DST: %pI4 %u\n",
&sin.sin_addr.s_addr, ntohs(sin.sin_port));
nf_ct_put(ct);
if (copy_to_user(user, &sin, sizeof(sin)) != 0)
return -EFAULT;
else
return 0;
}
pr_debug("SO_ORIGINAL_DST: Can't find %pI4/%u-%pI4/%u.\n",
&tuple.src.u3.ip, ntohs(tuple.src.u.tcp.port),
&tuple.dst.u3.ip, ntohs(tuple.dst.u.tcp.port));
return -ENOENT;
}
static int ipv4_tuple_to_nlattr(struct sk_buff *skb,
const struct nf_conntrack_tuple *tuple)
{
if (nla_put_in_addr(skb, CTA_IP_V4_SRC, tuple->src.u3.ip) ||
nla_put_in_addr(skb, CTA_IP_V4_DST, tuple->dst.u3.ip))
goto nla_put_failure;
return 0;
nla_put_failure:
return -1;
}
static int ipv4_nlattr_to_tuple(struct nlattr *tb[],
struct nf_conntrack_tuple *t)
{
if (!tb[CTA_IP_V4_SRC] || !tb[CTA_IP_V4_DST])
return -EINVAL;
t->src.u3.ip = nla_get_in_addr(tb[CTA_IP_V4_SRC]);
t->dst.u3.ip = nla_get_in_addr(tb[CTA_IP_V4_DST]);
return 0;
}
static int ipv4_nlattr_tuple_size(void)
{
return nla_policy_len(ipv4_nla_policy, CTA_IP_MAX + 1);
}
static int ipv4_hooks_register(struct net *net)
{
struct conntrack4_net *cnet = net_generic(net, conntrack4_net_id);
int err = 0;
mutex_lock(&register_ipv4_hooks);
cnet->users++;
if (cnet->users > 1)
goto out_unlock;
err = nf_defrag_ipv4_enable(net);
if (err) {
cnet->users = 0;
goto out_unlock;
}
err = nf_register_net_hooks(net, ipv4_conntrack_ops,
ARRAY_SIZE(ipv4_conntrack_ops));
if (err)
cnet->users = 0;
out_unlock:
mutex_unlock(&register_ipv4_hooks);
return err;
}
static void ipv4_hooks_unregister(struct net *net)
{
struct conntrack4_net *cnet = net_generic(net, conntrack4_net_id);
mutex_lock(&register_ipv4_hooks);
if (cnet->users && (--cnet->users == 0))
nf_unregister_net_hooks(net, ipv4_conntrack_ops,
ARRAY_SIZE(ipv4_conntrack_ops));
mutex_unlock(&register_ipv4_hooks);
}
static int ipv4_net_init(struct net *net)
{
int ret = 0;
ret = nf_ct_l4proto_pernet_register(net, builtin_l4proto4,
ARRAY_SIZE(builtin_l4proto4));
if (ret < 0)
return ret;
ret = nf_ct_l3proto_pernet_register(net, &nf_conntrack_l3proto_ipv4);
if (ret < 0) {
pr_err("nf_conntrack_ipv4: pernet registration failed\n");
nf_ct_l4proto_pernet_unregister(net, builtin_l4proto4,
ARRAY_SIZE(builtin_l4proto4));
}
return ret;
}
static void ipv4_net_exit(struct net *net)
{
nf_ct_l3proto_pernet_unregister(net, &nf_conntrack_l3proto_ipv4);
nf_ct_l4proto_pernet_unregister(net, builtin_l4proto4,
ARRAY_SIZE(builtin_l4proto4));
}
static int __init nf_conntrack_l3proto_ipv4_init(void)
{
int ret = 0;
need_conntrack();
ret = nf_register_sockopt(&so_getorigdst);
if (ret < 0) {
pr_err("Unable to register netfilter socket option\n");
return ret;
}
ret = register_pernet_subsys(&ipv4_net_ops);
if (ret < 0) {
pr_err("nf_conntrack_ipv4: can't register pernet ops\n");
goto cleanup_sockopt;
}
ret = nf_ct_l4proto_register(builtin_l4proto4,
ARRAY_SIZE(builtin_l4proto4));
if (ret < 0)
goto cleanup_pernet;
ret = nf_ct_l3proto_register(&nf_conntrack_l3proto_ipv4);
if (ret < 0) {
pr_err("nf_conntrack_ipv4: can't register ipv4 proto.\n");
goto cleanup_l4proto;
}
return ret;
cleanup_l4proto:
nf_ct_l4proto_unregister(builtin_l4proto4,
ARRAY_SIZE(builtin_l4proto4));
cleanup_pernet:
unregister_pernet_subsys(&ipv4_net_ops);
cleanup_sockopt:
nf_unregister_sockopt(&so_getorigdst);
return ret;
}
static void __exit nf_conntrack_l3proto_ipv4_fini(void)
{
synchronize_net();
nf_ct_l3proto_unregister(&nf_conntrack_l3proto_ipv4);
nf_ct_l4proto_unregister(builtin_l4proto4,
ARRAY_SIZE(builtin_l4proto4));
unregister_pernet_subsys(&ipv4_net_ops);
nf_unregister_sockopt(&so_getorigdst);
}
