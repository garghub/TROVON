static u32 asle_set_backlight(struct drm_device *dev, u32 bclp)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct opregion_asle __iomem *asle = dev_priv->opregion.asle;
u32 max;
DRM_DEBUG_DRIVER("bclp = 0x%08x\n", bclp);
if (!(bclp & ASLE_BCLP_VALID))
return ASLE_BACKLIGHT_FAILED;
bclp &= ASLE_BCLP_MSK;
if (bclp > 255)
return ASLE_BACKLIGHT_FAILED;
max = intel_panel_get_max_backlight(dev);
intel_panel_set_backlight(dev, bclp * max / 255);
iowrite32((bclp*0x64)/0xff | ASLE_CBLV_VALID, &asle->cblv);
return 0;
}
static u32 asle_set_als_illum(struct drm_device *dev, u32 alsi)
{
return 0;
}
static u32 asle_set_pwm_freq(struct drm_device *dev, u32 pfmb)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (pfmb & ASLE_PFMB_PWM_VALID) {
u32 blc_pwm_ctl = I915_READ(BLC_PWM_CTL);
u32 pwm = pfmb & ASLE_PFMB_PWM_MASK;
blc_pwm_ctl &= BACKLIGHT_DUTY_CYCLE_MASK;
pwm = pwm >> 9;
}
return 0;
}
static u32 asle_set_pfit(struct drm_device *dev, u32 pfit)
{
if (!(pfit & ASLE_PFIT_VALID))
return ASLE_PFIT_FAILED;
return 0;
}
void intel_opregion_asle_intr(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct opregion_asle __iomem *asle = dev_priv->opregion.asle;
u32 asle_stat = 0;
u32 asle_req;
if (!asle)
return;
asle_req = ioread32(&asle->aslc) & ASLE_REQ_MSK;
if (!asle_req) {
DRM_DEBUG_DRIVER("non asle set request??\n");
return;
}
if (asle_req & ASLE_SET_ALS_ILLUM)
asle_stat |= asle_set_als_illum(dev, ioread32(&asle->alsi));
if (asle_req & ASLE_SET_BACKLIGHT)
asle_stat |= asle_set_backlight(dev, ioread32(&asle->bclp));
if (asle_req & ASLE_SET_PFIT)
asle_stat |= asle_set_pfit(dev, ioread32(&asle->pfit));
if (asle_req & ASLE_SET_PWM_FREQ)
asle_stat |= asle_set_pwm_freq(dev, ioread32(&asle->pfmb));
iowrite32(asle_stat, &asle->aslc);
}
void intel_opregion_gse_intr(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct opregion_asle __iomem *asle = dev_priv->opregion.asle;
u32 asle_stat = 0;
u32 asle_req;
if (!asle)
return;
asle_req = ioread32(&asle->aslc) & ASLE_REQ_MSK;
if (!asle_req) {
DRM_DEBUG_DRIVER("non asle set request??\n");
return;
}
if (asle_req & ASLE_SET_ALS_ILLUM) {
DRM_DEBUG_DRIVER("Illum is not supported\n");
asle_stat |= ASLE_ALS_ILLUM_FAILED;
}
if (asle_req & ASLE_SET_BACKLIGHT)
asle_stat |= asle_set_backlight(dev, ioread32(&asle->bclp));
if (asle_req & ASLE_SET_PFIT) {
DRM_DEBUG_DRIVER("Pfit is not supported\n");
asle_stat |= ASLE_PFIT_FAILED;
}
if (asle_req & ASLE_SET_PWM_FREQ) {
DRM_DEBUG_DRIVER("PWM freq is not supported\n");
asle_stat |= ASLE_PWM_FREQ_FAILED;
}
iowrite32(asle_stat, &asle->aslc);
}
void intel_opregion_enable_asle(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct opregion_asle __iomem *asle = dev_priv->opregion.asle;
if (asle) {
if (IS_MOBILE(dev))
intel_enable_asle(dev);
iowrite32(ASLE_ALS_EN | ASLE_BLC_EN | ASLE_PFIT_EN |
ASLE_PFMB_EN,
&asle->tche);
iowrite32(1, &asle->ardy);
}
}
static int intel_opregion_video_event(struct notifier_block *nb,
unsigned long val, void *data)
{
struct opregion_acpi __iomem *acpi;
struct acpi_bus_event *event = data;
int ret = NOTIFY_OK;
if (strcmp(event->device_class, ACPI_VIDEO_CLASS) != 0)
return NOTIFY_DONE;
if (!system_opregion)
return NOTIFY_DONE;
acpi = system_opregion->acpi;
if (event->type == 0x80 &&
(ioread32(&acpi->cevt) & 1) == 0)
ret = NOTIFY_BAD;
iowrite32(0, &acpi->csts);
return ret;
}
static void intel_didl_outputs(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_opregion *opregion = &dev_priv->opregion;
struct drm_connector *connector;
acpi_handle handle;
struct acpi_device *acpi_dev, *acpi_cdev, *acpi_video_bus = NULL;
unsigned long long device_id;
acpi_status status;
u32 temp;
int i = 0;
handle = DEVICE_ACPI_HANDLE(&dev->pdev->dev);
if (!handle || acpi_bus_get_device(handle, &acpi_dev))
return;
if (acpi_is_video_device(acpi_dev))
acpi_video_bus = acpi_dev;
else {
list_for_each_entry(acpi_cdev, &acpi_dev->children, node) {
if (acpi_is_video_device(acpi_cdev)) {
acpi_video_bus = acpi_cdev;
break;
}
}
}
if (!acpi_video_bus) {
pr_warn("No ACPI video bus found\n");
return;
}
list_for_each_entry(acpi_cdev, &acpi_video_bus->children, node) {
if (i >= 8) {
dev_printk(KERN_ERR, &dev->pdev->dev,
"More than 8 outputs detected\n");
return;
}
status =
acpi_evaluate_integer(acpi_cdev->handle, "_ADR",
NULL, &device_id);
if (ACPI_SUCCESS(status)) {
if (!device_id)
goto blind_set;
iowrite32((u32)(device_id & 0x0f0f),
&opregion->acpi->didl[i]);
i++;
}
}
end:
if (i < 8)
iowrite32(0, &opregion->acpi->didl[i]);
return;
blind_set:
i = 0;
list_for_each_entry(connector, &dev->mode_config.connector_list, head) {
int output_type = ACPI_OTHER_OUTPUT;
if (i >= 8) {
dev_printk(KERN_ERR, &dev->pdev->dev,
"More than 8 outputs detected\n");
return;
}
switch (connector->connector_type) {
case DRM_MODE_CONNECTOR_VGA:
case DRM_MODE_CONNECTOR_DVIA:
output_type = ACPI_VGA_OUTPUT;
break;
case DRM_MODE_CONNECTOR_Composite:
case DRM_MODE_CONNECTOR_SVIDEO:
case DRM_MODE_CONNECTOR_Component:
case DRM_MODE_CONNECTOR_9PinDIN:
output_type = ACPI_TV_OUTPUT;
break;
case DRM_MODE_CONNECTOR_DVII:
case DRM_MODE_CONNECTOR_DVID:
case DRM_MODE_CONNECTOR_DisplayPort:
case DRM_MODE_CONNECTOR_HDMIA:
case DRM_MODE_CONNECTOR_HDMIB:
output_type = ACPI_DIGITAL_OUTPUT;
break;
case DRM_MODE_CONNECTOR_LVDS:
output_type = ACPI_LVDS_OUTPUT;
break;
}
temp = ioread32(&opregion->acpi->didl[i]);
iowrite32(temp | (1<<31) | output_type | i,
&opregion->acpi->didl[i]);
i++;
}
goto end;
}
static void intel_setup_cadls(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_opregion *opregion = &dev_priv->opregion;
int i = 0;
u32 disp_id;
do {
disp_id = ioread32(&opregion->acpi->didl[i]);
iowrite32(disp_id, &opregion->acpi->cadl[i]);
} while (++i < 8 && disp_id != 0);
}
void intel_opregion_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_opregion *opregion = &dev_priv->opregion;
if (!opregion->header)
return;
if (opregion->acpi) {
if (drm_core_check_feature(dev, DRIVER_MODESET)) {
intel_didl_outputs(dev);
intel_setup_cadls(dev);
}
iowrite32(0, &opregion->acpi->csts);
iowrite32(1, &opregion->acpi->drdy);
system_opregion = opregion;
register_acpi_notifier(&intel_opregion_notifier);
}
if (opregion->asle)
intel_opregion_enable_asle(dev);
}
void intel_opregion_fini(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_opregion *opregion = &dev_priv->opregion;
if (!opregion->header)
return;
if (opregion->acpi) {
iowrite32(0, &opregion->acpi->drdy);
system_opregion = NULL;
unregister_acpi_notifier(&intel_opregion_notifier);
}
iounmap(opregion->header);
opregion->header = NULL;
opregion->acpi = NULL;
opregion->swsci = NULL;
opregion->asle = NULL;
opregion->vbt = NULL;
}
int intel_opregion_setup(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_opregion *opregion = &dev_priv->opregion;
void __iomem *base;
u32 asls, mboxes;
char buf[sizeof(OPREGION_SIGNATURE)];
int err = 0;
pci_read_config_dword(dev->pdev, PCI_ASLS, &asls);
DRM_DEBUG_DRIVER("graphic opregion physical addr: 0x%x\n", asls);
if (asls == 0) {
DRM_DEBUG_DRIVER("ACPI OpRegion not supported!\n");
return -ENOTSUPP;
}
base = acpi_os_ioremap(asls, OPREGION_SIZE);
if (!base)
return -ENOMEM;
memcpy_fromio(buf, base, sizeof(buf));
if (memcmp(buf, OPREGION_SIGNATURE, 16)) {
DRM_DEBUG_DRIVER("opregion signature mismatch\n");
err = -EINVAL;
goto err_out;
}
opregion->header = base;
opregion->vbt = base + OPREGION_VBT_OFFSET;
opregion->lid_state = base + ACPI_CLID;
mboxes = ioread32(&opregion->header->mboxes);
if (mboxes & MBOX_ACPI) {
DRM_DEBUG_DRIVER("Public ACPI methods supported\n");
opregion->acpi = base + OPREGION_ACPI_OFFSET;
}
if (mboxes & MBOX_SWSCI) {
DRM_DEBUG_DRIVER("SWSCI supported\n");
opregion->swsci = base + OPREGION_SWSCI_OFFSET;
}
if (mboxes & MBOX_ASLE) {
DRM_DEBUG_DRIVER("ASLE supported\n");
opregion->asle = base + OPREGION_ASLE_OFFSET;
}
return 0;
err_out:
iounmap(base);
return err;
}
