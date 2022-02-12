static int assabet_pcmcia_hw_init(struct soc_pcmcia_socket *skt)
{
skt->socket.pci_irq = ASSABET_IRQ_GPIO_CF_IRQ;
return soc_pcmcia_request_irqs(skt, irqs, ARRAY_SIZE(irqs));
}
static void assabet_pcmcia_hw_shutdown(struct soc_pcmcia_socket *skt)
{
soc_pcmcia_free_irqs(skt, irqs, ARRAY_SIZE(irqs));
}
static void
assabet_pcmcia_socket_state(struct soc_pcmcia_socket *skt, struct pcmcia_state *state)
{
unsigned long levels = GPLR;
state->detect = (levels & ASSABET_GPIO_CF_CD) ? 0 : 1;
state->ready = (levels & ASSABET_GPIO_CF_IRQ) ? 1 : 0;
state->bvd1 = (levels & ASSABET_GPIO_CF_BVD1) ? 1 : 0;
state->bvd2 = (levels & ASSABET_GPIO_CF_BVD2) ? 1 : 0;
state->wrprot = 0;
state->vs_3v = 1;
state->vs_Xv = 0;
}
static int
assabet_pcmcia_configure_socket(struct soc_pcmcia_socket *skt, const socket_state_t *state)
{
unsigned int mask;
switch (state->Vcc) {
case 0:
mask = 0;
break;
case 50:
printk(KERN_WARNING "%s(): CS asked for 5V, applying 3.3V...\n",
__func__);
case 33:
mask = ASSABET_BCR_CF_PWR;
break;
default:
printk(KERN_ERR "%s(): unrecognized Vcc %u\n", __func__,
state->Vcc);
return -1;
}
if (state->flags & SS_RESET)
mask |= ASSABET_BCR_CF_RST;
ASSABET_BCR_frob(ASSABET_BCR_CF_RST | ASSABET_BCR_CF_PWR, mask);
return 0;
}
static void assabet_pcmcia_socket_init(struct soc_pcmcia_socket *skt)
{
ASSABET_BCR_clear(ASSABET_BCR_CF_BUS_OFF);
soc_pcmcia_enable_irqs(skt, irqs, ARRAY_SIZE(irqs));
}
static void assabet_pcmcia_socket_suspend(struct soc_pcmcia_socket *skt)
{
soc_pcmcia_disable_irqs(skt, irqs, ARRAY_SIZE(irqs));
ASSABET_BCR_set(ASSABET_BCR_CF_BUS_OFF | ASSABET_BCR_CF_RST);
}
int __devinit pcmcia_assabet_init(struct device *dev)
{
int ret = -ENODEV;
if (machine_is_assabet() && !machine_has_neponset())
ret = sa11xx_drv_pcmcia_probe(dev, &assabet_pcmcia_ops, 1, 1);
return ret;
}
