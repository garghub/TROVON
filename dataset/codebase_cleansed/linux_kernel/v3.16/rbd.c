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
rbdc->client = ceph_create_client(ceph_opts, rbdc, 0, 0);
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
if (token < 0)
return -EINVAL;
if (token < Opt_last_int) {
ret = match_int(&argstr[0], &intval);
if (ret < 0) {
pr_err("bad mount option arg (not int) "
"at '%s'\n", c);
return ret;
}
dout("got int token %d val %d\n", token, intval);
} else if (token > Opt_last_int && token < Opt_last_string) {
dout("got string token %d val %s\n", token,
argstr[0].from);
} else if (token > Opt_last_string && token < Opt_last_bool) {
dout("got Boolean token %d\n", token);
} else {
dout("got token %d\n", token);
}
switch (token) {
case Opt_read_only:
rbd_opts->read_only = true;
break;
case Opt_read_write:
rbd_opts->read_only = false;
break;
default:
rbd_assert(false);
break;
}
return 0;
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
size_t size;
int ret = -ENOMEM;
u32 i;
if (first_time) {
size_t len;
len = strnlen(ondisk->object_prefix,
sizeof (ondisk->object_prefix));
object_prefix = kmalloc(len + 1, GFP_KERNEL);
if (!object_prefix)
return -ENOMEM;
memcpy(object_prefix, ondisk->object_prefix, len);
object_prefix[len] = '\0';
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
size = snap_count * sizeof (*header->snap_sizes);
snap_sizes = kmalloc(size, GFP_KERNEL);
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
header->crypt_type = ondisk->options.crypt_type;
header->comp_type = ondisk->options.comp_type;
header->stripe_unit = 0;
header->stripe_count = 0;
header->features = 0;
} else {
ceph_put_snap_context(header->snapc);
kfree(header->snap_names);
kfree(header->snap_sizes);
}
header->image_size = le64_to_cpu(ondisk->image_size);
header->snapc = snapc;
header->snap_names = snap_names;
header->snap_sizes = snap_sizes;
if (rbd_dev->spec->snap_id == CEPH_NOSNAP || first_time)
if (rbd_dev->mapping.size != header->image_size)
rbd_dev->mapping.size = header->image_size;
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
static const char *rbd_segment_name(struct rbd_device *rbd_dev, u64 offset)
{
char *name;
u64 segment;
int ret;
char *name_format;
name = kmem_cache_alloc(rbd_segment_name_cache, GFP_NOIO);
if (!name)
return NULL;
segment = offset >> rbd_dev->header.obj_order;
name_format = "%s.%012llx";
if (rbd_dev->image_format == 2)
name_format = "%s.%016llx";
ret = snprintf(name, CEPH_MAX_OID_NAME_LEN + 1, name_format,
rbd_dev->header.object_prefix, segment);
if (ret < 0 || ret > CEPH_MAX_OID_NAME_LEN) {
pr_err("error formatting segment name for #%llu (%d)\n",
segment, ret);
kfree(name);
name = NULL;
}
return name;
}
static void rbd_segment_name_free(const char *name)
{
kmem_cache_free(rbd_segment_name_cache, (void *)name);
}
static u64 rbd_segment_offset(struct rbd_device *rbd_dev, u64 offset)
{
u64 segment_size = (u64) 1 << rbd_dev->header.obj_order;
return offset & (segment_size - 1);
}
static u64 rbd_segment_length(struct rbd_device *rbd_dev,
u64 offset, u64 length)
{
u64 segment_size = (u64) 1 << rbd_dev->header.obj_order;
offset &= segment_size - 1;
rbd_assert(length <= U64_MAX - offset);
if (offset + length > segment_size)
length = segment_size - offset;
return length;
}
static u64 rbd_obj_bytes(struct rbd_image_header *header)
{
return 1 << header->obj_order;
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
rbd_warn(rbd_dev, "obj_request %p already marked img_data\n",
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
rbd_warn(rbd_dev, "obj_request %p already marked done\n",
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
atomic_read(&obj_request->kref.refcount));
kref_get(&obj_request->kref);
}
static void rbd_obj_request_put(struct rbd_obj_request *obj_request)
{
rbd_assert(obj_request != NULL);
dout("%s: obj %p (was %d)\n", __func__, obj_request,
atomic_read(&obj_request->kref.refcount));
kref_put(&obj_request->kref, rbd_obj_request_destroy);
}
static void rbd_img_request_get(struct rbd_img_request *img_request)
{
dout("%s: img %p (was %d)\n", __func__, img_request,
atomic_read(&img_request->kref.refcount));
kref_get(&img_request->kref);
}
static void rbd_img_request_put(struct rbd_img_request *img_request)
{
rbd_assert(img_request != NULL);
dout("%s: img %p (was %d)\n", __func__, img_request,
atomic_read(&img_request->kref.refcount));
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
static int rbd_obj_request_submit(struct ceph_osd_client *osdc,
struct rbd_obj_request *obj_request)
{
dout("%s: osdc %p obj %p\n", __func__, osdc, obj_request);
return ceph_osdc_start_request(osdc, obj_request->osd_req, false);
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
static int rbd_obj_request_wait(struct rbd_obj_request *obj_request)
{
dout("%s: obj %p\n", __func__, obj_request);
return wait_for_completion_interruptible(&obj_request->completion);
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
static void rbd_osd_trivial_callback(struct rbd_obj_request *obj_request)
{
dout("%s: obj %p\n", __func__, obj_request);
obj_request_done_set(obj_request);
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
static void rbd_osd_stat_callback(struct rbd_obj_request *obj_request)
{
dout("%s: obj %p\n", __func__, obj_request);
obj_request_done_set(obj_request);
}
static void rbd_osd_req_callback(struct ceph_osd_request *osd_req,
struct ceph_msg *msg)
{
struct rbd_obj_request *obj_request = osd_req->r_priv;
u16 opcode;
dout("%s: osd_req %p msg %p\n", __func__, osd_req, msg);
rbd_assert(osd_req == obj_request->osd_req);
if (obj_request_img_data_test(obj_request)) {
rbd_assert(obj_request->img_request);
rbd_assert(obj_request->which != BAD_WHICH);
} else {
rbd_assert(obj_request->which == BAD_WHICH);
}
if (osd_req->r_result < 0)
obj_request->result = osd_req->r_result;
rbd_assert(osd_req->r_num_ops <= CEPH_OSD_MAX_OP);
obj_request->xferred = osd_req->r_reply_op_len[0];
rbd_assert(obj_request->xferred < (u64)UINT_MAX);
opcode = osd_req->r_ops[0].op;
switch (opcode) {
case CEPH_OSD_OP_READ:
rbd_osd_read_callback(obj_request);
break;
case CEPH_OSD_OP_SETALLOCHINT:
rbd_assert(osd_req->r_ops[1].op == CEPH_OSD_OP_WRITE);
case CEPH_OSD_OP_WRITE:
rbd_osd_write_callback(obj_request);
break;
case CEPH_OSD_OP_STAT:
rbd_osd_stat_callback(obj_request);
break;
case CEPH_OSD_OP_CALL:
case CEPH_OSD_OP_NOTIFY_ACK:
case CEPH_OSD_OP_WATCH:
rbd_osd_trivial_callback(obj_request);
break;
default:
rbd_warn(NULL, "%s: unsupported op %hu\n",
obj_request->object_name, (unsigned short) opcode);
break;
}
if (obj_request_done_test(obj_request))
rbd_obj_request_complete(obj_request);
}
static void rbd_osd_req_format_read(struct rbd_obj_request *obj_request)
{
struct rbd_img_request *img_request = obj_request->img_request;
struct ceph_osd_request *osd_req = obj_request->osd_req;
u64 snap_id;
rbd_assert(osd_req != NULL);
snap_id = img_request ? img_request->snap_id : CEPH_NOSNAP;
ceph_osdc_build_request(osd_req, obj_request->offset,
NULL, snap_id, NULL);
}
static void rbd_osd_req_format_write(struct rbd_obj_request *obj_request)
{
struct rbd_img_request *img_request = obj_request->img_request;
struct ceph_osd_request *osd_req = obj_request->osd_req;
struct ceph_snap_context *snapc;
struct timespec mtime = CURRENT_TIME;
rbd_assert(osd_req != NULL);
snapc = img_request ? img_request->snapc : NULL;
ceph_osdc_build_request(osd_req, obj_request->offset,
snapc, CEPH_NOSNAP, &mtime);
}
static struct ceph_osd_request *rbd_osd_req_create(
struct rbd_device *rbd_dev,
bool write_request,
unsigned int num_ops,
struct rbd_obj_request *obj_request)
{
struct ceph_snap_context *snapc = NULL;
struct ceph_osd_client *osdc;
struct ceph_osd_request *osd_req;
if (obj_request_img_data_test(obj_request)) {
struct rbd_img_request *img_request = obj_request->img_request;
rbd_assert(write_request ==
img_request_write_test(img_request));
if (write_request)
snapc = img_request->snapc;
}
rbd_assert(num_ops == 1 || (write_request && num_ops == 2));
osdc = &rbd_dev->rbd_client->client->osdc;
osd_req = ceph_osdc_alloc_request(osdc, snapc, num_ops, false,
GFP_ATOMIC);
if (!osd_req)
return NULL;
if (write_request)
osd_req->r_flags = CEPH_OSD_FLAG_WRITE | CEPH_OSD_FLAG_ONDISK;
else
osd_req->r_flags = CEPH_OSD_FLAG_READ;
osd_req->r_callback = rbd_osd_req_callback;
osd_req->r_priv = obj_request;
osd_req->r_base_oloc.pool = ceph_file_layout_pg_pool(rbd_dev->layout);
ceph_oid_set_name(&osd_req->r_base_oid, obj_request->object_name);
return osd_req;
}
static struct ceph_osd_request *
rbd_osd_req_create_copyup(struct rbd_obj_request *obj_request)
{
struct rbd_img_request *img_request;
struct ceph_snap_context *snapc;
struct rbd_device *rbd_dev;
struct ceph_osd_client *osdc;
struct ceph_osd_request *osd_req;
rbd_assert(obj_request_img_data_test(obj_request));
img_request = obj_request->img_request;
rbd_assert(img_request);
rbd_assert(img_request_write_test(img_request));
snapc = img_request->snapc;
rbd_dev = img_request->rbd_dev;
osdc = &rbd_dev->rbd_client->client->osdc;
osd_req = ceph_osdc_alloc_request(osdc, snapc, 3, false, GFP_ATOMIC);
if (!osd_req)
return NULL;
osd_req->r_flags = CEPH_OSD_FLAG_WRITE | CEPH_OSD_FLAG_ONDISK;
osd_req->r_callback = rbd_osd_req_callback;
osd_req->r_priv = obj_request;
osd_req->r_base_oloc.pool = ceph_file_layout_pg_pool(rbd_dev->layout);
ceph_oid_set_name(&osd_req->r_base_oid, obj_request->object_name);
return osd_req;
}
static void rbd_osd_req_destroy(struct ceph_osd_request *osd_req)
{
ceph_osdc_put_request(osd_req);
}
static struct rbd_obj_request *rbd_obj_request_create(const char *object_name,
u64 offset, u64 length,
enum obj_request_type type)
{
struct rbd_obj_request *obj_request;
size_t size;
char *name;
rbd_assert(obj_request_type_valid(type));
size = strlen(object_name) + 1;
name = kmalloc(size, GFP_KERNEL);
if (!name)
return NULL;
obj_request = kmem_cache_zalloc(rbd_obj_request_cache, GFP_KERNEL);
if (!obj_request) {
kfree(name);
return NULL;
}
obj_request->object_name = memcpy(name, object_name, size);
obj_request->offset = offset;
obj_request->length = length;
obj_request->flags = 0;
obj_request->which = BAD_WHICH;
obj_request->type = type;
INIT_LIST_HEAD(&obj_request->links);
init_completion(&obj_request->completion);
kref_init(&obj_request->kref);
dout("%s: \"%s\" %llu/%llu %d -> obj %p\n", __func__, object_name,
offset, length, (int)type, obj_request);
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
if (obj_request->pages)
ceph_release_page_vector(obj_request->pages,
obj_request->page_count);
break;
}
kfree(obj_request->object_name);
obj_request->object_name = NULL;
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
rbd_warn(rbd_dev, "parent reference underflow\n");
}
static bool rbd_dev_parent_get(struct rbd_device *rbd_dev)
{
int counter;
if (!rbd_dev->parent_spec)
return false;
counter = atomic_inc_return_safe(&rbd_dev->parent_ref);
if (counter > 0 && rbd_dev->parent_overlap)
return true;
if (counter < 0)
rbd_warn(rbd_dev, "parent reference overflow\n");
return false;
}
static struct rbd_img_request *rbd_img_request_create(
struct rbd_device *rbd_dev,
u64 offset, u64 length,
bool write_request)
{
struct rbd_img_request *img_request;
img_request = kmem_cache_alloc(rbd_img_request_cache, GFP_ATOMIC);
if (!img_request)
return NULL;
if (write_request) {
down_read(&rbd_dev->header_rwsem);
ceph_get_snap_context(rbd_dev->header.snapc);
up_read(&rbd_dev->header_rwsem);
}
img_request->rq = NULL;
img_request->rbd_dev = rbd_dev;
img_request->offset = offset;
img_request->length = length;
img_request->flags = 0;
if (write_request) {
img_request_write_set(img_request);
img_request->snapc = rbd_dev->header.snapc;
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
write_request ? "write" : "read", offset, length,
img_request);
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
if (img_request_write_test(img_request))
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
parent_request = rbd_img_request_create(rbd_dev->parent,
img_offset, length, false);
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
rbd_warn(rbd_dev, "%s %llx at %llx (%llx)\n",
img_request_write_test(img_request) ? "write" : "read",
obj_request->length, obj_request->img_offset,
obj_request->offset);
rbd_warn(rbd_dev, " result %d xferred %x\n",
result, xferred);
if (!img_request->result)
img_request->result = result;
}
if (obj_request->type == OBJ_REQUEST_PAGES) {
obj_request->pages = NULL;
obj_request->page_count = 0;
}
if (img_request_child_test(img_request)) {
rbd_assert(img_request->obj_request != NULL);
more = obj_request->which < img_request->obj_request_count - 1;
} else {
rbd_assert(img_request->rq != NULL);
more = blk_end_request(img_request->rq, result, xferred);
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
static int rbd_img_request_fill(struct rbd_img_request *img_request,
enum obj_request_type type,
void *data_desc)
{
struct rbd_device *rbd_dev = img_request->rbd_dev;
struct rbd_obj_request *obj_request = NULL;
struct rbd_obj_request *next_obj_request;
bool write_request = img_request_write_test(img_request);
struct bio *bio_list = NULL;
unsigned int bio_offset = 0;
struct page **pages = NULL;
u64 img_offset;
u64 resid;
u16 opcode;
dout("%s: img %p type %d data_desc %p\n", __func__, img_request,
(int)type, data_desc);
opcode = write_request ? CEPH_OSD_OP_WRITE : CEPH_OSD_OP_READ;
img_offset = img_request->offset;
resid = img_request->length;
rbd_assert(resid > 0);
if (type == OBJ_REQUEST_BIO) {
bio_list = data_desc;
rbd_assert(img_offset ==
bio_list->bi_iter.bi_sector << SECTOR_SHIFT);
} else {
rbd_assert(type == OBJ_REQUEST_PAGES);
pages = data_desc;
}
while (resid) {
struct ceph_osd_request *osd_req;
const char *object_name;
u64 offset;
u64 length;
unsigned int which = 0;
object_name = rbd_segment_name(rbd_dev, img_offset);
if (!object_name)
goto out_unwind;
offset = rbd_segment_offset(rbd_dev, img_offset);
length = rbd_segment_length(rbd_dev, img_offset, resid);
obj_request = rbd_obj_request_create(object_name,
offset, length, type);
rbd_segment_name_free(object_name);
if (!obj_request)
goto out_unwind;
rbd_img_obj_request_add(img_request, obj_request);
if (type == OBJ_REQUEST_BIO) {
unsigned int clone_size;
rbd_assert(length <= (u64)UINT_MAX);
clone_size = (unsigned int)length;
obj_request->bio_list =
bio_chain_clone_range(&bio_list,
&bio_offset,
clone_size,
GFP_ATOMIC);
if (!obj_request->bio_list)
goto out_unwind;
} else {
unsigned int page_count;
obj_request->pages = pages;
page_count = (u32)calc_pages_for(offset, length);
obj_request->page_count = page_count;
if ((offset + length) & ~PAGE_MASK)
page_count--;
pages += page_count;
}
osd_req = rbd_osd_req_create(rbd_dev, write_request,
(write_request ? 2 : 1),
obj_request);
if (!osd_req)
goto out_unwind;
obj_request->osd_req = osd_req;
obj_request->callback = rbd_img_obj_callback;
rbd_img_request_get(img_request);
if (write_request) {
osd_req_op_alloc_hint_init(osd_req, which,
rbd_obj_bytes(&rbd_dev->header),
rbd_obj_bytes(&rbd_dev->header));
which++;
}
osd_req_op_extent_init(osd_req, which, opcode, offset, length,
0, 0);
if (type == OBJ_REQUEST_BIO)
osd_req_op_extent_osd_data_bio(osd_req, which,
obj_request->bio_list, length);
else
osd_req_op_extent_osd_data_pages(osd_req, which,
obj_request->pages, length,
offset & ~PAGE_MASK, false, false);
if (write_request)
rbd_osd_req_format_write(obj_request);
else
rbd_osd_req_format_read(obj_request);
obj_request->img_offset = img_offset;
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
rbd_img_obj_copyup_callback(struct rbd_obj_request *obj_request)
{
struct rbd_img_request *img_request;
struct rbd_device *rbd_dev;
struct page **pages;
u32 page_count;
rbd_assert(obj_request->type == OBJ_REQUEST_BIO);
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
rbd_img_obj_callback(obj_request);
}
static void
rbd_img_obj_parent_read_full_callback(struct rbd_img_request *img_request)
{
struct rbd_obj_request *orig_request;
struct ceph_osd_request *osd_req;
struct ceph_osd_client *osdc;
struct rbd_device *rbd_dev;
struct page **pages;
u32 page_count;
int img_result;
u64 parent_length;
u64 offset;
u64 length;
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
rbd_assert(parent_length == img_request->xferred);
rbd_img_request_put(img_request);
rbd_assert(orig_request->img_request);
rbd_dev = orig_request->img_request->rbd_dev;
rbd_assert(rbd_dev);
if (!rbd_dev->parent_overlap) {
struct ceph_osd_client *osdc;
ceph_release_page_vector(pages, page_count);
osdc = &rbd_dev->rbd_client->client->osdc;
img_result = rbd_obj_request_submit(osdc, orig_request);
if (!img_result)
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
osd_req_op_alloc_hint_init(osd_req, 1, rbd_obj_bytes(&rbd_dev->header),
rbd_obj_bytes(&rbd_dev->header));
offset = orig_request->offset;
length = orig_request->length;
osd_req_op_extent_init(osd_req, 2, CEPH_OSD_OP_WRITE,
offset, length, 0, 0);
if (orig_request->type == OBJ_REQUEST_BIO)
osd_req_op_extent_osd_data_bio(osd_req, 2,
orig_request->bio_list, length);
else
osd_req_op_extent_osd_data_pages(osd_req, 2,
orig_request->pages, length,
offset & ~PAGE_MASK, false, false);
rbd_osd_req_format_write(orig_request);
orig_request->callback = rbd_img_obj_copyup_callback;
osdc = &rbd_dev->rbd_client->client->osdc;
img_result = rbd_obj_request_submit(osdc, orig_request);
if (!img_result)
return;
out_err:
orig_request->result = img_result;
orig_request->xferred = 0;
obj_request_done_set(orig_request);
rbd_obj_request_complete(orig_request);
}
static int rbd_img_obj_parent_read_full(struct rbd_obj_request *obj_request)
{
struct rbd_img_request *img_request = NULL;
struct rbd_img_request *parent_request = NULL;
struct rbd_device *rbd_dev;
u64 img_offset;
u64 length;
struct page **pages = NULL;
u32 page_count;
int result;
rbd_assert(obj_request_img_data_test(obj_request));
rbd_assert(obj_request_type_valid(obj_request->type));
img_request = obj_request->img_request;
rbd_assert(img_request != NULL);
rbd_dev = img_request->rbd_dev;
rbd_assert(rbd_dev->parent != NULL);
img_offset = obj_request->img_offset - obj_request->offset;
length = (u64)1 << rbd_dev->header.obj_order;
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
obj_request->result = result;
obj_request->xferred = 0;
obj_request_done_set(obj_request);
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
struct ceph_osd_client *osdc;
osdc = &rbd_dev->rbd_client->client->osdc;
result = rbd_obj_request_submit(osdc, orig_request);
if (!result)
return;
}
if (!result) {
obj_request_existence_set(orig_request, true);
} else if (result == -ENOENT) {
obj_request_existence_set(orig_request, false);
} else if (result) {
orig_request->result = result;
goto out;
}
orig_request->result = rbd_img_obj_request_submit(orig_request);
out:
if (orig_request->result)
rbd_obj_request_complete(orig_request);
}
static int rbd_img_obj_exists_submit(struct rbd_obj_request *obj_request)
{
struct rbd_obj_request *stat_request;
struct rbd_device *rbd_dev;
struct ceph_osd_client *osdc;
struct page **pages = NULL;
u32 page_count;
size_t size;
int ret;
size = sizeof (__le64) + sizeof (__le32) + sizeof (__le32);
page_count = (u32)calc_pages_for(0, size);
pages = ceph_alloc_page_vector(page_count, GFP_KERNEL);
if (IS_ERR(pages))
return PTR_ERR(pages);
ret = -ENOMEM;
stat_request = rbd_obj_request_create(obj_request->object_name, 0, 0,
OBJ_REQUEST_PAGES);
if (!stat_request)
goto out;
rbd_obj_request_get(obj_request);
stat_request->obj_request = obj_request;
stat_request->pages = pages;
stat_request->page_count = page_count;
rbd_assert(obj_request->img_request);
rbd_dev = obj_request->img_request->rbd_dev;
stat_request->osd_req = rbd_osd_req_create(rbd_dev, false, 1,
stat_request);
if (!stat_request->osd_req)
goto out;
stat_request->callback = rbd_img_obj_exists_callback;
osd_req_op_init(stat_request->osd_req, 0, CEPH_OSD_OP_STAT);
osd_req_op_raw_data_in_pages(stat_request->osd_req, 0, pages, size, 0,
false, false);
rbd_osd_req_format_read(stat_request);
osdc = &rbd_dev->rbd_client->client->osdc;
ret = rbd_obj_request_submit(osdc, stat_request);
out:
if (ret)
rbd_obj_request_put(obj_request);
return ret;
}
static int rbd_img_obj_request_submit(struct rbd_obj_request *obj_request)
{
struct rbd_img_request *img_request;
struct rbd_device *rbd_dev;
bool known;
rbd_assert(obj_request_img_data_test(obj_request));
img_request = obj_request->img_request;
rbd_assert(img_request);
rbd_dev = img_request->rbd_dev;
if (!img_request_write_test(img_request) ||
!img_request_layered_test(img_request) ||
!obj_request_overlaps_parent(obj_request) ||
((known = obj_request_known_test(obj_request)) &&
obj_request_exists_test(obj_request))) {
struct rbd_device *rbd_dev;
struct ceph_osd_client *osdc;
rbd_dev = obj_request->img_request->rbd_dev;
osdc = &rbd_dev->rbd_client->client->osdc;
return rbd_obj_request_submit(osdc, obj_request);
}
if (known)
return rbd_img_obj_parent_read_full(obj_request);
return rbd_img_obj_exists_submit(obj_request);
}
static int rbd_img_request_submit(struct rbd_img_request *img_request)
{
struct rbd_obj_request *obj_request;
struct rbd_obj_request *next_obj_request;
dout("%s: img %p\n", __func__, img_request);
for_each_obj_request_safe(img_request, obj_request, next_obj_request) {
int ret;
ret = rbd_img_obj_request_submit(obj_request);
if (ret)
return ret;
}
return 0;
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
struct ceph_osd_client *osdc;
osdc = &rbd_dev->rbd_client->client->osdc;
img_result = rbd_obj_request_submit(osdc, obj_request);
if (!img_result)
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
static int rbd_obj_notify_ack_sync(struct rbd_device *rbd_dev, u64 notify_id)
{
struct rbd_obj_request *obj_request;
struct ceph_osd_client *osdc = &rbd_dev->rbd_client->client->osdc;
int ret;
obj_request = rbd_obj_request_create(rbd_dev->header_name, 0, 0,
OBJ_REQUEST_NODATA);
if (!obj_request)
return -ENOMEM;
ret = -ENOMEM;
obj_request->osd_req = rbd_osd_req_create(rbd_dev, false, 1,
obj_request);
if (!obj_request->osd_req)
goto out;
osd_req_op_watch_init(obj_request->osd_req, 0, CEPH_OSD_OP_NOTIFY_ACK,
notify_id, 0, 0);
rbd_osd_req_format_read(obj_request);
ret = rbd_obj_request_submit(osdc, obj_request);
if (ret)
goto out;
ret = rbd_obj_request_wait(obj_request);
out:
rbd_obj_request_put(obj_request);
return ret;
}
static void rbd_watch_cb(u64 ver, u64 notify_id, u8 opcode, void *data)
{
struct rbd_device *rbd_dev = (struct rbd_device *)data;
int ret;
if (!rbd_dev)
return;
dout("%s: \"%s\" notify_id %llu opcode %u\n", __func__,
rbd_dev->header_name, (unsigned long long)notify_id,
(unsigned int)opcode);
ret = rbd_dev_refresh(rbd_dev);
if (ret)
rbd_warn(rbd_dev, "header refresh error (%d)\n", ret);
rbd_obj_notify_ack_sync(rbd_dev, notify_id);
}
static int rbd_dev_header_watch_sync(struct rbd_device *rbd_dev)
{
struct ceph_osd_client *osdc = &rbd_dev->rbd_client->client->osdc;
struct rbd_obj_request *obj_request;
int ret;
rbd_assert(!rbd_dev->watch_event);
rbd_assert(!rbd_dev->watch_request);
ret = ceph_osdc_create_event(osdc, rbd_watch_cb, rbd_dev,
&rbd_dev->watch_event);
if (ret < 0)
return ret;
rbd_assert(rbd_dev->watch_event);
obj_request = rbd_obj_request_create(rbd_dev->header_name, 0, 0,
OBJ_REQUEST_NODATA);
if (!obj_request) {
ret = -ENOMEM;
goto out_cancel;
}
obj_request->osd_req = rbd_osd_req_create(rbd_dev, true, 1,
obj_request);
if (!obj_request->osd_req) {
ret = -ENOMEM;
goto out_put;
}
ceph_osdc_set_request_linger(osdc, obj_request->osd_req);
osd_req_op_watch_init(obj_request->osd_req, 0, CEPH_OSD_OP_WATCH,
rbd_dev->watch_event->cookie, 0, 1);
rbd_osd_req_format_write(obj_request);
ret = rbd_obj_request_submit(osdc, obj_request);
if (ret)
goto out_linger;
ret = rbd_obj_request_wait(obj_request);
if (ret)
goto out_linger;
ret = obj_request->result;
if (ret)
goto out_linger;
rbd_dev->watch_request = obj_request;
return 0;
out_linger:
ceph_osdc_unregister_linger_request(osdc, obj_request->osd_req);
out_put:
rbd_obj_request_put(obj_request);
out_cancel:
ceph_osdc_cancel_event(rbd_dev->watch_event);
rbd_dev->watch_event = NULL;
return ret;
}
static int __rbd_dev_header_unwatch_sync(struct rbd_device *rbd_dev)
{
struct ceph_osd_client *osdc = &rbd_dev->rbd_client->client->osdc;
struct rbd_obj_request *obj_request;
int ret;
rbd_assert(rbd_dev->watch_event);
rbd_assert(rbd_dev->watch_request);
obj_request = rbd_obj_request_create(rbd_dev->header_name, 0, 0,
OBJ_REQUEST_NODATA);
if (!obj_request) {
ret = -ENOMEM;
goto out_cancel;
}
obj_request->osd_req = rbd_osd_req_create(rbd_dev, true, 1,
obj_request);
if (!obj_request->osd_req) {
ret = -ENOMEM;
goto out_put;
}
osd_req_op_watch_init(obj_request->osd_req, 0, CEPH_OSD_OP_WATCH,
rbd_dev->watch_event->cookie, 0, 0);
rbd_osd_req_format_write(obj_request);
ret = rbd_obj_request_submit(osdc, obj_request);
if (ret)
goto out_put;
ret = rbd_obj_request_wait(obj_request);
if (ret)
goto out_put;
ret = obj_request->result;
if (ret)
goto out_put;
ceph_osdc_unregister_linger_request(osdc,
rbd_dev->watch_request->osd_req);
rbd_obj_request_put(rbd_dev->watch_request);
rbd_dev->watch_request = NULL;
out_put:
rbd_obj_request_put(obj_request);
out_cancel:
ceph_osdc_cancel_event(rbd_dev->watch_event);
rbd_dev->watch_event = NULL;
return ret;
}
static void rbd_dev_header_unwatch_sync(struct rbd_device *rbd_dev)
{
int ret;
ret = __rbd_dev_header_unwatch_sync(rbd_dev);
if (ret) {
rbd_warn(rbd_dev, "unable to tear down watch request: %d\n",
ret);
}
}
static int rbd_obj_method_sync(struct rbd_device *rbd_dev,
const char *object_name,
const char *class_name,
const char *method_name,
const void *outbound,
size_t outbound_size,
void *inbound,
size_t inbound_size)
{
struct ceph_osd_client *osdc = &rbd_dev->rbd_client->client->osdc;
struct rbd_obj_request *obj_request;
struct page **pages;
u32 page_count;
int ret;
page_count = (u32)calc_pages_for(0, inbound_size);
pages = ceph_alloc_page_vector(page_count, GFP_KERNEL);
if (IS_ERR(pages))
return PTR_ERR(pages);
ret = -ENOMEM;
obj_request = rbd_obj_request_create(object_name, 0, inbound_size,
OBJ_REQUEST_PAGES);
if (!obj_request)
goto out;
obj_request->pages = pages;
obj_request->page_count = page_count;
obj_request->osd_req = rbd_osd_req_create(rbd_dev, false, 1,
obj_request);
if (!obj_request->osd_req)
goto out;
osd_req_op_cls_init(obj_request->osd_req, 0, CEPH_OSD_OP_CALL,
class_name, method_name);
if (outbound_size) {
struct ceph_pagelist *pagelist;
pagelist = kmalloc(sizeof (*pagelist), GFP_NOFS);
if (!pagelist)
goto out;
ceph_pagelist_init(pagelist);
ceph_pagelist_append(pagelist, outbound, outbound_size);
osd_req_op_cls_request_data_pagelist(obj_request->osd_req, 0,
pagelist);
}
osd_req_op_cls_response_data_pages(obj_request->osd_req, 0,
obj_request->pages, inbound_size,
0, false, false);
rbd_osd_req_format_read(obj_request);
ret = rbd_obj_request_submit(osdc, obj_request);
if (ret)
goto out;
ret = rbd_obj_request_wait(obj_request);
if (ret)
goto out;
ret = obj_request->result;
if (ret < 0)
goto out;
rbd_assert(obj_request->xferred < (u64)INT_MAX);
ret = (int)obj_request->xferred;
ceph_copy_from_page_vector(pages, inbound, 0, obj_request->xferred);
out:
if (obj_request)
rbd_obj_request_put(obj_request);
else
ceph_release_page_vector(pages, page_count);
return ret;
}
static void rbd_request_fn(struct request_queue *q)
__releases(q->queue_lock) __acquires(q->queue_lock)
{
struct rbd_device *rbd_dev = q->queuedata;
struct request *rq;
int result;
while ((rq = blk_fetch_request(q))) {
bool write_request = rq_data_dir(rq) == WRITE;
struct rbd_img_request *img_request;
u64 offset;
u64 length;
if (rq->cmd_type != REQ_TYPE_FS) {
dout("%s: non-fs request type %d\n", __func__,
(int) rq->cmd_type);
__blk_end_request_all(rq, 0);
continue;
}
offset = (u64) blk_rq_pos(rq) << SECTOR_SHIFT;
length = (u64) blk_rq_bytes(rq);
if (!length) {
dout("%s: zero-length request\n", __func__);
__blk_end_request_all(rq, 0);
continue;
}
spin_unlock_irq(q->queue_lock);
if (write_request) {
result = -EROFS;
if (rbd_dev->mapping.read_only)
goto end_request;
rbd_assert(rbd_dev->spec->snap_id == CEPH_NOSNAP);
}
if (!test_bit(RBD_DEV_FLAG_EXISTS, &rbd_dev->flags)) {
dout("request for non-existent snapshot");
rbd_assert(rbd_dev->spec->snap_id != CEPH_NOSNAP);
result = -ENXIO;
goto end_request;
}
result = -EINVAL;
if (offset && length > U64_MAX - offset + 1) {
rbd_warn(rbd_dev, "bad request range (%llu~%llu)\n",
offset, length);
goto end_request;
}
result = -EIO;
if (offset + length > rbd_dev->mapping.size) {
rbd_warn(rbd_dev, "beyond EOD (%llu~%llu > %llu)\n",
offset, length, rbd_dev->mapping.size);
goto end_request;
}
result = -ENOMEM;
img_request = rbd_img_request_create(rbd_dev, offset, length,
write_request);
if (!img_request)
goto end_request;
img_request->rq = rq;
result = rbd_img_request_fill(img_request, OBJ_REQUEST_BIO,
rq->bio);
if (!result)
result = rbd_img_request_submit(img_request);
if (result)
rbd_img_request_put(img_request);
end_request:
spin_lock_irq(q->queue_lock);
if (result < 0) {
rbd_warn(rbd_dev, "%s %llx at %llx result %d\n",
write_request ? "write" : "read",
length, offset, result);
__blk_end_request_all(rq, result);
}
}
}
static int rbd_merge_bvec(struct request_queue *q, struct bvec_merge_data *bmd,
struct bio_vec *bvec)
{
struct rbd_device *rbd_dev = q->queuedata;
sector_t sector_offset;
sector_t sectors_per_obj;
sector_t obj_sector_offset;
int ret;
sector_offset = get_start_sect(bmd->bi_bdev) + bmd->bi_sector;
sectors_per_obj = 1 << (rbd_dev->header.obj_order - SECTOR_SHIFT);
obj_sector_offset = sector_offset & (sectors_per_obj - 1);
ret = (int) (sectors_per_obj - obj_sector_offset) << SECTOR_SHIFT;
if (ret > bmd->bi_size)
ret -= bmd->bi_size;
else
ret = 0;
rbd_assert(bvec->bv_len <= PAGE_SIZE);
if (ret > (int) bvec->bv_len || !bmd->bi_size)
ret = (int) bvec->bv_len;
return ret;
}
static void rbd_free_disk(struct rbd_device *rbd_dev)
{
struct gendisk *disk = rbd_dev->disk;
if (!disk)
return;
rbd_dev->disk = NULL;
if (disk->flags & GENHD_FL_UP) {
del_gendisk(disk);
if (disk->queue)
blk_cleanup_queue(disk->queue);
}
put_disk(disk);
}
static int rbd_obj_read_sync(struct rbd_device *rbd_dev,
const char *object_name,
u64 offset, u64 length, void *buf)
{
struct ceph_osd_client *osdc = &rbd_dev->rbd_client->client->osdc;
struct rbd_obj_request *obj_request;
struct page **pages = NULL;
u32 page_count;
size_t size;
int ret;
page_count = (u32) calc_pages_for(offset, length);
pages = ceph_alloc_page_vector(page_count, GFP_KERNEL);
if (IS_ERR(pages))
ret = PTR_ERR(pages);
ret = -ENOMEM;
obj_request = rbd_obj_request_create(object_name, offset, length,
OBJ_REQUEST_PAGES);
if (!obj_request)
goto out;
obj_request->pages = pages;
obj_request->page_count = page_count;
obj_request->osd_req = rbd_osd_req_create(rbd_dev, false, 1,
obj_request);
if (!obj_request->osd_req)
goto out;
osd_req_op_extent_init(obj_request->osd_req, 0, CEPH_OSD_OP_READ,
offset, length, 0, 0);
osd_req_op_extent_osd_data_pages(obj_request->osd_req, 0,
obj_request->pages,
obj_request->length,
obj_request->offset & ~PAGE_MASK,
false, false);
rbd_osd_req_format_read(obj_request);
ret = rbd_obj_request_submit(osdc, obj_request);
if (ret)
goto out;
ret = rbd_obj_request_wait(obj_request);
if (ret)
goto out;
ret = obj_request->result;
if (ret < 0)
goto out;
rbd_assert(obj_request->xferred <= (u64) SIZE_MAX);
size = (size_t) obj_request->xferred;
ceph_copy_from_page_vector(pages, buf, 0, size);
rbd_assert(size <= (size_t)INT_MAX);
ret = (int)size;
out:
if (obj_request)
rbd_obj_request_put(obj_request);
else
ceph_release_page_vector(pages, page_count);
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
ret = rbd_obj_read_sync(rbd_dev, rbd_dev->header_name,
0, size, ondisk);
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
bool removing;
spin_lock_irq(&rbd_dev->lock);
removing = test_bit(RBD_DEV_FLAG_REMOVING, &rbd_dev->flags);
spin_unlock_irq(&rbd_dev->lock);
if (!removing) {
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
rbd_assert(rbd_image_format_valid(rbd_dev->image_format));
down_write(&rbd_dev->header_rwsem);
mapping_size = rbd_dev->mapping.size;
if (rbd_dev->image_format == 1)
ret = rbd_dev_v1_header_info(rbd_dev);
else
ret = rbd_dev_v2_header_info(rbd_dev);
rbd_exists_validate(rbd_dev);
up_write(&rbd_dev->header_rwsem);
if (mapping_size != rbd_dev->mapping.size) {
rbd_dev_update_size(rbd_dev);
}
return ret;
}
static int rbd_init_disk(struct rbd_device *rbd_dev)
{
struct gendisk *disk;
struct request_queue *q;
u64 segment_size;
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
q = blk_init_queue(rbd_request_fn, &rbd_dev->lock);
if (!q)
goto out_disk;
blk_queue_physical_block_size(q, SECTOR_SIZE);
segment_size = rbd_obj_bytes(&rbd_dev->header);
blk_queue_max_hw_sectors(q, segment_size / SECTOR_SIZE);
blk_queue_max_segment_size(q, segment_size);
blk_queue_io_min(q, segment_size);
blk_queue_io_opt(q, segment_size);
blk_queue_merge_bvec(q, rbd_merge_bvec);
disk->queue = q;
q->queuedata = rbd_dev;
rbd_dev->disk = disk;
return 0;
out_disk:
put_disk(disk);
return -ENOMEM;
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
static ssize_t rbd_client_id_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct rbd_device *rbd_dev = dev_to_rbd_dev(dev);
return sprintf(buf, "client%lld\n",
ceph_client_id(rbd_dev->rbd_client->client));
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
static ssize_t rbd_parent_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct rbd_device *rbd_dev = dev_to_rbd_dev(dev);
struct rbd_spec *spec = rbd_dev->parent_spec;
int count;
char *bufp = buf;
if (!spec)
return sprintf(buf, "(no parent image)\n");
count = sprintf(bufp, "pool_id %llu\npool_name %s\n",
(unsigned long long) spec->pool_id, spec->pool_name);
if (count < 0)
return count;
bufp += count;
count = sprintf(bufp, "image_id %s\nimage_name %s\n", spec->image_id,
spec->image_name ? spec->image_name : "(unknown)");
if (count < 0)
return count;
bufp += count;
count = sprintf(bufp, "snap_id %llu\nsnap_name %s\n",
(unsigned long long) spec->snap_id, spec->snap_name);
if (count < 0)
return count;
bufp += count;
count = sprintf(bufp, "overlap %llu\n", rbd_dev->parent_overlap);
if (count < 0)
return count;
bufp += count;
return (ssize_t) (bufp - buf);
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
rbd_warn(rbd_dev, ": manual header refresh error (%d)\n", ret);
return ret < 0 ? ret : size;
}
static void rbd_sysfs_dev_release(struct device *dev)
{
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
static struct rbd_device *rbd_dev_create(struct rbd_client *rbdc,
struct rbd_spec *spec)
{
struct rbd_device *rbd_dev;
rbd_dev = kzalloc(sizeof (*rbd_dev), GFP_KERNEL);
if (!rbd_dev)
return NULL;
spin_lock_init(&rbd_dev->lock);
rbd_dev->flags = 0;
atomic_set(&rbd_dev->parent_ref, 0);
INIT_LIST_HEAD(&rbd_dev->node);
init_rwsem(&rbd_dev->header_rwsem);
rbd_dev->spec = spec;
rbd_dev->rbd_client = rbdc;
rbd_dev->layout.fl_stripe_unit = cpu_to_le32(1 << RBD_MAX_OBJ_ORDER);
rbd_dev->layout.fl_stripe_count = cpu_to_le32(1);
rbd_dev->layout.fl_object_size = cpu_to_le32(1 << RBD_MAX_OBJ_ORDER);
rbd_dev->layout.fl_pg_pool = cpu_to_le32((u32) spec->pool_id);
return rbd_dev;
}
static void rbd_dev_destroy(struct rbd_device *rbd_dev)
{
rbd_put_client(rbd_dev->rbd_client);
rbd_spec_put(rbd_dev->spec);
kfree(rbd_dev);
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
ret = rbd_obj_method_sync(rbd_dev, rbd_dev->header_name,
"rbd", "get_size",
&snapid, sizeof (snapid),
&size_buf, sizeof (size_buf));
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
ret = rbd_obj_method_sync(rbd_dev, rbd_dev->header_name,
"rbd", "get_object_prefix", NULL, 0,
reply_buf, RBD_OBJ_PREFIX_LEN_MAX);
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
u64 incompat;
int ret;
ret = rbd_obj_method_sync(rbd_dev, rbd_dev->header_name,
"rbd", "get_features",
&snapid, sizeof (snapid),
&features_buf, sizeof (features_buf));
dout("%s: rbd_obj_method_sync returned %d\n", __func__, ret);
if (ret < 0)
return ret;
if (ret < sizeof (features_buf))
return -ERANGE;
incompat = le64_to_cpu(features_buf.incompat);
if (incompat & ~RBD_FEATURES_SUPPORTED)
return -ENXIO;
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
snapid = cpu_to_le64(CEPH_NOSNAP);
ret = rbd_obj_method_sync(rbd_dev, rbd_dev->header_name,
"rbd", "get_parent",
&snapid, sizeof (snapid),
reply_buf, size);
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
smp_mb();
rbd_dev_parent_put(rbd_dev);
pr_info("%s: clone image has been flattened\n",
rbd_dev->disk->disk_name);
}
goto out;
}
ret = -EIO;
if (pool_id > (u64)U32_MAX) {
rbd_warn(NULL, "parent pool id too large (%llu > %u)\n",
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
}
rbd_dev->parent_overlap = overlap;
smp_mb();
if (!overlap) {
if (parent_spec) {
rbd_dev_parent_put(rbd_dev);
pr_info("%s: clone image now standalone\n",
rbd_dev->disk->disk_name);
} else {
rbd_warn(rbd_dev, "ignoring parent of "
"clone with overlap 0\n");
}
}
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
ret = rbd_obj_method_sync(rbd_dev, rbd_dev->header_name,
"rbd", "get_stripe_unit_count", NULL, 0,
(char *)&striping_info_buf, size);
dout("%s: rbd_obj_method_sync returned %d\n", __func__, ret);
if (ret < 0)
return ret;
if (ret < size)
return -ERANGE;
ret = -EINVAL;
obj_size = (u64)1 << rbd_dev->header.obj_order;
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
static char *rbd_dev_image_name(struct rbd_device *rbd_dev)
{
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
ret = rbd_obj_method_sync(rbd_dev, RBD_DIRECTORY,
"rbd", "dir_get_name",
image_id, image_id_size,
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
static int rbd_dev_spec_update(struct rbd_device *rbd_dev)
{
struct ceph_osd_client *osdc = &rbd_dev->rbd_client->client->osdc;
struct rbd_spec *spec = rbd_dev->spec;
const char *pool_name;
const char *image_name;
const char *snap_name;
int ret;
if (spec->pool_name) {
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
ret = rbd_obj_method_sync(rbd_dev, rbd_dev->header_name,
"rbd", "get_snapcontext", NULL, 0,
reply_buf, size);
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
ret = rbd_obj_method_sync(rbd_dev, rbd_dev->header_name,
"rbd", "get_snapshot_name",
&snapid, sizeof (snapid),
reply_buf, size);
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
if (rbd_dev->header.features & RBD_FEATURE_LAYERING &&
(first_time || rbd_dev->parent_spec)) {
bool warn;
ret = rbd_dev_v2_parent_info(rbd_dev);
if (ret)
return ret;
warn = rbd_dev->parent_spec && rbd_dev->spec->pool_name;
if (first_time && warn)
rbd_warn(rbd_dev, "WARNING: kernel layering "
"is EXPERIMENTAL!");
}
if (rbd_dev->spec->snap_id == CEPH_NOSNAP)
if (rbd_dev->mapping.size != rbd_dev->header.image_size)
rbd_dev->mapping.size = rbd_dev->header.image_size;
ret = rbd_dev_v2_snap_context(rbd_dev);
dout("rbd_dev_v2_snap_context returned %d\n", ret);
return ret;
}
static int rbd_bus_add_dev(struct rbd_device *rbd_dev)
{
struct device *dev;
int ret;
dev = &rbd_dev->dev;
dev->bus = &rbd_bus_type;
dev->type = &rbd_device_type;
dev->parent = &rbd_root_dev;
dev->release = rbd_dev_device_release;
dev_set_name(dev, "%d", rbd_dev->dev_id);
ret = device_register(dev);
return ret;
}
static void rbd_bus_del_dev(struct rbd_device *rbd_dev)
{
device_unregister(&rbd_dev->dev);
}
static int rbd_dev_id_get(struct rbd_device *rbd_dev)
{
int new_dev_id;
new_dev_id = ida_simple_get(&rbd_dev_id_ida,
0, minor_to_rbd_dev_id(1 << MINORBITS),
GFP_KERNEL);
if (new_dev_id < 0)
return new_dev_id;
rbd_dev->dev_id = new_dev_id;
spin_lock(&rbd_dev_list_lock);
list_add_tail(&rbd_dev->node, &rbd_dev_list);
spin_unlock(&rbd_dev_list_lock);
dout("rbd_dev %p given dev id %d\n", rbd_dev, rbd_dev->dev_id);
return 0;
}
static void rbd_dev_id_put(struct rbd_device *rbd_dev)
{
spin_lock(&rbd_dev_list_lock);
list_del_init(&rbd_dev->node);
spin_unlock(&rbd_dev_list_lock);
ida_simple_remove(&rbd_dev_id_ida, rbd_dev->dev_id);
dout("rbd_dev %p released dev id %d\n", rbd_dev, rbd_dev->dev_id);
}
static inline size_t next_token(const char **buf)
{
const char *spaces = " \f\n\r\t\v";
*buf += strspn(*buf, spaces);
return strcspn(*buf, spaces);
}
static inline size_t copy_token(const char **buf,
char *token,
size_t token_size)
{
size_t len;
len = next_token(buf);
if (len < token_size) {
memcpy(token, *buf, len);
*(token + len) = '\0';
}
*buf += len;
return len;
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
u64 newest_epoch;
unsigned long timeout = rbdc->client->options->mount_timeout * HZ;
int tries = 0;
int ret;
again:
ret = ceph_pg_poolid_by_name(rbdc->client->osdc.osdmap, pool_name);
if (ret == -ENOENT && tries++ < 1) {
ret = ceph_monc_do_get_version(&rbdc->client->monc, "osdmap",
&newest_epoch);
if (ret < 0)
return ret;
if (rbdc->client->osdc.osdmap->epoch < newest_epoch) {
ceph_monc_request_next_osdmap(&rbdc->client->monc);
(void) ceph_monc_wait_osdmap(&rbdc->client->monc,
newest_epoch, timeout);
goto again;
} else {
return -ENOENT;
}
}
return ret;
}
static int rbd_dev_image_id(struct rbd_device *rbd_dev)
{
int ret;
size_t size;
char *object_name;
void *response;
char *image_id;
if (rbd_dev->spec->image_id) {
rbd_dev->image_format = *rbd_dev->spec->image_id ? 2 : 1;
return 0;
}
size = sizeof (RBD_ID_PREFIX) + strlen(rbd_dev->spec->image_name);
object_name = kmalloc(size, GFP_NOIO);
if (!object_name)
return -ENOMEM;
sprintf(object_name, "%s%s", RBD_ID_PREFIX, rbd_dev->spec->image_name);
dout("rbd id object name is %s\n", object_name);
size = sizeof (__le32) + RBD_IMAGE_ID_LEN_MAX;
response = kzalloc(size, GFP_NOIO);
if (!response) {
ret = -ENOMEM;
goto out;
}
ret = rbd_obj_method_sync(rbd_dev, object_name,
"rbd", "get_id", NULL, 0,
response, RBD_IMAGE_ID_LEN_MAX);
dout("%s: rbd_obj_method_sync returned %d\n", __func__, ret);
if (ret == -ENOENT) {
image_id = kstrdup("", GFP_KERNEL);
ret = image_id ? 0 : -ENOMEM;
if (!ret)
rbd_dev->image_format = 1;
} else if (ret > sizeof (__le32)) {
void *p = response;
image_id = ceph_extract_encoded_string(&p, p + ret,
NULL, GFP_NOIO);
ret = PTR_ERR_OR_ZERO(image_id);
if (!ret)
rbd_dev->image_format = 2;
} else {
ret = -EINVAL;
}
if (!ret) {
rbd_dev->spec->image_id = image_id;
dout("image_id is %s\n", image_id);
}
out:
kfree(response);
kfree(object_name);
return ret;
}
static void rbd_dev_unprobe(struct rbd_device *rbd_dev)
{
struct rbd_image_header *header;
if (rbd_dev->parent_overlap)
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
return 0;
out_err:
rbd_dev->header.features = 0;
kfree(rbd_dev->header.object_prefix);
rbd_dev->header.object_prefix = NULL;
return ret;
}
static int rbd_dev_probe_parent(struct rbd_device *rbd_dev)
{
struct rbd_device *parent = NULL;
struct rbd_spec *parent_spec;
struct rbd_client *rbdc;
int ret;
if (!rbd_dev->parent_spec)
return 0;
parent_spec = rbd_spec_get(rbd_dev->parent_spec);
rbdc = __rbd_get_client(rbd_dev->rbd_client);
ret = -ENOMEM;
parent = rbd_dev_create(rbdc, parent_spec);
if (!parent)
goto out_err;
ret = rbd_dev_image_probe(parent, false);
if (ret < 0)
goto out_err;
rbd_dev->parent = parent;
atomic_set(&rbd_dev->parent_ref, 1);
return 0;
out_err:
if (parent) {
rbd_dev_unparent(rbd_dev);
kfree(rbd_dev->header_name);
rbd_dev_destroy(parent);
} else {
rbd_put_client(rbdc);
rbd_spec_put(parent_spec);
}
return ret;
}
static int rbd_dev_device_setup(struct rbd_device *rbd_dev)
{
int ret;
ret = rbd_dev_id_get(rbd_dev);
if (ret)
return ret;
BUILD_BUG_ON(DEV_NAME_LEN
< sizeof (RBD_DRV_NAME) + MAX_INT_FORMAT_WIDTH);
sprintf(rbd_dev->name, "%s%d", RBD_DRV_NAME, rbd_dev->dev_id);
if (!single_major) {
ret = register_blkdev(0, rbd_dev->name);
if (ret < 0)
goto err_out_id;
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
ret = rbd_bus_add_dev(rbd_dev);
if (ret)
goto err_out_mapping;
set_bit(RBD_DEV_FLAG_EXISTS, &rbd_dev->flags);
add_disk(rbd_dev->disk);
pr_info("%s: added with size 0x%llx\n", rbd_dev->disk->disk_name,
(unsigned long long) rbd_dev->mapping.size);
return ret;
err_out_mapping:
rbd_dev_mapping_clear(rbd_dev);
err_out_disk:
rbd_free_disk(rbd_dev);
err_out_blkdev:
if (!single_major)
unregister_blkdev(rbd_dev->major, rbd_dev->name);
err_out_id:
rbd_dev_id_put(rbd_dev);
rbd_dev_mapping_clear(rbd_dev);
return ret;
}
static int rbd_dev_header_name(struct rbd_device *rbd_dev)
{
struct rbd_spec *spec = rbd_dev->spec;
size_t size;
rbd_assert(rbd_image_format_valid(rbd_dev->image_format));
if (rbd_dev->image_format == 1)
size = strlen(spec->image_name) + sizeof (RBD_SUFFIX);
else
size = sizeof (RBD_HEADER_PREFIX) + strlen(spec->image_id);
rbd_dev->header_name = kmalloc(size, GFP_KERNEL);
if (!rbd_dev->header_name)
return -ENOMEM;
if (rbd_dev->image_format == 1)
sprintf(rbd_dev->header_name, "%s%s",
spec->image_name, RBD_SUFFIX);
else
sprintf(rbd_dev->header_name, "%s%s",
RBD_HEADER_PREFIX, spec->image_id);
return 0;
}
static void rbd_dev_image_release(struct rbd_device *rbd_dev)
{
rbd_dev_unprobe(rbd_dev);
kfree(rbd_dev->header_name);
rbd_dev->header_name = NULL;
rbd_dev->image_format = 0;
kfree(rbd_dev->spec->image_id);
rbd_dev->spec->image_id = NULL;
rbd_dev_destroy(rbd_dev);
}
static int rbd_dev_image_probe(struct rbd_device *rbd_dev, bool mapping)
{
int ret;
ret = rbd_dev_image_id(rbd_dev);
if (ret)
return ret;
rbd_assert(rbd_dev->spec->image_id);
rbd_assert(rbd_image_format_valid(rbd_dev->image_format));
ret = rbd_dev_header_name(rbd_dev);
if (ret)
goto err_out_format;
if (mapping) {
ret = rbd_dev_header_watch_sync(rbd_dev);
if (ret)
goto out_header_name;
}
if (rbd_dev->image_format == 1)
ret = rbd_dev_v1_header_info(rbd_dev);
else
ret = rbd_dev_v2_header_info(rbd_dev);
if (ret)
goto err_out_watch;
ret = rbd_dev_spec_update(rbd_dev);
if (ret)
goto err_out_probe;
ret = rbd_dev_probe_parent(rbd_dev);
if (ret)
goto err_out_probe;
dout("discovered format %u image, header name is %s\n",
rbd_dev->image_format, rbd_dev->header_name);
return 0;
err_out_probe:
rbd_dev_unprobe(rbd_dev);
err_out_watch:
if (mapping)
rbd_dev_header_unwatch_sync(rbd_dev);
out_header_name:
kfree(rbd_dev->header_name);
rbd_dev->header_name = NULL;
err_out_format:
rbd_dev->image_format = 0;
kfree(rbd_dev->spec->image_id);
rbd_dev->spec->image_id = NULL;
dout("probe failed, returning %d\n", ret);
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
int rc = -ENOMEM;
if (!try_module_get(THIS_MODULE))
return -ENODEV;
rc = rbd_add_parse_args(buf, &ceph_opts, &rbd_opts, &spec);
if (rc < 0)
goto err_out_module;
read_only = rbd_opts->read_only;
kfree(rbd_opts);
rbd_opts = NULL;
rbdc = rbd_get_client(ceph_opts);
if (IS_ERR(rbdc)) {
rc = PTR_ERR(rbdc);
goto err_out_args;
}
rc = rbd_add_get_pool_id(rbdc, spec->pool_name);
if (rc < 0)
goto err_out_client;
spec->pool_id = (u64)rc;
if (spec->pool_id > (u64)U32_MAX) {
rbd_warn(NULL, "pool id too large (%llu > %u)\n",
(unsigned long long)spec->pool_id, U32_MAX);
rc = -EIO;
goto err_out_client;
}
rbd_dev = rbd_dev_create(rbdc, spec);
if (!rbd_dev)
goto err_out_client;
rbdc = NULL;
spec = NULL;
rc = rbd_dev_image_probe(rbd_dev, true);
if (rc < 0)
goto err_out_rbd_dev;
if (rbd_dev->spec->snap_id != CEPH_NOSNAP)
read_only = true;
rbd_dev->mapping.read_only = read_only;
rc = rbd_dev_device_setup(rbd_dev);
if (rc) {
rbd_dev_header_unwatch_sync(rbd_dev);
rbd_dev_image_release(rbd_dev);
goto err_out_module;
}
return count;
err_out_rbd_dev:
rbd_dev_destroy(rbd_dev);
err_out_client:
rbd_put_client(rbdc);
err_out_args:
rbd_spec_put(spec);
err_out_module:
module_put(THIS_MODULE);
dout("Error adding device %s\n", buf);
return (ssize_t)rc;
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
static void rbd_dev_device_release(struct device *dev)
{
struct rbd_device *rbd_dev = dev_to_rbd_dev(dev);
rbd_free_disk(rbd_dev);
clear_bit(RBD_DEV_FLAG_EXISTS, &rbd_dev->flags);
rbd_dev_mapping_clear(rbd_dev);
if (!single_major)
unregister_blkdev(rbd_dev->major, rbd_dev->name);
rbd_dev_id_put(rbd_dev);
rbd_dev_mapping_clear(rbd_dev);
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
unsigned long ul;
bool already = false;
int ret;
ret = kstrtoul(buf, 10, &ul);
if (ret)
return ret;
dev_id = (int)ul;
if (dev_id != ul)
return -EINVAL;
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
if (rbd_dev->open_count)
ret = -EBUSY;
else
already = test_and_set_bit(RBD_DEV_FLAG_REMOVING,
&rbd_dev->flags);
spin_unlock_irq(&rbd_dev->lock);
}
spin_unlock(&rbd_dev_list_lock);
if (ret < 0 || already)
return ret;
rbd_dev_header_unwatch_sync(rbd_dev);
dout("%s: flushing notifies", __func__);
ceph_osdc_flush_notifies(&rbd_dev->rbd_client->client->osdc);
rbd_bus_del_dev(rbd_dev);
rbd_dev_image_release(rbd_dev);
module_put(THIS_MODULE);
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
rbd_img_request_cache = kmem_cache_create("rbd_img_request",
sizeof (struct rbd_img_request),
__alignof__(struct rbd_img_request),
0, NULL);
if (!rbd_img_request_cache)
return -ENOMEM;
rbd_assert(!rbd_obj_request_cache);
rbd_obj_request_cache = kmem_cache_create("rbd_obj_request",
sizeof (struct rbd_obj_request),
__alignof__(struct rbd_obj_request),
0, NULL);
if (!rbd_obj_request_cache)
goto out_err;
rbd_assert(!rbd_segment_name_cache);
rbd_segment_name_cache = kmem_cache_create("rbd_segment_name",
CEPH_MAX_OID_NAME_LEN + 1, 1, 0, NULL);
if (rbd_segment_name_cache)
return 0;
out_err:
if (rbd_obj_request_cache) {
kmem_cache_destroy(rbd_obj_request_cache);
rbd_obj_request_cache = NULL;
}
kmem_cache_destroy(rbd_img_request_cache);
rbd_img_request_cache = NULL;
return -ENOMEM;
}
static void rbd_slab_exit(void)
{
rbd_assert(rbd_segment_name_cache);
kmem_cache_destroy(rbd_segment_name_cache);
rbd_segment_name_cache = NULL;
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
if (single_major) {
rbd_major = register_blkdev(0, RBD_DRV_NAME);
if (rbd_major < 0) {
rc = rbd_major;
goto err_out_slab;
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
rbd_slab_exit();
}
