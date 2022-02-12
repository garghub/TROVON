static struct mxsfb_drm_private *
drm_pipe_to_mxsfb_drm_private(struct drm_simple_display_pipe *pipe)
{
return container_of(pipe, struct mxsfb_drm_private, pipe);
}
void mxsfb_enable_axi_clk(struct mxsfb_drm_private *mxsfb)
{
if (mxsfb->clk_axi)
clk_prepare_enable(mxsfb->clk_axi);
}
void mxsfb_disable_axi_clk(struct mxsfb_drm_private *mxsfb)
{
if (mxsfb->clk_axi)
clk_disable_unprepare(mxsfb->clk_axi);
}
static void mxsfb_pipe_enable(struct drm_simple_display_pipe *pipe,
struct drm_crtc_state *crtc_state)
{
struct mxsfb_drm_private *mxsfb = drm_pipe_to_mxsfb_drm_private(pipe);
drm_panel_prepare(mxsfb->panel);
mxsfb_crtc_enable(mxsfb);
drm_panel_enable(mxsfb->panel);
}
static void mxsfb_pipe_disable(struct drm_simple_display_pipe *pipe)
{
struct mxsfb_drm_private *mxsfb = drm_pipe_to_mxsfb_drm_private(pipe);
drm_panel_disable(mxsfb->panel);
mxsfb_crtc_disable(mxsfb);
drm_panel_unprepare(mxsfb->panel);
}
static void mxsfb_pipe_update(struct drm_simple_display_pipe *pipe,
struct drm_plane_state *plane_state)
{
struct mxsfb_drm_private *mxsfb = drm_pipe_to_mxsfb_drm_private(pipe);
mxsfb_plane_atomic_update(mxsfb, plane_state);
}
static int mxsfb_pipe_prepare_fb(struct drm_simple_display_pipe *pipe,
struct drm_plane_state *plane_state)
{
return drm_fb_cma_prepare_fb(&pipe->plane, plane_state);
}
static int mxsfb_load(struct drm_device *drm, unsigned long flags)
{
struct platform_device *pdev = to_platform_device(drm->dev);
struct mxsfb_drm_private *mxsfb;
struct resource *res;
int ret;
mxsfb = devm_kzalloc(&pdev->dev, sizeof(*mxsfb), GFP_KERNEL);
if (!mxsfb)
return -ENOMEM;
drm->dev_private = mxsfb;
mxsfb->devdata = &mxsfb_devdata[pdev->id_entry->driver_data];
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
mxsfb->base = devm_ioremap_resource(drm->dev, res);
if (IS_ERR(mxsfb->base))
return PTR_ERR(mxsfb->base);
mxsfb->clk = devm_clk_get(drm->dev, NULL);
if (IS_ERR(mxsfb->clk))
return PTR_ERR(mxsfb->clk);
mxsfb->clk_axi = devm_clk_get(drm->dev, "axi");
if (IS_ERR(mxsfb->clk_axi))
mxsfb->clk_axi = NULL;
mxsfb->clk_disp_axi = devm_clk_get(drm->dev, "disp_axi");
if (IS_ERR(mxsfb->clk_disp_axi))
mxsfb->clk_disp_axi = NULL;
ret = dma_set_mask_and_coherent(drm->dev, DMA_BIT_MASK(32));
if (ret)
return ret;
pm_runtime_enable(drm->dev);
ret = drm_vblank_init(drm, drm->mode_config.num_crtc);
if (ret < 0) {
dev_err(drm->dev, "Failed to initialise vblank\n");
goto err_vblank;
}
drm_mode_config_init(drm);
ret = mxsfb_create_output(drm);
if (ret < 0) {
dev_err(drm->dev, "Failed to create outputs\n");
goto err_vblank;
}
ret = drm_simple_display_pipe_init(drm, &mxsfb->pipe, &mxsfb_funcs,
mxsfb_formats, ARRAY_SIZE(mxsfb_formats),
&mxsfb->connector);
if (ret < 0) {
dev_err(drm->dev, "Cannot setup simple display pipe\n");
goto err_vblank;
}
ret = drm_panel_attach(mxsfb->panel, &mxsfb->connector);
if (ret) {
dev_err(drm->dev, "Cannot connect panel\n");
goto err_vblank;
}
drm->mode_config.min_width = MXSFB_MIN_XRES;
drm->mode_config.min_height = MXSFB_MIN_YRES;
drm->mode_config.max_width = MXSFB_MAX_XRES;
drm->mode_config.max_height = MXSFB_MAX_YRES;
drm->mode_config.funcs = &mxsfb_mode_config_funcs;
drm_mode_config_reset(drm);
pm_runtime_get_sync(drm->dev);
ret = drm_irq_install(drm, platform_get_irq(pdev, 0));
pm_runtime_put_sync(drm->dev);
if (ret < 0) {
dev_err(drm->dev, "Failed to install IRQ handler\n");
goto err_irq;
}
drm_kms_helper_poll_init(drm);
mxsfb->fbdev = drm_fbdev_cma_init(drm, 32,
drm->mode_config.num_connector);
if (IS_ERR(mxsfb->fbdev)) {
mxsfb->fbdev = NULL;
dev_err(drm->dev, "Failed to init FB CMA area\n");
goto err_cma;
}
platform_set_drvdata(pdev, drm);
drm_helper_hpd_irq_event(drm);
return 0;
err_cma:
drm_irq_uninstall(drm);
err_irq:
drm_panel_detach(mxsfb->panel);
err_vblank:
pm_runtime_disable(drm->dev);
return ret;
}
static void mxsfb_unload(struct drm_device *drm)
{
struct mxsfb_drm_private *mxsfb = drm->dev_private;
if (mxsfb->fbdev)
drm_fbdev_cma_fini(mxsfb->fbdev);
drm_kms_helper_poll_fini(drm);
drm_mode_config_cleanup(drm);
drm_vblank_cleanup(drm);
pm_runtime_get_sync(drm->dev);
drm_irq_uninstall(drm);
pm_runtime_put_sync(drm->dev);
drm->dev_private = NULL;
pm_runtime_disable(drm->dev);
}
static void mxsfb_lastclose(struct drm_device *drm)
{
struct mxsfb_drm_private *mxsfb = drm->dev_private;
drm_fbdev_cma_restore_mode(mxsfb->fbdev);
}
static int mxsfb_enable_vblank(struct drm_device *drm, unsigned int crtc)
{
struct mxsfb_drm_private *mxsfb = drm->dev_private;
mxsfb_enable_axi_clk(mxsfb);
writel(CTRL1_CUR_FRAME_DONE_IRQ, mxsfb->base + LCDC_CTRL1 + REG_CLR);
writel(CTRL1_CUR_FRAME_DONE_IRQ_EN, mxsfb->base + LCDC_CTRL1 + REG_SET);
mxsfb_disable_axi_clk(mxsfb);
return 0;
}
static void mxsfb_disable_vblank(struct drm_device *drm, unsigned int crtc)
{
struct mxsfb_drm_private *mxsfb = drm->dev_private;
mxsfb_enable_axi_clk(mxsfb);
writel(CTRL1_CUR_FRAME_DONE_IRQ_EN, mxsfb->base + LCDC_CTRL1 + REG_CLR);
writel(CTRL1_CUR_FRAME_DONE_IRQ, mxsfb->base + LCDC_CTRL1 + REG_CLR);
mxsfb_disable_axi_clk(mxsfb);
}
static void mxsfb_irq_preinstall(struct drm_device *drm)
{
mxsfb_disable_vblank(drm, 0);
}
static irqreturn_t mxsfb_irq_handler(int irq, void *data)
{
struct drm_device *drm = data;
struct mxsfb_drm_private *mxsfb = drm->dev_private;
u32 reg;
mxsfb_enable_axi_clk(mxsfb);
reg = readl(mxsfb->base + LCDC_CTRL1);
if (reg & CTRL1_CUR_FRAME_DONE_IRQ)
drm_crtc_handle_vblank(&mxsfb->pipe.crtc);
writel(CTRL1_CUR_FRAME_DONE_IRQ, mxsfb->base + LCDC_CTRL1 + REG_CLR);
mxsfb_disable_axi_clk(mxsfb);
return IRQ_HANDLED;
}
static int mxsfb_probe(struct platform_device *pdev)
{
struct drm_device *drm;
const struct of_device_id *of_id =
of_match_device(mxsfb_dt_ids, &pdev->dev);
int ret;
if (!pdev->dev.of_node)
return -ENODEV;
if (of_id)
pdev->id_entry = of_id->data;
drm = drm_dev_alloc(&mxsfb_driver, &pdev->dev);
if (IS_ERR(drm))
return PTR_ERR(drm);
ret = mxsfb_load(drm, 0);
if (ret)
goto err_free;
ret = drm_dev_register(drm, 0);
if (ret)
goto err_unload;
return 0;
err_unload:
mxsfb_unload(drm);
err_free:
drm_dev_unref(drm);
return ret;
}
static int mxsfb_remove(struct platform_device *pdev)
{
struct drm_device *drm = platform_get_drvdata(pdev);
drm_dev_unregister(drm);
mxsfb_unload(drm);
drm_dev_unref(drm);
return 0;
}
