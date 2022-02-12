int mwifiex_process_rx_packet(struct mwifiex_private *priv,
struct sk_buff *skb)
{
int ret;
struct rx_packet_hdr *rx_pkt_hdr;
struct rxpd *local_rx_pd;
int hdr_chop;
struct ethhdr *eth_hdr;
u8 rfc1042_eth_hdr[ETH_ALEN] = { 0xaa, 0xaa, 0x03, 0x00, 0x00, 0x00 };
local_rx_pd = (struct rxpd *) (skb->data);
rx_pkt_hdr = (void *)local_rx_pd +
le16_to_cpu(local_rx_pd->rx_pkt_offset);
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
ret = mwifiex_recv_packet(priv, skb);
if (ret == -1)
dev_err(priv->adapter->dev, "recv packet failed\n");
return ret;
}
int mwifiex_process_sta_rx_packet(struct mwifiex_private *priv,
struct sk_buff *skb)
{
struct mwifiex_adapter *adapter = priv->adapter;
int ret = 0;
struct rxpd *local_rx_pd;
struct rx_packet_hdr *rx_pkt_hdr;
u8 ta[ETH_ALEN];
u16 rx_pkt_type, rx_pkt_offset, rx_pkt_length, seq_num;
local_rx_pd = (struct rxpd *) (skb->data);
rx_pkt_type = le16_to_cpu(local_rx_pd->rx_pkt_type);
rx_pkt_offset = le16_to_cpu(local_rx_pd->rx_pkt_offset);
rx_pkt_length = le16_to_cpu(local_rx_pd->rx_pkt_length);
seq_num = le16_to_cpu(local_rx_pd->seq_num);
rx_pkt_hdr = (void *)local_rx_pd + rx_pkt_offset;
if ((rx_pkt_offset + rx_pkt_length) > (u16) skb->len) {
dev_err(adapter->dev,
"wrong rx packet: len=%d, rx_pkt_offset=%d, rx_pkt_length=%d\n",
skb->len, rx_pkt_offset, rx_pkt_length);
priv->stats.rx_dropped++;
if (adapter->if_ops.data_complete)
adapter->if_ops.data_complete(adapter, skb);
else
dev_kfree_skb_any(skb);
return ret;
}
if (rx_pkt_type == PKT_TYPE_AMSDU) {
struct sk_buff_head list;
struct sk_buff *rx_skb;
__skb_queue_head_init(&list);
skb_pull(skb, rx_pkt_offset);
skb_trim(skb, rx_pkt_length);
ieee80211_amsdu_to_8023s(skb, &list, priv->curr_addr,
priv->wdev->iftype, 0, false);
while (!skb_queue_empty(&list)) {
rx_skb = __skb_dequeue(&list);
ret = mwifiex_recv_packet(priv, rx_skb);
if (ret == -1)
dev_err(adapter->dev, "Rx of A-MSDU failed");
}
return 0;
} else if (rx_pkt_type == PKT_TYPE_MGMT) {
ret = mwifiex_process_mgmt_packet(priv, skb);
if (ret)
dev_err(adapter->dev, "Rx of mgmt packet failed");
dev_kfree_skb_any(skb);
return ret;
}
if (!IS_11N_ENABLED(priv) ||
memcmp(priv->curr_addr, rx_pkt_hdr->eth803_hdr.h_dest, ETH_ALEN)) {
mwifiex_process_rx_packet(priv, skb);
return ret;
}
if (mwifiex_queuing_ra_based(priv)) {
memcpy(ta, rx_pkt_hdr->eth803_hdr.h_source, ETH_ALEN);
} else {
if (rx_pkt_type != PKT_TYPE_BAR)
priv->rx_seq[local_rx_pd->priority] = seq_num;
memcpy(ta, priv->curr_bss_params.bss_descriptor.mac_address,
ETH_ALEN);
}
ret = mwifiex_11n_rx_reorder_pkt(priv, seq_num, local_rx_pd->priority,
ta, (u8) rx_pkt_type, skb);
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
