static void rbd_root_dev_release(struct device *dev)
{
}
static struct device *rbd_get_dev(struct rbd_device *rbd_dev)
{
return get_device(&rbd_dev->dev);
}
static void rbd_put_dev(struct rbd_device *rbd_dev)
{
put_device(&rbd_dev->dev);
}
static int rbd_open(struct block_device *bdev, fmode_t mode)
{
struct rbd_device *rbd_dev = bdev->bd_disk->private_data;
if ((mode & FMODE_WRITE) && rbd_dev->mapping.read_only)
return -EROFS;
rbd_get_dev(rbd_dev);
set_device_ro(bdev, rbd_dev->mapping.read_only);
return 0;
}
static int rbd_release(struct gendisk *disk, fmode_t mode)
{
struct rbd_device *rbd_dev = disk->private_data;
rbd_put_dev(rbd_dev);
return 0;
}
static struct rbd_client *rbd_client_create(struct ceph_options *ceph_opts)
{
struct rbd_client *rbdc;
int ret = -ENOMEM;
dout("rbd_client_create\n");
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
dout("rbd_client_create created %p\n", rbdc);
return rbdc;
out_err:
ceph_destroy_client(rbdc->client);
out_mutex:
mutex_unlock(&ctl_mutex);
kfree(rbdc);
out_opt:
if (ceph_opts)
ceph_destroy_options(ceph_opts);
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
static int rbd_get_client(struct rbd_device *rbd_dev, const char *mon_addr,
size_t mon_addr_len, char *options)
{
struct rbd_options *rbd_opts = &rbd_dev->rbd_opts;
struct ceph_options *ceph_opts;
struct rbd_client *rbdc;
rbd_opts->read_only = RBD_READ_ONLY_DEFAULT;
ceph_opts = ceph_parse_options(options, mon_addr,
mon_addr + mon_addr_len,
parse_rbd_opts_token, rbd_opts);
if (IS_ERR(ceph_opts))
return PTR_ERR(ceph_opts);
rbdc = rbd_client_find(ceph_opts);
if (rbdc) {
ceph_destroy_options(ceph_opts);
} else {
rbdc = rbd_client_create(ceph_opts);
if (IS_ERR(rbdc))
return PTR_ERR(rbdc);
}
rbd_dev->rbd_client = rbdc;
return 0;
}
static void rbd_client_release(struct kref *kref)
{
struct rbd_client *rbdc = container_of(kref, struct rbd_client, kref);
dout("rbd_release_client %p\n", rbdc);
spin_lock(&rbd_client_list_lock);
list_del(&rbdc->node);
spin_unlock(&rbd_client_list_lock);
ceph_destroy_client(rbdc->client);
kfree(rbdc);
}
static void rbd_put_client(struct rbd_device *rbd_dev)
{
kref_put(&rbd_dev->rbd_client->kref, rbd_client_release);
rbd_dev->rbd_client = NULL;
}
static void rbd_coll_release(struct kref *kref)
{
struct rbd_req_coll *coll =
container_of(kref, struct rbd_req_coll, kref);
dout("rbd_coll_release %p\n", coll);
kfree(coll);
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
static int snap_by_name(struct rbd_device *rbd_dev, const char *snap_name)
{
struct rbd_snap *snap;
list_for_each_entry(snap, &rbd_dev->snaps, node) {
if (!strcmp(snap_name, snap->name)) {
rbd_dev->mapping.snap_id = snap->id;
rbd_dev->mapping.size = snap->size;
rbd_dev->mapping.features = snap->features;
return 0;
}
}
return -ENOENT;
}
static int rbd_dev_set_mapping(struct rbd_device *rbd_dev, char *snap_name)
{
int ret;
if (!memcmp(snap_name, RBD_SNAP_HEAD_NAME,
sizeof (RBD_SNAP_HEAD_NAME))) {
rbd_dev->mapping.snap_id = CEPH_NOSNAP;
rbd_dev->mapping.size = rbd_dev->header.image_size;
rbd_dev->mapping.features = rbd_dev->header.features;
rbd_dev->mapping.snap_exists = false;
rbd_dev->mapping.read_only = rbd_dev->rbd_opts.read_only;
ret = 0;
} else {
ret = snap_by_name(rbd_dev, snap_name);
if (ret < 0)
goto done;
rbd_dev->mapping.snap_exists = true;
rbd_dev->mapping.read_only = true;
}
rbd_dev->mapping.snap_name = snap_name;
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
static char *rbd_segment_name(struct rbd_device *rbd_dev, u64 offset)
{
char *name;
u64 segment;
int ret;
name = kmalloc(RBD_MAX_SEG_NAME_LEN + 1, GFP_NOIO);
if (!name)
return NULL;
segment = offset >> rbd_dev->header.obj_order;
ret = snprintf(name, RBD_MAX_SEG_NAME_LEN, "%s.%012llx",
rbd_dev->header.object_prefix, segment);
if (ret < 0 || ret >= RBD_MAX_SEG_NAME_LEN) {
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
static int rbd_get_num_segments(struct rbd_image_header *header,
u64 ofs, u64 len)
{
u64 start_seg;
u64 end_seg;
if (!len)
return 0;
if (len - 1 > U64_MAX - ofs)
return -ERANGE;
start_seg = ofs >> header->obj_order;
end_seg = (ofs + len - 1) >> header->obj_order;
return end_seg - start_seg + 1;
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
static struct bio *bio_chain_clone(struct bio **old, struct bio **next,
struct bio_pair **bp,
int len, gfp_t gfpmask)
{
struct bio *old_chain = *old;
struct bio *new_chain = NULL;
struct bio *tail;
int total = 0;
if (*bp) {
bio_pair_release(*bp);
*bp = NULL;
}
while (old_chain && (total < len)) {
struct bio *tmp;
tmp = bio_kmalloc(gfpmask, old_chain->bi_max_vecs);
if (!tmp)
goto err_out;
gfpmask &= ~__GFP_WAIT;
if (total + old_chain->bi_size > len) {
struct bio_pair *bp;
dout("bio_chain_clone split! total=%d remaining=%d"
"bi_size=%u\n",
total, len - total, old_chain->bi_size);
bp = bio_split(old_chain, (len - total) / SECTOR_SIZE);
if (!bp)
goto err_out;
__bio_clone(tmp, &bp->bio1);
*next = &bp->bio2;
} else {
__bio_clone(tmp, old_chain);
*next = old_chain->bi_next;
}
tmp->bi_bdev = NULL;
tmp->bi_next = NULL;
if (new_chain)
tail->bi_next = tmp;
else
new_chain = tmp;
tail = tmp;
old_chain = old_chain->bi_next;
total += tmp->bi_size;
}
rbd_assert(total == len);
*old = old_chain;
return new_chain;
err_out:
dout("bio_chain_clone with err\n");
bio_chain_put(new_chain);
return NULL;
}
static struct ceph_osd_req_op *rbd_create_rw_ops(int num_ops,
int opcode, u32 payload_len)
{
struct ceph_osd_req_op *ops;
ops = kzalloc(sizeof (*ops) * (num_ops + 1), GFP_NOIO);
if (!ops)
return NULL;
ops[0].op = opcode;
ops[0].payload_len = payload_len;
return ops;
}
static void rbd_destroy_ops(struct ceph_osd_req_op *ops)
{
kfree(ops);
}
static void rbd_coll_end_req_index(struct request *rq,
struct rbd_req_coll *coll,
int index,
int ret, u64 len)
{
struct request_queue *q;
int min, max, i;
dout("rbd_coll_end_req_index %p index %d ret %d len %llu\n",
coll, index, ret, (unsigned long long) len);
if (!rq)
return;
if (!coll) {
blk_end_request(rq, ret, len);
return;
}
q = rq->q;
spin_lock_irq(q->queue_lock);
coll->status[index].done = 1;
coll->status[index].rc = ret;
coll->status[index].bytes = len;
max = min = coll->num_done;
while (max < coll->total && coll->status[max].done)
max++;
for (i = min; i<max; i++) {
__blk_end_request(rq, coll->status[i].rc,
coll->status[i].bytes);
coll->num_done++;
kref_put(&coll->kref, rbd_coll_release);
}
spin_unlock_irq(q->queue_lock);
}
static void rbd_coll_end_req(struct rbd_request *req,
int ret, u64 len)
{
rbd_coll_end_req_index(req->rq, req->coll, req->coll_index, ret, len);
}
static int rbd_do_request(struct request *rq,
struct rbd_device *rbd_dev,
struct ceph_snap_context *snapc,
u64 snapid,
const char *object_name, u64 ofs, u64 len,
struct bio *bio,
struct page **pages,
int num_pages,
int flags,
struct ceph_osd_req_op *ops,
struct rbd_req_coll *coll,
int coll_index,
void (*rbd_cb)(struct ceph_osd_request *req,
struct ceph_msg *msg),
struct ceph_osd_request **linger_req,
u64 *ver)
{
struct ceph_osd_request *req;
struct ceph_file_layout *layout;
int ret;
u64 bno;
struct timespec mtime = CURRENT_TIME;
struct rbd_request *req_data;
struct ceph_osd_request_head *reqhead;
struct ceph_osd_client *osdc;
req_data = kzalloc(sizeof(*req_data), GFP_NOIO);
if (!req_data) {
if (coll)
rbd_coll_end_req_index(rq, coll, coll_index,
-ENOMEM, len);
return -ENOMEM;
}
if (coll) {
req_data->coll = coll;
req_data->coll_index = coll_index;
}
dout("rbd_do_request object_name=%s ofs=%llu len=%llu\n", object_name,
(unsigned long long) ofs, (unsigned long long) len);
osdc = &rbd_dev->rbd_client->client->osdc;
req = ceph_osdc_alloc_request(osdc, flags, snapc, ops,
false, GFP_NOIO, pages, bio);
if (!req) {
ret = -ENOMEM;
goto done_pages;
}
req->r_callback = rbd_cb;
req_data->rq = rq;
req_data->bio = bio;
req_data->pages = pages;
req_data->len = len;
req->r_priv = req_data;
reqhead = req->r_request->front.iov_base;
reqhead->snapid = cpu_to_le64(CEPH_NOSNAP);
strncpy(req->r_oid, object_name, sizeof(req->r_oid));
req->r_oid_len = strlen(req->r_oid);
layout = &req->r_file_layout;
memset(layout, 0, sizeof(*layout));
layout->fl_stripe_unit = cpu_to_le32(1 << RBD_MAX_OBJ_ORDER);
layout->fl_stripe_count = cpu_to_le32(1);
layout->fl_object_size = cpu_to_le32(1 << RBD_MAX_OBJ_ORDER);
layout->fl_pg_pool = cpu_to_le32(rbd_dev->pool_id);
ret = ceph_calc_raw_layout(osdc, layout, snapid, ofs, &len, &bno,
req, ops);
rbd_assert(ret == 0);
ceph_osdc_build_request(req, ofs, &len,
ops,
snapc,
&mtime,
req->r_oid, req->r_oid_len);
if (linger_req) {
ceph_osdc_set_request_linger(osdc, req);
*linger_req = req;
}
ret = ceph_osdc_start_request(osdc, req, false);
if (ret < 0)
goto done_err;
if (!rbd_cb) {
ret = ceph_osdc_wait_request(osdc, req);
if (ver)
*ver = le64_to_cpu(req->r_reassert_version.version);
dout("reassert_ver=%llu\n",
(unsigned long long)
le64_to_cpu(req->r_reassert_version.version));
ceph_osdc_put_request(req);
}
return ret;
done_err:
bio_chain_put(req_data->bio);
ceph_osdc_put_request(req);
done_pages:
rbd_coll_end_req(req_data, ret, len);
kfree(req_data);
return ret;
}
static void rbd_req_cb(struct ceph_osd_request *req, struct ceph_msg *msg)
{
struct rbd_request *req_data = req->r_priv;
struct ceph_osd_reply_head *replyhead;
struct ceph_osd_op *op;
__s32 rc;
u64 bytes;
int read_op;
replyhead = msg->front.iov_base;
WARN_ON(le32_to_cpu(replyhead->num_ops) == 0);
op = (void *)(replyhead + 1);
rc = le32_to_cpu(replyhead->result);
bytes = le64_to_cpu(op->extent.length);
read_op = (le16_to_cpu(op->op) == CEPH_OSD_OP_READ);
dout("rbd_req_cb bytes=%llu readop=%d rc=%d\n",
(unsigned long long) bytes, read_op, (int) rc);
if (rc == -ENOENT && read_op) {
zero_bio_chain(req_data->bio, 0);
rc = 0;
} else if (rc == 0 && read_op && bytes < req_data->len) {
zero_bio_chain(req_data->bio, bytes);
bytes = req_data->len;
}
rbd_coll_end_req(req_data, rc, bytes);
if (req_data->bio)
bio_chain_put(req_data->bio);
ceph_osdc_put_request(req);
kfree(req_data);
}
static void rbd_simple_req_cb(struct ceph_osd_request *req, struct ceph_msg *msg)
{
ceph_osdc_put_request(req);
}
static int rbd_req_sync_op(struct rbd_device *rbd_dev,
struct ceph_snap_context *snapc,
u64 snapid,
int flags,
struct ceph_osd_req_op *ops,
const char *object_name,
u64 ofs, u64 inbound_size,
char *inbound,
struct ceph_osd_request **linger_req,
u64 *ver)
{
int ret;
struct page **pages;
int num_pages;
rbd_assert(ops != NULL);
num_pages = calc_pages_for(ofs, inbound_size);
pages = ceph_alloc_page_vector(num_pages, GFP_KERNEL);
if (IS_ERR(pages))
return PTR_ERR(pages);
ret = rbd_do_request(NULL, rbd_dev, snapc, snapid,
object_name, ofs, inbound_size, NULL,
pages, num_pages,
flags,
ops,
NULL, 0,
NULL,
linger_req, ver);
if (ret < 0)
goto done;
if ((flags & CEPH_OSD_FLAG_READ) && inbound)
ret = ceph_copy_from_page_vector(pages, inbound, ofs, ret);
done:
ceph_release_page_vector(pages, num_pages);
return ret;
}
static int rbd_do_op(struct request *rq,
struct rbd_device *rbd_dev,
struct ceph_snap_context *snapc,
u64 snapid,
int opcode, int flags,
u64 ofs, u64 len,
struct bio *bio,
struct rbd_req_coll *coll,
int coll_index)
{
char *seg_name;
u64 seg_ofs;
u64 seg_len;
int ret;
struct ceph_osd_req_op *ops;
u32 payload_len;
seg_name = rbd_segment_name(rbd_dev, ofs);
if (!seg_name)
return -ENOMEM;
seg_len = rbd_segment_length(rbd_dev, ofs, len);
seg_ofs = rbd_segment_offset(rbd_dev, ofs);
payload_len = (flags & CEPH_OSD_FLAG_WRITE ? seg_len : 0);
ret = -ENOMEM;
ops = rbd_create_rw_ops(1, opcode, payload_len);
if (!ops)
goto done;
rbd_assert(seg_len == len);
ret = rbd_do_request(rq, rbd_dev, snapc, snapid,
seg_name, seg_ofs, seg_len,
bio,
NULL, 0,
flags,
ops,
coll, coll_index,
rbd_req_cb, 0, NULL);
rbd_destroy_ops(ops);
done:
kfree(seg_name);
return ret;
}
static int rbd_req_write(struct request *rq,
struct rbd_device *rbd_dev,
struct ceph_snap_context *snapc,
u64 ofs, u64 len,
struct bio *bio,
struct rbd_req_coll *coll,
int coll_index)
{
return rbd_do_op(rq, rbd_dev, snapc, CEPH_NOSNAP,
CEPH_OSD_OP_WRITE,
CEPH_OSD_FLAG_WRITE | CEPH_OSD_FLAG_ONDISK,
ofs, len, bio, coll, coll_index);
}
static int rbd_req_read(struct request *rq,
struct rbd_device *rbd_dev,
u64 snapid,
u64 ofs, u64 len,
struct bio *bio,
struct rbd_req_coll *coll,
int coll_index)
{
return rbd_do_op(rq, rbd_dev, NULL,
snapid,
CEPH_OSD_OP_READ,
CEPH_OSD_FLAG_READ,
ofs, len, bio, coll, coll_index);
}
static int rbd_req_sync_read(struct rbd_device *rbd_dev,
u64 snapid,
const char *object_name,
u64 ofs, u64 len,
char *buf,
u64 *ver)
{
struct ceph_osd_req_op *ops;
int ret;
ops = rbd_create_rw_ops(1, CEPH_OSD_OP_READ, 0);
if (!ops)
return -ENOMEM;
ret = rbd_req_sync_op(rbd_dev, NULL,
snapid,
CEPH_OSD_FLAG_READ,
ops, object_name, ofs, len, buf, NULL, ver);
rbd_destroy_ops(ops);
return ret;
}
static int rbd_req_sync_notify_ack(struct rbd_device *rbd_dev,
u64 ver,
u64 notify_id)
{
struct ceph_osd_req_op *ops;
int ret;
ops = rbd_create_rw_ops(1, CEPH_OSD_OP_NOTIFY_ACK, 0);
if (!ops)
return -ENOMEM;
ops[0].watch.ver = cpu_to_le64(ver);
ops[0].watch.cookie = notify_id;
ops[0].watch.flag = 0;
ret = rbd_do_request(NULL, rbd_dev, NULL, CEPH_NOSNAP,
rbd_dev->header_name, 0, 0, NULL,
NULL, 0,
CEPH_OSD_FLAG_READ,
ops,
NULL, 0,
rbd_simple_req_cb, 0, NULL);
rbd_destroy_ops(ops);
return ret;
}
static void rbd_watch_cb(u64 ver, u64 notify_id, u8 opcode, void *data)
{
struct rbd_device *rbd_dev = (struct rbd_device *)data;
u64 hver;
int rc;
if (!rbd_dev)
return;
dout("rbd_watch_cb %s notify_id=%llu opcode=%u\n",
rbd_dev->header_name, (unsigned long long) notify_id,
(unsigned int) opcode);
rc = rbd_refresh_header(rbd_dev, &hver);
if (rc)
pr_warning(RBD_DRV_NAME "%d got notification but failed to "
" update snaps: %d\n", rbd_dev->major, rc);
rbd_req_sync_notify_ack(rbd_dev, hver, notify_id);
}
static int rbd_req_sync_watch(struct rbd_device *rbd_dev)
{
struct ceph_osd_req_op *ops;
struct ceph_osd_client *osdc = &rbd_dev->rbd_client->client->osdc;
int ret;
ops = rbd_create_rw_ops(1, CEPH_OSD_OP_WATCH, 0);
if (!ops)
return -ENOMEM;
ret = ceph_osdc_create_event(osdc, rbd_watch_cb, 0,
(void *)rbd_dev, &rbd_dev->watch_event);
if (ret < 0)
goto fail;
ops[0].watch.ver = cpu_to_le64(rbd_dev->header.obj_version);
ops[0].watch.cookie = cpu_to_le64(rbd_dev->watch_event->cookie);
ops[0].watch.flag = 1;
ret = rbd_req_sync_op(rbd_dev, NULL,
CEPH_NOSNAP,
CEPH_OSD_FLAG_WRITE | CEPH_OSD_FLAG_ONDISK,
ops,
rbd_dev->header_name,
0, 0, NULL,
&rbd_dev->watch_request, NULL);
if (ret < 0)
goto fail_event;
rbd_destroy_ops(ops);
return 0;
fail_event:
ceph_osdc_cancel_event(rbd_dev->watch_event);
rbd_dev->watch_event = NULL;
fail:
rbd_destroy_ops(ops);
return ret;
}
static int rbd_req_sync_unwatch(struct rbd_device *rbd_dev)
{
struct ceph_osd_req_op *ops;
int ret;
ops = rbd_create_rw_ops(1, CEPH_OSD_OP_WATCH, 0);
if (!ops)
return -ENOMEM;
ops[0].watch.ver = 0;
ops[0].watch.cookie = cpu_to_le64(rbd_dev->watch_event->cookie);
ops[0].watch.flag = 0;
ret = rbd_req_sync_op(rbd_dev, NULL,
CEPH_NOSNAP,
CEPH_OSD_FLAG_WRITE | CEPH_OSD_FLAG_ONDISK,
ops,
rbd_dev->header_name,
0, 0, NULL, NULL, NULL);
rbd_destroy_ops(ops);
ceph_osdc_cancel_event(rbd_dev->watch_event);
rbd_dev->watch_event = NULL;
return ret;
}
static int rbd_req_sync_exec(struct rbd_device *rbd_dev,
const char *object_name,
const char *class_name,
const char *method_name,
const char *outbound,
size_t outbound_size,
char *inbound,
size_t inbound_size,
int flags,
u64 *ver)
{
struct ceph_osd_req_op *ops;
int class_name_len = strlen(class_name);
int method_name_len = strlen(method_name);
int payload_size;
int ret;
payload_size = class_name_len + method_name_len + outbound_size;
ops = rbd_create_rw_ops(1, CEPH_OSD_OP_CALL, payload_size);
if (!ops)
return -ENOMEM;
ops[0].cls.class_name = class_name;
ops[0].cls.class_len = (__u8) class_name_len;
ops[0].cls.method_name = method_name;
ops[0].cls.method_len = (__u8) method_name_len;
ops[0].cls.argc = 0;
ops[0].cls.indata = outbound;
ops[0].cls.indata_len = outbound_size;
ret = rbd_req_sync_op(rbd_dev, NULL,
CEPH_NOSNAP,
flags, ops,
object_name, 0, inbound_size, inbound,
NULL, ver);
rbd_destroy_ops(ops);
dout("cls_exec returned %d\n", ret);
return ret;
}
static struct rbd_req_coll *rbd_alloc_coll(int num_reqs)
{
struct rbd_req_coll *coll =
kzalloc(sizeof(struct rbd_req_coll) +
sizeof(struct rbd_req_status) * num_reqs,
GFP_ATOMIC);
if (!coll)
return NULL;
coll->total = num_reqs;
kref_init(&coll->kref);
return coll;
}
static void rbd_rq_fn(struct request_queue *q)
{
struct rbd_device *rbd_dev = q->queuedata;
struct request *rq;
struct bio_pair *bp = NULL;
while ((rq = blk_fetch_request(q))) {
struct bio *bio;
struct bio *rq_bio, *next_bio = NULL;
bool do_write;
unsigned int size;
u64 op_size = 0;
u64 ofs;
int num_segs, cur_seg = 0;
struct rbd_req_coll *coll;
struct ceph_snap_context *snapc;
dout("fetched request\n");
if ((rq->cmd_type != REQ_TYPE_FS)) {
__blk_end_request_all(rq, 0);
continue;
}
do_write = (rq_data_dir(rq) == WRITE);
size = blk_rq_bytes(rq);
ofs = blk_rq_pos(rq) * SECTOR_SIZE;
rq_bio = rq->bio;
if (do_write && rbd_dev->mapping.read_only) {
__blk_end_request_all(rq, -EROFS);
continue;
}
spin_unlock_irq(q->queue_lock);
down_read(&rbd_dev->header_rwsem);
if (rbd_dev->mapping.snap_id != CEPH_NOSNAP &&
!rbd_dev->mapping.snap_exists) {
up_read(&rbd_dev->header_rwsem);
dout("request for non-existent snapshot");
spin_lock_irq(q->queue_lock);
__blk_end_request_all(rq, -ENXIO);
continue;
}
snapc = ceph_get_snap_context(rbd_dev->header.snapc);
up_read(&rbd_dev->header_rwsem);
dout("%s 0x%x bytes at 0x%llx\n",
do_write ? "write" : "read",
size, (unsigned long long) blk_rq_pos(rq) * SECTOR_SIZE);
num_segs = rbd_get_num_segments(&rbd_dev->header, ofs, size);
if (num_segs <= 0) {
spin_lock_irq(q->queue_lock);
__blk_end_request_all(rq, num_segs);
ceph_put_snap_context(snapc);
continue;
}
coll = rbd_alloc_coll(num_segs);
if (!coll) {
spin_lock_irq(q->queue_lock);
__blk_end_request_all(rq, -ENOMEM);
ceph_put_snap_context(snapc);
continue;
}
do {
dout("rq->bio->bi_vcnt=%hu\n", rq->bio->bi_vcnt);
op_size = rbd_segment_length(rbd_dev, ofs, size);
kref_get(&coll->kref);
bio = bio_chain_clone(&rq_bio, &next_bio, &bp,
op_size, GFP_ATOMIC);
if (!bio) {
rbd_coll_end_req_index(rq, coll, cur_seg,
-ENOMEM, op_size);
goto next_seg;
}
if (do_write)
rbd_req_write(rq, rbd_dev,
snapc,
ofs,
op_size, bio,
coll, cur_seg);
else
rbd_req_read(rq, rbd_dev,
rbd_dev->mapping.snap_id,
ofs,
op_size, bio,
coll, cur_seg);
next_seg:
size -= op_size;
ofs += op_size;
cur_seg++;
rq_bio = next_bio;
} while (size > 0);
kref_put(&coll->kref, rbd_coll_release);
if (bp)
bio_pair_release(bp);
spin_lock_irq(q->queue_lock);
ceph_put_snap_context(snapc);
}
}
static int rbd_merge_bvec(struct request_queue *q, struct bvec_merge_data *bmd,
struct bio_vec *bvec)
{
struct rbd_device *rbd_dev = q->queuedata;
unsigned int chunk_sectors;
sector_t sector;
unsigned int bio_sectors;
int max;
chunk_sectors = 1 << (rbd_dev->header.obj_order - SECTOR_SHIFT);
sector = bmd->bi_sector + get_start_sect(bmd->bi_bdev);
bio_sectors = bmd->bi_size >> SECTOR_SHIFT;
max = (chunk_sectors - ((sector & (chunk_sectors - 1))
+ bio_sectors)) << SECTOR_SHIFT;
if (max < 0)
max = 0;
if (max <= bvec->bv_len && bio_sectors == 0)
return bvec->bv_len;
return max;
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
ret = rbd_req_sync_read(rbd_dev, CEPH_NOSNAP,
rbd_dev->header_name,
0, size,
(char *) ondisk, version);
if (ret < 0)
goto out_err;
if (WARN_ON((size_t) ret < size)) {
ret = -ENXIO;
pr_warning("short header read for image %s"
" (want %zd got %d)\n",
rbd_dev->image_name, size, ret);
goto out_err;
}
if (!rbd_dev_ondisk_valid(ondisk)) {
ret = -ENXIO;
pr_warning("invalid header for image %s\n",
rbd_dev->image_name);
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
static void __rbd_remove_all_snaps(struct rbd_device *rbd_dev)
{
struct rbd_snap *snap;
struct rbd_snap *next;
list_for_each_entry_safe(snap, next, &rbd_dev->snaps, node)
__rbd_remove_snap_dev(snap);
}
static int __rbd_refresh_header(struct rbd_device *rbd_dev, u64 *hver)
{
int ret;
struct rbd_image_header h;
ret = rbd_read_header(rbd_dev, &h);
if (ret < 0)
return ret;
down_write(&rbd_dev->header_rwsem);
if (rbd_dev->mapping.snap_id == CEPH_NOSNAP) {
sector_t size = (sector_t) h.image_size / SECTOR_SIZE;
if (size != (sector_t) rbd_dev->mapping.size) {
dout("setting size to %llu sectors",
(unsigned long long) size);
rbd_dev->mapping.size = (u64) size;
set_capacity(rbd_dev->disk, size);
}
}
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
static int rbd_refresh_header(struct rbd_device *rbd_dev, u64 *hver)
{
int ret;
mutex_lock_nested(&ctl_mutex, SINGLE_DEPTH_NESTING);
ret = __rbd_refresh_header(rbd_dev, hver);
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
q = blk_init_queue(rbd_rq_fn, &rbd_dev->lock);
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
return sprintf(buf, "%s\n", rbd_dev->pool_name);
}
static ssize_t rbd_pool_id_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct rbd_device *rbd_dev = dev_to_rbd_dev(dev);
return sprintf(buf, "%d\n", rbd_dev->pool_id);
}
static ssize_t rbd_name_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct rbd_device *rbd_dev = dev_to_rbd_dev(dev);
return sprintf(buf, "%s\n", rbd_dev->image_name);
}
static ssize_t rbd_image_id_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct rbd_device *rbd_dev = dev_to_rbd_dev(dev);
return sprintf(buf, "%s\n", rbd_dev->image_id);
}
static ssize_t rbd_snap_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct rbd_device *rbd_dev = dev_to_rbd_dev(dev);
return sprintf(buf, "%s\n", rbd_dev->mapping.snap_name);
}
static ssize_t rbd_image_refresh(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t size)
{
struct rbd_device *rbd_dev = dev_to_rbd_dev(dev);
int ret;
ret = rbd_refresh_header(rbd_dev, NULL);
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
static bool rbd_snap_registered(struct rbd_snap *snap)
{
bool ret = snap->dev.type == &rbd_snap_device_type;
bool reg = device_is_registered(&snap->dev);
rbd_assert(!ret ^ reg);
return ret;
}
static void __rbd_remove_snap_dev(struct rbd_snap *snap)
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
dev_set_name(dev, "snap_%s", snap->name);
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
ret = rbd_req_sync_exec(rbd_dev, rbd_dev->header_name,
"rbd", "get_size",
(char *) &snapid, sizeof (snapid),
(char *) &size_buf, sizeof (size_buf),
CEPH_OSD_FLAG_READ, NULL);
dout("%s: rbd_req_sync_exec returned %d\n", __func__, ret);
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
ret = rbd_req_sync_exec(rbd_dev, rbd_dev->header_name,
"rbd", "get_object_prefix",
NULL, 0,
reply_buf, RBD_OBJ_PREFIX_LEN_MAX,
CEPH_OSD_FLAG_READ, NULL);
dout("%s: rbd_req_sync_exec returned %d\n", __func__, ret);
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
int ret;
ret = rbd_req_sync_exec(rbd_dev, rbd_dev->header_name,
"rbd", "get_features",
(char *) &snapid, sizeof (snapid),
(char *) &features_buf, sizeof (features_buf),
CEPH_OSD_FLAG_READ, NULL);
dout("%s: rbd_req_sync_exec returned %d\n", __func__, ret);
if (ret < 0)
return ret;
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
ret = rbd_req_sync_exec(rbd_dev, rbd_dev->header_name,
"rbd", "get_snapcontext",
NULL, 0,
reply_buf, size,
CEPH_OSD_FLAG_READ, ver);
dout("%s: rbd_req_sync_exec returned %d\n", __func__, ret);
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
size_t snap_name_len;
char *snap_name;
size = sizeof (__le32) + RBD_MAX_SNAP_NAME_LEN;
reply_buf = kmalloc(size, GFP_KERNEL);
if (!reply_buf)
return ERR_PTR(-ENOMEM);
snap_id = cpu_to_le64(rbd_dev->header.snapc->snaps[which]);
ret = rbd_req_sync_exec(rbd_dev, rbd_dev->header_name,
"rbd", "get_snapshot_name",
(char *) &snap_id, sizeof (snap_id),
reply_buf, size,
CEPH_OSD_FLAG_READ, NULL);
dout("%s: rbd_req_sync_exec returned %d\n", __func__, ret);
if (ret < 0)
goto out;
p = reply_buf;
end = (char *) reply_buf + size;
snap_name_len = 0;
snap_name = ceph_extract_encoded_string(&p, end, &snap_name_len,
GFP_KERNEL);
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
__le64 snap_id;
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
if (rbd_dev->mapping.snap_id == snap->id)
rbd_dev->mapping.snap_exists = false;
__rbd_remove_snap_dev(snap);
dout("%ssnap id %llu has been removed\n",
rbd_dev->mapping.snap_id == snap->id ?
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
dout("%s called\n", __func__);
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
static int rbd_init_watch_dev(struct rbd_device *rbd_dev)
{
int ret, rc;
do {
ret = rbd_req_sync_watch(rbd_dev);
if (ret == -ERANGE) {
rc = rbd_refresh_header(rbd_dev, NULL);
if (rc < 0)
return rc;
}
} while (ret == -ERANGE);
return ret;
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
if (rbd_id > max_id)
max_id = rbd_id;
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
dup = kmalloc(len + 1, GFP_KERNEL);
if (!dup)
return NULL;
memcpy(dup, *buf, len);
*(dup + len) = '\0';
*buf += len;
if (lenp)
*lenp = len;
return dup;
}
static char *rbd_add_parse_args(struct rbd_device *rbd_dev,
const char *buf,
const char **mon_addrs,
size_t *mon_addrs_size,
char *options,
size_t options_size)
{
size_t len;
char *err_ptr = ERR_PTR(-EINVAL);
char *snap_name;
len = next_token(&buf);
if (!len)
return err_ptr;
*mon_addrs_size = len + 1;
*mon_addrs = buf;
buf += len;
len = copy_token(&buf, options, options_size);
if (!len || len >= options_size)
return err_ptr;
err_ptr = ERR_PTR(-ENOMEM);
rbd_dev->pool_name = dup_token(&buf, NULL);
if (!rbd_dev->pool_name)
goto out_err;
rbd_dev->image_name = dup_token(&buf, &rbd_dev->image_name_len);
if (!rbd_dev->image_name)
goto out_err;
len = next_token(&buf);
if (!len) {
buf = RBD_SNAP_HEAD_NAME;
len = sizeof (RBD_SNAP_HEAD_NAME) - 1;
}
snap_name = kmalloc(len + 1, GFP_KERNEL);
if (!snap_name)
goto out_err;
memcpy(snap_name, buf, len);
*(snap_name + len) = '\0';
dout(" SNAP_NAME is <%s>, len is %zd\n", snap_name, len);
return snap_name;
out_err:
kfree(rbd_dev->image_name);
rbd_dev->image_name = NULL;
rbd_dev->image_name_len = 0;
kfree(rbd_dev->pool_name);
rbd_dev->pool_name = NULL;
return err_ptr;
}
static int rbd_dev_image_id(struct rbd_device *rbd_dev)
{
int ret;
size_t size;
char *object_name;
void *response;
void *p;
size = sizeof (RBD_ID_PREFIX) + rbd_dev->image_name_len;
object_name = kmalloc(size, GFP_NOIO);
if (!object_name)
return -ENOMEM;
sprintf(object_name, "%s%s", RBD_ID_PREFIX, rbd_dev->image_name);
dout("rbd id object name is %s\n", object_name);
size = sizeof (__le32) + RBD_IMAGE_ID_LEN_MAX;
response = kzalloc(size, GFP_NOIO);
if (!response) {
ret = -ENOMEM;
goto out;
}
ret = rbd_req_sync_exec(rbd_dev, object_name,
"rbd", "get_id",
NULL, 0,
response, RBD_IMAGE_ID_LEN_MAX,
CEPH_OSD_FLAG_READ, NULL);
dout("%s: rbd_req_sync_exec returned %d\n", __func__, ret);
if (ret < 0)
goto out;
p = response;
rbd_dev->image_id = ceph_extract_encoded_string(&p,
p + RBD_IMAGE_ID_LEN_MAX,
&rbd_dev->image_id_len,
GFP_NOIO);
if (IS_ERR(rbd_dev->image_id)) {
ret = PTR_ERR(rbd_dev->image_id);
rbd_dev->image_id = NULL;
} else {
dout("image_id is %s\n", rbd_dev->image_id);
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
rbd_dev->image_id = kstrdup("", GFP_KERNEL);
if (!rbd_dev->image_id)
return -ENOMEM;
rbd_dev->image_id_len = 0;
size = rbd_dev->image_name_len + sizeof (RBD_SUFFIX);
rbd_dev->header_name = kmalloc(size, GFP_KERNEL);
if (!rbd_dev->header_name) {
ret = -ENOMEM;
goto out_err;
}
sprintf(rbd_dev->header_name, "%s%s", rbd_dev->image_name, RBD_SUFFIX);
ret = rbd_read_header(rbd_dev, &rbd_dev->header);
if (ret < 0)
goto out_err;
rbd_dev->image_format = 1;
dout("discovered version 1 image, header name is %s\n",
rbd_dev->header_name);
return 0;
out_err:
kfree(rbd_dev->header_name);
rbd_dev->header_name = NULL;
kfree(rbd_dev->image_id);
rbd_dev->image_id = NULL;
return ret;
}
static int rbd_dev_v2_probe(struct rbd_device *rbd_dev)
{
size_t size;
int ret;
u64 ver = 0;
size = sizeof (RBD_HEADER_PREFIX) + rbd_dev->image_id_len;
rbd_dev->header_name = kmalloc(size, GFP_KERNEL);
if (!rbd_dev->header_name)
return -ENOMEM;
sprintf(rbd_dev->header_name, "%s%s",
RBD_HEADER_PREFIX, rbd_dev->image_id);
ret = rbd_dev_v2_image_size(rbd_dev);
if (ret < 0)
goto out_err;
ret = rbd_dev_v2_object_prefix(rbd_dev);
if (ret < 0)
goto out_err;
ret = rbd_dev_v2_features(rbd_dev);
if (ret < 0)
goto out_err;
rbd_dev->header.crypt_type = 0;
rbd_dev->header.comp_type = 0;
ret = rbd_dev_v2_snap_context(rbd_dev, &ver);
if (ret)
goto out_err;
rbd_dev->header.obj_version = ver;
rbd_dev->image_format = 2;
dout("discovered version 2 image, header name is %s\n",
rbd_dev->header_name);
return -ENOTSUPP;
out_err:
kfree(rbd_dev->header_name);
rbd_dev->header_name = NULL;
kfree(rbd_dev->header.object_prefix);
rbd_dev->header.object_prefix = NULL;
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
if (ret)
dout("probe failed, returning %d\n", ret);
return ret;
}
static ssize_t rbd_add(struct bus_type *bus,
const char *buf,
size_t count)
{
char *options;
struct rbd_device *rbd_dev = NULL;
const char *mon_addrs = NULL;
size_t mon_addrs_size = 0;
struct ceph_osd_client *osdc;
int rc = -ENOMEM;
char *snap_name;
if (!try_module_get(THIS_MODULE))
return -ENODEV;
options = kmalloc(count, GFP_KERNEL);
if (!options)
goto err_out_mem;
rbd_dev = kzalloc(sizeof(*rbd_dev), GFP_KERNEL);
if (!rbd_dev)
goto err_out_mem;
spin_lock_init(&rbd_dev->lock);
INIT_LIST_HEAD(&rbd_dev->node);
INIT_LIST_HEAD(&rbd_dev->snaps);
init_rwsem(&rbd_dev->header_rwsem);
snap_name = rbd_add_parse_args(rbd_dev, buf,
&mon_addrs, &mon_addrs_size, options, count);
if (IS_ERR(snap_name)) {
rc = PTR_ERR(snap_name);
goto err_out_mem;
}
rc = rbd_get_client(rbd_dev, mon_addrs, mon_addrs_size - 1, options);
if (rc < 0)
goto err_out_args;
osdc = &rbd_dev->rbd_client->client->osdc;
rc = ceph_pg_poolid_by_name(osdc->osdmap, rbd_dev->pool_name);
if (rc < 0)
goto err_out_client;
rbd_dev->pool_id = rc;
rc = rbd_dev_probe(rbd_dev);
if (rc < 0)
goto err_out_client;
rbd_assert(rbd_image_format_valid(rbd_dev->image_format));
rc = rbd_dev_snaps_update(rbd_dev);
if (rc)
goto err_out_header;
rc = rbd_dev_set_mapping(rbd_dev, snap_name);
if (rc)
goto err_out_header;
rbd_dev_id_get(rbd_dev);
BUILD_BUG_ON(DEV_NAME_LEN
< sizeof (RBD_DRV_NAME) + MAX_INT_FORMAT_WIDTH);
sprintf(rbd_dev->name, "%s%d", RBD_DRV_NAME, rbd_dev->dev_id);
rc = register_blkdev(0, rbd_dev->name);
if (rc < 0)
goto err_out_id;
rbd_dev->major = rc;
rc = rbd_init_disk(rbd_dev);
if (rc)
goto err_out_blkdev;
rc = rbd_bus_add_dev(rbd_dev);
if (rc)
goto err_out_disk;
down_write(&rbd_dev->header_rwsem);
rc = rbd_dev_snaps_register(rbd_dev);
up_write(&rbd_dev->header_rwsem);
if (rc)
goto err_out_bus;
rc = rbd_init_watch_dev(rbd_dev);
if (rc)
goto err_out_bus;
add_disk(rbd_dev->disk);
pr_info("%s: added with size 0x%llx\n", rbd_dev->disk->disk_name,
(unsigned long long) rbd_dev->mapping.size);
return count;
err_out_bus:
rbd_bus_del_dev(rbd_dev);
kfree(options);
return rc;
err_out_disk:
rbd_free_disk(rbd_dev);
err_out_blkdev:
unregister_blkdev(rbd_dev->major, rbd_dev->name);
err_out_id:
rbd_dev_id_put(rbd_dev);
err_out_header:
rbd_header_free(&rbd_dev->header);
err_out_client:
kfree(rbd_dev->header_name);
rbd_put_client(rbd_dev);
kfree(rbd_dev->image_id);
err_out_args:
kfree(rbd_dev->mapping.snap_name);
kfree(rbd_dev->image_name);
kfree(rbd_dev->pool_name);
err_out_mem:
kfree(rbd_dev);
kfree(options);
dout("Error adding device %s\n", buf);
module_put(THIS_MODULE);
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
if (rbd_dev->watch_request) {
struct ceph_client *client = rbd_dev->rbd_client->client;
ceph_osdc_unregister_linger_request(&client->osdc,
rbd_dev->watch_request);
}
if (rbd_dev->watch_event)
rbd_req_sync_unwatch(rbd_dev);
rbd_put_client(rbd_dev);
rbd_free_disk(rbd_dev);
unregister_blkdev(rbd_dev->major, rbd_dev->name);
rbd_header_free(&rbd_dev->header);
kfree(rbd_dev->mapping.snap_name);
kfree(rbd_dev->image_id);
kfree(rbd_dev->header_name);
kfree(rbd_dev->pool_name);
kfree(rbd_dev->image_name);
rbd_dev_id_put(rbd_dev);
kfree(rbd_dev);
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
__rbd_remove_all_snaps(rbd_dev);
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
int __init rbd_init(void)
{
int rc;
rc = rbd_sysfs_init();
if (rc)
return rc;
pr_info("loaded " RBD_DRV_NAME_LONG "\n");
return 0;
}
void __exit rbd_exit(void)
{
rbd_sysfs_cleanup();
}
