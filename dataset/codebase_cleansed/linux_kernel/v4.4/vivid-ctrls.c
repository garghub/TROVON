static int vivid_user_gen_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct vivid_dev *dev = container_of(ctrl->handler, struct vivid_dev, ctrl_hdl_user_gen);
switch (ctrl->id) {
case VIVID_CID_DISCONNECT:
v4l2_info(&dev->v4l2_dev, "disconnect\n");
clear_bit(V4L2_FL_REGISTERED, &dev->vid_cap_dev.flags);
clear_bit(V4L2_FL_REGISTERED, &dev->vid_out_dev.flags);
clear_bit(V4L2_FL_REGISTERED, &dev->vbi_cap_dev.flags);
clear_bit(V4L2_FL_REGISTERED, &dev->vbi_out_dev.flags);
clear_bit(V4L2_FL_REGISTERED, &dev->sdr_cap_dev.flags);
clear_bit(V4L2_FL_REGISTERED, &dev->radio_rx_dev.flags);
clear_bit(V4L2_FL_REGISTERED, &dev->radio_tx_dev.flags);
break;
case VIVID_CID_CLEAR_FB:
vivid_clear_fb(dev);
break;
case VIVID_CID_BUTTON:
dev->button_pressed = 30;
break;
}
return 0;
}
static int vivid_user_vid_g_volatile_ctrl(struct v4l2_ctrl *ctrl)
{
struct vivid_dev *dev = container_of(ctrl->handler, struct vivid_dev, ctrl_hdl_user_vid);
switch (ctrl->id) {
case V4L2_CID_AUTOGAIN:
dev->gain->val = dev->jiffies_vid_cap & 0xff;
break;
}
return 0;
}
static int vivid_user_vid_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct vivid_dev *dev = container_of(ctrl->handler, struct vivid_dev, ctrl_hdl_user_vid);
switch (ctrl->id) {
case V4L2_CID_BRIGHTNESS:
dev->input_brightness[dev->input] = ctrl->val - dev->input * 128;
tpg_s_brightness(&dev->tpg, dev->input_brightness[dev->input]);
break;
case V4L2_CID_CONTRAST:
tpg_s_contrast(&dev->tpg, ctrl->val);
break;
case V4L2_CID_SATURATION:
tpg_s_saturation(&dev->tpg, ctrl->val);
break;
case V4L2_CID_HUE:
tpg_s_hue(&dev->tpg, ctrl->val);
break;
case V4L2_CID_HFLIP:
dev->hflip = ctrl->val;
tpg_s_hflip(&dev->tpg, dev->sensor_hflip ^ dev->hflip);
break;
case V4L2_CID_VFLIP:
dev->vflip = ctrl->val;
tpg_s_vflip(&dev->tpg, dev->sensor_vflip ^ dev->vflip);
break;
case V4L2_CID_ALPHA_COMPONENT:
tpg_s_alpha_component(&dev->tpg, ctrl->val);
break;
}
return 0;
}
static int vivid_vid_cap_s_ctrl(struct v4l2_ctrl *ctrl)
{
static const u32 colorspaces[] = {
V4L2_COLORSPACE_SMPTE170M,
V4L2_COLORSPACE_REC709,
V4L2_COLORSPACE_SRGB,
V4L2_COLORSPACE_ADOBERGB,
V4L2_COLORSPACE_BT2020,
V4L2_COLORSPACE_DCI_P3,
V4L2_COLORSPACE_SMPTE240M,
V4L2_COLORSPACE_470_SYSTEM_M,
V4L2_COLORSPACE_470_SYSTEM_BG,
};
struct vivid_dev *dev = container_of(ctrl->handler, struct vivid_dev, ctrl_hdl_vid_cap);
unsigned i;
switch (ctrl->id) {
case VIVID_CID_TEST_PATTERN:
vivid_update_quality(dev);
tpg_s_pattern(&dev->tpg, ctrl->val);
break;
case VIVID_CID_COLORSPACE:
tpg_s_colorspace(&dev->tpg, colorspaces[ctrl->val]);
vivid_send_source_change(dev, TV);
vivid_send_source_change(dev, SVID);
vivid_send_source_change(dev, HDMI);
vivid_send_source_change(dev, WEBCAM);
break;
case VIVID_CID_XFER_FUNC:
tpg_s_xfer_func(&dev->tpg, ctrl->val);
vivid_send_source_change(dev, TV);
vivid_send_source_change(dev, SVID);
vivid_send_source_change(dev, HDMI);
vivid_send_source_change(dev, WEBCAM);
break;
case VIVID_CID_YCBCR_ENC:
tpg_s_ycbcr_enc(&dev->tpg, ctrl->val);
vivid_send_source_change(dev, TV);
vivid_send_source_change(dev, SVID);
vivid_send_source_change(dev, HDMI);
vivid_send_source_change(dev, WEBCAM);
break;
case VIVID_CID_QUANTIZATION:
tpg_s_quantization(&dev->tpg, ctrl->val);
vivid_send_source_change(dev, TV);
vivid_send_source_change(dev, SVID);
vivid_send_source_change(dev, HDMI);
vivid_send_source_change(dev, WEBCAM);
break;
case V4L2_CID_DV_RX_RGB_RANGE:
if (!vivid_is_hdmi_cap(dev))
break;
tpg_s_rgb_range(&dev->tpg, ctrl->val);
break;
case VIVID_CID_LIMITED_RGB_RANGE:
tpg_s_real_rgb_range(&dev->tpg, ctrl->val ?
V4L2_DV_RGB_RANGE_LIMITED : V4L2_DV_RGB_RANGE_FULL);
break;
case VIVID_CID_ALPHA_MODE:
tpg_s_alpha_mode(&dev->tpg, ctrl->val);
break;
case VIVID_CID_HOR_MOVEMENT:
tpg_s_mv_hor_mode(&dev->tpg, ctrl->val);
break;
case VIVID_CID_VERT_MOVEMENT:
tpg_s_mv_vert_mode(&dev->tpg, ctrl->val);
break;
case VIVID_CID_OSD_TEXT_MODE:
dev->osd_mode = ctrl->val;
break;
case VIVID_CID_PERCENTAGE_FILL:
tpg_s_perc_fill(&dev->tpg, ctrl->val);
for (i = 0; i < VIDEO_MAX_FRAME; i++)
dev->must_blank[i] = ctrl->val < 100;
break;
case VIVID_CID_INSERT_SAV:
tpg_s_insert_sav(&dev->tpg, ctrl->val);
break;
case VIVID_CID_INSERT_EAV:
tpg_s_insert_eav(&dev->tpg, ctrl->val);
break;
case VIVID_CID_HFLIP:
dev->sensor_hflip = ctrl->val;
tpg_s_hflip(&dev->tpg, dev->sensor_hflip ^ dev->hflip);
break;
case VIVID_CID_VFLIP:
dev->sensor_vflip = ctrl->val;
tpg_s_vflip(&dev->tpg, dev->sensor_vflip ^ dev->vflip);
break;
case VIVID_CID_HAS_CROP_CAP:
dev->has_crop_cap = ctrl->val;
vivid_update_format_cap(dev, true);
break;
case VIVID_CID_HAS_COMPOSE_CAP:
dev->has_compose_cap = ctrl->val;
vivid_update_format_cap(dev, true);
break;
case VIVID_CID_HAS_SCALER_CAP:
dev->has_scaler_cap = ctrl->val;
vivid_update_format_cap(dev, true);
break;
case VIVID_CID_SHOW_BORDER:
tpg_s_show_border(&dev->tpg, ctrl->val);
break;
case VIVID_CID_SHOW_SQUARE:
tpg_s_show_square(&dev->tpg, ctrl->val);
break;
case VIVID_CID_STD_ASPECT_RATIO:
dev->std_aspect_ratio = ctrl->val;
tpg_s_video_aspect(&dev->tpg, vivid_get_video_aspect(dev));
break;
case VIVID_CID_DV_TIMINGS_SIGNAL_MODE:
dev->dv_timings_signal_mode = dev->ctrl_dv_timings_signal_mode->val;
if (dev->dv_timings_signal_mode == SELECTED_DV_TIMINGS)
dev->query_dv_timings = dev->ctrl_dv_timings->val;
v4l2_ctrl_activate(dev->ctrl_dv_timings,
dev->dv_timings_signal_mode == SELECTED_DV_TIMINGS);
vivid_update_quality(dev);
vivid_send_source_change(dev, HDMI);
break;
case VIVID_CID_DV_TIMINGS_ASPECT_RATIO:
dev->dv_timings_aspect_ratio = ctrl->val;
tpg_s_video_aspect(&dev->tpg, vivid_get_video_aspect(dev));
break;
case VIVID_CID_TSTAMP_SRC:
dev->tstamp_src_is_soe = ctrl->val;
dev->vb_vid_cap_q.timestamp_flags &= ~V4L2_BUF_FLAG_TSTAMP_SRC_MASK;
if (dev->tstamp_src_is_soe)
dev->vb_vid_cap_q.timestamp_flags |= V4L2_BUF_FLAG_TSTAMP_SRC_SOE;
break;
case VIVID_CID_MAX_EDID_BLOCKS:
dev->edid_max_blocks = ctrl->val;
if (dev->edid_blocks > dev->edid_max_blocks)
dev->edid_blocks = dev->edid_max_blocks;
break;
}
return 0;
}
static int vivid_loop_cap_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct vivid_dev *dev = container_of(ctrl->handler, struct vivid_dev, ctrl_hdl_loop_cap);
switch (ctrl->id) {
case VIVID_CID_LOOP_VIDEO:
dev->loop_video = ctrl->val;
vivid_update_quality(dev);
vivid_send_source_change(dev, SVID);
vivid_send_source_change(dev, HDMI);
break;
}
return 0;
}
static int vivid_vbi_cap_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct vivid_dev *dev = container_of(ctrl->handler, struct vivid_dev, ctrl_hdl_vbi_cap);
switch (ctrl->id) {
case VIVID_CID_VBI_CAP_INTERLACED:
dev->vbi_cap_interlaced = ctrl->val;
break;
}
return 0;
}
static int vivid_vid_out_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct vivid_dev *dev = container_of(ctrl->handler, struct vivid_dev, ctrl_hdl_vid_out);
struct v4l2_bt_timings *bt = &dev->dv_timings_out.bt;
switch (ctrl->id) {
case VIVID_CID_HAS_CROP_OUT:
dev->has_crop_out = ctrl->val;
vivid_update_format_out(dev);
break;
case VIVID_CID_HAS_COMPOSE_OUT:
dev->has_compose_out = ctrl->val;
vivid_update_format_out(dev);
break;
case VIVID_CID_HAS_SCALER_OUT:
dev->has_scaler_out = ctrl->val;
vivid_update_format_out(dev);
break;
case V4L2_CID_DV_TX_MODE:
dev->dvi_d_out = ctrl->val == V4L2_DV_TX_MODE_DVI_D;
if (!vivid_is_hdmi_out(dev))
break;
if (!dev->dvi_d_out && (bt->flags & V4L2_DV_FL_IS_CE_VIDEO)) {
if (bt->width == 720 && bt->height <= 576)
dev->colorspace_out = V4L2_COLORSPACE_SMPTE170M;
else
dev->colorspace_out = V4L2_COLORSPACE_REC709;
dev->quantization_out = V4L2_QUANTIZATION_DEFAULT;
} else {
dev->colorspace_out = V4L2_COLORSPACE_SRGB;
dev->quantization_out = dev->dvi_d_out ?
V4L2_QUANTIZATION_LIM_RANGE :
V4L2_QUANTIZATION_DEFAULT;
}
if (dev->loop_video)
vivid_send_source_change(dev, HDMI);
break;
}
return 0;
}
static int vivid_streaming_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct vivid_dev *dev = container_of(ctrl->handler, struct vivid_dev, ctrl_hdl_streaming);
struct timeval tv;
switch (ctrl->id) {
case VIVID_CID_DQBUF_ERROR:
dev->dqbuf_error = true;
break;
case VIVID_CID_PERC_DROPPED:
dev->perc_dropped_buffers = ctrl->val;
break;
case VIVID_CID_QUEUE_SETUP_ERROR:
dev->queue_setup_error = true;
break;
case VIVID_CID_BUF_PREPARE_ERROR:
dev->buf_prepare_error = true;
break;
case VIVID_CID_START_STR_ERROR:
dev->start_streaming_error = true;
break;
case VIVID_CID_QUEUE_ERROR:
if (vb2_start_streaming_called(&dev->vb_vid_cap_q))
vb2_queue_error(&dev->vb_vid_cap_q);
if (vb2_start_streaming_called(&dev->vb_vbi_cap_q))
vb2_queue_error(&dev->vb_vbi_cap_q);
if (vb2_start_streaming_called(&dev->vb_vid_out_q))
vb2_queue_error(&dev->vb_vid_out_q);
if (vb2_start_streaming_called(&dev->vb_vbi_out_q))
vb2_queue_error(&dev->vb_vbi_out_q);
if (vb2_start_streaming_called(&dev->vb_sdr_cap_q))
vb2_queue_error(&dev->vb_sdr_cap_q);
break;
case VIVID_CID_SEQ_WRAP:
dev->seq_wrap = ctrl->val;
break;
case VIVID_CID_TIME_WRAP:
dev->time_wrap = ctrl->val;
if (ctrl->val == 0) {
dev->time_wrap_offset = 0;
break;
}
v4l2_get_timestamp(&tv);
dev->time_wrap_offset = -tv.tv_sec - 16;
break;
}
return 0;
}
static int vivid_sdtv_cap_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct vivid_dev *dev = container_of(ctrl->handler, struct vivid_dev, ctrl_hdl_sdtv_cap);
switch (ctrl->id) {
case VIVID_CID_STD_SIGNAL_MODE:
dev->std_signal_mode = dev->ctrl_std_signal_mode->val;
if (dev->std_signal_mode == SELECTED_STD)
dev->query_std = vivid_standard[dev->ctrl_standard->val];
v4l2_ctrl_activate(dev->ctrl_standard, dev->std_signal_mode == SELECTED_STD);
vivid_update_quality(dev);
vivid_send_source_change(dev, TV);
vivid_send_source_change(dev, SVID);
break;
}
return 0;
}
static int vivid_radio_rx_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct vivid_dev *dev = container_of(ctrl->handler, struct vivid_dev, ctrl_hdl_radio_rx);
switch (ctrl->id) {
case VIVID_CID_RADIO_SEEK_MODE:
dev->radio_rx_hw_seek_mode = ctrl->val;
break;
case VIVID_CID_RADIO_SEEK_PROG_LIM:
dev->radio_rx_hw_seek_prog_lim = ctrl->val;
break;
case VIVID_CID_RADIO_RX_RDS_RBDS:
dev->rds_gen.use_rbds = ctrl->val;
break;
case VIVID_CID_RADIO_RX_RDS_BLOCKIO:
dev->radio_rx_rds_controls = ctrl->val;
dev->radio_rx_caps &= ~V4L2_CAP_READWRITE;
dev->radio_rx_rds_use_alternates = false;
if (!dev->radio_rx_rds_controls) {
dev->radio_rx_caps |= V4L2_CAP_READWRITE;
__v4l2_ctrl_s_ctrl(dev->radio_rx_rds_pty, 0);
__v4l2_ctrl_s_ctrl(dev->radio_rx_rds_ta, 0);
__v4l2_ctrl_s_ctrl(dev->radio_rx_rds_tp, 0);
__v4l2_ctrl_s_ctrl(dev->radio_rx_rds_ms, 0);
__v4l2_ctrl_s_ctrl_string(dev->radio_rx_rds_psname, "");
__v4l2_ctrl_s_ctrl_string(dev->radio_rx_rds_radiotext, "");
}
v4l2_ctrl_activate(dev->radio_rx_rds_pty, dev->radio_rx_rds_controls);
v4l2_ctrl_activate(dev->radio_rx_rds_psname, dev->radio_rx_rds_controls);
v4l2_ctrl_activate(dev->radio_rx_rds_radiotext, dev->radio_rx_rds_controls);
v4l2_ctrl_activate(dev->radio_rx_rds_ta, dev->radio_rx_rds_controls);
v4l2_ctrl_activate(dev->radio_rx_rds_tp, dev->radio_rx_rds_controls);
v4l2_ctrl_activate(dev->radio_rx_rds_ms, dev->radio_rx_rds_controls);
break;
case V4L2_CID_RDS_RECEPTION:
dev->radio_rx_rds_enabled = ctrl->val;
break;
}
return 0;
}
static int vivid_radio_tx_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct vivid_dev *dev = container_of(ctrl->handler, struct vivid_dev, ctrl_hdl_radio_tx);
switch (ctrl->id) {
case VIVID_CID_RADIO_TX_RDS_BLOCKIO:
dev->radio_tx_rds_controls = ctrl->val;
dev->radio_tx_caps &= ~V4L2_CAP_READWRITE;
if (!dev->radio_tx_rds_controls)
dev->radio_tx_caps |= V4L2_CAP_READWRITE;
break;
case V4L2_CID_RDS_TX_PTY:
if (dev->radio_rx_rds_controls)
v4l2_ctrl_s_ctrl(dev->radio_rx_rds_pty, ctrl->val);
break;
case V4L2_CID_RDS_TX_PS_NAME:
if (dev->radio_rx_rds_controls)
v4l2_ctrl_s_ctrl_string(dev->radio_rx_rds_psname, ctrl->p_new.p_char);
break;
case V4L2_CID_RDS_TX_RADIO_TEXT:
if (dev->radio_rx_rds_controls)
v4l2_ctrl_s_ctrl_string(dev->radio_rx_rds_radiotext, ctrl->p_new.p_char);
break;
case V4L2_CID_RDS_TX_TRAFFIC_ANNOUNCEMENT:
if (dev->radio_rx_rds_controls)
v4l2_ctrl_s_ctrl(dev->radio_rx_rds_ta, ctrl->val);
break;
case V4L2_CID_RDS_TX_TRAFFIC_PROGRAM:
if (dev->radio_rx_rds_controls)
v4l2_ctrl_s_ctrl(dev->radio_rx_rds_tp, ctrl->val);
break;
case V4L2_CID_RDS_TX_MUSIC_SPEECH:
if (dev->radio_rx_rds_controls)
v4l2_ctrl_s_ctrl(dev->radio_rx_rds_ms, ctrl->val);
break;
}
return 0;
}
static int vivid_sdr_cap_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct vivid_dev *dev = container_of(ctrl->handler, struct vivid_dev, ctrl_hdl_sdr_cap);
switch (ctrl->id) {
case VIVID_CID_SDR_CAP_FM_DEVIATION:
dev->sdr_fm_deviation = ctrl->val;
break;
}
return 0;
}
int vivid_create_controls(struct vivid_dev *dev, bool show_ccs_cap,
bool show_ccs_out, bool no_error_inj,
bool has_sdtv, bool has_hdmi)
{
struct v4l2_ctrl_handler *hdl_user_gen = &dev->ctrl_hdl_user_gen;
struct v4l2_ctrl_handler *hdl_user_vid = &dev->ctrl_hdl_user_vid;
struct v4l2_ctrl_handler *hdl_user_aud = &dev->ctrl_hdl_user_aud;
struct v4l2_ctrl_handler *hdl_streaming = &dev->ctrl_hdl_streaming;
struct v4l2_ctrl_handler *hdl_sdtv_cap = &dev->ctrl_hdl_sdtv_cap;
struct v4l2_ctrl_handler *hdl_loop_cap = &dev->ctrl_hdl_loop_cap;
struct v4l2_ctrl_handler *hdl_vid_cap = &dev->ctrl_hdl_vid_cap;
struct v4l2_ctrl_handler *hdl_vid_out = &dev->ctrl_hdl_vid_out;
struct v4l2_ctrl_handler *hdl_vbi_cap = &dev->ctrl_hdl_vbi_cap;
struct v4l2_ctrl_handler *hdl_vbi_out = &dev->ctrl_hdl_vbi_out;
struct v4l2_ctrl_handler *hdl_radio_rx = &dev->ctrl_hdl_radio_rx;
struct v4l2_ctrl_handler *hdl_radio_tx = &dev->ctrl_hdl_radio_tx;
struct v4l2_ctrl_handler *hdl_sdr_cap = &dev->ctrl_hdl_sdr_cap;
struct v4l2_ctrl_config vivid_ctrl_dv_timings = {
.ops = &vivid_vid_cap_ctrl_ops,
.id = VIVID_CID_DV_TIMINGS,
.name = "DV Timings",
.type = V4L2_CTRL_TYPE_MENU,
};
int i;
v4l2_ctrl_handler_init(hdl_user_gen, 10);
v4l2_ctrl_new_custom(hdl_user_gen, &vivid_ctrl_class, NULL);
v4l2_ctrl_handler_init(hdl_user_vid, 9);
v4l2_ctrl_new_custom(hdl_user_vid, &vivid_ctrl_class, NULL);
v4l2_ctrl_handler_init(hdl_user_aud, 2);
v4l2_ctrl_new_custom(hdl_user_aud, &vivid_ctrl_class, NULL);
v4l2_ctrl_handler_init(hdl_streaming, 8);
v4l2_ctrl_new_custom(hdl_streaming, &vivid_ctrl_class, NULL);
v4l2_ctrl_handler_init(hdl_sdtv_cap, 2);
v4l2_ctrl_new_custom(hdl_sdtv_cap, &vivid_ctrl_class, NULL);
v4l2_ctrl_handler_init(hdl_loop_cap, 1);
v4l2_ctrl_new_custom(hdl_loop_cap, &vivid_ctrl_class, NULL);
v4l2_ctrl_handler_init(hdl_vid_cap, 55);
v4l2_ctrl_new_custom(hdl_vid_cap, &vivid_ctrl_class, NULL);
v4l2_ctrl_handler_init(hdl_vid_out, 26);
v4l2_ctrl_new_custom(hdl_vid_out, &vivid_ctrl_class, NULL);
v4l2_ctrl_handler_init(hdl_vbi_cap, 21);
v4l2_ctrl_new_custom(hdl_vbi_cap, &vivid_ctrl_class, NULL);
v4l2_ctrl_handler_init(hdl_vbi_out, 19);
v4l2_ctrl_new_custom(hdl_vbi_out, &vivid_ctrl_class, NULL);
v4l2_ctrl_handler_init(hdl_radio_rx, 17);
v4l2_ctrl_new_custom(hdl_radio_rx, &vivid_ctrl_class, NULL);
v4l2_ctrl_handler_init(hdl_radio_tx, 17);
v4l2_ctrl_new_custom(hdl_radio_tx, &vivid_ctrl_class, NULL);
v4l2_ctrl_handler_init(hdl_sdr_cap, 19);
v4l2_ctrl_new_custom(hdl_sdr_cap, &vivid_ctrl_class, NULL);
dev->volume = v4l2_ctrl_new_std(hdl_user_aud, NULL,
V4L2_CID_AUDIO_VOLUME, 0, 255, 1, 200);
dev->mute = v4l2_ctrl_new_std(hdl_user_aud, NULL,
V4L2_CID_AUDIO_MUTE, 0, 1, 1, 0);
if (dev->has_vid_cap) {
dev->brightness = v4l2_ctrl_new_std(hdl_user_vid, &vivid_user_vid_ctrl_ops,
V4L2_CID_BRIGHTNESS, 0, 255, 1, 128);
for (i = 0; i < MAX_INPUTS; i++)
dev->input_brightness[i] = 128;
dev->contrast = v4l2_ctrl_new_std(hdl_user_vid, &vivid_user_vid_ctrl_ops,
V4L2_CID_CONTRAST, 0, 255, 1, 128);
dev->saturation = v4l2_ctrl_new_std(hdl_user_vid, &vivid_user_vid_ctrl_ops,
V4L2_CID_SATURATION, 0, 255, 1, 128);
dev->hue = v4l2_ctrl_new_std(hdl_user_vid, &vivid_user_vid_ctrl_ops,
V4L2_CID_HUE, -128, 128, 1, 0);
v4l2_ctrl_new_std(hdl_user_vid, &vivid_user_vid_ctrl_ops,
V4L2_CID_HFLIP, 0, 1, 1, 0);
v4l2_ctrl_new_std(hdl_user_vid, &vivid_user_vid_ctrl_ops,
V4L2_CID_VFLIP, 0, 1, 1, 0);
dev->autogain = v4l2_ctrl_new_std(hdl_user_vid, &vivid_user_vid_ctrl_ops,
V4L2_CID_AUTOGAIN, 0, 1, 1, 1);
dev->gain = v4l2_ctrl_new_std(hdl_user_vid, &vivid_user_vid_ctrl_ops,
V4L2_CID_GAIN, 0, 255, 1, 100);
dev->alpha = v4l2_ctrl_new_std(hdl_user_vid, &vivid_user_vid_ctrl_ops,
V4L2_CID_ALPHA_COMPONENT, 0, 255, 1, 0);
}
dev->button = v4l2_ctrl_new_custom(hdl_user_gen, &vivid_ctrl_button, NULL);
dev->int32 = v4l2_ctrl_new_custom(hdl_user_gen, &vivid_ctrl_int32, NULL);
dev->int64 = v4l2_ctrl_new_custom(hdl_user_gen, &vivid_ctrl_int64, NULL);
dev->boolean = v4l2_ctrl_new_custom(hdl_user_gen, &vivid_ctrl_boolean, NULL);
dev->menu = v4l2_ctrl_new_custom(hdl_user_gen, &vivid_ctrl_menu, NULL);
dev->string = v4l2_ctrl_new_custom(hdl_user_gen, &vivid_ctrl_string, NULL);
dev->bitmask = v4l2_ctrl_new_custom(hdl_user_gen, &vivid_ctrl_bitmask, NULL);
dev->int_menu = v4l2_ctrl_new_custom(hdl_user_gen, &vivid_ctrl_int_menu, NULL);
v4l2_ctrl_new_custom(hdl_user_gen, &vivid_ctrl_u32_array, NULL);
v4l2_ctrl_new_custom(hdl_user_gen, &vivid_ctrl_u16_matrix, NULL);
v4l2_ctrl_new_custom(hdl_user_gen, &vivid_ctrl_u8_4d_array, NULL);
if (dev->has_vid_cap) {
struct v4l2_ctrl_config vivid_ctrl_test_pattern = {
.ops = &vivid_vid_cap_ctrl_ops,
.id = VIVID_CID_TEST_PATTERN,
.name = "Test Pattern",
.type = V4L2_CTRL_TYPE_MENU,
.max = TPG_PAT_NOISE,
.qmenu = tpg_pattern_strings,
};
dev->test_pattern = v4l2_ctrl_new_custom(hdl_vid_cap,
&vivid_ctrl_test_pattern, NULL);
v4l2_ctrl_new_custom(hdl_vid_cap, &vivid_ctrl_perc_fill, NULL);
v4l2_ctrl_new_custom(hdl_vid_cap, &vivid_ctrl_hor_movement, NULL);
v4l2_ctrl_new_custom(hdl_vid_cap, &vivid_ctrl_vert_movement, NULL);
v4l2_ctrl_new_custom(hdl_vid_cap, &vivid_ctrl_osd_mode, NULL);
v4l2_ctrl_new_custom(hdl_vid_cap, &vivid_ctrl_show_border, NULL);
v4l2_ctrl_new_custom(hdl_vid_cap, &vivid_ctrl_show_square, NULL);
v4l2_ctrl_new_custom(hdl_vid_cap, &vivid_ctrl_hflip, NULL);
v4l2_ctrl_new_custom(hdl_vid_cap, &vivid_ctrl_vflip, NULL);
v4l2_ctrl_new_custom(hdl_vid_cap, &vivid_ctrl_insert_sav, NULL);
v4l2_ctrl_new_custom(hdl_vid_cap, &vivid_ctrl_insert_eav, NULL);
if (show_ccs_cap) {
dev->ctrl_has_crop_cap = v4l2_ctrl_new_custom(hdl_vid_cap,
&vivid_ctrl_has_crop_cap, NULL);
dev->ctrl_has_compose_cap = v4l2_ctrl_new_custom(hdl_vid_cap,
&vivid_ctrl_has_compose_cap, NULL);
dev->ctrl_has_scaler_cap = v4l2_ctrl_new_custom(hdl_vid_cap,
&vivid_ctrl_has_scaler_cap, NULL);
}
v4l2_ctrl_new_custom(hdl_vid_cap, &vivid_ctrl_tstamp_src, NULL);
dev->colorspace = v4l2_ctrl_new_custom(hdl_vid_cap,
&vivid_ctrl_colorspace, NULL);
v4l2_ctrl_new_custom(hdl_vid_cap, &vivid_ctrl_xfer_func, NULL);
v4l2_ctrl_new_custom(hdl_vid_cap, &vivid_ctrl_ycbcr_enc, NULL);
v4l2_ctrl_new_custom(hdl_vid_cap, &vivid_ctrl_quantization, NULL);
v4l2_ctrl_new_custom(hdl_vid_cap, &vivid_ctrl_alpha_mode, NULL);
}
if (dev->has_vid_out && show_ccs_out) {
dev->ctrl_has_crop_out = v4l2_ctrl_new_custom(hdl_vid_out,
&vivid_ctrl_has_crop_out, NULL);
dev->ctrl_has_compose_out = v4l2_ctrl_new_custom(hdl_vid_out,
&vivid_ctrl_has_compose_out, NULL);
dev->ctrl_has_scaler_out = v4l2_ctrl_new_custom(hdl_vid_out,
&vivid_ctrl_has_scaler_out, NULL);
}
if (!no_error_inj) {
v4l2_ctrl_new_custom(hdl_user_gen, &vivid_ctrl_disconnect, NULL);
v4l2_ctrl_new_custom(hdl_streaming, &vivid_ctrl_dqbuf_error, NULL);
v4l2_ctrl_new_custom(hdl_streaming, &vivid_ctrl_perc_dropped, NULL);
v4l2_ctrl_new_custom(hdl_streaming, &vivid_ctrl_queue_setup_error, NULL);
v4l2_ctrl_new_custom(hdl_streaming, &vivid_ctrl_buf_prepare_error, NULL);
v4l2_ctrl_new_custom(hdl_streaming, &vivid_ctrl_start_streaming_error, NULL);
v4l2_ctrl_new_custom(hdl_streaming, &vivid_ctrl_queue_error, NULL);
v4l2_ctrl_new_custom(hdl_streaming, &vivid_ctrl_seq_wrap, NULL);
v4l2_ctrl_new_custom(hdl_streaming, &vivid_ctrl_time_wrap, NULL);
}
if (has_sdtv && (dev->has_vid_cap || dev->has_vbi_cap)) {
if (dev->has_vid_cap)
v4l2_ctrl_new_custom(hdl_vid_cap, &vivid_ctrl_std_aspect_ratio, NULL);
dev->ctrl_std_signal_mode = v4l2_ctrl_new_custom(hdl_sdtv_cap,
&vivid_ctrl_std_signal_mode, NULL);
dev->ctrl_standard = v4l2_ctrl_new_custom(hdl_sdtv_cap,
&vivid_ctrl_standard, NULL);
if (dev->ctrl_std_signal_mode)
v4l2_ctrl_cluster(2, &dev->ctrl_std_signal_mode);
if (dev->has_raw_vbi_cap)
v4l2_ctrl_new_custom(hdl_vbi_cap, &vivid_ctrl_vbi_cap_interlaced, NULL);
}
if (has_hdmi && dev->has_vid_cap) {
dev->ctrl_dv_timings_signal_mode = v4l2_ctrl_new_custom(hdl_vid_cap,
&vivid_ctrl_dv_timings_signal_mode, NULL);
vivid_ctrl_dv_timings.max = dev->query_dv_timings_size - 1;
vivid_ctrl_dv_timings.qmenu =
(const char * const *)dev->query_dv_timings_qmenu;
dev->ctrl_dv_timings = v4l2_ctrl_new_custom(hdl_vid_cap,
&vivid_ctrl_dv_timings, NULL);
if (dev->ctrl_dv_timings_signal_mode)
v4l2_ctrl_cluster(2, &dev->ctrl_dv_timings_signal_mode);
v4l2_ctrl_new_custom(hdl_vid_cap, &vivid_ctrl_dv_timings_aspect_ratio, NULL);
v4l2_ctrl_new_custom(hdl_vid_cap, &vivid_ctrl_max_edid_blocks, NULL);
dev->real_rgb_range_cap = v4l2_ctrl_new_custom(hdl_vid_cap,
&vivid_ctrl_limited_rgb_range, NULL);
dev->rgb_range_cap = v4l2_ctrl_new_std_menu(hdl_vid_cap,
&vivid_vid_cap_ctrl_ops,
V4L2_CID_DV_RX_RGB_RANGE, V4L2_DV_RGB_RANGE_FULL,
0, V4L2_DV_RGB_RANGE_AUTO);
}
if (has_hdmi && dev->has_vid_out) {
dev->ctrl_tx_rgb_range = v4l2_ctrl_new_std_menu(hdl_vid_out, NULL,
V4L2_CID_DV_TX_RGB_RANGE, V4L2_DV_RGB_RANGE_FULL,
0, V4L2_DV_RGB_RANGE_AUTO);
dev->ctrl_tx_mode = v4l2_ctrl_new_std_menu(hdl_vid_out, NULL,
V4L2_CID_DV_TX_MODE, V4L2_DV_TX_MODE_HDMI,
0, V4L2_DV_TX_MODE_HDMI);
}
if ((dev->has_vid_cap && dev->has_vid_out) ||
(dev->has_vbi_cap && dev->has_vbi_out))
v4l2_ctrl_new_custom(hdl_loop_cap, &vivid_ctrl_loop_video, NULL);
if (dev->has_fb)
v4l2_ctrl_new_custom(hdl_user_gen, &vivid_ctrl_clear_fb, NULL);
if (dev->has_radio_rx) {
v4l2_ctrl_new_custom(hdl_radio_rx, &vivid_ctrl_radio_hw_seek_mode, NULL);
v4l2_ctrl_new_custom(hdl_radio_rx, &vivid_ctrl_radio_hw_seek_prog_lim, NULL);
v4l2_ctrl_new_custom(hdl_radio_rx, &vivid_ctrl_radio_rx_rds_blockio, NULL);
v4l2_ctrl_new_custom(hdl_radio_rx, &vivid_ctrl_radio_rx_rds_rbds, NULL);
v4l2_ctrl_new_std(hdl_radio_rx, &vivid_radio_rx_ctrl_ops,
V4L2_CID_RDS_RECEPTION, 0, 1, 1, 1);
dev->radio_rx_rds_pty = v4l2_ctrl_new_std(hdl_radio_rx,
&vivid_radio_rx_ctrl_ops,
V4L2_CID_RDS_RX_PTY, 0, 31, 1, 0);
dev->radio_rx_rds_psname = v4l2_ctrl_new_std(hdl_radio_rx,
&vivid_radio_rx_ctrl_ops,
V4L2_CID_RDS_RX_PS_NAME, 0, 8, 8, 0);
dev->radio_rx_rds_radiotext = v4l2_ctrl_new_std(hdl_radio_rx,
&vivid_radio_rx_ctrl_ops,
V4L2_CID_RDS_RX_RADIO_TEXT, 0, 64, 64, 0);
dev->radio_rx_rds_ta = v4l2_ctrl_new_std(hdl_radio_rx,
&vivid_radio_rx_ctrl_ops,
V4L2_CID_RDS_RX_TRAFFIC_ANNOUNCEMENT, 0, 1, 1, 0);
dev->radio_rx_rds_tp = v4l2_ctrl_new_std(hdl_radio_rx,
&vivid_radio_rx_ctrl_ops,
V4L2_CID_RDS_RX_TRAFFIC_PROGRAM, 0, 1, 1, 0);
dev->radio_rx_rds_ms = v4l2_ctrl_new_std(hdl_radio_rx,
&vivid_radio_rx_ctrl_ops,
V4L2_CID_RDS_RX_MUSIC_SPEECH, 0, 1, 1, 1);
}
if (dev->has_radio_tx) {
v4l2_ctrl_new_custom(hdl_radio_tx,
&vivid_ctrl_radio_tx_rds_blockio, NULL);
dev->radio_tx_rds_pi = v4l2_ctrl_new_std(hdl_radio_tx,
&vivid_radio_tx_ctrl_ops,
V4L2_CID_RDS_TX_PI, 0, 0xffff, 1, 0x8088);
dev->radio_tx_rds_pty = v4l2_ctrl_new_std(hdl_radio_tx,
&vivid_radio_tx_ctrl_ops,
V4L2_CID_RDS_TX_PTY, 0, 31, 1, 3);
dev->radio_tx_rds_psname = v4l2_ctrl_new_std(hdl_radio_tx,
&vivid_radio_tx_ctrl_ops,
V4L2_CID_RDS_TX_PS_NAME, 0, 8, 8, 0);
if (dev->radio_tx_rds_psname)
v4l2_ctrl_s_ctrl_string(dev->radio_tx_rds_psname, "VIVID-TX");
dev->radio_tx_rds_radiotext = v4l2_ctrl_new_std(hdl_radio_tx,
&vivid_radio_tx_ctrl_ops,
V4L2_CID_RDS_TX_RADIO_TEXT, 0, 64 * 2, 64, 0);
if (dev->radio_tx_rds_radiotext)
v4l2_ctrl_s_ctrl_string(dev->radio_tx_rds_radiotext,
"This is a VIVID default Radio Text template text, change at will");
dev->radio_tx_rds_mono_stereo = v4l2_ctrl_new_std(hdl_radio_tx,
&vivid_radio_tx_ctrl_ops,
V4L2_CID_RDS_TX_MONO_STEREO, 0, 1, 1, 1);
dev->radio_tx_rds_art_head = v4l2_ctrl_new_std(hdl_radio_tx,
&vivid_radio_tx_ctrl_ops,
V4L2_CID_RDS_TX_ARTIFICIAL_HEAD, 0, 1, 1, 0);
dev->radio_tx_rds_compressed = v4l2_ctrl_new_std(hdl_radio_tx,
&vivid_radio_tx_ctrl_ops,
V4L2_CID_RDS_TX_COMPRESSED, 0, 1, 1, 0);
dev->radio_tx_rds_dyn_pty = v4l2_ctrl_new_std(hdl_radio_tx,
&vivid_radio_tx_ctrl_ops,
V4L2_CID_RDS_TX_DYNAMIC_PTY, 0, 1, 1, 0);
dev->radio_tx_rds_ta = v4l2_ctrl_new_std(hdl_radio_tx,
&vivid_radio_tx_ctrl_ops,
V4L2_CID_RDS_TX_TRAFFIC_ANNOUNCEMENT, 0, 1, 1, 0);
dev->radio_tx_rds_tp = v4l2_ctrl_new_std(hdl_radio_tx,
&vivid_radio_tx_ctrl_ops,
V4L2_CID_RDS_TX_TRAFFIC_PROGRAM, 0, 1, 1, 1);
dev->radio_tx_rds_ms = v4l2_ctrl_new_std(hdl_radio_tx,
&vivid_radio_tx_ctrl_ops,
V4L2_CID_RDS_TX_MUSIC_SPEECH, 0, 1, 1, 1);
}
if (dev->has_sdr_cap) {
v4l2_ctrl_new_custom(hdl_sdr_cap,
&vivid_ctrl_sdr_cap_fm_deviation, NULL);
}
if (hdl_user_gen->error)
return hdl_user_gen->error;
if (hdl_user_vid->error)
return hdl_user_vid->error;
if (hdl_user_aud->error)
return hdl_user_aud->error;
if (hdl_streaming->error)
return hdl_streaming->error;
if (hdl_sdr_cap->error)
return hdl_sdr_cap->error;
if (hdl_loop_cap->error)
return hdl_loop_cap->error;
if (dev->autogain)
v4l2_ctrl_auto_cluster(2, &dev->autogain, 0, true);
if (dev->has_vid_cap) {
v4l2_ctrl_add_handler(hdl_vid_cap, hdl_user_gen, NULL);
v4l2_ctrl_add_handler(hdl_vid_cap, hdl_user_vid, NULL);
v4l2_ctrl_add_handler(hdl_vid_cap, hdl_user_aud, NULL);
v4l2_ctrl_add_handler(hdl_vid_cap, hdl_streaming, NULL);
v4l2_ctrl_add_handler(hdl_vid_cap, hdl_sdtv_cap, NULL);
v4l2_ctrl_add_handler(hdl_vid_cap, hdl_loop_cap, NULL);
if (hdl_vid_cap->error)
return hdl_vid_cap->error;
dev->vid_cap_dev.ctrl_handler = hdl_vid_cap;
}
if (dev->has_vid_out) {
v4l2_ctrl_add_handler(hdl_vid_out, hdl_user_gen, NULL);
v4l2_ctrl_add_handler(hdl_vid_out, hdl_user_aud, NULL);
v4l2_ctrl_add_handler(hdl_vid_out, hdl_streaming, NULL);
if (hdl_vid_out->error)
return hdl_vid_out->error;
dev->vid_out_dev.ctrl_handler = hdl_vid_out;
}
if (dev->has_vbi_cap) {
v4l2_ctrl_add_handler(hdl_vbi_cap, hdl_user_gen, NULL);
v4l2_ctrl_add_handler(hdl_vbi_cap, hdl_streaming, NULL);
v4l2_ctrl_add_handler(hdl_vbi_cap, hdl_sdtv_cap, NULL);
v4l2_ctrl_add_handler(hdl_vbi_cap, hdl_loop_cap, NULL);
if (hdl_vbi_cap->error)
return hdl_vbi_cap->error;
dev->vbi_cap_dev.ctrl_handler = hdl_vbi_cap;
}
if (dev->has_vbi_out) {
v4l2_ctrl_add_handler(hdl_vbi_out, hdl_user_gen, NULL);
v4l2_ctrl_add_handler(hdl_vbi_out, hdl_streaming, NULL);
if (hdl_vbi_out->error)
return hdl_vbi_out->error;
dev->vbi_out_dev.ctrl_handler = hdl_vbi_out;
}
if (dev->has_radio_rx) {
v4l2_ctrl_add_handler(hdl_radio_rx, hdl_user_gen, NULL);
v4l2_ctrl_add_handler(hdl_radio_rx, hdl_user_aud, NULL);
if (hdl_radio_rx->error)
return hdl_radio_rx->error;
dev->radio_rx_dev.ctrl_handler = hdl_radio_rx;
}
if (dev->has_radio_tx) {
v4l2_ctrl_add_handler(hdl_radio_tx, hdl_user_gen, NULL);
v4l2_ctrl_add_handler(hdl_radio_tx, hdl_user_aud, NULL);
if (hdl_radio_tx->error)
return hdl_radio_tx->error;
dev->radio_tx_dev.ctrl_handler = hdl_radio_tx;
}
if (dev->has_sdr_cap) {
v4l2_ctrl_add_handler(hdl_sdr_cap, hdl_user_gen, NULL);
v4l2_ctrl_add_handler(hdl_sdr_cap, hdl_streaming, NULL);
if (hdl_sdr_cap->error)
return hdl_sdr_cap->error;
dev->sdr_cap_dev.ctrl_handler = hdl_sdr_cap;
}
return 0;
}
void vivid_free_controls(struct vivid_dev *dev)
{
v4l2_ctrl_handler_free(&dev->ctrl_hdl_vid_cap);
v4l2_ctrl_handler_free(&dev->ctrl_hdl_vid_out);
v4l2_ctrl_handler_free(&dev->ctrl_hdl_vbi_cap);
v4l2_ctrl_handler_free(&dev->ctrl_hdl_vbi_out);
v4l2_ctrl_handler_free(&dev->ctrl_hdl_radio_rx);
v4l2_ctrl_handler_free(&dev->ctrl_hdl_radio_tx);
v4l2_ctrl_handler_free(&dev->ctrl_hdl_sdr_cap);
v4l2_ctrl_handler_free(&dev->ctrl_hdl_user_gen);
v4l2_ctrl_handler_free(&dev->ctrl_hdl_user_vid);
v4l2_ctrl_handler_free(&dev->ctrl_hdl_user_aud);
v4l2_ctrl_handler_free(&dev->ctrl_hdl_streaming);
v4l2_ctrl_handler_free(&dev->ctrl_hdl_sdtv_cap);
v4l2_ctrl_handler_free(&dev->ctrl_hdl_loop_cap);
}
