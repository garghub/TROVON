static int cmx255_pcmcia_hw_init(struct soc_pcmcia_socket *skt)
{
int ret = gpio_request(GPIO_PCMCIA_RESET, "PCCard reset");
if (ret)
return ret;
gpio_direction_output(GPIO_PCMCIA_RESET, 0);
if (skt->nr == 0) {
skt->stat[SOC_STAT_CD].gpio = GPIO_PCMCIA_S0_CD_VALID;
skt->stat[SOC_STAT_CD].name = "PCMCIA0 CD";
skt->stat[SOC_STAT_RDY].gpio = GPIO_PCMCIA_S0_RDYINT;
skt->stat[SOC_STAT_RDY].name = "PCMCIA0 RDY";
} else {
skt->stat[SOC_STAT_CD].gpio = GPIO_PCMCIA_S1_CD_VALID;
skt->stat[SOC_STAT_CD].name = "PCMCIA1 CD";
skt->stat[SOC_STAT_RDY].gpio = GPIO_PCMCIA_S1_RDYINT;
skt->stat[SOC_STAT_RDY].name = "PCMCIA1 RDY";
}
return 0;
}
static void cmx255_pcmcia_shutdown(struct soc_pcmcia_socket *skt)
{
gpio_free(GPIO_PCMCIA_RESET);
}
static void cmx255_pcmcia_socket_state(struct soc_pcmcia_socket *skt,
struct pcmcia_state *state)
{
state->vs_3v = 0;
state->vs_Xv = 0;
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
