static inline uint32_t batadv_choose_claim(const void *data, uint32_t size)
{
struct batadv_bla_claim *claim = (struct batadv_bla_claim *)data;
uint32_t hash = 0;
hash = batadv_hash_bytes(hash, &claim->addr, sizeof(claim->addr));
hash = batadv_hash_bytes(hash, &claim->vid, sizeof(claim->vid));
hash += (hash << 3);
hash ^= (hash >> 11);
hash += (hash << 15);
return hash % size;
}
static inline uint32_t batadv_choose_backbone_gw(const void *data,
uint32_t size)
{
const struct batadv_bla_claim *claim = (struct batadv_bla_claim *)data;
uint32_t hash = 0;
hash = batadv_hash_bytes(hash, &claim->addr, sizeof(claim->addr));
hash = batadv_hash_bytes(hash, &claim->vid, sizeof(claim->vid));
hash += (hash << 3);
hash ^= (hash >> 11);
hash += (hash << 15);
return hash % size;
}
static int batadv_compare_backbone_gw(const struct hlist_node *node,
const void *data2)
{
const void *data1 = container_of(node, struct batadv_bla_backbone_gw,
hash_entry);
const struct batadv_bla_backbone_gw *gw1 = data1, *gw2 = data2;
if (!batadv_compare_eth(gw1->orig, gw2->orig))
return 0;
if (gw1->vid != gw2->vid)
return 0;
return 1;
}
static int batadv_compare_claim(const struct hlist_node *node,
const void *data2)
{
const void *data1 = container_of(node, struct batadv_bla_claim,
hash_entry);
const struct batadv_bla_claim *cl1 = data1, *cl2 = data2;
if (!batadv_compare_eth(cl1->addr, cl2->addr))
return 0;
if (cl1->vid != cl2->vid)
return 0;
return 1;
}
static void
batadv_backbone_gw_free_ref(struct batadv_bla_backbone_gw *backbone_gw)
{
if (atomic_dec_and_test(&backbone_gw->refcount))
kfree_rcu(backbone_gw, rcu);
}
static void batadv_claim_free_rcu(struct rcu_head *rcu)
{
struct batadv_bla_claim *claim;
claim = container_of(rcu, struct batadv_bla_claim, rcu);
batadv_backbone_gw_free_ref(claim->backbone_gw);
kfree(claim);
}
static void batadv_claim_free_ref(struct batadv_bla_claim *claim)
{
if (atomic_dec_and_test(&claim->refcount))
call_rcu(&claim->rcu, batadv_claim_free_rcu);
}
static struct batadv_bla_claim
*batadv_claim_hash_find(struct batadv_priv *bat_priv,
struct batadv_bla_claim *data)
{
struct batadv_hashtable *hash = bat_priv->bla.claim_hash;
struct hlist_head *head;
struct batadv_bla_claim *claim;
struct batadv_bla_claim *claim_tmp = NULL;
int index;
if (!hash)
return NULL;
index = batadv_choose_claim(data, hash->size);
head = &hash->table[index];
rcu_read_lock();
hlist_for_each_entry_rcu(claim, head, hash_entry) {
if (!batadv_compare_claim(&claim->hash_entry, data))
continue;
if (!atomic_inc_not_zero(&claim->refcount))
continue;
claim_tmp = claim;
break;
}
rcu_read_unlock();
return claim_tmp;
}
static struct batadv_bla_backbone_gw *
batadv_backbone_hash_find(struct batadv_priv *bat_priv,
uint8_t *addr, short vid)
{
struct batadv_hashtable *hash = bat_priv->bla.backbone_hash;
struct hlist_head *head;
struct batadv_bla_backbone_gw search_entry, *backbone_gw;
struct batadv_bla_backbone_gw *backbone_gw_tmp = NULL;
int index;
if (!hash)
return NULL;
memcpy(search_entry.orig, addr, ETH_ALEN);
search_entry.vid = vid;
index = batadv_choose_backbone_gw(&search_entry, hash->size);
head = &hash->table[index];
rcu_read_lock();
hlist_for_each_entry_rcu(backbone_gw, head, hash_entry) {
if (!batadv_compare_backbone_gw(&backbone_gw->hash_entry,
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
static void
batadv_bla_del_backbone_claims(struct batadv_bla_backbone_gw *backbone_gw)
{
struct batadv_hashtable *hash;
struct hlist_node *node_tmp;
struct hlist_head *head;
struct batadv_bla_claim *claim;
int i;
spinlock_t *list_lock;
hash = backbone_gw->bat_priv->bla.claim_hash;
if (!hash)
return;
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
list_lock = &hash->list_locks[i];
spin_lock_bh(list_lock);
hlist_for_each_entry_safe(claim, node_tmp,
head, hash_entry) {
if (claim->backbone_gw != backbone_gw)
continue;
batadv_claim_free_ref(claim);
hlist_del_rcu(&claim->hash_entry);
}
spin_unlock_bh(list_lock);
}
backbone_gw->crc = BATADV_BLA_CRC_INIT;
}
static void batadv_bla_send_claim(struct batadv_priv *bat_priv, uint8_t *mac,
short vid, int claimtype)
{
struct sk_buff *skb;
struct ethhdr *ethhdr;
struct batadv_hard_iface *primary_if;
struct net_device *soft_iface;
uint8_t *hw_src;
struct batadv_bla_claim_dst local_claim_dest;
__be32 zeroip = 0;
primary_if = batadv_primary_if_get_selected(bat_priv);
if (!primary_if)
return;
memcpy(&local_claim_dest, &bat_priv->bla.claim_dest,
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
case BATADV_CLAIM_TYPE_CLAIM:
memcpy(ethhdr->h_source, mac, ETH_ALEN);
batadv_dbg(BATADV_DBG_BLA, bat_priv,
"bla_send_claim(): CLAIM %pM on vid %d\n", mac, vid);
break;
case BATADV_CLAIM_TYPE_UNCLAIM:
memcpy(hw_src, mac, ETH_ALEN);
batadv_dbg(BATADV_DBG_BLA, bat_priv,
"bla_send_claim(): UNCLAIM %pM on vid %d\n", mac,
vid);
break;
case BATADV_CLAIM_TYPE_ANNOUNCE:
memcpy(hw_src, mac, ETH_ALEN);
batadv_dbg(BATADV_DBG_BLA, bat_priv,
"bla_send_claim(): ANNOUNCE of %pM on vid %d\n",
ethhdr->h_source, vid);
break;
case BATADV_CLAIM_TYPE_REQUEST:
memcpy(hw_src, mac, ETH_ALEN);
memcpy(ethhdr->h_dest, mac, ETH_ALEN);
batadv_dbg(BATADV_DBG_BLA, bat_priv,
"bla_send_claim(): REQUEST of %pM to %pMon vid %d\n",
ethhdr->h_source, ethhdr->h_dest, vid);
break;
}
if (vid != -1)
skb = vlan_insert_tag(skb, htons(ETH_P_8021Q), vid);
skb_reset_mac_header(skb);
skb->protocol = eth_type_trans(skb, soft_iface);
batadv_inc_counter(bat_priv, BATADV_CNT_RX);
batadv_add_counter(bat_priv, BATADV_CNT_RX_BYTES,
skb->len + ETH_HLEN);
soft_iface->last_rx = jiffies;
netif_rx(skb);
out:
if (primary_if)
batadv_hardif_free_ref(primary_if);
}
static struct batadv_bla_backbone_gw *
batadv_bla_get_backbone_gw(struct batadv_priv *bat_priv, uint8_t *orig,
short vid, bool own_backbone)
{
struct batadv_bla_backbone_gw *entry;
struct batadv_orig_node *orig_node;
int hash_added;
entry = batadv_backbone_hash_find(bat_priv, orig, vid);
if (entry)
return entry;
batadv_dbg(BATADV_DBG_BLA, bat_priv,
"bla_get_backbone_gw(): not found (%pM, %d), creating new entry\n",
orig, vid);
entry = kzalloc(sizeof(*entry), GFP_ATOMIC);
if (!entry)
return NULL;
entry->vid = vid;
entry->lasttime = jiffies;
entry->crc = BATADV_BLA_CRC_INIT;
entry->bat_priv = bat_priv;
atomic_set(&entry->request_sent, 0);
atomic_set(&entry->wait_periods, 0);
memcpy(entry->orig, orig, ETH_ALEN);
atomic_set(&entry->refcount, 2);
hash_added = batadv_hash_add(bat_priv->bla.backbone_hash,
batadv_compare_backbone_gw,
batadv_choose_backbone_gw, entry,
&entry->hash_entry);
if (unlikely(hash_added != 0)) {
kfree(entry);
return NULL;
}
orig_node = batadv_orig_hash_find(bat_priv, orig);
if (orig_node) {
batadv_tt_global_del_orig(bat_priv, orig_node,
"became a backbone gateway");
batadv_orig_node_free_ref(orig_node);
}
if (own_backbone) {
batadv_bla_send_announce(bat_priv, entry);
atomic_inc(&entry->request_sent);
atomic_set(&entry->wait_periods, BATADV_BLA_WAIT_PERIODS);
atomic_inc(&bat_priv->bla.num_requests);
}
return entry;
}
static void
batadv_bla_update_own_backbone_gw(struct batadv_priv *bat_priv,
struct batadv_hard_iface *primary_if,
short vid)
{
struct batadv_bla_backbone_gw *backbone_gw;
backbone_gw = batadv_bla_get_backbone_gw(bat_priv,
primary_if->net_dev->dev_addr,
vid, true);
if (unlikely(!backbone_gw))
return;
backbone_gw->lasttime = jiffies;
batadv_backbone_gw_free_ref(backbone_gw);
}
static void batadv_bla_answer_request(struct batadv_priv *bat_priv,
struct batadv_hard_iface *primary_if,
short vid)
{
struct hlist_head *head;
struct batadv_hashtable *hash;
struct batadv_bla_claim *claim;
struct batadv_bla_backbone_gw *backbone_gw;
int i;
batadv_dbg(BATADV_DBG_BLA, bat_priv,
"bla_answer_request(): received a claim request, send all of our own claims again\n");
backbone_gw = batadv_backbone_hash_find(bat_priv,
primary_if->net_dev->dev_addr,
vid);
if (!backbone_gw)
return;
hash = bat_priv->bla.claim_hash;
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
rcu_read_lock();
hlist_for_each_entry_rcu(claim, head, hash_entry) {
if (claim->backbone_gw != backbone_gw)
continue;
batadv_bla_send_claim(bat_priv, claim->addr, claim->vid,
BATADV_CLAIM_TYPE_CLAIM);
}
rcu_read_unlock();
}
batadv_bla_send_announce(bat_priv, backbone_gw);
batadv_backbone_gw_free_ref(backbone_gw);
}
static void batadv_bla_send_request(struct batadv_bla_backbone_gw *backbone_gw)
{
batadv_bla_del_backbone_claims(backbone_gw);
batadv_dbg(BATADV_DBG_BLA, backbone_gw->bat_priv,
"Sending REQUEST to %pM\n", backbone_gw->orig);
batadv_bla_send_claim(backbone_gw->bat_priv, backbone_gw->orig,
backbone_gw->vid, BATADV_CLAIM_TYPE_REQUEST);
if (!atomic_read(&backbone_gw->request_sent)) {
atomic_inc(&backbone_gw->bat_priv->bla.num_requests);
atomic_set(&backbone_gw->request_sent, 1);
}
}
static void batadv_bla_send_announce(struct batadv_priv *bat_priv,
struct batadv_bla_backbone_gw *backbone_gw)
{
uint8_t mac[ETH_ALEN];
__be16 crc;
memcpy(mac, batadv_announce_mac, 4);
crc = htons(backbone_gw->crc);
memcpy(&mac[4], &crc, 2);
batadv_bla_send_claim(bat_priv, mac, backbone_gw->vid,
BATADV_CLAIM_TYPE_ANNOUNCE);
}
static void batadv_bla_add_claim(struct batadv_priv *bat_priv,
const uint8_t *mac, const short vid,
struct batadv_bla_backbone_gw *backbone_gw)
{
struct batadv_bla_claim *claim;
struct batadv_bla_claim search_claim;
int hash_added;
memcpy(search_claim.addr, mac, ETH_ALEN);
search_claim.vid = vid;
claim = batadv_claim_hash_find(bat_priv, &search_claim);
if (!claim) {
claim = kzalloc(sizeof(*claim), GFP_ATOMIC);
if (!claim)
return;
memcpy(claim->addr, mac, ETH_ALEN);
claim->vid = vid;
claim->lasttime = jiffies;
claim->backbone_gw = backbone_gw;
atomic_set(&claim->refcount, 2);
batadv_dbg(BATADV_DBG_BLA, bat_priv,
"bla_add_claim(): adding new entry %pM, vid %d to hash ...\n",
mac, vid);
hash_added = batadv_hash_add(bat_priv->bla.claim_hash,
batadv_compare_claim,
batadv_choose_claim, claim,
&claim->hash_entry);
if (unlikely(hash_added != 0)) {
kfree(claim);
return;
}
} else {
claim->lasttime = jiffies;
if (claim->backbone_gw == backbone_gw)
goto claim_free_ref;
batadv_dbg(BATADV_DBG_BLA, bat_priv,
"bla_add_claim(): changing ownership for %pM, vid %d\n",
mac, vid);
claim->backbone_gw->crc ^= crc16(0, claim->addr, ETH_ALEN);
batadv_backbone_gw_free_ref(claim->backbone_gw);
}
atomic_inc(&backbone_gw->refcount);
claim->backbone_gw = backbone_gw;
backbone_gw->crc ^= crc16(0, claim->addr, ETH_ALEN);
backbone_gw->lasttime = jiffies;
claim_free_ref:
batadv_claim_free_ref(claim);
}
static void batadv_bla_del_claim(struct batadv_priv *bat_priv,
const uint8_t *mac, const short vid)
{
struct batadv_bla_claim search_claim, *claim;
memcpy(search_claim.addr, mac, ETH_ALEN);
search_claim.vid = vid;
claim = batadv_claim_hash_find(bat_priv, &search_claim);
if (!claim)
return;
batadv_dbg(BATADV_DBG_BLA, bat_priv, "bla_del_claim(): %pM, vid %d\n",
mac, vid);
batadv_hash_remove(bat_priv->bla.claim_hash, batadv_compare_claim,
batadv_choose_claim, claim);
batadv_claim_free_ref(claim);
claim->backbone_gw->crc ^= crc16(0, claim->addr, ETH_ALEN);
batadv_claim_free_ref(claim);
}
static int batadv_handle_announce(struct batadv_priv *bat_priv,
uint8_t *an_addr, uint8_t *backbone_addr,
short vid)
{
struct batadv_bla_backbone_gw *backbone_gw;
uint16_t crc;
if (memcmp(an_addr, batadv_announce_mac, 4) != 0)
return 0;
backbone_gw = batadv_bla_get_backbone_gw(bat_priv, backbone_addr, vid,
false);
if (unlikely(!backbone_gw))
return 1;
backbone_gw->lasttime = jiffies;
crc = ntohs(*((__be16 *)(&an_addr[4])));
batadv_dbg(BATADV_DBG_BLA, bat_priv,
"handle_announce(): ANNOUNCE vid %d (sent by %pM)... CRC = %#.4x\n",
vid, backbone_gw->orig, crc);
if (backbone_gw->crc != crc) {
batadv_dbg(BATADV_DBG_BLA, backbone_gw->bat_priv,
"handle_announce(): CRC FAILED for %pM/%d (my = %#.4x, sent = %#.4x)\n",
backbone_gw->orig, backbone_gw->vid,
backbone_gw->crc, crc);
batadv_bla_send_request(backbone_gw);
} else {
if (atomic_read(&backbone_gw->request_sent)) {
atomic_dec(&backbone_gw->bat_priv->bla.num_requests);
atomic_set(&backbone_gw->request_sent, 0);
}
}
batadv_backbone_gw_free_ref(backbone_gw);
return 1;
}
static int batadv_handle_request(struct batadv_priv *bat_priv,
struct batadv_hard_iface *primary_if,
uint8_t *backbone_addr,
struct ethhdr *ethhdr, short vid)
{
if (!batadv_compare_eth(backbone_addr, ethhdr->h_dest))
return 0;
if (!batadv_compare_eth(ethhdr->h_dest, primary_if->net_dev->dev_addr))
return 1;
batadv_dbg(BATADV_DBG_BLA, bat_priv,
"handle_request(): REQUEST vid %d (sent by %pM)...\n",
vid, ethhdr->h_source);
batadv_bla_answer_request(bat_priv, primary_if, vid);
return 1;
}
static int batadv_handle_unclaim(struct batadv_priv *bat_priv,
struct batadv_hard_iface *primary_if,
uint8_t *backbone_addr,
uint8_t *claim_addr, short vid)
{
struct batadv_bla_backbone_gw *backbone_gw;
if (primary_if && batadv_compare_eth(backbone_addr,
primary_if->net_dev->dev_addr))
batadv_bla_send_claim(bat_priv, claim_addr, vid,
BATADV_CLAIM_TYPE_UNCLAIM);
backbone_gw = batadv_backbone_hash_find(bat_priv, backbone_addr, vid);
if (!backbone_gw)
return 1;
batadv_dbg(BATADV_DBG_BLA, bat_priv,
"handle_unclaim(): UNCLAIM %pM on vid %d (sent by %pM)...\n",
claim_addr, vid, backbone_gw->orig);
batadv_bla_del_claim(bat_priv, claim_addr, vid);
batadv_backbone_gw_free_ref(backbone_gw);
return 1;
}
static int batadv_handle_claim(struct batadv_priv *bat_priv,
struct batadv_hard_iface *primary_if,
uint8_t *backbone_addr, uint8_t *claim_addr,
short vid)
{
struct batadv_bla_backbone_gw *backbone_gw;
backbone_gw = batadv_bla_get_backbone_gw(bat_priv, backbone_addr, vid,
false);
if (unlikely(!backbone_gw))
return 1;
batadv_bla_add_claim(bat_priv, claim_addr, vid, backbone_gw);
if (batadv_compare_eth(backbone_addr, primary_if->net_dev->dev_addr))
batadv_bla_send_claim(bat_priv, claim_addr, vid,
BATADV_CLAIM_TYPE_CLAIM);
batadv_backbone_gw_free_ref(backbone_gw);
return 1;
}
static int batadv_check_claim_group(struct batadv_priv *bat_priv,
struct batadv_hard_iface *primary_if,
uint8_t *hw_src, uint8_t *hw_dst,
struct ethhdr *ethhdr)
{
uint8_t *backbone_addr;
struct batadv_orig_node *orig_node;
struct batadv_bla_claim_dst *bla_dst, *bla_dst_own;
bla_dst = (struct batadv_bla_claim_dst *)hw_dst;
bla_dst_own = &bat_priv->bla.claim_dest;
if (memcmp(bla_dst->magic, bla_dst_own->magic,
sizeof(bla_dst->magic)) != 0)
return 0;
switch (bla_dst->type) {
case BATADV_CLAIM_TYPE_CLAIM:
backbone_addr = hw_src;
break;
case BATADV_CLAIM_TYPE_REQUEST:
case BATADV_CLAIM_TYPE_ANNOUNCE:
case BATADV_CLAIM_TYPE_UNCLAIM:
backbone_addr = ethhdr->h_source;
break;
default:
return 0;
}
if (batadv_compare_eth(backbone_addr, primary_if->net_dev->dev_addr))
return 0;
if (bla_dst->group == bla_dst_own->group)
return 2;
orig_node = batadv_orig_hash_find(bat_priv, backbone_addr);
if (!orig_node)
return 1;
if (ntohs(bla_dst->group) > ntohs(bla_dst_own->group)) {
batadv_dbg(BATADV_DBG_BLA, bat_priv,
"taking other backbones claim group: %#.4x\n",
ntohs(bla_dst->group));
bla_dst_own->group = bla_dst->group;
}
batadv_orig_node_free_ref(orig_node);
return 2;
}
static int batadv_bla_process_claim(struct batadv_priv *bat_priv,
struct batadv_hard_iface *primary_if,
struct sk_buff *skb)
{
struct ethhdr *ethhdr;
struct vlan_ethhdr *vhdr;
struct arphdr *arphdr;
uint8_t *hw_src, *hw_dst;
struct batadv_bla_claim_dst *bla_dst;
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
bla_dst = (struct batadv_bla_claim_dst *)hw_dst;
ret = batadv_check_claim_group(bat_priv, primary_if, hw_src, hw_dst,
ethhdr);
if (ret == 1)
batadv_dbg(BATADV_DBG_BLA, bat_priv,
"bla_process_claim(): received a claim frame from another group. From: %pM on vid %d ...(hw_src %pM, hw_dst %pM)\n",
ethhdr->h_source, vid, hw_src, hw_dst);
if (ret < 2)
return ret;
batadv_bla_update_own_backbone_gw(bat_priv, primary_if, vid);
switch (bla_dst->type) {
case BATADV_CLAIM_TYPE_CLAIM:
if (batadv_handle_claim(bat_priv, primary_if, hw_src,
ethhdr->h_source, vid))
return 1;
break;
case BATADV_CLAIM_TYPE_UNCLAIM:
if (batadv_handle_unclaim(bat_priv, primary_if,
ethhdr->h_source, hw_src, vid))
return 1;
break;
case BATADV_CLAIM_TYPE_ANNOUNCE:
if (batadv_handle_announce(bat_priv, hw_src, ethhdr->h_source,
vid))
return 1;
break;
case BATADV_CLAIM_TYPE_REQUEST:
if (batadv_handle_request(bat_priv, primary_if, hw_src, ethhdr,
vid))
return 1;
break;
}
batadv_dbg(BATADV_DBG_BLA, bat_priv,
"bla_process_claim(): ERROR - this looks like a claim frame, but is useless. eth src %pM on vid %d ...(hw_src %pM, hw_dst %pM)\n",
ethhdr->h_source, vid, hw_src, hw_dst);
return 1;
}
static void batadv_bla_purge_backbone_gw(struct batadv_priv *bat_priv, int now)
{
struct batadv_bla_backbone_gw *backbone_gw;
struct hlist_node *node_tmp;
struct hlist_head *head;
struct batadv_hashtable *hash;
spinlock_t *list_lock;
int i;
hash = bat_priv->bla.backbone_hash;
if (!hash)
return;
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
list_lock = &hash->list_locks[i];
spin_lock_bh(list_lock);
hlist_for_each_entry_safe(backbone_gw, node_tmp,
head, hash_entry) {
if (now)
goto purge_now;
if (!batadv_has_timed_out(backbone_gw->lasttime,
BATADV_BLA_BACKBONE_TIMEOUT))
continue;
batadv_dbg(BATADV_DBG_BLA, backbone_gw->bat_priv,
"bla_purge_backbone_gw(): backbone gw %pM timed out\n",
backbone_gw->orig);
purge_now:
if (atomic_read(&backbone_gw->request_sent))
atomic_dec(&bat_priv->bla.num_requests);
batadv_bla_del_backbone_claims(backbone_gw);
hlist_del_rcu(&backbone_gw->hash_entry);
batadv_backbone_gw_free_ref(backbone_gw);
}
spin_unlock_bh(list_lock);
}
}
static void batadv_bla_purge_claims(struct batadv_priv *bat_priv,
struct batadv_hard_iface *primary_if,
int now)
{
struct batadv_bla_claim *claim;
struct hlist_head *head;
struct batadv_hashtable *hash;
int i;
hash = bat_priv->bla.claim_hash;
if (!hash)
return;
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
rcu_read_lock();
hlist_for_each_entry_rcu(claim, head, hash_entry) {
if (now)
goto purge_now;
if (!batadv_compare_eth(claim->backbone_gw->orig,
primary_if->net_dev->dev_addr))
continue;
if (!batadv_has_timed_out(claim->lasttime,
BATADV_BLA_CLAIM_TIMEOUT))
continue;
batadv_dbg(BATADV_DBG_BLA, bat_priv,
"bla_purge_claims(): %pM, vid %d, time out\n",
claim->addr, claim->vid);
purge_now:
batadv_handle_unclaim(bat_priv, primary_if,
claim->backbone_gw->orig,
claim->addr, claim->vid);
}
rcu_read_unlock();
}
}
void batadv_bla_update_orig_address(struct batadv_priv *bat_priv,
struct batadv_hard_iface *primary_if,
struct batadv_hard_iface *oldif)
{
struct batadv_bla_backbone_gw *backbone_gw;
struct hlist_head *head;
struct batadv_hashtable *hash;
__be16 group;
int i;
group = htons(crc16(0, primary_if->net_dev->dev_addr, ETH_ALEN));
bat_priv->bla.claim_dest.group = group;
if (!atomic_read(&bat_priv->bridge_loop_avoidance))
oldif = NULL;
if (!oldif) {
batadv_bla_purge_claims(bat_priv, NULL, 1);
batadv_bla_purge_backbone_gw(bat_priv, 1);
return;
}
hash = bat_priv->bla.backbone_hash;
if (!hash)
return;
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
rcu_read_lock();
hlist_for_each_entry_rcu(backbone_gw, head, hash_entry) {
if (!batadv_compare_eth(backbone_gw->orig,
oldif->net_dev->dev_addr))
continue;
memcpy(backbone_gw->orig,
primary_if->net_dev->dev_addr, ETH_ALEN);
batadv_bla_send_announce(bat_priv, backbone_gw);
}
rcu_read_unlock();
}
}
static void batadv_bla_periodic_work(struct work_struct *work)
{
struct delayed_work *delayed_work;
struct batadv_priv *bat_priv;
struct batadv_priv_bla *priv_bla;
struct hlist_head *head;
struct batadv_bla_backbone_gw *backbone_gw;
struct batadv_hashtable *hash;
struct batadv_hard_iface *primary_if;
int i;
delayed_work = container_of(work, struct delayed_work, work);
priv_bla = container_of(delayed_work, struct batadv_priv_bla, work);
bat_priv = container_of(priv_bla, struct batadv_priv, bla);
primary_if = batadv_primary_if_get_selected(bat_priv);
if (!primary_if)
goto out;
batadv_bla_purge_claims(bat_priv, primary_if, 0);
batadv_bla_purge_backbone_gw(bat_priv, 0);
if (!atomic_read(&bat_priv->bridge_loop_avoidance))
goto out;
hash = bat_priv->bla.backbone_hash;
if (!hash)
goto out;
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
rcu_read_lock();
hlist_for_each_entry_rcu(backbone_gw, head, hash_entry) {
if (!batadv_compare_eth(backbone_gw->orig,
primary_if->net_dev->dev_addr))
continue;
backbone_gw->lasttime = jiffies;
batadv_bla_send_announce(bat_priv, backbone_gw);
if (atomic_read(&backbone_gw->request_sent) == 0)
continue;
if (!atomic_dec_and_test(&backbone_gw->wait_periods))
continue;
atomic_dec(&backbone_gw->bat_priv->bla.num_requests);
atomic_set(&backbone_gw->request_sent, 0);
}
rcu_read_unlock();
}
out:
if (primary_if)
batadv_hardif_free_ref(primary_if);
queue_delayed_work(batadv_event_workqueue, &bat_priv->bla.work,
msecs_to_jiffies(BATADV_BLA_PERIOD_LENGTH));
}
int batadv_bla_init(struct batadv_priv *bat_priv)
{
int i;
uint8_t claim_dest[ETH_ALEN] = {0xff, 0x43, 0x05, 0x00, 0x00, 0x00};
struct batadv_hard_iface *primary_if;
uint16_t crc;
unsigned long entrytime;
spin_lock_init(&bat_priv->bla.bcast_duplist_lock);
batadv_dbg(BATADV_DBG_BLA, bat_priv, "bla hash registering\n");
memcpy(&bat_priv->bla.claim_dest.magic, claim_dest, 3);
bat_priv->bla.claim_dest.type = 0;
primary_if = batadv_primary_if_get_selected(bat_priv);
if (primary_if) {
crc = crc16(0, primary_if->net_dev->dev_addr, ETH_ALEN);
bat_priv->bla.claim_dest.group = htons(crc);
batadv_hardif_free_ref(primary_if);
} else {
bat_priv->bla.claim_dest.group = 0;
}
entrytime = jiffies - msecs_to_jiffies(BATADV_DUPLIST_TIMEOUT);
for (i = 0; i < BATADV_DUPLIST_SIZE; i++)
bat_priv->bla.bcast_duplist[i].entrytime = entrytime;
bat_priv->bla.bcast_duplist_curr = 0;
if (bat_priv->bla.claim_hash)
return 0;
bat_priv->bla.claim_hash = batadv_hash_new(128);
bat_priv->bla.backbone_hash = batadv_hash_new(32);
if (!bat_priv->bla.claim_hash || !bat_priv->bla.backbone_hash)
return -ENOMEM;
batadv_hash_set_lock_class(bat_priv->bla.claim_hash,
&batadv_claim_hash_lock_class_key);
batadv_hash_set_lock_class(bat_priv->bla.backbone_hash,
&batadv_backbone_hash_lock_class_key);
batadv_dbg(BATADV_DBG_BLA, bat_priv, "bla hashes initialized\n");
INIT_DELAYED_WORK(&bat_priv->bla.work, batadv_bla_periodic_work);
queue_delayed_work(batadv_event_workqueue, &bat_priv->bla.work,
msecs_to_jiffies(BATADV_BLA_PERIOD_LENGTH));
return 0;
}
int batadv_bla_check_bcast_duplist(struct batadv_priv *bat_priv,
struct sk_buff *skb)
{
int i, curr, ret = 0;
__be32 crc;
struct batadv_bcast_packet *bcast_packet;
struct batadv_bcast_duplist_entry *entry;
bcast_packet = (struct batadv_bcast_packet *)skb->data;
crc = batadv_skb_crc32(skb, (u8 *)(bcast_packet + 1));
spin_lock_bh(&bat_priv->bla.bcast_duplist_lock);
for (i = 0; i < BATADV_DUPLIST_SIZE; i++) {
curr = (bat_priv->bla.bcast_duplist_curr + i);
curr %= BATADV_DUPLIST_SIZE;
entry = &bat_priv->bla.bcast_duplist[curr];
if (batadv_has_timed_out(entry->entrytime,
BATADV_DUPLIST_TIMEOUT))
break;
if (entry->crc != crc)
continue;
if (batadv_compare_eth(entry->orig, bcast_packet->orig))
continue;
ret = 1;
goto out;
}
curr = (bat_priv->bla.bcast_duplist_curr + BATADV_DUPLIST_SIZE - 1);
curr %= BATADV_DUPLIST_SIZE;
entry = &bat_priv->bla.bcast_duplist[curr];
entry->crc = crc;
entry->entrytime = jiffies;
memcpy(entry->orig, bcast_packet->orig, ETH_ALEN);
bat_priv->bla.bcast_duplist_curr = curr;
out:
spin_unlock_bh(&bat_priv->bla.bcast_duplist_lock);
return ret;
}
int batadv_bla_is_backbone_gw_orig(struct batadv_priv *bat_priv, uint8_t *orig)
{
struct batadv_hashtable *hash = bat_priv->bla.backbone_hash;
struct hlist_head *head;
struct batadv_bla_backbone_gw *backbone_gw;
int i;
if (!atomic_read(&bat_priv->bridge_loop_avoidance))
return 0;
if (!hash)
return 0;
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
rcu_read_lock();
hlist_for_each_entry_rcu(backbone_gw, head, hash_entry) {
if (batadv_compare_eth(backbone_gw->orig, orig)) {
rcu_read_unlock();
return 1;
}
}
rcu_read_unlock();
}
return 0;
}
int batadv_bla_is_backbone_gw(struct sk_buff *skb,
struct batadv_orig_node *orig_node, int hdr_size)
{
struct ethhdr *ethhdr;
struct vlan_ethhdr *vhdr;
struct batadv_bla_backbone_gw *backbone_gw;
short vid = -1;
if (!atomic_read(&orig_node->bat_priv->bridge_loop_avoidance))
return 0;
if (!pskb_may_pull(skb, hdr_size + ETH_HLEN))
return 0;
ethhdr = (struct ethhdr *)(((uint8_t *)skb->data) + hdr_size);
if (ntohs(ethhdr->h_proto) == ETH_P_8021Q) {
if (!pskb_may_pull(skb, hdr_size + sizeof(struct vlan_ethhdr)))
return 0;
vhdr = (struct vlan_ethhdr *)(skb->data + hdr_size);
vid = ntohs(vhdr->h_vlan_TCI) & VLAN_VID_MASK;
}
backbone_gw = batadv_backbone_hash_find(orig_node->bat_priv,
orig_node->orig, vid);
if (!backbone_gw)
return 0;
batadv_backbone_gw_free_ref(backbone_gw);
return 1;
}
void batadv_bla_free(struct batadv_priv *bat_priv)
{
struct batadv_hard_iface *primary_if;
cancel_delayed_work_sync(&bat_priv->bla.work);
primary_if = batadv_primary_if_get_selected(bat_priv);
if (bat_priv->bla.claim_hash) {
batadv_bla_purge_claims(bat_priv, primary_if, 1);
batadv_hash_destroy(bat_priv->bla.claim_hash);
bat_priv->bla.claim_hash = NULL;
}
if (bat_priv->bla.backbone_hash) {
batadv_bla_purge_backbone_gw(bat_priv, 1);
batadv_hash_destroy(bat_priv->bla.backbone_hash);
bat_priv->bla.backbone_hash = NULL;
}
if (primary_if)
batadv_hardif_free_ref(primary_if);
}
int batadv_bla_rx(struct batadv_priv *bat_priv, struct sk_buff *skb, short vid,
bool is_bcast)
{
struct ethhdr *ethhdr;
struct batadv_bla_claim search_claim, *claim = NULL;
struct batadv_hard_iface *primary_if;
int ret;
ethhdr = (struct ethhdr *)skb_mac_header(skb);
primary_if = batadv_primary_if_get_selected(bat_priv);
if (!primary_if)
goto handled;
if (!atomic_read(&bat_priv->bridge_loop_avoidance))
goto allow;
if (unlikely(atomic_read(&bat_priv->bla.num_requests)))
if (is_multicast_ether_addr(ethhdr->h_dest) && is_bcast)
goto handled;
memcpy(search_claim.addr, ethhdr->h_source, ETH_ALEN);
search_claim.vid = vid;
claim = batadv_claim_hash_find(bat_priv, &search_claim);
if (!claim) {
batadv_handle_claim(bat_priv, primary_if,
primary_if->net_dev->dev_addr,
ethhdr->h_source, vid);
goto allow;
}
if (batadv_compare_eth(claim->backbone_gw->orig,
primary_if->net_dev->dev_addr)) {
claim->lasttime = jiffies;
goto allow;
}
if (is_multicast_ether_addr(ethhdr->h_dest) && is_bcast) {
goto handled;
} else {
batadv_handle_claim(bat_priv, primary_if,
primary_if->net_dev->dev_addr,
ethhdr->h_source, vid);
goto allow;
}
allow:
batadv_bla_update_own_backbone_gw(bat_priv, primary_if, vid);
ret = 0;
goto out;
handled:
kfree_skb(skb);
ret = 1;
out:
if (primary_if)
batadv_hardif_free_ref(primary_if);
if (claim)
batadv_claim_free_ref(claim);
return ret;
}
int batadv_bla_tx(struct batadv_priv *bat_priv, struct sk_buff *skb, short vid)
{
struct ethhdr *ethhdr;
struct batadv_bla_claim search_claim, *claim = NULL;
struct batadv_hard_iface *primary_if;
int ret = 0;
primary_if = batadv_primary_if_get_selected(bat_priv);
if (!primary_if)
goto out;
if (!atomic_read(&bat_priv->bridge_loop_avoidance))
goto allow;
skb_reset_mac_header(skb);
if (batadv_bla_process_claim(bat_priv, primary_if, skb))
goto handled;
ethhdr = (struct ethhdr *)skb_mac_header(skb);
if (unlikely(atomic_read(&bat_priv->bla.num_requests)))
if (is_multicast_ether_addr(ethhdr->h_dest))
goto handled;
memcpy(search_claim.addr, ethhdr->h_source, ETH_ALEN);
search_claim.vid = vid;
claim = batadv_claim_hash_find(bat_priv, &search_claim);
if (!claim)
goto allow;
if (batadv_compare_eth(claim->backbone_gw->orig,
primary_if->net_dev->dev_addr)) {
batadv_handle_unclaim(bat_priv, primary_if,
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
batadv_bla_update_own_backbone_gw(bat_priv, primary_if, vid);
ret = 0;
goto out;
handled:
ret = 1;
out:
if (primary_if)
batadv_hardif_free_ref(primary_if);
if (claim)
batadv_claim_free_ref(claim);
return ret;
}
int batadv_bla_claim_table_seq_print_text(struct seq_file *seq, void *offset)
{
struct net_device *net_dev = (struct net_device *)seq->private;
struct batadv_priv *bat_priv = netdev_priv(net_dev);
struct batadv_hashtable *hash = bat_priv->bla.claim_hash;
struct batadv_bla_claim *claim;
struct batadv_hard_iface *primary_if;
struct hlist_head *head;
uint32_t i;
bool is_own;
uint8_t *primary_addr;
primary_if = batadv_seq_print_text_primary_if_get(seq);
if (!primary_if)
goto out;
primary_addr = primary_if->net_dev->dev_addr;
seq_printf(seq,
"Claims announced for the mesh %s (orig %pM, group id %#.4x)\n",
net_dev->name, primary_addr,
ntohs(bat_priv->bla.claim_dest.group));
seq_printf(seq, " %-17s %-5s %-17s [o] (%-6s)\n",
"Client", "VID", "Originator", "CRC");
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
rcu_read_lock();
hlist_for_each_entry_rcu(claim, head, hash_entry) {
is_own = batadv_compare_eth(claim->backbone_gw->orig,
primary_addr);
seq_printf(seq, " * %pM on % 5d by %pM [%c] (%#.4x)\n",
claim->addr, claim->vid,
claim->backbone_gw->orig,
(is_own ? 'x' : ' '),
claim->backbone_gw->crc);
}
rcu_read_unlock();
}
out:
if (primary_if)
batadv_hardif_free_ref(primary_if);
return 0;
}
int batadv_bla_backbone_table_seq_print_text(struct seq_file *seq, void *offset)
{
struct net_device *net_dev = (struct net_device *)seq->private;
struct batadv_priv *bat_priv = netdev_priv(net_dev);
struct batadv_hashtable *hash = bat_priv->bla.backbone_hash;
struct batadv_bla_backbone_gw *backbone_gw;
struct batadv_hard_iface *primary_if;
struct hlist_head *head;
int secs, msecs;
uint32_t i;
bool is_own;
uint8_t *primary_addr;
primary_if = batadv_seq_print_text_primary_if_get(seq);
if (!primary_if)
goto out;
primary_addr = primary_if->net_dev->dev_addr;
seq_printf(seq,
"Backbones announced for the mesh %s (orig %pM, group id %#.4x)\n",
net_dev->name, primary_addr,
ntohs(bat_priv->bla.claim_dest.group));
seq_printf(seq, " %-17s %-5s %-9s (%-6s)\n",
"Originator", "VID", "last seen", "CRC");
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
rcu_read_lock();
hlist_for_each_entry_rcu(backbone_gw, head, hash_entry) {
msecs = jiffies_to_msecs(jiffies -
backbone_gw->lasttime);
secs = msecs / 1000;
msecs = msecs % 1000;
is_own = batadv_compare_eth(backbone_gw->orig,
primary_addr);
if (is_own)
continue;
seq_printf(seq,
" * %pM on % 5d % 4i.%03is (%#.4x)\n",
backbone_gw->orig, backbone_gw->vid,
secs, msecs, backbone_gw->crc);
}
rcu_read_unlock();
}
out:
if (primary_if)
batadv_hardif_free_ref(primary_if);
return 0;
}
