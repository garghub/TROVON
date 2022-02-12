static int pdacf_pcm_clear_sram(struct snd_pdacf *chip)
{
int max_loop = 64 * 1024;
while (inw(chip->port + PDAUDIOCF_REG_RDP) != inw(chip->port + PDAUDIOCF_REG_WDP)) {
if (max_loop-- < 0)
return -EIO;
inw(chip->port + PDAUDIOCF_REG_MD);
}
return 0;
}
static int pdacf_pcm_trigger(struct snd_pcm_substream *subs, int cmd)
{
struct snd_pdacf *chip = snd_pcm_substream_chip(subs);
struct snd_pcm_runtime *runtime = subs->runtime;
int inc, ret = 0, rate;
unsigned short mask, val, tmp;
if (chip->chip_status & PDAUDIOCF_STAT_IS_STALE)
return -EBUSY;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
chip->pcm_hwptr = 0;
chip->pcm_tdone = 0;
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
case SNDRV_PCM_TRIGGER_RESUME:
mask = 0;
val = PDAUDIOCF_RECORD;
inc = 1;
rate = snd_ak4117_check_rate_and_errors(chip->ak4117, AK4117_CHECK_NO_STAT|AK4117_CHECK_NO_RATE);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
case SNDRV_PCM_TRIGGER_SUSPEND:
mask = PDAUDIOCF_RECORD;
val = 0;
inc = -1;
rate = 0;
break;
default:
return -EINVAL;
}
mutex_lock(&chip->reg_lock);
chip->pcm_running += inc;
tmp = pdacf_reg_read(chip, PDAUDIOCF_REG_SCR);
if (chip->pcm_running) {
if ((chip->ak4117->rcs0 & AK4117_UNLCK) || runtime->rate != rate) {
chip->pcm_running -= inc;
ret = -EIO;
goto __end;
}
}
tmp &= ~mask;
tmp |= val;
pdacf_reg_write(chip, PDAUDIOCF_REG_SCR, tmp);
__end:
mutex_unlock(&chip->reg_lock);
snd_ak4117_check_rate_and_errors(chip->ak4117, AK4117_CHECK_NO_RATE);
return ret;
}
static int pdacf_pcm_hw_params(struct snd_pcm_substream *subs,
struct snd_pcm_hw_params *hw_params)
{
return snd_pcm_lib_alloc_vmalloc_32_buffer
(subs, params_buffer_bytes(hw_params));
}
static int pdacf_pcm_hw_free(struct snd_pcm_substream *subs)
{
return snd_pcm_lib_free_vmalloc_buffer(subs);
}
static int pdacf_pcm_prepare(struct snd_pcm_substream *subs)
{
struct snd_pdacf *chip = snd_pcm_substream_chip(subs);
struct snd_pcm_runtime *runtime = subs->runtime;
u16 val, nval, aval;
if (chip->chip_status & PDAUDIOCF_STAT_IS_STALE)
return -EBUSY;
chip->pcm_channels = runtime->channels;
chip->pcm_little = snd_pcm_format_little_endian(runtime->format) > 0;
#ifdef SNDRV_LITTLE_ENDIAN
chip->pcm_swab = snd_pcm_format_big_endian(runtime->format) > 0;
#else
chip->pcm_swab = chip->pcm_little;
#endif
if (snd_pcm_format_unsigned(runtime->format))
chip->pcm_xor = 0x80008000;
if (pdacf_pcm_clear_sram(chip) < 0)
return -EIO;
val = nval = pdacf_reg_read(chip, PDAUDIOCF_REG_SCR);
nval &= ~(PDAUDIOCF_DATAFMT0|PDAUDIOCF_DATAFMT1);
switch (runtime->format) {
case SNDRV_PCM_FORMAT_S16_LE:
case SNDRV_PCM_FORMAT_S16_BE:
break;
default:
nval |= PDAUDIOCF_DATAFMT0 | PDAUDIOCF_DATAFMT1;
break;
}
aval = 0;
chip->pcm_sample = 4;
switch (runtime->format) {
case SNDRV_PCM_FORMAT_S16_LE:
case SNDRV_PCM_FORMAT_S16_BE:
aval = AK4117_DIF_16R;
chip->pcm_frame = 2;
chip->pcm_sample = 2;
break;
case SNDRV_PCM_FORMAT_S24_3LE:
case SNDRV_PCM_FORMAT_S24_3BE:
chip->pcm_sample = 3;
default:
aval = AK4117_DIF_24R;
chip->pcm_frame = 3;
chip->pcm_xor &= 0xffff0000;
break;
}
if (val != nval) {
snd_ak4117_reg_write(chip->ak4117, AK4117_REG_IO, AK4117_DIF2|AK4117_DIF1|AK4117_DIF0, aval);
pdacf_reg_write(chip, PDAUDIOCF_REG_SCR, nval);
}
val = pdacf_reg_read(chip, PDAUDIOCF_REG_IER);
val &= ~(PDAUDIOCF_IRQLVLEN1);
val |= PDAUDIOCF_IRQLVLEN0;
pdacf_reg_write(chip, PDAUDIOCF_REG_IER, val);
chip->pcm_size = runtime->buffer_size;
chip->pcm_period = runtime->period_size;
chip->pcm_area = runtime->dma_area;
return 0;
}
static int pdacf_pcm_capture_open(struct snd_pcm_substream *subs)
{
struct snd_pcm_runtime *runtime = subs->runtime;
struct snd_pdacf *chip = snd_pcm_substream_chip(subs);
if (chip->chip_status & PDAUDIOCF_STAT_IS_STALE)
return -EBUSY;
runtime->hw = pdacf_pcm_capture_hw;
runtime->private_data = chip;
chip->pcm_substream = subs;
return 0;
}
static int pdacf_pcm_capture_close(struct snd_pcm_substream *subs)
{
struct snd_pdacf *chip = snd_pcm_substream_chip(subs);
if (!chip)
return -EINVAL;
pdacf_reinit(chip, 0);
chip->pcm_substream = NULL;
return 0;
}
static snd_pcm_uframes_t pdacf_pcm_capture_pointer(struct snd_pcm_substream *subs)
{
struct snd_pdacf *chip = snd_pcm_substream_chip(subs);
return chip->pcm_hwptr;
}
int snd_pdacf_pcm_new(struct snd_pdacf *chip)
{
struct snd_pcm *pcm;
int err;
err = snd_pcm_new(chip->card, "PDAudioCF", 0, 0, 1, &pcm);
if (err < 0)
return err;
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE, &pdacf_pcm_capture_ops);
pcm->private_data = chip;
pcm->info_flags = 0;
pcm->nonatomic = true;
strcpy(pcm->name, chip->card->shortname);
chip->pcm = pcm;
err = snd_ak4117_build(chip->ak4117, pcm->streams[SNDRV_PCM_STREAM_CAPTURE].substream);
if (err < 0)
return err;
return 0;
}
