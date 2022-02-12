static void wm_put(struct snd_ice1712 *ice, int reg, unsigned short val)
{
unsigned short cval;
cval = (reg << 9) | val;
snd_vt1724_write_i2c(ice, WM_DEV, cval >> 8, cval & 0xff);
}
static int __devinit snd_vt1724_amp_init(struct snd_ice1712 *ice)
{
static const unsigned short wm_inits[] = {
WM_ATTEN_L, 0x0000,
WM_ATTEN_R, 0x0000,
WM_DAC_CTRL, 0x0008,
WM_INT_CTRL, 0x0001,
};
unsigned int i;
ice->num_total_dacs = 6;
ice->num_total_adcs = 2;
if (ice->eeprom.subvendor == VT1724_SUBDEVICE_AV710) {
for (i = 0; i < ARRAY_SIZE(wm_inits); i += 2)
wm_put(ice, wm_inits[i], wm_inits[i+1]);
}
return 0;
}
static int __devinit snd_vt1724_amp_add_controls(struct snd_ice1712 *ice)
{
snd_ac97_write_cache(ice->ac97, 0x5a, snd_ac97_read(ice->ac97, 0x5a) & ~0x8000);
return 0;
}
