static int ad1843_read_bits(struct snd_ad1843 *ad1843,
const struct ad1843_bitfield *field)
{
int w;
w = ad1843->read(ad1843->chip, field->reg);
return w >> field->lo_bit & ((1 << field->nbits) - 1);
}
static int ad1843_write_bits(struct snd_ad1843 *ad1843,
const struct ad1843_bitfield *field,
int newval)
{
int w, mask, oldval, newbits;
w = ad1843->read(ad1843->chip, field->reg);
mask = ((1 << field->nbits) - 1) << field->lo_bit;
oldval = (w & mask) >> field->lo_bit;
newbits = (newval << field->lo_bit) & mask;
w = (w & ~mask) | newbits;
ad1843->write(ad1843->chip, field->reg, w);
return oldval;
}
static void ad1843_read_multi(struct snd_ad1843 *ad1843, int argcount, ...)
{
va_list ap;
const struct ad1843_bitfield *fp;
int w = 0, mask, *value, reg = -1;
va_start(ap, argcount);
while (--argcount >= 0) {
fp = va_arg(ap, const struct ad1843_bitfield *);
value = va_arg(ap, int *);
if (reg == -1) {
reg = fp->reg;
w = ad1843->read(ad1843->chip, reg);
}
mask = (1 << fp->nbits) - 1;
*value = w >> fp->lo_bit & mask;
}
va_end(ap);
}
static void ad1843_write_multi(struct snd_ad1843 *ad1843, int argcount, ...)
{
va_list ap;
int reg;
const struct ad1843_bitfield *fp;
int value;
int w, m, mask, bits;
mask = 0;
bits = 0;
reg = -1;
va_start(ap, argcount);
while (--argcount >= 0) {
fp = va_arg(ap, const struct ad1843_bitfield *);
value = va_arg(ap, int);
if (reg == -1)
reg = fp->reg;
else
WARN_ON(reg != fp->reg);
m = ((1 << fp->nbits) - 1) << fp->lo_bit;
mask |= m;
bits |= (value << fp->lo_bit) & m;
}
va_end(ap);
if (~mask & 0xFFFF)
w = ad1843->read(ad1843->chip, reg);
else
w = 0;
w = (w & ~mask) | bits;
ad1843->write(ad1843->chip, reg, w);
}
int ad1843_get_gain_max(struct snd_ad1843 *ad1843, int id)
{
const struct ad1843_gain *gp = ad1843_gain[id];
int ret;
ret = (1 << gp->lfield->nbits);
if (!gp->lmute)
ret -= 1;
return ret;
}
int ad1843_get_gain(struct snd_ad1843 *ad1843, int id)
{
int lg, rg, lm, rm;
const struct ad1843_gain *gp = ad1843_gain[id];
unsigned short mask = (1 << gp->lfield->nbits) - 1;
ad1843_read_multi(ad1843, 2, gp->lfield, &lg, gp->rfield, &rg);
if (gp->negative) {
lg = mask - lg;
rg = mask - rg;
}
if (gp->lmute) {
ad1843_read_multi(ad1843, 2, gp->lmute, &lm, gp->rmute, &rm);
if (lm)
lg = 0;
if (rm)
rg = 0;
}
return lg << 0 | rg << 8;
}
int ad1843_set_gain(struct snd_ad1843 *ad1843, int id, int newval)
{
const struct ad1843_gain *gp = ad1843_gain[id];
unsigned short mask = (1 << gp->lfield->nbits) - 1;
int lg = (newval >> 0) & mask;
int rg = (newval >> 8) & mask;
int lm = (lg == 0) ? 1 : 0;
int rm = (rg == 0) ? 1 : 0;
if (gp->negative) {
lg = mask - lg;
rg = mask - rg;
}
if (gp->lmute)
ad1843_write_multi(ad1843, 2, gp->lmute, lm, gp->rmute, rm);
ad1843_write_multi(ad1843, 2, gp->lfield, lg, gp->rfield, rg);
return ad1843_get_gain(ad1843, id);
}
int ad1843_get_recsrc(struct snd_ad1843 *ad1843)
{
int val = ad1843_read_bits(ad1843, &ad1843_LSS);
if (val < 0 || val > 2) {
val = 2;
ad1843_write_multi(ad1843, 2,
&ad1843_LSS, val, &ad1843_RSS, val);
}
return val;
}
int ad1843_set_recsrc(struct snd_ad1843 *ad1843, int newsrc)
{
if (newsrc < 0 || newsrc > 2)
return -EINVAL;
ad1843_write_multi(ad1843, 2, &ad1843_LSS, newsrc, &ad1843_RSS, newsrc);
return newsrc;
}
void ad1843_setup_dac(struct snd_ad1843 *ad1843,
unsigned int id,
unsigned int framerate,
snd_pcm_format_t fmt,
unsigned int channels)
{
int ad_fmt = 0, ad_mode = 0;
switch (fmt) {
case SNDRV_PCM_FORMAT_S8:
ad_fmt = 0;
break;
case SNDRV_PCM_FORMAT_U8:
ad_fmt = 0;
break;
case SNDRV_PCM_FORMAT_S16_LE:
ad_fmt = 1;
break;
case SNDRV_PCM_FORMAT_MU_LAW:
ad_fmt = 2;
break;
case SNDRV_PCM_FORMAT_A_LAW:
ad_fmt = 3;
break;
default:
break;
}
switch (channels) {
case 2:
ad_mode = 0;
break;
case 1:
ad_mode = 1;
break;
default:
break;
}
if (id) {
ad1843_write_bits(ad1843, &ad1843_C2C, framerate);
ad1843_write_multi(ad1843, 2,
&ad1843_DA2SM, ad_mode,
&ad1843_DA2F, ad_fmt);
} else {
ad1843_write_bits(ad1843, &ad1843_C1C, framerate);
ad1843_write_multi(ad1843, 2,
&ad1843_DA1SM, ad_mode,
&ad1843_DA1F, ad_fmt);
}
}
void ad1843_shutdown_dac(struct snd_ad1843 *ad1843, unsigned int id)
{
if (id)
ad1843_write_bits(ad1843, &ad1843_DA2F, 1);
else
ad1843_write_bits(ad1843, &ad1843_DA1F, 1);
}
void ad1843_setup_adc(struct snd_ad1843 *ad1843,
unsigned int framerate,
snd_pcm_format_t fmt,
unsigned int channels)
{
int da_fmt = 0;
switch (fmt) {
case SNDRV_PCM_FORMAT_S8: da_fmt = 0; break;
case SNDRV_PCM_FORMAT_U8: da_fmt = 0; break;
case SNDRV_PCM_FORMAT_S16_LE: da_fmt = 1; break;
case SNDRV_PCM_FORMAT_MU_LAW: da_fmt = 2; break;
case SNDRV_PCM_FORMAT_A_LAW: da_fmt = 3; break;
default: break;
}
ad1843_write_bits(ad1843, &ad1843_C3C, framerate);
ad1843_write_multi(ad1843, 2,
&ad1843_ADLF, da_fmt, &ad1843_ADRF, da_fmt);
}
void ad1843_shutdown_adc(struct snd_ad1843 *ad1843)
{
}
int ad1843_init(struct snd_ad1843 *ad1843)
{
unsigned long later;
if (ad1843_read_bits(ad1843, &ad1843_INIT) != 0) {
printk(KERN_ERR "ad1843: AD1843 won't initialize\n");
return -EIO;
}
ad1843_write_bits(ad1843, &ad1843_SCF, 1);
ad1843_write_bits(ad1843, &ad1843_PDNI, 0);
later = jiffies + msecs_to_jiffies(500);
while (ad1843_read_bits(ad1843, &ad1843_PDNO)) {
if (time_after(jiffies, later)) {
printk(KERN_ERR
"ad1843: AD1843 won't power up\n");
return -EIO;
}
schedule_timeout_interruptible(5);
}
ad1843_write_multi(ad1843, 3,
&ad1843_C1EN, 1,
&ad1843_C2EN, 1,
&ad1843_C3EN, 1);
ad1843_write_multi(ad1843, 4,
&ad1843_DA1C, 1,
&ad1843_DA2C, 2,
&ad1843_ADLC, 3,
&ad1843_ADRC, 3);
ad1843_write_bits(ad1843, &ad1843_ADTLK, 1);
ad1843_write_multi(ad1843, 7,
&ad1843_ANAEN, 1,
&ad1843_AAMEN, 1,
&ad1843_DA1EN, 1,
&ad1843_DA2EN, 1,
&ad1843_DDMEN, 1,
&ad1843_ADLEN, 1,
&ad1843_ADREN, 1);
ad1843_set_gain(ad1843, AD1843_GAIN_RECLEV, 0);
ad1843_set_gain(ad1843, AD1843_GAIN_LINE, 0);
ad1843_set_gain(ad1843, AD1843_GAIN_LINE_2, 0);
ad1843_set_gain(ad1843, AD1843_GAIN_MIC, 0);
ad1843_set_gain(ad1843, AD1843_GAIN_PCM_0, 0);
ad1843_set_gain(ad1843, AD1843_GAIN_PCM_1, 0);
ad1843_write_multi(ad1843, 2, &ad1843_LDA1GM, 0, &ad1843_RDA1GM, 0);
ad1843_write_multi(ad1843, 2, &ad1843_LDA2GM, 0, &ad1843_RDA2GM, 0);
ad1843_set_recsrc(ad1843, 2);
ad1843_write_multi(ad1843, 2, &ad1843_LMGE, 1, &ad1843_RMGE, 1);
ad1843_write_multi(ad1843, 3,
&ad1843_HPOS, 1,
&ad1843_HPOM, 0,
&ad1843_MPOM, 0);
return 0;
}
