static inline u32 hsw_mixer_to_ipc(unsigned int value)
{
if (value >= ARRAY_SIZE(volume_map))
return volume_map[0];
else
return volume_map[value];
}
static inline unsigned int hsw_ipc_to_mixer(u32 value)
{
int i;
for (i = 0; i < ARRAY_SIZE(volume_map); i++) {
if (volume_map[i] >= value)
return i;
}
return i - 1;
}
static int hsw_stream_volume_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_platform *platform = snd_soc_kcontrol_platform(kcontrol);
struct soc_mixer_control *mc =
(struct soc_mixer_control *)kcontrol->private_value;
struct hsw_priv_data *pdata =
snd_soc_platform_get_drvdata(platform);
struct hsw_pcm_data *pcm_data;
struct sst_hsw *hsw = pdata->hsw;
u32 volume;
int dai, stream;
dai = mod_map[mc->reg].dai_id;
stream = mod_map[mc->reg].stream;
pcm_data = &pdata->pcm[dai][stream];
mutex_lock(&pcm_data->mutex);
pm_runtime_get_sync(pdata->dev);
if (!pcm_data->stream) {
pcm_data->volume[0] =
hsw_mixer_to_ipc(ucontrol->value.integer.value[0]);
pcm_data->volume[1] =
hsw_mixer_to_ipc(ucontrol->value.integer.value[1]);
pm_runtime_mark_last_busy(pdata->dev);
pm_runtime_put_autosuspend(pdata->dev);
mutex_unlock(&pcm_data->mutex);
return 0;
}
if (ucontrol->value.integer.value[0] ==
ucontrol->value.integer.value[1]) {
volume = hsw_mixer_to_ipc(ucontrol->value.integer.value[0]);
sst_hsw_stream_set_volume(hsw, pcm_data->stream, 0, SST_HSW_CHANNELS_ALL, volume);
} else {
volume = hsw_mixer_to_ipc(ucontrol->value.integer.value[0]);
sst_hsw_stream_set_volume(hsw, pcm_data->stream, 0, 0, volume);
volume = hsw_mixer_to_ipc(ucontrol->value.integer.value[1]);
sst_hsw_stream_set_volume(hsw, pcm_data->stream, 0, 1, volume);
}
pm_runtime_mark_last_busy(pdata->dev);
pm_runtime_put_autosuspend(pdata->dev);
mutex_unlock(&pcm_data->mutex);
return 0;
}
static int hsw_stream_volume_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_platform *platform = snd_soc_kcontrol_platform(kcontrol);
struct soc_mixer_control *mc =
(struct soc_mixer_control *)kcontrol->private_value;
struct hsw_priv_data *pdata =
snd_soc_platform_get_drvdata(platform);
struct hsw_pcm_data *pcm_data;
struct sst_hsw *hsw = pdata->hsw;
u32 volume;
int dai, stream;
dai = mod_map[mc->reg].dai_id;
stream = mod_map[mc->reg].stream;
pcm_data = &pdata->pcm[dai][stream];
mutex_lock(&pcm_data->mutex);
pm_runtime_get_sync(pdata->dev);
if (!pcm_data->stream) {
ucontrol->value.integer.value[0] =
hsw_ipc_to_mixer(pcm_data->volume[0]);
ucontrol->value.integer.value[1] =
hsw_ipc_to_mixer(pcm_data->volume[1]);
pm_runtime_mark_last_busy(pdata->dev);
pm_runtime_put_autosuspend(pdata->dev);
mutex_unlock(&pcm_data->mutex);
return 0;
}
sst_hsw_stream_get_volume(hsw, pcm_data->stream, 0, 0, &volume);
ucontrol->value.integer.value[0] = hsw_ipc_to_mixer(volume);
sst_hsw_stream_get_volume(hsw, pcm_data->stream, 0, 1, &volume);
ucontrol->value.integer.value[1] = hsw_ipc_to_mixer(volume);
pm_runtime_mark_last_busy(pdata->dev);
pm_runtime_put_autosuspend(pdata->dev);
mutex_unlock(&pcm_data->mutex);
return 0;
}
static int hsw_volume_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_platform *platform = snd_soc_kcontrol_platform(kcontrol);
struct hsw_priv_data *pdata = snd_soc_platform_get_drvdata(platform);
struct sst_hsw *hsw = pdata->hsw;
u32 volume;
pm_runtime_get_sync(pdata->dev);
if (ucontrol->value.integer.value[0] ==
ucontrol->value.integer.value[1]) {
volume = hsw_mixer_to_ipc(ucontrol->value.integer.value[0]);
sst_hsw_mixer_set_volume(hsw, 0, SST_HSW_CHANNELS_ALL, volume);
} else {
volume = hsw_mixer_to_ipc(ucontrol->value.integer.value[0]);
sst_hsw_mixer_set_volume(hsw, 0, 0, volume);
volume = hsw_mixer_to_ipc(ucontrol->value.integer.value[1]);
sst_hsw_mixer_set_volume(hsw, 0, 1, volume);
}
pm_runtime_mark_last_busy(pdata->dev);
pm_runtime_put_autosuspend(pdata->dev);
return 0;
}
static int hsw_volume_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_platform *platform = snd_soc_kcontrol_platform(kcontrol);
struct hsw_priv_data *pdata = snd_soc_platform_get_drvdata(platform);
struct sst_hsw *hsw = pdata->hsw;
unsigned int volume = 0;
pm_runtime_get_sync(pdata->dev);
sst_hsw_mixer_get_volume(hsw, 0, 0, &volume);
ucontrol->value.integer.value[0] = hsw_ipc_to_mixer(volume);
sst_hsw_mixer_get_volume(hsw, 0, 1, &volume);
ucontrol->value.integer.value[1] = hsw_ipc_to_mixer(volume);
pm_runtime_mark_last_busy(pdata->dev);
pm_runtime_put_autosuspend(pdata->dev);
return 0;
}
static int hsw_waves_switch_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_platform *platform = snd_soc_kcontrol_platform(kcontrol);
struct hsw_priv_data *pdata = snd_soc_platform_get_drvdata(platform);
struct sst_hsw *hsw = pdata->hsw;
enum sst_hsw_module_id id = SST_HSW_MODULE_WAVES;
ucontrol->value.integer.value[0] =
(sst_hsw_is_module_active(hsw, id) ||
sst_hsw_is_module_enabled_rtd3(hsw, id));
return 0;
}
static int hsw_waves_switch_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_platform *platform = snd_soc_kcontrol_platform(kcontrol);
struct hsw_priv_data *pdata = snd_soc_platform_get_drvdata(platform);
struct sst_hsw *hsw = pdata->hsw;
int ret = 0;
enum sst_hsw_module_id id = SST_HSW_MODULE_WAVES;
bool switch_on = (bool)ucontrol->value.integer.value[0];
if (sst_hsw_is_module_loaded(hsw, id)) {
if (switch_on == sst_hsw_is_module_active(hsw, id))
return 0;
if (switch_on)
ret = sst_hsw_module_enable(hsw, id, 0);
else
ret = sst_hsw_module_disable(hsw, id, 0);
} else {
if (switch_on == sst_hsw_is_module_enabled_rtd3(hsw, id))
return 0;
if (switch_on)
sst_hsw_set_module_enabled_rtd3(hsw, id);
else
sst_hsw_set_module_disabled_rtd3(hsw, id);
}
return ret;
}
static int hsw_waves_param_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_platform *platform = snd_soc_kcontrol_platform(kcontrol);
struct hsw_priv_data *pdata = snd_soc_platform_get_drvdata(platform);
struct sst_hsw *hsw = pdata->hsw;
return sst_hsw_load_param_line(hsw, ucontrol->value.bytes.data);
}
static int hsw_waves_param_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_platform *platform = snd_soc_kcontrol_platform(kcontrol);
struct hsw_priv_data *pdata = snd_soc_platform_get_drvdata(platform);
struct sst_hsw *hsw = pdata->hsw;
int ret;
enum sst_hsw_module_id id = SST_HSW_MODULE_WAVES;
int param_id = ucontrol->value.bytes.data[0];
int param_size = WAVES_PARAM_COUNT;
if (param_id == 0xFF) {
sst_hsw_reset_param_buf(hsw);
return 0;
}
ret = sst_hsw_store_param_line(hsw, ucontrol->value.bytes.data);
if (ret < 0)
return ret;
if (sst_hsw_is_module_active(hsw, id))
ret = sst_hsw_module_set_param(hsw, id, 0, param_id,
param_size, ucontrol->value.bytes.data);
return ret;
}
static int create_adsp_page_table(struct snd_pcm_substream *substream,
struct hsw_priv_data *pdata, struct snd_soc_pcm_runtime *rtd,
unsigned char *dma_area, size_t size, int pcm)
{
struct snd_dma_buffer *dmab = snd_pcm_get_dma_buf(substream);
int i, pages, stream = substream->stream;
pages = snd_sgbuf_aligned_pages(size);
dev_dbg(rtd->dev, "generating page table for %p size 0x%zx pages %d\n",
dma_area, size, pages);
for (i = 0; i < pages; i++) {
u32 idx = (((i << 2) + i)) >> 1;
u32 pfn = snd_sgbuf_get_addr(dmab, i * PAGE_SIZE) >> PAGE_SHIFT;
u32 *pg_table;
dev_dbg(rtd->dev, "pfn i %i idx %d pfn %x\n", i, idx, pfn);
pg_table = (u32 *)(pdata->dmab[pcm][stream].area + idx);
if (i & 1)
*pg_table |= (pfn << 4);
else
*pg_table |= pfn;
}
return 0;
}
static int hsw_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_pcm_runtime *runtime = substream->runtime;
struct hsw_priv_data *pdata =
snd_soc_platform_get_drvdata(rtd->platform);
struct hsw_pcm_data *pcm_data;
struct sst_hsw *hsw = pdata->hsw;
struct sst_module *module_data;
struct sst_dsp *dsp;
struct snd_dma_buffer *dmab;
enum sst_hsw_stream_type stream_type;
enum sst_hsw_stream_path_id path_id;
u32 rate, bits, map, pages, module_id;
u8 channels;
int ret, dai;
dai = mod_map[rtd->cpu_dai->id].dai_id;
pcm_data = &pdata->pcm[dai][substream->stream];
if (pcm_data->allocated) {
ret = sst_hsw_stream_reset(hsw, pcm_data->stream);
if (ret < 0)
dev_dbg(rtd->dev, "error: reset stream failed %d\n",
ret);
ret = sst_hsw_stream_free(hsw, pcm_data->stream);
if (ret < 0) {
dev_dbg(rtd->dev, "error: free stream failed %d\n",
ret);
return ret;
}
pcm_data->allocated = false;
pcm_data->stream = sst_hsw_stream_new(hsw, rtd->cpu_dai->id,
hsw_notify_pointer, pcm_data);
if (pcm_data->stream == NULL) {
dev_err(rtd->dev, "error: failed to create stream\n");
return -EINVAL;
}
}
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
path_id = SST_HSW_STREAM_PATH_SSP0_OUT;
else
path_id = SST_HSW_STREAM_PATH_SSP0_IN;
switch (rtd->cpu_dai->id) {
case 0:
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
stream_type = SST_HSW_STREAM_TYPE_SYSTEM;
module_id = SST_HSW_MODULE_PCM_SYSTEM;
}
else {
stream_type = SST_HSW_STREAM_TYPE_CAPTURE;
module_id = SST_HSW_MODULE_PCM_CAPTURE;
}
break;
case 1:
case 2:
stream_type = SST_HSW_STREAM_TYPE_RENDER;
module_id = SST_HSW_MODULE_PCM;
break;
case 3:
stream_type = SST_HSW_STREAM_TYPE_LOOPBACK;
path_id = SST_HSW_STREAM_PATH_SSP0_OUT;
module_id = SST_HSW_MODULE_PCM_REFERENCE;
break;
default:
dev_err(rtd->dev, "error: invalid DAI ID %d\n",
rtd->cpu_dai->id);
return -EINVAL;
};
ret = sst_hsw_stream_format(hsw, pcm_data->stream,
path_id, stream_type, SST_HSW_STREAM_FORMAT_PCM_FORMAT);
if (ret < 0) {
dev_err(rtd->dev, "error: failed to set format %d\n", ret);
return ret;
}
rate = params_rate(params);
ret = sst_hsw_stream_set_rate(hsw, pcm_data->stream, rate);
if (ret < 0) {
dev_err(rtd->dev, "error: could not set rate %d\n", rate);
return ret;
}
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
bits = SST_HSW_DEPTH_16BIT;
sst_hsw_stream_set_valid(hsw, pcm_data->stream, 16);
break;
case SNDRV_PCM_FORMAT_S24_LE:
bits = SST_HSW_DEPTH_32BIT;
sst_hsw_stream_set_valid(hsw, pcm_data->stream, 24);
break;
case SNDRV_PCM_FORMAT_S8:
bits = SST_HSW_DEPTH_8BIT;
sst_hsw_stream_set_valid(hsw, pcm_data->stream, 8);
break;
case SNDRV_PCM_FORMAT_S32_LE:
bits = SST_HSW_DEPTH_32BIT;
sst_hsw_stream_set_valid(hsw, pcm_data->stream, 32);
break;
default:
dev_err(rtd->dev, "error: invalid format %d\n",
params_format(params));
return -EINVAL;
}
ret = sst_hsw_stream_set_bits(hsw, pcm_data->stream, bits);
if (ret < 0) {
dev_err(rtd->dev, "error: could not set bits %d\n", bits);
return ret;
}
channels = params_channels(params);
map = create_channel_map(SST_HSW_CHANNEL_CONFIG_STEREO);
sst_hsw_stream_set_map_config(hsw, pcm_data->stream,
map, SST_HSW_CHANNEL_CONFIG_STEREO);
ret = sst_hsw_stream_set_channels(hsw, pcm_data->stream, channels);
if (ret < 0) {
dev_err(rtd->dev, "error: could not set channels %d\n",
channels);
return ret;
}
ret = snd_pcm_lib_malloc_pages(substream, params_buffer_bytes(params));
if (ret < 0) {
dev_err(rtd->dev, "error: could not allocate %d bytes for PCM %d\n",
params_buffer_bytes(params), ret);
return ret;
}
dmab = snd_pcm_get_dma_buf(substream);
ret = create_adsp_page_table(substream, pdata, rtd, runtime->dma_area,
runtime->dma_bytes, rtd->cpu_dai->id);
if (ret < 0)
return ret;
sst_hsw_stream_set_style(hsw, pcm_data->stream,
SST_HSW_INTERLEAVING_PER_CHANNEL);
if (runtime->dma_bytes % PAGE_SIZE)
pages = (runtime->dma_bytes / PAGE_SIZE) + 1;
else
pages = runtime->dma_bytes / PAGE_SIZE;
ret = sst_hsw_stream_buffer(hsw, pcm_data->stream,
pdata->dmab[rtd->cpu_dai->id][substream->stream].addr,
pages, runtime->dma_bytes, 0,
snd_sgbuf_get_addr(dmab, 0) >> PAGE_SHIFT);
if (ret < 0) {
dev_err(rtd->dev, "error: failed to set DMA buffer %d\n", ret);
return ret;
}
dsp = sst_hsw_get_dsp(hsw);
module_data = sst_module_get_from_id(dsp, module_id);
if (module_data == NULL) {
dev_err(rtd->dev, "error: failed to get module config\n");
return -EINVAL;
}
sst_hsw_stream_set_module_info(hsw, pcm_data->stream,
pcm_data->runtime);
ret = sst_hsw_stream_commit(hsw, pcm_data->stream);
if (ret < 0) {
dev_err(rtd->dev, "error: failed to commit stream %d\n", ret);
return ret;
}
if (!pcm_data->allocated) {
sst_hsw_stream_set_volume(hsw, pcm_data->stream, 0,
0, pcm_data->volume[0]);
sst_hsw_stream_set_volume(hsw, pcm_data->stream, 0,
1, pcm_data->volume[1]);
pcm_data->allocated = true;
}
ret = sst_hsw_stream_pause(hsw, pcm_data->stream, 1);
if (ret < 0)
dev_err(rtd->dev, "error: failed to pause %d\n", ret);
return 0;
}
static int hsw_pcm_hw_free(struct snd_pcm_substream *substream)
{
snd_pcm_lib_free_pages(substream);
return 0;
}
static int hsw_pcm_trigger(struct snd_pcm_substream *substream, int cmd)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct hsw_priv_data *pdata =
snd_soc_platform_get_drvdata(rtd->platform);
struct hsw_pcm_data *pcm_data;
struct sst_hsw_stream *sst_stream;
struct sst_hsw *hsw = pdata->hsw;
struct snd_pcm_runtime *runtime = substream->runtime;
snd_pcm_uframes_t pos;
int dai;
dai = mod_map[rtd->cpu_dai->id].dai_id;
pcm_data = &pdata->pcm[dai][substream->stream];
sst_stream = pcm_data->stream;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
sst_hsw_stream_set_silence_start(hsw, sst_stream, false);
sst_hsw_stream_resume(hsw, pcm_data->stream, 0);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
sst_hsw_stream_set_silence_start(hsw, sst_stream, false);
sst_hsw_stream_pause(hsw, pcm_data->stream, 0);
break;
case SNDRV_PCM_TRIGGER_DRAIN:
pos = runtime->control->appl_ptr % runtime->buffer_size;
sst_hsw_stream_set_old_position(hsw, pcm_data->stream, pos);
sst_hsw_stream_set_silence_start(hsw, sst_stream, true);
break;
default:
break;
}
return 0;
}
static u32 hsw_notify_pointer(struct sst_hsw_stream *stream, void *data)
{
struct hsw_pcm_data *pcm_data = data;
struct snd_pcm_substream *substream = pcm_data->substream;
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct hsw_priv_data *pdata =
snd_soc_platform_get_drvdata(rtd->platform);
struct sst_hsw *hsw = pdata->hsw;
u32 pos;
snd_pcm_uframes_t position = bytes_to_frames(runtime,
sst_hsw_get_dsp_position(hsw, pcm_data->stream));
unsigned char *dma_area = runtime->dma_area;
snd_pcm_uframes_t dma_frames =
bytes_to_frames(runtime, runtime->dma_bytes);
snd_pcm_uframes_t old_position;
ssize_t samples;
pos = frames_to_bytes(runtime,
(runtime->control->appl_ptr % runtime->buffer_size));
dev_vdbg(rtd->dev, "PCM: App pointer %d bytes\n", pos);
if (dma_area == NULL || dma_frames <= 0
|| (substream->stream == SNDRV_PCM_STREAM_CAPTURE)
|| !sst_hsw_stream_get_silence_start(hsw, stream)) {
snd_pcm_period_elapsed(substream);
return pos;
}
old_position = sst_hsw_stream_get_old_position(hsw, stream);
if (position > old_position) {
if (position < dma_frames) {
samples = SST_SAMPLES(runtime, position - old_position);
snd_pcm_format_set_silence(runtime->format,
SST_OLD_POSITION(dma_area,
runtime, old_position),
samples);
} else
dev_err(rtd->dev, "PCM: position is wrong\n");
} else {
if (old_position < dma_frames) {
samples = SST_SAMPLES(runtime,
dma_frames - old_position);
snd_pcm_format_set_silence(runtime->format,
SST_OLD_POSITION(dma_area,
runtime, old_position),
samples);
} else
dev_err(rtd->dev, "PCM: dma_bytes is wrong\n");
if (position < dma_frames) {
samples = SST_SAMPLES(runtime, position);
snd_pcm_format_set_silence(runtime->format,
dma_area, samples);
} else
dev_err(rtd->dev, "PCM: position is wrong\n");
}
sst_hsw_stream_set_old_position(hsw, stream, position);
snd_pcm_period_elapsed(substream);
return pos;
}
static snd_pcm_uframes_t hsw_pcm_pointer(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_pcm_runtime *runtime = substream->runtime;
struct hsw_priv_data *pdata =
snd_soc_platform_get_drvdata(rtd->platform);
struct hsw_pcm_data *pcm_data;
struct sst_hsw *hsw = pdata->hsw;
snd_pcm_uframes_t offset;
uint64_t ppos;
u32 position;
int dai;
dai = mod_map[rtd->cpu_dai->id].dai_id;
pcm_data = &pdata->pcm[dai][substream->stream];
position = sst_hsw_get_dsp_position(hsw, pcm_data->stream);
offset = bytes_to_frames(runtime, position);
ppos = sst_hsw_get_dsp_presentation_position(hsw, pcm_data->stream);
dev_vdbg(rtd->dev, "PCM: DMA pointer %du bytes, pos %llu\n",
position, ppos);
return offset;
}
static int hsw_pcm_open(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct hsw_priv_data *pdata =
snd_soc_platform_get_drvdata(rtd->platform);
struct hsw_pcm_data *pcm_data;
struct sst_hsw *hsw = pdata->hsw;
int dai;
dai = mod_map[rtd->cpu_dai->id].dai_id;
pcm_data = &pdata->pcm[dai][substream->stream];
mutex_lock(&pcm_data->mutex);
pm_runtime_get_sync(pdata->dev);
pcm_data->substream = substream;
snd_soc_set_runtime_hwparams(substream, &hsw_pcm_hardware);
pcm_data->stream = sst_hsw_stream_new(hsw, rtd->cpu_dai->id,
hsw_notify_pointer, pcm_data);
if (pcm_data->stream == NULL) {
dev_err(rtd->dev, "error: failed to create stream\n");
pm_runtime_mark_last_busy(pdata->dev);
pm_runtime_put_autosuspend(pdata->dev);
mutex_unlock(&pcm_data->mutex);
return -EINVAL;
}
mutex_unlock(&pcm_data->mutex);
return 0;
}
static int hsw_pcm_close(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct hsw_priv_data *pdata =
snd_soc_platform_get_drvdata(rtd->platform);
struct hsw_pcm_data *pcm_data;
struct sst_hsw *hsw = pdata->hsw;
int ret, dai;
dai = mod_map[rtd->cpu_dai->id].dai_id;
pcm_data = &pdata->pcm[dai][substream->stream];
mutex_lock(&pcm_data->mutex);
ret = sst_hsw_stream_reset(hsw, pcm_data->stream);
if (ret < 0) {
dev_dbg(rtd->dev, "error: reset stream failed %d\n", ret);
goto out;
}
ret = sst_hsw_stream_free(hsw, pcm_data->stream);
if (ret < 0) {
dev_dbg(rtd->dev, "error: free stream failed %d\n", ret);
goto out;
}
pcm_data->allocated = 0;
pcm_data->stream = NULL;
out:
pm_runtime_mark_last_busy(pdata->dev);
pm_runtime_put_autosuspend(pdata->dev);
mutex_unlock(&pcm_data->mutex);
return ret;
}
static int hsw_pcm_create_modules(struct hsw_priv_data *pdata)
{
struct sst_hsw *hsw = pdata->hsw;
struct hsw_pcm_data *pcm_data;
int i;
for (i = 0; i < ARRAY_SIZE(mod_map); i++) {
pcm_data = &pdata->pcm[mod_map[i].dai_id][mod_map[i].stream];
pcm_data->runtime = sst_hsw_runtime_module_create(hsw,
mod_map[i].mod_id, pcm_data->persistent_offset);
if (pcm_data->runtime == NULL)
goto err;
pcm_data->persistent_offset =
pcm_data->runtime->persistent_offset;
}
if (sst_hsw_is_module_loaded(hsw, SST_HSW_MODULE_WAVES)) {
pdata->runtime_waves = sst_hsw_runtime_module_create(hsw,
SST_HSW_MODULE_WAVES, 0);
if (pdata->runtime_waves == NULL)
goto err;
}
return 0;
err:
for (--i; i >= 0; i--) {
pcm_data = &pdata->pcm[mod_map[i].dai_id][mod_map[i].stream];
sst_hsw_runtime_module_free(pcm_data->runtime);
}
return -ENODEV;
}
static void hsw_pcm_free_modules(struct hsw_priv_data *pdata)
{
struct sst_hsw *hsw = pdata->hsw;
struct hsw_pcm_data *pcm_data;
int i;
for (i = 0; i < ARRAY_SIZE(mod_map); i++) {
pcm_data = &pdata->pcm[mod_map[i].dai_id][mod_map[i].stream];
if (pcm_data->runtime){
sst_hsw_runtime_module_free(pcm_data->runtime);
pcm_data->runtime = NULL;
}
}
if (sst_hsw_is_module_loaded(hsw, SST_HSW_MODULE_WAVES) &&
pdata->runtime_waves) {
sst_hsw_runtime_module_free(pdata->runtime_waves);
pdata->runtime_waves = NULL;
}
}
static int hsw_pcm_new(struct snd_soc_pcm_runtime *rtd)
{
struct snd_pcm *pcm = rtd->pcm;
struct snd_soc_platform *platform = rtd->platform;
struct sst_pdata *pdata = dev_get_platdata(platform->dev);
struct hsw_priv_data *priv_data = dev_get_drvdata(platform->dev);
struct device *dev = pdata->dma_dev;
int ret = 0;
if (pcm->streams[SNDRV_PCM_STREAM_PLAYBACK].substream ||
pcm->streams[SNDRV_PCM_STREAM_CAPTURE].substream) {
ret = snd_pcm_lib_preallocate_pages_for_all(pcm,
SNDRV_DMA_TYPE_DEV_SG,
dev,
hsw_pcm_hardware.buffer_bytes_max,
hsw_pcm_hardware.buffer_bytes_max);
if (ret) {
dev_err(rtd->dev, "dma buffer allocation failed %d\n",
ret);
return ret;
}
}
if (pcm->streams[SNDRV_PCM_STREAM_PLAYBACK].substream)
priv_data->pcm[rtd->cpu_dai->id][SNDRV_PCM_STREAM_PLAYBACK].hsw_pcm = pcm;
if (pcm->streams[SNDRV_PCM_STREAM_CAPTURE].substream)
priv_data->pcm[rtd->cpu_dai->id][SNDRV_PCM_STREAM_CAPTURE].hsw_pcm = pcm;
return ret;
}
static int hsw_pcm_probe(struct snd_soc_platform *platform)
{
struct hsw_priv_data *priv_data = snd_soc_platform_get_drvdata(platform);
struct sst_pdata *pdata = dev_get_platdata(platform->dev);
struct device *dma_dev, *dev;
int i, ret = 0;
if (!pdata)
return -ENODEV;
dev = platform->dev;
dma_dev = pdata->dma_dev;
priv_data->hsw = pdata->dsp;
priv_data->dev = platform->dev;
priv_data->pm_state = HSW_PM_STATE_D0;
priv_data->soc_card = platform->component.card;
for (i = 0; i < ARRAY_SIZE(hsw_dais); i++) {
if (hsw_dais[i].playback.channels_min) {
mutex_init(&priv_data->pcm[i][SNDRV_PCM_STREAM_PLAYBACK].mutex);
ret = snd_dma_alloc_pages(SNDRV_DMA_TYPE_DEV, dma_dev,
PAGE_SIZE, &priv_data->dmab[i][0]);
if (ret < 0)
goto err;
}
if (hsw_dais[i].capture.channels_min) {
mutex_init(&priv_data->pcm[i][SNDRV_PCM_STREAM_CAPTURE].mutex);
ret = snd_dma_alloc_pages(SNDRV_DMA_TYPE_DEV, dma_dev,
PAGE_SIZE, &priv_data->dmab[i][1]);
if (ret < 0)
goto err;
}
}
ret = hsw_pcm_create_modules(priv_data);
if (ret < 0)
goto err;
pm_runtime_set_autosuspend_delay(platform->dev,
SST_RUNTIME_SUSPEND_DELAY);
pm_runtime_use_autosuspend(platform->dev);
pm_runtime_enable(platform->dev);
pm_runtime_idle(platform->dev);
return 0;
err:
for (--i; i >= 0; i--) {
if (hsw_dais[i].playback.channels_min)
snd_dma_free_pages(&priv_data->dmab[i][0]);
if (hsw_dais[i].capture.channels_min)
snd_dma_free_pages(&priv_data->dmab[i][1]);
}
return ret;
}
static int hsw_pcm_remove(struct snd_soc_platform *platform)
{
struct hsw_priv_data *priv_data =
snd_soc_platform_get_drvdata(platform);
int i;
pm_runtime_disable(platform->dev);
hsw_pcm_free_modules(priv_data);
for (i = 0; i < ARRAY_SIZE(hsw_dais); i++) {
if (hsw_dais[i].playback.channels_min)
snd_dma_free_pages(&priv_data->dmab[i][0]);
if (hsw_dais[i].capture.channels_min)
snd_dma_free_pages(&priv_data->dmab[i][1]);
}
return 0;
}
static int hsw_pcm_dev_probe(struct platform_device *pdev)
{
struct sst_pdata *sst_pdata = dev_get_platdata(&pdev->dev);
struct hsw_priv_data *priv_data;
int ret;
if (!sst_pdata)
return -EINVAL;
priv_data = devm_kzalloc(&pdev->dev, sizeof(*priv_data), GFP_KERNEL);
if (!priv_data)
return -ENOMEM;
ret = sst_hsw_dsp_init(&pdev->dev, sst_pdata);
if (ret < 0)
return -ENODEV;
priv_data->hsw = sst_pdata->dsp;
platform_set_drvdata(pdev, priv_data);
ret = snd_soc_register_platform(&pdev->dev, &hsw_soc_platform);
if (ret < 0)
goto err_plat;
ret = snd_soc_register_component(&pdev->dev, &hsw_dai_component,
hsw_dais, ARRAY_SIZE(hsw_dais));
if (ret < 0)
goto err_comp;
return 0;
err_comp:
snd_soc_unregister_platform(&pdev->dev);
err_plat:
sst_hsw_dsp_free(&pdev->dev, sst_pdata);
return 0;
}
static int hsw_pcm_dev_remove(struct platform_device *pdev)
{
struct sst_pdata *sst_pdata = dev_get_platdata(&pdev->dev);
snd_soc_unregister_platform(&pdev->dev);
snd_soc_unregister_component(&pdev->dev);
sst_hsw_dsp_free(&pdev->dev, sst_pdata);
return 0;
}
static int hsw_pcm_runtime_idle(struct device *dev)
{
return 0;
}
static int hsw_pcm_suspend(struct device *dev)
{
struct hsw_priv_data *pdata = dev_get_drvdata(dev);
struct sst_hsw *hsw = pdata->hsw;
sst_hsw_dsp_runtime_suspend(hsw);
hsw_pcm_free_modules(pdata);
sst_hsw_dsp_runtime_sleep(hsw);
return 0;
}
static int hsw_pcm_runtime_suspend(struct device *dev)
{
struct hsw_priv_data *pdata = dev_get_drvdata(dev);
struct sst_hsw *hsw = pdata->hsw;
int ret;
if (pdata->pm_state >= HSW_PM_STATE_RTD3)
return 0;
if (sst_hsw_is_module_active(hsw, SST_HSW_MODULE_WAVES)) {
ret = sst_hsw_module_disable(hsw, SST_HSW_MODULE_WAVES, 0);
if (ret < 0)
return ret;
sst_hsw_set_module_enabled_rtd3(hsw, SST_HSW_MODULE_WAVES);
}
hsw_pcm_suspend(dev);
pdata->pm_state = HSW_PM_STATE_RTD3;
return 0;
}
static int hsw_pcm_runtime_resume(struct device *dev)
{
struct hsw_priv_data *pdata = dev_get_drvdata(dev);
struct sst_hsw *hsw = pdata->hsw;
int ret;
if (pdata->pm_state != HSW_PM_STATE_RTD3)
return 0;
ret = sst_hsw_dsp_load(hsw);
if (ret < 0) {
dev_err(dev, "failed to reload %d\n", ret);
return ret;
}
ret = hsw_pcm_create_modules(pdata);
if (ret < 0) {
dev_err(dev, "failed to create modules %d\n", ret);
return ret;
}
ret = sst_hsw_dsp_runtime_resume(hsw);
if (ret < 0)
return ret;
else if (ret == 1)
return 0;
if (sst_hsw_is_module_enabled_rtd3(hsw, SST_HSW_MODULE_WAVES)) {
ret = sst_hsw_module_enable(hsw, SST_HSW_MODULE_WAVES, 0);
if (ret < 0)
return ret;
ret = sst_hsw_launch_param_buf(hsw);
if (ret < 0)
return ret;
sst_hsw_set_module_disabled_rtd3(hsw, SST_HSW_MODULE_WAVES);
}
pdata->pm_state = HSW_PM_STATE_D0;
return ret;
}
static void hsw_pcm_complete(struct device *dev)
{
struct hsw_priv_data *pdata = dev_get_drvdata(dev);
struct sst_hsw *hsw = pdata->hsw;
struct hsw_pcm_data *pcm_data;
int i, err;
if (pdata->pm_state != HSW_PM_STATE_D3)
return;
err = sst_hsw_dsp_load(hsw);
if (err < 0) {
dev_err(dev, "failed to reload %d\n", err);
return;
}
err = hsw_pcm_create_modules(pdata);
if (err < 0) {
dev_err(dev, "failed to create modules %d\n", err);
return;
}
for (i = 0; i < ARRAY_SIZE(mod_map); i++) {
pcm_data = &pdata->pcm[mod_map[i].dai_id][mod_map[i].stream];
if (!pcm_data->substream)
continue;
err = sst_module_runtime_restore(pcm_data->runtime,
&pcm_data->context);
if (err < 0)
dev_err(dev, "failed to restore context for PCM %d\n", i);
}
snd_soc_resume(pdata->soc_card->dev);
err = sst_hsw_dsp_runtime_resume(hsw);
if (err < 0)
return;
else if (err == 1)
return;
pdata->pm_state = HSW_PM_STATE_D0;
return;
}
static int hsw_pcm_prepare(struct device *dev)
{
struct hsw_priv_data *pdata = dev_get_drvdata(dev);
struct hsw_pcm_data *pcm_data;
int i, err;
if (pdata->pm_state == HSW_PM_STATE_D3)
return 0;
else if (pdata->pm_state == HSW_PM_STATE_D0) {
for (i = 0; i < ARRAY_SIZE(mod_map); i++) {
pcm_data = &pdata->pcm[mod_map[i].dai_id][mod_map[i].stream];
if (!pcm_data->substream)
continue;
dev_dbg(dev, "suspending pcm %d\n", i);
snd_pcm_suspend_all(pcm_data->hsw_pcm);
msleep(2);
}
for (i = 0; i < ARRAY_SIZE(mod_map); i++) {
pcm_data = &pdata->pcm[mod_map[i].dai_id][mod_map[i].stream];
if (!pcm_data->substream)
continue;
dev_dbg(dev, "saving context pcm %d\n", i);
err = sst_module_runtime_save(pcm_data->runtime,
&pcm_data->context);
if (err < 0)
dev_err(dev, "failed to save context for PCM %d\n", i);
}
hsw_pcm_suspend(dev);
}
snd_soc_suspend(pdata->soc_card->dev);
snd_soc_poweroff(pdata->soc_card->dev);
pdata->pm_state = HSW_PM_STATE_D3;
return 0;
}
