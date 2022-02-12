static void vtg_register(struct sti_vtg *vtg)
{
list_add_tail(&vtg->link, &vtg_lookup);
}
struct sti_vtg *of_vtg_find(struct device_node *np)
{
struct sti_vtg *vtg;
list_for_each_entry(vtg, &vtg_lookup, link) {
if (vtg->np == np)
return vtg;
}
return NULL;
}
static void vtg_reset(struct sti_vtg *vtg)
{
if (vtg->slave)
vtg_reset(vtg->slave);
writel(1, vtg->regs + VTG_DRST_AUTOC);
}
static void vtg_set_output_window(void __iomem *regs,
const struct drm_display_mode *mode)
{
u32 video_top_field_start;
u32 video_top_field_stop;
u32 video_bottom_field_start;
u32 video_bottom_field_stop;
u32 xstart = sti_vtg_get_pixel_number(*mode, 0);
u32 ystart = sti_vtg_get_line_number(*mode, 0);
u32 xstop = sti_vtg_get_pixel_number(*mode, mode->hdisplay - 1);
u32 ystop = sti_vtg_get_line_number(*mode, mode->vdisplay - 1);
video_top_field_start = (ystart << 16) | xstart;
video_top_field_stop = (ystop << 16) | xstop;
video_bottom_field_start = video_top_field_start;
video_bottom_field_stop = video_top_field_stop;
writel(video_top_field_start, regs + VTG_VID_TFO);
writel(video_top_field_stop, regs + VTG_VID_TFS);
writel(video_bottom_field_start, regs + VTG_VID_BFO);
writel(video_bottom_field_stop, regs + VTG_VID_BFS);
}
static void vtg_set_mode(struct sti_vtg *vtg,
int type, const struct drm_display_mode *mode)
{
u32 tmp;
if (vtg->slave)
vtg_set_mode(vtg->slave, VTG_TYPE_SLAVE_BY_EXT0, mode);
writel(mode->htotal, vtg->regs + VTG_CLKLN);
writel(mode->vtotal * 2, vtg->regs + VTG_HLFLN);
vtg_set_output_window(vtg->regs, mode);
tmp = (mode->hsync_end - mode->hsync_start + HDMI_DELAY) << 16;
tmp |= HDMI_DELAY;
writel(tmp, vtg->regs + VTG_H_HD_1);
tmp = (mode->vsync_end - mode->vsync_start + 1) << 16;
tmp |= 1;
writel(tmp, vtg->regs + VTG_TOP_V_VD_1);
writel(tmp, vtg->regs + VTG_BOT_V_VD_1);
tmp = HDMI_DELAY << 16;
tmp |= HDMI_DELAY;
writel(tmp, vtg->regs + VTG_TOP_V_HD_1);
writel(tmp, vtg->regs + VTG_BOT_V_HD_1);
tmp = (mode->hsync_end - mode->hsync_start) << 16;
writel(tmp, vtg->regs + VTG_H_HD_2);
tmp = (mode->vsync_end - mode->vsync_start + 1) << 16;
tmp |= 1;
writel(tmp, vtg->regs + VTG_TOP_V_VD_2);
writel(tmp, vtg->regs + VTG_BOT_V_VD_2);
writel(0, vtg->regs + VTG_TOP_V_HD_2);
writel(0, vtg->regs + VTG_BOT_V_HD_2);
tmp = (mode->hsync_end - mode->hsync_start + AWG_DELAY_HD) << 16;
tmp |= mode->htotal + AWG_DELAY_HD;
writel(tmp, vtg->regs + VTG_H_HD_3);
tmp = (mode->vsync_end - mode->vsync_start) << 16;
tmp |= mode->vtotal;
writel(tmp, vtg->regs + VTG_TOP_V_VD_3);
writel(tmp, vtg->regs + VTG_BOT_V_VD_3);
tmp = (mode->htotal + AWG_DELAY_HD) << 16;
tmp |= mode->htotal + AWG_DELAY_HD;
writel(tmp, vtg->regs + VTG_TOP_V_HD_3);
writel(tmp, vtg->regs + VTG_BOT_V_HD_3);
tmp = (mode->hsync_end - mode->hsync_start) << 16;
writel(tmp, vtg->regs + VTG_H_HD_4);
tmp = (mode->vsync_end - mode->vsync_start + 1) << 16;
tmp |= 1;
writel(tmp, vtg->regs + VTG_TOP_V_VD_4);
writel(tmp, vtg->regs + VTG_BOT_V_VD_4);
writel(0, vtg->regs + VTG_TOP_V_HD_4);
writel(0, vtg->regs + VTG_BOT_V_HD_4);
writel(type, vtg->regs + VTG_MODE);
}
static void vtg_enable_irq(struct sti_vtg *vtg)
{
writel(0xFFFF, vtg->regs + VTG_HOST_ITS_BCLR);
writel(0xFFFF, vtg->regs + VTG_HOST_ITM_BCLR);
writel(VTG_IRQ_MASK, vtg->regs + VTG_HOST_ITM_BSET);
}
void sti_vtg_set_config(struct sti_vtg *vtg,
const struct drm_display_mode *mode)
{
vtg_set_mode(vtg, VTG_TYPE_MASTER, mode);
vtg_reset(vtg);
if (vtg->slave)
vtg_enable_irq(vtg->slave);
else
vtg_enable_irq(vtg);
}
u32 sti_vtg_get_line_number(struct drm_display_mode mode, int y)
{
u32 start_line = mode.vtotal - mode.vsync_start + 1;
if (mode.flags & DRM_MODE_FLAG_INTERLACE)
start_line *= 2;
return start_line + y;
}
u32 sti_vtg_get_pixel_number(struct drm_display_mode mode, int x)
{
return mode.htotal - mode.hsync_start + x;
}
int sti_vtg_register_client(struct sti_vtg *vtg,
struct notifier_block *nb, int crtc_id)
{
if (vtg->slave)
return sti_vtg_register_client(vtg->slave, nb, crtc_id);
vtg->crtc_id = crtc_id;
return raw_notifier_chain_register(&vtg->notifier_list, nb);
}
int sti_vtg_unregister_client(struct sti_vtg *vtg, struct notifier_block *nb)
{
if (vtg->slave)
return sti_vtg_unregister_client(vtg->slave, nb);
return raw_notifier_chain_unregister(&vtg->notifier_list, nb);
}
static irqreturn_t vtg_irq_thread(int irq, void *arg)
{
struct sti_vtg *vtg = arg;
u32 event;
event = (vtg->irq_status & VTG_IRQ_TOP) ?
VTG_TOP_FIELD_EVENT : VTG_BOTTOM_FIELD_EVENT;
raw_notifier_call_chain(&vtg->notifier_list, event, &vtg->crtc_id);
return IRQ_HANDLED;
}
static irqreturn_t vtg_irq(int irq, void *arg)
{
struct sti_vtg *vtg = arg;
vtg->irq_status = readl(vtg->regs + VTG_HOST_ITS);
writel(vtg->irq_status, vtg->regs + VTG_HOST_ITS_BCLR);
readl(vtg->regs + VTG_HOST_ITS);
return IRQ_WAKE_THREAD;
}
static int vtg_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *np;
struct sti_vtg *vtg;
struct resource *res;
int ret;
vtg = devm_kzalloc(dev, sizeof(*vtg), GFP_KERNEL);
if (!vtg)
return -ENOMEM;
vtg->dev = dev;
vtg->np = pdev->dev.of_node;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
DRM_ERROR("Get memory resource failed\n");
return -ENOMEM;
}
vtg->regs = devm_ioremap_nocache(dev, res->start, resource_size(res));
np = of_parse_phandle(pdev->dev.of_node, "st,slave", 0);
if (np) {
vtg->slave = of_vtg_find(np);
if (!vtg->slave)
return -EPROBE_DEFER;
} else {
vtg->irq = platform_get_irq(pdev, 0);
if (IS_ERR_VALUE(vtg->irq)) {
DRM_ERROR("Failed to get VTG interrupt\n");
return vtg->irq;
}
RAW_INIT_NOTIFIER_HEAD(&vtg->notifier_list);
ret = devm_request_threaded_irq(dev, vtg->irq, vtg_irq,
vtg_irq_thread, IRQF_ONESHOT,
dev_name(dev), vtg);
if (IS_ERR_VALUE(ret)) {
DRM_ERROR("Failed to register VTG interrupt\n");
return ret;
}
}
vtg_register(vtg);
platform_set_drvdata(pdev, vtg);
DRM_INFO("%s %s\n", __func__, dev_name(vtg->dev));
return 0;
}
static int vtg_remove(struct platform_device *pdev)
{
return 0;
}
