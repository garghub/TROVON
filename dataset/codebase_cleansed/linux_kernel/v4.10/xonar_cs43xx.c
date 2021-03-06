static void cs4398_write(struct oxygen *chip, u8 reg, u8 value)
{
struct xonar_cs43xx *data = chip->model_data;
oxygen_write_i2c(chip, I2C_DEVICE_CS4398, reg, value);
if (reg < ARRAY_SIZE(data->cs4398_regs))
data->cs4398_regs[reg] = value;
}
static void cs4398_write_cached(struct oxygen *chip, u8 reg, u8 value)
{
struct xonar_cs43xx *data = chip->model_data;
if (value != data->cs4398_regs[reg])
cs4398_write(chip, reg, value);
}
static void cs4362a_write(struct oxygen *chip, u8 reg, u8 value)
{
struct xonar_cs43xx *data = chip->model_data;
oxygen_write_i2c(chip, I2C_DEVICE_CS4362A, reg, value);
if (reg < ARRAY_SIZE(data->cs4362a_regs))
data->cs4362a_regs[reg] = value;
}
static void cs4362a_write_cached(struct oxygen *chip, u8 reg, u8 value)
{
struct xonar_cs43xx *data = chip->model_data;
if (value != data->cs4362a_regs[reg])
cs4362a_write(chip, reg, value);
}
static void cs43xx_registers_init(struct oxygen *chip)
{
struct xonar_cs43xx *data = chip->model_data;
unsigned int i;
cs4398_write(chip, 8, CS4398_CPEN | CS4398_PDN);
cs4362a_write(chip, 0x01, CS4362A_PDN | CS4362A_CPEN);
cs4398_write(chip, 2, data->cs4398_regs[2]);
cs4398_write(chip, 3, CS4398_ATAPI_B_R | CS4398_ATAPI_A_L);
cs4398_write(chip, 4, data->cs4398_regs[4]);
cs4398_write(chip, 5, data->cs4398_regs[5]);
cs4398_write(chip, 6, data->cs4398_regs[6]);
cs4398_write(chip, 7, data->cs4398_regs[7]);
cs4362a_write(chip, 0x02, CS4362A_DIF_LJUST);
cs4362a_write(chip, 0x03, CS4362A_MUTEC_6 | CS4362A_AMUTE |
CS4362A_RMP_UP | CS4362A_ZERO_CROSS | CS4362A_SOFT_RAMP);
cs4362a_write(chip, 0x04, data->cs4362a_regs[0x04]);
cs4362a_write(chip, 0x05, 0);
for (i = 6; i <= 14; ++i)
cs4362a_write(chip, i, data->cs4362a_regs[i]);
cs4398_write(chip, 8, CS4398_CPEN);
cs4362a_write(chip, 0x01, CS4362A_CPEN);
}
static void xonar_d1_init(struct oxygen *chip)
{
struct xonar_cs43xx *data = chip->model_data;
data->generic.anti_pop_delay = 800;
data->generic.output_enable_bit = GPIO_D1_OUTPUT_ENABLE;
data->cs4398_regs[2] =
CS4398_FM_SINGLE | CS4398_DEM_NONE | CS4398_DIF_LJUST;
data->cs4398_regs[4] = CS4398_MUTEP_LOW |
CS4398_MUTE_B | CS4398_MUTE_A | CS4398_PAMUTE;
data->cs4398_regs[5] = 60 * 2;
data->cs4398_regs[6] = 60 * 2;
data->cs4398_regs[7] = CS4398_RMP_DN | CS4398_RMP_UP |
CS4398_ZERO_CROSS | CS4398_SOFT_RAMP;
data->cs4362a_regs[4] = CS4362A_RMP_DN | CS4362A_DEM_NONE;
data->cs4362a_regs[6] = CS4362A_FM_SINGLE |
CS4362A_ATAPI_B_R | CS4362A_ATAPI_A_L;
data->cs4362a_regs[7] = 60 | CS4362A_MUTE;
data->cs4362a_regs[8] = 60 | CS4362A_MUTE;
data->cs4362a_regs[9] = data->cs4362a_regs[6];
data->cs4362a_regs[10] = 60 | CS4362A_MUTE;
data->cs4362a_regs[11] = 60 | CS4362A_MUTE;
data->cs4362a_regs[12] = data->cs4362a_regs[6];
data->cs4362a_regs[13] = 60 | CS4362A_MUTE;
data->cs4362a_regs[14] = 60 | CS4362A_MUTE;
oxygen_write16(chip, OXYGEN_2WIRE_BUS_STATUS,
OXYGEN_2WIRE_LENGTH_8 |
OXYGEN_2WIRE_INTERRUPT_MASK |
OXYGEN_2WIRE_SPEED_FAST);
cs43xx_registers_init(chip);
oxygen_set_bits16(chip, OXYGEN_GPIO_CONTROL,
GPIO_D1_FRONT_PANEL |
GPIO_D1_MAGIC |
GPIO_D1_INPUT_ROUTE);
oxygen_clear_bits16(chip, OXYGEN_GPIO_DATA,
GPIO_D1_FRONT_PANEL | GPIO_D1_INPUT_ROUTE);
xonar_init_cs53x1(chip);
xonar_enable_output(chip);
snd_component_add(chip->card, "CS4398");
snd_component_add(chip->card, "CS4362A");
snd_component_add(chip->card, "CS5361");
}
static void xonar_dx_init(struct oxygen *chip)
{
struct xonar_cs43xx *data = chip->model_data;
data->generic.ext_power_reg = OXYGEN_GPI_DATA;
data->generic.ext_power_int_reg = OXYGEN_GPI_INTERRUPT_MASK;
data->generic.ext_power_bit = GPI_EXT_POWER;
xonar_init_ext_power(chip);
xonar_d1_init(chip);
}
static void xonar_d1_cleanup(struct oxygen *chip)
{
xonar_disable_output(chip);
cs4362a_write(chip, 0x01, CS4362A_PDN | CS4362A_CPEN);
oxygen_clear_bits8(chip, OXYGEN_FUNCTION, OXYGEN_FUNCTION_RESET_CODEC);
}
static void xonar_d1_suspend(struct oxygen *chip)
{
xonar_d1_cleanup(chip);
}
static void xonar_d1_resume(struct oxygen *chip)
{
oxygen_set_bits8(chip, OXYGEN_FUNCTION, OXYGEN_FUNCTION_RESET_CODEC);
msleep(1);
cs43xx_registers_init(chip);
xonar_enable_output(chip);
}
static void set_cs43xx_params(struct oxygen *chip,
struct snd_pcm_hw_params *params)
{
struct xonar_cs43xx *data = chip->model_data;
u8 cs4398_fm, cs4362a_fm;
if (params_rate(params) <= 50000) {
cs4398_fm = CS4398_FM_SINGLE;
cs4362a_fm = CS4362A_FM_SINGLE;
} else if (params_rate(params) <= 100000) {
cs4398_fm = CS4398_FM_DOUBLE;
cs4362a_fm = CS4362A_FM_DOUBLE;
} else {
cs4398_fm = CS4398_FM_QUAD;
cs4362a_fm = CS4362A_FM_QUAD;
}
cs4398_fm |= CS4398_DEM_NONE | CS4398_DIF_LJUST;
cs4398_write_cached(chip, 2, cs4398_fm);
cs4362a_fm |= data->cs4362a_regs[6] & ~CS4362A_FM_MASK;
cs4362a_write_cached(chip, 6, cs4362a_fm);
cs4362a_write_cached(chip, 12, cs4362a_fm);
cs4362a_fm &= CS4362A_FM_MASK;
cs4362a_fm |= data->cs4362a_regs[9] & ~CS4362A_FM_MASK;
cs4362a_write_cached(chip, 9, cs4362a_fm);
}
static void update_cs4362a_volumes(struct oxygen *chip)
{
unsigned int i;
u8 mute;
mute = chip->dac_mute ? CS4362A_MUTE : 0;
for (i = 0; i < 6; ++i)
cs4362a_write_cached(chip, 7 + i + i / 2,
(127 - chip->dac_volume[2 + i]) | mute);
}
static void update_cs43xx_volume(struct oxygen *chip)
{
cs4398_write_cached(chip, 5, (127 - chip->dac_volume[0]) * 2);
cs4398_write_cached(chip, 6, (127 - chip->dac_volume[1]) * 2);
update_cs4362a_volumes(chip);
}
static void update_cs43xx_mute(struct oxygen *chip)
{
u8 reg;
reg = CS4398_MUTEP_LOW | CS4398_PAMUTE;
if (chip->dac_mute)
reg |= CS4398_MUTE_B | CS4398_MUTE_A;
cs4398_write_cached(chip, 4, reg);
update_cs4362a_volumes(chip);
}
static void update_cs43xx_center_lfe_mix(struct oxygen *chip, bool mixed)
{
struct xonar_cs43xx *data = chip->model_data;
u8 reg;
reg = data->cs4362a_regs[9] & ~CS4362A_ATAPI_MASK;
if (mixed)
reg |= CS4362A_ATAPI_B_LR | CS4362A_ATAPI_A_LR;
else
reg |= CS4362A_ATAPI_B_R | CS4362A_ATAPI_A_L;
cs4362a_write_cached(chip, 9, reg);
}
static int rolloff_info(struct snd_kcontrol *ctl,
struct snd_ctl_elem_info *info)
{
static const char *const names[2] = {
"Fast Roll-off", "Slow Roll-off"
};
return snd_ctl_enum_info(info, 1, 2, names);
}
static int rolloff_get(struct snd_kcontrol *ctl,
struct snd_ctl_elem_value *value)
{
struct oxygen *chip = ctl->private_data;
struct xonar_cs43xx *data = chip->model_data;
value->value.enumerated.item[0] =
(data->cs4398_regs[7] & CS4398_FILT_SEL) != 0;
return 0;
}
static int rolloff_put(struct snd_kcontrol *ctl,
struct snd_ctl_elem_value *value)
{
struct oxygen *chip = ctl->private_data;
struct xonar_cs43xx *data = chip->model_data;
int changed;
u8 reg;
mutex_lock(&chip->mutex);
reg = data->cs4398_regs[7];
if (value->value.enumerated.item[0])
reg |= CS4398_FILT_SEL;
else
reg &= ~CS4398_FILT_SEL;
changed = reg != data->cs4398_regs[7];
if (changed) {
cs4398_write(chip, 7, reg);
if (reg & CS4398_FILT_SEL)
reg = data->cs4362a_regs[0x04] | CS4362A_FILT_SEL;
else
reg = data->cs4362a_regs[0x04] & ~CS4362A_FILT_SEL;
cs4362a_write(chip, 0x04, reg);
}
mutex_unlock(&chip->mutex);
return changed;
}
static void xonar_d1_line_mic_ac97_switch(struct oxygen *chip,
unsigned int reg, unsigned int mute)
{
if (reg == AC97_LINE) {
spin_lock_irq(&chip->reg_lock);
oxygen_write16_masked(chip, OXYGEN_GPIO_DATA,
mute ? GPIO_D1_INPUT_ROUTE : 0,
GPIO_D1_INPUT_ROUTE);
spin_unlock_irq(&chip->reg_lock);
}
}
static int xonar_d1_mixer_init(struct oxygen *chip)
{
int err;
err = snd_ctl_add(chip->card, snd_ctl_new1(&front_panel_switch, chip));
if (err < 0)
return err;
err = snd_ctl_add(chip->card, snd_ctl_new1(&rolloff_control, chip));
if (err < 0)
return err;
return 0;
}
static void dump_cs4362a_registers(struct xonar_cs43xx *data,
struct snd_info_buffer *buffer)
{
unsigned int i;
snd_iprintf(buffer, "\nCS4362A:");
for (i = 1; i <= 14; ++i)
snd_iprintf(buffer, " %02x", data->cs4362a_regs[i]);
snd_iprintf(buffer, "\n");
}
static void dump_d1_registers(struct oxygen *chip,
struct snd_info_buffer *buffer)
{
struct xonar_cs43xx *data = chip->model_data;
unsigned int i;
snd_iprintf(buffer, "\nCS4398: 7?");
for (i = 2; i < 8; ++i)
snd_iprintf(buffer, " %02x", data->cs4398_regs[i]);
snd_iprintf(buffer, "\n");
dump_cs4362a_registers(data, buffer);
}
int get_xonar_cs43xx_model(struct oxygen *chip,
const struct pci_device_id *id)
{
switch (id->subdevice) {
case 0x834f:
chip->model = model_xonar_d1;
chip->model.shortname = "Xonar D1";
break;
case 0x8275:
case 0x8327:
chip->model = model_xonar_d1;
chip->model.shortname = "Xonar DX";
chip->model.init = xonar_dx_init;
break;
default:
return -EINVAL;
}
return 0;
}
