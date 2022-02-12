static int
snd_azf3328_io_reg_setb(unsigned reg, u8 mask, bool do_set)
{
u8 prev = inb(reg), new;
new = (do_set) ? (prev|mask) : (prev & ~mask);
outb(new, reg);
if (new != prev)
return 1;
return 0;
}
static inline void
snd_azf3328_codec_outb(const struct snd_azf3328_codec_data *codec,
unsigned reg,
u8 value
)
{
outb(value, codec->io_base + reg);
}
static inline u8
snd_azf3328_codec_inb(const struct snd_azf3328_codec_data *codec, unsigned reg)
{
return inb(codec->io_base + reg);
}
static inline void
snd_azf3328_codec_outw(const struct snd_azf3328_codec_data *codec,
unsigned reg,
u16 value
)
{
outw(value, codec->io_base + reg);
}
static inline u16
snd_azf3328_codec_inw(const struct snd_azf3328_codec_data *codec, unsigned reg)
{
return inw(codec->io_base + reg);
}
static inline void
snd_azf3328_codec_outl(const struct snd_azf3328_codec_data *codec,
unsigned reg,
u32 value
)
{
outl(value, codec->io_base + reg);
}
static inline void
snd_azf3328_codec_outl_multi(const struct snd_azf3328_codec_data *codec,
unsigned reg, const void *buffer, int count
)
{
unsigned long addr = codec->io_base + reg;
if (count) {
const u32 *buf = buffer;
do {
outl(*buf++, addr);
addr += 4;
} while (--count);
}
}
static inline u32
snd_azf3328_codec_inl(const struct snd_azf3328_codec_data *codec, unsigned reg)
{
return inl(codec->io_base + reg);
}
static inline void
snd_azf3328_ctrl_outb(const struct snd_azf3328 *chip, unsigned reg, u8 value)
{
outb(value, chip->ctrl_io + reg);
}
static inline u8
snd_azf3328_ctrl_inb(const struct snd_azf3328 *chip, unsigned reg)
{
return inb(chip->ctrl_io + reg);
}
static inline u16
snd_azf3328_ctrl_inw(const struct snd_azf3328 *chip, unsigned reg)
{
return inw(chip->ctrl_io + reg);
}
static inline void
snd_azf3328_ctrl_outw(const struct snd_azf3328 *chip, unsigned reg, u16 value)
{
outw(value, chip->ctrl_io + reg);
}
static inline void
snd_azf3328_ctrl_outl(const struct snd_azf3328 *chip, unsigned reg, u32 value)
{
outl(value, chip->ctrl_io + reg);
}
static inline void
snd_azf3328_game_outb(const struct snd_azf3328 *chip, unsigned reg, u8 value)
{
outb(value, chip->game_io + reg);
}
static inline void
snd_azf3328_game_outw(const struct snd_azf3328 *chip, unsigned reg, u16 value)
{
outw(value, chip->game_io + reg);
}
static inline u8
snd_azf3328_game_inb(const struct snd_azf3328 *chip, unsigned reg)
{
return inb(chip->game_io + reg);
}
static inline u16
snd_azf3328_game_inw(const struct snd_azf3328 *chip, unsigned reg)
{
return inw(chip->game_io + reg);
}
static inline void
snd_azf3328_mixer_outw(const struct snd_azf3328 *chip, unsigned reg, u16 value)
{
outw(value, chip->mixer_io + reg);
}
static inline u16
snd_azf3328_mixer_inw(const struct snd_azf3328 *chip, unsigned reg)
{
return inw(chip->mixer_io + reg);
}
static bool
snd_azf3328_mixer_mute_control(const struct snd_azf3328 *chip,
unsigned reg, bool do_mute
)
{
unsigned long portbase = chip->mixer_io + reg + 1;
bool updated;
updated = snd_azf3328_io_reg_setb(portbase, AZF_MUTE_BIT, do_mute);
return (do_mute) ? !updated : updated;
}
static inline bool
snd_azf3328_mixer_mute_control_master(const struct snd_azf3328 *chip,
bool do_mute
)
{
return snd_azf3328_mixer_mute_control(
chip,
IDX_MIXER_PLAY_MASTER,
do_mute
);
}
static inline bool
snd_azf3328_mixer_mute_control_pcm(const struct snd_azf3328 *chip,
bool do_mute
)
{
return snd_azf3328_mixer_mute_control(
chip,
IDX_MIXER_WAVEOUT,
do_mute
);
}
static inline void
snd_azf3328_mixer_reset(const struct snd_azf3328 *chip)
{
snd_azf3328_mixer_mute_control_master(chip, 1);
snd_azf3328_mixer_outw(chip, IDX_MIXER_RESET, 0x0000);
}
static inline void
snd_azf3328_mixer_ac97_map_unsupported(const struct snd_azf3328 *chip,
unsigned short reg, const char *mode)
{
dev_warn(chip->card->dev,
"missing %s emulation for AC97 register 0x%02x!\n",
mode, reg);
}
static unsigned short
snd_azf3328_mixer_ac97_map_reg_idx(unsigned short reg)
{
static const struct {
unsigned short azf_reg;
} azf_reg_mapper[] = {
{ IDX_MIXER_RESET
| AZF_AC97_REG_REAL_IO_WRITE
| AZF_AC97_REG_EMU_IO_READ },
{ IDX_MIXER_PLAY_MASTER },
{ IDX_MIXER_FMSYNTH },
{ IDX_MIXER_MODEMOUT },
{ IDX_MIXER_BASSTREBLE },
{ IDX_MIXER_PCBEEP },
{ IDX_MIXER_MODEMIN },
{ IDX_MIXER_MIC },
{ IDX_MIXER_LINEIN },
{ IDX_MIXER_CDAUDIO },
{ IDX_MIXER_VIDEO },
{ IDX_MIXER_AUX },
{ IDX_MIXER_WAVEOUT },
{ IDX_MIXER_REC_SELECT },
{ IDX_MIXER_REC_VOLUME },
{ AZF_AC97_REG_EMU_IO_RW },
{ IDX_MIXER_ADVCTL2 },
{ IDX_MIXER_ADVCTL1 },
};
unsigned short reg_azf = AZF_AC97_REG_UNSUPPORTED;
if (reg <= AC97_3D_CONTROL) {
unsigned short reg_idx = reg / 2;
reg_azf = azf_reg_mapper[reg_idx].azf_reg;
if (!(reg_azf & ~AZF_REG_MASK))
reg_azf |= AZF_AC97_REG_REAL_IO_RW;
} else {
switch (reg) {
case AC97_POWERDOWN:
reg_azf = AZF_AC97_REG_EMU_IO_RW;
break;
case AC97_EXTENDED_ID:
reg_azf = AZF_AC97_REG_EMU_IO_READ;
break;
case AC97_EXTENDED_STATUS:
reg_azf = AZF_AC97_REG_EMU_IO_RW;
break;
case AC97_VENDOR_ID1:
case AC97_VENDOR_ID2:
reg_azf = AZF_AC97_REG_EMU_IO_READ;
break;
}
}
return reg_azf;
}
static unsigned short
snd_azf3328_mixer_ac97_read(struct snd_ac97 *ac97, unsigned short reg_ac97)
{
const struct snd_azf3328 *chip = ac97->private_data;
unsigned short reg_azf = snd_azf3328_mixer_ac97_map_reg_idx(reg_ac97);
unsigned short reg_val = 0;
bool unsupported = false;
dev_dbg(chip->card->dev, "snd_azf3328_mixer_ac97_read reg_ac97 %u\n",
reg_ac97);
if (reg_azf & AZF_AC97_REG_UNSUPPORTED)
unsupported = true;
else {
if (reg_azf & AZF_AC97_REG_REAL_IO_READ)
reg_val = snd_azf3328_mixer_inw(chip,
reg_azf & AZF_REG_MASK);
else {
snd_azf3328_mixer_inw(chip, IDX_MIXER_SOMETHING30H);
}
if (reg_azf & AZF_AC97_REG_EMU_IO_READ) {
switch (reg_ac97) {
case AC97_RESET:
reg_val |= azf_emulated_ac97_caps;
break;
case AC97_POWERDOWN:
reg_val |= azf_emulated_ac97_powerdown;
break;
case AC97_EXTENDED_ID:
case AC97_EXTENDED_STATUS:
reg_val |= 0;
break;
case AC97_VENDOR_ID1:
reg_val = azf_emulated_ac97_vendor_id >> 16;
break;
case AC97_VENDOR_ID2:
reg_val = azf_emulated_ac97_vendor_id & 0xffff;
break;
default:
unsupported = true;
break;
}
}
}
if (unsupported)
snd_azf3328_mixer_ac97_map_unsupported(chip, reg_ac97, "read");
return reg_val;
}
static void
snd_azf3328_mixer_ac97_write(struct snd_ac97 *ac97,
unsigned short reg_ac97, unsigned short val)
{
const struct snd_azf3328 *chip = ac97->private_data;
unsigned short reg_azf = snd_azf3328_mixer_ac97_map_reg_idx(reg_ac97);
bool unsupported = false;
dev_dbg(chip->card->dev,
"snd_azf3328_mixer_ac97_write reg_ac97 %u val %u\n",
reg_ac97, val);
if (reg_azf & AZF_AC97_REG_UNSUPPORTED)
unsupported = true;
else {
if (reg_azf & AZF_AC97_REG_REAL_IO_WRITE)
snd_azf3328_mixer_outw(
chip,
reg_azf & AZF_REG_MASK,
val
);
else
if (reg_azf & AZF_AC97_REG_EMU_IO_WRITE) {
switch (reg_ac97) {
case AC97_REC_GAIN_MIC:
case AC97_POWERDOWN:
case AC97_EXTENDED_STATUS:
break;
default:
unsupported = true;
break;
}
}
}
if (unsupported)
snd_azf3328_mixer_ac97_map_unsupported(chip, reg_ac97, "write");
}
static int
snd_azf3328_mixer_new(struct snd_azf3328 *chip)
{
struct snd_ac97_bus *bus;
struct snd_ac97_template ac97;
static struct snd_ac97_bus_ops ops = {
.write = snd_azf3328_mixer_ac97_write,
.read = snd_azf3328_mixer_ac97_read,
};
int rc;
memset(&ac97, 0, sizeof(ac97));
ac97.scaps = AC97_SCAP_SKIP_MODEM
| AC97_SCAP_AUDIO
| AC97_SCAP_NO_SPDIF;
ac97.private_data = chip;
ac97.pci = chip->pci;
rc = snd_ac97_bus(chip->card, 0, &ops, NULL, &bus);
if (!rc)
rc = snd_ac97_mixer(bus, &ac97, &chip->ac97);
if (rc)
dev_err(chip->card->dev, "AC97 init failed, err %d!\n", rc);
return rc;
}
static void
snd_azf3328_mixer_write_volume_gradually(const struct snd_azf3328 *chip,
unsigned reg,
unsigned char dst_vol_left,
unsigned char dst_vol_right,
int chan_sel, int delay
)
{
unsigned long portbase = chip->mixer_io + reg;
unsigned char curr_vol_left = 0, curr_vol_right = 0;
int left_change = 0, right_change = 0;
if (chan_sel & SET_CHAN_LEFT) {
curr_vol_left = inb(portbase + 1);
if (curr_vol_left & AZF_MUTE_BIT)
dst_vol_left |= AZF_MUTE_BIT;
else
dst_vol_left &= ~AZF_MUTE_BIT;
left_change = (curr_vol_left > dst_vol_left) ? -1 : 1;
}
if (chan_sel & SET_CHAN_RIGHT) {
curr_vol_right = inb(portbase + 0);
right_change = (curr_vol_right > dst_vol_right) ? -1 : 1;
}
do {
if (left_change) {
if (curr_vol_left != dst_vol_left) {
curr_vol_left += left_change;
outb(curr_vol_left, portbase + 1);
} else
left_change = 0;
}
if (right_change) {
if (curr_vol_right != dst_vol_right) {
curr_vol_right += right_change;
outb(curr_vol_right, portbase + 0);
} else
right_change = 0;
}
if (delay)
mdelay(delay);
} while ((left_change) || (right_change));
}
static void snd_azf3328_mixer_reg_decode(struct azf3328_mixer_reg *r, unsigned long val)
{
r->reg = val & 0xff;
r->lchan_shift = (val >> 8) & 0x0f;
r->rchan_shift = (val >> 12) & 0x0f;
r->mask = (val >> 16) & 0xff;
r->invert = (val >> 24) & 1;
r->stereo = (val >> 25) & 1;
r->enum_c = (val >> 26) & 0x0f;
}
static int
snd_azf3328_info_mixer(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct azf3328_mixer_reg reg;
snd_azf3328_mixer_reg_decode(&reg, kcontrol->private_value);
uinfo->type = reg.mask == 1 ?
SNDRV_CTL_ELEM_TYPE_BOOLEAN : SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = reg.stereo + 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = reg.mask;
return 0;
}
static int
snd_azf3328_get_mixer(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_azf3328 *chip = snd_kcontrol_chip(kcontrol);
struct azf3328_mixer_reg reg;
u16 oreg, val;
snd_azf3328_mixer_reg_decode(&reg, kcontrol->private_value);
oreg = snd_azf3328_mixer_inw(chip, reg.reg);
val = (oreg >> reg.lchan_shift) & reg.mask;
if (reg.invert)
val = reg.mask - val;
ucontrol->value.integer.value[0] = val;
if (reg.stereo) {
val = (oreg >> reg.rchan_shift) & reg.mask;
if (reg.invert)
val = reg.mask - val;
ucontrol->value.integer.value[1] = val;
}
dev_dbg(chip->card->dev,
"get: %02x is %04x -> vol %02lx|%02lx (shift %02d|%02d, mask %02x, inv. %d, stereo %d)\n",
reg.reg, oreg,
ucontrol->value.integer.value[0], ucontrol->value.integer.value[1],
reg.lchan_shift, reg.rchan_shift, reg.mask, reg.invert, reg.stereo);
return 0;
}
static int
snd_azf3328_put_mixer(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_azf3328 *chip = snd_kcontrol_chip(kcontrol);
struct azf3328_mixer_reg reg;
u16 oreg, nreg, val;
snd_azf3328_mixer_reg_decode(&reg, kcontrol->private_value);
oreg = snd_azf3328_mixer_inw(chip, reg.reg);
val = ucontrol->value.integer.value[0] & reg.mask;
if (reg.invert)
val = reg.mask - val;
nreg = oreg & ~(reg.mask << reg.lchan_shift);
nreg |= (val << reg.lchan_shift);
if (reg.stereo) {
val = ucontrol->value.integer.value[1] & reg.mask;
if (reg.invert)
val = reg.mask - val;
nreg &= ~(reg.mask << reg.rchan_shift);
nreg |= (val << reg.rchan_shift);
}
if (reg.mask >= 0x07)
snd_azf3328_mixer_write_volume_gradually(
chip, reg.reg, nreg >> 8, nreg & 0xff,
SET_CHAN_LEFT|SET_CHAN_RIGHT,
0);
else
snd_azf3328_mixer_outw(chip, reg.reg, nreg);
dev_dbg(chip->card->dev,
"put: %02x to %02lx|%02lx, oreg %04x; shift %02d|%02d -> nreg %04x; after: %04x\n",
reg.reg, ucontrol->value.integer.value[0], ucontrol->value.integer.value[1],
oreg, reg.lchan_shift, reg.rchan_shift,
nreg, snd_azf3328_mixer_inw(chip, reg.reg));
return (nreg != oreg);
}
static int
snd_azf3328_info_mixer_enum(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static const char * const texts1[] = {
"Mic1", "Mic2"
};
static const char * const texts2[] = {
"Mix", "Mic"
};
static const char * const texts3[] = {
"Mic", "CD", "Video", "Aux",
"Line", "Mix", "Mix Mono", "Phone"
};
static const char * const texts4[] = {
"pre 3D", "post 3D"
};
struct azf3328_mixer_reg reg;
const char * const *p = NULL;
snd_azf3328_mixer_reg_decode(&reg, kcontrol->private_value);
if (reg.reg == IDX_MIXER_ADVCTL2) {
switch(reg.lchan_shift) {
case 8:
p = texts1;
break;
case 9:
p = texts2;
break;
case 15:
p = texts4;
break;
}
} else if (reg.reg == IDX_MIXER_REC_SELECT)
p = texts3;
return snd_ctl_enum_info(uinfo,
(reg.reg == IDX_MIXER_REC_SELECT) ? 2 : 1,
reg.enum_c, p);
}
static int
snd_azf3328_get_mixer_enum(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_azf3328 *chip = snd_kcontrol_chip(kcontrol);
struct azf3328_mixer_reg reg;
unsigned short val;
snd_azf3328_mixer_reg_decode(&reg, kcontrol->private_value);
val = snd_azf3328_mixer_inw(chip, reg.reg);
if (reg.reg == IDX_MIXER_REC_SELECT) {
ucontrol->value.enumerated.item[0] = (val >> 8) & (reg.enum_c - 1);
ucontrol->value.enumerated.item[1] = (val >> 0) & (reg.enum_c - 1);
} else
ucontrol->value.enumerated.item[0] = (val >> reg.lchan_shift) & (reg.enum_c - 1);
dev_dbg(chip->card->dev,
"get_enum: %02x is %04x -> %d|%d (shift %02d, enum_c %d)\n",
reg.reg, val, ucontrol->value.enumerated.item[0], ucontrol->value.enumerated.item[1],
reg.lchan_shift, reg.enum_c);
return 0;
}
static int
snd_azf3328_put_mixer_enum(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_azf3328 *chip = snd_kcontrol_chip(kcontrol);
struct azf3328_mixer_reg reg;
u16 oreg, nreg, val;
snd_azf3328_mixer_reg_decode(&reg, kcontrol->private_value);
oreg = snd_azf3328_mixer_inw(chip, reg.reg);
val = oreg;
if (reg.reg == IDX_MIXER_REC_SELECT) {
if (ucontrol->value.enumerated.item[0] > reg.enum_c - 1U ||
ucontrol->value.enumerated.item[1] > reg.enum_c - 1U)
return -EINVAL;
val = (ucontrol->value.enumerated.item[0] << 8) |
(ucontrol->value.enumerated.item[1] << 0);
} else {
if (ucontrol->value.enumerated.item[0] > reg.enum_c - 1U)
return -EINVAL;
val &= ~((reg.enum_c - 1) << reg.lchan_shift);
val |= (ucontrol->value.enumerated.item[0] << reg.lchan_shift);
}
snd_azf3328_mixer_outw(chip, reg.reg, val);
nreg = val;
dev_dbg(chip->card->dev,
"put_enum: %02x to %04x, oreg %04x\n", reg.reg, val, oreg);
return (nreg != oreg);
}
static int
snd_azf3328_mixer_new(struct snd_azf3328 *chip)
{
struct snd_card *card;
const struct snd_kcontrol_new *sw;
unsigned int idx;
int err;
if (snd_BUG_ON(!chip || !chip->card))
return -EINVAL;
card = chip->card;
snd_azf3328_mixer_outw(chip, IDX_MIXER_RESET, 0x0000);
for (idx = 0; idx < ARRAY_SIZE(snd_azf3328_init_values); ++idx) {
snd_azf3328_mixer_outw(chip,
snd_azf3328_init_values[idx][0],
snd_azf3328_init_values[idx][1]);
}
sw = snd_azf3328_mixer_controls;
for (idx = 0; idx < ARRAY_SIZE(snd_azf3328_mixer_controls);
++idx, ++sw) {
if ((err = snd_ctl_add(chip->card, snd_ctl_new1(sw, chip))) < 0)
return err;
}
snd_component_add(card, "AZF3328 mixer");
strcpy(card->mixername, "AZF3328 mixer");
return 0;
}
static int
snd_azf3328_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
return snd_pcm_lib_malloc_pages(substream, params_buffer_bytes(hw_params));
}
static int
snd_azf3328_hw_free(struct snd_pcm_substream *substream)
{
snd_pcm_lib_free_pages(substream);
return 0;
}
static void
snd_azf3328_codec_setfmt(struct snd_azf3328_codec_data *codec,
enum azf_freq_t bitrate,
unsigned int format_width,
unsigned int channels
)
{
unsigned long flags;
u16 val = 0xff00;
u8 freq = 0;
switch (bitrate) {
case AZF_FREQ_4000: freq = SOUNDFORMAT_FREQ_SUSPECTED_4000; break;
case AZF_FREQ_4800: freq = SOUNDFORMAT_FREQ_SUSPECTED_4800; break;
case AZF_FREQ_5512:
freq = SOUNDFORMAT_FREQ_5510; break;
case AZF_FREQ_6620: freq = SOUNDFORMAT_FREQ_6620; break;
case AZF_FREQ_8000: freq = SOUNDFORMAT_FREQ_8000; break;
case AZF_FREQ_9600: freq = SOUNDFORMAT_FREQ_9600; break;
case AZF_FREQ_11025: freq = SOUNDFORMAT_FREQ_11025; break;
case AZF_FREQ_13240: freq = SOUNDFORMAT_FREQ_SUSPECTED_13240; break;
case AZF_FREQ_16000: freq = SOUNDFORMAT_FREQ_16000; break;
case AZF_FREQ_22050: freq = SOUNDFORMAT_FREQ_22050; break;
case AZF_FREQ_32000: freq = SOUNDFORMAT_FREQ_32000; break;
default:
snd_printk(KERN_WARNING "unknown bitrate %d, assuming 44.1kHz!\n", bitrate);
case AZF_FREQ_44100: freq = SOUNDFORMAT_FREQ_44100; break;
case AZF_FREQ_48000: freq = SOUNDFORMAT_FREQ_48000; break;
case AZF_FREQ_66200: freq = SOUNDFORMAT_FREQ_SUSPECTED_66200; break;
}
val |= freq;
if (channels == 2)
val |= SOUNDFORMAT_FLAG_2CHANNELS;
if (format_width == 16)
val |= SOUNDFORMAT_FLAG_16BIT;
spin_lock_irqsave(codec->lock, flags);
snd_azf3328_codec_outw(codec, IDX_IO_CODEC_SOUNDFORMAT, val);
if (codec->type != AZF_CODEC_CAPTURE)
snd_azf3328_codec_outw(codec, IDX_IO_CODEC_DMA_FLAGS,
snd_azf3328_codec_inw(codec, IDX_IO_CODEC_DMA_FLAGS) |
DMA_RUN_SOMETHING1 |
DMA_RUN_SOMETHING2 |
SOMETHING_ALMOST_ALWAYS_SET |
DMA_EPILOGUE_SOMETHING |
DMA_SOMETHING_ELSE
);
spin_unlock_irqrestore(codec->lock, flags);
}
static inline void
snd_azf3328_codec_setfmt_lowpower(struct snd_azf3328_codec_data *codec
)
{
snd_azf3328_codec_setfmt(codec, AZF_FREQ_4000, 8, 1);
}
static void
snd_azf3328_ctrl_reg_6AH_update(struct snd_azf3328 *chip,
unsigned bitmask,
bool enable
)
{
bool do_mask = !enable;
if (do_mask)
chip->shadow_reg_ctrl_6AH |= bitmask;
else
chip->shadow_reg_ctrl_6AH &= ~bitmask;
dev_dbg(chip->card->dev,
"6AH_update mask 0x%04x do_mask %d: val 0x%04x\n",
bitmask, do_mask, chip->shadow_reg_ctrl_6AH);
snd_azf3328_ctrl_outw(chip, IDX_IO_6AH, chip->shadow_reg_ctrl_6AH);
}
static inline void
snd_azf3328_ctrl_enable_codecs(struct snd_azf3328 *chip, bool enable)
{
dev_dbg(chip->card->dev, "codec_enable %d\n", enable);
snd_azf3328_ctrl_reg_6AH_update(
chip, IO_6A_PAUSE_PLAYBACK_BIT8, enable
);
}
static void
snd_azf3328_ctrl_codec_activity(struct snd_azf3328 *chip,
enum snd_azf3328_codec_type codec_type,
bool enable
)
{
struct snd_azf3328_codec_data *codec = &chip->codecs[codec_type];
bool need_change = (codec->running != enable);
dev_dbg(chip->card->dev,
"codec_activity: %s codec, enable %d, need_change %d\n",
codec->name, enable, need_change
);
if (need_change) {
static const struct {
enum snd_azf3328_codec_type other1;
enum snd_azf3328_codec_type other2;
} peer_codecs[3] =
{ { AZF_CODEC_CAPTURE, AZF_CODEC_I2S_OUT },
{ AZF_CODEC_PLAYBACK, AZF_CODEC_I2S_OUT },
{ AZF_CODEC_PLAYBACK, AZF_CODEC_CAPTURE } };
bool call_function;
if (enable)
call_function = 1;
else {
call_function =
((!chip->codecs[peer_codecs[codec_type].other1]
.running)
&& (!chip->codecs[peer_codecs[codec_type].other2]
.running));
}
if (call_function)
snd_azf3328_ctrl_enable_codecs(chip, enable);
if (!enable)
snd_azf3328_codec_setfmt_lowpower(codec);
codec->running = enable;
}
}
static void
snd_azf3328_codec_setdmaa(struct snd_azf3328 *chip,
struct snd_azf3328_codec_data *codec,
unsigned long addr,
unsigned int period_bytes,
unsigned int buffer_bytes
)
{
WARN_ONCE(period_bytes & 1, "odd period length!?\n");
WARN_ONCE(buffer_bytes != 2 * period_bytes,
"missed our input expectations! %u vs. %u\n",
buffer_bytes, period_bytes);
if (!codec->running) {
unsigned long flags;
u32 area_length;
struct codec_setup_io {
u32 dma_start_1;
u32 dma_start_2;
u32 dma_lengths;
} __attribute__((packed)) setup_io;
area_length = buffer_bytes/2;
setup_io.dma_start_1 = addr;
setup_io.dma_start_2 = addr+area_length;
dev_dbg(chip->card->dev,
"setdma: buffers %08x[%u] / %08x[%u], %u, %u\n",
setup_io.dma_start_1, area_length,
setup_io.dma_start_2, area_length,
period_bytes, buffer_bytes);
setup_io.dma_lengths = (area_length << 16) | (area_length);
spin_lock_irqsave(codec->lock, flags);
snd_azf3328_codec_outl_multi(
codec, IDX_IO_CODEC_DMA_START_1, &setup_io, 3
);
spin_unlock_irqrestore(codec->lock, flags);
}
}
static int
snd_azf3328_pcm_prepare(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_azf3328_codec_data *codec = runtime->private_data;
#if 0
unsigned int size = snd_pcm_lib_buffer_bytes(substream);
unsigned int count = snd_pcm_lib_period_bytes(substream);
#endif
codec->dma_base = runtime->dma_addr;
#if 0
snd_azf3328_codec_setfmt(codec,
runtime->rate,
snd_pcm_format_width(runtime->format),
runtime->channels);
snd_azf3328_codec_setdmaa(chip, codec,
runtime->dma_addr, count, size);
#endif
return 0;
}
static int
snd_azf3328_pcm_trigger(struct snd_pcm_substream *substream, int cmd)
{
struct snd_azf3328 *chip = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_azf3328_codec_data *codec = runtime->private_data;
int result = 0;
u16 flags1;
bool previously_muted = false;
bool is_main_mixer_playback_codec = (AZF_CODEC_PLAYBACK == codec->type);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
dev_dbg(chip->card->dev, "START PCM %s\n", codec->name);
if (is_main_mixer_playback_codec) {
previously_muted =
snd_azf3328_mixer_mute_control_pcm(
chip, 1
);
}
snd_azf3328_codec_setfmt(codec,
runtime->rate,
snd_pcm_format_width(runtime->format),
runtime->channels);
spin_lock(codec->lock);
flags1 = snd_azf3328_codec_inw(codec, IDX_IO_CODEC_DMA_FLAGS);
flags1 &= ~DMA_RESUME;
snd_azf3328_codec_outw(codec, IDX_IO_CODEC_DMA_FLAGS, flags1);
snd_azf3328_codec_outw(codec, IDX_IO_CODEC_IRQTYPE, 0xffff);
spin_unlock(codec->lock);
snd_azf3328_codec_setdmaa(chip, codec, runtime->dma_addr,
snd_pcm_lib_period_bytes(substream),
snd_pcm_lib_buffer_bytes(substream)
);
spin_lock(codec->lock);
#ifdef WIN9X
flags1 |= DMA_RUN_SOMETHING1 | DMA_RUN_SOMETHING2;
snd_azf3328_codec_outw(codec, IDX_IO_CODEC_DMA_FLAGS, flags1);
flags1 |= DMA_RESUME | DMA_EPILOGUE_SOMETHING;
snd_azf3328_codec_outw(codec, IDX_IO_CODEC_DMA_FLAGS, flags1);
#else
snd_azf3328_codec_outw(codec, IDX_IO_CODEC_DMA_FLAGS,
0x0000);
snd_azf3328_codec_outw(codec, IDX_IO_CODEC_DMA_FLAGS,
DMA_RUN_SOMETHING1);
snd_azf3328_codec_outw(codec, IDX_IO_CODEC_DMA_FLAGS,
DMA_RUN_SOMETHING1 |
DMA_RUN_SOMETHING2);
snd_azf3328_codec_outw(codec, IDX_IO_CODEC_DMA_FLAGS,
DMA_RESUME |
SOMETHING_ALMOST_ALWAYS_SET |
DMA_EPILOGUE_SOMETHING |
DMA_SOMETHING_ELSE);
#endif
spin_unlock(codec->lock);
snd_azf3328_ctrl_codec_activity(chip, codec->type, 1);
if (is_main_mixer_playback_codec) {
if (!previously_muted)
snd_azf3328_mixer_mute_control_pcm(
chip, 0
);
}
dev_dbg(chip->card->dev, "PCM STARTED %s\n", codec->name);
break;
case SNDRV_PCM_TRIGGER_RESUME:
dev_dbg(chip->card->dev, "PCM RESUME %s\n", codec->name);
spin_lock(codec->lock);
if (codec->running)
snd_azf3328_codec_outw(codec, IDX_IO_CODEC_DMA_FLAGS,
snd_azf3328_codec_inw(
codec, IDX_IO_CODEC_DMA_FLAGS
) | DMA_RESUME
);
spin_unlock(codec->lock);
break;
case SNDRV_PCM_TRIGGER_STOP:
dev_dbg(chip->card->dev, "PCM STOP %s\n", codec->name);
if (is_main_mixer_playback_codec) {
previously_muted =
snd_azf3328_mixer_mute_control_pcm(
chip, 1
);
}
spin_lock(codec->lock);
flags1 = snd_azf3328_codec_inw(codec, IDX_IO_CODEC_DMA_FLAGS);
flags1 &= ~DMA_RESUME;
snd_azf3328_codec_outw(codec, IDX_IO_CODEC_DMA_FLAGS, flags1);
flags1 |= DMA_RUN_SOMETHING1;
snd_azf3328_codec_outw(codec, IDX_IO_CODEC_DMA_FLAGS, flags1);
flags1 &= ~DMA_RUN_SOMETHING1;
snd_azf3328_codec_outw(codec, IDX_IO_CODEC_DMA_FLAGS, flags1);
spin_unlock(codec->lock);
snd_azf3328_ctrl_codec_activity(chip, codec->type, 0);
if (is_main_mixer_playback_codec) {
if (!previously_muted)
snd_azf3328_mixer_mute_control_pcm(
chip, 0
);
}
dev_dbg(chip->card->dev, "PCM STOPPED %s\n", codec->name);
break;
case SNDRV_PCM_TRIGGER_SUSPEND:
dev_dbg(chip->card->dev, "PCM SUSPEND %s\n", codec->name);
snd_azf3328_codec_outw(codec, IDX_IO_CODEC_DMA_FLAGS,
snd_azf3328_codec_inw(
codec, IDX_IO_CODEC_DMA_FLAGS
) & ~DMA_RESUME
);
break;
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
WARN(1, "FIXME: SNDRV_PCM_TRIGGER_PAUSE_PUSH NIY!\n");
break;
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
WARN(1, "FIXME: SNDRV_PCM_TRIGGER_PAUSE_RELEASE NIY!\n");
break;
default:
WARN(1, "FIXME: unknown trigger mode!\n");
return -EINVAL;
}
return result;
}
static snd_pcm_uframes_t
snd_azf3328_pcm_pointer(struct snd_pcm_substream *substream
)
{
const struct snd_azf3328_codec_data *codec =
substream->runtime->private_data;
unsigned long result;
snd_pcm_uframes_t frmres;
result = snd_azf3328_codec_inl(codec, IDX_IO_CODEC_DMA_CURRPOS);
#ifdef QUERY_HARDWARE
result -= snd_azf3328_codec_inl(codec, IDX_IO_CODEC_DMA_START_1);
#else
result -= codec->dma_base;
#endif
frmres = bytes_to_frames( substream->runtime, result);
dev_dbg(substream->pcm->card->dev, "%08li %s @ 0x%8lx, frames %8ld\n",
jiffies, codec->name, result, frmres);
return frmres;
}
static inline void
snd_azf3328_gameport_irq_enable(struct snd_azf3328 *chip,
bool enable
)
{
snd_azf3328_io_reg_setb(
chip->game_io+IDX_GAME_HWCONFIG,
GAME_HWCFG_IRQ_ENABLE,
enable
);
}
static inline void
snd_azf3328_gameport_legacy_address_enable(struct snd_azf3328 *chip,
bool enable
)
{
snd_azf3328_io_reg_setb(
chip->game_io+IDX_GAME_HWCONFIG,
GAME_HWCFG_LEGACY_ADDRESS_ENABLE,
enable
);
}
static void
snd_azf3328_gameport_set_counter_frequency(struct snd_azf3328 *chip,
unsigned int freq_cfg
)
{
snd_azf3328_io_reg_setb(
chip->game_io+IDX_GAME_HWCONFIG,
0x02,
(freq_cfg & 1) != 0
);
snd_azf3328_io_reg_setb(
chip->game_io+IDX_GAME_HWCONFIG,
0x04,
(freq_cfg & 2) != 0
);
}
static inline void
snd_azf3328_gameport_axis_circuit_enable(struct snd_azf3328 *chip, bool enable)
{
snd_azf3328_ctrl_reg_6AH_update(
chip, IO_6A_SOMETHING2_GAMEPORT, enable
);
}
static inline void
snd_azf3328_gameport_interrupt(struct snd_azf3328 *chip)
{
dev_dbg(chip->card->dev, "gameport irq\n");
snd_azf3328_game_inw(chip, IDX_GAME_AXIS_VALUE);
}
static int
snd_azf3328_gameport_open(struct gameport *gameport, int mode)
{
struct snd_azf3328 *chip = gameport_get_port_data(gameport);
int res;
dev_dbg(chip->card->dev, "gameport_open, mode %d\n", mode);
switch (mode) {
case GAMEPORT_MODE_COOKED:
case GAMEPORT_MODE_RAW:
res = 0;
break;
default:
res = -1;
break;
}
snd_azf3328_gameport_set_counter_frequency(chip,
GAME_HWCFG_ADC_COUNTER_FREQ_STD);
snd_azf3328_gameport_axis_circuit_enable(chip, (res == 0));
return res;
}
static void
snd_azf3328_gameport_close(struct gameport *gameport)
{
struct snd_azf3328 *chip = gameport_get_port_data(gameport);
dev_dbg(chip->card->dev, "gameport_close\n");
snd_azf3328_gameport_set_counter_frequency(chip,
GAME_HWCFG_ADC_COUNTER_FREQ_1_200);
snd_azf3328_gameport_axis_circuit_enable(chip, 0);
}
static int
snd_azf3328_gameport_cooked_read(struct gameport *gameport,
int *axes,
int *buttons
)
{
struct snd_azf3328 *chip = gameport_get_port_data(gameport);
int i;
u8 val;
unsigned long flags;
if (snd_BUG_ON(!chip))
return 0;
spin_lock_irqsave(&chip->reg_lock, flags);
val = snd_azf3328_game_inb(chip, IDX_GAME_LEGACY_COMPATIBLE);
*buttons = (~(val) >> 4) & 0xf;
val = snd_azf3328_game_inb(chip, IDX_GAME_AXES_CONFIG);
if (val & GAME_AXES_SAMPLING_READY) {
for (i = 0; i < ARRAY_SIZE(chip->axes); ++i) {
val = (i << 4) | 0x0f;
snd_azf3328_game_outb(chip, IDX_GAME_AXES_CONFIG, val);
chip->axes[i] = snd_azf3328_game_inw(
chip, IDX_GAME_AXIS_VALUE
);
}
}
val = 0x03;
snd_azf3328_game_outb(chip, IDX_GAME_AXES_CONFIG, val);
snd_azf3328_game_outw(chip, IDX_GAME_AXIS_VALUE, 0xffff);
spin_unlock_irqrestore(&chip->reg_lock, flags);
for (i = 0; i < ARRAY_SIZE(chip->axes); i++) {
axes[i] = chip->axes[i];
if (axes[i] == 0xffff)
axes[i] = -1;
}
dev_dbg(chip->card->dev, "cooked_read: axes %d %d %d %d buttons %d\n",
axes[0], axes[1], axes[2], axes[3], *buttons);
return 0;
}
static int
snd_azf3328_gameport(struct snd_azf3328 *chip, int dev)
{
struct gameport *gp;
chip->gameport = gp = gameport_allocate_port();
if (!gp) {
dev_err(chip->card->dev, "cannot alloc memory for gameport\n");
return -ENOMEM;
}
gameport_set_name(gp, "AZF3328 Gameport");
gameport_set_phys(gp, "pci%s/gameport0", pci_name(chip->pci));
gameport_set_dev_parent(gp, &chip->pci->dev);
gp->io = chip->game_io;
gameport_set_port_data(gp, chip);
gp->open = snd_azf3328_gameport_open;
gp->close = snd_azf3328_gameport_close;
gp->fuzz = 16;
gp->cooked_read = snd_azf3328_gameport_cooked_read;
snd_azf3328_gameport_legacy_address_enable(chip, 0);
snd_azf3328_gameport_set_counter_frequency(chip,
GAME_HWCFG_ADC_COUNTER_FREQ_1_200);
snd_azf3328_gameport_axis_circuit_enable(chip, 0);
gameport_register_port(chip->gameport);
return 0;
}
static void
snd_azf3328_gameport_free(struct snd_azf3328 *chip)
{
if (chip->gameport) {
gameport_unregister_port(chip->gameport);
chip->gameport = NULL;
}
snd_azf3328_gameport_irq_enable(chip, 0);
}
static inline int
snd_azf3328_gameport(struct snd_azf3328 *chip, int dev) { return -ENOSYS; }
static inline void
snd_azf3328_gameport_free(struct snd_azf3328 *chip) { }
static inline void
snd_azf3328_gameport_interrupt(struct snd_azf3328 *chip)
{
dev_warn(chip->card->dev, "huh, game port IRQ occurred!?\n");
}
static inline void
snd_azf3328_irq_log_unknown_type(struct snd_azf3328 *chip, u8 which)
{
dev_dbg(chip->card->dev,
"unknown IRQ type (%x) occurred, please report!\n",
which);
}
static inline void
snd_azf3328_pcm_interrupt(struct snd_azf3328 *chip,
const struct snd_azf3328_codec_data *first_codec,
u8 status
)
{
u8 which;
enum snd_azf3328_codec_type codec_type;
const struct snd_azf3328_codec_data *codec = first_codec;
for (codec_type = AZF_CODEC_PLAYBACK;
codec_type <= AZF_CODEC_I2S_OUT;
++codec_type, ++codec) {
if (!(status & (1 << codec_type)))
continue;
spin_lock(codec->lock);
which = snd_azf3328_codec_inb(codec, IDX_IO_CODEC_IRQTYPE);
snd_azf3328_codec_outb(codec, IDX_IO_CODEC_IRQTYPE, which);
spin_unlock(codec->lock);
if (codec->substream) {
snd_pcm_period_elapsed(codec->substream);
dev_dbg(chip->card->dev, "%s period done (#%x), @ %x\n",
codec->name,
which,
snd_azf3328_codec_inl(
codec, IDX_IO_CODEC_DMA_CURRPOS));
} else
dev_warn(chip->card->dev, "irq handler problem!\n");
if (which & IRQ_SOMETHING)
snd_azf3328_irq_log_unknown_type(chip, which);
}
}
static irqreturn_t
snd_azf3328_interrupt(int irq, void *dev_id)
{
struct snd_azf3328 *chip = dev_id;
u8 status;
static unsigned long irq_count;
status = snd_azf3328_ctrl_inb(chip, IDX_IO_IRQSTATUS);
if (!(status &
(IRQ_PLAYBACK|IRQ_RECORDING|IRQ_I2S_OUT
|IRQ_GAMEPORT|IRQ_MPU401|IRQ_TIMER)
))
return IRQ_NONE;
dev_dbg(chip->card->dev,
"irq_count %ld! IDX_IO_IRQSTATUS %04x\n",
irq_count++ ,
status);
if (status & IRQ_TIMER) {
if (chip->timer)
snd_timer_interrupt(chip->timer, chip->timer->sticks);
spin_lock(&chip->reg_lock);
snd_azf3328_ctrl_outb(chip, IDX_IO_TIMER_VALUE + 3, 0x07);
spin_unlock(&chip->reg_lock);
dev_dbg(chip->card->dev, "timer IRQ\n");
}
if (status & (IRQ_PLAYBACK|IRQ_RECORDING|IRQ_I2S_OUT))
snd_azf3328_pcm_interrupt(chip, chip->codecs, status);
if (status & IRQ_GAMEPORT)
snd_azf3328_gameport_interrupt(chip);
if (status & IRQ_MPU401) {
snd_mpu401_uart_interrupt(irq, chip->rmidi->private_data);
dev_dbg(chip->card->dev, "MPU401 IRQ\n");
}
return IRQ_HANDLED;
}
static int
snd_azf3328_pcm_open(struct snd_pcm_substream *substream,
enum snd_azf3328_codec_type codec_type
)
{
struct snd_azf3328 *chip = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_azf3328_codec_data *codec = &chip->codecs[codec_type];
codec->substream = substream;
runtime->hw = snd_azf3328_hardware;
snd_pcm_hw_constraint_list(runtime, 0, SNDRV_PCM_HW_PARAM_RATE,
&snd_azf3328_hw_constraints_rates);
runtime->private_data = codec;
return 0;
}
static int
snd_azf3328_pcm_playback_open(struct snd_pcm_substream *substream)
{
return snd_azf3328_pcm_open(substream, AZF_CODEC_PLAYBACK);
}
static int
snd_azf3328_pcm_capture_open(struct snd_pcm_substream *substream)
{
return snd_azf3328_pcm_open(substream, AZF_CODEC_CAPTURE);
}
static int
snd_azf3328_pcm_i2s_out_open(struct snd_pcm_substream *substream)
{
return snd_azf3328_pcm_open(substream, AZF_CODEC_I2S_OUT);
}
static int
snd_azf3328_pcm_close(struct snd_pcm_substream *substream
)
{
struct snd_azf3328_codec_data *codec =
substream->runtime->private_data;
codec->substream = NULL;
return 0;
}
static int
snd_azf3328_pcm(struct snd_azf3328 *chip)
{
enum { AZF_PCMDEV_STD, AZF_PCMDEV_I2S_OUT, NUM_AZF_PCMDEVS };
struct snd_pcm *pcm;
int err;
err = snd_pcm_new(chip->card, "AZF3328 DSP", AZF_PCMDEV_STD,
1, 1, &pcm);
if (err < 0)
return err;
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK,
&snd_azf3328_playback_ops);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE,
&snd_azf3328_capture_ops);
pcm->private_data = chip;
pcm->info_flags = 0;
strcpy(pcm->name, chip->card->shortname);
chip->pcm[AZF_CODEC_PLAYBACK] = pcm;
chip->pcm[AZF_CODEC_CAPTURE] = pcm;
snd_pcm_lib_preallocate_pages_for_all(pcm, SNDRV_DMA_TYPE_DEV,
snd_dma_pci_data(chip->pci),
64*1024, 64*1024);
err = snd_pcm_new(chip->card, "AZF3328 I2S OUT", AZF_PCMDEV_I2S_OUT,
1, 0, &pcm);
if (err < 0)
return err;
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK,
&snd_azf3328_i2s_out_ops);
pcm->private_data = chip;
pcm->info_flags = 0;
strcpy(pcm->name, chip->card->shortname);
chip->pcm[AZF_CODEC_I2S_OUT] = pcm;
snd_pcm_lib_preallocate_pages_for_all(pcm, SNDRV_DMA_TYPE_DEV,
snd_dma_pci_data(chip->pci),
64*1024, 64*1024);
return 0;
}
static int
snd_azf3328_timer_start(struct snd_timer *timer)
{
struct snd_azf3328 *chip;
unsigned long flags;
unsigned int delay;
chip = snd_timer_chip(timer);
delay = ((timer->sticks * seqtimer_scaling) - 1) & TIMER_VALUE_MASK;
if (delay < 49) {
dev_dbg(chip->card->dev, "delay was too low (%d)!\n", delay);
delay = 49;
}
dev_dbg(chip->card->dev, "setting timer countdown value %d\n", delay);
delay |= TIMER_COUNTDOWN_ENABLE | TIMER_IRQ_ENABLE;
spin_lock_irqsave(&chip->reg_lock, flags);
snd_azf3328_ctrl_outl(chip, IDX_IO_TIMER_VALUE, delay);
spin_unlock_irqrestore(&chip->reg_lock, flags);
return 0;
}
static int
snd_azf3328_timer_stop(struct snd_timer *timer)
{
struct snd_azf3328 *chip;
unsigned long flags;
chip = snd_timer_chip(timer);
spin_lock_irqsave(&chip->reg_lock, flags);
snd_azf3328_ctrl_outb(chip, IDX_IO_TIMER_VALUE + 3, 0x04);
spin_unlock_irqrestore(&chip->reg_lock, flags);
return 0;
}
static int
snd_azf3328_timer_precise_resolution(struct snd_timer *timer,
unsigned long *num, unsigned long *den)
{
*num = 1;
*den = 1024000 / seqtimer_scaling;
return 0;
}
static int
snd_azf3328_timer(struct snd_azf3328 *chip, int device)
{
struct snd_timer *timer = NULL;
struct snd_timer_id tid;
int err;
tid.dev_class = SNDRV_TIMER_CLASS_CARD;
tid.dev_sclass = SNDRV_TIMER_SCLASS_NONE;
tid.card = chip->card->number;
tid.device = device;
tid.subdevice = 0;
snd_azf3328_timer_hw.resolution *= seqtimer_scaling;
snd_azf3328_timer_hw.ticks /= seqtimer_scaling;
err = snd_timer_new(chip->card, "AZF3328", &tid, &timer);
if (err < 0)
goto out;
strcpy(timer->name, "AZF3328 timer");
timer->private_data = chip;
timer->hw = snd_azf3328_timer_hw;
chip->timer = timer;
snd_azf3328_timer_stop(timer);
err = 0;
out:
return err;
}
static int
snd_azf3328_free(struct snd_azf3328 *chip)
{
if (chip->irq < 0)
goto __end_hw;
snd_azf3328_mixer_reset(chip);
snd_azf3328_timer_stop(chip->timer);
snd_azf3328_gameport_free(chip);
if (chip->irq >= 0)
synchronize_irq(chip->irq);
__end_hw:
if (chip->irq >= 0)
free_irq(chip->irq, chip);
pci_release_regions(chip->pci);
pci_disable_device(chip->pci);
kfree(chip);
return 0;
}
static int
snd_azf3328_dev_free(struct snd_device *device)
{
struct snd_azf3328 *chip = device->device_data;
return snd_azf3328_free(chip);
}
static inline void
snd_azf3328_debug_show_ports(const struct snd_azf3328 *chip)
{
u16 tmp;
dev_dbg(chip->card->dev,
"ctrl_io 0x%lx, game_io 0x%lx, mpu_io 0x%lx, "
"opl3_io 0x%lx, mixer_io 0x%lx, irq %d\n",
chip->ctrl_io, chip->game_io, chip->mpu_io,
chip->opl3_io, chip->mixer_io, chip->irq);
dev_dbg(chip->card->dev,
"game %02x %02x %02x %02x %02x %02x\n",
snd_azf3328_game_inb(chip, 0),
snd_azf3328_game_inb(chip, 1),
snd_azf3328_game_inb(chip, 2),
snd_azf3328_game_inb(chip, 3),
snd_azf3328_game_inb(chip, 4),
snd_azf3328_game_inb(chip, 5));
for (tmp = 0; tmp < 0x07; tmp += 1)
dev_dbg(chip->card->dev,
"mpu_io 0x%04x\n", inb(chip->mpu_io + tmp));
for (tmp = 0; tmp <= 0x07; tmp += 1)
dev_dbg(chip->card->dev,
"0x%02x: game200 0x%04x, game208 0x%04x\n",
tmp, inb(0x200 + tmp), inb(0x208 + tmp));
for (tmp = 0; tmp <= 0x01; tmp += 1)
dev_dbg(chip->card->dev,
"0x%02x: mpu300 0x%04x, mpu310 0x%04x, mpu320 0x%04x, "
"mpu330 0x%04x opl388 0x%04x opl38c 0x%04x\n",
tmp,
inb(0x300 + tmp),
inb(0x310 + tmp),
inb(0x320 + tmp),
inb(0x330 + tmp),
inb(0x388 + tmp),
inb(0x38c + tmp));
for (tmp = 0; tmp < AZF_IO_SIZE_CTRL; tmp += 2)
dev_dbg(chip->card->dev,
"ctrl 0x%02x: 0x%04x\n",
tmp, snd_azf3328_ctrl_inw(chip, tmp));
for (tmp = 0; tmp < AZF_IO_SIZE_MIXER; tmp += 2)
dev_dbg(chip->card->dev,
"mixer 0x%02x: 0x%04x\n",
tmp, snd_azf3328_mixer_inw(chip, tmp));
}
static int
snd_azf3328_create(struct snd_card *card,
struct pci_dev *pci,
unsigned long device_type,
struct snd_azf3328 **rchip)
{
struct snd_azf3328 *chip;
int err;
static struct snd_device_ops ops = {
.dev_free = snd_azf3328_dev_free,
};
u8 dma_init;
enum snd_azf3328_codec_type codec_type;
struct snd_azf3328_codec_data *codec_setup;
*rchip = NULL;
err = pci_enable_device(pci);
if (err < 0)
return err;
chip = kzalloc(sizeof(*chip), GFP_KERNEL);
if (chip == NULL) {
err = -ENOMEM;
goto out_err;
}
spin_lock_init(&chip->reg_lock);
chip->card = card;
chip->pci = pci;
chip->irq = -1;
if (dma_set_mask(&pci->dev, DMA_BIT_MASK(24)) < 0 ||
dma_set_coherent_mask(&pci->dev, DMA_BIT_MASK(24)) < 0) {
dev_err(card->dev,
"architecture does not support 24bit PCI busmaster DMA\n"
);
err = -ENXIO;
goto out_err;
}
err = pci_request_regions(pci, "Aztech AZF3328");
if (err < 0)
goto out_err;
chip->ctrl_io = pci_resource_start(pci, 0);
chip->game_io = pci_resource_start(pci, 1);
chip->mpu_io = pci_resource_start(pci, 2);
chip->opl3_io = pci_resource_start(pci, 3);
chip->mixer_io = pci_resource_start(pci, 4);
codec_setup = &chip->codecs[AZF_CODEC_PLAYBACK];
codec_setup->io_base = chip->ctrl_io + AZF_IO_OFFS_CODEC_PLAYBACK;
codec_setup->lock = &chip->reg_lock;
codec_setup->type = AZF_CODEC_PLAYBACK;
codec_setup->name = "PLAYBACK";
codec_setup = &chip->codecs[AZF_CODEC_CAPTURE];
codec_setup->io_base = chip->ctrl_io + AZF_IO_OFFS_CODEC_CAPTURE;
codec_setup->lock = &chip->reg_lock;
codec_setup->type = AZF_CODEC_CAPTURE;
codec_setup->name = "CAPTURE";
codec_setup = &chip->codecs[AZF_CODEC_I2S_OUT];
codec_setup->io_base = chip->ctrl_io + AZF_IO_OFFS_CODEC_I2S_OUT;
codec_setup->lock = &chip->reg_lock;
codec_setup->type = AZF_CODEC_I2S_OUT;
codec_setup->name = "I2S_OUT";
if (request_irq(pci->irq, snd_azf3328_interrupt,
IRQF_SHARED, KBUILD_MODNAME, chip)) {
dev_err(card->dev, "unable to grab IRQ %d\n", pci->irq);
err = -EBUSY;
goto out_err;
}
chip->irq = pci->irq;
pci_set_master(pci);
synchronize_irq(chip->irq);
snd_azf3328_debug_show_ports(chip);
err = snd_device_new(card, SNDRV_DEV_LOWLEVEL, chip, &ops);
if (err < 0)
goto out_err;
err = snd_azf3328_mixer_new(chip);
if (err < 0)
goto out_err;
dma_init = DMA_RUN_SOMETHING2|DMA_EPILOGUE_SOMETHING|DMA_SOMETHING_ELSE;
for (codec_type = AZF_CODEC_PLAYBACK;
codec_type <= AZF_CODEC_I2S_OUT; ++codec_type) {
struct snd_azf3328_codec_data *codec =
&chip->codecs[codec_type];
codec->running = 1;
snd_azf3328_ctrl_codec_activity(chip, codec_type, 0);
spin_lock_irq(codec->lock);
snd_azf3328_codec_outb(codec, IDX_IO_CODEC_DMA_FLAGS,
dma_init);
spin_unlock_irq(codec->lock);
}
*rchip = chip;
err = 0;
goto out;
out_err:
if (chip)
snd_azf3328_free(chip);
pci_disable_device(pci);
out:
return err;
}
static int
snd_azf3328_probe(struct pci_dev *pci, const struct pci_device_id *pci_id)
{
static int dev;
struct snd_card *card;
struct snd_azf3328 *chip;
struct snd_opl3 *opl3;
int err;
if (dev >= SNDRV_CARDS) {
err = -ENODEV;
goto out;
}
if (!enable[dev]) {
dev++;
err = -ENOENT;
goto out;
}
err = snd_card_new(&pci->dev, index[dev], id[dev], THIS_MODULE,
0, &card);
if (err < 0)
goto out;
strcpy(card->driver, "AZF3328");
strcpy(card->shortname, "Aztech AZF3328 (PCI168)");
err = snd_azf3328_create(card, pci, pci_id->driver_data, &chip);
if (err < 0)
goto out_err;
card->private_data = chip;
err = snd_mpu401_uart_new(
card, 0,
MPU401_HW_AZT2320, chip->mpu_io,
MPU401_INFO_INTEGRATED | MPU401_INFO_IRQ_HOOK,
-1, &chip->rmidi
);
if (err < 0) {
dev_err(card->dev, "no MPU-401 device at 0x%lx?\n",
chip->mpu_io
);
goto out_err;
}
err = snd_azf3328_timer(chip, 0);
if (err < 0)
goto out_err;
err = snd_azf3328_pcm(chip);
if (err < 0)
goto out_err;
if (snd_opl3_create(card, chip->opl3_io, chip->opl3_io+2,
OPL3_HW_AUTO, 1, &opl3) < 0) {
dev_err(card->dev, "no OPL3 device at 0x%lx-0x%lx?\n",
chip->opl3_io, chip->opl3_io+2
);
} else {
err = snd_opl3_timer_new(opl3, 1, 2);
if (err < 0)
goto out_err;
err = snd_opl3_hwdep_new(opl3, 0, 1, NULL);
if (err < 0)
goto out_err;
opl3->private_data = chip;
}
sprintf(card->longname, "%s at 0x%lx, irq %i",
card->shortname, chip->ctrl_io, chip->irq);
err = snd_card_register(card);
if (err < 0)
goto out_err;
#ifdef MODULE
dev_info(card->dev,
"Sound driver for Aztech AZF3328-based soundcards such as PCI168.\n");
dev_info(card->dev,
"Hardware was completely undocumented, unfortunately.\n");
dev_info(card->dev,
"Feel free to contact andi AT lisas.de for bug reports etc.!\n");
dev_info(card->dev,
"User-scalable sequencer timer set to %dHz (1024000Hz / %d).\n",
1024000 / seqtimer_scaling, seqtimer_scaling);
#endif
snd_azf3328_gameport(chip, dev);
pci_set_drvdata(pci, card);
dev++;
err = 0;
goto out;
out_err:
dev_err(card->dev, "something failed, exiting\n");
snd_card_free(card);
out:
return err;
}
static void
snd_azf3328_remove(struct pci_dev *pci)
{
snd_card_free(pci_get_drvdata(pci));
}
static inline void
snd_azf3328_suspend_regs(const struct snd_azf3328 *chip,
unsigned long io_addr, unsigned count, u32 *saved_regs)
{
unsigned reg;
for (reg = 0; reg < count; ++reg) {
*saved_regs = inl(io_addr);
dev_dbg(chip->card->dev, "suspend: io 0x%04lx: 0x%08x\n",
io_addr, *saved_regs);
++saved_regs;
io_addr += sizeof(*saved_regs);
}
}
static inline void
snd_azf3328_resume_regs(const struct snd_azf3328 *chip,
const u32 *saved_regs,
unsigned long io_addr,
unsigned count
)
{
unsigned reg;
for (reg = 0; reg < count; ++reg) {
outl(*saved_regs, io_addr);
dev_dbg(chip->card->dev,
"resume: io 0x%04lx: 0x%08x --> 0x%08x\n",
io_addr, *saved_regs, inl(io_addr));
++saved_regs;
io_addr += sizeof(*saved_regs);
}
}
static inline void
snd_azf3328_suspend_ac97(struct snd_azf3328 *chip)
{
#ifdef AZF_USE_AC97_LAYER
snd_ac97_suspend(chip->ac97);
#else
snd_azf3328_suspend_regs(chip, chip->mixer_io,
ARRAY_SIZE(chip->saved_regs_mixer), chip->saved_regs_mixer);
snd_azf3328_mixer_mute_control_master(chip, 1);
snd_azf3328_mixer_mute_control_pcm(chip, 1);
#endif
}
static inline void
snd_azf3328_resume_ac97(const struct snd_azf3328 *chip)
{
#ifdef AZF_USE_AC97_LAYER
snd_ac97_resume(chip->ac97);
#else
snd_azf3328_resume_regs(chip, chip->saved_regs_mixer, chip->mixer_io,
ARRAY_SIZE(chip->saved_regs_mixer));
outw(((u16 *)chip->saved_regs_mixer)[1], chip->mixer_io + 2);
#endif
}
static int
snd_azf3328_suspend(struct device *dev)
{
struct snd_card *card = dev_get_drvdata(dev);
struct snd_azf3328 *chip = card->private_data;
u16 *saved_regs_ctrl_u16;
snd_power_change_state(card, SNDRV_CTL_POWER_D3hot);
snd_pcm_suspend_all(chip->pcm[AZF_CODEC_PLAYBACK]);
snd_pcm_suspend_all(chip->pcm[AZF_CODEC_I2S_OUT]);
snd_azf3328_suspend_ac97(chip);
snd_azf3328_suspend_regs(chip, chip->ctrl_io,
ARRAY_SIZE(chip->saved_regs_ctrl), chip->saved_regs_ctrl);
saved_regs_ctrl_u16 = (u16 *)chip->saved_regs_ctrl;
saved_regs_ctrl_u16[IDX_IO_6AH / 2] = chip->shadow_reg_ctrl_6AH;
snd_azf3328_suspend_regs(chip, chip->game_io,
ARRAY_SIZE(chip->saved_regs_game), chip->saved_regs_game);
snd_azf3328_suspend_regs(chip, chip->mpu_io,
ARRAY_SIZE(chip->saved_regs_mpu), chip->saved_regs_mpu);
snd_azf3328_suspend_regs(chip, chip->opl3_io,
ARRAY_SIZE(chip->saved_regs_opl3), chip->saved_regs_opl3);
return 0;
}
static int
snd_azf3328_resume(struct device *dev)
{
struct snd_card *card = dev_get_drvdata(dev);
const struct snd_azf3328 *chip = card->private_data;
snd_azf3328_resume_regs(chip, chip->saved_regs_game, chip->game_io,
ARRAY_SIZE(chip->saved_regs_game));
snd_azf3328_resume_regs(chip, chip->saved_regs_mpu, chip->mpu_io,
ARRAY_SIZE(chip->saved_regs_mpu));
snd_azf3328_resume_regs(chip, chip->saved_regs_opl3, chip->opl3_io,
ARRAY_SIZE(chip->saved_regs_opl3));
snd_azf3328_resume_ac97(chip);
snd_azf3328_resume_regs(chip, chip->saved_regs_ctrl, chip->ctrl_io,
ARRAY_SIZE(chip->saved_regs_ctrl));
snd_power_change_state(card, SNDRV_CTL_POWER_D0);
return 0;
}
