static inline void stac9460_put(struct snd_ice1712 *ice, int reg,
unsigned char val)
{
snd_vt1724_write_i2c(ice, STAC9460_I2C_ADDR, reg, val);
}
static inline unsigned char stac9460_get(struct snd_ice1712 *ice, int reg)
{
return snd_vt1724_read_i2c(ice, STAC9460_I2C_ADDR, reg);
}
static inline void stac9460_2_put(struct snd_ice1712 *ice, int reg,
unsigned char val)
{
snd_vt1724_write_i2c(ice, STAC9460_2_I2C_ADDR, reg, val);
}
static inline unsigned char stac9460_2_get(struct snd_ice1712 *ice, int reg)
{
return snd_vt1724_read_i2c(ice, STAC9460_2_I2C_ADDR, reg);
}
static int stac9460_dac_mute_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned char val;
int idx, id;
if (kcontrol->private_value) {
idx = STAC946X_MASTER_VOLUME;
id = 0;
} else {
id = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
idx = id + STAC946X_LF_VOLUME;
}
if (id < 6)
val = stac9460_get(ice, idx);
else
val = stac9460_2_get(ice, idx - 6);
ucontrol->value.integer.value[0] = (~val >> 7) & 0x1;
return 0;
}
static int stac9460_dac_mute_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned char new, old;
int id, idx;
int change;
if (kcontrol->private_value) {
idx = STAC946X_MASTER_VOLUME;
old = stac9460_get(ice, idx);
new = (~ucontrol->value.integer.value[0] << 7 & 0x80) |
(old & ~0x80);
change = (new != old);
if (change) {
stac9460_put(ice, idx, new);
stac9460_2_put(ice, idx, new);
}
} else {
id = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
idx = id + STAC946X_LF_VOLUME;
if (id < 6)
old = stac9460_get(ice, idx);
else
old = stac9460_2_get(ice, idx - 6);
new = (~ucontrol->value.integer.value[0] << 7 & 0x80) |
(old & ~0x80);
change = (new != old);
if (change) {
if (id < 6)
stac9460_put(ice, idx, new);
else
stac9460_2_put(ice, idx - 6, new);
}
}
return change;
}
static int stac9460_dac_vol_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 0x7f;
return 0;
}
static int stac9460_dac_vol_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
int idx, id;
unsigned char vol;
if (kcontrol->private_value) {
idx = STAC946X_MASTER_VOLUME;
id = 0;
} else {
id = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
idx = id + STAC946X_LF_VOLUME;
}
if (id < 6)
vol = stac9460_get(ice, idx) & 0x7f;
else
vol = stac9460_2_get(ice, idx - 6) & 0x7f;
ucontrol->value.integer.value[0] = 0x7f - vol;
return 0;
}
static int stac9460_dac_vol_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
int idx, id;
unsigned char tmp, ovol, nvol;
int change;
if (kcontrol->private_value) {
idx = STAC946X_MASTER_VOLUME;
nvol = ucontrol->value.integer.value[0] & 0x7f;
tmp = stac9460_get(ice, idx);
ovol = 0x7f - (tmp & 0x7f);
change = (ovol != nvol);
if (change) {
stac9460_put(ice, idx, (0x7f - nvol) | (tmp & 0x80));
stac9460_2_put(ice, idx, (0x7f - nvol) | (tmp & 0x80));
}
} else {
id = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
idx = id + STAC946X_LF_VOLUME;
nvol = ucontrol->value.integer.value[0] & 0x7f;
if (id < 6)
tmp = stac9460_get(ice, idx);
else
tmp = stac9460_2_get(ice, idx - 6);
ovol = 0x7f - (tmp & 0x7f);
change = (ovol != nvol);
if (change) {
if (id < 6)
stac9460_put(ice, idx, (0x7f - nvol) |
(tmp & 0x80));
else
stac9460_2_put(ice, idx-6, (0x7f - nvol) |
(tmp & 0x80));
}
}
return change;
}
static int stac9460_adc_mute_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned char val;
int i, id;
id = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
if (id == 0) {
for (i = 0; i < 2; ++i) {
val = stac9460_get(ice, STAC946X_MIC_L_VOLUME + i);
ucontrol->value.integer.value[i] = ~val>>7 & 0x1;
}
} else {
for (i = 0; i < 2; ++i) {
val = stac9460_2_get(ice, STAC946X_MIC_L_VOLUME + i);
ucontrol->value.integer.value[i] = ~val>>7 & 0x1;
}
}
return 0;
}
static int stac9460_adc_mute_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned char new, old;
int i, reg, id;
int change;
id = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
if (id == 0) {
for (i = 0; i < 2; ++i) {
reg = STAC946X_MIC_L_VOLUME + i;
old = stac9460_get(ice, reg);
new = (~ucontrol->value.integer.value[i]<<7&0x80) |
(old&~0x80);
change = (new != old);
if (change)
stac9460_put(ice, reg, new);
}
} else {
for (i = 0; i < 2; ++i) {
reg = STAC946X_MIC_L_VOLUME + i;
old = stac9460_2_get(ice, reg);
new = (~ucontrol->value.integer.value[i]<<7&0x80) |
(old&~0x80);
change = (new != old);
if (change)
stac9460_2_put(ice, reg, new);
}
}
return change;
}
static int stac9460_adc_vol_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 2;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 0x0f;
return 0;
}
static int stac9460_adc_vol_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
int i, reg, id;
unsigned char vol;
id = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
if (id == 0) {
for (i = 0; i < 2; ++i) {
reg = STAC946X_MIC_L_VOLUME + i;
vol = stac9460_get(ice, reg) & 0x0f;
ucontrol->value.integer.value[i] = 0x0f - vol;
}
} else {
for (i = 0; i < 2; ++i) {
reg = STAC946X_MIC_L_VOLUME + i;
vol = stac9460_2_get(ice, reg) & 0x0f;
ucontrol->value.integer.value[i] = 0x0f - vol;
}
}
return 0;
}
static int stac9460_adc_vol_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
int i, reg, id;
unsigned char ovol, nvol;
int change;
id = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
if (id == 0) {
for (i = 0; i < 2; ++i) {
reg = STAC946X_MIC_L_VOLUME + i;
nvol = ucontrol->value.integer.value[i] & 0x0f;
ovol = 0x0f - stac9460_get(ice, reg);
change = ((ovol & 0x0f) != nvol);
if (change)
stac9460_put(ice, reg, (0x0f - nvol) |
(ovol & ~0x0f));
}
} else {
for (i = 0; i < 2; ++i) {
reg = STAC946X_MIC_L_VOLUME + i;
nvol = ucontrol->value.integer.value[i] & 0x0f;
ovol = 0x0f - stac9460_2_get(ice, reg);
change = ((ovol & 0x0f) != nvol);
if (change)
stac9460_2_put(ice, reg, (0x0f - nvol) |
(ovol & ~0x0f));
}
}
return change;
}
static int stac9460_mic_sw_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned char val;
int id;
id = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
if (id == 0)
val = stac9460_get(ice, STAC946X_GENERAL_PURPOSE);
else
val = stac9460_2_get(ice, STAC946X_GENERAL_PURPOSE);
ucontrol->value.integer.value[0] = ~val>>7 & 0x1;
return 0;
}
static int stac9460_mic_sw_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned char new, old;
int change, id;
id = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
if (id == 0)
old = stac9460_get(ice, STAC946X_GENERAL_PURPOSE);
else
old = stac9460_2_get(ice, STAC946X_GENERAL_PURPOSE);
new = (~ucontrol->value.integer.value[0] << 7 & 0x80) | (old & ~0x80);
change = (new != old);
if (change) {
if (id == 0)
stac9460_put(ice, STAC946X_GENERAL_PURPOSE, new);
else
stac9460_2_put(ice, STAC946X_GENERAL_PURPOSE, new);
}
return change;
}
static int wtm_add_controls(struct snd_ice1712 *ice)
{
unsigned int i;
int err;
for (i = 0; i < ARRAY_SIZE(stac9640_controls); i++) {
err = snd_ctl_add(ice->card,
snd_ctl_new1(&stac9640_controls[i], ice));
if (err < 0)
return err;
}
return 0;
}
static int wtm_init(struct snd_ice1712 *ice)
{
static unsigned short stac_inits_prodigy[] = {
STAC946X_RESET, 0,
(unsigned short)-1
};
unsigned short *p;
ice->num_total_dacs = 8;
ice->num_total_adcs = 4;
ice->force_rdma1 = 1;
p = stac_inits_prodigy;
for (; *p != (unsigned short)-1; p += 2) {
stac9460_put(ice, p[0], p[1]);
stac9460_2_put(ice, p[0], p[1]);
}
return 0;
}
