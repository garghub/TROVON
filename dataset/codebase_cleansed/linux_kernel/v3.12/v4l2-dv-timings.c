bool v4l2_valid_dv_timings(const struct v4l2_dv_timings *t,
const struct v4l2_dv_timings_cap *dvcap,
v4l2_check_dv_timings_fnc fnc,
void *fnc_handle)
{
const struct v4l2_bt_timings *bt = &t->bt;
const struct v4l2_bt_timings_cap *cap = &dvcap->bt;
u32 caps = cap->capabilities;
if (t->type != V4L2_DV_BT_656_1120)
return false;
if (t->type != dvcap->type ||
bt->height < cap->min_height ||
bt->height > cap->max_height ||
bt->width < cap->min_width ||
bt->width > cap->max_width ||
bt->pixelclock < cap->min_pixelclock ||
bt->pixelclock > cap->max_pixelclock ||
(cap->standards && !(bt->standards & cap->standards)) ||
(bt->interlaced && !(caps & V4L2_DV_BT_CAP_INTERLACED)) ||
(!bt->interlaced && !(caps & V4L2_DV_BT_CAP_PROGRESSIVE)))
return false;
return fnc == NULL || fnc(t, fnc_handle);
}
int v4l2_enum_dv_timings_cap(struct v4l2_enum_dv_timings *t,
const struct v4l2_dv_timings_cap *cap,
v4l2_check_dv_timings_fnc fnc,
void *fnc_handle)
{
u32 i, idx;
memset(t->reserved, 0, sizeof(t->reserved));
for (i = idx = 0; v4l2_dv_timings_presets[i].bt.width; i++) {
if (v4l2_valid_dv_timings(v4l2_dv_timings_presets + i, cap,
fnc, fnc_handle) &&
idx++ == t->index) {
t->timings = v4l2_dv_timings_presets[i];
return 0;
}
}
return -EINVAL;
}
bool v4l2_find_dv_timings_cap(struct v4l2_dv_timings *t,
const struct v4l2_dv_timings_cap *cap,
unsigned pclock_delta,
v4l2_check_dv_timings_fnc fnc,
void *fnc_handle)
{
int i;
if (!v4l2_valid_dv_timings(t, cap, fnc, fnc_handle))
return false;
for (i = 0; i < v4l2_dv_timings_presets[i].bt.width; i++) {
if (v4l2_valid_dv_timings(v4l2_dv_timings_presets + i, cap,
fnc, fnc_handle) &&
v4l2_match_dv_timings(t, v4l2_dv_timings_presets + i,
pclock_delta)) {
*t = v4l2_dv_timings_presets[i];
return true;
}
}
return false;
}
bool v4l2_match_dv_timings(const struct v4l2_dv_timings *t1,
const struct v4l2_dv_timings *t2,
unsigned pclock_delta)
{
if (t1->type != t2->type || t1->type != V4L2_DV_BT_656_1120)
return false;
if (t1->bt.width == t2->bt.width &&
t1->bt.height == t2->bt.height &&
t1->bt.interlaced == t2->bt.interlaced &&
t1->bt.polarities == t2->bt.polarities &&
t1->bt.pixelclock >= t2->bt.pixelclock - pclock_delta &&
t1->bt.pixelclock <= t2->bt.pixelclock + pclock_delta &&
t1->bt.hfrontporch == t2->bt.hfrontporch &&
t1->bt.vfrontporch == t2->bt.vfrontporch &&
t1->bt.vsync == t2->bt.vsync &&
t1->bt.vbackporch == t2->bt.vbackporch &&
(!t1->bt.interlaced ||
(t1->bt.il_vfrontporch == t2->bt.il_vfrontporch &&
t1->bt.il_vsync == t2->bt.il_vsync &&
t1->bt.il_vbackporch == t2->bt.il_vbackporch)))
return true;
return false;
}
void v4l2_print_dv_timings(const char *dev_prefix, const char *prefix,
const struct v4l2_dv_timings *t, bool detailed)
{
const struct v4l2_bt_timings *bt = &t->bt;
u32 htot, vtot;
if (t->type != V4L2_DV_BT_656_1120)
return;
htot = V4L2_DV_BT_FRAME_WIDTH(bt);
vtot = V4L2_DV_BT_FRAME_HEIGHT(bt);
if (prefix == NULL)
prefix = "";
pr_info("%s: %s%ux%u%s%u (%ux%u)\n", dev_prefix, prefix,
bt->width, bt->height, bt->interlaced ? "i" : "p",
(htot * vtot) > 0 ? ((u32)bt->pixelclock / (htot * vtot)) : 0,
htot, vtot);
if (!detailed)
return;
pr_info("%s: horizontal: fp = %u, %ssync = %u, bp = %u\n",
dev_prefix, bt->hfrontporch,
(bt->polarities & V4L2_DV_HSYNC_POS_POL) ? "+" : "-",
bt->hsync, bt->hbackporch);
pr_info("%s: vertical: fp = %u, %ssync = %u, bp = %u\n",
dev_prefix, bt->vfrontporch,
(bt->polarities & V4L2_DV_VSYNC_POS_POL) ? "+" : "-",
bt->vsync, bt->vbackporch);
pr_info("%s: pixelclock: %llu\n", dev_prefix, bt->pixelclock);
pr_info("%s: flags (0x%x):%s%s%s%s\n", dev_prefix, bt->flags,
(bt->flags & V4L2_DV_FL_REDUCED_BLANKING) ?
" REDUCED_BLANKING" : "",
(bt->flags & V4L2_DV_FL_CAN_REDUCE_FPS) ?
" CAN_REDUCE_FPS" : "",
(bt->flags & V4L2_DV_FL_REDUCED_FPS) ?
" REDUCED_FPS" : "",
(bt->flags & V4L2_DV_FL_HALF_LINE) ?
" HALF_LINE" : "");
pr_info("%s: standards (0x%x):%s%s%s%s\n", dev_prefix, bt->standards,
(bt->standards & V4L2_DV_BT_STD_CEA861) ? " CEA" : "",
(bt->standards & V4L2_DV_BT_STD_DMT) ? " DMT" : "",
(bt->standards & V4L2_DV_BT_STD_CVT) ? " CVT" : "",
(bt->standards & V4L2_DV_BT_STD_GTF) ? " GTF" : "");
}
bool v4l2_detect_cvt(unsigned frame_height, unsigned hfreq, unsigned vsync,
u32 polarities, struct v4l2_dv_timings *fmt)
{
int v_fp, v_bp, h_fp, h_bp, hsync;
int frame_width, image_height, image_width;
bool reduced_blanking;
unsigned pix_clk;
if (vsync < 4 || vsync > 7)
return false;
if (polarities == V4L2_DV_VSYNC_POS_POL)
reduced_blanking = false;
else if (polarities == V4L2_DV_HSYNC_POS_POL)
reduced_blanking = true;
else
return false;
if (reduced_blanking) {
v_fp = CVT_RB_V_FPORCH;
v_bp = (CVT_RB_MIN_V_BLANK * hfreq + 1999999) / 1000000;
v_bp -= vsync + v_fp;
if (v_bp < CVT_RB_MIN_V_BPORCH)
v_bp = CVT_RB_MIN_V_BPORCH;
} else {
v_fp = CVT_MIN_V_PORCH_RND;
v_bp = (CVT_MIN_VSYNC_BP * hfreq + 1999999) / 1000000 - vsync;
if (v_bp < CVT_MIN_V_BPORCH)
v_bp = CVT_MIN_V_BPORCH;
}
image_height = (frame_height - v_fp - vsync - v_bp + 1) & ~0x1;
switch (vsync) {
case 4:
image_width = (image_height * 4) / 3;
break;
case 5:
image_width = (image_height * 16) / 9;
break;
case 6:
image_width = (image_height * 16) / 10;
break;
case 7:
if (image_height == 1024)
image_width = (image_height * 5) / 4;
else if (image_height == 768)
image_width = (image_height * 15) / 9;
else
return false;
break;
default:
return false;
}
image_width = image_width & ~7;
if (reduced_blanking) {
pix_clk = (image_width + CVT_RB_H_BLANK) * hfreq;
pix_clk = (pix_clk / CVT_PXL_CLK_GRAN) * CVT_PXL_CLK_GRAN;
h_bp = CVT_RB_H_BPORCH;
hsync = CVT_RB_H_SYNC;
h_fp = CVT_RB_H_BLANK - h_bp - hsync;
frame_width = image_width + CVT_RB_H_BLANK;
} else {
unsigned ideal_duty_cycle_per_myriad =
100 * CVT_C_PRIME - (CVT_M_PRIME * 100000) / hfreq;
int h_blank;
if (ideal_duty_cycle_per_myriad < 2000)
ideal_duty_cycle_per_myriad = 2000;
h_blank = image_width * ideal_duty_cycle_per_myriad /
(10000 - ideal_duty_cycle_per_myriad);
h_blank = (h_blank / (2 * CVT_CELL_GRAN)) * 2 * CVT_CELL_GRAN;
pix_clk = (image_width + h_blank) * hfreq;
pix_clk = (pix_clk / CVT_PXL_CLK_GRAN) * CVT_PXL_CLK_GRAN;
h_bp = h_blank / 2;
frame_width = image_width + h_blank;
hsync = (frame_width * 8 + 50) / 100;
hsync = hsync - hsync % CVT_CELL_GRAN;
h_fp = h_blank - hsync - h_bp;
}
fmt->type = V4L2_DV_BT_656_1120;
fmt->bt.polarities = polarities;
fmt->bt.width = image_width;
fmt->bt.height = image_height;
fmt->bt.hfrontporch = h_fp;
fmt->bt.vfrontporch = v_fp;
fmt->bt.hsync = hsync;
fmt->bt.vsync = vsync;
fmt->bt.hbackporch = frame_width - image_width - h_fp - hsync;
fmt->bt.vbackporch = frame_height - image_height - v_fp - vsync;
fmt->bt.pixelclock = pix_clk;
fmt->bt.standards = V4L2_DV_BT_STD_CVT;
if (reduced_blanking)
fmt->bt.flags |= V4L2_DV_FL_REDUCED_BLANKING;
return true;
}
bool v4l2_detect_gtf(unsigned frame_height,
unsigned hfreq,
unsigned vsync,
u32 polarities,
struct v4l2_fract aspect,
struct v4l2_dv_timings *fmt)
{
int pix_clk;
int v_fp, v_bp, h_fp, hsync;
int frame_width, image_height, image_width;
bool default_gtf;
int h_blank;
if (vsync != 3)
return false;
if (polarities == V4L2_DV_VSYNC_POS_POL)
default_gtf = true;
else if (polarities == V4L2_DV_HSYNC_POS_POL)
default_gtf = false;
else
return false;
v_fp = GTF_V_FP;
v_bp = (GTF_MIN_VSYNC_BP * hfreq + 999999) / 1000000 - vsync;
image_height = (frame_height - v_fp - vsync - v_bp + 1) & ~0x1;
if (aspect.numerator == 0 || aspect.denominator == 0) {
aspect.numerator = 16;
aspect.denominator = 9;
}
image_width = ((image_height * aspect.numerator) / aspect.denominator);
if (default_gtf)
h_blank = ((image_width * GTF_D_C_PRIME * hfreq) -
(image_width * GTF_D_M_PRIME * 1000) +
(hfreq * (100 - GTF_D_C_PRIME) + GTF_D_M_PRIME * 1000) / 2) /
(hfreq * (100 - GTF_D_C_PRIME) + GTF_D_M_PRIME * 1000);
else
h_blank = ((image_width * GTF_S_C_PRIME * hfreq) -
(image_width * GTF_S_M_PRIME * 1000) +
(hfreq * (100 - GTF_S_C_PRIME) + GTF_S_M_PRIME * 1000) / 2) /
(hfreq * (100 - GTF_S_C_PRIME) + GTF_S_M_PRIME * 1000);
h_blank = h_blank - h_blank % (2 * GTF_CELL_GRAN);
frame_width = image_width + h_blank;
pix_clk = (image_width + h_blank) * hfreq;
pix_clk = pix_clk / GTF_PXL_CLK_GRAN * GTF_PXL_CLK_GRAN;
hsync = (frame_width * 8 + 50) / 100;
hsync = hsync - hsync % GTF_CELL_GRAN;
h_fp = h_blank / 2 - hsync;
fmt->type = V4L2_DV_BT_656_1120;
fmt->bt.polarities = polarities;
fmt->bt.width = image_width;
fmt->bt.height = image_height;
fmt->bt.hfrontporch = h_fp;
fmt->bt.vfrontporch = v_fp;
fmt->bt.hsync = hsync;
fmt->bt.vsync = vsync;
fmt->bt.hbackporch = frame_width - image_width - h_fp - hsync;
fmt->bt.vbackporch = frame_height - image_height - v_fp - vsync;
fmt->bt.pixelclock = pix_clk;
fmt->bt.standards = V4L2_DV_BT_STD_GTF;
if (!default_gtf)
fmt->bt.flags |= V4L2_DV_FL_REDUCED_BLANKING;
return true;
}
struct v4l2_fract v4l2_calc_aspect_ratio(u8 hor_landscape, u8 vert_portrait)
{
struct v4l2_fract aspect = { 16, 9 };
u32 tmp;
u8 ratio;
if (!hor_landscape && !vert_portrait)
return aspect;
if (hor_landscape && vert_portrait) {
aspect.numerator = hor_landscape;
aspect.denominator = vert_portrait;
return aspect;
}
ratio = hor_landscape | vert_portrait;
if (ratio == 79) {
aspect.numerator = 16;
aspect.denominator = 9;
} else if (ratio == 34) {
aspect.numerator = 4;
aspect.numerator = 3;
} else if (ratio == 68) {
aspect.numerator = 15;
aspect.numerator = 9;
} else {
aspect.numerator = hor_landscape + 99;
aspect.denominator = 100;
}
if (hor_landscape)
return aspect;
tmp = aspect.denominator;
aspect.denominator = aspect.numerator;
aspect.numerator = tmp;
return aspect;
}
