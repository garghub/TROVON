static int jazzsonic_open(struct net_device* dev)
{
int retval;
retval = request_irq(dev->irq, sonic_interrupt, IRQF_DISABLED,
"sonic", dev);
if (retval) {
printk(KERN_ERR "%s: unable to get IRQ %d.\n",
dev->name, dev->irq);
return retval;
}
retval = sonic_open(dev);
if (retval)
free_irq(dev->irq, dev);
return retval;
}
static int jazzsonic_close(struct net_device* dev)
{
int err;
err = sonic_close(dev);
free_irq(dev->irq, dev);
return err;
}
static int __devinit sonic_probe1(struct net_device *dev)
{
static unsigned version_printed;
unsigned int silicon_revision;
unsigned int val;
struct sonic_local *lp = netdev_priv(dev);
int err = -ENODEV;
int i;
if (!request_mem_region(dev->base_addr, SONIC_MEM_SIZE, jazz_sonic_string))
return -EBUSY;
silicon_revision = SONIC_READ(SONIC_SR);
if (sonic_debug > 1)
printk("SONIC Silicon Revision = 0x%04x\n",silicon_revision);
i = 0;
while (known_revisions[i] != 0xffff &&
known_revisions[i] != silicon_revision)
i++;
if (known_revisions[i] == 0xffff) {
printk("SONIC ethernet controller not found (0x%4x)\n",
silicon_revision);
goto out;
}
if (sonic_debug && version_printed++ == 0)
printk(version);
printk(KERN_INFO "%s: Sonic ethernet found at 0x%08lx, ",
dev_name(lp->device), dev->base_addr);
SONIC_WRITE(SONIC_CMD,SONIC_CR_RST);
SONIC_WRITE(SONIC_CEP,0);
for (i=0; i<3; i++) {
val = SONIC_READ(SONIC_CAP0-i);
dev->dev_addr[i*2] = val;
dev->dev_addr[i*2+1] = val >> 8;
}
err = -ENOMEM;
lp->dma_bitmode = SONIC_BITMODE32;
if ((lp->descriptors = dma_alloc_coherent(lp->device,
SIZEOF_SONIC_DESC * SONIC_BUS_SCALE(lp->dma_bitmode),
&lp->descriptors_laddr, GFP_KERNEL)) == NULL) {
printk(KERN_ERR "%s: couldn't alloc DMA memory for descriptors.\n",
dev_name(lp->device));
goto out;
}
lp->cda = lp->descriptors;
lp->tda = lp->cda + (SIZEOF_SONIC_CDA
* SONIC_BUS_SCALE(lp->dma_bitmode));
lp->rda = lp->tda + (SIZEOF_SONIC_TD * SONIC_NUM_TDS
* SONIC_BUS_SCALE(lp->dma_bitmode));
lp->rra = lp->rda + (SIZEOF_SONIC_RD * SONIC_NUM_RDS
* SONIC_BUS_SCALE(lp->dma_bitmode));
lp->cda_laddr = lp->descriptors_laddr;
lp->tda_laddr = lp->cda_laddr + (SIZEOF_SONIC_CDA
* SONIC_BUS_SCALE(lp->dma_bitmode));
lp->rda_laddr = lp->tda_laddr + (SIZEOF_SONIC_TD * SONIC_NUM_TDS
* SONIC_BUS_SCALE(lp->dma_bitmode));
lp->rra_laddr = lp->rda_laddr + (SIZEOF_SONIC_RD * SONIC_NUM_RDS
* SONIC_BUS_SCALE(lp->dma_bitmode));
dev->netdev_ops = &sonic_netdev_ops;
dev->watchdog_timeo = TX_TIMEOUT;
SONIC_WRITE(SONIC_CRCT,0xffff);
SONIC_WRITE(SONIC_FAET,0xffff);
SONIC_WRITE(SONIC_MPT,0xffff);
return 0;
out:
release_mem_region(dev->base_addr, SONIC_MEM_SIZE);
return err;
}
static int __devinit jazz_sonic_probe(struct platform_device *pdev)
{
struct net_device *dev;
struct sonic_local *lp;
struct resource *res;
int err = 0;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
dev = alloc_etherdev(sizeof(struct sonic_local));
if (!dev)
return -ENOMEM;
lp = netdev_priv(dev);
lp->device = &pdev->dev;
SET_NETDEV_DEV(dev, &pdev->dev);
platform_set_drvdata(pdev, dev);
netdev_boot_setup_check(dev);
dev->base_addr = res->start;
dev->irq = platform_get_irq(pdev, 0);
err = sonic_probe1(dev);
if (err)
goto out;
err = register_netdev(dev);
if (err)
goto out1;
printk("%s: MAC %pM IRQ %d\n", dev->name, dev->dev_addr, dev->irq);
return 0;
out1:
release_mem_region(dev->base_addr, SONIC_MEM_SIZE);
out:
free_netdev(dev);
return err;
}
static int __devexit jazz_sonic_device_remove (struct platform_device *pdev)
{
struct net_device *dev = platform_get_drvdata(pdev);
struct sonic_local* lp = netdev_priv(dev);
unregister_netdev(dev);
dma_free_coherent(lp->device, SIZEOF_SONIC_DESC * SONIC_BUS_SCALE(lp->dma_bitmode),
lp->descriptors, lp->descriptors_laddr);
release_mem_region(dev->base_addr, SONIC_MEM_SIZE);
free_netdev(dev);
return 0;
}
