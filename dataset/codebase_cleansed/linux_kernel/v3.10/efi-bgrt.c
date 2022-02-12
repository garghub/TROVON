void __init efi_bgrt_init(void)
{
acpi_status status;
void __iomem *image;
bool ioremapped = false;
struct bmp_header bmp_header;
if (acpi_disabled)
return;
status = acpi_get_table("BGRT", 0,
(struct acpi_table_header **)&bgrt_tab);
if (ACPI_FAILURE(status))
return;
if (bgrt_tab->header.length < sizeof(*bgrt_tab))
return;
if (bgrt_tab->version != 1)
return;
if (bgrt_tab->image_type != 0 || !bgrt_tab->image_address)
return;
image = efi_lookup_mapped_addr(bgrt_tab->image_address);
if (!image) {
image = ioremap(bgrt_tab->image_address, sizeof(bmp_header));
ioremapped = true;
if (!image)
return;
}
memcpy_fromio(&bmp_header, image, sizeof(bmp_header));
if (ioremapped)
iounmap(image);
bgrt_image_size = bmp_header.size;
bgrt_image = kmalloc(bgrt_image_size, GFP_KERNEL);
if (!bgrt_image)
return;
if (ioremapped) {
image = ioremap(bgrt_tab->image_address, bmp_header.size);
if (!image) {
kfree(bgrt_image);
bgrt_image = NULL;
return;
}
}
memcpy_fromio(bgrt_image, image, bgrt_image_size);
if (ioremapped)
iounmap(image);
}
