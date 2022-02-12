static bool igp_read_bios_from_vram(struct amdgpu_device *adev)
{
uint8_t __iomem *bios;
resource_size_t vram_base;
resource_size_t size = 256 * 1024;
if (!(adev->flags & AMD_IS_APU))
if (!amdgpu_card_posted(adev))
return false;
adev->bios = NULL;
vram_base = pci_resource_start(adev->pdev, 0);
bios = ioremap(vram_base, size);
if (!bios) {
return false;
}
if (size == 0 || !AMD_IS_VALID_VBIOS(bios)) {
iounmap(bios);
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
return true;
}
bool amdgpu_read_bios(struct amdgpu_device *adev)
{
uint8_t __iomem *bios, val[2];
size_t size;
adev->bios = NULL;
bios = pci_map_rom(adev->pdev, &size);
if (!bios) {
return false;
}
val[0] = readb(&bios[0]);
val[1] = readb(&bios[1]);
if (size == 0 || !AMD_IS_VALID_VBIOS(val)) {
pci_unmap_rom(adev->pdev, bios);
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
return amdgpu_asic_read_bios_from_rom(adev, adev->bios, len);
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
if (size == 0 || !AMD_IS_VALID_VBIOS(bios)) {
return false;
}
adev->bios = kmemdup(bios, size, GFP_KERNEL);
if (adev->bios == NULL) {
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
if (i == 0 || !AMD_IS_VALID_VBIOS(adev->bios)) {
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
bool ret = false;
struct acpi_table_header *hdr;
acpi_size tbl_size;
UEFI_ACPI_VFCT *vfct;
GOP_VBIOS_CONTENT *vbios;
VFCT_IMAGE_HEADER *vhdr;
if (!ACPI_SUCCESS(acpi_get_table("VFCT", 1, &hdr)))
return false;
tbl_size = hdr->length;
if (tbl_size < sizeof(UEFI_ACPI_VFCT)) {
DRM_ERROR("ACPI VFCT table present but broken (too short #1)\n");
goto out_unmap;
}
vfct = (UEFI_ACPI_VFCT *)hdr;
if (vfct->VBIOSImageOffset + sizeof(VFCT_IMAGE_HEADER) > tbl_size) {
DRM_ERROR("ACPI VFCT table present but broken (too short #2)\n");
goto out_unmap;
}
vbios = (GOP_VBIOS_CONTENT *)((char *)hdr + vfct->VBIOSImageOffset);
vhdr = &vbios->VbiosHeader;
DRM_INFO("ACPI VFCT contains a BIOS for %02x:%02x.%d %04x:%04x, size %d\n",
vhdr->PCIBus, vhdr->PCIDevice, vhdr->PCIFunction,
vhdr->VendorID, vhdr->DeviceID, vhdr->ImageLength);
if (vhdr->PCIBus != adev->pdev->bus->number ||
vhdr->PCIDevice != PCI_SLOT(adev->pdev->devfn) ||
vhdr->PCIFunction != PCI_FUNC(adev->pdev->devfn) ||
vhdr->VendorID != adev->pdev->vendor ||
vhdr->DeviceID != adev->pdev->device) {
DRM_INFO("ACPI VFCT table is not for this card\n");
goto out_unmap;
}
if (vfct->VBIOSImageOffset + sizeof(VFCT_IMAGE_HEADER) + vhdr->ImageLength > tbl_size) {
DRM_ERROR("ACPI VFCT image truncated\n");
goto out_unmap;
}
adev->bios = kmemdup(&vbios->VbiosContent, vhdr->ImageLength, GFP_KERNEL);
adev->bios_size = vhdr->ImageLength;
ret = !!adev->bios;
out_unmap:
return ret;
}
static inline bool amdgpu_acpi_vfct_bios(struct amdgpu_device *adev)
{
return false;
}
bool amdgpu_get_bios(struct amdgpu_device *adev)
{
bool r;
uint16_t tmp, bios_header_start;
r = amdgpu_atrm_get_bios(adev);
if (!r)
r = amdgpu_acpi_vfct_bios(adev);
if (!r)
r = igp_read_bios_from_vram(adev);
if (!r)
r = amdgpu_read_bios(adev);
if (!r) {
r = amdgpu_read_bios_from_rom(adev);
}
if (!r) {
r = amdgpu_read_disabled_bios(adev);
}
if (!r) {
r = amdgpu_read_platform_bios(adev);
}
if (!r || adev->bios == NULL) {
DRM_ERROR("Unable to locate a BIOS ROM\n");
adev->bios = NULL;
return false;
}
if (!AMD_IS_VALID_VBIOS(adev->bios)) {
printk("BIOS signature incorrect %x %x\n", adev->bios[0], adev->bios[1]);
goto free_bios;
}
tmp = RBIOS16(0x18);
if (RBIOS8(tmp + 0x14) != 0x0) {
DRM_INFO("Not an x86 BIOS ROM, not using.\n");
goto free_bios;
}
bios_header_start = RBIOS16(0x48);
if (!bios_header_start) {
goto free_bios;
}
tmp = bios_header_start + 4;
if (!memcmp(adev->bios + tmp, "ATOM", 4) ||
!memcmp(adev->bios + tmp, "MOTA", 4)) {
adev->is_atom_bios = true;
} else {
adev->is_atom_bios = false;
}
DRM_DEBUG("%sBIOS detected\n", adev->is_atom_bios ? "ATOM" : "COM");
return true;
free_bios:
kfree(adev->bios);
adev->bios = NULL;
return false;
}
