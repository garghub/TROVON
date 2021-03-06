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
static struct hlist_head *hash_bucket(struct net *net, const char *name)
{
unsigned int hash = jhash(name, strlen(name), (unsigned long) net);
return &dev_table[hash & (VPORT_HASH_BUCKETS - 1)];
}
struct vport *ovs_vport_locate(struct net *net, const char *name)
{
struct hlist_head *bucket = hash_bucket(net, name);
struct vport *vport;
struct hlist_node *node;
hlist_for_each_entry_rcu(vport, node, bucket, hash_node)
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
vport->upcall_portid = parms->upcall_portid;
vport->ops = ops;
INIT_HLIST_NODE(&vport->dp_hash_node);
vport->percpu_stats = alloc_percpu(struct vport_percpu_stats);
if (!vport->percpu_stats) {
kfree(vport);
return ERR_PTR(-ENOMEM);
}
spin_lock_init(&vport->stats_lock);
return vport;
}
void ovs_vport_free(struct vport *vport)
{
free_percpu(vport->percpu_stats);
kfree(vport);
}
struct vport *ovs_vport_add(const struct vport_parms *parms)
{
struct vport *vport;
int err = 0;
int i;
ASSERT_RTNL();
for (i = 0; i < ARRAY_SIZE(vport_ops_list); i++) {
if (vport_ops_list[i]->type == parms->type) {
struct hlist_head *bucket;
vport = vport_ops_list[i]->create(parms);
if (IS_ERR(vport)) {
err = PTR_ERR(vport);
goto out;
}
bucket = hash_bucket(ovs_dp_get_net(vport->dp),
vport->ops->get_name(vport));
hlist_add_head_rcu(&vport->hash_node, bucket);
return vport;
}
}
err = -EAFNOSUPPORT;
out:
return ERR_PTR(err);
}
int ovs_vport_set_options(struct vport *vport, struct nlattr *options)
{
ASSERT_RTNL();
if (!vport->ops->set_options)
return -EOPNOTSUPP;
return vport->ops->set_options(vport, options);
}
void ovs_vport_del(struct vport *vport)
{
ASSERT_RTNL();
hlist_del_rcu(&vport->hash_node);
vport->ops->destroy(vport);
}
void ovs_vport_get_stats(struct vport *vport, struct ovs_vport_stats *stats)
{
int i;
memset(stats, 0, sizeof(*stats));
spin_lock_bh(&vport->stats_lock);
stats->rx_errors = vport->err_stats.rx_errors;
stats->tx_errors = vport->err_stats.tx_errors;
stats->tx_dropped = vport->err_stats.tx_dropped;
stats->rx_dropped = vport->err_stats.rx_dropped;
spin_unlock_bh(&vport->stats_lock);
for_each_possible_cpu(i) {
const struct vport_percpu_stats *percpu_stats;
struct vport_percpu_stats local_stats;
unsigned int start;
percpu_stats = per_cpu_ptr(vport->percpu_stats, i);
do {
start = u64_stats_fetch_begin_bh(&percpu_stats->sync);
local_stats = *percpu_stats;
} while (u64_stats_fetch_retry_bh(&percpu_stats->sync, start));
stats->rx_bytes += local_stats.rx_bytes;
stats->rx_packets += local_stats.rx_packets;
stats->tx_bytes += local_stats.tx_bytes;
stats->tx_packets += local_stats.tx_packets;
}
}
int ovs_vport_get_options(const struct vport *vport, struct sk_buff *skb)
{
struct nlattr *nla;
nla = nla_nest_start(skb, OVS_VPORT_ATTR_OPTIONS);
if (!nla)
return -EMSGSIZE;
if (vport->ops->get_options) {
int err = vport->ops->get_options(vport, skb);
if (err) {
nla_nest_cancel(skb, nla);
return err;
}
}
nla_nest_end(skb, nla);
return 0;
}
void ovs_vport_receive(struct vport *vport, struct sk_buff *skb)
{
struct vport_percpu_stats *stats;
stats = this_cpu_ptr(vport->percpu_stats);
u64_stats_update_begin(&stats->sync);
stats->rx_packets++;
stats->rx_bytes += skb->len;
u64_stats_update_end(&stats->sync);
ovs_dp_process_received_packet(vport, skb);
}
int ovs_vport_send(struct vport *vport, struct sk_buff *skb)
{
int sent = vport->ops->send(vport, skb);
if (likely(sent)) {
struct vport_percpu_stats *stats;
stats = this_cpu_ptr(vport->percpu_stats);
u64_stats_update_begin(&stats->sync);
stats->tx_packets++;
stats->tx_bytes += sent;
u64_stats_update_end(&stats->sync);
}
return sent;
}
void ovs_vport_record_error(struct vport *vport, enum vport_err_type err_type)
{
spin_lock(&vport->stats_lock);
switch (err_type) {
case VPORT_E_RX_DROPPED:
vport->err_stats.rx_dropped++;
break;
case VPORT_E_RX_ERROR:
vport->err_stats.rx_errors++;
break;
case VPORT_E_TX_DROPPED:
vport->err_stats.tx_dropped++;
break;
case VPORT_E_TX_ERROR:
vport->err_stats.tx_errors++;
break;
}
spin_unlock(&vport->stats_lock);
}
