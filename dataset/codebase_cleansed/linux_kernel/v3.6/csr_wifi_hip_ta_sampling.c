static enum ta_frame_identity ta_detect_protocol(card_t *card, CsrWifiRouterCtrlProtocolDirection direction,
const bulk_data_desc_t *data,
const u8 *saddr,
const u8 *sta_macaddr)
{
ta_data_t *tad = &card->ta_sampling;
u16 proto;
u16 source_port, dest_port;
CsrWifiMacAddress srcAddress;
u32 snap_hdr, oui_hdr;
if (data->data_length < TA_LLC_HEADER_SIZE)
{
return TA_FRAME_UNKNOWN;
}
snap_hdr = (((u32)data->os_data_ptr[0]) << 24) |
(((u32)data->os_data_ptr[1]) << 16) |
(((u32)data->os_data_ptr[2]) << 8);
if (snap_hdr != snap_802_2)
{
return TA_FRAME_UNKNOWN;
}
if (tad->packet_filter & CSR_WIFI_ROUTER_CTRL_TRAFFIC_PACKET_TYPE_CUSTOM)
{
}
oui_hdr = (((u32)data->os_data_ptr[3]) << 24) |
(((u32)data->os_data_ptr[4]) << 16) |
(((u32)data->os_data_ptr[5]) << 8);
if ((oui_hdr == oui_rfc1042) || (oui_hdr == oui_8021h))
{
proto = (data->os_data_ptr[TA_ETHERNET_TYPE_OFFSET] * 256) +
data->os_data_ptr[TA_ETHERNET_TYPE_OFFSET + 1];
if (proto == TA_PROTO_TYPE_IP)
{
if (data->data_length > TA_IP_TYPE_OFFSET)
{
if (tad->packet_filter & CSR_WIFI_ROUTER_CTRL_TRAFFIC_PACKET_TYPE_CUSTOM)
{
ta_l4stats_t *ta_l4stats = &tad->ta_l4stats;
u8 l4proto = data->os_data_ptr[TA_IP_TYPE_OFFSET];
if (l4proto == TA_IP_TYPE_TCP)
{
if (direction == CSR_WIFI_ROUTER_CTRL_PROTOCOL_DIRECTION_TX)
{
ta_l4stats->txTcpBytesCount += data->data_length;
}
else
{
ta_l4stats->rxTcpBytesCount += data->data_length;
}
}
else if (l4proto == TA_IP_TYPE_UDP)
{
if (direction == CSR_WIFI_ROUTER_CTRL_PROTOCOL_DIRECTION_TX)
{
ta_l4stats->txUdpBytesCount += data->data_length;
}
else
{
ta_l4stats->rxUdpBytesCount += data->data_length;
}
}
}
if (tad->packet_filter & CSR_WIFI_ROUTER_CTRL_TRAFFIC_PACKET_TYPE_DHCP)
{
if (data->os_data_ptr[TA_IP_TYPE_OFFSET] == TA_IP_TYPE_UDP)
{
if (data->data_length > TA_UDP_DEST_PORT_OFFSET)
{
source_port = (data->os_data_ptr[TA_UDP_SOURCE_PORT_OFFSET] * 256) +
data->os_data_ptr[TA_UDP_SOURCE_PORT_OFFSET + 1];
dest_port = (data->os_data_ptr[TA_UDP_DEST_PORT_OFFSET] * 256) +
data->os_data_ptr[TA_UDP_DEST_PORT_OFFSET + 1];
if (((source_port == TA_UDP_PORT_BOOTPC) && (dest_port == TA_UDP_PORT_BOOTPS)) ||
((source_port == TA_UDP_PORT_BOOTPS) && (dest_port == TA_UDP_PORT_BOOTPC)))
{
if (data->data_length > TA_DHCP_MESSAGE_TYPE_OFFSET + 6)
{
UNIFI_MAC_ADDRESS_COPY(srcAddress.a, saddr);
if (direction == CSR_WIFI_ROUTER_CTRL_PROTOCOL_DIRECTION_TX)
{
unifi_ta_indicate_protocol(card->ospriv,
CSR_WIFI_ROUTER_CTRL_TRAFFIC_PACKET_TYPE_DHCP,
direction,
&srcAddress);
return TA_FRAME_ETHERNET_UNINTERESTING;
}
if (UNIFI_MAC_ADDRESS_CMP(data->os_data_ptr + TA_BOOTP_CLIENT_MAC_ADDR_OFFSET, sta_macaddr) == TRUE)
{
if (data->os_data_ptr[TA_DHCP_MESSAGE_TYPE_OFFSET] == TA_DHCP_MESSAGE_TYPE_ACK)
{
unifi_ta_indicate_protocol(card->ospriv,
CSR_WIFI_ROUTER_CTRL_TRAFFIC_PACKET_TYPE_DHCP_ACK,
direction,
&srcAddress);
}
else
{
unifi_ta_indicate_protocol(card->ospriv,
CSR_WIFI_ROUTER_CTRL_TRAFFIC_PACKET_TYPE_DHCP,
direction,
&srcAddress);
}
}
}
}
}
}
}
}
return TA_FRAME_ETHERNET_INTERESTING;
}
if (tad->packet_filter & CSR_WIFI_ROUTER_CTRL_TRAFFIC_PACKET_TYPE_EAPOL)
{
if (TA_PROTO_TYPE_EAP == proto || TA_PROTO_TYPE_WAI == proto)
{
if ((TA_PROTO_TYPE_WAI == proto) || (direction != CSR_WIFI_ROUTER_CTRL_PROTOCOL_DIRECTION_TX) ||
(data->os_data_ptr[TA_EAPOL_TYPE_OFFSET] == TA_EAPOL_TYPE_START))
{
UNIFI_MAC_ADDRESS_COPY(srcAddress.a, saddr);
unifi_ta_indicate_protocol(card->ospriv,
CSR_WIFI_ROUTER_CTRL_TRAFFIC_PACKET_TYPE_EAPOL,
direction, &srcAddress);
}
return TA_FRAME_ETHERNET_UNINTERESTING;
}
}
if (tad->packet_filter & CSR_WIFI_ROUTER_CTRL_TRAFFIC_PACKET_TYPE_ARP)
{
if (proto == TA_PROTO_TYPE_ARP)
{
UNIFI_MAC_ADDRESS_COPY(srcAddress.a, saddr);
unifi_ta_indicate_protocol(card->ospriv,
CSR_WIFI_ROUTER_CTRL_TRAFFIC_PACKET_TYPE_ARP,
direction, &srcAddress);
return TA_FRAME_ETHERNET_UNINTERESTING;
}
}
return TA_FRAME_ETHERNET_INTERESTING;
}
else if (tad->packet_filter & CSR_WIFI_ROUTER_CTRL_TRAFFIC_PACKET_TYPE_AIRONET)
{
if (!memcmp(data->os_data_ptr + 3, aironet_snap, 5))
{
UNIFI_MAC_ADDRESS_COPY(srcAddress.a, saddr);
unifi_ta_indicate_protocol(card->ospriv, CSR_WIFI_ROUTER_CTRL_TRAFFIC_PACKET_TYPE_AIRONET,
direction, &srcAddress);
}
}
return TA_FRAME_ETHERNET_UNINTERESTING;
}
static void tas_reset_data(ta_data_t *tad)
{
s16 i;
for (i = 0; i < (TA_INTERVALS_NUM + 1); i++)
{
tad->stats.intervals[i] = 0;
}
tad->stats.rxFramesNum = 0;
tad->stats.txFramesNum = 0;
tad->stats.rxBytesCount = 0;
tad->stats.txBytesCount = 0;
tad->stats.rxMeanRate = 0;
tad->rx_sum_rate = 0;
tad->ta_l4stats.rxTcpBytesCount = 0;
tad->ta_l4stats.txTcpBytesCount = 0;
tad->ta_l4stats.rxUdpBytesCount = 0;
tad->ta_l4stats.txUdpBytesCount = 0;
}
void unifi_ta_sampling_init(card_t *card)
{
(void)unifi_ta_configure(card, CSR_WIFI_ROUTER_CTRL_TRAFFIC_CONFIG_TYPE_RESET, NULL);
card->ta_sampling.packet_filter = CSR_WIFI_ROUTER_CTRL_TRAFFIC_PACKET_TYPE_NONE;
card->ta_sampling.traffic_type = CSR_WIFI_ROUTER_CTRL_TRAFFIC_TYPE_OCCASIONAL;
}
void unifi_ta_sample(card_t *card,
CsrWifiRouterCtrlProtocolDirection direction,
const bulk_data_desc_t *data,
const u8 *saddr,
const u8 *sta_macaddr,
u32 timestamp,
u16 rate)
{
ta_data_t *tad = &card->ta_sampling;
enum ta_frame_identity identity;
u32 time_delta;
if (tad->packet_filter != CSR_WIFI_ROUTER_CTRL_TRAFFIC_PACKET_TYPE_NONE)
{
identity = ta_detect_protocol(card, direction, data, saddr, sta_macaddr);
}
else
{
identity = TA_FRAME_ETHERNET_INTERESTING;
}
if (direction == CSR_WIFI_ROUTER_CTRL_PROTOCOL_DIRECTION_RX)
{
tad->stats.rxFramesNum++;
tad->stats.rxBytesCount += data->data_length;
tad->rx_sum_rate += rate;
}
else
{
if (identity == TA_FRAME_ETHERNET_INTERESTING)
{
if (tad->stats.txFramesNum < TA_MAX_INTERVALS_IN_C1)
{
u32 interval;
u32 index_in_intervals;
interval = timestamp - tad->tx_last_ts;
tad->tx_last_ts = timestamp;
index_in_intervals = (interval + TA_INTERVALS_STEP / 2 - 1) / TA_INTERVALS_STEP;
if (index_in_intervals <= TA_INTERVALS_NUM)
{
unifi_trace(card->ospriv, UDBG5,
"unifi_ta_sample: TX interval=%d index=%d\n",
interval, index_in_intervals);
tad->stats.intervals[index_in_intervals]++;
}
}
}
tad->stats.txFramesNum++;
tad->stats.txBytesCount += data->data_length;
}
time_delta = timestamp - tad->last_indication_time;
if (time_delta >= 1000)
{
u32 temp_rxFramesNum;
temp_rxFramesNum = tad->stats.rxFramesNum;
if (temp_rxFramesNum)
{
tad->stats.rxMeanRate = tad->rx_sum_rate / temp_rxFramesNum;
}
unifi_trace(card->ospriv, UDBG5,
"unifi_ta_sample: RX fr=%lu, r=%u, sum=%lu, av=%lu\n",
tad->stats.rxFramesNum, rate,
tad->rx_sum_rate, tad->stats.rxMeanRate);
if (tad->packet_filter & CSR_WIFI_ROUTER_CTRL_TRAFFIC_PACKET_TYPE_CUSTOM)
{
u32 rxTcpThroughput = tad->ta_l4stats.rxTcpBytesCount / time_delta;
u32 txTcpThroughput = tad->ta_l4stats.txTcpBytesCount / time_delta;
u32 rxUdpThroughput = tad->ta_l4stats.rxUdpBytesCount / time_delta;
u32 txUdpThroughput = tad->ta_l4stats.txUdpBytesCount / time_delta;
unifi_ta_indicate_l4stats(card->ospriv,
rxTcpThroughput,
txTcpThroughput,
rxUdpThroughput,
txUdpThroughput
);
}
unifi_ta_indicate_sampling(card->ospriv, &tad->stats);
tas_reset_data(tad);
tad->last_indication_time = timestamp;
}
}
CsrResult unifi_ta_configure(card_t *card,
CsrWifiRouterCtrlTrafficConfigType config_type,
const CsrWifiRouterCtrlTrafficConfig *config)
{
ta_data_t *tad = &card->ta_sampling;
if (config_type == CSR_WIFI_ROUTER_CTRL_TRAFFIC_CONFIG_TYPE_RESET)
{
tas_reset_data(tad);
tad->tx_last_ts = 0;
tad->last_indication_time = 0;
return CSR_RESULT_SUCCESS;
}
if (config_type == CSR_WIFI_ROUTER_CTRL_TRAFFIC_CONFIG_TYPE_FILTER)
{
tad->packet_filter = config->packetFilter;
if (tad->packet_filter & CSR_WIFI_ROUTER_CTRL_TRAFFIC_PACKET_TYPE_CUSTOM)
{
tad->custom_filter = config->customFilter;
}
return CSR_RESULT_SUCCESS;
}
return CSR_RESULT_SUCCESS;
}
void unifi_ta_classification(card_t *card,
CsrWifiRouterCtrlTrafficType traffic_type,
u16 period)
{
unifi_trace(card->ospriv, UDBG3,
"Changed current ta classification to: %d\n", traffic_type);
card->ta_sampling.traffic_type = traffic_type;
}
