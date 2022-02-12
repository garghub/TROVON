bool nouveau_is_optimus(void) {
return nouveau_dsm_priv.optimus_detected;
}
bool nouveau_is_v1_dsm(void) {
return nouveau_dsm_priv.dsm_detected;
}
static int nouveau_optimus_dsm(acpi_handle handle, int func, int arg, uint32_t *result)
{
int i;
union acpi_object *obj;
char args_buff[4];
union acpi_object argv4 = {
.buffer.type = ACPI_TYPE_BUFFER,
.buffer.length = 4,
.buffer.pointer = args_buff
};
for (i = 0; i < 4; i++)
args_buff[i] = (arg >> i * 8) & 0xFF;
*result = 0;
obj = acpi_evaluate_dsm_typed(handle, nouveau_op_dsm_muid, 0x00000100,
func, &argv4, ACPI_TYPE_BUFFER);
if (!obj) {
acpi_handle_info(handle, "failed to evaluate _DSM\n");
return AE_ERROR;
} else {
if (obj->buffer.length == 4) {
*result |= obj->buffer.pointer[0];
*result |= (obj->buffer.pointer[1] << 8);
*result |= (obj->buffer.pointer[2] << 16);
*result |= (obj->buffer.pointer[3] << 24);
}
ACPI_FREE(obj);
}
return 0;
}
static int nouveau_dsm_get_optimus_functions(acpi_handle handle)
{
int result;
if (nouveau_optimus_dsm(handle, 0, 0, &result))
return 0;
if (result & 1 && result & (1 << NOUVEAU_DSM_OPTIMUS_CAPS))
return result;
return 0;
}
static int nouveau_dsm(acpi_handle handle, int func, int arg)
{
int ret = 0;
union acpi_object *obj;
union acpi_object argv4 = {
.integer.type = ACPI_TYPE_INTEGER,
.integer.value = arg,
};
obj = acpi_evaluate_dsm_typed(handle, nouveau_dsm_muid, 0x00000102,
func, &argv4, ACPI_TYPE_INTEGER);
if (!obj) {
acpi_handle_info(handle, "failed to evaluate _DSM\n");
return AE_ERROR;
} else {
if (obj->integer.value == 0x80000002)
ret = -ENODEV;
ACPI_FREE(obj);
}
return ret;
}
static int nouveau_dsm_switch_mux(acpi_handle handle, int mux_id)
{
mxm_wmi_call_mxmx(mux_id == NOUVEAU_DSM_LED_STAMINA ? MXM_MXDS_ADAPTER_IGD : MXM_MXDS_ADAPTER_0);
mxm_wmi_call_mxds(mux_id == NOUVEAU_DSM_LED_STAMINA ? MXM_MXDS_ADAPTER_IGD : MXM_MXDS_ADAPTER_0);
return nouveau_dsm(handle, NOUVEAU_DSM_LED, mux_id);
}
static int nouveau_dsm_set_discrete_state(acpi_handle handle, enum vga_switcheroo_state state)
{
int arg;
if (state == VGA_SWITCHEROO_ON)
arg = NOUVEAU_DSM_POWER_SPEED;
else
arg = NOUVEAU_DSM_POWER_STAMINA;
nouveau_dsm(handle, NOUVEAU_DSM_POWER, arg);
return 0;
}
static int nouveau_dsm_switchto(enum vga_switcheroo_client_id id)
{
if (!nouveau_dsm_priv.dsm_detected)
return 0;
if (id == VGA_SWITCHEROO_IGD)
return nouveau_dsm_switch_mux(nouveau_dsm_priv.dhandle, NOUVEAU_DSM_LED_STAMINA);
else
return nouveau_dsm_switch_mux(nouveau_dsm_priv.dhandle, NOUVEAU_DSM_LED_SPEED);
}
static int nouveau_dsm_power_state(enum vga_switcheroo_client_id id,
enum vga_switcheroo_state state)
{
if (id == VGA_SWITCHEROO_IGD)
return 0;
if (!nouveau_dsm_priv.dsm_detected)
return 0;
return nouveau_dsm_set_discrete_state(nouveau_dsm_priv.dhandle, state);
}
static int nouveau_dsm_get_client_id(struct pci_dev *pdev)
{
if (pdev->vendor == PCI_VENDOR_ID_INTEL)
return VGA_SWITCHEROO_IGD;
if (pdev->bus->number == 0)
return VGA_SWITCHEROO_IGD;
return VGA_SWITCHEROO_DIS;
}
static bool nouveau_pr3_present(struct pci_dev *pdev)
{
struct pci_dev *parent_pdev = pci_upstream_bridge(pdev);
struct acpi_device *parent_adev;
if (!parent_pdev)
return false;
if (!parent_pdev->bridge_d3) {
pci_d3cold_disable(pdev);
return false;
}
parent_adev = ACPI_COMPANION(&parent_pdev->dev);
if (!parent_adev)
return false;
return acpi_has_method(parent_adev->handle, "_PR3");
}
static void nouveau_dsm_pci_probe(struct pci_dev *pdev, acpi_handle *dhandle_out,
bool *has_mux, bool *has_opt,
bool *has_opt_flags, bool *has_pr3)
{
acpi_handle dhandle;
bool supports_mux;
int optimus_funcs;
dhandle = ACPI_HANDLE(&pdev->dev);
if (!dhandle)
return;
if (!acpi_has_method(dhandle, "_DSM"))
return;
supports_mux = acpi_check_dsm(dhandle, nouveau_dsm_muid, 0x00000102,
1 << NOUVEAU_DSM_POWER);
optimus_funcs = nouveau_dsm_get_optimus_functions(dhandle);
if (!supports_mux && !optimus_funcs)
return;
*dhandle_out = dhandle;
*has_mux = supports_mux;
*has_opt = !!optimus_funcs;
*has_opt_flags = optimus_funcs & (1 << NOUVEAU_DSM_OPTIMUS_FLAGS);
*has_pr3 = false;
if (optimus_funcs) {
uint32_t result;
nouveau_optimus_dsm(dhandle, NOUVEAU_DSM_OPTIMUS_CAPS, 0,
&result);
dev_info(&pdev->dev, "optimus capabilities: %s, status %s%s\n",
(result & OPTIMUS_ENABLED) ? "enabled" : "disabled",
(result & OPTIMUS_DYNAMIC_PWR_CAP) ? "dynamic power, " : "",
(result & OPTIMUS_HDA_CODEC_MASK) ? "hda bios codec supported" : "");
*has_pr3 = nouveau_pr3_present(pdev);
}
}
static bool nouveau_dsm_detect(void)
{
char acpi_method_name[255] = { 0 };
struct acpi_buffer buffer = {sizeof(acpi_method_name), acpi_method_name};
struct pci_dev *pdev = NULL;
acpi_handle dhandle = NULL;
bool has_mux = false;
bool has_optimus = false;
bool has_optimus_flags = false;
bool has_power_resources = false;
int vga_count = 0;
bool guid_valid;
bool ret = false;
guid_valid = mxm_wmi_supported();
if (guid_valid)
printk("MXM: GUID detected in BIOS\n");
while ((pdev = pci_get_class(PCI_CLASS_DISPLAY_VGA << 8, pdev)) != NULL) {
vga_count++;
nouveau_dsm_pci_probe(pdev, &dhandle, &has_mux, &has_optimus,
&has_optimus_flags, &has_power_resources);
}
while ((pdev = pci_get_class(PCI_CLASS_DISPLAY_3D << 8, pdev)) != NULL) {
vga_count++;
nouveau_dsm_pci_probe(pdev, &dhandle, &has_mux, &has_optimus,
&has_optimus_flags, &has_power_resources);
}
if (has_optimus) {
nouveau_dsm_priv.dhandle = dhandle;
acpi_get_name(nouveau_dsm_priv.dhandle, ACPI_FULL_PATHNAME,
&buffer);
printk(KERN_INFO "VGA switcheroo: detected Optimus DSM method %s handle\n",
acpi_method_name);
if (has_power_resources)
pr_info("nouveau: detected PR support, will not use DSM\n");
nouveau_dsm_priv.optimus_detected = true;
nouveau_dsm_priv.optimus_flags_detected = has_optimus_flags;
nouveau_dsm_priv.optimus_skip_dsm = has_power_resources;
ret = true;
} else if (vga_count == 2 && has_mux && guid_valid) {
nouveau_dsm_priv.dhandle = dhandle;
acpi_get_name(nouveau_dsm_priv.dhandle, ACPI_FULL_PATHNAME,
&buffer);
printk(KERN_INFO "VGA switcheroo: detected DSM switching method %s handle\n",
acpi_method_name);
nouveau_dsm_priv.dsm_detected = true;
ret = true;
}
return ret;
}
void nouveau_register_dsm_handler(void)
{
bool r;
r = nouveau_dsm_detect();
if (!r)
return;
vga_switcheroo_register_handler(&nouveau_dsm_handler, 0);
}
void nouveau_switcheroo_optimus_dsm(void)
{
u32 result = 0;
if (!nouveau_dsm_priv.optimus_detected || nouveau_dsm_priv.optimus_skip_dsm)
return;
if (nouveau_dsm_priv.optimus_flags_detected)
nouveau_optimus_dsm(nouveau_dsm_priv.dhandle, NOUVEAU_DSM_OPTIMUS_FLAGS,
0x3, &result);
nouveau_optimus_dsm(nouveau_dsm_priv.dhandle, NOUVEAU_DSM_OPTIMUS_CAPS,
NOUVEAU_DSM_OPTIMUS_SET_POWERDOWN, &result);
}
void nouveau_unregister_dsm_handler(void)
{
if (nouveau_dsm_priv.optimus_detected || nouveau_dsm_priv.dsm_detected)
vga_switcheroo_unregister_handler();
}
void nouveau_register_dsm_handler(void) {}
void nouveau_unregister_dsm_handler(void) {}
void nouveau_switcheroo_optimus_dsm(void) {}
static int nouveau_rom_call(acpi_handle rom_handle, uint8_t *bios,
int offset, int len)
{
acpi_status status;
union acpi_object rom_arg_elements[2], *obj;
struct acpi_object_list rom_arg;
struct acpi_buffer buffer = { ACPI_ALLOCATE_BUFFER, NULL};
rom_arg.count = 2;
rom_arg.pointer = &rom_arg_elements[0];
rom_arg_elements[0].type = ACPI_TYPE_INTEGER;
rom_arg_elements[0].integer.value = offset;
rom_arg_elements[1].type = ACPI_TYPE_INTEGER;
rom_arg_elements[1].integer.value = len;
status = acpi_evaluate_object(rom_handle, NULL, &rom_arg, &buffer);
if (ACPI_FAILURE(status)) {
printk(KERN_INFO "failed to evaluate ROM got %s\n", acpi_format_exception(status));
return -ENODEV;
}
obj = (union acpi_object *)buffer.pointer;
len = min(len, (int)obj->buffer.length);
memcpy(bios+offset, obj->buffer.pointer, len);
kfree(buffer.pointer);
return len;
}
bool nouveau_acpi_rom_supported(struct device *dev)
{
acpi_status status;
acpi_handle dhandle, rom_handle;
dhandle = ACPI_HANDLE(dev);
if (!dhandle)
return false;
status = acpi_get_handle(dhandle, "_ROM", &rom_handle);
if (ACPI_FAILURE(status))
return false;
nouveau_dsm_priv.rom_handle = rom_handle;
return true;
}
int nouveau_acpi_get_bios_chunk(uint8_t *bios, int offset, int len)
{
return nouveau_rom_call(nouveau_dsm_priv.rom_handle, bios, offset, len);
}
void *
nouveau_acpi_edid(struct drm_device *dev, struct drm_connector *connector)
{
struct acpi_device *acpidev;
acpi_handle handle;
int type, ret;
void *edid;
switch (connector->connector_type) {
case DRM_MODE_CONNECTOR_LVDS:
case DRM_MODE_CONNECTOR_eDP:
type = ACPI_VIDEO_DISPLAY_LCD;
break;
default:
return NULL;
}
handle = ACPI_HANDLE(&dev->pdev->dev);
if (!handle)
return NULL;
ret = acpi_bus_get_device(handle, &acpidev);
if (ret)
return NULL;
ret = acpi_video_get_edid(acpidev, type, -1, &edid);
if (ret < 0)
return NULL;
return kmemdup(edid, EDID_LENGTH, GFP_KERNEL);
}
