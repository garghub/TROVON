static int
orinoco_cs_hard_reset(struct orinoco_private *priv)
{
struct orinoco_pccard *card = priv->card;
struct pcmcia_device *link = card->p_dev;
int err;
set_bit(0, &card->hard_reset_in_progress);
err = pcmcia_reset_card(link->socket);
if (err)
return err;
msleep(100);
clear_bit(0, &card->hard_reset_in_progress);
return 0;
}
static int
orinoco_cs_probe(struct pcmcia_device *link)
{
struct orinoco_private *priv;
struct orinoco_pccard *card;
priv = alloc_orinocodev(sizeof(*card), &link->dev,
orinoco_cs_hard_reset, NULL);
if (!priv)
return -ENOMEM;
card = priv->card;
card->p_dev = link;
link->priv = priv;
return orinoco_cs_config(link);
}
static void orinoco_cs_detach(struct pcmcia_device *link)
{
struct orinoco_private *priv = link->priv;
orinoco_if_del(priv);
orinoco_cs_release(link);
free_orinocodev(priv);
}
static int orinoco_cs_config_check(struct pcmcia_device *p_dev, void *priv_data)
{
if (p_dev->config_index == 0)
return -EINVAL;
return pcmcia_request_io(p_dev);
}
static int
orinoco_cs_config(struct pcmcia_device *link)
{
struct orinoco_private *priv = link->priv;
hermes_t *hw = &priv->hw;
int ret;
void __iomem *mem;
link->config_flags |= CONF_AUTO_SET_VPP | CONF_AUTO_CHECK_VCC |
CONF_AUTO_SET_IO | CONF_ENABLE_IRQ;
if (ignore_cis_vcc)
link->config_flags &= ~CONF_AUTO_CHECK_VCC;
ret = pcmcia_loop_config(link, orinoco_cs_config_check, NULL);
if (ret) {
if (!ignore_cis_vcc)
printk(KERN_ERR PFX "GetNextTuple(): No matching "
"CIS configuration. Maybe you need the "
"ignore_cis_vcc=1 parameter.\n");
goto failed;
}
mem = ioport_map(link->resource[0]->start,
resource_size(link->resource[0]));
if (!mem)
goto failed;
hermes_struct_init(hw, mem, HERMES_16BIT_REGSPACING);
ret = pcmcia_request_irq(link, orinoco_interrupt);
if (ret)
goto failed;
ret = pcmcia_enable_device(link);
if (ret)
goto failed;
if (orinoco_init(priv) != 0) {
printk(KERN_ERR PFX "orinoco_init() failed\n");
goto failed;
}
if (orinoco_if_add(priv, link->resource[0]->start,
link->irq, NULL) != 0) {
printk(KERN_ERR PFX "orinoco_if_add() failed\n");
goto failed;
}
return 0;
failed:
orinoco_cs_release(link);
return -ENODEV;
}
static void
orinoco_cs_release(struct pcmcia_device *link)
{
struct orinoco_private *priv = link->priv;
unsigned long flags;
priv->hw.ops->lock_irqsave(&priv->lock, &flags);
priv->hw_unavailable++;
priv->hw.ops->unlock_irqrestore(&priv->lock, &flags);
pcmcia_disable_device(link);
if (priv->hw.iobase)
ioport_unmap(priv->hw.iobase);
}
static int orinoco_cs_suspend(struct pcmcia_device *link)
{
struct orinoco_private *priv = link->priv;
struct orinoco_pccard *card = priv->card;
if (!test_bit(0, &card->hard_reset_in_progress))
orinoco_down(priv);
return 0;
}
static int orinoco_cs_resume(struct pcmcia_device *link)
{
struct orinoco_private *priv = link->priv;
struct orinoco_pccard *card = priv->card;
int err = 0;
if (!test_bit(0, &card->hard_reset_in_progress))
err = orinoco_up(priv);
return err;
}
static int __init
init_orinoco_cs(void)
{
return pcmcia_register_driver(&orinoco_driver);
}
static void __exit
exit_orinoco_cs(void)
{
pcmcia_unregister_driver(&orinoco_driver);
}
