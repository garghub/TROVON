static struct snd_pcm_substream *
had_substream_get(struct snd_intelhad *intelhaddata)
{
struct snd_pcm_substream *substream;
unsigned long flags;
spin_lock_irqsave(&intelhaddata->had_spinlock, flags);
substream = intelhaddata->stream_info.substream;
if (substream)
intelhaddata->stream_info.substream_refcount++;
spin_unlock_irqrestore(&intelhaddata->had_spinlock, flags);
return substream;
}
static void had_substream_put(struct snd_intelhad *intelhaddata)
{
unsigned long flags;
spin_lock_irqsave(&intelhaddata->had_spinlock, flags);
intelhaddata->stream_info.substream_refcount--;
spin_unlock_irqrestore(&intelhaddata->had_spinlock, flags);
}
static u32 had_read_register_raw(struct snd_intelhad *ctx, u32 reg)
{
return ioread32(ctx->mmio_start + ctx->had_config_offset + reg);
}
static void had_write_register_raw(struct snd_intelhad *ctx, u32 reg, u32 val)
{
iowrite32(val, ctx->mmio_start + ctx->had_config_offset + reg);
}
static void had_read_register(struct snd_intelhad *ctx, u32 reg, u32 *val)
{
if (!ctx->connected)
*val = 0;
else
*val = had_read_register_raw(ctx, reg);
}
static void had_write_register(struct snd_intelhad *ctx, u32 reg, u32 val)
{
if (ctx->connected)
had_write_register_raw(ctx, reg, val);
}
static void had_enable_audio(struct snd_intelhad *intelhaddata,
bool enable)
{
intelhaddata->aud_config.regx.aud_en = enable;
had_write_register(intelhaddata, AUD_CONFIG,
intelhaddata->aud_config.regval);
}
static void had_ack_irqs(struct snd_intelhad *ctx)
{
u32 status_reg;
if (!ctx->connected)
return;
had_read_register(ctx, AUD_HDMI_STATUS, &status_reg);
status_reg |= HDMI_AUDIO_BUFFER_DONE | HDMI_AUDIO_UNDERRUN;
had_write_register(ctx, AUD_HDMI_STATUS, status_reg);
had_read_register(ctx, AUD_HDMI_STATUS, &status_reg);
}
static void had_reset_audio(struct snd_intelhad *intelhaddata)
{
had_write_register(intelhaddata, AUD_HDMI_STATUS,
AUD_HDMI_STATUSG_MASK_FUNCRST);
had_write_register(intelhaddata, AUD_HDMI_STATUS, 0);
}
static int had_prog_status_reg(struct snd_pcm_substream *substream,
struct snd_intelhad *intelhaddata)
{
union aud_cfg cfg_val = {.regval = 0};
union aud_ch_status_0 ch_stat0 = {.regval = 0};
union aud_ch_status_1 ch_stat1 = {.regval = 0};
ch_stat0.regx.lpcm_id = (intelhaddata->aes_bits &
IEC958_AES0_NONAUDIO) >> 1;
ch_stat0.regx.clk_acc = (intelhaddata->aes_bits &
IEC958_AES3_CON_CLOCK) >> 4;
cfg_val.regx.val_bit = ch_stat0.regx.lpcm_id;
switch (substream->runtime->rate) {
case AUD_SAMPLE_RATE_32:
ch_stat0.regx.samp_freq = CH_STATUS_MAP_32KHZ;
break;
case AUD_SAMPLE_RATE_44_1:
ch_stat0.regx.samp_freq = CH_STATUS_MAP_44KHZ;
break;
case AUD_SAMPLE_RATE_48:
ch_stat0.regx.samp_freq = CH_STATUS_MAP_48KHZ;
break;
case AUD_SAMPLE_RATE_88_2:
ch_stat0.regx.samp_freq = CH_STATUS_MAP_88KHZ;
break;
case AUD_SAMPLE_RATE_96:
ch_stat0.regx.samp_freq = CH_STATUS_MAP_96KHZ;
break;
case AUD_SAMPLE_RATE_176_4:
ch_stat0.regx.samp_freq = CH_STATUS_MAP_176KHZ;
break;
case AUD_SAMPLE_RATE_192:
ch_stat0.regx.samp_freq = CH_STATUS_MAP_192KHZ;
break;
default:
return -EINVAL;
}
had_write_register(intelhaddata,
AUD_CH_STATUS_0, ch_stat0.regval);
switch (substream->runtime->format) {
case SNDRV_PCM_FORMAT_S16_LE:
ch_stat1.regx.max_wrd_len = MAX_SMPL_WIDTH_20;
ch_stat1.regx.wrd_len = SMPL_WIDTH_16BITS;
break;
case SNDRV_PCM_FORMAT_S24_LE:
case SNDRV_PCM_FORMAT_S32_LE:
ch_stat1.regx.max_wrd_len = MAX_SMPL_WIDTH_24;
ch_stat1.regx.wrd_len = SMPL_WIDTH_24BITS;
break;
default:
return -EINVAL;
}
had_write_register(intelhaddata,
AUD_CH_STATUS_1, ch_stat1.regval);
return 0;
}
static int had_init_audio_ctrl(struct snd_pcm_substream *substream,
struct snd_intelhad *intelhaddata)
{
union aud_cfg cfg_val = {.regval = 0};
union aud_buf_config buf_cfg = {.regval = 0};
u8 channels;
had_prog_status_reg(substream, intelhaddata);
buf_cfg.regx.audio_fifo_watermark = FIFO_THRESHOLD;
buf_cfg.regx.dma_fifo_watermark = DMA_FIFO_THRESHOLD;
buf_cfg.regx.aud_delay = 0;
had_write_register(intelhaddata, AUD_BUF_CONFIG, buf_cfg.regval);
channels = substream->runtime->channels;
cfg_val.regx.num_ch = channels - 2;
if (channels <= 2)
cfg_val.regx.layout = LAYOUT0;
else
cfg_val.regx.layout = LAYOUT1;
if (substream->runtime->format == SNDRV_PCM_FORMAT_S16_LE)
cfg_val.regx.packet_mode = 1;
if (substream->runtime->format == SNDRV_PCM_FORMAT_S32_LE)
cfg_val.regx.left_align = 1;
cfg_val.regx.val_bit = 1;
if (intelhaddata->dp_output) {
cfg_val.regx.dp_modei = 1;
cfg_val.regx.set = 1;
}
had_write_register(intelhaddata, AUD_CONFIG, cfg_val.regval);
intelhaddata->aud_config = cfg_val;
return 0;
}
static void init_channel_allocations(void)
{
int i, j;
struct cea_channel_speaker_allocation *p;
for (i = 0; i < ARRAY_SIZE(channel_allocations); i++) {
p = channel_allocations + i;
p->channels = 0;
p->spk_mask = 0;
for (j = 0; j < ARRAY_SIZE(p->speakers); j++)
if (p->speakers[j]) {
p->channels++;
p->spk_mask |= p->speakers[j];
}
}
}
static int had_channel_allocation(struct snd_intelhad *intelhaddata,
int channels)
{
int i;
int ca = 0;
int spk_mask = 0;
if (channels <= 2)
return 0;
for (i = 0; i < ARRAY_SIZE(eld_speaker_allocation_bits); i++) {
if (intelhaddata->eld[DRM_ELD_SPEAKER] & (1 << i))
spk_mask |= eld_speaker_allocation_bits[i];
}
for (i = 0; i < ARRAY_SIZE(channel_allocations); i++) {
if (channels == channel_allocations[i].channels &&
(spk_mask & channel_allocations[i].spk_mask) ==
channel_allocations[i].spk_mask) {
ca = channel_allocations[i].ca_index;
break;
}
}
dev_dbg(intelhaddata->dev, "select CA 0x%x for %d\n", ca, channels);
return ca;
}
static int spk_to_chmap(int spk)
{
const struct channel_map_table *t = map_tables;
for (; t->map; t++) {
if (t->spk_mask == spk)
return t->map;
}
return 0;
}
static void had_build_channel_allocation_map(struct snd_intelhad *intelhaddata)
{
int i, c;
int spk_mask = 0;
struct snd_pcm_chmap_elem *chmap;
u8 eld_high, eld_high_mask = 0xF0;
u8 high_msb;
kfree(intelhaddata->chmap->chmap);
intelhaddata->chmap->chmap = NULL;
chmap = kzalloc(sizeof(*chmap), GFP_KERNEL);
if (!chmap)
return;
dev_dbg(intelhaddata->dev, "eld speaker = %x\n",
intelhaddata->eld[DRM_ELD_SPEAKER]);
eld_high = intelhaddata->eld[DRM_ELD_SPEAKER] & eld_high_mask;
if ((eld_high & (eld_high-1)) && (eld_high > 0x1F)) {
for (i = 1; i < 4; i++) {
high_msb = eld_high & (0x80 >> i);
if (high_msb) {
intelhaddata->eld[DRM_ELD_SPEAKER] &=
high_msb | 0xF;
break;
}
}
}
for (i = 0; i < ARRAY_SIZE(eld_speaker_allocation_bits); i++) {
if (intelhaddata->eld[DRM_ELD_SPEAKER] & (1 << i))
spk_mask |= eld_speaker_allocation_bits[i];
}
for (i = 0; i < ARRAY_SIZE(channel_allocations); i++) {
if (spk_mask == channel_allocations[i].spk_mask) {
for (c = 0; c < channel_allocations[i].channels; c++) {
chmap->map[c] = spk_to_chmap(
channel_allocations[i].speakers[
(MAX_SPEAKERS - 1) - c]);
}
chmap->channels = channel_allocations[i].channels;
intelhaddata->chmap->chmap = chmap;
break;
}
}
if (i >= ARRAY_SIZE(channel_allocations))
kfree(chmap);
}
static int had_chmap_ctl_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = HAD_MAX_CHANNEL;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = SNDRV_CHMAP_LAST;
return 0;
}
static int had_chmap_ctl_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_pcm_chmap *info = snd_kcontrol_chip(kcontrol);
struct snd_intelhad *intelhaddata = info->private_data;
int i;
const struct snd_pcm_chmap_elem *chmap;
memset(ucontrol->value.integer.value, 0,
sizeof(long) * HAD_MAX_CHANNEL);
mutex_lock(&intelhaddata->mutex);
if (!intelhaddata->chmap->chmap) {
mutex_unlock(&intelhaddata->mutex);
return 0;
}
chmap = intelhaddata->chmap->chmap;
for (i = 0; i < chmap->channels; i++)
ucontrol->value.integer.value[i] = chmap->map[i];
mutex_unlock(&intelhaddata->mutex);
return 0;
}
static int had_register_chmap_ctls(struct snd_intelhad *intelhaddata,
struct snd_pcm *pcm)
{
int err;
err = snd_pcm_add_chmap_ctls(pcm, SNDRV_PCM_STREAM_PLAYBACK,
NULL, 0, (unsigned long)intelhaddata,
&intelhaddata->chmap);
if (err < 0)
return err;
intelhaddata->chmap->private_data = intelhaddata;
intelhaddata->chmap->kctl->info = had_chmap_ctl_info;
intelhaddata->chmap->kctl->get = had_chmap_ctl_get;
intelhaddata->chmap->chmap = NULL;
return 0;
}
static void had_prog_dip(struct snd_pcm_substream *substream,
struct snd_intelhad *intelhaddata)
{
int i;
union aud_ctrl_st ctrl_state = {.regval = 0};
union aud_info_frame2 frame2 = {.regval = 0};
union aud_info_frame3 frame3 = {.regval = 0};
u8 checksum = 0;
u32 info_frame;
int channels;
int ca;
channels = substream->runtime->channels;
had_write_register(intelhaddata, AUD_CNTL_ST, ctrl_state.regval);
ca = had_channel_allocation(intelhaddata, channels);
if (intelhaddata->dp_output) {
info_frame = DP_INFO_FRAME_WORD1;
frame2.regval = (substream->runtime->channels - 1) | (ca << 24);
} else {
info_frame = HDMI_INFO_FRAME_WORD1;
frame2.regx.chnl_cnt = substream->runtime->channels - 1;
frame3.regx.chnl_alloc = ca;
for (i = 0; i < BYTES_PER_WORD; i++)
checksum += (info_frame >> (i * 8)) & 0xff;
for (i = 0; i < BYTES_PER_WORD; i++)
checksum += (frame2.regval >> (i * 8)) & 0xff;
for (i = 0; i < BYTES_PER_WORD; i++)
checksum += (frame3.regval >> (i * 8)) & 0xff;
frame2.regx.chksum = -(checksum);
}
had_write_register(intelhaddata, AUD_HDMIW_INFOFR, info_frame);
had_write_register(intelhaddata, AUD_HDMIW_INFOFR, frame2.regval);
had_write_register(intelhaddata, AUD_HDMIW_INFOFR, frame3.regval);
for (i = 0; i < HAD_MAX_DIP_WORDS-VALID_DIP_WORDS; i++)
had_write_register(intelhaddata, AUD_HDMIW_INFOFR, 0x0);
ctrl_state.regx.dip_freq = 1;
ctrl_state.regx.dip_en_sta = 1;
had_write_register(intelhaddata, AUD_CNTL_ST, ctrl_state.regval);
}
static int had_calculate_maud_value(u32 aud_samp_freq, u32 link_rate)
{
u32 maud_val;
if (link_rate == DP_2_7_GHZ) {
switch (aud_samp_freq) {
case AUD_SAMPLE_RATE_32:
maud_val = AUD_SAMPLE_RATE_32_DP_2_7_MAUD_VAL;
break;
case AUD_SAMPLE_RATE_44_1:
maud_val = AUD_SAMPLE_RATE_44_1_DP_2_7_MAUD_VAL;
break;
case AUD_SAMPLE_RATE_48:
maud_val = AUD_SAMPLE_RATE_48_DP_2_7_MAUD_VAL;
break;
case AUD_SAMPLE_RATE_88_2:
maud_val = AUD_SAMPLE_RATE_88_2_DP_2_7_MAUD_VAL;
break;
case AUD_SAMPLE_RATE_96:
maud_val = AUD_SAMPLE_RATE_96_DP_2_7_MAUD_VAL;
break;
case AUD_SAMPLE_RATE_176_4:
maud_val = AUD_SAMPLE_RATE_176_4_DP_2_7_MAUD_VAL;
break;
case HAD_MAX_RATE:
maud_val = HAD_MAX_RATE_DP_2_7_MAUD_VAL;
break;
default:
maud_val = -EINVAL;
break;
}
} else if (link_rate == DP_1_62_GHZ) {
switch (aud_samp_freq) {
case AUD_SAMPLE_RATE_32:
maud_val = AUD_SAMPLE_RATE_32_DP_1_62_MAUD_VAL;
break;
case AUD_SAMPLE_RATE_44_1:
maud_val = AUD_SAMPLE_RATE_44_1_DP_1_62_MAUD_VAL;
break;
case AUD_SAMPLE_RATE_48:
maud_val = AUD_SAMPLE_RATE_48_DP_1_62_MAUD_VAL;
break;
case AUD_SAMPLE_RATE_88_2:
maud_val = AUD_SAMPLE_RATE_88_2_DP_1_62_MAUD_VAL;
break;
case AUD_SAMPLE_RATE_96:
maud_val = AUD_SAMPLE_RATE_96_DP_1_62_MAUD_VAL;
break;
case AUD_SAMPLE_RATE_176_4:
maud_val = AUD_SAMPLE_RATE_176_4_DP_1_62_MAUD_VAL;
break;
case HAD_MAX_RATE:
maud_val = HAD_MAX_RATE_DP_1_62_MAUD_VAL;
break;
default:
maud_val = -EINVAL;
break;
}
} else
maud_val = -EINVAL;
return maud_val;
}
static void had_prog_cts(u32 aud_samp_freq, u32 tmds, u32 link_rate,
u32 n_param, struct snd_intelhad *intelhaddata)
{
u32 cts_val;
u64 dividend, divisor;
if (intelhaddata->dp_output) {
cts_val = had_calculate_maud_value(aud_samp_freq, link_rate);
} else {
dividend = (u64)tmds * n_param*1000;
divisor = 128 * aud_samp_freq;
cts_val = div64_u64(dividend, divisor);
}
dev_dbg(intelhaddata->dev, "TMDS value=%d, N value=%d, CTS Value=%d\n",
tmds, n_param, cts_val);
had_write_register(intelhaddata, AUD_HDMI_CTS, (BIT(24) | cts_val));
}
static int had_calculate_n_value(u32 aud_samp_freq)
{
int n_val;
switch (aud_samp_freq) {
case AUD_SAMPLE_RATE_32:
n_val = 4096;
break;
case AUD_SAMPLE_RATE_44_1:
n_val = 6272;
break;
case AUD_SAMPLE_RATE_48:
n_val = 6144;
break;
case AUD_SAMPLE_RATE_88_2:
n_val = 12544;
break;
case AUD_SAMPLE_RATE_96:
n_val = 12288;
break;
case AUD_SAMPLE_RATE_176_4:
n_val = 25088;
break;
case HAD_MAX_RATE:
n_val = 24576;
break;
default:
n_val = -EINVAL;
break;
}
return n_val;
}
static int had_prog_n(u32 aud_samp_freq, u32 *n_param,
struct snd_intelhad *intelhaddata)
{
int n_val;
if (intelhaddata->dp_output) {
n_val = DP_NAUD_VAL;
} else
n_val = had_calculate_n_value(aud_samp_freq);
if (n_val < 0)
return n_val;
had_write_register(intelhaddata, AUD_N_ENABLE, (BIT(24) | n_val));
*n_param = n_val;
return 0;
}
static void had_prog_bd(struct snd_pcm_substream *substream,
struct snd_intelhad *intelhaddata)
{
int idx = intelhaddata->bd_head;
int ofs = intelhaddata->pcmbuf_filled * intelhaddata->period_bytes;
u32 addr = substream->runtime->dma_addr + ofs;
addr |= AUD_BUF_VALID;
if (!substream->runtime->no_period_wakeup)
addr |= AUD_BUF_INTR_EN;
had_write_register(intelhaddata, AUD_BUF_ADDR(idx), addr);
had_write_register(intelhaddata, AUD_BUF_LEN(idx),
intelhaddata->period_bytes);
intelhaddata->bd_head++;
intelhaddata->bd_head %= intelhaddata->num_bds;
intelhaddata->pcmbuf_filled++;
intelhaddata->pcmbuf_filled %= substream->runtime->periods;
}
static void had_invalidate_bd(struct snd_intelhad *intelhaddata,
int idx)
{
had_write_register(intelhaddata, AUD_BUF_ADDR(idx), 0);
had_write_register(intelhaddata, AUD_BUF_LEN(idx), 0);
}
static void had_init_ringbuf(struct snd_pcm_substream *substream,
struct snd_intelhad *intelhaddata)
{
struct snd_pcm_runtime *runtime = substream->runtime;
int i, num_periods;
num_periods = runtime->periods;
intelhaddata->num_bds = min(num_periods, HAD_NUM_OF_RING_BUFS);
intelhaddata->num_bds = max(intelhaddata->num_bds, 2U);
intelhaddata->period_bytes =
frames_to_bytes(runtime, runtime->period_size);
WARN_ON(intelhaddata->period_bytes & 0x3f);
intelhaddata->bd_head = 0;
intelhaddata->pcmbuf_head = 0;
intelhaddata->pcmbuf_filled = 0;
for (i = 0; i < HAD_NUM_OF_RING_BUFS; i++) {
if (i < intelhaddata->num_bds)
had_prog_bd(substream, intelhaddata);
else
had_invalidate_bd(intelhaddata, i);
}
intelhaddata->bd_head = 0;
}
static void had_advance_ringbuf(struct snd_pcm_substream *substream,
struct snd_intelhad *intelhaddata)
{
int num_periods = substream->runtime->periods;
had_prog_bd(substream, intelhaddata);
intelhaddata->pcmbuf_head++;
intelhaddata->pcmbuf_head %= num_periods;
}
static int had_process_ringbuf(struct snd_pcm_substream *substream,
struct snd_intelhad *intelhaddata)
{
int len, processed;
unsigned long flags;
processed = 0;
spin_lock_irqsave(&intelhaddata->had_spinlock, flags);
for (;;) {
had_read_register(intelhaddata,
AUD_BUF_LEN(intelhaddata->bd_head),
&len);
if (len < 0 || len > intelhaddata->period_bytes) {
dev_dbg(intelhaddata->dev, "Invalid buf length %d\n",
len);
len = -EPIPE;
goto out;
}
if (len > 0)
break;
if (++processed >= intelhaddata->num_bds) {
len = -EPIPE;
goto out;
}
had_advance_ringbuf(substream, intelhaddata);
}
len = intelhaddata->period_bytes - len;
len += intelhaddata->period_bytes * intelhaddata->pcmbuf_head;
out:
spin_unlock_irqrestore(&intelhaddata->had_spinlock, flags);
return len;
}
static void had_process_buffer_done(struct snd_intelhad *intelhaddata)
{
struct snd_pcm_substream *substream;
substream = had_substream_get(intelhaddata);
if (!substream)
return;
if (!intelhaddata->connected) {
snd_pcm_stop_xrun(substream);
goto out;
}
if (had_process_ringbuf(substream, intelhaddata) < 0)
snd_pcm_stop_xrun(substream);
else
snd_pcm_period_elapsed(substream);
out:
had_substream_put(intelhaddata);
}
static void wait_clear_underrun_bit(struct snd_intelhad *intelhaddata)
{
int i;
u32 val;
for (i = 0; i < 100; i++) {
had_read_register(intelhaddata, AUD_HDMI_STATUS, &val);
if (!(val & AUD_HDMI_STATUS_MASK_UNDERRUN))
return;
udelay(100);
cond_resched();
had_write_register(intelhaddata, AUD_HDMI_STATUS, val);
}
dev_err(intelhaddata->dev, "Unable to clear UNDERRUN bits\n");
}
static void had_do_reset(struct snd_intelhad *intelhaddata)
{
if (!intelhaddata->need_reset || !intelhaddata->connected)
return;
had_reset_audio(intelhaddata);
wait_clear_underrun_bit(intelhaddata);
intelhaddata->need_reset = false;
}
static void had_process_buffer_underrun(struct snd_intelhad *intelhaddata)
{
struct snd_pcm_substream *substream;
substream = had_substream_get(intelhaddata);
if (substream) {
snd_pcm_stop_xrun(substream);
had_substream_put(intelhaddata);
}
intelhaddata->need_reset = true;
}
static int had_pcm_open(struct snd_pcm_substream *substream)
{
struct snd_intelhad *intelhaddata;
struct snd_pcm_runtime *runtime;
int retval;
intelhaddata = snd_pcm_substream_chip(substream);
runtime = substream->runtime;
pm_runtime_get_sync(intelhaddata->dev);
runtime->hw = had_pcm_hardware;
retval = snd_pcm_hw_constraint_integer(runtime,
SNDRV_PCM_HW_PARAM_PERIODS);
if (retval < 0)
goto error;
retval = snd_pcm_hw_constraint_step(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_PERIOD_BYTES, 64);
if (retval < 0)
goto error;
retval = snd_pcm_hw_constraint_msbits(runtime, 0, 32, 24);
if (retval < 0)
goto error;
spin_lock_irq(&intelhaddata->had_spinlock);
intelhaddata->stream_info.substream = substream;
intelhaddata->stream_info.substream_refcount++;
spin_unlock_irq(&intelhaddata->had_spinlock);
return retval;
error:
pm_runtime_mark_last_busy(intelhaddata->dev);
pm_runtime_put_autosuspend(intelhaddata->dev);
return retval;
}
static int had_pcm_close(struct snd_pcm_substream *substream)
{
struct snd_intelhad *intelhaddata;
intelhaddata = snd_pcm_substream_chip(substream);
spin_lock_irq(&intelhaddata->had_spinlock);
intelhaddata->stream_info.substream = NULL;
intelhaddata->stream_info.substream_refcount--;
while (intelhaddata->stream_info.substream_refcount > 0) {
spin_unlock_irq(&intelhaddata->had_spinlock);
cpu_relax();
spin_lock_irq(&intelhaddata->had_spinlock);
}
spin_unlock_irq(&intelhaddata->had_spinlock);
pm_runtime_mark_last_busy(intelhaddata->dev);
pm_runtime_put_autosuspend(intelhaddata->dev);
return 0;
}
static int had_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
struct snd_intelhad *intelhaddata;
unsigned long addr;
int pages, buf_size, retval;
intelhaddata = snd_pcm_substream_chip(substream);
buf_size = params_buffer_bytes(hw_params);
retval = snd_pcm_lib_malloc_pages(substream, buf_size);
if (retval < 0)
return retval;
dev_dbg(intelhaddata->dev, "%s:allocated memory = %d\n",
__func__, buf_size);
addr = (unsigned long) substream->runtime->dma_area;
pages = (substream->runtime->dma_bytes + PAGE_SIZE - 1) / PAGE_SIZE;
retval = set_memory_uc(addr, pages);
if (retval) {
dev_err(intelhaddata->dev, "set_memory_uc failed.Error:%d\n",
retval);
return retval;
}
memset(substream->runtime->dma_area, 0, buf_size);
return retval;
}
static int had_pcm_hw_free(struct snd_pcm_substream *substream)
{
struct snd_intelhad *intelhaddata;
unsigned long addr;
u32 pages;
intelhaddata = snd_pcm_substream_chip(substream);
had_do_reset(intelhaddata);
if (substream->runtime->dma_area != NULL) {
addr = (unsigned long) substream->runtime->dma_area;
pages = (substream->runtime->dma_bytes + PAGE_SIZE - 1) /
PAGE_SIZE;
set_memory_wb(addr, pages);
return snd_pcm_lib_free_pages(substream);
}
return 0;
}
static int had_pcm_trigger(struct snd_pcm_substream *substream, int cmd)
{
int retval = 0;
struct snd_intelhad *intelhaddata;
intelhaddata = snd_pcm_substream_chip(substream);
spin_lock(&intelhaddata->had_spinlock);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
case SNDRV_PCM_TRIGGER_RESUME:
had_ack_irqs(intelhaddata);
had_enable_audio(intelhaddata, true);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
had_enable_audio(intelhaddata, false);
intelhaddata->need_reset = true;
break;
default:
retval = -EINVAL;
}
spin_unlock(&intelhaddata->had_spinlock);
return retval;
}
static int had_pcm_prepare(struct snd_pcm_substream *substream)
{
int retval;
u32 disp_samp_freq, n_param;
u32 link_rate = 0;
struct snd_intelhad *intelhaddata;
struct snd_pcm_runtime *runtime;
intelhaddata = snd_pcm_substream_chip(substream);
runtime = substream->runtime;
dev_dbg(intelhaddata->dev, "period_size=%d\n",
(int)frames_to_bytes(runtime, runtime->period_size));
dev_dbg(intelhaddata->dev, "periods=%d\n", runtime->periods);
dev_dbg(intelhaddata->dev, "buffer_size=%d\n",
(int)snd_pcm_lib_buffer_bytes(substream));
dev_dbg(intelhaddata->dev, "rate=%d\n", runtime->rate);
dev_dbg(intelhaddata->dev, "channels=%d\n", runtime->channels);
had_do_reset(intelhaddata);
disp_samp_freq = intelhaddata->tmds_clock_speed;
retval = had_prog_n(substream->runtime->rate, &n_param, intelhaddata);
if (retval) {
dev_err(intelhaddata->dev,
"programming N value failed %#x\n", retval);
goto prep_end;
}
if (intelhaddata->dp_output)
link_rate = intelhaddata->link_rate;
had_prog_cts(substream->runtime->rate, disp_samp_freq, link_rate,
n_param, intelhaddata);
had_prog_dip(substream, intelhaddata);
retval = had_init_audio_ctrl(substream, intelhaddata);
had_init_ringbuf(substream, intelhaddata);
had_write_register(intelhaddata, AUD_BUF_CH_SWAP, SWAP_LFE_CENTER);
prep_end:
return retval;
}
static snd_pcm_uframes_t had_pcm_pointer(struct snd_pcm_substream *substream)
{
struct snd_intelhad *intelhaddata;
int len;
intelhaddata = snd_pcm_substream_chip(substream);
if (!intelhaddata->connected)
return SNDRV_PCM_POS_XRUN;
len = had_process_ringbuf(substream, intelhaddata);
if (len < 0)
return SNDRV_PCM_POS_XRUN;
len = bytes_to_frames(substream->runtime, len);
len %= substream->runtime->buffer_size;
return len;
}
static int had_pcm_mmap(struct snd_pcm_substream *substream,
struct vm_area_struct *vma)
{
vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);
return remap_pfn_range(vma, vma->vm_start,
substream->dma_buffer.addr >> PAGE_SHIFT,
vma->vm_end - vma->vm_start, vma->vm_page_prot);
}
static int had_process_mode_change(struct snd_intelhad *intelhaddata)
{
struct snd_pcm_substream *substream;
int retval = 0;
u32 disp_samp_freq, n_param;
u32 link_rate = 0;
substream = had_substream_get(intelhaddata);
if (!substream)
return 0;
had_enable_audio(intelhaddata, false);
disp_samp_freq = intelhaddata->tmds_clock_speed;
retval = had_prog_n(substream->runtime->rate, &n_param, intelhaddata);
if (retval) {
dev_err(intelhaddata->dev,
"programming N value failed %#x\n", retval);
goto out;
}
if (intelhaddata->dp_output)
link_rate = intelhaddata->link_rate;
had_prog_cts(substream->runtime->rate, disp_samp_freq, link_rate,
n_param, intelhaddata);
had_enable_audio(intelhaddata, true);
out:
had_substream_put(intelhaddata);
return retval;
}
static void had_process_hot_plug(struct snd_intelhad *intelhaddata)
{
struct snd_pcm_substream *substream;
spin_lock_irq(&intelhaddata->had_spinlock);
if (intelhaddata->connected) {
dev_dbg(intelhaddata->dev, "Device already connected\n");
spin_unlock_irq(&intelhaddata->had_spinlock);
return;
}
intelhaddata->connected = true;
dev_dbg(intelhaddata->dev,
"%s @ %d:DEBUG PLUG/UNPLUG : HAD_DRV_CONNECTED\n",
__func__, __LINE__);
spin_unlock_irq(&intelhaddata->had_spinlock);
had_build_channel_allocation_map(intelhaddata);
substream = had_substream_get(intelhaddata);
if (substream) {
snd_pcm_stop_xrun(substream);
had_substream_put(intelhaddata);
}
snd_jack_report(intelhaddata->jack, SND_JACK_AVOUT);
}
static void had_process_hot_unplug(struct snd_intelhad *intelhaddata)
{
struct snd_pcm_substream *substream;
spin_lock_irq(&intelhaddata->had_spinlock);
if (!intelhaddata->connected) {
dev_dbg(intelhaddata->dev, "Device already disconnected\n");
spin_unlock_irq(&intelhaddata->had_spinlock);
return;
}
had_enable_audio(intelhaddata, false);
intelhaddata->connected = false;
dev_dbg(intelhaddata->dev,
"%s @ %d:DEBUG PLUG/UNPLUG : HAD_DRV_DISCONNECTED\n",
__func__, __LINE__);
spin_unlock_irq(&intelhaddata->had_spinlock);
kfree(intelhaddata->chmap->chmap);
intelhaddata->chmap->chmap = NULL;
substream = had_substream_get(intelhaddata);
if (substream) {
snd_pcm_stop_xrun(substream);
had_substream_put(intelhaddata);
}
snd_jack_report(intelhaddata->jack, 0);
}
static int had_iec958_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_IEC958;
uinfo->count = 1;
return 0;
}
static int had_iec958_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_intelhad *intelhaddata = snd_kcontrol_chip(kcontrol);
mutex_lock(&intelhaddata->mutex);
ucontrol->value.iec958.status[0] = (intelhaddata->aes_bits >> 0) & 0xff;
ucontrol->value.iec958.status[1] = (intelhaddata->aes_bits >> 8) & 0xff;
ucontrol->value.iec958.status[2] =
(intelhaddata->aes_bits >> 16) & 0xff;
ucontrol->value.iec958.status[3] =
(intelhaddata->aes_bits >> 24) & 0xff;
mutex_unlock(&intelhaddata->mutex);
return 0;
}
static int had_iec958_mask_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
ucontrol->value.iec958.status[0] = 0xff;
ucontrol->value.iec958.status[1] = 0xff;
ucontrol->value.iec958.status[2] = 0xff;
ucontrol->value.iec958.status[3] = 0xff;
return 0;
}
static int had_iec958_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
unsigned int val;
struct snd_intelhad *intelhaddata = snd_kcontrol_chip(kcontrol);
int changed = 0;
val = (ucontrol->value.iec958.status[0] << 0) |
(ucontrol->value.iec958.status[1] << 8) |
(ucontrol->value.iec958.status[2] << 16) |
(ucontrol->value.iec958.status[3] << 24);
mutex_lock(&intelhaddata->mutex);
if (intelhaddata->aes_bits != val) {
intelhaddata->aes_bits = val;
changed = 1;
}
mutex_unlock(&intelhaddata->mutex);
return changed;
}
static int had_ctl_eld_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_BYTES;
uinfo->count = HDMI_MAX_ELD_BYTES;
return 0;
}
static int had_ctl_eld_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_intelhad *intelhaddata = snd_kcontrol_chip(kcontrol);
mutex_lock(&intelhaddata->mutex);
memcpy(ucontrol->value.bytes.data, intelhaddata->eld,
HDMI_MAX_ELD_BYTES);
mutex_unlock(&intelhaddata->mutex);
return 0;
}
static irqreturn_t display_pipe_interrupt_handler(int irq, void *dev_id)
{
struct snd_intelhad *ctx = dev_id;
u32 audio_stat;
audio_stat = had_read_register_raw(ctx, AUD_HDMI_STATUS);
if (audio_stat & HDMI_AUDIO_UNDERRUN) {
had_write_register_raw(ctx, AUD_HDMI_STATUS,
HDMI_AUDIO_UNDERRUN);
had_process_buffer_underrun(ctx);
}
if (audio_stat & HDMI_AUDIO_BUFFER_DONE) {
had_write_register_raw(ctx, AUD_HDMI_STATUS,
HDMI_AUDIO_BUFFER_DONE);
had_process_buffer_done(ctx);
}
return IRQ_HANDLED;
}
static void notify_audio_lpe(struct platform_device *pdev)
{
struct snd_intelhad *ctx = platform_get_drvdata(pdev);
schedule_work(&ctx->hdmi_audio_wq);
}
static void had_audio_wq(struct work_struct *work)
{
struct snd_intelhad *ctx =
container_of(work, struct snd_intelhad, hdmi_audio_wq);
struct intel_hdmi_lpe_audio_pdata *pdata = ctx->dev->platform_data;
pm_runtime_get_sync(ctx->dev);
mutex_lock(&ctx->mutex);
if (!pdata->hdmi_connected) {
dev_dbg(ctx->dev, "%s: Event: HAD_NOTIFY_HOT_UNPLUG\n",
__func__);
memset(ctx->eld, 0, sizeof(ctx->eld));
had_process_hot_unplug(ctx);
} else {
struct intel_hdmi_lpe_audio_eld *eld = &pdata->eld;
dev_dbg(ctx->dev, "%s: HAD_NOTIFY_ELD : port = %d, tmds = %d\n",
__func__, eld->port_id, pdata->tmds_clock_speed);
switch (eld->pipe_id) {
case 0:
ctx->had_config_offset = AUDIO_HDMI_CONFIG_A;
break;
case 1:
ctx->had_config_offset = AUDIO_HDMI_CONFIG_B;
break;
case 2:
ctx->had_config_offset = AUDIO_HDMI_CONFIG_C;
break;
default:
dev_dbg(ctx->dev, "Invalid pipe %d\n",
eld->pipe_id);
break;
}
memcpy(ctx->eld, eld->eld_data, sizeof(ctx->eld));
ctx->dp_output = pdata->dp_output;
ctx->tmds_clock_speed = pdata->tmds_clock_speed;
ctx->link_rate = pdata->link_rate;
had_process_hot_plug(ctx);
had_process_mode_change(ctx);
}
mutex_unlock(&ctx->mutex);
pm_runtime_mark_last_busy(ctx->dev);
pm_runtime_put_autosuspend(ctx->dev);
}
static int had_create_jack(struct snd_intelhad *ctx)
{
int err;
err = snd_jack_new(ctx->card, "HDMI/DP", SND_JACK_AVOUT, &ctx->jack,
true, false);
if (err < 0)
return err;
ctx->jack->private_data = ctx;
return 0;
}
static int hdmi_lpe_audio_runtime_suspend(struct device *dev)
{
struct snd_intelhad *ctx = dev_get_drvdata(dev);
struct snd_pcm_substream *substream;
substream = had_substream_get(ctx);
if (substream) {
snd_pcm_suspend(substream);
had_substream_put(ctx);
}
return 0;
}
static int __maybe_unused hdmi_lpe_audio_suspend(struct device *dev)
{
struct snd_intelhad *ctx = dev_get_drvdata(dev);
int err;
err = hdmi_lpe_audio_runtime_suspend(dev);
if (!err)
snd_power_change_state(ctx->card, SNDRV_CTL_POWER_D3hot);
return err;
}
static int hdmi_lpe_audio_runtime_resume(struct device *dev)
{
pm_runtime_mark_last_busy(dev);
return 0;
}
static int __maybe_unused hdmi_lpe_audio_resume(struct device *dev)
{
struct snd_intelhad *ctx = dev_get_drvdata(dev);
hdmi_lpe_audio_runtime_resume(dev);
snd_power_change_state(ctx->card, SNDRV_CTL_POWER_D0);
return 0;
}
static void hdmi_lpe_audio_free(struct snd_card *card)
{
struct snd_intelhad *ctx = card->private_data;
cancel_work_sync(&ctx->hdmi_audio_wq);
if (ctx->mmio_start)
iounmap(ctx->mmio_start);
if (ctx->irq >= 0)
free_irq(ctx->irq, ctx);
}
static int hdmi_lpe_audio_probe(struct platform_device *pdev)
{
struct snd_card *card;
struct snd_intelhad *ctx;
struct snd_pcm *pcm;
struct intel_hdmi_lpe_audio_pdata *pdata;
int irq;
struct resource *res_mmio;
int i, ret;
pdata = pdev->dev.platform_data;
if (!pdata) {
dev_err(&pdev->dev, "%s: quit: pdata not allocated by i915!!\n", __func__);
return -EINVAL;
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "Could not get irq resource\n");
return -ENODEV;
}
res_mmio = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res_mmio) {
dev_err(&pdev->dev, "Could not get IO_MEM resources\n");
return -ENXIO;
}
ret = snd_card_new(&pdev->dev, hdmi_card_index, hdmi_card_id,
THIS_MODULE, sizeof(*ctx), &card);
if (ret)
return ret;
ctx = card->private_data;
spin_lock_init(&ctx->had_spinlock);
mutex_init(&ctx->mutex);
ctx->connected = false;
ctx->dev = &pdev->dev;
ctx->card = card;
ctx->aes_bits = SNDRV_PCM_DEFAULT_CON_SPDIF;
strcpy(card->driver, INTEL_HAD);
strcpy(card->shortname, "Intel HDMI/DP LPE Audio");
strcpy(card->longname, "Intel HDMI/DP LPE Audio");
ctx->irq = -1;
ctx->tmds_clock_speed = DIS_SAMPLE_RATE_148_5;
INIT_WORK(&ctx->hdmi_audio_wq, had_audio_wq);
card->private_free = hdmi_lpe_audio_free;
ctx->had_config_offset = AUDIO_HDMI_CONFIG_A;
platform_set_drvdata(pdev, ctx);
dev_dbg(&pdev->dev, "%s: mmio_start = 0x%x, mmio_end = 0x%x\n",
__func__, (unsigned int)res_mmio->start,
(unsigned int)res_mmio->end);
ctx->mmio_start = ioremap_nocache(res_mmio->start,
(size_t)(resource_size(res_mmio)));
if (!ctx->mmio_start) {
dev_err(&pdev->dev, "Could not get ioremap\n");
ret = -EACCES;
goto err;
}
ret = request_irq(irq, display_pipe_interrupt_handler, 0,
pdev->name, ctx);
if (ret < 0) {
dev_err(&pdev->dev, "request_irq failed\n");
goto err;
}
ctx->irq = irq;
ret = snd_pcm_new(card, INTEL_HAD, PCM_INDEX, MAX_PB_STREAMS,
MAX_CAP_STREAMS, &pcm);
if (ret)
goto err;
pcm->private_data = ctx;
pcm->info_flags = 0;
strncpy(pcm->name, card->shortname, strlen(card->shortname));
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK, &had_pcm_ops);
dma_set_mask(&pdev->dev, DMA_BIT_MASK(32));
dma_set_coherent_mask(&pdev->dev, DMA_BIT_MASK(32));
snd_pcm_lib_preallocate_pages_for_all(pcm,
SNDRV_DMA_TYPE_DEV, NULL,
HAD_DEFAULT_BUFFER, HAD_MAX_BUFFER);
for (i = 0; i < ARRAY_SIZE(had_controls); i++) {
ret = snd_ctl_add(card, snd_ctl_new1(&had_controls[i], ctx));
if (ret < 0)
goto err;
}
init_channel_allocations();
ret = had_register_chmap_ctls(ctx, pcm);
if (ret < 0)
goto err;
ret = had_create_jack(ctx);
if (ret < 0)
goto err;
ret = snd_card_register(card);
if (ret)
goto err;
spin_lock_irq(&pdata->lpe_audio_slock);
pdata->notify_audio_lpe = notify_audio_lpe;
pdata->notify_pending = false;
spin_unlock_irq(&pdata->lpe_audio_slock);
pm_runtime_use_autosuspend(&pdev->dev);
pm_runtime_mark_last_busy(&pdev->dev);
pm_runtime_set_active(&pdev->dev);
dev_dbg(&pdev->dev, "%s: handle pending notification\n", __func__);
schedule_work(&ctx->hdmi_audio_wq);
return 0;
err:
snd_card_free(card);
return ret;
}
static int hdmi_lpe_audio_remove(struct platform_device *pdev)
{
struct snd_intelhad *ctx = platform_get_drvdata(pdev);
snd_card_free(ctx->card);
return 0;
}
