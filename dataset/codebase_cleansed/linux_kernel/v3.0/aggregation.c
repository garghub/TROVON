static int tt_len(struct batman_packet *batman_packet)
{
return batman_packet->num_tt * ETH_ALEN;
}
static bool can_aggregate_with(struct batman_packet *new_batman_packet,
int packet_len,
unsigned long send_time,
bool directlink,
struct hard_iface *if_incoming,
struct forw_packet *forw_packet)
{
struct batman_packet *batman_packet =
(struct batman_packet *)forw_packet->skb->data;
int aggregated_bytes = forw_packet->packet_len + packet_len;
if (time_before(send_time, forw_packet->send_time) &&
time_after_eq(send_time + msecs_to_jiffies(MAX_AGGREGATION_MS),
forw_packet->send_time) &&
(aggregated_bytes <= MAX_AGGREGATION_BYTES)) {
if ((!directlink) &&
(!(batman_packet->flags & DIRECTLINK)) &&
(batman_packet->ttl != 1) &&
((!forw_packet->own) ||
(forw_packet->if_incoming->if_num == 0)))
return true;
if ((directlink) &&
(new_batman_packet->ttl == 1) &&
(forw_packet->if_incoming == if_incoming) &&
(batman_packet->flags & DIRECTLINK ||
(forw_packet->own &&
forw_packet->if_incoming->if_num != 0)))
return true;
}
return false;
}
static void new_aggregated_packet(unsigned char *packet_buff, int packet_len,
unsigned long send_time, bool direct_link,
struct hard_iface *if_incoming,
int own_packet)
{
struct bat_priv *bat_priv = netdev_priv(if_incoming->soft_iface);
struct forw_packet *forw_packet_aggr;
unsigned char *skb_buff;
if (!atomic_inc_not_zero(&if_incoming->refcount))
return;
if (!own_packet) {
if (!atomic_dec_not_zero(&bat_priv->batman_queue_left)) {
bat_dbg(DBG_BATMAN, bat_priv,
"batman packet queue full\n");
goto out;
}
}
forw_packet_aggr = kmalloc(sizeof(struct forw_packet), GFP_ATOMIC);
if (!forw_packet_aggr) {
if (!own_packet)
atomic_inc(&bat_priv->batman_queue_left);
goto out;
}
if ((atomic_read(&bat_priv->aggregated_ogms)) &&
(packet_len < MAX_AGGREGATION_BYTES))
forw_packet_aggr->skb = dev_alloc_skb(MAX_AGGREGATION_BYTES +
sizeof(struct ethhdr));
else
forw_packet_aggr->skb = dev_alloc_skb(packet_len +
sizeof(struct ethhdr));
if (!forw_packet_aggr->skb) {
if (!own_packet)
atomic_inc(&bat_priv->batman_queue_left);
kfree(forw_packet_aggr);
goto out;
}
skb_reserve(forw_packet_aggr->skb, sizeof(struct ethhdr));
INIT_HLIST_NODE(&forw_packet_aggr->list);
skb_buff = skb_put(forw_packet_aggr->skb, packet_len);
forw_packet_aggr->packet_len = packet_len;
memcpy(skb_buff, packet_buff, packet_len);
forw_packet_aggr->own = own_packet;
forw_packet_aggr->if_incoming = if_incoming;
forw_packet_aggr->num_packets = 0;
forw_packet_aggr->direct_link_flags = 0;
forw_packet_aggr->send_time = send_time;
if (direct_link)
forw_packet_aggr->direct_link_flags |= 1;
spin_lock_bh(&bat_priv->forw_bat_list_lock);
hlist_add_head(&forw_packet_aggr->list, &bat_priv->forw_bat_list);
spin_unlock_bh(&bat_priv->forw_bat_list_lock);
INIT_DELAYED_WORK(&forw_packet_aggr->delayed_work,
send_outstanding_bat_packet);
queue_delayed_work(bat_event_workqueue,
&forw_packet_aggr->delayed_work,
send_time - jiffies);
return;
out:
hardif_free_ref(if_incoming);
}
static void aggregate(struct forw_packet *forw_packet_aggr,
unsigned char *packet_buff,
int packet_len,
bool direct_link)
{
unsigned char *skb_buff;
skb_buff = skb_put(forw_packet_aggr->skb, packet_len);
memcpy(skb_buff, packet_buff, packet_len);
forw_packet_aggr->packet_len += packet_len;
forw_packet_aggr->num_packets++;
if (direct_link)
forw_packet_aggr->direct_link_flags |=
(1 << forw_packet_aggr->num_packets);
}
void add_bat_packet_to_list(struct bat_priv *bat_priv,
unsigned char *packet_buff, int packet_len,
struct hard_iface *if_incoming, char own_packet,
unsigned long send_time)
{
struct forw_packet *forw_packet_aggr = NULL, *forw_packet_pos = NULL;
struct hlist_node *tmp_node;
struct batman_packet *batman_packet =
(struct batman_packet *)packet_buff;
bool direct_link = batman_packet->flags & DIRECTLINK ? 1 : 0;
spin_lock_bh(&bat_priv->forw_bat_list_lock);
if ((atomic_read(&bat_priv->aggregated_ogms)) && (!own_packet)) {
hlist_for_each_entry(forw_packet_pos, tmp_node,
&bat_priv->forw_bat_list, list) {
if (can_aggregate_with(batman_packet,
packet_len,
send_time,
direct_link,
if_incoming,
forw_packet_pos)) {
forw_packet_aggr = forw_packet_pos;
break;
}
}
}
if (!forw_packet_aggr) {
spin_unlock_bh(&bat_priv->forw_bat_list_lock);
if ((!own_packet) &&
(atomic_read(&bat_priv->aggregated_ogms)))
send_time += msecs_to_jiffies(MAX_AGGREGATION_MS);
new_aggregated_packet(packet_buff, packet_len,
send_time, direct_link,
if_incoming, own_packet);
} else {
aggregate(forw_packet_aggr,
packet_buff, packet_len,
direct_link);
spin_unlock_bh(&bat_priv->forw_bat_list_lock);
}
}
void receive_aggr_bat_packet(struct ethhdr *ethhdr, unsigned char *packet_buff,
int packet_len, struct hard_iface *if_incoming)
{
struct batman_packet *batman_packet;
int buff_pos = 0;
unsigned char *tt_buff;
batman_packet = (struct batman_packet *)packet_buff;
do {
batman_packet->seqno = ntohl(batman_packet->seqno);
tt_buff = packet_buff + buff_pos + BAT_PACKET_LEN;
receive_bat_packet(ethhdr, batman_packet,
tt_buff, tt_len(batman_packet),
if_incoming);
buff_pos += BAT_PACKET_LEN + tt_len(batman_packet);
batman_packet = (struct batman_packet *)
(packet_buff + buff_pos);
} while (aggregated_packet(buff_pos, packet_len,
batman_packet->num_tt));
}
