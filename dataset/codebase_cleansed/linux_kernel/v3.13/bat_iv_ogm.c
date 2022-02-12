static void batadv_ring_buffer_set(uint8_t lq_recv[], uint8_t *lq_index,
uint8_t value)
{
lq_recv[*lq_index] = value;
*lq_index = (*lq_index + 1) % BATADV_TQ_GLOBAL_WINDOW_SIZE;
}
static uint8_t batadv_ring_buffer_avg(const uint8_t lq_recv[])
{
const uint8_t *ptr;
uint16_t count = 0, i = 0, sum = 0;
ptr = lq_recv;
while (i < BATADV_TQ_GLOBAL_WINDOW_SIZE) {
if (*ptr != 0) {
count++;
sum += *ptr;
}
i++;
ptr++;
}
if (count == 0)
return 0;
return (uint8_t)(sum / count);
}
static void batadv_iv_ogm_orig_free(struct batadv_orig_node *orig_node)
{
kfree(orig_node->bat_iv.bcast_own);
kfree(orig_node->bat_iv.bcast_own_sum);
}
static int batadv_iv_ogm_orig_add_if(struct batadv_orig_node *orig_node,
int max_if_num)
{
void *data_ptr;
size_t data_size, old_size;
int ret = -ENOMEM;
spin_lock_bh(&orig_node->bat_iv.ogm_cnt_lock);
data_size = max_if_num * sizeof(unsigned long) * BATADV_NUM_WORDS;
old_size = (max_if_num - 1) * sizeof(unsigned long) * BATADV_NUM_WORDS;
data_ptr = kmalloc(data_size, GFP_ATOMIC);
if (!data_ptr)
goto unlock;
memcpy(data_ptr, orig_node->bat_iv.bcast_own, old_size);
kfree(orig_node->bat_iv.bcast_own);
orig_node->bat_iv.bcast_own = data_ptr;
data_ptr = kmalloc(max_if_num * sizeof(uint8_t), GFP_ATOMIC);
if (!data_ptr) {
kfree(orig_node->bat_iv.bcast_own);
goto unlock;
}
memcpy(data_ptr, orig_node->bat_iv.bcast_own_sum,
(max_if_num - 1) * sizeof(uint8_t));
kfree(orig_node->bat_iv.bcast_own_sum);
orig_node->bat_iv.bcast_own_sum = data_ptr;
ret = 0;
unlock:
spin_unlock_bh(&orig_node->bat_iv.ogm_cnt_lock);
return ret;
}
static int batadv_iv_ogm_orig_del_if(struct batadv_orig_node *orig_node,
int max_if_num, int del_if_num)
{
int chunk_size, ret = -ENOMEM, if_offset;
void *data_ptr = NULL;
spin_lock_bh(&orig_node->bat_iv.ogm_cnt_lock);
if (max_if_num == 0)
goto free_bcast_own;
chunk_size = sizeof(unsigned long) * BATADV_NUM_WORDS;
data_ptr = kmalloc(max_if_num * chunk_size, GFP_ATOMIC);
if (!data_ptr)
goto unlock;
memcpy(data_ptr, orig_node->bat_iv.bcast_own, del_if_num * chunk_size);
memcpy((char *)data_ptr + del_if_num * chunk_size,
orig_node->bat_iv.bcast_own + ((del_if_num + 1) * chunk_size),
(max_if_num - del_if_num) * chunk_size);
free_bcast_own:
kfree(orig_node->bat_iv.bcast_own);
orig_node->bat_iv.bcast_own = data_ptr;
if (max_if_num == 0)
goto free_own_sum;
data_ptr = kmalloc(max_if_num * sizeof(uint8_t), GFP_ATOMIC);
if (!data_ptr) {
kfree(orig_node->bat_iv.bcast_own);
goto unlock;
}
memcpy(data_ptr, orig_node->bat_iv.bcast_own_sum,
del_if_num * sizeof(uint8_t));
if_offset = (del_if_num + 1) * sizeof(uint8_t);
memcpy((char *)data_ptr + del_if_num * sizeof(uint8_t),
orig_node->bat_iv.bcast_own_sum + if_offset,
(max_if_num - del_if_num) * sizeof(uint8_t));
free_own_sum:
kfree(orig_node->bat_iv.bcast_own_sum);
orig_node->bat_iv.bcast_own_sum = data_ptr;
ret = 0;
unlock:
spin_unlock_bh(&orig_node->bat_iv.ogm_cnt_lock);
return ret;
}
static struct batadv_orig_node *
batadv_iv_ogm_orig_get(struct batadv_priv *bat_priv, const uint8_t *addr)
{
struct batadv_orig_node *orig_node;
int size, hash_added;
orig_node = batadv_orig_hash_find(bat_priv, addr);
if (orig_node)
return orig_node;
orig_node = batadv_orig_node_new(bat_priv, addr);
if (!orig_node)
return NULL;
spin_lock_init(&orig_node->bat_iv.ogm_cnt_lock);
size = bat_priv->num_ifaces * sizeof(unsigned long) * BATADV_NUM_WORDS;
orig_node->bat_iv.bcast_own = kzalloc(size, GFP_ATOMIC);
if (!orig_node->bat_iv.bcast_own)
goto free_orig_node;
size = bat_priv->num_ifaces * sizeof(uint8_t);
orig_node->bat_iv.bcast_own_sum = kzalloc(size, GFP_ATOMIC);
if (!orig_node->bat_iv.bcast_own_sum)
goto free_bcast_own;
hash_added = batadv_hash_add(bat_priv->orig_hash, batadv_compare_orig,
batadv_choose_orig, orig_node,
&orig_node->hash_entry);
if (hash_added != 0)
goto free_bcast_own;
return orig_node;
free_bcast_own:
kfree(orig_node->bat_iv.bcast_own);
free_orig_node:
batadv_orig_node_free_ref(orig_node);
return NULL;
}
static struct batadv_neigh_node *
batadv_iv_ogm_neigh_new(struct batadv_hard_iface *hard_iface,
const uint8_t *neigh_addr,
struct batadv_orig_node *orig_node,
struct batadv_orig_node *orig_neigh)
{
struct batadv_priv *bat_priv = netdev_priv(hard_iface->soft_iface);
struct batadv_neigh_node *neigh_node;
neigh_node = batadv_neigh_node_new(hard_iface, neigh_addr, orig_node);
if (!neigh_node)
goto out;
spin_lock_init(&neigh_node->bat_iv.lq_update_lock);
batadv_dbg(BATADV_DBG_BATMAN, bat_priv,
"Creating new neighbor %pM for orig_node %pM on interface %s\n",
neigh_addr, orig_node->orig, hard_iface->net_dev->name);
spin_lock_bh(&orig_node->neigh_list_lock);
hlist_add_head_rcu(&neigh_node->list, &orig_node->neigh_list);
spin_unlock_bh(&orig_node->neigh_list_lock);
out:
return neigh_node;
}
static int batadv_iv_ogm_iface_enable(struct batadv_hard_iface *hard_iface)
{
struct batadv_ogm_packet *batadv_ogm_packet;
unsigned char *ogm_buff;
uint32_t random_seqno;
int res = -ENOMEM;
get_random_bytes(&random_seqno, sizeof(random_seqno));
atomic_set(&hard_iface->bat_iv.ogm_seqno, random_seqno);
hard_iface->bat_iv.ogm_buff_len = BATADV_OGM_HLEN;
ogm_buff = kmalloc(hard_iface->bat_iv.ogm_buff_len, GFP_ATOMIC);
if (!ogm_buff)
goto out;
hard_iface->bat_iv.ogm_buff = ogm_buff;
batadv_ogm_packet = (struct batadv_ogm_packet *)ogm_buff;
batadv_ogm_packet->packet_type = BATADV_IV_OGM;
batadv_ogm_packet->version = BATADV_COMPAT_VERSION;
batadv_ogm_packet->ttl = 2;
batadv_ogm_packet->flags = BATADV_NO_FLAGS;
batadv_ogm_packet->reserved = 0;
batadv_ogm_packet->tq = BATADV_TQ_MAX_VALUE;
res = 0;
out:
return res;
}
static void batadv_iv_ogm_iface_disable(struct batadv_hard_iface *hard_iface)
{
kfree(hard_iface->bat_iv.ogm_buff);
hard_iface->bat_iv.ogm_buff = NULL;
}
static void batadv_iv_ogm_iface_update_mac(struct batadv_hard_iface *hard_iface)
{
struct batadv_ogm_packet *batadv_ogm_packet;
unsigned char *ogm_buff = hard_iface->bat_iv.ogm_buff;
batadv_ogm_packet = (struct batadv_ogm_packet *)ogm_buff;
memcpy(batadv_ogm_packet->orig,
hard_iface->net_dev->dev_addr, ETH_ALEN);
memcpy(batadv_ogm_packet->prev_sender,
hard_iface->net_dev->dev_addr, ETH_ALEN);
}
static void
batadv_iv_ogm_primary_iface_set(struct batadv_hard_iface *hard_iface)
{
struct batadv_ogm_packet *batadv_ogm_packet;
unsigned char *ogm_buff = hard_iface->bat_iv.ogm_buff;
batadv_ogm_packet = (struct batadv_ogm_packet *)ogm_buff;
batadv_ogm_packet->flags = BATADV_PRIMARIES_FIRST_HOP;
batadv_ogm_packet->ttl = BATADV_TTL;
}
static unsigned long
batadv_iv_ogm_emit_send_time(const struct batadv_priv *bat_priv)
{
unsigned int msecs;
msecs = atomic_read(&bat_priv->orig_interval) - BATADV_JITTER;
msecs += prandom_u32() % (2 * BATADV_JITTER);
return jiffies + msecs_to_jiffies(msecs);
}
static unsigned long batadv_iv_ogm_fwd_send_time(void)
{
return jiffies + msecs_to_jiffies(prandom_u32() % (BATADV_JITTER / 2));
}
static uint8_t batadv_hop_penalty(uint8_t tq,
const struct batadv_priv *bat_priv)
{
int hop_penalty = atomic_read(&bat_priv->hop_penalty);
int new_tq;
new_tq = tq * (BATADV_TQ_MAX_VALUE - hop_penalty);
new_tq /= BATADV_TQ_MAX_VALUE;
return new_tq;
}
static int batadv_iv_ogm_aggr_packet(int buff_pos, int packet_len,
__be16 tvlv_len)
{
int next_buff_pos = 0;
next_buff_pos += buff_pos + BATADV_OGM_HLEN;
next_buff_pos += ntohs(tvlv_len);
return (next_buff_pos <= packet_len) &&
(next_buff_pos <= BATADV_MAX_AGGREGATION_BYTES);
}
static void batadv_iv_ogm_send_to_if(struct batadv_forw_packet *forw_packet,
struct batadv_hard_iface *hard_iface)
{
struct batadv_priv *bat_priv = netdev_priv(hard_iface->soft_iface);
char *fwd_str;
uint8_t packet_num;
int16_t buff_pos;
struct batadv_ogm_packet *batadv_ogm_packet;
struct sk_buff *skb;
uint8_t *packet_pos;
if (hard_iface->if_status != BATADV_IF_ACTIVE)
return;
packet_num = 0;
buff_pos = 0;
packet_pos = forw_packet->skb->data;
batadv_ogm_packet = (struct batadv_ogm_packet *)packet_pos;
while (batadv_iv_ogm_aggr_packet(buff_pos, forw_packet->packet_len,
batadv_ogm_packet->tvlv_len)) {
if (forw_packet->direct_link_flags & BIT(packet_num) &&
forw_packet->if_incoming == hard_iface)
batadv_ogm_packet->flags |= BATADV_DIRECTLINK;
else
batadv_ogm_packet->flags &= ~BATADV_DIRECTLINK;
if (packet_num > 0 || !forw_packet->own)
fwd_str = "Forwarding";
else
fwd_str = "Sending own";
batadv_dbg(BATADV_DBG_BATMAN, bat_priv,
"%s %spacket (originator %pM, seqno %u, TQ %d, TTL %d, IDF %s) on interface %s [%pM]\n",
fwd_str, (packet_num > 0 ? "aggregated " : ""),
batadv_ogm_packet->orig,
ntohl(batadv_ogm_packet->seqno),
batadv_ogm_packet->tq, batadv_ogm_packet->ttl,
(batadv_ogm_packet->flags & BATADV_DIRECTLINK ?
"on" : "off"),
hard_iface->net_dev->name,
hard_iface->net_dev->dev_addr);
buff_pos += BATADV_OGM_HLEN;
buff_pos += ntohs(batadv_ogm_packet->tvlv_len);
packet_num++;
packet_pos = forw_packet->skb->data + buff_pos;
batadv_ogm_packet = (struct batadv_ogm_packet *)packet_pos;
}
skb = skb_clone(forw_packet->skb, GFP_ATOMIC);
if (skb) {
batadv_inc_counter(bat_priv, BATADV_CNT_MGMT_TX);
batadv_add_counter(bat_priv, BATADV_CNT_MGMT_TX_BYTES,
skb->len + ETH_HLEN);
batadv_send_skb_packet(skb, hard_iface, batadv_broadcast_addr);
}
}
static void batadv_iv_ogm_emit(struct batadv_forw_packet *forw_packet)
{
struct batadv_hard_iface *hard_iface;
struct net_device *soft_iface;
struct batadv_priv *bat_priv;
struct batadv_hard_iface *primary_if = NULL;
struct batadv_ogm_packet *batadv_ogm_packet;
unsigned char directlink;
uint8_t *packet_pos;
packet_pos = forw_packet->skb->data;
batadv_ogm_packet = (struct batadv_ogm_packet *)packet_pos;
directlink = (batadv_ogm_packet->flags & BATADV_DIRECTLINK ? 1 : 0);
if (!forw_packet->if_incoming) {
pr_err("Error - can't forward packet: incoming iface not specified\n");
goto out;
}
soft_iface = forw_packet->if_incoming->soft_iface;
bat_priv = netdev_priv(soft_iface);
if (forw_packet->if_incoming->if_status != BATADV_IF_ACTIVE)
goto out;
primary_if = batadv_primary_if_get_selected(bat_priv);
if (!primary_if)
goto out;
if ((directlink && (batadv_ogm_packet->ttl == 1)) ||
(forw_packet->own && (forw_packet->if_incoming != primary_if))) {
batadv_dbg(BATADV_DBG_BATMAN, bat_priv,
"%s packet (originator %pM, seqno %u, TTL %d) on interface %s [%pM]\n",
(forw_packet->own ? "Sending own" : "Forwarding"),
batadv_ogm_packet->orig,
ntohl(batadv_ogm_packet->seqno),
batadv_ogm_packet->ttl,
forw_packet->if_incoming->net_dev->name,
forw_packet->if_incoming->net_dev->dev_addr);
batadv_send_skb_packet(forw_packet->skb,
forw_packet->if_incoming,
batadv_broadcast_addr);
forw_packet->skb = NULL;
goto out;
}
rcu_read_lock();
list_for_each_entry_rcu(hard_iface, &batadv_hardif_list, list) {
if (hard_iface->soft_iface != soft_iface)
continue;
batadv_iv_ogm_send_to_if(forw_packet, hard_iface);
}
rcu_read_unlock();
out:
if (primary_if)
batadv_hardif_free_ref(primary_if);
}
static bool
batadv_iv_ogm_can_aggregate(const struct batadv_ogm_packet *new_bat_ogm_packet,
struct batadv_priv *bat_priv,
int packet_len, unsigned long send_time,
bool directlink,
const struct batadv_hard_iface *if_incoming,
const struct batadv_forw_packet *forw_packet)
{
struct batadv_ogm_packet *batadv_ogm_packet;
int aggregated_bytes = forw_packet->packet_len + packet_len;
struct batadv_hard_iface *primary_if = NULL;
bool res = false;
unsigned long aggregation_end_time;
batadv_ogm_packet = (struct batadv_ogm_packet *)forw_packet->skb->data;
aggregation_end_time = send_time;
aggregation_end_time += msecs_to_jiffies(BATADV_MAX_AGGREGATION_MS);
if (time_before(send_time, forw_packet->send_time) &&
time_after_eq(aggregation_end_time, forw_packet->send_time) &&
(aggregated_bytes <= BATADV_MAX_AGGREGATION_BYTES)) {
primary_if = batadv_primary_if_get_selected(bat_priv);
if (!primary_if)
goto out;
if ((!directlink) &&
(!(batadv_ogm_packet->flags & BATADV_DIRECTLINK)) &&
(batadv_ogm_packet->ttl != 1) &&
((!forw_packet->own) ||
(forw_packet->if_incoming == primary_if))) {
res = true;
goto out;
}
if ((directlink) &&
(new_bat_ogm_packet->ttl == 1) &&
(forw_packet->if_incoming == if_incoming) &&
(batadv_ogm_packet->flags & BATADV_DIRECTLINK ||
(forw_packet->own &&
forw_packet->if_incoming != primary_if))) {
res = true;
goto out;
}
}
out:
if (primary_if)
batadv_hardif_free_ref(primary_if);
return res;
}
static void batadv_iv_ogm_aggregate_new(const unsigned char *packet_buff,
int packet_len, unsigned long send_time,
bool direct_link,
struct batadv_hard_iface *if_incoming,
int own_packet)
{
struct batadv_priv *bat_priv = netdev_priv(if_incoming->soft_iface);
struct batadv_forw_packet *forw_packet_aggr;
unsigned char *skb_buff;
unsigned int skb_size;
if (!atomic_inc_not_zero(&if_incoming->refcount))
return;
if (!own_packet) {
if (!batadv_atomic_dec_not_zero(&bat_priv->batman_queue_left)) {
batadv_dbg(BATADV_DBG_BATMAN, bat_priv,
"batman packet queue full\n");
goto out;
}
}
forw_packet_aggr = kmalloc(sizeof(*forw_packet_aggr), GFP_ATOMIC);
if (!forw_packet_aggr) {
if (!own_packet)
atomic_inc(&bat_priv->batman_queue_left);
goto out;
}
if ((atomic_read(&bat_priv->aggregated_ogms)) &&
(packet_len < BATADV_MAX_AGGREGATION_BYTES))
skb_size = BATADV_MAX_AGGREGATION_BYTES;
else
skb_size = packet_len;
skb_size += ETH_HLEN;
forw_packet_aggr->skb = netdev_alloc_skb_ip_align(NULL, skb_size);
if (!forw_packet_aggr->skb) {
if (!own_packet)
atomic_inc(&bat_priv->batman_queue_left);
kfree(forw_packet_aggr);
goto out;
}
forw_packet_aggr->skb->priority = TC_PRIO_CONTROL;
skb_reserve(forw_packet_aggr->skb, ETH_HLEN);
skb_buff = skb_put(forw_packet_aggr->skb, packet_len);
forw_packet_aggr->packet_len = packet_len;
memcpy(skb_buff, packet_buff, packet_len);
forw_packet_aggr->own = own_packet;
forw_packet_aggr->if_incoming = if_incoming;
forw_packet_aggr->num_packets = 0;
forw_packet_aggr->direct_link_flags = BATADV_NO_FLAGS;
forw_packet_aggr->send_time = send_time;
if (direct_link)
forw_packet_aggr->direct_link_flags |= 1;
spin_lock_bh(&bat_priv->forw_bat_list_lock);
hlist_add_head(&forw_packet_aggr->list, &bat_priv->forw_bat_list);
spin_unlock_bh(&bat_priv->forw_bat_list_lock);
INIT_DELAYED_WORK(&forw_packet_aggr->delayed_work,
batadv_send_outstanding_bat_ogm_packet);
queue_delayed_work(batadv_event_workqueue,
&forw_packet_aggr->delayed_work,
send_time - jiffies);
return;
out:
batadv_hardif_free_ref(if_incoming);
}
static void batadv_iv_ogm_aggregate(struct batadv_forw_packet *forw_packet_aggr,
const unsigned char *packet_buff,
int packet_len, bool direct_link)
{
unsigned char *skb_buff;
unsigned long new_direct_link_flag;
skb_buff = skb_put(forw_packet_aggr->skb, packet_len);
memcpy(skb_buff, packet_buff, packet_len);
forw_packet_aggr->packet_len += packet_len;
forw_packet_aggr->num_packets++;
if (direct_link) {
new_direct_link_flag = BIT(forw_packet_aggr->num_packets);
forw_packet_aggr->direct_link_flags |= new_direct_link_flag;
}
}
static void batadv_iv_ogm_queue_add(struct batadv_priv *bat_priv,
unsigned char *packet_buff,
int packet_len,
struct batadv_hard_iface *if_incoming,
int own_packet, unsigned long send_time)
{
struct batadv_forw_packet *forw_packet_aggr = NULL;
struct batadv_forw_packet *forw_packet_pos = NULL;
struct batadv_ogm_packet *batadv_ogm_packet;
bool direct_link;
unsigned long max_aggregation_jiffies;
batadv_ogm_packet = (struct batadv_ogm_packet *)packet_buff;
direct_link = batadv_ogm_packet->flags & BATADV_DIRECTLINK ? 1 : 0;
max_aggregation_jiffies = msecs_to_jiffies(BATADV_MAX_AGGREGATION_MS);
spin_lock_bh(&bat_priv->forw_bat_list_lock);
if ((atomic_read(&bat_priv->aggregated_ogms)) && (!own_packet)) {
hlist_for_each_entry(forw_packet_pos,
&bat_priv->forw_bat_list, list) {
if (batadv_iv_ogm_can_aggregate(batadv_ogm_packet,
bat_priv, packet_len,
send_time, direct_link,
if_incoming,
forw_packet_pos)) {
forw_packet_aggr = forw_packet_pos;
break;
}
}
}
if (!forw_packet_aggr) {
spin_unlock_bh(&bat_priv->forw_bat_list_lock);
if (!own_packet && atomic_read(&bat_priv->aggregated_ogms))
send_time += max_aggregation_jiffies;
batadv_iv_ogm_aggregate_new(packet_buff, packet_len,
send_time, direct_link,
if_incoming, own_packet);
} else {
batadv_iv_ogm_aggregate(forw_packet_aggr, packet_buff,
packet_len, direct_link);
spin_unlock_bh(&bat_priv->forw_bat_list_lock);
}
}
static void batadv_iv_ogm_forward(struct batadv_orig_node *orig_node,
const struct ethhdr *ethhdr,
struct batadv_ogm_packet *batadv_ogm_packet,
bool is_single_hop_neigh,
bool is_from_best_next_hop,
struct batadv_hard_iface *if_incoming)
{
struct batadv_priv *bat_priv = netdev_priv(if_incoming->soft_iface);
uint16_t tvlv_len;
if (batadv_ogm_packet->ttl <= 1) {
batadv_dbg(BATADV_DBG_BATMAN, bat_priv, "ttl exceeded\n");
return;
}
if (!is_from_best_next_hop) {
if (is_single_hop_neigh)
batadv_ogm_packet->flags |= BATADV_NOT_BEST_NEXT_HOP;
else
return;
}
tvlv_len = ntohs(batadv_ogm_packet->tvlv_len);
batadv_ogm_packet->ttl--;
memcpy(batadv_ogm_packet->prev_sender, ethhdr->h_source, ETH_ALEN);
batadv_ogm_packet->tq = batadv_hop_penalty(batadv_ogm_packet->tq,
bat_priv);
batadv_dbg(BATADV_DBG_BATMAN, bat_priv,
"Forwarding packet: tq: %i, ttl: %i\n",
batadv_ogm_packet->tq, batadv_ogm_packet->ttl);
batadv_ogm_packet->flags &= ~BATADV_PRIMARIES_FIRST_HOP;
if (is_single_hop_neigh)
batadv_ogm_packet->flags |= BATADV_DIRECTLINK;
else
batadv_ogm_packet->flags &= ~BATADV_DIRECTLINK;
batadv_iv_ogm_queue_add(bat_priv, (unsigned char *)batadv_ogm_packet,
BATADV_OGM_HLEN + tvlv_len,
if_incoming, 0, batadv_iv_ogm_fwd_send_time());
}
static void
batadv_iv_ogm_slide_own_bcast_window(struct batadv_hard_iface *hard_iface)
{
struct batadv_priv *bat_priv = netdev_priv(hard_iface->soft_iface);
struct batadv_hashtable *hash = bat_priv->orig_hash;
struct hlist_head *head;
struct batadv_orig_node *orig_node;
unsigned long *word;
uint32_t i;
size_t word_index;
uint8_t *w;
int if_num;
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
rcu_read_lock();
hlist_for_each_entry_rcu(orig_node, head, hash_entry) {
spin_lock_bh(&orig_node->bat_iv.ogm_cnt_lock);
word_index = hard_iface->if_num * BATADV_NUM_WORDS;
word = &(orig_node->bat_iv.bcast_own[word_index]);
batadv_bit_get_packet(bat_priv, word, 1, 0);
if_num = hard_iface->if_num;
w = &orig_node->bat_iv.bcast_own_sum[if_num];
*w = bitmap_weight(word, BATADV_TQ_LOCAL_WINDOW_SIZE);
spin_unlock_bh(&orig_node->bat_iv.ogm_cnt_lock);
}
rcu_read_unlock();
}
}
static void batadv_iv_ogm_schedule(struct batadv_hard_iface *hard_iface)
{
struct batadv_priv *bat_priv = netdev_priv(hard_iface->soft_iface);
unsigned char **ogm_buff = &hard_iface->bat_iv.ogm_buff;
struct batadv_ogm_packet *batadv_ogm_packet;
struct batadv_hard_iface *primary_if;
int *ogm_buff_len = &hard_iface->bat_iv.ogm_buff_len;
uint32_t seqno;
uint16_t tvlv_len = 0;
primary_if = batadv_primary_if_get_selected(bat_priv);
if (hard_iface == primary_if) {
batadv_tt_local_commit_changes(bat_priv);
tvlv_len = batadv_tvlv_container_ogm_append(bat_priv, ogm_buff,
ogm_buff_len,
BATADV_OGM_HLEN);
}
batadv_ogm_packet = (struct batadv_ogm_packet *)(*ogm_buff);
batadv_ogm_packet->tvlv_len = htons(tvlv_len);
seqno = (uint32_t)atomic_read(&hard_iface->bat_iv.ogm_seqno);
batadv_ogm_packet->seqno = htonl(seqno);
atomic_inc(&hard_iface->bat_iv.ogm_seqno);
batadv_iv_ogm_slide_own_bcast_window(hard_iface);
batadv_iv_ogm_queue_add(bat_priv, hard_iface->bat_iv.ogm_buff,
hard_iface->bat_iv.ogm_buff_len, hard_iface, 1,
batadv_iv_ogm_emit_send_time(bat_priv));
if (primary_if)
batadv_hardif_free_ref(primary_if);
}
static void
batadv_iv_ogm_orig_update(struct batadv_priv *bat_priv,
struct batadv_orig_node *orig_node,
const struct ethhdr *ethhdr,
const struct batadv_ogm_packet *batadv_ogm_packet,
struct batadv_hard_iface *if_incoming,
const unsigned char *tt_buff,
enum batadv_dup_status dup_status)
{
struct batadv_neigh_node *neigh_node = NULL, *tmp_neigh_node = NULL;
struct batadv_neigh_node *router = NULL;
struct batadv_orig_node *orig_node_tmp;
int if_num;
uint8_t sum_orig, sum_neigh;
uint8_t *neigh_addr;
uint8_t tq_avg;
batadv_dbg(BATADV_DBG_BATMAN, bat_priv,
"update_originator(): Searching and updating originator entry of received packet\n");
rcu_read_lock();
hlist_for_each_entry_rcu(tmp_neigh_node,
&orig_node->neigh_list, list) {
neigh_addr = tmp_neigh_node->addr;
if (batadv_compare_eth(neigh_addr, ethhdr->h_source) &&
tmp_neigh_node->if_incoming == if_incoming &&
atomic_inc_not_zero(&tmp_neigh_node->refcount)) {
if (WARN(neigh_node, "too many matching neigh_nodes"))
batadv_neigh_node_free_ref(neigh_node);
neigh_node = tmp_neigh_node;
continue;
}
if (dup_status != BATADV_NO_DUP)
continue;
spin_lock_bh(&tmp_neigh_node->bat_iv.lq_update_lock);
batadv_ring_buffer_set(tmp_neigh_node->bat_iv.tq_recv,
&tmp_neigh_node->bat_iv.tq_index, 0);
tq_avg = batadv_ring_buffer_avg(tmp_neigh_node->bat_iv.tq_recv);
tmp_neigh_node->bat_iv.tq_avg = tq_avg;
spin_unlock_bh(&tmp_neigh_node->bat_iv.lq_update_lock);
}
if (!neigh_node) {
struct batadv_orig_node *orig_tmp;
orig_tmp = batadv_iv_ogm_orig_get(bat_priv, ethhdr->h_source);
if (!orig_tmp)
goto unlock;
neigh_node = batadv_iv_ogm_neigh_new(if_incoming,
ethhdr->h_source,
orig_node, orig_tmp);
batadv_orig_node_free_ref(orig_tmp);
if (!neigh_node)
goto unlock;
} else
batadv_dbg(BATADV_DBG_BATMAN, bat_priv,
"Updating existing last-hop neighbor of originator\n");
rcu_read_unlock();
neigh_node->last_seen = jiffies;
spin_lock_bh(&neigh_node->bat_iv.lq_update_lock);
batadv_ring_buffer_set(neigh_node->bat_iv.tq_recv,
&neigh_node->bat_iv.tq_index,
batadv_ogm_packet->tq);
tq_avg = batadv_ring_buffer_avg(neigh_node->bat_iv.tq_recv);
neigh_node->bat_iv.tq_avg = tq_avg;
spin_unlock_bh(&neigh_node->bat_iv.lq_update_lock);
if (dup_status == BATADV_NO_DUP) {
orig_node->last_ttl = batadv_ogm_packet->ttl;
neigh_node->last_ttl = batadv_ogm_packet->ttl;
}
batadv_bonding_candidate_add(bat_priv, orig_node, neigh_node);
router = batadv_orig_node_get_router(orig_node);
if (router == neigh_node)
goto out;
if (router && (router->bat_iv.tq_avg > neigh_node->bat_iv.tq_avg))
goto out;
if (router && (neigh_node->bat_iv.tq_avg == router->bat_iv.tq_avg)) {
orig_node_tmp = router->orig_node;
spin_lock_bh(&orig_node_tmp->bat_iv.ogm_cnt_lock);
if_num = router->if_incoming->if_num;
sum_orig = orig_node_tmp->bat_iv.bcast_own_sum[if_num];
spin_unlock_bh(&orig_node_tmp->bat_iv.ogm_cnt_lock);
orig_node_tmp = neigh_node->orig_node;
spin_lock_bh(&orig_node_tmp->bat_iv.ogm_cnt_lock);
if_num = neigh_node->if_incoming->if_num;
sum_neigh = orig_node_tmp->bat_iv.bcast_own_sum[if_num];
spin_unlock_bh(&orig_node_tmp->bat_iv.ogm_cnt_lock);
if (sum_orig >= sum_neigh)
goto out;
}
batadv_update_route(bat_priv, orig_node, neigh_node);
goto out;
unlock:
rcu_read_unlock();
out:
if (neigh_node)
batadv_neigh_node_free_ref(neigh_node);
if (router)
batadv_neigh_node_free_ref(router);
}
static int batadv_iv_ogm_calc_tq(struct batadv_orig_node *orig_node,
struct batadv_orig_node *orig_neigh_node,
struct batadv_ogm_packet *batadv_ogm_packet,
struct batadv_hard_iface *if_incoming)
{
struct batadv_priv *bat_priv = netdev_priv(if_incoming->soft_iface);
struct batadv_neigh_node *neigh_node = NULL, *tmp_neigh_node;
uint8_t total_count;
uint8_t orig_eq_count, neigh_rq_count, neigh_rq_inv, tq_own;
unsigned int neigh_rq_inv_cube, neigh_rq_max_cube;
int tq_asym_penalty, inv_asym_penalty, if_num, ret = 0;
unsigned int combined_tq;
rcu_read_lock();
hlist_for_each_entry_rcu(tmp_neigh_node,
&orig_neigh_node->neigh_list, list) {
if (!batadv_compare_eth(tmp_neigh_node->addr,
orig_neigh_node->orig))
continue;
if (tmp_neigh_node->if_incoming != if_incoming)
continue;
if (!atomic_inc_not_zero(&tmp_neigh_node->refcount))
continue;
neigh_node = tmp_neigh_node;
break;
}
rcu_read_unlock();
if (!neigh_node)
neigh_node = batadv_iv_ogm_neigh_new(if_incoming,
orig_neigh_node->orig,
orig_neigh_node,
orig_neigh_node);
if (!neigh_node)
goto out;
if (orig_node == orig_neigh_node)
neigh_node->last_seen = jiffies;
orig_node->last_seen = jiffies;
spin_lock_bh(&orig_node->bat_iv.ogm_cnt_lock);
if_num = if_incoming->if_num;
orig_eq_count = orig_neigh_node->bat_iv.bcast_own_sum[if_num];
neigh_rq_count = neigh_node->bat_iv.real_packet_count;
spin_unlock_bh(&orig_node->bat_iv.ogm_cnt_lock);
if (orig_eq_count > neigh_rq_count)
total_count = neigh_rq_count;
else
total_count = orig_eq_count;
if (total_count < BATADV_TQ_LOCAL_BIDRECT_SEND_MINIMUM ||
neigh_rq_count < BATADV_TQ_LOCAL_BIDRECT_RECV_MINIMUM)
tq_own = 0;
else
tq_own = (BATADV_TQ_MAX_VALUE * total_count) / neigh_rq_count;
neigh_rq_inv = BATADV_TQ_LOCAL_WINDOW_SIZE - neigh_rq_count;
neigh_rq_inv_cube = neigh_rq_inv * neigh_rq_inv * neigh_rq_inv;
neigh_rq_max_cube = BATADV_TQ_LOCAL_WINDOW_SIZE *
BATADV_TQ_LOCAL_WINDOW_SIZE *
BATADV_TQ_LOCAL_WINDOW_SIZE;
inv_asym_penalty = BATADV_TQ_MAX_VALUE * neigh_rq_inv_cube;
inv_asym_penalty /= neigh_rq_max_cube;
tq_asym_penalty = BATADV_TQ_MAX_VALUE - inv_asym_penalty;
combined_tq = batadv_ogm_packet->tq * tq_own * tq_asym_penalty;
combined_tq /= BATADV_TQ_MAX_VALUE * BATADV_TQ_MAX_VALUE;
batadv_ogm_packet->tq = combined_tq;
batadv_dbg(BATADV_DBG_BATMAN, bat_priv,
"bidirectional: orig = %-15pM neigh = %-15pM => own_bcast = %2i, real recv = %2i, local tq: %3i, asym_penalty: %3i, total tq: %3i\n",
orig_node->orig, orig_neigh_node->orig, total_count,
neigh_rq_count, tq_own,
tq_asym_penalty, batadv_ogm_packet->tq);
if (batadv_ogm_packet->tq >= BATADV_TQ_TOTAL_BIDRECT_LIMIT)
ret = 1;
out:
if (neigh_node)
batadv_neigh_node_free_ref(neigh_node);
return ret;
}
static enum batadv_dup_status
batadv_iv_ogm_update_seqnos(const struct ethhdr *ethhdr,
const struct batadv_ogm_packet *batadv_ogm_packet,
const struct batadv_hard_iface *if_incoming)
{
struct batadv_priv *bat_priv = netdev_priv(if_incoming->soft_iface);
struct batadv_orig_node *orig_node;
struct batadv_neigh_node *tmp_neigh_node;
int is_dup;
int32_t seq_diff;
int need_update = 0;
int set_mark;
enum batadv_dup_status ret = BATADV_NO_DUP;
uint32_t seqno = ntohl(batadv_ogm_packet->seqno);
uint8_t *neigh_addr;
uint8_t packet_count;
unsigned long *bitmap;
orig_node = batadv_iv_ogm_orig_get(bat_priv, batadv_ogm_packet->orig);
if (!orig_node)
return BATADV_NO_DUP;
spin_lock_bh(&orig_node->bat_iv.ogm_cnt_lock);
seq_diff = seqno - orig_node->last_real_seqno;
if (!hlist_empty(&orig_node->neigh_list) &&
batadv_window_protected(bat_priv, seq_diff,
&orig_node->batman_seqno_reset)) {
ret = BATADV_PROTECTED;
goto out;
}
rcu_read_lock();
hlist_for_each_entry_rcu(tmp_neigh_node,
&orig_node->neigh_list, list) {
neigh_addr = tmp_neigh_node->addr;
is_dup = batadv_test_bit(tmp_neigh_node->bat_iv.real_bits,
orig_node->last_real_seqno,
seqno);
if (batadv_compare_eth(neigh_addr, ethhdr->h_source) &&
tmp_neigh_node->if_incoming == if_incoming) {
set_mark = 1;
if (is_dup)
ret = BATADV_NEIGH_DUP;
} else {
set_mark = 0;
if (is_dup && (ret != BATADV_NEIGH_DUP))
ret = BATADV_ORIG_DUP;
}
bitmap = tmp_neigh_node->bat_iv.real_bits;
need_update |= batadv_bit_get_packet(bat_priv, bitmap,
seq_diff, set_mark);
packet_count = bitmap_weight(tmp_neigh_node->bat_iv.real_bits,
BATADV_TQ_LOCAL_WINDOW_SIZE);
tmp_neigh_node->bat_iv.real_packet_count = packet_count;
}
rcu_read_unlock();
if (need_update) {
batadv_dbg(BATADV_DBG_BATMAN, bat_priv,
"updating last_seqno: old %u, new %u\n",
orig_node->last_real_seqno, seqno);
orig_node->last_real_seqno = seqno;
}
out:
spin_unlock_bh(&orig_node->bat_iv.ogm_cnt_lock);
batadv_orig_node_free_ref(orig_node);
return ret;
}
static void batadv_iv_ogm_process(const struct ethhdr *ethhdr,
struct batadv_ogm_packet *batadv_ogm_packet,
const unsigned char *tt_buff,
struct batadv_hard_iface *if_incoming)
{
struct batadv_priv *bat_priv = netdev_priv(if_incoming->soft_iface);
struct batadv_hard_iface *hard_iface;
struct batadv_orig_node *orig_neigh_node, *orig_node, *orig_node_tmp;
struct batadv_neigh_node *router = NULL, *router_router = NULL;
struct batadv_neigh_node *orig_neigh_router = NULL;
int has_directlink_flag;
int is_my_addr = 0, is_my_orig = 0, is_my_oldorig = 0;
int is_bidirect;
bool is_single_hop_neigh = false;
bool is_from_best_next_hop = false;
int sameseq, similar_ttl;
enum batadv_dup_status dup_status;
uint32_t if_incoming_seqno;
uint8_t *prev_sender;
if (batadv_ogm_packet->packet_type != BATADV_IV_OGM)
return;
if_incoming_seqno = atomic_read(&if_incoming->bat_iv.ogm_seqno);
if (batadv_ogm_packet->flags & BATADV_DIRECTLINK)
has_directlink_flag = 1;
else
has_directlink_flag = 0;
if (batadv_compare_eth(ethhdr->h_source, batadv_ogm_packet->orig))
is_single_hop_neigh = true;
batadv_dbg(BATADV_DBG_BATMAN, bat_priv,
"Received BATMAN packet via NB: %pM, IF: %s [%pM] (from OG: %pM, via prev OG: %pM, seqno %u, tq %d, TTL %d, V %d, IDF %d)\n",
ethhdr->h_source, if_incoming->net_dev->name,
if_incoming->net_dev->dev_addr, batadv_ogm_packet->orig,
batadv_ogm_packet->prev_sender,
ntohl(batadv_ogm_packet->seqno), batadv_ogm_packet->tq,
batadv_ogm_packet->ttl,
batadv_ogm_packet->version, has_directlink_flag);
rcu_read_lock();
list_for_each_entry_rcu(hard_iface, &batadv_hardif_list, list) {
if (hard_iface->if_status != BATADV_IF_ACTIVE)
continue;
if (hard_iface->soft_iface != if_incoming->soft_iface)
continue;
if (batadv_compare_eth(ethhdr->h_source,
hard_iface->net_dev->dev_addr))
is_my_addr = 1;
if (batadv_compare_eth(batadv_ogm_packet->orig,
hard_iface->net_dev->dev_addr))
is_my_orig = 1;
if (batadv_compare_eth(batadv_ogm_packet->prev_sender,
hard_iface->net_dev->dev_addr))
is_my_oldorig = 1;
}
rcu_read_unlock();
if (is_my_addr) {
batadv_dbg(BATADV_DBG_BATMAN, bat_priv,
"Drop packet: received my own broadcast (sender: %pM)\n",
ethhdr->h_source);
return;
}
if (is_my_orig) {
unsigned long *word;
int offset;
int32_t bit_pos;
int16_t if_num;
uint8_t *weight;
orig_neigh_node = batadv_iv_ogm_orig_get(bat_priv,
ethhdr->h_source);
if (!orig_neigh_node)
return;
if (has_directlink_flag &&
batadv_compare_eth(if_incoming->net_dev->dev_addr,
batadv_ogm_packet->orig)) {
if_num = if_incoming->if_num;
offset = if_num * BATADV_NUM_WORDS;
spin_lock_bh(&orig_neigh_node->bat_iv.ogm_cnt_lock);
word = &(orig_neigh_node->bat_iv.bcast_own[offset]);
bit_pos = if_incoming_seqno - 2;
bit_pos -= ntohl(batadv_ogm_packet->seqno);
batadv_set_bit(word, bit_pos);
weight = &orig_neigh_node->bat_iv.bcast_own_sum[if_num];
*weight = bitmap_weight(word,
BATADV_TQ_LOCAL_WINDOW_SIZE);
spin_unlock_bh(&orig_neigh_node->bat_iv.ogm_cnt_lock);
}
batadv_dbg(BATADV_DBG_BATMAN, bat_priv,
"Drop packet: originator packet from myself (via neighbor)\n");
batadv_orig_node_free_ref(orig_neigh_node);
return;
}
if (is_my_oldorig) {
batadv_dbg(BATADV_DBG_BATMAN, bat_priv,
"Drop packet: ignoring all rebroadcast echos (sender: %pM)\n",
ethhdr->h_source);
return;
}
if (batadv_ogm_packet->flags & BATADV_NOT_BEST_NEXT_HOP) {
batadv_dbg(BATADV_DBG_BATMAN, bat_priv,
"Drop packet: ignoring all packets not forwarded from the best next hop (sender: %pM)\n",
ethhdr->h_source);
return;
}
orig_node = batadv_iv_ogm_orig_get(bat_priv, batadv_ogm_packet->orig);
if (!orig_node)
return;
dup_status = batadv_iv_ogm_update_seqnos(ethhdr, batadv_ogm_packet,
if_incoming);
if (dup_status == BATADV_PROTECTED) {
batadv_dbg(BATADV_DBG_BATMAN, bat_priv,
"Drop packet: packet within seqno protection time (sender: %pM)\n",
ethhdr->h_source);
goto out;
}
if (batadv_ogm_packet->tq == 0) {
batadv_dbg(BATADV_DBG_BATMAN, bat_priv,
"Drop packet: originator packet with tq equal 0\n");
goto out;
}
router = batadv_orig_node_get_router(orig_node);
if (router) {
orig_node_tmp = router->orig_node;
router_router = batadv_orig_node_get_router(orig_node_tmp);
}
if ((router && router->bat_iv.tq_avg != 0) &&
(batadv_compare_eth(router->addr, ethhdr->h_source)))
is_from_best_next_hop = true;
prev_sender = batadv_ogm_packet->prev_sender;
if (router && router_router &&
(batadv_compare_eth(router->addr, prev_sender)) &&
!(batadv_compare_eth(batadv_ogm_packet->orig, prev_sender)) &&
(batadv_compare_eth(router->addr, router_router->addr))) {
batadv_dbg(BATADV_DBG_BATMAN, bat_priv,
"Drop packet: ignoring all rebroadcast packets that may make me loop (sender: %pM)\n",
ethhdr->h_source);
goto out;
}
batadv_tvlv_ogm_receive(bat_priv, batadv_ogm_packet, orig_node);
if (is_single_hop_neigh)
orig_neigh_node = orig_node;
else
orig_neigh_node = batadv_iv_ogm_orig_get(bat_priv,
ethhdr->h_source);
if (!orig_neigh_node)
goto out;
batadv_nc_update_nc_node(bat_priv, orig_node, orig_neigh_node,
batadv_ogm_packet, is_single_hop_neigh);
orig_neigh_router = batadv_orig_node_get_router(orig_neigh_node);
if (!is_single_hop_neigh && (!orig_neigh_router)) {
batadv_dbg(BATADV_DBG_BATMAN, bat_priv,
"Drop packet: OGM via unknown neighbor!\n");
goto out_neigh;
}
is_bidirect = batadv_iv_ogm_calc_tq(orig_node, orig_neigh_node,
batadv_ogm_packet, if_incoming);
batadv_bonding_save_primary(orig_node, orig_neigh_node,
batadv_ogm_packet);
sameseq = orig_node->last_real_seqno == ntohl(batadv_ogm_packet->seqno);
similar_ttl = orig_node->last_ttl - 3 <= batadv_ogm_packet->ttl;
if (is_bidirect && ((dup_status == BATADV_NO_DUP) ||
(sameseq && similar_ttl)))
batadv_iv_ogm_orig_update(bat_priv, orig_node, ethhdr,
batadv_ogm_packet, if_incoming,
tt_buff, dup_status);
if (is_single_hop_neigh) {
batadv_iv_ogm_forward(orig_node, ethhdr, batadv_ogm_packet,
is_single_hop_neigh,
is_from_best_next_hop, if_incoming);
batadv_dbg(BATADV_DBG_BATMAN, bat_priv,
"Forwarding packet: rebroadcast neighbor packet with direct link flag\n");
goto out_neigh;
}
if (!is_bidirect) {
batadv_dbg(BATADV_DBG_BATMAN, bat_priv,
"Drop packet: not received via bidirectional link\n");
goto out_neigh;
}
if (dup_status == BATADV_NEIGH_DUP) {
batadv_dbg(BATADV_DBG_BATMAN, bat_priv,
"Drop packet: duplicate packet received\n");
goto out_neigh;
}
batadv_dbg(BATADV_DBG_BATMAN, bat_priv,
"Forwarding packet: rebroadcast originator packet\n");
batadv_iv_ogm_forward(orig_node, ethhdr, batadv_ogm_packet,
is_single_hop_neigh, is_from_best_next_hop,
if_incoming);
out_neigh:
if ((orig_neigh_node) && (!is_single_hop_neigh))
batadv_orig_node_free_ref(orig_neigh_node);
out:
if (router)
batadv_neigh_node_free_ref(router);
if (router_router)
batadv_neigh_node_free_ref(router_router);
if (orig_neigh_router)
batadv_neigh_node_free_ref(orig_neigh_router);
batadv_orig_node_free_ref(orig_node);
}
static int batadv_iv_ogm_receive(struct sk_buff *skb,
struct batadv_hard_iface *if_incoming)
{
struct batadv_priv *bat_priv = netdev_priv(if_incoming->soft_iface);
struct batadv_ogm_packet *batadv_ogm_packet;
struct ethhdr *ethhdr;
int buff_pos = 0, packet_len;
unsigned char *tvlv_buff, *packet_buff;
uint8_t *packet_pos;
bool ret;
ret = batadv_check_management_packet(skb, if_incoming, BATADV_OGM_HLEN);
if (!ret)
return NET_RX_DROP;
if (bat_priv->bat_algo_ops->bat_ogm_emit != batadv_iv_ogm_emit)
return NET_RX_DROP;
batadv_inc_counter(bat_priv, BATADV_CNT_MGMT_RX);
batadv_add_counter(bat_priv, BATADV_CNT_MGMT_RX_BYTES,
skb->len + ETH_HLEN);
packet_len = skb_headlen(skb);
ethhdr = eth_hdr(skb);
packet_buff = skb->data;
batadv_ogm_packet = (struct batadv_ogm_packet *)packet_buff;
while (batadv_iv_ogm_aggr_packet(buff_pos, packet_len,
batadv_ogm_packet->tvlv_len)) {
tvlv_buff = packet_buff + buff_pos + BATADV_OGM_HLEN;
batadv_iv_ogm_process(ethhdr, batadv_ogm_packet,
tvlv_buff, if_incoming);
buff_pos += BATADV_OGM_HLEN;
buff_pos += ntohs(batadv_ogm_packet->tvlv_len);
packet_pos = packet_buff + buff_pos;
batadv_ogm_packet = (struct batadv_ogm_packet *)packet_pos;
}
kfree_skb(skb);
return NET_RX_SUCCESS;
}
static void batadv_iv_ogm_orig_print(struct batadv_priv *bat_priv,
struct seq_file *seq)
{
struct batadv_neigh_node *neigh_node, *neigh_node_tmp;
struct batadv_hashtable *hash = bat_priv->orig_hash;
int last_seen_msecs, last_seen_secs;
struct batadv_orig_node *orig_node;
unsigned long last_seen_jiffies;
struct hlist_head *head;
int batman_count = 0;
uint32_t i;
seq_printf(seq, " %-15s %s (%s/%i) %17s [%10s]: %20s ...\n",
"Originator", "last-seen", "#", BATADV_TQ_MAX_VALUE,
"Nexthop", "outgoingIF", "Potential nexthops");
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
rcu_read_lock();
hlist_for_each_entry_rcu(orig_node, head, hash_entry) {
neigh_node = batadv_orig_node_get_router(orig_node);
if (!neigh_node)
continue;
if (neigh_node->bat_iv.tq_avg == 0)
goto next;
last_seen_jiffies = jiffies - orig_node->last_seen;
last_seen_msecs = jiffies_to_msecs(last_seen_jiffies);
last_seen_secs = last_seen_msecs / 1000;
last_seen_msecs = last_seen_msecs % 1000;
seq_printf(seq, "%pM %4i.%03is (%3i) %pM [%10s]:",
orig_node->orig, last_seen_secs,
last_seen_msecs, neigh_node->bat_iv.tq_avg,
neigh_node->addr,
neigh_node->if_incoming->net_dev->name);
hlist_for_each_entry_rcu(neigh_node_tmp,
&orig_node->neigh_list, list) {
seq_printf(seq, " %pM (%3i)",
neigh_node_tmp->addr,
neigh_node_tmp->bat_iv.tq_avg);
}
seq_puts(seq, "\n");
batman_count++;
next:
batadv_neigh_node_free_ref(neigh_node);
}
rcu_read_unlock();
}
if (batman_count == 0)
seq_puts(seq, "No batman nodes in range ...\n");
}
static int batadv_iv_ogm_neigh_cmp(struct batadv_neigh_node *neigh1,
struct batadv_neigh_node *neigh2)
{
uint8_t tq1, tq2;
tq1 = neigh1->bat_iv.tq_avg;
tq2 = neigh2->bat_iv.tq_avg;
return tq1 - tq2;
}
static bool batadv_iv_ogm_neigh_is_eob(struct batadv_neigh_node *neigh1,
struct batadv_neigh_node *neigh2)
{
int diff = batadv_iv_ogm_neigh_cmp(neigh1, neigh2);
return diff > -BATADV_TQ_SIMILARITY_THRESHOLD;
}
int __init batadv_iv_init(void)
{
int ret;
ret = batadv_recv_handler_register(BATADV_IV_OGM,
batadv_iv_ogm_receive);
if (ret < 0)
goto out;
ret = batadv_algo_register(&batadv_batman_iv);
if (ret < 0)
goto handler_unregister;
goto out;
handler_unregister:
batadv_recv_handler_unregister(BATADV_IV_OGM);
out:
return ret;
}
