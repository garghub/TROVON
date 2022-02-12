static int emu10k1_playback_constraints(struct snd_pcm_runtime *runtime)
{
int err;
err = snd_pcm_hw_constraint_integer(runtime, SNDRV_PCM_HW_PARAM_PERIODS);
if (err < 0)
return err;
err = snd_pcm_hw_constraint_minmax(runtime, SNDRV_PCM_HW_PARAM_BUFFER_BYTES, 256, UINT_MAX);
if (err < 0)
return err;
return 0;
}
static void dummy_systimer_rearm(struct dummy_systimer_pcm *dpcm)
{
dpcm->timer.expires = jiffies +
(dpcm->frac_period_rest + dpcm->rate - 1) / dpcm->rate;
add_timer(&dpcm->timer);
}
static void dummy_systimer_update(struct dummy_systimer_pcm *dpcm)
{
unsigned long delta;
delta = jiffies - dpcm->base_time;
if (!delta)
return;
dpcm->base_time += delta;
delta *= dpcm->rate;
dpcm->frac_pos += delta;
while (dpcm->frac_pos >= dpcm->frac_buffer_size)
dpcm->frac_pos -= dpcm->frac_buffer_size;
while (dpcm->frac_period_rest <= delta) {
dpcm->elapsed++;
dpcm->frac_period_rest += dpcm->frac_period_size;
}
dpcm->frac_period_rest -= delta;
}
static int dummy_systimer_start(struct snd_pcm_substream *substream)
{
struct dummy_systimer_pcm *dpcm = substream->runtime->private_data;
spin_lock(&dpcm->lock);
dpcm->base_time = jiffies;
dummy_systimer_rearm(dpcm);
spin_unlock(&dpcm->lock);
return 0;
}
static int dummy_systimer_stop(struct snd_pcm_substream *substream)
{
struct dummy_systimer_pcm *dpcm = substream->runtime->private_data;
spin_lock(&dpcm->lock);
del_timer(&dpcm->timer);
spin_unlock(&dpcm->lock);
return 0;
}
static int dummy_systimer_prepare(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct dummy_systimer_pcm *dpcm = runtime->private_data;
dpcm->frac_pos = 0;
dpcm->rate = runtime->rate;
dpcm->frac_buffer_size = runtime->buffer_size * HZ;
dpcm->frac_period_size = runtime->period_size * HZ;
dpcm->frac_period_rest = dpcm->frac_period_size;
dpcm->elapsed = 0;
return 0;
}
static void dummy_systimer_callback(unsigned long data)
{
struct dummy_systimer_pcm *dpcm = (struct dummy_systimer_pcm *)data;
unsigned long flags;
int elapsed = 0;
spin_lock_irqsave(&dpcm->lock, flags);
dummy_systimer_update(dpcm);
dummy_systimer_rearm(dpcm);
elapsed = dpcm->elapsed;
dpcm->elapsed = 0;
spin_unlock_irqrestore(&dpcm->lock, flags);
if (elapsed)
snd_pcm_period_elapsed(dpcm->substream);
}
static snd_pcm_uframes_t
dummy_systimer_pointer(struct snd_pcm_substream *substream)
{
struct dummy_systimer_pcm *dpcm = substream->runtime->private_data;
snd_pcm_uframes_t pos;
spin_lock(&dpcm->lock);
dummy_systimer_update(dpcm);
pos = dpcm->frac_pos / HZ;
spin_unlock(&dpcm->lock);
return pos;
}
static int dummy_systimer_create(struct snd_pcm_substream *substream)
{
struct dummy_systimer_pcm *dpcm;
dpcm = kzalloc(sizeof(*dpcm), GFP_KERNEL);
if (!dpcm)
return -ENOMEM;
substream->runtime->private_data = dpcm;
init_timer(&dpcm->timer);
dpcm->timer.data = (unsigned long) dpcm;
dpcm->timer.function = dummy_systimer_callback;
spin_lock_init(&dpcm->lock);
dpcm->substream = substream;
return 0;
}
static void dummy_systimer_free(struct snd_pcm_substream *substream)
{
kfree(substream->runtime->private_data);
}
static void dummy_hrtimer_pcm_elapsed(unsigned long priv)
{
struct dummy_hrtimer_pcm *dpcm = (struct dummy_hrtimer_pcm *)priv;
if (atomic_read(&dpcm->running))
snd_pcm_period_elapsed(dpcm->substream);
}
static enum hrtimer_restart dummy_hrtimer_callback(struct hrtimer *timer)
{
struct dummy_hrtimer_pcm *dpcm;
dpcm = container_of(timer, struct dummy_hrtimer_pcm, timer);
if (!atomic_read(&dpcm->running))
return HRTIMER_NORESTART;
tasklet_schedule(&dpcm->tasklet);
hrtimer_forward_now(timer, dpcm->period_time);
return HRTIMER_RESTART;
}
static int dummy_hrtimer_start(struct snd_pcm_substream *substream)
{
struct dummy_hrtimer_pcm *dpcm = substream->runtime->private_data;
dpcm->base_time = hrtimer_cb_get_time(&dpcm->timer);
hrtimer_start(&dpcm->timer, dpcm->period_time, HRTIMER_MODE_REL);
atomic_set(&dpcm->running, 1);
return 0;
}
static int dummy_hrtimer_stop(struct snd_pcm_substream *substream)
{
struct dummy_hrtimer_pcm *dpcm = substream->runtime->private_data;
atomic_set(&dpcm->running, 0);
hrtimer_cancel(&dpcm->timer);
return 0;
}
static inline void dummy_hrtimer_sync(struct dummy_hrtimer_pcm *dpcm)
{
tasklet_kill(&dpcm->tasklet);
}
static snd_pcm_uframes_t
dummy_hrtimer_pointer(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct dummy_hrtimer_pcm *dpcm = runtime->private_data;
u64 delta;
u32 pos;
delta = ktime_us_delta(hrtimer_cb_get_time(&dpcm->timer),
dpcm->base_time);
delta = div_u64(delta * runtime->rate + 999999, 1000000);
div_u64_rem(delta, runtime->buffer_size, &pos);
return pos;
}
static int dummy_hrtimer_prepare(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct dummy_hrtimer_pcm *dpcm = runtime->private_data;
unsigned int period, rate;
long sec;
unsigned long nsecs;
dummy_hrtimer_sync(dpcm);
period = runtime->period_size;
rate = runtime->rate;
sec = period / rate;
period %= rate;
nsecs = div_u64((u64)period * 1000000000UL + rate - 1, rate);
dpcm->period_time = ktime_set(sec, nsecs);
return 0;
}
static int dummy_hrtimer_create(struct snd_pcm_substream *substream)
{
struct dummy_hrtimer_pcm *dpcm;
dpcm = kzalloc(sizeof(*dpcm), GFP_KERNEL);
if (!dpcm)
return -ENOMEM;
substream->runtime->private_data = dpcm;
hrtimer_init(&dpcm->timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
dpcm->timer.function = dummy_hrtimer_callback;
dpcm->substream = substream;
atomic_set(&dpcm->running, 0);
tasklet_init(&dpcm->tasklet, dummy_hrtimer_pcm_elapsed,
(unsigned long)dpcm);
return 0;
}
static void dummy_hrtimer_free(struct snd_pcm_substream *substream)
{
struct dummy_hrtimer_pcm *dpcm = substream->runtime->private_data;
dummy_hrtimer_sync(dpcm);
kfree(dpcm);
}
static int dummy_pcm_trigger(struct snd_pcm_substream *substream, int cmd)
{
struct snd_dummy *dummy = snd_pcm_substream_chip(substream);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
return dummy->timer_ops->start(substream);
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
return dummy->timer_ops->stop(substream);
}
return -EINVAL;
}
static int dummy_pcm_prepare(struct snd_pcm_substream *substream)
{
struct snd_dummy *dummy = snd_pcm_substream_chip(substream);
return dummy->timer_ops->prepare(substream);
}
static snd_pcm_uframes_t dummy_pcm_pointer(struct snd_pcm_substream *substream)
{
struct snd_dummy *dummy = snd_pcm_substream_chip(substream);
return dummy->timer_ops->pointer(substream);
}
static int dummy_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
if (fake_buffer) {
substream->runtime->dma_bytes = params_buffer_bytes(hw_params);
return 0;
}
return snd_pcm_lib_malloc_pages(substream,
params_buffer_bytes(hw_params));
}
static int dummy_pcm_hw_free(struct snd_pcm_substream *substream)
{
if (fake_buffer)
return 0;
return snd_pcm_lib_free_pages(substream);
}
static int dummy_pcm_open(struct snd_pcm_substream *substream)
{
struct snd_dummy *dummy = snd_pcm_substream_chip(substream);
struct dummy_model *model = dummy->model;
struct snd_pcm_runtime *runtime = substream->runtime;
int err;
dummy->timer_ops = &dummy_systimer_ops;
#ifdef CONFIG_HIGH_RES_TIMERS
if (hrtimer)
dummy->timer_ops = &dummy_hrtimer_ops;
#endif
err = dummy->timer_ops->create(substream);
if (err < 0)
return err;
runtime->hw = dummy->pcm_hw;
if (substream->pcm->device & 1) {
runtime->hw.info &= ~SNDRV_PCM_INFO_INTERLEAVED;
runtime->hw.info |= SNDRV_PCM_INFO_NONINTERLEAVED;
}
if (substream->pcm->device & 2)
runtime->hw.info &= ~(SNDRV_PCM_INFO_MMAP |
SNDRV_PCM_INFO_MMAP_VALID);
if (model == NULL)
return 0;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
if (model->playback_constraints)
err = model->playback_constraints(substream->runtime);
} else {
if (model->capture_constraints)
err = model->capture_constraints(substream->runtime);
}
if (err < 0) {
dummy->timer_ops->free(substream);
return err;
}
return 0;
}
static int dummy_pcm_close(struct snd_pcm_substream *substream)
{
struct snd_dummy *dummy = snd_pcm_substream_chip(substream);
dummy->timer_ops->free(substream);
return 0;
}
static void free_fake_buffer(void)
{
if (fake_buffer) {
int i;
for (i = 0; i < 2; i++)
if (dummy_page[i]) {
free_page((unsigned long)dummy_page[i]);
dummy_page[i] = NULL;
}
}
}
static int alloc_fake_buffer(void)
{
int i;
if (!fake_buffer)
return 0;
for (i = 0; i < 2; i++) {
dummy_page[i] = (void *)get_zeroed_page(GFP_KERNEL);
if (!dummy_page[i]) {
free_fake_buffer();
return -ENOMEM;
}
}
return 0;
}
static int dummy_pcm_copy(struct snd_pcm_substream *substream,
int channel, snd_pcm_uframes_t pos,
void __user *dst, snd_pcm_uframes_t count)
{
return 0;
}
static int dummy_pcm_silence(struct snd_pcm_substream *substream,
int channel, snd_pcm_uframes_t pos,
snd_pcm_uframes_t count)
{
return 0;
}
static struct page *dummy_pcm_page(struct snd_pcm_substream *substream,
unsigned long offset)
{
return virt_to_page(dummy_page[substream->stream]);
}
static int __devinit snd_card_dummy_pcm(struct snd_dummy *dummy, int device,
int substreams)
{
struct snd_pcm *pcm;
struct snd_pcm_ops *ops;
int err;
err = snd_pcm_new(dummy->card, "Dummy PCM", device,
substreams, substreams, &pcm);
if (err < 0)
return err;
dummy->pcm = pcm;
if (fake_buffer)
ops = &dummy_pcm_ops_no_buf;
else
ops = &dummy_pcm_ops;
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, ops);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE, ops);
pcm->private_data = dummy;
pcm->info_flags = 0;
strcpy(pcm->name, "Dummy PCM");
if (!fake_buffer) {
snd_pcm_lib_preallocate_pages_for_all(pcm,
SNDRV_DMA_TYPE_CONTINUOUS,
snd_dma_continuous_data(GFP_KERNEL),
0, 64*1024);
}
return 0;
}
static int snd_dummy_volume_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 2;
uinfo->value.integer.min = -50;
uinfo->value.integer.max = 100;
return 0;
}
static int snd_dummy_volume_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_dummy *dummy = snd_kcontrol_chip(kcontrol);
int addr = kcontrol->private_value;
spin_lock_irq(&dummy->mixer_lock);
ucontrol->value.integer.value[0] = dummy->mixer_volume[addr][0];
ucontrol->value.integer.value[1] = dummy->mixer_volume[addr][1];
spin_unlock_irq(&dummy->mixer_lock);
return 0;
}
static int snd_dummy_volume_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_dummy *dummy = snd_kcontrol_chip(kcontrol);
int change, addr = kcontrol->private_value;
int left, right;
left = ucontrol->value.integer.value[0];
if (left < -50)
left = -50;
if (left > 100)
left = 100;
right = ucontrol->value.integer.value[1];
if (right < -50)
right = -50;
if (right > 100)
right = 100;
spin_lock_irq(&dummy->mixer_lock);
change = dummy->mixer_volume[addr][0] != left ||
dummy->mixer_volume[addr][1] != right;
dummy->mixer_volume[addr][0] = left;
dummy->mixer_volume[addr][1] = right;
spin_unlock_irq(&dummy->mixer_lock);
return change;
}
static int snd_dummy_capsrc_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_dummy *dummy = snd_kcontrol_chip(kcontrol);
int addr = kcontrol->private_value;
spin_lock_irq(&dummy->mixer_lock);
ucontrol->value.integer.value[0] = dummy->capture_source[addr][0];
ucontrol->value.integer.value[1] = dummy->capture_source[addr][1];
spin_unlock_irq(&dummy->mixer_lock);
return 0;
}
static int snd_dummy_capsrc_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_dummy *dummy = snd_kcontrol_chip(kcontrol);
int change, addr = kcontrol->private_value;
int left, right;
left = ucontrol->value.integer.value[0] & 1;
right = ucontrol->value.integer.value[1] & 1;
spin_lock_irq(&dummy->mixer_lock);
change = dummy->capture_source[addr][0] != left &&
dummy->capture_source[addr][1] != right;
dummy->capture_source[addr][0] = left;
dummy->capture_source[addr][1] = right;
spin_unlock_irq(&dummy->mixer_lock);
return change;
}
static int __devinit snd_card_dummy_new_mixer(struct snd_dummy *dummy)
{
struct snd_card *card = dummy->card;
unsigned int idx;
int err;
spin_lock_init(&dummy->mixer_lock);
strcpy(card->mixername, "Dummy Mixer");
for (idx = 0; idx < ARRAY_SIZE(snd_dummy_controls); idx++) {
err = snd_ctl_add(card, snd_ctl_new1(&snd_dummy_controls[idx], dummy));
if (err < 0)
return err;
}
return 0;
}
static void print_formats(struct snd_dummy *dummy,
struct snd_info_buffer *buffer)
{
int i;
for (i = 0; i < SNDRV_PCM_FORMAT_LAST; i++) {
if (dummy->pcm_hw.formats & (1ULL << i))
snd_iprintf(buffer, " %s", snd_pcm_format_name(i));
}
}
static void print_rates(struct snd_dummy *dummy,
struct snd_info_buffer *buffer)
{
static int rates[] = {
5512, 8000, 11025, 16000, 22050, 32000, 44100, 48000,
64000, 88200, 96000, 176400, 192000,
};
int i;
if (dummy->pcm_hw.rates & SNDRV_PCM_RATE_CONTINUOUS)
snd_iprintf(buffer, " continuous");
if (dummy->pcm_hw.rates & SNDRV_PCM_RATE_KNOT)
snd_iprintf(buffer, " knot");
for (i = 0; i < ARRAY_SIZE(rates); i++)
if (dummy->pcm_hw.rates & (1 << i))
snd_iprintf(buffer, " %d", rates[i]);
}
static void dummy_proc_read(struct snd_info_entry *entry,
struct snd_info_buffer *buffer)
{
struct snd_dummy *dummy = entry->private_data;
int i;
for (i = 0; i < ARRAY_SIZE(fields); i++) {
snd_iprintf(buffer, "%s ", fields[i].name);
if (fields[i].size == sizeof(int))
snd_iprintf(buffer, fields[i].format,
*get_dummy_int_ptr(dummy, fields[i].offset));
else
snd_iprintf(buffer, fields[i].format,
*get_dummy_ll_ptr(dummy, fields[i].offset));
if (!strcmp(fields[i].name, "formats"))
print_formats(dummy, buffer);
else if (!strcmp(fields[i].name, "rates"))
print_rates(dummy, buffer);
snd_iprintf(buffer, "\n");
}
}
static void dummy_proc_write(struct snd_info_entry *entry,
struct snd_info_buffer *buffer)
{
struct snd_dummy *dummy = entry->private_data;
char line[64];
while (!snd_info_get_line(buffer, line, sizeof(line))) {
char item[20];
const char *ptr;
unsigned long long val;
int i;
ptr = snd_info_get_str(item, line, sizeof(item));
for (i = 0; i < ARRAY_SIZE(fields); i++) {
if (!strcmp(item, fields[i].name))
break;
}
if (i >= ARRAY_SIZE(fields))
continue;
snd_info_get_str(item, ptr, sizeof(item));
if (strict_strtoull(item, 0, &val))
continue;
if (fields[i].size == sizeof(int))
*get_dummy_int_ptr(dummy, fields[i].offset) = val;
else
*get_dummy_ll_ptr(dummy, fields[i].offset) = val;
}
}
static void __devinit dummy_proc_init(struct snd_dummy *chip)
{
struct snd_info_entry *entry;
if (!snd_card_proc_new(chip->card, "dummy_pcm", &entry)) {
snd_info_set_text_ops(entry, chip, dummy_proc_read);
entry->c.text.write = dummy_proc_write;
entry->mode |= S_IWUSR;
entry->private_data = chip;
}
}
static int __devinit snd_dummy_probe(struct platform_device *devptr)
{
struct snd_card *card;
struct snd_dummy *dummy;
struct dummy_model *m = NULL, **mdl;
int idx, err;
int dev = devptr->id;
err = snd_card_create(index[dev], id[dev], THIS_MODULE,
sizeof(struct snd_dummy), &card);
if (err < 0)
return err;
dummy = card->private_data;
dummy->card = card;
for (mdl = dummy_models; *mdl && model[dev]; mdl++) {
if (strcmp(model[dev], (*mdl)->name) == 0) {
printk(KERN_INFO
"snd-dummy: Using model '%s' for card %i\n",
(*mdl)->name, card->number);
m = dummy->model = *mdl;
break;
}
}
for (idx = 0; idx < MAX_PCM_DEVICES && idx < pcm_devs[dev]; idx++) {
if (pcm_substreams[dev] < 1)
pcm_substreams[dev] = 1;
if (pcm_substreams[dev] > MAX_PCM_SUBSTREAMS)
pcm_substreams[dev] = MAX_PCM_SUBSTREAMS;
err = snd_card_dummy_pcm(dummy, idx, pcm_substreams[dev]);
if (err < 0)
goto __nodev;
}
dummy->pcm_hw = dummy_pcm_hardware;
if (m) {
if (m->formats)
dummy->pcm_hw.formats = m->formats;
if (m->buffer_bytes_max)
dummy->pcm_hw.buffer_bytes_max = m->buffer_bytes_max;
if (m->period_bytes_min)
dummy->pcm_hw.period_bytes_min = m->period_bytes_min;
if (m->period_bytes_max)
dummy->pcm_hw.period_bytes_max = m->period_bytes_max;
if (m->periods_min)
dummy->pcm_hw.periods_min = m->periods_min;
if (m->periods_max)
dummy->pcm_hw.periods_max = m->periods_max;
if (m->rates)
dummy->pcm_hw.rates = m->rates;
if (m->rate_min)
dummy->pcm_hw.rate_min = m->rate_min;
if (m->rate_max)
dummy->pcm_hw.rate_max = m->rate_max;
if (m->channels_min)
dummy->pcm_hw.channels_min = m->channels_min;
if (m->channels_max)
dummy->pcm_hw.channels_max = m->channels_max;
}
err = snd_card_dummy_new_mixer(dummy);
if (err < 0)
goto __nodev;
strcpy(card->driver, "Dummy");
strcpy(card->shortname, "Dummy");
sprintf(card->longname, "Dummy %i", dev + 1);
dummy_proc_init(dummy);
snd_card_set_dev(card, &devptr->dev);
err = snd_card_register(card);
if (err == 0) {
platform_set_drvdata(devptr, card);
return 0;
}
__nodev:
snd_card_free(card);
return err;
}
static int __devexit snd_dummy_remove(struct platform_device *devptr)
{
snd_card_free(platform_get_drvdata(devptr));
platform_set_drvdata(devptr, NULL);
return 0;
}
static int snd_dummy_suspend(struct device *pdev)
{
struct snd_card *card = dev_get_drvdata(pdev);
struct snd_dummy *dummy = card->private_data;
snd_power_change_state(card, SNDRV_CTL_POWER_D3hot);
snd_pcm_suspend_all(dummy->pcm);
return 0;
}
static int snd_dummy_resume(struct device *pdev)
{
struct snd_card *card = dev_get_drvdata(pdev);
snd_power_change_state(card, SNDRV_CTL_POWER_D0);
return 0;
}
static void snd_dummy_unregister_all(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(devices); ++i)
platform_device_unregister(devices[i]);
platform_driver_unregister(&snd_dummy_driver);
free_fake_buffer();
}
static int __init alsa_card_dummy_init(void)
{
int i, cards, err;
err = platform_driver_register(&snd_dummy_driver);
if (err < 0)
return err;
err = alloc_fake_buffer();
if (err < 0) {
platform_driver_unregister(&snd_dummy_driver);
return err;
}
cards = 0;
for (i = 0; i < SNDRV_CARDS; i++) {
struct platform_device *device;
if (! enable[i])
continue;
device = platform_device_register_simple(SND_DUMMY_DRIVER,
i, NULL, 0);
if (IS_ERR(device))
continue;
if (!platform_get_drvdata(device)) {
platform_device_unregister(device);
continue;
}
devices[i] = device;
cards++;
}
if (!cards) {
#ifdef MODULE
printk(KERN_ERR "Dummy soundcard not found or device busy\n");
#endif
snd_dummy_unregister_all();
return -ENODEV;
}
return 0;
}
static void __exit alsa_card_dummy_exit(void)
{
snd_dummy_unregister_all();
}
