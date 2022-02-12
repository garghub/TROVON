static ssize_t memconsole_read(char *buf, loff_t pos, size_t count)
{
return memory_read_from_buffer(buf, count, &pos, memconsole_baseaddr,
memconsole_length);
}
static void found_v1_header(struct biosmemcon_ebda *hdr)
{
pr_info("memconsole: BIOS console v1 EBDA structure found at %p\n",
hdr);
pr_info("memconsole: BIOS console buffer at 0x%.8x, start = %d, end = %d, num = %d\n",
hdr->v1.buffer_addr, hdr->v1.start,
hdr->v1.end, hdr->v1.num_chars);
memconsole_baseaddr = phys_to_virt(hdr->v1.buffer_addr);
memconsole_length = hdr->v1.num_chars;
memconsole_setup(memconsole_read);
}
static void found_v2_header(struct biosmemcon_ebda *hdr)
{
pr_info("memconsole: BIOS console v2 EBDA structure found at %p\n",
hdr);
pr_info("memconsole: BIOS console buffer at 0x%.8x, start = %d, end = %d, num_bytes = %d\n",
hdr->v2.buffer_addr, hdr->v2.start,
hdr->v2.end, hdr->v2.num_bytes);
memconsole_baseaddr = phys_to_virt(hdr->v2.buffer_addr + hdr->v2.start);
memconsole_length = hdr->v2.end - hdr->v2.start;
memconsole_setup(memconsole_read);
}
static bool memconsole_ebda_init(void)
{
unsigned int address;
size_t length, cur;
address = get_bios_ebda();
if (!address) {
pr_info("memconsole: BIOS EBDA non-existent.\n");
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
pr_info("memconsole: BIOS console EBDA structure not found!\n");
return false;
}
static bool __init memconsole_find(void)
{
if (!dmi_check_system(memconsole_dmi_table))
return false;
return memconsole_ebda_init();
}
static int __init memconsole_x86_init(void)
{
if (!memconsole_find())
return -ENODEV;
return memconsole_sysfs_init();
}
static void __exit memconsole_x86_exit(void)
{
memconsole_exit();
}
