static int parse_features(struct dm_arg_set *as, struct flakey_c *fc,
struct dm_target *ti)
{
int r;
unsigned argc;
const char *arg_name;
static struct dm_arg _args[] = {
{0, 6, "Invalid number of feature args"},
{1, UINT_MAX, "Invalid corrupt bio byte"},
{0, 255, "Invalid corrupt value to write into bio byte (0-255)"},
{0, UINT_MAX, "Invalid corrupt bio flags mask"},
};
if (!as->argc)
return 0;
r = dm_read_arg_group(_args, as, &argc, &ti->error);
if (r)
return r;
while (argc) {
arg_name = dm_shift_arg(as);
argc--;
if (!strcasecmp(arg_name, "drop_writes")) {
if (test_and_set_bit(DROP_WRITES, &fc->flags)) {
ti->error = "Feature drop_writes duplicated";
return -EINVAL;
} else if (test_bit(ERROR_WRITES, &fc->flags)) {
ti->error = "Feature drop_writes conflicts with feature error_writes";
return -EINVAL;
}
continue;
}
if (!strcasecmp(arg_name, "error_writes")) {
if (test_and_set_bit(ERROR_WRITES, &fc->flags)) {
ti->error = "Feature error_writes duplicated";
return -EINVAL;
} else if (test_bit(DROP_WRITES, &fc->flags)) {
ti->error = "Feature error_writes conflicts with feature drop_writes";
return -EINVAL;
}
continue;
}
if (!strcasecmp(arg_name, "corrupt_bio_byte")) {
if (!argc) {
ti->error = "Feature corrupt_bio_byte requires parameters";
return -EINVAL;
}
r = dm_read_arg(_args + 1, as, &fc->corrupt_bio_byte, &ti->error);
if (r)
return r;
argc--;
arg_name = dm_shift_arg(as);
if (!strcasecmp(arg_name, "w"))
fc->corrupt_bio_rw = WRITE;
else if (!strcasecmp(arg_name, "r"))
fc->corrupt_bio_rw = READ;
else {
ti->error = "Invalid corrupt bio direction (r or w)";
return -EINVAL;
}
argc--;
r = dm_read_arg(_args + 2, as, &fc->corrupt_bio_value, &ti->error);
if (r)
return r;
argc--;
r = dm_read_arg(_args + 3, as, &fc->corrupt_bio_flags, &ti->error);
if (r)
return r;
argc--;
continue;
}
ti->error = "Unrecognised flakey feature requested";
return -EINVAL;
}
if (test_bit(DROP_WRITES, &fc->flags) && (fc->corrupt_bio_rw == WRITE)) {
ti->error = "drop_writes is incompatible with corrupt_bio_byte with the WRITE flag set";
return -EINVAL;
} else if (test_bit(ERROR_WRITES, &fc->flags) && (fc->corrupt_bio_rw == WRITE)) {
ti->error = "error_writes is incompatible with corrupt_bio_byte with the WRITE flag set";
return -EINVAL;
}
return 0;
}
static int flakey_ctr(struct dm_target *ti, unsigned int argc, char **argv)
{
static struct dm_arg _args[] = {
{0, UINT_MAX, "Invalid up interval"},
{0, UINT_MAX, "Invalid down interval"},
};
int r;
struct flakey_c *fc;
unsigned long long tmpll;
struct dm_arg_set as;
const char *devname;
char dummy;
as.argc = argc;
as.argv = argv;
if (argc < 4) {
ti->error = "Invalid argument count";
return -EINVAL;
}
fc = kzalloc(sizeof(*fc), GFP_KERNEL);
if (!fc) {
ti->error = "Cannot allocate context";
return -ENOMEM;
}
fc->start_time = jiffies;
devname = dm_shift_arg(&as);
r = -EINVAL;
if (sscanf(dm_shift_arg(&as), "%llu%c", &tmpll, &dummy) != 1) {
ti->error = "Invalid device sector";
goto bad;
}
fc->start = tmpll;
r = dm_read_arg(_args, &as, &fc->up_interval, &ti->error);
if (r)
goto bad;
r = dm_read_arg(_args, &as, &fc->down_interval, &ti->error);
if (r)
goto bad;
if (!(fc->up_interval + fc->down_interval)) {
ti->error = "Total (up + down) interval is zero";
r = -EINVAL;
goto bad;
}
if (fc->up_interval + fc->down_interval < fc->up_interval) {
ti->error = "Interval overflow";
r = -EINVAL;
goto bad;
}
r = parse_features(&as, fc, ti);
if (r)
goto bad;
r = dm_get_device(ti, devname, dm_table_get_mode(ti->table), &fc->dev);
if (r) {
ti->error = "Device lookup failed";
goto bad;
}
ti->num_flush_bios = 1;
ti->num_discard_bios = 1;
ti->per_io_data_size = sizeof(struct per_bio_data);
ti->private = fc;
return 0;
bad:
kfree(fc);
return r;
}
static void flakey_dtr(struct dm_target *ti)
{
struct flakey_c *fc = ti->private;
dm_put_device(ti, fc->dev);
kfree(fc);
}
static sector_t flakey_map_sector(struct dm_target *ti, sector_t bi_sector)
{
struct flakey_c *fc = ti->private;
return fc->start + dm_target_offset(ti, bi_sector);
}
static void flakey_map_bio(struct dm_target *ti, struct bio *bio)
{
struct flakey_c *fc = ti->private;
bio->bi_bdev = fc->dev->bdev;
if (bio_sectors(bio))
bio->bi_iter.bi_sector =
flakey_map_sector(ti, bio->bi_iter.bi_sector);
}
static void corrupt_bio_data(struct bio *bio, struct flakey_c *fc)
{
unsigned bio_bytes = bio_cur_bytes(bio);
char *data = bio_data(bio);
if (data && bio_bytes >= fc->corrupt_bio_byte) {
data[fc->corrupt_bio_byte - 1] = fc->corrupt_bio_value;
DMDEBUG("Corrupting data bio=%p by writing %u to byte %u "
"(rw=%c bi_opf=%u bi_sector=%llu cur_bytes=%u)\n",
bio, fc->corrupt_bio_value, fc->corrupt_bio_byte,
(bio_data_dir(bio) == WRITE) ? 'w' : 'r', bio->bi_opf,
(unsigned long long)bio->bi_iter.bi_sector, bio_bytes);
}
}
static int flakey_map(struct dm_target *ti, struct bio *bio)
{
struct flakey_c *fc = ti->private;
unsigned elapsed;
struct per_bio_data *pb = dm_per_bio_data(bio, sizeof(struct per_bio_data));
pb->bio_submitted = false;
elapsed = (jiffies - fc->start_time) / HZ;
if (elapsed % (fc->up_interval + fc->down_interval) >= fc->up_interval) {
pb->bio_submitted = true;
if (bio_data_dir(bio) == READ) {
if (!fc->corrupt_bio_byte && !test_bit(DROP_WRITES, &fc->flags) &&
!test_bit(ERROR_WRITES, &fc->flags))
return -EIO;
goto map_bio;
}
if (test_bit(DROP_WRITES, &fc->flags)) {
bio_endio(bio);
return DM_MAPIO_SUBMITTED;
}
else if (test_bit(ERROR_WRITES, &fc->flags)) {
bio_io_error(bio);
return DM_MAPIO_SUBMITTED;
}
if (fc->corrupt_bio_byte && (fc->corrupt_bio_rw == WRITE)) {
if (all_corrupt_bio_flags_match(bio, fc))
corrupt_bio_data(bio, fc);
goto map_bio;
}
return -EIO;
}
map_bio:
flakey_map_bio(ti, bio);
return DM_MAPIO_REMAPPED;
}
static int flakey_end_io(struct dm_target *ti, struct bio *bio, int error)
{
struct flakey_c *fc = ti->private;
struct per_bio_data *pb = dm_per_bio_data(bio, sizeof(struct per_bio_data));
if (!error && pb->bio_submitted && (bio_data_dir(bio) == READ)) {
if (fc->corrupt_bio_byte && (fc->corrupt_bio_rw == READ) &&
all_corrupt_bio_flags_match(bio, fc)) {
corrupt_bio_data(bio, fc);
} else if (!test_bit(DROP_WRITES, &fc->flags) &&
!test_bit(ERROR_WRITES, &fc->flags)) {
return -EIO;
}
}
return error;
}
static void flakey_status(struct dm_target *ti, status_type_t type,
unsigned status_flags, char *result, unsigned maxlen)
{
unsigned sz = 0;
struct flakey_c *fc = ti->private;
unsigned drop_writes, error_writes;
switch (type) {
case STATUSTYPE_INFO:
result[0] = '\0';
break;
case STATUSTYPE_TABLE:
DMEMIT("%s %llu %u %u ", fc->dev->name,
(unsigned long long)fc->start, fc->up_interval,
fc->down_interval);
drop_writes = test_bit(DROP_WRITES, &fc->flags);
error_writes = test_bit(ERROR_WRITES, &fc->flags);
DMEMIT("%u ", drop_writes + error_writes + (fc->corrupt_bio_byte > 0) * 5);
if (drop_writes)
DMEMIT("drop_writes ");
else if (error_writes)
DMEMIT("error_writes ");
if (fc->corrupt_bio_byte)
DMEMIT("corrupt_bio_byte %u %c %u %u ",
fc->corrupt_bio_byte,
(fc->corrupt_bio_rw == WRITE) ? 'w' : 'r',
fc->corrupt_bio_value, fc->corrupt_bio_flags);
break;
}
}
static int flakey_prepare_ioctl(struct dm_target *ti,
struct block_device **bdev, fmode_t *mode)
{
struct flakey_c *fc = ti->private;
*bdev = fc->dev->bdev;
if (fc->start ||
ti->len != i_size_read((*bdev)->bd_inode) >> SECTOR_SHIFT)
return 1;
return 0;
}
static int flakey_iterate_devices(struct dm_target *ti, iterate_devices_callout_fn fn, void *data)
{
struct flakey_c *fc = ti->private;
return fn(ti, fc->dev, fc->start, ti->len, data);
}
static int __init dm_flakey_init(void)
{
int r = dm_register_target(&flakey_target);
if (r < 0)
DMERR("register failed %d", r);
return r;
}
static void __exit dm_flakey_exit(void)
{
dm_unregister_target(&flakey_target);
}
