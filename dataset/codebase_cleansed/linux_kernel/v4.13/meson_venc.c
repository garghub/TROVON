static signed int to_signed(unsigned int a)
{
if (a <= 7)
return a;
else
return a - 16;
}
static unsigned long modulo(unsigned long a, unsigned long b)
{
if (a >= b)
return a - b;
else
return a;
}
bool meson_venc_hdmi_supported_vic(int vic)
{
struct meson_hdmi_venc_vic_mode *vmode = meson_hdmi_venc_vic_modes;
while (vmode->vic && vmode->mode) {
if (vmode->vic == vic)
return true;
vmode++;
}
return false;
}
static union meson_hdmi_venc_mode *meson_venc_hdmi_get_vic_vmode(int vic)
{
struct meson_hdmi_venc_vic_mode *vmode = meson_hdmi_venc_vic_modes;
while (vmode->vic && vmode->mode) {
if (vmode->vic == vic)
return vmode->mode;
vmode++;
}
return NULL;
}
bool meson_venc_hdmi_venc_repeat(int vic)
{
if (vic == 6 || vic == 7 ||
vic == 21 || vic == 22 ||
vic == 17 || vic == 18 ||
vic == 2 || vic == 3 ||
vic == 4 ||
vic == 19 ||
vic == 5 ||
vic == 20)
return true;
return false;
}
void meson_venc_hdmi_mode_set(struct meson_drm *priv, int vic,
struct drm_display_mode *mode)
{
union meson_hdmi_venc_mode *vmode = NULL;
bool use_enci = false;
bool venc_repeat = false;
bool hdmi_repeat = false;
unsigned int venc_hdmi_latency = 2;
unsigned long total_pixels_venc = 0;
unsigned long active_pixels_venc = 0;
unsigned long front_porch_venc = 0;
unsigned long hsync_pixels_venc = 0;
unsigned long de_h_begin = 0;
unsigned long de_h_end = 0;
unsigned long de_v_begin_even = 0;
unsigned long de_v_end_even = 0;
unsigned long de_v_begin_odd = 0;
unsigned long de_v_end_odd = 0;
unsigned long hs_begin = 0;
unsigned long hs_end = 0;
unsigned long vs_adjust = 0;
unsigned long vs_bline_evn = 0;
unsigned long vs_eline_evn = 0;
unsigned long vs_bline_odd = 0;
unsigned long vs_eline_odd = 0;
unsigned long vso_begin_evn = 0;
unsigned long vso_begin_odd = 0;
unsigned int eof_lines;
unsigned int sof_lines;
unsigned int vsync_lines;
vmode = meson_venc_hdmi_get_vic_vmode(vic);
if (!vmode) {
dev_err(priv->dev, "%s: Fatal Error, unsupported vic %d\n",
__func__, vic);
return;
}
if (mode->flags & DRM_MODE_FLAG_DBLCLK) {
hdmi_repeat = true;
use_enci = true;
venc_hdmi_latency = 1;
}
if (meson_venc_hdmi_venc_repeat(vic))
venc_repeat = true;
eof_lines = mode->vsync_start - mode->vdisplay;
if (mode->flags & DRM_MODE_FLAG_INTERLACE)
eof_lines /= 2;
sof_lines = mode->vtotal - mode->vsync_end;
if (mode->flags & DRM_MODE_FLAG_INTERLACE)
sof_lines /= 2;
vsync_lines = mode->vsync_end - mode->vsync_start;
if (mode->flags & DRM_MODE_FLAG_INTERLACE)
vsync_lines /= 2;
total_pixels_venc = mode->htotal;
if (hdmi_repeat)
total_pixels_venc /= 2;
if (venc_repeat)
total_pixels_venc *= 2;
active_pixels_venc = mode->hdisplay;
if (hdmi_repeat)
active_pixels_venc /= 2;
if (venc_repeat)
active_pixels_venc *= 2;
front_porch_venc = (mode->hsync_start - mode->hdisplay);
if (hdmi_repeat)
front_porch_venc /= 2;
if (venc_repeat)
front_porch_venc *= 2;
hsync_pixels_venc = (mode->hsync_end - mode->hsync_start);
if (hdmi_repeat)
hsync_pixels_venc /= 2;
if (venc_repeat)
hsync_pixels_venc *= 2;
writel_bits_relaxed(0x1f, 0x1f,
priv->io_base + _REG(VENC_VDAC_SETTING));
writel_relaxed(0, priv->io_base + _REG(ENCI_VIDEO_EN));
writel_relaxed(0, priv->io_base + _REG(ENCP_VIDEO_EN));
if (use_enci) {
unsigned int lines_f0;
unsigned int lines_f1;
writel_relaxed(0x12, priv->io_base + _REG(ENCI_CFILT_CTRL));
writel_relaxed(0x12, priv->io_base + _REG(ENCI_CFILT_CTRL2));
writel_relaxed(0, priv->io_base + _REG(VENC_DVI_SETTING));
writel_relaxed(0, priv->io_base + _REG(ENCI_VIDEO_MODE));
writel_relaxed(0, priv->io_base + _REG(ENCI_VIDEO_MODE_ADV));
writel_relaxed(vmode->enci.hso_begin,
priv->io_base + _REG(ENCI_SYNC_HSO_BEGIN));
writel_relaxed(vmode->enci.hso_end,
priv->io_base + _REG(ENCI_SYNC_HSO_END));
writel_relaxed(vmode->enci.vso_even,
priv->io_base + _REG(ENCI_SYNC_VSO_EVNLN));
writel_relaxed(vmode->enci.vso_odd,
priv->io_base + _REG(ENCI_SYNC_VSO_ODDLN));
writel_relaxed(vmode->enci.macv_max_amp,
priv->io_base + _REG(ENCI_MACV_MAX_AMP));
writel_relaxed(vmode->enci.video_prog_mode,
priv->io_base + _REG(VENC_VIDEO_PROG_MODE));
writel_relaxed(vmode->enci.video_mode,
priv->io_base + _REG(ENCI_VIDEO_MODE));
writel_relaxed(0x26, priv->io_base + _REG(ENCI_VIDEO_MODE_ADV));
writel(vmode->enci.sch_adjust,
priv->io_base + _REG(ENCI_VIDEO_SCH));
writel_relaxed(0x07, priv->io_base + _REG(ENCI_SYNC_MODE));
if (vmode->enci.yc_delay)
writel_relaxed(vmode->enci.yc_delay,
priv->io_base + _REG(ENCI_YC_DELAY));
writel_relaxed(0, priv->io_base + _REG(ENCI_DBG_PX_RST));
writel_relaxed(0x4e01, priv->io_base + _REG(ENCI_VFIFO2VD_CTL));
writel_relaxed(vmode->enci.pixel_start,
priv->io_base + _REG(ENCI_VFIFO2VD_PIXEL_START));
writel_relaxed(vmode->enci.pixel_end,
priv->io_base + _REG(ENCI_VFIFO2VD_PIXEL_END));
writel_relaxed(vmode->enci.top_field_line_start,
priv->io_base + _REG(ENCI_VFIFO2VD_LINE_TOP_START));
writel_relaxed(vmode->enci.top_field_line_end,
priv->io_base + _REG(ENCI_VFIFO2VD_LINE_TOP_END));
writel_relaxed(vmode->enci.bottom_field_line_start,
priv->io_base + _REG(ENCI_VFIFO2VD_LINE_BOT_START));
writel_relaxed(vmode->enci.bottom_field_line_end,
priv->io_base + _REG(ENCI_VFIFO2VD_LINE_BOT_END));
meson_vpp_setup_mux(priv, MESON_VIU_VPP_MUX_ENCI);
writel_relaxed(1, priv->io_base + _REG(ENCI_VIDEO_EN));
lines_f0 = mode->vtotal >> 1;
lines_f1 = lines_f0 + 1;
de_h_begin = modulo(readl_relaxed(priv->io_base +
_REG(ENCI_VFIFO2VD_PIXEL_START))
+ venc_hdmi_latency,
total_pixels_venc);
de_h_end = modulo(de_h_begin + active_pixels_venc,
total_pixels_venc);
writel_relaxed(de_h_begin,
priv->io_base + _REG(ENCI_DE_H_BEGIN));
writel_relaxed(de_h_end,
priv->io_base + _REG(ENCI_DE_H_END));
de_v_begin_even = readl_relaxed(priv->io_base +
_REG(ENCI_VFIFO2VD_LINE_TOP_START));
de_v_end_even = de_v_begin_even + mode->vdisplay;
de_v_begin_odd = readl_relaxed(priv->io_base +
_REG(ENCI_VFIFO2VD_LINE_BOT_START));
de_v_end_odd = de_v_begin_odd + mode->vdisplay;
writel_relaxed(de_v_begin_even,
priv->io_base + _REG(ENCI_DE_V_BEGIN_EVEN));
writel_relaxed(de_v_end_even,
priv->io_base + _REG(ENCI_DE_V_END_EVEN));
writel_relaxed(de_v_begin_odd,
priv->io_base + _REG(ENCI_DE_V_BEGIN_ODD));
writel_relaxed(de_v_end_odd,
priv->io_base + _REG(ENCI_DE_V_END_ODD));
hs_begin = de_h_end + front_porch_venc;
if (de_h_end + front_porch_venc >= total_pixels_venc) {
hs_begin -= total_pixels_venc;
vs_adjust = 1;
} else {
hs_begin = de_h_end + front_porch_venc;
vs_adjust = 0;
}
hs_end = modulo(hs_begin + hsync_pixels_venc,
total_pixels_venc);
writel_relaxed(hs_begin,
priv->io_base + _REG(ENCI_DVI_HSO_BEGIN));
writel_relaxed(hs_end,
priv->io_base + _REG(ENCI_DVI_HSO_END));
if (((de_v_end_odd - 1) + eof_lines + vs_adjust) >= lines_f1) {
vs_bline_evn = (de_v_end_odd - 1)
+ eof_lines
+ vs_adjust
- lines_f1;
vs_eline_evn = vs_bline_evn + vsync_lines;
writel_relaxed(vs_bline_evn,
priv->io_base + _REG(ENCI_DVI_VSO_BLINE_EVN));
writel_relaxed(vs_eline_evn,
priv->io_base + _REG(ENCI_DVI_VSO_ELINE_EVN));
writel_relaxed(hs_begin,
priv->io_base + _REG(ENCI_DVI_VSO_BEGIN_EVN));
writel_relaxed(hs_begin,
priv->io_base + _REG(ENCI_DVI_VSO_END_EVN));
} else {
vs_bline_odd = (de_v_end_odd - 1)
+ eof_lines
+ vs_adjust;
writel_relaxed(vs_bline_odd,
priv->io_base + _REG(ENCI_DVI_VSO_BLINE_ODD));
writel_relaxed(hs_begin,
priv->io_base + _REG(ENCI_DVI_VSO_BEGIN_ODD));
if ((vs_bline_odd + vsync_lines) >= lines_f1) {
vs_eline_evn = vs_bline_odd
+ vsync_lines
- lines_f1;
writel_relaxed(vs_eline_evn, priv->io_base
+ _REG(ENCI_DVI_VSO_ELINE_EVN));
writel_relaxed(hs_begin, priv->io_base
+ _REG(ENCI_DVI_VSO_END_EVN));
} else {
vs_eline_odd = vs_bline_odd
+ vsync_lines;
writel_relaxed(vs_eline_odd, priv->io_base
+ _REG(ENCI_DVI_VSO_ELINE_ODD));
writel_relaxed(hs_begin, priv->io_base
+ _REG(ENCI_DVI_VSO_END_ODD));
}
}
if (((de_v_end_even - 1) + (eof_lines + 1)) >= lines_f0) {
vs_bline_odd = (de_v_end_even - 1)
+ (eof_lines + 1)
- lines_f0;
vs_eline_odd = vs_bline_odd + vsync_lines;
writel_relaxed(vs_bline_odd,
priv->io_base + _REG(ENCI_DVI_VSO_BLINE_ODD));
writel_relaxed(vs_eline_odd,
priv->io_base + _REG(ENCI_DVI_VSO_ELINE_ODD));
vso_begin_odd = modulo(hs_begin
+ (total_pixels_venc >> 1),
total_pixels_venc);
writel_relaxed(vso_begin_odd,
priv->io_base + _REG(ENCI_DVI_VSO_BEGIN_ODD));
writel_relaxed(vso_begin_odd,
priv->io_base + _REG(ENCI_DVI_VSO_END_ODD));
} else {
vs_bline_evn = (de_v_end_even - 1)
+ (eof_lines + 1);
writel_relaxed(vs_bline_evn,
priv->io_base + _REG(ENCI_DVI_VSO_BLINE_EVN));
vso_begin_evn = modulo(hs_begin
+ (total_pixels_venc >> 1),
total_pixels_venc);
writel_relaxed(vso_begin_evn, priv->io_base
+ _REG(ENCI_DVI_VSO_BEGIN_EVN));
if (vs_bline_evn + vsync_lines >= lines_f0) {
vs_eline_odd = vs_bline_evn
+ vsync_lines
- lines_f0;
writel_relaxed(vs_eline_odd, priv->io_base
+ _REG(ENCI_DVI_VSO_ELINE_ODD));
writel_relaxed(vso_begin_evn, priv->io_base
+ _REG(ENCI_DVI_VSO_END_ODD));
} else {
vs_eline_evn = vs_bline_evn + vsync_lines;
writel_relaxed(vs_eline_evn, priv->io_base
+ _REG(ENCI_DVI_VSO_ELINE_EVN));
writel_relaxed(vso_begin_evn, priv->io_base
+ _REG(ENCI_DVI_VSO_END_EVN));
}
}
} else {
writel_relaxed(vmode->encp.dvi_settings,
priv->io_base + _REG(VENC_DVI_SETTING));
writel_relaxed(vmode->encp.video_mode,
priv->io_base + _REG(ENCP_VIDEO_MODE));
writel_relaxed(vmode->encp.video_mode_adv,
priv->io_base + _REG(ENCP_VIDEO_MODE_ADV));
if (vmode->encp.video_prog_mode_present)
writel_relaxed(vmode->encp.video_prog_mode,
priv->io_base + _REG(VENC_VIDEO_PROG_MODE));
if (vmode->encp.video_sync_mode_present)
writel_relaxed(vmode->encp.video_sync_mode,
priv->io_base + _REG(ENCP_VIDEO_SYNC_MODE));
if (vmode->encp.video_yc_dly_present)
writel_relaxed(vmode->encp.video_yc_dly,
priv->io_base + _REG(ENCP_VIDEO_YC_DLY));
if (vmode->encp.video_rgb_ctrl_present)
writel_relaxed(vmode->encp.video_rgb_ctrl,
priv->io_base + _REG(ENCP_VIDEO_RGB_CTRL));
if (vmode->encp.video_filt_ctrl_present)
writel_relaxed(vmode->encp.video_filt_ctrl,
priv->io_base + _REG(ENCP_VIDEO_FILT_CTRL));
if (vmode->encp.video_ofld_voav_ofst_present)
writel_relaxed(vmode->encp.video_ofld_voav_ofst,
priv->io_base
+ _REG(ENCP_VIDEO_OFLD_VOAV_OFST));
writel_relaxed(vmode->encp.yfp1_htime,
priv->io_base + _REG(ENCP_VIDEO_YFP1_HTIME));
writel_relaxed(vmode->encp.yfp2_htime,
priv->io_base + _REG(ENCP_VIDEO_YFP2_HTIME));
writel_relaxed(vmode->encp.max_pxcnt,
priv->io_base + _REG(ENCP_VIDEO_MAX_PXCNT));
writel_relaxed(vmode->encp.hspuls_begin,
priv->io_base + _REG(ENCP_VIDEO_HSPULS_BEGIN));
writel_relaxed(vmode->encp.hspuls_end,
priv->io_base + _REG(ENCP_VIDEO_HSPULS_END));
writel_relaxed(vmode->encp.hspuls_switch,
priv->io_base + _REG(ENCP_VIDEO_HSPULS_SWITCH));
writel_relaxed(vmode->encp.vspuls_begin,
priv->io_base + _REG(ENCP_VIDEO_VSPULS_BEGIN));
writel_relaxed(vmode->encp.vspuls_end,
priv->io_base + _REG(ENCP_VIDEO_VSPULS_END));
writel_relaxed(vmode->encp.vspuls_bline,
priv->io_base + _REG(ENCP_VIDEO_VSPULS_BLINE));
writel_relaxed(vmode->encp.vspuls_eline,
priv->io_base + _REG(ENCP_VIDEO_VSPULS_ELINE));
if (vmode->encp.eqpuls_begin_present)
writel_relaxed(vmode->encp.eqpuls_begin,
priv->io_base + _REG(ENCP_VIDEO_EQPULS_BEGIN));
if (vmode->encp.eqpuls_end_present)
writel_relaxed(vmode->encp.eqpuls_end,
priv->io_base + _REG(ENCP_VIDEO_EQPULS_END));
if (vmode->encp.eqpuls_bline_present)
writel_relaxed(vmode->encp.eqpuls_bline,
priv->io_base + _REG(ENCP_VIDEO_EQPULS_BLINE));
if (vmode->encp.eqpuls_eline_present)
writel_relaxed(vmode->encp.eqpuls_eline,
priv->io_base + _REG(ENCP_VIDEO_EQPULS_ELINE));
writel_relaxed(vmode->encp.havon_begin,
priv->io_base + _REG(ENCP_VIDEO_HAVON_BEGIN));
writel_relaxed(vmode->encp.havon_end,
priv->io_base + _REG(ENCP_VIDEO_HAVON_END));
writel_relaxed(vmode->encp.vavon_bline,
priv->io_base + _REG(ENCP_VIDEO_VAVON_BLINE));
writel_relaxed(vmode->encp.vavon_eline,
priv->io_base + _REG(ENCP_VIDEO_VAVON_ELINE));
writel_relaxed(vmode->encp.hso_begin,
priv->io_base + _REG(ENCP_VIDEO_HSO_BEGIN));
writel_relaxed(vmode->encp.hso_end,
priv->io_base + _REG(ENCP_VIDEO_HSO_END));
writel_relaxed(vmode->encp.vso_begin,
priv->io_base + _REG(ENCP_VIDEO_VSO_BEGIN));
writel_relaxed(vmode->encp.vso_end,
priv->io_base + _REG(ENCP_VIDEO_VSO_END));
writel_relaxed(vmode->encp.vso_bline,
priv->io_base + _REG(ENCP_VIDEO_VSO_BLINE));
if (vmode->encp.vso_eline_present)
writel_relaxed(vmode->encp.vso_eline,
priv->io_base + _REG(ENCP_VIDEO_VSO_ELINE));
if (vmode->encp.sy_val_present)
writel_relaxed(vmode->encp.sy_val,
priv->io_base + _REG(ENCP_VIDEO_SY_VAL));
if (vmode->encp.sy2_val_present)
writel_relaxed(vmode->encp.sy2_val,
priv->io_base + _REG(ENCP_VIDEO_SY2_VAL));
writel_relaxed(vmode->encp.max_lncnt,
priv->io_base + _REG(ENCP_VIDEO_MAX_LNCNT));
writel_relaxed(1, priv->io_base + _REG(ENCP_VIDEO_EN));
writel_bits_relaxed(BIT(14), BIT(14),
priv->io_base + _REG(ENCP_VIDEO_MODE));
de_h_begin = modulo(readl_relaxed(priv->io_base +
_REG(ENCP_VIDEO_HAVON_BEGIN))
+ venc_hdmi_latency,
total_pixels_venc);
de_h_end = modulo(de_h_begin + active_pixels_venc,
total_pixels_venc);
writel_relaxed(de_h_begin,
priv->io_base + _REG(ENCP_DE_H_BEGIN));
writel_relaxed(de_h_end,
priv->io_base + _REG(ENCP_DE_H_END));
de_v_begin_even = readl_relaxed(priv->io_base
+ _REG(ENCP_VIDEO_VAVON_BLINE));
if (mode->flags & DRM_MODE_FLAG_INTERLACE)
de_v_end_even = de_v_begin_even +
(mode->vdisplay / 2);
else
de_v_end_even = de_v_begin_even + mode->vdisplay;
writel_relaxed(de_v_begin_even,
priv->io_base + _REG(ENCP_DE_V_BEGIN_EVEN));
writel_relaxed(de_v_end_even,
priv->io_base + _REG(ENCP_DE_V_END_EVEN));
if (mode->flags & DRM_MODE_FLAG_INTERLACE) {
unsigned int ofld_voav_ofst =
readl_relaxed(priv->io_base +
_REG(ENCP_VIDEO_OFLD_VOAV_OFST));
de_v_begin_odd = to_signed((ofld_voav_ofst & 0xf0) >> 4)
+ de_v_begin_even
+ ((mode->vtotal - 1) / 2);
de_v_end_odd = de_v_begin_odd + (mode->vdisplay / 2);
writel_relaxed(de_v_begin_odd,
priv->io_base + _REG(ENCP_DE_V_BEGIN_ODD));
writel_relaxed(de_v_end_odd,
priv->io_base + _REG(ENCP_DE_V_END_ODD));
}
if ((de_h_end + front_porch_venc) >= total_pixels_venc) {
hs_begin = de_h_end
+ front_porch_venc
- total_pixels_venc;
vs_adjust = 1;
} else {
hs_begin = de_h_end
+ front_porch_venc;
vs_adjust = 0;
}
hs_end = modulo(hs_begin + hsync_pixels_venc,
total_pixels_venc);
writel_relaxed(hs_begin,
priv->io_base + _REG(ENCP_DVI_HSO_BEGIN));
writel_relaxed(hs_end,
priv->io_base + _REG(ENCP_DVI_HSO_END));
if (de_v_begin_even >=
(sof_lines + vsync_lines + (1 - vs_adjust)))
vs_bline_evn = de_v_begin_even
- sof_lines
- vsync_lines
- (1 - vs_adjust);
else
vs_bline_evn = mode->vtotal
+ de_v_begin_even
- sof_lines
- vsync_lines
- (1 - vs_adjust);
vs_eline_evn = modulo(vs_bline_evn + vsync_lines,
mode->vtotal);
writel_relaxed(vs_bline_evn,
priv->io_base + _REG(ENCP_DVI_VSO_BLINE_EVN));
writel_relaxed(vs_eline_evn,
priv->io_base + _REG(ENCP_DVI_VSO_ELINE_EVN));
vso_begin_evn = hs_begin;
writel_relaxed(vso_begin_evn,
priv->io_base + _REG(ENCP_DVI_VSO_BEGIN_EVN));
writel_relaxed(vso_begin_evn,
priv->io_base + _REG(ENCP_DVI_VSO_END_EVN));
if (mode->flags & DRM_MODE_FLAG_INTERLACE) {
vs_bline_odd = (de_v_begin_odd - 1)
- sof_lines
- vsync_lines;
vs_eline_odd = (de_v_begin_odd - 1)
- vsync_lines;
vso_begin_odd = modulo(hs_begin
+ (total_pixels_venc >> 1),
total_pixels_venc);
writel_relaxed(vs_bline_odd,
priv->io_base + _REG(ENCP_DVI_VSO_BLINE_ODD));
writel_relaxed(vs_eline_odd,
priv->io_base + _REG(ENCP_DVI_VSO_ELINE_ODD));
writel_relaxed(vso_begin_odd,
priv->io_base + _REG(ENCP_DVI_VSO_BEGIN_ODD));
writel_relaxed(vso_begin_odd,
priv->io_base + _REG(ENCP_DVI_VSO_END_ODD));
}
meson_vpp_setup_mux(priv, MESON_VIU_VPP_MUX_ENCP);
}
writel_relaxed((use_enci ? 1 : 2) |
(mode->flags & DRM_MODE_FLAG_PHSYNC ? 1 << 2 : 0) |
(mode->flags & DRM_MODE_FLAG_PVSYNC ? 1 << 3 : 0) |
4 << 5 |
(venc_repeat ? 1 << 8 : 0) |
(hdmi_repeat ? 1 << 12 : 0),
priv->io_base + _REG(VPU_HDMI_SETTING));
priv->venc.hdmi_repeat = hdmi_repeat;
priv->venc.venc_repeat = venc_repeat;
priv->venc.hdmi_use_enci = use_enci;
priv->venc.current_mode = MESON_VENC_MODE_HDMI;
}
void meson_venci_cvbs_mode_set(struct meson_drm *priv,
struct meson_cvbs_enci_mode *mode)
{
if (mode->mode_tag == priv->venc.current_mode)
return;
writel_relaxed(0x12, priv->io_base + _REG(ENCI_CFILT_CTRL));
writel_relaxed(0x12, priv->io_base + _REG(ENCI_CFILT_CTRL2));
writel_relaxed(0, priv->io_base + _REG(VENC_DVI_SETTING));
writel_relaxed(0, priv->io_base + _REG(ENCI_VIDEO_MODE));
writel_relaxed(0, priv->io_base + _REG(ENCI_VIDEO_MODE_ADV));
writel_relaxed(mode->hso_begin,
priv->io_base + _REG(ENCI_SYNC_HSO_BEGIN));
writel_relaxed(mode->hso_end,
priv->io_base + _REG(ENCI_SYNC_HSO_END));
writel_relaxed(mode->vso_even,
priv->io_base + _REG(ENCI_SYNC_VSO_EVNLN));
writel_relaxed(mode->vso_odd,
priv->io_base + _REG(ENCI_SYNC_VSO_ODDLN));
writel_relaxed(0x8100 + mode->macv_max_amp,
priv->io_base + _REG(ENCI_MACV_MAX_AMP));
writel_relaxed(mode->video_prog_mode,
priv->io_base + _REG(VENC_VIDEO_PROG_MODE));
writel_relaxed(mode->video_mode,
priv->io_base + _REG(ENCI_VIDEO_MODE));
writel_relaxed(0x26, priv->io_base + _REG(ENCI_VIDEO_MODE_ADV));
writel(mode->sch_adjust, priv->io_base + _REG(ENCI_VIDEO_SCH));
writel_relaxed(0x07, priv->io_base + _REG(ENCI_SYNC_MODE));
writel_relaxed(mode->yc_delay, priv->io_base + _REG(ENCI_YC_DELAY));
writel_relaxed(mode->pixel_start,
priv->io_base + _REG(ENCI_VFIFO2VD_PIXEL_START));
writel_relaxed(mode->pixel_end,
priv->io_base + _REG(ENCI_VFIFO2VD_PIXEL_END));
writel_relaxed(mode->top_field_line_start,
priv->io_base + _REG(ENCI_VFIFO2VD_LINE_TOP_START));
writel_relaxed(mode->top_field_line_end,
priv->io_base + _REG(ENCI_VFIFO2VD_LINE_TOP_END));
writel_relaxed(mode->bottom_field_line_start,
priv->io_base + _REG(ENCI_VFIFO2VD_LINE_BOT_START));
writel_relaxed(mode->bottom_field_line_end,
priv->io_base + _REG(ENCI_VFIFO2VD_LINE_BOT_END));
writel_relaxed(0, priv->io_base + _REG(VENC_SYNC_ROUTE));
writel_relaxed(0, priv->io_base + _REG(ENCI_DBG_PX_RST));
writel_relaxed(0x4e01, priv->io_base + _REG(ENCI_VFIFO2VD_CTL));
writel_relaxed(0, priv->io_base + _REG(VENC_VDAC_SETTING));
writel_relaxed(0x0061, priv->io_base + _REG(VENC_UPSAMPLE_CTRL0));
writel_relaxed(0x4061, priv->io_base + _REG(VENC_UPSAMPLE_CTRL1));
writel_relaxed(0x5061, priv->io_base + _REG(VENC_UPSAMPLE_CTRL2));
writel_relaxed(0, priv->io_base + _REG(VENC_VDAC_DACSEL0));
writel_relaxed(0, priv->io_base + _REG(VENC_VDAC_DACSEL1));
writel_relaxed(0, priv->io_base + _REG(VENC_VDAC_DACSEL2));
writel_relaxed(0, priv->io_base + _REG(VENC_VDAC_DACSEL3));
writel_relaxed(0, priv->io_base + _REG(VENC_VDAC_DACSEL4));
writel_relaxed(0, priv->io_base + _REG(VENC_VDAC_DACSEL5));
meson_vpp_setup_mux(priv, MESON_VIU_VPP_MUX_ENCI);
writel_relaxed(0x2000, priv->io_base + _REG(VENC_VDAC_FIFO_CTRL));
writel_relaxed(0x11, priv->io_base + _REG(ENCI_DACSEL_0));
writel_relaxed(0x11, priv->io_base + _REG(ENCI_DACSEL_1));
writel_relaxed(1, priv->io_base + _REG(ENCI_VIDEO_EN));
writel_relaxed(mode->video_saturation,
priv->io_base + _REG(ENCI_VIDEO_SAT));
writel_relaxed(mode->video_contrast,
priv->io_base + _REG(ENCI_VIDEO_CONT));
writel_relaxed(mode->video_brightness,
priv->io_base + _REG(ENCI_VIDEO_BRIGHT));
writel_relaxed(mode->video_hue,
priv->io_base + _REG(ENCI_VIDEO_HUE));
writel_relaxed(0x1, priv->io_base + _REG(VENC_VDAC_DAC0_FILT_CTRL0));
writel_relaxed(0xfc48, priv->io_base + _REG(VENC_VDAC_DAC0_FILT_CTRL1));
writel_relaxed(0, priv->io_base + _REG(ENCI_MACV_N0));
writel_relaxed(mode->analog_sync_adj,
priv->io_base + _REG(ENCI_SYNC_ADJ));
priv->venc.current_mode = mode->mode_tag;
}
unsigned int meson_venci_get_field(struct meson_drm *priv)
{
return readl_relaxed(priv->io_base + _REG(ENCI_INFO_READ)) & BIT(29);
}
void meson_venc_enable_vsync(struct meson_drm *priv)
{
writel_relaxed(2, priv->io_base + _REG(VENC_INTCTRL));
}
void meson_venc_disable_vsync(struct meson_drm *priv)
{
writel_relaxed(0, priv->io_base + _REG(VENC_INTCTRL));
}
void meson_venc_init(struct meson_drm *priv)
{
regmap_write(priv->hhi, HHI_VDAC_CNTL0, 0);
regmap_write(priv->hhi, HHI_VDAC_CNTL1, 8);
writel_relaxed(0xff, priv->io_base + _REG(VENC_VDAC_SETTING));
regmap_write(priv->hhi, HHI_HDMI_PHY_CNTL0, 0);
writel_bits_relaxed(0x3, 0,
priv->io_base + _REG(VPU_HDMI_SETTING));
writel_relaxed(0, priv->io_base + _REG(ENCI_VIDEO_EN));
writel_relaxed(0, priv->io_base + _REG(ENCP_VIDEO_EN));
writel_relaxed(0, priv->io_base + _REG(ENCL_VIDEO_EN));
meson_venc_disable_vsync(priv);
priv->venc.current_mode = MESON_VENC_MODE_NONE;
}
