int m5mols_do_scenemode(struct m5mols_info *info, u8 mode)
{
struct v4l2_subdev *sd = &info->sd;
struct m5mols_scenemode scenemode = m5mols_default_scenemode[mode];
int ret;
if (mode > REG_SCENE_CANDLE)
return -EINVAL;
ret = m5mols_lock_3a(info, false);
if (!ret)
ret = m5mols_write(sd, AE_EV_PRESET_MONITOR, mode);
if (!ret)
ret = m5mols_write(sd, AE_EV_PRESET_CAPTURE, mode);
if (!ret)
ret = m5mols_write(sd, AE_MODE, scenemode.metering);
if (!ret)
ret = m5mols_write(sd, AE_INDEX, scenemode.ev_bias);
if (!ret)
ret = m5mols_write(sd, AWB_MODE, scenemode.wb_mode);
if (!ret)
ret = m5mols_write(sd, AWB_MANUAL, scenemode.wb_preset);
if (!ret)
ret = m5mols_write(sd, MON_CHROMA_EN, scenemode.chroma_en);
if (!ret)
ret = m5mols_write(sd, MON_CHROMA_LVL, scenemode.chroma_lvl);
if (!ret)
ret = m5mols_write(sd, MON_EDGE_EN, scenemode.edge_en);
if (!ret)
ret = m5mols_write(sd, MON_EDGE_LVL, scenemode.edge_lvl);
if (!ret && is_available_af(info))
ret = m5mols_write(sd, AF_MODE, scenemode.af_range);
if (!ret && is_available_af(info))
ret = m5mols_write(sd, FD_CTL, scenemode.fd_mode);
if (!ret)
ret = m5mols_write(sd, MON_TONE_CTL, scenemode.tone);
if (!ret)
ret = m5mols_write(sd, AE_ISO, scenemode.iso);
if (!ret)
ret = m5mols_mode(info, REG_CAPTURE);
if (!ret)
ret = m5mols_write(sd, CAPP_WDR_EN, scenemode.wdr);
if (!ret)
ret = m5mols_write(sd, CAPP_MCC_MODE, scenemode.mcc);
if (!ret)
ret = m5mols_write(sd, CAPP_LIGHT_CTRL, scenemode.light);
if (!ret)
ret = m5mols_write(sd, CAPP_FLASH_CTRL, scenemode.flash);
if (!ret)
ret = m5mols_write(sd, CAPC_MODE, scenemode.capt_mode);
if (!ret)
ret = m5mols_mode(info, REG_MONITOR);
return ret;
}
static int m5mols_lock_ae(struct m5mols_info *info, bool lock)
{
int ret = 0;
if (info->lock_ae != lock)
ret = m5mols_write(&info->sd, AE_LOCK,
lock ? REG_AE_LOCK : REG_AE_UNLOCK);
if (!ret)
info->lock_ae = lock;
return ret;
}
static int m5mols_lock_awb(struct m5mols_info *info, bool lock)
{
int ret = 0;
if (info->lock_awb != lock)
ret = m5mols_write(&info->sd, AWB_LOCK,
lock ? REG_AWB_LOCK : REG_AWB_UNLOCK);
if (!ret)
info->lock_awb = lock;
return ret;
}
int m5mols_lock_3a(struct m5mols_info *info, bool lock)
{
int ret;
ret = m5mols_lock_ae(info, lock);
if (!ret)
ret = m5mols_lock_awb(info, lock);
if (!ret && is_available_af(info) && lock)
ret = m5mols_write(&info->sd, AF_EXECUTE, REG_AF_STOP);
return ret;
}
int m5mols_set_ctrl(struct v4l2_ctrl *ctrl)
{
struct v4l2_subdev *sd = to_sd(ctrl);
struct m5mols_info *info = to_m5mols(sd);
int ret;
switch (ctrl->id) {
case V4L2_CID_ZOOM_ABSOLUTE:
return m5mols_write(sd, MON_ZOOM, ctrl->val);
case V4L2_CID_EXPOSURE_AUTO:
ret = m5mols_lock_ae(info,
ctrl->val == V4L2_EXPOSURE_AUTO ? false : true);
if (!ret && ctrl->val == V4L2_EXPOSURE_AUTO)
ret = m5mols_write(sd, AE_MODE, REG_AE_ALL);
if (!ret && ctrl->val == V4L2_EXPOSURE_MANUAL) {
int val = info->exposure->val;
ret = m5mols_write(sd, AE_MODE, REG_AE_OFF);
if (!ret)
ret = m5mols_write(sd, AE_MAN_GAIN_MON, val);
if (!ret)
ret = m5mols_write(sd, AE_MAN_GAIN_CAP, val);
}
return ret;
case V4L2_CID_AUTO_WHITE_BALANCE:
ret = m5mols_lock_awb(info, ctrl->val ? false : true);
if (!ret)
ret = m5mols_write(sd, AWB_MODE, ctrl->val ?
REG_AWB_AUTO : REG_AWB_PRESET);
return ret;
case V4L2_CID_SATURATION:
ret = m5mols_write(sd, MON_CHROMA_LVL, ctrl->val);
if (!ret)
ret = m5mols_write(sd, MON_CHROMA_EN, REG_CHROMA_ON);
return ret;
case V4L2_CID_COLORFX:
ret = m5mols_write(sd, PARM_EFFECT,
ctrl->val == V4L2_COLORFX_NEGATIVE ? REG_EFFECT_NEGA :
ctrl->val == V4L2_COLORFX_EMBOSS ? REG_EFFECT_EMBOSS :
REG_EFFECT_OFF);
if (!ret)
ret = m5mols_write(sd, MON_EFFECT,
ctrl->val == V4L2_COLORFX_SEPIA ?
REG_COLOR_EFFECT_ON : REG_COLOR_EFFECT_OFF);
if (!ret)
ret = m5mols_write(sd, MON_CFIXR,
ctrl->val == V4L2_COLORFX_SEPIA ?
REG_CFIXR_SEPIA : 0);
if (!ret)
ret = m5mols_write(sd, MON_CFIXB,
ctrl->val == V4L2_COLORFX_SEPIA ?
REG_CFIXB_SEPIA : 0);
return ret;
}
return -EINVAL;
}
