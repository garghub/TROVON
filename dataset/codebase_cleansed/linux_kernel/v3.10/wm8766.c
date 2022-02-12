static void snd_wm8766_write(struct snd_wm8766 *wm, u16 addr, u16 data)
{
if (addr < WM8766_REG_COUNT)
wm->regs[addr] = data;
wm->ops.write(wm, addr, data);
}
void snd_wm8766_init(struct snd_wm8766 *wm)
{
int i;
static const u16 default_values[] = {
0x000, 0x100,
0x120, 0x000,
0x000, 0x100, 0x000, 0x100, 0x000,
0x000, 0x080,
};
memcpy(wm->ctl, snd_wm8766_default_ctl, sizeof(wm->ctl));
snd_wm8766_write(wm, WM8766_REG_RESET, 0x00);
udelay(10);
for (i = 0; i < ARRAY_SIZE(default_values); i++)
snd_wm8766_write(wm, i, default_values[i]);
}
void snd_wm8766_resume(struct snd_wm8766 *wm)
{
int i;
for (i = 0; i < WM8766_REG_COUNT; i++)
snd_wm8766_write(wm, i, wm->regs[i]);
}
void snd_wm8766_set_if(struct snd_wm8766 *wm, u16 dac)
{
u16 val = wm->regs[WM8766_REG_IFCTRL] & ~WM8766_IF_MASK;
dac &= WM8766_IF_MASK;
snd_wm8766_write(wm, WM8766_REG_IFCTRL, val | dac);
}
void snd_wm8766_set_master_mode(struct snd_wm8766 *wm, u16 mode)
{
u16 val = wm->regs[WM8766_REG_DACCTRL3] & ~WM8766_DAC3_MSTR_MASK;
mode &= WM8766_DAC3_MSTR_MASK;
snd_wm8766_write(wm, WM8766_REG_DACCTRL3, val | mode);
}
void snd_wm8766_set_power(struct snd_wm8766 *wm, u16 power)
{
u16 val = wm->regs[WM8766_REG_DACCTRL3] & ~WM8766_DAC3_POWER_MASK;
power &= WM8766_DAC3_POWER_MASK;
snd_wm8766_write(wm, WM8766_REG_DACCTRL3, val | power);
}
void snd_wm8766_volume_restore(struct snd_wm8766 *wm)
{
u16 val = wm->regs[WM8766_REG_DACR1];
snd_wm8766_write(wm, WM8766_REG_DACR1, val | WM8766_VOL_UPDATE);
}
static int snd_wm8766_volume_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct snd_wm8766 *wm = snd_kcontrol_chip(kcontrol);
int n = kcontrol->private_value;
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = (wm->ctl[n].flags & WM8766_FLAG_STEREO) ? 2 : 1;
uinfo->value.integer.min = wm->ctl[n].min;
uinfo->value.integer.max = wm->ctl[n].max;
return 0;
}
static int snd_wm8766_enum_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct snd_wm8766 *wm = snd_kcontrol_chip(kcontrol);
int n = kcontrol->private_value;
return snd_ctl_enum_info(uinfo, 1, wm->ctl[n].max,
wm->ctl[n].enum_names);
}
static int snd_wm8766_ctl_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_wm8766 *wm = snd_kcontrol_chip(kcontrol);
int n = kcontrol->private_value;
u16 val1, val2;
if (wm->ctl[n].get)
wm->ctl[n].get(wm, &val1, &val2);
else {
val1 = wm->regs[wm->ctl[n].reg1] & wm->ctl[n].mask1;
val1 >>= __ffs(wm->ctl[n].mask1);
if (wm->ctl[n].flags & WM8766_FLAG_STEREO) {
val2 = wm->regs[wm->ctl[n].reg2] & wm->ctl[n].mask2;
val2 >>= __ffs(wm->ctl[n].mask2);
if (wm->ctl[n].flags & WM8766_FLAG_VOL_UPDATE)
val2 &= ~WM8766_VOL_UPDATE;
}
}
if (wm->ctl[n].flags & WM8766_FLAG_INVERT) {
val1 = wm->ctl[n].max - (val1 - wm->ctl[n].min);
val2 = wm->ctl[n].max - (val2 - wm->ctl[n].min);
}
ucontrol->value.integer.value[0] = val1;
if (wm->ctl[n].flags & WM8766_FLAG_STEREO)
ucontrol->value.integer.value[1] = val2;
return 0;
}
static int snd_wm8766_ctl_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_wm8766 *wm = snd_kcontrol_chip(kcontrol);
int n = kcontrol->private_value;
u16 val, regval1, regval2;
regval1 = ucontrol->value.integer.value[0];
regval2 = ucontrol->value.integer.value[1];
if (wm->ctl[n].flags & WM8766_FLAG_INVERT) {
regval1 = wm->ctl[n].max - (regval1 - wm->ctl[n].min);
regval2 = wm->ctl[n].max - (regval2 - wm->ctl[n].min);
}
if (wm->ctl[n].set)
wm->ctl[n].set(wm, regval1, regval2);
else {
val = wm->regs[wm->ctl[n].reg1] & ~wm->ctl[n].mask1;
val |= regval1 << __ffs(wm->ctl[n].mask1);
if (wm->ctl[n].flags & WM8766_FLAG_STEREO &&
wm->ctl[n].reg1 == wm->ctl[n].reg2) {
val &= ~wm->ctl[n].mask2;
val |= regval2 << __ffs(wm->ctl[n].mask2);
}
snd_wm8766_write(wm, wm->ctl[n].reg1, val);
if (wm->ctl[n].flags & WM8766_FLAG_STEREO &&
wm->ctl[n].reg1 != wm->ctl[n].reg2) {
val = wm->regs[wm->ctl[n].reg2] & ~wm->ctl[n].mask2;
val |= regval2 << __ffs(wm->ctl[n].mask2);
if (wm->ctl[n].flags & WM8766_FLAG_VOL_UPDATE)
val |= WM8766_VOL_UPDATE;
snd_wm8766_write(wm, wm->ctl[n].reg2, val);
}
}
return 0;
}
static int snd_wm8766_add_control(struct snd_wm8766 *wm, int num)
{
struct snd_kcontrol_new cont;
struct snd_kcontrol *ctl;
memset(&cont, 0, sizeof(cont));
cont.iface = SNDRV_CTL_ELEM_IFACE_MIXER;
cont.private_value = num;
cont.name = wm->ctl[num].name;
cont.access = SNDRV_CTL_ELEM_ACCESS_READWRITE;
if (wm->ctl[num].flags & WM8766_FLAG_LIM ||
wm->ctl[num].flags & WM8766_FLAG_ALC)
cont.access |= SNDRV_CTL_ELEM_ACCESS_INACTIVE;
cont.tlv.p = NULL;
cont.get = snd_wm8766_ctl_get;
cont.put = snd_wm8766_ctl_put;
switch (wm->ctl[num].type) {
case SNDRV_CTL_ELEM_TYPE_INTEGER:
cont.info = snd_wm8766_volume_info;
cont.access |= SNDRV_CTL_ELEM_ACCESS_TLV_READ;
cont.tlv.p = wm->ctl[num].tlv;
break;
case SNDRV_CTL_ELEM_TYPE_BOOLEAN:
wm->ctl[num].max = 1;
if (wm->ctl[num].flags & WM8766_FLAG_STEREO)
cont.info = snd_ctl_boolean_stereo_info;
else
cont.info = snd_ctl_boolean_mono_info;
break;
case SNDRV_CTL_ELEM_TYPE_ENUMERATED:
cont.info = snd_wm8766_enum_info;
break;
default:
return -EINVAL;
}
ctl = snd_ctl_new1(&cont, wm);
if (!ctl)
return -ENOMEM;
wm->ctl[num].kctl = ctl;
return snd_ctl_add(wm->card, ctl);
}
int snd_wm8766_build_controls(struct snd_wm8766 *wm)
{
int err, i;
for (i = 0; i < WM8766_CTL_COUNT; i++)
if (wm->ctl[i].name) {
err = snd_wm8766_add_control(wm, i);
if (err < 0)
return err;
}
return 0;
}
