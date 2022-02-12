static inline uint32_t choose_claim(const void *data, uint32_t size)
{
const unsigned char *key = data;
uint32_t hash = 0;
size_t i;
for (i = 0; i < ETH_ALEN + sizeof(short); i++) {
hash += key[i];
hash += (hash << 10);
hash ^= (hash >> 6);
}
hash += (hash << 3);
hash ^= (hash >> 11);
hash += (hash << 15);
return hash % size;
}
static inline uint32_t choose_backbone_gw(const void *data, uint32_t size)
{
const unsigned char *key = data;
uint32_t hash = 0;
size_t i;
for (i = 0; i < ETH_ALEN + sizeof(short); i++) {
hash += key[i];
hash += (hash << 10);
hash ^= (hash >> 6);
}
hash += (hash << 3);
hash ^= (hash >> 11);
hash += (hash << 15);
return hash % size;
}
static int compare_backbone_gw(const struct hlist_node *node, const void *data2)
{
const void *data1 = container_of(node, struct backbone_gw,
hash_entry);
return (memcmp(data1, data2, ETH_ALEN + sizeof(short)) == 0 ? 1 : 0);
}
static int compare_claim(const struct hlist_node *node, const void *data2)
{
const void *data1 = container_of(node, struct claim,
hash_entry);
return (memcmp(data1, data2, ETH_ALEN + sizeof(short)) == 0 ? 1 : 0);
}
static void backbone_gw_free_ref(struct backbone_gw *backbone_gw)
{
if (atomic_dec_and_test(&backbone_gw->refcount))
kfree_rcu(backbone_gw, rcu);
}
static void claim_free_rcu(struct rcu_head *rcu)
{
struct claim *claim;
claim = container_of(rcu, struct claim, rcu);
backbone_gw_free_ref(claim->backbone_gw);
kfree(claim);
}
static void claim_free_ref(struct claim *claim)
{
if (atomic_dec_and_test(&claim->refcount))
call_rcu(&claim->rcu, claim_free_rcu);
}
static struct claim *claim_hash_find(struct bat_priv *bat_priv,
struct claim *data)
{
struct hashtable_t *hash = bat_priv->claim_hash;
struct hlist_head *head;
struct hlist_node *node;
struct claim *claim;
struct claim *claim_tmp = NULL;
int index;
if (!hash)
return NULL;
index = choose_claim(data, hash->size);
head = &hash->table[index];
rcu_read_lock();
hlist_for_each_entry_rcu(claim, node, head, hash_entry) {
if (!compare_claim(&claim->hash_entry, data))
continue;
if (!atomic_inc_not_zero(&claim->refcount))
continue;
claim_tmp = claim;
break;
}
rcu_read_unlock();
return claim_tmp;
}
static struct backbone_gw *backbone_hash_find(struct bat_priv *bat_priv,
uint8_t *addr, short vid)
{
struct hashtable_t *hash = bat_priv->backbone_hash;
struct hlist_head *head;
struct hlist_node *node;
struct backbone_gw search_entry, *backbone_gw;
struct backbone_gw *backbone_gw_tmp = NULL;
int index;
if (!hash)
return NULL;
memcpy(search_entry.orig, addr, ETH_ALEN);
search_entry.vid = vid;
index = choose_backbone_gw(&search_entry, hash->size);
head = &hash->table[index];
rcu_read_lock();
hlist_for_each_entry_rcu(backbone_gw, node, head, hash_entry) {
if (!compare_backbone_gw(&backbone_gw->hash_entry,
&search_entry))
continue;
if (!atomic_inc_not_zero(&backbone_gw->refcount))
continue;
backbone_gw_tmp = backbone_gw;
break;
}
rcu_read_unlock();
return backbone_gw_tmp;
}
static void bla_del_backbone_claims(struct backbone_gw *backbone_gw)
{
struct hashtable_t *hash;
struct hlist_node *node, *node_tmp;
struct hlist_head *head;
struct claim *claim;
int i;
spinlock_t *list_lock;
hash = backbone_gw->bat_priv->claim_hash;
if (!hash)
return;
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
list_lock = &hash->list_locks[i];
spin_lock_bh(list_lock);
hlist_for_each_entry_safe(claim, node, node_tmp,
head, hash_entry) {
if (claim->backbone_gw != backbone_gw)
continue;
claim_free_ref(claim);
hlist_del_rcu(node);
}
spin_unlock_bh(list_lock);
}
backbone_gw->crc = BLA_CRC_INIT;
}
static void bla_send_claim(struct bat_priv *bat_priv, uint8_t *mac,
short vid, int claimtype)
{
struct sk_buff *skb;
struct ethhdr *ethhdr;
struct hard_iface *primary_if;
struct net_device *soft_iface;
uint8_t *hw_src;
struct bla_claim_dst local_claim_dest;
uint32_t zeroip = 0;
primary_if = primary_if_get_selected(bat_priv);
if (!primary_if)
return;
memcpy(&local_claim_dest, &bat_priv->claim_dest,
sizeof(local_claim_dest));
local_claim_dest.type = claimtype;
soft_iface = primary_if->soft_iface;
skb = arp_create(ARPOP_REPLY, ETH_P_ARP,
zeroip,
primary_if->soft_iface,
zeroip,
NULL,
primary_if->net_dev->dev_addr,
(uint8_t *)&local_claim_dest);
if (!skb)
goto out;
ethhdr = (struct ethhdr *)skb->data;
hw_src = (uint8_t *)ethhdr + ETH_HLEN + sizeof(struct arphdr);
switch (claimtype) {
case CLAIM_TYPE_ADD:
memcpy(ethhdr->h_source, mac, ETH_ALEN);
bat_dbg(DBG_BLA, bat_priv,
"bla_send_claim(): CLAIM %pM on vid %d\n", mac, vid);
break;
case CLAIM_TYPE_DEL:
memcpy(hw_src, mac, ETH_ALEN);
bat_dbg(DBG_BLA, bat_priv,
"bla_send_claim(): UNCLAIM %pM on vid %d\n", mac, vid);
break;
case CLAIM_TYPE_ANNOUNCE:
memcpy(hw_src, mac, ETH_ALEN);
bat_dbg(DBG_BLA, bat_priv,
"bla_send_claim(): ANNOUNCE of %pM on vid %d\n",
ethhdr->h_source, vid);
break;
case CLAIM_TYPE_REQUEST:
memcpy(hw_src, mac, ETH_ALEN);
memcpy(ethhdr->h_dest, mac, ETH_ALEN);
bat_dbg(DBG_BLA, bat_priv,
"bla_send_claim(): REQUEST of %pM to %pMon vid %d\n",
ethhdr->h_source, ethhdr->h_dest, vid);
break;
}
if (vid != -1)
skb = vlan_insert_tag(skb, vid);
skb_reset_mac_header(skb);
skb->protocol = eth_type_trans(skb, soft_iface);
bat_priv->stats.rx_packets++;
bat_priv->stats.rx_bytes += skb->len + ETH_HLEN;
soft_iface->last_rx = jiffies;
netif_rx(skb);
out:
if (primary_if)
hardif_free_ref(primary_if);
}
static struct backbone_gw *bla_get_backbone_gw(struct bat_priv *bat_priv,
uint8_t *orig, short vid)
{
struct backbone_gw *entry;
struct orig_node *orig_node;
int hash_added;
entry = backbone_hash_find(bat_priv, orig, vid);
if (entry)
return entry;
bat_dbg(DBG_BLA, bat_priv,
"bla_get_backbone_gw(): not found (%pM, %d), creating new entry\n",
orig, vid);
entry = kzalloc(sizeof(*entry), GFP_ATOMIC);
if (!entry)
return NULL;
entry->vid = vid;
entry->lasttime = jiffies;
entry->crc = BLA_CRC_INIT;
entry->bat_priv = bat_priv;
atomic_set(&entry->request_sent, 0);
memcpy(entry->orig, orig, ETH_ALEN);
atomic_set(&entry->refcount, 2);
hash_added = hash_add(bat_priv->backbone_hash, compare_backbone_gw,
choose_backbone_gw, entry, &entry->hash_entry);
if (unlikely(hash_added != 0)) {
kfree(entry);
return NULL;
}
orig_node = orig_hash_find(bat_priv, orig);
if (orig_node) {
tt_global_del_orig(bat_priv, orig_node,
"became a backbone gateway");
orig_node_free_ref(orig_node);
}
return entry;
}
static void bla_update_own_backbone_gw(struct bat_priv *bat_priv,
struct hard_iface *primary_if,
short vid)
{
struct backbone_gw *backbone_gw;
backbone_gw = bla_get_backbone_gw(bat_priv,
primary_if->net_dev->dev_addr, vid);
if (unlikely(!backbone_gw))
return;
backbone_gw->lasttime = jiffies;
backbone_gw_free_ref(backbone_gw);
}
static void bla_answer_request(struct bat_priv *bat_priv,
struct hard_iface *primary_if, short vid)
{
struct hlist_node *node;
struct hlist_head *head;
struct hashtable_t *hash;
struct claim *claim;
struct backbone_gw *backbone_gw;
int i;
bat_dbg(DBG_BLA, bat_priv,
"bla_answer_request(): received a claim request, send all of our own claims again\n");
backbone_gw = backbone_hash_find(bat_priv,
primary_if->net_dev->dev_addr, vid);
if (!backbone_gw)
return;
hash = bat_priv->claim_hash;
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
rcu_read_lock();
hlist_for_each_entry_rcu(claim, node, head, hash_entry) {
if (claim->backbone_gw != backbone_gw)
continue;
bla_send_claim(bat_priv, claim->addr, claim->vid,
CLAIM_TYPE_ADD);
}
rcu_read_unlock();
}
bla_send_announce(bat_priv, backbone_gw);
backbone_gw_free_ref(backbone_gw);
}
static void bla_send_request(struct backbone_gw *backbone_gw)
{
bla_del_backbone_claims(backbone_gw);
bat_dbg(DBG_BLA, backbone_gw->bat_priv,
"Sending REQUEST to %pM\n",
backbone_gw->orig);
bla_send_claim(backbone_gw->bat_priv, backbone_gw->orig,
backbone_gw->vid, CLAIM_TYPE_REQUEST);
if (!atomic_read(&backbone_gw->request_sent)) {
atomic_inc(&backbone_gw->bat_priv->bla_num_requests);
atomic_set(&backbone_gw->request_sent, 1);
}
}
static void bla_send_announce(struct bat_priv *bat_priv,
struct backbone_gw *backbone_gw)
{
uint8_t mac[ETH_ALEN];
uint16_t crc;
memcpy(mac, announce_mac, 4);
crc = htons(backbone_gw->crc);
memcpy(&mac[4], (uint8_t *)&crc, 2);
bla_send_claim(bat_priv, mac, backbone_gw->vid, CLAIM_TYPE_ANNOUNCE);
}
static void bla_add_claim(struct bat_priv *bat_priv, const uint8_t *mac,
const short vid, struct backbone_gw *backbone_gw)
{
struct claim *claim;
struct claim search_claim;
int hash_added;
memcpy(search_claim.addr, mac, ETH_ALEN);
search_claim.vid = vid;
claim = claim_hash_find(bat_priv, &search_claim);
if (!claim) {
claim = kzalloc(sizeof(*claim), GFP_ATOMIC);
if (!claim)
return;
memcpy(claim->addr, mac, ETH_ALEN);
claim->vid = vid;
claim->lasttime = jiffies;
claim->backbone_gw = backbone_gw;
atomic_set(&claim->refcount, 2);
bat_dbg(DBG_BLA, bat_priv,
"bla_add_claim(): adding new entry %pM, vid %d to hash ...\n",
mac, vid);
hash_added = hash_add(bat_priv->claim_hash, compare_claim,
choose_claim, claim, &claim->hash_entry);
if (unlikely(hash_added != 0)) {
kfree(claim);
return;
}
} else {
claim->lasttime = jiffies;
if (claim->backbone_gw == backbone_gw)
goto claim_free_ref;
bat_dbg(DBG_BLA, bat_priv,
"bla_add_claim(): changing ownership for %pM, vid %d\n",
mac, vid);
claim->backbone_gw->crc ^=
crc16(0, claim->addr, ETH_ALEN);
backbone_gw_free_ref(claim->backbone_gw);
}
atomic_inc(&backbone_gw->refcount);
claim->backbone_gw = backbone_gw;
backbone_gw->crc ^= crc16(0, claim->addr, ETH_ALEN);
backbone_gw->lasttime = jiffies;
claim_free_ref:
claim_free_ref(claim);
}
static void bla_del_claim(struct bat_priv *bat_priv, const uint8_t *mac,
const short vid)
{
struct claim search_claim, *claim;
memcpy(search_claim.addr, mac, ETH_ALEN);
search_claim.vid = vid;
claim = claim_hash_find(bat_priv, &search_claim);
if (!claim)
return;
bat_dbg(DBG_BLA, bat_priv, "bla_del_claim(): %pM, vid %d\n", mac, vid);
hash_remove(bat_priv->claim_hash, compare_claim, choose_claim, claim);
claim_free_ref(claim);
claim->backbone_gw->crc ^= crc16(0, claim->addr, ETH_ALEN);
claim_free_ref(claim);
}
static int handle_announce(struct bat_priv *bat_priv,
uint8_t *an_addr, uint8_t *backbone_addr, short vid)
{
struct backbone_gw *backbone_gw;
uint16_t crc;
if (memcmp(an_addr, announce_mac, 4) != 0)
return 0;
backbone_gw = bla_get_backbone_gw(bat_priv, backbone_addr, vid);
if (unlikely(!backbone_gw))
return 1;
backbone_gw->lasttime = jiffies;
crc = ntohs(*((uint16_t *)(&an_addr[4])));
bat_dbg(DBG_BLA, bat_priv,
"handle_announce(): ANNOUNCE vid %d (sent by %pM)... CRC = %04x\n",
vid, backbone_gw->orig, crc);
if (backbone_gw->crc != crc) {
bat_dbg(DBG_BLA, backbone_gw->bat_priv,
"handle_announce(): CRC FAILED for %pM/%d (my = %04x, sent = %04x)\n",
backbone_gw->orig, backbone_gw->vid, backbone_gw->crc,
crc);
bla_send_request(backbone_gw);
} else {
if (atomic_read(&backbone_gw->request_sent)) {
atomic_dec(&backbone_gw->bat_priv->bla_num_requests);
atomic_set(&backbone_gw->request_sent, 0);
}
}
backbone_gw_free_ref(backbone_gw);
return 1;
}
static int handle_request(struct bat_priv *bat_priv,
struct hard_iface *primary_if,
uint8_t *backbone_addr,
struct ethhdr *ethhdr, short vid)
{
if (!compare_eth(backbone_addr, ethhdr->h_dest))
return 0;
if (!compare_eth(ethhdr->h_dest, primary_if->net_dev->dev_addr))
return 1;
bat_dbg(DBG_BLA, bat_priv,
"handle_request(): REQUEST vid %d (sent by %pM)...\n",
vid, ethhdr->h_source);
bla_answer_request(bat_priv, primary_if, vid);
return 1;
}
static int handle_unclaim(struct bat_priv *bat_priv,
struct hard_iface *primary_if,
uint8_t *backbone_addr,
uint8_t *claim_addr, short vid)
{
struct backbone_gw *backbone_gw;
if (primary_if && compare_eth(backbone_addr,
primary_if->net_dev->dev_addr))
bla_send_claim(bat_priv, claim_addr, vid, CLAIM_TYPE_DEL);
backbone_gw = backbone_hash_find(bat_priv, backbone_addr, vid);
if (!backbone_gw)
return 1;
bat_dbg(DBG_BLA, bat_priv,
"handle_unclaim(): UNCLAIM %pM on vid %d (sent by %pM)...\n",
claim_addr, vid, backbone_gw->orig);
bla_del_claim(bat_priv, claim_addr, vid);
backbone_gw_free_ref(backbone_gw);
return 1;
}
static int handle_claim(struct bat_priv *bat_priv,
struct hard_iface *primary_if, uint8_t *backbone_addr,
uint8_t *claim_addr, short vid)
{
struct backbone_gw *backbone_gw;
backbone_gw = bla_get_backbone_gw(bat_priv, backbone_addr, vid);
if (unlikely(!backbone_gw))
return 1;
bla_add_claim(bat_priv, claim_addr, vid, backbone_gw);
if (compare_eth(backbone_addr, primary_if->net_dev->dev_addr))
bla_send_claim(bat_priv, claim_addr, vid, CLAIM_TYPE_ADD);
backbone_gw_free_ref(backbone_gw);
return 1;
}
static int check_claim_group(struct bat_priv *bat_priv,
struct hard_iface *primary_if,
uint8_t *hw_src, uint8_t *hw_dst,
struct ethhdr *ethhdr)
{
uint8_t *backbone_addr;
struct orig_node *orig_node;
struct bla_claim_dst *bla_dst, *bla_dst_own;
bla_dst = (struct bla_claim_dst *)hw_dst;
bla_dst_own = &bat_priv->claim_dest;
if (memcmp(bla_dst->magic, bla_dst_own->magic,
sizeof(bla_dst->magic)) != 0)
return 0;
switch (bla_dst->type) {
case CLAIM_TYPE_ADD:
backbone_addr = hw_src;
break;
case CLAIM_TYPE_REQUEST:
case CLAIM_TYPE_ANNOUNCE:
case CLAIM_TYPE_DEL:
backbone_addr = ethhdr->h_source;
break;
default:
return 0;
}
if (compare_eth(backbone_addr, primary_if->net_dev->dev_addr))
return 0;
if (bla_dst->group == bla_dst_own->group)
return 2;
orig_node = orig_hash_find(bat_priv, backbone_addr);
if (!orig_node)
return 1;
if (ntohs(bla_dst->group) > ntohs(bla_dst_own->group)) {
bat_dbg(DBG_BLA, bat_priv,
"taking other backbones claim group: %04x\n",
ntohs(bla_dst->group));
bla_dst_own->group = bla_dst->group;
}
orig_node_free_ref(orig_node);
return 2;
}
static int bla_process_claim(struct bat_priv *bat_priv,
struct hard_iface *primary_if,
struct sk_buff *skb)
{
struct ethhdr *ethhdr;
struct vlan_ethhdr *vhdr;
struct arphdr *arphdr;
uint8_t *hw_src, *hw_dst;
struct bla_claim_dst *bla_dst;
uint16_t proto;
int headlen;
short vid = -1;
int ret;
ethhdr = (struct ethhdr *)skb_mac_header(skb);
if (ntohs(ethhdr->h_proto) == ETH_P_8021Q) {
vhdr = (struct vlan_ethhdr *)ethhdr;
vid = ntohs(vhdr->h_vlan_TCI) & VLAN_VID_MASK;
proto = ntohs(vhdr->h_vlan_encapsulated_proto);
headlen = sizeof(*vhdr);
} else {
proto = ntohs(ethhdr->h_proto);
headlen = ETH_HLEN;
}
if (proto != ETH_P_ARP)
return 0;
if (unlikely(!pskb_may_pull(skb, headlen + arp_hdr_len(skb->dev))))
return 0;
ethhdr = (struct ethhdr *)skb_mac_header(skb);
arphdr = (struct arphdr *)((uint8_t *)ethhdr + headlen);
if (arphdr->ar_hrd != htons(ARPHRD_ETHER))
return 0;
if (arphdr->ar_pro != htons(ETH_P_IP))
return 0;
if (arphdr->ar_hln != ETH_ALEN)
return 0;
if (arphdr->ar_pln != 4)
return 0;
hw_src = (uint8_t *)arphdr + sizeof(struct arphdr);
hw_dst = hw_src + ETH_ALEN + 4;
bla_dst = (struct bla_claim_dst *)hw_dst;
ret = check_claim_group(bat_priv, primary_if, hw_src, hw_dst, ethhdr);
if (ret == 1)
bat_dbg(DBG_BLA, bat_priv,
"bla_process_claim(): received a claim frame from another group. From: %pM on vid %d ...(hw_src %pM, hw_dst %pM)\n",
ethhdr->h_source, vid, hw_src, hw_dst);
if (ret < 2)
return ret;
bla_update_own_backbone_gw(bat_priv, primary_if, vid);
switch (bla_dst->type) {
case CLAIM_TYPE_ADD:
if (handle_claim(bat_priv, primary_if, hw_src,
ethhdr->h_source, vid))
return 1;
break;
case CLAIM_TYPE_DEL:
if (handle_unclaim(bat_priv, primary_if,
ethhdr->h_source, hw_src, vid))
return 1;
break;
case CLAIM_TYPE_ANNOUNCE:
if (handle_announce(bat_priv, hw_src, ethhdr->h_source, vid))
return 1;
break;
case CLAIM_TYPE_REQUEST:
if (handle_request(bat_priv, primary_if, hw_src, ethhdr, vid))
return 1;
break;
}
bat_dbg(DBG_BLA, bat_priv,
"bla_process_claim(): ERROR - this looks like a claim frame, but is useless. eth src %pM on vid %d ...(hw_src %pM, hw_dst %pM)\n",
ethhdr->h_source, vid, hw_src, hw_dst);
return 1;
}
static void bla_purge_backbone_gw(struct bat_priv *bat_priv, int now)
{
struct backbone_gw *backbone_gw;
struct hlist_node *node, *node_tmp;
struct hlist_head *head;
struct hashtable_t *hash;
spinlock_t *list_lock;
int i;
hash = bat_priv->backbone_hash;
if (!hash)
return;
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
list_lock = &hash->list_locks[i];
spin_lock_bh(list_lock);
hlist_for_each_entry_safe(backbone_gw, node, node_tmp,
head, hash_entry) {
if (now)
goto purge_now;
if (!has_timed_out(backbone_gw->lasttime,
BLA_BACKBONE_TIMEOUT))
continue;
bat_dbg(DBG_BLA, backbone_gw->bat_priv,
"bla_purge_backbone_gw(): backbone gw %pM timed out\n",
backbone_gw->orig);
purge_now:
if (atomic_read(&backbone_gw->request_sent))
atomic_dec(&bat_priv->bla_num_requests);
bla_del_backbone_claims(backbone_gw);
hlist_del_rcu(node);
backbone_gw_free_ref(backbone_gw);
}
spin_unlock_bh(list_lock);
}
}
static void bla_purge_claims(struct bat_priv *bat_priv,
struct hard_iface *primary_if, int now)
{
struct claim *claim;
struct hlist_node *node;
struct hlist_head *head;
struct hashtable_t *hash;
int i;
hash = bat_priv->claim_hash;
if (!hash)
return;
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
rcu_read_lock();
hlist_for_each_entry_rcu(claim, node, head, hash_entry) {
if (now)
goto purge_now;
if (!compare_eth(claim->backbone_gw->orig,
primary_if->net_dev->dev_addr))
continue;
if (!has_timed_out(claim->lasttime,
BLA_CLAIM_TIMEOUT))
continue;
bat_dbg(DBG_BLA, bat_priv,
"bla_purge_claims(): %pM, vid %d, time out\n",
claim->addr, claim->vid);
purge_now:
handle_unclaim(bat_priv, primary_if,
claim->backbone_gw->orig,
claim->addr, claim->vid);
}
rcu_read_unlock();
}
}
void bla_update_orig_address(struct bat_priv *bat_priv,
struct hard_iface *primary_if,
struct hard_iface *oldif)
{
struct backbone_gw *backbone_gw;
struct hlist_node *node;
struct hlist_head *head;
struct hashtable_t *hash;
int i;
bat_priv->claim_dest.group =
htons(crc16(0, primary_if->net_dev->dev_addr, ETH_ALEN));
if (!oldif) {
bla_purge_claims(bat_priv, NULL, 1);
bla_purge_backbone_gw(bat_priv, 1);
return;
}
hash = bat_priv->backbone_hash;
if (!hash)
return;
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
rcu_read_lock();
hlist_for_each_entry_rcu(backbone_gw, node, head, hash_entry) {
if (!compare_eth(backbone_gw->orig,
oldif->net_dev->dev_addr))
continue;
memcpy(backbone_gw->orig,
primary_if->net_dev->dev_addr, ETH_ALEN);
bla_send_announce(bat_priv, backbone_gw);
}
rcu_read_unlock();
}
}
static void bla_start_timer(struct bat_priv *bat_priv)
{
INIT_DELAYED_WORK(&bat_priv->bla_work, bla_periodic_work);
queue_delayed_work(bat_event_workqueue, &bat_priv->bla_work,
msecs_to_jiffies(BLA_PERIOD_LENGTH));
}
static void bla_periodic_work(struct work_struct *work)
{
struct delayed_work *delayed_work =
container_of(work, struct delayed_work, work);
struct bat_priv *bat_priv =
container_of(delayed_work, struct bat_priv, bla_work);
struct hlist_node *node;
struct hlist_head *head;
struct backbone_gw *backbone_gw;
struct hashtable_t *hash;
struct hard_iface *primary_if;
int i;
primary_if = primary_if_get_selected(bat_priv);
if (!primary_if)
goto out;
bla_purge_claims(bat_priv, primary_if, 0);
bla_purge_backbone_gw(bat_priv, 0);
if (!atomic_read(&bat_priv->bridge_loop_avoidance))
goto out;
hash = bat_priv->backbone_hash;
if (!hash)
goto out;
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
rcu_read_lock();
hlist_for_each_entry_rcu(backbone_gw, node, head, hash_entry) {
if (!compare_eth(backbone_gw->orig,
primary_if->net_dev->dev_addr))
continue;
backbone_gw->lasttime = jiffies;
bla_send_announce(bat_priv, backbone_gw);
}
rcu_read_unlock();
}
out:
if (primary_if)
hardif_free_ref(primary_if);
bla_start_timer(bat_priv);
}
int bla_init(struct bat_priv *bat_priv)
{
int i;
uint8_t claim_dest[ETH_ALEN] = {0xff, 0x43, 0x05, 0x00, 0x00, 0x00};
struct hard_iface *primary_if;
bat_dbg(DBG_BLA, bat_priv, "bla hash registering\n");
memcpy(&bat_priv->claim_dest.magic, claim_dest, 3);
bat_priv->claim_dest.type = 0;
primary_if = primary_if_get_selected(bat_priv);
if (primary_if) {
bat_priv->claim_dest.group =
htons(crc16(0, primary_if->net_dev->dev_addr,
ETH_ALEN));
hardif_free_ref(primary_if);
} else {
bat_priv->claim_dest.group = 0;
}
for (i = 0; i < DUPLIST_SIZE; i++)
bat_priv->bcast_duplist[i].entrytime =
jiffies - msecs_to_jiffies(DUPLIST_TIMEOUT);
bat_priv->bcast_duplist_curr = 0;
if (bat_priv->claim_hash)
return 1;
bat_priv->claim_hash = hash_new(128);
bat_priv->backbone_hash = hash_new(32);
if (!bat_priv->claim_hash || !bat_priv->backbone_hash)
return -1;
bat_dbg(DBG_BLA, bat_priv, "bla hashes initialized\n");
bla_start_timer(bat_priv);
return 1;
}
int bla_check_bcast_duplist(struct bat_priv *bat_priv,
struct bcast_packet *bcast_packet,
int hdr_size)
{
int i, length, curr;
uint8_t *content;
uint16_t crc;
struct bcast_duplist_entry *entry;
length = hdr_size - sizeof(*bcast_packet);
content = (uint8_t *)bcast_packet;
content += sizeof(*bcast_packet);
crc = crc16(0, content, length);
for (i = 0 ; i < DUPLIST_SIZE; i++) {
curr = (bat_priv->bcast_duplist_curr + i) % DUPLIST_SIZE;
entry = &bat_priv->bcast_duplist[curr];
if (has_timed_out(entry->entrytime, DUPLIST_TIMEOUT))
break;
if (entry->crc != crc)
continue;
if (compare_eth(entry->orig, bcast_packet->orig))
continue;
return 1;
}
curr = (bat_priv->bcast_duplist_curr + DUPLIST_SIZE - 1) % DUPLIST_SIZE;
entry = &bat_priv->bcast_duplist[curr];
entry->crc = crc;
entry->entrytime = jiffies;
memcpy(entry->orig, bcast_packet->orig, ETH_ALEN);
bat_priv->bcast_duplist_curr = curr;
return 0;
}
int bla_is_backbone_gw_orig(struct bat_priv *bat_priv, uint8_t *orig)
{
struct hashtable_t *hash = bat_priv->backbone_hash;
struct hlist_head *head;
struct hlist_node *node;
struct backbone_gw *backbone_gw;
int i;
if (!atomic_read(&bat_priv->bridge_loop_avoidance))
return 0;
if (!hash)
return 0;
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
rcu_read_lock();
hlist_for_each_entry_rcu(backbone_gw, node, head, hash_entry) {
if (compare_eth(backbone_gw->orig, orig)) {
rcu_read_unlock();
return 1;
}
}
rcu_read_unlock();
}
return 0;
}
int bla_is_backbone_gw(struct sk_buff *skb,
struct orig_node *orig_node, int hdr_size)
{
struct ethhdr *ethhdr;
struct vlan_ethhdr *vhdr;
struct backbone_gw *backbone_gw;
short vid = -1;
if (!atomic_read(&orig_node->bat_priv->bridge_loop_avoidance))
return 0;
if (!pskb_may_pull(skb, hdr_size + ETH_HLEN))
return 0;
ethhdr = (struct ethhdr *)(((uint8_t *)skb->data) + hdr_size);
if (ntohs(ethhdr->h_proto) == ETH_P_8021Q) {
if (!pskb_may_pull(skb, hdr_size + sizeof(struct vlan_ethhdr)))
return 0;
vhdr = (struct vlan_ethhdr *)(((uint8_t *)skb->data) +
hdr_size);
vid = ntohs(vhdr->h_vlan_TCI) & VLAN_VID_MASK;
}
backbone_gw = backbone_hash_find(orig_node->bat_priv,
orig_node->orig, vid);
if (!backbone_gw)
return 0;
backbone_gw_free_ref(backbone_gw);
return 1;
}
void bla_free(struct bat_priv *bat_priv)
{
struct hard_iface *primary_if;
cancel_delayed_work_sync(&bat_priv->bla_work);
primary_if = primary_if_get_selected(bat_priv);
if (bat_priv->claim_hash) {
bla_purge_claims(bat_priv, primary_if, 1);
hash_destroy(bat_priv->claim_hash);
bat_priv->claim_hash = NULL;
}
if (bat_priv->backbone_hash) {
bla_purge_backbone_gw(bat_priv, 1);
hash_destroy(bat_priv->backbone_hash);
bat_priv->backbone_hash = NULL;
}
if (primary_if)
hardif_free_ref(primary_if);
}
int bla_rx(struct bat_priv *bat_priv, struct sk_buff *skb, short vid,
bool is_bcast)
{
struct ethhdr *ethhdr;
struct claim search_claim, *claim = NULL;
struct hard_iface *primary_if;
int ret;
ethhdr = (struct ethhdr *)skb_mac_header(skb);
primary_if = primary_if_get_selected(bat_priv);
if (!primary_if)
goto handled;
if (!atomic_read(&bat_priv->bridge_loop_avoidance))
goto allow;
if (unlikely(atomic_read(&bat_priv->bla_num_requests)))
if (is_multicast_ether_addr(ethhdr->h_dest) && is_bcast)
goto handled;
memcpy(search_claim.addr, ethhdr->h_source, ETH_ALEN);
search_claim.vid = vid;
claim = claim_hash_find(bat_priv, &search_claim);
if (!claim) {
handle_claim(bat_priv, primary_if,
primary_if->net_dev->dev_addr,
ethhdr->h_source, vid);
goto allow;
}
if (compare_eth(claim->backbone_gw->orig,
primary_if->net_dev->dev_addr)) {
claim->lasttime = jiffies;
goto allow;
}
if (is_multicast_ether_addr(ethhdr->h_dest) && is_bcast) {
goto handled;
} else {
handle_claim(bat_priv, primary_if,
primary_if->net_dev->dev_addr,
ethhdr->h_source, vid);
goto allow;
}
allow:
bla_update_own_backbone_gw(bat_priv, primary_if, vid);
ret = 0;
goto out;
handled:
kfree_skb(skb);
ret = 1;
out:
if (primary_if)
hardif_free_ref(primary_if);
if (claim)
claim_free_ref(claim);
return ret;
}
int bla_tx(struct bat_priv *bat_priv, struct sk_buff *skb, short vid)
{
struct ethhdr *ethhdr;
struct claim search_claim, *claim = NULL;
struct hard_iface *primary_if;
int ret = 0;
primary_if = primary_if_get_selected(bat_priv);
if (!primary_if)
goto out;
if (!atomic_read(&bat_priv->bridge_loop_avoidance))
goto allow;
skb_reset_mac_header(skb);
if (bla_process_claim(bat_priv, primary_if, skb))
goto handled;
ethhdr = (struct ethhdr *)skb_mac_header(skb);
if (unlikely(atomic_read(&bat_priv->bla_num_requests)))
if (is_multicast_ether_addr(ethhdr->h_dest))
goto handled;
memcpy(search_claim.addr, ethhdr->h_source, ETH_ALEN);
search_claim.vid = vid;
claim = claim_hash_find(bat_priv, &search_claim);
if (!claim)
goto allow;
if (compare_eth(claim->backbone_gw->orig,
primary_if->net_dev->dev_addr)) {
handle_unclaim(bat_priv, primary_if,
primary_if->net_dev->dev_addr,
ethhdr->h_source, vid);
goto allow;
}
if (is_multicast_ether_addr(ethhdr->h_dest)) {
goto handled;
} else {
goto allow;
}
allow:
bla_update_own_backbone_gw(bat_priv, primary_if, vid);
ret = 0;
goto out;
handled:
ret = 1;
out:
if (primary_if)
hardif_free_ref(primary_if);
if (claim)
claim_free_ref(claim);
return ret;
}
int bla_claim_table_seq_print_text(struct seq_file *seq, void *offset)
{
struct net_device *net_dev = (struct net_device *)seq->private;
struct bat_priv *bat_priv = netdev_priv(net_dev);
struct hashtable_t *hash = bat_priv->claim_hash;
struct claim *claim;
struct hard_iface *primary_if;
struct hlist_node *node;
struct hlist_head *head;
uint32_t i;
bool is_own;
int ret = 0;
primary_if = primary_if_get_selected(bat_priv);
if (!primary_if) {
ret = seq_printf(seq,
"BATMAN mesh %s disabled - please specify interfaces to enable it\n",
net_dev->name);
goto out;
}
if (primary_if->if_status != IF_ACTIVE) {
ret = seq_printf(seq,
"BATMAN mesh %s disabled - primary interface not active\n",
net_dev->name);
goto out;
}
seq_printf(seq,
"Claims announced for the mesh %s (orig %pM, group id %04x)\n",
net_dev->name, primary_if->net_dev->dev_addr,
ntohs(bat_priv->claim_dest.group));
seq_printf(seq, " %-17s %-5s %-17s [o] (%-4s)\n",
"Client", "VID", "Originator", "CRC");
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
rcu_read_lock();
hlist_for_each_entry_rcu(claim, node, head, hash_entry) {
is_own = compare_eth(claim->backbone_gw->orig,
primary_if->net_dev->dev_addr);
seq_printf(seq, " * %pM on % 5d by %pM [%c] (%04x)\n",
claim->addr, claim->vid,
claim->backbone_gw->orig,
(is_own ? 'x' : ' '),
claim->backbone_gw->crc);
}
rcu_read_unlock();
}
out:
if (primary_if)
hardif_free_ref(primary_if);
return ret;
}
