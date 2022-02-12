static unsigned int sh73a0_pinmux_get_bias(struct sh_pfc *pfc, unsigned int pin)
{
void __iomem *addr = pfc->window->virt
+ sh73a0_portcr_offsets[pin >> 5] + pin;
u32 value = ioread8(addr) & PORTnCR_PULMD_MASK;
switch (value) {
case PORTnCR_PULMD_UP:
return PIN_CONFIG_BIAS_PULL_UP;
case PORTnCR_PULMD_DOWN:
return PIN_CONFIG_BIAS_PULL_DOWN;
case PORTnCR_PULMD_OFF:
default:
return PIN_CONFIG_BIAS_DISABLE;
}
}
static void sh73a0_pinmux_set_bias(struct sh_pfc *pfc, unsigned int pin,
unsigned int bias)
{
void __iomem *addr = pfc->window->virt
+ sh73a0_portcr_offsets[pin >> 5] + pin;
u32 value = ioread8(addr) & ~PORTnCR_PULMD_MASK;
switch (bias) {
case PIN_CONFIG_BIAS_PULL_UP:
value |= PORTnCR_PULMD_UP;
break;
case PIN_CONFIG_BIAS_PULL_DOWN:
value |= PORTnCR_PULMD_DOWN;
break;
}
iowrite8(value, addr);
}
