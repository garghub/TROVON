static unsigned int r8a73a4_pinmux_get_bias(struct sh_pfc *pfc,
unsigned int pin)
{
void __iomem *addr;
addr = pfc->window->virt + r8a73a4_portcr_offsets[pin >> 5] + pin;
switch (ioread8(addr) & PORTCR_PULMD_MASK) {
case PORTCR_PULMD_UP:
return PIN_CONFIG_BIAS_PULL_UP;
case PORTCR_PULMD_DOWN:
return PIN_CONFIG_BIAS_PULL_DOWN;
case PORTCR_PULMD_OFF:
default:
return PIN_CONFIG_BIAS_DISABLE;
}
}
static void r8a73a4_pinmux_set_bias(struct sh_pfc *pfc, unsigned int pin,
unsigned int bias)
{
void __iomem *addr;
u32 value;
addr = pfc->window->virt + r8a73a4_portcr_offsets[pin >> 5] + pin;
value = ioread8(addr) & ~PORTCR_PULMD_MASK;
switch (bias) {
case PIN_CONFIG_BIAS_PULL_UP:
value |= PORTCR_PULMD_UP;
break;
case PIN_CONFIG_BIAS_PULL_DOWN:
value |= PORTCR_PULMD_DOWN;
break;
}
iowrite8(value, addr);
}
