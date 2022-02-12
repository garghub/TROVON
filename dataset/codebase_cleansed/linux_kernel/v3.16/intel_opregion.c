static int swsci(struct drm_device *dev, u32 function, u32 parm, u32 *parm_out)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct opregion_swsci __iomem *swsci = dev_priv->opregion.swsci;
u32 main_function, sub_function, scic;
u16 pci_swsci;
u32 dslp;
if (!swsci)
return -ENODEV;
main_function = (function & SWSCI_SCIC_MAIN_FUNCTION_MASK) >>
SWSCI_SCIC_MAIN_FUNCTION_SHIFT;
sub_function = (function & SWSCI_SCIC_SUB_FUNCTION_MASK) >>
SWSCI_SCIC_SUB_FUNCTION_SHIFT;
if (main_function == SWSCI_SBCB) {
if ((dev_priv->opregion.swsci_sbcb_sub_functions &
(1 << sub_function)) == 0)
return -EINVAL;
} else if (main_function == SWSCI_GBDA) {
if ((dev_priv->opregion.swsci_gbda_sub_functions &
(1 << sub_function)) == 0)
return -EINVAL;
}
dslp = ioread32(&swsci->dslp);
if (!dslp) {
dslp = 50;
} else if (dslp > MAX_DSLP) {
DRM_INFO_ONCE("ACPI BIOS requests an excessive sleep of %u ms, "
"using %u ms instead\n", dslp, MAX_DSLP);
dslp = MAX_DSLP;
}
scic = ioread32(&swsci->scic);
if (scic & SWSCI_SCIC_INDICATOR) {
DRM_DEBUG_DRIVER("SWSCI request already in progress\n");
return -EBUSY;
}
scic = function | SWSCI_SCIC_INDICATOR;
iowrite32(parm, &swsci->parm);
iowrite32(scic, &swsci->scic);
pci_read_config_word(dev->pdev, PCI_SWSCI, &pci_swsci);
if (!(pci_swsci & PCI_SWSCI_SCISEL) || (pci_swsci & PCI_SWSCI_GSSCIE)) {
pci_swsci |= PCI_SWSCI_SCISEL;
pci_swsci &= ~PCI_SWSCI_GSSCIE;
pci_write_config_word(dev->pdev, PCI_SWSCI, pci_swsci);
}
pci_swsci |= PCI_SWSCI_GSSCIE;
pci_write_config_word(dev->pdev, PCI_SWSCI, pci_swsci);
#define C (((scic = ioread32(&swsci->scic)) & SWSCI_SCIC_INDICATOR) == 0)
if (wait_for(C, dslp)) {
DRM_DEBUG_DRIVER("SWSCI request timed out\n");
return -ETIMEDOUT;
}
scic = (scic & SWSCI_SCIC_EXIT_STATUS_MASK) >>
SWSCI_SCIC_EXIT_STATUS_SHIFT;
if (scic != SWSCI_SCIC_EXIT_STATUS_SUCCESS) {
DRM_DEBUG_DRIVER("SWSCI request error %u\n", scic);
return -EIO;
}
if (parm_out)
*parm_out = ioread32(&swsci->parm);
return 0;
#undef C
}
int intel_opregion_notify_encoder(struct intel_encoder *intel_encoder,
bool enable)
{
struct drm_device *dev = intel_encoder->base.dev;
u32 parm = 0;
u32 type = 0;
u32 port;
if (!HAS_DDI(dev))
return 0;
port = intel_ddi_get_encoder_port(intel_encoder);
if (port == PORT_E) {
port = 0;
} else {
parm |= 1 << port;
port++;
}
if (!enable)
parm |= 4 << 8;
switch (intel_encoder->type) {
case INTEL_OUTPUT_ANALOG:
type = DISPLAY_TYPE_CRT;
break;
case INTEL_OUTPUT_UNKNOWN:
case INTEL_OUTPUT_DISPLAYPORT:
case INTEL_OUTPUT_HDMI:
type = DISPLAY_TYPE_EXTERNAL_FLAT_PANEL;
break;
case INTEL_OUTPUT_EDP:
type = DISPLAY_TYPE_INTERNAL_FLAT_PANEL;
break;
default:
WARN_ONCE(1, "unsupported intel_encoder type %d\n",
intel_encoder->type);
return -EINVAL;
}
parm |= type << (16 + port * 3);
return swsci(dev, SWSCI_SBCB_DISPLAY_POWER_STATE, parm, NULL);
}
int intel_opregion_notify_adapter(struct drm_device *dev, pci_power_t state)
{
int i;
if (!HAS_DDI(dev))
return 0;
for (i = 0; i < ARRAY_SIZE(power_state_map); i++) {
if (state == power_state_map[i].pci_power_state)
return swsci(dev, SWSCI_SBCB_ADAPTER_POWER_STATE,
power_state_map[i].parm, NULL);
}
return -EINVAL;
}
static u32 asle_set_backlight(struct drm_device *dev, u32 bclp)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_connector *intel_connector;
struct opregion_asle __iomem *asle = dev_priv->opregion.asle;
DRM_DEBUG_DRIVER("bclp = 0x%08x\n", bclp);
if (!acpi_video_verify_backlight_support()) {
DRM_DEBUG_KMS("opregion backlight request ignored\n");
return 0;
}
if (!(bclp & ASLE_BCLP_VALID))
return ASLC_BACKLIGHT_FAILED;
bclp &= ASLE_BCLP_MSK;
if (bclp > 255)
return ASLC_BACKLIGHT_FAILED;
drm_modeset_lock(&dev->mode_config.connection_mutex, NULL);
DRM_DEBUG_KMS("updating opregion backlight %d/255\n", bclp);
list_for_each_entry(intel_connector, &dev->mode_config.connector_list, base.head)
intel_panel_set_backlight(intel_connector, bclp, 255);
iowrite32(DIV_ROUND_UP(bclp * 100, 255) | ASLE_CBLV_VALID, &asle->cblv);
drm_modeset_unlock(&dev->mode_config.connection_mutex);
return 0;
}
static u32 asle_set_als_illum(struct drm_device *dev, u32 alsi)
{
DRM_DEBUG_DRIVER("Illum is not supported\n");
return ASLC_ALS_ILLUM_FAILED;
}
static u32 asle_set_pwm_freq(struct drm_device *dev, u32 pfmb)
{
DRM_DEBUG_DRIVER("PWM freq is not supported\n");
return ASLC_PWM_FREQ_FAILED;
}
static u32 asle_set_pfit(struct drm_device *dev, u32 pfit)
{
DRM_DEBUG_DRIVER("Pfit is not supported\n");
return ASLC_PFIT_FAILED;
}
static u32 asle_set_supported_rotation_angles(struct drm_device *dev, u32 srot)
{
DRM_DEBUG_DRIVER("SROT is not supported\n");
return ASLC_ROTATION_ANGLES_FAILED;
}
static u32 asle_set_button_array(struct drm_device *dev, u32 iuer)
{
if (!iuer)
DRM_DEBUG_DRIVER("Button array event is not supported (nothing)\n");
if (iuer & ASLE_IUER_ROTATION_LOCK_BTN)
DRM_DEBUG_DRIVER("Button array event is not supported (rotation lock)\n");
if (iuer & ASLE_IUER_VOLUME_DOWN_BTN)
DRM_DEBUG_DRIVER("Button array event is not supported (volume down)\n");
if (iuer & ASLE_IUER_VOLUME_UP_BTN)
DRM_DEBUG_DRIVER("Button array event is not supported (volume up)\n");
if (iuer & ASLE_IUER_WINDOWS_BTN)
DRM_DEBUG_DRIVER("Button array event is not supported (windows)\n");
if (iuer & ASLE_IUER_POWER_BTN)
DRM_DEBUG_DRIVER("Button array event is not supported (power)\n");
return ASLC_BUTTON_ARRAY_FAILED;
}
static u32 asle_set_convertible(struct drm_device *dev, u32 iuer)
{
if (iuer & ASLE_IUER_CONVERTIBLE)
DRM_DEBUG_DRIVER("Convertible is not supported (clamshell)\n");
else
DRM_DEBUG_DRIVER("Convertible is not supported (slate)\n");
return ASLC_CONVERTIBLE_FAILED;
}
static u32 asle_set_docking(struct drm_device *dev, u32 iuer)
{
if (iuer & ASLE_IUER_DOCKING)
DRM_DEBUG_DRIVER("Docking is not supported (docked)\n");
else
DRM_DEBUG_DRIVER("Docking is not supported (undocked)\n");
return ASLC_DOCKING_FAILED;
}
static u32 asle_isct_state(struct drm_device *dev)
{
DRM_DEBUG_DRIVER("ISCT is not supported\n");
return ASLC_ISCT_STATE_FAILED;
}
static void asle_work(struct work_struct *work)
{
struct intel_opregion *opregion =
container_of(work, struct intel_opregion, asle_work);
struct drm_i915_private *dev_priv =
container_of(opregion, struct drm_i915_private, opregion);
struct drm_device *dev = dev_priv->dev;
struct opregion_asle __iomem *asle = dev_priv->opregion.asle;
u32 aslc_stat = 0;
u32 aslc_req;
if (!asle)
return;
aslc_req = ioread32(&asle->aslc);
if (!(aslc_req & ASLC_REQ_MSK)) {
DRM_DEBUG_DRIVER("No request on ASLC interrupt 0x%08x\n",
aslc_req);
return;
}
if (aslc_req & ASLC_SET_ALS_ILLUM)
aslc_stat |= asle_set_als_illum(dev, ioread32(&asle->alsi));
if (aslc_req & ASLC_SET_BACKLIGHT)
aslc_stat |= asle_set_backlight(dev, ioread32(&asle->bclp));
if (aslc_req & ASLC_SET_PFIT)
aslc_stat |= asle_set_pfit(dev, ioread32(&asle->pfit));
if (aslc_req & ASLC_SET_PWM_FREQ)
aslc_stat |= asle_set_pwm_freq(dev, ioread32(&asle->pfmb));
if (aslc_req & ASLC_SUPPORTED_ROTATION_ANGLES)
aslc_stat |= asle_set_supported_rotation_angles(dev,
ioread32(&asle->srot));
if (aslc_req & ASLC_BUTTON_ARRAY)
aslc_stat |= asle_set_button_array(dev, ioread32(&asle->iuer));
if (aslc_req & ASLC_CONVERTIBLE_INDICATOR)
aslc_stat |= asle_set_convertible(dev, ioread32(&asle->iuer));
if (aslc_req & ASLC_DOCKING_INDICATOR)
aslc_stat |= asle_set_docking(dev, ioread32(&asle->iuer));
if (aslc_req & ASLC_ISCT_STATE_CHANGE)
aslc_stat |= asle_isct_state(dev);
iowrite32(aslc_stat, &asle->aslc);
}
void intel_opregion_asle_intr(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (dev_priv->opregion.asle)
schedule_work(&dev_priv->opregion.asle_work);
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
handle = ACPI_HANDLE(&dev->pdev->dev);
if (!handle || acpi_bus_get_device(handle, &acpi_dev))
return;
if (acpi_is_video_device(handle))
acpi_video_bus = acpi_dev;
else {
list_for_each_entry(acpi_cdev, &acpi_dev->children, node) {
if (acpi_is_video_device(acpi_cdev->handle)) {
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
dev_dbg(&dev->pdev->dev,
"More than 8 outputs detected via ACPI\n");
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
dev_dbg(&dev->pdev->dev,
"More than 8 outputs in connector list\n");
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
if (opregion->asle) {
iowrite32(ASLE_TCHE_BLC_EN, &opregion->asle->tche);
iowrite32(ASLE_ARDY_READY, &opregion->asle->ardy);
}
}
void intel_opregion_fini(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_opregion *opregion = &dev_priv->opregion;
if (!opregion->header)
return;
if (opregion->asle)
iowrite32(ASLE_ARDY_NOT_READY, &opregion->asle->ardy);
cancel_work_sync(&dev_priv->opregion.asle_work);
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
opregion->lid_state = NULL;
}
static void swsci_setup(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_opregion *opregion = &dev_priv->opregion;
bool requested_callbacks = false;
u32 tmp;
opregion->swsci_gbda_sub_functions = 1;
opregion->swsci_sbcb_sub_functions = 1;
if (swsci(dev, SWSCI_GBDA_SUPPORTED_CALLS, 0, &tmp) == 0) {
tmp <<= 1;
opregion->swsci_gbda_sub_functions |= tmp;
}
if (swsci(dev, SWSCI_GBDA_REQUESTED_CALLBACKS, 0, &tmp) == 0) {
opregion->swsci_sbcb_sub_functions |= tmp;
requested_callbacks = true;
}
if (swsci(dev, SWSCI_SBCB_SUPPORTED_CALLBACKS, 0, &tmp) == 0) {
u32 low = tmp & 0x7ff;
u32 high = tmp & ~0xfff;
tmp = (high << 4) | (low << 1) | 1;
if (requested_callbacks) {
u32 req = opregion->swsci_sbcb_sub_functions;
if ((req & tmp) != req)
DRM_DEBUG_DRIVER("SWSCI BIOS requested (%08x) SBCB callbacks that are not supported (%08x)\n", req, tmp);
} else {
opregion->swsci_sbcb_sub_functions |= tmp;
}
}
DRM_DEBUG_DRIVER("SWSCI GBDA callbacks %08x, SBCB callbacks %08x\n",
opregion->swsci_gbda_sub_functions,
opregion->swsci_sbcb_sub_functions);
}
static inline void swsci_setup(struct drm_device *dev) {}
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
#ifdef CONFIG_ACPI
INIT_WORK(&opregion->asle_work, asle_work);
#endif
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
swsci_setup(dev);
}
if (mboxes & MBOX_ASLE) {
DRM_DEBUG_DRIVER("ASLE supported\n");
opregion->asle = base + OPREGION_ASLE_OFFSET;
iowrite32(ASLE_ARDY_NOT_READY, &opregion->asle->ardy);
}
return 0;
err_out:
iounmap(base);
return err;
}
