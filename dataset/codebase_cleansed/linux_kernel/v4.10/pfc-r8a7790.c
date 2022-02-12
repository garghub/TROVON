static int r8a7790_pin_to_pocctrl(struct sh_pfc *pfc, unsigned int pin, u32 *pocctrl)
{
if (pin < RCAR_GP_PIN(3, 0) || pin > RCAR_GP_PIN(3, 31))
return -EINVAL;
*pocctrl = 0xe606008c;
return 31 - (pin & 0x1f);
}
