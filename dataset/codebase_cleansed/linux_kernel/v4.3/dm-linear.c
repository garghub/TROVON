static int linear_ctr(struct dm_target *ti, unsigned int argc, char **argv)
{
struct linear_c *lc;
unsigned long long tmp;
char dummy;
int ret;
if (argc != 2) {
ti->error = "Invalid argument count";
return -EINVAL;
}
lc = kmalloc(sizeof(*lc), GFP_KERNEL);
if (lc == NULL) {
ti->error = "dm-linear: Cannot allocate linear context";
return -ENOMEM;
}
ret = -EINVAL;
if (sscanf(argv[1], "%llu%c", &tmp, &dummy) != 1) {
ti->error = "dm-linear: Invalid device sector";
goto bad;
}
lc->start = tmp;
ret = dm_get_device(ti, argv[0], dm_table_get_mode(ti->table), &lc->dev);
if (ret) {
ti->error = "dm-linear: Device lookup failed";
goto bad;
}
ti->num_flush_bios = 1;
ti->num_discard_bios = 1;
ti->num_write_same_bios = 1;
ti->private = lc;
return 0;
bad:
kfree(lc);
return ret;
}
static void linear_dtr(struct dm_target *ti)
{
struct linear_c *lc = (struct linear_c *) ti->private;
dm_put_device(ti, lc->dev);
kfree(lc);
}
static sector_t linear_map_sector(struct dm_target *ti, sector_t bi_sector)
{
struct linear_c *lc = ti->private;
return lc->start + dm_target_offset(ti, bi_sector);
}
static void linear_map_bio(struct dm_target *ti, struct bio *bio)
{
struct linear_c *lc = ti->private;
bio->bi_bdev = lc->dev->bdev;
if (bio_sectors(bio))
bio->bi_iter.bi_sector =
linear_map_sector(ti, bio->bi_iter.bi_sector);
}
static int linear_map(struct dm_target *ti, struct bio *bio)
{
linear_map_bio(ti, bio);
return DM_MAPIO_REMAPPED;
}
static void linear_status(struct dm_target *ti, status_type_t type,
unsigned status_flags, char *result, unsigned maxlen)
{
struct linear_c *lc = (struct linear_c *) ti->private;
switch (type) {
case STATUSTYPE_INFO:
result[0] = '\0';
break;
case STATUSTYPE_TABLE:
snprintf(result, maxlen, "%s %llu", lc->dev->name,
(unsigned long long)lc->start);
break;
}
}
static int linear_ioctl(struct dm_target *ti, unsigned int cmd,
unsigned long arg)
{
struct linear_c *lc = (struct linear_c *) ti->private;
struct dm_dev *dev = lc->dev;
int r = 0;
if (lc->start ||
ti->len != i_size_read(dev->bdev->bd_inode) >> SECTOR_SHIFT)
r = scsi_verify_blk_ioctl(NULL, cmd);
return r ? : __blkdev_driver_ioctl(dev->bdev, dev->mode, cmd, arg);
}
static int linear_iterate_devices(struct dm_target *ti,
iterate_devices_callout_fn fn, void *data)
{
struct linear_c *lc = ti->private;
return fn(ti, lc->dev, lc->start, ti->len, data);
}
int __init dm_linear_init(void)
{
int r = dm_register_target(&linear_target);
if (r < 0)
DMERR("register failed %d", r);
return r;
}
void dm_linear_exit(void)
{
dm_unregister_target(&linear_target);
}
