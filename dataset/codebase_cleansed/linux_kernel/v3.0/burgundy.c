static inline void
snd_pmac_burgundy_busy_wait(struct snd_pmac *chip)
{
int timeout = 50;
while ((in_le32(&chip->awacs->codec_ctrl) & MASK_NEWECMD) && timeout--)
udelay(1);
if (timeout < 0)
printk(KERN_DEBUG "burgundy_busy_wait: timeout\n");
}
static inline void
snd_pmac_burgundy_extend_wait(struct snd_pmac *chip)
{
int timeout;
timeout = 50;
while (!(in_le32(&chip->awacs->codec_stat) & MASK_EXTEND) && timeout--)
udelay(1);
if (timeout < 0)
printk(KERN_DEBUG "burgundy_extend_wait: timeout #1\n");
timeout = 50;
while ((in_le32(&chip->awacs->codec_stat) & MASK_EXTEND) && timeout--)
udelay(1);
if (timeout < 0)
printk(KERN_DEBUG "burgundy_extend_wait: timeout #2\n");
}
static void
snd_pmac_burgundy_wcw(struct snd_pmac *chip, unsigned addr, unsigned val)
{
out_le32(&chip->awacs->codec_ctrl, addr + 0x200c00 + (val & 0xff));
snd_pmac_burgundy_busy_wait(chip);
out_le32(&chip->awacs->codec_ctrl, addr + 0x200d00 +((val>>8) & 0xff));
snd_pmac_burgundy_busy_wait(chip);
out_le32(&chip->awacs->codec_ctrl, addr + 0x200e00 +((val>>16) & 0xff));
snd_pmac_burgundy_busy_wait(chip);
out_le32(&chip->awacs->codec_ctrl, addr + 0x200f00 +((val>>24) & 0xff));
snd_pmac_burgundy_busy_wait(chip);
}
static unsigned
snd_pmac_burgundy_rcw(struct snd_pmac *chip, unsigned addr)
{
unsigned val = 0;
unsigned long flags;
spin_lock_irqsave(&chip->reg_lock, flags);
out_le32(&chip->awacs->codec_ctrl, addr + 0x100000);
snd_pmac_burgundy_busy_wait(chip);
snd_pmac_burgundy_extend_wait(chip);
val += (in_le32(&chip->awacs->codec_stat) >> 4) & 0xff;
out_le32(&chip->awacs->codec_ctrl, addr + 0x100100);
snd_pmac_burgundy_busy_wait(chip);
snd_pmac_burgundy_extend_wait(chip);
val += ((in_le32(&chip->awacs->codec_stat)>>4) & 0xff) <<8;
out_le32(&chip->awacs->codec_ctrl, addr + 0x100200);
snd_pmac_burgundy_busy_wait(chip);
snd_pmac_burgundy_extend_wait(chip);
val += ((in_le32(&chip->awacs->codec_stat)>>4) & 0xff) <<16;
out_le32(&chip->awacs->codec_ctrl, addr + 0x100300);
snd_pmac_burgundy_busy_wait(chip);
snd_pmac_burgundy_extend_wait(chip);
val += ((in_le32(&chip->awacs->codec_stat)>>4) & 0xff) <<24;
spin_unlock_irqrestore(&chip->reg_lock, flags);
return val;
}
static void
snd_pmac_burgundy_wcb(struct snd_pmac *chip, unsigned int addr,
unsigned int val)
{
out_le32(&chip->awacs->codec_ctrl, addr + 0x300000 + (val & 0xff));
snd_pmac_burgundy_busy_wait(chip);
}
static unsigned
snd_pmac_burgundy_rcb(struct snd_pmac *chip, unsigned int addr)
{
unsigned val = 0;
unsigned long flags;
spin_lock_irqsave(&chip->reg_lock, flags);
out_le32(&chip->awacs->codec_ctrl, addr + 0x100000);
snd_pmac_burgundy_busy_wait(chip);
snd_pmac_burgundy_extend_wait(chip);
val += (in_le32(&chip->awacs->codec_stat) >> 4) & 0xff;
spin_unlock_irqrestore(&chip->reg_lock, flags);
return val;
}
static void
snd_pmac_burgundy_write_volume(struct snd_pmac *chip, unsigned int address,
long *volume, int shift)
{
int hardvolume, lvolume, rvolume;
if (volume[0] < 0 || volume[0] > 100 ||
volume[1] < 0 || volume[1] > 100)
return;
lvolume = volume[0] ? volume[0] + BURGUNDY_VOLUME_OFFSET : 0;
rvolume = volume[1] ? volume[1] + BURGUNDY_VOLUME_OFFSET : 0;
hardvolume = lvolume + (rvolume << shift);
if (shift == 8)
hardvolume |= hardvolume << 16;
snd_pmac_burgundy_wcw(chip, address, hardvolume);
}
static void
snd_pmac_burgundy_read_volume(struct snd_pmac *chip, unsigned int address,
long *volume, int shift)
{
int wvolume;
wvolume = snd_pmac_burgundy_rcw(chip, address);
volume[0] = wvolume & 0xff;
if (volume[0] >= BURGUNDY_VOLUME_OFFSET)
volume[0] -= BURGUNDY_VOLUME_OFFSET;
else
volume[0] = 0;
volume[1] = (wvolume >> shift) & 0xff;
if (volume[1] >= BURGUNDY_VOLUME_OFFSET)
volume[1] -= BURGUNDY_VOLUME_OFFSET;
else
volume[1] = 0;
}
static int snd_pmac_burgundy_info_volume(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 2;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 100;
return 0;
}
static int snd_pmac_burgundy_get_volume(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_pmac *chip = snd_kcontrol_chip(kcontrol);
unsigned int addr = BASE2ADDR(kcontrol->private_value & 0xff);
int shift = (kcontrol->private_value >> 8) & 0xff;
snd_pmac_burgundy_read_volume(chip, addr,
ucontrol->value.integer.value, shift);
return 0;
}
static int snd_pmac_burgundy_put_volume(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_pmac *chip = snd_kcontrol_chip(kcontrol);
unsigned int addr = BASE2ADDR(kcontrol->private_value & 0xff);
int shift = (kcontrol->private_value >> 8) & 0xff;
long nvoices[2];
snd_pmac_burgundy_write_volume(chip, addr,
ucontrol->value.integer.value, shift);
snd_pmac_burgundy_read_volume(chip, addr, nvoices, shift);
return (nvoices[0] != ucontrol->value.integer.value[0] ||
nvoices[1] != ucontrol->value.integer.value[1]);
}
static void
snd_pmac_burgundy_write_volume_2b(struct snd_pmac *chip, unsigned int address,
long *volume, int off)
{
int lvolume, rvolume;
off |= off << 2;
lvolume = volume[0] ? volume[0] + BURGUNDY_VOLUME_OFFSET : 0;
rvolume = volume[1] ? volume[1] + BURGUNDY_VOLUME_OFFSET : 0;
snd_pmac_burgundy_wcb(chip, address + off, lvolume);
snd_pmac_burgundy_wcb(chip, address + off + 0x500, rvolume);
}
static void
snd_pmac_burgundy_read_volume_2b(struct snd_pmac *chip, unsigned int address,
long *volume, int off)
{
volume[0] = snd_pmac_burgundy_rcb(chip, address + off);
if (volume[0] >= BURGUNDY_VOLUME_OFFSET)
volume[0] -= BURGUNDY_VOLUME_OFFSET;
else
volume[0] = 0;
volume[1] = snd_pmac_burgundy_rcb(chip, address + off + 0x100);
if (volume[1] >= BURGUNDY_VOLUME_OFFSET)
volume[1] -= BURGUNDY_VOLUME_OFFSET;
else
volume[1] = 0;
}
static int snd_pmac_burgundy_info_volume_2b(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 2;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 100;
return 0;
}
static int snd_pmac_burgundy_get_volume_2b(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_pmac *chip = snd_kcontrol_chip(kcontrol);
unsigned int addr = BASE2ADDR(kcontrol->private_value & 0xff);
int off = kcontrol->private_value & 0x300;
snd_pmac_burgundy_read_volume_2b(chip, addr,
ucontrol->value.integer.value, off);
return 0;
}
static int snd_pmac_burgundy_put_volume_2b(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_pmac *chip = snd_kcontrol_chip(kcontrol);
unsigned int addr = BASE2ADDR(kcontrol->private_value & 0xff);
int off = kcontrol->private_value & 0x300;
long nvoices[2];
snd_pmac_burgundy_write_volume_2b(chip, addr,
ucontrol->value.integer.value, off);
snd_pmac_burgundy_read_volume_2b(chip, addr, nvoices, off);
return (nvoices[0] != ucontrol->value.integer.value[0] ||
nvoices[1] != ucontrol->value.integer.value[1]);
}
static int snd_pmac_burgundy_info_gain(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
int stereo = (kcontrol->private_value >> 24) & 1;
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = stereo + 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 15;
return 0;
}
static int snd_pmac_burgundy_get_gain(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_pmac *chip = snd_kcontrol_chip(kcontrol);
unsigned int addr = BASE2ADDR(kcontrol->private_value & 0xff);
int stereo = (kcontrol->private_value >> 24) & 1;
int atten = (kcontrol->private_value >> 25) & 1;
int oval;
oval = snd_pmac_burgundy_rcb(chip, addr);
if (atten)
oval = ~oval & 0xff;
ucontrol->value.integer.value[0] = oval & 0xf;
if (stereo)
ucontrol->value.integer.value[1] = (oval >> 4) & 0xf;
return 0;
}
static int snd_pmac_burgundy_put_gain(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_pmac *chip = snd_kcontrol_chip(kcontrol);
unsigned int addr = BASE2ADDR(kcontrol->private_value & 0xff);
int stereo = (kcontrol->private_value >> 24) & 1;
int atten = (kcontrol->private_value >> 25) & 1;
int oval, val;
oval = snd_pmac_burgundy_rcb(chip, addr);
if (atten)
oval = ~oval & 0xff;
val = ucontrol->value.integer.value[0];
if (stereo)
val |= ucontrol->value.integer.value[1] << 4;
else
val |= ucontrol->value.integer.value[0] << 4;
if (atten)
val = ~val & 0xff;
snd_pmac_burgundy_wcb(chip, addr, val);
return val != oval;
}
static int snd_pmac_burgundy_info_switch_w(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
int stereo = (kcontrol->private_value >> 24) & 1;
uinfo->type = SNDRV_CTL_ELEM_TYPE_BOOLEAN;
uinfo->count = stereo + 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 1;
return 0;
}
static int snd_pmac_burgundy_get_switch_w(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_pmac *chip = snd_kcontrol_chip(kcontrol);
unsigned int addr = BASE2ADDR((kcontrol->private_value >> 16) & 0xff);
int lmask = 1 << (kcontrol->private_value & 0xff);
int rmask = 1 << ((kcontrol->private_value >> 8) & 0xff);
int stereo = (kcontrol->private_value >> 24) & 1;
int val = snd_pmac_burgundy_rcw(chip, addr);
ucontrol->value.integer.value[0] = (val & lmask) ? 1 : 0;
if (stereo)
ucontrol->value.integer.value[1] = (val & rmask) ? 1 : 0;
return 0;
}
static int snd_pmac_burgundy_put_switch_w(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_pmac *chip = snd_kcontrol_chip(kcontrol);
unsigned int addr = BASE2ADDR((kcontrol->private_value >> 16) & 0xff);
int lmask = 1 << (kcontrol->private_value & 0xff);
int rmask = 1 << ((kcontrol->private_value >> 8) & 0xff);
int stereo = (kcontrol->private_value >> 24) & 1;
int val, oval;
oval = snd_pmac_burgundy_rcw(chip, addr);
val = oval & ~(lmask | (stereo ? rmask : 0));
if (ucontrol->value.integer.value[0])
val |= lmask;
if (stereo && ucontrol->value.integer.value[1])
val |= rmask;
snd_pmac_burgundy_wcw(chip, addr, val);
return val != oval;
}
static int snd_pmac_burgundy_info_switch_b(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
int stereo = (kcontrol->private_value >> 24) & 1;
uinfo->type = SNDRV_CTL_ELEM_TYPE_BOOLEAN;
uinfo->count = stereo + 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 1;
return 0;
}
static int snd_pmac_burgundy_get_switch_b(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_pmac *chip = snd_kcontrol_chip(kcontrol);
unsigned int addr = BASE2ADDR((kcontrol->private_value >> 16) & 0xff);
int lmask = kcontrol->private_value & 0xff;
int rmask = (kcontrol->private_value >> 8) & 0xff;
int stereo = (kcontrol->private_value >> 24) & 1;
int val = snd_pmac_burgundy_rcb(chip, addr);
ucontrol->value.integer.value[0] = (val & lmask) ? 1 : 0;
if (stereo)
ucontrol->value.integer.value[1] = (val & rmask) ? 1 : 0;
return 0;
}
static int snd_pmac_burgundy_put_switch_b(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_pmac *chip = snd_kcontrol_chip(kcontrol);
unsigned int addr = BASE2ADDR((kcontrol->private_value >> 16) & 0xff);
int lmask = kcontrol->private_value & 0xff;
int rmask = (kcontrol->private_value >> 8) & 0xff;
int stereo = (kcontrol->private_value >> 24) & 1;
int val, oval;
oval = snd_pmac_burgundy_rcb(chip, addr);
val = oval & ~(lmask | rmask);
if (ucontrol->value.integer.value[0])
val |= lmask;
if (stereo && ucontrol->value.integer.value[1])
val |= rmask;
snd_pmac_burgundy_wcb(chip, addr, val);
return val != oval;
}
static int snd_pmac_burgundy_detect_headphone(struct snd_pmac *chip)
{
return (in_le32(&chip->awacs->codec_stat) & chip->hp_stat_mask) ? 1 : 0;
}
static void snd_pmac_burgundy_update_automute(struct snd_pmac *chip, int do_notify)
{
if (chip->auto_mute) {
int imac = of_machine_is_compatible("iMac");
int reg, oreg;
reg = oreg = snd_pmac_burgundy_rcb(chip,
MASK_ADDR_BURGUNDY_MORE_OUTPUTENABLES);
reg &= imac ? ~(BURGUNDY_OUTPUT_LEFT | BURGUNDY_OUTPUT_RIGHT
| BURGUNDY_HP_LEFT | BURGUNDY_HP_RIGHT)
: ~(BURGUNDY_OUTPUT_LEFT | BURGUNDY_OUTPUT_RIGHT
| BURGUNDY_OUTPUT_INTERN);
if (snd_pmac_burgundy_detect_headphone(chip))
reg |= imac ? (BURGUNDY_HP_LEFT | BURGUNDY_HP_RIGHT)
: (BURGUNDY_OUTPUT_LEFT
| BURGUNDY_OUTPUT_RIGHT);
else
reg |= imac ? (BURGUNDY_OUTPUT_LEFT
| BURGUNDY_OUTPUT_RIGHT)
: (BURGUNDY_OUTPUT_INTERN);
if (do_notify && reg == oreg)
return;
snd_pmac_burgundy_wcb(chip,
MASK_ADDR_BURGUNDY_MORE_OUTPUTENABLES, reg);
if (do_notify) {
snd_ctl_notify(chip->card, SNDRV_CTL_EVENT_MASK_VALUE,
&chip->master_sw_ctl->id);
snd_ctl_notify(chip->card, SNDRV_CTL_EVENT_MASK_VALUE,
&chip->speaker_sw_ctl->id);
snd_ctl_notify(chip->card, SNDRV_CTL_EVENT_MASK_VALUE,
&chip->hp_detect_ctl->id);
}
}
}
int __devinit snd_pmac_burgundy_init(struct snd_pmac *chip)
{
int imac = of_machine_is_compatible("iMac");
int i, err;
if ((in_le32(&chip->awacs->codec_ctrl) & MASK_ERRCODE) == 0xf0000) {
printk(KERN_WARNING "pmac burgundy: disabled by MacOS :-(\n");
return 1;
}
snd_pmac_burgundy_wcw(chip, MASK_ADDR_BURGUNDY_OUTPUTENABLES,
DEF_BURGUNDY_OUTPUTENABLES);
snd_pmac_burgundy_wcb(chip, MASK_ADDR_BURGUNDY_MORE_OUTPUTENABLES,
DEF_BURGUNDY_MORE_OUTPUTENABLES);
snd_pmac_burgundy_wcw(chip, MASK_ADDR_BURGUNDY_OUTPUTSELECTS,
DEF_BURGUNDY_OUTPUTSELECTS);
snd_pmac_burgundy_wcb(chip, MASK_ADDR_BURGUNDY_INPSEL21,
DEF_BURGUNDY_INPSEL21);
snd_pmac_burgundy_wcb(chip, MASK_ADDR_BURGUNDY_INPSEL3,
imac ? DEF_BURGUNDY_INPSEL3_IMAC
: DEF_BURGUNDY_INPSEL3_PMAC);
snd_pmac_burgundy_wcb(chip, MASK_ADDR_BURGUNDY_GAINCD,
DEF_BURGUNDY_GAINCD);
snd_pmac_burgundy_wcb(chip, MASK_ADDR_BURGUNDY_GAINLINE,
DEF_BURGUNDY_GAINLINE);
snd_pmac_burgundy_wcb(chip, MASK_ADDR_BURGUNDY_GAINMIC,
DEF_BURGUNDY_GAINMIC);
snd_pmac_burgundy_wcb(chip, MASK_ADDR_BURGUNDY_GAINMODEM,
DEF_BURGUNDY_GAINMODEM);
snd_pmac_burgundy_wcb(chip, MASK_ADDR_BURGUNDY_ATTENSPEAKER,
DEF_BURGUNDY_ATTENSPEAKER);
snd_pmac_burgundy_wcb(chip, MASK_ADDR_BURGUNDY_ATTENLINEOUT,
DEF_BURGUNDY_ATTENLINEOUT);
snd_pmac_burgundy_wcb(chip, MASK_ADDR_BURGUNDY_ATTENHP,
DEF_BURGUNDY_ATTENHP);
snd_pmac_burgundy_wcw(chip, MASK_ADDR_BURGUNDY_MASTER_VOLUME,
DEF_BURGUNDY_MASTER_VOLUME);
snd_pmac_burgundy_wcw(chip, MASK_ADDR_BURGUNDY_VOLCD,
DEF_BURGUNDY_VOLCD);
snd_pmac_burgundy_wcw(chip, MASK_ADDR_BURGUNDY_VOLLINE,
DEF_BURGUNDY_VOLLINE);
snd_pmac_burgundy_wcw(chip, MASK_ADDR_BURGUNDY_VOLMIC,
DEF_BURGUNDY_VOLMIC);
if (chip->hp_stat_mask == 0) {
if (imac)
chip->hp_stat_mask = BURGUNDY_HPDETECT_IMAC_UPPER
| BURGUNDY_HPDETECT_IMAC_LOWER
| BURGUNDY_HPDETECT_IMAC_SIDE;
else
chip->hp_stat_mask = BURGUNDY_HPDETECT_PMAC_BACK;
}
strcpy(chip->card->mixername, "PowerMac Burgundy");
for (i = 0; i < ARRAY_SIZE(snd_pmac_burgundy_mixers); i++) {
err = snd_ctl_add(chip->card,
snd_ctl_new1(&snd_pmac_burgundy_mixers[i], chip));
if (err < 0)
return err;
}
for (i = 0; i < (imac ? ARRAY_SIZE(snd_pmac_burgundy_mixers_imac)
: ARRAY_SIZE(snd_pmac_burgundy_mixers_pmac)); i++) {
err = snd_ctl_add(chip->card,
snd_ctl_new1(imac ? &snd_pmac_burgundy_mixers_imac[i]
: &snd_pmac_burgundy_mixers_pmac[i], chip));
if (err < 0)
return err;
}
chip->master_sw_ctl = snd_ctl_new1(imac
? &snd_pmac_burgundy_master_sw_imac
: &snd_pmac_burgundy_master_sw_pmac, chip);
err = snd_ctl_add(chip->card, chip->master_sw_ctl);
if (err < 0)
return err;
chip->master_sw_ctl = snd_ctl_new1(imac
? &snd_pmac_burgundy_line_sw_imac
: &snd_pmac_burgundy_line_sw_pmac, chip);
err = snd_ctl_add(chip->card, chip->master_sw_ctl);
if (err < 0)
return err;
if (imac) {
chip->master_sw_ctl = snd_ctl_new1(
&snd_pmac_burgundy_hp_sw_imac, chip);
err = snd_ctl_add(chip->card, chip->master_sw_ctl);
if (err < 0)
return err;
}
chip->speaker_sw_ctl = snd_ctl_new1(imac
? &snd_pmac_burgundy_speaker_sw_imac
: &snd_pmac_burgundy_speaker_sw_pmac, chip);
err = snd_ctl_add(chip->card, chip->speaker_sw_ctl);
if (err < 0)
return err;
#ifdef PMAC_SUPPORT_AUTOMUTE
err = snd_pmac_add_automute(chip);
if (err < 0)
return err;
chip->detect_headphone = snd_pmac_burgundy_detect_headphone;
chip->update_automute = snd_pmac_burgundy_update_automute;
snd_pmac_burgundy_update_automute(chip, 0);
#endif
return 0;
}
