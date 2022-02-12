static int palmtx_pcmcia_hw_init(struct soc_pcmcia_socket *skt)
{
int ret;
ret = gpio_request_array(palmtx_pcmcia_gpios,
ARRAY_SIZE(palmtx_pcmcia_gpios));
skt->socket.pci_irq = gpio_to_irq(GPIO_NR_PALMTX_PCMCIA_READY);
return ret;
}
static void palmtx_pcmcia_hw_shutdown(struct soc_pcmcia_socket *skt)
{
gpio_free_array(palmtx_pcmcia_gpios, ARRAY_SIZE(palmtx_pcmcia_gpios));
}
static void palmtx_pcmcia_socket_state(struct soc_pcmcia_socket *skt,
struct pcmcia_state *state)
{
state->detect = 1;
state->ready = !!gpio_get_value(GPIO_NR_PALMTX_PCMCIA_READY);
state->bvd1 = 1;
state->bvd2 = 1;
state->wrprot = 0;
state->vs_3v = 1;
state->vs_Xv = 0;
}
static int
palmtx_pcmcia_configure_socket(struct soc_pcmcia_socket *skt,
const socket_state_t *state)
{
gpio_set_value(GPIO_NR_PALMTX_PCMCIA_POWER1, 1);
gpio_set_value(GPIO_NR_PALMTX_PCMCIA_POWER2, 1);
gpio_set_value(GPIO_NR_PALMTX_PCMCIA_RESET,
!!(state->flags & SS_RESET));
return 0;
}
static int __init palmtx_pcmcia_init(void)
{
int ret;
if (!machine_is_palmtx())
return -ENODEV;
palmtx_pcmcia_device = platform_device_alloc("pxa2xx-pcmcia", -1);
if (!palmtx_pcmcia_device)
return -ENOMEM;
ret = platform_device_add_data(palmtx_pcmcia_device, &palmtx_pcmcia_ops,
sizeof(palmtx_pcmcia_ops));
if (!ret)
ret = platform_device_add(palmtx_pcmcia_device);
if (ret)
platform_device_put(palmtx_pcmcia_device);
return ret;
}
static void __exit palmtx_pcmcia_exit(void)
{
platform_device_unregister(palmtx_pcmcia_device);
}
