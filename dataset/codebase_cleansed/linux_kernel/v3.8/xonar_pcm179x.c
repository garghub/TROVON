static inline void pcm1796_write_spi(struct oxygen *chip, unsigned int codec,
u8 reg, u8 value)
{
static const u8 codec_map[4] = {
0, 1, 2, 4
};
oxygen_write_spi(chip, OXYGEN_SPI_TRIGGER |
OXYGEN_SPI_DATA_LENGTH_2 |
OXYGEN_SPI_CLOCK_160 |
(codec_map[codec] << OXYGEN_SPI_CODEC_SHIFT) |
OXYGEN_SPI_CEN_LATCH_CLOCK_HI,
(reg << 8) | value);
}
static inline void pcm1796_write_i2c(struct oxygen *chip, unsigned int codec,
u8 reg, u8 value)
{
oxygen_write_i2c(chip, I2C_DEVICE_PCM1796(codec), reg, value);
}
static void pcm1796_write(struct oxygen *chip, unsigned int codec,
u8 reg, u8 value)
{
struct xonar_pcm179x *data = chip->model_data;
if ((chip->model.function_flags & OXYGEN_FUNCTION_2WIRE_SPI_MASK) ==
OXYGEN_FUNCTION_SPI)
pcm1796_write_spi(chip, codec, reg, value);
else
pcm1796_write_i2c(chip, codec, reg, value);
if ((unsigned int)(reg - PCM1796_REG_BASE)
< ARRAY_SIZE(data->pcm1796_regs[codec]))
data->pcm1796_regs[codec][reg - PCM1796_REG_BASE] = value;
}
static void pcm1796_write_cached(struct oxygen *chip, unsigned int codec,
u8 reg, u8 value)
{
struct xonar_pcm179x *data = chip->model_data;
if (value != data->pcm1796_regs[codec][reg - PCM1796_REG_BASE])
pcm1796_write(chip, codec, reg, value);
}
static void cs2000_write(struct oxygen *chip, u8 reg, u8 value)
{
struct xonar_pcm179x *data = chip->model_data;
oxygen_write_i2c(chip, I2C_DEVICE_CS2000, reg, value);
data->cs2000_regs[reg] = value;
}
static void cs2000_write_cached(struct oxygen *chip, u8 reg, u8 value)
{
struct xonar_pcm179x *data = chip->model_data;
if (value != data->cs2000_regs[reg])
cs2000_write(chip, reg, value);
}
static void pcm1796_registers_init(struct oxygen *chip)
{
struct xonar_pcm179x *data = chip->model_data;
unsigned int i;
s8 gain_offset;
msleep(1);
gain_offset = data->hp_active ? data->hp_gain_offset : 0;
for (i = 0; i < data->dacs; ++i) {
pcm1796_write(chip, i, 18,
data->pcm1796_regs[0][18 - PCM1796_REG_BASE]);
pcm1796_write(chip, i, 16, chip->dac_volume[i * 2]
+ gain_offset);
pcm1796_write(chip, i, 17, chip->dac_volume[i * 2 + 1]
+ gain_offset);
pcm1796_write(chip, i, 19,
data->pcm1796_regs[0][19 - PCM1796_REG_BASE]);
pcm1796_write(chip, i, 20,
data->pcm1796_regs[0][20 - PCM1796_REG_BASE]);
pcm1796_write(chip, i, 21, 0);
gain_offset = 0;
}
}
static void pcm1796_init(struct oxygen *chip)
{
struct xonar_pcm179x *data = chip->model_data;
data->pcm1796_regs[0][18 - PCM1796_REG_BASE] =
PCM1796_DMF_DISABLED | PCM1796_FMT_24_I2S | PCM1796_ATLD;
if (!data->broken_i2c)
data->pcm1796_regs[0][18 - PCM1796_REG_BASE] |= PCM1796_MUTE;
data->pcm1796_regs[0][19 - PCM1796_REG_BASE] =
PCM1796_FLT_SHARP | PCM1796_ATS_1;
data->pcm1796_regs[0][20 - PCM1796_REG_BASE] =
data->h6 ? PCM1796_OS_64 : PCM1796_OS_128;
pcm1796_registers_init(chip);
data->current_rate = 48000;
}
static void xonar_d2_init(struct oxygen *chip)
{
struct xonar_pcm179x *data = chip->model_data;
data->generic.anti_pop_delay = 300;
data->generic.output_enable_bit = GPIO_D2_OUTPUT_ENABLE;
data->dacs = 4;
pcm1796_init(chip);
oxygen_set_bits16(chip, OXYGEN_GPIO_CONTROL, GPIO_D2_ALT);
oxygen_clear_bits16(chip, OXYGEN_GPIO_DATA, GPIO_D2_ALT);
oxygen_ac97_set_bits(chip, 0, CM9780_JACK, CM9780_FMIC2MIC);
xonar_init_cs53x1(chip);
xonar_enable_output(chip);
snd_component_add(chip->card, "PCM1796");
snd_component_add(chip->card, "CS5381");
}
static void xonar_d2x_init(struct oxygen *chip)
{
struct xonar_pcm179x *data = chip->model_data;
data->generic.ext_power_reg = OXYGEN_GPIO_DATA;
data->generic.ext_power_int_reg = OXYGEN_GPIO_INTERRUPT_MASK;
data->generic.ext_power_bit = GPIO_D2X_EXT_POWER;
oxygen_clear_bits16(chip, OXYGEN_GPIO_CONTROL, GPIO_D2X_EXT_POWER);
xonar_init_ext_power(chip);
xonar_d2_init(chip);
}
static void xonar_hdav_init(struct oxygen *chip)
{
struct xonar_hdav *data = chip->model_data;
oxygen_write16(chip, OXYGEN_2WIRE_BUS_STATUS,
OXYGEN_2WIRE_LENGTH_8 |
OXYGEN_2WIRE_INTERRUPT_MASK |
OXYGEN_2WIRE_SPEED_STANDARD);
data->pcm179x.generic.anti_pop_delay = 100;
data->pcm179x.generic.output_enable_bit = GPIO_HDAV_OUTPUT_ENABLE;
data->pcm179x.generic.ext_power_reg = OXYGEN_GPI_DATA;
data->pcm179x.generic.ext_power_int_reg = OXYGEN_GPI_INTERRUPT_MASK;
data->pcm179x.generic.ext_power_bit = GPI_EXT_POWER;
data->pcm179x.dacs = chip->model.dac_channels_mixer / 2;
data->pcm179x.h6 = chip->model.dac_channels_mixer > 2;
pcm1796_init(chip);
oxygen_set_bits16(chip, OXYGEN_GPIO_CONTROL,
GPIO_HDAV_MAGIC | GPIO_INPUT_ROUTE);
oxygen_clear_bits16(chip, OXYGEN_GPIO_DATA, GPIO_INPUT_ROUTE);
xonar_init_cs53x1(chip);
xonar_init_ext_power(chip);
xonar_hdmi_init(chip, &data->hdmi);
xonar_enable_output(chip);
snd_component_add(chip->card, "PCM1796");
snd_component_add(chip->card, "CS5381");
}
static void xonar_st_init_i2c(struct oxygen *chip)
{
oxygen_write16(chip, OXYGEN_2WIRE_BUS_STATUS,
OXYGEN_2WIRE_LENGTH_8 |
OXYGEN_2WIRE_INTERRUPT_MASK |
OXYGEN_2WIRE_SPEED_STANDARD);
}
static void xonar_st_init_common(struct oxygen *chip)
{
struct xonar_pcm179x *data = chip->model_data;
data->generic.output_enable_bit = GPIO_ST_OUTPUT_ENABLE;
data->dacs = chip->model.dac_channels_mixer / 2;
data->hp_gain_offset = 2*-18;
pcm1796_init(chip);
oxygen_set_bits16(chip, OXYGEN_GPIO_CONTROL,
GPIO_INPUT_ROUTE | GPIO_ST_HP_REAR |
GPIO_ST_MAGIC | GPIO_ST_HP);
oxygen_clear_bits16(chip, OXYGEN_GPIO_DATA,
GPIO_INPUT_ROUTE | GPIO_ST_HP_REAR | GPIO_ST_HP);
xonar_init_cs53x1(chip);
xonar_enable_output(chip);
snd_component_add(chip->card, "PCM1792A");
snd_component_add(chip->card, "CS5381");
}
static void cs2000_registers_init(struct oxygen *chip)
{
struct xonar_pcm179x *data = chip->model_data;
cs2000_write(chip, CS2000_GLOBAL_CFG, CS2000_FREEZE);
cs2000_write(chip, CS2000_DEV_CTRL, 0);
cs2000_write(chip, CS2000_DEV_CFG_1,
CS2000_R_MOD_SEL_1 |
(0 << CS2000_R_SEL_SHIFT) |
CS2000_AUX_OUT_SRC_REF_CLK |
CS2000_EN_DEV_CFG_1);
cs2000_write(chip, CS2000_DEV_CFG_2,
(0 << CS2000_LOCK_CLK_SHIFT) |
CS2000_FRAC_N_SRC_STATIC);
cs2000_write(chip, CS2000_RATIO_0 + 0, 0x00);
cs2000_write(chip, CS2000_RATIO_0 + 1, 0x10);
cs2000_write(chip, CS2000_RATIO_0 + 2, 0x00);
cs2000_write(chip, CS2000_RATIO_0 + 3, 0x00);
cs2000_write(chip, CS2000_FUN_CFG_1,
data->cs2000_regs[CS2000_FUN_CFG_1]);
cs2000_write(chip, CS2000_FUN_CFG_2, 0);
cs2000_write(chip, CS2000_GLOBAL_CFG, CS2000_EN_DEV_CFG_2);
msleep(3);
}
static void xonar_st_init(struct oxygen *chip)
{
struct xonar_pcm179x *data = chip->model_data;
data->generic.anti_pop_delay = 100;
data->h6 = chip->model.dac_channels_mixer > 2;
data->has_cs2000 = 1;
data->cs2000_regs[CS2000_FUN_CFG_1] = CS2000_REF_CLK_DIV_1;
data->broken_i2c = true;
oxygen_write16(chip, OXYGEN_I2S_A_FORMAT,
OXYGEN_RATE_48000 |
OXYGEN_I2S_FORMAT_I2S |
OXYGEN_I2S_MCLK(data->h6 ? MCLK_256 : MCLK_512) |
OXYGEN_I2S_BITS_16 |
OXYGEN_I2S_MASTER |
OXYGEN_I2S_BCLK_64);
xonar_st_init_i2c(chip);
cs2000_registers_init(chip);
xonar_st_init_common(chip);
snd_component_add(chip->card, "CS2000");
}
static void xonar_stx_init(struct oxygen *chip)
{
struct xonar_pcm179x *data = chip->model_data;
xonar_st_init_i2c(chip);
data->generic.anti_pop_delay = 800;
data->generic.ext_power_reg = OXYGEN_GPI_DATA;
data->generic.ext_power_int_reg = OXYGEN_GPI_INTERRUPT_MASK;
data->generic.ext_power_bit = GPI_EXT_POWER;
xonar_init_ext_power(chip);
xonar_st_init_common(chip);
}
static void xonar_d2_cleanup(struct oxygen *chip)
{
xonar_disable_output(chip);
}
static void xonar_hdav_cleanup(struct oxygen *chip)
{
xonar_hdmi_cleanup(chip);
xonar_disable_output(chip);
msleep(2);
}
static void xonar_st_cleanup(struct oxygen *chip)
{
xonar_disable_output(chip);
}
static void xonar_d2_suspend(struct oxygen *chip)
{
xonar_d2_cleanup(chip);
}
static void xonar_hdav_suspend(struct oxygen *chip)
{
xonar_hdav_cleanup(chip);
}
static void xonar_st_suspend(struct oxygen *chip)
{
xonar_st_cleanup(chip);
}
static void xonar_d2_resume(struct oxygen *chip)
{
pcm1796_registers_init(chip);
xonar_enable_output(chip);
}
static void xonar_hdav_resume(struct oxygen *chip)
{
struct xonar_hdav *data = chip->model_data;
pcm1796_registers_init(chip);
xonar_hdmi_resume(chip, &data->hdmi);
xonar_enable_output(chip);
}
static void xonar_stx_resume(struct oxygen *chip)
{
pcm1796_registers_init(chip);
xonar_enable_output(chip);
}
static void xonar_st_resume(struct oxygen *chip)
{
cs2000_registers_init(chip);
xonar_stx_resume(chip);
}
static void update_pcm1796_oversampling(struct oxygen *chip)
{
struct xonar_pcm179x *data = chip->model_data;
unsigned int i;
u8 reg;
if (data->current_rate <= 48000 && !data->h6)
reg = PCM1796_OS_128;
else
reg = PCM1796_OS_64;
for (i = 0; i < data->dacs; ++i)
pcm1796_write_cached(chip, i, 20, reg);
}
static void set_pcm1796_params(struct oxygen *chip,
struct snd_pcm_hw_params *params)
{
struct xonar_pcm179x *data = chip->model_data;
msleep(1);
data->current_rate = params_rate(params);
update_pcm1796_oversampling(chip);
}
static void update_pcm1796_volume(struct oxygen *chip)
{
struct xonar_pcm179x *data = chip->model_data;
unsigned int i;
s8 gain_offset;
gain_offset = data->hp_active ? data->hp_gain_offset : 0;
for (i = 0; i < data->dacs; ++i) {
pcm1796_write_cached(chip, i, 16, chip->dac_volume[i * 2]
+ gain_offset);
pcm1796_write_cached(chip, i, 17, chip->dac_volume[i * 2 + 1]
+ gain_offset);
gain_offset = 0;
}
}
static void update_pcm1796_mute(struct oxygen *chip)
{
struct xonar_pcm179x *data = chip->model_data;
unsigned int i;
u8 value;
value = PCM1796_DMF_DISABLED | PCM1796_FMT_24_I2S | PCM1796_ATLD;
if (chip->dac_mute)
value |= PCM1796_MUTE;
for (i = 0; i < data->dacs; ++i)
pcm1796_write_cached(chip, i, 18, value);
}
static void update_cs2000_rate(struct oxygen *chip, unsigned int rate)
{
struct xonar_pcm179x *data = chip->model_data;
u8 rate_mclk, reg;
switch (rate) {
case 32000:
case 64000:
rate_mclk = OXYGEN_RATE_32000;
break;
case 44100:
case 88200:
case 176400:
rate_mclk = OXYGEN_RATE_44100;
break;
default:
case 48000:
case 96000:
case 192000:
rate_mclk = OXYGEN_RATE_48000;
break;
}
if (rate <= 96000 && (rate > 48000 || data->h6)) {
rate_mclk |= OXYGEN_I2S_MCLK(MCLK_256);
reg = CS2000_REF_CLK_DIV_1;
} else {
rate_mclk |= OXYGEN_I2S_MCLK(MCLK_512);
reg = CS2000_REF_CLK_DIV_2;
}
oxygen_write16_masked(chip, OXYGEN_I2S_A_FORMAT, rate_mclk,
OXYGEN_I2S_RATE_MASK | OXYGEN_I2S_MCLK_MASK);
cs2000_write_cached(chip, CS2000_FUN_CFG_1, reg);
msleep(3);
}
static void set_st_params(struct oxygen *chip,
struct snd_pcm_hw_params *params)
{
update_cs2000_rate(chip, params_rate(params));
set_pcm1796_params(chip, params);
}
static void set_hdav_params(struct oxygen *chip,
struct snd_pcm_hw_params *params)
{
struct xonar_hdav *data = chip->model_data;
set_pcm1796_params(chip, params);
xonar_set_hdmi_params(chip, &data->hdmi, params);
}
static int rolloff_info(struct snd_kcontrol *ctl,
struct snd_ctl_elem_info *info)
{
static const char *const names[2] = {
"Sharp Roll-off", "Slow Roll-off"
};
return snd_ctl_enum_info(info, 1, 2, names);
}
static int rolloff_get(struct snd_kcontrol *ctl,
struct snd_ctl_elem_value *value)
{
struct oxygen *chip = ctl->private_data;
struct xonar_pcm179x *data = chip->model_data;
value->value.enumerated.item[0] =
(data->pcm1796_regs[0][19 - PCM1796_REG_BASE] &
PCM1796_FLT_MASK) != PCM1796_FLT_SHARP;
return 0;
}
static int rolloff_put(struct snd_kcontrol *ctl,
struct snd_ctl_elem_value *value)
{
struct oxygen *chip = ctl->private_data;
struct xonar_pcm179x *data = chip->model_data;
unsigned int i;
int changed;
u8 reg;
mutex_lock(&chip->mutex);
reg = data->pcm1796_regs[0][19 - PCM1796_REG_BASE];
reg &= ~PCM1796_FLT_MASK;
if (!value->value.enumerated.item[0])
reg |= PCM1796_FLT_SHARP;
else
reg |= PCM1796_FLT_SLOW;
changed = reg != data->pcm1796_regs[0][19 - PCM1796_REG_BASE];
if (changed) {
for (i = 0; i < data->dacs; ++i)
pcm1796_write(chip, i, 19, reg);
}
mutex_unlock(&chip->mutex);
return changed;
}
static int st_output_switch_info(struct snd_kcontrol *ctl,
struct snd_ctl_elem_info *info)
{
static const char *const names[3] = {
"Speakers", "Headphones", "FP Headphones"
};
return snd_ctl_enum_info(info, 1, 3, names);
}
static int st_output_switch_get(struct snd_kcontrol *ctl,
struct snd_ctl_elem_value *value)
{
struct oxygen *chip = ctl->private_data;
u16 gpio;
gpio = oxygen_read16(chip, OXYGEN_GPIO_DATA);
if (!(gpio & GPIO_ST_HP))
value->value.enumerated.item[0] = 0;
else if (gpio & GPIO_ST_HP_REAR)
value->value.enumerated.item[0] = 1;
else
value->value.enumerated.item[0] = 2;
return 0;
}
static int st_output_switch_put(struct snd_kcontrol *ctl,
struct snd_ctl_elem_value *value)
{
struct oxygen *chip = ctl->private_data;
struct xonar_pcm179x *data = chip->model_data;
u16 gpio_old, gpio;
mutex_lock(&chip->mutex);
gpio_old = oxygen_read16(chip, OXYGEN_GPIO_DATA);
gpio = gpio_old;
switch (value->value.enumerated.item[0]) {
case 0:
gpio &= ~(GPIO_ST_HP | GPIO_ST_HP_REAR);
break;
case 1:
gpio |= GPIO_ST_HP | GPIO_ST_HP_REAR;
break;
case 2:
gpio = (gpio | GPIO_ST_HP) & ~GPIO_ST_HP_REAR;
break;
}
oxygen_write16(chip, OXYGEN_GPIO_DATA, gpio);
data->hp_active = gpio & GPIO_ST_HP;
update_pcm1796_volume(chip);
mutex_unlock(&chip->mutex);
return gpio != gpio_old;
}
static int st_hp_volume_offset_info(struct snd_kcontrol *ctl,
struct snd_ctl_elem_info *info)
{
static const char *const names[3] = {
"< 64 ohms", "64-300 ohms", "300-600 ohms"
};
return snd_ctl_enum_info(info, 1, 3, names);
}
static int st_hp_volume_offset_get(struct snd_kcontrol *ctl,
struct snd_ctl_elem_value *value)
{
struct oxygen *chip = ctl->private_data;
struct xonar_pcm179x *data = chip->model_data;
mutex_lock(&chip->mutex);
if (data->hp_gain_offset < 2*-6)
value->value.enumerated.item[0] = 0;
else if (data->hp_gain_offset < 0)
value->value.enumerated.item[0] = 1;
else
value->value.enumerated.item[0] = 2;
mutex_unlock(&chip->mutex);
return 0;
}
static int st_hp_volume_offset_put(struct snd_kcontrol *ctl,
struct snd_ctl_elem_value *value)
{
static const s8 offsets[] = { 2*-18, 2*-6, 0 };
struct oxygen *chip = ctl->private_data;
struct xonar_pcm179x *data = chip->model_data;
s8 offset;
int changed;
if (value->value.enumerated.item[0] > 2)
return -EINVAL;
offset = offsets[value->value.enumerated.item[0]];
mutex_lock(&chip->mutex);
changed = offset != data->hp_gain_offset;
if (changed) {
data->hp_gain_offset = offset;
update_pcm1796_volume(chip);
}
mutex_unlock(&chip->mutex);
return changed;
}
static void xonar_line_mic_ac97_switch(struct oxygen *chip,
unsigned int reg, unsigned int mute)
{
if (reg == AC97_LINE) {
spin_lock_irq(&chip->reg_lock);
oxygen_write16_masked(chip, OXYGEN_GPIO_DATA,
mute ? GPIO_INPUT_ROUTE : 0,
GPIO_INPUT_ROUTE);
spin_unlock_irq(&chip->reg_lock);
}
}
static int xonar_d2_control_filter(struct snd_kcontrol_new *template)
{
if (!strncmp(template->name, "CD Capture ", 11))
template->private_value ^= AC97_CD ^ AC97_VIDEO;
return 0;
}
static int xonar_st_h6_control_filter(struct snd_kcontrol_new *template)
{
if (!strncmp(template->name, "Master Playback ", 16))
return 1;
return 0;
}
static int add_pcm1796_controls(struct oxygen *chip)
{
struct xonar_pcm179x *data = chip->model_data;
int err;
if (!data->broken_i2c) {
err = snd_ctl_add(chip->card,
snd_ctl_new1(&rolloff_control, chip));
if (err < 0)
return err;
}
return 0;
}
static int xonar_d2_mixer_init(struct oxygen *chip)
{
int err;
err = snd_ctl_add(chip->card, snd_ctl_new1(&alt_switch, chip));
if (err < 0)
return err;
err = add_pcm1796_controls(chip);
if (err < 0)
return err;
return 0;
}
static int xonar_hdav_mixer_init(struct oxygen *chip)
{
int err;
err = snd_ctl_add(chip->card, snd_ctl_new1(&hdav_hdmi_control, chip));
if (err < 0)
return err;
err = add_pcm1796_controls(chip);
if (err < 0)
return err;
return 0;
}
static int xonar_st_mixer_init(struct oxygen *chip)
{
unsigned int i;
int err;
for (i = 0; i < ARRAY_SIZE(st_controls); ++i) {
err = snd_ctl_add(chip->card,
snd_ctl_new1(&st_controls[i], chip));
if (err < 0)
return err;
}
err = add_pcm1796_controls(chip);
if (err < 0)
return err;
return 0;
}
static void dump_pcm1796_registers(struct oxygen *chip,
struct snd_info_buffer *buffer)
{
struct xonar_pcm179x *data = chip->model_data;
unsigned int dac, i;
for (dac = 0; dac < data->dacs; ++dac) {
snd_iprintf(buffer, "\nPCM1796 %u:", dac + 1);
for (i = 0; i < 5; ++i)
snd_iprintf(buffer, " %02x",
data->pcm1796_regs[dac][i]);
}
snd_iprintf(buffer, "\n");
}
static void dump_cs2000_registers(struct oxygen *chip,
struct snd_info_buffer *buffer)
{
struct xonar_pcm179x *data = chip->model_data;
unsigned int i;
if (data->has_cs2000) {
snd_iprintf(buffer, "\nCS2000:\n00: ");
for (i = 1; i < 0x10; ++i)
snd_iprintf(buffer, " %02x", data->cs2000_regs[i]);
snd_iprintf(buffer, "\n10:");
for (i = 0x10; i < 0x1f; ++i)
snd_iprintf(buffer, " %02x", data->cs2000_regs[i]);
snd_iprintf(buffer, "\n");
}
}
static void dump_st_registers(struct oxygen *chip,
struct snd_info_buffer *buffer)
{
dump_pcm1796_registers(chip, buffer);
dump_cs2000_registers(chip, buffer);
}
int get_xonar_pcm179x_model(struct oxygen *chip,
const struct pci_device_id *id)
{
switch (id->subdevice) {
case 0x8269:
chip->model = model_xonar_d2;
chip->model.shortname = "Xonar D2";
break;
case 0x82b7:
chip->model = model_xonar_d2;
chip->model.shortname = "Xonar D2X";
chip->model.init = xonar_d2x_init;
break;
case 0x8314:
chip->model = model_xonar_hdav;
oxygen_clear_bits16(chip, OXYGEN_GPIO_CONTROL, GPIO_DB_MASK);
switch (oxygen_read16(chip, OXYGEN_GPIO_DATA) & GPIO_DB_MASK) {
default:
chip->model.shortname = "Xonar HDAV1.3";
break;
case GPIO_DB_H6:
chip->model.shortname = "Xonar HDAV1.3+H6";
chip->model.dac_channels_mixer = 8;
chip->model.dac_mclks = OXYGEN_MCLKS(256, 128, 128);
break;
}
break;
case 0x835d:
chip->model = model_xonar_st;
oxygen_clear_bits16(chip, OXYGEN_GPIO_CONTROL, GPIO_DB_MASK);
switch (oxygen_read16(chip, OXYGEN_GPIO_DATA) & GPIO_DB_MASK) {
default:
chip->model.shortname = "Xonar ST";
break;
case GPIO_DB_H6:
chip->model.shortname = "Xonar ST+H6";
chip->model.control_filter = xonar_st_h6_control_filter;
chip->model.dac_channels_pcm = 8;
chip->model.dac_channels_mixer = 8;
chip->model.dac_volume_min = 255;
chip->model.dac_mclks = OXYGEN_MCLKS(256, 128, 128);
break;
}
break;
case 0x835c:
chip->model = model_xonar_st;
chip->model.shortname = "Xonar STX";
chip->model.init = xonar_stx_init;
chip->model.resume = xonar_stx_resume;
chip->model.set_dac_params = set_pcm1796_params;
break;
default:
return -EINVAL;
}
return 0;
}
