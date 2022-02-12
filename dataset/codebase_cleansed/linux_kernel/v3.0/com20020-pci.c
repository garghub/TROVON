static int __devinit com20020pci_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
struct net_device *dev;
struct arcnet_local *lp;
int ioaddr, err;
if (pci_enable_device(pdev))
return -EIO;
dev = alloc_arcdev(device);
if (!dev)
return -ENOMEM;
dev->netdev_ops = &com20020_netdev_ops;
lp = netdev_priv(dev);
pci_set_drvdata(pdev, dev);
if (pdev->vendor==0x10B5) {
BUGMSG(D_NORMAL, "SOHARD\n");
ioaddr = pci_resource_start(pdev, 4);
}
else {
BUGMSG(D_NORMAL, "Contemporary Controls\n");
ioaddr = pci_resource_start(pdev, 2);
}
if (!request_region(ioaddr, ARCNET_TOTAL_SIZE, "com20020-pci")) {
BUGMSG(D_INIT, "IO region %xh-%xh already allocated.\n",
ioaddr, ioaddr + ARCNET_TOTAL_SIZE - 1);
err = -EBUSY;
goto out_dev;
}
outb(0x00,ioaddr+1);
inb(ioaddr+1);
dev->base_addr = ioaddr;
dev->irq = pdev->irq;
dev->dev_addr[0] = node;
lp->card_name = "PCI COM20020";
lp->card_flags = id->driver_data;
lp->backplane = backplane;
lp->clockp = clockp & 7;
lp->clockm = clockm & 3;
lp->timeout = timeout;
lp->hw.owner = THIS_MODULE;
if (ASTATUS() == 0xFF) {
BUGMSG(D_NORMAL, "IO address %Xh was reported by PCI BIOS, "
"but seems empty!\n", ioaddr);
err = -EIO;
goto out_port;
}
if (com20020_check(dev)) {
err = -EIO;
goto out_port;
}
if ((err = com20020_found(dev, IRQF_SHARED)) != 0)
goto out_port;
return 0;
out_port:
release_region(ioaddr, ARCNET_TOTAL_SIZE);
out_dev:
free_netdev(dev);
return err;
}
static void __devexit com20020pci_remove(struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
unregister_netdev(dev);
free_irq(dev->irq, dev);
release_region(dev->base_addr, ARCNET_TOTAL_SIZE);
free_netdev(dev);
}
static int __init com20020pci_init(void)
{
BUGLVL(D_NORMAL) printk(VERSION);
return pci_register_driver(&com20020pci_driver);
}
static void __exit com20020pci_cleanup(void)
{
pci_unregister_driver(&com20020pci_driver);
}
