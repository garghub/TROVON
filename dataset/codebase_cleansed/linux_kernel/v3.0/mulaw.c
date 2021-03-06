static inline int val_seg(int val)
{
int r = 0;
val >>= 7;
if (val & 0xf0) {
val >>= 4;
r += 4;
}
if (val & 0x0c) {
val >>= 2;
r += 2;
}
if (val & 0x02)
r += 1;
return r;
}
static unsigned char linear2ulaw(int pcm_val)
{
int mask;
int seg;
unsigned char uval;
if (pcm_val < 0) {
pcm_val = BIAS - pcm_val;
mask = 0x7F;
} else {
pcm_val += BIAS;
mask = 0xFF;
}
if (pcm_val > 0x7FFF)
pcm_val = 0x7FFF;
seg = val_seg(pcm_val);
uval = (seg << 4) | ((pcm_val >> (seg + 3)) & 0xF);
return uval ^ mask;
}
static int ulaw2linear(unsigned char u_val)
{
int t;
u_val = ~u_val;
t = ((u_val & QUANT_MASK) << 3) + BIAS;
t <<= ((unsigned)u_val & SEG_MASK) >> SEG_SHIFT;
return ((u_val & SIGN_BIT) ? (BIAS - t) : (t - BIAS));
}
static inline void cvt_s16_to_native(struct mulaw_priv *data,
unsigned char *dst, u16 sample)
{
sample ^= data->flip;
if (data->cvt_endian)
sample = swab16(sample);
if (data->native_bytes > data->copy_bytes)
memset(dst, 0, data->native_bytes);
memcpy(dst + data->native_ofs, (char *)&sample + data->copy_ofs,
data->copy_bytes);
}
static void mulaw_decode(struct snd_pcm_plugin *plugin,
const struct snd_pcm_plugin_channel *src_channels,
struct snd_pcm_plugin_channel *dst_channels,
snd_pcm_uframes_t frames)
{
struct mulaw_priv *data = (struct mulaw_priv *)plugin->extra_data;
int channel;
int nchannels = plugin->src_format.channels;
for (channel = 0; channel < nchannels; ++channel) {
char *src;
char *dst;
int src_step, dst_step;
snd_pcm_uframes_t frames1;
if (!src_channels[channel].enabled) {
if (dst_channels[channel].wanted)
snd_pcm_area_silence(&dst_channels[channel].area, 0, frames, plugin->dst_format.format);
dst_channels[channel].enabled = 0;
continue;
}
dst_channels[channel].enabled = 1;
src = src_channels[channel].area.addr + src_channels[channel].area.first / 8;
dst = dst_channels[channel].area.addr + dst_channels[channel].area.first / 8;
src_step = src_channels[channel].area.step / 8;
dst_step = dst_channels[channel].area.step / 8;
frames1 = frames;
while (frames1-- > 0) {
signed short sample = ulaw2linear(*src);
cvt_s16_to_native(data, dst, sample);
src += src_step;
dst += dst_step;
}
}
}
static inline signed short cvt_native_to_s16(struct mulaw_priv *data,
unsigned char *src)
{
u16 sample = 0;
memcpy((char *)&sample + data->copy_ofs, src + data->native_ofs,
data->copy_bytes);
if (data->cvt_endian)
sample = swab16(sample);
sample ^= data->flip;
return (signed short)sample;
}
static void mulaw_encode(struct snd_pcm_plugin *plugin,
const struct snd_pcm_plugin_channel *src_channels,
struct snd_pcm_plugin_channel *dst_channels,
snd_pcm_uframes_t frames)
{
struct mulaw_priv *data = (struct mulaw_priv *)plugin->extra_data;
int channel;
int nchannels = plugin->src_format.channels;
for (channel = 0; channel < nchannels; ++channel) {
char *src;
char *dst;
int src_step, dst_step;
snd_pcm_uframes_t frames1;
if (!src_channels[channel].enabled) {
if (dst_channels[channel].wanted)
snd_pcm_area_silence(&dst_channels[channel].area, 0, frames, plugin->dst_format.format);
dst_channels[channel].enabled = 0;
continue;
}
dst_channels[channel].enabled = 1;
src = src_channels[channel].area.addr + src_channels[channel].area.first / 8;
dst = dst_channels[channel].area.addr + dst_channels[channel].area.first / 8;
src_step = src_channels[channel].area.step / 8;
dst_step = dst_channels[channel].area.step / 8;
frames1 = frames;
while (frames1-- > 0) {
signed short sample = cvt_native_to_s16(data, src);
*dst = linear2ulaw(sample);
src += src_step;
dst += dst_step;
}
}
}
static snd_pcm_sframes_t mulaw_transfer(struct snd_pcm_plugin *plugin,
const struct snd_pcm_plugin_channel *src_channels,
struct snd_pcm_plugin_channel *dst_channels,
snd_pcm_uframes_t frames)
{
struct mulaw_priv *data;
if (snd_BUG_ON(!plugin || !src_channels || !dst_channels))
return -ENXIO;
if (frames == 0)
return 0;
#ifdef CONFIG_SND_DEBUG
{
unsigned int channel;
for (channel = 0; channel < plugin->src_format.channels; channel++) {
if (snd_BUG_ON(src_channels[channel].area.first % 8 ||
src_channels[channel].area.step % 8))
return -ENXIO;
if (snd_BUG_ON(dst_channels[channel].area.first % 8 ||
dst_channels[channel].area.step % 8))
return -ENXIO;
}
}
#endif
data = (struct mulaw_priv *)plugin->extra_data;
data->func(plugin, src_channels, dst_channels, frames);
return frames;
}
static void init_data(struct mulaw_priv *data, snd_pcm_format_t format)
{
#ifdef SNDRV_LITTLE_ENDIAN
data->cvt_endian = snd_pcm_format_big_endian(format) > 0;
#else
data->cvt_endian = snd_pcm_format_little_endian(format) > 0;
#endif
if (!snd_pcm_format_signed(format))
data->flip = 0x8000;
data->native_bytes = snd_pcm_format_physical_width(format) / 8;
data->copy_bytes = data->native_bytes < 2 ? 1 : 2;
if (snd_pcm_format_little_endian(format)) {
data->native_ofs = data->native_bytes - data->copy_bytes;
data->copy_ofs = 2 - data->copy_bytes;
} else {
data->native_ofs = data->native_bytes -
snd_pcm_format_width(format) / 8;
}
}
int snd_pcm_plugin_build_mulaw(struct snd_pcm_substream *plug,
struct snd_pcm_plugin_format *src_format,
struct snd_pcm_plugin_format *dst_format,
struct snd_pcm_plugin **r_plugin)
{
int err;
struct mulaw_priv *data;
struct snd_pcm_plugin *plugin;
struct snd_pcm_plugin_format *format;
mulaw_f func;
if (snd_BUG_ON(!r_plugin))
return -ENXIO;
*r_plugin = NULL;
if (snd_BUG_ON(src_format->rate != dst_format->rate))
return -ENXIO;
if (snd_BUG_ON(src_format->channels != dst_format->channels))
return -ENXIO;
if (dst_format->format == SNDRV_PCM_FORMAT_MU_LAW) {
format = src_format;
func = mulaw_encode;
}
else if (src_format->format == SNDRV_PCM_FORMAT_MU_LAW) {
format = dst_format;
func = mulaw_decode;
}
else {
snd_BUG();
return -EINVAL;
}
if (snd_BUG_ON(!snd_pcm_format_linear(format->format)))
return -ENXIO;
err = snd_pcm_plugin_build(plug, "Mu-Law<->linear conversion",
src_format, dst_format,
sizeof(struct mulaw_priv), &plugin);
if (err < 0)
return err;
data = (struct mulaw_priv *)plugin->extra_data;
data->func = func;
init_data(data, format->format);
plugin->transfer = mulaw_transfer;
*r_plugin = plugin;
return 0;
}
