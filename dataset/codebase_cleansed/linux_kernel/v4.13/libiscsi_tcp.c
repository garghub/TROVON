static inline void
iscsi_tcp_segment_init_sg(struct iscsi_segment *segment,
struct scatterlist *sg, unsigned int offset)
{
segment->sg = sg;
segment->sg_offset = offset;
segment->size = min(sg->length - offset,
segment->total_size - segment->total_copied);
segment->data = NULL;
}
static void iscsi_tcp_segment_map(struct iscsi_segment *segment, int recv)
{
struct scatterlist *sg;
if (segment->data != NULL || !segment->sg)
return;
sg = segment->sg;
BUG_ON(segment->sg_mapped);
BUG_ON(sg->length == 0);
if (page_count(sg_page(sg)) >= 1 && !recv)
return;
if (recv) {
segment->atomic_mapped = true;
segment->sg_mapped = kmap_atomic(sg_page(sg));
} else {
segment->atomic_mapped = false;
segment->sg_mapped = kmap(sg_page(sg));
}
segment->data = segment->sg_mapped + sg->offset + segment->sg_offset;
}
void iscsi_tcp_segment_unmap(struct iscsi_segment *segment)
{
if (segment->sg_mapped) {
if (segment->atomic_mapped)
kunmap_atomic(segment->sg_mapped);
else
kunmap(sg_page(segment->sg));
segment->sg_mapped = NULL;
segment->data = NULL;
}
}
static inline void
iscsi_tcp_segment_splice_digest(struct iscsi_segment *segment, void *digest)
{
segment->data = digest;
segment->digest_len = ISCSI_DIGEST_SIZE;
segment->total_size += ISCSI_DIGEST_SIZE;
segment->size = ISCSI_DIGEST_SIZE;
segment->copied = 0;
segment->sg = NULL;
segment->hash = NULL;
}
int iscsi_tcp_segment_done(struct iscsi_tcp_conn *tcp_conn,
struct iscsi_segment *segment, int recv,
unsigned copied)
{
struct scatterlist sg;
unsigned int pad;
ISCSI_DBG_TCP(tcp_conn->iscsi_conn, "copied %u %u size %u %s\n",
segment->copied, copied, segment->size,
recv ? "recv" : "xmit");
if (segment->hash && copied) {
iscsi_tcp_segment_unmap(segment);
if (!segment->data) {
sg_init_table(&sg, 1);
sg_set_page(&sg, sg_page(segment->sg), copied,
segment->copied + segment->sg_offset +
segment->sg->offset);
} else
sg_init_one(&sg, segment->data + segment->copied,
copied);
ahash_request_set_crypt(segment->hash, &sg, NULL, copied);
crypto_ahash_update(segment->hash);
}
segment->copied += copied;
if (segment->copied < segment->size) {
iscsi_tcp_segment_map(segment, recv);
return 0;
}
segment->total_copied += segment->copied;
segment->copied = 0;
segment->size = 0;
iscsi_tcp_segment_unmap(segment);
ISCSI_DBG_TCP(tcp_conn->iscsi_conn, "total copied %u total size %u\n",
segment->total_copied, segment->total_size);
if (segment->total_copied < segment->total_size) {
iscsi_tcp_segment_init_sg(segment, sg_next(segment->sg),
0);
iscsi_tcp_segment_map(segment, recv);
BUG_ON(segment->size == 0);
return 0;
}
if (!(tcp_conn->iscsi_conn->session->tt->caps & CAP_PADDING_OFFLOAD)) {
pad = iscsi_padding(segment->total_copied);
if (pad != 0) {
ISCSI_DBG_TCP(tcp_conn->iscsi_conn,
"consume %d pad bytes\n", pad);
segment->total_size += pad;
segment->size = pad;
segment->data = segment->padbuf;
return 0;
}
}
if (segment->hash) {
ahash_request_set_crypt(segment->hash, NULL,
segment->digest, 0);
crypto_ahash_final(segment->hash);
iscsi_tcp_segment_splice_digest(segment,
recv ? segment->recv_digest : segment->digest);
return 0;
}
return 1;
}
static int
iscsi_tcp_segment_recv(struct iscsi_tcp_conn *tcp_conn,
struct iscsi_segment *segment, const void *ptr,
unsigned int len)
{
unsigned int copy = 0, copied = 0;
while (!iscsi_tcp_segment_done(tcp_conn, segment, 1, copy)) {
if (copied == len) {
ISCSI_DBG_TCP(tcp_conn->iscsi_conn,
"copied %d bytes\n", len);
break;
}
copy = min(len - copied, segment->size - segment->copied);
ISCSI_DBG_TCP(tcp_conn->iscsi_conn, "copying %d\n", copy);
memcpy(segment->data + segment->copied, ptr + copied, copy);
copied += copy;
}
return copied;
}
inline void
iscsi_tcp_dgst_header(struct ahash_request *hash, const void *hdr,
size_t hdrlen, unsigned char digest[ISCSI_DIGEST_SIZE])
{
struct scatterlist sg;
sg_init_one(&sg, hdr, hdrlen);
ahash_request_set_crypt(hash, &sg, digest, hdrlen);
crypto_ahash_digest(hash);
}
static inline int
iscsi_tcp_dgst_verify(struct iscsi_tcp_conn *tcp_conn,
struct iscsi_segment *segment)
{
if (!segment->digest_len)
return 1;
if (memcmp(segment->recv_digest, segment->digest,
segment->digest_len)) {
ISCSI_DBG_TCP(tcp_conn->iscsi_conn, "digest mismatch\n");
return 0;
}
return 1;
}
static inline void
__iscsi_segment_init(struct iscsi_segment *segment, size_t size,
iscsi_segment_done_fn_t *done, struct ahash_request *hash)
{
memset(segment, 0, sizeof(*segment));
segment->total_size = size;
segment->done = done;
if (hash) {
segment->hash = hash;
crypto_ahash_init(hash);
}
}
inline void
iscsi_segment_init_linear(struct iscsi_segment *segment, void *data,
size_t size, iscsi_segment_done_fn_t *done,
struct ahash_request *hash)
{
__iscsi_segment_init(segment, size, done, hash);
segment->data = data;
segment->size = size;
}
inline int
iscsi_segment_seek_sg(struct iscsi_segment *segment,
struct scatterlist *sg_list, unsigned int sg_count,
unsigned int offset, size_t size,
iscsi_segment_done_fn_t *done,
struct ahash_request *hash)
{
struct scatterlist *sg;
unsigned int i;
__iscsi_segment_init(segment, size, done, hash);
for_each_sg(sg_list, sg, sg_count, i) {
if (offset < sg->length) {
iscsi_tcp_segment_init_sg(segment, sg, offset);
return 0;
}
offset -= sg->length;
}
return ISCSI_ERR_DATA_OFFSET;
}
void iscsi_tcp_hdr_recv_prep(struct iscsi_tcp_conn *tcp_conn)
{
ISCSI_DBG_TCP(tcp_conn->iscsi_conn,
"(%s)\n", tcp_conn->iscsi_conn->hdrdgst_en ?
"digest enabled" : "digest disabled");
iscsi_segment_init_linear(&tcp_conn->in.segment,
tcp_conn->in.hdr_buf, sizeof(struct iscsi_hdr),
iscsi_tcp_hdr_recv_done, NULL);
}
static int
iscsi_tcp_data_recv_done(struct iscsi_tcp_conn *tcp_conn,
struct iscsi_segment *segment)
{
struct iscsi_conn *conn = tcp_conn->iscsi_conn;
int rc = 0;
if (!iscsi_tcp_dgst_verify(tcp_conn, segment))
return ISCSI_ERR_DATA_DGST;
rc = iscsi_complete_pdu(conn, tcp_conn->in.hdr,
conn->data, tcp_conn->in.datalen);
if (rc)
return rc;
iscsi_tcp_hdr_recv_prep(tcp_conn);
return 0;
}
static void
iscsi_tcp_data_recv_prep(struct iscsi_tcp_conn *tcp_conn)
{
struct iscsi_conn *conn = tcp_conn->iscsi_conn;
struct ahash_request *rx_hash = NULL;
if (conn->datadgst_en &&
!(conn->session->tt->caps & CAP_DIGEST_OFFLOAD))
rx_hash = tcp_conn->rx_hash;
iscsi_segment_init_linear(&tcp_conn->in.segment,
conn->data, tcp_conn->in.datalen,
iscsi_tcp_data_recv_done, rx_hash);
}
void iscsi_tcp_cleanup_task(struct iscsi_task *task)
{
struct iscsi_tcp_task *tcp_task = task->dd_data;
struct iscsi_r2t_info *r2t;
if (!task->sc)
return;
spin_lock_bh(&tcp_task->queue2pool);
while (kfifo_out(&tcp_task->r2tqueue, (void*)&r2t, sizeof(void*))) {
kfifo_in(&tcp_task->r2tpool.queue, (void*)&r2t,
sizeof(void*));
ISCSI_DBG_TCP(task->conn, "pending r2t dropped\n");
}
r2t = tcp_task->r2t;
if (r2t != NULL) {
kfifo_in(&tcp_task->r2tpool.queue, (void*)&r2t,
sizeof(void*));
tcp_task->r2t = NULL;
}
spin_unlock_bh(&tcp_task->queue2pool);
}
static int iscsi_tcp_data_in(struct iscsi_conn *conn, struct iscsi_task *task)
{
struct iscsi_tcp_conn *tcp_conn = conn->dd_data;
struct iscsi_tcp_task *tcp_task = task->dd_data;
struct iscsi_data_rsp *rhdr = (struct iscsi_data_rsp *)tcp_conn->in.hdr;
int datasn = be32_to_cpu(rhdr->datasn);
unsigned total_in_length = scsi_in(task->sc)->length;
if (!(rhdr->flags & ISCSI_FLAG_DATA_STATUS))
iscsi_update_cmdsn(conn->session, (struct iscsi_nopin*)rhdr);
if (tcp_conn->in.datalen == 0)
return 0;
if (tcp_task->exp_datasn != datasn) {
ISCSI_DBG_TCP(conn, "task->exp_datasn(%d) != rhdr->datasn(%d)"
"\n", tcp_task->exp_datasn, datasn);
return ISCSI_ERR_DATASN;
}
tcp_task->exp_datasn++;
tcp_task->data_offset = be32_to_cpu(rhdr->offset);
if (tcp_task->data_offset + tcp_conn->in.datalen > total_in_length) {
ISCSI_DBG_TCP(conn, "data_offset(%d) + data_len(%d) > "
"total_length_in(%d)\n", tcp_task->data_offset,
tcp_conn->in.datalen, total_in_length);
return ISCSI_ERR_DATA_OFFSET;
}
conn->datain_pdus_cnt++;
return 0;
}
static int iscsi_tcp_r2t_rsp(struct iscsi_conn *conn, struct iscsi_task *task)
{
struct iscsi_session *session = conn->session;
struct iscsi_tcp_task *tcp_task = task->dd_data;
struct iscsi_tcp_conn *tcp_conn = conn->dd_data;
struct iscsi_r2t_rsp *rhdr = (struct iscsi_r2t_rsp *)tcp_conn->in.hdr;
struct iscsi_r2t_info *r2t;
int r2tsn = be32_to_cpu(rhdr->r2tsn);
u32 data_length;
u32 data_offset;
int rc;
if (tcp_conn->in.datalen) {
iscsi_conn_printk(KERN_ERR, conn,
"invalid R2t with datalen %d\n",
tcp_conn->in.datalen);
return ISCSI_ERR_DATALEN;
}
if (tcp_task->exp_datasn != r2tsn){
ISCSI_DBG_TCP(conn, "task->exp_datasn(%d) != rhdr->r2tsn(%d)\n",
tcp_task->exp_datasn, r2tsn);
return ISCSI_ERR_R2TSN;
}
iscsi_update_cmdsn(session, (struct iscsi_nopin*)rhdr);
if (!task->sc || session->state != ISCSI_STATE_LOGGED_IN) {
iscsi_conn_printk(KERN_INFO, conn,
"dropping R2T itt %d in recovery.\n",
task->itt);
return 0;
}
data_length = be32_to_cpu(rhdr->data_length);
if (data_length == 0) {
iscsi_conn_printk(KERN_ERR, conn,
"invalid R2T with zero data len\n");
return ISCSI_ERR_DATALEN;
}
if (data_length > session->max_burst)
ISCSI_DBG_TCP(conn, "invalid R2T with data len %u and max "
"burst %u. Attempting to execute request.\n",
data_length, session->max_burst);
data_offset = be32_to_cpu(rhdr->data_offset);
if (data_offset + data_length > scsi_out(task->sc)->length) {
iscsi_conn_printk(KERN_ERR, conn,
"invalid R2T with data len %u at offset %u "
"and total length %d\n", data_length,
data_offset, scsi_out(task->sc)->length);
return ISCSI_ERR_DATALEN;
}
spin_lock(&tcp_task->pool2queue);
rc = kfifo_out(&tcp_task->r2tpool.queue, (void *)&r2t, sizeof(void *));
if (!rc) {
iscsi_conn_printk(KERN_ERR, conn, "Could not allocate R2T. "
"Target has sent more R2Ts than it "
"negotiated for or driver has leaked.\n");
spin_unlock(&tcp_task->pool2queue);
return ISCSI_ERR_PROTO;
}
r2t->exp_statsn = rhdr->statsn;
r2t->data_length = data_length;
r2t->data_offset = data_offset;
r2t->ttt = rhdr->ttt;
r2t->datasn = 0;
r2t->sent = 0;
tcp_task->exp_datasn = r2tsn + 1;
kfifo_in(&tcp_task->r2tqueue, (void*)&r2t, sizeof(void*));
conn->r2t_pdus_cnt++;
spin_unlock(&tcp_task->pool2queue);
iscsi_requeue_task(task);
return 0;
}
static int
iscsi_tcp_process_data_in(struct iscsi_tcp_conn *tcp_conn,
struct iscsi_segment *segment)
{
struct iscsi_conn *conn = tcp_conn->iscsi_conn;
struct iscsi_hdr *hdr = tcp_conn->in.hdr;
int rc;
if (!iscsi_tcp_dgst_verify(tcp_conn, segment))
return ISCSI_ERR_DATA_DGST;
if (hdr->flags & ISCSI_FLAG_DATA_STATUS) {
rc = iscsi_complete_pdu(conn, tcp_conn->in.hdr, NULL, 0);
if (rc)
return rc;
}
iscsi_tcp_hdr_recv_prep(tcp_conn);
return 0;
}
static int
iscsi_tcp_hdr_dissect(struct iscsi_conn *conn, struct iscsi_hdr *hdr)
{
int rc = 0, opcode, ahslen;
struct iscsi_tcp_conn *tcp_conn = conn->dd_data;
struct iscsi_task *task;
tcp_conn->in.datalen = ntoh24(hdr->dlength);
if (tcp_conn->in.datalen > conn->max_recv_dlength) {
iscsi_conn_printk(KERN_ERR, conn,
"iscsi_tcp: datalen %d > %d\n",
tcp_conn->in.datalen, conn->max_recv_dlength);
return ISCSI_ERR_DATALEN;
}
ahslen = hdr->hlength << 2;
opcode = hdr->opcode & ISCSI_OPCODE_MASK;
rc = iscsi_verify_itt(conn, hdr->itt);
if (rc)
return rc;
ISCSI_DBG_TCP(conn, "opcode 0x%x ahslen %d datalen %d\n",
opcode, ahslen, tcp_conn->in.datalen);
switch(opcode) {
case ISCSI_OP_SCSI_DATA_IN:
spin_lock(&conn->session->back_lock);
task = iscsi_itt_to_ctask(conn, hdr->itt);
if (!task)
rc = ISCSI_ERR_BAD_ITT;
else
rc = iscsi_tcp_data_in(conn, task);
if (rc) {
spin_unlock(&conn->session->back_lock);
break;
}
if (tcp_conn->in.datalen) {
struct iscsi_tcp_task *tcp_task = task->dd_data;
struct ahash_request *rx_hash = NULL;
struct scsi_data_buffer *sdb = scsi_in(task->sc);
if (conn->datadgst_en &&
!(conn->session->tt->caps & CAP_DIGEST_OFFLOAD))
rx_hash = tcp_conn->rx_hash;
ISCSI_DBG_TCP(conn, "iscsi_tcp_begin_data_in( "
"offset=%d, datalen=%d)\n",
tcp_task->data_offset,
tcp_conn->in.datalen);
task->last_xfer = jiffies;
rc = iscsi_segment_seek_sg(&tcp_conn->in.segment,
sdb->table.sgl,
sdb->table.nents,
tcp_task->data_offset,
tcp_conn->in.datalen,
iscsi_tcp_process_data_in,
rx_hash);
spin_unlock(&conn->session->back_lock);
return rc;
}
rc = __iscsi_complete_pdu(conn, hdr, NULL, 0);
spin_unlock(&conn->session->back_lock);
break;
case ISCSI_OP_SCSI_CMD_RSP:
if (tcp_conn->in.datalen) {
iscsi_tcp_data_recv_prep(tcp_conn);
return 0;
}
rc = iscsi_complete_pdu(conn, hdr, NULL, 0);
break;
case ISCSI_OP_R2T:
spin_lock(&conn->session->back_lock);
task = iscsi_itt_to_ctask(conn, hdr->itt);
spin_unlock(&conn->session->back_lock);
if (!task)
rc = ISCSI_ERR_BAD_ITT;
else if (ahslen)
rc = ISCSI_ERR_AHSLEN;
else if (task->sc->sc_data_direction == DMA_TO_DEVICE) {
task->last_xfer = jiffies;
spin_lock(&conn->session->frwd_lock);
rc = iscsi_tcp_r2t_rsp(conn, task);
spin_unlock(&conn->session->frwd_lock);
} else
rc = ISCSI_ERR_PROTO;
break;
case ISCSI_OP_LOGIN_RSP:
case ISCSI_OP_TEXT_RSP:
case ISCSI_OP_REJECT:
case ISCSI_OP_ASYNC_EVENT:
if (ISCSI_DEF_MAX_RECV_SEG_LEN < tcp_conn->in.datalen) {
iscsi_conn_printk(KERN_ERR, conn,
"iscsi_tcp: received buffer of "
"len %u but conn buffer is only %u "
"(opcode %0x)\n",
tcp_conn->in.datalen,
ISCSI_DEF_MAX_RECV_SEG_LEN, opcode);
rc = ISCSI_ERR_PROTO;
break;
}
if (tcp_conn->in.datalen) {
iscsi_tcp_data_recv_prep(tcp_conn);
return 0;
}
case ISCSI_OP_LOGOUT_RSP:
case ISCSI_OP_NOOP_IN:
case ISCSI_OP_SCSI_TMFUNC_RSP:
rc = iscsi_complete_pdu(conn, hdr, NULL, 0);
break;
default:
rc = ISCSI_ERR_BAD_OPCODE;
break;
}
if (rc == 0) {
if (tcp_conn->in.datalen)
return ISCSI_ERR_PROTO;
iscsi_tcp_hdr_recv_prep(tcp_conn);
}
return rc;
}
static int
iscsi_tcp_hdr_recv_done(struct iscsi_tcp_conn *tcp_conn,
struct iscsi_segment *segment)
{
struct iscsi_conn *conn = tcp_conn->iscsi_conn;
struct iscsi_hdr *hdr;
hdr = (struct iscsi_hdr *) tcp_conn->in.hdr_buf;
if (segment->copied == sizeof(struct iscsi_hdr) && hdr->hlength) {
unsigned int ahslen = hdr->hlength << 2;
if (sizeof(*hdr) + ahslen > sizeof(tcp_conn->in.hdr_buf))
return ISCSI_ERR_AHSLEN;
segment->total_size += ahslen;
segment->size += ahslen;
return 0;
}
if (conn->hdrdgst_en &&
!(conn->session->tt->caps & CAP_DIGEST_OFFLOAD)) {
if (segment->digest_len == 0) {
iscsi_tcp_segment_splice_digest(segment,
segment->recv_digest);
return 0;
}
iscsi_tcp_dgst_header(tcp_conn->rx_hash, hdr,
segment->total_copied - ISCSI_DIGEST_SIZE,
segment->digest);
if (!iscsi_tcp_dgst_verify(tcp_conn, segment))
return ISCSI_ERR_HDR_DGST;
}
tcp_conn->in.hdr = hdr;
return iscsi_tcp_hdr_dissect(conn, hdr);
}
inline int iscsi_tcp_recv_segment_is_hdr(struct iscsi_tcp_conn *tcp_conn)
{
return tcp_conn->in.segment.done == iscsi_tcp_hdr_recv_done;
}
int iscsi_tcp_recv_skb(struct iscsi_conn *conn, struct sk_buff *skb,
unsigned int offset, bool offloaded, int *status)
{
struct iscsi_tcp_conn *tcp_conn = conn->dd_data;
struct iscsi_segment *segment = &tcp_conn->in.segment;
struct skb_seq_state seq;
unsigned int consumed = 0;
int rc = 0;
ISCSI_DBG_TCP(conn, "in %d bytes\n", skb->len - offset);
conn->last_recv = jiffies;
if (unlikely(conn->suspend_rx)) {
ISCSI_DBG_TCP(conn, "Rx suspended!\n");
*status = ISCSI_TCP_SUSPENDED;
return 0;
}
if (offloaded) {
segment->total_copied = segment->total_size;
goto segment_done;
}
skb_prepare_seq_read(skb, offset, skb->len, &seq);
while (1) {
unsigned int avail;
const u8 *ptr;
avail = skb_seq_read(consumed, &ptr, &seq);
if (avail == 0) {
ISCSI_DBG_TCP(conn, "no more data avail. Consumed %d\n",
consumed);
*status = ISCSI_TCP_SKB_DONE;
goto skb_done;
}
BUG_ON(segment->copied >= segment->size);
ISCSI_DBG_TCP(conn, "skb %p ptr=%p avail=%u\n", skb, ptr,
avail);
rc = iscsi_tcp_segment_recv(tcp_conn, segment, ptr, avail);
BUG_ON(rc == 0);
consumed += rc;
if (segment->total_copied >= segment->total_size) {
skb_abort_seq_read(&seq);
goto segment_done;
}
}
segment_done:
*status = ISCSI_TCP_SEGMENT_DONE;
ISCSI_DBG_TCP(conn, "segment done\n");
rc = segment->done(tcp_conn, segment);
if (rc != 0) {
*status = ISCSI_TCP_CONN_ERR;
ISCSI_DBG_TCP(conn, "Error receiving PDU, errno=%d\n", rc);
iscsi_conn_failure(conn, rc);
return 0;
}
skb_done:
conn->rxdata_octets += consumed;
return consumed;
}
int iscsi_tcp_task_init(struct iscsi_task *task)
{
struct iscsi_tcp_task *tcp_task = task->dd_data;
struct iscsi_conn *conn = task->conn;
struct scsi_cmnd *sc = task->sc;
int err;
if (!sc) {
ISCSI_DBG_TCP(conn, "mtask deq [itt 0x%x]\n", task->itt);
return conn->session->tt->init_pdu(task, 0, task->data_count);
}
BUG_ON(kfifo_len(&tcp_task->r2tqueue));
tcp_task->exp_datasn = 0;
ISCSI_DBG_TCP(conn, "task deq [itt 0x%x imm %d unsol %d]\n",
task->itt, task->imm_count, task->unsol_r2t.data_length);
err = conn->session->tt->init_pdu(task, 0, task->imm_count);
if (err)
return err;
task->imm_count = 0;
return 0;
}
static struct iscsi_r2t_info *iscsi_tcp_get_curr_r2t(struct iscsi_task *task)
{
struct iscsi_tcp_task *tcp_task = task->dd_data;
struct iscsi_r2t_info *r2t = NULL;
if (iscsi_task_has_unsol_data(task))
r2t = &task->unsol_r2t;
else {
spin_lock_bh(&tcp_task->queue2pool);
if (tcp_task->r2t) {
r2t = tcp_task->r2t;
if (r2t->data_length <= r2t->sent) {
ISCSI_DBG_TCP(task->conn,
" done with r2t %p\n", r2t);
kfifo_in(&tcp_task->r2tpool.queue,
(void *)&tcp_task->r2t,
sizeof(void *));
tcp_task->r2t = r2t = NULL;
}
}
if (r2t == NULL) {
if (kfifo_out(&tcp_task->r2tqueue,
(void *)&tcp_task->r2t, sizeof(void *)) !=
sizeof(void *))
r2t = NULL;
else
r2t = tcp_task->r2t;
}
spin_unlock_bh(&tcp_task->queue2pool);
}
return r2t;
}
int iscsi_tcp_task_xmit(struct iscsi_task *task)
{
struct iscsi_conn *conn = task->conn;
struct iscsi_session *session = conn->session;
struct iscsi_r2t_info *r2t;
int rc = 0;
flush:
rc = session->tt->xmit_pdu(task);
if (rc < 0)
return rc;
if (!task->sc) {
if (task->hdr->itt == RESERVED_ITT)
iscsi_put_task(task);
return 0;
}
if (task->sc->sc_data_direction != DMA_TO_DEVICE)
return 0;
r2t = iscsi_tcp_get_curr_r2t(task);
if (r2t == NULL) {
ISCSI_DBG_TCP(conn, "no R2Ts yet\n");
return 0;
}
rc = conn->session->tt->alloc_pdu(task, ISCSI_OP_SCSI_DATA_OUT);
if (rc)
return rc;
iscsi_prep_data_out_pdu(task, r2t, (struct iscsi_data *) task->hdr);
ISCSI_DBG_TCP(conn, "sol dout %p [dsn %d itt 0x%x doff %d dlen %d]\n",
r2t, r2t->datasn - 1, task->hdr->itt,
r2t->data_offset + r2t->sent, r2t->data_count);
rc = conn->session->tt->init_pdu(task, r2t->data_offset + r2t->sent,
r2t->data_count);
if (rc) {
iscsi_conn_failure(conn, ISCSI_ERR_XMIT_FAILED);
return rc;
}
r2t->sent += r2t->data_count;
goto flush;
}
struct iscsi_cls_conn *
iscsi_tcp_conn_setup(struct iscsi_cls_session *cls_session, int dd_data_size,
uint32_t conn_idx)
{
struct iscsi_conn *conn;
struct iscsi_cls_conn *cls_conn;
struct iscsi_tcp_conn *tcp_conn;
cls_conn = iscsi_conn_setup(cls_session,
sizeof(*tcp_conn) + dd_data_size, conn_idx);
if (!cls_conn)
return NULL;
conn = cls_conn->dd_data;
conn->max_recv_dlength = ISCSI_DEF_MAX_RECV_SEG_LEN;
tcp_conn = conn->dd_data;
tcp_conn->iscsi_conn = conn;
tcp_conn->dd_data = conn->dd_data + sizeof(*tcp_conn);
return cls_conn;
}
void iscsi_tcp_conn_teardown(struct iscsi_cls_conn *cls_conn)
{
iscsi_conn_teardown(cls_conn);
}
int iscsi_tcp_r2tpool_alloc(struct iscsi_session *session)
{
int i;
int cmd_i;
for (cmd_i = 0; cmd_i < session->cmds_max; cmd_i++) {
struct iscsi_task *task = session->cmds[cmd_i];
struct iscsi_tcp_task *tcp_task = task->dd_data;
if (iscsi_pool_init(&tcp_task->r2tpool,
session->max_r2t * 2, NULL,
sizeof(struct iscsi_r2t_info))) {
goto r2t_alloc_fail;
}
if (kfifo_alloc(&tcp_task->r2tqueue,
session->max_r2t * 4 * sizeof(void*), GFP_KERNEL)) {
iscsi_pool_free(&tcp_task->r2tpool);
goto r2t_alloc_fail;
}
spin_lock_init(&tcp_task->pool2queue);
spin_lock_init(&tcp_task->queue2pool);
}
return 0;
r2t_alloc_fail:
for (i = 0; i < cmd_i; i++) {
struct iscsi_task *task = session->cmds[i];
struct iscsi_tcp_task *tcp_task = task->dd_data;
kfifo_free(&tcp_task->r2tqueue);
iscsi_pool_free(&tcp_task->r2tpool);
}
return -ENOMEM;
}
void iscsi_tcp_r2tpool_free(struct iscsi_session *session)
{
int i;
for (i = 0; i < session->cmds_max; i++) {
struct iscsi_task *task = session->cmds[i];
struct iscsi_tcp_task *tcp_task = task->dd_data;
kfifo_free(&tcp_task->r2tqueue);
iscsi_pool_free(&tcp_task->r2tpool);
}
}
int iscsi_tcp_set_max_r2t(struct iscsi_conn *conn, char *buf)
{
struct iscsi_session *session = conn->session;
unsigned short r2ts = 0;
sscanf(buf, "%hu", &r2ts);
if (session->max_r2t == r2ts)
return 0;
if (!r2ts || !is_power_of_2(r2ts))
return -EINVAL;
session->max_r2t = r2ts;
iscsi_tcp_r2tpool_free(session);
return iscsi_tcp_r2tpool_alloc(session);
}
void iscsi_tcp_conn_get_stats(struct iscsi_cls_conn *cls_conn,
struct iscsi_stats *stats)
{
struct iscsi_conn *conn = cls_conn->dd_data;
stats->txdata_octets = conn->txdata_octets;
stats->rxdata_octets = conn->rxdata_octets;
stats->scsicmd_pdus = conn->scsicmd_pdus_cnt;
stats->dataout_pdus = conn->dataout_pdus_cnt;
stats->scsirsp_pdus = conn->scsirsp_pdus_cnt;
stats->datain_pdus = conn->datain_pdus_cnt;
stats->r2t_pdus = conn->r2t_pdus_cnt;
stats->tmfcmd_pdus = conn->tmfcmd_pdus_cnt;
stats->tmfrsp_pdus = conn->tmfrsp_pdus_cnt;
}
