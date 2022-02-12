int eip_open(struct net_device *dev)
{
return __ei_open(dev);
}
int eip_close(struct net_device *dev)
{
return __ei_close(dev);
}
netdev_tx_t eip_start_xmit(struct sk_buff *skb, struct net_device *dev)
{
return __ei_start_xmit(skb, dev);
}
struct net_device_stats *eip_get_stats(struct net_device *dev)
{
return __ei_get_stats(dev);
}
void eip_set_multicast_list(struct net_device *dev)
{
__ei_set_multicast_list(dev);
}
void eip_tx_timeout(struct net_device *dev)
{
__ei_tx_timeout(dev);
}
irqreturn_t eip_interrupt(int irq, void *dev_id)
{
return __ei_interrupt(irq, dev_id);
}
void eip_poll(struct net_device *dev)
{
__ei_poll(dev);
}
struct net_device *__alloc_eip_netdev(int size)
{
struct net_device *dev = ____alloc_ei_netdev(size);
if (dev)
dev->netdev_ops = &eip_netdev_ops;
return dev;
}
void NS8390p_init(struct net_device *dev, int startp)
{
__NS8390_init(dev, startp);
}
static int __init NS8390p_init_module(void)
{
return 0;
}
static void __exit NS8390p_cleanup_module(void)
{
}
