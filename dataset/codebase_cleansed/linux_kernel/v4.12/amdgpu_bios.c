static bool check_atom_bios(uint8_t *bios, size_t size)
{
uint16_t tmp, bios_header_start;
if (!bios || size < 0x49) {
DRM_INFO("vbios mem is null or mem size is wrong\n");
return false;
}
if (!AMD_IS_VALID_VBIOS(bios)) {
DRM_INFO("BIOS signature incorrect %x %x\n", bios[0], bios[1]);
return false;
}
tmp = bios[0x18] | (bios[0x19] << 8);
if (bios[tmp + 0x14] != 0x0) {
DRM_INFO("Not an x86 BIOS ROM\n");
return false;
}
bios_header_start = bios[0x48] | (bios[0x49] << 8);
if (!bios_header_start) {
DRM_INFO("Can't locate bios header\n");
return false;
}
tmp = bios_header_start + 4;
if (size < tmp) {
DRM_INFO("BIOS header is broken\n");
return false;
}
if (!memcmp(bios + tmp, "ATOM", 4) ||
!memcmp(bios + tmp, "MOTA", 4)) {
DRM_DEBUG("ATOMBIOS detected\n");
return true;
}
return false;
}
static bool is_atom_fw(uint8_t *bios)
{
uint16_t bios_header_start = bios[0x48] | (bios[0x49] << 8);
uint8_t frev = bios[bios_header_start + 2];
uint8_t crev = bios[bios_header_start + 3];
if ((frev < 3) ||
((frev == 3) && (crev < 3)))
return false;
return true;
}
static bool igp_read_bios_from_vram(struct amdgpu_device *adev)
{
uint8_t __iomem *bios;
resource_size_t vram_base;
resource_size_t size = 256 * 1024;
if (!(adev->flags & AMD_IS_APU))
if (amdgpu_need_post(adev))
return false;
adev->bios = NULL;
vram_base = pci_resource_start(adev->pdev, 0);
bios = ioremap(vram_base, size);
if (!bios) {
return false;
}
adev->bios = kmalloc(size, GFP_KERNEL);
if (!adev->bios) {
iounmap(bios);
return false;
}
adev->bios_size = size;
memcpy_fromio(adev->bios, bios, size);
iounmap(bios);
if (!check_atom_bios(adev->bios, size)) {
kfree(adev->bios);
return false;
}
return true;
}
bool amdgpu_read_bios(struct amdgpu_device *adev)
{
uint8_t __iomem *bios;
size_t size;
adev->bios = NULL;
bios = pci_map_rom(adev->pdev, &size);
if (!bios) {
return false;
}
adev->bios = kzalloc(size, GFP_KERNEL);
if (adev->bios == NULL) {
pci_unmap_rom(adev->pdev, bios);
return false;
}
adev->bios_size = size;
memcpy_fromio(adev->bios, bios, size);
pci_unmap_rom(adev->pdev, bios);
if (!check_atom_bios(adev->bios, size)) {
kfree(adev->bios);
return false;
}
return true;
}
static bool amdgpu_read_bios_from_rom(struct amdgpu_device *adev)
{
u8 header[AMD_VBIOS_SIGNATURE_END+1] = {0};
int len;
if (!adev->asic_funcs->read_bios_from_rom)
return false;
if (amdgpu_asic_read_bios_from_rom(adev, &header[0], sizeof(header)) == false)
return false;
header[AMD_VBIOS_SIGNATURE_END] = 0;
if ((!AMD_IS_VALID_VBIOS(header)) ||
0 != memcmp((char *)&header[AMD_VBIOS_SIGNATURE_OFFSET],
AMD_VBIOS_SIGNATURE,
strlen(AMD_VBIOS_SIGNATURE)))
return false;
len = AMD_VBIOS_LENGTH(header);
len = ALIGN(len, 4);
adev->bios = kmalloc(len, GFP_KERNEL);
if (!adev->bios) {
DRM_ERROR("no memory to allocate for BIOS\n");
return false;
}
adev->bios_size = len;
amdgpu_asic_read_bios_from_rom(adev, adev->bios, len);
if (!check_atom_bios(adev->bios, len)) {
kfree(adev->bios);
return false;
}
return true;
}
static bool amdgpu_read_platform_bios(struct amdgpu_device *adev)
{
uint8_t __iomem *bios;
size_t size;
adev->bios = NULL;
bios = pci_platform_rom(adev->pdev, &size);
if (!bios) {
return false;
}
adev->bios = kzalloc(size, GFP_KERNEL);
if (adev->bios == NULL)
return false;
memcpy_fromio(adev->bios, bios, size);
if (!check_atom_bios(adev->bios, size)) {
kfree(adev->bios);
return false;
}
adev->bios_size = size;
return true;
}
static int amdgpu_atrm_call(acpi_handle atrm_handle, uint8_t *bios,
int offset, int len)
{
acpi_status status;
union acpi_object atrm_arg_elements[2], *obj;
struct acpi_object_list atrm_arg;
struct acpi_buffer buffer = { ACPI_ALLOCATE_BUFFER, NULL};
atrm_arg.count = 2;
atrm_arg.pointer = &atrm_arg_elements[0];
atrm_arg_elements[0].type = ACPI_TYPE_INTEGER;
atrm_arg_elements[0].integer.value = offset;
atrm_arg_elements[1].type = ACPI_TYPE_INTEGER;
atrm_arg_elements[1].integer.value = len;
status = acpi_evaluate_object(atrm_handle, NULL, &atrm_arg, &buffer);
if (ACPI_FAILURE(status)) {
printk("failed to evaluate ATRM got %s\n", acpi_format_exception(status));
return -ENODEV;
}
obj = (union acpi_object *)buffer.pointer;
memcpy(bios+offset, obj->buffer.pointer, obj->buffer.length);
len = obj->buffer.length;
kfree(buffer.pointer);
return len;
}
static bool amdgpu_atrm_get_bios(struct amdgpu_device *adev)
{
int ret;
int size = 256 * 1024;
int i;
struct pci_dev *pdev = NULL;
acpi_handle dhandle, atrm_handle;
acpi_status status;
bool found = false;
if (adev->flags & AMD_IS_APU)
return false;
while ((pdev = pci_get_class(PCI_CLASS_DISPLAY_VGA << 8, pdev)) != NULL) {
dhandle = ACPI_HANDLE(&pdev->dev);
if (!dhandle)
continue;
status = acpi_get_handle(dhandle, "ATRM", &atrm_handle);
if (!ACPI_FAILURE(status)) {
found = true;
break;
}
}
if (!found) {
while ((pdev = pci_get_class(PCI_CLASS_DISPLAY_OTHER << 8, pdev)) != NULL) {
dhandle = ACPI_HANDLE(&pdev->dev);
if (!dhandle)
continue;
status = acpi_get_handle(dhandle, "ATRM", &atrm_handle);
if (!ACPI_FAILURE(status)) {
found = true;
break;
}
}
}
if (!found)
return false;
adev->bios = kmalloc(size, GFP_KERNEL);
if (!adev->bios) {
DRM_ERROR("Unable to allocate bios\n");
return false;
}
for (i = 0; i < size / ATRM_BIOS_PAGE; i++) {
ret = amdgpu_atrm_call(atrm_handle,
adev->bios,
(i * ATRM_BIOS_PAGE),
ATRM_BIOS_PAGE);
if (ret < ATRM_BIOS_PAGE)
break;
}
if (!check_atom_bios(adev->bios, size)) {
kfree(adev->bios);
return false;
}
adev->bios_size = size;
return true;
}
static inline bool amdgpu_atrm_get_bios(struct amdgpu_device *adev)
{
return false;
}
static bool amdgpu_read_disabled_bios(struct amdgpu_device *adev)
{
if (adev->flags & AMD_IS_APU)
return igp_read_bios_from_vram(adev);
else
return amdgpu_asic_read_disabled_bios(adev);
}
static bool amdgpu_acpi_vfct_bios(struct amdgpu_device *adev)
{
struct acpi_table_header *hdr;
acpi_size tbl_size;
UEFI_ACPI_VFCT *vfct;
unsigned offset;
if (!ACPI_SUCCESS(acpi_get_table("VFCT", 1, &hdr)))
return false;
tbl_size = hdr->length;
if (tbl_size < sizeof(UEFI_ACPI_VFCT)) {
DRM_ERROR("ACPI VFCT table present but broken (too short #1)\n");
return false;
}
vfct = (UEFI_ACPI_VFCT *)hdr;
offset = vfct->VBIOSImageOffset;
while (offset < tbl_size) {
GOP_VBIOS_CONTENT *vbios = (GOP_VBIOS_CONTENT *)((char *)hdr + offset);
VFCT_IMAGE_HEADER *vhdr = &vbios->VbiosHeader;
offset += sizeof(VFCT_IMAGE_HEADER);
if (offset > tbl_size) {
DRM_ERROR("ACPI VFCT image header truncated\n");
return false;
}
offset += vhdr->ImageLength;
if (offset > tbl_size) {
DRM_ERROR("ACPI VFCT image truncated\n");
return false;
}
if (vhdr->ImageLength &&
vhdr->PCIBus == adev->pdev->bus->number &&
vhdr->PCIDevice == PCI_SLOT(adev->pdev->devfn) &&
vhdr->PCIFunction == PCI_FUNC(adev->pdev->devfn) &&
vhdr->VendorID == adev->pdev->vendor &&
vhdr->DeviceID == adev->pdev->device) {
adev->bios = kmemdup(&vbios->VbiosContent,
vhdr->ImageLength,
GFP_KERNEL);
if (!check_atom_bios(adev->bios, vhdr->ImageLength)) {
kfree(adev->bios);
return false;
}
adev->bios_size = vhdr->ImageLength;
return true;
}
}
DRM_ERROR("ACPI VFCT table present but broken (too short #2)\n");
return false;
}
static inline bool amdgpu_acpi_vfct_bios(struct amdgpu_device *adev)
{
return false;
}
bool amdgpu_get_bios(struct amdgpu_device *adev)
{
if (amdgpu_atrm_get_bios(adev))
goto success;
if (amdgpu_acpi_vfct_bios(adev))
goto success;
if (igp_read_bios_from_vram(adev))
goto success;
if (amdgpu_read_bios(adev))
goto success;
if (amdgpu_read_bios_from_rom(adev))
goto success;
if (amdgpu_read_disabled_bios(adev))
goto success;
if (amdgpu_read_platform_bios(adev))
goto success;
DRM_ERROR("Unable to locate a BIOS ROM\n");
return false;
success:
adev->is_atom_fw = is_atom_fw(adev->bios);
return true;
}
