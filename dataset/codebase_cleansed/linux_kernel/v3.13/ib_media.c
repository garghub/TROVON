static void ib_media_addr_set(const struct tipc_bearer *tb_ptr,
struct tipc_media_addr *a, char *mac)
{
BUILD_BUG_ON(sizeof(a->value) < INFINIBAND_ALEN);
memcpy(a->value, mac, INFINIBAND_ALEN);
a->media_id = TIPC_MEDIA_TYPE_IB;
a->broadcast = !memcmp(mac, tb_ptr->bcast_addr.value, INFINIBAND_ALEN);
}
static int send_msg(struct sk_buff *buf, struct tipc_bearer *tb_ptr,
struct tipc_media_addr *dest)
{
struct sk_buff *clone;
struct net_device *dev;
int delta;
clone = skb_clone(buf, GFP_ATOMIC);
if (!clone)
return 0;
dev = ((struct ib_media *)(tb_ptr->usr_handle))->dev;
delta = dev->hard_header_len - skb_headroom(buf);
if ((delta > 0) &&
pskb_expand_head(clone, SKB_DATA_ALIGN(delta), 0, GFP_ATOMIC)) {
kfree_skb(clone);
return 0;
}
skb_reset_network_header(clone);
clone->dev = dev;
clone->protocol = htons(ETH_P_TIPC);
dev_hard_header(clone, dev, ETH_P_TIPC, dest->value,
dev->dev_addr, clone->len);
dev_queue_xmit(clone);
return 0;
}
static int recv_msg(struct sk_buff *buf, struct net_device *dev,
struct packet_type *pt, struct net_device *orig_dev)
{
struct ib_media *ib_ptr = (struct ib_media *)pt->af_packet_priv;
if (!net_eq(dev_net(dev), &init_net)) {
kfree_skb(buf);
return NET_RX_DROP;
}
if (likely(ib_ptr->bearer)) {
if (likely(buf->pkt_type <= PACKET_BROADCAST)) {
buf->next = NULL;
tipc_recv_msg(buf, ib_ptr->bearer);
return NET_RX_SUCCESS;
}
}
kfree_skb(buf);
return NET_RX_DROP;
}
static void setup_media(struct work_struct *work)
{
struct ib_media *ib_ptr =
container_of(work, struct ib_media, setup);
dev_add_pack(&ib_ptr->tipc_packet_type);
}
static int enable_media(struct tipc_bearer *tb_ptr)
{
struct net_device *dev;
struct ib_media *ib_ptr = &ib_media_array[0];
struct ib_media *stop = &ib_media_array[MAX_IB_MEDIA];
char *driver_name = strchr((const char *)tb_ptr->name, ':') + 1;
int pending_dev = 0;
while (ib_ptr->dev) {
if (!ib_ptr->bearer)
pending_dev++;
if (++ib_ptr == stop)
return pending_dev ? -EAGAIN : -EDQUOT;
}
dev = dev_get_by_name(&init_net, driver_name);
if (!dev)
return -ENODEV;
ib_ptr->dev = dev;
ib_ptr->tipc_packet_type.type = htons(ETH_P_TIPC);
ib_ptr->tipc_packet_type.dev = dev;
ib_ptr->tipc_packet_type.func = recv_msg;
ib_ptr->tipc_packet_type.af_packet_priv = ib_ptr;
INIT_LIST_HEAD(&(ib_ptr->tipc_packet_type.list));
INIT_WORK(&ib_ptr->setup, setup_media);
schedule_work(&ib_ptr->setup);
ib_ptr->bearer = tb_ptr;
tb_ptr->usr_handle = (void *)ib_ptr;
memset(tb_ptr->bcast_addr.value, 0, sizeof(tb_ptr->bcast_addr.value));
memcpy(tb_ptr->bcast_addr.value, dev->broadcast, INFINIBAND_ALEN);
tb_ptr->bcast_addr.media_id = TIPC_MEDIA_TYPE_IB;
tb_ptr->bcast_addr.broadcast = 1;
tb_ptr->mtu = dev->mtu;
tb_ptr->blocked = 0;
ib_media_addr_set(tb_ptr, &tb_ptr->addr, (char *)dev->dev_addr);
return 0;
}
static void cleanup_bearer(struct work_struct *work)
{
struct ib_media *ib_ptr =
container_of(work, struct ib_media, cleanup);
dev_remove_pack(&ib_ptr->tipc_packet_type);
dev_put(ib_ptr->dev);
ib_ptr->dev = NULL;
}
static void disable_media(struct tipc_bearer *tb_ptr)
{
struct ib_media *ib_ptr = (struct ib_media *)tb_ptr->usr_handle;
ib_ptr->bearer = NULL;
INIT_WORK(&ib_ptr->cleanup, cleanup_bearer);
schedule_work(&ib_ptr->cleanup);
}
static int recv_notification(struct notifier_block *nb, unsigned long evt,
void *ptr)
{
struct net_device *dev = netdev_notifier_info_to_dev(ptr);
struct ib_media *ib_ptr = &ib_media_array[0];
struct ib_media *stop = &ib_media_array[MAX_IB_MEDIA];
if (!net_eq(dev_net(dev), &init_net))
return NOTIFY_DONE;
while ((ib_ptr->dev != dev)) {
if (++ib_ptr == stop)
return NOTIFY_DONE;
}
if (!ib_ptr->bearer)
return NOTIFY_DONE;
ib_ptr->bearer->mtu = dev->mtu;
switch (evt) {
case NETDEV_CHANGE:
if (netif_carrier_ok(dev))
tipc_continue(ib_ptr->bearer);
else
tipc_block_bearer(ib_ptr->bearer);
break;
case NETDEV_UP:
tipc_continue(ib_ptr->bearer);
break;
case NETDEV_DOWN:
tipc_block_bearer(ib_ptr->bearer);
break;
case NETDEV_CHANGEMTU:
case NETDEV_CHANGEADDR:
tipc_block_bearer(ib_ptr->bearer);
tipc_continue(ib_ptr->bearer);
break;
case NETDEV_UNREGISTER:
case NETDEV_CHANGENAME:
tipc_disable_bearer(ib_ptr->bearer->name);
break;
}
return NOTIFY_OK;
}
static int ib_addr2str(struct tipc_media_addr *a, char *str_buf, int str_size)
{
if (str_size < 60)
return 1;
sprintf(str_buf, "%20phC", a->value);
return 0;
}
static int ib_addr2msg(struct tipc_media_addr *a, char *msg_area)
{
memset(msg_area, 0, TIPC_MEDIA_ADDR_SIZE);
msg_area[TIPC_MEDIA_TYPE_OFFSET] = TIPC_MEDIA_TYPE_IB;
memcpy(msg_area, a->value, INFINIBAND_ALEN);
return 0;
}
static int ib_msg2addr(const struct tipc_bearer *tb_ptr,
struct tipc_media_addr *a, char *msg_area)
{
ib_media_addr_set(tb_ptr, a, msg_area);
return 0;
}
int tipc_ib_media_start(void)
{
int res;
if (ib_started)
return -EINVAL;
res = tipc_register_media(&ib_media_info);
if (res)
return res;
res = register_netdevice_notifier(&notifier);
if (!res)
ib_started = 1;
return res;
}
void tipc_ib_media_stop(void)
{
if (!ib_started)
return;
flush_scheduled_work();
unregister_netdevice_notifier(&notifier);
ib_started = 0;
}
