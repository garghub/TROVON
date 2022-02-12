int coreboot_table_find(int tag, void *data, size_t data_size)
{
struct coreboot_table_header header;
struct coreboot_table_entry entry;
void *ptr_entry;
int i;
if (!ptr_header)
return -EPROBE_DEFER;
memcpy_fromio(&header, ptr_header, sizeof(header));
if (strncmp(header.signature, "LBIO", sizeof(header.signature))) {
pr_warn("coreboot_table: coreboot table missing or corrupt!\n");
return -ENODEV;
}
ptr_entry = (void *)ptr_header + header.header_bytes;
for (i = 0; i < header.table_entries; i++) {
memcpy_fromio(&entry, ptr_entry, sizeof(entry));
if (entry.tag == tag) {
if (data_size < entry.size)
return -EINVAL;
memcpy_fromio(data, ptr_entry, entry.size);
return 0;
}
ptr_entry += entry.size;
}
return -ENOENT;
}
int coreboot_table_init(void __iomem *ptr)
{
ptr_header = ptr;
return 0;
}
int coreboot_table_exit(void)
{
if (ptr_header)
iounmap(ptr_header);
return 0;
}
