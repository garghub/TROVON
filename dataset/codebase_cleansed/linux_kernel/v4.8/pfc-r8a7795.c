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
