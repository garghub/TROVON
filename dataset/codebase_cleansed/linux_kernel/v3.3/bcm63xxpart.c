static int bcm63xx_detect_cfe(struct mtd_info *master)
{
char buf[9];
int ret;
size_t retlen;
ret = mtd_read(master, BCM963XX_CFE_VERSION_OFFSET, 5, &retlen,
(void *)buf);
buf[retlen] = 0;
if (ret)
return ret;
if (strncmp("cfe-v", buf, 5) == 0)
return 0;
ret = mtd_read(master, BCM63XX_CFE_MAGIC_OFFSET, 8, &retlen,
(void *)buf);
buf[retlen] = 0;
return strncmp("CFE1CFE1", buf, 8);
}
static int bcm63xx_parse_cfe_partitions(struct mtd_info *master,
struct mtd_partition **pparts,
struct mtd_part_parser_data *data)
{
int nrparts = 3, curpart = 0;
struct bcm_tag *buf;
struct mtd_partition *parts;
int ret;
size_t retlen;
unsigned int rootfsaddr, kerneladdr, spareaddr;
unsigned int rootfslen, kernellen, sparelen, totallen;
unsigned int cfelen, nvramlen;
int namelen = 0;
int i;
u32 computed_crc;
if (bcm63xx_detect_cfe(master))
return -EINVAL;
cfelen = max_t(uint32_t, master->erasesize, BCM63XX_MIN_CFE_SIZE);
nvramlen = max_t(uint32_t, master->erasesize, BCM63XX_MIN_NVRAM_SIZE);
buf = vmalloc(sizeof(struct bcm_tag));
if (!buf)
return -ENOMEM;
ret = mtd_read(master, cfelen, sizeof(struct bcm_tag), &retlen,
(void *)buf);
if (retlen != sizeof(struct bcm_tag)) {
vfree(buf);
return -EIO;
}
computed_crc = crc32_le(IMAGETAG_CRC_START, (u8 *)buf,
offsetof(struct bcm_tag, header_crc));
if (computed_crc == buf->header_crc) {
char *boardid = &(buf->board_id[0]);
char *tagversion = &(buf->tag_version[0]);
sscanf(buf->kernel_address, "%u", &kerneladdr);
sscanf(buf->kernel_length, "%u", &kernellen);
sscanf(buf->total_length, "%u", &totallen);
pr_info("CFE boot tag found with version %s and board type %s\n",
tagversion, boardid);
kerneladdr = kerneladdr - BCM63XX_EXTENDED_SIZE;
rootfsaddr = kerneladdr + kernellen;
spareaddr = roundup(totallen, master->erasesize) + cfelen;
sparelen = master->size - spareaddr - nvramlen;
rootfslen = spareaddr - rootfsaddr;
} else {
pr_warn("CFE boot tag CRC invalid (expected %08x, actual %08x)\n",
buf->header_crc, computed_crc);
kernellen = 0;
rootfslen = 0;
rootfsaddr = 0;
spareaddr = cfelen;
sparelen = master->size - cfelen - nvramlen;
}
namelen = 8;
if (rootfslen > 0) {
nrparts++;
namelen += 6;
}
if (kernellen > 0) {
nrparts++;
namelen += 6;
}
parts = kzalloc(sizeof(*parts) * nrparts + 10 * nrparts, GFP_KERNEL);
if (!parts) {
vfree(buf);
return -ENOMEM;
}
parts[curpart].name = "CFE";
parts[curpart].offset = 0;
parts[curpart].size = cfelen;
curpart++;
if (kernellen > 0) {
parts[curpart].name = "kernel";
parts[curpart].offset = kerneladdr;
parts[curpart].size = kernellen;
curpart++;
}
if (rootfslen > 0) {
parts[curpart].name = "rootfs";
parts[curpart].offset = rootfsaddr;
parts[curpart].size = rootfslen;
if (sparelen > 0)
parts[curpart].size += sparelen;
curpart++;
}
parts[curpart].name = "nvram";
parts[curpart].offset = master->size - nvramlen;
parts[curpart].size = nvramlen;
curpart++;
parts[curpart].name = "linux";
parts[curpart].offset = cfelen;
parts[curpart].size = master->size - cfelen - nvramlen;
for (i = 0; i < nrparts; i++)
pr_info("Partition %d is %s offset %lx and length %lx\n", i,
parts[i].name, (long unsigned int)(parts[i].offset),
(long unsigned int)(parts[i].size));
pr_info("Spare partition is offset %x and length %x\n", spareaddr,
sparelen);
*pparts = parts;
vfree(buf);
return nrparts;
}
static int __init bcm63xx_cfe_parser_init(void)
{
return register_mtd_parser(&bcm63xx_cfe_parser);
}
static void __exit bcm63xx_cfe_parser_exit(void)
{
deregister_mtd_parser(&bcm63xx_cfe_parser);
}
