void __init efi_bgrt_init(void)
{
acpi_status status;
void *image;
struct bmp_header bmp_header;
if (acpi_disabled)
return;
status = acpi_get_table("BGRT", 0,
(struct acpi_table_header **)&bgrt_tab);
if (ACPI_FAILURE(status))
return;
if (bgrt_tab->header.length < sizeof(*bgrt_tab)) {
pr_notice("Ignoring BGRT: invalid length %u (expected %zu)\n",
bgrt_tab->header.length, sizeof(*bgrt_tab));
return;
}
if (bgrt_tab->version != 1) {
pr_notice("Ignoring BGRT: invalid version %u (expected 1)\n",
bgrt_tab->version);
return;
}
if (bgrt_tab->status & 0xfe) {
pr_notice("Ignoring BGRT: reserved status bits are non-zero %u\n",
bgrt_tab->status);
return;
}
if (bgrt_tab->image_type != 0) {
pr_notice("Ignoring BGRT: invalid image type %u (expected 0)\n",
bgrt_tab->image_type);
return;
}
if (!bgrt_tab->image_address) {
pr_notice("Ignoring BGRT: null image address\n");
return;
}
image = memremap(bgrt_tab->image_address, sizeof(bmp_header), MEMREMAP_WB);
if (!image) {
pr_notice("Ignoring BGRT: failed to map image header memory\n");
return;
}
memcpy(&bmp_header, image, sizeof(bmp_header));
memunmap(image);
if (bmp_header.id != 0x4d42) {
pr_notice("Ignoring BGRT: Incorrect BMP magic number 0x%x (expected 0x4d42)\n",
bmp_header.id);
return;
}
bgrt_image_size = bmp_header.size;
bgrt_image = memremap(bgrt_tab->image_address, bmp_header.size, MEMREMAP_WB);
if (!bgrt_image) {
pr_notice("Ignoring BGRT: failed to map image memory\n");
bgrt_image = NULL;
return;
}
efi_mem_reserve(bgrt_tab->image_address, bgrt_image_size);
}
