static int elsa_cs_probe(struct pcmcia_device *link)
{
local_info_t *local;
dev_dbg(&link->dev, "elsa_cs_attach()\n");
local = kzalloc(sizeof(local_info_t), GFP_KERNEL);
if (!local) return -ENOMEM;
local->p_dev = link;
link->priv = local;
local->cardnr = -1;
return elsa_cs_config(link);
}
static void elsa_cs_detach(struct pcmcia_device *link)
{
local_info_t *info = link->priv;
dev_dbg(&link->dev, "elsa_cs_detach(0x%p)\n", link);
info->busy = 1;
elsa_cs_release(link);
kfree(info);
}
static int elsa_cs_configcheck(struct pcmcia_device *p_dev, void *priv_data)
{
int j;
p_dev->io_lines = 3;
p_dev->resource[0]->end = 8;
p_dev->resource[0]->flags &= IO_DATA_PATH_WIDTH;
p_dev->resource[0]->flags |= IO_DATA_PATH_WIDTH_AUTO;
if ((p_dev->resource[0]->end) && p_dev->resource[0]->start) {
printk(KERN_INFO "(elsa_cs: looks like the 96 model)\n");
if (!pcmcia_request_io(p_dev))
return 0;
} else {
printk(KERN_INFO "(elsa_cs: looks like the 97 model)\n");
for (j = 0x2f0; j > 0x100; j -= 0x10) {
p_dev->resource[0]->start = j;
if (!pcmcia_request_io(p_dev))
return 0;
}
}
return -ENODEV;
}
static int elsa_cs_config(struct pcmcia_device *link)
{
int i;
IsdnCard_t icard;
dev_dbg(&link->dev, "elsa_config(0x%p)\n", link);
link->config_flags |= CONF_ENABLE_IRQ | CONF_AUTO_SET_IO;
i = pcmcia_loop_config(link, elsa_cs_configcheck, NULL);
if (i != 0)
goto failed;
if (!link->irq)
goto failed;
i = pcmcia_enable_device(link);
if (i != 0)
goto failed;
icard.para[0] = link->irq;
icard.para[1] = link->resource[0]->start;
icard.protocol = protocol;
icard.typ = ISDN_CTYPE_ELSA_PCMCIA;
i = hisax_init_pcmcia(link, &(((local_info_t *)link->priv)->busy), &icard);
if (i < 0) {
printk(KERN_ERR "elsa_cs: failed to initialize Elsa "
"PCMCIA %d with %pR\n", i, link->resource[0]);
elsa_cs_release(link);
} else
((local_info_t *)link->priv)->cardnr = i;
return 0;
failed:
elsa_cs_release(link);
return -ENODEV;
}
static void elsa_cs_release(struct pcmcia_device *link)
{
local_info_t *local = link->priv;
dev_dbg(&link->dev, "elsa_cs_release(0x%p)\n", link);
if (local) {
if (local->cardnr >= 0) {
HiSax_closecard(local->cardnr);
}
}
pcmcia_disable_device(link);
}
static int elsa_suspend(struct pcmcia_device *link)
{
local_info_t *dev = link->priv;
dev->busy = 1;
return 0;
}
static int elsa_resume(struct pcmcia_device *link)
{
local_info_t *dev = link->priv;
dev->busy = 0;
return 0;
}
static int __init init_elsa_cs(void)
{
return pcmcia_register_driver(&elsa_cs_driver);
}
static void __exit exit_elsa_cs(void)
{
pcmcia_unregister_driver(&elsa_cs_driver);
}
