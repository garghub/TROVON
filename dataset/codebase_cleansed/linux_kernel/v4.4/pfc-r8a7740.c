static void __iomem *r8a7740_pinmux_portcr(struct sh_pfc *pfc, unsigned int pin)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(r8a7740_portcr_offsets); ++i) {
const struct r8a7740_portcr_group *group =
&r8a7740_portcr_offsets[i];
if (pin <= group->end_pin)
return pfc->windows->virt + group->offset + pin;
}
return NULL;
}
static unsigned int r8a7740_pinmux_get_bias(struct sh_pfc *pfc, unsigned int pin)
{
void __iomem *addr = r8a7740_pinmux_portcr(pfc, pin);
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
static void r8a7740_pinmux_set_bias(struct sh_pfc *pfc, unsigned int pin,
unsigned int bias)
{
void __iomem *addr = r8a7740_pinmux_portcr(pfc, pin);
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
