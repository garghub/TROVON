static void faulty_fail(struct bio *bio, int error)
{
struct bio *b = bio->bi_private;
b->bi_iter.bi_size = bio->bi_iter.bi_size;
b->bi_iter.bi_sector = bio->bi_iter.bi_sector;
bio_put(bio);
bio_io_error(b);
}
static int check_mode(struct faulty_conf *conf, int mode)
{
if (conf->period[mode] == 0 &&
atomic_read(&conf->counters[mode]) <= 0)
return 0;
if (atomic_dec_and_test(&conf->counters[mode])) {
if (conf->period[mode])
atomic_set(&conf->counters[mode], conf->period[mode]);
return 1;
}
return 0;
}
static int check_sector(struct faulty_conf *conf, sector_t start, sector_t end, int dir)
{
int i;
for (i=0; i<conf->nfaults; i++)
if (conf->faults[i] >= start &&
conf->faults[i] < end) {
switch (conf->modes[i] * 2 + dir) {
case WritePersistent*2+WRITE: return 1;
case ReadPersistent*2+READ: return 1;
case ReadFixable*2+READ: return 1;
case ReadFixable*2+WRITE:
conf->modes[i] = NoPersist;
return 0;
case AllPersist*2+READ:
case AllPersist*2+WRITE: return 1;
default:
return 0;
}
}
return 0;
}
static void add_sector(struct faulty_conf *conf, sector_t start, int mode)
{
int i;
int n = conf->nfaults;
for (i=0; i<conf->nfaults; i++)
if (conf->faults[i] == start) {
switch(mode) {
case NoPersist: conf->modes[i] = mode; return;
case WritePersistent:
if (conf->modes[i] == ReadPersistent ||
conf->modes[i] == ReadFixable)
conf->modes[i] = AllPersist;
else
conf->modes[i] = WritePersistent;
return;
case ReadPersistent:
if (conf->modes[i] == WritePersistent)
conf->modes[i] = AllPersist;
else
conf->modes[i] = ReadPersistent;
return;
case ReadFixable:
if (conf->modes[i] == WritePersistent ||
conf->modes[i] == ReadPersistent)
conf->modes[i] = AllPersist;
else
conf->modes[i] = ReadFixable;
return;
}
} else if (conf->modes[i] == NoPersist)
n = i;
if (n >= MaxFault)
return;
conf->faults[n] = start;
conf->modes[n] = mode;
if (conf->nfaults == n)
conf->nfaults = n+1;
}
static void make_request(struct mddev *mddev, struct bio *bio)
{
struct faulty_conf *conf = mddev->private;
int failit = 0;
if (bio_data_dir(bio) == WRITE) {
if (atomic_read(&conf->counters[WriteAll])) {
bio_endio(bio, -EIO);
return;
}
if (check_sector(conf, bio->bi_iter.bi_sector,
bio_end_sector(bio), WRITE))
failit = 1;
if (check_mode(conf, WritePersistent)) {
add_sector(conf, bio->bi_iter.bi_sector,
WritePersistent);
failit = 1;
}
if (check_mode(conf, WriteTransient))
failit = 1;
} else {
if (check_sector(conf, bio->bi_iter.bi_sector,
bio_end_sector(bio), READ))
failit = 1;
if (check_mode(conf, ReadTransient))
failit = 1;
if (check_mode(conf, ReadPersistent)) {
add_sector(conf, bio->bi_iter.bi_sector,
ReadPersistent);
failit = 1;
}
if (check_mode(conf, ReadFixable)) {
add_sector(conf, bio->bi_iter.bi_sector,
ReadFixable);
failit = 1;
}
}
if (failit) {
struct bio *b = bio_clone_mddev(bio, GFP_NOIO, mddev);
b->bi_bdev = conf->rdev->bdev;
b->bi_private = bio;
b->bi_end_io = faulty_fail;
bio = b;
} else
bio->bi_bdev = conf->rdev->bdev;
generic_make_request(bio);
}
static void status(struct seq_file *seq, struct mddev *mddev)
{
struct faulty_conf *conf = mddev->private;
int n;
if ((n=atomic_read(&conf->counters[WriteTransient])) != 0)
seq_printf(seq, " WriteTransient=%d(%d)",
n, conf->period[WriteTransient]);
if ((n=atomic_read(&conf->counters[ReadTransient])) != 0)
seq_printf(seq, " ReadTransient=%d(%d)",
n, conf->period[ReadTransient]);
if ((n=atomic_read(&conf->counters[WritePersistent])) != 0)
seq_printf(seq, " WritePersistent=%d(%d)",
n, conf->period[WritePersistent]);
if ((n=atomic_read(&conf->counters[ReadPersistent])) != 0)
seq_printf(seq, " ReadPersistent=%d(%d)",
n, conf->period[ReadPersistent]);
if ((n=atomic_read(&conf->counters[ReadFixable])) != 0)
seq_printf(seq, " ReadFixable=%d(%d)",
n, conf->period[ReadFixable]);
if ((n=atomic_read(&conf->counters[WriteAll])) != 0)
seq_printf(seq, " WriteAll");
seq_printf(seq, " nfaults=%d", conf->nfaults);
}
static int reshape(struct mddev *mddev)
{
int mode = mddev->new_layout & ModeMask;
int count = mddev->new_layout >> ModeShift;
struct faulty_conf *conf = mddev->private;
if (mddev->new_layout < 0)
return 0;
if (mode == ClearFaults)
conf->nfaults = 0;
else if (mode == ClearErrors) {
int i;
for (i=0 ; i < Modes ; i++) {
conf->period[i] = 0;
atomic_set(&conf->counters[i], 0);
}
} else if (mode < Modes) {
conf->period[mode] = count;
if (!count) count++;
atomic_set(&conf->counters[mode], count);
} else
return -EINVAL;
mddev->new_layout = -1;
mddev->layout = -1;
return 0;
}
static sector_t faulty_size(struct mddev *mddev, sector_t sectors, int raid_disks)
{
WARN_ONCE(raid_disks,
"%s does not support generic reshape\n", __func__);
if (sectors == 0)
return mddev->dev_sectors;
return sectors;
}
static int run(struct mddev *mddev)
{
struct md_rdev *rdev;
int i;
struct faulty_conf *conf;
if (md_check_no_bitmap(mddev))
return -EINVAL;
conf = kmalloc(sizeof(*conf), GFP_KERNEL);
if (!conf)
return -ENOMEM;
for (i=0; i<Modes; i++) {
atomic_set(&conf->counters[i], 0);
conf->period[i] = 0;
}
conf->nfaults = 0;
rdev_for_each(rdev, mddev) {
conf->rdev = rdev;
disk_stack_limits(mddev->gendisk, rdev->bdev,
rdev->data_offset << 9);
}
md_set_array_sectors(mddev, faulty_size(mddev, 0, 0));
mddev->private = conf;
reshape(mddev);
return 0;
}
static void faulty_free(struct mddev *mddev, void *priv)
{
struct faulty_conf *conf = priv;
kfree(conf);
}
static int __init raid_init(void)
{
return register_md_personality(&faulty_personality);
}
static void raid_exit(void)
{
unregister_md_personality(&faulty_personality);
}
