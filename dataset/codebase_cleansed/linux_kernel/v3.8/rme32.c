static inline unsigned int snd_rme32_pcm_byteptr(struct rme32 * rme32)
{
return (readl(rme32->iobase + RME32_IO_GET_POS)
& RME32_RCR_AUDIO_ADDR_MASK);
}
static int snd_rme32_playback_silence(struct snd_pcm_substream *substream, int channel,
snd_pcm_uframes_t pos,
snd_pcm_uframes_t count)
{
struct rme32 *rme32 = snd_pcm_substream_chip(substream);
count <<= rme32->playback_frlog;
pos <<= rme32->playback_frlog;
memset_io(rme32->iobase + RME32_IO_DATA_BUFFER + pos, 0, count);
return 0;
}
static int snd_rme32_playback_copy(struct snd_pcm_substream *substream, int channel,
snd_pcm_uframes_t pos,
void __user *src, snd_pcm_uframes_t count)
{
struct rme32 *rme32 = snd_pcm_substream_chip(substream);
count <<= rme32->playback_frlog;
pos <<= rme32->playback_frlog;
if (copy_from_user_toio(rme32->iobase + RME32_IO_DATA_BUFFER + pos,
src, count))
return -EFAULT;
return 0;
}
static int snd_rme32_capture_copy(struct snd_pcm_substream *substream, int channel,
snd_pcm_uframes_t pos,
void __user *dst, snd_pcm_uframes_t count)
{
struct rme32 *rme32 = snd_pcm_substream_chip(substream);
count <<= rme32->capture_frlog;
pos <<= rme32->capture_frlog;
if (copy_to_user_fromio(dst,
rme32->iobase + RME32_IO_DATA_BUFFER + pos,
count))
return -EFAULT;
return 0;
}
static void snd_rme32_reset_dac(struct rme32 *rme32)
{
writel(rme32->wcreg | RME32_WCR_PD,
rme32->iobase + RME32_IO_CONTROL_REGISTER);
writel(rme32->wcreg, rme32->iobase + RME32_IO_CONTROL_REGISTER);
}
static int snd_rme32_playback_getrate(struct rme32 * rme32)
{
int rate;
rate = ((rme32->wcreg >> RME32_WCR_BITPOS_FREQ_0) & 1) +
(((rme32->wcreg >> RME32_WCR_BITPOS_FREQ_1) & 1) << 1);
switch (rate) {
case 1:
rate = 32000;
break;
case 2:
rate = 44100;
break;
case 3:
rate = 48000;
break;
default:
return -1;
}
return (rme32->wcreg & RME32_WCR_DS_BM) ? rate << 1 : rate;
}
static int snd_rme32_capture_getrate(struct rme32 * rme32, int *is_adat)
{
int n;
*is_adat = 0;
if (rme32->rcreg & RME32_RCR_LOCK) {
*is_adat = 1;
}
if (rme32->rcreg & RME32_RCR_ERF) {
return -1;
}
n = ((rme32->rcreg >> RME32_RCR_BITPOS_F0) & 1) +
(((rme32->rcreg >> RME32_RCR_BITPOS_F1) & 1) << 1) +
(((rme32->rcreg >> RME32_RCR_BITPOS_F2) & 1) << 2);
if (RME32_PRO_WITH_8414(rme32))
switch (n) {
case 0:
case 1:
case 2:
return -1;
case 3:
return 96000;
case 4:
return 88200;
case 5:
return 48000;
case 6:
return 44100;
case 7:
return 32000;
default:
return -1;
break;
}
else
switch (n) {
case 0:
return -1;
case 1:
return 48000;
case 2:
return 44100;
case 3:
return 32000;
case 4:
return 48000;
case 5:
return 44100;
case 6:
return 44056;
case 7:
return 32000;
default:
break;
}
return -1;
}
static int snd_rme32_playback_setrate(struct rme32 * rme32, int rate)
{
int ds;
ds = rme32->wcreg & RME32_WCR_DS_BM;
switch (rate) {
case 32000:
rme32->wcreg &= ~RME32_WCR_DS_BM;
rme32->wcreg = (rme32->wcreg | RME32_WCR_FREQ_0) &
~RME32_WCR_FREQ_1;
break;
case 44100:
rme32->wcreg &= ~RME32_WCR_DS_BM;
rme32->wcreg = (rme32->wcreg | RME32_WCR_FREQ_1) &
~RME32_WCR_FREQ_0;
break;
case 48000:
rme32->wcreg &= ~RME32_WCR_DS_BM;
rme32->wcreg = (rme32->wcreg | RME32_WCR_FREQ_0) |
RME32_WCR_FREQ_1;
break;
case 64000:
if (rme32->pci->device != PCI_DEVICE_ID_RME_DIGI32_PRO)
return -EINVAL;
rme32->wcreg |= RME32_WCR_DS_BM;
rme32->wcreg = (rme32->wcreg | RME32_WCR_FREQ_0) &
~RME32_WCR_FREQ_1;
break;
case 88200:
if (rme32->pci->device != PCI_DEVICE_ID_RME_DIGI32_PRO)
return -EINVAL;
rme32->wcreg |= RME32_WCR_DS_BM;
rme32->wcreg = (rme32->wcreg | RME32_WCR_FREQ_1) &
~RME32_WCR_FREQ_0;
break;
case 96000:
if (rme32->pci->device != PCI_DEVICE_ID_RME_DIGI32_PRO)
return -EINVAL;
rme32->wcreg |= RME32_WCR_DS_BM;
rme32->wcreg = (rme32->wcreg | RME32_WCR_FREQ_0) |
RME32_WCR_FREQ_1;
break;
default:
return -EINVAL;
}
if ((!ds && rme32->wcreg & RME32_WCR_DS_BM) ||
(ds && !(rme32->wcreg & RME32_WCR_DS_BM)))
{
snd_rme32_reset_dac(rme32);
} else {
writel(rme32->wcreg, rme32->iobase + RME32_IO_CONTROL_REGISTER);
}
return 0;
}
static int snd_rme32_setclockmode(struct rme32 * rme32, int mode)
{
switch (mode) {
case RME32_CLOCKMODE_SLAVE:
rme32->wcreg = (rme32->wcreg & ~RME32_WCR_FREQ_0) &
~RME32_WCR_FREQ_1;
break;
case RME32_CLOCKMODE_MASTER_32:
rme32->wcreg = (rme32->wcreg | RME32_WCR_FREQ_0) &
~RME32_WCR_FREQ_1;
break;
case RME32_CLOCKMODE_MASTER_44:
rme32->wcreg = (rme32->wcreg & ~RME32_WCR_FREQ_0) |
RME32_WCR_FREQ_1;
break;
case RME32_CLOCKMODE_MASTER_48:
rme32->wcreg = (rme32->wcreg | RME32_WCR_FREQ_0) |
RME32_WCR_FREQ_1;
break;
default:
return -EINVAL;
}
writel(rme32->wcreg, rme32->iobase + RME32_IO_CONTROL_REGISTER);
return 0;
}
static int snd_rme32_getclockmode(struct rme32 * rme32)
{
return ((rme32->wcreg >> RME32_WCR_BITPOS_FREQ_0) & 1) +
(((rme32->wcreg >> RME32_WCR_BITPOS_FREQ_1) & 1) << 1);
}
static int snd_rme32_setinputtype(struct rme32 * rme32, int type)
{
switch (type) {
case RME32_INPUT_OPTICAL:
rme32->wcreg = (rme32->wcreg & ~RME32_WCR_INP_0) &
~RME32_WCR_INP_1;
break;
case RME32_INPUT_COAXIAL:
rme32->wcreg = (rme32->wcreg | RME32_WCR_INP_0) &
~RME32_WCR_INP_1;
break;
case RME32_INPUT_INTERNAL:
rme32->wcreg = (rme32->wcreg & ~RME32_WCR_INP_0) |
RME32_WCR_INP_1;
break;
case RME32_INPUT_XLR:
rme32->wcreg = (rme32->wcreg | RME32_WCR_INP_0) |
RME32_WCR_INP_1;
break;
default:
return -EINVAL;
}
writel(rme32->wcreg, rme32->iobase + RME32_IO_CONTROL_REGISTER);
return 0;
}
static int snd_rme32_getinputtype(struct rme32 * rme32)
{
return ((rme32->wcreg >> RME32_WCR_BITPOS_INP_0) & 1) +
(((rme32->wcreg >> RME32_WCR_BITPOS_INP_1) & 1) << 1);
}
static void
snd_rme32_setframelog(struct rme32 * rme32, int n_channels, int is_playback)
{
int frlog;
if (n_channels == 2) {
frlog = 1;
} else {
frlog = 3;
}
if (is_playback) {
frlog += (rme32->wcreg & RME32_WCR_MODE24) ? 2 : 1;
rme32->playback_frlog = frlog;
} else {
frlog += (rme32->wcreg & RME32_WCR_MODE24) ? 2 : 1;
rme32->capture_frlog = frlog;
}
}
static int snd_rme32_setformat(struct rme32 * rme32, int format)
{
switch (format) {
case SNDRV_PCM_FORMAT_S16_LE:
rme32->wcreg &= ~RME32_WCR_MODE24;
break;
case SNDRV_PCM_FORMAT_S32_LE:
rme32->wcreg |= RME32_WCR_MODE24;
break;
default:
return -EINVAL;
}
writel(rme32->wcreg, rme32->iobase + RME32_IO_CONTROL_REGISTER);
return 0;
}
static int
snd_rme32_playback_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
int err, rate, dummy;
struct rme32 *rme32 = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
if (rme32->fullduplex_mode) {
err = snd_pcm_lib_malloc_pages(substream, params_buffer_bytes(params));
if (err < 0)
return err;
} else {
runtime->dma_area = (void __force *)(rme32->iobase +
RME32_IO_DATA_BUFFER);
runtime->dma_addr = rme32->port + RME32_IO_DATA_BUFFER;
runtime->dma_bytes = RME32_BUFFER_SIZE;
}
spin_lock_irq(&rme32->lock);
if ((rme32->rcreg & RME32_RCR_KMODE) &&
(rate = snd_rme32_capture_getrate(rme32, &dummy)) > 0) {
if ((int)params_rate(params) != rate) {
spin_unlock_irq(&rme32->lock);
return -EIO;
}
} else if ((err = snd_rme32_playback_setrate(rme32, params_rate(params))) < 0) {
spin_unlock_irq(&rme32->lock);
return err;
}
if ((err = snd_rme32_setformat(rme32, params_format(params))) < 0) {
spin_unlock_irq(&rme32->lock);
return err;
}
snd_rme32_setframelog(rme32, params_channels(params), 1);
if (rme32->capture_periodsize != 0) {
if (params_period_size(params) << rme32->playback_frlog != rme32->capture_periodsize) {
spin_unlock_irq(&rme32->lock);
return -EBUSY;
}
}
rme32->playback_periodsize = params_period_size(params) << rme32->playback_frlog;
if ((rme32->wcreg & RME32_WCR_ADAT) == 0) {
rme32->wcreg &= ~(RME32_WCR_PRO | RME32_WCR_EMP);
rme32->wcreg |= rme32->wcreg_spdif_stream;
writel(rme32->wcreg, rme32->iobase + RME32_IO_CONTROL_REGISTER);
}
spin_unlock_irq(&rme32->lock);
return 0;
}
static int
snd_rme32_capture_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
int err, isadat, rate;
struct rme32 *rme32 = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
if (rme32->fullduplex_mode) {
err = snd_pcm_lib_malloc_pages(substream, params_buffer_bytes(params));
if (err < 0)
return err;
} else {
runtime->dma_area = (void __force *)rme32->iobase +
RME32_IO_DATA_BUFFER;
runtime->dma_addr = rme32->port + RME32_IO_DATA_BUFFER;
runtime->dma_bytes = RME32_BUFFER_SIZE;
}
spin_lock_irq(&rme32->lock);
rme32->wcreg |= RME32_WCR_AUTOSYNC;
writel(rme32->wcreg, rme32->iobase + RME32_IO_CONTROL_REGISTER);
if ((err = snd_rme32_setformat(rme32, params_format(params))) < 0) {
spin_unlock_irq(&rme32->lock);
return err;
}
if ((err = snd_rme32_playback_setrate(rme32, params_rate(params))) < 0) {
spin_unlock_irq(&rme32->lock);
return err;
}
if ((rate = snd_rme32_capture_getrate(rme32, &isadat)) > 0) {
if ((int)params_rate(params) != rate) {
spin_unlock_irq(&rme32->lock);
return -EIO;
}
if ((isadat && runtime->hw.channels_min == 2) ||
(!isadat && runtime->hw.channels_min == 8)) {
spin_unlock_irq(&rme32->lock);
return -EIO;
}
}
rme32->wcreg &= ~RME32_WCR_AUTOSYNC;
writel(rme32->wcreg, rme32->iobase + RME32_IO_CONTROL_REGISTER);
snd_rme32_setframelog(rme32, params_channels(params), 0);
if (rme32->playback_periodsize != 0) {
if (params_period_size(params) << rme32->capture_frlog !=
rme32->playback_periodsize) {
spin_unlock_irq(&rme32->lock);
return -EBUSY;
}
}
rme32->capture_periodsize =
params_period_size(params) << rme32->capture_frlog;
spin_unlock_irq(&rme32->lock);
return 0;
}
static int snd_rme32_pcm_hw_free(struct snd_pcm_substream *substream)
{
struct rme32 *rme32 = snd_pcm_substream_chip(substream);
if (! rme32->fullduplex_mode)
return 0;
return snd_pcm_lib_free_pages(substream);
}
static void snd_rme32_pcm_start(struct rme32 * rme32, int from_pause)
{
if (!from_pause) {
writel(0, rme32->iobase + RME32_IO_RESET_POS);
}
rme32->wcreg |= RME32_WCR_START;
writel(rme32->wcreg, rme32->iobase + RME32_IO_CONTROL_REGISTER);
}
static void snd_rme32_pcm_stop(struct rme32 * rme32, int to_pause)
{
rme32->rcreg = readl(rme32->iobase + RME32_IO_CONTROL_REGISTER);
if (rme32->rcreg & RME32_RCR_IRQ) {
writel(0, rme32->iobase + RME32_IO_CONFIRM_ACTION_IRQ);
}
rme32->wcreg &= ~RME32_WCR_START;
if (rme32->wcreg & RME32_WCR_SEL)
rme32->wcreg |= RME32_WCR_MUTE;
writel(rme32->wcreg, rme32->iobase + RME32_IO_CONTROL_REGISTER);
if (! to_pause)
writel(0, rme32->iobase + RME32_IO_RESET_POS);
}
static irqreturn_t snd_rme32_interrupt(int irq, void *dev_id)
{
struct rme32 *rme32 = (struct rme32 *) dev_id;
rme32->rcreg = readl(rme32->iobase + RME32_IO_CONTROL_REGISTER);
if (!(rme32->rcreg & RME32_RCR_IRQ)) {
return IRQ_NONE;
} else {
if (rme32->capture_substream) {
snd_pcm_period_elapsed(rme32->capture_substream);
}
if (rme32->playback_substream) {
snd_pcm_period_elapsed(rme32->playback_substream);
}
writel(0, rme32->iobase + RME32_IO_CONFIRM_ACTION_IRQ);
}
return IRQ_HANDLED;
}
static void snd_rme32_set_buffer_constraint(struct rme32 *rme32, struct snd_pcm_runtime *runtime)
{
if (! rme32->fullduplex_mode) {
snd_pcm_hw_constraint_minmax(runtime,
SNDRV_PCM_HW_PARAM_BUFFER_BYTES,
RME32_BUFFER_SIZE, RME32_BUFFER_SIZE);
snd_pcm_hw_constraint_list(runtime, 0,
SNDRV_PCM_HW_PARAM_PERIOD_BYTES,
&hw_constraints_period_bytes);
}
}
static int snd_rme32_playback_spdif_open(struct snd_pcm_substream *substream)
{
int rate, dummy;
struct rme32 *rme32 = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
snd_pcm_set_sync(substream);
spin_lock_irq(&rme32->lock);
if (rme32->playback_substream != NULL) {
spin_unlock_irq(&rme32->lock);
return -EBUSY;
}
rme32->wcreg &= ~RME32_WCR_ADAT;
writel(rme32->wcreg, rme32->iobase + RME32_IO_CONTROL_REGISTER);
rme32->playback_substream = substream;
spin_unlock_irq(&rme32->lock);
if (rme32->fullduplex_mode)
runtime->hw = snd_rme32_spdif_fd_info;
else
runtime->hw = snd_rme32_spdif_info;
if (rme32->pci->device == PCI_DEVICE_ID_RME_DIGI32_PRO) {
runtime->hw.rates |= SNDRV_PCM_RATE_64000 | SNDRV_PCM_RATE_88200 | SNDRV_PCM_RATE_96000;
runtime->hw.rate_max = 96000;
}
if ((rme32->rcreg & RME32_RCR_KMODE) &&
(rate = snd_rme32_capture_getrate(rme32, &dummy)) > 0) {
runtime->hw.rates = snd_pcm_rate_to_rate_bit(rate);
runtime->hw.rate_min = rate;
runtime->hw.rate_max = rate;
}
snd_rme32_set_buffer_constraint(rme32, runtime);
rme32->wcreg_spdif_stream = rme32->wcreg_spdif;
rme32->spdif_ctl->vd[0].access &= ~SNDRV_CTL_ELEM_ACCESS_INACTIVE;
snd_ctl_notify(rme32->card, SNDRV_CTL_EVENT_MASK_VALUE |
SNDRV_CTL_EVENT_MASK_INFO, &rme32->spdif_ctl->id);
return 0;
}
static int snd_rme32_capture_spdif_open(struct snd_pcm_substream *substream)
{
int isadat, rate;
struct rme32 *rme32 = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
snd_pcm_set_sync(substream);
spin_lock_irq(&rme32->lock);
if (rme32->capture_substream != NULL) {
spin_unlock_irq(&rme32->lock);
return -EBUSY;
}
rme32->capture_substream = substream;
spin_unlock_irq(&rme32->lock);
if (rme32->fullduplex_mode)
runtime->hw = snd_rme32_spdif_fd_info;
else
runtime->hw = snd_rme32_spdif_info;
if (RME32_PRO_WITH_8414(rme32)) {
runtime->hw.rates |= SNDRV_PCM_RATE_88200 | SNDRV_PCM_RATE_96000;
runtime->hw.rate_max = 96000;
}
if ((rate = snd_rme32_capture_getrate(rme32, &isadat)) > 0) {
if (isadat) {
return -EIO;
}
runtime->hw.rates = snd_pcm_rate_to_rate_bit(rate);
runtime->hw.rate_min = rate;
runtime->hw.rate_max = rate;
}
snd_rme32_set_buffer_constraint(rme32, runtime);
return 0;
}
static int
snd_rme32_playback_adat_open(struct snd_pcm_substream *substream)
{
int rate, dummy;
struct rme32 *rme32 = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
snd_pcm_set_sync(substream);
spin_lock_irq(&rme32->lock);
if (rme32->playback_substream != NULL) {
spin_unlock_irq(&rme32->lock);
return -EBUSY;
}
rme32->wcreg |= RME32_WCR_ADAT;
writel(rme32->wcreg, rme32->iobase + RME32_IO_CONTROL_REGISTER);
rme32->playback_substream = substream;
spin_unlock_irq(&rme32->lock);
if (rme32->fullduplex_mode)
runtime->hw = snd_rme32_adat_fd_info;
else
runtime->hw = snd_rme32_adat_info;
if ((rme32->rcreg & RME32_RCR_KMODE) &&
(rate = snd_rme32_capture_getrate(rme32, &dummy)) > 0) {
runtime->hw.rates = snd_pcm_rate_to_rate_bit(rate);
runtime->hw.rate_min = rate;
runtime->hw.rate_max = rate;
}
snd_rme32_set_buffer_constraint(rme32, runtime);
return 0;
}
static int
snd_rme32_capture_adat_open(struct snd_pcm_substream *substream)
{
int isadat, rate;
struct rme32 *rme32 = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
if (rme32->fullduplex_mode)
runtime->hw = snd_rme32_adat_fd_info;
else
runtime->hw = snd_rme32_adat_info;
if ((rate = snd_rme32_capture_getrate(rme32, &isadat)) > 0) {
if (!isadat) {
return -EIO;
}
runtime->hw.rates = snd_pcm_rate_to_rate_bit(rate);
runtime->hw.rate_min = rate;
runtime->hw.rate_max = rate;
}
snd_pcm_set_sync(substream);
spin_lock_irq(&rme32->lock);
if (rme32->capture_substream != NULL) {
spin_unlock_irq(&rme32->lock);
return -EBUSY;
}
rme32->capture_substream = substream;
spin_unlock_irq(&rme32->lock);
snd_rme32_set_buffer_constraint(rme32, runtime);
return 0;
}
static int snd_rme32_playback_close(struct snd_pcm_substream *substream)
{
struct rme32 *rme32 = snd_pcm_substream_chip(substream);
int spdif = 0;
spin_lock_irq(&rme32->lock);
rme32->playback_substream = NULL;
rme32->playback_periodsize = 0;
spdif = (rme32->wcreg & RME32_WCR_ADAT) == 0;
spin_unlock_irq(&rme32->lock);
if (spdif) {
rme32->spdif_ctl->vd[0].access |= SNDRV_CTL_ELEM_ACCESS_INACTIVE;
snd_ctl_notify(rme32->card, SNDRV_CTL_EVENT_MASK_VALUE |
SNDRV_CTL_EVENT_MASK_INFO,
&rme32->spdif_ctl->id);
}
return 0;
}
static int snd_rme32_capture_close(struct snd_pcm_substream *substream)
{
struct rme32 *rme32 = snd_pcm_substream_chip(substream);
spin_lock_irq(&rme32->lock);
rme32->capture_substream = NULL;
rme32->capture_periodsize = 0;
spin_unlock(&rme32->lock);
return 0;
}
static int snd_rme32_playback_prepare(struct snd_pcm_substream *substream)
{
struct rme32 *rme32 = snd_pcm_substream_chip(substream);
spin_lock_irq(&rme32->lock);
if (rme32->fullduplex_mode) {
memset(&rme32->playback_pcm, 0, sizeof(rme32->playback_pcm));
rme32->playback_pcm.hw_buffer_size = RME32_BUFFER_SIZE;
rme32->playback_pcm.sw_buffer_size = snd_pcm_lib_buffer_bytes(substream);
} else {
writel(0, rme32->iobase + RME32_IO_RESET_POS);
}
if (rme32->wcreg & RME32_WCR_SEL)
rme32->wcreg &= ~RME32_WCR_MUTE;
writel(rme32->wcreg, rme32->iobase + RME32_IO_CONTROL_REGISTER);
spin_unlock_irq(&rme32->lock);
return 0;
}
static int snd_rme32_capture_prepare(struct snd_pcm_substream *substream)
{
struct rme32 *rme32 = snd_pcm_substream_chip(substream);
spin_lock_irq(&rme32->lock);
if (rme32->fullduplex_mode) {
memset(&rme32->capture_pcm, 0, sizeof(rme32->capture_pcm));
rme32->capture_pcm.hw_buffer_size = RME32_BUFFER_SIZE;
rme32->capture_pcm.hw_queue_size = RME32_BUFFER_SIZE / 2;
rme32->capture_pcm.sw_buffer_size = snd_pcm_lib_buffer_bytes(substream);
} else {
writel(0, rme32->iobase + RME32_IO_RESET_POS);
}
spin_unlock_irq(&rme32->lock);
return 0;
}
static int
snd_rme32_pcm_trigger(struct snd_pcm_substream *substream, int cmd)
{
struct rme32 *rme32 = snd_pcm_substream_chip(substream);
struct snd_pcm_substream *s;
spin_lock(&rme32->lock);
snd_pcm_group_for_each_entry(s, substream) {
if (s != rme32->playback_substream &&
s != rme32->capture_substream)
continue;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
rme32->running |= (1 << s->stream);
if (rme32->fullduplex_mode) {
if (s == rme32->playback_substream) {
rme32->playback_pcm.hw_io =
rme32->playback_pcm.hw_data = snd_rme32_pcm_byteptr(rme32);
} else {
rme32->capture_pcm.hw_io =
rme32->capture_pcm.hw_data = snd_rme32_pcm_byteptr(rme32);
}
}
break;
case SNDRV_PCM_TRIGGER_STOP:
rme32->running &= ~(1 << s->stream);
break;
}
snd_pcm_trigger_done(s, substream);
}
if (cmd == SNDRV_PCM_TRIGGER_START && rme32->fullduplex_mode) {
snd_pcm_group_for_each_entry(s, substream) {
if (s == rme32->playback_substream) {
s->ops->ack(s);
break;
}
}
}
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
if (rme32->running && ! RME32_ISWORKING(rme32))
snd_rme32_pcm_start(rme32, 0);
break;
case SNDRV_PCM_TRIGGER_STOP:
if (! rme32->running && RME32_ISWORKING(rme32))
snd_rme32_pcm_stop(rme32, 0);
break;
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
if (rme32->running && RME32_ISWORKING(rme32))
snd_rme32_pcm_stop(rme32, 1);
break;
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
if (rme32->running && ! RME32_ISWORKING(rme32))
snd_rme32_pcm_start(rme32, 1);
break;
}
spin_unlock(&rme32->lock);
return 0;
}
static snd_pcm_uframes_t
snd_rme32_playback_pointer(struct snd_pcm_substream *substream)
{
struct rme32 *rme32 = snd_pcm_substream_chip(substream);
return snd_rme32_pcm_byteptr(rme32) >> rme32->playback_frlog;
}
static snd_pcm_uframes_t
snd_rme32_capture_pointer(struct snd_pcm_substream *substream)
{
struct rme32 *rme32 = snd_pcm_substream_chip(substream);
return snd_rme32_pcm_byteptr(rme32) >> rme32->capture_frlog;
}
static void snd_rme32_pb_trans_copy(struct snd_pcm_substream *substream,
struct snd_pcm_indirect *rec, size_t bytes)
{
struct rme32 *rme32 = snd_pcm_substream_chip(substream);
memcpy_toio(rme32->iobase + RME32_IO_DATA_BUFFER + rec->hw_data,
substream->runtime->dma_area + rec->sw_data, bytes);
}
static int snd_rme32_playback_fd_ack(struct snd_pcm_substream *substream)
{
struct rme32 *rme32 = snd_pcm_substream_chip(substream);
struct snd_pcm_indirect *rec, *cprec;
rec = &rme32->playback_pcm;
cprec = &rme32->capture_pcm;
spin_lock(&rme32->lock);
rec->hw_queue_size = RME32_BUFFER_SIZE;
if (rme32->running & (1 << SNDRV_PCM_STREAM_CAPTURE))
rec->hw_queue_size -= cprec->hw_ready;
spin_unlock(&rme32->lock);
snd_pcm_indirect_playback_transfer(substream, rec,
snd_rme32_pb_trans_copy);
return 0;
}
static void snd_rme32_cp_trans_copy(struct snd_pcm_substream *substream,
struct snd_pcm_indirect *rec, size_t bytes)
{
struct rme32 *rme32 = snd_pcm_substream_chip(substream);
memcpy_fromio(substream->runtime->dma_area + rec->sw_data,
rme32->iobase + RME32_IO_DATA_BUFFER + rec->hw_data,
bytes);
}
static int snd_rme32_capture_fd_ack(struct snd_pcm_substream *substream)
{
struct rme32 *rme32 = snd_pcm_substream_chip(substream);
snd_pcm_indirect_capture_transfer(substream, &rme32->capture_pcm,
snd_rme32_cp_trans_copy);
return 0;
}
static snd_pcm_uframes_t
snd_rme32_playback_fd_pointer(struct snd_pcm_substream *substream)
{
struct rme32 *rme32 = snd_pcm_substream_chip(substream);
return snd_pcm_indirect_playback_pointer(substream, &rme32->playback_pcm,
snd_rme32_pcm_byteptr(rme32));
}
static snd_pcm_uframes_t
snd_rme32_capture_fd_pointer(struct snd_pcm_substream *substream)
{
struct rme32 *rme32 = snd_pcm_substream_chip(substream);
return snd_pcm_indirect_capture_pointer(substream, &rme32->capture_pcm,
snd_rme32_pcm_byteptr(rme32));
}
static void snd_rme32_free(void *private_data)
{
struct rme32 *rme32 = (struct rme32 *) private_data;
if (rme32 == NULL) {
return;
}
if (rme32->irq >= 0) {
snd_rme32_pcm_stop(rme32, 0);
free_irq(rme32->irq, (void *) rme32);
rme32->irq = -1;
}
if (rme32->iobase) {
iounmap(rme32->iobase);
rme32->iobase = NULL;
}
if (rme32->port) {
pci_release_regions(rme32->pci);
rme32->port = 0;
}
pci_disable_device(rme32->pci);
}
static void snd_rme32_free_spdif_pcm(struct snd_pcm *pcm)
{
struct rme32 *rme32 = (struct rme32 *) pcm->private_data;
rme32->spdif_pcm = NULL;
}
static void
snd_rme32_free_adat_pcm(struct snd_pcm *pcm)
{
struct rme32 *rme32 = (struct rme32 *) pcm->private_data;
rme32->adat_pcm = NULL;
}
static int snd_rme32_create(struct rme32 *rme32)
{
struct pci_dev *pci = rme32->pci;
int err;
rme32->irq = -1;
spin_lock_init(&rme32->lock);
if ((err = pci_enable_device(pci)) < 0)
return err;
if ((err = pci_request_regions(pci, "RME32")) < 0)
return err;
rme32->port = pci_resource_start(rme32->pci, 0);
rme32->iobase = ioremap_nocache(rme32->port, RME32_IO_SIZE);
if (!rme32->iobase) {
snd_printk(KERN_ERR "unable to remap memory region 0x%lx-0x%lx\n",
rme32->port, rme32->port + RME32_IO_SIZE - 1);
return -ENOMEM;
}
if (request_irq(pci->irq, snd_rme32_interrupt, IRQF_SHARED,
KBUILD_MODNAME, rme32)) {
snd_printk(KERN_ERR "unable to grab IRQ %d\n", pci->irq);
return -EBUSY;
}
rme32->irq = pci->irq;
pci_read_config_byte(pci, 8, &rme32->rev);
if ((err = snd_pcm_new(rme32->card, "Digi32 IEC958", 0, 1, 1, &rme32->spdif_pcm)) < 0) {
return err;
}
rme32->spdif_pcm->private_data = rme32;
rme32->spdif_pcm->private_free = snd_rme32_free_spdif_pcm;
strcpy(rme32->spdif_pcm->name, "Digi32 IEC958");
if (rme32->fullduplex_mode) {
snd_pcm_set_ops(rme32->spdif_pcm, SNDRV_PCM_STREAM_PLAYBACK,
&snd_rme32_playback_spdif_fd_ops);
snd_pcm_set_ops(rme32->spdif_pcm, SNDRV_PCM_STREAM_CAPTURE,
&snd_rme32_capture_spdif_fd_ops);
snd_pcm_lib_preallocate_pages_for_all(rme32->spdif_pcm, SNDRV_DMA_TYPE_CONTINUOUS,
snd_dma_continuous_data(GFP_KERNEL),
0, RME32_MID_BUFFER_SIZE);
rme32->spdif_pcm->info_flags = SNDRV_PCM_INFO_JOINT_DUPLEX;
} else {
snd_pcm_set_ops(rme32->spdif_pcm, SNDRV_PCM_STREAM_PLAYBACK,
&snd_rme32_playback_spdif_ops);
snd_pcm_set_ops(rme32->spdif_pcm, SNDRV_PCM_STREAM_CAPTURE,
&snd_rme32_capture_spdif_ops);
rme32->spdif_pcm->info_flags = SNDRV_PCM_INFO_HALF_DUPLEX;
}
if ((pci->device == PCI_DEVICE_ID_RME_DIGI32) ||
(pci->device == PCI_DEVICE_ID_RME_DIGI32_PRO)) {
rme32->adat_pcm = NULL;
}
else {
if ((err = snd_pcm_new(rme32->card, "Digi32 ADAT", 1,
1, 1, &rme32->adat_pcm)) < 0)
{
return err;
}
rme32->adat_pcm->private_data = rme32;
rme32->adat_pcm->private_free = snd_rme32_free_adat_pcm;
strcpy(rme32->adat_pcm->name, "Digi32 ADAT");
if (rme32->fullduplex_mode) {
snd_pcm_set_ops(rme32->adat_pcm, SNDRV_PCM_STREAM_PLAYBACK,
&snd_rme32_playback_adat_fd_ops);
snd_pcm_set_ops(rme32->adat_pcm, SNDRV_PCM_STREAM_CAPTURE,
&snd_rme32_capture_adat_fd_ops);
snd_pcm_lib_preallocate_pages_for_all(rme32->adat_pcm, SNDRV_DMA_TYPE_CONTINUOUS,
snd_dma_continuous_data(GFP_KERNEL),
0, RME32_MID_BUFFER_SIZE);
rme32->adat_pcm->info_flags = SNDRV_PCM_INFO_JOINT_DUPLEX;
} else {
snd_pcm_set_ops(rme32->adat_pcm, SNDRV_PCM_STREAM_PLAYBACK,
&snd_rme32_playback_adat_ops);
snd_pcm_set_ops(rme32->adat_pcm, SNDRV_PCM_STREAM_CAPTURE,
&snd_rme32_capture_adat_ops);
rme32->adat_pcm->info_flags = SNDRV_PCM_INFO_HALF_DUPLEX;
}
}
rme32->playback_periodsize = 0;
rme32->capture_periodsize = 0;
snd_rme32_pcm_stop(rme32, 0);
snd_rme32_reset_dac(rme32);
writel(0, rme32->iobase + RME32_IO_RESET_POS);
rme32->wcreg = RME32_WCR_SEL |
RME32_WCR_INP_0 |
RME32_WCR_MUTE;
writel(rme32->wcreg, rme32->iobase + RME32_IO_CONTROL_REGISTER);
if ((err = snd_rme32_create_switches(rme32->card, rme32)) < 0) {
return err;
}
snd_rme32_proc_init(rme32);
rme32->capture_substream = NULL;
rme32->playback_substream = NULL;
return 0;
}
static void
snd_rme32_proc_read(struct snd_info_entry * entry, struct snd_info_buffer *buffer)
{
int n;
struct rme32 *rme32 = (struct rme32 *) entry->private_data;
rme32->rcreg = readl(rme32->iobase + RME32_IO_CONTROL_REGISTER);
snd_iprintf(buffer, rme32->card->longname);
snd_iprintf(buffer, " (index #%d)\n", rme32->card->number + 1);
snd_iprintf(buffer, "\nGeneral settings\n");
if (rme32->fullduplex_mode)
snd_iprintf(buffer, " Full-duplex mode\n");
else
snd_iprintf(buffer, " Half-duplex mode\n");
if (RME32_PRO_WITH_8414(rme32)) {
snd_iprintf(buffer, " receiver: CS8414\n");
} else {
snd_iprintf(buffer, " receiver: CS8412\n");
}
if (rme32->wcreg & RME32_WCR_MODE24) {
snd_iprintf(buffer, " format: 24 bit");
} else {
snd_iprintf(buffer, " format: 16 bit");
}
if (rme32->wcreg & RME32_WCR_MONO) {
snd_iprintf(buffer, ", Mono\n");
} else {
snd_iprintf(buffer, ", Stereo\n");
}
snd_iprintf(buffer, "\nInput settings\n");
switch (snd_rme32_getinputtype(rme32)) {
case RME32_INPUT_OPTICAL:
snd_iprintf(buffer, " input: optical");
break;
case RME32_INPUT_COAXIAL:
snd_iprintf(buffer, " input: coaxial");
break;
case RME32_INPUT_INTERNAL:
snd_iprintf(buffer, " input: internal");
break;
case RME32_INPUT_XLR:
snd_iprintf(buffer, " input: XLR");
break;
}
if (snd_rme32_capture_getrate(rme32, &n) < 0) {
snd_iprintf(buffer, "\n sample rate: no valid signal\n");
} else {
if (n) {
snd_iprintf(buffer, " (8 channels)\n");
} else {
snd_iprintf(buffer, " (2 channels)\n");
}
snd_iprintf(buffer, " sample rate: %d Hz\n",
snd_rme32_capture_getrate(rme32, &n));
}
snd_iprintf(buffer, "\nOutput settings\n");
if (rme32->wcreg & RME32_WCR_SEL) {
snd_iprintf(buffer, " output signal: normal playback");
} else {
snd_iprintf(buffer, " output signal: same as input");
}
if (rme32->wcreg & RME32_WCR_MUTE) {
snd_iprintf(buffer, " (muted)\n");
} else {
snd_iprintf(buffer, "\n");
}
if (!
((!(rme32->wcreg & RME32_WCR_FREQ_0))
&& (!(rme32->wcreg & RME32_WCR_FREQ_1)))) {
snd_iprintf(buffer, " sample rate: %d Hz\n",
snd_rme32_playback_getrate(rme32));
}
if (rme32->rcreg & RME32_RCR_KMODE) {
snd_iprintf(buffer, " sample clock source: AutoSync\n");
} else {
snd_iprintf(buffer, " sample clock source: Internal\n");
}
if (rme32->wcreg & RME32_WCR_PRO) {
snd_iprintf(buffer, " format: AES/EBU (professional)\n");
} else {
snd_iprintf(buffer, " format: IEC958 (consumer)\n");
}
if (rme32->wcreg & RME32_WCR_EMP) {
snd_iprintf(buffer, " emphasis: on\n");
} else {
snd_iprintf(buffer, " emphasis: off\n");
}
}
static void snd_rme32_proc_init(struct rme32 *rme32)
{
struct snd_info_entry *entry;
if (! snd_card_proc_new(rme32->card, "rme32", &entry))
snd_info_set_text_ops(entry, rme32, snd_rme32_proc_read);
}
static int
snd_rme32_get_loopback_control(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct rme32 *rme32 = snd_kcontrol_chip(kcontrol);
spin_lock_irq(&rme32->lock);
ucontrol->value.integer.value[0] =
rme32->wcreg & RME32_WCR_SEL ? 0 : 1;
spin_unlock_irq(&rme32->lock);
return 0;
}
static int
snd_rme32_put_loopback_control(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct rme32 *rme32 = snd_kcontrol_chip(kcontrol);
unsigned int val;
int change;
val = ucontrol->value.integer.value[0] ? 0 : RME32_WCR_SEL;
spin_lock_irq(&rme32->lock);
val = (rme32->wcreg & ~RME32_WCR_SEL) | val;
change = val != rme32->wcreg;
if (ucontrol->value.integer.value[0])
val &= ~RME32_WCR_MUTE;
else
val |= RME32_WCR_MUTE;
rme32->wcreg = val;
writel(val, rme32->iobase + RME32_IO_CONTROL_REGISTER);
spin_unlock_irq(&rme32->lock);
return change;
}
static int
snd_rme32_info_inputtype_control(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct rme32 *rme32 = snd_kcontrol_chip(kcontrol);
static char *texts[4] = { "Optical", "Coaxial", "Internal", "XLR" };
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
switch (rme32->pci->device) {
case PCI_DEVICE_ID_RME_DIGI32:
case PCI_DEVICE_ID_RME_DIGI32_8:
uinfo->value.enumerated.items = 3;
break;
case PCI_DEVICE_ID_RME_DIGI32_PRO:
uinfo->value.enumerated.items = 4;
break;
default:
snd_BUG();
break;
}
if (uinfo->value.enumerated.item >
uinfo->value.enumerated.items - 1) {
uinfo->value.enumerated.item =
uinfo->value.enumerated.items - 1;
}
strcpy(uinfo->value.enumerated.name,
texts[uinfo->value.enumerated.item]);
return 0;
}
static int
snd_rme32_get_inputtype_control(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct rme32 *rme32 = snd_kcontrol_chip(kcontrol);
unsigned int items = 3;
spin_lock_irq(&rme32->lock);
ucontrol->value.enumerated.item[0] = snd_rme32_getinputtype(rme32);
switch (rme32->pci->device) {
case PCI_DEVICE_ID_RME_DIGI32:
case PCI_DEVICE_ID_RME_DIGI32_8:
items = 3;
break;
case PCI_DEVICE_ID_RME_DIGI32_PRO:
items = 4;
break;
default:
snd_BUG();
break;
}
if (ucontrol->value.enumerated.item[0] >= items) {
ucontrol->value.enumerated.item[0] = items - 1;
}
spin_unlock_irq(&rme32->lock);
return 0;
}
static int
snd_rme32_put_inputtype_control(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct rme32 *rme32 = snd_kcontrol_chip(kcontrol);
unsigned int val;
int change, items = 3;
switch (rme32->pci->device) {
case PCI_DEVICE_ID_RME_DIGI32:
case PCI_DEVICE_ID_RME_DIGI32_8:
items = 3;
break;
case PCI_DEVICE_ID_RME_DIGI32_PRO:
items = 4;
break;
default:
snd_BUG();
break;
}
val = ucontrol->value.enumerated.item[0] % items;
spin_lock_irq(&rme32->lock);
change = val != (unsigned int)snd_rme32_getinputtype(rme32);
snd_rme32_setinputtype(rme32, val);
spin_unlock_irq(&rme32->lock);
return change;
}
static int
snd_rme32_info_clockmode_control(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static char *texts[4] = { "AutoSync",
"Internal 32.0kHz",
"Internal 44.1kHz",
"Internal 48.0kHz" };
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = 4;
if (uinfo->value.enumerated.item > 3) {
uinfo->value.enumerated.item = 3;
}
strcpy(uinfo->value.enumerated.name,
texts[uinfo->value.enumerated.item]);
return 0;
}
static int
snd_rme32_get_clockmode_control(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct rme32 *rme32 = snd_kcontrol_chip(kcontrol);
spin_lock_irq(&rme32->lock);
ucontrol->value.enumerated.item[0] = snd_rme32_getclockmode(rme32);
spin_unlock_irq(&rme32->lock);
return 0;
}
static int
snd_rme32_put_clockmode_control(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct rme32 *rme32 = snd_kcontrol_chip(kcontrol);
unsigned int val;
int change;
val = ucontrol->value.enumerated.item[0] % 3;
spin_lock_irq(&rme32->lock);
change = val != (unsigned int)snd_rme32_getclockmode(rme32);
snd_rme32_setclockmode(rme32, val);
spin_unlock_irq(&rme32->lock);
return change;
}
static u32 snd_rme32_convert_from_aes(struct snd_aes_iec958 * aes)
{
u32 val = 0;
val |= (aes->status[0] & IEC958_AES0_PROFESSIONAL) ? RME32_WCR_PRO : 0;
if (val & RME32_WCR_PRO)
val |= (aes->status[0] & IEC958_AES0_PRO_EMPHASIS_5015) ? RME32_WCR_EMP : 0;
else
val |= (aes->status[0] & IEC958_AES0_CON_EMPHASIS_5015) ? RME32_WCR_EMP : 0;
return val;
}
static void snd_rme32_convert_to_aes(struct snd_aes_iec958 * aes, u32 val)
{
aes->status[0] = ((val & RME32_WCR_PRO) ? IEC958_AES0_PROFESSIONAL : 0);
if (val & RME32_WCR_PRO)
aes->status[0] |= (val & RME32_WCR_EMP) ? IEC958_AES0_PRO_EMPHASIS_5015 : 0;
else
aes->status[0] |= (val & RME32_WCR_EMP) ? IEC958_AES0_CON_EMPHASIS_5015 : 0;
}
static int snd_rme32_control_spdif_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_IEC958;
uinfo->count = 1;
return 0;
}
static int snd_rme32_control_spdif_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct rme32 *rme32 = snd_kcontrol_chip(kcontrol);
snd_rme32_convert_to_aes(&ucontrol->value.iec958,
rme32->wcreg_spdif);
return 0;
}
static int snd_rme32_control_spdif_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct rme32 *rme32 = snd_kcontrol_chip(kcontrol);
int change;
u32 val;
val = snd_rme32_convert_from_aes(&ucontrol->value.iec958);
spin_lock_irq(&rme32->lock);
change = val != rme32->wcreg_spdif;
rme32->wcreg_spdif = val;
spin_unlock_irq(&rme32->lock);
return change;
}
static int snd_rme32_control_spdif_stream_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_IEC958;
uinfo->count = 1;
return 0;
}
static int snd_rme32_control_spdif_stream_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *
ucontrol)
{
struct rme32 *rme32 = snd_kcontrol_chip(kcontrol);
snd_rme32_convert_to_aes(&ucontrol->value.iec958,
rme32->wcreg_spdif_stream);
return 0;
}
static int snd_rme32_control_spdif_stream_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *
ucontrol)
{
struct rme32 *rme32 = snd_kcontrol_chip(kcontrol);
int change;
u32 val;
val = snd_rme32_convert_from_aes(&ucontrol->value.iec958);
spin_lock_irq(&rme32->lock);
change = val != rme32->wcreg_spdif_stream;
rme32->wcreg_spdif_stream = val;
rme32->wcreg &= ~(RME32_WCR_PRO | RME32_WCR_EMP);
rme32->wcreg |= val;
writel(rme32->wcreg, rme32->iobase + RME32_IO_CONTROL_REGISTER);
spin_unlock_irq(&rme32->lock);
return change;
}
static int snd_rme32_control_spdif_mask_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_IEC958;
uinfo->count = 1;
return 0;
}
static int snd_rme32_control_spdif_mask_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *
ucontrol)
{
ucontrol->value.iec958.status[0] = kcontrol->private_value;
return 0;
}
static int snd_rme32_create_switches(struct snd_card *card, struct rme32 * rme32)
{
int idx, err;
struct snd_kcontrol *kctl;
for (idx = 0; idx < (int)ARRAY_SIZE(snd_rme32_controls); idx++) {
if ((err = snd_ctl_add(card, kctl = snd_ctl_new1(&snd_rme32_controls[idx], rme32))) < 0)
return err;
if (idx == 1)
rme32->spdif_ctl = kctl;
}
return 0;
}
static void snd_rme32_card_free(struct snd_card *card)
{
snd_rme32_free(card->private_data);
}
static int
snd_rme32_probe(struct pci_dev *pci, const struct pci_device_id *pci_id)
{
static int dev;
struct rme32 *rme32;
struct snd_card *card;
int err;
if (dev >= SNDRV_CARDS) {
return -ENODEV;
}
if (!enable[dev]) {
dev++;
return -ENOENT;
}
err = snd_card_create(index[dev], id[dev], THIS_MODULE,
sizeof(struct rme32), &card);
if (err < 0)
return err;
card->private_free = snd_rme32_card_free;
rme32 = (struct rme32 *) card->private_data;
rme32->card = card;
rme32->pci = pci;
snd_card_set_dev(card, &pci->dev);
if (fullduplex[dev])
rme32->fullduplex_mode = 1;
if ((err = snd_rme32_create(rme32)) < 0) {
snd_card_free(card);
return err;
}
strcpy(card->driver, "Digi32");
switch (rme32->pci->device) {
case PCI_DEVICE_ID_RME_DIGI32:
strcpy(card->shortname, "RME Digi32");
break;
case PCI_DEVICE_ID_RME_DIGI32_8:
strcpy(card->shortname, "RME Digi32/8");
break;
case PCI_DEVICE_ID_RME_DIGI32_PRO:
strcpy(card->shortname, "RME Digi32 PRO");
break;
}
sprintf(card->longname, "%s (Rev. %d) at 0x%lx, irq %d",
card->shortname, rme32->rev, rme32->port, rme32->irq);
if ((err = snd_card_register(card)) < 0) {
snd_card_free(card);
return err;
}
pci_set_drvdata(pci, card);
dev++;
return 0;
}
static void snd_rme32_remove(struct pci_dev *pci)
{
snd_card_free(pci_get_drvdata(pci));
pci_set_drvdata(pci, NULL);
}
