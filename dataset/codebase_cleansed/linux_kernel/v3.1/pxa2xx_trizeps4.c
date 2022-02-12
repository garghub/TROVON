static int trizeps_pcmcia_hw_init(struct soc_pcmcia_socket *skt)
{
int ret, i;
switch (skt->nr) {
case 0:
if (gpio_request(GPIO_PRDY, "cf_irq") < 0) {
pr_err("%s: sock %d unable to request gpio %d\n", __func__,
skt->nr, GPIO_PRDY);
return -EBUSY;
}
if (gpio_direction_input(GPIO_PRDY) < 0) {
pr_err("%s: sock %d unable to set input gpio %d\n", __func__,
skt->nr, GPIO_PRDY);
gpio_free(GPIO_PRDY);
return -EINVAL;
}
skt->socket.pci_irq = IRQ_GPIO(GPIO_PRDY);
break;
default:
break;
}
pr_debug("%s: sock %d irq %d\n", __func__, skt->nr, skt->socket.pci_irq);
for (i = 0; i < ARRAY_SIZE(irqs); i++) {
if (irqs[i].sock != skt->nr)
continue;
if (gpio_request(irq_to_gpio(irqs[i].irq), irqs[i].str) < 0) {
pr_err("%s: sock %d unable to request gpio %d\n",
__func__, skt->nr, irq_to_gpio(irqs[i].irq));
ret = -EBUSY;
goto error;
}
if (gpio_direction_input(irq_to_gpio(irqs[i].irq)) < 0) {
pr_err("%s: sock %d unable to set input gpio %d\n",
__func__, skt->nr, irq_to_gpio(irqs[i].irq));
ret = -EINVAL;
goto error;
}
}
return soc_pcmcia_request_irqs(skt, irqs, ARRAY_SIZE(irqs));
error:
for (; i >= 0; i--) {
gpio_free(irq_to_gpio(irqs[i].irq));
}
return (ret);
}
static void trizeps_pcmcia_hw_shutdown(struct soc_pcmcia_socket *skt)
{
int i;
gpio_free(GPIO_PRDY);
for (i = 0; i < ARRAY_SIZE(irqs); i++)
gpio_free(irq_to_gpio(irqs[i].irq));
}
static void trizeps_pcmcia_socket_state(struct soc_pcmcia_socket *skt,
struct pcmcia_state *state)
{
unsigned short status = 0, change;
status = CFSR_readw();
change = (status ^ trizeps_pcmcia_status[skt->nr]) &
ConXS_CFSR_BVD_MASK;
if (change) {
trizeps_pcmcia_status[skt->nr] = status;
if (status & ConXS_CFSR_BVD1) {
} else {
}
}
switch (skt->nr) {
case 0:
state->detect = gpio_get_value(GPIO_PCD) ? 0 : 1;
state->ready = gpio_get_value(GPIO_PRDY) ? 1 : 0;
state->bvd1 = (status & ConXS_CFSR_BVD1) ? 1 : 0;
state->bvd2 = (status & ConXS_CFSR_BVD2) ? 1 : 0;
state->vs_3v = (status & ConXS_CFSR_VS1) ? 0 : 1;
state->vs_Xv = (status & ConXS_CFSR_VS2) ? 0 : 1;
state->wrprot = 0;
break;
#ifndef CONFIG_MACH_TRIZEPS_CONXS
case 1:
state->detect = 0;
state->ready = 0;
state->bvd1 = 0;
state->bvd2 = 0;
state->vs_3v = 0;
state->vs_Xv = 0;
state->wrprot = 0;
break;
#endif
}
}
static int trizeps_pcmcia_configure_socket(struct soc_pcmcia_socket *skt,
const socket_state_t *state)
{
int ret = 0;
unsigned short power = 0;
switch (state->Vcc) {
case 0: power &= 0xfc; break;
case 33: power |= ConXS_BCR_S0_VCC_3V3; break;
case 50:
pr_err("%s(): Vcc 5V not supported in socket\n", __func__);
break;
default:
pr_err("%s(): bad Vcc %u\n", __func__, state->Vcc);
ret = -1;
}
switch (state->Vpp) {
case 0: power &= 0xf3; break;
case 33: power |= ConXS_BCR_S0_VPP_3V3; break;
case 120:
pr_err("%s(): Vpp 12V not supported in socket\n", __func__);
break;
default:
if (state->Vpp != state->Vcc) {
pr_err("%s(): bad Vpp %u\n", __func__, state->Vpp);
ret = -1;
}
}
switch (skt->nr) {
case 0:
board_pcmcia_power(power);
break;
#ifndef CONFIG_MACH_TRIZEPS_CONXS
case 1:
#endif
default:
break;
}
return ret;
}
static void trizeps_pcmcia_socket_init(struct soc_pcmcia_socket *skt)
{
board_pcmcia_power(0x9);
}
static void trizeps_pcmcia_socket_suspend(struct soc_pcmcia_socket *skt)
{
board_pcmcia_power(0x0);
}
static int __init trizeps_pcmcia_init(void)
{
int ret;
if (!machine_is_trizeps4() && !machine_is_trizeps4wl())
return -ENODEV;
trizeps_pcmcia_device = platform_device_alloc("pxa2xx-pcmcia", -1);
if (!trizeps_pcmcia_device)
return -ENOMEM;
ret = platform_device_add_data(trizeps_pcmcia_device,
&trizeps_pcmcia_ops, sizeof(trizeps_pcmcia_ops));
if (ret == 0)
ret = platform_device_add(trizeps_pcmcia_device);
if (ret)
platform_device_put(trizeps_pcmcia_device);
return ret;
}
static void __exit trizeps_pcmcia_exit(void)
{
platform_device_unregister(trizeps_pcmcia_device);
}
