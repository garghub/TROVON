void cx18_video_set_io(struct cx18 *cx)
{
int inp = cx->active_input;
v4l2_subdev_call(cx->sd_av, video, s_routing,
cx->card->video_inputs[inp].video_input, 0, 0);
}
