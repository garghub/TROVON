static inline unsigned char linear2alaw(short int linear)
{
int mask;
int seg;
int pcm_val;
static int seg_end[8] = {
0xFF, 0x1FF, 0x3FF, 0x7FF, 0xFFF, 0x1FFF, 0x3FFF, 0x7FFF
};
pcm_val = linear;
if (pcm_val >= 0) {
mask = AMI_MASK | 0x80;
} else {
mask = AMI_MASK;
pcm_val = -pcm_val;
}
for (seg = 0; seg < 8; seg++) {
if (pcm_val <= seg_end[seg])
break;
}
return ((seg << 4) |
((pcm_val >> ((seg) ? (seg + 3) : 4)) & 0x0F)) ^ mask;
}
static inline short int alaw2linear(unsigned char alaw)
{
int i;
int seg;
alaw ^= AMI_MASK;
i = ((alaw & 0x0F) << 4) + 8 ;
seg = (((int) alaw & 0x70) >> 4);
if (seg)
i = (i + 0x100) << (seg - 1);
return (short int) ((alaw & 0x80) ? i : -i);
}
static inline short int ulaw2linear(unsigned char ulaw)
{
short mu, e, f, y;
static short etab[] = {0, 132, 396, 924, 1980, 4092, 8316, 16764};
mu = 255 - ulaw;
e = (mu & 0x70) / 16;
f = mu & 0x0f;
y = f * (1 << (e + 3));
y += etab[e];
if (mu & 0x80)
y = -y;
return y;
}
static unsigned char linear2ulaw(short sample)
{
static int exp_lut[256] = {
0, 0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3,
4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7};
int sign, exponent, mantissa;
unsigned char ulawbyte;
sign = (sample >> 8) & 0x80;
if (sign != 0)
sample = -sample;
sample = sample + BIAS;
exponent = exp_lut[(sample >> 7) & 0xFF];
mantissa = (sample >> (exponent + 3)) & 0x0F;
ulawbyte = ~(sign | (exponent << 4) | mantissa);
return ulawbyte;
}
static int reverse_bits(int i)
{
int z, j;
z = 0;
for (j = 0; j < 8; j++) {
if ((i & (1 << j)) != 0)
z |= 1 << (7 - j);
}
return z;
}
void dsp_audio_generate_law_tables(void)
{
int i;
for (i = 0; i < 256; i++)
dsp_audio_alaw_to_s32[i] = alaw2linear(reverse_bits(i));
for (i = 0; i < 256; i++)
dsp_audio_ulaw_to_s32[i] = ulaw2linear(reverse_bits(i));
for (i = 0; i < 256; i++) {
dsp_audio_alaw_to_ulaw[i] =
linear2ulaw(dsp_audio_alaw_to_s32[i]);
dsp_audio_ulaw_to_alaw[i] =
linear2alaw(dsp_audio_ulaw_to_s32[i]);
}
}
void
dsp_audio_generate_s2law_table(void)
{
int i;
if (dsp_options & DSP_OPT_ULAW) {
for (i = -32768; i < 32768; i++) {
dsp_audio_s16_to_law[i & 0xffff] =
reverse_bits(linear2ulaw(i));
}
} else {
for (i = -32768; i < 32768; i++) {
dsp_audio_s16_to_law[i & 0xffff] =
reverse_bits(linear2alaw(i));
}
}
}
void
dsp_audio_generate_seven(void)
{
int i, j, k;
u8 spl;
u8 sorted_alaw[256];
for (i = 0; i < 256; i++) {
j = 0;
for (k = 0; k < 256; k++) {
if (dsp_audio_alaw_to_s32[k]
< dsp_audio_alaw_to_s32[i])
j++;
}
sorted_alaw[j] = i;
}
for (i = 0; i < 256; i++) {
spl = i;
if (dsp_options & DSP_OPT_ULAW)
spl = dsp_audio_ulaw_to_alaw[i];
for (j = 0; j < 256; j++) {
if (sorted_alaw[j] == spl)
break;
}
dsp_audio_law2seven[i] = j >> 1;
}
for (i = 0; i < 128; i++) {
spl = sorted_alaw[i << 1];
if (dsp_options & DSP_OPT_ULAW)
spl = dsp_audio_alaw_to_ulaw[spl];
dsp_audio_seven2law[i] = spl;
}
}
void
dsp_audio_generate_mix_table(void)
{
int i, j;
s32 sample;
i = 0;
while (i < 256) {
j = 0;
while (j < 256) {
sample = dsp_audio_law_to_s32[i];
sample += dsp_audio_law_to_s32[j];
if (sample > 32767)
sample = 32767;
if (sample < -32768)
sample = -32768;
dsp_audio_mix_law[(i << 8) | j] =
dsp_audio_s16_to_law[sample & 0xffff];
j++;
}
i++;
}
}
void
dsp_audio_generate_volume_changes(void)
{
register s32 sample;
int i;
int num[] = { 110, 125, 150, 175, 200, 300, 400, 500 };
int denum[] = { 100, 100, 100, 100, 100, 100, 100, 100 };
i = 0;
while (i < 256) {
dsp_audio_reduce8[i] = dsp_audio_s16_to_law[
(dsp_audio_law_to_s32[i] * denum[7] / num[7]) & 0xffff];
dsp_audio_reduce7[i] = dsp_audio_s16_to_law[
(dsp_audio_law_to_s32[i] * denum[6] / num[6]) & 0xffff];
dsp_audio_reduce6[i] = dsp_audio_s16_to_law[
(dsp_audio_law_to_s32[i] * denum[5] / num[5]) & 0xffff];
dsp_audio_reduce5[i] = dsp_audio_s16_to_law[
(dsp_audio_law_to_s32[i] * denum[4] / num[4]) & 0xffff];
dsp_audio_reduce4[i] = dsp_audio_s16_to_law[
(dsp_audio_law_to_s32[i] * denum[3] / num[3]) & 0xffff];
dsp_audio_reduce3[i] = dsp_audio_s16_to_law[
(dsp_audio_law_to_s32[i] * denum[2] / num[2]) & 0xffff];
dsp_audio_reduce2[i] = dsp_audio_s16_to_law[
(dsp_audio_law_to_s32[i] * denum[1] / num[1]) & 0xffff];
dsp_audio_reduce1[i] = dsp_audio_s16_to_law[
(dsp_audio_law_to_s32[i] * denum[0] / num[0]) & 0xffff];
sample = dsp_audio_law_to_s32[i] * num[0] / denum[0];
if (sample < -32768)
sample = -32768;
else if (sample > 32767)
sample = 32767;
dsp_audio_increase1[i] = dsp_audio_s16_to_law[sample & 0xffff];
sample = dsp_audio_law_to_s32[i] * num[1] / denum[1];
if (sample < -32768)
sample = -32768;
else if (sample > 32767)
sample = 32767;
dsp_audio_increase2[i] = dsp_audio_s16_to_law[sample & 0xffff];
sample = dsp_audio_law_to_s32[i] * num[2] / denum[2];
if (sample < -32768)
sample = -32768;
else if (sample > 32767)
sample = 32767;
dsp_audio_increase3[i] = dsp_audio_s16_to_law[sample & 0xffff];
sample = dsp_audio_law_to_s32[i] * num[3] / denum[3];
if (sample < -32768)
sample = -32768;
else if (sample > 32767)
sample = 32767;
dsp_audio_increase4[i] = dsp_audio_s16_to_law[sample & 0xffff];
sample = dsp_audio_law_to_s32[i] * num[4] / denum[4];
if (sample < -32768)
sample = -32768;
else if (sample > 32767)
sample = 32767;
dsp_audio_increase5[i] = dsp_audio_s16_to_law[sample & 0xffff];
sample = dsp_audio_law_to_s32[i] * num[5] / denum[5];
if (sample < -32768)
sample = -32768;
else if (sample > 32767)
sample = 32767;
dsp_audio_increase6[i] = dsp_audio_s16_to_law[sample & 0xffff];
sample = dsp_audio_law_to_s32[i] * num[6] / denum[6];
if (sample < -32768)
sample = -32768;
else if (sample > 32767)
sample = 32767;
dsp_audio_increase7[i] = dsp_audio_s16_to_law[sample & 0xffff];
sample = dsp_audio_law_to_s32[i] * num[7] / denum[7];
if (sample < -32768)
sample = -32768;
else if (sample > 32767)
sample = 32767;
dsp_audio_increase8[i] = dsp_audio_s16_to_law[sample & 0xffff];
i++;
}
}
void
dsp_change_volume(struct sk_buff *skb, int volume)
{
u8 *volume_change;
int i, ii;
u8 *p;
int shift;
if (volume == 0)
return;
if (volume < 0) {
shift = volume + 8;
if (shift < 0)
shift = 0;
} else {
shift = volume + 7;
if (shift > 15)
shift = 15;
}
volume_change = dsp_audio_volume_change[shift];
i = 0;
ii = skb->len;
p = skb->data;
while (i < ii) {
*p = volume_change[*p];
p++;
i++;
}
}
