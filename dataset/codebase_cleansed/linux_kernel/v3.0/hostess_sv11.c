static inline struct z8530_dev* dev_to_sv(struct net_device *dev)
{
return (struct z8530_dev *)dev_to_hdlc(dev)->priv;
}
static void hostess_input(struct z8530_channel *c, struct sk_buff *skb)
{
skb_trim(skb, skb->len - 2);
skb->protocol = hdlc_type_trans(skb, c->netdevice);
skb_reset_mac_header(skb);
skb->dev = c->netdevice;
netif_rx(skb);
}
static int hostess_open(struct net_device *d)
{
struct z8530_dev *sv11 = dev_to_sv(d);
int err = -1;
switch (dma) {
case 0:
err = z8530_sync_open(d, &sv11->chanA);
break;
case 1:
err = z8530_sync_dma_open(d, &sv11->chanA);
break;
case 2:
err = z8530_sync_txdma_open(d, &sv11->chanA);
break;
}
if (err)
return err;
err = hdlc_open(d);
if (err) {
switch (dma) {
case 0:
z8530_sync_close(d, &sv11->chanA);
break;
case 1:
z8530_sync_dma_close(d, &sv11->chanA);
break;
case 2:
z8530_sync_txdma_close(d, &sv11->chanA);
break;
}
return err;
}
sv11->chanA.rx_function = hostess_input;
netif_start_queue(d);
return 0;
}
static int hostess_close(struct net_device *d)
{
struct z8530_dev *sv11 = dev_to_sv(d);
sv11->chanA.rx_function = z8530_null_rx;
hdlc_close(d);
netif_stop_queue(d);
switch (dma) {
case 0:
z8530_sync_close(d, &sv11->chanA);
break;
case 1:
z8530_sync_dma_close(d, &sv11->chanA);
break;
case 2:
z8530_sync_txdma_close(d, &sv11->chanA);
break;
}
return 0;
}
static int hostess_ioctl(struct net_device *d, struct ifreq *ifr, int cmd)
{
return hdlc_ioctl(d, ifr, cmd);
}
static netdev_tx_t hostess_queue_xmit(struct sk_buff *skb,
struct net_device *d)
{
return z8530_queue_xmit(&dev_to_sv(d)->chanA, skb);
}
static int hostess_attach(struct net_device *dev, unsigned short encoding,
unsigned short parity)
{
if (encoding == ENCODING_NRZ && parity == PARITY_CRC16_PR1_CCITT)
return 0;
return -EINVAL;
}
static struct z8530_dev *sv11_init(int iobase, int irq)
{
struct z8530_dev *sv;
struct net_device *netdev;
if (!request_region(iobase, 8, "Comtrol SV11")) {
printk(KERN_WARNING "hostess: I/O 0x%X already in use.\n",
iobase);
return NULL;
}
sv = kzalloc(sizeof(struct z8530_dev), GFP_KERNEL);
if (!sv)
goto err_kzalloc;
sv->active = 0;
sv->chanA.ctrlio = iobase + 1;
sv->chanA.dataio = iobase + 3;
sv->chanB.ctrlio = -1;
sv->chanB.dataio = -1;
sv->chanA.irqs = &z8530_nop;
sv->chanB.irqs = &z8530_nop;
outb(0, iobase + 4);
if (request_irq(irq, z8530_interrupt, IRQF_DISABLED,
"Hostess SV11", sv) < 0) {
printk(KERN_WARNING "hostess: IRQ %d already in use.\n", irq);
goto err_irq;
}
sv->irq = irq;
sv->chanA.private = sv;
sv->chanA.dev = sv;
sv->chanB.dev = sv;
if (dma) {
sv->chanA.txdma = 3;
sv->chanA.rxdma = 1;
outb(0x03 | 0x08, iobase + 4);
if (request_dma(sv->chanA.txdma, "Hostess SV/11 (TX)"))
goto err_txdma;
if (dma == 1)
if (request_dma(sv->chanA.rxdma, "Hostess SV/11 (RX)"))
goto err_rxdma;
}
disable_irq(irq);
if (z8530_init(sv)) {
printk(KERN_ERR "Z8530 series device not found.\n");
enable_irq(irq);
goto free_dma;
}
z8530_channel_load(&sv->chanB, z8530_dead_port);
if (sv->type == Z85C30)
z8530_channel_load(&sv->chanA, z8530_hdlc_kilostream);
else
z8530_channel_load(&sv->chanA, z8530_hdlc_kilostream_85230);
enable_irq(irq);
sv->chanA.netdevice = netdev = alloc_hdlcdev(sv);
if (!netdev)
goto free_dma;
dev_to_hdlc(netdev)->attach = hostess_attach;
dev_to_hdlc(netdev)->xmit = hostess_queue_xmit;
netdev->netdev_ops = &hostess_ops;
netdev->base_addr = iobase;
netdev->irq = irq;
if (register_hdlc_device(netdev)) {
printk(KERN_ERR "hostess: unable to register HDLC device.\n");
free_netdev(netdev);
goto free_dma;
}
z8530_describe(sv, "I/O", iobase);
sv->active = 1;
return sv;
free_dma:
if (dma == 1)
free_dma(sv->chanA.rxdma);
err_rxdma:
if (dma)
free_dma(sv->chanA.txdma);
err_txdma:
free_irq(irq, sv);
err_irq:
kfree(sv);
err_kzalloc:
release_region(iobase, 8);
return NULL;
}
static void sv11_shutdown(struct z8530_dev *dev)
{
unregister_hdlc_device(dev->chanA.netdevice);
z8530_shutdown(dev);
free_irq(dev->irq, dev);
if (dma) {
if (dma == 1)
free_dma(dev->chanA.rxdma);
free_dma(dev->chanA.txdma);
}
release_region(dev->chanA.ctrlio - 1, 8);
free_netdev(dev->chanA.netdevice);
kfree(dev);
}
int init_module(void)
{
if ((sv11_unit = sv11_init(io, irq)) == NULL)
return -ENODEV;
return 0;
}
void cleanup_module(void)
{
if (sv11_unit)
sv11_shutdown(sv11_unit);
}
