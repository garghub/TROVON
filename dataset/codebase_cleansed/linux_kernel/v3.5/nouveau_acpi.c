static int nouveau_optimus_dsm(acpi_handle handle, int func, int arg, uint32_t *result)
{
struct acpi_buffer output = { ACPI_ALLOCATE_BUFFER, NULL };
struct acpi_object_list input;
union acpi_object params[4];
union acpi_object *obj;
int i, err;
char args_buff[4];
input.count = 4;
input.pointer = params;
params[0].type = ACPI_TYPE_BUFFER;
params[0].buffer.length = sizeof(nouveau_op_dsm_muid);
params[0].buffer.pointer = (char *)nouveau_op_dsm_muid;
params[1].type = ACPI_TYPE_INTEGER;
params[1].integer.value = 0x00000100;
params[2].type = ACPI_TYPE_INTEGER;
params[2].integer.value = func;
params[3].type = ACPI_TYPE_BUFFER;
params[3].buffer.length = 4;
for (i = 0; i < 4; i++)
args_buff[i] = (arg >> i * 8) & 0xFF;
params[3].buffer.pointer = args_buff;
err = acpi_evaluate_object(handle, "_DSM", &input, &output);
if (err) {
printk(KERN_INFO "failed to evaluate _DSM: %d\n", err);
return err;
}
obj = (union acpi_object *)output.pointer;
if (obj->type == ACPI_TYPE_INTEGER)
if (obj->integer.value == 0x80000002) {
return -ENODEV;
}
if (obj->type == ACPI_TYPE_BUFFER) {
if (obj->buffer.length == 4 && result) {
*result = 0;
*result |= obj->buffer.pointer[0];
*result |= (obj->buffer.pointer[1] << 8);
*result |= (obj->buffer.pointer[2] << 16);
*result |= (obj->buffer.pointer[3] << 24);
}
}
kfree(output.pointer);
return 0;
}
static int nouveau_dsm(acpi_handle handle, int func, int arg, uint32_t *result)
{
struct acpi_buffer output = { ACPI_ALLOCATE_BUFFER, NULL };
struct acpi_object_list input;
union acpi_object params[4];
union acpi_object *obj;
int err;
input.count = 4;
input.pointer = params;
params[0].type = ACPI_TYPE_BUFFER;
params[0].buffer.length = sizeof(nouveau_dsm_muid);
params[0].buffer.pointer = (char *)nouveau_dsm_muid;
params[1].type = ACPI_TYPE_INTEGER;
params[1].integer.value = 0x00000102;
params[2].type = ACPI_TYPE_INTEGER;
params[2].integer.value = func;
params[3].type = ACPI_TYPE_INTEGER;
params[3].integer.value = arg;
err = acpi_evaluate_object(handle, "_DSM", &input, &output);
if (err) {
printk(KERN_INFO "failed to evaluate _DSM: %d\n", err);
return err;
}
obj = (union acpi_object *)output.pointer;
if (obj->type == ACPI_TYPE_INTEGER)
if (obj->integer.value == 0x80000002)
return -ENODEV;
if (obj->type == ACPI_TYPE_BUFFER) {
if (obj->buffer.length == 4 && result) {
*result = 0;
*result |= obj->buffer.pointer[0];
*result |= (obj->buffer.pointer[1] << 8);
*result |= (obj->buffer.pointer[2] << 16);
*result |= (obj->buffer.pointer[3] << 24);
}
}
kfree(output.pointer);
return 0;
}
static int nouveau_test_dsm(acpi_handle test_handle,
int (*dsm_func)(acpi_handle, int, int, uint32_t *),
int sfnc)
{
u32 result = 0;
if (dsm_func(test_handle, 0, 0, &result))
return 0;
return result & 1 && result & (1 << sfnc);
}
static int nouveau_dsm_switch_mux(acpi_handle handle, int mux_id)
{
mxm_wmi_call_mxmx(mux_id == NOUVEAU_DSM_LED_STAMINA ? MXM_MXDS_ADAPTER_IGD : MXM_MXDS_ADAPTER_0);
mxm_wmi_call_mxds(mux_id == NOUVEAU_DSM_LED_STAMINA ? MXM_MXDS_ADAPTER_IGD : MXM_MXDS_ADAPTER_0);
return nouveau_dsm(handle, NOUVEAU_DSM_LED, mux_id, NULL);
}
static int nouveau_dsm_set_discrete_state(acpi_handle handle, enum vga_switcheroo_state state)
{
int arg;
if (state == VGA_SWITCHEROO_ON)
arg = NOUVEAU_DSM_POWER_SPEED;
else
arg = NOUVEAU_DSM_POWER_STAMINA;
nouveau_dsm(handle, NOUVEAU_DSM_POWER, arg, NULL);
return 0;
}
static int nouveau_dsm_switchto(enum vga_switcheroo_client_id id)
{
if (!nouveau_dsm_priv.dsm_detected && nouveau_dsm_priv.optimus_detected)
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
if (!nouveau_dsm_priv.dsm_detected && nouveau_dsm_priv.optimus_detected)
return 0;
return nouveau_dsm_set_discrete_state(nouveau_dsm_priv.dhandle, state);
}
static int nouveau_dsm_init(void)
{
return 0;
}
static int nouveau_dsm_get_client_id(struct pci_dev *pdev)
{
if (pdev->vendor == PCI_VENDOR_ID_INTEL)
return VGA_SWITCHEROO_IGD;
if (pdev->bus->number == 0)
return VGA_SWITCHEROO_IGD;
return VGA_SWITCHEROO_DIS;
}
static int nouveau_dsm_pci_probe(struct pci_dev *pdev)
{
acpi_handle dhandle, nvidia_handle;
acpi_status status;
int retval = 0;
dhandle = DEVICE_ACPI_HANDLE(&pdev->dev);
if (!dhandle)
return false;
status = acpi_get_handle(dhandle, "_DSM", &nvidia_handle);
if (ACPI_FAILURE(status)) {
return false;
}
if (nouveau_test_dsm(dhandle, nouveau_dsm, NOUVEAU_DSM_POWER))
retval |= NOUVEAU_DSM_HAS_MUX;
if (nouveau_test_dsm(dhandle, nouveau_optimus_dsm,
NOUVEAU_DSM_OPTIMUS_FN))
retval |= NOUVEAU_DSM_HAS_OPT;
if (retval)
nouveau_dsm_priv.dhandle = dhandle;
return retval;
}
static bool nouveau_dsm_detect(void)
{
char acpi_method_name[255] = { 0 };
struct acpi_buffer buffer = {sizeof(acpi_method_name), acpi_method_name};
struct pci_dev *pdev = NULL;
int has_dsm = 0;
int has_optimus = 0;
int vga_count = 0;
bool guid_valid;
int retval;
bool ret = false;
guid_valid = mxm_wmi_supported();
if (guid_valid)
printk("MXM: GUID detected in BIOS\n");
while ((pdev = pci_get_class(PCI_CLASS_DISPLAY_VGA << 8, pdev)) != NULL) {
vga_count++;
retval = nouveau_dsm_pci_probe(pdev);
if (retval & NOUVEAU_DSM_HAS_MUX)
has_dsm |= 1;
if (retval & NOUVEAU_DSM_HAS_OPT)
has_optimus = 1;
}
if (vga_count == 2 && has_dsm && guid_valid) {
acpi_get_name(nouveau_dsm_priv.dhandle, ACPI_FULL_PATHNAME,
&buffer);
printk(KERN_INFO "VGA switcheroo: detected DSM switching method %s handle\n",
acpi_method_name);
nouveau_dsm_priv.dsm_detected = true;
ret = true;
}
if (has_optimus == 1) {
acpi_get_name(nouveau_dsm_priv.dhandle, ACPI_FULL_PATHNAME,
&buffer);
printk(KERN_INFO "VGA switcheroo: detected Optimus DSM method %s handle\n",
acpi_method_name);
nouveau_dsm_priv.optimus_detected = true;
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
vga_switcheroo_register_handler(&nouveau_dsm_handler);
}
void nouveau_switcheroo_optimus_dsm(void)
{
u32 result = 0;
if (!nouveau_dsm_priv.optimus_detected)
return;
nouveau_optimus_dsm(nouveau_dsm_priv.dhandle, NOUVEAU_DSM_OPTIMUS_FN,
NOUVEAU_DSM_OPTIMUS_ARGS, &result);
}
void nouveau_unregister_dsm_handler(void)
{
if (nouveau_dsm_priv.optimus_detected || nouveau_dsm_priv.dsm_detected)
vga_switcheroo_unregister_handler();
}
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
memcpy(bios+offset, obj->buffer.pointer, len);
kfree(buffer.pointer);
return len;
}
bool nouveau_acpi_rom_supported(struct pci_dev *pdev)
{
acpi_status status;
acpi_handle dhandle, rom_handle;
if (!nouveau_dsm_priv.dsm_detected && !nouveau_dsm_priv.optimus_detected)
return false;
dhandle = DEVICE_ACPI_HANDLE(&pdev->dev);
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
int
nouveau_acpi_edid(struct drm_device *dev, struct drm_connector *connector)
{
struct nouveau_connector *nv_connector = nouveau_connector(connector);
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
return -EINVAL;
}
handle = DEVICE_ACPI_HANDLE(&dev->pdev->dev);
if (!handle)
return -ENODEV;
ret = acpi_bus_get_device(handle, &acpidev);
if (ret)
return -ENODEV;
ret = acpi_video_get_edid(acpidev, type, -1, &edid);
if (ret < 0)
return ret;
nv_connector->edid = kmemdup(edid, EDID_LENGTH, GFP_KERNEL);
return 0;
}
