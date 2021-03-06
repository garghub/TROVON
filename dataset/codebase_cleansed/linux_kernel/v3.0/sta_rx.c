int mwifiex_process_rx_packet(struct mwifiex_adapter *adapter,
struct sk_buff *skb)
{
int ret;
struct mwifiex_rxinfo *rx_info = MWIFIEX_SKB_RXCB(skb);
struct mwifiex_private *priv = adapter->priv[rx_info->bss_index];
struct rx_packet_hdr *rx_pkt_hdr;
struct rxpd *local_rx_pd;
int hdr_chop;
struct ethhdr *eth_hdr;
u8 rfc1042_eth_hdr[ETH_ALEN] = { 0xaa, 0xaa, 0x03, 0x00, 0x00, 0x00 };
local_rx_pd = (struct rxpd *) (skb->data);
rx_pkt_hdr = (struct rx_packet_hdr *) ((u8 *) local_rx_pd +
local_rx_pd->rx_pkt_offset);
if (!memcmp(&rx_pkt_hdr->rfc1042_hdr,
rfc1042_eth_hdr, sizeof(rfc1042_eth_hdr))) {
eth_hdr = (struct ethhdr *)
((u8 *) &rx_pkt_hdr->eth803_hdr
+ sizeof(rx_pkt_hdr->eth803_hdr) +
sizeof(rx_pkt_hdr->rfc1042_hdr)
- sizeof(rx_pkt_hdr->eth803_hdr.h_dest)
- sizeof(rx_pkt_hdr->eth803_hdr.h_source)
- sizeof(rx_pkt_hdr->rfc1042_hdr.snap_type));
memcpy(eth_hdr->h_source, rx_pkt_hdr->eth803_hdr.h_source,
sizeof(eth_hdr->h_source));
memcpy(eth_hdr->h_dest, rx_pkt_hdr->eth803_hdr.h_dest,
sizeof(eth_hdr->h_dest));
hdr_chop = (u8 *) eth_hdr - (u8 *) local_rx_pd;
} else {
hdr_chop = (u8 *) &rx_pkt_hdr->eth803_hdr -
(u8 *) local_rx_pd;
}
skb_pull(skb, hdr_chop);
priv->rxpd_rate = local_rx_pd->rx_rate;
priv->rxpd_htinfo = local_rx_pd->ht_info;
ret = mwifiex_recv_packet(adapter, skb);
if (ret == -1)
dev_err(adapter->dev, "recv packet failed\n");
return ret;
}
int mwifiex_process_sta_rx_packet(struct mwifiex_adapter *adapter,
struct sk_buff *skb)
{
int ret = 0;
struct rxpd *local_rx_pd;
struct mwifiex_rxinfo *rx_info = MWIFIEX_SKB_RXCB(skb);
struct rx_packet_hdr *rx_pkt_hdr;
u8 ta[ETH_ALEN];
u16 rx_pkt_type;
struct mwifiex_private *priv = adapter->priv[rx_info->bss_index];
local_rx_pd = (struct rxpd *) (skb->data);
rx_pkt_type = local_rx_pd->rx_pkt_type;
rx_pkt_hdr = (struct rx_packet_hdr *) ((u8 *) local_rx_pd +
local_rx_pd->rx_pkt_offset);
if ((local_rx_pd->rx_pkt_offset + local_rx_pd->rx_pkt_length) >
(u16) skb->len) {
dev_err(adapter->dev, "wrong rx packet: len=%d,"
" rx_pkt_offset=%d, rx_pkt_length=%d\n", skb->len,
local_rx_pd->rx_pkt_offset, local_rx_pd->rx_pkt_length);
priv->stats.rx_dropped++;
dev_kfree_skb_any(skb);
return ret;
}
if (local_rx_pd->rx_pkt_type == PKT_TYPE_AMSDU) {
struct sk_buff_head list;
struct sk_buff *rx_skb;
__skb_queue_head_init(&list);
skb_pull(skb, local_rx_pd->rx_pkt_offset);
skb_trim(skb, local_rx_pd->rx_pkt_length);
ieee80211_amsdu_to_8023s(skb, &list, priv->curr_addr,
priv->wdev->iftype, 0, false);
while (!skb_queue_empty(&list)) {
rx_skb = __skb_dequeue(&list);
ret = mwifiex_recv_packet(adapter, rx_skb);
if (ret == -1)
dev_err(adapter->dev, "Rx of A-MSDU failed");
}
return 0;
}
if (!IS_11N_ENABLED(priv) ||
memcmp(priv->curr_addr, rx_pkt_hdr->eth803_hdr.h_dest, ETH_ALEN)) {
mwifiex_process_rx_packet(adapter, skb);
return ret;
}
if (mwifiex_queuing_ra_based(priv)) {
memcpy(ta, rx_pkt_hdr->eth803_hdr.h_source, ETH_ALEN);
} else {
if (rx_pkt_type != PKT_TYPE_BAR)
priv->rx_seq[local_rx_pd->priority] =
local_rx_pd->seq_num;
memcpy(ta, priv->curr_bss_params.bss_descriptor.mac_address,
ETH_ALEN);
}
ret = mwifiex_11n_rx_reorder_pkt(priv, local_rx_pd->seq_num,
local_rx_pd->priority, ta,
(u8) local_rx_pd->rx_pkt_type,
(void *) skb);
if (ret || (rx_pkt_type == PKT_TYPE_BAR)) {
if (priv && (ret == -1))
priv->stats.rx_dropped++;
dev_kfree_skb_any(skb);
}
return ret;
}
