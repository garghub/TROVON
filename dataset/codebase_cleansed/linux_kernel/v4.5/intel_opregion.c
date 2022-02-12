static int swsci(struct drm_device *dev, u32 function, u32 parm, u32 *parm_out)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct opregion_swsci *swsci = dev_priv->opregion.swsci;
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
dslp = swsci->dslp;
if (!dslp) {
dslp = 50;
} else if (dslp > MAX_DSLP) {
DRM_INFO_ONCE("ACPI BIOS requests an excessive sleep of %u ms, "
"using %u ms instead\n", dslp, MAX_DSLP);
dslp = MAX_DSLP;
}
scic = swsci->scic;
if (scic & SWSCI_SCIC_INDICATOR) {
DRM_DEBUG_DRIVER("SWSCI request already in progress\n");
return -EBUSY;
}
scic = function | SWSCI_SCIC_INDICATOR;
swsci->parm = parm;
swsci->scic = scic;
pci_read_config_word(dev->pdev, PCI_SWSCI, &pci_swsci);
if (!(pci_swsci & PCI_SWSCI_SCISEL) || (pci_swsci & PCI_SWSCI_GSSCIE)) {
pci_swsci |= PCI_SWSCI_SCISEL;
pci_swsci &= ~PCI_SWSCI_GSSCIE;
pci_write_config_word(dev->pdev, PCI_SWSCI, pci_swsci);
}
pci_swsci |= PCI_SWSCI_GSSCIE;
pci_write_config_word(dev->pdev, PCI_SWSCI, pci_swsci);
#define C (((scic = swsci->scic) & SWSCI_SCIC_INDICATOR) == 0)
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
*parm_out = swsci->parm;
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
if (intel_encoder->type == INTEL_OUTPUT_DSI)
port = 0;
else
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
case INTEL_OUTPUT_DP_MST:
type = DISPLAY_TYPE_EXTERNAL_FLAT_PANEL;
break;
case INTEL_OUTPUT_EDP:
case INTEL_OUTPUT_DSI:
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
struct intel_connector *connector;
struct opregion_asle *asle = dev_priv->opregion.asle;
DRM_DEBUG_DRIVER("bclp = 0x%08x\n", bclp);
if (acpi_video_get_backlight_type() == acpi_backlight_native) {
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
for_each_intel_connector(dev, connector)
intel_panel_set_backlight_acpi(connector, bclp, 255);
asle->cblv = DIV_ROUND_UP(bclp * 100, 255) | ASLE_CBLV_VALID;
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
struct opregion_asle *asle = dev_priv->opregion.asle;
u32 aslc_stat = 0;
u32 aslc_req;
if (!asle)
return;
aslc_req = asle->aslc;
if (!(aslc_req & ASLC_REQ_MSK)) {
DRM_DEBUG_DRIVER("No request on ASLC interrupt 0x%08x\n",
aslc_req);
return;
}
if (aslc_req & ASLC_SET_ALS_ILLUM)
aslc_stat |= asle_set_als_illum(dev, asle->alsi);
if (aslc_req & ASLC_SET_BACKLIGHT)
aslc_stat |= asle_set_backlight(dev, asle->bclp);
if (aslc_req & ASLC_SET_PFIT)
aslc_stat |= asle_set_pfit(dev, asle->pfit);
if (aslc_req & ASLC_SET_PWM_FREQ)
aslc_stat |= asle_set_pwm_freq(dev, asle->pfmb);
if (aslc_req & ASLC_SUPPORTED_ROTATION_ANGLES)
aslc_stat |= asle_set_supported_rotation_angles(dev,
asle->srot);
if (aslc_req & ASLC_BUTTON_ARRAY)
aslc_stat |= asle_set_button_array(dev, asle->iuer);
if (aslc_req & ASLC_CONVERTIBLE_INDICATOR)
aslc_stat |= asle_set_convertible(dev, asle->iuer);
if (aslc_req & ASLC_DOCKING_INDICATOR)
aslc_stat |= asle_set_docking(dev, asle->iuer);
if (aslc_req & ASLC_ISCT_STATE_CHANGE)
aslc_stat |= asle_isct_state(dev);
asle->aslc = aslc_stat;
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
struct acpi_bus_event *event = data;
struct opregion_acpi *acpi;
int ret = NOTIFY_OK;
if (strcmp(event->device_class, ACPI_VIDEO_CLASS) != 0)
return NOTIFY_DONE;
if (!system_opregion)
return NOTIFY_DONE;
acpi = system_opregion->acpi;
if (event->type == 0x80 && ((acpi->cevt & 1) == 0))
ret = NOTIFY_BAD;
acpi->csts = 0;
return ret;
}
static u32 get_did(struct intel_opregion *opregion, int i)
{
u32 did;
if (i < ARRAY_SIZE(opregion->acpi->didl)) {
did = opregion->acpi->didl[i];
} else {
i -= ARRAY_SIZE(opregion->acpi->didl);
if (WARN_ON(i >= ARRAY_SIZE(opregion->acpi->did2)))
return 0;
did = opregion->acpi->did2[i];
}
return did;
}
static void set_did(struct intel_opregion *opregion, int i, u32 val)
{
if (i < ARRAY_SIZE(opregion->acpi->didl)) {
opregion->acpi->didl[i] = val;
} else {
i -= ARRAY_SIZE(opregion->acpi->didl);
if (WARN_ON(i >= ARRAY_SIZE(opregion->acpi->did2)))
return;
opregion->acpi->did2[i] = val;
}
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
u32 temp, max_outputs;
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
DRM_DEBUG_KMS("No ACPI video bus found\n");
return;
}
max_outputs = ARRAY_SIZE(opregion->acpi->didl) +
ARRAY_SIZE(opregion->acpi->did2);
list_for_each_entry(acpi_cdev, &acpi_video_bus->children, node) {
if (i >= max_outputs) {
DRM_DEBUG_KMS("More than %u outputs detected via ACPI\n",
max_outputs);
return;
}
status = acpi_evaluate_integer(acpi_cdev->handle, "_ADR",
NULL, &device_id);
if (ACPI_SUCCESS(status)) {
if (!device_id)
goto blind_set;
set_did(opregion, i++, (u32)(device_id & 0x0f0f));
}
}
end:
DRM_DEBUG_KMS("%d outputs detected\n", i);
if (i < max_outputs)
set_did(opregion, i, 0);
return;
blind_set:
i = 0;
list_for_each_entry(connector, &dev->mode_config.connector_list, head) {
int output_type = ACPI_OTHER_OUTPUT;
if (i >= max_outputs) {
DRM_DEBUG_KMS("More than %u outputs in connector list\n",
max_outputs);
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
temp = get_did(opregion, i);
set_did(opregion, i, temp | (1 << 31) | output_type | i);
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
disp_id = get_did(opregion, i);
opregion->acpi->cadl[i] = disp_id;
} while (++i < 8 && disp_id != 0);
}
void intel_opregion_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_opregion *opregion = &dev_priv->opregion;
if (!opregion->header)
return;
if (opregion->acpi) {
intel_didl_outputs(dev);
intel_setup_cadls(dev);
opregion->acpi->csts = 0;
opregion->acpi->drdy = 1;
system_opregion = opregion;
register_acpi_notifier(&intel_opregion_notifier);
}
if (opregion->asle) {
opregion->asle->tche = ASLE_TCHE_BLC_EN;
opregion->asle->ardy = ASLE_ARDY_READY;
}
}
void intel_opregion_fini(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_opregion *opregion = &dev_priv->opregion;
if (!opregion->header)
return;
if (opregion->asle)
opregion->asle->ardy = ASLE_ARDY_NOT_READY;
cancel_work_sync(&dev_priv->opregion.asle_work);
if (opregion->acpi) {
opregion->acpi->drdy = 0;
system_opregion = NULL;
unregister_acpi_notifier(&intel_opregion_notifier);
}
memunmap(opregion->header);
if (opregion->rvda) {
memunmap(opregion->rvda);
opregion->rvda = NULL;
}
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
static int intel_no_opregion_vbt_callback(const struct dmi_system_id *id)
{
DRM_DEBUG_KMS("Falling back to manually reading VBT from "
"VBIOS ROM for %s\n", id->ident);
return 1;
}
int intel_opregion_setup(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_opregion *opregion = &dev_priv->opregion;
u32 asls, mboxes;
char buf[sizeof(OPREGION_SIGNATURE)];
int err = 0;
void *base;
BUILD_BUG_ON(sizeof(struct opregion_header) != 0x100);
BUILD_BUG_ON(sizeof(struct opregion_acpi) != 0x100);
BUILD_BUG_ON(sizeof(struct opregion_swsci) != 0x100);
BUILD_BUG_ON(sizeof(struct opregion_asle) != 0x100);
BUILD_BUG_ON(sizeof(struct opregion_asle_ext) != 0x400);
pci_read_config_dword(dev->pdev, PCI_ASLS, &asls);
DRM_DEBUG_DRIVER("graphic opregion physical addr: 0x%x\n", asls);
if (asls == 0) {
DRM_DEBUG_DRIVER("ACPI OpRegion not supported!\n");
return -ENOTSUPP;
}
#ifdef CONFIG_ACPI
INIT_WORK(&opregion->asle_work, asle_work);
#endif
base = memremap(asls, OPREGION_SIZE, MEMREMAP_WB);
if (!base)
return -ENOMEM;
memcpy(buf, base, sizeof(buf));
if (memcmp(buf, OPREGION_SIGNATURE, 16)) {
DRM_DEBUG_DRIVER("opregion signature mismatch\n");
err = -EINVAL;
goto err_out;
}
opregion->header = base;
opregion->lid_state = base + ACPI_CLID;
mboxes = opregion->header->mboxes;
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
opregion->asle->ardy = ASLE_ARDY_NOT_READY;
}
if (mboxes & MBOX_ASLE_EXT)
DRM_DEBUG_DRIVER("ASLE extension supported\n");
if (!dmi_check_system(intel_no_opregion_vbt)) {
const void *vbt = NULL;
u32 vbt_size = 0;
if (opregion->header->opregion_ver >= 2 && opregion->asle &&
opregion->asle->rvda && opregion->asle->rvds) {
opregion->rvda = memremap(opregion->asle->rvda,
opregion->asle->rvds,
MEMREMAP_WB);
vbt = opregion->rvda;
vbt_size = opregion->asle->rvds;
}
if (intel_bios_is_valid_vbt(vbt, vbt_size)) {
DRM_DEBUG_KMS("Found valid VBT in ACPI OpRegion (RVDA)\n");
opregion->vbt = vbt;
opregion->vbt_size = vbt_size;
} else {
vbt = base + OPREGION_VBT_OFFSET;
vbt_size = OPREGION_ASLE_EXT_OFFSET - OPREGION_VBT_OFFSET;
if (intel_bios_is_valid_vbt(vbt, vbt_size)) {
DRM_DEBUG_KMS("Found valid VBT in ACPI OpRegion (Mailbox #4)\n");
opregion->vbt = vbt;
opregion->vbt_size = vbt_size;
}
}
}
return 0;
err_out:
memunmap(base);
return err;
}
