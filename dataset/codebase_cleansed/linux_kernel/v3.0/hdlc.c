int hdlc_change_mtu(struct net_device *dev, int new_mtu)
{
if ((new_mtu < 68) || (new_mtu > HDLC_MAX_MTU))
return -EINVAL;
dev->mtu = new_mtu;
return 0;
}
static int hdlc_rcv(struct sk_buff *skb, struct net_device *dev,
struct packet_type *p, struct net_device *orig_dev)
{
struct hdlc_device *hdlc = dev_to_hdlc(dev);
if (!net_eq(dev_net(dev), &init_net)) {
kfree_skb(skb);
return 0;
}
BUG_ON(!hdlc->proto->netif_rx);
return hdlc->proto->netif_rx(skb);
}
netdev_tx_t hdlc_start_xmit(struct sk_buff *skb, struct net_device *dev)
{
hdlc_device *hdlc = dev_to_hdlc(dev);
if (hdlc->proto->xmit)
return hdlc->proto->xmit(skb, dev);
return hdlc->xmit(skb, dev);
}
static inline void hdlc_proto_start(struct net_device *dev)
{
hdlc_device *hdlc = dev_to_hdlc(dev);
if (hdlc->proto->start)
hdlc->proto->start(dev);
}
static inline void hdlc_proto_stop(struct net_device *dev)
{
hdlc_device *hdlc = dev_to_hdlc(dev);
if (hdlc->proto->stop)
hdlc->proto->stop(dev);
}
static int hdlc_device_event(struct notifier_block *this, unsigned long event,
void *ptr)
{
struct net_device *dev = ptr;
hdlc_device *hdlc;
unsigned long flags;
int on;
if (!net_eq(dev_net(dev), &init_net))
return NOTIFY_DONE;
if (!(dev->priv_flags & IFF_WAN_HDLC))
return NOTIFY_DONE;
if (event != NETDEV_CHANGE)
return NOTIFY_DONE;
on = netif_carrier_ok(dev);
#ifdef DEBUG_LINK
printk(KERN_DEBUG "%s: hdlc_device_event NETDEV_CHANGE, carrier %i\n",
dev->name, on);
#endif
hdlc = dev_to_hdlc(dev);
spin_lock_irqsave(&hdlc->state_lock, flags);
if (hdlc->carrier == on)
goto carrier_exit;
hdlc->carrier = on;
if (!hdlc->open)
goto carrier_exit;
if (hdlc->carrier) {
printk(KERN_INFO "%s: Carrier detected\n", dev->name);
hdlc_proto_start(dev);
} else {
printk(KERN_INFO "%s: Carrier lost\n", dev->name);
hdlc_proto_stop(dev);
}
carrier_exit:
spin_unlock_irqrestore(&hdlc->state_lock, flags);
return NOTIFY_DONE;
}
int hdlc_open(struct net_device *dev)
{
hdlc_device *hdlc = dev_to_hdlc(dev);
#ifdef DEBUG_LINK
printk(KERN_DEBUG "%s: hdlc_open() carrier %i open %i\n", dev->name,
hdlc->carrier, hdlc->open);
#endif
if (hdlc->proto == NULL)
return -ENOSYS;
if (hdlc->proto->open) {
int result = hdlc->proto->open(dev);
if (result)
return result;
}
spin_lock_irq(&hdlc->state_lock);
if (hdlc->carrier) {
printk(KERN_INFO "%s: Carrier detected\n", dev->name);
hdlc_proto_start(dev);
} else
printk(KERN_INFO "%s: No carrier\n", dev->name);
hdlc->open = 1;
spin_unlock_irq(&hdlc->state_lock);
return 0;
}
void hdlc_close(struct net_device *dev)
{
hdlc_device *hdlc = dev_to_hdlc(dev);
#ifdef DEBUG_LINK
printk(KERN_DEBUG "%s: hdlc_close() carrier %i open %i\n", dev->name,
hdlc->carrier, hdlc->open);
#endif
spin_lock_irq(&hdlc->state_lock);
hdlc->open = 0;
if (hdlc->carrier)
hdlc_proto_stop(dev);
spin_unlock_irq(&hdlc->state_lock);
if (hdlc->proto->close)
hdlc->proto->close(dev);
}
int hdlc_ioctl(struct net_device *dev, struct ifreq *ifr, int cmd)
{
struct hdlc_proto *proto = first_proto;
int result;
if (cmd != SIOCWANDEV)
return -EINVAL;
if (dev_to_hdlc(dev)->proto) {
result = dev_to_hdlc(dev)->proto->ioctl(dev, ifr);
if (result != -EINVAL)
return result;
}
while (proto) {
if ((result = proto->ioctl(dev, ifr)) != -EINVAL)
return result;
proto = proto->next;
}
return -EINVAL;
}
static void hdlc_setup_dev(struct net_device *dev)
{
dev->flags = IFF_POINTOPOINT | IFF_NOARP;
dev->priv_flags = IFF_WAN_HDLC;
dev->mtu = HDLC_MAX_MTU;
dev->type = ARPHRD_RAWHDLC;
dev->hard_header_len = 16;
dev->addr_len = 0;
dev->header_ops = &hdlc_null_ops;
}
static void hdlc_setup(struct net_device *dev)
{
hdlc_device *hdlc = dev_to_hdlc(dev);
hdlc_setup_dev(dev);
hdlc->carrier = 1;
hdlc->open = 0;
spin_lock_init(&hdlc->state_lock);
}
struct net_device *alloc_hdlcdev(void *priv)
{
struct net_device *dev;
dev = alloc_netdev(sizeof(struct hdlc_device), "hdlc%d", hdlc_setup);
if (dev)
dev_to_hdlc(dev)->priv = priv;
return dev;
}
void unregister_hdlc_device(struct net_device *dev)
{
rtnl_lock();
unregister_netdevice(dev);
detach_hdlc_protocol(dev);
rtnl_unlock();
}
int attach_hdlc_protocol(struct net_device *dev, struct hdlc_proto *proto,
size_t size)
{
detach_hdlc_protocol(dev);
if (!try_module_get(proto->module))
return -ENOSYS;
if (size)
if ((dev_to_hdlc(dev)->state = kmalloc(size,
GFP_KERNEL)) == NULL) {
printk(KERN_WARNING "Memory squeeze on"
" hdlc_proto_attach()\n");
module_put(proto->module);
return -ENOBUFS;
}
dev_to_hdlc(dev)->proto = proto;
return 0;
}
void detach_hdlc_protocol(struct net_device *dev)
{
hdlc_device *hdlc = dev_to_hdlc(dev);
if (hdlc->proto) {
if (hdlc->proto->detach)
hdlc->proto->detach(dev);
module_put(hdlc->proto->module);
hdlc->proto = NULL;
}
kfree(hdlc->state);
hdlc->state = NULL;
hdlc_setup_dev(dev);
}
void register_hdlc_protocol(struct hdlc_proto *proto)
{
rtnl_lock();
proto->next = first_proto;
first_proto = proto;
rtnl_unlock();
}
void unregister_hdlc_protocol(struct hdlc_proto *proto)
{
struct hdlc_proto **p;
rtnl_lock();
p = &first_proto;
while (*p != proto) {
BUG_ON(!*p);
p = &((*p)->next);
}
*p = proto->next;
rtnl_unlock();
}
static int __init hdlc_module_init(void)
{
int result;
printk(KERN_INFO "%s\n", version);
if ((result = register_netdevice_notifier(&hdlc_notifier)) != 0)
return result;
dev_add_pack(&hdlc_packet_type);
return 0;
}
static void __exit hdlc_module_exit(void)
{
dev_remove_pack(&hdlc_packet_type);
unregister_netdevice_notifier(&hdlc_notifier);
}
