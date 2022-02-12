static int palmtc_pcmcia_hw_init(struct soc_pcmcia_socket *skt)
{
int ret;
ret = gpio_request_array(palmtc_pcmcia_gpios,
ARRAY_SIZE(palmtc_pcmcia_gpios));
skt->socket.pci_irq = IRQ_GPIO(GPIO_NR_PALMTC_PCMCIA_READY);
return ret;
}
static void palmtc_pcmcia_hw_shutdown(struct soc_pcmcia_socket *skt)
{
gpio_free_array(palmtc_pcmcia_gpios, ARRAY_SIZE(palmtc_pcmcia_gpios));
}
static void palmtc_pcmcia_socket_state(struct soc_pcmcia_socket *skt,
struct pcmcia_state *state)
{
state->detect = 1;
state->ready = !!gpio_get_value(GPIO_NR_PALMTC_PCMCIA_READY);
state->bvd1 = 1;
state->bvd2 = 1;
state->wrprot = 0;
state->vs_3v = 1;
state->vs_Xv = 0;
}
static int palmtc_wifi_powerdown(void)
{
gpio_set_value(GPIO_NR_PALMTC_PCMCIA_RESET, 1);
gpio_set_value(GPIO_NR_PALMTC_PCMCIA_POWER2, 0);
mdelay(40);
gpio_set_value(GPIO_NR_PALMTC_PCMCIA_POWER1, 0);
return 0;
}
static int palmtc_wifi_powerup(void)
{
int timeout = 50;
gpio_set_value(GPIO_NR_PALMTC_PCMCIA_POWER3, 1);
mdelay(50);
gpio_set_value(GPIO_NR_PALMTC_PCMCIA_POWER1, 1);
mdelay(100);
gpio_set_value(GPIO_NR_PALMTC_PCMCIA_POWER2, 1);
while (!gpio_get_value(GPIO_NR_PALMTC_PCMCIA_PWRREADY) &&
timeout) {
mdelay(1);
timeout--;
}
if (!timeout) {
palmtc_wifi_powerdown();
return 1;
}
gpio_set_value(GPIO_NR_PALMTC_PCMCIA_RESET, 1);
mdelay(20);
gpio_set_value(GPIO_NR_PALMTC_PCMCIA_RESET, 0);
mdelay(25);
gpio_set_value(GPIO_NR_PALMTC_PCMCIA_POWER3, 0);
return 0;
}
static int palmtc_pcmcia_configure_socket(struct soc_pcmcia_socket *skt,
const socket_state_t *state)
{
int ret = 1;
if (state->Vcc == 0)
ret = palmtc_wifi_powerdown();
else if (state->Vcc == 33)
ret = palmtc_wifi_powerup();
return ret;
}
static int __init palmtc_pcmcia_init(void)
{
int ret;
if (!machine_is_palmtc())
return -ENODEV;
palmtc_pcmcia_device = platform_device_alloc("pxa2xx-pcmcia", -1);
if (!palmtc_pcmcia_device)
return -ENOMEM;
ret = platform_device_add_data(palmtc_pcmcia_device, &palmtc_pcmcia_ops,
sizeof(palmtc_pcmcia_ops));
if (!ret)
ret = platform_device_add(palmtc_pcmcia_device);
if (ret)
platform_device_put(palmtc_pcmcia_device);
return ret;
}
static void __exit palmtc_pcmcia_exit(void)
{
platform_device_unregister(palmtc_pcmcia_device);
}
