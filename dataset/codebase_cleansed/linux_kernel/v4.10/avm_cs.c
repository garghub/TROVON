static int avmcs_probe(struct pcmcia_device *p_dev)
{
p_dev->config_flags |= CONF_ENABLE_IRQ | CONF_AUTO_SET_IO;
p_dev->config_index = 1;
p_dev->config_regs = PRESENT_OPTION;
return avmcs_config(p_dev);
}
static void avmcs_detach(struct pcmcia_device *link)
{
avmcs_release(link);
}
static int avmcs_configcheck(struct pcmcia_device *p_dev, void *priv_data)
{
p_dev->resource[0]->end = 16;
p_dev->resource[0]->flags &= ~IO_DATA_PATH_WIDTH;
p_dev->resource[0]->flags |= IO_DATA_PATH_WIDTH_8;
return pcmcia_request_io(p_dev);
}
static int avmcs_config(struct pcmcia_device *link)
{
int i = -1;
char devname[128];
int cardtype;
int (*addcard)(unsigned int port, unsigned irq);
devname[0] = 0;
if (link->prod_id[1])
strlcpy(devname, link->prod_id[1], sizeof(devname));
if (pcmcia_loop_config(link, avmcs_configcheck, NULL))
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
if (devname[0]) {
char *s = strrchr(devname, ' ');
if (!s)
s = devname;
else s++;
if (strcmp("M1", s) == 0) {
cardtype = AVM_CARDTYPE_M1;
} else if (strcmp("M2", s) == 0) {
cardtype = AVM_CARDTYPE_M2;
} else {
cardtype = AVM_CARDTYPE_B1;
}
} else
cardtype = AVM_CARDTYPE_B1;
if (i != 0) {
avmcs_release(link);
return -ENODEV;
}
switch (cardtype) {
case AVM_CARDTYPE_M1: addcard = b1pcmcia_addcard_m1; break;
case AVM_CARDTYPE_M2: addcard = b1pcmcia_addcard_m2; break;
default:
case AVM_CARDTYPE_B1: addcard = b1pcmcia_addcard_b1; break;
}
if ((i = (*addcard)(link->resource[0]->start, link->irq)) < 0) {
dev_err(&link->dev,
"avm_cs: failed to add AVM-Controller at i/o %#x, irq %d\n",
(unsigned int) link->resource[0]->start, link->irq);
avmcs_release(link);
return -ENODEV;
}
return 0;
}
static void avmcs_release(struct pcmcia_device *link)
{
b1pcmcia_delcard(link->resource[0]->start, link->irq);
pcmcia_disable_device(link);
}
