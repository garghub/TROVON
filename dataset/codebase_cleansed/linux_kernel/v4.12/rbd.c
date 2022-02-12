static int atomic_inc_return_safe(atomic_t *v)
{
unsigned int counter;
counter = (unsigned int)__atomic_add_unless(v, 1, 0);
if (counter <= (unsigned int)INT_MAX)
return (int)counter;
atomic_dec(v);
return -EINVAL;
}
static int atomic_dec_return_safe(atomic_t *v)
{
int counter;
counter = atomic_dec_return(v);
if (counter >= 0)
return counter;
atomic_inc(v);
return -EINVAL;
}
static int rbd_dev_id_to_minor(int dev_id)
{
return dev_id << RBD_SINGLE_MAJOR_PART_SHIFT;
}
static int minor_to_rbd_dev_id(int minor)
{
return minor >> RBD_SINGLE_MAJOR_PART_SHIFT;
}
static bool __rbd_is_lock_owner(struct rbd_device *rbd_dev)
{
return rbd_dev->lock_state == RBD_LOCK_STATE_LOCKED ||
rbd_dev->lock_state == RBD_LOCK_STATE_RELEASING;
}
static bool rbd_is_lock_owner(struct rbd_device *rbd_dev)
{
bool is_lock_owner;
down_read(&rbd_dev->lock_rwsem);
is_lock_owner = __rbd_is_lock_owner(rbd_dev);
up_read(&rbd_dev->lock_rwsem);
return is_lock_owner;
}
static ssize_t rbd_supported_features_show(struct bus_type *bus, char *buf)
{
return sprintf(buf, "0x%llx\n", RBD_FEATURES_SUPPORTED);
}
static umode_t rbd_bus_is_visible(struct kobject *kobj,
struct attribute *attr, int index)
{
if (!single_major &&
(attr == &bus_attr_add_single_major.attr ||
attr == &bus_attr_remove_single_major.attr))
return 0;
return attr->mode;
}
static void rbd_root_dev_release(struct device *dev)
{
}
static int rbd_open(struct block_device *bdev, fmode_t mode)
{
struct rbd_device *rbd_dev = bdev->bd_disk->private_data;
bool removing = false;
if ((mode & FMODE_WRITE) && rbd_dev->mapping.read_only)
return -EROFS;
spin_lock_irq(&rbd_dev->lock);
if (test_bit(RBD_DEV_FLAG_REMOVING, &rbd_dev->flags))
removing = true;
else
rbd_dev->open_count++;
spin_unlock_irq(&rbd_dev->lock);
if (removing)
return -ENOENT;
(void) get_device(&rbd_dev->dev);
return 0;
}
static void rbd_release(struct gendisk *disk, fmode_t mode)
{
struct rbd_device *rbd_dev = disk->private_data;
unsigned long open_count_before;
spin_lock_irq(&rbd_dev->lock);
open_count_before = rbd_dev->open_count--;
spin_unlock_irq(&rbd_dev->lock);
rbd_assert(open_count_before > 0);
put_device(&rbd_dev->dev);
}
static int rbd_ioctl_set_ro(struct rbd_device *rbd_dev, unsigned long arg)
{
int ret = 0;
int val;
bool ro;
bool ro_changed = false;
if (get_user(val, (int __user *)(arg)))
return -EFAULT;
ro = val ? true : false;
if (rbd_dev->spec->snap_id != CEPH_NOSNAP && !ro)
return -EROFS;
spin_lock_irq(&rbd_dev->lock);
if (rbd_dev->open_count > 1) {
ret = -EBUSY;
goto out;
}
if (rbd_dev->mapping.read_only != ro) {
rbd_dev->mapping.read_only = ro;
ro_changed = true;
}
out:
spin_unlock_irq(&rbd_dev->lock);
if (ret == 0 && ro_changed)
set_disk_ro(rbd_dev->disk, ro ? 1 : 0);
return ret;
}
static int rbd_ioctl(struct block_device *bdev, fmode_t mode,
unsigned int cmd, unsigned long arg)
{
struct rbd_device *rbd_dev = bdev->bd_disk->private_data;
int ret = 0;
switch (cmd) {
case BLKROSET:
ret = rbd_ioctl_set_ro(rbd_dev, arg);
break;
default:
ret = -ENOTTY;
}
return ret;
}
static int rbd_compat_ioctl(struct block_device *bdev, fmode_t mode,
unsigned int cmd, unsigned long arg)
{
return rbd_ioctl(bdev, mode, cmd, arg);
}
static struct rbd_client *rbd_client_create(struct ceph_options *ceph_opts)
{
struct rbd_client *rbdc;
int ret = -ENOMEM;
dout("%s:\n", __func__);
rbdc = kmalloc(sizeof(struct rbd_client), GFP_KERNEL);
if (!rbdc)
goto out_opt;
kref_init(&rbdc->kref);
INIT_LIST_HEAD(&rbdc->node);
rbdc->client = ceph_create_client(ceph_opts, rbdc);
if (IS_ERR(rbdc->client))
goto out_rbdc;
ceph_opts = NULL;
ret = ceph_open_session(rbdc->client);
if (ret < 0)
goto out_client;
spin_lock(&rbd_client_list_lock);
list_add_tail(&rbdc->node, &rbd_client_list);
spin_unlock(&rbd_client_list_lock);
dout("%s: rbdc %p\n", __func__, rbdc);
return rbdc;
out_client:
ceph_destroy_client(rbdc->client);
out_rbdc:
kfree(rbdc);
out_opt:
if (ceph_opts)
ceph_destroy_options(ceph_opts);
dout("%s: error %d\n", __func__, ret);
return ERR_PTR(ret);
}
static struct rbd_client *__rbd_get_client(struct rbd_client *rbdc)
{
kref_get(&rbdc->kref);
return rbdc;
}
static struct rbd_client *rbd_client_find(struct ceph_options *ceph_opts)
{
struct rbd_client *client_node;
bool found = false;
if (ceph_opts->flags & CEPH_OPT_NOSHARE)
return NULL;
spin_lock(&rbd_client_list_lock);
list_for_each_entry(client_node, &rbd_client_list, node) {
if (!ceph_compare_options(ceph_opts, client_node->client)) {
__rbd_get_client(client_node);
found = true;
break;
}
}
spin_unlock(&rbd_client_list_lock);
return found ? client_node : NULL;
}
static int parse_rbd_opts_token(char *c, void *private)
{
struct rbd_options *rbd_opts = private;
substring_t argstr[MAX_OPT_ARGS];
int token, intval, ret;
token = match_token(c, rbd_opts_tokens, argstr);
if (token < Opt_last_int) {
ret = match_int(&argstr[0], &intval);
if (ret < 0) {
pr_err("bad mount option arg (not int) at '%s'\n", c);
return ret;
}
dout("got int token %d val %d\n", token, intval);
} else if (token > Opt_last_int && token < Opt_last_string) {
dout("got string token %d val %s\n", token, argstr[0].from);
} else {
dout("got token %d\n", token);
}
switch (token) {
case Opt_queue_depth:
if (intval < 1) {
pr_err("queue_depth out of range\n");
return -EINVAL;
}
rbd_opts->queue_depth = intval;
break;
case Opt_read_only:
rbd_opts->read_only = true;
break;
case Opt_read_write:
rbd_opts->read_only = false;
break;
case Opt_lock_on_read:
rbd_opts->lock_on_read = true;
break;
case Opt_exclusive:
rbd_opts->exclusive = true;
break;
default:
return -EINVAL;
}
return 0;
}
static char* obj_op_name(enum obj_operation_type op_type)
{
switch (op_type) {
case OBJ_OP_READ:
return "read";
case OBJ_OP_WRITE:
return "write";
case OBJ_OP_DISCARD:
return "discard";
default:
return "???";
}
}
static struct rbd_client *rbd_get_client(struct ceph_options *ceph_opts)
{
struct rbd_client *rbdc;
mutex_lock_nested(&client_mutex, SINGLE_DEPTH_NESTING);
rbdc = rbd_client_find(ceph_opts);
if (rbdc)
ceph_destroy_options(ceph_opts);
else
rbdc = rbd_client_create(ceph_opts);
mutex_unlock(&client_mutex);
return rbdc;
}
static void rbd_client_release(struct kref *kref)
{
struct rbd_client *rbdc = container_of(kref, struct rbd_client, kref);
dout("%s: rbdc %p\n", __func__, rbdc);
spin_lock(&rbd_client_list_lock);
list_del(&rbdc->node);
spin_unlock(&rbd_client_list_lock);
ceph_destroy_client(rbdc->client);
kfree(rbdc);
}
static void rbd_put_client(struct rbd_client *rbdc)
{
if (rbdc)
kref_put(&rbdc->kref, rbd_client_release);
}
static bool rbd_image_format_valid(u32 image_format)
{
return image_format == 1 || image_format == 2;
}
static bool rbd_dev_ondisk_valid(struct rbd_image_header_ondisk *ondisk)
{
size_t size;
u32 snap_count;
if (memcmp(&ondisk->text, RBD_HEADER_TEXT, sizeof (RBD_HEADER_TEXT)))
return false;
if (ondisk->options.order < SECTOR_SHIFT)
return false;
if (ondisk->options.order > 8 * sizeof (int) - 1)
return false;
snap_count = le32_to_cpu(ondisk->snap_count);
size = SIZE_MAX - sizeof (struct ceph_snap_context);
if (snap_count > size / sizeof (__le64))
return false;
size -= snap_count * sizeof (__le64);
if ((u64) size < le64_to_cpu(ondisk->snap_names_len))
return false;
return true;
}
static u32 rbd_obj_bytes(struct rbd_image_header *header)
{
return 1U << header->obj_order;
}
static void rbd_init_layout(struct rbd_device *rbd_dev)
{
if (rbd_dev->header.stripe_unit == 0 ||
rbd_dev->header.stripe_count == 0) {
rbd_dev->header.stripe_unit = rbd_obj_bytes(&rbd_dev->header);
rbd_dev->header.stripe_count = 1;
}
rbd_dev->layout.stripe_unit = rbd_dev->header.stripe_unit;
rbd_dev->layout.stripe_count = rbd_dev->header.stripe_count;
rbd_dev->layout.object_size = rbd_obj_bytes(&rbd_dev->header);
rbd_dev->layout.pool_id = rbd_dev->header.data_pool_id == CEPH_NOPOOL ?
rbd_dev->spec->pool_id : rbd_dev->header.data_pool_id;
RCU_INIT_POINTER(rbd_dev->layout.pool_ns, NULL);
}
static int rbd_header_from_disk(struct rbd_device *rbd_dev,
struct rbd_image_header_ondisk *ondisk)
{
struct rbd_image_header *header = &rbd_dev->header;
bool first_time = header->object_prefix == NULL;
struct ceph_snap_context *snapc;
char *object_prefix = NULL;
char *snap_names = NULL;
u64 *snap_sizes = NULL;
u32 snap_count;
int ret = -ENOMEM;
u32 i;
if (first_time) {
object_prefix = kstrndup(ondisk->object_prefix,
sizeof(ondisk->object_prefix),
GFP_KERNEL);
if (!object_prefix)
return -ENOMEM;
}
snap_count = le32_to_cpu(ondisk->snap_count);
snapc = ceph_create_snap_context(snap_count, GFP_KERNEL);
if (!snapc)
goto out_err;
snapc->seq = le64_to_cpu(ondisk->snap_seq);
if (snap_count) {
struct rbd_image_snap_ondisk *snaps;
u64 snap_names_len = le64_to_cpu(ondisk->snap_names_len);
if (snap_names_len > (u64)SIZE_MAX)
goto out_2big;
snap_names = kmalloc(snap_names_len, GFP_KERNEL);
if (!snap_names)
goto out_err;
snap_sizes = kmalloc_array(snap_count,
sizeof(*header->snap_sizes),
GFP_KERNEL);
if (!snap_sizes)
goto out_err;
memcpy(snap_names, &ondisk->snaps[snap_count], snap_names_len);
snaps = ondisk->snaps;
for (i = 0; i < snap_count; i++) {
snapc->snaps[i] = le64_to_cpu(snaps[i].id);
snap_sizes[i] = le64_to_cpu(snaps[i].image_size);
}
}
if (first_time) {
header->object_prefix = object_prefix;
header->obj_order = ondisk->options.order;
rbd_init_layout(rbd_dev);
} else {
ceph_put_snap_context(header->snapc);
kfree(header->snap_names);
kfree(header->snap_sizes);
}
header->image_size = le64_to_cpu(ondisk->image_size);
header->snapc = snapc;
header->snap_names = snap_names;
header->snap_sizes = snap_sizes;
return 0;
out_2big:
ret = -EIO;
out_err:
kfree(snap_sizes);
kfree(snap_names);
ceph_put_snap_context(snapc);
kfree(object_prefix);
return ret;
}
static const char *_rbd_dev_v1_snap_name(struct rbd_device *rbd_dev, u32 which)
{
const char *snap_name;
rbd_assert(which < rbd_dev->header.snapc->num_snaps);
snap_name = rbd_dev->header.snap_names;
while (which--)
snap_name += strlen(snap_name) + 1;
return kstrdup(snap_name, GFP_KERNEL);
}
static int snapid_compare_reverse(const void *s1, const void *s2)
{
u64 snap_id1 = *(u64 *)s1;
u64 snap_id2 = *(u64 *)s2;
if (snap_id1 < snap_id2)
return 1;
return snap_id1 == snap_id2 ? 0 : -1;
}
static u32 rbd_dev_snap_index(struct rbd_device *rbd_dev, u64 snap_id)
{
struct ceph_snap_context *snapc = rbd_dev->header.snapc;
u64 *found;
found = bsearch(&snap_id, &snapc->snaps, snapc->num_snaps,
sizeof (snap_id), snapid_compare_reverse);
return found ? (u32)(found - &snapc->snaps[0]) : BAD_SNAP_INDEX;
}
static const char *rbd_dev_v1_snap_name(struct rbd_device *rbd_dev,
u64 snap_id)
{
u32 which;
const char *snap_name;
which = rbd_dev_snap_index(rbd_dev, snap_id);
if (which == BAD_SNAP_INDEX)
return ERR_PTR(-ENOENT);
snap_name = _rbd_dev_v1_snap_name(rbd_dev, which);
return snap_name ? snap_name : ERR_PTR(-ENOMEM);
}
static const char *rbd_snap_name(struct rbd_device *rbd_dev, u64 snap_id)
{
if (snap_id == CEPH_NOSNAP)
return RBD_SNAP_HEAD_NAME;
rbd_assert(rbd_image_format_valid(rbd_dev->image_format));
if (rbd_dev->image_format == 1)
return rbd_dev_v1_snap_name(rbd_dev, snap_id);
return rbd_dev_v2_snap_name(rbd_dev, snap_id);
}
static int rbd_snap_size(struct rbd_device *rbd_dev, u64 snap_id,
u64 *snap_size)
{
rbd_assert(rbd_image_format_valid(rbd_dev->image_format));
if (snap_id == CEPH_NOSNAP) {
*snap_size = rbd_dev->header.image_size;
} else if (rbd_dev->image_format == 1) {
u32 which;
which = rbd_dev_snap_index(rbd_dev, snap_id);
if (which == BAD_SNAP_INDEX)
return -ENOENT;
*snap_size = rbd_dev->header.snap_sizes[which];
} else {
u64 size = 0;
int ret;
ret = _rbd_dev_v2_snap_size(rbd_dev, snap_id, NULL, &size);
if (ret)
return ret;
*snap_size = size;
}
return 0;
}
static int rbd_snap_features(struct rbd_device *rbd_dev, u64 snap_id,
u64 *snap_features)
{
rbd_assert(rbd_image_format_valid(rbd_dev->image_format));
if (snap_id == CEPH_NOSNAP) {
*snap_features = rbd_dev->header.features;
} else if (rbd_dev->image_format == 1) {
*snap_features = 0;
} else {
u64 features = 0;
int ret;
ret = _rbd_dev_v2_snap_features(rbd_dev, snap_id, &features);
if (ret)
return ret;
*snap_features = features;
}
return 0;
}
static int rbd_dev_mapping_set(struct rbd_device *rbd_dev)
{
u64 snap_id = rbd_dev->spec->snap_id;
u64 size = 0;
u64 features = 0;
int ret;
ret = rbd_snap_size(rbd_dev, snap_id, &size);
if (ret)
return ret;
ret = rbd_snap_features(rbd_dev, snap_id, &features);
if (ret)
return ret;
rbd_dev->mapping.size = size;
rbd_dev->mapping.features = features;
return 0;
}
static void rbd_dev_mapping_clear(struct rbd_device *rbd_dev)
{
rbd_dev->mapping.size = 0;
rbd_dev->mapping.features = 0;
}
static u64 rbd_segment_offset(struct rbd_device *rbd_dev, u64 offset)
{
u64 segment_size = rbd_obj_bytes(&rbd_dev->header);
return offset & (segment_size - 1);
}
static u64 rbd_segment_length(struct rbd_device *rbd_dev,
u64 offset, u64 length)
{
u64 segment_size = rbd_obj_bytes(&rbd_dev->header);
offset &= segment_size - 1;
rbd_assert(length <= U64_MAX - offset);
if (offset + length > segment_size)
length = segment_size - offset;
return length;
}
static void bio_chain_put(struct bio *chain)
{
struct bio *tmp;
while (chain) {
tmp = chain;
chain = chain->bi_next;
bio_put(tmp);
}
}
static void zero_bio_chain(struct bio *chain, int start_ofs)
{
struct bio_vec bv;
struct bvec_iter iter;
unsigned long flags;
void *buf;
int pos = 0;
while (chain) {
bio_for_each_segment(bv, chain, iter) {
if (pos + bv.bv_len > start_ofs) {
int remainder = max(start_ofs - pos, 0);
buf = bvec_kmap_irq(&bv, &flags);
memset(buf + remainder, 0,
bv.bv_len - remainder);
flush_dcache_page(bv.bv_page);
bvec_kunmap_irq(buf, &flags);
}
pos += bv.bv_len;
}
chain = chain->bi_next;
}
}
static void zero_pages(struct page **pages, u64 offset, u64 end)
{
struct page **page = &pages[offset >> PAGE_SHIFT];
rbd_assert(end > offset);
rbd_assert(end - offset <= (u64)SIZE_MAX);
while (offset < end) {
size_t page_offset;
size_t length;
unsigned long flags;
void *kaddr;
page_offset = offset & ~PAGE_MASK;
length = min_t(size_t, PAGE_SIZE - page_offset, end - offset);
local_irq_save(flags);
kaddr = kmap_atomic(*page);
memset(kaddr + page_offset, 0, length);
flush_dcache_page(*page);
kunmap_atomic(kaddr);
local_irq_restore(flags);
offset += length;
page++;
}
}
static struct bio *bio_clone_range(struct bio *bio_src,
unsigned int offset,
unsigned int len,
gfp_t gfpmask)
{
struct bio *bio;
bio = bio_clone(bio_src, gfpmask);
if (!bio)
return NULL;
bio_advance(bio, offset);
bio->bi_iter.bi_size = len;
return bio;
}
static struct bio *bio_chain_clone_range(struct bio **bio_src,
unsigned int *offset,
unsigned int len,
gfp_t gfpmask)
{
struct bio *bi = *bio_src;
unsigned int off = *offset;
struct bio *chain = NULL;
struct bio **end;
if (!bi || off >= bi->bi_iter.bi_size || !len)
return NULL;
end = &chain;
while (len) {
unsigned int bi_size;
struct bio *bio;
if (!bi) {
rbd_warn(NULL, "bio_chain exhausted with %u left", len);
goto out_err;
}
bi_size = min_t(unsigned int, bi->bi_iter.bi_size - off, len);
bio = bio_clone_range(bi, off, bi_size, gfpmask);
if (!bio)
goto out_err;
*end = bio;
end = &bio->bi_next;
off += bi_size;
if (off == bi->bi_iter.bi_size) {
bi = bi->bi_next;
off = 0;
}
len -= bi_size;
}
*bio_src = bi;
*offset = off;
return chain;
out_err:
bio_chain_put(chain);
return NULL;
}
static void obj_request_img_data_set(struct rbd_obj_request *obj_request)
{
if (test_and_set_bit(OBJ_REQ_IMG_DATA, &obj_request->flags)) {
struct rbd_device *rbd_dev;
rbd_dev = obj_request->img_request->rbd_dev;
rbd_warn(rbd_dev, "obj_request %p already marked img_data",
obj_request);
}
}
static bool obj_request_img_data_test(struct rbd_obj_request *obj_request)
{
smp_mb();
return test_bit(OBJ_REQ_IMG_DATA, &obj_request->flags) != 0;
}
static void obj_request_done_set(struct rbd_obj_request *obj_request)
{
if (test_and_set_bit(OBJ_REQ_DONE, &obj_request->flags)) {
struct rbd_device *rbd_dev = NULL;
if (obj_request_img_data_test(obj_request))
rbd_dev = obj_request->img_request->rbd_dev;
rbd_warn(rbd_dev, "obj_request %p already marked done",
obj_request);
}
}
static bool obj_request_done_test(struct rbd_obj_request *obj_request)
{
smp_mb();
return test_bit(OBJ_REQ_DONE, &obj_request->flags) != 0;
}
static void obj_request_existence_set(struct rbd_obj_request *obj_request,
bool exists)
{
if (exists)
set_bit(OBJ_REQ_EXISTS, &obj_request->flags);
set_bit(OBJ_REQ_KNOWN, &obj_request->flags);
smp_mb();
}
static bool obj_request_known_test(struct rbd_obj_request *obj_request)
{
smp_mb();
return test_bit(OBJ_REQ_KNOWN, &obj_request->flags) != 0;
}
static bool obj_request_exists_test(struct rbd_obj_request *obj_request)
{
smp_mb();
return test_bit(OBJ_REQ_EXISTS, &obj_request->flags) != 0;
}
static bool obj_request_overlaps_parent(struct rbd_obj_request *obj_request)
{
struct rbd_device *rbd_dev = obj_request->img_request->rbd_dev;
return obj_request->img_offset <
round_up(rbd_dev->parent_overlap, rbd_obj_bytes(&rbd_dev->header));
}
static void rbd_obj_request_get(struct rbd_obj_request *obj_request)
{
dout("%s: obj %p (was %d)\n", __func__, obj_request,
kref_read(&obj_request->kref));
kref_get(&obj_request->kref);
}
static void rbd_obj_request_put(struct rbd_obj_request *obj_request)
{
rbd_assert(obj_request != NULL);
dout("%s: obj %p (was %d)\n", __func__, obj_request,
kref_read(&obj_request->kref));
kref_put(&obj_request->kref, rbd_obj_request_destroy);
}
static void rbd_img_request_get(struct rbd_img_request *img_request)
{
dout("%s: img %p (was %d)\n", __func__, img_request,
kref_read(&img_request->kref));
kref_get(&img_request->kref);
}
static void rbd_img_request_put(struct rbd_img_request *img_request)
{
rbd_assert(img_request != NULL);
dout("%s: img %p (was %d)\n", __func__, img_request,
kref_read(&img_request->kref));
if (img_request_child_test(img_request))
kref_put(&img_request->kref, rbd_parent_request_destroy);
else
kref_put(&img_request->kref, rbd_img_request_destroy);
}
static inline void rbd_img_obj_request_add(struct rbd_img_request *img_request,
struct rbd_obj_request *obj_request)
{
rbd_assert(obj_request->img_request == NULL);
obj_request->img_request = img_request;
obj_request->which = img_request->obj_request_count;
rbd_assert(!obj_request_img_data_test(obj_request));
obj_request_img_data_set(obj_request);
rbd_assert(obj_request->which != BAD_WHICH);
img_request->obj_request_count++;
list_add_tail(&obj_request->links, &img_request->obj_requests);
dout("%s: img %p obj %p w=%u\n", __func__, img_request, obj_request,
obj_request->which);
}
static inline void rbd_img_obj_request_del(struct rbd_img_request *img_request,
struct rbd_obj_request *obj_request)
{
rbd_assert(obj_request->which != BAD_WHICH);
dout("%s: img %p obj %p w=%u\n", __func__, img_request, obj_request,
obj_request->which);
list_del(&obj_request->links);
rbd_assert(img_request->obj_request_count > 0);
img_request->obj_request_count--;
rbd_assert(obj_request->which == img_request->obj_request_count);
obj_request->which = BAD_WHICH;
rbd_assert(obj_request_img_data_test(obj_request));
rbd_assert(obj_request->img_request == img_request);
obj_request->img_request = NULL;
obj_request->callback = NULL;
rbd_obj_request_put(obj_request);
}
static bool obj_request_type_valid(enum obj_request_type type)
{
switch (type) {
case OBJ_REQUEST_NODATA:
case OBJ_REQUEST_BIO:
case OBJ_REQUEST_PAGES:
return true;
default:
return false;
}
}
static void rbd_obj_request_submit(struct rbd_obj_request *obj_request)
{
struct ceph_osd_request *osd_req = obj_request->osd_req;
dout("%s %p object_no %016llx %llu~%llu osd_req %p\n", __func__,
obj_request, obj_request->object_no, obj_request->offset,
obj_request->length, osd_req);
if (obj_request_img_data_test(obj_request)) {
WARN_ON(obj_request->callback != rbd_img_obj_callback);
rbd_img_request_get(obj_request->img_request);
}
ceph_osdc_start_request(osd_req->r_osdc, osd_req, false);
}
static void rbd_img_request_complete(struct rbd_img_request *img_request)
{
dout("%s: img %p\n", __func__, img_request);
if (!img_request->result) {
struct rbd_obj_request *obj_request;
u64 xferred = 0;
for_each_obj_request(img_request, obj_request)
xferred += obj_request->xferred;
img_request->xferred = xferred;
}
if (img_request->callback)
img_request->callback(img_request);
else
rbd_img_request_put(img_request);
}
static void img_request_write_set(struct rbd_img_request *img_request)
{
set_bit(IMG_REQ_WRITE, &img_request->flags);
smp_mb();
}
static bool img_request_write_test(struct rbd_img_request *img_request)
{
smp_mb();
return test_bit(IMG_REQ_WRITE, &img_request->flags) != 0;
}
static void img_request_discard_set(struct rbd_img_request *img_request)
{
set_bit(IMG_REQ_DISCARD, &img_request->flags);
smp_mb();
}
static bool img_request_discard_test(struct rbd_img_request *img_request)
{
smp_mb();
return test_bit(IMG_REQ_DISCARD, &img_request->flags) != 0;
}
static void img_request_child_set(struct rbd_img_request *img_request)
{
set_bit(IMG_REQ_CHILD, &img_request->flags);
smp_mb();
}
static void img_request_child_clear(struct rbd_img_request *img_request)
{
clear_bit(IMG_REQ_CHILD, &img_request->flags);
smp_mb();
}
static bool img_request_child_test(struct rbd_img_request *img_request)
{
smp_mb();
return test_bit(IMG_REQ_CHILD, &img_request->flags) != 0;
}
static void img_request_layered_set(struct rbd_img_request *img_request)
{
set_bit(IMG_REQ_LAYERED, &img_request->flags);
smp_mb();
}
static void img_request_layered_clear(struct rbd_img_request *img_request)
{
clear_bit(IMG_REQ_LAYERED, &img_request->flags);
smp_mb();
}
static bool img_request_layered_test(struct rbd_img_request *img_request)
{
smp_mb();
return test_bit(IMG_REQ_LAYERED, &img_request->flags) != 0;
}
static enum obj_operation_type
rbd_img_request_op_type(struct rbd_img_request *img_request)
{
if (img_request_write_test(img_request))
return OBJ_OP_WRITE;
else if (img_request_discard_test(img_request))
return OBJ_OP_DISCARD;
else
return OBJ_OP_READ;
}
static void
rbd_img_obj_request_read_callback(struct rbd_obj_request *obj_request)
{
u64 xferred = obj_request->xferred;
u64 length = obj_request->length;
dout("%s: obj %p img %p result %d %llu/%llu\n", __func__,
obj_request, obj_request->img_request, obj_request->result,
xferred, length);
rbd_assert(obj_request->type != OBJ_REQUEST_NODATA);
if (obj_request->result == -ENOENT) {
if (obj_request->type == OBJ_REQUEST_BIO)
zero_bio_chain(obj_request->bio_list, 0);
else
zero_pages(obj_request->pages, 0, length);
obj_request->result = 0;
} else if (xferred < length && !obj_request->result) {
if (obj_request->type == OBJ_REQUEST_BIO)
zero_bio_chain(obj_request->bio_list, xferred);
else
zero_pages(obj_request->pages, xferred, length);
}
obj_request->xferred = length;
obj_request_done_set(obj_request);
}
static void rbd_obj_request_complete(struct rbd_obj_request *obj_request)
{
dout("%s: obj %p cb %p\n", __func__, obj_request,
obj_request->callback);
if (obj_request->callback)
obj_request->callback(obj_request);
else
complete_all(&obj_request->completion);
}
static void rbd_obj_request_error(struct rbd_obj_request *obj_request, int err)
{
obj_request->result = err;
obj_request->xferred = 0;
if (obj_request_img_data_test(obj_request)) {
WARN_ON(obj_request->callback != rbd_img_obj_callback);
rbd_img_request_get(obj_request->img_request);
}
obj_request_done_set(obj_request);
rbd_obj_request_complete(obj_request);
}
static void rbd_osd_read_callback(struct rbd_obj_request *obj_request)
{
struct rbd_img_request *img_request = NULL;
struct rbd_device *rbd_dev = NULL;
bool layered = false;
if (obj_request_img_data_test(obj_request)) {
img_request = obj_request->img_request;
layered = img_request && img_request_layered_test(img_request);
rbd_dev = img_request->rbd_dev;
}
dout("%s: obj %p img %p result %d %llu/%llu\n", __func__,
obj_request, img_request, obj_request->result,
obj_request->xferred, obj_request->length);
if (layered && obj_request->result == -ENOENT &&
obj_request->img_offset < rbd_dev->parent_overlap)
rbd_img_parent_read(obj_request);
else if (img_request)
rbd_img_obj_request_read_callback(obj_request);
else
obj_request_done_set(obj_request);
}
static void rbd_osd_write_callback(struct rbd_obj_request *obj_request)
{
dout("%s: obj %p result %d %llu\n", __func__, obj_request,
obj_request->result, obj_request->length);
obj_request->xferred = obj_request->length;
obj_request_done_set(obj_request);
}
static void rbd_osd_discard_callback(struct rbd_obj_request *obj_request)
{
dout("%s: obj %p result %d %llu\n", __func__, obj_request,
obj_request->result, obj_request->length);
obj_request->xferred = obj_request->length;
if (obj_request->result == -ENOENT)
obj_request->result = 0;
obj_request_done_set(obj_request);
}
static void rbd_osd_stat_callback(struct rbd_obj_request *obj_request)
{
dout("%s: obj %p\n", __func__, obj_request);
obj_request_done_set(obj_request);
}
static void rbd_osd_call_callback(struct rbd_obj_request *obj_request)
{
dout("%s: obj %p\n", __func__, obj_request);
if (obj_request_img_data_test(obj_request))
rbd_osd_copyup_callback(obj_request);
else
obj_request_done_set(obj_request);
}
static void rbd_osd_req_callback(struct ceph_osd_request *osd_req)
{
struct rbd_obj_request *obj_request = osd_req->r_priv;
u16 opcode;
dout("%s: osd_req %p\n", __func__, osd_req);
rbd_assert(osd_req == obj_request->osd_req);
if (obj_request_img_data_test(obj_request)) {
rbd_assert(obj_request->img_request);
rbd_assert(obj_request->which != BAD_WHICH);
} else {
rbd_assert(obj_request->which == BAD_WHICH);
}
if (osd_req->r_result < 0)
obj_request->result = osd_req->r_result;
obj_request->xferred = osd_req->r_ops[0].outdata_len;
rbd_assert(obj_request->xferred < (u64)UINT_MAX);
opcode = osd_req->r_ops[0].op;
switch (opcode) {
case CEPH_OSD_OP_READ:
rbd_osd_read_callback(obj_request);
break;
case CEPH_OSD_OP_SETALLOCHINT:
rbd_assert(osd_req->r_ops[1].op == CEPH_OSD_OP_WRITE ||
osd_req->r_ops[1].op == CEPH_OSD_OP_WRITEFULL);
case CEPH_OSD_OP_WRITE:
case CEPH_OSD_OP_WRITEFULL:
rbd_osd_write_callback(obj_request);
break;
case CEPH_OSD_OP_STAT:
rbd_osd_stat_callback(obj_request);
break;
case CEPH_OSD_OP_DELETE:
case CEPH_OSD_OP_TRUNCATE:
case CEPH_OSD_OP_ZERO:
rbd_osd_discard_callback(obj_request);
break;
case CEPH_OSD_OP_CALL:
rbd_osd_call_callback(obj_request);
break;
default:
rbd_warn(NULL, "unexpected OSD op: object_no %016llx opcode %d",
obj_request->object_no, opcode);
break;
}
if (obj_request_done_test(obj_request))
rbd_obj_request_complete(obj_request);
}
static void rbd_osd_req_format_read(struct rbd_obj_request *obj_request)
{
struct ceph_osd_request *osd_req = obj_request->osd_req;
rbd_assert(obj_request_img_data_test(obj_request));
osd_req->r_snapid = obj_request->img_request->snap_id;
}
static void rbd_osd_req_format_write(struct rbd_obj_request *obj_request)
{
struct ceph_osd_request *osd_req = obj_request->osd_req;
ktime_get_real_ts(&osd_req->r_mtime);
osd_req->r_data_offset = obj_request->offset;
}
static struct ceph_osd_request *
__rbd_osd_req_create(struct rbd_device *rbd_dev,
struct ceph_snap_context *snapc,
int num_ops, unsigned int flags,
struct rbd_obj_request *obj_request)
{
struct ceph_osd_client *osdc = &rbd_dev->rbd_client->client->osdc;
struct ceph_osd_request *req;
const char *name_format = rbd_dev->image_format == 1 ?
RBD_V1_DATA_FORMAT : RBD_V2_DATA_FORMAT;
req = ceph_osdc_alloc_request(osdc, snapc, num_ops, false, GFP_NOIO);
if (!req)
return NULL;
req->r_flags = flags;
req->r_callback = rbd_osd_req_callback;
req->r_priv = obj_request;
req->r_base_oloc.pool = rbd_dev->layout.pool_id;
if (ceph_oid_aprintf(&req->r_base_oid, GFP_NOIO, name_format,
rbd_dev->header.object_prefix, obj_request->object_no))
goto err_req;
if (ceph_osdc_alloc_messages(req, GFP_NOIO))
goto err_req;
return req;
err_req:
ceph_osdc_put_request(req);
return NULL;
}
static struct ceph_osd_request *rbd_osd_req_create(
struct rbd_device *rbd_dev,
enum obj_operation_type op_type,
unsigned int num_ops,
struct rbd_obj_request *obj_request)
{
struct ceph_snap_context *snapc = NULL;
if (obj_request_img_data_test(obj_request) &&
(op_type == OBJ_OP_DISCARD || op_type == OBJ_OP_WRITE)) {
struct rbd_img_request *img_request = obj_request->img_request;
if (op_type == OBJ_OP_WRITE) {
rbd_assert(img_request_write_test(img_request));
} else {
rbd_assert(img_request_discard_test(img_request));
}
snapc = img_request->snapc;
}
rbd_assert(num_ops == 1 || ((op_type == OBJ_OP_WRITE) && num_ops == 2));
return __rbd_osd_req_create(rbd_dev, snapc, num_ops,
(op_type == OBJ_OP_WRITE || op_type == OBJ_OP_DISCARD) ?
CEPH_OSD_FLAG_WRITE : CEPH_OSD_FLAG_READ, obj_request);
}
static struct ceph_osd_request *
rbd_osd_req_create_copyup(struct rbd_obj_request *obj_request)
{
struct rbd_img_request *img_request;
int num_osd_ops = 3;
rbd_assert(obj_request_img_data_test(obj_request));
img_request = obj_request->img_request;
rbd_assert(img_request);
rbd_assert(img_request_write_test(img_request) ||
img_request_discard_test(img_request));
if (img_request_discard_test(img_request))
num_osd_ops = 2;
return __rbd_osd_req_create(img_request->rbd_dev,
img_request->snapc, num_osd_ops,
CEPH_OSD_FLAG_WRITE, obj_request);
}
static void rbd_osd_req_destroy(struct ceph_osd_request *osd_req)
{
ceph_osdc_put_request(osd_req);
}
static struct rbd_obj_request *
rbd_obj_request_create(enum obj_request_type type)
{
struct rbd_obj_request *obj_request;
rbd_assert(obj_request_type_valid(type));
obj_request = kmem_cache_zalloc(rbd_obj_request_cache, GFP_NOIO);
if (!obj_request)
return NULL;
obj_request->which = BAD_WHICH;
obj_request->type = type;
INIT_LIST_HEAD(&obj_request->links);
init_completion(&obj_request->completion);
kref_init(&obj_request->kref);
dout("%s %p\n", __func__, obj_request);
return obj_request;
}
static void rbd_obj_request_destroy(struct kref *kref)
{
struct rbd_obj_request *obj_request;
obj_request = container_of(kref, struct rbd_obj_request, kref);
dout("%s: obj %p\n", __func__, obj_request);
rbd_assert(obj_request->img_request == NULL);
rbd_assert(obj_request->which == BAD_WHICH);
if (obj_request->osd_req)
rbd_osd_req_destroy(obj_request->osd_req);
rbd_assert(obj_request_type_valid(obj_request->type));
switch (obj_request->type) {
case OBJ_REQUEST_NODATA:
break;
case OBJ_REQUEST_BIO:
if (obj_request->bio_list)
bio_chain_put(obj_request->bio_list);
break;
case OBJ_REQUEST_PAGES:
if (obj_request->pages &&
!obj_request_img_data_test(obj_request))
ceph_release_page_vector(obj_request->pages,
obj_request->page_count);
break;
}
kmem_cache_free(rbd_obj_request_cache, obj_request);
}
static void rbd_dev_unparent(struct rbd_device *rbd_dev)
{
rbd_dev_remove_parent(rbd_dev);
rbd_spec_put(rbd_dev->parent_spec);
rbd_dev->parent_spec = NULL;
rbd_dev->parent_overlap = 0;
}
static void rbd_dev_parent_put(struct rbd_device *rbd_dev)
{
int counter;
if (!rbd_dev->parent_spec)
return;
counter = atomic_dec_return_safe(&rbd_dev->parent_ref);
if (counter > 0)
return;
if (!counter)
rbd_dev_unparent(rbd_dev);
else
rbd_warn(rbd_dev, "parent reference underflow");
}
static bool rbd_dev_parent_get(struct rbd_device *rbd_dev)
{
int counter = 0;
if (!rbd_dev->parent_spec)
return false;
down_read(&rbd_dev->header_rwsem);
if (rbd_dev->parent_overlap)
counter = atomic_inc_return_safe(&rbd_dev->parent_ref);
up_read(&rbd_dev->header_rwsem);
if (counter < 0)
rbd_warn(rbd_dev, "parent reference overflow");
return counter > 0;
}
static struct rbd_img_request *rbd_img_request_create(
struct rbd_device *rbd_dev,
u64 offset, u64 length,
enum obj_operation_type op_type,
struct ceph_snap_context *snapc)
{
struct rbd_img_request *img_request;
img_request = kmem_cache_alloc(rbd_img_request_cache, GFP_NOIO);
if (!img_request)
return NULL;
img_request->rq = NULL;
img_request->rbd_dev = rbd_dev;
img_request->offset = offset;
img_request->length = length;
img_request->flags = 0;
if (op_type == OBJ_OP_DISCARD) {
img_request_discard_set(img_request);
img_request->snapc = snapc;
} else if (op_type == OBJ_OP_WRITE) {
img_request_write_set(img_request);
img_request->snapc = snapc;
} else {
img_request->snap_id = rbd_dev->spec->snap_id;
}
if (rbd_dev_parent_get(rbd_dev))
img_request_layered_set(img_request);
spin_lock_init(&img_request->completion_lock);
img_request->next_completion = 0;
img_request->callback = NULL;
img_request->result = 0;
img_request->obj_request_count = 0;
INIT_LIST_HEAD(&img_request->obj_requests);
kref_init(&img_request->kref);
dout("%s: rbd_dev %p %s %llu/%llu -> img %p\n", __func__, rbd_dev,
obj_op_name(op_type), offset, length, img_request);
return img_request;
}
static void rbd_img_request_destroy(struct kref *kref)
{
struct rbd_img_request *img_request;
struct rbd_obj_request *obj_request;
struct rbd_obj_request *next_obj_request;
img_request = container_of(kref, struct rbd_img_request, kref);
dout("%s: img %p\n", __func__, img_request);
for_each_obj_request_safe(img_request, obj_request, next_obj_request)
rbd_img_obj_request_del(img_request, obj_request);
rbd_assert(img_request->obj_request_count == 0);
if (img_request_layered_test(img_request)) {
img_request_layered_clear(img_request);
rbd_dev_parent_put(img_request->rbd_dev);
}
if (img_request_write_test(img_request) ||
img_request_discard_test(img_request))
ceph_put_snap_context(img_request->snapc);
kmem_cache_free(rbd_img_request_cache, img_request);
}
static struct rbd_img_request *rbd_parent_request_create(
struct rbd_obj_request *obj_request,
u64 img_offset, u64 length)
{
struct rbd_img_request *parent_request;
struct rbd_device *rbd_dev;
rbd_assert(obj_request->img_request);
rbd_dev = obj_request->img_request->rbd_dev;
parent_request = rbd_img_request_create(rbd_dev->parent, img_offset,
length, OBJ_OP_READ, NULL);
if (!parent_request)
return NULL;
img_request_child_set(parent_request);
rbd_obj_request_get(obj_request);
parent_request->obj_request = obj_request;
return parent_request;
}
static void rbd_parent_request_destroy(struct kref *kref)
{
struct rbd_img_request *parent_request;
struct rbd_obj_request *orig_request;
parent_request = container_of(kref, struct rbd_img_request, kref);
orig_request = parent_request->obj_request;
parent_request->obj_request = NULL;
rbd_obj_request_put(orig_request);
img_request_child_clear(parent_request);
rbd_img_request_destroy(kref);
}
static bool rbd_img_obj_end_request(struct rbd_obj_request *obj_request)
{
struct rbd_img_request *img_request;
unsigned int xferred;
int result;
bool more;
rbd_assert(obj_request_img_data_test(obj_request));
img_request = obj_request->img_request;
rbd_assert(obj_request->xferred <= (u64)UINT_MAX);
xferred = (unsigned int)obj_request->xferred;
result = obj_request->result;
if (result) {
struct rbd_device *rbd_dev = img_request->rbd_dev;
enum obj_operation_type op_type;
if (img_request_discard_test(img_request))
op_type = OBJ_OP_DISCARD;
else if (img_request_write_test(img_request))
op_type = OBJ_OP_WRITE;
else
op_type = OBJ_OP_READ;
rbd_warn(rbd_dev, "%s %llx at %llx (%llx)",
obj_op_name(op_type), obj_request->length,
obj_request->img_offset, obj_request->offset);
rbd_warn(rbd_dev, " result %d xferred %x",
result, xferred);
if (!img_request->result)
img_request->result = result;
xferred = obj_request->length;
}
if (img_request_child_test(img_request)) {
rbd_assert(img_request->obj_request != NULL);
more = obj_request->which < img_request->obj_request_count - 1;
} else {
rbd_assert(img_request->rq != NULL);
more = blk_update_request(img_request->rq, result, xferred);
if (!more)
__blk_mq_end_request(img_request->rq, result);
}
return more;
}
static void rbd_img_obj_callback(struct rbd_obj_request *obj_request)
{
struct rbd_img_request *img_request;
u32 which = obj_request->which;
bool more = true;
rbd_assert(obj_request_img_data_test(obj_request));
img_request = obj_request->img_request;
dout("%s: img %p obj %p\n", __func__, img_request, obj_request);
rbd_assert(img_request != NULL);
rbd_assert(img_request->obj_request_count > 0);
rbd_assert(which != BAD_WHICH);
rbd_assert(which < img_request->obj_request_count);
spin_lock_irq(&img_request->completion_lock);
if (which != img_request->next_completion)
goto out;
for_each_obj_request_from(img_request, obj_request) {
rbd_assert(more);
rbd_assert(which < img_request->obj_request_count);
if (!obj_request_done_test(obj_request))
break;
more = rbd_img_obj_end_request(obj_request);
which++;
}
rbd_assert(more ^ (which == img_request->obj_request_count));
img_request->next_completion = which;
out:
spin_unlock_irq(&img_request->completion_lock);
rbd_img_request_put(img_request);
if (!more)
rbd_img_request_complete(img_request);
}
static void rbd_img_obj_request_fill(struct rbd_obj_request *obj_request,
struct ceph_osd_request *osd_request,
enum obj_operation_type op_type,
unsigned int num_ops)
{
struct rbd_img_request *img_request = obj_request->img_request;
struct rbd_device *rbd_dev = img_request->rbd_dev;
u64 object_size = rbd_obj_bytes(&rbd_dev->header);
u64 offset = obj_request->offset;
u64 length = obj_request->length;
u64 img_end;
u16 opcode;
if (op_type == OBJ_OP_DISCARD) {
if (!offset && length == object_size &&
(!img_request_layered_test(img_request) ||
!obj_request_overlaps_parent(obj_request))) {
opcode = CEPH_OSD_OP_DELETE;
} else if ((offset + length == object_size)) {
opcode = CEPH_OSD_OP_TRUNCATE;
} else {
down_read(&rbd_dev->header_rwsem);
img_end = rbd_dev->header.image_size;
up_read(&rbd_dev->header_rwsem);
if (obj_request->img_offset + length == img_end)
opcode = CEPH_OSD_OP_TRUNCATE;
else
opcode = CEPH_OSD_OP_ZERO;
}
} else if (op_type == OBJ_OP_WRITE) {
if (!offset && length == object_size)
opcode = CEPH_OSD_OP_WRITEFULL;
else
opcode = CEPH_OSD_OP_WRITE;
osd_req_op_alloc_hint_init(osd_request, num_ops,
object_size, object_size);
num_ops++;
} else {
opcode = CEPH_OSD_OP_READ;
}
if (opcode == CEPH_OSD_OP_DELETE)
osd_req_op_init(osd_request, num_ops, opcode, 0);
else
osd_req_op_extent_init(osd_request, num_ops, opcode,
offset, length, 0, 0);
if (obj_request->type == OBJ_REQUEST_BIO)
osd_req_op_extent_osd_data_bio(osd_request, num_ops,
obj_request->bio_list, length);
else if (obj_request->type == OBJ_REQUEST_PAGES)
osd_req_op_extent_osd_data_pages(osd_request, num_ops,
obj_request->pages, length,
offset & ~PAGE_MASK, false, false);
if (op_type == OBJ_OP_WRITE || op_type == OBJ_OP_DISCARD)
rbd_osd_req_format_write(obj_request);
else
rbd_osd_req_format_read(obj_request);
}
static int rbd_img_request_fill(struct rbd_img_request *img_request,
enum obj_request_type type,
void *data_desc)
{
struct rbd_device *rbd_dev = img_request->rbd_dev;
struct rbd_obj_request *obj_request = NULL;
struct rbd_obj_request *next_obj_request;
struct bio *bio_list = NULL;
unsigned int bio_offset = 0;
struct page **pages = NULL;
enum obj_operation_type op_type;
u64 img_offset;
u64 resid;
dout("%s: img %p type %d data_desc %p\n", __func__, img_request,
(int)type, data_desc);
img_offset = img_request->offset;
resid = img_request->length;
rbd_assert(resid > 0);
op_type = rbd_img_request_op_type(img_request);
if (type == OBJ_REQUEST_BIO) {
bio_list = data_desc;
rbd_assert(img_offset ==
bio_list->bi_iter.bi_sector << SECTOR_SHIFT);
} else if (type == OBJ_REQUEST_PAGES) {
pages = data_desc;
}
while (resid) {
struct ceph_osd_request *osd_req;
u64 object_no = img_offset >> rbd_dev->header.obj_order;
u64 offset = rbd_segment_offset(rbd_dev, img_offset);
u64 length = rbd_segment_length(rbd_dev, img_offset, resid);
obj_request = rbd_obj_request_create(type);
if (!obj_request)
goto out_unwind;
obj_request->object_no = object_no;
obj_request->offset = offset;
obj_request->length = length;
rbd_img_obj_request_add(img_request, obj_request);
if (type == OBJ_REQUEST_BIO) {
unsigned int clone_size;
rbd_assert(length <= (u64)UINT_MAX);
clone_size = (unsigned int)length;
obj_request->bio_list =
bio_chain_clone_range(&bio_list,
&bio_offset,
clone_size,
GFP_NOIO);
if (!obj_request->bio_list)
goto out_unwind;
} else if (type == OBJ_REQUEST_PAGES) {
unsigned int page_count;
obj_request->pages = pages;
page_count = (u32)calc_pages_for(offset, length);
obj_request->page_count = page_count;
if ((offset + length) & ~PAGE_MASK)
page_count--;
pages += page_count;
}
osd_req = rbd_osd_req_create(rbd_dev, op_type,
(op_type == OBJ_OP_WRITE) ? 2 : 1,
obj_request);
if (!osd_req)
goto out_unwind;
obj_request->osd_req = osd_req;
obj_request->callback = rbd_img_obj_callback;
obj_request->img_offset = img_offset;
rbd_img_obj_request_fill(obj_request, osd_req, op_type, 0);
img_offset += length;
resid -= length;
}
return 0;
out_unwind:
for_each_obj_request_safe(img_request, obj_request, next_obj_request)
rbd_img_obj_request_del(img_request, obj_request);
return -ENOMEM;
}
static void
rbd_osd_copyup_callback(struct rbd_obj_request *obj_request)
{
struct rbd_img_request *img_request;
struct rbd_device *rbd_dev;
struct page **pages;
u32 page_count;
dout("%s: obj %p\n", __func__, obj_request);
rbd_assert(obj_request->type == OBJ_REQUEST_BIO ||
obj_request->type == OBJ_REQUEST_NODATA);
rbd_assert(obj_request_img_data_test(obj_request));
img_request = obj_request->img_request;
rbd_assert(img_request);
rbd_dev = img_request->rbd_dev;
rbd_assert(rbd_dev);
pages = obj_request->copyup_pages;
rbd_assert(pages != NULL);
obj_request->copyup_pages = NULL;
page_count = obj_request->copyup_page_count;
rbd_assert(page_count);
obj_request->copyup_page_count = 0;
ceph_release_page_vector(pages, page_count);
if (!obj_request->result)
obj_request->xferred = obj_request->length;
obj_request_done_set(obj_request);
}
static void
rbd_img_obj_parent_read_full_callback(struct rbd_img_request *img_request)
{
struct rbd_obj_request *orig_request;
struct ceph_osd_request *osd_req;
struct rbd_device *rbd_dev;
struct page **pages;
enum obj_operation_type op_type;
u32 page_count;
int img_result;
u64 parent_length;
rbd_assert(img_request_child_test(img_request));
pages = img_request->copyup_pages;
rbd_assert(pages != NULL);
img_request->copyup_pages = NULL;
page_count = img_request->copyup_page_count;
rbd_assert(page_count);
img_request->copyup_page_count = 0;
orig_request = img_request->obj_request;
rbd_assert(orig_request != NULL);
rbd_assert(obj_request_type_valid(orig_request->type));
img_result = img_request->result;
parent_length = img_request->length;
rbd_assert(img_result || parent_length == img_request->xferred);
rbd_img_request_put(img_request);
rbd_assert(orig_request->img_request);
rbd_dev = orig_request->img_request->rbd_dev;
rbd_assert(rbd_dev);
if (!rbd_dev->parent_overlap) {
ceph_release_page_vector(pages, page_count);
rbd_obj_request_submit(orig_request);
return;
}
if (img_result)
goto out_err;
img_result = -ENOMEM;
osd_req = rbd_osd_req_create_copyup(orig_request);
if (!osd_req)
goto out_err;
rbd_osd_req_destroy(orig_request->osd_req);
orig_request->osd_req = osd_req;
orig_request->copyup_pages = pages;
orig_request->copyup_page_count = page_count;
osd_req_op_cls_init(osd_req, 0, CEPH_OSD_OP_CALL, "rbd", "copyup");
osd_req_op_cls_request_data_pages(osd_req, 0, pages, parent_length, 0,
false, false);
op_type = rbd_img_request_op_type(orig_request->img_request);
rbd_img_obj_request_fill(orig_request, osd_req, op_type, 1);
rbd_obj_request_submit(orig_request);
return;
out_err:
ceph_release_page_vector(pages, page_count);
rbd_obj_request_error(orig_request, img_result);
}
static int rbd_img_obj_parent_read_full(struct rbd_obj_request *obj_request)
{
struct rbd_device *rbd_dev = obj_request->img_request->rbd_dev;
struct rbd_img_request *parent_request = NULL;
u64 img_offset;
u64 length;
struct page **pages = NULL;
u32 page_count;
int result;
rbd_assert(rbd_dev->parent != NULL);
img_offset = obj_request->img_offset - obj_request->offset;
length = rbd_obj_bytes(&rbd_dev->header);
if (img_offset + length > rbd_dev->parent_overlap) {
rbd_assert(img_offset < rbd_dev->parent_overlap);
length = rbd_dev->parent_overlap - img_offset;
}
page_count = (u32)calc_pages_for(0, length);
pages = ceph_alloc_page_vector(page_count, GFP_KERNEL);
if (IS_ERR(pages)) {
result = PTR_ERR(pages);
pages = NULL;
goto out_err;
}
result = -ENOMEM;
parent_request = rbd_parent_request_create(obj_request,
img_offset, length);
if (!parent_request)
goto out_err;
result = rbd_img_request_fill(parent_request, OBJ_REQUEST_PAGES, pages);
if (result)
goto out_err;
parent_request->copyup_pages = pages;
parent_request->copyup_page_count = page_count;
parent_request->callback = rbd_img_obj_parent_read_full_callback;
result = rbd_img_request_submit(parent_request);
if (!result)
return 0;
parent_request->copyup_pages = NULL;
parent_request->copyup_page_count = 0;
parent_request->obj_request = NULL;
rbd_obj_request_put(obj_request);
out_err:
if (pages)
ceph_release_page_vector(pages, page_count);
if (parent_request)
rbd_img_request_put(parent_request);
return result;
}
static void rbd_img_obj_exists_callback(struct rbd_obj_request *obj_request)
{
struct rbd_obj_request *orig_request;
struct rbd_device *rbd_dev;
int result;
rbd_assert(!obj_request_img_data_test(obj_request));
orig_request = obj_request->obj_request;
obj_request->obj_request = NULL;
rbd_obj_request_put(orig_request);
rbd_assert(orig_request);
rbd_assert(orig_request->img_request);
result = obj_request->result;
obj_request->result = 0;
dout("%s: obj %p for obj %p result %d %llu/%llu\n", __func__,
obj_request, orig_request, result,
obj_request->xferred, obj_request->length);
rbd_obj_request_put(obj_request);
rbd_dev = orig_request->img_request->rbd_dev;
if (!rbd_dev->parent_overlap) {
rbd_obj_request_submit(orig_request);
return;
}
if (!result) {
obj_request_existence_set(orig_request, true);
} else if (result == -ENOENT) {
obj_request_existence_set(orig_request, false);
} else {
goto fail_orig_request;
}
result = rbd_img_obj_request_submit(orig_request);
if (result)
goto fail_orig_request;
return;
fail_orig_request:
rbd_obj_request_error(orig_request, result);
}
static int rbd_img_obj_exists_submit(struct rbd_obj_request *obj_request)
{
struct rbd_device *rbd_dev = obj_request->img_request->rbd_dev;
struct rbd_obj_request *stat_request;
struct page **pages;
u32 page_count;
size_t size;
int ret;
stat_request = rbd_obj_request_create(OBJ_REQUEST_PAGES);
if (!stat_request)
return -ENOMEM;
stat_request->object_no = obj_request->object_no;
stat_request->osd_req = rbd_osd_req_create(rbd_dev, OBJ_OP_READ, 1,
stat_request);
if (!stat_request->osd_req) {
ret = -ENOMEM;
goto fail_stat_request;
}
size = sizeof (__le64) + sizeof (__le32) + sizeof (__le32);
page_count = (u32)calc_pages_for(0, size);
pages = ceph_alloc_page_vector(page_count, GFP_KERNEL);
if (IS_ERR(pages)) {
ret = PTR_ERR(pages);
goto fail_stat_request;
}
osd_req_op_init(stat_request->osd_req, 0, CEPH_OSD_OP_STAT, 0);
osd_req_op_raw_data_in_pages(stat_request->osd_req, 0, pages, size, 0,
false, false);
rbd_obj_request_get(obj_request);
stat_request->obj_request = obj_request;
stat_request->pages = pages;
stat_request->page_count = page_count;
stat_request->callback = rbd_img_obj_exists_callback;
rbd_obj_request_submit(stat_request);
return 0;
fail_stat_request:
rbd_obj_request_put(stat_request);
return ret;
}
static bool img_obj_request_simple(struct rbd_obj_request *obj_request)
{
struct rbd_img_request *img_request = obj_request->img_request;
struct rbd_device *rbd_dev = img_request->rbd_dev;
if (!img_request_write_test(img_request) &&
!img_request_discard_test(img_request))
return true;
if (!img_request_layered_test(img_request))
return true;
if (!obj_request_overlaps_parent(obj_request))
return true;
if (!obj_request->offset &&
obj_request->length == rbd_obj_bytes(&rbd_dev->header))
return true;
if (obj_request_known_test(obj_request) &&
obj_request_exists_test(obj_request))
return true;
return false;
}
static int rbd_img_obj_request_submit(struct rbd_obj_request *obj_request)
{
rbd_assert(obj_request_img_data_test(obj_request));
rbd_assert(obj_request_type_valid(obj_request->type));
rbd_assert(obj_request->img_request);
if (img_obj_request_simple(obj_request)) {
rbd_obj_request_submit(obj_request);
return 0;
}
if (obj_request_known_test(obj_request))
return rbd_img_obj_parent_read_full(obj_request);
return rbd_img_obj_exists_submit(obj_request);
}
static int rbd_img_request_submit(struct rbd_img_request *img_request)
{
struct rbd_obj_request *obj_request;
struct rbd_obj_request *next_obj_request;
int ret = 0;
dout("%s: img %p\n", __func__, img_request);
rbd_img_request_get(img_request);
for_each_obj_request_safe(img_request, obj_request, next_obj_request) {
ret = rbd_img_obj_request_submit(obj_request);
if (ret)
goto out_put_ireq;
}
out_put_ireq:
rbd_img_request_put(img_request);
return ret;
}
static void rbd_img_parent_read_callback(struct rbd_img_request *img_request)
{
struct rbd_obj_request *obj_request;
struct rbd_device *rbd_dev;
u64 obj_end;
u64 img_xferred;
int img_result;
rbd_assert(img_request_child_test(img_request));
obj_request = img_request->obj_request;
img_xferred = img_request->xferred;
img_result = img_request->result;
rbd_img_request_put(img_request);
rbd_assert(obj_request);
rbd_assert(obj_request->img_request);
rbd_dev = obj_request->img_request->rbd_dev;
if (!rbd_dev->parent_overlap) {
rbd_obj_request_submit(obj_request);
return;
}
obj_request->result = img_result;
if (obj_request->result)
goto out;
rbd_assert(obj_request->img_offset < U64_MAX - obj_request->length);
obj_end = obj_request->img_offset + obj_request->length;
if (obj_end > rbd_dev->parent_overlap) {
u64 xferred = 0;
if (obj_request->img_offset < rbd_dev->parent_overlap)
xferred = rbd_dev->parent_overlap -
obj_request->img_offset;
obj_request->xferred = min(img_xferred, xferred);
} else {
obj_request->xferred = img_xferred;
}
out:
rbd_img_obj_request_read_callback(obj_request);
rbd_obj_request_complete(obj_request);
}
static void rbd_img_parent_read(struct rbd_obj_request *obj_request)
{
struct rbd_img_request *img_request;
int result;
rbd_assert(obj_request_img_data_test(obj_request));
rbd_assert(obj_request->img_request != NULL);
rbd_assert(obj_request->result == (s32) -ENOENT);
rbd_assert(obj_request_type_valid(obj_request->type));
img_request = rbd_parent_request_create(obj_request,
obj_request->img_offset,
obj_request->length);
result = -ENOMEM;
if (!img_request)
goto out_err;
if (obj_request->type == OBJ_REQUEST_BIO)
result = rbd_img_request_fill(img_request, OBJ_REQUEST_BIO,
obj_request->bio_list);
else
result = rbd_img_request_fill(img_request, OBJ_REQUEST_PAGES,
obj_request->pages);
if (result)
goto out_err;
img_request->callback = rbd_img_parent_read_callback;
result = rbd_img_request_submit(img_request);
if (result)
goto out_err;
return;
out_err:
if (img_request)
rbd_img_request_put(img_request);
obj_request->result = result;
obj_request->xferred = 0;
obj_request_done_set(obj_request);
}
static bool rbd_cid_equal(const struct rbd_client_id *lhs,
const struct rbd_client_id *rhs)
{
return lhs->gid == rhs->gid && lhs->handle == rhs->handle;
}
static struct rbd_client_id rbd_get_cid(struct rbd_device *rbd_dev)
{
struct rbd_client_id cid;
mutex_lock(&rbd_dev->watch_mutex);
cid.gid = ceph_client_gid(rbd_dev->rbd_client->client);
cid.handle = rbd_dev->watch_cookie;
mutex_unlock(&rbd_dev->watch_mutex);
return cid;
}
static void rbd_set_owner_cid(struct rbd_device *rbd_dev,
const struct rbd_client_id *cid)
{
dout("%s rbd_dev %p %llu-%llu -> %llu-%llu\n", __func__, rbd_dev,
rbd_dev->owner_cid.gid, rbd_dev->owner_cid.handle,
cid->gid, cid->handle);
rbd_dev->owner_cid = *cid;
}
static void format_lock_cookie(struct rbd_device *rbd_dev, char *buf)
{
mutex_lock(&rbd_dev->watch_mutex);
sprintf(buf, "%s %llu", RBD_LOCK_COOKIE_PREFIX, rbd_dev->watch_cookie);
mutex_unlock(&rbd_dev->watch_mutex);
}
static int rbd_lock(struct rbd_device *rbd_dev)
{
struct ceph_osd_client *osdc = &rbd_dev->rbd_client->client->osdc;
struct rbd_client_id cid = rbd_get_cid(rbd_dev);
char cookie[32];
int ret;
WARN_ON(__rbd_is_lock_owner(rbd_dev) ||
rbd_dev->lock_cookie[0] != '\0');
format_lock_cookie(rbd_dev, cookie);
ret = ceph_cls_lock(osdc, &rbd_dev->header_oid, &rbd_dev->header_oloc,
RBD_LOCK_NAME, CEPH_CLS_LOCK_EXCLUSIVE, cookie,
RBD_LOCK_TAG, "", 0);
if (ret)
return ret;
rbd_dev->lock_state = RBD_LOCK_STATE_LOCKED;
strcpy(rbd_dev->lock_cookie, cookie);
rbd_set_owner_cid(rbd_dev, &cid);
queue_work(rbd_dev->task_wq, &rbd_dev->acquired_lock_work);
return 0;
}
static void rbd_unlock(struct rbd_device *rbd_dev)
{
struct ceph_osd_client *osdc = &rbd_dev->rbd_client->client->osdc;
int ret;
WARN_ON(!__rbd_is_lock_owner(rbd_dev) ||
rbd_dev->lock_cookie[0] == '\0');
ret = ceph_cls_unlock(osdc, &rbd_dev->header_oid, &rbd_dev->header_oloc,
RBD_LOCK_NAME, rbd_dev->lock_cookie);
if (ret && ret != -ENOENT)
rbd_warn(rbd_dev, "failed to unlock: %d", ret);
rbd_dev->lock_state = RBD_LOCK_STATE_UNLOCKED;
rbd_dev->lock_cookie[0] = '\0';
rbd_set_owner_cid(rbd_dev, &rbd_empty_cid);
queue_work(rbd_dev->task_wq, &rbd_dev->released_lock_work);
}
static int __rbd_notify_op_lock(struct rbd_device *rbd_dev,
enum rbd_notify_op notify_op,
struct page ***preply_pages,
size_t *preply_len)
{
struct ceph_osd_client *osdc = &rbd_dev->rbd_client->client->osdc;
struct rbd_client_id cid = rbd_get_cid(rbd_dev);
int buf_size = 4 + 8 + 8 + CEPH_ENCODING_START_BLK_LEN;
char buf[buf_size];
void *p = buf;
dout("%s rbd_dev %p notify_op %d\n", __func__, rbd_dev, notify_op);
ceph_start_encoding(&p, 2, 1, buf_size - CEPH_ENCODING_START_BLK_LEN);
ceph_encode_32(&p, notify_op);
ceph_encode_64(&p, cid.gid);
ceph_encode_64(&p, cid.handle);
return ceph_osdc_notify(osdc, &rbd_dev->header_oid,
&rbd_dev->header_oloc, buf, buf_size,
RBD_NOTIFY_TIMEOUT, preply_pages, preply_len);
}
static void rbd_notify_op_lock(struct rbd_device *rbd_dev,
enum rbd_notify_op notify_op)
{
struct page **reply_pages;
size_t reply_len;
__rbd_notify_op_lock(rbd_dev, notify_op, &reply_pages, &reply_len);
ceph_release_page_vector(reply_pages, calc_pages_for(0, reply_len));
}
static void rbd_notify_acquired_lock(struct work_struct *work)
{
struct rbd_device *rbd_dev = container_of(work, struct rbd_device,
acquired_lock_work);
rbd_notify_op_lock(rbd_dev, RBD_NOTIFY_OP_ACQUIRED_LOCK);
}
static void rbd_notify_released_lock(struct work_struct *work)
{
struct rbd_device *rbd_dev = container_of(work, struct rbd_device,
released_lock_work);
rbd_notify_op_lock(rbd_dev, RBD_NOTIFY_OP_RELEASED_LOCK);
}
static int rbd_request_lock(struct rbd_device *rbd_dev)
{
struct page **reply_pages;
size_t reply_len;
bool lock_owner_responded = false;
int ret;
dout("%s rbd_dev %p\n", __func__, rbd_dev);
ret = __rbd_notify_op_lock(rbd_dev, RBD_NOTIFY_OP_REQUEST_LOCK,
&reply_pages, &reply_len);
if (ret && ret != -ETIMEDOUT) {
rbd_warn(rbd_dev, "failed to request lock: %d", ret);
goto out;
}
if (reply_len > 0 && reply_len <= PAGE_SIZE) {
void *p = page_address(reply_pages[0]);
void *const end = p + reply_len;
u32 n;
ceph_decode_32_safe(&p, end, n, e_inval);
while (n--) {
u8 struct_v;
u32 len;
ceph_decode_need(&p, end, 8 + 8, e_inval);
p += 8 + 8;
ceph_decode_32_safe(&p, end, len, e_inval);
if (!len)
continue;
if (lock_owner_responded) {
rbd_warn(rbd_dev,
"duplicate lock owners detected");
ret = -EIO;
goto out;
}
lock_owner_responded = true;
ret = ceph_start_decoding(&p, end, 1, "ResponseMessage",
&struct_v, &len);
if (ret) {
rbd_warn(rbd_dev,
"failed to decode ResponseMessage: %d",
ret);
goto e_inval;
}
ret = ceph_decode_32(&p);
}
}
if (!lock_owner_responded) {
rbd_warn(rbd_dev, "no lock owners detected");
ret = -ETIMEDOUT;
}
out:
ceph_release_page_vector(reply_pages, calc_pages_for(0, reply_len));
return ret;
e_inval:
ret = -EINVAL;
goto out;
}
static void wake_requests(struct rbd_device *rbd_dev, bool wake_all)
{
dout("%s rbd_dev %p wake_all %d\n", __func__, rbd_dev, wake_all);
cancel_delayed_work(&rbd_dev->lock_dwork);
if (wake_all)
wake_up_all(&rbd_dev->lock_waitq);
else
wake_up(&rbd_dev->lock_waitq);
}
static int get_lock_owner_info(struct rbd_device *rbd_dev,
struct ceph_locker **lockers, u32 *num_lockers)
{
struct ceph_osd_client *osdc = &rbd_dev->rbd_client->client->osdc;
u8 lock_type;
char *lock_tag;
int ret;
dout("%s rbd_dev %p\n", __func__, rbd_dev);
ret = ceph_cls_lock_info(osdc, &rbd_dev->header_oid,
&rbd_dev->header_oloc, RBD_LOCK_NAME,
&lock_type, &lock_tag, lockers, num_lockers);
if (ret)
return ret;
if (*num_lockers == 0) {
dout("%s rbd_dev %p no lockers detected\n", __func__, rbd_dev);
goto out;
}
if (strcmp(lock_tag, RBD_LOCK_TAG)) {
rbd_warn(rbd_dev, "locked by external mechanism, tag %s",
lock_tag);
ret = -EBUSY;
goto out;
}
if (lock_type == CEPH_CLS_LOCK_SHARED) {
rbd_warn(rbd_dev, "shared lock type detected");
ret = -EBUSY;
goto out;
}
if (strncmp((*lockers)[0].id.cookie, RBD_LOCK_COOKIE_PREFIX,
strlen(RBD_LOCK_COOKIE_PREFIX))) {
rbd_warn(rbd_dev, "locked by external mechanism, cookie %s",
(*lockers)[0].id.cookie);
ret = -EBUSY;
goto out;
}
out:
kfree(lock_tag);
return ret;
}
static int find_watcher(struct rbd_device *rbd_dev,
const struct ceph_locker *locker)
{
struct ceph_osd_client *osdc = &rbd_dev->rbd_client->client->osdc;
struct ceph_watch_item *watchers;
u32 num_watchers;
u64 cookie;
int i;
int ret;
ret = ceph_osdc_list_watchers(osdc, &rbd_dev->header_oid,
&rbd_dev->header_oloc, &watchers,
&num_watchers);
if (ret)
return ret;
sscanf(locker->id.cookie, RBD_LOCK_COOKIE_PREFIX " %llu", &cookie);
for (i = 0; i < num_watchers; i++) {
if (!memcmp(&watchers[i].addr, &locker->info.addr,
sizeof(locker->info.addr)) &&
watchers[i].cookie == cookie) {
struct rbd_client_id cid = {
.gid = le64_to_cpu(watchers[i].name.num),
.handle = cookie,
};
dout("%s rbd_dev %p found cid %llu-%llu\n", __func__,
rbd_dev, cid.gid, cid.handle);
rbd_set_owner_cid(rbd_dev, &cid);
ret = 1;
goto out;
}
}
dout("%s rbd_dev %p no watchers\n", __func__, rbd_dev);
ret = 0;
out:
kfree(watchers);
return ret;
}
static int rbd_try_lock(struct rbd_device *rbd_dev)
{
struct ceph_client *client = rbd_dev->rbd_client->client;
struct ceph_locker *lockers;
u32 num_lockers;
int ret;
for (;;) {
ret = rbd_lock(rbd_dev);
if (ret != -EBUSY)
return ret;
ret = get_lock_owner_info(rbd_dev, &lockers, &num_lockers);
if (ret)
return ret;
if (num_lockers == 0)
goto again;
ret = find_watcher(rbd_dev, lockers);
if (ret) {
if (ret > 0)
ret = 0;
goto out;
}
rbd_warn(rbd_dev, "%s%llu seems dead, breaking lock",
ENTITY_NAME(lockers[0].id.name));
ret = ceph_monc_blacklist_add(&client->monc,
&lockers[0].info.addr);
if (ret) {
rbd_warn(rbd_dev, "blacklist of %s%llu failed: %d",
ENTITY_NAME(lockers[0].id.name), ret);
goto out;
}
ret = ceph_cls_break_lock(&client->osdc, &rbd_dev->header_oid,
&rbd_dev->header_oloc, RBD_LOCK_NAME,
lockers[0].id.cookie,
&lockers[0].id.name);
if (ret && ret != -ENOENT)
goto out;
again:
ceph_free_lockers(lockers, num_lockers);
}
out:
ceph_free_lockers(lockers, num_lockers);
return ret;
}
static enum rbd_lock_state rbd_try_acquire_lock(struct rbd_device *rbd_dev,
int *pret)
{
enum rbd_lock_state lock_state;
down_read(&rbd_dev->lock_rwsem);
dout("%s rbd_dev %p read lock_state %d\n", __func__, rbd_dev,
rbd_dev->lock_state);
if (__rbd_is_lock_owner(rbd_dev)) {
lock_state = rbd_dev->lock_state;
up_read(&rbd_dev->lock_rwsem);
return lock_state;
}
up_read(&rbd_dev->lock_rwsem);
down_write(&rbd_dev->lock_rwsem);
dout("%s rbd_dev %p write lock_state %d\n", __func__, rbd_dev,
rbd_dev->lock_state);
if (!__rbd_is_lock_owner(rbd_dev)) {
*pret = rbd_try_lock(rbd_dev);
if (*pret)
rbd_warn(rbd_dev, "failed to acquire lock: %d", *pret);
}
lock_state = rbd_dev->lock_state;
up_write(&rbd_dev->lock_rwsem);
return lock_state;
}
static void rbd_acquire_lock(struct work_struct *work)
{
struct rbd_device *rbd_dev = container_of(to_delayed_work(work),
struct rbd_device, lock_dwork);
enum rbd_lock_state lock_state;
int ret;
dout("%s rbd_dev %p\n", __func__, rbd_dev);
again:
lock_state = rbd_try_acquire_lock(rbd_dev, &ret);
if (lock_state != RBD_LOCK_STATE_UNLOCKED || ret == -EBLACKLISTED) {
if (lock_state == RBD_LOCK_STATE_LOCKED)
wake_requests(rbd_dev, true);
dout("%s rbd_dev %p lock_state %d ret %d - done\n", __func__,
rbd_dev, lock_state, ret);
return;
}
ret = rbd_request_lock(rbd_dev);
if (ret == -ETIMEDOUT) {
goto again;
} else if (ret == -EROFS) {
rbd_warn(rbd_dev, "peer will not release lock");
if (!(rbd_dev->disk->flags & GENHD_FL_UP)) {
set_bit(RBD_DEV_FLAG_BLACKLISTED, &rbd_dev->flags);
wake_requests(rbd_dev, false);
}
} else if (ret < 0) {
rbd_warn(rbd_dev, "error requesting lock: %d", ret);
mod_delayed_work(rbd_dev->task_wq, &rbd_dev->lock_dwork,
RBD_RETRY_DELAY);
} else {
dout("%s rbd_dev %p requeueing lock_dwork\n", __func__,
rbd_dev);
mod_delayed_work(rbd_dev->task_wq, &rbd_dev->lock_dwork,
msecs_to_jiffies(2 * RBD_NOTIFY_TIMEOUT * MSEC_PER_SEC));
}
}
static bool rbd_release_lock(struct rbd_device *rbd_dev)
{
dout("%s rbd_dev %p read lock_state %d\n", __func__, rbd_dev,
rbd_dev->lock_state);
if (rbd_dev->lock_state != RBD_LOCK_STATE_LOCKED)
return false;
rbd_dev->lock_state = RBD_LOCK_STATE_RELEASING;
downgrade_write(&rbd_dev->lock_rwsem);
ceph_osdc_sync(&rbd_dev->rbd_client->client->osdc);
up_read(&rbd_dev->lock_rwsem);
down_write(&rbd_dev->lock_rwsem);
dout("%s rbd_dev %p write lock_state %d\n", __func__, rbd_dev,
rbd_dev->lock_state);
if (rbd_dev->lock_state != RBD_LOCK_STATE_RELEASING)
return false;
rbd_unlock(rbd_dev);
cancel_delayed_work(&rbd_dev->lock_dwork);
return true;
}
static void rbd_release_lock_work(struct work_struct *work)
{
struct rbd_device *rbd_dev = container_of(work, struct rbd_device,
unlock_work);
down_write(&rbd_dev->lock_rwsem);
rbd_release_lock(rbd_dev);
up_write(&rbd_dev->lock_rwsem);
}
static void rbd_handle_acquired_lock(struct rbd_device *rbd_dev, u8 struct_v,
void **p)
{
struct rbd_client_id cid = { 0 };
if (struct_v >= 2) {
cid.gid = ceph_decode_64(p);
cid.handle = ceph_decode_64(p);
}
dout("%s rbd_dev %p cid %llu-%llu\n", __func__, rbd_dev, cid.gid,
cid.handle);
if (!rbd_cid_equal(&cid, &rbd_empty_cid)) {
down_write(&rbd_dev->lock_rwsem);
if (rbd_cid_equal(&cid, &rbd_dev->owner_cid)) {
up_write(&rbd_dev->lock_rwsem);
return;
}
rbd_set_owner_cid(rbd_dev, &cid);
downgrade_write(&rbd_dev->lock_rwsem);
} else {
down_read(&rbd_dev->lock_rwsem);
}
if (!__rbd_is_lock_owner(rbd_dev))
wake_requests(rbd_dev, false);
up_read(&rbd_dev->lock_rwsem);
}
static void rbd_handle_released_lock(struct rbd_device *rbd_dev, u8 struct_v,
void **p)
{
struct rbd_client_id cid = { 0 };
if (struct_v >= 2) {
cid.gid = ceph_decode_64(p);
cid.handle = ceph_decode_64(p);
}
dout("%s rbd_dev %p cid %llu-%llu\n", __func__, rbd_dev, cid.gid,
cid.handle);
if (!rbd_cid_equal(&cid, &rbd_empty_cid)) {
down_write(&rbd_dev->lock_rwsem);
if (!rbd_cid_equal(&cid, &rbd_dev->owner_cid)) {
dout("%s rbd_dev %p unexpected owner, cid %llu-%llu != owner_cid %llu-%llu\n",
__func__, rbd_dev, cid.gid, cid.handle,
rbd_dev->owner_cid.gid, rbd_dev->owner_cid.handle);
up_write(&rbd_dev->lock_rwsem);
return;
}
rbd_set_owner_cid(rbd_dev, &rbd_empty_cid);
downgrade_write(&rbd_dev->lock_rwsem);
} else {
down_read(&rbd_dev->lock_rwsem);
}
if (!__rbd_is_lock_owner(rbd_dev))
wake_requests(rbd_dev, false);
up_read(&rbd_dev->lock_rwsem);
}
static int rbd_handle_request_lock(struct rbd_device *rbd_dev, u8 struct_v,
void **p)
{
struct rbd_client_id my_cid = rbd_get_cid(rbd_dev);
struct rbd_client_id cid = { 0 };
int result = 1;
if (struct_v >= 2) {
cid.gid = ceph_decode_64(p);
cid.handle = ceph_decode_64(p);
}
dout("%s rbd_dev %p cid %llu-%llu\n", __func__, rbd_dev, cid.gid,
cid.handle);
if (rbd_cid_equal(&cid, &my_cid))
return result;
down_read(&rbd_dev->lock_rwsem);
if (__rbd_is_lock_owner(rbd_dev)) {
if (rbd_dev->lock_state == RBD_LOCK_STATE_LOCKED &&
rbd_cid_equal(&rbd_dev->owner_cid, &rbd_empty_cid))
goto out_unlock;
result = 0;
if (rbd_dev->lock_state == RBD_LOCK_STATE_LOCKED) {
if (!rbd_dev->opts->exclusive) {
dout("%s rbd_dev %p queueing unlock_work\n",
__func__, rbd_dev);
queue_work(rbd_dev->task_wq,
&rbd_dev->unlock_work);
} else {
result = -EROFS;
}
}
}
out_unlock:
up_read(&rbd_dev->lock_rwsem);
return result;
}
static void __rbd_acknowledge_notify(struct rbd_device *rbd_dev,
u64 notify_id, u64 cookie, s32 *result)
{
struct ceph_osd_client *osdc = &rbd_dev->rbd_client->client->osdc;
int buf_size = 4 + CEPH_ENCODING_START_BLK_LEN;
char buf[buf_size];
int ret;
if (result) {
void *p = buf;
ceph_start_encoding(&p, 1, 1,
buf_size - CEPH_ENCODING_START_BLK_LEN);
ceph_encode_32(&p, *result);
} else {
buf_size = 0;
}
ret = ceph_osdc_notify_ack(osdc, &rbd_dev->header_oid,
&rbd_dev->header_oloc, notify_id, cookie,
buf, buf_size);
if (ret)
rbd_warn(rbd_dev, "acknowledge_notify failed: %d", ret);
}
static void rbd_acknowledge_notify(struct rbd_device *rbd_dev, u64 notify_id,
u64 cookie)
{
dout("%s rbd_dev %p\n", __func__, rbd_dev);
__rbd_acknowledge_notify(rbd_dev, notify_id, cookie, NULL);
}
static void rbd_acknowledge_notify_result(struct rbd_device *rbd_dev,
u64 notify_id, u64 cookie, s32 result)
{
dout("%s rbd_dev %p result %d\n", __func__, rbd_dev, result);
__rbd_acknowledge_notify(rbd_dev, notify_id, cookie, &result);
}
static void rbd_watch_cb(void *arg, u64 notify_id, u64 cookie,
u64 notifier_id, void *data, size_t data_len)
{
struct rbd_device *rbd_dev = arg;
void *p = data;
void *const end = p + data_len;
u8 struct_v = 0;
u32 len;
u32 notify_op;
int ret;
dout("%s rbd_dev %p cookie %llu notify_id %llu data_len %zu\n",
__func__, rbd_dev, cookie, notify_id, data_len);
if (data_len) {
ret = ceph_start_decoding(&p, end, 1, "NotifyMessage",
&struct_v, &len);
if (ret) {
rbd_warn(rbd_dev, "failed to decode NotifyMessage: %d",
ret);
return;
}
notify_op = ceph_decode_32(&p);
} else {
notify_op = RBD_NOTIFY_OP_HEADER_UPDATE;
len = 0;
}
dout("%s rbd_dev %p notify_op %u\n", __func__, rbd_dev, notify_op);
switch (notify_op) {
case RBD_NOTIFY_OP_ACQUIRED_LOCK:
rbd_handle_acquired_lock(rbd_dev, struct_v, &p);
rbd_acknowledge_notify(rbd_dev, notify_id, cookie);
break;
case RBD_NOTIFY_OP_RELEASED_LOCK:
rbd_handle_released_lock(rbd_dev, struct_v, &p);
rbd_acknowledge_notify(rbd_dev, notify_id, cookie);
break;
case RBD_NOTIFY_OP_REQUEST_LOCK:
ret = rbd_handle_request_lock(rbd_dev, struct_v, &p);
if (ret <= 0)
rbd_acknowledge_notify_result(rbd_dev, notify_id,
cookie, ret);
else
rbd_acknowledge_notify(rbd_dev, notify_id, cookie);
break;
case RBD_NOTIFY_OP_HEADER_UPDATE:
ret = rbd_dev_refresh(rbd_dev);
if (ret)
rbd_warn(rbd_dev, "refresh failed: %d", ret);
rbd_acknowledge_notify(rbd_dev, notify_id, cookie);
break;
default:
if (rbd_is_lock_owner(rbd_dev))
rbd_acknowledge_notify_result(rbd_dev, notify_id,
cookie, -EOPNOTSUPP);
else
rbd_acknowledge_notify(rbd_dev, notify_id, cookie);
break;
}
}
static void rbd_watch_errcb(void *arg, u64 cookie, int err)
{
struct rbd_device *rbd_dev = arg;
rbd_warn(rbd_dev, "encountered watch error: %d", err);
down_write(&rbd_dev->lock_rwsem);
rbd_set_owner_cid(rbd_dev, &rbd_empty_cid);
up_write(&rbd_dev->lock_rwsem);
mutex_lock(&rbd_dev->watch_mutex);
if (rbd_dev->watch_state == RBD_WATCH_STATE_REGISTERED) {
__rbd_unregister_watch(rbd_dev);
rbd_dev->watch_state = RBD_WATCH_STATE_ERROR;
queue_delayed_work(rbd_dev->task_wq, &rbd_dev->watch_dwork, 0);
}
mutex_unlock(&rbd_dev->watch_mutex);
}
static int __rbd_register_watch(struct rbd_device *rbd_dev)
{
struct ceph_osd_client *osdc = &rbd_dev->rbd_client->client->osdc;
struct ceph_osd_linger_request *handle;
rbd_assert(!rbd_dev->watch_handle);
dout("%s rbd_dev %p\n", __func__, rbd_dev);
handle = ceph_osdc_watch(osdc, &rbd_dev->header_oid,
&rbd_dev->header_oloc, rbd_watch_cb,
rbd_watch_errcb, rbd_dev);
if (IS_ERR(handle))
return PTR_ERR(handle);
rbd_dev->watch_handle = handle;
return 0;
}
static void __rbd_unregister_watch(struct rbd_device *rbd_dev)
{
struct ceph_osd_client *osdc = &rbd_dev->rbd_client->client->osdc;
int ret;
rbd_assert(rbd_dev->watch_handle);
dout("%s rbd_dev %p\n", __func__, rbd_dev);
ret = ceph_osdc_unwatch(osdc, rbd_dev->watch_handle);
if (ret)
rbd_warn(rbd_dev, "failed to unwatch: %d", ret);
rbd_dev->watch_handle = NULL;
}
static int rbd_register_watch(struct rbd_device *rbd_dev)
{
int ret;
mutex_lock(&rbd_dev->watch_mutex);
rbd_assert(rbd_dev->watch_state == RBD_WATCH_STATE_UNREGISTERED);
ret = __rbd_register_watch(rbd_dev);
if (ret)
goto out;
rbd_dev->watch_state = RBD_WATCH_STATE_REGISTERED;
rbd_dev->watch_cookie = rbd_dev->watch_handle->linger_id;
out:
mutex_unlock(&rbd_dev->watch_mutex);
return ret;
}
static void cancel_tasks_sync(struct rbd_device *rbd_dev)
{
dout("%s rbd_dev %p\n", __func__, rbd_dev);
cancel_delayed_work_sync(&rbd_dev->watch_dwork);
cancel_work_sync(&rbd_dev->acquired_lock_work);
cancel_work_sync(&rbd_dev->released_lock_work);
cancel_delayed_work_sync(&rbd_dev->lock_dwork);
cancel_work_sync(&rbd_dev->unlock_work);
}
static void rbd_unregister_watch(struct rbd_device *rbd_dev)
{
WARN_ON(waitqueue_active(&rbd_dev->lock_waitq));
cancel_tasks_sync(rbd_dev);
mutex_lock(&rbd_dev->watch_mutex);
if (rbd_dev->watch_state == RBD_WATCH_STATE_REGISTERED)
__rbd_unregister_watch(rbd_dev);
rbd_dev->watch_state = RBD_WATCH_STATE_UNREGISTERED;
mutex_unlock(&rbd_dev->watch_mutex);
ceph_osdc_flush_notifies(&rbd_dev->rbd_client->client->osdc);
}
static void rbd_reacquire_lock(struct rbd_device *rbd_dev)
{
struct ceph_osd_client *osdc = &rbd_dev->rbd_client->client->osdc;
char cookie[32];
int ret;
WARN_ON(rbd_dev->lock_state != RBD_LOCK_STATE_LOCKED);
format_lock_cookie(rbd_dev, cookie);
ret = ceph_cls_set_cookie(osdc, &rbd_dev->header_oid,
&rbd_dev->header_oloc, RBD_LOCK_NAME,
CEPH_CLS_LOCK_EXCLUSIVE, rbd_dev->lock_cookie,
RBD_LOCK_TAG, cookie);
if (ret) {
if (ret != -EOPNOTSUPP)
rbd_warn(rbd_dev, "failed to update lock cookie: %d",
ret);
if (rbd_release_lock(rbd_dev))
queue_delayed_work(rbd_dev->task_wq,
&rbd_dev->lock_dwork, 0);
} else {
strcpy(rbd_dev->lock_cookie, cookie);
}
}
static void rbd_reregister_watch(struct work_struct *work)
{
struct rbd_device *rbd_dev = container_of(to_delayed_work(work),
struct rbd_device, watch_dwork);
int ret;
dout("%s rbd_dev %p\n", __func__, rbd_dev);
mutex_lock(&rbd_dev->watch_mutex);
if (rbd_dev->watch_state != RBD_WATCH_STATE_ERROR) {
mutex_unlock(&rbd_dev->watch_mutex);
return;
}
ret = __rbd_register_watch(rbd_dev);
if (ret) {
rbd_warn(rbd_dev, "failed to reregister watch: %d", ret);
if (ret == -EBLACKLISTED || ret == -ENOENT) {
set_bit(RBD_DEV_FLAG_BLACKLISTED, &rbd_dev->flags);
wake_requests(rbd_dev, true);
} else {
queue_delayed_work(rbd_dev->task_wq,
&rbd_dev->watch_dwork,
RBD_RETRY_DELAY);
}
mutex_unlock(&rbd_dev->watch_mutex);
return;
}
rbd_dev->watch_state = RBD_WATCH_STATE_REGISTERED;
rbd_dev->watch_cookie = rbd_dev->watch_handle->linger_id;
mutex_unlock(&rbd_dev->watch_mutex);
down_write(&rbd_dev->lock_rwsem);
if (rbd_dev->lock_state == RBD_LOCK_STATE_LOCKED)
rbd_reacquire_lock(rbd_dev);
up_write(&rbd_dev->lock_rwsem);
ret = rbd_dev_refresh(rbd_dev);
if (ret)
rbd_warn(rbd_dev, "reregisteration refresh failed: %d", ret);
}
static int rbd_obj_method_sync(struct rbd_device *rbd_dev,
struct ceph_object_id *oid,
struct ceph_object_locator *oloc,
const char *method_name,
const void *outbound,
size_t outbound_size,
void *inbound,
size_t inbound_size)
{
struct ceph_osd_client *osdc = &rbd_dev->rbd_client->client->osdc;
struct page *req_page = NULL;
struct page *reply_page;
int ret;
if (outbound) {
if (outbound_size > PAGE_SIZE)
return -E2BIG;
req_page = alloc_page(GFP_KERNEL);
if (!req_page)
return -ENOMEM;
memcpy(page_address(req_page), outbound, outbound_size);
}
reply_page = alloc_page(GFP_KERNEL);
if (!reply_page) {
if (req_page)
__free_page(req_page);
return -ENOMEM;
}
ret = ceph_osdc_call(osdc, oid, oloc, RBD_DRV_NAME, method_name,
CEPH_OSD_FLAG_READ, req_page, outbound_size,
reply_page, &inbound_size);
if (!ret) {
memcpy(inbound, page_address(reply_page), inbound_size);
ret = inbound_size;
}
if (req_page)
__free_page(req_page);
__free_page(reply_page);
return ret;
}
static void rbd_wait_state_locked(struct rbd_device *rbd_dev)
{
DEFINE_WAIT(wait);
do {
dout("%s rbd_dev %p queueing lock_dwork\n", __func__, rbd_dev);
queue_delayed_work(rbd_dev->task_wq, &rbd_dev->lock_dwork, 0);
prepare_to_wait_exclusive(&rbd_dev->lock_waitq, &wait,
TASK_UNINTERRUPTIBLE);
up_read(&rbd_dev->lock_rwsem);
schedule();
down_read(&rbd_dev->lock_rwsem);
} while (rbd_dev->lock_state != RBD_LOCK_STATE_LOCKED &&
!test_bit(RBD_DEV_FLAG_BLACKLISTED, &rbd_dev->flags));
finish_wait(&rbd_dev->lock_waitq, &wait);
}
static void rbd_queue_workfn(struct work_struct *work)
{
struct request *rq = blk_mq_rq_from_pdu(work);
struct rbd_device *rbd_dev = rq->q->queuedata;
struct rbd_img_request *img_request;
struct ceph_snap_context *snapc = NULL;
u64 offset = (u64)blk_rq_pos(rq) << SECTOR_SHIFT;
u64 length = blk_rq_bytes(rq);
enum obj_operation_type op_type;
u64 mapping_size;
bool must_be_locked;
int result;
switch (req_op(rq)) {
case REQ_OP_DISCARD:
case REQ_OP_WRITE_ZEROES:
op_type = OBJ_OP_DISCARD;
break;
case REQ_OP_WRITE:
op_type = OBJ_OP_WRITE;
break;
case REQ_OP_READ:
op_type = OBJ_OP_READ;
break;
default:
dout("%s: non-fs request type %d\n", __func__, req_op(rq));
result = -EIO;
goto err;
}
if (!length) {
dout("%s: zero-length request\n", __func__);
result = 0;
goto err_rq;
}
if (op_type != OBJ_OP_READ) {
if (rbd_dev->mapping.read_only) {
result = -EROFS;
goto err_rq;
}
rbd_assert(rbd_dev->spec->snap_id == CEPH_NOSNAP);
}
if (!test_bit(RBD_DEV_FLAG_EXISTS, &rbd_dev->flags)) {
dout("request for non-existent snapshot");
rbd_assert(rbd_dev->spec->snap_id != CEPH_NOSNAP);
result = -ENXIO;
goto err_rq;
}
if (offset && length > U64_MAX - offset + 1) {
rbd_warn(rbd_dev, "bad request range (%llu~%llu)", offset,
length);
result = -EINVAL;
goto err_rq;
}
blk_mq_start_request(rq);
down_read(&rbd_dev->header_rwsem);
mapping_size = rbd_dev->mapping.size;
if (op_type != OBJ_OP_READ) {
snapc = rbd_dev->header.snapc;
ceph_get_snap_context(snapc);
}
up_read(&rbd_dev->header_rwsem);
if (offset + length > mapping_size) {
rbd_warn(rbd_dev, "beyond EOD (%llu~%llu > %llu)", offset,
length, mapping_size);
result = -EIO;
goto err_rq;
}
must_be_locked =
(rbd_dev->header.features & RBD_FEATURE_EXCLUSIVE_LOCK) &&
(op_type != OBJ_OP_READ || rbd_dev->opts->lock_on_read);
if (must_be_locked) {
down_read(&rbd_dev->lock_rwsem);
if (rbd_dev->lock_state != RBD_LOCK_STATE_LOCKED &&
!test_bit(RBD_DEV_FLAG_BLACKLISTED, &rbd_dev->flags)) {
if (rbd_dev->opts->exclusive) {
rbd_warn(rbd_dev, "exclusive lock required");
result = -EROFS;
goto err_unlock;
}
rbd_wait_state_locked(rbd_dev);
}
if (test_bit(RBD_DEV_FLAG_BLACKLISTED, &rbd_dev->flags)) {
result = -EBLACKLISTED;
goto err_unlock;
}
}
img_request = rbd_img_request_create(rbd_dev, offset, length, op_type,
snapc);
if (!img_request) {
result = -ENOMEM;
goto err_unlock;
}
img_request->rq = rq;
snapc = NULL;
if (op_type == OBJ_OP_DISCARD)
result = rbd_img_request_fill(img_request, OBJ_REQUEST_NODATA,
NULL);
else
result = rbd_img_request_fill(img_request, OBJ_REQUEST_BIO,
rq->bio);
if (result)
goto err_img_request;
result = rbd_img_request_submit(img_request);
if (result)
goto err_img_request;
if (must_be_locked)
up_read(&rbd_dev->lock_rwsem);
return;
err_img_request:
rbd_img_request_put(img_request);
err_unlock:
if (must_be_locked)
up_read(&rbd_dev->lock_rwsem);
err_rq:
if (result)
rbd_warn(rbd_dev, "%s %llx at %llx result %d",
obj_op_name(op_type), length, offset, result);
ceph_put_snap_context(snapc);
err:
blk_mq_end_request(rq, result);
}
static int rbd_queue_rq(struct blk_mq_hw_ctx *hctx,
const struct blk_mq_queue_data *bd)
{
struct request *rq = bd->rq;
struct work_struct *work = blk_mq_rq_to_pdu(rq);
queue_work(rbd_wq, work);
return BLK_MQ_RQ_QUEUE_OK;
}
static void rbd_free_disk(struct rbd_device *rbd_dev)
{
blk_cleanup_queue(rbd_dev->disk->queue);
blk_mq_free_tag_set(&rbd_dev->tag_set);
put_disk(rbd_dev->disk);
rbd_dev->disk = NULL;
}
static int rbd_obj_read_sync(struct rbd_device *rbd_dev,
struct ceph_object_id *oid,
struct ceph_object_locator *oloc,
void *buf, int buf_len)
{
struct ceph_osd_client *osdc = &rbd_dev->rbd_client->client->osdc;
struct ceph_osd_request *req;
struct page **pages;
int num_pages = calc_pages_for(0, buf_len);
int ret;
req = ceph_osdc_alloc_request(osdc, NULL, 1, false, GFP_KERNEL);
if (!req)
return -ENOMEM;
ceph_oid_copy(&req->r_base_oid, oid);
ceph_oloc_copy(&req->r_base_oloc, oloc);
req->r_flags = CEPH_OSD_FLAG_READ;
ret = ceph_osdc_alloc_messages(req, GFP_KERNEL);
if (ret)
goto out_req;
pages = ceph_alloc_page_vector(num_pages, GFP_KERNEL);
if (IS_ERR(pages)) {
ret = PTR_ERR(pages);
goto out_req;
}
osd_req_op_extent_init(req, 0, CEPH_OSD_OP_READ, 0, buf_len, 0, 0);
osd_req_op_extent_osd_data_pages(req, 0, pages, buf_len, 0, false,
true);
ceph_osdc_start_request(osdc, req, false);
ret = ceph_osdc_wait_request(osdc, req);
if (ret >= 0)
ceph_copy_from_page_vector(pages, buf, 0, ret);
out_req:
ceph_osdc_put_request(req);
return ret;
}
static int rbd_dev_v1_header_info(struct rbd_device *rbd_dev)
{
struct rbd_image_header_ondisk *ondisk = NULL;
u32 snap_count = 0;
u64 names_size = 0;
u32 want_count;
int ret;
do {
size_t size;
kfree(ondisk);
size = sizeof (*ondisk);
size += snap_count * sizeof (struct rbd_image_snap_ondisk);
size += names_size;
ondisk = kmalloc(size, GFP_KERNEL);
if (!ondisk)
return -ENOMEM;
ret = rbd_obj_read_sync(rbd_dev, &rbd_dev->header_oid,
&rbd_dev->header_oloc, ondisk, size);
if (ret < 0)
goto out;
if ((size_t)ret < size) {
ret = -ENXIO;
rbd_warn(rbd_dev, "short header read (want %zd got %d)",
size, ret);
goto out;
}
if (!rbd_dev_ondisk_valid(ondisk)) {
ret = -ENXIO;
rbd_warn(rbd_dev, "invalid header");
goto out;
}
names_size = le64_to_cpu(ondisk->snap_names_len);
want_count = snap_count;
snap_count = le32_to_cpu(ondisk->snap_count);
} while (snap_count != want_count);
ret = rbd_header_from_disk(rbd_dev, ondisk);
out:
kfree(ondisk);
return ret;
}
static void rbd_exists_validate(struct rbd_device *rbd_dev)
{
u64 snap_id;
if (!test_bit(RBD_DEV_FLAG_EXISTS, &rbd_dev->flags))
return;
snap_id = rbd_dev->spec->snap_id;
if (snap_id == CEPH_NOSNAP)
return;
if (rbd_dev_snap_index(rbd_dev, snap_id) == BAD_SNAP_INDEX)
clear_bit(RBD_DEV_FLAG_EXISTS, &rbd_dev->flags);
}
static void rbd_dev_update_size(struct rbd_device *rbd_dev)
{
sector_t size;
if (test_bit(RBD_DEV_FLAG_EXISTS, &rbd_dev->flags) &&
!test_bit(RBD_DEV_FLAG_REMOVING, &rbd_dev->flags)) {
size = (sector_t)rbd_dev->mapping.size / SECTOR_SIZE;
dout("setting size to %llu sectors", (unsigned long long)size);
set_capacity(rbd_dev->disk, size);
revalidate_disk(rbd_dev->disk);
}
}
static int rbd_dev_refresh(struct rbd_device *rbd_dev)
{
u64 mapping_size;
int ret;
down_write(&rbd_dev->header_rwsem);
mapping_size = rbd_dev->mapping.size;
ret = rbd_dev_header_info(rbd_dev);
if (ret)
goto out;
if (rbd_dev->parent) {
ret = rbd_dev_v2_parent_info(rbd_dev);
if (ret)
goto out;
}
if (rbd_dev->spec->snap_id == CEPH_NOSNAP) {
rbd_dev->mapping.size = rbd_dev->header.image_size;
} else {
rbd_exists_validate(rbd_dev);
}
out:
up_write(&rbd_dev->header_rwsem);
if (!ret && mapping_size != rbd_dev->mapping.size)
rbd_dev_update_size(rbd_dev);
return ret;
}
static int rbd_init_request(struct blk_mq_tag_set *set, struct request *rq,
unsigned int hctx_idx, unsigned int numa_node)
{
struct work_struct *work = blk_mq_rq_to_pdu(rq);
INIT_WORK(work, rbd_queue_workfn);
return 0;
}
static int rbd_init_disk(struct rbd_device *rbd_dev)
{
struct gendisk *disk;
struct request_queue *q;
u64 segment_size;
int err;
disk = alloc_disk(single_major ?
(1 << RBD_SINGLE_MAJOR_PART_SHIFT) :
RBD_MINORS_PER_MAJOR);
if (!disk)
return -ENOMEM;
snprintf(disk->disk_name, sizeof(disk->disk_name), RBD_DRV_NAME "%d",
rbd_dev->dev_id);
disk->major = rbd_dev->major;
disk->first_minor = rbd_dev->minor;
if (single_major)
disk->flags |= GENHD_FL_EXT_DEVT;
disk->fops = &rbd_bd_ops;
disk->private_data = rbd_dev;
memset(&rbd_dev->tag_set, 0, sizeof(rbd_dev->tag_set));
rbd_dev->tag_set.ops = &rbd_mq_ops;
rbd_dev->tag_set.queue_depth = rbd_dev->opts->queue_depth;
rbd_dev->tag_set.numa_node = NUMA_NO_NODE;
rbd_dev->tag_set.flags = BLK_MQ_F_SHOULD_MERGE | BLK_MQ_F_SG_MERGE;
rbd_dev->tag_set.nr_hw_queues = 1;
rbd_dev->tag_set.cmd_size = sizeof(struct work_struct);
err = blk_mq_alloc_tag_set(&rbd_dev->tag_set);
if (err)
goto out_disk;
q = blk_mq_init_queue(&rbd_dev->tag_set);
if (IS_ERR(q)) {
err = PTR_ERR(q);
goto out_tag_set;
}
queue_flag_set_unlocked(QUEUE_FLAG_NONROT, q);
segment_size = rbd_obj_bytes(&rbd_dev->header);
blk_queue_max_hw_sectors(q, segment_size / SECTOR_SIZE);
q->limits.max_sectors = queue_max_hw_sectors(q);
blk_queue_max_segments(q, segment_size / SECTOR_SIZE);
blk_queue_max_segment_size(q, segment_size);
blk_queue_io_min(q, segment_size);
blk_queue_io_opt(q, segment_size);
queue_flag_set_unlocked(QUEUE_FLAG_DISCARD, q);
q->limits.discard_granularity = segment_size;
q->limits.discard_alignment = segment_size;
blk_queue_max_discard_sectors(q, segment_size / SECTOR_SIZE);
blk_queue_max_write_zeroes_sectors(q, segment_size / SECTOR_SIZE);
if (!ceph_test_opt(rbd_dev->rbd_client->client, NOCRC))
q->backing_dev_info->capabilities |= BDI_CAP_STABLE_WRITES;
WARN_ON(!blk_get_queue(q));
disk->queue = q;
q->queuedata = rbd_dev;
rbd_dev->disk = disk;
return 0;
out_tag_set:
blk_mq_free_tag_set(&rbd_dev->tag_set);
out_disk:
put_disk(disk);
return err;
}
static struct rbd_device *dev_to_rbd_dev(struct device *dev)
{
return container_of(dev, struct rbd_device, dev);
}
static ssize_t rbd_size_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct rbd_device *rbd_dev = dev_to_rbd_dev(dev);
return sprintf(buf, "%llu\n",
(unsigned long long)rbd_dev->mapping.size);
}
static ssize_t rbd_features_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct rbd_device *rbd_dev = dev_to_rbd_dev(dev);
return sprintf(buf, "0x%016llx\n",
(unsigned long long)rbd_dev->mapping.features);
}
static ssize_t rbd_major_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct rbd_device *rbd_dev = dev_to_rbd_dev(dev);
if (rbd_dev->major)
return sprintf(buf, "%d\n", rbd_dev->major);
return sprintf(buf, "(none)\n");
}
static ssize_t rbd_minor_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct rbd_device *rbd_dev = dev_to_rbd_dev(dev);
return sprintf(buf, "%d\n", rbd_dev->minor);
}
static ssize_t rbd_client_addr_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct rbd_device *rbd_dev = dev_to_rbd_dev(dev);
struct ceph_entity_addr *client_addr =
ceph_client_addr(rbd_dev->rbd_client->client);
return sprintf(buf, "%pISpc/%u\n", &client_addr->in_addr,
le32_to_cpu(client_addr->nonce));
}
static ssize_t rbd_client_id_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct rbd_device *rbd_dev = dev_to_rbd_dev(dev);
return sprintf(buf, "client%lld\n",
ceph_client_gid(rbd_dev->rbd_client->client));
}
static ssize_t rbd_cluster_fsid_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct rbd_device *rbd_dev = dev_to_rbd_dev(dev);
return sprintf(buf, "%pU\n", &rbd_dev->rbd_client->client->fsid);
}
static ssize_t rbd_config_info_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct rbd_device *rbd_dev = dev_to_rbd_dev(dev);
return sprintf(buf, "%s\n", rbd_dev->config_info);
}
static ssize_t rbd_pool_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct rbd_device *rbd_dev = dev_to_rbd_dev(dev);
return sprintf(buf, "%s\n", rbd_dev->spec->pool_name);
}
static ssize_t rbd_pool_id_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct rbd_device *rbd_dev = dev_to_rbd_dev(dev);
return sprintf(buf, "%llu\n",
(unsigned long long) rbd_dev->spec->pool_id);
}
static ssize_t rbd_name_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct rbd_device *rbd_dev = dev_to_rbd_dev(dev);
if (rbd_dev->spec->image_name)
return sprintf(buf, "%s\n", rbd_dev->spec->image_name);
return sprintf(buf, "(unknown)\n");
}
static ssize_t rbd_image_id_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct rbd_device *rbd_dev = dev_to_rbd_dev(dev);
return sprintf(buf, "%s\n", rbd_dev->spec->image_id);
}
static ssize_t rbd_snap_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct rbd_device *rbd_dev = dev_to_rbd_dev(dev);
return sprintf(buf, "%s\n", rbd_dev->spec->snap_name);
}
static ssize_t rbd_snap_id_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct rbd_device *rbd_dev = dev_to_rbd_dev(dev);
return sprintf(buf, "%llu\n", rbd_dev->spec->snap_id);
}
static ssize_t rbd_parent_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct rbd_device *rbd_dev = dev_to_rbd_dev(dev);
ssize_t count = 0;
if (!rbd_dev->parent)
return sprintf(buf, "(no parent image)\n");
for ( ; rbd_dev->parent; rbd_dev = rbd_dev->parent) {
struct rbd_spec *spec = rbd_dev->parent_spec;
count += sprintf(&buf[count], "%s"
"pool_id %llu\npool_name %s\n"
"image_id %s\nimage_name %s\n"
"snap_id %llu\nsnap_name %s\n"
"overlap %llu\n",
!count ? "" : "\n",
spec->pool_id, spec->pool_name,
spec->image_id, spec->image_name ?: "(unknown)",
spec->snap_id, spec->snap_name,
rbd_dev->parent_overlap);
}
return count;
}
static ssize_t rbd_image_refresh(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t size)
{
struct rbd_device *rbd_dev = dev_to_rbd_dev(dev);
int ret;
ret = rbd_dev_refresh(rbd_dev);
if (ret)
return ret;
return size;
}
static struct rbd_spec *rbd_spec_get(struct rbd_spec *spec)
{
kref_get(&spec->kref);
return spec;
}
static void rbd_spec_put(struct rbd_spec *spec)
{
if (spec)
kref_put(&spec->kref, rbd_spec_free);
}
static struct rbd_spec *rbd_spec_alloc(void)
{
struct rbd_spec *spec;
spec = kzalloc(sizeof (*spec), GFP_KERNEL);
if (!spec)
return NULL;
spec->pool_id = CEPH_NOPOOL;
spec->snap_id = CEPH_NOSNAP;
kref_init(&spec->kref);
return spec;
}
static void rbd_spec_free(struct kref *kref)
{
struct rbd_spec *spec = container_of(kref, struct rbd_spec, kref);
kfree(spec->pool_name);
kfree(spec->image_id);
kfree(spec->image_name);
kfree(spec->snap_name);
kfree(spec);
}
static void rbd_dev_free(struct rbd_device *rbd_dev)
{
WARN_ON(rbd_dev->watch_state != RBD_WATCH_STATE_UNREGISTERED);
WARN_ON(rbd_dev->lock_state != RBD_LOCK_STATE_UNLOCKED);
ceph_oid_destroy(&rbd_dev->header_oid);
ceph_oloc_destroy(&rbd_dev->header_oloc);
kfree(rbd_dev->config_info);
rbd_put_client(rbd_dev->rbd_client);
rbd_spec_put(rbd_dev->spec);
kfree(rbd_dev->opts);
kfree(rbd_dev);
}
static void rbd_dev_release(struct device *dev)
{
struct rbd_device *rbd_dev = dev_to_rbd_dev(dev);
bool need_put = !!rbd_dev->opts;
if (need_put) {
destroy_workqueue(rbd_dev->task_wq);
ida_simple_remove(&rbd_dev_id_ida, rbd_dev->dev_id);
}
rbd_dev_free(rbd_dev);
if (need_put)
module_put(THIS_MODULE);
}
static struct rbd_device *__rbd_dev_create(struct rbd_client *rbdc,
struct rbd_spec *spec)
{
struct rbd_device *rbd_dev;
rbd_dev = kzalloc(sizeof(*rbd_dev), GFP_KERNEL);
if (!rbd_dev)
return NULL;
spin_lock_init(&rbd_dev->lock);
INIT_LIST_HEAD(&rbd_dev->node);
init_rwsem(&rbd_dev->header_rwsem);
rbd_dev->header.data_pool_id = CEPH_NOPOOL;
ceph_oid_init(&rbd_dev->header_oid);
rbd_dev->header_oloc.pool = spec->pool_id;
mutex_init(&rbd_dev->watch_mutex);
rbd_dev->watch_state = RBD_WATCH_STATE_UNREGISTERED;
INIT_DELAYED_WORK(&rbd_dev->watch_dwork, rbd_reregister_watch);
init_rwsem(&rbd_dev->lock_rwsem);
rbd_dev->lock_state = RBD_LOCK_STATE_UNLOCKED;
INIT_WORK(&rbd_dev->acquired_lock_work, rbd_notify_acquired_lock);
INIT_WORK(&rbd_dev->released_lock_work, rbd_notify_released_lock);
INIT_DELAYED_WORK(&rbd_dev->lock_dwork, rbd_acquire_lock);
INIT_WORK(&rbd_dev->unlock_work, rbd_release_lock_work);
init_waitqueue_head(&rbd_dev->lock_waitq);
rbd_dev->dev.bus = &rbd_bus_type;
rbd_dev->dev.type = &rbd_device_type;
rbd_dev->dev.parent = &rbd_root_dev;
device_initialize(&rbd_dev->dev);
rbd_dev->rbd_client = rbdc;
rbd_dev->spec = spec;
return rbd_dev;
}
static struct rbd_device *rbd_dev_create(struct rbd_client *rbdc,
struct rbd_spec *spec,
struct rbd_options *opts)
{
struct rbd_device *rbd_dev;
rbd_dev = __rbd_dev_create(rbdc, spec);
if (!rbd_dev)
return NULL;
rbd_dev->opts = opts;
rbd_dev->dev_id = ida_simple_get(&rbd_dev_id_ida, 0,
minor_to_rbd_dev_id(1 << MINORBITS),
GFP_KERNEL);
if (rbd_dev->dev_id < 0)
goto fail_rbd_dev;
sprintf(rbd_dev->name, RBD_DRV_NAME "%d", rbd_dev->dev_id);
rbd_dev->task_wq = alloc_ordered_workqueue("%s-tasks", WQ_MEM_RECLAIM,
rbd_dev->name);
if (!rbd_dev->task_wq)
goto fail_dev_id;
__module_get(THIS_MODULE);
dout("%s rbd_dev %p dev_id %d\n", __func__, rbd_dev, rbd_dev->dev_id);
return rbd_dev;
fail_dev_id:
ida_simple_remove(&rbd_dev_id_ida, rbd_dev->dev_id);
fail_rbd_dev:
rbd_dev_free(rbd_dev);
return NULL;
}
static void rbd_dev_destroy(struct rbd_device *rbd_dev)
{
if (rbd_dev)
put_device(&rbd_dev->dev);
}
static int _rbd_dev_v2_snap_size(struct rbd_device *rbd_dev, u64 snap_id,
u8 *order, u64 *snap_size)
{
__le64 snapid = cpu_to_le64(snap_id);
int ret;
struct {
u8 order;
__le64 size;
} __attribute__ ((packed)) size_buf = { 0 };
ret = rbd_obj_method_sync(rbd_dev, &rbd_dev->header_oid,
&rbd_dev->header_oloc, "get_size",
&snapid, sizeof(snapid),
&size_buf, sizeof(size_buf));
dout("%s: rbd_obj_method_sync returned %d\n", __func__, ret);
if (ret < 0)
return ret;
if (ret < sizeof (size_buf))
return -ERANGE;
if (order) {
*order = size_buf.order;
dout(" order %u", (unsigned int)*order);
}
*snap_size = le64_to_cpu(size_buf.size);
dout(" snap_id 0x%016llx snap_size = %llu\n",
(unsigned long long)snap_id,
(unsigned long long)*snap_size);
return 0;
}
static int rbd_dev_v2_image_size(struct rbd_device *rbd_dev)
{
return _rbd_dev_v2_snap_size(rbd_dev, CEPH_NOSNAP,
&rbd_dev->header.obj_order,
&rbd_dev->header.image_size);
}
static int rbd_dev_v2_object_prefix(struct rbd_device *rbd_dev)
{
void *reply_buf;
int ret;
void *p;
reply_buf = kzalloc(RBD_OBJ_PREFIX_LEN_MAX, GFP_KERNEL);
if (!reply_buf)
return -ENOMEM;
ret = rbd_obj_method_sync(rbd_dev, &rbd_dev->header_oid,
&rbd_dev->header_oloc, "get_object_prefix",
NULL, 0, reply_buf, RBD_OBJ_PREFIX_LEN_MAX);
dout("%s: rbd_obj_method_sync returned %d\n", __func__, ret);
if (ret < 0)
goto out;
p = reply_buf;
rbd_dev->header.object_prefix = ceph_extract_encoded_string(&p,
p + ret, NULL, GFP_NOIO);
ret = 0;
if (IS_ERR(rbd_dev->header.object_prefix)) {
ret = PTR_ERR(rbd_dev->header.object_prefix);
rbd_dev->header.object_prefix = NULL;
} else {
dout(" object_prefix = %s\n", rbd_dev->header.object_prefix);
}
out:
kfree(reply_buf);
return ret;
}
static int _rbd_dev_v2_snap_features(struct rbd_device *rbd_dev, u64 snap_id,
u64 *snap_features)
{
__le64 snapid = cpu_to_le64(snap_id);
struct {
__le64 features;
__le64 incompat;
} __attribute__ ((packed)) features_buf = { 0 };
u64 unsup;
int ret;
ret = rbd_obj_method_sync(rbd_dev, &rbd_dev->header_oid,
&rbd_dev->header_oloc, "get_features",
&snapid, sizeof(snapid),
&features_buf, sizeof(features_buf));
dout("%s: rbd_obj_method_sync returned %d\n", __func__, ret);
if (ret < 0)
return ret;
if (ret < sizeof (features_buf))
return -ERANGE;
unsup = le64_to_cpu(features_buf.incompat) & ~RBD_FEATURES_SUPPORTED;
if (unsup) {
rbd_warn(rbd_dev, "image uses unsupported features: 0x%llx",
unsup);
return -ENXIO;
}
*snap_features = le64_to_cpu(features_buf.features);
dout(" snap_id 0x%016llx features = 0x%016llx incompat = 0x%016llx\n",
(unsigned long long)snap_id,
(unsigned long long)*snap_features,
(unsigned long long)le64_to_cpu(features_buf.incompat));
return 0;
}
static int rbd_dev_v2_features(struct rbd_device *rbd_dev)
{
return _rbd_dev_v2_snap_features(rbd_dev, CEPH_NOSNAP,
&rbd_dev->header.features);
}
static int rbd_dev_v2_parent_info(struct rbd_device *rbd_dev)
{
struct rbd_spec *parent_spec;
size_t size;
void *reply_buf = NULL;
__le64 snapid;
void *p;
void *end;
u64 pool_id;
char *image_id;
u64 snap_id;
u64 overlap;
int ret;
parent_spec = rbd_spec_alloc();
if (!parent_spec)
return -ENOMEM;
size = sizeof (__le64) +
sizeof (__le32) + RBD_IMAGE_ID_LEN_MAX +
sizeof (__le64) +
sizeof (__le64);
reply_buf = kmalloc(size, GFP_KERNEL);
if (!reply_buf) {
ret = -ENOMEM;
goto out_err;
}
snapid = cpu_to_le64(rbd_dev->spec->snap_id);
ret = rbd_obj_method_sync(rbd_dev, &rbd_dev->header_oid,
&rbd_dev->header_oloc, "get_parent",
&snapid, sizeof(snapid), reply_buf, size);
dout("%s: rbd_obj_method_sync returned %d\n", __func__, ret);
if (ret < 0)
goto out_err;
p = reply_buf;
end = reply_buf + ret;
ret = -ERANGE;
ceph_decode_64_safe(&p, end, pool_id, out_err);
if (pool_id == CEPH_NOPOOL) {
if (rbd_dev->parent_overlap) {
rbd_dev->parent_overlap = 0;
rbd_dev_parent_put(rbd_dev);
pr_info("%s: clone image has been flattened\n",
rbd_dev->disk->disk_name);
}
goto out;
}
ret = -EIO;
if (pool_id > (u64)U32_MAX) {
rbd_warn(NULL, "parent pool id too large (%llu > %u)",
(unsigned long long)pool_id, U32_MAX);
goto out_err;
}
image_id = ceph_extract_encoded_string(&p, end, NULL, GFP_KERNEL);
if (IS_ERR(image_id)) {
ret = PTR_ERR(image_id);
goto out_err;
}
ceph_decode_64_safe(&p, end, snap_id, out_err);
ceph_decode_64_safe(&p, end, overlap, out_err);
if (!rbd_dev->parent_spec) {
parent_spec->pool_id = pool_id;
parent_spec->image_id = image_id;
parent_spec->snap_id = snap_id;
rbd_dev->parent_spec = parent_spec;
parent_spec = NULL;
} else {
kfree(image_id);
}
if (!overlap) {
if (parent_spec) {
if (rbd_dev->parent_overlap)
rbd_warn(rbd_dev,
"clone now standalone (overlap became 0)");
} else {
rbd_warn(rbd_dev, "clone is standalone (overlap 0)");
}
}
rbd_dev->parent_overlap = overlap;
out:
ret = 0;
out_err:
kfree(reply_buf);
rbd_spec_put(parent_spec);
return ret;
}
static int rbd_dev_v2_striping_info(struct rbd_device *rbd_dev)
{
struct {
__le64 stripe_unit;
__le64 stripe_count;
} __attribute__ ((packed)) striping_info_buf = { 0 };
size_t size = sizeof (striping_info_buf);
void *p;
u64 obj_size;
u64 stripe_unit;
u64 stripe_count;
int ret;
ret = rbd_obj_method_sync(rbd_dev, &rbd_dev->header_oid,
&rbd_dev->header_oloc, "get_stripe_unit_count",
NULL, 0, &striping_info_buf, size);
dout("%s: rbd_obj_method_sync returned %d\n", __func__, ret);
if (ret < 0)
return ret;
if (ret < size)
return -ERANGE;
ret = -EINVAL;
obj_size = rbd_obj_bytes(&rbd_dev->header);
p = &striping_info_buf;
stripe_unit = ceph_decode_64(&p);
if (stripe_unit != obj_size) {
rbd_warn(rbd_dev, "unsupported stripe unit "
"(got %llu want %llu)",
stripe_unit, obj_size);
return -EINVAL;
}
stripe_count = ceph_decode_64(&p);
if (stripe_count != 1) {
rbd_warn(rbd_dev, "unsupported stripe count "
"(got %llu want 1)", stripe_count);
return -EINVAL;
}
rbd_dev->header.stripe_unit = stripe_unit;
rbd_dev->header.stripe_count = stripe_count;
return 0;
}
static int rbd_dev_v2_data_pool(struct rbd_device *rbd_dev)
{
__le64 data_pool_id;
int ret;
ret = rbd_obj_method_sync(rbd_dev, &rbd_dev->header_oid,
&rbd_dev->header_oloc, "get_data_pool",
NULL, 0, &data_pool_id, sizeof(data_pool_id));
if (ret < 0)
return ret;
if (ret < sizeof(data_pool_id))
return -EBADMSG;
rbd_dev->header.data_pool_id = le64_to_cpu(data_pool_id);
WARN_ON(rbd_dev->header.data_pool_id == CEPH_NOPOOL);
return 0;
}
static char *rbd_dev_image_name(struct rbd_device *rbd_dev)
{
CEPH_DEFINE_OID_ONSTACK(oid);
size_t image_id_size;
char *image_id;
void *p;
void *end;
size_t size;
void *reply_buf = NULL;
size_t len = 0;
char *image_name = NULL;
int ret;
rbd_assert(!rbd_dev->spec->image_name);
len = strlen(rbd_dev->spec->image_id);
image_id_size = sizeof (__le32) + len;
image_id = kmalloc(image_id_size, GFP_KERNEL);
if (!image_id)
return NULL;
p = image_id;
end = image_id + image_id_size;
ceph_encode_string(&p, end, rbd_dev->spec->image_id, (u32)len);
size = sizeof (__le32) + RBD_IMAGE_NAME_LEN_MAX;
reply_buf = kmalloc(size, GFP_KERNEL);
if (!reply_buf)
goto out;
ceph_oid_printf(&oid, "%s", RBD_DIRECTORY);
ret = rbd_obj_method_sync(rbd_dev, &oid, &rbd_dev->header_oloc,
"dir_get_name", image_id, image_id_size,
reply_buf, size);
if (ret < 0)
goto out;
p = reply_buf;
end = reply_buf + ret;
image_name = ceph_extract_encoded_string(&p, end, &len, GFP_KERNEL);
if (IS_ERR(image_name))
image_name = NULL;
else
dout("%s: name is %s len is %zd\n", __func__, image_name, len);
out:
kfree(reply_buf);
kfree(image_id);
return image_name;
}
static u64 rbd_v1_snap_id_by_name(struct rbd_device *rbd_dev, const char *name)
{
struct ceph_snap_context *snapc = rbd_dev->header.snapc;
const char *snap_name;
u32 which = 0;
snap_name = rbd_dev->header.snap_names;
while (which < snapc->num_snaps) {
if (!strcmp(name, snap_name))
return snapc->snaps[which];
snap_name += strlen(snap_name) + 1;
which++;
}
return CEPH_NOSNAP;
}
static u64 rbd_v2_snap_id_by_name(struct rbd_device *rbd_dev, const char *name)
{
struct ceph_snap_context *snapc = rbd_dev->header.snapc;
u32 which;
bool found = false;
u64 snap_id;
for (which = 0; !found && which < snapc->num_snaps; which++) {
const char *snap_name;
snap_id = snapc->snaps[which];
snap_name = rbd_dev_v2_snap_name(rbd_dev, snap_id);
if (IS_ERR(snap_name)) {
if (PTR_ERR(snap_name) == -ENOENT)
continue;
else
break;
}
found = !strcmp(name, snap_name);
kfree(snap_name);
}
return found ? snap_id : CEPH_NOSNAP;
}
static u64 rbd_snap_id_by_name(struct rbd_device *rbd_dev, const char *name)
{
if (rbd_dev->image_format == 1)
return rbd_v1_snap_id_by_name(rbd_dev, name);
return rbd_v2_snap_id_by_name(rbd_dev, name);
}
static int rbd_spec_fill_snap_id(struct rbd_device *rbd_dev)
{
struct rbd_spec *spec = rbd_dev->spec;
rbd_assert(spec->pool_id != CEPH_NOPOOL && spec->pool_name);
rbd_assert(spec->image_id && spec->image_name);
rbd_assert(spec->snap_name);
if (strcmp(spec->snap_name, RBD_SNAP_HEAD_NAME)) {
u64 snap_id;
snap_id = rbd_snap_id_by_name(rbd_dev, spec->snap_name);
if (snap_id == CEPH_NOSNAP)
return -ENOENT;
spec->snap_id = snap_id;
} else {
spec->snap_id = CEPH_NOSNAP;
}
return 0;
}
static int rbd_spec_fill_names(struct rbd_device *rbd_dev)
{
struct ceph_osd_client *osdc = &rbd_dev->rbd_client->client->osdc;
struct rbd_spec *spec = rbd_dev->spec;
const char *pool_name;
const char *image_name;
const char *snap_name;
int ret;
rbd_assert(spec->pool_id != CEPH_NOPOOL);
rbd_assert(spec->image_id);
rbd_assert(spec->snap_id != CEPH_NOSNAP);
pool_name = ceph_pg_pool_name_by_id(osdc->osdmap, spec->pool_id);
if (!pool_name) {
rbd_warn(rbd_dev, "no pool with id %llu", spec->pool_id);
return -EIO;
}
pool_name = kstrdup(pool_name, GFP_KERNEL);
if (!pool_name)
return -ENOMEM;
image_name = rbd_dev_image_name(rbd_dev);
if (!image_name)
rbd_warn(rbd_dev, "unable to get image name");
snap_name = rbd_snap_name(rbd_dev, spec->snap_id);
if (IS_ERR(snap_name)) {
ret = PTR_ERR(snap_name);
goto out_err;
}
spec->pool_name = pool_name;
spec->image_name = image_name;
spec->snap_name = snap_name;
return 0;
out_err:
kfree(image_name);
kfree(pool_name);
return ret;
}
static int rbd_dev_v2_snap_context(struct rbd_device *rbd_dev)
{
size_t size;
int ret;
void *reply_buf;
void *p;
void *end;
u64 seq;
u32 snap_count;
struct ceph_snap_context *snapc;
u32 i;
size = sizeof (__le64) + sizeof (__le32) +
RBD_MAX_SNAP_COUNT * sizeof (__le64);
reply_buf = kzalloc(size, GFP_KERNEL);
if (!reply_buf)
return -ENOMEM;
ret = rbd_obj_method_sync(rbd_dev, &rbd_dev->header_oid,
&rbd_dev->header_oloc, "get_snapcontext",
NULL, 0, reply_buf, size);
dout("%s: rbd_obj_method_sync returned %d\n", __func__, ret);
if (ret < 0)
goto out;
p = reply_buf;
end = reply_buf + ret;
ret = -ERANGE;
ceph_decode_64_safe(&p, end, seq, out);
ceph_decode_32_safe(&p, end, snap_count, out);
if (snap_count > (SIZE_MAX - sizeof (struct ceph_snap_context))
/ sizeof (u64)) {
ret = -EINVAL;
goto out;
}
if (!ceph_has_room(&p, end, snap_count * sizeof (__le64)))
goto out;
ret = 0;
snapc = ceph_create_snap_context(snap_count, GFP_KERNEL);
if (!snapc) {
ret = -ENOMEM;
goto out;
}
snapc->seq = seq;
for (i = 0; i < snap_count; i++)
snapc->snaps[i] = ceph_decode_64(&p);
ceph_put_snap_context(rbd_dev->header.snapc);
rbd_dev->header.snapc = snapc;
dout(" snap context seq = %llu, snap_count = %u\n",
(unsigned long long)seq, (unsigned int)snap_count);
out:
kfree(reply_buf);
return ret;
}
static const char *rbd_dev_v2_snap_name(struct rbd_device *rbd_dev,
u64 snap_id)
{
size_t size;
void *reply_buf;
__le64 snapid;
int ret;
void *p;
void *end;
char *snap_name;
size = sizeof (__le32) + RBD_MAX_SNAP_NAME_LEN;
reply_buf = kmalloc(size, GFP_KERNEL);
if (!reply_buf)
return ERR_PTR(-ENOMEM);
snapid = cpu_to_le64(snap_id);
ret = rbd_obj_method_sync(rbd_dev, &rbd_dev->header_oid,
&rbd_dev->header_oloc, "get_snapshot_name",
&snapid, sizeof(snapid), reply_buf, size);
dout("%s: rbd_obj_method_sync returned %d\n", __func__, ret);
if (ret < 0) {
snap_name = ERR_PTR(ret);
goto out;
}
p = reply_buf;
end = reply_buf + ret;
snap_name = ceph_extract_encoded_string(&p, end, NULL, GFP_KERNEL);
if (IS_ERR(snap_name))
goto out;
dout(" snap_id 0x%016llx snap_name = %s\n",
(unsigned long long)snap_id, snap_name);
out:
kfree(reply_buf);
return snap_name;
}
static int rbd_dev_v2_header_info(struct rbd_device *rbd_dev)
{
bool first_time = rbd_dev->header.object_prefix == NULL;
int ret;
ret = rbd_dev_v2_image_size(rbd_dev);
if (ret)
return ret;
if (first_time) {
ret = rbd_dev_v2_header_onetime(rbd_dev);
if (ret)
return ret;
}
ret = rbd_dev_v2_snap_context(rbd_dev);
if (ret && first_time) {
kfree(rbd_dev->header.object_prefix);
rbd_dev->header.object_prefix = NULL;
}
return ret;
}
static int rbd_dev_header_info(struct rbd_device *rbd_dev)
{
rbd_assert(rbd_image_format_valid(rbd_dev->image_format));
if (rbd_dev->image_format == 1)
return rbd_dev_v1_header_info(rbd_dev);
return rbd_dev_v2_header_info(rbd_dev);
}
static inline size_t next_token(const char **buf)
{
const char *spaces = " \f\n\r\t\v";
*buf += strspn(*buf, spaces);
return strcspn(*buf, spaces);
}
static inline char *dup_token(const char **buf, size_t *lenp)
{
char *dup;
size_t len;
len = next_token(buf);
dup = kmemdup(*buf, len + 1, GFP_KERNEL);
if (!dup)
return NULL;
*(dup + len) = '\0';
*buf += len;
if (lenp)
*lenp = len;
return dup;
}
static int rbd_add_parse_args(const char *buf,
struct ceph_options **ceph_opts,
struct rbd_options **opts,
struct rbd_spec **rbd_spec)
{
size_t len;
char *options;
const char *mon_addrs;
char *snap_name;
size_t mon_addrs_size;
struct rbd_spec *spec = NULL;
struct rbd_options *rbd_opts = NULL;
struct ceph_options *copts;
int ret;
len = next_token(&buf);
if (!len) {
rbd_warn(NULL, "no monitor address(es) provided");
return -EINVAL;
}
mon_addrs = buf;
mon_addrs_size = len + 1;
buf += len;
ret = -EINVAL;
options = dup_token(&buf, NULL);
if (!options)
return -ENOMEM;
if (!*options) {
rbd_warn(NULL, "no options provided");
goto out_err;
}
spec = rbd_spec_alloc();
if (!spec)
goto out_mem;
spec->pool_name = dup_token(&buf, NULL);
if (!spec->pool_name)
goto out_mem;
if (!*spec->pool_name) {
rbd_warn(NULL, "no pool name provided");
goto out_err;
}
spec->image_name = dup_token(&buf, NULL);
if (!spec->image_name)
goto out_mem;
if (!*spec->image_name) {
rbd_warn(NULL, "no image name provided");
goto out_err;
}
len = next_token(&buf);
if (!len) {
buf = RBD_SNAP_HEAD_NAME;
len = sizeof (RBD_SNAP_HEAD_NAME) - 1;
} else if (len > RBD_MAX_SNAP_NAME_LEN) {
ret = -ENAMETOOLONG;
goto out_err;
}
snap_name = kmemdup(buf, len + 1, GFP_KERNEL);
if (!snap_name)
goto out_mem;
*(snap_name + len) = '\0';
spec->snap_name = snap_name;
rbd_opts = kzalloc(sizeof (*rbd_opts), GFP_KERNEL);
if (!rbd_opts)
goto out_mem;
rbd_opts->read_only = RBD_READ_ONLY_DEFAULT;
rbd_opts->queue_depth = RBD_QUEUE_DEPTH_DEFAULT;
rbd_opts->lock_on_read = RBD_LOCK_ON_READ_DEFAULT;
rbd_opts->exclusive = RBD_EXCLUSIVE_DEFAULT;
copts = ceph_parse_options(options, mon_addrs,
mon_addrs + mon_addrs_size - 1,
parse_rbd_opts_token, rbd_opts);
if (IS_ERR(copts)) {
ret = PTR_ERR(copts);
goto out_err;
}
kfree(options);
*ceph_opts = copts;
*opts = rbd_opts;
*rbd_spec = spec;
return 0;
out_mem:
ret = -ENOMEM;
out_err:
kfree(rbd_opts);
rbd_spec_put(spec);
kfree(options);
return ret;
}
static int rbd_add_get_pool_id(struct rbd_client *rbdc, const char *pool_name)
{
struct ceph_options *opts = rbdc->client->options;
u64 newest_epoch;
int tries = 0;
int ret;
again:
ret = ceph_pg_poolid_by_name(rbdc->client->osdc.osdmap, pool_name);
if (ret == -ENOENT && tries++ < 1) {
ret = ceph_monc_get_version(&rbdc->client->monc, "osdmap",
&newest_epoch);
if (ret < 0)
return ret;
if (rbdc->client->osdc.osdmap->epoch < newest_epoch) {
ceph_osdc_maybe_request_map(&rbdc->client->osdc);
(void) ceph_monc_wait_osdmap(&rbdc->client->monc,
newest_epoch,
opts->mount_timeout);
goto again;
} else {
return -ENOENT;
}
}
return ret;
}
static void rbd_dev_image_unlock(struct rbd_device *rbd_dev)
{
down_write(&rbd_dev->lock_rwsem);
if (__rbd_is_lock_owner(rbd_dev))
rbd_unlock(rbd_dev);
up_write(&rbd_dev->lock_rwsem);
}
static int rbd_add_acquire_lock(struct rbd_device *rbd_dev)
{
if (!(rbd_dev->header.features & RBD_FEATURE_EXCLUSIVE_LOCK)) {
rbd_warn(rbd_dev, "exclusive-lock feature is not enabled");
return -EINVAL;
}
down_read(&rbd_dev->lock_rwsem);
rbd_wait_state_locked(rbd_dev);
up_read(&rbd_dev->lock_rwsem);
if (test_bit(RBD_DEV_FLAG_BLACKLISTED, &rbd_dev->flags)) {
rbd_warn(rbd_dev, "failed to acquire exclusive lock");
return -EROFS;
}
return 0;
}
static int rbd_dev_image_id(struct rbd_device *rbd_dev)
{
int ret;
size_t size;
CEPH_DEFINE_OID_ONSTACK(oid);
void *response;
char *image_id;
if (rbd_dev->spec->image_id) {
rbd_dev->image_format = *rbd_dev->spec->image_id ? 2 : 1;
return 0;
}
ret = ceph_oid_aprintf(&oid, GFP_KERNEL, "%s%s", RBD_ID_PREFIX,
rbd_dev->spec->image_name);
if (ret)
return ret;
dout("rbd id object name is %s\n", oid.name);
size = sizeof (__le32) + RBD_IMAGE_ID_LEN_MAX;
response = kzalloc(size, GFP_NOIO);
if (!response) {
ret = -ENOMEM;
goto out;
}
ret = rbd_obj_method_sync(rbd_dev, &oid, &rbd_dev->header_oloc,
"get_id", NULL, 0,
response, RBD_IMAGE_ID_LEN_MAX);
dout("%s: rbd_obj_method_sync returned %d\n", __func__, ret);
if (ret == -ENOENT) {
image_id = kstrdup("", GFP_KERNEL);
ret = image_id ? 0 : -ENOMEM;
if (!ret)
rbd_dev->image_format = 1;
} else if (ret >= 0) {
void *p = response;
image_id = ceph_extract_encoded_string(&p, p + ret,
NULL, GFP_NOIO);
ret = PTR_ERR_OR_ZERO(image_id);
if (!ret)
rbd_dev->image_format = 2;
}
if (!ret) {
rbd_dev->spec->image_id = image_id;
dout("image_id is %s\n", image_id);
}
out:
kfree(response);
ceph_oid_destroy(&oid);
return ret;
}
static void rbd_dev_unprobe(struct rbd_device *rbd_dev)
{
struct rbd_image_header *header;
rbd_dev_parent_put(rbd_dev);
header = &rbd_dev->header;
ceph_put_snap_context(header->snapc);
kfree(header->snap_sizes);
kfree(header->snap_names);
kfree(header->object_prefix);
memset(header, 0, sizeof (*header));
}
static int rbd_dev_v2_header_onetime(struct rbd_device *rbd_dev)
{
int ret;
ret = rbd_dev_v2_object_prefix(rbd_dev);
if (ret)
goto out_err;
ret = rbd_dev_v2_features(rbd_dev);
if (ret)
goto out_err;
if (rbd_dev->header.features & RBD_FEATURE_STRIPINGV2) {
ret = rbd_dev_v2_striping_info(rbd_dev);
if (ret < 0)
goto out_err;
}
if (rbd_dev->header.features & RBD_FEATURE_DATA_POOL) {
ret = rbd_dev_v2_data_pool(rbd_dev);
if (ret)
goto out_err;
}
rbd_init_layout(rbd_dev);
return 0;
out_err:
rbd_dev->header.features = 0;
kfree(rbd_dev->header.object_prefix);
rbd_dev->header.object_prefix = NULL;
return ret;
}
static int rbd_dev_probe_parent(struct rbd_device *rbd_dev, int depth)
{
struct rbd_device *parent = NULL;
int ret;
if (!rbd_dev->parent_spec)
return 0;
if (++depth > RBD_MAX_PARENT_CHAIN_LEN) {
pr_info("parent chain is too long (%d)\n", depth);
ret = -EINVAL;
goto out_err;
}
parent = __rbd_dev_create(rbd_dev->rbd_client, rbd_dev->parent_spec);
if (!parent) {
ret = -ENOMEM;
goto out_err;
}
__rbd_get_client(rbd_dev->rbd_client);
rbd_spec_get(rbd_dev->parent_spec);
ret = rbd_dev_image_probe(parent, depth);
if (ret < 0)
goto out_err;
rbd_dev->parent = parent;
atomic_set(&rbd_dev->parent_ref, 1);
return 0;
out_err:
rbd_dev_unparent(rbd_dev);
rbd_dev_destroy(parent);
return ret;
}
static void rbd_dev_device_release(struct rbd_device *rbd_dev)
{
clear_bit(RBD_DEV_FLAG_EXISTS, &rbd_dev->flags);
rbd_dev_mapping_clear(rbd_dev);
rbd_free_disk(rbd_dev);
if (!single_major)
unregister_blkdev(rbd_dev->major, rbd_dev->name);
}
static int rbd_dev_device_setup(struct rbd_device *rbd_dev)
{
int ret;
if (!single_major) {
ret = register_blkdev(0, rbd_dev->name);
if (ret < 0)
goto err_out_unlock;
rbd_dev->major = ret;
rbd_dev->minor = 0;
} else {
rbd_dev->major = rbd_major;
rbd_dev->minor = rbd_dev_id_to_minor(rbd_dev->dev_id);
}
ret = rbd_init_disk(rbd_dev);
if (ret)
goto err_out_blkdev;
ret = rbd_dev_mapping_set(rbd_dev);
if (ret)
goto err_out_disk;
set_capacity(rbd_dev->disk, rbd_dev->mapping.size / SECTOR_SIZE);
set_disk_ro(rbd_dev->disk, rbd_dev->mapping.read_only);
ret = dev_set_name(&rbd_dev->dev, "%d", rbd_dev->dev_id);
if (ret)
goto err_out_mapping;
set_bit(RBD_DEV_FLAG_EXISTS, &rbd_dev->flags);
up_write(&rbd_dev->header_rwsem);
return 0;
err_out_mapping:
rbd_dev_mapping_clear(rbd_dev);
err_out_disk:
rbd_free_disk(rbd_dev);
err_out_blkdev:
if (!single_major)
unregister_blkdev(rbd_dev->major, rbd_dev->name);
err_out_unlock:
up_write(&rbd_dev->header_rwsem);
return ret;
}
static int rbd_dev_header_name(struct rbd_device *rbd_dev)
{
struct rbd_spec *spec = rbd_dev->spec;
int ret;
rbd_assert(rbd_image_format_valid(rbd_dev->image_format));
if (rbd_dev->image_format == 1)
ret = ceph_oid_aprintf(&rbd_dev->header_oid, GFP_KERNEL, "%s%s",
spec->image_name, RBD_SUFFIX);
else
ret = ceph_oid_aprintf(&rbd_dev->header_oid, GFP_KERNEL, "%s%s",
RBD_HEADER_PREFIX, spec->image_id);
return ret;
}
static void rbd_dev_image_release(struct rbd_device *rbd_dev)
{
rbd_dev_unprobe(rbd_dev);
if (rbd_dev->opts)
rbd_unregister_watch(rbd_dev);
rbd_dev->image_format = 0;
kfree(rbd_dev->spec->image_id);
rbd_dev->spec->image_id = NULL;
}
static int rbd_dev_image_probe(struct rbd_device *rbd_dev, int depth)
{
int ret;
ret = rbd_dev_image_id(rbd_dev);
if (ret)
return ret;
ret = rbd_dev_header_name(rbd_dev);
if (ret)
goto err_out_format;
if (!depth) {
ret = rbd_register_watch(rbd_dev);
if (ret) {
if (ret == -ENOENT)
pr_info("image %s/%s does not exist\n",
rbd_dev->spec->pool_name,
rbd_dev->spec->image_name);
goto err_out_format;
}
}
ret = rbd_dev_header_info(rbd_dev);
if (ret)
goto err_out_watch;
if (!depth)
ret = rbd_spec_fill_snap_id(rbd_dev);
else
ret = rbd_spec_fill_names(rbd_dev);
if (ret) {
if (ret == -ENOENT)
pr_info("snap %s/%s@%s does not exist\n",
rbd_dev->spec->pool_name,
rbd_dev->spec->image_name,
rbd_dev->spec->snap_name);
goto err_out_probe;
}
if (rbd_dev->header.features & RBD_FEATURE_LAYERING) {
ret = rbd_dev_v2_parent_info(rbd_dev);
if (ret)
goto err_out_probe;
if (!depth && rbd_dev->parent_spec)
rbd_warn(rbd_dev,
"WARNING: kernel layering is EXPERIMENTAL!");
}
ret = rbd_dev_probe_parent(rbd_dev, depth);
if (ret)
goto err_out_probe;
dout("discovered format %u image, header name is %s\n",
rbd_dev->image_format, rbd_dev->header_oid.name);
return 0;
err_out_probe:
rbd_dev_unprobe(rbd_dev);
err_out_watch:
if (!depth)
rbd_unregister_watch(rbd_dev);
err_out_format:
rbd_dev->image_format = 0;
kfree(rbd_dev->spec->image_id);
rbd_dev->spec->image_id = NULL;
return ret;
}
static ssize_t do_rbd_add(struct bus_type *bus,
const char *buf,
size_t count)
{
struct rbd_device *rbd_dev = NULL;
struct ceph_options *ceph_opts = NULL;
struct rbd_options *rbd_opts = NULL;
struct rbd_spec *spec = NULL;
struct rbd_client *rbdc;
bool read_only;
int rc;
if (!try_module_get(THIS_MODULE))
return -ENODEV;
rc = rbd_add_parse_args(buf, &ceph_opts, &rbd_opts, &spec);
if (rc < 0)
goto out;
rbdc = rbd_get_client(ceph_opts);
if (IS_ERR(rbdc)) {
rc = PTR_ERR(rbdc);
goto err_out_args;
}
rc = rbd_add_get_pool_id(rbdc, spec->pool_name);
if (rc < 0) {
if (rc == -ENOENT)
pr_info("pool %s does not exist\n", spec->pool_name);
goto err_out_client;
}
spec->pool_id = (u64)rc;
rbd_dev = rbd_dev_create(rbdc, spec, rbd_opts);
if (!rbd_dev) {
rc = -ENOMEM;
goto err_out_client;
}
rbdc = NULL;
spec = NULL;
rbd_opts = NULL;
rbd_dev->config_info = kstrdup(buf, GFP_KERNEL);
if (!rbd_dev->config_info) {
rc = -ENOMEM;
goto err_out_rbd_dev;
}
down_write(&rbd_dev->header_rwsem);
rc = rbd_dev_image_probe(rbd_dev, 0);
if (rc < 0) {
up_write(&rbd_dev->header_rwsem);
goto err_out_rbd_dev;
}
read_only = rbd_dev->opts->read_only;
if (rbd_dev->spec->snap_id != CEPH_NOSNAP)
read_only = true;
rbd_dev->mapping.read_only = read_only;
rc = rbd_dev_device_setup(rbd_dev);
if (rc)
goto err_out_image_probe;
if (rbd_dev->opts->exclusive) {
rc = rbd_add_acquire_lock(rbd_dev);
if (rc)
goto err_out_device_setup;
}
rc = device_add(&rbd_dev->dev);
if (rc)
goto err_out_image_lock;
add_disk(rbd_dev->disk);
blk_put_queue(rbd_dev->disk->queue);
spin_lock(&rbd_dev_list_lock);
list_add_tail(&rbd_dev->node, &rbd_dev_list);
spin_unlock(&rbd_dev_list_lock);
pr_info("%s: capacity %llu features 0x%llx\n", rbd_dev->disk->disk_name,
(unsigned long long)get_capacity(rbd_dev->disk) << SECTOR_SHIFT,
rbd_dev->header.features);
rc = count;
out:
module_put(THIS_MODULE);
return rc;
err_out_image_lock:
rbd_dev_image_unlock(rbd_dev);
err_out_device_setup:
rbd_dev_device_release(rbd_dev);
err_out_image_probe:
rbd_dev_image_release(rbd_dev);
err_out_rbd_dev:
rbd_dev_destroy(rbd_dev);
err_out_client:
rbd_put_client(rbdc);
err_out_args:
rbd_spec_put(spec);
kfree(rbd_opts);
goto out;
}
static ssize_t rbd_add(struct bus_type *bus,
const char *buf,
size_t count)
{
if (single_major)
return -EINVAL;
return do_rbd_add(bus, buf, count);
}
static ssize_t rbd_add_single_major(struct bus_type *bus,
const char *buf,
size_t count)
{
return do_rbd_add(bus, buf, count);
}
static void rbd_dev_remove_parent(struct rbd_device *rbd_dev)
{
while (rbd_dev->parent) {
struct rbd_device *first = rbd_dev;
struct rbd_device *second = first->parent;
struct rbd_device *third;
while (second && (third = second->parent)) {
first = second;
second = third;
}
rbd_assert(second);
rbd_dev_image_release(second);
rbd_dev_destroy(second);
first->parent = NULL;
first->parent_overlap = 0;
rbd_assert(first->parent_spec);
rbd_spec_put(first->parent_spec);
first->parent_spec = NULL;
}
}
static ssize_t do_rbd_remove(struct bus_type *bus,
const char *buf,
size_t count)
{
struct rbd_device *rbd_dev = NULL;
struct list_head *tmp;
int dev_id;
char opt_buf[6];
bool already = false;
bool force = false;
int ret;
dev_id = -1;
opt_buf[0] = '\0';
sscanf(buf, "%d %5s", &dev_id, opt_buf);
if (dev_id < 0) {
pr_err("dev_id out of range\n");
return -EINVAL;
}
if (opt_buf[0] != '\0') {
if (!strcmp(opt_buf, "force")) {
force = true;
} else {
pr_err("bad remove option at '%s'\n", opt_buf);
return -EINVAL;
}
}
ret = -ENOENT;
spin_lock(&rbd_dev_list_lock);
list_for_each(tmp, &rbd_dev_list) {
rbd_dev = list_entry(tmp, struct rbd_device, node);
if (rbd_dev->dev_id == dev_id) {
ret = 0;
break;
}
}
if (!ret) {
spin_lock_irq(&rbd_dev->lock);
if (rbd_dev->open_count && !force)
ret = -EBUSY;
else
already = test_and_set_bit(RBD_DEV_FLAG_REMOVING,
&rbd_dev->flags);
spin_unlock_irq(&rbd_dev->lock);
}
spin_unlock(&rbd_dev_list_lock);
if (ret < 0 || already)
return ret;
if (force) {
blk_mq_freeze_queue(rbd_dev->disk->queue);
blk_set_queue_dying(rbd_dev->disk->queue);
}
del_gendisk(rbd_dev->disk);
spin_lock(&rbd_dev_list_lock);
list_del_init(&rbd_dev->node);
spin_unlock(&rbd_dev_list_lock);
device_del(&rbd_dev->dev);
rbd_dev_image_unlock(rbd_dev);
rbd_dev_device_release(rbd_dev);
rbd_dev_image_release(rbd_dev);
rbd_dev_destroy(rbd_dev);
return count;
}
static ssize_t rbd_remove(struct bus_type *bus,
const char *buf,
size_t count)
{
if (single_major)
return -EINVAL;
return do_rbd_remove(bus, buf, count);
}
static ssize_t rbd_remove_single_major(struct bus_type *bus,
const char *buf,
size_t count)
{
return do_rbd_remove(bus, buf, count);
}
static int rbd_sysfs_init(void)
{
int ret;
ret = device_register(&rbd_root_dev);
if (ret < 0)
return ret;
ret = bus_register(&rbd_bus_type);
if (ret < 0)
device_unregister(&rbd_root_dev);
return ret;
}
static void rbd_sysfs_cleanup(void)
{
bus_unregister(&rbd_bus_type);
device_unregister(&rbd_root_dev);
}
static int rbd_slab_init(void)
{
rbd_assert(!rbd_img_request_cache);
rbd_img_request_cache = KMEM_CACHE(rbd_img_request, 0);
if (!rbd_img_request_cache)
return -ENOMEM;
rbd_assert(!rbd_obj_request_cache);
rbd_obj_request_cache = KMEM_CACHE(rbd_obj_request, 0);
if (!rbd_obj_request_cache)
goto out_err;
return 0;
out_err:
kmem_cache_destroy(rbd_img_request_cache);
rbd_img_request_cache = NULL;
return -ENOMEM;
}
static void rbd_slab_exit(void)
{
rbd_assert(rbd_obj_request_cache);
kmem_cache_destroy(rbd_obj_request_cache);
rbd_obj_request_cache = NULL;
rbd_assert(rbd_img_request_cache);
kmem_cache_destroy(rbd_img_request_cache);
rbd_img_request_cache = NULL;
}
static int __init rbd_init(void)
{
int rc;
if (!libceph_compatible(NULL)) {
rbd_warn(NULL, "libceph incompatibility (quitting)");
return -EINVAL;
}
rc = rbd_slab_init();
if (rc)
return rc;
rbd_wq = alloc_workqueue(RBD_DRV_NAME, WQ_MEM_RECLAIM, 0);
if (!rbd_wq) {
rc = -ENOMEM;
goto err_out_slab;
}
if (single_major) {
rbd_major = register_blkdev(0, RBD_DRV_NAME);
if (rbd_major < 0) {
rc = rbd_major;
goto err_out_wq;
}
}
rc = rbd_sysfs_init();
if (rc)
goto err_out_blkdev;
if (single_major)
pr_info("loaded (major %d)\n", rbd_major);
else
pr_info("loaded\n");
return 0;
err_out_blkdev:
if (single_major)
unregister_blkdev(rbd_major, RBD_DRV_NAME);
err_out_wq:
destroy_workqueue(rbd_wq);
err_out_slab:
rbd_slab_exit();
return rc;
}
static void __exit rbd_exit(void)
{
ida_destroy(&rbd_dev_id_ida);
rbd_sysfs_cleanup();
if (single_major)
unregister_blkdev(rbd_major, RBD_DRV_NAME);
destroy_workqueue(rbd_wq);
rbd_slab_exit();
}
