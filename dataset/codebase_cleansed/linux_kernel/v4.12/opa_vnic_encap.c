static inline void opa_vnic_make_header(u8 *hdr, u32 slid, u32 dlid, u16 len,
u16 pkey, u16 entropy, u8 sc, u8 rc,
u8 l4_type, u16 l4_hdr)
{
u32 h[OPA_VNIC_HDR_QW_LEN] = {0, 0xc0000000, 0, 0, 0};
h[2] = l4_type;
h[3] = entropy;
h[4] = l4_hdr << OPA_VNIC_L4_HDR_SHFT;
h[0] |= (slid & OPA_16B_LID_MASK);
h[2] |= ((slid >> (20 - OPA_16B_SLID_HIGH_SHFT)) & OPA_16B_SLID_MASK);
h[1] |= (dlid & OPA_16B_LID_MASK);
h[2] |= ((dlid >> (20 - OPA_16B_DLID_HIGH_SHFT)) & OPA_16B_DLID_MASK);
h[0] |= (len << OPA_16B_LEN_SHFT);
h[1] |= (rc << OPA_16B_RC_SHFT);
h[1] |= (sc << OPA_16B_SC_SHFT);
h[2] |= ((u32)pkey << OPA_16B_PKEY_SHFT);
memcpy(hdr, h, OPA_VNIC_HDR_LEN);
}
static void opa_vnic_free_mac_tbl(struct hlist_head *mactbl)
{
struct opa_vnic_mac_tbl_node *node;
struct hlist_node *tmp;
int bkt;
if (!mactbl)
return;
vnic_hash_for_each_safe(mactbl, bkt, tmp, node, hlist) {
hash_del(&node->hlist);
kfree(node);
}
kfree(mactbl);
}
static struct hlist_head *opa_vnic_alloc_mac_tbl(void)
{
u32 size = sizeof(struct hlist_head) * OPA_VNIC_MAC_TBL_SIZE;
struct hlist_head *mactbl;
mactbl = kzalloc(size, GFP_KERNEL);
if (!mactbl)
return ERR_PTR(-ENOMEM);
vnic_hash_init(mactbl);
return mactbl;
}
void opa_vnic_release_mac_tbl(struct opa_vnic_adapter *adapter)
{
struct hlist_head *mactbl;
mutex_lock(&adapter->mactbl_lock);
mactbl = rcu_access_pointer(adapter->mactbl);
rcu_assign_pointer(adapter->mactbl, NULL);
synchronize_rcu();
opa_vnic_free_mac_tbl(mactbl);
mutex_unlock(&adapter->mactbl_lock);
}
void opa_vnic_query_mac_tbl(struct opa_vnic_adapter *adapter,
struct opa_veswport_mactable *tbl)
{
struct opa_vnic_mac_tbl_node *node;
struct hlist_head *mactbl;
int bkt;
u16 loffset, lnum_entries;
rcu_read_lock();
mactbl = rcu_dereference(adapter->mactbl);
if (!mactbl)
goto get_mac_done;
loffset = be16_to_cpu(tbl->offset);
lnum_entries = be16_to_cpu(tbl->num_entries);
vnic_hash_for_each(mactbl, bkt, node, hlist) {
struct __opa_vnic_mactable_entry *nentry = &node->entry;
struct opa_veswport_mactable_entry *entry;
if ((node->index < loffset) ||
(node->index >= (loffset + lnum_entries)))
continue;
entry = &tbl->tbl_entries[node->index - loffset];
memcpy(entry->mac_addr, nentry->mac_addr,
ARRAY_SIZE(entry->mac_addr));
memcpy(entry->mac_addr_mask, nentry->mac_addr_mask,
ARRAY_SIZE(entry->mac_addr_mask));
entry->dlid_sd = cpu_to_be32(nentry->dlid_sd);
}
tbl->mac_tbl_digest = cpu_to_be32(adapter->info.vport.mac_tbl_digest);
get_mac_done:
rcu_read_unlock();
}
int opa_vnic_update_mac_tbl(struct opa_vnic_adapter *adapter,
struct opa_veswport_mactable *tbl)
{
struct opa_vnic_mac_tbl_node *node, *new_node;
struct hlist_head *new_mactbl, *old_mactbl;
int i, bkt, rc = 0;
u8 key;
u16 loffset, lnum_entries;
mutex_lock(&adapter->mactbl_lock);
new_mactbl = opa_vnic_alloc_mac_tbl();
if (IS_ERR(new_mactbl)) {
mutex_unlock(&adapter->mactbl_lock);
return PTR_ERR(new_mactbl);
}
loffset = be16_to_cpu(tbl->offset);
lnum_entries = be16_to_cpu(tbl->num_entries);
for (i = 0; i < lnum_entries; i++) {
struct __opa_vnic_mactable_entry *nentry;
struct opa_veswport_mactable_entry *entry =
&tbl->tbl_entries[i];
u8 *mac_addr = entry->mac_addr;
u8 empty_mac[ETH_ALEN] = { 0 };
v_dbg("new mac entry %4d: %02x:%02x:%02x:%02x:%02x:%02x %x\n",
loffset + i, mac_addr[0], mac_addr[1], mac_addr[2],
mac_addr[3], mac_addr[4], mac_addr[5],
entry->dlid_sd);
if (!memcmp(mac_addr, empty_mac, ARRAY_SIZE(empty_mac)))
continue;
node = kzalloc(sizeof(*node), GFP_KERNEL);
if (!node) {
rc = -ENOMEM;
goto updt_done;
}
node->index = loffset + i;
nentry = &node->entry;
memcpy(nentry->mac_addr, entry->mac_addr,
ARRAY_SIZE(nentry->mac_addr));
memcpy(nentry->mac_addr_mask, entry->mac_addr_mask,
ARRAY_SIZE(nentry->mac_addr_mask));
nentry->dlid_sd = be32_to_cpu(entry->dlid_sd);
key = node->entry.mac_addr[OPA_VNIC_MAC_HASH_IDX];
vnic_hash_add(new_mactbl, &node->hlist, key);
}
old_mactbl = rcu_access_pointer(adapter->mactbl);
if (!old_mactbl)
goto switch_tbl;
vnic_hash_for_each(old_mactbl, bkt, node, hlist) {
if ((node->index >= loffset) &&
(node->index < (loffset + lnum_entries)))
continue;
new_node = kzalloc(sizeof(*new_node), GFP_KERNEL);
if (!new_node) {
rc = -ENOMEM;
goto updt_done;
}
new_node->index = node->index;
memcpy(&new_node->entry, &node->entry, sizeof(node->entry));
key = new_node->entry.mac_addr[OPA_VNIC_MAC_HASH_IDX];
vnic_hash_add(new_mactbl, &new_node->hlist, key);
}
switch_tbl:
rcu_assign_pointer(adapter->mactbl, new_mactbl);
synchronize_rcu();
adapter->info.vport.mac_tbl_digest = be32_to_cpu(tbl->mac_tbl_digest);
updt_done:
if (rc)
opa_vnic_free_mac_tbl(new_mactbl);
else
opa_vnic_free_mac_tbl(old_mactbl);
mutex_unlock(&adapter->mactbl_lock);
return rc;
}
static uint32_t opa_vnic_chk_mac_tbl(struct opa_vnic_adapter *adapter,
struct ethhdr *mac_hdr)
{
struct opa_vnic_mac_tbl_node *node;
struct hlist_head *mactbl;
u32 dlid = 0;
u8 key;
rcu_read_lock();
mactbl = rcu_dereference(adapter->mactbl);
if (unlikely(!mactbl))
goto chk_done;
key = mac_hdr->h_dest[OPA_VNIC_MAC_HASH_IDX];
vnic_hash_for_each_possible(mactbl, node, hlist, key) {
struct __opa_vnic_mactable_entry *entry = &node->entry;
if (unlikely(OPA_VNIC_DLID_SD_IS_SRC_MAC(entry->dlid_sd)))
continue;
if (!memcmp(node->entry.mac_addr, mac_hdr->h_dest,
ARRAY_SIZE(node->entry.mac_addr))) {
dlid = OPA_VNIC_DLID_SD_GET_DLID(node->entry.dlid_sd);
break;
}
}
chk_done:
rcu_read_unlock();
return dlid;
}
static uint32_t opa_vnic_get_dlid(struct opa_vnic_adapter *adapter,
struct sk_buff *skb, u8 def_port)
{
struct __opa_veswport_info *info = &adapter->info;
struct ethhdr *mac_hdr = (struct ethhdr *)skb_mac_header(skb);
u32 dlid;
dlid = opa_vnic_chk_mac_tbl(adapter, mac_hdr);
if (dlid)
return dlid;
if (is_multicast_ether_addr(mac_hdr->h_dest)) {
dlid = info->vesw.u_mcast_dlid;
} else {
if (is_local_ether_addr(mac_hdr->h_dest)) {
dlid = ((uint32_t)mac_hdr->h_dest[5] << 16) |
((uint32_t)mac_hdr->h_dest[4] << 8) |
mac_hdr->h_dest[3];
if (unlikely(!dlid))
v_warn("Null dlid in MAC address\n");
} else if (def_port != OPA_VNIC_INVALID_PORT) {
dlid = info->vesw.u_ucast_dlid[def_port];
}
}
return dlid;
}
static u8 opa_vnic_get_sc(struct __opa_veswport_info *info,
struct sk_buff *skb)
{
struct ethhdr *mac_hdr = (struct ethhdr *)skb_mac_header(skb);
u16 vlan_tci;
u8 sc;
if (!__vlan_get_tag(skb, &vlan_tci)) {
u8 pcp = OPA_VNIC_VLAN_PCP(vlan_tci);
if (is_multicast_ether_addr(mac_hdr->h_dest))
sc = info->vport.pcp_to_sc_mc[pcp];
else
sc = info->vport.pcp_to_sc_uc[pcp];
} else {
if (is_multicast_ether_addr(mac_hdr->h_dest))
sc = info->vport.non_vlan_sc_mc;
else
sc = info->vport.non_vlan_sc_uc;
}
return sc;
}
u8 opa_vnic_get_vl(struct opa_vnic_adapter *adapter, struct sk_buff *skb)
{
struct ethhdr *mac_hdr = (struct ethhdr *)skb_mac_header(skb);
struct __opa_veswport_info *info = &adapter->info;
u8 vl;
if (skb_vlan_tag_present(skb)) {
u8 pcp = skb_vlan_tag_get(skb) >> VLAN_PRIO_SHIFT;
if (is_multicast_ether_addr(mac_hdr->h_dest))
vl = info->vport.pcp_to_vl_mc[pcp];
else
vl = info->vport.pcp_to_vl_uc[pcp];
} else {
if (is_multicast_ether_addr(mac_hdr->h_dest))
vl = info->vport.non_vlan_vl_mc;
else
vl = info->vport.non_vlan_vl_uc;
}
return vl;
}
u8 opa_vnic_calc_entropy(struct opa_vnic_adapter *adapter, struct sk_buff *skb)
{
u16 hash16;
hash16 = __skb_tx_hash(adapter->netdev, skb, BIT(15));
return (u8)((hash16 >> 8) ^ (hash16 & 0xff));
}
static inline u8 opa_vnic_get_def_port(struct opa_vnic_adapter *adapter,
u8 entropy)
{
u8 flow_id;
flow_id = ((entropy & 0xf) + (entropy >> 4));
return adapter->flow_tbl[flow_id & (OPA_VNIC_FLOW_TBL_SIZE - 1)];
}
static inline int opa_vnic_wire_length(struct sk_buff *skb)
{
u32 pad_len;
pad_len = -(skb->len + OPA_VNIC_ICRC_TAIL_LEN) & 0x7;
pad_len += OPA_VNIC_ICRC_TAIL_LEN;
return (skb->len + pad_len) >> 3;
}
void opa_vnic_encap_skb(struct opa_vnic_adapter *adapter, struct sk_buff *skb)
{
struct __opa_veswport_info *info = &adapter->info;
struct opa_vnic_skb_mdata *mdata;
u8 def_port, sc, entropy, *hdr;
u16 len, l4_hdr;
u32 dlid;
hdr = skb_push(skb, OPA_VNIC_HDR_LEN);
entropy = opa_vnic_calc_entropy(adapter, skb);
def_port = opa_vnic_get_def_port(adapter, entropy);
len = opa_vnic_wire_length(skb);
dlid = opa_vnic_get_dlid(adapter, skb, def_port);
sc = opa_vnic_get_sc(info, skb);
l4_hdr = info->vesw.vesw_id;
mdata = (struct opa_vnic_skb_mdata *)skb_push(skb, sizeof(*mdata));
mdata->vl = opa_vnic_get_vl(adapter, skb);
mdata->entropy = entropy;
mdata->flags = 0;
if (unlikely(!dlid)) {
mdata->flags = OPA_VNIC_SKB_MDATA_ENCAP_ERR;
return;
}
opa_vnic_make_header(hdr, info->vport.encap_slid, dlid, len,
info->vesw.pkey, entropy, sc, 0,
OPA_VNIC_L4_ETHR, l4_hdr);
}
