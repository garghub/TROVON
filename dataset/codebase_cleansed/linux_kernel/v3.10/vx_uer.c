static int vx_modify_board_clock(struct vx_core *chip, int sync)
{
struct vx_rmh rmh;
vx_init_rmh(&rmh, CMD_MODIFY_CLOCK);
if (sync)
rmh.Cmd[0] |= CMD_MODIFY_CLOCK_S_BIT;
return vx_send_msg(chip, &rmh);
}
static int vx_modify_board_inputs(struct vx_core *chip)
{
struct vx_rmh rmh;
vx_init_rmh(&rmh, CMD_RESYNC_AUDIO_INPUTS);
rmh.Cmd[0] |= 1 << 0;
return vx_send_msg(chip, &rmh);
}
static int vx_read_one_cbit(struct vx_core *chip, int index)
{
unsigned long flags;
int val;
spin_lock_irqsave(&chip->lock, flags);
if (chip->type >= VX_TYPE_VXPOCKET) {
vx_outb(chip, CSUER, 1);
vx_outb(chip, RUER, index & XX_UER_CBITS_OFFSET_MASK);
val = (vx_inb(chip, RUER) >> 7) & 0x01;
} else {
vx_outl(chip, CSUER, 1);
vx_outl(chip, RUER, index & XX_UER_CBITS_OFFSET_MASK);
val = (vx_inl(chip, RUER) >> 7) & 0x01;
}
spin_unlock_irqrestore(&chip->lock, flags);
return val;
}
static void vx_write_one_cbit(struct vx_core *chip, int index, int val)
{
unsigned long flags;
val = !!val;
spin_lock_irqsave(&chip->lock, flags);
if (vx_is_pcmcia(chip)) {
vx_outb(chip, CSUER, 0);
vx_outb(chip, RUER, (val << 7) | (index & XX_UER_CBITS_OFFSET_MASK));
} else {
vx_outl(chip, CSUER, 0);
vx_outl(chip, RUER, (val << 7) | (index & XX_UER_CBITS_OFFSET_MASK));
}
spin_unlock_irqrestore(&chip->lock, flags);
}
static int vx_read_uer_status(struct vx_core *chip, unsigned int *mode)
{
int val, freq;
freq = 0;
if (vx_is_pcmcia(chip))
val = vx_inb(chip, CSUER);
else
val = vx_inl(chip, CSUER);
if (val < 0)
return val;
if (val & VX_SUER_CLOCK_PRESENT_MASK) {
switch (val & VX_SUER_FREQ_MASK) {
case VX_SUER_FREQ_32KHz_MASK:
freq = 32000;
break;
case VX_SUER_FREQ_44KHz_MASK:
freq = 44100;
break;
case VX_SUER_FREQ_48KHz_MASK:
freq = 48000;
break;
}
}
if (val & VX_SUER_DATA_PRESENT_MASK)
*mode = vx_read_one_cbit(chip, 0) ?
VX_UER_MODE_PROFESSIONAL : VX_UER_MODE_CONSUMER;
else
*mode = VX_UER_MODE_NOT_PRESENT;
return freq;
}
static int vx_calc_clock_from_freq(struct vx_core *chip, int freq)
{
int hexfreq;
if (snd_BUG_ON(freq <= 0))
return 0;
hexfreq = (28224000 * 10) / freq;
hexfreq = (hexfreq + 5) / 10;
if (snd_BUG_ON(hexfreq <= 0x00000200))
return 0;
if (hexfreq <= 0x03ff)
return hexfreq - 0x00000201;
if (hexfreq <= 0x07ff)
return (hexfreq / 2) - 1;
if (hexfreq <= 0x0fff)
return (hexfreq / 4) + 0x000001ff;
return 0x5fe;
}
static void vx_change_clock_source(struct vx_core *chip, int source)
{
unsigned long flags;
vx_toggle_dac_mute(chip, 1);
spin_lock_irqsave(&chip->lock, flags);
chip->ops->set_clock_source(chip, source);
chip->clock_source = source;
spin_unlock_irqrestore(&chip->lock, flags);
vx_toggle_dac_mute(chip, 0);
}
void vx_set_internal_clock(struct vx_core *chip, unsigned int freq)
{
int clock;
unsigned long flags;
clock = vx_calc_clock_from_freq(chip, freq);
snd_printdd(KERN_DEBUG "set internal clock to 0x%x from freq %d\n", clock, freq);
spin_lock_irqsave(&chip->lock, flags);
if (vx_is_pcmcia(chip)) {
vx_outb(chip, HIFREQ, (clock >> 8) & 0x0f);
vx_outb(chip, LOFREQ, clock & 0xff);
} else {
vx_outl(chip, HIFREQ, (clock >> 8) & 0x0f);
vx_outl(chip, LOFREQ, clock & 0xff);
}
spin_unlock_irqrestore(&chip->lock, flags);
}
void vx_set_iec958_status(struct vx_core *chip, unsigned int bits)
{
int i;
if (chip->chip_status & VX_STAT_IS_STALE)
return;
for (i = 0; i < 32; i++)
vx_write_one_cbit(chip, i, bits & (1 << i));
}
int vx_set_clock(struct vx_core *chip, unsigned int freq)
{
int src_changed = 0;
if (chip->chip_status & VX_STAT_IS_STALE)
return 0;
vx_sync_audio_source(chip);
if (chip->clock_mode == VX_CLOCK_MODE_EXTERNAL ||
(chip->clock_mode == VX_CLOCK_MODE_AUTO &&
chip->audio_source == VX_AUDIO_SRC_DIGITAL)) {
if (chip->clock_source != UER_SYNC) {
vx_change_clock_source(chip, UER_SYNC);
mdelay(6);
src_changed = 1;
}
} else if (chip->clock_mode == VX_CLOCK_MODE_INTERNAL ||
(chip->clock_mode == VX_CLOCK_MODE_AUTO &&
chip->audio_source != VX_AUDIO_SRC_DIGITAL)) {
if (chip->clock_source != INTERNAL_QUARTZ) {
vx_change_clock_source(chip, INTERNAL_QUARTZ);
src_changed = 1;
}
if (chip->freq == freq)
return 0;
vx_set_internal_clock(chip, freq);
if (src_changed)
vx_modify_board_inputs(chip);
}
if (chip->freq == freq)
return 0;
chip->freq = freq;
vx_modify_board_clock(chip, 1);
return 0;
}
int vx_change_frequency(struct vx_core *chip)
{
int freq;
if (chip->chip_status & VX_STAT_IS_STALE)
return 0;
if (chip->clock_source == INTERNAL_QUARTZ)
return 0;
freq = vx_read_uer_status(chip, &chip->uer_detected);
if (freq < 0)
return freq;
if (freq == 48000 || freq == 44100 || freq == 32000)
chip->freq_detected = freq;
return 0;
}
