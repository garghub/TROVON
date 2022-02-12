static int r8a7791_pin_to_pocctrl(struct sh_pfc *pfc, unsigned int pin, u32 *pocctrl)
{
if (pin < RCAR_GP_PIN(6, 0) || pin > RCAR_GP_PIN(6, 23))
return -EINVAL;
*pocctrl = 0xe606008c;
return 31 - (pin & 0x1f);
}
