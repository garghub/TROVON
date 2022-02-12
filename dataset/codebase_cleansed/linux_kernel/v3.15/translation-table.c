static int batadv_compare_tt(const struct hlist_node *node, const void *data2)
{
const void *data1 = container_of(node, struct batadv_tt_common_entry,
hash_entry);
return batadv_compare_eth(data1, data2);
}
static inline uint32_t batadv_choose_tt(const void *data, uint32_t size)
{
struct batadv_tt_common_entry *tt;
uint32_t hash = 0;
tt = (struct batadv_tt_common_entry *)data;
hash = batadv_hash_bytes(hash, &tt->addr, ETH_ALEN);
hash = batadv_hash_bytes(hash, &tt->vid, sizeof(tt->vid));
hash += (hash << 3);
hash ^= (hash >> 11);
hash += (hash << 15);
return hash % size;
}
static struct batadv_tt_common_entry *
batadv_tt_hash_find(struct batadv_hashtable *hash, const uint8_t *addr,
unsigned short vid)
{
struct hlist_head *head;
struct batadv_tt_common_entry to_search, *tt, *tt_tmp = NULL;
uint32_t index;
if (!hash)
return NULL;
ether_addr_copy(to_search.addr, addr);
to_search.vid = vid;
index = batadv_choose_tt(&to_search, hash->size);
head = &hash->table[index];
rcu_read_lock();
hlist_for_each_entry_rcu(tt, head, hash_entry) {
if (!batadv_compare_eth(tt, addr))
continue;
if (tt->vid != vid)
continue;
if (!atomic_inc_not_zero(&tt->refcount))
continue;
tt_tmp = tt;
break;
}
rcu_read_unlock();
return tt_tmp;
}
static struct batadv_tt_local_entry *
batadv_tt_local_hash_find(struct batadv_priv *bat_priv, const uint8_t *addr,
unsigned short vid)
{
struct batadv_tt_common_entry *tt_common_entry;
struct batadv_tt_local_entry *tt_local_entry = NULL;
tt_common_entry = batadv_tt_hash_find(bat_priv->tt.local_hash, addr,
vid);
if (tt_common_entry)
tt_local_entry = container_of(tt_common_entry,
struct batadv_tt_local_entry,
common);
return tt_local_entry;
}
static struct batadv_tt_global_entry *
batadv_tt_global_hash_find(struct batadv_priv *bat_priv, const uint8_t *addr,
unsigned short vid)
{
struct batadv_tt_common_entry *tt_common_entry;
struct batadv_tt_global_entry *tt_global_entry = NULL;
tt_common_entry = batadv_tt_hash_find(bat_priv->tt.global_hash, addr,
vid);
if (tt_common_entry)
tt_global_entry = container_of(tt_common_entry,
struct batadv_tt_global_entry,
common);
return tt_global_entry;
}
static void
batadv_tt_local_entry_free_ref(struct batadv_tt_local_entry *tt_local_entry)
{
if (atomic_dec_and_test(&tt_local_entry->common.refcount))
kfree_rcu(tt_local_entry, common.rcu);
}
static void
batadv_tt_global_entry_free_ref(struct batadv_tt_global_entry *tt_global_entry)
{
if (atomic_dec_and_test(&tt_global_entry->common.refcount)) {
batadv_tt_global_del_orig_list(tt_global_entry);
kfree_rcu(tt_global_entry, common.rcu);
}
}
int batadv_tt_global_hash_count(struct batadv_priv *bat_priv,
const uint8_t *addr, unsigned short vid)
{
struct batadv_tt_global_entry *tt_global_entry;
int count;
tt_global_entry = batadv_tt_global_hash_find(bat_priv, addr, vid);
if (!tt_global_entry)
return 0;
count = atomic_read(&tt_global_entry->orig_list_count);
batadv_tt_global_entry_free_ref(tt_global_entry);
return count;
}
static void batadv_tt_orig_list_entry_free_rcu(struct rcu_head *rcu)
{
struct batadv_tt_orig_list_entry *orig_entry;
orig_entry = container_of(rcu, struct batadv_tt_orig_list_entry, rcu);
batadv_orig_node_free_ref_now(orig_entry->orig_node);
kfree(orig_entry);
}
static void batadv_tt_local_size_mod(struct batadv_priv *bat_priv,
unsigned short vid, int v)
{
struct batadv_softif_vlan *vlan;
vlan = batadv_softif_vlan_get(bat_priv, vid);
if (!vlan)
return;
atomic_add(v, &vlan->tt.num_entries);
batadv_softif_vlan_free_ref(vlan);
}
static void batadv_tt_local_size_inc(struct batadv_priv *bat_priv,
unsigned short vid)
{
batadv_tt_local_size_mod(bat_priv, vid, 1);
}
static void batadv_tt_local_size_dec(struct batadv_priv *bat_priv,
unsigned short vid)
{
batadv_tt_local_size_mod(bat_priv, vid, -1);
}
static void batadv_tt_global_size_mod(struct batadv_orig_node *orig_node,
unsigned short vid, int v)
{
struct batadv_orig_node_vlan *vlan;
vlan = batadv_orig_node_vlan_new(orig_node, vid);
if (!vlan)
return;
if (atomic_add_return(v, &vlan->tt.num_entries) == 0) {
spin_lock_bh(&orig_node->vlan_list_lock);
list_del_rcu(&vlan->list);
spin_unlock_bh(&orig_node->vlan_list_lock);
batadv_orig_node_vlan_free_ref(vlan);
}
batadv_orig_node_vlan_free_ref(vlan);
}
static void batadv_tt_global_size_inc(struct batadv_orig_node *orig_node,
unsigned short vid)
{
batadv_tt_global_size_mod(orig_node, vid, 1);
}
static void batadv_tt_global_size_dec(struct batadv_orig_node *orig_node,
unsigned short vid)
{
batadv_tt_global_size_mod(orig_node, vid, -1);
}
static void
batadv_tt_orig_list_entry_free_ref(struct batadv_tt_orig_list_entry *orig_entry)
{
if (!atomic_dec_and_test(&orig_entry->refcount))
return;
call_rcu(&orig_entry->rcu, batadv_tt_orig_list_entry_free_rcu);
}
static void batadv_tt_local_event(struct batadv_priv *bat_priv,
struct batadv_tt_local_entry *tt_local_entry,
uint8_t event_flags)
{
struct batadv_tt_change_node *tt_change_node, *entry, *safe;
struct batadv_tt_common_entry *common = &tt_local_entry->common;
uint8_t flags = common->flags | event_flags;
bool event_removed = false;
bool del_op_requested, del_op_entry;
tt_change_node = kmalloc(sizeof(*tt_change_node), GFP_ATOMIC);
if (!tt_change_node)
return;
tt_change_node->change.flags = flags;
memset(tt_change_node->change.reserved, 0,
sizeof(tt_change_node->change.reserved));
ether_addr_copy(tt_change_node->change.addr, common->addr);
tt_change_node->change.vid = htons(common->vid);
del_op_requested = flags & BATADV_TT_CLIENT_DEL;
spin_lock_bh(&bat_priv->tt.changes_list_lock);
list_for_each_entry_safe(entry, safe, &bat_priv->tt.changes_list,
list) {
if (!batadv_compare_eth(entry->change.addr, common->addr))
continue;
del_op_entry = entry->change.flags & BATADV_TT_CLIENT_DEL;
if (!del_op_requested && del_op_entry)
goto del;
if (del_op_requested && !del_op_entry)
goto del;
if (!del_op_requested && !del_op_entry)
entry->change.flags = flags;
continue;
del:
list_del(&entry->list);
kfree(entry);
kfree(tt_change_node);
event_removed = true;
goto unlock;
}
list_add_tail(&tt_change_node->list, &bat_priv->tt.changes_list);
unlock:
spin_unlock_bh(&bat_priv->tt.changes_list_lock);
if (event_removed)
atomic_dec(&bat_priv->tt.local_changes);
else
atomic_inc(&bat_priv->tt.local_changes);
}
static int batadv_tt_len(int changes_num)
{
return changes_num * sizeof(struct batadv_tvlv_tt_change);
}
static uint16_t batadv_tt_entries(uint16_t tt_len)
{
return tt_len / batadv_tt_len(1);
}
static int batadv_tt_local_table_transmit_size(struct batadv_priv *bat_priv)
{
uint16_t num_vlan = 0, tt_local_entries = 0;
struct batadv_softif_vlan *vlan;
int hdr_size;
rcu_read_lock();
hlist_for_each_entry_rcu(vlan, &bat_priv->softif_vlan_list, list) {
num_vlan++;
tt_local_entries += atomic_read(&vlan->tt.num_entries);
}
rcu_read_unlock();
hdr_size = sizeof(struct batadv_unicast_tvlv_packet);
hdr_size += sizeof(struct batadv_tvlv_hdr);
hdr_size += sizeof(struct batadv_tvlv_tt_data);
hdr_size += num_vlan * sizeof(struct batadv_tvlv_tt_vlan_data);
return hdr_size + batadv_tt_len(tt_local_entries);
}
static int batadv_tt_local_init(struct batadv_priv *bat_priv)
{
if (bat_priv->tt.local_hash)
return 0;
bat_priv->tt.local_hash = batadv_hash_new(1024);
if (!bat_priv->tt.local_hash)
return -ENOMEM;
batadv_hash_set_lock_class(bat_priv->tt.local_hash,
&batadv_tt_local_hash_lock_class_key);
return 0;
}
static void batadv_tt_global_free(struct batadv_priv *bat_priv,
struct batadv_tt_global_entry *tt_global,
const char *message)
{
batadv_dbg(BATADV_DBG_TT, bat_priv,
"Deleting global tt entry %pM (vid: %d): %s\n",
tt_global->common.addr,
BATADV_PRINT_VID(tt_global->common.vid), message);
batadv_hash_remove(bat_priv->tt.global_hash, batadv_compare_tt,
batadv_choose_tt, &tt_global->common);
batadv_tt_global_entry_free_ref(tt_global);
}
bool batadv_tt_local_add(struct net_device *soft_iface, const uint8_t *addr,
unsigned short vid, int ifindex, uint32_t mark)
{
struct batadv_priv *bat_priv = netdev_priv(soft_iface);
struct batadv_tt_local_entry *tt_local;
struct batadv_tt_global_entry *tt_global = NULL;
struct net_device *in_dev = NULL;
struct hlist_head *head;
struct batadv_tt_orig_list_entry *orig_entry;
int hash_added, table_size, packet_size_max;
bool ret = false, roamed_back = false;
uint8_t remote_flags;
uint32_t match_mark;
if (ifindex != BATADV_NULL_IFINDEX)
in_dev = dev_get_by_index(&init_net, ifindex);
tt_local = batadv_tt_local_hash_find(bat_priv, addr, vid);
if (!is_multicast_ether_addr(addr))
tt_global = batadv_tt_global_hash_find(bat_priv, addr, vid);
if (tt_local) {
tt_local->last_seen = jiffies;
if (tt_local->common.flags & BATADV_TT_CLIENT_PENDING) {
batadv_dbg(BATADV_DBG_TT, bat_priv,
"Re-adding pending client %pM (vid: %d)\n",
addr, BATADV_PRINT_VID(vid));
tt_local->common.flags &= ~BATADV_TT_CLIENT_PENDING;
goto add_event;
}
if (tt_local->common.flags & BATADV_TT_CLIENT_ROAM) {
batadv_dbg(BATADV_DBG_TT, bat_priv,
"Roaming client %pM (vid: %d) came back to its original location\n",
addr, BATADV_PRINT_VID(vid));
tt_local->common.flags &= ~BATADV_TT_CLIENT_ROAM;
roamed_back = true;
}
goto check_roaming;
}
table_size = batadv_tt_local_table_transmit_size(bat_priv);
table_size += batadv_tt_len(1);
packet_size_max = atomic_read(&bat_priv->packet_size_max);
if (table_size > packet_size_max) {
net_ratelimited_function(batadv_info, soft_iface,
"Local translation table size (%i) exceeds maximum packet size (%i); Ignoring new local tt entry: %pM\n",
table_size, packet_size_max, addr);
goto out;
}
tt_local = kmalloc(sizeof(*tt_local), GFP_ATOMIC);
if (!tt_local)
goto out;
batadv_dbg(BATADV_DBG_TT, bat_priv,
"Creating new local tt entry: %pM (vid: %d, ttvn: %d)\n",
addr, BATADV_PRINT_VID(vid),
(uint8_t)atomic_read(&bat_priv->tt.vn));
ether_addr_copy(tt_local->common.addr, addr);
tt_local->common.flags = BATADV_TT_CLIENT_NEW;
tt_local->common.vid = vid;
if (batadv_is_wifi_netdev(in_dev))
tt_local->common.flags |= BATADV_TT_CLIENT_WIFI;
atomic_set(&tt_local->common.refcount, 2);
tt_local->last_seen = jiffies;
tt_local->common.added_at = tt_local->last_seen;
if (batadv_compare_eth(addr, soft_iface->dev_addr) ||
is_multicast_ether_addr(addr))
tt_local->common.flags |= BATADV_TT_CLIENT_NOPURGE;
hash_added = batadv_hash_add(bat_priv->tt.local_hash, batadv_compare_tt,
batadv_choose_tt, &tt_local->common,
&tt_local->common.hash_entry);
if (unlikely(hash_added != 0)) {
batadv_tt_local_entry_free_ref(tt_local);
goto out;
}
add_event:
batadv_tt_local_event(bat_priv, tt_local, BATADV_NO_FLAGS);
check_roaming:
if (tt_global && !(tt_global->common.flags & BATADV_TT_CLIENT_ROAM)) {
head = &tt_global->orig_list;
rcu_read_lock();
hlist_for_each_entry_rcu(orig_entry, head, list) {
batadv_send_roam_adv(bat_priv, tt_global->common.addr,
tt_global->common.vid,
orig_entry->orig_node);
}
rcu_read_unlock();
if (roamed_back) {
batadv_tt_global_free(bat_priv, tt_global,
"Roaming canceled");
tt_global = NULL;
} else {
tt_global->common.flags |= BATADV_TT_CLIENT_ROAM;
tt_global->roam_at = jiffies;
}
}
remote_flags = tt_local->common.flags & BATADV_TT_REMOTE_MASK;
if (batadv_is_wifi_netdev(in_dev))
tt_local->common.flags |= BATADV_TT_CLIENT_WIFI;
else
tt_local->common.flags &= ~BATADV_TT_CLIENT_WIFI;
match_mark = (mark & bat_priv->isolation_mark_mask);
if (bat_priv->isolation_mark_mask &&
match_mark == bat_priv->isolation_mark)
tt_local->common.flags |= BATADV_TT_CLIENT_ISOLA;
else
tt_local->common.flags &= ~BATADV_TT_CLIENT_ISOLA;
if (remote_flags ^ (tt_local->common.flags & BATADV_TT_REMOTE_MASK))
batadv_tt_local_event(bat_priv, tt_local, BATADV_NO_FLAGS);
ret = true;
out:
if (in_dev)
dev_put(in_dev);
if (tt_local)
batadv_tt_local_entry_free_ref(tt_local);
if (tt_global)
batadv_tt_global_entry_free_ref(tt_global);
return ret;
}
static uint16_t
batadv_tt_prepare_tvlv_global_data(struct batadv_orig_node *orig_node,
struct batadv_tvlv_tt_data **tt_data,
struct batadv_tvlv_tt_change **tt_change,
int32_t *tt_len)
{
uint16_t num_vlan = 0, num_entries = 0, change_offset, tvlv_len;
struct batadv_tvlv_tt_vlan_data *tt_vlan;
struct batadv_orig_node_vlan *vlan;
uint8_t *tt_change_ptr;
rcu_read_lock();
list_for_each_entry_rcu(vlan, &orig_node->vlan_list, list) {
num_vlan++;
num_entries += atomic_read(&vlan->tt.num_entries);
}
change_offset = sizeof(**tt_data);
change_offset += num_vlan * sizeof(*tt_vlan);
if (*tt_len < 0)
*tt_len = batadv_tt_len(num_entries);
tvlv_len = *tt_len;
tvlv_len += change_offset;
*tt_data = kmalloc(tvlv_len, GFP_ATOMIC);
if (!*tt_data) {
*tt_len = 0;
goto out;
}
(*tt_data)->flags = BATADV_NO_FLAGS;
(*tt_data)->ttvn = atomic_read(&orig_node->last_ttvn);
(*tt_data)->num_vlan = htons(num_vlan);
tt_vlan = (struct batadv_tvlv_tt_vlan_data *)(*tt_data + 1);
list_for_each_entry_rcu(vlan, &orig_node->vlan_list, list) {
tt_vlan->vid = htons(vlan->vid);
tt_vlan->crc = htonl(vlan->tt.crc);
tt_vlan++;
}
tt_change_ptr = (uint8_t *)*tt_data + change_offset;
*tt_change = (struct batadv_tvlv_tt_change *)tt_change_ptr;
out:
rcu_read_unlock();
return tvlv_len;
}
static uint16_t
batadv_tt_prepare_tvlv_local_data(struct batadv_priv *bat_priv,
struct batadv_tvlv_tt_data **tt_data,
struct batadv_tvlv_tt_change **tt_change,
int32_t *tt_len)
{
struct batadv_tvlv_tt_vlan_data *tt_vlan;
struct batadv_softif_vlan *vlan;
uint16_t num_vlan = 0, num_entries = 0, tvlv_len;
uint8_t *tt_change_ptr;
int change_offset;
rcu_read_lock();
hlist_for_each_entry_rcu(vlan, &bat_priv->softif_vlan_list, list) {
num_vlan++;
num_entries += atomic_read(&vlan->tt.num_entries);
}
change_offset = sizeof(**tt_data);
change_offset += num_vlan * sizeof(*tt_vlan);
if (*tt_len < 0)
*tt_len = batadv_tt_len(num_entries);
tvlv_len = *tt_len;
tvlv_len += change_offset;
*tt_data = kmalloc(tvlv_len, GFP_ATOMIC);
if (!*tt_data) {
tvlv_len = 0;
goto out;
}
(*tt_data)->flags = BATADV_NO_FLAGS;
(*tt_data)->ttvn = atomic_read(&bat_priv->tt.vn);
(*tt_data)->num_vlan = htons(num_vlan);
tt_vlan = (struct batadv_tvlv_tt_vlan_data *)(*tt_data + 1);
hlist_for_each_entry_rcu(vlan, &bat_priv->softif_vlan_list, list) {
tt_vlan->vid = htons(vlan->vid);
tt_vlan->crc = htonl(vlan->tt.crc);
tt_vlan++;
}
tt_change_ptr = (uint8_t *)*tt_data + change_offset;
*tt_change = (struct batadv_tvlv_tt_change *)tt_change_ptr;
out:
rcu_read_unlock();
return tvlv_len;
}
static void batadv_tt_tvlv_container_update(struct batadv_priv *bat_priv)
{
struct batadv_tt_change_node *entry, *safe;
struct batadv_tvlv_tt_data *tt_data;
struct batadv_tvlv_tt_change *tt_change;
int tt_diff_len, tt_change_len = 0;
int tt_diff_entries_num = 0, tt_diff_entries_count = 0;
uint16_t tvlv_len;
tt_diff_entries_num = atomic_read(&bat_priv->tt.local_changes);
tt_diff_len = batadv_tt_len(tt_diff_entries_num);
if (tt_diff_len > bat_priv->soft_iface->mtu)
tt_diff_len = 0;
tvlv_len = batadv_tt_prepare_tvlv_local_data(bat_priv, &tt_data,
&tt_change, &tt_diff_len);
if (!tvlv_len)
return;
tt_data->flags = BATADV_TT_OGM_DIFF;
if (tt_diff_len == 0)
goto container_register;
spin_lock_bh(&bat_priv->tt.changes_list_lock);
atomic_set(&bat_priv->tt.local_changes, 0);
list_for_each_entry_safe(entry, safe, &bat_priv->tt.changes_list,
list) {
if (tt_diff_entries_count < tt_diff_entries_num) {
memcpy(tt_change + tt_diff_entries_count,
&entry->change,
sizeof(struct batadv_tvlv_tt_change));
tt_diff_entries_count++;
}
list_del(&entry->list);
kfree(entry);
}
spin_unlock_bh(&bat_priv->tt.changes_list_lock);
spin_lock_bh(&bat_priv->tt.last_changeset_lock);
kfree(bat_priv->tt.last_changeset);
bat_priv->tt.last_changeset_len = 0;
bat_priv->tt.last_changeset = NULL;
tt_change_len = batadv_tt_len(tt_diff_entries_count);
if (tt_diff_entries_count > 0) {
bat_priv->tt.last_changeset = kzalloc(tt_diff_len, GFP_ATOMIC);
if (bat_priv->tt.last_changeset) {
memcpy(bat_priv->tt.last_changeset,
tt_change, tt_change_len);
bat_priv->tt.last_changeset_len = tt_diff_len;
}
}
spin_unlock_bh(&bat_priv->tt.last_changeset_lock);
container_register:
batadv_tvlv_container_register(bat_priv, BATADV_TVLV_TT, 1, tt_data,
tvlv_len);
kfree(tt_data);
}
int batadv_tt_local_seq_print_text(struct seq_file *seq, void *offset)
{
struct net_device *net_dev = (struct net_device *)seq->private;
struct batadv_priv *bat_priv = netdev_priv(net_dev);
struct batadv_hashtable *hash = bat_priv->tt.local_hash;
struct batadv_tt_common_entry *tt_common_entry;
struct batadv_tt_local_entry *tt_local;
struct batadv_hard_iface *primary_if;
struct batadv_softif_vlan *vlan;
struct hlist_head *head;
unsigned short vid;
uint32_t i;
int last_seen_secs;
int last_seen_msecs;
unsigned long last_seen_jiffies;
bool no_purge;
uint16_t np_flag = BATADV_TT_CLIENT_NOPURGE;
primary_if = batadv_seq_print_text_primary_if_get(seq);
if (!primary_if)
goto out;
seq_printf(seq,
"Locally retrieved addresses (from %s) announced via TT (TTVN: %u):\n",
net_dev->name, (uint8_t)atomic_read(&bat_priv->tt.vn));
seq_printf(seq, " %-13s %s %-8s %-9s (%-10s)\n", "Client", "VID",
"Flags", "Last seen", "CRC");
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
rcu_read_lock();
hlist_for_each_entry_rcu(tt_common_entry,
head, hash_entry) {
tt_local = container_of(tt_common_entry,
struct batadv_tt_local_entry,
common);
vid = tt_common_entry->vid;
last_seen_jiffies = jiffies - tt_local->last_seen;
last_seen_msecs = jiffies_to_msecs(last_seen_jiffies);
last_seen_secs = last_seen_msecs / 1000;
last_seen_msecs = last_seen_msecs % 1000;
no_purge = tt_common_entry->flags & np_flag;
vlan = batadv_softif_vlan_get(bat_priv, vid);
if (!vlan) {
seq_printf(seq, "Cannot retrieve VLAN %d\n",
BATADV_PRINT_VID(vid));
continue;
}
seq_printf(seq,
" * %pM %4i [%c%c%c%c%c%c] %3u.%03u (%#.8x)\n",
tt_common_entry->addr,
BATADV_PRINT_VID(tt_common_entry->vid),
(tt_common_entry->flags &
BATADV_TT_CLIENT_ROAM ? 'R' : '.'),
no_purge ? 'P' : '.',
(tt_common_entry->flags &
BATADV_TT_CLIENT_NEW ? 'N' : '.'),
(tt_common_entry->flags &
BATADV_TT_CLIENT_PENDING ? 'X' : '.'),
(tt_common_entry->flags &
BATADV_TT_CLIENT_WIFI ? 'W' : '.'),
(tt_common_entry->flags &
BATADV_TT_CLIENT_ISOLA ? 'I' : '.'),
no_purge ? 0 : last_seen_secs,
no_purge ? 0 : last_seen_msecs,
vlan->tt.crc);
batadv_softif_vlan_free_ref(vlan);
}
rcu_read_unlock();
}
out:
if (primary_if)
batadv_hardif_free_ref(primary_if);
return 0;
}
static void
batadv_tt_local_set_pending(struct batadv_priv *bat_priv,
struct batadv_tt_local_entry *tt_local_entry,
uint16_t flags, const char *message)
{
batadv_tt_local_event(bat_priv, tt_local_entry, flags);
tt_local_entry->common.flags |= BATADV_TT_CLIENT_PENDING;
batadv_dbg(BATADV_DBG_TT, bat_priv,
"Local tt entry (%pM, vid: %d) pending to be removed: %s\n",
tt_local_entry->common.addr,
BATADV_PRINT_VID(tt_local_entry->common.vid), message);
}
uint16_t batadv_tt_local_remove(struct batadv_priv *bat_priv,
const uint8_t *addr, unsigned short vid,
const char *message, bool roaming)
{
struct batadv_tt_local_entry *tt_local_entry;
uint16_t flags, curr_flags = BATADV_NO_FLAGS;
tt_local_entry = batadv_tt_local_hash_find(bat_priv, addr, vid);
if (!tt_local_entry)
goto out;
curr_flags = tt_local_entry->common.flags;
flags = BATADV_TT_CLIENT_DEL;
if (roaming) {
flags |= BATADV_TT_CLIENT_ROAM;
tt_local_entry->common.flags |= BATADV_TT_CLIENT_ROAM;
}
if (!(tt_local_entry->common.flags & BATADV_TT_CLIENT_NEW)) {
batadv_tt_local_set_pending(bat_priv, tt_local_entry, flags,
message);
goto out;
}
batadv_tt_local_event(bat_priv, tt_local_entry, BATADV_TT_CLIENT_DEL);
hlist_del_rcu(&tt_local_entry->common.hash_entry);
batadv_tt_local_entry_free_ref(tt_local_entry);
out:
if (tt_local_entry)
batadv_tt_local_entry_free_ref(tt_local_entry);
return curr_flags;
}
static void batadv_tt_local_purge_list(struct batadv_priv *bat_priv,
struct hlist_head *head,
int timeout)
{
struct batadv_tt_local_entry *tt_local_entry;
struct batadv_tt_common_entry *tt_common_entry;
struct hlist_node *node_tmp;
hlist_for_each_entry_safe(tt_common_entry, node_tmp, head,
hash_entry) {
tt_local_entry = container_of(tt_common_entry,
struct batadv_tt_local_entry,
common);
if (tt_local_entry->common.flags & BATADV_TT_CLIENT_NOPURGE)
continue;
if (tt_local_entry->common.flags & BATADV_TT_CLIENT_PENDING)
continue;
if (!batadv_has_timed_out(tt_local_entry->last_seen, timeout))
continue;
batadv_tt_local_set_pending(bat_priv, tt_local_entry,
BATADV_TT_CLIENT_DEL, "timed out");
}
}
static void batadv_tt_local_purge(struct batadv_priv *bat_priv,
int timeout)
{
struct batadv_hashtable *hash = bat_priv->tt.local_hash;
struct hlist_head *head;
spinlock_t *list_lock;
uint32_t i;
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
list_lock = &hash->list_locks[i];
spin_lock_bh(list_lock);
batadv_tt_local_purge_list(bat_priv, head, timeout);
spin_unlock_bh(list_lock);
}
}
static void batadv_tt_local_table_free(struct batadv_priv *bat_priv)
{
struct batadv_hashtable *hash;
spinlock_t *list_lock;
struct batadv_tt_common_entry *tt_common_entry;
struct batadv_tt_local_entry *tt_local;
struct hlist_node *node_tmp;
struct hlist_head *head;
uint32_t i;
if (!bat_priv->tt.local_hash)
return;
hash = bat_priv->tt.local_hash;
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
list_lock = &hash->list_locks[i];
spin_lock_bh(list_lock);
hlist_for_each_entry_safe(tt_common_entry, node_tmp,
head, hash_entry) {
hlist_del_rcu(&tt_common_entry->hash_entry);
tt_local = container_of(tt_common_entry,
struct batadv_tt_local_entry,
common);
batadv_tt_local_entry_free_ref(tt_local);
}
spin_unlock_bh(list_lock);
}
batadv_hash_destroy(hash);
bat_priv->tt.local_hash = NULL;
}
static int batadv_tt_global_init(struct batadv_priv *bat_priv)
{
if (bat_priv->tt.global_hash)
return 0;
bat_priv->tt.global_hash = batadv_hash_new(1024);
if (!bat_priv->tt.global_hash)
return -ENOMEM;
batadv_hash_set_lock_class(bat_priv->tt.global_hash,
&batadv_tt_global_hash_lock_class_key);
return 0;
}
static void batadv_tt_changes_list_free(struct batadv_priv *bat_priv)
{
struct batadv_tt_change_node *entry, *safe;
spin_lock_bh(&bat_priv->tt.changes_list_lock);
list_for_each_entry_safe(entry, safe, &bat_priv->tt.changes_list,
list) {
list_del(&entry->list);
kfree(entry);
}
atomic_set(&bat_priv->tt.local_changes, 0);
spin_unlock_bh(&bat_priv->tt.changes_list_lock);
}
static struct batadv_tt_orig_list_entry *
batadv_tt_global_orig_entry_find(const struct batadv_tt_global_entry *entry,
const struct batadv_orig_node *orig_node)
{
struct batadv_tt_orig_list_entry *tmp_orig_entry, *orig_entry = NULL;
const struct hlist_head *head;
rcu_read_lock();
head = &entry->orig_list;
hlist_for_each_entry_rcu(tmp_orig_entry, head, list) {
if (tmp_orig_entry->orig_node != orig_node)
continue;
if (!atomic_inc_not_zero(&tmp_orig_entry->refcount))
continue;
orig_entry = tmp_orig_entry;
break;
}
rcu_read_unlock();
return orig_entry;
}
static bool
batadv_tt_global_entry_has_orig(const struct batadv_tt_global_entry *entry,
const struct batadv_orig_node *orig_node)
{
struct batadv_tt_orig_list_entry *orig_entry;
bool found = false;
orig_entry = batadv_tt_global_orig_entry_find(entry, orig_node);
if (orig_entry) {
found = true;
batadv_tt_orig_list_entry_free_ref(orig_entry);
}
return found;
}
static void
batadv_tt_global_orig_entry_add(struct batadv_tt_global_entry *tt_global,
struct batadv_orig_node *orig_node, int ttvn)
{
struct batadv_tt_orig_list_entry *orig_entry;
orig_entry = batadv_tt_global_orig_entry_find(tt_global, orig_node);
if (orig_entry) {
orig_entry->ttvn = ttvn;
goto out;
}
orig_entry = kzalloc(sizeof(*orig_entry), GFP_ATOMIC);
if (!orig_entry)
goto out;
INIT_HLIST_NODE(&orig_entry->list);
atomic_inc(&orig_node->refcount);
batadv_tt_global_size_inc(orig_node, tt_global->common.vid);
orig_entry->orig_node = orig_node;
orig_entry->ttvn = ttvn;
atomic_set(&orig_entry->refcount, 2);
spin_lock_bh(&tt_global->list_lock);
hlist_add_head_rcu(&orig_entry->list,
&tt_global->orig_list);
spin_unlock_bh(&tt_global->list_lock);
atomic_inc(&tt_global->orig_list_count);
out:
if (orig_entry)
batadv_tt_orig_list_entry_free_ref(orig_entry);
}
static bool batadv_tt_global_add(struct batadv_priv *bat_priv,
struct batadv_orig_node *orig_node,
const unsigned char *tt_addr,
unsigned short vid, uint16_t flags,
uint8_t ttvn)
{
struct batadv_tt_global_entry *tt_global_entry;
struct batadv_tt_local_entry *tt_local_entry;
bool ret = false;
int hash_added;
struct batadv_tt_common_entry *common;
uint16_t local_flags;
if (batadv_bla_is_backbone_gw_orig(bat_priv, orig_node->orig, vid))
return true;
tt_global_entry = batadv_tt_global_hash_find(bat_priv, tt_addr, vid);
tt_local_entry = batadv_tt_local_hash_find(bat_priv, tt_addr, vid);
if ((flags & BATADV_TT_CLIENT_TEMP) && tt_local_entry &&
!(tt_local_entry->common.flags & BATADV_TT_CLIENT_NEW))
goto out;
if (!tt_global_entry) {
tt_global_entry = kzalloc(sizeof(*tt_global_entry), GFP_ATOMIC);
if (!tt_global_entry)
goto out;
common = &tt_global_entry->common;
ether_addr_copy(common->addr, tt_addr);
common->vid = vid;
common->flags = flags;
tt_global_entry->roam_at = 0;
if (flags & BATADV_TT_CLIENT_ROAM)
tt_global_entry->roam_at = jiffies;
atomic_set(&common->refcount, 2);
common->added_at = jiffies;
INIT_HLIST_HEAD(&tt_global_entry->orig_list);
atomic_set(&tt_global_entry->orig_list_count, 0);
spin_lock_init(&tt_global_entry->list_lock);
hash_added = batadv_hash_add(bat_priv->tt.global_hash,
batadv_compare_tt,
batadv_choose_tt, common,
&common->hash_entry);
if (unlikely(hash_added != 0)) {
batadv_tt_global_entry_free_ref(tt_global_entry);
goto out_remove;
}
} else {
common = &tt_global_entry->common;
if (flags & BATADV_TT_CLIENT_TEMP) {
if (!(common->flags & BATADV_TT_CLIENT_TEMP))
goto out;
if (batadv_tt_global_entry_has_orig(tt_global_entry,
orig_node))
goto out_remove;
batadv_tt_global_del_orig_list(tt_global_entry);
goto add_orig_entry;
}
common->flags &= ~BATADV_TT_CLIENT_TEMP;
tt_global_entry->common.flags |= flags;
if (common->flags & BATADV_TT_CLIENT_ROAM) {
batadv_tt_global_del_orig_list(tt_global_entry);
common->flags &= ~BATADV_TT_CLIENT_ROAM;
tt_global_entry->roam_at = 0;
}
}
add_orig_entry:
batadv_tt_global_orig_entry_add(tt_global_entry, orig_node, ttvn);
batadv_dbg(BATADV_DBG_TT, bat_priv,
"Creating new global tt entry: %pM (vid: %d, via %pM)\n",
common->addr, BATADV_PRINT_VID(common->vid),
orig_node->orig);
ret = true;
out_remove:
if (is_multicast_ether_addr(tt_addr))
goto out;
local_flags = batadv_tt_local_remove(bat_priv, tt_addr, vid,
"global tt received",
flags & BATADV_TT_CLIENT_ROAM);
tt_global_entry->common.flags |= local_flags & BATADV_TT_CLIENT_WIFI;
if (!(flags & BATADV_TT_CLIENT_ROAM))
tt_global_entry->common.flags &= ~BATADV_TT_CLIENT_ROAM;
out:
if (tt_global_entry)
batadv_tt_global_entry_free_ref(tt_global_entry);
if (tt_local_entry)
batadv_tt_local_entry_free_ref(tt_local_entry);
return ret;
}
static struct batadv_tt_orig_list_entry *
batadv_transtable_best_orig(struct batadv_priv *bat_priv,
struct batadv_tt_global_entry *tt_global_entry)
{
struct batadv_neigh_node *router, *best_router = NULL;
struct batadv_algo_ops *bao = bat_priv->bat_algo_ops;
struct hlist_head *head;
struct batadv_tt_orig_list_entry *orig_entry, *best_entry = NULL;
head = &tt_global_entry->orig_list;
hlist_for_each_entry_rcu(orig_entry, head, list) {
router = batadv_orig_router_get(orig_entry->orig_node,
BATADV_IF_DEFAULT);
if (!router)
continue;
if (best_router &&
bao->bat_neigh_cmp(router, BATADV_IF_DEFAULT,
best_router, BATADV_IF_DEFAULT) <= 0) {
batadv_neigh_node_free_ref(router);
continue;
}
if (best_router)
batadv_neigh_node_free_ref(best_router);
best_entry = orig_entry;
best_router = router;
}
if (best_router)
batadv_neigh_node_free_ref(best_router);
return best_entry;
}
static void
batadv_tt_global_print_entry(struct batadv_priv *bat_priv,
struct batadv_tt_global_entry *tt_global_entry,
struct seq_file *seq)
{
struct batadv_tt_orig_list_entry *orig_entry, *best_entry;
struct batadv_tt_common_entry *tt_common_entry;
struct batadv_orig_node_vlan *vlan;
struct hlist_head *head;
uint8_t last_ttvn;
uint16_t flags;
tt_common_entry = &tt_global_entry->common;
flags = tt_common_entry->flags;
best_entry = batadv_transtable_best_orig(bat_priv, tt_global_entry);
if (best_entry) {
vlan = batadv_orig_node_vlan_get(best_entry->orig_node,
tt_common_entry->vid);
if (!vlan) {
seq_printf(seq,
" * Cannot retrieve VLAN %d for originator %pM\n",
BATADV_PRINT_VID(tt_common_entry->vid),
best_entry->orig_node->orig);
goto print_list;
}
last_ttvn = atomic_read(&best_entry->orig_node->last_ttvn);
seq_printf(seq,
" %c %pM %4i (%3u) via %pM (%3u) (%#.8x) [%c%c%c%c]\n",
'*', tt_global_entry->common.addr,
BATADV_PRINT_VID(tt_global_entry->common.vid),
best_entry->ttvn, best_entry->orig_node->orig,
last_ttvn, vlan->tt.crc,
(flags & BATADV_TT_CLIENT_ROAM ? 'R' : '.'),
(flags & BATADV_TT_CLIENT_WIFI ? 'W' : '.'),
(flags & BATADV_TT_CLIENT_ISOLA ? 'I' : '.'),
(flags & BATADV_TT_CLIENT_TEMP ? 'T' : '.'));
batadv_orig_node_vlan_free_ref(vlan);
}
print_list:
head = &tt_global_entry->orig_list;
hlist_for_each_entry_rcu(orig_entry, head, list) {
if (best_entry == orig_entry)
continue;
vlan = batadv_orig_node_vlan_get(orig_entry->orig_node,
tt_common_entry->vid);
if (!vlan) {
seq_printf(seq,
" + Cannot retrieve VLAN %d for originator %pM\n",
BATADV_PRINT_VID(tt_common_entry->vid),
orig_entry->orig_node->orig);
continue;
}
last_ttvn = atomic_read(&orig_entry->orig_node->last_ttvn);
seq_printf(seq,
" %c %pM %4d (%3u) via %pM (%3u) (%#.8x) [%c%c%c%c]\n",
'+', tt_global_entry->common.addr,
BATADV_PRINT_VID(tt_global_entry->common.vid),
orig_entry->ttvn, orig_entry->orig_node->orig,
last_ttvn, vlan->tt.crc,
(flags & BATADV_TT_CLIENT_ROAM ? 'R' : '.'),
(flags & BATADV_TT_CLIENT_WIFI ? 'W' : '.'),
(flags & BATADV_TT_CLIENT_ISOLA ? 'I' : '.'),
(flags & BATADV_TT_CLIENT_TEMP ? 'T' : '.'));
batadv_orig_node_vlan_free_ref(vlan);
}
}
int batadv_tt_global_seq_print_text(struct seq_file *seq, void *offset)
{
struct net_device *net_dev = (struct net_device *)seq->private;
struct batadv_priv *bat_priv = netdev_priv(net_dev);
struct batadv_hashtable *hash = bat_priv->tt.global_hash;
struct batadv_tt_common_entry *tt_common_entry;
struct batadv_tt_global_entry *tt_global;
struct batadv_hard_iface *primary_if;
struct hlist_head *head;
uint32_t i;
primary_if = batadv_seq_print_text_primary_if_get(seq);
if (!primary_if)
goto out;
seq_printf(seq,
"Globally announced TT entries received via the mesh %s\n",
net_dev->name);
seq_printf(seq, " %-13s %s %s %-15s %s (%-10s) %s\n",
"Client", "VID", "(TTVN)", "Originator", "(Curr TTVN)",
"CRC", "Flags");
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
rcu_read_lock();
hlist_for_each_entry_rcu(tt_common_entry,
head, hash_entry) {
tt_global = container_of(tt_common_entry,
struct batadv_tt_global_entry,
common);
batadv_tt_global_print_entry(bat_priv, tt_global, seq);
}
rcu_read_unlock();
}
out:
if (primary_if)
batadv_hardif_free_ref(primary_if);
return 0;
}
static void
batadv_tt_global_del_orig_entry(struct batadv_tt_global_entry *tt_global_entry,
struct batadv_tt_orig_list_entry *orig_entry)
{
batadv_tt_global_size_dec(orig_entry->orig_node,
tt_global_entry->common.vid);
atomic_dec(&tt_global_entry->orig_list_count);
hlist_del_rcu(&orig_entry->list);
batadv_tt_orig_list_entry_free_ref(orig_entry);
}
static void
batadv_tt_global_del_orig_list(struct batadv_tt_global_entry *tt_global_entry)
{
struct hlist_head *head;
struct hlist_node *safe;
struct batadv_tt_orig_list_entry *orig_entry;
spin_lock_bh(&tt_global_entry->list_lock);
head = &tt_global_entry->orig_list;
hlist_for_each_entry_safe(orig_entry, safe, head, list)
batadv_tt_global_del_orig_entry(tt_global_entry, orig_entry);
spin_unlock_bh(&tt_global_entry->list_lock);
}
static void
batadv_tt_global_del_orig_node(struct batadv_priv *bat_priv,
struct batadv_tt_global_entry *tt_global_entry,
struct batadv_orig_node *orig_node,
const char *message)
{
struct hlist_head *head;
struct hlist_node *safe;
struct batadv_tt_orig_list_entry *orig_entry;
unsigned short vid;
spin_lock_bh(&tt_global_entry->list_lock);
head = &tt_global_entry->orig_list;
hlist_for_each_entry_safe(orig_entry, safe, head, list) {
if (orig_entry->orig_node == orig_node) {
vid = tt_global_entry->common.vid;
batadv_dbg(BATADV_DBG_TT, bat_priv,
"Deleting %pM from global tt entry %pM (vid: %d): %s\n",
orig_node->orig,
tt_global_entry->common.addr,
BATADV_PRINT_VID(vid), message);
batadv_tt_global_del_orig_entry(tt_global_entry,
orig_entry);
}
}
spin_unlock_bh(&tt_global_entry->list_lock);
}
static void
batadv_tt_global_del_roaming(struct batadv_priv *bat_priv,
struct batadv_tt_global_entry *tt_global_entry,
struct batadv_orig_node *orig_node,
const char *message)
{
bool last_entry = true;
struct hlist_head *head;
struct batadv_tt_orig_list_entry *orig_entry;
rcu_read_lock();
head = &tt_global_entry->orig_list;
hlist_for_each_entry_rcu(orig_entry, head, list) {
if (orig_entry->orig_node != orig_node) {
last_entry = false;
break;
}
}
rcu_read_unlock();
if (last_entry) {
tt_global_entry->common.flags |= BATADV_TT_CLIENT_ROAM;
tt_global_entry->roam_at = jiffies;
} else
batadv_tt_global_del_orig_node(bat_priv, tt_global_entry,
orig_node, message);
}
static void batadv_tt_global_del(struct batadv_priv *bat_priv,
struct batadv_orig_node *orig_node,
const unsigned char *addr, unsigned short vid,
const char *message, bool roaming)
{
struct batadv_tt_global_entry *tt_global_entry;
struct batadv_tt_local_entry *local_entry = NULL;
tt_global_entry = batadv_tt_global_hash_find(bat_priv, addr, vid);
if (!tt_global_entry)
goto out;
if (!roaming) {
batadv_tt_global_del_orig_node(bat_priv, tt_global_entry,
orig_node, message);
if (hlist_empty(&tt_global_entry->orig_list))
batadv_tt_global_free(bat_priv, tt_global_entry,
message);
goto out;
}
local_entry = batadv_tt_local_hash_find(bat_priv,
tt_global_entry->common.addr,
vid);
if (local_entry) {
batadv_tt_global_del_orig_list(tt_global_entry);
batadv_tt_global_free(bat_priv, tt_global_entry, message);
} else
batadv_tt_global_del_roaming(bat_priv, tt_global_entry,
orig_node, message);
out:
if (tt_global_entry)
batadv_tt_global_entry_free_ref(tt_global_entry);
if (local_entry)
batadv_tt_local_entry_free_ref(local_entry);
}
void batadv_tt_global_del_orig(struct batadv_priv *bat_priv,
struct batadv_orig_node *orig_node,
int32_t match_vid,
const char *message)
{
struct batadv_tt_global_entry *tt_global;
struct batadv_tt_common_entry *tt_common_entry;
uint32_t i;
struct batadv_hashtable *hash = bat_priv->tt.global_hash;
struct hlist_node *safe;
struct hlist_head *head;
spinlock_t *list_lock;
unsigned short vid;
if (!hash)
return;
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
list_lock = &hash->list_locks[i];
spin_lock_bh(list_lock);
hlist_for_each_entry_safe(tt_common_entry, safe,
head, hash_entry) {
if (match_vid >= 0 && tt_common_entry->vid != match_vid)
continue;
tt_global = container_of(tt_common_entry,
struct batadv_tt_global_entry,
common);
batadv_tt_global_del_orig_node(bat_priv, tt_global,
orig_node, message);
if (hlist_empty(&tt_global->orig_list)) {
vid = tt_global->common.vid;
batadv_dbg(BATADV_DBG_TT, bat_priv,
"Deleting global tt entry %pM (vid: %d): %s\n",
tt_global->common.addr,
BATADV_PRINT_VID(vid), message);
hlist_del_rcu(&tt_common_entry->hash_entry);
batadv_tt_global_entry_free_ref(tt_global);
}
}
spin_unlock_bh(list_lock);
}
orig_node->capa_initialized &= ~BATADV_ORIG_CAPA_HAS_TT;
}
static bool batadv_tt_global_to_purge(struct batadv_tt_global_entry *tt_global,
char **msg)
{
bool purge = false;
unsigned long roam_timeout = BATADV_TT_CLIENT_ROAM_TIMEOUT;
unsigned long temp_timeout = BATADV_TT_CLIENT_TEMP_TIMEOUT;
if ((tt_global->common.flags & BATADV_TT_CLIENT_ROAM) &&
batadv_has_timed_out(tt_global->roam_at, roam_timeout)) {
purge = true;
*msg = "Roaming timeout\n";
}
if ((tt_global->common.flags & BATADV_TT_CLIENT_TEMP) &&
batadv_has_timed_out(tt_global->common.added_at, temp_timeout)) {
purge = true;
*msg = "Temporary client timeout\n";
}
return purge;
}
static void batadv_tt_global_purge(struct batadv_priv *bat_priv)
{
struct batadv_hashtable *hash = bat_priv->tt.global_hash;
struct hlist_head *head;
struct hlist_node *node_tmp;
spinlock_t *list_lock;
uint32_t i;
char *msg = NULL;
struct batadv_tt_common_entry *tt_common;
struct batadv_tt_global_entry *tt_global;
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
list_lock = &hash->list_locks[i];
spin_lock_bh(list_lock);
hlist_for_each_entry_safe(tt_common, node_tmp, head,
hash_entry) {
tt_global = container_of(tt_common,
struct batadv_tt_global_entry,
common);
if (!batadv_tt_global_to_purge(tt_global, &msg))
continue;
batadv_dbg(BATADV_DBG_TT, bat_priv,
"Deleting global tt entry %pM (vid: %d): %s\n",
tt_global->common.addr,
BATADV_PRINT_VID(tt_global->common.vid),
msg);
hlist_del_rcu(&tt_common->hash_entry);
batadv_tt_global_entry_free_ref(tt_global);
}
spin_unlock_bh(list_lock);
}
}
static void batadv_tt_global_table_free(struct batadv_priv *bat_priv)
{
struct batadv_hashtable *hash;
spinlock_t *list_lock;
struct batadv_tt_common_entry *tt_common_entry;
struct batadv_tt_global_entry *tt_global;
struct hlist_node *node_tmp;
struct hlist_head *head;
uint32_t i;
if (!bat_priv->tt.global_hash)
return;
hash = bat_priv->tt.global_hash;
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
list_lock = &hash->list_locks[i];
spin_lock_bh(list_lock);
hlist_for_each_entry_safe(tt_common_entry, node_tmp,
head, hash_entry) {
hlist_del_rcu(&tt_common_entry->hash_entry);
tt_global = container_of(tt_common_entry,
struct batadv_tt_global_entry,
common);
batadv_tt_global_entry_free_ref(tt_global);
}
spin_unlock_bh(list_lock);
}
batadv_hash_destroy(hash);
bat_priv->tt.global_hash = NULL;
}
static bool
_batadv_is_ap_isolated(struct batadv_tt_local_entry *tt_local_entry,
struct batadv_tt_global_entry *tt_global_entry)
{
bool ret = false;
if (tt_local_entry->common.flags & BATADV_TT_CLIENT_WIFI &&
tt_global_entry->common.flags & BATADV_TT_CLIENT_WIFI)
ret = true;
if (tt_local_entry->common.flags & BATADV_TT_CLIENT_ISOLA &&
tt_global_entry->common.flags & BATADV_TT_CLIENT_ISOLA)
ret = true;
return ret;
}
struct batadv_orig_node *batadv_transtable_search(struct batadv_priv *bat_priv,
const uint8_t *src,
const uint8_t *addr,
unsigned short vid)
{
struct batadv_tt_local_entry *tt_local_entry = NULL;
struct batadv_tt_global_entry *tt_global_entry = NULL;
struct batadv_orig_node *orig_node = NULL;
struct batadv_tt_orig_list_entry *best_entry;
if (src && batadv_vlan_ap_isola_get(bat_priv, vid)) {
tt_local_entry = batadv_tt_local_hash_find(bat_priv, src, vid);
if (!tt_local_entry ||
(tt_local_entry->common.flags & BATADV_TT_CLIENT_PENDING))
goto out;
}
tt_global_entry = batadv_tt_global_hash_find(bat_priv, addr, vid);
if (!tt_global_entry)
goto out;
if (tt_local_entry &&
_batadv_is_ap_isolated(tt_local_entry, tt_global_entry))
goto out;
rcu_read_lock();
best_entry = batadv_transtable_best_orig(bat_priv, tt_global_entry);
if (best_entry)
orig_node = best_entry->orig_node;
if (orig_node && !atomic_inc_not_zero(&orig_node->refcount))
orig_node = NULL;
rcu_read_unlock();
out:
if (tt_global_entry)
batadv_tt_global_entry_free_ref(tt_global_entry);
if (tt_local_entry)
batadv_tt_local_entry_free_ref(tt_local_entry);
return orig_node;
}
static uint32_t batadv_tt_global_crc(struct batadv_priv *bat_priv,
struct batadv_orig_node *orig_node,
unsigned short vid)
{
struct batadv_hashtable *hash = bat_priv->tt.global_hash;
struct batadv_tt_common_entry *tt_common;
struct batadv_tt_global_entry *tt_global;
struct hlist_head *head;
uint32_t i, crc_tmp, crc = 0;
uint8_t flags;
__be16 tmp_vid;
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
rcu_read_lock();
hlist_for_each_entry_rcu(tt_common, head, hash_entry) {
tt_global = container_of(tt_common,
struct batadv_tt_global_entry,
common);
if (tt_common->vid != vid)
continue;
if (tt_common->flags & BATADV_TT_CLIENT_ROAM)
continue;
if (tt_common->flags & BATADV_TT_CLIENT_TEMP)
continue;
if (!batadv_tt_global_entry_has_orig(tt_global,
orig_node))
continue;
tmp_vid = htons(tt_common->vid);
crc_tmp = crc32c(0, &tmp_vid, sizeof(tmp_vid));
flags = tt_common->flags & BATADV_TT_SYNC_MASK;
crc_tmp = crc32c(crc_tmp, &flags, sizeof(flags));
crc ^= crc32c(crc_tmp, tt_common->addr, ETH_ALEN);
}
rcu_read_unlock();
}
return crc;
}
static uint32_t batadv_tt_local_crc(struct batadv_priv *bat_priv,
unsigned short vid)
{
struct batadv_hashtable *hash = bat_priv->tt.local_hash;
struct batadv_tt_common_entry *tt_common;
struct hlist_head *head;
uint32_t i, crc_tmp, crc = 0;
uint8_t flags;
__be16 tmp_vid;
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
rcu_read_lock();
hlist_for_each_entry_rcu(tt_common, head, hash_entry) {
if (tt_common->vid != vid)
continue;
if (tt_common->flags & BATADV_TT_CLIENT_NEW)
continue;
tmp_vid = htons(tt_common->vid);
crc_tmp = crc32c(0, &tmp_vid, sizeof(tmp_vid));
flags = tt_common->flags & BATADV_TT_SYNC_MASK;
crc_tmp = crc32c(crc_tmp, &flags, sizeof(flags));
crc ^= crc32c(crc_tmp, tt_common->addr, ETH_ALEN);
}
rcu_read_unlock();
}
return crc;
}
static void batadv_tt_req_list_free(struct batadv_priv *bat_priv)
{
struct batadv_tt_req_node *node, *safe;
spin_lock_bh(&bat_priv->tt.req_list_lock);
list_for_each_entry_safe(node, safe, &bat_priv->tt.req_list, list) {
list_del(&node->list);
kfree(node);
}
spin_unlock_bh(&bat_priv->tt.req_list_lock);
}
static void batadv_tt_save_orig_buffer(struct batadv_priv *bat_priv,
struct batadv_orig_node *orig_node,
const void *tt_buff,
uint16_t tt_buff_len)
{
spin_lock_bh(&orig_node->tt_buff_lock);
if (tt_buff_len > 0) {
kfree(orig_node->tt_buff);
orig_node->tt_buff_len = 0;
orig_node->tt_buff = kmalloc(tt_buff_len, GFP_ATOMIC);
if (orig_node->tt_buff) {
memcpy(orig_node->tt_buff, tt_buff, tt_buff_len);
orig_node->tt_buff_len = tt_buff_len;
}
}
spin_unlock_bh(&orig_node->tt_buff_lock);
}
static void batadv_tt_req_purge(struct batadv_priv *bat_priv)
{
struct batadv_tt_req_node *node, *safe;
spin_lock_bh(&bat_priv->tt.req_list_lock);
list_for_each_entry_safe(node, safe, &bat_priv->tt.req_list, list) {
if (batadv_has_timed_out(node->issued_at,
BATADV_TT_REQUEST_TIMEOUT)) {
list_del(&node->list);
kfree(node);
}
}
spin_unlock_bh(&bat_priv->tt.req_list_lock);
}
static struct batadv_tt_req_node *
batadv_new_tt_req_node(struct batadv_priv *bat_priv,
struct batadv_orig_node *orig_node)
{
struct batadv_tt_req_node *tt_req_node_tmp, *tt_req_node = NULL;
spin_lock_bh(&bat_priv->tt.req_list_lock);
list_for_each_entry(tt_req_node_tmp, &bat_priv->tt.req_list, list) {
if (batadv_compare_eth(tt_req_node_tmp, orig_node) &&
!batadv_has_timed_out(tt_req_node_tmp->issued_at,
BATADV_TT_REQUEST_TIMEOUT))
goto unlock;
}
tt_req_node = kmalloc(sizeof(*tt_req_node), GFP_ATOMIC);
if (!tt_req_node)
goto unlock;
ether_addr_copy(tt_req_node->addr, orig_node->orig);
tt_req_node->issued_at = jiffies;
list_add(&tt_req_node->list, &bat_priv->tt.req_list);
unlock:
spin_unlock_bh(&bat_priv->tt.req_list_lock);
return tt_req_node;
}
static int batadv_tt_local_valid(const void *entry_ptr, const void *data_ptr)
{
const struct batadv_tt_common_entry *tt_common_entry = entry_ptr;
if (tt_common_entry->flags & BATADV_TT_CLIENT_NEW)
return 0;
return 1;
}
static int batadv_tt_global_valid(const void *entry_ptr,
const void *data_ptr)
{
const struct batadv_tt_common_entry *tt_common_entry = entry_ptr;
const struct batadv_tt_global_entry *tt_global_entry;
const struct batadv_orig_node *orig_node = data_ptr;
if (tt_common_entry->flags & BATADV_TT_CLIENT_ROAM ||
tt_common_entry->flags & BATADV_TT_CLIENT_TEMP)
return 0;
tt_global_entry = container_of(tt_common_entry,
struct batadv_tt_global_entry,
common);
return batadv_tt_global_entry_has_orig(tt_global_entry, orig_node);
}
static void batadv_tt_tvlv_generate(struct batadv_priv *bat_priv,
struct batadv_hashtable *hash,
void *tvlv_buff, uint16_t tt_len,
int (*valid_cb)(const void *, const void *),
void *cb_data)
{
struct batadv_tt_common_entry *tt_common_entry;
struct batadv_tvlv_tt_change *tt_change;
struct hlist_head *head;
uint16_t tt_tot, tt_num_entries = 0;
uint32_t i;
tt_tot = batadv_tt_entries(tt_len);
tt_change = (struct batadv_tvlv_tt_change *)tvlv_buff;
rcu_read_lock();
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
hlist_for_each_entry_rcu(tt_common_entry,
head, hash_entry) {
if (tt_tot == tt_num_entries)
break;
if ((valid_cb) && (!valid_cb(tt_common_entry, cb_data)))
continue;
ether_addr_copy(tt_change->addr, tt_common_entry->addr);
tt_change->flags = tt_common_entry->flags;
tt_change->vid = htons(tt_common_entry->vid);
memset(tt_change->reserved, 0,
sizeof(tt_change->reserved));
tt_num_entries++;
tt_change++;
}
}
rcu_read_unlock();
}
static bool batadv_tt_global_check_crc(struct batadv_orig_node *orig_node,
struct batadv_tvlv_tt_vlan_data *tt_vlan,
uint16_t num_vlan)
{
struct batadv_tvlv_tt_vlan_data *tt_vlan_tmp;
struct batadv_orig_node_vlan *vlan;
uint32_t crc;
int i;
for (i = 0; i < num_vlan; i++) {
tt_vlan_tmp = tt_vlan + i;
if (batadv_bla_is_backbone_gw_orig(orig_node->bat_priv,
orig_node->orig,
ntohs(tt_vlan_tmp->vid)))
continue;
vlan = batadv_orig_node_vlan_get(orig_node,
ntohs(tt_vlan_tmp->vid));
if (!vlan)
return false;
crc = vlan->tt.crc;
batadv_orig_node_vlan_free_ref(vlan);
if (crc != ntohl(tt_vlan_tmp->crc))
return false;
}
return true;
}
static void batadv_tt_local_update_crc(struct batadv_priv *bat_priv)
{
struct batadv_softif_vlan *vlan;
rcu_read_lock();
hlist_for_each_entry_rcu(vlan, &bat_priv->softif_vlan_list, list) {
vlan->tt.crc = batadv_tt_local_crc(bat_priv, vlan->vid);
}
rcu_read_unlock();
}
static void batadv_tt_global_update_crc(struct batadv_priv *bat_priv,
struct batadv_orig_node *orig_node)
{
struct batadv_orig_node_vlan *vlan;
uint32_t crc;
rcu_read_lock();
list_for_each_entry_rcu(vlan, &orig_node->vlan_list, list) {
if (batadv_bla_is_backbone_gw_orig(bat_priv, orig_node->orig,
vlan->vid))
continue;
crc = batadv_tt_global_crc(bat_priv, orig_node, vlan->vid);
vlan->tt.crc = crc;
}
rcu_read_unlock();
}
static int batadv_send_tt_request(struct batadv_priv *bat_priv,
struct batadv_orig_node *dst_orig_node,
uint8_t ttvn,
struct batadv_tvlv_tt_vlan_data *tt_vlan,
uint16_t num_vlan, bool full_table)
{
struct batadv_tvlv_tt_data *tvlv_tt_data = NULL;
struct batadv_tt_req_node *tt_req_node = NULL;
struct batadv_tvlv_tt_vlan_data *tt_vlan_req;
struct batadv_hard_iface *primary_if;
bool ret = false;
int i, size;
primary_if = batadv_primary_if_get_selected(bat_priv);
if (!primary_if)
goto out;
tt_req_node = batadv_new_tt_req_node(bat_priv, dst_orig_node);
if (!tt_req_node)
goto out;
size = sizeof(*tvlv_tt_data) + sizeof(*tt_vlan_req) * num_vlan;
tvlv_tt_data = kzalloc(size, GFP_ATOMIC);
if (!tvlv_tt_data)
goto out;
tvlv_tt_data->flags = BATADV_TT_REQUEST;
tvlv_tt_data->ttvn = ttvn;
tvlv_tt_data->num_vlan = htons(num_vlan);
tt_vlan_req = (struct batadv_tvlv_tt_vlan_data *)(tvlv_tt_data + 1);
for (i = 0; i < num_vlan; i++) {
tt_vlan_req->vid = tt_vlan->vid;
tt_vlan_req->crc = tt_vlan->crc;
tt_vlan_req++;
tt_vlan++;
}
if (full_table)
tvlv_tt_data->flags |= BATADV_TT_FULL_TABLE;
batadv_dbg(BATADV_DBG_TT, bat_priv, "Sending TT_REQUEST to %pM [%c]\n",
dst_orig_node->orig, full_table ? 'F' : '.');
batadv_inc_counter(bat_priv, BATADV_CNT_TT_REQUEST_TX);
batadv_tvlv_unicast_send(bat_priv, primary_if->net_dev->dev_addr,
dst_orig_node->orig, BATADV_TVLV_TT, 1,
tvlv_tt_data, size);
ret = true;
out:
if (primary_if)
batadv_hardif_free_ref(primary_if);
if (ret && tt_req_node) {
spin_lock_bh(&bat_priv->tt.req_list_lock);
list_del(&tt_req_node->list);
spin_unlock_bh(&bat_priv->tt.req_list_lock);
kfree(tt_req_node);
}
kfree(tvlv_tt_data);
return ret;
}
static bool batadv_send_other_tt_response(struct batadv_priv *bat_priv,
struct batadv_tvlv_tt_data *tt_data,
uint8_t *req_src, uint8_t *req_dst)
{
struct batadv_orig_node *req_dst_orig_node;
struct batadv_orig_node *res_dst_orig_node = NULL;
struct batadv_tvlv_tt_change *tt_change;
struct batadv_tvlv_tt_data *tvlv_tt_data = NULL;
struct batadv_tvlv_tt_vlan_data *tt_vlan;
bool ret = false, full_table;
uint8_t orig_ttvn, req_ttvn;
uint16_t tvlv_len;
int32_t tt_len;
batadv_dbg(BATADV_DBG_TT, bat_priv,
"Received TT_REQUEST from %pM for ttvn: %u (%pM) [%c]\n",
req_src, tt_data->ttvn, req_dst,
(tt_data->flags & BATADV_TT_FULL_TABLE ? 'F' : '.'));
req_dst_orig_node = batadv_orig_hash_find(bat_priv, req_dst);
if (!req_dst_orig_node)
goto out;
res_dst_orig_node = batadv_orig_hash_find(bat_priv, req_src);
if (!res_dst_orig_node)
goto out;
orig_ttvn = (uint8_t)atomic_read(&req_dst_orig_node->last_ttvn);
req_ttvn = tt_data->ttvn;
tt_vlan = (struct batadv_tvlv_tt_vlan_data *)(tt_data + 1);
if (orig_ttvn != req_ttvn ||
!batadv_tt_global_check_crc(req_dst_orig_node, tt_vlan,
ntohs(tt_data->num_vlan)))
goto out;
if (tt_data->flags & BATADV_TT_FULL_TABLE ||
!req_dst_orig_node->tt_buff)
full_table = true;
else
full_table = false;
if (!full_table) {
spin_lock_bh(&req_dst_orig_node->tt_buff_lock);
tt_len = req_dst_orig_node->tt_buff_len;
tvlv_len = batadv_tt_prepare_tvlv_global_data(req_dst_orig_node,
&tvlv_tt_data,
&tt_change,
&tt_len);
if (!tt_len)
goto unlock;
memcpy(tt_change, req_dst_orig_node->tt_buff,
req_dst_orig_node->tt_buff_len);
spin_unlock_bh(&req_dst_orig_node->tt_buff_lock);
} else {
tt_len = -1;
tvlv_len = batadv_tt_prepare_tvlv_global_data(req_dst_orig_node,
&tvlv_tt_data,
&tt_change,
&tt_len);
if (!tt_len)
goto out;
batadv_tt_tvlv_generate(bat_priv, bat_priv->tt.global_hash,
tt_change, tt_len,
batadv_tt_global_valid,
req_dst_orig_node);
}
tt_len = sizeof(struct batadv_unicast_tvlv_packet) + tvlv_len;
if (tt_len > atomic_read(&bat_priv->packet_size_max)) {
net_ratelimited_function(batadv_info, bat_priv->soft_iface,
"Ignoring TT_REQUEST from %pM; Response size exceeds max packet size.\n",
res_dst_orig_node->orig);
goto out;
}
tvlv_tt_data->flags = BATADV_TT_RESPONSE;
tvlv_tt_data->ttvn = req_ttvn;
if (full_table)
tvlv_tt_data->flags |= BATADV_TT_FULL_TABLE;
batadv_dbg(BATADV_DBG_TT, bat_priv,
"Sending TT_RESPONSE %pM for %pM [%c] (ttvn: %u)\n",
res_dst_orig_node->orig, req_dst_orig_node->orig,
full_table ? 'F' : '.', req_ttvn);
batadv_inc_counter(bat_priv, BATADV_CNT_TT_RESPONSE_TX);
batadv_tvlv_unicast_send(bat_priv, req_dst_orig_node->orig,
req_src, BATADV_TVLV_TT, 1, tvlv_tt_data,
tvlv_len);
ret = true;
goto out;
unlock:
spin_unlock_bh(&req_dst_orig_node->tt_buff_lock);
out:
if (res_dst_orig_node)
batadv_orig_node_free_ref(res_dst_orig_node);
if (req_dst_orig_node)
batadv_orig_node_free_ref(req_dst_orig_node);
kfree(tvlv_tt_data);
return ret;
}
static bool batadv_send_my_tt_response(struct batadv_priv *bat_priv,
struct batadv_tvlv_tt_data *tt_data,
uint8_t *req_src)
{
struct batadv_tvlv_tt_data *tvlv_tt_data = NULL;
struct batadv_hard_iface *primary_if = NULL;
struct batadv_tvlv_tt_change *tt_change;
struct batadv_orig_node *orig_node;
uint8_t my_ttvn, req_ttvn;
uint16_t tvlv_len;
bool full_table;
int32_t tt_len;
batadv_dbg(BATADV_DBG_TT, bat_priv,
"Received TT_REQUEST from %pM for ttvn: %u (me) [%c]\n",
req_src, tt_data->ttvn,
(tt_data->flags & BATADV_TT_FULL_TABLE ? 'F' : '.'));
spin_lock_bh(&bat_priv->tt.commit_lock);
my_ttvn = (uint8_t)atomic_read(&bat_priv->tt.vn);
req_ttvn = tt_data->ttvn;
orig_node = batadv_orig_hash_find(bat_priv, req_src);
if (!orig_node)
goto out;
primary_if = batadv_primary_if_get_selected(bat_priv);
if (!primary_if)
goto out;
if (tt_data->flags & BATADV_TT_FULL_TABLE || my_ttvn != req_ttvn ||
!bat_priv->tt.last_changeset)
full_table = true;
else
full_table = false;
if (!full_table) {
spin_lock_bh(&bat_priv->tt.last_changeset_lock);
tt_len = bat_priv->tt.last_changeset_len;
tvlv_len = batadv_tt_prepare_tvlv_local_data(bat_priv,
&tvlv_tt_data,
&tt_change,
&tt_len);
if (!tt_len)
goto unlock;
memcpy(tt_change, bat_priv->tt.last_changeset,
bat_priv->tt.last_changeset_len);
spin_unlock_bh(&bat_priv->tt.last_changeset_lock);
} else {
req_ttvn = (uint8_t)atomic_read(&bat_priv->tt.vn);
tt_len = -1;
tvlv_len = batadv_tt_prepare_tvlv_local_data(bat_priv,
&tvlv_tt_data,
&tt_change,
&tt_len);
if (!tt_len)
goto out;
batadv_tt_tvlv_generate(bat_priv, bat_priv->tt.local_hash,
tt_change, tt_len,
batadv_tt_local_valid, NULL);
}
tvlv_tt_data->flags = BATADV_TT_RESPONSE;
tvlv_tt_data->ttvn = req_ttvn;
if (full_table)
tvlv_tt_data->flags |= BATADV_TT_FULL_TABLE;
batadv_dbg(BATADV_DBG_TT, bat_priv,
"Sending TT_RESPONSE to %pM [%c] (ttvn: %u)\n",
orig_node->orig, full_table ? 'F' : '.', req_ttvn);
batadv_inc_counter(bat_priv, BATADV_CNT_TT_RESPONSE_TX);
batadv_tvlv_unicast_send(bat_priv, primary_if->net_dev->dev_addr,
req_src, BATADV_TVLV_TT, 1, tvlv_tt_data,
tvlv_len);
goto out;
unlock:
spin_unlock_bh(&bat_priv->tt.last_changeset_lock);
out:
spin_unlock_bh(&bat_priv->tt.commit_lock);
if (orig_node)
batadv_orig_node_free_ref(orig_node);
if (primary_if)
batadv_hardif_free_ref(primary_if);
kfree(tvlv_tt_data);
return true;
}
static bool batadv_send_tt_response(struct batadv_priv *bat_priv,
struct batadv_tvlv_tt_data *tt_data,
uint8_t *req_src, uint8_t *req_dst)
{
if (batadv_is_my_mac(bat_priv, req_dst))
return batadv_send_my_tt_response(bat_priv, tt_data, req_src);
else
return batadv_send_other_tt_response(bat_priv, tt_data,
req_src, req_dst);
}
static void _batadv_tt_update_changes(struct batadv_priv *bat_priv,
struct batadv_orig_node *orig_node,
struct batadv_tvlv_tt_change *tt_change,
uint16_t tt_num_changes, uint8_t ttvn)
{
int i;
int roams;
for (i = 0; i < tt_num_changes; i++) {
if ((tt_change + i)->flags & BATADV_TT_CLIENT_DEL) {
roams = (tt_change + i)->flags & BATADV_TT_CLIENT_ROAM;
batadv_tt_global_del(bat_priv, orig_node,
(tt_change + i)->addr,
ntohs((tt_change + i)->vid),
"tt removed by changes",
roams);
} else {
if (!batadv_tt_global_add(bat_priv, orig_node,
(tt_change + i)->addr,
ntohs((tt_change + i)->vid),
(tt_change + i)->flags, ttvn))
return;
}
}
orig_node->capa_initialized |= BATADV_ORIG_CAPA_HAS_TT;
}
static void batadv_tt_fill_gtable(struct batadv_priv *bat_priv,
struct batadv_tvlv_tt_change *tt_change,
uint8_t ttvn, uint8_t *resp_src,
uint16_t num_entries)
{
struct batadv_orig_node *orig_node;
orig_node = batadv_orig_hash_find(bat_priv, resp_src);
if (!orig_node)
goto out;
batadv_tt_global_del_orig(bat_priv, orig_node, -1,
"Received full table");
_batadv_tt_update_changes(bat_priv, orig_node, tt_change, num_entries,
ttvn);
spin_lock_bh(&orig_node->tt_buff_lock);
kfree(orig_node->tt_buff);
orig_node->tt_buff_len = 0;
orig_node->tt_buff = NULL;
spin_unlock_bh(&orig_node->tt_buff_lock);
atomic_set(&orig_node->last_ttvn, ttvn);
out:
if (orig_node)
batadv_orig_node_free_ref(orig_node);
}
static void batadv_tt_update_changes(struct batadv_priv *bat_priv,
struct batadv_orig_node *orig_node,
uint16_t tt_num_changes, uint8_t ttvn,
struct batadv_tvlv_tt_change *tt_change)
{
_batadv_tt_update_changes(bat_priv, orig_node, tt_change,
tt_num_changes, ttvn);
batadv_tt_save_orig_buffer(bat_priv, orig_node, tt_change,
batadv_tt_len(tt_num_changes));
atomic_set(&orig_node->last_ttvn, ttvn);
}
bool batadv_is_my_client(struct batadv_priv *bat_priv, const uint8_t *addr,
unsigned short vid)
{
struct batadv_tt_local_entry *tt_local_entry;
bool ret = false;
tt_local_entry = batadv_tt_local_hash_find(bat_priv, addr, vid);
if (!tt_local_entry)
goto out;
if ((tt_local_entry->common.flags & BATADV_TT_CLIENT_PENDING) ||
(tt_local_entry->common.flags & BATADV_TT_CLIENT_ROAM))
goto out;
ret = true;
out:
if (tt_local_entry)
batadv_tt_local_entry_free_ref(tt_local_entry);
return ret;
}
static void batadv_handle_tt_response(struct batadv_priv *bat_priv,
struct batadv_tvlv_tt_data *tt_data,
uint8_t *resp_src, uint16_t num_entries)
{
struct batadv_tt_req_node *node, *safe;
struct batadv_orig_node *orig_node = NULL;
struct batadv_tvlv_tt_change *tt_change;
uint8_t *tvlv_ptr = (uint8_t *)tt_data;
uint16_t change_offset;
batadv_dbg(BATADV_DBG_TT, bat_priv,
"Received TT_RESPONSE from %pM for ttvn %d t_size: %d [%c]\n",
resp_src, tt_data->ttvn, num_entries,
(tt_data->flags & BATADV_TT_FULL_TABLE ? 'F' : '.'));
orig_node = batadv_orig_hash_find(bat_priv, resp_src);
if (!orig_node)
goto out;
spin_lock_bh(&orig_node->tt_lock);
change_offset = sizeof(struct batadv_tvlv_tt_vlan_data);
change_offset *= ntohs(tt_data->num_vlan);
change_offset += sizeof(*tt_data);
tvlv_ptr += change_offset;
tt_change = (struct batadv_tvlv_tt_change *)tvlv_ptr;
if (tt_data->flags & BATADV_TT_FULL_TABLE) {
batadv_tt_fill_gtable(bat_priv, tt_change, tt_data->ttvn,
resp_src, num_entries);
} else {
batadv_tt_update_changes(bat_priv, orig_node, num_entries,
tt_data->ttvn, tt_change);
}
batadv_tt_global_update_crc(bat_priv, orig_node);
spin_unlock_bh(&orig_node->tt_lock);
spin_lock_bh(&bat_priv->tt.req_list_lock);
list_for_each_entry_safe(node, safe, &bat_priv->tt.req_list, list) {
if (!batadv_compare_eth(node->addr, resp_src))
continue;
list_del(&node->list);
kfree(node);
}
spin_unlock_bh(&bat_priv->tt.req_list_lock);
out:
if (orig_node)
batadv_orig_node_free_ref(orig_node);
}
static void batadv_tt_roam_list_free(struct batadv_priv *bat_priv)
{
struct batadv_tt_roam_node *node, *safe;
spin_lock_bh(&bat_priv->tt.roam_list_lock);
list_for_each_entry_safe(node, safe, &bat_priv->tt.roam_list, list) {
list_del(&node->list);
kfree(node);
}
spin_unlock_bh(&bat_priv->tt.roam_list_lock);
}
static void batadv_tt_roam_purge(struct batadv_priv *bat_priv)
{
struct batadv_tt_roam_node *node, *safe;
spin_lock_bh(&bat_priv->tt.roam_list_lock);
list_for_each_entry_safe(node, safe, &bat_priv->tt.roam_list, list) {
if (!batadv_has_timed_out(node->first_time,
BATADV_ROAMING_MAX_TIME))
continue;
list_del(&node->list);
kfree(node);
}
spin_unlock_bh(&bat_priv->tt.roam_list_lock);
}
static bool batadv_tt_check_roam_count(struct batadv_priv *bat_priv,
uint8_t *client)
{
struct batadv_tt_roam_node *tt_roam_node;
bool ret = false;
spin_lock_bh(&bat_priv->tt.roam_list_lock);
list_for_each_entry(tt_roam_node, &bat_priv->tt.roam_list, list) {
if (!batadv_compare_eth(tt_roam_node->addr, client))
continue;
if (batadv_has_timed_out(tt_roam_node->first_time,
BATADV_ROAMING_MAX_TIME))
continue;
if (!batadv_atomic_dec_not_zero(&tt_roam_node->counter))
goto unlock;
ret = true;
break;
}
if (!ret) {
tt_roam_node = kmalloc(sizeof(*tt_roam_node), GFP_ATOMIC);
if (!tt_roam_node)
goto unlock;
tt_roam_node->first_time = jiffies;
atomic_set(&tt_roam_node->counter,
BATADV_ROAMING_MAX_COUNT - 1);
ether_addr_copy(tt_roam_node->addr, client);
list_add(&tt_roam_node->list, &bat_priv->tt.roam_list);
ret = true;
}
unlock:
spin_unlock_bh(&bat_priv->tt.roam_list_lock);
return ret;
}
static void batadv_send_roam_adv(struct batadv_priv *bat_priv, uint8_t *client,
unsigned short vid,
struct batadv_orig_node *orig_node)
{
struct batadv_hard_iface *primary_if;
struct batadv_tvlv_roam_adv tvlv_roam;
primary_if = batadv_primary_if_get_selected(bat_priv);
if (!primary_if)
goto out;
if (!batadv_tt_check_roam_count(bat_priv, client))
goto out;
batadv_dbg(BATADV_DBG_TT, bat_priv,
"Sending ROAMING_ADV to %pM (client %pM, vid: %d)\n",
orig_node->orig, client, BATADV_PRINT_VID(vid));
batadv_inc_counter(bat_priv, BATADV_CNT_TT_ROAM_ADV_TX);
memcpy(tvlv_roam.client, client, sizeof(tvlv_roam.client));
tvlv_roam.vid = htons(vid);
batadv_tvlv_unicast_send(bat_priv, primary_if->net_dev->dev_addr,
orig_node->orig, BATADV_TVLV_ROAM, 1,
&tvlv_roam, sizeof(tvlv_roam));
out:
if (primary_if)
batadv_hardif_free_ref(primary_if);
}
static void batadv_tt_purge(struct work_struct *work)
{
struct delayed_work *delayed_work;
struct batadv_priv_tt *priv_tt;
struct batadv_priv *bat_priv;
delayed_work = container_of(work, struct delayed_work, work);
priv_tt = container_of(delayed_work, struct batadv_priv_tt, work);
bat_priv = container_of(priv_tt, struct batadv_priv, tt);
batadv_tt_local_purge(bat_priv, BATADV_TT_LOCAL_TIMEOUT);
batadv_tt_global_purge(bat_priv);
batadv_tt_req_purge(bat_priv);
batadv_tt_roam_purge(bat_priv);
queue_delayed_work(batadv_event_workqueue, &bat_priv->tt.work,
msecs_to_jiffies(BATADV_TT_WORK_PERIOD));
}
void batadv_tt_free(struct batadv_priv *bat_priv)
{
batadv_tvlv_container_unregister(bat_priv, BATADV_TVLV_TT, 1);
batadv_tvlv_handler_unregister(bat_priv, BATADV_TVLV_TT, 1);
cancel_delayed_work_sync(&bat_priv->tt.work);
batadv_tt_local_table_free(bat_priv);
batadv_tt_global_table_free(bat_priv);
batadv_tt_req_list_free(bat_priv);
batadv_tt_changes_list_free(bat_priv);
batadv_tt_roam_list_free(bat_priv);
kfree(bat_priv->tt.last_changeset);
}
static void batadv_tt_local_set_flags(struct batadv_priv *bat_priv,
uint16_t flags, bool enable, bool count)
{
struct batadv_hashtable *hash = bat_priv->tt.local_hash;
struct batadv_tt_common_entry *tt_common_entry;
uint16_t changed_num = 0;
struct hlist_head *head;
uint32_t i;
if (!hash)
return;
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
rcu_read_lock();
hlist_for_each_entry_rcu(tt_common_entry,
head, hash_entry) {
if (enable) {
if ((tt_common_entry->flags & flags) == flags)
continue;
tt_common_entry->flags |= flags;
} else {
if (!(tt_common_entry->flags & flags))
continue;
tt_common_entry->flags &= ~flags;
}
changed_num++;
if (!count)
continue;
batadv_tt_local_size_inc(bat_priv,
tt_common_entry->vid);
}
rcu_read_unlock();
}
}
static void batadv_tt_local_purge_pending_clients(struct batadv_priv *bat_priv)
{
struct batadv_hashtable *hash = bat_priv->tt.local_hash;
struct batadv_tt_common_entry *tt_common;
struct batadv_tt_local_entry *tt_local;
struct hlist_node *node_tmp;
struct hlist_head *head;
spinlock_t *list_lock;
uint32_t i;
if (!hash)
return;
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
list_lock = &hash->list_locks[i];
spin_lock_bh(list_lock);
hlist_for_each_entry_safe(tt_common, node_tmp, head,
hash_entry) {
if (!(tt_common->flags & BATADV_TT_CLIENT_PENDING))
continue;
batadv_dbg(BATADV_DBG_TT, bat_priv,
"Deleting local tt entry (%pM, vid: %d): pending\n",
tt_common->addr,
BATADV_PRINT_VID(tt_common->vid));
batadv_tt_local_size_dec(bat_priv, tt_common->vid);
hlist_del_rcu(&tt_common->hash_entry);
tt_local = container_of(tt_common,
struct batadv_tt_local_entry,
common);
batadv_tt_local_entry_free_ref(tt_local);
}
spin_unlock_bh(list_lock);
}
}
static void batadv_tt_local_commit_changes_nolock(struct batadv_priv *bat_priv)
{
batadv_mcast_mla_update(bat_priv);
if (atomic_read(&bat_priv->tt.local_changes) < 1) {
if (!batadv_atomic_dec_not_zero(&bat_priv->tt.ogm_append_cnt))
batadv_tt_tvlv_container_update(bat_priv);
return;
}
batadv_tt_local_set_flags(bat_priv, BATADV_TT_CLIENT_NEW, false, true);
batadv_tt_local_purge_pending_clients(bat_priv);
batadv_tt_local_update_crc(bat_priv);
atomic_inc(&bat_priv->tt.vn);
batadv_dbg(BATADV_DBG_TT, bat_priv,
"Local changes committed, updating to ttvn %u\n",
(uint8_t)atomic_read(&bat_priv->tt.vn));
atomic_set(&bat_priv->tt.ogm_append_cnt, BATADV_TT_OGM_APPEND_MAX);
batadv_tt_tvlv_container_update(bat_priv);
}
void batadv_tt_local_commit_changes(struct batadv_priv *bat_priv)
{
spin_lock_bh(&bat_priv->tt.commit_lock);
batadv_tt_local_commit_changes_nolock(bat_priv);
spin_unlock_bh(&bat_priv->tt.commit_lock);
}
bool batadv_is_ap_isolated(struct batadv_priv *bat_priv, uint8_t *src,
uint8_t *dst, unsigned short vid)
{
struct batadv_tt_local_entry *tt_local_entry = NULL;
struct batadv_tt_global_entry *tt_global_entry = NULL;
struct batadv_softif_vlan *vlan;
bool ret = false;
vlan = batadv_softif_vlan_get(bat_priv, vid);
if (!vlan || !atomic_read(&vlan->ap_isolation))
goto out;
tt_local_entry = batadv_tt_local_hash_find(bat_priv, dst, vid);
if (!tt_local_entry)
goto out;
tt_global_entry = batadv_tt_global_hash_find(bat_priv, src, vid);
if (!tt_global_entry)
goto out;
if (!_batadv_is_ap_isolated(tt_local_entry, tt_global_entry))
goto out;
ret = true;
out:
if (vlan)
batadv_softif_vlan_free_ref(vlan);
if (tt_global_entry)
batadv_tt_global_entry_free_ref(tt_global_entry);
if (tt_local_entry)
batadv_tt_local_entry_free_ref(tt_local_entry);
return ret;
}
static void batadv_tt_update_orig(struct batadv_priv *bat_priv,
struct batadv_orig_node *orig_node,
const void *tt_buff, uint16_t tt_num_vlan,
struct batadv_tvlv_tt_change *tt_change,
uint16_t tt_num_changes, uint8_t ttvn)
{
uint8_t orig_ttvn = (uint8_t)atomic_read(&orig_node->last_ttvn);
struct batadv_tvlv_tt_vlan_data *tt_vlan;
bool full_table = true;
bool has_tt_init;
tt_vlan = (struct batadv_tvlv_tt_vlan_data *)tt_buff;
has_tt_init = orig_node->capa_initialized & BATADV_ORIG_CAPA_HAS_TT;
if ((!has_tt_init && ttvn == 1) || ttvn - orig_ttvn == 1) {
if (!tt_num_changes) {
full_table = false;
goto request_table;
}
spin_lock_bh(&orig_node->tt_lock);
batadv_tt_update_changes(bat_priv, orig_node, tt_num_changes,
ttvn, tt_change);
batadv_tt_global_update_crc(bat_priv, orig_node);
spin_unlock_bh(&orig_node->tt_lock);
if (!batadv_tt_global_check_crc(orig_node, tt_vlan,
tt_num_vlan))
goto request_table;
} else {
if (!has_tt_init || ttvn != orig_ttvn ||
!batadv_tt_global_check_crc(orig_node, tt_vlan,
tt_num_vlan)) {
request_table:
batadv_dbg(BATADV_DBG_TT, bat_priv,
"TT inconsistency for %pM. Need to retrieve the correct information (ttvn: %u last_ttvn: %u num_changes: %u)\n",
orig_node->orig, ttvn, orig_ttvn,
tt_num_changes);
batadv_send_tt_request(bat_priv, orig_node, ttvn,
tt_vlan, tt_num_vlan,
full_table);
return;
}
}
}
bool batadv_tt_global_client_is_roaming(struct batadv_priv *bat_priv,
uint8_t *addr, unsigned short vid)
{
struct batadv_tt_global_entry *tt_global_entry;
bool ret = false;
tt_global_entry = batadv_tt_global_hash_find(bat_priv, addr, vid);
if (!tt_global_entry)
goto out;
ret = tt_global_entry->common.flags & BATADV_TT_CLIENT_ROAM;
batadv_tt_global_entry_free_ref(tt_global_entry);
out:
return ret;
}
bool batadv_tt_local_client_is_roaming(struct batadv_priv *bat_priv,
uint8_t *addr, unsigned short vid)
{
struct batadv_tt_local_entry *tt_local_entry;
bool ret = false;
tt_local_entry = batadv_tt_local_hash_find(bat_priv, addr, vid);
if (!tt_local_entry)
goto out;
ret = tt_local_entry->common.flags & BATADV_TT_CLIENT_ROAM;
batadv_tt_local_entry_free_ref(tt_local_entry);
out:
return ret;
}
bool batadv_tt_add_temporary_global_entry(struct batadv_priv *bat_priv,
struct batadv_orig_node *orig_node,
const unsigned char *addr,
unsigned short vid)
{
bool ret = false;
if (!batadv_tt_global_add(bat_priv, orig_node, addr, vid,
BATADV_TT_CLIENT_TEMP,
atomic_read(&orig_node->last_ttvn)))
goto out;
batadv_dbg(BATADV_DBG_TT, bat_priv,
"Added temporary global client (addr: %pM, vid: %d, orig: %pM)\n",
addr, BATADV_PRINT_VID(vid), orig_node->orig);
ret = true;
out:
return ret;
}
void batadv_tt_local_resize_to_mtu(struct net_device *soft_iface)
{
struct batadv_priv *bat_priv = netdev_priv(soft_iface);
int packet_size_max = atomic_read(&bat_priv->packet_size_max);
int table_size, timeout = BATADV_TT_LOCAL_TIMEOUT / 2;
bool reduced = false;
spin_lock_bh(&bat_priv->tt.commit_lock);
while (true) {
table_size = batadv_tt_local_table_transmit_size(bat_priv);
if (packet_size_max >= table_size)
break;
batadv_tt_local_purge(bat_priv, timeout);
batadv_tt_local_purge_pending_clients(bat_priv);
timeout /= 2;
reduced = true;
net_ratelimited_function(batadv_info, soft_iface,
"Forced to purge local tt entries to fit new maximum fragment MTU (%i)\n",
packet_size_max);
}
if (reduced)
batadv_tt_local_commit_changes_nolock(bat_priv);
spin_unlock_bh(&bat_priv->tt.commit_lock);
}
static void batadv_tt_tvlv_ogm_handler_v1(struct batadv_priv *bat_priv,
struct batadv_orig_node *orig,
uint8_t flags, void *tvlv_value,
uint16_t tvlv_value_len)
{
struct batadv_tvlv_tt_vlan_data *tt_vlan;
struct batadv_tvlv_tt_change *tt_change;
struct batadv_tvlv_tt_data *tt_data;
uint16_t num_entries, num_vlan;
if (tvlv_value_len < sizeof(*tt_data))
return;
tt_data = (struct batadv_tvlv_tt_data *)tvlv_value;
tvlv_value_len -= sizeof(*tt_data);
num_vlan = ntohs(tt_data->num_vlan);
if (tvlv_value_len < sizeof(*tt_vlan) * num_vlan)
return;
tt_vlan = (struct batadv_tvlv_tt_vlan_data *)(tt_data + 1);
tt_change = (struct batadv_tvlv_tt_change *)(tt_vlan + num_vlan);
tvlv_value_len -= sizeof(*tt_vlan) * num_vlan;
num_entries = batadv_tt_entries(tvlv_value_len);
batadv_tt_update_orig(bat_priv, orig, tt_vlan, num_vlan, tt_change,
num_entries, tt_data->ttvn);
}
static int batadv_tt_tvlv_unicast_handler_v1(struct batadv_priv *bat_priv,
uint8_t *src, uint8_t *dst,
void *tvlv_value,
uint16_t tvlv_value_len)
{
struct batadv_tvlv_tt_data *tt_data;
uint16_t tt_vlan_len, tt_num_entries;
char tt_flag;
bool ret;
if (tvlv_value_len < sizeof(*tt_data))
return NET_RX_SUCCESS;
tt_data = (struct batadv_tvlv_tt_data *)tvlv_value;
tvlv_value_len -= sizeof(*tt_data);
tt_vlan_len = sizeof(struct batadv_tvlv_tt_vlan_data);
tt_vlan_len *= ntohs(tt_data->num_vlan);
if (tvlv_value_len < tt_vlan_len)
return NET_RX_SUCCESS;
tvlv_value_len -= tt_vlan_len;
tt_num_entries = batadv_tt_entries(tvlv_value_len);
switch (tt_data->flags & BATADV_TT_DATA_TYPE_MASK) {
case BATADV_TT_REQUEST:
batadv_inc_counter(bat_priv, BATADV_CNT_TT_REQUEST_RX);
ret = batadv_send_tt_response(bat_priv, tt_data, src, dst);
if (!ret) {
if (tt_data->flags & BATADV_TT_FULL_TABLE)
tt_flag = 'F';
else
tt_flag = '.';
batadv_dbg(BATADV_DBG_TT, bat_priv,
"Routing TT_REQUEST to %pM [%c]\n",
dst, tt_flag);
return NET_RX_DROP;
}
break;
case BATADV_TT_RESPONSE:
batadv_inc_counter(bat_priv, BATADV_CNT_TT_RESPONSE_RX);
if (batadv_is_my_mac(bat_priv, dst)) {
batadv_handle_tt_response(bat_priv, tt_data,
src, tt_num_entries);
return NET_RX_SUCCESS;
}
if (tt_data->flags & BATADV_TT_FULL_TABLE)
tt_flag = 'F';
else
tt_flag = '.';
batadv_dbg(BATADV_DBG_TT, bat_priv,
"Routing TT_RESPONSE to %pM [%c]\n", dst, tt_flag);
return NET_RX_DROP;
}
return NET_RX_SUCCESS;
}
static int batadv_roam_tvlv_unicast_handler_v1(struct batadv_priv *bat_priv,
uint8_t *src, uint8_t *dst,
void *tvlv_value,
uint16_t tvlv_value_len)
{
struct batadv_tvlv_roam_adv *roaming_adv;
struct batadv_orig_node *orig_node = NULL;
if (!batadv_is_my_mac(bat_priv, dst))
return NET_RX_DROP;
if (tvlv_value_len < sizeof(*roaming_adv))
goto out;
orig_node = batadv_orig_hash_find(bat_priv, src);
if (!orig_node)
goto out;
batadv_inc_counter(bat_priv, BATADV_CNT_TT_ROAM_ADV_RX);
roaming_adv = (struct batadv_tvlv_roam_adv *)tvlv_value;
batadv_dbg(BATADV_DBG_TT, bat_priv,
"Received ROAMING_ADV from %pM (client %pM)\n",
src, roaming_adv->client);
batadv_tt_global_add(bat_priv, orig_node, roaming_adv->client,
ntohs(roaming_adv->vid), BATADV_TT_CLIENT_ROAM,
atomic_read(&orig_node->last_ttvn) + 1);
out:
if (orig_node)
batadv_orig_node_free_ref(orig_node);
return NET_RX_SUCCESS;
}
int batadv_tt_init(struct batadv_priv *bat_priv)
{
int ret;
BUILD_BUG_ON(!(BATADV_TT_SYNC_MASK & BATADV_TT_REMOTE_MASK));
ret = batadv_tt_local_init(bat_priv);
if (ret < 0)
return ret;
ret = batadv_tt_global_init(bat_priv);
if (ret < 0)
return ret;
batadv_tvlv_handler_register(bat_priv, batadv_tt_tvlv_ogm_handler_v1,
batadv_tt_tvlv_unicast_handler_v1,
BATADV_TVLV_TT, 1, BATADV_NO_FLAGS);
batadv_tvlv_handler_register(bat_priv, NULL,
batadv_roam_tvlv_unicast_handler_v1,
BATADV_TVLV_ROAM, 1, BATADV_NO_FLAGS);
INIT_DELAYED_WORK(&bat_priv->tt.work, batadv_tt_purge);
queue_delayed_work(batadv_event_workqueue, &bat_priv->tt.work,
msecs_to_jiffies(BATADV_TT_WORK_PERIOD));
return 1;
}
bool batadv_tt_global_is_isolated(struct batadv_priv *bat_priv,
const uint8_t *addr, unsigned short vid)
{
struct batadv_tt_global_entry *tt;
bool ret;
tt = batadv_tt_global_hash_find(bat_priv, addr, vid);
if (!tt)
return false;
ret = tt->common.flags & BATADV_TT_CLIENT_ISOLA;
batadv_tt_global_entry_free_ref(tt);
return ret;
}
