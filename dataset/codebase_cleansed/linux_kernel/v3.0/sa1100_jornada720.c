static int
jornada720_pcmcia_configure_socket(struct soc_pcmcia_socket *skt, const socket_state_t *state)
{
struct sa1111_pcmcia_socket *s = to_skt(skt);
unsigned int pa_dwr_mask, pa_dwr_set;
int ret;
printk(KERN_INFO "%s(): config socket %d vcc %d vpp %d\n", __func__,
skt->nr, state->Vcc, state->Vpp);
switch (skt->nr) {
case 0:
pa_dwr_mask = SOCKET0_POWER | SOCKET0_3V;
switch (state->Vcc) {
default:
case 0:
pa_dwr_set = 0;
break;
case 33:
pa_dwr_set = SOCKET0_POWER | SOCKET0_3V;
break;
case 50:
pa_dwr_set = SOCKET0_POWER;
break;
}
break;
case 1:
pa_dwr_mask = SOCKET1_POWER;
switch (state->Vcc) {
default:
case 0:
pa_dwr_set = 0;
break;
case 33:
pa_dwr_set = SOCKET1_POWER;
break;
case 50:
pa_dwr_set = SOCKET1_POWER;
break;
}
break;
default:
return -1;
}
if (state->Vpp != state->Vcc && state->Vpp != 0) {
printk(KERN_ERR "%s(): slot cannot support VPP %u\n",
__func__, state->Vpp);
return -EPERM;
}
ret = sa1111_pcmcia_configure_socket(skt, state);
if (ret == 0) {
unsigned long flags;
local_irq_save(flags);
sa1111_set_io(s->dev, pa_dwr_mask, pa_dwr_set);
local_irq_restore(flags);
}
return ret;
}
int __devinit pcmcia_jornada720_init(struct device *dev)
{
int ret = -ENODEV;
if (machine_is_jornada720()) {
unsigned int pin = GPIO_A0 | GPIO_A1 | GPIO_A2 | GPIO_A3;
GRER |= 0x00000002;
sa1111_set_io_dir(dev, pin, 0, 0);
sa1111_set_io(dev, pin, 0);
sa1111_set_sleep_io(dev, pin, 0);
sa11xx_drv_pcmcia_ops(&jornada720_pcmcia_ops);
ret = sa1111_pcmcia_add(dev, &jornada720_pcmcia_ops,
sa11xx_drv_pcmcia_add_one);
}
return ret;
}
