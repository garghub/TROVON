int batadv_skb_head_push(struct sk_buff *skb, unsigned int len)
{
int result;
result = skb_cow_head(skb, len);
if (result < 0)
return result;
skb_push(skb, len);
return 0;
}
static int batadv_interface_open(struct net_device *dev)
{
netif_start_queue(dev);
return 0;
}
static int batadv_interface_release(struct net_device *dev)
{
netif_stop_queue(dev);
return 0;
}
static struct net_device_stats *batadv_interface_stats(struct net_device *dev)
{
struct batadv_priv *bat_priv = netdev_priv(dev);
struct net_device_stats *stats = &bat_priv->stats;
stats->tx_packets = batadv_sum_counter(bat_priv, BATADV_CNT_TX);
stats->tx_bytes = batadv_sum_counter(bat_priv, BATADV_CNT_TX_BYTES);
stats->tx_dropped = batadv_sum_counter(bat_priv, BATADV_CNT_TX_DROPPED);
stats->rx_packets = batadv_sum_counter(bat_priv, BATADV_CNT_RX);
stats->rx_bytes = batadv_sum_counter(bat_priv, BATADV_CNT_RX_BYTES);
return stats;
}
static int batadv_interface_set_mac_addr(struct net_device *dev, void *p)
{
struct batadv_priv *bat_priv = netdev_priv(dev);
struct sockaddr *addr = p;
uint8_t old_addr[ETH_ALEN];
if (!is_valid_ether_addr(addr->sa_data))
return -EADDRNOTAVAIL;
memcpy(old_addr, dev->dev_addr, ETH_ALEN);
memcpy(dev->dev_addr, addr->sa_data, ETH_ALEN);
if (atomic_read(&bat_priv->mesh_state) == BATADV_MESH_ACTIVE) {
batadv_tt_local_remove(bat_priv, old_addr,
"mac address changed", false);
batadv_tt_local_add(dev, addr->sa_data, BATADV_NULL_IFINDEX);
}
return 0;
}
static int batadv_interface_change_mtu(struct net_device *dev, int new_mtu)
{
if ((new_mtu < 68) || (new_mtu > batadv_hardif_min_mtu(dev)))
return -EINVAL;
dev->mtu = new_mtu;
return 0;
}
static int batadv_interface_tx(struct sk_buff *skb,
struct net_device *soft_iface)
{
struct ethhdr *ethhdr = (struct ethhdr *)skb->data;
struct batadv_priv *bat_priv = netdev_priv(soft_iface);
struct batadv_hard_iface *primary_if = NULL;
struct batadv_bcast_packet *bcast_packet;
struct vlan_ethhdr *vhdr;
__be16 ethertype = __constant_htons(ETH_P_BATMAN);
static const uint8_t stp_addr[ETH_ALEN] = {0x01, 0x80, 0xC2, 0x00,
0x00, 0x00};
static const uint8_t ectp_addr[ETH_ALEN] = {0xCF, 0x00, 0x00, 0x00,
0x00, 0x00};
unsigned int header_len = 0;
int data_len = skb->len, ret;
short vid __maybe_unused = -1;
bool do_bcast = false;
uint32_t seqno;
unsigned long brd_delay = 1;
if (atomic_read(&bat_priv->mesh_state) != BATADV_MESH_ACTIVE)
goto dropped;
soft_iface->trans_start = jiffies;
switch (ntohs(ethhdr->h_proto)) {
case ETH_P_8021Q:
vhdr = (struct vlan_ethhdr *)skb->data;
vid = ntohs(vhdr->h_vlan_TCI) & VLAN_VID_MASK;
if (vhdr->h_vlan_encapsulated_proto != ethertype)
break;
case ETH_P_BATMAN:
goto dropped;
}
if (batadv_bla_tx(bat_priv, skb, vid))
goto dropped;
if (!is_multicast_ether_addr(ethhdr->h_source))
batadv_tt_local_add(soft_iface, ethhdr->h_source, skb->skb_iif);
if (batadv_compare_eth(ethhdr->h_dest, stp_addr))
goto dropped;
if (batadv_compare_eth(ethhdr->h_dest, ectp_addr))
goto dropped;
if (is_multicast_ether_addr(ethhdr->h_dest)) {
do_bcast = true;
switch (atomic_read(&bat_priv->gw_mode)) {
case BATADV_GW_MODE_SERVER:
ret = batadv_gw_is_dhcp_target(skb, &header_len);
if (ret)
goto dropped;
break;
case BATADV_GW_MODE_CLIENT:
ret = batadv_gw_is_dhcp_target(skb, &header_len);
if (ret)
do_bcast = false;
break;
case BATADV_GW_MODE_OFF:
default:
break;
}
}
if (do_bcast) {
primary_if = batadv_primary_if_get_selected(bat_priv);
if (!primary_if)
goto dropped;
if (batadv_dat_snoop_outgoing_arp_request(bat_priv, skb))
brd_delay = msecs_to_jiffies(ARP_REQ_DELAY);
if (batadv_skb_head_push(skb, sizeof(*bcast_packet)) < 0)
goto dropped;
bcast_packet = (struct batadv_bcast_packet *)skb->data;
bcast_packet->header.version = BATADV_COMPAT_VERSION;
bcast_packet->header.ttl = BATADV_TTL;
bcast_packet->header.packet_type = BATADV_BCAST;
bcast_packet->reserved = 0;
memcpy(bcast_packet->orig,
primary_if->net_dev->dev_addr, ETH_ALEN);
seqno = atomic_inc_return(&bat_priv->bcast_seqno);
bcast_packet->seqno = htonl(seqno);
batadv_add_bcast_packet_to_list(bat_priv, skb, brd_delay);
kfree_skb(skb);
} else {
if (atomic_read(&bat_priv->gw_mode) != BATADV_GW_MODE_OFF) {
ret = batadv_gw_out_of_range(bat_priv, skb, ethhdr);
if (ret)
goto dropped;
}
if (batadv_dat_snoop_outgoing_arp_request(bat_priv, skb))
goto dropped;
batadv_dat_snoop_outgoing_arp_reply(bat_priv, skb);
ret = batadv_unicast_send_skb(bat_priv, skb);
if (ret != 0)
goto dropped_freed;
}
batadv_inc_counter(bat_priv, BATADV_CNT_TX);
batadv_add_counter(bat_priv, BATADV_CNT_TX_BYTES, data_len);
goto end;
dropped:
kfree_skb(skb);
dropped_freed:
batadv_inc_counter(bat_priv, BATADV_CNT_TX_DROPPED);
end:
if (primary_if)
batadv_hardif_free_ref(primary_if);
return NETDEV_TX_OK;
}
void batadv_interface_rx(struct net_device *soft_iface,
struct sk_buff *skb, struct batadv_hard_iface *recv_if,
int hdr_size, struct batadv_orig_node *orig_node)
{
struct batadv_priv *bat_priv = netdev_priv(soft_iface);
struct ethhdr *ethhdr;
struct vlan_ethhdr *vhdr;
struct batadv_header *batadv_header = (struct batadv_header *)skb->data;
short vid __maybe_unused = -1;
__be16 ethertype = __constant_htons(ETH_P_BATMAN);
bool is_bcast;
is_bcast = (batadv_header->packet_type == BATADV_BCAST);
if (!pskb_may_pull(skb, hdr_size))
goto dropped;
skb_pull_rcsum(skb, hdr_size);
skb_reset_mac_header(skb);
ethhdr = (struct ethhdr *)skb_mac_header(skb);
switch (ntohs(ethhdr->h_proto)) {
case ETH_P_8021Q:
vhdr = (struct vlan_ethhdr *)skb->data;
vid = ntohs(vhdr->h_vlan_TCI) & VLAN_VID_MASK;
if (vhdr->h_vlan_encapsulated_proto != ethertype)
break;
case ETH_P_BATMAN:
goto dropped;
}
if (unlikely(!pskb_may_pull(skb, ETH_HLEN)))
goto dropped;
skb->protocol = eth_type_trans(skb, soft_iface);
batadv_inc_counter(bat_priv, BATADV_CNT_RX);
batadv_add_counter(bat_priv, BATADV_CNT_RX_BYTES,
skb->len + ETH_HLEN);
soft_iface->last_rx = jiffies;
if (batadv_bla_rx(bat_priv, skb, vid, is_bcast))
goto out;
if (orig_node)
batadv_tt_add_temporary_global_entry(bat_priv, orig_node,
ethhdr->h_source);
if (batadv_is_ap_isolated(bat_priv, ethhdr->h_source, ethhdr->h_dest))
goto dropped;
netif_rx(skb);
goto out;
dropped:
kfree_skb(skb);
out:
return;
}
static void batadv_set_lockdep_class_one(struct net_device *dev,
struct netdev_queue *txq,
void *_unused)
{
lockdep_set_class(&txq->_xmit_lock, &batadv_netdev_xmit_lock_key);
}
static void batadv_set_lockdep_class(struct net_device *dev)
{
lockdep_set_class(&dev->addr_list_lock, &batadv_netdev_addr_lock_key);
netdev_for_each_tx_queue(dev, batadv_set_lockdep_class_one, NULL);
}
static void batadv_softif_destroy_finish(struct work_struct *work)
{
struct batadv_priv *bat_priv;
struct net_device *soft_iface;
bat_priv = container_of(work, struct batadv_priv,
cleanup_work);
soft_iface = bat_priv->soft_iface;
batadv_sysfs_del_meshif(soft_iface);
rtnl_lock();
unregister_netdevice(soft_iface);
rtnl_unlock();
}
static int batadv_softif_init_late(struct net_device *dev)
{
struct batadv_priv *bat_priv;
int ret;
size_t cnt_len = sizeof(uint64_t) * BATADV_CNT_NUM;
batadv_set_lockdep_class(dev);
bat_priv = netdev_priv(dev);
bat_priv->soft_iface = dev;
INIT_WORK(&bat_priv->cleanup_work, batadv_softif_destroy_finish);
bat_priv->bat_counters = __alloc_percpu(cnt_len, __alignof__(uint64_t));
if (!bat_priv->bat_counters)
return -ENOMEM;
atomic_set(&bat_priv->aggregated_ogms, 1);
atomic_set(&bat_priv->bonding, 0);
#ifdef CONFIG_BATMAN_ADV_BLA
atomic_set(&bat_priv->bridge_loop_avoidance, 0);
#endif
#ifdef CONFIG_BATMAN_ADV_DAT
atomic_set(&bat_priv->distributed_arp_table, 1);
#endif
atomic_set(&bat_priv->ap_isolation, 0);
atomic_set(&bat_priv->vis_mode, BATADV_VIS_TYPE_CLIENT_UPDATE);
atomic_set(&bat_priv->gw_mode, BATADV_GW_MODE_OFF);
atomic_set(&bat_priv->gw_sel_class, 20);
atomic_set(&bat_priv->gw_bandwidth, 41);
atomic_set(&bat_priv->orig_interval, 1000);
atomic_set(&bat_priv->hop_penalty, 30);
#ifdef CONFIG_BATMAN_ADV_DEBUG
atomic_set(&bat_priv->log_level, 0);
#endif
atomic_set(&bat_priv->fragmentation, 1);
atomic_set(&bat_priv->bcast_queue_left, BATADV_BCAST_QUEUE_LEN);
atomic_set(&bat_priv->batman_queue_left, BATADV_BATMAN_QUEUE_LEN);
atomic_set(&bat_priv->mesh_state, BATADV_MESH_INACTIVE);
atomic_set(&bat_priv->bcast_seqno, 1);
atomic_set(&bat_priv->tt.vn, 0);
atomic_set(&bat_priv->tt.local_changes, 0);
atomic_set(&bat_priv->tt.ogm_append_cnt, 0);
#ifdef CONFIG_BATMAN_ADV_BLA
atomic_set(&bat_priv->bla.num_requests, 0);
#endif
bat_priv->tt.last_changeset = NULL;
bat_priv->tt.last_changeset_len = 0;
bat_priv->primary_if = NULL;
bat_priv->num_ifaces = 0;
batadv_nc_init_bat_priv(bat_priv);
ret = batadv_algo_select(bat_priv, batadv_routing_algo);
if (ret < 0)
goto free_bat_counters;
ret = batadv_debugfs_add_meshif(dev);
if (ret < 0)
goto free_bat_counters;
ret = batadv_mesh_init(dev);
if (ret < 0)
goto unreg_debugfs;
return 0;
unreg_debugfs:
batadv_debugfs_del_meshif(dev);
free_bat_counters:
free_percpu(bat_priv->bat_counters);
bat_priv->bat_counters = NULL;
return ret;
}
static int batadv_softif_slave_add(struct net_device *dev,
struct net_device *slave_dev)
{
struct batadv_hard_iface *hard_iface;
int ret = -EINVAL;
hard_iface = batadv_hardif_get_by_netdev(slave_dev);
if (!hard_iface || hard_iface->soft_iface != NULL)
goto out;
ret = batadv_hardif_enable_interface(hard_iface, dev->name);
out:
if (hard_iface)
batadv_hardif_free_ref(hard_iface);
return ret;
}
static int batadv_softif_slave_del(struct net_device *dev,
struct net_device *slave_dev)
{
struct batadv_hard_iface *hard_iface;
int ret = -EINVAL;
hard_iface = batadv_hardif_get_by_netdev(slave_dev);
if (!hard_iface || hard_iface->soft_iface != dev)
goto out;
batadv_hardif_disable_interface(hard_iface, BATADV_IF_CLEANUP_KEEP);
ret = 0;
out:
if (hard_iface)
batadv_hardif_free_ref(hard_iface);
return ret;
}
static void batadv_softif_free(struct net_device *dev)
{
batadv_debugfs_del_meshif(dev);
batadv_mesh_free(dev);
rcu_barrier();
free_netdev(dev);
}
static void batadv_softif_init_early(struct net_device *dev)
{
struct batadv_priv *priv = netdev_priv(dev);
ether_setup(dev);
dev->netdev_ops = &batadv_netdev_ops;
dev->destructor = batadv_softif_free;
dev->tx_queue_len = 0;
dev->mtu = ETH_DATA_LEN;
dev->hard_header_len = BATADV_HEADER_LEN;
eth_hw_addr_random(dev);
SET_ETHTOOL_OPS(dev, &batadv_ethtool_ops);
memset(priv, 0, sizeof(*priv));
}
struct net_device *batadv_softif_create(const char *name)
{
struct net_device *soft_iface;
int ret;
soft_iface = alloc_netdev(sizeof(struct batadv_priv), name,
batadv_softif_init_early);
if (!soft_iface)
return NULL;
soft_iface->rtnl_link_ops = &batadv_link_ops;
ret = register_netdevice(soft_iface);
if (ret < 0) {
pr_err("Unable to register the batman interface '%s': %i\n",
name, ret);
free_netdev(soft_iface);
return NULL;
}
return soft_iface;
}
void batadv_softif_destroy_sysfs(struct net_device *soft_iface)
{
struct batadv_priv *bat_priv = netdev_priv(soft_iface);
queue_work(batadv_event_workqueue, &bat_priv->cleanup_work);
}
static void batadv_softif_destroy_netlink(struct net_device *soft_iface,
struct list_head *head)
{
struct batadv_hard_iface *hard_iface;
list_for_each_entry(hard_iface, &batadv_hardif_list, list) {
if (hard_iface->soft_iface == soft_iface)
batadv_hardif_disable_interface(hard_iface,
BATADV_IF_CLEANUP_KEEP);
}
batadv_sysfs_del_meshif(soft_iface);
unregister_netdevice_queue(soft_iface, head);
}
int batadv_softif_is_valid(const struct net_device *net_dev)
{
if (net_dev->netdev_ops->ndo_start_xmit == batadv_interface_tx)
return 1;
return 0;
}
static int batadv_get_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
cmd->supported = 0;
cmd->advertising = 0;
ethtool_cmd_speed_set(cmd, SPEED_10);
cmd->duplex = DUPLEX_FULL;
cmd->port = PORT_TP;
cmd->phy_address = 0;
cmd->transceiver = XCVR_INTERNAL;
cmd->autoneg = AUTONEG_DISABLE;
cmd->maxtxpkt = 0;
cmd->maxrxpkt = 0;
return 0;
}
static void batadv_get_drvinfo(struct net_device *dev,
struct ethtool_drvinfo *info)
{
strlcpy(info->driver, "B.A.T.M.A.N. advanced", sizeof(info->driver));
strlcpy(info->version, BATADV_SOURCE_VERSION, sizeof(info->version));
strlcpy(info->fw_version, "N/A", sizeof(info->fw_version));
strlcpy(info->bus_info, "batman", sizeof(info->bus_info));
}
static u32 batadv_get_msglevel(struct net_device *dev)
{
return -EOPNOTSUPP;
}
static void batadv_set_msglevel(struct net_device *dev, u32 value)
{
}
static u32 batadv_get_link(struct net_device *dev)
{
return 1;
}
static void batadv_get_strings(struct net_device *dev, uint32_t stringset,
uint8_t *data)
{
if (stringset == ETH_SS_STATS)
memcpy(data, batadv_counters_strings,
sizeof(batadv_counters_strings));
}
static void batadv_get_ethtool_stats(struct net_device *dev,
struct ethtool_stats *stats,
uint64_t *data)
{
struct batadv_priv *bat_priv = netdev_priv(dev);
int i;
for (i = 0; i < BATADV_CNT_NUM; i++)
data[i] = batadv_sum_counter(bat_priv, i);
}
static int batadv_get_sset_count(struct net_device *dev, int stringset)
{
if (stringset == ETH_SS_STATS)
return BATADV_CNT_NUM;
return -EOPNOTSUPP;
}
