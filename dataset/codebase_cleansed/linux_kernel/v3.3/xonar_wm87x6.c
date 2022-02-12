static void wm8776_write_spi(struct oxygen *chip,
unsigned int reg, unsigned int value)
{
oxygen_write_spi(chip, OXYGEN_SPI_TRIGGER |
OXYGEN_SPI_DATA_LENGTH_2 |
OXYGEN_SPI_CLOCK_160 |
(1 << OXYGEN_SPI_CODEC_SHIFT) |
OXYGEN_SPI_CEN_LATCH_CLOCK_LO,
(reg << 9) | value);
}
static void wm8776_write_i2c(struct oxygen *chip,
unsigned int reg, unsigned int value)
{
oxygen_write_i2c(chip, I2C_DEVICE_WM8776,
(reg << 1) | (value >> 8), value);
}
static void wm8776_write(struct oxygen *chip,
unsigned int reg, unsigned int value)
{
struct xonar_wm87x6 *data = chip->model_data;
if ((chip->model.function_flags & OXYGEN_FUNCTION_2WIRE_SPI_MASK) ==
OXYGEN_FUNCTION_SPI)
wm8776_write_spi(chip, reg, value);
else
wm8776_write_i2c(chip, reg, value);
if (reg < ARRAY_SIZE(data->wm8776_regs)) {
if (reg >= WM8776_HPLVOL && reg <= WM8776_DACMASTER)
value &= ~WM8776_UPDATE;
data->wm8776_regs[reg] = value;
}
}
static void wm8776_write_cached(struct oxygen *chip,
unsigned int reg, unsigned int value)
{
struct xonar_wm87x6 *data = chip->model_data;
if (reg >= ARRAY_SIZE(data->wm8776_regs) ||
value != data->wm8776_regs[reg])
wm8776_write(chip, reg, value);
}
static void wm8766_write(struct oxygen *chip,
unsigned int reg, unsigned int value)
{
struct xonar_wm87x6 *data = chip->model_data;
oxygen_write_spi(chip, OXYGEN_SPI_TRIGGER |
OXYGEN_SPI_DATA_LENGTH_2 |
OXYGEN_SPI_CLOCK_160 |
(0 << OXYGEN_SPI_CODEC_SHIFT) |
OXYGEN_SPI_CEN_LATCH_CLOCK_LO,
(reg << 9) | value);
if (reg < ARRAY_SIZE(data->wm8766_regs)) {
if ((reg >= WM8766_LDA1 && reg <= WM8766_RDA1) ||
(reg >= WM8766_LDA2 && reg <= WM8766_MASTDA))
value &= ~WM8766_UPDATE;
data->wm8766_regs[reg] = value;
}
}
static void wm8766_write_cached(struct oxygen *chip,
unsigned int reg, unsigned int value)
{
struct xonar_wm87x6 *data = chip->model_data;
if (reg >= ARRAY_SIZE(data->wm8766_regs) ||
value != data->wm8766_regs[reg])
wm8766_write(chip, reg, value);
}
static void wm8776_registers_init(struct oxygen *chip)
{
struct xonar_wm87x6 *data = chip->model_data;
wm8776_write(chip, WM8776_RESET, 0);
wm8776_write(chip, WM8776_PHASESWAP, WM8776_PH_MASK);
wm8776_write(chip, WM8776_DACCTRL1, WM8776_DZCEN |
WM8776_PL_LEFT_LEFT | WM8776_PL_RIGHT_RIGHT);
wm8776_write(chip, WM8776_DACMUTE, chip->dac_mute ? WM8776_DMUTE : 0);
wm8776_write(chip, WM8776_DACIFCTRL,
WM8776_DACFMT_LJUST | WM8776_DACWL_24);
wm8776_write(chip, WM8776_ADCIFCTRL,
data->wm8776_regs[WM8776_ADCIFCTRL]);
wm8776_write(chip, WM8776_MSTRCTRL, data->wm8776_regs[WM8776_MSTRCTRL]);
wm8776_write(chip, WM8776_PWRDOWN, data->wm8776_regs[WM8776_PWRDOWN]);
wm8776_write(chip, WM8776_HPLVOL, data->wm8776_regs[WM8776_HPLVOL]);
wm8776_write(chip, WM8776_HPRVOL, data->wm8776_regs[WM8776_HPRVOL] |
WM8776_UPDATE);
wm8776_write(chip, WM8776_ADCLVOL, data->wm8776_regs[WM8776_ADCLVOL]);
wm8776_write(chip, WM8776_ADCRVOL, data->wm8776_regs[WM8776_ADCRVOL]);
wm8776_write(chip, WM8776_ADCMUX, data->wm8776_regs[WM8776_ADCMUX]);
wm8776_write(chip, WM8776_DACLVOL, chip->dac_volume[0]);
wm8776_write(chip, WM8776_DACRVOL, chip->dac_volume[1] | WM8776_UPDATE);
}
static void wm8766_registers_init(struct oxygen *chip)
{
struct xonar_wm87x6 *data = chip->model_data;
wm8766_write(chip, WM8766_RESET, 0);
wm8766_write(chip, WM8766_DAC_CTRL, data->wm8766_regs[WM8766_DAC_CTRL]);
wm8766_write(chip, WM8766_INT_CTRL, WM8766_FMT_LJUST | WM8766_IWL_24);
wm8766_write(chip, WM8766_DAC_CTRL2,
WM8766_ZCD | (chip->dac_mute ? WM8766_DMUTE_MASK : 0));
wm8766_write(chip, WM8766_LDA1, chip->dac_volume[2]);
wm8766_write(chip, WM8766_RDA1, chip->dac_volume[3]);
wm8766_write(chip, WM8766_LDA2, chip->dac_volume[4]);
wm8766_write(chip, WM8766_RDA2, chip->dac_volume[5]);
wm8766_write(chip, WM8766_LDA3, chip->dac_volume[6]);
wm8766_write(chip, WM8766_RDA3, chip->dac_volume[7] | WM8766_UPDATE);
}
static void wm8776_init(struct oxygen *chip)
{
struct xonar_wm87x6 *data = chip->model_data;
data->wm8776_regs[WM8776_HPLVOL] = (0x79 - 60) | WM8776_HPZCEN;
data->wm8776_regs[WM8776_HPRVOL] = (0x79 - 60) | WM8776_HPZCEN;
data->wm8776_regs[WM8776_ADCIFCTRL] =
WM8776_ADCFMT_LJUST | WM8776_ADCWL_24 | WM8776_ADCMCLK;
data->wm8776_regs[WM8776_MSTRCTRL] =
WM8776_ADCRATE_256 | WM8776_DACRATE_256;
data->wm8776_regs[WM8776_PWRDOWN] = WM8776_HPPD;
data->wm8776_regs[WM8776_ADCLVOL] = 0xa5 | WM8776_ZCA;
data->wm8776_regs[WM8776_ADCRVOL] = 0xa5 | WM8776_ZCA;
data->wm8776_regs[WM8776_ADCMUX] = 0x001;
wm8776_registers_init(chip);
}
static void wm8766_init(struct oxygen *chip)
{
struct xonar_wm87x6 *data = chip->model_data;
data->wm8766_regs[WM8766_DAC_CTRL] =
WM8766_PL_LEFT_LEFT | WM8766_PL_RIGHT_RIGHT;
wm8766_registers_init(chip);
}
static void xonar_ds_handle_hp_jack(struct oxygen *chip)
{
struct xonar_wm87x6 *data = chip->model_data;
bool hp_plugged;
unsigned int reg;
mutex_lock(&chip->mutex);
hp_plugged = !(oxygen_read16(chip, OXYGEN_GPIO_DATA) &
GPIO_DS_HP_DETECT);
oxygen_write16_masked(chip, OXYGEN_GPIO_DATA,
hp_plugged ? 0 : GPIO_DS_OUTPUT_FRONTLR,
GPIO_DS_OUTPUT_FRONTLR);
reg = data->wm8766_regs[WM8766_DAC_CTRL] & ~WM8766_MUTEALL;
if (hp_plugged)
reg |= WM8766_MUTEALL;
wm8766_write_cached(chip, WM8766_DAC_CTRL, reg);
snd_jack_report(data->hp_jack, hp_plugged ? SND_JACK_HEADPHONE : 0);
mutex_unlock(&chip->mutex);
}
static void xonar_ds_init(struct oxygen *chip)
{
struct xonar_wm87x6 *data = chip->model_data;
data->generic.anti_pop_delay = 300;
data->generic.output_enable_bit = GPIO_DS_OUTPUT_ENABLE;
wm8776_init(chip);
wm8766_init(chip);
oxygen_set_bits16(chip, OXYGEN_GPIO_CONTROL,
GPIO_DS_INPUT_ROUTE | GPIO_DS_OUTPUT_FRONTLR);
oxygen_clear_bits16(chip, OXYGEN_GPIO_CONTROL,
GPIO_DS_HP_DETECT);
oxygen_set_bits16(chip, OXYGEN_GPIO_DATA, GPIO_DS_INPUT_ROUTE);
oxygen_set_bits16(chip, OXYGEN_GPIO_INTERRUPT_MASK, GPIO_DS_HP_DETECT);
chip->interrupt_mask |= OXYGEN_INT_GPIO;
xonar_enable_output(chip);
snd_jack_new(chip->card, "Headphone",
SND_JACK_HEADPHONE, &data->hp_jack);
xonar_ds_handle_hp_jack(chip);
snd_component_add(chip->card, "WM8776");
snd_component_add(chip->card, "WM8766");
}
static void xonar_hdav_slim_init(struct oxygen *chip)
{
struct xonar_wm87x6 *data = chip->model_data;
data->generic.anti_pop_delay = 300;
data->generic.output_enable_bit = GPIO_SLIM_OUTPUT_ENABLE;
wm8776_init(chip);
oxygen_set_bits16(chip, OXYGEN_GPIO_CONTROL,
GPIO_SLIM_HDMI_DISABLE |
GPIO_SLIM_FIRMWARE_CLK |
GPIO_SLIM_FIRMWARE_DATA);
xonar_hdmi_init(chip, &data->hdmi);
xonar_enable_output(chip);
snd_component_add(chip->card, "WM8776");
}
static void xonar_ds_cleanup(struct oxygen *chip)
{
xonar_disable_output(chip);
wm8776_write(chip, WM8776_RESET, 0);
}
static void xonar_hdav_slim_cleanup(struct oxygen *chip)
{
xonar_hdmi_cleanup(chip);
xonar_disable_output(chip);
wm8776_write(chip, WM8776_RESET, 0);
msleep(2);
}
static void xonar_ds_suspend(struct oxygen *chip)
{
xonar_ds_cleanup(chip);
}
static void xonar_hdav_slim_suspend(struct oxygen *chip)
{
xonar_hdav_slim_cleanup(chip);
}
static void xonar_ds_resume(struct oxygen *chip)
{
wm8776_registers_init(chip);
wm8766_registers_init(chip);
xonar_enable_output(chip);
xonar_ds_handle_hp_jack(chip);
}
static void xonar_hdav_slim_resume(struct oxygen *chip)
{
struct xonar_wm87x6 *data = chip->model_data;
wm8776_registers_init(chip);
xonar_hdmi_resume(chip, &data->hdmi);
xonar_enable_output(chip);
}
static void wm8776_adc_hardware_filter(unsigned int channel,
struct snd_pcm_hardware *hardware)
{
if (channel == PCM_A) {
hardware->rates = SNDRV_PCM_RATE_32000 |
SNDRV_PCM_RATE_44100 |
SNDRV_PCM_RATE_48000 |
SNDRV_PCM_RATE_64000 |
SNDRV_PCM_RATE_88200 |
SNDRV_PCM_RATE_96000;
hardware->rate_max = 96000;
}
}
static void xonar_hdav_slim_hardware_filter(unsigned int channel,
struct snd_pcm_hardware *hardware)
{
wm8776_adc_hardware_filter(channel, hardware);
xonar_hdmi_pcm_hardware_filter(channel, hardware);
}
static void set_wm87x6_dac_params(struct oxygen *chip,
struct snd_pcm_hw_params *params)
{
}
static void set_wm8776_adc_params(struct oxygen *chip,
struct snd_pcm_hw_params *params)
{
u16 reg;
reg = WM8776_ADCRATE_256 | WM8776_DACRATE_256;
if (params_rate(params) > 48000)
reg |= WM8776_ADCOSR;
wm8776_write_cached(chip, WM8776_MSTRCTRL, reg);
}
static void set_hdav_slim_dac_params(struct oxygen *chip,
struct snd_pcm_hw_params *params)
{
struct xonar_wm87x6 *data = chip->model_data;
xonar_set_hdmi_params(chip, &data->hdmi, params);
}
static void update_wm8776_volume(struct oxygen *chip)
{
struct xonar_wm87x6 *data = chip->model_data;
u8 to_change;
if (chip->dac_volume[0] == chip->dac_volume[1]) {
if (chip->dac_volume[0] != data->wm8776_regs[WM8776_DACLVOL] ||
chip->dac_volume[1] != data->wm8776_regs[WM8776_DACRVOL]) {
wm8776_write(chip, WM8776_DACMASTER,
chip->dac_volume[0] | WM8776_UPDATE);
data->wm8776_regs[WM8776_DACLVOL] = chip->dac_volume[0];
data->wm8776_regs[WM8776_DACRVOL] = chip->dac_volume[0];
}
} else {
to_change = (chip->dac_volume[0] !=
data->wm8776_regs[WM8776_DACLVOL]) << 0;
to_change |= (chip->dac_volume[1] !=
data->wm8776_regs[WM8776_DACLVOL]) << 1;
if (to_change & 1)
wm8776_write(chip, WM8776_DACLVOL, chip->dac_volume[0] |
((to_change & 2) ? 0 : WM8776_UPDATE));
if (to_change & 2)
wm8776_write(chip, WM8776_DACRVOL,
chip->dac_volume[1] | WM8776_UPDATE);
}
}
static void update_wm87x6_volume(struct oxygen *chip)
{
static const u8 wm8766_regs[6] = {
WM8766_LDA1, WM8766_RDA1,
WM8766_LDA2, WM8766_RDA2,
WM8766_LDA3, WM8766_RDA3,
};
struct xonar_wm87x6 *data = chip->model_data;
unsigned int i;
u8 to_change;
update_wm8776_volume(chip);
if (chip->dac_volume[2] == chip->dac_volume[3] &&
chip->dac_volume[2] == chip->dac_volume[4] &&
chip->dac_volume[2] == chip->dac_volume[5] &&
chip->dac_volume[2] == chip->dac_volume[6] &&
chip->dac_volume[2] == chip->dac_volume[7]) {
to_change = 0;
for (i = 0; i < 6; ++i)
if (chip->dac_volume[2] !=
data->wm8766_regs[wm8766_regs[i]])
to_change = 1;
if (to_change) {
wm8766_write(chip, WM8766_MASTDA,
chip->dac_volume[2] | WM8766_UPDATE);
for (i = 0; i < 6; ++i)
data->wm8766_regs[wm8766_regs[i]] =
chip->dac_volume[2];
}
} else {
to_change = 0;
for (i = 0; i < 6; ++i)
to_change |= (chip->dac_volume[2 + i] !=
data->wm8766_regs[wm8766_regs[i]]) << i;
for (i = 0; i < 6; ++i)
if (to_change & (1 << i))
wm8766_write(chip, wm8766_regs[i],
chip->dac_volume[2 + i] |
((to_change & (0x3e << i))
? 0 : WM8766_UPDATE));
}
}
static void update_wm8776_mute(struct oxygen *chip)
{
wm8776_write_cached(chip, WM8776_DACMUTE,
chip->dac_mute ? WM8776_DMUTE : 0);
}
static void update_wm87x6_mute(struct oxygen *chip)
{
update_wm8776_mute(chip);
wm8766_write_cached(chip, WM8766_DAC_CTRL2, WM8766_ZCD |
(chip->dac_mute ? WM8766_DMUTE_MASK : 0));
}
static void update_wm8766_center_lfe_mix(struct oxygen *chip, bool mixed)
{
struct xonar_wm87x6 *data = chip->model_data;
unsigned int reg;
reg = data->wm8766_regs[WM8766_DAC_CTRL] &
~(WM8766_PL_LEFT_MASK | WM8766_PL_RIGHT_MASK);
if (mixed)
reg |= WM8766_PL_LEFT_LRMIX | WM8766_PL_RIGHT_LRMIX;
else
reg |= WM8766_PL_LEFT_LEFT | WM8766_PL_RIGHT_RIGHT;
wm8766_write_cached(chip, WM8766_DAC_CTRL, reg);
}
static void xonar_ds_gpio_changed(struct oxygen *chip)
{
xonar_ds_handle_hp_jack(chip);
}
static int wm8776_bit_switch_get(struct snd_kcontrol *ctl,
struct snd_ctl_elem_value *value)
{
struct oxygen *chip = ctl->private_data;
struct xonar_wm87x6 *data = chip->model_data;
u16 bit = ctl->private_value & 0xffff;
unsigned int reg_index = (ctl->private_value >> 16) & 0xff;
bool invert = (ctl->private_value >> 24) & 1;
value->value.integer.value[0] =
((data->wm8776_regs[reg_index] & bit) != 0) ^ invert;
return 0;
}
static int wm8776_bit_switch_put(struct snd_kcontrol *ctl,
struct snd_ctl_elem_value *value)
{
struct oxygen *chip = ctl->private_data;
struct xonar_wm87x6 *data = chip->model_data;
u16 bit = ctl->private_value & 0xffff;
u16 reg_value;
unsigned int reg_index = (ctl->private_value >> 16) & 0xff;
bool invert = (ctl->private_value >> 24) & 1;
int changed;
mutex_lock(&chip->mutex);
reg_value = data->wm8776_regs[reg_index] & ~bit;
if (value->value.integer.value[0] ^ invert)
reg_value |= bit;
changed = reg_value != data->wm8776_regs[reg_index];
if (changed)
wm8776_write(chip, reg_index, reg_value);
mutex_unlock(&chip->mutex);
return changed;
}
static int wm8776_field_enum_info(struct snd_kcontrol *ctl,
struct snd_ctl_elem_info *info)
{
static const char *const hld[16] = {
"0 ms", "2.67 ms", "5.33 ms", "10.6 ms",
"21.3 ms", "42.7 ms", "85.3 ms", "171 ms",
"341 ms", "683 ms", "1.37 s", "2.73 s",
"5.46 s", "10.9 s", "21.8 s", "43.7 s",
};
static const char *const atk_lim[11] = {
"0.25 ms", "0.5 ms", "1 ms", "2 ms",
"4 ms", "8 ms", "16 ms", "32 ms",
"64 ms", "128 ms", "256 ms",
};
static const char *const atk_alc[11] = {
"8.40 ms", "16.8 ms", "33.6 ms", "67.2 ms",
"134 ms", "269 ms", "538 ms", "1.08 s",
"2.15 s", "4.3 s", "8.6 s",
};
static const char *const dcy_lim[11] = {
"1.2 ms", "2.4 ms", "4.8 ms", "9.6 ms",
"19.2 ms", "38.4 ms", "76.8 ms", "154 ms",
"307 ms", "614 ms", "1.23 s",
};
static const char *const dcy_alc[11] = {
"33.5 ms", "67.0 ms", "134 ms", "268 ms",
"536 ms", "1.07 s", "2.14 s", "4.29 s",
"8.58 s", "17.2 s", "34.3 s",
};
static const char *const tranwin[8] = {
"0 us", "62.5 us", "125 us", "250 us",
"500 us", "1 ms", "2 ms", "4 ms",
};
u8 max;
const char *const *names;
max = (ctl->private_value >> 12) & 0xf;
switch ((ctl->private_value >> 24) & 0x1f) {
case WM8776_ALCCTRL2:
names = hld;
break;
case WM8776_ALCCTRL3:
if (((ctl->private_value >> 20) & 0xf) == 0) {
if (ctl->private_value & LC_CONTROL_LIMITER)
names = atk_lim;
else
names = atk_alc;
} else {
if (ctl->private_value & LC_CONTROL_LIMITER)
names = dcy_lim;
else
names = dcy_alc;
}
break;
case WM8776_LIMITER:
names = tranwin;
break;
default:
return -ENXIO;
}
return snd_ctl_enum_info(info, 1, max + 1, names);
}
static int wm8776_field_volume_info(struct snd_kcontrol *ctl,
struct snd_ctl_elem_info *info)
{
info->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
info->count = 1;
info->value.integer.min = (ctl->private_value >> 8) & 0xf;
info->value.integer.max = (ctl->private_value >> 12) & 0xf;
return 0;
}
static void wm8776_field_set_from_ctl(struct snd_kcontrol *ctl)
{
struct oxygen *chip = ctl->private_data;
struct xonar_wm87x6 *data = chip->model_data;
unsigned int value, reg_index, mode;
u8 min, max, shift;
u16 mask, reg_value;
bool invert;
if ((data->wm8776_regs[WM8776_ALCCTRL1] & WM8776_LCSEL_MASK) ==
WM8776_LCSEL_LIMITER)
mode = LC_CONTROL_LIMITER;
else
mode = LC_CONTROL_ALC;
if (!(ctl->private_value & mode))
return;
value = ctl->private_value & 0xf;
min = (ctl->private_value >> 8) & 0xf;
max = (ctl->private_value >> 12) & 0xf;
mask = (ctl->private_value >> 16) & 0xf;
shift = (ctl->private_value >> 20) & 0xf;
reg_index = (ctl->private_value >> 24) & 0x1f;
invert = (ctl->private_value >> 29) & 0x1;
if (invert)
value = max - (value - min);
reg_value = data->wm8776_regs[reg_index];
reg_value &= ~(mask << shift);
reg_value |= value << shift;
wm8776_write_cached(chip, reg_index, reg_value);
}
static int wm8776_field_set(struct snd_kcontrol *ctl, unsigned int value)
{
struct oxygen *chip = ctl->private_data;
u8 min, max;
int changed;
min = (ctl->private_value >> 8) & 0xf;
max = (ctl->private_value >> 12) & 0xf;
if (value < min || value > max)
return -EINVAL;
mutex_lock(&chip->mutex);
changed = value != (ctl->private_value & 0xf);
if (changed) {
ctl->private_value = (ctl->private_value & ~0xf) | value;
wm8776_field_set_from_ctl(ctl);
}
mutex_unlock(&chip->mutex);
return changed;
}
static int wm8776_field_enum_get(struct snd_kcontrol *ctl,
struct snd_ctl_elem_value *value)
{
value->value.enumerated.item[0] = ctl->private_value & 0xf;
return 0;
}
static int wm8776_field_volume_get(struct snd_kcontrol *ctl,
struct snd_ctl_elem_value *value)
{
value->value.integer.value[0] = ctl->private_value & 0xf;
return 0;
}
static int wm8776_field_enum_put(struct snd_kcontrol *ctl,
struct snd_ctl_elem_value *value)
{
return wm8776_field_set(ctl, value->value.enumerated.item[0]);
}
static int wm8776_field_volume_put(struct snd_kcontrol *ctl,
struct snd_ctl_elem_value *value)
{
return wm8776_field_set(ctl, value->value.integer.value[0]);
}
static int wm8776_hp_vol_info(struct snd_kcontrol *ctl,
struct snd_ctl_elem_info *info)
{
info->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
info->count = 2;
info->value.integer.min = 0x79 - 60;
info->value.integer.max = 0x7f;
return 0;
}
static int wm8776_hp_vol_get(struct snd_kcontrol *ctl,
struct snd_ctl_elem_value *value)
{
struct oxygen *chip = ctl->private_data;
struct xonar_wm87x6 *data = chip->model_data;
mutex_lock(&chip->mutex);
value->value.integer.value[0] =
data->wm8776_regs[WM8776_HPLVOL] & WM8776_HPATT_MASK;
value->value.integer.value[1] =
data->wm8776_regs[WM8776_HPRVOL] & WM8776_HPATT_MASK;
mutex_unlock(&chip->mutex);
return 0;
}
static int wm8776_hp_vol_put(struct snd_kcontrol *ctl,
struct snd_ctl_elem_value *value)
{
struct oxygen *chip = ctl->private_data;
struct xonar_wm87x6 *data = chip->model_data;
u8 to_update;
mutex_lock(&chip->mutex);
to_update = (value->value.integer.value[0] !=
(data->wm8776_regs[WM8776_HPLVOL] & WM8776_HPATT_MASK))
<< 0;
to_update |= (value->value.integer.value[1] !=
(data->wm8776_regs[WM8776_HPRVOL] & WM8776_HPATT_MASK))
<< 1;
if (value->value.integer.value[0] == value->value.integer.value[1]) {
if (to_update) {
wm8776_write(chip, WM8776_HPMASTER,
value->value.integer.value[0] |
WM8776_HPZCEN | WM8776_UPDATE);
data->wm8776_regs[WM8776_HPLVOL] =
value->value.integer.value[0] | WM8776_HPZCEN;
data->wm8776_regs[WM8776_HPRVOL] =
value->value.integer.value[0] | WM8776_HPZCEN;
}
} else {
if (to_update & 1)
wm8776_write(chip, WM8776_HPLVOL,
value->value.integer.value[0] |
WM8776_HPZCEN |
((to_update & 2) ? 0 : WM8776_UPDATE));
if (to_update & 2)
wm8776_write(chip, WM8776_HPRVOL,
value->value.integer.value[1] |
WM8776_HPZCEN | WM8776_UPDATE);
}
mutex_unlock(&chip->mutex);
return to_update != 0;
}
static int wm8776_input_mux_get(struct snd_kcontrol *ctl,
struct snd_ctl_elem_value *value)
{
struct oxygen *chip = ctl->private_data;
struct xonar_wm87x6 *data = chip->model_data;
unsigned int mux_bit = ctl->private_value;
value->value.integer.value[0] =
!!(data->wm8776_regs[WM8776_ADCMUX] & mux_bit);
return 0;
}
static int wm8776_input_mux_put(struct snd_kcontrol *ctl,
struct snd_ctl_elem_value *value)
{
struct oxygen *chip = ctl->private_data;
struct xonar_wm87x6 *data = chip->model_data;
struct snd_kcontrol *other_ctl;
unsigned int mux_bit = ctl->private_value;
u16 reg;
int changed;
mutex_lock(&chip->mutex);
reg = data->wm8776_regs[WM8776_ADCMUX];
if (value->value.integer.value[0]) {
reg |= mux_bit;
mux_bit ^= 3;
if (reg & mux_bit) {
reg &= ~mux_bit;
if (mux_bit == 1)
other_ctl = data->line_adcmux_control;
else
other_ctl = data->mic_adcmux_control;
snd_ctl_notify(chip->card, SNDRV_CTL_EVENT_MASK_VALUE,
&other_ctl->id);
}
} else
reg &= ~mux_bit;
changed = reg != data->wm8776_regs[WM8776_ADCMUX];
if (changed) {
oxygen_write16_masked(chip, OXYGEN_GPIO_DATA,
reg & 1 ? GPIO_DS_INPUT_ROUTE : 0,
GPIO_DS_INPUT_ROUTE);
wm8776_write(chip, WM8776_ADCMUX, reg);
}
mutex_unlock(&chip->mutex);
return changed;
}
static int wm8776_input_vol_info(struct snd_kcontrol *ctl,
struct snd_ctl_elem_info *info)
{
info->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
info->count = 2;
info->value.integer.min = 0xa5;
info->value.integer.max = 0xff;
return 0;
}
static int wm8776_input_vol_get(struct snd_kcontrol *ctl,
struct snd_ctl_elem_value *value)
{
struct oxygen *chip = ctl->private_data;
struct xonar_wm87x6 *data = chip->model_data;
mutex_lock(&chip->mutex);
value->value.integer.value[0] =
data->wm8776_regs[WM8776_ADCLVOL] & WM8776_AGMASK;
value->value.integer.value[1] =
data->wm8776_regs[WM8776_ADCRVOL] & WM8776_AGMASK;
mutex_unlock(&chip->mutex);
return 0;
}
static int wm8776_input_vol_put(struct snd_kcontrol *ctl,
struct snd_ctl_elem_value *value)
{
struct oxygen *chip = ctl->private_data;
struct xonar_wm87x6 *data = chip->model_data;
int changed = 0;
mutex_lock(&chip->mutex);
changed = (value->value.integer.value[0] !=
(data->wm8776_regs[WM8776_ADCLVOL] & WM8776_AGMASK)) ||
(value->value.integer.value[1] !=
(data->wm8776_regs[WM8776_ADCRVOL] & WM8776_AGMASK));
wm8776_write_cached(chip, WM8776_ADCLVOL,
value->value.integer.value[0] | WM8776_ZCA);
wm8776_write_cached(chip, WM8776_ADCRVOL,
value->value.integer.value[1] | WM8776_ZCA);
mutex_unlock(&chip->mutex);
return changed;
}
static int wm8776_level_control_info(struct snd_kcontrol *ctl,
struct snd_ctl_elem_info *info)
{
static const char *const names[3] = {
"None", "Peak Limiter", "Automatic Level Control"
};
return snd_ctl_enum_info(info, 1, 3, names);
}
static int wm8776_level_control_get(struct snd_kcontrol *ctl,
struct snd_ctl_elem_value *value)
{
struct oxygen *chip = ctl->private_data;
struct xonar_wm87x6 *data = chip->model_data;
if (!(data->wm8776_regs[WM8776_ALCCTRL2] & WM8776_LCEN))
value->value.enumerated.item[0] = 0;
else if ((data->wm8776_regs[WM8776_ALCCTRL1] & WM8776_LCSEL_MASK) ==
WM8776_LCSEL_LIMITER)
value->value.enumerated.item[0] = 1;
else
value->value.enumerated.item[0] = 2;
return 0;
}
static void activate_control(struct oxygen *chip,
struct snd_kcontrol *ctl, unsigned int mode)
{
unsigned int access;
if (ctl->private_value & mode)
access = 0;
else
access = SNDRV_CTL_ELEM_ACCESS_INACTIVE;
if ((ctl->vd[0].access & SNDRV_CTL_ELEM_ACCESS_INACTIVE) != access) {
ctl->vd[0].access ^= SNDRV_CTL_ELEM_ACCESS_INACTIVE;
snd_ctl_notify(chip->card, SNDRV_CTL_EVENT_MASK_INFO, &ctl->id);
}
}
static int wm8776_level_control_put(struct snd_kcontrol *ctl,
struct snd_ctl_elem_value *value)
{
struct oxygen *chip = ctl->private_data;
struct xonar_wm87x6 *data = chip->model_data;
unsigned int mode = 0, i;
u16 ctrl1, ctrl2;
int changed;
if (value->value.enumerated.item[0] >= 3)
return -EINVAL;
mutex_lock(&chip->mutex);
changed = value->value.enumerated.item[0] != ctl->private_value;
if (changed) {
ctl->private_value = value->value.enumerated.item[0];
ctrl1 = data->wm8776_regs[WM8776_ALCCTRL1];
ctrl2 = data->wm8776_regs[WM8776_ALCCTRL2];
switch (value->value.enumerated.item[0]) {
default:
wm8776_write_cached(chip, WM8776_ALCCTRL2,
ctrl2 & ~WM8776_LCEN);
break;
case 1:
wm8776_write_cached(chip, WM8776_ALCCTRL1,
(ctrl1 & ~WM8776_LCSEL_MASK) |
WM8776_LCSEL_LIMITER);
wm8776_write_cached(chip, WM8776_ALCCTRL2,
ctrl2 | WM8776_LCEN);
mode = LC_CONTROL_LIMITER;
break;
case 2:
wm8776_write_cached(chip, WM8776_ALCCTRL1,
(ctrl1 & ~WM8776_LCSEL_MASK) |
WM8776_LCSEL_ALC_STEREO);
wm8776_write_cached(chip, WM8776_ALCCTRL2,
ctrl2 | WM8776_LCEN);
mode = LC_CONTROL_ALC;
break;
}
for (i = 0; i < ARRAY_SIZE(data->lc_controls); ++i)
activate_control(chip, data->lc_controls[i], mode);
}
mutex_unlock(&chip->mutex);
return changed;
}
static int hpf_info(struct snd_kcontrol *ctl, struct snd_ctl_elem_info *info)
{
static const char *const names[2] = {
"None", "High-pass Filter"
};
return snd_ctl_enum_info(info, 1, 2, names);
}
static int hpf_get(struct snd_kcontrol *ctl, struct snd_ctl_elem_value *value)
{
struct oxygen *chip = ctl->private_data;
struct xonar_wm87x6 *data = chip->model_data;
value->value.enumerated.item[0] =
!(data->wm8776_regs[WM8776_ADCIFCTRL] & WM8776_ADCHPD);
return 0;
}
static int hpf_put(struct snd_kcontrol *ctl, struct snd_ctl_elem_value *value)
{
struct oxygen *chip = ctl->private_data;
struct xonar_wm87x6 *data = chip->model_data;
unsigned int reg;
int changed;
mutex_lock(&chip->mutex);
reg = data->wm8776_regs[WM8776_ADCIFCTRL] & ~WM8776_ADCHPD;
if (!value->value.enumerated.item[0])
reg |= WM8776_ADCHPD;
changed = reg != data->wm8776_regs[WM8776_ADCIFCTRL];
if (changed)
wm8776_write(chip, WM8776_ADCIFCTRL, reg);
mutex_unlock(&chip->mutex);
return changed;
}
static int add_lc_controls(struct oxygen *chip)
{
struct xonar_wm87x6 *data = chip->model_data;
unsigned int i;
struct snd_kcontrol *ctl;
int err;
BUILD_BUG_ON(ARRAY_SIZE(lc_controls) != ARRAY_SIZE(data->lc_controls));
for (i = 0; i < ARRAY_SIZE(lc_controls); ++i) {
ctl = snd_ctl_new1(&lc_controls[i], chip);
if (!ctl)
return -ENOMEM;
err = snd_ctl_add(chip->card, ctl);
if (err < 0)
return err;
data->lc_controls[i] = ctl;
}
return 0;
}
static int xonar_ds_mixer_init(struct oxygen *chip)
{
struct xonar_wm87x6 *data = chip->model_data;
unsigned int i;
struct snd_kcontrol *ctl;
int err;
for (i = 0; i < ARRAY_SIZE(ds_controls); ++i) {
ctl = snd_ctl_new1(&ds_controls[i], chip);
if (!ctl)
return -ENOMEM;
err = snd_ctl_add(chip->card, ctl);
if (err < 0)
return err;
if (!strcmp(ctl->id.name, "Line Capture Switch"))
data->line_adcmux_control = ctl;
else if (!strcmp(ctl->id.name, "Mic Capture Switch"))
data->mic_adcmux_control = ctl;
}
if (!data->line_adcmux_control || !data->mic_adcmux_control)
return -ENXIO;
return add_lc_controls(chip);
}
static int xonar_hdav_slim_mixer_init(struct oxygen *chip)
{
unsigned int i;
struct snd_kcontrol *ctl;
int err;
for (i = 0; i < ARRAY_SIZE(hdav_slim_controls); ++i) {
ctl = snd_ctl_new1(&hdav_slim_controls[i], chip);
if (!ctl)
return -ENOMEM;
err = snd_ctl_add(chip->card, ctl);
if (err < 0)
return err;
}
return add_lc_controls(chip);
}
static void dump_wm8776_registers(struct oxygen *chip,
struct snd_info_buffer *buffer)
{
struct xonar_wm87x6 *data = chip->model_data;
unsigned int i;
snd_iprintf(buffer, "\nWM8776:\n00:");
for (i = 0; i < 0x10; ++i)
snd_iprintf(buffer, " %03x", data->wm8776_regs[i]);
snd_iprintf(buffer, "\n10:");
for (i = 0x10; i < 0x17; ++i)
snd_iprintf(buffer, " %03x", data->wm8776_regs[i]);
snd_iprintf(buffer, "\n");
}
static void dump_wm87x6_registers(struct oxygen *chip,
struct snd_info_buffer *buffer)
{
struct xonar_wm87x6 *data = chip->model_data;
unsigned int i;
dump_wm8776_registers(chip, buffer);
snd_iprintf(buffer, "\nWM8766:\n00:");
for (i = 0; i < 0x10; ++i)
snd_iprintf(buffer, " %03x", data->wm8766_regs[i]);
snd_iprintf(buffer, "\n");
}
int __devinit get_xonar_wm87x6_model(struct oxygen *chip,
const struct pci_device_id *id)
{
switch (id->subdevice) {
case 0x838e:
chip->model = model_xonar_ds;
break;
case 0x835e:
chip->model = model_xonar_hdav_slim;
break;
default:
return -EINVAL;
}
return 0;
}
