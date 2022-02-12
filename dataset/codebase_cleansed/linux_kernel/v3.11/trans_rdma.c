static int parse_opts(char *params, struct p9_rdma_opts *opts)
{
char *p;
substring_t args[MAX_OPT_ARGS];
int option;
char *options, *tmp_options;
opts->port = P9_PORT;
opts->sq_depth = P9_RDMA_SQ_DEPTH;
opts->rq_depth = P9_RDMA_RQ_DEPTH;
opts->timeout = P9_RDMA_TIMEOUT;
if (!params)
return 0;
tmp_options = kstrdup(params, GFP_KERNEL);
if (!tmp_options) {
p9_debug(P9_DEBUG_ERROR,
"failed to allocate copy of option string\n");
return -ENOMEM;
}
options = tmp_options;
while ((p = strsep(&options, ",")) != NULL) {
int token;
int r;
if (!*p)
continue;
token = match_token(p, tokens, args);
r = match_int(&args[0], &option);
if (r < 0) {
p9_debug(P9_DEBUG_ERROR,
"integer field, but no integer?\n");
continue;
}
switch (token) {
case Opt_port:
opts->port = option;
break;
case Opt_sq_depth:
opts->sq_depth = option;
break;
case Opt_rq_depth:
opts->rq_depth = option;
break;
case Opt_timeout:
opts->timeout = option;
break;
default:
continue;
}
}
opts->rq_depth = max(opts->rq_depth, opts->sq_depth);
kfree(tmp_options);
return 0;
}
static int
p9_cm_event_handler(struct rdma_cm_id *id, struct rdma_cm_event *event)
{
struct p9_client *c = id->context;
struct p9_trans_rdma *rdma = c->trans;
switch (event->event) {
case RDMA_CM_EVENT_ADDR_RESOLVED:
BUG_ON(rdma->state != P9_RDMA_INIT);
rdma->state = P9_RDMA_ADDR_RESOLVED;
break;
case RDMA_CM_EVENT_ROUTE_RESOLVED:
BUG_ON(rdma->state != P9_RDMA_ADDR_RESOLVED);
rdma->state = P9_RDMA_ROUTE_RESOLVED;
break;
case RDMA_CM_EVENT_ESTABLISHED:
BUG_ON(rdma->state != P9_RDMA_ROUTE_RESOLVED);
rdma->state = P9_RDMA_CONNECTED;
break;
case RDMA_CM_EVENT_DISCONNECTED:
if (rdma)
rdma->state = P9_RDMA_CLOSED;
if (c)
c->status = Disconnected;
break;
case RDMA_CM_EVENT_TIMEWAIT_EXIT:
break;
case RDMA_CM_EVENT_ADDR_CHANGE:
case RDMA_CM_EVENT_ROUTE_ERROR:
case RDMA_CM_EVENT_DEVICE_REMOVAL:
case RDMA_CM_EVENT_MULTICAST_JOIN:
case RDMA_CM_EVENT_MULTICAST_ERROR:
case RDMA_CM_EVENT_REJECTED:
case RDMA_CM_EVENT_CONNECT_REQUEST:
case RDMA_CM_EVENT_CONNECT_RESPONSE:
case RDMA_CM_EVENT_CONNECT_ERROR:
case RDMA_CM_EVENT_ADDR_ERROR:
case RDMA_CM_EVENT_UNREACHABLE:
c->status = Disconnected;
rdma_disconnect(rdma->cm_id);
break;
default:
BUG();
}
complete(&rdma->cm_done);
return 0;
}
static void
handle_recv(struct p9_client *client, struct p9_trans_rdma *rdma,
struct p9_rdma_context *c, enum ib_wc_status status, u32 byte_len)
{
struct p9_req_t *req;
int err = 0;
int16_t tag;
req = NULL;
ib_dma_unmap_single(rdma->cm_id->device, c->busa, client->msize,
DMA_FROM_DEVICE);
if (status != IB_WC_SUCCESS)
goto err_out;
err = p9_parse_header(c->rc, NULL, NULL, &tag, 1);
if (err)
goto err_out;
req = p9_tag_lookup(client, tag);
if (!req)
goto err_out;
if (unlikely(req->rc)) {
pr_err("Duplicate reply for request %d", tag);
goto err_out;
}
req->rc = c->rc;
req->status = REQ_STATUS_RCVD;
p9_client_cb(client, req);
return;
err_out:
p9_debug(P9_DEBUG_ERROR, "req %p err %d status %d\n", req, err, status);
rdma->state = P9_RDMA_FLUSHING;
client->status = Disconnected;
}
static void
handle_send(struct p9_client *client, struct p9_trans_rdma *rdma,
struct p9_rdma_context *c, enum ib_wc_status status, u32 byte_len)
{
ib_dma_unmap_single(rdma->cm_id->device,
c->busa, c->req->tc->size,
DMA_TO_DEVICE);
}
static void qp_event_handler(struct ib_event *event, void *context)
{
p9_debug(P9_DEBUG_ERROR, "QP event %d context %p\n",
event->event, context);
}
static void cq_comp_handler(struct ib_cq *cq, void *cq_context)
{
struct p9_client *client = cq_context;
struct p9_trans_rdma *rdma = client->trans;
int ret;
struct ib_wc wc;
ib_req_notify_cq(rdma->cq, IB_CQ_NEXT_COMP);
while ((ret = ib_poll_cq(cq, 1, &wc)) > 0) {
struct p9_rdma_context *c = (void *) (unsigned long) wc.wr_id;
switch (c->wc_op) {
case IB_WC_RECV:
handle_recv(client, rdma, c, wc.status, wc.byte_len);
up(&rdma->rq_sem);
break;
case IB_WC_SEND:
handle_send(client, rdma, c, wc.status, wc.byte_len);
up(&rdma->sq_sem);
break;
default:
pr_err("unexpected completion type, c->wc_op=%d, wc.opcode=%d, status=%d\n",
c->wc_op, wc.opcode, wc.status);
break;
}
kfree(c);
}
}
static void cq_event_handler(struct ib_event *e, void *v)
{
p9_debug(P9_DEBUG_ERROR, "CQ event %d context %p\n", e->event, v);
}
static void rdma_destroy_trans(struct p9_trans_rdma *rdma)
{
if (!rdma)
return;
if (rdma->dma_mr && !IS_ERR(rdma->dma_mr))
ib_dereg_mr(rdma->dma_mr);
if (rdma->qp && !IS_ERR(rdma->qp))
ib_destroy_qp(rdma->qp);
if (rdma->pd && !IS_ERR(rdma->pd))
ib_dealloc_pd(rdma->pd);
if (rdma->cq && !IS_ERR(rdma->cq))
ib_destroy_cq(rdma->cq);
if (rdma->cm_id && !IS_ERR(rdma->cm_id))
rdma_destroy_id(rdma->cm_id);
kfree(rdma);
}
static int
post_recv(struct p9_client *client, struct p9_rdma_context *c)
{
struct p9_trans_rdma *rdma = client->trans;
struct ib_recv_wr wr, *bad_wr;
struct ib_sge sge;
c->busa = ib_dma_map_single(rdma->cm_id->device,
c->rc->sdata, client->msize,
DMA_FROM_DEVICE);
if (ib_dma_mapping_error(rdma->cm_id->device, c->busa))
goto error;
sge.addr = c->busa;
sge.length = client->msize;
sge.lkey = rdma->lkey;
wr.next = NULL;
c->wc_op = IB_WC_RECV;
wr.wr_id = (unsigned long) c;
wr.sg_list = &sge;
wr.num_sge = 1;
return ib_post_recv(rdma->qp, &wr, &bad_wr);
error:
p9_debug(P9_DEBUG_ERROR, "EIO\n");
return -EIO;
}
static int rdma_request(struct p9_client *client, struct p9_req_t *req)
{
struct p9_trans_rdma *rdma = client->trans;
struct ib_send_wr wr, *bad_wr;
struct ib_sge sge;
int err = 0;
unsigned long flags;
struct p9_rdma_context *c = NULL;
struct p9_rdma_context *rpl_context = NULL;
if (unlikely(atomic_read(&rdma->excess_rc) > 0)) {
if ((atomic_sub_return(1, &rdma->excess_rc) >= 0)) {
kfree(req->rc);
req->rc = NULL;
goto dont_need_post_recv;
} else {
atomic_inc(&rdma->excess_rc);
}
}
rpl_context = kmalloc(sizeof *rpl_context, GFP_NOFS);
if (!rpl_context) {
err = -ENOMEM;
goto recv_error;
}
rpl_context->rc = req->rc;
if (down_interruptible(&rdma->rq_sem)) {
err = -EINTR;
goto recv_error;
}
err = post_recv(client, rpl_context);
if (err) {
p9_debug(P9_DEBUG_FCALL, "POST RECV failed\n");
goto recv_error;
}
req->rc = NULL;
dont_need_post_recv:
c = kmalloc(sizeof *c, GFP_NOFS);
if (!c) {
err = -ENOMEM;
goto send_error;
}
c->req = req;
c->busa = ib_dma_map_single(rdma->cm_id->device,
c->req->tc->sdata, c->req->tc->size,
DMA_TO_DEVICE);
if (ib_dma_mapping_error(rdma->cm_id->device, c->busa)) {
err = -EIO;
goto send_error;
}
sge.addr = c->busa;
sge.length = c->req->tc->size;
sge.lkey = rdma->lkey;
wr.next = NULL;
c->wc_op = IB_WC_SEND;
wr.wr_id = (unsigned long) c;
wr.opcode = IB_WR_SEND;
wr.send_flags = IB_SEND_SIGNALED;
wr.sg_list = &sge;
wr.num_sge = 1;
if (down_interruptible(&rdma->sq_sem)) {
err = -EINTR;
goto send_error;
}
err = ib_post_send(rdma->qp, &wr, &bad_wr);
if (err)
goto send_error;
return 0;
send_error:
kfree(c);
p9_debug(P9_DEBUG_ERROR, "Error %d in rdma_request()\n", err);
atomic_inc(&rdma->excess_rc);
return err;
recv_error:
kfree(rpl_context);
spin_lock_irqsave(&rdma->req_lock, flags);
if (rdma->state < P9_RDMA_CLOSING) {
rdma->state = P9_RDMA_CLOSING;
spin_unlock_irqrestore(&rdma->req_lock, flags);
rdma_disconnect(rdma->cm_id);
} else
spin_unlock_irqrestore(&rdma->req_lock, flags);
return err;
}
static void rdma_close(struct p9_client *client)
{
struct p9_trans_rdma *rdma;
if (!client)
return;
rdma = client->trans;
if (!rdma)
return;
client->status = Disconnected;
rdma_disconnect(rdma->cm_id);
rdma_destroy_trans(rdma);
}
static struct p9_trans_rdma *alloc_rdma(struct p9_rdma_opts *opts)
{
struct p9_trans_rdma *rdma;
rdma = kzalloc(sizeof(struct p9_trans_rdma), GFP_KERNEL);
if (!rdma)
return NULL;
rdma->sq_depth = opts->sq_depth;
rdma->rq_depth = opts->rq_depth;
rdma->timeout = opts->timeout;
spin_lock_init(&rdma->req_lock);
init_completion(&rdma->cm_done);
sema_init(&rdma->sq_sem, rdma->sq_depth);
sema_init(&rdma->rq_sem, rdma->rq_depth);
atomic_set(&rdma->excess_rc, 0);
return rdma;
}
static int rdma_cancel(struct p9_client *client, struct p9_req_t *req)
{
return 1;
}
static int rdma_cancelled(struct p9_client *client, struct p9_req_t *req)
{
struct p9_trans_rdma *rdma = client->trans;
atomic_inc(&rdma->excess_rc);
return 0;
}
static int
rdma_create_trans(struct p9_client *client, const char *addr, char *args)
{
int err;
struct p9_rdma_opts opts;
struct p9_trans_rdma *rdma;
struct rdma_conn_param conn_param;
struct ib_qp_init_attr qp_attr;
struct ib_device_attr devattr;
err = parse_opts(args, &opts);
if (err < 0)
return err;
rdma = alloc_rdma(&opts);
if (!rdma)
return -ENOMEM;
rdma->cm_id = rdma_create_id(p9_cm_event_handler, client, RDMA_PS_TCP,
IB_QPT_RC);
if (IS_ERR(rdma->cm_id))
goto error;
client->trans = rdma;
rdma->addr.sin_family = AF_INET;
rdma->addr.sin_addr.s_addr = in_aton(addr);
rdma->addr.sin_port = htons(opts.port);
err = rdma_resolve_addr(rdma->cm_id, NULL,
(struct sockaddr *)&rdma->addr,
rdma->timeout);
if (err)
goto error;
err = wait_for_completion_interruptible(&rdma->cm_done);
if (err || (rdma->state != P9_RDMA_ADDR_RESOLVED))
goto error;
err = rdma_resolve_route(rdma->cm_id, rdma->timeout);
if (err)
goto error;
err = wait_for_completion_interruptible(&rdma->cm_done);
if (err || (rdma->state != P9_RDMA_ROUTE_RESOLVED))
goto error;
err = ib_query_device(rdma->cm_id->device, &devattr);
if (err)
goto error;
rdma->cq = ib_create_cq(rdma->cm_id->device, cq_comp_handler,
cq_event_handler, client,
opts.sq_depth + opts.rq_depth + 1, 0);
if (IS_ERR(rdma->cq))
goto error;
ib_req_notify_cq(rdma->cq, IB_CQ_NEXT_COMP);
rdma->pd = ib_alloc_pd(rdma->cm_id->device);
if (IS_ERR(rdma->pd))
goto error;
rdma->dma_mr = NULL;
if (devattr.device_cap_flags & IB_DEVICE_LOCAL_DMA_LKEY)
rdma->lkey = rdma->cm_id->device->local_dma_lkey;
else {
rdma->dma_mr = ib_get_dma_mr(rdma->pd, IB_ACCESS_LOCAL_WRITE);
if (IS_ERR(rdma->dma_mr))
goto error;
rdma->lkey = rdma->dma_mr->lkey;
}
memset(&qp_attr, 0, sizeof qp_attr);
qp_attr.event_handler = qp_event_handler;
qp_attr.qp_context = client;
qp_attr.cap.max_send_wr = opts.sq_depth;
qp_attr.cap.max_recv_wr = opts.rq_depth;
qp_attr.cap.max_send_sge = P9_RDMA_SEND_SGE;
qp_attr.cap.max_recv_sge = P9_RDMA_RECV_SGE;
qp_attr.sq_sig_type = IB_SIGNAL_REQ_WR;
qp_attr.qp_type = IB_QPT_RC;
qp_attr.send_cq = rdma->cq;
qp_attr.recv_cq = rdma->cq;
err = rdma_create_qp(rdma->cm_id, rdma->pd, &qp_attr);
if (err)
goto error;
rdma->qp = rdma->cm_id->qp;
memset(&conn_param, 0, sizeof(conn_param));
conn_param.private_data = NULL;
conn_param.private_data_len = 0;
conn_param.responder_resources = P9_RDMA_IRD;
conn_param.initiator_depth = P9_RDMA_ORD;
err = rdma_connect(rdma->cm_id, &conn_param);
if (err)
goto error;
err = wait_for_completion_interruptible(&rdma->cm_done);
if (err || (rdma->state != P9_RDMA_CONNECTED))
goto error;
client->status = Connected;
return 0;
error:
rdma_destroy_trans(rdma);
return -ENOTCONN;
}
static int __init p9_trans_rdma_init(void)
{
v9fs_register_trans(&p9_rdma_trans);
return 0;
}
static void __exit p9_trans_rdma_exit(void)
{
v9fs_unregister_trans(&p9_rdma_trans);
}
