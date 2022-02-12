static int mdp5_hw_init(struct msm_kms *kms)
{
struct mdp5_kms *mdp5_kms = to_mdp5_kms(to_mdp_kms(kms));
struct drm_device *dev = mdp5_kms->dev;
uint32_t version, major, minor;
int ret = 0;
pm_runtime_get_sync(dev->dev);
mdp5_enable(mdp5_kms);
version = mdp5_read(mdp5_kms, REG_MDP5_MDP_VERSION);
mdp5_disable(mdp5_kms);
major = FIELD(version, MDP5_MDP_VERSION_MAJOR);
minor = FIELD(version, MDP5_MDP_VERSION_MINOR);
DBG("found MDP5 version v%d.%d", major, minor);
if ((major != 1) || ((minor != 0) && (minor != 2))) {
dev_err(dev->dev, "unexpected MDP version: v%d.%d\n",
major, minor);
ret = -ENXIO;
goto out;
}
mdp5_kms->rev = minor;
mdp5_write(mdp5_kms, REG_MDP5_DISP_INTF_SEL, 0);
mdp5_write(mdp5_kms, REG_MDP5_CTL_OP(0), 0);
mdp5_write(mdp5_kms, REG_MDP5_CTL_OP(1), 0);
mdp5_write(mdp5_kms, REG_MDP5_CTL_OP(2), 0);
mdp5_write(mdp5_kms, REG_MDP5_CTL_OP(3), 0);
out:
pm_runtime_put_sync(dev->dev);
return ret;
}
static long mdp5_round_pixclk(struct msm_kms *kms, unsigned long rate,
struct drm_encoder *encoder)
{
return rate;
}
static void mdp5_preclose(struct msm_kms *kms, struct drm_file *file)
{
struct mdp5_kms *mdp5_kms = to_mdp5_kms(to_mdp_kms(kms));
struct msm_drm_private *priv = mdp5_kms->dev->dev_private;
unsigned i;
for (i = 0; i < priv->num_crtcs; i++)
mdp5_crtc_cancel_pending_flip(priv->crtcs[i], file);
}
static void mdp5_destroy(struct msm_kms *kms)
{
struct mdp5_kms *mdp5_kms = to_mdp5_kms(to_mdp_kms(kms));
kfree(mdp5_kms);
}
int mdp5_disable(struct mdp5_kms *mdp5_kms)
{
DBG("");
clk_disable_unprepare(mdp5_kms->ahb_clk);
clk_disable_unprepare(mdp5_kms->axi_clk);
clk_disable_unprepare(mdp5_kms->core_clk);
clk_disable_unprepare(mdp5_kms->lut_clk);
return 0;
}
int mdp5_enable(struct mdp5_kms *mdp5_kms)
{
DBG("");
clk_prepare_enable(mdp5_kms->ahb_clk);
clk_prepare_enable(mdp5_kms->axi_clk);
clk_prepare_enable(mdp5_kms->core_clk);
clk_prepare_enable(mdp5_kms->lut_clk);
return 0;
}
static int modeset_init(struct mdp5_kms *mdp5_kms)
{
static const enum mdp5_pipe crtcs[] = {
SSPP_RGB0, SSPP_RGB1, SSPP_RGB2,
};
struct drm_device *dev = mdp5_kms->dev;
struct msm_drm_private *priv = dev->dev_private;
struct drm_encoder *encoder;
int i, ret;
for (i = 0; i < ARRAY_SIZE(crtcs); i++) {
struct drm_plane *plane;
struct drm_crtc *crtc;
plane = mdp5_plane_init(dev, crtcs[i], true);
if (IS_ERR(plane)) {
ret = PTR_ERR(plane);
dev_err(dev->dev, "failed to construct plane for %s (%d)\n",
pipe2name(crtcs[i]), ret);
goto fail;
}
crtc = mdp5_crtc_init(dev, plane, i);
if (IS_ERR(crtc)) {
ret = PTR_ERR(crtc);
dev_err(dev->dev, "failed to construct crtc for %s (%d)\n",
pipe2name(crtcs[i]), ret);
goto fail;
}
priv->crtcs[priv->num_crtcs++] = crtc;
}
encoder = mdp5_encoder_init(dev, 3, INTF_HDMI);
if (IS_ERR(encoder)) {
dev_err(dev->dev, "failed to construct encoder\n");
ret = PTR_ERR(encoder);
goto fail;
}
encoder->possible_crtcs = BIT(0);
mdp5_crtc_set_intf(priv->crtcs[0], 3, INTF_HDMI);
priv->encoders[priv->num_encoders++] = encoder;
mdp5_kms->hdmi = hdmi_init(dev, encoder);
if (IS_ERR(mdp5_kms->hdmi)) {
ret = PTR_ERR(mdp5_kms->hdmi);
dev_err(dev->dev, "failed to initialize HDMI: %d\n", ret);
goto fail;
}
return 0;
fail:
return ret;
}
static int get_clk(struct platform_device *pdev, struct clk **clkp,
const char *name)
{
struct device *dev = &pdev->dev;
struct clk *clk = devm_clk_get(dev, name);
if (IS_ERR(clk)) {
dev_err(dev, "failed to get %s (%ld)\n", name, PTR_ERR(clk));
return PTR_ERR(clk);
}
*clkp = clk;
return 0;
}
struct msm_kms *mdp5_kms_init(struct drm_device *dev)
{
struct platform_device *pdev = dev->platformdev;
struct mdp5_platform_config *config = mdp5_get_config(pdev);
struct mdp5_kms *mdp5_kms;
struct msm_kms *kms = NULL;
struct msm_mmu *mmu;
int ret;
mdp5_kms = kzalloc(sizeof(*mdp5_kms), GFP_KERNEL);
if (!mdp5_kms) {
dev_err(dev->dev, "failed to allocate kms\n");
ret = -ENOMEM;
goto fail;
}
mdp_kms_init(&mdp5_kms->base, &kms_funcs);
kms = &mdp5_kms->base.base;
mdp5_kms->dev = dev;
mdp5_kms->smp_blk_cnt = config->smp_blk_cnt;
mdp5_kms->mmio = msm_ioremap(pdev, "mdp_phys", "MDP5");
if (IS_ERR(mdp5_kms->mmio)) {
ret = PTR_ERR(mdp5_kms->mmio);
goto fail;
}
mdp5_kms->vbif = msm_ioremap(pdev, "vbif_phys", "VBIF");
if (IS_ERR(mdp5_kms->vbif)) {
ret = PTR_ERR(mdp5_kms->vbif);
goto fail;
}
mdp5_kms->vdd = devm_regulator_get(&pdev->dev, "vdd");
if (IS_ERR(mdp5_kms->vdd)) {
ret = PTR_ERR(mdp5_kms->vdd);
goto fail;
}
ret = regulator_enable(mdp5_kms->vdd);
if (ret) {
dev_err(dev->dev, "failed to enable regulator vdd: %d\n", ret);
goto fail;
}
ret = get_clk(pdev, &mdp5_kms->axi_clk, "bus_clk") ||
get_clk(pdev, &mdp5_kms->ahb_clk, "iface_clk") ||
get_clk(pdev, &mdp5_kms->src_clk, "core_clk_src") ||
get_clk(pdev, &mdp5_kms->core_clk, "core_clk") ||
get_clk(pdev, &mdp5_kms->lut_clk, "lut_clk") ||
get_clk(pdev, &mdp5_kms->vsync_clk, "vsync_clk");
if (ret)
goto fail;
ret = clk_set_rate(mdp5_kms->src_clk, config->max_clk);
mdp5_enable(mdp5_kms);
mdp5_write(mdp5_kms, REG_MDP5_INTF_TIMING_ENGINE_EN(0), 0);
mdp5_write(mdp5_kms, REG_MDP5_INTF_TIMING_ENGINE_EN(1), 0);
mdp5_write(mdp5_kms, REG_MDP5_INTF_TIMING_ENGINE_EN(2), 0);
mdp5_write(mdp5_kms, REG_MDP5_INTF_TIMING_ENGINE_EN(3), 0);
mdp5_disable(mdp5_kms);
mdelay(16);
if (config->iommu) {
mmu = msm_iommu_new(dev, config->iommu);
if (IS_ERR(mmu)) {
ret = PTR_ERR(mmu);
goto fail;
}
ret = mmu->funcs->attach(mmu, iommu_ports,
ARRAY_SIZE(iommu_ports));
if (ret)
goto fail;
} else {
dev_info(dev->dev, "no iommu, fallback to phys "
"contig buffers for scanout\n");
mmu = NULL;
}
mdp5_kms->id = msm_register_mmu(dev, mmu);
if (mdp5_kms->id < 0) {
ret = mdp5_kms->id;
dev_err(dev->dev, "failed to register mdp5 iommu: %d\n", ret);
goto fail;
}
ret = modeset_init(mdp5_kms);
if (ret) {
dev_err(dev->dev, "modeset_init failed: %d\n", ret);
goto fail;
}
return kms;
fail:
if (kms)
mdp5_destroy(kms);
return ERR_PTR(ret);
}
static struct mdp5_platform_config *mdp5_get_config(struct platform_device *dev)
{
static struct mdp5_platform_config config = {};
#ifdef CONFIG_OF
#endif
return &config;
}
