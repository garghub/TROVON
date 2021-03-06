static int __readahead_hook(struct btrfs_root *root, struct extent_buffer *eb,
u64 start, int err)
{
int level = 0;
int nritems;
int i;
u64 bytenr;
u64 generation;
struct reada_extent *re;
struct btrfs_fs_info *fs_info = root->fs_info;
struct list_head list;
unsigned long index = start >> PAGE_CACHE_SHIFT;
struct btrfs_device *for_dev;
if (eb)
level = btrfs_header_level(eb);
spin_lock(&fs_info->reada_lock);
re = radix_tree_lookup(&fs_info->reada_tree, index);
if (re)
kref_get(&re->refcnt);
spin_unlock(&fs_info->reada_lock);
if (!re)
return -1;
spin_lock(&re->lock);
list_replace_init(&re->extctl, &list);
for_dev = re->scheduled_for;
re->scheduled_for = NULL;
spin_unlock(&re->lock);
if (err == 0) {
nritems = level ? btrfs_header_nritems(eb) : 0;
generation = btrfs_header_generation(eb);
} else {
nritems = 0;
generation = 0;
}
for (i = 0; i < nritems; i++) {
struct reada_extctl *rec;
u64 n_gen;
struct btrfs_key key;
struct btrfs_key next_key;
btrfs_node_key_to_cpu(eb, &key, i);
if (i + 1 < nritems)
btrfs_node_key_to_cpu(eb, &next_key, i + 1);
else
next_key = re->top;
bytenr = btrfs_node_blockptr(eb, i);
n_gen = btrfs_node_ptr_generation(eb, i);
list_for_each_entry(rec, &list, list) {
struct reada_control *rc = rec->rc;
#ifdef DEBUG
if (rec->generation != generation) {
printk(KERN_DEBUG "generation mismatch for "
"(%llu,%d,%llu) %llu != %llu\n",
key.objectid, key.type, key.offset,
rec->generation, generation);
}
#endif
if (rec->generation == generation &&
btrfs_comp_cpu_keys(&key, &rc->key_end) < 0 &&
btrfs_comp_cpu_keys(&next_key, &rc->key_start) > 0)
reada_add_block(rc, bytenr, &next_key,
level - 1, n_gen);
}
}
while (!list_empty(&list)) {
struct reada_control *rc;
struct reada_extctl *rec;
rec = list_first_entry(&list, struct reada_extctl, list);
list_del(&rec->list);
rc = rec->rc;
kfree(rec);
kref_get(&rc->refcnt);
if (atomic_dec_and_test(&rc->elems)) {
kref_put(&rc->refcnt, reada_control_release);
wake_up(&rc->wait);
}
kref_put(&rc->refcnt, reada_control_release);
reada_extent_put(fs_info, re);
}
reada_extent_put(fs_info, re);
if (for_dev)
atomic_dec(&for_dev->reada_in_flight);
return 0;
}
int btree_readahead_hook(struct btrfs_root *root, struct extent_buffer *eb,
u64 start, int err)
{
int ret;
ret = __readahead_hook(root, eb, start, err);
reada_start_machine(root->fs_info);
return ret;
}
static struct reada_zone *reada_find_zone(struct btrfs_fs_info *fs_info,
struct btrfs_device *dev, u64 logical,
struct btrfs_bio *bbio)
{
int ret;
int looped = 0;
struct reada_zone *zone;
struct btrfs_block_group_cache *cache = NULL;
u64 start;
u64 end;
int i;
again:
zone = NULL;
spin_lock(&fs_info->reada_lock);
ret = radix_tree_gang_lookup(&dev->reada_zones, (void **)&zone,
logical >> PAGE_CACHE_SHIFT, 1);
if (ret == 1)
kref_get(&zone->refcnt);
spin_unlock(&fs_info->reada_lock);
if (ret == 1) {
if (logical >= zone->start && logical < zone->end)
return zone;
spin_lock(&fs_info->reada_lock);
kref_put(&zone->refcnt, reada_zone_release);
spin_unlock(&fs_info->reada_lock);
}
if (looped)
return NULL;
cache = btrfs_lookup_block_group(fs_info, logical);
if (!cache)
return NULL;
start = cache->key.objectid;
end = start + cache->key.offset - 1;
btrfs_put_block_group(cache);
zone = kzalloc(sizeof(*zone), GFP_NOFS);
if (!zone)
return NULL;
zone->start = start;
zone->end = end;
INIT_LIST_HEAD(&zone->list);
spin_lock_init(&zone->lock);
zone->locked = 0;
kref_init(&zone->refcnt);
zone->elems = 0;
zone->device = dev;
for (i = 0; i < bbio->num_stripes; ++i) {
zone->devs[i] = bbio->stripes[i].dev;
}
zone->ndevs = bbio->num_stripes;
spin_lock(&fs_info->reada_lock);
ret = radix_tree_insert(&dev->reada_zones,
(unsigned long)(zone->end >> PAGE_CACHE_SHIFT),
zone);
spin_unlock(&fs_info->reada_lock);
if (ret) {
kfree(zone);
looped = 1;
goto again;
}
return zone;
}
static struct reada_extent *reada_find_extent(struct btrfs_root *root,
u64 logical,
struct btrfs_key *top, int level)
{
int ret;
int looped = 0;
struct reada_extent *re = NULL;
struct btrfs_fs_info *fs_info = root->fs_info;
struct btrfs_mapping_tree *map_tree = &fs_info->mapping_tree;
struct btrfs_bio *bbio = NULL;
struct btrfs_device *dev;
u32 blocksize;
u64 length;
int nzones = 0;
int i;
unsigned long index = logical >> PAGE_CACHE_SHIFT;
again:
spin_lock(&fs_info->reada_lock);
re = radix_tree_lookup(&fs_info->reada_tree, index);
if (re)
kref_get(&re->refcnt);
spin_unlock(&fs_info->reada_lock);
if (re || looped)
return re;
re = kzalloc(sizeof(*re), GFP_NOFS);
if (!re)
return NULL;
blocksize = btrfs_level_size(root, level);
re->logical = logical;
re->blocksize = blocksize;
re->top = *top;
INIT_LIST_HEAD(&re->extctl);
spin_lock_init(&re->lock);
kref_init(&re->refcnt);
length = blocksize;
ret = btrfs_map_block(map_tree, REQ_WRITE, logical, &length, &bbio, 0);
if (ret || !bbio || length < blocksize)
goto error;
if (bbio->num_stripes > MAX_MIRRORS) {
printk(KERN_ERR "btrfs readahead: more than %d copies not "
"supported", MAX_MIRRORS);
goto error;
}
for (nzones = 0; nzones < bbio->num_stripes; ++nzones) {
struct reada_zone *zone;
dev = bbio->stripes[nzones].dev;
zone = reada_find_zone(fs_info, dev, logical, bbio);
if (!zone)
break;
re->zones[nzones] = zone;
spin_lock(&zone->lock);
if (!zone->elems)
kref_get(&zone->refcnt);
++zone->elems;
spin_unlock(&zone->lock);
spin_lock(&fs_info->reada_lock);
kref_put(&zone->refcnt, reada_zone_release);
spin_unlock(&fs_info->reada_lock);
}
re->nzones = nzones;
if (nzones == 0) {
goto error;
}
spin_lock(&fs_info->reada_lock);
ret = radix_tree_insert(&fs_info->reada_tree, index, re);
if (ret) {
spin_unlock(&fs_info->reada_lock);
if (ret != -ENOMEM) {
looped = 1;
}
goto error;
}
for (i = 0; i < nzones; ++i) {
dev = bbio->stripes[i].dev;
ret = radix_tree_insert(&dev->reada_extents, index, re);
if (ret) {
while (--i >= 0) {
dev = bbio->stripes[i].dev;
BUG_ON(dev == NULL);
radix_tree_delete(&dev->reada_extents, index);
}
BUG_ON(fs_info == NULL);
radix_tree_delete(&fs_info->reada_tree, index);
spin_unlock(&fs_info->reada_lock);
goto error;
}
}
spin_unlock(&fs_info->reada_lock);
kfree(bbio);
return re;
error:
while (nzones) {
struct reada_zone *zone;
--nzones;
zone = re->zones[nzones];
kref_get(&zone->refcnt);
spin_lock(&zone->lock);
--zone->elems;
if (zone->elems == 0) {
kref_put(&zone->refcnt, reada_zone_release);
}
spin_unlock(&zone->lock);
spin_lock(&fs_info->reada_lock);
kref_put(&zone->refcnt, reada_zone_release);
spin_unlock(&fs_info->reada_lock);
}
kfree(bbio);
kfree(re);
if (looped)
goto again;
return NULL;
}
static void reada_kref_dummy(struct kref *kr)
{
}
static void reada_extent_put(struct btrfs_fs_info *fs_info,
struct reada_extent *re)
{
int i;
unsigned long index = re->logical >> PAGE_CACHE_SHIFT;
spin_lock(&fs_info->reada_lock);
if (!kref_put(&re->refcnt, reada_kref_dummy)) {
spin_unlock(&fs_info->reada_lock);
return;
}
radix_tree_delete(&fs_info->reada_tree, index);
for (i = 0; i < re->nzones; ++i) {
struct reada_zone *zone = re->zones[i];
radix_tree_delete(&zone->device->reada_extents, index);
}
spin_unlock(&fs_info->reada_lock);
for (i = 0; i < re->nzones; ++i) {
struct reada_zone *zone = re->zones[i];
kref_get(&zone->refcnt);
spin_lock(&zone->lock);
--zone->elems;
if (zone->elems == 0) {
kref_put(&zone->refcnt, reada_zone_release);
}
spin_unlock(&zone->lock);
spin_lock(&fs_info->reada_lock);
kref_put(&zone->refcnt, reada_zone_release);
spin_unlock(&fs_info->reada_lock);
}
if (re->scheduled_for)
atomic_dec(&re->scheduled_for->reada_in_flight);
kfree(re);
}
static void reada_zone_release(struct kref *kref)
{
struct reada_zone *zone = container_of(kref, struct reada_zone, refcnt);
radix_tree_delete(&zone->device->reada_zones,
zone->end >> PAGE_CACHE_SHIFT);
kfree(zone);
}
static void reada_control_release(struct kref *kref)
{
struct reada_control *rc = container_of(kref, struct reada_control,
refcnt);
kfree(rc);
}
static int reada_add_block(struct reada_control *rc, u64 logical,
struct btrfs_key *top, int level, u64 generation)
{
struct btrfs_root *root = rc->root;
struct reada_extent *re;
struct reada_extctl *rec;
re = reada_find_extent(root, logical, top, level);
if (!re)
return -1;
rec = kzalloc(sizeof(*rec), GFP_NOFS);
if (!rec) {
reada_extent_put(root->fs_info, re);
return -1;
}
rec->rc = rc;
rec->generation = generation;
atomic_inc(&rc->elems);
spin_lock(&re->lock);
list_add_tail(&rec->list, &re->extctl);
spin_unlock(&re->lock);
return 0;
}
static void reada_peer_zones_set_lock(struct reada_zone *zone, int lock)
{
int i;
unsigned long index = zone->end >> PAGE_CACHE_SHIFT;
for (i = 0; i < zone->ndevs; ++i) {
struct reada_zone *peer;
peer = radix_tree_lookup(&zone->devs[i]->reada_zones, index);
if (peer && peer->device != zone->device)
peer->locked = lock;
}
}
static int reada_pick_zone(struct btrfs_device *dev)
{
struct reada_zone *top_zone = NULL;
struct reada_zone *top_locked_zone = NULL;
u64 top_elems = 0;
u64 top_locked_elems = 0;
unsigned long index = 0;
int ret;
if (dev->reada_curr_zone) {
reada_peer_zones_set_lock(dev->reada_curr_zone, 0);
kref_put(&dev->reada_curr_zone->refcnt, reada_zone_release);
dev->reada_curr_zone = NULL;
}
while (1) {
struct reada_zone *zone;
ret = radix_tree_gang_lookup(&dev->reada_zones,
(void **)&zone, index, 1);
if (ret == 0)
break;
index = (zone->end >> PAGE_CACHE_SHIFT) + 1;
if (zone->locked) {
if (zone->elems > top_locked_elems) {
top_locked_elems = zone->elems;
top_locked_zone = zone;
}
} else {
if (zone->elems > top_elems) {
top_elems = zone->elems;
top_zone = zone;
}
}
}
if (top_zone)
dev->reada_curr_zone = top_zone;
else if (top_locked_zone)
dev->reada_curr_zone = top_locked_zone;
else
return 0;
dev->reada_next = dev->reada_curr_zone->start;
kref_get(&dev->reada_curr_zone->refcnt);
reada_peer_zones_set_lock(dev->reada_curr_zone, 1);
return 1;
}
static int reada_start_machine_dev(struct btrfs_fs_info *fs_info,
struct btrfs_device *dev)
{
struct reada_extent *re = NULL;
int mirror_num = 0;
struct extent_buffer *eb = NULL;
u64 logical;
u32 blocksize;
int ret;
int i;
int need_kick = 0;
spin_lock(&fs_info->reada_lock);
if (dev->reada_curr_zone == NULL) {
ret = reada_pick_zone(dev);
if (!ret) {
spin_unlock(&fs_info->reada_lock);
return 0;
}
}
ret = radix_tree_gang_lookup(&dev->reada_extents, (void **)&re,
dev->reada_next >> PAGE_CACHE_SHIFT, 1);
if (ret == 0 || re->logical >= dev->reada_curr_zone->end) {
ret = reada_pick_zone(dev);
if (!ret) {
spin_unlock(&fs_info->reada_lock);
return 0;
}
re = NULL;
ret = radix_tree_gang_lookup(&dev->reada_extents, (void **)&re,
dev->reada_next >> PAGE_CACHE_SHIFT, 1);
}
if (ret == 0) {
spin_unlock(&fs_info->reada_lock);
return 0;
}
dev->reada_next = re->logical + re->blocksize;
kref_get(&re->refcnt);
spin_unlock(&fs_info->reada_lock);
for (i = 0; i < re->nzones; ++i) {
if (re->zones[i]->device == dev) {
mirror_num = i + 1;
break;
}
}
logical = re->logical;
blocksize = re->blocksize;
spin_lock(&re->lock);
if (re->scheduled_for == NULL) {
re->scheduled_for = dev;
need_kick = 1;
}
spin_unlock(&re->lock);
reada_extent_put(fs_info, re);
if (!need_kick)
return 0;
atomic_inc(&dev->reada_in_flight);
ret = reada_tree_block_flagged(fs_info->extent_root, logical, blocksize,
mirror_num, &eb);
if (ret)
__readahead_hook(fs_info->extent_root, NULL, logical, ret);
else if (eb)
__readahead_hook(fs_info->extent_root, eb, eb->start, ret);
if (eb)
free_extent_buffer(eb);
return 1;
}
static void reada_start_machine_worker(struct btrfs_work *work)
{
struct reada_machine_work *rmw;
struct btrfs_fs_info *fs_info;
rmw = container_of(work, struct reada_machine_work, work);
fs_info = rmw->fs_info;
kfree(rmw);
__reada_start_machine(fs_info);
}
static void __reada_start_machine(struct btrfs_fs_info *fs_info)
{
struct btrfs_device *device;
struct btrfs_fs_devices *fs_devices = fs_info->fs_devices;
u64 enqueued;
u64 total = 0;
int i;
do {
enqueued = 0;
list_for_each_entry(device, &fs_devices->devices, dev_list) {
if (atomic_read(&device->reada_in_flight) <
MAX_IN_FLIGHT)
enqueued += reada_start_machine_dev(fs_info,
device);
}
total += enqueued;
} while (enqueued && total < 10000);
if (enqueued == 0)
return;
for (i = 0; i < 2; ++i)
reada_start_machine(fs_info);
}
static void reada_start_machine(struct btrfs_fs_info *fs_info)
{
struct reada_machine_work *rmw;
rmw = kzalloc(sizeof(*rmw), GFP_NOFS);
if (!rmw) {
BUG();
}
rmw->work.func = reada_start_machine_worker;
rmw->fs_info = fs_info;
btrfs_queue_worker(&fs_info->readahead_workers, &rmw->work);
}
static void dump_devs(struct btrfs_fs_info *fs_info, int all)
{
struct btrfs_device *device;
struct btrfs_fs_devices *fs_devices = fs_info->fs_devices;
unsigned long index;
int ret;
int i;
int j;
int cnt;
spin_lock(&fs_info->reada_lock);
list_for_each_entry(device, &fs_devices->devices, dev_list) {
printk(KERN_DEBUG "dev %lld has %d in flight\n", device->devid,
atomic_read(&device->reada_in_flight));
index = 0;
while (1) {
struct reada_zone *zone;
ret = radix_tree_gang_lookup(&device->reada_zones,
(void **)&zone, index, 1);
if (ret == 0)
break;
printk(KERN_DEBUG " zone %llu-%llu elems %llu locked "
"%d devs", zone->start, zone->end, zone->elems,
zone->locked);
for (j = 0; j < zone->ndevs; ++j) {
printk(KERN_CONT " %lld",
zone->devs[j]->devid);
}
if (device->reada_curr_zone == zone)
printk(KERN_CONT " curr off %llu",
device->reada_next - zone->start);
printk(KERN_CONT "\n");
index = (zone->end >> PAGE_CACHE_SHIFT) + 1;
}
cnt = 0;
index = 0;
while (all) {
struct reada_extent *re = NULL;
ret = radix_tree_gang_lookup(&device->reada_extents,
(void **)&re, index, 1);
if (ret == 0)
break;
printk(KERN_DEBUG
" re: logical %llu size %u empty %d for %lld",
re->logical, re->blocksize,
list_empty(&re->extctl), re->scheduled_for ?
re->scheduled_for->devid : -1);
for (i = 0; i < re->nzones; ++i) {
printk(KERN_CONT " zone %llu-%llu devs",
re->zones[i]->start,
re->zones[i]->end);
for (j = 0; j < re->zones[i]->ndevs; ++j) {
printk(KERN_CONT " %lld",
re->zones[i]->devs[j]->devid);
}
}
printk(KERN_CONT "\n");
index = (re->logical >> PAGE_CACHE_SHIFT) + 1;
if (++cnt > 15)
break;
}
}
index = 0;
cnt = 0;
while (all) {
struct reada_extent *re = NULL;
ret = radix_tree_gang_lookup(&fs_info->reada_tree, (void **)&re,
index, 1);
if (ret == 0)
break;
if (!re->scheduled_for) {
index = (re->logical >> PAGE_CACHE_SHIFT) + 1;
continue;
}
printk(KERN_DEBUG
"re: logical %llu size %u list empty %d for %lld",
re->logical, re->blocksize, list_empty(&re->extctl),
re->scheduled_for ? re->scheduled_for->devid : -1);
for (i = 0; i < re->nzones; ++i) {
printk(KERN_CONT " zone %llu-%llu devs",
re->zones[i]->start,
re->zones[i]->end);
for (i = 0; i < re->nzones; ++i) {
printk(KERN_CONT " zone %llu-%llu devs",
re->zones[i]->start,
re->zones[i]->end);
for (j = 0; j < re->zones[i]->ndevs; ++j) {
printk(KERN_CONT " %lld",
re->zones[i]->devs[j]->devid);
}
}
}
printk(KERN_CONT "\n");
index = (re->logical >> PAGE_CACHE_SHIFT) + 1;
}
spin_unlock(&fs_info->reada_lock);
}
struct reada_control *btrfs_reada_add(struct btrfs_root *root,
struct btrfs_key *key_start, struct btrfs_key *key_end)
{
struct reada_control *rc;
u64 start;
u64 generation;
int level;
struct extent_buffer *node;
static struct btrfs_key max_key = {
.objectid = (u64)-1,
.type = (u8)-1,
.offset = (u64)-1
};
rc = kzalloc(sizeof(*rc), GFP_NOFS);
if (!rc)
return ERR_PTR(-ENOMEM);
rc->root = root;
rc->key_start = *key_start;
rc->key_end = *key_end;
atomic_set(&rc->elems, 0);
init_waitqueue_head(&rc->wait);
kref_init(&rc->refcnt);
kref_get(&rc->refcnt);
node = btrfs_root_node(root);
start = node->start;
level = btrfs_header_level(node);
generation = btrfs_header_generation(node);
free_extent_buffer(node);
reada_add_block(rc, start, &max_key, level, generation);
reada_start_machine(root->fs_info);
return rc;
}
int btrfs_reada_wait(void *handle)
{
struct reada_control *rc = handle;
while (atomic_read(&rc->elems)) {
wait_event_timeout(rc->wait, atomic_read(&rc->elems) == 0,
5 * HZ);
dump_devs(rc->root->fs_info, rc->elems < 10 ? 1 : 0);
}
dump_devs(rc->root->fs_info, rc->elems < 10 ? 1 : 0);
kref_put(&rc->refcnt, reada_control_release);
return 0;
}
int btrfs_reada_wait(void *handle)
{
struct reada_control *rc = handle;
while (atomic_read(&rc->elems)) {
wait_event(rc->wait, atomic_read(&rc->elems) == 0);
}
kref_put(&rc->refcnt, reada_control_release);
return 0;
}
void btrfs_reada_detach(void *handle)
{
struct reada_control *rc = handle;
kref_put(&rc->refcnt, reada_control_release);
}
