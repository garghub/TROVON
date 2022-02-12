static void batadv_free_info(struct kref *ref)
{
struct batadv_vis_info *info;
struct batadv_priv *bat_priv;
struct batadv_vis_recvlist_node *entry, *tmp;
info = container_of(ref, struct batadv_vis_info, refcount);
bat_priv = info->bat_priv;
list_del_init(&info->send_list);
spin_lock_bh(&bat_priv->vis.list_lock);
list_for_each_entry_safe(entry, tmp, &info->recv_list, list) {
list_del(&entry->list);
kfree(entry);
}
spin_unlock_bh(&bat_priv->vis.list_lock);
kfree_skb(info->skb_packet);
kfree(info);
}
static int batadv_vis_info_cmp(const struct hlist_node *node, const void *data2)
{
const struct batadv_vis_info *d1, *d2;
const struct batadv_vis_packet *p1, *p2;
d1 = container_of(node, struct batadv_vis_info, hash_entry);
d2 = data2;
p1 = (struct batadv_vis_packet *)d1->skb_packet->data;
p2 = (struct batadv_vis_packet *)d2->skb_packet->data;
return batadv_compare_eth(p1->vis_orig, p2->vis_orig);
}
static uint32_t batadv_vis_info_choose(const void *data, uint32_t size)
{
const struct batadv_vis_info *vis_info = data;
const struct batadv_vis_packet *packet;
const unsigned char *key;
uint32_t hash = 0;
size_t i;
packet = (struct batadv_vis_packet *)vis_info->skb_packet->data;
key = packet->vis_orig;
for (i = 0; i < ETH_ALEN; i++) {
hash += key[i];
hash += (hash << 10);
hash ^= (hash >> 6);
}
hash += (hash << 3);
hash ^= (hash >> 11);
hash += (hash << 15);
return hash % size;
}
static struct batadv_vis_info *
batadv_vis_hash_find(struct batadv_priv *bat_priv, const void *data)
{
struct batadv_hashtable *hash = bat_priv->vis.hash;
struct hlist_head *head;
struct batadv_vis_info *vis_info, *vis_info_tmp = NULL;
uint32_t index;
if (!hash)
return NULL;
index = batadv_vis_info_choose(data, hash->size);
head = &hash->table[index];
rcu_read_lock();
hlist_for_each_entry_rcu(vis_info, head, hash_entry) {
if (!batadv_vis_info_cmp(&vis_info->hash_entry, data))
continue;
vis_info_tmp = vis_info;
break;
}
rcu_read_unlock();
return vis_info_tmp;
}
static void batadv_vis_data_insert_interface(const uint8_t *interface,
struct hlist_head *if_list,
bool primary)
{
struct batadv_vis_if_list_entry *entry;
hlist_for_each_entry(entry, if_list, list) {
if (batadv_compare_eth(entry->addr, interface))
return;
}
entry = kmalloc(sizeof(*entry), GFP_ATOMIC);
if (!entry)
return;
memcpy(entry->addr, interface, ETH_ALEN);
entry->primary = primary;
hlist_add_head(&entry->list, if_list);
}
static void batadv_vis_data_read_prim_sec(struct seq_file *seq,
const struct hlist_head *if_list)
{
struct batadv_vis_if_list_entry *entry;
hlist_for_each_entry(entry, if_list, list) {
if (entry->primary)
seq_puts(seq, "PRIMARY, ");
else
seq_printf(seq, "SEC %pM, ", entry->addr);
}
}
static ssize_t
batadv_vis_data_read_entry(struct seq_file *seq,
const struct batadv_vis_info_entry *entry,
const uint8_t *src, bool primary)
{
if (primary && entry->quality == 0)
return seq_printf(seq, "TT %pM, ", entry->dest);
else if (batadv_compare_eth(entry->src, src))
return seq_printf(seq, "TQ %pM %d, ", entry->dest,
entry->quality);
return 0;
}
static void
batadv_vis_data_insert_interfaces(struct hlist_head *list,
struct batadv_vis_packet *packet,
struct batadv_vis_info_entry *entries)
{
int i;
for (i = 0; i < packet->entries; i++) {
if (entries[i].quality == 0)
continue;
if (batadv_compare_eth(entries[i].src, packet->vis_orig))
continue;
batadv_vis_data_insert_interface(entries[i].src, list, false);
}
}
static void batadv_vis_data_read_entries(struct seq_file *seq,
struct hlist_head *list,
struct batadv_vis_packet *packet,
struct batadv_vis_info_entry *entries)
{
int i;
struct batadv_vis_if_list_entry *entry;
hlist_for_each_entry(entry, list, list) {
seq_printf(seq, "%pM,", entry->addr);
for (i = 0; i < packet->entries; i++)
batadv_vis_data_read_entry(seq, &entries[i],
entry->addr, entry->primary);
if (batadv_compare_eth(entry->addr, packet->vis_orig))
batadv_vis_data_read_prim_sec(seq, list);
seq_puts(seq, "\n");
}
}
static void batadv_vis_seq_print_text_bucket(struct seq_file *seq,
const struct hlist_head *head)
{
struct batadv_vis_info *info;
struct batadv_vis_packet *packet;
uint8_t *entries_pos;
struct batadv_vis_info_entry *entries;
struct batadv_vis_if_list_entry *entry;
struct hlist_node *n;
HLIST_HEAD(vis_if_list);
hlist_for_each_entry_rcu(info, head, hash_entry) {
packet = (struct batadv_vis_packet *)info->skb_packet->data;
entries_pos = (uint8_t *)packet + sizeof(*packet);
entries = (struct batadv_vis_info_entry *)entries_pos;
batadv_vis_data_insert_interface(packet->vis_orig, &vis_if_list,
true);
batadv_vis_data_insert_interfaces(&vis_if_list, packet,
entries);
batadv_vis_data_read_entries(seq, &vis_if_list, packet,
entries);
hlist_for_each_entry_safe(entry, n, &vis_if_list, list) {
hlist_del(&entry->list);
kfree(entry);
}
}
}
int batadv_vis_seq_print_text(struct seq_file *seq, void *offset)
{
struct batadv_hard_iface *primary_if;
struct hlist_head *head;
struct net_device *net_dev = (struct net_device *)seq->private;
struct batadv_priv *bat_priv = netdev_priv(net_dev);
struct batadv_hashtable *hash = bat_priv->vis.hash;
uint32_t i;
int ret = 0;
int vis_server = atomic_read(&bat_priv->vis_mode);
primary_if = batadv_primary_if_get_selected(bat_priv);
if (!primary_if)
goto out;
if (vis_server == BATADV_VIS_TYPE_CLIENT_UPDATE)
goto out;
spin_lock_bh(&bat_priv->vis.hash_lock);
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
batadv_vis_seq_print_text_bucket(seq, head);
}
spin_unlock_bh(&bat_priv->vis.hash_lock);
out:
if (primary_if)
batadv_hardif_free_ref(primary_if);
return ret;
}
static void batadv_send_list_add(struct batadv_priv *bat_priv,
struct batadv_vis_info *info)
{
if (list_empty(&info->send_list)) {
kref_get(&info->refcount);
list_add_tail(&info->send_list, &bat_priv->vis.send_list);
}
}
static void batadv_send_list_del(struct batadv_vis_info *info)
{
if (!list_empty(&info->send_list)) {
list_del_init(&info->send_list);
kref_put(&info->refcount, batadv_free_info);
}
}
static void batadv_recv_list_add(struct batadv_priv *bat_priv,
struct list_head *recv_list, const char *mac)
{
struct batadv_vis_recvlist_node *entry;
entry = kmalloc(sizeof(*entry), GFP_ATOMIC);
if (!entry)
return;
memcpy(entry->mac, mac, ETH_ALEN);
spin_lock_bh(&bat_priv->vis.list_lock);
list_add_tail(&entry->list, recv_list);
spin_unlock_bh(&bat_priv->vis.list_lock);
}
static int batadv_recv_list_is_in(struct batadv_priv *bat_priv,
const struct list_head *recv_list,
const char *mac)
{
const struct batadv_vis_recvlist_node *entry;
spin_lock_bh(&bat_priv->vis.list_lock);
list_for_each_entry(entry, recv_list, list) {
if (batadv_compare_eth(entry->mac, mac)) {
spin_unlock_bh(&bat_priv->vis.list_lock);
return 1;
}
}
spin_unlock_bh(&bat_priv->vis.list_lock);
return 0;
}
static struct batadv_vis_info *
batadv_add_packet(struct batadv_priv *bat_priv,
struct batadv_vis_packet *vis_packet, int vis_info_len,
int *is_new, int make_broadcast)
{
struct batadv_vis_info *info, *old_info;
struct batadv_vis_packet *search_packet, *old_packet;
struct batadv_vis_info search_elem;
struct batadv_vis_packet *packet;
struct sk_buff *tmp_skb;
int hash_added;
size_t len;
size_t max_entries;
*is_new = 0;
if (!bat_priv->vis.hash)
return NULL;
search_elem.skb_packet = dev_alloc_skb(sizeof(*search_packet));
if (!search_elem.skb_packet)
return NULL;
len = sizeof(*search_packet);
tmp_skb = search_elem.skb_packet;
search_packet = (struct batadv_vis_packet *)skb_put(tmp_skb, len);
memcpy(search_packet->vis_orig, vis_packet->vis_orig, ETH_ALEN);
old_info = batadv_vis_hash_find(bat_priv, &search_elem);
kfree_skb(search_elem.skb_packet);
if (old_info) {
tmp_skb = old_info->skb_packet;
old_packet = (struct batadv_vis_packet *)tmp_skb->data;
if (!batadv_seq_after(ntohl(vis_packet->seqno),
ntohl(old_packet->seqno))) {
if (old_packet->seqno == vis_packet->seqno) {
batadv_recv_list_add(bat_priv,
&old_info->recv_list,
vis_packet->sender_orig);
return old_info;
} else {
return NULL;
}
}
batadv_hash_remove(bat_priv->vis.hash, batadv_vis_info_cmp,
batadv_vis_info_choose, old_info);
batadv_send_list_del(old_info);
kref_put(&old_info->refcount, batadv_free_info);
}
info = kmalloc(sizeof(*info), GFP_ATOMIC);
if (!info)
return NULL;
len = sizeof(*packet) + vis_info_len;
info->skb_packet = netdev_alloc_skb_ip_align(NULL, len + ETH_HLEN);
if (!info->skb_packet) {
kfree(info);
return NULL;
}
skb_reserve(info->skb_packet, ETH_HLEN);
packet = (struct batadv_vis_packet *)skb_put(info->skb_packet, len);
kref_init(&info->refcount);
INIT_LIST_HEAD(&info->send_list);
INIT_LIST_HEAD(&info->recv_list);
info->first_seen = jiffies;
info->bat_priv = bat_priv;
memcpy(packet, vis_packet, len);
*is_new = 1;
if (make_broadcast)
memcpy(packet->target_orig, batadv_broadcast_addr, ETH_ALEN);
max_entries = vis_info_len / sizeof(struct batadv_vis_info_entry);
if (packet->entries > max_entries)
packet->entries = max_entries;
batadv_recv_list_add(bat_priv, &info->recv_list, packet->sender_orig);
hash_added = batadv_hash_add(bat_priv->vis.hash, batadv_vis_info_cmp,
batadv_vis_info_choose, info,
&info->hash_entry);
if (hash_added != 0) {
kref_put(&info->refcount, batadv_free_info);
info = NULL;
}
return info;
}
void batadv_receive_server_sync_packet(struct batadv_priv *bat_priv,
struct batadv_vis_packet *vis_packet,
int vis_info_len)
{
struct batadv_vis_info *info;
int is_new, make_broadcast;
int vis_server = atomic_read(&bat_priv->vis_mode);
make_broadcast = (vis_server == BATADV_VIS_TYPE_SERVER_SYNC);
spin_lock_bh(&bat_priv->vis.hash_lock);
info = batadv_add_packet(bat_priv, vis_packet, vis_info_len,
&is_new, make_broadcast);
if (!info)
goto end;
if (vis_server == BATADV_VIS_TYPE_SERVER_SYNC && is_new)
batadv_send_list_add(bat_priv, info);
end:
spin_unlock_bh(&bat_priv->vis.hash_lock);
}
void batadv_receive_client_update_packet(struct batadv_priv *bat_priv,
struct batadv_vis_packet *vis_packet,
int vis_info_len)
{
struct batadv_vis_info *info;
struct batadv_vis_packet *packet;
int is_new;
int vis_server = atomic_read(&bat_priv->vis_mode);
int are_target = 0;
if (is_broadcast_ether_addr(vis_packet->target_orig))
return;
if (vis_server == BATADV_VIS_TYPE_SERVER_SYNC &&
batadv_is_my_mac(bat_priv, vis_packet->target_orig))
are_target = 1;
spin_lock_bh(&bat_priv->vis.hash_lock);
info = batadv_add_packet(bat_priv, vis_packet, vis_info_len,
&is_new, are_target);
if (!info)
goto end;
packet = (struct batadv_vis_packet *)info->skb_packet->data;
if (are_target && is_new) {
packet->vis_type = BATADV_VIS_TYPE_SERVER_SYNC;
batadv_send_list_add(bat_priv, info);
} else if (!batadv_is_my_mac(bat_priv, packet->target_orig)) {
batadv_send_list_add(bat_priv, info);
}
end:
spin_unlock_bh(&bat_priv->vis.hash_lock);
}
static int batadv_find_best_vis_server(struct batadv_priv *bat_priv,
struct batadv_vis_info *info)
{
struct batadv_hashtable *hash = bat_priv->orig_hash;
struct batadv_neigh_node *router;
struct hlist_head *head;
struct batadv_orig_node *orig_node;
struct batadv_vis_packet *packet;
int best_tq = -1;
uint32_t i;
packet = (struct batadv_vis_packet *)info->skb_packet->data;
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
rcu_read_lock();
hlist_for_each_entry_rcu(orig_node, head, hash_entry) {
router = batadv_orig_node_get_router(orig_node);
if (!router)
continue;
if ((orig_node->flags & BATADV_VIS_SERVER) &&
(router->tq_avg > best_tq)) {
best_tq = router->tq_avg;
memcpy(packet->target_orig, orig_node->orig,
ETH_ALEN);
}
batadv_neigh_node_free_ref(router);
}
rcu_read_unlock();
}
return best_tq;
}
static bool batadv_vis_packet_full(const struct batadv_vis_info *info)
{
const struct batadv_vis_packet *packet;
size_t num;
packet = (struct batadv_vis_packet *)info->skb_packet->data;
num = BATADV_MAX_VIS_PACKET_SIZE / sizeof(struct batadv_vis_info_entry);
if (num < packet->entries + 1)
return true;
return false;
}
static int batadv_generate_vis_packet(struct batadv_priv *bat_priv)
{
struct batadv_hashtable *hash = bat_priv->orig_hash;
struct hlist_head *head;
struct batadv_orig_node *orig_node;
struct batadv_neigh_node *router;
struct batadv_vis_info *info = bat_priv->vis.my_info;
struct batadv_vis_packet *packet;
struct batadv_vis_info_entry *entry;
struct batadv_tt_common_entry *tt_common_entry;
uint8_t *packet_pos;
int best_tq = -1;
uint32_t i;
info->first_seen = jiffies;
packet = (struct batadv_vis_packet *)info->skb_packet->data;
packet->vis_type = atomic_read(&bat_priv->vis_mode);
memcpy(packet->target_orig, batadv_broadcast_addr, ETH_ALEN);
packet->header.ttl = BATADV_TTL;
packet->seqno = htonl(ntohl(packet->seqno) + 1);
packet->entries = 0;
packet->reserved = 0;
skb_trim(info->skb_packet, sizeof(*packet));
if (packet->vis_type == BATADV_VIS_TYPE_CLIENT_UPDATE) {
best_tq = batadv_find_best_vis_server(bat_priv, info);
if (best_tq < 0)
return best_tq;
}
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
rcu_read_lock();
hlist_for_each_entry_rcu(orig_node, head, hash_entry) {
router = batadv_orig_node_get_router(orig_node);
if (!router)
continue;
if (!batadv_compare_eth(router->addr, orig_node->orig))
goto next;
if (router->if_incoming->if_status != BATADV_IF_ACTIVE)
goto next;
if (router->tq_avg < 1)
goto next;
packet_pos = skb_put(info->skb_packet, sizeof(*entry));
entry = (struct batadv_vis_info_entry *)packet_pos;
memcpy(entry->src,
router->if_incoming->net_dev->dev_addr,
ETH_ALEN);
memcpy(entry->dest, orig_node->orig, ETH_ALEN);
entry->quality = router->tq_avg;
packet->entries++;
next:
batadv_neigh_node_free_ref(router);
if (batadv_vis_packet_full(info))
goto unlock;
}
rcu_read_unlock();
}
hash = bat_priv->tt.local_hash;
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
rcu_read_lock();
hlist_for_each_entry_rcu(tt_common_entry, head,
hash_entry) {
packet_pos = skb_put(info->skb_packet, sizeof(*entry));
entry = (struct batadv_vis_info_entry *)packet_pos;
memset(entry->src, 0, ETH_ALEN);
memcpy(entry->dest, tt_common_entry->addr, ETH_ALEN);
entry->quality = 0;
packet->entries++;
if (batadv_vis_packet_full(info))
goto unlock;
}
rcu_read_unlock();
}
return 0;
unlock:
rcu_read_unlock();
return 0;
}
static void batadv_purge_vis_packets(struct batadv_priv *bat_priv)
{
uint32_t i;
struct batadv_hashtable *hash = bat_priv->vis.hash;
struct hlist_node *node_tmp;
struct hlist_head *head;
struct batadv_vis_info *info;
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
hlist_for_each_entry_safe(info, node_tmp,
head, hash_entry) {
if (info == bat_priv->vis.my_info)
continue;
if (batadv_has_timed_out(info->first_seen,
BATADV_VIS_TIMEOUT)) {
hlist_del(&info->hash_entry);
batadv_send_list_del(info);
kref_put(&info->refcount, batadv_free_info);
}
}
}
}
static void batadv_broadcast_vis_packet(struct batadv_priv *bat_priv,
struct batadv_vis_info *info)
{
struct batadv_hashtable *hash = bat_priv->orig_hash;
struct hlist_head *head;
struct batadv_orig_node *orig_node;
struct batadv_vis_packet *packet;
struct sk_buff *skb;
uint32_t i, res;
packet = (struct batadv_vis_packet *)info->skb_packet->data;
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
rcu_read_lock();
hlist_for_each_entry_rcu(orig_node, head, hash_entry) {
if (!(orig_node->flags & BATADV_VIS_SERVER))
continue;
if (batadv_recv_list_is_in(bat_priv, &info->recv_list,
orig_node->orig))
continue;
memcpy(packet->target_orig, orig_node->orig, ETH_ALEN);
skb = skb_clone(info->skb_packet, GFP_ATOMIC);
if (!skb)
continue;
res = batadv_send_skb_to_orig(skb, orig_node, NULL);
if (res == NET_XMIT_DROP)
kfree_skb(skb);
}
rcu_read_unlock();
}
}
static void batadv_unicast_vis_packet(struct batadv_priv *bat_priv,
struct batadv_vis_info *info)
{
struct batadv_orig_node *orig_node;
struct sk_buff *skb;
struct batadv_vis_packet *packet;
packet = (struct batadv_vis_packet *)info->skb_packet->data;
orig_node = batadv_orig_hash_find(bat_priv, packet->target_orig);
if (!orig_node)
goto out;
skb = skb_clone(info->skb_packet, GFP_ATOMIC);
if (!skb)
goto out;
if (batadv_send_skb_to_orig(skb, orig_node, NULL) == NET_XMIT_DROP)
kfree_skb(skb);
out:
if (orig_node)
batadv_orig_node_free_ref(orig_node);
}
static void batadv_send_vis_packet(struct batadv_priv *bat_priv,
struct batadv_vis_info *info)
{
struct batadv_hard_iface *primary_if;
struct batadv_vis_packet *packet;
primary_if = batadv_primary_if_get_selected(bat_priv);
if (!primary_if)
goto out;
packet = (struct batadv_vis_packet *)info->skb_packet->data;
if (packet->header.ttl < 2) {
pr_debug("Error - can't send vis packet: ttl exceeded\n");
goto out;
}
memcpy(packet->sender_orig, primary_if->net_dev->dev_addr, ETH_ALEN);
packet->header.ttl--;
if (is_broadcast_ether_addr(packet->target_orig))
batadv_broadcast_vis_packet(bat_priv, info);
else
batadv_unicast_vis_packet(bat_priv, info);
packet->header.ttl++;
out:
if (primary_if)
batadv_hardif_free_ref(primary_if);
}
static void batadv_send_vis_packets(struct work_struct *work)
{
struct delayed_work *delayed_work;
struct batadv_priv *bat_priv;
struct batadv_priv_vis *priv_vis;
struct batadv_vis_info *info;
delayed_work = container_of(work, struct delayed_work, work);
priv_vis = container_of(delayed_work, struct batadv_priv_vis, work);
bat_priv = container_of(priv_vis, struct batadv_priv, vis);
spin_lock_bh(&bat_priv->vis.hash_lock);
batadv_purge_vis_packets(bat_priv);
if (batadv_generate_vis_packet(bat_priv) == 0) {
batadv_send_list_add(bat_priv, bat_priv->vis.my_info);
}
while (!list_empty(&bat_priv->vis.send_list)) {
info = list_first_entry(&bat_priv->vis.send_list,
typeof(*info), send_list);
kref_get(&info->refcount);
spin_unlock_bh(&bat_priv->vis.hash_lock);
batadv_send_vis_packet(bat_priv, info);
spin_lock_bh(&bat_priv->vis.hash_lock);
batadv_send_list_del(info);
kref_put(&info->refcount, batadv_free_info);
}
spin_unlock_bh(&bat_priv->vis.hash_lock);
queue_delayed_work(batadv_event_workqueue, &bat_priv->vis.work,
msecs_to_jiffies(BATADV_VIS_INTERVAL));
}
int batadv_vis_init(struct batadv_priv *bat_priv)
{
struct batadv_vis_packet *packet;
int hash_added;
unsigned int len;
unsigned long first_seen;
struct sk_buff *tmp_skb;
if (bat_priv->vis.hash)
return 0;
spin_lock_bh(&bat_priv->vis.hash_lock);
bat_priv->vis.hash = batadv_hash_new(256);
if (!bat_priv->vis.hash) {
pr_err("Can't initialize vis_hash\n");
goto err;
}
batadv_hash_set_lock_class(bat_priv->vis.hash,
&batadv_vis_hash_lock_class_key);
bat_priv->vis.my_info = kmalloc(BATADV_MAX_VIS_PACKET_SIZE, GFP_ATOMIC);
if (!bat_priv->vis.my_info)
goto err;
len = sizeof(*packet) + BATADV_MAX_VIS_PACKET_SIZE + ETH_HLEN;
bat_priv->vis.my_info->skb_packet = netdev_alloc_skb_ip_align(NULL,
len);
if (!bat_priv->vis.my_info->skb_packet)
goto free_info;
skb_reserve(bat_priv->vis.my_info->skb_packet, ETH_HLEN);
tmp_skb = bat_priv->vis.my_info->skb_packet;
packet = (struct batadv_vis_packet *)skb_put(tmp_skb, sizeof(*packet));
first_seen = jiffies - msecs_to_jiffies(BATADV_VIS_INTERVAL);
bat_priv->vis.my_info->first_seen = first_seen;
INIT_LIST_HEAD(&bat_priv->vis.my_info->recv_list);
INIT_LIST_HEAD(&bat_priv->vis.my_info->send_list);
kref_init(&bat_priv->vis.my_info->refcount);
bat_priv->vis.my_info->bat_priv = bat_priv;
packet->header.version = BATADV_COMPAT_VERSION;
packet->header.packet_type = BATADV_VIS;
packet->header.ttl = BATADV_TTL;
packet->seqno = 0;
packet->reserved = 0;
packet->entries = 0;
INIT_LIST_HEAD(&bat_priv->vis.send_list);
hash_added = batadv_hash_add(bat_priv->vis.hash, batadv_vis_info_cmp,
batadv_vis_info_choose,
bat_priv->vis.my_info,
&bat_priv->vis.my_info->hash_entry);
if (hash_added != 0) {
pr_err("Can't add own vis packet into hash\n");
kref_put(&bat_priv->vis.my_info->refcount, batadv_free_info);
goto err;
}
spin_unlock_bh(&bat_priv->vis.hash_lock);
INIT_DELAYED_WORK(&bat_priv->vis.work, batadv_send_vis_packets);
queue_delayed_work(batadv_event_workqueue, &bat_priv->vis.work,
msecs_to_jiffies(BATADV_VIS_INTERVAL));
return 0;
free_info:
kfree(bat_priv->vis.my_info);
bat_priv->vis.my_info = NULL;
err:
spin_unlock_bh(&bat_priv->vis.hash_lock);
batadv_vis_quit(bat_priv);
return -ENOMEM;
}
static void batadv_free_info_ref(struct hlist_node *node, void *arg)
{
struct batadv_vis_info *info;
info = container_of(node, struct batadv_vis_info, hash_entry);
batadv_send_list_del(info);
kref_put(&info->refcount, batadv_free_info);
}
void batadv_vis_quit(struct batadv_priv *bat_priv)
{
if (!bat_priv->vis.hash)
return;
cancel_delayed_work_sync(&bat_priv->vis.work);
spin_lock_bh(&bat_priv->vis.hash_lock);
batadv_hash_delete(bat_priv->vis.hash, batadv_free_info_ref, NULL);
bat_priv->vis.hash = NULL;
bat_priv->vis.my_info = NULL;
spin_unlock_bh(&bat_priv->vis.hash_lock);
}
