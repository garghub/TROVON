static int cx23885_start_audio_dma(struct cx23885_audio_dev *chip)
{
struct cx23885_audio_buffer *buf = chip->buf;
struct cx23885_dev *dev = chip->dev;
struct sram_channel *audio_ch =
&dev->sram_channels[AUDIO_SRAM_CHANNEL];
dprintk(1, "%s()\n", __func__);
cx_clear(AUD_INT_DMA_CTL, 0x11);
cx23885_sram_channel_setup(chip->dev, audio_ch, buf->bpl,
buf->risc.dma);
cx_write(AUD_INT_A_LNGTH, buf->bpl);
cx_write(AUD_INT_A_MODE, 1);
cx_write(AUD_INT_A_GPCNT_CTL, GP_COUNT_CONTROL_RESET);
atomic_set(&chip->count, 0);
dprintk(1, "Start audio DMA, %d B/line, %d lines/FIFO, %d periods, %d "
"byte buffer\n", buf->bpl, cx_read(audio_ch->cmds_start+12)>>1,
chip->num_periods, buf->bpl * chip->num_periods);
cx_write(AUDIO_INT_INT_MSK, AUD_INT_OPC_ERR | AUD_INT_DN_SYNC |
AUD_INT_DN_RISCI1);
cx_write(AUDIO_INT_INT_STAT, ~0);
cx_set(PCI_INT_MSK, chip->dev->pci_irqmask | PCI_MSK_AUD_INT);
cx_set(DEV_CNTRL2, (1<<5));
cx_set(AUD_INT_DMA_CTL, 0x11);
if (audio_debug)
cx23885_sram_channel_dump(chip->dev, audio_ch);
return 0;
}
static int cx23885_stop_audio_dma(struct cx23885_audio_dev *chip)
{
struct cx23885_dev *dev = chip->dev;
dprintk(1, "Stopping audio DMA\n");
cx_clear(AUD_INT_DMA_CTL, 0x11);
cx_clear(PCI_INT_MSK, PCI_MSK_AUD_INT);
cx_clear(AUDIO_INT_INT_MSK, AUD_INT_OPC_ERR | AUD_INT_DN_SYNC |
AUD_INT_DN_RISCI1);
if (audio_debug)
cx23885_sram_channel_dump(chip->dev,
&dev->sram_channels[AUDIO_SRAM_CHANNEL]);
return 0;
}
int cx23885_audio_irq(struct cx23885_dev *dev, u32 status, u32 mask)
{
struct cx23885_audio_dev *chip = dev->audio_dev;
if (0 == (status & mask))
return 0;
cx_write(AUDIO_INT_INT_STAT, status);
if (status & AUD_INT_OPC_ERR) {
printk(KERN_WARNING "%s/1: Audio risc op code error\n",
dev->name);
cx_clear(AUD_INT_DMA_CTL, 0x11);
cx23885_sram_channel_dump(dev,
&dev->sram_channels[AUDIO_SRAM_CHANNEL]);
}
if (status & AUD_INT_DN_SYNC) {
dprintk(1, "Downstream sync error\n");
cx_write(AUD_INT_A_GPCNT_CTL, GP_COUNT_CONTROL_RESET);
return 1;
}
if (status & AUD_INT_DN_RISCI1) {
atomic_set(&chip->count, cx_read(AUD_INT_A_GPCNT));
snd_pcm_period_elapsed(chip->substream);
}
return 1;
}
static int dsp_buffer_free(struct cx23885_audio_dev *chip)
{
BUG_ON(!chip->dma_size);
dprintk(2, "Freeing buffer\n");
videobuf_dma_unmap(&chip->pci->dev, chip->dma_risc);
videobuf_dma_free(chip->dma_risc);
btcx_riscmem_free(chip->pci, &chip->buf->risc);
kfree(chip->buf);
chip->dma_risc = NULL;
chip->dma_size = 0;
return 0;
}
static int snd_cx23885_pcm_open(struct snd_pcm_substream *substream)
{
struct cx23885_audio_dev *chip = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
int err;
if (!chip) {
printk(KERN_ERR "BUG: cx23885 can't find device struct."
" Can't proceed with open\n");
return -ENODEV;
}
err = snd_pcm_hw_constraint_pow2(runtime, 0,
SNDRV_PCM_HW_PARAM_PERIODS);
if (err < 0)
goto _error;
chip->substream = substream;
runtime->hw = snd_cx23885_digital_hw;
if (chip->dev->sram_channels[AUDIO_SRAM_CHANNEL].fifo_size !=
DEFAULT_FIFO_SIZE) {
unsigned int bpl = chip->dev->
sram_channels[AUDIO_SRAM_CHANNEL].fifo_size / 4;
bpl &= ~7;
runtime->hw.period_bytes_min = bpl;
runtime->hw.period_bytes_max = bpl;
}
return 0;
_error:
dprintk(1, "Error opening PCM!\n");
return err;
}
static int snd_cx23885_close(struct snd_pcm_substream *substream)
{
return 0;
}
static int snd_cx23885_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
struct cx23885_audio_dev *chip = snd_pcm_substream_chip(substream);
struct videobuf_dmabuf *dma;
struct cx23885_audio_buffer *buf;
int ret;
if (substream->runtime->dma_area) {
dsp_buffer_free(chip);
substream->runtime->dma_area = NULL;
}
chip->period_size = params_period_bytes(hw_params);
chip->num_periods = params_periods(hw_params);
chip->dma_size = chip->period_size * params_periods(hw_params);
BUG_ON(!chip->dma_size);
BUG_ON(chip->num_periods & (chip->num_periods-1));
buf = kzalloc(sizeof(*buf), GFP_KERNEL);
if (NULL == buf)
return -ENOMEM;
buf->bpl = chip->period_size;
dma = &buf->dma;
videobuf_dma_init(dma);
ret = videobuf_dma_init_kernel(dma, PCI_DMA_FROMDEVICE,
(PAGE_ALIGN(chip->dma_size) >> PAGE_SHIFT));
if (ret < 0)
goto error;
ret = videobuf_dma_map(&chip->pci->dev, dma);
if (ret < 0)
goto error;
ret = cx23885_risc_databuffer(chip->pci, &buf->risc, dma->sglist,
chip->period_size, chip->num_periods, 1);
if (ret < 0)
goto error;
buf->risc.jmp[0] = cpu_to_le32(RISC_JUMP|RISC_IRQ1|RISC_CNT_INC);
buf->risc.jmp[1] = cpu_to_le32(buf->risc.dma);
buf->risc.jmp[2] = cpu_to_le32(0);
chip->buf = buf;
chip->dma_risc = dma;
substream->runtime->dma_area = chip->dma_risc->vaddr;
substream->runtime->dma_bytes = chip->dma_size;
substream->runtime->dma_addr = 0;
return 0;
error:
kfree(buf);
return ret;
}
static int snd_cx23885_hw_free(struct snd_pcm_substream *substream)
{
struct cx23885_audio_dev *chip = snd_pcm_substream_chip(substream);
if (substream->runtime->dma_area) {
dsp_buffer_free(chip);
substream->runtime->dma_area = NULL;
}
return 0;
}
static int snd_cx23885_prepare(struct snd_pcm_substream *substream)
{
return 0;
}
static int snd_cx23885_card_trigger(struct snd_pcm_substream *substream,
int cmd)
{
struct cx23885_audio_dev *chip = snd_pcm_substream_chip(substream);
int err;
spin_lock(&chip->lock);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
err = cx23885_start_audio_dma(chip);
break;
case SNDRV_PCM_TRIGGER_STOP:
err = cx23885_stop_audio_dma(chip);
break;
default:
err = -EINVAL;
break;
}
spin_unlock(&chip->lock);
return err;
}
static snd_pcm_uframes_t snd_cx23885_pointer(
struct snd_pcm_substream *substream)
{
struct cx23885_audio_dev *chip = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
u16 count;
count = atomic_read(&chip->count);
return runtime->period_size * (count & (runtime->periods-1));
}
static struct page *snd_cx23885_page(struct snd_pcm_substream *substream,
unsigned long offset)
{
void *pageptr = substream->runtime->dma_area + offset;
return vmalloc_to_page(pageptr);
}
static int snd_cx23885_pcm(struct cx23885_audio_dev *chip, int device,
char *name)
{
int err;
struct snd_pcm *pcm;
err = snd_pcm_new(chip->card, name, device, 0, 1, &pcm);
if (err < 0)
return err;
pcm->private_data = chip;
strcpy(pcm->name, name);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE, &snd_cx23885_pcm_ops);
return 0;
}
struct cx23885_audio_dev *cx23885_audio_register(struct cx23885_dev *dev)
{
struct snd_card *card;
struct cx23885_audio_dev *chip;
int err;
if (disable_analog_audio)
return NULL;
if (dev->sram_channels[AUDIO_SRAM_CHANNEL].cmds_start == 0) {
printk(KERN_WARNING "%s(): Missing SRAM channel configuration "
"for analog TV Audio\n", __func__);
return NULL;
}
err = snd_card_new(&dev->pci->dev,
SNDRV_DEFAULT_IDX1, SNDRV_DEFAULT_STR1,
THIS_MODULE, sizeof(struct cx23885_audio_dev), &card);
if (err < 0)
goto error;
chip = (struct cx23885_audio_dev *) card->private_data;
chip->dev = dev;
chip->pci = dev->pci;
chip->card = card;
spin_lock_init(&chip->lock);
err = snd_cx23885_pcm(chip, 0, "CX23885 Digital");
if (err < 0)
goto error;
strcpy(card->driver, "CX23885");
sprintf(card->shortname, "Conexant CX23885");
sprintf(card->longname, "%s at %s", card->shortname, dev->name);
err = snd_card_register(card);
if (err < 0)
goto error;
dprintk(0, "registered ALSA audio device\n");
return chip;
error:
snd_card_free(card);
printk(KERN_ERR "%s(): Failed to register analog "
"audio adapter\n", __func__);
return NULL;
}
void cx23885_audio_unregister(struct cx23885_dev *dev)
{
struct cx23885_audio_dev *chip = dev->audio_dev;
snd_card_free(chip->card);
}
