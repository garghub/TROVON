static struct mtd_info *map_rom_probe(struct map_info *map)
{
struct mtd_info *mtd;
mtd = kzalloc(sizeof(*mtd), GFP_KERNEL);
if (!mtd)
return NULL;
map->fldrv = &maprom_chipdrv;
mtd->priv = map;
mtd->name = map->name;
mtd->type = MTD_ROM;
mtd->size = map->size;
mtd->get_unmapped_area = maprom_unmapped_area;
mtd->read = maprom_read;
mtd->write = maprom_write;
mtd->sync = maprom_nop;
mtd->erase = maprom_erase;
mtd->flags = MTD_CAP_ROM;
mtd->erasesize = map->size;
mtd->writesize = 1;
__module_get(THIS_MODULE);
return mtd;
}
static unsigned long maprom_unmapped_area(struct mtd_info *mtd,
unsigned long len,
unsigned long offset,
unsigned long flags)
{
struct map_info *map = mtd->priv;
return (unsigned long) map->virt + offset;
}
static int maprom_read (struct mtd_info *mtd, loff_t from, size_t len, size_t *retlen, u_char *buf)
{
struct map_info *map = mtd->priv;
map_copy_from(map, buf, from, len);
*retlen = len;
return 0;
}
static void maprom_nop(struct mtd_info *mtd)
{
}
static int maprom_write (struct mtd_info *mtd, loff_t to, size_t len, size_t *retlen, const u_char *buf)
{
printk(KERN_NOTICE "maprom_write called\n");
return -EIO;
}
static int maprom_erase (struct mtd_info *mtd, struct erase_info *info)
{
return -EROFS;
}
static int __init map_rom_init(void)
{
register_mtd_chip_driver(&maprom_chipdrv);
return 0;
}
static void __exit map_rom_exit(void)
{
unregister_mtd_chip_driver(&maprom_chipdrv);
}
