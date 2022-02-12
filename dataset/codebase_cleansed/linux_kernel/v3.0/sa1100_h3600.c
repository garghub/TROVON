static int h3600_pcmcia_hw_init(struct soc_pcmcia_socket *skt)
{
int err;
switch (skt->nr) {
case 0:
err = gpio_request(H3XXX_GPIO_PCMCIA_IRQ0, "PCMCIA IRQ0");
if (err)
goto err00;
err = gpio_direction_input(H3XXX_GPIO_PCMCIA_IRQ0);
if (err)
goto err01;
skt->socket.pci_irq = gpio_to_irq(H3XXX_GPIO_PCMCIA_IRQ0);
err = gpio_request(H3XXX_GPIO_PCMCIA_CD0, "PCMCIA CD0");
if (err)
goto err01;
err = gpio_direction_input(H3XXX_GPIO_PCMCIA_CD0);
if (err)
goto err02;
irqs[0].irq = gpio_to_irq(H3XXX_GPIO_PCMCIA_CD0);
err = gpio_request(H3XXX_EGPIO_OPT_NVRAM_ON, "OPT NVRAM ON");
if (err)
goto err02;
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
err = soc_pcmcia_request_irqs(skt, irqs, ARRAY_SIZE(irqs));
if (err)
goto err06;
break;
case 1:
err = gpio_request(H3XXX_GPIO_PCMCIA_IRQ1, "PCMCIA IRQ1");
if (err)
goto err10;
err = gpio_direction_input(H3XXX_GPIO_PCMCIA_IRQ1);
if (err)
goto err11;
skt->socket.pci_irq = gpio_to_irq(H3XXX_GPIO_PCMCIA_IRQ1);
err = gpio_request(H3XXX_GPIO_PCMCIA_CD1, "PCMCIA CD1");
if (err)
goto err11;
err = gpio_direction_input(H3XXX_GPIO_PCMCIA_CD1);
if (err)
goto err12;
irqs[1].irq = gpio_to_irq(H3XXX_GPIO_PCMCIA_CD1);
err = soc_pcmcia_request_irqs(skt, irqs, ARRAY_SIZE(irqs));
if (err)
goto err12;
break;
}
return 0;
err06: gpio_free(H3XXX_EGPIO_CARD_RESET);
err05: gpio_free(H3XXX_EGPIO_OPT_RESET);
err04: gpio_free(H3XXX_EGPIO_OPT_ON);
err03: gpio_free(H3XXX_EGPIO_OPT_NVRAM_ON);
err02: gpio_free(H3XXX_GPIO_PCMCIA_CD0);
err01: gpio_free(H3XXX_GPIO_PCMCIA_IRQ0);
err00: return err;
err12: gpio_free(H3XXX_GPIO_PCMCIA_CD0);
err11: gpio_free(H3XXX_GPIO_PCMCIA_IRQ0);
err10: return err;
}
static void h3600_pcmcia_hw_shutdown(struct soc_pcmcia_socket *skt)
{
soc_pcmcia_free_irqs(skt, irqs, ARRAY_SIZE(irqs));
switch (skt->nr) {
case 0:
gpio_set_value(H3XXX_EGPIO_OPT_NVRAM_ON, 0);
gpio_set_value(H3XXX_EGPIO_OPT_ON, 0);
gpio_set_value(H3XXX_EGPIO_OPT_RESET, 1);
gpio_free(H3XXX_EGPIO_CARD_RESET);
gpio_free(H3XXX_EGPIO_OPT_RESET);
gpio_free(H3XXX_EGPIO_OPT_ON);
gpio_free(H3XXX_EGPIO_OPT_NVRAM_ON);
gpio_free(H3XXX_GPIO_PCMCIA_CD0);
gpio_free(H3XXX_GPIO_PCMCIA_IRQ0);
break;
case 1:
gpio_free(H3XXX_GPIO_PCMCIA_CD1);
gpio_free(H3XXX_GPIO_PCMCIA_IRQ1);
break;
}
}
static void
h3600_pcmcia_socket_state(struct soc_pcmcia_socket *skt, struct pcmcia_state *state)
{
switch (skt->nr) {
case 0:
state->detect = !gpio_get_value(H3XXX_GPIO_PCMCIA_CD0);
state->ready = !!gpio_get_value(H3XXX_GPIO_PCMCIA_IRQ0);
state->bvd1 = 0;
state->bvd2 = 0;
state->wrprot = 0;
state->vs_3v = 0;
state->vs_Xv = 0;
break;
case 1:
state->detect = !gpio_get_value(H3XXX_GPIO_PCMCIA_CD1);
state->ready = !!gpio_get_value(H3XXX_GPIO_PCMCIA_IRQ1);
state->bvd1 = 0;
state->bvd2 = 0;
state->wrprot = 0;
state->vs_3v = 0;
state->vs_Xv = 0;
break;
}
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
soc_pcmcia_enable_irqs(skt, irqs, ARRAY_SIZE(irqs));
}
static void h3600_pcmcia_socket_suspend(struct soc_pcmcia_socket *skt)
{
soc_pcmcia_disable_irqs(skt, irqs, ARRAY_SIZE(irqs));
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
