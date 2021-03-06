static inline const struct nf_nat_protocol *
__nf_nat_proto_find(u_int8_t protonum)
{
return rcu_dereference(nf_nat_protos[protonum]);
}
static inline unsigned int
hash_by_src(const struct net *net, u16 zone,
const struct nf_conntrack_tuple *tuple)
{
unsigned int hash;
hash = jhash_3words((__force u32)tuple->src.u3.ip,
(__force u32)tuple->src.u.all ^ zone,
tuple->dst.protonum, 0);
return ((u64)hash * net->ipv4.nat_htable_size) >> 32;
}
int
nf_nat_used_tuple(const struct nf_conntrack_tuple *tuple,
const struct nf_conn *ignored_conntrack)
{
struct nf_conntrack_tuple reply;
nf_ct_invert_tuplepr(&reply, tuple);
return nf_conntrack_tuple_taken(&reply, ignored_conntrack);
}
static int
in_range(const struct nf_conntrack_tuple *tuple,
const struct nf_nat_range *range)
{
const struct nf_nat_protocol *proto;
int ret = 0;
if (range->flags & IP_NAT_RANGE_MAP_IPS) {
if (ntohl(tuple->src.u3.ip) < ntohl(range->min_ip) ||
ntohl(tuple->src.u3.ip) > ntohl(range->max_ip))
return 0;
}
rcu_read_lock();
proto = __nf_nat_proto_find(tuple->dst.protonum);
if (!(range->flags & IP_NAT_RANGE_PROTO_SPECIFIED) ||
proto->in_range(tuple, IP_NAT_MANIP_SRC,
&range->min, &range->max))
ret = 1;
rcu_read_unlock();
return ret;
}
static inline int
same_src(const struct nf_conn *ct,
const struct nf_conntrack_tuple *tuple)
{
const struct nf_conntrack_tuple *t;
t = &ct->tuplehash[IP_CT_DIR_ORIGINAL].tuple;
return (t->dst.protonum == tuple->dst.protonum &&
t->src.u3.ip == tuple->src.u3.ip &&
t->src.u.all == tuple->src.u.all);
}
static int
find_appropriate_src(struct net *net, u16 zone,
const struct nf_conntrack_tuple *tuple,
struct nf_conntrack_tuple *result,
const struct nf_nat_range *range)
{
unsigned int h = hash_by_src(net, zone, tuple);
const struct nf_conn_nat *nat;
const struct nf_conn *ct;
const struct hlist_node *n;
rcu_read_lock();
hlist_for_each_entry_rcu(nat, n, &net->ipv4.nat_bysource[h], bysource) {
ct = nat->ct;
if (same_src(ct, tuple) && nf_ct_zone(ct) == zone) {
nf_ct_invert_tuplepr(result,
&ct->tuplehash[IP_CT_DIR_REPLY].tuple);
result->dst = tuple->dst;
if (in_range(result, range)) {
rcu_read_unlock();
return 1;
}
}
}
rcu_read_unlock();
return 0;
}
static void
find_best_ips_proto(u16 zone, struct nf_conntrack_tuple *tuple,
const struct nf_nat_range *range,
const struct nf_conn *ct,
enum nf_nat_manip_type maniptype)
{
__be32 *var_ipp;
u_int32_t minip, maxip, j;
if (!(range->flags & IP_NAT_RANGE_MAP_IPS))
return;
if (maniptype == IP_NAT_MANIP_SRC)
var_ipp = &tuple->src.u3.ip;
else
var_ipp = &tuple->dst.u3.ip;
if (range->min_ip == range->max_ip) {
*var_ipp = range->min_ip;
return;
}
minip = ntohl(range->min_ip);
maxip = ntohl(range->max_ip);
j = jhash_2words((__force u32)tuple->src.u3.ip,
range->flags & IP_NAT_RANGE_PERSISTENT ?
0 : (__force u32)tuple->dst.u3.ip ^ zone, 0);
j = ((u64)j * (maxip - minip + 1)) >> 32;
*var_ipp = htonl(minip + j);
}
static void
get_unique_tuple(struct nf_conntrack_tuple *tuple,
const struct nf_conntrack_tuple *orig_tuple,
const struct nf_nat_range *range,
struct nf_conn *ct,
enum nf_nat_manip_type maniptype)
{
struct net *net = nf_ct_net(ct);
const struct nf_nat_protocol *proto;
u16 zone = nf_ct_zone(ct);
if (maniptype == IP_NAT_MANIP_SRC &&
!(range->flags & IP_NAT_RANGE_PROTO_RANDOM)) {
if (in_range(orig_tuple, range)) {
if (!nf_nat_used_tuple(orig_tuple, ct)) {
*tuple = *orig_tuple;
return;
}
} else if (find_appropriate_src(net, zone, orig_tuple, tuple,
range)) {
pr_debug("get_unique_tuple: Found current src map\n");
if (!nf_nat_used_tuple(tuple, ct))
return;
}
}
*tuple = *orig_tuple;
find_best_ips_proto(zone, tuple, range, ct, maniptype);
rcu_read_lock();
proto = __nf_nat_proto_find(orig_tuple->dst.protonum);
if (!(range->flags & IP_NAT_RANGE_PROTO_RANDOM)) {
if (range->flags & IP_NAT_RANGE_PROTO_SPECIFIED) {
if (proto->in_range(tuple, maniptype, &range->min,
&range->max) &&
(range->min.all == range->max.all ||
!nf_nat_used_tuple(tuple, ct)))
goto out;
} else if (!nf_nat_used_tuple(tuple, ct)) {
goto out;
}
}
proto->unique_tuple(tuple, range, maniptype, ct);
out:
rcu_read_unlock();
}
unsigned int
nf_nat_setup_info(struct nf_conn *ct,
const struct nf_nat_range *range,
enum nf_nat_manip_type maniptype)
{
struct net *net = nf_ct_net(ct);
struct nf_conntrack_tuple curr_tuple, new_tuple;
struct nf_conn_nat *nat;
nat = nfct_nat(ct);
if (!nat) {
nat = nf_ct_ext_add(ct, NF_CT_EXT_NAT, GFP_ATOMIC);
if (nat == NULL) {
pr_debug("failed to add NAT extension\n");
return NF_ACCEPT;
}
}
NF_CT_ASSERT(maniptype == IP_NAT_MANIP_SRC ||
maniptype == IP_NAT_MANIP_DST);
BUG_ON(nf_nat_initialized(ct, maniptype));
nf_ct_invert_tuplepr(&curr_tuple,
&ct->tuplehash[IP_CT_DIR_REPLY].tuple);
get_unique_tuple(&new_tuple, &curr_tuple, range, ct, maniptype);
if (!nf_ct_tuple_equal(&new_tuple, &curr_tuple)) {
struct nf_conntrack_tuple reply;
nf_ct_invert_tuplepr(&reply, &new_tuple);
nf_conntrack_alter_reply(ct, &reply);
if (maniptype == IP_NAT_MANIP_SRC)
ct->status |= IPS_SRC_NAT;
else
ct->status |= IPS_DST_NAT;
}
if (maniptype == IP_NAT_MANIP_SRC) {
unsigned int srchash;
srchash = hash_by_src(net, nf_ct_zone(ct),
&ct->tuplehash[IP_CT_DIR_ORIGINAL].tuple);
spin_lock_bh(&nf_nat_lock);
nat = nfct_nat(ct);
nat->ct = ct;
hlist_add_head_rcu(&nat->bysource,
&net->ipv4.nat_bysource[srchash]);
spin_unlock_bh(&nf_nat_lock);
}
if (maniptype == IP_NAT_MANIP_DST)
ct->status |= IPS_DST_NAT_DONE;
else
ct->status |= IPS_SRC_NAT_DONE;
return NF_ACCEPT;
}
static bool
manip_pkt(u_int16_t proto,
struct sk_buff *skb,
unsigned int iphdroff,
const struct nf_conntrack_tuple *target,
enum nf_nat_manip_type maniptype)
{
struct iphdr *iph;
const struct nf_nat_protocol *p;
if (!skb_make_writable(skb, iphdroff + sizeof(*iph)))
return false;
iph = (void *)skb->data + iphdroff;
p = __nf_nat_proto_find(proto);
if (!p->manip_pkt(skb, iphdroff, target, maniptype))
return false;
iph = (void *)skb->data + iphdroff;
if (maniptype == IP_NAT_MANIP_SRC) {
csum_replace4(&iph->check, iph->saddr, target->src.u3.ip);
iph->saddr = target->src.u3.ip;
} else {
csum_replace4(&iph->check, iph->daddr, target->dst.u3.ip);
iph->daddr = target->dst.u3.ip;
}
return true;
}
unsigned int nf_nat_packet(struct nf_conn *ct,
enum ip_conntrack_info ctinfo,
unsigned int hooknum,
struct sk_buff *skb)
{
enum ip_conntrack_dir dir = CTINFO2DIR(ctinfo);
unsigned long statusbit;
enum nf_nat_manip_type mtype = HOOK2MANIP(hooknum);
if (mtype == IP_NAT_MANIP_SRC)
statusbit = IPS_SRC_NAT;
else
statusbit = IPS_DST_NAT;
if (dir == IP_CT_DIR_REPLY)
statusbit ^= IPS_NAT_MASK;
if (ct->status & statusbit) {
struct nf_conntrack_tuple target;
nf_ct_invert_tuplepr(&target, &ct->tuplehash[!dir].tuple);
if (!manip_pkt(target.dst.protonum, skb, 0, &target, mtype))
return NF_DROP;
}
return NF_ACCEPT;
}
int nf_nat_icmp_reply_translation(struct nf_conn *ct,
enum ip_conntrack_info ctinfo,
unsigned int hooknum,
struct sk_buff *skb)
{
struct {
struct icmphdr icmp;
struct iphdr ip;
} *inside;
const struct nf_conntrack_l4proto *l4proto;
struct nf_conntrack_tuple inner, target;
int hdrlen = ip_hdrlen(skb);
enum ip_conntrack_dir dir = CTINFO2DIR(ctinfo);
unsigned long statusbit;
enum nf_nat_manip_type manip = HOOK2MANIP(hooknum);
if (!skb_make_writable(skb, hdrlen + sizeof(*inside)))
return 0;
inside = (void *)skb->data + hdrlen;
if (nf_ip_checksum(skb, hooknum, hdrlen, 0))
return 0;
NF_CT_ASSERT(skb->nfctinfo == IP_CT_RELATED ||
skb->nfctinfo == IP_CT_RELATED_REPLY);
if (inside->icmp.type == ICMP_REDIRECT) {
if ((ct->status & IPS_NAT_DONE_MASK) != IPS_NAT_DONE_MASK)
return 0;
if (ct->status & IPS_NAT_MASK)
return 0;
}
if (manip == IP_NAT_MANIP_SRC)
statusbit = IPS_SRC_NAT;
else
statusbit = IPS_DST_NAT;
if (dir == IP_CT_DIR_REPLY)
statusbit ^= IPS_NAT_MASK;
if (!(ct->status & statusbit))
return 1;
pr_debug("icmp_reply_translation: translating error %p manip %u "
"dir %s\n", skb, manip,
dir == IP_CT_DIR_ORIGINAL ? "ORIG" : "REPLY");
l4proto = __nf_ct_l4proto_find(PF_INET, inside->ip.protocol);
if (!nf_ct_get_tuple(skb, hdrlen + sizeof(struct icmphdr),
(hdrlen +
sizeof(struct icmphdr) + inside->ip.ihl * 4),
(u_int16_t)AF_INET, inside->ip.protocol,
&inner, l3proto, l4proto))
return 0;
if (!manip_pkt(inside->ip.protocol, skb, hdrlen + sizeof(inside->icmp),
&ct->tuplehash[!dir].tuple, !manip))
return 0;
if (skb->ip_summed != CHECKSUM_PARTIAL) {
inside = (void *)skb->data + hdrlen;
inside->icmp.checksum = 0;
inside->icmp.checksum =
csum_fold(skb_checksum(skb, hdrlen,
skb->len - hdrlen, 0));
}
nf_ct_invert_tuplepr(&target, &ct->tuplehash[!dir].tuple);
if (!manip_pkt(0, skb, 0, &target, manip))
return 0;
return 1;
}
int nf_nat_protocol_register(const struct nf_nat_protocol *proto)
{
int ret = 0;
spin_lock_bh(&nf_nat_lock);
if (rcu_dereference_protected(
nf_nat_protos[proto->protonum],
lockdep_is_held(&nf_nat_lock)
) != &nf_nat_unknown_protocol) {
ret = -EBUSY;
goto out;
}
rcu_assign_pointer(nf_nat_protos[proto->protonum], proto);
out:
spin_unlock_bh(&nf_nat_lock);
return ret;
}
void nf_nat_protocol_unregister(const struct nf_nat_protocol *proto)
{
spin_lock_bh(&nf_nat_lock);
rcu_assign_pointer(nf_nat_protos[proto->protonum],
&nf_nat_unknown_protocol);
spin_unlock_bh(&nf_nat_lock);
synchronize_rcu();
}
static void nf_nat_cleanup_conntrack(struct nf_conn *ct)
{
struct nf_conn_nat *nat = nf_ct_ext_find(ct, NF_CT_EXT_NAT);
if (nat == NULL || nat->ct == NULL)
return;
NF_CT_ASSERT(nat->ct->status & IPS_SRC_NAT_DONE);
spin_lock_bh(&nf_nat_lock);
hlist_del_rcu(&nat->bysource);
spin_unlock_bh(&nf_nat_lock);
}
static void nf_nat_move_storage(void *new, void *old)
{
struct nf_conn_nat *new_nat = new;
struct nf_conn_nat *old_nat = old;
struct nf_conn *ct = old_nat->ct;
if (!ct || !(ct->status & IPS_SRC_NAT_DONE))
return;
spin_lock_bh(&nf_nat_lock);
hlist_replace_rcu(&old_nat->bysource, &new_nat->bysource);
spin_unlock_bh(&nf_nat_lock);
}
static const struct nf_nat_protocol *
nf_nat_proto_find_get(u_int8_t protonum)
{
const struct nf_nat_protocol *p;
rcu_read_lock();
p = __nf_nat_proto_find(protonum);
if (!try_module_get(p->me))
p = &nf_nat_unknown_protocol;
rcu_read_unlock();
return p;
}
static void
nf_nat_proto_put(const struct nf_nat_protocol *p)
{
module_put(p->me);
}
static int nfnetlink_parse_nat_proto(struct nlattr *attr,
const struct nf_conn *ct,
struct nf_nat_range *range)
{
struct nlattr *tb[CTA_PROTONAT_MAX+1];
const struct nf_nat_protocol *npt;
int err;
err = nla_parse_nested(tb, CTA_PROTONAT_MAX, attr, protonat_nla_policy);
if (err < 0)
return err;
npt = nf_nat_proto_find_get(nf_ct_protonum(ct));
if (npt->nlattr_to_range)
err = npt->nlattr_to_range(tb, range);
nf_nat_proto_put(npt);
return err;
}
static int
nfnetlink_parse_nat(const struct nlattr *nat,
const struct nf_conn *ct, struct nf_nat_range *range)
{
struct nlattr *tb[CTA_NAT_MAX+1];
int err;
memset(range, 0, sizeof(*range));
err = nla_parse_nested(tb, CTA_NAT_MAX, nat, nat_nla_policy);
if (err < 0)
return err;
if (tb[CTA_NAT_MINIP])
range->min_ip = nla_get_be32(tb[CTA_NAT_MINIP]);
if (!tb[CTA_NAT_MAXIP])
range->max_ip = range->min_ip;
else
range->max_ip = nla_get_be32(tb[CTA_NAT_MAXIP]);
if (range->min_ip)
range->flags |= IP_NAT_RANGE_MAP_IPS;
if (!tb[CTA_NAT_PROTO])
return 0;
err = nfnetlink_parse_nat_proto(tb[CTA_NAT_PROTO], ct, range);
if (err < 0)
return err;
return 0;
}
static int
nfnetlink_parse_nat_setup(struct nf_conn *ct,
enum nf_nat_manip_type manip,
const struct nlattr *attr)
{
struct nf_nat_range range;
if (nfnetlink_parse_nat(attr, ct, &range) < 0)
return -EINVAL;
if (nf_nat_initialized(ct, manip))
return -EEXIST;
return nf_nat_setup_info(ct, &range, manip);
}
static int
nfnetlink_parse_nat_setup(struct nf_conn *ct,
enum nf_nat_manip_type manip,
const struct nlattr *attr)
{
return -EOPNOTSUPP;
}
static int __net_init nf_nat_net_init(struct net *net)
{
net->ipv4.nat_htable_size = net->ct.htable_size;
net->ipv4.nat_bysource = nf_ct_alloc_hashtable(&net->ipv4.nat_htable_size, 0);
if (!net->ipv4.nat_bysource)
return -ENOMEM;
return 0;
}
static int clean_nat(struct nf_conn *i, void *data)
{
struct nf_conn_nat *nat = nfct_nat(i);
if (!nat)
return 0;
memset(nat, 0, sizeof(*nat));
i->status &= ~(IPS_NAT_MASK | IPS_NAT_DONE_MASK | IPS_SEQ_ADJUST);
return 0;
}
static void __net_exit nf_nat_net_exit(struct net *net)
{
nf_ct_iterate_cleanup(net, &clean_nat, NULL);
synchronize_rcu();
nf_ct_free_hashtable(net->ipv4.nat_bysource, net->ipv4.nat_htable_size);
}
static int __init nf_nat_init(void)
{
size_t i;
int ret;
need_ipv4_conntrack();
ret = nf_ct_extend_register(&nat_extend);
if (ret < 0) {
printk(KERN_ERR "nf_nat_core: Unable to register extension\n");
return ret;
}
ret = register_pernet_subsys(&nf_nat_net_ops);
if (ret < 0)
goto cleanup_extend;
spin_lock_bh(&nf_nat_lock);
for (i = 0; i < MAX_IP_NAT_PROTO; i++)
rcu_assign_pointer(nf_nat_protos[i], &nf_nat_unknown_protocol);
rcu_assign_pointer(nf_nat_protos[IPPROTO_TCP], &nf_nat_protocol_tcp);
rcu_assign_pointer(nf_nat_protos[IPPROTO_UDP], &nf_nat_protocol_udp);
rcu_assign_pointer(nf_nat_protos[IPPROTO_ICMP], &nf_nat_protocol_icmp);
spin_unlock_bh(&nf_nat_lock);
nf_ct_untracked_status_or(IPS_NAT_DONE_MASK);
l3proto = nf_ct_l3proto_find_get((u_int16_t)AF_INET);
BUG_ON(nf_nat_seq_adjust_hook != NULL);
rcu_assign_pointer(nf_nat_seq_adjust_hook, nf_nat_seq_adjust);
BUG_ON(nfnetlink_parse_nat_setup_hook != NULL);
rcu_assign_pointer(nfnetlink_parse_nat_setup_hook,
nfnetlink_parse_nat_setup);
BUG_ON(nf_ct_nat_offset != NULL);
rcu_assign_pointer(nf_ct_nat_offset, nf_nat_get_offset);
return 0;
cleanup_extend:
nf_ct_extend_unregister(&nat_extend);
return ret;
}
static void __exit nf_nat_cleanup(void)
{
unregister_pernet_subsys(&nf_nat_net_ops);
nf_ct_l3proto_put(l3proto);
nf_ct_extend_unregister(&nat_extend);
rcu_assign_pointer(nf_nat_seq_adjust_hook, NULL);
rcu_assign_pointer(nfnetlink_parse_nat_setup_hook, NULL);
rcu_assign_pointer(nf_ct_nat_offset, NULL);
synchronize_net();
}
