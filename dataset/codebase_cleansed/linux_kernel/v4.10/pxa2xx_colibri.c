static int colibri_pcmcia_hw_init(struct soc_pcmcia_socket *skt)
{
int ret;
ret = gpio_request_array(colibri_pcmcia_gpios,
ARRAY_SIZE(colibri_pcmcia_gpios));
if (ret)
goto err1;
skt->socket.pci_irq = gpio_to_irq(colibri_pcmcia_gpios[READY].gpio);
skt->stat[SOC_STAT_CD].irq = gpio_to_irq(colibri_pcmcia_gpios[DETECT].gpio);
skt->stat[SOC_STAT_CD].name = "PCMCIA CD";
err1:
return ret;
}
static void colibri_pcmcia_hw_shutdown(struct soc_pcmcia_socket *skt)
{
gpio_free_array(colibri_pcmcia_gpios,
ARRAY_SIZE(colibri_pcmcia_gpios));
}
static void colibri_pcmcia_socket_state(struct soc_pcmcia_socket *skt,
struct pcmcia_state *state)
{
state->detect = !!gpio_get_value(colibri_pcmcia_gpios[DETECT].gpio);
state->ready = !!gpio_get_value(colibri_pcmcia_gpios[READY].gpio);
state->bvd1 = !!gpio_get_value(colibri_pcmcia_gpios[BVD1].gpio);
state->bvd2 = !!gpio_get_value(colibri_pcmcia_gpios[BVD2].gpio);
state->vs_3v = 1;
state->vs_Xv = 0;
}
static int
colibri_pcmcia_configure_socket(struct soc_pcmcia_socket *skt,
const socket_state_t *state)
{
gpio_set_value(colibri_pcmcia_gpios[PPEN].gpio,
!(state->Vcc == 33 && state->Vpp < 50));
gpio_set_value(colibri_pcmcia_gpios[RESET].gpio,
state->flags & SS_RESET);
return 0;
}
static int __init colibri_pcmcia_init(void)
{
int ret;
if (!machine_is_colibri() && !machine_is_colibri320())
return -ENODEV;
colibri_pcmcia_device = platform_device_alloc("pxa2xx-pcmcia", -1);
if (!colibri_pcmcia_device)
return -ENOMEM;
if (machine_is_colibri()) {
colibri_pcmcia_gpios[RESET].gpio = COLIBRI270_RESET_GPIO;
colibri_pcmcia_gpios[PPEN].gpio = COLIBRI270_PPEN_GPIO;
colibri_pcmcia_gpios[BVD1].gpio = COLIBRI270_BVD1_GPIO;
colibri_pcmcia_gpios[BVD2].gpio = COLIBRI270_BVD2_GPIO;
colibri_pcmcia_gpios[DETECT].gpio = COLIBRI270_DETECT_GPIO;
colibri_pcmcia_gpios[READY].gpio = COLIBRI270_READY_GPIO;
} else if (machine_is_colibri320()) {
colibri_pcmcia_gpios[RESET].gpio = COLIBRI320_RESET_GPIO;
colibri_pcmcia_gpios[PPEN].gpio = COLIBRI320_PPEN_GPIO;
colibri_pcmcia_gpios[BVD1].gpio = COLIBRI320_BVD1_GPIO;
colibri_pcmcia_gpios[BVD2].gpio = COLIBRI320_BVD2_GPIO;
colibri_pcmcia_gpios[DETECT].gpio = COLIBRI320_DETECT_GPIO;
colibri_pcmcia_gpios[READY].gpio = COLIBRI320_READY_GPIO;
}
ret = platform_device_add_data(colibri_pcmcia_device,
&colibri_pcmcia_ops, sizeof(colibri_pcmcia_ops));
if (!ret)
ret = platform_device_add(colibri_pcmcia_device);
if (ret)
platform_device_put(colibri_pcmcia_device);
return ret;
}
static void __exit colibri_pcmcia_exit(void)
{
platform_device_unregister(colibri_pcmcia_device);
}
