static void ca0106_spdif_enable(struct snd_ca0106 *emu)
{
unsigned int val;
if (emu->spdif_enable) {
snd_ca0106_ptr_write(emu, SPDIF_SELECT1, 0, 0xf);
snd_ca0106_ptr_write(emu, SPDIF_SELECT2, 0, 0x0b000000);
val = snd_ca0106_ptr_read(emu, CAPTURE_CONTROL, 0) & ~0x1000;
snd_ca0106_ptr_write(emu, CAPTURE_CONTROL, 0, val);
val = inl(emu->port + GPIO) & ~0x101;
outl(val, emu->port + GPIO);
} else {
snd_ca0106_ptr_write(emu, SPDIF_SELECT1, 0, 0xf);
snd_ca0106_ptr_write(emu, SPDIF_SELECT2, 0, 0x000f0000);
val = snd_ca0106_ptr_read(emu, CAPTURE_CONTROL, 0) | 0x1000;
snd_ca0106_ptr_write(emu, CAPTURE_CONTROL, 0, val);
val = inl(emu->port + GPIO) | 0x101;
outl(val, emu->port + GPIO);
}
}
static void ca0106_set_capture_source(struct snd_ca0106 *emu)
{
unsigned int val = emu->capture_source;
unsigned int source, mask;
source = (val << 28) | (val << 24) | (val << 20) | (val << 16);
mask = snd_ca0106_ptr_read(emu, CAPTURE_SOURCE, 0) & 0xffff;
snd_ca0106_ptr_write(emu, CAPTURE_SOURCE, 0, source | mask);
}
static void ca0106_set_i2c_capture_source(struct snd_ca0106 *emu,
unsigned int val, int force)
{
unsigned int ngain, ogain;
u32 source;
snd_ca0106_i2c_write(emu, ADC_MUX, 0);
ngain = emu->i2c_capture_volume[val][0];
ogain = emu->i2c_capture_volume[emu->i2c_capture_source][0];
if (force || ngain != ogain)
snd_ca0106_i2c_write(emu, ADC_ATTEN_ADCL, ngain & 0xff);
ngain = emu->i2c_capture_volume[val][1];
ogain = emu->i2c_capture_volume[emu->i2c_capture_source][1];
if (force || ngain != ogain)
snd_ca0106_i2c_write(emu, ADC_ATTEN_ADCR, ngain & 0xff);
source = 1 << val;
snd_ca0106_i2c_write(emu, ADC_MUX, source);
emu->i2c_capture_source = val;
}
static void ca0106_set_capture_mic_line_in(struct snd_ca0106 *emu)
{
u32 tmp;
if (emu->capture_mic_line_in) {
tmp = inl(emu->port+GPIO) & ~0x400;
tmp = tmp | 0x400;
outl(tmp, emu->port+GPIO);
} else {
tmp = inl(emu->port+GPIO) & ~0x400;
outl(tmp, emu->port+GPIO);
}
}
static void ca0106_set_spdif_bits(struct snd_ca0106 *emu, int idx)
{
snd_ca0106_ptr_write(emu, SPCS0 + idx, 0, emu->spdif_str_bits[idx]);
}
static int snd_ca0106_shared_spdif_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ca0106 *emu = snd_kcontrol_chip(kcontrol);
ucontrol->value.integer.value[0] = emu->spdif_enable;
return 0;
}
static int snd_ca0106_shared_spdif_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ca0106 *emu = snd_kcontrol_chip(kcontrol);
unsigned int val;
int change = 0;
val = !!ucontrol->value.integer.value[0];
change = (emu->spdif_enable != val);
if (change) {
emu->spdif_enable = val;
ca0106_spdif_enable(emu);
}
return change;
}
static int snd_ca0106_capture_source_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static const char * const texts[6] = {
"IEC958 out", "i2s mixer out", "IEC958 in", "i2s in", "AC97 in", "SRC out"
};
return snd_ctl_enum_info(uinfo, 1, 6, texts);
}
static int snd_ca0106_capture_source_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ca0106 *emu = snd_kcontrol_chip(kcontrol);
ucontrol->value.enumerated.item[0] = emu->capture_source;
return 0;
}
static int snd_ca0106_capture_source_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ca0106 *emu = snd_kcontrol_chip(kcontrol);
unsigned int val;
int change = 0;
val = ucontrol->value.enumerated.item[0] ;
if (val >= 6)
return -EINVAL;
change = (emu->capture_source != val);
if (change) {
emu->capture_source = val;
ca0106_set_capture_source(emu);
}
return change;
}
static int snd_ca0106_i2c_capture_source_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static const char * const texts[4] = {
"Phone", "Mic", "Line in", "Aux"
};
return snd_ctl_enum_info(uinfo, 1, 4, texts);
}
static int snd_ca0106_i2c_capture_source_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ca0106 *emu = snd_kcontrol_chip(kcontrol);
ucontrol->value.enumerated.item[0] = emu->i2c_capture_source;
return 0;
}
static int snd_ca0106_i2c_capture_source_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ca0106 *emu = snd_kcontrol_chip(kcontrol);
unsigned int source_id;
int change = 0;
source_id = ucontrol->value.enumerated.item[0] ;
if (source_id >= 4)
return -EINVAL;
change = (emu->i2c_capture_source != source_id);
if (change) {
ca0106_set_i2c_capture_source(emu, source_id, 0);
}
return change;
}
static int snd_ca0106_capture_line_in_side_out_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static const char * const texts[2] = { "Side out", "Line in" };
return snd_ctl_enum_info(uinfo, 1, 2, texts);
}
static int snd_ca0106_capture_mic_line_in_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static const char * const texts[2] = { "Line in", "Mic in" };
return snd_ctl_enum_info(uinfo, 1, 2, texts);
}
static int snd_ca0106_capture_mic_line_in_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ca0106 *emu = snd_kcontrol_chip(kcontrol);
ucontrol->value.enumerated.item[0] = emu->capture_mic_line_in;
return 0;
}
static int snd_ca0106_capture_mic_line_in_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ca0106 *emu = snd_kcontrol_chip(kcontrol);
unsigned int val;
int change = 0;
val = ucontrol->value.enumerated.item[0] ;
if (val > 1)
return -EINVAL;
change = (emu->capture_mic_line_in != val);
if (change) {
emu->capture_mic_line_in = val;
ca0106_set_capture_mic_line_in(emu);
}
return change;
}
static int snd_ca0106_spdif_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_IEC958;
uinfo->count = 1;
return 0;
}
static void decode_spdif_bits(unsigned char *status, unsigned int bits)
{
status[0] = (bits >> 0) & 0xff;
status[1] = (bits >> 8) & 0xff;
status[2] = (bits >> 16) & 0xff;
status[3] = (bits >> 24) & 0xff;
}
static int snd_ca0106_spdif_get_default(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ca0106 *emu = snd_kcontrol_chip(kcontrol);
unsigned int idx = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
decode_spdif_bits(ucontrol->value.iec958.status,
emu->spdif_bits[idx]);
return 0;
}
static int snd_ca0106_spdif_get_stream(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ca0106 *emu = snd_kcontrol_chip(kcontrol);
unsigned int idx = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
decode_spdif_bits(ucontrol->value.iec958.status,
emu->spdif_str_bits[idx]);
return 0;
}
static int snd_ca0106_spdif_get_mask(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
ucontrol->value.iec958.status[0] = 0xff;
ucontrol->value.iec958.status[1] = 0xff;
ucontrol->value.iec958.status[2] = 0xff;
ucontrol->value.iec958.status[3] = 0xff;
return 0;
}
static unsigned int encode_spdif_bits(unsigned char *status)
{
return ((unsigned int)status[0] << 0) |
((unsigned int)status[1] << 8) |
((unsigned int)status[2] << 16) |
((unsigned int)status[3] << 24);
}
static int snd_ca0106_spdif_put_default(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ca0106 *emu = snd_kcontrol_chip(kcontrol);
unsigned int idx = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
unsigned int val;
val = encode_spdif_bits(ucontrol->value.iec958.status);
if (val != emu->spdif_bits[idx]) {
emu->spdif_bits[idx] = val;
emu->spdif_str_bits[idx] = val;
ca0106_set_spdif_bits(emu, idx);
return 1;
}
return 0;
}
static int snd_ca0106_spdif_put_stream(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ca0106 *emu = snd_kcontrol_chip(kcontrol);
unsigned int idx = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
unsigned int val;
val = encode_spdif_bits(ucontrol->value.iec958.status);
if (val != emu->spdif_str_bits[idx]) {
emu->spdif_str_bits[idx] = val;
ca0106_set_spdif_bits(emu, idx);
return 1;
}
return 0;
}
static int snd_ca0106_volume_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 2;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 255;
return 0;
}
static int snd_ca0106_volume_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ca0106 *emu = snd_kcontrol_chip(kcontrol);
unsigned int value;
int channel_id, reg;
channel_id = (kcontrol->private_value >> 8) & 0xff;
reg = kcontrol->private_value & 0xff;
value = snd_ca0106_ptr_read(emu, reg, channel_id);
ucontrol->value.integer.value[0] = 0xff - ((value >> 24) & 0xff);
ucontrol->value.integer.value[1] = 0xff - ((value >> 16) & 0xff);
return 0;
}
static int snd_ca0106_volume_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ca0106 *emu = snd_kcontrol_chip(kcontrol);
unsigned int oval, nval;
int channel_id, reg;
channel_id = (kcontrol->private_value >> 8) & 0xff;
reg = kcontrol->private_value & 0xff;
oval = snd_ca0106_ptr_read(emu, reg, channel_id);
nval = ((0xff - ucontrol->value.integer.value[0]) << 24) |
((0xff - ucontrol->value.integer.value[1]) << 16);
nval |= ((0xff - ucontrol->value.integer.value[0]) << 8) |
((0xff - ucontrol->value.integer.value[1]) );
if (oval == nval)
return 0;
snd_ca0106_ptr_write(emu, reg, channel_id, nval);
return 1;
}
static int snd_ca0106_i2c_volume_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 2;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 255;
return 0;
}
static int snd_ca0106_i2c_volume_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ca0106 *emu = snd_kcontrol_chip(kcontrol);
int source_id;
source_id = kcontrol->private_value;
ucontrol->value.integer.value[0] = emu->i2c_capture_volume[source_id][0];
ucontrol->value.integer.value[1] = emu->i2c_capture_volume[source_id][1];
return 0;
}
static int snd_ca0106_i2c_volume_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ca0106 *emu = snd_kcontrol_chip(kcontrol);
unsigned int ogain;
unsigned int ngain;
int source_id;
int change = 0;
source_id = kcontrol->private_value;
ogain = emu->i2c_capture_volume[source_id][0];
ngain = ucontrol->value.integer.value[0];
if (ngain > 0xff)
return -EINVAL;
if (ogain != ngain) {
if (emu->i2c_capture_source == source_id)
snd_ca0106_i2c_write(emu, ADC_ATTEN_ADCL, ((ngain) & 0xff) );
emu->i2c_capture_volume[source_id][0] = ucontrol->value.integer.value[0];
change = 1;
}
ogain = emu->i2c_capture_volume[source_id][1];
ngain = ucontrol->value.integer.value[1];
if (ngain > 0xff)
return -EINVAL;
if (ogain != ngain) {
if (emu->i2c_capture_source == source_id)
snd_ca0106_i2c_write(emu, ADC_ATTEN_ADCR, ((ngain) & 0xff));
emu->i2c_capture_volume[source_id][1] = ucontrol->value.integer.value[1];
change = 1;
}
return change;
}
static int spi_mute_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ca0106 *emu = snd_kcontrol_chip(kcontrol);
unsigned int reg = kcontrol->private_value >> SPI_REG_SHIFT;
unsigned int bit = kcontrol->private_value & SPI_REG_MASK;
ucontrol->value.integer.value[0] = !(emu->spi_dac_reg[reg] & bit);
return 0;
}
static int spi_mute_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ca0106 *emu = snd_kcontrol_chip(kcontrol);
unsigned int reg = kcontrol->private_value >> SPI_REG_SHIFT;
unsigned int bit = kcontrol->private_value & SPI_REG_MASK;
int ret;
ret = emu->spi_dac_reg[reg] & bit;
if (ucontrol->value.integer.value[0]) {
if (!ret)
return 0;
emu->spi_dac_reg[reg] &= ~bit;
} else {
if (ret)
return 0;
emu->spi_dac_reg[reg] |= bit;
}
ret = snd_ca0106_spi_write(emu, emu->spi_dac_reg[reg]);
return ret ? -EINVAL : 1;
}
static struct snd_kcontrol_new
snd_ca0106_volume_spi_dac_ctl(struct snd_ca0106_details *details,
int channel_id)
{
struct snd_kcontrol_new spi_switch = {0};
int reg, bit;
int dac_id;
spi_switch.iface = SNDRV_CTL_ELEM_IFACE_MIXER;
spi_switch.access = SNDRV_CTL_ELEM_ACCESS_READWRITE;
spi_switch.info = spi_mute_info;
spi_switch.get = spi_mute_get;
spi_switch.put = spi_mute_put;
switch (channel_id) {
case PCM_FRONT_CHANNEL:
spi_switch.name = "Analog Front Playback Switch";
dac_id = (details->spi_dac & 0xf000) >> (4 * 3);
break;
case PCM_REAR_CHANNEL:
spi_switch.name = "Analog Rear Playback Switch";
dac_id = (details->spi_dac & 0x0f00) >> (4 * 2);
break;
case PCM_CENTER_LFE_CHANNEL:
spi_switch.name = "Analog Center/LFE Playback Switch";
dac_id = (details->spi_dac & 0x00f0) >> (4 * 1);
break;
case PCM_UNKNOWN_CHANNEL:
spi_switch.name = "Analog Side Playback Switch";
dac_id = (details->spi_dac & 0x000f) >> (4 * 0);
break;
default:
spi_switch.name = NULL;
dac_id = 0;
}
reg = spi_dmute_reg[dac_id];
bit = spi_dmute_bit[dac_id];
spi_switch.private_value = (reg << SPI_REG_SHIFT) | bit;
return spi_switch;
}
static int remove_ctl(struct snd_card *card, const char *name)
{
struct snd_ctl_elem_id id;
memset(&id, 0, sizeof(id));
strcpy(id.name, name);
id.iface = SNDRV_CTL_ELEM_IFACE_MIXER;
return snd_ctl_remove_id(card, &id);
}
static struct snd_kcontrol *ctl_find(struct snd_card *card, const char *name)
{
struct snd_ctl_elem_id sid;
memset(&sid, 0, sizeof(sid));
strcpy(sid.name, name);
sid.iface = SNDRV_CTL_ELEM_IFACE_MIXER;
return snd_ctl_find_id(card, &sid);
}
static int rename_ctl(struct snd_card *card, const char *src, const char *dst)
{
struct snd_kcontrol *kctl = ctl_find(card, src);
if (kctl) {
strcpy(kctl->id.name, dst);
return 0;
}
return -ENOENT;
}
static void add_slaves(struct snd_card *card,
struct snd_kcontrol *master, char **list)
{
for (; *list; list++) {
struct snd_kcontrol *slave = ctl_find(card, *list);
if (slave)
snd_ctl_add_slave(master, slave);
}
}
int snd_ca0106_mixer(struct snd_ca0106 *emu)
{
int err;
struct snd_card *card = emu->card;
char **c;
struct snd_kcontrol *vmaster;
static char *ca0106_remove_ctls[] = {
"Master Mono Playback Switch",
"Master Mono Playback Volume",
"3D Control - Switch",
"3D Control Sigmatel - Depth",
"PCM Playback Switch",
"PCM Playback Volume",
"CD Playback Switch",
"CD Playback Volume",
"Phone Playback Switch",
"Phone Playback Volume",
"Video Playback Switch",
"Video Playback Volume",
"Beep Playback Switch",
"Beep Playback Volume",
"Mono Output Select",
"Capture Source",
"Capture Switch",
"Capture Volume",
"External Amplifier",
"Sigmatel 4-Speaker Stereo Playback Switch",
"Surround Phase Inversion Playback Switch",
NULL
};
static char *ca0106_rename_ctls[] = {
"Master Playback Switch", "Capture Switch",
"Master Playback Volume", "Capture Volume",
"Line Playback Switch", "AC97 Line Capture Switch",
"Line Playback Volume", "AC97 Line Capture Volume",
"Aux Playback Switch", "AC97 Aux Capture Switch",
"Aux Playback Volume", "AC97 Aux Capture Volume",
"Mic Playback Switch", "AC97 Mic Capture Switch",
"Mic Playback Volume", "AC97 Mic Capture Volume",
"Mic Select", "AC97 Mic Select",
"Mic Boost (+20dB)", "AC97 Mic Boost (+20dB)",
NULL
};
#if 1
for (c = ca0106_remove_ctls; *c; c++)
remove_ctl(card, *c);
for (c = ca0106_rename_ctls; *c; c += 2)
rename_ctl(card, c[0], c[1]);
#endif
ADD_CTLS(emu, snd_ca0106_volume_ctls);
if (emu->details->i2c_adc == 1) {
ADD_CTLS(emu, snd_ca0106_volume_i2c_adc_ctls);
if (emu->details->gpio_type == 1)
err = snd_ctl_add(card, snd_ctl_new1(&snd_ca0106_capture_mic_line_in, emu));
else
err = snd_ctl_add(card, snd_ctl_new1(&snd_ca0106_capture_line_in_side_out, emu));
if (err < 0)
return err;
}
if (emu->details->spi_dac) {
int i;
for (i = 0;; i++) {
struct snd_kcontrol_new ctl;
ctl = snd_ca0106_volume_spi_dac_ctl(emu->details, i);
if (!ctl.name)
break;
err = snd_ctl_add(card, snd_ctl_new1(&ctl, emu));
if (err < 0)
return err;
}
}
vmaster = snd_ctl_make_virtual_master("Master Playback Volume",
snd_ca0106_master_db_scale);
if (!vmaster)
return -ENOMEM;
err = snd_ctl_add(card, vmaster);
if (err < 0)
return err;
add_slaves(card, vmaster, slave_vols);
if (emu->details->spi_dac) {
vmaster = snd_ctl_make_virtual_master("Master Playback Switch",
NULL);
if (!vmaster)
return -ENOMEM;
err = snd_ctl_add(card, vmaster);
if (err < 0)
return err;
add_slaves(card, vmaster, slave_sws);
}
strcpy(card->mixername, "CA0106");
return 0;
}
void snd_ca0106_mixer_suspend(struct snd_ca0106 *chip)
{
int i;
for (i = 0; i < NUM_SAVED_VOLUMES; i++)
chip->saved_vol[i] =
snd_ca0106_ptr_read(chip, saved_volumes[i].reg,
saved_volumes[i].channel_id);
}
void snd_ca0106_mixer_resume(struct snd_ca0106 *chip)
{
int i;
for (i = 0; i < NUM_SAVED_VOLUMES; i++)
snd_ca0106_ptr_write(chip, saved_volumes[i].reg,
saved_volumes[i].channel_id,
chip->saved_vol[i]);
ca0106_spdif_enable(chip);
ca0106_set_capture_source(chip);
ca0106_set_i2c_capture_source(chip, chip->i2c_capture_source, 1);
for (i = 0; i < 4; i++)
ca0106_set_spdif_bits(chip, i);
if (chip->details->i2c_adc)
ca0106_set_capture_mic_line_in(chip);
}
