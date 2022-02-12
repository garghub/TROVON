static __inline__ void amd7930_idle(struct snd_amd7930 *amd)
{
unsigned long flags;
spin_lock_irqsave(&amd->lock, flags);
sbus_writeb(AMR_INIT, amd->regs + AMD7930_CR);
sbus_writeb(0, amd->regs + AMD7930_DR);
spin_unlock_irqrestore(&amd->lock, flags);
}
static __inline__ void amd7930_enable_ints(struct snd_amd7930 *amd)
{
unsigned long flags;
spin_lock_irqsave(&amd->lock, flags);
sbus_writeb(AMR_INIT, amd->regs + AMD7930_CR);
sbus_writeb(AM_INIT_ACTIVE, amd->regs + AMD7930_DR);
spin_unlock_irqrestore(&amd->lock, flags);
}
static __inline__ void amd7930_disable_ints(struct snd_amd7930 *amd)
{
unsigned long flags;
spin_lock_irqsave(&amd->lock, flags);
sbus_writeb(AMR_INIT, amd->regs + AMD7930_CR);
sbus_writeb(AM_INIT_ACTIVE | AM_INIT_DISABLE_INTS, amd->regs + AMD7930_DR);
spin_unlock_irqrestore(&amd->lock, flags);
}
static void __amd7930_write_map(struct snd_amd7930 *amd)
{
struct amd7930_map *map = &amd->map;
sbus_writeb(AMR_MAP_GX, amd->regs + AMD7930_CR);
sbus_writeb(((map->gx >> 0) & 0xff), amd->regs + AMD7930_DR);
sbus_writeb(((map->gx >> 8) & 0xff), amd->regs + AMD7930_DR);
sbus_writeb(AMR_MAP_GR, amd->regs + AMD7930_CR);
sbus_writeb(((map->gr >> 0) & 0xff), amd->regs + AMD7930_DR);
sbus_writeb(((map->gr >> 8) & 0xff), amd->regs + AMD7930_DR);
sbus_writeb(AMR_MAP_STGR, amd->regs + AMD7930_CR);
sbus_writeb(((map->stgr >> 0) & 0xff), amd->regs + AMD7930_DR);
sbus_writeb(((map->stgr >> 8) & 0xff), amd->regs + AMD7930_DR);
sbus_writeb(AMR_MAP_GER, amd->regs + AMD7930_CR);
sbus_writeb(((map->ger >> 0) & 0xff), amd->regs + AMD7930_DR);
sbus_writeb(((map->ger >> 8) & 0xff), amd->regs + AMD7930_DR);
sbus_writeb(AMR_MAP_MMR1, amd->regs + AMD7930_CR);
sbus_writeb(map->mmr1, amd->regs + AMD7930_DR);
sbus_writeb(AMR_MAP_MMR2, amd->regs + AMD7930_CR);
sbus_writeb(map->mmr2, amd->regs + AMD7930_DR);
}
static void __amd7930_update_map(struct snd_amd7930 *amd)
{
struct amd7930_map *map = &amd->map;
int level;
map->gx = gx_coeff[amd->rgain];
map->stgr = gx_coeff[amd->mgain];
level = (amd->pgain * (256 + ARRAY_SIZE(ger_coeff))) >> 8;
if (level >= 256) {
map->ger = ger_coeff[level - 256];
map->gr = gx_coeff[255];
} else {
map->ger = ger_coeff[0];
map->gr = gx_coeff[level];
}
__amd7930_write_map(amd);
}
static irqreturn_t snd_amd7930_interrupt(int irq, void *dev_id)
{
struct snd_amd7930 *amd = dev_id;
unsigned int elapsed;
u8 ir;
spin_lock(&amd->lock);
elapsed = 0;
ir = sbus_readb(amd->regs + AMD7930_IR);
if (ir & AMR_IR_BBUF) {
u8 byte;
if (amd->flags & AMD7930_FLAG_PLAYBACK) {
if (amd->p_left > 0) {
byte = *(amd->p_cur++);
amd->p_left--;
sbus_writeb(byte, amd->regs + AMD7930_BBTB);
if (amd->p_left == 0)
elapsed |= AMD7930_FLAG_PLAYBACK;
} else
sbus_writeb(0, amd->regs + AMD7930_BBTB);
} else if (amd->flags & AMD7930_FLAG_CAPTURE) {
byte = sbus_readb(amd->regs + AMD7930_BBRB);
if (amd->c_left > 0) {
*(amd->c_cur++) = byte;
amd->c_left--;
if (amd->c_left == 0)
elapsed |= AMD7930_FLAG_CAPTURE;
}
}
}
spin_unlock(&amd->lock);
if (elapsed & AMD7930_FLAG_PLAYBACK)
snd_pcm_period_elapsed(amd->playback_substream);
else
snd_pcm_period_elapsed(amd->capture_substream);
return IRQ_HANDLED;
}
static int snd_amd7930_trigger(struct snd_amd7930 *amd, unsigned int flag, int cmd)
{
unsigned long flags;
int result = 0;
spin_lock_irqsave(&amd->lock, flags);
if (cmd == SNDRV_PCM_TRIGGER_START) {
if (!(amd->flags & flag)) {
amd->flags |= flag;
sbus_writeb(AMR_MUX_MCR4, amd->regs + AMD7930_CR);
sbus_writeb(AM_MUX_MCR4_ENABLE_INTS, amd->regs + AMD7930_DR);
}
} else if (cmd == SNDRV_PCM_TRIGGER_STOP) {
if (amd->flags & flag) {
amd->flags &= ~flag;
sbus_writeb(AMR_MUX_MCR4, amd->regs + AMD7930_CR);
sbus_writeb(0, amd->regs + AMD7930_DR);
}
} else {
result = -EINVAL;
}
spin_unlock_irqrestore(&amd->lock, flags);
return result;
}
static int snd_amd7930_playback_trigger(struct snd_pcm_substream *substream,
int cmd)
{
struct snd_amd7930 *amd = snd_pcm_substream_chip(substream);
return snd_amd7930_trigger(amd, AMD7930_FLAG_PLAYBACK, cmd);
}
static int snd_amd7930_capture_trigger(struct snd_pcm_substream *substream,
int cmd)
{
struct snd_amd7930 *amd = snd_pcm_substream_chip(substream);
return snd_amd7930_trigger(amd, AMD7930_FLAG_CAPTURE, cmd);
}
static int snd_amd7930_playback_prepare(struct snd_pcm_substream *substream)
{
struct snd_amd7930 *amd = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
unsigned int size = snd_pcm_lib_buffer_bytes(substream);
unsigned long flags;
u8 new_mmr1;
spin_lock_irqsave(&amd->lock, flags);
amd->flags |= AMD7930_FLAG_PLAYBACK;
amd->p_orig = amd->p_cur = runtime->dma_area;
amd->p_left = size;
new_mmr1 = amd->map.mmr1;
if (runtime->format == SNDRV_PCM_FORMAT_A_LAW)
new_mmr1 |= AM_MAP_MMR1_ALAW;
else
new_mmr1 &= ~AM_MAP_MMR1_ALAW;
if (new_mmr1 != amd->map.mmr1) {
amd->map.mmr1 = new_mmr1;
__amd7930_update_map(amd);
}
spin_unlock_irqrestore(&amd->lock, flags);
return 0;
}
static int snd_amd7930_capture_prepare(struct snd_pcm_substream *substream)
{
struct snd_amd7930 *amd = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
unsigned int size = snd_pcm_lib_buffer_bytes(substream);
unsigned long flags;
u8 new_mmr1;
spin_lock_irqsave(&amd->lock, flags);
amd->flags |= AMD7930_FLAG_CAPTURE;
amd->c_orig = amd->c_cur = runtime->dma_area;
amd->c_left = size;
new_mmr1 = amd->map.mmr1;
if (runtime->format == SNDRV_PCM_FORMAT_A_LAW)
new_mmr1 |= AM_MAP_MMR1_ALAW;
else
new_mmr1 &= ~AM_MAP_MMR1_ALAW;
if (new_mmr1 != amd->map.mmr1) {
amd->map.mmr1 = new_mmr1;
__amd7930_update_map(amd);
}
spin_unlock_irqrestore(&amd->lock, flags);
return 0;
}
static snd_pcm_uframes_t snd_amd7930_playback_pointer(struct snd_pcm_substream *substream)
{
struct snd_amd7930 *amd = snd_pcm_substream_chip(substream);
size_t ptr;
if (!(amd->flags & AMD7930_FLAG_PLAYBACK))
return 0;
ptr = amd->p_cur - amd->p_orig;
return bytes_to_frames(substream->runtime, ptr);
}
static snd_pcm_uframes_t snd_amd7930_capture_pointer(struct snd_pcm_substream *substream)
{
struct snd_amd7930 *amd = snd_pcm_substream_chip(substream);
size_t ptr;
if (!(amd->flags & AMD7930_FLAG_CAPTURE))
return 0;
ptr = amd->c_cur - amd->c_orig;
return bytes_to_frames(substream->runtime, ptr);
}
static int snd_amd7930_playback_open(struct snd_pcm_substream *substream)
{
struct snd_amd7930 *amd = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
amd->playback_substream = substream;
runtime->hw = snd_amd7930_pcm_hw;
return 0;
}
static int snd_amd7930_capture_open(struct snd_pcm_substream *substream)
{
struct snd_amd7930 *amd = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
amd->capture_substream = substream;
runtime->hw = snd_amd7930_pcm_hw;
return 0;
}
static int snd_amd7930_playback_close(struct snd_pcm_substream *substream)
{
struct snd_amd7930 *amd = snd_pcm_substream_chip(substream);
amd->playback_substream = NULL;
return 0;
}
static int snd_amd7930_capture_close(struct snd_pcm_substream *substream)
{
struct snd_amd7930 *amd = snd_pcm_substream_chip(substream);
amd->capture_substream = NULL;
return 0;
}
static int snd_amd7930_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
return snd_pcm_lib_malloc_pages(substream, params_buffer_bytes(hw_params));
}
static int snd_amd7930_hw_free(struct snd_pcm_substream *substream)
{
return snd_pcm_lib_free_pages(substream);
}
static int snd_amd7930_pcm(struct snd_amd7930 *amd)
{
struct snd_pcm *pcm;
int err;
if ((err = snd_pcm_new(amd->card,
"sun_amd7930",
0,
1,
1, &pcm)) < 0)
return err;
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, &snd_amd7930_playback_ops);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE, &snd_amd7930_capture_ops);
pcm->private_data = amd;
pcm->info_flags = 0;
strcpy(pcm->name, amd->card->shortname);
amd->pcm = pcm;
snd_pcm_lib_preallocate_pages_for_all(pcm, SNDRV_DMA_TYPE_CONTINUOUS,
snd_dma_continuous_data(GFP_KERNEL),
64*1024, 64*1024);
return 0;
}
static int snd_amd7930_info_volume(struct snd_kcontrol *kctl, struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 255;
return 0;
}
static int snd_amd7930_get_volume(struct snd_kcontrol *kctl, struct snd_ctl_elem_value *ucontrol)
{
struct snd_amd7930 *amd = snd_kcontrol_chip(kctl);
int type = kctl->private_value;
int *swval;
switch (type) {
case VOLUME_MONITOR:
swval = &amd->mgain;
break;
case VOLUME_CAPTURE:
swval = &amd->rgain;
break;
case VOLUME_PLAYBACK:
default:
swval = &amd->pgain;
break;
}
ucontrol->value.integer.value[0] = *swval;
return 0;
}
static int snd_amd7930_put_volume(struct snd_kcontrol *kctl, struct snd_ctl_elem_value *ucontrol)
{
struct snd_amd7930 *amd = snd_kcontrol_chip(kctl);
unsigned long flags;
int type = kctl->private_value;
int *swval, change;
switch (type) {
case VOLUME_MONITOR:
swval = &amd->mgain;
break;
case VOLUME_CAPTURE:
swval = &amd->rgain;
break;
case VOLUME_PLAYBACK:
default:
swval = &amd->pgain;
break;
}
spin_lock_irqsave(&amd->lock, flags);
if (*swval != ucontrol->value.integer.value[0]) {
*swval = ucontrol->value.integer.value[0] & 0xff;
__amd7930_update_map(amd);
change = 1;
} else
change = 0;
spin_unlock_irqrestore(&amd->lock, flags);
return change;
}
static int snd_amd7930_mixer(struct snd_amd7930 *amd)
{
struct snd_card *card;
int idx, err;
if (snd_BUG_ON(!amd || !amd->card))
return -EINVAL;
card = amd->card;
strcpy(card->mixername, card->shortname);
for (idx = 0; idx < ARRAY_SIZE(amd7930_controls); idx++) {
if ((err = snd_ctl_add(card,
snd_ctl_new1(&amd7930_controls[idx], amd))) < 0)
return err;
}
return 0;
}
static int snd_amd7930_free(struct snd_amd7930 *amd)
{
struct platform_device *op = amd->op;
amd7930_idle(amd);
if (amd->irq)
free_irq(amd->irq, amd);
if (amd->regs)
of_iounmap(&op->resource[0], amd->regs,
resource_size(&op->resource[0]));
kfree(amd);
return 0;
}
static int snd_amd7930_dev_free(struct snd_device *device)
{
struct snd_amd7930 *amd = device->device_data;
return snd_amd7930_free(amd);
}
static int snd_amd7930_create(struct snd_card *card,
struct platform_device *op,
int irq, int dev,
struct snd_amd7930 **ramd)
{
struct snd_amd7930 *amd;
unsigned long flags;
int err;
*ramd = NULL;
amd = kzalloc(sizeof(*amd), GFP_KERNEL);
if (amd == NULL)
return -ENOMEM;
spin_lock_init(&amd->lock);
amd->card = card;
amd->op = op;
amd->regs = of_ioremap(&op->resource[0], 0,
resource_size(&op->resource[0]), "amd7930");
if (!amd->regs) {
snd_printk(KERN_ERR
"amd7930-%d: Unable to map chip registers.\n", dev);
return -EIO;
}
amd7930_idle(amd);
if (request_irq(irq, snd_amd7930_interrupt,
IRQF_SHARED, "amd7930", amd)) {
snd_printk(KERN_ERR "amd7930-%d: Unable to grab IRQ %d\n",
dev, irq);
snd_amd7930_free(amd);
return -EBUSY;
}
amd->irq = irq;
amd7930_enable_ints(amd);
spin_lock_irqsave(&amd->lock, flags);
amd->rgain = 128;
amd->pgain = 200;
amd->mgain = 0;
memset(&amd->map, 0, sizeof(amd->map));
amd->map.mmr1 = (AM_MAP_MMR1_GX | AM_MAP_MMR1_GER |
AM_MAP_MMR1_GR | AM_MAP_MMR1_STG);
amd->map.mmr2 = (AM_MAP_MMR2_LS | AM_MAP_MMR2_AINB);
__amd7930_update_map(amd);
sbus_writeb(AMR_MUX_MCR1, amd->regs + AMD7930_CR);
sbus_writeb(AM_MUX_CHANNEL_Ba | (AM_MUX_CHANNEL_Bb << 4),
amd->regs + AMD7930_DR);
spin_unlock_irqrestore(&amd->lock, flags);
if ((err = snd_device_new(card, SNDRV_DEV_LOWLEVEL,
amd, &snd_amd7930_dev_ops)) < 0) {
snd_amd7930_free(amd);
return err;
}
*ramd = amd;
return 0;
}
static int amd7930_sbus_probe(struct platform_device *op)
{
struct resource *rp = &op->resource[0];
static int dev_num;
struct snd_card *card;
struct snd_amd7930 *amd;
int err, irq;
irq = op->archdata.irqs[0];
if (dev_num >= SNDRV_CARDS)
return -ENODEV;
if (!enable[dev_num]) {
dev_num++;
return -ENOENT;
}
err = snd_card_new(&op->dev, index[dev_num], id[dev_num],
THIS_MODULE, 0, &card);
if (err < 0)
return err;
strcpy(card->driver, "AMD7930");
strcpy(card->shortname, "Sun AMD7930");
sprintf(card->longname, "%s at 0x%02lx:0x%08Lx, irq %d",
card->shortname,
rp->flags & 0xffL,
(unsigned long long)rp->start,
irq);
if ((err = snd_amd7930_create(card, op,
irq, dev_num, &amd)) < 0)
goto out_err;
if ((err = snd_amd7930_pcm(amd)) < 0)
goto out_err;
if ((err = snd_amd7930_mixer(amd)) < 0)
goto out_err;
if ((err = snd_card_register(card)) < 0)
goto out_err;
amd->next = amd7930_list;
amd7930_list = amd;
dev_num++;
return 0;
out_err:
snd_card_free(card);
return err;
}
static int __init amd7930_init(void)
{
return platform_driver_register(&amd7930_sbus_driver);
}
static void __exit amd7930_exit(void)
{
struct snd_amd7930 *p = amd7930_list;
while (p != NULL) {
struct snd_amd7930 *next = p->next;
snd_card_free(p->card);
p = next;
}
amd7930_list = NULL;
platform_driver_unregister(&amd7930_sbus_driver);
}
