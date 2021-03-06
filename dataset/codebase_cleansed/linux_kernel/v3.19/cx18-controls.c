static int cx18_s_stream_vbi_fmt(struct cx2341x_handler *cxhdl, u32 fmt)
{
struct cx18 *cx = container_of(cxhdl, struct cx18, cxhdl);
int type = cxhdl->stream_type->val;
if (atomic_read(&cx->ana_capturing) > 0)
return -EBUSY;
if (fmt != V4L2_MPEG_STREAM_VBI_FMT_IVTV ||
!(type == V4L2_MPEG_STREAM_TYPE_MPEG2_PS ||
type == V4L2_MPEG_STREAM_TYPE_MPEG2_DVD ||
type == V4L2_MPEG_STREAM_TYPE_MPEG2_SVCD)) {
cx->vbi.insert_mpeg = V4L2_MPEG_STREAM_VBI_FMT_NONE;
CX18_DEBUG_INFO("disabled insertion of sliced VBI data into "
"the MPEG stream\n");
return 0;
}
if (cx->vbi.sliced_mpeg_data[0] == NULL) {
int i;
for (i = 0; i < CX18_VBI_FRAMES; i++) {
cx->vbi.sliced_mpeg_data[i] =
kmalloc(CX18_SLICED_MPEG_DATA_BUFSZ, GFP_KERNEL);
if (cx->vbi.sliced_mpeg_data[i] == NULL) {
while (--i >= 0) {
kfree(cx->vbi.sliced_mpeg_data[i]);
cx->vbi.sliced_mpeg_data[i] = NULL;
}
cx->vbi.insert_mpeg =
V4L2_MPEG_STREAM_VBI_FMT_NONE;
CX18_WARN("Unable to allocate buffers for "
"sliced VBI data insertion\n");
return -ENOMEM;
}
}
}
cx->vbi.insert_mpeg = fmt;
CX18_DEBUG_INFO("enabled insertion of sliced VBI data into the MPEG PS,"
"when sliced VBI is enabled\n");
if (cx18_get_service_set(cx->vbi.sliced_in) == 0) {
if (cx->is_60hz)
cx->vbi.sliced_in->service_set =
V4L2_SLICED_CAPTION_525;
else
cx->vbi.sliced_in->service_set = V4L2_SLICED_WSS_625;
cx18_expand_service_set(cx->vbi.sliced_in, cx->is_50hz);
}
return 0;
}
static int cx18_s_video_encoding(struct cx2341x_handler *cxhdl, u32 val)
{
struct cx18 *cx = container_of(cxhdl, struct cx18, cxhdl);
int is_mpeg1 = val == V4L2_MPEG_VIDEO_ENCODING_MPEG_1;
struct v4l2_mbus_framefmt fmt;
fmt.width = cxhdl->width / (is_mpeg1 ? 2 : 1);
fmt.height = cxhdl->height;
fmt.code = MEDIA_BUS_FMT_FIXED;
v4l2_subdev_call(cx->sd_av, video, s_mbus_fmt, &fmt);
return 0;
}
static int cx18_s_audio_sampling_freq(struct cx2341x_handler *cxhdl, u32 idx)
{
static const u32 freqs[3] = { 44100, 48000, 32000 };
struct cx18 *cx = container_of(cxhdl, struct cx18, cxhdl);
if (idx < ARRAY_SIZE(freqs))
cx18_call_all(cx, audio, s_clock_freq, freqs[idx]);
return 0;
}
static int cx18_s_audio_mode(struct cx2341x_handler *cxhdl, u32 val)
{
struct cx18 *cx = container_of(cxhdl, struct cx18, cxhdl);
cx->dualwatch_stereo_mode = val;
return 0;
}
