static void medusa_enable_bluefield_output(struct cx25821_dev *dev, int channel,
int enable)
{
u32 value = 0;
u32 tmp = 0;
int out_ctrl = OUT_CTRL1;
int out_ctrl_ns = OUT_CTRL_NS;
switch (channel) {
default:
case VDEC_A:
break;
case VDEC_B:
out_ctrl = VDEC_B_OUT_CTRL1;
out_ctrl_ns = VDEC_B_OUT_CTRL_NS;
break;
case VDEC_C:
out_ctrl = VDEC_C_OUT_CTRL1;
out_ctrl_ns = VDEC_C_OUT_CTRL_NS;
break;
case VDEC_D:
out_ctrl = VDEC_D_OUT_CTRL1;
out_ctrl_ns = VDEC_D_OUT_CTRL_NS;
break;
case VDEC_E:
out_ctrl = VDEC_E_OUT_CTRL1;
out_ctrl_ns = VDEC_E_OUT_CTRL_NS;
return;
case VDEC_F:
out_ctrl = VDEC_F_OUT_CTRL1;
out_ctrl_ns = VDEC_F_OUT_CTRL_NS;
return;
case VDEC_G:
out_ctrl = VDEC_G_OUT_CTRL1;
out_ctrl_ns = VDEC_G_OUT_CTRL_NS;
return;
case VDEC_H:
out_ctrl = VDEC_H_OUT_CTRL1;
out_ctrl_ns = VDEC_H_OUT_CTRL_NS;
return;
}
value = cx25821_i2c_read(&dev->i2c_bus[0], out_ctrl, &tmp);
value &= 0xFFFFFF7F;
if (enable)
value |= 0x00000080;
cx25821_i2c_write(&dev->i2c_bus[0], out_ctrl, value);
value = cx25821_i2c_read(&dev->i2c_bus[0], out_ctrl_ns, &tmp);
value &= 0xFFFFFF7F;
if (enable)
value |= 0x00000080;
cx25821_i2c_write(&dev->i2c_bus[0], out_ctrl_ns, value);
}
static int medusa_initialize_ntsc(struct cx25821_dev *dev)
{
int ret_val = 0;
int i = 0;
u32 value = 0;
u32 tmp = 0;
for (i = 0; i < MAX_DECODERS; i++) {
value = cx25821_i2c_read(&dev->i2c_bus[0],
MODE_CTRL + (0x200 * i), &tmp);
value &= 0xFFFFFFF0;
value |= 0x10001;
ret_val = cx25821_i2c_write(&dev->i2c_bus[0],
MODE_CTRL + (0x200 * i), value);
value = cx25821_i2c_read(&dev->i2c_bus[0],
HORIZ_TIM_CTRL + (0x200 * i), &tmp);
value &= 0x00C00C00;
value |= 0x612D0074;
ret_val = cx25821_i2c_write(&dev->i2c_bus[0],
HORIZ_TIM_CTRL + (0x200 * i), value);
value = cx25821_i2c_read(&dev->i2c_bus[0],
VERT_TIM_CTRL + (0x200 * i), &tmp);
value &= 0x00C00C00;
value |= 0x1C1E001A;
ret_val = cx25821_i2c_write(&dev->i2c_bus[0],
VERT_TIM_CTRL + (0x200 * i), value);
ret_val = cx25821_i2c_write(&dev->i2c_bus[0],
SC_STEP_SIZE + (0x200 * i), 0x43E00000);
value = cx25821_i2c_read(&dev->i2c_bus[0],
OUT_CTRL_NS + (0x200 * i), &tmp);
value &= 0xFFFBFFFF;
value |= 0x00040000;
ret_val = cx25821_i2c_write(&dev->i2c_bus[0],
OUT_CTRL_NS + (0x200 * i), value);
value = cx25821_i2c_read(&dev->i2c_bus[0],
OUT_CTRL1 + (0x200 * i), &tmp);
value &= 0xFFFBFFFF;
value |= 0x00040000;
ret_val = cx25821_i2c_write(&dev->i2c_bus[0],
OUT_CTRL1 + (0x200 * i), value);
value = cx25821_i2c_read(&dev->i2c_bus[0],
MISC_TIM_CTRL + (0x200 * i), &tmp);
value = setBitAtPos(value, 14);
value = clearBitAtPos(value, 15);
ret_val = cx25821_i2c_write(&dev->i2c_bus[0],
MISC_TIM_CTRL + (0x200 * i), value);
value = cx25821_i2c_read(&dev->i2c_bus[0],
DFE_CTRL1 + (0x200 * i), &tmp);
value = clearBitAtPos(value, 29);
ret_val = cx25821_i2c_write(&dev->i2c_bus[0],
DFE_CTRL1 + (0x200 * i), value);
medusa_enable_bluefield_output(dev, i, 1);
}
for (i = 0; i < MAX_ENCODERS; i++) {
value = cx25821_i2c_read(&dev->i2c_bus[0],
DENC_A_REG_1 + (0x100 * i), &tmp);
value &= 0xF000FC00;
value |= 0x06B402D0;
ret_val = cx25821_i2c_write(&dev->i2c_bus[0],
DENC_A_REG_1 + (0x100 * i), value);
value = cx25821_i2c_read(&dev->i2c_bus[0],
DENC_A_REG_2 + (0x100 * i), &tmp);
value &= 0xFF000000;
value |= 0x007E9054;
ret_val = cx25821_i2c_write(&dev->i2c_bus[0],
DENC_A_REG_2 + (0x100 * i), value);
value = cx25821_i2c_read(&dev->i2c_bus[0],
DENC_A_REG_3 + (0x100 * i), &tmp);
value &= 0xFC00FE00;
value |= 0x00EC00F0;
ret_val = cx25821_i2c_write(&dev->i2c_bus[0],
DENC_A_REG_3 + (0x100 * i), value);
value = cx25821_i2c_read(&dev->i2c_bus[0],
DENC_A_REG_4 + (0x100 * i), &tmp);
value &= 0x00FCFFFF;
value |= 0x13020000;
ret_val = cx25821_i2c_write(&dev->i2c_bus[0],
DENC_A_REG_4 + (0x100 * i), value);
value = cx25821_i2c_read(&dev->i2c_bus[0],
DENC_A_REG_5 + (0x100 * i), &tmp);
value &= 0xFFFF0000;
value |= 0x0000E575;
ret_val = cx25821_i2c_write(&dev->i2c_bus[0],
DENC_A_REG_5 + (0x100 * i), value);
ret_val = cx25821_i2c_write(&dev->i2c_bus[0],
DENC_A_REG_6 + (0x100 * i), 0x009A89C1);
ret_val = cx25821_i2c_write(&dev->i2c_bus[0],
DENC_A_REG_7 + (0x100 * i), 0x21F07C1F);
}
ret_val = cx25821_i2c_write(&dev->i2c_bus[0], HSCALE_CTRL, 0x0);
ret_val = cx25821_i2c_write(&dev->i2c_bus[0], VSCALE_CTRL, 0x0);
value = cx25821_i2c_read(&dev->i2c_bus[0], BYP_AB_CTRL, &tmp);
value |= 0x00080200;
ret_val = cx25821_i2c_write(&dev->i2c_bus[0], BYP_AB_CTRL, value);
return ret_val;
}
static int medusa_PALCombInit(struct cx25821_dev *dev, int dec)
{
int ret_val = -1;
u32 value = 0, tmp = 0;
ret_val = cx25821_i2c_write(&dev->i2c_bus[0],
COMB_2D_HFS_CFG + (0x200 * dec), 0x20002861);
ret_val = cx25821_i2c_write(&dev->i2c_bus[0],
COMB_2D_HFD_CFG + (0x200 * dec), 0x20002861);
ret_val = cx25821_i2c_write(&dev->i2c_bus[0],
COMB_2D_LF_CFG + (0x200 * dec), 0x200A1023);
value = cx25821_i2c_read(&dev->i2c_bus[0],
COMB_FLAT_THRESH_CTRL + (0x200 * dec), &tmp);
value &= 0x06230000;
ret_val = cx25821_i2c_write(&dev->i2c_bus[0],
COMB_FLAT_THRESH_CTRL + (0x200 * dec), value);
ret_val = cx25821_i2c_write(&dev->i2c_bus[0],
COMB_2D_BLEND + (0x200 * dec), 0x210F0F0F);
ret_val = cx25821_i2c_write(&dev->i2c_bus[0],
COMB_MISC_CTRL + (0x200 * dec), 0x41120A7F);
return ret_val;
}
static int medusa_initialize_pal(struct cx25821_dev *dev)
{
int ret_val = 0;
int i = 0;
u32 value = 0;
u32 tmp = 0;
for (i = 0; i < MAX_DECODERS; i++) {
value = cx25821_i2c_read(&dev->i2c_bus[0],
MODE_CTRL + (0x200 * i), &tmp);
value &= 0xFFFFFFF0;
value |= 0x10004;
ret_val = cx25821_i2c_write(&dev->i2c_bus[0],
MODE_CTRL + (0x200 * i), value);
value = cx25821_i2c_read(&dev->i2c_bus[0],
HORIZ_TIM_CTRL + (0x200 * i), &tmp);
value &= 0x00C00C00;
value |= 0x632D007D;
ret_val = cx25821_i2c_write(&dev->i2c_bus[0],
HORIZ_TIM_CTRL + (0x200 * i), value);
value = cx25821_i2c_read(&dev->i2c_bus[0],
VERT_TIM_CTRL + (0x200 * i), &tmp);
value &= 0x00C00C00;
value |= 0x28240026;
ret_val = cx25821_i2c_write(&dev->i2c_bus[0],
VERT_TIM_CTRL + (0x200 * i), value);
ret_val = cx25821_i2c_write(&dev->i2c_bus[0],
SC_STEP_SIZE + (0x200 * i), 0x5411E2D0);
value = cx25821_i2c_read(&dev->i2c_bus[0],
OUT_CTRL_NS + (0x200 * i), &tmp);
value &= 0xFFFBFFFF;
value |= 0x00040000;
ret_val = cx25821_i2c_write(&dev->i2c_bus[0],
OUT_CTRL_NS + (0x200 * i), value);
value = cx25821_i2c_read(&dev->i2c_bus[0],
OUT_CTRL1 + (0x200 * i), &tmp);
value &= 0xFFFBFFFF;
value |= 0x00040000;
ret_val = cx25821_i2c_write(&dev->i2c_bus[0],
OUT_CTRL1 + (0x200 * i), value);
value = cx25821_i2c_read(&dev->i2c_bus[0],
MISC_TIM_CTRL + (0x200 * i), &tmp);
value = setBitAtPos(value, 14);
value = clearBitAtPos(value, 15);
ret_val = cx25821_i2c_write(&dev->i2c_bus[0],
MISC_TIM_CTRL + (0x200 * i), value);
value = cx25821_i2c_read(&dev->i2c_bus[0],
DFE_CTRL1 + (0x200 * i), &tmp);
value = clearBitAtPos(value, 29);
ret_val = cx25821_i2c_write(&dev->i2c_bus[0],
DFE_CTRL1 + (0x200 * i), value);
medusa_PALCombInit(dev, i);
medusa_enable_bluefield_output(dev, i, 1);
}
for (i = 0; i < MAX_ENCODERS; i++) {
value = cx25821_i2c_read(&dev->i2c_bus[0],
DENC_A_REG_1 + (0x100 * i), &tmp);
value &= 0xF000FC00;
value |= 0x06C002D0;
ret_val = cx25821_i2c_write(&dev->i2c_bus[0],
DENC_A_REG_1 + (0x100 * i), value);
value = cx25821_i2c_read(&dev->i2c_bus[0],
DENC_A_REG_2 + (0x100 * i), &tmp);
value &= 0xFF000000;
value |= 0x007E9754;
ret_val = cx25821_i2c_write(&dev->i2c_bus[0],
DENC_A_REG_2 + (0x100 * i), value);
value = cx25821_i2c_read(&dev->i2c_bus[0],
DENC_A_REG_3 + (0x100 * i), &tmp);
value &= 0xFC00FE00;
value |= 0x00FC0120;
ret_val = cx25821_i2c_write(&dev->i2c_bus[0],
DENC_A_REG_3 + (0x100 * i), value);
value = cx25821_i2c_read(&dev->i2c_bus[0],
DENC_A_REG_4 + (0x100 * i), &tmp);
value &= 0x00FCFFFF;
value |= 0x14010000;
ret_val = cx25821_i2c_write(&dev->i2c_bus[0],
DENC_A_REG_4 + (0x100 * i), value);
value = cx25821_i2c_read(&dev->i2c_bus[0],
DENC_A_REG_5 + (0x100 * i), &tmp);
value &= 0xFFFF0000;
value |= 0x0000F078;
ret_val = cx25821_i2c_write(&dev->i2c_bus[0],
DENC_A_REG_5 + (0x100 * i), value);
ret_val = cx25821_i2c_write(&dev->i2c_bus[0],
DENC_A_REG_6 + (0x100 * i), 0x00A493CF);
ret_val = cx25821_i2c_write(&dev->i2c_bus[0],
DENC_A_REG_7 + (0x100 * i), 0x2A098ACB);
}
ret_val = cx25821_i2c_write(&dev->i2c_bus[0], HSCALE_CTRL, 0x0);
ret_val = cx25821_i2c_write(&dev->i2c_bus[0], VSCALE_CTRL, 0x0);
value = cx25821_i2c_read(&dev->i2c_bus[0], BYP_AB_CTRL, &tmp);
value &= 0xFFF7FDFF;
ret_val = cx25821_i2c_write(&dev->i2c_bus[0], BYP_AB_CTRL, value);
return ret_val;
}
int medusa_set_videostandard(struct cx25821_dev *dev)
{
int status = 0;
u32 value = 0, tmp = 0;
if (dev->tvnorm & V4L2_STD_PAL_BG || dev->tvnorm & V4L2_STD_PAL_DK)
status = medusa_initialize_pal(dev);
else
status = medusa_initialize_ntsc(dev);
value = cx25821_i2c_read(&dev->i2c_bus[0], DENC_A_REG_4, &tmp);
value = setBitAtPos(value, 4);
status = cx25821_i2c_write(&dev->i2c_bus[0], DENC_A_REG_4, value);
value = cx25821_i2c_read(&dev->i2c_bus[0], DENC_B_REG_4, &tmp);
value = setBitAtPos(value, 4);
status = cx25821_i2c_write(&dev->i2c_bus[0], DENC_B_REG_4, value);
return status;
}
void medusa_set_resolution(struct cx25821_dev *dev, int width,
int decoder_select)
{
int decoder = 0;
int decoder_count = 0;
u32 hscale = 0x0;
u32 vscale = 0x0;
const int MAX_WIDTH = 720;
if (width > MAX_WIDTH) {
pr_info("%s(): width %d > MAX_WIDTH %d ! resetting to MAX_WIDTH\n",
__func__, width, MAX_WIDTH);
width = MAX_WIDTH;
}
if (decoder_select <= 7 && decoder_select >= 0) {
decoder = decoder_select;
decoder_count = decoder_select + 1;
} else {
decoder = 0;
decoder_count = _num_decoders;
}
switch (width) {
case 320:
hscale = 0x13E34B;
vscale = 0x0;
break;
case 352:
hscale = 0x10A273;
vscale = 0x0;
break;
case 176:
hscale = 0x3115B2;
vscale = 0x1E00;
break;
case 160:
hscale = 0x378D84;
vscale = 0x1E00;
break;
default:
hscale = 0x0;
vscale = 0x0;
break;
}
for (; decoder < decoder_count; decoder++) {
cx25821_i2c_write(&dev->i2c_bus[0],
HSCALE_CTRL + (0x200 * decoder), hscale);
cx25821_i2c_write(&dev->i2c_bus[0],
VSCALE_CTRL + (0x200 * decoder), vscale);
}
}
static void medusa_set_decoderduration(struct cx25821_dev *dev, int decoder,
int duration)
{
u32 fld_cnt = 0;
u32 tmp = 0;
u32 disp_cnt_reg = DISP_AB_CNT;
if (decoder < VDEC_A || decoder > VDEC_H) {
return;
}
switch (decoder) {
default:
break;
case VDEC_C:
case VDEC_D:
disp_cnt_reg = DISP_CD_CNT;
break;
case VDEC_E:
case VDEC_F:
disp_cnt_reg = DISP_EF_CNT;
break;
case VDEC_G:
case VDEC_H:
disp_cnt_reg = DISP_GH_CNT;
break;
}
_display_field_cnt[decoder] = duration;
fld_cnt = cx25821_i2c_read(&dev->i2c_bus[0], disp_cnt_reg, &tmp);
if (!(decoder % 2)) {
fld_cnt &= 0xFFFF0000;
fld_cnt |= duration;
} else {
fld_cnt &= 0x0000FFFF;
fld_cnt |= ((u32) duration) << 16;
}
cx25821_i2c_write(&dev->i2c_bus[0], disp_cnt_reg, fld_cnt);
}
static int mapM(int srcMin, int srcMax, int srcVal, int dstMin, int dstMax,
int *dstVal)
{
int numerator;
int denominator;
int quotient;
if ((srcMin == srcMax) || (srcVal < srcMin) || (srcVal > srcMax))
return -1;
numerator = (srcVal - srcMin) * (dstMax - dstMin);
denominator = srcMax - srcMin;
quotient = numerator / denominator;
if (2 * (numerator % denominator) >= denominator)
quotient++;
*dstVal = quotient + dstMin;
return 0;
}
static unsigned long convert_to_twos(long numeric, unsigned long bits_len)
{
unsigned char temp;
if (numeric >= 0)
return numeric;
else {
temp = ~(abs(numeric) & 0xFF);
temp += 1;
return temp;
}
}
int medusa_set_brightness(struct cx25821_dev *dev, int brightness, int decoder)
{
int ret_val = 0;
int value = 0;
u32 val = 0, tmp = 0;
if ((brightness > VIDEO_PROCAMP_MAX) ||
(brightness < VIDEO_PROCAMP_MIN)) {
return -1;
}
ret_val = mapM(VIDEO_PROCAMP_MIN, VIDEO_PROCAMP_MAX, brightness,
SIGNED_BYTE_MIN, SIGNED_BYTE_MAX, &value);
value = convert_to_twos(value, 8);
val = cx25821_i2c_read(&dev->i2c_bus[0],
VDEC_A_BRITE_CTRL + (0x200 * decoder), &tmp);
val &= 0xFFFFFF00;
ret_val |= cx25821_i2c_write(&dev->i2c_bus[0],
VDEC_A_BRITE_CTRL + (0x200 * decoder), val | value);
return ret_val;
}
int medusa_set_contrast(struct cx25821_dev *dev, int contrast, int decoder)
{
int ret_val = 0;
int value = 0;
u32 val = 0, tmp = 0;
if ((contrast > VIDEO_PROCAMP_MAX) || (contrast < VIDEO_PROCAMP_MIN)) {
return -1;
}
ret_val = mapM(VIDEO_PROCAMP_MIN, VIDEO_PROCAMP_MAX, contrast,
UNSIGNED_BYTE_MIN, UNSIGNED_BYTE_MAX, &value);
val = cx25821_i2c_read(&dev->i2c_bus[0],
VDEC_A_CNTRST_CTRL + (0x200 * decoder), &tmp);
val &= 0xFFFFFF00;
ret_val |= cx25821_i2c_write(&dev->i2c_bus[0],
VDEC_A_CNTRST_CTRL + (0x200 * decoder), val | value);
return ret_val;
}
int medusa_set_hue(struct cx25821_dev *dev, int hue, int decoder)
{
int ret_val = 0;
int value = 0;
u32 val = 0, tmp = 0;
if ((hue > VIDEO_PROCAMP_MAX) || (hue < VIDEO_PROCAMP_MIN)) {
return -1;
}
ret_val = mapM(VIDEO_PROCAMP_MIN, VIDEO_PROCAMP_MAX, hue,
SIGNED_BYTE_MIN, SIGNED_BYTE_MAX, &value);
value = convert_to_twos(value, 8);
val = cx25821_i2c_read(&dev->i2c_bus[0],
VDEC_A_HUE_CTRL + (0x200 * decoder), &tmp);
val &= 0xFFFFFF00;
ret_val |= cx25821_i2c_write(&dev->i2c_bus[0],
VDEC_A_HUE_CTRL + (0x200 * decoder), val | value);
return ret_val;
}
int medusa_set_saturation(struct cx25821_dev *dev, int saturation, int decoder)
{
int ret_val = 0;
int value = 0;
u32 val = 0, tmp = 0;
if ((saturation > VIDEO_PROCAMP_MAX) ||
(saturation < VIDEO_PROCAMP_MIN)) {
return -1;
}
ret_val = mapM(VIDEO_PROCAMP_MIN, VIDEO_PROCAMP_MAX, saturation,
UNSIGNED_BYTE_MIN, UNSIGNED_BYTE_MAX, &value);
val = cx25821_i2c_read(&dev->i2c_bus[0],
VDEC_A_USAT_CTRL + (0x200 * decoder), &tmp);
val &= 0xFFFFFF00;
ret_val |= cx25821_i2c_write(&dev->i2c_bus[0],
VDEC_A_USAT_CTRL + (0x200 * decoder), val | value);
val = cx25821_i2c_read(&dev->i2c_bus[0],
VDEC_A_VSAT_CTRL + (0x200 * decoder), &tmp);
val &= 0xFFFFFF00;
ret_val |= cx25821_i2c_write(&dev->i2c_bus[0],
VDEC_A_VSAT_CTRL + (0x200 * decoder), val | value);
return ret_val;
}
int medusa_video_init(struct cx25821_dev *dev)
{
u32 value = 0, tmp = 0;
int ret_val = 0;
int i = 0;
_num_decoders = dev->_max_num_decoders;
value = cx25821_i2c_read(&dev->i2c_bus[0], MON_A_CTRL, &tmp);
value &= 0xFFFFF0FF;
ret_val = cx25821_i2c_write(&dev->i2c_bus[0], MON_A_CTRL, value);
if (ret_val < 0)
goto error;
value = cx25821_i2c_read(&dev->i2c_bus[0], MON_A_CTRL, &tmp);
value &= 0xFFFFFFDF;
ret_val = cx25821_i2c_write(&dev->i2c_bus[0], MON_A_CTRL, value);
if (ret_val < 0)
goto error;
for (i = 0; i < _num_decoders; i++)
medusa_set_decoderduration(dev, i, _display_field_cnt[i]);
value = cx25821_i2c_read(&dev->i2c_bus[0], DENC_AB_CTRL, &tmp);
value &= 0xFF70FF70;
value |= 0x00090008;
ret_val = cx25821_i2c_write(&dev->i2c_bus[0], DENC_AB_CTRL, value);
if (ret_val < 0)
goto error;
value = cx25821_i2c_read(&dev->i2c_bus[0], BYP_AB_CTRL, &tmp);
value |= 0x00040100;
ret_val = cx25821_i2c_write(&dev->i2c_bus[0], BYP_AB_CTRL, value);
if (ret_val < 0)
goto error;
value = cx25821_i2c_read(&dev->i2c_bus[0], AFE_AB_DIAG_CTRL, &tmp);
value &= 0x83FFFFFF;
ret_val = cx25821_i2c_write(&dev->i2c_bus[0], AFE_AB_DIAG_CTRL,
value | 0x10000000);
if (ret_val < 0)
goto error;
value = cx25821_i2c_read(&dev->i2c_bus[0], PIN_OE_CTRL, &tmp);
value &= 0xFEF0FE00;
if (_num_decoders == MAX_DECODERS) {
value |= 0x010001F8;
} else {
value |= 0x010F0108;
}
value |= 7;
ret_val = cx25821_i2c_write(&dev->i2c_bus[0], PIN_OE_CTRL, value);
if (ret_val < 0)
goto error;
ret_val = medusa_set_videostandard(dev);
error:
return ret_val;
}
