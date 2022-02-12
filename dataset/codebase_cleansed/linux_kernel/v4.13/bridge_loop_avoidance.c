static inline u32 batadv_choose_claim(const void *data, u32 size)
{
struct batadv_bla_claim *claim = (struct batadv_bla_claim *)data;
u32 hash = 0;
hash = jhash(&claim->addr, sizeof(claim->addr), hash);
hash = jhash(&claim->vid, sizeof(claim->vid), hash);
return hash % size;
}
static inline u32 batadv_choose_backbone_gw(const void *data, u32 size)
{
const struct batadv_bla_claim *claim = (struct batadv_bla_claim *)data;
u32 hash = 0;
hash = jhash(&claim->addr, sizeof(claim->addr), hash);
hash = jhash(&claim->vid, sizeof(claim->vid), hash);
return hash % size;
}
static bool batadv_compare_backbone_gw(const struct hlist_node *node,
const void *data2)
{
const void *data1 = container_of(node, struct batadv_bla_backbone_gw,
hash_entry);
const struct batadv_bla_backbone_gw *gw1 = data1;
const struct batadv_bla_backbone_gw *gw2 = data2;
if (!batadv_compare_eth(gw1->orig, gw2->orig))
return false;
if (gw1->vid != gw2->vid)
return false;
return true;
}
static bool batadv_compare_claim(const struct hlist_node *node,
const void *data2)
{
const void *data1 = container_of(node, struct batadv_bla_claim,
hash_entry);
const struct batadv_bla_claim *cl1 = data1;
const struct batadv_bla_claim *cl2 = data2;
if (!batadv_compare_eth(cl1->addr, cl2->addr))
return false;
if (cl1->vid != cl2->vid)
return false;
return true;
}
static void batadv_backbone_gw_release(struct kref *ref)
{
struct batadv_bla_backbone_gw *backbone_gw;
backbone_gw = container_of(ref, struct batadv_bla_backbone_gw,
refcount);
kfree_rcu(backbone_gw, rcu);
}
static void batadv_backbone_gw_put(struct batadv_bla_backbone_gw *backbone_gw)
{
kref_put(&backbone_gw->refcount, batadv_backbone_gw_release);
}
static void batadv_claim_release(struct kref *ref)
{
struct batadv_bla_claim *claim;
struct batadv_bla_backbone_gw *old_backbone_gw;
claim = container_of(ref, struct batadv_bla_claim, refcount);
spin_lock_bh(&claim->backbone_lock);
old_backbone_gw = claim->backbone_gw;
claim->backbone_gw = NULL;
spin_unlock_bh(&claim->backbone_lock);
spin_lock_bh(&old_backbone_gw->crc_lock);
old_backbone_gw->crc ^= crc16(0, claim->addr, ETH_ALEN);
spin_unlock_bh(&old_backbone_gw->crc_lock);
batadv_backbone_gw_put(old_backbone_gw);
kfree_rcu(claim, rcu);
}
static void batadv_claim_put(struct batadv_bla_claim *claim)
{
kref_put(&claim->refcount, batadv_claim_release);
}
static struct batadv_bla_claim *
batadv_claim_hash_find(struct batadv_priv *bat_priv,
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
if (!kref_get_unless_zero(&claim->refcount))
continue;
claim_tmp = claim;
break;
}
rcu_read_unlock();
return claim_tmp;
}
static struct batadv_bla_backbone_gw *
batadv_backbone_hash_find(struct batadv_priv *bat_priv, u8 *addr,
unsigned short vid)
{
struct batadv_hashtable *hash = bat_priv->bla.backbone_hash;
struct hlist_head *head;
struct batadv_bla_backbone_gw search_entry, *backbone_gw;
struct batadv_bla_backbone_gw *backbone_gw_tmp = NULL;
int index;
if (!hash)
return NULL;
ether_addr_copy(search_entry.orig, addr);
search_entry.vid = vid;
index = batadv_choose_backbone_gw(&search_entry, hash->size);
head = &hash->table[index];
rcu_read_lock();
hlist_for_each_entry_rcu(backbone_gw, head, hash_entry) {
if (!batadv_compare_backbone_gw(&backbone_gw->hash_entry,
&search_entry))
continue;
if (!kref_get_unless_zero(&backbone_gw->refcount))
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
batadv_claim_put(claim);
hlist_del_rcu(&claim->hash_entry);
}
spin_unlock_bh(list_lock);
}
spin_lock_bh(&backbone_gw->crc_lock);
backbone_gw->crc = BATADV_BLA_CRC_INIT;
spin_unlock_bh(&backbone_gw->crc_lock);
}
static void batadv_bla_send_claim(struct batadv_priv *bat_priv, u8 *mac,
unsigned short vid, int claimtype)
{
struct sk_buff *skb;
struct ethhdr *ethhdr;
struct batadv_hard_iface *primary_if;
struct net_device *soft_iface;
u8 *hw_src;
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
(u8 *)&local_claim_dest);
if (!skb)
goto out;
ethhdr = (struct ethhdr *)skb->data;
hw_src = (u8 *)ethhdr + ETH_HLEN + sizeof(struct arphdr);
switch (claimtype) {
case BATADV_CLAIM_TYPE_CLAIM:
ether_addr_copy(ethhdr->h_source, mac);
batadv_dbg(BATADV_DBG_BLA, bat_priv,
"%s(): CLAIM %pM on vid %d\n", __func__, mac,
batadv_print_vid(vid));
break;
case BATADV_CLAIM_TYPE_UNCLAIM:
ether_addr_copy(hw_src, mac);
batadv_dbg(BATADV_DBG_BLA, bat_priv,
"%s(): UNCLAIM %pM on vid %d\n", __func__, mac,
batadv_print_vid(vid));
break;
case BATADV_CLAIM_TYPE_ANNOUNCE:
ether_addr_copy(hw_src, mac);
batadv_dbg(BATADV_DBG_BLA, bat_priv,
"%s(): ANNOUNCE of %pM on vid %d\n", __func__,
ethhdr->h_source, batadv_print_vid(vid));
break;
case BATADV_CLAIM_TYPE_REQUEST:
ether_addr_copy(hw_src, mac);
ether_addr_copy(ethhdr->h_dest, mac);
batadv_dbg(BATADV_DBG_BLA, bat_priv,
"%s(): REQUEST of %pM to %pM on vid %d\n", __func__,
ethhdr->h_source, ethhdr->h_dest,
batadv_print_vid(vid));
break;
case BATADV_CLAIM_TYPE_LOOPDETECT:
ether_addr_copy(ethhdr->h_source, mac);
batadv_dbg(BATADV_DBG_BLA, bat_priv,
"%s(): LOOPDETECT of %pM to %pM on vid %d\n",
__func__, ethhdr->h_source, ethhdr->h_dest,
batadv_print_vid(vid));
break;
}
if (vid & BATADV_VLAN_HAS_TAG) {
skb = vlan_insert_tag(skb, htons(ETH_P_8021Q),
vid & VLAN_VID_MASK);
if (!skb)
goto out;
}
skb_reset_mac_header(skb);
skb->protocol = eth_type_trans(skb, soft_iface);
batadv_inc_counter(bat_priv, BATADV_CNT_RX);
batadv_add_counter(bat_priv, BATADV_CNT_RX_BYTES,
skb->len + ETH_HLEN);
netif_rx(skb);
out:
if (primary_if)
batadv_hardif_put(primary_if);
}
static void batadv_bla_loopdetect_report(struct work_struct *work)
{
struct batadv_bla_backbone_gw *backbone_gw;
struct batadv_priv *bat_priv;
char vid_str[6] = { '\0' };
backbone_gw = container_of(work, struct batadv_bla_backbone_gw,
report_work);
bat_priv = backbone_gw->bat_priv;
batadv_info(bat_priv->soft_iface,
"Possible loop on VLAN %d detected which can't be handled by BLA - please check your network setup!\n",
batadv_print_vid(backbone_gw->vid));
snprintf(vid_str, sizeof(vid_str), "%d",
batadv_print_vid(backbone_gw->vid));
vid_str[sizeof(vid_str) - 1] = 0;
batadv_throw_uevent(bat_priv, BATADV_UEV_BLA, BATADV_UEV_LOOPDETECT,
vid_str);
batadv_backbone_gw_put(backbone_gw);
}
static struct batadv_bla_backbone_gw *
batadv_bla_get_backbone_gw(struct batadv_priv *bat_priv, u8 *orig,
unsigned short vid, bool own_backbone)
{
struct batadv_bla_backbone_gw *entry;
struct batadv_orig_node *orig_node;
int hash_added;
entry = batadv_backbone_hash_find(bat_priv, orig, vid);
if (entry)
return entry;
batadv_dbg(BATADV_DBG_BLA, bat_priv,
"%s(): not found (%pM, %d), creating new entry\n", __func__,
orig, batadv_print_vid(vid));
entry = kzalloc(sizeof(*entry), GFP_ATOMIC);
if (!entry)
return NULL;
entry->vid = vid;
entry->lasttime = jiffies;
entry->crc = BATADV_BLA_CRC_INIT;
entry->bat_priv = bat_priv;
spin_lock_init(&entry->crc_lock);
atomic_set(&entry->request_sent, 0);
atomic_set(&entry->wait_periods, 0);
ether_addr_copy(entry->orig, orig);
INIT_WORK(&entry->report_work, batadv_bla_loopdetect_report);
kref_init(&entry->refcount);
kref_get(&entry->refcount);
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
batadv_tt_global_del_orig(bat_priv, orig_node, vid,
"became a backbone gateway");
batadv_orig_node_put(orig_node);
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
unsigned short vid)
{
struct batadv_bla_backbone_gw *backbone_gw;
backbone_gw = batadv_bla_get_backbone_gw(bat_priv,
primary_if->net_dev->dev_addr,
vid, true);
if (unlikely(!backbone_gw))
return;
backbone_gw->lasttime = jiffies;
batadv_backbone_gw_put(backbone_gw);
}
static void batadv_bla_answer_request(struct batadv_priv *bat_priv,
struct batadv_hard_iface *primary_if,
unsigned short vid)
{
struct hlist_head *head;
struct batadv_hashtable *hash;
struct batadv_bla_claim *claim;
struct batadv_bla_backbone_gw *backbone_gw;
int i;
batadv_dbg(BATADV_DBG_BLA, bat_priv,
"%s(): received a claim request, send all of our own claims again\n",
__func__);
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
batadv_backbone_gw_put(backbone_gw);
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
u8 mac[ETH_ALEN];
__be16 crc;
memcpy(mac, batadv_announce_mac, 4);
spin_lock_bh(&backbone_gw->crc_lock);
crc = htons(backbone_gw->crc);
spin_unlock_bh(&backbone_gw->crc_lock);
memcpy(&mac[4], &crc, 2);
batadv_bla_send_claim(bat_priv, mac, backbone_gw->vid,
BATADV_CLAIM_TYPE_ANNOUNCE);
}
static void batadv_bla_add_claim(struct batadv_priv *bat_priv,
const u8 *mac, const unsigned short vid,
struct batadv_bla_backbone_gw *backbone_gw)
{
struct batadv_bla_backbone_gw *old_backbone_gw;
struct batadv_bla_claim *claim;
struct batadv_bla_claim search_claim;
bool remove_crc = false;
int hash_added;
ether_addr_copy(search_claim.addr, mac);
search_claim.vid = vid;
claim = batadv_claim_hash_find(bat_priv, &search_claim);
if (!claim) {
claim = kzalloc(sizeof(*claim), GFP_ATOMIC);
if (!claim)
return;
ether_addr_copy(claim->addr, mac);
spin_lock_init(&claim->backbone_lock);
claim->vid = vid;
claim->lasttime = jiffies;
kref_get(&backbone_gw->refcount);
claim->backbone_gw = backbone_gw;
kref_init(&claim->refcount);
batadv_dbg(BATADV_DBG_BLA, bat_priv,
"%s(): adding new entry %pM, vid %d to hash ...\n",
__func__, mac, batadv_print_vid(vid));
kref_get(&claim->refcount);
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
"%s(): changing ownership for %pM, vid %d to gw %pM\n",
__func__, mac, batadv_print_vid(vid),
backbone_gw->orig);
remove_crc = true;
}
spin_lock_bh(&claim->backbone_lock);
old_backbone_gw = claim->backbone_gw;
kref_get(&backbone_gw->refcount);
claim->backbone_gw = backbone_gw;
spin_unlock_bh(&claim->backbone_lock);
if (remove_crc) {
spin_lock_bh(&old_backbone_gw->crc_lock);
old_backbone_gw->crc ^= crc16(0, claim->addr, ETH_ALEN);
spin_unlock_bh(&old_backbone_gw->crc_lock);
}
batadv_backbone_gw_put(old_backbone_gw);
spin_lock_bh(&backbone_gw->crc_lock);
backbone_gw->crc ^= crc16(0, claim->addr, ETH_ALEN);
spin_unlock_bh(&backbone_gw->crc_lock);
backbone_gw->lasttime = jiffies;
claim_free_ref:
batadv_claim_put(claim);
}
static struct batadv_bla_backbone_gw *
batadv_bla_claim_get_backbone_gw(struct batadv_bla_claim *claim)
{
struct batadv_bla_backbone_gw *backbone_gw;
spin_lock_bh(&claim->backbone_lock);
backbone_gw = claim->backbone_gw;
kref_get(&backbone_gw->refcount);
spin_unlock_bh(&claim->backbone_lock);
return backbone_gw;
}
static void batadv_bla_del_claim(struct batadv_priv *bat_priv,
const u8 *mac, const unsigned short vid)
{
struct batadv_bla_claim search_claim, *claim;
ether_addr_copy(search_claim.addr, mac);
search_claim.vid = vid;
claim = batadv_claim_hash_find(bat_priv, &search_claim);
if (!claim)
return;
batadv_dbg(BATADV_DBG_BLA, bat_priv, "%s(): %pM, vid %d\n", __func__,
mac, batadv_print_vid(vid));
batadv_hash_remove(bat_priv->bla.claim_hash, batadv_compare_claim,
batadv_choose_claim, claim);
batadv_claim_put(claim);
batadv_claim_put(claim);
}
static bool batadv_handle_announce(struct batadv_priv *bat_priv, u8 *an_addr,
u8 *backbone_addr, unsigned short vid)
{
struct batadv_bla_backbone_gw *backbone_gw;
u16 backbone_crc, crc;
if (memcmp(an_addr, batadv_announce_mac, 4) != 0)
return false;
backbone_gw = batadv_bla_get_backbone_gw(bat_priv, backbone_addr, vid,
false);
if (unlikely(!backbone_gw))
return true;
backbone_gw->lasttime = jiffies;
crc = ntohs(*((__be16 *)(&an_addr[4])));
batadv_dbg(BATADV_DBG_BLA, bat_priv,
"%s(): ANNOUNCE vid %d (sent by %pM)... CRC = %#.4x\n",
__func__, batadv_print_vid(vid), backbone_gw->orig, crc);
spin_lock_bh(&backbone_gw->crc_lock);
backbone_crc = backbone_gw->crc;
spin_unlock_bh(&backbone_gw->crc_lock);
if (backbone_crc != crc) {
batadv_dbg(BATADV_DBG_BLA, backbone_gw->bat_priv,
"%s(): CRC FAILED for %pM/%d (my = %#.4x, sent = %#.4x)\n",
__func__, backbone_gw->orig,
batadv_print_vid(backbone_gw->vid),
backbone_crc, crc);
batadv_bla_send_request(backbone_gw);
} else {
if (atomic_read(&backbone_gw->request_sent)) {
atomic_dec(&backbone_gw->bat_priv->bla.num_requests);
atomic_set(&backbone_gw->request_sent, 0);
}
}
batadv_backbone_gw_put(backbone_gw);
return true;
}
static bool batadv_handle_request(struct batadv_priv *bat_priv,
struct batadv_hard_iface *primary_if,
u8 *backbone_addr, struct ethhdr *ethhdr,
unsigned short vid)
{
if (!batadv_compare_eth(backbone_addr, ethhdr->h_dest))
return false;
if (!batadv_compare_eth(ethhdr->h_dest, primary_if->net_dev->dev_addr))
return true;
batadv_dbg(BATADV_DBG_BLA, bat_priv,
"%s(): REQUEST vid %d (sent by %pM)...\n",
__func__, batadv_print_vid(vid), ethhdr->h_source);
batadv_bla_answer_request(bat_priv, primary_if, vid);
return true;
}
static bool batadv_handle_unclaim(struct batadv_priv *bat_priv,
struct batadv_hard_iface *primary_if,
u8 *backbone_addr, u8 *claim_addr,
unsigned short vid)
{
struct batadv_bla_backbone_gw *backbone_gw;
if (primary_if && batadv_compare_eth(backbone_addr,
primary_if->net_dev->dev_addr))
batadv_bla_send_claim(bat_priv, claim_addr, vid,
BATADV_CLAIM_TYPE_UNCLAIM);
backbone_gw = batadv_backbone_hash_find(bat_priv, backbone_addr, vid);
if (!backbone_gw)
return true;
batadv_dbg(BATADV_DBG_BLA, bat_priv,
"%s(): UNCLAIM %pM on vid %d (sent by %pM)...\n", __func__,
claim_addr, batadv_print_vid(vid), backbone_gw->orig);
batadv_bla_del_claim(bat_priv, claim_addr, vid);
batadv_backbone_gw_put(backbone_gw);
return true;
}
static bool batadv_handle_claim(struct batadv_priv *bat_priv,
struct batadv_hard_iface *primary_if,
u8 *backbone_addr, u8 *claim_addr,
unsigned short vid)
{
struct batadv_bla_backbone_gw *backbone_gw;
backbone_gw = batadv_bla_get_backbone_gw(bat_priv, backbone_addr, vid,
false);
if (unlikely(!backbone_gw))
return true;
batadv_bla_add_claim(bat_priv, claim_addr, vid, backbone_gw);
if (batadv_compare_eth(backbone_addr, primary_if->net_dev->dev_addr))
batadv_bla_send_claim(bat_priv, claim_addr, vid,
BATADV_CLAIM_TYPE_CLAIM);
batadv_backbone_gw_put(backbone_gw);
return true;
}
static int batadv_check_claim_group(struct batadv_priv *bat_priv,
struct batadv_hard_iface *primary_if,
u8 *hw_src, u8 *hw_dst,
struct ethhdr *ethhdr)
{
u8 *backbone_addr;
struct batadv_orig_node *orig_node;
struct batadv_bla_claim_dst *bla_dst, *bla_dst_own;
bla_dst = (struct batadv_bla_claim_dst *)hw_dst;
bla_dst_own = &bat_priv->bla.claim_dest;
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
batadv_orig_node_put(orig_node);
return 2;
}
static bool batadv_bla_process_claim(struct batadv_priv *bat_priv,
struct batadv_hard_iface *primary_if,
struct sk_buff *skb)
{
struct batadv_bla_claim_dst *bla_dst, *bla_dst_own;
u8 *hw_src, *hw_dst;
struct vlan_hdr *vhdr, vhdr_buf;
struct ethhdr *ethhdr;
struct arphdr *arphdr;
unsigned short vid;
int vlan_depth = 0;
__be16 proto;
int headlen;
int ret;
vid = batadv_get_vid(skb, 0);
ethhdr = eth_hdr(skb);
proto = ethhdr->h_proto;
headlen = ETH_HLEN;
if (vid & BATADV_VLAN_HAS_TAG) {
do {
vhdr = skb_header_pointer(skb, headlen, VLAN_HLEN,
&vhdr_buf);
if (!vhdr)
return false;
proto = vhdr->h_vlan_encapsulated_proto;
headlen += VLAN_HLEN;
vlan_depth++;
} while (proto == htons(ETH_P_8021Q));
}
if (proto != htons(ETH_P_ARP))
return false;
if (unlikely(!pskb_may_pull(skb, headlen + arp_hdr_len(skb->dev))))
return false;
ethhdr = eth_hdr(skb);
arphdr = (struct arphdr *)((u8 *)ethhdr + headlen);
if (arphdr->ar_hrd != htons(ARPHRD_ETHER))
return false;
if (arphdr->ar_pro != htons(ETH_P_IP))
return false;
if (arphdr->ar_hln != ETH_ALEN)
return false;
if (arphdr->ar_pln != 4)
return false;
hw_src = (u8 *)arphdr + sizeof(struct arphdr);
hw_dst = hw_src + ETH_ALEN + 4;
bla_dst = (struct batadv_bla_claim_dst *)hw_dst;
bla_dst_own = &bat_priv->bla.claim_dest;
if (memcmp(bla_dst->magic, bla_dst_own->magic,
sizeof(bla_dst->magic)) != 0)
return false;
if (vlan_depth > 1)
return true;
if (bla_dst->type == BATADV_CLAIM_TYPE_LOOPDETECT)
return false;
ret = batadv_check_claim_group(bat_priv, primary_if, hw_src, hw_dst,
ethhdr);
if (ret == 1)
batadv_dbg(BATADV_DBG_BLA, bat_priv,
"%s(): received a claim frame from another group. From: %pM on vid %d ...(hw_src %pM, hw_dst %pM)\n",
__func__, ethhdr->h_source, batadv_print_vid(vid),
hw_src, hw_dst);
if (ret < 2)
return !!ret;
batadv_bla_update_own_backbone_gw(bat_priv, primary_if, vid);
switch (bla_dst->type) {
case BATADV_CLAIM_TYPE_CLAIM:
if (batadv_handle_claim(bat_priv, primary_if, hw_src,
ethhdr->h_source, vid))
return true;
break;
case BATADV_CLAIM_TYPE_UNCLAIM:
if (batadv_handle_unclaim(bat_priv, primary_if,
ethhdr->h_source, hw_src, vid))
return true;
break;
case BATADV_CLAIM_TYPE_ANNOUNCE:
if (batadv_handle_announce(bat_priv, hw_src, ethhdr->h_source,
vid))
return true;
break;
case BATADV_CLAIM_TYPE_REQUEST:
if (batadv_handle_request(bat_priv, primary_if, hw_src, ethhdr,
vid))
return true;
break;
}
batadv_dbg(BATADV_DBG_BLA, bat_priv,
"%s(): ERROR - this looks like a claim frame, but is useless. eth src %pM on vid %d ...(hw_src %pM, hw_dst %pM)\n",
__func__, ethhdr->h_source, batadv_print_vid(vid), hw_src,
hw_dst);
return true;
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
"%s(): backbone gw %pM timed out\n",
__func__, backbone_gw->orig);
purge_now:
if (atomic_read(&backbone_gw->request_sent))
atomic_dec(&bat_priv->bla.num_requests);
batadv_bla_del_backbone_claims(backbone_gw);
hlist_del_rcu(&backbone_gw->hash_entry);
batadv_backbone_gw_put(backbone_gw);
}
spin_unlock_bh(list_lock);
}
}
static void batadv_bla_purge_claims(struct batadv_priv *bat_priv,
struct batadv_hard_iface *primary_if,
int now)
{
struct batadv_bla_backbone_gw *backbone_gw;
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
backbone_gw = batadv_bla_claim_get_backbone_gw(claim);
if (now)
goto purge_now;
if (!batadv_compare_eth(backbone_gw->orig,
primary_if->net_dev->dev_addr))
goto skip;
if (!batadv_has_timed_out(claim->lasttime,
BATADV_BLA_CLAIM_TIMEOUT))
goto skip;
batadv_dbg(BATADV_DBG_BLA, bat_priv,
"%s(): timed out.\n", __func__);
purge_now:
batadv_dbg(BATADV_DBG_BLA, bat_priv,
"%s(): %pM, vid %d\n", __func__,
claim->addr, claim->vid);
batadv_handle_unclaim(bat_priv, primary_if,
backbone_gw->orig,
claim->addr, claim->vid);
skip:
batadv_backbone_gw_put(backbone_gw);
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
ether_addr_copy(backbone_gw->orig,
primary_if->net_dev->dev_addr);
batadv_bla_send_announce(bat_priv, backbone_gw);
}
rcu_read_unlock();
}
}
static void
batadv_bla_send_loopdetect(struct batadv_priv *bat_priv,
struct batadv_bla_backbone_gw *backbone_gw)
{
batadv_dbg(BATADV_DBG_BLA, bat_priv, "Send loopdetect frame for vid %d\n",
backbone_gw->vid);
batadv_bla_send_claim(bat_priv, bat_priv->bla.loopdetect_addr,
backbone_gw->vid, BATADV_CLAIM_TYPE_LOOPDETECT);
}
void batadv_bla_status_update(struct net_device *net_dev)
{
struct batadv_priv *bat_priv = netdev_priv(net_dev);
struct batadv_hard_iface *primary_if;
primary_if = batadv_primary_if_get_selected(bat_priv);
if (!primary_if)
return;
batadv_bla_update_orig_address(bat_priv, primary_if, primary_if);
batadv_hardif_put(primary_if);
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
bool send_loopdetect = false;
int i;
delayed_work = to_delayed_work(work);
priv_bla = container_of(delayed_work, struct batadv_priv_bla, work);
bat_priv = container_of(priv_bla, struct batadv_priv, bla);
primary_if = batadv_primary_if_get_selected(bat_priv);
if (!primary_if)
goto out;
batadv_bla_purge_claims(bat_priv, primary_if, 0);
batadv_bla_purge_backbone_gw(bat_priv, 0);
if (!atomic_read(&bat_priv->bridge_loop_avoidance))
goto out;
if (atomic_dec_and_test(&bat_priv->bla.loopdetect_next)) {
random_ether_addr(bat_priv->bla.loopdetect_addr);
bat_priv->bla.loopdetect_addr[0] = 0xba;
bat_priv->bla.loopdetect_addr[1] = 0xbe;
bat_priv->bla.loopdetect_lasttime = jiffies;
atomic_set(&bat_priv->bla.loopdetect_next,
BATADV_BLA_LOOPDETECT_PERIODS);
send_loopdetect = true;
}
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
if (send_loopdetect)
batadv_bla_send_loopdetect(bat_priv,
backbone_gw);
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
batadv_hardif_put(primary_if);
queue_delayed_work(batadv_event_workqueue, &bat_priv->bla.work,
msecs_to_jiffies(BATADV_BLA_PERIOD_LENGTH));
}
int batadv_bla_init(struct batadv_priv *bat_priv)
{
int i;
u8 claim_dest[ETH_ALEN] = {0xff, 0x43, 0x05, 0x00, 0x00, 0x00};
struct batadv_hard_iface *primary_if;
u16 crc;
unsigned long entrytime;
spin_lock_init(&bat_priv->bla.bcast_duplist_lock);
batadv_dbg(BATADV_DBG_BLA, bat_priv, "bla hash registering\n");
memcpy(&bat_priv->bla.claim_dest.magic, claim_dest, 3);
bat_priv->bla.claim_dest.type = 0;
primary_if = batadv_primary_if_get_selected(bat_priv);
if (primary_if) {
crc = crc16(0, primary_if->net_dev->dev_addr, ETH_ALEN);
bat_priv->bla.claim_dest.group = htons(crc);
batadv_hardif_put(primary_if);
} else {
bat_priv->bla.claim_dest.group = 0;
}
entrytime = jiffies - msecs_to_jiffies(BATADV_DUPLIST_TIMEOUT);
for (i = 0; i < BATADV_DUPLIST_SIZE; i++)
bat_priv->bla.bcast_duplist[i].entrytime = entrytime;
bat_priv->bla.bcast_duplist_curr = 0;
atomic_set(&bat_priv->bla.loopdetect_next,
BATADV_BLA_LOOPDETECT_PERIODS);
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
bool batadv_bla_check_bcast_duplist(struct batadv_priv *bat_priv,
struct sk_buff *skb)
{
int i, curr;
__be32 crc;
struct batadv_bcast_packet *bcast_packet;
struct batadv_bcast_duplist_entry *entry;
bool ret = false;
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
ret = true;
goto out;
}
curr = (bat_priv->bla.bcast_duplist_curr + BATADV_DUPLIST_SIZE - 1);
curr %= BATADV_DUPLIST_SIZE;
entry = &bat_priv->bla.bcast_duplist[curr];
entry->crc = crc;
entry->entrytime = jiffies;
ether_addr_copy(entry->orig, bcast_packet->orig);
bat_priv->bla.bcast_duplist_curr = curr;
out:
spin_unlock_bh(&bat_priv->bla.bcast_duplist_lock);
return ret;
}
bool batadv_bla_is_backbone_gw_orig(struct batadv_priv *bat_priv, u8 *orig,
unsigned short vid)
{
struct batadv_hashtable *hash = bat_priv->bla.backbone_hash;
struct hlist_head *head;
struct batadv_bla_backbone_gw *backbone_gw;
int i;
if (!atomic_read(&bat_priv->bridge_loop_avoidance))
return false;
if (!hash)
return false;
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
rcu_read_lock();
hlist_for_each_entry_rcu(backbone_gw, head, hash_entry) {
if (batadv_compare_eth(backbone_gw->orig, orig) &&
backbone_gw->vid == vid) {
rcu_read_unlock();
return true;
}
}
rcu_read_unlock();
}
return false;
}
bool batadv_bla_is_backbone_gw(struct sk_buff *skb,
struct batadv_orig_node *orig_node, int hdr_size)
{
struct batadv_bla_backbone_gw *backbone_gw;
unsigned short vid;
if (!atomic_read(&orig_node->bat_priv->bridge_loop_avoidance))
return false;
if (!pskb_may_pull(skb, hdr_size + ETH_HLEN))
return false;
vid = batadv_get_vid(skb, hdr_size);
backbone_gw = batadv_backbone_hash_find(orig_node->bat_priv,
orig_node->orig, vid);
if (!backbone_gw)
return false;
batadv_backbone_gw_put(backbone_gw);
return true;
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
batadv_hardif_put(primary_if);
}
static bool
batadv_bla_loopdetect_check(struct batadv_priv *bat_priv, struct sk_buff *skb,
struct batadv_hard_iface *primary_if,
unsigned short vid)
{
struct batadv_bla_backbone_gw *backbone_gw;
struct ethhdr *ethhdr;
ethhdr = eth_hdr(skb);
if (!batadv_compare_eth(ethhdr->h_source,
bat_priv->bla.loopdetect_addr))
return false;
if (batadv_has_timed_out(bat_priv->bla.loopdetect_lasttime,
BATADV_BLA_LOOPDETECT_TIMEOUT))
return true;
backbone_gw = batadv_bla_get_backbone_gw(bat_priv,
primary_if->net_dev->dev_addr,
vid, true);
if (unlikely(!backbone_gw))
return true;
queue_work(batadv_event_workqueue, &backbone_gw->report_work);
return true;
}
bool batadv_bla_rx(struct batadv_priv *bat_priv, struct sk_buff *skb,
unsigned short vid, bool is_bcast)
{
struct batadv_bla_backbone_gw *backbone_gw;
struct ethhdr *ethhdr;
struct batadv_bla_claim search_claim, *claim = NULL;
struct batadv_hard_iface *primary_if;
bool own_claim;
bool ret;
ethhdr = eth_hdr(skb);
primary_if = batadv_primary_if_get_selected(bat_priv);
if (!primary_if)
goto handled;
if (!atomic_read(&bat_priv->bridge_loop_avoidance))
goto allow;
if (batadv_bla_loopdetect_check(bat_priv, skb, primary_if, vid))
goto handled;
if (unlikely(atomic_read(&bat_priv->bla.num_requests)))
if (is_multicast_ether_addr(ethhdr->h_dest) && is_bcast)
goto handled;
ether_addr_copy(search_claim.addr, ethhdr->h_source);
search_claim.vid = vid;
claim = batadv_claim_hash_find(bat_priv, &search_claim);
if (!claim) {
batadv_dbg(BATADV_DBG_BLA, bat_priv,
"%s(): Unclaimed MAC %pM found. Claim it. Local: %s\n",
__func__, ethhdr->h_source,
batadv_is_my_client(bat_priv,
ethhdr->h_source, vid) ?
"yes" : "no");
batadv_handle_claim(bat_priv, primary_if,
primary_if->net_dev->dev_addr,
ethhdr->h_source, vid);
goto allow;
}
backbone_gw = batadv_bla_claim_get_backbone_gw(claim);
own_claim = batadv_compare_eth(backbone_gw->orig,
primary_if->net_dev->dev_addr);
batadv_backbone_gw_put(backbone_gw);
if (own_claim) {
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
ret = false;
goto out;
handled:
kfree_skb(skb);
ret = true;
out:
if (primary_if)
batadv_hardif_put(primary_if);
if (claim)
batadv_claim_put(claim);
return ret;
}
bool batadv_bla_tx(struct batadv_priv *bat_priv, struct sk_buff *skb,
unsigned short vid)
{
struct ethhdr *ethhdr;
struct batadv_bla_claim search_claim, *claim = NULL;
struct batadv_bla_backbone_gw *backbone_gw;
struct batadv_hard_iface *primary_if;
bool client_roamed;
bool ret = false;
primary_if = batadv_primary_if_get_selected(bat_priv);
if (!primary_if)
goto out;
if (!atomic_read(&bat_priv->bridge_loop_avoidance))
goto allow;
if (batadv_bla_process_claim(bat_priv, primary_if, skb))
goto handled;
ethhdr = eth_hdr(skb);
if (unlikely(atomic_read(&bat_priv->bla.num_requests)))
if (is_multicast_ether_addr(ethhdr->h_dest))
goto handled;
ether_addr_copy(search_claim.addr, ethhdr->h_source);
search_claim.vid = vid;
claim = batadv_claim_hash_find(bat_priv, &search_claim);
if (!claim)
goto allow;
backbone_gw = batadv_bla_claim_get_backbone_gw(claim);
client_roamed = batadv_compare_eth(backbone_gw->orig,
primary_if->net_dev->dev_addr);
batadv_backbone_gw_put(backbone_gw);
if (client_roamed) {
if (batadv_has_timed_out(claim->lasttime, 100)) {
batadv_dbg(BATADV_DBG_BLA, bat_priv, "%s(): Roaming client %pM detected. Unclaim it.\n",
__func__, ethhdr->h_source);
batadv_handle_unclaim(bat_priv, primary_if,
primary_if->net_dev->dev_addr,
ethhdr->h_source, vid);
goto allow;
} else {
batadv_dbg(BATADV_DBG_BLA, bat_priv, "%s(): Race for claim %pM detected. Drop packet.\n",
__func__, ethhdr->h_source);
goto handled;
}
}
if (is_multicast_ether_addr(ethhdr->h_dest)) {
goto handled;
} else {
goto allow;
}
allow:
batadv_bla_update_own_backbone_gw(bat_priv, primary_if, vid);
ret = false;
goto out;
handled:
ret = true;
out:
if (primary_if)
batadv_hardif_put(primary_if);
if (claim)
batadv_claim_put(claim);
return ret;
}
int batadv_bla_claim_table_seq_print_text(struct seq_file *seq, void *offset)
{
struct net_device *net_dev = (struct net_device *)seq->private;
struct batadv_priv *bat_priv = netdev_priv(net_dev);
struct batadv_hashtable *hash = bat_priv->bla.claim_hash;
struct batadv_bla_backbone_gw *backbone_gw;
struct batadv_bla_claim *claim;
struct batadv_hard_iface *primary_if;
struct hlist_head *head;
u16 backbone_crc;
u32 i;
bool is_own;
u8 *primary_addr;
primary_if = batadv_seq_print_text_primary_if_get(seq);
if (!primary_if)
goto out;
primary_addr = primary_if->net_dev->dev_addr;
seq_printf(seq,
"Claims announced for the mesh %s (orig %pM, group id %#.4x)\n",
net_dev->name, primary_addr,
ntohs(bat_priv->bla.claim_dest.group));
seq_puts(seq,
" Client VID Originator [o] (CRC )\n");
for (i = 0; i < hash->size; i++) {
head = &hash->table[i];
rcu_read_lock();
hlist_for_each_entry_rcu(claim, head, hash_entry) {
backbone_gw = batadv_bla_claim_get_backbone_gw(claim);
is_own = batadv_compare_eth(backbone_gw->orig,
primary_addr);
spin_lock_bh(&backbone_gw->crc_lock);
backbone_crc = backbone_gw->crc;
spin_unlock_bh(&backbone_gw->crc_lock);
seq_printf(seq, " * %pM on %5d by %pM [%c] (%#.4x)\n",
claim->addr, batadv_print_vid(claim->vid),
backbone_gw->orig,
(is_own ? 'x' : ' '),
backbone_crc);
batadv_backbone_gw_put(backbone_gw);
}
rcu_read_unlock();
}
out:
if (primary_if)
batadv_hardif_put(primary_if);
return 0;
}
static int
batadv_bla_claim_dump_entry(struct sk_buff *msg, u32 portid, u32 seq,
struct batadv_hard_iface *primary_if,
struct batadv_bla_claim *claim)
{
u8 *primary_addr = primary_if->net_dev->dev_addr;
u16 backbone_crc;
bool is_own;
void *hdr;
int ret = -EINVAL;
hdr = genlmsg_put(msg, portid, seq, &batadv_netlink_family,
NLM_F_MULTI, BATADV_CMD_GET_BLA_CLAIM);
if (!hdr) {
ret = -ENOBUFS;
goto out;
}
is_own = batadv_compare_eth(claim->backbone_gw->orig,
primary_addr);
spin_lock_bh(&claim->backbone_gw->crc_lock);
backbone_crc = claim->backbone_gw->crc;
spin_unlock_bh(&claim->backbone_gw->crc_lock);
if (is_own)
if (nla_put_flag(msg, BATADV_ATTR_BLA_OWN)) {
genlmsg_cancel(msg, hdr);
goto out;
}
if (nla_put(msg, BATADV_ATTR_BLA_ADDRESS, ETH_ALEN, claim->addr) ||
nla_put_u16(msg, BATADV_ATTR_BLA_VID, claim->vid) ||
nla_put(msg, BATADV_ATTR_BLA_BACKBONE, ETH_ALEN,
claim->backbone_gw->orig) ||
nla_put_u16(msg, BATADV_ATTR_BLA_CRC,
backbone_crc)) {
genlmsg_cancel(msg, hdr);
goto out;
}
genlmsg_end(msg, hdr);
ret = 0;
out:
return ret;
}
static int
batadv_bla_claim_dump_bucket(struct sk_buff *msg, u32 portid, u32 seq,
struct batadv_hard_iface *primary_if,
struct hlist_head *head, int *idx_skip)
{
struct batadv_bla_claim *claim;
int idx = 0;
rcu_read_lock();
hlist_for_each_entry_rcu(claim, head, hash_entry) {
if (idx++ < *idx_skip)
continue;
if (batadv_bla_claim_dump_entry(msg, portid, seq,
primary_if, claim)) {
*idx_skip = idx - 1;
goto unlock;
}
}
*idx_skip = idx;
unlock:
rcu_read_unlock();
return 0;
}
int batadv_bla_claim_dump(struct sk_buff *msg, struct netlink_callback *cb)
{
struct batadv_hard_iface *primary_if = NULL;
int portid = NETLINK_CB(cb->skb).portid;
struct net *net = sock_net(cb->skb->sk);
struct net_device *soft_iface;
struct batadv_hashtable *hash;
struct batadv_priv *bat_priv;
int bucket = cb->args[0];
struct hlist_head *head;
int idx = cb->args[1];
int ifindex;
int ret = 0;
ifindex = batadv_netlink_get_ifindex(cb->nlh,
BATADV_ATTR_MESH_IFINDEX);
if (!ifindex)
return -EINVAL;
soft_iface = dev_get_by_index(net, ifindex);
if (!soft_iface || !batadv_softif_is_valid(soft_iface)) {
ret = -ENODEV;
goto out;
}
bat_priv = netdev_priv(soft_iface);
hash = bat_priv->bla.claim_hash;
primary_if = batadv_primary_if_get_selected(bat_priv);
if (!primary_if || primary_if->if_status != BATADV_IF_ACTIVE) {
ret = -ENOENT;
goto out;
}
while (bucket < hash->size) {
head = &hash->table[bucket];
if (batadv_bla_claim_dump_bucket(msg, portid,
cb->nlh->nlmsg_seq,
primary_if, head, &idx))
break;
bucket++;
}
cb->args[0] = bucket;
cb->args[1] = idx;
ret = msg->len;
out:
if (primary_if)
batadv_hardif_put(primary_if);
if (soft_iface)
dev_put(soft_iface);
return ret;
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
u16 backbone_crc;
u32 i;
bool is_own;
u8 *primary_addr;
primary_if = batadv_seq_print_text_primary_if_get(seq);
if (!primary_if)
goto out;
primary_addr = primary_if->net_dev->dev_addr;
seq_printf(seq,
"Backbones announced for the mesh %s (orig %pM, group id %#.4x)\n",
net_dev->name, primary_addr,
ntohs(bat_priv->bla.claim_dest.group));
seq_puts(seq, " Originator VID last seen (CRC )\n");
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
spin_lock_bh(&backbone_gw->crc_lock);
backbone_crc = backbone_gw->crc;
spin_unlock_bh(&backbone_gw->crc_lock);
seq_printf(seq, " * %pM on %5d %4i.%03is (%#.4x)\n",
backbone_gw->orig,
batadv_print_vid(backbone_gw->vid), secs,
msecs, backbone_crc);
}
rcu_read_unlock();
}
out:
if (primary_if)
batadv_hardif_put(primary_if);
return 0;
}
static int
batadv_bla_backbone_dump_entry(struct sk_buff *msg, u32 portid, u32 seq,
struct batadv_hard_iface *primary_if,
struct batadv_bla_backbone_gw *backbone_gw)
{
u8 *primary_addr = primary_if->net_dev->dev_addr;
u16 backbone_crc;
bool is_own;
int msecs;
void *hdr;
int ret = -EINVAL;
hdr = genlmsg_put(msg, portid, seq, &batadv_netlink_family,
NLM_F_MULTI, BATADV_CMD_GET_BLA_BACKBONE);
if (!hdr) {
ret = -ENOBUFS;
goto out;
}
is_own = batadv_compare_eth(backbone_gw->orig, primary_addr);
spin_lock_bh(&backbone_gw->crc_lock);
backbone_crc = backbone_gw->crc;
spin_unlock_bh(&backbone_gw->crc_lock);
msecs = jiffies_to_msecs(jiffies - backbone_gw->lasttime);
if (is_own)
if (nla_put_flag(msg, BATADV_ATTR_BLA_OWN)) {
genlmsg_cancel(msg, hdr);
goto out;
}
if (nla_put(msg, BATADV_ATTR_BLA_BACKBONE, ETH_ALEN,
backbone_gw->orig) ||
nla_put_u16(msg, BATADV_ATTR_BLA_VID, backbone_gw->vid) ||
nla_put_u16(msg, BATADV_ATTR_BLA_CRC,
backbone_crc) ||
nla_put_u32(msg, BATADV_ATTR_LAST_SEEN_MSECS, msecs)) {
genlmsg_cancel(msg, hdr);
goto out;
}
genlmsg_end(msg, hdr);
ret = 0;
out:
return ret;
}
static int
batadv_bla_backbone_dump_bucket(struct sk_buff *msg, u32 portid, u32 seq,
struct batadv_hard_iface *primary_if,
struct hlist_head *head, int *idx_skip)
{
struct batadv_bla_backbone_gw *backbone_gw;
int idx = 0;
rcu_read_lock();
hlist_for_each_entry_rcu(backbone_gw, head, hash_entry) {
if (idx++ < *idx_skip)
continue;
if (batadv_bla_backbone_dump_entry(msg, portid, seq,
primary_if, backbone_gw)) {
*idx_skip = idx - 1;
goto unlock;
}
}
*idx_skip = idx;
unlock:
rcu_read_unlock();
return 0;
}
int batadv_bla_backbone_dump(struct sk_buff *msg, struct netlink_callback *cb)
{
struct batadv_hard_iface *primary_if = NULL;
int portid = NETLINK_CB(cb->skb).portid;
struct net *net = sock_net(cb->skb->sk);
struct net_device *soft_iface;
struct batadv_hashtable *hash;
struct batadv_priv *bat_priv;
int bucket = cb->args[0];
struct hlist_head *head;
int idx = cb->args[1];
int ifindex;
int ret = 0;
ifindex = batadv_netlink_get_ifindex(cb->nlh,
BATADV_ATTR_MESH_IFINDEX);
if (!ifindex)
return -EINVAL;
soft_iface = dev_get_by_index(net, ifindex);
if (!soft_iface || !batadv_softif_is_valid(soft_iface)) {
ret = -ENODEV;
goto out;
}
bat_priv = netdev_priv(soft_iface);
hash = bat_priv->bla.backbone_hash;
primary_if = batadv_primary_if_get_selected(bat_priv);
if (!primary_if || primary_if->if_status != BATADV_IF_ACTIVE) {
ret = -ENOENT;
goto out;
}
while (bucket < hash->size) {
head = &hash->table[bucket];
if (batadv_bla_backbone_dump_bucket(msg, portid,
cb->nlh->nlmsg_seq,
primary_if, head, &idx))
break;
bucket++;
}
cb->args[0] = bucket;
cb->args[1] = idx;
ret = msg->len;
out:
if (primary_if)
batadv_hardif_put(primary_if);
if (soft_iface)
dev_put(soft_iface);
return ret;
}
bool batadv_bla_check_claim(struct batadv_priv *bat_priv,
u8 *addr, unsigned short vid)
{
struct batadv_bla_claim search_claim;
struct batadv_bla_claim *claim = NULL;
struct batadv_hard_iface *primary_if = NULL;
bool ret = true;
if (!atomic_read(&bat_priv->bridge_loop_avoidance))
return ret;
primary_if = batadv_primary_if_get_selected(bat_priv);
if (!primary_if)
return ret;
ether_addr_copy(search_claim.addr, addr);
search_claim.vid = vid;
claim = batadv_claim_hash_find(bat_priv, &search_claim);
if (claim) {
if (!batadv_compare_eth(claim->backbone_gw->orig,
primary_if->net_dev->dev_addr))
ret = false;
batadv_claim_put(claim);
}
batadv_hardif_put(primary_if);
return ret;
}
