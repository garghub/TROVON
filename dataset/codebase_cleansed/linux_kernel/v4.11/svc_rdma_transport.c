static struct svc_xprt *svc_rdma_bc_create(struct svc_serv *serv,
struct net *net,
struct sockaddr *sa, int salen,
int flags)
{
struct svcxprt_rdma *cma_xprt;
struct svc_xprt *xprt;
cma_xprt = rdma_create_xprt(serv, 0);
if (!cma_xprt)
return ERR_PTR(-ENOMEM);
xprt = &cma_xprt->sc_xprt;
svc_xprt_init(net, &svc_rdma_bc_class, xprt, serv);
set_bit(XPT_CONG_CTRL, &xprt->xpt_flags);
serv->sv_bc_xprt = xprt;
dprintk("svcrdma: %s(%p)\n", __func__, xprt);
return xprt;
}
static void svc_rdma_bc_detach(struct svc_xprt *xprt)
{
dprintk("svcrdma: %s(%p)\n", __func__, xprt);
}
static void svc_rdma_bc_free(struct svc_xprt *xprt)
{
struct svcxprt_rdma *rdma =
container_of(xprt, struct svcxprt_rdma, sc_xprt);
dprintk("svcrdma: %s(%p)\n", __func__, xprt);
if (xprt)
kfree(rdma);
}
static struct svc_rdma_op_ctxt *alloc_ctxt(struct svcxprt_rdma *xprt,
gfp_t flags)
{
struct svc_rdma_op_ctxt *ctxt;
ctxt = kmalloc(sizeof(*ctxt), flags);
if (ctxt) {
ctxt->xprt = xprt;
INIT_LIST_HEAD(&ctxt->list);
}
return ctxt;
}
static bool svc_rdma_prealloc_ctxts(struct svcxprt_rdma *xprt)
{
unsigned int i;
i = xprt->sc_sq_depth + xprt->sc_rq_depth;
while (i--) {
struct svc_rdma_op_ctxt *ctxt;
ctxt = alloc_ctxt(xprt, GFP_KERNEL);
if (!ctxt) {
dprintk("svcrdma: No memory for RDMA ctxt\n");
return false;
}
list_add(&ctxt->list, &xprt->sc_ctxts);
}
return true;
}
struct svc_rdma_op_ctxt *svc_rdma_get_context(struct svcxprt_rdma *xprt)
{
struct svc_rdma_op_ctxt *ctxt = NULL;
spin_lock(&xprt->sc_ctxt_lock);
xprt->sc_ctxt_used++;
if (list_empty(&xprt->sc_ctxts))
goto out_empty;
ctxt = list_first_entry(&xprt->sc_ctxts,
struct svc_rdma_op_ctxt, list);
list_del(&ctxt->list);
spin_unlock(&xprt->sc_ctxt_lock);
out:
ctxt->count = 0;
ctxt->mapped_sges = 0;
ctxt->frmr = NULL;
return ctxt;
out_empty:
spin_unlock(&xprt->sc_ctxt_lock);
ctxt = alloc_ctxt(xprt, GFP_NOIO);
if (ctxt)
goto out;
spin_lock(&xprt->sc_ctxt_lock);
xprt->sc_ctxt_used--;
spin_unlock(&xprt->sc_ctxt_lock);
WARN_ONCE(1, "svcrdma: empty RDMA ctxt list?\n");
return NULL;
}
void svc_rdma_unmap_dma(struct svc_rdma_op_ctxt *ctxt)
{
struct svcxprt_rdma *xprt = ctxt->xprt;
struct ib_device *device = xprt->sc_cm_id->device;
u32 lkey = xprt->sc_pd->local_dma_lkey;
unsigned int i;
for (i = 0; i < ctxt->mapped_sges; i++) {
if (ctxt->sge[i].lkey == lkey)
ib_dma_unmap_page(device,
ctxt->sge[i].addr,
ctxt->sge[i].length,
ctxt->direction);
}
ctxt->mapped_sges = 0;
}
void svc_rdma_put_context(struct svc_rdma_op_ctxt *ctxt, int free_pages)
{
struct svcxprt_rdma *xprt = ctxt->xprt;
int i;
if (free_pages)
for (i = 0; i < ctxt->count; i++)
put_page(ctxt->pages[i]);
spin_lock(&xprt->sc_ctxt_lock);
xprt->sc_ctxt_used--;
list_add(&ctxt->list, &xprt->sc_ctxts);
spin_unlock(&xprt->sc_ctxt_lock);
}
static void svc_rdma_destroy_ctxts(struct svcxprt_rdma *xprt)
{
while (!list_empty(&xprt->sc_ctxts)) {
struct svc_rdma_op_ctxt *ctxt;
ctxt = list_first_entry(&xprt->sc_ctxts,
struct svc_rdma_op_ctxt, list);
list_del(&ctxt->list);
kfree(ctxt);
}
}
static struct svc_rdma_req_map *alloc_req_map(gfp_t flags)
{
struct svc_rdma_req_map *map;
map = kmalloc(sizeof(*map), flags);
if (map)
INIT_LIST_HEAD(&map->free);
return map;
}
static bool svc_rdma_prealloc_maps(struct svcxprt_rdma *xprt)
{
unsigned int i;
i = xprt->sc_max_requests;
while (i--) {
struct svc_rdma_req_map *map;
map = alloc_req_map(GFP_KERNEL);
if (!map) {
dprintk("svcrdma: No memory for request map\n");
return false;
}
list_add(&map->free, &xprt->sc_maps);
}
return true;
}
struct svc_rdma_req_map *svc_rdma_get_req_map(struct svcxprt_rdma *xprt)
{
struct svc_rdma_req_map *map = NULL;
spin_lock(&xprt->sc_map_lock);
if (list_empty(&xprt->sc_maps))
goto out_empty;
map = list_first_entry(&xprt->sc_maps,
struct svc_rdma_req_map, free);
list_del_init(&map->free);
spin_unlock(&xprt->sc_map_lock);
out:
map->count = 0;
return map;
out_empty:
spin_unlock(&xprt->sc_map_lock);
map = alloc_req_map(GFP_NOIO);
if (map)
goto out;
WARN_ONCE(1, "svcrdma: empty request map list?\n");
return NULL;
}
void svc_rdma_put_req_map(struct svcxprt_rdma *xprt,
struct svc_rdma_req_map *map)
{
spin_lock(&xprt->sc_map_lock);
list_add(&map->free, &xprt->sc_maps);
spin_unlock(&xprt->sc_map_lock);
}
static void svc_rdma_destroy_maps(struct svcxprt_rdma *xprt)
{
while (!list_empty(&xprt->sc_maps)) {
struct svc_rdma_req_map *map;
map = list_first_entry(&xprt->sc_maps,
struct svc_rdma_req_map, free);
list_del(&map->free);
kfree(map);
}
}
static void qp_event_handler(struct ib_event *event, void *context)
{
struct svc_xprt *xprt = context;
switch (event->event) {
case IB_EVENT_PATH_MIG:
case IB_EVENT_COMM_EST:
case IB_EVENT_SQ_DRAINED:
case IB_EVENT_QP_LAST_WQE_REACHED:
dprintk("svcrdma: QP event %s (%d) received for QP=%p\n",
ib_event_msg(event->event), event->event,
event->element.qp);
break;
case IB_EVENT_PATH_MIG_ERR:
case IB_EVENT_QP_FATAL:
case IB_EVENT_QP_REQ_ERR:
case IB_EVENT_QP_ACCESS_ERR:
case IB_EVENT_DEVICE_FATAL:
default:
dprintk("svcrdma: QP ERROR event %s (%d) received for QP=%p, "
"closing transport\n",
ib_event_msg(event->event), event->event,
event->element.qp);
set_bit(XPT_CLOSE, &xprt->xpt_flags);
break;
}
}
static void svc_rdma_wc_receive(struct ib_cq *cq, struct ib_wc *wc)
{
struct svcxprt_rdma *xprt = cq->cq_context;
struct ib_cqe *cqe = wc->wr_cqe;
struct svc_rdma_op_ctxt *ctxt;
ctxt = container_of(cqe, struct svc_rdma_op_ctxt, cqe);
svc_rdma_unmap_dma(ctxt);
if (wc->status != IB_WC_SUCCESS)
goto flushed;
ctxt->byte_len = wc->byte_len;
spin_lock(&xprt->sc_rq_dto_lock);
list_add_tail(&ctxt->list, &xprt->sc_rq_dto_q);
spin_unlock(&xprt->sc_rq_dto_lock);
set_bit(XPT_DATA, &xprt->sc_xprt.xpt_flags);
if (test_bit(RDMAXPRT_CONN_PENDING, &xprt->sc_flags))
goto out;
svc_xprt_enqueue(&xprt->sc_xprt);
goto out;
flushed:
if (wc->status != IB_WC_WR_FLUSH_ERR)
pr_warn("svcrdma: receive: %s (%u/0x%x)\n",
ib_wc_status_msg(wc->status),
wc->status, wc->vendor_err);
set_bit(XPT_CLOSE, &xprt->sc_xprt.xpt_flags);
svc_rdma_put_context(ctxt, 1);
out:
svc_xprt_put(&xprt->sc_xprt);
}
static void svc_rdma_send_wc_common(struct svcxprt_rdma *xprt,
struct ib_wc *wc,
const char *opname)
{
if (wc->status != IB_WC_SUCCESS)
goto err;
out:
atomic_inc(&xprt->sc_sq_avail);
wake_up(&xprt->sc_send_wait);
return;
err:
set_bit(XPT_CLOSE, &xprt->sc_xprt.xpt_flags);
if (wc->status != IB_WC_WR_FLUSH_ERR)
pr_err("svcrdma: %s: %s (%u/0x%x)\n",
opname, ib_wc_status_msg(wc->status),
wc->status, wc->vendor_err);
goto out;
}
static void svc_rdma_send_wc_common_put(struct ib_cq *cq, struct ib_wc *wc,
const char *opname)
{
struct svcxprt_rdma *xprt = cq->cq_context;
svc_rdma_send_wc_common(xprt, wc, opname);
svc_xprt_put(&xprt->sc_xprt);
}
void svc_rdma_wc_send(struct ib_cq *cq, struct ib_wc *wc)
{
struct ib_cqe *cqe = wc->wr_cqe;
struct svc_rdma_op_ctxt *ctxt;
svc_rdma_send_wc_common_put(cq, wc, "send");
ctxt = container_of(cqe, struct svc_rdma_op_ctxt, cqe);
svc_rdma_unmap_dma(ctxt);
svc_rdma_put_context(ctxt, 1);
}
void svc_rdma_wc_write(struct ib_cq *cq, struct ib_wc *wc)
{
struct ib_cqe *cqe = wc->wr_cqe;
struct svc_rdma_op_ctxt *ctxt;
svc_rdma_send_wc_common_put(cq, wc, "write");
ctxt = container_of(cqe, struct svc_rdma_op_ctxt, cqe);
svc_rdma_unmap_dma(ctxt);
svc_rdma_put_context(ctxt, 0);
}
void svc_rdma_wc_reg(struct ib_cq *cq, struct ib_wc *wc)
{
svc_rdma_send_wc_common_put(cq, wc, "fastreg");
}
void svc_rdma_wc_read(struct ib_cq *cq, struct ib_wc *wc)
{
struct svcxprt_rdma *xprt = cq->cq_context;
struct ib_cqe *cqe = wc->wr_cqe;
struct svc_rdma_op_ctxt *ctxt;
svc_rdma_send_wc_common(xprt, wc, "read");
ctxt = container_of(cqe, struct svc_rdma_op_ctxt, cqe);
svc_rdma_unmap_dma(ctxt);
svc_rdma_put_frmr(xprt, ctxt->frmr);
if (test_bit(RDMACTXT_F_LAST_CTXT, &ctxt->flags)) {
struct svc_rdma_op_ctxt *read_hdr;
read_hdr = ctxt->read_hdr;
spin_lock(&xprt->sc_rq_dto_lock);
list_add_tail(&read_hdr->list,
&xprt->sc_read_complete_q);
spin_unlock(&xprt->sc_rq_dto_lock);
set_bit(XPT_DATA, &xprt->sc_xprt.xpt_flags);
svc_xprt_enqueue(&xprt->sc_xprt);
}
svc_rdma_put_context(ctxt, 0);
svc_xprt_put(&xprt->sc_xprt);
}
void svc_rdma_wc_inv(struct ib_cq *cq, struct ib_wc *wc)
{
svc_rdma_send_wc_common_put(cq, wc, "localInv");
}
static struct svcxprt_rdma *rdma_create_xprt(struct svc_serv *serv,
int listener)
{
struct svcxprt_rdma *cma_xprt = kzalloc(sizeof *cma_xprt, GFP_KERNEL);
if (!cma_xprt)
return NULL;
svc_xprt_init(&init_net, &svc_rdma_class, &cma_xprt->sc_xprt, serv);
INIT_LIST_HEAD(&cma_xprt->sc_accept_q);
INIT_LIST_HEAD(&cma_xprt->sc_rq_dto_q);
INIT_LIST_HEAD(&cma_xprt->sc_read_complete_q);
INIT_LIST_HEAD(&cma_xprt->sc_frmr_q);
INIT_LIST_HEAD(&cma_xprt->sc_ctxts);
INIT_LIST_HEAD(&cma_xprt->sc_maps);
init_waitqueue_head(&cma_xprt->sc_send_wait);
spin_lock_init(&cma_xprt->sc_lock);
spin_lock_init(&cma_xprt->sc_rq_dto_lock);
spin_lock_init(&cma_xprt->sc_frmr_q_lock);
spin_lock_init(&cma_xprt->sc_ctxt_lock);
spin_lock_init(&cma_xprt->sc_map_lock);
set_bit(XPT_CONG_CTRL, &cma_xprt->sc_xprt.xpt_flags);
if (listener)
set_bit(XPT_LISTENER, &cma_xprt->sc_xprt.xpt_flags);
return cma_xprt;
}
int svc_rdma_post_recv(struct svcxprt_rdma *xprt, gfp_t flags)
{
struct ib_recv_wr recv_wr, *bad_recv_wr;
struct svc_rdma_op_ctxt *ctxt;
struct page *page;
dma_addr_t pa;
int sge_no;
int buflen;
int ret;
ctxt = svc_rdma_get_context(xprt);
buflen = 0;
ctxt->direction = DMA_FROM_DEVICE;
ctxt->cqe.done = svc_rdma_wc_receive;
for (sge_no = 0; buflen < xprt->sc_max_req_size; sge_no++) {
if (sge_no >= xprt->sc_max_sge) {
pr_err("svcrdma: Too many sges (%d)\n", sge_no);
goto err_put_ctxt;
}
page = alloc_page(flags);
if (!page)
goto err_put_ctxt;
ctxt->pages[sge_no] = page;
pa = ib_dma_map_page(xprt->sc_cm_id->device,
page, 0, PAGE_SIZE,
DMA_FROM_DEVICE);
if (ib_dma_mapping_error(xprt->sc_cm_id->device, pa))
goto err_put_ctxt;
svc_rdma_count_mappings(xprt, ctxt);
ctxt->sge[sge_no].addr = pa;
ctxt->sge[sge_no].length = PAGE_SIZE;
ctxt->sge[sge_no].lkey = xprt->sc_pd->local_dma_lkey;
ctxt->count = sge_no + 1;
buflen += PAGE_SIZE;
}
recv_wr.next = NULL;
recv_wr.sg_list = &ctxt->sge[0];
recv_wr.num_sge = ctxt->count;
recv_wr.wr_cqe = &ctxt->cqe;
svc_xprt_get(&xprt->sc_xprt);
ret = ib_post_recv(xprt->sc_qp, &recv_wr, &bad_recv_wr);
if (ret) {
svc_rdma_unmap_dma(ctxt);
svc_rdma_put_context(ctxt, 1);
svc_xprt_put(&xprt->sc_xprt);
}
return ret;
err_put_ctxt:
svc_rdma_unmap_dma(ctxt);
svc_rdma_put_context(ctxt, 1);
return -ENOMEM;
}
int svc_rdma_repost_recv(struct svcxprt_rdma *xprt, gfp_t flags)
{
int ret = 0;
ret = svc_rdma_post_recv(xprt, flags);
if (ret) {
pr_err("svcrdma: could not post a receive buffer, err=%d.\n",
ret);
pr_err("svcrdma: closing transport %p.\n", xprt);
set_bit(XPT_CLOSE, &xprt->sc_xprt.xpt_flags);
ret = -ENOTCONN;
}
return ret;
}
static void
svc_rdma_parse_connect_private(struct svcxprt_rdma *newxprt,
struct rdma_conn_param *param)
{
const struct rpcrdma_connect_private *pmsg = param->private_data;
if (pmsg &&
pmsg->cp_magic == rpcrdma_cmp_magic &&
pmsg->cp_version == RPCRDMA_CMP_VERSION) {
newxprt->sc_snd_w_inv = pmsg->cp_flags &
RPCRDMA_CMP_F_SND_W_INV_OK;
dprintk("svcrdma: client send_size %u, recv_size %u "
"remote inv %ssupported\n",
rpcrdma_decode_buffer_size(pmsg->cp_send_size),
rpcrdma_decode_buffer_size(pmsg->cp_recv_size),
newxprt->sc_snd_w_inv ? "" : "un");
}
}
static void handle_connect_req(struct rdma_cm_id *new_cma_id,
struct rdma_conn_param *param)
{
struct svcxprt_rdma *listen_xprt = new_cma_id->context;
struct svcxprt_rdma *newxprt;
struct sockaddr *sa;
newxprt = rdma_create_xprt(listen_xprt->sc_xprt.xpt_server, 0);
if (!newxprt) {
dprintk("svcrdma: failed to create new transport\n");
return;
}
newxprt->sc_cm_id = new_cma_id;
new_cma_id->context = newxprt;
dprintk("svcrdma: Creating newxprt=%p, cm_id=%p, listenxprt=%p\n",
newxprt, newxprt->sc_cm_id, listen_xprt);
svc_rdma_parse_connect_private(newxprt, param);
newxprt->sc_ord = param->initiator_depth;
sa = (struct sockaddr *)&newxprt->sc_cm_id->route.addr.dst_addr;
svc_xprt_set_remote(&newxprt->sc_xprt, sa, svc_addr_len(sa));
sa = (struct sockaddr *)&newxprt->sc_cm_id->route.addr.src_addr;
svc_xprt_set_local(&newxprt->sc_xprt, sa, svc_addr_len(sa));
spin_lock_bh(&listen_xprt->sc_lock);
list_add_tail(&newxprt->sc_accept_q, &listen_xprt->sc_accept_q);
spin_unlock_bh(&listen_xprt->sc_lock);
set_bit(XPT_CONN, &listen_xprt->sc_xprt.xpt_flags);
svc_xprt_enqueue(&listen_xprt->sc_xprt);
}
static int rdma_listen_handler(struct rdma_cm_id *cma_id,
struct rdma_cm_event *event)
{
struct svcxprt_rdma *xprt = cma_id->context;
int ret = 0;
switch (event->event) {
case RDMA_CM_EVENT_CONNECT_REQUEST:
dprintk("svcrdma: Connect request on cma_id=%p, xprt = %p, "
"event = %s (%d)\n", cma_id, cma_id->context,
rdma_event_msg(event->event), event->event);
handle_connect_req(cma_id, &event->param.conn);
break;
case RDMA_CM_EVENT_ESTABLISHED:
dprintk("svcrdma: Connection completed on LISTEN xprt=%p, "
"cm_id=%p\n", xprt, cma_id);
break;
case RDMA_CM_EVENT_DEVICE_REMOVAL:
dprintk("svcrdma: Device removal xprt=%p, cm_id=%p\n",
xprt, cma_id);
if (xprt)
set_bit(XPT_CLOSE, &xprt->sc_xprt.xpt_flags);
break;
default:
dprintk("svcrdma: Unexpected event on listening endpoint %p, "
"event = %s (%d)\n", cma_id,
rdma_event_msg(event->event), event->event);
break;
}
return ret;
}
static int rdma_cma_handler(struct rdma_cm_id *cma_id,
struct rdma_cm_event *event)
{
struct svc_xprt *xprt = cma_id->context;
struct svcxprt_rdma *rdma =
container_of(xprt, struct svcxprt_rdma, sc_xprt);
switch (event->event) {
case RDMA_CM_EVENT_ESTABLISHED:
svc_xprt_get(xprt);
dprintk("svcrdma: Connection completed on DTO xprt=%p, "
"cm_id=%p\n", xprt, cma_id);
clear_bit(RDMAXPRT_CONN_PENDING, &rdma->sc_flags);
svc_xprt_enqueue(xprt);
break;
case RDMA_CM_EVENT_DISCONNECTED:
dprintk("svcrdma: Disconnect on DTO xprt=%p, cm_id=%p\n",
xprt, cma_id);
if (xprt) {
set_bit(XPT_CLOSE, &xprt->xpt_flags);
svc_xprt_enqueue(xprt);
svc_xprt_put(xprt);
}
break;
case RDMA_CM_EVENT_DEVICE_REMOVAL:
dprintk("svcrdma: Device removal cma_id=%p, xprt = %p, "
"event = %s (%d)\n", cma_id, xprt,
rdma_event_msg(event->event), event->event);
if (xprt) {
set_bit(XPT_CLOSE, &xprt->xpt_flags);
svc_xprt_enqueue(xprt);
svc_xprt_put(xprt);
}
break;
default:
dprintk("svcrdma: Unexpected event on DTO endpoint %p, "
"event = %s (%d)\n", cma_id,
rdma_event_msg(event->event), event->event);
break;
}
return 0;
}
static struct svc_xprt *svc_rdma_create(struct svc_serv *serv,
struct net *net,
struct sockaddr *sa, int salen,
int flags)
{
struct rdma_cm_id *listen_id;
struct svcxprt_rdma *cma_xprt;
int ret;
dprintk("svcrdma: Creating RDMA socket\n");
if ((sa->sa_family != AF_INET) && (sa->sa_family != AF_INET6)) {
dprintk("svcrdma: Address family %d is not supported.\n", sa->sa_family);
return ERR_PTR(-EAFNOSUPPORT);
}
cma_xprt = rdma_create_xprt(serv, 1);
if (!cma_xprt)
return ERR_PTR(-ENOMEM);
listen_id = rdma_create_id(&init_net, rdma_listen_handler, cma_xprt,
RDMA_PS_TCP, IB_QPT_RC);
if (IS_ERR(listen_id)) {
ret = PTR_ERR(listen_id);
dprintk("svcrdma: rdma_create_id failed = %d\n", ret);
goto err0;
}
#if IS_ENABLED(CONFIG_IPV6)
ret = rdma_set_afonly(listen_id, 1);
if (ret) {
dprintk("svcrdma: rdma_set_afonly failed = %d\n", ret);
goto err1;
}
#endif
ret = rdma_bind_addr(listen_id, sa);
if (ret) {
dprintk("svcrdma: rdma_bind_addr failed = %d\n", ret);
goto err1;
}
cma_xprt->sc_cm_id = listen_id;
ret = rdma_listen(listen_id, RPCRDMA_LISTEN_BACKLOG);
if (ret) {
dprintk("svcrdma: rdma_listen failed = %d\n", ret);
goto err1;
}
sa = (struct sockaddr *)&cma_xprt->sc_cm_id->route.addr.src_addr;
svc_xprt_set_local(&cma_xprt->sc_xprt, sa, salen);
return &cma_xprt->sc_xprt;
err1:
rdma_destroy_id(listen_id);
err0:
kfree(cma_xprt);
return ERR_PTR(ret);
}
static struct svc_rdma_fastreg_mr *rdma_alloc_frmr(struct svcxprt_rdma *xprt)
{
struct ib_mr *mr;
struct scatterlist *sg;
struct svc_rdma_fastreg_mr *frmr;
u32 num_sg;
frmr = kmalloc(sizeof(*frmr), GFP_KERNEL);
if (!frmr)
goto err;
num_sg = min_t(u32, RPCSVC_MAXPAGES, xprt->sc_frmr_pg_list_len);
mr = ib_alloc_mr(xprt->sc_pd, IB_MR_TYPE_MEM_REG, num_sg);
if (IS_ERR(mr))
goto err_free_frmr;
sg = kcalloc(RPCSVC_MAXPAGES, sizeof(*sg), GFP_KERNEL);
if (!sg)
goto err_free_mr;
sg_init_table(sg, RPCSVC_MAXPAGES);
frmr->mr = mr;
frmr->sg = sg;
INIT_LIST_HEAD(&frmr->frmr_list);
return frmr;
err_free_mr:
ib_dereg_mr(mr);
err_free_frmr:
kfree(frmr);
err:
return ERR_PTR(-ENOMEM);
}
static void rdma_dealloc_frmr_q(struct svcxprt_rdma *xprt)
{
struct svc_rdma_fastreg_mr *frmr;
while (!list_empty(&xprt->sc_frmr_q)) {
frmr = list_entry(xprt->sc_frmr_q.next,
struct svc_rdma_fastreg_mr, frmr_list);
list_del_init(&frmr->frmr_list);
kfree(frmr->sg);
ib_dereg_mr(frmr->mr);
kfree(frmr);
}
}
struct svc_rdma_fastreg_mr *svc_rdma_get_frmr(struct svcxprt_rdma *rdma)
{
struct svc_rdma_fastreg_mr *frmr = NULL;
spin_lock(&rdma->sc_frmr_q_lock);
if (!list_empty(&rdma->sc_frmr_q)) {
frmr = list_entry(rdma->sc_frmr_q.next,
struct svc_rdma_fastreg_mr, frmr_list);
list_del_init(&frmr->frmr_list);
frmr->sg_nents = 0;
}
spin_unlock(&rdma->sc_frmr_q_lock);
if (frmr)
return frmr;
return rdma_alloc_frmr(rdma);
}
void svc_rdma_put_frmr(struct svcxprt_rdma *rdma,
struct svc_rdma_fastreg_mr *frmr)
{
if (frmr) {
ib_dma_unmap_sg(rdma->sc_cm_id->device,
frmr->sg, frmr->sg_nents, frmr->direction);
spin_lock(&rdma->sc_frmr_q_lock);
WARN_ON_ONCE(!list_empty(&frmr->frmr_list));
list_add(&frmr->frmr_list, &rdma->sc_frmr_q);
spin_unlock(&rdma->sc_frmr_q_lock);
}
}
static struct svc_xprt *svc_rdma_accept(struct svc_xprt *xprt)
{
struct svcxprt_rdma *listen_rdma;
struct svcxprt_rdma *newxprt = NULL;
struct rdma_conn_param conn_param;
struct rpcrdma_connect_private pmsg;
struct ib_qp_init_attr qp_attr;
struct ib_device *dev;
struct sockaddr *sap;
unsigned int i;
int ret = 0;
listen_rdma = container_of(xprt, struct svcxprt_rdma, sc_xprt);
clear_bit(XPT_CONN, &xprt->xpt_flags);
spin_lock_bh(&listen_rdma->sc_lock);
if (!list_empty(&listen_rdma->sc_accept_q)) {
newxprt = list_entry(listen_rdma->sc_accept_q.next,
struct svcxprt_rdma, sc_accept_q);
list_del_init(&newxprt->sc_accept_q);
}
if (!list_empty(&listen_rdma->sc_accept_q))
set_bit(XPT_CONN, &listen_rdma->sc_xprt.xpt_flags);
spin_unlock_bh(&listen_rdma->sc_lock);
if (!newxprt)
return NULL;
dprintk("svcrdma: newxprt from accept queue = %p, cm_id=%p\n",
newxprt, newxprt->sc_cm_id);
dev = newxprt->sc_cm_id->device;
newxprt->sc_max_sge = min((size_t)dev->attrs.max_sge,
(size_t)RPCSVC_MAXPAGES);
newxprt->sc_max_sge_rd = min_t(size_t, dev->attrs.max_sge_rd,
RPCSVC_MAXPAGES);
newxprt->sc_max_req_size = svcrdma_max_req_size;
newxprt->sc_max_requests = min_t(u32, dev->attrs.max_qp_wr,
svcrdma_max_requests);
newxprt->sc_fc_credits = cpu_to_be32(newxprt->sc_max_requests);
newxprt->sc_max_bc_requests = min_t(u32, dev->attrs.max_qp_wr,
svcrdma_max_bc_requests);
newxprt->sc_rq_depth = newxprt->sc_max_requests +
newxprt->sc_max_bc_requests;
newxprt->sc_sq_depth = RPCRDMA_SQ_DEPTH_MULT * newxprt->sc_rq_depth;
atomic_set(&newxprt->sc_sq_avail, newxprt->sc_sq_depth);
if (!svc_rdma_prealloc_ctxts(newxprt))
goto errout;
if (!svc_rdma_prealloc_maps(newxprt))
goto errout;
newxprt->sc_ord = min_t(size_t, dev->attrs.max_qp_rd_atom, newxprt->sc_ord);
newxprt->sc_ord = min_t(size_t, svcrdma_ord, newxprt->sc_ord);
newxprt->sc_pd = ib_alloc_pd(dev, 0);
if (IS_ERR(newxprt->sc_pd)) {
dprintk("svcrdma: error creating PD for connect request\n");
goto errout;
}
newxprt->sc_sq_cq = ib_alloc_cq(dev, newxprt, newxprt->sc_sq_depth,
0, IB_POLL_WORKQUEUE);
if (IS_ERR(newxprt->sc_sq_cq)) {
dprintk("svcrdma: error creating SQ CQ for connect request\n");
goto errout;
}
newxprt->sc_rq_cq = ib_alloc_cq(dev, newxprt, newxprt->sc_rq_depth,
0, IB_POLL_WORKQUEUE);
if (IS_ERR(newxprt->sc_rq_cq)) {
dprintk("svcrdma: error creating RQ CQ for connect request\n");
goto errout;
}
memset(&qp_attr, 0, sizeof qp_attr);
qp_attr.event_handler = qp_event_handler;
qp_attr.qp_context = &newxprt->sc_xprt;
qp_attr.cap.max_send_wr = newxprt->sc_sq_depth;
qp_attr.cap.max_recv_wr = newxprt->sc_rq_depth;
qp_attr.cap.max_send_sge = newxprt->sc_max_sge;
qp_attr.cap.max_recv_sge = newxprt->sc_max_sge;
qp_attr.sq_sig_type = IB_SIGNAL_REQ_WR;
qp_attr.qp_type = IB_QPT_RC;
qp_attr.send_cq = newxprt->sc_sq_cq;
qp_attr.recv_cq = newxprt->sc_rq_cq;
dprintk("svcrdma: newxprt->sc_cm_id=%p, newxprt->sc_pd=%p\n",
newxprt->sc_cm_id, newxprt->sc_pd);
dprintk(" cap.max_send_wr = %d, cap.max_recv_wr = %d\n",
qp_attr.cap.max_send_wr, qp_attr.cap.max_recv_wr);
dprintk(" cap.max_send_sge = %d, cap.max_recv_sge = %d\n",
qp_attr.cap.max_send_sge, qp_attr.cap.max_recv_sge);
ret = rdma_create_qp(newxprt->sc_cm_id, newxprt->sc_pd, &qp_attr);
if (ret) {
dprintk("svcrdma: failed to create QP, ret=%d\n", ret);
goto errout;
}
newxprt->sc_qp = newxprt->sc_cm_id->qp;
newxprt->sc_reader = rdma_read_chunk_lcl;
if (dev->attrs.device_cap_flags & IB_DEVICE_MEM_MGT_EXTENSIONS) {
newxprt->sc_frmr_pg_list_len =
dev->attrs.max_fast_reg_page_list_len;
newxprt->sc_dev_caps |= SVCRDMA_DEVCAP_FAST_REG;
newxprt->sc_reader = rdma_read_chunk_frmr;
} else
newxprt->sc_snd_w_inv = false;
if (!rdma_protocol_iwarp(dev, newxprt->sc_cm_id->port_num) &&
!rdma_ib_or_roce(dev, newxprt->sc_cm_id->port_num))
goto errout;
if (rdma_protocol_iwarp(dev, newxprt->sc_cm_id->port_num))
newxprt->sc_dev_caps |= SVCRDMA_DEVCAP_READ_W_INV;
for (i = 0; i < newxprt->sc_max_requests; i++) {
ret = svc_rdma_post_recv(newxprt, GFP_KERNEL);
if (ret) {
dprintk("svcrdma: failure posting receive buffers\n");
goto errout;
}
}
newxprt->sc_cm_id->event_handler = rdma_cma_handler;
pmsg.cp_magic = rpcrdma_cmp_magic;
pmsg.cp_version = RPCRDMA_CMP_VERSION;
pmsg.cp_flags = 0;
pmsg.cp_send_size = pmsg.cp_recv_size =
rpcrdma_encode_buffer_size(newxprt->sc_max_req_size);
set_bit(RDMAXPRT_CONN_PENDING, &newxprt->sc_flags);
memset(&conn_param, 0, sizeof conn_param);
conn_param.responder_resources = 0;
conn_param.initiator_depth = newxprt->sc_ord;
conn_param.private_data = &pmsg;
conn_param.private_data_len = sizeof(pmsg);
ret = rdma_accept(newxprt->sc_cm_id, &conn_param);
if (ret) {
dprintk("svcrdma: failed to accept new connection, ret=%d\n",
ret);
goto errout;
}
dprintk("svcrdma: new connection %p accepted:\n", newxprt);
sap = (struct sockaddr *)&newxprt->sc_cm_id->route.addr.src_addr;
dprintk(" local address : %pIS:%u\n", sap, rpc_get_port(sap));
sap = (struct sockaddr *)&newxprt->sc_cm_id->route.addr.dst_addr;
dprintk(" remote address : %pIS:%u\n", sap, rpc_get_port(sap));
dprintk(" max_sge : %d\n", newxprt->sc_max_sge);
dprintk(" max_sge_rd : %d\n", newxprt->sc_max_sge_rd);
dprintk(" sq_depth : %d\n", newxprt->sc_sq_depth);
dprintk(" max_requests : %d\n", newxprt->sc_max_requests);
dprintk(" ord : %d\n", newxprt->sc_ord);
return &newxprt->sc_xprt;
errout:
dprintk("svcrdma: failure accepting new connection rc=%d.\n", ret);
svc_xprt_get(&newxprt->sc_xprt);
if (newxprt->sc_qp && !IS_ERR(newxprt->sc_qp))
ib_destroy_qp(newxprt->sc_qp);
rdma_destroy_id(newxprt->sc_cm_id);
svc_xprt_put(&newxprt->sc_xprt);
return NULL;
}
static void svc_rdma_release_rqst(struct svc_rqst *rqstp)
{
}
static void svc_rdma_detach(struct svc_xprt *xprt)
{
struct svcxprt_rdma *rdma =
container_of(xprt, struct svcxprt_rdma, sc_xprt);
dprintk("svc: svc_rdma_detach(%p)\n", xprt);
rdma_disconnect(rdma->sc_cm_id);
}
static void __svc_rdma_free(struct work_struct *work)
{
struct svcxprt_rdma *rdma =
container_of(work, struct svcxprt_rdma, sc_work);
struct svc_xprt *xprt = &rdma->sc_xprt;
dprintk("svcrdma: %s(%p)\n", __func__, rdma);
if (rdma->sc_qp && !IS_ERR(rdma->sc_qp))
ib_drain_qp(rdma->sc_qp);
if (kref_read(&xprt->xpt_ref) != 0)
pr_err("svcrdma: sc_xprt still in use? (%d)\n",
kref_read(&xprt->xpt_ref));
while (!list_empty(&rdma->sc_read_complete_q)) {
struct svc_rdma_op_ctxt *ctxt;
ctxt = list_first_entry(&rdma->sc_read_complete_q,
struct svc_rdma_op_ctxt, list);
list_del(&ctxt->list);
svc_rdma_put_context(ctxt, 1);
}
while (!list_empty(&rdma->sc_rq_dto_q)) {
struct svc_rdma_op_ctxt *ctxt;
ctxt = list_first_entry(&rdma->sc_rq_dto_q,
struct svc_rdma_op_ctxt, list);
list_del(&ctxt->list);
svc_rdma_put_context(ctxt, 1);
}
if (rdma->sc_ctxt_used != 0)
pr_err("svcrdma: ctxt still in use? (%d)\n",
rdma->sc_ctxt_used);
if (xprt->xpt_bc_xprt) {
xprt_put(xprt->xpt_bc_xprt);
xprt->xpt_bc_xprt = NULL;
}
rdma_dealloc_frmr_q(rdma);
svc_rdma_destroy_ctxts(rdma);
svc_rdma_destroy_maps(rdma);
if (rdma->sc_qp && !IS_ERR(rdma->sc_qp))
ib_destroy_qp(rdma->sc_qp);
if (rdma->sc_sq_cq && !IS_ERR(rdma->sc_sq_cq))
ib_free_cq(rdma->sc_sq_cq);
if (rdma->sc_rq_cq && !IS_ERR(rdma->sc_rq_cq))
ib_free_cq(rdma->sc_rq_cq);
if (rdma->sc_pd && !IS_ERR(rdma->sc_pd))
ib_dealloc_pd(rdma->sc_pd);
rdma_destroy_id(rdma->sc_cm_id);
kfree(rdma);
}
static void svc_rdma_free(struct svc_xprt *xprt)
{
struct svcxprt_rdma *rdma =
container_of(xprt, struct svcxprt_rdma, sc_xprt);
INIT_WORK(&rdma->sc_work, __svc_rdma_free);
queue_work(svc_rdma_wq, &rdma->sc_work);
}
static int svc_rdma_has_wspace(struct svc_xprt *xprt)
{
struct svcxprt_rdma *rdma =
container_of(xprt, struct svcxprt_rdma, sc_xprt);
if (waitqueue_active(&rdma->sc_send_wait))
return 0;
return 1;
}
static int svc_rdma_secure_port(struct svc_rqst *rqstp)
{
return 1;
}
static void svc_rdma_kill_temp_xprt(struct svc_xprt *xprt)
{
}
int svc_rdma_send(struct svcxprt_rdma *xprt, struct ib_send_wr *wr)
{
struct ib_send_wr *bad_wr, *n_wr;
int wr_count;
int i;
int ret;
if (test_bit(XPT_CLOSE, &xprt->sc_xprt.xpt_flags))
return -ENOTCONN;
wr_count = 1;
for (n_wr = wr->next; n_wr; n_wr = n_wr->next)
wr_count++;
while (1) {
if ((atomic_sub_return(wr_count, &xprt->sc_sq_avail) < 0)) {
atomic_inc(&rdma_stat_sq_starve);
atomic_add(wr_count, &xprt->sc_sq_avail);
wait_event(xprt->sc_send_wait,
atomic_read(&xprt->sc_sq_avail) > wr_count);
if (test_bit(XPT_CLOSE, &xprt->sc_xprt.xpt_flags))
return -ENOTCONN;
continue;
}
for (i = 0; i < wr_count; i++)
svc_xprt_get(&xprt->sc_xprt);
ret = ib_post_send(xprt->sc_qp, wr, &bad_wr);
if (ret) {
set_bit(XPT_CLOSE, &xprt->sc_xprt.xpt_flags);
for (i = 0; i < wr_count; i ++)
svc_xprt_put(&xprt->sc_xprt);
dprintk("svcrdma: failed to post SQ WR rc=%d\n", ret);
dprintk(" sc_sq_avail=%d, sc_sq_depth=%d\n",
atomic_read(&xprt->sc_sq_avail),
xprt->sc_sq_depth);
wake_up(&xprt->sc_send_wait);
}
break;
}
return ret;
}
