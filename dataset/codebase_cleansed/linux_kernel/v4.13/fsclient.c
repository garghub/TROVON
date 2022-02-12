static void xdr_decode_AFSFid(const __be32 **_bp, struct afs_fid *fid)
{
const __be32 *bp = *_bp;
fid->vid = ntohl(*bp++);
fid->vnode = ntohl(*bp++);
fid->unique = ntohl(*bp++);
*_bp = bp;
}
static void xdr_decode_AFSFetchStatus(const __be32 **_bp,
struct afs_file_status *status,
struct afs_vnode *vnode,
afs_dataversion_t *store_version)
{
afs_dataversion_t expected_version;
const __be32 *bp = *_bp;
umode_t mode;
u64 data_version, size;
u32 changed = 0;
kuid_t owner;
kgid_t group;
#define EXTRACT(DST) \
do { \
u32 x = ntohl(*bp++); \
changed |= DST - x; \
DST = x; \
} while (0)
status->if_version = ntohl(*bp++);
EXTRACT(status->type);
EXTRACT(status->nlink);
size = ntohl(*bp++);
data_version = ntohl(*bp++);
EXTRACT(status->author);
owner = make_kuid(&init_user_ns, ntohl(*bp++));
changed |= !uid_eq(owner, status->owner);
status->owner = owner;
EXTRACT(status->caller_access);
EXTRACT(status->anon_access);
EXTRACT(status->mode);
EXTRACT(status->parent.vnode);
EXTRACT(status->parent.unique);
bp++;
status->mtime_client = ntohl(*bp++);
status->mtime_server = ntohl(*bp++);
group = make_kgid(&init_user_ns, ntohl(*bp++));
changed |= !gid_eq(group, status->group);
status->group = group;
bp++;
data_version |= (u64) ntohl(*bp++) << 32;
EXTRACT(status->lock_count);
size |= (u64) ntohl(*bp++) << 32;
bp++;
*_bp = bp;
if (size != status->size) {
status->size = size;
changed |= true;
}
status->mode &= S_IALLUGO;
_debug("vnode time %lx, %lx",
status->mtime_client, status->mtime_server);
if (vnode) {
status->parent.vid = vnode->fid.vid;
if (changed && !test_bit(AFS_VNODE_UNSET, &vnode->flags)) {
_debug("vnode changed");
i_size_write(&vnode->vfs_inode, size);
vnode->vfs_inode.i_uid = status->owner;
vnode->vfs_inode.i_gid = status->group;
vnode->vfs_inode.i_generation = vnode->fid.unique;
set_nlink(&vnode->vfs_inode, status->nlink);
mode = vnode->vfs_inode.i_mode;
mode &= ~S_IALLUGO;
mode |= status->mode;
barrier();
vnode->vfs_inode.i_mode = mode;
}
vnode->vfs_inode.i_ctime.tv_sec = status->mtime_client;
vnode->vfs_inode.i_mtime = vnode->vfs_inode.i_ctime;
vnode->vfs_inode.i_atime = vnode->vfs_inode.i_ctime;
vnode->vfs_inode.i_version = data_version;
}
expected_version = status->data_version;
if (store_version)
expected_version = *store_version;
if (expected_version != data_version) {
status->data_version = data_version;
if (vnode && !test_bit(AFS_VNODE_UNSET, &vnode->flags)) {
_debug("vnode modified %llx on {%x:%u}",
(unsigned long long) data_version,
vnode->fid.vid, vnode->fid.vnode);
set_bit(AFS_VNODE_MODIFIED, &vnode->flags);
set_bit(AFS_VNODE_ZAP_DATA, &vnode->flags);
}
} else if (store_version) {
status->data_version = data_version;
}
}
static void xdr_decode_AFSCallBack(const __be32 **_bp, struct afs_vnode *vnode)
{
const __be32 *bp = *_bp;
vnode->cb_version = ntohl(*bp++);
vnode->cb_expiry = ntohl(*bp++);
vnode->cb_type = ntohl(*bp++);
vnode->cb_expires = vnode->cb_expiry + ktime_get_real_seconds();
*_bp = bp;
}
static void xdr_decode_AFSCallBack_raw(const __be32 **_bp,
struct afs_callback *cb)
{
const __be32 *bp = *_bp;
cb->version = ntohl(*bp++);
cb->expiry = ntohl(*bp++);
cb->type = ntohl(*bp++);
*_bp = bp;
}
static void xdr_decode_AFSVolSync(const __be32 **_bp,
struct afs_volsync *volsync)
{
const __be32 *bp = *_bp;
volsync->creation = ntohl(*bp++);
bp++;
bp++;
bp++;
bp++;
bp++;
*_bp = bp;
}
static void xdr_encode_AFS_StoreStatus(__be32 **_bp, struct iattr *attr)
{
__be32 *bp = *_bp;
u32 mask = 0, mtime = 0, owner = 0, group = 0, mode = 0;
mask = 0;
if (attr->ia_valid & ATTR_MTIME) {
mask |= AFS_SET_MTIME;
mtime = attr->ia_mtime.tv_sec;
}
if (attr->ia_valid & ATTR_UID) {
mask |= AFS_SET_OWNER;
owner = from_kuid(&init_user_ns, attr->ia_uid);
}
if (attr->ia_valid & ATTR_GID) {
mask |= AFS_SET_GROUP;
group = from_kgid(&init_user_ns, attr->ia_gid);
}
if (attr->ia_valid & ATTR_MODE) {
mask |= AFS_SET_MODE;
mode = attr->ia_mode & S_IALLUGO;
}
*bp++ = htonl(mask);
*bp++ = htonl(mtime);
*bp++ = htonl(owner);
*bp++ = htonl(group);
*bp++ = htonl(mode);
*bp++ = 0;
*_bp = bp;
}
static void xdr_decode_AFSFetchVolumeStatus(const __be32 **_bp,
struct afs_volume_status *vs)
{
const __be32 *bp = *_bp;
vs->vid = ntohl(*bp++);
vs->parent_id = ntohl(*bp++);
vs->online = ntohl(*bp++);
vs->in_service = ntohl(*bp++);
vs->blessed = ntohl(*bp++);
vs->needs_salvage = ntohl(*bp++);
vs->type = ntohl(*bp++);
vs->min_quota = ntohl(*bp++);
vs->max_quota = ntohl(*bp++);
vs->blocks_in_use = ntohl(*bp++);
vs->part_blocks_avail = ntohl(*bp++);
vs->part_max_blocks = ntohl(*bp++);
*_bp = bp;
}
static int afs_deliver_fs_fetch_status(struct afs_call *call)
{
struct afs_vnode *vnode = call->reply;
const __be32 *bp;
int ret;
_enter("");
ret = afs_transfer_reply(call);
if (ret < 0)
return ret;
bp = call->buffer;
xdr_decode_AFSFetchStatus(&bp, &vnode->status, vnode, NULL);
xdr_decode_AFSCallBack(&bp, vnode);
if (call->reply2)
xdr_decode_AFSVolSync(&bp, call->reply2);
_leave(" = 0 [done]");
return 0;
}
int afs_fs_fetch_file_status(struct afs_server *server,
struct key *key,
struct afs_vnode *vnode,
struct afs_volsync *volsync,
bool async)
{
struct afs_call *call;
__be32 *bp;
_enter(",%x,{%x:%u},,",
key_serial(key), vnode->fid.vid, vnode->fid.vnode);
call = afs_alloc_flat_call(&afs_RXFSFetchStatus, 16, (21 + 3 + 6) * 4);
if (!call)
return -ENOMEM;
call->key = key;
call->reply = vnode;
call->reply2 = volsync;
call->service_id = FS_SERVICE;
call->port = htons(AFS_FS_PORT);
bp = call->request;
bp[0] = htonl(FSFETCHSTATUS);
bp[1] = htonl(vnode->fid.vid);
bp[2] = htonl(vnode->fid.vnode);
bp[3] = htonl(vnode->fid.unique);
return afs_make_call(&server->addr, call, GFP_NOFS, async);
}
static int afs_deliver_fs_fetch_data(struct afs_call *call)
{
struct afs_vnode *vnode = call->reply;
struct afs_read *req = call->reply3;
const __be32 *bp;
unsigned int size;
void *buffer;
int ret;
_enter("{%u,%zu/%u;%llu/%llu}",
call->unmarshall, call->offset, call->count,
req->remain, req->actual_len);
switch (call->unmarshall) {
case 0:
req->actual_len = 0;
call->offset = 0;
call->unmarshall++;
if (call->operation_ID != FSFETCHDATA64) {
call->unmarshall++;
goto no_msw;
}
case 1:
_debug("extract data length (MSW)");
ret = afs_extract_data(call, &call->tmp, 4, true);
if (ret < 0)
return ret;
req->actual_len = ntohl(call->tmp);
req->actual_len <<= 32;
call->offset = 0;
call->unmarshall++;
no_msw:
case 2:
_debug("extract data length");
ret = afs_extract_data(call, &call->tmp, 4, true);
if (ret < 0)
return ret;
req->actual_len |= ntohl(call->tmp);
_debug("DATA length: %llu", req->actual_len);
req->remain = req->actual_len;
call->offset = req->pos & (PAGE_SIZE - 1);
req->index = 0;
if (req->actual_len == 0)
goto no_more_data;
call->unmarshall++;
begin_page:
ASSERTCMP(req->index, <, req->nr_pages);
if (req->remain > PAGE_SIZE - call->offset)
size = PAGE_SIZE - call->offset;
else
size = req->remain;
call->count = call->offset + size;
ASSERTCMP(call->count, <=, PAGE_SIZE);
req->remain -= size;
case 3:
_debug("extract data %llu/%llu %zu/%u",
req->remain, req->actual_len, call->offset, call->count);
buffer = kmap(req->pages[req->index]);
ret = afs_extract_data(call, buffer, call->count, true);
kunmap(req->pages[req->index]);
if (ret < 0)
return ret;
if (call->offset == PAGE_SIZE) {
if (req->page_done)
req->page_done(call, req);
req->index++;
if (req->remain > 0) {
call->offset = 0;
if (req->index >= req->nr_pages) {
call->unmarshall = 4;
goto begin_discard;
}
goto begin_page;
}
}
goto no_more_data;
begin_discard:
case 4:
size = min_t(loff_t, sizeof(afs_discard_buffer), req->remain);
call->count = size;
_debug("extract discard %llu/%llu %zu/%u",
req->remain, req->actual_len, call->offset, call->count);
call->offset = 0;
ret = afs_extract_data(call, afs_discard_buffer, call->count, true);
req->remain -= call->offset;
if (ret < 0)
return ret;
if (req->remain > 0)
goto begin_discard;
no_more_data:
call->offset = 0;
call->unmarshall = 5;
case 5:
ret = afs_extract_data(call, call->buffer,
(21 + 3 + 6) * 4, false);
if (ret < 0)
return ret;
bp = call->buffer;
xdr_decode_AFSFetchStatus(&bp, &vnode->status, vnode, NULL);
xdr_decode_AFSCallBack(&bp, vnode);
if (call->reply2)
xdr_decode_AFSVolSync(&bp, call->reply2);
call->offset = 0;
call->unmarshall++;
case 6:
break;
}
for (; req->index < req->nr_pages; req->index++) {
if (call->count < PAGE_SIZE)
zero_user_segment(req->pages[req->index],
call->count, PAGE_SIZE);
if (req->page_done)
req->page_done(call, req);
call->count = 0;
}
_leave(" = 0 [done]");
return 0;
}
static void afs_fetch_data_destructor(struct afs_call *call)
{
struct afs_read *req = call->reply3;
afs_put_read(req);
afs_flat_call_destructor(call);
}
static int afs_fs_fetch_data64(struct afs_server *server,
struct key *key,
struct afs_vnode *vnode,
struct afs_read *req,
bool async)
{
struct afs_call *call;
__be32 *bp;
_enter("");
call = afs_alloc_flat_call(&afs_RXFSFetchData64, 32, (21 + 3 + 6) * 4);
if (!call)
return -ENOMEM;
call->key = key;
call->reply = vnode;
call->reply2 = NULL;
call->reply3 = req;
call->service_id = FS_SERVICE;
call->port = htons(AFS_FS_PORT);
call->operation_ID = FSFETCHDATA64;
bp = call->request;
bp[0] = htonl(FSFETCHDATA64);
bp[1] = htonl(vnode->fid.vid);
bp[2] = htonl(vnode->fid.vnode);
bp[3] = htonl(vnode->fid.unique);
bp[4] = htonl(upper_32_bits(req->pos));
bp[5] = htonl(lower_32_bits(req->pos));
bp[6] = 0;
bp[7] = htonl(lower_32_bits(req->len));
atomic_inc(&req->usage);
return afs_make_call(&server->addr, call, GFP_NOFS, async);
}
int afs_fs_fetch_data(struct afs_server *server,
struct key *key,
struct afs_vnode *vnode,
struct afs_read *req,
bool async)
{
struct afs_call *call;
__be32 *bp;
if (upper_32_bits(req->pos) ||
upper_32_bits(req->len) ||
upper_32_bits(req->pos + req->len))
return afs_fs_fetch_data64(server, key, vnode, req, async);
_enter("");
call = afs_alloc_flat_call(&afs_RXFSFetchData, 24, (21 + 3 + 6) * 4);
if (!call)
return -ENOMEM;
call->key = key;
call->reply = vnode;
call->reply2 = NULL;
call->reply3 = req;
call->service_id = FS_SERVICE;
call->port = htons(AFS_FS_PORT);
call->operation_ID = FSFETCHDATA;
bp = call->request;
bp[0] = htonl(FSFETCHDATA);
bp[1] = htonl(vnode->fid.vid);
bp[2] = htonl(vnode->fid.vnode);
bp[3] = htonl(vnode->fid.unique);
bp[4] = htonl(lower_32_bits(req->pos));
bp[5] = htonl(lower_32_bits(req->len));
atomic_inc(&req->usage);
return afs_make_call(&server->addr, call, GFP_NOFS, async);
}
static int afs_deliver_fs_give_up_callbacks(struct afs_call *call)
{
_enter("");
return afs_extract_data(call, NULL, 0, false);
}
int afs_fs_give_up_callbacks(struct afs_server *server,
bool async)
{
struct afs_call *call;
size_t ncallbacks;
__be32 *bp, *tp;
int loop;
ncallbacks = CIRC_CNT(server->cb_break_head, server->cb_break_tail,
ARRAY_SIZE(server->cb_break));
_enter("{%zu},", ncallbacks);
if (ncallbacks == 0)
return 0;
if (ncallbacks > AFSCBMAX)
ncallbacks = AFSCBMAX;
_debug("break %zu callbacks", ncallbacks);
call = afs_alloc_flat_call(&afs_RXFSGiveUpCallBacks,
12 + ncallbacks * 6 * 4, 0);
if (!call)
return -ENOMEM;
call->service_id = FS_SERVICE;
call->port = htons(AFS_FS_PORT);
bp = call->request;
tp = bp + 2 + ncallbacks * 3;
*bp++ = htonl(FSGIVEUPCALLBACKS);
*bp++ = htonl(ncallbacks);
*tp++ = htonl(ncallbacks);
atomic_sub(ncallbacks, &server->cb_break_n);
for (loop = ncallbacks; loop > 0; loop--) {
struct afs_callback *cb =
&server->cb_break[server->cb_break_tail];
*bp++ = htonl(cb->fid.vid);
*bp++ = htonl(cb->fid.vnode);
*bp++ = htonl(cb->fid.unique);
*tp++ = htonl(cb->version);
*tp++ = htonl(cb->expiry);
*tp++ = htonl(cb->type);
smp_mb();
server->cb_break_tail =
(server->cb_break_tail + 1) &
(ARRAY_SIZE(server->cb_break) - 1);
}
ASSERT(ncallbacks > 0);
wake_up_nr(&server->cb_break_waitq, ncallbacks);
return afs_make_call(&server->addr, call, GFP_NOFS, async);
}
static int afs_deliver_fs_create_vnode(struct afs_call *call)
{
struct afs_vnode *vnode = call->reply;
const __be32 *bp;
int ret;
_enter("{%u}", call->unmarshall);
ret = afs_transfer_reply(call);
if (ret < 0)
return ret;
bp = call->buffer;
xdr_decode_AFSFid(&bp, call->reply2);
xdr_decode_AFSFetchStatus(&bp, call->reply3, NULL, NULL);
xdr_decode_AFSFetchStatus(&bp, &vnode->status, vnode, NULL);
xdr_decode_AFSCallBack_raw(&bp, call->reply4);
_leave(" = 0 [done]");
return 0;
}
int afs_fs_create(struct afs_server *server,
struct key *key,
struct afs_vnode *vnode,
const char *name,
umode_t mode,
struct afs_fid *newfid,
struct afs_file_status *newstatus,
struct afs_callback *newcb,
bool async)
{
struct afs_call *call;
size_t namesz, reqsz, padsz;
__be32 *bp;
_enter("");
namesz = strlen(name);
padsz = (4 - (namesz & 3)) & 3;
reqsz = (5 * 4) + namesz + padsz + (6 * 4);
call = afs_alloc_flat_call(&afs_RXFSCreateXXXX, reqsz,
(3 + 21 + 21 + 3 + 6) * 4);
if (!call)
return -ENOMEM;
call->key = key;
call->reply = vnode;
call->reply2 = newfid;
call->reply3 = newstatus;
call->reply4 = newcb;
call->service_id = FS_SERVICE;
call->port = htons(AFS_FS_PORT);
bp = call->request;
*bp++ = htonl(S_ISDIR(mode) ? FSMAKEDIR : FSCREATEFILE);
*bp++ = htonl(vnode->fid.vid);
*bp++ = htonl(vnode->fid.vnode);
*bp++ = htonl(vnode->fid.unique);
*bp++ = htonl(namesz);
memcpy(bp, name, namesz);
bp = (void *) bp + namesz;
if (padsz > 0) {
memset(bp, 0, padsz);
bp = (void *) bp + padsz;
}
*bp++ = htonl(AFS_SET_MODE | AFS_SET_MTIME);
*bp++ = htonl(vnode->vfs_inode.i_mtime.tv_sec);
*bp++ = 0;
*bp++ = 0;
*bp++ = htonl(mode & S_IALLUGO);
*bp++ = 0;
return afs_make_call(&server->addr, call, GFP_NOFS, async);
}
static int afs_deliver_fs_remove(struct afs_call *call)
{
struct afs_vnode *vnode = call->reply;
const __be32 *bp;
int ret;
_enter("{%u}", call->unmarshall);
ret = afs_transfer_reply(call);
if (ret < 0)
return ret;
bp = call->buffer;
xdr_decode_AFSFetchStatus(&bp, &vnode->status, vnode, NULL);
_leave(" = 0 [done]");
return 0;
}
int afs_fs_remove(struct afs_server *server,
struct key *key,
struct afs_vnode *vnode,
const char *name,
bool isdir,
bool async)
{
struct afs_call *call;
size_t namesz, reqsz, padsz;
__be32 *bp;
_enter("");
namesz = strlen(name);
padsz = (4 - (namesz & 3)) & 3;
reqsz = (5 * 4) + namesz + padsz;
call = afs_alloc_flat_call(&afs_RXFSRemoveXXXX, reqsz, (21 + 6) * 4);
if (!call)
return -ENOMEM;
call->key = key;
call->reply = vnode;
call->service_id = FS_SERVICE;
call->port = htons(AFS_FS_PORT);
bp = call->request;
*bp++ = htonl(isdir ? FSREMOVEDIR : FSREMOVEFILE);
*bp++ = htonl(vnode->fid.vid);
*bp++ = htonl(vnode->fid.vnode);
*bp++ = htonl(vnode->fid.unique);
*bp++ = htonl(namesz);
memcpy(bp, name, namesz);
bp = (void *) bp + namesz;
if (padsz > 0) {
memset(bp, 0, padsz);
bp = (void *) bp + padsz;
}
return afs_make_call(&server->addr, call, GFP_NOFS, async);
}
static int afs_deliver_fs_link(struct afs_call *call)
{
struct afs_vnode *dvnode = call->reply, *vnode = call->reply2;
const __be32 *bp;
int ret;
_enter("{%u}", call->unmarshall);
ret = afs_transfer_reply(call);
if (ret < 0)
return ret;
bp = call->buffer;
xdr_decode_AFSFetchStatus(&bp, &vnode->status, vnode, NULL);
xdr_decode_AFSFetchStatus(&bp, &dvnode->status, dvnode, NULL);
_leave(" = 0 [done]");
return 0;
}
int afs_fs_link(struct afs_server *server,
struct key *key,
struct afs_vnode *dvnode,
struct afs_vnode *vnode,
const char *name,
bool async)
{
struct afs_call *call;
size_t namesz, reqsz, padsz;
__be32 *bp;
_enter("");
namesz = strlen(name);
padsz = (4 - (namesz & 3)) & 3;
reqsz = (5 * 4) + namesz + padsz + (3 * 4);
call = afs_alloc_flat_call(&afs_RXFSLink, reqsz, (21 + 21 + 6) * 4);
if (!call)
return -ENOMEM;
call->key = key;
call->reply = dvnode;
call->reply2 = vnode;
call->service_id = FS_SERVICE;
call->port = htons(AFS_FS_PORT);
bp = call->request;
*bp++ = htonl(FSLINK);
*bp++ = htonl(dvnode->fid.vid);
*bp++ = htonl(dvnode->fid.vnode);
*bp++ = htonl(dvnode->fid.unique);
*bp++ = htonl(namesz);
memcpy(bp, name, namesz);
bp = (void *) bp + namesz;
if (padsz > 0) {
memset(bp, 0, padsz);
bp = (void *) bp + padsz;
}
*bp++ = htonl(vnode->fid.vid);
*bp++ = htonl(vnode->fid.vnode);
*bp++ = htonl(vnode->fid.unique);
return afs_make_call(&server->addr, call, GFP_NOFS, async);
}
static int afs_deliver_fs_symlink(struct afs_call *call)
{
struct afs_vnode *vnode = call->reply;
const __be32 *bp;
int ret;
_enter("{%u}", call->unmarshall);
ret = afs_transfer_reply(call);
if (ret < 0)
return ret;
bp = call->buffer;
xdr_decode_AFSFid(&bp, call->reply2);
xdr_decode_AFSFetchStatus(&bp, call->reply3, NULL, NULL);
xdr_decode_AFSFetchStatus(&bp, &vnode->status, vnode, NULL);
_leave(" = 0 [done]");
return 0;
}
int afs_fs_symlink(struct afs_server *server,
struct key *key,
struct afs_vnode *vnode,
const char *name,
const char *contents,
struct afs_fid *newfid,
struct afs_file_status *newstatus,
bool async)
{
struct afs_call *call;
size_t namesz, reqsz, padsz, c_namesz, c_padsz;
__be32 *bp;
_enter("");
namesz = strlen(name);
padsz = (4 - (namesz & 3)) & 3;
c_namesz = strlen(contents);
c_padsz = (4 - (c_namesz & 3)) & 3;
reqsz = (6 * 4) + namesz + padsz + c_namesz + c_padsz + (6 * 4);
call = afs_alloc_flat_call(&afs_RXFSSymlink, reqsz,
(3 + 21 + 21 + 6) * 4);
if (!call)
return -ENOMEM;
call->key = key;
call->reply = vnode;
call->reply2 = newfid;
call->reply3 = newstatus;
call->service_id = FS_SERVICE;
call->port = htons(AFS_FS_PORT);
bp = call->request;
*bp++ = htonl(FSSYMLINK);
*bp++ = htonl(vnode->fid.vid);
*bp++ = htonl(vnode->fid.vnode);
*bp++ = htonl(vnode->fid.unique);
*bp++ = htonl(namesz);
memcpy(bp, name, namesz);
bp = (void *) bp + namesz;
if (padsz > 0) {
memset(bp, 0, padsz);
bp = (void *) bp + padsz;
}
*bp++ = htonl(c_namesz);
memcpy(bp, contents, c_namesz);
bp = (void *) bp + c_namesz;
if (c_padsz > 0) {
memset(bp, 0, c_padsz);
bp = (void *) bp + c_padsz;
}
*bp++ = htonl(AFS_SET_MODE | AFS_SET_MTIME);
*bp++ = htonl(vnode->vfs_inode.i_mtime.tv_sec);
*bp++ = 0;
*bp++ = 0;
*bp++ = htonl(S_IRWXUGO);
*bp++ = 0;
return afs_make_call(&server->addr, call, GFP_NOFS, async);
}
static int afs_deliver_fs_rename(struct afs_call *call)
{
struct afs_vnode *orig_dvnode = call->reply, *new_dvnode = call->reply2;
const __be32 *bp;
int ret;
_enter("{%u}", call->unmarshall);
ret = afs_transfer_reply(call);
if (ret < 0)
return ret;
bp = call->buffer;
xdr_decode_AFSFetchStatus(&bp, &orig_dvnode->status, orig_dvnode, NULL);
if (new_dvnode != orig_dvnode)
xdr_decode_AFSFetchStatus(&bp, &new_dvnode->status, new_dvnode,
NULL);
_leave(" = 0 [done]");
return 0;
}
int afs_fs_rename(struct afs_server *server,
struct key *key,
struct afs_vnode *orig_dvnode,
const char *orig_name,
struct afs_vnode *new_dvnode,
const char *new_name,
bool async)
{
struct afs_call *call;
size_t reqsz, o_namesz, o_padsz, n_namesz, n_padsz;
__be32 *bp;
_enter("");
o_namesz = strlen(orig_name);
o_padsz = (4 - (o_namesz & 3)) & 3;
n_namesz = strlen(new_name);
n_padsz = (4 - (n_namesz & 3)) & 3;
reqsz = (4 * 4) +
4 + o_namesz + o_padsz +
(3 * 4) +
4 + n_namesz + n_padsz;
call = afs_alloc_flat_call(&afs_RXFSRename, reqsz, (21 + 21 + 6) * 4);
if (!call)
return -ENOMEM;
call->key = key;
call->reply = orig_dvnode;
call->reply2 = new_dvnode;
call->service_id = FS_SERVICE;
call->port = htons(AFS_FS_PORT);
bp = call->request;
*bp++ = htonl(FSRENAME);
*bp++ = htonl(orig_dvnode->fid.vid);
*bp++ = htonl(orig_dvnode->fid.vnode);
*bp++ = htonl(orig_dvnode->fid.unique);
*bp++ = htonl(o_namesz);
memcpy(bp, orig_name, o_namesz);
bp = (void *) bp + o_namesz;
if (o_padsz > 0) {
memset(bp, 0, o_padsz);
bp = (void *) bp + o_padsz;
}
*bp++ = htonl(new_dvnode->fid.vid);
*bp++ = htonl(new_dvnode->fid.vnode);
*bp++ = htonl(new_dvnode->fid.unique);
*bp++ = htonl(n_namesz);
memcpy(bp, new_name, n_namesz);
bp = (void *) bp + n_namesz;
if (n_padsz > 0) {
memset(bp, 0, n_padsz);
bp = (void *) bp + n_padsz;
}
return afs_make_call(&server->addr, call, GFP_NOFS, async);
}
static int afs_deliver_fs_store_data(struct afs_call *call)
{
struct afs_vnode *vnode = call->reply;
const __be32 *bp;
int ret;
_enter("");
ret = afs_transfer_reply(call);
if (ret < 0)
return ret;
bp = call->buffer;
xdr_decode_AFSFetchStatus(&bp, &vnode->status, vnode,
&call->store_version);
afs_pages_written_back(vnode, call);
_leave(" = 0 [done]");
return 0;
}
static int afs_fs_store_data64(struct afs_server *server,
struct afs_writeback *wb,
pgoff_t first, pgoff_t last,
unsigned offset, unsigned to,
loff_t size, loff_t pos, loff_t i_size,
bool async)
{
struct afs_vnode *vnode = wb->vnode;
struct afs_call *call;
__be32 *bp;
_enter(",%x,{%x:%u},,",
key_serial(wb->key), vnode->fid.vid, vnode->fid.vnode);
call = afs_alloc_flat_call(&afs_RXFSStoreData64,
(4 + 6 + 3 * 2) * 4,
(21 + 6) * 4);
if (!call)
return -ENOMEM;
call->wb = wb;
call->key = wb->key;
call->reply = vnode;
call->service_id = FS_SERVICE;
call->port = htons(AFS_FS_PORT);
call->mapping = vnode->vfs_inode.i_mapping;
call->first = first;
call->last = last;
call->first_offset = offset;
call->last_to = to;
call->send_pages = true;
call->store_version = vnode->status.data_version + 1;
bp = call->request;
*bp++ = htonl(FSSTOREDATA64);
*bp++ = htonl(vnode->fid.vid);
*bp++ = htonl(vnode->fid.vnode);
*bp++ = htonl(vnode->fid.unique);
*bp++ = htonl(AFS_SET_MTIME);
*bp++ = htonl(vnode->vfs_inode.i_mtime.tv_sec);
*bp++ = 0;
*bp++ = 0;
*bp++ = 0;
*bp++ = 0;
*bp++ = htonl(pos >> 32);
*bp++ = htonl((u32) pos);
*bp++ = htonl(size >> 32);
*bp++ = htonl((u32) size);
*bp++ = htonl(i_size >> 32);
*bp++ = htonl((u32) i_size);
return afs_make_call(&server->addr, call, GFP_NOFS, async);
}
int afs_fs_store_data(struct afs_server *server, struct afs_writeback *wb,
pgoff_t first, pgoff_t last,
unsigned offset, unsigned to,
bool async)
{
struct afs_vnode *vnode = wb->vnode;
struct afs_call *call;
loff_t size, pos, i_size;
__be32 *bp;
_enter(",%x,{%x:%u},,",
key_serial(wb->key), vnode->fid.vid, vnode->fid.vnode);
size = (loff_t)to - (loff_t)offset;
if (first != last)
size += (loff_t)(last - first) << PAGE_SHIFT;
pos = (loff_t)first << PAGE_SHIFT;
pos += offset;
i_size = i_size_read(&vnode->vfs_inode);
if (pos + size > i_size)
i_size = size + pos;
_debug("size %llx, at %llx, i_size %llx",
(unsigned long long) size, (unsigned long long) pos,
(unsigned long long) i_size);
if (pos >> 32 || i_size >> 32 || size >> 32 || (pos + size) >> 32)
return afs_fs_store_data64(server, wb, first, last, offset, to,
size, pos, i_size, async);
call = afs_alloc_flat_call(&afs_RXFSStoreData,
(4 + 6 + 3) * 4,
(21 + 6) * 4);
if (!call)
return -ENOMEM;
call->wb = wb;
call->key = wb->key;
call->reply = vnode;
call->service_id = FS_SERVICE;
call->port = htons(AFS_FS_PORT);
call->mapping = vnode->vfs_inode.i_mapping;
call->first = first;
call->last = last;
call->first_offset = offset;
call->last_to = to;
call->send_pages = true;
call->store_version = vnode->status.data_version + 1;
bp = call->request;
*bp++ = htonl(FSSTOREDATA);
*bp++ = htonl(vnode->fid.vid);
*bp++ = htonl(vnode->fid.vnode);
*bp++ = htonl(vnode->fid.unique);
*bp++ = htonl(AFS_SET_MTIME);
*bp++ = htonl(vnode->vfs_inode.i_mtime.tv_sec);
*bp++ = 0;
*bp++ = 0;
*bp++ = 0;
*bp++ = 0;
*bp++ = htonl(pos);
*bp++ = htonl(size);
*bp++ = htonl(i_size);
return afs_make_call(&server->addr, call, GFP_NOFS, async);
}
static int afs_deliver_fs_store_status(struct afs_call *call)
{
afs_dataversion_t *store_version;
struct afs_vnode *vnode = call->reply;
const __be32 *bp;
int ret;
_enter("");
ret = afs_transfer_reply(call);
if (ret < 0)
return ret;
store_version = NULL;
if (call->operation_ID == FSSTOREDATA)
store_version = &call->store_version;
bp = call->buffer;
xdr_decode_AFSFetchStatus(&bp, &vnode->status, vnode, store_version);
_leave(" = 0 [done]");
return 0;
}
static int afs_fs_setattr_size64(struct afs_server *server, struct key *key,
struct afs_vnode *vnode, struct iattr *attr,
bool async)
{
struct afs_call *call;
__be32 *bp;
_enter(",%x,{%x:%u},,",
key_serial(key), vnode->fid.vid, vnode->fid.vnode);
ASSERT(attr->ia_valid & ATTR_SIZE);
call = afs_alloc_flat_call(&afs_RXFSStoreData64_as_Status,
(4 + 6 + 3 * 2) * 4,
(21 + 6) * 4);
if (!call)
return -ENOMEM;
call->key = key;
call->reply = vnode;
call->service_id = FS_SERVICE;
call->port = htons(AFS_FS_PORT);
call->store_version = vnode->status.data_version + 1;
call->operation_ID = FSSTOREDATA;
bp = call->request;
*bp++ = htonl(FSSTOREDATA64);
*bp++ = htonl(vnode->fid.vid);
*bp++ = htonl(vnode->fid.vnode);
*bp++ = htonl(vnode->fid.unique);
xdr_encode_AFS_StoreStatus(&bp, attr);
*bp++ = 0;
*bp++ = 0;
*bp++ = 0;
*bp++ = 0;
*bp++ = htonl(attr->ia_size >> 32);
*bp++ = htonl((u32) attr->ia_size);
return afs_make_call(&server->addr, call, GFP_NOFS, async);
}
static int afs_fs_setattr_size(struct afs_server *server, struct key *key,
struct afs_vnode *vnode, struct iattr *attr,
bool async)
{
struct afs_call *call;
__be32 *bp;
_enter(",%x,{%x:%u},,",
key_serial(key), vnode->fid.vid, vnode->fid.vnode);
ASSERT(attr->ia_valid & ATTR_SIZE);
if (attr->ia_size >> 32)
return afs_fs_setattr_size64(server, key, vnode, attr,
async);
call = afs_alloc_flat_call(&afs_RXFSStoreData_as_Status,
(4 + 6 + 3) * 4,
(21 + 6) * 4);
if (!call)
return -ENOMEM;
call->key = key;
call->reply = vnode;
call->service_id = FS_SERVICE;
call->port = htons(AFS_FS_PORT);
call->store_version = vnode->status.data_version + 1;
call->operation_ID = FSSTOREDATA;
bp = call->request;
*bp++ = htonl(FSSTOREDATA);
*bp++ = htonl(vnode->fid.vid);
*bp++ = htonl(vnode->fid.vnode);
*bp++ = htonl(vnode->fid.unique);
xdr_encode_AFS_StoreStatus(&bp, attr);
*bp++ = 0;
*bp++ = 0;
*bp++ = htonl(attr->ia_size);
return afs_make_call(&server->addr, call, GFP_NOFS, async);
}
int afs_fs_setattr(struct afs_server *server, struct key *key,
struct afs_vnode *vnode, struct iattr *attr,
bool async)
{
struct afs_call *call;
__be32 *bp;
if (attr->ia_valid & ATTR_SIZE)
return afs_fs_setattr_size(server, key, vnode, attr,
async);
_enter(",%x,{%x:%u},,",
key_serial(key), vnode->fid.vid, vnode->fid.vnode);
call = afs_alloc_flat_call(&afs_RXFSStoreStatus,
(4 + 6) * 4,
(21 + 6) * 4);
if (!call)
return -ENOMEM;
call->key = key;
call->reply = vnode;
call->service_id = FS_SERVICE;
call->port = htons(AFS_FS_PORT);
call->operation_ID = FSSTORESTATUS;
bp = call->request;
*bp++ = htonl(FSSTORESTATUS);
*bp++ = htonl(vnode->fid.vid);
*bp++ = htonl(vnode->fid.vnode);
*bp++ = htonl(vnode->fid.unique);
xdr_encode_AFS_StoreStatus(&bp, attr);
return afs_make_call(&server->addr, call, GFP_NOFS, async);
}
static int afs_deliver_fs_get_volume_status(struct afs_call *call)
{
const __be32 *bp;
char *p;
int ret;
_enter("{%u}", call->unmarshall);
switch (call->unmarshall) {
case 0:
call->offset = 0;
call->unmarshall++;
case 1:
_debug("extract status");
ret = afs_extract_data(call, call->buffer,
12 * 4, true);
if (ret < 0)
return ret;
bp = call->buffer;
xdr_decode_AFSFetchVolumeStatus(&bp, call->reply2);
call->offset = 0;
call->unmarshall++;
case 2:
ret = afs_extract_data(call, &call->tmp, 4, true);
if (ret < 0)
return ret;
call->count = ntohl(call->tmp);
_debug("volname length: %u", call->count);
if (call->count >= AFSNAMEMAX)
return -EBADMSG;
call->offset = 0;
call->unmarshall++;
case 3:
_debug("extract volname");
if (call->count > 0) {
ret = afs_extract_data(call, call->reply3,
call->count, true);
if (ret < 0)
return ret;
}
p = call->reply3;
p[call->count] = 0;
_debug("volname '%s'", p);
call->offset = 0;
call->unmarshall++;
if ((call->count & 3) == 0) {
call->unmarshall++;
goto no_volname_padding;
}
call->count = 4 - (call->count & 3);
case 4:
ret = afs_extract_data(call, call->buffer,
call->count, true);
if (ret < 0)
return ret;
call->offset = 0;
call->unmarshall++;
no_volname_padding:
case 5:
ret = afs_extract_data(call, &call->tmp, 4, true);
if (ret < 0)
return ret;
call->count = ntohl(call->tmp);
_debug("offline msg length: %u", call->count);
if (call->count >= AFSNAMEMAX)
return -EBADMSG;
call->offset = 0;
call->unmarshall++;
case 6:
_debug("extract offline");
if (call->count > 0) {
ret = afs_extract_data(call, call->reply3,
call->count, true);
if (ret < 0)
return ret;
}
p = call->reply3;
p[call->count] = 0;
_debug("offline '%s'", p);
call->offset = 0;
call->unmarshall++;
if ((call->count & 3) == 0) {
call->unmarshall++;
goto no_offline_padding;
}
call->count = 4 - (call->count & 3);
case 7:
ret = afs_extract_data(call, call->buffer,
call->count, true);
if (ret < 0)
return ret;
call->offset = 0;
call->unmarshall++;
no_offline_padding:
case 8:
ret = afs_extract_data(call, &call->tmp, 4, true);
if (ret < 0)
return ret;
call->count = ntohl(call->tmp);
_debug("motd length: %u", call->count);
if (call->count >= AFSNAMEMAX)
return -EBADMSG;
call->offset = 0;
call->unmarshall++;
case 9:
_debug("extract motd");
if (call->count > 0) {
ret = afs_extract_data(call, call->reply3,
call->count, true);
if (ret < 0)
return ret;
}
p = call->reply3;
p[call->count] = 0;
_debug("motd '%s'", p);
call->offset = 0;
call->unmarshall++;
call->count = (4 - (call->count & 3)) & 3;
case 10:
ret = afs_extract_data(call, call->buffer,
call->count, false);
if (ret < 0)
return ret;
call->offset = 0;
call->unmarshall++;
case 11:
break;
}
_leave(" = 0 [done]");
return 0;
}
static void afs_get_volume_status_call_destructor(struct afs_call *call)
{
kfree(call->reply3);
call->reply3 = NULL;
afs_flat_call_destructor(call);
}
int afs_fs_get_volume_status(struct afs_server *server,
struct key *key,
struct afs_vnode *vnode,
struct afs_volume_status *vs,
bool async)
{
struct afs_call *call;
__be32 *bp;
void *tmpbuf;
_enter("");
tmpbuf = kmalloc(AFSOPAQUEMAX, GFP_KERNEL);
if (!tmpbuf)
return -ENOMEM;
call = afs_alloc_flat_call(&afs_RXFSGetVolumeStatus, 2 * 4, 12 * 4);
if (!call) {
kfree(tmpbuf);
return -ENOMEM;
}
call->key = key;
call->reply = vnode;
call->reply2 = vs;
call->reply3 = tmpbuf;
call->service_id = FS_SERVICE;
call->port = htons(AFS_FS_PORT);
bp = call->request;
bp[0] = htonl(FSGETVOLUMESTATUS);
bp[1] = htonl(vnode->fid.vid);
return afs_make_call(&server->addr, call, GFP_NOFS, async);
}
static int afs_deliver_fs_xxxx_lock(struct afs_call *call)
{
const __be32 *bp;
int ret;
_enter("{%u}", call->unmarshall);
ret = afs_transfer_reply(call);
if (ret < 0)
return ret;
bp = call->buffer;
_leave(" = 0 [done]");
return 0;
}
int afs_fs_set_lock(struct afs_server *server,
struct key *key,
struct afs_vnode *vnode,
afs_lock_type_t type,
bool async)
{
struct afs_call *call;
__be32 *bp;
_enter("");
call = afs_alloc_flat_call(&afs_RXFSSetLock, 5 * 4, 6 * 4);
if (!call)
return -ENOMEM;
call->key = key;
call->reply = vnode;
call->service_id = FS_SERVICE;
call->port = htons(AFS_FS_PORT);
bp = call->request;
*bp++ = htonl(FSSETLOCK);
*bp++ = htonl(vnode->fid.vid);
*bp++ = htonl(vnode->fid.vnode);
*bp++ = htonl(vnode->fid.unique);
*bp++ = htonl(type);
return afs_make_call(&server->addr, call, GFP_NOFS, async);
}
int afs_fs_extend_lock(struct afs_server *server,
struct key *key,
struct afs_vnode *vnode,
bool async)
{
struct afs_call *call;
__be32 *bp;
_enter("");
call = afs_alloc_flat_call(&afs_RXFSExtendLock, 4 * 4, 6 * 4);
if (!call)
return -ENOMEM;
call->key = key;
call->reply = vnode;
call->service_id = FS_SERVICE;
call->port = htons(AFS_FS_PORT);
bp = call->request;
*bp++ = htonl(FSEXTENDLOCK);
*bp++ = htonl(vnode->fid.vid);
*bp++ = htonl(vnode->fid.vnode);
*bp++ = htonl(vnode->fid.unique);
return afs_make_call(&server->addr, call, GFP_NOFS, async);
}
int afs_fs_release_lock(struct afs_server *server,
struct key *key,
struct afs_vnode *vnode,
bool async)
{
struct afs_call *call;
__be32 *bp;
_enter("");
call = afs_alloc_flat_call(&afs_RXFSReleaseLock, 4 * 4, 6 * 4);
if (!call)
return -ENOMEM;
call->key = key;
call->reply = vnode;
call->service_id = FS_SERVICE;
call->port = htons(AFS_FS_PORT);
bp = call->request;
*bp++ = htonl(FSRELEASELOCK);
*bp++ = htonl(vnode->fid.vid);
*bp++ = htonl(vnode->fid.vnode);
*bp++ = htonl(vnode->fid.unique);
return afs_make_call(&server->addr, call, GFP_NOFS, async);
}
