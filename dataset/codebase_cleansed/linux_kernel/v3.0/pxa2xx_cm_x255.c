static int cmx255_pcmcia_hw_init(struct soc_pcmcia_socket *skt)
{
int ret = gpio_request(GPIO_PCMCIA_RESET, "PCCard reset");
if (ret)
return ret;
gpio_direction_output(GPIO_PCMCIA_RESET, 0);
skt->socket.pci_irq = skt->nr == 0 ? PCMCIA_S0_RDYINT : PCMCIA_S1_RDYINT;
ret = soc_pcmcia_request_irqs(skt, irqs, ARRAY_SIZE(irqs));
if (!ret)
gpio_free(GPIO_PCMCIA_RESET);
return ret;
}
static void cmx255_pcmcia_shutdown(struct soc_pcmcia_socket *skt)
{
soc_pcmcia_free_irqs(skt, irqs, ARRAY_SIZE(irqs));
gpio_free(GPIO_PCMCIA_RESET);
}
static void cmx255_pcmcia_socket_state(struct soc_pcmcia_socket *skt,
struct pcmcia_state *state)
{
int cd = skt->nr ? GPIO_PCMCIA_S1_CD_VALID : GPIO_PCMCIA_S0_CD_VALID;
int rdy = skt->nr ? GPIO_PCMCIA_S1_RDYINT : GPIO_PCMCIA_S0_RDYINT;
state->detect = !gpio_get_value(cd);
state->ready = !!gpio_get_value(rdy);
state->bvd1 = 1;
state->bvd2 = 1;
state->vs_3v = 0;
state->vs_Xv = 0;
state->wrprot = 0;
}
static int cmx255_pcmcia_configure_socket(struct soc_pcmcia_socket *skt,
const socket_state_t *state)
{
switch (skt->nr) {
case 0:
if (state->flags & SS_RESET) {
gpio_set_value(GPIO_PCMCIA_SKTSEL, 0);
udelay(1);
gpio_set_value(GPIO_PCMCIA_RESET, 1);
udelay(10);
gpio_set_value(GPIO_PCMCIA_RESET, 0);
}
break;
case 1:
if (state->flags & SS_RESET) {
gpio_set_value(GPIO_PCMCIA_SKTSEL, 1);
udelay(1);
gpio_set_value(GPIO_PCMCIA_RESET, 1);
udelay(10);
gpio_set_value(GPIO_PCMCIA_RESET, 0);
}
break;
}
return 0;
}
static void cmx255_pcmcia_socket_init(struct soc_pcmcia_socket *skt)
{
}
static void cmx255_pcmcia_socket_suspend(struct soc_pcmcia_socket *skt)
{
}
int __init cmx255_pcmcia_init(void)
{
int ret;
cmx255_pcmcia_device = platform_device_alloc("pxa2xx-pcmcia", -1);
if (!cmx255_pcmcia_device)
return -ENOMEM;
ret = platform_device_add_data(cmx255_pcmcia_device, &cmx255_pcmcia_ops,
sizeof(cmx255_pcmcia_ops));
if (ret == 0) {
printk(KERN_INFO "Registering cm-x255 PCMCIA interface.\n");
ret = platform_device_add(cmx255_pcmcia_device);
}
if (ret)
platform_device_put(cmx255_pcmcia_device);
return ret;
}
void __exit cmx255_pcmcia_exit(void)
{
platform_device_unregister(cmx255_pcmcia_device);
}
