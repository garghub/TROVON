static int lx_hardware_open(struct lx6464es *chip,
struct snd_pcm_substream *substream)
{
int err = 0;
struct snd_pcm_runtime *runtime = substream->runtime;
int channels = runtime->channels;
int is_capture = (substream->stream == SNDRV_PCM_STREAM_CAPTURE);
snd_pcm_uframes_t period_size = runtime->period_size;
snd_printd(LXP "allocating pipe for %d channels\n", channels);
err = lx_pipe_allocate(chip, 0, is_capture, channels);
if (err < 0) {
snd_printk(KERN_ERR LXP "allocating pipe failed\n");
return err;
}
err = lx_set_granularity(chip, period_size);
if (err < 0) {
snd_printk(KERN_ERR LXP "setting granularity to %ld failed\n",
period_size);
return err;
}
return 0;
}
static int lx_hardware_start(struct lx6464es *chip,
struct snd_pcm_substream *substream)
{
int err = 0;
struct snd_pcm_runtime *runtime = substream->runtime;
int is_capture = (substream->stream == SNDRV_PCM_STREAM_CAPTURE);
snd_printd(LXP "setting stream format\n");
err = lx_stream_set_format(chip, runtime, 0, is_capture);
if (err < 0) {
snd_printk(KERN_ERR LXP "setting stream format failed\n");
return err;
}
snd_printd(LXP "starting pipe\n");
err = lx_pipe_start(chip, 0, is_capture);
if (err < 0) {
snd_printk(KERN_ERR LXP "starting pipe failed\n");
return err;
}
snd_printd(LXP "waiting for pipe to start\n");
err = lx_pipe_wait_for_start(chip, 0, is_capture);
if (err < 0) {
snd_printk(KERN_ERR LXP "waiting for pipe failed\n");
return err;
}
return err;
}
static int lx_hardware_stop(struct lx6464es *chip,
struct snd_pcm_substream *substream)
{
int err = 0;
int is_capture = (substream->stream == SNDRV_PCM_STREAM_CAPTURE);
snd_printd(LXP "pausing pipe\n");
err = lx_pipe_pause(chip, 0, is_capture);
if (err < 0) {
snd_printk(KERN_ERR LXP "pausing pipe failed\n");
return err;
}
snd_printd(LXP "waiting for pipe to become idle\n");
err = lx_pipe_wait_for_idle(chip, 0, is_capture);
if (err < 0) {
snd_printk(KERN_ERR LXP "waiting for pipe failed\n");
return err;
}
snd_printd(LXP "stopping pipe\n");
err = lx_pipe_stop(chip, 0, is_capture);
if (err < 0) {
snd_printk(LXP "stopping pipe failed\n");
return err;
}
return err;
}
static int lx_hardware_close(struct lx6464es *chip,
struct snd_pcm_substream *substream)
{
int err = 0;
int is_capture = (substream->stream == SNDRV_PCM_STREAM_CAPTURE);
snd_printd(LXP "releasing pipe\n");
err = lx_pipe_release(chip, 0, is_capture);
if (err < 0) {
snd_printk(LXP "releasing pipe failed\n");
return err;
}
return err;
}
static int lx_pcm_open(struct snd_pcm_substream *substream)
{
struct lx6464es *chip = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
int err = 0;
int board_rate;
snd_printdd("->lx_pcm_open\n");
mutex_lock(&chip->setup_mutex);
runtime->hw = lx_caps;
#if 0
err = snd_pcm_hw_constraint_integer(runtime,
SNDRV_PCM_HW_PARAM_PERIODS);
if (err < 0) {
snd_printk(KERN_WARNING LXP "could not constrain periods\n");
goto exit;
}
#endif
board_rate = chip->board_sample_rate;
err = snd_pcm_hw_constraint_minmax(runtime, SNDRV_PCM_HW_PARAM_RATE,
board_rate, board_rate);
if (err < 0) {
snd_printk(KERN_WARNING LXP "could not constrain periods\n");
goto exit;
}
err = snd_pcm_hw_constraint_minmax(runtime,
SNDRV_PCM_HW_PARAM_PERIOD_SIZE,
MICROBLAZE_IBL_MIN,
MICROBLAZE_IBL_MAX);
if (err < 0) {
snd_printk(KERN_WARNING LXP
"could not constrain period size\n");
goto exit;
}
snd_pcm_hw_constraint_step(runtime, 0,
SNDRV_PCM_HW_PARAM_BUFFER_SIZE, 32);
snd_pcm_set_sync(substream);
err = 0;
exit:
runtime->private_data = chip;
mutex_unlock(&chip->setup_mutex);
snd_printdd("<-lx_pcm_open, %d\n", err);
return err;
}
static int lx_pcm_close(struct snd_pcm_substream *substream)
{
int err = 0;
snd_printdd("->lx_pcm_close\n");
return err;
}
static snd_pcm_uframes_t lx_pcm_stream_pointer(struct snd_pcm_substream
*substream)
{
struct lx6464es *chip = snd_pcm_substream_chip(substream);
snd_pcm_uframes_t pos;
unsigned long flags;
int is_capture = (substream->stream == SNDRV_PCM_STREAM_CAPTURE);
struct lx_stream *lx_stream = is_capture ? &chip->capture_stream :
&chip->playback_stream;
snd_printdd("->lx_pcm_stream_pointer\n");
spin_lock_irqsave(&chip->lock, flags);
pos = lx_stream->frame_pos * substream->runtime->period_size;
spin_unlock_irqrestore(&chip->lock, flags);
snd_printdd(LXP "stream_pointer at %ld\n", pos);
return pos;
}
static int lx_pcm_prepare(struct snd_pcm_substream *substream)
{
struct lx6464es *chip = snd_pcm_substream_chip(substream);
int err = 0;
const int is_capture = (substream->stream == SNDRV_PCM_STREAM_CAPTURE);
snd_printdd("->lx_pcm_prepare\n");
mutex_lock(&chip->setup_mutex);
if (chip->hardware_running[is_capture]) {
err = lx_hardware_stop(chip, substream);
if (err < 0) {
snd_printk(KERN_ERR LXP "failed to stop hardware. "
"Error code %d\n", err);
goto exit;
}
err = lx_hardware_close(chip, substream);
if (err < 0) {
snd_printk(KERN_ERR LXP "failed to close hardware. "
"Error code %d\n", err);
goto exit;
}
}
snd_printd(LXP "opening hardware\n");
err = lx_hardware_open(chip, substream);
if (err < 0) {
snd_printk(KERN_ERR LXP "failed to open hardware. "
"Error code %d\n", err);
goto exit;
}
err = lx_hardware_start(chip, substream);
if (err < 0) {
snd_printk(KERN_ERR LXP "failed to start hardware. "
"Error code %d\n", err);
goto exit;
}
chip->hardware_running[is_capture] = 1;
if (chip->board_sample_rate != substream->runtime->rate) {
if (!err)
chip->board_sample_rate = substream->runtime->rate;
}
exit:
mutex_unlock(&chip->setup_mutex);
return err;
}
static int lx_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params, int is_capture)
{
struct lx6464es *chip = snd_pcm_substream_chip(substream);
int err = 0;
snd_printdd("->lx_pcm_hw_params\n");
mutex_lock(&chip->setup_mutex);
err = snd_pcm_lib_malloc_pages(substream,
params_buffer_bytes(hw_params));
if (is_capture)
chip->capture_stream.stream = substream;
else
chip->playback_stream.stream = substream;
mutex_unlock(&chip->setup_mutex);
return err;
}
static int lx_pcm_hw_params_playback(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
return lx_pcm_hw_params(substream, hw_params, 0);
}
static int lx_pcm_hw_params_capture(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
return lx_pcm_hw_params(substream, hw_params, 1);
}
static int lx_pcm_hw_free(struct snd_pcm_substream *substream)
{
struct lx6464es *chip = snd_pcm_substream_chip(substream);
int err = 0;
int is_capture = (substream->stream == SNDRV_PCM_STREAM_CAPTURE);
snd_printdd("->lx_pcm_hw_free\n");
mutex_lock(&chip->setup_mutex);
if (chip->hardware_running[is_capture]) {
err = lx_hardware_stop(chip, substream);
if (err < 0) {
snd_printk(KERN_ERR LXP "failed to stop hardware. "
"Error code %d\n", err);
goto exit;
}
err = lx_hardware_close(chip, substream);
if (err < 0) {
snd_printk(KERN_ERR LXP "failed to close hardware. "
"Error code %d\n", err);
goto exit;
}
chip->hardware_running[is_capture] = 0;
}
err = snd_pcm_lib_free_pages(substream);
if (is_capture)
chip->capture_stream.stream = 0;
else
chip->playback_stream.stream = 0;
exit:
mutex_unlock(&chip->setup_mutex);
return err;
}
static void lx_trigger_start(struct lx6464es *chip, struct lx_stream *lx_stream)
{
struct snd_pcm_substream *substream = lx_stream->stream;
const unsigned int is_capture = lx_stream->is_capture;
int err;
const u32 channels = substream->runtime->channels;
const u32 bytes_per_frame = channels * 3;
const u32 period_size = substream->runtime->period_size;
const u32 periods = substream->runtime->periods;
const u32 period_bytes = period_size * bytes_per_frame;
dma_addr_t buf = substream->dma_buffer.addr;
int i;
u32 needed, freed;
u32 size_array[5];
for (i = 0; i != periods; ++i) {
u32 buffer_index = 0;
err = lx_buffer_ask(chip, 0, is_capture, &needed, &freed,
size_array);
snd_printdd(LXP "starting: needed %d, freed %d\n",
needed, freed);
err = lx_buffer_give(chip, 0, is_capture, period_bytes,
lower_32_bits(buf), upper_32_bits(buf),
&buffer_index);
snd_printdd(LXP "starting: buffer index %x on %p (%d bytes)\n",
buffer_index, (void *)buf, period_bytes);
buf += period_bytes;
}
err = lx_buffer_ask(chip, 0, is_capture, &needed, &freed, size_array);
snd_printdd(LXP "starting: needed %d, freed %d\n", needed, freed);
snd_printd(LXP "starting: starting stream\n");
err = lx_stream_start(chip, 0, is_capture);
if (err < 0)
snd_printk(KERN_ERR LXP "couldn't start stream\n");
else
lx_stream->status = LX_STREAM_STATUS_RUNNING;
lx_stream->frame_pos = 0;
}
static void lx_trigger_stop(struct lx6464es *chip, struct lx_stream *lx_stream)
{
const unsigned int is_capture = lx_stream->is_capture;
int err;
snd_printd(LXP "stopping: stopping stream\n");
err = lx_stream_stop(chip, 0, is_capture);
if (err < 0)
snd_printk(KERN_ERR LXP "couldn't stop stream\n");
else
lx_stream->status = LX_STREAM_STATUS_FREE;
}
static void lx_trigger_tasklet_dispatch_stream(struct lx6464es *chip,
struct lx_stream *lx_stream)
{
switch (lx_stream->status) {
case LX_STREAM_STATUS_SCHEDULE_RUN:
lx_trigger_start(chip, lx_stream);
break;
case LX_STREAM_STATUS_SCHEDULE_STOP:
lx_trigger_stop(chip, lx_stream);
break;
default:
break;
}
}
static void lx_trigger_tasklet(unsigned long data)
{
struct lx6464es *chip = (struct lx6464es *)data;
unsigned long flags;
snd_printdd("->lx_trigger_tasklet\n");
spin_lock_irqsave(&chip->lock, flags);
lx_trigger_tasklet_dispatch_stream(chip, &chip->capture_stream);
lx_trigger_tasklet_dispatch_stream(chip, &chip->playback_stream);
spin_unlock_irqrestore(&chip->lock, flags);
}
static int lx_pcm_trigger_dispatch(struct lx6464es *chip,
struct lx_stream *lx_stream, int cmd)
{
int err = 0;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
lx_stream->status = LX_STREAM_STATUS_SCHEDULE_RUN;
break;
case SNDRV_PCM_TRIGGER_STOP:
lx_stream->status = LX_STREAM_STATUS_SCHEDULE_STOP;
break;
default:
err = -EINVAL;
goto exit;
}
tasklet_schedule(&chip->trigger_tasklet);
exit:
return err;
}
static int lx_pcm_trigger(struct snd_pcm_substream *substream, int cmd)
{
struct lx6464es *chip = snd_pcm_substream_chip(substream);
const int is_capture = (substream->stream == SNDRV_PCM_STREAM_CAPTURE);
struct lx_stream *stream = is_capture ? &chip->capture_stream :
&chip->playback_stream;
snd_printdd("->lx_pcm_trigger\n");
return lx_pcm_trigger_dispatch(chip, stream, cmd);
}
static int snd_lx6464es_free(struct lx6464es *chip)
{
snd_printdd("->snd_lx6464es_free\n");
lx_irq_disable(chip);
if (chip->irq >= 0)
free_irq(chip->irq, chip);
iounmap(chip->port_dsp_bar);
ioport_unmap(chip->port_plx_remapped);
pci_release_regions(chip->pci);
pci_disable_device(chip->pci);
kfree(chip);
return 0;
}
static int snd_lx6464es_dev_free(struct snd_device *device)
{
return snd_lx6464es_free(device->device_data);
}
static int __devinit lx_init_xilinx_reset(struct lx6464es *chip)
{
int i;
u32 plx_reg = lx_plx_reg_read(chip, ePLX_CHIPSC);
snd_printdd("->lx_init_xilinx_reset\n");
plx_reg &= ~CHIPSC_RESET_XILINX;
lx_plx_reg_write(chip, ePLX_CHIPSC, plx_reg);
msleep(1);
lx_plx_reg_write(chip, ePLX_MBOX3, 0);
msleep(1);
plx_reg |= CHIPSC_RESET_XILINX;
lx_plx_reg_write(chip, ePLX_CHIPSC, plx_reg);
for (i = 0; i != 100; ++i) {
u32 reg_mbox3;
msleep(10);
reg_mbox3 = lx_plx_reg_read(chip, ePLX_MBOX3);
if (reg_mbox3) {
snd_printd(LXP "xilinx reset done\n");
snd_printdd(LXP "xilinx took %d loops\n", i);
break;
}
}
lx_dsp_reg_write(chip, eReg_CSM, 0);
msleep(600);
return 0;
}
static int __devinit lx_init_xilinx_test(struct lx6464es *chip)
{
u32 reg;
snd_printdd("->lx_init_xilinx_test\n");
lx_dsp_reg_write(chip, eReg_CSM, 0);
reg = lx_dsp_reg_read(chip, eReg_CSM);
if (reg) {
snd_printk(KERN_ERR LXP "Problem: Reg_CSM %x.\n", reg);
lx_plx_reg_write(chip, ePLX_PCICR, 1);
reg = lx_dsp_reg_read(chip, eReg_CSM);
if (reg) {
snd_printk(KERN_ERR LXP "Error: Reg_CSM %x.\n", reg);
return -EAGAIN;
}
}
snd_printd(LXP "Xilinx/MicroBlaze access test successful\n");
return 0;
}
static int __devinit lx_init_ethersound_config(struct lx6464es *chip)
{
int i;
u32 orig_conf_es = lx_dsp_reg_read(chip, eReg_CONFES);
u32 conf_es = (orig_conf_es & CONFES_READ_PART_MASK) |
(64 << IOCR_INPUTS_OFFSET) |
(64 << IOCR_OUTPUTS_OFFSET) |
(FREQ_RATIO_SINGLE_MODE << FREQ_RATIO_OFFSET);
snd_printdd("->lx_init_ethersound\n");
chip->freq_ratio = FREQ_RATIO_SINGLE_MODE;
lx_dsp_reg_write(chip, eReg_CONFES, conf_es);
for (i = 0; i != 1000; ++i) {
if (lx_dsp_reg_read(chip, eReg_CSES) & 4) {
snd_printd(LXP "ethersound initialized after %dms\n",
i);
goto ethersound_initialized;
}
msleep(1);
}
snd_printk(KERN_WARNING LXP
"ethersound could not be initialized after %dms\n", i);
return -ETIMEDOUT;
ethersound_initialized:
snd_printd(LXP "ethersound initialized\n");
return 0;
}
static int __devinit lx_init_get_version_features(struct lx6464es *chip)
{
u32 dsp_version;
int err;
snd_printdd("->lx_init_get_version_features\n");
err = lx_dsp_get_version(chip, &dsp_version);
if (err == 0) {
u32 freq;
snd_printk(LXP "DSP version: V%02d.%02d #%d\n",
(dsp_version>>16) & 0xff, (dsp_version>>8) & 0xff,
dsp_version & 0xff);
err = lx_dsp_get_clock_frequency(chip, &freq);
if (err == 0)
chip->board_sample_rate = freq;
snd_printd(LXP "actual clock frequency %d\n", freq);
} else {
snd_printk(KERN_ERR LXP "DSP corrupted \n");
err = -EAGAIN;
}
return err;
}
static int lx_set_granularity(struct lx6464es *chip, u32 gran)
{
int err = 0;
u32 snapped_gran = MICROBLAZE_IBL_MIN;
snd_printdd("->lx_set_granularity\n");
while ((snapped_gran < gran) &&
(snapped_gran < MICROBLAZE_IBL_MAX)) {
snapped_gran *= 2;
}
if (snapped_gran == chip->pcm_granularity)
return 0;
err = lx_dsp_set_granularity(chip, snapped_gran);
if (err < 0) {
snd_printk(KERN_WARNING LXP "could not set granularity\n");
err = -EAGAIN;
}
if (snapped_gran != gran)
snd_printk(LXP "snapped blocksize to %d\n", snapped_gran);
snd_printd(LXP "set blocksize on board %d\n", snapped_gran);
chip->pcm_granularity = snapped_gran;
return err;
}
static int __devinit lx_init_dsp(struct lx6464es *chip)
{
int err;
int i;
snd_printdd("->lx_init_dsp\n");
snd_printd(LXP "initialize board\n");
err = lx_init_xilinx_reset(chip);
if (err)
return err;
snd_printd(LXP "testing board\n");
err = lx_init_xilinx_test(chip);
if (err)
return err;
snd_printd(LXP "initialize ethersound configuration\n");
err = lx_init_ethersound_config(chip);
if (err)
return err;
lx_irq_enable(chip);
for (i = 0; i != 1000; ++i) {
err = lx_dsp_get_mac(chip);
if (err)
return err;
if (chip->mac_address[0] || chip->mac_address[1] || chip->mac_address[2] ||
chip->mac_address[3] || chip->mac_address[4] || chip->mac_address[5])
goto mac_ready;
msleep(1);
}
return -ETIMEDOUT;
mac_ready:
snd_printd(LXP "mac address ready read after: %dms\n", i);
snd_printk(LXP "mac address: %02X.%02X.%02X.%02X.%02X.%02X\n",
chip->mac_address[0], chip->mac_address[1], chip->mac_address[2],
chip->mac_address[3], chip->mac_address[4], chip->mac_address[5]);
err = lx_init_get_version_features(chip);
if (err)
return err;
lx_set_granularity(chip, MICROBLAZE_IBL_DEFAULT);
chip->playback_mute = 0;
return err;
}
static int __devinit lx_pcm_create(struct lx6464es *chip)
{
int err;
struct snd_pcm *pcm;
u32 size = 64 *
3 *
MAX_STREAM_BUFFER *
MICROBLAZE_IBL_MAX *
2;
size = PAGE_ALIGN(size);
err = snd_pcm_new(chip->card, (char *)card_name, 0,
1, 1, &pcm);
pcm->private_data = chip;
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, &lx_ops_playback);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE, &lx_ops_capture);
pcm->info_flags = 0;
strcpy(pcm->name, card_name);
err = snd_pcm_lib_preallocate_pages_for_all(pcm, SNDRV_DMA_TYPE_DEV,
snd_dma_pci_data(chip->pci),
size, size);
if (err < 0)
return err;
chip->pcm = pcm;
chip->capture_stream.is_capture = 1;
return 0;
}
static int lx_control_playback_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_BOOLEAN;
uinfo->count = 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 1;
return 0;
}
static int lx_control_playback_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct lx6464es *chip = snd_kcontrol_chip(kcontrol);
ucontrol->value.integer.value[0] = chip->playback_mute;
return 0;
}
static int lx_control_playback_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct lx6464es *chip = snd_kcontrol_chip(kcontrol);
int changed = 0;
int current_value = chip->playback_mute;
if (current_value != ucontrol->value.integer.value[0]) {
lx_level_unmute(chip, 0, !current_value);
chip->playback_mute = !current_value;
changed = 1;
}
return changed;
}
static void lx_proc_levels_read(struct snd_info_entry *entry,
struct snd_info_buffer *buffer)
{
u32 levels[64];
int err;
int i, j;
struct lx6464es *chip = entry->private_data;
snd_iprintf(buffer, "capture levels:\n");
err = lx_level_peaks(chip, 1, 64, levels);
if (err < 0)
return;
for (i = 0; i != 8; ++i) {
for (j = 0; j != 8; ++j)
snd_iprintf(buffer, "%08x ", levels[i*8+j]);
snd_iprintf(buffer, "\n");
}
snd_iprintf(buffer, "\nplayback levels:\n");
err = lx_level_peaks(chip, 0, 64, levels);
if (err < 0)
return;
for (i = 0; i != 8; ++i) {
for (j = 0; j != 8; ++j)
snd_iprintf(buffer, "%08x ", levels[i*8+j]);
snd_iprintf(buffer, "\n");
}
snd_iprintf(buffer, "\n");
}
static int __devinit lx_proc_create(struct snd_card *card, struct lx6464es *chip)
{
struct snd_info_entry *entry;
int err = snd_card_proc_new(card, "levels", &entry);
if (err < 0)
return err;
snd_info_set_text_ops(entry, chip, lx_proc_levels_read);
return 0;
}
static int __devinit snd_lx6464es_create(struct snd_card *card,
struct pci_dev *pci,
struct lx6464es **rchip)
{
struct lx6464es *chip;
int err;
static struct snd_device_ops ops = {
.dev_free = snd_lx6464es_dev_free,
};
snd_printdd("->snd_lx6464es_create\n");
*rchip = NULL;
err = pci_enable_device(pci);
if (err < 0)
return err;
pci_set_master(pci);
err = pci_set_dma_mask(pci, DMA_BIT_MASK(32));
if (err < 0) {
snd_printk(KERN_ERR "architecture does not support "
"32bit PCI busmaster DMA\n");
pci_disable_device(pci);
return -ENXIO;
}
chip = kzalloc(sizeof(*chip), GFP_KERNEL);
if (chip == NULL) {
err = -ENOMEM;
goto alloc_failed;
}
chip->card = card;
chip->pci = pci;
chip->irq = -1;
spin_lock_init(&chip->lock);
spin_lock_init(&chip->msg_lock);
mutex_init(&chip->setup_mutex);
tasklet_init(&chip->trigger_tasklet, lx_trigger_tasklet,
(unsigned long)chip);
tasklet_init(&chip->tasklet_capture, lx_tasklet_capture,
(unsigned long)chip);
tasklet_init(&chip->tasklet_playback, lx_tasklet_playback,
(unsigned long)chip);
err = pci_request_regions(pci, card_name);
if (err < 0)
goto request_regions_failed;
chip->port_plx = pci_resource_start(pci, 1);
chip->port_plx_remapped = ioport_map(chip->port_plx,
pci_resource_len(pci, 1));
chip->port_dsp_bar = pci_ioremap_bar(pci, 2);
err = request_irq(pci->irq, lx_interrupt, IRQF_SHARED,
KBUILD_MODNAME, chip);
if (err) {
snd_printk(KERN_ERR LXP "unable to grab IRQ %d\n", pci->irq);
goto request_irq_failed;
}
chip->irq = pci->irq;
err = snd_device_new(card, SNDRV_DEV_LOWLEVEL, chip, &ops);
if (err < 0)
goto device_new_failed;
err = lx_init_dsp(chip);
if (err < 0) {
snd_printk(KERN_ERR LXP "error during DSP initialization\n");
return err;
}
err = lx_pcm_create(chip);
if (err < 0)
return err;
err = lx_proc_create(card, chip);
if (err < 0)
return err;
err = snd_ctl_add(card, snd_ctl_new1(&lx_control_playback_switch,
chip));
if (err < 0)
return err;
snd_card_set_dev(card, &pci->dev);
*rchip = chip;
return 0;
device_new_failed:
free_irq(pci->irq, chip);
request_irq_failed:
pci_release_regions(pci);
request_regions_failed:
kfree(chip);
alloc_failed:
pci_disable_device(pci);
return err;
}
static int __devinit snd_lx6464es_probe(struct pci_dev *pci,
const struct pci_device_id *pci_id)
{
static int dev;
struct snd_card *card;
struct lx6464es *chip;
int err;
snd_printdd("->snd_lx6464es_probe\n");
if (dev >= SNDRV_CARDS)
return -ENODEV;
if (!enable[dev]) {
dev++;
return -ENOENT;
}
err = snd_card_create(index[dev], id[dev], THIS_MODULE, 0, &card);
if (err < 0)
return err;
err = snd_lx6464es_create(card, pci, &chip);
if (err < 0) {
snd_printk(KERN_ERR LXP "error during snd_lx6464es_create\n");
goto out_free;
}
strcpy(card->driver, "LX6464ES");
sprintf(card->id, "LX6464ES_%02X%02X%02X",
chip->mac_address[3], chip->mac_address[4], chip->mac_address[5]);
sprintf(card->shortname, "LX6464ES %02X.%02X.%02X.%02X.%02X.%02X",
chip->mac_address[0], chip->mac_address[1], chip->mac_address[2],
chip->mac_address[3], chip->mac_address[4], chip->mac_address[5]);
sprintf(card->longname, "%s at 0x%lx, 0x%p, irq %i",
card->shortname, chip->port_plx,
chip->port_dsp_bar, chip->irq);
err = snd_card_register(card);
if (err < 0)
goto out_free;
snd_printdd(LXP "initialization successful\n");
pci_set_drvdata(pci, card);
dev++;
return 0;
out_free:
snd_card_free(card);
return err;
}
static void __devexit snd_lx6464es_remove(struct pci_dev *pci)
{
snd_card_free(pci_get_drvdata(pci));
pci_set_drvdata(pci, NULL);
}
static int __init mod_init(void)
{
return pci_register_driver(&driver);
}
static void __exit mod_exit(void)
{
pci_unregister_driver(&driver);
}
