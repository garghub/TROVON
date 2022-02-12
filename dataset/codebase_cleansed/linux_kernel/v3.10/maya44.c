static void wm8776_write(struct snd_ice1712 *ice, struct snd_wm8776 *wm,
unsigned char reg, unsigned short val)
{
snd_vt1724_write_i2c(ice, wm->addr,
(reg << 1) | ((val >> 8) & 1),
val & 0xff);
wm->regs[reg] = val;
}
static int wm8776_write_bits(struct snd_ice1712 *ice, struct snd_wm8776 *wm,
unsigned char reg,
unsigned short mask, unsigned short val)
{
val |= wm->regs[reg] & ~mask;
if (val != wm->regs[reg]) {
wm8776_write(ice, wm, reg, val);
return 1;
}
return 0;
}
static int maya_vol_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
unsigned int idx = kcontrol->private_value;
struct maya_vol_info *vol = &vol_info[idx];
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 2;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = vol->maxval;
return 0;
}
static int maya_vol_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_maya44 *chip = snd_kcontrol_chip(kcontrol);
struct snd_wm8776 *wm =
&chip->wm[snd_ctl_get_ioff(kcontrol, &ucontrol->id)];
unsigned int idx = kcontrol->private_value;
mutex_lock(&chip->mutex);
ucontrol->value.integer.value[0] = wm->volumes[idx][0];
ucontrol->value.integer.value[1] = wm->volumes[idx][1];
mutex_unlock(&chip->mutex);
return 0;
}
static int maya_vol_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_maya44 *chip = snd_kcontrol_chip(kcontrol);
struct snd_wm8776 *wm =
&chip->wm[snd_ctl_get_ioff(kcontrol, &ucontrol->id)];
unsigned int idx = kcontrol->private_value;
struct maya_vol_info *vol = &vol_info[idx];
unsigned int val, data;
int ch, changed = 0;
mutex_lock(&chip->mutex);
for (ch = 0; ch < 2; ch++) {
val = ucontrol->value.integer.value[ch];
if (val > vol->maxval)
val = vol->maxval;
if (val == wm->volumes[idx][ch])
continue;
if (!val)
data = vol->mute;
else
data = (val - 1) + vol->offset;
data |= vol->update;
changed |= wm8776_write_bits(chip->ice, wm, vol->regs[ch],
vol->mask | vol->update, data);
if (vol->mux_bits[ch])
wm8776_write_bits(chip->ice, wm, WM8776_REG_ADC_MUX,
vol->mux_bits[ch],
val ? 0 : vol->mux_bits[ch]);
wm->volumes[idx][ch] = val;
}
mutex_unlock(&chip->mutex);
return changed;
}
static int maya_sw_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_maya44 *chip = snd_kcontrol_chip(kcontrol);
struct snd_wm8776 *wm =
&chip->wm[snd_ctl_get_ioff(kcontrol, &ucontrol->id)];
unsigned int idx = GET_SW_VAL_IDX(kcontrol->private_value);
ucontrol->value.integer.value[0] = (wm->switch_bits >> idx) & 1;
return 0;
}
static int maya_sw_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_maya44 *chip = snd_kcontrol_chip(kcontrol);
struct snd_wm8776 *wm =
&chip->wm[snd_ctl_get_ioff(kcontrol, &ucontrol->id)];
unsigned int idx = GET_SW_VAL_IDX(kcontrol->private_value);
unsigned int mask, val;
int changed;
mutex_lock(&chip->mutex);
mask = 1 << idx;
wm->switch_bits &= ~mask;
val = ucontrol->value.integer.value[0];
if (val)
wm->switch_bits |= mask;
mask = GET_SW_VAL_MASK(kcontrol->private_value);
changed = wm8776_write_bits(chip->ice, wm,
GET_SW_VAL_REG(kcontrol->private_value),
mask, val ? mask : 0);
mutex_unlock(&chip->mutex);
return changed;
}
static int maya_set_gpio_bits(struct snd_ice1712 *ice, unsigned int mask,
unsigned int bits)
{
unsigned int data;
data = snd_ice1712_gpio_read(ice);
if ((data & mask) == bits)
return 0;
snd_ice1712_gpio_write(ice, (data & ~mask) | bits);
return 1;
}
static int maya_gpio_sw_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_maya44 *chip = snd_kcontrol_chip(kcontrol);
unsigned int shift = GET_GPIO_VAL_SHIFT(kcontrol->private_value);
unsigned int val;
val = (snd_ice1712_gpio_read(chip->ice) >> shift) & 1;
if (GET_GPIO_VAL_INV(kcontrol->private_value))
val = !val;
ucontrol->value.integer.value[0] = val;
return 0;
}
static int maya_gpio_sw_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_maya44 *chip = snd_kcontrol_chip(kcontrol);
unsigned int shift = GET_GPIO_VAL_SHIFT(kcontrol->private_value);
unsigned int val, mask;
int changed;
mutex_lock(&chip->mutex);
mask = 1 << shift;
val = ucontrol->value.integer.value[0];
if (GET_GPIO_VAL_INV(kcontrol->private_value))
val = !val;
val = val ? mask : 0;
changed = maya_set_gpio_bits(chip->ice, mask, val);
mutex_unlock(&chip->mutex);
return changed;
}
static void wm8776_select_input(struct snd_maya44 *chip, int idx, int line)
{
wm8776_write_bits(chip->ice, &chip->wm[idx], WM8776_REG_ADC_MUX,
0x1f, 1 << line);
}
static int maya_rec_src_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static const char * const texts[] = { "Line", "Mic" };
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = ARRAY_SIZE(texts);
if (uinfo->value.enumerated.item >= uinfo->value.enumerated.items)
uinfo->value.enumerated.item =
uinfo->value.enumerated.items - 1;
strcpy(uinfo->value.enumerated.name,
texts[uinfo->value.enumerated.item]);
return 0;
}
static int maya_rec_src_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_maya44 *chip = snd_kcontrol_chip(kcontrol);
int sel;
if (snd_ice1712_gpio_read(chip->ice) & (1 << GPIO_MIC_RELAY))
sel = 1;
else
sel = 0;
ucontrol->value.enumerated.item[0] = sel;
return 0;
}
static int maya_rec_src_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_maya44 *chip = snd_kcontrol_chip(kcontrol);
int sel = ucontrol->value.enumerated.item[0];
int changed;
mutex_lock(&chip->mutex);
changed = maya_set_gpio_bits(chip->ice, 1 << GPIO_MIC_RELAY,
sel ? (1 << GPIO_MIC_RELAY) : 0);
wm8776_select_input(chip, 0, sel ? MAYA_MIC_IN : MAYA_LINE_IN);
mutex_unlock(&chip->mutex);
return changed;
}
static int maya_pb_route_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static const char * const texts[] = {
"PCM Out",
"Input 1", "Input 2", "Input 3", "Input 4"
};
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = ARRAY_SIZE(texts);
if (uinfo->value.enumerated.item >= uinfo->value.enumerated.items)
uinfo->value.enumerated.item =
uinfo->value.enumerated.items - 1;
strcpy(uinfo->value.enumerated.name,
texts[uinfo->value.enumerated.item]);
return 0;
}
static int maya_pb_route_shift(int idx)
{
static const unsigned char shift[10] =
{ 8, 20, 0, 3, 11, 23, 14, 26, 17, 29 };
return shift[idx % 10];
}
static int maya_pb_route_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_maya44 *chip = snd_kcontrol_chip(kcontrol);
int idx = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
ucontrol->value.enumerated.item[0] =
snd_ice1724_get_route_val(chip->ice, maya_pb_route_shift(idx));
return 0;
}
static int maya_pb_route_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_maya44 *chip = snd_kcontrol_chip(kcontrol);
int idx = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
return snd_ice1724_put_route_val(chip->ice,
ucontrol->value.enumerated.item[0],
maya_pb_route_shift(idx));
}
static int maya44_add_controls(struct snd_ice1712 *ice)
{
int err, i;
for (i = 0; i < ARRAY_SIZE(maya_controls); i++) {
err = snd_ctl_add(ice->card, snd_ctl_new1(&maya_controls[i],
ice->spec));
if (err < 0)
return err;
}
return 0;
}
static void wm8776_init(struct snd_ice1712 *ice,
struct snd_wm8776 *wm, unsigned int addr)
{
static const unsigned short inits_wm8776[] = {
0x02, 0x100,
0x05, 0x100,
0x06, 0x000,
0x07, 0x091,
0x08, 0x000,
0x09, 0x000,
0x0a, 0x022,
0x0b, 0x022,
0x0c, 0x042,
0x0d, 0x000,
0x0e, 0x100,
0x0f, 0x100,
0x11, 0x000,
0x15, 0x000,
0x16, 0x001,
0xff, 0xff
};
const unsigned short *ptr;
unsigned char reg;
unsigned short data;
wm->addr = addr;
wm->switch_bits = (1 << WM_SW_DAC);
ptr = inits_wm8776;
while (*ptr != 0xff) {
reg = *ptr++;
data = *ptr++;
wm8776_write(ice, wm, reg, data);
}
}
static void set_rate(struct snd_ice1712 *ice, unsigned int rate)
{
struct snd_maya44 *chip = ice->spec;
unsigned int ratio, adc_ratio, val;
int i;
switch (rate) {
case 192000:
ratio = WM8776_CLOCK_RATIO_128FS;
break;
case 176400:
ratio = WM8776_CLOCK_RATIO_128FS;
break;
case 96000:
ratio = WM8776_CLOCK_RATIO_256FS;
break;
case 88200:
ratio = WM8776_CLOCK_RATIO_384FS;
break;
case 48000:
ratio = WM8776_CLOCK_RATIO_512FS;
break;
case 44100:
ratio = WM8776_CLOCK_RATIO_512FS;
break;
case 32000:
ratio = WM8776_CLOCK_RATIO_768FS;
break;
case 0:
return;
default:
snd_BUG();
return;
}
adc_ratio = ratio;
if (adc_ratio < WM8776_CLOCK_RATIO_256FS)
adc_ratio = WM8776_CLOCK_RATIO_256FS;
val = adc_ratio;
if (adc_ratio == WM8776_CLOCK_RATIO_256FS)
val |= 8;
val |= ratio << 4;
mutex_lock(&chip->mutex);
for (i = 0; i < 2; i++)
wm8776_write_bits(ice, &chip->wm[i],
WM8776_REG_MASTER_MODE_CONTROL,
0x180, val);
mutex_unlock(&chip->mutex);
}
static int maya44_init(struct snd_ice1712 *ice)
{
int i;
struct snd_maya44 *chip;
chip = kzalloc(sizeof(*chip), GFP_KERNEL);
if (!chip)
return -ENOMEM;
mutex_init(&chip->mutex);
chip->ice = ice;
ice->spec = chip;
ice->num_total_dacs = 4;
ice->num_total_adcs = 4;
ice->akm_codecs = 0;
for (i = 0; i < 2; i++) {
wm8776_init(ice, &chip->wm[i], wm8776_addr[i]);
wm8776_select_input(chip, i, MAYA_LINE_IN);
}
ice->hw_rates = &dac_rates;
ice->gpio.set_pro_rate = set_rate;
ice->force_rdma1 = 1;
ice->own_routing = 1;
return 0;
}
