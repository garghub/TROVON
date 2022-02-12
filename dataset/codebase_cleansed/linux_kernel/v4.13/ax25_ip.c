static int ax25_hard_header(struct sk_buff *skb, struct net_device *dev,
unsigned short type, const void *daddr,
const void *saddr, unsigned int len)
{
unsigned char *buff;
if (type == ETH_P_AX25)
return 0;
buff = skb_push(skb, AX25_HEADER_LEN);
*buff++ = 0x00;
if (daddr != NULL)
memcpy(buff, daddr, dev->addr_len);
buff[6] &= ~AX25_CBIT;
buff[6] &= ~AX25_EBIT;
buff[6] |= AX25_SSSID_SPARE;
buff += AX25_ADDR_LEN;
if (saddr != NULL)
memcpy(buff, saddr, dev->addr_len);
else
memcpy(buff, dev->dev_addr, dev->addr_len);
buff[6] &= ~AX25_CBIT;
buff[6] |= AX25_EBIT;
buff[6] |= AX25_SSSID_SPARE;
buff += AX25_ADDR_LEN;
*buff++ = AX25_UI;
switch (type) {
case ETH_P_IP:
*buff++ = AX25_P_IP;
break;
case ETH_P_ARP:
*buff++ = AX25_P_ARP;
break;
default:
printk(KERN_ERR "AX.25: ax25_hard_header - wrong protocol type 0x%2.2x\n", type);
*buff++ = 0;
break;
}
if (daddr != NULL)
return AX25_HEADER_LEN;
return -AX25_HEADER_LEN;
}
netdev_tx_t ax25_ip_xmit(struct sk_buff *skb)
{
struct sk_buff *ourskb;
unsigned char *bp = skb->data;
ax25_route *route;
struct net_device *dev = NULL;
ax25_address *src, *dst;
ax25_digi *digipeat = NULL;
ax25_dev *ax25_dev;
ax25_cb *ax25;
char ip_mode = ' ';
dst = (ax25_address *)(bp + 1);
src = (ax25_address *)(bp + 8);
route = ax25_get_route(dst, NULL);
if (route) {
digipeat = route->digipeat;
dev = route->dev;
ip_mode = route->ip_mode;
}
if (dev == NULL)
dev = skb->dev;
if ((ax25_dev = ax25_dev_ax25dev(dev)) == NULL) {
kfree_skb(skb);
goto put;
}
if (bp[16] == AX25_P_IP) {
if (ip_mode == 'V' || (ip_mode == ' ' && ax25_dev->values[AX25_VALUES_IPDEFMODE])) {
ax25_address src_c;
ax25_address dst_c;
if ((ourskb = skb_copy(skb, GFP_ATOMIC)) == NULL) {
kfree_skb(skb);
goto put;
}
if (skb->sk != NULL)
skb_set_owner_w(ourskb, skb->sk);
kfree_skb(skb);
bp = ourskb->data;
dst_c = *(ax25_address *)(bp + 1);
src_c = *(ax25_address *)(bp + 8);
skb_pull(ourskb, AX25_HEADER_LEN - 1);
skb_reset_network_header(ourskb);
ax25=ax25_send_frame(
ourskb,
ax25_dev->values[AX25_VALUES_PACLEN],
&src_c,
&dst_c, digipeat, dev);
if (ax25) {
ax25_cb_put(ax25);
}
goto put;
}
}
bp[7] &= ~AX25_CBIT;
bp[7] &= ~AX25_EBIT;
bp[7] |= AX25_SSSID_SPARE;
bp[14] &= ~AX25_CBIT;
bp[14] |= AX25_EBIT;
bp[14] |= AX25_SSSID_SPARE;
skb_pull(skb, AX25_KISS_HEADER_LEN);
if (digipeat != NULL) {
if ((ourskb = ax25_rt_build_path(skb, src, dst, route->digipeat)) == NULL) {
kfree_skb(skb);
goto put;
}
skb = ourskb;
}
ax25_queue_xmit(skb, dev);
put:
if (route)
ax25_put_route(route);
return NETDEV_TX_OK;
}
static int ax25_hard_header(struct sk_buff *skb, struct net_device *dev,
unsigned short type, const void *daddr,
const void *saddr, unsigned int len)
{
return -AX25_HEADER_LEN;
}
netdev_tx_t ax25_ip_xmit(struct sk_buff *skb)
{
kfree_skb(skb);
return NETDEV_TX_OK;
}
static bool ax25_validate_header(const char *header, unsigned int len)
{
ax25_digi digi;
if (!len)
return false;
if (header[0])
return true;
return ax25_addr_parse(header + 1, len - 1, NULL, NULL, &digi, NULL,
NULL);
}
