static int vpac270_pcmcia_hw_init(struct soc_pcmcia_socket *skt)
{
int ret;
if (skt->nr == 0) {
ret = gpio_request_array(vpac270_pcmcia_gpios,
ARRAY_SIZE(vpac270_pcmcia_gpios));
skt->stat[SOC_STAT_CD].gpio = GPIO84_VPAC270_PCMCIA_CD;
skt->stat[SOC_STAT_CD].name = "PCMCIA CD";
skt->stat[SOC_STAT_RDY].gpio = GPIO35_VPAC270_PCMCIA_RDY;
skt->stat[SOC_STAT_RDY].name = "PCMCIA Ready";
} else {
ret = gpio_request_array(vpac270_cf_gpios,
ARRAY_SIZE(vpac270_cf_gpios));
skt->stat[SOC_STAT_CD].gpio = GPIO17_VPAC270_CF_CD;
skt->stat[SOC_STAT_CD].name = "CF CD";
skt->stat[SOC_STAT_RDY].gpio = GPIO12_VPAC270_CF_RDY;
skt->stat[SOC_STAT_RDY].name = "CF Ready";
}
return ret;
}
static void vpac270_pcmcia_hw_shutdown(struct soc_pcmcia_socket *skt)
{
if (skt->nr == 0)
gpio_free_array(vpac270_pcmcia_gpios,
ARRAY_SIZE(vpac270_pcmcia_gpios));
else
gpio_free_array(vpac270_cf_gpios,
ARRAY_SIZE(vpac270_cf_gpios));
}
static void vpac270_pcmcia_socket_state(struct soc_pcmcia_socket *skt,
struct pcmcia_state *state)
{
state->vs_3v = 1;
state->vs_Xv = 0;
}
static int
vpac270_pcmcia_configure_socket(struct soc_pcmcia_socket *skt,
const socket_state_t *state)
{
if (skt->nr == 0) {
gpio_set_value(GPIO11_VPAC270_PCMCIA_RESET,
(state->flags & SS_RESET));
gpio_set_value(GPIO107_VPAC270_PCMCIA_PPEN,
!(state->Vcc == 33 || state->Vcc == 50));
} else {
gpio_set_value(GPIO16_VPAC270_CF_RESET,
(state->flags & SS_RESET));
}
return 0;
}
static int __init vpac270_pcmcia_init(void)
{
int ret;
if (!machine_is_vpac270())
return -ENODEV;
vpac270_pcmcia_device = platform_device_alloc("pxa2xx-pcmcia", -1);
if (!vpac270_pcmcia_device)
return -ENOMEM;
ret = platform_device_add_data(vpac270_pcmcia_device,
&vpac270_pcmcia_ops, sizeof(vpac270_pcmcia_ops));
if (!ret)
ret = platform_device_add(vpac270_pcmcia_device);
if (ret)
platform_device_put(vpac270_pcmcia_device);
return ret;
}
static void __exit vpac270_pcmcia_exit(void)
{
platform_device_unregister(vpac270_pcmcia_device);
}
