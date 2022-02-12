static inline u8 igetbyte(struct intel8x0m *chip, u32 offset)
{
return ioread8(chip->bmaddr + offset);
}
static inline u16 igetword(struct intel8x0m *chip, u32 offset)
{
return ioread16(chip->bmaddr + offset);
}
static inline u32 igetdword(struct intel8x0m *chip, u32 offset)
{
return ioread32(chip->bmaddr + offset);
}
static inline void iputbyte(struct intel8x0m *chip, u32 offset, u8 val)
{
iowrite8(val, chip->bmaddr + offset);
}
static inline void iputword(struct intel8x0m *chip, u32 offset, u16 val)
{
iowrite16(val, chip->bmaddr + offset);
}
static inline void iputdword(struct intel8x0m *chip, u32 offset, u32 val)
{
iowrite32(val, chip->bmaddr + offset);
}
static inline u16 iagetword(struct intel8x0m *chip, u32 offset)
{
return ioread16(chip->addr + offset);
}
static inline void iaputword(struct intel8x0m *chip, u32 offset, u16 val)
{
iowrite16(val, chip->addr + offset);
}
static unsigned int get_ich_codec_bit(struct intel8x0m *chip, unsigned int codec)
{
static unsigned int codec_bit[3] = {
ICH_PCR, ICH_SCR, ICH_TCR
};
if (snd_BUG_ON(codec >= 3))
return ICH_PCR;
return codec_bit[codec];
}
static int snd_intel8x0m_codec_semaphore(struct intel8x0m *chip, unsigned int codec)
{
int time;
if (codec > 1)
return -EIO;
codec = get_ich_codec_bit(chip, codec);
if ((igetdword(chip, ICHREG(GLOB_STA)) & codec) == 0)
return -EIO;
time = 100;
do {
if (!(igetbyte(chip, ICHREG(ACC_SEMA)) & ICH_CAS))
return 0;
udelay(10);
} while (time--);
snd_printk(KERN_ERR "codec_semaphore: semaphore is not ready [0x%x][0x%x]\n",
igetbyte(chip, ICHREG(ACC_SEMA)), igetdword(chip, ICHREG(GLOB_STA)));
iagetword(chip, 0);
return -EBUSY;
}
static void snd_intel8x0m_codec_write(struct snd_ac97 *ac97,
unsigned short reg,
unsigned short val)
{
struct intel8x0m *chip = ac97->private_data;
if (snd_intel8x0m_codec_semaphore(chip, ac97->num) < 0) {
if (! chip->in_ac97_init)
snd_printk(KERN_ERR "codec_write %d: semaphore is not ready for register 0x%x\n", ac97->num, reg);
}
iaputword(chip, reg + ac97->num * 0x80, val);
}
static unsigned short snd_intel8x0m_codec_read(struct snd_ac97 *ac97,
unsigned short reg)
{
struct intel8x0m *chip = ac97->private_data;
unsigned short res;
unsigned int tmp;
if (snd_intel8x0m_codec_semaphore(chip, ac97->num) < 0) {
if (! chip->in_ac97_init)
snd_printk(KERN_ERR "codec_read %d: semaphore is not ready for register 0x%x\n", ac97->num, reg);
res = 0xffff;
} else {
res = iagetword(chip, reg + ac97->num * 0x80);
if ((tmp = igetdword(chip, ICHREG(GLOB_STA))) & ICH_RCS) {
iputdword(chip, ICHREG(GLOB_STA),
tmp & ~(ICH_SRI|ICH_PRI|ICH_TRI|ICH_GSCI));
if (! chip->in_ac97_init)
snd_printk(KERN_ERR "codec_read %d: read timeout for register 0x%x\n", ac97->num, reg);
res = 0xffff;
}
}
if (reg == AC97_GPIO_STATUS)
iagetword(chip, 0);
return res;
}
static void snd_intel8x0m_setup_periods(struct intel8x0m *chip, struct ichdev *ichdev)
{
int idx;
u32 *bdbar = ichdev->bdbar;
unsigned long port = ichdev->reg_offset;
iputdword(chip, port + ICH_REG_OFF_BDBAR, ichdev->bdbar_addr);
if (ichdev->size == ichdev->fragsize) {
ichdev->ack_reload = ichdev->ack = 2;
ichdev->fragsize1 = ichdev->fragsize >> 1;
for (idx = 0; idx < (ICH_REG_LVI_MASK + 1) * 2; idx += 4) {
bdbar[idx + 0] = cpu_to_le32(ichdev->physbuf);
bdbar[idx + 1] = cpu_to_le32(0x80000000 |
ichdev->fragsize1 >> chip->pcm_pos_shift);
bdbar[idx + 2] = cpu_to_le32(ichdev->physbuf + (ichdev->size >> 1));
bdbar[idx + 3] = cpu_to_le32(0x80000000 |
ichdev->fragsize1 >> chip->pcm_pos_shift);
}
ichdev->frags = 2;
} else {
ichdev->ack_reload = ichdev->ack = 1;
ichdev->fragsize1 = ichdev->fragsize;
for (idx = 0; idx < (ICH_REG_LVI_MASK + 1) * 2; idx += 2) {
bdbar[idx + 0] = cpu_to_le32(ichdev->physbuf + (((idx >> 1) * ichdev->fragsize) % ichdev->size));
bdbar[idx + 1] = cpu_to_le32(0x80000000 |
ichdev->fragsize >> chip->pcm_pos_shift);
}
ichdev->frags = ichdev->size / ichdev->fragsize;
}
iputbyte(chip, port + ICH_REG_OFF_LVI, ichdev->lvi = ICH_REG_LVI_MASK);
ichdev->civ = 0;
iputbyte(chip, port + ICH_REG_OFF_CIV, 0);
ichdev->lvi_frag = ICH_REG_LVI_MASK % ichdev->frags;
ichdev->position = 0;
#if 0
printk(KERN_DEBUG "lvi_frag = %i, frags = %i, period_size = 0x%x, "
"period_size1 = 0x%x\n",
ichdev->lvi_frag, ichdev->frags, ichdev->fragsize,
ichdev->fragsize1);
#endif
iputbyte(chip, port + ichdev->roff_sr, ICH_FIFOE | ICH_BCIS | ICH_LVBCI);
}
static inline void snd_intel8x0m_update(struct intel8x0m *chip, struct ichdev *ichdev)
{
unsigned long port = ichdev->reg_offset;
int civ, i, step;
int ack = 0;
civ = igetbyte(chip, port + ICH_REG_OFF_CIV);
if (civ == ichdev->civ) {
step = 1;
ichdev->civ++;
ichdev->civ &= ICH_REG_LVI_MASK;
} else {
step = civ - ichdev->civ;
if (step < 0)
step += ICH_REG_LVI_MASK + 1;
ichdev->civ = civ;
}
ichdev->position += step * ichdev->fragsize1;
ichdev->position %= ichdev->size;
ichdev->lvi += step;
ichdev->lvi &= ICH_REG_LVI_MASK;
iputbyte(chip, port + ICH_REG_OFF_LVI, ichdev->lvi);
for (i = 0; i < step; i++) {
ichdev->lvi_frag++;
ichdev->lvi_frag %= ichdev->frags;
ichdev->bdbar[ichdev->lvi * 2] = cpu_to_le32(ichdev->physbuf +
ichdev->lvi_frag *
ichdev->fragsize1);
#if 0
printk(KERN_DEBUG "new: bdbar[%i] = 0x%x [0x%x], "
"prefetch = %i, all = 0x%x, 0x%x\n",
ichdev->lvi * 2, ichdev->bdbar[ichdev->lvi * 2],
ichdev->bdbar[ichdev->lvi * 2 + 1], inb(ICH_REG_OFF_PIV + port),
inl(port + 4), inb(port + ICH_REG_OFF_CR));
#endif
if (--ichdev->ack == 0) {
ichdev->ack = ichdev->ack_reload;
ack = 1;
}
}
if (ack && ichdev->substream) {
spin_unlock(&chip->reg_lock);
snd_pcm_period_elapsed(ichdev->substream);
spin_lock(&chip->reg_lock);
}
iputbyte(chip, port + ichdev->roff_sr, ICH_FIFOE | ICH_BCIS | ICH_LVBCI);
}
static irqreturn_t snd_intel8x0m_interrupt(int irq, void *dev_id)
{
struct intel8x0m *chip = dev_id;
struct ichdev *ichdev;
unsigned int status;
unsigned int i;
spin_lock(&chip->reg_lock);
status = igetdword(chip, chip->int_sta_reg);
if (status == 0xffffffff) {
spin_unlock(&chip->reg_lock);
return IRQ_NONE;
}
if ((status & chip->int_sta_mask) == 0) {
if (status)
iputdword(chip, chip->int_sta_reg, status);
spin_unlock(&chip->reg_lock);
return IRQ_NONE;
}
for (i = 0; i < chip->bdbars_count; i++) {
ichdev = &chip->ichd[i];
if (status & ichdev->int_sta_mask)
snd_intel8x0m_update(chip, ichdev);
}
iputdword(chip, chip->int_sta_reg, status & chip->int_sta_mask);
spin_unlock(&chip->reg_lock);
return IRQ_HANDLED;
}
static int snd_intel8x0m_pcm_trigger(struct snd_pcm_substream *substream, int cmd)
{
struct intel8x0m *chip = snd_pcm_substream_chip(substream);
struct ichdev *ichdev = get_ichdev(substream);
unsigned char val = 0;
unsigned long port = ichdev->reg_offset;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
val = ICH_IOCE | ICH_STARTBM;
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
val = 0;
break;
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
val = ICH_IOCE;
break;
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
val = ICH_IOCE | ICH_STARTBM;
break;
default:
return -EINVAL;
}
iputbyte(chip, port + ICH_REG_OFF_CR, val);
if (cmd == SNDRV_PCM_TRIGGER_STOP) {
while (!(igetbyte(chip, port + ichdev->roff_sr) & ICH_DCH)) ;
iputbyte(chip, port + ICH_REG_OFF_CR, ICH_RESETREGS);
}
return 0;
}
static int snd_intel8x0m_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
return snd_pcm_lib_malloc_pages(substream, params_buffer_bytes(hw_params));
}
static int snd_intel8x0m_hw_free(struct snd_pcm_substream *substream)
{
return snd_pcm_lib_free_pages(substream);
}
static snd_pcm_uframes_t snd_intel8x0m_pcm_pointer(struct snd_pcm_substream *substream)
{
struct intel8x0m *chip = snd_pcm_substream_chip(substream);
struct ichdev *ichdev = get_ichdev(substream);
size_t ptr1, ptr;
ptr1 = igetword(chip, ichdev->reg_offset + ichdev->roff_picb) << chip->pcm_pos_shift;
if (ptr1 != 0)
ptr = ichdev->fragsize1 - ptr1;
else
ptr = 0;
ptr += ichdev->position;
if (ptr >= ichdev->size)
return 0;
return bytes_to_frames(substream->runtime, ptr);
}
static int snd_intel8x0m_pcm_prepare(struct snd_pcm_substream *substream)
{
struct intel8x0m *chip = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct ichdev *ichdev = get_ichdev(substream);
ichdev->physbuf = runtime->dma_addr;
ichdev->size = snd_pcm_lib_buffer_bytes(substream);
ichdev->fragsize = snd_pcm_lib_period_bytes(substream);
snd_ac97_write(ichdev->ac97, AC97_LINE1_RATE, runtime->rate);
snd_ac97_write(ichdev->ac97, AC97_LINE1_LEVEL, 0);
snd_intel8x0m_setup_periods(chip, ichdev);
return 0;
}
static int snd_intel8x0m_pcm_open(struct snd_pcm_substream *substream, struct ichdev *ichdev)
{
static unsigned int rates[] = { 8000, 9600, 12000, 16000 };
static struct snd_pcm_hw_constraint_list hw_constraints_rates = {
.count = ARRAY_SIZE(rates),
.list = rates,
.mask = 0,
};
struct snd_pcm_runtime *runtime = substream->runtime;
int err;
ichdev->substream = substream;
runtime->hw = snd_intel8x0m_stream;
err = snd_pcm_hw_constraint_list(runtime, 0, SNDRV_PCM_HW_PARAM_RATE,
&hw_constraints_rates);
if ( err < 0 )
return err;
runtime->private_data = ichdev;
return 0;
}
static int snd_intel8x0m_playback_open(struct snd_pcm_substream *substream)
{
struct intel8x0m *chip = snd_pcm_substream_chip(substream);
return snd_intel8x0m_pcm_open(substream, &chip->ichd[ICHD_MDMOUT]);
}
static int snd_intel8x0m_playback_close(struct snd_pcm_substream *substream)
{
struct intel8x0m *chip = snd_pcm_substream_chip(substream);
chip->ichd[ICHD_MDMOUT].substream = NULL;
return 0;
}
static int snd_intel8x0m_capture_open(struct snd_pcm_substream *substream)
{
struct intel8x0m *chip = snd_pcm_substream_chip(substream);
return snd_intel8x0m_pcm_open(substream, &chip->ichd[ICHD_MDMIN]);
}
static int snd_intel8x0m_capture_close(struct snd_pcm_substream *substream)
{
struct intel8x0m *chip = snd_pcm_substream_chip(substream);
chip->ichd[ICHD_MDMIN].substream = NULL;
return 0;
}
static int __devinit snd_intel8x0m_pcm1(struct intel8x0m *chip, int device,
struct ich_pcm_table *rec)
{
struct snd_pcm *pcm;
int err;
char name[32];
if (rec->suffix)
sprintf(name, "Intel ICH - %s", rec->suffix);
else
strcpy(name, "Intel ICH");
err = snd_pcm_new(chip->card, name, device,
rec->playback_ops ? 1 : 0,
rec->capture_ops ? 1 : 0, &pcm);
if (err < 0)
return err;
if (rec->playback_ops)
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, rec->playback_ops);
if (rec->capture_ops)
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE, rec->capture_ops);
pcm->private_data = chip;
pcm->info_flags = 0;
pcm->dev_class = SNDRV_PCM_CLASS_MODEM;
if (rec->suffix)
sprintf(pcm->name, "%s - %s", chip->card->shortname, rec->suffix);
else
strcpy(pcm->name, chip->card->shortname);
chip->pcm[device] = pcm;
snd_pcm_lib_preallocate_pages_for_all(pcm, SNDRV_DMA_TYPE_DEV,
snd_dma_pci_data(chip->pci),
rec->prealloc_size,
rec->prealloc_max_size);
return 0;
}
static int __devinit snd_intel8x0m_pcm(struct intel8x0m *chip)
{
int i, tblsize, device, err;
struct ich_pcm_table *tbl, *rec;
#if 1
tbl = intel_pcms;
tblsize = 1;
#else
switch (chip->device_type) {
case DEVICE_NFORCE:
tbl = nforce_pcms;
tblsize = ARRAY_SIZE(nforce_pcms);
break;
case DEVICE_ALI:
tbl = ali_pcms;
tblsize = ARRAY_SIZE(ali_pcms);
break;
default:
tbl = intel_pcms;
tblsize = 2;
break;
}
#endif
device = 0;
for (i = 0; i < tblsize; i++) {
rec = tbl + i;
if (i > 0 && rec->ac97_idx) {
if (! chip->ichd[rec->ac97_idx].ac97)
continue;
}
err = snd_intel8x0m_pcm1(chip, device, rec);
if (err < 0)
return err;
device++;
}
chip->pcm_devs = device;
return 0;
}
static void snd_intel8x0m_mixer_free_ac97_bus(struct snd_ac97_bus *bus)
{
struct intel8x0m *chip = bus->private_data;
chip->ac97_bus = NULL;
}
static void snd_intel8x0m_mixer_free_ac97(struct snd_ac97 *ac97)
{
struct intel8x0m *chip = ac97->private_data;
chip->ac97 = NULL;
}
static int __devinit snd_intel8x0m_mixer(struct intel8x0m *chip, int ac97_clock)
{
struct snd_ac97_bus *pbus;
struct snd_ac97_template ac97;
struct snd_ac97 *x97;
int err;
unsigned int glob_sta = 0;
static struct snd_ac97_bus_ops ops = {
.write = snd_intel8x0m_codec_write,
.read = snd_intel8x0m_codec_read,
};
chip->in_ac97_init = 1;
memset(&ac97, 0, sizeof(ac97));
ac97.private_data = chip;
ac97.private_free = snd_intel8x0m_mixer_free_ac97;
ac97.scaps = AC97_SCAP_SKIP_AUDIO | AC97_SCAP_POWER_SAVE;
glob_sta = igetdword(chip, ICHREG(GLOB_STA));
if ((err = snd_ac97_bus(chip->card, 0, &ops, chip, &pbus)) < 0)
goto __err;
pbus->private_free = snd_intel8x0m_mixer_free_ac97_bus;
if (ac97_clock >= 8000 && ac97_clock <= 48000)
pbus->clock = ac97_clock;
chip->ac97_bus = pbus;
ac97.pci = chip->pci;
ac97.num = glob_sta & ICH_SCR ? 1 : 0;
if ((err = snd_ac97_mixer(pbus, &ac97, &x97)) < 0) {
snd_printk(KERN_ERR "Unable to initialize codec #%d\n", ac97.num);
if (ac97.num == 0)
goto __err;
return err;
}
chip->ac97 = x97;
if(ac97_is_modem(x97) && !chip->ichd[ICHD_MDMIN].ac97) {
chip->ichd[ICHD_MDMIN].ac97 = x97;
chip->ichd[ICHD_MDMOUT].ac97 = x97;
}
chip->in_ac97_init = 0;
return 0;
__err:
if (chip->device_type != DEVICE_ALI)
iputdword(chip, ICHREG(GLOB_CNT),
igetdword(chip, ICHREG(GLOB_CNT)) & ~ICH_AC97COLD);
return err;
}
static int snd_intel8x0m_ich_chip_init(struct intel8x0m *chip, int probing)
{
unsigned long end_time;
unsigned int cnt, status, nstatus;
status = ICH_RCS | ICH_MIINT | ICH_MOINT;
cnt = igetdword(chip, ICHREG(GLOB_STA));
iputdword(chip, ICHREG(GLOB_STA), cnt & status);
cnt = igetdword(chip, ICHREG(GLOB_CNT));
cnt &= ~(ICH_ACLINK);
cnt |= (cnt & ICH_AC97COLD) == 0 ? ICH_AC97COLD : ICH_AC97WARM;
iputdword(chip, ICHREG(GLOB_CNT), cnt);
usleep_range(500, 1000);
end_time = jiffies + HZ / 4;
do {
if ((igetdword(chip, ICHREG(GLOB_CNT)) & ICH_AC97WARM) == 0)
goto __ok;
schedule_timeout_uninterruptible(1);
} while (time_after_eq(end_time, jiffies));
snd_printk(KERN_ERR "AC'97 warm reset still in progress? [0x%x]\n",
igetdword(chip, ICHREG(GLOB_CNT)));
return -EIO;
__ok:
if (probing) {
end_time = jiffies + HZ;
do {
status = igetdword(chip, ICHREG(GLOB_STA)) &
(ICH_PCR | ICH_SCR | ICH_TCR);
if (status)
break;
schedule_timeout_uninterruptible(1);
} while (time_after_eq(end_time, jiffies));
if (! status) {
snd_printk(KERN_ERR "codec_ready: codec is not ready [0x%x]\n",
igetdword(chip, ICHREG(GLOB_STA)));
return -EIO;
}
nstatus = ICH_PCR | ICH_SCR;
end_time = jiffies + HZ / 4;
while (status != nstatus && time_after_eq(end_time, jiffies)) {
schedule_timeout_uninterruptible(1);
status |= igetdword(chip, ICHREG(GLOB_STA)) & nstatus;
}
} else {
status = 0;
if (chip->ac97)
status |= get_ich_codec_bit(chip, chip->ac97->num);
end_time = jiffies + HZ;
do {
nstatus = igetdword(chip, ICHREG(GLOB_STA)) &
(ICH_PCR | ICH_SCR | ICH_TCR);
if (status == nstatus)
break;
schedule_timeout_uninterruptible(1);
} while (time_after_eq(end_time, jiffies));
}
if (chip->device_type == DEVICE_SIS) {
iputword(chip, 0x4c, igetword(chip, 0x4c) | 1);
}
return 0;
}
static int snd_intel8x0m_chip_init(struct intel8x0m *chip, int probing)
{
unsigned int i;
int err;
if ((err = snd_intel8x0m_ich_chip_init(chip, probing)) < 0)
return err;
iagetword(chip, 0);
for (i = 0; i < chip->bdbars_count; i++)
iputbyte(chip, ICH_REG_OFF_CR + chip->ichd[i].reg_offset, 0x00);
for (i = 0; i < chip->bdbars_count; i++)
iputbyte(chip, ICH_REG_OFF_CR + chip->ichd[i].reg_offset, ICH_RESETREGS);
for (i = 0; i < chip->bdbars_count; i++)
iputdword(chip, ICH_REG_OFF_BDBAR + chip->ichd[i].reg_offset, chip->ichd[i].bdbar_addr);
return 0;
}
static int snd_intel8x0m_free(struct intel8x0m *chip)
{
unsigned int i;
if (chip->irq < 0)
goto __hw_end;
for (i = 0; i < chip->bdbars_count; i++)
iputbyte(chip, ICH_REG_OFF_CR + chip->ichd[i].reg_offset, 0x00);
for (i = 0; i < chip->bdbars_count; i++)
iputbyte(chip, ICH_REG_OFF_CR + chip->ichd[i].reg_offset, ICH_RESETREGS);
__hw_end:
if (chip->irq >= 0)
free_irq(chip->irq, chip);
if (chip->bdbars.area)
snd_dma_free_pages(&chip->bdbars);
if (chip->addr)
pci_iounmap(chip->pci, chip->addr);
if (chip->bmaddr)
pci_iounmap(chip->pci, chip->bmaddr);
pci_release_regions(chip->pci);
pci_disable_device(chip->pci);
kfree(chip);
return 0;
}
static int intel8x0m_suspend(struct pci_dev *pci, pm_message_t state)
{
struct snd_card *card = pci_get_drvdata(pci);
struct intel8x0m *chip = card->private_data;
int i;
snd_power_change_state(card, SNDRV_CTL_POWER_D3hot);
for (i = 0; i < chip->pcm_devs; i++)
snd_pcm_suspend_all(chip->pcm[i]);
snd_ac97_suspend(chip->ac97);
if (chip->irq >= 0) {
free_irq(chip->irq, chip);
chip->irq = -1;
}
pci_disable_device(pci);
pci_save_state(pci);
pci_set_power_state(pci, pci_choose_state(pci, state));
return 0;
}
static int intel8x0m_resume(struct pci_dev *pci)
{
struct snd_card *card = pci_get_drvdata(pci);
struct intel8x0m *chip = card->private_data;
pci_set_power_state(pci, PCI_D0);
pci_restore_state(pci);
if (pci_enable_device(pci) < 0) {
printk(KERN_ERR "intel8x0m: pci_enable_device failed, "
"disabling device\n");
snd_card_disconnect(card);
return -EIO;
}
pci_set_master(pci);
if (request_irq(pci->irq, snd_intel8x0m_interrupt,
IRQF_SHARED, card->shortname, chip)) {
printk(KERN_ERR "intel8x0m: unable to grab IRQ %d, "
"disabling device\n", pci->irq);
snd_card_disconnect(card);
return -EIO;
}
chip->irq = pci->irq;
snd_intel8x0m_chip_init(chip, 0);
snd_ac97_resume(chip->ac97);
snd_power_change_state(card, SNDRV_CTL_POWER_D0);
return 0;
}
static void snd_intel8x0m_proc_read(struct snd_info_entry * entry,
struct snd_info_buffer *buffer)
{
struct intel8x0m *chip = entry->private_data;
unsigned int tmp;
snd_iprintf(buffer, "Intel8x0m\n\n");
if (chip->device_type == DEVICE_ALI)
return;
tmp = igetdword(chip, ICHREG(GLOB_STA));
snd_iprintf(buffer, "Global control : 0x%08x\n",
igetdword(chip, ICHREG(GLOB_CNT)));
snd_iprintf(buffer, "Global status : 0x%08x\n", tmp);
snd_iprintf(buffer, "AC'97 codecs ready :%s%s%s%s\n",
tmp & ICH_PCR ? " primary" : "",
tmp & ICH_SCR ? " secondary" : "",
tmp & ICH_TCR ? " tertiary" : "",
(tmp & (ICH_PCR | ICH_SCR | ICH_TCR)) == 0 ? " none" : "");
}
static void __devinit snd_intel8x0m_proc_init(struct intel8x0m * chip)
{
struct snd_info_entry *entry;
if (! snd_card_proc_new(chip->card, "intel8x0m", &entry))
snd_info_set_text_ops(entry, chip, snd_intel8x0m_proc_read);
}
static int snd_intel8x0m_dev_free(struct snd_device *device)
{
struct intel8x0m *chip = device->device_data;
return snd_intel8x0m_free(chip);
}
static int __devinit snd_intel8x0m_create(struct snd_card *card,
struct pci_dev *pci,
unsigned long device_type,
struct intel8x0m **r_intel8x0m)
{
struct intel8x0m *chip;
int err;
unsigned int i;
unsigned int int_sta_masks;
struct ichdev *ichdev;
static struct snd_device_ops ops = {
.dev_free = snd_intel8x0m_dev_free,
};
static struct ich_reg_info intel_regs[2] = {
{ ICH_MIINT, 0 },
{ ICH_MOINT, 0x10 },
};
struct ich_reg_info *tbl;
*r_intel8x0m = NULL;
if ((err = pci_enable_device(pci)) < 0)
return err;
chip = kzalloc(sizeof(*chip), GFP_KERNEL);
if (chip == NULL) {
pci_disable_device(pci);
return -ENOMEM;
}
spin_lock_init(&chip->reg_lock);
chip->device_type = device_type;
chip->card = card;
chip->pci = pci;
chip->irq = -1;
if ((err = pci_request_regions(pci, card->shortname)) < 0) {
kfree(chip);
pci_disable_device(pci);
return err;
}
if (device_type == DEVICE_ALI) {
chip->bmaddr = pci_iomap(pci, 0, 0);
goto port_inited;
}
if (pci_resource_flags(pci, 2) & IORESOURCE_MEM)
chip->addr = pci_iomap(pci, 2, 0);
else
chip->addr = pci_iomap(pci, 0, 0);
if (!chip->addr) {
snd_printk(KERN_ERR "AC'97 space ioremap problem\n");
snd_intel8x0m_free(chip);
return -EIO;
}
if (pci_resource_flags(pci, 3) & IORESOURCE_MEM)
chip->bmaddr = pci_iomap(pci, 3, 0);
else
chip->bmaddr = pci_iomap(pci, 1, 0);
if (!chip->bmaddr) {
snd_printk(KERN_ERR "Controller space ioremap problem\n");
snd_intel8x0m_free(chip);
return -EIO;
}
port_inited:
if (request_irq(pci->irq, snd_intel8x0m_interrupt, IRQF_SHARED,
card->shortname, chip)) {
snd_printk(KERN_ERR "unable to grab IRQ %d\n", pci->irq);
snd_intel8x0m_free(chip);
return -EBUSY;
}
chip->irq = pci->irq;
pci_set_master(pci);
synchronize_irq(chip->irq);
chip->bdbars_count = 2;
tbl = intel_regs;
for (i = 0; i < chip->bdbars_count; i++) {
ichdev = &chip->ichd[i];
ichdev->ichd = i;
ichdev->reg_offset = tbl[i].offset;
ichdev->int_sta_mask = tbl[i].int_sta_mask;
if (device_type == DEVICE_SIS) {
ichdev->roff_sr = ICH_REG_OFF_PICB;
ichdev->roff_picb = ICH_REG_OFF_SR;
} else {
ichdev->roff_sr = ICH_REG_OFF_SR;
ichdev->roff_picb = ICH_REG_OFF_PICB;
}
if (device_type == DEVICE_ALI)
ichdev->ali_slot = (ichdev->reg_offset - 0x40) / 0x10;
}
chip->pcm_pos_shift = (device_type == DEVICE_SIS) ? 0 : 1;
if (snd_dma_alloc_pages(SNDRV_DMA_TYPE_DEV, snd_dma_pci_data(pci),
chip->bdbars_count * sizeof(u32) * ICH_MAX_FRAGS * 2,
&chip->bdbars) < 0) {
snd_intel8x0m_free(chip);
return -ENOMEM;
}
int_sta_masks = 0;
for (i = 0; i < chip->bdbars_count; i++) {
ichdev = &chip->ichd[i];
ichdev->bdbar = ((u32 *)chip->bdbars.area) + (i * ICH_MAX_FRAGS * 2);
ichdev->bdbar_addr = chip->bdbars.addr + (i * sizeof(u32) * ICH_MAX_FRAGS * 2);
int_sta_masks |= ichdev->int_sta_mask;
}
chip->int_sta_reg = ICH_REG_GLOB_STA;
chip->int_sta_mask = int_sta_masks;
if ((err = snd_intel8x0m_chip_init(chip, 1)) < 0) {
snd_intel8x0m_free(chip);
return err;
}
if ((err = snd_device_new(card, SNDRV_DEV_LOWLEVEL, chip, &ops)) < 0) {
snd_intel8x0m_free(chip);
return err;
}
snd_card_set_dev(card, &pci->dev);
*r_intel8x0m = chip;
return 0;
}
static int __devinit snd_intel8x0m_probe(struct pci_dev *pci,
const struct pci_device_id *pci_id)
{
struct snd_card *card;
struct intel8x0m *chip;
int err;
struct shortname_table *name;
err = snd_card_create(index, id, THIS_MODULE, 0, &card);
if (err < 0)
return err;
strcpy(card->driver, "ICH-MODEM");
strcpy(card->shortname, "Intel ICH");
for (name = shortnames; name->id; name++) {
if (pci->device == name->id) {
strcpy(card->shortname, name->s);
break;
}
}
strcat(card->shortname," Modem");
if ((err = snd_intel8x0m_create(card, pci, pci_id->driver_data, &chip)) < 0) {
snd_card_free(card);
return err;
}
card->private_data = chip;
if ((err = snd_intel8x0m_mixer(chip, ac97_clock)) < 0) {
snd_card_free(card);
return err;
}
if ((err = snd_intel8x0m_pcm(chip)) < 0) {
snd_card_free(card);
return err;
}
snd_intel8x0m_proc_init(chip);
sprintf(card->longname, "%s at irq %i",
card->shortname, chip->irq);
if ((err = snd_card_register(card)) < 0) {
snd_card_free(card);
return err;
}
pci_set_drvdata(pci, card);
return 0;
}
static void __devexit snd_intel8x0m_remove(struct pci_dev *pci)
{
snd_card_free(pci_get_drvdata(pci));
pci_set_drvdata(pci, NULL);
}
static int __init alsa_card_intel8x0m_init(void)
{
return pci_register_driver(&driver);
}
static void __exit alsa_card_intel8x0m_exit(void)
{
pci_unregister_driver(&driver);
}
