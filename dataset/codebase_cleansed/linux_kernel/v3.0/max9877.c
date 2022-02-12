static void max9877_write_regs(void)
{
unsigned int i;
u8 data[6];
data[0] = MAX9877_INPUT_MODE;
for (i = 0; i < ARRAY_SIZE(max9877_regs); i++)
data[i + 1] = max9877_regs[i];
if (i2c_master_send(i2c, data, 6) != 6)
dev_err(&i2c->dev, "i2c write failed\n");
}
static int max9877_get_reg(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct soc_mixer_control *mc =
(struct soc_mixer_control *)kcontrol->private_value;
unsigned int reg = mc->reg;
unsigned int shift = mc->shift;
unsigned int mask = mc->max;
unsigned int invert = mc->invert;
ucontrol->value.integer.value[0] = (max9877_regs[reg] >> shift) & mask;
if (invert)
ucontrol->value.integer.value[0] =
mask - ucontrol->value.integer.value[0];
return 0;
}
static int max9877_set_reg(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct soc_mixer_control *mc =
(struct soc_mixer_control *)kcontrol->private_value;
unsigned int reg = mc->reg;
unsigned int shift = mc->shift;
unsigned int mask = mc->max;
unsigned int invert = mc->invert;
unsigned int val = (ucontrol->value.integer.value[0] & mask);
if (invert)
val = mask - val;
if (((max9877_regs[reg] >> shift) & mask) == val)
return 0;
max9877_regs[reg] &= ~(mask << shift);
max9877_regs[reg] |= val << shift;
max9877_write_regs();
return 1;
}
static int max9877_get_2reg(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct soc_mixer_control *mc =
(struct soc_mixer_control *)kcontrol->private_value;
unsigned int reg = mc->reg;
unsigned int reg2 = mc->rreg;
unsigned int shift = mc->shift;
unsigned int mask = mc->max;
ucontrol->value.integer.value[0] = (max9877_regs[reg] >> shift) & mask;
ucontrol->value.integer.value[1] = (max9877_regs[reg2] >> shift) & mask;
return 0;
}
static int max9877_set_2reg(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct soc_mixer_control *mc =
(struct soc_mixer_control *)kcontrol->private_value;
unsigned int reg = mc->reg;
unsigned int reg2 = mc->rreg;
unsigned int shift = mc->shift;
unsigned int mask = mc->max;
unsigned int val = (ucontrol->value.integer.value[0] & mask);
unsigned int val2 = (ucontrol->value.integer.value[1] & mask);
unsigned int change = 1;
if (((max9877_regs[reg] >> shift) & mask) == val)
change = 0;
if (((max9877_regs[reg2] >> shift) & mask) == val2)
change = 0;
if (change) {
max9877_regs[reg] &= ~(mask << shift);
max9877_regs[reg] |= val << shift;
max9877_regs[reg2] &= ~(mask << shift);
max9877_regs[reg2] |= val2 << shift;
max9877_write_regs();
}
return change;
}
static int max9877_get_out_mode(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
u8 value = max9877_regs[MAX9877_OUTPUT_MODE] & MAX9877_OUTMODE_MASK;
if (value)
value -= 1;
ucontrol->value.integer.value[0] = value;
return 0;
}
static int max9877_set_out_mode(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
u8 value = ucontrol->value.integer.value[0];
value += 1;
if ((max9877_regs[MAX9877_OUTPUT_MODE] & MAX9877_OUTMODE_MASK) == value)
return 0;
max9877_regs[MAX9877_OUTPUT_MODE] &= ~MAX9877_OUTMODE_MASK;
max9877_regs[MAX9877_OUTPUT_MODE] |= value;
max9877_write_regs();
return 1;
}
static int max9877_get_osc_mode(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
u8 value = (max9877_regs[MAX9877_OUTPUT_MODE] & MAX9877_OSC_MASK);
value = value >> MAX9877_OSC_OFFSET;
ucontrol->value.integer.value[0] = value;
return 0;
}
static int max9877_set_osc_mode(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
u8 value = ucontrol->value.integer.value[0];
value = value << MAX9877_OSC_OFFSET;
if ((max9877_regs[MAX9877_OUTPUT_MODE] & MAX9877_OSC_MASK) == value)
return 0;
max9877_regs[MAX9877_OUTPUT_MODE] &= ~MAX9877_OSC_MASK;
max9877_regs[MAX9877_OUTPUT_MODE] |= value;
max9877_write_regs();
return 1;
}
int max9877_add_controls(struct snd_soc_codec *codec)
{
return snd_soc_add_controls(codec, max9877_controls,
ARRAY_SIZE(max9877_controls));
}
static int __devinit max9877_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
i2c = client;
max9877_write_regs();
return 0;
}
static __devexit int max9877_i2c_remove(struct i2c_client *client)
{
i2c = NULL;
return 0;
}
static int __init max9877_init(void)
{
return i2c_add_driver(&max9877_i2c_driver);
}
static void __exit max9877_exit(void)
{
i2c_del_driver(&max9877_i2c_driver);
}
