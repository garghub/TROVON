static int e740_pcmcia_hw_init(struct soc_pcmcia_socket *skt)
{
skt->socket.pci_irq = skt->nr == 0 ? IRQ_GPIO(GPIO_E740_PCMCIA_RDY0) :
IRQ_GPIO(GPIO_E740_PCMCIA_RDY1);
return soc_pcmcia_request_irqs(skt, &cd_irqs[skt->nr], 1);
}
static void e740_pcmcia_hw_shutdown(struct soc_pcmcia_socket *skt)
{
soc_pcmcia_free_irqs(skt, &cd_irqs[skt->nr], 1);
}
static void e740_pcmcia_socket_state(struct soc_pcmcia_socket *skt,
struct pcmcia_state *state)
{
if (skt->nr == 0) {
state->detect = gpio_get_value(GPIO_E740_PCMCIA_CD0) ? 0 : 1;
state->ready = gpio_get_value(GPIO_E740_PCMCIA_RDY0) ? 1 : 0;
} else {
state->detect = gpio_get_value(GPIO_E740_PCMCIA_CD1) ? 0 : 1;
state->ready = gpio_get_value(GPIO_E740_PCMCIA_RDY1) ? 1 : 0;
}
state->vs_3v = 1;
state->bvd1 = 1;
state->bvd2 = 1;
state->wrprot = 0;
state->vs_Xv = 0;
}
static int e740_pcmcia_configure_socket(struct soc_pcmcia_socket *skt,
const socket_state_t *state)
{
if (state->flags & SS_RESET) {
if (skt->nr == 0)
gpio_set_value(GPIO_E740_PCMCIA_RST0, 1);
else
gpio_set_value(GPIO_E740_PCMCIA_RST1, 1);
} else {
if (skt->nr == 0)
gpio_set_value(GPIO_E740_PCMCIA_RST0, 0);
else
gpio_set_value(GPIO_E740_PCMCIA_RST1, 0);
}
switch (state->Vcc) {
case 0:
if (skt->nr == 0)
gpio_set_value(GPIO_E740_PCMCIA_PWR0, 0);
else
gpio_set_value(GPIO_E740_PCMCIA_PWR1, 1);
break;
case 50:
case 33:
if (skt->nr == 0)
gpio_set_value(GPIO_E740_PCMCIA_PWR0, 1);
else
gpio_set_value(GPIO_E740_PCMCIA_PWR1, 0);
break;
default:
printk(KERN_ERR "e740_cs: Unsupported Vcc: %d\n", state->Vcc);
}
return 0;
}
static void e740_pcmcia_socket_init(struct soc_pcmcia_socket *skt)
{
soc_pcmcia_enable_irqs(skt, cd_irqs, ARRAY_SIZE(cd_irqs));
}
static void e740_pcmcia_socket_suspend(struct soc_pcmcia_socket *skt)
{
soc_pcmcia_disable_irqs(skt, cd_irqs, ARRAY_SIZE(cd_irqs));
}
static int __init e740_pcmcia_init(void)
{
int ret;
if (!machine_is_e740())
return -ENODEV;
e740_pcmcia_device = platform_device_alloc("pxa2xx-pcmcia", -1);
if (!e740_pcmcia_device)
return -ENOMEM;
ret = platform_device_add_data(e740_pcmcia_device, &e740_pcmcia_ops,
sizeof(e740_pcmcia_ops));
if (!ret)
ret = platform_device_add(e740_pcmcia_device);
if (ret)
platform_device_put(e740_pcmcia_device);
return ret;
}
static void __exit e740_pcmcia_exit(void)
{
platform_device_unregister(e740_pcmcia_device);
}
