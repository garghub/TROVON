int snd_vx_check_reg_bit(struct vx_core *chip, int reg, int mask, int bit, int time)
{
unsigned long end_time = jiffies + (time * HZ + 999) / 1000;
static char *reg_names[VX_REG_MAX] = {
"ICR", "CVR", "ISR", "IVR", "RXH", "RXM", "RXL",
"DMA", "CDSP", "RFREQ", "RUER/V2", "DATA", "MEMIRQ",
"ACQ", "BIT0", "BIT1", "MIC0", "MIC1", "MIC2",
"MIC3", "INTCSR", "CNTRL", "GPIOC",
"LOFREQ", "HIFREQ", "CSUER", "RUER"
};
do {
if ((snd_vx_inb(chip, reg) & mask) == bit)
return 0;
} while (time_after_eq(end_time, jiffies));
snd_printd(KERN_DEBUG "vx_check_reg_bit: timeout, reg=%s, mask=0x%x, val=0x%x\n", reg_names[reg], mask, snd_vx_inb(chip, reg));
return -EIO;
}
static int vx_send_irq_dsp(struct vx_core *chip, int num)
{
int nirq;
if (snd_vx_check_reg_bit(chip, VX_CVR, CVR_HC, 0, 200) < 0)
return -EIO;
nirq = num;
if (vx_has_new_dsp(chip))
nirq += VXP_IRQ_OFFSET;
vx_outb(chip, CVR, (nirq >> 1) | CVR_HC);
return 0;
}
static int vx_reset_chk(struct vx_core *chip)
{
if (vx_send_irq_dsp(chip, IRQ_RESET_CHK) < 0)
return -EIO;
if (vx_check_isr(chip, ISR_CHK, 0, 200) < 0)
return -EIO;
return 0;
}
static int vx_transfer_end(struct vx_core *chip, int cmd)
{
int err;
if ((err = vx_reset_chk(chip)) < 0)
return err;
if ((err = vx_send_irq_dsp(chip, cmd)) < 0)
return err;
if ((err = vx_wait_isr_bit(chip, ISR_CHK)) < 0)
return err;
if ((err = vx_inb(chip, ISR)) & ISR_ERR) {
if ((err = vx_wait_for_rx_full(chip)) < 0) {
snd_printd(KERN_DEBUG "transfer_end: error in rx_full\n");
return err;
}
err = vx_inb(chip, RXH) << 16;
err |= vx_inb(chip, RXM) << 8;
err |= vx_inb(chip, RXL);
snd_printd(KERN_DEBUG "transfer_end: error = 0x%x\n", err);
return -(VX_ERR_MASK | err);
}
return 0;
}
static int vx_read_status(struct vx_core *chip, struct vx_rmh *rmh)
{
int i, err, val, size;
if (rmh->DspStat == RMH_SSIZE_FIXED && rmh->LgStat == 0)
return 0;
err = vx_wait_for_rx_full(chip);
if (err < 0)
return err;
val = vx_inb(chip, RXH) << 16;
val |= vx_inb(chip, RXM) << 8;
val |= vx_inb(chip, RXL);
switch (rmh->DspStat) {
case RMH_SSIZE_ARG:
size = val & 0xff;
rmh->Stat[0] = val & 0xffff00;
rmh->LgStat = size + 1;
break;
case RMH_SSIZE_MASK:
rmh->Stat[0] = val;
size = 0;
while (val) {
if (val & 0x01)
size++;
val >>= 1;
}
rmh->LgStat = size + 1;
break;
default:
size = rmh->LgStat;
rmh->Stat[0] = val;
size--;
break;
}
if (size < 1)
return 0;
if (snd_BUG_ON(size >= SIZE_MAX_STATUS))
return -EINVAL;
for (i = 1; i <= size; i++) {
err = vx_send_irq_dsp(chip, IRQ_MESS_WRITE_NEXT);
if (err < 0)
return err;
err = vx_wait_for_rx_full(chip);
if (err < 0)
return err;
rmh->Stat[i] = vx_inb(chip, RXH) << 16;
rmh->Stat[i] |= vx_inb(chip, RXM) << 8;
rmh->Stat[i] |= vx_inb(chip, RXL);
}
return vx_transfer_end(chip, IRQ_MESS_WRITE_END);
}
int vx_send_msg_nolock(struct vx_core *chip, struct vx_rmh *rmh)
{
int i, err;
if (chip->chip_status & VX_STAT_IS_STALE)
return -EBUSY;
if ((err = vx_reset_chk(chip)) < 0) {
snd_printd(KERN_DEBUG "vx_send_msg: vx_reset_chk error\n");
return err;
}
#if 0
printk(KERN_DEBUG "rmh: cmd = 0x%06x, length = %d, stype = %d\n",
rmh->Cmd[0], rmh->LgCmd, rmh->DspStat);
if (rmh->LgCmd > 1) {
printk(KERN_DEBUG " ");
for (i = 1; i < rmh->LgCmd; i++)
printk(KERN_CONT "0x%06x ", rmh->Cmd[i]);
printk(KERN_CONT "\n");
}
#endif
if (rmh->LgCmd > 1)
rmh->Cmd[0] |= MASK_MORE_THAN_1_WORD_COMMAND;
else
rmh->Cmd[0] &= MASK_1_WORD_COMMAND;
if ((err = vx_wait_isr_bit(chip, ISR_TX_EMPTY)) < 0) {
snd_printd(KERN_DEBUG "vx_send_msg: wait tx empty error\n");
return err;
}
vx_outb(chip, TXH, (rmh->Cmd[0] >> 16) & 0xff);
vx_outb(chip, TXM, (rmh->Cmd[0] >> 8) & 0xff);
vx_outb(chip, TXL, rmh->Cmd[0] & 0xff);
if ((err = vx_send_irq_dsp(chip, IRQ_MESSAGE)) < 0) {
snd_printd(KERN_DEBUG "vx_send_msg: send IRQ_MESSAGE error\n");
return err;
}
if ((err = vx_wait_isr_bit(chip, ISR_CHK)) < 0)
return err;
if (vx_inb(chip, ISR) & ISR_ERR) {
if ((err = vx_wait_for_rx_full(chip)) < 0) {
snd_printd(KERN_DEBUG "vx_send_msg: rx_full read error\n");
return err;
}
err = vx_inb(chip, RXH) << 16;
err |= vx_inb(chip, RXM) << 8;
err |= vx_inb(chip, RXL);
snd_printd(KERN_DEBUG "msg got error = 0x%x at cmd[0]\n", err);
err = -(VX_ERR_MASK | err);
return err;
}
if (rmh->LgCmd > 1) {
for (i = 1; i < rmh->LgCmd; i++) {
if ((err = vx_wait_isr_bit(chip, ISR_TX_READY)) < 0) {
snd_printd(KERN_DEBUG "vx_send_msg: tx_ready error\n");
return err;
}
vx_outb(chip, TXH, (rmh->Cmd[i] >> 16) & 0xff);
vx_outb(chip, TXM, (rmh->Cmd[i] >> 8) & 0xff);
vx_outb(chip, TXL, rmh->Cmd[i] & 0xff);
if ((err = vx_send_irq_dsp(chip, IRQ_MESS_READ_NEXT)) < 0) {
snd_printd(KERN_DEBUG "vx_send_msg: IRQ_READ_NEXT error\n");
return err;
}
}
if ((err = vx_wait_isr_bit(chip, ISR_TX_READY)) < 0) {
snd_printd(KERN_DEBUG "vx_send_msg: TX_READY error\n");
return err;
}
err = vx_transfer_end(chip, IRQ_MESS_READ_END);
if (err < 0)
return err;
}
return vx_read_status(chip, rmh);
}
int vx_send_msg(struct vx_core *chip, struct vx_rmh *rmh)
{
int err;
mutex_lock(&chip->lock);
err = vx_send_msg_nolock(chip, rmh);
mutex_unlock(&chip->lock);
return err;
}
int vx_send_rih_nolock(struct vx_core *chip, int cmd)
{
int err;
if (chip->chip_status & VX_STAT_IS_STALE)
return -EBUSY;
#if 0
printk(KERN_DEBUG "send_rih: cmd = 0x%x\n", cmd);
#endif
if ((err = vx_reset_chk(chip)) < 0)
return err;
if ((err = vx_send_irq_dsp(chip, cmd)) < 0)
return err;
if ((err = vx_wait_isr_bit(chip, ISR_CHK)) < 0)
return err;
if (vx_inb(chip, ISR) & ISR_ERR) {
if ((err = vx_wait_for_rx_full(chip)) < 0)
return err;
err = vx_inb(chip, RXH) << 16;
err |= vx_inb(chip, RXM) << 8;
err |= vx_inb(chip, RXL);
return -(VX_ERR_MASK | err);
}
return 0;
}
int vx_send_rih(struct vx_core *chip, int cmd)
{
int err;
mutex_lock(&chip->lock);
err = vx_send_rih_nolock(chip, cmd);
mutex_unlock(&chip->lock);
return err;
}
int snd_vx_load_boot_image(struct vx_core *chip, const struct firmware *boot)
{
unsigned int i;
int no_fillup = vx_has_new_dsp(chip);
if (boot->size <= 0)
return -EINVAL;
if (boot->size % 3)
return -EINVAL;
#if 0
{
unsigned int c = ((u32)boot->data[0] << 16) | ((u32)boot->data[1] << 8) | boot->data[2];
if (boot->size != (c + 2) * 3)
return -EINVAL;
}
#endif
vx_reset_dsp(chip);
udelay(END_OF_RESET_WAIT_TIME);
for (i = 0; i < 0x600; i += 3) {
if (i >= boot->size) {
if (no_fillup)
break;
if (vx_wait_isr_bit(chip, ISR_TX_EMPTY) < 0) {
snd_printk(KERN_ERR "dsp boot failed at %d\n", i);
return -EIO;
}
vx_outb(chip, TXH, 0);
vx_outb(chip, TXM, 0);
vx_outb(chip, TXL, 0);
} else {
const unsigned char *image = boot->data + i;
if (vx_wait_isr_bit(chip, ISR_TX_EMPTY) < 0) {
snd_printk(KERN_ERR "dsp boot failed at %d\n", i);
return -EIO;
}
vx_outb(chip, TXH, image[0]);
vx_outb(chip, TXM, image[1]);
vx_outb(chip, TXL, image[2]);
}
}
return 0;
}
static int vx_test_irq_src(struct vx_core *chip, unsigned int *ret)
{
int err;
vx_init_rmh(&chip->irq_rmh, CMD_TEST_IT);
mutex_lock(&chip->lock);
err = vx_send_msg_nolock(chip, &chip->irq_rmh);
if (err < 0)
*ret = 0;
else
*ret = chip->irq_rmh.Stat[0];
mutex_unlock(&chip->lock);
return err;
}
irqreturn_t snd_vx_threaded_irq_handler(int irq, void *dev)
{
struct vx_core *chip = dev;
unsigned int events;
if (chip->chip_status & VX_STAT_IS_STALE)
return IRQ_HANDLED;
if (vx_test_irq_src(chip, &events) < 0)
return IRQ_HANDLED;
#if 0
if (events & 0x000800)
printk(KERN_ERR "DSP Stream underrun ! IRQ events = 0x%x\n", events);
#endif
if (events & FATAL_DSP_ERROR) {
snd_printk(KERN_ERR "vx_core: fatal DSP error!!\n");
return IRQ_HANDLED;
}
if (events & TIME_CODE_EVENT_PENDING)
;
if (events & FREQUENCY_CHANGE_EVENT_PENDING)
vx_change_frequency(chip);
vx_pcm_update_intr(chip, events);
return IRQ_HANDLED;
}
irqreturn_t snd_vx_irq_handler(int irq, void *dev)
{
struct vx_core *chip = dev;
if (! (chip->chip_status & VX_STAT_CHIP_INIT) ||
(chip->chip_status & VX_STAT_IS_STALE))
return IRQ_NONE;
if (! vx_test_and_ack(chip))
return IRQ_WAKE_THREAD;
return IRQ_NONE;
}
static void vx_reset_board(struct vx_core *chip, int cold_reset)
{
if (snd_BUG_ON(!chip->ops->reset_board))
return;
chip->audio_source = VX_AUDIO_SRC_LINE;
if (cold_reset) {
chip->audio_source_target = chip->audio_source;
chip->clock_source = INTERNAL_QUARTZ;
chip->clock_mode = VX_CLOCK_MODE_AUTO;
chip->freq = 48000;
chip->uer_detected = VX_UER_MODE_NOT_PRESENT;
chip->uer_bits = SNDRV_PCM_DEFAULT_CON_SPDIF;
}
chip->ops->reset_board(chip, cold_reset);
vx_reset_codec(chip, cold_reset);
vx_set_internal_clock(chip, chip->freq);
vx_reset_dsp(chip);
if (vx_is_pcmcia(chip)) {
vx_test_and_ack(chip);
vx_validate_irq(chip, 1);
}
vx_set_iec958_status(chip, chip->uer_bits);
}
static void vx_proc_read(struct snd_info_entry *entry, struct snd_info_buffer *buffer)
{
struct vx_core *chip = entry->private_data;
static char *audio_src_vxp[] = { "Line", "Mic", "Digital" };
static char *audio_src_vx2[] = { "Analog", "Analog", "Digital" };
static char *clock_mode[] = { "Auto", "Internal", "External" };
static char *clock_src[] = { "Internal", "External" };
static char *uer_type[] = { "Consumer", "Professional", "Not Present" };
snd_iprintf(buffer, "%s\n", chip->card->longname);
snd_iprintf(buffer, "Xilinx Firmware: %s\n",
chip->chip_status & VX_STAT_XILINX_LOADED ? "Loaded" : "No");
snd_iprintf(buffer, "Device Initialized: %s\n",
chip->chip_status & VX_STAT_DEVICE_INIT ? "Yes" : "No");
snd_iprintf(buffer, "DSP audio info:");
if (chip->audio_info & VX_AUDIO_INFO_REAL_TIME)
snd_iprintf(buffer, " realtime");
if (chip->audio_info & VX_AUDIO_INFO_OFFLINE)
snd_iprintf(buffer, " offline");
if (chip->audio_info & VX_AUDIO_INFO_MPEG1)
snd_iprintf(buffer, " mpeg1");
if (chip->audio_info & VX_AUDIO_INFO_MPEG2)
snd_iprintf(buffer, " mpeg2");
if (chip->audio_info & VX_AUDIO_INFO_LINEAR_8)
snd_iprintf(buffer, " linear8");
if (chip->audio_info & VX_AUDIO_INFO_LINEAR_16)
snd_iprintf(buffer, " linear16");
if (chip->audio_info & VX_AUDIO_INFO_LINEAR_24)
snd_iprintf(buffer, " linear24");
snd_iprintf(buffer, "\n");
snd_iprintf(buffer, "Input Source: %s\n", vx_is_pcmcia(chip) ?
audio_src_vxp[chip->audio_source] :
audio_src_vx2[chip->audio_source]);
snd_iprintf(buffer, "Clock Mode: %s\n", clock_mode[chip->clock_mode]);
snd_iprintf(buffer, "Clock Source: %s\n", clock_src[chip->clock_source]);
snd_iprintf(buffer, "Frequency: %d\n", chip->freq);
snd_iprintf(buffer, "Detected Frequency: %d\n", chip->freq_detected);
snd_iprintf(buffer, "Detected UER type: %s\n", uer_type[chip->uer_detected]);
snd_iprintf(buffer, "Min/Max/Cur IBL: %d/%d/%d (granularity=%d)\n",
chip->ibl.min_size, chip->ibl.max_size, chip->ibl.size,
chip->ibl.granularity);
}
static void vx_proc_init(struct vx_core *chip)
{
struct snd_info_entry *entry;
if (! snd_card_proc_new(chip->card, "vx-status", &entry))
snd_info_set_text_ops(entry, chip, vx_proc_read);
}
int snd_vx_dsp_boot(struct vx_core *chip, const struct firmware *boot)
{
int err;
int cold_reset = !(chip->chip_status & VX_STAT_DEVICE_INIT);
vx_reset_board(chip, cold_reset);
vx_validate_irq(chip, 0);
if ((err = snd_vx_load_boot_image(chip, boot)) < 0)
return err;
msleep(10);
return 0;
}
int snd_vx_dsp_load(struct vx_core *chip, const struct firmware *dsp)
{
unsigned int i;
int err;
unsigned int csum = 0;
const unsigned char *image, *cptr;
if (dsp->size % 3)
return -EINVAL;
vx_toggle_dac_mute(chip, 1);
for (i = 0; i < dsp->size; i += 3) {
image = dsp->data + i;
if ((err = vx_wait_isr_bit(chip, ISR_TX_EMPTY)) < 0) {
printk(KERN_ERR
"dsp loading error at position %d\n", i);
return err;
}
cptr = image;
csum ^= *cptr;
csum = (csum >> 24) | (csum << 8);
vx_outb(chip, TXH, *cptr++);
csum ^= *cptr;
csum = (csum >> 24) | (csum << 8);
vx_outb(chip, TXM, *cptr++);
csum ^= *cptr;
csum = (csum >> 24) | (csum << 8);
vx_outb(chip, TXL, *cptr++);
}
snd_printdd(KERN_DEBUG "checksum = 0x%08x\n", csum);
msleep(200);
if ((err = vx_wait_isr_bit(chip, ISR_CHK)) < 0)
return err;
vx_toggle_dac_mute(chip, 0);
vx_test_and_ack(chip);
vx_validate_irq(chip, 1);
return 0;
}
int snd_vx_suspend(struct vx_core *chip)
{
unsigned int i;
snd_power_change_state(chip->card, SNDRV_CTL_POWER_D3hot);
chip->chip_status |= VX_STAT_IN_SUSPEND;
for (i = 0; i < chip->hw->num_codecs; i++)
snd_pcm_suspend_all(chip->pcm[i]);
return 0;
}
int snd_vx_resume(struct vx_core *chip)
{
int i, err;
chip->chip_status &= ~VX_STAT_CHIP_INIT;
for (i = 0; i < 4; i++) {
if (! chip->firmware[i])
continue;
err = chip->ops->load_dsp(chip, i, chip->firmware[i]);
if (err < 0) {
snd_printk(KERN_ERR "vx: firmware resume error at DSP %d\n", i);
return -EIO;
}
}
chip->chip_status |= VX_STAT_CHIP_INIT;
chip->chip_status &= ~VX_STAT_IN_SUSPEND;
snd_power_change_state(chip->card, SNDRV_CTL_POWER_D0);
return 0;
}
struct vx_core *snd_vx_create(struct snd_card *card, struct snd_vx_hardware *hw,
struct snd_vx_ops *ops,
int extra_size)
{
struct vx_core *chip;
if (snd_BUG_ON(!card || !hw || !ops))
return NULL;
chip = kzalloc(sizeof(*chip) + extra_size, GFP_KERNEL);
if (! chip)
return NULL;
mutex_init(&chip->lock);
chip->irq = -1;
chip->hw = hw;
chip->type = hw->type;
chip->ops = ops;
mutex_init(&chip->mixer_mutex);
chip->card = card;
card->private_data = chip;
strcpy(card->driver, hw->name);
sprintf(card->shortname, "Digigram %s", hw->name);
vx_proc_init(chip);
return chip;
}
static int __init alsa_vx_core_init(void)
{
return 0;
}
static void __exit alsa_vx_core_exit(void)
{
}
