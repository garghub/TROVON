static int avma1cs_probe(struct pcmcia_device *p_dev)
{
dev_dbg(&p_dev->dev, "avma1cs_attach()\n");
p_dev->config_flags |= CONF_ENABLE_IRQ | CONF_AUTO_SET_IO;
p_dev->config_index = 1;
p_dev->config_regs = PRESENT_OPTION;
return avma1cs_config(p_dev);
}
static void avma1cs_detach(struct pcmcia_device *link)
{
dev_dbg(&link->dev, "avma1cs_detach(0x%p)\n", link);
avma1cs_release(link);
kfree(link->priv);
}
static int avma1cs_configcheck(struct pcmcia_device *p_dev, void *priv_data)
{
p_dev->resource[0]->end = 16;
p_dev->resource[0]->flags &= ~IO_DATA_PATH_WIDTH;
p_dev->resource[0]->flags |= IO_DATA_PATH_WIDTH_8;
p_dev->io_lines = 5;
return pcmcia_request_io(p_dev);
}
static int avma1cs_config(struct pcmcia_device *link)
{
int i = -1;
char devname[128];
IsdnCard_t icard;
int busy = 0;
dev_dbg(&link->dev, "avma1cs_config(0x%p)\n", link);
devname[0] = 0;
if (link->prod_id[1])
strlcpy(devname, link->prod_id[1], sizeof(devname));
if (pcmcia_loop_config(link, avma1cs_configcheck, NULL))
return -ENODEV;
do {
if (!link->irq) {
pcmcia_disable_device(link);
break;
}
i = pcmcia_enable_device(link);
if (i != 0) {
pcmcia_disable_device(link);
break;
}
} while (0);
if (i != 0) {
avma1cs_release(link);
return -ENODEV;
}
icard.para[0] = link->irq;
icard.para[1] = link->resource[0]->start;
icard.protocol = isdnprot;
icard.typ = ISDN_CTYPE_A1_PCMCIA;
i = hisax_init_pcmcia(link, &busy, &icard);
if (i < 0) {
printk(KERN_ERR "avma1_cs: failed to initialize AVM A1 "
"PCMCIA %d at i/o %#x\n", i,
(unsigned int) link->resource[0]->start);
avma1cs_release(link);
return -ENODEV;
}
link->priv = (void *) (unsigned long) i;
return 0;
}
static void avma1cs_release(struct pcmcia_device *link)
{
unsigned long minor = (unsigned long) link->priv;
dev_dbg(&link->dev, "avma1cs_release(0x%p)\n", link);
HiSax_closecard(minor);
pcmcia_disable_device(link);
}
static int __init init_avma1_cs(void)
{
return pcmcia_register_driver(&avma1cs_driver);
}
static void __exit exit_avma1_cs(void)
{
pcmcia_unregister_driver(&avma1cs_driver);
}
