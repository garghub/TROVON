static int raid0_congested(void *data, int bits)
{
mddev_t *mddev = data;
raid0_conf_t *conf = mddev->private;
mdk_rdev_t **devlist = conf->devlist;
int raid_disks = conf->strip_zone[0].nb_dev;
int i, ret = 0;
if (mddev_congested(mddev, bits))
return 1;
for (i = 0; i < raid_disks && !ret ; i++) {
struct request_queue *q = bdev_get_queue(devlist[i]->bdev);
ret |= bdi_congested(&q->backing_dev_info, bits);
}
return ret;
}
static void dump_zones(mddev_t *mddev)
{
int j, k, h;
sector_t zone_size = 0;
sector_t zone_start = 0;
char b[BDEVNAME_SIZE];
raid0_conf_t *conf = mddev->private;
int raid_disks = conf->strip_zone[0].nb_dev;
printk(KERN_INFO "******* %s configuration *********\n",
mdname(mddev));
h = 0;
for (j = 0; j < conf->nr_strip_zones; j++) {
printk(KERN_INFO "zone%d=[", j);
for (k = 0; k < conf->strip_zone[j].nb_dev; k++)
printk(KERN_CONT "%s/",
bdevname(conf->devlist[j*raid_disks
+ k]->bdev, b));
printk(KERN_CONT "]\n");
zone_size = conf->strip_zone[j].zone_end - zone_start;
printk(KERN_INFO " zone offset=%llukb "
"device offset=%llukb size=%llukb\n",
(unsigned long long)zone_start>>1,
(unsigned long long)conf->strip_zone[j].dev_start>>1,
(unsigned long long)zone_size>>1);
zone_start = conf->strip_zone[j].zone_end;
}
printk(KERN_INFO "**********************************\n\n");
}
static int create_strip_zones(mddev_t *mddev, raid0_conf_t **private_conf)
{
int i, c, err;
sector_t curr_zone_end, sectors;
mdk_rdev_t *smallest, *rdev1, *rdev2, *rdev, **dev;
struct strip_zone *zone;
int cnt;
char b[BDEVNAME_SIZE];
raid0_conf_t *conf = kzalloc(sizeof(*conf), GFP_KERNEL);
if (!conf)
return -ENOMEM;
list_for_each_entry(rdev1, &mddev->disks, same_set) {
printk(KERN_INFO "md/raid0:%s: looking at %s\n",
mdname(mddev),
bdevname(rdev1->bdev, b));
c = 0;
sectors = rdev1->sectors;
sector_div(sectors, mddev->chunk_sectors);
rdev1->sectors = sectors * mddev->chunk_sectors;
list_for_each_entry(rdev2, &mddev->disks, same_set) {
printk(KERN_INFO "md/raid0:%s: comparing %s(%llu)",
mdname(mddev),
bdevname(rdev1->bdev,b),
(unsigned long long)rdev1->sectors);
printk(KERN_CONT " with %s(%llu)\n",
bdevname(rdev2->bdev,b),
(unsigned long long)rdev2->sectors);
if (rdev2 == rdev1) {
printk(KERN_INFO "md/raid0:%s: END\n",
mdname(mddev));
break;
}
if (rdev2->sectors == rdev1->sectors) {
printk(KERN_INFO "md/raid0:%s: EQUAL\n",
mdname(mddev));
c = 1;
break;
}
printk(KERN_INFO "md/raid0:%s: NOT EQUAL\n",
mdname(mddev));
}
if (!c) {
printk(KERN_INFO "md/raid0:%s: ==> UNIQUE\n",
mdname(mddev));
conf->nr_strip_zones++;
printk(KERN_INFO "md/raid0:%s: %d zones\n",
mdname(mddev), conf->nr_strip_zones);
}
}
printk(KERN_INFO "md/raid0:%s: FINAL %d zones\n",
mdname(mddev), conf->nr_strip_zones);
err = -ENOMEM;
conf->strip_zone = kzalloc(sizeof(struct strip_zone)*
conf->nr_strip_zones, GFP_KERNEL);
if (!conf->strip_zone)
goto abort;
conf->devlist = kzalloc(sizeof(mdk_rdev_t*)*
conf->nr_strip_zones*mddev->raid_disks,
GFP_KERNEL);
if (!conf->devlist)
goto abort;
zone = &conf->strip_zone[0];
cnt = 0;
smallest = NULL;
dev = conf->devlist;
err = -EINVAL;
list_for_each_entry(rdev1, &mddev->disks, same_set) {
int j = rdev1->raid_disk;
if (mddev->level == 10) {
j /= 2;
rdev1->new_raid_disk = j;
}
if (mddev->level == 1) {
j = 0;
rdev1->new_raid_disk = j;
}
if (j < 0 || j >= mddev->raid_disks) {
printk(KERN_ERR "md/raid0:%s: bad disk number %d - "
"aborting!\n", mdname(mddev), j);
goto abort;
}
if (dev[j]) {
printk(KERN_ERR "md/raid0:%s: multiple devices for %d - "
"aborting!\n", mdname(mddev), j);
goto abort;
}
dev[j] = rdev1;
disk_stack_limits(mddev->gendisk, rdev1->bdev,
rdev1->data_offset << 9);
if (rdev1->bdev->bd_disk->queue->merge_bvec_fn) {
blk_queue_max_segments(mddev->queue, 1);
blk_queue_segment_boundary(mddev->queue,
PAGE_CACHE_SIZE - 1);
}
if (!smallest || (rdev1->sectors < smallest->sectors))
smallest = rdev1;
cnt++;
}
if (cnt != mddev->raid_disks) {
printk(KERN_ERR "md/raid0:%s: too few disks (%d of %d) - "
"aborting!\n", mdname(mddev), cnt, mddev->raid_disks);
goto abort;
}
zone->nb_dev = cnt;
zone->zone_end = smallest->sectors * cnt;
curr_zone_end = zone->zone_end;
for (i = 1; i < conf->nr_strip_zones; i++)
{
int j;
zone = conf->strip_zone + i;
dev = conf->devlist + i * mddev->raid_disks;
printk(KERN_INFO "md/raid0:%s: zone %d\n",
mdname(mddev), i);
zone->dev_start = smallest->sectors;
smallest = NULL;
c = 0;
for (j=0; j<cnt; j++) {
rdev = conf->devlist[j];
printk(KERN_INFO "md/raid0:%s: checking %s ...",
mdname(mddev),
bdevname(rdev->bdev, b));
if (rdev->sectors <= zone->dev_start) {
printk(KERN_CONT " nope.\n");
continue;
}
printk(KERN_CONT " contained as device %d\n", c);
dev[c] = rdev;
c++;
if (!smallest || rdev->sectors < smallest->sectors) {
smallest = rdev;
printk(KERN_INFO "md/raid0:%s: (%llu) is smallest!.\n",
mdname(mddev),
(unsigned long long)rdev->sectors);
}
}
zone->nb_dev = c;
sectors = (smallest->sectors - zone->dev_start) * c;
printk(KERN_INFO "md/raid0:%s: zone->nb_dev: %d, sectors: %llu\n",
mdname(mddev),
zone->nb_dev, (unsigned long long)sectors);
curr_zone_end += sectors;
zone->zone_end = curr_zone_end;
printk(KERN_INFO "md/raid0:%s: current zone start: %llu\n",
mdname(mddev),
(unsigned long long)smallest->sectors);
}
mddev->queue->backing_dev_info.congested_fn = raid0_congested;
mddev->queue->backing_dev_info.congested_data = mddev;
if ((mddev->chunk_sectors << 9) % queue_logical_block_size(mddev->queue)) {
printk(KERN_ERR "md/raid0:%s: chunk_size of %d not valid\n",
mdname(mddev),
mddev->chunk_sectors << 9);
goto abort;
}
blk_queue_io_min(mddev->queue, mddev->chunk_sectors << 9);
blk_queue_io_opt(mddev->queue,
(mddev->chunk_sectors << 9) * mddev->raid_disks);
printk(KERN_INFO "md/raid0:%s: done.\n", mdname(mddev));
*private_conf = conf;
return 0;
abort:
kfree(conf->strip_zone);
kfree(conf->devlist);
kfree(conf);
*private_conf = NULL;
return err;
}
static int raid0_mergeable_bvec(struct request_queue *q,
struct bvec_merge_data *bvm,
struct bio_vec *biovec)
{
mddev_t *mddev = q->queuedata;
sector_t sector = bvm->bi_sector + get_start_sect(bvm->bi_bdev);
int max;
unsigned int chunk_sectors = mddev->chunk_sectors;
unsigned int bio_sectors = bvm->bi_size >> 9;
if (is_power_of_2(chunk_sectors))
max = (chunk_sectors - ((sector & (chunk_sectors-1))
+ bio_sectors)) << 9;
else
max = (chunk_sectors - (sector_div(sector, chunk_sectors)
+ bio_sectors)) << 9;
if (max < 0) max = 0;
if (max <= biovec->bv_len && bio_sectors == 0)
return biovec->bv_len;
else
return max;
}
static sector_t raid0_size(mddev_t *mddev, sector_t sectors, int raid_disks)
{
sector_t array_sectors = 0;
mdk_rdev_t *rdev;
WARN_ONCE(sectors || raid_disks,
"%s does not support generic reshape\n", __func__);
list_for_each_entry(rdev, &mddev->disks, same_set)
array_sectors += rdev->sectors;
return array_sectors;
}
static int raid0_run(mddev_t *mddev)
{
raid0_conf_t *conf;
int ret;
if (mddev->chunk_sectors == 0) {
printk(KERN_ERR "md/raid0:%s: chunk size must be set.\n",
mdname(mddev));
return -EINVAL;
}
if (md_check_no_bitmap(mddev))
return -EINVAL;
blk_queue_max_hw_sectors(mddev->queue, mddev->chunk_sectors);
if (mddev->private == NULL) {
ret = create_strip_zones(mddev, &conf);
if (ret < 0)
return ret;
mddev->private = conf;
}
conf = mddev->private;
md_set_array_sectors(mddev, raid0_size(mddev, 0, 0));
printk(KERN_INFO "md/raid0:%s: md_size is %llu sectors.\n",
mdname(mddev),
(unsigned long long)mddev->array_sectors);
{
int stripe = mddev->raid_disks *
(mddev->chunk_sectors << 9) / PAGE_SIZE;
if (mddev->queue->backing_dev_info.ra_pages < 2* stripe)
mddev->queue->backing_dev_info.ra_pages = 2* stripe;
}
blk_queue_merge_bvec(mddev->queue, raid0_mergeable_bvec);
dump_zones(mddev);
return md_integrity_register(mddev);
}
static int raid0_stop(mddev_t *mddev)
{
raid0_conf_t *conf = mddev->private;
blk_sync_queue(mddev->queue);
kfree(conf->strip_zone);
kfree(conf->devlist);
kfree(conf);
mddev->private = NULL;
return 0;
}
static struct strip_zone *find_zone(struct raid0_private_data *conf,
sector_t *sectorp)
{
int i;
struct strip_zone *z = conf->strip_zone;
sector_t sector = *sectorp;
for (i = 0; i < conf->nr_strip_zones; i++)
if (sector < z[i].zone_end) {
if (i)
*sectorp = sector - z[i-1].zone_end;
return z + i;
}
BUG();
}
static mdk_rdev_t *map_sector(mddev_t *mddev, struct strip_zone *zone,
sector_t sector, sector_t *sector_offset)
{
unsigned int sect_in_chunk;
sector_t chunk;
raid0_conf_t *conf = mddev->private;
int raid_disks = conf->strip_zone[0].nb_dev;
unsigned int chunk_sects = mddev->chunk_sectors;
if (is_power_of_2(chunk_sects)) {
int chunksect_bits = ffz(~chunk_sects);
sect_in_chunk = sector & (chunk_sects - 1);
sector >>= chunksect_bits;
chunk = *sector_offset;
sector_div(chunk, zone->nb_dev << chunksect_bits);
} else{
sect_in_chunk = sector_div(sector, chunk_sects);
chunk = *sector_offset;
sector_div(chunk, chunk_sects * zone->nb_dev);
}
*sector_offset = (chunk * chunk_sects) + sect_in_chunk;
return conf->devlist[(zone - conf->strip_zone)*raid_disks
+ sector_div(sector, zone->nb_dev)];
}
static inline int is_io_in_chunk_boundary(mddev_t *mddev,
unsigned int chunk_sects, struct bio *bio)
{
if (likely(is_power_of_2(chunk_sects))) {
return chunk_sects >= ((bio->bi_sector & (chunk_sects-1))
+ (bio->bi_size >> 9));
} else{
sector_t sector = bio->bi_sector;
return chunk_sects >= (sector_div(sector, chunk_sects)
+ (bio->bi_size >> 9));
}
}
static int raid0_make_request(mddev_t *mddev, struct bio *bio)
{
unsigned int chunk_sects;
sector_t sector_offset;
struct strip_zone *zone;
mdk_rdev_t *tmp_dev;
if (unlikely(bio->bi_rw & REQ_FLUSH)) {
md_flush_request(mddev, bio);
return 0;
}
chunk_sects = mddev->chunk_sectors;
if (unlikely(!is_io_in_chunk_boundary(mddev, chunk_sects, bio))) {
sector_t sector = bio->bi_sector;
struct bio_pair *bp;
if (bio->bi_vcnt != 1 ||
bio->bi_idx != 0)
goto bad_map;
if (likely(is_power_of_2(chunk_sects)))
bp = bio_split(bio, chunk_sects - (sector &
(chunk_sects-1)));
else
bp = bio_split(bio, chunk_sects -
sector_div(sector, chunk_sects));
if (raid0_make_request(mddev, &bp->bio1))
generic_make_request(&bp->bio1);
if (raid0_make_request(mddev, &bp->bio2))
generic_make_request(&bp->bio2);
bio_pair_release(bp);
return 0;
}
sector_offset = bio->bi_sector;
zone = find_zone(mddev->private, &sector_offset);
tmp_dev = map_sector(mddev, zone, bio->bi_sector,
&sector_offset);
bio->bi_bdev = tmp_dev->bdev;
bio->bi_sector = sector_offset + zone->dev_start +
tmp_dev->data_offset;
return 1;
bad_map:
printk("md/raid0:%s: make_request bug: can't convert block across chunks"
" or bigger than %dk %llu %d\n",
mdname(mddev), chunk_sects / 2,
(unsigned long long)bio->bi_sector, bio->bi_size >> 10);
bio_io_error(bio);
return 0;
}
static void raid0_status(struct seq_file *seq, mddev_t *mddev)
{
#undef MD_DEBUG
#ifdef MD_DEBUG
int j, k, h;
char b[BDEVNAME_SIZE];
raid0_conf_t *conf = mddev->private;
int raid_disks = conf->strip_zone[0].nb_dev;
sector_t zone_size;
sector_t zone_start = 0;
h = 0;
for (j = 0; j < conf->nr_strip_zones; j++) {
seq_printf(seq, " z%d", j);
seq_printf(seq, "=[");
for (k = 0; k < conf->strip_zone[j].nb_dev; k++)
seq_printf(seq, "%s/", bdevname(
conf->devlist[j*raid_disks + k]
->bdev, b));
zone_size = conf->strip_zone[j].zone_end - zone_start;
seq_printf(seq, "] ze=%lld ds=%lld s=%lld\n",
(unsigned long long)zone_start>>1,
(unsigned long long)conf->strip_zone[j].dev_start>>1,
(unsigned long long)zone_size>>1);
zone_start = conf->strip_zone[j].zone_end;
}
#endif
seq_printf(seq, " %dk chunks", mddev->chunk_sectors / 2);
return;
}
static void *raid0_takeover_raid45(mddev_t *mddev)
{
mdk_rdev_t *rdev;
raid0_conf_t *priv_conf;
if (mddev->degraded != 1) {
printk(KERN_ERR "md/raid0:%s: raid5 must be degraded! Degraded disks: %d\n",
mdname(mddev),
mddev->degraded);
return ERR_PTR(-EINVAL);
}
list_for_each_entry(rdev, &mddev->disks, same_set) {
if (rdev->raid_disk == mddev->raid_disks-1) {
printk(KERN_ERR "md/raid0:%s: raid5 must have missing parity disk!\n",
mdname(mddev));
return ERR_PTR(-EINVAL);
}
}
mddev->new_level = 0;
mddev->new_layout = 0;
mddev->new_chunk_sectors = mddev->chunk_sectors;
mddev->raid_disks--;
mddev->delta_disks = -1;
mddev->recovery_cp = MaxSector;
create_strip_zones(mddev, &priv_conf);
return priv_conf;
}
static void *raid0_takeover_raid10(mddev_t *mddev)
{
raid0_conf_t *priv_conf;
if (mddev->layout != ((1 << 8) + 2)) {
printk(KERN_ERR "md/raid0:%s:: Raid0 cannot takover layout: 0x%x\n",
mdname(mddev),
mddev->layout);
return ERR_PTR(-EINVAL);
}
if (mddev->raid_disks & 1) {
printk(KERN_ERR "md/raid0:%s: Raid0 cannot takover Raid10 with odd disk number.\n",
mdname(mddev));
return ERR_PTR(-EINVAL);
}
if (mddev->degraded != (mddev->raid_disks>>1)) {
printk(KERN_ERR "md/raid0:%s: All mirrors must be already degraded!\n",
mdname(mddev));
return ERR_PTR(-EINVAL);
}
mddev->new_level = 0;
mddev->new_layout = 0;
mddev->new_chunk_sectors = mddev->chunk_sectors;
mddev->delta_disks = - mddev->raid_disks / 2;
mddev->raid_disks += mddev->delta_disks;
mddev->degraded = 0;
mddev->recovery_cp = MaxSector;
create_strip_zones(mddev, &priv_conf);
return priv_conf;
}
static void *raid0_takeover_raid1(mddev_t *mddev)
{
raid0_conf_t *priv_conf;
if ((mddev->raid_disks - 1) != mddev->degraded) {
printk(KERN_ERR "md/raid0:%s: (N - 1) mirrors drives must be already faulty!\n",
mdname(mddev));
return ERR_PTR(-EINVAL);
}
mddev->new_level = 0;
mddev->new_layout = 0;
mddev->new_chunk_sectors = 128;
mddev->delta_disks = 1 - mddev->raid_disks;
mddev->raid_disks = 1;
mddev->recovery_cp = MaxSector;
create_strip_zones(mddev, &priv_conf);
return priv_conf;
}
static void *raid0_takeover(mddev_t *mddev)
{
if (mddev->level == 4)
return raid0_takeover_raid45(mddev);
if (mddev->level == 5) {
if (mddev->layout == ALGORITHM_PARITY_N)
return raid0_takeover_raid45(mddev);
printk(KERN_ERR "md/raid0:%s: Raid can only takeover Raid5 with layout: %d\n",
mdname(mddev), ALGORITHM_PARITY_N);
}
if (mddev->level == 10)
return raid0_takeover_raid10(mddev);
if (mddev->level == 1)
return raid0_takeover_raid1(mddev);
printk(KERN_ERR "Takeover from raid%i to raid0 not supported\n",
mddev->level);
return ERR_PTR(-EINVAL);
}
static void raid0_quiesce(mddev_t *mddev, int state)
{
}
static int __init raid0_init (void)
{
return register_md_personality (&raid0_personality);
}
static void raid0_exit (void)
{
unregister_md_personality (&raid0_personality);
}
