int ovs_vport_init(void)
{
dev_table = kzalloc(VPORT_HASH_BUCKETS * sizeof(struct hlist_head),
GFP_KERNEL);
if (!dev_table)
return -ENOMEM;
return 0;
}
void ovs_vport_exit(void)
{
kfree(dev_table);
}
static struct hlist_head *hash_bucket(const struct net *net, const char *name)
{
unsigned int hash = jhash(name, strlen(name), (unsigned long) net);
return &dev_table[hash & (VPORT_HASH_BUCKETS - 1)];
}
int ovs_vport_ops_register(struct vport_ops *ops)
{
int err = -EEXIST;
struct vport_ops *o;
ovs_lock();
list_for_each_entry(o, &vport_ops_list, list)
if (ops->type == o->type)
goto errout;
list_add_tail(&ops->list, &vport_ops_list);
err = 0;
errout:
ovs_unlock();
return err;
}
void ovs_vport_ops_unregister(struct vport_ops *ops)
{
ovs_lock();
list_del(&ops->list);
ovs_unlock();
}
struct vport *ovs_vport_locate(const struct net *net, const char *name)
{
struct hlist_head *bucket = hash_bucket(net, name);
struct vport *vport;
hlist_for_each_entry_rcu(vport, bucket, hash_node)
if (!strcmp(name, vport->ops->get_name(vport)) &&
net_eq(ovs_dp_get_net(vport->dp), net))
return vport;
return NULL;
}
struct vport *ovs_vport_alloc(int priv_size, const struct vport_ops *ops,
const struct vport_parms *parms)
{
struct vport *vport;
size_t alloc_size;
alloc_size = sizeof(struct vport);
if (priv_size) {
alloc_size = ALIGN(alloc_size, VPORT_ALIGN);
alloc_size += priv_size;
}
vport = kzalloc(alloc_size, GFP_KERNEL);
if (!vport)
return ERR_PTR(-ENOMEM);
vport->dp = parms->dp;
vport->port_no = parms->port_no;
vport->ops = ops;
INIT_HLIST_NODE(&vport->dp_hash_node);
if (ovs_vport_set_upcall_portids(vport, parms->upcall_portids)) {
kfree(vport);
return ERR_PTR(-EINVAL);
}
vport->percpu_stats = netdev_alloc_pcpu_stats(struct pcpu_sw_netstats);
if (!vport->percpu_stats) {
kfree(vport);
return ERR_PTR(-ENOMEM);
}
return vport;
}
void ovs_vport_free(struct vport *vport)
{
kfree(rcu_dereference_raw(vport->upcall_portids));
free_percpu(vport->percpu_stats);
kfree(vport);
}
static struct vport_ops *ovs_vport_lookup(const struct vport_parms *parms)
{
struct vport_ops *ops;
list_for_each_entry(ops, &vport_ops_list, list)
if (ops->type == parms->type)
return ops;
return NULL;
}
struct vport *ovs_vport_add(const struct vport_parms *parms)
{
struct vport_ops *ops;
struct vport *vport;
ops = ovs_vport_lookup(parms);
if (ops) {
struct hlist_head *bucket;
if (!try_module_get(ops->owner))
return ERR_PTR(-EAFNOSUPPORT);
vport = ops->create(parms);
if (IS_ERR(vport)) {
module_put(ops->owner);
return vport;
}
bucket = hash_bucket(ovs_dp_get_net(vport->dp),
vport->ops->get_name(vport));
hlist_add_head_rcu(&vport->hash_node, bucket);
return vport;
}
ovs_unlock();
request_module("vport-type-%d", parms->type);
ovs_lock();
if (!ovs_vport_lookup(parms))
return ERR_PTR(-EAFNOSUPPORT);
else
return ERR_PTR(-EAGAIN);
}
int ovs_vport_set_options(struct vport *vport, struct nlattr *options)
{
if (!vport->ops->set_options)
return -EOPNOTSUPP;
return vport->ops->set_options(vport, options);
}
void ovs_vport_del(struct vport *vport)
{
ASSERT_OVSL();
hlist_del_rcu(&vport->hash_node);
module_put(vport->ops->owner);
vport->ops->destroy(vport);
}
void ovs_vport_get_stats(struct vport *vport, struct ovs_vport_stats *stats)
{
int i;
memset(stats, 0, sizeof(*stats));
stats->rx_errors = atomic_long_read(&vport->err_stats.rx_errors);
stats->tx_errors = atomic_long_read(&vport->err_stats.tx_errors);
stats->tx_dropped = atomic_long_read(&vport->err_stats.tx_dropped);
stats->rx_dropped = atomic_long_read(&vport->err_stats.rx_dropped);
for_each_possible_cpu(i) {
const struct pcpu_sw_netstats *percpu_stats;
struct pcpu_sw_netstats local_stats;
unsigned int start;
percpu_stats = per_cpu_ptr(vport->percpu_stats, i);
do {
start = u64_stats_fetch_begin_irq(&percpu_stats->syncp);
local_stats = *percpu_stats;
} while (u64_stats_fetch_retry_irq(&percpu_stats->syncp, start));
stats->rx_bytes += local_stats.rx_bytes;
stats->rx_packets += local_stats.rx_packets;
stats->tx_bytes += local_stats.tx_bytes;
stats->tx_packets += local_stats.tx_packets;
}
}
int ovs_vport_get_options(const struct vport *vport, struct sk_buff *skb)
{
struct nlattr *nla;
int err;
if (!vport->ops->get_options)
return 0;
nla = nla_nest_start(skb, OVS_VPORT_ATTR_OPTIONS);
if (!nla)
return -EMSGSIZE;
err = vport->ops->get_options(vport, skb);
if (err) {
nla_nest_cancel(skb, nla);
return err;
}
nla_nest_end(skb, nla);
return 0;
}
int ovs_vport_set_upcall_portids(struct vport *vport, const struct nlattr *ids)
{
struct vport_portids *old, *vport_portids;
if (!nla_len(ids) || nla_len(ids) % sizeof(u32))
return -EINVAL;
old = ovsl_dereference(vport->upcall_portids);
vport_portids = kmalloc(sizeof(*vport_portids) + nla_len(ids),
GFP_KERNEL);
if (!vport_portids)
return -ENOMEM;
vport_portids->n_ids = nla_len(ids) / sizeof(u32);
vport_portids->rn_ids = reciprocal_value(vport_portids->n_ids);
nla_memcpy(vport_portids->ids, ids, nla_len(ids));
rcu_assign_pointer(vport->upcall_portids, vport_portids);
if (old)
kfree_rcu(old, rcu);
return 0;
}
int ovs_vport_get_upcall_portids(const struct vport *vport,
struct sk_buff *skb)
{
struct vport_portids *ids;
ids = rcu_dereference_ovsl(vport->upcall_portids);
if (vport->dp->user_features & OVS_DP_F_VPORT_PIDS)
return nla_put(skb, OVS_VPORT_ATTR_UPCALL_PID,
ids->n_ids * sizeof(u32), (void *)ids->ids);
else
return nla_put_u32(skb, OVS_VPORT_ATTR_UPCALL_PID, ids->ids[0]);
}
u32 ovs_vport_find_upcall_portid(const struct vport *vport, struct sk_buff *skb)
{
struct vport_portids *ids;
u32 ids_index;
u32 hash;
ids = rcu_dereference(vport->upcall_portids);
if (ids->n_ids == 1 && ids->ids[0] == 0)
return 0;
hash = skb_get_hash(skb);
ids_index = hash - ids->n_ids * reciprocal_divide(hash, ids->rn_ids);
return ids->ids[ids_index];
}
void ovs_vport_receive(struct vport *vport, struct sk_buff *skb,
const struct ovs_tunnel_info *tun_info)
{
struct pcpu_sw_netstats *stats;
struct sw_flow_key key;
int error;
stats = this_cpu_ptr(vport->percpu_stats);
u64_stats_update_begin(&stats->syncp);
stats->rx_packets++;
stats->rx_bytes += skb->len +
(skb_vlan_tag_present(skb) ? VLAN_HLEN : 0);
u64_stats_update_end(&stats->syncp);
OVS_CB(skb)->input_vport = vport;
OVS_CB(skb)->egress_tun_info = NULL;
error = ovs_flow_key_extract(tun_info, skb, &key);
if (unlikely(error)) {
kfree_skb(skb);
return;
}
ovs_dp_process_packet(skb, &key);
}
int ovs_vport_send(struct vport *vport, struct sk_buff *skb)
{
int sent = vport->ops->send(vport, skb);
if (likely(sent > 0)) {
struct pcpu_sw_netstats *stats;
stats = this_cpu_ptr(vport->percpu_stats);
u64_stats_update_begin(&stats->syncp);
stats->tx_packets++;
stats->tx_bytes += sent;
u64_stats_update_end(&stats->syncp);
} else if (sent < 0) {
ovs_vport_record_error(vport, VPORT_E_TX_ERROR);
} else {
ovs_vport_record_error(vport, VPORT_E_TX_DROPPED);
}
return sent;
}
static void ovs_vport_record_error(struct vport *vport,
enum vport_err_type err_type)
{
switch (err_type) {
case VPORT_E_RX_DROPPED:
atomic_long_inc(&vport->err_stats.rx_dropped);
break;
case VPORT_E_RX_ERROR:
atomic_long_inc(&vport->err_stats.rx_errors);
break;
case VPORT_E_TX_DROPPED:
atomic_long_inc(&vport->err_stats.tx_dropped);
break;
case VPORT_E_TX_ERROR:
atomic_long_inc(&vport->err_stats.tx_errors);
break;
}
}
static void free_vport_rcu(struct rcu_head *rcu)
{
struct vport *vport = container_of(rcu, struct vport, rcu);
ovs_vport_free(vport);
}
void ovs_vport_deferred_free(struct vport *vport)
{
if (!vport)
return;
call_rcu(&vport->rcu, free_vport_rcu);
}
int ovs_tunnel_get_egress_info(struct ovs_tunnel_info *egress_tun_info,
struct net *net,
const struct ovs_tunnel_info *tun_info,
u8 ipproto,
u32 skb_mark,
__be16 tp_src,
__be16 tp_dst)
{
const struct ovs_key_ipv4_tunnel *tun_key;
struct rtable *rt;
struct flowi4 fl;
if (unlikely(!tun_info))
return -EINVAL;
tun_key = &tun_info->tunnel;
rt = ovs_tunnel_route_lookup(net, tun_key, skb_mark, &fl, ipproto);
if (IS_ERR(rt))
return PTR_ERR(rt);
ip_rt_put(rt);
__ovs_flow_tun_info_init(egress_tun_info,
fl.saddr, tun_key->ipv4_dst,
tun_key->ipv4_tos,
tun_key->ipv4_ttl,
tp_src, tp_dst,
tun_key->tun_id,
tun_key->tun_flags,
tun_info->options,
tun_info->options_len);
return 0;
}
int ovs_vport_get_egress_tun_info(struct vport *vport, struct sk_buff *skb,
struct ovs_tunnel_info *info)
{
if (unlikely(!vport->ops->get_egress_tun_info))
return -EINVAL;
return vport->ops->get_egress_tun_info(vport, skb, info);
}
