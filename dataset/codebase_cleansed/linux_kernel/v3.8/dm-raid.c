static unsigned raid10_md_layout_to_copies(int layout)
{
return layout & 0xFF;
}
static int raid10_format_to_md_layout(char *format, unsigned copies)
{
return (1 << 8) | (copies & 0xFF);
}
static struct raid_type *get_raid_type(char *name)
{
int i;
for (i = 0; i < ARRAY_SIZE(raid_types); i++)
if (!strcmp(raid_types[i].name, name))
return &raid_types[i];
return NULL;
}
static struct raid_set *context_alloc(struct dm_target *ti, struct raid_type *raid_type, unsigned raid_devs)
{
unsigned i;
struct raid_set *rs;
if (raid_devs <= raid_type->parity_devs) {
ti->error = "Insufficient number of devices";
return ERR_PTR(-EINVAL);
}
rs = kzalloc(sizeof(*rs) + raid_devs * sizeof(rs->dev[0]), GFP_KERNEL);
if (!rs) {
ti->error = "Cannot allocate raid context";
return ERR_PTR(-ENOMEM);
}
mddev_init(&rs->md);
rs->ti = ti;
rs->raid_type = raid_type;
rs->md.raid_disks = raid_devs;
rs->md.level = raid_type->level;
rs->md.new_level = rs->md.level;
rs->md.layout = raid_type->algorithm;
rs->md.new_layout = rs->md.layout;
rs->md.delta_disks = 0;
rs->md.recovery_cp = 0;
for (i = 0; i < raid_devs; i++)
md_rdev_init(&rs->dev[i].rdev);
return rs;
}
static void context_free(struct raid_set *rs)
{
int i;
for (i = 0; i < rs->md.raid_disks; i++) {
if (rs->dev[i].meta_dev)
dm_put_device(rs->ti, rs->dev[i].meta_dev);
md_rdev_clear(&rs->dev[i].rdev);
if (rs->dev[i].data_dev)
dm_put_device(rs->ti, rs->dev[i].data_dev);
}
kfree(rs);
}
static int dev_parms(struct raid_set *rs, char **argv)
{
int i;
int rebuild = 0;
int metadata_available = 0;
int ret = 0;
for (i = 0; i < rs->md.raid_disks; i++, argv += 2) {
rs->dev[i].rdev.raid_disk = i;
rs->dev[i].meta_dev = NULL;
rs->dev[i].data_dev = NULL;
rs->dev[i].rdev.data_offset = 0;
rs->dev[i].rdev.mddev = &rs->md;
if (strcmp(argv[0], "-")) {
ret = dm_get_device(rs->ti, argv[0],
dm_table_get_mode(rs->ti->table),
&rs->dev[i].meta_dev);
rs->ti->error = "RAID metadata device lookup failure";
if (ret)
return ret;
rs->dev[i].rdev.sb_page = alloc_page(GFP_KERNEL);
if (!rs->dev[i].rdev.sb_page)
return -ENOMEM;
}
if (!strcmp(argv[1], "-")) {
if (!test_bit(In_sync, &rs->dev[i].rdev.flags) &&
(!rs->dev[i].rdev.recovery_offset)) {
rs->ti->error = "Drive designated for rebuild not specified";
return -EINVAL;
}
rs->ti->error = "No data device supplied with metadata device";
if (rs->dev[i].meta_dev)
return -EINVAL;
continue;
}
ret = dm_get_device(rs->ti, argv[1],
dm_table_get_mode(rs->ti->table),
&rs->dev[i].data_dev);
if (ret) {
rs->ti->error = "RAID device lookup failure";
return ret;
}
if (rs->dev[i].meta_dev) {
metadata_available = 1;
rs->dev[i].rdev.meta_bdev = rs->dev[i].meta_dev->bdev;
}
rs->dev[i].rdev.bdev = rs->dev[i].data_dev->bdev;
list_add(&rs->dev[i].rdev.same_set, &rs->md.disks);
if (!test_bit(In_sync, &rs->dev[i].rdev.flags))
rebuild++;
}
if (metadata_available) {
rs->md.external = 0;
rs->md.persistent = 1;
rs->md.major_version = 2;
} else if (rebuild && !rs->md.recovery_cp) {
DMERR("Unable to rebuild drive while array is not in-sync");
rs->ti->error = "RAID device lookup failure";
return -EINVAL;
}
return 0;
}
static int validate_region_size(struct raid_set *rs, unsigned long region_size)
{
unsigned long min_region_size = rs->ti->len / (1 << 21);
if (!region_size) {
if (min_region_size > (1 << 13)) {
if (min_region_size & (min_region_size - 1))
region_size = 1 << fls(region_size);
DMINFO("Choosing default region size of %lu sectors",
region_size);
} else {
DMINFO("Choosing default region size of 4MiB");
region_size = 1 << 13;
}
} else {
if (region_size > rs->ti->len) {
rs->ti->error = "Supplied region size is too large";
return -EINVAL;
}
if (region_size < min_region_size) {
DMERR("Supplied region_size (%lu sectors) below minimum (%lu)",
region_size, min_region_size);
rs->ti->error = "Supplied region size is too small";
return -EINVAL;
}
if (!is_power_of_2(region_size)) {
rs->ti->error = "Region size is not a power of 2";
return -EINVAL;
}
if (region_size < rs->md.chunk_sectors) {
rs->ti->error = "Region size is smaller than the chunk size";
return -EINVAL;
}
}
rs->md.bitmap_info.chunksize = (region_size << 9);
return 0;
}
static int validate_raid_redundancy(struct raid_set *rs)
{
unsigned i, rebuild_cnt = 0;
unsigned rebuilds_per_group, copies, d;
for (i = 0; i < rs->md.raid_disks; i++)
if (!test_bit(In_sync, &rs->dev[i].rdev.flags) ||
!rs->dev[i].rdev.sb_page)
rebuild_cnt++;
switch (rs->raid_type->level) {
case 1:
if (rebuild_cnt >= rs->md.raid_disks)
goto too_many;
break;
case 4:
case 5:
case 6:
if (rebuild_cnt > rs->raid_type->parity_devs)
goto too_many;
break;
case 10:
copies = raid10_md_layout_to_copies(rs->md.layout);
if (rebuild_cnt < copies)
break;
for (i = 0; i < rs->md.raid_disks * copies; i++) {
if (!(i % copies))
rebuilds_per_group = 0;
d = i % rs->md.raid_disks;
if ((!rs->dev[d].rdev.sb_page ||
!test_bit(In_sync, &rs->dev[d].rdev.flags)) &&
(++rebuilds_per_group >= copies))
goto too_many;
}
break;
default:
if (rebuild_cnt)
return -EINVAL;
}
return 0;
too_many:
return -EINVAL;
}
static int parse_raid_params(struct raid_set *rs, char **argv,
unsigned num_raid_params)
{
char *raid10_format = "near";
unsigned raid10_copies = 2;
unsigned i;
unsigned long value, region_size = 0;
sector_t sectors_per_dev = rs->ti->len;
sector_t max_io_len;
char *key;
if ((strict_strtoul(argv[0], 10, &value) < 0)) {
rs->ti->error = "Bad chunk size";
return -EINVAL;
} else if (rs->raid_type->level == 1) {
if (value)
DMERR("Ignoring chunk size parameter for RAID 1");
value = 0;
} else if (!is_power_of_2(value)) {
rs->ti->error = "Chunk size must be a power of 2";
return -EINVAL;
} else if (value < 8) {
rs->ti->error = "Chunk size value is too small";
return -EINVAL;
}
rs->md.new_chunk_sectors = rs->md.chunk_sectors = value;
argv++;
num_raid_params--;
for (i = 0; i < rs->md.raid_disks; i++) {
set_bit(In_sync, &rs->dev[i].rdev.flags);
rs->dev[i].rdev.recovery_offset = MaxSector;
}
for (i = 0; i < num_raid_params; i++) {
if (!strcasecmp(argv[i], "nosync")) {
rs->md.recovery_cp = MaxSector;
rs->print_flags |= DMPF_NOSYNC;
continue;
}
if (!strcasecmp(argv[i], "sync")) {
rs->md.recovery_cp = 0;
rs->print_flags |= DMPF_SYNC;
continue;
}
if ((i + 1) >= num_raid_params) {
rs->ti->error = "Wrong number of raid parameters given";
return -EINVAL;
}
key = argv[i++];
if (!strcasecmp(key, "raid10_format")) {
if (rs->raid_type->level != 10) {
rs->ti->error = "'raid10_format' is an invalid parameter for this RAID type";
return -EINVAL;
}
if (strcmp("near", argv[i])) {
rs->ti->error = "Invalid 'raid10_format' value given";
return -EINVAL;
}
raid10_format = argv[i];
rs->print_flags |= DMPF_RAID10_FORMAT;
continue;
}
if (strict_strtoul(argv[i], 10, &value) < 0) {
rs->ti->error = "Bad numerical argument given in raid params";
return -EINVAL;
}
if (!strcasecmp(key, "rebuild")) {
if (value >= rs->md.raid_disks) {
rs->ti->error = "Invalid rebuild index given";
return -EINVAL;
}
clear_bit(In_sync, &rs->dev[value].rdev.flags);
rs->dev[value].rdev.recovery_offset = 0;
rs->print_flags |= DMPF_REBUILD;
} else if (!strcasecmp(key, "write_mostly")) {
if (rs->raid_type->level != 1) {
rs->ti->error = "write_mostly option is only valid for RAID1";
return -EINVAL;
}
if (value >= rs->md.raid_disks) {
rs->ti->error = "Invalid write_mostly drive index given";
return -EINVAL;
}
set_bit(WriteMostly, &rs->dev[value].rdev.flags);
} else if (!strcasecmp(key, "max_write_behind")) {
if (rs->raid_type->level != 1) {
rs->ti->error = "max_write_behind option is only valid for RAID1";
return -EINVAL;
}
rs->print_flags |= DMPF_MAX_WRITE_BEHIND;
value /= 2;
if (value > COUNTER_MAX) {
rs->ti->error = "Max write-behind limit out of range";
return -EINVAL;
}
rs->md.bitmap_info.max_write_behind = value;
} else if (!strcasecmp(key, "daemon_sleep")) {
rs->print_flags |= DMPF_DAEMON_SLEEP;
if (!value || (value > MAX_SCHEDULE_TIMEOUT)) {
rs->ti->error = "daemon sleep period out of range";
return -EINVAL;
}
rs->md.bitmap_info.daemon_sleep = value;
} else if (!strcasecmp(key, "stripe_cache")) {
rs->print_flags |= DMPF_STRIPE_CACHE;
value /= 2;
if ((rs->raid_type->level != 5) &&
(rs->raid_type->level != 6)) {
rs->ti->error = "Inappropriate argument: stripe_cache";
return -EINVAL;
}
if (raid5_set_cache_size(&rs->md, (int)value)) {
rs->ti->error = "Bad stripe_cache size";
return -EINVAL;
}
} else if (!strcasecmp(key, "min_recovery_rate")) {
rs->print_flags |= DMPF_MIN_RECOVERY_RATE;
if (value > INT_MAX) {
rs->ti->error = "min_recovery_rate out of range";
return -EINVAL;
}
rs->md.sync_speed_min = (int)value;
} else if (!strcasecmp(key, "max_recovery_rate")) {
rs->print_flags |= DMPF_MAX_RECOVERY_RATE;
if (value > INT_MAX) {
rs->ti->error = "max_recovery_rate out of range";
return -EINVAL;
}
rs->md.sync_speed_max = (int)value;
} else if (!strcasecmp(key, "region_size")) {
rs->print_flags |= DMPF_REGION_SIZE;
region_size = value;
} else if (!strcasecmp(key, "raid10_copies") &&
(rs->raid_type->level == 10)) {
if ((value < 2) || (value > 0xFF)) {
rs->ti->error = "Bad value for 'raid10_copies'";
return -EINVAL;
}
rs->print_flags |= DMPF_RAID10_COPIES;
raid10_copies = value;
} else {
DMERR("Unable to parse RAID parameter: %s", key);
rs->ti->error = "Unable to parse RAID parameters";
return -EINVAL;
}
}
if (validate_region_size(rs, region_size))
return -EINVAL;
if (rs->md.chunk_sectors)
max_io_len = rs->md.chunk_sectors;
else
max_io_len = region_size;
if (dm_set_target_max_io_len(rs->ti, max_io_len))
return -EINVAL;
if (rs->raid_type->level == 10) {
if (raid10_copies > rs->md.raid_disks) {
rs->ti->error = "Not enough devices to satisfy specification";
return -EINVAL;
}
sectors_per_dev = rs->ti->len * raid10_copies;
sector_div(sectors_per_dev, rs->md.raid_disks);
rs->md.layout = raid10_format_to_md_layout(raid10_format,
raid10_copies);
rs->md.new_layout = rs->md.layout;
} else if ((rs->raid_type->level > 1) &&
sector_div(sectors_per_dev,
(rs->md.raid_disks - rs->raid_type->parity_devs))) {
rs->ti->error = "Target length not divisible by number of data devices";
return -EINVAL;
}
rs->md.dev_sectors = sectors_per_dev;
rs->md.persistent = 0;
rs->md.external = 1;
return 0;
}
static void do_table_event(struct work_struct *ws)
{
struct raid_set *rs = container_of(ws, struct raid_set, md.event_work);
dm_table_event(rs->ti->table);
}
static int raid_is_congested(struct dm_target_callbacks *cb, int bits)
{
struct raid_set *rs = container_of(cb, struct raid_set, callbacks);
if (rs->raid_type->level == 1)
return md_raid1_congested(&rs->md, bits);
if (rs->raid_type->level == 10)
return md_raid10_congested(&rs->md, bits);
return md_raid5_congested(&rs->md, bits);
}
static int read_disk_sb(struct md_rdev *rdev, int size)
{
BUG_ON(!rdev->sb_page);
if (rdev->sb_loaded)
return 0;
if (!sync_page_io(rdev, 0, size, rdev->sb_page, READ, 1)) {
DMERR("Failed to read superblock of device at position %d",
rdev->raid_disk);
md_error(rdev->mddev, rdev);
return -EINVAL;
}
rdev->sb_loaded = 1;
return 0;
}
static void super_sync(struct mddev *mddev, struct md_rdev *rdev)
{
int i;
uint64_t failed_devices;
struct dm_raid_superblock *sb;
struct raid_set *rs = container_of(mddev, struct raid_set, md);
sb = page_address(rdev->sb_page);
failed_devices = le64_to_cpu(sb->failed_devices);
for (i = 0; i < mddev->raid_disks; i++)
if (!rs->dev[i].data_dev ||
test_bit(Faulty, &(rs->dev[i].rdev.flags)))
failed_devices |= (1ULL << i);
memset(sb, 0, sizeof(*sb));
sb->magic = cpu_to_le32(DM_RAID_MAGIC);
sb->features = cpu_to_le32(0);
sb->num_devices = cpu_to_le32(mddev->raid_disks);
sb->array_position = cpu_to_le32(rdev->raid_disk);
sb->events = cpu_to_le64(mddev->events);
sb->failed_devices = cpu_to_le64(failed_devices);
sb->disk_recovery_offset = cpu_to_le64(rdev->recovery_offset);
sb->array_resync_offset = cpu_to_le64(mddev->recovery_cp);
sb->level = cpu_to_le32(mddev->level);
sb->layout = cpu_to_le32(mddev->layout);
sb->stripe_sectors = cpu_to_le32(mddev->chunk_sectors);
}
static int super_load(struct md_rdev *rdev, struct md_rdev *refdev)
{
int ret;
struct dm_raid_superblock *sb;
struct dm_raid_superblock *refsb;
uint64_t events_sb, events_refsb;
rdev->sb_start = 0;
rdev->sb_size = sizeof(*sb);
ret = read_disk_sb(rdev, rdev->sb_size);
if (ret)
return ret;
sb = page_address(rdev->sb_page);
if ((sb->magic != cpu_to_le32(DM_RAID_MAGIC)) ||
(!test_bit(In_sync, &rdev->flags) && !rdev->recovery_offset)) {
super_sync(rdev->mddev, rdev);
set_bit(FirstUse, &rdev->flags);
set_bit(MD_CHANGE_DEVS, &rdev->mddev->flags);
return refdev ? 0 : 1;
}
if (!refdev)
return 1;
events_sb = le64_to_cpu(sb->events);
refsb = page_address(refdev->sb_page);
events_refsb = le64_to_cpu(refsb->events);
return (events_sb > events_refsb) ? 1 : 0;
}
static int super_init_validation(struct mddev *mddev, struct md_rdev *rdev)
{
int role;
struct raid_set *rs = container_of(mddev, struct raid_set, md);
uint64_t events_sb;
uint64_t failed_devices;
struct dm_raid_superblock *sb;
uint32_t new_devs = 0;
uint32_t rebuilds = 0;
struct md_rdev *r;
struct dm_raid_superblock *sb2;
sb = page_address(rdev->sb_page);
events_sb = le64_to_cpu(sb->events);
failed_devices = le64_to_cpu(sb->failed_devices);
mddev->events = events_sb ? : 1;
if ((le32_to_cpu(sb->level) != mddev->level) ||
(le32_to_cpu(sb->layout) != mddev->layout) ||
(le32_to_cpu(sb->stripe_sectors) != mddev->chunk_sectors)) {
DMERR("Reshaping arrays not yet supported.");
return -EINVAL;
}
if ((rs->raid_type->level != 1) &&
(le32_to_cpu(sb->num_devices) != mddev->raid_disks)) {
DMERR("Reshaping arrays not yet supported.");
return -EINVAL;
}
if (!(rs->print_flags & (DMPF_SYNC | DMPF_NOSYNC)))
mddev->recovery_cp = le64_to_cpu(sb->array_resync_offset);
rdev_for_each(r, mddev) {
if (!test_bit(In_sync, &r->flags)) {
DMINFO("Device %d specified for rebuild: "
"Clearing superblock", r->raid_disk);
rebuilds++;
} else if (test_bit(FirstUse, &r->flags))
new_devs++;
}
if (!rebuilds) {
if (new_devs == mddev->raid_disks) {
DMINFO("Superblocks created for new array");
set_bit(MD_ARRAY_FIRST_USE, &mddev->flags);
} else if (new_devs) {
DMERR("New device injected "
"into existing array without 'rebuild' "
"parameter specified");
return -EINVAL;
}
} else if (new_devs) {
DMERR("'rebuild' devices cannot be "
"injected into an array with other first-time devices");
return -EINVAL;
} else if (mddev->recovery_cp != MaxSector) {
DMERR("'rebuild' specified while array is not in-sync");
return -EINVAL;
}
rdev_for_each(r, mddev) {
if (!r->sb_page)
continue;
sb2 = page_address(r->sb_page);
sb2->failed_devices = 0;
if (!test_bit(FirstUse, &r->flags) && (r->raid_disk >= 0)) {
role = le32_to_cpu(sb2->array_position);
if (role != r->raid_disk) {
if (rs->raid_type->level != 1) {
rs->ti->error = "Cannot change device "
"positions in RAID array";
return -EINVAL;
}
DMINFO("RAID1 device #%d now at position #%d",
role, r->raid_disk);
}
if (failed_devices & (1 << role))
set_bit(Faulty, &r->flags);
}
}
return 0;
}
static int super_validate(struct mddev *mddev, struct md_rdev *rdev)
{
struct dm_raid_superblock *sb = page_address(rdev->sb_page);
if (!mddev->events && super_init_validation(mddev, rdev))
return -EINVAL;
mddev->bitmap_info.offset = 4096 >> 9;
rdev->mddev->bitmap_info.default_offset = 4096 >> 9;
if (!test_bit(FirstUse, &rdev->flags)) {
rdev->recovery_offset = le64_to_cpu(sb->disk_recovery_offset);
if (rdev->recovery_offset != MaxSector)
clear_bit(In_sync, &rdev->flags);
}
if (test_bit(Faulty, &rdev->flags)) {
clear_bit(Faulty, &rdev->flags);
clear_bit(In_sync, &rdev->flags);
rdev->saved_raid_disk = rdev->raid_disk;
rdev->recovery_offset = 0;
}
clear_bit(FirstUse, &rdev->flags);
return 0;
}
static int analyse_superblocks(struct dm_target *ti, struct raid_set *rs)
{
int ret;
struct raid_dev *dev;
struct md_rdev *rdev, *tmp, *freshest;
struct mddev *mddev = &rs->md;
freshest = NULL;
rdev_for_each_safe(rdev, tmp, mddev) {
if (rs->print_flags & DMPF_SYNC)
continue;
if (!rdev->meta_bdev)
continue;
ret = super_load(rdev, freshest);
switch (ret) {
case 1:
freshest = rdev;
break;
case 0:
break;
default:
dev = container_of(rdev, struct raid_dev, rdev);
if (dev->meta_dev)
dm_put_device(ti, dev->meta_dev);
dev->meta_dev = NULL;
rdev->meta_bdev = NULL;
if (rdev->sb_page)
put_page(rdev->sb_page);
rdev->sb_page = NULL;
rdev->sb_loaded = 0;
if (dev->data_dev)
dm_put_device(ti, dev->data_dev);
dev->data_dev = NULL;
rdev->bdev = NULL;
list_del(&rdev->same_set);
}
}
if (!freshest)
return 0;
if (validate_raid_redundancy(rs)) {
rs->ti->error = "Insufficient redundancy to activate array";
return -EINVAL;
}
ti->error = "Unable to assemble array: Invalid superblocks";
if (super_validate(mddev, freshest))
return -EINVAL;
rdev_for_each(rdev, mddev)
if ((rdev != freshest) && super_validate(mddev, rdev))
return -EINVAL;
return 0;
}
static int raid_ctr(struct dm_target *ti, unsigned argc, char **argv)
{
int ret;
struct raid_type *rt;
unsigned long num_raid_params, num_raid_devs;
struct raid_set *rs = NULL;
if (argc < 2) {
ti->error = "Too few arguments";
return -EINVAL;
}
rt = get_raid_type(argv[0]);
if (!rt) {
ti->error = "Unrecognised raid_type";
return -EINVAL;
}
argc--;
argv++;
if (strict_strtoul(argv[0], 10, &num_raid_params) < 0) {
ti->error = "Cannot understand number of RAID parameters";
return -EINVAL;
}
argc--;
argv++;
if (num_raid_params + 1 > argc) {
ti->error = "Arguments do not agree with counts given";
return -EINVAL;
}
if ((strict_strtoul(argv[num_raid_params], 10, &num_raid_devs) < 0) ||
(num_raid_devs >= INT_MAX)) {
ti->error = "Cannot understand number of raid devices";
return -EINVAL;
}
rs = context_alloc(ti, rt, (unsigned)num_raid_devs);
if (IS_ERR(rs))
return PTR_ERR(rs);
ret = parse_raid_params(rs, argv, (unsigned)num_raid_params);
if (ret)
goto bad;
ret = -EINVAL;
argc -= num_raid_params + 1;
argv += num_raid_params + 1;
if (argc != (num_raid_devs * 2)) {
ti->error = "Supplied RAID devices does not match the count given";
goto bad;
}
ret = dev_parms(rs, argv);
if (ret)
goto bad;
rs->md.sync_super = super_sync;
ret = analyse_superblocks(ti, rs);
if (ret)
goto bad;
INIT_WORK(&rs->md.event_work, do_table_event);
ti->private = rs;
ti->num_flush_requests = 1;
mutex_lock(&rs->md.reconfig_mutex);
ret = md_run(&rs->md);
rs->md.in_sync = 0;
mutex_unlock(&rs->md.reconfig_mutex);
if (ret) {
ti->error = "Fail to run raid array";
goto bad;
}
if (ti->len != rs->md.array_sectors) {
ti->error = "Array size does not match requested target length";
ret = -EINVAL;
goto size_mismatch;
}
rs->callbacks.congested_fn = raid_is_congested;
dm_table_add_target_callbacks(ti->table, &rs->callbacks);
mddev_suspend(&rs->md);
return 0;
size_mismatch:
md_stop(&rs->md);
bad:
context_free(rs);
return ret;
}
static void raid_dtr(struct dm_target *ti)
{
struct raid_set *rs = ti->private;
list_del_init(&rs->callbacks.list);
md_stop(&rs->md);
context_free(rs);
}
static int raid_map(struct dm_target *ti, struct bio *bio)
{
struct raid_set *rs = ti->private;
struct mddev *mddev = &rs->md;
mddev->pers->make_request(mddev, bio);
return DM_MAPIO_SUBMITTED;
}
static int raid_status(struct dm_target *ti, status_type_t type,
unsigned status_flags, char *result, unsigned maxlen)
{
struct raid_set *rs = ti->private;
unsigned raid_param_cnt = 1;
unsigned sz = 0;
int i, array_in_sync = 0;
sector_t sync;
switch (type) {
case STATUSTYPE_INFO:
DMEMIT("%s %d ", rs->raid_type->name, rs->md.raid_disks);
if (test_bit(MD_RECOVERY_RUNNING, &rs->md.recovery))
sync = rs->md.curr_resync_completed;
else
sync = rs->md.recovery_cp;
if (sync >= rs->md.resync_max_sectors) {
array_in_sync = 1;
sync = rs->md.resync_max_sectors;
} else {
for (i = 0; i < rs->md.raid_disks; i++)
if (!test_bit(In_sync, &rs->dev[i].rdev.flags))
array_in_sync = 1;
}
for (i = 0; i < rs->md.raid_disks; i++) {
if (test_bit(Faulty, &rs->dev[i].rdev.flags))
DMEMIT("D");
else if (!array_in_sync ||
!test_bit(In_sync, &rs->dev[i].rdev.flags))
DMEMIT("a");
else
DMEMIT("A");
}
DMEMIT(" %llu/%llu",
(unsigned long long) sync,
(unsigned long long) rs->md.resync_max_sectors);
break;
case STATUSTYPE_TABLE:
for (i = 0; i < rs->md.raid_disks; i++) {
if ((rs->print_flags & DMPF_REBUILD) &&
rs->dev[i].data_dev &&
!test_bit(In_sync, &rs->dev[i].rdev.flags))
raid_param_cnt += 2;
if (rs->dev[i].data_dev &&
test_bit(WriteMostly, &rs->dev[i].rdev.flags))
raid_param_cnt += 2;
}
raid_param_cnt += (hweight32(rs->print_flags & ~DMPF_REBUILD) * 2);
if (rs->print_flags & (DMPF_SYNC | DMPF_NOSYNC))
raid_param_cnt--;
DMEMIT("%s %u %u", rs->raid_type->name,
raid_param_cnt, rs->md.chunk_sectors);
if ((rs->print_flags & DMPF_SYNC) &&
(rs->md.recovery_cp == MaxSector))
DMEMIT(" sync");
if (rs->print_flags & DMPF_NOSYNC)
DMEMIT(" nosync");
for (i = 0; i < rs->md.raid_disks; i++)
if ((rs->print_flags & DMPF_REBUILD) &&
rs->dev[i].data_dev &&
!test_bit(In_sync, &rs->dev[i].rdev.flags))
DMEMIT(" rebuild %u", i);
if (rs->print_flags & DMPF_DAEMON_SLEEP)
DMEMIT(" daemon_sleep %lu",
rs->md.bitmap_info.daemon_sleep);
if (rs->print_flags & DMPF_MIN_RECOVERY_RATE)
DMEMIT(" min_recovery_rate %d", rs->md.sync_speed_min);
if (rs->print_flags & DMPF_MAX_RECOVERY_RATE)
DMEMIT(" max_recovery_rate %d", rs->md.sync_speed_max);
for (i = 0; i < rs->md.raid_disks; i++)
if (rs->dev[i].data_dev &&
test_bit(WriteMostly, &rs->dev[i].rdev.flags))
DMEMIT(" write_mostly %u", i);
if (rs->print_flags & DMPF_MAX_WRITE_BEHIND)
DMEMIT(" max_write_behind %lu",
rs->md.bitmap_info.max_write_behind);
if (rs->print_flags & DMPF_STRIPE_CACHE) {
struct r5conf *conf = rs->md.private;
DMEMIT(" stripe_cache %d",
conf ? conf->max_nr_stripes * 2 : 0);
}
if (rs->print_flags & DMPF_REGION_SIZE)
DMEMIT(" region_size %lu",
rs->md.bitmap_info.chunksize >> 9);
if (rs->print_flags & DMPF_RAID10_COPIES)
DMEMIT(" raid10_copies %u",
raid10_md_layout_to_copies(rs->md.layout));
if (rs->print_flags & DMPF_RAID10_FORMAT)
DMEMIT(" raid10_format near");
DMEMIT(" %d", rs->md.raid_disks);
for (i = 0; i < rs->md.raid_disks; i++) {
if (rs->dev[i].meta_dev)
DMEMIT(" %s", rs->dev[i].meta_dev->name);
else
DMEMIT(" -");
if (rs->dev[i].data_dev)
DMEMIT(" %s", rs->dev[i].data_dev->name);
else
DMEMIT(" -");
}
}
return 0;
}
static int raid_iterate_devices(struct dm_target *ti, iterate_devices_callout_fn fn, void *data)
{
struct raid_set *rs = ti->private;
unsigned i;
int ret = 0;
for (i = 0; !ret && i < rs->md.raid_disks; i++)
if (rs->dev[i].data_dev)
ret = fn(ti,
rs->dev[i].data_dev,
0,
rs->md.dev_sectors,
data);
return ret;
}
static void raid_io_hints(struct dm_target *ti, struct queue_limits *limits)
{
struct raid_set *rs = ti->private;
unsigned chunk_size = rs->md.chunk_sectors << 9;
struct r5conf *conf = rs->md.private;
blk_limits_io_min(limits, chunk_size);
blk_limits_io_opt(limits, chunk_size * (conf->raid_disks - conf->max_degraded));
}
static void raid_presuspend(struct dm_target *ti)
{
struct raid_set *rs = ti->private;
md_stop_writes(&rs->md);
}
static void raid_postsuspend(struct dm_target *ti)
{
struct raid_set *rs = ti->private;
mddev_suspend(&rs->md);
}
static void raid_resume(struct dm_target *ti)
{
struct raid_set *rs = ti->private;
set_bit(MD_CHANGE_DEVS, &rs->md.flags);
if (!rs->bitmap_loaded) {
bitmap_load(&rs->md);
rs->bitmap_loaded = 1;
}
clear_bit(MD_RECOVERY_FROZEN, &rs->md.recovery);
mddev_resume(&rs->md);
}
static int __init dm_raid_init(void)
{
return dm_register_target(&raid_target);
}
static void __exit dm_raid_exit(void)
{
dm_unregister_target(&raid_target);
}
