static inline void stac9460_put(struct snd_ice1712 *ice, int reg, unsigned char val)
{
snd_vt1724_write_i2c(ice, PRODIGY192_STAC9460_ADDR, reg, val);
}
static inline unsigned char stac9460_get(struct snd_ice1712 *ice, int reg)
{
return snd_vt1724_read_i2c(ice, PRODIGY192_STAC9460_ADDR, reg);
}
static int stac9460_dac_mute(struct snd_ice1712 *ice, int idx,
unsigned char mute)
{
unsigned char new, old;
int change;
old = stac9460_get(ice, idx);
new = (~mute << 7 & 0x80) | (old & ~0x80);
change = (new != old);
if (change)
stac9460_put(ice, idx, new);
return change;
}
static int stac9460_dac_mute_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned char val;
int idx;
if (kcontrol->private_value)
idx = STAC946X_MASTER_VOLUME;
else
idx = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id) + STAC946X_LF_VOLUME;
val = stac9460_get(ice, idx);
ucontrol->value.integer.value[0] = (~val >> 7) & 0x1;
return 0;
}
static int stac9460_dac_mute_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
struct prodigy192_spec *spec = ice->spec;
int idx, change;
if (kcontrol->private_value)
idx = STAC946X_MASTER_VOLUME;
else
idx = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id) + STAC946X_LF_VOLUME;
mutex_lock(&spec->mute_mutex);
change = stac9460_dac_mute(ice, idx, ucontrol->value.integer.value[0]);
mutex_unlock(&spec->mute_mutex);
return change;
}
static int stac9460_dac_vol_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 0x7f;
return 0;
}
static int stac9460_dac_vol_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
int idx;
unsigned char vol;
if (kcontrol->private_value)
idx = STAC946X_MASTER_VOLUME;
else
idx = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id) + STAC946X_LF_VOLUME;
vol = stac9460_get(ice, idx) & 0x7f;
ucontrol->value.integer.value[0] = 0x7f - vol;
return 0;
}
static int stac9460_dac_vol_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
int idx;
unsigned char tmp, ovol, nvol;
int change;
if (kcontrol->private_value)
idx = STAC946X_MASTER_VOLUME;
else
idx = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id) + STAC946X_LF_VOLUME;
nvol = ucontrol->value.integer.value[0];
tmp = stac9460_get(ice, idx);
ovol = 0x7f - (tmp & 0x7f);
change = (ovol != nvol);
if (change) {
ovol = (0x7f - nvol) | (tmp & 0x80);
stac9460_put(ice, idx, (0x7f - nvol) | (tmp & 0x80));
}
return change;
}
static int stac9460_adc_mute_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned char val;
int i;
for (i = 0; i < 2; ++i) {
val = stac9460_get(ice, STAC946X_MIC_L_VOLUME + i);
ucontrol->value.integer.value[i] = ~val>>7 & 0x1;
}
return 0;
}
static int stac9460_adc_mute_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned char new, old;
int i, reg;
int change;
for (i = 0; i < 2; ++i) {
reg = STAC946X_MIC_L_VOLUME + i;
old = stac9460_get(ice, reg);
new = (~ucontrol->value.integer.value[i]<<7&0x80) | (old&~0x80);
change = (new != old);
if (change)
stac9460_put(ice, reg, new);
}
return change;
}
static int stac9460_adc_vol_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 2;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 0x0f;
return 0;
}
static int stac9460_adc_vol_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
int i, reg;
unsigned char vol;
for (i = 0; i < 2; ++i) {
reg = STAC946X_MIC_L_VOLUME + i;
vol = stac9460_get(ice, reg) & 0x0f;
ucontrol->value.integer.value[i] = 0x0f - vol;
}
return 0;
}
static int stac9460_adc_vol_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
int i, reg;
unsigned char ovol, nvol;
int change;
for (i = 0; i < 2; ++i) {
reg = STAC946X_MIC_L_VOLUME + i;
nvol = ucontrol->value.integer.value[i] & 0x0f;
ovol = 0x0f - stac9460_get(ice, reg);
change = ((ovol & 0x0f) != nvol);
if (change)
stac9460_put(ice, reg, (0x0f - nvol) | (ovol & ~0x0f));
}
return change;
}
static int stac9460_mic_sw_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static char *texts[2] = { "Line In", "Mic" };
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = 2;
if (uinfo->value.enumerated.item >= uinfo->value.enumerated.items)
uinfo->value.enumerated.item = uinfo->value.enumerated.items - 1;
strcpy(uinfo->value.enumerated.name, texts[uinfo->value.enumerated.item]);
return 0;
}
static int stac9460_mic_sw_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned char val;
val = stac9460_get(ice, STAC946X_GENERAL_PURPOSE);
ucontrol->value.enumerated.item[0] = (val >> 7) & 0x1;
return 0;
}
static int stac9460_mic_sw_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned char new, old;
int change;
old = stac9460_get(ice, STAC946X_GENERAL_PURPOSE);
new = (ucontrol->value.enumerated.item[0] << 7 & 0x80) | (old & ~0x80);
change = (new != old);
if (change)
stac9460_put(ice, STAC946X_GENERAL_PURPOSE, new);
return change;
}
static void stac9460_set_rate_val(struct snd_ice1712 *ice, unsigned int rate)
{
unsigned char old, new;
int idx;
unsigned char changed[7];
struct prodigy192_spec *spec = ice->spec;
if (rate == 0)
return;
else if (rate <= 48000)
new = 0x08;
else if (rate <= 96000)
new = 0x11;
else
new = 0x12;
old = stac9460_get(ice, STAC946X_MASTER_CLOCKING);
if (old == new)
return;
mutex_lock(&spec->mute_mutex);
for (idx = 0; idx < 7 ; ++idx)
changed[idx] = stac9460_dac_mute(ice,
STAC946X_MASTER_VOLUME + idx, 0);
stac9460_put(ice, STAC946X_MASTER_CLOCKING, new);
udelay(10);
for (idx = 0; idx < 7 ; ++idx) {
if (changed[idx])
stac9460_dac_mute(ice, STAC946X_MASTER_VOLUME + idx, 1);
}
mutex_unlock(&spec->mute_mutex);
}
static void write_data(struct snd_ice1712 *ice, unsigned int gpio,
unsigned int data, int idx)
{
for (; idx >= 0; idx--) {
gpio &= ~VT1724_PRODIGY192_CCLK;
snd_ice1712_gpio_write(ice, gpio);
udelay(1);
if (data & (1 << idx))
gpio |= VT1724_PRODIGY192_CDOUT;
else
gpio &= ~VT1724_PRODIGY192_CDOUT;
snd_ice1712_gpio_write(ice, gpio);
udelay(1);
gpio |= VT1724_PRODIGY192_CCLK;
snd_ice1712_gpio_write(ice, gpio);
udelay(1);
}
}
static unsigned char read_data(struct snd_ice1712 *ice, unsigned int gpio,
int idx)
{
unsigned char data = 0;
for (; idx >= 0; idx--) {
gpio &= ~VT1724_PRODIGY192_CCLK;
snd_ice1712_gpio_write(ice, gpio);
udelay(1);
if (snd_ice1712_gpio_read(ice) & VT1724_PRODIGY192_CDIN)
data |= (1 << idx);
udelay(1);
gpio |= VT1724_PRODIGY192_CCLK;
snd_ice1712_gpio_write(ice, gpio);
udelay(1);
}
return data;
}
static unsigned int prodigy192_4wire_start(struct snd_ice1712 *ice)
{
unsigned int tmp;
snd_ice1712_save_gpio_status(ice);
tmp = snd_ice1712_gpio_read(ice);
tmp |= VT1724_PRODIGY192_CCLK;
tmp &= ~VT1724_PRODIGY192_CS;
snd_ice1712_gpio_write(ice, tmp);
udelay(1);
return tmp;
}
static void prodigy192_4wire_finish(struct snd_ice1712 *ice, unsigned int tmp)
{
tmp |= VT1724_PRODIGY192_CS;
snd_ice1712_gpio_write(ice, tmp);
udelay(1);
snd_ice1712_restore_gpio_status(ice);
}
static void prodigy192_ak4114_write(void *private_data, unsigned char addr,
unsigned char data)
{
struct snd_ice1712 *ice = private_data;
unsigned int tmp, addrdata;
tmp = prodigy192_4wire_start(ice);
addrdata = (AK4114_ADDR << 6) | 0x20 | (addr & 0x1f);
addrdata = (addrdata << 8) | data;
write_data(ice, tmp, addrdata, 15);
prodigy192_4wire_finish(ice, tmp);
}
static unsigned char prodigy192_ak4114_read(void *private_data,
unsigned char addr)
{
struct snd_ice1712 *ice = private_data;
unsigned int tmp;
unsigned char data;
tmp = prodigy192_4wire_start(ice);
write_data(ice, tmp, (AK4114_ADDR << 6) | (addr & 0x1f), 7);
data = read_data(ice, tmp, 7);
prodigy192_4wire_finish(ice, tmp);
return data;
}
static int ak4114_input_sw_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static char *texts[2] = { "Toslink", "Coax" };
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = 2;
if (uinfo->value.enumerated.item >= uinfo->value.enumerated.items)
uinfo->value.enumerated.item = uinfo->value.enumerated.items - 1;
strcpy(uinfo->value.enumerated.name, texts[uinfo->value.enumerated.item]);
return 0;
}
static int ak4114_input_sw_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned char val;
val = prodigy192_ak4114_read(ice, AK4114_REG_IO1);
ucontrol->value.enumerated.item[0] = (val & AK4114_IPS0) ? 1 : 0;
return 0;
}
static int ak4114_input_sw_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned char new, old, itemvalue;
int change;
old = prodigy192_ak4114_read(ice, AK4114_REG_IO1);
itemvalue = (ucontrol->value.enumerated.item[0]) ? 0xff : 0x00;
new = (itemvalue & AK4114_IPS0) | (old & ~AK4114_IPS0);
change = (new != old);
if (change)
prodigy192_ak4114_write(ice, AK4114_REG_IO1, new);
return change;
}
static int prodigy192_ak4114_init(struct snd_ice1712 *ice)
{
static const unsigned char ak4114_init_vals[] = {
AK4114_RST | AK4114_PWN | AK4114_OCKS0 | AK4114_OCKS1,
AK4114_DIF_I24I2S | AK4114_DEM0 ,
AK4114_TX1E,
AK4114_EFH_1024 | AK4114_DIT,
0,
0
};
static const unsigned char ak4114_init_txcsb[] = {
0x41, 0x02, 0x2c, 0x00, 0x00
};
struct prodigy192_spec *spec = ice->spec;
int err;
err = snd_ak4114_create(ice->card,
prodigy192_ak4114_read,
prodigy192_ak4114_write,
ak4114_init_vals, ak4114_init_txcsb,
ice, &spec->ak4114);
if (err < 0)
return err;
spec->ak4114->check_flags = AK4114_CHECK_NO_RATE;
return 0;
}
static void stac9460_proc_regs_read(struct snd_info_entry *entry,
struct snd_info_buffer *buffer)
{
struct snd_ice1712 *ice = entry->private_data;
int reg, val;
for (reg = 0; reg <= 0x15; reg++) {
val = stac9460_get(ice, reg);
snd_iprintf(buffer, "0x%02x = 0x%02x\n", reg, val);
}
}
static void stac9460_proc_init(struct snd_ice1712 *ice)
{
struct snd_info_entry *entry;
if (!snd_card_proc_new(ice->card, "stac9460_codec", &entry))
snd_info_set_text_ops(entry, ice, stac9460_proc_regs_read);
}
static int __devinit prodigy192_add_controls(struct snd_ice1712 *ice)
{
struct prodigy192_spec *spec = ice->spec;
unsigned int i;
int err;
for (i = 0; i < ARRAY_SIZE(stac_controls); i++) {
err = snd_ctl_add(ice->card,
snd_ctl_new1(&stac_controls[i], ice));
if (err < 0)
return err;
}
if (spec->ak4114) {
for (i = 0; i < ARRAY_SIZE(ak4114_controls); i++) {
err = snd_ctl_add(ice->card,
snd_ctl_new1(&ak4114_controls[i],
ice));
if (err < 0)
return err;
}
err = snd_ak4114_build(spec->ak4114,
NULL,
ice->pcm->streams[SNDRV_PCM_STREAM_CAPTURE].substream);
if (err < 0)
return err;
}
stac9460_proc_init(ice);
return 0;
}
static int prodigy192_miodio_exists(struct snd_ice1712 *ice)
{
unsigned char orig_value;
const unsigned char test_data = 0xd1;
unsigned char addr = AK4114_REG_INT0_MASK;
int exists = 0;
orig_value = prodigy192_ak4114_read(ice, addr);
prodigy192_ak4114_write(ice, addr, test_data);
if (prodigy192_ak4114_read(ice, addr) == test_data) {
prodigy192_ak4114_write(ice, addr, orig_value);
exists = 1;
}
return exists;
}
static int __devinit prodigy192_init(struct snd_ice1712 *ice)
{
static const unsigned short stac_inits_prodigy[] = {
STAC946X_RESET, 0,
STAC946X_MASTER_CLOCKING, 0x11,
(unsigned short)-1
};
const unsigned short *p;
int err = 0;
struct prodigy192_spec *spec;
ice->num_total_dacs = 6;
ice->num_total_adcs = 2;
ice->vt1720 = 0;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (!spec)
return -ENOMEM;
ice->spec = spec;
mutex_init(&spec->mute_mutex);
p = stac_inits_prodigy;
for (; *p != (unsigned short)-1; p += 2)
stac9460_put(ice, p[0], p[1]);
ice->gpio.set_pro_rate = stac9460_set_rate_val;
if (prodigy192_miodio_exists(ice)) {
err = prodigy192_ak4114_init(ice);
snd_printdd("AK4114 initialized with status %d\n", err);
} else
snd_printdd("AK4114 not found\n");
if (err < 0)
return err;
return 0;
}
