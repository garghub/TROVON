static void solo_g723_config(struct solo_dev *solo_dev)
{
int clk_div;
clk_div = SOLO_CLOCK_MHZ / (SAMPLERATE * (BITRATE * 2) * 2);
solo_reg_write(solo_dev, SOLO_AUDIO_SAMPLE,
SOLO_AUDIO_BITRATE(BITRATE) |
SOLO_AUDIO_CLK_DIV(clk_div));
solo_reg_write(solo_dev, SOLO_AUDIO_FDMA_INTR,
SOLO_AUDIO_FDMA_INTERVAL(IRQ_PAGES) |
SOLO_AUDIO_INTR_ORDER(G723_INTR_ORDER) |
SOLO_AUDIO_FDMA_BASE(SOLO_G723_EXT_ADDR(solo_dev) >> 16));
solo_reg_write(solo_dev, SOLO_AUDIO_CONTROL,
SOLO_AUDIO_ENABLE | SOLO_AUDIO_I2S_MODE |
SOLO_AUDIO_I2S_MULTI(3) | SOLO_AUDIO_MODE(OUTMODE_MASK));
}
void solo_g723_isr(struct solo_dev *solo_dev)
{
struct snd_pcm_str *pstr =
&solo_dev->snd_pcm->streams[SNDRV_PCM_STREAM_CAPTURE];
struct snd_pcm_substream *ss;
struct solo_snd_pcm *solo_pcm;
solo_reg_write(solo_dev, SOLO_IRQ_STAT, SOLO_IRQ_G723);
for (ss = pstr->substream; ss != NULL; ss = ss->next) {
if (snd_pcm_substream_chip(ss) == NULL)
continue;
if (snd_pcm_substream_chip(ss) == solo_dev)
continue;
solo_pcm = snd_pcm_substream_chip(ss);
if (!solo_pcm->on)
continue;
snd_pcm_period_elapsed(ss);
}
}
static int snd_solo_hw_params(struct snd_pcm_substream *ss,
struct snd_pcm_hw_params *hw_params)
{
return snd_pcm_lib_malloc_pages(ss, params_buffer_bytes(hw_params));
}
static int snd_solo_hw_free(struct snd_pcm_substream *ss)
{
return snd_pcm_lib_free_pages(ss);
}
static int snd_solo_pcm_open(struct snd_pcm_substream *ss)
{
struct solo_dev *solo_dev = snd_pcm_substream_chip(ss);
struct solo_snd_pcm *solo_pcm;
solo_pcm = kzalloc(sizeof(*solo_pcm), GFP_KERNEL);
if (solo_pcm == NULL)
return -ENOMEM;
spin_lock_init(&solo_pcm->lock);
solo_pcm->solo_dev = solo_dev;
ss->runtime->hw = snd_solo_pcm_hw;
snd_pcm_substream_chip(ss) = solo_pcm;
return 0;
}
static int snd_solo_pcm_close(struct snd_pcm_substream *ss)
{
struct solo_snd_pcm *solo_pcm = snd_pcm_substream_chip(ss);
snd_pcm_substream_chip(ss) = solo_pcm->solo_dev;
kfree(solo_pcm);
return 0;
}
static int snd_solo_pcm_trigger(struct snd_pcm_substream *ss, int cmd)
{
struct solo_snd_pcm *solo_pcm = snd_pcm_substream_chip(ss);
struct solo_dev *solo_dev = solo_pcm->solo_dev;
int ret = 0;
spin_lock(&solo_pcm->lock);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
if (solo_pcm->on == 0) {
if (atomic_inc_return(&solo_dev->snd_users) == 1)
solo_irq_on(solo_dev, SOLO_IRQ_G723);
solo_pcm->on = 1;
}
break;
case SNDRV_PCM_TRIGGER_STOP:
if (solo_pcm->on) {
if (atomic_dec_return(&solo_dev->snd_users) == 0)
solo_irq_off(solo_dev, SOLO_IRQ_G723);
solo_pcm->on = 0;
}
break;
default:
ret = -EINVAL;
}
spin_unlock(&solo_pcm->lock);
return ret;
}
static int snd_solo_pcm_prepare(struct snd_pcm_substream *ss)
{
return 0;
}
static snd_pcm_uframes_t snd_solo_pcm_pointer(struct snd_pcm_substream *ss)
{
struct solo_snd_pcm *solo_pcm = snd_pcm_substream_chip(ss);
struct solo_dev *solo_dev = solo_pcm->solo_dev;
snd_pcm_uframes_t idx = solo_reg_read(solo_dev, SOLO_AUDIO_STA) & 0x1f;
return idx * G723_FRAMES_PER_PAGE;
}
static int snd_solo_pcm_copy(struct snd_pcm_substream *ss, int channel,
snd_pcm_uframes_t pos, void __user *dst,
snd_pcm_uframes_t count)
{
struct solo_snd_pcm *solo_pcm = snd_pcm_substream_chip(ss);
struct solo_dev *solo_dev = solo_pcm->solo_dev;
int err, i;
for (i = 0; i < (count / G723_FRAMES_PER_PAGE); i++) {
int page = (pos / G723_FRAMES_PER_PAGE) + i;
err = solo_p2m_dma(solo_dev, SOLO_P2M_DMA_ID_G723E, 0,
solo_pcm->g723_buf,
SOLO_G723_EXT_ADDR(solo_dev) +
(page * G723_PERIOD_BLOCK) +
(ss->number * G723_PERIOD_BYTES),
G723_PERIOD_BYTES);
if (err)
return err;
err = copy_to_user(dst + (i * G723_PERIOD_BYTES),
solo_pcm->g723_buf, G723_PERIOD_BYTES);
if (err)
return -EFAULT;
}
return 0;
}
static int snd_solo_capture_volume_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *info)
{
info->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
info->count = 1;
info->value.integer.min = 0;
info->value.integer.max = 15;
info->value.integer.step = 1;
return 0;
}
static int snd_solo_capture_volume_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *value)
{
struct solo_dev *solo_dev = snd_kcontrol_chip(kcontrol);
u8 ch = value->id.numid - 1;
value->value.integer.value[0] = tw28_get_audio_gain(solo_dev, ch);
return 0;
}
static int snd_solo_capture_volume_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *value)
{
struct solo_dev *solo_dev = snd_kcontrol_chip(kcontrol);
u8 ch = value->id.numid - 1;
u8 old_val;
old_val = tw28_get_audio_gain(solo_dev, ch);
if (old_val == value->value.integer.value[0])
return 0;
tw28_set_audio_gain(solo_dev, ch, value->value.integer.value[0]);
return 1;
}
static int solo_snd_pcm_init(struct solo_dev *solo_dev)
{
struct snd_card *card = solo_dev->snd_card;
struct snd_pcm *pcm;
struct snd_pcm_substream *ss;
int ret;
int i;
ret = snd_pcm_new(card, card->driver, 0, 0, solo_dev->nr_chans,
&pcm);
if (ret < 0)
return ret;
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE,
&snd_solo_pcm_ops);
snd_pcm_chip(pcm) = solo_dev;
pcm->info_flags = 0;
strcpy(pcm->name, card->shortname);
for (i = 0, ss = pcm->streams[SNDRV_PCM_STREAM_CAPTURE].substream;
ss; ss = ss->next, i++)
sprintf(ss->name, "Camera #%d Audio", i);
ret = snd_pcm_lib_preallocate_pages_for_all(pcm,
SNDRV_DMA_TYPE_CONTINUOUS,
snd_dma_continuous_data(GFP_KERNEL),
MAX_BUFFER, MAX_BUFFER);
if (ret < 0)
return ret;
solo_dev->snd_pcm = pcm;
return 0;
}
int solo_g723_init(struct solo_dev *solo_dev)
{
static struct snd_device_ops ops = { NULL };
struct snd_card *card;
struct snd_kcontrol_new kctl;
char name[32];
int ret;
atomic_set(&solo_dev->snd_users, 0);
sprintf(name, "Softlogic%d", solo_dev->vfd->num);
ret = snd_card_create(SNDRV_DEFAULT_IDX1, name, THIS_MODULE, 0,
&solo_dev->snd_card);
if (ret < 0)
return ret;
card = solo_dev->snd_card;
strcpy(card->driver, SOLO6X10_NAME);
strcpy(card->shortname, "SOLO-6x10 Audio");
sprintf(card->longname, "%s on %s IRQ %d", card->shortname,
pci_name(solo_dev->pdev), solo_dev->pdev->irq);
snd_card_set_dev(card, &solo_dev->pdev->dev);
ret = snd_device_new(card, SNDRV_DEV_LOWLEVEL, solo_dev, &ops);
if (ret < 0)
goto snd_error;
strcpy(card->mixername, "SOLO-6x10");
kctl = snd_solo_capture_volume;
kctl.count = solo_dev->nr_chans;
ret = snd_ctl_add(card, snd_ctl_new1(&kctl, solo_dev));
if (ret < 0)
return ret;
ret = solo_snd_pcm_init(solo_dev);
if (ret < 0)
goto snd_error;
ret = snd_card_register(card);
if (ret < 0)
goto snd_error;
solo_g723_config(solo_dev);
dev_info(&solo_dev->pdev->dev, "Alsa sound card as %s\n", name);
return 0;
snd_error:
snd_card_free(card);
return ret;
}
void solo_g723_exit(struct solo_dev *solo_dev)
{
solo_reg_write(solo_dev, SOLO_AUDIO_CONTROL, 0);
solo_irq_off(solo_dev, SOLO_IRQ_G723);
snd_card_free(solo_dev->snd_card);
}
