int my_skb_head_push(struct sk_buff *skb, unsigned int len)
{
int result;
result = skb_cow_head(skb, len);
if (result < 0)
return result;
skb_push(skb, len);
return 0;
}
static void softif_neigh_free_ref(struct softif_neigh *softif_neigh)
{
if (atomic_dec_and_test(&softif_neigh->refcount))
kfree_rcu(softif_neigh, rcu);
}
static void softif_neigh_vid_free_rcu(struct rcu_head *rcu)
{
struct softif_neigh_vid *softif_neigh_vid;
struct softif_neigh *softif_neigh;
struct hlist_node *node, *node_tmp;
struct bat_priv *bat_priv;
softif_neigh_vid = container_of(rcu, struct softif_neigh_vid, rcu);
bat_priv = softif_neigh_vid->bat_priv;
spin_lock_bh(&bat_priv->softif_neigh_lock);
hlist_for_each_entry_safe(softif_neigh, node, node_tmp,
&softif_neigh_vid->softif_neigh_list, list) {
hlist_del_rcu(&softif_neigh->list);
softif_neigh_free_ref(softif_neigh);
}
spin_unlock_bh(&bat_priv->softif_neigh_lock);
kfree(softif_neigh_vid);
}
static void softif_neigh_vid_free_ref(struct softif_neigh_vid *softif_neigh_vid)
{
if (atomic_dec_and_test(&softif_neigh_vid->refcount))
call_rcu(&softif_neigh_vid->rcu, softif_neigh_vid_free_rcu);
}
static struct softif_neigh_vid *softif_neigh_vid_get(struct bat_priv *bat_priv,
short vid)
{
struct softif_neigh_vid *softif_neigh_vid;
struct hlist_node *node;
rcu_read_lock();
hlist_for_each_entry_rcu(softif_neigh_vid, node,
&bat_priv->softif_neigh_vids, list) {
if (softif_neigh_vid->vid != vid)
continue;
if (!atomic_inc_not_zero(&softif_neigh_vid->refcount))
continue;
goto out;
}
softif_neigh_vid = kzalloc(sizeof(struct softif_neigh_vid),
GFP_ATOMIC);
if (!softif_neigh_vid)
goto out;
softif_neigh_vid->vid = vid;
softif_neigh_vid->bat_priv = bat_priv;
atomic_set(&softif_neigh_vid->refcount, 2);
INIT_HLIST_HEAD(&softif_neigh_vid->softif_neigh_list);
INIT_HLIST_NODE(&softif_neigh_vid->list);
spin_lock_bh(&bat_priv->softif_neigh_vid_lock);
hlist_add_head_rcu(&softif_neigh_vid->list,
&bat_priv->softif_neigh_vids);
spin_unlock_bh(&bat_priv->softif_neigh_vid_lock);
out:
rcu_read_unlock();
return softif_neigh_vid;
}
static struct softif_neigh *softif_neigh_get(struct bat_priv *bat_priv,
uint8_t *addr, short vid)
{
struct softif_neigh_vid *softif_neigh_vid;
struct softif_neigh *softif_neigh = NULL;
struct hlist_node *node;
softif_neigh_vid = softif_neigh_vid_get(bat_priv, vid);
if (!softif_neigh_vid)
goto out;
rcu_read_lock();
hlist_for_each_entry_rcu(softif_neigh, node,
&softif_neigh_vid->softif_neigh_list,
list) {
if (!compare_eth(softif_neigh->addr, addr))
continue;
if (!atomic_inc_not_zero(&softif_neigh->refcount))
continue;
softif_neigh->last_seen = jiffies;
goto unlock;
}
softif_neigh = kzalloc(sizeof(struct softif_neigh), GFP_ATOMIC);
if (!softif_neigh)
goto unlock;
memcpy(softif_neigh->addr, addr, ETH_ALEN);
softif_neigh->last_seen = jiffies;
atomic_set(&softif_neigh->refcount, 2);
INIT_HLIST_NODE(&softif_neigh->list);
spin_lock_bh(&bat_priv->softif_neigh_lock);
hlist_add_head_rcu(&softif_neigh->list,
&softif_neigh_vid->softif_neigh_list);
spin_unlock_bh(&bat_priv->softif_neigh_lock);
unlock:
rcu_read_unlock();
out:
if (softif_neigh_vid)
softif_neigh_vid_free_ref(softif_neigh_vid);
return softif_neigh;
}
static struct softif_neigh *softif_neigh_get_selected(
struct softif_neigh_vid *softif_neigh_vid)
{
struct softif_neigh *softif_neigh;
rcu_read_lock();
softif_neigh = rcu_dereference(softif_neigh_vid->softif_neigh);
if (softif_neigh && !atomic_inc_not_zero(&softif_neigh->refcount))
softif_neigh = NULL;
rcu_read_unlock();
return softif_neigh;
}
static struct softif_neigh *softif_neigh_vid_get_selected(
struct bat_priv *bat_priv,
short vid)
{
struct softif_neigh_vid *softif_neigh_vid;
struct softif_neigh *softif_neigh = NULL;
softif_neigh_vid = softif_neigh_vid_get(bat_priv, vid);
if (!softif_neigh_vid)
goto out;
softif_neigh = softif_neigh_get_selected(softif_neigh_vid);
out:
if (softif_neigh_vid)
softif_neigh_vid_free_ref(softif_neigh_vid);
return softif_neigh;
}
static void softif_neigh_vid_select(struct bat_priv *bat_priv,
struct softif_neigh *new_neigh,
short vid)
{
struct softif_neigh_vid *softif_neigh_vid;
struct softif_neigh *curr_neigh;
softif_neigh_vid = softif_neigh_vid_get(bat_priv, vid);
if (!softif_neigh_vid)
goto out;
spin_lock_bh(&bat_priv->softif_neigh_lock);
if (new_neigh && !atomic_inc_not_zero(&new_neigh->refcount))
new_neigh = NULL;
curr_neigh = softif_neigh_vid->softif_neigh;
rcu_assign_pointer(softif_neigh_vid->softif_neigh, new_neigh);
if ((curr_neigh) && (!new_neigh))
bat_dbg(DBG_ROUTES, bat_priv,
"Removing mesh exit point on vid: %d (prev: %pM).\n",
vid, curr_neigh->addr);
else if ((curr_neigh) && (new_neigh))
bat_dbg(DBG_ROUTES, bat_priv,
"Changing mesh exit point on vid: %d from %pM "
"to %pM.\n", vid, curr_neigh->addr, new_neigh->addr);
else if ((!curr_neigh) && (new_neigh))
bat_dbg(DBG_ROUTES, bat_priv,
"Setting mesh exit point on vid: %d to %pM.\n",
vid, new_neigh->addr);
if (curr_neigh)
softif_neigh_free_ref(curr_neigh);
spin_unlock_bh(&bat_priv->softif_neigh_lock);
out:
if (softif_neigh_vid)
softif_neigh_vid_free_ref(softif_neigh_vid);
}
static void softif_neigh_vid_deselect(struct bat_priv *bat_priv,
struct softif_neigh_vid *softif_neigh_vid)
{
struct softif_neigh *curr_neigh;
struct softif_neigh *softif_neigh = NULL, *softif_neigh_tmp;
struct hard_iface *primary_if = NULL;
struct hlist_node *node;
primary_if = primary_if_get_selected(bat_priv);
if (!primary_if)
goto out;
rcu_read_lock();
curr_neigh = rcu_dereference(softif_neigh_vid->softif_neigh);
hlist_for_each_entry_rcu(softif_neigh_tmp, node,
&softif_neigh_vid->softif_neigh_list,
list) {
if (softif_neigh_tmp == curr_neigh)
continue;
if (memcmp(primary_if->net_dev->dev_addr,
softif_neigh_tmp->addr, ETH_ALEN) < 0)
continue;
if (!atomic_inc_not_zero(&softif_neigh_tmp->refcount))
continue;
softif_neigh = softif_neigh_tmp;
goto unlock;
}
unlock:
rcu_read_unlock();
out:
softif_neigh_vid_select(bat_priv, softif_neigh, softif_neigh_vid->vid);
if (primary_if)
hardif_free_ref(primary_if);
if (softif_neigh)
softif_neigh_free_ref(softif_neigh);
}
int softif_neigh_seq_print_text(struct seq_file *seq, void *offset)
{
struct net_device *net_dev = (struct net_device *)seq->private;
struct bat_priv *bat_priv = netdev_priv(net_dev);
struct softif_neigh_vid *softif_neigh_vid;
struct softif_neigh *softif_neigh;
struct hard_iface *primary_if;
struct hlist_node *node, *node_tmp;
struct softif_neigh *curr_softif_neigh;
int ret = 0, last_seen_secs, last_seen_msecs;
primary_if = primary_if_get_selected(bat_priv);
if (!primary_if) {
ret = seq_printf(seq, "BATMAN mesh %s disabled - "
"please specify interfaces to enable it\n",
net_dev->name);
goto out;
}
if (primary_if->if_status != IF_ACTIVE) {
ret = seq_printf(seq, "BATMAN mesh %s "
"disabled - primary interface not active\n",
net_dev->name);
goto out;
}
seq_printf(seq, "Softif neighbor list (%s)\n", net_dev->name);
rcu_read_lock();
hlist_for_each_entry_rcu(softif_neigh_vid, node,
&bat_priv->softif_neigh_vids, list) {
seq_printf(seq, " %-15s %s on vid: %d\n",
"Originator", "last-seen", softif_neigh_vid->vid);
curr_softif_neigh = softif_neigh_get_selected(softif_neigh_vid);
hlist_for_each_entry_rcu(softif_neigh, node_tmp,
&softif_neigh_vid->softif_neigh_list,
list) {
last_seen_secs = jiffies_to_msecs(jiffies -
softif_neigh->last_seen) / 1000;
last_seen_msecs = jiffies_to_msecs(jiffies -
softif_neigh->last_seen) % 1000;
seq_printf(seq, "%s %pM %3i.%03is\n",
curr_softif_neigh == softif_neigh
? "=>" : " ", softif_neigh->addr,
last_seen_secs, last_seen_msecs);
}
if (curr_softif_neigh)
softif_neigh_free_ref(curr_softif_neigh);
seq_printf(seq, "\n");
}
rcu_read_unlock();
out:
if (primary_if)
hardif_free_ref(primary_if);
return ret;
}
void softif_neigh_purge(struct bat_priv *bat_priv)
{
struct softif_neigh *softif_neigh, *curr_softif_neigh;
struct softif_neigh_vid *softif_neigh_vid;
struct hlist_node *node, *node_tmp, *node_tmp2;
char do_deselect;
rcu_read_lock();
hlist_for_each_entry_rcu(softif_neigh_vid, node,
&bat_priv->softif_neigh_vids, list) {
if (!atomic_inc_not_zero(&softif_neigh_vid->refcount))
continue;
curr_softif_neigh = softif_neigh_get_selected(softif_neigh_vid);
do_deselect = 0;
spin_lock_bh(&bat_priv->softif_neigh_lock);
hlist_for_each_entry_safe(softif_neigh, node_tmp, node_tmp2,
&softif_neigh_vid->softif_neigh_list,
list) {
if ((!time_after(jiffies, softif_neigh->last_seen +
msecs_to_jiffies(SOFTIF_NEIGH_TIMEOUT))) &&
(atomic_read(&bat_priv->mesh_state) == MESH_ACTIVE))
continue;
if (curr_softif_neigh == softif_neigh) {
bat_dbg(DBG_ROUTES, bat_priv,
"Current mesh exit point on vid: %d "
"'%pM' vanished.\n",
softif_neigh_vid->vid,
softif_neigh->addr);
do_deselect = 1;
}
hlist_del_rcu(&softif_neigh->list);
softif_neigh_free_ref(softif_neigh);
}
spin_unlock_bh(&bat_priv->softif_neigh_lock);
if (do_deselect)
softif_neigh_vid_deselect(bat_priv, softif_neigh_vid);
if (curr_softif_neigh)
softif_neigh_free_ref(curr_softif_neigh);
softif_neigh_vid_free_ref(softif_neigh_vid);
}
rcu_read_unlock();
spin_lock_bh(&bat_priv->softif_neigh_vid_lock);
hlist_for_each_entry_safe(softif_neigh_vid, node, node_tmp,
&bat_priv->softif_neigh_vids, list) {
if (!hlist_empty(&softif_neigh_vid->softif_neigh_list))
continue;
hlist_del_rcu(&softif_neigh_vid->list);
softif_neigh_vid_free_ref(softif_neigh_vid);
}
spin_unlock_bh(&bat_priv->softif_neigh_vid_lock);
}
static void softif_batman_recv(struct sk_buff *skb, struct net_device *dev,
short vid)
{
struct bat_priv *bat_priv = netdev_priv(dev);
struct ethhdr *ethhdr = (struct ethhdr *)skb->data;
struct batman_packet *batman_packet;
struct softif_neigh *softif_neigh = NULL;
struct hard_iface *primary_if = NULL;
struct softif_neigh *curr_softif_neigh = NULL;
if (ntohs(ethhdr->h_proto) == ETH_P_8021Q)
batman_packet = (struct batman_packet *)
(skb->data + ETH_HLEN + VLAN_HLEN);
else
batman_packet = (struct batman_packet *)(skb->data + ETH_HLEN);
if (batman_packet->version != COMPAT_VERSION)
goto out;
if (batman_packet->packet_type != BAT_PACKET)
goto out;
if (!(batman_packet->flags & PRIMARIES_FIRST_HOP))
goto out;
if (is_my_mac(batman_packet->orig))
goto out;
softif_neigh = softif_neigh_get(bat_priv, batman_packet->orig, vid);
if (!softif_neigh)
goto out;
curr_softif_neigh = softif_neigh_vid_get_selected(bat_priv, vid);
if (curr_softif_neigh == softif_neigh)
goto out;
primary_if = primary_if_get_selected(bat_priv);
if (!primary_if)
goto out;
if (memcmp(primary_if->net_dev->dev_addr,
softif_neigh->addr, ETH_ALEN) < 0)
goto out;
if (!curr_softif_neigh) {
softif_neigh_vid_select(bat_priv, softif_neigh, vid);
goto out;
}
if (memcmp(softif_neigh->addr, curr_softif_neigh->addr, ETH_ALEN) < 0)
softif_neigh_vid_select(bat_priv, softif_neigh, vid);
out:
kfree_skb(skb);
if (softif_neigh)
softif_neigh_free_ref(softif_neigh);
if (curr_softif_neigh)
softif_neigh_free_ref(curr_softif_neigh);
if (primary_if)
hardif_free_ref(primary_if);
return;
}
static int interface_open(struct net_device *dev)
{
netif_start_queue(dev);
return 0;
}
static int interface_release(struct net_device *dev)
{
netif_stop_queue(dev);
return 0;
}
static struct net_device_stats *interface_stats(struct net_device *dev)
{
struct bat_priv *bat_priv = netdev_priv(dev);
return &bat_priv->stats;
}
static int interface_set_mac_addr(struct net_device *dev, void *p)
{
struct bat_priv *bat_priv = netdev_priv(dev);
struct sockaddr *addr = p;
if (!is_valid_ether_addr(addr->sa_data))
return -EADDRNOTAVAIL;
if (atomic_read(&bat_priv->mesh_state) == MESH_ACTIVE) {
tt_local_remove(bat_priv, dev->dev_addr,
"mac address changed");
tt_local_add(dev, addr->sa_data);
}
memcpy(dev->dev_addr, addr->sa_data, ETH_ALEN);
return 0;
}
static int interface_change_mtu(struct net_device *dev, int new_mtu)
{
if ((new_mtu < 68) || (new_mtu > hardif_min_mtu(dev)))
return -EINVAL;
dev->mtu = new_mtu;
return 0;
}
int interface_tx(struct sk_buff *skb, struct net_device *soft_iface)
{
struct ethhdr *ethhdr = (struct ethhdr *)skb->data;
struct bat_priv *bat_priv = netdev_priv(soft_iface);
struct hard_iface *primary_if = NULL;
struct bcast_packet *bcast_packet;
struct vlan_ethhdr *vhdr;
struct softif_neigh *curr_softif_neigh = NULL;
int data_len = skb->len, ret;
short vid = -1;
bool do_bcast = false;
if (atomic_read(&bat_priv->mesh_state) != MESH_ACTIVE)
goto dropped;
soft_iface->trans_start = jiffies;
switch (ntohs(ethhdr->h_proto)) {
case ETH_P_8021Q:
vhdr = (struct vlan_ethhdr *)skb->data;
vid = ntohs(vhdr->h_vlan_TCI) & VLAN_VID_MASK;
if (ntohs(vhdr->h_vlan_encapsulated_proto) != ETH_P_BATMAN)
break;
case ETH_P_BATMAN:
softif_batman_recv(skb, soft_iface, vid);
goto end;
}
curr_softif_neigh = softif_neigh_vid_get_selected(bat_priv, vid);
if (curr_softif_neigh)
goto dropped;
tt_local_add(soft_iface, ethhdr->h_source);
if (is_multicast_ether_addr(ethhdr->h_dest)) {
ret = gw_is_target(bat_priv, skb);
if (ret < 0)
goto dropped;
if (ret == 0)
do_bcast = true;
}
if (do_bcast) {
primary_if = primary_if_get_selected(bat_priv);
if (!primary_if)
goto dropped;
if (my_skb_head_push(skb, sizeof(struct bcast_packet)) < 0)
goto dropped;
bcast_packet = (struct bcast_packet *)skb->data;
bcast_packet->version = COMPAT_VERSION;
bcast_packet->ttl = TTL;
bcast_packet->packet_type = BAT_BCAST;
memcpy(bcast_packet->orig,
primary_if->net_dev->dev_addr, ETH_ALEN);
bcast_packet->seqno =
htonl(atomic_inc_return(&bat_priv->bcast_seqno));
add_bcast_packet_to_list(bat_priv, skb);
kfree_skb(skb);
} else {
ret = unicast_send_skb(skb, bat_priv);
if (ret != 0)
goto dropped_freed;
}
bat_priv->stats.tx_packets++;
bat_priv->stats.tx_bytes += data_len;
goto end;
dropped:
kfree_skb(skb);
dropped_freed:
bat_priv->stats.tx_dropped++;
end:
if (curr_softif_neigh)
softif_neigh_free_ref(curr_softif_neigh);
if (primary_if)
hardif_free_ref(primary_if);
return NETDEV_TX_OK;
}
void interface_rx(struct net_device *soft_iface,
struct sk_buff *skb, struct hard_iface *recv_if,
int hdr_size)
{
struct bat_priv *bat_priv = netdev_priv(soft_iface);
struct unicast_packet *unicast_packet;
struct ethhdr *ethhdr;
struct vlan_ethhdr *vhdr;
struct softif_neigh *curr_softif_neigh = NULL;
short vid = -1;
int ret;
if (!pskb_may_pull(skb, hdr_size))
goto dropped;
skb_pull_rcsum(skb, hdr_size);
skb_reset_mac_header(skb);
ethhdr = (struct ethhdr *)skb_mac_header(skb);
switch (ntohs(ethhdr->h_proto)) {
case ETH_P_8021Q:
vhdr = (struct vlan_ethhdr *)skb->data;
vid = ntohs(vhdr->h_vlan_TCI) & VLAN_VID_MASK;
if (ntohs(vhdr->h_vlan_encapsulated_proto) != ETH_P_BATMAN)
break;
case ETH_P_BATMAN:
goto dropped;
}
curr_softif_neigh = softif_neigh_vid_get_selected(bat_priv, vid);
if (curr_softif_neigh) {
skb_push(skb, hdr_size);
unicast_packet = (struct unicast_packet *)skb->data;
if ((unicast_packet->packet_type != BAT_UNICAST) &&
(unicast_packet->packet_type != BAT_UNICAST_FRAG))
goto dropped;
skb_reset_mac_header(skb);
memcpy(unicast_packet->dest,
curr_softif_neigh->addr, ETH_ALEN);
ret = route_unicast_packet(skb, recv_if);
if (ret == NET_RX_DROP)
goto dropped;
goto out;
}
if (unlikely(!pskb_may_pull(skb, ETH_HLEN)))
goto dropped;
skb->protocol = eth_type_trans(skb, soft_iface);
bat_priv->stats.rx_packets++;
bat_priv->stats.rx_bytes += skb->len + sizeof(struct ethhdr);
soft_iface->last_rx = jiffies;
netif_rx(skb);
goto out;
dropped:
kfree_skb(skb);
out:
if (curr_softif_neigh)
softif_neigh_free_ref(curr_softif_neigh);
return;
}
static void interface_setup(struct net_device *dev)
{
struct bat_priv *priv = netdev_priv(dev);
char dev_addr[ETH_ALEN];
ether_setup(dev);
#ifdef HAVE_NET_DEVICE_OPS
dev->netdev_ops = &bat_netdev_ops;
#else
dev->open = interface_open;
dev->stop = interface_release;
dev->get_stats = interface_stats;
dev->set_mac_address = interface_set_mac_addr;
dev->change_mtu = interface_change_mtu;
dev->hard_start_xmit = interface_tx;
#endif
dev->destructor = free_netdev;
dev->tx_queue_len = 0;
dev->mtu = ETH_DATA_LEN;
dev->hard_header_len = BAT_HEADER_LEN;
random_ether_addr(dev_addr);
memcpy(dev->dev_addr, dev_addr, ETH_ALEN);
SET_ETHTOOL_OPS(dev, &bat_ethtool_ops);
memset(priv, 0, sizeof(struct bat_priv));
}
struct net_device *softif_create(char *name)
{
struct net_device *soft_iface;
struct bat_priv *bat_priv;
int ret;
soft_iface = alloc_netdev(sizeof(struct bat_priv) , name,
interface_setup);
if (!soft_iface) {
pr_err("Unable to allocate the batman interface: %s\n", name);
goto out;
}
ret = register_netdevice(soft_iface);
if (ret < 0) {
pr_err("Unable to register the batman interface '%s': %i\n",
name, ret);
goto free_soft_iface;
}
bat_priv = netdev_priv(soft_iface);
atomic_set(&bat_priv->aggregated_ogms, 1);
atomic_set(&bat_priv->bonding, 0);
atomic_set(&bat_priv->vis_mode, VIS_TYPE_CLIENT_UPDATE);
atomic_set(&bat_priv->gw_mode, GW_MODE_OFF);
atomic_set(&bat_priv->gw_sel_class, 20);
atomic_set(&bat_priv->gw_bandwidth, 41);
atomic_set(&bat_priv->orig_interval, 1000);
atomic_set(&bat_priv->hop_penalty, 10);
atomic_set(&bat_priv->log_level, 0);
atomic_set(&bat_priv->fragmentation, 1);
atomic_set(&bat_priv->bcast_queue_left, BCAST_QUEUE_LEN);
atomic_set(&bat_priv->batman_queue_left, BATMAN_QUEUE_LEN);
atomic_set(&bat_priv->mesh_state, MESH_INACTIVE);
atomic_set(&bat_priv->bcast_seqno, 1);
atomic_set(&bat_priv->tt_local_changed, 0);
bat_priv->primary_if = NULL;
bat_priv->num_ifaces = 0;
ret = sysfs_add_meshif(soft_iface);
if (ret < 0)
goto unreg_soft_iface;
ret = debugfs_add_meshif(soft_iface);
if (ret < 0)
goto unreg_sysfs;
ret = mesh_init(soft_iface);
if (ret < 0)
goto unreg_debugfs;
return soft_iface;
unreg_debugfs:
debugfs_del_meshif(soft_iface);
unreg_sysfs:
sysfs_del_meshif(soft_iface);
unreg_soft_iface:
unregister_netdev(soft_iface);
return NULL;
free_soft_iface:
free_netdev(soft_iface);
out:
return NULL;
}
void softif_destroy(struct net_device *soft_iface)
{
debugfs_del_meshif(soft_iface);
sysfs_del_meshif(soft_iface);
mesh_free(soft_iface);
unregister_netdevice(soft_iface);
}
int softif_is_valid(struct net_device *net_dev)
{
#ifdef HAVE_NET_DEVICE_OPS
if (net_dev->netdev_ops->ndo_start_xmit == interface_tx)
return 1;
#else
if (net_dev->hard_start_xmit == interface_tx)
return 1;
#endif
return 0;
}
static int bat_get_settings(struct net_device *dev, struct ethtool_cmd *cmd)
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
static void bat_get_drvinfo(struct net_device *dev,
struct ethtool_drvinfo *info)
{
strcpy(info->driver, "B.A.T.M.A.N. advanced");
strcpy(info->version, SOURCE_VERSION);
strcpy(info->fw_version, "N/A");
strcpy(info->bus_info, "batman");
}
static u32 bat_get_msglevel(struct net_device *dev)
{
return -EOPNOTSUPP;
}
static void bat_set_msglevel(struct net_device *dev, u32 value)
{
}
static u32 bat_get_link(struct net_device *dev)
{
return 1;
}
