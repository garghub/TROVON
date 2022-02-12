void pvr2_cx25840_subdev_update(struct pvr2_hdw *hdw, struct v4l2_subdev *sd)
{
pvr2_trace(PVR2_TRACE_CHIPS, "subdev cx2584x update...");
if (hdw->input_dirty || hdw->force_dirty) {
enum cx25840_video_input vid_input;
enum cx25840_audio_input aud_input;
const struct routing_scheme *sp;
unsigned int sid = hdw->hdw_desc->signal_routing_scheme;
sp = (sid < ARRAY_SIZE(routing_schemes)) ?
routing_schemes[sid] : NULL;
if ((sp == NULL) ||
(hdw->input_val < 0) ||
(hdw->input_val >= sp->cnt)) {
pvr2_trace(PVR2_TRACE_ERROR_LEGS,
"*** WARNING *** subdev cx2584x set_input:"
" Invalid routing scheme (%u)"
" and/or input (%d)",
sid, hdw->input_val);
return;
}
vid_input = sp->def[hdw->input_val].vid;
aud_input = sp->def[hdw->input_val].aud;
pvr2_trace(PVR2_TRACE_CHIPS,
"subdev cx2584x set_input vid=0x%x aud=0x%x",
vid_input, aud_input);
sd->ops->video->s_routing(sd, (u32)vid_input, 0, 0);
sd->ops->audio->s_routing(sd, (u32)aud_input, 0, 0);
}
}
