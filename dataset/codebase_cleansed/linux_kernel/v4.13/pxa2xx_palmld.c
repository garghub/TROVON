static int palmld_pcmcia_hw_init(struct soc_pcmcia_socket *skt)
{
int ret;
ret = gpio_request_array(palmld_pcmcia_gpios,
ARRAY_SIZE(palmld_pcmcia_gpios));
skt->stat[SOC_STAT_RDY].gpio = GPIO_NR_PALMLD_PCMCIA_READY;
skt->stat[SOC_STAT_RDY].name = "PCMCIA Ready";
return ret;
}
static void palmld_pcmcia_hw_shutdown(struct soc_pcmcia_socket *skt)
{
gpio_free_array(palmld_pcmcia_gpios, ARRAY_SIZE(palmld_pcmcia_gpios));
}
static void palmld_pcmcia_socket_state(struct soc_pcmcia_socket *skt,
struct pcmcia_state *state)
{
state->detect = 1;
state->vs_3v = 1;
state->vs_Xv = 0;
}
static int palmld_pcmcia_configure_socket(struct soc_pcmcia_socket *skt,
const socket_state_t *state)
{
gpio_set_value(GPIO_NR_PALMLD_PCMCIA_POWER, 1);
gpio_set_value(GPIO_NR_PALMLD_PCMCIA_RESET,
!!(state->flags & SS_RESET));
return 0;
}
static int __init palmld_pcmcia_init(void)
{
int ret;
if (!machine_is_palmld())
return -ENODEV;
palmld_pcmcia_device = platform_device_alloc("pxa2xx-pcmcia", -1);
if (!palmld_pcmcia_device)
return -ENOMEM;
ret = platform_device_add_data(palmld_pcmcia_device, &palmld_pcmcia_ops,
sizeof(palmld_pcmcia_ops));
if (!ret)
ret = platform_device_add(palmld_pcmcia_device);
if (ret)
platform_device_put(palmld_pcmcia_device);
return ret;
}
static void __exit palmld_pcmcia_exit(void)
{
platform_device_unregister(palmld_pcmcia_device);
}
