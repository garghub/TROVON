static inline struct au8522_state *to_state(struct v4l2_subdev *sd)
{
return container_of(sd, struct au8522_state, sd);
}
static void setup_vbi(struct au8522_state *state, int aud_input)
{
int i;
au8522_writereg(state, AU8522_TVDEC_VBI_CTRL_H_REG017H, 0x00);
au8522_writereg(state, AU8522_TVDEC_VBI_CTRL_L_REG018H, 0x00);
au8522_writereg(state, AU8522_TVDEC_VBI_USER_TOTAL_BITS_REG019H, 0x00);
au8522_writereg(state, AU8522_TVDEC_VBI_USER_TUNIT_H_REG01AH, 0x00);
au8522_writereg(state, AU8522_TVDEC_VBI_USER_TUNIT_L_REG01BH, 0x00);
au8522_writereg(state, AU8522_TVDEC_VBI_USER_THRESH1_REG01CH, 0x00);
au8522_writereg(state, AU8522_TVDEC_VBI_USER_FRAME_PAT2_REG01EH, 0x00);
au8522_writereg(state, AU8522_TVDEC_VBI_USER_FRAME_PAT1_REG01FH, 0x00);
au8522_writereg(state, AU8522_TVDEC_VBI_USER_FRAME_PAT0_REG020H, 0x00);
au8522_writereg(state, AU8522_TVDEC_VBI_USER_FRAME_MASK2_REG021H,
0x00);
au8522_writereg(state, AU8522_TVDEC_VBI_USER_FRAME_MASK1_REG022H,
0x00);
au8522_writereg(state, AU8522_TVDEC_VBI_USER_FRAME_MASK0_REG023H,
0x00);
for (i = 0x30; i < 0x60; i++)
au8522_writereg(state, i, 0x40);
au8522_writereg(state, 0x44, 0x60);
au8522_writereg(state, AU8522_TVDEC_VBI_CTRL_H_REG017H,
AU8522_TVDEC_VBI_CTRL_H_REG017H_CCON);
}
static void setup_decoder_defaults(struct au8522_state *state, bool is_svideo)
{
int i;
int filter_coef_type;
au8522_writereg(state, AU8522_TVDEC_SHARPNESSREG009H, 0x07);
au8522_writereg(state, AU8522_TVDEC_BRIGHTNESS_REG00AH, 0xed);
au8522_writereg(state, AU8522_TVDEC_CONTRAST_REG00BH, 0x79);
au8522_writereg(state, AU8522_TVDEC_SATURATION_CB_REG00CH, 0x80);
au8522_writereg(state, AU8522_TVDEC_SATURATION_CR_REG00DH, 0x80);
au8522_writereg(state, AU8522_TVDEC_HUE_H_REG00EH, 0x00);
au8522_writereg(state, AU8522_TVDEC_HUE_L_REG00FH, 0x00);
au8522_writereg(state, AU8522_TVDEC_INT_MASK_REG010H, 0x00);
if (is_svideo)
au8522_writereg(state, AU8522_VIDEO_MODE_REG011H, 0x04);
else
au8522_writereg(state, AU8522_VIDEO_MODE_REG011H, 0x00);
au8522_writereg(state, AU8522_TVDEC_PGA_REG012H,
AU8522_TVDEC_PGA_REG012H_CVBS);
au8522_writereg(state, AU8522_TVDEC_COMB_MODE_REG015H,
AU8522_TVDEC_COMB_MODE_REG015H_CVBS);
au8522_writereg(state, AU8522_TVDED_DBG_MODE_REG060H,
AU8522_TVDED_DBG_MODE_REG060H_CVBS);
if (state->std == V4L2_STD_PAL_M) {
au8522_writereg(state, AU8522_TVDEC_FORMAT_CTRL1_REG061H,
AU8522_TVDEC_FORMAT_CTRL1_REG061H_FIELD_LEN_525 |
AU8522_TVDEC_FORMAT_CTRL1_REG061H_LINE_LEN_63_492 |
AU8522_TVDEC_FORMAT_CTRL1_REG061H_SUBCARRIER_NTSC_AUTO);
au8522_writereg(state, AU8522_TVDEC_FORMAT_CTRL2_REG062H,
AU8522_TVDEC_FORMAT_CTRL2_REG062H_STD_PAL_M);
} else {
au8522_writereg(state, AU8522_TVDEC_FORMAT_CTRL1_REG061H,
AU8522_TVDEC_FORMAT_CTRL1_REG061H_FIELD_LEN_525 |
AU8522_TVDEC_FORMAT_CTRL1_REG061H_LINE_LEN_63_492 |
AU8522_TVDEC_FORMAT_CTRL1_REG061H_SUBCARRIER_NTSC_MN);
au8522_writereg(state, AU8522_TVDEC_FORMAT_CTRL2_REG062H,
AU8522_TVDEC_FORMAT_CTRL2_REG062H_STD_NTSC);
}
au8522_writereg(state, AU8522_TVDEC_VCR_DET_LLIM_REG063H,
AU8522_TVDEC_VCR_DET_LLIM_REG063H_CVBS);
au8522_writereg(state, AU8522_TVDEC_VCR_DET_HLIM_REG064H,
AU8522_TVDEC_VCR_DET_HLIM_REG064H_CVBS);
au8522_writereg(state, AU8522_TVDEC_COMB_VDIF_THR1_REG065H,
AU8522_TVDEC_COMB_VDIF_THR1_REG065H_CVBS);
au8522_writereg(state, AU8522_TVDEC_COMB_VDIF_THR2_REG066H,
AU8522_TVDEC_COMB_VDIF_THR2_REG066H_CVBS);
au8522_writereg(state, AU8522_TVDEC_COMB_VDIF_THR3_REG067H,
AU8522_TVDEC_COMB_VDIF_THR3_REG067H_CVBS);
au8522_writereg(state, AU8522_TVDEC_COMB_NOTCH_THR_REG068H,
AU8522_TVDEC_COMB_NOTCH_THR_REG068H_CVBS);
au8522_writereg(state, AU8522_TVDEC_COMB_HDIF_THR1_REG069H,
AU8522_TVDEC_COMB_HDIF_THR1_REG069H_CVBS);
au8522_writereg(state, AU8522_TVDEC_COMB_HDIF_THR2_REG06AH,
AU8522_TVDEC_COMB_HDIF_THR2_REG06AH_CVBS);
au8522_writereg(state, AU8522_TVDEC_COMB_HDIF_THR3_REG06BH,
AU8522_TVDEC_COMB_HDIF_THR3_REG06BH_CVBS);
if (is_svideo) {
au8522_writereg(state, AU8522_TVDEC_COMB_DCDIF_THR1_REG06CH,
AU8522_TVDEC_COMB_DCDIF_THR1_REG06CH_SVIDEO);
au8522_writereg(state, AU8522_TVDEC_COMB_DCDIF_THR2_REG06DH,
AU8522_TVDEC_COMB_DCDIF_THR2_REG06DH_SVIDEO);
} else {
au8522_writereg(state, AU8522_TVDEC_COMB_DCDIF_THR1_REG06CH,
AU8522_TVDEC_COMB_DCDIF_THR1_REG06CH_CVBS);
au8522_writereg(state, AU8522_TVDEC_COMB_DCDIF_THR2_REG06DH,
AU8522_TVDEC_COMB_DCDIF_THR2_REG06DH_CVBS);
}
au8522_writereg(state, AU8522_TVDEC_COMB_DCDIF_THR3_REG06EH,
AU8522_TVDEC_COMB_DCDIF_THR3_REG06EH_CVBS);
au8522_writereg(state, AU8522_TVDEC_UV_SEP_THR_REG06FH,
AU8522_TVDEC_UV_SEP_THR_REG06FH_CVBS);
au8522_writereg(state, AU8522_TVDEC_COMB_DC_THR1_NTSC_REG070H,
AU8522_TVDEC_COMB_DC_THR1_NTSC_REG070H_CVBS);
au8522_writereg(state, AU8522_REG071H, AU8522_REG071H_CVBS);
au8522_writereg(state, AU8522_REG072H, AU8522_REG072H_CVBS);
au8522_writereg(state, AU8522_TVDEC_COMB_DC_THR2_NTSC_REG073H,
AU8522_TVDEC_COMB_DC_THR2_NTSC_REG073H_CVBS);
au8522_writereg(state, AU8522_REG074H, AU8522_REG074H_CVBS);
au8522_writereg(state, AU8522_REG075H, AU8522_REG075H_CVBS);
au8522_writereg(state, AU8522_TVDEC_DCAGC_CTRL_REG077H,
AU8522_TVDEC_DCAGC_CTRL_REG077H_CVBS);
au8522_writereg(state, AU8522_TVDEC_PIC_START_ADJ_REG078H,
AU8522_TVDEC_PIC_START_ADJ_REG078H_CVBS);
au8522_writereg(state, AU8522_TVDEC_AGC_HIGH_LIMIT_REG079H,
AU8522_TVDEC_AGC_HIGH_LIMIT_REG079H_CVBS);
au8522_writereg(state, AU8522_TVDEC_MACROVISION_SYNC_THR_REG07AH,
AU8522_TVDEC_MACROVISION_SYNC_THR_REG07AH_CVBS);
au8522_writereg(state, AU8522_TVDEC_INTRP_CTRL_REG07BH,
AU8522_TVDEC_INTRP_CTRL_REG07BH_CVBS);
au8522_writereg(state, AU8522_TVDEC_AGC_LOW_LIMIT_REG0E4H,
AU8522_TVDEC_AGC_LOW_LIMIT_REG0E4H_CVBS);
au8522_writereg(state, AU8522_TOREGAAGC_REG0E5H,
AU8522_TOREGAAGC_REG0E5H_CVBS);
au8522_writereg(state, AU8522_REG016H, AU8522_REG016H_CVBS);
setup_vbi(state, 0);
if (is_svideo) {
filter_coef_type = 5;
} else {
filter_coef_type = 5;
}
for (i = 0; i < NUM_FILTER_COEF; i++) {
au8522_writereg(state, filter_coef[i].reg_name,
filter_coef[i].reg_val[filter_coef_type]);
}
au8522_writereg(state, AU8522_REG42EH, 0x87);
au8522_writereg(state, AU8522_REG42FH, 0xa2);
au8522_writereg(state, AU8522_REG430H, 0xbf);
au8522_writereg(state, AU8522_REG431H, 0xcb);
au8522_writereg(state, AU8522_REG432H, 0xa1);
au8522_writereg(state, AU8522_REG433H, 0x41);
au8522_writereg(state, AU8522_REG434H, 0x88);
au8522_writereg(state, AU8522_REG435H, 0xc2);
au8522_writereg(state, AU8522_REG436H, 0x3c);
}
static void au8522_setup_cvbs_mode(struct au8522_state *state, u8 input_mode)
{
au8522_writereg(state, AU8522_MODULE_CLOCK_CONTROL_REG0A3H,
AU8522_MODULE_CLOCK_CONTROL_REG0A3H_CVBS);
au8522_writereg(state, AU8522_PGA_CONTROL_REG082H, 0x00);
au8522_writereg(state, AU8522_CLAMPING_CONTROL_REG083H, 0x00);
au8522_writereg(state, AU8522_INPUT_CONTROL_REG081H, input_mode);
setup_decoder_defaults(state, false);
au8522_writereg(state, AU8522_SYSTEM_MODULE_CONTROL_0_REG0A4H,
AU8522_SYSTEM_MODULE_CONTROL_0_REG0A4H_CVBS);
}
static void au8522_setup_cvbs_tuner_mode(struct au8522_state *state,
u8 input_mode)
{
au8522_writereg(state, AU8522_MODULE_CLOCK_CONTROL_REG0A3H,
AU8522_MODULE_CLOCK_CONTROL_REG0A3H_CVBS);
au8522_writereg(state, AU8522_PGA_CONTROL_REG082H, 0x00);
au8522_writereg(state, AU8522_CLAMPING_CONTROL_REG083H, 0x0e);
au8522_writereg(state, AU8522_PGA_CONTROL_REG082H, 0x10);
au8522_writereg(state, AU8522_INPUT_CONTROL_REG081H, input_mode);
setup_decoder_defaults(state, false);
au8522_writereg(state, AU8522_SYSTEM_MODULE_CONTROL_0_REG0A4H,
AU8522_SYSTEM_MODULE_CONTROL_0_REG0A4H_CVBS);
}
static void au8522_setup_svideo_mode(struct au8522_state *state,
u8 input_mode)
{
au8522_writereg(state, AU8522_MODULE_CLOCK_CONTROL_REG0A3H,
AU8522_MODULE_CLOCK_CONTROL_REG0A3H_SVIDEO);
au8522_writereg(state, AU8522_INPUT_CONTROL_REG081H, input_mode);
au8522_writereg(state, AU8522_PGA_CONTROL_REG082H, 0x00);
au8522_writereg(state, AU8522_CLAMPING_CONTROL_REG083H, 0x00);
setup_decoder_defaults(state, true);
au8522_writereg(state, AU8522_SYSTEM_MODULE_CONTROL_0_REG0A4H,
AU8522_SYSTEM_MODULE_CONTROL_0_REG0A4H_CVBS);
}
static void disable_audio_input(struct au8522_state *state)
{
au8522_writereg(state, AU8522_AUDIO_VOLUME_L_REG0F2H, 0x00);
au8522_writereg(state, AU8522_AUDIO_VOLUME_R_REG0F3H, 0x00);
au8522_writereg(state, AU8522_AUDIO_VOLUME_REG0F4H, 0x00);
au8522_writereg(state, AU8522_SYSTEM_MODULE_CONTROL_1_REG0A5H, 0x04);
au8522_writereg(state, AU8522_I2S_CTRL_2_REG112H, 0x02);
au8522_writereg(state, AU8522_SYSTEM_MODULE_CONTROL_0_REG0A4H,
AU8522_SYSTEM_MODULE_CONTROL_0_REG0A4H_SVIDEO);
}
static void set_audio_input(struct au8522_state *state)
{
int aud_input = state->aud_input;
int i;
if (aud_input == AU8522_AUDIO_NONE) {
disable_audio_input(state);
return;
}
if (aud_input != AU8522_AUDIO_SIF) {
printk(KERN_ERR "Unsupported audio mode requested! mode=%d\n",
aud_input);
return;
}
for (i = 0; i < NUM_LPFILTER_COEF; i++) {
au8522_writereg(state, lpfilter_coef[i].reg_name,
lpfilter_coef[i].reg_val[0]);
}
au8522_writereg(state, AU8522_AUDIO_VOLUME_L_REG0F2H, 0x00);
au8522_writereg(state, AU8522_AUDIO_VOLUME_R_REG0F3H, 0x00);
au8522_writereg(state, AU8522_AUDIO_VOLUME_REG0F4H, 0x00);
au8522_writereg(state, AU8522_I2C_CONTROL_REG1_REG091H, 0x80);
au8522_writereg(state, AU8522_I2C_CONTROL_REG0_REG090H, 0x84);
msleep(150);
au8522_writereg(state, AU8522_SYSTEM_MODULE_CONTROL_0_REG0A4H, 0x00);
msleep(10);
au8522_writereg(state, AU8522_SYSTEM_MODULE_CONTROL_0_REG0A4H,
AU8522_SYSTEM_MODULE_CONTROL_0_REG0A4H_CVBS);
msleep(50);
au8522_writereg(state, AU8522_AUDIO_VOLUME_L_REG0F2H, 0x7F);
au8522_writereg(state, AU8522_AUDIO_VOLUME_R_REG0F3H, 0x7F);
au8522_writereg(state, AU8522_AUDIO_VOLUME_REG0F4H, 0xff);
msleep(80);
au8522_writereg(state, AU8522_AUDIO_VOLUME_L_REG0F2H, 0x7F);
au8522_writereg(state, AU8522_AUDIO_VOLUME_R_REG0F3H, 0x7F);
au8522_writereg(state, AU8522_REG0F9H, AU8522_REG0F9H_AUDIO);
au8522_writereg(state, AU8522_AUDIO_MODE_REG0F1H, 0x82);
msleep(70);
au8522_writereg(state, AU8522_SYSTEM_MODULE_CONTROL_1_REG0A5H, 0x09);
au8522_writereg(state, AU8522_AUDIOFREQ_REG606H, 0x03);
au8522_writereg(state, AU8522_I2S_CTRL_2_REG112H, 0xc2);
}
static int au8522_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct au8522_state *state =
container_of(ctrl->handler, struct au8522_state, hdl);
switch (ctrl->id) {
case V4L2_CID_BRIGHTNESS:
au8522_writereg(state, AU8522_TVDEC_BRIGHTNESS_REG00AH,
ctrl->val - 128);
break;
case V4L2_CID_CONTRAST:
au8522_writereg(state, AU8522_TVDEC_CONTRAST_REG00BH,
ctrl->val);
break;
case V4L2_CID_SATURATION:
au8522_writereg(state, AU8522_TVDEC_SATURATION_CB_REG00CH,
ctrl->val);
au8522_writereg(state, AU8522_TVDEC_SATURATION_CR_REG00DH,
ctrl->val);
break;
case V4L2_CID_HUE:
au8522_writereg(state, AU8522_TVDEC_HUE_H_REG00EH,
ctrl->val >> 8);
au8522_writereg(state, AU8522_TVDEC_HUE_L_REG00FH,
ctrl->val & 0xFF);
break;
default:
return -EINVAL;
}
return 0;
}
static int au8522_g_register(struct v4l2_subdev *sd,
struct v4l2_dbg_register *reg)
{
struct au8522_state *state = to_state(sd);
reg->val = au8522_readreg(state, reg->reg & 0xffff);
return 0;
}
static int au8522_s_register(struct v4l2_subdev *sd,
const struct v4l2_dbg_register *reg)
{
struct au8522_state *state = to_state(sd);
au8522_writereg(state, reg->reg, reg->val & 0xff);
return 0;
}
static void au8522_video_set(struct au8522_state *state)
{
u8 input_mode;
au8522_writereg(state, 0xa4, 1 << 5);
switch (state->vid_input) {
case AU8522_COMPOSITE_CH1:
input_mode = AU8522_INPUT_CONTROL_REG081H_CVBS_CH1;
au8522_setup_cvbs_mode(state, input_mode);
break;
case AU8522_COMPOSITE_CH2:
input_mode = AU8522_INPUT_CONTROL_REG081H_CVBS_CH2;
au8522_setup_cvbs_mode(state, input_mode);
break;
case AU8522_COMPOSITE_CH3:
input_mode = AU8522_INPUT_CONTROL_REG081H_CVBS_CH3;
au8522_setup_cvbs_mode(state, input_mode);
break;
case AU8522_COMPOSITE_CH4:
input_mode = AU8522_INPUT_CONTROL_REG081H_CVBS_CH4;
au8522_setup_cvbs_mode(state, input_mode);
break;
case AU8522_SVIDEO_CH13:
input_mode = AU8522_INPUT_CONTROL_REG081H_SVIDEO_CH13;
au8522_setup_svideo_mode(state, input_mode);
break;
case AU8522_SVIDEO_CH24:
input_mode = AU8522_INPUT_CONTROL_REG081H_SVIDEO_CH24;
au8522_setup_svideo_mode(state, input_mode);
break;
default:
case AU8522_COMPOSITE_CH4_SIF:
input_mode = AU8522_INPUT_CONTROL_REG081H_CVBS_CH4_SIF;
au8522_setup_cvbs_tuner_mode(state, input_mode);
break;
}
}
static int au8522_s_stream(struct v4l2_subdev *sd, int enable)
{
struct au8522_state *state = to_state(sd);
if (enable) {
state->current_frequency = 0;
au8522_writereg(state, AU8522_SYSTEM_MODULE_CONTROL_0_REG0A4H,
0x01);
msleep(10);
au8522_video_set(state);
set_audio_input(state);
state->operational_mode = AU8522_ANALOG_MODE;
} else {
au8522_writereg(state, AU8522_SYSTEM_MODULE_CONTROL_0_REG0A4H,
1 << 5);
state->operational_mode = AU8522_SUSPEND_MODE;
}
return 0;
}
static int au8522_s_video_routing(struct v4l2_subdev *sd,
u32 input, u32 output, u32 config)
{
struct au8522_state *state = to_state(sd);
switch(input) {
case AU8522_COMPOSITE_CH1:
case AU8522_SVIDEO_CH13:
case AU8522_COMPOSITE_CH4_SIF:
state->vid_input = input;
break;
default:
printk(KERN_ERR "au8522 mode not currently supported\n");
return -EINVAL;
}
if (state->operational_mode == AU8522_ANALOG_MODE)
au8522_video_set(state);
return 0;
}
static int au8522_s_std(struct v4l2_subdev *sd, v4l2_std_id std)
{
struct au8522_state *state = to_state(sd);
if ((std & (V4L2_STD_PAL_M | V4L2_STD_NTSC_M)) == 0)
return -EINVAL;
state->std = std;
if (state->operational_mode == AU8522_ANALOG_MODE)
au8522_video_set(state);
return 0;
}
static int au8522_s_audio_routing(struct v4l2_subdev *sd,
u32 input, u32 output, u32 config)
{
struct au8522_state *state = to_state(sd);
state->aud_input = input;
if (state->operational_mode == AU8522_ANALOG_MODE)
set_audio_input(state);
return 0;
}
static int au8522_g_tuner(struct v4l2_subdev *sd, struct v4l2_tuner *vt)
{
int val = 0;
struct au8522_state *state = to_state(sd);
u8 lock_status;
lock_status = au8522_readreg(state, 0x00);
if (lock_status == 0xa2)
vt->signal = 0xffff;
else
vt->signal = 0x00;
vt->capability |=
V4L2_TUNER_CAP_STEREO | V4L2_TUNER_CAP_LANG1 |
V4L2_TUNER_CAP_LANG2 | V4L2_TUNER_CAP_SAP;
val = V4L2_TUNER_SUB_MONO;
vt->rxsubchans = val;
vt->audmode = V4L2_TUNER_MODE_STEREO;
return 0;
}
static int au8522_probe(struct i2c_client *client,
const struct i2c_device_id *did)
{
struct au8522_state *state;
struct v4l2_ctrl_handler *hdl;
struct v4l2_subdev *sd;
int instance;
#ifdef CONFIG_MEDIA_CONTROLLER
int ret;
#endif
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_BYTE_DATA)) {
return -EIO;
}
instance = au8522_get_state(&state, client->adapter, client->addr);
switch (instance) {
case 0:
printk(KERN_ERR "au8522_decoder allocation failed\n");
return -EIO;
case 1:
printk(KERN_INFO "au8522_decoder creating new instance...\n");
break;
default:
printk(KERN_INFO "au8522_decoder attach existing instance.\n");
break;
}
state->config.demod_address = 0x8e >> 1;
state->i2c = client->adapter;
sd = &state->sd;
v4l2_i2c_subdev_init(sd, client, &au8522_ops);
#if defined(CONFIG_MEDIA_CONTROLLER)
state->pads[DEMOD_PAD_IF_INPUT].flags = MEDIA_PAD_FL_SINK;
state->pads[DEMOD_PAD_VID_OUT].flags = MEDIA_PAD_FL_SOURCE;
state->pads[DEMOD_PAD_VBI_OUT].flags = MEDIA_PAD_FL_SOURCE;
state->pads[DEMOD_PAD_AUDIO_OUT].flags = MEDIA_PAD_FL_SOURCE;
sd->entity.function = MEDIA_ENT_F_ATV_DECODER;
ret = media_entity_pads_init(&sd->entity, ARRAY_SIZE(state->pads),
state->pads);
if (ret < 0) {
v4l_info(client, "failed to initialize media entity!\n");
return ret;
}
#endif
hdl = &state->hdl;
v4l2_ctrl_handler_init(hdl, 4);
v4l2_ctrl_new_std(hdl, &au8522_ctrl_ops,
V4L2_CID_BRIGHTNESS, 0, 255, 1, 109);
v4l2_ctrl_new_std(hdl, &au8522_ctrl_ops,
V4L2_CID_CONTRAST, 0, 255, 1,
AU8522_TVDEC_CONTRAST_REG00BH_CVBS);
v4l2_ctrl_new_std(hdl, &au8522_ctrl_ops,
V4L2_CID_SATURATION, 0, 255, 1, 128);
v4l2_ctrl_new_std(hdl, &au8522_ctrl_ops,
V4L2_CID_HUE, -32768, 32767, 1, 0);
sd->ctrl_handler = hdl;
if (hdl->error) {
int err = hdl->error;
v4l2_ctrl_handler_free(hdl);
au8522_release_state(state);
return err;
}
state->c = client;
state->std = V4L2_STD_NTSC_M;
state->vid_input = AU8522_COMPOSITE_CH1;
state->aud_input = AU8522_AUDIO_NONE;
state->id = 8522;
state->rev = 0;
au8522_writereg(state, 0x106, 1);
return 0;
}
static int au8522_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
v4l2_device_unregister_subdev(sd);
v4l2_ctrl_handler_free(sd->ctrl_handler);
au8522_release_state(to_state(sd));
return 0;
}
