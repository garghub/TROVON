static int hx4700_pcmcia_hw_init(struct soc_pcmcia_socket *skt)
{
int ret;
ret = gpio_request_array(gpios, ARRAY_SIZE(gpios));
if (ret)
goto out;
irq_set_irq_type(gpio_to_irq(GPIOD4_CF_nCD), IRQ_TYPE_EDGE_BOTH);
skt->stat[SOC_STAT_CD].gpio = GPIOD4_CF_nCD;
skt->stat[SOC_STAT_CD].name = "PCMCIA CD";
skt->stat[SOC_STAT_RDY].gpio = GPIO60_HX4700_CF_RNB;
skt->stat[SOC_STAT_RDY].name = "PCMCIA Ready";
out:
return ret;
}
static void hx4700_pcmcia_hw_shutdown(struct soc_pcmcia_socket *skt)
{
gpio_free_array(gpios, ARRAY_SIZE(gpios));
}
static void hx4700_pcmcia_socket_state(struct soc_pcmcia_socket *skt,
struct pcmcia_state *state)
{
state->vs_3v = 1;
state->vs_Xv = 0;
}
static int hx4700_pcmcia_configure_socket(struct soc_pcmcia_socket *skt,
const socket_state_t *state)
{
switch (state->Vcc) {
case 0:
gpio_set_value(EGPIO4_CF_3V3_ON, 0);
break;
case 33:
gpio_set_value(EGPIO4_CF_3V3_ON, 1);
break;
default:
printk(KERN_ERR "pcmcia: Unsupported Vcc: %d\n", state->Vcc);
return -EINVAL;
}
gpio_set_value(GPIO114_HX4700_CF_RESET, (state->flags & SS_RESET) != 0);
return 0;
}
static int __init hx4700_pcmcia_init(void)
{
struct platform_device *pdev;
if (!machine_is_h4700())
return -ENODEV;
pdev = platform_device_register_data(NULL, "pxa2xx-pcmcia", -1,
&hx4700_pcmcia_ops, sizeof(hx4700_pcmcia_ops));
if (IS_ERR(pdev))
return PTR_ERR(pdev);
hx4700_pcmcia_device = pdev;
return 0;
}
static void __exit hx4700_pcmcia_exit(void)
{
platform_device_unregister(hx4700_pcmcia_device);
}
