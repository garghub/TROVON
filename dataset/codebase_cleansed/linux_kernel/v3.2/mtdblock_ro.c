static int mtdblock_readsect(struct mtd_blktrans_dev *dev,
unsigned long block, char *buf)
{
size_t retlen;
if (dev->mtd->read(dev->mtd, (block * 512), 512, &retlen, buf))
return 1;
return 0;
}
static int mtdblock_writesect(struct mtd_blktrans_dev *dev,
unsigned long block, char *buf)
{
size_t retlen;
if (dev->mtd->write(dev->mtd, (block * 512), 512, &retlen, buf))
return 1;
return 0;
}
static void mtdblock_add_mtd(struct mtd_blktrans_ops *tr, struct mtd_info *mtd)
{
struct mtd_blktrans_dev *dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (!dev)
return;
dev->mtd = mtd;
dev->devnum = mtd->index;
dev->size = mtd->size >> 9;
dev->tr = tr;
dev->readonly = 1;
if (add_mtd_blktrans_dev(dev))
kfree(dev);
}
static void mtdblock_remove_dev(struct mtd_blktrans_dev *dev)
{
del_mtd_blktrans_dev(dev);
}
static int __init mtdblock_init(void)
{
return register_mtd_blktrans(&mtdblock_tr);
}
static void __exit mtdblock_exit(void)
{
deregister_mtd_blktrans(&mtdblock_tr);
}
