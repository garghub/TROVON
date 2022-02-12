static netdev_tx_t eth_tx(struct sk_buff *skb, struct net_device *dev)
{
int pad = ETH_ZLEN - skb->len;
if (pad > 0) {
int len = skb->len;
if (skb_tailroom(skb) < pad)
if (pskb_expand_head(skb, 0, pad, GFP_ATOMIC)) {
dev->stats.tx_dropped++;
dev_kfree_skb(skb);
return 0;
}
skb_put(skb, pad);
memset(skb->data + len, 0, pad);
}
return dev_to_hdlc(dev)->xmit(skb, dev);
}
static int raw_eth_ioctl(struct net_device *dev, struct ifreq *ifr)
{
raw_hdlc_proto __user *raw_s = ifr->ifr_settings.ifs_ifsu.raw_hdlc;
const size_t size = sizeof(raw_hdlc_proto);
raw_hdlc_proto new_settings;
hdlc_device *hdlc = dev_to_hdlc(dev);
unsigned int old_qlen;
int result;
switch (ifr->ifr_settings.type) {
case IF_GET_PROTO:
if (dev_to_hdlc(dev)->proto != &proto)
return -EINVAL;
ifr->ifr_settings.type = IF_PROTO_HDLC_ETH;
if (ifr->ifr_settings.size < size) {
ifr->ifr_settings.size = size;
return -ENOBUFS;
}
if (copy_to_user(raw_s, hdlc->state, size))
return -EFAULT;
return 0;
case IF_PROTO_HDLC_ETH:
if (!capable(CAP_NET_ADMIN))
return -EPERM;
if (dev->flags & IFF_UP)
return -EBUSY;
if (copy_from_user(&new_settings, raw_s, size))
return -EFAULT;
if (new_settings.encoding == ENCODING_DEFAULT)
new_settings.encoding = ENCODING_NRZ;
if (new_settings.parity == PARITY_DEFAULT)
new_settings.parity = PARITY_CRC16_PR1_CCITT;
result = hdlc->attach(dev, new_settings.encoding,
new_settings.parity);
if (result)
return result;
result = attach_hdlc_protocol(dev, &proto,
sizeof(raw_hdlc_proto));
if (result)
return result;
memcpy(hdlc->state, &new_settings, size);
old_qlen = dev->tx_queue_len;
ether_setup(dev);
dev->tx_queue_len = old_qlen;
eth_hw_addr_random(dev);
call_netdevice_notifiers(NETDEV_POST_TYPE_CHANGE, dev);
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
