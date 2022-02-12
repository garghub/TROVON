static int r8a7795es1_pin_to_pocctrl(struct sh_pfc *pfc, unsigned int pin,
u32 *pocctrl)
{
int bit = -EINVAL;
*pocctrl = 0xe6060380;
if (pin >= RCAR_GP_PIN(3, 0) && pin <= RCAR_GP_PIN(3, 11))
bit = pin & 0x1f;
if (pin >= RCAR_GP_PIN(4, 0) && pin <= RCAR_GP_PIN(4, 17))
bit = (pin & 0x1f) + 12;
return bit;
}
static unsigned int r8a7795es1_pinmux_get_bias(struct sh_pfc *pfc,
unsigned int pin)
{
const struct sh_pfc_bias_info *info;
u32 reg;
u32 bit;
info = sh_pfc_pin_to_bias_info(bias_info, ARRAY_SIZE(bias_info), pin);
if (!info)
return PIN_CONFIG_BIAS_DISABLE;
reg = info->reg;
bit = BIT(info->bit);
if (!(sh_pfc_read_reg(pfc, PUEN + reg, 32) & bit))
return PIN_CONFIG_BIAS_DISABLE;
else if (sh_pfc_read_reg(pfc, PUD + reg, 32) & bit)
return PIN_CONFIG_BIAS_PULL_UP;
else
return PIN_CONFIG_BIAS_PULL_DOWN;
}
static void r8a7795es1_pinmux_set_bias(struct sh_pfc *pfc, unsigned int pin,
unsigned int bias)
{
const struct sh_pfc_bias_info *info;
u32 enable, updown;
u32 reg;
u32 bit;
info = sh_pfc_pin_to_bias_info(bias_info, ARRAY_SIZE(bias_info), pin);
if (!info)
return;
reg = info->reg;
bit = BIT(info->bit);
enable = sh_pfc_read_reg(pfc, PUEN + reg, 32) & ~bit;
if (bias != PIN_CONFIG_BIAS_DISABLE)
enable |= bit;
updown = sh_pfc_read_reg(pfc, PUD + reg, 32) & ~bit;
if (bias == PIN_CONFIG_BIAS_PULL_UP)
updown |= bit;
sh_pfc_write_reg(pfc, PUD + reg, 32, updown);
sh_pfc_write_reg(pfc, PUEN + reg, 32, enable);
}
