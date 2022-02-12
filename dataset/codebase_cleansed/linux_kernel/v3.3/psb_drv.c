static void psb_lastclose(struct drm_device *dev)
{
return;
}
static void psb_do_takedown(struct drm_device *dev)
{
}
static int psb_do_init(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
struct psb_gtt *pg = &dev_priv->gtt;
uint32_t stolen_gtt;
int ret = -ENOMEM;
if (pg->mmu_gatt_start & 0x0FFFFFFF) {
dev_err(dev->dev, "Gatt must be 256M aligned. This is a bug.\n");
ret = -EINVAL;
goto out_err;
}
stolen_gtt = (pg->stolen_size >> PAGE_SHIFT) * 4;
stolen_gtt = (stolen_gtt + PAGE_SIZE - 1) >> PAGE_SHIFT;
stolen_gtt =
(stolen_gtt < pg->gtt_pages) ? stolen_gtt : pg->gtt_pages;
dev_priv->gatt_free_offset = pg->mmu_gatt_start +
(stolen_gtt << PAGE_SHIFT) * 1024;
if (1 || drm_debug) {
uint32_t core_id = PSB_RSGX32(PSB_CR_CORE_ID);
uint32_t core_rev = PSB_RSGX32(PSB_CR_CORE_REVISION);
DRM_INFO("SGX core id = 0x%08x\n", core_id);
DRM_INFO("SGX core rev major = 0x%02x, minor = 0x%02x\n",
(core_rev & _PSB_CC_REVISION_MAJOR_MASK) >>
_PSB_CC_REVISION_MAJOR_SHIFT,
(core_rev & _PSB_CC_REVISION_MINOR_MASK) >>
_PSB_CC_REVISION_MINOR_SHIFT);
DRM_INFO
("SGX core rev maintenance = 0x%02x, designer = 0x%02x\n",
(core_rev & _PSB_CC_REVISION_MAINTENANCE_MASK) >>
_PSB_CC_REVISION_MAINTENANCE_SHIFT,
(core_rev & _PSB_CC_REVISION_DESIGNER_MASK) >>
_PSB_CC_REVISION_DESIGNER_SHIFT);
}
spin_lock_init(&dev_priv->irqmask_lock);
spin_lock_init(&dev_priv->lock_2d);
PSB_WSGX32(0x00000000, PSB_CR_BIF_BANK0);
PSB_WSGX32(0x00000000, PSB_CR_BIF_BANK1);
PSB_RSGX32(PSB_CR_BIF_BANK1);
PSB_WSGX32(PSB_RSGX32(PSB_CR_BIF_CTRL) | _PSB_MMU_ER_MASK,
PSB_CR_BIF_CTRL);
psb_spank(dev_priv);
PSB_WSGX32(pg->gatt_start, PSB_CR_BIF_TWOD_REQ_BASE);
return 0;
out_err:
psb_do_takedown(dev);
return ret;
}
static int psb_driver_unload(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
gma_backlight_exit(dev);
psb_modeset_cleanup(dev);
if (dev_priv) {
psb_lid_timer_takedown(dev_priv);
gma_intel_opregion_exit(dev);
if (dev_priv->ops->chip_teardown)
dev_priv->ops->chip_teardown(dev);
psb_do_takedown(dev);
if (dev_priv->pf_pd) {
psb_mmu_free_pagedir(dev_priv->pf_pd);
dev_priv->pf_pd = NULL;
}
if (dev_priv->mmu) {
struct psb_gtt *pg = &dev_priv->gtt;
down_read(&pg->sem);
psb_mmu_remove_pfn_sequence(
psb_mmu_get_default_pd
(dev_priv->mmu),
pg->mmu_gatt_start,
dev_priv->vram_stolen_size >> PAGE_SHIFT);
up_read(&pg->sem);
psb_mmu_driver_takedown(dev_priv->mmu);
dev_priv->mmu = NULL;
}
psb_gtt_takedown(dev);
if (dev_priv->scratch_page) {
__free_page(dev_priv->scratch_page);
dev_priv->scratch_page = NULL;
}
if (dev_priv->vdc_reg) {
iounmap(dev_priv->vdc_reg);
dev_priv->vdc_reg = NULL;
}
if (dev_priv->sgx_reg) {
iounmap(dev_priv->sgx_reg);
dev_priv->sgx_reg = NULL;
}
kfree(dev_priv);
dev->dev_private = NULL;
psb_intel_destroy_bios(dev);
}
gma_power_uninit(dev);
return 0;
}
static int psb_driver_load(struct drm_device *dev, unsigned long chipset)
{
struct drm_psb_private *dev_priv;
unsigned long resource_start;
struct psb_gtt *pg;
unsigned long irqflags;
int ret = -ENOMEM;
uint32_t tt_pages;
struct drm_connector *connector;
struct psb_intel_encoder *psb_intel_encoder;
dev_priv = kzalloc(sizeof(*dev_priv), GFP_KERNEL);
if (dev_priv == NULL)
return -ENOMEM;
dev_priv->ops = (struct psb_ops *)chipset;
dev_priv->dev = dev;
dev->dev_private = (void *) dev_priv;
if (!IS_PSB(dev)) {
if (pci_enable_msi(dev->pdev))
dev_warn(dev->dev, "Enabling MSI failed!\n");
}
dev_priv->num_pipe = dev_priv->ops->pipes;
resource_start = pci_resource_start(dev->pdev, PSB_MMIO_RESOURCE);
dev_priv->vdc_reg =
ioremap(resource_start + PSB_VDC_OFFSET, PSB_VDC_SIZE);
if (!dev_priv->vdc_reg)
goto out_err;
dev_priv->sgx_reg = ioremap(resource_start + dev_priv->ops->sgx_offset,
PSB_SGX_SIZE);
if (!dev_priv->sgx_reg)
goto out_err;
ret = dev_priv->ops->chip_setup(dev);
if (ret)
goto out_err;
gma_power_init(dev);
ret = -ENOMEM;
dev_priv->scratch_page = alloc_page(GFP_DMA32 | __GFP_ZERO);
if (!dev_priv->scratch_page)
goto out_err;
set_pages_uc(dev_priv->scratch_page, 1);
ret = psb_gtt_init(dev, 0);
if (ret)
goto out_err;
dev_priv->mmu = psb_mmu_driver_init((void *)0,
drm_psb_trap_pagefaults, 0,
dev_priv);
if (!dev_priv->mmu)
goto out_err;
pg = &dev_priv->gtt;
tt_pages = (pg->gatt_pages < PSB_TT_PRIV0_PLIMIT) ?
(pg->gatt_pages) : PSB_TT_PRIV0_PLIMIT;
dev_priv->pf_pd = psb_mmu_alloc_pd(dev_priv->mmu, 1, 0);
if (!dev_priv->pf_pd)
goto out_err;
psb_mmu_set_pd_context(psb_mmu_get_default_pd(dev_priv->mmu), 0);
psb_mmu_set_pd_context(dev_priv->pf_pd, 1);
ret = psb_do_init(dev);
if (ret)
return ret;
PSB_WSGX32(0x20000000, PSB_CR_PDS_EXEC_BASE);
PSB_WSGX32(0x30000000, PSB_CR_BIF_3D_REQ_BASE);
acpi_video_register();
if (dev_priv->lid_state)
psb_lid_timer_init(dev_priv);
ret = drm_vblank_init(dev, dev_priv->num_pipe);
if (ret)
goto out_err;
dev_priv->vdc_irq_mask = 0;
dev_priv->pipestat[0] = 0;
dev_priv->pipestat[1] = 0;
dev_priv->pipestat[2] = 0;
spin_lock_irqsave(&dev_priv->irqmask_lock, irqflags);
PSB_WVDC32(0xFFFFFFFF, PSB_HWSTAM);
PSB_WVDC32(0x00000000, PSB_INT_ENABLE_R);
PSB_WVDC32(0xFFFFFFFF, PSB_INT_MASK_R);
spin_unlock_irqrestore(&dev_priv->irqmask_lock, irqflags);
if (IS_PSB(dev) && drm_core_check_feature(dev, DRIVER_MODESET))
drm_irq_install(dev);
dev->vblank_disable_allowed = 1;
dev->max_vblank_count = 0xffffff;
dev->driver->get_vblank_counter = psb_get_vblank_counter;
psb_modeset_init(dev);
psb_fbdev_init(dev);
drm_kms_helper_poll_init(dev);
list_for_each_entry(connector, &dev->mode_config.connector_list,
head) {
psb_intel_encoder = psb_intel_attached_encoder(connector);
switch (psb_intel_encoder->type) {
case INTEL_OUTPUT_LVDS:
case INTEL_OUTPUT_MIPI:
ret = gma_backlight_init(dev);
break;
}
}
if (ret)
return ret;
#if 0
pm_runtime_enable(&dev->pdev->dev);
pm_runtime_set_active(&dev->pdev->dev);
#endif
return 0;
out_err:
psb_driver_unload(dev);
return ret;
}
int psb_driver_device_is_agp(struct drm_device *dev)
{
return 0;
}
static inline void get_brightness(struct backlight_device *bd)
{
#ifdef CONFIG_BACKLIGHT_CLASS_DEVICE
if (bd) {
bd->props.brightness = bd->ops->get_brightness(bd);
backlight_update_status(bd);
}
#endif
}
static int psb_dpst_bl_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_psb_private *dev_priv = psb_priv(dev);
uint32_t *arg = data;
dev_priv->blc_adj2 = *arg;
get_brightness(dev_priv->backlight_device);
return 0;
}
static int psb_adb_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_psb_private *dev_priv = psb_priv(dev);
uint32_t *arg = data;
dev_priv->blc_adj1 = *arg;
get_brightness(dev_priv->backlight_device);
return 0;
}
static int psb_gamma_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_psb_dpst_lut_arg *lut_arg = data;
struct drm_mode_object *obj;
struct drm_crtc *crtc;
struct drm_connector *connector;
struct psb_intel_crtc *psb_intel_crtc;
int i = 0;
int32_t obj_id;
obj_id = lut_arg->output_id;
obj = drm_mode_object_find(dev, obj_id, DRM_MODE_OBJECT_CONNECTOR);
if (!obj) {
dev_dbg(dev->dev, "Invalid Connector object.\n");
return -EINVAL;
}
connector = obj_to_connector(obj);
crtc = connector->encoder->crtc;
psb_intel_crtc = to_psb_intel_crtc(crtc);
for (i = 0; i < 256; i++)
psb_intel_crtc->lut_adj[i] = lut_arg->lut[i];
psb_intel_crtc_load_lut(crtc);
return 0;
}
static int psb_mode_operation_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
uint32_t obj_id;
uint16_t op;
struct drm_mode_modeinfo *umode;
struct drm_display_mode *mode = NULL;
struct drm_psb_mode_operation_arg *arg;
struct drm_mode_object *obj;
struct drm_connector *connector;
struct drm_connector_helper_funcs *connector_funcs;
int ret = 0;
int resp = MODE_OK;
arg = (struct drm_psb_mode_operation_arg *)data;
obj_id = arg->obj_id;
op = arg->operation;
switch (op) {
case PSB_MODE_OPERATION_MODE_VALID:
umode = &arg->mode;
mutex_lock(&dev->mode_config.mutex);
obj = drm_mode_object_find(dev, obj_id,
DRM_MODE_OBJECT_CONNECTOR);
if (!obj) {
ret = -EINVAL;
goto mode_op_out;
}
connector = obj_to_connector(obj);
mode = drm_mode_create(dev);
if (!mode) {
ret = -ENOMEM;
goto mode_op_out;
}
{
mode->clock = umode->clock;
mode->hdisplay = umode->hdisplay;
mode->hsync_start = umode->hsync_start;
mode->hsync_end = umode->hsync_end;
mode->htotal = umode->htotal;
mode->hskew = umode->hskew;
mode->vdisplay = umode->vdisplay;
mode->vsync_start = umode->vsync_start;
mode->vsync_end = umode->vsync_end;
mode->vtotal = umode->vtotal;
mode->vscan = umode->vscan;
mode->vrefresh = umode->vrefresh;
mode->flags = umode->flags;
mode->type = umode->type;
strncpy(mode->name, umode->name, DRM_DISPLAY_MODE_LEN);
mode->name[DRM_DISPLAY_MODE_LEN-1] = 0;
}
connector_funcs = (struct drm_connector_helper_funcs *)
connector->helper_private;
if (connector_funcs->mode_valid) {
resp = connector_funcs->mode_valid(connector, mode);
arg->data = resp;
}
if (mode)
drm_mode_destroy(dev, mode);
mode_op_out:
mutex_unlock(&dev->mode_config.mutex);
return ret;
default:
dev_dbg(dev->dev, "Unsupported psb mode operation\n");
return -EOPNOTSUPP;
}
return 0;
}
static int psb_stolen_memory_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_psb_private *dev_priv = psb_priv(dev);
struct drm_psb_stolen_memory_arg *arg = data;
arg->base = dev_priv->stolen_base;
arg->size = dev_priv->vram_stolen_size;
return 0;
}
static int psb_driver_open(struct drm_device *dev, struct drm_file *priv)
{
return 0;
}
static void psb_driver_close(struct drm_device *dev, struct drm_file *priv)
{
}
static long psb_unlocked_ioctl(struct file *filp, unsigned int cmd,
unsigned long arg)
{
struct drm_file *file_priv = filp->private_data;
struct drm_device *dev = file_priv->minor->dev;
struct drm_psb_private *dev_priv = dev->dev_private;
static unsigned int runtime_allowed;
if (runtime_allowed == 1 && dev_priv->is_lvds_on) {
runtime_allowed++;
pm_runtime_allow(&dev->pdev->dev);
dev_priv->rpm_enabled = 1;
}
return drm_ioctl(filp, cmd, arg);
}
void psb_driver_preclose(struct drm_device *dev, struct drm_file *priv)
{
}
static void psb_remove(struct pci_dev *pdev)
{
struct drm_device *dev = pci_get_drvdata(pdev);
drm_put_dev(dev);
}
static int psb_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
return drm_get_pci_dev(pdev, ent, &driver);
}
static int __init psb_init(void)
{
return drm_pci_init(&driver, &psb_pci_driver);
}
static void __exit psb_exit(void)
{
drm_pci_exit(&driver, &psb_pci_driver);
}
