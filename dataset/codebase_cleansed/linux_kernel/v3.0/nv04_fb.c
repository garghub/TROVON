int
nv04_fb_init(struct drm_device *dev)
{
nv_wr32(dev, NV04_PFB_CFG0, 0x1114);
return 0;
}
void
nv04_fb_takedown(struct drm_device *dev)
{
}
