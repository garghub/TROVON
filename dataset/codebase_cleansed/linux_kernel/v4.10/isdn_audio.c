static inline void
isdn_audio_tlookup(const u_char *table, u_char *buff, unsigned long n)
{
#ifdef __i386__
unsigned long d0, d1, d2, d3;
__asm__ __volatile__(
"cld\n"
"1:\tlodsb\n\t"
"xlatb\n\t"
"stosb\n\t"
"loop 1b\n\t"
: "=&b"(d0), "=&c"(d1), "=&D"(d2), "=&S"(d3)
: "0"((long) table), "1"(n), "2"((long) buff), "3"((long) buff)
: "memory", "ax");
#else
while (n--)
*buff = table[*(unsigned char *)buff], buff++;
#endif
}
void
isdn_audio_ulaw2alaw(unsigned char *buff, unsigned long len)
{
isdn_audio_tlookup(isdn_audio_ulaw_to_alaw, buff, len);
}
void
isdn_audio_alaw2ulaw(unsigned char *buff, unsigned long len)
{
isdn_audio_tlookup(isdn_audio_alaw_to_ulaw, buff, len);
}
static unsigned char
isdn_audio_linear2ulaw(int sample)
{
static int exp_lut[256] =
{
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
7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7
};
int sign,
exponent,
mantissa;
unsigned char ulawbyte;
sign = (sample >> 8) & 0x80;
if (sign != 0)
sample = -sample;
if (sample > CLIP)
sample = CLIP;
sample = sample + BIAS;
exponent = exp_lut[(sample >> 7) & 0xFF];
mantissa = (sample >> (exponent + 3)) & 0x0F;
ulawbyte = ~(sign | (exponent << 4) | mantissa);
#ifdef ZEROTRAP
if (ulawbyte == 0)
ulawbyte = 0x02;
#endif
return (ulawbyte);
}
static int
isdn_audio_get_bits(adpcm_state *s, unsigned char **in, int *len)
{
while (s->nleft < s->nbits) {
int d = *((*in)++);
(*len)--;
s->word = (s->word << 8) | d;
s->nleft += 8;
}
s->nleft -= s->nbits;
return (s->word >> s->nleft) & bitmask[s->nbits];
}
static void
isdn_audio_put_bits(int data, int nbits, adpcm_state *s,
unsigned char **out, int *len)
{
s->word = (s->word << nbits) | (data & bitmask[nbits]);
s->nleft += nbits;
while (s->nleft >= 8) {
int d = (s->word >> (s->nleft - 8));
*(out[0]++) = d & 255;
(*len)++;
s->nleft -= 8;
}
}
adpcm_state *
isdn_audio_adpcm_init(adpcm_state *s, int nbits)
{
if (!s)
s = kmalloc(sizeof(adpcm_state), GFP_ATOMIC);
if (s) {
s->a = 0;
s->d = 5;
s->word = 0;
s->nleft = 0;
s->nbits = nbits;
}
return s;
}
dtmf_state *
isdn_audio_dtmf_init(dtmf_state *s)
{
if (!s)
s = kmalloc(sizeof(dtmf_state), GFP_ATOMIC);
if (s) {
s->idx = 0;
s->last = ' ';
}
return s;
}
int
isdn_audio_adpcm2xlaw(adpcm_state *s, int fmt, unsigned char *in,
unsigned char *out, int len)
{
int a = s->a;
int d = s->d;
int nbits = s->nbits;
int olen = 0;
while (len) {
int e = isdn_audio_get_bits(s, &in, &len);
int sign;
if (nbits == 4 && e == 0)
d = 4;
sign = (e >> (nbits - 1)) ? -1 : 1;
e &= bitmask[nbits - 1];
a += sign * ((e << 1) + 1) * d >> 1;
if (d & 1)
a++;
if (fmt)
*out++ = isdn_audio_ulaw_to_alaw[
isdn_audio_linear2ulaw(a << 2)];
else
*out++ = isdn_audio_linear2ulaw(a << 2);
olen++;
d = (d * Mx[nbits - 2][e] + 0x2000) >> 14;
if (d < 5)
d = 5;
}
s->a = a;
s->d = d;
return olen;
}
int
isdn_audio_xlaw2adpcm(adpcm_state *s, int fmt, unsigned char *in,
unsigned char *out, int len)
{
int a = s->a;
int d = s->d;
int nbits = s->nbits;
int olen = 0;
while (len--) {
int e = 0,
nmax = 1 << (nbits - 1);
int sign,
delta;
if (fmt)
delta = (isdn_audio_alaw_to_s16[*in++] >> 2) - a;
else
delta = (isdn_audio_ulaw_to_s16[*in++] >> 2) - a;
if (delta < 0) {
e = nmax;
delta = -delta;
}
while (--nmax && delta > d) {
delta -= d;
e++;
}
if (nbits == 4 && ((e & 0x0f) == 0))
e = 8;
isdn_audio_put_bits(e, nbits, s, &out, &olen);
sign = (e >> (nbits - 1)) ? -1 : 1;
e &= bitmask[nbits - 1];
a += sign * ((e << 1) + 1) * d >> 1;
if (d & 1)
a++;
d = (d * Mx[nbits - 2][e] + 0x2000) >> 14;
if (d < 5)
d = 5;
}
s->a = a;
s->d = d;
return olen;
}
static void
isdn_audio_goertzel(int *sample, modem_info *info)
{
int sk,
sk1,
sk2;
int k,
n;
struct sk_buff *skb;
int *result;
skb = dev_alloc_skb(sizeof(int) * NCOEFF);
if (!skb) {
printk(KERN_WARNING
"isdn_audio: Could not alloc DTMF result for ttyI%d\n",
info->line);
return;
}
result = (int *) skb_put(skb, sizeof(int) * NCOEFF);
for (k = 0; k < NCOEFF; k++) {
sk = sk1 = sk2 = 0;
for (n = 0; n < DTMF_NPOINTS; n++) {
sk = sample[n] + ((cos2pik[k] * sk1) >> 15) - sk2;
sk2 = sk1;
sk1 = sk;
}
sk >>= 1;
sk2 >>= 1;
if (sk < -32768 || sk > 32767)
printk(KERN_DEBUG
"isdn_audio: dtmf goertzel overflow, sk=%d\n", sk);
if (sk2 < -32768 || sk2 > 32767)
printk(KERN_DEBUG
"isdn_audio: dtmf goertzel overflow, sk2=%d\n", sk2);
result[k] =
((sk * sk) >> AMP_BITS) -
((((cos2pik[k] * sk) >> 15) * sk2) >> AMP_BITS) +
((sk2 * sk2) >> AMP_BITS);
}
skb_queue_tail(&info->dtmf_queue, skb);
isdn_timer_ctrl(ISDN_TIMER_MODEMREAD, 1);
}
void
isdn_audio_eval_dtmf(modem_info *info)
{
struct sk_buff *skb;
int *result;
dtmf_state *s;
int silence;
int i;
int di;
int ch;
int grp[2];
char what;
char *p;
int thresh;
while ((skb = skb_dequeue(&info->dtmf_queue))) {
result = (int *) skb->data;
s = info->dtmf_state;
grp[LOGRP] = grp[HIGRP] = -1;
silence = 0;
thresh = 0;
for (i = 0; i < NCOEFF; i++) {
if (result[i] > DTMF_TRESH) {
if (result[i] > thresh)
thresh = result[i];
}
else if (result[i] < SILENCE_TRESH)
silence++;
}
if (silence == NCOEFF)
what = ' ';
else {
if (thresh > 0) {
thresh = thresh >> 4;
for (i = 0; i < NCOEFF; i++) {
if (result[i] < thresh)
continue;
if (i < NCOEFF / 2) {
if (grp[LOGRP] >= 0) {
grp[LOGRP] = -1;
break;
}
else
grp[LOGRP] = i;
}
else {
if (grp[HIGRP] >= 0) {
grp[HIGRP] = -1;
break;
}
else
grp[HIGRP] = i - NCOEFF/2;
}
}
if ((grp[LOGRP] >= 0) && (grp[HIGRP] >= 0)) {
what = dtmf_matrix[grp[LOGRP]][grp[HIGRP]];
if (s->last != ' ' && s->last != '.')
s->last = what;
} else
what = '.';
}
else
what = '.';
}
if ((what != s->last) && (what != ' ') && (what != '.')) {
printk(KERN_DEBUG "dtmf: tt='%c'\n", what);
p = skb->data;
*p++ = 0x10;
*p = what;
skb_trim(skb, 2);
ISDN_AUDIO_SKB_DLECOUNT(skb) = 0;
ISDN_AUDIO_SKB_LOCK(skb) = 0;
di = info->isdn_driver;
ch = info->isdn_channel;
__skb_queue_tail(&dev->drv[di]->rpqueue[ch], skb);
dev->drv[di]->rcvcount[ch] += 2;
if ((dev->modempoll) && (info->rcvsched))
isdn_timer_ctrl(ISDN_TIMER_MODEMREAD, 1);
wake_up_interruptible(&dev->drv[di]->rcv_waitq[ch]);
} else
kfree_skb(skb);
s->last = what;
}
}
void
isdn_audio_calc_dtmf(modem_info *info, unsigned char *buf, int len, int fmt)
{
dtmf_state *s = info->dtmf_state;
int i;
int c;
while (len) {
c = DTMF_NPOINTS - s->idx;
if (c > len)
c = len;
if (c <= 0)
break;
for (i = 0; i < c; i++) {
if (fmt)
s->buf[s->idx++] =
isdn_audio_alaw_to_s16[*buf++] >> (15 - AMP_BITS);
else
s->buf[s->idx++] =
isdn_audio_ulaw_to_s16[*buf++] >> (15 - AMP_BITS);
}
if (s->idx == DTMF_NPOINTS) {
isdn_audio_goertzel(s->buf, info);
s->idx = 0;
}
len -= c;
}
}
silence_state *
isdn_audio_silence_init(silence_state *s)
{
if (!s)
s = kmalloc(sizeof(silence_state), GFP_ATOMIC);
if (s) {
s->idx = 0;
s->state = 0;
}
return s;
}
void
isdn_audio_calc_silence(modem_info *info, unsigned char *buf, int len, int fmt)
{
silence_state *s = info->silence_state;
int i;
signed char c;
if (!info->emu.vpar[1]) return;
for (i = 0; i < len; i++) {
if (fmt)
c = isdn_audio_alaw_to_ulaw[*buf++];
else
c = *buf++;
if (c > 0) c -= 128;
c = abs(c);
if (c > (info->emu.vpar[1] * 4)) {
s->idx = 0;
s->state = 1;
} else {
if (s->idx < 210000) s->idx++;
}
}
}
void
isdn_audio_put_dle_code(modem_info *info, u_char code)
{
struct sk_buff *skb;
int di;
int ch;
char *p;
skb = dev_alloc_skb(2);
if (!skb) {
printk(KERN_WARNING
"isdn_audio: Could not alloc skb for ttyI%d\n",
info->line);
return;
}
p = (char *) skb_put(skb, 2);
p[0] = 0x10;
p[1] = code;
ISDN_AUDIO_SKB_DLECOUNT(skb) = 0;
ISDN_AUDIO_SKB_LOCK(skb) = 0;
di = info->isdn_driver;
ch = info->isdn_channel;
__skb_queue_tail(&dev->drv[di]->rpqueue[ch], skb);
dev->drv[di]->rcvcount[ch] += 2;
if ((dev->modempoll) && (info->rcvsched))
isdn_timer_ctrl(ISDN_TIMER_MODEMREAD, 1);
wake_up_interruptible(&dev->drv[di]->rcv_waitq[ch]);
}
void
isdn_audio_eval_silence(modem_info *info)
{
silence_state *s = info->silence_state;
char what;
what = ' ';
if (s->idx > (info->emu.vpar[2] * 800)) {
s->idx = 0;
if (!s->state) {
what = 's';
} else {
what = 'q';
}
}
if ((what == 's') || (what == 'q')) {
printk(KERN_DEBUG "ttyI%d: %s\n", info->line,
(what == 's') ? "silence" : "quiet");
isdn_audio_put_dle_code(info, what);
}
}
