void sti_vid_commit(struct sti_vid *vid,
struct drm_plane_state *state)
{
struct drm_crtc *crtc = state->crtc;
struct drm_display_mode *mode = &crtc->mode;
int dst_x = state->crtc_x;
int dst_y = state->crtc_y;
int dst_w = clamp_val(state->crtc_w, 0, mode->crtc_hdisplay - dst_x);
int dst_h = clamp_val(state->crtc_h, 0, mode->crtc_vdisplay - dst_y);
u32 val, ydo, xdo, yds, xds;
dst_w = ALIGN(dst_w, 2);
dst_h = ALIGN(dst_h, 2);
val = readl(vid->regs + VID_CTL);
val &= ~VID_CTL_IGNORE;
writel(val, vid->regs + VID_CTL);
ydo = sti_vtg_get_line_number(*mode, dst_y);
yds = sti_vtg_get_line_number(*mode, dst_y + dst_h - 1);
xdo = sti_vtg_get_pixel_number(*mode, dst_x);
xds = sti_vtg_get_pixel_number(*mode, dst_x + dst_w - 1);
writel((ydo << 16) | xdo, vid->regs + VID_VPO);
writel((yds << 16) | xds, vid->regs + VID_VPS);
}
void sti_vid_disable(struct sti_vid *vid)
{
u32 val;
val = readl(vid->regs + VID_CTL);
val |= VID_CTL_IGNORE;
writel(val, vid->regs + VID_CTL);
}
static void sti_vid_init(struct sti_vid *vid)
{
writel(VID_CTL_PSI_ENABLE | VID_CTL_IGNORE, vid->regs + VID_CTL);
writel(VID_ALP_OPAQUE, vid->regs + VID_ALP);
writel(VID_MPR0_BT709, vid->regs + VID_MPR0);
writel(VID_MPR1_BT709, vid->regs + VID_MPR1);
writel(VID_MPR2_BT709, vid->regs + VID_MPR2);
writel(VID_MPR3_BT709, vid->regs + VID_MPR3);
writel(VID_BC_DFLT, vid->regs + VID_BC);
writel(VID_TINT_DFLT, vid->regs + VID_TINT);
writel(VID_CSAT_DFLT, vid->regs + VID_CSAT);
}
struct sti_vid *sti_vid_create(struct device *dev, int id,
void __iomem *baseaddr)
{
struct sti_vid *vid;
vid = devm_kzalloc(dev, sizeof(*vid), GFP_KERNEL);
if (!vid) {
DRM_ERROR("Failed to allocate memory for VID\n");
return NULL;
}
vid->dev = dev;
vid->regs = baseaddr;
vid->id = id;
sti_vid_init(vid);
return vid;
}
