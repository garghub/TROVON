static void regdump(struct net_device *dev)
{
#ifdef DEBUG
int ioaddr = dev->base_addr;
int count;
netdev_dbg(dev, "register dump:\n");
for (count = ioaddr; count < ioaddr + 16; count++)
{
if (!(count % 16))
pr_cont("%04X:", count);
pr_cont(" %02X", inb(count));
}
pr_cont("\n");
netdev_dbg(dev, "buffer0 dump:\n");
count = 0;
outb((count >> 8) | RDDATAflag | AUTOINCflag, _ADDR_HI);
outb(count & 0xff, _ADDR_LO);
for (count = 0; count < 256+32; count++)
{
if (!(count % 16))
pr_cont("%04X:", count);
pr_cont(" %02X", inb(_MEMDATA));
}
pr_cont("\n");
#endif
}
static int com20020_probe(struct pcmcia_device *p_dev)
{
struct com20020_dev *info;
struct net_device *dev;
struct arcnet_local *lp;
dev_dbg(&p_dev->dev, "com20020_attach()\n");
info = kzalloc(sizeof(*info), GFP_KERNEL);
if (!info)
goto fail_alloc_info;
dev = alloc_arcdev("");
if (!dev)
goto fail_alloc_dev;
lp = netdev_priv(dev);
lp->timeout = timeout;
lp->backplane = backplane;
lp->clockp = clockp;
lp->clockm = clockm & 3;
lp->hw.owner = THIS_MODULE;
dev->dev_addr[0] = node;
p_dev->resource[0]->flags |= IO_DATA_PATH_WIDTH_8;
p_dev->resource[0]->end = 16;
p_dev->config_flags |= CONF_ENABLE_IRQ;
info->dev = dev;
p_dev->priv = info;
return com20020_config(p_dev);
fail_alloc_dev:
kfree(info);
fail_alloc_info:
return -ENOMEM;
}
static void com20020_detach(struct pcmcia_device *link)
{
struct com20020_dev *info = link->priv;
struct net_device *dev = info->dev;
dev_dbg(&link->dev, "detach...\n");
dev_dbg(&link->dev, "com20020_detach\n");
dev_dbg(&link->dev, "unregister...\n");
unregister_netdev(dev);
if (dev->irq)
free_irq(dev->irq, dev);
com20020_release(link);
dev_dbg(&link->dev, "unlinking...\n");
if (link->priv)
{
dev = info->dev;
if (dev)
{
dev_dbg(&link->dev, "kfree...\n");
free_netdev(dev);
}
dev_dbg(&link->dev, "kfree2...\n");
kfree(info);
}
}
static int com20020_config(struct pcmcia_device *link)
{
struct arcnet_local *lp;
struct com20020_dev *info;
struct net_device *dev;
int i, ret;
int ioaddr;
info = link->priv;
dev = info->dev;
dev_dbg(&link->dev, "config...\n");
dev_dbg(&link->dev, "com20020_config\n");
dev_dbg(&link->dev, "baseport1 is %Xh\n",
(unsigned int) link->resource[0]->start);
i = -ENODEV;
link->io_lines = 16;
if (!link->resource[0]->start)
{
for (ioaddr = 0x100; ioaddr < 0x400; ioaddr += 0x10)
{
link->resource[0]->start = ioaddr;
i = pcmcia_request_io(link);
if (i == 0)
break;
}
}
else
i = pcmcia_request_io(link);
if (i != 0)
{
dev_dbg(&link->dev, "requestIO failed totally!\n");
goto failed;
}
ioaddr = dev->base_addr = link->resource[0]->start;
dev_dbg(&link->dev, "got ioaddr %Xh\n", ioaddr);
dev_dbg(&link->dev, "request IRQ %d\n",
link->irq);
if (!link->irq)
{
dev_dbg(&link->dev, "requestIRQ failed totally!\n");
goto failed;
}
dev->irq = link->irq;
ret = pcmcia_enable_device(link);
if (ret)
goto failed;
if (com20020_check(dev))
{
regdump(dev);
goto failed;
}
lp = netdev_priv(dev);
lp->card_name = "PCMCIA COM20020";
lp->card_flags = ARC_CAN_10MBIT;
SET_NETDEV_DEV(dev, &link->dev);
i = com20020_found(dev, 0);
if (i != 0) {
dev_notice(&link->dev,
"com20020_found() failed\n");
goto failed;
}
netdev_dbg(dev, "port %#3lx, irq %d\n",
dev->base_addr, dev->irq);
return 0;
failed:
dev_dbg(&link->dev, "com20020_config failed...\n");
com20020_release(link);
return -ENODEV;
}
static void com20020_release(struct pcmcia_device *link)
{
dev_dbg(&link->dev, "com20020_release\n");
pcmcia_disable_device(link);
}
static int com20020_suspend(struct pcmcia_device *link)
{
struct com20020_dev *info = link->priv;
struct net_device *dev = info->dev;
if (link->open)
netif_device_detach(dev);
return 0;
}
static int com20020_resume(struct pcmcia_device *link)
{
struct com20020_dev *info = link->priv;
struct net_device *dev = info->dev;
if (link->open) {
int ioaddr = dev->base_addr;
struct arcnet_local *lp = netdev_priv(dev);
ARCRESET;
}
return 0;
}
