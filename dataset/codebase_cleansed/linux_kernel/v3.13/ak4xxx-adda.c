void snd_akm4xxx_write(struct snd_akm4xxx *ak, int chip, unsigned char reg,
unsigned char val)
{
ak->ops.lock(ak, chip);
ak->ops.write(ak, chip, reg, val);
snd_akm4xxx_set(ak, chip, reg, val);
ak->ops.unlock(ak, chip);
}
static void ak4524_reset(struct snd_akm4xxx *ak, int state)
{
unsigned int chip;
unsigned char reg;
for (chip = 0; chip < ak->num_dacs/2; chip++) {
snd_akm4xxx_write(ak, chip, 0x01, state ? 0x00 : 0x03);
if (state)
continue;
for (reg = 0x04; reg < ak->total_regs; reg++)
snd_akm4xxx_write(ak, chip, reg,
snd_akm4xxx_get(ak, chip, reg));
}
}
static void ak435X_reset(struct snd_akm4xxx *ak, int state)
{
unsigned char reg;
if (state) {
snd_akm4xxx_write(ak, 0, 0x01, 0x02);
return;
}
for (reg = 0x00; reg < ak->total_regs; reg++)
if (reg != 0x01)
snd_akm4xxx_write(ak, 0, reg,
snd_akm4xxx_get(ak, 0, reg));
snd_akm4xxx_write(ak, 0, 0x01, 0x01);
}
static void ak4381_reset(struct snd_akm4xxx *ak, int state)
{
unsigned int chip;
unsigned char reg;
for (chip = 0; chip < ak->num_dacs/2; chip++) {
snd_akm4xxx_write(ak, chip, 0x00, state ? 0x0c : 0x0f);
if (state)
continue;
for (reg = 0x01; reg < ak->total_regs; reg++)
snd_akm4xxx_write(ak, chip, reg,
snd_akm4xxx_get(ak, chip, reg));
}
}
void snd_akm4xxx_reset(struct snd_akm4xxx *ak, int state)
{
switch (ak->type) {
case SND_AK4524:
case SND_AK4528:
case SND_AK4620:
ak4524_reset(ak, state);
break;
case SND_AK4529:
break;
case SND_AK4355:
ak435X_reset(ak, state);
break;
case SND_AK4358:
ak435X_reset(ak, state);
break;
case SND_AK4381:
ak4381_reset(ak, state);
break;
default:
break;
}
}
void snd_akm4xxx_init(struct snd_akm4xxx *ak)
{
static const unsigned char inits_ak4524[] = {
0x00, 0x07,
0x01, 0x00,
0x02, 0x60,
0x03, 0x19,
0x01, 0x03,
0x04, 0x00,
0x05, 0x00,
0x06, 0x00,
0x07, 0x00,
0xff, 0xff
};
static const unsigned char inits_ak4528[] = {
0x00, 0x07,
0x01, 0x00,
0x02, 0x60,
0x03, 0x0d,
0x01, 0x03,
0x04, 0x00,
0x05, 0x00,
0xff, 0xff
};
static const unsigned char inits_ak4529[] = {
0x09, 0x01,
0x0a, 0x3f,
0x00, 0x0c,
0x01, 0x00,
0x02, 0xff,
0x03, 0xff,
0x04, 0xff,
0x05, 0xff,
0x06, 0xff,
0x07, 0xff,
0x0b, 0xff,
0x0c, 0xff,
0x08, 0x55,
0xff, 0xff
};
static const unsigned char inits_ak4355[] = {
0x01, 0x02,
0x00, 0x06,
0x02, 0x0e,
0x03, 0x01,
0x04, 0x00,
0x05, 0x00,
0x06, 0x00,
0x07, 0x00,
0x08, 0x00,
0x09, 0x00,
0x0a, 0x00,
0x01, 0x01,
0xff, 0xff
};
static const unsigned char inits_ak4358[] = {
0x01, 0x02,
0x00, 0x06,
0x02, 0x4e,
0x03, 0x01,
0x04, 0x00,
0x05, 0x00,
0x06, 0x00,
0x07, 0x00,
0x08, 0x00,
0x09, 0x00,
0x0b, 0x00,
0x0c, 0x00,
0x0a, 0x00,
0x01, 0x01,
0xff, 0xff
};
static const unsigned char inits_ak4381[] = {
0x00, 0x0c,
0x01, 0x02,
0x02, 0x00,
0x03, 0x00,
0x04, 0x00,
0x00, 0x0f,
0xff, 0xff
};
static const unsigned char inits_ak4620[] = {
0x00, 0x07,
0x01, 0x00,
0x01, 0x02,
0x01, 0x03,
0x01, 0x0f,
0x02, 0x60,
0x03, 0x01,
0x04, 0x00,
0x05, 0x00,
0x06, 0x00,
0x07, 0x00,
0xff, 0xff
};
int chip;
const unsigned char *ptr, *inits;
unsigned char reg, data;
memset(ak->images, 0, sizeof(ak->images));
memset(ak->volumes, 0, sizeof(ak->volumes));
switch (ak->type) {
case SND_AK4524:
inits = inits_ak4524;
ak->num_chips = ak->num_dacs / 2;
ak->name = "ak4524";
ak->total_regs = 0x08;
break;
case SND_AK4528:
inits = inits_ak4528;
ak->num_chips = ak->num_dacs / 2;
ak->name = "ak4528";
ak->total_regs = 0x06;
break;
case SND_AK4529:
inits = inits_ak4529;
ak->num_chips = 1;
ak->name = "ak4529";
ak->total_regs = 0x0d;
break;
case SND_AK4355:
inits = inits_ak4355;
ak->num_chips = 1;
ak->name = "ak4355";
ak->total_regs = 0x0b;
break;
case SND_AK4358:
inits = inits_ak4358;
ak->num_chips = 1;
ak->name = "ak4358";
ak->total_regs = 0x10;
break;
case SND_AK4381:
inits = inits_ak4381;
ak->num_chips = ak->num_dacs / 2;
ak->name = "ak4381";
ak->total_regs = 0x05;
break;
case SND_AK5365:
ak->num_chips = 1;
ak->name = "ak5365";
ak->total_regs = 0x08;
return;
case SND_AK4620:
inits = inits_ak4620;
ak->num_chips = ak->num_dacs / 2;
ak->name = "ak4620";
ak->total_regs = 0x08;
break;
default:
snd_BUG();
return;
}
for (chip = 0; chip < ak->num_chips; chip++) {
ptr = inits;
while (*ptr != 0xff) {
reg = *ptr++;
data = *ptr++;
snd_akm4xxx_write(ak, chip, reg, data);
udelay(10);
}
}
}
static int snd_akm4xxx_volume_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
unsigned int mask = AK_GET_MASK(kcontrol->private_value);
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = mask;
return 0;
}
static int snd_akm4xxx_volume_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_akm4xxx *ak = snd_kcontrol_chip(kcontrol);
int chip = AK_GET_CHIP(kcontrol->private_value);
int addr = AK_GET_ADDR(kcontrol->private_value);
ucontrol->value.integer.value[0] = snd_akm4xxx_get_vol(ak, chip, addr);
return 0;
}
static int put_ak_reg(struct snd_kcontrol *kcontrol, int addr,
unsigned char nval)
{
struct snd_akm4xxx *ak = snd_kcontrol_chip(kcontrol);
unsigned int mask = AK_GET_MASK(kcontrol->private_value);
int chip = AK_GET_CHIP(kcontrol->private_value);
if (snd_akm4xxx_get_vol(ak, chip, addr) == nval)
return 0;
snd_akm4xxx_set_vol(ak, chip, addr, nval);
if (AK_GET_VOL_CVT(kcontrol->private_value) && nval < 128)
nval = vol_cvt_datt[nval];
if (AK_GET_IPGA(kcontrol->private_value) && nval >= 128)
nval++;
if (AK_GET_INVERT(kcontrol->private_value))
nval = mask - nval;
if (AK_GET_NEEDSMSB(kcontrol->private_value))
nval |= 0x80;
snd_akm4xxx_write(ak, chip, addr, nval);
return 1;
}
static int snd_akm4xxx_volume_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
unsigned int mask = AK_GET_MASK(kcontrol->private_value);
unsigned int val = ucontrol->value.integer.value[0];
if (val > mask)
return -EINVAL;
return put_ak_reg(kcontrol, AK_GET_ADDR(kcontrol->private_value), val);
}
static int snd_akm4xxx_stereo_volume_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
unsigned int mask = AK_GET_MASK(kcontrol->private_value);
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 2;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = mask;
return 0;
}
static int snd_akm4xxx_stereo_volume_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_akm4xxx *ak = snd_kcontrol_chip(kcontrol);
int chip = AK_GET_CHIP(kcontrol->private_value);
int addr = AK_GET_ADDR(kcontrol->private_value);
ucontrol->value.integer.value[0] = snd_akm4xxx_get_vol(ak, chip, addr);
ucontrol->value.integer.value[1] = snd_akm4xxx_get_vol(ak, chip, addr+1);
return 0;
}
static int snd_akm4xxx_stereo_volume_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
int addr = AK_GET_ADDR(kcontrol->private_value);
unsigned int mask = AK_GET_MASK(kcontrol->private_value);
unsigned int val[2];
int change;
val[0] = ucontrol->value.integer.value[0];
val[1] = ucontrol->value.integer.value[1];
if (val[0] > mask || val[1] > mask)
return -EINVAL;
change = put_ak_reg(kcontrol, addr, val[0]);
change |= put_ak_reg(kcontrol, addr + 1, val[1]);
return change;
}
static int snd_akm4xxx_deemphasis_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static char *texts[4] = {
"44.1kHz", "Off", "48kHz", "32kHz",
};
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = 4;
if (uinfo->value.enumerated.item >= 4)
uinfo->value.enumerated.item = 3;
strcpy(uinfo->value.enumerated.name,
texts[uinfo->value.enumerated.item]);
return 0;
}
static int snd_akm4xxx_deemphasis_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_akm4xxx *ak = snd_kcontrol_chip(kcontrol);
int chip = AK_GET_CHIP(kcontrol->private_value);
int addr = AK_GET_ADDR(kcontrol->private_value);
int shift = AK_GET_SHIFT(kcontrol->private_value);
ucontrol->value.enumerated.item[0] =
(snd_akm4xxx_get(ak, chip, addr) >> shift) & 3;
return 0;
}
static int snd_akm4xxx_deemphasis_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_akm4xxx *ak = snd_kcontrol_chip(kcontrol);
int chip = AK_GET_CHIP(kcontrol->private_value);
int addr = AK_GET_ADDR(kcontrol->private_value);
int shift = AK_GET_SHIFT(kcontrol->private_value);
unsigned char nval = ucontrol->value.enumerated.item[0] & 3;
int change;
nval = (nval << shift) |
(snd_akm4xxx_get(ak, chip, addr) & ~(3 << shift));
change = snd_akm4xxx_get(ak, chip, addr) != nval;
if (change)
snd_akm4xxx_write(ak, chip, addr, nval);
return change;
}
static int ak4xxx_switch_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_akm4xxx *ak = snd_kcontrol_chip(kcontrol);
int chip = AK_GET_CHIP(kcontrol->private_value);
int addr = AK_GET_ADDR(kcontrol->private_value);
int shift = AK_GET_SHIFT(kcontrol->private_value);
int invert = AK_GET_INVERT(kcontrol->private_value);
unsigned char val = snd_akm4xxx_get(ak, chip, addr) & (1<<shift);
if (invert)
val = ! val;
ucontrol->value.integer.value[0] = (val & (1<<shift)) != 0;
return 0;
}
static int ak4xxx_switch_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_akm4xxx *ak = snd_kcontrol_chip(kcontrol);
int chip = AK_GET_CHIP(kcontrol->private_value);
int addr = AK_GET_ADDR(kcontrol->private_value);
int shift = AK_GET_SHIFT(kcontrol->private_value);
int invert = AK_GET_INVERT(kcontrol->private_value);
long flag = ucontrol->value.integer.value[0];
unsigned char val, oval;
int change;
if (invert)
flag = ! flag;
oval = snd_akm4xxx_get(ak, chip, addr);
if (flag)
val = oval | (1<<shift);
else
val = oval & ~(1<<shift);
change = (oval != val);
if (change)
snd_akm4xxx_write(ak, chip, addr, val);
return change;
}
static int ak4xxx_capture_num_inputs(struct snd_akm4xxx *ak, int mixer_ch)
{
int num_names;
const char **input_names;
input_names = ak->adc_info[mixer_ch].input_names;
num_names = 0;
while (num_names < AK5365_NUM_INPUTS && input_names[num_names])
++num_names;
return num_names;
}
static int ak4xxx_capture_source_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct snd_akm4xxx *ak = snd_kcontrol_chip(kcontrol);
int mixer_ch = AK_GET_SHIFT(kcontrol->private_value);
const char **input_names;
unsigned int num_names, idx;
num_names = ak4xxx_capture_num_inputs(ak, mixer_ch);
if (!num_names)
return -EINVAL;
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = num_names;
idx = uinfo->value.enumerated.item;
if (idx >= num_names)
return -EINVAL;
input_names = ak->adc_info[mixer_ch].input_names;
strlcpy(uinfo->value.enumerated.name, input_names[idx],
sizeof(uinfo->value.enumerated.name));
return 0;
}
static int ak4xxx_capture_source_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_akm4xxx *ak = snd_kcontrol_chip(kcontrol);
int chip = AK_GET_CHIP(kcontrol->private_value);
int addr = AK_GET_ADDR(kcontrol->private_value);
int mask = AK_GET_MASK(kcontrol->private_value);
unsigned char val;
val = snd_akm4xxx_get(ak, chip, addr) & mask;
ucontrol->value.enumerated.item[0] = val;
return 0;
}
static int ak4xxx_capture_source_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_akm4xxx *ak = snd_kcontrol_chip(kcontrol);
int mixer_ch = AK_GET_SHIFT(kcontrol->private_value);
int chip = AK_GET_CHIP(kcontrol->private_value);
int addr = AK_GET_ADDR(kcontrol->private_value);
int mask = AK_GET_MASK(kcontrol->private_value);
unsigned char oval, val;
int num_names = ak4xxx_capture_num_inputs(ak, mixer_ch);
if (ucontrol->value.enumerated.item[0] >= num_names)
return -EINVAL;
oval = snd_akm4xxx_get(ak, chip, addr);
val = oval & ~mask;
val |= ucontrol->value.enumerated.item[0] & mask;
if (val != oval) {
snd_akm4xxx_write(ak, chip, addr, val);
return 1;
}
return 0;
}
static int build_dac_controls(struct snd_akm4xxx *ak)
{
int idx, err, mixer_ch, num_stereo;
struct snd_kcontrol_new knew;
mixer_ch = 0;
for (idx = 0; idx < ak->num_dacs; ) {
if (ak->type == SND_AK4381
&& ak->dac_info[mixer_ch].switch_name) {
memset(&knew, 0, sizeof(knew));
knew.iface = SNDRV_CTL_ELEM_IFACE_MIXER;
knew.count = 1;
knew.access = SNDRV_CTL_ELEM_ACCESS_READWRITE;
knew.name = ak->dac_info[mixer_ch].switch_name;
knew.info = ak4xxx_switch_info;
knew.get = ak4xxx_switch_get;
knew.put = ak4xxx_switch_put;
knew.access = 0;
knew.private_value =
AK_COMPOSE(idx/2, 1, 0, 0) | AK_INVERT;
err = snd_ctl_add(ak->card, snd_ctl_new1(&knew, ak));
if (err < 0)
return err;
}
memset(&knew, 0, sizeof(knew));
if (! ak->dac_info || ! ak->dac_info[mixer_ch].name) {
knew.name = "DAC Volume";
knew.index = mixer_ch + ak->idx_offset * 2;
num_stereo = 1;
} else {
knew.name = ak->dac_info[mixer_ch].name;
num_stereo = ak->dac_info[mixer_ch].num_channels;
}
knew.iface = SNDRV_CTL_ELEM_IFACE_MIXER;
knew.count = 1;
knew.access = SNDRV_CTL_ELEM_ACCESS_READWRITE |
SNDRV_CTL_ELEM_ACCESS_TLV_READ;
if (num_stereo == 2) {
knew.info = snd_akm4xxx_stereo_volume_info;
knew.get = snd_akm4xxx_stereo_volume_get;
knew.put = snd_akm4xxx_stereo_volume_put;
} else {
knew.info = snd_akm4xxx_volume_info;
knew.get = snd_akm4xxx_volume_get;
knew.put = snd_akm4xxx_volume_put;
}
switch (ak->type) {
case SND_AK4524:
knew.private_value =
AK_COMPOSE(idx/2, (idx%2) + 6, 0, 127) |
AK_VOL_CVT;
knew.tlv.p = db_scale_vol_datt;
break;
case SND_AK4528:
knew.private_value =
AK_COMPOSE(idx/2, (idx%2) + 4, 0, 127) |
AK_VOL_CVT;
knew.tlv.p = db_scale_vol_datt;
break;
case SND_AK4529: {
int val = idx < 6 ? idx + 2 : (idx - 6) + 0xb;
knew.private_value =
AK_COMPOSE(0, val, 0, 255) | AK_INVERT;
knew.tlv.p = db_scale_8bit;
break;
}
case SND_AK4355:
knew.private_value = AK_COMPOSE(0, idx + 4, 0, 255);
knew.tlv.p = db_scale_8bit;
break;
case SND_AK4358: {
int addr = idx < 6 ? idx + 4 : idx + 5;
knew.private_value =
AK_COMPOSE(0, addr, 0, 127) | AK_NEEDSMSB;
knew.tlv.p = db_scale_7bit;
break;
}
case SND_AK4381:
knew.private_value =
AK_COMPOSE(idx/2, (idx%2) + 3, 0, 255);
knew.tlv.p = db_scale_linear;
break;
case SND_AK4620:
knew.private_value =
AK_COMPOSE(idx/2, (idx%2) + 6, 0, 255);
knew.tlv.p = db_scale_linear;
break;
default:
return -EINVAL;
}
err = snd_ctl_add(ak->card, snd_ctl_new1(&knew, ak));
if (err < 0)
return err;
idx += num_stereo;
mixer_ch++;
}
return 0;
}
static int build_adc_controls(struct snd_akm4xxx *ak)
{
int idx, err, mixer_ch, num_stereo, max_steps;
struct snd_kcontrol_new knew;
mixer_ch = 0;
if (ak->type == SND_AK4528)
return 0;
for (idx = 0; idx < ak->num_adcs;) {
memset(&knew, 0, sizeof(knew));
if (! ak->adc_info || ! ak->adc_info[mixer_ch].name) {
knew.name = "ADC Volume";
knew.index = mixer_ch + ak->idx_offset * 2;
num_stereo = 1;
} else {
knew.name = ak->adc_info[mixer_ch].name;
num_stereo = ak->adc_info[mixer_ch].num_channels;
}
knew.iface = SNDRV_CTL_ELEM_IFACE_MIXER;
knew.count = 1;
knew.access = SNDRV_CTL_ELEM_ACCESS_READWRITE |
SNDRV_CTL_ELEM_ACCESS_TLV_READ;
if (num_stereo == 2) {
knew.info = snd_akm4xxx_stereo_volume_info;
knew.get = snd_akm4xxx_stereo_volume_get;
knew.put = snd_akm4xxx_stereo_volume_put;
} else {
knew.info = snd_akm4xxx_volume_info;
knew.get = snd_akm4xxx_volume_get;
knew.put = snd_akm4xxx_volume_put;
}
if (ak->type == SND_AK5365)
max_steps = 152;
else
max_steps = 164;
knew.private_value =
AK_COMPOSE(idx/2, (idx%2) + 4, 0, max_steps) |
AK_VOL_CVT | AK_IPGA;
knew.tlv.p = db_scale_vol_datt;
err = snd_ctl_add(ak->card, snd_ctl_new1(&knew, ak));
if (err < 0)
return err;
if (ak->type == SND_AK5365 && (idx % 2) == 0) {
if (! ak->adc_info ||
! ak->adc_info[mixer_ch].switch_name) {
knew.name = "Capture Switch";
knew.index = mixer_ch + ak->idx_offset * 2;
} else
knew.name = ak->adc_info[mixer_ch].switch_name;
knew.info = ak4xxx_switch_info;
knew.get = ak4xxx_switch_get;
knew.put = ak4xxx_switch_put;
knew.access = 0;
knew.private_value =
AK_COMPOSE(idx/2, 2, 0, 0) | AK_INVERT;
err = snd_ctl_add(ak->card, snd_ctl_new1(&knew, ak));
if (err < 0)
return err;
memset(&knew, 0, sizeof(knew));
knew.name = ak->adc_info[mixer_ch].selector_name;
if (!knew.name) {
knew.name = "Capture Channel";
knew.index = mixer_ch + ak->idx_offset * 2;
}
knew.iface = SNDRV_CTL_ELEM_IFACE_MIXER;
knew.info = ak4xxx_capture_source_info;
knew.get = ak4xxx_capture_source_get;
knew.put = ak4xxx_capture_source_put;
knew.access = 0;
knew.private_value
= AK_COMPOSE(idx/2, 1, mixer_ch, 0x07);
err = snd_ctl_add(ak->card, snd_ctl_new1(&knew, ak));
if (err < 0)
return err;
}
idx += num_stereo;
mixer_ch++;
}
return 0;
}
static int build_deemphasis(struct snd_akm4xxx *ak, int num_emphs)
{
int idx, err;
struct snd_kcontrol_new knew;
for (idx = 0; idx < num_emphs; idx++) {
memset(&knew, 0, sizeof(knew));
knew.name = "Deemphasis";
knew.index = idx + ak->idx_offset;
knew.iface = SNDRV_CTL_ELEM_IFACE_MIXER;
knew.count = 1;
knew.info = snd_akm4xxx_deemphasis_info;
knew.get = snd_akm4xxx_deemphasis_get;
knew.put = snd_akm4xxx_deemphasis_put;
switch (ak->type) {
case SND_AK4524:
case SND_AK4528:
case SND_AK4620:
knew.private_value = AK_COMPOSE(idx, 3, 0, 0);
break;
case SND_AK4529: {
int shift = idx == 3 ? 6 : (2 - idx) * 2;
knew.private_value = AK_COMPOSE(0, 8, shift, 0);
break;
}
case SND_AK4355:
case SND_AK4358:
knew.private_value = AK_COMPOSE(idx, 3, 0, 0);
break;
case SND_AK4381:
knew.private_value = AK_COMPOSE(idx, 1, 1, 0);
break;
default:
return -EINVAL;
}
err = snd_ctl_add(ak->card, snd_ctl_new1(&knew, ak));
if (err < 0)
return err;
}
return 0;
}
static void proc_regs_read(struct snd_info_entry *entry,
struct snd_info_buffer *buffer)
{
struct snd_akm4xxx *ak = entry->private_data;
int reg, val, chip;
for (chip = 0; chip < ak->num_chips; chip++) {
for (reg = 0; reg < ak->total_regs; reg++) {
val = snd_akm4xxx_get(ak, chip, reg);
snd_iprintf(buffer, "chip %d: 0x%02x = 0x%02x\n", chip,
reg, val);
}
}
}
static int proc_init(struct snd_akm4xxx *ak)
{
struct snd_info_entry *entry;
int err;
err = snd_card_proc_new(ak->card, ak->name, &entry);
if (err < 0)
return err;
snd_info_set_text_ops(entry, ak, proc_regs_read);
return 0;
}
static int proc_init(struct snd_akm4xxx *ak) { return 0; }
int snd_akm4xxx_build_controls(struct snd_akm4xxx *ak)
{
int err, num_emphs;
err = build_dac_controls(ak);
if (err < 0)
return err;
err = build_adc_controls(ak);
if (err < 0)
return err;
if (ak->type == SND_AK4355 || ak->type == SND_AK4358)
num_emphs = 1;
else if (ak->type == SND_AK4620)
num_emphs = 0;
else
num_emphs = ak->num_dacs / 2;
err = build_deemphasis(ak, num_emphs);
if (err < 0)
return err;
err = proc_init(ak);
if (err < 0)
return err;
return 0;
}
static int __init alsa_akm4xxx_module_init(void)
{
return 0;
}
static void __exit alsa_akm4xxx_module_exit(void)
{
}
