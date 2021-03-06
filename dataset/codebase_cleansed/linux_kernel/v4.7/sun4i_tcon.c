void sun4i_tcon_disable(struct sun4i_tcon *tcon)
{
DRM_DEBUG_DRIVER("Disabling TCON\n");
regmap_update_bits(tcon->regs, SUN4I_TCON_GCTL_REG,
SUN4I_TCON_GCTL_TCON_ENABLE, 0);
}
void sun4i_tcon_enable(struct sun4i_tcon *tcon)
{
DRM_DEBUG_DRIVER("Enabling TCON\n");
regmap_update_bits(tcon->regs, SUN4I_TCON_GCTL_REG,
SUN4I_TCON_GCTL_TCON_ENABLE,
SUN4I_TCON_GCTL_TCON_ENABLE);
}
void sun4i_tcon_channel_disable(struct sun4i_tcon *tcon, int channel)
{
if (channel == 0) {
regmap_update_bits(tcon->regs, SUN4I_TCON0_CTL_REG,
SUN4I_TCON0_CTL_TCON_ENABLE, 0);
clk_disable_unprepare(tcon->dclk);
} else if (channel == 1) {
regmap_update_bits(tcon->regs, SUN4I_TCON1_CTL_REG,
SUN4I_TCON1_CTL_TCON_ENABLE, 0);
clk_disable_unprepare(tcon->sclk1);
}
}
void sun4i_tcon_channel_enable(struct sun4i_tcon *tcon, int channel)
{
if (channel == 0) {
regmap_update_bits(tcon->regs, SUN4I_TCON0_CTL_REG,
SUN4I_TCON0_CTL_TCON_ENABLE,
SUN4I_TCON0_CTL_TCON_ENABLE);
clk_prepare_enable(tcon->dclk);
} else if (channel == 1) {
regmap_update_bits(tcon->regs, SUN4I_TCON1_CTL_REG,
SUN4I_TCON1_CTL_TCON_ENABLE,
SUN4I_TCON1_CTL_TCON_ENABLE);
clk_prepare_enable(tcon->sclk1);
}
}
void sun4i_tcon_enable_vblank(struct sun4i_tcon *tcon, bool enable)
{
u32 mask, val = 0;
DRM_DEBUG_DRIVER("%sabling VBLANK interrupt\n", enable ? "En" : "Dis");
mask = SUN4I_TCON_GINT0_VBLANK_ENABLE(0) |
SUN4I_TCON_GINT0_VBLANK_ENABLE(1);
if (enable)
val = mask;
regmap_update_bits(tcon->regs, SUN4I_TCON_GINT0_REG, mask, val);
}
static int sun4i_tcon_get_clk_delay(struct drm_display_mode *mode,
int channel)
{
int delay = mode->vtotal - mode->vdisplay;
if (mode->flags & DRM_MODE_FLAG_INTERLACE)
delay /= 2;
if (channel == 1)
delay -= 2;
delay = min(delay, 30);
DRM_DEBUG_DRIVER("TCON %d clock delay %u\n", channel, delay);
return delay;
}
void sun4i_tcon0_mode_set(struct sun4i_tcon *tcon,
struct drm_display_mode *mode)
{
unsigned int bp, hsync, vsync;
u8 clk_delay;
u32 val = 0;
clk_delay = sun4i_tcon_get_clk_delay(mode, 0);
regmap_update_bits(tcon->regs, SUN4I_TCON0_CTL_REG,
SUN4I_TCON0_CTL_CLK_DELAY_MASK,
SUN4I_TCON0_CTL_CLK_DELAY(clk_delay));
regmap_write(tcon->regs, SUN4I_TCON0_BASIC0_REG,
SUN4I_TCON0_BASIC0_X(mode->crtc_hdisplay) |
SUN4I_TCON0_BASIC0_Y(mode->crtc_vdisplay));
bp = mode->crtc_htotal - mode->crtc_hsync_start;
DRM_DEBUG_DRIVER("Setting horizontal total %d, backporch %d\n",
mode->crtc_htotal, bp);
regmap_write(tcon->regs, SUN4I_TCON0_BASIC1_REG,
SUN4I_TCON0_BASIC1_H_TOTAL(mode->crtc_htotal) |
SUN4I_TCON0_BASIC1_H_BACKPORCH(bp));
bp = mode->crtc_vtotal - mode->crtc_vsync_start;
DRM_DEBUG_DRIVER("Setting vertical total %d, backporch %d\n",
mode->crtc_vtotal, bp);
regmap_write(tcon->regs, SUN4I_TCON0_BASIC2_REG,
SUN4I_TCON0_BASIC2_V_TOTAL(mode->crtc_vtotal) |
SUN4I_TCON0_BASIC2_V_BACKPORCH(bp));
hsync = mode->crtc_hsync_end - mode->crtc_hsync_start;
vsync = mode->crtc_vsync_end - mode->crtc_vsync_start;
DRM_DEBUG_DRIVER("Setting HSYNC %d, VSYNC %d\n", hsync, vsync);
regmap_write(tcon->regs, SUN4I_TCON0_BASIC3_REG,
SUN4I_TCON0_BASIC3_V_SYNC(vsync) |
SUN4I_TCON0_BASIC3_H_SYNC(hsync));
if (!(mode->flags & DRM_MODE_FLAG_PHSYNC))
val |= SUN4I_TCON0_IO_POL_HSYNC_POSITIVE;
if (!(mode->flags & DRM_MODE_FLAG_PVSYNC))
val |= SUN4I_TCON0_IO_POL_VSYNC_POSITIVE;
regmap_update_bits(tcon->regs, SUN4I_TCON0_IO_POL_REG,
SUN4I_TCON0_IO_POL_HSYNC_POSITIVE | SUN4I_TCON0_IO_POL_VSYNC_POSITIVE,
val);
regmap_update_bits(tcon->regs, SUN4I_TCON_GCTL_REG,
SUN4I_TCON_GCTL_IOMAP_MASK,
SUN4I_TCON_GCTL_IOMAP_TCON0);
regmap_write(tcon->regs, SUN4I_TCON0_IO_TRI_REG, 0);
}
void sun4i_tcon1_mode_set(struct sun4i_tcon *tcon,
struct drm_display_mode *mode)
{
unsigned int bp, hsync, vsync;
u8 clk_delay;
u32 val;
clk_delay = sun4i_tcon_get_clk_delay(mode, 1);
regmap_update_bits(tcon->regs, SUN4I_TCON1_CTL_REG,
SUN4I_TCON1_CTL_CLK_DELAY_MASK,
SUN4I_TCON1_CTL_CLK_DELAY(clk_delay));
if (mode->flags & DRM_MODE_FLAG_INTERLACE)
val = SUN4I_TCON1_CTL_INTERLACE_ENABLE;
else
val = 0;
regmap_update_bits(tcon->regs, SUN4I_TCON1_CTL_REG,
SUN4I_TCON1_CTL_INTERLACE_ENABLE,
val);
regmap_write(tcon->regs, SUN4I_TCON1_BASIC0_REG,
SUN4I_TCON1_BASIC0_X(mode->crtc_hdisplay) |
SUN4I_TCON1_BASIC0_Y(mode->crtc_vdisplay));
regmap_write(tcon->regs, SUN4I_TCON1_BASIC1_REG,
SUN4I_TCON1_BASIC1_X(mode->crtc_hdisplay) |
SUN4I_TCON1_BASIC1_Y(mode->crtc_vdisplay));
regmap_write(tcon->regs, SUN4I_TCON1_BASIC2_REG,
SUN4I_TCON1_BASIC2_X(mode->crtc_hdisplay) |
SUN4I_TCON1_BASIC2_Y(mode->crtc_vdisplay));
bp = mode->crtc_htotal - mode->crtc_hsync_end;
DRM_DEBUG_DRIVER("Setting horizontal total %d, backporch %d\n",
mode->htotal, bp);
regmap_write(tcon->regs, SUN4I_TCON1_BASIC3_REG,
SUN4I_TCON1_BASIC3_H_TOTAL(mode->crtc_htotal) |
SUN4I_TCON1_BASIC3_H_BACKPORCH(bp));
bp = mode->crtc_vtotal - mode->crtc_vsync_end;
DRM_DEBUG_DRIVER("Setting vertical total %d, backporch %d\n",
mode->vtotal, bp);
regmap_write(tcon->regs, SUN4I_TCON1_BASIC4_REG,
SUN4I_TCON1_BASIC4_V_TOTAL(mode->vtotal) |
SUN4I_TCON1_BASIC4_V_BACKPORCH(bp));
hsync = mode->crtc_hsync_end - mode->crtc_hsync_start;
vsync = mode->crtc_vsync_end - mode->crtc_vsync_start;
DRM_DEBUG_DRIVER("Setting HSYNC %d, VSYNC %d\n", hsync, vsync);
regmap_write(tcon->regs, SUN4I_TCON1_BASIC5_REG,
SUN4I_TCON1_BASIC5_V_SYNC(vsync) |
SUN4I_TCON1_BASIC5_H_SYNC(hsync));
regmap_update_bits(tcon->regs, SUN4I_TCON_GCTL_REG,
SUN4I_TCON_GCTL_IOMAP_MASK,
SUN4I_TCON_GCTL_IOMAP_TCON1);
if (tcon->has_mux)
regmap_write(tcon->regs, SUN4I_TCON_MUX_CTRL_REG, 1);
}
static void sun4i_tcon_finish_page_flip(struct drm_device *dev,
struct sun4i_crtc *scrtc)
{
unsigned long flags;
spin_lock_irqsave(&dev->event_lock, flags);
if (scrtc->event) {
drm_crtc_send_vblank_event(&scrtc->crtc, scrtc->event);
drm_crtc_vblank_put(&scrtc->crtc);
scrtc->event = NULL;
}
spin_unlock_irqrestore(&dev->event_lock, flags);
}
static irqreturn_t sun4i_tcon_handler(int irq, void *private)
{
struct sun4i_tcon *tcon = private;
struct drm_device *drm = tcon->drm;
struct sun4i_drv *drv = drm->dev_private;
struct sun4i_crtc *scrtc = drv->crtc;
unsigned int status;
regmap_read(tcon->regs, SUN4I_TCON_GINT0_REG, &status);
if (!(status & (SUN4I_TCON_GINT0_VBLANK_INT(0) |
SUN4I_TCON_GINT0_VBLANK_INT(1))))
return IRQ_NONE;
drm_crtc_handle_vblank(&scrtc->crtc);
sun4i_tcon_finish_page_flip(drm, scrtc);
regmap_update_bits(tcon->regs, SUN4I_TCON_GINT0_REG,
SUN4I_TCON_GINT0_VBLANK_INT(0) |
SUN4I_TCON_GINT0_VBLANK_INT(1),
0);
return IRQ_HANDLED;
}
static int sun4i_tcon_init_clocks(struct device *dev,
struct sun4i_tcon *tcon)
{
tcon->clk = devm_clk_get(dev, "ahb");
if (IS_ERR(tcon->clk)) {
dev_err(dev, "Couldn't get the TCON bus clock\n");
return PTR_ERR(tcon->clk);
}
clk_prepare_enable(tcon->clk);
tcon->sclk0 = devm_clk_get(dev, "tcon-ch0");
if (IS_ERR(tcon->sclk0)) {
dev_err(dev, "Couldn't get the TCON channel 0 clock\n");
return PTR_ERR(tcon->sclk0);
}
tcon->sclk1 = devm_clk_get(dev, "tcon-ch1");
if (IS_ERR(tcon->sclk1)) {
dev_err(dev, "Couldn't get the TCON channel 1 clock\n");
return PTR_ERR(tcon->sclk1);
}
return sun4i_dclk_create(dev, tcon);
}
static void sun4i_tcon_free_clocks(struct sun4i_tcon *tcon)
{
sun4i_dclk_free(tcon);
clk_disable_unprepare(tcon->clk);
}
static int sun4i_tcon_init_irq(struct device *dev,
struct sun4i_tcon *tcon)
{
struct platform_device *pdev = to_platform_device(dev);
int irq, ret;
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(dev, "Couldn't retrieve the TCON interrupt\n");
return irq;
}
ret = devm_request_irq(dev, irq, sun4i_tcon_handler, 0,
dev_name(dev), tcon);
if (ret) {
dev_err(dev, "Couldn't request the IRQ\n");
return ret;
}
return 0;
}
static int sun4i_tcon_init_regmap(struct device *dev,
struct sun4i_tcon *tcon)
{
struct platform_device *pdev = to_platform_device(dev);
struct resource *res;
void __iomem *regs;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
regs = devm_ioremap_resource(dev, res);
if (IS_ERR(regs)) {
dev_err(dev, "Couldn't map the TCON registers\n");
return PTR_ERR(regs);
}
tcon->regs = devm_regmap_init_mmio(dev, regs,
&sun4i_tcon_regmap_config);
if (IS_ERR(tcon->regs)) {
dev_err(dev, "Couldn't create the TCON regmap\n");
return PTR_ERR(tcon->regs);
}
regmap_write(tcon->regs, SUN4I_TCON_GCTL_REG, 0);
regmap_write(tcon->regs, SUN4I_TCON_GINT0_REG, 0);
regmap_write(tcon->regs, SUN4I_TCON_GINT1_REG, 0);
regmap_write(tcon->regs, SUN4I_TCON0_IO_TRI_REG, ~0);
regmap_write(tcon->regs, SUN4I_TCON1_IO_TRI_REG, ~0);
return 0;
}
static struct drm_panel *sun4i_tcon_find_panel(struct device_node *node)
{
struct device_node *port, *remote, *child;
struct device_node *end_node = NULL;
port = of_graph_get_port_by_id(node, 1);
for_each_child_of_node(port, child) {
u32 reg;
of_property_read_u32(child, "reg", &reg);
if (reg == 0)
end_node = child;
}
if (!end_node) {
DRM_DEBUG_DRIVER("Missing panel endpoint\n");
return ERR_PTR(-ENODEV);
}
remote = of_graph_get_remote_port_parent(end_node);
if (!remote) {
DRM_DEBUG_DRIVER("Unable to parse remote node\n");
return ERR_PTR(-EINVAL);
}
return of_drm_find_panel(remote) ?: ERR_PTR(-EPROBE_DEFER);
}
static int sun4i_tcon_bind(struct device *dev, struct device *master,
void *data)
{
struct drm_device *drm = data;
struct sun4i_drv *drv = drm->dev_private;
struct sun4i_tcon *tcon;
int ret;
tcon = devm_kzalloc(dev, sizeof(*tcon), GFP_KERNEL);
if (!tcon)
return -ENOMEM;
dev_set_drvdata(dev, tcon);
drv->tcon = tcon;
tcon->drm = drm;
if (of_device_is_compatible(dev->of_node, "allwinner,sun5i-a13-tcon"))
tcon->has_mux = true;
tcon->lcd_rst = devm_reset_control_get(dev, "lcd");
if (IS_ERR(tcon->lcd_rst)) {
dev_err(dev, "Couldn't get our reset line\n");
return PTR_ERR(tcon->lcd_rst);
}
if (!reset_control_status(tcon->lcd_rst))
reset_control_assert(tcon->lcd_rst);
ret = reset_control_deassert(tcon->lcd_rst);
if (ret) {
dev_err(dev, "Couldn't deassert our reset line\n");
return ret;
}
ret = sun4i_tcon_init_regmap(dev, tcon);
if (ret) {
dev_err(dev, "Couldn't init our TCON regmap\n");
goto err_assert_reset;
}
ret = sun4i_tcon_init_clocks(dev, tcon);
if (ret) {
dev_err(dev, "Couldn't init our TCON clocks\n");
goto err_assert_reset;
}
ret = sun4i_tcon_init_irq(dev, tcon);
if (ret) {
dev_err(dev, "Couldn't init our TCON interrupts\n");
goto err_free_clocks;
}
tcon->panel = sun4i_tcon_find_panel(dev->of_node);
if (IS_ERR(tcon->panel)) {
dev_info(dev, "No panel found... RGB output disabled\n");
return 0;
}
ret = sun4i_rgb_init(drm);
if (ret < 0)
goto err_free_clocks;
return 0;
err_free_clocks:
sun4i_tcon_free_clocks(tcon);
err_assert_reset:
reset_control_assert(tcon->lcd_rst);
return ret;
}
static void sun4i_tcon_unbind(struct device *dev, struct device *master,
void *data)
{
struct sun4i_tcon *tcon = dev_get_drvdata(dev);
sun4i_tcon_free_clocks(tcon);
}
static int sun4i_tcon_probe(struct platform_device *pdev)
{
struct device_node *node = pdev->dev.of_node;
struct drm_panel *panel;
panel = sun4i_tcon_find_panel(node);
if (PTR_ERR(panel) == -EPROBE_DEFER) {
DRM_DEBUG_DRIVER("Still waiting for our panel. Deferring...\n");
return -EPROBE_DEFER;
}
return component_add(&pdev->dev, &sun4i_tcon_ops);
}
static int sun4i_tcon_remove(struct platform_device *pdev)
{
component_del(&pdev->dev, &sun4i_tcon_ops);
return 0;
}
