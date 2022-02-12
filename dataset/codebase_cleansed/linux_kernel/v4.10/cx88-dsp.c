static s32 int_cos(u32 x)
{
u32 t2, t4, t6, t8;
s32 ret;
u16 period = x / INT_PI;
if (period % 2)
return -int_cos(x - INT_PI);
x = x % INT_PI;
if (x > INT_PI / 2)
return -int_cos(INT_PI / 2 - (x % (INT_PI / 2)));
t2 = x * x / 32768 / 2;
t4 = t2 * x / 32768 * x / 32768 / 3 / 4;
t6 = t4 * x / 32768 * x / 32768 / 5 / 6;
t8 = t6 * x / 32768 * x / 32768 / 7 / 8;
ret = 32768 - t2 + t4 - t6 + t8;
return ret;
}
static u32 int_goertzel(s16 x[], u32 N, u32 freq)
{
s32 s_prev = 0;
s32 s_prev2 = 0;
s32 coeff = 2 * int_cos(freq);
u32 i;
u64 tmp;
u32 divisor;
for (i = 0; i < N; i++) {
s32 s = x[i] + ((s64)coeff * s_prev / 32768) - s_prev2;
s_prev2 = s_prev;
s_prev = s;
}
tmp = (s64)s_prev2 * s_prev2 + (s64)s_prev * s_prev -
(s64)coeff * s_prev2 * s_prev / 32768;
divisor = N * N;
do_div(tmp, divisor);
return (u32)tmp;
}
static u32 freq_magnitude(s16 x[], u32 N, u32 freq)
{
u32 sum = int_goertzel(x, N, freq);
return (u32)int_sqrt(sum);
}
static u32 noise_magnitude(s16 x[], u32 N, u32 freq_start, u32 freq_end)
{
int i;
u32 sum = 0;
u32 freq_step;
int samples = 5;
if (N > 192) {
x += (N - 192);
N = 192;
}
freq_step = (freq_end - freq_start) / (samples - 1);
for (i = 0; i < samples; i++) {
sum += int_goertzel(x, N, freq_start);
freq_start += freq_step;
}
return (u32)int_sqrt(sum / samples);
}
static s32 detect_a2_a2m_eiaj(struct cx88_core *core, s16 x[], u32 N)
{
s32 carrier, stereo, dual, noise;
s32 carrier_freq, stereo_freq, dual_freq;
s32 ret;
switch (core->tvaudio) {
case WW_BG:
case WW_DK:
carrier_freq = FREQ_A2_CARRIER;
stereo_freq = FREQ_A2_STEREO;
dual_freq = FREQ_A2_DUAL;
break;
case WW_M:
carrier_freq = FREQ_A2M_CARRIER;
stereo_freq = FREQ_A2M_STEREO;
dual_freq = FREQ_A2M_DUAL;
break;
case WW_EIAJ:
carrier_freq = FREQ_EIAJ_CARRIER;
stereo_freq = FREQ_EIAJ_STEREO;
dual_freq = FREQ_EIAJ_DUAL;
break;
default:
pr_warn("unsupported audio mode %d for %s\n",
core->tvaudio, __func__);
return UNSET;
}
carrier = freq_magnitude(x, N, carrier_freq);
stereo = freq_magnitude(x, N, stereo_freq);
dual = freq_magnitude(x, N, dual_freq);
noise = noise_magnitude(x, N, FREQ_NOISE_START, FREQ_NOISE_END);
dprintk(1,
"detect a2/a2m/eiaj: carrier=%d, stereo=%d, dual=%d, noise=%d\n",
carrier, stereo, dual, noise);
if (stereo > dual)
ret = V4L2_TUNER_SUB_STEREO;
else
ret = V4L2_TUNER_SUB_LANG1 | V4L2_TUNER_SUB_LANG2;
if (core->tvaudio == WW_EIAJ) {
if ((carrier > max(stereo, dual) * 2) &&
(carrier < max(stereo, dual) * 6) &&
(carrier > 20 && carrier < 200) &&
(max(stereo, dual) > min(stereo, dual))) {
return ret;
}
} else {
if ((carrier > max(stereo, dual) * 2) &&
(carrier < max(stereo, dual) * 8) &&
(carrier > 20 && carrier < 200) &&
(noise < 10) &&
(max(stereo, dual) > min(stereo, dual) * 2)) {
return ret;
}
}
return V4L2_TUNER_SUB_MONO;
}
static s32 detect_btsc(struct cx88_core *core, s16 x[], u32 N)
{
s32 sap_ref = freq_magnitude(x, N, FREQ_BTSC_SAP_REF);
s32 sap = freq_magnitude(x, N, FREQ_BTSC_SAP);
s32 dual_ref = freq_magnitude(x, N, FREQ_BTSC_DUAL_REF);
s32 dual = freq_magnitude(x, N, FREQ_BTSC_DUAL);
dprintk(1, "detect btsc: dual_ref=%d, dual=%d, sap_ref=%d, sap=%d\n",
dual_ref, dual, sap_ref, sap);
return UNSET;
}
static s16 *read_rds_samples(struct cx88_core *core, u32 *N)
{
const struct sram_channel *srch = &cx88_sram_channels[SRAM_CH27];
s16 *samples;
unsigned int i;
unsigned int bpl = srch->fifo_size / AUD_RDS_LINES;
unsigned int spl = bpl / 4;
unsigned int sample_count = spl * (AUD_RDS_LINES - 1);
u32 current_address = cx_read(srch->ptr1_reg);
u32 offset = (current_address - srch->fifo_start + bpl);
dprintk(1,
"read RDS samples: current_address=%08x (offset=%08x), sample_count=%d, aud_intstat=%08x\n",
current_address,
current_address - srch->fifo_start, sample_count,
cx_read(MO_AUD_INTSTAT));
samples = kmalloc_array(sample_count, sizeof(*samples), GFP_KERNEL);
if (!samples)
return NULL;
*N = sample_count;
for (i = 0; i < sample_count; i++) {
offset = offset % (AUD_RDS_LINES * bpl);
samples[i] = cx_read(srch->fifo_start + offset);
offset += 4;
}
dprintk(2, "RDS samples dump: %*ph\n", sample_count, samples);
return samples;
}
s32 cx88_dsp_detect_stereo_sap(struct cx88_core *core)
{
s16 *samples;
u32 N = 0;
s32 ret = UNSET;
if (!(cx_read(MO_AUD_DMACNTRL) & 0x04))
return ret;
if (!(cx_read(AUD_CTL) & EN_FMRADIO_EN_RDS))
return ret;
if (time_before(jiffies, core->last_change + msecs_to_jiffies(500)))
return ret;
samples = read_rds_samples(core, &N);
if (!samples)
return ret;
switch (core->tvaudio) {
case WW_BG:
case WW_DK:
case WW_EIAJ:
case WW_M:
ret = detect_a2_a2m_eiaj(core, samples, N);
break;
case WW_BTSC:
ret = detect_btsc(core, samples, N);
break;
case WW_NONE:
case WW_I:
case WW_L:
case WW_I2SPT:
case WW_FM:
case WW_I2SADC:
break;
}
kfree(samples);
if (ret != UNSET)
dprintk(1, "stereo/sap detection result:%s%s%s\n",
(ret & V4L2_TUNER_SUB_MONO) ? " mono" : "",
(ret & V4L2_TUNER_SUB_STEREO) ? " stereo" : "",
(ret & V4L2_TUNER_SUB_LANG2) ? " dual" : "");
return ret;
}
