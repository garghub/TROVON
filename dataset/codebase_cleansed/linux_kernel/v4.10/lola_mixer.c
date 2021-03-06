static int lola_init_pin(struct lola *chip, struct lola_pin *pin,
int dir, int nid)
{
unsigned int val;
int err;
pin->nid = nid;
err = lola_read_param(chip, nid, LOLA_PAR_AUDIO_WIDGET_CAP, &val);
if (err < 0) {
dev_err(chip->card->dev, "Can't read wcaps for 0x%x\n", nid);
return err;
}
val &= 0x00f00fff;
if (val == 0x00400200)
pin->is_analog = false;
else if (val == 0x0040000a && dir == CAPT)
pin->is_analog = true;
else if (val == 0x0040000c && dir == PLAY)
pin->is_analog = true;
else {
dev_err(chip->card->dev, "Invalid wcaps 0x%x for 0x%x\n", val, nid);
return -EINVAL;
}
if (!pin->is_analog)
return 0;
if (dir == PLAY)
err = lola_read_param(chip, nid, LOLA_PAR_AMP_OUT_CAP, &val);
else
err = lola_read_param(chip, nid, LOLA_PAR_AMP_IN_CAP, &val);
if (err < 0) {
dev_err(chip->card->dev, "Can't read AMP-caps for 0x%x\n", nid);
return err;
}
pin->amp_mute = LOLA_AMP_MUTE_CAPABLE(val);
pin->amp_step_size = LOLA_AMP_STEP_SIZE(val);
pin->amp_num_steps = LOLA_AMP_NUM_STEPS(val);
if (pin->amp_num_steps) {
pin->amp_num_steps++;
pin->amp_step_size++;
}
pin->amp_offset = LOLA_AMP_OFFSET(val);
err = lola_codec_read(chip, nid, LOLA_VERB_GET_MAX_LEVEL, 0, 0, &val,
NULL);
if (err < 0) {
dev_err(chip->card->dev, "Can't get MAX_LEVEL 0x%x\n", nid);
return err;
}
pin->max_level = val & 0x3ff;
pin->config_default_reg = 0;
pin->fixed_gain_list_len = 0;
pin->cur_gain_step = 0;
return 0;
}
int lola_init_pins(struct lola *chip, int dir, int *nidp)
{
int i, err, nid;
nid = *nidp;
for (i = 0; i < chip->pin[dir].num_pins; i++, nid++) {
err = lola_init_pin(chip, &chip->pin[dir].pins[i], dir, nid);
if (err < 0)
return err;
if (chip->pin[dir].pins[i].is_analog)
chip->pin[dir].num_analog_pins++;
}
*nidp = nid;
return 0;
}
void lola_free_mixer(struct lola *chip)
{
vfree(chip->mixer.array_saved);
}
int lola_init_mixer_widget(struct lola *chip, int nid)
{
unsigned int val;
int err;
err = lola_read_param(chip, nid, LOLA_PAR_AUDIO_WIDGET_CAP, &val);
if (err < 0) {
dev_err(chip->card->dev, "Can't read wcaps for 0x%x\n", nid);
return err;
}
if ((val & 0xfff00000) != 0x02f00000) {
dev_dbg(chip->card->dev, "No valid mixer widget\n");
return 0;
}
chip->mixer.nid = nid;
chip->mixer.caps = val;
chip->mixer.array = (struct lola_mixer_array __iomem *)
(chip->bar[BAR1].remap_addr + LOLA_BAR1_SOURCE_GAIN_ENABLE);
chip->mixer.array_saved = vmalloc(sizeof(struct lola_mixer_array));
chip->mixer.src_stream_outs = chip->pcm[PLAY].num_streams;
chip->mixer.src_phys_ins = chip->pin[CAPT].num_pins;
chip->mixer.dest_stream_ins = chip->pcm[CAPT].num_streams;
chip->mixer.dest_phys_outs = chip->pin[PLAY].num_pins;
chip->mixer.src_stream_out_ofs = chip->mixer.src_phys_ins +
LOLA_MIXER_SRC_INPUT_PLAY_SEPARATION(val);
chip->mixer.dest_phys_out_ofs = chip->mixer.dest_stream_ins +
LOLA_MIXER_DEST_REC_OUTPUT_SEPARATION(val);
if (chip->mixer.src_stream_out_ofs > MAX_AUDIO_INOUT_COUNT ||
chip->mixer.dest_phys_out_ofs > MAX_STREAM_IN_COUNT) {
dev_err(chip->card->dev, "Invalid mixer widget size\n");
return -EINVAL;
}
chip->mixer.src_mask = ((1U << chip->mixer.src_phys_ins) - 1) |
(((1U << chip->mixer.src_stream_outs) - 1)
<< chip->mixer.src_stream_out_ofs);
chip->mixer.dest_mask = ((1U << chip->mixer.dest_stream_ins) - 1) |
(((1U << chip->mixer.dest_phys_outs) - 1)
<< chip->mixer.dest_phys_out_ofs);
dev_dbg(chip->card->dev, "Mixer src_mask=%x, dest_mask=%x\n",
chip->mixer.src_mask, chip->mixer.dest_mask);
return 0;
}
static int lola_mixer_set_src_gain(struct lola *chip, unsigned int id,
unsigned short gain, bool on)
{
unsigned int oldval, val;
if (!(chip->mixer.src_mask & (1 << id)))
return -EINVAL;
oldval = val = readl(&chip->mixer.array->src_gain_enable);
if (on)
val |= (1 << id);
else
val &= ~(1 << id);
if ((val == oldval) &&
(gain == readw(&chip->mixer.array->src_gain[id])))
return 0;
dev_dbg(chip->card->dev,
"lola_mixer_set_src_gain (id=%d, gain=%d) enable=%x\n",
id, gain, val);
writew(gain, &chip->mixer.array->src_gain[id]);
writel(val, &chip->mixer.array->src_gain_enable);
lola_codec_flush(chip);
return lola_codec_write(chip, chip->mixer.nid,
LOLA_VERB_SET_SOURCE_GAIN, id, 0);
}
static int lola_mixer_set_mapping_gain(struct lola *chip,
unsigned int src, unsigned int dest,
unsigned short gain, bool on)
{
unsigned int val;
if (!(chip->mixer.src_mask & (1 << src)) ||
!(chip->mixer.dest_mask & (1 << dest)))
return -EINVAL;
if (on)
writew(gain, &chip->mixer.array->dest_mix_gain[dest][src]);
val = readl(&chip->mixer.array->dest_mix_gain_enable[dest]);
if (on)
val |= (1 << src);
else
val &= ~(1 << src);
writel(val, &chip->mixer.array->dest_mix_gain_enable[dest]);
lola_codec_flush(chip);
return lola_codec_write(chip, chip->mixer.nid, LOLA_VERB_SET_MIX_GAIN,
src, dest);
}
int lola_setup_all_analog_gains(struct lola *chip, int dir, bool mute)
{
struct lola_pin *pin;
int idx, max_idx;
pin = chip->pin[dir].pins;
max_idx = chip->pin[dir].num_pins;
for (idx = 0; idx < max_idx; idx++) {
if (pin[idx].is_analog) {
unsigned int val = mute ? 0 : pin[idx].cur_gain_step;
set_analog_volume(chip, dir, idx, val, false);
}
}
return lola_codec_flush(chip);
}
void lola_save_mixer(struct lola *chip)
{
if (chip->mixer.array_saved) {
memcpy_fromio(chip->mixer.array_saved, chip->mixer.array,
sizeof(*chip->mixer.array));
}
lola_setup_all_analog_gains(chip, PLAY, true);
}
void lola_restore_mixer(struct lola *chip)
{
int i;
if (chip->mixer.array_saved) {
memcpy_toio(chip->mixer.array, chip->mixer.array_saved,
sizeof(*chip->mixer.array));
for (i = 0; i < chip->mixer.src_phys_ins; i++)
lola_codec_write(chip, chip->mixer.nid,
LOLA_VERB_SET_SOURCE_GAIN,
i, 0);
for (i = 0; i < chip->mixer.src_stream_outs; i++)
lola_codec_write(chip, chip->mixer.nid,
LOLA_VERB_SET_SOURCE_GAIN,
chip->mixer.src_stream_out_ofs + i, 0);
for (i = 0; i < chip->mixer.dest_stream_ins; i++)
lola_codec_write(chip, chip->mixer.nid,
LOLA_VERB_SET_DESTINATION_GAIN,
i, 0);
for (i = 0; i < chip->mixer.dest_phys_outs; i++)
lola_codec_write(chip, chip->mixer.nid,
LOLA_VERB_SET_DESTINATION_GAIN,
chip->mixer.dest_phys_out_ofs + i, 0);
lola_codec_flush(chip);
}
}
static int set_analog_volume(struct lola *chip, int dir,
unsigned int idx, unsigned int val,
bool external_call)
{
struct lola_pin *pin;
int err;
if (idx >= chip->pin[dir].num_pins)
return -EINVAL;
pin = &chip->pin[dir].pins[idx];
if (!pin->is_analog || pin->amp_num_steps <= val)
return -EINVAL;
if (external_call && pin->cur_gain_step == val)
return 0;
if (external_call)
lola_codec_flush(chip);
dev_dbg(chip->card->dev,
"set_analog_volume (dir=%d idx=%d, volume=%d)\n",
dir, idx, val);
err = lola_codec_write(chip, pin->nid,
LOLA_VERB_SET_AMP_GAIN_MUTE, val, 0);
if (err < 0)
return err;
if (external_call)
pin->cur_gain_step = val;
return 0;
}
int lola_set_src_config(struct lola *chip, unsigned int src_mask, bool update)
{
int ret = 0;
int success = 0;
int n, err;
if ((chip->input_src_caps_mask & src_mask) != src_mask)
return -EINVAL;
for (n = 0; n < chip->pin[CAPT].num_pins; n += 2) {
unsigned int mask = 3U << n;
unsigned int new_src, src_state;
if (!(chip->input_src_caps_mask & mask))
continue;
new_src = (src_mask & mask) != 0;
if (update) {
src_state = (chip->input_src_mask & mask) != 0;
if (src_state == new_src)
continue;
}
err = lola_codec_write(chip, chip->pcm[CAPT].streams[n].nid,
LOLA_VERB_SET_SRC, new_src, 0);
if (!err)
success++;
else
ret = err;
}
if (success)
ret = lola_codec_flush(chip);
if (!ret)
chip->input_src_mask = src_mask;
return ret;
}
static int init_mixer_values(struct lola *chip)
{
int i;
lola_set_src_config(chip, (1 << chip->pin[CAPT].num_pins) - 1, false);
memset_io(chip->mixer.array, 0, sizeof(*chip->mixer.array));
for (i = 0; i < chip->mixer.dest_stream_ins; i++)
lola_codec_write(chip, chip->mixer.nid,
LOLA_VERB_SET_DESTINATION_GAIN,
i, 0);
for (i = 0; i < chip->mixer.dest_phys_outs; i++)
lola_codec_write(chip, chip->mixer.nid,
LOLA_VERB_SET_DESTINATION_GAIN,
chip->mixer.dest_phys_out_ofs + i, 0);
for (i = 0; i < chip->mixer.src_phys_ins; i++)
lola_mixer_set_src_gain(chip, i, 336, true);
for (i = 0; i < chip->mixer.src_stream_outs; i++)
lola_mixer_set_src_gain(chip,
i + chip->mixer.src_stream_out_ofs,
336, true);
for (i = 0; i < chip->mixer.dest_stream_ins; i++) {
int src = i % chip->mixer.src_phys_ins;
lola_mixer_set_mapping_gain(chip, src, i, 336, true);
}
for (i = 0; i < chip->mixer.src_stream_outs; i++) {
int src = chip->mixer.src_stream_out_ofs + i;
int dst = chip->mixer.dest_phys_out_ofs +
i % chip->mixer.dest_phys_outs;
lola_mixer_set_mapping_gain(chip, src, dst, 336, true);
}
return 0;
}
static int lola_analog_vol_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct lola *chip = snd_kcontrol_chip(kcontrol);
int dir = kcontrol->private_value;
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = chip->pin[dir].num_pins;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = chip->pin[dir].pins[0].amp_num_steps;
return 0;
}
static int lola_analog_vol_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct lola *chip = snd_kcontrol_chip(kcontrol);
int dir = kcontrol->private_value;
int i;
for (i = 0; i < chip->pin[dir].num_pins; i++)
ucontrol->value.integer.value[i] =
chip->pin[dir].pins[i].cur_gain_step;
return 0;
}
static int lola_analog_vol_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct lola *chip = snd_kcontrol_chip(kcontrol);
int dir = kcontrol->private_value;
int i, err;
for (i = 0; i < chip->pin[dir].num_pins; i++) {
err = set_analog_volume(chip, dir, i,
ucontrol->value.integer.value[i],
true);
if (err < 0)
return err;
}
return 0;
}
static int lola_analog_vol_tlv(struct snd_kcontrol *kcontrol, int op_flag,
unsigned int size, unsigned int __user *tlv)
{
struct lola *chip = snd_kcontrol_chip(kcontrol);
int dir = kcontrol->private_value;
unsigned int val1, val2;
struct lola_pin *pin;
if (size < 4 * sizeof(unsigned int))
return -ENOMEM;
pin = &chip->pin[dir].pins[0];
val2 = pin->amp_step_size * 25;
val1 = -1 * (int)pin->amp_offset * (int)val2;
#ifdef TLV_DB_SCALE_MUTE
val2 |= TLV_DB_SCALE_MUTE;
#endif
if (put_user(SNDRV_CTL_TLVT_DB_SCALE, tlv))
return -EFAULT;
if (put_user(2 * sizeof(unsigned int), tlv + 1))
return -EFAULT;
if (put_user(val1, tlv + 2))
return -EFAULT;
if (put_user(val2, tlv + 3))
return -EFAULT;
return 0;
}
static int create_analog_mixer(struct lola *chip, int dir, char *name)
{
if (!chip->pin[dir].num_pins)
return 0;
if (chip->pin[dir].num_pins != chip->pin[dir].num_analog_pins)
return 0;
lola_analog_mixer.name = name;
lola_analog_mixer.private_value = dir;
return snd_ctl_add(chip->card,
snd_ctl_new1(&lola_analog_mixer, chip));
}
static int lola_input_src_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct lola *chip = snd_kcontrol_chip(kcontrol);
uinfo->type = SNDRV_CTL_ELEM_TYPE_BOOLEAN;
uinfo->count = chip->pin[CAPT].num_pins;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 1;
return 0;
}
static int lola_input_src_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct lola *chip = snd_kcontrol_chip(kcontrol);
int i;
for (i = 0; i < chip->pin[CAPT].num_pins; i++)
ucontrol->value.integer.value[i] =
!!(chip->input_src_mask & (1 << i));
return 0;
}
static int lola_input_src_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct lola *chip = snd_kcontrol_chip(kcontrol);
int i;
unsigned int mask;
mask = 0;
for (i = 0; i < chip->pin[CAPT].num_pins; i++)
if (ucontrol->value.integer.value[i])
mask |= 1 << i;
return lola_set_src_config(chip, mask, true);
}
static int create_input_src_mixer(struct lola *chip)
{
if (!chip->input_src_caps_mask)
return 0;
return snd_ctl_add(chip->card,
snd_ctl_new1(&lola_input_src_mixer, chip));
}
static int lola_src_gain_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
unsigned int count = (kcontrol->private_value >> 8) & 0xff;
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = count;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 409;
return 0;
}
static int lola_src_gain_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct lola *chip = snd_kcontrol_chip(kcontrol);
unsigned int ofs = kcontrol->private_value & 0xff;
unsigned int count = (kcontrol->private_value >> 8) & 0xff;
unsigned int mask, i;
mask = readl(&chip->mixer.array->src_gain_enable);
for (i = 0; i < count; i++) {
unsigned int idx = ofs + i;
unsigned short val;
if (!(chip->mixer.src_mask & (1 << idx)))
return -EINVAL;
if (mask & (1 << idx))
val = readw(&chip->mixer.array->src_gain[idx]) + 1;
else
val = 0;
ucontrol->value.integer.value[i] = val;
}
return 0;
}
static int lola_src_gain_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct lola *chip = snd_kcontrol_chip(kcontrol);
unsigned int ofs = kcontrol->private_value & 0xff;
unsigned int count = (kcontrol->private_value >> 8) & 0xff;
int i, err;
for (i = 0; i < count; i++) {
unsigned int idx = ofs + i;
unsigned short val = ucontrol->value.integer.value[i];
if (val)
val--;
err = lola_mixer_set_src_gain(chip, idx, val, !!val);
if (err < 0)
return err;
}
return 0;
}
static int create_src_gain_mixer(struct lola *chip,
int num, int ofs, char *name)
{
lola_src_gain_mixer.name = name;
lola_src_gain_mixer.private_value = ofs + (num << 8);
return snd_ctl_add(chip->card,
snd_ctl_new1(&lola_src_gain_mixer, chip));
}
int lola_create_mixer(struct lola *chip)
{
int err;
err = create_analog_mixer(chip, PLAY, "Analog Playback Volume");
if (err < 0)
return err;
err = create_analog_mixer(chip, CAPT, "Analog Capture Volume");
if (err < 0)
return err;
err = create_input_src_mixer(chip);
if (err < 0)
return err;
err = create_src_gain_mixer(chip, chip->mixer.src_phys_ins, 0,
"Digital Capture Volume");
if (err < 0)
return err;
err = create_src_gain_mixer(chip, chip->mixer.src_stream_outs,
chip->mixer.src_stream_out_ofs,
"Digital Playback Volume");
if (err < 0)
return err;
#if 0
err = create_dest_gain_mixer(chip,
chip->mixer.src_phys_ins, 0,
chip->mixer.dest_stream_ins, 0,
"Line Capture Volume");
if (err < 0)
return err;
err = create_dest_gain_mixer(chip,
chip->mixer.src_stream_outs,
chip->mixer.src_stream_out_ofs,
chip->mixer.dest_stream_ins, 0,
"Stream-Loopback Capture Volume");
if (err < 0)
return err;
err = create_dest_gain_mixer(chip,
chip->mixer.src_phys_ins, 0,
chip->mixer.dest_phys_outs,
chip->mixer.dest_phys_out_ofs,
"Line-Loopback Playback Volume");
if (err < 0)
return err;
err = create_dest_gain_mixer(chip,
chip->mixer.src_stream_outs,
chip->mixer.src_stream_out_ofs,
chip->mixer.dest_phys_outs,
chip->mixer.dest_phys_out_ofs,
"Stream Playback Volume");
if (err < 0)
return err;
#endif
return init_mixer_values(chip);
}
