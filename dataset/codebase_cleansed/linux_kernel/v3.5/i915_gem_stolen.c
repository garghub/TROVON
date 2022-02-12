static unsigned long i915_stolen_to_phys(struct drm_device *dev, u32 offset)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct pci_dev *pdev = dev_priv->bridge_dev;
u32 base;
#if 0
if (INTEL_INFO(dev)->gen > 3 || IS_G33(dev)) {
pci_read_config_dword(pdev, 0xA4, &base);
} else {
pci_bus_read_config_dword(pdev->bus, 2, 0x5C, &base);
}
#else
if (INTEL_INFO(dev)->gen > 3 || IS_G33(dev)) {
u16 val;
pci_read_config_word(pdev, 0xb0, &val);
base = val >> 4 << 20;
} else {
u8 val;
pci_read_config_byte(pdev, 0x9c, &val);
base = val >> 3 << 27;
}
base -= dev_priv->mm.gtt->stolen_size;
#endif
return base + offset;
}
static void i915_warn_stolen(struct drm_device *dev)
{
DRM_INFO("not enough stolen space for compressed buffer, disabling\n");
DRM_INFO("hint: you may be able to increase stolen memory size in the BIOS to avoid this\n");
}
static void i915_setup_compression(struct drm_device *dev, int size)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_mm_node *compressed_fb, *uninitialized_var(compressed_llb);
unsigned long cfb_base;
unsigned long ll_base = 0;
intel_disable_fbc(dev);
compressed_fb = drm_mm_search_free(&dev_priv->mm.stolen, size, 4096, 0);
if (compressed_fb)
compressed_fb = drm_mm_get_block(compressed_fb, size, 4096);
if (!compressed_fb)
goto err;
cfb_base = i915_stolen_to_phys(dev, compressed_fb->start);
if (!cfb_base)
goto err_fb;
if (!(IS_GM45(dev) || HAS_PCH_SPLIT(dev))) {
compressed_llb = drm_mm_search_free(&dev_priv->mm.stolen,
4096, 4096, 0);
if (compressed_llb)
compressed_llb = drm_mm_get_block(compressed_llb,
4096, 4096);
if (!compressed_llb)
goto err_fb;
ll_base = i915_stolen_to_phys(dev, compressed_llb->start);
if (!ll_base)
goto err_llb;
}
dev_priv->cfb_size = size;
dev_priv->compressed_fb = compressed_fb;
if (HAS_PCH_SPLIT(dev))
I915_WRITE(ILK_DPFC_CB_BASE, compressed_fb->start);
else if (IS_GM45(dev)) {
I915_WRITE(DPFC_CB_BASE, compressed_fb->start);
} else {
I915_WRITE(FBC_CFB_BASE, cfb_base);
I915_WRITE(FBC_LL_BASE, ll_base);
dev_priv->compressed_llb = compressed_llb;
}
DRM_DEBUG_KMS("FBC base 0x%08lx, ll base 0x%08lx, size %dM\n",
cfb_base, ll_base, size >> 20);
return;
err_llb:
drm_mm_put_block(compressed_llb);
err_fb:
drm_mm_put_block(compressed_fb);
err:
dev_priv->no_fbc_reason = FBC_STOLEN_TOO_SMALL;
i915_warn_stolen(dev);
}
static void i915_cleanup_compression(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
drm_mm_put_block(dev_priv->compressed_fb);
if (dev_priv->compressed_llb)
drm_mm_put_block(dev_priv->compressed_llb);
}
void i915_gem_cleanup_stolen(struct drm_device *dev)
{
if (I915_HAS_FBC(dev) && i915_powersave)
i915_cleanup_compression(dev);
}
int i915_gem_init_stolen(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
unsigned long prealloc_size = dev_priv->mm.gtt->stolen_size;
drm_mm_init(&dev_priv->mm.stolen, 0, prealloc_size);
if (I915_HAS_FBC(dev) && i915_powersave) {
int cfb_size;
if (prealloc_size > (36*1024*1024))
cfb_size = 32*1024*1024;
else
cfb_size = prealloc_size * 7 / 8;
i915_setup_compression(dev, cfb_size);
}
return 0;
}
