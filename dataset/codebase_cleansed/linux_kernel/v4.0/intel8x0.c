static inline u8 igetbyte(struct intel8x0 *chip, u32 offset)
{
return ioread8(chip->bmaddr + offset);
}
static inline u16 igetword(struct intel8x0 *chip, u32 offset)
{
return ioread16(chip->bmaddr + offset);
}
static inline u32 igetdword(struct intel8x0 *chip, u32 offset)
{
return ioread32(chip->bmaddr + offset);
}
static inline void iputbyte(struct intel8x0 *chip, u32 offset, u8 val)
{
iowrite8(val, chip->bmaddr + offset);
}
static inline void iputword(struct intel8x0 *chip, u32 offset, u16 val)
{
iowrite16(val, chip->bmaddr + offset);
}
static inline void iputdword(struct intel8x0 *chip, u32 offset, u32 val)
{
iowrite32(val, chip->bmaddr + offset);
}
static inline u16 iagetword(struct intel8x0 *chip, u32 offset)
{
return ioread16(chip->addr + offset);
}
static inline void iaputword(struct intel8x0 *chip, u32 offset, u16 val)
{
iowrite16(val, chip->addr + offset);
}
static int snd_intel8x0_codec_semaphore(struct intel8x0 *chip, unsigned int codec)
{
int time;
if (codec > 2)
return -EIO;
if (chip->in_sdin_init) {
codec = chip->codec_isr_bits;
} else {
codec = chip->codec_bit[chip->ac97_sdin[codec]];
}
if ((igetdword(chip, ICHREG(GLOB_STA)) & codec) == 0)
return -EIO;
if (chip->buggy_semaphore)
return 0;
time = 100;
do {
if (!(igetbyte(chip, ICHREG(ACC_SEMA)) & ICH_CAS))
return 0;
udelay(10);
} while (time--);
dev_err(chip->card->dev,
"codec_semaphore: semaphore is not ready [0x%x][0x%x]\n",
igetbyte(chip, ICHREG(ACC_SEMA)), igetdword(chip, ICHREG(GLOB_STA)));
iagetword(chip, 0);
return -EBUSY;
}
static void snd_intel8x0_codec_write(struct snd_ac97 *ac97,
unsigned short reg,
unsigned short val)
{
struct intel8x0 *chip = ac97->private_data;
if (snd_intel8x0_codec_semaphore(chip, ac97->num) < 0) {
if (! chip->in_ac97_init)
dev_err(chip->card->dev,
"codec_write %d: semaphore is not ready for register 0x%x\n",
ac97->num, reg);
}
iaputword(chip, reg + ac97->num * 0x80, val);
}
static unsigned short snd_intel8x0_codec_read(struct snd_ac97 *ac97,
unsigned short reg)
{
struct intel8x0 *chip = ac97->private_data;
unsigned short res;
unsigned int tmp;
if (snd_intel8x0_codec_semaphore(chip, ac97->num) < 0) {
if (! chip->in_ac97_init)
dev_err(chip->card->dev,
"codec_read %d: semaphore is not ready for register 0x%x\n",
ac97->num, reg);
res = 0xffff;
} else {
res = iagetword(chip, reg + ac97->num * 0x80);
if ((tmp = igetdword(chip, ICHREG(GLOB_STA))) & ICH_RCS) {
iputdword(chip, ICHREG(GLOB_STA), tmp &
~(chip->codec_ready_bits | ICH_GSCI));
if (! chip->in_ac97_init)
dev_err(chip->card->dev,
"codec_read %d: read timeout for register 0x%x\n",
ac97->num, reg);
res = 0xffff;
}
}
return res;
}
static void snd_intel8x0_codec_read_test(struct intel8x0 *chip,
unsigned int codec)
{
unsigned int tmp;
if (snd_intel8x0_codec_semaphore(chip, codec) >= 0) {
iagetword(chip, codec * 0x80);
if ((tmp = igetdword(chip, ICHREG(GLOB_STA))) & ICH_RCS) {
iputdword(chip, ICHREG(GLOB_STA), tmp &
~(chip->codec_ready_bits | ICH_GSCI));
}
}
}
static int snd_intel8x0_ali_codec_ready(struct intel8x0 *chip, int mask)
{
int count = 0;
for (count = 0; count < 0x7f; count++) {
int val = igetbyte(chip, ICHREG(ALI_CSPSR));
if (val & mask)
return 0;
}
if (! chip->in_ac97_init)
dev_warn(chip->card->dev, "AC97 codec ready timeout.\n");
return -EBUSY;
}
static int snd_intel8x0_ali_codec_semaphore(struct intel8x0 *chip)
{
int time = 100;
if (chip->buggy_semaphore)
return 0;
while (--time && (igetdword(chip, ICHREG(ALI_CAS)) & ALI_CAS_SEM_BUSY))
udelay(1);
if (! time && ! chip->in_ac97_init)
dev_warn(chip->card->dev, "ali_codec_semaphore timeout\n");
return snd_intel8x0_ali_codec_ready(chip, ALI_CSPSR_CODEC_READY);
}
static unsigned short snd_intel8x0_ali_codec_read(struct snd_ac97 *ac97, unsigned short reg)
{
struct intel8x0 *chip = ac97->private_data;
unsigned short data = 0xffff;
if (snd_intel8x0_ali_codec_semaphore(chip))
goto __err;
reg |= ALI_CPR_ADDR_READ;
if (ac97->num)
reg |= ALI_CPR_ADDR_SECONDARY;
iputword(chip, ICHREG(ALI_CPR_ADDR), reg);
if (snd_intel8x0_ali_codec_ready(chip, ALI_CSPSR_READ_OK))
goto __err;
data = igetword(chip, ICHREG(ALI_SPR));
__err:
return data;
}
static void snd_intel8x0_ali_codec_write(struct snd_ac97 *ac97, unsigned short reg,
unsigned short val)
{
struct intel8x0 *chip = ac97->private_data;
if (snd_intel8x0_ali_codec_semaphore(chip))
return;
iputword(chip, ICHREG(ALI_CPR), val);
if (ac97->num)
reg |= ALI_CPR_ADDR_SECONDARY;
iputword(chip, ICHREG(ALI_CPR_ADDR), reg);
snd_intel8x0_ali_codec_ready(chip, ALI_CSPSR_WRITE_OK);
}
static void snd_intel8x0_setup_periods(struct intel8x0 *chip, struct ichdev *ichdev)
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
ichdev->fragsize1 >> ichdev->pos_shift);
bdbar[idx + 2] = cpu_to_le32(ichdev->physbuf + (ichdev->size >> 1));
bdbar[idx + 3] = cpu_to_le32(0x80000000 |
ichdev->fragsize1 >> ichdev->pos_shift);
}
ichdev->frags = 2;
} else {
ichdev->ack_reload = ichdev->ack = 1;
ichdev->fragsize1 = ichdev->fragsize;
for (idx = 0; idx < (ICH_REG_LVI_MASK + 1) * 2; idx += 2) {
bdbar[idx + 0] = cpu_to_le32(ichdev->physbuf +
(((idx >> 1) * ichdev->fragsize) %
ichdev->size));
bdbar[idx + 1] = cpu_to_le32(0x80000000 |
ichdev->fragsize >> ichdev->pos_shift);
#if 0
dev_dbg(chip->card->dev, "bdbar[%i] = 0x%x [0x%x]\n",
idx + 0, bdbar[idx + 0], bdbar[idx + 1]);
#endif
}
ichdev->frags = ichdev->size / ichdev->fragsize;
}
iputbyte(chip, port + ICH_REG_OFF_LVI, ichdev->lvi = ICH_REG_LVI_MASK);
ichdev->civ = 0;
iputbyte(chip, port + ICH_REG_OFF_CIV, 0);
ichdev->lvi_frag = ICH_REG_LVI_MASK % ichdev->frags;
ichdev->position = 0;
#if 0
dev_dbg(chip->card->dev,
"lvi_frag = %i, frags = %i, period_size = 0x%x, period_size1 = 0x%x\n",
ichdev->lvi_frag, ichdev->frags, ichdev->fragsize,
ichdev->fragsize1);
#endif
iputbyte(chip, port + ichdev->roff_sr, ICH_FIFOE | ICH_BCIS | ICH_LVBCI);
}
static void fill_nocache(void *buf, int size, int nocache)
{
size = (size + PAGE_SIZE - 1) >> PAGE_SHIFT;
if (nocache)
set_pages_uc(virt_to_page(buf), size);
else
set_pages_wb(virt_to_page(buf), size);
}
static inline void snd_intel8x0_update(struct intel8x0 *chip, struct ichdev *ichdev)
{
unsigned long port = ichdev->reg_offset;
unsigned long flags;
int status, civ, i, step;
int ack = 0;
spin_lock_irqsave(&chip->reg_lock, flags);
status = igetbyte(chip, port + ichdev->roff_sr);
civ = igetbyte(chip, port + ICH_REG_OFF_CIV);
if (!(status & ICH_BCIS)) {
step = 0;
} else if (civ == ichdev->civ) {
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
if (! chip->in_measurement)
ichdev->position %= ichdev->size;
ichdev->lvi += step;
ichdev->lvi &= ICH_REG_LVI_MASK;
iputbyte(chip, port + ICH_REG_OFF_LVI, ichdev->lvi);
for (i = 0; i < step; i++) {
ichdev->lvi_frag++;
ichdev->lvi_frag %= ichdev->frags;
ichdev->bdbar[ichdev->lvi * 2] = cpu_to_le32(ichdev->physbuf + ichdev->lvi_frag * ichdev->fragsize1);
#if 0
dev_dbg(chip->card->dev,
"new: bdbar[%i] = 0x%x [0x%x], prefetch = %i, all = 0x%x, 0x%x\n",
ichdev->lvi * 2, ichdev->bdbar[ichdev->lvi * 2],
ichdev->bdbar[ichdev->lvi * 2 + 1], inb(ICH_REG_OFF_PIV + port),
inl(port + 4), inb(port + ICH_REG_OFF_CR));
#endif
if (--ichdev->ack == 0) {
ichdev->ack = ichdev->ack_reload;
ack = 1;
}
}
spin_unlock_irqrestore(&chip->reg_lock, flags);
if (ack && ichdev->substream) {
snd_pcm_period_elapsed(ichdev->substream);
}
iputbyte(chip, port + ichdev->roff_sr,
status & (ICH_FIFOE | ICH_BCIS | ICH_LVBCI));
}
static irqreturn_t snd_intel8x0_interrupt(int irq, void *dev_id)
{
struct intel8x0 *chip = dev_id;
struct ichdev *ichdev;
unsigned int status;
unsigned int i;
status = igetdword(chip, chip->int_sta_reg);
if (status == 0xffffffff)
return IRQ_NONE;
if ((status & chip->int_sta_mask) == 0) {
if (status) {
iputdword(chip, chip->int_sta_reg, status);
if (! chip->buggy_irq)
status = 0;
}
return IRQ_RETVAL(status);
}
for (i = 0; i < chip->bdbars_count; i++) {
ichdev = &chip->ichd[i];
if (status & ichdev->int_sta_mask)
snd_intel8x0_update(chip, ichdev);
}
iputdword(chip, chip->int_sta_reg, status & chip->int_sta_mask);
return IRQ_HANDLED;
}
static int snd_intel8x0_pcm_trigger(struct snd_pcm_substream *substream, int cmd)
{
struct intel8x0 *chip = snd_pcm_substream_chip(substream);
struct ichdev *ichdev = get_ichdev(substream);
unsigned char val = 0;
unsigned long port = ichdev->reg_offset;
switch (cmd) {
case SNDRV_PCM_TRIGGER_RESUME:
ichdev->suspended = 0;
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
val = ICH_IOCE | ICH_STARTBM;
ichdev->last_pos = ichdev->position;
break;
case SNDRV_PCM_TRIGGER_SUSPEND:
ichdev->suspended = 1;
case SNDRV_PCM_TRIGGER_STOP:
val = 0;
break;
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
val = ICH_IOCE;
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
static int snd_intel8x0_ali_trigger(struct snd_pcm_substream *substream, int cmd)
{
struct intel8x0 *chip = snd_pcm_substream_chip(substream);
struct ichdev *ichdev = get_ichdev(substream);
unsigned long port = ichdev->reg_offset;
static int fiforeg[] = {
ICHREG(ALI_FIFOCR1), ICHREG(ALI_FIFOCR2), ICHREG(ALI_FIFOCR3)
};
unsigned int val, fifo;
val = igetdword(chip, ICHREG(ALI_DMACR));
switch (cmd) {
case SNDRV_PCM_TRIGGER_RESUME:
ichdev->suspended = 0;
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
fifo = igetdword(chip, fiforeg[ichdev->ali_slot / 4]);
fifo &= ~(0xff << (ichdev->ali_slot % 4));
fifo |= 0x83 << (ichdev->ali_slot % 4);
iputdword(chip, fiforeg[ichdev->ali_slot / 4], fifo);
}
iputbyte(chip, port + ICH_REG_OFF_CR, ICH_IOCE);
val &= ~(1 << (ichdev->ali_slot + 16));
iputdword(chip, ICHREG(ALI_DMACR), val | (1 << ichdev->ali_slot));
break;
case SNDRV_PCM_TRIGGER_SUSPEND:
ichdev->suspended = 1;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
iputdword(chip, ICHREG(ALI_DMACR), val | (1 << (ichdev->ali_slot + 16)));
iputbyte(chip, port + ICH_REG_OFF_CR, 0);
while (igetbyte(chip, port + ICH_REG_OFF_CR))
;
if (cmd == SNDRV_PCM_TRIGGER_PAUSE_PUSH)
break;
iputbyte(chip, port + ICH_REG_OFF_CR, ICH_RESETREGS);
iputbyte(chip, port + ICH_REG_OFF_SR,
igetbyte(chip, port + ICH_REG_OFF_SR) | 0x1e);
iputdword(chip, ICHREG(ALI_INTERRUPTSR),
igetdword(chip, ICHREG(ALI_INTERRUPTSR)) & ichdev->int_sta_mask);
break;
default:
return -EINVAL;
}
return 0;
}
static int snd_intel8x0_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
struct intel8x0 *chip = snd_pcm_substream_chip(substream);
struct ichdev *ichdev = get_ichdev(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
int dbl = params_rate(hw_params) > 48000;
int err;
if (chip->fix_nocache && ichdev->page_attr_changed) {
fill_nocache(runtime->dma_area, runtime->dma_bytes, 0);
ichdev->page_attr_changed = 0;
}
err = snd_pcm_lib_malloc_pages(substream, params_buffer_bytes(hw_params));
if (err < 0)
return err;
if (chip->fix_nocache) {
if (runtime->dma_area && ! ichdev->page_attr_changed) {
fill_nocache(runtime->dma_area, runtime->dma_bytes, 1);
ichdev->page_attr_changed = 1;
}
}
if (ichdev->pcm_open_flag) {
snd_ac97_pcm_close(ichdev->pcm);
ichdev->pcm_open_flag = 0;
}
err = snd_ac97_pcm_open(ichdev->pcm, params_rate(hw_params),
params_channels(hw_params),
ichdev->pcm->r[dbl].slots);
if (err >= 0) {
ichdev->pcm_open_flag = 1;
if (ichdev->ichd == ICHD_PCMOUT && chip->spdif_idx < 0)
snd_ac97_set_rate(ichdev->pcm->r[0].codec[0], AC97_SPDIF,
params_rate(hw_params));
}
return err;
}
static int snd_intel8x0_hw_free(struct snd_pcm_substream *substream)
{
struct intel8x0 *chip = snd_pcm_substream_chip(substream);
struct ichdev *ichdev = get_ichdev(substream);
if (ichdev->pcm_open_flag) {
snd_ac97_pcm_close(ichdev->pcm);
ichdev->pcm_open_flag = 0;
}
if (chip->fix_nocache && ichdev->page_attr_changed) {
fill_nocache(substream->runtime->dma_area, substream->runtime->dma_bytes, 0);
ichdev->page_attr_changed = 0;
}
return snd_pcm_lib_free_pages(substream);
}
static void snd_intel8x0_setup_pcm_out(struct intel8x0 *chip,
struct snd_pcm_runtime *runtime)
{
unsigned int cnt;
int dbl = runtime->rate > 48000;
spin_lock_irq(&chip->reg_lock);
switch (chip->device_type) {
case DEVICE_ALI:
cnt = igetdword(chip, ICHREG(ALI_SCR));
cnt &= ~ICH_ALI_SC_PCM_246_MASK;
if (runtime->channels == 4 || dbl)
cnt |= ICH_ALI_SC_PCM_4;
else if (runtime->channels == 6)
cnt |= ICH_ALI_SC_PCM_6;
iputdword(chip, ICHREG(ALI_SCR), cnt);
break;
case DEVICE_SIS:
cnt = igetdword(chip, ICHREG(GLOB_CNT));
cnt &= ~ICH_SIS_PCM_246_MASK;
if (runtime->channels == 4 || dbl)
cnt |= ICH_SIS_PCM_4;
else if (runtime->channels == 6)
cnt |= ICH_SIS_PCM_6;
iputdword(chip, ICHREG(GLOB_CNT), cnt);
break;
default:
cnt = igetdword(chip, ICHREG(GLOB_CNT));
cnt &= ~(ICH_PCM_246_MASK | ICH_PCM_20BIT);
if (runtime->channels == 4 || dbl)
cnt |= ICH_PCM_4;
else if (runtime->channels == 6)
cnt |= ICH_PCM_6;
else if (runtime->channels == 8)
cnt |= ICH_PCM_8;
if (chip->device_type == DEVICE_NFORCE) {
if (cnt & ICH_PCM_246_MASK) {
iputdword(chip, ICHREG(GLOB_CNT), cnt & ~ICH_PCM_246_MASK);
spin_unlock_irq(&chip->reg_lock);
msleep(50);
spin_lock_irq(&chip->reg_lock);
}
} else if (chip->device_type == DEVICE_INTEL_ICH4) {
if (runtime->sample_bits > 16)
cnt |= ICH_PCM_20BIT;
}
iputdword(chip, ICHREG(GLOB_CNT), cnt);
break;
}
spin_unlock_irq(&chip->reg_lock);
}
static int snd_intel8x0_pcm_prepare(struct snd_pcm_substream *substream)
{
struct intel8x0 *chip = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct ichdev *ichdev = get_ichdev(substream);
ichdev->physbuf = runtime->dma_addr;
ichdev->size = snd_pcm_lib_buffer_bytes(substream);
ichdev->fragsize = snd_pcm_lib_period_bytes(substream);
if (ichdev->ichd == ICHD_PCMOUT) {
snd_intel8x0_setup_pcm_out(chip, runtime);
if (chip->device_type == DEVICE_INTEL_ICH4)
ichdev->pos_shift = (runtime->sample_bits > 16) ? 2 : 1;
}
snd_intel8x0_setup_periods(chip, ichdev);
return 0;
}
static snd_pcm_uframes_t snd_intel8x0_pcm_pointer(struct snd_pcm_substream *substream)
{
struct intel8x0 *chip = snd_pcm_substream_chip(substream);
struct ichdev *ichdev = get_ichdev(substream);
size_t ptr1, ptr;
int civ, timeout = 10;
unsigned int position;
spin_lock(&chip->reg_lock);
do {
civ = igetbyte(chip, ichdev->reg_offset + ICH_REG_OFF_CIV);
ptr1 = igetword(chip, ichdev->reg_offset + ichdev->roff_picb);
position = ichdev->position;
if (ptr1 == 0) {
udelay(10);
continue;
}
if (civ != igetbyte(chip, ichdev->reg_offset + ICH_REG_OFF_CIV))
continue;
if (chip->inside_vm)
break;
if (ptr1 == igetword(chip, ichdev->reg_offset + ichdev->roff_picb))
break;
} while (timeout--);
ptr = ichdev->last_pos;
if (ptr1 != 0) {
ptr1 <<= ichdev->pos_shift;
ptr = ichdev->fragsize1 - ptr1;
ptr += position;
if (ptr < ichdev->last_pos) {
unsigned int pos_base, last_base;
pos_base = position / ichdev->fragsize1;
last_base = ichdev->last_pos / ichdev->fragsize1;
if (pos_base == last_base)
ptr = ichdev->last_pos;
}
}
ichdev->last_pos = ptr;
spin_unlock(&chip->reg_lock);
if (ptr >= ichdev->size)
return 0;
return bytes_to_frames(substream->runtime, ptr);
}
static int snd_intel8x0_pcm_open(struct snd_pcm_substream *substream, struct ichdev *ichdev)
{
struct intel8x0 *chip = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
int err;
ichdev->substream = substream;
runtime->hw = snd_intel8x0_stream;
runtime->hw.rates = ichdev->pcm->rates;
snd_pcm_limit_hw_rates(runtime);
if (chip->device_type == DEVICE_SIS) {
runtime->hw.buffer_bytes_max = 64*1024;
runtime->hw.period_bytes_max = 64*1024;
}
if ((err = snd_pcm_hw_constraint_integer(runtime, SNDRV_PCM_HW_PARAM_PERIODS)) < 0)
return err;
runtime->private_data = ichdev;
return 0;
}
static int snd_intel8x0_playback_open(struct snd_pcm_substream *substream)
{
struct intel8x0 *chip = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
int err;
err = snd_intel8x0_pcm_open(substream, &chip->ichd[ICHD_PCMOUT]);
if (err < 0)
return err;
if (chip->multi8) {
runtime->hw.channels_max = 8;
snd_pcm_hw_constraint_list(runtime, 0,
SNDRV_PCM_HW_PARAM_CHANNELS,
&hw_constraints_channels8);
} else if (chip->multi6) {
runtime->hw.channels_max = 6;
snd_pcm_hw_constraint_list(runtime, 0, SNDRV_PCM_HW_PARAM_CHANNELS,
&hw_constraints_channels6);
} else if (chip->multi4) {
runtime->hw.channels_max = 4;
snd_pcm_hw_constraint_list(runtime, 0, SNDRV_PCM_HW_PARAM_CHANNELS,
&hw_constraints_channels4);
}
if (chip->dra) {
snd_ac97_pcm_double_rate_rules(runtime);
}
if (chip->smp20bit) {
runtime->hw.formats |= SNDRV_PCM_FMTBIT_S32_LE;
snd_pcm_hw_constraint_msbits(runtime, 0, 32, 20);
}
return 0;
}
static int snd_intel8x0_playback_close(struct snd_pcm_substream *substream)
{
struct intel8x0 *chip = snd_pcm_substream_chip(substream);
chip->ichd[ICHD_PCMOUT].substream = NULL;
return 0;
}
static int snd_intel8x0_capture_open(struct snd_pcm_substream *substream)
{
struct intel8x0 *chip = snd_pcm_substream_chip(substream);
return snd_intel8x0_pcm_open(substream, &chip->ichd[ICHD_PCMIN]);
}
static int snd_intel8x0_capture_close(struct snd_pcm_substream *substream)
{
struct intel8x0 *chip = snd_pcm_substream_chip(substream);
chip->ichd[ICHD_PCMIN].substream = NULL;
return 0;
}
static int snd_intel8x0_mic_open(struct snd_pcm_substream *substream)
{
struct intel8x0 *chip = snd_pcm_substream_chip(substream);
return snd_intel8x0_pcm_open(substream, &chip->ichd[ICHD_MIC]);
}
static int snd_intel8x0_mic_close(struct snd_pcm_substream *substream)
{
struct intel8x0 *chip = snd_pcm_substream_chip(substream);
chip->ichd[ICHD_MIC].substream = NULL;
return 0;
}
static int snd_intel8x0_mic2_open(struct snd_pcm_substream *substream)
{
struct intel8x0 *chip = snd_pcm_substream_chip(substream);
return snd_intel8x0_pcm_open(substream, &chip->ichd[ICHD_MIC2]);
}
static int snd_intel8x0_mic2_close(struct snd_pcm_substream *substream)
{
struct intel8x0 *chip = snd_pcm_substream_chip(substream);
chip->ichd[ICHD_MIC2].substream = NULL;
return 0;
}
static int snd_intel8x0_capture2_open(struct snd_pcm_substream *substream)
{
struct intel8x0 *chip = snd_pcm_substream_chip(substream);
return snd_intel8x0_pcm_open(substream, &chip->ichd[ICHD_PCM2IN]);
}
static int snd_intel8x0_capture2_close(struct snd_pcm_substream *substream)
{
struct intel8x0 *chip = snd_pcm_substream_chip(substream);
chip->ichd[ICHD_PCM2IN].substream = NULL;
return 0;
}
static int snd_intel8x0_spdif_open(struct snd_pcm_substream *substream)
{
struct intel8x0 *chip = snd_pcm_substream_chip(substream);
int idx = chip->device_type == DEVICE_NFORCE ? NVD_SPBAR : ICHD_SPBAR;
return snd_intel8x0_pcm_open(substream, &chip->ichd[idx]);
}
static int snd_intel8x0_spdif_close(struct snd_pcm_substream *substream)
{
struct intel8x0 *chip = snd_pcm_substream_chip(substream);
int idx = chip->device_type == DEVICE_NFORCE ? NVD_SPBAR : ICHD_SPBAR;
chip->ichd[idx].substream = NULL;
return 0;
}
static int snd_intel8x0_ali_ac97spdifout_open(struct snd_pcm_substream *substream)
{
struct intel8x0 *chip = snd_pcm_substream_chip(substream);
unsigned int val;
spin_lock_irq(&chip->reg_lock);
val = igetdword(chip, ICHREG(ALI_INTERFACECR));
val |= ICH_ALI_IF_AC97SP;
iputdword(chip, ICHREG(ALI_INTERFACECR), val);
spin_unlock_irq(&chip->reg_lock);
return snd_intel8x0_pcm_open(substream, &chip->ichd[ALID_AC97SPDIFOUT]);
}
static int snd_intel8x0_ali_ac97spdifout_close(struct snd_pcm_substream *substream)
{
struct intel8x0 *chip = snd_pcm_substream_chip(substream);
unsigned int val;
chip->ichd[ALID_AC97SPDIFOUT].substream = NULL;
spin_lock_irq(&chip->reg_lock);
val = igetdword(chip, ICHREG(ALI_INTERFACECR));
val &= ~ICH_ALI_IF_AC97SP;
iputdword(chip, ICHREG(ALI_INTERFACECR), val);
spin_unlock_irq(&chip->reg_lock);
return 0;
}
static int snd_intel8x0_pcm1(struct intel8x0 *chip, int device,
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
if (rec->suffix)
sprintf(pcm->name, "%s - %s", chip->card->shortname, rec->suffix);
else
strcpy(pcm->name, chip->card->shortname);
chip->pcm[device] = pcm;
snd_pcm_lib_preallocate_pages_for_all(pcm, SNDRV_DMA_TYPE_DEV,
snd_dma_pci_data(chip->pci),
rec->prealloc_size, rec->prealloc_max_size);
if (rec->playback_ops &&
rec->playback_ops->open == snd_intel8x0_playback_open) {
struct snd_pcm_chmap *chmap;
int chs = 2;
if (chip->multi8)
chs = 8;
else if (chip->multi6)
chs = 6;
else if (chip->multi4)
chs = 4;
err = snd_pcm_add_chmap_ctls(pcm, SNDRV_PCM_STREAM_PLAYBACK,
snd_pcm_alt_chmaps, chs, 0,
&chmap);
if (err < 0)
return err;
chmap->channel_mask = SND_PCM_CHMAP_MASK_2468;
chip->ac97[0]->chmaps[SNDRV_PCM_STREAM_PLAYBACK] = chmap;
}
return 0;
}
static int snd_intel8x0_pcm(struct intel8x0 *chip)
{
int i, tblsize, device, err;
struct ich_pcm_table *tbl, *rec;
switch (chip->device_type) {
case DEVICE_INTEL_ICH4:
tbl = intel_pcms;
tblsize = ARRAY_SIZE(intel_pcms);
if (spdif_aclink)
tblsize--;
break;
case DEVICE_NFORCE:
tbl = nforce_pcms;
tblsize = ARRAY_SIZE(nforce_pcms);
if (spdif_aclink)
tblsize--;
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
device = 0;
for (i = 0; i < tblsize; i++) {
rec = tbl + i;
if (i > 0 && rec->ac97_idx) {
if (! chip->ichd[rec->ac97_idx].pcm)
continue;
}
err = snd_intel8x0_pcm1(chip, device, rec);
if (err < 0)
return err;
device++;
}
chip->pcm_devs = device;
return 0;
}
static void snd_intel8x0_mixer_free_ac97_bus(struct snd_ac97_bus *bus)
{
struct intel8x0 *chip = bus->private_data;
chip->ac97_bus = NULL;
}
static void snd_intel8x0_mixer_free_ac97(struct snd_ac97 *ac97)
{
struct intel8x0 *chip = ac97->private_data;
chip->ac97[ac97->num] = NULL;
}
static int snd_intel8x0_mixer(struct intel8x0 *chip, int ac97_clock,
const char *quirk_override)
{
struct snd_ac97_bus *pbus;
struct snd_ac97_template ac97;
int err;
unsigned int i, codecs;
unsigned int glob_sta = 0;
struct snd_ac97_bus_ops *ops;
static struct snd_ac97_bus_ops standard_bus_ops = {
.write = snd_intel8x0_codec_write,
.read = snd_intel8x0_codec_read,
};
static struct snd_ac97_bus_ops ali_bus_ops = {
.write = snd_intel8x0_ali_codec_write,
.read = snd_intel8x0_ali_codec_read,
};
chip->spdif_idx = -1;
if (!spdif_aclink) {
switch (chip->device_type) {
case DEVICE_NFORCE:
chip->spdif_idx = NVD_SPBAR;
break;
case DEVICE_ALI:
chip->spdif_idx = ALID_AC97SPDIFOUT;
break;
case DEVICE_INTEL_ICH4:
chip->spdif_idx = ICHD_SPBAR;
break;
}
}
chip->in_ac97_init = 1;
memset(&ac97, 0, sizeof(ac97));
ac97.private_data = chip;
ac97.private_free = snd_intel8x0_mixer_free_ac97;
ac97.scaps = AC97_SCAP_SKIP_MODEM | AC97_SCAP_POWER_SAVE;
if (chip->xbox)
ac97.scaps |= AC97_SCAP_DETECT_BY_VENDOR;
if (chip->device_type != DEVICE_ALI) {
glob_sta = igetdword(chip, ICHREG(GLOB_STA));
ops = &standard_bus_ops;
chip->in_sdin_init = 1;
codecs = 0;
for (i = 0; i < chip->max_codecs; i++) {
if (! (glob_sta & chip->codec_bit[i]))
continue;
if (chip->device_type == DEVICE_INTEL_ICH4) {
snd_intel8x0_codec_read_test(chip, codecs);
chip->ac97_sdin[codecs] =
igetbyte(chip, ICHREG(SDM)) & ICH_LDI_MASK;
if (snd_BUG_ON(chip->ac97_sdin[codecs] >= 3))
chip->ac97_sdin[codecs] = 0;
} else
chip->ac97_sdin[codecs] = i;
codecs++;
}
chip->in_sdin_init = 0;
if (! codecs)
codecs = 1;
} else {
ops = &ali_bus_ops;
codecs = 1;
for (i = 0; i < 100; i++) {
unsigned int reg = igetdword(chip, ICHREG(ALI_RTSR));
if (reg & 0x40) {
codecs = 2;
break;
}
iputdword(chip, ICHREG(ALI_RTSR), reg | 0x40);
udelay(1);
}
}
if ((err = snd_ac97_bus(chip->card, 0, ops, chip, &pbus)) < 0)
goto __err;
pbus->private_free = snd_intel8x0_mixer_free_ac97_bus;
if (ac97_clock >= 8000 && ac97_clock <= 48000)
pbus->clock = ac97_clock;
if (chip->device_type == DEVICE_ALI)
pbus->no_vra = 1;
else
pbus->dra = 1;
chip->ac97_bus = pbus;
chip->ncodecs = codecs;
ac97.pci = chip->pci;
for (i = 0; i < codecs; i++) {
ac97.num = i;
if ((err = snd_ac97_mixer(pbus, &ac97, &chip->ac97[i])) < 0) {
if (err != -EACCES)
dev_err(chip->card->dev,
"Unable to initialize codec #%d\n", i);
if (i == 0)
goto __err;
}
}
snd_ac97_tune_hardware(chip->ac97[0], ac97_quirks, quirk_override);
if (chip->device_type == DEVICE_INTEL_ICH4)
pbus->isdin = 1;
i = ARRAY_SIZE(ac97_pcm_defs);
if (chip->device_type != DEVICE_INTEL_ICH4)
i -= 2;
if (chip->spdif_idx < 0)
i--;
err = snd_ac97_pcm_assign(pbus, i, ac97_pcm_defs);
if (err < 0)
goto __err;
chip->ichd[ICHD_PCMOUT].pcm = &pbus->pcms[0];
chip->ichd[ICHD_PCMIN].pcm = &pbus->pcms[1];
chip->ichd[ICHD_MIC].pcm = &pbus->pcms[2];
if (chip->spdif_idx >= 0)
chip->ichd[chip->spdif_idx].pcm = &pbus->pcms[3];
if (chip->device_type == DEVICE_INTEL_ICH4) {
chip->ichd[ICHD_PCM2IN].pcm = &pbus->pcms[4];
chip->ichd[ICHD_MIC2].pcm = &pbus->pcms[5];
}
if (chip->device_type == DEVICE_INTEL_ICH4) {
struct ac97_pcm *pcm = chip->ichd[ICHD_PCM2IN].pcm;
u8 tmp = igetbyte(chip, ICHREG(SDM));
tmp &= ~(ICH_DI2L_MASK|ICH_DI1L_MASK);
if (pcm) {
tmp |= ICH_SE;
tmp |= chip->ac97_sdin[0] << ICH_DI1L_SHIFT;
for (i = 1; i < 4; i++) {
if (pcm->r[0].codec[i]) {
tmp |= chip->ac97_sdin[pcm->r[0].codec[1]->num] << ICH_DI2L_SHIFT;
break;
}
}
} else {
tmp &= ~ICH_SE;
}
iputbyte(chip, ICHREG(SDM), tmp);
}
if (pbus->pcms[0].r[0].slots & (1 << AC97_SLOT_PCM_SLEFT)) {
chip->multi4 = 1;
if (pbus->pcms[0].r[0].slots & (1 << AC97_SLOT_LFE)) {
chip->multi6 = 1;
if (chip->ac97[0]->flags & AC97_HAS_8CH)
chip->multi8 = 1;
}
}
if (pbus->pcms[0].r[1].rslots[0]) {
chip->dra = 1;
}
if (chip->device_type == DEVICE_INTEL_ICH4) {
if ((igetdword(chip, ICHREG(GLOB_STA)) & ICH_SAMPLE_CAP) == ICH_SAMPLE_16_20)
chip->smp20bit = 1;
}
if (chip->device_type == DEVICE_NFORCE && !spdif_aclink) {
chip->ichd[chip->spdif_idx].pcm->rates = SNDRV_PCM_RATE_48000;
}
if (chip->device_type == DEVICE_INTEL_ICH4 && !spdif_aclink) {
u32 val;
val = igetdword(chip, ICHREG(GLOB_CNT)) & ~ICH_PCM_SPDIF_MASK;
val |= ICH_PCM_SPDIF_1011;
iputdword(chip, ICHREG(GLOB_CNT), val);
snd_ac97_update_bits(chip->ac97[0], AC97_EXTENDED_STATUS, 0x03 << 4, 0x03 << 4);
}
chip->in_ac97_init = 0;
return 0;
__err:
if (chip->device_type != DEVICE_ALI)
iputdword(chip, ICHREG(GLOB_CNT),
igetdword(chip, ICHREG(GLOB_CNT)) & ~ICH_AC97COLD);
return err;
}
static void do_ali_reset(struct intel8x0 *chip)
{
iputdword(chip, ICHREG(ALI_SCR), ICH_ALI_SC_RESET);
iputdword(chip, ICHREG(ALI_FIFOCR1), 0x83838383);
iputdword(chip, ICHREG(ALI_FIFOCR2), 0x83838383);
iputdword(chip, ICHREG(ALI_FIFOCR3), 0x83838383);
iputdword(chip, ICHREG(ALI_INTERFACECR),
ICH_ALI_IF_PI|ICH_ALI_IF_PO);
iputdword(chip, ICHREG(ALI_INTERRUPTCR), 0x00000000);
iputdword(chip, ICHREG(ALI_INTERRUPTSR), 0x00000000);
}
static int snd_intel8x0_ich_chip_cold_reset(struct intel8x0 *chip)
{
unsigned int cnt;
if (snd_pci_quirk_lookup(chip->pci, ich_chip_reset_mode))
return -EIO;
cnt = igetdword(chip, ICHREG(GLOB_CNT));
cnt &= ~(ICH_ACLINK | ICH_PCM_246_MASK);
iputdword(chip, ICHREG(GLOB_CNT), cnt & ~ICH_AC97COLD);
cnt = igetdword(chip, ICHREG(GLOB_CNT));
udelay(10);
iputdword(chip, ICHREG(GLOB_CNT), cnt | ICH_AC97COLD);
msleep(1);
return 0;
}
static int snd_intel8x0_ich_chip_reset(struct intel8x0 *chip)
{
unsigned long end_time;
unsigned int cnt;
cnt = igetdword(chip, ICHREG(GLOB_CNT));
cnt &= ~(ICH_ACLINK | ICH_PCM_246_MASK);
cnt |= (cnt & ICH_AC97COLD) == 0 ? ICH_AC97COLD : ICH_AC97WARM;
iputdword(chip, ICHREG(GLOB_CNT), cnt);
end_time = (jiffies + (HZ / 4)) + 1;
do {
if ((igetdword(chip, ICHREG(GLOB_CNT)) & ICH_AC97WARM) == 0)
return 0;
schedule_timeout_uninterruptible(1);
} while (time_after_eq(end_time, jiffies));
dev_err(chip->card->dev, "AC'97 warm reset still in progress? [0x%x]\n",
igetdword(chip, ICHREG(GLOB_CNT)));
return -EIO;
}
static int snd_intel8x0_ich_chip_init(struct intel8x0 *chip, int probing)
{
unsigned long end_time;
unsigned int status, nstatus;
unsigned int cnt;
int err;
status = ICH_RCS | ICH_MCINT | ICH_POINT | ICH_PIINT;
if (chip->device_type == DEVICE_NFORCE)
status |= ICH_NVSPINT;
cnt = igetdword(chip, ICHREG(GLOB_STA));
iputdword(chip, ICHREG(GLOB_STA), cnt & status);
if (snd_intel8x0_ich_chip_can_cold_reset(chip))
err = snd_intel8x0_ich_chip_cold_reset(chip);
else
err = snd_intel8x0_ich_chip_reset(chip);
if (err < 0)
return err;
if (probing) {
end_time = jiffies + HZ;
do {
status = igetdword(chip, ICHREG(GLOB_STA)) &
chip->codec_isr_bits;
if (status)
break;
schedule_timeout_uninterruptible(1);
} while (time_after_eq(end_time, jiffies));
if (! status) {
dev_err(chip->card->dev,
"codec_ready: codec is not ready [0x%x]\n",
igetdword(chip, ICHREG(GLOB_STA)));
return -EIO;
}
end_time = jiffies + HZ / 4;
while (status != chip->codec_isr_bits &&
time_after_eq(end_time, jiffies)) {
schedule_timeout_uninterruptible(1);
status |= igetdword(chip, ICHREG(GLOB_STA)) &
chip->codec_isr_bits;
}
} else {
int i;
status = 0;
for (i = 0; i < chip->ncodecs; i++)
if (chip->ac97[i])
status |= chip->codec_bit[chip->ac97_sdin[i]];
end_time = jiffies + HZ;
do {
nstatus = igetdword(chip, ICHREG(GLOB_STA)) &
chip->codec_isr_bits;
if (status == nstatus)
break;
schedule_timeout_uninterruptible(1);
} while (time_after_eq(end_time, jiffies));
}
if (chip->device_type == DEVICE_SIS) {
iputword(chip, 0x4c, igetword(chip, 0x4c) | 1);
}
if (chip->device_type == DEVICE_NFORCE && !spdif_aclink) {
unsigned int val;
pci_read_config_dword(chip->pci, 0x4c, &val);
val |= 0x1000000;
pci_write_config_dword(chip->pci, 0x4c, val);
}
return 0;
}
static int snd_intel8x0_ali_chip_init(struct intel8x0 *chip, int probing)
{
u32 reg;
int i = 0;
reg = igetdword(chip, ICHREG(ALI_SCR));
if ((reg & 2) == 0)
reg |= 2;
else
reg |= 1;
reg &= ~0x80000000;
iputdword(chip, ICHREG(ALI_SCR), reg);
for (i = 0; i < HZ / 2; i++) {
if (! (igetdword(chip, ICHREG(ALI_INTERRUPTSR)) & ALI_INT_GPIO))
goto __ok;
schedule_timeout_uninterruptible(1);
}
dev_err(chip->card->dev, "AC'97 reset failed.\n");
if (probing)
return -EIO;
__ok:
for (i = 0; i < HZ / 2; i++) {
reg = igetdword(chip, ICHREG(ALI_RTSR));
if (reg & 0x80)
break;
iputdword(chip, ICHREG(ALI_RTSR), reg | 0x80);
schedule_timeout_uninterruptible(1);
}
do_ali_reset(chip);
return 0;
}
static int snd_intel8x0_chip_init(struct intel8x0 *chip, int probing)
{
unsigned int i, timeout;
int err;
if (chip->device_type != DEVICE_ALI) {
if ((err = snd_intel8x0_ich_chip_init(chip, probing)) < 0)
return err;
iagetword(chip, 0);
} else {
if ((err = snd_intel8x0_ali_chip_init(chip, probing)) < 0)
return err;
}
for (i = 0; i < chip->bdbars_count; i++)
iputbyte(chip, ICH_REG_OFF_CR + chip->ichd[i].reg_offset, 0x00);
for (i = 0; i < chip->bdbars_count; i++)
iputbyte(chip, ICH_REG_OFF_CR + chip->ichd[i].reg_offset, ICH_RESETREGS);
for (i = 0; i < chip->bdbars_count; i++) {
timeout = 100000;
while (--timeout != 0) {
if ((igetbyte(chip, ICH_REG_OFF_CR + chip->ichd[i].reg_offset) & ICH_RESETREGS) == 0)
break;
}
if (timeout == 0)
dev_err(chip->card->dev, "reset of registers failed?\n");
}
for (i = 0; i < chip->bdbars_count; i++)
iputdword(chip, ICH_REG_OFF_BDBAR + chip->ichd[i].reg_offset,
chip->ichd[i].bdbar_addr);
return 0;
}
static int snd_intel8x0_free(struct intel8x0 *chip)
{
unsigned int i;
if (chip->irq < 0)
goto __hw_end;
for (i = 0; i < chip->bdbars_count; i++)
iputbyte(chip, ICH_REG_OFF_CR + chip->ichd[i].reg_offset, 0x00);
for (i = 0; i < chip->bdbars_count; i++)
iputbyte(chip, ICH_REG_OFF_CR + chip->ichd[i].reg_offset, ICH_RESETREGS);
if (chip->device_type == DEVICE_NFORCE && !spdif_aclink) {
unsigned int val;
pci_read_config_dword(chip->pci, 0x4c, &val);
val &= ~0x1000000;
pci_write_config_dword(chip->pci, 0x4c, val);
}
__hw_end:
if (chip->irq >= 0)
free_irq(chip->irq, chip);
if (chip->bdbars.area) {
if (chip->fix_nocache)
fill_nocache(chip->bdbars.area, chip->bdbars.bytes, 0);
snd_dma_free_pages(&chip->bdbars);
}
if (chip->addr)
pci_iounmap(chip->pci, chip->addr);
if (chip->bmaddr)
pci_iounmap(chip->pci, chip->bmaddr);
pci_release_regions(chip->pci);
pci_disable_device(chip->pci);
kfree(chip);
return 0;
}
static int intel8x0_suspend(struct device *dev)
{
struct snd_card *card = dev_get_drvdata(dev);
struct intel8x0 *chip = card->private_data;
int i;
snd_power_change_state(card, SNDRV_CTL_POWER_D3hot);
for (i = 0; i < chip->pcm_devs; i++)
snd_pcm_suspend_all(chip->pcm[i]);
if (chip->fix_nocache) {
for (i = 0; i < chip->bdbars_count; i++) {
struct ichdev *ichdev = &chip->ichd[i];
if (ichdev->substream && ichdev->page_attr_changed) {
struct snd_pcm_runtime *runtime = ichdev->substream->runtime;
if (runtime->dma_area)
fill_nocache(runtime->dma_area, runtime->dma_bytes, 0);
}
}
}
for (i = 0; i < chip->ncodecs; i++)
snd_ac97_suspend(chip->ac97[i]);
if (chip->device_type == DEVICE_INTEL_ICH4)
chip->sdm_saved = igetbyte(chip, ICHREG(SDM));
if (chip->irq >= 0) {
free_irq(chip->irq, chip);
chip->irq = -1;
}
return 0;
}
static int intel8x0_resume(struct device *dev)
{
struct pci_dev *pci = to_pci_dev(dev);
struct snd_card *card = dev_get_drvdata(dev);
struct intel8x0 *chip = card->private_data;
int i;
snd_intel8x0_chip_init(chip, 0);
if (request_irq(pci->irq, snd_intel8x0_interrupt,
IRQF_SHARED, KBUILD_MODNAME, chip)) {
dev_err(dev, "unable to grab IRQ %d, disabling device\n",
pci->irq);
snd_card_disconnect(card);
return -EIO;
}
chip->irq = pci->irq;
synchronize_irq(chip->irq);
if (chip->device_type == DEVICE_INTEL_ICH4 && !spdif_aclink) {
iputbyte(chip, ICHREG(SDM), chip->sdm_saved);
iputdword(chip, ICHREG(GLOB_CNT),
(igetdword(chip, ICHREG(GLOB_CNT)) & ~ICH_PCM_SPDIF_MASK) |
ICH_PCM_SPDIF_1011);
}
if (chip->fix_nocache)
fill_nocache(chip->bdbars.area, chip->bdbars.bytes, 1);
for (i = 0; i < chip->ncodecs; i++)
snd_ac97_resume(chip->ac97[i]);
if (chip->fix_nocache) {
for (i = 0; i < chip->bdbars_count; i++) {
struct ichdev *ichdev = &chip->ichd[i];
if (ichdev->substream && ichdev->page_attr_changed) {
struct snd_pcm_runtime *runtime = ichdev->substream->runtime;
if (runtime->dma_area)
fill_nocache(runtime->dma_area, runtime->dma_bytes, 1);
}
}
}
for (i = 0; i < chip->bdbars_count; i++) {
struct ichdev *ichdev = &chip->ichd[i];
unsigned long port = ichdev->reg_offset;
if (! ichdev->substream || ! ichdev->suspended)
continue;
if (ichdev->ichd == ICHD_PCMOUT)
snd_intel8x0_setup_pcm_out(chip, ichdev->substream->runtime);
iputdword(chip, port + ICH_REG_OFF_BDBAR, ichdev->bdbar_addr);
iputbyte(chip, port + ICH_REG_OFF_LVI, ichdev->lvi);
iputbyte(chip, port + ICH_REG_OFF_CIV, ichdev->civ);
iputbyte(chip, port + ichdev->roff_sr, ICH_FIFOE | ICH_BCIS | ICH_LVBCI);
}
snd_power_change_state(card, SNDRV_CTL_POWER_D0);
return 0;
}
static void intel8x0_measure_ac97_clock(struct intel8x0 *chip)
{
struct snd_pcm_substream *subs;
struct ichdev *ichdev;
unsigned long port;
unsigned long pos, pos1, t;
int civ, timeout = 1000, attempt = 1;
ktime_t start_time, stop_time;
if (chip->ac97_bus->clock != 48000)
return;
__again:
subs = chip->pcm[0]->streams[0].substream;
if (! subs || subs->dma_buffer.bytes < INTEL8X0_TESTBUF_SIZE) {
dev_warn(chip->card->dev,
"no playback buffer allocated - aborting measure ac97 clock\n");
return;
}
ichdev = &chip->ichd[ICHD_PCMOUT];
ichdev->physbuf = subs->dma_buffer.addr;
ichdev->size = ichdev->fragsize = INTEL8X0_TESTBUF_SIZE;
ichdev->substream = NULL;
if (snd_ac97_set_rate(chip->ac97[0], AC97_PCM_FRONT_DAC_RATE, 48000) < 0) {
dev_err(chip->card->dev, "cannot set ac97 rate: clock = %d\n",
chip->ac97_bus->clock);
return;
}
snd_intel8x0_setup_periods(chip, ichdev);
port = ichdev->reg_offset;
spin_lock_irq(&chip->reg_lock);
chip->in_measurement = 1;
if (chip->device_type != DEVICE_ALI)
iputbyte(chip, port + ICH_REG_OFF_CR, ICH_IOCE | ICH_STARTBM);
else {
iputbyte(chip, port + ICH_REG_OFF_CR, ICH_IOCE);
iputdword(chip, ICHREG(ALI_DMACR), 1 << ichdev->ali_slot);
}
start_time = ktime_get();
spin_unlock_irq(&chip->reg_lock);
msleep(50);
spin_lock_irq(&chip->reg_lock);
do {
civ = igetbyte(chip, ichdev->reg_offset + ICH_REG_OFF_CIV);
pos1 = igetword(chip, ichdev->reg_offset + ichdev->roff_picb);
if (pos1 == 0) {
udelay(10);
continue;
}
if (civ == igetbyte(chip, ichdev->reg_offset + ICH_REG_OFF_CIV) &&
pos1 == igetword(chip, ichdev->reg_offset + ichdev->roff_picb))
break;
} while (timeout--);
if (pos1 == 0) {
pos = 0;
} else {
pos = ichdev->fragsize1;
pos -= pos1 << ichdev->pos_shift;
pos += ichdev->position;
}
chip->in_measurement = 0;
stop_time = ktime_get();
if (chip->device_type == DEVICE_ALI) {
iputdword(chip, ICHREG(ALI_DMACR), 1 << (ichdev->ali_slot + 16));
iputbyte(chip, port + ICH_REG_OFF_CR, 0);
while (igetbyte(chip, port + ICH_REG_OFF_CR))
;
} else {
iputbyte(chip, port + ICH_REG_OFF_CR, 0);
while (!(igetbyte(chip, port + ichdev->roff_sr) & ICH_DCH))
;
}
iputbyte(chip, port + ICH_REG_OFF_CR, ICH_RESETREGS);
spin_unlock_irq(&chip->reg_lock);
if (pos == 0) {
dev_err(chip->card->dev,
"measure - unreliable DMA position..\n");
__retry:
if (attempt < 3) {
msleep(300);
attempt++;
goto __again;
}
goto __end;
}
pos /= 4;
t = ktime_us_delta(stop_time, start_time);
dev_info(chip->card->dev,
"%s: measured %lu usecs (%lu samples)\n", __func__, t, pos);
if (t == 0) {
dev_err(chip->card->dev, "?? calculation error..\n");
goto __retry;
}
pos *= 1000;
pos = (pos / t) * 1000 + ((pos % t) * 1000) / t;
if (pos < 40000 || pos >= 60000) {
dev_info(chip->card->dev, "measured clock %ld rejected\n", pos);
goto __retry;
} else if (pos > 40500 && pos < 41500)
chip->ac97_bus->clock = 41000;
else if (pos > 43600 && pos < 44600)
chip->ac97_bus->clock = 44100;
else if (pos < 47500 || pos > 48500)
chip->ac97_bus->clock = (chip->ac97_bus->clock * 48000) / pos;
__end:
dev_info(chip->card->dev, "clocking to %d\n", chip->ac97_bus->clock);
snd_ac97_update_power(chip->ac97[0], AC97_PCM_FRONT_DAC_RATE, 0);
}
static int intel8x0_in_clock_list(struct intel8x0 *chip)
{
struct pci_dev *pci = chip->pci;
const struct snd_pci_quirk *wl;
wl = snd_pci_quirk_lookup(pci, intel8x0_clock_list);
if (!wl)
return 0;
dev_info(chip->card->dev, "white list rate for %04x:%04x is %i\n",
pci->subsystem_vendor, pci->subsystem_device, wl->value);
chip->ac97_bus->clock = wl->value;
return 1;
}
static void snd_intel8x0_proc_read(struct snd_info_entry * entry,
struct snd_info_buffer *buffer)
{
struct intel8x0 *chip = entry->private_data;
unsigned int tmp;
snd_iprintf(buffer, "Intel8x0\n\n");
if (chip->device_type == DEVICE_ALI)
return;
tmp = igetdword(chip, ICHREG(GLOB_STA));
snd_iprintf(buffer, "Global control : 0x%08x\n", igetdword(chip, ICHREG(GLOB_CNT)));
snd_iprintf(buffer, "Global status : 0x%08x\n", tmp);
if (chip->device_type == DEVICE_INTEL_ICH4)
snd_iprintf(buffer, "SDM : 0x%08x\n", igetdword(chip, ICHREG(SDM)));
snd_iprintf(buffer, "AC'97 codecs ready :");
if (tmp & chip->codec_isr_bits) {
int i;
static const char *codecs[3] = {
"primary", "secondary", "tertiary"
};
for (i = 0; i < chip->max_codecs; i++)
if (tmp & chip->codec_bit[i])
snd_iprintf(buffer, " %s", codecs[i]);
} else
snd_iprintf(buffer, " none");
snd_iprintf(buffer, "\n");
if (chip->device_type == DEVICE_INTEL_ICH4 ||
chip->device_type == DEVICE_SIS)
snd_iprintf(buffer, "AC'97 codecs SDIN : %i %i %i\n",
chip->ac97_sdin[0],
chip->ac97_sdin[1],
chip->ac97_sdin[2]);
}
static void snd_intel8x0_proc_init(struct intel8x0 *chip)
{
struct snd_info_entry *entry;
if (! snd_card_proc_new(chip->card, "intel8x0", &entry))
snd_info_set_text_ops(entry, chip, snd_intel8x0_proc_read);
}
static int snd_intel8x0_dev_free(struct snd_device *device)
{
struct intel8x0 *chip = device->device_data;
return snd_intel8x0_free(chip);
}
static int snd_intel8x0_inside_vm(struct pci_dev *pci)
{
int result = inside_vm;
char *msg = NULL;
if (result >= 0) {
msg = result ? "enable (forced) VM" : "disable (forced) VM";
goto fini;
}
result = kvm_para_available();
#ifdef X86_FEATURE_HYPERVISOR
result = result || boot_cpu_has(X86_FEATURE_HYPERVISOR);
#endif
if (!result)
goto fini;
if (pci->subsystem_vendor == 0x1af4 &&
pci->subsystem_device == 0x1100) {
msg = "enable KVM";
} else if (pci->subsystem_vendor == 0x1ab8) {
msg = "enable Parallels VM";
} else {
msg = "disable (unknown or VT-d) VM";
result = 0;
}
fini:
if (msg != NULL)
dev_info(&pci->dev, "%s optimization\n", msg);
return result;
}
static int snd_intel8x0_create(struct snd_card *card,
struct pci_dev *pci,
unsigned long device_type,
struct intel8x0 **r_intel8x0)
{
struct intel8x0 *chip;
int err;
unsigned int i;
unsigned int int_sta_masks;
struct ichdev *ichdev;
static struct snd_device_ops ops = {
.dev_free = snd_intel8x0_dev_free,
};
static unsigned int bdbars[] = {
3,
6,
3,
6,
4,
};
static struct ich_reg_info intel_regs[6] = {
{ ICH_PIINT, 0 },
{ ICH_POINT, 0x10 },
{ ICH_MCINT, 0x20 },
{ ICH_M2INT, 0x40 },
{ ICH_P2INT, 0x50 },
{ ICH_SPINT, 0x60 },
};
static struct ich_reg_info nforce_regs[4] = {
{ ICH_PIINT, 0 },
{ ICH_POINT, 0x10 },
{ ICH_MCINT, 0x20 },
{ ICH_NVSPINT, 0x70 },
};
static struct ich_reg_info ali_regs[6] = {
{ ALI_INT_PCMIN, 0x40 },
{ ALI_INT_PCMOUT, 0x50 },
{ ALI_INT_MICIN, 0x60 },
{ ALI_INT_CODECSPDIFOUT, 0x70 },
{ ALI_INT_SPDIFIN, 0xa0 },
{ ALI_INT_SPDIFOUT, 0xb0 },
};
struct ich_reg_info *tbl;
*r_intel8x0 = NULL;
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
chip->buggy_irq = buggy_irq;
chip->buggy_semaphore = buggy_semaphore;
if (xbox)
chip->xbox = 1;
chip->inside_vm = snd_intel8x0_inside_vm(pci);
if (pci->vendor == PCI_VENDOR_ID_INTEL &&
pci->device == PCI_DEVICE_ID_INTEL_440MX)
chip->fix_nocache = 1;
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
dev_err(card->dev, "AC'97 space ioremap problem\n");
snd_intel8x0_free(chip);
return -EIO;
}
if (pci_resource_flags(pci, 3) & IORESOURCE_MEM)
chip->bmaddr = pci_iomap(pci, 3, 0);
else
chip->bmaddr = pci_iomap(pci, 1, 0);
if (!chip->bmaddr) {
dev_err(card->dev, "Controller space ioremap problem\n");
snd_intel8x0_free(chip);
return -EIO;
}
port_inited:
chip->bdbars_count = bdbars[device_type];
switch (device_type) {
case DEVICE_NFORCE:
tbl = nforce_regs;
break;
case DEVICE_ALI:
tbl = ali_regs;
break;
default:
tbl = intel_regs;
break;
}
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
ichdev->pos_shift = (device_type == DEVICE_SIS) ? 0 : 1;
}
if (snd_dma_alloc_pages(SNDRV_DMA_TYPE_DEV, snd_dma_pci_data(pci),
chip->bdbars_count * sizeof(u32) * ICH_MAX_FRAGS * 2,
&chip->bdbars) < 0) {
snd_intel8x0_free(chip);
dev_err(card->dev, "cannot allocate buffer descriptors\n");
return -ENOMEM;
}
if (chip->fix_nocache)
fill_nocache(chip->bdbars.area, chip->bdbars.bytes, 1);
int_sta_masks = 0;
for (i = 0; i < chip->bdbars_count; i++) {
ichdev = &chip->ichd[i];
ichdev->bdbar = ((u32 *)chip->bdbars.area) +
(i * ICH_MAX_FRAGS * 2);
ichdev->bdbar_addr = chip->bdbars.addr +
(i * sizeof(u32) * ICH_MAX_FRAGS * 2);
int_sta_masks |= ichdev->int_sta_mask;
}
chip->int_sta_reg = device_type == DEVICE_ALI ?
ICH_REG_ALI_INTERRUPTSR : ICH_REG_GLOB_STA;
chip->int_sta_mask = int_sta_masks;
pci_set_master(pci);
switch(chip->device_type) {
case DEVICE_INTEL_ICH4:
chip->max_codecs = 3;
chip->codec_bit = ich_codec_bits;
chip->codec_ready_bits = ICH_PRI | ICH_SRI | ICH_TRI;
break;
case DEVICE_SIS:
chip->max_codecs = 3;
chip->codec_bit = sis_codec_bits;
chip->codec_ready_bits = ICH_PRI | ICH_SRI | ICH_SIS_TRI;
break;
default:
chip->max_codecs = 2;
chip->codec_bit = ich_codec_bits;
chip->codec_ready_bits = ICH_PRI | ICH_SRI;
break;
}
for (i = 0; i < chip->max_codecs; i++)
chip->codec_isr_bits |= chip->codec_bit[i];
if ((err = snd_intel8x0_chip_init(chip, 1)) < 0) {
snd_intel8x0_free(chip);
return err;
}
if (request_irq(pci->irq, snd_intel8x0_interrupt,
IRQF_SHARED, KBUILD_MODNAME, chip)) {
dev_err(card->dev, "unable to grab IRQ %d\n", pci->irq);
snd_intel8x0_free(chip);
return -EBUSY;
}
chip->irq = pci->irq;
if ((err = snd_device_new(card, SNDRV_DEV_LOWLEVEL, chip, &ops)) < 0) {
snd_intel8x0_free(chip);
return err;
}
*r_intel8x0 = chip;
return 0;
}
static int check_default_spdif_aclink(struct pci_dev *pci)
{
const struct snd_pci_quirk *w;
w = snd_pci_quirk_lookup(pci, spdif_aclink_defaults);
if (w) {
if (w->value)
dev_dbg(&pci->dev,
"Using SPDIF over AC-Link for %s\n",
snd_pci_quirk_name(w));
else
dev_dbg(&pci->dev,
"Using integrated SPDIF DMA for %s\n",
snd_pci_quirk_name(w));
return w->value;
}
return 0;
}
static int snd_intel8x0_probe(struct pci_dev *pci,
const struct pci_device_id *pci_id)
{
struct snd_card *card;
struct intel8x0 *chip;
int err;
struct shortname_table *name;
err = snd_card_new(&pci->dev, index, id, THIS_MODULE, 0, &card);
if (err < 0)
return err;
if (spdif_aclink < 0)
spdif_aclink = check_default_spdif_aclink(pci);
strcpy(card->driver, "ICH");
if (!spdif_aclink) {
switch (pci_id->driver_data) {
case DEVICE_NFORCE:
strcpy(card->driver, "NFORCE");
break;
case DEVICE_INTEL_ICH4:
strcpy(card->driver, "ICH4");
}
}
strcpy(card->shortname, "Intel ICH");
for (name = shortnames; name->id; name++) {
if (pci->device == name->id) {
strcpy(card->shortname, name->s);
break;
}
}
if (buggy_irq < 0) {
if (pci_id->driver_data == DEVICE_NFORCE)
buggy_irq = 1;
else
buggy_irq = 0;
}
if ((err = snd_intel8x0_create(card, pci, pci_id->driver_data,
&chip)) < 0) {
snd_card_free(card);
return err;
}
card->private_data = chip;
if ((err = snd_intel8x0_mixer(chip, ac97_clock, ac97_quirk)) < 0) {
snd_card_free(card);
return err;
}
if ((err = snd_intel8x0_pcm(chip)) < 0) {
snd_card_free(card);
return err;
}
snd_intel8x0_proc_init(chip);
snprintf(card->longname, sizeof(card->longname),
"%s with %s at irq %i", card->shortname,
snd_ac97_get_short_name(chip->ac97[0]), chip->irq);
if (ac97_clock == 0 || ac97_clock == 1) {
if (ac97_clock == 0) {
if (intel8x0_in_clock_list(chip) == 0)
intel8x0_measure_ac97_clock(chip);
} else {
intel8x0_measure_ac97_clock(chip);
}
}
if ((err = snd_card_register(card)) < 0) {
snd_card_free(card);
return err;
}
pci_set_drvdata(pci, card);
return 0;
}
static void snd_intel8x0_remove(struct pci_dev *pci)
{
snd_card_free(pci_get_drvdata(pci));
}
