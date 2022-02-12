static void
au1000_set_ac97_xmit_slots(struct snd_au1000 *au1000, long xmit_slots)
{
u32 volatile ac97_config;
spin_lock(&au1000->ac97_lock);
ac97_config = au1000->ac97_ioport->config;
ac97_config = ac97_config & ~AC97C_XMIT_SLOTS_MASK;
ac97_config |= (xmit_slots << AC97C_XMIT_SLOTS_BIT);
au1000->ac97_ioport->config = ac97_config;
spin_unlock(&au1000->ac97_lock);
}
static void
au1000_set_ac97_recv_slots(struct snd_au1000 *au1000, long recv_slots)
{
u32 volatile ac97_config;
spin_lock(&au1000->ac97_lock);
ac97_config = au1000->ac97_ioport->config;
ac97_config = ac97_config & ~AC97C_RECV_SLOTS_MASK;
ac97_config |= (recv_slots << AC97C_RECV_SLOTS_BIT);
au1000->ac97_ioport->config = ac97_config;
spin_unlock(&au1000->ac97_lock);
}
static void
au1000_release_dma_link(struct audio_stream *stream)
{
struct au1000_period * pointer;
struct au1000_period * pointer_next;
stream->period_size = 0;
stream->periods = 0;
pointer = stream->buffer;
if (! pointer)
return;
do {
pointer_next = pointer->next;
kfree(pointer);
pointer = pointer_next;
} while (pointer != stream->buffer);
stream->buffer = NULL;
}
static int
au1000_setup_dma_link(struct audio_stream *stream, unsigned int period_bytes,
unsigned int periods)
{
struct snd_pcm_substream *substream = stream->substream;
struct snd_pcm_runtime *runtime = substream->runtime;
struct au1000_period *pointer;
unsigned long dma_start;
int i;
dma_start = virt_to_phys(runtime->dma_area);
if (stream->period_size == period_bytes &&
stream->periods == periods)
return 0;
au1000_release_dma_link(stream);
stream->period_size = period_bytes;
stream->periods = periods;
stream->buffer = kmalloc(sizeof(struct au1000_period), GFP_KERNEL);
if (! stream->buffer)
return -ENOMEM;
pointer = stream->buffer;
for (i = 0; i < periods; i++) {
pointer->start = (u32)(dma_start + (i * period_bytes));
pointer->relative_end = (u32) (((i+1) * period_bytes) - 0x1);
if (i < periods - 1) {
pointer->next = kmalloc(sizeof(struct au1000_period), GFP_KERNEL);
if (! pointer->next) {
au1000_release_dma_link(stream);
return -ENOMEM;
}
pointer = pointer->next;
}
}
pointer->next = stream->buffer;
return 0;
}
static void
au1000_dma_stop(struct audio_stream *stream)
{
if (snd_BUG_ON(!stream->buffer))
return;
disable_dma(stream->dma);
}
static void
au1000_dma_start(struct audio_stream *stream)
{
if (snd_BUG_ON(!stream->buffer))
return;
init_dma(stream->dma);
if (get_dma_active_buffer(stream->dma) == 0) {
clear_dma_done0(stream->dma);
set_dma_addr0(stream->dma, stream->buffer->start);
set_dma_count0(stream->dma, stream->period_size >> 1);
set_dma_addr1(stream->dma, stream->buffer->next->start);
set_dma_count1(stream->dma, stream->period_size >> 1);
} else {
clear_dma_done1(stream->dma);
set_dma_addr1(stream->dma, stream->buffer->start);
set_dma_count1(stream->dma, stream->period_size >> 1);
set_dma_addr0(stream->dma, stream->buffer->next->start);
set_dma_count0(stream->dma, stream->period_size >> 1);
}
enable_dma_buffers(stream->dma);
start_dma(stream->dma);
}
static irqreturn_t
au1000_dma_interrupt(int irq, void *dev_id)
{
struct audio_stream *stream = (struct audio_stream *) dev_id;
struct snd_pcm_substream *substream = stream->substream;
spin_lock(&stream->dma_lock);
switch (get_dma_buffer_done(stream->dma)) {
case DMA_D0:
stream->buffer = stream->buffer->next;
clear_dma_done0(stream->dma);
set_dma_addr0(stream->dma, stream->buffer->next->start);
set_dma_count0(stream->dma, stream->period_size >> 1);
enable_dma_buffer0(stream->dma);
break;
case DMA_D1:
stream->buffer = stream->buffer->next;
clear_dma_done1(stream->dma);
set_dma_addr1(stream->dma, stream->buffer->next->start);
set_dma_count1(stream->dma, stream->period_size >> 1);
enable_dma_buffer1(stream->dma);
break;
case (DMA_D0 | DMA_D1):
printk(KERN_ERR "DMA %d missed interrupt.\n",stream->dma);
au1000_dma_stop(stream);
au1000_dma_start(stream);
break;
case (~DMA_D0 & ~DMA_D1):
printk(KERN_ERR "DMA %d empty irq.\n",stream->dma);
}
spin_unlock(&stream->dma_lock);
snd_pcm_period_elapsed(substream);
return IRQ_HANDLED;
}
static int
snd_au1000_playback_open(struct snd_pcm_substream *substream)
{
struct snd_au1000 *au1000 = substream->pcm->private_data;
au1000->stream[PLAYBACK]->substream = substream;
au1000->stream[PLAYBACK]->buffer = NULL;
substream->private_data = au1000->stream[PLAYBACK];
substream->runtime->hw = snd_au1000_hw;
return (snd_pcm_hw_constraint_list(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_RATE, &hw_constraints_rates) < 0);
}
static int
snd_au1000_capture_open(struct snd_pcm_substream *substream)
{
struct snd_au1000 *au1000 = substream->pcm->private_data;
au1000->stream[CAPTURE]->substream = substream;
au1000->stream[CAPTURE]->buffer = NULL;
substream->private_data = au1000->stream[CAPTURE];
substream->runtime->hw = snd_au1000_hw;
return (snd_pcm_hw_constraint_list(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_RATE, &hw_constraints_rates) < 0);
}
static int
snd_au1000_playback_close(struct snd_pcm_substream *substream)
{
struct snd_au1000 *au1000 = substream->pcm->private_data;
au1000->stream[PLAYBACK]->substream = NULL;
return 0;
}
static int
snd_au1000_capture_close(struct snd_pcm_substream *substream)
{
struct snd_au1000 *au1000 = substream->pcm->private_data;
au1000->stream[CAPTURE]->substream = NULL;
return 0;
}
static int
snd_au1000_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
struct audio_stream *stream = substream->private_data;
int err;
err = snd_pcm_lib_malloc_pages(substream,
params_buffer_bytes(hw_params));
if (err < 0)
return err;
return au1000_setup_dma_link(stream,
params_period_bytes(hw_params),
params_periods(hw_params));
}
static int
snd_au1000_hw_free(struct snd_pcm_substream *substream)
{
struct audio_stream *stream = substream->private_data;
au1000_release_dma_link(stream);
return snd_pcm_lib_free_pages(substream);
}
static int
snd_au1000_playback_prepare(struct snd_pcm_substream *substream)
{
struct snd_au1000 *au1000 = substream->pcm->private_data;
struct snd_pcm_runtime *runtime = substream->runtime;
if (runtime->channels == 1)
au1000_set_ac97_xmit_slots(au1000, AC97_SLOT_4);
else
au1000_set_ac97_xmit_slots(au1000, AC97_SLOT_3 | AC97_SLOT_4);
snd_ac97_set_rate(au1000->ac97, AC97_PCM_FRONT_DAC_RATE, runtime->rate);
return 0;
}
static int
snd_au1000_capture_prepare(struct snd_pcm_substream *substream)
{
struct snd_au1000 *au1000 = substream->pcm->private_data;
struct snd_pcm_runtime *runtime = substream->runtime;
if (runtime->channels == 1)
au1000_set_ac97_recv_slots(au1000, AC97_SLOT_4);
else
au1000_set_ac97_recv_slots(au1000, AC97_SLOT_3 | AC97_SLOT_4);
snd_ac97_set_rate(au1000->ac97, AC97_PCM_LR_ADC_RATE, runtime->rate);
return 0;
}
static int
snd_au1000_trigger(struct snd_pcm_substream *substream, int cmd)
{
struct audio_stream *stream = substream->private_data;
int err = 0;
spin_lock(&stream->dma_lock);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
au1000_dma_start(stream);
break;
case SNDRV_PCM_TRIGGER_STOP:
au1000_dma_stop(stream);
break;
default:
err = -EINVAL;
break;
}
spin_unlock(&stream->dma_lock);
return err;
}
static snd_pcm_uframes_t
snd_au1000_pointer(struct snd_pcm_substream *substream)
{
struct audio_stream *stream = substream->private_data;
struct snd_pcm_runtime *runtime = substream->runtime;
long location;
spin_lock(&stream->dma_lock);
location = get_dma_residue(stream->dma);
spin_unlock(&stream->dma_lock);
location = stream->buffer->relative_end - location;
if (location == -1)
location = 0;
return bytes_to_frames(runtime,location);
}
static int
snd_au1000_pcm_new(struct snd_au1000 *au1000)
{
struct snd_pcm *pcm;
int err;
unsigned long flags;
if ((err = snd_pcm_new(au1000->card, "AU1000 AC97 PCM", 0, 1, 1, &pcm)) < 0)
return err;
snd_pcm_lib_preallocate_pages_for_all(pcm, SNDRV_DMA_TYPE_CONTINUOUS,
snd_dma_continuous_data(GFP_KERNEL), 128*1024, 128*1024);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK,
&snd_card_au1000_playback_ops);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE,
&snd_card_au1000_capture_ops);
pcm->private_data = au1000;
pcm->info_flags = 0;
strcpy(pcm->name, "Au1000 AC97 PCM");
spin_lock_init(&au1000->stream[PLAYBACK]->dma_lock);
spin_lock_init(&au1000->stream[CAPTURE]->dma_lock);
flags = claim_dma_lock();
au1000->stream[PLAYBACK]->dma = request_au1000_dma(au1000->dmaid[0],
"AC97 TX", au1000_dma_interrupt, 0,
au1000->stream[PLAYBACK]);
if (au1000->stream[PLAYBACK]->dma < 0) {
release_dma_lock(flags);
return -EBUSY;
}
au1000->stream[CAPTURE]->dma = request_au1000_dma(au1000->dmaid[1],
"AC97 RX", au1000_dma_interrupt, 0,
au1000->stream[CAPTURE]);
if (au1000->stream[CAPTURE]->dma < 0){
release_dma_lock(flags);
return -EBUSY;
}
set_dma_mode(au1000->stream[PLAYBACK]->dma,
get_dma_mode(au1000->stream[PLAYBACK]->dma) & ~DMA_NC);
set_dma_mode(au1000->stream[CAPTURE]->dma,
get_dma_mode(au1000->stream[CAPTURE]->dma) & ~DMA_NC);
release_dma_lock(flags);
au1000->pcm = pcm;
return 0;
}
static unsigned short
snd_au1000_ac97_read(struct snd_ac97 *ac97, unsigned short reg)
{
struct snd_au1000 *au1000 = ac97->private_data;
u32 volatile cmd;
u16 volatile data;
int i;
spin_lock(&au1000->ac97_lock);
for (i = 0; i < 0x5000; i++)
if (!(au1000->ac97_ioport->status & AC97C_CP))
break;
if (i == 0x5000)
printk(KERN_ERR "au1000 AC97: AC97 command read timeout\n");
cmd = (u32) reg & AC97C_INDEX_MASK;
cmd |= AC97C_READ;
au1000->ac97_ioport->cmd = cmd;
for (i = 0; i < 0x5000; i++)
if (!(au1000->ac97_ioport->status & AC97C_CP))
break;
if (i == 0x5000) {
printk(KERN_ERR "au1000 AC97: AC97 command read timeout\n");
spin_unlock(&au1000->ac97_lock);
return 0;
}
data = au1000->ac97_ioport->cmd & 0xffff;
spin_unlock(&au1000->ac97_lock);
return data;
}
static void
snd_au1000_ac97_write(struct snd_ac97 *ac97, unsigned short reg, unsigned short val)
{
struct snd_au1000 *au1000 = ac97->private_data;
u32 cmd;
int i;
spin_lock(&au1000->ac97_lock);
for (i = 0; i < 0x5000; i++)
if (!(au1000->ac97_ioport->status & AC97C_CP))
break;
if (i == 0x5000)
printk(KERN_ERR "au1000 AC97: AC97 command write timeout\n");
cmd = (u32) reg & AC97C_INDEX_MASK;
cmd &= ~AC97C_READ;
cmd |= ((u32) val << AC97C_WD_BIT);
au1000->ac97_ioport->cmd = cmd;
spin_unlock(&au1000->ac97_lock);
}
static void snd_au1000_free(struct snd_card *card)
{
struct snd_au1000 *au1000 = card->private_data;
if (au1000->stream[PLAYBACK]) {
if (au1000->stream[PLAYBACK]->dma >= 0)
free_au1000_dma(au1000->stream[PLAYBACK]->dma);
kfree(au1000->stream[PLAYBACK]);
}
if (au1000->stream[CAPTURE]) {
if (au1000->stream[CAPTURE]->dma >= 0)
free_au1000_dma(au1000->stream[CAPTURE]->dma);
kfree(au1000->stream[CAPTURE]);
}
if (au1000->ac97_res_port) {
if (au1000->ac97_ioport) {
au1000->ac97_ioport->cntrl = AC97C_RS;
iounmap(au1000->ac97_ioport);
au1000->ac97_ioport = NULL;
}
release_and_free_resource(au1000->ac97_res_port);
au1000->ac97_res_port = NULL;
}
}
static int au1000_ac97_probe(struct platform_device *pdev)
{
int err;
void __iomem *io;
struct resource *r;
struct snd_card *card;
struct snd_au1000 *au1000;
struct snd_ac97_bus *pbus;
struct snd_ac97_template ac97;
err = snd_card_new(&pdev->dev, -1, "AC97", THIS_MODULE,
sizeof(struct snd_au1000), &card);
if (err < 0)
return err;
au1000 = card->private_data;
au1000->card = card;
spin_lock_init(&au1000->ac97_lock);
card->private_free = snd_au1000_free;
r = platform_get_resource(pdev, IORESOURCE_DMA, 0);
if (!r) {
err = -ENODEV;
snd_printk(KERN_INFO "no TX DMA platform resource!\n");
goto out;
}
au1000->dmaid[0] = r->start;
r = platform_get_resource(pdev, IORESOURCE_DMA, 1);
if (!r) {
err = -ENODEV;
snd_printk(KERN_INFO "no RX DMA platform resource!\n");
goto out;
}
au1000->dmaid[1] = r->start;
au1000->stream[PLAYBACK] = kmalloc(sizeof(struct audio_stream),
GFP_KERNEL);
if (!au1000->stream[PLAYBACK]) {
err = -ENOMEM;
goto out;
}
au1000->stream[PLAYBACK]->dma = -1;
au1000->stream[CAPTURE] = kmalloc(sizeof(struct audio_stream),
GFP_KERNEL);
if (!au1000->stream[CAPTURE]) {
err = -ENOMEM;
goto out;
}
au1000->stream[CAPTURE]->dma = -1;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!r) {
err = -ENODEV;
goto out;
}
err = -EBUSY;
au1000->ac97_res_port = request_mem_region(r->start, resource_size(r),
pdev->name);
if (!au1000->ac97_res_port) {
snd_printk(KERN_ERR "ALSA AC97: can't grab AC97 port\n");
goto out;
}
io = ioremap(r->start, resource_size(r));
if (!io)
goto out;
au1000->ac97_ioport = (struct au1000_ac97_reg *)io;
au_writel(au_readl(SYS_PINFUNC) & ~0x02, SYS_PINFUNC);
au1000->ac97_ioport->cntrl = AC97C_RS | AC97C_CE;
udelay(10);
au1000->ac97_ioport->cntrl = AC97C_CE;
udelay(10);
au1000->ac97_ioport->config = AC97C_RESET;
udelay(10);
au1000->ac97_ioport->config = 0x0;
mdelay(5);
err = snd_ac97_bus(au1000->card, 0, &ops, au1000, &pbus);
if (err < 0)
goto out;
memset(&ac97, 0, sizeof(ac97));
ac97.private_data = au1000;
err = snd_ac97_mixer(pbus, &ac97, &au1000->ac97);
if (err < 0)
goto out;
err = snd_au1000_pcm_new(au1000);
if (err < 0)
goto out;
strcpy(card->driver, "Au1000-AC97");
strcpy(card->shortname, "AMD Au1000-AC97");
sprintf(card->longname, "AMD Au1000--AC97 ALSA Driver");
err = snd_card_register(card);
if (err < 0)
goto out;
printk(KERN_INFO "ALSA AC97: Driver Initialized\n");
platform_set_drvdata(pdev, card);
return 0;
out:
snd_card_free(card);
return err;
}
static int au1000_ac97_remove(struct platform_device *pdev)
{
return snd_card_free(platform_get_drvdata(pdev));
}
