static struct platform_device *
lpe_audio_platdev_create(struct drm_i915_private *dev_priv)
{
int ret;
struct drm_device *dev = &dev_priv->drm;
struct platform_device_info pinfo = {};
struct resource *rsc;
struct platform_device *platdev;
struct intel_hdmi_lpe_audio_pdata *pdata;
pdata = kzalloc(sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return ERR_PTR(-ENOMEM);
rsc = kcalloc(2, sizeof(*rsc), GFP_KERNEL);
if (!rsc) {
kfree(pdata);
return ERR_PTR(-ENOMEM);
}
rsc[0].start = rsc[0].end = dev_priv->lpe_audio.irq;
rsc[0].flags = IORESOURCE_IRQ;
rsc[0].name = "hdmi-lpe-audio-irq";
rsc[1].start = pci_resource_start(dev->pdev, 0) +
I915_HDMI_LPE_AUDIO_BASE;
rsc[1].end = pci_resource_start(dev->pdev, 0) +
I915_HDMI_LPE_AUDIO_BASE + I915_HDMI_LPE_AUDIO_SIZE - 1;
rsc[1].flags = IORESOURCE_MEM;
rsc[1].name = "hdmi-lpe-audio-mmio";
pinfo.parent = dev->dev;
pinfo.name = "hdmi-lpe-audio";
pinfo.id = -1;
pinfo.res = rsc;
pinfo.num_res = 2;
pinfo.data = pdata;
pinfo.size_data = sizeof(*pdata);
pinfo.dma_mask = DMA_BIT_MASK(32);
spin_lock_init(&pdata->lpe_audio_slock);
platdev = platform_device_register_full(&pinfo);
if (IS_ERR(platdev)) {
ret = PTR_ERR(platdev);
DRM_ERROR("Failed to allocate LPE audio platform device\n");
goto err;
}
kfree(rsc);
pm_runtime_forbid(&platdev->dev);
pm_runtime_set_active(&platdev->dev);
pm_runtime_enable(&platdev->dev);
return platdev;
err:
kfree(rsc);
kfree(pdata);
return ERR_PTR(ret);
}
static void lpe_audio_platdev_destroy(struct drm_i915_private *dev_priv)
{
platform_device_unregister(dev_priv->lpe_audio.platdev);
}
static void lpe_audio_irq_unmask(struct irq_data *d)
{
}
static void lpe_audio_irq_mask(struct irq_data *d)
{
}
static int lpe_audio_irq_init(struct drm_i915_private *dev_priv)
{
int irq = dev_priv->lpe_audio.irq;
WARN_ON(!intel_irqs_enabled(dev_priv));
irq_set_chip_and_handler_name(irq,
&lpe_audio_irqchip,
handle_simple_irq,
"hdmi_lpe_audio_irq_handler");
return irq_set_chip_data(irq, dev_priv);
}
static bool lpe_audio_detect(struct drm_i915_private *dev_priv)
{
int lpe_present = false;
if (IS_VALLEYVIEW(dev_priv) || IS_CHERRYVIEW(dev_priv)) {
static const struct pci_device_id atom_hdaudio_ids[] = {
{PCI_DEVICE(PCI_VENDOR_ID_INTEL, 0x0f04)},
{PCI_DEVICE(PCI_VENDOR_ID_INTEL, 0x2284)},
{}
};
if (!pci_dev_present(atom_hdaudio_ids)) {
DRM_INFO("%s\n", "HDaudio controller not detected, using LPE audio instead\n");
lpe_present = true;
}
}
return lpe_present;
}
static int lpe_audio_setup(struct drm_i915_private *dev_priv)
{
int ret;
dev_priv->lpe_audio.irq = irq_alloc_desc(0);
if (dev_priv->lpe_audio.irq < 0) {
DRM_ERROR("Failed to allocate IRQ desc: %d\n",
dev_priv->lpe_audio.irq);
ret = dev_priv->lpe_audio.irq;
goto err;
}
DRM_DEBUG("irq = %d\n", dev_priv->lpe_audio.irq);
ret = lpe_audio_irq_init(dev_priv);
if (ret) {
DRM_ERROR("Failed to initialize irqchip for lpe audio: %d\n",
ret);
goto err_free_irq;
}
dev_priv->lpe_audio.platdev = lpe_audio_platdev_create(dev_priv);
if (IS_ERR(dev_priv->lpe_audio.platdev)) {
ret = PTR_ERR(dev_priv->lpe_audio.platdev);
DRM_ERROR("Failed to create lpe audio platform device: %d\n",
ret);
goto err_free_irq;
}
I915_WRITE(VLV_AUD_CHICKEN_BIT_REG, VLV_CHICKEN_BIT_DBG_ENABLE);
return 0;
err_free_irq:
irq_free_desc(dev_priv->lpe_audio.irq);
err:
dev_priv->lpe_audio.irq = -1;
dev_priv->lpe_audio.platdev = NULL;
return ret;
}
void intel_lpe_audio_irq_handler(struct drm_i915_private *dev_priv)
{
int ret;
if (!HAS_LPE_AUDIO(dev_priv))
return;
ret = generic_handle_irq(dev_priv->lpe_audio.irq);
if (ret)
DRM_ERROR_RATELIMITED("error handling LPE audio irq: %d\n",
ret);
}
int intel_lpe_audio_init(struct drm_i915_private *dev_priv)
{
int ret = -ENODEV;
if (lpe_audio_detect(dev_priv)) {
ret = lpe_audio_setup(dev_priv);
if (ret < 0)
DRM_ERROR("failed to setup LPE Audio bridge\n");
}
return ret;
}
void intel_lpe_audio_teardown(struct drm_i915_private *dev_priv)
{
struct irq_desc *desc;
if (!HAS_LPE_AUDIO(dev_priv))
return;
desc = irq_to_desc(dev_priv->lpe_audio.irq);
lpe_audio_platdev_destroy(dev_priv);
irq_free_desc(dev_priv->lpe_audio.irq);
}
void intel_lpe_audio_notify(struct drm_i915_private *dev_priv,
void *eld, int port, int pipe, int tmds_clk_speed,
bool dp_output, int link_rate)
{
unsigned long irq_flags;
struct intel_hdmi_lpe_audio_pdata *pdata = NULL;
u32 audio_enable;
if (!HAS_LPE_AUDIO(dev_priv))
return;
pdata = dev_get_platdata(
&(dev_priv->lpe_audio.platdev->dev));
spin_lock_irqsave(&pdata->lpe_audio_slock, irq_flags);
audio_enable = I915_READ(VLV_AUD_PORT_EN_DBG(port));
if (eld != NULL) {
memcpy(pdata->eld.eld_data, eld,
HDMI_MAX_ELD_BYTES);
pdata->eld.port_id = port;
pdata->eld.pipe_id = pipe;
pdata->hdmi_connected = true;
pdata->dp_output = dp_output;
if (tmds_clk_speed)
pdata->tmds_clock_speed = tmds_clk_speed;
if (link_rate)
pdata->link_rate = link_rate;
I915_WRITE(VLV_AUD_PORT_EN_DBG(port),
audio_enable & ~VLV_AMP_MUTE);
} else {
memset(pdata->eld.eld_data, 0,
HDMI_MAX_ELD_BYTES);
pdata->hdmi_connected = false;
pdata->dp_output = false;
I915_WRITE(VLV_AUD_PORT_EN_DBG(port),
audio_enable | VLV_AMP_MUTE);
}
if (pdata->notify_audio_lpe)
pdata->notify_audio_lpe(dev_priv->lpe_audio.platdev);
else
pdata->notify_pending = true;
spin_unlock_irqrestore(&pdata->lpe_audio_slock,
irq_flags);
}
