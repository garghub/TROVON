static irqreturn_t ctrl_handle_irq(int irq, void *dev_id)
{
struct mmphw_ctrl *ctrl = (struct mmphw_ctrl *)dev_id;
u32 isr, imask, tmp;
isr = readl_relaxed(ctrl->reg_base + SPU_IRQ_ISR);
imask = readl_relaxed(ctrl->reg_base + SPU_IRQ_ENA);
do {
tmp = readl_relaxed(ctrl->reg_base + SPU_IRQ_ISR);
if (tmp & isr)
writel_relaxed(~isr, ctrl->reg_base + SPU_IRQ_ISR);
} while ((isr = readl(ctrl->reg_base + SPU_IRQ_ISR)) & imask);
return IRQ_HANDLED;
}
static u32 fmt_to_reg(struct mmp_overlay *overlay, int pix_fmt)
{
u32 link_config = path_to_path_plat(overlay->path)->link_config;
u32 rbswap, uvswap = 0, yuvswap = 0,
csc_en = 0, val = 0,
vid = overlay_is_vid(overlay);
switch (pix_fmt) {
case PIXFMT_RGB565:
case PIXFMT_RGB1555:
case PIXFMT_RGB888PACK:
case PIXFMT_RGB888UNPACK:
case PIXFMT_RGBA888:
rbswap = !(link_config & 0x1);
break;
case PIXFMT_VYUY:
case PIXFMT_YVU422P:
case PIXFMT_YVU420P:
rbswap = link_config & 0x1;
uvswap = 1;
break;
case PIXFMT_YUYV:
rbswap = link_config & 0x1;
yuvswap = 1;
break;
default:
rbswap = link_config & 0x1;
break;
}
switch (pix_fmt) {
case PIXFMT_RGB565:
case PIXFMT_BGR565:
val = 0;
break;
case PIXFMT_RGB1555:
case PIXFMT_BGR1555:
val = 0x1;
break;
case PIXFMT_RGB888PACK:
case PIXFMT_BGR888PACK:
val = 0x2;
break;
case PIXFMT_RGB888UNPACK:
case PIXFMT_BGR888UNPACK:
val = 0x3;
break;
case PIXFMT_RGBA888:
case PIXFMT_BGRA888:
val = 0x4;
break;
case PIXFMT_UYVY:
case PIXFMT_VYUY:
case PIXFMT_YUYV:
val = 0x5;
csc_en = 1;
break;
case PIXFMT_YUV422P:
case PIXFMT_YVU422P:
val = 0x6;
csc_en = 1;
break;
case PIXFMT_YUV420P:
case PIXFMT_YVU420P:
val = 0x7;
csc_en = 1;
break;
default:
break;
}
return (dma_palette(0) | dma_fmt(vid, val) |
dma_swaprb(vid, rbswap) | dma_swapuv(vid, uvswap) |
dma_swapyuv(vid, yuvswap) | dma_csc(vid, csc_en));
}
static void dmafetch_set_fmt(struct mmp_overlay *overlay)
{
u32 tmp;
struct mmp_path *path = overlay->path;
tmp = readl_relaxed(ctrl_regs(path) + dma_ctrl(0, path->id));
tmp &= ~dma_mask(overlay_is_vid(overlay));
tmp |= fmt_to_reg(overlay, overlay->win.pix_fmt);
writel_relaxed(tmp, ctrl_regs(path) + dma_ctrl(0, path->id));
}
static void overlay_set_win(struct mmp_overlay *overlay, struct mmp_win *win)
{
struct lcd_regs *regs = path_regs(overlay->path);
u32 pitch;
memcpy(&overlay->win, win, sizeof(struct mmp_win));
mutex_lock(&overlay->access_ok);
pitch = win->xsrc * pixfmt_to_stride(win->pix_fmt);
writel_relaxed(pitch, &regs->g_pitch);
writel_relaxed((win->ysrc << 16) | win->xsrc, &regs->g_size);
writel_relaxed((win->ydst << 16) | win->xdst, &regs->g_size_z);
writel_relaxed(0, &regs->g_start);
dmafetch_set_fmt(overlay);
mutex_unlock(&overlay->access_ok);
}
static void dmafetch_onoff(struct mmp_overlay *overlay, int on)
{
u32 mask = overlay_is_vid(overlay) ? CFG_GRA_ENA_MASK :
CFG_DMA_ENA_MASK;
u32 enable = overlay_is_vid(overlay) ? CFG_GRA_ENA(1) : CFG_DMA_ENA(1);
u32 tmp;
struct mmp_path *path = overlay->path;
mutex_lock(&overlay->access_ok);
tmp = readl_relaxed(ctrl_regs(path) + dma_ctrl(0, path->id));
tmp &= ~mask;
tmp |= (on ? enable : 0);
writel(tmp, ctrl_regs(path) + dma_ctrl(0, path->id));
mutex_unlock(&overlay->access_ok);
}
static void path_enabledisable(struct mmp_path *path, int on)
{
u32 tmp;
mutex_lock(&path->access_ok);
tmp = readl_relaxed(ctrl_regs(path) + LCD_SCLK(path));
if (on)
tmp &= ~SCLK_DISABLE;
else
tmp |= SCLK_DISABLE;
writel_relaxed(tmp, ctrl_regs(path) + LCD_SCLK(path));
mutex_unlock(&path->access_ok);
}
static void path_onoff(struct mmp_path *path, int on)
{
if (path->status == on) {
dev_info(path->dev, "path %s is already %s\n",
path->name, stat_name(path->status));
return;
}
if (on) {
path_enabledisable(path, 1);
if (path->panel && path->panel->set_onoff)
path->panel->set_onoff(path->panel, 1);
} else {
if (path->panel && path->panel->set_onoff)
path->panel->set_onoff(path->panel, 0);
path_enabledisable(path, 0);
}
path->status = on;
}
static void overlay_set_onoff(struct mmp_overlay *overlay, int on)
{
if (overlay->status == on) {
dev_info(overlay_to_ctrl(overlay)->dev, "overlay %s is already %s\n",
overlay->path->name, stat_name(overlay->status));
return;
}
overlay->status = on;
dmafetch_onoff(overlay, on);
if (overlay->path->ops.check_status(overlay->path)
!= overlay->path->status)
path_onoff(overlay->path, on);
}
static void overlay_set_fetch(struct mmp_overlay *overlay, int fetch_id)
{
overlay->dmafetch_id = fetch_id;
}
static int overlay_set_addr(struct mmp_overlay *overlay, struct mmp_addr *addr)
{
struct lcd_regs *regs = path_regs(overlay->path);
memcpy(&overlay->addr, addr, sizeof(struct mmp_win));
writel(addr->phys[0], &regs->g_0);
return overlay->addr.phys[0];
}
static void path_set_mode(struct mmp_path *path, struct mmp_mode *mode)
{
struct lcd_regs *regs = path_regs(path);
u32 total_x, total_y, vsync_ctrl, tmp, sclk_src, sclk_div,
link_config = path_to_path_plat(path)->link_config;
memcpy(&path->mode, mode, sizeof(struct mmp_mode));
mutex_lock(&path->access_ok);
tmp = readl_relaxed(ctrl_regs(path) + intf_ctrl(path->id)) & 0x1;
tmp |= mode->vsync_invert ? 0 : 0x8;
tmp |= mode->hsync_invert ? 0 : 0x4;
tmp |= link_config & CFG_DUMBMODE_MASK;
tmp |= CFG_DUMB_ENA(1);
writel_relaxed(tmp, ctrl_regs(path) + intf_ctrl(path->id));
writel_relaxed((mode->yres << 16) | mode->xres, &regs->screen_active);
writel_relaxed((mode->left_margin << 16) | mode->right_margin,
&regs->screen_h_porch);
writel_relaxed((mode->upper_margin << 16) | mode->lower_margin,
&regs->screen_v_porch);
total_x = mode->xres + mode->left_margin + mode->right_margin +
mode->hsync_len;
total_y = mode->yres + mode->upper_margin + mode->lower_margin +
mode->vsync_len;
writel_relaxed((total_y << 16) | total_x, &regs->screen_size);
if (path->output_type == PATH_OUT_DSI)
vsync_ctrl = 0x01330133;
else
vsync_ctrl = ((mode->xres + mode->right_margin) << 16)
| (mode->xres + mode->right_margin);
writel_relaxed(vsync_ctrl, &regs->vsync_ctrl);
sclk_src = clk_get_rate(path_to_ctrl(path)->clk);
sclk_div = sclk_src / mode->pixclock_freq;
if (sclk_div * mode->pixclock_freq < sclk_src)
sclk_div++;
dev_info(path->dev, "%s sclk_src %d sclk_div 0x%x pclk %d\n",
__func__, sclk_src, sclk_div, mode->pixclock_freq);
tmp = readl_relaxed(ctrl_regs(path) + LCD_SCLK(path));
tmp &= ~CLK_INT_DIV_MASK;
tmp |= sclk_div;
writel_relaxed(tmp, ctrl_regs(path) + LCD_SCLK(path));
mutex_unlock(&path->access_ok);
}
static void ctrl_set_default(struct mmphw_ctrl *ctrl)
{
u32 tmp, irq_mask;
tmp = readl_relaxed(ctrl->reg_base + LCD_TOP_CTRL);
tmp |= 0xfff0;
writel_relaxed(tmp, ctrl->reg_base + LCD_TOP_CTRL);
irq_mask = path_imasks(0) | err_imask(0) |
path_imasks(1) | err_imask(1);
tmp = readl_relaxed(ctrl->reg_base + SPU_IRQ_ENA);
tmp &= ~irq_mask;
tmp |= irq_mask;
writel_relaxed(tmp, ctrl->reg_base + SPU_IRQ_ENA);
}
static void path_set_default(struct mmp_path *path)
{
struct lcd_regs *regs = path_regs(path);
u32 dma_ctrl1, mask, tmp, path_config;
path_config = path_to_path_plat(path)->path_config;
if (PATH_OUT_PARALLEL == path->output_type) {
mask = CFG_IOPADMODE_MASK | CFG_BURST_MASK | CFG_BOUNDARY_MASK;
tmp = readl_relaxed(ctrl_regs(path) + SPU_IOPAD_CONTROL);
tmp &= ~mask;
tmp |= path_config;
writel_relaxed(tmp, ctrl_regs(path) + SPU_IOPAD_CONTROL);
}
tmp = readl_relaxed(ctrl_regs(path) + LCD_SCLK(path));
tmp &= ~SCLK_SRC_SEL_MASK;
tmp |= path_config;
writel_relaxed(tmp, ctrl_regs(path) + LCD_SCLK(path));
dma_ctrl1 = 0x2032ff81;
dma_ctrl1 |= CFG_VSYNC_INV_MASK;
writel_relaxed(dma_ctrl1, ctrl_regs(path) + dma_ctrl(1, path->id));
writel_relaxed(0x00000000, &regs->blank_color);
writel_relaxed(0x00000000, &regs->g_1);
writel_relaxed(0x00000000, &regs->g_start);
if (PATH_PN == path->id) {
mask = CFG_GRA_HSMOOTH_MASK | CFG_DMA_HSMOOTH_MASK
| CFG_ARBFAST_ENA(1);
tmp = readl_relaxed(ctrl_regs(path) + dma_ctrl(0, path->id));
tmp |= mask;
writel_relaxed(tmp, ctrl_regs(path) + dma_ctrl(0, path->id));
} else if (PATH_TV == path->id) {
mask = CFG_GRA_HSMOOTH_MASK | CFG_DMA_HSMOOTH_MASK
| CFG_ARBFAST_ENA(1);
tmp = readl_relaxed(ctrl_regs(path) + dma_ctrl(0, path->id));
tmp &= ~mask;
tmp |= CFG_GRA_HSMOOTH_MASK | CFG_DMA_HSMOOTH_MASK;
writel_relaxed(tmp, ctrl_regs(path) + dma_ctrl(0, path->id));
}
}
static int path_init(struct mmphw_path_plat *path_plat,
struct mmp_mach_path_config *config)
{
struct mmphw_ctrl *ctrl = path_plat->ctrl;
struct mmp_path_info *path_info;
struct mmp_path *path = NULL;
dev_info(ctrl->dev, "%s: %s\n", __func__, config->name);
path_info = kzalloc(sizeof(struct mmp_path_info), GFP_KERNEL);
if (!path_info) {
dev_err(ctrl->dev, "%s: unable to alloc path_info for %s\n",
__func__, config->name);
return 0;
}
path_info->name = config->name;
path_info->id = path_plat->id;
path_info->dev = ctrl->dev;
path_info->overlay_num = config->overlay_num;
path_info->overlay_ops = &mmphw_overlay_ops;
path_info->set_mode = path_set_mode;
path_info->plat_data = path_plat;
path = mmp_register_path(path_info);
if (!path) {
kfree(path_info);
return 0;
}
path_plat->path = path;
path_plat->path_config = config->path_config;
path_plat->link_config = config->link_config;
path_set_default(path);
kfree(path_info);
return 1;
}
static void path_deinit(struct mmphw_path_plat *path_plat)
{
if (!path_plat)
return;
if (path_plat->path)
mmp_unregister_path(path_plat->path);
}
static int mmphw_probe(struct platform_device *pdev)
{
struct mmp_mach_plat_info *mi;
struct resource *res;
int ret, i, size, irq;
struct mmphw_path_plat *path_plat;
struct mmphw_ctrl *ctrl = NULL;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (res == NULL) {
dev_err(&pdev->dev, "%s: no IO memory defined\n", __func__);
ret = -ENOENT;
goto failed;
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "%s: no IRQ defined\n", __func__);
ret = -ENOENT;
goto failed;
}
mi = pdev->dev.platform_data;
if (mi == NULL || !mi->path_num || !mi->paths) {
dev_err(&pdev->dev, "%s: no platform data defined\n", __func__);
ret = -EINVAL;
goto failed;
}
size = sizeof(struct mmphw_ctrl) + sizeof(struct mmphw_path_plat) *
mi->path_num;
ctrl = devm_kzalloc(&pdev->dev, size, GFP_KERNEL);
if (!ctrl) {
ret = -ENOMEM;
goto failed;
}
ctrl->name = mi->name;
ctrl->path_num = mi->path_num;
ctrl->dev = &pdev->dev;
ctrl->irq = irq;
platform_set_drvdata(pdev, ctrl);
mutex_init(&ctrl->access_ok);
if (!devm_request_mem_region(ctrl->dev, res->start,
resource_size(res), ctrl->name)) {
dev_err(ctrl->dev,
"can't request region for resource %pR\n", res);
ret = -EINVAL;
goto failed;
}
ctrl->reg_base = devm_ioremap_nocache(ctrl->dev,
res->start, resource_size(res));
if (ctrl->reg_base == NULL) {
dev_err(ctrl->dev, "%s: res %x - %x map failed\n", __func__,
res->start, res->end);
ret = -ENOMEM;
goto failed;
}
ret = devm_request_irq(ctrl->dev, ctrl->irq, ctrl_handle_irq,
IRQF_SHARED, "lcd_controller", ctrl);
if (ret < 0) {
dev_err(ctrl->dev, "%s unable to request IRQ %d\n",
__func__, ctrl->irq);
ret = -ENXIO;
goto failed;
}
ctrl->clk = devm_clk_get(ctrl->dev, mi->clk_name);
if (IS_ERR(ctrl->clk)) {
dev_err(ctrl->dev, "unable to get clk %s\n", mi->clk_name);
ret = -ENOENT;
goto failed_get_clk;
}
clk_prepare_enable(ctrl->clk);
ctrl_set_default(ctrl);
for (i = 0; i < ctrl->path_num; i++) {
path_plat = &ctrl->path_plats[i];
path_plat->id = i;
path_plat->ctrl = ctrl;
if (!path_init(path_plat, &mi->paths[i])) {
ret = -EINVAL;
goto failed_path_init;
}
}
#ifdef CONFIG_MMP_DISP_SPI
ret = lcd_spi_register(ctrl);
if (ret < 0)
goto failed_path_init;
#endif
dev_info(ctrl->dev, "device init done\n");
return 0;
failed_path_init:
for (i = 0; i < ctrl->path_num; i++) {
path_plat = &ctrl->path_plats[i];
path_deinit(path_plat);
}
if (ctrl->clk) {
devm_clk_put(ctrl->dev, ctrl->clk);
clk_disable_unprepare(ctrl->clk);
}
failed_get_clk:
devm_free_irq(ctrl->dev, ctrl->irq, ctrl);
failed:
if (ctrl) {
if (ctrl->reg_base)
devm_iounmap(ctrl->dev, ctrl->reg_base);
devm_release_mem_region(ctrl->dev, res->start,
resource_size(res));
devm_kfree(ctrl->dev, ctrl);
}
platform_set_drvdata(pdev, NULL);
dev_err(&pdev->dev, "device init failed\n");
return ret;
}
static int mmphw_init(void)
{
return platform_driver_register(&mmphw_driver);
}
