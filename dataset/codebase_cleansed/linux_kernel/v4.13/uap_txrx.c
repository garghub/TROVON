static bool
mwifiex_uap_del_tx_pkts_in_ralist(struct mwifiex_private *priv,
struct list_head *ra_list_head,
int tid)
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
if (ra_list->tx_paused)
priv->wmm.pkts_paused[tid]--;
else
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
if (mwifiex_uap_del_tx_pkts_in_ralist(priv, ra_list, i)) {
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
struct mwifiex_sta_node *src_node;
int index;
uap_rx_pd = (struct uap_rxpd *)(skb->data);
rx_pkt_hdr = (void *)uap_rx_pd + le16_to_cpu(uap_rx_pd->rx_pkt_offset);
if ((atomic_read(&adapter->pending_bridged_pkts) >=
MWIFIEX_BRIDGED_PKTS_THR_HIGH)) {
mwifiex_dbg(priv->adapter, ERROR,
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
mwifiex_dbg(priv->adapter, ERROR,
"data: Tx: insufficient skb headroom %d\n",
skb_headroom(skb));
new_skb =
skb_realloc_headroom(skb, MWIFIEX_MIN_DATA_HEADER_LEN);
if (unlikely(!new_skb)) {
mwifiex_dbg(priv->adapter, ERROR,
"Tx: cannot allocate new_skb\n");
kfree_skb(skb);
priv->stats.tx_dropped++;
return;
}
kfree_skb(skb);
skb = new_skb;
mwifiex_dbg(priv->adapter, INFO,
"info: new skb headroom %d\n",
skb_headroom(skb));
}
tx_info = MWIFIEX_SKB_TXCB(skb);
memset(tx_info, 0, sizeof(*tx_info));
tx_info->bss_num = priv->bss_num;
tx_info->bss_type = priv->bss_type;
tx_info->flags |= MWIFIEX_BUF_FLAG_BRIDGED_PKT;
src_node = mwifiex_get_sta_entry(priv, rx_pkt_hdr->eth803_hdr.h_source);
if (src_node) {
src_node->stats.last_rx = jiffies;
src_node->stats.rx_bytes += skb->len;
src_node->stats.rx_packets++;
src_node->stats.last_tx_rate = uap_rx_pd->rx_rate;
src_node->stats.last_tx_htinfo = uap_rx_pd->ht_info;
}
if (is_unicast_ether_addr(rx_pkt_hdr->eth803_hdr.h_dest)) {
priv->stats.rx_bytes += skb->len;
priv->stats.rx_packets++;
tx_info->pkt_len = skb->len;
}
__net_timestamp(skb);
index = mwifiex_1d_to_wmm_queue[skb->priority];
atomic_inc(&priv->wmm_tx_pending[index]);
mwifiex_wmm_add_buf_txqueue(priv, skb);
atomic_inc(&adapter->tx_pending);
atomic_inc(&adapter->pending_bridged_pkts);
mwifiex_queue_main_work(priv->adapter);
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
mwifiex_dbg(adapter, ERROR,
"drop packet in disconnected state.\n");
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
int mwifiex_uap_recv_packet(struct mwifiex_private *priv,
struct sk_buff *skb)
{
struct mwifiex_adapter *adapter = priv->adapter;
struct mwifiex_sta_node *src_node;
struct ethhdr *p_ethhdr;
struct sk_buff *skb_uap;
struct mwifiex_txinfo *tx_info;
if (!skb)
return -1;
p_ethhdr = (void *)skb->data;
src_node = mwifiex_get_sta_entry(priv, p_ethhdr->h_source);
if (src_node) {
src_node->stats.last_rx = jiffies;
src_node->stats.rx_bytes += skb->len;
src_node->stats.rx_packets++;
}
skb->dev = priv->netdev;
skb->protocol = eth_type_trans(skb, priv->netdev);
skb->ip_summed = CHECKSUM_NONE;
if ((adapter->iface_type == MWIFIEX_USB ||
adapter->iface_type == MWIFIEX_PCIE) &&
(skb->truesize > MWIFIEX_RX_DATA_BUF_SIZE))
skb->truesize += (skb->len - MWIFIEX_RX_DATA_BUF_SIZE);
if (is_multicast_ether_addr(p_ethhdr->h_dest) ||
mwifiex_get_sta_entry(priv, p_ethhdr->h_dest)) {
if (skb_headroom(skb) < MWIFIEX_MIN_DATA_HEADER_LEN)
skb_uap =
skb_realloc_headroom(skb, MWIFIEX_MIN_DATA_HEADER_LEN);
else
skb_uap = skb_copy(skb, GFP_ATOMIC);
if (likely(skb_uap)) {
tx_info = MWIFIEX_SKB_TXCB(skb_uap);
memset(tx_info, 0, sizeof(*tx_info));
tx_info->bss_num = priv->bss_num;
tx_info->bss_type = priv->bss_type;
tx_info->flags |= MWIFIEX_BUF_FLAG_BRIDGED_PKT;
__net_timestamp(skb_uap);
mwifiex_wmm_add_buf_txqueue(priv, skb_uap);
atomic_inc(&adapter->tx_pending);
atomic_inc(&adapter->pending_bridged_pkts);
if ((atomic_read(&adapter->pending_bridged_pkts) >=
MWIFIEX_BRIDGED_PKTS_THR_HIGH)) {
mwifiex_dbg(adapter, ERROR,
"Tx: Bridge packet limit reached. Drop packet!\n");
mwifiex_uap_cleanup_tx_queues(priv);
}
} else {
mwifiex_dbg(adapter, ERROR, "failed to allocate skb_uap");
}
mwifiex_queue_main_work(adapter);
if (mwifiex_get_sta_entry(priv, p_ethhdr->h_dest))
return 0;
}
if (in_interrupt())
netif_rx(skb);
else
netif_rx_ni(skb);
return 0;
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
unsigned long flags;
struct mwifiex_sta_node *node;
uap_rx_pd = (struct uap_rxpd *)(skb->data);
rx_pkt_type = le16_to_cpu(uap_rx_pd->rx_pkt_type);
rx_pkt_hdr = (void *)uap_rx_pd + le16_to_cpu(uap_rx_pd->rx_pkt_offset);
ether_addr_copy(ta, rx_pkt_hdr->eth803_hdr.h_source);
if ((le16_to_cpu(uap_rx_pd->rx_pkt_offset) +
le16_to_cpu(uap_rx_pd->rx_pkt_length)) > (u16) skb->len) {
mwifiex_dbg(adapter, ERROR,
"wrong rx packet: len=%d, offset=%d, length=%d\n",
skb->len, le16_to_cpu(uap_rx_pd->rx_pkt_offset),
le16_to_cpu(uap_rx_pd->rx_pkt_length));
priv->stats.rx_dropped++;
node = mwifiex_get_sta_entry(priv, ta);
if (node)
node->stats.tx_failed++;
dev_kfree_skb_any(skb);
return 0;
}
if (rx_pkt_type == PKT_TYPE_MGMT) {
ret = mwifiex_process_mgmt_packet(priv, skb);
if (ret)
mwifiex_dbg(adapter, DATA, "Rx of mgmt packet failed");
dev_kfree_skb_any(skb);
return ret;
}
if (rx_pkt_type != PKT_TYPE_BAR && uap_rx_pd->priority < MAX_NUM_TID) {
spin_lock_irqsave(&priv->sta_list_spinlock, flags);
node = mwifiex_get_sta_entry(priv, ta);
if (node)
node->rx_seq[uap_rx_pd->priority] =
le16_to_cpu(uap_rx_pd->seq_num);
spin_unlock_irqrestore(&priv->sta_list_spinlock, flags);
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
int pad;
u16 pkt_type, pkt_offset;
int hroom = adapter->intf_hdr_len;
if (!skb->len) {
mwifiex_dbg(adapter, ERROR,
"Tx: bad packet length: %d\n", skb->len);
tx_info->status_code = -1;
return skb->data;
}
BUG_ON(skb_headroom(skb) < MWIFIEX_MIN_DATA_HEADER_LEN);
pkt_type = mwifiex_is_skb_mgmt_frame(skb) ? PKT_TYPE_MGMT : 0;
pad = ((void *)skb->data - (sizeof(*txpd) + hroom) - NULL) &
(MWIFIEX_DMA_ALIGN_SZ - 1);
skb_push(skb, sizeof(*txpd) + pad);
txpd = (struct uap_txpd *)skb->data;
memset(txpd, 0, sizeof(*txpd));
txpd->bss_num = priv->bss_num;
txpd->bss_type = priv->bss_type;
txpd->tx_pkt_length = cpu_to_le16((u16)(skb->len - (sizeof(*txpd) +
pad)));
txpd->priority = (u8)skb->priority;
txpd->pkt_delay_2ms = mwifiex_wmm_compute_drv_pkt_delay(priv, skb);
if (tx_info->flags & MWIFIEX_BUF_FLAG_EAPOL_TX_STATUS ||
tx_info->flags & MWIFIEX_BUF_FLAG_ACTION_TX_STATUS) {
txpd->tx_token_id = tx_info->ack_frame_id;
txpd->flags |= MWIFIEX_TXPD_FLAGS_REQ_TX_STATUS;
}
if (txpd->priority < ARRAY_SIZE(priv->wmm.user_pri_pkt_tx_ctrl))
txpd->tx_control =
cpu_to_le32(priv->wmm.user_pri_pkt_tx_ctrl[txpd->priority]);
pkt_offset = sizeof(*txpd) + pad;
if (pkt_type == PKT_TYPE_MGMT) {
txpd->tx_pkt_type = cpu_to_le16(pkt_type);
pkt_offset += MWIFIEX_MGMT_FRAME_HEADER_SIZE;
}
txpd->tx_pkt_offset = cpu_to_le16(pkt_offset);
skb_push(skb, hroom);
if (!txpd->tx_control)
txpd->tx_control = cpu_to_le32(priv->pkt_tx_ctrl);
return skb->data;
}
