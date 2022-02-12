static int parse_cfe_partitions(struct mtd_info *master,
struct mtd_partition **pparts)
{
int nrparts = 3, curpart = 0;
struct bcm_tag *buf;
struct mtd_partition *parts;
int ret;
size_t retlen;
unsigned int rootfsaddr, kerneladdr, spareaddr;
unsigned int rootfslen, kernellen, sparelen, totallen;
int namelen = 0;
int i;
char *boardid;
char *tagversion;
buf = vmalloc(sizeof(struct bcm_tag));
if (!buf)
return -ENOMEM;
ret = master->read(master, master->erasesize, sizeof(struct bcm_tag),
&retlen, (void *)buf);
if (retlen != sizeof(struct bcm_tag)) {
vfree(buf);
return -EIO;
}
sscanf(buf->kernel_address, "%u", &kerneladdr);
sscanf(buf->kernel_length, "%u", &kernellen);
sscanf(buf->total_length, "%u", &totallen);
tagversion = &(buf->tag_version[0]);
boardid = &(buf->board_id[0]);
printk(KERN_INFO PFX "CFE boot tag found with version %s "
"and board type %s\n", tagversion, boardid);
kerneladdr = kerneladdr - BCM63XX_EXTENDED_SIZE;
rootfsaddr = kerneladdr + kernellen;
spareaddr = roundup(totallen, master->erasesize) + master->erasesize;
sparelen = master->size - spareaddr - master->erasesize;
rootfslen = spareaddr - rootfsaddr;
namelen = 8;
if (rootfslen > 0) {
nrparts++;
namelen += 6;
};
if (kernellen > 0) {
nrparts++;
namelen += 6;
};
parts = kzalloc(sizeof(*parts) * nrparts + 10 * nrparts, GFP_KERNEL);
if (!parts) {
vfree(buf);
return -ENOMEM;
};
parts[curpart].name = "CFE";
parts[curpart].offset = 0;
parts[curpart].size = master->erasesize;
curpart++;
if (kernellen > 0) {
parts[curpart].name = "kernel";
parts[curpart].offset = kerneladdr;
parts[curpart].size = kernellen;
curpart++;
};
if (rootfslen > 0) {
parts[curpart].name = "rootfs";
parts[curpart].offset = rootfsaddr;
parts[curpart].size = rootfslen;
if (sparelen > 0)
parts[curpart].size += sparelen;
curpart++;
};
parts[curpart].name = "nvram";
parts[curpart].offset = master->size - master->erasesize;
parts[curpart].size = master->erasesize;
curpart++;
parts[curpart].name = "linux";
parts[curpart].offset = parts[0].size;
parts[curpart].size = master->size - parts[0].size - parts[3].size;
for (i = 0; i < nrparts; i++)
printk(KERN_INFO PFX "Partition %d is %s offset %lx and "
"length %lx\n", i, parts[i].name,
(long unsigned int)(parts[i].offset),
(long unsigned int)(parts[i].size));
printk(KERN_INFO PFX "Spare partition is %x offset and length %x\n",
spareaddr, sparelen);
*pparts = parts;
vfree(buf);
return nrparts;
}
static int bcm963xx_detect_cfe(struct mtd_info *master)
{
int idoffset = 0x4e0;
static char idstring[8] = "CFE1CFE1";
char buf[9];
int ret;
size_t retlen;
ret = master->read(master, idoffset, 8, &retlen, (void *)buf);
buf[retlen] = 0;
printk(KERN_INFO PFX "Read Signature value of %s\n", buf);
return strncmp(idstring, buf, 8);
}
static int bcm963xx_probe(struct platform_device *pdev)
{
int err = 0;
int parsed_nr_parts = 0;
char *part_type;
struct resource *r;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!r) {
dev_err(&pdev->dev, "no resource supplied\n");
return -ENODEV;
}
bcm963xx_map.phys = r->start;
bcm963xx_map.size = resource_size(r);
bcm963xx_map.virt = ioremap(r->start, resource_size(r));
if (!bcm963xx_map.virt) {
dev_err(&pdev->dev, "failed to ioremap\n");
return -EIO;
}
dev_info(&pdev->dev, "0x%08lx at 0x%08x\n",
bcm963xx_map.size, bcm963xx_map.phys);
simple_map_init(&bcm963xx_map);
bcm963xx_mtd_info = do_map_probe("cfi_probe", &bcm963xx_map);
if (!bcm963xx_mtd_info) {
dev_err(&pdev->dev, "failed to probe using CFI\n");
bcm963xx_mtd_info = do_map_probe("jedec_probe", &bcm963xx_map);
if (bcm963xx_mtd_info)
goto probe_ok;
dev_err(&pdev->dev, "failed to probe using JEDEC\n");
err = -EIO;
goto err_probe;
}
probe_ok:
bcm963xx_mtd_info->owner = THIS_MODULE;
if (bcm963xx_detect_cfe(bcm963xx_mtd_info) == 0) {
dev_info(&pdev->dev, "CFE bootloader detected\n");
if (parsed_nr_parts == 0) {
int ret = parse_cfe_partitions(bcm963xx_mtd_info,
&parsed_parts);
if (ret > 0) {
part_type = "CFE";
parsed_nr_parts = ret;
}
}
} else {
dev_info(&pdev->dev, "unsupported bootloader\n");
err = -ENODEV;
goto err_probe;
}
return mtd_device_register(bcm963xx_mtd_info, parsed_parts,
parsed_nr_parts);
err_probe:
iounmap(bcm963xx_map.virt);
return err;
}
static int bcm963xx_remove(struct platform_device *pdev)
{
if (bcm963xx_mtd_info) {
mtd_device_unregister(bcm963xx_mtd_info);
map_destroy(bcm963xx_mtd_info);
}
if (bcm963xx_map.virt) {
iounmap(bcm963xx_map.virt);
bcm963xx_map.virt = 0;
}
return 0;
}
static int __init bcm963xx_mtd_init(void)
{
return platform_driver_register(&bcm63xx_mtd_dev);
}
static void __exit bcm963xx_mtd_exit(void)
{
platform_driver_unregister(&bcm63xx_mtd_dev);
}
