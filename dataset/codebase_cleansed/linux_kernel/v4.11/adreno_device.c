static inline bool _rev_match(uint8_t entry, uint8_t id)
{
return (entry == ANY_ID) || (entry == id);
}
const struct adreno_info *adreno_info(struct adreno_rev rev)
{
int i;
for (i = 0; i < ARRAY_SIZE(gpulist); i++) {
const struct adreno_info *info = &gpulist[i];
if (_rev_match(info->rev.core, rev.core) &&
_rev_match(info->rev.major, rev.major) &&
_rev_match(info->rev.minor, rev.minor) &&
_rev_match(info->rev.patchid, rev.patchid))
return info;
}
return NULL;
}
struct msm_gpu *adreno_load_gpu(struct drm_device *dev)
{
struct msm_drm_private *priv = dev->dev_private;
struct platform_device *pdev = priv->gpu_pdev;
struct adreno_platform_config *config;
struct adreno_rev rev;
const struct adreno_info *info;
struct msm_gpu *gpu = NULL;
if (!pdev) {
dev_err(dev->dev, "no adreno device\n");
return NULL;
}
config = pdev->dev.platform_data;
rev = config->rev;
info = adreno_info(config->rev);
if (!info) {
dev_warn(dev->dev, "Unknown GPU revision: %u.%u.%u.%u\n",
rev.core, rev.major, rev.minor, rev.patchid);
return NULL;
}
DBG("Found GPU: %u.%u.%u.%u", rev.core, rev.major,
rev.minor, rev.patchid);
gpu = info->init(dev);
if (IS_ERR(gpu)) {
dev_warn(dev->dev, "failed to load adreno gpu\n");
gpu = NULL;
}
if (gpu) {
int ret;
mutex_lock(&dev->struct_mutex);
gpu->funcs->pm_resume(gpu);
mutex_unlock(&dev->struct_mutex);
disable_irq(gpu->irq);
ret = gpu->funcs->hw_init(gpu);
if (ret) {
dev_err(dev->dev, "gpu hw init failed: %d\n", ret);
gpu->funcs->destroy(gpu);
gpu = NULL;
} else {
enable_irq(gpu->irq);
msm_gpu_retire(gpu);
}
}
return gpu;
}
static void set_gpu_pdev(struct drm_device *dev,
struct platform_device *pdev)
{
struct msm_drm_private *priv = dev->dev_private;
priv->gpu_pdev = pdev;
}
static int find_chipid(struct device *dev, u32 *chipid)
{
struct device_node *node = dev->of_node;
const char *compat;
int ret;
ret = of_property_read_string_index(node, "compatible", 0, &compat);
if (ret == 0) {
unsigned rev, patch;
if (sscanf(compat, "qcom,adreno-%u.%u", &rev, &patch) == 2) {
*chipid = 0;
*chipid |= (rev / 100) << 24;
rev %= 100;
*chipid |= (rev / 10) << 16;
rev %= 10;
*chipid |= rev << 8;
*chipid |= patch;
return 0;
}
}
ret = of_property_read_u32(node, "qcom,chipid", chipid);
if (ret)
return ret;
dev_warn(dev, "Using legacy qcom,chipid binding!\n");
dev_warn(dev, "Use compatible qcom,adreno-%u%u%u.%u instead.\n",
(*chipid >> 24) & 0xff, (*chipid >> 16) & 0xff,
(*chipid >> 8) & 0xff, *chipid & 0xff);
return 0;
}
static int adreno_bind(struct device *dev, struct device *master, void *data)
{
static struct adreno_platform_config config = {};
struct device_node *child, *node = dev->of_node;
u32 val;
int ret;
ret = find_chipid(dev, &val);
if (ret) {
dev_err(dev, "could not find chipid: %d\n", ret);
return ret;
}
config.rev = ADRENO_REV((val >> 24) & 0xff,
(val >> 16) & 0xff, (val >> 8) & 0xff, val & 0xff);
config.fast_rate = 0;
config.slow_rate = ~0;
for_each_child_of_node(node, child) {
if (of_device_is_compatible(child, "qcom,gpu-pwrlevels")) {
struct device_node *pwrlvl;
for_each_child_of_node(child, pwrlvl) {
ret = of_property_read_u32(pwrlvl, "qcom,gpu-freq", &val);
if (ret) {
dev_err(dev, "could not find gpu-freq: %d\n", ret);
return ret;
}
config.fast_rate = max(config.fast_rate, val);
config.slow_rate = min(config.slow_rate, val);
}
}
}
if (!config.fast_rate) {
dev_warn(dev, "could not find clk rates\n");
config.fast_rate = 200000000;
config.slow_rate = 27000000;
}
dev->platform_data = &config;
set_gpu_pdev(dev_get_drvdata(master), to_platform_device(dev));
return 0;
}
static void adreno_unbind(struct device *dev, struct device *master,
void *data)
{
set_gpu_pdev(dev_get_drvdata(master), NULL);
}
static int adreno_probe(struct platform_device *pdev)
{
return component_add(&pdev->dev, &a3xx_ops);
}
static int adreno_remove(struct platform_device *pdev)
{
component_del(&pdev->dev, &a3xx_ops);
return 0;
}
void __init adreno_register(void)
{
platform_driver_register(&adreno_driver);
}
void __exit adreno_unregister(void)
{
platform_driver_unregister(&adreno_driver);
}
