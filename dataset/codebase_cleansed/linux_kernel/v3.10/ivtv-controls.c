static int ivtv_s_stream_vbi_fmt(struct cx2341x_handler *cxhdl, u32 fmt)
{
struct ivtv *itv = container_of(cxhdl, struct ivtv, cxhdl);
if (fmt && itv->vbi.sliced_mpeg_data[0] == NULL) {
int i;
for (i = 0; i < IVTV_VBI_FRAMES; i++) {
itv->vbi.sliced_mpeg_data[i] = kmalloc(2049, GFP_KERNEL);
if (itv->vbi.sliced_mpeg_data[i] == NULL) {
while (--i >= 0) {
kfree(itv->vbi.sliced_mpeg_data[i]);
itv->vbi.sliced_mpeg_data[i] = NULL;
}
return -ENOMEM;
}
}
}
itv->vbi.insert_mpeg = fmt;
if (itv->vbi.insert_mpeg == 0) {
return 0;
}
if (ivtv_get_service_set(itv->vbi.sliced_in) == 0) {
if (itv->is_60hz)
itv->vbi.sliced_in->service_set = V4L2_SLICED_CAPTION_525;
else
itv->vbi.sliced_in->service_set = V4L2_SLICED_WSS_625;
ivtv_expand_service_set(itv->vbi.sliced_in, itv->is_50hz);
}
return 0;
}
static int ivtv_s_video_encoding(struct cx2341x_handler *cxhdl, u32 val)
{
struct ivtv *itv = container_of(cxhdl, struct ivtv, cxhdl);
int is_mpeg1 = val == V4L2_MPEG_VIDEO_ENCODING_MPEG_1;
struct v4l2_mbus_framefmt fmt;
fmt.width = cxhdl->width / (is_mpeg1 ? 2 : 1);
fmt.height = cxhdl->height;
fmt.code = V4L2_MBUS_FMT_FIXED;
v4l2_subdev_call(itv->sd_video, video, s_mbus_fmt, &fmt);
return 0;
}
static int ivtv_s_audio_sampling_freq(struct cx2341x_handler *cxhdl, u32 idx)
{
static const u32 freqs[3] = { 44100, 48000, 32000 };
struct ivtv *itv = container_of(cxhdl, struct ivtv, cxhdl);
if (idx < ARRAY_SIZE(freqs))
ivtv_call_all(itv, audio, s_clock_freq, freqs[idx]);
return 0;
}
static int ivtv_s_audio_mode(struct cx2341x_handler *cxhdl, u32 val)
{
struct ivtv *itv = container_of(cxhdl, struct ivtv, cxhdl);
itv->dualwatch_stereo_mode = val;
return 0;
}
int ivtv_g_pts_frame(struct ivtv *itv, s64 *pts, s64 *frame)
{
u32 data[CX2341X_MBOX_MAX_DATA];
if (test_bit(IVTV_F_I_VALID_DEC_TIMINGS, &itv->i_flags)) {
*pts = (s64)((u64)itv->last_dec_timing[2] << 32) |
(u64)itv->last_dec_timing[1];
*frame = itv->last_dec_timing[0];
return 0;
}
*pts = 0;
*frame = 0;
if (atomic_read(&itv->decoding)) {
if (ivtv_api(itv, CX2341X_DEC_GET_TIMING_INFO, 5, data)) {
IVTV_DEBUG_WARN("GET_TIMING: couldn't read clock\n");
return -EIO;
}
memcpy(itv->last_dec_timing, data, sizeof(itv->last_dec_timing));
set_bit(IVTV_F_I_VALID_DEC_TIMINGS, &itv->i_flags);
*pts = (s64)((u64) data[2] << 32) | (u64) data[1];
*frame = data[0];
}
return 0;
}
static int ivtv_g_volatile_ctrl(struct v4l2_ctrl *ctrl)
{
struct ivtv *itv = container_of(ctrl->handler, struct ivtv, cxhdl.hdl);
switch (ctrl->id) {
case V4L2_CID_MPEG_VIDEO_DEC_PTS:
return ivtv_g_pts_frame(itv, &itv->ctrl_pts->val64,
&itv->ctrl_frame->val64);
}
return 0;
}
static int ivtv_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct ivtv *itv = container_of(ctrl->handler, struct ivtv, cxhdl.hdl);
switch (ctrl->id) {
case V4L2_CID_MPEG_AUDIO_DEC_PLAYBACK:
itv->audio_stereo_mode = itv->ctrl_audio_playback->val - 1;
itv->audio_bilingual_mode = itv->ctrl_audio_multilingual_playback->val - 1;
ivtv_vapi(itv, CX2341X_DEC_SET_AUDIO_MODE, 2, itv->audio_bilingual_mode, itv->audio_stereo_mode);
break;
}
return 0;
}
