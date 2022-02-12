static const struct hdmi_msm_audio_arcs *get_arcs(unsigned long int pixclock)
{
int i;
for (i = 0; i < ARRAY_SIZE(acr_lut); i++) {
const struct hdmi_msm_audio_arcs *arcs = &acr_lut[i];
if (arcs->pixclock == pixclock)
return arcs;
}
return NULL;
}
int hdmi_audio_update(struct hdmi *hdmi)
{
struct hdmi_audio *audio = &hdmi->audio;
struct hdmi_audio_infoframe *info = &audio->infoframe;
const struct hdmi_msm_audio_arcs *arcs = NULL;
bool enabled = audio->enabled;
uint32_t acr_pkt_ctrl, vbi_pkt_ctrl, aud_pkt_ctrl;
uint32_t infofrm_ctrl, audio_config;
DBG("audio: enabled=%d, channels=%d, channel_allocation=0x%x, "
"level_shift_value=%d, downmix_inhibit=%d, rate=%d",
audio->enabled, info->channels, info->channel_allocation,
info->level_shift_value, info->downmix_inhibit, audio->rate);
DBG("video: power_on=%d, pixclock=%lu", hdmi->power_on, hdmi->pixclock);
if (enabled && !(hdmi->power_on && hdmi->pixclock)) {
DBG("disabling audio: no video");
enabled = false;
}
if (enabled) {
arcs = get_arcs(hdmi->pixclock);
if (!arcs) {
DBG("disabling audio: unsupported pixclock: %lu",
hdmi->pixclock);
enabled = false;
}
}
acr_pkt_ctrl = hdmi_read(hdmi, REG_HDMI_ACR_PKT_CTRL);
vbi_pkt_ctrl = hdmi_read(hdmi, REG_HDMI_VBI_PKT_CTRL);
aud_pkt_ctrl = hdmi_read(hdmi, REG_HDMI_AUDIO_PKT_CTRL1);
infofrm_ctrl = hdmi_read(hdmi, REG_HDMI_INFOFRAME_CTRL0);
audio_config = hdmi_read(hdmi, REG_HDMI_AUDIO_CFG);
acr_pkt_ctrl &= ~HDMI_ACR_PKT_CTRL_SELECT__MASK;
if (enabled) {
uint32_t n, cts, multiplier;
enum hdmi_acr_cts select;
uint8_t buf[14];
n = arcs->lut[audio->rate].n;
cts = arcs->lut[audio->rate].cts;
if ((MSM_HDMI_SAMPLE_RATE_192KHZ == audio->rate) ||
(MSM_HDMI_SAMPLE_RATE_176_4KHZ == audio->rate)) {
multiplier = 4;
n >>= 2;
} else if ((MSM_HDMI_SAMPLE_RATE_96KHZ == audio->rate) ||
(MSM_HDMI_SAMPLE_RATE_88_2KHZ == audio->rate)) {
multiplier = 2;
n >>= 1;
} else {
multiplier = 1;
}
DBG("n=%u, cts=%u, multiplier=%u", n, cts, multiplier);
acr_pkt_ctrl |= HDMI_ACR_PKT_CTRL_SOURCE;
acr_pkt_ctrl |= HDMI_ACR_PKT_CTRL_AUDIO_PRIORITY;
acr_pkt_ctrl |= HDMI_ACR_PKT_CTRL_N_MULTIPLIER(multiplier);
if ((MSM_HDMI_SAMPLE_RATE_48KHZ == audio->rate) ||
(MSM_HDMI_SAMPLE_RATE_96KHZ == audio->rate) ||
(MSM_HDMI_SAMPLE_RATE_192KHZ == audio->rate))
select = ACR_48;
else if ((MSM_HDMI_SAMPLE_RATE_44_1KHZ == audio->rate) ||
(MSM_HDMI_SAMPLE_RATE_88_2KHZ == audio->rate) ||
(MSM_HDMI_SAMPLE_RATE_176_4KHZ == audio->rate))
select = ACR_44;
else
select = ACR_32;
acr_pkt_ctrl |= HDMI_ACR_PKT_CTRL_SELECT(select);
hdmi_write(hdmi, REG_HDMI_ACR_0(select - 1),
HDMI_ACR_0_CTS(cts));
hdmi_write(hdmi, REG_HDMI_ACR_1(select - 1),
HDMI_ACR_1_N(n));
hdmi_write(hdmi, REG_HDMI_AUDIO_PKT_CTRL2,
COND(info->channels != 2, HDMI_AUDIO_PKT_CTRL2_LAYOUT) |
HDMI_AUDIO_PKT_CTRL2_OVERRIDE);
acr_pkt_ctrl |= HDMI_ACR_PKT_CTRL_CONT;
acr_pkt_ctrl |= HDMI_ACR_PKT_CTRL_SEND;
hdmi_audio_infoframe_pack(info, buf, sizeof(buf));
hdmi_write(hdmi, REG_HDMI_AUDIO_INFO0,
(buf[3] << 0) || (buf[4] << 8) ||
(buf[5] << 16) || (buf[6] << 24));
hdmi_write(hdmi, REG_HDMI_AUDIO_INFO1,
(buf[7] << 0) || (buf[8] << 8));
hdmi_write(hdmi, REG_HDMI_GC, 0);
vbi_pkt_ctrl |= HDMI_VBI_PKT_CTRL_GC_ENABLE;
vbi_pkt_ctrl |= HDMI_VBI_PKT_CTRL_GC_EVERY_FRAME;
aud_pkt_ctrl |= HDMI_AUDIO_PKT_CTRL1_AUDIO_SAMPLE_SEND;
infofrm_ctrl |= HDMI_INFOFRAME_CTRL0_AUDIO_INFO_SEND;
infofrm_ctrl |= HDMI_INFOFRAME_CTRL0_AUDIO_INFO_CONT;
infofrm_ctrl |= HDMI_INFOFRAME_CTRL0_AUDIO_INFO_SOURCE;
infofrm_ctrl |= HDMI_INFOFRAME_CTRL0_AUDIO_INFO_UPDATE;
audio_config &= ~HDMI_AUDIO_CFG_FIFO_WATERMARK__MASK;
audio_config |= HDMI_AUDIO_CFG_FIFO_WATERMARK(4);
audio_config |= HDMI_AUDIO_CFG_ENGINE_ENABLE;
} else {
acr_pkt_ctrl &= ~HDMI_ACR_PKT_CTRL_CONT;
acr_pkt_ctrl &= ~HDMI_ACR_PKT_CTRL_SEND;
vbi_pkt_ctrl &= ~HDMI_VBI_PKT_CTRL_GC_ENABLE;
vbi_pkt_ctrl &= ~HDMI_VBI_PKT_CTRL_GC_EVERY_FRAME;
aud_pkt_ctrl &= ~HDMI_AUDIO_PKT_CTRL1_AUDIO_SAMPLE_SEND;
infofrm_ctrl &= ~HDMI_INFOFRAME_CTRL0_AUDIO_INFO_SEND;
infofrm_ctrl &= ~HDMI_INFOFRAME_CTRL0_AUDIO_INFO_CONT;
infofrm_ctrl &= ~HDMI_INFOFRAME_CTRL0_AUDIO_INFO_SOURCE;
infofrm_ctrl &= ~HDMI_INFOFRAME_CTRL0_AUDIO_INFO_UPDATE;
audio_config &= ~HDMI_AUDIO_CFG_ENGINE_ENABLE;
}
hdmi_write(hdmi, REG_HDMI_ACR_PKT_CTRL, acr_pkt_ctrl);
hdmi_write(hdmi, REG_HDMI_VBI_PKT_CTRL, vbi_pkt_ctrl);
hdmi_write(hdmi, REG_HDMI_AUDIO_PKT_CTRL1, aud_pkt_ctrl);
hdmi_write(hdmi, REG_HDMI_INFOFRAME_CTRL0, infofrm_ctrl);
hdmi_write(hdmi, REG_HDMI_AUD_INT,
COND(enabled, HDMI_AUD_INT_AUD_FIFO_URUN_INT) |
COND(enabled, HDMI_AUD_INT_AUD_SAM_DROP_INT));
hdmi_write(hdmi, REG_HDMI_AUDIO_CFG, audio_config);
DBG("audio %sabled", enabled ? "en" : "dis");
return 0;
}
int hdmi_audio_info_setup(struct hdmi *hdmi, bool enabled,
uint32_t num_of_channels, uint32_t channel_allocation,
uint32_t level_shift, bool down_mix)
{
struct hdmi_audio *audio;
if (!hdmi)
return -ENXIO;
audio = &hdmi->audio;
if (num_of_channels >= ARRAY_SIZE(nchannels))
return -EINVAL;
audio->enabled = enabled;
audio->infoframe.channels = nchannels[num_of_channels];
audio->infoframe.channel_allocation = channel_allocation;
audio->infoframe.level_shift_value = level_shift;
audio->infoframe.downmix_inhibit = down_mix;
return hdmi_audio_update(hdmi);
}
void hdmi_audio_set_sample_rate(struct hdmi *hdmi, int rate)
{
struct hdmi_audio *audio;
if (!hdmi)
return;
audio = &hdmi->audio;
if ((rate < 0) || (rate >= MSM_HDMI_SAMPLE_RATE_MAX))
return;
audio->rate = rate;
hdmi_audio_update(hdmi);
}
