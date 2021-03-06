static int cmx270_pcmcia_hw_init(struct soc_pcmcia_socket *skt)
{
int ret = gpio_request(GPIO_PCMCIA_RESET, "PCCard reset");
if (ret)
return ret;
gpio_direction_output(GPIO_PCMCIA_RESET, 0);
skt->socket.pci_irq = PCMCIA_S0_RDYINT;
irqs[0].irq = PCMCIA_S0_CD_VALID;
ret = soc_pcmcia_request_irqs(skt, irqs, ARRAY_SIZE(irqs));
if (!ret)
gpio_free(GPIO_PCMCIA_RESET);
return ret;
}
static void cmx270_pcmcia_shutdown(struct soc_pcmcia_socket *skt)
{
soc_pcmcia_free_irqs(skt, irqs, ARRAY_SIZE(irqs));
gpio_free(GPIO_PCMCIA_RESET);
}
static void cmx270_pcmcia_socket_state(struct soc_pcmcia_socket *skt,
struct pcmcia_state *state)
{
state->detect = (gpio_get_value(GPIO_PCMCIA_S0_CD_VALID) == 0) ? 1 : 0;
state->ready = (gpio_get_value(GPIO_PCMCIA_S0_RDYINT) == 0) ? 0 : 1;
state->bvd1 = 1;
state->bvd2 = 1;
state->vs_3v = 0;
state->vs_Xv = 0;
state->wrprot = 0;
}
static int cmx270_pcmcia_configure_socket(struct soc_pcmcia_socket *skt,
const socket_state_t *state)
{
switch (skt->nr) {
case 0:
if (state->flags & SS_RESET) {
gpio_set_value(GPIO_PCMCIA_RESET, 1);
udelay(10);
gpio_set_value(GPIO_PCMCIA_RESET, 0);
}
break;
}
return 0;
}
int __init cmx270_pcmcia_init(void)
{
int ret;
cmx270_pcmcia_device = platform_device_alloc("pxa2xx-pcmcia", -1);
if (!cmx270_pcmcia_device)
return -ENOMEM;
ret = platform_device_add_data(cmx270_pcmcia_device, &cmx270_pcmcia_ops,
sizeof(cmx270_pcmcia_ops));
if (ret == 0) {
printk(KERN_INFO "Registering cm-x270 PCMCIA interface.\n");
ret = platform_device_add(cmx270_pcmcia_device);
}
if (ret)
platform_device_put(cmx270_pcmcia_device);
return ret;
}
void __exit cmx270_pcmcia_exit(void)
{
platform_device_unregister(cmx270_pcmcia_device);
}
