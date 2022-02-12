static unsigned short wm_get(struct snd_ice1712 *ice, int reg)
{
reg <<= 1;
return ((unsigned short)ice->akm[0].images[reg] << 8) |
ice->akm[0].images[reg + 1];
}
static void wm_put_nocache(struct snd_ice1712 *ice, int reg, unsigned short val)
{
unsigned short cval;
cval = (reg << 9) | val;
snd_vt1724_write_i2c(ice, WM_DEV, cval >> 8, cval & 0xff);
}
static void wm_put(struct snd_ice1712 *ice, int reg, unsigned short val)
{
wm_put_nocache(ice, reg, val);
reg <<= 1;
ice->akm[0].images[reg] = val >> 8;
ice->akm[0].images[reg + 1] = val;
}
static int wm_dac_vol_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 2;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = DAC_RES;
return 0;
}
static int wm_dac_vol_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned short val;
int i;
mutex_lock(&ice->gpio_mutex);
for (i = 0; i < 2; i++) {
val = wm_get(ice, WM_DAC_ATTEN_L + i) & 0xff;
val = val > DAC_MIN ? (val - DAC_MIN) : 0;
ucontrol->value.integer.value[i] = val;
}
mutex_unlock(&ice->gpio_mutex);
return 0;
}
static int wm_dac_vol_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned short oval, nval;
int i, idx, change = 0;
mutex_lock(&ice->gpio_mutex);
for (i = 0; i < 2; i++) {
nval = ucontrol->value.integer.value[i];
nval = (nval ? (nval + DAC_MIN) : 0) & 0xff;
idx = WM_DAC_ATTEN_L + i;
oval = wm_get(ice, idx) & 0xff;
if (oval != nval) {
wm_put(ice, idx, nval);
wm_put_nocache(ice, idx, nval | 0x100);
change = 1;
}
}
mutex_unlock(&ice->gpio_mutex);
return change;
}
static int wm_adc_vol_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 2;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = ADC_RES;
return 0;
}
static int wm_adc_vol_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned short val;
int i;
mutex_lock(&ice->gpio_mutex);
for (i = 0; i < 2; i++) {
val = wm_get(ice, WM_ADC_ATTEN_L + i) & 0xff;
val = val > ADC_MIN ? (val - ADC_MIN) : 0;
ucontrol->value.integer.value[i] = val;
}
mutex_unlock(&ice->gpio_mutex);
return 0;
}
static int wm_adc_vol_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned short ovol, nvol;
int i, idx, change = 0;
mutex_lock(&ice->gpio_mutex);
for (i = 0; i < 2; i++) {
nvol = ucontrol->value.integer.value[i];
nvol = nvol ? (nvol + ADC_MIN) : 0;
idx = WM_ADC_ATTEN_L + i;
ovol = wm_get(ice, idx) & 0xff;
if (ovol != nvol) {
wm_put(ice, idx, nvol);
change = 1;
}
}
mutex_unlock(&ice->gpio_mutex);
return change;
}
static int wm_adc_mux_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
int bit = kcontrol->private_value;
mutex_lock(&ice->gpio_mutex);
ucontrol->value.integer.value[0] = (wm_get(ice, WM_ADC_MUX) & (1 << bit)) ? 1 : 0;
mutex_unlock(&ice->gpio_mutex);
return 0;
}
static int wm_adc_mux_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
int bit = kcontrol->private_value;
unsigned short oval, nval;
int change;
mutex_lock(&ice->gpio_mutex);
nval = oval = wm_get(ice, WM_ADC_MUX);
if (ucontrol->value.integer.value[0])
nval |= (1 << bit);
else
nval &= ~(1 << bit);
change = nval != oval;
if (change) {
wm_put(ice, WM_ADC_MUX, nval);
}
mutex_unlock(&ice->gpio_mutex);
return change;
}
static int wm_bypass_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
mutex_lock(&ice->gpio_mutex);
ucontrol->value.integer.value[0] = (wm_get(ice, WM_OUT_MUX) & 0x04) ? 1 : 0;
mutex_unlock(&ice->gpio_mutex);
return 0;
}
static int wm_bypass_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned short val, oval;
int change = 0;
mutex_lock(&ice->gpio_mutex);
val = oval = wm_get(ice, WM_OUT_MUX);
if (ucontrol->value.integer.value[0])
val |= 0x04;
else
val &= ~0x04;
if (val != oval) {
wm_put(ice, WM_OUT_MUX, val);
change = 1;
}
mutex_unlock(&ice->gpio_mutex);
return change;
}
static int wm_chswap_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
mutex_lock(&ice->gpio_mutex);
ucontrol->value.integer.value[0] = (wm_get(ice, WM_DAC_CTRL1) & 0xf0) != 0x90;
mutex_unlock(&ice->gpio_mutex);
return 0;
}
static int wm_chswap_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned short val, oval;
int change = 0;
mutex_lock(&ice->gpio_mutex);
oval = wm_get(ice, WM_DAC_CTRL1);
val = oval & 0x0f;
if (ucontrol->value.integer.value[0])
val |= 0x60;
else
val |= 0x90;
if (val != oval) {
wm_put(ice, WM_DAC_CTRL1, val);
wm_put_nocache(ice, WM_DAC_CTRL1, val);
change = 1;
}
mutex_unlock(&ice->gpio_mutex);
return change;
}
static void set_gpio_bit(struct snd_ice1712 *ice, unsigned int bit, int val)
{
unsigned int tmp = snd_ice1712_gpio_read(ice);
if (val)
tmp |= bit;
else
tmp &= ~bit;
snd_ice1712_gpio_write(ice, tmp);
}
static void spi_send_byte(struct snd_ice1712 *ice, unsigned char data)
{
int i;
for (i = 0; i < 8; i++) {
set_gpio_bit(ice, PONTIS_CS_CLK, 0);
udelay(1);
set_gpio_bit(ice, PONTIS_CS_WDATA, data & 0x80);
udelay(1);
set_gpio_bit(ice, PONTIS_CS_CLK, 1);
udelay(1);
data <<= 1;
}
}
static unsigned int spi_read_byte(struct snd_ice1712 *ice)
{
int i;
unsigned int val = 0;
for (i = 0; i < 8; i++) {
val <<= 1;
set_gpio_bit(ice, PONTIS_CS_CLK, 0);
udelay(1);
if (snd_ice1712_gpio_read(ice) & PONTIS_CS_RDATA)
val |= 1;
udelay(1);
set_gpio_bit(ice, PONTIS_CS_CLK, 1);
udelay(1);
}
return val;
}
static void spi_write(struct snd_ice1712 *ice, unsigned int dev, unsigned int reg, unsigned int data)
{
snd_ice1712_gpio_set_dir(ice, PONTIS_CS_CS|PONTIS_CS_WDATA|PONTIS_CS_CLK);
snd_ice1712_gpio_set_mask(ice, ~(PONTIS_CS_CS|PONTIS_CS_WDATA|PONTIS_CS_CLK));
set_gpio_bit(ice, PONTIS_CS_CS, 0);
spi_send_byte(ice, dev & ~1);
spi_send_byte(ice, reg);
spi_send_byte(ice, data);
set_gpio_bit(ice, PONTIS_CS_CS, 1);
udelay(1);
snd_ice1712_gpio_set_mask(ice, ice->gpio.write_mask);
snd_ice1712_gpio_set_dir(ice, ice->gpio.direction);
}
static unsigned int spi_read(struct snd_ice1712 *ice, unsigned int dev, unsigned int reg)
{
unsigned int val;
snd_ice1712_gpio_set_dir(ice, PONTIS_CS_CS|PONTIS_CS_WDATA|PONTIS_CS_CLK);
snd_ice1712_gpio_set_mask(ice, ~(PONTIS_CS_CS|PONTIS_CS_WDATA|PONTIS_CS_CLK));
set_gpio_bit(ice, PONTIS_CS_CS, 0);
spi_send_byte(ice, dev & ~1);
spi_send_byte(ice, reg);
set_gpio_bit(ice, PONTIS_CS_CS, 1);
udelay(1);
set_gpio_bit(ice, PONTIS_CS_CS, 0);
spi_send_byte(ice, dev | 1);
val = spi_read_byte(ice);
set_gpio_bit(ice, PONTIS_CS_CS, 1);
udelay(1);
snd_ice1712_gpio_set_mask(ice, ice->gpio.write_mask);
snd_ice1712_gpio_set_dir(ice, ice->gpio.direction);
return val;
}
static int cs_source_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
static const char * const texts[] = {
"Coax",
"Optical",
"CD",
};
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = 3;
if (uinfo->value.enumerated.item >= uinfo->value.enumerated.items)
uinfo->value.enumerated.item = uinfo->value.enumerated.items - 1;
strcpy(uinfo->value.enumerated.name, texts[uinfo->value.enumerated.item]);
return 0;
}
static int cs_source_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
mutex_lock(&ice->gpio_mutex);
ucontrol->value.enumerated.item[0] = ice->gpio.saved[0];
mutex_unlock(&ice->gpio_mutex);
return 0;
}
static int cs_source_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned char val;
int change = 0;
mutex_lock(&ice->gpio_mutex);
if (ucontrol->value.enumerated.item[0] != ice->gpio.saved[0]) {
ice->gpio.saved[0] = ucontrol->value.enumerated.item[0] & 3;
val = 0x80 | (ice->gpio.saved[0] << 3);
spi_write(ice, CS_DEV, 0x04, val);
change = 1;
}
mutex_unlock(&ice->gpio_mutex);
return change;
}
static int pontis_gpio_mask_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 0xffff;
return 0;
}
static int pontis_gpio_mask_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
mutex_lock(&ice->gpio_mutex);
ucontrol->value.integer.value[0] = (~ice->gpio.write_mask & 0xffff) | 0x00f0;
mutex_unlock(&ice->gpio_mutex);
return 0;
}
static int pontis_gpio_mask_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned int val;
int changed;
mutex_lock(&ice->gpio_mutex);
val = (~ucontrol->value.integer.value[0] & 0xffff) | 0x00f0;
changed = val != ice->gpio.write_mask;
ice->gpio.write_mask = val;
mutex_unlock(&ice->gpio_mutex);
return changed;
}
static int pontis_gpio_dir_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
mutex_lock(&ice->gpio_mutex);
ucontrol->value.integer.value[0] = ice->gpio.direction & 0xff0f;
mutex_unlock(&ice->gpio_mutex);
return 0;
}
static int pontis_gpio_dir_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned int val;
int changed;
mutex_lock(&ice->gpio_mutex);
val = ucontrol->value.integer.value[0] & 0xff0f;
changed = (val != ice->gpio.direction);
ice->gpio.direction = val;
mutex_unlock(&ice->gpio_mutex);
return changed;
}
static int pontis_gpio_data_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
mutex_lock(&ice->gpio_mutex);
snd_ice1712_gpio_set_dir(ice, ice->gpio.direction);
snd_ice1712_gpio_set_mask(ice, ice->gpio.write_mask);
ucontrol->value.integer.value[0] = snd_ice1712_gpio_read(ice) & 0xffff;
mutex_unlock(&ice->gpio_mutex);
return 0;
}
static int pontis_gpio_data_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned int val, nval;
int changed = 0;
mutex_lock(&ice->gpio_mutex);
snd_ice1712_gpio_set_dir(ice, ice->gpio.direction);
snd_ice1712_gpio_set_mask(ice, ice->gpio.write_mask);
val = snd_ice1712_gpio_read(ice) & 0xffff;
nval = ucontrol->value.integer.value[0] & 0xffff;
if (val != nval) {
snd_ice1712_gpio_write(ice, nval);
changed = 1;
}
mutex_unlock(&ice->gpio_mutex);
return changed;
}
static void wm_proc_regs_write(struct snd_info_entry *entry, struct snd_info_buffer *buffer)
{
struct snd_ice1712 *ice = entry->private_data;
char line[64];
unsigned int reg, val;
mutex_lock(&ice->gpio_mutex);
while (!snd_info_get_line(buffer, line, sizeof(line))) {
if (sscanf(line, "%x %x", &reg, &val) != 2)
continue;
if (reg <= 0x17 && val <= 0xffff)
wm_put(ice, reg, val);
}
mutex_unlock(&ice->gpio_mutex);
}
static void wm_proc_regs_read(struct snd_info_entry *entry, struct snd_info_buffer *buffer)
{
struct snd_ice1712 *ice = entry->private_data;
int reg, val;
mutex_lock(&ice->gpio_mutex);
for (reg = 0; reg <= 0x17; reg++) {
val = wm_get(ice, reg);
snd_iprintf(buffer, "%02x = %04x\n", reg, val);
}
mutex_unlock(&ice->gpio_mutex);
}
static void wm_proc_init(struct snd_ice1712 *ice)
{
struct snd_info_entry *entry;
if (! snd_card_proc_new(ice->card, "wm_codec", &entry)) {
snd_info_set_text_ops(entry, ice, wm_proc_regs_read);
entry->mode |= S_IWUSR;
entry->c.text.write = wm_proc_regs_write;
}
}
static void cs_proc_regs_read(struct snd_info_entry *entry, struct snd_info_buffer *buffer)
{
struct snd_ice1712 *ice = entry->private_data;
int reg, val;
mutex_lock(&ice->gpio_mutex);
for (reg = 0; reg <= 0x26; reg++) {
val = spi_read(ice, CS_DEV, reg);
snd_iprintf(buffer, "%02x = %02x\n", reg, val);
}
val = spi_read(ice, CS_DEV, 0x7f);
snd_iprintf(buffer, "%02x = %02x\n", 0x7f, val);
mutex_unlock(&ice->gpio_mutex);
}
static void cs_proc_init(struct snd_ice1712 *ice)
{
struct snd_info_entry *entry;
if (! snd_card_proc_new(ice->card, "cs_codec", &entry))
snd_info_set_text_ops(entry, ice, cs_proc_regs_read);
}
static int pontis_add_controls(struct snd_ice1712 *ice)
{
unsigned int i;
int err;
for (i = 0; i < ARRAY_SIZE(pontis_controls); i++) {
err = snd_ctl_add(ice->card, snd_ctl_new1(&pontis_controls[i], ice));
if (err < 0)
return err;
}
wm_proc_init(ice);
cs_proc_init(ice);
return 0;
}
static int pontis_init(struct snd_ice1712 *ice)
{
static const unsigned short wm_inits[] = {
WM_ADC_MUX, 0x00c0,
WM_DAC_MUTE, 0x0001,
WM_DAC_CTRL1, 0x0000,
WM_POWERDOWN, 0x0008,
WM_RESET, 0x0000,
};
static const unsigned short wm_inits2[] = {
WM_MASTER_CTRL, 0x0022,
WM_DAC_INT, 0x0022,
WM_ADC_INT, 0x0022,
WM_DAC_CTRL1, 0x0090,
WM_OUT_MUX, 0x0001,
WM_HP_ATTEN_L, 0x0179,
WM_HP_ATTEN_R, 0x0179,
WM_DAC_ATTEN_L, 0x0000,
WM_DAC_ATTEN_L, 0x0100,
WM_DAC_ATTEN_R, 0x0000,
WM_DAC_ATTEN_R, 0x0100,
WM_PHASE_SWAP, 0x0000,
WM_DAC_CTRL2, 0x0000,
WM_ADC_ATTEN_L, 0x0000,
WM_ADC_ATTEN_R, 0x0000,
#if 0
WM_ALC_CTRL1, 0x007b,
WM_ALC_CTRL2, 0x0000,
WM_ALC_CTRL3, 0x0000,
WM_NOISE_GATE, 0x0000,
#endif
WM_DAC_MUTE, 0x0000,
WM_ADC_MUX, 0x0003,
};
static const unsigned char cs_inits[] = {
0x04, 0x80,
0x05, 0x05,
0x01, 0x00,
0x02, 0x00,
0x03, 0x00,
};
unsigned int i;
ice->vt1720 = 1;
ice->num_total_dacs = 2;
ice->num_total_adcs = 2;
ice->akm = kzalloc(sizeof(struct snd_akm4xxx), GFP_KERNEL);
if (! ice->akm)
return -ENOMEM;
ice->akm_codecs = 1;
ice->gpio.saved[0] = 0;
for (i = 0; i < ARRAY_SIZE(wm_inits); i += 2)
wm_put(ice, wm_inits[i], wm_inits[i+1]);
schedule_timeout_uninterruptible(1);
for (i = 0; i < ARRAY_SIZE(wm_inits2); i += 2)
wm_put(ice, wm_inits2[i], wm_inits2[i+1]);
outb(inb(ICEMT1724(ice, AC97_CMD)) | 0x80, ICEMT1724(ice, AC97_CMD));
mdelay(5);
outb(inb(ICEMT1724(ice, AC97_CMD)) & ~0x80, ICEMT1724(ice, AC97_CMD));
for (i = 0; i < ARRAY_SIZE(cs_inits); i += 2)
spi_write(ice, CS_DEV, cs_inits[i], cs_inits[i+1]);
return 0;
}
