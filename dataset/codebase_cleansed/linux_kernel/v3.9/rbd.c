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
mutex_lock_nested(&ctl_mutex, SINGLE_DEPTH_NESTING);
(void) get_device(&rbd_dev->dev);
set_device_ro(bdev, rbd_dev->mapping.read_only);
mutex_unlock(&ctl_mutex);
return 0;
}
static int rbd_release(struct gendisk *disk, fmode_t mode)
{
struct rbd_device *rbd_dev = disk->private_data;
unsigned long open_count_before;
spin_lock_irq(&rbd_dev->lock);
open_count_before = rbd_dev->open_count--;
spin_unlock_irq(&rbd_dev->lock);
rbd_assert(open_count_before > 0);
mutex_lock_nested(&ctl_mutex, SINGLE_DEPTH_NESTING);
put_device(&rbd_dev->dev);
mutex_unlock(&ctl_mutex);
return 0;
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
mutex_lock_nested(&ctl_mutex, SINGLE_DEPTH_NESTING);
rbdc->client = ceph_create_client(ceph_opts, rbdc, 0, 0);
if (IS_ERR(rbdc->client))
goto out_mutex;
ceph_opts = NULL;
ret = ceph_open_session(rbdc->client);
if (ret < 0)
goto out_err;
spin_lock(&rbd_client_list_lock);
list_add_tail(&rbdc->node, &rbd_client_list);
spin_unlock(&rbd_client_list_lock);
mutex_unlock(&ctl_mutex);
dout("%s: rbdc %p\n", __func__, rbdc);
return rbdc;
out_err:
ceph_destroy_client(rbdc->client);
out_mutex:
mutex_unlock(&ctl_mutex);
kfree(rbdc);
out_opt:
if (ceph_opts)
ceph_destroy_options(ceph_opts);
dout("%s: error %d\n", __func__, ret);
return ERR_PTR(ret);
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
kref_get(&client_node->kref);
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
rbdc = rbd_client_find(ceph_opts);
if (rbdc)
ceph_destroy_options(ceph_opts);
else
rbdc = rbd_client_create(ceph_opts);
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
static int rbd_header_from_disk(struct rbd_image_header *header,
struct rbd_image_header_ondisk *ondisk)
{
u32 snap_count;
size_t len;
size_t size;
u32 i;
memset(header, 0, sizeof (*header));
snap_count = le32_to_cpu(ondisk->snap_count);
len = strnlen(ondisk->object_prefix, sizeof (ondisk->object_prefix));
header->object_prefix = kmalloc(len + 1, GFP_KERNEL);
if (!header->object_prefix)
return -ENOMEM;
memcpy(header->object_prefix, ondisk->object_prefix, len);
header->object_prefix[len] = '\0';
if (snap_count) {
u64 snap_names_len = le64_to_cpu(ondisk->snap_names_len);
if (snap_names_len > (u64) SIZE_MAX)
return -EIO;
header->snap_names = kmalloc(snap_names_len, GFP_KERNEL);
if (!header->snap_names)
goto out_err;
memcpy(header->snap_names, &ondisk->snaps[snap_count],
snap_names_len);
size = snap_count * sizeof (*header->snap_sizes);
header->snap_sizes = kmalloc(size, GFP_KERNEL);
if (!header->snap_sizes)
goto out_err;
for (i = 0; i < snap_count; i++)
header->snap_sizes[i] =
le64_to_cpu(ondisk->snaps[i].image_size);
} else {
WARN_ON(ondisk->snap_names_len);
header->snap_names = NULL;
header->snap_sizes = NULL;
}
header->features = 0;
header->obj_order = ondisk->options.order;
header->crypt_type = ondisk->options.crypt_type;
header->comp_type = ondisk->options.comp_type;
header->image_size = le64_to_cpu(ondisk->image_size);
size = sizeof (struct ceph_snap_context);
size += snap_count * sizeof (header->snapc->snaps[0]);
header->snapc = kzalloc(size, GFP_KERNEL);
if (!header->snapc)
goto out_err;
atomic_set(&header->snapc->nref, 1);
header->snapc->seq = le64_to_cpu(ondisk->snap_seq);
header->snapc->num_snaps = snap_count;
for (i = 0; i < snap_count; i++)
header->snapc->snaps[i] =
le64_to_cpu(ondisk->snaps[i].id);
return 0;
out_err:
kfree(header->snap_sizes);
header->snap_sizes = NULL;
kfree(header->snap_names);
header->snap_names = NULL;
kfree(header->object_prefix);
header->object_prefix = NULL;
return -ENOMEM;
}
static const char *rbd_snap_name(struct rbd_device *rbd_dev, u64 snap_id)
{
struct rbd_snap *snap;
if (snap_id == CEPH_NOSNAP)
return RBD_SNAP_HEAD_NAME;
list_for_each_entry(snap, &rbd_dev->snaps, node)
if (snap_id == snap->id)
return snap->name;
return NULL;
}
static int snap_by_name(struct rbd_device *rbd_dev, const char *snap_name)
{
struct rbd_snap *snap;
list_for_each_entry(snap, &rbd_dev->snaps, node) {
if (!strcmp(snap_name, snap->name)) {
rbd_dev->spec->snap_id = snap->id;
rbd_dev->mapping.size = snap->size;
rbd_dev->mapping.features = snap->features;
return 0;
}
}
return -ENOENT;
}
static int rbd_dev_set_mapping(struct rbd_device *rbd_dev)
{
int ret;
if (!memcmp(rbd_dev->spec->snap_name, RBD_SNAP_HEAD_NAME,
sizeof (RBD_SNAP_HEAD_NAME))) {
rbd_dev->spec->snap_id = CEPH_NOSNAP;
rbd_dev->mapping.size = rbd_dev->header.image_size;
rbd_dev->mapping.features = rbd_dev->header.features;
ret = 0;
} else {
ret = snap_by_name(rbd_dev, rbd_dev->spec->snap_name);
if (ret < 0)
goto done;
rbd_dev->mapping.read_only = true;
}
set_bit(RBD_DEV_FLAG_EXISTS, &rbd_dev->flags);
done:
return ret;
}
static void rbd_header_free(struct rbd_image_header *header)
{
kfree(header->object_prefix);
header->object_prefix = NULL;
kfree(header->snap_sizes);
header->snap_sizes = NULL;
kfree(header->snap_names);
header->snap_names = NULL;
ceph_put_snap_context(header->snapc);
header->snapc = NULL;
}
static const char *rbd_segment_name(struct rbd_device *rbd_dev, u64 offset)
{
char *name;
u64 segment;
int ret;
name = kmalloc(MAX_OBJ_NAME_SIZE + 1, GFP_NOIO);
if (!name)
return NULL;
segment = offset >> rbd_dev->header.obj_order;
ret = snprintf(name, MAX_OBJ_NAME_SIZE + 1, "%s.%012llx",
rbd_dev->header.object_prefix, segment);
if (ret < 0 || ret > MAX_OBJ_NAME_SIZE) {
pr_err("error formatting segment name for #%llu (%d)\n",
segment, ret);
kfree(name);
name = NULL;
}
return name;
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
struct bio_vec *bv;
unsigned long flags;
void *buf;
int i;
int pos = 0;
while (chain) {
bio_for_each_segment(bv, chain, i) {
if (pos + bv->bv_len > start_ofs) {
int remainder = max(start_ofs - pos, 0);
buf = bvec_kmap_irq(bv, &flags);
memset(buf + remainder, 0,
bv->bv_len - remainder);
bvec_kunmap_irq(buf, &flags);
}
pos += bv->bv_len;
}
chain = chain->bi_next;
}
}
static struct bio *bio_clone_range(struct bio *bio_src,
unsigned int offset,
unsigned int len,
gfp_t gfpmask)
{
struct bio_vec *bv;
unsigned int resid;
unsigned short idx;
unsigned int voff;
unsigned short end_idx;
unsigned short vcnt;
struct bio *bio;
if (!offset && len == bio_src->bi_size)
return bio_clone(bio_src, gfpmask);
if (WARN_ON_ONCE(!len))
return NULL;
if (WARN_ON_ONCE(len > bio_src->bi_size))
return NULL;
if (WARN_ON_ONCE(offset > bio_src->bi_size - len))
return NULL;
resid = offset;
__bio_for_each_segment(bv, bio_src, idx, 0) {
if (resid < bv->bv_len)
break;
resid -= bv->bv_len;
}
voff = resid;
resid += len;
__bio_for_each_segment(bv, bio_src, end_idx, idx) {
if (resid <= bv->bv_len)
break;
resid -= bv->bv_len;
}
vcnt = end_idx - idx + 1;
bio = bio_alloc(gfpmask, (unsigned int) vcnt);
if (!bio)
return NULL;
bio->bi_bdev = bio_src->bi_bdev;
bio->bi_sector = bio_src->bi_sector + (offset >> SECTOR_SHIFT);
bio->bi_rw = bio_src->bi_rw;
bio->bi_flags |= 1 << BIO_CLONED;
memcpy(&bio->bi_io_vec[0], &bio_src->bi_io_vec[idx],
vcnt * sizeof (struct bio_vec));
bio->bi_io_vec[0].bv_offset += voff;
if (vcnt > 1) {
bio->bi_io_vec[0].bv_len -= voff;
bio->bi_io_vec[vcnt - 1].bv_len = resid;
} else {
bio->bi_io_vec[0].bv_len = len;
}
bio->bi_vcnt = vcnt;
bio->bi_size = len;
bio->bi_idx = 0;
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
if (!bi || off >= bi->bi_size || !len)
return NULL;
end = &chain;
while (len) {
unsigned int bi_size;
struct bio *bio;
if (!bi) {
rbd_warn(NULL, "bio_chain exhausted with %u left", len);
goto out_err;
}
bi_size = min_t(unsigned int, bi->bi_size - off, len);
bio = bio_clone_range(bi, off, bi_size, gfpmask);
if (!bio)
goto out_err;
*end = bio;
end = &bio->bi_next;
off += bi_size;
if (off == bi->bi_size) {
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
kref_put(&img_request->kref, rbd_img_request_destroy);
}
static inline void rbd_img_obj_request_add(struct rbd_img_request *img_request,
struct rbd_obj_request *obj_request)
{
rbd_assert(obj_request->img_request == NULL);
rbd_obj_request_get(obj_request);
obj_request->img_request = img_request;
obj_request->which = img_request->obj_request_count;
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
static struct ceph_osd_req_op *rbd_osd_req_op_create(u16 opcode, ...)
{
struct ceph_osd_req_op *op;
va_list args;
size_t size;
op = kzalloc(sizeof (*op), GFP_NOIO);
if (!op)
return NULL;
op->op = opcode;
va_start(args, opcode);
switch (opcode) {
case CEPH_OSD_OP_READ:
case CEPH_OSD_OP_WRITE:
op->extent.offset = va_arg(args, u64);
op->extent.length = va_arg(args, u64);
if (opcode == CEPH_OSD_OP_WRITE)
op->payload_len = op->extent.length;
break;
case CEPH_OSD_OP_STAT:
break;
case CEPH_OSD_OP_CALL:
op->cls.class_name = va_arg(args, char *);
size = strlen(op->cls.class_name);
rbd_assert(size <= (size_t) U8_MAX);
op->cls.class_len = size;
op->payload_len = size;
op->cls.method_name = va_arg(args, char *);
size = strlen(op->cls.method_name);
rbd_assert(size <= (size_t) U8_MAX);
op->cls.method_len = size;
op->payload_len += size;
op->cls.argc = 0;
op->cls.indata = va_arg(args, void *);
size = va_arg(args, size_t);
rbd_assert(size <= (size_t) U32_MAX);
op->cls.indata_len = (u32) size;
op->payload_len += size;
break;
case CEPH_OSD_OP_NOTIFY_ACK:
case CEPH_OSD_OP_WATCH:
op->watch.cookie = va_arg(args, u64);
op->watch.ver = va_arg(args, u64);
op->watch.ver = cpu_to_le64(op->watch.ver);
if (opcode == CEPH_OSD_OP_WATCH && va_arg(args, int))
op->watch.flag = (u8) 1;
break;
default:
rbd_warn(NULL, "unsupported opcode %hu\n", opcode);
kfree(op);
op = NULL;
break;
}
va_end(args);
return op;
}
static void rbd_osd_req_op_destroy(struct ceph_osd_req_op *op)
{
kfree(op);
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
static void obj_request_done_init(struct rbd_obj_request *obj_request)
{
atomic_set(&obj_request->done, 0);
smp_wmb();
}
static void obj_request_done_set(struct rbd_obj_request *obj_request)
{
int done;
done = atomic_inc_return(&obj_request->done);
if (done > 1) {
struct rbd_img_request *img_request = obj_request->img_request;
struct rbd_device *rbd_dev;
rbd_dev = img_request ? img_request->rbd_dev : NULL;
rbd_warn(rbd_dev, "obj_request %p was already done\n",
obj_request);
}
}
static bool obj_request_done_test(struct rbd_obj_request *obj_request)
{
smp_mb();
return atomic_read(&obj_request->done) != 0;
}
static void
rbd_img_obj_request_read_callback(struct rbd_obj_request *obj_request)
{
dout("%s: obj %p img %p result %d %llu/%llu\n", __func__,
obj_request, obj_request->img_request, obj_request->result,
obj_request->xferred, obj_request->length);
BUG_ON(obj_request->type != OBJ_REQUEST_BIO);
if (obj_request->result == -ENOENT) {
zero_bio_chain(obj_request->bio_list, 0);
obj_request->result = 0;
obj_request->xferred = obj_request->length;
} else if (obj_request->xferred < obj_request->length &&
!obj_request->result) {
zero_bio_chain(obj_request->bio_list, obj_request->xferred);
obj_request->xferred = obj_request->length;
}
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
dout("%s: obj %p result %d %llu/%llu\n", __func__, obj_request,
obj_request->result, obj_request->xferred, obj_request->length);
if (obj_request->img_request)
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
rbd_assert(!!obj_request->img_request ^
(obj_request->which == BAD_WHICH));
if (osd_req->r_result < 0)
obj_request->result = osd_req->r_result;
obj_request->version = le64_to_cpu(osd_req->r_reassert_version.version);
WARN_ON(osd_req->r_num_ops != 1);
obj_request->xferred = osd_req->r_reply_op_len[0];
rbd_assert(obj_request->xferred < (u64) UINT_MAX);
opcode = osd_req->r_request_ops[0].op;
switch (opcode) {
case CEPH_OSD_OP_READ:
rbd_osd_read_callback(obj_request);
break;
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
static struct ceph_osd_request *rbd_osd_req_create(
struct rbd_device *rbd_dev,
bool write_request,
struct rbd_obj_request *obj_request,
struct ceph_osd_req_op *op)
{
struct rbd_img_request *img_request = obj_request->img_request;
struct ceph_snap_context *snapc = NULL;
struct ceph_osd_client *osdc;
struct ceph_osd_request *osd_req;
struct timespec now;
struct timespec *mtime;
u64 snap_id = CEPH_NOSNAP;
u64 offset = obj_request->offset;
u64 length = obj_request->length;
if (img_request) {
rbd_assert(img_request->write_request == write_request);
if (img_request->write_request)
snapc = img_request->snapc;
else
snap_id = img_request->snap_id;
}
osdc = &rbd_dev->rbd_client->client->osdc;
osd_req = ceph_osdc_alloc_request(osdc, snapc, 1, false, GFP_ATOMIC);
if (!osd_req)
return NULL;
rbd_assert(obj_request_type_valid(obj_request->type));
switch (obj_request->type) {
case OBJ_REQUEST_NODATA:
break;
case OBJ_REQUEST_BIO:
rbd_assert(obj_request->bio_list != NULL);
osd_req->r_bio = obj_request->bio_list;
break;
case OBJ_REQUEST_PAGES:
osd_req->r_pages = obj_request->pages;
osd_req->r_num_pages = obj_request->page_count;
osd_req->r_page_alignment = offset & ~PAGE_MASK;
break;
}
if (write_request) {
osd_req->r_flags = CEPH_OSD_FLAG_WRITE | CEPH_OSD_FLAG_ONDISK;
now = CURRENT_TIME;
mtime = &now;
} else {
osd_req->r_flags = CEPH_OSD_FLAG_READ;
mtime = NULL;
offset = 0;
length = 0;
}
osd_req->r_callback = rbd_osd_req_callback;
osd_req->r_priv = obj_request;
osd_req->r_oid_len = strlen(obj_request->object_name);
rbd_assert(osd_req->r_oid_len < sizeof (osd_req->r_oid));
memcpy(osd_req->r_oid, obj_request->object_name, osd_req->r_oid_len);
osd_req->r_file_layout = rbd_dev->layout;
ceph_osdc_build_request(osd_req, offset, length, 1, op,
snapc, snap_id, mtime);
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
obj_request = kzalloc(sizeof (*obj_request) + size, GFP_KERNEL);
if (!obj_request)
return NULL;
name = (char *)(obj_request + 1);
obj_request->object_name = memcpy(name, object_name, size);
obj_request->offset = offset;
obj_request->length = length;
obj_request->which = BAD_WHICH;
obj_request->type = type;
INIT_LIST_HEAD(&obj_request->links);
obj_request_done_init(obj_request);
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
kfree(obj_request);
}
static struct rbd_img_request *rbd_img_request_create(
struct rbd_device *rbd_dev,
u64 offset, u64 length,
bool write_request)
{
struct rbd_img_request *img_request;
struct ceph_snap_context *snapc = NULL;
img_request = kmalloc(sizeof (*img_request), GFP_ATOMIC);
if (!img_request)
return NULL;
if (write_request) {
down_read(&rbd_dev->header_rwsem);
snapc = ceph_get_snap_context(rbd_dev->header.snapc);
up_read(&rbd_dev->header_rwsem);
if (WARN_ON(!snapc)) {
kfree(img_request);
return NULL;
}
}
img_request->rq = NULL;
img_request->rbd_dev = rbd_dev;
img_request->offset = offset;
img_request->length = length;
img_request->write_request = write_request;
if (write_request)
img_request->snapc = snapc;
else
img_request->snap_id = rbd_dev->spec->snap_id;
spin_lock_init(&img_request->completion_lock);
img_request->next_completion = 0;
img_request->callback = NULL;
img_request->obj_request_count = 0;
INIT_LIST_HEAD(&img_request->obj_requests);
kref_init(&img_request->kref);
rbd_img_request_get(img_request);
rbd_img_request_put(img_request);
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
if (img_request->write_request)
ceph_put_snap_context(img_request->snapc);
kfree(img_request);
}
static int rbd_img_request_fill_bio(struct rbd_img_request *img_request,
struct bio *bio_list)
{
struct rbd_device *rbd_dev = img_request->rbd_dev;
struct rbd_obj_request *obj_request = NULL;
struct rbd_obj_request *next_obj_request;
unsigned int bio_offset;
u64 image_offset;
u64 resid;
u16 opcode;
dout("%s: img %p bio %p\n", __func__, img_request, bio_list);
opcode = img_request->write_request ? CEPH_OSD_OP_WRITE
: CEPH_OSD_OP_READ;
bio_offset = 0;
image_offset = img_request->offset;
rbd_assert(image_offset == bio_list->bi_sector << SECTOR_SHIFT);
resid = img_request->length;
rbd_assert(resid > 0);
while (resid) {
const char *object_name;
unsigned int clone_size;
struct ceph_osd_req_op *op;
u64 offset;
u64 length;
object_name = rbd_segment_name(rbd_dev, image_offset);
if (!object_name)
goto out_unwind;
offset = rbd_segment_offset(rbd_dev, image_offset);
length = rbd_segment_length(rbd_dev, image_offset, resid);
obj_request = rbd_obj_request_create(object_name,
offset, length,
OBJ_REQUEST_BIO);
kfree(object_name);
if (!obj_request)
goto out_unwind;
rbd_assert(length <= (u64) UINT_MAX);
clone_size = (unsigned int) length;
obj_request->bio_list = bio_chain_clone_range(&bio_list,
&bio_offset, clone_size,
GFP_ATOMIC);
if (!obj_request->bio_list)
goto out_partial;
op = rbd_osd_req_op_create(opcode, offset, length);
if (!op)
goto out_partial;
obj_request->osd_req = rbd_osd_req_create(rbd_dev,
img_request->write_request,
obj_request, op);
rbd_osd_req_op_destroy(op);
if (!obj_request->osd_req)
goto out_partial;
rbd_img_obj_request_add(img_request, obj_request);
image_offset += length;
resid -= length;
}
return 0;
out_partial:
rbd_obj_request_put(obj_request);
out_unwind:
for_each_obj_request_safe(img_request, obj_request, next_obj_request)
rbd_obj_request_put(obj_request);
return -ENOMEM;
}
static void rbd_img_obj_callback(struct rbd_obj_request *obj_request)
{
struct rbd_img_request *img_request;
u32 which = obj_request->which;
bool more = true;
img_request = obj_request->img_request;
dout("%s: img %p obj %p\n", __func__, img_request, obj_request);
rbd_assert(img_request != NULL);
rbd_assert(img_request->rq != NULL);
rbd_assert(img_request->obj_request_count > 0);
rbd_assert(which != BAD_WHICH);
rbd_assert(which < img_request->obj_request_count);
rbd_assert(which >= img_request->next_completion);
spin_lock_irq(&img_request->completion_lock);
if (which != img_request->next_completion)
goto out;
for_each_obj_request_from(img_request, obj_request) {
unsigned int xferred;
int result;
rbd_assert(more);
rbd_assert(which < img_request->obj_request_count);
if (!obj_request_done_test(obj_request))
break;
rbd_assert(obj_request->xferred <= (u64) UINT_MAX);
xferred = (unsigned int) obj_request->xferred;
result = (int) obj_request->result;
if (result)
rbd_warn(NULL, "obj_request %s result %d xferred %u\n",
img_request->write_request ? "write" : "read",
result, xferred);
more = blk_end_request(img_request->rq, result, xferred);
which++;
}
rbd_assert(more ^ (which == img_request->obj_request_count));
img_request->next_completion = which;
out:
spin_unlock_irq(&img_request->completion_lock);
if (!more)
rbd_img_request_complete(img_request);
}
static int rbd_img_request_submit(struct rbd_img_request *img_request)
{
struct rbd_device *rbd_dev = img_request->rbd_dev;
struct ceph_osd_client *osdc = &rbd_dev->rbd_client->client->osdc;
struct rbd_obj_request *obj_request;
struct rbd_obj_request *next_obj_request;
dout("%s: img %p\n", __func__, img_request);
for_each_obj_request_safe(img_request, obj_request, next_obj_request) {
int ret;
obj_request->callback = rbd_img_obj_callback;
ret = rbd_obj_request_submit(osdc, obj_request);
if (ret)
return ret;
rbd_obj_request_put(obj_request);
}
return 0;
}
static int rbd_obj_notify_ack(struct rbd_device *rbd_dev,
u64 ver, u64 notify_id)
{
struct rbd_obj_request *obj_request;
struct ceph_osd_req_op *op;
struct ceph_osd_client *osdc;
int ret;
obj_request = rbd_obj_request_create(rbd_dev->header_name, 0, 0,
OBJ_REQUEST_NODATA);
if (!obj_request)
return -ENOMEM;
ret = -ENOMEM;
op = rbd_osd_req_op_create(CEPH_OSD_OP_NOTIFY_ACK, notify_id, ver);
if (!op)
goto out;
obj_request->osd_req = rbd_osd_req_create(rbd_dev, false,
obj_request, op);
rbd_osd_req_op_destroy(op);
if (!obj_request->osd_req)
goto out;
osdc = &rbd_dev->rbd_client->client->osdc;
obj_request->callback = rbd_obj_request_put;
ret = rbd_obj_request_submit(osdc, obj_request);
out:
if (ret)
rbd_obj_request_put(obj_request);
return ret;
}
static void rbd_watch_cb(u64 ver, u64 notify_id, u8 opcode, void *data)
{
struct rbd_device *rbd_dev = (struct rbd_device *)data;
u64 hver;
int rc;
if (!rbd_dev)
return;
dout("%s: \"%s\" notify_id %llu opcode %u\n", __func__,
rbd_dev->header_name, (unsigned long long) notify_id,
(unsigned int) opcode);
rc = rbd_dev_refresh(rbd_dev, &hver);
if (rc)
rbd_warn(rbd_dev, "got notification but failed to "
" update snaps: %d\n", rc);
rbd_obj_notify_ack(rbd_dev, hver, notify_id);
}
static int rbd_dev_header_watch_sync(struct rbd_device *rbd_dev, int start)
{
struct ceph_osd_client *osdc = &rbd_dev->rbd_client->client->osdc;
struct rbd_obj_request *obj_request;
struct ceph_osd_req_op *op;
int ret;
rbd_assert(start ^ !!rbd_dev->watch_event);
rbd_assert(start ^ !!rbd_dev->watch_request);
if (start) {
ret = ceph_osdc_create_event(osdc, rbd_watch_cb, rbd_dev,
&rbd_dev->watch_event);
if (ret < 0)
return ret;
rbd_assert(rbd_dev->watch_event != NULL);
}
ret = -ENOMEM;
obj_request = rbd_obj_request_create(rbd_dev->header_name, 0, 0,
OBJ_REQUEST_NODATA);
if (!obj_request)
goto out_cancel;
op = rbd_osd_req_op_create(CEPH_OSD_OP_WATCH,
rbd_dev->watch_event->cookie,
rbd_dev->header.obj_version, start);
if (!op)
goto out_cancel;
obj_request->osd_req = rbd_osd_req_create(rbd_dev, true,
obj_request, op);
rbd_osd_req_op_destroy(op);
if (!obj_request->osd_req)
goto out_cancel;
if (start)
ceph_osdc_set_request_linger(osdc, obj_request->osd_req);
else
ceph_osdc_unregister_linger_request(osdc,
rbd_dev->watch_request->osd_req);
ret = rbd_obj_request_submit(osdc, obj_request);
if (ret)
goto out_cancel;
ret = rbd_obj_request_wait(obj_request);
if (ret)
goto out_cancel;
ret = obj_request->result;
if (ret)
goto out_cancel;
if (start) {
rbd_dev->watch_request = obj_request;
return 0;
}
rbd_obj_request_put(rbd_dev->watch_request);
rbd_dev->watch_request = NULL;
out_cancel:
ceph_osdc_cancel_event(rbd_dev->watch_event);
rbd_dev->watch_event = NULL;
if (obj_request)
rbd_obj_request_put(obj_request);
return ret;
}
static int rbd_obj_method_sync(struct rbd_device *rbd_dev,
const char *object_name,
const char *class_name,
const char *method_name,
const char *outbound,
size_t outbound_size,
char *inbound,
size_t inbound_size,
u64 *version)
{
struct rbd_obj_request *obj_request;
struct ceph_osd_client *osdc;
struct ceph_osd_req_op *op;
struct page **pages;
u32 page_count;
int ret;
page_count = (u32) calc_pages_for(0, inbound_size);
pages = ceph_alloc_page_vector(page_count, GFP_KERNEL);
if (IS_ERR(pages))
return PTR_ERR(pages);
ret = -ENOMEM;
obj_request = rbd_obj_request_create(object_name, 0, 0,
OBJ_REQUEST_PAGES);
if (!obj_request)
goto out;
obj_request->pages = pages;
obj_request->page_count = page_count;
op = rbd_osd_req_op_create(CEPH_OSD_OP_CALL, class_name,
method_name, outbound, outbound_size);
if (!op)
goto out;
obj_request->osd_req = rbd_osd_req_create(rbd_dev, false,
obj_request, op);
rbd_osd_req_op_destroy(op);
if (!obj_request->osd_req)
goto out;
osdc = &rbd_dev->rbd_client->client->osdc;
ret = rbd_obj_request_submit(osdc, obj_request);
if (ret)
goto out;
ret = rbd_obj_request_wait(obj_request);
if (ret)
goto out;
ret = obj_request->result;
if (ret < 0)
goto out;
ret = 0;
ceph_copy_from_page_vector(pages, inbound, 0, obj_request->xferred);
if (version)
*version = obj_request->version;
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
bool read_only = rbd_dev->mapping.read_only;
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
if (read_only)
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
if (WARN_ON(offset && length > U64_MAX - offset + 1))
goto end_request;
result = -ENOMEM;
img_request = rbd_img_request_create(rbd_dev, offset, length,
write_request);
if (!img_request)
goto end_request;
img_request->rq = rq;
result = rbd_img_request_fill_bio(img_request, rq->bio);
if (!result)
result = rbd_img_request_submit(img_request);
if (result)
rbd_img_request_put(img_request);
end_request:
spin_lock_irq(q->queue_lock);
if (result < 0) {
rbd_warn(rbd_dev, "obj_request %s result %d\n",
write_request ? "write" : "read", result);
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
if (disk->flags & GENHD_FL_UP)
del_gendisk(disk);
if (disk->queue)
blk_cleanup_queue(disk->queue);
put_disk(disk);
}
static int rbd_obj_read_sync(struct rbd_device *rbd_dev,
const char *object_name,
u64 offset, u64 length,
char *buf, u64 *version)
{
struct ceph_osd_req_op *op;
struct rbd_obj_request *obj_request;
struct ceph_osd_client *osdc;
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
op = rbd_osd_req_op_create(CEPH_OSD_OP_READ, offset, length);
if (!op)
goto out;
obj_request->osd_req = rbd_osd_req_create(rbd_dev, false,
obj_request, op);
rbd_osd_req_op_destroy(op);
if (!obj_request->osd_req)
goto out;
osdc = &rbd_dev->rbd_client->client->osdc;
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
rbd_assert(size <= (size_t) INT_MAX);
ret = (int) size;
if (version)
*version = obj_request->version;
out:
if (obj_request)
rbd_obj_request_put(obj_request);
else
ceph_release_page_vector(pages, page_count);
return ret;
}
static struct rbd_image_header_ondisk *
rbd_dev_v1_header_read(struct rbd_device *rbd_dev, u64 *version)
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
return ERR_PTR(-ENOMEM);
ret = rbd_obj_read_sync(rbd_dev, rbd_dev->header_name,
0, size,
(char *) ondisk, version);
if (ret < 0)
goto out_err;
if (WARN_ON((size_t) ret < size)) {
ret = -ENXIO;
rbd_warn(rbd_dev, "short header read (want %zd got %d)",
size, ret);
goto out_err;
}
if (!rbd_dev_ondisk_valid(ondisk)) {
ret = -ENXIO;
rbd_warn(rbd_dev, "invalid header");
goto out_err;
}
names_size = le64_to_cpu(ondisk->snap_names_len);
want_count = snap_count;
snap_count = le32_to_cpu(ondisk->snap_count);
} while (snap_count != want_count);
return ondisk;
out_err:
kfree(ondisk);
return ERR_PTR(ret);
}
static int rbd_read_header(struct rbd_device *rbd_dev,
struct rbd_image_header *header)
{
struct rbd_image_header_ondisk *ondisk;
u64 ver = 0;
int ret;
ondisk = rbd_dev_v1_header_read(rbd_dev, &ver);
if (IS_ERR(ondisk))
return PTR_ERR(ondisk);
ret = rbd_header_from_disk(header, ondisk);
if (ret >= 0)
header->obj_version = ver;
kfree(ondisk);
return ret;
}
static void rbd_remove_all_snaps(struct rbd_device *rbd_dev)
{
struct rbd_snap *snap;
struct rbd_snap *next;
list_for_each_entry_safe(snap, next, &rbd_dev->snaps, node)
rbd_remove_snap_dev(snap);
}
static void rbd_update_mapping_size(struct rbd_device *rbd_dev)
{
sector_t size;
if (rbd_dev->spec->snap_id != CEPH_NOSNAP)
return;
size = (sector_t) rbd_dev->header.image_size / SECTOR_SIZE;
dout("setting size to %llu sectors", (unsigned long long) size);
rbd_dev->mapping.size = (u64) size;
set_capacity(rbd_dev->disk, size);
}
static int rbd_dev_v1_refresh(struct rbd_device *rbd_dev, u64 *hver)
{
int ret;
struct rbd_image_header h;
ret = rbd_read_header(rbd_dev, &h);
if (ret < 0)
return ret;
down_write(&rbd_dev->header_rwsem);
rbd_dev->header.image_size = h.image_size;
rbd_update_mapping_size(rbd_dev);
kfree(rbd_dev->header.snap_sizes);
kfree(rbd_dev->header.snap_names);
ceph_put_snap_context(rbd_dev->header.snapc);
if (hver)
*hver = h.obj_version;
rbd_dev->header.obj_version = h.obj_version;
rbd_dev->header.image_size = h.image_size;
rbd_dev->header.snapc = h.snapc;
rbd_dev->header.snap_names = h.snap_names;
rbd_dev->header.snap_sizes = h.snap_sizes;
WARN_ON(strcmp(rbd_dev->header.object_prefix, h.object_prefix));
kfree(h.object_prefix);
ret = rbd_dev_snaps_update(rbd_dev);
if (!ret)
ret = rbd_dev_snaps_register(rbd_dev);
up_write(&rbd_dev->header_rwsem);
return ret;
}
static int rbd_dev_refresh(struct rbd_device *rbd_dev, u64 *hver)
{
int ret;
rbd_assert(rbd_image_format_valid(rbd_dev->image_format));
mutex_lock_nested(&ctl_mutex, SINGLE_DEPTH_NESTING);
if (rbd_dev->image_format == 1)
ret = rbd_dev_v1_refresh(rbd_dev, hver);
else
ret = rbd_dev_v2_refresh(rbd_dev, hver);
mutex_unlock(&ctl_mutex);
return ret;
}
static int rbd_init_disk(struct rbd_device *rbd_dev)
{
struct gendisk *disk;
struct request_queue *q;
u64 segment_size;
disk = alloc_disk(RBD_MINORS_PER_MAJOR);
if (!disk)
return -ENOMEM;
snprintf(disk->disk_name, sizeof(disk->disk_name), RBD_DRV_NAME "%d",
rbd_dev->dev_id);
disk->major = rbd_dev->major;
disk->first_minor = 0;
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
set_capacity(rbd_dev->disk, rbd_dev->mapping.size / SECTOR_SIZE);
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
sector_t size;
down_read(&rbd_dev->header_rwsem);
size = get_capacity(rbd_dev->disk);
up_read(&rbd_dev->header_rwsem);
return sprintf(buf, "%llu\n", (unsigned long long) size * SECTOR_SIZE);
}
static ssize_t rbd_features_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct rbd_device *rbd_dev = dev_to_rbd_dev(dev);
return sprintf(buf, "0x%016llx\n",
(unsigned long long) rbd_dev->mapping.features);
}
static ssize_t rbd_major_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct rbd_device *rbd_dev = dev_to_rbd_dev(dev);
return sprintf(buf, "%d\n", rbd_dev->major);
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
ret = rbd_dev_refresh(rbd_dev, NULL);
return ret < 0 ? ret : size;
}
static void rbd_sysfs_dev_release(struct device *dev)
{
}
static ssize_t rbd_snap_size_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct rbd_snap *snap = container_of(dev, struct rbd_snap, dev);
return sprintf(buf, "%llu\n", (unsigned long long)snap->size);
}
static ssize_t rbd_snap_id_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct rbd_snap *snap = container_of(dev, struct rbd_snap, dev);
return sprintf(buf, "%llu\n", (unsigned long long)snap->id);
}
static ssize_t rbd_snap_features_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct rbd_snap *snap = container_of(dev, struct rbd_snap, dev);
return sprintf(buf, "0x%016llx\n",
(unsigned long long) snap->features);
}
static void rbd_snap_dev_release(struct device *dev)
{
struct rbd_snap *snap = container_of(dev, struct rbd_snap, dev);
kfree(snap->name);
kfree(snap);
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
rbd_spec_put(rbd_spec_get(spec));
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
INIT_LIST_HEAD(&rbd_dev->node);
INIT_LIST_HEAD(&rbd_dev->snaps);
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
rbd_spec_put(rbd_dev->parent_spec);
kfree(rbd_dev->header_name);
rbd_put_client(rbd_dev->rbd_client);
rbd_spec_put(rbd_dev->spec);
kfree(rbd_dev);
}
static bool rbd_snap_registered(struct rbd_snap *snap)
{
bool ret = snap->dev.type == &rbd_snap_device_type;
bool reg = device_is_registered(&snap->dev);
rbd_assert(!ret ^ reg);
return ret;
}
static void rbd_remove_snap_dev(struct rbd_snap *snap)
{
list_del(&snap->node);
if (device_is_registered(&snap->dev))
device_unregister(&snap->dev);
}
static int rbd_register_snap_dev(struct rbd_snap *snap,
struct device *parent)
{
struct device *dev = &snap->dev;
int ret;
dev->type = &rbd_snap_device_type;
dev->parent = parent;
dev->release = rbd_snap_dev_release;
dev_set_name(dev, "%s%s", RBD_SNAP_DEV_NAME_PREFIX, snap->name);
dout("%s: registering device for snapshot %s\n", __func__, snap->name);
ret = device_register(dev);
return ret;
}
static struct rbd_snap *__rbd_add_snap_dev(struct rbd_device *rbd_dev,
const char *snap_name,
u64 snap_id, u64 snap_size,
u64 snap_features)
{
struct rbd_snap *snap;
int ret;
snap = kzalloc(sizeof (*snap), GFP_KERNEL);
if (!snap)
return ERR_PTR(-ENOMEM);
ret = -ENOMEM;
snap->name = kstrdup(snap_name, GFP_KERNEL);
if (!snap->name)
goto err;
snap->id = snap_id;
snap->size = snap_size;
snap->features = snap_features;
return snap;
err:
kfree(snap->name);
kfree(snap);
return ERR_PTR(ret);
}
static char *rbd_dev_v1_snap_info(struct rbd_device *rbd_dev, u32 which,
u64 *snap_size, u64 *snap_features)
{
char *snap_name;
rbd_assert(which < rbd_dev->header.snapc->num_snaps);
*snap_size = rbd_dev->header.snap_sizes[which];
*snap_features = 0;
snap_name = rbd_dev->header.snap_names;
while (which--)
snap_name += strlen(snap_name) + 1;
return snap_name;
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
(char *) &snapid, sizeof (snapid),
(char *) &size_buf, sizeof (size_buf), NULL);
dout("%s: rbd_obj_method_sync returned %d\n", __func__, ret);
if (ret < 0)
return ret;
*order = size_buf.order;
*snap_size = le64_to_cpu(size_buf.size);
dout(" snap_id 0x%016llx order = %u, snap_size = %llu\n",
(unsigned long long) snap_id, (unsigned int) *order,
(unsigned long long) *snap_size);
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
"rbd", "get_object_prefix",
NULL, 0,
reply_buf, RBD_OBJ_PREFIX_LEN_MAX, NULL);
dout("%s: rbd_obj_method_sync returned %d\n", __func__, ret);
if (ret < 0)
goto out;
p = reply_buf;
rbd_dev->header.object_prefix = ceph_extract_encoded_string(&p,
p + RBD_OBJ_PREFIX_LEN_MAX,
NULL, GFP_NOIO);
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
} features_buf = { 0 };
u64 incompat;
int ret;
ret = rbd_obj_method_sync(rbd_dev, rbd_dev->header_name,
"rbd", "get_features",
(char *) &snapid, sizeof (snapid),
(char *) &features_buf, sizeof (features_buf),
NULL);
dout("%s: rbd_obj_method_sync returned %d\n", __func__, ret);
if (ret < 0)
return ret;
incompat = le64_to_cpu(features_buf.incompat);
if (incompat & ~RBD_FEATURES_ALL)
return -ENXIO;
*snap_features = le64_to_cpu(features_buf.features);
dout(" snap_id 0x%016llx features = 0x%016llx incompat = 0x%016llx\n",
(unsigned long long) snap_id,
(unsigned long long) *snap_features,
(unsigned long long) le64_to_cpu(features_buf.incompat));
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
char *image_id;
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
(char *) &snapid, sizeof (snapid),
(char *) reply_buf, size, NULL);
dout("%s: rbd_obj_method_sync returned %d\n", __func__, ret);
if (ret < 0)
goto out_err;
ret = -ERANGE;
p = reply_buf;
end = (char *) reply_buf + size;
ceph_decode_64_safe(&p, end, parent_spec->pool_id, out_err);
if (parent_spec->pool_id == CEPH_NOPOOL)
goto out;
ret = -EIO;
if (WARN_ON(parent_spec->pool_id > (u64) U32_MAX))
goto out;
image_id = ceph_extract_encoded_string(&p, end, NULL, GFP_KERNEL);
if (IS_ERR(image_id)) {
ret = PTR_ERR(image_id);
goto out_err;
}
parent_spec->image_id = image_id;
ceph_decode_64_safe(&p, end, parent_spec->snap_id, out_err);
ceph_decode_64_safe(&p, end, overlap, out_err);
rbd_dev->parent_overlap = overlap;
rbd_dev->parent_spec = parent_spec;
parent_spec = NULL;
out:
ret = 0;
out_err:
kfree(reply_buf);
rbd_spec_put(parent_spec);
return ret;
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
end = (char *) image_id + image_id_size;
ceph_encode_string(&p, end, rbd_dev->spec->image_id, (u32) len);
size = sizeof (__le32) + RBD_IMAGE_NAME_LEN_MAX;
reply_buf = kmalloc(size, GFP_KERNEL);
if (!reply_buf)
goto out;
ret = rbd_obj_method_sync(rbd_dev, RBD_DIRECTORY,
"rbd", "dir_get_name",
image_id, image_id_size,
(char *) reply_buf, size, NULL);
if (ret < 0)
goto out;
p = reply_buf;
end = (char *) reply_buf + size;
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
static int rbd_dev_probe_update_spec(struct rbd_device *rbd_dev)
{
struct ceph_osd_client *osdc;
const char *name;
void *reply_buf = NULL;
int ret;
if (rbd_dev->spec->pool_name)
return 0;
osdc = &rbd_dev->rbd_client->client->osdc;
name = ceph_pg_pool_name_by_id(osdc->osdmap, rbd_dev->spec->pool_id);
if (!name) {
rbd_warn(rbd_dev, "there is no pool with id %llu",
rbd_dev->spec->pool_id);
return -EIO;
}
rbd_dev->spec->pool_name = kstrdup(name, GFP_KERNEL);
if (!rbd_dev->spec->pool_name)
return -ENOMEM;
name = rbd_dev_image_name(rbd_dev);
if (name)
rbd_dev->spec->image_name = (char *) name;
else
rbd_warn(rbd_dev, "unable to get image name");
name = rbd_snap_name(rbd_dev, rbd_dev->spec->snap_id);
if (!name) {
rbd_warn(rbd_dev, "no snapshot with id %llu",
rbd_dev->spec->snap_id);
ret = -EIO;
goto out_err;
}
rbd_dev->spec->snap_name = kstrdup(name, GFP_KERNEL);
if(!rbd_dev->spec->snap_name)
goto out_err;
return 0;
out_err:
kfree(reply_buf);
kfree(rbd_dev->spec->pool_name);
rbd_dev->spec->pool_name = NULL;
return ret;
}
static int rbd_dev_v2_snap_context(struct rbd_device *rbd_dev, u64 *ver)
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
"rbd", "get_snapcontext",
NULL, 0,
reply_buf, size, ver);
dout("%s: rbd_obj_method_sync returned %d\n", __func__, ret);
if (ret < 0)
goto out;
ret = -ERANGE;
p = reply_buf;
end = (char *) reply_buf + size;
ceph_decode_64_safe(&p, end, seq, out);
ceph_decode_32_safe(&p, end, snap_count, out);
if (snap_count > (SIZE_MAX - sizeof (struct ceph_snap_context))
/ sizeof (u64)) {
ret = -EINVAL;
goto out;
}
if (!ceph_has_room(&p, end, snap_count * sizeof (__le64)))
goto out;
size = sizeof (struct ceph_snap_context) +
snap_count * sizeof (snapc->snaps[0]);
snapc = kmalloc(size, GFP_KERNEL);
if (!snapc) {
ret = -ENOMEM;
goto out;
}
atomic_set(&snapc->nref, 1);
snapc->seq = seq;
snapc->num_snaps = snap_count;
for (i = 0; i < snap_count; i++)
snapc->snaps[i] = ceph_decode_64(&p);
rbd_dev->header.snapc = snapc;
dout(" snap context seq = %llu, snap_count = %u\n",
(unsigned long long) seq, (unsigned int) snap_count);
out:
kfree(reply_buf);
return 0;
}
static char *rbd_dev_v2_snap_name(struct rbd_device *rbd_dev, u32 which)
{
size_t size;
void *reply_buf;
__le64 snap_id;
int ret;
void *p;
void *end;
char *snap_name;
size = sizeof (__le32) + RBD_MAX_SNAP_NAME_LEN;
reply_buf = kmalloc(size, GFP_KERNEL);
if (!reply_buf)
return ERR_PTR(-ENOMEM);
snap_id = cpu_to_le64(rbd_dev->header.snapc->snaps[which]);
ret = rbd_obj_method_sync(rbd_dev, rbd_dev->header_name,
"rbd", "get_snapshot_name",
(char *) &snap_id, sizeof (snap_id),
reply_buf, size, NULL);
dout("%s: rbd_obj_method_sync returned %d\n", __func__, ret);
if (ret < 0)
goto out;
p = reply_buf;
end = (char *) reply_buf + size;
snap_name = ceph_extract_encoded_string(&p, end, NULL, GFP_KERNEL);
if (IS_ERR(snap_name)) {
ret = PTR_ERR(snap_name);
goto out;
} else {
dout(" snap_id 0x%016llx snap_name = %s\n",
(unsigned long long) le64_to_cpu(snap_id), snap_name);
}
kfree(reply_buf);
return snap_name;
out:
kfree(reply_buf);
return ERR_PTR(ret);
}
static char *rbd_dev_v2_snap_info(struct rbd_device *rbd_dev, u32 which,
u64 *snap_size, u64 *snap_features)
{
u64 snap_id;
u8 order;
int ret;
snap_id = rbd_dev->header.snapc->snaps[which];
ret = _rbd_dev_v2_snap_size(rbd_dev, snap_id, &order, snap_size);
if (ret)
return ERR_PTR(ret);
ret = _rbd_dev_v2_snap_features(rbd_dev, snap_id, snap_features);
if (ret)
return ERR_PTR(ret);
return rbd_dev_v2_snap_name(rbd_dev, which);
}
static char *rbd_dev_snap_info(struct rbd_device *rbd_dev, u32 which,
u64 *snap_size, u64 *snap_features)
{
if (rbd_dev->image_format == 1)
return rbd_dev_v1_snap_info(rbd_dev, which,
snap_size, snap_features);
if (rbd_dev->image_format == 2)
return rbd_dev_v2_snap_info(rbd_dev, which,
snap_size, snap_features);
return ERR_PTR(-EINVAL);
}
static int rbd_dev_v2_refresh(struct rbd_device *rbd_dev, u64 *hver)
{
int ret;
__u8 obj_order;
down_write(&rbd_dev->header_rwsem);
obj_order = rbd_dev->header.obj_order,
ret = rbd_dev_v2_image_size(rbd_dev);
if (ret)
goto out;
if (rbd_dev->header.obj_order != obj_order) {
ret = -EIO;
goto out;
}
rbd_update_mapping_size(rbd_dev);
ret = rbd_dev_v2_snap_context(rbd_dev, hver);
dout("rbd_dev_v2_snap_context returned %d\n", ret);
if (ret)
goto out;
ret = rbd_dev_snaps_update(rbd_dev);
dout("rbd_dev_snaps_update returned %d\n", ret);
if (ret)
goto out;
ret = rbd_dev_snaps_register(rbd_dev);
dout("rbd_dev_snaps_register returned %d\n", ret);
out:
up_write(&rbd_dev->header_rwsem);
return ret;
}
static int rbd_dev_snaps_update(struct rbd_device *rbd_dev)
{
struct ceph_snap_context *snapc = rbd_dev->header.snapc;
const u32 snap_count = snapc->num_snaps;
struct list_head *head = &rbd_dev->snaps;
struct list_head *links = head->next;
u32 index = 0;
dout("%s: snap count is %u\n", __func__, (unsigned int) snap_count);
while (index < snap_count || links != head) {
u64 snap_id;
struct rbd_snap *snap;
char *snap_name;
u64 snap_size = 0;
u64 snap_features = 0;
snap_id = index < snap_count ? snapc->snaps[index]
: CEPH_NOSNAP;
snap = links != head ? list_entry(links, struct rbd_snap, node)
: NULL;
rbd_assert(!snap || snap->id != CEPH_NOSNAP);
if (snap_id == CEPH_NOSNAP || (snap && snap->id > snap_id)) {
struct list_head *next = links->next;
if (rbd_dev->spec->snap_id == snap->id)
clear_bit(RBD_DEV_FLAG_EXISTS, &rbd_dev->flags);
rbd_remove_snap_dev(snap);
dout("%ssnap id %llu has been removed\n",
rbd_dev->spec->snap_id == snap->id ?
"mapped " : "",
(unsigned long long) snap->id);
links = next;
continue;
}
snap_name = rbd_dev_snap_info(rbd_dev, index,
&snap_size, &snap_features);
if (IS_ERR(snap_name))
return PTR_ERR(snap_name);
dout("entry %u: snap_id = %llu\n", (unsigned int) snap_count,
(unsigned long long) snap_id);
if (!snap || (snap_id != CEPH_NOSNAP && snap->id < snap_id)) {
struct rbd_snap *new_snap;
new_snap = __rbd_add_snap_dev(rbd_dev, snap_name,
snap_id, snap_size, snap_features);
if (IS_ERR(new_snap)) {
int err = PTR_ERR(new_snap);
dout(" failed to add dev, error %d\n", err);
return err;
}
dout(" added dev%s\n", snap ? "" : " at end\n");
if (snap)
list_add_tail(&new_snap->node, &snap->node);
else
list_add_tail(&new_snap->node, head);
} else {
dout(" already present\n");
rbd_assert(snap->size == snap_size);
rbd_assert(!strcmp(snap->name, snap_name));
rbd_assert(snap->features == snap_features);
links = links->next;
}
index++;
}
dout("%s: done\n", __func__);
return 0;
}
static int rbd_dev_snaps_register(struct rbd_device *rbd_dev)
{
struct rbd_snap *snap;
int ret = 0;
dout("%s:\n", __func__);
if (WARN_ON(!device_is_registered(&rbd_dev->dev)))
return -EIO;
list_for_each_entry(snap, &rbd_dev->snaps, node) {
if (!rbd_snap_registered(snap)) {
ret = rbd_register_snap_dev(snap, &rbd_dev->dev);
if (ret < 0)
break;
}
}
dout("%s: returning %d\n", __func__, ret);
return ret;
}
static int rbd_bus_add_dev(struct rbd_device *rbd_dev)
{
struct device *dev;
int ret;
mutex_lock_nested(&ctl_mutex, SINGLE_DEPTH_NESTING);
dev = &rbd_dev->dev;
dev->bus = &rbd_bus_type;
dev->type = &rbd_device_type;
dev->parent = &rbd_root_dev;
dev->release = rbd_dev_release;
dev_set_name(dev, "%d", rbd_dev->dev_id);
ret = device_register(dev);
mutex_unlock(&ctl_mutex);
return ret;
}
static void rbd_bus_del_dev(struct rbd_device *rbd_dev)
{
device_unregister(&rbd_dev->dev);
}
static void rbd_dev_id_get(struct rbd_device *rbd_dev)
{
rbd_dev->dev_id = atomic64_inc_return(&rbd_dev_id_max);
spin_lock(&rbd_dev_list_lock);
list_add_tail(&rbd_dev->node, &rbd_dev_list);
spin_unlock(&rbd_dev_list_lock);
dout("rbd_dev %p given dev id %llu\n", rbd_dev,
(unsigned long long) rbd_dev->dev_id);
}
static void rbd_dev_id_put(struct rbd_device *rbd_dev)
{
struct list_head *tmp;
int rbd_id = rbd_dev->dev_id;
int max_id;
rbd_assert(rbd_id > 0);
dout("rbd_dev %p released dev id %llu\n", rbd_dev,
(unsigned long long) rbd_dev->dev_id);
spin_lock(&rbd_dev_list_lock);
list_del_init(&rbd_dev->node);
if (rbd_id != atomic64_read(&rbd_dev_id_max)) {
spin_unlock(&rbd_dev_list_lock);
return;
}
max_id = 0;
list_for_each_prev(tmp, &rbd_dev_list) {
struct rbd_device *rbd_dev;
rbd_dev = list_entry(tmp, struct rbd_device, node);
if (rbd_dev->dev_id > max_id)
max_id = rbd_dev->dev_id;
}
spin_unlock(&rbd_dev_list_lock);
atomic64_cmpxchg(&rbd_dev_id_max, rbd_id, max_id);
dout(" max dev id has been reset\n");
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
spec->snap_name = kmemdup(buf, len + 1, GFP_KERNEL);
if (!spec->snap_name)
goto out_mem;
*(spec->snap_name + len) = '\0';
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
static int rbd_dev_image_id(struct rbd_device *rbd_dev)
{
int ret;
size_t size;
char *object_name;
void *response;
void *p;
if (rbd_dev->spec->image_id)
return 0;
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
"rbd", "get_id",
NULL, 0,
response, RBD_IMAGE_ID_LEN_MAX, NULL);
dout("%s: rbd_obj_method_sync returned %d\n", __func__, ret);
if (ret < 0)
goto out;
p = response;
rbd_dev->spec->image_id = ceph_extract_encoded_string(&p,
p + RBD_IMAGE_ID_LEN_MAX,
NULL, GFP_NOIO);
if (IS_ERR(rbd_dev->spec->image_id)) {
ret = PTR_ERR(rbd_dev->spec->image_id);
rbd_dev->spec->image_id = NULL;
} else {
dout("image_id is %s\n", rbd_dev->spec->image_id);
}
out:
kfree(response);
kfree(object_name);
return ret;
}
static int rbd_dev_v1_probe(struct rbd_device *rbd_dev)
{
int ret;
size_t size;
rbd_dev->spec->image_id = kstrdup("", GFP_KERNEL);
if (!rbd_dev->spec->image_id)
return -ENOMEM;
size = strlen(rbd_dev->spec->image_name) + sizeof (RBD_SUFFIX);
rbd_dev->header_name = kmalloc(size, GFP_KERNEL);
if (!rbd_dev->header_name) {
ret = -ENOMEM;
goto out_err;
}
sprintf(rbd_dev->header_name, "%s%s",
rbd_dev->spec->image_name, RBD_SUFFIX);
ret = rbd_read_header(rbd_dev, &rbd_dev->header);
if (ret < 0)
goto out_err;
rbd_dev->parent_spec = NULL;
rbd_dev->parent_overlap = 0;
rbd_dev->image_format = 1;
dout("discovered version 1 image, header name is %s\n",
rbd_dev->header_name);
return 0;
out_err:
kfree(rbd_dev->header_name);
rbd_dev->header_name = NULL;
kfree(rbd_dev->spec->image_id);
rbd_dev->spec->image_id = NULL;
return ret;
}
static int rbd_dev_v2_probe(struct rbd_device *rbd_dev)
{
size_t size;
int ret;
u64 ver = 0;
size = sizeof (RBD_HEADER_PREFIX) + strlen(rbd_dev->spec->image_id);
rbd_dev->header_name = kmalloc(size, GFP_KERNEL);
if (!rbd_dev->header_name)
return -ENOMEM;
sprintf(rbd_dev->header_name, "%s%s",
RBD_HEADER_PREFIX, rbd_dev->spec->image_id);
ret = rbd_dev_v2_image_size(rbd_dev);
if (ret < 0)
goto out_err;
ret = rbd_dev_v2_object_prefix(rbd_dev);
if (ret < 0)
goto out_err;
ret = rbd_dev_v2_features(rbd_dev);
if (ret < 0)
goto out_err;
if (rbd_dev->header.features & RBD_FEATURE_LAYERING) {
ret = rbd_dev_v2_parent_info(rbd_dev);
if (ret < 0)
goto out_err;
}
rbd_dev->header.crypt_type = 0;
rbd_dev->header.comp_type = 0;
ret = rbd_dev_v2_snap_context(rbd_dev, &ver);
if (ret)
goto out_err;
rbd_dev->header.obj_version = ver;
rbd_dev->image_format = 2;
dout("discovered version 2 image, header name is %s\n",
rbd_dev->header_name);
return 0;
out_err:
rbd_dev->parent_overlap = 0;
rbd_spec_put(rbd_dev->parent_spec);
rbd_dev->parent_spec = NULL;
kfree(rbd_dev->header_name);
rbd_dev->header_name = NULL;
kfree(rbd_dev->header.object_prefix);
rbd_dev->header.object_prefix = NULL;
return ret;
}
static int rbd_dev_probe_finish(struct rbd_device *rbd_dev)
{
int ret;
ret = rbd_dev_snaps_update(rbd_dev);
if (ret)
return ret;
ret = rbd_dev_probe_update_spec(rbd_dev);
if (ret)
goto err_out_snaps;
ret = rbd_dev_set_mapping(rbd_dev);
if (ret)
goto err_out_snaps;
rbd_dev_id_get(rbd_dev);
BUILD_BUG_ON(DEV_NAME_LEN
< sizeof (RBD_DRV_NAME) + MAX_INT_FORMAT_WIDTH);
sprintf(rbd_dev->name, "%s%d", RBD_DRV_NAME, rbd_dev->dev_id);
ret = register_blkdev(0, rbd_dev->name);
if (ret < 0)
goto err_out_id;
rbd_dev->major = ret;
ret = rbd_init_disk(rbd_dev);
if (ret)
goto err_out_blkdev;
ret = rbd_bus_add_dev(rbd_dev);
if (ret)
goto err_out_disk;
down_write(&rbd_dev->header_rwsem);
ret = rbd_dev_snaps_register(rbd_dev);
up_write(&rbd_dev->header_rwsem);
if (ret)
goto err_out_bus;
ret = rbd_dev_header_watch_sync(rbd_dev, 1);
if (ret)
goto err_out_bus;
add_disk(rbd_dev->disk);
pr_info("%s: added with size 0x%llx\n", rbd_dev->disk->disk_name,
(unsigned long long) rbd_dev->mapping.size);
return ret;
err_out_bus:
rbd_bus_del_dev(rbd_dev);
return ret;
err_out_disk:
rbd_free_disk(rbd_dev);
err_out_blkdev:
unregister_blkdev(rbd_dev->major, rbd_dev->name);
err_out_id:
rbd_dev_id_put(rbd_dev);
err_out_snaps:
rbd_remove_all_snaps(rbd_dev);
return ret;
}
static int rbd_dev_probe(struct rbd_device *rbd_dev)
{
int ret;
ret = rbd_dev_image_id(rbd_dev);
if (ret)
ret = rbd_dev_v1_probe(rbd_dev);
else
ret = rbd_dev_v2_probe(rbd_dev);
if (ret) {
dout("probe failed, returning %d\n", ret);
return ret;
}
ret = rbd_dev_probe_finish(rbd_dev);
if (ret)
rbd_header_free(&rbd_dev->header);
return ret;
}
static ssize_t rbd_add(struct bus_type *bus,
const char *buf,
size_t count)
{
struct rbd_device *rbd_dev = NULL;
struct ceph_options *ceph_opts = NULL;
struct rbd_options *rbd_opts = NULL;
struct rbd_spec *spec = NULL;
struct rbd_client *rbdc;
struct ceph_osd_client *osdc;
int rc = -ENOMEM;
if (!try_module_get(THIS_MODULE))
return -ENODEV;
rc = rbd_add_parse_args(buf, &ceph_opts, &rbd_opts, &spec);
if (rc < 0)
goto err_out_module;
rbdc = rbd_get_client(ceph_opts);
if (IS_ERR(rbdc)) {
rc = PTR_ERR(rbdc);
goto err_out_args;
}
ceph_opts = NULL;
osdc = &rbdc->client->osdc;
rc = ceph_pg_poolid_by_name(osdc->osdmap, spec->pool_name);
if (rc < 0)
goto err_out_client;
spec->pool_id = (u64) rc;
if (WARN_ON(spec->pool_id > (u64) U32_MAX)) {
rc = -EIO;
goto err_out_client;
}
rbd_dev = rbd_dev_create(rbdc, spec);
if (!rbd_dev)
goto err_out_client;
rbdc = NULL;
spec = NULL;
rbd_dev->mapping.read_only = rbd_opts->read_only;
kfree(rbd_opts);
rbd_opts = NULL;
rc = rbd_dev_probe(rbd_dev);
if (rc < 0)
goto err_out_rbd_dev;
return count;
err_out_rbd_dev:
rbd_dev_destroy(rbd_dev);
err_out_client:
rbd_put_client(rbdc);
err_out_args:
if (ceph_opts)
ceph_destroy_options(ceph_opts);
kfree(rbd_opts);
rbd_spec_put(spec);
err_out_module:
module_put(THIS_MODULE);
dout("Error adding device %s\n", buf);
return (ssize_t) rc;
}
static struct rbd_device *__rbd_get_dev(unsigned long dev_id)
{
struct list_head *tmp;
struct rbd_device *rbd_dev;
spin_lock(&rbd_dev_list_lock);
list_for_each(tmp, &rbd_dev_list) {
rbd_dev = list_entry(tmp, struct rbd_device, node);
if (rbd_dev->dev_id == dev_id) {
spin_unlock(&rbd_dev_list_lock);
return rbd_dev;
}
}
spin_unlock(&rbd_dev_list_lock);
return NULL;
}
static void rbd_dev_release(struct device *dev)
{
struct rbd_device *rbd_dev = dev_to_rbd_dev(dev);
if (rbd_dev->watch_event)
rbd_dev_header_watch_sync(rbd_dev, 0);
rbd_free_disk(rbd_dev);
unregister_blkdev(rbd_dev->major, rbd_dev->name);
rbd_header_free(&rbd_dev->header);
rbd_dev_id_put(rbd_dev);
rbd_assert(rbd_dev->rbd_client != NULL);
rbd_dev_destroy(rbd_dev);
module_put(THIS_MODULE);
}
static ssize_t rbd_remove(struct bus_type *bus,
const char *buf,
size_t count)
{
struct rbd_device *rbd_dev = NULL;
int target_id, rc;
unsigned long ul;
int ret = count;
rc = strict_strtoul(buf, 10, &ul);
if (rc)
return rc;
target_id = (int) ul;
if (target_id != ul)
return -EINVAL;
mutex_lock_nested(&ctl_mutex, SINGLE_DEPTH_NESTING);
rbd_dev = __rbd_get_dev(target_id);
if (!rbd_dev) {
ret = -ENOENT;
goto done;
}
spin_lock_irq(&rbd_dev->lock);
if (rbd_dev->open_count)
ret = -EBUSY;
else
set_bit(RBD_DEV_FLAG_REMOVING, &rbd_dev->flags);
spin_unlock_irq(&rbd_dev->lock);
if (ret < 0)
goto done;
rbd_remove_all_snaps(rbd_dev);
rbd_bus_del_dev(rbd_dev);
done:
mutex_unlock(&ctl_mutex);
return ret;
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
static int __init rbd_init(void)
{
int rc;
if (!libceph_compatible(NULL)) {
rbd_warn(NULL, "libceph incompatibility (quitting)");
return -EINVAL;
}
rc = rbd_sysfs_init();
if (rc)
return rc;
pr_info("loaded " RBD_DRV_NAME_LONG "\n");
return 0;
}
static void __exit rbd_exit(void)
{
rbd_sysfs_cleanup();
}
