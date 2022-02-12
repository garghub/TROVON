static void led_tx_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
struct com20020_dev *card;
struct com20020_priv *priv;
struct com20020_pci_card_info *ci;
card = container_of(led_cdev, struct com20020_dev, tx_led);
priv = card->pci_priv;
ci = priv->ci;
outb(!!value, priv->misc + ci->leds[card->index].green);
}
static void led_recon_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
struct com20020_dev *card;
struct com20020_priv *priv;
struct com20020_pci_card_info *ci;
card = container_of(led_cdev, struct com20020_dev, recon_led);
priv = card->pci_priv;
ci = priv->ci;
outb(!!value, priv->misc + ci->leds[card->index].red);
}
static int com20020pci_probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
struct com20020_pci_card_info *ci;
struct com20020_pci_channel_map *mm;
struct net_device *dev;
struct arcnet_local *lp;
struct com20020_priv *priv;
int i, ioaddr, ret;
struct resource *r;
if (pci_enable_device(pdev))
return -EIO;
priv = devm_kzalloc(&pdev->dev, sizeof(struct com20020_priv),
GFP_KERNEL);
if (!priv)
return -ENOMEM;
ci = (struct com20020_pci_card_info *)id->driver_data;
priv->ci = ci;
mm = &ci->misc_map;
INIT_LIST_HEAD(&priv->list_dev);
if (mm->size) {
ioaddr = pci_resource_start(pdev, mm->bar) + mm->offset;
r = devm_request_region(&pdev->dev, ioaddr, mm->size,
"com20020-pci");
if (!r) {
pr_err("IO region %xh-%xh already allocated.\n",
ioaddr, ioaddr + mm->size - 1);
return -EBUSY;
}
priv->misc = ioaddr;
}
for (i = 0; i < ci->devcount; i++) {
struct com20020_pci_channel_map *cm = &ci->chan_map_tbl[i];
struct com20020_dev *card;
int dev_id_mask = 0xf;
dev = alloc_arcdev(device);
if (!dev) {
ret = -ENOMEM;
goto out_port;
}
dev->dev_port = i;
dev->netdev_ops = &com20020_netdev_ops;
lp = netdev_priv(dev);
arc_printk(D_NORMAL, dev, "%s Controls\n", ci->name);
ioaddr = pci_resource_start(pdev, cm->bar) + cm->offset;
r = devm_request_region(&pdev->dev, ioaddr, cm->size,
"com20020-pci");
if (!r) {
pr_err("IO region %xh-%xh already allocated\n",
ioaddr, ioaddr + cm->size - 1);
ret = -EBUSY;
goto out_port;
}
arcnet_outb(0x00, ioaddr, COM20020_REG_W_COMMAND);
arcnet_inb(ioaddr, COM20020_REG_R_DIAGSTAT);
SET_NETDEV_DEV(dev, &pdev->dev);
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
if (!strncmp(ci->name, "EAE PLX-PCI MA1", 15))
dev_id_mask = 0x3;
dev->dev_id = (inb(priv->misc + ci->rotary) >> 4) & dev_id_mask;
snprintf(dev->name, sizeof(dev->name), "arc%d-%d", dev->dev_id, i);
if (arcnet_inb(ioaddr, COM20020_REG_R_STATUS) == 0xFF) {
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
if (!card)
return -ENOMEM;
card->index = i;
card->pci_priv = priv;
card->tx_led.brightness_set = led_tx_set;
card->tx_led.default_trigger = devm_kasprintf(&pdev->dev,
GFP_KERNEL, "arc%d-%d-tx",
dev->dev_id, i);
card->tx_led.name = devm_kasprintf(&pdev->dev, GFP_KERNEL,
"pci:green:tx:%d-%d",
dev->dev_id, i);
card->tx_led.dev = &dev->dev;
card->recon_led.brightness_set = led_recon_set;
card->recon_led.default_trigger = devm_kasprintf(&pdev->dev,
GFP_KERNEL, "arc%d-%d-recon",
dev->dev_id, i);
card->recon_led.name = devm_kasprintf(&pdev->dev, GFP_KERNEL,
"pci:red:recon:%d-%d",
dev->dev_id, i);
card->recon_led.dev = &dev->dev;
card->dev = dev;
ret = devm_led_classdev_register(&pdev->dev, &card->tx_led);
if (ret)
goto out_port;
ret = devm_led_classdev_register(&pdev->dev, &card->recon_led);
if (ret)
goto out_port;
dev_set_drvdata(&dev->dev, card);
ret = com20020_found(dev, IRQF_SHARED);
if (ret)
goto out_port;
devm_arcnet_led_init(dev, dev->dev_id, i);
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
if (BUGLVL(D_NORMAL))
pr_info("%s\n", "COM20020 PCI support");
return pci_register_driver(&com20020pci_driver);
}
static void __exit com20020pci_cleanup(void)
{
pci_unregister_driver(&com20020pci_driver);
}
