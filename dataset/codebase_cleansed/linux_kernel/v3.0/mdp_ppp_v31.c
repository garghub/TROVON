static void mdp_update_scale_table(int index, int16 *c0, int16 *c1,
int16 *c2, int16 *c3)
{
int i, val;
for (i = 0; i < MDP_SCALE_COEFF_NUM; i++) {
val =
((MDP_SCALE_COEFF_MASK & c1[i]) << 16) |
(MDP_SCALE_COEFF_MASK & c0[i]);
MDP_OUTP(MDP_PPP_SCALE_COEFF_LSBn(index), val);
val =
((MDP_SCALE_COEFF_MASK & c3[i]) << 16) |
(MDP_SCALE_COEFF_MASK & c2[i]);
MDP_OUTP(MDP_PPP_SCALE_COEFF_MSBn(index), val);
index++;
}
}
void mdp_init_scale_table(void)
{
mdp_scale_0p2_to_0p4_mode = MDP_SCALE_FIR;
mdp_update_scale_table(MDP_SCALE_0P2_TO_0P4_INDEX,
mdp_scale_0p2_to_0p4_C0,
mdp_scale_0p2_to_0p4_C1,
mdp_scale_0p2_to_0p4_C2,
mdp_scale_0p2_to_0p4_C3);
mdp_scale_0p4_to_0p6_mode = MDP_SCALE_FIR;
mdp_update_scale_table(MDP_SCALE_0P4_TO_0P6_INDEX,
mdp_scale_0p4_to_0p6_C0,
mdp_scale_0p4_to_0p6_C1,
mdp_scale_0p4_to_0p6_C2,
mdp_scale_0p4_to_0p6_C3);
mdp_scale_0p6_to_0p8_mode = MDP_SCALE_FIR;
mdp_update_scale_table(MDP_SCALE_0P6_TO_0P8_INDEX,
mdp_scale_0p6_to_0p8_C0,
mdp_scale_0p6_to_0p8_C1,
mdp_scale_0p6_to_0p8_C2,
mdp_scale_0p6_to_0p8_C3);
mdp_scale_0p8_to_8p0_mode = MDP_SCALE_FIR;
mdp_update_scale_table(MDP_SCALE_0P8_TO_8P0_INDEX,
mdp_scale_0p8_to_8p0_C0,
mdp_scale_0p8_to_8p0_C1,
mdp_scale_0p8_to_8p0_C2,
mdp_scale_0p8_to_8p0_C3);
}
static long long mdp_do_div(long long num, long long den)
{
do_div(num, den);
return num;
}
static void mdp_calc_scaleInitPhase_3p1(uint32 in_w,
uint32 in_h,
uint32 out_w,
uint32 out_h,
boolean is_rotate,
boolean is_pp_x,
boolean is_pp_y, struct phase_val *pval)
{
uint64 dst_ROI_width;
uint64 dst_ROI_height;
uint64 src_ROI_width;
uint64 src_ROI_height;
uint32 phase_step_x = 0;
uint32 phase_step_y = 0;
uint32 phase_init_x = 0;
uint32 phase_init_y = 0;
uint32 yscale_filter_sel, xscale_filter_sel;
uint32 scale_unit_sel_x, scale_unit_sel_y;
uint64 numerator, denominator;
uint64 temp_dim;
src_ROI_width = in_w;
src_ROI_height = in_h;
dst_ROI_width = out_w;
dst_ROI_height = out_h;
if (is_rotate) {
if (src_ROI_width > (4 * dst_ROI_height))
scale_unit_sel_x = 1;
else
scale_unit_sel_x = 0;
if (src_ROI_height > (4 * dst_ROI_width))
scale_unit_sel_y = 1;
else
scale_unit_sel_y = 0;
} else {
if (src_ROI_width > (4 * dst_ROI_width))
scale_unit_sel_x = 1;
else
scale_unit_sel_x = 0;
if (src_ROI_height > (4 * dst_ROI_height))
scale_unit_sel_y = 1;
else
scale_unit_sel_y = 0;
}
if (is_rotate) {
temp_dim = dst_ROI_width;
dst_ROI_width = dst_ROI_height;
dst_ROI_height = temp_dim;
}
if (dst_ROI_width == 1)
phase_step_x = (uint32) ((src_ROI_width) << SCALER_PHASE_BITS);
else if (scale_unit_sel_x == 0) {
numerator = (src_ROI_width - 1) << SCALER_PHASE_BITS;
denominator = (dst_ROI_width - 1);
phase_step_x = (uint32) mdp_do_div((numerator + denominator - 1), denominator);
}
else if (scale_unit_sel_x == 1) {
numerator = (src_ROI_width) << SCALER_PHASE_BITS;
denominator = (dst_ROI_width);
phase_step_x = (uint32) mdp_do_div(numerator, denominator);
}
if (dst_ROI_height == 1)
phase_step_y = (uint32) ((src_ROI_height) << SCALER_PHASE_BITS);
else if (scale_unit_sel_y == 0) {
numerator = (src_ROI_height - 1) << SCALER_PHASE_BITS;
denominator = (dst_ROI_height - 1);
phase_step_y = (uint32) mdp_do_div((numerator + denominator - 1), denominator);
}
else if (scale_unit_sel_y == 1) {
numerator = (src_ROI_height) << SCALER_PHASE_BITS;
denominator = (dst_ROI_height);
phase_step_y = (uint32) mdp_do_div(numerator, denominator);
}
if (phase_step_x > HAL_MDP_PHASE_STEP_2P50)
xscale_filter_sel = 0;
else if (phase_step_x > HAL_MDP_PHASE_STEP_1P66)
xscale_filter_sel = 1;
else if (phase_step_x > HAL_MDP_PHASE_STEP_1P25)
xscale_filter_sel = 2;
else
xscale_filter_sel = 3;
if (phase_step_y > HAL_MDP_PHASE_STEP_2P50)
yscale_filter_sel = 0;
else if (phase_step_y > HAL_MDP_PHASE_STEP_1P66)
yscale_filter_sel = 1;
else if (phase_step_y > HAL_MDP_PHASE_STEP_1P25)
yscale_filter_sel = 2;
else
yscale_filter_sel = 3;
if (scale_unit_sel_x == 0) {
if (dst_ROI_width == 1)
phase_init_x =
(uint32) ((src_ROI_width - 1) << SCALER_PHASE_BITS);
else
phase_init_x = 0;
}
else if (scale_unit_sel_x == 1)
phase_init_x = 0;
if (scale_unit_sel_y == 0) {
if (dst_ROI_height == 1)
phase_init_y =
(uint32) ((src_ROI_height -
1) << SCALER_PHASE_BITS);
else
phase_init_y = 0;
}
else if (scale_unit_sel_y == 1)
phase_init_y = 0;
pval->phase_step_x = (uint32) phase_step_x;
pval->phase_step_y = (uint32) phase_step_y;
pval->phase_init_x = (uint32) phase_init_x;
pval->phase_init_y = (uint32) phase_init_y;
return;
}
void mdp_set_scale(MDPIBUF *iBuf,
uint32 dst_roi_width,
uint32 dst_roi_height,
boolean inputRGB, boolean outputRGB, uint32 *pppop_reg_ptr)
{
uint32 dst_roi_width_scale;
uint32 dst_roi_height_scale;
struct phase_val pval;
boolean use_pr;
uint32 ppp_scale_config = 0;
if (!inputRGB)
ppp_scale_config |= BIT(6);
if (iBuf->mdpImg.mdpOp & MDPOP_ASCALE) {
if (iBuf->mdpImg.mdpOp & MDPOP_ROT90) {
dst_roi_width_scale = dst_roi_height;
dst_roi_height_scale = dst_roi_width;
} else {
dst_roi_width_scale = dst_roi_width;
dst_roi_height_scale = dst_roi_height;
}
if ((dst_roi_width_scale != iBuf->roi.width) ||
(dst_roi_height_scale != iBuf->roi.height) ||
(iBuf->mdpImg.mdpOp & MDPOP_SHARPENING)) {
*pppop_reg_ptr |=
(PPP_OP_SCALE_Y_ON | PPP_OP_SCALE_X_ON);
mdp_calc_scaleInitPhase_3p1(iBuf->roi.width,
iBuf->roi.height,
dst_roi_width,
dst_roi_height,
iBuf->mdpImg.
mdpOp & MDPOP_ROT90, 1, 1,
&pval);
MDP_OUTP(MDP_CMD_DEBUG_ACCESS_BASE + 0x013c,
pval.phase_init_x);
MDP_OUTP(MDP_CMD_DEBUG_ACCESS_BASE + 0x0140,
pval.phase_init_y);
MDP_OUTP(MDP_CMD_DEBUG_ACCESS_BASE + 0x0144,
pval.phase_step_x);
MDP_OUTP(MDP_CMD_DEBUG_ACCESS_BASE + 0x0148,
pval.phase_step_y);
use_pr = (inputRGB) && (outputRGB);
if ((dst_roi_width_scale == iBuf->roi.width) &&
!(iBuf->mdpImg.mdpOp & MDPOP_SHARPENING)) {
*pppop_reg_ptr &= ~PPP_OP_SCALE_X_ON;
} else
if (((dst_roi_width_scale * 10) / iBuf->roi.width) >
8) {
if ((use_pr)
&& (mdp_scale_0p8_to_8p0_mode !=
MDP_SCALE_PR)) {
mdp_scale_0p8_to_8p0_mode =
MDP_SCALE_PR;
mdp_update_scale_table
(MDP_SCALE_0P8_TO_8P0_INDEX,
mdp_scale_pixel_repeat_C0,
mdp_scale_pixel_repeat_C1,
mdp_scale_pixel_repeat_C2,
mdp_scale_pixel_repeat_C3);
} else if ((!use_pr)
&& (mdp_scale_0p8_to_8p0_mode !=
MDP_SCALE_FIR)) {
mdp_scale_0p8_to_8p0_mode =
MDP_SCALE_FIR;
mdp_update_scale_table
(MDP_SCALE_0P8_TO_8P0_INDEX,
mdp_scale_0p8_to_8p0_C0,
mdp_scale_0p8_to_8p0_C1,
mdp_scale_0p8_to_8p0_C2,
mdp_scale_0p8_to_8p0_C3);
}
ppp_scale_config |= (SCALE_U1_SET << 2);
} else
if (((dst_roi_width_scale * 10) / iBuf->roi.width) >
6) {
if ((use_pr)
&& (mdp_scale_0p6_to_0p8_mode !=
MDP_SCALE_PR)) {
mdp_scale_0p6_to_0p8_mode =
MDP_SCALE_PR;
mdp_update_scale_table
(MDP_SCALE_0P6_TO_0P8_INDEX,
mdp_scale_pixel_repeat_C0,
mdp_scale_pixel_repeat_C1,
mdp_scale_pixel_repeat_C2,
mdp_scale_pixel_repeat_C3);
} else if ((!use_pr)
&& (mdp_scale_0p6_to_0p8_mode !=
MDP_SCALE_FIR)) {
mdp_scale_0p6_to_0p8_mode =
MDP_SCALE_FIR;
mdp_update_scale_table
(MDP_SCALE_0P6_TO_0P8_INDEX,
mdp_scale_0p6_to_0p8_C0,
mdp_scale_0p6_to_0p8_C1,
mdp_scale_0p6_to_0p8_C2,
mdp_scale_0p6_to_0p8_C3);
}
ppp_scale_config |= (SCALE_D2_SET << 2);
} else
if (((dst_roi_width_scale * 10) / iBuf->roi.width) >
4) {
if ((use_pr)
&& (mdp_scale_0p4_to_0p6_mode !=
MDP_SCALE_PR)) {
mdp_scale_0p4_to_0p6_mode =
MDP_SCALE_PR;
mdp_update_scale_table
(MDP_SCALE_0P4_TO_0P6_INDEX,
mdp_scale_pixel_repeat_C0,
mdp_scale_pixel_repeat_C1,
mdp_scale_pixel_repeat_C2,
mdp_scale_pixel_repeat_C3);
} else if ((!use_pr)
&& (mdp_scale_0p4_to_0p6_mode !=
MDP_SCALE_FIR)) {
mdp_scale_0p4_to_0p6_mode =
MDP_SCALE_FIR;
mdp_update_scale_table
(MDP_SCALE_0P4_TO_0P6_INDEX,
mdp_scale_0p4_to_0p6_C0,
mdp_scale_0p4_to_0p6_C1,
mdp_scale_0p4_to_0p6_C2,
mdp_scale_0p4_to_0p6_C3);
}
ppp_scale_config |= (SCALE_D1_SET << 2);
} else
if (((dst_roi_width_scale * 4) / iBuf->roi.width) >=
1) {
if ((use_pr)
&& (mdp_scale_0p2_to_0p4_mode !=
MDP_SCALE_PR)) {
mdp_scale_0p2_to_0p4_mode =
MDP_SCALE_PR;
mdp_update_scale_table
(MDP_SCALE_0P2_TO_0P4_INDEX,
mdp_scale_pixel_repeat_C0,
mdp_scale_pixel_repeat_C1,
mdp_scale_pixel_repeat_C2,
mdp_scale_pixel_repeat_C3);
} else if ((!use_pr)
&& (mdp_scale_0p2_to_0p4_mode !=
MDP_SCALE_FIR)) {
mdp_scale_0p2_to_0p4_mode =
MDP_SCALE_FIR;
mdp_update_scale_table
(MDP_SCALE_0P2_TO_0P4_INDEX,
mdp_scale_0p2_to_0p4_C0,
mdp_scale_0p2_to_0p4_C1,
mdp_scale_0p2_to_0p4_C2,
mdp_scale_0p2_to_0p4_C3);
}
ppp_scale_config |= (SCALE_D0_SET << 2);
} else
ppp_scale_config |= BIT(0);
if ((dst_roi_height_scale == iBuf->roi.height) &&
!(iBuf->mdpImg.mdpOp & MDPOP_SHARPENING)) {
*pppop_reg_ptr &= ~PPP_OP_SCALE_Y_ON;
} else if (((dst_roi_height_scale * 10) /
iBuf->roi.height) > 8) {
if ((use_pr)
&& (mdp_scale_0p8_to_8p0_mode !=
MDP_SCALE_PR)) {
mdp_scale_0p8_to_8p0_mode =
MDP_SCALE_PR;
mdp_update_scale_table
(MDP_SCALE_0P8_TO_8P0_INDEX,
mdp_scale_pixel_repeat_C0,
mdp_scale_pixel_repeat_C1,
mdp_scale_pixel_repeat_C2,
mdp_scale_pixel_repeat_C3);
} else if ((!use_pr)
&& (mdp_scale_0p8_to_8p0_mode !=
MDP_SCALE_FIR)) {
mdp_scale_0p8_to_8p0_mode =
MDP_SCALE_FIR;
mdp_update_scale_table
(MDP_SCALE_0P8_TO_8P0_INDEX,
mdp_scale_0p8_to_8p0_C0,
mdp_scale_0p8_to_8p0_C1,
mdp_scale_0p8_to_8p0_C2,
mdp_scale_0p8_to_8p0_C3);
}
ppp_scale_config |= (SCALE_U1_SET << 4);
} else
if (((dst_roi_height_scale * 10) /
iBuf->roi.height) > 6) {
if ((use_pr)
&& (mdp_scale_0p6_to_0p8_mode !=
MDP_SCALE_PR)) {
mdp_scale_0p6_to_0p8_mode =
MDP_SCALE_PR;
mdp_update_scale_table
(MDP_SCALE_0P6_TO_0P8_INDEX,
mdp_scale_pixel_repeat_C0,
mdp_scale_pixel_repeat_C1,
mdp_scale_pixel_repeat_C2,
mdp_scale_pixel_repeat_C3);
} else if ((!use_pr)
&& (mdp_scale_0p6_to_0p8_mode !=
MDP_SCALE_FIR)) {
mdp_scale_0p6_to_0p8_mode =
MDP_SCALE_FIR;
mdp_update_scale_table
(MDP_SCALE_0P6_TO_0P8_INDEX,
mdp_scale_0p6_to_0p8_C0,
mdp_scale_0p6_to_0p8_C1,
mdp_scale_0p6_to_0p8_C2,
mdp_scale_0p6_to_0p8_C3);
}
ppp_scale_config |= (SCALE_D2_SET << 4);
} else
if (((dst_roi_height_scale * 10) /
iBuf->roi.height) > 4) {
if ((use_pr)
&& (mdp_scale_0p4_to_0p6_mode !=
MDP_SCALE_PR)) {
mdp_scale_0p4_to_0p6_mode =
MDP_SCALE_PR;
mdp_update_scale_table
(MDP_SCALE_0P4_TO_0P6_INDEX,
mdp_scale_pixel_repeat_C0,
mdp_scale_pixel_repeat_C1,
mdp_scale_pixel_repeat_C2,
mdp_scale_pixel_repeat_C3);
} else if ((!use_pr)
&& (mdp_scale_0p4_to_0p6_mode !=
MDP_SCALE_FIR)) {
mdp_scale_0p4_to_0p6_mode =
MDP_SCALE_FIR;
mdp_update_scale_table
(MDP_SCALE_0P4_TO_0P6_INDEX,
mdp_scale_0p4_to_0p6_C0,
mdp_scale_0p4_to_0p6_C1,
mdp_scale_0p4_to_0p6_C2,
mdp_scale_0p4_to_0p6_C3);
}
ppp_scale_config |= (SCALE_D1_SET << 4);
} else
if (((dst_roi_height_scale * 4) /
iBuf->roi.height) >= 1) {
if ((use_pr)
&& (mdp_scale_0p2_to_0p4_mode !=
MDP_SCALE_PR)) {
mdp_scale_0p2_to_0p4_mode =
MDP_SCALE_PR;
mdp_update_scale_table
(MDP_SCALE_0P2_TO_0P4_INDEX,
mdp_scale_pixel_repeat_C0,
mdp_scale_pixel_repeat_C1,
mdp_scale_pixel_repeat_C2,
mdp_scale_pixel_repeat_C3);
} else if ((!use_pr)
&& (mdp_scale_0p2_to_0p4_mode !=
MDP_SCALE_FIR)) {
mdp_scale_0p2_to_0p4_mode =
MDP_SCALE_FIR;
mdp_update_scale_table
(MDP_SCALE_0P2_TO_0P4_INDEX,
mdp_scale_0p2_to_0p4_C0,
mdp_scale_0p2_to_0p4_C1,
mdp_scale_0p2_to_0p4_C2,
mdp_scale_0p2_to_0p4_C3);
}
ppp_scale_config |= (SCALE_D0_SET << 4);
} else
ppp_scale_config |= BIT(1);
if (iBuf->mdpImg.mdpOp & MDPOP_SHARPENING) {
ppp_scale_config |= BIT(7);
MDP_OUTP(MDP_BASE + 0x50020,
iBuf->mdpImg.sp_value);
}
MDP_OUTP(MDP_BASE + 0x10230, ppp_scale_config);
} else {
iBuf->mdpImg.mdpOp &= ~(MDPOP_ASCALE);
}
}
}
void mdp_adjust_start_addr(uint8 **src0,
uint8 **src1,
int v_slice,
int h_slice,
int x,
int y,
uint32 width,
uint32 height, int bpp, MDPIBUF *iBuf, int layer)
{
switch (layer) {
case 0:
MDP_OUTP(MDP_CMD_DEBUG_ACCESS_BASE + 0x0200, (y << 16) | (x));
MDP_OUTP(MDP_CMD_DEBUG_ACCESS_BASE + 0x0208,
(height << 16) | (width));
break;
case 1:
if (iBuf->ibuf_type == MDP_YCRYCB_H2V1) {
*src0 += (x + y * width) * bpp;
x = y = 0;
width = iBuf->roi.dst_width;
height = iBuf->roi.dst_height;
}
MDP_OUTP(MDP_CMD_DEBUG_ACCESS_BASE + 0x0204, (y << 16) | (x));
MDP_OUTP(MDP_CMD_DEBUG_ACCESS_BASE + 0x020c,
(height << 16) | (width));
break;
case 2:
MDP_OUTP(MDP_CMD_DEBUG_ACCESS_BASE + 0x019c, (y << 16) | (x));
break;
}
}
void mdp_set_blend_attr(MDPIBUF *iBuf,
uint32 *alpha,
uint32 *tpVal,
uint32 perPixelAlpha, uint32 *pppop_reg_ptr)
{
int bg_alpha;
*alpha = iBuf->mdpImg.alpha;
*tpVal = iBuf->mdpImg.tpVal;
if (iBuf->mdpImg.mdpOp & MDPOP_FG_PM_ALPHA) {
*pppop_reg_ptr |= PPP_OP_ROT_ON |
PPP_OP_BLEND_ON | PPP_OP_BLEND_CONSTANT_ALPHA;
bg_alpha = PPP_BLEND_BG_USE_ALPHA_SEL |
PPP_BLEND_BG_ALPHA_REVERSE;
if (perPixelAlpha)
bg_alpha |= PPP_BLEND_BG_SRCPIXEL_ALPHA;
else
bg_alpha |= PPP_BLEND_BG_CONSTANT_ALPHA;
outpdw(MDP_BASE + 0x70010, bg_alpha);
if (iBuf->mdpImg.mdpOp & MDPOP_TRANSP)
*pppop_reg_ptr |= PPP_BLEND_CALPHA_TRNASP;
} else if (perPixelAlpha) {
*pppop_reg_ptr |= PPP_OP_ROT_ON |
PPP_OP_BLEND_ON | PPP_OP_BLEND_SRCPIXEL_ALPHA;
} else {
if ((iBuf->mdpImg.mdpOp & MDPOP_ALPHAB)
&& (iBuf->mdpImg.alpha == 0xff)) {
iBuf->mdpImg.mdpOp &= ~(MDPOP_ALPHAB);
}
if ((iBuf->mdpImg.mdpOp & MDPOP_ALPHAB)
|| (iBuf->mdpImg.mdpOp & MDPOP_TRANSP)) {
*pppop_reg_ptr |=
PPP_OP_ROT_ON | PPP_OP_BLEND_ON |
PPP_OP_BLEND_CONSTANT_ALPHA |
PPP_OP_BLEND_ALPHA_BLEND_NORMAL;
}
if (iBuf->mdpImg.mdpOp & MDPOP_TRANSP)
*pppop_reg_ptr |= PPP_BLEND_CALPHA_TRNASP;
}
}
