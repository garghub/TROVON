static irqreturn_t ibmtr_interrupt(int irq, void *dev_id) {
ibmtr_dev_t *info = dev_id;
struct net_device *dev = info->dev;
return tok_interrupt(irq, dev);
}
static int __devinit ibmtr_attach(struct pcmcia_device *link)
{
ibmtr_dev_t *info;
struct net_device *dev;
dev_dbg(&link->dev, "ibmtr_attach()\n");
info = kzalloc(sizeof(*info), GFP_KERNEL);
if (!info) return -ENOMEM;
dev = alloc_trdev(sizeof(struct tok_info));
if (!dev) {
kfree(info);
return -ENOMEM;
}
info->p_dev = link;
link->priv = info;
info->ti = netdev_priv(dev);
link->resource[0]->flags |= IO_DATA_PATH_WIDTH_8;
link->resource[0]->end = 4;
link->config_flags |= CONF_ENABLE_IRQ;
link->config_regs = PRESENT_OPTION;
info->dev = dev;
return ibmtr_config(link);
}
static void ibmtr_detach(struct pcmcia_device *link)
{
struct ibmtr_dev_t *info = link->priv;
struct net_device *dev = info->dev;
struct tok_info *ti = netdev_priv(dev);
dev_dbg(&link->dev, "ibmtr_detach\n");
ti->sram_phys |= 1;
unregister_netdev(dev);
del_timer_sync(&(ti->tr_timer));
ibmtr_release(link);
free_netdev(dev);
kfree(info);
}
static int __devinit ibmtr_config(struct pcmcia_device *link)
{
ibmtr_dev_t *info = link->priv;
struct net_device *dev = info->dev;
struct tok_info *ti = netdev_priv(dev);
int i, ret;
dev_dbg(&link->dev, "ibmtr_config\n");
link->io_lines = 16;
link->config_index = 0x61;
link->resource[0]->start = 0xA20;
i = pcmcia_request_io(link);
if (i != 0) {
link->resource[0]->start = 0xA24;
ret = pcmcia_request_io(link);
if (ret)
goto failed;
}
dev->base_addr = link->resource[0]->start;
ret = pcmcia_request_exclusive_irq(link, ibmtr_interrupt);
if (ret)
goto failed;
dev->irq = link->irq;
ti->irq = link->irq;
ti->global_int_enable=GLOBAL_INT_ENABLE+((dev->irq==9) ? 2 : dev->irq);
link->resource[2]->flags |= WIN_DATA_WIDTH_16|WIN_MEMORY_TYPE_CM|WIN_ENABLE;
link->resource[2]->flags |= WIN_USE_WAIT;
link->resource[2]->start = 0;
link->resource[2]->end = 0x2000;
ret = pcmcia_request_window(link, link->resource[2], 250);
if (ret)
goto failed;
ret = pcmcia_map_mem_page(link, link->resource[2], mmiobase);
if (ret)
goto failed;
ti->mmio = ioremap(link->resource[2]->start,
resource_size(link->resource[2]));
link->resource[3]->flags = WIN_DATA_WIDTH_16|WIN_MEMORY_TYPE_CM|WIN_ENABLE;
link->resource[3]->flags |= WIN_USE_WAIT;
link->resource[3]->start = 0;
link->resource[3]->end = sramsize * 1024;
ret = pcmcia_request_window(link, link->resource[3], 250);
if (ret)
goto failed;
ret = pcmcia_map_mem_page(link, link->resource[3], srambase);
if (ret)
goto failed;
ti->sram_base = srambase >> 12;
ti->sram_virt = ioremap(link->resource[3]->start,
resource_size(link->resource[3]));
ti->sram_phys = link->resource[3]->start;
ret = pcmcia_enable_device(link);
if (ret)
goto failed;
ibmtr_hw_setup(dev, mmiobase);
SET_NETDEV_DEV(dev, &link->dev);
i = ibmtr_probe_card(dev);
if (i != 0) {
pr_notice("register_netdev() failed\n");
goto failed;
}
netdev_info(dev, "port %#3lx, irq %d, mmio %#5lx, sram %#5lx, hwaddr=%pM\n",
dev->base_addr, dev->irq,
(u_long)ti->mmio, (u_long)(ti->sram_base << 12),
dev->dev_addr);
return 0;
failed:
ibmtr_release(link);
return -ENODEV;
}
static void ibmtr_release(struct pcmcia_device *link)
{
ibmtr_dev_t *info = link->priv;
struct net_device *dev = info->dev;
dev_dbg(&link->dev, "ibmtr_release\n");
if (link->resource[2]->end) {
struct tok_info *ti = netdev_priv(dev);
iounmap(ti->mmio);
}
pcmcia_disable_device(link);
}
static int ibmtr_suspend(struct pcmcia_device *link)
{
ibmtr_dev_t *info = link->priv;
struct net_device *dev = info->dev;
if (link->open)
netif_device_detach(dev);
return 0;
}
static int __devinit ibmtr_resume(struct pcmcia_device *link)
{
ibmtr_dev_t *info = link->priv;
struct net_device *dev = info->dev;
if (link->open) {
ibmtr_probe(dev);
netif_device_attach(dev);
}
return 0;
}
static void ibmtr_hw_setup(struct net_device *dev, u_int mmiobase)
{
int i;
i = (mmiobase >> 16) & 0x0F;
outb(i, dev->base_addr);
i = 0x10 | ((mmiobase >> 12) & 0x0E);
outb(i, dev->base_addr);
i = 0x26;
outb(i, dev->base_addr);
i = (sramsize >> 4) & 0x07;
i = ((i == 4) ? 3 : i) << 2;
i |= 0x30;
if (ringspeed == 16)
i |= 2;
if (dev->base_addr == 0xA24)
i |= 1;
outb(i, dev->base_addr);
outb(0x40, dev->base_addr);
}
static int __init init_ibmtr_cs(void)
{
return pcmcia_register_driver(&ibmtr_cs_driver);
}
static void __exit exit_ibmtr_cs(void)
{
pcmcia_unregister_driver(&ibmtr_cs_driver);
}
