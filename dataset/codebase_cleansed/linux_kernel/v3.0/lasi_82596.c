static inline void ca(struct net_device *dev)
{
gsc_writel(0, dev->base_addr + PA_CHANNEL_ATTENTION);
}
static void mpu_port(struct net_device *dev, int c, dma_addr_t x)
{
struct i596_private *lp = netdev_priv(dev);
u32 v = (u32) (c) | (u32) (x);
u16 a, b;
if (lp->options & OPT_SWAP_PORT) {
a = v >> 16;
b = v & 0xffff;
} else {
a = v & 0xffff;
b = v >> 16;
}
gsc_writel(a, dev->base_addr + PA_CPU_PORT_L_ACCESS);
udelay(1);
gsc_writel(b, dev->base_addr + PA_CPU_PORT_L_ACCESS);
}
static int __devinit
lan_init_chip(struct parisc_device *dev)
{
struct net_device *netdevice;
struct i596_private *lp;
int retval;
int i;
if (!dev->irq) {
printk(KERN_ERR "%s: IRQ not found for i82596 at 0x%lx\n",
__FILE__, (unsigned long)dev->hpa.start);
return -ENODEV;
}
printk(KERN_INFO "Found i82596 at 0x%lx, IRQ %d\n",
(unsigned long)dev->hpa.start, dev->irq);
netdevice = alloc_etherdev(sizeof(struct i596_private));
if (!netdevice)
return -ENOMEM;
SET_NETDEV_DEV(netdevice, &dev->dev);
parisc_set_drvdata (dev, netdevice);
netdevice->base_addr = dev->hpa.start;
netdevice->irq = dev->irq;
if (pdc_lan_station_id(netdevice->dev_addr, netdevice->base_addr)) {
for (i = 0; i < 6; i++) {
netdevice->dev_addr[i] = gsc_readb(LAN_PROM_ADDR + i);
}
printk(KERN_INFO
"%s: MAC of HP700 LAN read from EEPROM\n", __FILE__);
}
lp = netdev_priv(netdevice);
lp->options = dev->id.sversion == 0x72 ? OPT_SWAP_PORT : 0;
retval = i82596_probe(netdevice);
if (retval) {
free_netdev(netdevice);
return -ENODEV;
}
return retval;
}
static int __devexit lan_remove_chip (struct parisc_device *pdev)
{
struct net_device *dev = parisc_get_drvdata(pdev);
struct i596_private *lp = netdev_priv(dev);
unregister_netdev (dev);
DMA_FREE(&pdev->dev, sizeof(struct i596_private),
(void *)lp->dma, lp->dma_addr);
free_netdev (dev);
return 0;
}
static int __devinit lasi_82596_init(void)
{
printk(KERN_INFO LASI_82596_DRIVER_VERSION "\n");
return register_parisc_driver(&lan_driver);
}
static void __exit lasi_82596_exit(void)
{
unregister_parisc_driver(&lan_driver);
}
