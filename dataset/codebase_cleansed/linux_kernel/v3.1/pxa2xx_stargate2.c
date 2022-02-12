static int sg2_pcmcia_hw_init(struct soc_pcmcia_socket *skt)
{
skt->socket.pci_irq = IRQ_GPIO(SG2_S0_GPIO_READY);
return soc_pcmcia_request_irqs(skt, irqs, ARRAY_SIZE(irqs));
}
static void sg2_pcmcia_hw_shutdown(struct soc_pcmcia_socket *skt)
{
soc_pcmcia_free_irqs(skt, irqs, ARRAY_SIZE(irqs));
}
static void sg2_pcmcia_socket_state(struct soc_pcmcia_socket *skt,
struct pcmcia_state *state)
{
state->detect = !gpio_get_value(SG2_S0_GPIO_DETECT);
state->ready = !!gpio_get_value(SG2_S0_GPIO_READY);
state->bvd1 = 0;
state->bvd2 = 0;
state->vs_3v = 1;
state->vs_Xv = 0;
state->wrprot = 0;
}
static int sg2_pcmcia_configure_socket(struct soc_pcmcia_socket *skt,
const socket_state_t *state)
{
switch (state->Vcc) {
case 0:
gpio_set_value(SG2_S0_POWER_CTL, 1);
break;
case 33:
case 50:
gpio_set_value(SG2_S0_POWER_CTL, 0);
msleep(100);
break;
default:
pr_err("%s(): bad Vcc %u\n",
__func__, state->Vcc);
return -1;
}
gpio_set_value(SG2_S0_GPIO_RESET, !!(state->flags & SS_RESET));
return 0;
}
static void sg2_pcmcia_socket_init(struct soc_pcmcia_socket *skt)
{
soc_pcmcia_enable_irqs(skt, irqs, ARRAY_SIZE(irqs));
}
static void sg2_pcmcia_socket_suspend(struct soc_pcmcia_socket *skt)
{
soc_pcmcia_disable_irqs(skt, irqs, ARRAY_SIZE(irqs));
}
static int __init sg2_pcmcia_init(void)
{
int ret;
if (!machine_is_stargate2())
return -ENODEV;
sg2_pcmcia_device = platform_device_alloc("pxa2xx-pcmcia", -1);
if (!sg2_pcmcia_device)
return -ENOMEM;
ret = gpio_request_array(sg2_pcmcia_gpios, ARRAY_SIZE(sg2_pcmcia_gpios));
if (ret)
goto error_put_platform_device;
ret = platform_device_add_data(sg2_pcmcia_device,
&sg2_pcmcia_ops,
sizeof(sg2_pcmcia_ops));
if (ret)
goto error_free_gpios;
ret = platform_device_add(sg2_pcmcia_device);
if (ret)
goto error_free_gpios;
return 0;
error_free_gpios:
gpio_free_array(sg2_pcmcia_gpios, ARRAY_SIZE(sg2_pcmcia_gpios));
error_put_platform_device:
platform_device_put(sg2_pcmcia_device);
return ret;
}
static void __exit sg2_pcmcia_exit(void)
{
platform_device_unregister(sg2_pcmcia_device);
gpio_free_array(sg2_pcmcia_gpios, ARRAY_SIZE(sg2_pcmcia_gpios));
}
