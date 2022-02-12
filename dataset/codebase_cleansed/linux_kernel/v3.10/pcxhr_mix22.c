static void hr222_config_akm(struct pcxhr_mgr *mgr, unsigned short data)
{
unsigned short mask = 0x8000;
PCXHR_INPB(mgr, PCXHR_XLX_HIFREQ);
while (mask) {
PCXHR_OUTPB(mgr, PCXHR_XLX_DATA,
data & mask ? PCXHR_DATA_CODEC : 0);
mask >>= 1;
}
PCXHR_INPB(mgr, PCXHR_XLX_RUER);
}
static int hr222_set_hw_playback_level(struct pcxhr_mgr *mgr,
int idx, int level)
{
unsigned short cmd;
if (idx > 1 ||
level < 0 ||
level >= ARRAY_SIZE(g_hr222_p_level))
return -EINVAL;
if (idx == 0)
cmd = AKM_LEFT_LEVEL_CMD;
else
cmd = AKM_RIGHT_LEVEL_CMD;
cmd += g_hr222_p_level[level];
hr222_config_akm(mgr, cmd);
return 0;
}
static int hr222_set_hw_capture_level(struct pcxhr_mgr *mgr,
int level_l, int level_r, int level_mic)
{
unsigned int data;
int i;
if (!mgr->capture_chips)
return -EINVAL;
data = ((level_mic & 0xff) << 24);
data |= ((level_mic & 0xff) << 16);
data |= ((level_r & 0xff) << 8);
data |= (level_l & 0xff);
PCXHR_INPB(mgr, PCXHR_XLX_DATA);
for (i = 0; i < 32; i++, data <<= 1) {
PCXHR_OUTPB(mgr, PCXHR_XLX_DATA,
(data & 0x80000000) ? PCXHR_DATA_CODEC : 0);
}
PCXHR_INPB(mgr, PCXHR_XLX_RUER);
return 0;
}
int hr222_sub_init(struct pcxhr_mgr *mgr)
{
unsigned char reg;
mgr->board_has_analog = 1;
mgr->xlx_cfg = PCXHR_CFG_SYNCDSP_MASK;
reg = PCXHR_INPB(mgr, PCXHR_XLX_STATUS);
if (reg & PCXHR_STAT_MIC_CAPS)
mgr->board_has_mic = 1;
snd_printdd("MIC input available = %d\n", mgr->board_has_mic);
PCXHR_OUTPB(mgr, PCXHR_DSP_RESET,
PCXHR_DSP_RESET_DSP);
msleep(5);
mgr->dsp_reset = PCXHR_DSP_RESET_DSP |
PCXHR_DSP_RESET_MUTE |
PCXHR_DSP_RESET_CODEC;
PCXHR_OUTPB(mgr, PCXHR_DSP_RESET, mgr->dsp_reset);
msleep(5);
hr222_config_akm(mgr, AKM_POWER_CONTROL_CMD);
hr222_config_akm(mgr, AKM_CLOCK_INF_55K_CMD);
hr222_config_akm(mgr, AKM_UNMUTE_CMD);
hr222_config_akm(mgr, AKM_RESET_OFF_CMD);
hr222_micro_boost(mgr, 0);
return 0;
}
static int hr222_pll_freq_register(unsigned int freq,
unsigned int *pllreg,
unsigned int *realfreq)
{
unsigned int reg;
if (freq < 6900 || freq > 219000)
return -EINVAL;
reg = (28224000 * 2) / freq;
reg = (reg - 1) / 2;
if (reg < 0x100)
*pllreg = reg + 0xC00;
else if (reg < 0x200)
*pllreg = reg + 0x800;
else if (reg < 0x400)
*pllreg = reg & 0x1ff;
else if (reg < 0x800) {
*pllreg = ((reg >> 1) & 0x1ff) + 0x200;
reg &= ~1;
} else {
*pllreg = ((reg >> 2) & 0x1ff) + 0x400;
reg &= ~3;
}
if (realfreq)
*realfreq = (28224000 / (reg + 1));
return 0;
}
int hr222_sub_set_clock(struct pcxhr_mgr *mgr,
unsigned int rate,
int *changed)
{
unsigned int speed, pllreg = 0;
int err;
unsigned realfreq = rate;
switch (mgr->use_clock_type) {
case HR22_CLOCK_TYPE_INTERNAL:
err = hr222_pll_freq_register(rate, &pllreg, &realfreq);
if (err)
return err;
mgr->xlx_cfg &= ~(PCXHR_CFG_CLOCKIN_SEL_MASK |
PCXHR_CFG_CLOCK_UER1_SEL_MASK);
break;
case HR22_CLOCK_TYPE_AES_SYNC:
mgr->xlx_cfg |= PCXHR_CFG_CLOCKIN_SEL_MASK;
mgr->xlx_cfg &= ~PCXHR_CFG_CLOCK_UER1_SEL_MASK;
break;
case HR22_CLOCK_TYPE_AES_1:
if (!mgr->board_has_aes1)
return -EINVAL;
mgr->xlx_cfg |= (PCXHR_CFG_CLOCKIN_SEL_MASK |
PCXHR_CFG_CLOCK_UER1_SEL_MASK);
break;
default:
return -EINVAL;
}
hr222_config_akm(mgr, AKM_MUTE_CMD);
if (mgr->use_clock_type == HR22_CLOCK_TYPE_INTERNAL) {
PCXHR_OUTPB(mgr, PCXHR_XLX_HIFREQ, pllreg >> 8);
PCXHR_OUTPB(mgr, PCXHR_XLX_LOFREQ, pllreg & 0xff);
}
PCXHR_OUTPB(mgr, PCXHR_XLX_CFG, mgr->xlx_cfg);
speed = rate < 55000 ? 0 : 1;
if (mgr->codec_speed != speed) {
mgr->codec_speed = speed;
if (speed == 0)
hr222_config_akm(mgr, AKM_CLOCK_INF_55K_CMD);
else
hr222_config_akm(mgr, AKM_CLOCK_SUP_55K_CMD);
}
mgr->sample_rate_real = realfreq;
mgr->cur_clock_type = mgr->use_clock_type;
if (changed)
*changed = 1;
hr222_config_akm(mgr, AKM_UNMUTE_CMD);
snd_printdd("set_clock to %dHz (realfreq=%d pllreg=%x)\n",
rate, realfreq, pllreg);
return 0;
}
int hr222_get_external_clock(struct pcxhr_mgr *mgr,
enum pcxhr_clock_type clock_type,
int *sample_rate)
{
int rate, calc_rate = 0;
unsigned int ticks;
unsigned char mask, reg;
if (clock_type == HR22_CLOCK_TYPE_AES_SYNC) {
mask = (PCXHR_SUER_CLOCK_PRESENT_MASK |
PCXHR_SUER_DATA_PRESENT_MASK);
reg = PCXHR_STAT_FREQ_SYNC_MASK;
} else if (clock_type == HR22_CLOCK_TYPE_AES_1 && mgr->board_has_aes1) {
mask = (PCXHR_SUER1_CLOCK_PRESENT_MASK |
PCXHR_SUER1_DATA_PRESENT_MASK);
reg = PCXHR_STAT_FREQ_UER1_MASK;
} else {
snd_printdd("get_external_clock : type %d not supported\n",
clock_type);
return -EINVAL;
}
if ((PCXHR_INPB(mgr, PCXHR_XLX_CSUER) & mask) != mask) {
snd_printdd("get_external_clock(%d) = 0 Hz\n", clock_type);
*sample_rate = 0;
return 0;
}
PCXHR_OUTPB(mgr, PCXHR_XLX_STATUS, reg);
reg |= PCXHR_STAT_FREQ_SAVE_MASK;
if (mgr->last_reg_stat != reg) {
udelay(500);
mgr->last_reg_stat = reg;
}
PCXHR_OUTPB(mgr, PCXHR_XLX_STATUS, reg);
ticks = (unsigned int)PCXHR_INPB(mgr, PCXHR_XLX_CFG);
ticks = (ticks & 0x03) << 8;
ticks |= (unsigned int)PCXHR_INPB(mgr, PCXHR_DSP_RESET);
if (ticks != 0)
calc_rate = 28224000 / ticks;
if (calc_rate > 184200)
rate = 192000;
else if (calc_rate > 152200)
rate = 176400;
else if (calc_rate > 112000)
rate = 128000;
else if (calc_rate > 92100)
rate = 96000;
else if (calc_rate > 76100)
rate = 88200;
else if (calc_rate > 56000)
rate = 64000;
else if (calc_rate > 46050)
rate = 48000;
else if (calc_rate > 38050)
rate = 44100;
else if (calc_rate > 28000)
rate = 32000;
else if (calc_rate > 23025)
rate = 24000;
else if (calc_rate > 19025)
rate = 22050;
else if (calc_rate > 14000)
rate = 16000;
else if (calc_rate > 11512)
rate = 12000;
else if (calc_rate > 9512)
rate = 11025;
else if (calc_rate > 7000)
rate = 8000;
else
rate = 0;
snd_printdd("External clock is at %d Hz (measured %d Hz)\n",
rate, calc_rate);
*sample_rate = rate;
return 0;
}
int hr222_read_gpio(struct pcxhr_mgr *mgr, int is_gpi, int *value)
{
if (is_gpi) {
unsigned char reg = PCXHR_INPB(mgr, PCXHR_XLX_STATUS);
*value = (int)(reg & PCXHR_STAT_GPI_MASK) >>
PCXHR_STAT_GPI_OFFSET;
} else {
*value = (int)(mgr->dsp_reset & PCXHR_DSP_RESET_GPO_MASK) >>
PCXHR_DSP_RESET_GPO_OFFSET;
}
return 0;
}
int hr222_write_gpo(struct pcxhr_mgr *mgr, int value)
{
unsigned char reg = mgr->dsp_reset & ~PCXHR_DSP_RESET_GPO_MASK;
reg |= (unsigned char)(value << PCXHR_DSP_RESET_GPO_OFFSET) &
PCXHR_DSP_RESET_GPO_MASK;
PCXHR_OUTPB(mgr, PCXHR_DSP_RESET, reg);
mgr->dsp_reset = reg;
return 0;
}
int hr222_manage_timecode(struct pcxhr_mgr *mgr, int enable)
{
if (enable)
mgr->dsp_reset |= PCXHR_DSP_RESET_SMPTE;
else
mgr->dsp_reset &= ~PCXHR_DSP_RESET_SMPTE;
PCXHR_OUTPB(mgr, PCXHR_DSP_RESET, mgr->dsp_reset);
return 0;
}
int hr222_update_analog_audio_level(struct snd_pcxhr *chip,
int is_capture, int channel)
{
snd_printdd("hr222_update_analog_audio_level(%s chan=%d)\n",
is_capture ? "capture" : "playback", channel);
if (is_capture) {
int level_l, level_r, level_mic;
if (chip->analog_capture_active) {
level_l = chip->analog_capture_volume[0];
level_r = chip->analog_capture_volume[1];
} else {
level_l = HR222_LINE_CAPTURE_LEVEL_MIN;
level_r = HR222_LINE_CAPTURE_LEVEL_MIN;
}
if (chip->mic_active)
level_mic = chip->mic_volume;
else
level_mic = HR222_MICRO_CAPTURE_LEVEL_MIN;
return hr222_set_hw_capture_level(chip->mgr,
level_l, level_r, level_mic);
} else {
int vol;
if (chip->analog_playback_active[channel])
vol = chip->analog_playback_volume[channel];
else
vol = HR222_LINE_PLAYBACK_LEVEL_MIN;
return hr222_set_hw_playback_level(chip->mgr, channel, vol);
}
}
int hr222_set_audio_source(struct snd_pcxhr *chip)
{
int digital = 0;
chip->mgr->xlx_cfg &= ~(PCXHR_CFG_SRC_MASK |
PCXHR_CFG_DATAIN_SEL_MASK |
PCXHR_CFG_DATA_UER1_SEL_MASK);
if (chip->audio_capture_source == SOURCE_DIGISRC) {
chip->mgr->xlx_cfg |= PCXHR_CFG_SRC_MASK;
digital = 1;
} else {
if (chip->audio_capture_source == SOURCE_DIGITAL)
digital = 1;
}
if (digital) {
chip->mgr->xlx_cfg |= PCXHR_CFG_DATAIN_SEL_MASK;
if (chip->mgr->board_has_aes1) {
chip->mgr->xlx_cfg |= PCXHR_CFG_DATA_UER1_SEL_MASK;
}
} else {
int update_lvl = 0;
chip->analog_capture_active = 0;
chip->mic_active = 0;
if (chip->audio_capture_source == SOURCE_LINE ||
chip->audio_capture_source == SOURCE_LINEMIC) {
if (chip->analog_capture_active == 0)
update_lvl = 1;
chip->analog_capture_active = 1;
}
if (chip->audio_capture_source == SOURCE_MIC ||
chip->audio_capture_source == SOURCE_LINEMIC) {
if (chip->mic_active == 0)
update_lvl = 1;
chip->mic_active = 1;
}
if (update_lvl) {
hr222_update_analog_audio_level(chip, 1, 0);
}
}
PCXHR_OUTPB(chip->mgr, PCXHR_XLX_CFG, chip->mgr->xlx_cfg);
return 0;
}
int hr222_iec958_capture_byte(struct snd_pcxhr *chip,
int aes_idx, unsigned char *aes_bits)
{
unsigned char idx = (unsigned char)(aes_idx * 8);
unsigned char temp = 0;
unsigned char mask = chip->mgr->board_has_aes1 ?
PCXHR_SUER1_BIT_C_READ_MASK : PCXHR_SUER_BIT_C_READ_MASK;
int i;
for (i = 0; i < 8; i++) {
PCXHR_OUTPB(chip->mgr, PCXHR_XLX_RUER, idx++);
temp <<= 1;
if (PCXHR_INPB(chip->mgr, PCXHR_XLX_CSUER) & mask)
temp |= 1;
}
snd_printdd("read iec958 AES %d byte %d = 0x%x\n",
chip->chip_idx, aes_idx, temp);
*aes_bits = temp;
return 0;
}
int hr222_iec958_update_byte(struct snd_pcxhr *chip,
int aes_idx, unsigned char aes_bits)
{
int i;
unsigned char new_bits = aes_bits;
unsigned char old_bits = chip->aes_bits[aes_idx];
unsigned char idx = (unsigned char)(aes_idx * 8);
for (i = 0; i < 8; i++) {
if ((old_bits & 0x01) != (new_bits & 0x01)) {
PCXHR_OUTPB(chip->mgr, PCXHR_XLX_RUER, idx);
PCXHR_OUTPB(chip->mgr, PCXHR_XLX_CSUER, new_bits&0x01 ?
PCXHR_SUER_BIT_C_WRITE_MASK : 0);
}
idx++;
old_bits >>= 1;
new_bits >>= 1;
}
chip->aes_bits[aes_idx] = aes_bits;
return 0;
}
static void hr222_micro_boost(struct pcxhr_mgr *mgr, int level)
{
unsigned char boost_mask;
boost_mask = (unsigned char) (level << PCXHR_SELMIC_PREAMPLI_OFFSET);
if (boost_mask & (~PCXHR_SELMIC_PREAMPLI_MASK))
return;
mgr->xlx_selmic &= ~PCXHR_SELMIC_PREAMPLI_MASK;
mgr->xlx_selmic |= boost_mask;
PCXHR_OUTPB(mgr, PCXHR_XLX_SELMIC, mgr->xlx_selmic);
snd_printdd("hr222_micro_boost : set %x\n", boost_mask);
}
static void hr222_phantom_power(struct pcxhr_mgr *mgr, int power)
{
if (power)
mgr->xlx_selmic |= PCXHR_SELMIC_PHANTOM_ALIM;
else
mgr->xlx_selmic &= ~PCXHR_SELMIC_PHANTOM_ALIM;
PCXHR_OUTPB(mgr, PCXHR_XLX_SELMIC, mgr->xlx_selmic);
snd_printdd("hr222_phantom_power : set %d\n", power);
}
static int hr222_mic_vol_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 1;
uinfo->value.integer.min = HR222_MICRO_CAPTURE_LEVEL_MIN;
uinfo->value.integer.max = HR222_MICRO_CAPTURE_LEVEL_MAX;
return 0;
}
static int hr222_mic_vol_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_pcxhr *chip = snd_kcontrol_chip(kcontrol);
mutex_lock(&chip->mgr->mixer_mutex);
ucontrol->value.integer.value[0] = chip->mic_volume;
mutex_unlock(&chip->mgr->mixer_mutex);
return 0;
}
static int hr222_mic_vol_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_pcxhr *chip = snd_kcontrol_chip(kcontrol);
int changed = 0;
mutex_lock(&chip->mgr->mixer_mutex);
if (chip->mic_volume != ucontrol->value.integer.value[0]) {
changed = 1;
chip->mic_volume = ucontrol->value.integer.value[0];
hr222_update_analog_audio_level(chip, 1, 0);
}
mutex_unlock(&chip->mgr->mixer_mutex);
return changed;
}
static int hr222_mic_boost_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 3;
return 0;
}
static int hr222_mic_boost_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_pcxhr *chip = snd_kcontrol_chip(kcontrol);
mutex_lock(&chip->mgr->mixer_mutex);
ucontrol->value.integer.value[0] = chip->mic_boost;
mutex_unlock(&chip->mgr->mixer_mutex);
return 0;
}
static int hr222_mic_boost_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_pcxhr *chip = snd_kcontrol_chip(kcontrol);
int changed = 0;
mutex_lock(&chip->mgr->mixer_mutex);
if (chip->mic_boost != ucontrol->value.integer.value[0]) {
changed = 1;
chip->mic_boost = ucontrol->value.integer.value[0];
hr222_micro_boost(chip->mgr, chip->mic_boost);
}
mutex_unlock(&chip->mgr->mixer_mutex);
return changed;
}
static int hr222_phantom_power_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_pcxhr *chip = snd_kcontrol_chip(kcontrol);
mutex_lock(&chip->mgr->mixer_mutex);
ucontrol->value.integer.value[0] = chip->phantom_power;
mutex_unlock(&chip->mgr->mixer_mutex);
return 0;
}
static int hr222_phantom_power_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_pcxhr *chip = snd_kcontrol_chip(kcontrol);
int power, changed = 0;
mutex_lock(&chip->mgr->mixer_mutex);
power = !!ucontrol->value.integer.value[0];
if (chip->phantom_power != power) {
hr222_phantom_power(chip->mgr, power);
chip->phantom_power = power;
changed = 1;
}
mutex_unlock(&chip->mgr->mixer_mutex);
return changed;
}
int hr222_add_mic_controls(struct snd_pcxhr *chip)
{
int err;
if (!chip->mgr->board_has_mic)
return 0;
err = snd_ctl_add(chip->card, snd_ctl_new1(&hr222_control_mic_level,
chip));
if (err < 0)
return err;
err = snd_ctl_add(chip->card, snd_ctl_new1(&hr222_control_mic_boost,
chip));
if (err < 0)
return err;
err = snd_ctl_add(chip->card, snd_ctl_new1(&hr222_phantom_power_switch,
chip));
return err;
}
