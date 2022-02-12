const struct mdp5_cfg_hw *mdp5_cfg_get_hw_config(struct mdp5_cfg_handler *cfg_handler)
{
return cfg_handler->config.hw;
}
struct mdp5_cfg *mdp5_cfg_get_config(struct mdp5_cfg_handler *cfg_handler)
{
return &cfg_handler->config;
}
int mdp5_cfg_get_hw_rev(struct mdp5_cfg_handler *cfg_handler)
{
return cfg_handler->revision;
}
void mdp5_cfg_destroy(struct mdp5_cfg_handler *cfg_handler)
{
kfree(cfg_handler);
}
struct mdp5_cfg_handler *mdp5_cfg_init(struct mdp5_kms *mdp5_kms,
uint32_t major, uint32_t minor)
{
struct drm_device *dev = mdp5_kms->dev;
struct platform_device *pdev = to_platform_device(dev->dev);
struct mdp5_cfg_handler *cfg_handler;
struct mdp5_cfg_platform *pconfig;
int i, ret = 0;
cfg_handler = kzalloc(sizeof(*cfg_handler), GFP_KERNEL);
if (unlikely(!cfg_handler)) {
ret = -ENOMEM;
goto fail;
}
if (major != 1) {
dev_err(dev->dev, "unexpected MDP major version: v%d.%d\n",
major, minor);
ret = -ENXIO;
goto fail;
}
for (i = 0; i < ARRAY_SIZE(cfg_handlers); i++) {
if (cfg_handlers[i].revision != minor)
continue;
mdp5_cfg = cfg_handlers[i].config.hw;
break;
}
if (unlikely(!mdp5_cfg)) {
dev_err(dev->dev, "unexpected MDP minor revision: v%d.%d\n",
major, minor);
ret = -ENXIO;
goto fail;
}
cfg_handler->revision = minor;
cfg_handler->config.hw = mdp5_cfg;
pconfig = mdp5_get_config(pdev);
memcpy(&cfg_handler->config.platform, pconfig, sizeof(*pconfig));
DBG("MDP5: %s hw config selected", mdp5_cfg->name);
return cfg_handler;
fail:
if (cfg_handler)
mdp5_cfg_destroy(cfg_handler);
return NULL;
}
static struct mdp5_cfg_platform *mdp5_get_config(struct platform_device *dev)
{
static struct mdp5_cfg_platform config = {};
config.iommu = iommu_domain_alloc(&platform_bus_type);
if (config.iommu) {
config.iommu->geometry.aperture_start = 0x1000;
config.iommu->geometry.aperture_end = 0xffffffff;
}
return &config;
}
