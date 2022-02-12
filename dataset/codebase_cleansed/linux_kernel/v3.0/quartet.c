static char *get_binary(char *buffer, int value)
{
int i, j, pos;
pos = 0;
for (i = 0; i < 4; ++i) {
for (j = 0; j < 8; ++j) {
if (value & (1 << (31-(i*8 + j))))
buffer[pos] = '1';
else
buffer[pos] = '0';
pos++;
}
if (i < 3) {
buffer[pos] = ' ';
pos++;
}
}
buffer[pos] = '\0';
return buffer;
}
static void qtet_ak4113_write(void *private_data, unsigned char reg,
unsigned char val)
{
snd_vt1724_write_i2c((struct snd_ice1712 *)private_data, AK4113_ADDR,
reg, val);
}
static unsigned char qtet_ak4113_read(void *private_data, unsigned char reg)
{
return snd_vt1724_read_i2c((struct snd_ice1712 *)private_data,
AK4113_ADDR, reg);
}
static void qtet_akm_write(struct snd_akm4xxx *ak, int chip,
unsigned char addr, unsigned char data)
{
unsigned int tmp, orig_dir;
int idx;
unsigned int addrdata;
struct snd_ice1712 *ice = ak->private_data[0];
if (snd_BUG_ON(chip < 0 || chip >= 4))
return;
orig_dir = ice->gpio.get_dir(ice);
ice->gpio.set_dir(ice, orig_dir | GPIO_SPI_ALL);
ice->gpio.set_mask(ice, ~GPIO_SPI_ALL);
tmp = ice->gpio.get_data(ice);
tmp |= GPIO_SPI_ALL;
ice->gpio.set_data(ice, tmp);
udelay(100);
if (chip)
tmp &= ~GPIO_SPI_CSN1;
else
tmp &= ~GPIO_SPI_CSN0;
ice->gpio.set_data(ice, tmp);
udelay(100);
addrdata = (AK4620_ADDR << 6) | 0x20 | (addr & 0x1f);
addrdata = (addrdata << 8) | data;
for (idx = 15; idx >= 0; idx--) {
tmp &= ~GPIO_D5_SPI_CCLK;
ice->gpio.set_data(ice, tmp);
udelay(100);
if (addrdata & (1 << idx))
tmp |= GPIO_D4_SPI_CDTO;
else
tmp &= ~GPIO_D4_SPI_CDTO;
ice->gpio.set_data(ice, tmp);
udelay(100);
tmp |= GPIO_D5_SPI_CCLK;
ice->gpio.set_data(ice, tmp);
udelay(100);
}
tmp |= GPIO_SPI_ALL;
ice->gpio.set_data(ice, tmp);
udelay(100);
ice->gpio.set_mask(ice, 0xffffff);
ice->gpio.set_dir(ice, orig_dir);
}
static void qtet_akm_set_regs(struct snd_akm4xxx *ak, unsigned char addr,
unsigned char mask, unsigned char value)
{
unsigned char tmp;
int chip;
for (chip = 0; chip < ak->num_chips; chip++) {
tmp = snd_akm4xxx_get(ak, chip, addr);
tmp &= ~mask;
tmp |= value;
snd_akm4xxx_write(ak, chip, addr, tmp);
}
}
static void qtet_akm_set_rate_val(struct snd_akm4xxx *ak, unsigned int rate)
{
unsigned char ak4620_dfs;
if (rate == 0)
return;
if (rate > 108000)
ak4620_dfs = AK4620_DFS1 | AK4620_CKS1;
else if (rate > 54000)
ak4620_dfs = AK4620_DFS0 | AK4620_CKS0;
else
ak4620_dfs = 0;
qtet_akm_set_regs(ak, AK4620_DFS_REG, AK4620_DFS0 | AK4620_DFS1 |
AK4620_CKS0 | AK4620_CKS1, ak4620_dfs);
}
static void reg_write(struct snd_ice1712 *ice, unsigned int reg,
unsigned int data)
{
unsigned int tmp;
mutex_lock(&ice->gpio_mutex);
tmp = 0x00ffff;
ice->gpio.set_dir(ice, tmp);
ice->gpio.set_mask(ice, ~(tmp));
tmp = ice->gpio.get_data(ice);
tmp &= ~GPIO_DATA_MASK;
tmp |= data;
ice->gpio.set_data(ice, tmp);
udelay(100);
tmp &= ~GPIO_EX_GPIOE;
ice->gpio.set_data(ice, tmp);
udelay(100);
tmp &= ~reg;
ice->gpio.set_data(ice, tmp);
udelay(100);
tmp |= reg;
ice->gpio.set_data(ice, tmp);
udelay(100);
tmp |= GPIO_DATA_MASK;
ice->gpio.set_data(ice, tmp);
ice->gpio.set_mask(ice, 0xffffff);
ice->gpio.set_dir(ice, 0x00ff00);
mutex_unlock(&ice->gpio_mutex);
}
static unsigned int get_scr(struct snd_ice1712 *ice)
{
struct qtet_spec *spec = ice->spec;
return spec->scr;
}
static unsigned int get_mcr(struct snd_ice1712 *ice)
{
struct qtet_spec *spec = ice->spec;
return spec->mcr;
}
static unsigned int get_cpld(struct snd_ice1712 *ice)
{
struct qtet_spec *spec = ice->spec;
return spec->cpld;
}
static void set_scr(struct snd_ice1712 *ice, unsigned int val)
{
struct qtet_spec *spec = ice->spec;
reg_write(ice, GPIO_SCR, val);
spec->scr = val;
}
static void set_mcr(struct snd_ice1712 *ice, unsigned int val)
{
struct qtet_spec *spec = ice->spec;
reg_write(ice, GPIO_MCR, val);
spec->mcr = val;
}
static void set_cpld(struct snd_ice1712 *ice, unsigned int val)
{
struct qtet_spec *spec = ice->spec;
reg_write(ice, GPIO_CPLD_CSN, val);
spec->cpld = val;
}
static void proc_regs_read(struct snd_info_entry *entry,
struct snd_info_buffer *buffer)
{
struct snd_ice1712 *ice = entry->private_data;
char bin_buffer[36];
snd_iprintf(buffer, "SCR: %s\n", get_binary(bin_buffer,
get_scr(ice)));
snd_iprintf(buffer, "MCR: %s\n", get_binary(bin_buffer,
get_mcr(ice)));
snd_iprintf(buffer, "CPLD: %s\n", get_binary(bin_buffer,
get_cpld(ice)));
}
static void proc_init(struct snd_ice1712 *ice)
{
struct snd_info_entry *entry;
if (!snd_card_proc_new(ice->card, "quartet", &entry))
snd_info_set_text_ops(entry, ice, proc_regs_read);
}
static void proc_init(struct snd_ice1712 *ice) {}
static int qtet_mute_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned int val;
val = get_scr(ice) & SCR_MUTE;
ucontrol->value.integer.value[0] = (val) ? 0 : 1;
return 0;
}
static int qtet_mute_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned int old, new, smute;
old = get_scr(ice) & SCR_MUTE;
if (ucontrol->value.integer.value[0]) {
new = 0;
smute = 0;
} else {
new = SCR_MUTE;
smute = AK4620_SMUTE;
}
if (old != new) {
struct snd_akm4xxx *ak = ice->akm;
set_scr(ice, (get_scr(ice) & ~SCR_MUTE) | new);
qtet_akm_set_regs(ak, AK4620_DEEMVOL_REG, AK4620_SMUTE, smute);
return 1;
}
return 0;
}
static int qtet_ain12_enum_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static char *texts[3] = {"Line In 1/2", "Mic", "Mic + Low-cut"};
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = ARRAY_SIZE(texts);
if (uinfo->value.enumerated.item >= uinfo->value.enumerated.items)
uinfo->value.enumerated.item =
uinfo->value.enumerated.items - 1;
strcpy(uinfo->value.enumerated.name,
texts[uinfo->value.enumerated.item]);
return 0;
}
static int qtet_ain12_sw_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned int val, result;
val = get_scr(ice) & (SCR_AIN12_SEL1 | SCR_AIN12_SEL0);
switch (val) {
case SCR_AIN12_LINE:
result = 0;
break;
case SCR_AIN12_MIC:
result = 1;
break;
case SCR_AIN12_LOWCUT:
result = 2;
break;
default:
snd_BUG();
result = 0;
}
ucontrol->value.integer.value[0] = result;
return 0;
}
static int qtet_ain12_sw_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned int old, new, tmp, masked_old;
old = new = get_scr(ice);
masked_old = old & (SCR_AIN12_SEL1 | SCR_AIN12_SEL0);
tmp = ucontrol->value.integer.value[0];
if (tmp == 2)
tmp = 3;
tmp <<= 4;
if (tmp != masked_old) {
switch (tmp) {
case SCR_AIN12_LINE:
new = old & ~(SCR_AIN12_SEL1 | SCR_AIN12_SEL0);
set_scr(ice, new);
new &= ~SCR_RELAY;
set_scr(ice, new);
break;
case SCR_AIN12_MIC:
new = old | SCR_RELAY;
set_scr(ice, new);
new = (new & ~SCR_AIN12_SEL1) | SCR_AIN12_SEL0;
set_scr(ice, new);
break;
case SCR_AIN12_LOWCUT:
new = old | SCR_RELAY;
set_scr(ice, new);
new |= SCR_AIN12_SEL1 | SCR_AIN12_SEL0;
set_scr(ice, new);
break;
default:
snd_BUG();
}
return 1;
}
return 0;
}
static int qtet_php_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned int val;
val = get_scr(ice) & SCR_PHP_V;
ucontrol->value.integer.value[0] = val ? 1 : 0;
return 0;
}
static int qtet_php_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned int old, new;
old = new = get_scr(ice);
if (ucontrol->value.integer.value[0]
&& (~old & SCR_PHP_V)) {
new = old | SCR_PHP_V;
set_scr(ice, new);
new &= ~SCR_PHP;
set_scr(ice, new);
} else if (!ucontrol->value.integer.value[0] && (old & SCR_PHP_V)) {
new = old & ~SCR_PHP_V;
set_scr(ice, new);
new |= SCR_PHP;
set_scr(ice, new);
}
if (old != new)
return 1;
return 0;
}
static int qtet_enum_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct qtet_kcontrol_private private =
qtet_privates[kcontrol->private_value];
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = ARRAY_SIZE(private.texts);
if (uinfo->value.enumerated.item >= uinfo->value.enumerated.items)
uinfo->value.enumerated.item =
uinfo->value.enumerated.items - 1;
strcpy(uinfo->value.enumerated.name,
private.texts[uinfo->value.enumerated.item]);
return 0;
}
static int qtet_sw_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct qtet_kcontrol_private private =
qtet_privates[kcontrol->private_value];
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
ucontrol->value.integer.value[0] =
(private.get_register(ice) & private.bit) ? 1 : 0;
return 0;
}
static int qtet_sw_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct qtet_kcontrol_private private =
qtet_privates[kcontrol->private_value];
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned int old, new;
old = private.get_register(ice);
if (ucontrol->value.integer.value[0])
new = old | private.bit;
else
new = old & ~private.bit;
if (old != new) {
private.set_register(ice, new);
return 1;
}
return 0;
}
static struct snd_kcontrol __devinit *ctl_find(struct snd_card *card,
const char *name)
{
struct snd_ctl_elem_id sid;
memset(&sid, 0, sizeof(sid));
strcpy(sid.name, name);
sid.iface = SNDRV_CTL_ELEM_IFACE_MIXER;
return snd_ctl_find_id(card, &sid);
}
static void __devinit add_slaves(struct snd_card *card,
struct snd_kcontrol *master, char **list)
{
for (; *list; list++) {
struct snd_kcontrol *slave = ctl_find(card, *list);
if (slave)
snd_ctl_add_slave(master, slave);
}
}
static int __devinit qtet_add_controls(struct snd_ice1712 *ice)
{
struct qtet_spec *spec = ice->spec;
int err, i;
struct snd_kcontrol *vmaster;
err = snd_ice1712_akm4xxx_build_controls(ice);
if (err < 0)
return err;
for (i = 0; i < ARRAY_SIZE(qtet_controls); i++) {
err = snd_ctl_add(ice->card,
snd_ctl_new1(&qtet_controls[i], ice));
if (err < 0)
return err;
}
vmaster = snd_ctl_make_virtual_master("Master Playback Volume",
qtet_master_db_scale);
if (!vmaster)
return -ENOMEM;
add_slaves(ice->card, vmaster, slave_vols);
err = snd_ctl_add(ice->card, vmaster);
if (err < 0)
return err;
err = snd_ak4113_build(spec->ak4113,
ice->pcm->streams[SNDRV_PCM_STREAM_CAPTURE].substream);
if (err < 0)
return err;
return 0;
}
static inline int qtet_is_spdif_master(struct snd_ice1712 *ice)
{
return (get_cpld(ice) & CPLD_SYNC_SEL) ? 1 : 0;
}
static unsigned int qtet_get_rate(struct snd_ice1712 *ice)
{
int i;
unsigned char result;
result = get_cpld(ice) & CPLD_CKS_MASK;
for (i = 0; i < ARRAY_SIZE(cks_vals); i++)
if (cks_vals[i] == result)
return qtet_rates[i];
return 0;
}
static int get_cks_val(int rate)
{
int i;
for (i = 0; i < ARRAY_SIZE(qtet_rates); i++)
if (qtet_rates[i] == rate)
return cks_vals[i];
return 0;
}
static void qtet_set_rate(struct snd_ice1712 *ice, unsigned int rate)
{
unsigned int new;
unsigned char val;
val = inb(ICEMT1724(ice, RATE));
outb(val | VT1724_SPDIF_MASTER, ICEMT1724(ice, RATE));
new = (get_cpld(ice) & ~CPLD_CKS_MASK) | get_cks_val(rate);
new &= ~CPLD_SYNC_SEL;
set_cpld(ice, new);
}
static inline unsigned char qtet_set_mclk(struct snd_ice1712 *ice,
unsigned int rate)
{
return 0;
}
static int qtet_set_spdif_clock(struct snd_ice1712 *ice, int type)
{
unsigned int old, new;
old = new = get_cpld(ice);
new &= ~(CPLD_CKS_MASK | CPLD_WORD_SEL);
switch (type) {
case EXT_SPDIF_TYPE:
new |= CPLD_EXT_SPDIF;
break;
case EXT_WORDCLOCK_1FS_TYPE:
new |= CPLD_EXT_WORDCLOCK_1FS;
break;
case EXT_WORDCLOCK_256FS_TYPE:
new |= CPLD_EXT_WORDCLOCK_256FS;
break;
default:
snd_BUG();
}
if (old != new) {
set_cpld(ice, new);
return 1;
}
return 0;
}
static int qtet_get_spdif_master_type(struct snd_ice1712 *ice)
{
unsigned int val;
int result;
val = get_cpld(ice);
val &= (CPLD_CKS_MASK | CPLD_WORD_SEL | CPLD_SYNC_SEL);
if (!(val & CPLD_SYNC_SEL)) {
result = -1;
} else {
switch (val) {
case (CPLD_EXT_SPDIF):
result = EXT_SPDIF_TYPE;
break;
case (CPLD_EXT_WORDCLOCK_1FS):
result = EXT_WORDCLOCK_1FS_TYPE;
break;
case (CPLD_EXT_WORDCLOCK_256FS):
result = EXT_WORDCLOCK_256FS_TYPE;
break;
default:
snd_BUG();
result = 0;
}
}
return result;
}
static void qtet_ak4113_change(struct ak4113 *ak4113, unsigned char c0,
unsigned char c1)
{
struct snd_ice1712 *ice = ak4113->change_callback_private;
int rate;
if ((qtet_get_spdif_master_type(ice) == EXT_SPDIF_TYPE) &&
c1) {
rate = snd_ak4113_external_rate(ak4113);
qtet_akm_set_rate_val(ice->akm, rate);
}
}
static void qtet_spdif_in_open(struct snd_ice1712 *ice,
struct snd_pcm_substream *substream)
{
struct qtet_spec *spec = ice->spec;
struct snd_pcm_runtime *runtime = substream->runtime;
int rate;
if (qtet_get_spdif_master_type(ice) != EXT_SPDIF_TYPE)
return;
rate = snd_ak4113_external_rate(spec->ak4113);
if (rate >= runtime->hw.rate_min && rate <= runtime->hw.rate_max) {
runtime->hw.rate_min = rate;
runtime->hw.rate_max = rate;
}
}
static int __devinit qtet_init(struct snd_ice1712 *ice)
{
static const unsigned char ak4113_init_vals[] = {
AK4113_RST | AK4113_PWN |
AK4113_OCKS0 | AK4113_OCKS1,
AK4113_DIF_I24I2S | AK4113_VTX |
AK4113_DEM_OFF | AK4113_DEAU,
AK4113_OPS2 | AK4113_TXE |
AK4113_XTL_24_576M,
AK4113_EFH_1024LRCLK | AK4113_IPS(0),
0,
0,
0,
};
int err;
struct qtet_spec *spec;
struct snd_akm4xxx *ak;
unsigned char val;
val = inb(ICEMT1724(ice, RATE));
outb(val | VT1724_SPDIF_MASTER, ICEMT1724(ice, RATE));
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (!spec)
return -ENOMEM;
ice->hw_rates = &qtet_rates_info;
ice->is_spdif_master = qtet_is_spdif_master;
ice->get_rate = qtet_get_rate;
ice->set_rate = qtet_set_rate;
ice->set_mclk = qtet_set_mclk;
ice->set_spdif_clock = qtet_set_spdif_clock;
ice->get_spdif_master_type = qtet_get_spdif_master_type;
ice->ext_clock_names = ext_clock_names;
ice->ext_clock_count = ARRAY_SIZE(ext_clock_names);
ice->spdif.ops.open = ice->pro_open = qtet_spdif_in_open;
ice->spec = spec;
set_scr(ice, SCR_PHP);
udelay(1);
set_scr(ice, SCR_PHP | SCR_CODEC_PDN);
set_mcr(ice, 0);
set_cpld(ice, 0);
ice->num_total_dacs = 2;
ice->num_total_adcs = 2;
ice->akm = kcalloc(2, sizeof(struct snd_akm4xxx), GFP_KERNEL);
ak = ice->akm;
if (!ak)
return -ENOMEM;
ice->akm_codecs = 1;
err = snd_ice1712_akm4xxx_init(ak, &akm_qtet_dac, NULL, ice);
if (err < 0)
return err;
err = snd_ak4113_create(ice->card,
qtet_ak4113_read,
qtet_ak4113_write,
ak4113_init_vals,
ice, &spec->ak4113);
if (err < 0)
return err;
spec->ak4113->change_callback = qtet_ak4113_change;
spec->ak4113->change_callback_private = ice;
spec->ak4113->check_flags = 0;
proc_init(ice);
qtet_set_rate(ice, 44100);
return 0;
}
