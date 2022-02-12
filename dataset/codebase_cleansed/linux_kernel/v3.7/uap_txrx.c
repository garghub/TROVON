static void mwifiex_uap_queue_bridged_pkt(struct mwifiex_private *priv,
struct sk_buff *skb)
{
struct mwifiex_adapter *adapter = priv->adapter;
struct uap_rxpd *uap_rx_pd;
struct rx_packet_hdr *rx_pkt_hdr;
struct sk_buff *new_skb;
struct mwifiex_txinfo *tx_info;
int hdr_chop;
struct timeval tv;
u8 rfc1042_eth_hdr[ETH_ALEN] = { 0xaa, 0xaa, 0x03, 0x00, 0x00, 0x00 };
uap_rx_pd = (struct uap_rxpd *)(skb->data);
rx_pkt_hdr = (void *)uap_rx_pd + le16_to_cpu(uap_rx_pd->rx_pkt_offset);
if ((atomic_read(&adapter->pending_bridged_pkts) >=
MWIFIEX_BRIDGED_PKTS_THRESHOLD)) {
dev_err(priv->adapter->dev,
"Tx: Bridge packet limit reached. Drop packet!\n");
kfree_skb(skb);
return;
}
if (!memcmp(&rx_pkt_hdr->rfc1042_hdr,
rfc1042_eth_hdr, sizeof(rfc1042_eth_hdr)))
hdr_chop = (u8 *)eth_hdr - (u8 *)uap_rx_pd;
else
hdr_chop = (u8 *)&rx_pkt_hdr->eth803_hdr - (u8 *)uap_rx_pd;
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
tx_info->bss_num = priv->bss_num;
tx_info->bss_type = priv->bss_type;
tx_info->flags |= MWIFIEX_BUF_FLAG_BRIDGED_PKT;
do_gettimeofday(&tv);
skb->tstamp = timeval_to_ktime(tv);
mwifiex_wmm_add_buf_txqueue(priv, skb);
atomic_inc(&adapter->tx_pending);
atomic_inc(&adapter->pending_bridged_pkts);
if ((atomic_read(&adapter->tx_pending) >= MAX_TX_PENDING)) {
mwifiex_set_trans_start(priv->netdev);
mwifiex_stop_net_dev_queue(priv->netdev, priv->adapter);
}
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
return mwifiex_process_rx_packet(adapter, skb);
}
int mwifiex_process_uap_rx_packet(struct mwifiex_adapter *adapter,
struct sk_buff *skb)
{
int ret;
struct uap_rxpd *uap_rx_pd;
struct mwifiex_rxinfo *rx_info = MWIFIEX_SKB_RXCB(skb);
struct rx_packet_hdr *rx_pkt_hdr;
u16 rx_pkt_type;
u8 ta[ETH_ALEN], pkt_type;
struct mwifiex_sta_node *node;
struct mwifiex_private *priv =
mwifiex_get_priv_by_id(adapter, rx_info->bss_num,
rx_info->bss_type);
if (!priv)
return -1;
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
if (adapter->if_ops.data_complete)
adapter->if_ops.data_complete(adapter, skb);
else
dev_kfree_skb_any(skb);
return 0;
}
if (le16_to_cpu(uap_rx_pd->rx_pkt_type) == PKT_TYPE_AMSDU) {
struct sk_buff_head list;
struct sk_buff *rx_skb;
__skb_queue_head_init(&list);
skb_pull(skb, le16_to_cpu(uap_rx_pd->rx_pkt_offset));
skb_trim(skb, le16_to_cpu(uap_rx_pd->rx_pkt_length));
ieee80211_amsdu_to_8023s(skb, &list, priv->curr_addr,
priv->wdev->iftype, 0, false);
while (!skb_queue_empty(&list)) {
rx_skb = __skb_dequeue(&list);
ret = mwifiex_recv_packet(adapter, rx_skb);
if (ret)
dev_err(adapter->dev,
"AP:Rx A-MSDU failed");
}
return 0;
} else if (rx_pkt_type == PKT_TYPE_MGMT) {
ret = mwifiex_process_mgmt_packet(adapter, skb);
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
if (ret || (rx_pkt_type == PKT_TYPE_BAR)) {
if (adapter->if_ops.data_complete)
adapter->if_ops.data_complete(adapter, skb);
else
dev_kfree_skb_any(skb);
}
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
