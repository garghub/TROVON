int snd_pcm_format_signed(snd_pcm_format_t format)
{
int val;
if ((INT)format < 0 || (INT)format > (INT)SNDRV_PCM_FORMAT_LAST)
return -EINVAL;
if ((val = pcm_formats[(INT)format].signd) < 0)
return -EINVAL;
return val;
}
int snd_pcm_format_unsigned(snd_pcm_format_t format)
{
int val;
val = snd_pcm_format_signed(format);
if (val < 0)
return val;
return !val;
}
int snd_pcm_format_linear(snd_pcm_format_t format)
{
return snd_pcm_format_signed(format) >= 0;
}
int snd_pcm_format_little_endian(snd_pcm_format_t format)
{
int val;
if ((INT)format < 0 || (INT)format > (INT)SNDRV_PCM_FORMAT_LAST)
return -EINVAL;
if ((val = pcm_formats[(INT)format].le) < 0)
return -EINVAL;
return val;
}
int snd_pcm_format_big_endian(snd_pcm_format_t format)
{
int val;
val = snd_pcm_format_little_endian(format);
if (val < 0)
return val;
return !val;
}
int snd_pcm_format_width(snd_pcm_format_t format)
{
int val;
if ((INT)format < 0 || (INT)format > (INT)SNDRV_PCM_FORMAT_LAST)
return -EINVAL;
if ((val = pcm_formats[(INT)format].width) == 0)
return -EINVAL;
return val;
}
int snd_pcm_format_physical_width(snd_pcm_format_t format)
{
int val;
if ((INT)format < 0 || (INT)format > (INT)SNDRV_PCM_FORMAT_LAST)
return -EINVAL;
if ((val = pcm_formats[(INT)format].phys) == 0)
return -EINVAL;
return val;
}
ssize_t snd_pcm_format_size(snd_pcm_format_t format, size_t samples)
{
int phys_width = snd_pcm_format_physical_width(format);
if (phys_width < 0)
return -EINVAL;
return samples * phys_width / 8;
}
const unsigned char *snd_pcm_format_silence_64(snd_pcm_format_t format)
{
if ((INT)format < 0 || (INT)format > (INT)SNDRV_PCM_FORMAT_LAST)
return NULL;
if (! pcm_formats[(INT)format].phys)
return NULL;
return pcm_formats[(INT)format].silence;
}
int snd_pcm_format_set_silence(snd_pcm_format_t format, void *data, unsigned int samples)
{
int width;
unsigned char *dst, *pat;
if ((INT)format < 0 || (INT)format > (INT)SNDRV_PCM_FORMAT_LAST)
return -EINVAL;
if (samples == 0)
return 0;
width = pcm_formats[(INT)format].phys;
pat = pcm_formats[(INT)format].silence;
if (! width)
return -EINVAL;
if (pcm_formats[(INT)format].signd == 1 || width <= 8) {
unsigned int bytes = samples * width / 8;
memset(data, *pat, bytes);
return 0;
}
width /= 8;
dst = data;
#if 0
while (samples--) {
memcpy(dst, pat, width);
dst += width;
}
#else
switch (width) {
case 2:
while (samples--) {
memcpy(dst, pat, 2);
dst += 2;
}
break;
case 3:
while (samples--) {
memcpy(dst, pat, 3);
dst += 3;
}
break;
case 4:
while (samples--) {
memcpy(dst, pat, 4);
dst += 4;
}
break;
case 8:
while (samples--) {
memcpy(dst, pat, 8);
dst += 8;
}
break;
}
#endif
return 0;
}
int snd_pcm_limit_hw_rates(struct snd_pcm_runtime *runtime)
{
int i;
for (i = 0; i < (int)snd_pcm_known_rates.count; i++) {
if (runtime->hw.rates & (1 << i)) {
runtime->hw.rate_min = snd_pcm_known_rates.list[i];
break;
}
}
for (i = (int)snd_pcm_known_rates.count - 1; i >= 0; i--) {
if (runtime->hw.rates & (1 << i)) {
runtime->hw.rate_max = snd_pcm_known_rates.list[i];
break;
}
}
return 0;
}
unsigned int snd_pcm_rate_to_rate_bit(unsigned int rate)
{
unsigned int i;
for (i = 0; i < snd_pcm_known_rates.count; i++)
if (snd_pcm_known_rates.list[i] == rate)
return 1u << i;
return SNDRV_PCM_RATE_KNOT;
}
