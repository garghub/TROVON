static inline u32 hal2_read(u32 *reg)
{
return __raw_readl(reg);
}
static inline void hal2_write(u32 val, u32 *reg)
{
__raw_writel(val, reg);
}
static u32 hal2_i_read32(struct snd_hal2 *hal2, u16 addr)
{
u32 ret;
struct hal2_ctl_regs *regs = hal2->ctl_regs;
hal2_write(H2_READ_ADDR(addr), &regs->iar);
H2_INDIRECT_WAIT(regs);
ret = hal2_read(&regs->idr0) & 0xffff;
hal2_write(H2_READ_ADDR(addr) | 0x1, &regs->iar);
H2_INDIRECT_WAIT(regs);
ret |= (hal2_read(&regs->idr0) & 0xffff) << 16;
return ret;
}
static void hal2_i_write16(struct snd_hal2 *hal2, u16 addr, u16 val)
{
struct hal2_ctl_regs *regs = hal2->ctl_regs;
hal2_write(val, &regs->idr0);
hal2_write(0, &regs->idr1);
hal2_write(0, &regs->idr2);
hal2_write(0, &regs->idr3);
hal2_write(H2_WRITE_ADDR(addr), &regs->iar);
H2_INDIRECT_WAIT(regs);
}
static void hal2_i_write32(struct snd_hal2 *hal2, u16 addr, u32 val)
{
struct hal2_ctl_regs *regs = hal2->ctl_regs;
hal2_write(val & 0xffff, &regs->idr0);
hal2_write(val >> 16, &regs->idr1);
hal2_write(0, &regs->idr2);
hal2_write(0, &regs->idr3);
hal2_write(H2_WRITE_ADDR(addr), &regs->iar);
H2_INDIRECT_WAIT(regs);
}
static void hal2_i_setbit16(struct snd_hal2 *hal2, u16 addr, u16 bit)
{
struct hal2_ctl_regs *regs = hal2->ctl_regs;
hal2_write(H2_READ_ADDR(addr), &regs->iar);
H2_INDIRECT_WAIT(regs);
hal2_write((hal2_read(&regs->idr0) & 0xffff) | bit, &regs->idr0);
hal2_write(0, &regs->idr1);
hal2_write(0, &regs->idr2);
hal2_write(0, &regs->idr3);
hal2_write(H2_WRITE_ADDR(addr), &regs->iar);
H2_INDIRECT_WAIT(regs);
}
static void hal2_i_clearbit16(struct snd_hal2 *hal2, u16 addr, u16 bit)
{
struct hal2_ctl_regs *regs = hal2->ctl_regs;
hal2_write(H2_READ_ADDR(addr), &regs->iar);
H2_INDIRECT_WAIT(regs);
hal2_write((hal2_read(&regs->idr0) & 0xffff) & ~bit, &regs->idr0);
hal2_write(0, &regs->idr1);
hal2_write(0, &regs->idr2);
hal2_write(0, &regs->idr3);
hal2_write(H2_WRITE_ADDR(addr), &regs->iar);
H2_INDIRECT_WAIT(regs);
}
static int hal2_gain_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 2;
uinfo->value.integer.min = 0;
switch ((int)kcontrol->private_value) {
case H2_MIX_OUTPUT_ATT:
uinfo->value.integer.max = 31;
break;
case H2_MIX_INPUT_GAIN:
uinfo->value.integer.max = 15;
break;
}
return 0;
}
static int hal2_gain_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_hal2 *hal2 = snd_kcontrol_chip(kcontrol);
u32 tmp;
int l, r;
switch ((int)kcontrol->private_value) {
case H2_MIX_OUTPUT_ATT:
tmp = hal2_i_read32(hal2, H2I_DAC_C2);
if (tmp & H2I_C2_MUTE) {
l = 0;
r = 0;
} else {
l = 31 - ((tmp >> H2I_C2_L_ATT_SHIFT) & 31);
r = 31 - ((tmp >> H2I_C2_R_ATT_SHIFT) & 31);
}
break;
case H2_MIX_INPUT_GAIN:
tmp = hal2_i_read32(hal2, H2I_ADC_C2);
l = (tmp >> H2I_C2_L_GAIN_SHIFT) & 15;
r = (tmp >> H2I_C2_R_GAIN_SHIFT) & 15;
break;
}
ucontrol->value.integer.value[0] = l;
ucontrol->value.integer.value[1] = r;
return 0;
}
static int hal2_gain_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_hal2 *hal2 = snd_kcontrol_chip(kcontrol);
u32 old, new;
int l, r;
l = ucontrol->value.integer.value[0];
r = ucontrol->value.integer.value[1];
switch ((int)kcontrol->private_value) {
case H2_MIX_OUTPUT_ATT:
old = hal2_i_read32(hal2, H2I_DAC_C2);
new = old & ~(H2I_C2_L_ATT_M | H2I_C2_R_ATT_M | H2I_C2_MUTE);
if (l | r) {
l = 31 - l;
r = 31 - r;
new |= (l << H2I_C2_L_ATT_SHIFT);
new |= (r << H2I_C2_R_ATT_SHIFT);
} else
new |= H2I_C2_L_ATT_M | H2I_C2_R_ATT_M | H2I_C2_MUTE;
hal2_i_write32(hal2, H2I_DAC_C2, new);
break;
case H2_MIX_INPUT_GAIN:
old = hal2_i_read32(hal2, H2I_ADC_C2);
new = old & ~(H2I_C2_L_GAIN_M | H2I_C2_R_GAIN_M);
new |= (l << H2I_C2_L_GAIN_SHIFT);
new |= (r << H2I_C2_R_GAIN_SHIFT);
hal2_i_write32(hal2, H2I_ADC_C2, new);
break;
}
return old != new;
}
static int hal2_mixer_create(struct snd_hal2 *hal2)
{
int err;
hal2_i_write32(hal2, H2I_DAC_C2,
H2I_C2_L_ATT_M | H2I_C2_R_ATT_M | H2I_C2_MUTE);
hal2_i_write32(hal2, H2I_ADC_C2, 0);
err = snd_ctl_add(hal2->card,
snd_ctl_new1(&hal2_ctrl_headphone, hal2));
if (err < 0)
return err;
err = snd_ctl_add(hal2->card,
snd_ctl_new1(&hal2_ctrl_mic, hal2));
if (err < 0)
return err;
return 0;
}
static irqreturn_t hal2_interrupt(int irq, void *dev_id)
{
struct snd_hal2 *hal2 = dev_id;
irqreturn_t ret = IRQ_NONE;
if (hal2->dac.pbus.pbus->pbdma_ctrl & HPC3_PDMACTRL_INT) {
snd_pcm_period_elapsed(hal2->dac.substream);
ret = IRQ_HANDLED;
}
if (hal2->adc.pbus.pbus->pbdma_ctrl & HPC3_PDMACTRL_INT) {
snd_pcm_period_elapsed(hal2->adc.substream);
ret = IRQ_HANDLED;
}
return ret;
}
static int hal2_compute_rate(struct hal2_codec *codec, unsigned int rate)
{
unsigned short mod;
if (44100 % rate < 48000 % rate) {
mod = 4 * 44100 / rate;
codec->master = 44100;
} else {
mod = 4 * 48000 / rate;
codec->master = 48000;
}
codec->inc = 4;
codec->mod = mod;
rate = 4 * codec->master / mod;
return rate;
}
static void hal2_set_dac_rate(struct snd_hal2 *hal2)
{
unsigned int master = hal2->dac.master;
int inc = hal2->dac.inc;
int mod = hal2->dac.mod;
hal2_i_write16(hal2, H2I_BRES1_C1, (master == 44100) ? 1 : 0);
hal2_i_write32(hal2, H2I_BRES1_C2,
((0xffff & (inc - mod - 1)) << 16) | inc);
}
static void hal2_set_adc_rate(struct snd_hal2 *hal2)
{
unsigned int master = hal2->adc.master;
int inc = hal2->adc.inc;
int mod = hal2->adc.mod;
hal2_i_write16(hal2, H2I_BRES2_C1, (master == 44100) ? 1 : 0);
hal2_i_write32(hal2, H2I_BRES2_C2,
((0xffff & (inc - mod - 1)) << 16) | inc);
}
static void hal2_setup_dac(struct snd_hal2 *hal2)
{
unsigned int fifobeg, fifoend, highwater, sample_size;
struct hal2_pbus *pbus = &hal2->dac.pbus;
sample_size = 2 * hal2->dac.voices;
highwater = (sample_size * 2) >> 1;
fifobeg = 0;
fifoend = (sample_size * 4) >> 3;
pbus->ctrl = HPC3_PDMACTRL_RT | HPC3_PDMACTRL_LD |
(highwater << 8) | (fifobeg << 16) | (fifoend << 24);
pbus->pbus->pbdma_ctrl = HPC3_PDMACTRL_LD;
hal2_i_clearbit16(hal2, H2I_DMA_PORT_EN, H2I_DMA_PORT_EN_CODECTX);
hal2_set_dac_rate(hal2);
hal2_i_clearbit16(hal2, H2I_DMA_END, H2I_DMA_END_CODECTX);
hal2_i_setbit16(hal2, H2I_DMA_DRV, (1 << pbus->pbusnr));
hal2_i_write16(hal2, H2I_DAC_C1, (pbus->pbusnr << H2I_C1_DMA_SHIFT)
| (1 << H2I_C1_CLKID_SHIFT)
| (hal2->dac.voices << H2I_C1_DATAT_SHIFT));
}
static void hal2_setup_adc(struct snd_hal2 *hal2)
{
unsigned int fifobeg, fifoend, highwater, sample_size;
struct hal2_pbus *pbus = &hal2->adc.pbus;
sample_size = 2 * hal2->adc.voices;
highwater = (sample_size * 2) >> 1;
fifobeg = (4 * 4) >> 3;
fifoend = (4 * 4 + sample_size * 4) >> 3;
pbus->ctrl = HPC3_PDMACTRL_RT | HPC3_PDMACTRL_RCV | HPC3_PDMACTRL_LD |
(highwater << 8) | (fifobeg << 16) | (fifoend << 24);
pbus->pbus->pbdma_ctrl = HPC3_PDMACTRL_LD;
hal2_i_clearbit16(hal2, H2I_DMA_PORT_EN, H2I_DMA_PORT_EN_CODECR);
hal2_set_adc_rate(hal2);
hal2_i_clearbit16(hal2, H2I_DMA_END, H2I_DMA_END_CODECR);
hal2_i_setbit16(hal2, H2I_DMA_DRV, (1 << pbus->pbusnr));
hal2_i_write16(hal2, H2I_ADC_C1, (pbus->pbusnr << H2I_C1_DMA_SHIFT)
| (2 << H2I_C1_CLKID_SHIFT)
| (hal2->adc.voices << H2I_C1_DATAT_SHIFT));
}
static void hal2_start_dac(struct snd_hal2 *hal2)
{
struct hal2_pbus *pbus = &hal2->dac.pbus;
pbus->pbus->pbdma_dptr = hal2->dac.desc_dma;
pbus->pbus->pbdma_ctrl = pbus->ctrl | HPC3_PDMACTRL_ACT;
hal2_i_setbit16(hal2, H2I_DMA_PORT_EN, H2I_DMA_PORT_EN_CODECTX);
}
static void hal2_start_adc(struct snd_hal2 *hal2)
{
struct hal2_pbus *pbus = &hal2->adc.pbus;
pbus->pbus->pbdma_dptr = hal2->adc.desc_dma;
pbus->pbus->pbdma_ctrl = pbus->ctrl | HPC3_PDMACTRL_ACT;
hal2_i_setbit16(hal2, H2I_DMA_PORT_EN, H2I_DMA_PORT_EN_CODECR);
}
static inline void hal2_stop_dac(struct snd_hal2 *hal2)
{
hal2->dac.pbus.pbus->pbdma_ctrl = HPC3_PDMACTRL_LD;
}
static inline void hal2_stop_adc(struct snd_hal2 *hal2)
{
hal2->adc.pbus.pbus->pbdma_ctrl = HPC3_PDMACTRL_LD;
}
static int hal2_alloc_dmabuf(struct hal2_codec *codec)
{
struct hal2_desc *desc;
dma_addr_t desc_dma, buffer_dma;
int count = H2_BUF_SIZE / H2_BLOCK_SIZE;
int i;
codec->buffer = dma_alloc_noncoherent(NULL, H2_BUF_SIZE,
&buffer_dma, GFP_KERNEL);
if (!codec->buffer)
return -ENOMEM;
desc = dma_alloc_noncoherent(NULL, count * sizeof(struct hal2_desc),
&desc_dma, GFP_KERNEL);
if (!desc) {
dma_free_noncoherent(NULL, H2_BUF_SIZE,
codec->buffer, buffer_dma);
return -ENOMEM;
}
codec->buffer_dma = buffer_dma;
codec->desc_dma = desc_dma;
codec->desc = desc;
for (i = 0; i < count; i++) {
desc->desc.pbuf = buffer_dma + i * H2_BLOCK_SIZE;
desc->desc.cntinfo = HPCDMA_XIE | H2_BLOCK_SIZE;
desc->desc.pnext = (i == count - 1) ?
desc_dma : desc_dma + (i + 1) * sizeof(struct hal2_desc);
desc++;
}
dma_cache_sync(NULL, codec->desc, count * sizeof(struct hal2_desc),
DMA_TO_DEVICE);
codec->desc_count = count;
return 0;
}
static void hal2_free_dmabuf(struct hal2_codec *codec)
{
dma_free_noncoherent(NULL, codec->desc_count * sizeof(struct hal2_desc),
codec->desc, codec->desc_dma);
dma_free_noncoherent(NULL, H2_BUF_SIZE, codec->buffer,
codec->buffer_dma);
}
static int hal2_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
int err;
err = snd_pcm_lib_malloc_pages(substream, params_buffer_bytes(params));
if (err < 0)
return err;
return 0;
}
static int hal2_pcm_hw_free(struct snd_pcm_substream *substream)
{
return snd_pcm_lib_free_pages(substream);
}
static int hal2_playback_open(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_hal2 *hal2 = snd_pcm_substream_chip(substream);
int err;
runtime->hw = hal2_pcm_hw;
err = hal2_alloc_dmabuf(&hal2->dac);
if (err)
return err;
return 0;
}
static int hal2_playback_close(struct snd_pcm_substream *substream)
{
struct snd_hal2 *hal2 = snd_pcm_substream_chip(substream);
hal2_free_dmabuf(&hal2->dac);
return 0;
}
static int hal2_playback_prepare(struct snd_pcm_substream *substream)
{
struct snd_hal2 *hal2 = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct hal2_codec *dac = &hal2->dac;
dac->voices = runtime->channels;
dac->sample_rate = hal2_compute_rate(dac, runtime->rate);
memset(&dac->pcm_indirect, 0, sizeof(dac->pcm_indirect));
dac->pcm_indirect.hw_buffer_size = H2_BUF_SIZE;
dac->pcm_indirect.sw_buffer_size = snd_pcm_lib_buffer_bytes(substream);
dac->substream = substream;
hal2_setup_dac(hal2);
return 0;
}
static int hal2_playback_trigger(struct snd_pcm_substream *substream, int cmd)
{
struct snd_hal2 *hal2 = snd_pcm_substream_chip(substream);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
hal2->dac.pcm_indirect.hw_io = hal2->dac.buffer_dma;
hal2->dac.pcm_indirect.hw_data = 0;
substream->ops->ack(substream);
hal2_start_dac(hal2);
break;
case SNDRV_PCM_TRIGGER_STOP:
hal2_stop_dac(hal2);
break;
default:
return -EINVAL;
}
return 0;
}
static snd_pcm_uframes_t
hal2_playback_pointer(struct snd_pcm_substream *substream)
{
struct snd_hal2 *hal2 = snd_pcm_substream_chip(substream);
struct hal2_codec *dac = &hal2->dac;
return snd_pcm_indirect_playback_pointer(substream, &dac->pcm_indirect,
dac->pbus.pbus->pbdma_bptr);
}
static void hal2_playback_transfer(struct snd_pcm_substream *substream,
struct snd_pcm_indirect *rec, size_t bytes)
{
struct snd_hal2 *hal2 = snd_pcm_substream_chip(substream);
unsigned char *buf = hal2->dac.buffer + rec->hw_data;
memcpy(buf, substream->runtime->dma_area + rec->sw_data, bytes);
dma_cache_sync(NULL, buf, bytes, DMA_TO_DEVICE);
}
static int hal2_playback_ack(struct snd_pcm_substream *substream)
{
struct snd_hal2 *hal2 = snd_pcm_substream_chip(substream);
struct hal2_codec *dac = &hal2->dac;
dac->pcm_indirect.hw_queue_size = H2_BUF_SIZE / 2;
snd_pcm_indirect_playback_transfer(substream,
&dac->pcm_indirect,
hal2_playback_transfer);
return 0;
}
static int hal2_capture_open(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_hal2 *hal2 = snd_pcm_substream_chip(substream);
struct hal2_codec *adc = &hal2->adc;
int err;
runtime->hw = hal2_pcm_hw;
err = hal2_alloc_dmabuf(adc);
if (err)
return err;
return 0;
}
static int hal2_capture_close(struct snd_pcm_substream *substream)
{
struct snd_hal2 *hal2 = snd_pcm_substream_chip(substream);
hal2_free_dmabuf(&hal2->adc);
return 0;
}
static int hal2_capture_prepare(struct snd_pcm_substream *substream)
{
struct snd_hal2 *hal2 = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
struct hal2_codec *adc = &hal2->adc;
adc->voices = runtime->channels;
adc->sample_rate = hal2_compute_rate(adc, runtime->rate);
memset(&adc->pcm_indirect, 0, sizeof(adc->pcm_indirect));
adc->pcm_indirect.hw_buffer_size = H2_BUF_SIZE;
adc->pcm_indirect.hw_queue_size = H2_BUF_SIZE / 2;
adc->pcm_indirect.sw_buffer_size = snd_pcm_lib_buffer_bytes(substream);
adc->substream = substream;
hal2_setup_adc(hal2);
return 0;
}
static int hal2_capture_trigger(struct snd_pcm_substream *substream, int cmd)
{
struct snd_hal2 *hal2 = snd_pcm_substream_chip(substream);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
hal2->adc.pcm_indirect.hw_io = hal2->adc.buffer_dma;
hal2->adc.pcm_indirect.hw_data = 0;
printk(KERN_DEBUG "buffer_dma %x\n", hal2->adc.buffer_dma);
hal2_start_adc(hal2);
break;
case SNDRV_PCM_TRIGGER_STOP:
hal2_stop_adc(hal2);
break;
default:
return -EINVAL;
}
return 0;
}
static snd_pcm_uframes_t
hal2_capture_pointer(struct snd_pcm_substream *substream)
{
struct snd_hal2 *hal2 = snd_pcm_substream_chip(substream);
struct hal2_codec *adc = &hal2->adc;
return snd_pcm_indirect_capture_pointer(substream, &adc->pcm_indirect,
adc->pbus.pbus->pbdma_bptr);
}
static void hal2_capture_transfer(struct snd_pcm_substream *substream,
struct snd_pcm_indirect *rec, size_t bytes)
{
struct snd_hal2 *hal2 = snd_pcm_substream_chip(substream);
unsigned char *buf = hal2->adc.buffer + rec->hw_data;
dma_cache_sync(NULL, buf, bytes, DMA_FROM_DEVICE);
memcpy(substream->runtime->dma_area + rec->sw_data, buf, bytes);
}
static int hal2_capture_ack(struct snd_pcm_substream *substream)
{
struct snd_hal2 *hal2 = snd_pcm_substream_chip(substream);
struct hal2_codec *adc = &hal2->adc;
snd_pcm_indirect_capture_transfer(substream,
&adc->pcm_indirect,
hal2_capture_transfer);
return 0;
}
static int hal2_pcm_create(struct snd_hal2 *hal2)
{
struct snd_pcm *pcm;
int err;
err = snd_pcm_new(hal2->card, "SGI HAL2 Audio", 0, 1, 1, &pcm);
if (err < 0)
return err;
pcm->private_data = hal2;
strcpy(pcm->name, "SGI HAL2");
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK,
&hal2_playback_ops);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE,
&hal2_capture_ops);
snd_pcm_lib_preallocate_pages_for_all(pcm, SNDRV_DMA_TYPE_CONTINUOUS,
snd_dma_continuous_data(GFP_KERNEL),
0, 1024 * 1024);
return 0;
}
static int hal2_dev_free(struct snd_device *device)
{
struct snd_hal2 *hal2 = device->device_data;
free_irq(SGI_HPCDMA_IRQ, hal2);
kfree(hal2);
return 0;
}
static void hal2_init_codec(struct hal2_codec *codec, struct hpc3_regs *hpc3,
int index)
{
codec->pbus.pbusnr = index;
codec->pbus.pbus = &hpc3->pbdma[index];
}
static int hal2_detect(struct snd_hal2 *hal2)
{
unsigned short board, major, minor;
unsigned short rev;
hal2_write(0, &hal2->ctl_regs->isr);
hal2_write(H2_ISR_GLOBAL_RESET_N | H2_ISR_CODEC_RESET_N,
&hal2->ctl_regs->isr);
hal2_i_write16(hal2, H2I_RELAY_C, H2I_RELAY_C_STATE);
rev = hal2_read(&hal2->ctl_regs->rev);
if (rev & H2_REV_AUDIO_PRESENT)
return -ENODEV;
board = (rev & H2_REV_BOARD_M) >> 12;
major = (rev & H2_REV_MAJOR_CHIP_M) >> 4;
minor = (rev & H2_REV_MINOR_CHIP_M);
printk(KERN_INFO "SGI HAL2 revision %i.%i.%i\n",
board, major, minor);
return 0;
}
static int hal2_create(struct snd_card *card, struct snd_hal2 **rchip)
{
struct snd_hal2 *hal2;
struct hpc3_regs *hpc3 = hpc3c0;
int err;
hal2 = kzalloc(sizeof(struct snd_hal2), GFP_KERNEL);
if (!hal2)
return -ENOMEM;
hal2->card = card;
if (request_irq(SGI_HPCDMA_IRQ, hal2_interrupt, IRQF_SHARED,
"SGI HAL2", hal2)) {
printk(KERN_ERR "HAL2: Can't get irq %d\n", SGI_HPCDMA_IRQ);
kfree(hal2);
return -EAGAIN;
}
hal2->ctl_regs = (struct hal2_ctl_regs *)hpc3->pbus_extregs[0];
hal2->aes_regs = (struct hal2_aes_regs *)hpc3->pbus_extregs[1];
hal2->vol_regs = (struct hal2_vol_regs *)hpc3->pbus_extregs[2];
hal2->syn_regs = (struct hal2_syn_regs *)hpc3->pbus_extregs[3];
if (hal2_detect(hal2) < 0) {
kfree(hal2);
return -ENODEV;
}
hal2_init_codec(&hal2->dac, hpc3, 0);
hal2_init_codec(&hal2->adc, hpc3, 1);
#define HAL2_PBUS_DMACFG ((0 << HPC3_DMACFG_D3R_SHIFT) | \
(2 << HPC3_DMACFG_D4R_SHIFT) | \
(2 << HPC3_DMACFG_D5R_SHIFT) | \
(0 << HPC3_DMACFG_D3W_SHIFT) | \
(2 << HPC3_DMACFG_D4W_SHIFT) | \
(2 << HPC3_DMACFG_D5W_SHIFT) | \
HPC3_DMACFG_DS16 | \
HPC3_DMACFG_EVENHI | \
HPC3_DMACFG_RTIME | \
(8 << HPC3_DMACFG_BURST_SHIFT) | \
HPC3_DMACFG_DRQLIVE)
hpc3->pbus_dmacfg[hal2->dac.pbus.pbusnr][0] = 0x8208844;
hpc3->pbus_dmacfg[hal2->adc.pbus.pbusnr][0] = 0x8208844;
err = snd_device_new(card, SNDRV_DEV_LOWLEVEL, hal2, &hal2_ops);
if (err < 0) {
free_irq(SGI_HPCDMA_IRQ, hal2);
kfree(hal2);
return err;
}
*rchip = hal2;
return 0;
}
static int hal2_probe(struct platform_device *pdev)
{
struct snd_card *card;
struct snd_hal2 *chip;
int err;
err = snd_card_create(index, id, THIS_MODULE, 0, &card);
if (err < 0)
return err;
err = hal2_create(card, &chip);
if (err < 0) {
snd_card_free(card);
return err;
}
snd_card_set_dev(card, &pdev->dev);
err = hal2_pcm_create(chip);
if (err < 0) {
snd_card_free(card);
return err;
}
err = hal2_mixer_create(chip);
if (err < 0) {
snd_card_free(card);
return err;
}
strcpy(card->driver, "SGI HAL2 Audio");
strcpy(card->shortname, "SGI HAL2 Audio");
sprintf(card->longname, "%s irq %i",
card->shortname,
SGI_HPCDMA_IRQ);
err = snd_card_register(card);
if (err < 0) {
snd_card_free(card);
return err;
}
platform_set_drvdata(pdev, card);
return 0;
}
static int hal2_remove(struct platform_device *pdev)
{
struct snd_card *card = platform_get_drvdata(pdev);
snd_card_free(card);
platform_set_drvdata(pdev, NULL);
return 0;
}
