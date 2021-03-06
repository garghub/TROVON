static int h3600_pcmcia_hw_init(struct soc_pcmcia_socket *skt)
{
int err;
switch (skt->nr) {
case 0:
skt->stat[SOC_STAT_CD].gpio = H3XXX_GPIO_PCMCIA_CD0;
skt->stat[SOC_STAT_CD].name = "PCMCIA CD0";
skt->stat[SOC_STAT_RDY].gpio = H3XXX_GPIO_PCMCIA_IRQ0;
skt->stat[SOC_STAT_RDY].name = "PCMCIA IRQ0";
err = gpio_request(H3XXX_EGPIO_OPT_NVRAM_ON, "OPT NVRAM ON");
if (err)
goto err01;
err = gpio_direction_output(H3XXX_EGPIO_OPT_NVRAM_ON, 0);
if (err)
goto err03;
err = gpio_request(H3XXX_EGPIO_OPT_ON, "OPT ON");
if (err)
goto err03;
err = gpio_direction_output(H3XXX_EGPIO_OPT_ON, 0);
if (err)
goto err04;
err = gpio_request(H3XXX_EGPIO_OPT_RESET, "OPT RESET");
if (err)
goto err04;
err = gpio_direction_output(H3XXX_EGPIO_OPT_RESET, 0);
if (err)
goto err05;
err = gpio_request(H3XXX_EGPIO_CARD_RESET, "PCMCIA CARD RESET");
if (err)
goto err05;
err = gpio_direction_output(H3XXX_EGPIO_CARD_RESET, 0);
if (err)
goto err06;
break;
case 1:
skt->stat[SOC_STAT_CD].gpio = H3XXX_GPIO_PCMCIA_CD1;
skt->stat[SOC_STAT_CD].name = "PCMCIA CD1";
skt->stat[SOC_STAT_RDY].gpio = H3XXX_GPIO_PCMCIA_IRQ1;
skt->stat[SOC_STAT_RDY].name = "PCMCIA IRQ1";
break;
}
return 0;
err06: gpio_free(H3XXX_EGPIO_CARD_RESET);
err05: gpio_free(H3XXX_EGPIO_OPT_RESET);
err04: gpio_free(H3XXX_EGPIO_OPT_ON);
err03: gpio_free(H3XXX_EGPIO_OPT_NVRAM_ON);
err01: gpio_free(H3XXX_GPIO_PCMCIA_IRQ0);
return err;
}
static void h3600_pcmcia_hw_shutdown(struct soc_pcmcia_socket *skt)
{
switch (skt->nr) {
case 0:
gpio_set_value(H3XXX_EGPIO_OPT_NVRAM_ON, 0);
gpio_set_value(H3XXX_EGPIO_OPT_ON, 0);
gpio_set_value(H3XXX_EGPIO_OPT_RESET, 1);
gpio_free(H3XXX_EGPIO_CARD_RESET);
gpio_free(H3XXX_EGPIO_OPT_RESET);
gpio_free(H3XXX_EGPIO_OPT_ON);
gpio_free(H3XXX_EGPIO_OPT_NVRAM_ON);
break;
case 1:
break;
}
}
static void
h3600_pcmcia_socket_state(struct soc_pcmcia_socket *skt, struct pcmcia_state *state)
{
state->bvd1 = 0;
state->bvd2 = 0;
state->vs_3v = 0;
state->vs_Xv = 0;
}
static int
h3600_pcmcia_configure_socket(struct soc_pcmcia_socket *skt, const socket_state_t *state)
{
if (state->Vcc != 0 && state->Vcc != 33 && state->Vcc != 50) {
printk(KERN_ERR "h3600_pcmcia: unrecognized Vcc %u.%uV\n",
state->Vcc / 10, state->Vcc % 10);
return -1;
}
gpio_set_value(H3XXX_EGPIO_CARD_RESET, !!(state->flags & SS_RESET));
return 0;
}
static void h3600_pcmcia_socket_init(struct soc_pcmcia_socket *skt)
{
gpio_set_value(H3XXX_EGPIO_OPT_NVRAM_ON, 1);
gpio_set_value(H3XXX_EGPIO_OPT_ON, 1);
gpio_set_value(H3XXX_EGPIO_OPT_RESET, 0);
msleep(10);
}
static void h3600_pcmcia_socket_suspend(struct soc_pcmcia_socket *skt)
{
if (skt->nr == 1) {
gpio_set_value(H3XXX_EGPIO_OPT_ON, 0);
gpio_set_value(H3XXX_EGPIO_OPT_NVRAM_ON, 0);
gpio_set_value(H3XXX_EGPIO_OPT_RESET, 1);
}
}
int __devinit pcmcia_h3600_init(struct device *dev)
{
int ret = -ENODEV;
if (machine_is_h3600() || machine_is_h3100())
ret = sa11xx_drv_pcmcia_probe(dev, &h3600_pcmcia_ops, 0, 2);
return ret;
}
