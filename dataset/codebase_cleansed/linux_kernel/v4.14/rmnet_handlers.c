static void rmnet_set_skb_proto(struct sk_buff *skb)
{
switch (skb->data[0] & 0xF0) {
case RMNET_IP_VERSION_4:
skb->protocol = htons(ETH_P_IP);
break;
case RMNET_IP_VERSION_6:
skb->protocol = htons(ETH_P_IPV6);
break;
default:
skb->protocol = htons(ETH_P_MAP);
break;
}
}
static rx_handler_result_t
rmnet_bridge_handler(struct sk_buff *skb, struct rmnet_endpoint *ep)
{
if (!ep->egress_dev)
kfree_skb(skb);
else
rmnet_egress_handler(skb, ep);
return RX_HANDLER_CONSUMED;
}
static rx_handler_result_t
rmnet_deliver_skb(struct sk_buff *skb, struct rmnet_endpoint *ep)
{
switch (ep->rmnet_mode) {
case RMNET_EPMODE_NONE:
return RX_HANDLER_PASS;
case RMNET_EPMODE_BRIDGE:
return rmnet_bridge_handler(skb, ep);
case RMNET_EPMODE_VND:
skb_reset_transport_header(skb);
skb_reset_network_header(skb);
rmnet_vnd_rx_fixup(skb, skb->dev);
skb->pkt_type = PACKET_HOST;
skb_set_mac_header(skb, 0);
netif_receive_skb(skb);
return RX_HANDLER_CONSUMED;
default:
kfree_skb(skb);
return RX_HANDLER_CONSUMED;
}
}
static rx_handler_result_t
rmnet_ingress_deliver_packet(struct sk_buff *skb,
struct rmnet_port *port)
{
if (!port) {
kfree_skb(skb);
return RX_HANDLER_CONSUMED;
}
skb->dev = port->local_ep.egress_dev;
return rmnet_deliver_skb(skb, &port->local_ep);
}
static rx_handler_result_t
__rmnet_map_ingress_handler(struct sk_buff *skb,
struct rmnet_port *port)
{
struct rmnet_endpoint *ep;
u8 mux_id;
u16 len;
if (RMNET_MAP_GET_CD_BIT(skb)) {
if (port->ingress_data_format
& RMNET_INGRESS_FORMAT_MAP_COMMANDS)
return rmnet_map_command(skb, port);
kfree_skb(skb);
return RX_HANDLER_CONSUMED;
}
mux_id = RMNET_MAP_GET_MUX_ID(skb);
len = RMNET_MAP_GET_LENGTH(skb) - RMNET_MAP_GET_PAD(skb);
if (mux_id >= RMNET_MAX_LOGICAL_EP) {
kfree_skb(skb);
return RX_HANDLER_CONSUMED;
}
ep = &port->muxed_ep[mux_id];
if (port->ingress_data_format & RMNET_INGRESS_FORMAT_DEMUXING)
skb->dev = ep->egress_dev;
skb_pull(skb, sizeof(struct rmnet_map_header));
skb_trim(skb, len);
rmnet_set_skb_proto(skb);
return rmnet_deliver_skb(skb, ep);
}
static rx_handler_result_t
rmnet_map_ingress_handler(struct sk_buff *skb,
struct rmnet_port *port)
{
struct sk_buff *skbn;
int rc;
if (port->ingress_data_format & RMNET_INGRESS_FORMAT_DEAGGREGATION) {
while ((skbn = rmnet_map_deaggregate(skb)) != NULL)
__rmnet_map_ingress_handler(skbn, port);
consume_skb(skb);
rc = RX_HANDLER_CONSUMED;
} else {
rc = __rmnet_map_ingress_handler(skb, port);
}
return rc;
}
static int rmnet_map_egress_handler(struct sk_buff *skb,
struct rmnet_port *port,
struct rmnet_endpoint *ep,
struct net_device *orig_dev)
{
int required_headroom, additional_header_len;
struct rmnet_map_header *map_header;
additional_header_len = 0;
required_headroom = sizeof(struct rmnet_map_header);
if (skb_headroom(skb) < required_headroom) {
if (pskb_expand_head(skb, required_headroom, 0, GFP_KERNEL))
return RMNET_MAP_CONSUMED;
}
map_header = rmnet_map_add_map_header(skb, additional_header_len, 0);
if (!map_header)
return RMNET_MAP_CONSUMED;
if (port->egress_data_format & RMNET_EGRESS_FORMAT_MUXING) {
if (ep->mux_id == 0xff)
map_header->mux_id = 0;
else
map_header->mux_id = ep->mux_id;
}
skb->protocol = htons(ETH_P_MAP);
return RMNET_MAP_SUCCESS;
}
rx_handler_result_t rmnet_rx_handler(struct sk_buff **pskb)
{
struct rmnet_port *port;
struct sk_buff *skb = *pskb;
struct net_device *dev;
int rc;
if (!skb)
return RX_HANDLER_CONSUMED;
dev = skb->dev;
port = rmnet_get_port(dev);
if (port->ingress_data_format & RMNET_INGRESS_FORMAT_MAP) {
rc = rmnet_map_ingress_handler(skb, port);
} else {
switch (ntohs(skb->protocol)) {
case ETH_P_MAP:
if (port->local_ep.rmnet_mode ==
RMNET_EPMODE_BRIDGE) {
rc = rmnet_ingress_deliver_packet(skb, port);
} else {
kfree_skb(skb);
rc = RX_HANDLER_CONSUMED;
}
break;
case ETH_P_IP:
case ETH_P_IPV6:
rc = rmnet_ingress_deliver_packet(skb, port);
break;
default:
rc = RX_HANDLER_PASS;
}
}
return rc;
}
void rmnet_egress_handler(struct sk_buff *skb,
struct rmnet_endpoint *ep)
{
struct net_device *orig_dev;
struct rmnet_port *port;
orig_dev = skb->dev;
skb->dev = ep->egress_dev;
port = rmnet_get_port(skb->dev);
if (!port) {
kfree_skb(skb);
return;
}
if (port->egress_data_format & RMNET_EGRESS_FORMAT_MAP) {
switch (rmnet_map_egress_handler(skb, port, ep, orig_dev)) {
case RMNET_MAP_CONSUMED:
return;
case RMNET_MAP_SUCCESS:
break;
default:
kfree_skb(skb);
return;
}
}
if (ep->rmnet_mode == RMNET_EPMODE_VND)
rmnet_vnd_tx_fixup(skb, orig_dev);
dev_queue_xmit(skb);
}
