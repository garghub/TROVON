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
sector_t sectors_per_dev;
if (raid_devs <= raid_type->parity_devs) {
ti->error = "Insufficient number of devices";
return ERR_PTR(-EINVAL);
}
sectors_per_dev = ti->len;
if (sector_div(sectors_per_dev, (raid_devs - raid_type->parity_devs))) {
ti->error = "Target length not divisible by number of data devices";
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
rs->md.dev_sectors = sectors_per_dev;
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
for (i = 0; i < rs->md.raid_disks; i++)
if (rs->dev[i].data_dev)
dm_put_device(rs->ti, rs->dev[i].data_dev);
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
rs->ti->error = "Metadata devices not supported";
return -EINVAL;
}
if (!strcmp(argv[1], "-")) {
if (!test_bit(In_sync, &rs->dev[i].rdev.flags) &&
(!rs->dev[i].rdev.recovery_offset)) {
rs->ti->error = "Drive designated for rebuild not specified";
return -EINVAL;
}
continue;
}
ret = dm_get_device(rs->ti, argv[1],
dm_table_get_mode(rs->ti->table),
&rs->dev[i].data_dev);
if (ret) {
rs->ti->error = "RAID device lookup failure";
return ret;
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
static int parse_raid_params(struct raid_set *rs, char **argv,
unsigned num_raid_params)
{
unsigned i, rebuild_cnt = 0;
unsigned long value;
char *key;
if ((strict_strtoul(argv[0], 10, &value) < 0) ||
!is_power_of_2(value) || (value < 8)) {
rs->ti->error = "Bad chunk size";
return -EINVAL;
}
rs->md.new_chunk_sectors = rs->md.chunk_sectors = value;
argv++;
num_raid_params--;
for (i = 0; i < rs->md.raid_disks; i++)
set_bit(In_sync, &rs->dev[i].rdev.flags);
for (i = 0; i < num_raid_params; i++) {
if (!strcmp(argv[i], "nosync")) {
rs->md.recovery_cp = MaxSector;
rs->print_flags |= DMPF_NOSYNC;
rs->md.flags |= MD_SYNC_STATE_FORCED;
continue;
}
if (!strcmp(argv[i], "sync")) {
rs->md.recovery_cp = 0;
rs->print_flags |= DMPF_SYNC;
rs->md.flags |= MD_SYNC_STATE_FORCED;
continue;
}
if ((i + 1) >= num_raid_params) {
rs->ti->error = "Wrong number of raid parameters given";
return -EINVAL;
}
key = argv[i++];
if (strict_strtoul(argv[i], 10, &value) < 0) {
rs->ti->error = "Bad numerical argument given in raid params";
return -EINVAL;
}
if (!strcmp(key, "rebuild")) {
if (++rebuild_cnt > rs->raid_type->parity_devs) {
rs->ti->error = "Too many rebuild drives given";
return -EINVAL;
}
if (value > rs->md.raid_disks) {
rs->ti->error = "Invalid rebuild index given";
return -EINVAL;
}
clear_bit(In_sync, &rs->dev[value].rdev.flags);
rs->dev[value].rdev.recovery_offset = 0;
} else if (!strcmp(key, "max_write_behind")) {
rs->print_flags |= DMPF_MAX_WRITE_BEHIND;
value /= 2;
if (value > COUNTER_MAX) {
rs->ti->error = "Max write-behind limit out of range";
return -EINVAL;
}
rs->md.bitmap_info.max_write_behind = value;
} else if (!strcmp(key, "daemon_sleep")) {
rs->print_flags |= DMPF_DAEMON_SLEEP;
if (!value || (value > MAX_SCHEDULE_TIMEOUT)) {
rs->ti->error = "daemon sleep period out of range";
return -EINVAL;
}
rs->md.bitmap_info.daemon_sleep = value;
} else if (!strcmp(key, "stripe_cache")) {
rs->print_flags |= DMPF_STRIPE_CACHE;
value /= 2;
if (rs->raid_type->level < 5) {
rs->ti->error = "Inappropriate argument: stripe_cache";
return -EINVAL;
}
if (raid5_set_cache_size(&rs->md, (int)value)) {
rs->ti->error = "Bad stripe_cache size";
return -EINVAL;
}
} else if (!strcmp(key, "min_recovery_rate")) {
rs->print_flags |= DMPF_MIN_RECOVERY_RATE;
if (value > INT_MAX) {
rs->ti->error = "min_recovery_rate out of range";
return -EINVAL;
}
rs->md.sync_speed_min = (int)value;
} else if (!strcmp(key, "max_recovery_rate")) {
rs->print_flags |= DMPF_MAX_RECOVERY_RATE;
if (value > INT_MAX) {
rs->ti->error = "max_recovery_rate out of range";
return -EINVAL;
}
rs->md.sync_speed_max = (int)value;
} else {
DMERR("Unable to parse RAID parameter: %s", key);
rs->ti->error = "Unable to parse RAID parameters";
return -EINVAL;
}
}
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
return md_raid5_congested(&rs->md, bits);
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
INIT_WORK(&rs->md.event_work, do_table_event);
ti->split_io = rs->md.chunk_sectors;
ti->private = rs;
mutex_lock(&rs->md.reconfig_mutex);
ret = md_run(&rs->md);
rs->md.in_sync = 0;
mutex_unlock(&rs->md.reconfig_mutex);
if (ret) {
ti->error = "Fail to run raid array";
goto bad;
}
rs->callbacks.congested_fn = raid_is_congested;
dm_table_add_target_callbacks(ti->table, &rs->callbacks);
return 0;
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
static int raid_map(struct dm_target *ti, struct bio *bio, union map_info *map_context)
{
struct raid_set *rs = ti->private;
mddev_t *mddev = &rs->md;
mddev->pers->make_request(mddev, bio);
return DM_MAPIO_SUBMITTED;
}
static int raid_status(struct dm_target *ti, status_type_t type,
char *result, unsigned maxlen)
{
struct raid_set *rs = ti->private;
unsigned raid_param_cnt = 1;
unsigned sz = 0;
int i;
sector_t sync;
switch (type) {
case STATUSTYPE_INFO:
DMEMIT("%s %d ", rs->raid_type->name, rs->md.raid_disks);
for (i = 0; i < rs->md.raid_disks; i++) {
if (test_bit(Faulty, &rs->dev[i].rdev.flags))
DMEMIT("D");
else if (test_bit(In_sync, &rs->dev[i].rdev.flags))
DMEMIT("A");
else
DMEMIT("a");
}
if (test_bit(MD_RECOVERY_RUNNING, &rs->md.recovery))
sync = rs->md.curr_resync_completed;
else
sync = rs->md.recovery_cp;
if (sync > rs->md.resync_max_sectors)
sync = rs->md.resync_max_sectors;
DMEMIT(" %llu/%llu",
(unsigned long long) sync,
(unsigned long long) rs->md.resync_max_sectors);
break;
case STATUSTYPE_TABLE:
for (i = 0; i < rs->md.raid_disks; i++)
if (rs->dev[i].data_dev &&
!test_bit(In_sync, &rs->dev[i].rdev.flags))
raid_param_cnt++;
raid_param_cnt += (hweight64(rs->print_flags) * 2);
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
if (rs->dev[i].data_dev &&
!test_bit(In_sync, &rs->dev[i].rdev.flags))
DMEMIT(" rebuild %u", i);
if (rs->print_flags & DMPF_DAEMON_SLEEP)
DMEMIT(" daemon_sleep %lu",
rs->md.bitmap_info.daemon_sleep);
if (rs->print_flags & DMPF_MIN_RECOVERY_RATE)
DMEMIT(" min_recovery_rate %d", rs->md.sync_speed_min);
if (rs->print_flags & DMPF_MAX_RECOVERY_RATE)
DMEMIT(" max_recovery_rate %d", rs->md.sync_speed_max);
if (rs->print_flags & DMPF_MAX_WRITE_BEHIND)
DMEMIT(" max_write_behind %lu",
rs->md.bitmap_info.max_write_behind);
if (rs->print_flags & DMPF_STRIPE_CACHE) {
raid5_conf_t *conf = rs->md.private;
DMEMIT(" stripe_cache %d",
conf ? conf->max_nr_stripes * 2 : 0);
}
DMEMIT(" %d", rs->md.raid_disks);
for (i = 0; i < rs->md.raid_disks; i++) {
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
raid5_conf_t *conf = rs->md.private;
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
