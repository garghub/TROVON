static int nanoengine_pcmcia_hw_init(struct soc_pcmcia_socket *skt)
{
unsigned i = skt->nr;
if (i >= num_nano_pcmcia_sockets)
return -ENXIO;
GPDR &= ~nano_skts[i].input_pins;
GPDR |= nano_skts[i].output_pins;
GPCR = nano_skts[i].clear_outputs;
irq_set_irq_type(nano_skts[i].transition_pins, IRQ_TYPE_EDGE_BOTH);
skt->socket.pci_irq = nano_skts[i].pci_irq;
return soc_pcmcia_request_irqs(skt,
nano_skts[i].pcmcia_irqs, nano_skts[i].pcmcia_irqs_size);
}
static void nanoengine_pcmcia_hw_shutdown(struct soc_pcmcia_socket *skt)
{
unsigned i = skt->nr;
if (i >= num_nano_pcmcia_sockets)
return;
soc_pcmcia_free_irqs(skt,
nano_skts[i].pcmcia_irqs, nano_skts[i].pcmcia_irqs_size);
}
static int nanoengine_pcmcia_configure_socket(
struct soc_pcmcia_socket *skt, const socket_state_t *state)
{
unsigned reset;
unsigned i = skt->nr;
if (i >= num_nano_pcmcia_sockets)
return -ENXIO;
switch (i) {
case 0:
reset = GPIO_PC_RESET0;
break;
case 1:
reset = GPIO_PC_RESET1;
break;
default:
return -ENXIO;
}
if (state->flags & SS_RESET)
GPSR = reset;
else
GPCR = reset;
return 0;
}
static void nanoengine_pcmcia_socket_state(
struct soc_pcmcia_socket *skt, struct pcmcia_state *state)
{
unsigned long levels = GPLR;
unsigned i = skt->nr;
if (i >= num_nano_pcmcia_sockets)
return;
memset(state, 0, sizeof(struct pcmcia_state));
switch (i) {
case 0:
state->ready = (levels & GPIO_PC_READY0) ? 1 : 0;
state->detect = !(levels & GPIO_PC_CD0) ? 1 : 0;
break;
case 1:
state->ready = (levels & GPIO_PC_READY1) ? 1 : 0;
state->detect = !(levels & GPIO_PC_CD1) ? 1 : 0;
break;
default:
return;
}
state->bvd1 = 1;
state->bvd2 = 1;
state->wrprot = 0;
state->vs_3v = 1;
state->vs_Xv = 0;
}
static void nanoengine_pcmcia_socket_init(struct soc_pcmcia_socket *skt)
{
unsigned i = skt->nr;
if (i >= num_nano_pcmcia_sockets)
return;
soc_pcmcia_enable_irqs(skt,
nano_skts[i].pcmcia_irqs, nano_skts[i].pcmcia_irqs_size);
}
static void nanoengine_pcmcia_socket_suspend(struct soc_pcmcia_socket *skt)
{
unsigned i = skt->nr;
if (i >= num_nano_pcmcia_sockets)
return;
soc_pcmcia_disable_irqs(skt,
nano_skts[i].pcmcia_irqs, nano_skts[i].pcmcia_irqs_size);
}
int pcmcia_nanoengine_init(struct device *dev)
{
int ret = -ENODEV;
if (machine_is_nanoengine())
ret = sa11xx_drv_pcmcia_probe(
dev, &nanoengine_pcmcia_ops, 0, 2);
return ret;
}
