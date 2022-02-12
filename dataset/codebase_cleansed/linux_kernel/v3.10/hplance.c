static int hplance_init_one(struct dio_dev *d, const struct dio_device_id *ent)
{
struct net_device *dev;
int err = -ENOMEM;
dev = alloc_etherdev(sizeof(struct hplance_private));
if (!dev)
goto out;
err = -EBUSY;
if (!request_mem_region(dio_resource_start(d),
dio_resource_len(d), d->name))
goto out_free_netdev;
hplance_init(dev, d);
err = register_netdev(dev);
if (err)
goto out_release_mem_region;
dio_set_drvdata(d, dev);
printk(KERN_INFO "%s: %s; select code %d, addr %pM, irq %d\n",
dev->name, d->name, d->scode, dev->dev_addr, d->ipl);
return 0;
out_release_mem_region:
release_mem_region(dio_resource_start(d), dio_resource_len(d));
out_free_netdev:
free_netdev(dev);
out:
return err;
}
static void hplance_remove_one(struct dio_dev *d)
{
struct net_device *dev = dio_get_drvdata(d);
unregister_netdev(dev);
release_mem_region(dio_resource_start(d), dio_resource_len(d));
free_netdev(dev);
}
static void hplance_init(struct net_device *dev, struct dio_dev *d)
{
unsigned long va = (d->resource.start + DIO_VIRADDRBASE);
struct hplance_private *lp;
int i;
out_8(va+DIO_IDOFF, 0xff);
udelay(100);
dev->base_addr = va;
dev->netdev_ops = &hplance_netdev_ops;
dev->dma = 0;
for (i=0; i<6; i++) {
dev->dev_addr[i] = ((in_8(va + HPLANCE_NVRAMOFF + i*4 + 1) & 0xF) << 4)
| (in_8(va + HPLANCE_NVRAMOFF + i*4 + 3) & 0xF);
}
lp = netdev_priv(dev);
lp->lance.name = (char*)d->name;
lp->lance.base = va;
lp->lance.init_block = (struct lance_init_block *)(va + HPLANCE_MEMOFF);
lp->lance.lance_init_block = NULL;
lp->lance.busmaster_regval = LE_C3_BSWP;
lp->lance.irq = d->ipl;
lp->lance.writerap = hplance_writerap;
lp->lance.writerdp = hplance_writerdp;
lp->lance.readrdp = hplance_readrdp;
lp->lance.lance_log_rx_bufs = LANCE_LOG_RX_BUFFERS;
lp->lance.lance_log_tx_bufs = LANCE_LOG_TX_BUFFERS;
lp->lance.rx_ring_mod_mask = RX_RING_MOD_MASK;
lp->lance.tx_ring_mod_mask = TX_RING_MOD_MASK;
}
static void hplance_writerap(void *priv, unsigned short value)
{
struct lance_private *lp = (struct lance_private *)priv;
do {
out_be16(lp->base + HPLANCE_REGOFF + LANCE_RAP, value);
} while ((in_8(lp->base + HPLANCE_STATUS) & LE_ACK) == 0);
}
static void hplance_writerdp(void *priv, unsigned short value)
{
struct lance_private *lp = (struct lance_private *)priv;
do {
out_be16(lp->base + HPLANCE_REGOFF + LANCE_RDP, value);
} while ((in_8(lp->base + HPLANCE_STATUS) & LE_ACK) == 0);
}
static unsigned short hplance_readrdp(void *priv)
{
struct lance_private *lp = (struct lance_private *)priv;
__u16 value;
do {
value = in_be16(lp->base + HPLANCE_REGOFF + LANCE_RDP);
} while ((in_8(lp->base + HPLANCE_STATUS) & LE_ACK) == 0);
return value;
}
static int hplance_open(struct net_device *dev)
{
int status;
struct lance_private *lp = netdev_priv(dev);
status = lance_open(dev);
if (status)
return status;
out_8(lp->base + HPLANCE_STATUS, LE_IE);
return 0;
}
static int hplance_close(struct net_device *dev)
{
struct lance_private *lp = netdev_priv(dev);
out_8(lp->base + HPLANCE_STATUS, 0);
lance_close(dev);
return 0;
}
static int __init hplance_init_module(void)
{
return dio_register_driver(&hplance_driver);
}
static void __exit hplance_cleanup_module(void)
{
dio_unregister_driver(&hplance_driver);
}
