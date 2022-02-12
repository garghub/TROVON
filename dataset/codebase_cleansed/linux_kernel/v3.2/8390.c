int ei_open(struct net_device *dev)
{
return __ei_open(dev);
}
int ei_close(struct net_device *dev)
{
return __ei_close(dev);
}
netdev_tx_t ei_start_xmit(struct sk_buff *skb, struct net_device *dev)
{
return __ei_start_xmit(skb, dev);
}
struct net_device_stats *ei_get_stats(struct net_device *dev)
{
return __ei_get_stats(dev);
}
void ei_set_multicast_list(struct net_device *dev)
{
__ei_set_multicast_list(dev);
}
void ei_tx_timeout(struct net_device *dev)
{
__ei_tx_timeout(dev);
}
irqreturn_t ei_interrupt(int irq, void *dev_id)
{
return __ei_interrupt(irq, dev_id);
}
void ei_poll(struct net_device *dev)
{
__ei_poll(dev);
}
struct net_device *__alloc_ei_netdev(int size)
{
struct net_device *dev = ____alloc_ei_netdev(size);
if (dev)
dev->netdev_ops = &ei_netdev_ops;
return dev;
}
void NS8390_init(struct net_device *dev, int startp)
{
__NS8390_init(dev, startp);
}
static int __init ns8390_module_init(void)
{
return 0;
}
static void __exit ns8390_module_exit(void)
{
}
