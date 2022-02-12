static int cerf_pcmcia_hw_init(struct soc_pcmcia_socket *skt)
{
skt->socket.pci_irq = CERF_IRQ_GPIO_CF_IRQ;
return soc_pcmcia_request_irqs(skt, irqs, ARRAY_SIZE(irqs));
}
static void cerf_pcmcia_hw_shutdown(struct soc_pcmcia_socket *skt)
{
soc_pcmcia_free_irqs(skt, irqs, ARRAY_SIZE(irqs));
}
static void
cerf_pcmcia_socket_state(struct soc_pcmcia_socket *skt, struct pcmcia_state *state)
{
unsigned long levels = GPLR;
state->detect = (levels & CERF_GPIO_CF_CD) ?0:1;
state->ready = (levels & CERF_GPIO_CF_IRQ) ?1:0;
state->bvd1 = (levels & CERF_GPIO_CF_BVD1)?1:0;
state->bvd2 = (levels & CERF_GPIO_CF_BVD2)?1:0;
state->wrprot = 0;
state->vs_3v = 1;
state->vs_Xv = 0;
}
static int
cerf_pcmcia_configure_socket(struct soc_pcmcia_socket *skt,
const socket_state_t *state)
{
switch (state->Vcc) {
case 0:
case 50:
case 33:
break;
default:
printk(KERN_ERR "%s(): unrecognized Vcc %u\n",
__func__, state->Vcc);
return -1;
}
if (state->flags & SS_RESET) {
GPSR = CERF_GPIO_CF_RESET;
} else {
GPCR = CERF_GPIO_CF_RESET;
}
return 0;
}
static void cerf_pcmcia_socket_init(struct soc_pcmcia_socket *skt)
{
soc_pcmcia_enable_irqs(skt, irqs, ARRAY_SIZE(irqs));
}
static void cerf_pcmcia_socket_suspend(struct soc_pcmcia_socket *skt)
{
soc_pcmcia_disable_irqs(skt, irqs, ARRAY_SIZE(irqs));
}
int __devinit pcmcia_cerf_init(struct device *dev)
{
int ret = -ENODEV;
if (machine_is_cerf())
ret = sa11xx_drv_pcmcia_probe(dev, &cerf_pcmcia_ops, CERF_SOCKET, 1);
return ret;
}
