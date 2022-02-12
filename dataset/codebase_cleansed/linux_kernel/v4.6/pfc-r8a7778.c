static unsigned int r8a7778_pinmux_get_bias(struct sh_pfc *pfc,
unsigned int pin)
{
void __iomem *addr;
if (WARN_ON_ONCE(!pullups[pin].reg))
return PIN_CONFIG_BIAS_DISABLE;
addr = pfc->windows->virt + pullups[pin].reg;
if (ioread32(addr) & BIT(pullups[pin].bit))
return PIN_CONFIG_BIAS_PULL_UP;
else
return PIN_CONFIG_BIAS_DISABLE;
}
static void r8a7778_pinmux_set_bias(struct sh_pfc *pfc, unsigned int pin,
unsigned int bias)
{
void __iomem *addr;
u32 value;
u32 bit;
if (WARN_ON_ONCE(!pullups[pin].reg))
return;
addr = pfc->windows->virt + pullups[pin].reg;
bit = BIT(pullups[pin].bit);
value = ioread32(addr) & ~bit;
if (bias == PIN_CONFIG_BIAS_PULL_UP)
value |= bit;
iowrite32(value, addr);
}
