static void aureon_pca9554_write(struct snd_ice1712 *ice, unsigned char reg,
unsigned char data)
{
unsigned int tmp;
int i, j;
unsigned char dev = PCA9554_DEV;
unsigned char val = 0;
tmp = snd_ice1712_gpio_read(ice);
snd_ice1712_gpio_set_mask(ice, ~(AUREON_SPI_MOSI|AUREON_SPI_CLK|
AUREON_WM_RW|AUREON_WM_CS|
AUREON_CS8415_CS));
tmp |= AUREON_WM_RW;
tmp |= AUREON_CS8415_CS | AUREON_WM_CS;
tmp &= ~AUREON_SPI_MOSI;
tmp &= ~AUREON_SPI_CLK;
snd_ice1712_gpio_write(ice, tmp);
udelay(50);
tmp |= AUREON_SPI_CLK;
snd_ice1712_gpio_write(ice, tmp);
udelay(50);
tmp |= AUREON_SPI_MOSI;
snd_ice1712_gpio_write(ice, tmp);
udelay(100);
tmp &= ~AUREON_SPI_MOSI;
snd_ice1712_gpio_write(ice, tmp);
udelay(50);
tmp &= ~AUREON_SPI_CLK;
snd_ice1712_gpio_write(ice, tmp);
udelay(100);
for (j = 0; j < 3; j++) {
switch (j) {
case 0:
val = dev;
break;
case 1:
val = reg;
break;
case 2:
val = data;
break;
}
for (i = 7; i >= 0; i--) {
tmp &= ~AUREON_SPI_CLK;
snd_ice1712_gpio_write(ice, tmp);
udelay(40);
if (val & (1 << i))
tmp |= AUREON_SPI_MOSI;
else
tmp &= ~AUREON_SPI_MOSI;
snd_ice1712_gpio_write(ice, tmp);
udelay(40);
tmp |= AUREON_SPI_CLK;
snd_ice1712_gpio_write(ice, tmp);
udelay(40);
}
tmp &= ~AUREON_SPI_CLK;
snd_ice1712_gpio_write(ice, tmp);
udelay(40);
tmp |= AUREON_SPI_CLK;
snd_ice1712_gpio_write(ice, tmp);
udelay(40);
tmp &= ~AUREON_SPI_CLK;
snd_ice1712_gpio_write(ice, tmp);
udelay(40);
}
tmp &= ~AUREON_SPI_CLK;
snd_ice1712_gpio_write(ice, tmp);
udelay(40);
tmp &= ~AUREON_SPI_MOSI;
snd_ice1712_gpio_write(ice, tmp);
udelay(40);
tmp |= AUREON_SPI_CLK;
snd_ice1712_gpio_write(ice, tmp);
udelay(50);
tmp |= AUREON_SPI_MOSI;
snd_ice1712_gpio_write(ice, tmp);
udelay(100);
}
static int aureon_universe_inmux_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static const char * const texts[3] =
{"Internal Aux", "Wavetable", "Rear Line-In"};
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = 3;
if (uinfo->value.enumerated.item >= uinfo->value.enumerated.items)
uinfo->value.enumerated.item = uinfo->value.enumerated.items - 1;
strcpy(uinfo->value.enumerated.name, texts[uinfo->value.enumerated.item]);
return 0;
}
static int aureon_universe_inmux_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
struct aureon_spec *spec = ice->spec;
ucontrol->value.enumerated.item[0] = spec->pca9554_out;
return 0;
}
static int aureon_universe_inmux_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
struct aureon_spec *spec = ice->spec;
unsigned char oval, nval;
int change;
nval = ucontrol->value.enumerated.item[0];
if (nval >= 3)
return -EINVAL;
snd_ice1712_save_gpio_status(ice);
oval = spec->pca9554_out;
change = (oval != nval);
if (change) {
aureon_pca9554_write(ice, PCA9554_OUT, nval);
spec->pca9554_out = nval;
}
snd_ice1712_restore_gpio_status(ice);
return change;
}
static void aureon_ac97_write(struct snd_ice1712 *ice, unsigned short reg,
unsigned short val)
{
struct aureon_spec *spec = ice->spec;
unsigned int tmp;
tmp = (snd_ice1712_gpio_read(ice) & ~0xFF) | (reg & 0x7F);
snd_ice1712_gpio_write(ice, tmp);
udelay(10);
tmp |= AUREON_AC97_ADDR;
snd_ice1712_gpio_write(ice, tmp);
udelay(10);
tmp &= ~AUREON_AC97_ADDR;
snd_ice1712_gpio_write(ice, tmp);
udelay(10);
tmp &= ~AUREON_AC97_DATA_MASK;
tmp |= val & AUREON_AC97_DATA_MASK;
snd_ice1712_gpio_write(ice, tmp);
udelay(10);
tmp |= AUREON_AC97_DATA_LOW;
snd_ice1712_gpio_write(ice, tmp);
udelay(10);
tmp &= ~AUREON_AC97_DATA_LOW;
snd_ice1712_gpio_write(ice, tmp);
udelay(10);
tmp &= ~AUREON_AC97_DATA_MASK;
tmp |= (val >> 8) & AUREON_AC97_DATA_MASK;
snd_ice1712_gpio_write(ice, tmp);
udelay(10);
tmp |= AUREON_AC97_DATA_HIGH;
snd_ice1712_gpio_write(ice, tmp);
udelay(10);
tmp &= ~AUREON_AC97_DATA_HIGH;
snd_ice1712_gpio_write(ice, tmp);
udelay(10);
tmp |= AUREON_AC97_COMMIT;
snd_ice1712_gpio_write(ice, tmp);
udelay(10);
tmp &= ~AUREON_AC97_COMMIT;
snd_ice1712_gpio_write(ice, tmp);
udelay(10);
spec->stac9744[(reg & 0x7F) >> 1] = val;
}
static unsigned short aureon_ac97_read(struct snd_ice1712 *ice, unsigned short reg)
{
struct aureon_spec *spec = ice->spec;
return spec->stac9744[(reg & 0x7F) >> 1];
}
static int aureon_ac97_init(struct snd_ice1712 *ice)
{
struct aureon_spec *spec = ice->spec;
int i;
static const unsigned short ac97_defaults[] = {
0x00, 0x9640,
0x02, 0x8000,
0x04, 0x8000,
0x06, 0x8000,
0x0C, 0x8008,
0x0E, 0x8008,
0x10, 0x8808,
0x12, 0x8808,
0x14, 0x8808,
0x16, 0x8808,
0x18, 0x8808,
0x1C, 0x8000,
0x26, 0x000F,
0x28, 0x0201,
0x2C, 0xBB80,
0x32, 0xBB80,
0x7C, 0x8384,
0x7E, 0x7644,
(unsigned short)-1
};
unsigned int tmp;
tmp = (snd_ice1712_gpio_read(ice) | AUREON_AC97_RESET) & ~AUREON_AC97_DATA_MASK;
snd_ice1712_gpio_write(ice, tmp);
udelay(3);
tmp &= ~AUREON_AC97_RESET;
snd_ice1712_gpio_write(ice, tmp);
udelay(3);
tmp |= AUREON_AC97_RESET;
snd_ice1712_gpio_write(ice, tmp);
udelay(3);
memset(&spec->stac9744, 0, sizeof(spec->stac9744));
for (i = 0; ac97_defaults[i] != (unsigned short)-1; i += 2)
spec->stac9744[(ac97_defaults[i]) >> 1] = ac97_defaults[i+1];
aureon_ac97_write(ice, AC97_MASTER, 0x0000);
return 0;
}
static int aureon_ac97_vol_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = kcontrol->private_value & AUREON_AC97_STEREO ? 2 : 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 31;
return 0;
}
static int aureon_ac97_vol_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned short vol;
mutex_lock(&ice->gpio_mutex);
vol = aureon_ac97_read(ice, kcontrol->private_value & 0x7F);
ucontrol->value.integer.value[0] = 0x1F - (vol & 0x1F);
if (kcontrol->private_value & AUREON_AC97_STEREO)
ucontrol->value.integer.value[1] = 0x1F - ((vol >> 8) & 0x1F);
mutex_unlock(&ice->gpio_mutex);
return 0;
}
static int aureon_ac97_vol_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned short ovol, nvol;
int change;
snd_ice1712_save_gpio_status(ice);
ovol = aureon_ac97_read(ice, kcontrol->private_value & 0x7F);
nvol = (0x1F - ucontrol->value.integer.value[0]) & 0x001F;
if (kcontrol->private_value & AUREON_AC97_STEREO)
nvol |= ((0x1F - ucontrol->value.integer.value[1]) << 8) & 0x1F00;
nvol |= ovol & ~0x1F1F;
change = (ovol != nvol);
if (change)
aureon_ac97_write(ice, kcontrol->private_value & 0x7F, nvol);
snd_ice1712_restore_gpio_status(ice);
return change;
}
static int aureon_ac97_mute_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
mutex_lock(&ice->gpio_mutex);
ucontrol->value.integer.value[0] = aureon_ac97_read(ice,
kcontrol->private_value & 0x7F) & 0x8000 ? 0 : 1;
mutex_unlock(&ice->gpio_mutex);
return 0;
}
static int aureon_ac97_mute_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned short ovol, nvol;
int change;
snd_ice1712_save_gpio_status(ice);
ovol = aureon_ac97_read(ice, kcontrol->private_value & 0x7F);
nvol = (ucontrol->value.integer.value[0] ? 0x0000 : 0x8000) | (ovol & ~0x8000);
change = (ovol != nvol);
if (change)
aureon_ac97_write(ice, kcontrol->private_value & 0x7F, nvol);
snd_ice1712_restore_gpio_status(ice);
return change;
}
static int aureon_ac97_micboost_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
mutex_lock(&ice->gpio_mutex);
ucontrol->value.integer.value[0] = aureon_ac97_read(ice, AC97_MIC) & 0x0020 ? 0 : 1;
mutex_unlock(&ice->gpio_mutex);
return 0;
}
static int aureon_ac97_micboost_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned short ovol, nvol;
int change;
snd_ice1712_save_gpio_status(ice);
ovol = aureon_ac97_read(ice, AC97_MIC);
nvol = (ucontrol->value.integer.value[0] ? 0x0000 : 0x0020) | (ovol & ~0x0020);
change = (ovol != nvol);
if (change)
aureon_ac97_write(ice, AC97_MIC, nvol);
snd_ice1712_restore_gpio_status(ice);
return change;
}
static void aureon_spi_write(struct snd_ice1712 *ice, unsigned int cs, unsigned int data, int bits)
{
unsigned int tmp;
int i;
unsigned int mosi, clk;
tmp = snd_ice1712_gpio_read(ice);
if (ice->eeprom.subvendor == VT1724_SUBDEVICE_PRODIGY71LT ||
ice->eeprom.subvendor == VT1724_SUBDEVICE_PRODIGY71XT) {
snd_ice1712_gpio_set_mask(ice, ~(PRODIGY_SPI_MOSI|PRODIGY_SPI_CLK|PRODIGY_WM_CS));
mosi = PRODIGY_SPI_MOSI;
clk = PRODIGY_SPI_CLK;
} else {
snd_ice1712_gpio_set_mask(ice, ~(AUREON_WM_RW|AUREON_SPI_MOSI|AUREON_SPI_CLK|
AUREON_WM_CS|AUREON_CS8415_CS));
mosi = AUREON_SPI_MOSI;
clk = AUREON_SPI_CLK;
tmp |= AUREON_WM_RW;
}
tmp &= ~cs;
snd_ice1712_gpio_write(ice, tmp);
udelay(1);
for (i = bits - 1; i >= 0; i--) {
tmp &= ~clk;
snd_ice1712_gpio_write(ice, tmp);
udelay(1);
if (data & (1 << i))
tmp |= mosi;
else
tmp &= ~mosi;
snd_ice1712_gpio_write(ice, tmp);
udelay(1);
tmp |= clk;
snd_ice1712_gpio_write(ice, tmp);
udelay(1);
}
tmp &= ~clk;
tmp |= cs;
snd_ice1712_gpio_write(ice, tmp);
udelay(1);
tmp |= clk;
snd_ice1712_gpio_write(ice, tmp);
udelay(1);
}
static void aureon_spi_read(struct snd_ice1712 *ice, unsigned int cs,
unsigned int data, int bits, unsigned char *buffer, int size)
{
int i, j;
unsigned int tmp;
tmp = (snd_ice1712_gpio_read(ice) & ~AUREON_SPI_CLK) | AUREON_CS8415_CS|AUREON_WM_CS;
snd_ice1712_gpio_write(ice, tmp);
tmp &= ~cs;
snd_ice1712_gpio_write(ice, tmp);
udelay(1);
for (i = bits-1; i >= 0; i--) {
if (data & (1 << i))
tmp |= AUREON_SPI_MOSI;
else
tmp &= ~AUREON_SPI_MOSI;
snd_ice1712_gpio_write(ice, tmp);
udelay(1);
tmp |= AUREON_SPI_CLK;
snd_ice1712_gpio_write(ice, tmp);
udelay(1);
tmp &= ~AUREON_SPI_CLK;
snd_ice1712_gpio_write(ice, tmp);
udelay(1);
}
for (j = 0; j < size; j++) {
unsigned char outdata = 0;
for (i = 7; i >= 0; i--) {
tmp = snd_ice1712_gpio_read(ice);
outdata <<= 1;
outdata |= (tmp & AUREON_SPI_MISO) ? 1 : 0;
udelay(1);
tmp |= AUREON_SPI_CLK;
snd_ice1712_gpio_write(ice, tmp);
udelay(1);
tmp &= ~AUREON_SPI_CLK;
snd_ice1712_gpio_write(ice, tmp);
udelay(1);
}
buffer[j] = outdata;
}
tmp |= cs;
snd_ice1712_gpio_write(ice, tmp);
}
static unsigned char aureon_cs8415_get(struct snd_ice1712 *ice, int reg)
{
unsigned char val;
aureon_spi_write(ice, AUREON_CS8415_CS, 0x2000 | reg, 16);
aureon_spi_read(ice, AUREON_CS8415_CS, 0x21, 8, &val, 1);
return val;
}
static void aureon_cs8415_read(struct snd_ice1712 *ice, int reg,
unsigned char *buffer, int size)
{
aureon_spi_write(ice, AUREON_CS8415_CS, 0x2000 | reg, 16);
aureon_spi_read(ice, AUREON_CS8415_CS, 0x21, 8, buffer, size);
}
static void aureon_cs8415_put(struct snd_ice1712 *ice, int reg,
unsigned char val)
{
aureon_spi_write(ice, AUREON_CS8415_CS, 0x200000 | (reg << 8) | val, 24);
}
static unsigned short wm_get(struct snd_ice1712 *ice, int reg)
{
reg <<= 1;
return ((unsigned short)ice->akm[0].images[reg] << 8) |
ice->akm[0].images[reg + 1];
}
static void wm_put_nocache(struct snd_ice1712 *ice, int reg, unsigned short val)
{
aureon_spi_write(ice,
((ice->eeprom.subvendor == VT1724_SUBDEVICE_PRODIGY71LT ||
ice->eeprom.subvendor == VT1724_SUBDEVICE_PRODIGY71XT) ?
PRODIGY_WM_CS : AUREON_WM_CS),
(reg << 9) | (val & 0x1ff), 16);
}
static void wm_put(struct snd_ice1712 *ice, int reg, unsigned short val)
{
wm_put_nocache(ice, reg, val);
reg <<= 1;
ice->akm[0].images[reg] = val >> 8;
ice->akm[0].images[reg + 1] = val;
}
static int aureon_ac97_mmute_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
mutex_lock(&ice->gpio_mutex);
ucontrol->value.integer.value[0] = (wm_get(ice, WM_OUT_MUX1) >> 1) & 0x01;
mutex_unlock(&ice->gpio_mutex);
return 0;
}
static int aureon_ac97_mmute_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned short ovol, nvol;
int change;
snd_ice1712_save_gpio_status(ice);
ovol = wm_get(ice, WM_OUT_MUX1);
nvol = (ovol & ~0x02) | (ucontrol->value.integer.value[0] ? 0x02 : 0x00);
change = (ovol != nvol);
if (change)
wm_put(ice, WM_OUT_MUX1, nvol);
snd_ice1712_restore_gpio_status(ice);
return change;
}
static void wm_set_vol(struct snd_ice1712 *ice, unsigned int index, unsigned short vol, unsigned short master)
{
unsigned char nvol;
if ((master & WM_VOL_MUTE) || (vol & WM_VOL_MUTE)) {
nvol = 0;
} else {
nvol = ((vol % WM_VOL_CNT) * (master % WM_VOL_CNT)) /
WM_VOL_MAX;
nvol += 0x1b;
}
wm_put(ice, index, nvol);
wm_put_nocache(ice, index, 0x180 | nvol);
}
static int wm_pcm_mute_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
mutex_lock(&ice->gpio_mutex);
ucontrol->value.integer.value[0] = (wm_get(ice, WM_MUTE) & 0x10) ? 0 : 1;
mutex_unlock(&ice->gpio_mutex);
return 0;
}
static int wm_pcm_mute_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned short nval, oval;
int change;
snd_ice1712_save_gpio_status(ice);
oval = wm_get(ice, WM_MUTE);
nval = (oval & ~0x10) | (ucontrol->value.integer.value[0] ? 0 : 0x10);
change = (oval != nval);
if (change)
wm_put(ice, WM_MUTE, nval);
snd_ice1712_restore_gpio_status(ice);
return change;
}
static int wm_master_vol_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 2;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = WM_VOL_MAX;
return 0;
}
static int wm_master_vol_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
struct aureon_spec *spec = ice->spec;
int i;
for (i = 0; i < 2; i++)
ucontrol->value.integer.value[i] =
spec->master[i] & ~WM_VOL_MUTE;
return 0;
}
static int wm_master_vol_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
struct aureon_spec *spec = ice->spec;
int ch, change = 0;
snd_ice1712_save_gpio_status(ice);
for (ch = 0; ch < 2; ch++) {
unsigned int vol = ucontrol->value.integer.value[ch];
if (vol > WM_VOL_MAX)
vol = WM_VOL_MAX;
vol |= spec->master[ch] & WM_VOL_MUTE;
if (vol != spec->master[ch]) {
int dac;
spec->master[ch] = vol;
for (dac = 0; dac < ice->num_total_dacs; dac += 2)
wm_set_vol(ice, WM_DAC_ATTEN + dac + ch,
spec->vol[dac + ch],
spec->master[ch]);
change = 1;
}
}
snd_ice1712_restore_gpio_status(ice);
return change;
}
static int wm_vol_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
int voices = kcontrol->private_value >> 8;
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = voices;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = WM_VOL_MAX;
return 0;
}
static int wm_vol_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
struct aureon_spec *spec = ice->spec;
int i, ofs, voices;
voices = kcontrol->private_value >> 8;
ofs = kcontrol->private_value & 0xff;
for (i = 0; i < voices; i++)
ucontrol->value.integer.value[i] =
spec->vol[ofs+i] & ~WM_VOL_MUTE;
return 0;
}
static int wm_vol_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
struct aureon_spec *spec = ice->spec;
int i, idx, ofs, voices;
int change = 0;
voices = kcontrol->private_value >> 8;
ofs = kcontrol->private_value & 0xff;
snd_ice1712_save_gpio_status(ice);
for (i = 0; i < voices; i++) {
unsigned int vol = ucontrol->value.integer.value[i];
if (vol > WM_VOL_MAX)
vol = WM_VOL_MAX;
vol |= spec->vol[ofs+i] & WM_VOL_MUTE;
if (vol != spec->vol[ofs+i]) {
spec->vol[ofs+i] = vol;
idx = WM_DAC_ATTEN + ofs + i;
wm_set_vol(ice, idx, spec->vol[ofs + i],
spec->master[i]);
change = 1;
}
}
snd_ice1712_restore_gpio_status(ice);
return change;
}
static int wm_mute_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_BOOLEAN;
uinfo->count = kcontrol->private_value >> 8;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 1;
return 0;
}
static int wm_mute_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
struct aureon_spec *spec = ice->spec;
int voices, ofs, i;
voices = kcontrol->private_value >> 8;
ofs = kcontrol->private_value & 0xFF;
for (i = 0; i < voices; i++)
ucontrol->value.integer.value[i] =
(spec->vol[ofs + i] & WM_VOL_MUTE) ? 0 : 1;
return 0;
}
static int wm_mute_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
struct aureon_spec *spec = ice->spec;
int change = 0, voices, ofs, i;
voices = kcontrol->private_value >> 8;
ofs = kcontrol->private_value & 0xFF;
snd_ice1712_save_gpio_status(ice);
for (i = 0; i < voices; i++) {
int val = (spec->vol[ofs + i] & WM_VOL_MUTE) ? 0 : 1;
if (ucontrol->value.integer.value[i] != val) {
spec->vol[ofs + i] &= ~WM_VOL_MUTE;
spec->vol[ofs + i] |=
ucontrol->value.integer.value[i] ? 0 : WM_VOL_MUTE;
wm_set_vol(ice, ofs + i, spec->vol[ofs + i],
spec->master[i]);
change = 1;
}
}
snd_ice1712_restore_gpio_status(ice);
return change;
}
static int wm_master_mute_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
struct aureon_spec *spec = ice->spec;
ucontrol->value.integer.value[0] =
(spec->master[0] & WM_VOL_MUTE) ? 0 : 1;
ucontrol->value.integer.value[1] =
(spec->master[1] & WM_VOL_MUTE) ? 0 : 1;
return 0;
}
static int wm_master_mute_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
struct aureon_spec *spec = ice->spec;
int change = 0, i;
snd_ice1712_save_gpio_status(ice);
for (i = 0; i < 2; i++) {
int val = (spec->master[i] & WM_VOL_MUTE) ? 0 : 1;
if (ucontrol->value.integer.value[i] != val) {
int dac;
spec->master[i] &= ~WM_VOL_MUTE;
spec->master[i] |=
ucontrol->value.integer.value[i] ? 0 : WM_VOL_MUTE;
for (dac = 0; dac < ice->num_total_dacs; dac += 2)
wm_set_vol(ice, WM_DAC_ATTEN + dac + i,
spec->vol[dac + i],
spec->master[i]);
change = 1;
}
}
snd_ice1712_restore_gpio_status(ice);
return change;
}
static int wm_pcm_vol_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = PCM_RES;
return 0;
}
static int wm_pcm_vol_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned short val;
mutex_lock(&ice->gpio_mutex);
val = wm_get(ice, WM_DAC_DIG_MASTER_ATTEN) & 0xff;
val = val > PCM_MIN ? (val - PCM_MIN) : 0;
ucontrol->value.integer.value[0] = val;
mutex_unlock(&ice->gpio_mutex);
return 0;
}
static int wm_pcm_vol_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned short ovol, nvol;
int change = 0;
nvol = ucontrol->value.integer.value[0];
if (nvol > PCM_RES)
return -EINVAL;
snd_ice1712_save_gpio_status(ice);
nvol = (nvol ? (nvol + PCM_MIN) : 0) & 0xff;
ovol = wm_get(ice, WM_DAC_DIG_MASTER_ATTEN) & 0xff;
if (ovol != nvol) {
wm_put(ice, WM_DAC_DIG_MASTER_ATTEN, nvol);
wm_put_nocache(ice, WM_DAC_DIG_MASTER_ATTEN, nvol | 0x100);
change = 1;
}
snd_ice1712_restore_gpio_status(ice);
return change;
}
static int wm_adc_mute_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned short val;
int i;
mutex_lock(&ice->gpio_mutex);
for (i = 0; i < 2; i++) {
val = wm_get(ice, WM_ADC_GAIN + i);
ucontrol->value.integer.value[i] = ~val>>5 & 0x1;
}
mutex_unlock(&ice->gpio_mutex);
return 0;
}
static int wm_adc_mute_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned short new, old;
int i, change = 0;
snd_ice1712_save_gpio_status(ice);
for (i = 0; i < 2; i++) {
old = wm_get(ice, WM_ADC_GAIN + i);
new = (~ucontrol->value.integer.value[i]<<5&0x20) | (old&~0x20);
if (new != old) {
wm_put(ice, WM_ADC_GAIN + i, new);
change = 1;
}
}
snd_ice1712_restore_gpio_status(ice);
return change;
}
static int wm_adc_vol_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 2;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 0x1f;
return 0;
}
static int wm_adc_vol_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
int i, idx;
unsigned short vol;
mutex_lock(&ice->gpio_mutex);
for (i = 0; i < 2; i++) {
idx = WM_ADC_GAIN + i;
vol = wm_get(ice, idx) & 0x1f;
ucontrol->value.integer.value[i] = vol;
}
mutex_unlock(&ice->gpio_mutex);
return 0;
}
static int wm_adc_vol_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
int i, idx;
unsigned short ovol, nvol;
int change = 0;
snd_ice1712_save_gpio_status(ice);
for (i = 0; i < 2; i++) {
idx = WM_ADC_GAIN + i;
nvol = ucontrol->value.integer.value[i] & 0x1f;
ovol = wm_get(ice, idx);
if ((ovol & 0x1f) != nvol) {
wm_put(ice, idx, nvol | (ovol & ~0x1f));
change = 1;
}
}
snd_ice1712_restore_gpio_status(ice);
return change;
}
static int wm_adc_mux_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
static const char * const texts[] = {
"CD",
"Aux",
"Line",
"Mic",
"AC97"
};
static const char * const universe_texts[] = {
"Aux1",
"CD",
"Phono",
"Line",
"Aux2",
"Mic",
"Aux3",
"AC97"
};
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 2;
if (ice->eeprom.subvendor == VT1724_SUBDEVICE_AUREON71_UNIVERSE) {
uinfo->value.enumerated.items = 8;
if (uinfo->value.enumerated.item >= uinfo->value.enumerated.items)
uinfo->value.enumerated.item = uinfo->value.enumerated.items - 1;
strcpy(uinfo->value.enumerated.name, universe_texts[uinfo->value.enumerated.item]);
} else {
uinfo->value.enumerated.items = 5;
if (uinfo->value.enumerated.item >= uinfo->value.enumerated.items)
uinfo->value.enumerated.item = uinfo->value.enumerated.items - 1;
strcpy(uinfo->value.enumerated.name, texts[uinfo->value.enumerated.item]);
}
return 0;
}
static int wm_adc_mux_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned short val;
mutex_lock(&ice->gpio_mutex);
val = wm_get(ice, WM_ADC_MUX);
ucontrol->value.enumerated.item[0] = val & 7;
ucontrol->value.enumerated.item[1] = (val >> 4) & 7;
mutex_unlock(&ice->gpio_mutex);
return 0;
}
static int wm_adc_mux_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned short oval, nval;
int change;
snd_ice1712_save_gpio_status(ice);
oval = wm_get(ice, WM_ADC_MUX);
nval = oval & ~0x77;
nval |= ucontrol->value.enumerated.item[0] & 7;
nval |= (ucontrol->value.enumerated.item[1] & 7) << 4;
change = (oval != nval);
if (change)
wm_put(ice, WM_ADC_MUX, nval);
snd_ice1712_restore_gpio_status(ice);
return change;
}
static int aureon_cs8415_mux_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
static const char * const aureon_texts[] = {
"CD",
"Optical"
};
static const char * const prodigy_texts[] = {
"CD",
"Coax"
};
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = 2;
if (uinfo->value.enumerated.item >= uinfo->value.enumerated.items)
uinfo->value.enumerated.item = uinfo->value.enumerated.items - 1;
if (ice->eeprom.subvendor == VT1724_SUBDEVICE_PRODIGY71)
strcpy(uinfo->value.enumerated.name, prodigy_texts[uinfo->value.enumerated.item]);
else
strcpy(uinfo->value.enumerated.name, aureon_texts[uinfo->value.enumerated.item]);
return 0;
}
static int aureon_cs8415_mux_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
struct aureon_spec *spec = ice->spec;
ucontrol->value.enumerated.item[0] = spec->cs8415_mux;
return 0;
}
static int aureon_cs8415_mux_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
struct aureon_spec *spec = ice->spec;
unsigned short oval, nval;
int change;
snd_ice1712_save_gpio_status(ice);
oval = aureon_cs8415_get(ice, CS8415_CTRL2);
nval = oval & ~0x07;
nval |= ucontrol->value.enumerated.item[0] & 7;
change = (oval != nval);
if (change)
aureon_cs8415_put(ice, CS8415_CTRL2, nval);
snd_ice1712_restore_gpio_status(ice);
spec->cs8415_mux = ucontrol->value.enumerated.item[0];
return change;
}
static int aureon_cs8415_rate_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 192000;
return 0;
}
static int aureon_cs8415_rate_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned char ratio;
ratio = aureon_cs8415_get(ice, CS8415_RATIO);
ucontrol->value.integer.value[0] = (int)((unsigned int)ratio * 750);
return 0;
}
static int aureon_cs8415_mute_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
snd_ice1712_save_gpio_status(ice);
ucontrol->value.integer.value[0] = (aureon_cs8415_get(ice, CS8415_CTRL1) & 0x20) ? 0 : 1;
snd_ice1712_restore_gpio_status(ice);
return 0;
}
static int aureon_cs8415_mute_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned char oval, nval;
int change;
snd_ice1712_save_gpio_status(ice);
oval = aureon_cs8415_get(ice, CS8415_CTRL1);
if (ucontrol->value.integer.value[0])
nval = oval & ~0x20;
else
nval = oval | 0x20;
change = (oval != nval);
if (change)
aureon_cs8415_put(ice, CS8415_CTRL1, nval);
snd_ice1712_restore_gpio_status(ice);
return change;
}
static int aureon_cs8415_qsub_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_BYTES;
uinfo->count = 10;
return 0;
}
static int aureon_cs8415_qsub_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
snd_ice1712_save_gpio_status(ice);
aureon_cs8415_read(ice, CS8415_QSUB, ucontrol->value.bytes.data, 10);
snd_ice1712_restore_gpio_status(ice);
return 0;
}
static int aureon_cs8415_spdif_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_IEC958;
uinfo->count = 1;
return 0;
}
static int aureon_cs8415_mask_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
memset(ucontrol->value.iec958.status, 0xFF, 24);
return 0;
}
static int aureon_cs8415_spdif_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
snd_ice1712_save_gpio_status(ice);
aureon_cs8415_read(ice, CS8415_C_BUFFER, ucontrol->value.iec958.status, 24);
snd_ice1712_restore_gpio_status(ice);
return 0;
}
static int aureon_set_headphone_amp(struct snd_ice1712 *ice, int enable)
{
unsigned int tmp, tmp2;
tmp2 = tmp = snd_ice1712_gpio_read(ice);
if (enable)
if (ice->eeprom.subvendor != VT1724_SUBDEVICE_PRODIGY71LT &&
ice->eeprom.subvendor != VT1724_SUBDEVICE_PRODIGY71XT)
tmp |= AUREON_HP_SEL;
else
tmp |= PRODIGY_HP_SEL;
else
if (ice->eeprom.subvendor != VT1724_SUBDEVICE_PRODIGY71LT &&
ice->eeprom.subvendor != VT1724_SUBDEVICE_PRODIGY71XT)
tmp &= ~AUREON_HP_SEL;
else
tmp &= ~PRODIGY_HP_SEL;
if (tmp != tmp2) {
snd_ice1712_gpio_write(ice, tmp);
return 1;
}
return 0;
}
static int aureon_get_headphone_amp(struct snd_ice1712 *ice)
{
unsigned int tmp = snd_ice1712_gpio_read(ice);
return (tmp & AUREON_HP_SEL) != 0;
}
static int aureon_hpamp_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
ucontrol->value.integer.value[0] = aureon_get_headphone_amp(ice);
return 0;
}
static int aureon_hpamp_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
return aureon_set_headphone_amp(ice, ucontrol->value.integer.value[0]);
}
static int aureon_deemp_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
ucontrol->value.integer.value[0] = (wm_get(ice, WM_DAC_CTRL2) & 0xf) == 0xf;
return 0;
}
static int aureon_deemp_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
int temp, temp2;
temp2 = temp = wm_get(ice, WM_DAC_CTRL2);
if (ucontrol->value.integer.value[0])
temp |= 0xf;
else
temp &= ~0xf;
if (temp != temp2) {
wm_put(ice, WM_DAC_CTRL2, temp);
return 1;
}
return 0;
}
static int aureon_oversampling_info(struct snd_kcontrol *k, struct snd_ctl_elem_info *uinfo)
{
static const char * const texts[2] = { "128x", "64x" };
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = 2;
if (uinfo->value.enumerated.item >= uinfo->value.enumerated.items)
uinfo->value.enumerated.item = uinfo->value.enumerated.items - 1;
strcpy(uinfo->value.enumerated.name, texts[uinfo->value.enumerated.item]);
return 0;
}
static int aureon_oversampling_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
ucontrol->value.enumerated.item[0] = (wm_get(ice, WM_MASTER) & 0x8) == 0x8;
return 0;
}
static int aureon_oversampling_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
int temp, temp2;
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
temp2 = temp = wm_get(ice, WM_MASTER);
if (ucontrol->value.enumerated.item[0])
temp |= 0x8;
else
temp &= ~0x8;
if (temp != temp2) {
wm_put(ice, WM_MASTER, temp);
return 1;
}
return 0;
}
static int aureon_add_controls(struct snd_ice1712 *ice)
{
unsigned int i, counts;
int err;
counts = ARRAY_SIZE(aureon_dac_controls);
if (ice->eeprom.subvendor == VT1724_SUBDEVICE_AUREON51_SKY)
counts -= 2;
for (i = 0; i < counts; i++) {
err = snd_ctl_add(ice->card, snd_ctl_new1(&aureon_dac_controls[i], ice));
if (err < 0)
return err;
}
for (i = 0; i < ARRAY_SIZE(wm_controls); i++) {
err = snd_ctl_add(ice->card, snd_ctl_new1(&wm_controls[i], ice));
if (err < 0)
return err;
}
if (ice->eeprom.subvendor == VT1724_SUBDEVICE_AUREON71_UNIVERSE) {
for (i = 0; i < ARRAY_SIZE(universe_ac97_controls); i++) {
err = snd_ctl_add(ice->card, snd_ctl_new1(&universe_ac97_controls[i], ice));
if (err < 0)
return err;
}
} else if (ice->eeprom.subvendor != VT1724_SUBDEVICE_PRODIGY71LT &&
ice->eeprom.subvendor != VT1724_SUBDEVICE_PRODIGY71XT) {
for (i = 0; i < ARRAY_SIZE(ac97_controls); i++) {
err = snd_ctl_add(ice->card, snd_ctl_new1(&ac97_controls[i], ice));
if (err < 0)
return err;
}
}
if (ice->eeprom.subvendor != VT1724_SUBDEVICE_PRODIGY71LT &&
ice->eeprom.subvendor != VT1724_SUBDEVICE_PRODIGY71XT) {
unsigned char id;
snd_ice1712_save_gpio_status(ice);
id = aureon_cs8415_get(ice, CS8415_ID);
if (id != 0x41)
snd_printk(KERN_INFO "No CS8415 chip. Skipping CS8415 controls.\n");
else if ((id & 0x0F) != 0x01)
snd_printk(KERN_INFO "Detected unsupported CS8415 rev. (%c)\n", (char)((id & 0x0F) + 'A' - 1));
else {
for (i = 0; i < ARRAY_SIZE(cs8415_controls); i++) {
struct snd_kcontrol *kctl;
err = snd_ctl_add(ice->card, (kctl = snd_ctl_new1(&cs8415_controls[i], ice)));
if (err < 0)
return err;
if (i > 1)
kctl->id.device = ice->pcm->device;
}
}
snd_ice1712_restore_gpio_status(ice);
}
return 0;
}
static int aureon_reset(struct snd_ice1712 *ice)
{
static const unsigned short wm_inits_aureon[] = {
0x1b, 0x044,
0x1c, 0x00B,
0x1d, 0x009,
0x18, 0x000,
0x16, 0x122,
0x17, 0x022,
0x00, 0,
0x01, 0,
0x02, 0,
0x03, 0,
0x04, 0,
0x05, 0,
0x06, 0,
0x07, 0,
0x08, 0x100,
0x09, 0xff,
0x0a, 0xff,
0x0b, 0xff,
0x0c, 0xff,
0x0d, 0xff,
0x0e, 0xff,
0x0f, 0xff,
0x10, 0xff,
0x11, 0x1ff,
0x12, 0x000,
0x13, 0x090,
0x14, 0x000,
0x15, 0x000,
0x19, 0x000,
0x1a, 0x000,
(unsigned short)-1
};
static const unsigned short wm_inits_prodigy[] = {
0x1b, 0x000,
0x1c, 0x009,
0x1d, 0x009,
0x18, 0x000,
0x16, 0x022,
0x17, 0x006,
0x00, 0,
0x01, 0,
0x02, 0,
0x03, 0,
0x04, 0,
0x05, 0,
0x06, 0,
0x07, 0,
0x08, 0x100,
0x09, 0x7f,
0x0a, 0x7f,
0x0b, 0x7f,
0x0c, 0x7f,
0x0d, 0x7f,
0x0e, 0x7f,
0x0f, 0x7f,
0x10, 0x7f,
0x11, 0x1FF,
0x12, 0x000,
0x13, 0x090,
0x14, 0x000,
0x15, 0x000,
0x19, 0x000,
0x1a, 0x000,
(unsigned short)-1
};
static const unsigned short cs_inits[] = {
0x0441,
0x0180,
0x0201,
0x0605,
(unsigned short)-1
};
unsigned int tmp;
const unsigned short *p;
int err;
struct aureon_spec *spec = ice->spec;
err = aureon_ac97_init(ice);
if (err != 0)
return err;
snd_ice1712_gpio_set_dir(ice, 0x5fffff);
snd_ice1712_save_gpio_status(ice);
snd_ice1712_gpio_set_mask(ice, ~(AUREON_WM_RESET|AUREON_WM_CS|AUREON_CS8415_CS|AUREON_HP_SEL));
tmp = snd_ice1712_gpio_read(ice);
tmp &= ~AUREON_WM_RESET;
snd_ice1712_gpio_write(ice, tmp);
udelay(1);
tmp |= AUREON_WM_CS | AUREON_CS8415_CS;
snd_ice1712_gpio_write(ice, tmp);
udelay(1);
tmp |= AUREON_WM_RESET;
snd_ice1712_gpio_write(ice, tmp);
udelay(1);
if (ice->eeprom.subvendor == VT1724_SUBDEVICE_PRODIGY71 ||
ice->eeprom.subvendor == VT1724_SUBDEVICE_PRODIGY71LT ||
ice->eeprom.subvendor == VT1724_SUBDEVICE_PRODIGY71XT)
p = wm_inits_prodigy;
else
p = wm_inits_aureon;
for (; *p != (unsigned short)-1; p += 2)
wm_put(ice, p[0], p[1]);
if (ice->eeprom.subvendor != VT1724_SUBDEVICE_PRODIGY71LT &&
ice->eeprom.subvendor != VT1724_SUBDEVICE_PRODIGY71XT) {
for (p = cs_inits; *p != (unsigned short)-1; p++)
aureon_spi_write(ice, AUREON_CS8415_CS, *p | 0x200000, 24);
spec->cs8415_mux = 1;
aureon_set_headphone_amp(ice, 1);
}
snd_ice1712_restore_gpio_status(ice);
aureon_pca9554_write(ice, PCA9554_DIR, 0x00);
aureon_pca9554_write(ice, PCA9554_OUT, 0x00);
return 0;
}
static int aureon_resume(struct snd_ice1712 *ice)
{
struct aureon_spec *spec = ice->spec;
int err, i;
err = aureon_reset(ice);
if (err != 0)
return err;
for (i = 0; i < ice->num_total_dacs; i++)
wm_set_vol(ice, i, spec->vol[i], spec->master[i % 2]);
return 0;
}
static int aureon_init(struct snd_ice1712 *ice)
{
struct aureon_spec *spec;
int i, err;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (!spec)
return -ENOMEM;
ice->spec = spec;
if (ice->eeprom.subvendor == VT1724_SUBDEVICE_AUREON51_SKY) {
ice->num_total_dacs = 6;
ice->num_total_adcs = 2;
} else {
ice->num_total_dacs = 8;
ice->num_total_adcs = 2;
}
ice->akm = kzalloc(sizeof(struct snd_akm4xxx), GFP_KERNEL);
if (!ice->akm)
return -ENOMEM;
ice->akm_codecs = 1;
err = aureon_reset(ice);
if (err != 0)
return err;
spec->master[0] = WM_VOL_MUTE;
spec->master[1] = WM_VOL_MUTE;
for (i = 0; i < ice->num_total_dacs; i++) {
spec->vol[i] = WM_VOL_MUTE;
wm_set_vol(ice, i, spec->vol[i], spec->master[i % 2]);
}
#ifdef CONFIG_PM_SLEEP
ice->pm_resume = aureon_resume;
ice->pm_suspend_enabled = 1;
#endif
return 0;
}
