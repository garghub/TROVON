static bool
mwifiex_uap_del_tx_pkts_in_ralist(struct mwifiex_private *priv,
struct list_head *ra_list_head)
{
struct mwifiex_ra_list_tbl *ra_list;
struct sk_buff *skb, *tmp;
bool pkt_deleted = false;
struct mwifiex_txinfo *tx_info;
struct mwifiex_adapter *adapter = priv->adapter;
list_for_each_entry(ra_list, ra_list_head, list) {
if (skb_queue_empty(&ra_list->skb_head))
continue;
skb_queue_walk_safe(&ra_list->skb_head, skb, tmp) {
tx_info = MWIFIEX_SKB_TXCB(skb);
if (tx_info->flags & MWIFIEX_BUF_FLAG_BRIDGED_PKT) {
__skb_unlink(skb, &ra_list->skb_head);
mwifiex_write_data_complete(adapter, skb, 0,
-1);
atomic_dec(&priv->wmm.tx_pkts_queued);
pkt_deleted = true;
}
if ((atomic_read(&adapter->pending_bridged_pkts) <=
MWIFIEX_BRIDGED_PKTS_THR_LOW))
break;
}
}
return pkt_deleted;
}
static void mwifiex_uap_cleanup_tx_queues(struct mwifiex_private *priv)
{
unsigned long flags;
struct list_head *ra_list;
int i;
spin_lock_irqsave(&priv->wmm.ra_list_spinlock, flags);
for (i = 0; i < MAX_NUM_TID; i++, priv->del_list_idx++) {
if (priv->del_list_idx == MAX_NUM_TID)
priv->del_list_idx = 0;
ra_list = &priv->wmm.tid_tbl_ptr[priv->del_list_idx].ra_list;
if (mwifiex_uap_del_tx_pkts_in_ralist(priv, ra_list)) {
priv->del_list_idx++;
break;
}
}
spin_unlock_irqrestore(&priv->wmm.ra_list_spinlock, flags);
}
static void mwifiex_uap_queue_bridged_pkt(struct mwifiex_private *priv,
struct sk_buff *skb)
{
struct mwifiex_adapter *adapter = priv->adapter;
struct uap_rxpd *uap_rx_pd;
struct rx_packet_hdr *rx_pkt_hdr;
struct sk_buff *new_skb;
struct mwifiex_txinfo *tx_info;
int hdr_chop;
struct ethhdr *p_ethhdr;
uap_rx_pd = (struct uap_rxpd *)(skb->data);
rx_pkt_hdr = (void *)uap_rx_pd + le16_to_cpu(uap_rx_pd->rx_pkt_offset);
if ((atomic_read(&adapter->pending_bridged_pkts) >=
MWIFIEX_BRIDGED_PKTS_THR_HIGH)) {
dev_err(priv->adapter->dev,
"Tx: Bridge packet limit reached. Drop packet!\n");
kfree_skb(skb);
mwifiex_uap_cleanup_tx_queues(priv);
return;
}
if ((!memcmp(&rx_pkt_hdr->rfc1042_hdr, bridge_tunnel_header,
sizeof(bridge_tunnel_header))) ||
(!memcmp(&rx_pkt_hdr->rfc1042_hdr, rfc1042_header,
sizeof(rfc1042_header)) &&
ntohs(rx_pkt_hdr->rfc1042_hdr.snap_type) != ETH_P_AARP &&
ntohs(rx_pkt_hdr->rfc1042_hdr.snap_type) != ETH_P_IPX)) {
p_ethhdr = (struct ethhdr *)
((u8 *)(&rx_pkt_hdr->eth803_hdr)
+ sizeof(rx_pkt_hdr->eth803_hdr)
+ sizeof(rx_pkt_hdr->rfc1042_hdr)
- sizeof(rx_pkt_hdr->eth803_hdr.h_dest)
- sizeof(rx_pkt_hdr->eth803_hdr.h_source)
- sizeof(rx_pkt_hdr->rfc1042_hdr.snap_type));
memcpy(p_ethhdr->h_source, rx_pkt_hdr->eth803_hdr.h_source,
sizeof(p_ethhdr->h_source));
memcpy(p_ethhdr->h_dest, rx_pkt_hdr->eth803_hdr.h_dest,
sizeof(p_ethhdr->h_dest));
hdr_chop = (u8 *)p_ethhdr - (u8 *)uap_rx_pd;
} else {
hdr_chop = (u8 *)&rx_pkt_hdr->eth803_hdr - (u8 *)uap_rx_pd;
}
skb_pull(skb, hdr_chop);
if (skb_headroom(skb) < MWIFIEX_MIN_DATA_HEADER_LEN) {
dev_dbg(priv->adapter->dev,
"data: Tx: insufficient skb headroom %d\n",
skb_headroom(skb));
new_skb =
skb_realloc_headroom(skb, MWIFIEX_MIN_DATA_HEADER_LEN);
if (unlikely(!new_skb)) {
dev_err(priv->adapter->dev,
"Tx: cannot allocate new_skb\n");
kfree_skb(skb);
priv->stats.tx_dropped++;
return;
}
kfree_skb(skb);
skb = new_skb;
dev_dbg(priv->adapter->dev, "info: new skb headroom %d\n",
skb_headroom(skb));
}
tx_info = MWIFIEX_SKB_TXCB(skb);
memset(tx_info, 0, sizeof(*tx_info));
tx_info->bss_num = priv->bss_num;
tx_info->bss_type = priv->bss_type;
tx_info->flags |= MWIFIEX_BUF_FLAG_BRIDGED_PKT;
if (is_unicast_ether_addr(rx_pkt_hdr->eth803_hdr.h_dest)) {
priv->stats.rx_bytes += skb->len;
priv->stats.rx_packets++;
tx_info->pkt_len = skb->len;
}
__net_timestamp(skb);
mwifiex_wmm_add_buf_txqueue(priv, skb);
atomic_inc(&adapter->tx_pending);
atomic_inc(&adapter->pending_bridged_pkts);
return;
}
int mwifiex_handle_uap_rx_forward(struct mwifiex_private *priv,
struct sk_buff *skb)
{
struct mwifiex_adapter *adapter = priv->adapter;
struct uap_rxpd *uap_rx_pd;
struct rx_packet_hdr *rx_pkt_hdr;
u8 ra[ETH_ALEN];
struct sk_buff *skb_uap;
uap_rx_pd = (struct uap_rxpd *)(skb->data);
rx_pkt_hdr = (void *)uap_rx_pd + le16_to_cpu(uap_rx_pd->rx_pkt_offset);
if (!priv->media_connected) {
dev_err(adapter->dev, "drop packet in disconnected state.\n");
dev_kfree_skb_any(skb);
return 0;
}
memcpy(ra, rx_pkt_hdr->eth803_hdr.h_dest, ETH_ALEN);
if (is_multicast_ether_addr(ra)) {
skb_uap = skb_copy(skb, GFP_ATOMIC);
mwifiex_uap_queue_bridged_pkt(priv, skb_uap);
} else {
if (mwifiex_get_sta_entry(priv, ra)) {
mwifiex_uap_queue_bridged_pkt(priv, skb);
return 0;
}
}
return mwifiex_process_rx_packet(priv, skb);
}
int mwifiex_process_uap_rx_packet(struct mwifiex_private *priv,
struct sk_buff *skb)
{
struct mwifiex_adapter *adapter = priv->adapter;
int ret;
struct uap_rxpd *uap_rx_pd;
struct rx_packet_hdr *rx_pkt_hdr;
u16 rx_pkt_type;
u8 ta[ETH_ALEN], pkt_type;
struct mwifiex_sta_node *node;
uap_rx_pd = (struct uap_rxpd *)(skb->data);
rx_pkt_type = le16_to_cpu(uap_rx_pd->rx_pkt_type);
rx_pkt_hdr = (void *)uap_rx_pd + le16_to_cpu(uap_rx_pd->rx_pkt_offset);
if ((le16_to_cpu(uap_rx_pd->rx_pkt_offset) +
le16_to_cpu(uap_rx_pd->rx_pkt_length)) > (u16) skb->len) {
dev_err(adapter->dev,
"wrong rx packet: len=%d, offset=%d, length=%d\n",
skb->len, le16_to_cpu(uap_rx_pd->rx_pkt_offset),
le16_to_cpu(uap_rx_pd->rx_pkt_length));
priv->stats.rx_dropped++;
dev_kfree_skb_any(skb);
return 0;
}
if (rx_pkt_type == PKT_TYPE_MGMT) {
ret = mwifiex_process_mgmt_packet(priv, skb);
if (ret)
dev_err(adapter->dev, "Rx of mgmt packet failed");
dev_kfree_skb_any(skb);
return ret;
}
memcpy(ta, rx_pkt_hdr->eth803_hdr.h_source, ETH_ALEN);
if (rx_pkt_type != PKT_TYPE_BAR && uap_rx_pd->priority < MAX_NUM_TID) {
node = mwifiex_get_sta_entry(priv, ta);
if (node)
node->rx_seq[uap_rx_pd->priority] =
le16_to_cpu(uap_rx_pd->seq_num);
}
if (!priv->ap_11n_enabled ||
(!mwifiex_11n_get_rx_reorder_tbl(priv, uap_rx_pd->priority, ta) &&
(le16_to_cpu(uap_rx_pd->rx_pkt_type) != PKT_TYPE_AMSDU))) {
ret = mwifiex_handle_uap_rx_forward(priv, skb);
return ret;
}
pkt_type = (u8)le16_to_cpu(uap_rx_pd->rx_pkt_type);
ret = mwifiex_11n_rx_reorder_pkt(priv, le16_to_cpu(uap_rx_pd->seq_num),
uap_rx_pd->priority, ta, pkt_type,
skb);
if (ret || (rx_pkt_type == PKT_TYPE_BAR))
dev_kfree_skb_any(skb);
if (ret)
priv->stats.rx_dropped++;
return ret;
}
void *mwifiex_process_uap_txpd(struct mwifiex_private *priv,
struct sk_buff *skb)
{
struct mwifiex_adapter *adapter = priv->adapter;
struct uap_txpd *txpd;
struct mwifiex_txinfo *tx_info = MWIFIEX_SKB_TXCB(skb);
int pad, len;
u16 pkt_type;
if (!skb->len) {
dev_err(adapter->dev, "Tx: bad packet length: %d\n", skb->len);
tx_info->status_code = -1;
return skb->data;
}
pkt_type = mwifiex_is_skb_mgmt_frame(skb) ? PKT_TYPE_MGMT : 0;
pad = (4 - (((void *)skb->data - NULL) & 0x3)) % 4;
len = sizeof(*txpd) + pad;
BUG_ON(skb_headroom(skb) < len + INTF_HEADER_LEN);
skb_push(skb, len);
txpd = (struct uap_txpd *)skb->data;
memset(txpd, 0, sizeof(*txpd));
txpd->bss_num = priv->bss_num;
txpd->bss_type = priv->bss_type;
txpd->tx_pkt_length = cpu_to_le16((u16)(skb->len - len));
txpd->priority = (u8)skb->priority;
txpd->pkt_delay_2ms = mwifiex_wmm_compute_drv_pkt_delay(priv, skb);
if (txpd->priority < ARRAY_SIZE(priv->wmm.user_pri_pkt_tx_ctrl))
txpd->tx_control =
cpu_to_le32(priv->wmm.user_pri_pkt_tx_ctrl[txpd->priority]);
if (pkt_type == PKT_TYPE_MGMT) {
txpd->tx_pkt_type = cpu_to_le16(pkt_type);
len += MWIFIEX_MGMT_FRAME_HEADER_SIZE;
}
txpd->tx_pkt_offset = cpu_to_le16(len);
skb_push(skb, INTF_HEADER_LEN);
if (!txpd->tx_control)
txpd->tx_control = cpu_to_le32(priv->pkt_tx_ctrl);
return skb->data;
}
