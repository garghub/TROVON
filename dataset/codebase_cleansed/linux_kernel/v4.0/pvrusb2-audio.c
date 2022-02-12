void pvr2_msp3400_subdev_update(struct pvr2_hdw *hdw, struct v4l2_subdev *sd)
{
if (hdw->input_dirty || hdw->force_dirty) {
const struct routing_scheme *sp;
unsigned int sid = hdw->hdw_desc->signal_routing_scheme;
u32 input;
pvr2_trace(PVR2_TRACE_CHIPS, "subdev msp3400 v4l2 set_stereo");
sp = (sid < ARRAY_SIZE(routing_schemes)) ?
routing_schemes[sid] : NULL;
if ((sp != NULL) &&
(hdw->input_val >= 0) &&
(hdw->input_val < sp->cnt)) {
input = sp->def[hdw->input_val];
} else {
pvr2_trace(PVR2_TRACE_ERROR_LEGS,
"*** WARNING *** subdev msp3400 set_input:"
" Invalid routing scheme (%u)"
" and/or input (%d)",
sid, hdw->input_val);
return;
}
sd->ops->audio->s_routing(sd, input,
MSP_OUTPUT(MSP_SC_IN_DSP_SCART1), 0);
}
}
