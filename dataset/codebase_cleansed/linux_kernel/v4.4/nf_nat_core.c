inline const struct nf_nat_l3proto *
__nf_nat_l3proto_find(u8 family)
{
return rcu_dereference(nf_nat_l3protos[family]);
}
inline const struct nf_nat_l4proto *
__nf_nat_l4proto_find(u8 family, u8 protonum)
{
return rcu_dereference(nf_nat_l4protos[family][protonum]);
}
static void __nf_nat_decode_session(struct sk_buff *skb, struct flowi *fl)
{
const struct nf_nat_l3proto *l3proto;
const struct nf_conn *ct;
enum ip_conntrack_info ctinfo;
enum ip_conntrack_dir dir;
unsigned long statusbit;
u8 family;
ct = nf_ct_get(skb, &ctinfo);
if (ct == NULL)
return;
family = ct->tuplehash[IP_CT_DIR_ORIGINAL].tuple.src.l3num;
rcu_read_lock();
l3proto = __nf_nat_l3proto_find(family);
if (l3proto == NULL)
goto out;
dir = CTINFO2DIR(ctinfo);
if (dir == IP_CT_DIR_ORIGINAL)
statusbit = IPS_DST_NAT;
else
statusbit = IPS_SRC_NAT;
l3proto->decode_session(skb, ct, dir, statusbit, fl);
out:
rcu_read_unlock();
}
int nf_xfrm_me_harder(struct net *net, struct sk_buff *skb, unsigned int family)
{
struct flowi fl;
unsigned int hh_len;
struct dst_entry *dst;
int err;
err = xfrm_decode_session(skb, &fl, family);
if (err < 0)
return err;
dst = skb_dst(skb);
if (dst->xfrm)
dst = ((struct xfrm_dst *)dst)->route;
dst_hold(dst);
dst = xfrm_lookup(net, dst, &fl, skb->sk, 0);
if (IS_ERR(dst))
return PTR_ERR(dst);
skb_dst_drop(skb);
skb_dst_set(skb, dst);
hh_len = skb_dst(skb)->dev->hard_header_len;
if (skb_headroom(skb) < hh_len &&
pskb_expand_head(skb, hh_len - skb_headroom(skb), 0, GFP_ATOMIC))
return -ENOMEM;
return 0;
}
static inline unsigned int
hash_by_src(const struct net *net, const struct nf_conntrack_tuple *tuple)
{
unsigned int hash;
hash = jhash2((u32 *)&tuple->src, sizeof(tuple->src) / sizeof(u32),
tuple->dst.protonum ^ nf_conntrack_hash_rnd);
return reciprocal_scale(hash, net->ct.nat_htable_size);
}
int
nf_nat_used_tuple(const struct nf_conntrack_tuple *tuple,
const struct nf_conn *ignored_conntrack)
{
struct nf_conntrack_tuple reply;
nf_ct_invert_tuplepr(&reply, tuple);
return nf_conntrack_tuple_taken(&reply, ignored_conntrack);
}
static int in_range(const struct nf_nat_l3proto *l3proto,
const struct nf_nat_l4proto *l4proto,
const struct nf_conntrack_tuple *tuple,
const struct nf_nat_range *range)
{
if (range->flags & NF_NAT_RANGE_MAP_IPS &&
!l3proto->in_range(tuple, range))
return 0;
if (!(range->flags & NF_NAT_RANGE_PROTO_SPECIFIED) ||
l4proto->in_range(tuple, NF_NAT_MANIP_SRC,
&range->min_proto, &range->max_proto))
return 1;
return 0;
}
static inline int
same_src(const struct nf_conn *ct,
const struct nf_conntrack_tuple *tuple)
{
const struct nf_conntrack_tuple *t;
t = &ct->tuplehash[IP_CT_DIR_ORIGINAL].tuple;
return (t->dst.protonum == tuple->dst.protonum &&
nf_inet_addr_cmp(&t->src.u3, &tuple->src.u3) &&
t->src.u.all == tuple->src.u.all);
}
static int
find_appropriate_src(struct net *net,
const struct nf_conntrack_zone *zone,
const struct nf_nat_l3proto *l3proto,
const struct nf_nat_l4proto *l4proto,
const struct nf_conntrack_tuple *tuple,
struct nf_conntrack_tuple *result,
const struct nf_nat_range *range)
{
unsigned int h = hash_by_src(net, tuple);
const struct nf_conn_nat *nat;
const struct nf_conn *ct;
hlist_for_each_entry_rcu(nat, &net->ct.nat_bysource[h], bysource) {
ct = nat->ct;
if (same_src(ct, tuple) &&
nf_ct_zone_equal(ct, zone, IP_CT_DIR_ORIGINAL)) {
nf_ct_invert_tuplepr(result,
&ct->tuplehash[IP_CT_DIR_REPLY].tuple);
result->dst = tuple->dst;
if (in_range(l3proto, l4proto, result, range))
return 1;
}
}
return 0;
}
static void
find_best_ips_proto(const struct nf_conntrack_zone *zone,
struct nf_conntrack_tuple *tuple,
const struct nf_nat_range *range,
const struct nf_conn *ct,
enum nf_nat_manip_type maniptype)
{
union nf_inet_addr *var_ipp;
unsigned int i, max;
u32 minip, maxip, j, dist;
bool full_range;
if (!(range->flags & NF_NAT_RANGE_MAP_IPS))
return;
if (maniptype == NF_NAT_MANIP_SRC)
var_ipp = &tuple->src.u3;
else
var_ipp = &tuple->dst.u3;
if (nf_inet_addr_cmp(&range->min_addr, &range->max_addr)) {
*var_ipp = range->min_addr;
return;
}
if (nf_ct_l3num(ct) == NFPROTO_IPV4)
max = sizeof(var_ipp->ip) / sizeof(u32) - 1;
else
max = sizeof(var_ipp->ip6) / sizeof(u32) - 1;
j = jhash2((u32 *)&tuple->src.u3, sizeof(tuple->src.u3) / sizeof(u32),
range->flags & NF_NAT_RANGE_PERSISTENT ?
0 : (__force u32)tuple->dst.u3.all[max] ^ zone->id);
full_range = false;
for (i = 0; i <= max; i++) {
if (!full_range) {
minip = ntohl((__force __be32)range->min_addr.all[i]);
maxip = ntohl((__force __be32)range->max_addr.all[i]);
dist = maxip - minip + 1;
} else {
minip = 0;
dist = ~0;
}
var_ipp->all[i] = (__force __u32)
htonl(minip + reciprocal_scale(j, dist));
if (var_ipp->all[i] != range->max_addr.all[i])
full_range = true;
if (!(range->flags & NF_NAT_RANGE_PERSISTENT))
j ^= (__force u32)tuple->dst.u3.all[i];
}
}
static void
get_unique_tuple(struct nf_conntrack_tuple *tuple,
const struct nf_conntrack_tuple *orig_tuple,
const struct nf_nat_range *range,
struct nf_conn *ct,
enum nf_nat_manip_type maniptype)
{
const struct nf_conntrack_zone *zone;
const struct nf_nat_l3proto *l3proto;
const struct nf_nat_l4proto *l4proto;
struct net *net = nf_ct_net(ct);
zone = nf_ct_zone(ct);
rcu_read_lock();
l3proto = __nf_nat_l3proto_find(orig_tuple->src.l3num);
l4proto = __nf_nat_l4proto_find(orig_tuple->src.l3num,
orig_tuple->dst.protonum);
if (maniptype == NF_NAT_MANIP_SRC &&
!(range->flags & NF_NAT_RANGE_PROTO_RANDOM_ALL)) {
if (in_range(l3proto, l4proto, orig_tuple, range)) {
if (!nf_nat_used_tuple(orig_tuple, ct)) {
*tuple = *orig_tuple;
goto out;
}
} else if (find_appropriate_src(net, zone, l3proto, l4proto,
orig_tuple, tuple, range)) {
pr_debug("get_unique_tuple: Found current src map\n");
if (!nf_nat_used_tuple(tuple, ct))
goto out;
}
}
*tuple = *orig_tuple;
find_best_ips_proto(zone, tuple, range, ct, maniptype);
if (!(range->flags & NF_NAT_RANGE_PROTO_RANDOM_ALL)) {
if (range->flags & NF_NAT_RANGE_PROTO_SPECIFIED) {
if (l4proto->in_range(tuple, maniptype,
&range->min_proto,
&range->max_proto) &&
(range->min_proto.all == range->max_proto.all ||
!nf_nat_used_tuple(tuple, ct)))
goto out;
} else if (!nf_nat_used_tuple(tuple, ct)) {
goto out;
}
}
l4proto->unique_tuple(l3proto, tuple, range, maniptype, ct);
out:
rcu_read_unlock();
}
struct nf_conn_nat *nf_ct_nat_ext_add(struct nf_conn *ct)
{
struct nf_conn_nat *nat = nfct_nat(ct);
if (nat)
return nat;
if (!nf_ct_is_confirmed(ct))
nat = nf_ct_ext_add(ct, NF_CT_EXT_NAT, GFP_ATOMIC);
return nat;
}
unsigned int
nf_nat_setup_info(struct nf_conn *ct,
const struct nf_nat_range *range,
enum nf_nat_manip_type maniptype)
{
struct net *net = nf_ct_net(ct);
struct nf_conntrack_tuple curr_tuple, new_tuple;
struct nf_conn_nat *nat;
nat = nf_ct_nat_ext_add(ct);
if (nat == NULL)
return NF_ACCEPT;
NF_CT_ASSERT(maniptype == NF_NAT_MANIP_SRC ||
maniptype == NF_NAT_MANIP_DST);
BUG_ON(nf_nat_initialized(ct, maniptype));
nf_ct_invert_tuplepr(&curr_tuple,
&ct->tuplehash[IP_CT_DIR_REPLY].tuple);
get_unique_tuple(&new_tuple, &curr_tuple, range, ct, maniptype);
if (!nf_ct_tuple_equal(&new_tuple, &curr_tuple)) {
struct nf_conntrack_tuple reply;
nf_ct_invert_tuplepr(&reply, &new_tuple);
nf_conntrack_alter_reply(ct, &reply);
if (maniptype == NF_NAT_MANIP_SRC)
ct->status |= IPS_SRC_NAT;
else
ct->status |= IPS_DST_NAT;
if (nfct_help(ct))
nfct_seqadj_ext_add(ct);
}
if (maniptype == NF_NAT_MANIP_SRC) {
unsigned int srchash;
srchash = hash_by_src(net,
&ct->tuplehash[IP_CT_DIR_ORIGINAL].tuple);
spin_lock_bh(&nf_nat_lock);
nat = nfct_nat(ct);
nat->ct = ct;
hlist_add_head_rcu(&nat->bysource,
&net->ct.nat_bysource[srchash]);
spin_unlock_bh(&nf_nat_lock);
}
if (maniptype == NF_NAT_MANIP_DST)
ct->status |= IPS_DST_NAT_DONE;
else
ct->status |= IPS_SRC_NAT_DONE;
return NF_ACCEPT;
}
static unsigned int
__nf_nat_alloc_null_binding(struct nf_conn *ct, enum nf_nat_manip_type manip)
{
union nf_inet_addr ip =
(manip == NF_NAT_MANIP_SRC ?
ct->tuplehash[IP_CT_DIR_REPLY].tuple.dst.u3 :
ct->tuplehash[IP_CT_DIR_REPLY].tuple.src.u3);
struct nf_nat_range range = {
.flags = NF_NAT_RANGE_MAP_IPS,
.min_addr = ip,
.max_addr = ip,
};
return nf_nat_setup_info(ct, &range, manip);
}
unsigned int
nf_nat_alloc_null_binding(struct nf_conn *ct, unsigned int hooknum)
{
return __nf_nat_alloc_null_binding(ct, HOOK2MANIP(hooknum));
}
unsigned int nf_nat_packet(struct nf_conn *ct,
enum ip_conntrack_info ctinfo,
unsigned int hooknum,
struct sk_buff *skb)
{
const struct nf_nat_l3proto *l3proto;
const struct nf_nat_l4proto *l4proto;
enum ip_conntrack_dir dir = CTINFO2DIR(ctinfo);
unsigned long statusbit;
enum nf_nat_manip_type mtype = HOOK2MANIP(hooknum);
if (mtype == NF_NAT_MANIP_SRC)
statusbit = IPS_SRC_NAT;
else
statusbit = IPS_DST_NAT;
if (dir == IP_CT_DIR_REPLY)
statusbit ^= IPS_NAT_MASK;
if (ct->status & statusbit) {
struct nf_conntrack_tuple target;
nf_ct_invert_tuplepr(&target, &ct->tuplehash[!dir].tuple);
l3proto = __nf_nat_l3proto_find(target.src.l3num);
l4proto = __nf_nat_l4proto_find(target.src.l3num,
target.dst.protonum);
if (!l3proto->manip_pkt(skb, 0, l4proto, &target, mtype))
return NF_DROP;
}
return NF_ACCEPT;
}
static int nf_nat_proto_remove(struct nf_conn *i, void *data)
{
const struct nf_nat_proto_clean *clean = data;
struct nf_conn_nat *nat = nfct_nat(i);
if (!nat)
return 0;
if ((clean->l3proto && nf_ct_l3num(i) != clean->l3proto) ||
(clean->l4proto && nf_ct_protonum(i) != clean->l4proto))
return 0;
return i->status & IPS_NAT_MASK ? 1 : 0;
}
static int nf_nat_proto_clean(struct nf_conn *ct, void *data)
{
struct nf_conn_nat *nat = nfct_nat(ct);
if (nf_nat_proto_remove(ct, data))
return 1;
if (!nat || !nat->ct)
return 0;
if (!del_timer(&ct->timeout))
return 1;
spin_lock_bh(&nf_nat_lock);
hlist_del_rcu(&nat->bysource);
ct->status &= ~IPS_NAT_DONE_MASK;
nat->ct = NULL;
spin_unlock_bh(&nf_nat_lock);
add_timer(&ct->timeout);
return 0;
}
static void nf_nat_l4proto_clean(u8 l3proto, u8 l4proto)
{
struct nf_nat_proto_clean clean = {
.l3proto = l3proto,
.l4proto = l4proto,
};
struct net *net;
rtnl_lock();
for_each_net(net)
nf_ct_iterate_cleanup(net, nf_nat_proto_remove, &clean, 0, 0);
rtnl_unlock();
}
static void nf_nat_l3proto_clean(u8 l3proto)
{
struct nf_nat_proto_clean clean = {
.l3proto = l3proto,
};
struct net *net;
rtnl_lock();
for_each_net(net)
nf_ct_iterate_cleanup(net, nf_nat_proto_remove, &clean, 0, 0);
rtnl_unlock();
}
int nf_nat_l4proto_register(u8 l3proto, const struct nf_nat_l4proto *l4proto)
{
const struct nf_nat_l4proto **l4protos;
unsigned int i;
int ret = 0;
mutex_lock(&nf_nat_proto_mutex);
if (nf_nat_l4protos[l3proto] == NULL) {
l4protos = kmalloc(IPPROTO_MAX * sizeof(struct nf_nat_l4proto *),
GFP_KERNEL);
if (l4protos == NULL) {
ret = -ENOMEM;
goto out;
}
for (i = 0; i < IPPROTO_MAX; i++)
RCU_INIT_POINTER(l4protos[i], &nf_nat_l4proto_unknown);
smp_wmb();
nf_nat_l4protos[l3proto] = l4protos;
}
if (rcu_dereference_protected(
nf_nat_l4protos[l3proto][l4proto->l4proto],
lockdep_is_held(&nf_nat_proto_mutex)
) != &nf_nat_l4proto_unknown) {
ret = -EBUSY;
goto out;
}
RCU_INIT_POINTER(nf_nat_l4protos[l3proto][l4proto->l4proto], l4proto);
out:
mutex_unlock(&nf_nat_proto_mutex);
return ret;
}
void nf_nat_l4proto_unregister(u8 l3proto, const struct nf_nat_l4proto *l4proto)
{
mutex_lock(&nf_nat_proto_mutex);
RCU_INIT_POINTER(nf_nat_l4protos[l3proto][l4proto->l4proto],
&nf_nat_l4proto_unknown);
mutex_unlock(&nf_nat_proto_mutex);
synchronize_rcu();
nf_nat_l4proto_clean(l3proto, l4proto->l4proto);
}
int nf_nat_l3proto_register(const struct nf_nat_l3proto *l3proto)
{
int err;
err = nf_ct_l3proto_try_module_get(l3proto->l3proto);
if (err < 0)
return err;
mutex_lock(&nf_nat_proto_mutex);
RCU_INIT_POINTER(nf_nat_l4protos[l3proto->l3proto][IPPROTO_TCP],
&nf_nat_l4proto_tcp);
RCU_INIT_POINTER(nf_nat_l4protos[l3proto->l3proto][IPPROTO_UDP],
&nf_nat_l4proto_udp);
mutex_unlock(&nf_nat_proto_mutex);
RCU_INIT_POINTER(nf_nat_l3protos[l3proto->l3proto], l3proto);
return 0;
}
void nf_nat_l3proto_unregister(const struct nf_nat_l3proto *l3proto)
{
mutex_lock(&nf_nat_proto_mutex);
RCU_INIT_POINTER(nf_nat_l3protos[l3proto->l3proto], NULL);
mutex_unlock(&nf_nat_proto_mutex);
synchronize_rcu();
nf_nat_l3proto_clean(l3proto->l3proto);
nf_ct_l3proto_module_put(l3proto->l3proto);
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
static int nfnetlink_parse_nat_proto(struct nlattr *attr,
const struct nf_conn *ct,
struct nf_nat_range *range)
{
struct nlattr *tb[CTA_PROTONAT_MAX+1];
const struct nf_nat_l4proto *l4proto;
int err;
err = nla_parse_nested(tb, CTA_PROTONAT_MAX, attr, protonat_nla_policy);
if (err < 0)
return err;
l4proto = __nf_nat_l4proto_find(nf_ct_l3num(ct), nf_ct_protonum(ct));
if (l4proto->nlattr_to_range)
err = l4proto->nlattr_to_range(tb, range);
return err;
}
static int
nfnetlink_parse_nat(const struct nlattr *nat,
const struct nf_conn *ct, struct nf_nat_range *range,
const struct nf_nat_l3proto *l3proto)
{
struct nlattr *tb[CTA_NAT_MAX+1];
int err;
memset(range, 0, sizeof(*range));
err = nla_parse_nested(tb, CTA_NAT_MAX, nat, nat_nla_policy);
if (err < 0)
return err;
err = l3proto->nlattr_to_range(tb, range);
if (err < 0)
return err;
if (!tb[CTA_NAT_PROTO])
return 0;
return nfnetlink_parse_nat_proto(tb[CTA_NAT_PROTO], ct, range);
}
static int
nfnetlink_parse_nat_setup(struct nf_conn *ct,
enum nf_nat_manip_type manip,
const struct nlattr *attr)
{
struct nf_nat_range range;
const struct nf_nat_l3proto *l3proto;
int err;
if (WARN_ON_ONCE(nf_nat_initialized(ct, manip)))
return -EEXIST;
l3proto = __nf_nat_l3proto_find(nf_ct_l3num(ct));
if (l3proto == NULL)
return -EAGAIN;
if (attr == NULL)
return __nf_nat_alloc_null_binding(ct, manip);
err = nfnetlink_parse_nat(attr, ct, &range, l3proto);
if (err < 0)
return err;
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
net->ct.nat_htable_size = net->ct.htable_size;
net->ct.nat_bysource = nf_ct_alloc_hashtable(&net->ct.nat_htable_size, 0);
if (!net->ct.nat_bysource)
return -ENOMEM;
return 0;
}
static void __net_exit nf_nat_net_exit(struct net *net)
{
struct nf_nat_proto_clean clean = {};
nf_ct_iterate_cleanup(net, nf_nat_proto_clean, &clean, 0, 0);
synchronize_rcu();
nf_ct_free_hashtable(net->ct.nat_bysource, net->ct.nat_htable_size);
}
static int __init nf_nat_init(void)
{
int ret;
ret = nf_ct_extend_register(&nat_extend);
if (ret < 0) {
printk(KERN_ERR "nf_nat_core: Unable to register extension\n");
return ret;
}
ret = register_pernet_subsys(&nf_nat_net_ops);
if (ret < 0)
goto cleanup_extend;
nf_ct_helper_expectfn_register(&follow_master_nat);
nf_ct_untracked_status_or(IPS_NAT_DONE_MASK);
BUG_ON(nfnetlink_parse_nat_setup_hook != NULL);
RCU_INIT_POINTER(nfnetlink_parse_nat_setup_hook,
nfnetlink_parse_nat_setup);
#ifdef CONFIG_XFRM
BUG_ON(nf_nat_decode_session_hook != NULL);
RCU_INIT_POINTER(nf_nat_decode_session_hook, __nf_nat_decode_session);
#endif
return 0;
cleanup_extend:
nf_ct_extend_unregister(&nat_extend);
return ret;
}
static void __exit nf_nat_cleanup(void)
{
unsigned int i;
unregister_pernet_subsys(&nf_nat_net_ops);
nf_ct_extend_unregister(&nat_extend);
nf_ct_helper_expectfn_unregister(&follow_master_nat);
RCU_INIT_POINTER(nfnetlink_parse_nat_setup_hook, NULL);
#ifdef CONFIG_XFRM
RCU_INIT_POINTER(nf_nat_decode_session_hook, NULL);
#endif
for (i = 0; i < NFPROTO_NUMPROTO; i++)
kfree(nf_nat_l4protos[i]);
synchronize_net();
}
