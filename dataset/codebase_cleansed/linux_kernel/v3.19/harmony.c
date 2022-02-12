static inline unsigned long
harmony_read(struct snd_harmony *h, unsigned r)
{
return __raw_readl(h->iobase + r);
}
static inline void
harmony_write(struct snd_harmony *h, unsigned r, unsigned long v)
{
__raw_writel(v, h->iobase + r);
}
static inline void
harmony_wait_for_control(struct snd_harmony *h)
{
while (harmony_read(h, HARMONY_CNTL) & HARMONY_CNTL_C) ;
}
static inline void
harmony_reset(struct snd_harmony *h)
{
harmony_write(h, HARMONY_RESET, 1);
mdelay(50);
harmony_write(h, HARMONY_RESET, 0);
}
static void
harmony_disable_interrupts(struct snd_harmony *h)
{
u32 dstatus;
harmony_wait_for_control(h);
dstatus = harmony_read(h, HARMONY_DSTATUS);
dstatus &= ~HARMONY_DSTATUS_IE;
harmony_write(h, HARMONY_DSTATUS, dstatus);
}
static void
harmony_enable_interrupts(struct snd_harmony *h)
{
u32 dstatus;
harmony_wait_for_control(h);
dstatus = harmony_read(h, HARMONY_DSTATUS);
dstatus |= HARMONY_DSTATUS_IE;
harmony_write(h, HARMONY_DSTATUS, dstatus);
}
static void
harmony_mute(struct snd_harmony *h)
{
unsigned long flags;
spin_lock_irqsave(&h->mixer_lock, flags);
harmony_wait_for_control(h);
harmony_write(h, HARMONY_GAINCTL, HARMONY_GAIN_SILENCE);
spin_unlock_irqrestore(&h->mixer_lock, flags);
}
static void
harmony_unmute(struct snd_harmony *h)
{
unsigned long flags;
spin_lock_irqsave(&h->mixer_lock, flags);
harmony_wait_for_control(h);
harmony_write(h, HARMONY_GAINCTL, h->st.gain);
spin_unlock_irqrestore(&h->mixer_lock, flags);
}
static void
harmony_set_control(struct snd_harmony *h)
{
u32 ctrl;
unsigned long flags;
spin_lock_irqsave(&h->lock, flags);
ctrl = (HARMONY_CNTL_C |
(h->st.format << 6) |
(h->st.stereo << 5) |
(h->st.rate));
harmony_wait_for_control(h);
harmony_write(h, HARMONY_CNTL, ctrl);
spin_unlock_irqrestore(&h->lock, flags);
}
static irqreturn_t
snd_harmony_interrupt(int irq, void *dev)
{
u32 dstatus;
struct snd_harmony *h = dev;
spin_lock(&h->lock);
harmony_disable_interrupts(h);
harmony_wait_for_control(h);
dstatus = harmony_read(h, HARMONY_DSTATUS);
spin_unlock(&h->lock);
if (dstatus & HARMONY_DSTATUS_PN) {
if (h->psubs && h->st.playing) {
spin_lock(&h->lock);
h->pbuf.buf += h->pbuf.count;
h->pbuf.buf %= h->pbuf.size;
harmony_write(h, HARMONY_PNXTADD,
h->pbuf.addr + h->pbuf.buf);
h->stats.play_intr++;
spin_unlock(&h->lock);
snd_pcm_period_elapsed(h->psubs);
} else {
spin_lock(&h->lock);
harmony_write(h, HARMONY_PNXTADD, h->sdma.addr);
h->stats.silence_intr++;
spin_unlock(&h->lock);
}
}
if (dstatus & HARMONY_DSTATUS_RN) {
if (h->csubs && h->st.capturing) {
spin_lock(&h->lock);
h->cbuf.buf += h->cbuf.count;
h->cbuf.buf %= h->cbuf.size;
harmony_write(h, HARMONY_RNXTADD,
h->cbuf.addr + h->cbuf.buf);
h->stats.rec_intr++;
spin_unlock(&h->lock);
snd_pcm_period_elapsed(h->csubs);
} else {
spin_lock(&h->lock);
harmony_write(h, HARMONY_RNXTADD, h->gdma.addr);
h->stats.graveyard_intr++;
spin_unlock(&h->lock);
}
}
spin_lock(&h->lock);
harmony_enable_interrupts(h);
spin_unlock(&h->lock);
return IRQ_HANDLED;
}
static unsigned int
snd_harmony_rate_bits(int rate)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(snd_harmony_rates); i++)
if (snd_harmony_rates[i] == rate)
return rate_bits[i];
return HARMONY_SR_44KHZ;
}
static int
snd_harmony_playback_trigger(struct snd_pcm_substream *ss, int cmd)
{
struct snd_harmony *h = snd_pcm_substream_chip(ss);
if (h->st.capturing)
return -EBUSY;
spin_lock(&h->lock);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
h->st.playing = 1;
harmony_write(h, HARMONY_PNXTADD, h->pbuf.addr);
harmony_write(h, HARMONY_RNXTADD, h->gdma.addr);
harmony_unmute(h);
harmony_enable_interrupts(h);
break;
case SNDRV_PCM_TRIGGER_STOP:
h->st.playing = 0;
harmony_mute(h);
harmony_write(h, HARMONY_PNXTADD, h->sdma.addr);
harmony_disable_interrupts(h);
break;
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
case SNDRV_PCM_TRIGGER_SUSPEND:
default:
spin_unlock(&h->lock);
snd_BUG();
return -EINVAL;
}
spin_unlock(&h->lock);
return 0;
}
static int
snd_harmony_capture_trigger(struct snd_pcm_substream *ss, int cmd)
{
struct snd_harmony *h = snd_pcm_substream_chip(ss);
if (h->st.playing)
return -EBUSY;
spin_lock(&h->lock);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
h->st.capturing = 1;
harmony_write(h, HARMONY_PNXTADD, h->sdma.addr);
harmony_write(h, HARMONY_RNXTADD, h->cbuf.addr);
harmony_unmute(h);
harmony_enable_interrupts(h);
break;
case SNDRV_PCM_TRIGGER_STOP:
h->st.capturing = 0;
harmony_mute(h);
harmony_write(h, HARMONY_RNXTADD, h->gdma.addr);
harmony_disable_interrupts(h);
break;
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
case SNDRV_PCM_TRIGGER_SUSPEND:
default:
spin_unlock(&h->lock);
snd_BUG();
return -EINVAL;
}
spin_unlock(&h->lock);
return 0;
}
static int
snd_harmony_set_data_format(struct snd_harmony *h, int fmt, int force)
{
int o = h->st.format;
int n;
switch(fmt) {
case SNDRV_PCM_FORMAT_S16_BE:
n = HARMONY_DF_16BIT_LINEAR;
break;
case SNDRV_PCM_FORMAT_A_LAW:
n = HARMONY_DF_8BIT_ALAW;
break;
case SNDRV_PCM_FORMAT_MU_LAW:
n = HARMONY_DF_8BIT_ULAW;
break;
default:
n = HARMONY_DF_16BIT_LINEAR;
break;
}
if (force || o != n) {
snd_pcm_format_set_silence(fmt, h->sdma.area, SILENCE_BUFSZ /
(snd_pcm_format_physical_width(fmt)
/ 8));
}
return n;
}
static int
snd_harmony_playback_prepare(struct snd_pcm_substream *ss)
{
struct snd_harmony *h = snd_pcm_substream_chip(ss);
struct snd_pcm_runtime *rt = ss->runtime;
if (h->st.capturing)
return -EBUSY;
h->pbuf.size = snd_pcm_lib_buffer_bytes(ss);
h->pbuf.count = snd_pcm_lib_period_bytes(ss);
if (h->pbuf.buf >= h->pbuf.size)
h->pbuf.buf = 0;
h->st.playing = 0;
h->st.rate = snd_harmony_rate_bits(rt->rate);
h->st.format = snd_harmony_set_data_format(h, rt->format, 0);
if (rt->channels == 2)
h->st.stereo = HARMONY_SS_STEREO;
else
h->st.stereo = HARMONY_SS_MONO;
harmony_set_control(h);
h->pbuf.addr = rt->dma_addr;
return 0;
}
static int
snd_harmony_capture_prepare(struct snd_pcm_substream *ss)
{
struct snd_harmony *h = snd_pcm_substream_chip(ss);
struct snd_pcm_runtime *rt = ss->runtime;
if (h->st.playing)
return -EBUSY;
h->cbuf.size = snd_pcm_lib_buffer_bytes(ss);
h->cbuf.count = snd_pcm_lib_period_bytes(ss);
if (h->cbuf.buf >= h->cbuf.size)
h->cbuf.buf = 0;
h->st.capturing = 0;
h->st.rate = snd_harmony_rate_bits(rt->rate);
h->st.format = snd_harmony_set_data_format(h, rt->format, 0);
if (rt->channels == 2)
h->st.stereo = HARMONY_SS_STEREO;
else
h->st.stereo = HARMONY_SS_MONO;
harmony_set_control(h);
h->cbuf.addr = rt->dma_addr;
return 0;
}
static snd_pcm_uframes_t
snd_harmony_playback_pointer(struct snd_pcm_substream *ss)
{
struct snd_pcm_runtime *rt = ss->runtime;
struct snd_harmony *h = snd_pcm_substream_chip(ss);
unsigned long pcuradd;
unsigned long played;
if (!(h->st.playing) || (h->psubs == NULL))
return 0;
if ((h->pbuf.addr == 0) || (h->pbuf.size == 0))
return 0;
pcuradd = harmony_read(h, HARMONY_PCURADD);
played = pcuradd - h->pbuf.addr;
#ifdef HARMONY_DEBUG
printk(KERN_DEBUG PFX "playback_pointer is 0x%lx-0x%lx = %d bytes\n",
pcuradd, h->pbuf.addr, played);
#endif
if (pcuradd > h->pbuf.addr + h->pbuf.size) {
return 0;
}
return bytes_to_frames(rt, played);
}
static snd_pcm_uframes_t
snd_harmony_capture_pointer(struct snd_pcm_substream *ss)
{
struct snd_pcm_runtime *rt = ss->runtime;
struct snd_harmony *h = snd_pcm_substream_chip(ss);
unsigned long rcuradd;
unsigned long caught;
if (!(h->st.capturing) || (h->csubs == NULL))
return 0;
if ((h->cbuf.addr == 0) || (h->cbuf.size == 0))
return 0;
rcuradd = harmony_read(h, HARMONY_RCURADD);
caught = rcuradd - h->cbuf.addr;
#ifdef HARMONY_DEBUG
printk(KERN_DEBUG PFX "capture_pointer is 0x%lx-0x%lx = %d bytes\n",
rcuradd, h->cbuf.addr, caught);
#endif
if (rcuradd > h->cbuf.addr + h->cbuf.size) {
return 0;
}
return bytes_to_frames(rt, caught);
}
static int
snd_harmony_playback_open(struct snd_pcm_substream *ss)
{
struct snd_harmony *h = snd_pcm_substream_chip(ss);
struct snd_pcm_runtime *rt = ss->runtime;
int err;
h->psubs = ss;
rt->hw = snd_harmony_playback;
snd_pcm_hw_constraint_list(rt, 0, SNDRV_PCM_HW_PARAM_RATE,
&hw_constraint_rates);
err = snd_pcm_hw_constraint_integer(rt, SNDRV_PCM_HW_PARAM_PERIODS);
if (err < 0)
return err;
return 0;
}
static int
snd_harmony_capture_open(struct snd_pcm_substream *ss)
{
struct snd_harmony *h = snd_pcm_substream_chip(ss);
struct snd_pcm_runtime *rt = ss->runtime;
int err;
h->csubs = ss;
rt->hw = snd_harmony_capture;
snd_pcm_hw_constraint_list(rt, 0, SNDRV_PCM_HW_PARAM_RATE,
&hw_constraint_rates);
err = snd_pcm_hw_constraint_integer(rt, SNDRV_PCM_HW_PARAM_PERIODS);
if (err < 0)
return err;
return 0;
}
static int
snd_harmony_playback_close(struct snd_pcm_substream *ss)
{
struct snd_harmony *h = snd_pcm_substream_chip(ss);
h->psubs = NULL;
return 0;
}
static int
snd_harmony_capture_close(struct snd_pcm_substream *ss)
{
struct snd_harmony *h = snd_pcm_substream_chip(ss);
h->csubs = NULL;
return 0;
}
static int
snd_harmony_hw_params(struct snd_pcm_substream *ss,
struct snd_pcm_hw_params *hw)
{
int err;
struct snd_harmony *h = snd_pcm_substream_chip(ss);
err = snd_pcm_lib_malloc_pages(ss, params_buffer_bytes(hw));
if (err > 0 && h->dma.type == SNDRV_DMA_TYPE_CONTINUOUS)
ss->runtime->dma_addr = __pa(ss->runtime->dma_area);
return err;
}
static int
snd_harmony_hw_free(struct snd_pcm_substream *ss)
{
return snd_pcm_lib_free_pages(ss);
}
static int
snd_harmony_pcm_init(struct snd_harmony *h)
{
struct snd_pcm *pcm;
int err;
if (snd_BUG_ON(!h))
return -EINVAL;
harmony_disable_interrupts(h);
err = snd_pcm_new(h->card, "harmony", 0, 1, 1, &pcm);
if (err < 0)
return err;
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK,
&snd_harmony_playback_ops);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE,
&snd_harmony_capture_ops);
pcm->private_data = h;
pcm->info_flags = 0;
strcpy(pcm->name, "harmony");
h->pcm = pcm;
h->psubs = NULL;
h->csubs = NULL;
h->dma.type = SNDRV_DMA_TYPE_DEV;
h->dma.dev = &h->dev->dev;
err = snd_dma_alloc_pages(h->dma.type,
h->dma.dev,
BUF_SIZE*GRAVEYARD_BUFS,
&h->gdma);
if (err < 0) {
printk(KERN_ERR PFX "cannot allocate graveyard buffer!\n");
return err;
}
err = snd_dma_alloc_pages(h->dma.type,
h->dma.dev,
BUF_SIZE*SILENCE_BUFS,
&h->sdma);
if (err < 0) {
printk(KERN_ERR PFX "cannot allocate silence buffer!\n");
return err;
}
err = snd_pcm_lib_preallocate_pages_for_all(pcm, h->dma.type,
h->dma.dev,
MAX_BUF_SIZE,
MAX_BUF_SIZE);
if (err < 0) {
printk(KERN_ERR PFX "buffer allocation error: %d\n", err);
return err;
}
h->st.format = snd_harmony_set_data_format(h,
SNDRV_PCM_FORMAT_S16_BE, 1);
return 0;
}
static void
snd_harmony_set_new_gain(struct snd_harmony *h)
{
harmony_wait_for_control(h);
harmony_write(h, HARMONY_GAINCTL, h->st.gain);
}
static int
snd_harmony_mixercontrol_info(struct snd_kcontrol *kc,
struct snd_ctl_elem_info *uinfo)
{
int mask = (kc->private_value >> 16) & 0xff;
int left_shift = (kc->private_value) & 0xff;
int right_shift = (kc->private_value >> 8) & 0xff;
uinfo->type = mask == 1 ? SNDRV_CTL_ELEM_TYPE_BOOLEAN :
SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = left_shift == right_shift ? 1 : 2;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = mask;
return 0;
}
static int
snd_harmony_volume_get(struct snd_kcontrol *kc,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_harmony *h = snd_kcontrol_chip(kc);
int shift_left = (kc->private_value) & 0xff;
int shift_right = (kc->private_value >> 8) & 0xff;
int mask = (kc->private_value >> 16) & 0xff;
int invert = (kc->private_value >> 24) & 0xff;
int left, right;
spin_lock_irq(&h->mixer_lock);
left = (h->st.gain >> shift_left) & mask;
right = (h->st.gain >> shift_right) & mask;
if (invert) {
left = mask - left;
right = mask - right;
}
ucontrol->value.integer.value[0] = left;
if (shift_left != shift_right)
ucontrol->value.integer.value[1] = right;
spin_unlock_irq(&h->mixer_lock);
return 0;
}
static int
snd_harmony_volume_put(struct snd_kcontrol *kc,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_harmony *h = snd_kcontrol_chip(kc);
int shift_left = (kc->private_value) & 0xff;
int shift_right = (kc->private_value >> 8) & 0xff;
int mask = (kc->private_value >> 16) & 0xff;
int invert = (kc->private_value >> 24) & 0xff;
int left, right;
int old_gain = h->st.gain;
spin_lock_irq(&h->mixer_lock);
left = ucontrol->value.integer.value[0] & mask;
if (invert)
left = mask - left;
h->st.gain &= ~( (mask << shift_left ) );
h->st.gain |= (left << shift_left);
if (shift_left != shift_right) {
right = ucontrol->value.integer.value[1] & mask;
if (invert)
right = mask - right;
h->st.gain &= ~( (mask << shift_right) );
h->st.gain |= (right << shift_right);
}
snd_harmony_set_new_gain(h);
spin_unlock_irq(&h->mixer_lock);
return h->st.gain != old_gain;
}
static int
snd_harmony_captureroute_info(struct snd_kcontrol *kc,
struct snd_ctl_elem_info *uinfo)
{
static const char * const texts[2] = { "Line", "Mic" };
return snd_ctl_enum_info(uinfo, 1, 2, texts);
}
static int
snd_harmony_captureroute_get(struct snd_kcontrol *kc,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_harmony *h = snd_kcontrol_chip(kc);
int value;
spin_lock_irq(&h->mixer_lock);
value = (h->st.gain >> HARMONY_GAIN_IS_SHIFT) & 1;
ucontrol->value.enumerated.item[0] = value;
spin_unlock_irq(&h->mixer_lock);
return 0;
}
static int
snd_harmony_captureroute_put(struct snd_kcontrol *kc,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_harmony *h = snd_kcontrol_chip(kc);
int value;
int old_gain = h->st.gain;
spin_lock_irq(&h->mixer_lock);
value = ucontrol->value.enumerated.item[0] & 1;
h->st.gain &= ~HARMONY_GAIN_IS_MASK;
h->st.gain |= value << HARMONY_GAIN_IS_SHIFT;
snd_harmony_set_new_gain(h);
spin_unlock_irq(&h->mixer_lock);
return h->st.gain != old_gain;
}
static void
snd_harmony_mixer_reset(struct snd_harmony *h)
{
harmony_mute(h);
harmony_reset(h);
h->st.gain = HARMONY_GAIN_DEFAULT;
harmony_unmute(h);
}
static int
snd_harmony_mixer_init(struct snd_harmony *h)
{
struct snd_card *card;
int idx, err;
if (snd_BUG_ON(!h))
return -EINVAL;
card = h->card;
strcpy(card->mixername, "Harmony Gain control interface");
for (idx = 0; idx < HARMONY_CONTROLS; idx++) {
err = snd_ctl_add(card,
snd_ctl_new1(&snd_harmony_controls[idx], h));
if (err < 0)
return err;
}
snd_harmony_mixer_reset(h);
return 0;
}
static int
snd_harmony_free(struct snd_harmony *h)
{
if (h->gdma.addr)
snd_dma_free_pages(&h->gdma);
if (h->sdma.addr)
snd_dma_free_pages(&h->sdma);
if (h->irq >= 0)
free_irq(h->irq, h);
if (h->iobase)
iounmap(h->iobase);
kfree(h);
return 0;
}
static int
snd_harmony_dev_free(struct snd_device *dev)
{
struct snd_harmony *h = dev->device_data;
return snd_harmony_free(h);
}
static int
snd_harmony_create(struct snd_card *card,
struct parisc_device *padev,
struct snd_harmony **rchip)
{
int err;
struct snd_harmony *h;
static struct snd_device_ops ops = {
.dev_free = snd_harmony_dev_free,
};
*rchip = NULL;
h = kzalloc(sizeof(*h), GFP_KERNEL);
if (h == NULL)
return -ENOMEM;
h->hpa = padev->hpa.start;
h->card = card;
h->dev = padev;
h->irq = -1;
h->iobase = ioremap_nocache(padev->hpa.start, HARMONY_SIZE);
if (h->iobase == NULL) {
printk(KERN_ERR PFX "unable to remap hpa 0x%lx\n",
(unsigned long)padev->hpa.start);
err = -EBUSY;
goto free_and_ret;
}
err = request_irq(padev->irq, snd_harmony_interrupt, 0,
"harmony", h);
if (err) {
printk(KERN_ERR PFX "could not obtain interrupt %d",
padev->irq);
goto free_and_ret;
}
h->irq = padev->irq;
spin_lock_init(&h->mixer_lock);
spin_lock_init(&h->lock);
if ((err = snd_device_new(card, SNDRV_DEV_LOWLEVEL,
h, &ops)) < 0) {
goto free_and_ret;
}
*rchip = h;
return 0;
free_and_ret:
snd_harmony_free(h);
return err;
}
static int
snd_harmony_probe(struct parisc_device *padev)
{
int err;
struct snd_card *card;
struct snd_harmony *h;
err = snd_card_new(&padev->dev, index, id, THIS_MODULE, 0, &card);
if (err < 0)
return err;
err = snd_harmony_create(card, padev, &h);
if (err < 0)
goto free_and_ret;
err = snd_harmony_pcm_init(h);
if (err < 0)
goto free_and_ret;
err = snd_harmony_mixer_init(h);
if (err < 0)
goto free_and_ret;
strcpy(card->driver, "harmony");
strcpy(card->shortname, "Harmony");
sprintf(card->longname, "%s at 0x%lx, irq %i",
card->shortname, h->hpa, h->irq);
err = snd_card_register(card);
if (err < 0)
goto free_and_ret;
parisc_set_drvdata(padev, card);
return 0;
free_and_ret:
snd_card_free(card);
return err;
}
static int
snd_harmony_remove(struct parisc_device *padev)
{
snd_card_free(parisc_get_drvdata(padev));
return 0;
}
static int __init
alsa_harmony_init(void)
{
return register_parisc_driver(&snd_harmony_driver);
}
static void __exit
alsa_harmony_fini(void)
{
unregister_parisc_driver(&snd_harmony_driver);
}
