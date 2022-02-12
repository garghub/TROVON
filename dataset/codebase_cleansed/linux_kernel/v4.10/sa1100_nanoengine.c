static int nanoengine_pcmcia_hw_init(struct soc_pcmcia_socket *skt)
{
unsigned i = skt->nr;
int ret;
if (i >= num_nano_pcmcia_sockets)
return -ENXIO;
ret = gpio_request_one(nano_skts[i].gpio_rst, GPIOF_OUT_INIT_LOW,
i ? "PC RST1" : "PC RST0");
if (ret)
return ret;
skt->stat[SOC_STAT_CD].gpio = nano_skts[i].gpio_cd;
skt->stat[SOC_STAT_CD].name = i ? "PC CD1" : "PC CD0";
skt->stat[SOC_STAT_RDY].gpio = nano_skts[i].gpio_rdy;
skt->stat[SOC_STAT_RDY].name = i ? "PC RDY1" : "PC RDY0";
return 0;
}
static void nanoengine_pcmcia_hw_shutdown(struct soc_pcmcia_socket *skt)
{
gpio_free(nano_skts[skt->nr].gpio_rst);
}
static int nanoengine_pcmcia_configure_socket(
struct soc_pcmcia_socket *skt, const socket_state_t *state)
{
unsigned i = skt->nr;
if (i >= num_nano_pcmcia_sockets)
return -ENXIO;
gpio_set_value(nano_skts[skt->nr].gpio_rst, !!(state->flags & SS_RESET));
return 0;
}
static void nanoengine_pcmcia_socket_state(
struct soc_pcmcia_socket *skt, struct pcmcia_state *state)
{
unsigned i = skt->nr;
if (i >= num_nano_pcmcia_sockets)
return;
state->bvd1 = 1;
state->bvd2 = 1;
state->vs_3v = 1;
state->vs_Xv = 0;
}
int pcmcia_nanoengine_init(struct device *dev)
{
int ret = -ENODEV;
if (machine_is_nanoengine())
ret = sa11xx_drv_pcmcia_probe(
dev, &nanoengine_pcmcia_ops, 0, 2);
return ret;
}
