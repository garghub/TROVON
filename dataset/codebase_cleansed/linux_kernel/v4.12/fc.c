static inline struct nvme_fc_ctrl *
to_fc_ctrl(struct nvme_ctrl *ctrl)
{
return container_of(ctrl, struct nvme_fc_ctrl, ctrl);
}
static inline struct nvme_fc_lport *
localport_to_lport(struct nvme_fc_local_port *portptr)
{
return container_of(portptr, struct nvme_fc_lport, localport);
}
static inline struct nvme_fc_rport *
remoteport_to_rport(struct nvme_fc_remote_port *portptr)
{
return container_of(portptr, struct nvme_fc_rport, remoteport);
}
static inline struct nvmefc_ls_req_op *
ls_req_to_lsop(struct nvmefc_ls_req *lsreq)
{
return container_of(lsreq, struct nvmefc_ls_req_op, ls_req);
}
static inline struct nvme_fc_fcp_op *
fcp_req_to_fcp_op(struct nvmefc_fcp_req *fcpreq)
{
return container_of(fcpreq, struct nvme_fc_fcp_op, fcp_req);
}
int
nvme_fc_register_localport(struct nvme_fc_port_info *pinfo,
struct nvme_fc_port_template *template,
struct device *dev,
struct nvme_fc_local_port **portptr)
{
struct nvme_fc_lport *newrec;
unsigned long flags;
int ret, idx;
if (!template->localport_delete || !template->remoteport_delete ||
!template->ls_req || !template->fcp_io ||
!template->ls_abort || !template->fcp_abort ||
!template->max_hw_queues || !template->max_sgl_segments ||
!template->max_dif_sgl_segments || !template->dma_boundary) {
ret = -EINVAL;
goto out_reghost_failed;
}
newrec = kmalloc((sizeof(*newrec) + template->local_priv_sz),
GFP_KERNEL);
if (!newrec) {
ret = -ENOMEM;
goto out_reghost_failed;
}
idx = ida_simple_get(&nvme_fc_local_port_cnt, 0, 0, GFP_KERNEL);
if (idx < 0) {
ret = -ENOSPC;
goto out_fail_kfree;
}
if (!get_device(dev) && dev) {
ret = -ENODEV;
goto out_ida_put;
}
INIT_LIST_HEAD(&newrec->port_list);
INIT_LIST_HEAD(&newrec->endp_list);
kref_init(&newrec->ref);
newrec->ops = template;
newrec->dev = dev;
ida_init(&newrec->endp_cnt);
newrec->localport.private = &newrec[1];
newrec->localport.node_name = pinfo->node_name;
newrec->localport.port_name = pinfo->port_name;
newrec->localport.port_role = pinfo->port_role;
newrec->localport.port_id = pinfo->port_id;
newrec->localport.port_state = FC_OBJSTATE_ONLINE;
newrec->localport.port_num = idx;
spin_lock_irqsave(&nvme_fc_lock, flags);
list_add_tail(&newrec->port_list, &nvme_fc_lport_list);
spin_unlock_irqrestore(&nvme_fc_lock, flags);
if (dev)
dma_set_seg_boundary(dev, template->dma_boundary);
*portptr = &newrec->localport;
return 0;
out_ida_put:
ida_simple_remove(&nvme_fc_local_port_cnt, idx);
out_fail_kfree:
kfree(newrec);
out_reghost_failed:
*portptr = NULL;
return ret;
}
static void
nvme_fc_free_lport(struct kref *ref)
{
struct nvme_fc_lport *lport =
container_of(ref, struct nvme_fc_lport, ref);
unsigned long flags;
WARN_ON(lport->localport.port_state != FC_OBJSTATE_DELETED);
WARN_ON(!list_empty(&lport->endp_list));
spin_lock_irqsave(&nvme_fc_lock, flags);
list_del(&lport->port_list);
spin_unlock_irqrestore(&nvme_fc_lock, flags);
lport->ops->localport_delete(&lport->localport);
ida_simple_remove(&nvme_fc_local_port_cnt, lport->localport.port_num);
ida_destroy(&lport->endp_cnt);
put_device(lport->dev);
kfree(lport);
}
static void
nvme_fc_lport_put(struct nvme_fc_lport *lport)
{
kref_put(&lport->ref, nvme_fc_free_lport);
}
static int
nvme_fc_lport_get(struct nvme_fc_lport *lport)
{
return kref_get_unless_zero(&lport->ref);
}
int
nvme_fc_unregister_localport(struct nvme_fc_local_port *portptr)
{
struct nvme_fc_lport *lport = localport_to_lport(portptr);
unsigned long flags;
if (!portptr)
return -EINVAL;
spin_lock_irqsave(&nvme_fc_lock, flags);
if (portptr->port_state != FC_OBJSTATE_ONLINE) {
spin_unlock_irqrestore(&nvme_fc_lock, flags);
return -EINVAL;
}
portptr->port_state = FC_OBJSTATE_DELETED;
spin_unlock_irqrestore(&nvme_fc_lock, flags);
nvme_fc_lport_put(lport);
return 0;
}
int
nvme_fc_register_remoteport(struct nvme_fc_local_port *localport,
struct nvme_fc_port_info *pinfo,
struct nvme_fc_remote_port **portptr)
{
struct nvme_fc_lport *lport = localport_to_lport(localport);
struct nvme_fc_rport *newrec;
unsigned long flags;
int ret, idx;
newrec = kmalloc((sizeof(*newrec) + lport->ops->remote_priv_sz),
GFP_KERNEL);
if (!newrec) {
ret = -ENOMEM;
goto out_reghost_failed;
}
if (!nvme_fc_lport_get(lport)) {
ret = -ESHUTDOWN;
goto out_kfree_rport;
}
idx = ida_simple_get(&lport->endp_cnt, 0, 0, GFP_KERNEL);
if (idx < 0) {
ret = -ENOSPC;
goto out_lport_put;
}
INIT_LIST_HEAD(&newrec->endp_list);
INIT_LIST_HEAD(&newrec->ctrl_list);
INIT_LIST_HEAD(&newrec->ls_req_list);
kref_init(&newrec->ref);
spin_lock_init(&newrec->lock);
newrec->remoteport.localport = &lport->localport;
newrec->dev = lport->dev;
newrec->lport = lport;
newrec->remoteport.private = &newrec[1];
newrec->remoteport.port_role = pinfo->port_role;
newrec->remoteport.node_name = pinfo->node_name;
newrec->remoteport.port_name = pinfo->port_name;
newrec->remoteport.port_id = pinfo->port_id;
newrec->remoteport.port_state = FC_OBJSTATE_ONLINE;
newrec->remoteport.port_num = idx;
spin_lock_irqsave(&nvme_fc_lock, flags);
list_add_tail(&newrec->endp_list, &lport->endp_list);
spin_unlock_irqrestore(&nvme_fc_lock, flags);
*portptr = &newrec->remoteport;
return 0;
out_lport_put:
nvme_fc_lport_put(lport);
out_kfree_rport:
kfree(newrec);
out_reghost_failed:
*portptr = NULL;
return ret;
}
static void
nvme_fc_free_rport(struct kref *ref)
{
struct nvme_fc_rport *rport =
container_of(ref, struct nvme_fc_rport, ref);
struct nvme_fc_lport *lport =
localport_to_lport(rport->remoteport.localport);
unsigned long flags;
WARN_ON(rport->remoteport.port_state != FC_OBJSTATE_DELETED);
WARN_ON(!list_empty(&rport->ctrl_list));
spin_lock_irqsave(&nvme_fc_lock, flags);
list_del(&rport->endp_list);
spin_unlock_irqrestore(&nvme_fc_lock, flags);
lport->ops->remoteport_delete(&rport->remoteport);
ida_simple_remove(&lport->endp_cnt, rport->remoteport.port_num);
kfree(rport);
nvme_fc_lport_put(lport);
}
static void
nvme_fc_rport_put(struct nvme_fc_rport *rport)
{
kref_put(&rport->ref, nvme_fc_free_rport);
}
static int
nvme_fc_rport_get(struct nvme_fc_rport *rport)
{
return kref_get_unless_zero(&rport->ref);
}
static int
nvme_fc_abort_lsops(struct nvme_fc_rport *rport)
{
struct nvmefc_ls_req_op *lsop;
unsigned long flags;
restart:
spin_lock_irqsave(&rport->lock, flags);
list_for_each_entry(lsop, &rport->ls_req_list, lsreq_list) {
if (!(lsop->flags & FCOP_FLAGS_TERMIO)) {
lsop->flags |= FCOP_FLAGS_TERMIO;
spin_unlock_irqrestore(&rport->lock, flags);
rport->lport->ops->ls_abort(&rport->lport->localport,
&rport->remoteport,
&lsop->ls_req);
goto restart;
}
}
spin_unlock_irqrestore(&rport->lock, flags);
return 0;
}
int
nvme_fc_unregister_remoteport(struct nvme_fc_remote_port *portptr)
{
struct nvme_fc_rport *rport = remoteport_to_rport(portptr);
struct nvme_fc_ctrl *ctrl;
unsigned long flags;
if (!portptr)
return -EINVAL;
spin_lock_irqsave(&rport->lock, flags);
if (portptr->port_state != FC_OBJSTATE_ONLINE) {
spin_unlock_irqrestore(&rport->lock, flags);
return -EINVAL;
}
portptr->port_state = FC_OBJSTATE_DELETED;
list_for_each_entry(ctrl, &rport->ctrl_list, ctrl_list)
__nvme_fc_del_ctrl(ctrl);
spin_unlock_irqrestore(&rport->lock, flags);
nvme_fc_abort_lsops(rport);
nvme_fc_rport_put(rport);
return 0;
}
static inline dma_addr_t
fc_dma_map_single(struct device *dev, void *ptr, size_t size,
enum dma_data_direction dir)
{
return dev ? dma_map_single(dev, ptr, size, dir) : (dma_addr_t)0L;
}
static inline int
fc_dma_mapping_error(struct device *dev, dma_addr_t dma_addr)
{
return dev ? dma_mapping_error(dev, dma_addr) : 0;
}
static inline void
fc_dma_unmap_single(struct device *dev, dma_addr_t addr, size_t size,
enum dma_data_direction dir)
{
if (dev)
dma_unmap_single(dev, addr, size, dir);
}
static inline void
fc_dma_sync_single_for_cpu(struct device *dev, dma_addr_t addr, size_t size,
enum dma_data_direction dir)
{
if (dev)
dma_sync_single_for_cpu(dev, addr, size, dir);
}
static inline void
fc_dma_sync_single_for_device(struct device *dev, dma_addr_t addr, size_t size,
enum dma_data_direction dir)
{
if (dev)
dma_sync_single_for_device(dev, addr, size, dir);
}
static int
fc_map_sg(struct scatterlist *sg, int nents)
{
struct scatterlist *s;
int i;
WARN_ON(nents == 0 || sg[0].length == 0);
for_each_sg(sg, s, nents, i) {
s->dma_address = 0L;
#ifdef CONFIG_NEED_SG_DMA_LENGTH
s->dma_length = s->length;
#endif
}
return nents;
}
static inline int
fc_dma_map_sg(struct device *dev, struct scatterlist *sg, int nents,
enum dma_data_direction dir)
{
return dev ? dma_map_sg(dev, sg, nents, dir) : fc_map_sg(sg, nents);
}
static inline void
fc_dma_unmap_sg(struct device *dev, struct scatterlist *sg, int nents,
enum dma_data_direction dir)
{
if (dev)
dma_unmap_sg(dev, sg, nents, dir);
}
static void
__nvme_fc_finish_ls_req(struct nvmefc_ls_req_op *lsop)
{
struct nvme_fc_rport *rport = lsop->rport;
struct nvmefc_ls_req *lsreq = &lsop->ls_req;
unsigned long flags;
spin_lock_irqsave(&rport->lock, flags);
if (!lsop->req_queued) {
spin_unlock_irqrestore(&rport->lock, flags);
return;
}
list_del(&lsop->lsreq_list);
lsop->req_queued = false;
spin_unlock_irqrestore(&rport->lock, flags);
fc_dma_unmap_single(rport->dev, lsreq->rqstdma,
(lsreq->rqstlen + lsreq->rsplen),
DMA_BIDIRECTIONAL);
nvme_fc_rport_put(rport);
}
static int
__nvme_fc_send_ls_req(struct nvme_fc_rport *rport,
struct nvmefc_ls_req_op *lsop,
void (*done)(struct nvmefc_ls_req *req, int status))
{
struct nvmefc_ls_req *lsreq = &lsop->ls_req;
unsigned long flags;
int ret = 0;
if (rport->remoteport.port_state != FC_OBJSTATE_ONLINE)
return -ECONNREFUSED;
if (!nvme_fc_rport_get(rport))
return -ESHUTDOWN;
lsreq->done = done;
lsop->rport = rport;
lsop->req_queued = false;
INIT_LIST_HEAD(&lsop->lsreq_list);
init_completion(&lsop->ls_done);
lsreq->rqstdma = fc_dma_map_single(rport->dev, lsreq->rqstaddr,
lsreq->rqstlen + lsreq->rsplen,
DMA_BIDIRECTIONAL);
if (fc_dma_mapping_error(rport->dev, lsreq->rqstdma)) {
ret = -EFAULT;
goto out_putrport;
}
lsreq->rspdma = lsreq->rqstdma + lsreq->rqstlen;
spin_lock_irqsave(&rport->lock, flags);
list_add_tail(&lsop->lsreq_list, &rport->ls_req_list);
lsop->req_queued = true;
spin_unlock_irqrestore(&rport->lock, flags);
ret = rport->lport->ops->ls_req(&rport->lport->localport,
&rport->remoteport, lsreq);
if (ret)
goto out_unlink;
return 0;
out_unlink:
lsop->ls_error = ret;
spin_lock_irqsave(&rport->lock, flags);
lsop->req_queued = false;
list_del(&lsop->lsreq_list);
spin_unlock_irqrestore(&rport->lock, flags);
fc_dma_unmap_single(rport->dev, lsreq->rqstdma,
(lsreq->rqstlen + lsreq->rsplen),
DMA_BIDIRECTIONAL);
out_putrport:
nvme_fc_rport_put(rport);
return ret;
}
static void
nvme_fc_send_ls_req_done(struct nvmefc_ls_req *lsreq, int status)
{
struct nvmefc_ls_req_op *lsop = ls_req_to_lsop(lsreq);
lsop->ls_error = status;
complete(&lsop->ls_done);
}
static int
nvme_fc_send_ls_req(struct nvme_fc_rport *rport, struct nvmefc_ls_req_op *lsop)
{
struct nvmefc_ls_req *lsreq = &lsop->ls_req;
struct fcnvme_ls_rjt *rjt = lsreq->rspaddr;
int ret;
ret = __nvme_fc_send_ls_req(rport, lsop, nvme_fc_send_ls_req_done);
if (!ret) {
wait_for_completion(&lsop->ls_done);
__nvme_fc_finish_ls_req(lsop);
ret = lsop->ls_error;
}
if (ret)
return ret;
if (rjt->w0.ls_cmd == FCNVME_LS_RJT)
return -ENXIO;
return 0;
}
static int
nvme_fc_send_ls_req_async(struct nvme_fc_rport *rport,
struct nvmefc_ls_req_op *lsop,
void (*done)(struct nvmefc_ls_req *req, int status))
{
return __nvme_fc_send_ls_req(rport, lsop, done);
}
static int
nvme_fc_connect_admin_queue(struct nvme_fc_ctrl *ctrl,
struct nvme_fc_queue *queue, u16 qsize, u16 ersp_ratio)
{
struct nvmefc_ls_req_op *lsop;
struct nvmefc_ls_req *lsreq;
struct fcnvme_ls_cr_assoc_rqst *assoc_rqst;
struct fcnvme_ls_cr_assoc_acc *assoc_acc;
int ret, fcret = 0;
lsop = kzalloc((sizeof(*lsop) +
ctrl->lport->ops->lsrqst_priv_sz +
sizeof(*assoc_rqst) + sizeof(*assoc_acc)), GFP_KERNEL);
if (!lsop) {
ret = -ENOMEM;
goto out_no_memory;
}
lsreq = &lsop->ls_req;
lsreq->private = (void *)&lsop[1];
assoc_rqst = (struct fcnvme_ls_cr_assoc_rqst *)
(lsreq->private + ctrl->lport->ops->lsrqst_priv_sz);
assoc_acc = (struct fcnvme_ls_cr_assoc_acc *)&assoc_rqst[1];
assoc_rqst->w0.ls_cmd = FCNVME_LS_CREATE_ASSOCIATION;
assoc_rqst->desc_list_len =
cpu_to_be32(sizeof(struct fcnvme_lsdesc_cr_assoc_cmd));
assoc_rqst->assoc_cmd.desc_tag =
cpu_to_be32(FCNVME_LSDESC_CREATE_ASSOC_CMD);
assoc_rqst->assoc_cmd.desc_len =
fcnvme_lsdesc_len(
sizeof(struct fcnvme_lsdesc_cr_assoc_cmd));
assoc_rqst->assoc_cmd.ersp_ratio = cpu_to_be16(ersp_ratio);
assoc_rqst->assoc_cmd.sqsize = cpu_to_be16(qsize);
assoc_rqst->assoc_cmd.cntlid = cpu_to_be16(0xffff);
memcpy(&assoc_rqst->assoc_cmd.hostid, &ctrl->ctrl.opts->host->id,
min_t(size_t, FCNVME_ASSOC_HOSTID_LEN, sizeof(uuid_be)));
strncpy(assoc_rqst->assoc_cmd.hostnqn, ctrl->ctrl.opts->host->nqn,
min(FCNVME_ASSOC_HOSTNQN_LEN, NVMF_NQN_SIZE));
strncpy(assoc_rqst->assoc_cmd.subnqn, ctrl->ctrl.opts->subsysnqn,
min(FCNVME_ASSOC_SUBNQN_LEN, NVMF_NQN_SIZE));
lsop->queue = queue;
lsreq->rqstaddr = assoc_rqst;
lsreq->rqstlen = sizeof(*assoc_rqst);
lsreq->rspaddr = assoc_acc;
lsreq->rsplen = sizeof(*assoc_acc);
lsreq->timeout = NVME_FC_CONNECT_TIMEOUT_SEC;
ret = nvme_fc_send_ls_req(ctrl->rport, lsop);
if (ret)
goto out_free_buffer;
if (assoc_acc->hdr.w0.ls_cmd != FCNVME_LS_ACC)
fcret = VERR_LSACC;
else if (assoc_acc->hdr.desc_list_len !=
fcnvme_lsdesc_len(
sizeof(struct fcnvme_ls_cr_assoc_acc)))
fcret = VERR_CR_ASSOC_ACC_LEN;
else if (assoc_acc->hdr.rqst.desc_tag !=
cpu_to_be32(FCNVME_LSDESC_RQST))
fcret = VERR_LSDESC_RQST;
else if (assoc_acc->hdr.rqst.desc_len !=
fcnvme_lsdesc_len(sizeof(struct fcnvme_lsdesc_rqst)))
fcret = VERR_LSDESC_RQST_LEN;
else if (assoc_acc->hdr.rqst.w0.ls_cmd != FCNVME_LS_CREATE_ASSOCIATION)
fcret = VERR_CR_ASSOC;
else if (assoc_acc->associd.desc_tag !=
cpu_to_be32(FCNVME_LSDESC_ASSOC_ID))
fcret = VERR_ASSOC_ID;
else if (assoc_acc->associd.desc_len !=
fcnvme_lsdesc_len(
sizeof(struct fcnvme_lsdesc_assoc_id)))
fcret = VERR_ASSOC_ID_LEN;
else if (assoc_acc->connectid.desc_tag !=
cpu_to_be32(FCNVME_LSDESC_CONN_ID))
fcret = VERR_CONN_ID;
else if (assoc_acc->connectid.desc_len !=
fcnvme_lsdesc_len(sizeof(struct fcnvme_lsdesc_conn_id)))
fcret = VERR_CONN_ID_LEN;
if (fcret) {
ret = -EBADF;
dev_err(ctrl->dev,
"q %d connect failed: %s\n",
queue->qnum, validation_errors[fcret]);
} else {
ctrl->association_id =
be64_to_cpu(assoc_acc->associd.association_id);
queue->connection_id =
be64_to_cpu(assoc_acc->connectid.connection_id);
set_bit(NVME_FC_Q_CONNECTED, &queue->flags);
}
out_free_buffer:
kfree(lsop);
out_no_memory:
if (ret)
dev_err(ctrl->dev,
"queue %d connect admin queue failed (%d).\n",
queue->qnum, ret);
return ret;
}
static int
nvme_fc_connect_queue(struct nvme_fc_ctrl *ctrl, struct nvme_fc_queue *queue,
u16 qsize, u16 ersp_ratio)
{
struct nvmefc_ls_req_op *lsop;
struct nvmefc_ls_req *lsreq;
struct fcnvme_ls_cr_conn_rqst *conn_rqst;
struct fcnvme_ls_cr_conn_acc *conn_acc;
int ret, fcret = 0;
lsop = kzalloc((sizeof(*lsop) +
ctrl->lport->ops->lsrqst_priv_sz +
sizeof(*conn_rqst) + sizeof(*conn_acc)), GFP_KERNEL);
if (!lsop) {
ret = -ENOMEM;
goto out_no_memory;
}
lsreq = &lsop->ls_req;
lsreq->private = (void *)&lsop[1];
conn_rqst = (struct fcnvme_ls_cr_conn_rqst *)
(lsreq->private + ctrl->lport->ops->lsrqst_priv_sz);
conn_acc = (struct fcnvme_ls_cr_conn_acc *)&conn_rqst[1];
conn_rqst->w0.ls_cmd = FCNVME_LS_CREATE_CONNECTION;
conn_rqst->desc_list_len = cpu_to_be32(
sizeof(struct fcnvme_lsdesc_assoc_id) +
sizeof(struct fcnvme_lsdesc_cr_conn_cmd));
conn_rqst->associd.desc_tag = cpu_to_be32(FCNVME_LSDESC_ASSOC_ID);
conn_rqst->associd.desc_len =
fcnvme_lsdesc_len(
sizeof(struct fcnvme_lsdesc_assoc_id));
conn_rqst->associd.association_id = cpu_to_be64(ctrl->association_id);
conn_rqst->connect_cmd.desc_tag =
cpu_to_be32(FCNVME_LSDESC_CREATE_CONN_CMD);
conn_rqst->connect_cmd.desc_len =
fcnvme_lsdesc_len(
sizeof(struct fcnvme_lsdesc_cr_conn_cmd));
conn_rqst->connect_cmd.ersp_ratio = cpu_to_be16(ersp_ratio);
conn_rqst->connect_cmd.qid = cpu_to_be16(queue->qnum);
conn_rqst->connect_cmd.sqsize = cpu_to_be16(qsize);
lsop->queue = queue;
lsreq->rqstaddr = conn_rqst;
lsreq->rqstlen = sizeof(*conn_rqst);
lsreq->rspaddr = conn_acc;
lsreq->rsplen = sizeof(*conn_acc);
lsreq->timeout = NVME_FC_CONNECT_TIMEOUT_SEC;
ret = nvme_fc_send_ls_req(ctrl->rport, lsop);
if (ret)
goto out_free_buffer;
if (conn_acc->hdr.w0.ls_cmd != FCNVME_LS_ACC)
fcret = VERR_LSACC;
else if (conn_acc->hdr.desc_list_len !=
fcnvme_lsdesc_len(sizeof(struct fcnvme_ls_cr_conn_acc)))
fcret = VERR_CR_CONN_ACC_LEN;
else if (conn_acc->hdr.rqst.desc_tag != cpu_to_be32(FCNVME_LSDESC_RQST))
fcret = VERR_LSDESC_RQST;
else if (conn_acc->hdr.rqst.desc_len !=
fcnvme_lsdesc_len(sizeof(struct fcnvme_lsdesc_rqst)))
fcret = VERR_LSDESC_RQST_LEN;
else if (conn_acc->hdr.rqst.w0.ls_cmd != FCNVME_LS_CREATE_CONNECTION)
fcret = VERR_CR_CONN;
else if (conn_acc->connectid.desc_tag !=
cpu_to_be32(FCNVME_LSDESC_CONN_ID))
fcret = VERR_CONN_ID;
else if (conn_acc->connectid.desc_len !=
fcnvme_lsdesc_len(sizeof(struct fcnvme_lsdesc_conn_id)))
fcret = VERR_CONN_ID_LEN;
if (fcret) {
ret = -EBADF;
dev_err(ctrl->dev,
"q %d connect failed: %s\n",
queue->qnum, validation_errors[fcret]);
} else {
queue->connection_id =
be64_to_cpu(conn_acc->connectid.connection_id);
set_bit(NVME_FC_Q_CONNECTED, &queue->flags);
}
out_free_buffer:
kfree(lsop);
out_no_memory:
if (ret)
dev_err(ctrl->dev,
"queue %d connect command failed (%d).\n",
queue->qnum, ret);
return ret;
}
static void
nvme_fc_disconnect_assoc_done(struct nvmefc_ls_req *lsreq, int status)
{
struct nvmefc_ls_req_op *lsop = ls_req_to_lsop(lsreq);
__nvme_fc_finish_ls_req(lsop);
kfree(lsop);
}
static void
nvme_fc_xmt_disconnect_assoc(struct nvme_fc_ctrl *ctrl)
{
struct fcnvme_ls_disconnect_rqst *discon_rqst;
struct fcnvme_ls_disconnect_acc *discon_acc;
struct nvmefc_ls_req_op *lsop;
struct nvmefc_ls_req *lsreq;
int ret;
lsop = kzalloc((sizeof(*lsop) +
ctrl->lport->ops->lsrqst_priv_sz +
sizeof(*discon_rqst) + sizeof(*discon_acc)),
GFP_KERNEL);
if (!lsop)
return;
lsreq = &lsop->ls_req;
lsreq->private = (void *)&lsop[1];
discon_rqst = (struct fcnvme_ls_disconnect_rqst *)
(lsreq->private + ctrl->lport->ops->lsrqst_priv_sz);
discon_acc = (struct fcnvme_ls_disconnect_acc *)&discon_rqst[1];
discon_rqst->w0.ls_cmd = FCNVME_LS_DISCONNECT;
discon_rqst->desc_list_len = cpu_to_be32(
sizeof(struct fcnvme_lsdesc_assoc_id) +
sizeof(struct fcnvme_lsdesc_disconn_cmd));
discon_rqst->associd.desc_tag = cpu_to_be32(FCNVME_LSDESC_ASSOC_ID);
discon_rqst->associd.desc_len =
fcnvme_lsdesc_len(
sizeof(struct fcnvme_lsdesc_assoc_id));
discon_rqst->associd.association_id = cpu_to_be64(ctrl->association_id);
discon_rqst->discon_cmd.desc_tag = cpu_to_be32(
FCNVME_LSDESC_DISCONN_CMD);
discon_rqst->discon_cmd.desc_len =
fcnvme_lsdesc_len(
sizeof(struct fcnvme_lsdesc_disconn_cmd));
discon_rqst->discon_cmd.scope = FCNVME_DISCONN_ASSOCIATION;
discon_rqst->discon_cmd.id = cpu_to_be64(ctrl->association_id);
lsreq->rqstaddr = discon_rqst;
lsreq->rqstlen = sizeof(*discon_rqst);
lsreq->rspaddr = discon_acc;
lsreq->rsplen = sizeof(*discon_acc);
lsreq->timeout = NVME_FC_CONNECT_TIMEOUT_SEC;
ret = nvme_fc_send_ls_req_async(ctrl->rport, lsop,
nvme_fc_disconnect_assoc_done);
if (ret)
kfree(lsop);
ctrl->association_id = 0;
}
static int
nvme_fc_reinit_request(void *data, struct request *rq)
{
struct nvme_fc_fcp_op *op = blk_mq_rq_to_pdu(rq);
struct nvme_fc_cmd_iu *cmdiu = &op->cmd_iu;
memset(cmdiu, 0, sizeof(*cmdiu));
cmdiu->scsi_id = NVME_CMD_SCSI_ID;
cmdiu->fc_id = NVME_CMD_FC_ID;
cmdiu->iu_len = cpu_to_be16(sizeof(*cmdiu) / sizeof(u32));
memset(&op->rsp_iu, 0, sizeof(op->rsp_iu));
return 0;
}
static void
__nvme_fc_exit_request(struct nvme_fc_ctrl *ctrl,
struct nvme_fc_fcp_op *op)
{
fc_dma_unmap_single(ctrl->lport->dev, op->fcp_req.rspdma,
sizeof(op->rsp_iu), DMA_FROM_DEVICE);
fc_dma_unmap_single(ctrl->lport->dev, op->fcp_req.cmddma,
sizeof(op->cmd_iu), DMA_TO_DEVICE);
atomic_set(&op->state, FCPOP_STATE_UNINIT);
}
static void
nvme_fc_exit_request(struct blk_mq_tag_set *set, struct request *rq,
unsigned int hctx_idx)
{
struct nvme_fc_fcp_op *op = blk_mq_rq_to_pdu(rq);
return __nvme_fc_exit_request(set->driver_data, op);
}
static int
__nvme_fc_abort_op(struct nvme_fc_ctrl *ctrl, struct nvme_fc_fcp_op *op)
{
int state;
state = atomic_xchg(&op->state, FCPOP_STATE_ABORTED);
if (state != FCPOP_STATE_ACTIVE) {
atomic_set(&op->state, state);
return -ECANCELED;
}
ctrl->lport->ops->fcp_abort(&ctrl->lport->localport,
&ctrl->rport->remoteport,
op->queue->lldd_handle,
&op->fcp_req);
return 0;
}
static void
nvme_fc_abort_aen_ops(struct nvme_fc_ctrl *ctrl)
{
struct nvme_fc_fcp_op *aen_op = ctrl->aen_ops;
unsigned long flags;
int i, ret;
for (i = 0; i < NVME_FC_NR_AEN_COMMANDS; i++, aen_op++) {
if (atomic_read(&aen_op->state) != FCPOP_STATE_ACTIVE)
continue;
spin_lock_irqsave(&ctrl->lock, flags);
if (ctrl->flags & FCCTRL_TERMIO) {
ctrl->iocnt++;
aen_op->flags |= FCOP_FLAGS_TERMIO;
}
spin_unlock_irqrestore(&ctrl->lock, flags);
ret = __nvme_fc_abort_op(ctrl, aen_op);
if (ret) {
spin_lock_irqsave(&ctrl->lock, flags);
if (ctrl->flags & FCCTRL_TERMIO)
ctrl->iocnt--;
aen_op->flags &= ~FCOP_FLAGS_TERMIO;
spin_unlock_irqrestore(&ctrl->lock, flags);
return;
}
}
}
static inline int
__nvme_fc_fcpop_chk_teardowns(struct nvme_fc_ctrl *ctrl,
struct nvme_fc_fcp_op *op)
{
unsigned long flags;
bool complete_rq = false;
spin_lock_irqsave(&ctrl->lock, flags);
if (unlikely(op->flags & FCOP_FLAGS_TERMIO)) {
if (ctrl->flags & FCCTRL_TERMIO)
ctrl->iocnt--;
}
if (op->flags & FCOP_FLAGS_RELEASED)
complete_rq = true;
else
op->flags |= FCOP_FLAGS_COMPLETE;
spin_unlock_irqrestore(&ctrl->lock, flags);
return complete_rq;
}
static void
nvme_fc_fcpio_done(struct nvmefc_fcp_req *req)
{
struct nvme_fc_fcp_op *op = fcp_req_to_fcp_op(req);
struct request *rq = op->rq;
struct nvmefc_fcp_req *freq = &op->fcp_req;
struct nvme_fc_ctrl *ctrl = op->ctrl;
struct nvme_fc_queue *queue = op->queue;
struct nvme_completion *cqe = &op->rsp_iu.cqe;
struct nvme_command *sqe = &op->cmd_iu.sqe;
__le16 status = cpu_to_le16(NVME_SC_SUCCESS << 1);
union nvme_result result;
bool complete_rq, terminate_assoc = true;
fc_dma_sync_single_for_cpu(ctrl->lport->dev, op->fcp_req.rspdma,
sizeof(op->rsp_iu), DMA_FROM_DEVICE);
if (atomic_read(&op->state) == FCPOP_STATE_ABORTED)
status = cpu_to_le16((NVME_SC_ABORT_REQ | NVME_SC_DNR) << 1);
else if (freq->status)
status = cpu_to_le16(NVME_SC_FC_TRANSPORT_ERROR << 1);
if (status)
goto done;
switch (freq->rcv_rsplen) {
case 0:
case NVME_FC_SIZEOF_ZEROS_RSP:
if (freq->transferred_length !=
be32_to_cpu(op->cmd_iu.data_len)) {
status = cpu_to_le16(NVME_SC_FC_TRANSPORT_ERROR << 1);
goto done;
}
result.u64 = 0;
break;
case sizeof(struct nvme_fc_ersp_iu):
if (unlikely(be16_to_cpu(op->rsp_iu.iu_len) !=
(freq->rcv_rsplen / 4) ||
be32_to_cpu(op->rsp_iu.xfrd_len) !=
freq->transferred_length ||
op->rsp_iu.status_code ||
sqe->common.command_id != cqe->command_id)) {
status = cpu_to_le16(NVME_SC_FC_TRANSPORT_ERROR << 1);
goto done;
}
result = cqe->result;
status = cqe->status;
break;
default:
status = cpu_to_le16(NVME_SC_FC_TRANSPORT_ERROR << 1);
goto done;
}
terminate_assoc = false;
done:
if (op->flags & FCOP_FLAGS_AEN) {
nvme_complete_async_event(&queue->ctrl->ctrl, status, &result);
complete_rq = __nvme_fc_fcpop_chk_teardowns(ctrl, op);
atomic_set(&op->state, FCPOP_STATE_IDLE);
op->flags = FCOP_FLAGS_AEN;
nvme_fc_ctrl_put(ctrl);
goto check_error;
}
complete_rq = __nvme_fc_fcpop_chk_teardowns(ctrl, op);
if (!complete_rq) {
if (unlikely(op->flags & FCOP_FLAGS_TERMIO)) {
status = cpu_to_le16(NVME_SC_ABORT_REQ << 1);
if (blk_queue_dying(rq->q))
status |= cpu_to_le16(NVME_SC_DNR << 1);
}
nvme_end_request(rq, status, result);
} else
__nvme_fc_final_op_cleanup(rq);
check_error:
if (terminate_assoc)
nvme_fc_error_recovery(ctrl, "transport detected io error");
}
static int
__nvme_fc_init_request(struct nvme_fc_ctrl *ctrl,
struct nvme_fc_queue *queue, struct nvme_fc_fcp_op *op,
struct request *rq, u32 rqno)
{
struct nvme_fc_cmd_iu *cmdiu = &op->cmd_iu;
int ret = 0;
memset(op, 0, sizeof(*op));
op->fcp_req.cmdaddr = &op->cmd_iu;
op->fcp_req.cmdlen = sizeof(op->cmd_iu);
op->fcp_req.rspaddr = &op->rsp_iu;
op->fcp_req.rsplen = sizeof(op->rsp_iu);
op->fcp_req.done = nvme_fc_fcpio_done;
op->fcp_req.first_sgl = (struct scatterlist *)&op[1];
op->fcp_req.private = &op->fcp_req.first_sgl[SG_CHUNK_SIZE];
op->ctrl = ctrl;
op->queue = queue;
op->rq = rq;
op->rqno = rqno;
cmdiu->scsi_id = NVME_CMD_SCSI_ID;
cmdiu->fc_id = NVME_CMD_FC_ID;
cmdiu->iu_len = cpu_to_be16(sizeof(*cmdiu) / sizeof(u32));
op->fcp_req.cmddma = fc_dma_map_single(ctrl->lport->dev,
&op->cmd_iu, sizeof(op->cmd_iu), DMA_TO_DEVICE);
if (fc_dma_mapping_error(ctrl->lport->dev, op->fcp_req.cmddma)) {
dev_err(ctrl->dev,
"FCP Op failed - cmdiu dma mapping failed.\n");
ret = EFAULT;
goto out_on_error;
}
op->fcp_req.rspdma = fc_dma_map_single(ctrl->lport->dev,
&op->rsp_iu, sizeof(op->rsp_iu),
DMA_FROM_DEVICE);
if (fc_dma_mapping_error(ctrl->lport->dev, op->fcp_req.rspdma)) {
dev_err(ctrl->dev,
"FCP Op failed - rspiu dma mapping failed.\n");
ret = EFAULT;
}
atomic_set(&op->state, FCPOP_STATE_IDLE);
out_on_error:
return ret;
}
static int
nvme_fc_init_request(struct blk_mq_tag_set *set, struct request *rq,
unsigned int hctx_idx, unsigned int numa_node)
{
struct nvme_fc_ctrl *ctrl = set->driver_data;
struct nvme_fc_fcp_op *op = blk_mq_rq_to_pdu(rq);
struct nvme_fc_queue *queue = &ctrl->queues[hctx_idx+1];
return __nvme_fc_init_request(ctrl, queue, op, rq, queue->rqcnt++);
}
static int
nvme_fc_init_admin_request(struct blk_mq_tag_set *set, struct request *rq,
unsigned int hctx_idx, unsigned int numa_node)
{
struct nvme_fc_ctrl *ctrl = set->driver_data;
struct nvme_fc_fcp_op *op = blk_mq_rq_to_pdu(rq);
struct nvme_fc_queue *queue = &ctrl->queues[0];
return __nvme_fc_init_request(ctrl, queue, op, rq, queue->rqcnt++);
}
static int
nvme_fc_init_aen_ops(struct nvme_fc_ctrl *ctrl)
{
struct nvme_fc_fcp_op *aen_op;
struct nvme_fc_cmd_iu *cmdiu;
struct nvme_command *sqe;
void *private;
int i, ret;
aen_op = ctrl->aen_ops;
for (i = 0; i < NVME_FC_NR_AEN_COMMANDS; i++, aen_op++) {
private = kzalloc(ctrl->lport->ops->fcprqst_priv_sz,
GFP_KERNEL);
if (!private)
return -ENOMEM;
cmdiu = &aen_op->cmd_iu;
sqe = &cmdiu->sqe;
ret = __nvme_fc_init_request(ctrl, &ctrl->queues[0],
aen_op, (struct request *)NULL,
(AEN_CMDID_BASE + i));
if (ret) {
kfree(private);
return ret;
}
aen_op->flags = FCOP_FLAGS_AEN;
aen_op->fcp_req.first_sgl = NULL;
aen_op->fcp_req.private = private;
memset(sqe, 0, sizeof(*sqe));
sqe->common.opcode = nvme_admin_async_event;
sqe->common.command_id = AEN_CMDID_BASE + i;
}
return 0;
}
static void
nvme_fc_term_aen_ops(struct nvme_fc_ctrl *ctrl)
{
struct nvme_fc_fcp_op *aen_op;
int i;
aen_op = ctrl->aen_ops;
for (i = 0; i < NVME_FC_NR_AEN_COMMANDS; i++, aen_op++) {
if (!aen_op->fcp_req.private)
continue;
__nvme_fc_exit_request(ctrl, aen_op);
kfree(aen_op->fcp_req.private);
aen_op->fcp_req.private = NULL;
}
}
static inline void
__nvme_fc_init_hctx(struct blk_mq_hw_ctx *hctx, struct nvme_fc_ctrl *ctrl,
unsigned int qidx)
{
struct nvme_fc_queue *queue = &ctrl->queues[qidx];
hctx->driver_data = queue;
queue->hctx = hctx;
}
static int
nvme_fc_init_hctx(struct blk_mq_hw_ctx *hctx, void *data,
unsigned int hctx_idx)
{
struct nvme_fc_ctrl *ctrl = data;
__nvme_fc_init_hctx(hctx, ctrl, hctx_idx + 1);
return 0;
}
static int
nvme_fc_init_admin_hctx(struct blk_mq_hw_ctx *hctx, void *data,
unsigned int hctx_idx)
{
struct nvme_fc_ctrl *ctrl = data;
__nvme_fc_init_hctx(hctx, ctrl, hctx_idx);
return 0;
}
static void
nvme_fc_init_queue(struct nvme_fc_ctrl *ctrl, int idx, size_t queue_size)
{
struct nvme_fc_queue *queue;
queue = &ctrl->queues[idx];
memset(queue, 0, sizeof(*queue));
queue->ctrl = ctrl;
queue->qnum = idx;
atomic_set(&queue->csn, 1);
queue->dev = ctrl->dev;
if (idx > 0)
queue->cmnd_capsule_len = ctrl->ctrl.ioccsz * 16;
else
queue->cmnd_capsule_len = sizeof(struct nvme_command);
queue->queue_size = queue_size;
}
static void
nvme_fc_free_queue(struct nvme_fc_queue *queue)
{
if (!test_and_clear_bit(NVME_FC_Q_CONNECTED, &queue->flags))
return;
queue->connection_id = 0;
clear_bit(NVME_FC_Q_CONNECTED, &queue->flags);
}
static void
__nvme_fc_delete_hw_queue(struct nvme_fc_ctrl *ctrl,
struct nvme_fc_queue *queue, unsigned int qidx)
{
if (ctrl->lport->ops->delete_queue)
ctrl->lport->ops->delete_queue(&ctrl->lport->localport, qidx,
queue->lldd_handle);
queue->lldd_handle = NULL;
}
static void
nvme_fc_free_io_queues(struct nvme_fc_ctrl *ctrl)
{
int i;
for (i = 1; i < ctrl->queue_count; i++)
nvme_fc_free_queue(&ctrl->queues[i]);
}
static int
__nvme_fc_create_hw_queue(struct nvme_fc_ctrl *ctrl,
struct nvme_fc_queue *queue, unsigned int qidx, u16 qsize)
{
int ret = 0;
queue->lldd_handle = NULL;
if (ctrl->lport->ops->create_queue)
ret = ctrl->lport->ops->create_queue(&ctrl->lport->localport,
qidx, qsize, &queue->lldd_handle);
return ret;
}
static void
nvme_fc_delete_hw_io_queues(struct nvme_fc_ctrl *ctrl)
{
struct nvme_fc_queue *queue = &ctrl->queues[ctrl->queue_count - 1];
int i;
for (i = ctrl->queue_count - 1; i >= 1; i--, queue--)
__nvme_fc_delete_hw_queue(ctrl, queue, i);
}
static int
nvme_fc_create_hw_io_queues(struct nvme_fc_ctrl *ctrl, u16 qsize)
{
struct nvme_fc_queue *queue = &ctrl->queues[1];
int i, ret;
for (i = 1; i < ctrl->queue_count; i++, queue++) {
ret = __nvme_fc_create_hw_queue(ctrl, queue, i, qsize);
if (ret)
goto delete_queues;
}
return 0;
delete_queues:
for (; i >= 0; i--)
__nvme_fc_delete_hw_queue(ctrl, &ctrl->queues[i], i);
return ret;
}
static int
nvme_fc_connect_io_queues(struct nvme_fc_ctrl *ctrl, u16 qsize)
{
int i, ret = 0;
for (i = 1; i < ctrl->queue_count; i++) {
ret = nvme_fc_connect_queue(ctrl, &ctrl->queues[i], qsize,
(qsize / 5));
if (ret)
break;
ret = nvmf_connect_io_queue(&ctrl->ctrl, i);
if (ret)
break;
}
return ret;
}
static void
nvme_fc_init_io_queues(struct nvme_fc_ctrl *ctrl)
{
int i;
for (i = 1; i < ctrl->queue_count; i++)
nvme_fc_init_queue(ctrl, i, ctrl->ctrl.sqsize);
}
static void
nvme_fc_ctrl_free(struct kref *ref)
{
struct nvme_fc_ctrl *ctrl =
container_of(ref, struct nvme_fc_ctrl, ref);
unsigned long flags;
if (ctrl->ctrl.tagset) {
blk_cleanup_queue(ctrl->ctrl.connect_q);
blk_mq_free_tag_set(&ctrl->tag_set);
}
spin_lock_irqsave(&ctrl->rport->lock, flags);
list_del(&ctrl->ctrl_list);
spin_unlock_irqrestore(&ctrl->rport->lock, flags);
blk_cleanup_queue(ctrl->ctrl.admin_q);
blk_mq_free_tag_set(&ctrl->admin_tag_set);
kfree(ctrl->queues);
put_device(ctrl->dev);
nvme_fc_rport_put(ctrl->rport);
ida_simple_remove(&nvme_fc_ctrl_cnt, ctrl->cnum);
if (ctrl->ctrl.opts)
nvmf_free_options(ctrl->ctrl.opts);
kfree(ctrl);
}
static void
nvme_fc_ctrl_put(struct nvme_fc_ctrl *ctrl)
{
kref_put(&ctrl->ref, nvme_fc_ctrl_free);
}
static int
nvme_fc_ctrl_get(struct nvme_fc_ctrl *ctrl)
{
return kref_get_unless_zero(&ctrl->ref);
}
static void
nvme_fc_nvme_ctrl_freed(struct nvme_ctrl *nctrl)
{
struct nvme_fc_ctrl *ctrl = to_fc_ctrl(nctrl);
WARN_ON(nctrl != &ctrl->ctrl);
nvme_fc_ctrl_put(ctrl);
}
static void
nvme_fc_error_recovery(struct nvme_fc_ctrl *ctrl, char *errmsg)
{
dev_warn(ctrl->ctrl.device,
"NVME-FC{%d}: transport association error detected: %s\n",
ctrl->cnum, errmsg);
dev_warn(ctrl->ctrl.device,
"NVME-FC{%d}: resetting controller\n", ctrl->cnum);
if (ctrl->queue_count > 1)
nvme_stop_queues(&ctrl->ctrl);
if (!nvme_change_ctrl_state(&ctrl->ctrl, NVME_CTRL_RECONNECTING)) {
dev_err(ctrl->ctrl.device,
"NVME-FC{%d}: error_recovery: Couldn't change state "
"to RECONNECTING\n", ctrl->cnum);
return;
}
if (!queue_work(nvme_fc_wq, &ctrl->reset_work))
dev_err(ctrl->ctrl.device,
"NVME-FC{%d}: error_recovery: Failed to schedule "
"reset work\n", ctrl->cnum);
}
static enum blk_eh_timer_return
nvme_fc_timeout(struct request *rq, bool reserved)
{
struct nvme_fc_fcp_op *op = blk_mq_rq_to_pdu(rq);
struct nvme_fc_ctrl *ctrl = op->ctrl;
int ret;
if (reserved)
return BLK_EH_RESET_TIMER;
ret = __nvme_fc_abort_op(ctrl, op);
if (ret)
return BLK_EH_HANDLED;
nvme_fc_error_recovery(ctrl, "io timeout error");
return BLK_EH_HANDLED;
}
static int
nvme_fc_map_data(struct nvme_fc_ctrl *ctrl, struct request *rq,
struct nvme_fc_fcp_op *op)
{
struct nvmefc_fcp_req *freq = &op->fcp_req;
enum dma_data_direction dir;
int ret;
freq->sg_cnt = 0;
if (!blk_rq_payload_bytes(rq))
return 0;
freq->sg_table.sgl = freq->first_sgl;
ret = sg_alloc_table_chained(&freq->sg_table,
blk_rq_nr_phys_segments(rq), freq->sg_table.sgl);
if (ret)
return -ENOMEM;
op->nents = blk_rq_map_sg(rq->q, rq, freq->sg_table.sgl);
WARN_ON(op->nents > blk_rq_nr_phys_segments(rq));
dir = (rq_data_dir(rq) == WRITE) ? DMA_TO_DEVICE : DMA_FROM_DEVICE;
freq->sg_cnt = fc_dma_map_sg(ctrl->lport->dev, freq->sg_table.sgl,
op->nents, dir);
if (unlikely(freq->sg_cnt <= 0)) {
sg_free_table_chained(&freq->sg_table, true);
freq->sg_cnt = 0;
return -EFAULT;
}
return 0;
}
static void
nvme_fc_unmap_data(struct nvme_fc_ctrl *ctrl, struct request *rq,
struct nvme_fc_fcp_op *op)
{
struct nvmefc_fcp_req *freq = &op->fcp_req;
if (!freq->sg_cnt)
return;
fc_dma_unmap_sg(ctrl->lport->dev, freq->sg_table.sgl, op->nents,
((rq_data_dir(rq) == WRITE) ?
DMA_TO_DEVICE : DMA_FROM_DEVICE));
nvme_cleanup_cmd(rq);
sg_free_table_chained(&freq->sg_table, true);
freq->sg_cnt = 0;
}
static int
nvme_fc_start_fcp_op(struct nvme_fc_ctrl *ctrl, struct nvme_fc_queue *queue,
struct nvme_fc_fcp_op *op, u32 data_len,
enum nvmefc_fcp_datadir io_dir)
{
struct nvme_fc_cmd_iu *cmdiu = &op->cmd_iu;
struct nvme_command *sqe = &cmdiu->sqe;
u32 csn;
int ret;
if (ctrl->rport->remoteport.port_state != FC_OBJSTATE_ONLINE)
return BLK_MQ_RQ_QUEUE_ERROR;
if (!nvme_fc_ctrl_get(ctrl))
return BLK_MQ_RQ_QUEUE_ERROR;
cmdiu->connection_id = cpu_to_be64(queue->connection_id);
csn = atomic_inc_return(&queue->csn);
cmdiu->csn = cpu_to_be32(csn);
cmdiu->data_len = cpu_to_be32(data_len);
switch (io_dir) {
case NVMEFC_FCP_WRITE:
cmdiu->flags = FCNVME_CMD_FLAGS_WRITE;
break;
case NVMEFC_FCP_READ:
cmdiu->flags = FCNVME_CMD_FLAGS_READ;
break;
case NVMEFC_FCP_NODATA:
cmdiu->flags = 0;
break;
}
op->fcp_req.payload_length = data_len;
op->fcp_req.io_dir = io_dir;
op->fcp_req.transferred_length = 0;
op->fcp_req.rcv_rsplen = 0;
op->fcp_req.status = NVME_SC_SUCCESS;
op->fcp_req.sqid = cpu_to_le16(queue->qnum);
WARN_ON_ONCE(sqe->common.metadata);
WARN_ON_ONCE(sqe->common.dptr.prp1);
WARN_ON_ONCE(sqe->common.dptr.prp2);
sqe->common.flags |= NVME_CMD_SGL_METABUF;
sqe->rw.dptr.sgl.type = NVME_SGL_FMT_OFFSET;
sqe->rw.dptr.sgl.length = cpu_to_le32(data_len);
sqe->rw.dptr.sgl.addr = 0;
if (!(op->flags & FCOP_FLAGS_AEN)) {
ret = nvme_fc_map_data(ctrl, op->rq, op);
if (ret < 0) {
nvme_cleanup_cmd(op->rq);
nvme_fc_ctrl_put(ctrl);
return (ret == -ENOMEM || ret == -EAGAIN) ?
BLK_MQ_RQ_QUEUE_BUSY : BLK_MQ_RQ_QUEUE_ERROR;
}
}
fc_dma_sync_single_for_device(ctrl->lport->dev, op->fcp_req.cmddma,
sizeof(op->cmd_iu), DMA_TO_DEVICE);
atomic_set(&op->state, FCPOP_STATE_ACTIVE);
if (!(op->flags & FCOP_FLAGS_AEN))
blk_mq_start_request(op->rq);
ret = ctrl->lport->ops->fcp_io(&ctrl->lport->localport,
&ctrl->rport->remoteport,
queue->lldd_handle, &op->fcp_req);
if (ret) {
if (op->rq) {
nvme_fc_unmap_data(ctrl, op->rq, op);
nvme_cleanup_cmd(op->rq);
}
nvme_fc_ctrl_put(ctrl);
if (ret != -EBUSY)
return BLK_MQ_RQ_QUEUE_ERROR;
if (op->rq) {
blk_mq_stop_hw_queues(op->rq->q);
blk_mq_delay_queue(queue->hctx, NVMEFC_QUEUE_DELAY);
}
return BLK_MQ_RQ_QUEUE_BUSY;
}
return BLK_MQ_RQ_QUEUE_OK;
}
static int
nvme_fc_queue_rq(struct blk_mq_hw_ctx *hctx,
const struct blk_mq_queue_data *bd)
{
struct nvme_ns *ns = hctx->queue->queuedata;
struct nvme_fc_queue *queue = hctx->driver_data;
struct nvme_fc_ctrl *ctrl = queue->ctrl;
struct request *rq = bd->rq;
struct nvme_fc_fcp_op *op = blk_mq_rq_to_pdu(rq);
struct nvme_fc_cmd_iu *cmdiu = &op->cmd_iu;
struct nvme_command *sqe = &cmdiu->sqe;
enum nvmefc_fcp_datadir io_dir;
u32 data_len;
int ret;
ret = nvme_setup_cmd(ns, rq, sqe);
if (ret)
return ret;
data_len = blk_rq_payload_bytes(rq);
if (data_len)
io_dir = ((rq_data_dir(rq) == WRITE) ?
NVMEFC_FCP_WRITE : NVMEFC_FCP_READ);
else
io_dir = NVMEFC_FCP_NODATA;
return nvme_fc_start_fcp_op(ctrl, queue, op, data_len, io_dir);
}
static struct blk_mq_tags *
nvme_fc_tagset(struct nvme_fc_queue *queue)
{
if (queue->qnum == 0)
return queue->ctrl->admin_tag_set.tags[queue->qnum];
return queue->ctrl->tag_set.tags[queue->qnum - 1];
}
static int
nvme_fc_poll(struct blk_mq_hw_ctx *hctx, unsigned int tag)
{
struct nvme_fc_queue *queue = hctx->driver_data;
struct nvme_fc_ctrl *ctrl = queue->ctrl;
struct request *req;
struct nvme_fc_fcp_op *op;
req = blk_mq_tag_to_rq(nvme_fc_tagset(queue), tag);
if (!req)
return 0;
op = blk_mq_rq_to_pdu(req);
if ((atomic_read(&op->state) == FCPOP_STATE_ACTIVE) &&
(ctrl->lport->ops->poll_queue))
ctrl->lport->ops->poll_queue(&ctrl->lport->localport,
queue->lldd_handle);
return ((atomic_read(&op->state) != FCPOP_STATE_ACTIVE));
}
static void
nvme_fc_submit_async_event(struct nvme_ctrl *arg, int aer_idx)
{
struct nvme_fc_ctrl *ctrl = to_fc_ctrl(arg);
struct nvme_fc_fcp_op *aen_op;
unsigned long flags;
bool terminating = false;
int ret;
if (aer_idx > NVME_FC_NR_AEN_COMMANDS)
return;
spin_lock_irqsave(&ctrl->lock, flags);
if (ctrl->flags & FCCTRL_TERMIO)
terminating = true;
spin_unlock_irqrestore(&ctrl->lock, flags);
if (terminating)
return;
aen_op = &ctrl->aen_ops[aer_idx];
ret = nvme_fc_start_fcp_op(ctrl, aen_op->queue, aen_op, 0,
NVMEFC_FCP_NODATA);
if (ret)
dev_err(ctrl->ctrl.device,
"failed async event work [%d]\n", aer_idx);
}
static void
__nvme_fc_final_op_cleanup(struct request *rq)
{
struct nvme_fc_fcp_op *op = blk_mq_rq_to_pdu(rq);
struct nvme_fc_ctrl *ctrl = op->ctrl;
atomic_set(&op->state, FCPOP_STATE_IDLE);
op->flags &= ~(FCOP_FLAGS_TERMIO | FCOP_FLAGS_RELEASED |
FCOP_FLAGS_COMPLETE);
nvme_cleanup_cmd(rq);
nvme_fc_unmap_data(ctrl, rq, op);
nvme_complete_rq(rq);
nvme_fc_ctrl_put(ctrl);
}
static void
nvme_fc_complete_rq(struct request *rq)
{
struct nvme_fc_fcp_op *op = blk_mq_rq_to_pdu(rq);
struct nvme_fc_ctrl *ctrl = op->ctrl;
unsigned long flags;
bool completed = false;
spin_lock_irqsave(&ctrl->lock, flags);
if (op->flags & FCOP_FLAGS_COMPLETE)
completed = true;
else
op->flags |= FCOP_FLAGS_RELEASED;
spin_unlock_irqrestore(&ctrl->lock, flags);
if (completed)
__nvme_fc_final_op_cleanup(rq);
}
static void
nvme_fc_terminate_exchange(struct request *req, void *data, bool reserved)
{
struct nvme_ctrl *nctrl = data;
struct nvme_fc_ctrl *ctrl = to_fc_ctrl(nctrl);
struct nvme_fc_fcp_op *op = blk_mq_rq_to_pdu(req);
unsigned long flags;
int status;
if (!blk_mq_request_started(req))
return;
spin_lock_irqsave(&ctrl->lock, flags);
if (ctrl->flags & FCCTRL_TERMIO) {
ctrl->iocnt++;
op->flags |= FCOP_FLAGS_TERMIO;
}
spin_unlock_irqrestore(&ctrl->lock, flags);
status = __nvme_fc_abort_op(ctrl, op);
if (status) {
spin_lock_irqsave(&ctrl->lock, flags);
if (ctrl->flags & FCCTRL_TERMIO)
ctrl->iocnt--;
op->flags &= ~FCOP_FLAGS_TERMIO;
spin_unlock_irqrestore(&ctrl->lock, flags);
return;
}
}
static int
nvme_fc_create_io_queues(struct nvme_fc_ctrl *ctrl)
{
struct nvmf_ctrl_options *opts = ctrl->ctrl.opts;
int ret;
ret = nvme_set_queue_count(&ctrl->ctrl, &opts->nr_io_queues);
if (ret) {
dev_info(ctrl->ctrl.device,
"set_queue_count failed: %d\n", ret);
return ret;
}
ctrl->queue_count = opts->nr_io_queues + 1;
if (!opts->nr_io_queues)
return 0;
nvme_fc_init_io_queues(ctrl);
memset(&ctrl->tag_set, 0, sizeof(ctrl->tag_set));
ctrl->tag_set.ops = &nvme_fc_mq_ops;
ctrl->tag_set.queue_depth = ctrl->ctrl.opts->queue_size;
ctrl->tag_set.reserved_tags = 1;
ctrl->tag_set.numa_node = NUMA_NO_NODE;
ctrl->tag_set.flags = BLK_MQ_F_SHOULD_MERGE;
ctrl->tag_set.cmd_size = sizeof(struct nvme_fc_fcp_op) +
(SG_CHUNK_SIZE *
sizeof(struct scatterlist)) +
ctrl->lport->ops->fcprqst_priv_sz;
ctrl->tag_set.driver_data = ctrl;
ctrl->tag_set.nr_hw_queues = ctrl->queue_count - 1;
ctrl->tag_set.timeout = NVME_IO_TIMEOUT;
ret = blk_mq_alloc_tag_set(&ctrl->tag_set);
if (ret)
return ret;
ctrl->ctrl.tagset = &ctrl->tag_set;
ctrl->ctrl.connect_q = blk_mq_init_queue(&ctrl->tag_set);
if (IS_ERR(ctrl->ctrl.connect_q)) {
ret = PTR_ERR(ctrl->ctrl.connect_q);
goto out_free_tag_set;
}
ret = nvme_fc_create_hw_io_queues(ctrl, ctrl->ctrl.opts->queue_size);
if (ret)
goto out_cleanup_blk_queue;
ret = nvme_fc_connect_io_queues(ctrl, ctrl->ctrl.opts->queue_size);
if (ret)
goto out_delete_hw_queues;
return 0;
out_delete_hw_queues:
nvme_fc_delete_hw_io_queues(ctrl);
out_cleanup_blk_queue:
nvme_stop_keep_alive(&ctrl->ctrl);
blk_cleanup_queue(ctrl->ctrl.connect_q);
out_free_tag_set:
blk_mq_free_tag_set(&ctrl->tag_set);
nvme_fc_free_io_queues(ctrl);
ctrl->ctrl.tagset = NULL;
return ret;
}
static int
nvme_fc_reinit_io_queues(struct nvme_fc_ctrl *ctrl)
{
struct nvmf_ctrl_options *opts = ctrl->ctrl.opts;
int ret;
ret = nvme_set_queue_count(&ctrl->ctrl, &opts->nr_io_queues);
if (ret) {
dev_info(ctrl->ctrl.device,
"set_queue_count failed: %d\n", ret);
return ret;
}
if (ctrl->queue_count == 1)
return 0;
nvme_fc_init_io_queues(ctrl);
ret = blk_mq_reinit_tagset(&ctrl->tag_set);
if (ret)
goto out_free_io_queues;
ret = nvme_fc_create_hw_io_queues(ctrl, ctrl->ctrl.opts->queue_size);
if (ret)
goto out_free_io_queues;
ret = nvme_fc_connect_io_queues(ctrl, ctrl->ctrl.opts->queue_size);
if (ret)
goto out_delete_hw_queues;
return 0;
out_delete_hw_queues:
nvme_fc_delete_hw_io_queues(ctrl);
out_free_io_queues:
nvme_fc_free_io_queues(ctrl);
return ret;
}
static int
nvme_fc_create_association(struct nvme_fc_ctrl *ctrl)
{
struct nvmf_ctrl_options *opts = ctrl->ctrl.opts;
u32 segs;
int ret;
bool changed;
++ctrl->ctrl.opts->nr_reconnects;
nvme_fc_init_queue(ctrl, 0, NVME_FC_AQ_BLKMQ_DEPTH);
ret = __nvme_fc_create_hw_queue(ctrl, &ctrl->queues[0], 0,
NVME_FC_AQ_BLKMQ_DEPTH);
if (ret)
goto out_free_queue;
ret = nvme_fc_connect_admin_queue(ctrl, &ctrl->queues[0],
NVME_FC_AQ_BLKMQ_DEPTH,
(NVME_FC_AQ_BLKMQ_DEPTH / 4));
if (ret)
goto out_delete_hw_queue;
if (ctrl->ctrl.state != NVME_CTRL_NEW)
blk_mq_start_stopped_hw_queues(ctrl->ctrl.admin_q, true);
ret = nvmf_connect_admin_queue(&ctrl->ctrl);
if (ret)
goto out_disconnect_admin_queue;
ret = nvmf_reg_read64(&ctrl->ctrl, NVME_REG_CAP, &ctrl->cap);
if (ret) {
dev_err(ctrl->ctrl.device,
"prop_get NVME_REG_CAP failed\n");
goto out_disconnect_admin_queue;
}
ctrl->ctrl.sqsize =
min_t(int, NVME_CAP_MQES(ctrl->cap) + 1, ctrl->ctrl.sqsize);
ret = nvme_enable_ctrl(&ctrl->ctrl, ctrl->cap);
if (ret)
goto out_disconnect_admin_queue;
segs = min_t(u32, NVME_FC_MAX_SEGMENTS,
ctrl->lport->ops->max_sgl_segments);
ctrl->ctrl.max_hw_sectors = (segs - 1) << (PAGE_SHIFT - 9);
ret = nvme_init_identify(&ctrl->ctrl);
if (ret)
goto out_disconnect_admin_queue;
if (ctrl->ctrl.icdoff) {
dev_err(ctrl->ctrl.device, "icdoff %d is not supported!\n",
ctrl->ctrl.icdoff);
goto out_disconnect_admin_queue;
}
nvme_start_keep_alive(&ctrl->ctrl);
if (opts->queue_size > ctrl->ctrl.maxcmd) {
dev_warn(ctrl->ctrl.device,
"queue_size %zu > ctrl maxcmd %u, reducing "
"to queue_size\n",
opts->queue_size, ctrl->ctrl.maxcmd);
opts->queue_size = ctrl->ctrl.maxcmd;
}
ret = nvme_fc_init_aen_ops(ctrl);
if (ret)
goto out_term_aen_ops;
if (ctrl->queue_count > 1) {
if (ctrl->ctrl.state == NVME_CTRL_NEW)
ret = nvme_fc_create_io_queues(ctrl);
else
ret = nvme_fc_reinit_io_queues(ctrl);
if (ret)
goto out_term_aen_ops;
}
changed = nvme_change_ctrl_state(&ctrl->ctrl, NVME_CTRL_LIVE);
WARN_ON_ONCE(!changed);
ctrl->ctrl.opts->nr_reconnects = 0;
if (ctrl->queue_count > 1) {
nvme_start_queues(&ctrl->ctrl);
nvme_queue_scan(&ctrl->ctrl);
nvme_queue_async_events(&ctrl->ctrl);
}
return 0;
out_term_aen_ops:
nvme_fc_term_aen_ops(ctrl);
nvme_stop_keep_alive(&ctrl->ctrl);
out_disconnect_admin_queue:
nvme_fc_xmt_disconnect_assoc(ctrl);
out_delete_hw_queue:
__nvme_fc_delete_hw_queue(ctrl, &ctrl->queues[0], 0);
out_free_queue:
nvme_fc_free_queue(&ctrl->queues[0]);
return ret;
}
static void
nvme_fc_delete_association(struct nvme_fc_ctrl *ctrl)
{
unsigned long flags;
nvme_stop_keep_alive(&ctrl->ctrl);
spin_lock_irqsave(&ctrl->lock, flags);
ctrl->flags |= FCCTRL_TERMIO;
ctrl->iocnt = 0;
spin_unlock_irqrestore(&ctrl->lock, flags);
if (ctrl->queue_count > 1) {
nvme_stop_queues(&ctrl->ctrl);
blk_mq_tagset_busy_iter(&ctrl->tag_set,
nvme_fc_terminate_exchange, &ctrl->ctrl);
}
blk_mq_stop_hw_queues(ctrl->ctrl.admin_q);
blk_mq_tagset_busy_iter(&ctrl->admin_tag_set,
nvme_fc_terminate_exchange, &ctrl->ctrl);
nvme_fc_abort_aen_ops(ctrl);
spin_lock_irqsave(&ctrl->lock, flags);
while (ctrl->iocnt) {
spin_unlock_irqrestore(&ctrl->lock, flags);
msleep(1000);
spin_lock_irqsave(&ctrl->lock, flags);
}
ctrl->flags &= ~FCCTRL_TERMIO;
spin_unlock_irqrestore(&ctrl->lock, flags);
nvme_fc_term_aen_ops(ctrl);
if (ctrl->association_id)
nvme_fc_xmt_disconnect_assoc(ctrl);
if (ctrl->ctrl.tagset) {
nvme_fc_delete_hw_io_queues(ctrl);
nvme_fc_free_io_queues(ctrl);
}
__nvme_fc_delete_hw_queue(ctrl, &ctrl->queues[0], 0);
nvme_fc_free_queue(&ctrl->queues[0]);
}
static void
nvme_fc_delete_ctrl_work(struct work_struct *work)
{
struct nvme_fc_ctrl *ctrl =
container_of(work, struct nvme_fc_ctrl, delete_work);
cancel_work_sync(&ctrl->reset_work);
cancel_delayed_work_sync(&ctrl->connect_work);
nvme_fc_delete_association(ctrl);
nvme_uninit_ctrl(&ctrl->ctrl);
nvme_put_ctrl(&ctrl->ctrl);
}
static bool
__nvme_fc_schedule_delete_work(struct nvme_fc_ctrl *ctrl)
{
if (!nvme_change_ctrl_state(&ctrl->ctrl, NVME_CTRL_DELETING))
return true;
if (!queue_work(nvme_fc_wq, &ctrl->delete_work))
return true;
return false;
}
static int
__nvme_fc_del_ctrl(struct nvme_fc_ctrl *ctrl)
{
return __nvme_fc_schedule_delete_work(ctrl) ? -EBUSY : 0;
}
static int
nvme_fc_del_nvme_ctrl(struct nvme_ctrl *nctrl)
{
struct nvme_fc_ctrl *ctrl = to_fc_ctrl(nctrl);
int ret;
if (!kref_get_unless_zero(&ctrl->ctrl.kref))
return -EBUSY;
ret = __nvme_fc_del_ctrl(ctrl);
if (!ret)
flush_workqueue(nvme_fc_wq);
nvme_put_ctrl(&ctrl->ctrl);
return ret;
}
static void
nvme_fc_reconnect_or_delete(struct nvme_fc_ctrl *ctrl, int status)
{
if (ctrl->ctrl.state != NVME_CTRL_RECONNECTING) {
WARN_ON_ONCE(ctrl->ctrl.state == NVME_CTRL_NEW ||
ctrl->ctrl.state == NVME_CTRL_LIVE);
return;
}
dev_info(ctrl->ctrl.device,
"NVME-FC{%d}: reset: Reconnect attempt failed (%d)\n",
ctrl->cnum, status);
if (nvmf_should_reconnect(&ctrl->ctrl)) {
dev_info(ctrl->ctrl.device,
"NVME-FC{%d}: Reconnect attempt in %d seconds.\n",
ctrl->cnum, ctrl->ctrl.opts->reconnect_delay);
queue_delayed_work(nvme_fc_wq, &ctrl->connect_work,
ctrl->ctrl.opts->reconnect_delay * HZ);
} else {
dev_warn(ctrl->ctrl.device,
"NVME-FC{%d}: Max reconnect attempts (%d) "
"reached. Removing controller\n",
ctrl->cnum, ctrl->ctrl.opts->nr_reconnects);
WARN_ON(__nvme_fc_schedule_delete_work(ctrl));
}
}
static void
nvme_fc_reset_ctrl_work(struct work_struct *work)
{
struct nvme_fc_ctrl *ctrl =
container_of(work, struct nvme_fc_ctrl, reset_work);
int ret;
nvme_fc_delete_association(ctrl);
ret = nvme_fc_create_association(ctrl);
if (ret)
nvme_fc_reconnect_or_delete(ctrl, ret);
else
dev_info(ctrl->ctrl.device,
"NVME-FC{%d}: controller reset complete\n", ctrl->cnum);
}
static int
nvme_fc_reset_nvme_ctrl(struct nvme_ctrl *nctrl)
{
struct nvme_fc_ctrl *ctrl = to_fc_ctrl(nctrl);
dev_info(ctrl->ctrl.device,
"NVME-FC{%d}: admin requested controller reset\n", ctrl->cnum);
if (!nvme_change_ctrl_state(&ctrl->ctrl, NVME_CTRL_RESETTING))
return -EBUSY;
if (!queue_work(nvme_fc_wq, &ctrl->reset_work))
return -EBUSY;
flush_work(&ctrl->reset_work);
return 0;
}
static void
nvme_fc_connect_ctrl_work(struct work_struct *work)
{
int ret;
struct nvme_fc_ctrl *ctrl =
container_of(to_delayed_work(work),
struct nvme_fc_ctrl, connect_work);
ret = nvme_fc_create_association(ctrl);
if (ret)
nvme_fc_reconnect_or_delete(ctrl, ret);
else
dev_info(ctrl->ctrl.device,
"NVME-FC{%d}: controller reconnect complete\n",
ctrl->cnum);
}
static struct nvme_ctrl *
nvme_fc_init_ctrl(struct device *dev, struct nvmf_ctrl_options *opts,
struct nvme_fc_lport *lport, struct nvme_fc_rport *rport)
{
struct nvme_fc_ctrl *ctrl;
unsigned long flags;
int ret, idx;
if (!(rport->remoteport.port_role &
(FC_PORT_ROLE_NVME_DISCOVERY | FC_PORT_ROLE_NVME_TARGET))) {
ret = -EBADR;
goto out_fail;
}
ctrl = kzalloc(sizeof(*ctrl), GFP_KERNEL);
if (!ctrl) {
ret = -ENOMEM;
goto out_fail;
}
idx = ida_simple_get(&nvme_fc_ctrl_cnt, 0, 0, GFP_KERNEL);
if (idx < 0) {
ret = -ENOSPC;
goto out_free_ctrl;
}
ctrl->ctrl.opts = opts;
INIT_LIST_HEAD(&ctrl->ctrl_list);
ctrl->lport = lport;
ctrl->rport = rport;
ctrl->dev = lport->dev;
ctrl->cnum = idx;
get_device(ctrl->dev);
kref_init(&ctrl->ref);
INIT_WORK(&ctrl->delete_work, nvme_fc_delete_ctrl_work);
INIT_WORK(&ctrl->reset_work, nvme_fc_reset_ctrl_work);
INIT_DELAYED_WORK(&ctrl->connect_work, nvme_fc_connect_ctrl_work);
spin_lock_init(&ctrl->lock);
ctrl->queue_count = min_t(unsigned int,
opts->nr_io_queues,
lport->ops->max_hw_queues);
opts->nr_io_queues = ctrl->queue_count;
ctrl->queue_count++;
ctrl->ctrl.sqsize = opts->queue_size - 1;
ctrl->ctrl.kato = opts->kato;
ret = -ENOMEM;
ctrl->queues = kcalloc(ctrl->queue_count, sizeof(struct nvme_fc_queue),
GFP_KERNEL);
if (!ctrl->queues)
goto out_free_ida;
memset(&ctrl->admin_tag_set, 0, sizeof(ctrl->admin_tag_set));
ctrl->admin_tag_set.ops = &nvme_fc_admin_mq_ops;
ctrl->admin_tag_set.queue_depth = NVME_FC_AQ_BLKMQ_DEPTH;
ctrl->admin_tag_set.reserved_tags = 2;
ctrl->admin_tag_set.numa_node = NUMA_NO_NODE;
ctrl->admin_tag_set.cmd_size = sizeof(struct nvme_fc_fcp_op) +
(SG_CHUNK_SIZE *
sizeof(struct scatterlist)) +
ctrl->lport->ops->fcprqst_priv_sz;
ctrl->admin_tag_set.driver_data = ctrl;
ctrl->admin_tag_set.nr_hw_queues = 1;
ctrl->admin_tag_set.timeout = ADMIN_TIMEOUT;
ret = blk_mq_alloc_tag_set(&ctrl->admin_tag_set);
if (ret)
goto out_free_queues;
ctrl->ctrl.admin_q = blk_mq_init_queue(&ctrl->admin_tag_set);
if (IS_ERR(ctrl->ctrl.admin_q)) {
ret = PTR_ERR(ctrl->ctrl.admin_q);
goto out_free_admin_tag_set;
}
ret = nvme_init_ctrl(&ctrl->ctrl, dev, &nvme_fc_ctrl_ops, 0);
if (ret)
goto out_cleanup_admin_q;
spin_lock_irqsave(&rport->lock, flags);
list_add_tail(&ctrl->ctrl_list, &rport->ctrl_list);
spin_unlock_irqrestore(&rport->lock, flags);
ret = nvme_fc_create_association(ctrl);
if (ret) {
ctrl->ctrl.opts = NULL;
nvme_uninit_ctrl(&ctrl->ctrl);
nvme_put_ctrl(&ctrl->ctrl);
nvme_fc_rport_get(rport);
if (ret > 0)
ret = -EIO;
return ERR_PTR(ret);
}
kref_get(&ctrl->ctrl.kref);
dev_info(ctrl->ctrl.device,
"NVME-FC{%d}: new ctrl: NQN \"%s\"\n",
ctrl->cnum, ctrl->ctrl.opts->subsysnqn);
return &ctrl->ctrl;
out_cleanup_admin_q:
blk_cleanup_queue(ctrl->ctrl.admin_q);
out_free_admin_tag_set:
blk_mq_free_tag_set(&ctrl->admin_tag_set);
out_free_queues:
kfree(ctrl->queues);
out_free_ida:
put_device(ctrl->dev);
ida_simple_remove(&nvme_fc_ctrl_cnt, ctrl->cnum);
out_free_ctrl:
kfree(ctrl);
out_fail:
return ERR_PTR(ret);
}
static int
nvme_fc_parse_address(struct nvmet_fc_traddr *traddr, char *buf)
{
substring_t args[MAX_OPT_ARGS];
char *options, *o, *p;
int token, ret = 0;
u64 token64;
options = o = kstrdup(buf, GFP_KERNEL);
if (!options)
return -ENOMEM;
while ((p = strsep(&o, ":\n")) != NULL) {
if (!*p)
continue;
token = match_token(p, traddr_opt_tokens, args);
switch (token) {
case FCT_TRADDR_WWNN:
if (match_u64(args, &token64)) {
ret = -EINVAL;
goto out;
}
traddr->nn = token64;
break;
case FCT_TRADDR_WWPN:
if (match_u64(args, &token64)) {
ret = -EINVAL;
goto out;
}
traddr->pn = token64;
break;
default:
pr_warn("unknown traddr token or missing value '%s'\n",
p);
ret = -EINVAL;
goto out;
}
}
out:
kfree(options);
return ret;
}
static struct nvme_ctrl *
nvme_fc_create_ctrl(struct device *dev, struct nvmf_ctrl_options *opts)
{
struct nvme_fc_lport *lport;
struct nvme_fc_rport *rport;
struct nvme_ctrl *ctrl;
struct nvmet_fc_traddr laddr = { 0L, 0L };
struct nvmet_fc_traddr raddr = { 0L, 0L };
unsigned long flags;
int ret;
ret = nvme_fc_parse_address(&raddr, opts->traddr);
if (ret || !raddr.nn || !raddr.pn)
return ERR_PTR(-EINVAL);
ret = nvme_fc_parse_address(&laddr, opts->host_traddr);
if (ret || !laddr.nn || !laddr.pn)
return ERR_PTR(-EINVAL);
spin_lock_irqsave(&nvme_fc_lock, flags);
list_for_each_entry(lport, &nvme_fc_lport_list, port_list) {
if (lport->localport.node_name != laddr.nn ||
lport->localport.port_name != laddr.pn)
continue;
list_for_each_entry(rport, &lport->endp_list, endp_list) {
if (rport->remoteport.node_name != raddr.nn ||
rport->remoteport.port_name != raddr.pn)
continue;
if (!nvme_fc_rport_get(rport))
break;
spin_unlock_irqrestore(&nvme_fc_lock, flags);
ctrl = nvme_fc_init_ctrl(dev, opts, lport, rport);
if (IS_ERR(ctrl))
nvme_fc_rport_put(rport);
return ctrl;
}
}
spin_unlock_irqrestore(&nvme_fc_lock, flags);
return ERR_PTR(-ENOENT);
}
static int __init nvme_fc_init_module(void)
{
int ret;
nvme_fc_wq = create_workqueue("nvme_fc_wq");
if (!nvme_fc_wq)
return -ENOMEM;
ret = nvmf_register_transport(&nvme_fc_transport);
if (ret)
goto err;
return 0;
err:
destroy_workqueue(nvme_fc_wq);
return ret;
}
static void __exit nvme_fc_exit_module(void)
{
if (!list_empty(&nvme_fc_lport_list))
pr_warn("%s: localport list not empty\n", __func__);
nvmf_unregister_transport(&nvme_fc_transport);
destroy_workqueue(nvme_fc_wq);
ida_destroy(&nvme_fc_local_port_cnt);
ida_destroy(&nvme_fc_ctrl_cnt);
}
