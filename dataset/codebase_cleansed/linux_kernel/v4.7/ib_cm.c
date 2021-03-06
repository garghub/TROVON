static void rds_ib_set_protocol(struct rds_connection *conn, unsigned int version)
{
conn->c_version = version;
}
static void rds_ib_set_flow_control(struct rds_connection *conn, u32 credits)
{
struct rds_ib_connection *ic = conn->c_transport_data;
if (rds_ib_sysctl_flow_control && credits != 0) {
ic->i_flowctl = 1;
rds_ib_send_add_credits(conn, credits);
} else {
ic->i_flowctl = 0;
}
}
static void
rds_ib_tune_rnr(struct rds_ib_connection *ic, struct ib_qp_attr *attr)
{
int ret;
attr->min_rnr_timer = IB_RNR_TIMER_000_32;
ret = ib_modify_qp(ic->i_cm_id->qp, attr, IB_QP_MIN_RNR_TIMER);
if (ret)
printk(KERN_NOTICE "ib_modify_qp(IB_QP_MIN_RNR_TIMER): err=%d\n", -ret);
}
void rds_ib_cm_connect_complete(struct rds_connection *conn, struct rdma_cm_event *event)
{
const struct rds_ib_connect_private *dp = NULL;
struct rds_ib_connection *ic = conn->c_transport_data;
struct ib_qp_attr qp_attr;
int err;
if (event->param.conn.private_data_len >= sizeof(*dp)) {
dp = event->param.conn.private_data;
if (dp->dp_protocol_major) {
rds_ib_set_protocol(conn,
RDS_PROTOCOL(dp->dp_protocol_major,
dp->dp_protocol_minor));
rds_ib_set_flow_control(conn, be32_to_cpu(dp->dp_credit));
}
}
if (conn->c_version < RDS_PROTOCOL(3, 1)) {
printk(KERN_NOTICE "RDS/IB: Connection to %pI4 version %u.%u failed,"
" no longer supported\n",
&conn->c_faddr,
RDS_PROTOCOL_MAJOR(conn->c_version),
RDS_PROTOCOL_MINOR(conn->c_version));
rds_conn_destroy(conn);
return;
} else {
printk(KERN_NOTICE "RDS/IB: connected to %pI4 version %u.%u%s\n",
&conn->c_faddr,
RDS_PROTOCOL_MAJOR(conn->c_version),
RDS_PROTOCOL_MINOR(conn->c_version),
ic->i_flowctl ? ", flow control" : "");
}
rds_ib_send_init_ring(ic);
rds_ib_recv_init_ring(ic);
rds_ib_recv_refill(conn, 1, GFP_KERNEL);
rds_ib_tune_rnr(ic, &qp_attr);
qp_attr.qp_state = IB_QPS_RTS;
err = ib_modify_qp(ic->i_cm_id->qp, &qp_attr, IB_QP_STATE);
if (err)
printk(KERN_NOTICE "ib_modify_qp(IB_QP_STATE, RTS): err=%d\n", err);
err = rds_ib_update_ipaddr(ic->rds_ibdev, conn->c_laddr);
if (err)
printk(KERN_ERR "rds_ib_update_ipaddr failed (%d)\n",
err);
if (dp) {
__be64 dp_ack_seq = get_unaligned(&dp->dp_ack_seq);
if (dp_ack_seq)
rds_send_drop_acked(conn, be64_to_cpu(dp_ack_seq),
NULL);
}
rds_connect_complete(conn);
}
static void rds_ib_cm_fill_conn_param(struct rds_connection *conn,
struct rdma_conn_param *conn_param,
struct rds_ib_connect_private *dp,
u32 protocol_version,
u32 max_responder_resources,
u32 max_initiator_depth)
{
struct rds_ib_connection *ic = conn->c_transport_data;
struct rds_ib_device *rds_ibdev = ic->rds_ibdev;
memset(conn_param, 0, sizeof(struct rdma_conn_param));
conn_param->responder_resources =
min_t(u32, rds_ibdev->max_responder_resources, max_responder_resources);
conn_param->initiator_depth =
min_t(u32, rds_ibdev->max_initiator_depth, max_initiator_depth);
conn_param->retry_count = min_t(unsigned int, rds_ib_retry_count, 7);
conn_param->rnr_retry_count = 7;
if (dp) {
memset(dp, 0, sizeof(*dp));
dp->dp_saddr = conn->c_laddr;
dp->dp_daddr = conn->c_faddr;
dp->dp_protocol_major = RDS_PROTOCOL_MAJOR(protocol_version);
dp->dp_protocol_minor = RDS_PROTOCOL_MINOR(protocol_version);
dp->dp_protocol_minor_mask = cpu_to_be16(RDS_IB_SUPPORTED_PROTOCOLS);
dp->dp_ack_seq = cpu_to_be64(rds_ib_piggyb_ack(ic));
if (ic->i_flowctl) {
unsigned int credits;
credits = IB_GET_POST_CREDITS(atomic_read(&ic->i_credits));
dp->dp_credit = cpu_to_be32(credits);
atomic_sub(IB_SET_POST_CREDITS(credits), &ic->i_credits);
}
conn_param->private_data = dp;
conn_param->private_data_len = sizeof(*dp);
}
}
static void rds_ib_cq_event_handler(struct ib_event *event, void *data)
{
rdsdebug("event %u (%s) data %p\n",
event->event, ib_event_msg(event->event), data);
}
static void rds_ib_cq_comp_handler_recv(struct ib_cq *cq, void *context)
{
struct rds_connection *conn = context;
struct rds_ib_connection *ic = conn->c_transport_data;
rdsdebug("conn %p cq %p\n", conn, cq);
rds_ib_stats_inc(s_ib_evt_handler_call);
tasklet_schedule(&ic->i_recv_tasklet);
}
static void poll_scq(struct rds_ib_connection *ic, struct ib_cq *cq,
struct ib_wc *wcs)
{
int nr, i;
struct ib_wc *wc;
while ((nr = ib_poll_cq(cq, RDS_IB_WC_MAX, wcs)) > 0) {
for (i = 0; i < nr; i++) {
wc = wcs + i;
rdsdebug("wc wr_id 0x%llx status %u byte_len %u imm_data %u\n",
(unsigned long long)wc->wr_id, wc->status,
wc->byte_len, be32_to_cpu(wc->ex.imm_data));
if (wc->wr_id <= ic->i_send_ring.w_nr ||
wc->wr_id == RDS_IB_ACK_WR_ID)
rds_ib_send_cqe_handler(ic, wc);
else
rds_ib_mr_cqe_handler(ic, wc);
}
}
}
static void rds_ib_tasklet_fn_send(unsigned long data)
{
struct rds_ib_connection *ic = (struct rds_ib_connection *)data;
struct rds_connection *conn = ic->conn;
rds_ib_stats_inc(s_ib_tasklet_call);
poll_scq(ic, ic->i_send_cq, ic->i_send_wc);
ib_req_notify_cq(ic->i_send_cq, IB_CQ_NEXT_COMP);
poll_scq(ic, ic->i_send_cq, ic->i_send_wc);
if (rds_conn_up(conn) &&
(!test_bit(RDS_LL_SEND_FULL, &conn->c_flags) ||
test_bit(0, &conn->c_map_queued)))
rds_send_xmit(ic->conn);
}
static void poll_rcq(struct rds_ib_connection *ic, struct ib_cq *cq,
struct ib_wc *wcs,
struct rds_ib_ack_state *ack_state)
{
int nr, i;
struct ib_wc *wc;
while ((nr = ib_poll_cq(cq, RDS_IB_WC_MAX, wcs)) > 0) {
for (i = 0; i < nr; i++) {
wc = wcs + i;
rdsdebug("wc wr_id 0x%llx status %u byte_len %u imm_data %u\n",
(unsigned long long)wc->wr_id, wc->status,
wc->byte_len, be32_to_cpu(wc->ex.imm_data));
rds_ib_recv_cqe_handler(ic, wc, ack_state);
}
}
}
static void rds_ib_tasklet_fn_recv(unsigned long data)
{
struct rds_ib_connection *ic = (struct rds_ib_connection *)data;
struct rds_connection *conn = ic->conn;
struct rds_ib_device *rds_ibdev = ic->rds_ibdev;
struct rds_ib_ack_state state;
if (!rds_ibdev)
rds_conn_drop(conn);
rds_ib_stats_inc(s_ib_tasklet_call);
memset(&state, 0, sizeof(state));
poll_rcq(ic, ic->i_recv_cq, ic->i_recv_wc, &state);
ib_req_notify_cq(ic->i_recv_cq, IB_CQ_SOLICITED);
poll_rcq(ic, ic->i_recv_cq, ic->i_recv_wc, &state);
if (state.ack_next_valid)
rds_ib_set_ack(ic, state.ack_next, state.ack_required);
if (state.ack_recv_valid && state.ack_recv > ic->i_ack_recv) {
rds_send_drop_acked(conn, state.ack_recv, NULL);
ic->i_ack_recv = state.ack_recv;
}
if (rds_conn_up(conn))
rds_ib_attempt_ack(ic);
}
static void rds_ib_qp_event_handler(struct ib_event *event, void *data)
{
struct rds_connection *conn = data;
struct rds_ib_connection *ic = conn->c_transport_data;
rdsdebug("conn %p ic %p event %u (%s)\n", conn, ic, event->event,
ib_event_msg(event->event));
switch (event->event) {
case IB_EVENT_COMM_EST:
rdma_notify(ic->i_cm_id, IB_EVENT_COMM_EST);
break;
default:
rdsdebug("Fatal QP Event %u (%s) "
"- connection %pI4->%pI4, reconnecting\n",
event->event, ib_event_msg(event->event),
&conn->c_laddr, &conn->c_faddr);
rds_conn_drop(conn);
break;
}
}
static void rds_ib_cq_comp_handler_send(struct ib_cq *cq, void *context)
{
struct rds_connection *conn = context;
struct rds_ib_connection *ic = conn->c_transport_data;
rdsdebug("conn %p cq %p\n", conn, cq);
rds_ib_stats_inc(s_ib_evt_handler_call);
tasklet_schedule(&ic->i_send_tasklet);
}
static int rds_ib_setup_qp(struct rds_connection *conn)
{
struct rds_ib_connection *ic = conn->c_transport_data;
struct ib_device *dev = ic->i_cm_id->device;
struct ib_qp_init_attr attr;
struct ib_cq_init_attr cq_attr = {};
struct rds_ib_device *rds_ibdev;
int ret, fr_queue_space;
rds_ibdev = rds_ib_get_client_data(dev);
if (!rds_ibdev)
return -EOPNOTSUPP;
fr_queue_space = (rds_ibdev->use_fastreg ? RDS_IB_DEFAULT_FR_WR : 0);
rds_ib_add_conn(rds_ibdev, conn);
if (rds_ibdev->max_wrs < ic->i_send_ring.w_nr + 1)
rds_ib_ring_resize(&ic->i_send_ring, rds_ibdev->max_wrs - 1);
if (rds_ibdev->max_wrs < ic->i_recv_ring.w_nr + 1)
rds_ib_ring_resize(&ic->i_recv_ring, rds_ibdev->max_wrs - 1);
ic->i_pd = rds_ibdev->pd;
cq_attr.cqe = ic->i_send_ring.w_nr + fr_queue_space + 1;
ic->i_send_cq = ib_create_cq(dev, rds_ib_cq_comp_handler_send,
rds_ib_cq_event_handler, conn,
&cq_attr);
if (IS_ERR(ic->i_send_cq)) {
ret = PTR_ERR(ic->i_send_cq);
ic->i_send_cq = NULL;
rdsdebug("ib_create_cq send failed: %d\n", ret);
goto out;
}
cq_attr.cqe = ic->i_recv_ring.w_nr;
ic->i_recv_cq = ib_create_cq(dev, rds_ib_cq_comp_handler_recv,
rds_ib_cq_event_handler, conn,
&cq_attr);
if (IS_ERR(ic->i_recv_cq)) {
ret = PTR_ERR(ic->i_recv_cq);
ic->i_recv_cq = NULL;
rdsdebug("ib_create_cq recv failed: %d\n", ret);
goto out;
}
ret = ib_req_notify_cq(ic->i_send_cq, IB_CQ_NEXT_COMP);
if (ret) {
rdsdebug("ib_req_notify_cq send failed: %d\n", ret);
goto out;
}
ret = ib_req_notify_cq(ic->i_recv_cq, IB_CQ_SOLICITED);
if (ret) {
rdsdebug("ib_req_notify_cq recv failed: %d\n", ret);
goto out;
}
memset(&attr, 0, sizeof(attr));
attr.event_handler = rds_ib_qp_event_handler;
attr.qp_context = conn;
attr.cap.max_send_wr = ic->i_send_ring.w_nr + fr_queue_space + 1;
attr.cap.max_recv_wr = ic->i_recv_ring.w_nr + 1;
attr.cap.max_send_sge = rds_ibdev->max_sge;
attr.cap.max_recv_sge = RDS_IB_RECV_SGE;
attr.sq_sig_type = IB_SIGNAL_REQ_WR;
attr.qp_type = IB_QPT_RC;
attr.send_cq = ic->i_send_cq;
attr.recv_cq = ic->i_recv_cq;
atomic_set(&ic->i_fastreg_wrs, RDS_IB_DEFAULT_FR_WR);
ret = rdma_create_qp(ic->i_cm_id, ic->i_pd, &attr);
if (ret) {
rdsdebug("rdma_create_qp failed: %d\n", ret);
goto out;
}
ic->i_send_hdrs = ib_dma_alloc_coherent(dev,
ic->i_send_ring.w_nr *
sizeof(struct rds_header),
&ic->i_send_hdrs_dma, GFP_KERNEL);
if (!ic->i_send_hdrs) {
ret = -ENOMEM;
rdsdebug("ib_dma_alloc_coherent send failed\n");
goto out;
}
ic->i_recv_hdrs = ib_dma_alloc_coherent(dev,
ic->i_recv_ring.w_nr *
sizeof(struct rds_header),
&ic->i_recv_hdrs_dma, GFP_KERNEL);
if (!ic->i_recv_hdrs) {
ret = -ENOMEM;
rdsdebug("ib_dma_alloc_coherent recv failed\n");
goto out;
}
ic->i_ack = ib_dma_alloc_coherent(dev, sizeof(struct rds_header),
&ic->i_ack_dma, GFP_KERNEL);
if (!ic->i_ack) {
ret = -ENOMEM;
rdsdebug("ib_dma_alloc_coherent ack failed\n");
goto out;
}
ic->i_sends = vzalloc_node(ic->i_send_ring.w_nr * sizeof(struct rds_ib_send_work),
ibdev_to_node(dev));
if (!ic->i_sends) {
ret = -ENOMEM;
rdsdebug("send allocation failed\n");
goto out;
}
ic->i_recvs = vzalloc_node(ic->i_recv_ring.w_nr * sizeof(struct rds_ib_recv_work),
ibdev_to_node(dev));
if (!ic->i_recvs) {
ret = -ENOMEM;
rdsdebug("recv allocation failed\n");
goto out;
}
rds_ib_recv_init_ack(ic);
rdsdebug("conn %p pd %p cq %p %p\n", conn, ic->i_pd,
ic->i_send_cq, ic->i_recv_cq);
out:
rds_ib_dev_put(rds_ibdev);
return ret;
}
static u32 rds_ib_protocol_compatible(struct rdma_cm_event *event)
{
const struct rds_ib_connect_private *dp = event->param.conn.private_data;
u16 common;
u32 version = 0;
if (!event->param.conn.private_data_len) {
printk(KERN_NOTICE "RDS incoming connection has no private data, "
"rejecting\n");
return 0;
}
if (event->param.conn.private_data_len < sizeof (*dp) ||
dp->dp_protocol_major == 0)
return RDS_PROTOCOL_3_0;
common = be16_to_cpu(dp->dp_protocol_minor_mask) & RDS_IB_SUPPORTED_PROTOCOLS;
if (dp->dp_protocol_major == 3 && common) {
version = RDS_PROTOCOL_3_0;
while ((common >>= 1) != 0)
version++;
} else
printk_ratelimited(KERN_NOTICE "RDS: Connection from %pI4 using incompatible protocol version %u.%u\n",
&dp->dp_saddr,
dp->dp_protocol_major,
dp->dp_protocol_minor);
return version;
}
int rds_ib_cm_handle_connect(struct rdma_cm_id *cm_id,
struct rdma_cm_event *event)
{
__be64 lguid = cm_id->route.path_rec->sgid.global.interface_id;
__be64 fguid = cm_id->route.path_rec->dgid.global.interface_id;
const struct rds_ib_connect_private *dp = event->param.conn.private_data;
struct rds_ib_connect_private dp_rep;
struct rds_connection *conn = NULL;
struct rds_ib_connection *ic = NULL;
struct rdma_conn_param conn_param;
u32 version;
int err = 1, destroy = 1;
version = rds_ib_protocol_compatible(event);
if (!version)
goto out;
rdsdebug("saddr %pI4 daddr %pI4 RDSv%u.%u lguid 0x%llx fguid "
"0x%llx\n", &dp->dp_saddr, &dp->dp_daddr,
RDS_PROTOCOL_MAJOR(version), RDS_PROTOCOL_MINOR(version),
(unsigned long long)be64_to_cpu(lguid),
(unsigned long long)be64_to_cpu(fguid));
conn = rds_conn_create(&init_net, dp->dp_daddr, dp->dp_saddr,
&rds_ib_transport, GFP_KERNEL);
if (IS_ERR(conn)) {
rdsdebug("rds_conn_create failed (%ld)\n", PTR_ERR(conn));
conn = NULL;
goto out;
}
mutex_lock(&conn->c_cm_lock);
if (!rds_conn_transition(conn, RDS_CONN_DOWN, RDS_CONN_CONNECTING)) {
if (rds_conn_state(conn) == RDS_CONN_UP) {
rdsdebug("incoming connect while connecting\n");
rds_conn_drop(conn);
rds_ib_stats_inc(s_ib_listen_closed_stale);
} else
if (rds_conn_state(conn) == RDS_CONN_CONNECTING) {
rds_ib_stats_inc(s_ib_connect_raced);
}
goto out;
}
ic = conn->c_transport_data;
rds_ib_set_protocol(conn, version);
rds_ib_set_flow_control(conn, be32_to_cpu(dp->dp_credit));
if (dp->dp_ack_seq)
rds_send_drop_acked(conn, be64_to_cpu(dp->dp_ack_seq), NULL);
BUG_ON(cm_id->context);
BUG_ON(ic->i_cm_id);
ic->i_cm_id = cm_id;
cm_id->context = conn;
destroy = 0;
err = rds_ib_setup_qp(conn);
if (err) {
rds_ib_conn_error(conn, "rds_ib_setup_qp failed (%d)\n", err);
goto out;
}
rds_ib_cm_fill_conn_param(conn, &conn_param, &dp_rep, version,
event->param.conn.responder_resources,
event->param.conn.initiator_depth);
err = rdma_accept(cm_id, &conn_param);
if (err)
rds_ib_conn_error(conn, "rdma_accept failed (%d)\n", err);
out:
if (conn)
mutex_unlock(&conn->c_cm_lock);
if (err)
rdma_reject(cm_id, NULL, 0);
return destroy;
}
int rds_ib_cm_initiate_connect(struct rdma_cm_id *cm_id)
{
struct rds_connection *conn = cm_id->context;
struct rds_ib_connection *ic = conn->c_transport_data;
struct rdma_conn_param conn_param;
struct rds_ib_connect_private dp;
int ret;
rds_ib_set_protocol(conn, RDS_PROTOCOL_3_0);
ic->i_flowctl = rds_ib_sysctl_flow_control;
ret = rds_ib_setup_qp(conn);
if (ret) {
rds_ib_conn_error(conn, "rds_ib_setup_qp failed (%d)\n", ret);
goto out;
}
rds_ib_cm_fill_conn_param(conn, &conn_param, &dp, RDS_PROTOCOL_VERSION,
UINT_MAX, UINT_MAX);
ret = rdma_connect(cm_id, &conn_param);
if (ret)
rds_ib_conn_error(conn, "rdma_connect failed (%d)\n", ret);
out:
if (ret) {
if (ic->i_cm_id == cm_id)
ret = 0;
}
return ret;
}
int rds_ib_conn_connect(struct rds_connection *conn)
{
struct rds_ib_connection *ic = conn->c_transport_data;
struct sockaddr_in src, dest;
int ret;
ic->i_cm_id = rdma_create_id(&init_net, rds_rdma_cm_event_handler, conn,
RDMA_PS_TCP, IB_QPT_RC);
if (IS_ERR(ic->i_cm_id)) {
ret = PTR_ERR(ic->i_cm_id);
ic->i_cm_id = NULL;
rdsdebug("rdma_create_id() failed: %d\n", ret);
goto out;
}
rdsdebug("created cm id %p for conn %p\n", ic->i_cm_id, conn);
src.sin_family = AF_INET;
src.sin_addr.s_addr = (__force u32)conn->c_laddr;
src.sin_port = (__force u16)htons(0);
dest.sin_family = AF_INET;
dest.sin_addr.s_addr = (__force u32)conn->c_faddr;
dest.sin_port = (__force u16)htons(RDS_PORT);
ret = rdma_resolve_addr(ic->i_cm_id, (struct sockaddr *)&src,
(struct sockaddr *)&dest,
RDS_RDMA_RESOLVE_TIMEOUT_MS);
if (ret) {
rdsdebug("addr resolve failed for cm id %p: %d\n", ic->i_cm_id,
ret);
rdma_destroy_id(ic->i_cm_id);
ic->i_cm_id = NULL;
}
out:
return ret;
}
void rds_ib_conn_shutdown(struct rds_connection *conn)
{
struct rds_ib_connection *ic = conn->c_transport_data;
int err = 0;
rdsdebug("cm %p pd %p cq %p %p qp %p\n", ic->i_cm_id,
ic->i_pd, ic->i_send_cq, ic->i_recv_cq,
ic->i_cm_id ? ic->i_cm_id->qp : NULL);
if (ic->i_cm_id) {
struct ib_device *dev = ic->i_cm_id->device;
rdsdebug("disconnecting cm %p\n", ic->i_cm_id);
err = rdma_disconnect(ic->i_cm_id);
if (err) {
rdsdebug("failed to disconnect, cm: %p err %d\n",
ic->i_cm_id, err);
}
wait_event(rds_ib_ring_empty_wait,
rds_ib_ring_empty(&ic->i_recv_ring) &&
(atomic_read(&ic->i_signaled_sends) == 0) &&
(atomic_read(&ic->i_fastreg_wrs) == RDS_IB_DEFAULT_FR_WR));
tasklet_kill(&ic->i_send_tasklet);
tasklet_kill(&ic->i_recv_tasklet);
if (ic->i_cm_id->qp)
rdma_destroy_qp(ic->i_cm_id);
if (ic->i_send_cq)
ib_destroy_cq(ic->i_send_cq);
if (ic->i_recv_cq)
ib_destroy_cq(ic->i_recv_cq);
if (ic->i_send_hdrs)
ib_dma_free_coherent(dev,
ic->i_send_ring.w_nr *
sizeof(struct rds_header),
ic->i_send_hdrs,
ic->i_send_hdrs_dma);
if (ic->i_recv_hdrs)
ib_dma_free_coherent(dev,
ic->i_recv_ring.w_nr *
sizeof(struct rds_header),
ic->i_recv_hdrs,
ic->i_recv_hdrs_dma);
if (ic->i_ack)
ib_dma_free_coherent(dev, sizeof(struct rds_header),
ic->i_ack, ic->i_ack_dma);
if (ic->i_sends)
rds_ib_send_clear_ring(ic);
if (ic->i_recvs)
rds_ib_recv_clear_ring(ic);
rdma_destroy_id(ic->i_cm_id);
if (ic->rds_ibdev)
rds_ib_remove_conn(ic->rds_ibdev, conn);
ic->i_cm_id = NULL;
ic->i_pd = NULL;
ic->i_send_cq = NULL;
ic->i_recv_cq = NULL;
ic->i_send_hdrs = NULL;
ic->i_recv_hdrs = NULL;
ic->i_ack = NULL;
}
BUG_ON(ic->rds_ibdev);
if (ic->i_data_op) {
struct rds_message *rm;
rm = container_of(ic->i_data_op, struct rds_message, data);
rds_message_put(rm);
ic->i_data_op = NULL;
}
clear_bit(IB_ACK_IN_FLIGHT, &ic->i_ack_flags);
#ifdef KERNEL_HAS_ATOMIC64
atomic64_set(&ic->i_ack_next, 0);
#else
ic->i_ack_next = 0;
#endif
ic->i_ack_recv = 0;
ic->i_flowctl = 0;
atomic_set(&ic->i_credits, 0);
rds_ib_ring_init(&ic->i_send_ring, rds_ib_sysctl_max_send_wr);
rds_ib_ring_init(&ic->i_recv_ring, rds_ib_sysctl_max_recv_wr);
if (ic->i_ibinc) {
rds_inc_put(&ic->i_ibinc->ii_inc);
ic->i_ibinc = NULL;
}
vfree(ic->i_sends);
ic->i_sends = NULL;
vfree(ic->i_recvs);
ic->i_recvs = NULL;
}
int rds_ib_conn_alloc(struct rds_connection *conn, gfp_t gfp)
{
struct rds_ib_connection *ic;
unsigned long flags;
int ret;
ic = kzalloc(sizeof(struct rds_ib_connection), gfp);
if (!ic)
return -ENOMEM;
ret = rds_ib_recv_alloc_caches(ic);
if (ret) {
kfree(ic);
return ret;
}
INIT_LIST_HEAD(&ic->ib_node);
tasklet_init(&ic->i_send_tasklet, rds_ib_tasklet_fn_send,
(unsigned long)ic);
tasklet_init(&ic->i_recv_tasklet, rds_ib_tasklet_fn_recv,
(unsigned long)ic);
mutex_init(&ic->i_recv_mutex);
#ifndef KERNEL_HAS_ATOMIC64
spin_lock_init(&ic->i_ack_lock);
#endif
atomic_set(&ic->i_signaled_sends, 0);
rds_ib_ring_init(&ic->i_send_ring, rds_ib_sysctl_max_send_wr);
rds_ib_ring_init(&ic->i_recv_ring, rds_ib_sysctl_max_recv_wr);
ic->conn = conn;
conn->c_transport_data = ic;
spin_lock_irqsave(&ib_nodev_conns_lock, flags);
list_add_tail(&ic->ib_node, &ib_nodev_conns);
spin_unlock_irqrestore(&ib_nodev_conns_lock, flags);
rdsdebug("conn %p conn ic %p\n", conn, conn->c_transport_data);
return 0;
}
void rds_ib_conn_free(void *arg)
{
struct rds_ib_connection *ic = arg;
spinlock_t *lock_ptr;
rdsdebug("ic %p\n", ic);
lock_ptr = ic->rds_ibdev ? &ic->rds_ibdev->spinlock : &ib_nodev_conns_lock;
spin_lock_irq(lock_ptr);
list_del(&ic->ib_node);
spin_unlock_irq(lock_ptr);
rds_ib_recv_free_caches(ic);
kfree(ic);
}
void
__rds_ib_conn_error(struct rds_connection *conn, const char *fmt, ...)
{
va_list ap;
rds_conn_drop(conn);
va_start(ap, fmt);
vprintk(fmt, ap);
va_end(ap);
}
