static int daca_init_client(struct pmac_keywest *i2c)
{
unsigned short wdata = 0x00;
if (i2c_smbus_write_byte_data(i2c->client, DACA_REG_SR, 0x08) < 0 ||
i2c_smbus_write_byte_data(i2c->client, DACA_REG_GCFG, 0x05) < 0)
return -EINVAL;
return i2c_smbus_write_block_data(i2c->client, DACA_REG_AVOL,
2, (unsigned char*)&wdata);
}
static int daca_set_volume(struct pmac_daca *mix)
{
unsigned char data[2];
if (! mix->i2c.client)
return -ENODEV;
if (mix->left_vol > DACA_VOL_MAX)
data[0] = DACA_VOL_MAX;
else
data[0] = mix->left_vol;
if (mix->right_vol > DACA_VOL_MAX)
data[1] = DACA_VOL_MAX;
else
data[1] = mix->right_vol;
data[1] |= mix->deemphasis ? 0x40 : 0;
if (i2c_smbus_write_block_data(mix->i2c.client, DACA_REG_AVOL,
2, data) < 0) {
snd_printk(KERN_ERR "failed to set volume \n");
return -EINVAL;
}
return 0;
}
static int daca_get_deemphasis(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_pmac *chip = snd_kcontrol_chip(kcontrol);
struct pmac_daca *mix;
if (! (mix = chip->mixer_data))
return -ENODEV;
ucontrol->value.integer.value[0] = mix->deemphasis ? 1 : 0;
return 0;
}
static int daca_put_deemphasis(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_pmac *chip = snd_kcontrol_chip(kcontrol);
struct pmac_daca *mix;
int change;
if (! (mix = chip->mixer_data))
return -ENODEV;
change = mix->deemphasis != ucontrol->value.integer.value[0];
if (change) {
mix->deemphasis = !!ucontrol->value.integer.value[0];
daca_set_volume(mix);
}
return change;
}
static int daca_info_volume(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 2;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = DACA_VOL_MAX;
return 0;
}
static int daca_get_volume(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_pmac *chip = snd_kcontrol_chip(kcontrol);
struct pmac_daca *mix;
if (! (mix = chip->mixer_data))
return -ENODEV;
ucontrol->value.integer.value[0] = mix->left_vol;
ucontrol->value.integer.value[1] = mix->right_vol;
return 0;
}
static int daca_put_volume(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_pmac *chip = snd_kcontrol_chip(kcontrol);
struct pmac_daca *mix;
unsigned int vol[2];
int change;
if (! (mix = chip->mixer_data))
return -ENODEV;
vol[0] = ucontrol->value.integer.value[0];
vol[1] = ucontrol->value.integer.value[1];
if (vol[0] > DACA_VOL_MAX || vol[1] > DACA_VOL_MAX)
return -EINVAL;
change = mix->left_vol != vol[0] ||
mix->right_vol != vol[1];
if (change) {
mix->left_vol = vol[0];
mix->right_vol = vol[1];
daca_set_volume(mix);
}
return change;
}
static int daca_get_amp(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_pmac *chip = snd_kcontrol_chip(kcontrol);
struct pmac_daca *mix;
if (! (mix = chip->mixer_data))
return -ENODEV;
ucontrol->value.integer.value[0] = mix->amp_on ? 1 : 0;
return 0;
}
static int daca_put_amp(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_pmac *chip = snd_kcontrol_chip(kcontrol);
struct pmac_daca *mix;
int change;
if (! (mix = chip->mixer_data))
return -ENODEV;
change = mix->amp_on != ucontrol->value.integer.value[0];
if (change) {
mix->amp_on = !!ucontrol->value.integer.value[0];
i2c_smbus_write_byte_data(mix->i2c.client, DACA_REG_GCFG,
mix->amp_on ? 0x05 : 0x04);
}
return change;
}
static void daca_resume(struct snd_pmac *chip)
{
struct pmac_daca *mix = chip->mixer_data;
i2c_smbus_write_byte_data(mix->i2c.client, DACA_REG_SR, 0x08);
i2c_smbus_write_byte_data(mix->i2c.client, DACA_REG_GCFG,
mix->amp_on ? 0x05 : 0x04);
daca_set_volume(mix);
}
static void daca_cleanup(struct snd_pmac *chip)
{
struct pmac_daca *mix = chip->mixer_data;
if (! mix)
return;
snd_pmac_keywest_cleanup(&mix->i2c);
kfree(mix);
chip->mixer_data = NULL;
}
int snd_pmac_daca_init(struct snd_pmac *chip)
{
int i, err;
struct pmac_daca *mix;
request_module("i2c-powermac");
mix = kzalloc(sizeof(*mix), GFP_KERNEL);
if (! mix)
return -ENOMEM;
chip->mixer_data = mix;
chip->mixer_free = daca_cleanup;
mix->amp_on = 1;
mix->i2c.addr = DACA_I2C_ADDR;
mix->i2c.init_client = daca_init_client;
mix->i2c.name = "DACA";
if ((err = snd_pmac_keywest_init(&mix->i2c)) < 0)
return err;
strcpy(chip->card->mixername, "PowerMac DACA");
for (i = 0; i < ARRAY_SIZE(daca_mixers); i++) {
if ((err = snd_ctl_add(chip->card, snd_ctl_new1(&daca_mixers[i], chip))) < 0)
return err;
}
#ifdef CONFIG_PM
chip->resume = daca_resume;
#endif
return 0;
}
