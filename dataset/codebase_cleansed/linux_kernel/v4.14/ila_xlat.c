static int alloc_ila_locks(struct ila_net *ilan)
{
unsigned int i, size;
unsigned int nr_pcpus = num_possible_cpus();
nr_pcpus = min_t(unsigned int, nr_pcpus, 32UL);
size = roundup_pow_of_two(nr_pcpus * LOCKS_PER_CPU);
if (sizeof(spinlock_t) != 0) {
ilan->locks = kvmalloc(size * sizeof(spinlock_t), GFP_KERNEL);
if (!ilan->locks)
return -ENOMEM;
for (i = 0; i < size; i++)
spin_lock_init(&ilan->locks[i]);
}
ilan->locks_mask = size - 1;
return 0;
}
static __always_inline void __ila_hash_secret_init(void)
{
net_get_random_once(&hashrnd, sizeof(hashrnd));
}
static inline u32 ila_locator_hash(struct ila_locator loc)
{
u32 *v = (u32 *)loc.v32;
__ila_hash_secret_init();
return jhash_2words(v[0], v[1], hashrnd);
}
static inline spinlock_t *ila_get_lock(struct ila_net *ilan,
struct ila_locator loc)
{
return &ilan->locks[ila_locator_hash(loc) & ilan->locks_mask];
}
static inline int ila_cmp_wildcards(struct ila_map *ila,
struct ila_addr *iaddr, int ifindex)
{
return (ila->xp.ifindex && ila->xp.ifindex != ifindex);
}
static inline int ila_cmp_params(struct ila_map *ila,
struct ila_xlat_params *xp)
{
return (ila->xp.ifindex != xp->ifindex);
}
static int ila_cmpfn(struct rhashtable_compare_arg *arg,
const void *obj)
{
const struct ila_map *ila = obj;
return (ila->xp.ip.locator_match.v64 != *(__be64 *)arg->key);
}
static inline int ila_order(struct ila_map *ila)
{
int score = 0;
if (ila->xp.ifindex)
score += 1 << 1;
return score;
}
static int parse_nl_config(struct genl_info *info,
struct ila_xlat_params *xp)
{
memset(xp, 0, sizeof(*xp));
if (info->attrs[ILA_ATTR_LOCATOR])
xp->ip.locator.v64 = (__force __be64)nla_get_u64(
info->attrs[ILA_ATTR_LOCATOR]);
if (info->attrs[ILA_ATTR_LOCATOR_MATCH])
xp->ip.locator_match.v64 = (__force __be64)nla_get_u64(
info->attrs[ILA_ATTR_LOCATOR_MATCH]);
if (info->attrs[ILA_ATTR_CSUM_MODE])
xp->ip.csum_mode = nla_get_u8(info->attrs[ILA_ATTR_CSUM_MODE]);
if (info->attrs[ILA_ATTR_IFINDEX])
xp->ifindex = nla_get_s32(info->attrs[ILA_ATTR_IFINDEX]);
return 0;
}
static inline struct ila_map *ila_lookup_wildcards(struct ila_addr *iaddr,
int ifindex,
struct ila_net *ilan)
{
struct ila_map *ila;
ila = rhashtable_lookup_fast(&ilan->rhash_table, &iaddr->loc,
rht_params);
while (ila) {
if (!ila_cmp_wildcards(ila, iaddr, ifindex))
return ila;
ila = rcu_access_pointer(ila->next);
}
return NULL;
}
static inline struct ila_map *ila_lookup_by_params(struct ila_xlat_params *xp,
struct ila_net *ilan)
{
struct ila_map *ila;
ila = rhashtable_lookup_fast(&ilan->rhash_table,
&xp->ip.locator_match,
rht_params);
while (ila) {
if (!ila_cmp_params(ila, xp))
return ila;
ila = rcu_access_pointer(ila->next);
}
return NULL;
}
static inline void ila_release(struct ila_map *ila)
{
kfree_rcu(ila, rcu);
}
static void ila_free_cb(void *ptr, void *arg)
{
struct ila_map *ila = (struct ila_map *)ptr, *next;
while (ila) {
next = rcu_access_pointer(ila->next);
ila_release(ila);
ila = next;
}
}
static unsigned int
ila_nf_input(void *priv,
struct sk_buff *skb,
const struct nf_hook_state *state)
{
ila_xlat_addr(skb, false);
return NF_ACCEPT;
}
static int ila_add_mapping(struct net *net, struct ila_xlat_params *xp)
{
struct ila_net *ilan = net_generic(net, ila_net_id);
struct ila_map *ila, *head;
spinlock_t *lock = ila_get_lock(ilan, xp->ip.locator_match);
int err = 0, order;
if (!ilan->hooks_registered) {
err = nf_register_net_hooks(net, ila_nf_hook_ops,
ARRAY_SIZE(ila_nf_hook_ops));
if (err)
return err;
ilan->hooks_registered = true;
}
ila = kzalloc(sizeof(*ila), GFP_KERNEL);
if (!ila)
return -ENOMEM;
ila_init_saved_csum(&xp->ip);
ila->xp = *xp;
order = ila_order(ila);
spin_lock(lock);
head = rhashtable_lookup_fast(&ilan->rhash_table,
&xp->ip.locator_match,
rht_params);
if (!head) {
err = rhashtable_lookup_insert_fast(&ilan->rhash_table,
&ila->node, rht_params);
} else {
struct ila_map *tila = head, *prev = NULL;
do {
if (!ila_cmp_params(tila, xp)) {
err = -EEXIST;
goto out;
}
if (order > ila_order(tila))
break;
prev = tila;
tila = rcu_dereference_protected(tila->next,
lockdep_is_held(lock));
} while (tila);
if (prev) {
RCU_INIT_POINTER(ila->next, tila);
rcu_assign_pointer(prev->next, ila);
} else {
RCU_INIT_POINTER(ila->next, head);
err = rhashtable_replace_fast(&ilan->rhash_table,
&head->node,
&ila->node, rht_params);
if (err)
goto out;
}
}
out:
spin_unlock(lock);
if (err)
kfree(ila);
return err;
}
static int ila_del_mapping(struct net *net, struct ila_xlat_params *xp)
{
struct ila_net *ilan = net_generic(net, ila_net_id);
struct ila_map *ila, *head, *prev;
spinlock_t *lock = ila_get_lock(ilan, xp->ip.locator_match);
int err = -ENOENT;
spin_lock(lock);
head = rhashtable_lookup_fast(&ilan->rhash_table,
&xp->ip.locator_match, rht_params);
ila = head;
prev = NULL;
while (ila) {
if (ila_cmp_params(ila, xp)) {
prev = ila;
ila = rcu_dereference_protected(ila->next,
lockdep_is_held(lock));
continue;
}
err = 0;
if (prev) {
rcu_assign_pointer(prev->next, ila->next);
} else {
head = rcu_dereference_protected(ila->next,
lockdep_is_held(lock));
if (head) {
err = rhashtable_replace_fast(
&ilan->rhash_table, &ila->node,
&head->node, rht_params);
if (err)
goto out;
} else {
err = rhashtable_remove_fast(&ilan->rhash_table,
&ila->node,
rht_params);
}
}
ila_release(ila);
break;
}
out:
spin_unlock(lock);
return err;
}
static int ila_nl_cmd_add_mapping(struct sk_buff *skb, struct genl_info *info)
{
struct net *net = genl_info_net(info);
struct ila_xlat_params p;
int err;
err = parse_nl_config(info, &p);
if (err)
return err;
return ila_add_mapping(net, &p);
}
static int ila_nl_cmd_del_mapping(struct sk_buff *skb, struct genl_info *info)
{
struct net *net = genl_info_net(info);
struct ila_xlat_params xp;
int err;
err = parse_nl_config(info, &xp);
if (err)
return err;
ila_del_mapping(net, &xp);
return 0;
}
static int ila_fill_info(struct ila_map *ila, struct sk_buff *msg)
{
if (nla_put_u64_64bit(msg, ILA_ATTR_LOCATOR,
(__force u64)ila->xp.ip.locator.v64,
ILA_ATTR_PAD) ||
nla_put_u64_64bit(msg, ILA_ATTR_LOCATOR_MATCH,
(__force u64)ila->xp.ip.locator_match.v64,
ILA_ATTR_PAD) ||
nla_put_s32(msg, ILA_ATTR_IFINDEX, ila->xp.ifindex) ||
nla_put_u32(msg, ILA_ATTR_CSUM_MODE, ila->xp.ip.csum_mode))
return -1;
return 0;
}
static int ila_dump_info(struct ila_map *ila,
u32 portid, u32 seq, u32 flags,
struct sk_buff *skb, u8 cmd)
{
void *hdr;
hdr = genlmsg_put(skb, portid, seq, &ila_nl_family, flags, cmd);
if (!hdr)
return -ENOMEM;
if (ila_fill_info(ila, skb) < 0)
goto nla_put_failure;
genlmsg_end(skb, hdr);
return 0;
nla_put_failure:
genlmsg_cancel(skb, hdr);
return -EMSGSIZE;
}
static int ila_nl_cmd_get_mapping(struct sk_buff *skb, struct genl_info *info)
{
struct net *net = genl_info_net(info);
struct ila_net *ilan = net_generic(net, ila_net_id);
struct sk_buff *msg;
struct ila_xlat_params xp;
struct ila_map *ila;
int ret;
ret = parse_nl_config(info, &xp);
if (ret)
return ret;
msg = nlmsg_new(NLMSG_DEFAULT_SIZE, GFP_KERNEL);
if (!msg)
return -ENOMEM;
rcu_read_lock();
ila = ila_lookup_by_params(&xp, ilan);
if (ila) {
ret = ila_dump_info(ila,
info->snd_portid,
info->snd_seq, 0, msg,
info->genlhdr->cmd);
}
rcu_read_unlock();
if (ret < 0)
goto out_free;
return genlmsg_reply(msg, info);
out_free:
nlmsg_free(msg);
return ret;
}
static int ila_nl_dump_start(struct netlink_callback *cb)
{
struct net *net = sock_net(cb->skb->sk);
struct ila_net *ilan = net_generic(net, ila_net_id);
struct ila_dump_iter *iter = (struct ila_dump_iter *)cb->args[0];
if (!iter) {
iter = kmalloc(sizeof(*iter), GFP_KERNEL);
if (!iter)
return -ENOMEM;
cb->args[0] = (long)iter;
}
return rhashtable_walk_init(&ilan->rhash_table, &iter->rhiter,
GFP_KERNEL);
}
static int ila_nl_dump_done(struct netlink_callback *cb)
{
struct ila_dump_iter *iter = (struct ila_dump_iter *)cb->args[0];
rhashtable_walk_exit(&iter->rhiter);
kfree(iter);
return 0;
}
static int ila_nl_dump(struct sk_buff *skb, struct netlink_callback *cb)
{
struct ila_dump_iter *iter = (struct ila_dump_iter *)cb->args[0];
struct rhashtable_iter *rhiter = &iter->rhiter;
struct ila_map *ila;
int ret;
ret = rhashtable_walk_start(rhiter);
if (ret && ret != -EAGAIN)
goto done;
for (;;) {
ila = rhashtable_walk_next(rhiter);
if (IS_ERR(ila)) {
if (PTR_ERR(ila) == -EAGAIN)
continue;
ret = PTR_ERR(ila);
goto done;
} else if (!ila) {
break;
}
while (ila) {
ret = ila_dump_info(ila, NETLINK_CB(cb->skb).portid,
cb->nlh->nlmsg_seq, NLM_F_MULTI,
skb, ILA_CMD_GET);
if (ret)
goto done;
ila = rcu_access_pointer(ila->next);
}
}
ret = skb->len;
done:
rhashtable_walk_stop(rhiter);
return ret;
}
static __net_init int ila_init_net(struct net *net)
{
int err;
struct ila_net *ilan = net_generic(net, ila_net_id);
err = alloc_ila_locks(ilan);
if (err)
return err;
rhashtable_init(&ilan->rhash_table, &rht_params);
return 0;
}
static __net_exit void ila_exit_net(struct net *net)
{
struct ila_net *ilan = net_generic(net, ila_net_id);
rhashtable_free_and_destroy(&ilan->rhash_table, ila_free_cb, NULL);
kvfree(ilan->locks);
if (ilan->hooks_registered)
nf_unregister_net_hooks(net, ila_nf_hook_ops,
ARRAY_SIZE(ila_nf_hook_ops));
}
static int ila_xlat_addr(struct sk_buff *skb, bool set_csum_neutral)
{
struct ila_map *ila;
struct ipv6hdr *ip6h = ipv6_hdr(skb);
struct net *net = dev_net(skb->dev);
struct ila_net *ilan = net_generic(net, ila_net_id);
struct ila_addr *iaddr = ila_a2i(&ip6h->daddr);
if (!ila_addr_is_ila(iaddr)) {
return 0;
}
rcu_read_lock();
ila = ila_lookup_wildcards(iaddr, skb->dev->ifindex, ilan);
if (ila)
ila_update_ipv6_locator(skb, &ila->xp.ip, set_csum_neutral);
rcu_read_unlock();
return 0;
}
int __init ila_xlat_init(void)
{
int ret;
ret = register_pernet_device(&ila_net_ops);
if (ret)
goto exit;
ret = genl_register_family(&ila_nl_family);
if (ret < 0)
goto unregister;
return 0;
unregister:
unregister_pernet_device(&ila_net_ops);
exit:
return ret;
}
void ila_xlat_fini(void)
{
genl_unregister_family(&ila_nl_family);
unregister_pernet_device(&ila_net_ops);
}
