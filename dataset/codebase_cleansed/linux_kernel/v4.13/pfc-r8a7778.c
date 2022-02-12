static unsigned int r8a7778_pinmux_get_bias(struct sh_pfc *pfc,
unsigned int pin)
{
const struct sh_pfc_bias_info *info;
void __iomem *addr;
info = sh_pfc_pin_to_bias_info(bias_info, ARRAY_SIZE(bias_info), pin);
if (!info)
return PIN_CONFIG_BIAS_DISABLE;
addr = pfc->windows->virt + info->reg;
if (ioread32(addr) & BIT(info->bit))
return PIN_CONFIG_BIAS_PULL_UP;
else
return PIN_CONFIG_BIAS_DISABLE;
}
static void r8a7778_pinmux_set_bias(struct sh_pfc *pfc, unsigned int pin,
unsigned int bias)
{
const struct sh_pfc_bias_info *info;
void __iomem *addr;
u32 value;
u32 bit;
info = sh_pfc_pin_to_bias_info(bias_info, ARRAY_SIZE(bias_info), pin);
if (!info)
return;
addr = pfc->windows->virt + info->reg;
bit = BIT(info->bit);
value = ioread32(addr) & ~bit;
if (bias == PIN_CONFIG_BIAS_PULL_UP)
value |= bit;
iowrite32(value, addr);
}
