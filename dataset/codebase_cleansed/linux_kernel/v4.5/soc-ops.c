int snd_soc_info_enum_double(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct soc_enum *e = (struct soc_enum *)kcontrol->private_value;
return snd_ctl_enum_info(uinfo, e->shift_l == e->shift_r ? 1 : 2,
e->items, e->texts);
}
int snd_soc_get_enum_double(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_component *component = snd_kcontrol_chip(kcontrol);
struct soc_enum *e = (struct soc_enum *)kcontrol->private_value;
unsigned int val, item;
unsigned int reg_val;
int ret;
ret = snd_soc_component_read(component, e->reg, &reg_val);
if (ret)
return ret;
val = (reg_val >> e->shift_l) & e->mask;
item = snd_soc_enum_val_to_item(e, val);
ucontrol->value.enumerated.item[0] = item;
if (e->shift_l != e->shift_r) {
val = (reg_val >> e->shift_l) & e->mask;
item = snd_soc_enum_val_to_item(e, val);
ucontrol->value.enumerated.item[1] = item;
}
return 0;
}
int snd_soc_put_enum_double(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_component *component = snd_kcontrol_chip(kcontrol);
struct soc_enum *e = (struct soc_enum *)kcontrol->private_value;
unsigned int *item = ucontrol->value.enumerated.item;
unsigned int val;
unsigned int mask;
if (item[0] >= e->items)
return -EINVAL;
val = snd_soc_enum_item_to_val(e, item[0]) << e->shift_l;
mask = e->mask << e->shift_l;
if (e->shift_l != e->shift_r) {
if (item[1] >= e->items)
return -EINVAL;
val |= snd_soc_enum_item_to_val(e, item[1]) << e->shift_r;
mask |= e->mask << e->shift_r;
}
return snd_soc_component_update_bits(component, e->reg, mask, val);
}
static int snd_soc_read_signed(struct snd_soc_component *component,
unsigned int reg, unsigned int mask, unsigned int shift,
unsigned int sign_bit, int *signed_val)
{
int ret;
unsigned int val;
ret = snd_soc_component_read(component, reg, &val);
if (ret < 0)
return ret;
val = (val >> shift) & mask;
if (!sign_bit) {
*signed_val = val;
return 0;
}
if (!(val & BIT(sign_bit))) {
*signed_val = val;
return 0;
}
ret = val;
ret |= ~((int)(BIT(sign_bit) - 1));
*signed_val = ret;
return 0;
}
int snd_soc_info_volsw(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct soc_mixer_control *mc =
(struct soc_mixer_control *)kcontrol->private_value;
int platform_max;
if (!mc->platform_max)
mc->platform_max = mc->max;
platform_max = mc->platform_max;
if (platform_max == 1 && !strstr(kcontrol->id.name, " Volume"))
uinfo->type = SNDRV_CTL_ELEM_TYPE_BOOLEAN;
else
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = snd_soc_volsw_is_stereo(mc) ? 2 : 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = platform_max - mc->min;
return 0;
}
int snd_soc_info_volsw_sx(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct soc_mixer_control *mc =
(struct soc_mixer_control *)kcontrol->private_value;
snd_soc_info_volsw(kcontrol, uinfo);
uinfo->value.integer.max += mc->min;
return 0;
}
int snd_soc_get_volsw(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_component *component = snd_kcontrol_chip(kcontrol);
struct soc_mixer_control *mc =
(struct soc_mixer_control *)kcontrol->private_value;
unsigned int reg = mc->reg;
unsigned int reg2 = mc->rreg;
unsigned int shift = mc->shift;
unsigned int rshift = mc->rshift;
int max = mc->max;
int min = mc->min;
int sign_bit = mc->sign_bit;
unsigned int mask = (1 << fls(max)) - 1;
unsigned int invert = mc->invert;
int val;
int ret;
if (sign_bit)
mask = BIT(sign_bit + 1) - 1;
ret = snd_soc_read_signed(component, reg, mask, shift, sign_bit, &val);
if (ret)
return ret;
ucontrol->value.integer.value[0] = val - min;
if (invert)
ucontrol->value.integer.value[0] =
max - ucontrol->value.integer.value[0];
if (snd_soc_volsw_is_stereo(mc)) {
if (reg == reg2)
ret = snd_soc_read_signed(component, reg, mask, rshift,
sign_bit, &val);
else
ret = snd_soc_read_signed(component, reg2, mask, shift,
sign_bit, &val);
if (ret)
return ret;
ucontrol->value.integer.value[1] = val - min;
if (invert)
ucontrol->value.integer.value[1] =
max - ucontrol->value.integer.value[1];
}
return 0;
}
int snd_soc_put_volsw(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_component *component = snd_kcontrol_chip(kcontrol);
struct soc_mixer_control *mc =
(struct soc_mixer_control *)kcontrol->private_value;
unsigned int reg = mc->reg;
unsigned int reg2 = mc->rreg;
unsigned int shift = mc->shift;
unsigned int rshift = mc->rshift;
int max = mc->max;
int min = mc->min;
unsigned int sign_bit = mc->sign_bit;
unsigned int mask = (1 << fls(max)) - 1;
unsigned int invert = mc->invert;
int err;
bool type_2r = false;
unsigned int val2 = 0;
unsigned int val, val_mask;
if (sign_bit)
mask = BIT(sign_bit + 1) - 1;
val = ((ucontrol->value.integer.value[0] + min) & mask);
if (invert)
val = max - val;
val_mask = mask << shift;
val = val << shift;
if (snd_soc_volsw_is_stereo(mc)) {
val2 = ((ucontrol->value.integer.value[1] + min) & mask);
if (invert)
val2 = max - val2;
if (reg == reg2) {
val_mask |= mask << rshift;
val |= val2 << rshift;
} else {
val2 = val2 << shift;
type_2r = true;
}
}
err = snd_soc_component_update_bits(component, reg, val_mask, val);
if (err < 0)
return err;
if (type_2r)
err = snd_soc_component_update_bits(component, reg2, val_mask,
val2);
return err;
}
int snd_soc_get_volsw_sx(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_component *component = snd_kcontrol_chip(kcontrol);
struct soc_mixer_control *mc =
(struct soc_mixer_control *)kcontrol->private_value;
unsigned int reg = mc->reg;
unsigned int reg2 = mc->rreg;
unsigned int shift = mc->shift;
unsigned int rshift = mc->rshift;
int max = mc->max;
int min = mc->min;
int mask = (1 << (fls(min + max) - 1)) - 1;
unsigned int val;
int ret;
ret = snd_soc_component_read(component, reg, &val);
if (ret < 0)
return ret;
ucontrol->value.integer.value[0] = ((val >> shift) - min) & mask;
if (snd_soc_volsw_is_stereo(mc)) {
ret = snd_soc_component_read(component, reg2, &val);
if (ret < 0)
return ret;
val = ((val >> rshift) - min) & mask;
ucontrol->value.integer.value[1] = val;
}
return 0;
}
int snd_soc_put_volsw_sx(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_component *component = snd_kcontrol_chip(kcontrol);
struct soc_mixer_control *mc =
(struct soc_mixer_control *)kcontrol->private_value;
unsigned int reg = mc->reg;
unsigned int reg2 = mc->rreg;
unsigned int shift = mc->shift;
unsigned int rshift = mc->rshift;
int max = mc->max;
int min = mc->min;
int mask = (1 << (fls(min + max) - 1)) - 1;
int err = 0;
unsigned int val, val_mask, val2 = 0;
val_mask = mask << shift;
val = (ucontrol->value.integer.value[0] + min) & mask;
val = val << shift;
err = snd_soc_component_update_bits(component, reg, val_mask, val);
if (err < 0)
return err;
if (snd_soc_volsw_is_stereo(mc)) {
val_mask = mask << rshift;
val2 = (ucontrol->value.integer.value[1] + min) & mask;
val2 = val2 << rshift;
err = snd_soc_component_update_bits(component, reg2, val_mask,
val2);
}
return err;
}
int snd_soc_info_volsw_range(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct soc_mixer_control *mc =
(struct soc_mixer_control *)kcontrol->private_value;
int platform_max;
int min = mc->min;
if (!mc->platform_max)
mc->platform_max = mc->max;
platform_max = mc->platform_max;
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = snd_soc_volsw_is_stereo(mc) ? 2 : 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = platform_max - min;
return 0;
}
int snd_soc_put_volsw_range(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct soc_mixer_control *mc =
(struct soc_mixer_control *)kcontrol->private_value;
struct snd_soc_component *component = snd_kcontrol_chip(kcontrol);
unsigned int reg = mc->reg;
unsigned int rreg = mc->rreg;
unsigned int shift = mc->shift;
int min = mc->min;
int max = mc->max;
unsigned int mask = (1 << fls(max)) - 1;
unsigned int invert = mc->invert;
unsigned int val, val_mask;
int ret;
if (invert)
val = (max - ucontrol->value.integer.value[0]) & mask;
else
val = ((ucontrol->value.integer.value[0] + min) & mask);
val_mask = mask << shift;
val = val << shift;
ret = snd_soc_component_update_bits(component, reg, val_mask, val);
if (ret < 0)
return ret;
if (snd_soc_volsw_is_stereo(mc)) {
if (invert)
val = (max - ucontrol->value.integer.value[1]) & mask;
else
val = ((ucontrol->value.integer.value[1] + min) & mask);
val_mask = mask << shift;
val = val << shift;
ret = snd_soc_component_update_bits(component, rreg, val_mask,
val);
}
return ret;
}
int snd_soc_get_volsw_range(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_component *component = snd_kcontrol_chip(kcontrol);
struct soc_mixer_control *mc =
(struct soc_mixer_control *)kcontrol->private_value;
unsigned int reg = mc->reg;
unsigned int rreg = mc->rreg;
unsigned int shift = mc->shift;
int min = mc->min;
int max = mc->max;
unsigned int mask = (1 << fls(max)) - 1;
unsigned int invert = mc->invert;
unsigned int val;
int ret;
ret = snd_soc_component_read(component, reg, &val);
if (ret)
return ret;
ucontrol->value.integer.value[0] = (val >> shift) & mask;
if (invert)
ucontrol->value.integer.value[0] =
max - ucontrol->value.integer.value[0];
else
ucontrol->value.integer.value[0] =
ucontrol->value.integer.value[0] - min;
if (snd_soc_volsw_is_stereo(mc)) {
ret = snd_soc_component_read(component, rreg, &val);
if (ret)
return ret;
ucontrol->value.integer.value[1] = (val >> shift) & mask;
if (invert)
ucontrol->value.integer.value[1] =
max - ucontrol->value.integer.value[1];
else
ucontrol->value.integer.value[1] =
ucontrol->value.integer.value[1] - min;
}
return 0;
}
int snd_soc_limit_volume(struct snd_soc_card *card,
const char *name, int max)
{
struct snd_card *snd_card = card->snd_card;
struct snd_kcontrol *kctl;
struct soc_mixer_control *mc;
int found = 0;
int ret = -EINVAL;
if (unlikely(!name || max <= 0))
return -EINVAL;
list_for_each_entry(kctl, &snd_card->controls, list) {
if (!strncmp(kctl->id.name, name, sizeof(kctl->id.name))) {
found = 1;
break;
}
}
if (found) {
mc = (struct soc_mixer_control *)kctl->private_value;
if (max <= mc->max) {
mc->platform_max = max;
ret = 0;
}
}
return ret;
}
int snd_soc_bytes_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct snd_soc_component *component = snd_kcontrol_chip(kcontrol);
struct soc_bytes *params = (void *)kcontrol->private_value;
uinfo->type = SNDRV_CTL_ELEM_TYPE_BYTES;
uinfo->count = params->num_regs * component->val_bytes;
return 0;
}
int snd_soc_bytes_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_component *component = snd_kcontrol_chip(kcontrol);
struct soc_bytes *params = (void *)kcontrol->private_value;
int ret;
if (component->regmap)
ret = regmap_raw_read(component->regmap, params->base,
ucontrol->value.bytes.data,
params->num_regs * component->val_bytes);
else
ret = -EINVAL;
if (ret == 0 && params->mask) {
switch (component->val_bytes) {
case 1:
ucontrol->value.bytes.data[0] &= ~params->mask;
break;
case 2:
((u16 *)(&ucontrol->value.bytes.data))[0]
&= cpu_to_be16(~params->mask);
break;
case 4:
((u32 *)(&ucontrol->value.bytes.data))[0]
&= cpu_to_be32(~params->mask);
break;
default:
return -EINVAL;
}
}
return ret;
}
int snd_soc_bytes_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_component *component = snd_kcontrol_chip(kcontrol);
struct soc_bytes *params = (void *)kcontrol->private_value;
int ret, len;
unsigned int val, mask;
void *data;
if (!component->regmap || !params->num_regs)
return -EINVAL;
len = params->num_regs * component->val_bytes;
data = kmemdup(ucontrol->value.bytes.data, len, GFP_KERNEL | GFP_DMA);
if (!data)
return -ENOMEM;
if (params->mask) {
ret = regmap_read(component->regmap, params->base, &val);
if (ret != 0)
goto out;
val &= params->mask;
switch (component->val_bytes) {
case 1:
((u8 *)data)[0] &= ~params->mask;
((u8 *)data)[0] |= val;
break;
case 2:
mask = ~params->mask;
ret = regmap_parse_val(component->regmap,
&mask, &mask);
if (ret != 0)
goto out;
((u16 *)data)[0] &= mask;
ret = regmap_parse_val(component->regmap,
&val, &val);
if (ret != 0)
goto out;
((u16 *)data)[0] |= val;
break;
case 4:
mask = ~params->mask;
ret = regmap_parse_val(component->regmap,
&mask, &mask);
if (ret != 0)
goto out;
((u32 *)data)[0] &= mask;
ret = regmap_parse_val(component->regmap,
&val, &val);
if (ret != 0)
goto out;
((u32 *)data)[0] |= val;
break;
default:
ret = -EINVAL;
goto out;
}
}
ret = regmap_raw_write(component->regmap, params->base,
data, len);
out:
kfree(data);
return ret;
}
int snd_soc_bytes_info_ext(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *ucontrol)
{
struct soc_bytes_ext *params = (void *)kcontrol->private_value;
ucontrol->type = SNDRV_CTL_ELEM_TYPE_BYTES;
ucontrol->count = params->max;
return 0;
}
int snd_soc_bytes_tlv_callback(struct snd_kcontrol *kcontrol, int op_flag,
unsigned int size, unsigned int __user *tlv)
{
struct soc_bytes_ext *params = (void *)kcontrol->private_value;
unsigned int count = size < params->max ? size : params->max;
int ret = -ENXIO;
switch (op_flag) {
case SNDRV_CTL_TLV_OP_READ:
if (params->get)
ret = params->get(kcontrol, tlv, count);
break;
case SNDRV_CTL_TLV_OP_WRITE:
if (params->put)
ret = params->put(kcontrol, tlv, count);
break;
}
return ret;
}
int snd_soc_info_xr_sx(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct soc_mreg_control *mc =
(struct soc_mreg_control *)kcontrol->private_value;
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 1;
uinfo->value.integer.min = mc->min;
uinfo->value.integer.max = mc->max;
return 0;
}
int snd_soc_get_xr_sx(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_component *component = snd_kcontrol_chip(kcontrol);
struct soc_mreg_control *mc =
(struct soc_mreg_control *)kcontrol->private_value;
unsigned int regbase = mc->regbase;
unsigned int regcount = mc->regcount;
unsigned int regwshift = component->val_bytes * BITS_PER_BYTE;
unsigned int regwmask = (1<<regwshift)-1;
unsigned int invert = mc->invert;
unsigned long mask = (1UL<<mc->nbits)-1;
long min = mc->min;
long max = mc->max;
long val = 0;
unsigned int regval;
unsigned int i;
int ret;
for (i = 0; i < regcount; i++) {
ret = snd_soc_component_read(component, regbase+i, &regval);
if (ret)
return ret;
val |= (regval & regwmask) << (regwshift*(regcount-i-1));
}
val &= mask;
if (min < 0 && val > max)
val |= ~mask;
if (invert)
val = max - val;
ucontrol->value.integer.value[0] = val;
return 0;
}
int snd_soc_put_xr_sx(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_component *component = snd_kcontrol_chip(kcontrol);
struct soc_mreg_control *mc =
(struct soc_mreg_control *)kcontrol->private_value;
unsigned int regbase = mc->regbase;
unsigned int regcount = mc->regcount;
unsigned int regwshift = component->val_bytes * BITS_PER_BYTE;
unsigned int regwmask = (1<<regwshift)-1;
unsigned int invert = mc->invert;
unsigned long mask = (1UL<<mc->nbits)-1;
long max = mc->max;
long val = ucontrol->value.integer.value[0];
unsigned int i, regval, regmask;
int err;
if (invert)
val = max - val;
val &= mask;
for (i = 0; i < regcount; i++) {
regval = (val >> (regwshift*(regcount-i-1))) & regwmask;
regmask = (mask >> (regwshift*(regcount-i-1))) & regwmask;
err = snd_soc_component_update_bits(component, regbase+i,
regmask, regval);
if (err < 0)
return err;
}
return 0;
}
int snd_soc_get_strobe(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_component *component = snd_kcontrol_chip(kcontrol);
struct soc_mixer_control *mc =
(struct soc_mixer_control *)kcontrol->private_value;
unsigned int reg = mc->reg;
unsigned int shift = mc->shift;
unsigned int mask = 1 << shift;
unsigned int invert = mc->invert != 0;
unsigned int val;
int ret;
ret = snd_soc_component_read(component, reg, &val);
if (ret)
return ret;
val &= mask;
if (shift != 0 && val != 0)
val = val >> shift;
ucontrol->value.enumerated.item[0] = val ^ invert;
return 0;
}
int snd_soc_put_strobe(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_component *component = snd_kcontrol_chip(kcontrol);
struct soc_mixer_control *mc =
(struct soc_mixer_control *)kcontrol->private_value;
unsigned int reg = mc->reg;
unsigned int shift = mc->shift;
unsigned int mask = 1 << shift;
unsigned int invert = mc->invert != 0;
unsigned int strobe = ucontrol->value.enumerated.item[0] != 0;
unsigned int val1 = (strobe ^ invert) ? mask : 0;
unsigned int val2 = (strobe ^ invert) ? 0 : mask;
int err;
err = snd_soc_component_update_bits(component, reg, mask, val1);
if (err < 0)
return err;
return snd_soc_component_update_bits(component, reg, mask, val2);
}
