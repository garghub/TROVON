static int swsci(struct drm_i915_private *dev_priv,
u32 function, u32 parm, u32 *parm_out)
{
struct opregion_swsci *swsci = dev_priv->opregion.swsci;
struct pci_dev *pdev = dev_priv->drm.pdev;
u32 main_function, sub_function, scic;
u16 swsci_val;
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
pci_read_config_word(pdev, SWSCI, &swsci_val);
if (!(swsci_val & SWSCI_SCISEL) || (swsci_val & SWSCI_GSSCIE)) {
swsci_val |= SWSCI_SCISEL;
swsci_val &= ~SWSCI_GSSCIE;
pci_write_config_word(pdev, SWSCI, swsci_val);
}
swsci_val |= SWSCI_GSSCIE;
pci_write_config_word(pdev, SWSCI, swsci_val);
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
struct drm_i915_private *dev_priv = to_i915(intel_encoder->base.dev);
u32 parm = 0;
u32 type = 0;
u32 port;
if (!HAS_DDI(dev_priv))
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
case INTEL_OUTPUT_DP:
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
return swsci(dev_priv, SWSCI_SBCB_DISPLAY_POWER_STATE, parm, NULL);
}
int intel_opregion_notify_adapter(struct drm_i915_private *dev_priv,
pci_power_t state)
{
int i;
if (!HAS_DDI(dev_priv))
return 0;
for (i = 0; i < ARRAY_SIZE(power_state_map); i++) {
if (state == power_state_map[i].pci_power_state)
return swsci(dev_priv, SWSCI_SBCB_ADAPTER_POWER_STATE,
power_state_map[i].parm, NULL);
}
return -EINVAL;
}
static u32 asle_set_backlight(struct drm_i915_private *dev_priv, u32 bclp)
{
struct intel_connector *connector;
struct drm_connector_list_iter conn_iter;
struct opregion_asle *asle = dev_priv->opregion.asle;
struct drm_device *dev = &dev_priv->drm;
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
drm_connector_list_iter_begin(dev, &conn_iter);
for_each_intel_connector_iter(connector, &conn_iter)
intel_panel_set_backlight_acpi(connector->base.state, bclp, 255);
drm_connector_list_iter_end(&conn_iter);
asle->cblv = DIV_ROUND_UP(bclp * 100, 255) | ASLE_CBLV_VALID;
drm_modeset_unlock(&dev->mode_config.connection_mutex);
return 0;
}
static u32 asle_set_als_illum(struct drm_i915_private *dev_priv, u32 alsi)
{
DRM_DEBUG_DRIVER("Illum is not supported\n");
return ASLC_ALS_ILLUM_FAILED;
}
static u32 asle_set_pwm_freq(struct drm_i915_private *dev_priv, u32 pfmb)
{
DRM_DEBUG_DRIVER("PWM freq is not supported\n");
return ASLC_PWM_FREQ_FAILED;
}
static u32 asle_set_pfit(struct drm_i915_private *dev_priv, u32 pfit)
{
DRM_DEBUG_DRIVER("Pfit is not supported\n");
return ASLC_PFIT_FAILED;
}
static u32 asle_set_supported_rotation_angles(struct drm_i915_private *dev_priv, u32 srot)
{
DRM_DEBUG_DRIVER("SROT is not supported\n");
return ASLC_ROTATION_ANGLES_FAILED;
}
static u32 asle_set_button_array(struct drm_i915_private *dev_priv, u32 iuer)
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
static u32 asle_set_convertible(struct drm_i915_private *dev_priv, u32 iuer)
{
if (iuer & ASLE_IUER_CONVERTIBLE)
DRM_DEBUG_DRIVER("Convertible is not supported (clamshell)\n");
else
DRM_DEBUG_DRIVER("Convertible is not supported (slate)\n");
return ASLC_CONVERTIBLE_FAILED;
}
static u32 asle_set_docking(struct drm_i915_private *dev_priv, u32 iuer)
{
if (iuer & ASLE_IUER_DOCKING)
DRM_DEBUG_DRIVER("Docking is not supported (docked)\n");
else
DRM_DEBUG_DRIVER("Docking is not supported (undocked)\n");
return ASLC_DOCKING_FAILED;
}
static u32 asle_isct_state(struct drm_i915_private *dev_priv)
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
aslc_stat |= asle_set_als_illum(dev_priv, asle->alsi);
if (aslc_req & ASLC_SET_BACKLIGHT)
aslc_stat |= asle_set_backlight(dev_priv, asle->bclp);
if (aslc_req & ASLC_SET_PFIT)
aslc_stat |= asle_set_pfit(dev_priv, asle->pfit);
if (aslc_req & ASLC_SET_PWM_FREQ)
aslc_stat |= asle_set_pwm_freq(dev_priv, asle->pfmb);
if (aslc_req & ASLC_SUPPORTED_ROTATION_ANGLES)
aslc_stat |= asle_set_supported_rotation_angles(dev_priv,
asle->srot);
if (aslc_req & ASLC_BUTTON_ARRAY)
aslc_stat |= asle_set_button_array(dev_priv, asle->iuer);
if (aslc_req & ASLC_CONVERTIBLE_INDICATOR)
aslc_stat |= asle_set_convertible(dev_priv, asle->iuer);
if (aslc_req & ASLC_DOCKING_INDICATOR)
aslc_stat |= asle_set_docking(dev_priv, asle->iuer);
if (aslc_req & ASLC_ISCT_STATE_CHANGE)
aslc_stat |= asle_isct_state(dev_priv);
asle->aslc = aslc_stat;
}
void intel_opregion_asle_intr(struct drm_i915_private *dev_priv)
{
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
static u32 acpi_display_type(struct intel_connector *connector)
{
u32 display_type;
switch (connector->base.connector_type) {
case DRM_MODE_CONNECTOR_VGA:
case DRM_MODE_CONNECTOR_DVIA:
display_type = ACPI_DISPLAY_TYPE_VGA;
break;
case DRM_MODE_CONNECTOR_Composite:
case DRM_MODE_CONNECTOR_SVIDEO:
case DRM_MODE_CONNECTOR_Component:
case DRM_MODE_CONNECTOR_9PinDIN:
case DRM_MODE_CONNECTOR_TV:
display_type = ACPI_DISPLAY_TYPE_TV;
break;
case DRM_MODE_CONNECTOR_DVII:
case DRM_MODE_CONNECTOR_DVID:
case DRM_MODE_CONNECTOR_DisplayPort:
case DRM_MODE_CONNECTOR_HDMIA:
case DRM_MODE_CONNECTOR_HDMIB:
display_type = ACPI_DISPLAY_TYPE_EXTERNAL_DIGITAL;
break;
case DRM_MODE_CONNECTOR_LVDS:
case DRM_MODE_CONNECTOR_eDP:
case DRM_MODE_CONNECTOR_DSI:
display_type = ACPI_DISPLAY_TYPE_INTERNAL_DIGITAL;
break;
case DRM_MODE_CONNECTOR_Unknown:
case DRM_MODE_CONNECTOR_VIRTUAL:
display_type = ACPI_DISPLAY_TYPE_OTHER;
break;
default:
MISSING_CASE(connector->base.connector_type);
display_type = ACPI_DISPLAY_TYPE_OTHER;
break;
}
return display_type;
}
static void intel_didl_outputs(struct drm_i915_private *dev_priv)
{
struct intel_opregion *opregion = &dev_priv->opregion;
struct intel_connector *connector;
struct drm_connector_list_iter conn_iter;
int i = 0, max_outputs;
int display_index[16] = {};
max_outputs = ARRAY_SIZE(opregion->acpi->didl) +
ARRAY_SIZE(opregion->acpi->did2);
drm_connector_list_iter_begin(&dev_priv->drm, &conn_iter);
for_each_intel_connector_iter(connector, &conn_iter) {
u32 device_id, type;
device_id = acpi_display_type(connector);
type = (device_id & ACPI_DISPLAY_TYPE_MASK)
>> ACPI_DISPLAY_TYPE_SHIFT;
device_id |= display_index[type]++ << ACPI_DISPLAY_INDEX_SHIFT;
connector->acpi_device_id = device_id;
if (i < max_outputs)
set_did(opregion, i, device_id);
i++;
}
drm_connector_list_iter_end(&conn_iter);
DRM_DEBUG_KMS("%d outputs detected\n", i);
if (i > max_outputs)
DRM_ERROR("More than %d outputs in connector list\n",
max_outputs);
if (i < max_outputs)
set_did(opregion, i, 0);
}
static void intel_setup_cadls(struct drm_i915_private *dev_priv)
{
struct intel_opregion *opregion = &dev_priv->opregion;
struct intel_connector *connector;
struct drm_connector_list_iter conn_iter;
int i = 0;
drm_connector_list_iter_begin(&dev_priv->drm, &conn_iter);
for_each_intel_connector_iter(connector, &conn_iter) {
if (i >= ARRAY_SIZE(opregion->acpi->cadl))
break;
opregion->acpi->cadl[i++] = connector->acpi_device_id;
}
drm_connector_list_iter_end(&conn_iter);
if (i < ARRAY_SIZE(opregion->acpi->cadl))
opregion->acpi->cadl[i] = 0;
}
void intel_opregion_register(struct drm_i915_private *dev_priv)
{
struct intel_opregion *opregion = &dev_priv->opregion;
if (!opregion->header)
return;
if (opregion->acpi) {
intel_didl_outputs(dev_priv);
intel_setup_cadls(dev_priv);
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
void intel_opregion_unregister(struct drm_i915_private *dev_priv)
{
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
if (opregion->vbt_firmware) {
kfree(opregion->vbt_firmware);
opregion->vbt_firmware = NULL;
}
opregion->header = NULL;
opregion->acpi = NULL;
opregion->swsci = NULL;
opregion->asle = NULL;
opregion->vbt = NULL;
opregion->lid_state = NULL;
}
static void swsci_setup(struct drm_i915_private *dev_priv)
{
struct intel_opregion *opregion = &dev_priv->opregion;
bool requested_callbacks = false;
u32 tmp;
opregion->swsci_gbda_sub_functions = 1;
opregion->swsci_sbcb_sub_functions = 1;
if (swsci(dev_priv, SWSCI_GBDA_SUPPORTED_CALLS, 0, &tmp) == 0) {
tmp <<= 1;
opregion->swsci_gbda_sub_functions |= tmp;
}
if (swsci(dev_priv, SWSCI_GBDA_REQUESTED_CALLBACKS, 0, &tmp) == 0) {
opregion->swsci_sbcb_sub_functions |= tmp;
requested_callbacks = true;
}
if (swsci(dev_priv, SWSCI_SBCB_SUPPORTED_CALLBACKS, 0, &tmp) == 0) {
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
static int intel_no_opregion_vbt_callback(const struct dmi_system_id *id)
{
DRM_DEBUG_KMS("Falling back to manually reading VBT from "
"VBIOS ROM for %s\n", id->ident);
return 1;
}
static int intel_load_vbt_firmware(struct drm_i915_private *dev_priv)
{
struct intel_opregion *opregion = &dev_priv->opregion;
const struct firmware *fw = NULL;
const char *name = i915.vbt_firmware;
int ret;
if (!name || !*name)
return -ENOENT;
ret = request_firmware(&fw, name, &dev_priv->drm.pdev->dev);
if (ret) {
DRM_ERROR("Requesting VBT firmware \"%s\" failed (%d)\n",
name, ret);
return ret;
}
if (intel_bios_is_valid_vbt(fw->data, fw->size)) {
opregion->vbt_firmware = kmemdup(fw->data, fw->size, GFP_KERNEL);
if (opregion->vbt_firmware) {
DRM_DEBUG_KMS("Found valid VBT firmware \"%s\"\n", name);
opregion->vbt = opregion->vbt_firmware;
opregion->vbt_size = fw->size;
ret = 0;
} else {
ret = -ENOMEM;
}
} else {
DRM_DEBUG_KMS("Invalid VBT firmware \"%s\"\n", name);
ret = -EINVAL;
}
release_firmware(fw);
return ret;
}
int intel_opregion_setup(struct drm_i915_private *dev_priv)
{
struct intel_opregion *opregion = &dev_priv->opregion;
struct pci_dev *pdev = dev_priv->drm.pdev;
u32 asls, mboxes;
char buf[sizeof(OPREGION_SIGNATURE)];
int err = 0;
void *base;
const void *vbt;
u32 vbt_size;
BUILD_BUG_ON(sizeof(struct opregion_header) != 0x100);
BUILD_BUG_ON(sizeof(struct opregion_acpi) != 0x100);
BUILD_BUG_ON(sizeof(struct opregion_swsci) != 0x100);
BUILD_BUG_ON(sizeof(struct opregion_asle) != 0x100);
BUILD_BUG_ON(sizeof(struct opregion_asle_ext) != 0x400);
pci_read_config_dword(pdev, ASLS, &asls);
DRM_DEBUG_DRIVER("graphic opregion physical addr: 0x%x\n", asls);
if (asls == 0) {
DRM_DEBUG_DRIVER("ACPI OpRegion not supported!\n");
return -ENOTSUPP;
}
INIT_WORK(&opregion->asle_work, asle_work);
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
swsci_setup(dev_priv);
}
if (mboxes & MBOX_ASLE) {
DRM_DEBUG_DRIVER("ASLE supported\n");
opregion->asle = base + OPREGION_ASLE_OFFSET;
opregion->asle->ardy = ASLE_ARDY_NOT_READY;
}
if (mboxes & MBOX_ASLE_EXT)
DRM_DEBUG_DRIVER("ASLE extension supported\n");
if (intel_load_vbt_firmware(dev_priv) == 0)
goto out;
if (dmi_check_system(intel_no_opregion_vbt))
goto out;
if (opregion->header->opregion_ver >= 2 && opregion->asle &&
opregion->asle->rvda && opregion->asle->rvds) {
opregion->rvda = memremap(opregion->asle->rvda,
opregion->asle->rvds,
MEMREMAP_WB);
vbt = opregion->rvda;
vbt_size = opregion->asle->rvds;
if (intel_bios_is_valid_vbt(vbt, vbt_size)) {
DRM_DEBUG_KMS("Found valid VBT in ACPI OpRegion (RVDA)\n");
opregion->vbt = vbt;
opregion->vbt_size = vbt_size;
goto out;
} else {
DRM_DEBUG_KMS("Invalid VBT in ACPI OpRegion (RVDA)\n");
}
}
vbt = base + OPREGION_VBT_OFFSET;
vbt_size = (mboxes & MBOX_ASLE_EXT) ?
OPREGION_ASLE_EXT_OFFSET : OPREGION_SIZE;
vbt_size -= OPREGION_VBT_OFFSET;
if (intel_bios_is_valid_vbt(vbt, vbt_size)) {
DRM_DEBUG_KMS("Found valid VBT in ACPI OpRegion (Mailbox #4)\n");
opregion->vbt = vbt;
opregion->vbt_size = vbt_size;
} else {
DRM_DEBUG_KMS("Invalid VBT in ACPI OpRegion (Mailbox #4)\n");
}
out:
return 0;
err_out:
memunmap(base);
return err;
}
static int intel_use_opregion_panel_type_callback(const struct dmi_system_id *id)
{
DRM_INFO("Using panel type from OpRegion on %s\n", id->ident);
return 1;
}
int
intel_opregion_get_panel_type(struct drm_i915_private *dev_priv)
{
u32 panel_details;
int ret;
ret = swsci(dev_priv, SWSCI_GBDA_PANEL_DETAILS, 0x0, &panel_details);
if (ret) {
DRM_DEBUG_KMS("Failed to get panel details from OpRegion (%d)\n",
ret);
return ret;
}
ret = (panel_details >> 8) & 0xff;
if (ret > 0x10) {
DRM_DEBUG_KMS("Invalid OpRegion panel type 0x%x\n", ret);
return -EINVAL;
}
if (ret == 0x0) {
DRM_DEBUG_KMS("No panel type in OpRegion\n");
return -ENODEV;
}
if (!dmi_check_system(intel_use_opregion_panel_type)) {
DRM_DEBUG_KMS("Ignoring OpRegion panel type (%d)\n", ret - 1);
return -ENODEV;
}
return ret - 1;
}
