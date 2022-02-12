static int r8a77995_pin_to_pocctrl(struct sh_pfc *pfc, unsigned int pin, u32 *pocctrl)
{
int bit = -EINVAL;
*pocctrl = 0xe6060380;
if (pin >= RCAR_GP_PIN(3, 0) && pin <= RCAR_GP_PIN(3, 9))
bit = 29 - (pin - RCAR_GP_PIN(3, 0));
return bit;
}
