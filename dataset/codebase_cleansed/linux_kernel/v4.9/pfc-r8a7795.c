static int r8a7795_pin_to_pocctrl(struct sh_pfc *pfc, unsigned int pin, u32 *pocctrl)
{
int bit = -EINVAL;
*pocctrl = 0xe6060380;
if (pin >= RCAR_GP_PIN(3, 0) && pin <= RCAR_GP_PIN(3, 11))
bit = pin & 0x1f;
if (pin >= RCAR_GP_PIN(4, 0) && pin <= RCAR_GP_PIN(4, 17))
bit = (pin & 0x1f) + 12;
return bit;
}
static unsigned int r8a7795_pinmux_get_bias(struct sh_pfc *pfc,
unsigned int pin)
{
u32 reg;
u32 bit;
if (WARN_ON_ONCE(!pullups[pin].reg))
return PIN_CONFIG_BIAS_DISABLE;
reg = pullups[pin].reg;
bit = BIT(pullups[pin].bit);
if (sh_pfc_read_reg(pfc, PUEN + reg, 32) & bit) {
if (sh_pfc_read_reg(pfc, PUD + reg, 32) & bit)
return PIN_CONFIG_BIAS_PULL_UP;
else
return PIN_CONFIG_BIAS_PULL_DOWN;
} else
return PIN_CONFIG_BIAS_DISABLE;
}
static void r8a7795_pinmux_set_bias(struct sh_pfc *pfc, unsigned int pin,
unsigned int bias)
{
u32 enable, updown;
u32 reg;
u32 bit;
if (WARN_ON_ONCE(!pullups[pin].reg))
return;
reg = pullups[pin].reg;
bit = BIT(pullups[pin].bit);
enable = sh_pfc_read_reg(pfc, PUEN + reg, 32) & ~bit;
if (bias != PIN_CONFIG_BIAS_DISABLE)
enable |= bit;
updown = sh_pfc_read_reg(pfc, PUD + reg, 32) & ~bit;
if (bias == PIN_CONFIG_BIAS_PULL_UP)
updown |= bit;
sh_pfc_write_reg(pfc, PUD + reg, 32, updown);
sh_pfc_write_reg(pfc, PUEN + reg, 32, enable);
}
