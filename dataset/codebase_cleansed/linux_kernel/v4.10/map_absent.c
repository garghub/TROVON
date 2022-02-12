static struct mtd_info *map_absent_probe(struct map_info *map)
{
struct mtd_info *mtd;
mtd = kzalloc(sizeof(*mtd), GFP_KERNEL);
if (!mtd) {
return NULL;
}
map->fldrv = &map_absent_chipdrv;
mtd->priv = map;
mtd->name = map->name;
mtd->type = MTD_ABSENT;
mtd->size = map->size;
mtd->_erase = map_absent_erase;
mtd->_read = map_absent_read;
mtd->_write = map_absent_write;
mtd->_sync = map_absent_sync;
mtd->flags = 0;
mtd->erasesize = PAGE_SIZE;
mtd->writesize = 1;
__module_get(THIS_MODULE);
return mtd;
}
static int map_absent_read(struct mtd_info *mtd, loff_t from, size_t len, size_t *retlen, u_char *buf)
{
return -ENODEV;
}
static int map_absent_write(struct mtd_info *mtd, loff_t to, size_t len, size_t *retlen, const u_char *buf)
{
return -ENODEV;
}
static int map_absent_erase(struct mtd_info *mtd, struct erase_info *instr)
{
return -ENODEV;
}
static void map_absent_sync(struct mtd_info *mtd)
{
}
static void map_absent_destroy(struct mtd_info *mtd)
{
}
static int __init map_absent_init(void)
{
register_mtd_chip_driver(&map_absent_chipdrv);
return 0;
}
static void __exit map_absent_exit(void)
{
unregister_mtd_chip_driver(&map_absent_chipdrv);
}
