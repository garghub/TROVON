static ssize_t ata_ct_law(const u_char __user *userPtr, size_t userCount,
u_char frame[], ssize_t *frameUsed,
ssize_t frameLeft)
{
char *table = dmasound.soft.format == AFMT_MU_LAW ? dmasound_ulaw2dma8
: dmasound_alaw2dma8;
ssize_t count, used;
u_char *p = &frame[*frameUsed];
count = min_t(unsigned long, userCount, frameLeft);
if (dmasound.soft.stereo)
count &= ~1;
used = count;
while (count > 0) {
u_char data;
if (get_user(data, userPtr++))
return -EFAULT;
*p++ = table[data];
count--;
}
*frameUsed += used;
return used;
}
static ssize_t ata_ct_s8(const u_char __user *userPtr, size_t userCount,
u_char frame[], ssize_t *frameUsed,
ssize_t frameLeft)
{
ssize_t count, used;
void *p = &frame[*frameUsed];
count = min_t(unsigned long, userCount, frameLeft);
if (dmasound.soft.stereo)
count &= ~1;
used = count;
if (copy_from_user(p, userPtr, count))
return -EFAULT;
*frameUsed += used;
return used;
}
static ssize_t ata_ct_u8(const u_char __user *userPtr, size_t userCount,
u_char frame[], ssize_t *frameUsed,
ssize_t frameLeft)
{
ssize_t count, used;
if (!dmasound.soft.stereo) {
u_char *p = &frame[*frameUsed];
count = min_t(unsigned long, userCount, frameLeft);
used = count;
while (count > 0) {
u_char data;
if (get_user(data, userPtr++))
return -EFAULT;
*p++ = data ^ 0x80;
count--;
}
} else {
u_short *p = (u_short *)&frame[*frameUsed];
count = min_t(unsigned long, userCount, frameLeft)>>1;
used = count*2;
while (count > 0) {
u_short data;
if (get_user(data, (u_short __user *)userPtr))
return -EFAULT;
userPtr += 2;
*p++ = data ^ 0x8080;
count--;
}
}
*frameUsed += used;
return used;
}
static ssize_t ata_ct_s16be(const u_char __user *userPtr, size_t userCount,
u_char frame[], ssize_t *frameUsed,
ssize_t frameLeft)
{
ssize_t count, used;
if (!dmasound.soft.stereo) {
u_short *p = (u_short *)&frame[*frameUsed];
count = min_t(unsigned long, userCount, frameLeft)>>1;
used = count*2;
while (count > 0) {
u_short data;
if (get_user(data, (u_short __user *)userPtr))
return -EFAULT;
userPtr += 2;
*p++ = data;
*p++ = data;
count--;
}
*frameUsed += used*2;
} else {
void *p = (u_short *)&frame[*frameUsed];
count = min_t(unsigned long, userCount, frameLeft) & ~3;
used = count;
if (copy_from_user(p, userPtr, count))
return -EFAULT;
*frameUsed += used;
}
return used;
}
static ssize_t ata_ct_u16be(const u_char __user *userPtr, size_t userCount,
u_char frame[], ssize_t *frameUsed,
ssize_t frameLeft)
{
ssize_t count, used;
if (!dmasound.soft.stereo) {
u_short *p = (u_short *)&frame[*frameUsed];
count = min_t(unsigned long, userCount, frameLeft)>>1;
used = count*2;
while (count > 0) {
u_short data;
if (get_user(data, (u_short __user *)userPtr))
return -EFAULT;
userPtr += 2;
data ^= 0x8000;
*p++ = data;
*p++ = data;
count--;
}
*frameUsed += used*2;
} else {
u_long *p = (u_long *)&frame[*frameUsed];
count = min_t(unsigned long, userCount, frameLeft)>>2;
used = count*4;
while (count > 0) {
u_int data;
if (get_user(data, (u_int __user *)userPtr))
return -EFAULT;
userPtr += 4;
*p++ = data ^ 0x80008000;
count--;
}
*frameUsed += used;
}
return used;
}
static ssize_t ata_ct_s16le(const u_char __user *userPtr, size_t userCount,
u_char frame[], ssize_t *frameUsed,
ssize_t frameLeft)
{
ssize_t count, used;
count = frameLeft;
if (!dmasound.soft.stereo) {
u_short *p = (u_short *)&frame[*frameUsed];
count = min_t(unsigned long, userCount, frameLeft)>>1;
used = count*2;
while (count > 0) {
u_short data;
if (get_user(data, (u_short __user *)userPtr))
return -EFAULT;
userPtr += 2;
data = le2be16(data);
*p++ = data;
*p++ = data;
count--;
}
*frameUsed += used*2;
} else {
u_long *p = (u_long *)&frame[*frameUsed];
count = min_t(unsigned long, userCount, frameLeft)>>2;
used = count*4;
while (count > 0) {
u_long data;
if (get_user(data, (u_int __user *)userPtr))
return -EFAULT;
userPtr += 4;
data = le2be16dbl(data);
*p++ = data;
count--;
}
*frameUsed += used;
}
return used;
}
static ssize_t ata_ct_u16le(const u_char __user *userPtr, size_t userCount,
u_char frame[], ssize_t *frameUsed,
ssize_t frameLeft)
{
ssize_t count, used;
count = frameLeft;
if (!dmasound.soft.stereo) {
u_short *p = (u_short *)&frame[*frameUsed];
count = min_t(unsigned long, userCount, frameLeft)>>1;
used = count*2;
while (count > 0) {
u_short data;
if (get_user(data, (u_short __user *)userPtr))
return -EFAULT;
userPtr += 2;
data = le2be16(data) ^ 0x8000;
*p++ = data;
*p++ = data;
}
*frameUsed += used*2;
} else {
u_long *p = (u_long *)&frame[*frameUsed];
count = min_t(unsigned long, userCount, frameLeft)>>2;
used = count;
while (count > 0) {
u_long data;
if (get_user(data, (u_int __user *)userPtr))
return -EFAULT;
userPtr += 4;
data = le2be16dbl(data) ^ 0x80008000;
*p++ = data;
count--;
}
*frameUsed += used;
}
return used;
}
static ssize_t ata_ctx_law(const u_char __user *userPtr, size_t userCount,
u_char frame[], ssize_t *frameUsed,
ssize_t frameLeft)
{
char *table = dmasound.soft.format == AFMT_MU_LAW ? dmasound_ulaw2dma8
: dmasound_alaw2dma8;
long bal = expand_bal;
long hSpeed = dmasound.hard.speed, sSpeed = dmasound.soft.speed;
ssize_t used, usedf;
used = userCount;
usedf = frameLeft;
if (!dmasound.soft.stereo) {
u_char *p = &frame[*frameUsed];
u_char data = expand_data;
while (frameLeft) {
u_char c;
if (bal < 0) {
if (!userCount)
break;
if (get_user(c, userPtr++))
return -EFAULT;
data = table[c];
userCount--;
bal += hSpeed;
}
*p++ = data;
frameLeft--;
bal -= sSpeed;
}
expand_data = data;
} else {
u_short *p = (u_short *)&frame[*frameUsed];
u_short data = expand_data;
while (frameLeft >= 2) {
u_char c;
if (bal < 0) {
if (userCount < 2)
break;
if (get_user(c, userPtr++))
return -EFAULT;
data = table[c] << 8;
if (get_user(c, userPtr++))
return -EFAULT;
data |= table[c];
userCount -= 2;
bal += hSpeed;
}
*p++ = data;
frameLeft -= 2;
bal -= sSpeed;
}
expand_data = data;
}
expand_bal = bal;
used -= userCount;
*frameUsed += usedf-frameLeft;
return used;
}
static ssize_t ata_ctx_s8(const u_char __user *userPtr, size_t userCount,
u_char frame[], ssize_t *frameUsed,
ssize_t frameLeft)
{
long bal = expand_bal;
long hSpeed = dmasound.hard.speed, sSpeed = dmasound.soft.speed;
ssize_t used, usedf;
used = userCount;
usedf = frameLeft;
if (!dmasound.soft.stereo) {
u_char *p = &frame[*frameUsed];
u_char data = expand_data;
while (frameLeft) {
if (bal < 0) {
if (!userCount)
break;
if (get_user(data, userPtr++))
return -EFAULT;
userCount--;
bal += hSpeed;
}
*p++ = data;
frameLeft--;
bal -= sSpeed;
}
expand_data = data;
} else {
u_short *p = (u_short *)&frame[*frameUsed];
u_short data = expand_data;
while (frameLeft >= 2) {
if (bal < 0) {
if (userCount < 2)
break;
if (get_user(data, (u_short __user *)userPtr))
return -EFAULT;
userPtr += 2;
userCount -= 2;
bal += hSpeed;
}
*p++ = data;
frameLeft -= 2;
bal -= sSpeed;
}
expand_data = data;
}
expand_bal = bal;
used -= userCount;
*frameUsed += usedf-frameLeft;
return used;
}
static ssize_t ata_ctx_u8(const u_char __user *userPtr, size_t userCount,
u_char frame[], ssize_t *frameUsed,
ssize_t frameLeft)
{
long bal = expand_bal;
long hSpeed = dmasound.hard.speed, sSpeed = dmasound.soft.speed;
ssize_t used, usedf;
used = userCount;
usedf = frameLeft;
if (!dmasound.soft.stereo) {
u_char *p = &frame[*frameUsed];
u_char data = expand_data;
while (frameLeft) {
if (bal < 0) {
if (!userCount)
break;
if (get_user(data, userPtr++))
return -EFAULT;
data ^= 0x80;
userCount--;
bal += hSpeed;
}
*p++ = data;
frameLeft--;
bal -= sSpeed;
}
expand_data = data;
} else {
u_short *p = (u_short *)&frame[*frameUsed];
u_short data = expand_data;
while (frameLeft >= 2) {
if (bal < 0) {
if (userCount < 2)
break;
if (get_user(data, (u_short __user *)userPtr))
return -EFAULT;
userPtr += 2;
data ^= 0x8080;
userCount -= 2;
bal += hSpeed;
}
*p++ = data;
frameLeft -= 2;
bal -= sSpeed;
}
expand_data = data;
}
expand_bal = bal;
used -= userCount;
*frameUsed += usedf-frameLeft;
return used;
}
static ssize_t ata_ctx_s16be(const u_char __user *userPtr, size_t userCount,
u_char frame[], ssize_t *frameUsed,
ssize_t frameLeft)
{
long bal = expand_bal;
long hSpeed = dmasound.hard.speed, sSpeed = dmasound.soft.speed;
ssize_t used, usedf;
used = userCount;
usedf = frameLeft;
if (!dmasound.soft.stereo) {
u_short *p = (u_short *)&frame[*frameUsed];
u_short data = expand_data;
while (frameLeft >= 4) {
if (bal < 0) {
if (userCount < 2)
break;
if (get_user(data, (u_short __user *)userPtr))
return -EFAULT;
userPtr += 2;
userCount -= 2;
bal += hSpeed;
}
*p++ = data;
*p++ = data;
frameLeft -= 4;
bal -= sSpeed;
}
expand_data = data;
} else {
u_long *p = (u_long *)&frame[*frameUsed];
u_long data = expand_data;
while (frameLeft >= 4) {
if (bal < 0) {
if (userCount < 4)
break;
if (get_user(data, (u_int __user *)userPtr))
return -EFAULT;
userPtr += 4;
userCount -= 4;
bal += hSpeed;
}
*p++ = data;
frameLeft -= 4;
bal -= sSpeed;
}
expand_data = data;
}
expand_bal = bal;
used -= userCount;
*frameUsed += usedf-frameLeft;
return used;
}
static ssize_t ata_ctx_u16be(const u_char __user *userPtr, size_t userCount,
u_char frame[], ssize_t *frameUsed,
ssize_t frameLeft)
{
long bal = expand_bal;
long hSpeed = dmasound.hard.speed, sSpeed = dmasound.soft.speed;
ssize_t used, usedf;
used = userCount;
usedf = frameLeft;
if (!dmasound.soft.stereo) {
u_short *p = (u_short *)&frame[*frameUsed];
u_short data = expand_data;
while (frameLeft >= 4) {
if (bal < 0) {
if (userCount < 2)
break;
if (get_user(data, (u_short __user *)userPtr))
return -EFAULT;
userPtr += 2;
data ^= 0x8000;
userCount -= 2;
bal += hSpeed;
}
*p++ = data;
*p++ = data;
frameLeft -= 4;
bal -= sSpeed;
}
expand_data = data;
} else {
u_long *p = (u_long *)&frame[*frameUsed];
u_long data = expand_data;
while (frameLeft >= 4) {
if (bal < 0) {
if (userCount < 4)
break;
if (get_user(data, (u_int __user *)userPtr))
return -EFAULT;
userPtr += 4;
data ^= 0x80008000;
userCount -= 4;
bal += hSpeed;
}
*p++ = data;
frameLeft -= 4;
bal -= sSpeed;
}
expand_data = data;
}
expand_bal = bal;
used -= userCount;
*frameUsed += usedf-frameLeft;
return used;
}
static ssize_t ata_ctx_s16le(const u_char __user *userPtr, size_t userCount,
u_char frame[], ssize_t *frameUsed,
ssize_t frameLeft)
{
long bal = expand_bal;
long hSpeed = dmasound.hard.speed, sSpeed = dmasound.soft.speed;
ssize_t used, usedf;
used = userCount;
usedf = frameLeft;
if (!dmasound.soft.stereo) {
u_short *p = (u_short *)&frame[*frameUsed];
u_short data = expand_data;
while (frameLeft >= 4) {
if (bal < 0) {
if (userCount < 2)
break;
if (get_user(data, (u_short __user *)userPtr))
return -EFAULT;
userPtr += 2;
data = le2be16(data);
userCount -= 2;
bal += hSpeed;
}
*p++ = data;
*p++ = data;
frameLeft -= 4;
bal -= sSpeed;
}
expand_data = data;
} else {
u_long *p = (u_long *)&frame[*frameUsed];
u_long data = expand_data;
while (frameLeft >= 4) {
if (bal < 0) {
if (userCount < 4)
break;
if (get_user(data, (u_int __user *)userPtr))
return -EFAULT;
userPtr += 4;
data = le2be16dbl(data);
userCount -= 4;
bal += hSpeed;
}
*p++ = data;
frameLeft -= 4;
bal -= sSpeed;
}
expand_data = data;
}
expand_bal = bal;
used -= userCount;
*frameUsed += usedf-frameLeft;
return used;
}
static ssize_t ata_ctx_u16le(const u_char __user *userPtr, size_t userCount,
u_char frame[], ssize_t *frameUsed,
ssize_t frameLeft)
{
long bal = expand_bal;
long hSpeed = dmasound.hard.speed, sSpeed = dmasound.soft.speed;
ssize_t used, usedf;
used = userCount;
usedf = frameLeft;
if (!dmasound.soft.stereo) {
u_short *p = (u_short *)&frame[*frameUsed];
u_short data = expand_data;
while (frameLeft >= 4) {
if (bal < 0) {
if (userCount < 2)
break;
if (get_user(data, (u_short __user *)userPtr))
return -EFAULT;
userPtr += 2;
data = le2be16(data) ^ 0x8000;
userCount -= 2;
bal += hSpeed;
}
*p++ = data;
*p++ = data;
frameLeft -= 4;
bal -= sSpeed;
}
expand_data = data;
} else {
u_long *p = (u_long *)&frame[*frameUsed];
u_long data = expand_data;
while (frameLeft >= 4) {
if (bal < 0) {
if (userCount < 4)
break;
if (get_user(data, (u_int __user *)userPtr))
return -EFAULT;
userPtr += 4;
data = le2be16dbl(data) ^ 0x80008000;
userCount -= 4;
bal += hSpeed;
}
*p++ = data;
frameLeft -= 4;
bal -= sSpeed;
}
expand_data = data;
}
expand_bal = bal;
used -= userCount;
*frameUsed += usedf-frameLeft;
return used;
}
static void *AtaAlloc(unsigned int size, gfp_t flags)
{
return atari_stram_alloc(size, "dmasound");
}
static void AtaFree(void *obj, unsigned int size)
{
atari_stram_free( obj );
}
static int __init AtaIrqInit(void)
{
st_mfp.tim_ct_a = 0;
st_mfp.tim_dt_a = 1;
st_mfp.tim_ct_a = 8;
if (request_irq(IRQ_MFP_TIMA, AtaInterrupt, IRQ_TYPE_SLOW, "DMA sound",
AtaInterrupt))
return 0;
st_mfp.int_en_a |= 0x20;
st_mfp.int_mk_a |= 0x20;
return 1;
}
static void AtaIrqCleanUp(void)
{
st_mfp.tim_ct_a = 0;
st_mfp.int_en_a &= ~0x20;
free_irq(IRQ_MFP_TIMA, AtaInterrupt);
}
static int AtaSetBass(int bass)
{
dmasound.bass = TONE_VOXWARE_TO_DB(bass);
atari_microwire_cmd(MW_LM1992_BASS(dmasound.bass));
return TONE_DB_TO_VOXWARE(dmasound.bass);
}
static int AtaSetTreble(int treble)
{
dmasound.treble = TONE_VOXWARE_TO_DB(treble);
atari_microwire_cmd(MW_LM1992_TREBLE(dmasound.treble));
return TONE_DB_TO_VOXWARE(dmasound.treble);
}
static void TTSilence(void)
{
tt_dmasnd.ctrl = DMASND_CTRL_OFF;
atari_microwire_cmd(MW_LM1992_PSG_HIGH);
}
static void TTInit(void)
{
int mode, i, idx;
const int freq[4] = {50066, 25033, 12517, 6258};
idx = -1;
for (i = 0; i < ARRAY_SIZE(freq); i++)
if ((100 * abs(dmasound.soft.speed - freq[i]) / freq[i]) < catchRadius)
idx = i;
if (idx > -1) {
dmasound.soft.speed = freq[idx];
dmasound.trans_write = &transTTNormal;
} else
dmasound.trans_write = &transTTExpanding;
TTSilence();
dmasound.hard = dmasound.soft;
if (dmasound.hard.speed > 50066) {
dmasound.hard.speed = 50066;
mode = DMASND_MODE_50KHZ;
dmasound.trans_write = &transTTNormal;
} else if (dmasound.hard.speed > 25033) {
dmasound.hard.speed = 50066;
mode = DMASND_MODE_50KHZ;
} else if (dmasound.hard.speed > 12517) {
dmasound.hard.speed = 25033;
mode = DMASND_MODE_25KHZ;
} else if (dmasound.hard.speed > 6258) {
dmasound.hard.speed = 12517;
mode = DMASND_MODE_12KHZ;
} else {
dmasound.hard.speed = 6258;
mode = DMASND_MODE_6KHZ;
}
tt_dmasnd.mode = (dmasound.hard.stereo ?
DMASND_MODE_STEREO : DMASND_MODE_MONO) |
DMASND_MODE_8BIT | mode;
expand_bal = -dmasound.soft.speed;
}
static int TTSetFormat(int format)
{
switch (format) {
case AFMT_QUERY:
return dmasound.soft.format;
case AFMT_MU_LAW:
case AFMT_A_LAW:
case AFMT_S8:
case AFMT_U8:
break;
default:
format = AFMT_S8;
}
dmasound.soft.format = format;
dmasound.soft.size = 8;
if (dmasound.minDev == SND_DEV_DSP) {
dmasound.dsp.format = format;
dmasound.dsp.size = 8;
}
TTInit();
return format;
}
static int TTSetVolume(int volume)
{
dmasound.volume_left = VOLUME_VOXWARE_TO_DB(volume & 0xff);
atari_microwire_cmd(MW_LM1992_BALLEFT(dmasound.volume_left));
dmasound.volume_right = VOLUME_VOXWARE_TO_DB((volume & 0xff00) >> 8);
atari_microwire_cmd(MW_LM1992_BALRIGHT(dmasound.volume_right));
return VOLUME_DB_TO_VOXWARE(dmasound.volume_left) |
(VOLUME_DB_TO_VOXWARE(dmasound.volume_right) << 8);
}
static int TTSetGain(int gain)
{
dmasound.gain = GAIN_VOXWARE_TO_DB(gain);
atari_microwire_cmd(MW_LM1992_VOLUME(dmasound.gain));
return GAIN_DB_TO_VOXWARE(dmasound.gain);
}
static void FalconSilence(void)
{
tt_dmasnd.ctrl = DMASND_CTRL_OFF;
tt_dmasnd.mode = DMASND_MODE_50KHZ | DMASND_MODE_STEREO | DMASND_MODE_8BIT;
tt_dmasnd.int_div = 0;
tt_dmasnd.int_ctrl = 0x0;
tt_dmasnd.cbar_src = 0x0000;
tt_dmasnd.cbar_dst = 0x0000;
tt_dmasnd.dac_src = 1;
tt_dmasnd.adc_src = 3;
}
static void FalconInit(void)
{
int divider, i, idx;
const int freq[8] = {49170, 32780, 24585, 19668, 16390, 12292, 9834, 8195};
idx = -1;
for (i = 0; i < ARRAY_SIZE(freq); i++)
if ((100 * abs(dmasound.soft.speed - freq[i]) / freq[i]) < catchRadius)
idx = i;
if (idx > -1) {
dmasound.soft.speed = freq[idx];
dmasound.trans_write = &transFalconNormal;
} else
dmasound.trans_write = &transFalconExpanding;
FalconSilence();
dmasound.hard = dmasound.soft;
if (dmasound.hard.size == 16) {
dmasound.hard.stereo = 1;
}
if (dmasound.hard.speed > 49170) {
dmasound.hard.speed = 49170;
divider = 1;
dmasound.trans_write = &transFalconNormal;
} else if (dmasound.hard.speed > 32780) {
dmasound.hard.speed = 49170;
divider = 1;
} else if (dmasound.hard.speed > 24585) {
dmasound.hard.speed = 32780;
divider = 2;
} else if (dmasound.hard.speed > 19668) {
dmasound.hard.speed = 24585;
divider = 3;
} else if (dmasound.hard.speed > 16390) {
dmasound.hard.speed = 19668;
divider = 4;
} else if (dmasound.hard.speed > 12292) {
dmasound.hard.speed = 16390;
divider = 5;
} else if (dmasound.hard.speed > 9834) {
dmasound.hard.speed = 12292;
divider = 7;
} else if (dmasound.hard.speed > 8195) {
dmasound.hard.speed = 9834;
divider = 9;
} else {
dmasound.hard.speed = 8195;
divider = 11;
}
tt_dmasnd.int_div = divider;
tt_dmasnd.int_ctrl = 0x4;
tt_dmasnd.track_select = 0x0;
tt_dmasnd.cbar_src = 0x0001;
tt_dmasnd.cbar_dst = 0x0000;
tt_dmasnd.rec_track_select = 0;
tt_dmasnd.dac_src = 2;
tt_dmasnd.adc_src = 0;
tt_dmasnd.mode = (dmasound.hard.stereo ?
DMASND_MODE_STEREO : DMASND_MODE_MONO) |
((dmasound.hard.size == 8) ?
DMASND_MODE_8BIT : DMASND_MODE_16BIT) |
DMASND_MODE_6KHZ;
expand_bal = -dmasound.soft.speed;
}
static int FalconSetFormat(int format)
{
int size;
switch (format) {
case AFMT_QUERY:
return dmasound.soft.format;
case AFMT_MU_LAW:
case AFMT_A_LAW:
case AFMT_U8:
case AFMT_S8:
size = 8;
break;
case AFMT_S16_BE:
case AFMT_U16_BE:
case AFMT_S16_LE:
case AFMT_U16_LE:
size = 16;
break;
default:
size = 8;
format = AFMT_S8;
}
dmasound.soft.format = format;
dmasound.soft.size = size;
if (dmasound.minDev == SND_DEV_DSP) {
dmasound.dsp.format = format;
dmasound.dsp.size = dmasound.soft.size;
}
FalconInit();
return format;
}
static int FalconSetVolume(int volume)
{
dmasound.volume_left = VOLUME_VOXWARE_TO_ATT(volume & 0xff);
dmasound.volume_right = VOLUME_VOXWARE_TO_ATT((volume & 0xff00) >> 8);
tt_dmasnd.output_atten = dmasound.volume_left << 8 | dmasound.volume_right << 4;
return VOLUME_ATT_TO_VOXWARE(dmasound.volume_left) |
VOLUME_ATT_TO_VOXWARE(dmasound.volume_right) << 8;
}
static void AtaPlayNextFrame(int index)
{
char *start, *end;
start = write_sq.buffers[write_sq.front];
end = start+((write_sq.count == index) ? write_sq.rear_size
: write_sq.block_size);
DMASNDSetEnd(virt_to_phys(end - 1) + 1);
DMASNDSetBase(virt_to_phys(start));
write_sq.front = (write_sq.front+1) % write_sq.max_count;
write_sq.active++;
tt_dmasnd.ctrl = DMASND_CTRL_ON | DMASND_CTRL_REPEAT;
}
static void AtaPlay(void)
{
atari_disable_irq(IRQ_MFP_TIMA);
if (write_sq.active == 2 ||
write_sq.count <= 0) {
atari_enable_irq(IRQ_MFP_TIMA);
return;
}
if (write_sq.active == 0) {
if (write_sq.count == 1 &&
write_sq.rear_size < write_sq.block_size &&
!write_sq.syncing) {
atari_enable_irq(IRQ_MFP_TIMA);
return;
}
AtaPlayNextFrame(1);
if (write_sq.count == 1) {
atari_enable_irq(IRQ_MFP_TIMA);
return;
}
if (write_sq.count == 2 &&
write_sq.rear_size < write_sq.block_size &&
!write_sq.syncing) {
atari_enable_irq(IRQ_MFP_TIMA);
return;
}
AtaPlayNextFrame(2);
} else {
if (write_sq.count == 2 &&
write_sq.rear_size < write_sq.block_size &&
!write_sq.syncing) {
atari_enable_irq(IRQ_MFP_TIMA);
return;
}
AtaPlayNextFrame(2);
}
atari_enable_irq(IRQ_MFP_TIMA);
}
static irqreturn_t AtaInterrupt(int irq, void *dummy)
{
#if 0
static int cnt;
if (write_sq.active == 2)
if (++cnt == 10) {
cnt = 0;
return IRQ_HANDLED;
}
#endif
spin_lock(&dmasound.lock);
if (write_sq_ignore_int && is_falcon) {
write_sq_ignore_int = 0;
goto out;
}
if (!write_sq.active) {
WAKE_UP(write_sq.sync_queue);
goto out;
}
write_sq.count--;
write_sq.active--;
if (!write_sq.active) {
tt_dmasnd.ctrl = DMASND_CTRL_OFF;
write_sq_ignore_int = 1;
}
WAKE_UP(write_sq.action_queue);
if ((write_sq.active != 1) || (write_sq.count != 1))
AtaPlay();
if (!write_sq.active) WAKE_UP(write_sq.sync_queue);
out:
spin_unlock(&dmasound.lock);
return IRQ_HANDLED;
}
static void __init TTMixerInit(void)
{
atari_microwire_cmd(MW_LM1992_VOLUME(0));
dmasound.volume_left = 0;
atari_microwire_cmd(MW_LM1992_BALLEFT(0));
dmasound.volume_right = 0;
atari_microwire_cmd(MW_LM1992_BALRIGHT(0));
atari_microwire_cmd(MW_LM1992_TREBLE(0));
atari_microwire_cmd(MW_LM1992_BASS(0));
}
static void __init FalconMixerInit(void)
{
dmasound.volume_left = (tt_dmasnd.output_atten & 0xf00) >> 8;
dmasound.volume_right = (tt_dmasnd.output_atten & 0xf0) >> 4;
}
static int AtaMixerIoctl(u_int cmd, u_long arg)
{
int data;
unsigned long flags;
switch (cmd) {
case SOUND_MIXER_READ_SPEAKER:
if (is_falcon || MACH_IS_TT) {
int porta;
spin_lock_irqsave(&dmasound.lock, flags);
sound_ym.rd_data_reg_sel = 14;
porta = sound_ym.rd_data_reg_sel;
spin_unlock_irqrestore(&dmasound.lock, flags);
return IOCTL_OUT(arg, porta & 0x40 ? 0 : 100);
}
break;
case SOUND_MIXER_WRITE_VOLUME:
IOCTL_IN(arg, data);
return IOCTL_OUT(arg, dmasound_set_volume(data));
case SOUND_MIXER_WRITE_SPEAKER:
if (is_falcon || MACH_IS_TT) {
int porta;
IOCTL_IN(arg, data);
spin_lock_irqsave(&dmasound.lock, flags);
sound_ym.rd_data_reg_sel = 14;
porta = (sound_ym.rd_data_reg_sel & ~0x40) |
(data < 50 ? 0x40 : 0);
sound_ym.wd_data = porta;
spin_unlock_irqrestore(&dmasound.lock, flags);
return IOCTL_OUT(arg, porta & 0x40 ? 0 : 100);
}
}
return -EINVAL;
}
static int TTMixerIoctl(u_int cmd, u_long arg)
{
int data;
switch (cmd) {
case SOUND_MIXER_READ_RECMASK:
return IOCTL_OUT(arg, 0);
case SOUND_MIXER_READ_DEVMASK:
return IOCTL_OUT(arg,
SOUND_MASK_VOLUME | SOUND_MASK_TREBLE | SOUND_MASK_BASS |
(MACH_IS_TT ? SOUND_MASK_SPEAKER : 0));
case SOUND_MIXER_READ_STEREODEVS:
return IOCTL_OUT(arg, SOUND_MASK_VOLUME);
case SOUND_MIXER_READ_VOLUME:
return IOCTL_OUT(arg,
VOLUME_DB_TO_VOXWARE(dmasound.volume_left) |
(VOLUME_DB_TO_VOXWARE(dmasound.volume_right) << 8));
case SOUND_MIXER_READ_BASS:
return IOCTL_OUT(arg, TONE_DB_TO_VOXWARE(dmasound.bass));
case SOUND_MIXER_READ_TREBLE:
return IOCTL_OUT(arg, TONE_DB_TO_VOXWARE(dmasound.treble));
case SOUND_MIXER_READ_OGAIN:
return IOCTL_OUT(arg, GAIN_DB_TO_VOXWARE(dmasound.gain));
case SOUND_MIXER_WRITE_BASS:
IOCTL_IN(arg, data);
return IOCTL_OUT(arg, dmasound_set_bass(data));
case SOUND_MIXER_WRITE_TREBLE:
IOCTL_IN(arg, data);
return IOCTL_OUT(arg, dmasound_set_treble(data));
case SOUND_MIXER_WRITE_OGAIN:
IOCTL_IN(arg, data);
return IOCTL_OUT(arg, dmasound_set_gain(data));
}
return AtaMixerIoctl(cmd, arg);
}
static int FalconMixerIoctl(u_int cmd, u_long arg)
{
int data;
switch (cmd) {
case SOUND_MIXER_READ_RECMASK:
return IOCTL_OUT(arg, SOUND_MASK_MIC);
case SOUND_MIXER_READ_DEVMASK:
return IOCTL_OUT(arg, SOUND_MASK_VOLUME | SOUND_MASK_MIC | SOUND_MASK_SPEAKER);
case SOUND_MIXER_READ_STEREODEVS:
return IOCTL_OUT(arg, SOUND_MASK_VOLUME | SOUND_MASK_MIC);
case SOUND_MIXER_READ_VOLUME:
return IOCTL_OUT(arg,
VOLUME_ATT_TO_VOXWARE(dmasound.volume_left) |
VOLUME_ATT_TO_VOXWARE(dmasound.volume_right) << 8);
case SOUND_MIXER_READ_CAPS:
return IOCTL_OUT(arg, SOUND_CAP_EXCL_INPUT);
case SOUND_MIXER_WRITE_MIC:
IOCTL_IN(arg, data);
tt_dmasnd.input_gain =
RECLEVEL_VOXWARE_TO_GAIN(data & 0xff) << 4 |
RECLEVEL_VOXWARE_TO_GAIN(data >> 8 & 0xff);
case SOUND_MIXER_READ_MIC:
return IOCTL_OUT(arg,
RECLEVEL_GAIN_TO_VOXWARE(tt_dmasnd.input_gain >> 4 & 0xf) |
RECLEVEL_GAIN_TO_VOXWARE(tt_dmasnd.input_gain & 0xf) << 8);
}
return AtaMixerIoctl(cmd, arg);
}
static int AtaWriteSqSetup(void)
{
write_sq_ignore_int = 0;
return 0 ;
}
static int AtaSqOpen(fmode_t mode)
{
write_sq_ignore_int = 1;
return 0 ;
}
static int TTStateInfo(char *buffer, size_t space)
{
int len = 0;
len += sprintf(buffer+len, "\tvol left %ddB [-40... 0]\n",
dmasound.volume_left);
len += sprintf(buffer+len, "\tvol right %ddB [-40... 0]\n",
dmasound.volume_right);
len += sprintf(buffer+len, "\tbass %ddB [-12...+12]\n",
dmasound.bass);
len += sprintf(buffer+len, "\ttreble %ddB [-12...+12]\n",
dmasound.treble);
if (len >= space) {
printk(KERN_ERR "dmasound_atari: overflowed state buffer alloc.\n") ;
len = space ;
}
return len;
}
static int FalconStateInfo(char *buffer, size_t space)
{
int len = 0;
len += sprintf(buffer+len, "\tvol left %ddB [-22.5 ... 0]\n",
dmasound.volume_left);
len += sprintf(buffer+len, "\tvol right %ddB [-22.5 ... 0]\n",
dmasound.volume_right);
if (len >= space) {
printk(KERN_ERR "dmasound_atari: overflowed state buffer alloc.\n") ;
len = space ;
}
return len;
}
static int __init dmasound_atari_init(void)
{
if (MACH_IS_ATARI && ATARIHW_PRESENT(PCM_8BIT)) {
if (ATARIHW_PRESENT(CODEC)) {
dmasound.mach = machFalcon;
dmasound.mach.default_soft = def_soft ;
dmasound.mach.default_hard = def_hard_falcon ;
is_falcon = 1;
} else if (ATARIHW_PRESENT(MICROWIRE)) {
dmasound.mach = machTT;
dmasound.mach.default_soft = def_soft ;
dmasound.mach.default_hard = def_hard_tt ;
is_falcon = 0;
} else
return -ENODEV;
if ((st_mfp.int_en_a & st_mfp.int_mk_a & 0x20) == 0)
return dmasound_init();
else {
printk("DMA sound driver: Timer A interrupt already in use\n");
return -EBUSY;
}
}
return -ENODEV;
}
static void __exit dmasound_atari_cleanup(void)
{
dmasound_deinit();
}
