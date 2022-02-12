void vc4_hvs_dump_state(struct drm_device *dev)
{
struct vc4_dev *vc4 = to_vc4_dev(dev);
int i;
for (i = 0; i < ARRAY_SIZE(hvs_regs); i++) {
DRM_INFO("0x%04x (%s): 0x%08x\n",
hvs_regs[i].reg, hvs_regs[i].name,
HVS_READ(hvs_regs[i].reg));
}
DRM_INFO("HVS ctx:\n");
for (i = 0; i < 64; i += 4) {
DRM_INFO("0x%08x (%s): 0x%08x 0x%08x 0x%08x 0x%08x\n",
i * 4, i < HVS_BOOTLOADER_DLIST_END ? "B" : "D",
readl((u32 __iomem *)vc4->hvs->dlist + i + 0),
readl((u32 __iomem *)vc4->hvs->dlist + i + 1),
readl((u32 __iomem *)vc4->hvs->dlist + i + 2),
readl((u32 __iomem *)vc4->hvs->dlist + i + 3));
}
}
int vc4_hvs_debugfs_regs(struct seq_file *m, void *unused)
{
struct drm_info_node *node = (struct drm_info_node *)m->private;
struct drm_device *dev = node->minor->dev;
struct vc4_dev *vc4 = to_vc4_dev(dev);
int i;
for (i = 0; i < ARRAY_SIZE(hvs_regs); i++) {
seq_printf(m, "%s (0x%04x): 0x%08x\n",
hvs_regs[i].name, hvs_regs[i].reg,
HVS_READ(hvs_regs[i].reg));
}
return 0;
}
static int vc4_hvs_bind(struct device *dev, struct device *master, void *data)
{
struct platform_device *pdev = to_platform_device(dev);
struct drm_device *drm = dev_get_drvdata(master);
struct vc4_dev *vc4 = drm->dev_private;
struct vc4_hvs *hvs = NULL;
hvs = devm_kzalloc(&pdev->dev, sizeof(*hvs), GFP_KERNEL);
if (!hvs)
return -ENOMEM;
hvs->pdev = pdev;
hvs->regs = vc4_ioremap_regs(pdev, 0);
if (IS_ERR(hvs->regs))
return PTR_ERR(hvs->regs);
hvs->dlist = hvs->regs + SCALER_DLIST_START;
vc4->hvs = hvs;
return 0;
}
static void vc4_hvs_unbind(struct device *dev, struct device *master,
void *data)
{
struct drm_device *drm = dev_get_drvdata(master);
struct vc4_dev *vc4 = drm->dev_private;
vc4->hvs = NULL;
}
static int vc4_hvs_dev_probe(struct platform_device *pdev)
{
return component_add(&pdev->dev, &vc4_hvs_ops);
}
static int vc4_hvs_dev_remove(struct platform_device *pdev)
{
component_del(&pdev->dev, &vc4_hvs_ops);
return 0;
}
