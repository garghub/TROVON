static ssize_t memconsole_read(struct file *filp, struct kobject *kobp,
struct bin_attribute *bin_attr, char *buf,
loff_t pos, size_t count)
{
char *memconsole;
ssize_t ret;
memconsole = ioremap_cache(memconsole_baseaddr, memconsole_length);
if (!memconsole) {
pr_err("memconsole: ioremap_cache failed\n");
return -ENOMEM;
}
ret = memory_read_from_buffer(buf, count, &pos, memconsole,
memconsole_length);
iounmap(memconsole);
return ret;
}
static void __init found_v1_header(struct biosmemcon_ebda *hdr)
{
pr_info("BIOS console v1 EBDA structure found at %p\n", hdr);
pr_info("BIOS console buffer at 0x%.8x, "
"start = %d, end = %d, num = %d\n",
hdr->v1.buffer_addr, hdr->v1.start,
hdr->v1.end, hdr->v1.num_chars);
memconsole_length = hdr->v1.num_chars;
memconsole_baseaddr = hdr->v1.buffer_addr;
}
static void __init found_v2_header(struct biosmemcon_ebda *hdr)
{
pr_info("BIOS console v2 EBDA structure found at %p\n", hdr);
pr_info("BIOS console buffer at 0x%.8x, "
"start = %d, end = %d, num_bytes = %d\n",
hdr->v2.buffer_addr, hdr->v2.start,
hdr->v2.end, hdr->v2.num_bytes);
memconsole_length = hdr->v2.end - hdr->v2.start;
memconsole_baseaddr = hdr->v2.buffer_addr + hdr->v2.start;
}
static bool __init found_memconsole(void)
{
unsigned int address;
size_t length, cur;
address = get_bios_ebda();
if (!address) {
pr_info("BIOS EBDA non-existent.\n");
return false;
}
length = *(u8 *)phys_to_virt(address);
length <<= 10;
for (cur = 0; cur < length; cur++) {
struct biosmemcon_ebda *hdr = phys_to_virt(address + cur);
if (hdr->signature == BIOS_MEMCONSOLE_V1_MAGIC) {
found_v1_header(hdr);
return true;
}
if (hdr->signature == BIOS_MEMCONSOLE_V2_MAGIC) {
found_v2_header(hdr);
return true;
}
}
pr_info("BIOS console EBDA structure not found!\n");
return false;
}
static int __init memconsole_init(void)
{
if (!dmi_check_system(memconsole_dmi_table))
return -ENODEV;
if (!found_memconsole())
return -ENODEV;
memconsole_bin_attr.size = memconsole_length;
return sysfs_create_bin_file(firmware_kobj, &memconsole_bin_attr);
}
static void __exit memconsole_exit(void)
{
sysfs_remove_bin_file(firmware_kobj, &memconsole_bin_attr);
}
