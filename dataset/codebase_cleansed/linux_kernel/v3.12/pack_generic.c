static inline int lustre_msg_hdr_size_v2(int count)
{
return cfs_size_round(offsetof(struct lustre_msg_v2,
lm_buflens[count]));
}
int lustre_msg_hdr_size(__u32 magic, int count)
{
switch (magic) {
case LUSTRE_MSG_MAGIC_V2:
return lustre_msg_hdr_size_v2(count);
default:
LASSERTF(0, "incorrect message magic: %08x\n", magic);
return -EINVAL;
}
}
void ptlrpc_buf_set_swabbed(struct ptlrpc_request *req, const int inout,
int index)
{
if (inout)
lustre_set_req_swabbed(req, index);
else
lustre_set_rep_swabbed(req, index);
}
int ptlrpc_buf_need_swab(struct ptlrpc_request *req, const int inout,
int index)
{
if (inout)
return (ptlrpc_req_need_swab(req) &&
!lustre_req_swabbed(req, index));
else
return (ptlrpc_rep_need_swab(req) &&
!lustre_rep_swabbed(req, index));
}
static inline int lustre_msg_check_version_v2(struct lustre_msg_v2 *msg,
__u32 version)
{
__u32 ver = lustre_msg_get_version(msg);
return (ver & LUSTRE_VERSION_MASK) != version;
}
int lustre_msg_check_version(struct lustre_msg *msg, __u32 version)
{
switch (msg->lm_magic) {
case LUSTRE_MSG_MAGIC_V1:
CERROR("msg v1 not supported - please upgrade you system\n");
return -EINVAL;
case LUSTRE_MSG_MAGIC_V2:
return lustre_msg_check_version_v2(msg, version);
default:
CERROR("incorrect message magic: %08x\n", msg->lm_magic);
return 0;
}
}
int lustre_msg_early_size(void)
{
static int size = 0;
if (!size) {
__u32 pblen = sizeof(struct ptlrpc_body_v2);
size = lustre_msg_size(LUSTRE_MSG_MAGIC_V2, 1, &pblen);
}
return size;
}
int lustre_msg_size_v2(int count, __u32 *lengths)
{
int size;
int i;
size = lustre_msg_hdr_size_v2(count);
for (i = 0; i < count; i++)
size += cfs_size_round(lengths[i]);
return size;
}
int lustre_msg_size(__u32 magic, int count, __u32 *lens)
{
__u32 size[] = { sizeof(struct ptlrpc_body) };
if (!lens) {
LASSERT(count == 1);
lens = size;
}
LASSERT(count > 0);
LASSERT(lens[MSG_PTLRPC_BODY_OFF] >= sizeof(struct ptlrpc_body_v2));
switch (magic) {
case LUSTRE_MSG_MAGIC_V2:
return lustre_msg_size_v2(count, lens);
default:
LASSERTF(0, "incorrect message magic: %08x\n", magic);
return -EINVAL;
}
}
int lustre_packed_msg_size(struct lustre_msg *msg)
{
switch (msg->lm_magic) {
case LUSTRE_MSG_MAGIC_V2:
return lustre_msg_size_v2(msg->lm_bufcount, msg->lm_buflens);
default:
CERROR("incorrect message magic: %08x\n", msg->lm_magic);
return 0;
}
}
void lustre_init_msg_v2(struct lustre_msg_v2 *msg, int count, __u32 *lens,
char **bufs)
{
char *ptr;
int i;
msg->lm_bufcount = count;
msg->lm_magic = LUSTRE_MSG_MAGIC_V2;
for (i = 0; i < count; i++)
msg->lm_buflens[i] = lens[i];
if (bufs == NULL)
return;
ptr = (char *)msg + lustre_msg_hdr_size_v2(count);
for (i = 0; i < count; i++) {
char *tmp = bufs[i];
LOGL(tmp, lens[i], ptr);
}
}
static int lustre_pack_request_v2(struct ptlrpc_request *req,
int count, __u32 *lens, char **bufs)
{
int reqlen, rc;
reqlen = lustre_msg_size_v2(count, lens);
rc = sptlrpc_cli_alloc_reqbuf(req, reqlen);
if (rc)
return rc;
req->rq_reqlen = reqlen;
lustre_init_msg_v2(req->rq_reqmsg, count, lens, bufs);
lustre_msg_add_version(req->rq_reqmsg, PTLRPC_MSG_VERSION);
return 0;
}
int lustre_pack_request(struct ptlrpc_request *req, __u32 magic, int count,
__u32 *lens, char **bufs)
{
__u32 size[] = { sizeof(struct ptlrpc_body) };
if (!lens) {
LASSERT(count == 1);
lens = size;
}
LASSERT(count > 0);
LASSERT(lens[MSG_PTLRPC_BODY_OFF] == sizeof(struct ptlrpc_body));
magic = LUSTRE_MSG_MAGIC_V2;
switch (magic) {
case LUSTRE_MSG_MAGIC_V2:
return lustre_pack_request_v2(req, count, lens, bufs);
default:
LASSERTF(0, "incorrect message magic: %08x\n", magic);
return -EINVAL;
}
}
struct ptlrpc_reply_state *
lustre_get_emerg_rs(struct ptlrpc_service_part *svcpt)
{
struct ptlrpc_reply_state *rs = NULL;
spin_lock(&svcpt->scp_rep_lock);
while (list_empty(&svcpt->scp_rep_idle)) {
struct l_wait_info lwi;
int rc;
spin_unlock(&svcpt->scp_rep_lock);
lwi = LWI_TIMEOUT(cfs_time_seconds(10), NULL, NULL);
rc = l_wait_event(svcpt->scp_rep_waitq,
!list_empty(&svcpt->scp_rep_idle), &lwi);
if (rc != 0)
goto out;
spin_lock(&svcpt->scp_rep_lock);
}
rs = list_entry(svcpt->scp_rep_idle.next,
struct ptlrpc_reply_state, rs_list);
list_del(&rs->rs_list);
spin_unlock(&svcpt->scp_rep_lock);
memset(rs, 0, svcpt->scp_service->srv_max_reply_size);
rs->rs_svcpt = svcpt;
rs->rs_prealloc = 1;
out:
return rs;
}
void lustre_put_emerg_rs(struct ptlrpc_reply_state *rs)
{
struct ptlrpc_service_part *svcpt = rs->rs_svcpt;
spin_lock(&svcpt->scp_rep_lock);
list_add(&rs->rs_list, &svcpt->scp_rep_idle);
spin_unlock(&svcpt->scp_rep_lock);
wake_up(&svcpt->scp_rep_waitq);
}
int lustre_pack_reply_v2(struct ptlrpc_request *req, int count,
__u32 *lens, char **bufs, int flags)
{
struct ptlrpc_reply_state *rs;
int msg_len, rc;
LASSERT(req->rq_reply_state == NULL);
if ((flags & LPRFL_EARLY_REPLY) == 0) {
spin_lock(&req->rq_lock);
req->rq_packed_final = 1;
spin_unlock(&req->rq_lock);
}
msg_len = lustre_msg_size_v2(count, lens);
rc = sptlrpc_svc_alloc_rs(req, msg_len);
if (rc)
return rc;
rs = req->rq_reply_state;
atomic_set(&rs->rs_refcount, 1);
rs->rs_cb_id.cbid_fn = reply_out_callback;
rs->rs_cb_id.cbid_arg = rs;
rs->rs_svcpt = req->rq_rqbd->rqbd_svcpt;
INIT_LIST_HEAD(&rs->rs_exp_list);
INIT_LIST_HEAD(&rs->rs_obd_list);
INIT_LIST_HEAD(&rs->rs_list);
spin_lock_init(&rs->rs_lock);
req->rq_replen = msg_len;
req->rq_reply_state = rs;
req->rq_repmsg = rs->rs_msg;
lustre_init_msg_v2(rs->rs_msg, count, lens, bufs);
lustre_msg_add_version(rs->rs_msg, PTLRPC_MSG_VERSION);
PTLRPC_RS_DEBUG_LRU_ADD(rs);
return 0;
}
int lustre_pack_reply_flags(struct ptlrpc_request *req, int count, __u32 *lens,
char **bufs, int flags)
{
int rc = 0;
__u32 size[] = { sizeof(struct ptlrpc_body) };
if (!lens) {
LASSERT(count == 1);
lens = size;
}
LASSERT(count > 0);
LASSERT(lens[MSG_PTLRPC_BODY_OFF] == sizeof(struct ptlrpc_body));
switch (req->rq_reqmsg->lm_magic) {
case LUSTRE_MSG_MAGIC_V2:
rc = lustre_pack_reply_v2(req, count, lens, bufs, flags);
break;
default:
LASSERTF(0, "incorrect message magic: %08x\n",
req->rq_reqmsg->lm_magic);
rc = -EINVAL;
}
if (rc != 0)
CERROR("lustre_pack_reply failed: rc=%d size=%d\n", rc,
lustre_msg_size(req->rq_reqmsg->lm_magic, count, lens));
return rc;
}
int lustre_pack_reply(struct ptlrpc_request *req, int count, __u32 *lens,
char **bufs)
{
return lustre_pack_reply_flags(req, count, lens, bufs, 0);
}
void *lustre_msg_buf_v2(struct lustre_msg_v2 *m, int n, int min_size)
{
int i, offset, buflen, bufcount;
LASSERT(m != NULL);
LASSERT(n >= 0);
bufcount = m->lm_bufcount;
if (unlikely(n >= bufcount)) {
CDEBUG(D_INFO, "msg %p buffer[%d] not present (count %d)\n",
m, n, bufcount);
return NULL;
}
buflen = m->lm_buflens[n];
if (unlikely(buflen < min_size)) {
CERROR("msg %p buffer[%d] size %d too small "
"(required %d, opc=%d)\n", m, n, buflen, min_size,
n == MSG_PTLRPC_BODY_OFF ? -1 : lustre_msg_get_opc(m));
return NULL;
}
offset = lustre_msg_hdr_size_v2(bufcount);
for (i = 0; i < n; i++)
offset += cfs_size_round(m->lm_buflens[i]);
return (char *)m + offset;
}
void *lustre_msg_buf(struct lustre_msg *m, int n, int min_size)
{
switch (m->lm_magic) {
case LUSTRE_MSG_MAGIC_V2:
return lustre_msg_buf_v2(m, n, min_size);
default:
LASSERTF(0, "incorrect message magic: %08x(msg:%p)\n", m->lm_magic, m);
return NULL;
}
}
int lustre_shrink_msg_v2(struct lustre_msg_v2 *msg, int segment,
unsigned int newlen, int move_data)
{
char *tail = NULL, *newpos;
int tail_len = 0, n;
LASSERT(msg);
LASSERT(msg->lm_bufcount > segment);
LASSERT(msg->lm_buflens[segment] >= newlen);
if (msg->lm_buflens[segment] == newlen)
goto out;
if (move_data && msg->lm_bufcount > segment + 1) {
tail = lustre_msg_buf_v2(msg, segment + 1, 0);
for (n = segment + 1; n < msg->lm_bufcount; n++)
tail_len += cfs_size_round(msg->lm_buflens[n]);
}
msg->lm_buflens[segment] = newlen;
if (tail && tail_len) {
newpos = lustre_msg_buf_v2(msg, segment + 1, 0);
LASSERT(newpos <= tail);
if (newpos != tail)
memmove(newpos, tail, tail_len);
}
out:
return lustre_msg_size_v2(msg->lm_bufcount, msg->lm_buflens);
}
int lustre_shrink_msg(struct lustre_msg *msg, int segment,
unsigned int newlen, int move_data)
{
switch (msg->lm_magic) {
case LUSTRE_MSG_MAGIC_V2:
return lustre_shrink_msg_v2(msg, segment, newlen, move_data);
default:
LASSERTF(0, "incorrect message magic: %08x\n", msg->lm_magic);
}
}
void lustre_free_reply_state(struct ptlrpc_reply_state *rs)
{
PTLRPC_RS_DEBUG_LRU_DEL(rs);
LASSERT (atomic_read(&rs->rs_refcount) == 0);
LASSERT (!rs->rs_difficult || rs->rs_handled);
LASSERT (!rs->rs_on_net);
LASSERT (!rs->rs_scheduled);
LASSERT (rs->rs_export == NULL);
LASSERT (rs->rs_nlocks == 0);
LASSERT (list_empty(&rs->rs_exp_list));
LASSERT (list_empty(&rs->rs_obd_list));
sptlrpc_svc_free_rs(rs);
}
static int lustre_unpack_msg_v2(struct lustre_msg_v2 *m, int len)
{
int swabbed, required_len, i;
required_len = lustre_msg_hdr_size_v2(0);
if (len < required_len) {
CERROR("message length %d too small for lustre_msg\n", len);
return -EINVAL;
}
swabbed = (m->lm_magic == LUSTRE_MSG_MAGIC_V2_SWABBED);
if (swabbed) {
__swab32s(&m->lm_magic);
__swab32s(&m->lm_bufcount);
__swab32s(&m->lm_secflvr);
__swab32s(&m->lm_repsize);
__swab32s(&m->lm_cksum);
__swab32s(&m->lm_flags);
CLASSERT(offsetof(typeof(*m), lm_padding_2) != 0);
CLASSERT(offsetof(typeof(*m), lm_padding_3) != 0);
}
required_len = lustre_msg_hdr_size_v2(m->lm_bufcount);
if (len < required_len) {
CERROR ("message length %d too small for %d buflens\n",
len, m->lm_bufcount);
return -EINVAL;
}
for (i = 0; i < m->lm_bufcount; i++) {
if (swabbed)
__swab32s(&m->lm_buflens[i]);
required_len += cfs_size_round(m->lm_buflens[i]);
}
if (len < required_len) {
CERROR("len: %d, required_len %d\n", len, required_len);
CERROR("bufcount: %d\n", m->lm_bufcount);
for (i = 0; i < m->lm_bufcount; i++)
CERROR("buffer %d length %d\n", i, m->lm_buflens[i]);
return -EINVAL;
}
return swabbed;
}
int __lustre_unpack_msg(struct lustre_msg *m, int len)
{
int required_len, rc;
required_len = offsetof(struct lustre_msg, lm_magic) +
sizeof(m->lm_magic);
if (len < required_len) {
CERROR("message length %d too small for magic/version check\n",
len);
return -EINVAL;
}
rc = lustre_unpack_msg_v2(m, len);
return rc;
}
int ptlrpc_unpack_req_msg(struct ptlrpc_request *req, int len)
{
int rc;
rc = __lustre_unpack_msg(req->rq_reqmsg, len);
if (rc == 1) {
lustre_set_req_swabbed(req, MSG_PTLRPC_HEADER_OFF);
rc = 0;
}
return rc;
}
int ptlrpc_unpack_rep_msg(struct ptlrpc_request *req, int len)
{
int rc;
rc = __lustre_unpack_msg(req->rq_repmsg, len);
if (rc == 1) {
lustre_set_rep_swabbed(req, MSG_PTLRPC_HEADER_OFF);
rc = 0;
}
return rc;
}
static inline int lustre_unpack_ptlrpc_body_v2(struct ptlrpc_request *req,
const int inout, int offset)
{
struct ptlrpc_body *pb;
struct lustre_msg_v2 *m = inout ? req->rq_reqmsg : req->rq_repmsg;
pb = lustre_msg_buf_v2(m, offset, sizeof(struct ptlrpc_body_v2));
if (!pb) {
CERROR("error unpacking ptlrpc body\n");
return -EFAULT;
}
if (ptlrpc_buf_need_swab(req, inout, offset)) {
lustre_swab_ptlrpc_body(pb);
ptlrpc_buf_set_swabbed(req, inout, offset);
}
if ((pb->pb_version & ~LUSTRE_VERSION_MASK) != PTLRPC_MSG_VERSION) {
CERROR("wrong lustre_msg version %08x\n", pb->pb_version);
return -EINVAL;
}
if (!inout)
pb->pb_status = ptlrpc_status_ntoh(pb->pb_status);
return 0;
}
int lustre_unpack_req_ptlrpc_body(struct ptlrpc_request *req, int offset)
{
switch (req->rq_reqmsg->lm_magic) {
case LUSTRE_MSG_MAGIC_V2:
return lustre_unpack_ptlrpc_body_v2(req, 1, offset);
default:
CERROR("bad lustre msg magic: %08x\n",
req->rq_reqmsg->lm_magic);
return -EINVAL;
}
}
int lustre_unpack_rep_ptlrpc_body(struct ptlrpc_request *req, int offset)
{
switch (req->rq_repmsg->lm_magic) {
case LUSTRE_MSG_MAGIC_V2:
return lustre_unpack_ptlrpc_body_v2(req, 0, offset);
default:
CERROR("bad lustre msg magic: %08x\n",
req->rq_repmsg->lm_magic);
return -EINVAL;
}
}
static inline int lustre_msg_buflen_v2(struct lustre_msg_v2 *m, int n)
{
if (n >= m->lm_bufcount)
return 0;
return m->lm_buflens[n];
}
int lustre_msg_buflen(struct lustre_msg *m, int n)
{
switch (m->lm_magic) {
case LUSTRE_MSG_MAGIC_V2:
return lustre_msg_buflen_v2(m, n);
default:
CERROR("incorrect message magic: %08x\n", m->lm_magic);
return -EINVAL;
}
}
static inline void
lustre_msg_set_buflen_v2(struct lustre_msg_v2 *m, int n, int len)
{
if (n >= m->lm_bufcount)
LBUG();
m->lm_buflens[n] = len;
}
void lustre_msg_set_buflen(struct lustre_msg *m, int n, int len)
{
switch (m->lm_magic) {
case LUSTRE_MSG_MAGIC_V2:
lustre_msg_set_buflen_v2(m, n, len);
return;
default:
LASSERTF(0, "incorrect message magic: %08x\n", m->lm_magic);
}
}
int lustre_msg_bufcount(struct lustre_msg *m)
{
switch (m->lm_magic) {
case LUSTRE_MSG_MAGIC_V2:
return m->lm_bufcount;
default:
CERROR("incorrect message magic: %08x\n", m->lm_magic);
return -EINVAL;
}
}
char *lustre_msg_string(struct lustre_msg *m, int index, int max_len)
{
char *str;
int slen, blen;
switch (m->lm_magic) {
case LUSTRE_MSG_MAGIC_V2:
str = lustre_msg_buf_v2(m, index, 0);
blen = lustre_msg_buflen_v2(m, index);
break;
default:
LASSERTF(0, "incorrect message magic: %08x\n", m->lm_magic);
}
if (str == NULL) {
CERROR ("can't unpack string in msg %p buffer[%d]\n", m, index);
return NULL;
}
slen = strnlen(str, blen);
if (slen == blen) {
CERROR("can't unpack non-NULL terminated string in "
"msg %p buffer[%d] len %d\n", m, index, blen);
return NULL;
}
if (max_len == 0) {
if (slen != blen - 1) {
CERROR("can't unpack short string in msg %p "
"buffer[%d] len %d: strlen %d\n",
m, index, blen, slen);
return NULL;
}
} else if (slen > max_len) {
CERROR("can't unpack oversized string in msg %p "
"buffer[%d] len %d strlen %d: max %d expected\n",
m, index, blen, slen, max_len);
return NULL;
}
return str;
}
static inline void *__lustre_swab_buf(struct lustre_msg *msg, int index,
int min_size, void *swabber)
{
void *ptr = NULL;
LASSERT(msg != NULL);
switch (msg->lm_magic) {
case LUSTRE_MSG_MAGIC_V2:
ptr = lustre_msg_buf_v2(msg, index, min_size);
break;
default:
CERROR("incorrect message magic: %08x\n", msg->lm_magic);
}
if (ptr && swabber)
((void (*)(void *))swabber)(ptr);
return ptr;
}
static inline struct ptlrpc_body *lustre_msg_ptlrpc_body(struct lustre_msg *msg)
{
return lustre_msg_buf_v2(msg, MSG_PTLRPC_BODY_OFF,
sizeof(struct ptlrpc_body_v2));
}
__u32 lustre_msghdr_get_flags(struct lustre_msg *msg)
{
switch (msg->lm_magic) {
case LUSTRE_MSG_MAGIC_V1:
case LUSTRE_MSG_MAGIC_V1_SWABBED:
return 0;
case LUSTRE_MSG_MAGIC_V2:
return msg->lm_flags;
default:
LASSERTF(0, "incorrect message magic: %08x\n", msg->lm_magic);
return 0;
}
}
void lustre_msghdr_set_flags(struct lustre_msg *msg, __u32 flags)
{
switch (msg->lm_magic) {
case LUSTRE_MSG_MAGIC_V1:
return;
case LUSTRE_MSG_MAGIC_V2:
msg->lm_flags = flags;
return;
default:
LASSERTF(0, "incorrect message magic: %08x\n", msg->lm_magic);
}
}
__u32 lustre_msg_get_flags(struct lustre_msg *msg)
{
switch (msg->lm_magic) {
case LUSTRE_MSG_MAGIC_V2: {
struct ptlrpc_body *pb = lustre_msg_ptlrpc_body(msg);
if (!pb) {
CERROR("invalid msg %p: no ptlrpc body!\n", msg);
return 0;
}
return pb->pb_flags;
}
default:
return 0;
}
}
void lustre_msg_add_flags(struct lustre_msg *msg, int flags)
{
switch (msg->lm_magic) {
case LUSTRE_MSG_MAGIC_V2: {
struct ptlrpc_body *pb = lustre_msg_ptlrpc_body(msg);
LASSERTF(pb, "invalid msg %p: no ptlrpc body!\n", msg);
pb->pb_flags |= flags;
return;
}
default:
LASSERTF(0, "incorrect message magic: %08x\n", msg->lm_magic);
}
}
void lustre_msg_set_flags(struct lustre_msg *msg, int flags)
{
switch (msg->lm_magic) {
case LUSTRE_MSG_MAGIC_V2: {
struct ptlrpc_body *pb = lustre_msg_ptlrpc_body(msg);
LASSERTF(pb, "invalid msg %p: no ptlrpc body!\n", msg);
pb->pb_flags = flags;
return;
}
default:
LASSERTF(0, "incorrect message magic: %08x\n", msg->lm_magic);
}
}
void lustre_msg_clear_flags(struct lustre_msg *msg, int flags)
{
switch (msg->lm_magic) {
case LUSTRE_MSG_MAGIC_V2: {
struct ptlrpc_body *pb = lustre_msg_ptlrpc_body(msg);
LASSERTF(pb, "invalid msg %p: no ptlrpc body!\n", msg);
pb->pb_flags &= ~(MSG_GEN_FLAG_MASK & flags);
return;
}
default:
LASSERTF(0, "incorrect message magic: %08x\n", msg->lm_magic);
}
}
__u32 lustre_msg_get_op_flags(struct lustre_msg *msg)
{
switch (msg->lm_magic) {
case LUSTRE_MSG_MAGIC_V2: {
struct ptlrpc_body *pb = lustre_msg_ptlrpc_body(msg);
if (!pb) {
CERROR("invalid msg %p: no ptlrpc body!\n", msg);
return 0;
}
return pb->pb_op_flags;
}
default:
return 0;
}
}
void lustre_msg_add_op_flags(struct lustre_msg *msg, int flags)
{
switch (msg->lm_magic) {
case LUSTRE_MSG_MAGIC_V2: {
struct ptlrpc_body *pb = lustre_msg_ptlrpc_body(msg);
LASSERTF(pb, "invalid msg %p: no ptlrpc body!\n", msg);
pb->pb_op_flags |= flags;
return;
}
default:
LASSERTF(0, "incorrect message magic: %08x\n", msg->lm_magic);
}
}
void lustre_msg_set_op_flags(struct lustre_msg *msg, int flags)
{
switch (msg->lm_magic) {
case LUSTRE_MSG_MAGIC_V2: {
struct ptlrpc_body *pb = lustre_msg_ptlrpc_body(msg);
LASSERTF(pb, "invalid msg %p: no ptlrpc body!\n", msg);
pb->pb_op_flags |= flags;
return;
}
default:
LASSERTF(0, "incorrect message magic: %08x\n", msg->lm_magic);
}
}
struct lustre_handle *lustre_msg_get_handle(struct lustre_msg *msg)
{
switch (msg->lm_magic) {
case LUSTRE_MSG_MAGIC_V2: {
struct ptlrpc_body *pb = lustre_msg_ptlrpc_body(msg);
if (!pb) {
CERROR("invalid msg %p: no ptlrpc body!\n", msg);
return NULL;
}
return &pb->pb_handle;
}
default:
CERROR("incorrect message magic: %08x\n", msg->lm_magic);
return NULL;
}
}
__u32 lustre_msg_get_type(struct lustre_msg *msg)
{
switch (msg->lm_magic) {
case LUSTRE_MSG_MAGIC_V2: {
struct ptlrpc_body *pb = lustre_msg_ptlrpc_body(msg);
if (!pb) {
CERROR("invalid msg %p: no ptlrpc body!\n", msg);
return PTL_RPC_MSG_ERR;
}
return pb->pb_type;
}
default:
CERROR("incorrect message magic: %08x\n", msg->lm_magic);
return PTL_RPC_MSG_ERR;
}
}
__u32 lustre_msg_get_version(struct lustre_msg *msg)
{
switch (msg->lm_magic) {
case LUSTRE_MSG_MAGIC_V2: {
struct ptlrpc_body *pb = lustre_msg_ptlrpc_body(msg);
if (!pb) {
CERROR("invalid msg %p: no ptlrpc body!\n", msg);
return 0;
}
return pb->pb_version;
}
default:
CERROR("incorrect message magic: %08x\n", msg->lm_magic);
return 0;
}
}
void lustre_msg_add_version(struct lustre_msg *msg, int version)
{
switch (msg->lm_magic) {
case LUSTRE_MSG_MAGIC_V2: {
struct ptlrpc_body *pb = lustre_msg_ptlrpc_body(msg);
LASSERTF(pb, "invalid msg %p: no ptlrpc body!\n", msg);
pb->pb_version |= version;
return;
}
default:
LASSERTF(0, "incorrect message magic: %08x\n", msg->lm_magic);
}
}
__u32 lustre_msg_get_opc(struct lustre_msg *msg)
{
switch (msg->lm_magic) {
case LUSTRE_MSG_MAGIC_V2: {
struct ptlrpc_body *pb = lustre_msg_ptlrpc_body(msg);
if (!pb) {
CERROR("invalid msg %p: no ptlrpc body!\n", msg);
return 0;
}
return pb->pb_opc;
}
default:
CERROR("incorrect message magic: %08x(msg:%p)\n", msg->lm_magic, msg);
LBUG();
return 0;
}
}
__u64 lustre_msg_get_last_xid(struct lustre_msg *msg)
{
switch (msg->lm_magic) {
case LUSTRE_MSG_MAGIC_V2: {
struct ptlrpc_body *pb = lustre_msg_ptlrpc_body(msg);
if (!pb) {
CERROR("invalid msg %p: no ptlrpc body!\n", msg);
return 0;
}
return pb->pb_last_xid;
}
default:
CERROR("incorrect message magic: %08x\n", msg->lm_magic);
return 0;
}
}
__u64 lustre_msg_get_last_committed(struct lustre_msg *msg)
{
switch (msg->lm_magic) {
case LUSTRE_MSG_MAGIC_V2: {
struct ptlrpc_body *pb = lustre_msg_ptlrpc_body(msg);
if (!pb) {
CERROR("invalid msg %p: no ptlrpc body!\n", msg);
return 0;
}
return pb->pb_last_committed;
}
default:
CERROR("incorrect message magic: %08x\n", msg->lm_magic);
return 0;
}
}
__u64 *lustre_msg_get_versions(struct lustre_msg *msg)
{
switch (msg->lm_magic) {
case LUSTRE_MSG_MAGIC_V1:
return NULL;
case LUSTRE_MSG_MAGIC_V2: {
struct ptlrpc_body *pb = lustre_msg_ptlrpc_body(msg);
if (!pb) {
CERROR("invalid msg %p: no ptlrpc body!\n", msg);
return NULL;
}
return pb->pb_pre_versions;
}
default:
CERROR("incorrect message magic: %08x\n", msg->lm_magic);
return NULL;
}
}
__u64 lustre_msg_get_transno(struct lustre_msg *msg)
{
switch (msg->lm_magic) {
case LUSTRE_MSG_MAGIC_V2: {
struct ptlrpc_body *pb = lustre_msg_ptlrpc_body(msg);
if (!pb) {
CERROR("invalid msg %p: no ptlrpc body!\n", msg);
return 0;
}
return pb->pb_transno;
}
default:
CERROR("incorrect message magic: %08x\n", msg->lm_magic);
return 0;
}
}
int lustre_msg_get_status(struct lustre_msg *msg)
{
switch (msg->lm_magic) {
case LUSTRE_MSG_MAGIC_V2: {
struct ptlrpc_body *pb = lustre_msg_ptlrpc_body(msg);
if (!pb) {
CERROR("invalid msg %p: no ptlrpc body!\n", msg);
return -EINVAL;
}
return pb->pb_status;
}
default:
return -EINVAL;
}
}
__u64 lustre_msg_get_slv(struct lustre_msg *msg)
{
switch (msg->lm_magic) {
case LUSTRE_MSG_MAGIC_V2: {
struct ptlrpc_body *pb = lustre_msg_ptlrpc_body(msg);
if (!pb) {
CERROR("invalid msg %p: no ptlrpc body!\n", msg);
return -EINVAL;
}
return pb->pb_slv;
}
default:
CERROR("invalid msg magic %08x\n", msg->lm_magic);
return -EINVAL;
}
}
void lustre_msg_set_slv(struct lustre_msg *msg, __u64 slv)
{
switch (msg->lm_magic) {
case LUSTRE_MSG_MAGIC_V2: {
struct ptlrpc_body *pb = lustre_msg_ptlrpc_body(msg);
if (!pb) {
CERROR("invalid msg %p: no ptlrpc body!\n", msg);
return;
}
pb->pb_slv = slv;
return;
}
default:
CERROR("invalid msg magic %x\n", msg->lm_magic);
return;
}
}
__u32 lustre_msg_get_limit(struct lustre_msg *msg)
{
switch (msg->lm_magic) {
case LUSTRE_MSG_MAGIC_V2: {
struct ptlrpc_body *pb = lustre_msg_ptlrpc_body(msg);
if (!pb) {
CERROR("invalid msg %p: no ptlrpc body!\n", msg);
return -EINVAL;
}
return pb->pb_limit;
}
default:
CERROR("invalid msg magic %x\n", msg->lm_magic);
return -EINVAL;
}
}
void lustre_msg_set_limit(struct lustre_msg *msg, __u64 limit)
{
switch (msg->lm_magic) {
case LUSTRE_MSG_MAGIC_V2: {
struct ptlrpc_body *pb = lustre_msg_ptlrpc_body(msg);
if (!pb) {
CERROR("invalid msg %p: no ptlrpc body!\n", msg);
return;
}
pb->pb_limit = limit;
return;
}
default:
CERROR("invalid msg magic %08x\n", msg->lm_magic);
return;
}
}
__u32 lustre_msg_get_conn_cnt(struct lustre_msg *msg)
{
switch (msg->lm_magic) {
case LUSTRE_MSG_MAGIC_V2: {
struct ptlrpc_body *pb = lustre_msg_ptlrpc_body(msg);
if (!pb) {
CERROR("invalid msg %p: no ptlrpc body!\n", msg);
return 0;
}
return pb->pb_conn_cnt;
}
default:
CERROR("incorrect message magic: %08x\n", msg->lm_magic);
return 0;
}
}
int lustre_msg_is_v1(struct lustre_msg *msg)
{
switch (msg->lm_magic) {
case LUSTRE_MSG_MAGIC_V1:
case LUSTRE_MSG_MAGIC_V1_SWABBED:
return 1;
default:
return 0;
}
}
__u32 lustre_msg_get_magic(struct lustre_msg *msg)
{
switch (msg->lm_magic) {
case LUSTRE_MSG_MAGIC_V2:
return msg->lm_magic;
default:
CERROR("incorrect message magic: %08x\n", msg->lm_magic);
return 0;
}
}
__u32 lustre_msg_get_timeout(struct lustre_msg *msg)
{
switch (msg->lm_magic) {
case LUSTRE_MSG_MAGIC_V1:
case LUSTRE_MSG_MAGIC_V1_SWABBED:
return 0;
case LUSTRE_MSG_MAGIC_V2: {
struct ptlrpc_body *pb = lustre_msg_ptlrpc_body(msg);
if (!pb) {
CERROR("invalid msg %p: no ptlrpc body!\n", msg);
return 0;
}
return pb->pb_timeout;
}
default:
CERROR("incorrect message magic: %08x\n", msg->lm_magic);
return 0;
}
}
__u32 lustre_msg_get_service_time(struct lustre_msg *msg)
{
switch (msg->lm_magic) {
case LUSTRE_MSG_MAGIC_V1:
case LUSTRE_MSG_MAGIC_V1_SWABBED:
return 0;
case LUSTRE_MSG_MAGIC_V2: {
struct ptlrpc_body *pb = lustre_msg_ptlrpc_body(msg);
if (!pb) {
CERROR("invalid msg %p: no ptlrpc body!\n", msg);
return 0;
}
return pb->pb_service_time;
}
default:
CERROR("incorrect message magic: %08x\n", msg->lm_magic);
return 0;
}
}
char *lustre_msg_get_jobid(struct lustre_msg *msg)
{
switch (msg->lm_magic) {
case LUSTRE_MSG_MAGIC_V1:
case LUSTRE_MSG_MAGIC_V1_SWABBED:
return NULL;
case LUSTRE_MSG_MAGIC_V2: {
struct ptlrpc_body *pb =
lustre_msg_buf_v2(msg, MSG_PTLRPC_BODY_OFF,
sizeof(struct ptlrpc_body));
if (!pb)
return NULL;
return pb->pb_jobid;
}
default:
CERROR("incorrect message magic: %08x\n", msg->lm_magic);
return NULL;
}
}
__u32 lustre_msg_get_cksum(struct lustre_msg *msg)
{
switch (msg->lm_magic) {
case LUSTRE_MSG_MAGIC_V2:
return msg->lm_cksum;
default:
CERROR("incorrect message magic: %08x\n", msg->lm_magic);
return 0;
}
}
void lustre_msg_set_handle(struct lustre_msg *msg, struct lustre_handle *handle)
{
switch (msg->lm_magic) {
case LUSTRE_MSG_MAGIC_V2: {
struct ptlrpc_body *pb = lustre_msg_ptlrpc_body(msg);
LASSERTF(pb, "invalid msg %p: no ptlrpc body!\n", msg);
pb->pb_handle = *handle;
return;
}
default:
LASSERTF(0, "incorrect message magic: %08x\n", msg->lm_magic);
}
}
void lustre_msg_set_type(struct lustre_msg *msg, __u32 type)
{
switch (msg->lm_magic) {
case LUSTRE_MSG_MAGIC_V2: {
struct ptlrpc_body *pb = lustre_msg_ptlrpc_body(msg);
LASSERTF(pb, "invalid msg %p: no ptlrpc body!\n", msg);
pb->pb_type = type;
return;
}
default:
LASSERTF(0, "incorrect message magic: %08x\n", msg->lm_magic);
}
}
void lustre_msg_set_opc(struct lustre_msg *msg, __u32 opc)
{
switch (msg->lm_magic) {
case LUSTRE_MSG_MAGIC_V2: {
struct ptlrpc_body *pb = lustre_msg_ptlrpc_body(msg);
LASSERTF(pb, "invalid msg %p: no ptlrpc body!\n", msg);
pb->pb_opc = opc;
return;
}
default:
LASSERTF(0, "incorrect message magic: %08x\n", msg->lm_magic);
}
}
void lustre_msg_set_last_xid(struct lustre_msg *msg, __u64 last_xid)
{
switch (msg->lm_magic) {
case LUSTRE_MSG_MAGIC_V2: {
struct ptlrpc_body *pb = lustre_msg_ptlrpc_body(msg);
LASSERTF(pb, "invalid msg %p: no ptlrpc body!\n", msg);
pb->pb_last_xid = last_xid;
return;
}
default:
LASSERTF(0, "incorrect message magic: %08x\n", msg->lm_magic);
}
}
void lustre_msg_set_last_committed(struct lustre_msg *msg, __u64 last_committed)
{
switch (msg->lm_magic) {
case LUSTRE_MSG_MAGIC_V2: {
struct ptlrpc_body *pb = lustre_msg_ptlrpc_body(msg);
LASSERTF(pb, "invalid msg %p: no ptlrpc body!\n", msg);
pb->pb_last_committed = last_committed;
return;
}
default:
LASSERTF(0, "incorrect message magic: %08x\n", msg->lm_magic);
}
}
void lustre_msg_set_versions(struct lustre_msg *msg, __u64 *versions)
{
switch (msg->lm_magic) {
case LUSTRE_MSG_MAGIC_V1:
return;
case LUSTRE_MSG_MAGIC_V2: {
struct ptlrpc_body *pb = lustre_msg_ptlrpc_body(msg);
LASSERTF(pb, "invalid msg %p: no ptlrpc body!\n", msg);
pb->pb_pre_versions[0] = versions[0];
pb->pb_pre_versions[1] = versions[1];
pb->pb_pre_versions[2] = versions[2];
pb->pb_pre_versions[3] = versions[3];
return;
}
default:
LASSERTF(0, "incorrect message magic: %08x\n", msg->lm_magic);
}
}
void lustre_msg_set_transno(struct lustre_msg *msg, __u64 transno)
{
switch (msg->lm_magic) {
case LUSTRE_MSG_MAGIC_V2: {
struct ptlrpc_body *pb = lustre_msg_ptlrpc_body(msg);
LASSERTF(pb, "invalid msg %p: no ptlrpc body!\n", msg);
pb->pb_transno = transno;
return;
}
default:
LASSERTF(0, "incorrect message magic: %08x\n", msg->lm_magic);
}
}
void lustre_msg_set_status(struct lustre_msg *msg, __u32 status)
{
switch (msg->lm_magic) {
case LUSTRE_MSG_MAGIC_V2: {
struct ptlrpc_body *pb = lustre_msg_ptlrpc_body(msg);
LASSERTF(pb, "invalid msg %p: no ptlrpc body!\n", msg);
pb->pb_status = status;
return;
}
default:
LASSERTF(0, "incorrect message magic: %08x\n", msg->lm_magic);
}
}
void lustre_msg_set_conn_cnt(struct lustre_msg *msg, __u32 conn_cnt)
{
switch (msg->lm_magic) {
case LUSTRE_MSG_MAGIC_V2: {
struct ptlrpc_body *pb = lustre_msg_ptlrpc_body(msg);
LASSERTF(pb, "invalid msg %p: no ptlrpc body!\n", msg);
pb->pb_conn_cnt = conn_cnt;
return;
}
default:
LASSERTF(0, "incorrect message magic: %08x\n", msg->lm_magic);
}
}
void lustre_msg_set_timeout(struct lustre_msg *msg, __u32 timeout)
{
switch (msg->lm_magic) {
case LUSTRE_MSG_MAGIC_V1:
return;
case LUSTRE_MSG_MAGIC_V2: {
struct ptlrpc_body *pb = lustre_msg_ptlrpc_body(msg);
LASSERTF(pb, "invalid msg %p: no ptlrpc body!\n", msg);
pb->pb_timeout = timeout;
return;
}
default:
LASSERTF(0, "incorrect message magic: %08x\n", msg->lm_magic);
}
}
void lustre_msg_set_service_time(struct lustre_msg *msg, __u32 service_time)
{
switch (msg->lm_magic) {
case LUSTRE_MSG_MAGIC_V1:
return;
case LUSTRE_MSG_MAGIC_V2: {
struct ptlrpc_body *pb = lustre_msg_ptlrpc_body(msg);
LASSERTF(pb, "invalid msg %p: no ptlrpc body!\n", msg);
pb->pb_service_time = service_time;
return;
}
default:
LASSERTF(0, "incorrect message magic: %08x\n", msg->lm_magic);
}
}
void lustre_msg_set_jobid(struct lustre_msg *msg, char *jobid)
{
switch (msg->lm_magic) {
case LUSTRE_MSG_MAGIC_V1:
return;
case LUSTRE_MSG_MAGIC_V2: {
__u32 opc = lustre_msg_get_opc(msg);
struct ptlrpc_body *pb;
if (!opc || opc == LDLM_BL_CALLBACK ||
opc == LDLM_CP_CALLBACK || opc == LDLM_GL_CALLBACK)
return;
pb = lustre_msg_buf_v2(msg, MSG_PTLRPC_BODY_OFF,
sizeof(struct ptlrpc_body));
LASSERTF(pb, "invalid msg %p: no ptlrpc body!\n", msg);
if (jobid != NULL)
memcpy(pb->pb_jobid, jobid, JOBSTATS_JOBID_SIZE);
else if (pb->pb_jobid[0] == '\0')
lustre_get_jobid(pb->pb_jobid);
return;
}
default:
LASSERTF(0, "incorrect message magic: %08x\n", msg->lm_magic);
}
}
void lustre_msg_set_cksum(struct lustre_msg *msg, __u32 cksum)
{
switch (msg->lm_magic) {
case LUSTRE_MSG_MAGIC_V1:
return;
case LUSTRE_MSG_MAGIC_V2:
msg->lm_cksum = cksum;
return;
default:
LASSERTF(0, "incorrect message magic: %08x\n", msg->lm_magic);
}
}
void ptlrpc_request_set_replen(struct ptlrpc_request *req)
{
int count = req_capsule_filled_sizes(&req->rq_pill, RCL_SERVER);
req->rq_replen = lustre_msg_size(req->rq_reqmsg->lm_magic, count,
req->rq_pill.rc_area[RCL_SERVER]);
if (req->rq_reqmsg->lm_magic == LUSTRE_MSG_MAGIC_V2)
req->rq_reqmsg->lm_repsize = req->rq_replen;
}
void ptlrpc_req_set_repsize(struct ptlrpc_request *req, int count, __u32 *lens)
{
req->rq_replen = lustre_msg_size(req->rq_reqmsg->lm_magic, count, lens);
if (req->rq_reqmsg->lm_magic == LUSTRE_MSG_MAGIC_V2)
req->rq_reqmsg->lm_repsize = req->rq_replen;
}
int do_set_info_async(struct obd_import *imp,
int opcode, int version,
obd_count keylen, void *key,
obd_count vallen, void *val,
struct ptlrpc_request_set *set)
{
struct ptlrpc_request *req;
char *tmp;
int rc;
req = ptlrpc_request_alloc(imp, &RQF_OBD_SET_INFO);
if (req == NULL)
return -ENOMEM;
req_capsule_set_size(&req->rq_pill, &RMF_SETINFO_KEY,
RCL_CLIENT, keylen);
req_capsule_set_size(&req->rq_pill, &RMF_SETINFO_VAL,
RCL_CLIENT, vallen);
rc = ptlrpc_request_pack(req, version, opcode);
if (rc) {
ptlrpc_request_free(req);
return rc;
}
tmp = req_capsule_client_get(&req->rq_pill, &RMF_SETINFO_KEY);
memcpy(tmp, key, keylen);
tmp = req_capsule_client_get(&req->rq_pill, &RMF_SETINFO_VAL);
memcpy(tmp, val, vallen);
ptlrpc_request_set_replen(req);
if (set) {
ptlrpc_set_add_req(set, req);
ptlrpc_check_set(NULL, set);
} else {
rc = ptlrpc_queue_wait(req);
ptlrpc_req_finished(req);
}
return rc;
}
void lustre_swab_ptlrpc_body(struct ptlrpc_body *b)
{
__swab32s (&b->pb_type);
__swab32s (&b->pb_version);
__swab32s (&b->pb_opc);
__swab32s (&b->pb_status);
__swab64s (&b->pb_last_xid);
__swab64s (&b->pb_last_seen);
__swab64s (&b->pb_last_committed);
__swab64s (&b->pb_transno);
__swab32s (&b->pb_flags);
__swab32s (&b->pb_op_flags);
__swab32s (&b->pb_conn_cnt);
__swab32s (&b->pb_timeout);
__swab32s (&b->pb_service_time);
__swab32s (&b->pb_limit);
__swab64s (&b->pb_slv);
__swab64s (&b->pb_pre_versions[0]);
__swab64s (&b->pb_pre_versions[1]);
__swab64s (&b->pb_pre_versions[2]);
__swab64s (&b->pb_pre_versions[3]);
CLASSERT(offsetof(typeof(*b), pb_padding) != 0);
CLASSERT(offsetof(typeof(*b), pb_jobid) != 0);
}
void lustre_swab_connect(struct obd_connect_data *ocd)
{
__swab64s(&ocd->ocd_connect_flags);
__swab32s(&ocd->ocd_version);
__swab32s(&ocd->ocd_grant);
__swab64s(&ocd->ocd_ibits_known);
__swab32s(&ocd->ocd_index);
__swab32s(&ocd->ocd_brw_size);
__swab16s(&ocd->ocd_grant_extent);
__swab32s(&ocd->ocd_unused);
__swab64s(&ocd->ocd_transno);
__swab32s(&ocd->ocd_group);
__swab32s(&ocd->ocd_cksum_types);
__swab32s(&ocd->ocd_instance);
if (ocd->ocd_connect_flags & OBD_CONNECT_MAX_EASIZE)
__swab32s(&ocd->ocd_max_easize);
if (ocd->ocd_connect_flags & OBD_CONNECT_MAXBYTES)
__swab64s(&ocd->ocd_maxbytes);
CLASSERT(offsetof(typeof(*ocd), padding1) != 0);
CLASSERT(offsetof(typeof(*ocd), padding2) != 0);
CLASSERT(offsetof(typeof(*ocd), padding3) != 0);
CLASSERT(offsetof(typeof(*ocd), padding4) != 0);
CLASSERT(offsetof(typeof(*ocd), padding5) != 0);
CLASSERT(offsetof(typeof(*ocd), padding6) != 0);
CLASSERT(offsetof(typeof(*ocd), padding7) != 0);
CLASSERT(offsetof(typeof(*ocd), padding8) != 0);
CLASSERT(offsetof(typeof(*ocd), padding9) != 0);
CLASSERT(offsetof(typeof(*ocd), paddingA) != 0);
CLASSERT(offsetof(typeof(*ocd), paddingB) != 0);
CLASSERT(offsetof(typeof(*ocd), paddingC) != 0);
CLASSERT(offsetof(typeof(*ocd), paddingD) != 0);
CLASSERT(offsetof(typeof(*ocd), paddingE) != 0);
CLASSERT(offsetof(typeof(*ocd), paddingF) != 0);
}
void lustre_swab_obdo (struct obdo *o)
{
__swab64s (&o->o_valid);
lustre_swab_ost_id(&o->o_oi);
__swab64s (&o->o_parent_seq);
__swab64s (&o->o_size);
__swab64s (&o->o_mtime);
__swab64s (&o->o_atime);
__swab64s (&o->o_ctime);
__swab64s (&o->o_blocks);
__swab64s (&o->o_grant);
__swab32s (&o->o_blksize);
__swab32s (&o->o_mode);
__swab32s (&o->o_uid);
__swab32s (&o->o_gid);
__swab32s (&o->o_flags);
__swab32s (&o->o_nlink);
__swab32s (&o->o_parent_oid);
__swab32s (&o->o_misc);
__swab64s (&o->o_ioepoch);
__swab32s (&o->o_stripe_idx);
__swab32s (&o->o_parent_ver);
__swab32s (&o->o_uid_h);
__swab32s (&o->o_gid_h);
__swab64s (&o->o_data_version);
CLASSERT(offsetof(typeof(*o), o_padding_4) != 0);
CLASSERT(offsetof(typeof(*o), o_padding_5) != 0);
CLASSERT(offsetof(typeof(*o), o_padding_6) != 0);
}
void lustre_swab_obd_statfs (struct obd_statfs *os)
{
__swab64s (&os->os_type);
__swab64s (&os->os_blocks);
__swab64s (&os->os_bfree);
__swab64s (&os->os_bavail);
__swab64s (&os->os_files);
__swab64s (&os->os_ffree);
__swab32s (&os->os_bsize);
__swab32s (&os->os_namelen);
__swab64s (&os->os_maxbytes);
__swab32s (&os->os_state);
CLASSERT(offsetof(typeof(*os), os_fprecreated) != 0);
CLASSERT(offsetof(typeof(*os), os_spare2) != 0);
CLASSERT(offsetof(typeof(*os), os_spare3) != 0);
CLASSERT(offsetof(typeof(*os), os_spare4) != 0);
CLASSERT(offsetof(typeof(*os), os_spare5) != 0);
CLASSERT(offsetof(typeof(*os), os_spare6) != 0);
CLASSERT(offsetof(typeof(*os), os_spare7) != 0);
CLASSERT(offsetof(typeof(*os), os_spare8) != 0);
CLASSERT(offsetof(typeof(*os), os_spare9) != 0);
}
void lustre_swab_obd_ioobj(struct obd_ioobj *ioo)
{
lustre_swab_ost_id(&ioo->ioo_oid);
__swab32s(&ioo->ioo_max_brw);
__swab32s(&ioo->ioo_bufcnt);
}
void lustre_swab_niobuf_remote (struct niobuf_remote *nbr)
{
__swab64s (&nbr->offset);
__swab32s (&nbr->len);
__swab32s (&nbr->flags);
}
void lustre_swab_ost_body (struct ost_body *b)
{
lustre_swab_obdo (&b->oa);
}
void lustre_swab_ost_last_id(obd_id *id)
{
__swab64s(id);
}
void lustre_swab_generic_32s(__u32 *val)
{
__swab32s(val);
}
void lustre_swab_gl_desc(union ldlm_gl_desc *desc)
{
lustre_swab_lu_fid(&desc->lquota_desc.gl_id.qid_fid);
__swab64s(&desc->lquota_desc.gl_flags);
__swab64s(&desc->lquota_desc.gl_ver);
__swab64s(&desc->lquota_desc.gl_hardlimit);
__swab64s(&desc->lquota_desc.gl_softlimit);
__swab64s(&desc->lquota_desc.gl_time);
CLASSERT(offsetof(typeof(desc->lquota_desc), gl_pad2) != 0);
}
void lustre_swab_ost_lvb_v1(struct ost_lvb_v1 *lvb)
{
__swab64s(&lvb->lvb_size);
__swab64s(&lvb->lvb_mtime);
__swab64s(&lvb->lvb_atime);
__swab64s(&lvb->lvb_ctime);
__swab64s(&lvb->lvb_blocks);
}
void lustre_swab_ost_lvb(struct ost_lvb *lvb)
{
__swab64s(&lvb->lvb_size);
__swab64s(&lvb->lvb_mtime);
__swab64s(&lvb->lvb_atime);
__swab64s(&lvb->lvb_ctime);
__swab64s(&lvb->lvb_blocks);
__swab32s(&lvb->lvb_mtime_ns);
__swab32s(&lvb->lvb_atime_ns);
__swab32s(&lvb->lvb_ctime_ns);
__swab32s(&lvb->lvb_padding);
}
void lustre_swab_lquota_lvb(struct lquota_lvb *lvb)
{
__swab64s(&lvb->lvb_flags);
__swab64s(&lvb->lvb_id_may_rel);
__swab64s(&lvb->lvb_id_rel);
__swab64s(&lvb->lvb_id_qunit);
__swab64s(&lvb->lvb_pad1);
}
void lustre_swab_mdt_body (struct mdt_body *b)
{
lustre_swab_lu_fid (&b->fid1);
lustre_swab_lu_fid (&b->fid2);
__swab64s (&b->valid);
__swab64s (&b->size);
__swab64s (&b->mtime);
__swab64s (&b->atime);
__swab64s (&b->ctime);
__swab64s (&b->blocks);
__swab64s (&b->ioepoch);
CLASSERT(offsetof(typeof(*b), unused1) != 0);
__swab32s (&b->fsuid);
__swab32s (&b->fsgid);
__swab32s (&b->capability);
__swab32s (&b->mode);
__swab32s (&b->uid);
__swab32s (&b->gid);
__swab32s (&b->flags);
__swab32s (&b->rdev);
__swab32s (&b->nlink);
CLASSERT(offsetof(typeof(*b), unused2) != 0);
__swab32s (&b->suppgid);
__swab32s (&b->eadatasize);
__swab32s (&b->aclsize);
__swab32s (&b->max_mdsize);
__swab32s (&b->max_cookiesize);
__swab32s (&b->uid_h);
__swab32s (&b->gid_h);
CLASSERT(offsetof(typeof(*b), padding_5) != 0);
}
void lustre_swab_mdt_ioepoch (struct mdt_ioepoch *b)
{
__swab64s (&b->ioepoch);
__swab32s (&b->flags);
CLASSERT(offsetof(typeof(*b), padding) != 0);
}
void lustre_swab_mgs_target_info(struct mgs_target_info *mti)
{
int i;
__swab32s(&mti->mti_lustre_ver);
__swab32s(&mti->mti_stripe_index);
__swab32s(&mti->mti_config_ver);
__swab32s(&mti->mti_flags);
__swab32s(&mti->mti_instance);
__swab32s(&mti->mti_nid_count);
CLASSERT(sizeof(lnet_nid_t) == sizeof(__u64));
for (i = 0; i < MTI_NIDS_MAX; i++)
__swab64s(&mti->mti_nids[i]);
}
void lustre_swab_mgs_nidtbl_entry(struct mgs_nidtbl_entry *entry)
{
int i;
__swab64s(&entry->mne_version);
__swab32s(&entry->mne_instance);
__swab32s(&entry->mne_index);
__swab32s(&entry->mne_length);
CLASSERT(sizeof(entry->mne_nid_count) == sizeof(__u8));
CLASSERT(sizeof(entry->mne_nid_type) == sizeof(__u8));
LASSERT(entry->mne_nid_type == 0);
for (i = 0; i < entry->mne_nid_count; i++) {
CLASSERT(sizeof(lnet_nid_t) == sizeof(__u64));
__swab64s(&entry->u.nids[i]);
}
}
void lustre_swab_mgs_config_body(struct mgs_config_body *body)
{
__swab64s(&body->mcb_offset);
__swab32s(&body->mcb_units);
__swab16s(&body->mcb_type);
}
void lustre_swab_mgs_config_res(struct mgs_config_res *body)
{
__swab64s(&body->mcr_offset);
__swab64s(&body->mcr_size);
}
static void lustre_swab_obd_dqinfo (struct obd_dqinfo *i)
{
__swab64s (&i->dqi_bgrace);
__swab64s (&i->dqi_igrace);
__swab32s (&i->dqi_flags);
__swab32s (&i->dqi_valid);
}
static void lustre_swab_obd_dqblk (struct obd_dqblk *b)
{
__swab64s (&b->dqb_ihardlimit);
__swab64s (&b->dqb_isoftlimit);
__swab64s (&b->dqb_curinodes);
__swab64s (&b->dqb_bhardlimit);
__swab64s (&b->dqb_bsoftlimit);
__swab64s (&b->dqb_curspace);
__swab64s (&b->dqb_btime);
__swab64s (&b->dqb_itime);
__swab32s (&b->dqb_valid);
CLASSERT(offsetof(typeof(*b), dqb_padding) != 0);
}
void lustre_swab_obd_quotactl (struct obd_quotactl *q)
{
__swab32s (&q->qc_cmd);
__swab32s (&q->qc_type);
__swab32s (&q->qc_id);
__swab32s (&q->qc_stat);
lustre_swab_obd_dqinfo (&q->qc_dqinfo);
lustre_swab_obd_dqblk (&q->qc_dqblk);
}
void lustre_swab_mdt_remote_perm (struct mdt_remote_perm *p)
{
__swab32s (&p->rp_uid);
__swab32s (&p->rp_gid);
__swab32s (&p->rp_fsuid);
__swab32s (&p->rp_fsuid_h);
__swab32s (&p->rp_fsgid);
__swab32s (&p->rp_fsgid_h);
__swab32s (&p->rp_access_perm);
__swab32s (&p->rp_padding);
}
void lustre_swab_fid2path(struct getinfo_fid2path *gf)
{
lustre_swab_lu_fid(&gf->gf_fid);
__swab64s(&gf->gf_recno);
__swab32s(&gf->gf_linkno);
__swab32s(&gf->gf_pathlen);
}
void lustre_swab_fiemap_extent(struct ll_fiemap_extent *fm_extent)
{
__swab64s(&fm_extent->fe_logical);
__swab64s(&fm_extent->fe_physical);
__swab64s(&fm_extent->fe_length);
__swab32s(&fm_extent->fe_flags);
__swab32s(&fm_extent->fe_device);
}
void lustre_swab_fiemap(struct ll_user_fiemap *fiemap)
{
int i;
__swab64s(&fiemap->fm_start);
__swab64s(&fiemap->fm_length);
__swab32s(&fiemap->fm_flags);
__swab32s(&fiemap->fm_mapped_extents);
__swab32s(&fiemap->fm_extent_count);
__swab32s(&fiemap->fm_reserved);
for (i = 0; i < fiemap->fm_mapped_extents; i++)
lustre_swab_fiemap_extent(&fiemap->fm_extents[i]);
}
void lustre_swab_idx_info(struct idx_info *ii)
{
__swab32s(&ii->ii_magic);
__swab32s(&ii->ii_flags);
__swab16s(&ii->ii_count);
__swab32s(&ii->ii_attrs);
lustre_swab_lu_fid(&ii->ii_fid);
__swab64s(&ii->ii_version);
__swab64s(&ii->ii_hash_start);
__swab64s(&ii->ii_hash_end);
__swab16s(&ii->ii_keysize);
__swab16s(&ii->ii_recsize);
}
void lustre_swab_lip_header(struct lu_idxpage *lip)
{
__swab32s(&lip->lip_magic);
__swab16s(&lip->lip_flags);
__swab16s(&lip->lip_nr);
}
void lustre_swab_mdt_rec_reint (struct mdt_rec_reint *rr)
{
__swab32s(&rr->rr_opcode);
__swab32s(&rr->rr_cap);
__swab32s(&rr->rr_fsuid);
__swab32s(&rr->rr_fsgid);
__swab32s(&rr->rr_suppgid1);
__swab32s(&rr->rr_suppgid2);
lustre_swab_lu_fid(&rr->rr_fid1);
lustre_swab_lu_fid(&rr->rr_fid2);
__swab64s(&rr->rr_mtime);
__swab64s(&rr->rr_atime);
__swab64s(&rr->rr_ctime);
__swab64s(&rr->rr_size);
__swab64s(&rr->rr_blocks);
__swab32s(&rr->rr_bias);
__swab32s(&rr->rr_mode);
__swab32s(&rr->rr_flags);
__swab32s(&rr->rr_flags_h);
__swab32s(&rr->rr_umask);
CLASSERT(offsetof(typeof(*rr), rr_padding_4) != 0);
}
void lustre_swab_lov_desc (struct lov_desc *ld)
{
__swab32s (&ld->ld_tgt_count);
__swab32s (&ld->ld_active_tgt_count);
__swab32s (&ld->ld_default_stripe_count);
__swab32s (&ld->ld_pattern);
__swab64s (&ld->ld_default_stripe_size);
__swab64s (&ld->ld_default_stripe_offset);
__swab32s (&ld->ld_qos_maxage);
}
void lustre_swab_lmv_desc (struct lmv_desc *ld)
{
__swab32s (&ld->ld_tgt_count);
__swab32s (&ld->ld_active_tgt_count);
__swab32s (&ld->ld_default_stripe_count);
__swab32s (&ld->ld_pattern);
__swab64s (&ld->ld_default_hash_size);
__swab32s (&ld->ld_qos_maxage);
}
void lustre_swab_lmv_stripe_md (struct lmv_stripe_md *mea)
{
__swab32s(&mea->mea_magic);
__swab32s(&mea->mea_count);
__swab32s(&mea->mea_master);
CLASSERT(offsetof(typeof(*mea), mea_padding) != 0);
}
void lustre_swab_lmv_user_md(struct lmv_user_md *lum)
{
int i;
__swab32s(&lum->lum_magic);
__swab32s(&lum->lum_stripe_count);
__swab32s(&lum->lum_stripe_offset);
__swab32s(&lum->lum_hash_type);
__swab32s(&lum->lum_type);
CLASSERT(offsetof(typeof(*lum), lum_padding1) != 0);
CLASSERT(offsetof(typeof(*lum), lum_padding2) != 0);
CLASSERT(offsetof(typeof(*lum), lum_padding3) != 0);
for (i = 0; i < lum->lum_stripe_count; i++) {
__swab32s(&lum->lum_objects[i].lum_mds);
lustre_swab_lu_fid(&lum->lum_objects[i].lum_fid);
}
}
static void print_lum (struct lov_user_md *lum)
{
CDEBUG(D_OTHER, "lov_user_md %p:\n", lum);
CDEBUG(D_OTHER, "\tlmm_magic: %#x\n", lum->lmm_magic);
CDEBUG(D_OTHER, "\tlmm_pattern: %#x\n", lum->lmm_pattern);
CDEBUG(D_OTHER, "\tlmm_object_id: "LPU64"\n", lmm_oi_id(&lum->lmm_oi));
CDEBUG(D_OTHER, "\tlmm_object_gr: "LPU64"\n", lmm_oi_seq(&lum->lmm_oi));
CDEBUG(D_OTHER, "\tlmm_stripe_size: %#x\n", lum->lmm_stripe_size);
CDEBUG(D_OTHER, "\tlmm_stripe_count: %#x\n", lum->lmm_stripe_count);
CDEBUG(D_OTHER, "\tlmm_stripe_offset/lmm_layout_gen: %#x\n",
lum->lmm_stripe_offset);
}
static void lustre_swab_lmm_oi(struct ost_id *oi)
{
__swab64s(&oi->oi.oi_id);
__swab64s(&oi->oi.oi_seq);
}
static void lustre_swab_lov_user_md_common(struct lov_user_md_v1 *lum)
{
__swab32s(&lum->lmm_magic);
__swab32s(&lum->lmm_pattern);
lustre_swab_lmm_oi(&lum->lmm_oi);
__swab32s(&lum->lmm_stripe_size);
__swab16s(&lum->lmm_stripe_count);
__swab16s(&lum->lmm_stripe_offset);
print_lum(lum);
}
void lustre_swab_lov_user_md_v1(struct lov_user_md_v1 *lum)
{
CDEBUG(D_IOCTL, "swabbing lov_user_md v1\n");
lustre_swab_lov_user_md_common(lum);
}
void lustre_swab_lov_user_md_v3(struct lov_user_md_v3 *lum)
{
CDEBUG(D_IOCTL, "swabbing lov_user_md v3\n");
lustre_swab_lov_user_md_common((struct lov_user_md_v1 *)lum);
}
void lustre_swab_lov_mds_md(struct lov_mds_md *lmm)
{
CDEBUG(D_IOCTL, "swabbing lov_mds_md\n");
__swab32s(&lmm->lmm_magic);
__swab32s(&lmm->lmm_pattern);
lustre_swab_lmm_oi(&lmm->lmm_oi);
__swab32s(&lmm->lmm_stripe_size);
__swab16s(&lmm->lmm_stripe_count);
__swab16s(&lmm->lmm_layout_gen);
}
void lustre_swab_lov_user_md_objects(struct lov_user_ost_data *lod,
int stripe_count)
{
int i;
for (i = 0; i < stripe_count; i++) {
lustre_swab_ost_id(&(lod[i].l_ost_oi));
__swab32s(&(lod[i].l_ost_gen));
__swab32s(&(lod[i].l_ost_idx));
}
}
void lustre_swab_ldlm_res_id (struct ldlm_res_id *id)
{
int i;
for (i = 0; i < RES_NAME_SIZE; i++)
__swab64s (&id->name[i]);
}
void lustre_swab_ldlm_policy_data (ldlm_wire_policy_data_t *d)
{
__swab64s(&d->l_extent.start);
__swab64s(&d->l_extent.end);
__swab64s(&d->l_extent.gid);
__swab64s(&d->l_flock.lfw_owner);
__swab32s(&d->l_flock.lfw_pid);
}
void lustre_swab_ldlm_intent (struct ldlm_intent *i)
{
__swab64s (&i->opc);
}
void lustre_swab_ldlm_resource_desc (struct ldlm_resource_desc *r)
{
__swab32s (&r->lr_type);
CLASSERT(offsetof(typeof(*r), lr_padding) != 0);
lustre_swab_ldlm_res_id (&r->lr_name);
}
void lustre_swab_ldlm_lock_desc (struct ldlm_lock_desc *l)
{
lustre_swab_ldlm_resource_desc (&l->l_resource);
__swab32s (&l->l_req_mode);
__swab32s (&l->l_granted_mode);
lustre_swab_ldlm_policy_data (&l->l_policy_data);
}
void lustre_swab_ldlm_request (struct ldlm_request *rq)
{
__swab32s (&rq->lock_flags);
lustre_swab_ldlm_lock_desc (&rq->lock_desc);
__swab32s (&rq->lock_count);
}
void lustre_swab_ldlm_reply (struct ldlm_reply *r)
{
__swab32s (&r->lock_flags);
CLASSERT(offsetof(typeof(*r), lock_padding) != 0);
lustre_swab_ldlm_lock_desc (&r->lock_desc);
__swab64s (&r->lock_policy_res1);
__swab64s (&r->lock_policy_res2);
}
void lustre_swab_quota_body(struct quota_body *b)
{
lustre_swab_lu_fid(&b->qb_fid);
lustre_swab_lu_fid((struct lu_fid *)&b->qb_id);
__swab32s(&b->qb_flags);
__swab64s(&b->qb_count);
__swab64s(&b->qb_usage);
__swab64s(&b->qb_slv_ver);
}
void dump_ioo(struct obd_ioobj *ioo)
{
CDEBUG(D_RPCTRACE,
"obd_ioobj: ioo_oid="DOSTID", ioo_max_brw=%#x, "
"ioo_bufct=%d\n", POSTID(&ioo->ioo_oid), ioo->ioo_max_brw,
ioo->ioo_bufcnt);
}
void dump_rniobuf(struct niobuf_remote *nb)
{
CDEBUG(D_RPCTRACE, "niobuf_remote: offset="LPU64", len=%d, flags=%x\n",
nb->offset, nb->len, nb->flags);
}
void dump_obdo(struct obdo *oa)
{
__u32 valid = oa->o_valid;
CDEBUG(D_RPCTRACE, "obdo: o_valid = %08x\n", valid);
if (valid & OBD_MD_FLID)
CDEBUG(D_RPCTRACE, "obdo: id = "DOSTID"\n", POSTID(&oa->o_oi));
if (valid & OBD_MD_FLFID)
CDEBUG(D_RPCTRACE, "obdo: o_parent_seq = "LPX64"\n",
oa->o_parent_seq);
if (valid & OBD_MD_FLSIZE)
CDEBUG(D_RPCTRACE, "obdo: o_size = "LPD64"\n", oa->o_size);
if (valid & OBD_MD_FLMTIME)
CDEBUG(D_RPCTRACE, "obdo: o_mtime = "LPD64"\n", oa->o_mtime);
if (valid & OBD_MD_FLATIME)
CDEBUG(D_RPCTRACE, "obdo: o_atime = "LPD64"\n", oa->o_atime);
if (valid & OBD_MD_FLCTIME)
CDEBUG(D_RPCTRACE, "obdo: o_ctime = "LPD64"\n", oa->o_ctime);
if (valid & OBD_MD_FLBLOCKS)
CDEBUG(D_RPCTRACE, "obdo: o_blocks = "LPD64"\n", oa->o_blocks);
if (valid & OBD_MD_FLGRANT)
CDEBUG(D_RPCTRACE, "obdo: o_grant = "LPD64"\n", oa->o_grant);
if (valid & OBD_MD_FLBLKSZ)
CDEBUG(D_RPCTRACE, "obdo: o_blksize = %d\n", oa->o_blksize);
if (valid & (OBD_MD_FLTYPE | OBD_MD_FLMODE))
CDEBUG(D_RPCTRACE, "obdo: o_mode = %o\n",
oa->o_mode & ((valid & OBD_MD_FLTYPE ? S_IFMT : 0) |
(valid & OBD_MD_FLMODE ? ~S_IFMT : 0)));
if (valid & OBD_MD_FLUID)
CDEBUG(D_RPCTRACE, "obdo: o_uid = %u\n", oa->o_uid);
if (valid & OBD_MD_FLUID)
CDEBUG(D_RPCTRACE, "obdo: o_uid_h = %u\n", oa->o_uid_h);
if (valid & OBD_MD_FLGID)
CDEBUG(D_RPCTRACE, "obdo: o_gid = %u\n", oa->o_gid);
if (valid & OBD_MD_FLGID)
CDEBUG(D_RPCTRACE, "obdo: o_gid_h = %u\n", oa->o_gid_h);
if (valid & OBD_MD_FLFLAGS)
CDEBUG(D_RPCTRACE, "obdo: o_flags = %x\n", oa->o_flags);
if (valid & OBD_MD_FLNLINK)
CDEBUG(D_RPCTRACE, "obdo: o_nlink = %u\n", oa->o_nlink);
else if (valid & OBD_MD_FLCKSUM)
CDEBUG(D_RPCTRACE, "obdo: o_checksum (o_nlink) = %u\n",
oa->o_nlink);
if (valid & OBD_MD_FLGENER)
CDEBUG(D_RPCTRACE, "obdo: o_parent_oid = %x\n",
oa->o_parent_oid);
if (valid & OBD_MD_FLEPOCH)
CDEBUG(D_RPCTRACE, "obdo: o_ioepoch = "LPD64"\n",
oa->o_ioepoch);
if (valid & OBD_MD_FLFID) {
CDEBUG(D_RPCTRACE, "obdo: o_stripe_idx = %u\n",
oa->o_stripe_idx);
CDEBUG(D_RPCTRACE, "obdo: o_parent_ver = %x\n",
oa->o_parent_ver);
}
if (valid & OBD_MD_FLHANDLE)
CDEBUG(D_RPCTRACE, "obdo: o_handle = "LPD64"\n",
oa->o_handle.cookie);
if (valid & OBD_MD_FLCOOKIE)
CDEBUG(D_RPCTRACE, "obdo: o_lcookie = "
"(llog_cookie dumping not yet implemented)\n");
}
void dump_ost_body(struct ost_body *ob)
{
dump_obdo(&ob->oa);
}
void dump_rcs(__u32 *rc)
{
CDEBUG(D_RPCTRACE, "rmf_rcs: %d\n", *rc);
}
static inline int req_ptlrpc_body_swabbed(struct ptlrpc_request *req)
{
LASSERT(req->rq_reqmsg);
switch (req->rq_reqmsg->lm_magic) {
case LUSTRE_MSG_MAGIC_V2:
return lustre_req_swabbed(req, MSG_PTLRPC_BODY_OFF);
default:
CERROR("bad lustre msg magic: %#08X\n",
req->rq_reqmsg->lm_magic);
}
return 0;
}
static inline int rep_ptlrpc_body_swabbed(struct ptlrpc_request *req)
{
LASSERT(req->rq_repmsg);
switch (req->rq_repmsg->lm_magic) {
case LUSTRE_MSG_MAGIC_V2:
return lustre_rep_swabbed(req, MSG_PTLRPC_BODY_OFF);
default:
return 0;
}
}
void _debug_req(struct ptlrpc_request *req,
struct libcfs_debug_msg_data *msgdata,
const char *fmt, ... )
{
int req_ok = req->rq_reqmsg != NULL;
int rep_ok = req->rq_repmsg != NULL;
lnet_nid_t nid = LNET_NID_ANY;
va_list args;
if (ptlrpc_req_need_swab(req)) {
req_ok = req_ok && req_ptlrpc_body_swabbed(req);
rep_ok = rep_ok && rep_ptlrpc_body_swabbed(req);
}
if (req->rq_import && req->rq_import->imp_connection)
nid = req->rq_import->imp_connection->c_peer.nid;
else if (req->rq_export && req->rq_export->exp_connection)
nid = req->rq_export->exp_connection->c_peer.nid;
va_start(args, fmt);
libcfs_debug_vmsg2(msgdata, fmt, args,
" req@%p x"LPU64"/t"LPD64"("LPD64") o%d->%s@%s:%d/%d"
" lens %d/%d e %d to %d dl "CFS_TIME_T" ref %d "
"fl "REQ_FLAGS_FMT"/%x/%x rc %d/%d\n",
req, req->rq_xid, req->rq_transno,
req_ok ? lustre_msg_get_transno(req->rq_reqmsg) : 0,
req_ok ? lustre_msg_get_opc(req->rq_reqmsg) : -1,
req->rq_import ?
req->rq_import->imp_obd->obd_name :
req->rq_export ?
req->rq_export->exp_client_uuid.uuid :
"<?>",
libcfs_nid2str(nid),
req->rq_request_portal, req->rq_reply_portal,
req->rq_reqlen, req->rq_replen,
req->rq_early_count, req->rq_timedout,
req->rq_deadline,
atomic_read(&req->rq_refcount),
DEBUG_REQ_FLAGS(req),
req_ok ? lustre_msg_get_flags(req->rq_reqmsg) : -1,
rep_ok ? lustre_msg_get_flags(req->rq_repmsg) : -1,
req->rq_status,
rep_ok ? lustre_msg_get_status(req->rq_repmsg) : -1);
va_end(args);
}
void lustre_swab_lustre_capa(struct lustre_capa *c)
{
lustre_swab_lu_fid(&c->lc_fid);
__swab64s (&c->lc_opc);
__swab64s (&c->lc_uid);
__swab64s (&c->lc_gid);
__swab32s (&c->lc_flags);
__swab32s (&c->lc_keyid);
__swab32s (&c->lc_timeout);
__swab32s (&c->lc_expiry);
}
void lustre_swab_lustre_capa_key(struct lustre_capa_key *k)
{
__swab64s (&k->lk_seq);
__swab32s (&k->lk_keyid);
CLASSERT(offsetof(typeof(*k), lk_padding) != 0);
}
void lustre_swab_hsm_user_state(struct hsm_user_state *state)
{
__swab32s(&state->hus_states);
__swab32s(&state->hus_archive_id);
}
void lustre_swab_hsm_state_set(struct hsm_state_set *hss)
{
__swab32s(&hss->hss_valid);
__swab64s(&hss->hss_setmask);
__swab64s(&hss->hss_clearmask);
__swab32s(&hss->hss_archive_id);
}
void lustre_swab_hsm_extent(struct hsm_extent *extent)
{
__swab64s(&extent->offset);
__swab64s(&extent->length);
}
void lustre_swab_hsm_current_action(struct hsm_current_action *action)
{
__swab32s(&action->hca_state);
__swab32s(&action->hca_action);
lustre_swab_hsm_extent(&action->hca_location);
}
void lustre_swab_hsm_user_item(struct hsm_user_item *hui)
{
lustre_swab_lu_fid(&hui->hui_fid);
lustre_swab_hsm_extent(&hui->hui_extent);
}
void lustre_swab_layout_intent(struct layout_intent *li)
{
__swab32s(&li->li_opc);
__swab32s(&li->li_flags);
__swab64s(&li->li_start);
__swab64s(&li->li_end);
}
void lustre_swab_hsm_progress_kernel(struct hsm_progress_kernel *hpk)
{
lustre_swab_lu_fid(&hpk->hpk_fid);
__swab64s(&hpk->hpk_cookie);
__swab64s(&hpk->hpk_extent.offset);
__swab64s(&hpk->hpk_extent.length);
__swab16s(&hpk->hpk_flags);
__swab16s(&hpk->hpk_errval);
}
void lustre_swab_hsm_request(struct hsm_request *hr)
{
__swab32s(&hr->hr_action);
__swab32s(&hr->hr_archive_id);
__swab64s(&hr->hr_flags);
__swab32s(&hr->hr_itemcount);
__swab32s(&hr->hr_data_len);
}
void lustre_swab_update_buf(struct update_buf *ub)
{
__swab32s(&ub->ub_magic);
__swab32s(&ub->ub_count);
}
void lustre_swab_update_reply_buf(struct update_reply *ur)
{
int i;
__swab32s(&ur->ur_version);
__swab32s(&ur->ur_count);
for (i = 0; i < ur->ur_count; i++)
__swab32s(&ur->ur_lens[i]);
}
void lustre_swab_swap_layouts(struct mdc_swap_layouts *msl)
{
__swab64s(&msl->msl_flags);
}
