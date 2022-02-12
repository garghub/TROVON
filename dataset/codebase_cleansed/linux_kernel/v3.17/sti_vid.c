static int sti_vid_prepare_layer(struct sti_layer *vid, bool first_prepare)
{
u32 val;
val = readl(vid->regs + VID_CTL);
val &= ~VID_CTL_IGNORE;
writel(val, vid->regs + VID_CTL);
return 0;
}
static int sti_vid_commit_layer(struct sti_layer *vid)
{
struct drm_display_mode *mode = vid->mode;
u32 ydo, xdo, yds, xds;
ydo = sti_vtg_get_line_number(*mode, vid->dst_y);
yds = sti_vtg_get_line_number(*mode, vid->dst_y + vid->dst_h - 1);
xdo = sti_vtg_get_pixel_number(*mode, vid->dst_x);
xds = sti_vtg_get_pixel_number(*mode, vid->dst_x + vid->dst_w - 1);
writel((ydo << 16) | xdo, vid->regs + VID_VPO);
writel((yds << 16) | xds, vid->regs + VID_VPS);
return 0;
}
static int sti_vid_disable_layer(struct sti_layer *vid)
{
u32 val;
val = readl(vid->regs + VID_CTL);
val |= VID_CTL_IGNORE;
writel(val, vid->regs + VID_CTL);
return 0;
}
static const uint32_t *sti_vid_get_formats(struct sti_layer *layer)
{
return NULL;
}
static unsigned int sti_vid_get_nb_formats(struct sti_layer *layer)
{
return 0;
}
static void sti_vid_init(struct sti_layer *vid)
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
struct sti_layer *sti_vid_create(struct device *dev)
{
struct sti_layer *vid;
vid = devm_kzalloc(dev, sizeof(*vid), GFP_KERNEL);
if (!vid) {
DRM_ERROR("Failed to allocate memory for VID\n");
return NULL;
}
vid->ops = &vid_ops;
return vid;
}
