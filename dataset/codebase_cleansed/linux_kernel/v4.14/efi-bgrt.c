void __init efi_bgrt_init(struct acpi_table_header *table)
{
void *image;
struct bmp_header bmp_header;
struct acpi_table_bgrt *bgrt = &bgrt_tab;
if (acpi_disabled)
return;
if (!efi_enabled(EFI_MEMMAP))
return;
if (table->length < sizeof(bgrt_tab)) {
pr_notice("Ignoring BGRT: invalid length %u (expected %zu)\n",
table->length, sizeof(bgrt_tab));
return;
}
*bgrt = *(struct acpi_table_bgrt *)table;
if (bgrt->version != 1) {
pr_notice("Ignoring BGRT: invalid version %u (expected 1)\n",
bgrt->version);
goto out;
}
if (bgrt->status & 0xfe) {
pr_notice("Ignoring BGRT: reserved status bits are non-zero %u\n",
bgrt->status);
goto out;
}
if (bgrt->image_type != 0) {
pr_notice("Ignoring BGRT: invalid image type %u (expected 0)\n",
bgrt->image_type);
goto out;
}
if (!bgrt->image_address) {
pr_notice("Ignoring BGRT: null image address\n");
goto out;
}
if (efi_mem_type(bgrt->image_address) != EFI_BOOT_SERVICES_DATA) {
pr_notice("Ignoring BGRT: invalid image address\n");
goto out;
}
image = early_memremap(bgrt->image_address, sizeof(bmp_header));
if (!image) {
pr_notice("Ignoring BGRT: failed to map image header memory\n");
goto out;
}
memcpy(&bmp_header, image, sizeof(bmp_header));
early_memunmap(image, sizeof(bmp_header));
if (bmp_header.id != 0x4d42) {
pr_notice("Ignoring BGRT: Incorrect BMP magic number 0x%x (expected 0x4d42)\n",
bmp_header.id);
goto out;
}
bgrt_image_size = bmp_header.size;
efi_mem_reserve(bgrt->image_address, bgrt_image_size);
return;
out:
memset(bgrt, 0, sizeof(bgrt_tab));
}
