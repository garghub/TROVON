static int create_mtd_partitions(struct mtd_info *master,
struct mtd_partition **pparts,
struct mtd_part_parser_data *data)
{
struct ar7_bin_rec header;
unsigned int offset;
size_t len;
unsigned int pre_size = master->erasesize, post_size = 0;
unsigned int root_offset = ROOT_OFFSET;
int retries = 10;
struct mtd_partition *ar7_parts;
ar7_parts = kzalloc(sizeof(*ar7_parts) * AR7_PARTS, GFP_KERNEL);
if (!ar7_parts)
return -ENOMEM;
ar7_parts[0].name = "loader";
ar7_parts[0].offset = 0;
ar7_parts[0].size = master->erasesize;
ar7_parts[0].mask_flags = MTD_WRITEABLE;
ar7_parts[1].name = "config";
ar7_parts[1].offset = 0;
ar7_parts[1].size = master->erasesize;
ar7_parts[1].mask_flags = 0;
do {
offset = pre_size;
mtd_read(master, offset, sizeof(header), &len,
(uint8_t *)&header);
if (!strncmp((char *)&header, "TIENV0.8", 8))
ar7_parts[1].offset = pre_size;
if (header.checksum == LOADER_MAGIC1)
break;
if (header.checksum == LOADER_MAGIC2)
break;
pre_size += master->erasesize;
} while (retries--);
pre_size = offset;
if (!ar7_parts[1].offset) {
ar7_parts[1].offset = master->size - master->erasesize;
post_size = master->erasesize;
}
switch (header.checksum) {
case LOADER_MAGIC1:
while (header.length) {
offset += sizeof(header) + header.length;
mtd_read(master, offset, sizeof(header), &len,
(uint8_t *)&header);
}
root_offset = offset + sizeof(header) + 4;
break;
case LOADER_MAGIC2:
while (header.length) {
offset += sizeof(header) + header.length;
mtd_read(master, offset, sizeof(header), &len,
(uint8_t *)&header);
}
root_offset = offset + sizeof(header) + 4 + 0xff;
root_offset &= ~(uint32_t)0xff;
break;
default:
printk(KERN_WARNING "Unknown magic: %08x\n", header.checksum);
break;
}
mtd_read(master, root_offset, sizeof(header), &len, (u8 *)&header);
if (header.checksum != SQUASHFS_MAGIC) {
root_offset += master->erasesize - 1;
root_offset &= ~(master->erasesize - 1);
}
ar7_parts[2].name = "linux";
ar7_parts[2].offset = pre_size;
ar7_parts[2].size = master->size - pre_size - post_size;
ar7_parts[2].mask_flags = 0;
ar7_parts[3].name = "rootfs";
ar7_parts[3].offset = root_offset;
ar7_parts[3].size = master->size - root_offset - post_size;
ar7_parts[3].mask_flags = 0;
*pparts = ar7_parts;
return AR7_PARTS;
}
static int __init ar7_parser_init(void)
{
register_mtd_parser(&ar7_parser);
return 0;
}
static void __exit ar7_parser_exit(void)
{
deregister_mtd_parser(&ar7_parser);
}
