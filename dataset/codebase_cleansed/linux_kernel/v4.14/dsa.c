static struct sk_buff *dsa_slave_notag_xmit(struct sk_buff *skb,
struct net_device *dev)
{
return skb;
}
int dsa_cpu_dsa_setup(struct dsa_port *port)
{
struct device_node *port_dn = port->dn;
struct dsa_switch *ds = port->ds;
struct phy_device *phydev;
int ret, mode;
if (of_phy_is_fixed_link(port_dn)) {
ret = of_phy_register_fixed_link(port_dn);
if (ret) {
dev_err(ds->dev, "failed to register fixed PHY\n");
return ret;
}
phydev = of_phy_find_device(port_dn);
mode = of_get_phy_mode(port_dn);
if (mode < 0)
mode = PHY_INTERFACE_MODE_NA;
phydev->interface = mode;
genphy_config_init(phydev);
genphy_read_status(phydev);
if (ds->ops->adjust_link)
ds->ops->adjust_link(ds, port->index, phydev);
put_device(&phydev->mdio.dev);
}
return 0;
}
const struct dsa_device_ops *dsa_resolve_tag_protocol(int tag_protocol)
{
const struct dsa_device_ops *ops;
if (tag_protocol >= DSA_TAG_LAST)
return ERR_PTR(-EINVAL);
ops = dsa_device_ops[tag_protocol];
if (!ops)
return ERR_PTR(-ENOPROTOOPT);
return ops;
}
int dsa_cpu_port_ethtool_setup(struct dsa_port *cpu_dp)
{
struct dsa_switch *ds = cpu_dp->ds;
struct net_device *master;
struct ethtool_ops *cpu_ops;
master = cpu_dp->netdev;
cpu_ops = devm_kzalloc(ds->dev, sizeof(*cpu_ops), GFP_KERNEL);
if (!cpu_ops)
return -ENOMEM;
memcpy(&cpu_dp->ethtool_ops, master->ethtool_ops,
sizeof(struct ethtool_ops));
cpu_dp->orig_ethtool_ops = master->ethtool_ops;
memcpy(cpu_ops, &cpu_dp->ethtool_ops,
sizeof(struct ethtool_ops));
dsa_cpu_port_ethtool_init(cpu_ops);
master->ethtool_ops = cpu_ops;
return 0;
}
void dsa_cpu_port_ethtool_restore(struct dsa_port *cpu_dp)
{
cpu_dp->netdev->ethtool_ops = cpu_dp->orig_ethtool_ops;
}
void dsa_cpu_dsa_destroy(struct dsa_port *port)
{
struct device_node *port_dn = port->dn;
if (of_phy_is_fixed_link(port_dn))
of_phy_deregister_fixed_link(port_dn);
}
static int dev_is_class(struct device *dev, void *class)
{
if (dev->class != NULL && !strcmp(dev->class->name, class))
return 1;
return 0;
}
static struct device *dev_find_class(struct device *parent, char *class)
{
if (dev_is_class(parent, class)) {
get_device(parent);
return parent;
}
return device_find_child(parent, class, dev_is_class);
}
struct net_device *dsa_dev_to_net_device(struct device *dev)
{
struct device *d;
d = dev_find_class(dev, "net");
if (d != NULL) {
struct net_device *nd;
nd = to_net_dev(d);
dev_hold(nd);
put_device(d);
return nd;
}
return NULL;
}
static int dsa_switch_rcv(struct sk_buff *skb, struct net_device *dev,
struct packet_type *pt, struct net_device *unused)
{
struct dsa_switch_tree *dst = dev->dsa_ptr;
struct sk_buff *nskb = NULL;
struct pcpu_sw_netstats *s;
struct dsa_slave_priv *p;
if (unlikely(dst == NULL)) {
kfree_skb(skb);
return 0;
}
skb = skb_unshare(skb, GFP_ATOMIC);
if (!skb)
return 0;
nskb = dst->rcv(skb, dev, pt);
if (!nskb) {
kfree_skb(skb);
return 0;
}
skb = nskb;
p = netdev_priv(skb->dev);
skb_push(skb, ETH_HLEN);
skb->pkt_type = PACKET_HOST;
skb->protocol = eth_type_trans(skb, skb->dev);
s = this_cpu_ptr(p->stats64);
u64_stats_update_begin(&s->syncp);
s->rx_packets++;
s->rx_bytes += skb->len;
u64_stats_update_end(&s->syncp);
netif_receive_skb(skb);
return 0;
}
static bool dsa_is_port_initialized(struct dsa_switch *ds, int p)
{
return ds->enabled_port_mask & (1 << p) && ds->ports[p].netdev;
}
int dsa_switch_suspend(struct dsa_switch *ds)
{
int i, ret = 0;
for (i = 0; i < ds->num_ports; i++) {
if (!dsa_is_port_initialized(ds, i))
continue;
ret = dsa_slave_suspend(ds->ports[i].netdev);
if (ret)
return ret;
}
if (ds->ops->suspend)
ret = ds->ops->suspend(ds);
return ret;
}
int dsa_switch_resume(struct dsa_switch *ds)
{
int i, ret = 0;
if (ds->ops->resume)
ret = ds->ops->resume(ds);
if (ret)
return ret;
for (i = 0; i < ds->num_ports; i++) {
if (!dsa_is_port_initialized(ds, i))
continue;
ret = dsa_slave_resume(ds->ports[i].netdev);
if (ret)
return ret;
}
return 0;
}
bool dsa_schedule_work(struct work_struct *work)
{
return queue_work(dsa_owq, work);
}
static int __init dsa_init_module(void)
{
int rc;
dsa_owq = alloc_ordered_workqueue("dsa_ordered",
WQ_MEM_RECLAIM);
if (!dsa_owq)
return -ENOMEM;
rc = dsa_slave_register_notifier();
if (rc)
return rc;
rc = dsa_legacy_register();
if (rc)
return rc;
dev_add_pack(&dsa_pack_type);
return 0;
}
static void __exit dsa_cleanup_module(void)
{
dsa_slave_unregister_notifier();
dev_remove_pack(&dsa_pack_type);
dsa_legacy_unregister();
destroy_workqueue(dsa_owq);
}
