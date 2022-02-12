static int batadv_compare_tt(const struct hlist_node *node, const void *data2)
{
const void *data1 = container_of(node, struct batadv_tt_common_entry,
hash_entry);
return (memcmp(data1, data2, ETH_ALEN) == 0 ? 1 : 0);
}
static struct batadv_tt_common_entry *
batadv_tt_hash_find(struct batadv_hashtable *hash, const void *data)
{
struct hlist_head *head;
struct batadv_tt_common_entry *tt_common_entry;
struct batadv_tt_common_entry *tt_common_entry_tmp = NULL;
uint32_t index;
if (!hash)
return NULL;
index = batadv_choose_orig(data, hash->size);
head = &hash->table[index];
rcu_read_lock();
hlist_for_each_entry_rcu(tt_common_entry, head, hash_entry) {
if (!batadv_compare_eth(tt_common_entry, data))
continue;
if (!atomic_inc_not_zero(&tt_common_entry->refcount))
continue;
tt_common_entry_tmp = tt_common_entry;
break;
}
rcu_read_unlock();
return tt_common_entry_tmp;
}
static struct batadv_tt_local_entry *
batadv_tt_local_hash_find(struct batadv_priv *bat_priv, const void *data)
{
struct batadv_tt_common_entry *tt_common_entry;
struct batadv_tt_local_entry *tt_local_entry = NULL;
tt_common_entry = batadv_tt_hash_find(bat_priv->tt.local_hash, data);
if (tt_common_entry)
tt_local_entry = container_of(tt_common_entry,
struct batadv_tt_local_entry,
common);
return tt_local_entry;
}
static struct batadv_tt_global_entry *
batadv_tt_global_hash_find(struct batadv_priv *bat_priv, const void *data)
{
struct batadv_tt_common_entry *tt_common_entry;
struct batadv_tt_global_entry *tt_global_entry = NULL;
tt_common_entry = batadv_tt_hash_find(bat_priv->tt.global_hash, data);
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
static void batadv_tt_global_entry_free_rcu(struct rcu_head *rcu)
{
struct batadv_tt_common_entry *tt_common_entry;
struct batadv_tt_global_entry *tt_global_entry;
tt_common_entry = container_of(rcu, struct batadv_tt_common_entry, rcu);
tt_global_entry = container_of(tt_common_entry,
struct batadv_tt_global_entry, common);
kfree(tt_global_entry);
}
static void
batadv_tt_global_entry_free_ref(struct batadv_tt_global_entry *tt_global_entry)
{
if (atomic_dec_and_test(&tt_global_entry->common.refcount)) {
batadv_tt_global_del_orig_list(tt_global_entry);
call_rcu(&tt_global_entry->common.rcu,
batadv_tt_global_entry_free_rcu);
}
}
static void batadv_tt_orig_list_entry_free_rcu(struct rcu_head *rcu)
{
struct batadv_tt_orig_list_entry *orig_entry;
orig_entry = container_of(rcu, struct batadv_tt_orig_list_entry, rcu);
batadv_orig_node_free_ref_now(orig_entry->orig_node);
kfree(orig_entry);
}
static void
batadv_tt_orig_list_entry_free_ref(struct batadv_tt_orig_list_entry *orig_entry)
{
if (!atomic_dec_and_test(&orig_entry->refcount))
return;
atomic_dec(&orig_entry->orig_node->tt_size);
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
memcpy(tt_change_node->change.addr, common->addr, ETH_ALEN);
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
int batadv_tt_len(int changes_num)
{
return changes_num * sizeof(struct batadv_tt_change);
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
"Deleting global tt entry %pM: %s\n",
tt_global->common.addr, message);
batadv_hash_remove(bat_priv->tt.global_hash, batadv_compare_tt,
batadv_choose_orig, tt_global->common.addr);
batadv_tt_global_entry_free_ref(tt_global);
}
void batadv_tt_local_add(struct net_device *soft_iface, const uint8_t *addr,
int ifindex)
{
struct batadv_priv *bat_priv = netdev_priv(soft_iface);
struct batadv_tt_local_entry *tt_local;
struct batadv_tt_global_entry *tt_global;
struct hlist_head *head;
struct batadv_tt_orig_list_entry *orig_entry;
int hash_added;
bool roamed_back = false;
tt_local = batadv_tt_local_hash_find(bat_priv, addr);
tt_global = batadv_tt_global_hash_find(bat_priv, addr);
if (tt_local) {
tt_local->last_seen = jiffies;
if (tt_local->common.flags & BATADV_TT_CLIENT_PENDING) {
batadv_dbg(BATADV_DBG_TT, bat_priv,
"Re-adding pending client %pM\n", addr);
tt_local->common.flags &= ~BATADV_TT_CLIENT_PENDING;
goto add_event;
}
if (tt_local->common.flags & BATADV_TT_CLIENT_ROAM) {
batadv_dbg(BATADV_DBG_TT, bat_priv,
"Roaming client %pM came back to its original location\n",
addr);
tt_local->common.flags &= ~BATADV_TT_CLIENT_ROAM;
roamed_back = true;
}
goto check_roaming;
}
tt_local = kmalloc(sizeof(*tt_local), GFP_ATOMIC);
if (!tt_local)
goto out;
batadv_dbg(BATADV_DBG_TT, bat_priv,
"Creating new local tt entry: %pM (ttvn: %d)\n", addr,
(uint8_t)atomic_read(&bat_priv->tt.vn));
memcpy(tt_local->common.addr, addr, ETH_ALEN);
tt_local->common.flags = BATADV_TT_CLIENT_NEW;
if (batadv_is_wifi_iface(ifindex))
tt_local->common.flags |= BATADV_TT_CLIENT_WIFI;
atomic_set(&tt_local->common.refcount, 2);
tt_local->last_seen = jiffies;
tt_local->common.added_at = tt_local->last_seen;
if (batadv_compare_eth(addr, soft_iface->dev_addr))
tt_local->common.flags |= BATADV_TT_CLIENT_NOPURGE;
hash_added = batadv_hash_add(bat_priv->tt.local_hash, batadv_compare_tt,
batadv_choose_orig, &tt_local->common,
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
out:
if (tt_local)
batadv_tt_local_entry_free_ref(tt_local);
if (tt_global)
batadv_tt_global_entry_free_ref(tt_global);
}
static void batadv_tt_realloc_packet_buff(unsigned char **packet_buff,
int *packet_buff_len,
int min_packet_len,
int new_packet_len)
{
unsigned char *new_buff;
new_buff = kmalloc(new_packet_len, GFP_ATOMIC);
if (new_buff) {
memcpy(new_buff, *packet_buff, min_packet_len);
kfree(*packet_buff);
*packet_buff = new_buff;
*packet_buff_len = new_packet_len;
}
}
static void batadv_tt_prepare_packet_buff(struct batadv_priv *bat_priv,
unsigned char **packet_buff,
int *packet_buff_len,
int min_packet_len)
{
int req_len;
req_len = min_packet_len;
req_len += batadv_tt_len(atomic_read(&bat_priv->tt.local_changes));
if (req_len > bat_priv->soft_iface->mtu)
req_len = min_packet_len;
batadv_tt_realloc_packet_buff(packet_buff, packet_buff_len,
min_packet_len, req_len);
}
static int batadv_tt_changes_fill_buff(struct batadv_priv *bat_priv,
unsigned char **packet_buff,
int *packet_buff_len,
int min_packet_len)
{
struct batadv_tt_change_node *entry, *safe;
int count = 0, tot_changes = 0, new_len;
unsigned char *tt_buff;
batadv_tt_prepare_packet_buff(bat_priv, packet_buff,
packet_buff_len, min_packet_len);
new_len = *packet_buff_len - min_packet_len;
tt_buff = *packet_buff + min_packet_len;
if (new_len > 0)
tot_changes = new_len / batadv_tt_len(1);
spin_lock_bh(&bat_priv->tt.changes_list_lock);
atomic_set(&bat_priv->tt.local_changes, 0);
list_for_each_entry_safe(entry, safe, &bat_priv->tt.changes_list,
list) {
if (count < tot_changes) {
memcpy(tt_buff + batadv_tt_len(count),
&entry->change, sizeof(struct batadv_tt_change));
count++;
}
list_del(&entry->list);
kfree(entry);
}
spin_unlock_bh(&bat_priv->tt.changes_list_lock);
spin_lock_bh(&bat_priv->tt.last_changeset_lock);
kfree(bat_priv->tt.last_changeset);
bat_priv->tt.last_changeset_len = 0;
bat_priv->tt.last_changeset = NULL;
if (new_len > 0) {
bat_priv->tt.last_changeset = kmalloc(new_len, GFP_ATOMIC);
if (bat_priv->tt.last_changeset) {
memcpy(bat_priv->tt.last_changeset, tt_buff, new_len);
bat_priv->tt.last_changeset_len = new_len;
}
}
spin_unlock_bh(&bat_priv->tt.last_changeset_lock);
return count;
}
int batadv_tt_local_seq_print_text(struct seq_file *seq, void *offset)
{
struct net_device *net_dev = (struct net_device *)seq->private;
struct batadv_priv *bat_priv = netdev_priv(net_dev);
struct batadv_hashtable *hash = bat_priv->tt.local_hash;
struct batadv_tt_common_entry *tt_common_entry;
struct batadv_tt_local_entry *tt_local;
struct batadv_hard_iface *primary_if;
struct hlist_head *head;
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
"Locally retrieved addresses (from %s) announced via TT (TTVN: %u CRC: %#.4x):\n",
net_dev->name, (uint8_t)atomic_read(&bat_priv->tt.vn),
bat_priv->tt.local_crc);
seq_printf(seq, " %-13s %-7s %-10s\n", "Client", "Flags",
"Last seen");
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
rcu_read_lock();
hlist_for_each_entry_rcu(tt_common_entry,
head, hash_entry) {
tt_local = container_of(tt_common_entry,
struct batadv_tt_local_entry,
common);
last_seen_jiffies = jiffies - tt_local->last_seen;
last_seen_msecs = jiffies_to_msecs(last_seen_jiffies);
last_seen_secs = last_seen_msecs / 1000;
last_seen_msecs = last_seen_msecs % 1000;
no_purge = tt_common_entry->flags & np_flag;
seq_printf(seq, " * %pM [%c%c%c%c%c] %3u.%03u\n",
tt_common_entry->addr,
(tt_common_entry->flags &
BATADV_TT_CLIENT_ROAM ? 'R' : '.'),
no_purge ? 'P' : '.',
(tt_common_entry->flags &
BATADV_TT_CLIENT_NEW ? 'N' : '.'),
(tt_common_entry->flags &
BATADV_TT_CLIENT_PENDING ? 'X' : '.'),
(tt_common_entry->flags &
BATADV_TT_CLIENT_WIFI ? 'W' : '.'),
no_purge ? 0 : last_seen_secs,
no_purge ? 0 : last_seen_msecs);
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
"Local tt entry (%pM) pending to be removed: %s\n",
tt_local_entry->common.addr, message);
}
uint16_t batadv_tt_local_remove(struct batadv_priv *bat_priv,
const uint8_t *addr, const char *message,
bool roaming)
{
struct batadv_tt_local_entry *tt_local_entry;
uint16_t flags, curr_flags = BATADV_NO_FLAGS;
tt_local_entry = batadv_tt_local_hash_find(bat_priv, addr);
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
struct hlist_head *head)
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
if (!batadv_has_timed_out(tt_local_entry->last_seen,
BATADV_TT_LOCAL_TIMEOUT))
continue;
batadv_tt_local_set_pending(bat_priv, tt_local_entry,
BATADV_TT_CLIENT_DEL, "timed out");
}
}
static void batadv_tt_local_purge(struct batadv_priv *bat_priv)
{
struct batadv_hashtable *hash = bat_priv->tt.local_hash;
struct hlist_head *head;
spinlock_t *list_lock;
uint32_t i;
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
list_lock = &hash->list_locks[i];
spin_lock_bh(list_lock);
batadv_tt_local_purge_list(bat_priv, head);
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
atomic_inc(&orig_node->tt_size);
orig_entry->orig_node = orig_node;
orig_entry->ttvn = ttvn;
atomic_set(&orig_entry->refcount, 2);
spin_lock_bh(&tt_global->list_lock);
hlist_add_head_rcu(&orig_entry->list,
&tt_global->orig_list);
spin_unlock_bh(&tt_global->list_lock);
out:
if (orig_entry)
batadv_tt_orig_list_entry_free_ref(orig_entry);
}
int batadv_tt_global_add(struct batadv_priv *bat_priv,
struct batadv_orig_node *orig_node,
const unsigned char *tt_addr, uint16_t flags,
uint8_t ttvn)
{
struct batadv_tt_global_entry *tt_global_entry;
struct batadv_tt_local_entry *tt_local_entry;
int ret = 0;
int hash_added;
struct batadv_tt_common_entry *common;
uint16_t local_flags;
tt_global_entry = batadv_tt_global_hash_find(bat_priv, tt_addr);
tt_local_entry = batadv_tt_local_hash_find(bat_priv, tt_addr);
if ((flags & BATADV_TT_CLIENT_TEMP) && tt_local_entry &&
!(tt_local_entry->common.flags & BATADV_TT_CLIENT_NEW))
goto out;
if (!tt_global_entry) {
tt_global_entry = kzalloc(sizeof(*tt_global_entry), GFP_ATOMIC);
if (!tt_global_entry)
goto out;
common = &tt_global_entry->common;
memcpy(common->addr, tt_addr, ETH_ALEN);
common->flags = flags;
tt_global_entry->roam_at = 0;
if (flags & BATADV_TT_CLIENT_ROAM)
tt_global_entry->roam_at = jiffies;
atomic_set(&common->refcount, 2);
common->added_at = jiffies;
INIT_HLIST_HEAD(&tt_global_entry->orig_list);
spin_lock_init(&tt_global_entry->list_lock);
hash_added = batadv_hash_add(bat_priv->tt.global_hash,
batadv_compare_tt,
batadv_choose_orig, common,
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
"Creating new global tt entry: %pM (via %pM)\n",
common->addr, orig_node->orig);
ret = 1;
out_remove:
local_flags = batadv_tt_local_remove(bat_priv, tt_addr,
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
batadv_transtable_best_orig(struct batadv_tt_global_entry *tt_global_entry)
{
struct batadv_neigh_node *router = NULL;
struct hlist_head *head;
struct batadv_tt_orig_list_entry *orig_entry, *best_entry = NULL;
int best_tq = 0;
head = &tt_global_entry->orig_list;
hlist_for_each_entry_rcu(orig_entry, head, list) {
router = batadv_orig_node_get_router(orig_entry->orig_node);
if (!router)
continue;
if (router->tq_avg > best_tq) {
best_entry = orig_entry;
best_tq = router->tq_avg;
}
batadv_neigh_node_free_ref(router);
}
return best_entry;
}
static void
batadv_tt_global_print_entry(struct batadv_tt_global_entry *tt_global_entry,
struct seq_file *seq)
{
struct hlist_head *head;
struct batadv_tt_orig_list_entry *orig_entry, *best_entry;
struct batadv_tt_common_entry *tt_common_entry;
uint16_t flags;
uint8_t last_ttvn;
tt_common_entry = &tt_global_entry->common;
flags = tt_common_entry->flags;
best_entry = batadv_transtable_best_orig(tt_global_entry);
if (best_entry) {
last_ttvn = atomic_read(&best_entry->orig_node->last_ttvn);
seq_printf(seq,
" %c %pM (%3u) via %pM (%3u) (%#.4x) [%c%c%c]\n",
'*', tt_global_entry->common.addr,
best_entry->ttvn, best_entry->orig_node->orig,
last_ttvn, best_entry->orig_node->tt_crc,
(flags & BATADV_TT_CLIENT_ROAM ? 'R' : '.'),
(flags & BATADV_TT_CLIENT_WIFI ? 'W' : '.'),
(flags & BATADV_TT_CLIENT_TEMP ? 'T' : '.'));
}
head = &tt_global_entry->orig_list;
hlist_for_each_entry_rcu(orig_entry, head, list) {
if (best_entry == orig_entry)
continue;
last_ttvn = atomic_read(&orig_entry->orig_node->last_ttvn);
seq_printf(seq, " %c %pM (%3u) via %pM (%3u) [%c%c%c]\n",
'+', tt_global_entry->common.addr,
orig_entry->ttvn, orig_entry->orig_node->orig,
last_ttvn,
(flags & BATADV_TT_CLIENT_ROAM ? 'R' : '.'),
(flags & BATADV_TT_CLIENT_WIFI ? 'W' : '.'),
(flags & BATADV_TT_CLIENT_TEMP ? 'T' : '.'));
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
seq_printf(seq, " %-13s %s %-15s %s (%-6s) %s\n",
"Client", "(TTVN)", "Originator", "(Curr TTVN)", "CRC",
"Flags");
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
rcu_read_lock();
hlist_for_each_entry_rcu(tt_common_entry,
head, hash_entry) {
tt_global = container_of(tt_common_entry,
struct batadv_tt_global_entry,
common);
batadv_tt_global_print_entry(tt_global, seq);
}
rcu_read_unlock();
}
out:
if (primary_if)
batadv_hardif_free_ref(primary_if);
return 0;
}
static void
batadv_tt_global_del_orig_list(struct batadv_tt_global_entry *tt_global_entry)
{
struct hlist_head *head;
struct hlist_node *safe;
struct batadv_tt_orig_list_entry *orig_entry;
spin_lock_bh(&tt_global_entry->list_lock);
head = &tt_global_entry->orig_list;
hlist_for_each_entry_safe(orig_entry, safe, head, list) {
hlist_del_rcu(&orig_entry->list);
batadv_tt_orig_list_entry_free_ref(orig_entry);
}
spin_unlock_bh(&tt_global_entry->list_lock);
}
static void
batadv_tt_global_del_orig_entry(struct batadv_priv *bat_priv,
struct batadv_tt_global_entry *tt_global_entry,
struct batadv_orig_node *orig_node,
const char *message)
{
struct hlist_head *head;
struct hlist_node *safe;
struct batadv_tt_orig_list_entry *orig_entry;
spin_lock_bh(&tt_global_entry->list_lock);
head = &tt_global_entry->orig_list;
hlist_for_each_entry_safe(orig_entry, safe, head, list) {
if (orig_entry->orig_node == orig_node) {
batadv_dbg(BATADV_DBG_TT, bat_priv,
"Deleting %pM from global tt entry %pM: %s\n",
orig_node->orig,
tt_global_entry->common.addr, message);
hlist_del_rcu(&orig_entry->list);
batadv_tt_orig_list_entry_free_ref(orig_entry);
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
batadv_tt_global_del_orig_entry(bat_priv, tt_global_entry,
orig_node, message);
}
static void batadv_tt_global_del(struct batadv_priv *bat_priv,
struct batadv_orig_node *orig_node,
const unsigned char *addr,
const char *message, bool roaming)
{
struct batadv_tt_global_entry *tt_global_entry;
struct batadv_tt_local_entry *local_entry = NULL;
tt_global_entry = batadv_tt_global_hash_find(bat_priv, addr);
if (!tt_global_entry)
goto out;
if (!roaming) {
batadv_tt_global_del_orig_entry(bat_priv, tt_global_entry,
orig_node, message);
if (hlist_empty(&tt_global_entry->orig_list))
batadv_tt_global_free(bat_priv, tt_global_entry,
message);
goto out;
}
local_entry = batadv_tt_local_hash_find(bat_priv,
tt_global_entry->common.addr);
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
const char *message)
{
struct batadv_tt_global_entry *tt_global;
struct batadv_tt_common_entry *tt_common_entry;
uint32_t i;
struct batadv_hashtable *hash = bat_priv->tt.global_hash;
struct hlist_node *safe;
struct hlist_head *head;
spinlock_t *list_lock;
if (!hash)
return;
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
list_lock = &hash->list_locks[i];
spin_lock_bh(list_lock);
hlist_for_each_entry_safe(tt_common_entry, safe,
head, hash_entry) {
tt_global = container_of(tt_common_entry,
struct batadv_tt_global_entry,
common);
batadv_tt_global_del_orig_entry(bat_priv, tt_global,
orig_node, message);
if (hlist_empty(&tt_global->orig_list)) {
batadv_dbg(BATADV_DBG_TT, bat_priv,
"Deleting global tt entry %pM: %s\n",
tt_global->common.addr, message);
hlist_del_rcu(&tt_common_entry->hash_entry);
batadv_tt_global_entry_free_ref(tt_global);
}
}
spin_unlock_bh(list_lock);
}
orig_node->tt_initialised = false;
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
"Deleting global tt entry (%pM): %s\n",
tt_global->common.addr, msg);
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
return ret;
}
struct batadv_orig_node *batadv_transtable_search(struct batadv_priv *bat_priv,
const uint8_t *src,
const uint8_t *addr)
{
struct batadv_tt_local_entry *tt_local_entry = NULL;
struct batadv_tt_global_entry *tt_global_entry = NULL;
struct batadv_orig_node *orig_node = NULL;
struct batadv_tt_orig_list_entry *best_entry;
if (src && atomic_read(&bat_priv->ap_isolation)) {
tt_local_entry = batadv_tt_local_hash_find(bat_priv, src);
if (!tt_local_entry ||
(tt_local_entry->common.flags & BATADV_TT_CLIENT_PENDING))
goto out;
}
tt_global_entry = batadv_tt_global_hash_find(bat_priv, addr);
if (!tt_global_entry)
goto out;
if (tt_local_entry &&
_batadv_is_ap_isolated(tt_local_entry, tt_global_entry))
goto out;
rcu_read_lock();
best_entry = batadv_transtable_best_orig(tt_global_entry);
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
static uint16_t batadv_tt_global_crc(struct batadv_priv *bat_priv,
struct batadv_orig_node *orig_node)
{
uint16_t total = 0, total_one;
struct batadv_hashtable *hash = bat_priv->tt.global_hash;
struct batadv_tt_common_entry *tt_common;
struct batadv_tt_global_entry *tt_global;
struct hlist_head *head;
uint32_t i;
int j;
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
rcu_read_lock();
hlist_for_each_entry_rcu(tt_common, head, hash_entry) {
tt_global = container_of(tt_common,
struct batadv_tt_global_entry,
common);
if (tt_common->flags & BATADV_TT_CLIENT_ROAM)
continue;
if (tt_common->flags & BATADV_TT_CLIENT_TEMP)
continue;
if (!batadv_tt_global_entry_has_orig(tt_global,
orig_node))
continue;
total_one = 0;
for (j = 0; j < ETH_ALEN; j++)
total_one = crc16_byte(total_one,
tt_common->addr[j]);
total ^= total_one;
}
rcu_read_unlock();
}
return total;
}
static uint16_t batadv_tt_local_crc(struct batadv_priv *bat_priv)
{
uint16_t total = 0, total_one;
struct batadv_hashtable *hash = bat_priv->tt.local_hash;
struct batadv_tt_common_entry *tt_common;
struct hlist_head *head;
uint32_t i;
int j;
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
rcu_read_lock();
hlist_for_each_entry_rcu(tt_common, head, hash_entry) {
if (tt_common->flags & BATADV_TT_CLIENT_NEW)
continue;
total_one = 0;
for (j = 0; j < ETH_ALEN; j++)
total_one = crc16_byte(total_one,
tt_common->addr[j]);
total ^= total_one;
}
rcu_read_unlock();
}
return total;
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
const unsigned char *tt_buff,
uint8_t tt_num_changes)
{
uint16_t tt_buff_len = batadv_tt_len(tt_num_changes);
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
memcpy(tt_req_node->addr, orig_node->orig, ETH_ALEN);
tt_req_node->issued_at = jiffies;
list_add(&tt_req_node->list, &bat_priv->tt.req_list);
unlock:
spin_unlock_bh(&bat_priv->tt.req_list_lock);
return tt_req_node;
}
static int batadv_tt_local_valid_entry(const void *entry_ptr,
const void *data_ptr)
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
static struct sk_buff *
batadv_tt_response_fill_table(uint16_t tt_len, uint8_t ttvn,
struct batadv_hashtable *hash,
struct batadv_priv *bat_priv,
int (*valid_cb)(const void *, const void *),
void *cb_data)
{
struct batadv_tt_common_entry *tt_common_entry;
struct batadv_tt_query_packet *tt_response;
struct batadv_tt_change *tt_change;
struct hlist_head *head;
struct sk_buff *skb = NULL;
uint16_t tt_tot, tt_count;
ssize_t tt_query_size = sizeof(struct batadv_tt_query_packet);
uint32_t i;
size_t len;
if (tt_query_size + tt_len > bat_priv->soft_iface->mtu) {
tt_len = bat_priv->soft_iface->mtu - tt_query_size;
tt_len -= tt_len % sizeof(struct batadv_tt_change);
}
tt_tot = tt_len / sizeof(struct batadv_tt_change);
len = tt_query_size + tt_len;
skb = netdev_alloc_skb_ip_align(NULL, len + ETH_HLEN);
if (!skb)
goto out;
skb_reserve(skb, ETH_HLEN);
tt_response = (struct batadv_tt_query_packet *)skb_put(skb, len);
tt_response->ttvn = ttvn;
tt_change = (struct batadv_tt_change *)(skb->data + tt_query_size);
tt_count = 0;
rcu_read_lock();
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
hlist_for_each_entry_rcu(tt_common_entry,
head, hash_entry) {
if (tt_count == tt_tot)
break;
if ((valid_cb) && (!valid_cb(tt_common_entry, cb_data)))
continue;
memcpy(tt_change->addr, tt_common_entry->addr,
ETH_ALEN);
tt_change->flags = tt_common_entry->flags;
tt_count++;
tt_change++;
}
}
rcu_read_unlock();
tt_response->tt_data = htons(tt_count);
out:
return skb;
}
static int batadv_send_tt_request(struct batadv_priv *bat_priv,
struct batadv_orig_node *dst_orig_node,
uint8_t ttvn, uint16_t tt_crc,
bool full_table)
{
struct sk_buff *skb = NULL;
struct batadv_tt_query_packet *tt_request;
struct batadv_hard_iface *primary_if;
struct batadv_tt_req_node *tt_req_node = NULL;
int ret = 1;
size_t tt_req_len;
primary_if = batadv_primary_if_get_selected(bat_priv);
if (!primary_if)
goto out;
tt_req_node = batadv_new_tt_req_node(bat_priv, dst_orig_node);
if (!tt_req_node)
goto out;
skb = netdev_alloc_skb_ip_align(NULL, sizeof(*tt_request) + ETH_HLEN);
if (!skb)
goto out;
skb_reserve(skb, ETH_HLEN);
tt_req_len = sizeof(*tt_request);
tt_request = (struct batadv_tt_query_packet *)skb_put(skb, tt_req_len);
tt_request->header.packet_type = BATADV_TT_QUERY;
tt_request->header.version = BATADV_COMPAT_VERSION;
memcpy(tt_request->src, primary_if->net_dev->dev_addr, ETH_ALEN);
memcpy(tt_request->dst, dst_orig_node->orig, ETH_ALEN);
tt_request->header.ttl = BATADV_TTL;
tt_request->ttvn = ttvn;
tt_request->tt_data = htons(tt_crc);
tt_request->flags = BATADV_TT_REQUEST;
if (full_table)
tt_request->flags |= BATADV_TT_FULL_TABLE;
batadv_dbg(BATADV_DBG_TT, bat_priv, "Sending TT_REQUEST to %pM [%c]\n",
dst_orig_node->orig, (full_table ? 'F' : '.'));
batadv_inc_counter(bat_priv, BATADV_CNT_TT_REQUEST_TX);
if (batadv_send_skb_to_orig(skb, dst_orig_node, NULL) != NET_XMIT_DROP)
ret = 0;
out:
if (primary_if)
batadv_hardif_free_ref(primary_if);
if (ret)
kfree_skb(skb);
if (ret && tt_req_node) {
spin_lock_bh(&bat_priv->tt.req_list_lock);
list_del(&tt_req_node->list);
spin_unlock_bh(&bat_priv->tt.req_list_lock);
kfree(tt_req_node);
}
return ret;
}
static bool
batadv_send_other_tt_response(struct batadv_priv *bat_priv,
struct batadv_tt_query_packet *tt_request)
{
struct batadv_orig_node *req_dst_orig_node;
struct batadv_orig_node *res_dst_orig_node = NULL;
uint8_t orig_ttvn, req_ttvn, ttvn;
int res, ret = false;
unsigned char *tt_buff;
bool full_table;
uint16_t tt_len, tt_tot;
struct sk_buff *skb = NULL;
struct batadv_tt_query_packet *tt_response;
uint8_t *packet_pos;
size_t len;
batadv_dbg(BATADV_DBG_TT, bat_priv,
"Received TT_REQUEST from %pM for ttvn: %u (%pM) [%c]\n",
tt_request->src, tt_request->ttvn, tt_request->dst,
(tt_request->flags & BATADV_TT_FULL_TABLE ? 'F' : '.'));
req_dst_orig_node = batadv_orig_hash_find(bat_priv, tt_request->dst);
if (!req_dst_orig_node)
goto out;
res_dst_orig_node = batadv_orig_hash_find(bat_priv, tt_request->src);
if (!res_dst_orig_node)
goto out;
orig_ttvn = (uint8_t)atomic_read(&req_dst_orig_node->last_ttvn);
req_ttvn = tt_request->ttvn;
if (orig_ttvn != req_ttvn ||
tt_request->tt_data != htons(req_dst_orig_node->tt_crc))
goto out;
if (tt_request->flags & BATADV_TT_FULL_TABLE ||
!req_dst_orig_node->tt_buff)
full_table = true;
else
full_table = false;
if (!full_table) {
spin_lock_bh(&req_dst_orig_node->tt_buff_lock);
tt_len = req_dst_orig_node->tt_buff_len;
tt_tot = tt_len / sizeof(struct batadv_tt_change);
len = sizeof(*tt_response) + tt_len;
skb = netdev_alloc_skb_ip_align(NULL, len + ETH_HLEN);
if (!skb)
goto unlock;
skb_reserve(skb, ETH_HLEN);
packet_pos = skb_put(skb, len);
tt_response = (struct batadv_tt_query_packet *)packet_pos;
tt_response->ttvn = req_ttvn;
tt_response->tt_data = htons(tt_tot);
tt_buff = skb->data + sizeof(*tt_response);
memcpy(tt_buff, req_dst_orig_node->tt_buff,
req_dst_orig_node->tt_buff_len);
spin_unlock_bh(&req_dst_orig_node->tt_buff_lock);
} else {
tt_len = (uint16_t)atomic_read(&req_dst_orig_node->tt_size);
tt_len *= sizeof(struct batadv_tt_change);
ttvn = (uint8_t)atomic_read(&req_dst_orig_node->last_ttvn);
skb = batadv_tt_response_fill_table(tt_len, ttvn,
bat_priv->tt.global_hash,
bat_priv,
batadv_tt_global_valid,
req_dst_orig_node);
if (!skb)
goto out;
tt_response = (struct batadv_tt_query_packet *)skb->data;
}
tt_response->header.packet_type = BATADV_TT_QUERY;
tt_response->header.version = BATADV_COMPAT_VERSION;
tt_response->header.ttl = BATADV_TTL;
memcpy(tt_response->src, req_dst_orig_node->orig, ETH_ALEN);
memcpy(tt_response->dst, tt_request->src, ETH_ALEN);
tt_response->flags = BATADV_TT_RESPONSE;
if (full_table)
tt_response->flags |= BATADV_TT_FULL_TABLE;
batadv_dbg(BATADV_DBG_TT, bat_priv,
"Sending TT_RESPONSE %pM for %pM (ttvn: %u)\n",
res_dst_orig_node->orig, req_dst_orig_node->orig, req_ttvn);
batadv_inc_counter(bat_priv, BATADV_CNT_TT_RESPONSE_TX);
res = batadv_send_skb_to_orig(skb, res_dst_orig_node, NULL);
if (res != NET_XMIT_DROP)
ret = true;
goto out;
unlock:
spin_unlock_bh(&req_dst_orig_node->tt_buff_lock);
out:
if (res_dst_orig_node)
batadv_orig_node_free_ref(res_dst_orig_node);
if (req_dst_orig_node)
batadv_orig_node_free_ref(req_dst_orig_node);
if (!ret)
kfree_skb(skb);
return ret;
}
static bool
batadv_send_my_tt_response(struct batadv_priv *bat_priv,
struct batadv_tt_query_packet *tt_request)
{
struct batadv_orig_node *orig_node;
struct batadv_hard_iface *primary_if = NULL;
uint8_t my_ttvn, req_ttvn, ttvn;
int ret = false;
unsigned char *tt_buff;
bool full_table;
uint16_t tt_len, tt_tot;
struct sk_buff *skb = NULL;
struct batadv_tt_query_packet *tt_response;
uint8_t *packet_pos;
size_t len;
batadv_dbg(BATADV_DBG_TT, bat_priv,
"Received TT_REQUEST from %pM for ttvn: %u (me) [%c]\n",
tt_request->src, tt_request->ttvn,
(tt_request->flags & BATADV_TT_FULL_TABLE ? 'F' : '.'));
my_ttvn = (uint8_t)atomic_read(&bat_priv->tt.vn);
req_ttvn = tt_request->ttvn;
orig_node = batadv_orig_hash_find(bat_priv, tt_request->src);
if (!orig_node)
goto out;
primary_if = batadv_primary_if_get_selected(bat_priv);
if (!primary_if)
goto out;
if (tt_request->flags & BATADV_TT_FULL_TABLE || my_ttvn != req_ttvn ||
!bat_priv->tt.last_changeset)
full_table = true;
else
full_table = false;
if (!full_table) {
spin_lock_bh(&bat_priv->tt.last_changeset_lock);
tt_len = bat_priv->tt.last_changeset_len;
tt_tot = tt_len / sizeof(struct batadv_tt_change);
len = sizeof(*tt_response) + tt_len;
skb = netdev_alloc_skb_ip_align(NULL, len + ETH_HLEN);
if (!skb)
goto unlock;
skb_reserve(skb, ETH_HLEN);
packet_pos = skb_put(skb, len);
tt_response = (struct batadv_tt_query_packet *)packet_pos;
tt_response->ttvn = req_ttvn;
tt_response->tt_data = htons(tt_tot);
tt_buff = skb->data + sizeof(*tt_response);
memcpy(tt_buff, bat_priv->tt.last_changeset,
bat_priv->tt.last_changeset_len);
spin_unlock_bh(&bat_priv->tt.last_changeset_lock);
} else {
tt_len = (uint16_t)atomic_read(&bat_priv->tt.local_entry_num);
tt_len *= sizeof(struct batadv_tt_change);
ttvn = (uint8_t)atomic_read(&bat_priv->tt.vn);
skb = batadv_tt_response_fill_table(tt_len, ttvn,
bat_priv->tt.local_hash,
bat_priv,
batadv_tt_local_valid_entry,
NULL);
if (!skb)
goto out;
tt_response = (struct batadv_tt_query_packet *)skb->data;
}
tt_response->header.packet_type = BATADV_TT_QUERY;
tt_response->header.version = BATADV_COMPAT_VERSION;
tt_response->header.ttl = BATADV_TTL;
memcpy(tt_response->src, primary_if->net_dev->dev_addr, ETH_ALEN);
memcpy(tt_response->dst, tt_request->src, ETH_ALEN);
tt_response->flags = BATADV_TT_RESPONSE;
if (full_table)
tt_response->flags |= BATADV_TT_FULL_TABLE;
batadv_dbg(BATADV_DBG_TT, bat_priv,
"Sending TT_RESPONSE to %pM [%c]\n",
orig_node->orig,
(tt_response->flags & BATADV_TT_FULL_TABLE ? 'F' : '.'));
batadv_inc_counter(bat_priv, BATADV_CNT_TT_RESPONSE_TX);
if (batadv_send_skb_to_orig(skb, orig_node, NULL) != NET_XMIT_DROP)
ret = true;
goto out;
unlock:
spin_unlock_bh(&bat_priv->tt.last_changeset_lock);
out:
if (orig_node)
batadv_orig_node_free_ref(orig_node);
if (primary_if)
batadv_hardif_free_ref(primary_if);
if (!ret)
kfree_skb(skb);
return true;
}
bool batadv_send_tt_response(struct batadv_priv *bat_priv,
struct batadv_tt_query_packet *tt_request)
{
if (batadv_is_my_mac(bat_priv, tt_request->dst)) {
if (batadv_bla_is_backbone_gw_orig(bat_priv, tt_request->src))
return true;
return batadv_send_my_tt_response(bat_priv, tt_request);
} else {
return batadv_send_other_tt_response(bat_priv, tt_request);
}
}
static void _batadv_tt_update_changes(struct batadv_priv *bat_priv,
struct batadv_orig_node *orig_node,
struct batadv_tt_change *tt_change,
uint16_t tt_num_changes, uint8_t ttvn)
{
int i;
int roams;
for (i = 0; i < tt_num_changes; i++) {
if ((tt_change + i)->flags & BATADV_TT_CLIENT_DEL) {
roams = (tt_change + i)->flags & BATADV_TT_CLIENT_ROAM;
batadv_tt_global_del(bat_priv, orig_node,
(tt_change + i)->addr,
"tt removed by changes",
roams);
} else {
if (!batadv_tt_global_add(bat_priv, orig_node,
(tt_change + i)->addr,
(tt_change + i)->flags, ttvn))
return;
}
}
orig_node->tt_initialised = true;
}
static void batadv_tt_fill_gtable(struct batadv_priv *bat_priv,
struct batadv_tt_query_packet *tt_response)
{
struct batadv_orig_node *orig_node;
orig_node = batadv_orig_hash_find(bat_priv, tt_response->src);
if (!orig_node)
goto out;
batadv_tt_global_del_orig(bat_priv, orig_node, "Received full table");
_batadv_tt_update_changes(bat_priv, orig_node,
(struct batadv_tt_change *)(tt_response + 1),
ntohs(tt_response->tt_data),
tt_response->ttvn);
spin_lock_bh(&orig_node->tt_buff_lock);
kfree(orig_node->tt_buff);
orig_node->tt_buff_len = 0;
orig_node->tt_buff = NULL;
spin_unlock_bh(&orig_node->tt_buff_lock);
atomic_set(&orig_node->last_ttvn, tt_response->ttvn);
out:
if (orig_node)
batadv_orig_node_free_ref(orig_node);
}
static void batadv_tt_update_changes(struct batadv_priv *bat_priv,
struct batadv_orig_node *orig_node,
uint16_t tt_num_changes, uint8_t ttvn,
struct batadv_tt_change *tt_change)
{
_batadv_tt_update_changes(bat_priv, orig_node, tt_change,
tt_num_changes, ttvn);
batadv_tt_save_orig_buffer(bat_priv, orig_node,
(unsigned char *)tt_change, tt_num_changes);
atomic_set(&orig_node->last_ttvn, ttvn);
}
bool batadv_is_my_client(struct batadv_priv *bat_priv, const uint8_t *addr)
{
struct batadv_tt_local_entry *tt_local_entry;
bool ret = false;
tt_local_entry = batadv_tt_local_hash_find(bat_priv, addr);
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
void batadv_handle_tt_response(struct batadv_priv *bat_priv,
struct batadv_tt_query_packet *tt_response)
{
struct batadv_tt_req_node *node, *safe;
struct batadv_orig_node *orig_node = NULL;
struct batadv_tt_change *tt_change;
batadv_dbg(BATADV_DBG_TT, bat_priv,
"Received TT_RESPONSE from %pM for ttvn %d t_size: %d [%c]\n",
tt_response->src, tt_response->ttvn,
ntohs(tt_response->tt_data),
(tt_response->flags & BATADV_TT_FULL_TABLE ? 'F' : '.'));
if (batadv_bla_is_backbone_gw_orig(bat_priv, tt_response->src))
goto out;
orig_node = batadv_orig_hash_find(bat_priv, tt_response->src);
if (!orig_node)
goto out;
if (tt_response->flags & BATADV_TT_FULL_TABLE) {
batadv_tt_fill_gtable(bat_priv, tt_response);
} else {
tt_change = (struct batadv_tt_change *)(tt_response + 1);
batadv_tt_update_changes(bat_priv, orig_node,
ntohs(tt_response->tt_data),
tt_response->ttvn, tt_change);
}
spin_lock_bh(&bat_priv->tt.req_list_lock);
list_for_each_entry_safe(node, safe, &bat_priv->tt.req_list, list) {
if (!batadv_compare_eth(node->addr, tt_response->src))
continue;
list_del(&node->list);
kfree(node);
}
spin_unlock_bh(&bat_priv->tt.req_list_lock);
orig_node->tt_crc = batadv_tt_global_crc(bat_priv, orig_node);
out:
if (orig_node)
batadv_orig_node_free_ref(orig_node);
}
int batadv_tt_init(struct batadv_priv *bat_priv)
{
int ret;
ret = batadv_tt_local_init(bat_priv);
if (ret < 0)
return ret;
ret = batadv_tt_global_init(bat_priv);
if (ret < 0)
return ret;
INIT_DELAYED_WORK(&bat_priv->tt.work, batadv_tt_purge);
queue_delayed_work(batadv_event_workqueue, &bat_priv->tt.work,
msecs_to_jiffies(BATADV_TT_WORK_PERIOD));
return 1;
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
memcpy(tt_roam_node->addr, client, ETH_ALEN);
list_add(&tt_roam_node->list, &bat_priv->tt.roam_list);
ret = true;
}
unlock:
spin_unlock_bh(&bat_priv->tt.roam_list_lock);
return ret;
}
static void batadv_send_roam_adv(struct batadv_priv *bat_priv, uint8_t *client,
struct batadv_orig_node *orig_node)
{
struct sk_buff *skb = NULL;
struct batadv_roam_adv_packet *roam_adv_packet;
int ret = 1;
struct batadv_hard_iface *primary_if;
size_t len = sizeof(*roam_adv_packet);
if (!batadv_tt_check_roam_count(bat_priv, client))
goto out;
skb = netdev_alloc_skb_ip_align(NULL, len + ETH_HLEN);
if (!skb)
goto out;
skb_reserve(skb, ETH_HLEN);
roam_adv_packet = (struct batadv_roam_adv_packet *)skb_put(skb, len);
roam_adv_packet->header.packet_type = BATADV_ROAM_ADV;
roam_adv_packet->header.version = BATADV_COMPAT_VERSION;
roam_adv_packet->header.ttl = BATADV_TTL;
roam_adv_packet->reserved = 0;
primary_if = batadv_primary_if_get_selected(bat_priv);
if (!primary_if)
goto out;
memcpy(roam_adv_packet->src, primary_if->net_dev->dev_addr, ETH_ALEN);
batadv_hardif_free_ref(primary_if);
memcpy(roam_adv_packet->dst, orig_node->orig, ETH_ALEN);
memcpy(roam_adv_packet->client, client, ETH_ALEN);
batadv_dbg(BATADV_DBG_TT, bat_priv,
"Sending ROAMING_ADV to %pM (client %pM)\n",
orig_node->orig, client);
batadv_inc_counter(bat_priv, BATADV_CNT_TT_ROAM_ADV_TX);
if (batadv_send_skb_to_orig(skb, orig_node, NULL) != NET_XMIT_DROP)
ret = 0;
out:
if (ret && skb)
kfree_skb(skb);
return;
}
static void batadv_tt_purge(struct work_struct *work)
{
struct delayed_work *delayed_work;
struct batadv_priv_tt *priv_tt;
struct batadv_priv *bat_priv;
delayed_work = container_of(work, struct delayed_work, work);
priv_tt = container_of(delayed_work, struct batadv_priv_tt, work);
bat_priv = container_of(priv_tt, struct batadv_priv, tt);
batadv_tt_local_purge(bat_priv);
batadv_tt_global_purge(bat_priv);
batadv_tt_req_purge(bat_priv);
batadv_tt_roam_purge(bat_priv);
queue_delayed_work(batadv_event_workqueue, &bat_priv->tt.work,
msecs_to_jiffies(BATADV_TT_WORK_PERIOD));
}
void batadv_tt_free(struct batadv_priv *bat_priv)
{
cancel_delayed_work_sync(&bat_priv->tt.work);
batadv_tt_local_table_free(bat_priv);
batadv_tt_global_table_free(bat_priv);
batadv_tt_req_list_free(bat_priv);
batadv_tt_changes_list_free(bat_priv);
batadv_tt_roam_list_free(bat_priv);
kfree(bat_priv->tt.last_changeset);
}
static uint16_t batadv_tt_set_flags(struct batadv_hashtable *hash,
uint16_t flags, bool enable)
{
uint32_t i;
uint16_t changed_num = 0;
struct hlist_head *head;
struct batadv_tt_common_entry *tt_common_entry;
if (!hash)
goto out;
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
}
rcu_read_unlock();
}
out:
return changed_num;
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
"Deleting local tt entry (%pM): pending\n",
tt_common->addr);
atomic_dec(&bat_priv->tt.local_entry_num);
hlist_del_rcu(&tt_common->hash_entry);
tt_local = container_of(tt_common,
struct batadv_tt_local_entry,
common);
batadv_tt_local_entry_free_ref(tt_local);
}
spin_unlock_bh(list_lock);
}
}
static int batadv_tt_commit_changes(struct batadv_priv *bat_priv,
unsigned char **packet_buff,
int *packet_buff_len, int packet_min_len)
{
uint16_t changed_num = 0;
if (atomic_read(&bat_priv->tt.local_changes) < 1)
return -ENOENT;
changed_num = batadv_tt_set_flags(bat_priv->tt.local_hash,
BATADV_TT_CLIENT_NEW, false);
atomic_add(changed_num, &bat_priv->tt.local_entry_num);
batadv_tt_local_purge_pending_clients(bat_priv);
bat_priv->tt.local_crc = batadv_tt_local_crc(bat_priv);
atomic_inc(&bat_priv->tt.vn);
batadv_dbg(BATADV_DBG_TT, bat_priv,
"Local changes committed, updating to ttvn %u\n",
(uint8_t)atomic_read(&bat_priv->tt.vn));
atomic_set(&bat_priv->tt.ogm_append_cnt, BATADV_TT_OGM_APPEND_MAX);
return batadv_tt_changes_fill_buff(bat_priv, packet_buff,
packet_buff_len, packet_min_len);
}
int batadv_tt_append_diff(struct batadv_priv *bat_priv,
unsigned char **packet_buff, int *packet_buff_len,
int packet_min_len)
{
int tt_num_changes;
tt_num_changes = batadv_tt_commit_changes(bat_priv, packet_buff,
packet_buff_len,
packet_min_len);
if ((tt_num_changes < 0) &&
(!batadv_atomic_dec_not_zero(&bat_priv->tt.ogm_append_cnt))) {
batadv_tt_realloc_packet_buff(packet_buff, packet_buff_len,
packet_min_len, packet_min_len);
tt_num_changes = 0;
}
return tt_num_changes;
}
bool batadv_is_ap_isolated(struct batadv_priv *bat_priv, uint8_t *src,
uint8_t *dst)
{
struct batadv_tt_local_entry *tt_local_entry = NULL;
struct batadv_tt_global_entry *tt_global_entry = NULL;
bool ret = false;
if (!atomic_read(&bat_priv->ap_isolation))
goto out;
tt_local_entry = batadv_tt_local_hash_find(bat_priv, dst);
if (!tt_local_entry)
goto out;
tt_global_entry = batadv_tt_global_hash_find(bat_priv, src);
if (!tt_global_entry)
goto out;
if (!_batadv_is_ap_isolated(tt_local_entry, tt_global_entry))
goto out;
ret = true;
out:
if (tt_global_entry)
batadv_tt_global_entry_free_ref(tt_global_entry);
if (tt_local_entry)
batadv_tt_local_entry_free_ref(tt_local_entry);
return ret;
}
void batadv_tt_update_orig(struct batadv_priv *bat_priv,
struct batadv_orig_node *orig_node,
const unsigned char *tt_buff, uint8_t tt_num_changes,
uint8_t ttvn, uint16_t tt_crc)
{
uint8_t orig_ttvn = (uint8_t)atomic_read(&orig_node->last_ttvn);
bool full_table = true;
struct batadv_tt_change *tt_change;
if (batadv_bla_is_backbone_gw_orig(bat_priv, orig_node->orig))
return;
if ((!orig_node->tt_initialised && ttvn == 1) ||
ttvn - orig_ttvn == 1) {
if (!tt_num_changes) {
full_table = false;
goto request_table;
}
tt_change = (struct batadv_tt_change *)tt_buff;
batadv_tt_update_changes(bat_priv, orig_node, tt_num_changes,
ttvn, tt_change);
orig_node->tt_crc = batadv_tt_global_crc(bat_priv, orig_node);
if (orig_node->tt_crc != tt_crc)
goto request_table;
} else {
if (!orig_node->tt_initialised || ttvn != orig_ttvn ||
orig_node->tt_crc != tt_crc) {
request_table:
batadv_dbg(BATADV_DBG_TT, bat_priv,
"TT inconsistency for %pM. Need to retrieve the correct information (ttvn: %u last_ttvn: %u crc: %#.4x last_crc: %#.4x num_changes: %u)\n",
orig_node->orig, ttvn, orig_ttvn, tt_crc,
orig_node->tt_crc, tt_num_changes);
batadv_send_tt_request(bat_priv, orig_node, ttvn,
tt_crc, full_table);
return;
}
}
}
bool batadv_tt_global_client_is_roaming(struct batadv_priv *bat_priv,
uint8_t *addr)
{
struct batadv_tt_global_entry *tt_global_entry;
bool ret = false;
tt_global_entry = batadv_tt_global_hash_find(bat_priv, addr);
if (!tt_global_entry)
goto out;
ret = tt_global_entry->common.flags & BATADV_TT_CLIENT_ROAM;
batadv_tt_global_entry_free_ref(tt_global_entry);
out:
return ret;
}
bool batadv_tt_local_client_is_roaming(struct batadv_priv *bat_priv,
uint8_t *addr)
{
struct batadv_tt_local_entry *tt_local_entry;
bool ret = false;
tt_local_entry = batadv_tt_local_hash_find(bat_priv, addr);
if (!tt_local_entry)
goto out;
ret = tt_local_entry->common.flags & BATADV_TT_CLIENT_ROAM;
batadv_tt_local_entry_free_ref(tt_local_entry);
out:
return ret;
}
bool batadv_tt_add_temporary_global_entry(struct batadv_priv *bat_priv,
struct batadv_orig_node *orig_node,
const unsigned char *addr)
{
bool ret = false;
if (batadv_bla_is_backbone_gw_orig(bat_priv, orig_node->orig))
goto out;
if (!batadv_tt_global_add(bat_priv, orig_node, addr,
BATADV_TT_CLIENT_TEMP,
atomic_read(&orig_node->last_ttvn)))
goto out;
batadv_dbg(BATADV_DBG_TT, bat_priv,
"Added temporary global client (addr: %pM orig: %pM)\n",
addr, orig_node->orig);
ret = true;
out:
return ret;
}
