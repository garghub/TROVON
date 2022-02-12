int __init batadv_nc_init(void)
{
int ret;
ret = batadv_recv_handler_register(BATADV_CODED,
batadv_nc_recv_coded_packet);
return ret;
}
static void batadv_nc_start_timer(struct batadv_priv *bat_priv)
{
queue_delayed_work(batadv_event_workqueue, &bat_priv->nc.work,
msecs_to_jiffies(10));
}
int batadv_nc_mesh_init(struct batadv_priv *bat_priv)
{
bat_priv->nc.timestamp_fwd_flush = jiffies;
bat_priv->nc.timestamp_sniffed_purge = jiffies;
if (bat_priv->nc.coding_hash || bat_priv->nc.decoding_hash)
return 0;
bat_priv->nc.coding_hash = batadv_hash_new(128);
if (!bat_priv->nc.coding_hash)
goto err;
batadv_hash_set_lock_class(bat_priv->nc.coding_hash,
&batadv_nc_coding_hash_lock_class_key);
bat_priv->nc.decoding_hash = batadv_hash_new(128);
if (!bat_priv->nc.decoding_hash)
goto err;
batadv_hash_set_lock_class(bat_priv->nc.coding_hash,
&batadv_nc_decoding_hash_lock_class_key);
INIT_DELAYED_WORK(&bat_priv->nc.work, batadv_nc_worker);
batadv_nc_start_timer(bat_priv);
return 0;
err:
return -ENOMEM;
}
void batadv_nc_init_bat_priv(struct batadv_priv *bat_priv)
{
atomic_set(&bat_priv->network_coding, 1);
bat_priv->nc.min_tq = 200;
bat_priv->nc.max_fwd_delay = 10;
bat_priv->nc.max_buffer_time = 200;
}
void batadv_nc_init_orig(struct batadv_orig_node *orig_node)
{
INIT_LIST_HEAD(&orig_node->in_coding_list);
INIT_LIST_HEAD(&orig_node->out_coding_list);
spin_lock_init(&orig_node->in_coding_list_lock);
spin_lock_init(&orig_node->out_coding_list_lock);
}
static void batadv_nc_node_free_rcu(struct rcu_head *rcu)
{
struct batadv_nc_node *nc_node;
nc_node = container_of(rcu, struct batadv_nc_node, rcu);
batadv_orig_node_free_ref(nc_node->orig_node);
kfree(nc_node);
}
static void batadv_nc_node_free_ref(struct batadv_nc_node *nc_node)
{
if (atomic_dec_and_test(&nc_node->refcount))
call_rcu(&nc_node->rcu, batadv_nc_node_free_rcu);
}
static void batadv_nc_path_free_ref(struct batadv_nc_path *nc_path)
{
if (atomic_dec_and_test(&nc_path->refcount))
kfree_rcu(nc_path, rcu);
}
static void batadv_nc_packet_free(struct batadv_nc_packet *nc_packet)
{
if (nc_packet->skb)
kfree_skb(nc_packet->skb);
batadv_nc_path_free_ref(nc_packet->nc_path);
kfree(nc_packet);
}
static bool batadv_nc_to_purge_nc_node(struct batadv_priv *bat_priv,
struct batadv_nc_node *nc_node)
{
if (atomic_read(&bat_priv->mesh_state) != BATADV_MESH_ACTIVE)
return true;
return batadv_has_timed_out(nc_node->last_seen, BATADV_NC_NODE_TIMEOUT);
}
static bool batadv_nc_to_purge_nc_path_coding(struct batadv_priv *bat_priv,
struct batadv_nc_path *nc_path)
{
if (atomic_read(&bat_priv->mesh_state) != BATADV_MESH_ACTIVE)
return true;
return batadv_has_timed_out(nc_path->last_valid,
bat_priv->nc.max_fwd_delay * 10);
}
static bool batadv_nc_to_purge_nc_path_decoding(struct batadv_priv *bat_priv,
struct batadv_nc_path *nc_path)
{
if (atomic_read(&bat_priv->mesh_state) != BATADV_MESH_ACTIVE)
return true;
return batadv_has_timed_out(nc_path->last_valid,
bat_priv->nc.max_buffer_time*10);
}
static void
batadv_nc_purge_orig_nc_nodes(struct batadv_priv *bat_priv,
struct list_head *list,
spinlock_t *lock,
bool (*to_purge)(struct batadv_priv *,
struct batadv_nc_node *))
{
struct batadv_nc_node *nc_node, *nc_node_tmp;
spin_lock_bh(lock);
list_for_each_entry_safe(nc_node, nc_node_tmp, list, list) {
if (to_purge && !to_purge(bat_priv, nc_node))
continue;
batadv_dbg(BATADV_DBG_NC, bat_priv,
"Removing nc_node %pM -> %pM\n",
nc_node->addr, nc_node->orig_node->orig);
list_del_rcu(&nc_node->list);
batadv_nc_node_free_ref(nc_node);
}
spin_unlock_bh(lock);
}
void batadv_nc_purge_orig(struct batadv_priv *bat_priv,
struct batadv_orig_node *orig_node,
bool (*to_purge)(struct batadv_priv *,
struct batadv_nc_node *))
{
batadv_nc_purge_orig_nc_nodes(bat_priv, &orig_node->in_coding_list,
&orig_node->in_coding_list_lock,
to_purge);
batadv_nc_purge_orig_nc_nodes(bat_priv, &orig_node->out_coding_list,
&orig_node->out_coding_list_lock,
to_purge);
}
static void batadv_nc_purge_orig_hash(struct batadv_priv *bat_priv)
{
struct batadv_hashtable *hash = bat_priv->orig_hash;
struct hlist_head *head;
struct batadv_orig_node *orig_node;
uint32_t i;
if (!hash)
return;
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
rcu_read_lock();
hlist_for_each_entry_rcu(orig_node, head, hash_entry)
batadv_nc_purge_orig(bat_priv, orig_node,
batadv_nc_to_purge_nc_node);
rcu_read_unlock();
}
}
static void batadv_nc_purge_paths(struct batadv_priv *bat_priv,
struct batadv_hashtable *hash,
bool (*to_purge)(struct batadv_priv *,
struct batadv_nc_path *))
{
struct hlist_head *head;
struct hlist_node *node_tmp;
struct batadv_nc_path *nc_path;
spinlock_t *lock;
uint32_t i;
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
lock = &hash->list_locks[i];
spin_lock_bh(lock);
hlist_for_each_entry_safe(nc_path, node_tmp, head, hash_entry) {
if (to_purge && !to_purge(bat_priv, nc_path))
continue;
if (!unlikely(list_empty(&nc_path->packet_list))) {
net_ratelimited_function(printk,
KERN_WARNING
"Skipping free of non-empty nc_path (%pM -> %pM)!\n",
nc_path->prev_hop,
nc_path->next_hop);
continue;
}
batadv_dbg(BATADV_DBG_NC, bat_priv,
"Remove nc_path %pM -> %pM\n",
nc_path->prev_hop, nc_path->next_hop);
hlist_del_rcu(&nc_path->hash_entry);
batadv_nc_path_free_ref(nc_path);
}
spin_unlock_bh(lock);
}
}
static void batadv_nc_hash_key_gen(struct batadv_nc_path *key, const char *src,
const char *dst)
{
memcpy(key->prev_hop, src, sizeof(key->prev_hop));
memcpy(key->next_hop, dst, sizeof(key->next_hop));
}
static uint32_t batadv_nc_hash_choose(const void *data, uint32_t size)
{
const struct batadv_nc_path *nc_path = data;
uint32_t hash = 0;
hash = batadv_hash_bytes(hash, &nc_path->prev_hop,
sizeof(nc_path->prev_hop));
hash = batadv_hash_bytes(hash, &nc_path->next_hop,
sizeof(nc_path->next_hop));
hash += (hash << 3);
hash ^= (hash >> 11);
hash += (hash << 15);
return hash % size;
}
static int batadv_nc_hash_compare(const struct hlist_node *node,
const void *data2)
{
const struct batadv_nc_path *nc_path1, *nc_path2;
nc_path1 = container_of(node, struct batadv_nc_path, hash_entry);
nc_path2 = data2;
if (memcmp(nc_path1->prev_hop, nc_path2->prev_hop,
sizeof(nc_path1->prev_hop)) != 0)
return 0;
if (memcmp(nc_path1->next_hop, nc_path2->next_hop,
sizeof(nc_path1->next_hop)) != 0)
return 0;
return 1;
}
static struct batadv_nc_path *
batadv_nc_hash_find(struct batadv_hashtable *hash,
void *data)
{
struct hlist_head *head;
struct batadv_nc_path *nc_path, *nc_path_tmp = NULL;
int index;
if (!hash)
return NULL;
index = batadv_nc_hash_choose(data, hash->size);
head = &hash->table[index];
rcu_read_lock();
hlist_for_each_entry_rcu(nc_path, head, hash_entry) {
if (!batadv_nc_hash_compare(&nc_path->hash_entry, data))
continue;
if (!atomic_inc_not_zero(&nc_path->refcount))
continue;
nc_path_tmp = nc_path;
break;
}
rcu_read_unlock();
return nc_path_tmp;
}
static void batadv_nc_send_packet(struct batadv_nc_packet *nc_packet)
{
batadv_send_skb_packet(nc_packet->skb,
nc_packet->neigh_node->if_incoming,
nc_packet->nc_path->next_hop);
nc_packet->skb = NULL;
batadv_nc_packet_free(nc_packet);
}
static bool batadv_nc_sniffed_purge(struct batadv_priv *bat_priv,
struct batadv_nc_path *nc_path,
struct batadv_nc_packet *nc_packet)
{
unsigned long timeout = bat_priv->nc.max_buffer_time;
bool res = false;
if (atomic_read(&bat_priv->mesh_state) == BATADV_MESH_ACTIVE &&
!batadv_has_timed_out(nc_packet->timestamp, timeout))
goto out;
list_del(&nc_packet->list);
batadv_nc_packet_free(nc_packet);
res = true;
out:
return res;
}
static bool batadv_nc_fwd_flush(struct batadv_priv *bat_priv,
struct batadv_nc_path *nc_path,
struct batadv_nc_packet *nc_packet)
{
unsigned long timeout = bat_priv->nc.max_fwd_delay;
if (atomic_read(&bat_priv->mesh_state) == BATADV_MESH_ACTIVE &&
!batadv_has_timed_out(nc_packet->timestamp, timeout))
return false;
batadv_inc_counter(bat_priv, BATADV_CNT_FORWARD);
batadv_add_counter(bat_priv, BATADV_CNT_FORWARD_BYTES,
nc_packet->skb->len + ETH_HLEN);
list_del(&nc_packet->list);
batadv_nc_send_packet(nc_packet);
return true;
}
static void
batadv_nc_process_nc_paths(struct batadv_priv *bat_priv,
struct batadv_hashtable *hash,
bool (*process_fn)(struct batadv_priv *,
struct batadv_nc_path *,
struct batadv_nc_packet *))
{
struct hlist_head *head;
struct batadv_nc_packet *nc_packet, *nc_packet_tmp;
struct batadv_nc_path *nc_path;
bool ret;
int i;
if (!hash)
return;
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
rcu_read_lock();
hlist_for_each_entry_rcu(nc_path, head, hash_entry) {
spin_lock_bh(&nc_path->packet_list_lock);
list_for_each_entry_safe(nc_packet, nc_packet_tmp,
&nc_path->packet_list, list) {
ret = process_fn(bat_priv, nc_path, nc_packet);
if (!ret)
break;
}
spin_unlock_bh(&nc_path->packet_list_lock);
}
rcu_read_unlock();
}
}
static void batadv_nc_worker(struct work_struct *work)
{
struct delayed_work *delayed_work;
struct batadv_priv_nc *priv_nc;
struct batadv_priv *bat_priv;
unsigned long timeout;
delayed_work = container_of(work, struct delayed_work, work);
priv_nc = container_of(delayed_work, struct batadv_priv_nc, work);
bat_priv = container_of(priv_nc, struct batadv_priv, nc);
batadv_nc_purge_orig_hash(bat_priv);
batadv_nc_purge_paths(bat_priv, bat_priv->nc.coding_hash,
batadv_nc_to_purge_nc_path_coding);
batadv_nc_purge_paths(bat_priv, bat_priv->nc.decoding_hash,
batadv_nc_to_purge_nc_path_decoding);
timeout = bat_priv->nc.max_fwd_delay;
if (batadv_has_timed_out(bat_priv->nc.timestamp_fwd_flush, timeout)) {
batadv_nc_process_nc_paths(bat_priv, bat_priv->nc.coding_hash,
batadv_nc_fwd_flush);
bat_priv->nc.timestamp_fwd_flush = jiffies;
}
if (batadv_has_timed_out(bat_priv->nc.timestamp_sniffed_purge,
bat_priv->nc.max_buffer_time)) {
batadv_nc_process_nc_paths(bat_priv, bat_priv->nc.decoding_hash,
batadv_nc_sniffed_purge);
bat_priv->nc.timestamp_sniffed_purge = jiffies;
}
batadv_nc_start_timer(bat_priv);
}
static bool batadv_can_nc_with_orig(struct batadv_priv *bat_priv,
struct batadv_orig_node *orig_node,
struct batadv_ogm_packet *ogm_packet)
{
if (orig_node->last_real_seqno != ntohl(ogm_packet->seqno))
return false;
if (orig_node->last_ttl != ogm_packet->header.ttl + 1)
return false;
if (!batadv_compare_eth(ogm_packet->orig, ogm_packet->prev_sender))
return false;
if (ogm_packet->tq < bat_priv->nc.min_tq)
return false;
return true;
}
static struct batadv_nc_node
*batadv_nc_find_nc_node(struct batadv_orig_node *orig_node,
struct batadv_orig_node *orig_neigh_node,
bool in_coding)
{
struct batadv_nc_node *nc_node, *nc_node_out = NULL;
struct list_head *list;
if (in_coding)
list = &orig_neigh_node->in_coding_list;
else
list = &orig_neigh_node->out_coding_list;
rcu_read_lock();
list_for_each_entry_rcu(nc_node, list, list) {
if (!batadv_compare_eth(nc_node->addr, orig_node->orig))
continue;
if (!atomic_inc_not_zero(&nc_node->refcount))
continue;
nc_node_out = nc_node;
break;
}
rcu_read_unlock();
return nc_node_out;
}
static struct batadv_nc_node
*batadv_nc_get_nc_node(struct batadv_priv *bat_priv,
struct batadv_orig_node *orig_node,
struct batadv_orig_node *orig_neigh_node,
bool in_coding)
{
struct batadv_nc_node *nc_node;
spinlock_t *lock;
struct list_head *list;
nc_node = batadv_nc_find_nc_node(orig_node, orig_neigh_node, in_coding);
if (nc_node)
return nc_node;
nc_node = kzalloc(sizeof(*nc_node), GFP_ATOMIC);
if (!nc_node)
return NULL;
if (!atomic_inc_not_zero(&orig_neigh_node->refcount))
goto free;
INIT_LIST_HEAD(&nc_node->list);
memcpy(nc_node->addr, orig_node->orig, ETH_ALEN);
nc_node->orig_node = orig_neigh_node;
atomic_set(&nc_node->refcount, 2);
if (in_coding) {
lock = &orig_neigh_node->in_coding_list_lock;
list = &orig_neigh_node->in_coding_list;
} else {
lock = &orig_neigh_node->out_coding_list_lock;
list = &orig_neigh_node->out_coding_list;
}
batadv_dbg(BATADV_DBG_NC, bat_priv, "Adding nc_node %pM -> %pM\n",
nc_node->addr, nc_node->orig_node->orig);
spin_lock_bh(lock);
list_add_tail_rcu(&nc_node->list, list);
spin_unlock_bh(lock);
return nc_node;
free:
kfree(nc_node);
return NULL;
}
void batadv_nc_update_nc_node(struct batadv_priv *bat_priv,
struct batadv_orig_node *orig_node,
struct batadv_orig_node *orig_neigh_node,
struct batadv_ogm_packet *ogm_packet,
int is_single_hop_neigh)
{
struct batadv_nc_node *in_nc_node = NULL, *out_nc_node = NULL;
if (!atomic_read(&bat_priv->network_coding))
goto out;
if (!batadv_can_nc_with_orig(bat_priv, orig_node, ogm_packet) &&
!is_single_hop_neigh)
goto out;
in_nc_node = batadv_nc_get_nc_node(bat_priv, orig_node,
orig_neigh_node, true);
if (!in_nc_node)
goto out;
in_nc_node->last_seen = jiffies;
out_nc_node = batadv_nc_get_nc_node(bat_priv, orig_neigh_node,
orig_node, false);
if (!out_nc_node)
goto out;
out_nc_node->last_seen = jiffies;
out:
if (in_nc_node)
batadv_nc_node_free_ref(in_nc_node);
if (out_nc_node)
batadv_nc_node_free_ref(out_nc_node);
}
static struct batadv_nc_path *batadv_nc_get_path(struct batadv_priv *bat_priv,
struct batadv_hashtable *hash,
uint8_t *src,
uint8_t *dst)
{
int hash_added;
struct batadv_nc_path *nc_path, nc_path_key;
batadv_nc_hash_key_gen(&nc_path_key, src, dst);
nc_path = batadv_nc_hash_find(hash, (void *)&nc_path_key);
if (nc_path) {
nc_path->last_valid = jiffies;
return nc_path;
}
nc_path = kzalloc(sizeof(*nc_path), GFP_ATOMIC);
if (!nc_path)
return NULL;
INIT_LIST_HEAD(&nc_path->packet_list);
spin_lock_init(&nc_path->packet_list_lock);
atomic_set(&nc_path->refcount, 2);
nc_path->last_valid = jiffies;
memcpy(nc_path->next_hop, dst, ETH_ALEN);
memcpy(nc_path->prev_hop, src, ETH_ALEN);
batadv_dbg(BATADV_DBG_NC, bat_priv, "Adding nc_path %pM -> %pM\n",
nc_path->prev_hop,
nc_path->next_hop);
hash_added = batadv_hash_add(hash, batadv_nc_hash_compare,
batadv_nc_hash_choose, &nc_path_key,
&nc_path->hash_entry);
if (hash_added < 0) {
kfree(nc_path);
return NULL;
}
return nc_path;
}
static uint8_t batadv_nc_random_weight_tq(uint8_t tq)
{
uint8_t rand_val, rand_tq;
get_random_bytes(&rand_val, sizeof(rand_val));
rand_tq = rand_val * (BATADV_TQ_MAX_VALUE - tq);
rand_tq /= BATADV_TQ_MAX_VALUE;
return BATADV_TQ_MAX_VALUE - rand_tq;
}
static void batadv_nc_memxor(char *dst, const char *src, unsigned int len)
{
unsigned int i;
for (i = 0; i < len; ++i)
dst[i] ^= src[i];
}
static bool batadv_nc_code_packets(struct batadv_priv *bat_priv,
struct sk_buff *skb,
struct ethhdr *ethhdr,
struct batadv_nc_packet *nc_packet,
struct batadv_neigh_node *neigh_node)
{
uint8_t tq_weighted_neigh, tq_weighted_coding;
struct sk_buff *skb_dest, *skb_src;
struct batadv_unicast_packet *packet1;
struct batadv_unicast_packet *packet2;
struct batadv_coded_packet *coded_packet;
struct batadv_neigh_node *neigh_tmp, *router_neigh;
struct batadv_neigh_node *router_coding = NULL;
uint8_t *first_source, *first_dest, *second_source, *second_dest;
__be32 packet_id1, packet_id2;
size_t count;
bool res = false;
int coding_len;
int unicast_size = sizeof(*packet1);
int coded_size = sizeof(*coded_packet);
int header_add = coded_size - unicast_size;
router_neigh = batadv_orig_node_get_router(neigh_node->orig_node);
if (!router_neigh)
goto out;
neigh_tmp = nc_packet->neigh_node;
router_coding = batadv_orig_node_get_router(neigh_tmp->orig_node);
if (!router_coding)
goto out;
tq_weighted_neigh = batadv_nc_random_weight_tq(router_neigh->tq_avg);
tq_weighted_coding = batadv_nc_random_weight_tq(router_coding->tq_avg);
if (tq_weighted_neigh >= tq_weighted_coding) {
first_dest = nc_packet->nc_path->next_hop;
first_source = nc_packet->nc_path->prev_hop;
second_dest = neigh_node->addr;
second_source = ethhdr->h_source;
packet1 = (struct batadv_unicast_packet *)nc_packet->skb->data;
packet2 = (struct batadv_unicast_packet *)skb->data;
packet_id1 = nc_packet->packet_id;
packet_id2 = batadv_skb_crc32(skb,
skb->data + sizeof(*packet2));
} else {
first_dest = neigh_node->addr;
first_source = ethhdr->h_source;
second_dest = nc_packet->nc_path->next_hop;
second_source = nc_packet->nc_path->prev_hop;
packet1 = (struct batadv_unicast_packet *)skb->data;
packet2 = (struct batadv_unicast_packet *)nc_packet->skb->data;
packet_id1 = batadv_skb_crc32(skb,
skb->data + sizeof(*packet1));
packet_id2 = nc_packet->packet_id;
}
if (skb->len <= nc_packet->skb->len) {
skb_dest = nc_packet->skb;
skb_src = skb;
} else {
skb_dest = skb;
skb_src = nc_packet->skb;
}
coding_len = skb_src->len - unicast_size;
if (skb_linearize(skb_dest) < 0 || skb_linearize(skb_src) < 0)
goto out;
skb_push(skb_dest, header_add);
coded_packet = (struct batadv_coded_packet *)skb_dest->data;
skb_reset_mac_header(skb_dest);
coded_packet->header.packet_type = BATADV_CODED;
coded_packet->header.version = BATADV_COMPAT_VERSION;
coded_packet->header.ttl = packet1->header.ttl;
memcpy(coded_packet->first_source, first_source, ETH_ALEN);
memcpy(coded_packet->first_orig_dest, packet1->dest, ETH_ALEN);
coded_packet->first_crc = packet_id1;
coded_packet->first_ttvn = packet1->ttvn;
memcpy(coded_packet->second_dest, second_dest, ETH_ALEN);
memcpy(coded_packet->second_source, second_source, ETH_ALEN);
memcpy(coded_packet->second_orig_dest, packet2->dest, ETH_ALEN);
coded_packet->second_crc = packet_id2;
coded_packet->second_ttl = packet2->header.ttl;
coded_packet->second_ttvn = packet2->ttvn;
coded_packet->coded_len = htons(coding_len);
batadv_nc_memxor(skb_dest->data + coded_size,
skb_src->data + unicast_size, coding_len);
if (BATADV_SKB_CB(skb_src)->decoded &&
BATADV_SKB_CB(skb_dest)->decoded) {
count = skb_src->len + ETH_HLEN;
count += skb_dest->len + ETH_HLEN;
batadv_add_counter(bat_priv, BATADV_CNT_NC_RECODE, 2);
batadv_add_counter(bat_priv, BATADV_CNT_NC_RECODE_BYTES, count);
} else if (!BATADV_SKB_CB(skb_src)->decoded &&
!BATADV_SKB_CB(skb_dest)->decoded) {
count = skb_src->len + ETH_HLEN;
count += skb_dest->len + ETH_HLEN;
batadv_add_counter(bat_priv, BATADV_CNT_NC_CODE, 2);
batadv_add_counter(bat_priv, BATADV_CNT_NC_CODE_BYTES, count);
} else if (BATADV_SKB_CB(skb_src)->decoded &&
!BATADV_SKB_CB(skb_dest)->decoded) {
batadv_inc_counter(bat_priv, BATADV_CNT_NC_RECODE);
batadv_add_counter(bat_priv, BATADV_CNT_NC_RECODE_BYTES,
skb_src->len + ETH_HLEN);
batadv_inc_counter(bat_priv, BATADV_CNT_NC_CODE);
batadv_add_counter(bat_priv, BATADV_CNT_NC_CODE_BYTES,
skb_dest->len + ETH_HLEN);
} else if (!BATADV_SKB_CB(skb_src)->decoded &&
BATADV_SKB_CB(skb_dest)->decoded) {
batadv_inc_counter(bat_priv, BATADV_CNT_NC_CODE);
batadv_add_counter(bat_priv, BATADV_CNT_NC_CODE_BYTES,
skb_src->len + ETH_HLEN);
batadv_inc_counter(bat_priv, BATADV_CNT_NC_RECODE);
batadv_add_counter(bat_priv, BATADV_CNT_NC_RECODE_BYTES,
skb_dest->len + ETH_HLEN);
}
kfree_skb(skb_src);
nc_packet->skb = NULL;
batadv_nc_packet_free(nc_packet);
batadv_send_skb_packet(skb_dest, neigh_node->if_incoming, first_dest);
res = true;
out:
if (router_neigh)
batadv_neigh_node_free_ref(router_neigh);
if (router_coding)
batadv_neigh_node_free_ref(router_coding);
return res;
}
static bool batadv_nc_skb_coding_possible(struct sk_buff *skb,
uint8_t *dst, uint8_t *src)
{
if (BATADV_SKB_CB(skb)->decoded && !batadv_compare_eth(dst, src))
return false;
else
return true;
}
static struct batadv_nc_packet *
batadv_nc_path_search(struct batadv_priv *bat_priv,
struct batadv_nc_node *in_nc_node,
struct batadv_nc_node *out_nc_node,
struct sk_buff *skb,
uint8_t *eth_dst)
{
struct batadv_nc_path *nc_path, nc_path_key;
struct batadv_nc_packet *nc_packet_out = NULL;
struct batadv_nc_packet *nc_packet, *nc_packet_tmp;
struct batadv_hashtable *hash = bat_priv->nc.coding_hash;
int idx;
if (!hash)
return NULL;
batadv_nc_hash_key_gen(&nc_path_key, in_nc_node->addr,
out_nc_node->addr);
idx = batadv_nc_hash_choose(&nc_path_key, hash->size);
rcu_read_lock();
hlist_for_each_entry_rcu(nc_path, &hash->table[idx], hash_entry) {
if (!batadv_compare_eth(nc_path->prev_hop, in_nc_node->addr))
continue;
if (!batadv_compare_eth(nc_path->next_hop, out_nc_node->addr))
continue;
spin_lock_bh(&nc_path->packet_list_lock);
if (list_empty(&nc_path->packet_list)) {
spin_unlock_bh(&nc_path->packet_list_lock);
continue;
}
list_for_each_entry_safe(nc_packet, nc_packet_tmp,
&nc_path->packet_list, list) {
if (!batadv_nc_skb_coding_possible(nc_packet->skb,
eth_dst,
in_nc_node->addr))
continue;
list_del(&nc_packet->list);
nc_packet_out = nc_packet;
break;
}
spin_unlock_bh(&nc_path->packet_list_lock);
break;
}
rcu_read_unlock();
return nc_packet_out;
}
static struct batadv_nc_packet *
batadv_nc_skb_src_search(struct batadv_priv *bat_priv,
struct sk_buff *skb,
uint8_t *eth_dst,
uint8_t *eth_src,
struct batadv_nc_node *in_nc_node)
{
struct batadv_orig_node *orig_node;
struct batadv_nc_node *out_nc_node;
struct batadv_nc_packet *nc_packet = NULL;
orig_node = batadv_orig_hash_find(bat_priv, eth_src);
if (!orig_node)
return NULL;
rcu_read_lock();
list_for_each_entry_rcu(out_nc_node,
&orig_node->out_coding_list, list) {
if (!batadv_nc_skb_coding_possible(skb,
out_nc_node->addr, eth_src))
continue;
nc_packet = batadv_nc_path_search(bat_priv, in_nc_node,
out_nc_node, skb, eth_dst);
if (nc_packet)
break;
}
rcu_read_unlock();
batadv_orig_node_free_ref(orig_node);
return nc_packet;
}
static void batadv_nc_skb_store_before_coding(struct batadv_priv *bat_priv,
struct sk_buff *skb,
uint8_t *eth_dst_new)
{
struct ethhdr *ethhdr;
skb = pskb_copy(skb, GFP_ATOMIC);
if (!skb)
return;
ethhdr = eth_hdr(skb);
memcpy(ethhdr->h_source, ethhdr->h_dest, ETH_ALEN);
memcpy(ethhdr->h_dest, eth_dst_new, ETH_ALEN);
skb_push(skb, ETH_HLEN);
batadv_nc_skb_store_for_decoding(bat_priv, skb);
kfree_skb(skb);
}
static bool batadv_nc_skb_dst_search(struct sk_buff *skb,
struct batadv_neigh_node *neigh_node,
struct ethhdr *ethhdr)
{
struct net_device *netdev = neigh_node->if_incoming->soft_iface;
struct batadv_priv *bat_priv = netdev_priv(netdev);
struct batadv_orig_node *orig_node = neigh_node->orig_node;
struct batadv_nc_node *nc_node;
struct batadv_nc_packet *nc_packet = NULL;
rcu_read_lock();
list_for_each_entry_rcu(nc_node, &orig_node->in_coding_list, list) {
nc_packet = batadv_nc_skb_src_search(bat_priv, skb,
neigh_node->addr,
ethhdr->h_source, nc_node);
if (nc_packet)
break;
}
rcu_read_unlock();
if (!nc_packet)
return false;
batadv_nc_skb_store_before_coding(bat_priv, skb,
neigh_node->addr);
batadv_nc_skb_store_before_coding(bat_priv, nc_packet->skb,
nc_packet->neigh_node->addr);
if (batadv_nc_code_packets(bat_priv, skb, ethhdr, nc_packet,
neigh_node))
return true;
batadv_nc_send_packet(nc_packet);
return false;
}
static bool batadv_nc_skb_add_to_path(struct sk_buff *skb,
struct batadv_nc_path *nc_path,
struct batadv_neigh_node *neigh_node,
__be32 packet_id)
{
struct batadv_nc_packet *nc_packet;
nc_packet = kzalloc(sizeof(*nc_packet), GFP_ATOMIC);
if (!nc_packet)
return false;
nc_packet->timestamp = jiffies;
nc_packet->packet_id = packet_id;
nc_packet->skb = skb;
nc_packet->neigh_node = neigh_node;
nc_packet->nc_path = nc_path;
spin_lock_bh(&nc_path->packet_list_lock);
list_add_tail(&nc_packet->list, &nc_path->packet_list);
spin_unlock_bh(&nc_path->packet_list_lock);
return true;
}
bool batadv_nc_skb_forward(struct sk_buff *skb,
struct batadv_neigh_node *neigh_node)
{
const struct net_device *netdev = neigh_node->if_incoming->soft_iface;
struct batadv_priv *bat_priv = netdev_priv(netdev);
struct batadv_unicast_packet *packet;
struct batadv_nc_path *nc_path;
struct ethhdr *ethhdr = eth_hdr(skb);
__be32 packet_id;
u8 *payload;
if (!atomic_read(&bat_priv->network_coding))
goto out;
payload = skb_network_header(skb);
packet = (struct batadv_unicast_packet *)payload;
if (packet->header.packet_type != BATADV_UNICAST)
goto out;
if (batadv_nc_skb_dst_search(skb, neigh_node, ethhdr))
return true;
nc_path = batadv_nc_get_path(bat_priv,
bat_priv->nc.coding_hash,
ethhdr->h_source,
neigh_node->addr);
if (!nc_path)
goto out;
packet_id = batadv_skb_crc32(skb, payload + sizeof(*packet));
if (!batadv_nc_skb_add_to_path(skb, nc_path, neigh_node, packet_id))
goto free_nc_path;
return true;
free_nc_path:
batadv_nc_path_free_ref(nc_path);
out:
return false;
}
void batadv_nc_skb_store_for_decoding(struct batadv_priv *bat_priv,
struct sk_buff *skb)
{
struct batadv_unicast_packet *packet;
struct batadv_nc_path *nc_path;
struct ethhdr *ethhdr = eth_hdr(skb);
__be32 packet_id;
u8 *payload;
if (!atomic_read(&bat_priv->network_coding))
goto out;
payload = skb_network_header(skb);
packet = (struct batadv_unicast_packet *)payload;
if (packet->header.packet_type != BATADV_UNICAST)
goto out;
nc_path = batadv_nc_get_path(bat_priv,
bat_priv->nc.decoding_hash,
ethhdr->h_source,
ethhdr->h_dest);
if (!nc_path)
goto out;
skb = skb_clone(skb, GFP_ATOMIC);
if (unlikely(!skb))
goto free_nc_path;
if (unlikely(!pskb_may_pull(skb, ETH_HLEN)))
goto free_skb;
if (unlikely(!skb_pull_rcsum(skb, ETH_HLEN)))
goto free_skb;
packet_id = batadv_skb_crc32(skb, payload + sizeof(*packet));
if (!batadv_nc_skb_add_to_path(skb, nc_path, NULL, packet_id))
goto free_skb;
batadv_inc_counter(bat_priv, BATADV_CNT_NC_BUFFER);
return;
free_skb:
kfree_skb(skb);
free_nc_path:
batadv_nc_path_free_ref(nc_path);
out:
return;
}
void batadv_nc_skb_store_sniffed_unicast(struct batadv_priv *bat_priv,
struct sk_buff *skb)
{
struct ethhdr *ethhdr = eth_hdr(skb);
if (batadv_is_my_mac(bat_priv, ethhdr->h_dest))
return;
skb_push(skb, ETH_HLEN);
batadv_nc_skb_store_for_decoding(bat_priv, skb);
}
static struct batadv_unicast_packet *
batadv_nc_skb_decode_packet(struct batadv_priv *bat_priv, struct sk_buff *skb,
struct batadv_nc_packet *nc_packet)
{
const int h_size = sizeof(struct batadv_unicast_packet);
const int h_diff = sizeof(struct batadv_coded_packet) - h_size;
struct batadv_unicast_packet *unicast_packet;
struct batadv_coded_packet coded_packet_tmp;
struct ethhdr *ethhdr, ethhdr_tmp;
uint8_t *orig_dest, ttl, ttvn;
unsigned int coding_len;
int err;
memcpy(&coded_packet_tmp, skb->data, sizeof(coded_packet_tmp));
memcpy(&ethhdr_tmp, skb_mac_header(skb), sizeof(ethhdr_tmp));
if (skb_cow(skb, 0) < 0)
return NULL;
if (unlikely(!skb_pull_rcsum(skb, h_diff)))
return NULL;
skb_set_mac_header(skb, -ETH_HLEN);
skb_reset_network_header(skb);
ethhdr = eth_hdr(skb);
memcpy(ethhdr, &ethhdr_tmp, sizeof(*ethhdr));
if (batadv_is_my_mac(bat_priv, coded_packet_tmp.second_dest)) {
memcpy(ethhdr->h_dest, coded_packet_tmp.second_dest, ETH_ALEN);
skb->pkt_type = PACKET_HOST;
orig_dest = coded_packet_tmp.second_orig_dest;
ttl = coded_packet_tmp.second_ttl;
ttvn = coded_packet_tmp.second_ttvn;
} else {
orig_dest = coded_packet_tmp.first_orig_dest;
ttl = coded_packet_tmp.header.ttl;
ttvn = coded_packet_tmp.first_ttvn;
}
coding_len = ntohs(coded_packet_tmp.coded_len);
if (coding_len > skb->len)
return NULL;
batadv_nc_memxor(skb->data + h_size,
nc_packet->skb->data + h_size,
coding_len);
if (nc_packet->skb->len > coding_len + h_size) {
err = pskb_trim_rcsum(skb, coding_len + h_size);
if (err)
return NULL;
}
unicast_packet = (struct batadv_unicast_packet *)skb->data;
unicast_packet->header.packet_type = BATADV_UNICAST;
unicast_packet->header.version = BATADV_COMPAT_VERSION;
unicast_packet->header.ttl = ttl;
memcpy(unicast_packet->dest, orig_dest, ETH_ALEN);
unicast_packet->ttvn = ttvn;
batadv_nc_packet_free(nc_packet);
return unicast_packet;
}
static struct batadv_nc_packet *
batadv_nc_find_decoding_packet(struct batadv_priv *bat_priv,
struct ethhdr *ethhdr,
struct batadv_coded_packet *coded)
{
struct batadv_hashtable *hash = bat_priv->nc.decoding_hash;
struct batadv_nc_packet *tmp_nc_packet, *nc_packet = NULL;
struct batadv_nc_path *nc_path, nc_path_key;
uint8_t *dest, *source;
__be32 packet_id;
int index;
if (!hash)
return NULL;
dest = ethhdr->h_source;
if (!batadv_is_my_mac(bat_priv, coded->second_dest)) {
source = coded->second_source;
packet_id = coded->second_crc;
} else {
source = coded->first_source;
packet_id = coded->first_crc;
}
batadv_nc_hash_key_gen(&nc_path_key, source, dest);
index = batadv_nc_hash_choose(&nc_path_key, hash->size);
rcu_read_lock();
hlist_for_each_entry_rcu(nc_path, &hash->table[index], hash_entry) {
spin_lock_bh(&nc_path->packet_list_lock);
list_for_each_entry(tmp_nc_packet,
&nc_path->packet_list, list) {
if (packet_id == tmp_nc_packet->packet_id) {
list_del(&tmp_nc_packet->list);
nc_packet = tmp_nc_packet;
break;
}
}
spin_unlock_bh(&nc_path->packet_list_lock);
if (nc_packet)
break;
}
rcu_read_unlock();
if (!nc_packet)
batadv_dbg(BATADV_DBG_NC, bat_priv,
"No decoding packet found for %u\n", packet_id);
return nc_packet;
}
static int batadv_nc_recv_coded_packet(struct sk_buff *skb,
struct batadv_hard_iface *recv_if)
{
struct batadv_priv *bat_priv = netdev_priv(recv_if->soft_iface);
struct batadv_unicast_packet *unicast_packet;
struct batadv_coded_packet *coded_packet;
struct batadv_nc_packet *nc_packet;
struct ethhdr *ethhdr;
int hdr_size = sizeof(*coded_packet);
if (!atomic_read(&bat_priv->network_coding))
return NET_RX_DROP;
if (unlikely(!pskb_may_pull(skb, hdr_size)))
return NET_RX_DROP;
coded_packet = (struct batadv_coded_packet *)skb->data;
ethhdr = eth_hdr(skb);
if (!batadv_is_my_mac(bat_priv, ethhdr->h_dest) &&
!batadv_is_my_mac(bat_priv, coded_packet->second_dest))
return NET_RX_DROP;
if (batadv_is_my_mac(bat_priv, coded_packet->second_dest))
batadv_inc_counter(bat_priv, BATADV_CNT_NC_SNIFFED);
nc_packet = batadv_nc_find_decoding_packet(bat_priv, ethhdr,
coded_packet);
if (!nc_packet) {
batadv_inc_counter(bat_priv, BATADV_CNT_NC_DECODE_FAILED);
return NET_RX_DROP;
}
if (skb_linearize(skb) < 0)
goto free_nc_packet;
if (skb_linearize(nc_packet->skb) < 0)
goto free_nc_packet;
unicast_packet = batadv_nc_skb_decode_packet(bat_priv, skb, nc_packet);
if (!unicast_packet) {
batadv_inc_counter(bat_priv, BATADV_CNT_NC_DECODE_FAILED);
goto free_nc_packet;
}
BATADV_SKB_CB(skb)->decoded = true;
batadv_inc_counter(bat_priv, BATADV_CNT_NC_DECODE);
batadv_add_counter(bat_priv, BATADV_CNT_NC_DECODE_BYTES,
skb->len + ETH_HLEN);
return batadv_recv_unicast_packet(skb, recv_if);
free_nc_packet:
batadv_nc_packet_free(nc_packet);
return NET_RX_DROP;
}
void batadv_nc_mesh_free(struct batadv_priv *bat_priv)
{
cancel_delayed_work_sync(&bat_priv->nc.work);
batadv_nc_purge_paths(bat_priv, bat_priv->nc.coding_hash, NULL);
batadv_hash_destroy(bat_priv->nc.coding_hash);
batadv_nc_purge_paths(bat_priv, bat_priv->nc.decoding_hash, NULL);
batadv_hash_destroy(bat_priv->nc.decoding_hash);
}
int batadv_nc_nodes_seq_print_text(struct seq_file *seq, void *offset)
{
struct net_device *net_dev = (struct net_device *)seq->private;
struct batadv_priv *bat_priv = netdev_priv(net_dev);
struct batadv_hashtable *hash = bat_priv->orig_hash;
struct batadv_hard_iface *primary_if;
struct hlist_head *head;
struct batadv_orig_node *orig_node;
struct batadv_nc_node *nc_node;
int i;
primary_if = batadv_seq_print_text_primary_if_get(seq);
if (!primary_if)
goto out;
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
rcu_read_lock();
hlist_for_each_entry_rcu(orig_node, head, hash_entry) {
if (list_empty(&orig_node->in_coding_list) &&
list_empty(&orig_node->out_coding_list))
continue;
seq_printf(seq, "Node: %pM\n", orig_node->orig);
seq_puts(seq, " Ingoing: ");
list_for_each_entry_rcu(nc_node,
&orig_node->in_coding_list,
list)
seq_printf(seq, "%pM ",
nc_node->addr);
seq_puts(seq, "\n");
seq_puts(seq, " Outgoing: ");
list_for_each_entry_rcu(nc_node,
&orig_node->out_coding_list,
list)
seq_printf(seq, "%pM ",
nc_node->addr);
seq_puts(seq, "\n\n");
}
rcu_read_unlock();
}
out:
if (primary_if)
batadv_hardif_free_ref(primary_if);
return 0;
}
int batadv_nc_init_debugfs(struct batadv_priv *bat_priv)
{
struct dentry *nc_dir, *file;
nc_dir = debugfs_create_dir("nc", bat_priv->debug_dir);
if (!nc_dir)
goto out;
file = debugfs_create_u8("min_tq", S_IRUGO | S_IWUSR, nc_dir,
&bat_priv->nc.min_tq);
if (!file)
goto out;
file = debugfs_create_u32("max_fwd_delay", S_IRUGO | S_IWUSR, nc_dir,
&bat_priv->nc.max_fwd_delay);
if (!file)
goto out;
file = debugfs_create_u32("max_buffer_time", S_IRUGO | S_IWUSR, nc_dir,
&bat_priv->nc.max_buffer_time);
if (!file)
goto out;
return 0;
out:
return -ENOMEM;
}
