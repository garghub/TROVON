static int com20020pci_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
struct com20020_pci_card_info *ci;
struct net_device *dev;
struct arcnet_local *lp;
struct com20020_priv *priv;
int i, ioaddr, ret;
struct resource *r;
if (pci_enable_device(pdev))
return -EIO;
priv = devm_kzalloc(&pdev->dev, sizeof(struct com20020_priv),
GFP_KERNEL);
ci = (struct com20020_pci_card_info *)id->driver_data;
priv->ci = ci;
INIT_LIST_HEAD(&priv->list_dev);
for (i = 0; i < ci->devcount; i++) {
struct com20020_pci_channel_map *cm = &ci->chan_map_tbl[i];
struct com20020_dev *card;
dev = alloc_arcdev(device);
if (!dev) {
ret = -ENOMEM;
goto out_port;
}
dev->netdev_ops = &com20020_netdev_ops;
lp = netdev_priv(dev);
BUGMSG(D_NORMAL, "%s Controls\n", ci->name);
ioaddr = pci_resource_start(pdev, cm->bar) + cm->offset;
r = devm_request_region(&pdev->dev, ioaddr, cm->size,
"com20020-pci");
if (!r) {
pr_err("IO region %xh-%xh already allocated.\n",
ioaddr, ioaddr + cm->size - 1);
ret = -EBUSY;
goto out_port;
}
outb(0x00, ioaddr + 1);
inb(ioaddr + 1);
dev->base_addr = ioaddr;
dev->dev_addr[0] = node;
dev->irq = pdev->irq;
lp->card_name = "PCI COM20020";
lp->card_flags = ci->flags;
lp->backplane = backplane;
lp->clockp = clockp & 7;
lp->clockm = clockm & 3;
lp->timeout = timeout;
lp->hw.owner = THIS_MODULE;
if (ASTATUS() == 0xFF) {
pr_err("IO address %Xh is empty!\n", ioaddr);
ret = -EIO;
goto out_port;
}
if (com20020_check(dev)) {
ret = -EIO;
goto out_port;
}
card = devm_kzalloc(&pdev->dev, sizeof(struct com20020_dev),
GFP_KERNEL);
if (!card) {
pr_err("%s out of memory!\n", __func__);
return -ENOMEM;
}
card->index = i;
card->pci_priv = priv;
card->dev = dev;
dev_set_drvdata(&dev->dev, card);
ret = com20020_found(dev, IRQF_SHARED);
if (ret)
goto out_port;
list_add(&card->list, &priv->list_dev);
}
pci_set_drvdata(pdev, priv);
return 0;
out_port:
com20020pci_remove(pdev);
return ret;
}
static void com20020pci_remove(struct pci_dev *pdev)
{
struct com20020_dev *card, *tmpcard;
struct com20020_priv *priv;
priv = pci_get_drvdata(pdev);
list_for_each_entry_safe(card, tmpcard, &priv->list_dev, list) {
struct net_device *dev = card->dev;
unregister_netdev(dev);
free_irq(dev->irq, dev);
free_netdev(dev);
}
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
