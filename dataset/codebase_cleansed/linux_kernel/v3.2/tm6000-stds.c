static int tm6000_set_audio_std(struct tm6000_core *dev)
{
uint8_t areg_02 = 0x04;
uint8_t areg_05 = 0x01;
uint8_t areg_06 = 0x02;
uint8_t nicam_flag = 0;
if (dev->radio) {
tm6000_set_reg(dev, TM6010_REQ08_R01_A_INIT, 0x00);
tm6000_set_reg(dev, TM6010_REQ08_R02_A_FIX_GAIN_CTRL, 0x04);
tm6000_set_reg(dev, TM6010_REQ08_R03_A_AUTO_GAIN_CTRL, 0x00);
tm6000_set_reg(dev, TM6010_REQ08_R04_A_SIF_AMP_CTRL, 0x80);
tm6000_set_reg(dev, TM6010_REQ08_R05_A_STANDARD_MOD, 0x0c);
if (dev->amode == V4L2_TUNER_MODE_MONO)
tm6000_set_reg(dev, TM6010_REQ08_R06_A_SOUND_MOD, 0x00);
else if (dev->amode == V4L2_TUNER_MODE_STEREO)
tm6000_set_reg(dev, TM6010_REQ08_R06_A_SOUND_MOD, 0x02);
tm6000_set_reg(dev, TM6010_REQ08_R09_A_MAIN_VOL, 0x18);
tm6000_set_reg(dev, TM6010_REQ08_R0C_A_ASD_THRES2, 0x0a);
tm6000_set_reg(dev, TM6010_REQ08_R0D_A_AMD_THRES, 0x40);
tm6000_set_reg(dev, TM6010_REQ08_RF1_AADC_POWER_DOWN, 0xfe);
tm6000_set_reg(dev, TM6010_REQ08_R1E_A_GAIN_DEEMPH_OUT, 0x13);
tm6000_set_reg(dev, TM6010_REQ08_R01_A_INIT, 0x80);
tm6000_set_reg(dev, TM6010_REQ07_RFE_POWER_DOWN, 0xff);
return 0;
}
switch (tm6010_a_mode) {
case 0:
switch (dev->norm) {
case V4L2_STD_NTSC_M_KR:
areg_05 |= 0x00;
break;
case V4L2_STD_NTSC_M_JP:
areg_05 |= 0x40;
break;
case V4L2_STD_NTSC_M:
case V4L2_STD_PAL_M:
case V4L2_STD_PAL_N:
areg_05 |= 0x20;
break;
case V4L2_STD_PAL_Nc:
areg_05 |= 0x60;
break;
case V4L2_STD_SECAM_L:
areg_05 |= 0x00;
break;
case V4L2_STD_DK:
areg_05 |= 0x10;
break;
}
break;
case 1:
switch (dev->norm) {
case V4L2_STD_B:
case V4L2_STD_GH:
areg_05 = 0x05;
break;
case V4L2_STD_DK:
areg_05 = 0x09;
break;
}
break;
case 2:
switch (dev->norm) {
case V4L2_STD_B:
case V4L2_STD_GH:
areg_05 = 0x07;
break;
case V4L2_STD_DK:
areg_05 = 0x06;
break;
case V4L2_STD_PAL_I:
areg_05 = 0x08;
break;
case V4L2_STD_SECAM_L:
areg_05 = 0x0a;
areg_02 = 0x02;
break;
}
nicam_flag = 1;
break;
case 3:
switch (dev->norm) {
case V4L2_STD_DK:
areg_05 = 0x0b;
break;
case V4L2_STD_NTSC_M_KR:
areg_05 = 0x04;
break;
case V4L2_STD_NTSC_M_JP:
areg_05 = 0x03;
break;
default:
areg_05 = 0x02;
break;
}
break;
}
tm6000_set_reg(dev, TM6010_REQ08_R01_A_INIT, 0x00);
tm6000_set_reg(dev, TM6010_REQ08_R02_A_FIX_GAIN_CTRL, areg_02);
tm6000_set_reg(dev, TM6010_REQ08_R03_A_AUTO_GAIN_CTRL, 0x00);
tm6000_set_reg(dev, TM6010_REQ08_R04_A_SIF_AMP_CTRL, 0xa0);
tm6000_set_reg(dev, TM6010_REQ08_R05_A_STANDARD_MOD, areg_05);
tm6000_set_reg(dev, TM6010_REQ08_R06_A_SOUND_MOD, areg_06);
tm6000_set_reg(dev, TM6010_REQ08_R07_A_LEFT_VOL, 0x00);
tm6000_set_reg(dev, TM6010_REQ08_R08_A_RIGHT_VOL, 0x00);
tm6000_set_reg(dev, TM6010_REQ08_R09_A_MAIN_VOL, 0x08);
tm6000_set_reg(dev, TM6010_REQ08_R0A_A_I2S_MOD, 0x91);
tm6000_set_reg(dev, TM6010_REQ08_R0B_A_ASD_THRES1, 0x20);
tm6000_set_reg(dev, TM6010_REQ08_R0C_A_ASD_THRES2, 0x12);
tm6000_set_reg(dev, TM6010_REQ08_R0D_A_AMD_THRES, 0x20);
tm6000_set_reg(dev, TM6010_REQ08_R0E_A_MONO_THRES1, 0xf0);
tm6000_set_reg(dev, TM6010_REQ08_R0F_A_MONO_THRES2, 0x80);
tm6000_set_reg(dev, TM6010_REQ08_R10_A_MUTE_THRES1, 0xc0);
tm6000_set_reg(dev, TM6010_REQ08_R11_A_MUTE_THRES2, 0x80);
tm6000_set_reg(dev, TM6010_REQ08_R12_A_AGC_U, 0x12);
tm6000_set_reg(dev, TM6010_REQ08_R13_A_AGC_ERR_T, 0xfe);
tm6000_set_reg(dev, TM6010_REQ08_R14_A_AGC_GAIN_INIT, 0x20);
tm6000_set_reg(dev, TM6010_REQ08_R15_A_AGC_STEP_THR, 0x14);
tm6000_set_reg(dev, TM6010_REQ08_R16_A_AGC_GAIN_MAX, 0xfe);
tm6000_set_reg(dev, TM6010_REQ08_R17_A_AGC_GAIN_MIN, 0x01);
tm6000_set_reg(dev, TM6010_REQ08_R18_A_TR_CTRL, 0xa0);
tm6000_set_reg(dev, TM6010_REQ08_R19_A_FH_2FH_GAIN, 0x32);
tm6000_set_reg(dev, TM6010_REQ08_R1A_A_NICAM_SER_MAX, 0x64);
tm6000_set_reg(dev, TM6010_REQ08_R1B_A_NICAM_SER_MIN, 0x20);
tm6000_set_reg(dev, REQ_08_SET_GET_AVREG_BIT, 0x1c, 0x00);
tm6000_set_reg(dev, REQ_08_SET_GET_AVREG_BIT, 0x1d, 0x00);
tm6000_set_reg(dev, TM6010_REQ08_R1E_A_GAIN_DEEMPH_OUT, 0x13);
tm6000_set_reg(dev, TM6010_REQ08_R1F_A_TEST_INTF_SEL, 0x00);
tm6000_set_reg(dev, TM6010_REQ08_R20_A_TEST_PIN_SEL, 0x00);
tm6000_set_reg(dev, TM6010_REQ08_R01_A_INIT, 0x80);
return 0;
}
void tm6000_get_std_res(struct tm6000_core *dev)
{
if (dev->norm & V4L2_STD_525_60)
dev->height = 480;
else
dev->height = 576;
dev->width = 720;
}
static int tm6000_load_std(struct tm6000_core *dev, struct tm6000_reg_settings *set)
{
int i, rc;
for (i = 0; set[i].req; i++) {
rc = tm6000_set_reg(dev, set[i].req, set[i].reg, set[i].value);
if (rc < 0) {
printk(KERN_ERR "Error %i while setting "
"req %d, reg %d to value %d\n",
rc, set[i].req, set[i].reg, set[i].value);
return rc;
}
}
return 0;
}
int tm6000_set_standard(struct tm6000_core *dev)
{
struct tm6000_input *input;
int i, rc = 0;
u8 reg_07_fe = 0x8a;
u8 reg_08_f1 = 0xfc;
u8 reg_08_e2 = 0xf0;
u8 reg_08_e6 = 0x0f;
tm6000_get_std_res(dev);
if (!dev->radio)
input = &dev->vinput[dev->input];
else
input = &dev->rinput;
if (dev->dev_type == TM6010) {
switch (input->vmux) {
case TM6000_VMUX_VIDEO_A:
tm6000_set_reg(dev, TM6010_REQ08_RE3_ADC_IN1_SEL, 0xf4);
tm6000_set_reg(dev, TM6010_REQ08_REA_BUFF_DRV_CTRL, 0xf1);
tm6000_set_reg(dev, TM6010_REQ08_REB_SIF_GAIN_CTRL, 0xe0);
tm6000_set_reg(dev, TM6010_REQ08_REC_REVERSE_YC_CTRL, 0xc2);
tm6000_set_reg(dev, TM6010_REQ08_RED_GAIN_SEL, 0xe8);
reg_07_fe |= 0x01;
break;
case TM6000_VMUX_VIDEO_B:
tm6000_set_reg(dev, TM6010_REQ08_RE3_ADC_IN1_SEL, 0xf8);
tm6000_set_reg(dev, TM6010_REQ08_REA_BUFF_DRV_CTRL, 0xf1);
tm6000_set_reg(dev, TM6010_REQ08_REB_SIF_GAIN_CTRL, 0xe0);
tm6000_set_reg(dev, TM6010_REQ08_REC_REVERSE_YC_CTRL, 0xc2);
tm6000_set_reg(dev, TM6010_REQ08_RED_GAIN_SEL, 0xe8);
reg_07_fe |= 0x01;
break;
case TM6000_VMUX_VIDEO_AB:
tm6000_set_reg(dev, TM6010_REQ08_RE3_ADC_IN1_SEL, 0xfc);
tm6000_set_reg(dev, TM6010_REQ08_RE4_ADC_IN2_SEL, 0xf8);
reg_08_e6 = 0x00;
tm6000_set_reg(dev, TM6010_REQ08_REA_BUFF_DRV_CTRL, 0xf2);
tm6000_set_reg(dev, TM6010_REQ08_REB_SIF_GAIN_CTRL, 0xf0);
tm6000_set_reg(dev, TM6010_REQ08_REC_REVERSE_YC_CTRL, 0xc2);
tm6000_set_reg(dev, TM6010_REQ08_RED_GAIN_SEL, 0xe0);
break;
default:
break;
}
switch (input->amux) {
case TM6000_AMUX_ADC1:
tm6000_set_reg_mask(dev, TM6010_REQ08_RF0_DAUDIO_INPUT_CONFIG,
0x00, 0x0f);
break;
case TM6000_AMUX_ADC2:
tm6000_set_reg_mask(dev, TM6010_REQ08_RF0_DAUDIO_INPUT_CONFIG,
0x08, 0x0f);
break;
case TM6000_AMUX_SIF1:
reg_08_e2 |= 0x02;
reg_08_e6 = 0x08;
reg_07_fe |= 0x40;
reg_08_f1 |= 0x02;
tm6000_set_reg(dev, TM6010_REQ08_RE4_ADC_IN2_SEL, 0xf3);
tm6000_set_reg_mask(dev, TM6010_REQ08_RF0_DAUDIO_INPUT_CONFIG,
0x02, 0x0f);
break;
case TM6000_AMUX_SIF2:
reg_08_e2 |= 0x02;
reg_08_e6 = 0x08;
reg_07_fe |= 0x40;
reg_08_f1 |= 0x02;
tm6000_set_reg(dev, TM6010_REQ08_RE4_ADC_IN2_SEL, 0xf7);
tm6000_set_reg_mask(dev, TM6010_REQ08_RF0_DAUDIO_INPUT_CONFIG,
0x02, 0x0f);
break;
default:
break;
}
tm6000_set_reg(dev, TM6010_REQ08_RE2_POWER_DOWN_CTRL1, reg_08_e2);
tm6000_set_reg(dev, TM6010_REQ08_RE6_POWER_DOWN_CTRL2, reg_08_e6);
tm6000_set_reg(dev, TM6010_REQ08_RF1_AADC_POWER_DOWN, reg_08_f1);
tm6000_set_reg(dev, TM6010_REQ07_RFE_POWER_DOWN, reg_07_fe);
} else {
switch (input->vmux) {
case TM6000_VMUX_VIDEO_A:
tm6000_set_reg(dev, TM6000_REQ07_RE3_VADC_INP_LPF_SEL1, 0x10);
tm6000_set_reg(dev, TM6000_REQ07_RE5_VADC_INP_LPF_SEL2, 0x00);
tm6000_set_reg(dev, TM6000_REQ07_RE8_VADC_PWDOWN_CTL, 0x0f);
tm6000_set_reg(dev,
REQ_03_SET_GET_MCU_PIN, input->v_gpio, 0);
break;
case TM6000_VMUX_VIDEO_B:
tm6000_set_reg(dev, TM6000_REQ07_RE3_VADC_INP_LPF_SEL1, 0x00);
tm6000_set_reg(dev, TM6000_REQ07_RE5_VADC_INP_LPF_SEL2, 0x00);
tm6000_set_reg(dev, TM6000_REQ07_RE8_VADC_PWDOWN_CTL, 0x0f);
tm6000_set_reg(dev,
REQ_03_SET_GET_MCU_PIN, input->v_gpio, 0);
break;
case TM6000_VMUX_VIDEO_AB:
tm6000_set_reg(dev, TM6000_REQ07_RE3_VADC_INP_LPF_SEL1, 0x10);
tm6000_set_reg(dev, TM6000_REQ07_RE5_VADC_INP_LPF_SEL2, 0x10);
tm6000_set_reg(dev, TM6000_REQ07_RE8_VADC_PWDOWN_CTL, 0x00);
tm6000_set_reg(dev,
REQ_03_SET_GET_MCU_PIN, input->v_gpio, 1);
break;
default:
break;
}
switch (input->amux) {
case TM6000_AMUX_ADC1:
tm6000_set_reg_mask(dev,
TM6000_REQ07_REB_VADC_AADC_MODE, 0x00, 0x0f);
break;
case TM6000_AMUX_ADC2:
tm6000_set_reg_mask(dev,
TM6000_REQ07_REB_VADC_AADC_MODE, 0x04, 0x0f);
break;
default:
break;
}
}
if (input->type == TM6000_INPUT_SVIDEO) {
for (i = 0; i < ARRAY_SIZE(svideo_stds); i++) {
if (dev->norm & svideo_stds[i].id) {
rc = tm6000_load_std(dev, svideo_stds[i].common);
goto ret;
}
}
return -EINVAL;
} else {
for (i = 0; i < ARRAY_SIZE(composite_stds); i++) {
if (dev->norm & composite_stds[i].id) {
rc = tm6000_load_std(dev, composite_stds[i].common);
goto ret;
}
}
return -EINVAL;
}
ret:
if (rc < 0)
return rc;
if ((dev->dev_type == TM6010) &&
((input->amux == TM6000_AMUX_SIF1) ||
(input->amux == TM6000_AMUX_SIF2)))
tm6000_set_audio_std(dev);
msleep(40);
return 0;
}
