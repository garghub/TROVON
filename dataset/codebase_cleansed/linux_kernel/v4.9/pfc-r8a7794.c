static int r8a7794_pin_to_pocctrl(struct sh_pfc *pfc, unsigned int pin, u32 *pocctrl)
{
*pocctrl = 0xe606006c;
switch (pin & 0x1f) {
case 6: return 23;
case 7: return 16;
case 14: return 15;
case 15: return 8;
case 0 ... 5:
case 8 ... 13:
return 22 - (pin & 0x1f);
case 16 ... 23:
return 47 - (pin & 0x1f);
}
return -EINVAL;
}
