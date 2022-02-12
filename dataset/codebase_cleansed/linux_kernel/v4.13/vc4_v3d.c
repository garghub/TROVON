int vc4_v3d_debugfs_regs(struct seq_file *m, void *unused)
{
struct drm_info_node *node = (struct drm_info_node *)m->private;
struct drm_device *dev = node->minor->dev;
struct vc4_dev *vc4 = to_vc4_dev(dev);
int i;
for (i = 0; i < ARRAY_SIZE(vc4_reg_defs); i++) {
seq_printf(m, "%s (0x%04x): 0x%08x\n",
vc4_reg_defs[i].name, vc4_reg_defs[i].reg,
V3D_READ(vc4_reg_defs[i].reg));
}
return 0;
}
int vc4_v3d_debugfs_ident(struct seq_file *m, void *unused)
{
struct drm_info_node *node = (struct drm_info_node *)m->private;
struct drm_device *dev = node->minor->dev;
struct vc4_dev *vc4 = to_vc4_dev(dev);
uint32_t ident1 = V3D_READ(V3D_IDENT1);
uint32_t nslc = VC4_GET_FIELD(ident1, V3D_IDENT1_NSLC);
uint32_t tups = VC4_GET_FIELD(ident1, V3D_IDENT1_TUPS);
uint32_t qups = VC4_GET_FIELD(ident1, V3D_IDENT1_QUPS);
seq_printf(m, "Revision: %d\n",
VC4_GET_FIELD(ident1, V3D_IDENT1_REV));
seq_printf(m, "Slices: %d\n", nslc);
seq_printf(m, "TMUs: %d\n", nslc * tups);
seq_printf(m, "QPUs: %d\n", nslc * qups);
seq_printf(m, "Semaphores: %d\n",
VC4_GET_FIELD(ident1, V3D_IDENT1_NSEM));
return 0;
}
static void vc4_v3d_init_hw(struct drm_device *dev)
{
struct vc4_dev *vc4 = to_vc4_dev(dev);
V3D_WRITE(V3D_VPMBASE, 0);
}
int vc4_v3d_get_bin_slot(struct vc4_dev *vc4)
{
struct drm_device *dev = vc4->dev;
unsigned long irqflags;
int slot;
uint64_t seqno = 0;
struct vc4_exec_info *exec;
try_again:
spin_lock_irqsave(&vc4->job_lock, irqflags);
slot = ffs(~vc4->bin_alloc_used);
if (slot != 0) {
slot--;
vc4->bin_alloc_used |= BIT(slot);
spin_unlock_irqrestore(&vc4->job_lock, irqflags);
return slot;
}
exec = vc4_last_render_job(vc4);
if (exec)
seqno = exec->seqno;
spin_unlock_irqrestore(&vc4->job_lock, irqflags);
if (seqno) {
int ret = vc4_wait_for_seqno(dev, seqno, ~0ull, true);
if (ret == 0)
goto try_again;
return ret;
}
return -ENOMEM;
}
int
vc4_allocate_bin_bo(struct drm_device *drm)
{
struct vc4_dev *vc4 = to_vc4_dev(drm);
struct vc4_v3d *v3d = vc4->v3d;
uint32_t size = 16 * 1024 * 1024;
int ret = 0;
struct list_head list;
INIT_LIST_HEAD(&list);
while (true) {
struct vc4_bo *bo = vc4_bo_create(drm, size, true);
if (IS_ERR(bo)) {
ret = PTR_ERR(bo);
dev_err(&v3d->pdev->dev,
"Failed to allocate memory for tile binning: "
"%d. You may need to enable CMA or give it "
"more memory.",
ret);
break;
}
if ((bo->base.paddr & 0xf0000000) ==
((bo->base.paddr + bo->base.base.size - 1) & 0xf0000000)) {
vc4->bin_bo = bo;
vc4->bin_alloc_size = 512 * 1024;
vc4->bin_alloc_used = 0;
vc4->bin_alloc_overflow = 0;
WARN_ON_ONCE(sizeof(vc4->bin_alloc_used) * 8 !=
bo->base.base.size / vc4->bin_alloc_size);
break;
}
list_add(&bo->unref_head, &list);
}
while (!list_empty(&list)) {
struct vc4_bo *bo = list_last_entry(&list,
struct vc4_bo, unref_head);
list_del(&bo->unref_head);
drm_gem_object_put_unlocked(&bo->base.base);
}
return ret;
}
static int vc4_v3d_runtime_suspend(struct device *dev)
{
struct vc4_v3d *v3d = dev_get_drvdata(dev);
struct vc4_dev *vc4 = v3d->vc4;
vc4_irq_uninstall(vc4->dev);
drm_gem_object_put_unlocked(&vc4->bin_bo->base.base);
vc4->bin_bo = NULL;
clk_disable_unprepare(v3d->clk);
return 0;
}
static int vc4_v3d_runtime_resume(struct device *dev)
{
struct vc4_v3d *v3d = dev_get_drvdata(dev);
struct vc4_dev *vc4 = v3d->vc4;
int ret;
ret = vc4_allocate_bin_bo(vc4->dev);
if (ret)
return ret;
ret = clk_prepare_enable(v3d->clk);
if (ret != 0)
return ret;
vc4_v3d_init_hw(vc4->dev);
vc4_irq_postinstall(vc4->dev);
return 0;
}
static int vc4_v3d_bind(struct device *dev, struct device *master, void *data)
{
struct platform_device *pdev = to_platform_device(dev);
struct drm_device *drm = dev_get_drvdata(master);
struct vc4_dev *vc4 = to_vc4_dev(drm);
struct vc4_v3d *v3d = NULL;
int ret;
v3d = devm_kzalloc(&pdev->dev, sizeof(*v3d), GFP_KERNEL);
if (!v3d)
return -ENOMEM;
dev_set_drvdata(dev, v3d);
v3d->pdev = pdev;
v3d->regs = vc4_ioremap_regs(pdev, 0);
if (IS_ERR(v3d->regs))
return PTR_ERR(v3d->regs);
vc4->v3d = v3d;
v3d->vc4 = vc4;
v3d->clk = devm_clk_get(dev, NULL);
if (IS_ERR(v3d->clk)) {
int ret = PTR_ERR(v3d->clk);
if (ret == -ENOENT) {
ret = 0;
v3d->clk = NULL;
} else {
if (ret != -EPROBE_DEFER)
dev_err(dev, "Failed to get V3D clock: %d\n",
ret);
return ret;
}
}
if (V3D_READ(V3D_IDENT0) != V3D_EXPECTED_IDENT0) {
DRM_ERROR("V3D_IDENT0 read 0x%08x instead of 0x%08x\n",
V3D_READ(V3D_IDENT0), V3D_EXPECTED_IDENT0);
return -EINVAL;
}
ret = clk_prepare_enable(v3d->clk);
if (ret != 0)
return ret;
ret = vc4_allocate_bin_bo(drm);
if (ret) {
clk_disable_unprepare(v3d->clk);
return ret;
}
V3D_WRITE(V3D_BPOA, 0);
V3D_WRITE(V3D_BPOS, 0);
vc4_v3d_init_hw(drm);
ret = drm_irq_install(drm, platform_get_irq(pdev, 0));
if (ret) {
DRM_ERROR("Failed to install IRQ handler\n");
return ret;
}
pm_runtime_set_active(dev);
pm_runtime_use_autosuspend(dev);
pm_runtime_set_autosuspend_delay(dev, 40);
pm_runtime_enable(dev);
return 0;
}
static void vc4_v3d_unbind(struct device *dev, struct device *master,
void *data)
{
struct drm_device *drm = dev_get_drvdata(master);
struct vc4_dev *vc4 = to_vc4_dev(drm);
pm_runtime_disable(dev);
drm_irq_uninstall(drm);
V3D_WRITE(V3D_BPOA, 0);
V3D_WRITE(V3D_BPOS, 0);
vc4->v3d = NULL;
}
static int vc4_v3d_dev_probe(struct platform_device *pdev)
{
return component_add(&pdev->dev, &vc4_v3d_ops);
}
static int vc4_v3d_dev_remove(struct platform_device *pdev)
{
component_del(&pdev->dev, &vc4_v3d_ops);
return 0;
}
