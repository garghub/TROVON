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
mutex_init(&dev_priv->mutex_2d);
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
if (drm_psb_no_fb == 0)
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
struct psb_intel_output *psb_intel_output;
dev_priv = kzalloc(sizeof(*dev_priv), GFP_KERNEL);
if (dev_priv == NULL)
return -ENOMEM;
dev_priv->ops = (struct psb_ops *)chipset;
dev_priv->dev = dev;
dev->dev_private = (void *) dev_priv;
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
if (drm_core_check_feature(dev, DRIVER_MODESET))
drm_irq_install(dev);
dev->vblank_disable_allowed = 1;
dev->max_vblank_count = 0xffffff;
dev->driver->get_vblank_counter = psb_get_vblank_counter;
#if defined(CONFIG_DRM_PSB_MFLD)
mdfld_output_setup(dev);
#endif
if (drm_psb_no_fb == 0) {
psb_modeset_init(dev);
psb_fbdev_init(dev);
drm_kms_helper_poll_init(dev);
}
list_for_each_entry(connector, &dev->mode_config.connector_list,
head) {
psb_intel_output = to_psb_intel_output(connector);
switch (psb_intel_output->type) {
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
static int psb_sizes_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_psb_private *dev_priv = psb_priv(dev);
struct drm_psb_sizes_arg *arg =
(struct drm_psb_sizes_arg *) data;
*arg = dev_priv->sizes;
return 0;
}
static int psb_dc_state_ioctl(struct drm_device *dev, void * data,
struct drm_file *file_priv)
{
uint32_t flags;
uint32_t obj_id;
struct drm_mode_object *obj;
struct drm_connector *connector;
struct drm_crtc *crtc;
struct drm_psb_dc_state_arg *arg =
(struct drm_psb_dc_state_arg *)data;
if (IS_MRST(dev) || IS_MFLD(dev))
return -EOPNOTSUPP;
flags = arg->flags;
obj_id = arg->obj_id;
if (flags & PSB_DC_CRTC_MASK) {
obj = drm_mode_object_find(dev, obj_id,
DRM_MODE_OBJECT_CRTC);
if (!obj) {
dev_dbg(dev->dev, "Invalid CRTC object.\n");
return -EINVAL;
}
crtc = obj_to_crtc(obj);
mutex_lock(&dev->mode_config.mutex);
if (drm_helper_crtc_in_use(crtc)) {
if (flags & PSB_DC_CRTC_SAVE)
crtc->funcs->save(crtc);
else
crtc->funcs->restore(crtc);
}
mutex_unlock(&dev->mode_config.mutex);
return 0;
} else if (flags & PSB_DC_OUTPUT_MASK) {
obj = drm_mode_object_find(dev, obj_id,
DRM_MODE_OBJECT_CONNECTOR);
if (!obj) {
dev_dbg(dev->dev, "Invalid connector id.\n");
return -EINVAL;
}
connector = obj_to_connector(obj);
if (flags & PSB_DC_OUTPUT_SAVE)
connector->funcs->save(connector);
else
connector->funcs->restore(connector);
return 0;
}
return -EINVAL;
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
static int psb_dpst_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_psb_private *dev_priv = psb_priv(dev);
uint32_t *arg = data;
uint32_t x;
uint32_t y;
uint32_t reg;
if (!gma_power_begin(dev, 0))
return -EIO;
reg = PSB_RVDC32(PIPEASRC);
gma_power_end(dev);
x = reg >> 16;
y = reg & 0x0000ffff;
x++;
y++;
*arg = (x << 16) | y;
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
struct drm_framebuffer *drm_fb;
struct psb_framebuffer *psb_fb;
struct drm_connector_helper_funcs *connector_funcs;
int ret = 0;
int resp = MODE_OK;
struct drm_psb_private *dev_priv = psb_priv(dev);
arg = (struct drm_psb_mode_operation_arg *)data;
obj_id = arg->obj_id;
op = arg->operation;
switch (op) {
case PSB_MODE_OPERATION_SET_DC_BASE:
obj = drm_mode_object_find(dev, obj_id, DRM_MODE_OBJECT_FB);
if (!obj) {
dev_dbg(dev->dev, "Invalid FB id %d\n", obj_id);
return -EINVAL;
}
drm_fb = obj_to_fb(obj);
psb_fb = to_psb_fb(drm_fb);
if (gma_power_begin(dev, 0)) {
REG_WRITE(DSPASURF, psb_fb->gtt->offset);
REG_READ(DSPASURF);
gma_power_end(dev);
} else {
dev_priv->saveDSPASURF = psb_fb->gtt->offset;
}
return 0;
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
arg->data = (void *)resp;
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
static int psb_register_rw_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_psb_private *dev_priv = psb_priv(dev);
struct drm_psb_register_rw_arg *arg = data;
bool usage = arg->b_force_hw_on ? true : false;
if (arg->display_write_mask != 0) {
if (gma_power_begin(dev, usage)) {
if (arg->display_write_mask & REGRWBITS_PFIT_CONTROLS)
PSB_WVDC32(arg->display.pfit_controls,
PFIT_CONTROL);
if (arg->display_write_mask &
REGRWBITS_PFIT_AUTOSCALE_RATIOS)
PSB_WVDC32(arg->display.pfit_autoscale_ratios,
PFIT_AUTO_RATIOS);
if (arg->display_write_mask &
REGRWBITS_PFIT_PROGRAMMED_SCALE_RATIOS)
PSB_WVDC32(
arg->display.pfit_programmed_scale_ratios,
PFIT_PGM_RATIOS);
if (arg->display_write_mask & REGRWBITS_PIPEASRC)
PSB_WVDC32(arg->display.pipeasrc,
PIPEASRC);
if (arg->display_write_mask & REGRWBITS_PIPEBSRC)
PSB_WVDC32(arg->display.pipebsrc,
PIPEBSRC);
if (arg->display_write_mask & REGRWBITS_VTOTAL_A)
PSB_WVDC32(arg->display.vtotal_a,
VTOTAL_A);
if (arg->display_write_mask & REGRWBITS_VTOTAL_B)
PSB_WVDC32(arg->display.vtotal_b,
VTOTAL_B);
gma_power_end(dev);
} else {
if (arg->display_write_mask & REGRWBITS_PFIT_CONTROLS)
dev_priv->savePFIT_CONTROL =
arg->display.pfit_controls;
if (arg->display_write_mask &
REGRWBITS_PFIT_AUTOSCALE_RATIOS)
dev_priv->savePFIT_AUTO_RATIOS =
arg->display.pfit_autoscale_ratios;
if (arg->display_write_mask &
REGRWBITS_PFIT_PROGRAMMED_SCALE_RATIOS)
dev_priv->savePFIT_PGM_RATIOS =
arg->display.pfit_programmed_scale_ratios;
if (arg->display_write_mask & REGRWBITS_PIPEASRC)
dev_priv->savePIPEASRC = arg->display.pipeasrc;
if (arg->display_write_mask & REGRWBITS_PIPEBSRC)
dev_priv->savePIPEBSRC = arg->display.pipebsrc;
if (arg->display_write_mask & REGRWBITS_VTOTAL_A)
dev_priv->saveVTOTAL_A = arg->display.vtotal_a;
if (arg->display_write_mask & REGRWBITS_VTOTAL_B)
dev_priv->saveVTOTAL_B = arg->display.vtotal_b;
}
}
if (arg->display_read_mask != 0) {
if (gma_power_begin(dev, usage)) {
if (arg->display_read_mask &
REGRWBITS_PFIT_CONTROLS)
arg->display.pfit_controls =
PSB_RVDC32(PFIT_CONTROL);
if (arg->display_read_mask &
REGRWBITS_PFIT_AUTOSCALE_RATIOS)
arg->display.pfit_autoscale_ratios =
PSB_RVDC32(PFIT_AUTO_RATIOS);
if (arg->display_read_mask &
REGRWBITS_PFIT_PROGRAMMED_SCALE_RATIOS)
arg->display.pfit_programmed_scale_ratios =
PSB_RVDC32(PFIT_PGM_RATIOS);
if (arg->display_read_mask & REGRWBITS_PIPEASRC)
arg->display.pipeasrc = PSB_RVDC32(PIPEASRC);
if (arg->display_read_mask & REGRWBITS_PIPEBSRC)
arg->display.pipebsrc = PSB_RVDC32(PIPEBSRC);
if (arg->display_read_mask & REGRWBITS_VTOTAL_A)
arg->display.vtotal_a = PSB_RVDC32(VTOTAL_A);
if (arg->display_read_mask & REGRWBITS_VTOTAL_B)
arg->display.vtotal_b = PSB_RVDC32(VTOTAL_B);
gma_power_end(dev);
} else {
if (arg->display_read_mask &
REGRWBITS_PFIT_CONTROLS)
arg->display.pfit_controls =
dev_priv->savePFIT_CONTROL;
if (arg->display_read_mask &
REGRWBITS_PFIT_AUTOSCALE_RATIOS)
arg->display.pfit_autoscale_ratios =
dev_priv->savePFIT_AUTO_RATIOS;
if (arg->display_read_mask &
REGRWBITS_PFIT_PROGRAMMED_SCALE_RATIOS)
arg->display.pfit_programmed_scale_ratios =
dev_priv->savePFIT_PGM_RATIOS;
if (arg->display_read_mask & REGRWBITS_PIPEASRC)
arg->display.pipeasrc = dev_priv->savePIPEASRC;
if (arg->display_read_mask & REGRWBITS_PIPEBSRC)
arg->display.pipebsrc = dev_priv->savePIPEBSRC;
if (arg->display_read_mask & REGRWBITS_VTOTAL_A)
arg->display.vtotal_a = dev_priv->saveVTOTAL_A;
if (arg->display_read_mask & REGRWBITS_VTOTAL_B)
arg->display.vtotal_b = dev_priv->saveVTOTAL_B;
}
}
if (arg->overlay_write_mask != 0) {
if (gma_power_begin(dev, usage)) {
if (arg->overlay_write_mask & OV_REGRWBITS_OGAM_ALL) {
PSB_WVDC32(arg->overlay.OGAMC5, OV_OGAMC5);
PSB_WVDC32(arg->overlay.OGAMC4, OV_OGAMC4);
PSB_WVDC32(arg->overlay.OGAMC3, OV_OGAMC3);
PSB_WVDC32(arg->overlay.OGAMC2, OV_OGAMC2);
PSB_WVDC32(arg->overlay.OGAMC1, OV_OGAMC1);
PSB_WVDC32(arg->overlay.OGAMC0, OV_OGAMC0);
}
if (arg->overlay_write_mask & OVC_REGRWBITS_OGAM_ALL) {
PSB_WVDC32(arg->overlay.OGAMC5, OVC_OGAMC5);
PSB_WVDC32(arg->overlay.OGAMC4, OVC_OGAMC4);
PSB_WVDC32(arg->overlay.OGAMC3, OVC_OGAMC3);
PSB_WVDC32(arg->overlay.OGAMC2, OVC_OGAMC2);
PSB_WVDC32(arg->overlay.OGAMC1, OVC_OGAMC1);
PSB_WVDC32(arg->overlay.OGAMC0, OVC_OGAMC0);
}
if (arg->overlay_write_mask & OV_REGRWBITS_OVADD) {
PSB_WVDC32(arg->overlay.OVADD, OV_OVADD);
if (arg->overlay.b_wait_vblank) {
unsigned long vblank_timeout = jiffies
+ HZ/50;
uint32_t temp;
while (time_before_eq(jiffies,
vblank_timeout)) {
temp = PSB_RVDC32(OV_DOVASTA);
if ((temp & (0x1 << 31)) != 0)
break;
cpu_relax();
}
}
}
if (arg->overlay_write_mask & OVC_REGRWBITS_OVADD) {
PSB_WVDC32(arg->overlay.OVADD, OVC_OVADD);
if (arg->overlay.b_wait_vblank) {
unsigned long vblank_timeout =
jiffies + HZ/50;
uint32_t temp;
while (time_before_eq(jiffies,
vblank_timeout)) {
temp = PSB_RVDC32(OVC_DOVCSTA);
if ((temp & (0x1 << 31)) != 0)
break;
cpu_relax();
}
}
}
gma_power_end(dev);
} else {
if (arg->overlay_write_mask & OV_REGRWBITS_OGAM_ALL) {
dev_priv->saveOV_OGAMC5 = arg->overlay.OGAMC5;
dev_priv->saveOV_OGAMC4 = arg->overlay.OGAMC4;
dev_priv->saveOV_OGAMC3 = arg->overlay.OGAMC3;
dev_priv->saveOV_OGAMC2 = arg->overlay.OGAMC2;
dev_priv->saveOV_OGAMC1 = arg->overlay.OGAMC1;
dev_priv->saveOV_OGAMC0 = arg->overlay.OGAMC0;
}
if (arg->overlay_write_mask & OVC_REGRWBITS_OGAM_ALL) {
dev_priv->saveOVC_OGAMC5 = arg->overlay.OGAMC5;
dev_priv->saveOVC_OGAMC4 = arg->overlay.OGAMC4;
dev_priv->saveOVC_OGAMC3 = arg->overlay.OGAMC3;
dev_priv->saveOVC_OGAMC2 = arg->overlay.OGAMC2;
dev_priv->saveOVC_OGAMC1 = arg->overlay.OGAMC1;
dev_priv->saveOVC_OGAMC0 = arg->overlay.OGAMC0;
}
if (arg->overlay_write_mask & OV_REGRWBITS_OVADD)
dev_priv->saveOV_OVADD = arg->overlay.OVADD;
if (arg->overlay_write_mask & OVC_REGRWBITS_OVADD)
dev_priv->saveOVC_OVADD = arg->overlay.OVADD;
}
}
if (arg->overlay_read_mask != 0) {
if (gma_power_begin(dev, usage)) {
if (arg->overlay_read_mask & OV_REGRWBITS_OGAM_ALL) {
arg->overlay.OGAMC5 = PSB_RVDC32(OV_OGAMC5);
arg->overlay.OGAMC4 = PSB_RVDC32(OV_OGAMC4);
arg->overlay.OGAMC3 = PSB_RVDC32(OV_OGAMC3);
arg->overlay.OGAMC2 = PSB_RVDC32(OV_OGAMC2);
arg->overlay.OGAMC1 = PSB_RVDC32(OV_OGAMC1);
arg->overlay.OGAMC0 = PSB_RVDC32(OV_OGAMC0);
}
if (arg->overlay_read_mask & OVC_REGRWBITS_OGAM_ALL) {
arg->overlay.OGAMC5 = PSB_RVDC32(OVC_OGAMC5);
arg->overlay.OGAMC4 = PSB_RVDC32(OVC_OGAMC4);
arg->overlay.OGAMC3 = PSB_RVDC32(OVC_OGAMC3);
arg->overlay.OGAMC2 = PSB_RVDC32(OVC_OGAMC2);
arg->overlay.OGAMC1 = PSB_RVDC32(OVC_OGAMC1);
arg->overlay.OGAMC0 = PSB_RVDC32(OVC_OGAMC0);
}
if (arg->overlay_read_mask & OV_REGRWBITS_OVADD)
arg->overlay.OVADD = PSB_RVDC32(OV_OVADD);
if (arg->overlay_read_mask & OVC_REGRWBITS_OVADD)
arg->overlay.OVADD = PSB_RVDC32(OVC_OVADD);
gma_power_end(dev);
} else {
if (arg->overlay_read_mask & OV_REGRWBITS_OGAM_ALL) {
arg->overlay.OGAMC5 = dev_priv->saveOV_OGAMC5;
arg->overlay.OGAMC4 = dev_priv->saveOV_OGAMC4;
arg->overlay.OGAMC3 = dev_priv->saveOV_OGAMC3;
arg->overlay.OGAMC2 = dev_priv->saveOV_OGAMC2;
arg->overlay.OGAMC1 = dev_priv->saveOV_OGAMC1;
arg->overlay.OGAMC0 = dev_priv->saveOV_OGAMC0;
}
if (arg->overlay_read_mask & OVC_REGRWBITS_OGAM_ALL) {
arg->overlay.OGAMC5 = dev_priv->saveOVC_OGAMC5;
arg->overlay.OGAMC4 = dev_priv->saveOVC_OGAMC4;
arg->overlay.OGAMC3 = dev_priv->saveOVC_OGAMC3;
arg->overlay.OGAMC2 = dev_priv->saveOVC_OGAMC2;
arg->overlay.OGAMC1 = dev_priv->saveOVC_OGAMC1;
arg->overlay.OGAMC0 = dev_priv->saveOVC_OGAMC0;
}
if (arg->overlay_read_mask & OV_REGRWBITS_OVADD)
arg->overlay.OVADD = dev_priv->saveOV_OVADD;
if (arg->overlay_read_mask & OVC_REGRWBITS_OVADD)
arg->overlay.OVADD = dev_priv->saveOVC_OVADD;
}
}
if (arg->sprite_enable_mask != 0) {
if (gma_power_begin(dev, usage)) {
PSB_WVDC32(0x1F3E, DSPARB);
PSB_WVDC32(arg->sprite.dspa_control
| PSB_RVDC32(DSPACNTR), DSPACNTR);
PSB_WVDC32(arg->sprite.dspa_key_value, DSPAKEYVAL);
PSB_WVDC32(arg->sprite.dspa_key_mask, DSPAKEYMASK);
PSB_WVDC32(PSB_RVDC32(DSPASURF), DSPASURF);
PSB_RVDC32(DSPASURF);
PSB_WVDC32(arg->sprite.dspc_control, DSPCCNTR);
PSB_WVDC32(arg->sprite.dspc_stride, DSPCSTRIDE);
PSB_WVDC32(arg->sprite.dspc_position, DSPCPOS);
PSB_WVDC32(arg->sprite.dspc_linear_offset, DSPCLINOFF);
PSB_WVDC32(arg->sprite.dspc_size, DSPCSIZE);
PSB_WVDC32(arg->sprite.dspc_surface, DSPCSURF);
PSB_RVDC32(DSPCSURF);
gma_power_end(dev);
}
}
if (arg->sprite_disable_mask != 0) {
if (gma_power_begin(dev, usage)) {
PSB_WVDC32(0x3F3E, DSPARB);
PSB_WVDC32(0x0, DSPCCNTR);
PSB_WVDC32(arg->sprite.dspc_surface, DSPCSURF);
PSB_RVDC32(DSPCSURF);
gma_power_end(dev);
}
}
if (arg->subpicture_enable_mask != 0) {
if (gma_power_begin(dev, usage)) {
uint32_t temp;
if (arg->subpicture_enable_mask & REGRWBITS_DSPACNTR) {
temp = PSB_RVDC32(DSPACNTR);
temp &= ~DISPPLANE_PIXFORMAT_MASK;
temp &= ~DISPPLANE_BOTTOM;
temp |= DISPPLANE_32BPP;
PSB_WVDC32(temp, DSPACNTR);
temp = PSB_RVDC32(DSPABASE);
PSB_WVDC32(temp, DSPABASE);
PSB_RVDC32(DSPABASE);
temp = PSB_RVDC32(DSPASURF);
PSB_WVDC32(temp, DSPASURF);
PSB_RVDC32(DSPASURF);
}
if (arg->subpicture_enable_mask & REGRWBITS_DSPBCNTR) {
temp = PSB_RVDC32(DSPBCNTR);
temp &= ~DISPPLANE_PIXFORMAT_MASK;
temp &= ~DISPPLANE_BOTTOM;
temp |= DISPPLANE_32BPP;
PSB_WVDC32(temp, DSPBCNTR);
temp = PSB_RVDC32(DSPBBASE);
PSB_WVDC32(temp, DSPBBASE);
PSB_RVDC32(DSPBBASE);
temp = PSB_RVDC32(DSPBSURF);
PSB_WVDC32(temp, DSPBSURF);
PSB_RVDC32(DSPBSURF);
}
if (arg->subpicture_enable_mask & REGRWBITS_DSPCCNTR) {
temp = PSB_RVDC32(DSPCCNTR);
temp &= ~DISPPLANE_PIXFORMAT_MASK;
temp &= ~DISPPLANE_BOTTOM;
temp |= DISPPLANE_32BPP;
PSB_WVDC32(temp, DSPCCNTR);
temp = PSB_RVDC32(DSPCBASE);
PSB_WVDC32(temp, DSPCBASE);
PSB_RVDC32(DSPCBASE);
temp = PSB_RVDC32(DSPCSURF);
PSB_WVDC32(temp, DSPCSURF);
PSB_RVDC32(DSPCSURF);
}
gma_power_end(dev);
}
}
if (arg->subpicture_disable_mask != 0) {
if (gma_power_begin(dev, usage)) {
uint32_t temp;
if (arg->subpicture_disable_mask & REGRWBITS_DSPACNTR) {
temp = PSB_RVDC32(DSPACNTR);
temp &= ~DISPPLANE_PIXFORMAT_MASK;
temp |= DISPPLANE_32BPP_NO_ALPHA;
PSB_WVDC32(temp, DSPACNTR);
temp = PSB_RVDC32(DSPABASE);
PSB_WVDC32(temp, DSPABASE);
PSB_RVDC32(DSPABASE);
temp = PSB_RVDC32(DSPASURF);
PSB_WVDC32(temp, DSPASURF);
PSB_RVDC32(DSPASURF);
}
if (arg->subpicture_disable_mask & REGRWBITS_DSPBCNTR) {
temp = PSB_RVDC32(DSPBCNTR);
temp &= ~DISPPLANE_PIXFORMAT_MASK;
temp |= DISPPLANE_32BPP_NO_ALPHA;
PSB_WVDC32(temp, DSPBCNTR);
temp = PSB_RVDC32(DSPBBASE);
PSB_WVDC32(temp, DSPBBASE);
PSB_RVDC32(DSPBBASE);
temp = PSB_RVDC32(DSPBSURF);
PSB_WVDC32(temp, DSPBSURF);
PSB_RVDC32(DSPBSURF);
}
if (arg->subpicture_disable_mask & REGRWBITS_DSPCCNTR) {
temp = PSB_RVDC32(DSPCCNTR);
temp &= ~DISPPLANE_PIXFORMAT_MASK;
temp |= DISPPLANE_32BPP_NO_ALPHA;
PSB_WVDC32(temp, DSPCCNTR);
temp = PSB_RVDC32(DSPCBASE);
PSB_WVDC32(temp, DSPCBASE);
PSB_RVDC32(DSPCBASE);
temp = PSB_RVDC32(DSPCSURF);
PSB_WVDC32(temp, DSPCSURF);
PSB_RVDC32(DSPCSURF);
}
gma_power_end(dev);
}
}
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
if (pci_enable_msi(pdev))
dev_warn(&pdev->dev, "Enable MSI failed!\n");
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
