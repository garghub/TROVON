static inline struct slvl_device* dev_to_chan(struct net_device *dev)
{
return (struct slvl_device *)dev_to_hdlc(dev)->priv;
}
static void sealevel_input(struct z8530_channel *c, struct sk_buff *skb)
{
skb_trim(skb, skb->len - 2);
skb->protocol = hdlc_type_trans(skb, c->netdevice);
skb_reset_mac_header(skb);
skb->dev = c->netdevice;
netif_rx(skb);
}
static int sealevel_open(struct net_device *d)
{
struct slvl_device *slvl = dev_to_chan(d);
int err = -1;
int unit = slvl->channel;
switch (unit) {
case 0:
err = z8530_sync_dma_open(d, slvl->chan);
break;
case 1:
err = z8530_sync_open(d, slvl->chan);
break;
}
if (err)
return err;
err = hdlc_open(d);
if (err) {
switch (unit) {
case 0:
z8530_sync_dma_close(d, slvl->chan);
break;
case 1:
z8530_sync_close(d, slvl->chan);
break;
}
return err;
}
slvl->chan->rx_function = sealevel_input;
netif_start_queue(d);
return 0;
}
static int sealevel_close(struct net_device *d)
{
struct slvl_device *slvl = dev_to_chan(d);
int unit = slvl->channel;
slvl->chan->rx_function = z8530_null_rx;
hdlc_close(d);
netif_stop_queue(d);
switch (unit) {
case 0:
z8530_sync_dma_close(d, slvl->chan);
break;
case 1:
z8530_sync_close(d, slvl->chan);
break;
}
return 0;
}
static int sealevel_ioctl(struct net_device *d, struct ifreq *ifr, int cmd)
{
return hdlc_ioctl(d, ifr, cmd);
}
static netdev_tx_t sealevel_queue_xmit(struct sk_buff *skb,
struct net_device *d)
{
return z8530_queue_xmit(dev_to_chan(d)->chan, skb);
}
static int sealevel_attach(struct net_device *dev, unsigned short encoding,
unsigned short parity)
{
if (encoding == ENCODING_NRZ && parity == PARITY_CRC16_PR1_CCITT)
return 0;
return -EINVAL;
}
static int slvl_setup(struct slvl_device *sv, int iobase, int irq)
{
struct net_device *dev = alloc_hdlcdev(sv);
if (!dev)
return -1;
dev_to_hdlc(dev)->attach = sealevel_attach;
dev_to_hdlc(dev)->xmit = sealevel_queue_xmit;
dev->netdev_ops = &sealevel_ops;
dev->base_addr = iobase;
dev->irq = irq;
if (register_hdlc_device(dev)) {
printk(KERN_ERR "sealevel: unable to register HDLC device\n");
free_netdev(dev);
return -1;
}
sv->chan->netdevice = dev;
return 0;
}
void __exit slvl_shutdown(struct slvl_board *b)
{
int u;
z8530_shutdown(&b->board);
for (u = 0; u < 2; u++) {
struct net_device *d = b->dev[u].chan->netdevice;
unregister_hdlc_device(d);
free_netdev(d);
}
free_irq(b->board.irq, &b->board);
free_dma(b->board.chanA.rxdma);
free_dma(b->board.chanA.txdma);
outb(0, b->iobase);
release_region(b->iobase, 8);
kfree(b);
}
static int __init slvl_init_module(void)
{
slvl_unit = slvl_init(io, irq, txdma, rxdma, slow);
return slvl_unit ? 0 : -ENODEV;
}
static void __exit slvl_cleanup_module(void)
{
if (slvl_unit)
slvl_shutdown(slvl_unit);
}
