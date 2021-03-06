static int iscsi_sw_tcp_recv(read_descriptor_t *rd_desc, struct sk_buff *skb,
unsigned int offset, size_t len)
{
struct iscsi_conn *conn = rd_desc->arg.data;
unsigned int consumed, total_consumed = 0;
int status;
ISCSI_SW_TCP_DBG(conn, "in %d bytes\n", skb->len - offset);
do {
status = 0;
consumed = iscsi_tcp_recv_skb(conn, skb, offset, 0, &status);
offset += consumed;
total_consumed += consumed;
} while (consumed != 0 && status != ISCSI_TCP_SKB_DONE);
ISCSI_SW_TCP_DBG(conn, "read %d bytes status %d\n",
skb->len - offset, status);
return total_consumed;
}
static inline int iscsi_sw_sk_state_check(struct sock *sk)
{
struct iscsi_conn *conn = sk->sk_user_data;
if ((sk->sk_state == TCP_CLOSE_WAIT || sk->sk_state == TCP_CLOSE) &&
!atomic_read(&sk->sk_rmem_alloc)) {
ISCSI_SW_TCP_DBG(conn, "TCP_CLOSE|TCP_CLOSE_WAIT\n");
iscsi_conn_failure(conn, ISCSI_ERR_TCP_CONN_CLOSE);
return -ECONNRESET;
}
return 0;
}
static void iscsi_sw_tcp_data_ready(struct sock *sk, int flag)
{
struct iscsi_conn *conn;
struct iscsi_tcp_conn *tcp_conn;
read_descriptor_t rd_desc;
read_lock(&sk->sk_callback_lock);
conn = sk->sk_user_data;
if (!conn) {
read_unlock(&sk->sk_callback_lock);
return;
}
tcp_conn = conn->dd_data;
rd_desc.arg.data = conn;
rd_desc.count = 1;
tcp_read_sock(sk, &rd_desc, iscsi_sw_tcp_recv);
iscsi_sw_sk_state_check(sk);
iscsi_tcp_segment_unmap(&tcp_conn->in.segment);
read_unlock(&sk->sk_callback_lock);
}
static void iscsi_sw_tcp_state_change(struct sock *sk)
{
struct iscsi_tcp_conn *tcp_conn;
struct iscsi_sw_tcp_conn *tcp_sw_conn;
struct iscsi_conn *conn;
struct iscsi_session *session;
void (*old_state_change)(struct sock *);
read_lock(&sk->sk_callback_lock);
conn = sk->sk_user_data;
if (!conn) {
read_unlock(&sk->sk_callback_lock);
return;
}
session = conn->session;
iscsi_sw_sk_state_check(sk);
tcp_conn = conn->dd_data;
tcp_sw_conn = tcp_conn->dd_data;
old_state_change = tcp_sw_conn->old_state_change;
read_unlock(&sk->sk_callback_lock);
old_state_change(sk);
}
static void iscsi_sw_tcp_write_space(struct sock *sk)
{
struct iscsi_conn *conn;
struct iscsi_tcp_conn *tcp_conn;
struct iscsi_sw_tcp_conn *tcp_sw_conn;
void (*old_write_space)(struct sock *);
read_lock_bh(&sk->sk_callback_lock);
conn = sk->sk_user_data;
if (!conn) {
read_unlock_bh(&sk->sk_callback_lock);
return;
}
tcp_conn = conn->dd_data;
tcp_sw_conn = tcp_conn->dd_data;
old_write_space = tcp_sw_conn->old_write_space;
read_unlock_bh(&sk->sk_callback_lock);
old_write_space(sk);
ISCSI_SW_TCP_DBG(conn, "iscsi_write_space\n");
iscsi_conn_queue_work(conn);
}
static void iscsi_sw_tcp_conn_set_callbacks(struct iscsi_conn *conn)
{
struct iscsi_tcp_conn *tcp_conn = conn->dd_data;
struct iscsi_sw_tcp_conn *tcp_sw_conn = tcp_conn->dd_data;
struct sock *sk = tcp_sw_conn->sock->sk;
write_lock_bh(&sk->sk_callback_lock);
sk->sk_user_data = conn;
tcp_sw_conn->old_data_ready = sk->sk_data_ready;
tcp_sw_conn->old_state_change = sk->sk_state_change;
tcp_sw_conn->old_write_space = sk->sk_write_space;
sk->sk_data_ready = iscsi_sw_tcp_data_ready;
sk->sk_state_change = iscsi_sw_tcp_state_change;
sk->sk_write_space = iscsi_sw_tcp_write_space;
write_unlock_bh(&sk->sk_callback_lock);
}
static void
iscsi_sw_tcp_conn_restore_callbacks(struct iscsi_conn *conn)
{
struct iscsi_tcp_conn *tcp_conn = conn->dd_data;
struct iscsi_sw_tcp_conn *tcp_sw_conn = tcp_conn->dd_data;
struct sock *sk = tcp_sw_conn->sock->sk;
write_lock_bh(&sk->sk_callback_lock);
sk->sk_user_data = NULL;
sk->sk_data_ready = tcp_sw_conn->old_data_ready;
sk->sk_state_change = tcp_sw_conn->old_state_change;
sk->sk_write_space = tcp_sw_conn->old_write_space;
sk->sk_no_check = 0;
write_unlock_bh(&sk->sk_callback_lock);
}
static int iscsi_sw_tcp_xmit_segment(struct iscsi_tcp_conn *tcp_conn,
struct iscsi_segment *segment)
{
struct iscsi_sw_tcp_conn *tcp_sw_conn = tcp_conn->dd_data;
struct socket *sk = tcp_sw_conn->sock;
unsigned int copied = 0;
int r = 0;
while (!iscsi_tcp_segment_done(tcp_conn, segment, 0, r)) {
struct scatterlist *sg;
unsigned int offset, copy;
int flags = 0;
r = 0;
offset = segment->copied;
copy = segment->size - offset;
if (segment->total_copied + segment->size < segment->total_size)
flags |= MSG_MORE;
if (!segment->data) {
sg = segment->sg;
offset += segment->sg_offset + sg->offset;
r = tcp_sw_conn->sendpage(sk, sg_page(sg), offset,
copy, flags);
} else {
struct msghdr msg = { .msg_flags = flags };
struct kvec iov = {
.iov_base = segment->data + offset,
.iov_len = copy
};
r = kernel_sendmsg(sk, &msg, &iov, 1, copy);
}
if (r < 0) {
iscsi_tcp_segment_unmap(segment);
return r;
}
copied += r;
}
return copied;
}
static int iscsi_sw_tcp_xmit(struct iscsi_conn *conn)
{
struct iscsi_tcp_conn *tcp_conn = conn->dd_data;
struct iscsi_sw_tcp_conn *tcp_sw_conn = tcp_conn->dd_data;
struct iscsi_segment *segment = &tcp_sw_conn->out.segment;
unsigned int consumed = 0;
int rc = 0;
while (1) {
rc = iscsi_sw_tcp_xmit_segment(tcp_conn, segment);
if (rc == -EAGAIN)
return rc;
else if (rc < 0) {
rc = ISCSI_ERR_XMIT_FAILED;
goto error;
} else if (rc == 0)
break;
consumed += rc;
if (segment->total_copied >= segment->total_size) {
if (segment->done != NULL) {
rc = segment->done(tcp_conn, segment);
if (rc != 0)
goto error;
}
}
}
ISCSI_SW_TCP_DBG(conn, "xmit %d bytes\n", consumed);
conn->txdata_octets += consumed;
return consumed;
error:
ISCSI_SW_TCP_DBG(conn, "Error sending PDU, errno=%d\n", rc);
iscsi_conn_failure(conn, rc);
return -EIO;
}
static inline int iscsi_sw_tcp_xmit_qlen(struct iscsi_conn *conn)
{
struct iscsi_tcp_conn *tcp_conn = conn->dd_data;
struct iscsi_sw_tcp_conn *tcp_sw_conn = tcp_conn->dd_data;
struct iscsi_segment *segment = &tcp_sw_conn->out.segment;
return segment->total_copied - segment->total_size;
}
static int iscsi_sw_tcp_pdu_xmit(struct iscsi_task *task)
{
struct iscsi_conn *conn = task->conn;
int rc;
while (iscsi_sw_tcp_xmit_qlen(conn)) {
rc = iscsi_sw_tcp_xmit(conn);
if (rc == 0)
return -EAGAIN;
if (rc < 0)
return rc;
}
return 0;
}
static int iscsi_sw_tcp_send_hdr_done(struct iscsi_tcp_conn *tcp_conn,
struct iscsi_segment *segment)
{
struct iscsi_sw_tcp_conn *tcp_sw_conn = tcp_conn->dd_data;
tcp_sw_conn->out.segment = tcp_sw_conn->out.data_segment;
ISCSI_SW_TCP_DBG(tcp_conn->iscsi_conn,
"Header done. Next segment size %u total_size %u\n",
tcp_sw_conn->out.segment.size,
tcp_sw_conn->out.segment.total_size);
return 0;
}
static void iscsi_sw_tcp_send_hdr_prep(struct iscsi_conn *conn, void *hdr,
size_t hdrlen)
{
struct iscsi_tcp_conn *tcp_conn = conn->dd_data;
struct iscsi_sw_tcp_conn *tcp_sw_conn = tcp_conn->dd_data;
ISCSI_SW_TCP_DBG(conn, "%s\n", conn->hdrdgst_en ?
"digest enabled" : "digest disabled");
memset(&tcp_sw_conn->out.data_segment, 0,
sizeof(struct iscsi_segment));
if (conn->hdrdgst_en) {
iscsi_tcp_dgst_header(&tcp_sw_conn->tx_hash, hdr, hdrlen,
hdr + hdrlen);
hdrlen += ISCSI_DIGEST_SIZE;
}
tcp_sw_conn->out.hdr = hdr;
iscsi_segment_init_linear(&tcp_sw_conn->out.segment, hdr, hdrlen,
iscsi_sw_tcp_send_hdr_done, NULL);
}
static int
iscsi_sw_tcp_send_data_prep(struct iscsi_conn *conn, struct scatterlist *sg,
unsigned int count, unsigned int offset,
unsigned int len)
{
struct iscsi_tcp_conn *tcp_conn = conn->dd_data;
struct iscsi_sw_tcp_conn *tcp_sw_conn = tcp_conn->dd_data;
struct hash_desc *tx_hash = NULL;
unsigned int hdr_spec_len;
ISCSI_SW_TCP_DBG(conn, "offset=%d, datalen=%d %s\n", offset, len,
conn->datadgst_en ?
"digest enabled" : "digest disabled");
hdr_spec_len = ntoh24(tcp_sw_conn->out.hdr->dlength);
WARN_ON(iscsi_padded(len) != iscsi_padded(hdr_spec_len));
if (conn->datadgst_en)
tx_hash = &tcp_sw_conn->tx_hash;
return iscsi_segment_seek_sg(&tcp_sw_conn->out.data_segment,
sg, count, offset, len,
NULL, tx_hash);
}
static void
iscsi_sw_tcp_send_linear_data_prep(struct iscsi_conn *conn, void *data,
size_t len)
{
struct iscsi_tcp_conn *tcp_conn = conn->dd_data;
struct iscsi_sw_tcp_conn *tcp_sw_conn = tcp_conn->dd_data;
struct hash_desc *tx_hash = NULL;
unsigned int hdr_spec_len;
ISCSI_SW_TCP_DBG(conn, "datalen=%zd %s\n", len, conn->datadgst_en ?
"digest enabled" : "digest disabled");
hdr_spec_len = ntoh24(tcp_sw_conn->out.hdr->dlength);
WARN_ON(iscsi_padded(len) != iscsi_padded(hdr_spec_len));
if (conn->datadgst_en)
tx_hash = &tcp_sw_conn->tx_hash;
iscsi_segment_init_linear(&tcp_sw_conn->out.data_segment,
data, len, NULL, tx_hash);
}
static int iscsi_sw_tcp_pdu_init(struct iscsi_task *task,
unsigned int offset, unsigned int count)
{
struct iscsi_conn *conn = task->conn;
int err = 0;
iscsi_sw_tcp_send_hdr_prep(conn, task->hdr, task->hdr_len);
if (!count)
return 0;
if (!task->sc)
iscsi_sw_tcp_send_linear_data_prep(conn, task->data, count);
else {
struct scsi_data_buffer *sdb = scsi_out(task->sc);
err = iscsi_sw_tcp_send_data_prep(conn, sdb->table.sgl,
sdb->table.nents, offset,
count);
}
if (err) {
return -EIO;
}
return 0;
}
static int iscsi_sw_tcp_pdu_alloc(struct iscsi_task *task, uint8_t opcode)
{
struct iscsi_tcp_task *tcp_task = task->dd_data;
task->hdr = task->dd_data + sizeof(*tcp_task);
task->hdr_max = sizeof(struct iscsi_sw_tcp_hdrbuf) - ISCSI_DIGEST_SIZE;
return 0;
}
static struct iscsi_cls_conn *
iscsi_sw_tcp_conn_create(struct iscsi_cls_session *cls_session,
uint32_t conn_idx)
{
struct iscsi_conn *conn;
struct iscsi_cls_conn *cls_conn;
struct iscsi_tcp_conn *tcp_conn;
struct iscsi_sw_tcp_conn *tcp_sw_conn;
cls_conn = iscsi_tcp_conn_setup(cls_session, sizeof(*tcp_sw_conn),
conn_idx);
if (!cls_conn)
return NULL;
conn = cls_conn->dd_data;
tcp_conn = conn->dd_data;
tcp_sw_conn = tcp_conn->dd_data;
tcp_sw_conn->tx_hash.tfm = crypto_alloc_hash("crc32c", 0,
CRYPTO_ALG_ASYNC);
tcp_sw_conn->tx_hash.flags = 0;
if (IS_ERR(tcp_sw_conn->tx_hash.tfm))
goto free_conn;
tcp_sw_conn->rx_hash.tfm = crypto_alloc_hash("crc32c", 0,
CRYPTO_ALG_ASYNC);
tcp_sw_conn->rx_hash.flags = 0;
if (IS_ERR(tcp_sw_conn->rx_hash.tfm))
goto free_tx_tfm;
tcp_conn->rx_hash = &tcp_sw_conn->rx_hash;
return cls_conn;
free_tx_tfm:
crypto_free_hash(tcp_sw_conn->tx_hash.tfm);
free_conn:
iscsi_conn_printk(KERN_ERR, conn,
"Could not create connection due to crc32c "
"loading error. Make sure the crc32c "
"module is built as a module or into the "
"kernel\n");
iscsi_tcp_conn_teardown(cls_conn);
return NULL;
}
static void iscsi_sw_tcp_release_conn(struct iscsi_conn *conn)
{
struct iscsi_session *session = conn->session;
struct iscsi_tcp_conn *tcp_conn = conn->dd_data;
struct iscsi_sw_tcp_conn *tcp_sw_conn = tcp_conn->dd_data;
struct socket *sock = tcp_sw_conn->sock;
if (!sock)
return;
sock_hold(sock->sk);
iscsi_sw_tcp_conn_restore_callbacks(conn);
sock_put(sock->sk);
spin_lock_bh(&session->lock);
tcp_sw_conn->sock = NULL;
spin_unlock_bh(&session->lock);
sockfd_put(sock);
}
static void iscsi_sw_tcp_conn_destroy(struct iscsi_cls_conn *cls_conn)
{
struct iscsi_conn *conn = cls_conn->dd_data;
struct iscsi_tcp_conn *tcp_conn = conn->dd_data;
struct iscsi_sw_tcp_conn *tcp_sw_conn = tcp_conn->dd_data;
iscsi_sw_tcp_release_conn(conn);
if (tcp_sw_conn->tx_hash.tfm)
crypto_free_hash(tcp_sw_conn->tx_hash.tfm);
if (tcp_sw_conn->rx_hash.tfm)
crypto_free_hash(tcp_sw_conn->rx_hash.tfm);
iscsi_tcp_conn_teardown(cls_conn);
}
static void iscsi_sw_tcp_conn_stop(struct iscsi_cls_conn *cls_conn, int flag)
{
struct iscsi_conn *conn = cls_conn->dd_data;
struct iscsi_tcp_conn *tcp_conn = conn->dd_data;
struct iscsi_sw_tcp_conn *tcp_sw_conn = tcp_conn->dd_data;
struct socket *sock = tcp_sw_conn->sock;
if (!sock)
return;
sock->sk->sk_err = EIO;
wake_up_interruptible(sk_sleep(sock->sk));
iscsi_suspend_tx(conn);
iscsi_sw_tcp_release_conn(conn);
iscsi_conn_stop(cls_conn, flag);
}
static int
iscsi_sw_tcp_conn_bind(struct iscsi_cls_session *cls_session,
struct iscsi_cls_conn *cls_conn, uint64_t transport_eph,
int is_leading)
{
struct iscsi_session *session = cls_session->dd_data;
struct iscsi_conn *conn = cls_conn->dd_data;
struct iscsi_tcp_conn *tcp_conn = conn->dd_data;
struct iscsi_sw_tcp_conn *tcp_sw_conn = tcp_conn->dd_data;
struct sock *sk;
struct socket *sock;
int err;
sock = sockfd_lookup((int)transport_eph, &err);
if (!sock) {
iscsi_conn_printk(KERN_ERR, conn,
"sockfd_lookup failed %d\n", err);
return -EEXIST;
}
err = iscsi_conn_bind(cls_session, cls_conn, is_leading);
if (err)
goto free_socket;
spin_lock_bh(&session->lock);
tcp_sw_conn->sock = sock;
spin_unlock_bh(&session->lock);
sk = sock->sk;
sk->sk_reuse = 1;
sk->sk_sndtimeo = 15 * HZ;
sk->sk_allocation = GFP_ATOMIC;
iscsi_sw_tcp_conn_set_callbacks(conn);
tcp_sw_conn->sendpage = tcp_sw_conn->sock->ops->sendpage;
iscsi_tcp_hdr_recv_prep(tcp_conn);
return 0;
free_socket:
sockfd_put(sock);
return err;
}
static int iscsi_sw_tcp_conn_set_param(struct iscsi_cls_conn *cls_conn,
enum iscsi_param param, char *buf,
int buflen)
{
struct iscsi_conn *conn = cls_conn->dd_data;
struct iscsi_session *session = conn->session;
struct iscsi_tcp_conn *tcp_conn = conn->dd_data;
struct iscsi_sw_tcp_conn *tcp_sw_conn = tcp_conn->dd_data;
int value;
switch(param) {
case ISCSI_PARAM_HDRDGST_EN:
iscsi_set_param(cls_conn, param, buf, buflen);
break;
case ISCSI_PARAM_DATADGST_EN:
iscsi_set_param(cls_conn, param, buf, buflen);
tcp_sw_conn->sendpage = conn->datadgst_en ?
sock_no_sendpage : tcp_sw_conn->sock->ops->sendpage;
break;
case ISCSI_PARAM_MAX_R2T:
sscanf(buf, "%d", &value);
if (value <= 0 || !is_power_of_2(value))
return -EINVAL;
if (session->max_r2t == value)
break;
iscsi_tcp_r2tpool_free(session);
iscsi_set_param(cls_conn, param, buf, buflen);
if (iscsi_tcp_r2tpool_alloc(session))
return -ENOMEM;
break;
default:
return iscsi_set_param(cls_conn, param, buf, buflen);
}
return 0;
}
static int iscsi_sw_tcp_conn_get_param(struct iscsi_cls_conn *cls_conn,
enum iscsi_param param, char *buf)
{
struct iscsi_conn *conn = cls_conn->dd_data;
struct iscsi_tcp_conn *tcp_conn = conn->dd_data;
struct iscsi_sw_tcp_conn *tcp_sw_conn = tcp_conn->dd_data;
struct sockaddr_in6 addr;
int rc, len;
switch(param) {
case ISCSI_PARAM_CONN_PORT:
case ISCSI_PARAM_CONN_ADDRESS:
spin_lock_bh(&conn->session->lock);
if (!tcp_sw_conn || !tcp_sw_conn->sock) {
spin_unlock_bh(&conn->session->lock);
return -ENOTCONN;
}
rc = kernel_getpeername(tcp_sw_conn->sock,
(struct sockaddr *)&addr, &len);
spin_unlock_bh(&conn->session->lock);
if (rc)
return rc;
return iscsi_conn_get_addr_param((struct sockaddr_storage *)
&addr, param, buf);
default:
return iscsi_conn_get_param(cls_conn, param, buf);
}
return 0;
}
static int iscsi_sw_tcp_host_get_param(struct Scsi_Host *shost,
enum iscsi_host_param param, char *buf)
{
struct iscsi_sw_tcp_host *tcp_sw_host = iscsi_host_priv(shost);
struct iscsi_session *session = tcp_sw_host->session;
struct iscsi_conn *conn;
struct iscsi_tcp_conn *tcp_conn;
struct iscsi_sw_tcp_conn *tcp_sw_conn;
struct sockaddr_in6 addr;
int rc, len;
switch (param) {
case ISCSI_HOST_PARAM_IPADDRESS:
spin_lock_bh(&session->lock);
conn = session->leadconn;
if (!conn) {
spin_unlock_bh(&session->lock);
return -ENOTCONN;
}
tcp_conn = conn->dd_data;
tcp_sw_conn = tcp_conn->dd_data;
if (!tcp_sw_conn->sock) {
spin_unlock_bh(&session->lock);
return -ENOTCONN;
}
rc = kernel_getsockname(tcp_sw_conn->sock,
(struct sockaddr *)&addr, &len);
spin_unlock_bh(&session->lock);
if (rc)
return rc;
return iscsi_conn_get_addr_param((struct sockaddr_storage *)
&addr, param, buf);
default:
return iscsi_host_get_param(shost, param, buf);
}
return 0;
}
static void
iscsi_sw_tcp_conn_get_stats(struct iscsi_cls_conn *cls_conn,
struct iscsi_stats *stats)
{
struct iscsi_conn *conn = cls_conn->dd_data;
struct iscsi_tcp_conn *tcp_conn = conn->dd_data;
struct iscsi_sw_tcp_conn *tcp_sw_conn = tcp_conn->dd_data;
stats->custom_length = 3;
strcpy(stats->custom[0].desc, "tx_sendpage_failures");
stats->custom[0].value = tcp_sw_conn->sendpage_failures_cnt;
strcpy(stats->custom[1].desc, "rx_discontiguous_hdr");
stats->custom[1].value = tcp_sw_conn->discontiguous_hdr_cnt;
strcpy(stats->custom[2].desc, "eh_abort_cnt");
stats->custom[2].value = conn->eh_abort_cnt;
iscsi_tcp_conn_get_stats(cls_conn, stats);
}
static struct iscsi_cls_session *
iscsi_sw_tcp_session_create(struct iscsi_endpoint *ep, uint16_t cmds_max,
uint16_t qdepth, uint32_t initial_cmdsn)
{
struct iscsi_cls_session *cls_session;
struct iscsi_session *session;
struct iscsi_sw_tcp_host *tcp_sw_host;
struct Scsi_Host *shost;
if (ep) {
printk(KERN_ERR "iscsi_tcp: invalid ep %p.\n", ep);
return NULL;
}
shost = iscsi_host_alloc(&iscsi_sw_tcp_sht,
sizeof(struct iscsi_sw_tcp_host), 1);
if (!shost)
return NULL;
shost->transportt = iscsi_sw_tcp_scsi_transport;
shost->cmd_per_lun = qdepth;
shost->max_lun = iscsi_max_lun;
shost->max_id = 0;
shost->max_channel = 0;
shost->max_cmd_len = SCSI_MAX_VARLEN_CDB_SIZE;
if (iscsi_host_add(shost, NULL))
goto free_host;
cls_session = iscsi_session_setup(&iscsi_sw_tcp_transport, shost,
cmds_max, 0,
sizeof(struct iscsi_tcp_task) +
sizeof(struct iscsi_sw_tcp_hdrbuf),
initial_cmdsn, 0);
if (!cls_session)
goto remove_host;
session = cls_session->dd_data;
tcp_sw_host = iscsi_host_priv(shost);
tcp_sw_host->session = session;
shost->can_queue = session->scsi_cmds_max;
if (iscsi_tcp_r2tpool_alloc(session))
goto remove_session;
return cls_session;
remove_session:
iscsi_session_teardown(cls_session);
remove_host:
iscsi_host_remove(shost);
free_host:
iscsi_host_free(shost);
return NULL;
}
static void iscsi_sw_tcp_session_destroy(struct iscsi_cls_session *cls_session)
{
struct Scsi_Host *shost = iscsi_session_to_shost(cls_session);
iscsi_tcp_r2tpool_free(cls_session->dd_data);
iscsi_session_teardown(cls_session);
iscsi_host_remove(shost);
iscsi_host_free(shost);
}
static int iscsi_sw_tcp_slave_alloc(struct scsi_device *sdev)
{
set_bit(QUEUE_FLAG_BIDI, &sdev->request_queue->queue_flags);
return 0;
}
static int iscsi_sw_tcp_slave_configure(struct scsi_device *sdev)
{
blk_queue_bounce_limit(sdev->request_queue, BLK_BOUNCE_ANY);
blk_queue_dma_alignment(sdev->request_queue, 0);
return 0;
}
static int __init iscsi_sw_tcp_init(void)
{
if (iscsi_max_lun < 1) {
printk(KERN_ERR "iscsi_tcp: Invalid max_lun value of %u\n",
iscsi_max_lun);
return -EINVAL;
}
iscsi_sw_tcp_scsi_transport = iscsi_register_transport(
&iscsi_sw_tcp_transport);
if (!iscsi_sw_tcp_scsi_transport)
return -ENODEV;
return 0;
}
static void __exit iscsi_sw_tcp_exit(void)
{
iscsi_unregister_transport(&iscsi_sw_tcp_transport);
}
