static bool
mwifiex_discard_gratuitous_arp(struct mwifiex_private *priv,
struct sk_buff *skb)
{
const struct mwifiex_arp_eth_header *arp;
struct ethhdr *eth;
struct ipv6hdr *ipv6;
struct icmp6hdr *icmpv6;
eth = (struct ethhdr *)skb->data;
switch (ntohs(eth->h_proto)) {
case ETH_P_ARP:
arp = (void *)(skb->data + sizeof(struct ethhdr));
if (arp->hdr.ar_op == htons(ARPOP_REPLY) ||
arp->hdr.ar_op == htons(ARPOP_REQUEST)) {
if (!memcmp(arp->ar_sip, arp->ar_tip, 4))
return true;
}
break;
case ETH_P_IPV6:
ipv6 = (void *)(skb->data + sizeof(struct ethhdr));
icmpv6 = (void *)(skb->data + sizeof(struct ethhdr) +
sizeof(struct ipv6hdr));
if (NDISC_NEIGHBOUR_ADVERTISEMENT == icmpv6->icmp6_type) {
if (!memcmp(&ipv6->saddr, &ipv6->daddr,
sizeof(struct in6_addr)))
return true;
}
break;
default:
break;
}
return false;
}
int mwifiex_process_rx_packet(struct mwifiex_private *priv,
struct sk_buff *skb)
{
int ret;
struct rx_packet_hdr *rx_pkt_hdr;
struct rxpd *local_rx_pd;
int hdr_chop;
struct ethhdr *eth;
u16 rx_pkt_off, rx_pkt_len;
u8 *offset;
local_rx_pd = (struct rxpd *) (skb->data);
rx_pkt_off = le16_to_cpu(local_rx_pd->rx_pkt_offset);
rx_pkt_len = le16_to_cpu(local_rx_pd->rx_pkt_length);
rx_pkt_hdr = (void *)local_rx_pd + rx_pkt_off;
if ((!memcmp(&rx_pkt_hdr->rfc1042_hdr, bridge_tunnel_header,
sizeof(bridge_tunnel_header))) ||
(!memcmp(&rx_pkt_hdr->rfc1042_hdr, rfc1042_header,
sizeof(rfc1042_header)) &&
ntohs(rx_pkt_hdr->rfc1042_hdr.snap_type) != ETH_P_AARP &&
ntohs(rx_pkt_hdr->rfc1042_hdr.snap_type) != ETH_P_IPX)) {
eth = (struct ethhdr *)
((u8 *) &rx_pkt_hdr->eth803_hdr
+ sizeof(rx_pkt_hdr->eth803_hdr) +
sizeof(rx_pkt_hdr->rfc1042_hdr)
- sizeof(rx_pkt_hdr->eth803_hdr.h_dest)
- sizeof(rx_pkt_hdr->eth803_hdr.h_source)
- sizeof(rx_pkt_hdr->rfc1042_hdr.snap_type));
memcpy(eth->h_source, rx_pkt_hdr->eth803_hdr.h_source,
sizeof(eth->h_source));
memcpy(eth->h_dest, rx_pkt_hdr->eth803_hdr.h_dest,
sizeof(eth->h_dest));
hdr_chop = (u8 *) eth - (u8 *) local_rx_pd;
} else {
hdr_chop = (u8 *) &rx_pkt_hdr->eth803_hdr -
(u8 *) local_rx_pd;
}
skb_pull(skb, hdr_chop);
if (priv->hs2_enabled &&
mwifiex_discard_gratuitous_arp(priv, skb)) {
dev_dbg(priv->adapter->dev, "Bypassed Gratuitous ARP\n");
dev_kfree_skb_any(skb);
return 0;
}
if (ISSUPP_TDLS_ENABLED(priv->adapter->fw_cap_info) &&
ntohs(rx_pkt_hdr->eth803_hdr.h_proto) == ETH_P_TDLS) {
offset = (u8 *)local_rx_pd + rx_pkt_off;
mwifiex_process_tdls_action_frame(priv, offset, rx_pkt_len);
}
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
struct mwifiex_sta_node *sta_ptr;
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
dev_kfree_skb_any(skb);
return ret;
}
if (rx_pkt_type == PKT_TYPE_MGMT) {
ret = mwifiex_process_mgmt_packet(priv, skb);
if (ret)
dev_err(adapter->dev, "Rx of mgmt packet failed");
dev_kfree_skb_any(skb);
return ret;
}
if ((!IS_11N_ENABLED(priv) &&
!(ISSUPP_TDLS_ENABLED(priv->adapter->fw_cap_info) &&
!(local_rx_pd->flags & MWIFIEX_RXPD_FLAGS_TDLS_PACKET))) ||
!ether_addr_equal_unaligned(priv->curr_addr, rx_pkt_hdr->eth803_hdr.h_dest)) {
mwifiex_process_rx_packet(priv, skb);
return ret;
}
if (mwifiex_queuing_ra_based(priv) ||
(ISSUPP_TDLS_ENABLED(priv->adapter->fw_cap_info) &&
local_rx_pd->flags & MWIFIEX_RXPD_FLAGS_TDLS_PACKET)) {
memcpy(ta, rx_pkt_hdr->eth803_hdr.h_source, ETH_ALEN);
if (local_rx_pd->flags & MWIFIEX_RXPD_FLAGS_TDLS_PACKET &&
local_rx_pd->priority < MAX_NUM_TID) {
sta_ptr = mwifiex_get_sta_entry(priv, ta);
if (sta_ptr)
sta_ptr->rx_seq[local_rx_pd->priority] =
le16_to_cpu(local_rx_pd->seq_num);
mwifiex_auto_tdls_update_peer_signal(priv, ta,
local_rx_pd->snr,
local_rx_pd->nf);
}
} else {
if (rx_pkt_type != PKT_TYPE_BAR)
priv->rx_seq[local_rx_pd->priority] = seq_num;
memcpy(ta, priv->curr_bss_params.bss_descriptor.mac_address,
ETH_ALEN);
}
ret = mwifiex_11n_rx_reorder_pkt(priv, seq_num, local_rx_pd->priority,
ta, (u8) rx_pkt_type, skb);
if (ret || (rx_pkt_type == PKT_TYPE_BAR))
dev_kfree_skb_any(skb);
if (ret)
priv->stats.rx_dropped++;
return ret;
}
