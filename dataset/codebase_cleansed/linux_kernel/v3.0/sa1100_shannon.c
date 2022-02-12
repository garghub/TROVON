static int shannon_pcmcia_hw_init(struct soc_pcmcia_socket *skt)
{
GPDR &= ~(SHANNON_GPIO_EJECT_0 | SHANNON_GPIO_EJECT_1 |
SHANNON_GPIO_RDY_0 | SHANNON_GPIO_RDY_1);
GAFR &= ~(SHANNON_GPIO_EJECT_0 | SHANNON_GPIO_EJECT_1 |
SHANNON_GPIO_RDY_0 | SHANNON_GPIO_RDY_1);
skt->socket.pci_irq = skt->nr ? SHANNON_IRQ_GPIO_RDY_1 : SHANNON_IRQ_GPIO_RDY_0;
return soc_pcmcia_request_irqs(skt, irqs, ARRAY_SIZE(irqs));
}
static void shannon_pcmcia_hw_shutdown(struct soc_pcmcia_socket *skt)
{
soc_pcmcia_free_irqs(skt, irqs, ARRAY_SIZE(irqs));
}
static void
shannon_pcmcia_socket_state(struct soc_pcmcia_socket *skt,
struct pcmcia_state *state)
{
unsigned long levels = GPLR;
switch (skt->nr) {
case 0:
state->detect = (levels & SHANNON_GPIO_EJECT_0) ? 0 : 1;
state->ready = (levels & SHANNON_GPIO_RDY_0) ? 1 : 0;
state->wrprot = 0;
state->bvd1 = 1;
state->bvd2 = 1;
state->vs_3v = 1;
state->vs_Xv = 0;
break;
case 1:
state->detect = (levels & SHANNON_GPIO_EJECT_1) ? 0 : 1;
state->ready = (levels & SHANNON_GPIO_RDY_1) ? 1 : 0;
state->wrprot = 0;
state->bvd1 = 1;
state->bvd2 = 1;
state->vs_3v = 1;
state->vs_Xv = 0;
break;
}
}
static int
shannon_pcmcia_configure_socket(struct soc_pcmcia_socket *skt,
const socket_state_t *state)
{
switch (state->Vcc) {
case 0:
printk(KERN_WARNING "%s(): CS asked for 0V, still applying 3.3V..\n", __func__);
break;
case 50:
printk(KERN_WARNING "%s(): CS asked for 5V, applying 3.3V..\n", __func__);
case 33:
break;
default:
printk(KERN_ERR "%s(): unrecognized Vcc %u\n",
__func__, state->Vcc);
return -1;
}
printk(KERN_WARNING "%s(): Warning, Can't perform reset\n", __func__);
return 0;
}
static void shannon_pcmcia_socket_init(struct soc_pcmcia_socket *skt)
{
soc_pcmcia_enable_irqs(skt, irqs, ARRAY_SIZE(irqs));
}
static void shannon_pcmcia_socket_suspend(struct soc_pcmcia_socket *skt)
{
soc_pcmcia_disable_irqs(skt, irqs, ARRAY_SIZE(irqs));
}
int __devinit pcmcia_shannon_init(struct device *dev)
{
int ret = -ENODEV;
if (machine_is_shannon())
ret = sa11xx_drv_pcmcia_probe(dev, &shannon_pcmcia_ops, 0, 2);
return ret;
}
