void register_hsr_master(struct hsr_priv *hsr_priv)
{
list_add_tail_rcu(&hsr_priv->hsr_list, &hsr_list);
}
void unregister_hsr_master(struct hsr_priv *hsr_priv)
{
struct hsr_priv *hsr_priv_it;
list_for_each_entry(hsr_priv_it, &hsr_list, hsr_list)
if (hsr_priv_it == hsr_priv) {
list_del_rcu(&hsr_priv_it->hsr_list);
return;
}
}
bool is_hsr_slave(struct net_device *dev)
{
struct hsr_priv *hsr_priv_it;
list_for_each_entry_rcu(hsr_priv_it, &hsr_list, hsr_list) {
if (dev == hsr_priv_it->slave[0])
return true;
if (dev == hsr_priv_it->slave[1])
return true;
}
return false;
}
static struct hsr_priv *get_hsr_master(struct net_device *dev)
{
struct hsr_priv *hsr_priv;
rcu_read_lock();
list_for_each_entry_rcu(hsr_priv, &hsr_list, hsr_list)
if ((dev == hsr_priv->slave[0]) ||
(dev == hsr_priv->slave[1])) {
rcu_read_unlock();
return hsr_priv;
}
rcu_read_unlock();
return NULL;
}
static struct net_device *get_other_slave(struct hsr_priv *hsr_priv,
struct net_device *dev)
{
if (dev == hsr_priv->slave[0])
return hsr_priv->slave[1];
if (dev == hsr_priv->slave[1])
return hsr_priv->slave[0];
return NULL;
}
static int hsr_netdev_notify(struct notifier_block *nb, unsigned long event,
void *ptr)
{
struct net_device *slave, *other_slave;
struct hsr_priv *hsr_priv;
int old_operstate;
int mtu_max;
int res;
struct net_device *dev;
dev = netdev_notifier_info_to_dev(ptr);
hsr_priv = get_hsr_master(dev);
if (hsr_priv) {
slave = dev;
other_slave = get_other_slave(hsr_priv, slave);
} else {
if (!is_hsr_master(dev))
return NOTIFY_DONE;
hsr_priv = netdev_priv(dev);
slave = hsr_priv->slave[0];
other_slave = hsr_priv->slave[1];
}
switch (event) {
case NETDEV_UP:
case NETDEV_DOWN:
case NETDEV_CHANGE:
old_operstate = hsr_priv->dev->operstate;
hsr_set_carrier(hsr_priv->dev, slave, other_slave);
hsr_set_operstate(hsr_priv->dev, slave, other_slave);
hsr_check_announce(hsr_priv->dev, old_operstate);
break;
case NETDEV_CHANGEADDR:
if (dev == hsr_priv->dev)
break;
if (dev == hsr_priv->slave[0])
memcpy(hsr_priv->dev->dev_addr,
hsr_priv->slave[0]->dev_addr, ETH_ALEN);
res = hsr_create_self_node(&hsr_priv->self_node_db,
hsr_priv->dev->dev_addr,
hsr_priv->slave[1] ?
hsr_priv->slave[1]->dev_addr :
hsr_priv->dev->dev_addr);
if (res)
netdev_warn(hsr_priv->dev,
"Could not update HSR node address.\n");
if (dev == hsr_priv->slave[0])
call_netdevice_notifiers(NETDEV_CHANGEADDR, hsr_priv->dev);
break;
case NETDEV_CHANGEMTU:
if (dev == hsr_priv->dev)
break;
mtu_max = hsr_get_max_mtu(hsr_priv);
if (hsr_priv->dev->mtu > mtu_max)
dev_set_mtu(hsr_priv->dev, mtu_max);
break;
case NETDEV_UNREGISTER:
if (dev == hsr_priv->slave[0])
hsr_priv->slave[0] = NULL;
if (dev == hsr_priv->slave[1])
hsr_priv->slave[1] = NULL;
break;
case NETDEV_PRE_TYPE_CHANGE:
return NOTIFY_BAD;
}
return NOTIFY_DONE;
}
static void prune_nodes_all(unsigned long data)
{
struct hsr_priv *hsr_priv;
rcu_read_lock();
list_for_each_entry_rcu(hsr_priv, &hsr_list, hsr_list)
hsr_prune_nodes(hsr_priv);
rcu_read_unlock();
prune_timer.expires = jiffies + msecs_to_jiffies(PRUNE_PERIOD);
add_timer(&prune_timer);
}
static struct sk_buff *hsr_pull_tag(struct sk_buff *skb)
{
struct hsr_tag *hsr_tag;
struct sk_buff *skb2;
skb2 = skb_share_check(skb, GFP_ATOMIC);
if (unlikely(!skb2))
goto err_free;
skb = skb2;
if (unlikely(!pskb_may_pull(skb, HSR_TAGLEN)))
goto err_free;
hsr_tag = (struct hsr_tag *) skb->data;
skb->protocol = hsr_tag->encap_proto;
skb_pull(skb, HSR_TAGLEN);
return skb;
err_free:
kfree_skb(skb);
return NULL;
}
static bool is_supervision_frame(struct hsr_priv *hsr_priv, struct sk_buff *skb)
{
struct hsr_sup_tag *hsr_stag;
if (!ether_addr_equal(eth_hdr(skb)->h_dest,
hsr_priv->sup_multicast_addr))
return false;
hsr_stag = (struct hsr_sup_tag *) skb->data;
if (get_hsr_stag_path(hsr_stag) != 0x0f)
return false;
if ((hsr_stag->HSR_TLV_Type != HSR_TLV_ANNOUNCE) &&
(hsr_stag->HSR_TLV_Type != HSR_TLV_LIFE_CHECK))
return false;
if (hsr_stag->HSR_TLV_Length != 12)
return false;
return true;
}
static int hsr_rcv(struct sk_buff *skb, struct net_device *dev,
struct packet_type *pt, struct net_device *orig_dev)
{
struct hsr_priv *hsr_priv;
struct net_device *other_slave;
struct node_entry *node;
bool deliver_to_self;
struct sk_buff *skb_deliver;
enum hsr_dev_idx dev_in_idx, dev_other_idx;
bool dup_out;
int ret;
hsr_priv = get_hsr_master(dev);
if (!hsr_priv) {
kfree_skb(skb);
dev->stats.rx_errors++;
return NET_RX_SUCCESS;
}
if (dev == hsr_priv->slave[0]) {
dev_in_idx = HSR_DEV_SLAVE_A;
dev_other_idx = HSR_DEV_SLAVE_B;
} else {
dev_in_idx = HSR_DEV_SLAVE_B;
dev_other_idx = HSR_DEV_SLAVE_A;
}
node = hsr_find_node(&hsr_priv->self_node_db, skb);
if (node) {
kfree_skb(skb);
return NET_RX_SUCCESS;
}
deliver_to_self = false;
if ((skb->pkt_type == PACKET_HOST) ||
(skb->pkt_type == PACKET_MULTICAST) ||
(skb->pkt_type == PACKET_BROADCAST))
deliver_to_self = true;
else if (ether_addr_equal(eth_hdr(skb)->h_dest,
hsr_priv->dev->dev_addr)) {
skb->pkt_type = PACKET_HOST;
deliver_to_self = true;
}
rcu_read_lock();
node = hsr_find_node(&hsr_priv->node_db, skb);
if (is_supervision_frame(hsr_priv, skb)) {
skb_pull(skb, sizeof(struct hsr_sup_tag));
node = hsr_merge_node(hsr_priv, node, skb, dev_in_idx);
if (!node) {
rcu_read_unlock();
kfree_skb(skb);
hsr_priv->dev->stats.rx_dropped++;
return NET_RX_DROP;
}
skb_push(skb, sizeof(struct hsr_sup_tag));
deliver_to_self = false;
}
if (!node) {
rcu_read_unlock();
kfree_skb(skb);
return NET_RX_SUCCESS;
}
dup_out = hsr_register_frame_out(node, dev_other_idx, skb);
if (!dup_out)
hsr_register_frame_in(node, dev_in_idx);
if (!dup_out && (skb->pkt_type != PACKET_HOST))
other_slave = get_other_slave(hsr_priv, dev);
else
other_slave = NULL;
if (hsr_register_frame_out(node, HSR_DEV_MASTER, skb))
deliver_to_self = false;
rcu_read_unlock();
if (!deliver_to_self && !other_slave) {
kfree_skb(skb);
return NET_RX_SUCCESS;
}
skb_deliver = skb;
if (deliver_to_self && other_slave) {
skb_deliver = pskb_copy(skb, GFP_ATOMIC);
if (!skb_deliver) {
deliver_to_self = false;
hsr_priv->dev->stats.rx_dropped++;
}
}
if (deliver_to_self) {
bool multicast_frame;
skb_deliver = hsr_pull_tag(skb_deliver);
if (!skb_deliver) {
hsr_priv->dev->stats.rx_dropped++;
goto forward;
}
#if !defined(CONFIG_HAVE_EFFICIENT_UNALIGNED_ACCESS)
memmove(skb_deliver->data - HSR_TAGLEN, skb_deliver->data,
skb_headlen(skb_deliver));
skb_deliver->data -= HSR_TAGLEN;
skb_deliver->tail -= HSR_TAGLEN;
#endif
skb_deliver->dev = hsr_priv->dev;
hsr_addr_subst_source(hsr_priv, skb_deliver);
multicast_frame = (skb_deliver->pkt_type == PACKET_MULTICAST);
ret = netif_rx(skb_deliver);
if (ret == NET_RX_DROP) {
hsr_priv->dev->stats.rx_dropped++;
} else {
hsr_priv->dev->stats.rx_packets++;
hsr_priv->dev->stats.rx_bytes += skb->len;
if (multicast_frame)
hsr_priv->dev->stats.multicast++;
}
}
forward:
if (other_slave) {
skb_push(skb, ETH_HLEN);
skb->dev = other_slave;
dev_queue_xmit(skb);
}
return NET_RX_SUCCESS;
}
static int __init hsr_init(void)
{
int res;
BUILD_BUG_ON(sizeof(struct hsr_tag) != HSR_TAGLEN);
dev_add_pack(&hsr_pt);
init_timer(&prune_timer);
prune_timer.function = prune_nodes_all;
prune_timer.data = 0;
prune_timer.expires = jiffies + msecs_to_jiffies(PRUNE_PERIOD);
add_timer(&prune_timer);
register_netdevice_notifier(&hsr_nb);
res = hsr_netlink_init();
return res;
}
static void __exit hsr_exit(void)
{
unregister_netdevice_notifier(&hsr_nb);
del_timer(&prune_timer);
hsr_netlink_exit();
dev_remove_pack(&hsr_pt);
}
