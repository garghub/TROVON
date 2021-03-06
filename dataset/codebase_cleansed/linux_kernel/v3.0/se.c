static void __devinit se200pci_WM8740_init(struct snd_ice1712 *ice)
{
}
static void se200pci_WM8740_set_pro_rate(struct snd_ice1712 *ice,
unsigned int rate)
{
}
static void se200pci_WM8766_write(struct snd_ice1712 *ice,
unsigned int addr, unsigned int data)
{
unsigned int st;
unsigned int bits;
int i;
const unsigned int DATA = 0x010000;
const unsigned int CLOCK = 0x020000;
const unsigned int LOAD = 0x040000;
const unsigned int ALL_MASK = (DATA | CLOCK | LOAD);
snd_ice1712_save_gpio_status(ice);
st = ((addr & 0x7f) << 9) | (data & 0x1ff);
snd_ice1712_gpio_set_dir(ice, ice->gpio.direction | ALL_MASK);
snd_ice1712_gpio_set_mask(ice, ice->gpio.write_mask & ~ALL_MASK);
bits = snd_ice1712_gpio_read(ice) & ~ALL_MASK;
snd_ice1712_gpio_write(ice, bits);
for (i = 0; i < 16; i++) {
udelay(1);
bits &= ~CLOCK;
st = (st << 1);
if (st & 0x10000)
bits |= DATA;
else
bits &= ~DATA;
snd_ice1712_gpio_write(ice, bits);
udelay(1);
bits |= CLOCK;
snd_ice1712_gpio_write(ice, bits);
}
udelay(1);
bits |= LOAD;
snd_ice1712_gpio_write(ice, bits);
udelay(1);
bits |= (DATA | CLOCK);
snd_ice1712_gpio_write(ice, bits);
snd_ice1712_restore_gpio_status(ice);
}
static void se200pci_WM8766_set_volume(struct snd_ice1712 *ice, int ch,
unsigned int vol1, unsigned int vol2)
{
switch (ch) {
case 0:
se200pci_WM8766_write(ice, 0x000, vol1);
se200pci_WM8766_write(ice, 0x001, vol2 | 0x100);
break;
case 1:
se200pci_WM8766_write(ice, 0x004, vol1);
se200pci_WM8766_write(ice, 0x005, vol2 | 0x100);
break;
case 2:
se200pci_WM8766_write(ice, 0x006, vol1);
se200pci_WM8766_write(ice, 0x007, vol2 | 0x100);
break;
}
}
static void __devinit se200pci_WM8766_init(struct snd_ice1712 *ice)
{
se200pci_WM8766_write(ice, 0x1f, 0x000);
udelay(10);
se200pci_WM8766_set_volume(ice, 0, 0, 0);
se200pci_WM8766_set_volume(ice, 1, 0, 0);
se200pci_WM8766_set_volume(ice, 2, 0, 0);
se200pci_WM8766_write(ice, 0x03, 0x022);
se200pci_WM8766_write(ice, 0x0a, 0x080);
se200pci_WM8766_write(ice, 0x12, 0x000);
se200pci_WM8766_write(ice, 0x15, 0x000);
se200pci_WM8766_write(ice, 0x09, 0x000);
se200pci_WM8766_write(ice, 0x02, 0x124);
se200pci_WM8766_write(ice, 0x02, 0x120);
}
static void se200pci_WM8766_set_pro_rate(struct snd_ice1712 *ice,
unsigned int rate)
{
if (rate > 96000)
se200pci_WM8766_write(ice, 0x0a, 0x000);
else
se200pci_WM8766_write(ice, 0x0a, 0x080);
}
static void se200pci_WM8776_write(struct snd_ice1712 *ice,
unsigned int addr, unsigned int data)
{
unsigned int val;
val = (addr << 9) | data;
snd_vt1724_write_i2c(ice, 0x34, val >> 8, val & 0xff);
}
static void se200pci_WM8776_set_output_volume(struct snd_ice1712 *ice,
unsigned int vol1, unsigned int vol2)
{
se200pci_WM8776_write(ice, 0x03, vol1);
se200pci_WM8776_write(ice, 0x04, vol2 | 0x100);
}
static void se200pci_WM8776_set_input_volume(struct snd_ice1712 *ice,
unsigned int vol1, unsigned int vol2)
{
se200pci_WM8776_write(ice, 0x0e, vol1);
se200pci_WM8776_write(ice, 0x0f, vol2 | 0x100);
}
static void se200pci_WM8776_set_input_selector(struct snd_ice1712 *ice,
unsigned int sel)
{
static unsigned char vals[] = {
0x10, 0x04, 0x08, 0x1c, 0x03
};
if (sel > 4)
sel = 4;
se200pci_WM8776_write(ice, 0x15, vals[sel]);
}
static void se200pci_WM8776_set_afl(struct snd_ice1712 *ice, unsigned int afl)
{
if (afl)
se200pci_WM8776_write(ice, 0x16, 0x005);
else
se200pci_WM8776_write(ice, 0x16, 0x001);
}
static void se200pci_WM8776_set_agc(struct snd_ice1712 *ice, unsigned int agc)
{
switch (agc) {
case 0:
se200pci_WM8776_write(ice, 0x11, 0x000);
break;
case 1:
se200pci_WM8776_write(ice, 0x10, 0x07b);
se200pci_WM8776_write(ice, 0x11, 0x100);
break;
case 2:
se200pci_WM8776_write(ice, 0x10, 0x1fb);
se200pci_WM8776_write(ice, 0x11, 0x100);
break;
}
}
static void __devinit se200pci_WM8776_init(struct snd_ice1712 *ice)
{
int i;
static unsigned short __devinitdata default_values[] = {
0x100, 0x100, 0x100,
0x100, 0x100, 0x100,
0x000, 0x090, 0x000, 0x000,
0x022, 0x022, 0x022,
0x008, 0x0cf, 0x0cf, 0x07b, 0x000,
0x032, 0x000, 0x0a6, 0x001, 0x001
};
se200pci_WM8776_write(ice, 0x17, 0x000);
udelay(10);
for (i = 0; i < ARRAY_SIZE(default_values); i++)
se200pci_WM8776_write(ice, i, default_values[i]);
se200pci_WM8776_set_input_selector(ice, 0);
se200pci_WM8776_set_afl(ice, 0);
se200pci_WM8776_set_agc(ice, 0);
se200pci_WM8776_set_input_volume(ice, 0, 0);
se200pci_WM8776_set_output_volume(ice, 0, 0);
se200pci_WM8776_write(ice, 0x00, 0);
se200pci_WM8776_write(ice, 0x01, 0);
se200pci_WM8776_write(ice, 0x02, 0x100);
se200pci_WM8776_write(ice, 0x0d, 0x080);
}
static void se200pci_WM8776_set_pro_rate(struct snd_ice1712 *ice,
unsigned int rate)
{
}
static void se200pci_set_pro_rate(struct snd_ice1712 *ice, unsigned int rate)
{
se200pci_WM8740_set_pro_rate(ice, rate);
se200pci_WM8766_set_pro_rate(ice, rate);
se200pci_WM8776_set_pro_rate(ice, rate);
}
static int se200pci_get_enum_count(int n)
{
const char **member;
int c;
member = se200pci_cont[n].member;
if (!member)
return 0;
for (c = 0; member[c]; c++)
;
return c;
}
static int se200pci_cont_volume_info(struct snd_kcontrol *kc,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 2;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 0xff;
return 0;
}
static int se200pci_cont_enum_info(struct snd_kcontrol *kc,
struct snd_ctl_elem_info *uinfo)
{
int n, c;
n = kc->private_value;
c = se200pci_get_enum_count(n);
if (!c)
return -EINVAL;
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = c;
if (uinfo->value.enumerated.item >= c)
uinfo->value.enumerated.item = c - 1;
strcpy(uinfo->value.enumerated.name,
se200pci_cont[n].member[uinfo->value.enumerated.item]);
return 0;
}
static int se200pci_cont_volume_get(struct snd_kcontrol *kc,
struct snd_ctl_elem_value *uc)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kc);
struct se_spec *spec = ice->spec;
int n = kc->private_value;
uc->value.integer.value[0] = spec->vol[n].ch1;
uc->value.integer.value[1] = spec->vol[n].ch2;
return 0;
}
static int se200pci_cont_boolean_get(struct snd_kcontrol *kc,
struct snd_ctl_elem_value *uc)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kc);
struct se_spec *spec = ice->spec;
int n = kc->private_value;
uc->value.integer.value[0] = spec->vol[n].ch1;
return 0;
}
static int se200pci_cont_enum_get(struct snd_kcontrol *kc,
struct snd_ctl_elem_value *uc)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kc);
struct se_spec *spec = ice->spec;
int n = kc->private_value;
uc->value.enumerated.item[0] = spec->vol[n].ch1;
return 0;
}
static void se200pci_cont_update(struct snd_ice1712 *ice, int n)
{
struct se_spec *spec = ice->spec;
switch (se200pci_cont[n].target) {
case WM8766:
se200pci_WM8766_set_volume(ice,
se200pci_cont[n].ch,
spec->vol[n].ch1,
spec->vol[n].ch2);
break;
case WM8776in:
se200pci_WM8776_set_input_volume(ice,
spec->vol[n].ch1,
spec->vol[n].ch2);
break;
case WM8776out:
se200pci_WM8776_set_output_volume(ice,
spec->vol[n].ch1,
spec->vol[n].ch2);
break;
case WM8776sel:
se200pci_WM8776_set_input_selector(ice,
spec->vol[n].ch1);
break;
case WM8776agc:
se200pci_WM8776_set_agc(ice, spec->vol[n].ch1);
break;
case WM8776afl:
se200pci_WM8776_set_afl(ice, spec->vol[n].ch1);
break;
default:
break;
}
}
static int se200pci_cont_volume_put(struct snd_kcontrol *kc,
struct snd_ctl_elem_value *uc)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kc);
struct se_spec *spec = ice->spec;
int n = kc->private_value;
unsigned int vol1, vol2;
int changed;
changed = 0;
vol1 = uc->value.integer.value[0] & 0xff;
vol2 = uc->value.integer.value[1] & 0xff;
if (spec->vol[n].ch1 != vol1) {
spec->vol[n].ch1 = vol1;
changed = 1;
}
if (spec->vol[n].ch2 != vol2) {
spec->vol[n].ch2 = vol2;
changed = 1;
}
if (changed)
se200pci_cont_update(ice, n);
return changed;
}
static int se200pci_cont_boolean_put(struct snd_kcontrol *kc,
struct snd_ctl_elem_value *uc)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kc);
struct se_spec *spec = ice->spec;
int n = kc->private_value;
unsigned int vol1;
vol1 = !!uc->value.integer.value[0];
if (spec->vol[n].ch1 != vol1) {
spec->vol[n].ch1 = vol1;
se200pci_cont_update(ice, n);
return 1;
}
return 0;
}
static int se200pci_cont_enum_put(struct snd_kcontrol *kc,
struct snd_ctl_elem_value *uc)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kc);
struct se_spec *spec = ice->spec;
int n = kc->private_value;
unsigned int vol1;
vol1 = uc->value.enumerated.item[0];
if (vol1 >= se200pci_get_enum_count(n))
return -EINVAL;
if (spec->vol[n].ch1 != vol1) {
spec->vol[n].ch1 = vol1;
se200pci_cont_update(ice, n);
return 1;
}
return 0;
}
static int __devinit se200pci_add_controls(struct snd_ice1712 *ice)
{
int i;
struct snd_kcontrol_new cont;
int err;
memset(&cont, 0, sizeof(cont));
cont.iface = SNDRV_CTL_ELEM_IFACE_MIXER;
for (i = 0; i < ARRAY_SIZE(se200pci_cont); i++) {
cont.private_value = i;
cont.name = se200pci_cont[i].name;
cont.access = SNDRV_CTL_ELEM_ACCESS_READWRITE;
cont.tlv.p = NULL;
switch (se200pci_cont[i].type) {
case VOLUME1:
case VOLUME2:
cont.info = se200pci_cont_volume_info;
cont.get = se200pci_cont_volume_get;
cont.put = se200pci_cont_volume_put;
cont.access |= SNDRV_CTL_ELEM_ACCESS_TLV_READ;
if (se200pci_cont[i].type == VOLUME1)
cont.tlv.p = db_scale_gain1;
else
cont.tlv.p = db_scale_gain2;
break;
case BOOLEAN:
cont.info = se200pci_cont_boolean_info;
cont.get = se200pci_cont_boolean_get;
cont.put = se200pci_cont_boolean_put;
break;
case ENUM:
cont.info = se200pci_cont_enum_info;
cont.get = se200pci_cont_enum_get;
cont.put = se200pci_cont_enum_put;
break;
default:
snd_BUG();
return -EINVAL;
}
err = snd_ctl_add(ice->card, snd_ctl_new1(&cont, ice));
if (err < 0)
return err;
}
return 0;
}
static int __devinit se_init(struct snd_ice1712 *ice)
{
struct se_spec *spec;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (!spec)
return -ENOMEM;
ice->spec = spec;
if (ice->eeprom.subvendor == VT1724_SUBDEVICE_SE90PCI) {
ice->num_total_dacs = 2;
ice->num_total_adcs = 0;
ice->vt1720 = 1;
return 0;
} else if (ice->eeprom.subvendor == VT1724_SUBDEVICE_SE200PCI) {
ice->num_total_dacs = 8;
ice->num_total_adcs = 2;
se200pci_WM8740_init(ice);
se200pci_WM8766_init(ice);
se200pci_WM8776_init(ice);
ice->gpio.set_pro_rate = se200pci_set_pro_rate;
return 0;
}
return -ENOENT;
}
static int __devinit se_add_controls(struct snd_ice1712 *ice)
{
int err;
err = 0;
if (ice->eeprom.subvendor == VT1724_SUBDEVICE_SE200PCI)
err = se200pci_add_controls(ice);
return err;
}
