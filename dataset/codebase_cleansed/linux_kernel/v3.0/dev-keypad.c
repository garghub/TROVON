void __init samsung_keypad_set_platdata(struct samsung_keypad_platdata *pd)
{
struct samsung_keypad_platdata *npd;
npd = s3c_set_platdata(pd, sizeof(struct samsung_keypad_platdata),
&samsung_device_keypad);
if (!npd->cfg_gpio)
npd->cfg_gpio = samsung_keypad_cfg_gpio;
}
