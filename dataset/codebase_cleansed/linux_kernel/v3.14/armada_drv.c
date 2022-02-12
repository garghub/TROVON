static void armada_drm_unref_work(struct work_struct *work)
{
struct armada_private *priv =
container_of(work, struct armada_private, fb_unref_work);
struct drm_framebuffer *fb;
while (kfifo_get(&priv->fb_unref, &fb))
drm_framebuffer_unreference(fb);
}
void __armada_drm_queue_unref_work(struct drm_device *dev,
struct drm_framebuffer *fb)
{
struct armada_private *priv = dev->dev_private;
WARN_ON(!kfifo_put(&priv->fb_unref, fb));
schedule_work(&priv->fb_unref_work);
}
void armada_drm_queue_unref_work(struct drm_device *dev,
struct drm_framebuffer *fb)
{
unsigned long flags;
spin_lock_irqsave(&dev->event_lock, flags);
__armada_drm_queue_unref_work(dev, fb);
spin_unlock_irqrestore(&dev->event_lock, flags);
}
static int armada_drm_load(struct drm_device *dev, unsigned long flags)
{
const struct platform_device_id *id;
struct armada_private *priv;
struct resource *res[ARRAY_SIZE(priv->dcrtc)];
struct resource *mem = NULL;
int ret, n, i;
memset(res, 0, sizeof(res));
for (n = i = 0; ; n++) {
struct resource *r = platform_get_resource(dev->platformdev,
IORESOURCE_MEM, n);
if (!r)
break;
if (resource_size(r) > SZ_64K)
mem = r;
else if (i < ARRAY_SIZE(priv->dcrtc))
res[i++] = r;
else
return -EINVAL;
}
if (!res[0] || !mem)
return -ENXIO;
if (!devm_request_mem_region(dev->dev, mem->start,
resource_size(mem), "armada-drm"))
return -EBUSY;
priv = devm_kzalloc(dev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv) {
DRM_ERROR("failed to allocate private\n");
return -ENOMEM;
}
platform_set_drvdata(dev->platformdev, dev);
dev->dev_private = priv;
id = platform_get_device_id(dev->platformdev);
if (!id)
return -ENXIO;
priv->variant = (struct armada_variant *)id->driver_data;
ret = priv->variant->init(priv, dev->dev);
if (ret)
return ret;
INIT_WORK(&priv->fb_unref_work, armada_drm_unref_work);
INIT_KFIFO(priv->fb_unref);
drm_mode_config_init(dev);
dev->mode_config.min_width = 320;
dev->mode_config.min_height = 200;
dev->mode_config.max_width = 1920;
dev->mode_config.max_height = 2048;
dev->mode_config.preferred_depth = 24;
dev->mode_config.funcs = &armada_drm_mode_config_funcs;
drm_mm_init(&priv->linear, mem->start, resource_size(mem));
for (n = 0; n < ARRAY_SIZE(priv->dcrtc); n++) {
if (!res[n])
break;
ret = armada_drm_crtc_create(dev, n, res[n]);
if (ret)
goto err_kms;
}
#ifdef CONFIG_DRM_ARMADA_TDA1998X
ret = armada_drm_connector_slave_create(dev, &tda19988_config);
if (ret)
goto err_kms;
#endif
ret = drm_vblank_init(dev, n);
if (ret)
goto err_kms;
ret = drm_irq_install(dev);
if (ret)
goto err_kms;
dev->vblank_disable_allowed = 1;
ret = armada_fbdev_init(dev);
if (ret)
goto err_irq;
drm_kms_helper_poll_init(dev);
return 0;
err_irq:
drm_irq_uninstall(dev);
err_kms:
drm_mode_config_cleanup(dev);
drm_mm_takedown(&priv->linear);
flush_work(&priv->fb_unref_work);
return ret;
}
static int armada_drm_unload(struct drm_device *dev)
{
struct armada_private *priv = dev->dev_private;
drm_kms_helper_poll_fini(dev);
armada_fbdev_fini(dev);
drm_irq_uninstall(dev);
drm_mode_config_cleanup(dev);
drm_mm_takedown(&priv->linear);
flush_work(&priv->fb_unref_work);
dev->dev_private = NULL;
return 0;
}
void armada_drm_vbl_event_add(struct armada_crtc *dcrtc,
struct armada_vbl_event *evt)
{
unsigned long flags;
spin_lock_irqsave(&dcrtc->irq_lock, flags);
if (list_empty(&evt->node)) {
list_add_tail(&evt->node, &dcrtc->vbl_list);
drm_vblank_get(dcrtc->crtc.dev, dcrtc->num);
}
spin_unlock_irqrestore(&dcrtc->irq_lock, flags);
}
void armada_drm_vbl_event_remove(struct armada_crtc *dcrtc,
struct armada_vbl_event *evt)
{
if (!list_empty(&evt->node)) {
list_del_init(&evt->node);
drm_vblank_put(dcrtc->crtc.dev, dcrtc->num);
}
}
void armada_drm_vbl_event_remove_unlocked(struct armada_crtc *dcrtc,
struct armada_vbl_event *evt)
{
unsigned long flags;
spin_lock_irqsave(&dcrtc->irq_lock, flags);
armada_drm_vbl_event_remove(dcrtc, evt);
spin_unlock_irqrestore(&dcrtc->irq_lock, flags);
}
static int armada_drm_enable_vblank(struct drm_device *dev, int crtc)
{
struct armada_private *priv = dev->dev_private;
armada_drm_crtc_enable_irq(priv->dcrtc[crtc], VSYNC_IRQ_ENA);
return 0;
}
static void armada_drm_disable_vblank(struct drm_device *dev, int crtc)
{
struct armada_private *priv = dev->dev_private;
armada_drm_crtc_disable_irq(priv->dcrtc[crtc], VSYNC_IRQ_ENA);
}
static irqreturn_t armada_drm_irq_handler(int irq, void *arg)
{
struct drm_device *dev = arg;
struct armada_private *priv = dev->dev_private;
struct armada_crtc *dcrtc = priv->dcrtc[0];
uint32_t v, stat = readl_relaxed(dcrtc->base + LCD_SPU_IRQ_ISR);
irqreturn_t handled = IRQ_NONE;
writel_relaxed(0, dcrtc->base + LCD_SPU_IRQ_ISR);
v = stat & dcrtc->irq_ena;
if (v & (VSYNC_IRQ|GRA_FRAME_IRQ|DUMB_FRAMEDONE)) {
armada_drm_crtc_irq(dcrtc, stat);
handled = IRQ_HANDLED;
}
return handled;
}
static int armada_drm_irq_postinstall(struct drm_device *dev)
{
struct armada_private *priv = dev->dev_private;
struct armada_crtc *dcrtc = priv->dcrtc[0];
spin_lock_irq(&dev->vbl_lock);
writel_relaxed(dcrtc->irq_ena, dcrtc->base + LCD_SPU_IRQ_ENA);
writel(0, dcrtc->base + LCD_SPU_IRQ_ISR);
spin_unlock_irq(&dev->vbl_lock);
return 0;
}
static void armada_drm_irq_uninstall(struct drm_device *dev)
{
struct armada_private *priv = dev->dev_private;
struct armada_crtc *dcrtc = priv->dcrtc[0];
writel(0, dcrtc->base + LCD_SPU_IRQ_ENA);
}
static void armada_drm_lastclose(struct drm_device *dev)
{
armada_fbdev_lastclose(dev);
}
static int armada_drm_probe(struct platform_device *pdev)
{
return drm_platform_init(&armada_drm_driver, pdev);
}
static int armada_drm_remove(struct platform_device *pdev)
{
drm_put_dev(platform_get_drvdata(pdev));
return 0;
}
static int __init armada_drm_init(void)
{
armada_drm_driver.num_ioctls = DRM_ARRAY_SIZE(armada_ioctls);
return platform_driver_register(&armada_drm_platform_driver);
}
static void __exit armada_drm_exit(void)
{
platform_driver_unregister(&armada_drm_platform_driver);
}
