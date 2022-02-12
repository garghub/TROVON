static int ram_erase(struct mtd_info *mtd, struct erase_info *instr)
{
if (instr->addr + instr->len > mtd->size)
return -EINVAL;
memset((char *)mtd->priv + instr->addr, 0xff, instr->len);
instr->state = MTD_ERASE_DONE;
mtd_erase_callback(instr);
return 0;
}
static int ram_point(struct mtd_info *mtd, loff_t from, size_t len,
size_t *retlen, void **virt, resource_size_t *phys)
{
if (from + len > mtd->size)
return -EINVAL;
if (phys)
return -EINVAL;
*virt = mtd->priv + from;
*retlen = len;
return 0;
}
static void ram_unpoint(struct mtd_info *mtd, loff_t from, size_t len)
{
}
static unsigned long ram_get_unmapped_area(struct mtd_info *mtd,
unsigned long len,
unsigned long offset,
unsigned long flags)
{
return (unsigned long) mtd->priv + offset;
}
static int ram_read(struct mtd_info *mtd, loff_t from, size_t len,
size_t *retlen, u_char *buf)
{
if (from + len > mtd->size)
return -EINVAL;
memcpy(buf, mtd->priv + from, len);
*retlen = len;
return 0;
}
static int ram_write(struct mtd_info *mtd, loff_t to, size_t len,
size_t *retlen, const u_char *buf)
{
if (to + len > mtd->size)
return -EINVAL;
memcpy((char *)mtd->priv + to, buf, len);
*retlen = len;
return 0;
}
static void __exit cleanup_mtdram(void)
{
if (mtd_info) {
mtd_device_unregister(mtd_info);
vfree(mtd_info->priv);
kfree(mtd_info);
}
}
int mtdram_init_device(struct mtd_info *mtd, void *mapped_address,
unsigned long size, char *name)
{
memset(mtd, 0, sizeof(*mtd));
mtd->name = name;
mtd->type = MTD_RAM;
mtd->flags = MTD_CAP_RAM;
mtd->size = size;
mtd->writesize = 1;
mtd->writebufsize = 64;
mtd->erasesize = MTDRAM_ERASE_SIZE;
mtd->priv = mapped_address;
mtd->owner = THIS_MODULE;
mtd->erase = ram_erase;
mtd->point = ram_point;
mtd->unpoint = ram_unpoint;
mtd->get_unmapped_area = ram_get_unmapped_area;
mtd->read = ram_read;
mtd->write = ram_write;
if (mtd_device_register(mtd, NULL, 0))
return -EIO;
return 0;
}
static int __init init_mtdram(void)
{
void *addr;
int err;
if (!total_size)
return -EINVAL;
mtd_info = kmalloc(sizeof(struct mtd_info), GFP_KERNEL);
if (!mtd_info)
return -ENOMEM;
addr = vmalloc(MTDRAM_TOTAL_SIZE);
if (!addr) {
kfree(mtd_info);
mtd_info = NULL;
return -ENOMEM;
}
err = mtdram_init_device(mtd_info, addr, MTDRAM_TOTAL_SIZE, "mtdram test device");
if (err) {
vfree(addr);
kfree(mtd_info);
mtd_info = NULL;
return err;
}
memset(mtd_info->priv, 0xff, MTDRAM_TOTAL_SIZE);
return err;
}
