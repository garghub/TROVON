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
static void setup_decoder_defaults(struct au8522_state *state, u8 input_mode)
{
int i;
int filter_coef_type;
au8522_writereg(state, AU8522_TVDEC_SHARPNESSREG009H, 0x07);
au8522_writereg(state, AU8522_TVDEC_BRIGHTNESS_REG00AH, 0xed);
state->brightness = 0xed - 128;
au8522_writereg(state, AU8522_TVDEC_CONTRAST_REG00BH, 0x79);
state->contrast = 0x79;
au8522_writereg(state, AU8522_TVDEC_SATURATION_CB_REG00CH, 0x80);
au8522_writereg(state, AU8522_TVDEC_SATURATION_CR_REG00DH, 0x80);
state->saturation = 0x80;
au8522_writereg(state, AU8522_TVDEC_HUE_H_REG00EH, 0x00);
au8522_writereg(state, AU8522_TVDEC_HUE_L_REG00FH, 0x00);
state->hue = 0x00;
au8522_writereg(state, AU8522_TVDEC_INT_MASK_REG010H, 0x00);
if (input_mode == 0x23) {
au8522_writereg(state, AU8522_VIDEO_MODE_REG011H, 0x04);
} else {
au8522_writereg(state, AU8522_VIDEO_MODE_REG011H, 0x00);
}
au8522_writereg(state, AU8522_TVDEC_PGA_REG012H,
AU8522_TVDEC_PGA_REG012H_CVBS);
au8522_writereg(state, AU8522_TVDEC_COMB_MODE_REG015H,
AU8522_TVDEC_COMB_MODE_REG015H_CVBS);
au8522_writereg(state, AU8522_TVDED_DBG_MODE_REG060H,
AU8522_TVDED_DBG_MODE_REG060H_CVBS);
au8522_writereg(state, AU8522_TVDEC_FORMAT_CTRL1_REG061H,
AU8522_TVDEC_FORMAT_CTRL1_REG061H_FIELD_LEN_525 |
AU8522_TVDEC_FORMAT_CTRL1_REG061H_LINE_LEN_63_492 |
AU8522_TVDEC_FORMAT_CTRL1_REG061H_SUBCARRIER_NTSC_MN);
au8522_writereg(state, AU8522_TVDEC_FORMAT_CTRL2_REG062H,
AU8522_TVDEC_FORMAT_CTRL2_REG062H_STD_NTSC);
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
if (input_mode == AU8522_INPUT_CONTROL_REG081H_SVIDEO_CH13 ||
input_mode == AU8522_INPUT_CONTROL_REG081H_SVIDEO_CH24) {
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
if (input_mode == AU8522_INPUT_CONTROL_REG081H_SVIDEO_CH13 ||
input_mode == AU8522_INPUT_CONTROL_REG081H_SVIDEO_CH24) {
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
static void au8522_setup_cvbs_mode(struct au8522_state *state)
{
au8522_writereg(state, AU8522_MODULE_CLOCK_CONTROL_REG0A3H,
AU8522_MODULE_CLOCK_CONTROL_REG0A3H_CVBS);
au8522_writereg(state, AU8522_PGA_CONTROL_REG082H, 0x00);
au8522_writereg(state, AU8522_CLAMPING_CONTROL_REG083H, 0x00);
au8522_writereg(state, AU8522_INPUT_CONTROL_REG081H,
AU8522_INPUT_CONTROL_REG081H_CVBS_CH1);
setup_decoder_defaults(state, AU8522_INPUT_CONTROL_REG081H_CVBS_CH1);
au8522_writereg(state, AU8522_SYSTEM_MODULE_CONTROL_0_REG0A4H,
AU8522_SYSTEM_MODULE_CONTROL_0_REG0A4H_CVBS);
}
static void au8522_setup_cvbs_tuner_mode(struct au8522_state *state)
{
au8522_writereg(state, AU8522_MODULE_CLOCK_CONTROL_REG0A3H,
AU8522_MODULE_CLOCK_CONTROL_REG0A3H_CVBS);
au8522_writereg(state, AU8522_PGA_CONTROL_REG082H, 0x00);
au8522_writereg(state, AU8522_CLAMPING_CONTROL_REG083H, 0x0e);
au8522_writereg(state, AU8522_PGA_CONTROL_REG082H, 0x10);
au8522_writereg(state, AU8522_INPUT_CONTROL_REG081H,
AU8522_INPUT_CONTROL_REG081H_CVBS_CH4_SIF);
setup_decoder_defaults(state,
AU8522_INPUT_CONTROL_REG081H_CVBS_CH4_SIF);
au8522_writereg(state, AU8522_SYSTEM_MODULE_CONTROL_0_REG0A4H,
AU8522_SYSTEM_MODULE_CONTROL_0_REG0A4H_CVBS);
}
static void au8522_setup_svideo_mode(struct au8522_state *state)
{
au8522_writereg(state, AU8522_MODULE_CLOCK_CONTROL_REG0A3H,
AU8522_MODULE_CLOCK_CONTROL_REG0A3H_SVIDEO);
au8522_writereg(state, AU8522_INPUT_CONTROL_REG081H,
AU8522_INPUT_CONTROL_REG081H_SVIDEO_CH13);
au8522_writereg(state, AU8522_PGA_CONTROL_REG082H, 0x00);
au8522_writereg(state, AU8522_CLAMPING_CONTROL_REG083H, 0x00);
setup_decoder_defaults(state,
AU8522_INPUT_CONTROL_REG081H_SVIDEO_CH13);
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
static void set_audio_input(struct au8522_state *state, int aud_input)
{
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
msleep(1);
au8522_writereg(state, AU8522_SYSTEM_MODULE_CONTROL_0_REG0A4H, 0x9d);
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
static int au8522_s_ctrl(struct v4l2_subdev *sd, struct v4l2_control *ctrl)
{
struct au8522_state *state = to_state(sd);
switch (ctrl->id) {
case V4L2_CID_BRIGHTNESS:
state->brightness = ctrl->value;
au8522_writereg(state, AU8522_TVDEC_BRIGHTNESS_REG00AH,
ctrl->value - 128);
break;
case V4L2_CID_CONTRAST:
state->contrast = ctrl->value;
au8522_writereg(state, AU8522_TVDEC_CONTRAST_REG00BH,
ctrl->value);
break;
case V4L2_CID_SATURATION:
state->saturation = ctrl->value;
au8522_writereg(state, AU8522_TVDEC_SATURATION_CB_REG00CH,
ctrl->value);
au8522_writereg(state, AU8522_TVDEC_SATURATION_CR_REG00DH,
ctrl->value);
break;
case V4L2_CID_HUE:
state->hue = ctrl->value;
au8522_writereg(state, AU8522_TVDEC_HUE_H_REG00EH,
ctrl->value >> 8);
au8522_writereg(state, AU8522_TVDEC_HUE_L_REG00FH,
ctrl->value & 0xFF);
break;
case V4L2_CID_AUDIO_VOLUME:
case V4L2_CID_AUDIO_BASS:
case V4L2_CID_AUDIO_TREBLE:
case V4L2_CID_AUDIO_BALANCE:
case V4L2_CID_AUDIO_MUTE:
default:
return -EINVAL;
}
return 0;
}
static int au8522_g_ctrl(struct v4l2_subdev *sd, struct v4l2_control *ctrl)
{
struct au8522_state *state = to_state(sd);
switch (ctrl->id) {
case V4L2_CID_BRIGHTNESS:
ctrl->value = state->brightness;
break;
case V4L2_CID_CONTRAST:
ctrl->value = state->contrast;
break;
case V4L2_CID_SATURATION:
ctrl->value = state->saturation;
break;
case V4L2_CID_HUE:
ctrl->value = state->hue;
break;
case V4L2_CID_AUDIO_VOLUME:
case V4L2_CID_AUDIO_BASS:
case V4L2_CID_AUDIO_TREBLE:
case V4L2_CID_AUDIO_BALANCE:
case V4L2_CID_AUDIO_MUTE:
default:
return -EINVAL;
}
return 0;
}
static int au8522_g_register(struct v4l2_subdev *sd,
struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct au8522_state *state = to_state(sd);
if (!v4l2_chip_match_i2c_client(client, &reg->match))
return -EINVAL;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
reg->val = au8522_readreg(state, reg->reg & 0xffff);
return 0;
}
static int au8522_s_register(struct v4l2_subdev *sd,
struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct au8522_state *state = to_state(sd);
if (!v4l2_chip_match_i2c_client(client, &reg->match))
return -EINVAL;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
au8522_writereg(state, reg->reg, reg->val & 0xff);
return 0;
}
static int au8522_s_stream(struct v4l2_subdev *sd, int enable)
{
struct au8522_state *state = to_state(sd);
if (enable) {
au8522_writereg(state, AU8522_SYSTEM_MODULE_CONTROL_0_REG0A4H,
0x01);
msleep(1);
au8522_writereg(state, AU8522_SYSTEM_MODULE_CONTROL_0_REG0A4H,
AU8522_SYSTEM_MODULE_CONTROL_0_REG0A4H_CVBS);
} else {
au8522_writereg(state, AU8522_SYSTEM_MODULE_CONTROL_0_REG0A4H,
1 << 5);
}
return 0;
}
static int au8522_queryctrl(struct v4l2_subdev *sd, struct v4l2_queryctrl *qc)
{
switch (qc->id) {
case V4L2_CID_CONTRAST:
return v4l2_ctrl_query_fill(qc, 0, 255, 1,
AU8522_TVDEC_CONTRAST_REG00BH_CVBS);
case V4L2_CID_BRIGHTNESS:
return v4l2_ctrl_query_fill(qc, 0, 255, 1, 109);
case V4L2_CID_SATURATION:
return v4l2_ctrl_query_fill(qc, 0, 255, 1, 128);
case V4L2_CID_HUE:
return v4l2_ctrl_query_fill(qc, -32768, 32768, 1, 0);
default:
break;
}
qc->type = 0;
return -EINVAL;
}
static int au8522_reset(struct v4l2_subdev *sd, u32 val)
{
struct au8522_state *state = to_state(sd);
state->operational_mode = AU8522_ANALOG_MODE;
state->current_frequency = 0;
au8522_writereg(state, 0xa4, 1 << 5);
return 0;
}
static int au8522_s_video_routing(struct v4l2_subdev *sd,
u32 input, u32 output, u32 config)
{
struct au8522_state *state = to_state(sd);
au8522_reset(sd, 0);
if (input == AU8522_COMPOSITE_CH1) {
au8522_setup_cvbs_mode(state);
} else if (input == AU8522_SVIDEO_CH13) {
au8522_setup_svideo_mode(state);
} else if (input == AU8522_COMPOSITE_CH4_SIF) {
au8522_setup_cvbs_tuner_mode(state);
} else {
printk(KERN_ERR "au8522 mode not currently supported\n");
return -EINVAL;
}
return 0;
}
static int au8522_s_audio_routing(struct v4l2_subdev *sd,
u32 input, u32 output, u32 config)
{
struct au8522_state *state = to_state(sd);
set_audio_input(state, input);
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
static int au8522_g_chip_ident(struct v4l2_subdev *sd,
struct v4l2_dbg_chip_ident *chip)
{
struct au8522_state *state = to_state(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
return v4l2_chip_ident_i2c_client(client, chip, state->id, state->rev);
}
static int au8522_log_status(struct v4l2_subdev *sd)
{
return 0;
}
static int au8522_probe(struct i2c_client *client,
const struct i2c_device_id *did)
{
struct au8522_state *state;
struct v4l2_subdev *sd;
int instance;
struct au8522_config *demod_config;
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
demod_config = kzalloc(sizeof(struct au8522_config), GFP_KERNEL);
if (demod_config == NULL) {
if (instance == 1)
kfree(state);
return -ENOMEM;
}
demod_config->demod_address = 0x8e >> 1;
state->config = demod_config;
state->i2c = client->adapter;
sd = &state->sd;
v4l2_i2c_subdev_init(sd, client, &au8522_ops);
state->c = client;
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
au8522_release_state(to_state(sd));
return 0;
}
