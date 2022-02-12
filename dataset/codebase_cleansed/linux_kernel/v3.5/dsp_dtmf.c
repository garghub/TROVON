void dsp_dtmf_goertzel_init(struct dsp *dsp)
{
dsp->dtmf.size = 0;
dsp->dtmf.lastwhat = '\0';
dsp->dtmf.lastdigit = '\0';
dsp->dtmf.count = 0;
}
void dsp_dtmf_hardware(struct dsp *dsp)
{
int hardware = 1;
if (!dsp->dtmf.enable)
return;
if (!dsp->features.hfc_dtmf)
hardware = 0;
if (dsp->tx_volume) {
if (dsp_debug & DEBUG_DSP_DTMF)
printk(KERN_DEBUG "%s dsp %s cannot do hardware DTMF, "
"because tx_volume is changed\n",
__func__, dsp->name);
hardware = 0;
}
if (dsp->rx_volume) {
if (dsp_debug & DEBUG_DSP_DTMF)
printk(KERN_DEBUG "%s dsp %s cannot do hardware DTMF, "
"because rx_volume is changed\n",
__func__, dsp->name);
hardware = 0;
}
if (dsp->bf_enable) {
if (dsp_debug & DEBUG_DSP_DTMF)
printk(KERN_DEBUG "%s dsp %s cannot do hardware DTMF, "
"because encryption is enabled\n",
__func__, dsp->name);
hardware = 0;
}
if (dsp->pipeline.inuse) {
if (dsp_debug & DEBUG_DSP_DTMF)
printk(KERN_DEBUG "%s dsp %s cannot do hardware DTMF, "
"because pipeline exists.\n",
__func__, dsp->name);
hardware = 0;
}
dsp->dtmf.hardware = hardware;
dsp->dtmf.software = !hardware;
}
u8
*dsp_dtmf_goertzel_decode(struct dsp *dsp, u8 *data, int len, int fmt)
{
u8 what;
int size;
signed short *buf;
s32 sk, sk1, sk2;
int k, n, i;
s32 *hfccoeff;
s32 result[NCOEFF], tresh, treshl;
int lowgroup, highgroup;
s64 cos2pik_;
dsp->dtmf.digits[0] = '\0';
again:
size = dsp->dtmf.size;
buf = dsp->dtmf.buffer;
switch (fmt) {
case 0:
case 1:
while (size < DSP_DTMF_NPOINTS && len) {
buf[size++] = dsp_audio_law_to_s32[*data++];
len--;
}
break;
case 2:
default:
if (len < 64) {
if (len > 0)
printk(KERN_ERR "%s: coefficients have invalid "
"size. (is=%d < must=%d)\n",
__func__, len, 64);
return dsp->dtmf.digits;
}
hfccoeff = (s32 *)data;
for (k = 0; k < NCOEFF; k++) {
sk2 = (*hfccoeff++) >> 4;
sk = (*hfccoeff++) >> 4;
if (sk > 32767 || sk < -32767 || sk2 > 32767
|| sk2 < -32767)
printk(KERN_WARNING
"DTMF-Detection overflow\n");
result[k] =
(sk * sk) -
(((cos2pik[k] * sk) >> 15) * sk2) +
(sk2 * sk2);
}
data += 64;
len -= 64;
goto coefficients;
break;
}
dsp->dtmf.size = size;
if (size < DSP_DTMF_NPOINTS)
return dsp->dtmf.digits;
dsp->dtmf.size = 0;
for (k = 0; k < NCOEFF; k++) {
sk = 0;
sk1 = 0;
sk2 = 0;
buf = dsp->dtmf.buffer;
cos2pik_ = cos2pik[k];
for (n = 0; n < DSP_DTMF_NPOINTS; n++) {
sk = ((cos2pik_ * sk1) >> 15) - sk2 + (*buf++);
sk2 = sk1;
sk1 = sk;
}
sk >>= 8;
sk2 >>= 8;
if (sk > 32767 || sk < -32767 || sk2 > 32767 || sk2 < -32767)
printk(KERN_WARNING "DTMF-Detection overflow\n");
result[k] =
(sk * sk) -
(((cos2pik[k] * sk) >> 15) * sk2) +
(sk2 * sk2);
}
coefficients:
tresh = 0;
for (i = 0; i < NCOEFF; i++) {
if (result[i] < 0)
result[i] = 0;
if (result[i] > dsp->dtmf.treshold) {
if (result[i] > tresh)
tresh = result[i];
}
}
if (tresh == 0) {
what = 0;
goto storedigit;
}
if (dsp_debug & DEBUG_DSP_DTMFCOEFF) {
s32 tresh_100 = tresh/100;
if (tresh_100 == 0) {
tresh_100 = 1;
printk(KERN_DEBUG
"tresh(%d) too small set tresh/100 to 1\n",
tresh);
}
printk(KERN_DEBUG "a %3d %3d %3d %3d %3d %3d %3d %3d"
" tr:%3d r %3d %3d %3d %3d %3d %3d %3d %3d\n",
result[0] / 10000, result[1] / 10000, result[2] / 10000,
result[3] / 10000, result[4] / 10000, result[5] / 10000,
result[6] / 10000, result[7] / 10000, tresh / 10000,
result[0] / (tresh_100), result[1] / (tresh_100),
result[2] / (tresh_100), result[3] / (tresh_100),
result[4] / (tresh_100), result[5] / (tresh_100),
result[6] / (tresh_100), result[7] / (tresh_100));
}
lowgroup = -1;
highgroup = -1;
treshl = tresh >> 3;
tresh = tresh >> 2;
for (i = 0; i < NCOEFF; i++) {
if (result[i] < treshl)
continue;
if (result[i] < tresh) {
lowgroup = -1;
highgroup = -1;
break;
}
if (i < NCOEFF / 2) {
if (lowgroup >= 0) {
lowgroup = -1;
break;
} else
lowgroup = i;
} else {
if (highgroup >= 0) {
highgroup = -1;
break;
} else
highgroup = i - (NCOEFF / 2);
}
}
what = 0;
if (lowgroup >= 0 && highgroup >= 0)
what = dtmf_matrix[lowgroup][highgroup];
storedigit:
if (what && (dsp_debug & DEBUG_DSP_DTMF))
printk(KERN_DEBUG "DTMF what: %c\n", what);
if (dsp->dtmf.lastwhat != what)
dsp->dtmf.count = 0;
if (dsp->dtmf.count == 2) {
if (dsp->dtmf.lastdigit != what) {
dsp->dtmf.lastdigit = what;
if (what) {
if (dsp_debug & DEBUG_DSP_DTMF)
printk(KERN_DEBUG "DTMF digit: %c\n",
what);
if ((strlen(dsp->dtmf.digits) + 1)
< sizeof(dsp->dtmf.digits)) {
dsp->dtmf.digits[strlen(
dsp->dtmf.digits) + 1] = '\0';
dsp->dtmf.digits[strlen(
dsp->dtmf.digits)] = what;
}
}
}
} else
dsp->dtmf.count++;
dsp->dtmf.lastwhat = what;
goto again;
}
