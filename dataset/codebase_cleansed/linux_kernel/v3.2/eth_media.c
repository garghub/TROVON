static int send_msg(struct sk_buff *buf, struct tipc_bearer *tb_ptr,
struct tipc_media_addr *dest)
{
struct sk_buff *clone;
struct net_device *dev;
int delta;
clone = skb_clone(buf, GFP_ATOMIC);
if (!clone)
return 0;
dev = ((struct eth_bearer *)(tb_ptr->usr_handle))->dev;
delta = dev->hard_header_len - skb_headroom(buf);
if ((delta > 0) &&
pskb_expand_head(clone, SKB_DATA_ALIGN(delta), 0, GFP_ATOMIC)) {
kfree_skb(clone);
return 0;
}
skb_reset_network_header(clone);
clone->dev = dev;
dev_hard_header(clone, dev, ETH_P_TIPC, &dest->dev_addr.eth_addr,
dev->dev_addr, clone->len);
dev_queue_xmit(clone);
return 0;
}
static int recv_msg(struct sk_buff *buf, struct net_device *dev,
struct packet_type *pt, struct net_device *orig_dev)
{
struct eth_bearer *eb_ptr = (struct eth_bearer *)pt->af_packet_priv;
if (!net_eq(dev_net(dev), &init_net)) {
kfree_skb(buf);
return 0;
}
if (likely(eb_ptr->bearer)) {
if (likely(buf->pkt_type <= PACKET_BROADCAST)) {
buf->next = NULL;
tipc_recv_msg(buf, eb_ptr->bearer);
return 0;
}
}
kfree_skb(buf);
return 0;
}
static int enable_bearer(struct tipc_bearer *tb_ptr)
{
struct net_device *dev = NULL;
struct net_device *pdev = NULL;
struct eth_bearer *eb_ptr = &eth_bearers[0];
struct eth_bearer *stop = &eth_bearers[MAX_ETH_BEARERS];
char *driver_name = strchr((const char *)tb_ptr->name, ':') + 1;
int pending_dev = 0;
while (eb_ptr->dev) {
if (!eb_ptr->bearer)
pending_dev++;
if (++eb_ptr == stop)
return pending_dev ? -EAGAIN : -EDQUOT;
}
read_lock(&dev_base_lock);
for_each_netdev(&init_net, pdev) {
if (!strncmp(pdev->name, driver_name, IFNAMSIZ)) {
dev = pdev;
dev_hold(dev);
break;
}
}
read_unlock(&dev_base_lock);
if (!dev)
return -ENODEV;
eb_ptr->dev = dev;
eb_ptr->tipc_packet_type.type = htons(ETH_P_TIPC);
eb_ptr->tipc_packet_type.dev = dev;
eb_ptr->tipc_packet_type.func = recv_msg;
eb_ptr->tipc_packet_type.af_packet_priv = eb_ptr;
INIT_LIST_HEAD(&(eb_ptr->tipc_packet_type.list));
dev_add_pack(&eb_ptr->tipc_packet_type);
eb_ptr->bearer = tb_ptr;
tb_ptr->usr_handle = (void *)eb_ptr;
tb_ptr->mtu = dev->mtu;
tb_ptr->blocked = 0;
tb_ptr->addr.type = htonl(TIPC_MEDIA_TYPE_ETH);
memcpy(&tb_ptr->addr.dev_addr, dev->dev_addr, ETH_ALEN);
return 0;
}
static void disable_bearer(struct tipc_bearer *tb_ptr)
{
((struct eth_bearer *)tb_ptr->usr_handle)->bearer = NULL;
}
static int recv_notification(struct notifier_block *nb, unsigned long evt,
void *dv)
{
struct net_device *dev = (struct net_device *)dv;
struct eth_bearer *eb_ptr = &eth_bearers[0];
struct eth_bearer *stop = &eth_bearers[MAX_ETH_BEARERS];
if (!net_eq(dev_net(dev), &init_net))
return NOTIFY_DONE;
while ((eb_ptr->dev != dev)) {
if (++eb_ptr == stop)
return NOTIFY_DONE;
}
if (!eb_ptr->bearer)
return NOTIFY_DONE;
eb_ptr->bearer->mtu = dev->mtu;
switch (evt) {
case NETDEV_CHANGE:
if (netif_carrier_ok(dev))
tipc_continue(eb_ptr->bearer);
else
tipc_block_bearer(eb_ptr->bearer->name);
break;
case NETDEV_UP:
tipc_continue(eb_ptr->bearer);
break;
case NETDEV_DOWN:
tipc_block_bearer(eb_ptr->bearer->name);
break;
case NETDEV_CHANGEMTU:
case NETDEV_CHANGEADDR:
tipc_block_bearer(eb_ptr->bearer->name);
tipc_continue(eb_ptr->bearer);
break;
case NETDEV_UNREGISTER:
case NETDEV_CHANGENAME:
tipc_disable_bearer(eb_ptr->bearer->name);
break;
}
return NOTIFY_OK;
}
static char *eth_addr2str(struct tipc_media_addr *a, char *str_buf, int str_size)
{
unchar *addr = (unchar *)&a->dev_addr;
if (str_size < 18)
*str_buf = '\0';
else
sprintf(str_buf, "%pM", addr);
return str_buf;
}
int tipc_eth_media_start(void)
{
struct tipc_media_addr bcast_addr;
int res;
if (eth_started)
return -EINVAL;
bcast_addr.type = htonl(TIPC_MEDIA_TYPE_ETH);
memset(&bcast_addr.dev_addr, 0xff, ETH_ALEN);
memset(eth_bearers, 0, sizeof(eth_bearers));
res = tipc_register_media(TIPC_MEDIA_TYPE_ETH, "eth",
enable_bearer, disable_bearer, send_msg,
eth_addr2str, &bcast_addr, ETH_LINK_PRIORITY,
ETH_LINK_TOLERANCE, ETH_LINK_WINDOW);
if (res)
return res;
notifier.notifier_call = &recv_notification;
notifier.priority = 0;
res = register_netdevice_notifier(&notifier);
if (!res)
eth_started = 1;
return res;
}
void tipc_eth_media_stop(void)
{
int i;
if (!eth_started)
return;
unregister_netdevice_notifier(&notifier);
for (i = 0; i < MAX_ETH_BEARERS ; i++) {
if (eth_bearers[i].bearer) {
eth_bearers[i].bearer->blocked = 1;
eth_bearers[i].bearer = NULL;
}
if (eth_bearers[i].dev) {
dev_remove_pack(&eth_bearers[i].tipc_packet_type);
dev_put(eth_bearers[i].dev);
}
}
memset(&eth_bearers, 0, sizeof(eth_bearers));
eth_started = 0;
}
