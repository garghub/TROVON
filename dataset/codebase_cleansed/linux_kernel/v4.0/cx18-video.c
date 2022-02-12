void cx18_video_set_io(struct cx18 *cx)\r\n{\r\nint inp = cx->active_input;\r\nv4l2_subdev_call(cx->sd_av, video, s_routing,\r\ncx->card->video_inputs[inp].video_input, 0, 0);\r\n}
