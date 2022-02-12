static void batadv_v_elp_start_timer(struct batadv_hard_iface *hard_iface)
{
unsigned int msecs;
msecs = atomic_read(&hard_iface->bat_v.elp_interval) - BATADV_JITTER;
msecs += prandom_u32() % (2 * BATADV_JITTER);
queue_delayed_work(batadv_event_workqueue, &hard_iface->bat_v.elp_wq,
msecs_to_jiffies(msecs));
}
static u32 batadv_v_elp_get_throughput(struct batadv_hardif_neigh_node *neigh)
{
struct batadv_hard_iface *hard_iface = neigh->if_incoming;
struct ethtool_link_ksettings link_settings;
struct net_device *real_netdev;
struct station_info sinfo;
u32 throughput;
int ret;
throughput = atomic_read(&hard_iface->bat_v.throughput_override);
if (throughput != 0)
return throughput;
if (batadv_is_wifi_hardif(hard_iface)) {
if (!batadv_is_cfg80211_hardif(hard_iface))
goto default_throughput;
real_netdev = batadv_get_real_netdev(hard_iface->net_dev);
if (!real_netdev)
goto default_throughput;
ret = cfg80211_get_station(real_netdev, neigh->addr, &sinfo);
dev_put(real_netdev);
if (ret == -ENOENT) {
return 0;
}
if (!ret)
return sinfo.expected_throughput / 100;
}
memset(&link_settings, 0, sizeof(link_settings));
rtnl_lock();
ret = __ethtool_get_link_ksettings(hard_iface->net_dev, &link_settings);
rtnl_unlock();
if (ret == 0) {
if (link_settings.base.duplex == DUPLEX_FULL)
hard_iface->bat_v.flags |= BATADV_FULL_DUPLEX;
else
hard_iface->bat_v.flags &= ~BATADV_FULL_DUPLEX;
throughput = link_settings.base.speed;
if (throughput && (throughput != SPEED_UNKNOWN))
return throughput * 10;
}
default_throughput:
if (!(hard_iface->bat_v.flags & BATADV_WARNING_DEFAULT)) {
batadv_info(hard_iface->soft_iface,
"WiFi driver or ethtool info does not provide information about link speeds on interface %s, therefore defaulting to hardcoded throughput values of %u.%1u Mbps. Consider overriding the throughput manually or checking your driver.\n",
hard_iface->net_dev->name,
BATADV_THROUGHPUT_DEFAULT_VALUE / 10,
BATADV_THROUGHPUT_DEFAULT_VALUE % 10);
hard_iface->bat_v.flags |= BATADV_WARNING_DEFAULT;
}
return BATADV_THROUGHPUT_DEFAULT_VALUE;
}
void batadv_v_elp_throughput_metric_update(struct work_struct *work)
{
struct batadv_hardif_neigh_node_bat_v *neigh_bat_v;
struct batadv_hardif_neigh_node *neigh;
neigh_bat_v = container_of(work, struct batadv_hardif_neigh_node_bat_v,
metric_work);
neigh = container_of(neigh_bat_v, struct batadv_hardif_neigh_node,
bat_v);
ewma_throughput_add(&neigh->bat_v.throughput,
batadv_v_elp_get_throughput(neigh));
batadv_hardif_neigh_put(neigh);
}
static bool
batadv_v_elp_wifi_neigh_probe(struct batadv_hardif_neigh_node *neigh)
{
struct batadv_hard_iface *hard_iface = neigh->if_incoming;
struct batadv_priv *bat_priv = netdev_priv(hard_iface->soft_iface);
unsigned long last_tx_diff;
struct sk_buff *skb;
int probe_len, i;
int elp_skb_len;
if (!batadv_is_wifi_hardif(hard_iface))
return true;
last_tx_diff = jiffies_to_msecs(jiffies - neigh->bat_v.last_unicast_tx);
if (last_tx_diff <= BATADV_ELP_PROBE_MAX_TX_DIFF)
return true;
probe_len = max_t(int, sizeof(struct batadv_elp_packet),
BATADV_ELP_MIN_PROBE_SIZE);
for (i = 0; i < BATADV_ELP_PROBES_PER_NODE; i++) {
elp_skb_len = hard_iface->bat_v.elp_skb->len;
skb = skb_copy_expand(hard_iface->bat_v.elp_skb, 0,
probe_len - elp_skb_len,
GFP_ATOMIC);
if (!skb)
return false;
skb_put(skb, probe_len - hard_iface->bat_v.elp_skb->len);
batadv_dbg(BATADV_DBG_BATMAN, bat_priv,
"Sending unicast (probe) ELP packet on interface %s to %pM\n",
hard_iface->net_dev->name, neigh->addr);
batadv_send_skb_packet(skb, hard_iface, neigh->addr);
}
return true;
}
static void batadv_v_elp_periodic_work(struct work_struct *work)
{
struct batadv_hardif_neigh_node *hardif_neigh;
struct batadv_hard_iface *hard_iface;
struct batadv_hard_iface_bat_v *bat_v;
struct batadv_elp_packet *elp_packet;
struct batadv_priv *bat_priv;
struct sk_buff *skb;
u32 elp_interval;
bat_v = container_of(work, struct batadv_hard_iface_bat_v, elp_wq.work);
hard_iface = container_of(bat_v, struct batadv_hard_iface, bat_v);
bat_priv = netdev_priv(hard_iface->soft_iface);
if (atomic_read(&bat_priv->mesh_state) == BATADV_MESH_DEACTIVATING)
goto out;
if ((hard_iface->if_status == BATADV_IF_NOT_IN_USE) ||
(hard_iface->if_status == BATADV_IF_TO_BE_REMOVED))
goto out;
if (hard_iface->if_status != BATADV_IF_ACTIVE)
goto restart_timer;
skb = skb_copy(hard_iface->bat_v.elp_skb, GFP_ATOMIC);
if (!skb)
goto restart_timer;
elp_packet = (struct batadv_elp_packet *)skb->data;
elp_packet->seqno = htonl(atomic_read(&hard_iface->bat_v.elp_seqno));
elp_interval = atomic_read(&hard_iface->bat_v.elp_interval);
elp_packet->elp_interval = htonl(elp_interval);
batadv_dbg(BATADV_DBG_BATMAN, bat_priv,
"Sending broadcast ELP packet on interface %s, seqno %u\n",
hard_iface->net_dev->name,
atomic_read(&hard_iface->bat_v.elp_seqno));
batadv_send_broadcast_skb(skb, hard_iface);
atomic_inc(&hard_iface->bat_v.elp_seqno);
rcu_read_lock();
hlist_for_each_entry_rcu(hardif_neigh, &hard_iface->neigh_list, list) {
if (!batadv_v_elp_wifi_neigh_probe(hardif_neigh))
break;
if (!kref_get_unless_zero(&hardif_neigh->refcount))
continue;
queue_work(batadv_event_workqueue,
&hardif_neigh->bat_v.metric_work);
}
rcu_read_unlock();
restart_timer:
batadv_v_elp_start_timer(hard_iface);
out:
return;
}
int batadv_v_elp_iface_enable(struct batadv_hard_iface *hard_iface)
{
struct batadv_elp_packet *elp_packet;
unsigned char *elp_buff;
u32 random_seqno;
size_t size;
int res = -ENOMEM;
size = ETH_HLEN + NET_IP_ALIGN + BATADV_ELP_HLEN;
hard_iface->bat_v.elp_skb = dev_alloc_skb(size);
if (!hard_iface->bat_v.elp_skb)
goto out;
skb_reserve(hard_iface->bat_v.elp_skb, ETH_HLEN + NET_IP_ALIGN);
elp_buff = skb_put(hard_iface->bat_v.elp_skb, BATADV_ELP_HLEN);
elp_packet = (struct batadv_elp_packet *)elp_buff;
memset(elp_packet, 0, BATADV_ELP_HLEN);
elp_packet->packet_type = BATADV_ELP;
elp_packet->version = BATADV_COMPAT_VERSION;
get_random_bytes(&random_seqno, sizeof(random_seqno));
atomic_set(&hard_iface->bat_v.elp_seqno, random_seqno);
hard_iface->bat_v.flags |= BATADV_FULL_DUPLEX;
hard_iface->bat_v.flags &= ~BATADV_WARNING_DEFAULT;
if (batadv_is_wifi_hardif(hard_iface))
hard_iface->bat_v.flags &= ~BATADV_FULL_DUPLEX;
INIT_DELAYED_WORK(&hard_iface->bat_v.elp_wq,
batadv_v_elp_periodic_work);
batadv_v_elp_start_timer(hard_iface);
res = 0;
out:
return res;
}
void batadv_v_elp_iface_disable(struct batadv_hard_iface *hard_iface)
{
cancel_delayed_work_sync(&hard_iface->bat_v.elp_wq);
dev_kfree_skb(hard_iface->bat_v.elp_skb);
hard_iface->bat_v.elp_skb = NULL;
}
void batadv_v_elp_iface_activate(struct batadv_hard_iface *primary_iface,
struct batadv_hard_iface *hard_iface)
{
struct batadv_elp_packet *elp_packet;
struct sk_buff *skb;
if (!hard_iface->bat_v.elp_skb)
return;
skb = hard_iface->bat_v.elp_skb;
elp_packet = (struct batadv_elp_packet *)skb->data;
ether_addr_copy(elp_packet->orig,
primary_iface->net_dev->dev_addr);
}
void batadv_v_elp_primary_iface_set(struct batadv_hard_iface *primary_iface)
{
struct batadv_hard_iface *hard_iface;
rcu_read_lock();
list_for_each_entry_rcu(hard_iface, &batadv_hardif_list, list) {
if (primary_iface->soft_iface != hard_iface->soft_iface)
continue;
batadv_v_elp_iface_activate(primary_iface, hard_iface);
}
rcu_read_unlock();
}
static void batadv_v_elp_neigh_update(struct batadv_priv *bat_priv,
u8 *neigh_addr,
struct batadv_hard_iface *if_incoming,
struct batadv_elp_packet *elp_packet)
{
struct batadv_neigh_node *neigh;
struct batadv_orig_node *orig_neigh;
struct batadv_hardif_neigh_node *hardif_neigh;
s32 seqno_diff;
s32 elp_latest_seqno;
orig_neigh = batadv_v_ogm_orig_get(bat_priv, elp_packet->orig);
if (!orig_neigh)
return;
neigh = batadv_neigh_node_get_or_create(orig_neigh,
if_incoming, neigh_addr);
if (!neigh)
goto orig_free;
hardif_neigh = batadv_hardif_neigh_get(if_incoming, neigh_addr);
if (!hardif_neigh)
goto neigh_free;
elp_latest_seqno = hardif_neigh->bat_v.elp_latest_seqno;
seqno_diff = ntohl(elp_packet->seqno) - elp_latest_seqno;
if (seqno_diff < 1 && seqno_diff > -BATADV_ELP_MAX_AGE)
goto hardif_free;
neigh->last_seen = jiffies;
hardif_neigh->last_seen = jiffies;
hardif_neigh->bat_v.elp_latest_seqno = ntohl(elp_packet->seqno);
hardif_neigh->bat_v.elp_interval = ntohl(elp_packet->elp_interval);
hardif_free:
if (hardif_neigh)
batadv_hardif_neigh_put(hardif_neigh);
neigh_free:
if (neigh)
batadv_neigh_node_put(neigh);
orig_free:
if (orig_neigh)
batadv_orig_node_put(orig_neigh);
}
int batadv_v_elp_packet_recv(struct sk_buff *skb,
struct batadv_hard_iface *if_incoming)
{
struct batadv_priv *bat_priv = netdev_priv(if_incoming->soft_iface);
struct batadv_elp_packet *elp_packet;
struct batadv_hard_iface *primary_if;
struct ethhdr *ethhdr = (struct ethhdr *)skb_mac_header(skb);
bool res;
int ret = NET_RX_DROP;
res = batadv_check_management_packet(skb, if_incoming, BATADV_ELP_HLEN);
if (!res)
goto free_skb;
if (batadv_is_my_mac(bat_priv, ethhdr->h_source))
goto free_skb;
if (strcmp(bat_priv->algo_ops->name, "BATMAN_V") != 0)
goto free_skb;
elp_packet = (struct batadv_elp_packet *)skb->data;
batadv_dbg(BATADV_DBG_BATMAN, bat_priv,
"Received ELP packet from %pM seqno %u ORIG: %pM\n",
ethhdr->h_source, ntohl(elp_packet->seqno),
elp_packet->orig);
primary_if = batadv_primary_if_get_selected(bat_priv);
if (!primary_if)
goto free_skb;
batadv_v_elp_neigh_update(bat_priv, ethhdr->h_source, if_incoming,
elp_packet);
ret = NET_RX_SUCCESS;
batadv_hardif_put(primary_if);
free_skb:
if (ret == NET_RX_SUCCESS)
consume_skb(skb);
else
kfree_skb(skb);
return ret;
}
