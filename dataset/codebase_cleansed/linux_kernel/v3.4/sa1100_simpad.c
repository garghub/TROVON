static int simpad_pcmcia_hw_init(struct soc_pcmcia_socket *skt)
{
simpad_clear_cs3_bit(VCC_3V_EN|VCC_5V_EN|EN0|EN1);
skt->stat[SOC_STAT_CD].gpio = GPIO_CF_CD;
skt->stat[SOC_STAT_CD].name = "CF_CD";
skt->stat[SOC_STAT_RDY].gpio = GPIO_CF_IRQ;
skt->stat[SOC_STAT_RDY].name = "CF_RDY";
return 0;
}
static void simpad_pcmcia_hw_shutdown(struct soc_pcmcia_socket *skt)
{
simpad_clear_cs3_bit(PCMCIA_RESET);
}
static void
simpad_pcmcia_socket_state(struct soc_pcmcia_socket *skt,
struct pcmcia_state *state)
{
long cs3reg = simpad_get_cs3_ro();
state->detect = !state->detect;
state->bvd1 = 1;
state->bvd2 = 1;
if ((cs3reg & (PCMCIA_VS1|PCMCIA_VS2)) ==
(PCMCIA_VS1|PCMCIA_VS2)) {
state->vs_3v=0;
state->vs_Xv=0;
} else {
state->vs_3v=1;
state->vs_Xv=0;
}
}
static int
simpad_pcmcia_configure_socket(struct soc_pcmcia_socket *skt,
const socket_state_t *state)
{
unsigned long flags;
local_irq_save(flags);
switch (state->Vcc) {
case 0:
simpad_clear_cs3_bit(VCC_3V_EN|VCC_5V_EN|EN0|EN1);
break;
case 33:
simpad_clear_cs3_bit(VCC_3V_EN|EN1);
simpad_set_cs3_bit(VCC_5V_EN|EN0);
break;
case 50:
simpad_clear_cs3_bit(VCC_5V_EN|EN1);
simpad_set_cs3_bit(VCC_3V_EN|EN0);
break;
default:
printk(KERN_ERR "%s(): unrecognized Vcc %u\n",
__func__, state->Vcc);
simpad_clear_cs3_bit(VCC_3V_EN|VCC_5V_EN|EN0|EN1);
local_irq_restore(flags);
return -1;
}
local_irq_restore(flags);
return 0;
}
static void simpad_pcmcia_socket_suspend(struct soc_pcmcia_socket *skt)
{
simpad_set_cs3_bit(PCMCIA_RESET);
}
int __devinit pcmcia_simpad_init(struct device *dev)
{
int ret = -ENODEV;
if (machine_is_simpad())
ret = sa11xx_drv_pcmcia_probe(dev, &simpad_pcmcia_ops, 1, 1);
return ret;
}
