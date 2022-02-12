static void x25_connect_disconnect(struct net_device *dev, int reason, int code)
{
struct sk_buff *skb;
unsigned char *ptr;
if ((skb = dev_alloc_skb(1)) == NULL) {
netdev_err(dev, "out of memory\n");
return;
}
ptr = skb_put(skb, 1);
*ptr = code;
skb->protocol = x25_type_trans(skb, dev);
netif_rx(skb);
}
static void x25_connected(struct net_device *dev, int reason)
{
x25_connect_disconnect(dev, reason, X25_IFACE_CONNECT);
}
static void x25_disconnected(struct net_device *dev, int reason)
{
x25_connect_disconnect(dev, reason, X25_IFACE_DISCONNECT);
}
static int x25_data_indication(struct net_device *dev, struct sk_buff *skb)
{
unsigned char *ptr;
skb_push(skb, 1);
if (skb_cow(skb, 1))
return NET_RX_DROP;
ptr = skb->data;
*ptr = X25_IFACE_DATA;
skb->protocol = x25_type_trans(skb, dev);
return netif_rx(skb);
}
static void x25_data_transmit(struct net_device *dev, struct sk_buff *skb)
{
hdlc_device *hdlc = dev_to_hdlc(dev);
hdlc->xmit(skb, dev);
}
static netdev_tx_t x25_xmit(struct sk_buff *skb, struct net_device *dev)
{
int result;
switch (skb->data[0]) {
case X25_IFACE_DATA:
skb_pull(skb, 1);
if ((result = lapb_data_request(dev, skb)) != LAPB_OK)
dev_kfree_skb(skb);
return NETDEV_TX_OK;
case X25_IFACE_CONNECT:
if ((result = lapb_connect_request(dev))!= LAPB_OK) {
if (result == LAPB_CONNECTED)
x25_connected(dev, 0);
else
netdev_err(dev, "LAPB connect request failed, error code = %i\n",
result);
}
break;
case X25_IFACE_DISCONNECT:
if ((result = lapb_disconnect_request(dev)) != LAPB_OK) {
if (result == LAPB_NOTCONNECTED)
x25_disconnected(dev, 0);
else
netdev_err(dev, "LAPB disconnect request failed, error code = %i\n",
result);
}
break;
default:
break;
}
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
static int x25_open(struct net_device *dev)
{
struct lapb_register_struct cb;
int result;
cb.connect_confirmation = x25_connected;
cb.connect_indication = x25_connected;
cb.disconnect_confirmation = x25_disconnected;
cb.disconnect_indication = x25_disconnected;
cb.data_indication = x25_data_indication;
cb.data_transmit = x25_data_transmit;
result = lapb_register(dev, &cb);
if (result != LAPB_OK)
return result;
return 0;
}
static void x25_close(struct net_device *dev)
{
lapb_unregister(dev);
}
static int x25_rx(struct sk_buff *skb)
{
struct net_device *dev = skb->dev;
if ((skb = skb_share_check(skb, GFP_ATOMIC)) == NULL) {
dev->stats.rx_dropped++;
return NET_RX_DROP;
}
if (lapb_data_received(dev, skb) == LAPB_OK)
return NET_RX_SUCCESS;
dev->stats.rx_errors++;
dev_kfree_skb_any(skb);
return NET_RX_DROP;
}
static int x25_ioctl(struct net_device *dev, struct ifreq *ifr)
{
hdlc_device *hdlc = dev_to_hdlc(dev);
int result;
switch (ifr->ifr_settings.type) {
case IF_GET_PROTO:
if (dev_to_hdlc(dev)->proto != &proto)
return -EINVAL;
ifr->ifr_settings.type = IF_PROTO_X25;
return 0;
case IF_PROTO_X25:
if (!capable(CAP_NET_ADMIN))
return -EPERM;
if (dev->flags & IFF_UP)
return -EBUSY;
result=hdlc->attach(dev, ENCODING_NRZ,PARITY_CRC16_PR1_CCITT);
if (result)
return result;
if ((result = attach_hdlc_protocol(dev, &proto, 0)))
return result;
dev->type = ARPHRD_X25;
netif_dormant_off(dev);
return 0;
}
return -EINVAL;
}
static int __init mod_init(void)
{
register_hdlc_protocol(&proto);
return 0;
}
static void __exit mod_exit(void)
{
unregister_hdlc_protocol(&proto);
}
