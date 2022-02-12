int
nv50_mc_init(struct drm_device *dev)
{
nv_wr32(dev, NV03_PMC_ENABLE, 0xFFFFFFFF);
return 0;
}
void nv50_mc_takedown(struct drm_device *dev)
{
}
