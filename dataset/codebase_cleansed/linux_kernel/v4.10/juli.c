static int get_gpio_val(int rate)
{
int i;
for (i = 0; i < ARRAY_SIZE(juli_rates); i++)
if (juli_rates[i] == rate)
return gpio_vals[i];
return 0;
}
static void juli_ak4114_write(void *private_data, unsigned char reg,
unsigned char val)
{
snd_vt1724_write_i2c((struct snd_ice1712 *)private_data, AK4114_ADDR,
reg, val);
}
static unsigned char juli_ak4114_read(void *private_data, unsigned char reg)
{
return snd_vt1724_read_i2c((struct snd_ice1712 *)private_data,
AK4114_ADDR, reg);
}
static void juli_spdif_in_open(struct snd_ice1712 *ice,
struct snd_pcm_substream *substream)
{
struct juli_spec *spec = ice->spec;
struct snd_pcm_runtime *runtime = substream->runtime;
int rate;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK ||
!ice->is_spdif_master(ice))
return;
rate = snd_ak4114_external_rate(spec->ak4114);
if (rate >= runtime->hw.rate_min && rate <= runtime->hw.rate_max) {
runtime->hw.rate_min = rate;
runtime->hw.rate_max = rate;
}
}
static void juli_akm_lock(struct snd_akm4xxx *ak, int chip)
{
}
static void juli_akm_unlock(struct snd_akm4xxx *ak, int chip)
{
}
static void juli_akm_write(struct snd_akm4xxx *ak, int chip,
unsigned char addr, unsigned char data)
{
struct snd_ice1712 *ice = ak->private_data[0];
if (snd_BUG_ON(chip))
return;
snd_vt1724_write_i2c(ice, AK4358_ADDR, addr, data);
}
static void juli_akm_set_rate_val(struct snd_akm4xxx *ak, unsigned int rate)
{
unsigned char old, tmp, ak4358_dfs;
unsigned int ak5385_pins, old_gpio, new_gpio;
struct snd_ice1712 *ice = ak->private_data[0];
struct juli_spec *spec = ice->spec;
if (rate == 0)
return;
if (rate > 96000) {
ak4358_dfs = 2;
ak5385_pins = GPIO_AK5385A_DFS1 | GPIO_AK5385A_CKS0;
} else if (rate > 48000) {
ak4358_dfs = 1;
ak5385_pins = GPIO_AK5385A_DFS0;
} else {
ak4358_dfs = 0;
ak5385_pins = 0;
}
old_gpio = ice->gpio.get_data(ice);
new_gpio = (old_gpio & ~GPIO_AK5385A_MASK) | ak5385_pins;
ice->gpio.set_data(ice, new_gpio);
old = inb(ICEMT1724(ice, AC97_CMD));
outb(old | VT1724_AC97_COLD, ICEMT1724(ice, AC97_CMD));
udelay(1);
outb(old & ~VT1724_AC97_COLD, ICEMT1724(ice, AC97_CMD));
tmp = snd_akm4xxx_get(ak, 0, 2);
snd_akm4xxx_reset(ak, 1);
tmp = snd_akm4xxx_get(ak, 0, 2);
tmp &= ~(0x03 << 4);
tmp |= ak4358_dfs << 4;
snd_akm4xxx_set(ak, 0, 2, tmp);
snd_akm4xxx_reset(ak, 0);
snd_ak4114_reinit(spec->ak4114);
}
static int juli_mute_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned int val;
val = ice->gpio.get_data(ice) & (unsigned int) kcontrol->private_value;
if (kcontrol->private_value == GPIO_MUTE_CONTROL)
ucontrol->value.integer.value[0] = (val) ? 0 : 1;
else
ucontrol->value.integer.value[0] = (val) ? 1 : 0;
return 0;
}
static int juli_mute_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned int old_gpio, new_gpio;
old_gpio = ice->gpio.get_data(ice);
if (ucontrol->value.integer.value[0]) {
if (kcontrol->private_value == GPIO_MUTE_CONTROL) {
new_gpio = old_gpio & ~GPIO_MUTE_CONTROL;
snd_akm4xxx_write(ice->akm, 0, 0x01, 0x01);
} else
new_gpio = old_gpio |
(unsigned int) kcontrol->private_value;
} else {
if (kcontrol->private_value == GPIO_MUTE_CONTROL) {
new_gpio = old_gpio | GPIO_MUTE_CONTROL;
snd_akm4xxx_write(ice->akm, 0, 0x01, 0x03);
} else
new_gpio = old_gpio &
~((unsigned int) kcontrol->private_value);
}
if (old_gpio != new_gpio) {
ice->gpio.set_data(ice, new_gpio);
return 1;
}
return 0;
}
static struct snd_kcontrol *ctl_find(struct snd_card *card,
const char *name)
{
struct snd_ctl_elem_id sid;
memset(&sid, 0, sizeof(sid));
strcpy(sid.name, name);
sid.iface = SNDRV_CTL_ELEM_IFACE_MIXER;
return snd_ctl_find_id(card, &sid);
}
static void add_slaves(struct snd_card *card,
struct snd_kcontrol *master,
char * const *list)
{
for (; *list; list++) {
struct snd_kcontrol *slave = ctl_find(card, *list);
if (slave) {
snd_ctl_add_slave(master, slave);
}
}
}
static int juli_add_controls(struct snd_ice1712 *ice)
{
struct juli_spec *spec = ice->spec;
int err;
unsigned int i;
struct snd_kcontrol *vmaster;
err = snd_ice1712_akm4xxx_build_controls(ice);
if (err < 0)
return err;
for (i = 0; i < ARRAY_SIZE(juli_mute_controls); i++) {
err = snd_ctl_add(ice->card,
snd_ctl_new1(&juli_mute_controls[i], ice));
if (err < 0)
return err;
}
vmaster = snd_ctl_make_virtual_master("Master Playback Volume",
juli_master_db_scale);
if (!vmaster)
return -ENOMEM;
add_slaves(ice->card, vmaster, slave_vols);
err = snd_ctl_add(ice->card, vmaster);
if (err < 0)
return err;
return snd_ak4114_build(spec->ak4114, NULL,
ice->pcm->streams[SNDRV_PCM_STREAM_CAPTURE].substream);
}
static int juli_resume(struct snd_ice1712 *ice)
{
struct snd_akm4xxx *ak = ice->akm;
struct juli_spec *spec = ice->spec;
snd_akm4xxx_reset(ak, 0);
snd_ak4114_resume(spec->ak4114);
return 0;
}
static int juli_suspend(struct snd_ice1712 *ice)
{
struct snd_akm4xxx *ak = ice->akm;
struct juli_spec *spec = ice->spec;
snd_akm4xxx_reset(ak, 1);
snd_ak4114_suspend(spec->ak4114);
return 0;
}
static inline int juli_is_spdif_master(struct snd_ice1712 *ice)
{
return (ice->gpio.get_data(ice) & GPIO_INTERNAL_CLOCK) ? 0 : 1;
}
static unsigned int juli_get_rate(struct snd_ice1712 *ice)
{
int i;
unsigned char result;
result = ice->gpio.get_data(ice) & GPIO_RATE_MASK;
for (i = 0; i < ARRAY_SIZE(gpio_vals); i++)
if (gpio_vals[i] == result)
return juli_rates[i];
return 0;
}
static void juli_set_rate(struct snd_ice1712 *ice, unsigned int rate)
{
unsigned int old, new;
unsigned char val;
old = ice->gpio.get_data(ice);
new = (old & ~GPIO_RATE_MASK) | get_gpio_val(rate);
ice->gpio.set_data(ice, new);
val = inb(ICEMT1724(ice, RATE));
outb(val | VT1724_SPDIF_MASTER, ICEMT1724(ice, RATE));
}
static inline unsigned char juli_set_mclk(struct snd_ice1712 *ice,
unsigned int rate)
{
return 0;
}
static int juli_set_spdif_clock(struct snd_ice1712 *ice, int type)
{
unsigned int old;
old = ice->gpio.get_data(ice);
ice->gpio.set_data(ice, (old & ~GPIO_RATE_MASK) | GPIO_MULTI_1X |
GPIO_FREQ_48KHZ);
return 0;
}
static void juli_ak4114_change(struct ak4114 *ak4114, unsigned char c0,
unsigned char c1)
{
struct snd_ice1712 *ice = ak4114->change_callback_private;
int rate;
if (ice->is_spdif_master(ice) && c1) {
rate = snd_ak4114_external_rate(ak4114);
juli_akm_set_rate_val(ice->akm, rate);
}
}
static int juli_init(struct snd_ice1712 *ice)
{
static const unsigned char ak4114_init_vals[] = {
AK4114_RST | AK4114_PWN |
AK4114_OCKS0 | AK4114_OCKS1,
AK4114_DIF_I24I2S,
AK4114_TX1E,
AK4114_EFH_1024 | AK4114_DIT |
AK4114_IPS(1),
0,
0
};
static const unsigned char ak4114_init_txcsb[] = {
0x41, 0x02, 0x2c, 0x00, 0x00
};
int err;
struct juli_spec *spec;
struct snd_akm4xxx *ak;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (!spec)
return -ENOMEM;
ice->spec = spec;
err = snd_ak4114_create(ice->card,
juli_ak4114_read,
juli_ak4114_write,
ak4114_init_vals, ak4114_init_txcsb,
ice, &spec->ak4114);
if (err < 0)
return err;
spec->ak4114->change_callback = juli_ak4114_change;
spec->ak4114->change_callback_private = ice;
spec->ak4114->check_flags = 0;
#if 0
spec->analog = (ice->gpio.get_data(ice) & GPIO_ANALOG_PRESENT) ? 0 : 1;
#else
spec->analog = 1;
#endif
if (spec->analog) {
dev_info(ice->card->dev, "juli@: analog I/O detected\n");
ice->num_total_dacs = 2;
ice->num_total_adcs = 2;
ice->akm = kzalloc(sizeof(struct snd_akm4xxx), GFP_KERNEL);
ak = ice->akm;
if (!ak)
return -ENOMEM;
ice->akm_codecs = 1;
err = snd_ice1712_akm4xxx_init(ak, &akm_juli_dac, NULL, ice);
if (err < 0)
return err;
}
ice->hw_rates = &juli_rates_info;
ice->is_spdif_master = juli_is_spdif_master;
ice->get_rate = juli_get_rate;
ice->set_rate = juli_set_rate;
ice->set_mclk = juli_set_mclk;
ice->set_spdif_clock = juli_set_spdif_clock;
ice->spdif.ops.open = juli_spdif_in_open;
#ifdef CONFIG_PM_SLEEP
ice->pm_resume = juli_resume;
ice->pm_suspend = juli_suspend;
ice->pm_suspend_enabled = 1;
#endif
return 0;
}
