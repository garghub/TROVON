static int
airport_suspend(struct macio_dev *mdev, pm_message_t state)
{
struct orinoco_private *priv = dev_get_drvdata(&mdev->ofdev.dev);
struct net_device *dev = priv->ndev;
struct airport *card = priv->card;
unsigned long flags;
int err;
printk(KERN_DEBUG "%s: Airport entering sleep mode\n", dev->name);
err = orinoco_lock(priv, &flags);
if (err) {
printk(KERN_ERR "%s: hw_unavailable on PBOOK_SLEEP_NOW\n",
dev->name);
return 0;
}
orinoco_down(priv);
orinoco_unlock(priv, &flags);
disable_irq(card->irq);
pmac_call_feature(PMAC_FTR_AIRPORT_ENABLE,
macio_get_of_node(mdev), 0, 0);
return 0;
}
static int
airport_resume(struct macio_dev *mdev)
{
struct orinoco_private *priv = dev_get_drvdata(&mdev->ofdev.dev);
struct net_device *dev = priv->ndev;
struct airport *card = priv->card;
unsigned long flags;
int err;
printk(KERN_DEBUG "%s: Airport waking up\n", dev->name);
pmac_call_feature(PMAC_FTR_AIRPORT_ENABLE,
macio_get_of_node(mdev), 0, 1);
msleep(200);
enable_irq(card->irq);
priv->hw.ops->lock_irqsave(&priv->lock, &flags);
err = orinoco_up(priv);
priv->hw.ops->unlock_irqrestore(&priv->lock, &flags);
return err;
}
static int
airport_detach(struct macio_dev *mdev)
{
struct orinoco_private *priv = dev_get_drvdata(&mdev->ofdev.dev);
struct airport *card = priv->card;
if (card->ndev_registered)
orinoco_if_del(priv);
card->ndev_registered = 0;
if (card->irq_requested)
free_irq(card->irq, priv);
card->irq_requested = 0;
if (card->vaddr)
iounmap(card->vaddr);
card->vaddr = NULL;
macio_release_resource(mdev, 0);
pmac_call_feature(PMAC_FTR_AIRPORT_ENABLE,
macio_get_of_node(mdev), 0, 0);
ssleep(1);
macio_set_drvdata(mdev, NULL);
free_orinocodev(priv);
return 0;
}
static int airport_hard_reset(struct orinoco_private *priv)
{
#if 0
struct airport *card = priv->card;
disable_irq(card->irq);
pmac_call_feature(PMAC_FTR_AIRPORT_ENABLE,
macio_get_of_node(card->mdev), 0, 0);
ssleep(1);
pmac_call_feature(PMAC_FTR_AIRPORT_ENABLE,
macio_get_of_node(card->mdev), 0, 1);
ssleep(1);
enable_irq(card->irq);
ssleep(1);
#endif
return 0;
}
static int
airport_attach(struct macio_dev *mdev, const struct of_device_id *match)
{
struct orinoco_private *priv;
struct airport *card;
unsigned long phys_addr;
struct hermes *hw;
if (macio_resource_count(mdev) < 1 || macio_irq_count(mdev) < 1) {
printk(KERN_ERR PFX "Wrong interrupt/addresses in OF tree\n");
return -ENODEV;
}
priv = alloc_orinocodev(sizeof(*card), &mdev->ofdev.dev,
airport_hard_reset, NULL);
if (!priv) {
printk(KERN_ERR PFX "Cannot allocate network device\n");
return -ENODEV;
}
card = priv->card;
hw = &priv->hw;
card->mdev = mdev;
if (macio_request_resource(mdev, 0, DRIVER_NAME)) {
printk(KERN_ERR PFX "can't request IO resource !\n");
free_orinocodev(priv);
return -EBUSY;
}
macio_set_drvdata(mdev, priv);
card->irq = macio_irq(mdev, 0);
phys_addr = macio_resource_start(mdev, 0);
printk(KERN_DEBUG PFX "Physical address %lx\n", phys_addr);
card->vaddr = ioremap(phys_addr, AIRPORT_IO_LEN);
if (!card->vaddr) {
printk(KERN_ERR PFX "ioremap() failed\n");
goto failed;
}
hermes_struct_init(hw, card->vaddr, HERMES_16BIT_REGSPACING);
pmac_call_feature(PMAC_FTR_AIRPORT_ENABLE,
macio_get_of_node(mdev), 0, 1);
ssleep(1);
hw->ops->init(hw);
if (request_irq(card->irq, orinoco_interrupt, 0, DRIVER_NAME, priv)) {
printk(KERN_ERR PFX "Couldn't get IRQ %d\n", card->irq);
goto failed;
}
card->irq_requested = 1;
if (orinoco_init(priv) != 0) {
printk(KERN_ERR PFX "orinoco_init() failed\n");
goto failed;
}
if (orinoco_if_add(priv, phys_addr, card->irq, NULL) != 0) {
printk(KERN_ERR PFX "orinoco_if_add() failed\n");
goto failed;
}
card->ndev_registered = 1;
return 0;
failed:
airport_detach(mdev);
return -ENODEV;
}
static int __init
init_airport(void)
{
printk(KERN_DEBUG "%s\n", version);
return macio_register_driver(&airport_driver);
}
static void __exit
exit_airport(void)
{
macio_unregister_driver(&airport_driver);
}
