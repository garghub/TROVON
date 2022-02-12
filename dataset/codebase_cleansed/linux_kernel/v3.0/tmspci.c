static unsigned short tms_pci_sifreadb(struct net_device *dev, unsigned short reg)
{
return inb(dev->base_addr + reg);
}
static unsigned short tms_pci_sifreadw(struct net_device *dev, unsigned short reg)
{
return inw(dev->base_addr + reg);
}
static void tms_pci_sifwriteb(struct net_device *dev, unsigned short val, unsigned short reg)
{
outb(val, dev->base_addr + reg);
}
static void tms_pci_sifwritew(struct net_device *dev, unsigned short val, unsigned short reg)
{
outw(val, dev->base_addr + reg);
}
static int __devinit tms_pci_attach(struct pci_dev *pdev, const struct pci_device_id *ent)
{
static int versionprinted;
struct net_device *dev;
struct net_local *tp;
int ret;
unsigned int pci_irq_line;
unsigned long pci_ioaddr;
struct card_info *cardinfo = &card_info_table[ent->driver_data];
if (versionprinted++ == 0)
printk("%s", version);
if (pci_enable_device(pdev))
return -EIO;
pci_irq_line = pdev->irq;
pci_ioaddr = pci_resource_start (pdev, 0);
dev = alloc_trdev(sizeof(struct net_local));
if (!dev)
return -ENOMEM;
if (!request_region(pci_ioaddr, TMS_PCI_IO_EXTENT, dev->name)) {
ret = -EBUSY;
goto err_out_trdev;
}
dev->base_addr = pci_ioaddr;
dev->irq = pci_irq_line;
dev->dma = 0;
dev_info(&pdev->dev, "%s\n", cardinfo->name);
dev_info(&pdev->dev, " IO: %#4lx IRQ: %d\n", dev->base_addr, dev->irq);
tms_pci_read_eeprom(dev);
dev_info(&pdev->dev, " Ring Station Address: %pM\n", dev->dev_addr);
ret = tmsdev_init(dev, &pdev->dev);
if (ret) {
dev_info(&pdev->dev, "unable to get memory for dev->priv.\n");
goto err_out_region;
}
tp = netdev_priv(dev);
tp->setnselout = tms_pci_setnselout_pins;
tp->sifreadb = tms_pci_sifreadb;
tp->sifreadw = tms_pci_sifreadw;
tp->sifwriteb = tms_pci_sifwriteb;
tp->sifwritew = tms_pci_sifwritew;
memcpy(tp->ProductID, cardinfo->name, PROD_ID_SIZE + 1);
tp->tmspriv = cardinfo;
dev->netdev_ops = &tms380tr_netdev_ops;
ret = request_irq(pdev->irq, tms380tr_interrupt, IRQF_SHARED,
dev->name, dev);
if (ret)
goto err_out_tmsdev;
pci_set_drvdata(pdev, dev);
SET_NETDEV_DEV(dev, &pdev->dev);
ret = register_netdev(dev);
if (ret)
goto err_out_irq;
return 0;
err_out_irq:
free_irq(pdev->irq, dev);
err_out_tmsdev:
pci_set_drvdata(pdev, NULL);
tmsdev_term(dev);
err_out_region:
release_region(pci_ioaddr, TMS_PCI_IO_EXTENT);
err_out_trdev:
free_netdev(dev);
return ret;
}
static void tms_pci_read_eeprom(struct net_device *dev)
{
int i;
tms_pci_sifwritew(dev, 0, SIFADX);
tms_pci_sifwritew(dev, 0, SIFADR);
dev->addr_len = 6;
for(i = 0; i < 6; i++)
dev->dev_addr[i] = tms_pci_sifreadw(dev, SIFINC) >> 8;
}
static unsigned short tms_pci_setnselout_pins(struct net_device *dev)
{
unsigned short val = 0;
struct net_local *tp = netdev_priv(dev);
struct card_info *cardinfo = tp->tmspriv;
if(tp->DataRate == SPEED_4)
val |= cardinfo->nselout[0];
else
val |= cardinfo->nselout[1];
return val;
}
static void __devexit tms_pci_detach (struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
BUG_ON(!dev);
unregister_netdev(dev);
release_region(dev->base_addr, TMS_PCI_IO_EXTENT);
free_irq(dev->irq, dev);
tmsdev_term(dev);
free_netdev(dev);
pci_set_drvdata(pdev, NULL);
}
static int __init tms_pci_init (void)
{
return pci_register_driver(&tms_pci_driver);
}
static void __exit tms_pci_rmmod (void)
{
pci_unregister_driver (&tms_pci_driver);
}
