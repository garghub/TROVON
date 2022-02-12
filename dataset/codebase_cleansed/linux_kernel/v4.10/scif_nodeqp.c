int scif_setup_qp_connect(struct scif_qp *qp, dma_addr_t *qp_offset,
int local_size, struct scif_dev *scifdev)
{
void *local_q = qp->inbound_q.rb_base;
int err = 0;
u32 tmp_rd = 0;
spin_lock_init(&qp->send_lock);
spin_lock_init(&qp->recv_lock);
if (!local_q) {
local_q = kzalloc(local_size, GFP_KERNEL);
if (!local_q) {
err = -ENOMEM;
return err;
}
}
err = scif_map_single(&qp->local_buf, local_q, scifdev, local_size);
if (err)
goto kfree;
scif_rb_init(&qp->inbound_q,
&tmp_rd,
&qp->local_write,
local_q, get_count_order(local_size));
qp->inbound_q.read_ptr = NULL;
err = scif_map_single(qp_offset, qp,
scifdev, sizeof(struct scif_qp));
if (err)
goto unmap;
qp->local_qp = *qp_offset;
return err;
unmap:
scif_unmap_single(qp->local_buf, scifdev, local_size);
qp->local_buf = 0;
kfree:
kfree(local_q);
return err;
}
int scif_setup_qp_accept(struct scif_qp *qp, dma_addr_t *qp_offset,
dma_addr_t phys, int local_size,
struct scif_dev *scifdev)
{
void *local_q;
void *remote_q;
struct scif_qp *remote_qp;
int remote_size;
int err = 0;
spin_lock_init(&qp->send_lock);
spin_lock_init(&qp->recv_lock);
remote_qp = scif_ioremap(phys, sizeof(struct scif_qp), scifdev);
if (!remote_qp)
return -EIO;
qp->remote_qp = remote_qp;
if (qp->remote_qp->magic != SCIFEP_MAGIC) {
err = -EIO;
goto iounmap;
}
qp->remote_buf = remote_qp->local_buf;
remote_size = qp->remote_qp->inbound_q.size;
remote_q = scif_ioremap(qp->remote_buf, remote_size, scifdev);
if (!remote_q) {
err = -EIO;
goto iounmap;
}
qp->remote_qp->local_write = 0;
scif_rb_init(&qp->outbound_q,
&qp->local_read,
&qp->remote_qp->local_write,
remote_q,
get_count_order(remote_size));
local_q = kzalloc(local_size, GFP_KERNEL);
if (!local_q) {
err = -ENOMEM;
goto iounmap_1;
}
err = scif_map_single(&qp->local_buf, local_q, scifdev, local_size);
if (err)
goto kfree;
qp->remote_qp->local_read = 0;
scif_rb_init(&qp->inbound_q,
&qp->remote_qp->local_read,
&qp->local_write,
local_q, get_count_order(local_size));
err = scif_map_single(qp_offset, qp, scifdev,
sizeof(struct scif_qp));
if (err)
goto unmap;
qp->local_qp = *qp_offset;
return err;
unmap:
scif_unmap_single(qp->local_buf, scifdev, local_size);
qp->local_buf = 0;
kfree:
kfree(local_q);
iounmap_1:
scif_iounmap(remote_q, remote_size, scifdev);
qp->outbound_q.rb_base = NULL;
iounmap:
scif_iounmap(qp->remote_qp, sizeof(struct scif_qp), scifdev);
qp->remote_qp = NULL;
return err;
}
int scif_setup_qp_connect_response(struct scif_dev *scifdev,
struct scif_qp *qp, u64 payload)
{
int err = 0;
void *r_buf;
int remote_size;
phys_addr_t tmp_phys;
qp->remote_qp = scif_ioremap(payload, sizeof(struct scif_qp), scifdev);
if (!qp->remote_qp) {
err = -ENOMEM;
goto error;
}
if (qp->remote_qp->magic != SCIFEP_MAGIC) {
dev_err(&scifdev->sdev->dev,
"SCIFEP_MAGIC mismatch between self %d remote %d\n",
scif_dev[scif_info.nodeid].node, scifdev->node);
err = -ENODEV;
goto error;
}
tmp_phys = qp->remote_qp->local_buf;
remote_size = qp->remote_qp->inbound_q.size;
r_buf = scif_ioremap(tmp_phys, remote_size, scifdev);
if (!r_buf)
return -EIO;
qp->local_read = 0;
scif_rb_init(&qp->outbound_q,
&qp->local_read,
&qp->remote_qp->local_write,
r_buf,
get_count_order(remote_size));
qp->remote_qp->local_read = qp->inbound_q.current_read_offset;
scif_rb_init(&qp->inbound_q,
&qp->remote_qp->local_read,
&qp->local_write,
qp->inbound_q.rb_base,
get_count_order(qp->inbound_q.size));
error:
return err;
}
static __always_inline void
scif_send_msg_intr(struct scif_dev *scifdev)
{
struct scif_hw_dev *sdev = scifdev->sdev;
if (scifdev_is_p2p(scifdev))
sdev->hw_ops->send_p2p_intr(sdev, scifdev->rdb, &scifdev->mmio);
else
sdev->hw_ops->send_intr(sdev, scifdev->rdb);
}
int scif_qp_response(phys_addr_t phys, struct scif_dev *scifdev)
{
int err = 0;
struct scifmsg msg;
err = scif_setup_qp_connect_response(scifdev, scifdev->qpairs, phys);
if (!err) {
msg.uop = SCIF_INIT;
msg.dst.node = scifdev->node;
err = scif_nodeqp_send(scifdev, &msg);
}
return err;
}
void scif_send_exit(struct scif_dev *scifdev)
{
struct scifmsg msg;
int ret;
scifdev->exit = OP_IN_PROGRESS;
msg.uop = SCIF_EXIT;
msg.src.node = scif_info.nodeid;
msg.dst.node = scifdev->node;
ret = scif_nodeqp_send(scifdev, &msg);
if (ret)
goto done;
wait_event_timeout(scif_info.exitwq, scifdev->exit == OP_COMPLETED,
SCIF_NODE_ALIVE_TIMEOUT);
done:
scifdev->exit = OP_IDLE;
}
int scif_setup_qp(struct scif_dev *scifdev)
{
int err = 0;
int local_size;
struct scif_qp *qp;
local_size = SCIF_NODE_QP_SIZE;
qp = kzalloc(sizeof(*qp), GFP_KERNEL);
if (!qp) {
err = -ENOMEM;
return err;
}
qp->magic = SCIFEP_MAGIC;
scifdev->qpairs = qp;
err = scif_setup_qp_connect(qp, &scifdev->qp_dma_addr,
local_size, scifdev);
if (err)
goto free_qp;
return err;
free_qp:
kfree(scifdev->qpairs);
scifdev->qpairs = NULL;
return err;
}
static void scif_p2p_freesg(struct scatterlist *sg)
{
kfree(sg);
}
static struct scatterlist *
scif_p2p_setsg(phys_addr_t pa, int page_size, int page_cnt)
{
struct scatterlist *sg;
struct page *page;
int i;
sg = kcalloc(page_cnt, sizeof(struct scatterlist), GFP_KERNEL);
if (!sg)
return NULL;
sg_init_table(sg, page_cnt);
for (i = 0; i < page_cnt; i++) {
page = pfn_to_page(pa >> PAGE_SHIFT);
sg_set_page(&sg[i], page, page_size, 0);
pa += page_size;
}
return sg;
}
static struct scif_p2p_info *
scif_init_p2p_info(struct scif_dev *scifdev, struct scif_dev *peerdev)
{
struct scif_p2p_info *p2p;
int num_mmio_pages, num_aper_pages, sg_page_shift, err, num_aper_chunks;
struct scif_hw_dev *psdev = peerdev->sdev;
struct scif_hw_dev *sdev = scifdev->sdev;
num_mmio_pages = psdev->mmio->len >> PAGE_SHIFT;
num_aper_pages = psdev->aper->len >> PAGE_SHIFT;
p2p = kzalloc(sizeof(*p2p), GFP_KERNEL);
if (!p2p)
return NULL;
p2p->ppi_sg[SCIF_PPI_MMIO] = scif_p2p_setsg(psdev->mmio->pa,
PAGE_SIZE, num_mmio_pages);
if (!p2p->ppi_sg[SCIF_PPI_MMIO])
goto free_p2p;
p2p->sg_nentries[SCIF_PPI_MMIO] = num_mmio_pages;
sg_page_shift = get_order(min(psdev->aper->len, (u64)(1 << 30)));
num_aper_chunks = num_aper_pages >> (sg_page_shift - PAGE_SHIFT);
p2p->ppi_sg[SCIF_PPI_APER] = scif_p2p_setsg(psdev->aper->pa,
1 << sg_page_shift,
num_aper_chunks);
p2p->sg_nentries[SCIF_PPI_APER] = num_aper_chunks;
err = dma_map_sg(&sdev->dev, p2p->ppi_sg[SCIF_PPI_MMIO],
num_mmio_pages, PCI_DMA_BIDIRECTIONAL);
if (err != num_mmio_pages)
goto scif_p2p_free;
err = dma_map_sg(&sdev->dev, p2p->ppi_sg[SCIF_PPI_APER],
num_aper_chunks, PCI_DMA_BIDIRECTIONAL);
if (err != num_aper_chunks)
goto dma_unmap;
p2p->ppi_da[SCIF_PPI_MMIO] = sg_dma_address(p2p->ppi_sg[SCIF_PPI_MMIO]);
p2p->ppi_da[SCIF_PPI_APER] = sg_dma_address(p2p->ppi_sg[SCIF_PPI_APER]);
p2p->ppi_len[SCIF_PPI_MMIO] = num_mmio_pages;
p2p->ppi_len[SCIF_PPI_APER] = num_aper_pages;
p2p->ppi_peer_id = peerdev->node;
return p2p;
dma_unmap:
dma_unmap_sg(&sdev->dev, p2p->ppi_sg[SCIF_PPI_MMIO],
p2p->sg_nentries[SCIF_PPI_MMIO], DMA_BIDIRECTIONAL);
scif_p2p_free:
scif_p2p_freesg(p2p->ppi_sg[SCIF_PPI_MMIO]);
scif_p2p_freesg(p2p->ppi_sg[SCIF_PPI_APER]);
free_p2p:
kfree(p2p);
return NULL;
}
static void scif_deinit_p2p_info(struct scif_dev *scifdev,
struct scif_p2p_info *p2p)
{
struct scif_hw_dev *sdev = scifdev->sdev;
dma_unmap_sg(&sdev->dev, p2p->ppi_sg[SCIF_PPI_MMIO],
p2p->sg_nentries[SCIF_PPI_MMIO], DMA_BIDIRECTIONAL);
dma_unmap_sg(&sdev->dev, p2p->ppi_sg[SCIF_PPI_APER],
p2p->sg_nentries[SCIF_PPI_APER], DMA_BIDIRECTIONAL);
scif_p2p_freesg(p2p->ppi_sg[SCIF_PPI_MMIO]);
scif_p2p_freesg(p2p->ppi_sg[SCIF_PPI_APER]);
kfree(p2p);
}
static void scif_node_connect(struct scif_dev *scifdev, int dst)
{
struct scif_dev *dev_j = scifdev;
struct scif_dev *dev_i = NULL;
struct scif_p2p_info *p2p_ij = NULL;
struct scif_p2p_info *p2p_ji = NULL;
struct scif_p2p_info *p2p;
struct list_head *pos, *tmp;
struct scifmsg msg;
int err;
u64 tmppayload;
if (dst < 1 || dst > scif_info.maxid)
return;
dev_i = &scif_dev[dst];
if (!_scifdev_alive(dev_i))
return;
if (!list_empty(&dev_i->p2p)) {
list_for_each_safe(pos, tmp, &dev_i->p2p) {
p2p = list_entry(pos, struct scif_p2p_info, ppi_list);
if (p2p->ppi_peer_id == dev_j->node)
return;
}
}
p2p_ij = scif_init_p2p_info(dev_i, dev_j);
if (!p2p_ij)
return;
p2p_ji = scif_init_p2p_info(dev_j, dev_i);
if (!p2p_ji) {
scif_deinit_p2p_info(dev_i, p2p_ij);
return;
}
list_add_tail(&p2p_ij->ppi_list, &dev_i->p2p);
list_add_tail(&p2p_ji->ppi_list, &dev_j->p2p);
msg.uop = SCIF_NODE_ADD;
msg.src.node = dev_j->node;
msg.dst.node = dev_i->node;
msg.payload[0] = p2p_ji->ppi_da[SCIF_PPI_APER];
msg.payload[1] = p2p_ij->ppi_da[SCIF_PPI_MMIO];
msg.payload[2] = p2p_ij->ppi_da[SCIF_PPI_APER];
msg.payload[3] = p2p_ij->ppi_len[SCIF_PPI_APER] << PAGE_SHIFT;
err = scif_nodeqp_send(dev_i, &msg);
if (err) {
dev_err(&scifdev->sdev->dev,
"%s %d error %d\n", __func__, __LINE__, err);
return;
}
msg.uop = SCIF_NODE_ADD;
msg.src.node = dev_i->node;
msg.dst.node = dev_j->node;
tmppayload = msg.payload[0];
msg.payload[0] = msg.payload[2];
msg.payload[2] = tmppayload;
msg.payload[1] = p2p_ji->ppi_da[SCIF_PPI_MMIO];
msg.payload[3] = p2p_ji->ppi_len[SCIF_PPI_APER] << PAGE_SHIFT;
scif_nodeqp_send(dev_j, &msg);
}
static void scif_p2p_setup(void)
{
int i, j;
if (!scif_info.p2p_enable)
return;
for (i = 1; i <= scif_info.maxid; i++)
if (!_scifdev_alive(&scif_dev[i]))
return;
for (i = 1; i <= scif_info.maxid; i++) {
for (j = 1; j <= scif_info.maxid; j++) {
struct scif_dev *scifdev = &scif_dev[i];
if (i == j)
continue;
scif_node_connect(scifdev, j);
}
}
}
static void
scif_display_message(struct scif_dev *scifdev, struct scifmsg *msg,
const char *label)
{
if (!scif_info.en_msg_log)
return;
if (msg->uop > SCIF_MAX_MSG) {
dev_err(&scifdev->sdev->dev,
"%s: unknown msg type %d\n", label, msg->uop);
return;
}
dev_info(&scifdev->sdev->dev,
"%s: msg type %s, src %d:%d, dest %d:%d payload 0x%llx:0x%llx:0x%llx:0x%llx\n",
label, message_types[msg->uop], msg->src.node, msg->src.port,
msg->dst.node, msg->dst.port, msg->payload[0], msg->payload[1],
msg->payload[2], msg->payload[3]);
}
int _scif_nodeqp_send(struct scif_dev *scifdev, struct scifmsg *msg)
{
struct scif_qp *qp = scifdev->qpairs;
int err = -ENOMEM, loop_cnt = 0;
scif_display_message(scifdev, msg, "Sent");
if (!qp) {
err = -EINVAL;
goto error;
}
spin_lock(&qp->send_lock);
while ((err = scif_rb_write(&qp->outbound_q,
msg, sizeof(struct scifmsg)))) {
mdelay(1);
#define SCIF_NODEQP_SEND_TO_MSEC (3 * 1000)
if (loop_cnt++ > (SCIF_NODEQP_SEND_TO_MSEC)) {
err = -ENODEV;
break;
}
}
if (!err)
scif_rb_commit(&qp->outbound_q);
spin_unlock(&qp->send_lock);
if (!err) {
if (scifdev_self(scifdev))
queue_work(scifdev->intr_wq, &scifdev->intr_bh);
else
scif_send_msg_intr(scifdev);
}
error:
if (err)
dev_dbg(&scifdev->sdev->dev,
"%s %d error %d uop %d\n",
__func__, __LINE__, err, msg->uop);
return err;
}
int scif_nodeqp_send(struct scif_dev *scifdev, struct scifmsg *msg)
{
int err;
struct device *spdev = NULL;
if (msg->uop > SCIF_EXIT_ACK) {
if (OP_IDLE != scifdev->exit)
return -ENODEV;
spdev = scif_get_peer_dev(scifdev);
if (IS_ERR(spdev)) {
err = PTR_ERR(spdev);
return err;
}
}
err = _scif_nodeqp_send(scifdev, msg);
if (msg->uop > SCIF_EXIT_ACK)
scif_put_peer_dev(spdev);
return err;
}
void scif_misc_handler(struct work_struct *work)
{
scif_rma_handle_remote_fences();
scif_rma_destroy_windows();
scif_rma_destroy_tcw_invalid();
scif_cleanup_zombie_epd();
}
static __always_inline void
scif_init(struct scif_dev *scifdev, struct scifmsg *msg)
{
flush_delayed_work(&scifdev->qp_dwork);
scif_peer_register_device(scifdev);
if (scif_is_mgmt_node()) {
mutex_lock(&scif_info.conflock);
scif_p2p_setup();
mutex_unlock(&scif_info.conflock);
}
}
static __always_inline void
scif_exit(struct scif_dev *scifdev, struct scifmsg *unused)
{
scifdev->exit_ack_pending = true;
if (scif_is_mgmt_node())
scif_disconnect_node(scifdev->node, false);
else
scif_stop(scifdev);
schedule_delayed_work(&scifdev->qp_dwork,
msecs_to_jiffies(1000));
}
static __always_inline void
scif_exit_ack(struct scif_dev *scifdev, struct scifmsg *unused)
{
scifdev->exit = OP_COMPLETED;
wake_up(&scif_info.exitwq);
}
static __always_inline void
scif_node_add(struct scif_dev *scifdev, struct scifmsg *msg)
{
struct scif_dev *newdev;
dma_addr_t qp_offset;
int qp_connect;
struct scif_hw_dev *sdev;
dev_dbg(&scifdev->sdev->dev,
"Scifdev %d:%d received NODE_ADD msg for node %d\n",
scifdev->node, msg->dst.node, msg->src.node);
dev_dbg(&scifdev->sdev->dev,
"Remote address for this node's aperture %llx\n",
msg->payload[0]);
newdev = &scif_dev[msg->src.node];
newdev->node = msg->src.node;
newdev->sdev = scif_dev[SCIF_MGMT_NODE].sdev;
sdev = newdev->sdev;
if (scif_setup_intr_wq(newdev)) {
dev_err(&scifdev->sdev->dev,
"failed to setup interrupts for %d\n", msg->src.node);
goto interrupt_setup_error;
}
newdev->mmio.va = ioremap_nocache(msg->payload[1], sdev->mmio->len);
if (!newdev->mmio.va) {
dev_err(&scifdev->sdev->dev,
"failed to map mmio for %d\n", msg->src.node);
goto mmio_map_error;
}
newdev->qpairs = kzalloc(sizeof(*newdev->qpairs), GFP_KERNEL);
if (!newdev->qpairs)
goto qp_alloc_error;
newdev->base_addr = msg->payload[0];
qp_connect = scif_setup_qp_connect(newdev->qpairs, &qp_offset,
SCIF_NODE_QP_SIZE, newdev);
if (qp_connect) {
dev_err(&scifdev->sdev->dev,
"failed to setup qp_connect %d\n", qp_connect);
goto qp_connect_error;
}
newdev->db = sdev->hw_ops->next_db(sdev);
newdev->cookie = sdev->hw_ops->request_irq(sdev, scif_intr_handler,
"SCIF_INTR", newdev,
newdev->db);
if (IS_ERR(newdev->cookie))
goto qp_connect_error;
newdev->qpairs->magic = SCIFEP_MAGIC;
newdev->qpairs->qp_state = SCIF_QP_OFFLINE;
msg->uop = SCIF_NODE_ADD_ACK;
msg->dst.node = msg->src.node;
msg->src.node = scif_info.nodeid;
msg->payload[0] = qp_offset;
msg->payload[2] = newdev->db;
scif_nodeqp_send(&scif_dev[SCIF_MGMT_NODE], msg);
return;
qp_connect_error:
kfree(newdev->qpairs);
newdev->qpairs = NULL;
qp_alloc_error:
iounmap(newdev->mmio.va);
newdev->mmio.va = NULL;
mmio_map_error:
interrupt_setup_error:
dev_err(&scifdev->sdev->dev,
"node add failed for node %d\n", msg->src.node);
msg->uop = SCIF_NODE_ADD_NACK;
msg->dst.node = msg->src.node;
msg->src.node = scif_info.nodeid;
scif_nodeqp_send(&scif_dev[SCIF_MGMT_NODE], msg);
}
void scif_poll_qp_state(struct work_struct *work)
{
#define SCIF_NODE_QP_RETRY 100
#define SCIF_NODE_QP_TIMEOUT 100
struct scif_dev *peerdev = container_of(work, struct scif_dev,
p2p_dwork.work);
struct scif_qp *qp = &peerdev->qpairs[0];
if (qp->qp_state != SCIF_QP_ONLINE ||
qp->remote_qp->qp_state != SCIF_QP_ONLINE) {
if (peerdev->p2p_retry++ == SCIF_NODE_QP_RETRY) {
dev_err(&peerdev->sdev->dev,
"Warning: QP check timeout with state %d\n",
qp->qp_state);
goto timeout;
}
schedule_delayed_work(&peerdev->p2p_dwork,
msecs_to_jiffies(SCIF_NODE_QP_TIMEOUT));
return;
}
return;
timeout:
dev_err(&peerdev->sdev->dev,
"%s %d remote node %d offline, state = 0x%x\n",
__func__, __LINE__, peerdev->node, qp->qp_state);
qp->remote_qp->qp_state = SCIF_QP_OFFLINE;
scif_peer_unregister_device(peerdev);
scif_cleanup_scifdev(peerdev);
}
static __always_inline void
scif_node_add_ack(struct scif_dev *scifdev, struct scifmsg *msg)
{
struct scif_dev *peerdev;
struct scif_qp *qp;
struct scif_dev *dst_dev = &scif_dev[msg->dst.node];
dev_dbg(&scifdev->sdev->dev,
"Scifdev %d received SCIF_NODE_ADD_ACK msg src %d dst %d\n",
scifdev->node, msg->src.node, msg->dst.node);
dev_dbg(&scifdev->sdev->dev,
"payload %llx %llx %llx %llx\n", msg->payload[0],
msg->payload[1], msg->payload[2], msg->payload[3]);
if (scif_is_mgmt_node()) {
mutex_lock(&scif_info.conflock);
msg->payload[1] = scif_info.maxid;
scif_nodeqp_send(dst_dev, msg);
mutex_unlock(&scif_info.conflock);
return;
}
peerdev = &scif_dev[msg->src.node];
peerdev->sdev = scif_dev[SCIF_MGMT_NODE].sdev;
peerdev->node = msg->src.node;
qp = &peerdev->qpairs[0];
if ((scif_setup_qp_connect_response(peerdev, &peerdev->qpairs[0],
msg->payload[0])))
goto local_error;
peerdev->rdb = msg->payload[2];
qp->remote_qp->qp_state = SCIF_QP_ONLINE;
scif_peer_register_device(peerdev);
schedule_delayed_work(&peerdev->p2p_dwork, 0);
return;
local_error:
scif_cleanup_scifdev(peerdev);
}
static __always_inline void
scif_node_add_nack(struct scif_dev *scifdev, struct scifmsg *msg)
{
if (scif_is_mgmt_node()) {
struct scif_dev *dst_dev = &scif_dev[msg->dst.node];
dev_dbg(&scifdev->sdev->dev,
"SCIF_NODE_ADD_NACK received from %d\n", scifdev->node);
scif_nodeqp_send(dst_dev, msg);
}
}
static __always_inline void
scif_node_remove(struct scif_dev *scifdev, struct scifmsg *msg)
{
int node = msg->payload[0];
struct scif_dev *scdev = &scif_dev[node];
scdev->node_remove_ack_pending = true;
scif_handle_remove_node(node);
}
static __always_inline void
scif_node_remove_ack(struct scif_dev *scifdev, struct scifmsg *msg)
{
struct scif_dev *sdev = &scif_dev[msg->payload[0]];
atomic_inc(&sdev->disconn_rescnt);
wake_up(&sdev->disconn_wq);
}
static __always_inline void
scif_get_node_info_resp(struct scif_dev *scifdev, struct scifmsg *msg)
{
if (scif_is_mgmt_node()) {
swap(msg->dst.node, msg->src.node);
mutex_lock(&scif_info.conflock);
msg->payload[1] = scif_info.maxid;
msg->payload[2] = scif_info.total;
mutex_unlock(&scif_info.conflock);
scif_nodeqp_send(scifdev, msg);
} else {
struct completion *node_info =
(struct completion *)msg->payload[3];
mutex_lock(&scif_info.conflock);
scif_info.maxid = msg->payload[1];
scif_info.total = msg->payload[2];
complete_all(node_info);
mutex_unlock(&scif_info.conflock);
}
}
static void
scif_msg_unknown(struct scif_dev *scifdev, struct scifmsg *msg)
{
dev_err(&scifdev->sdev->dev,
"Unknown message 0x%xn scifdev->node 0x%x\n",
msg->uop, scifdev->node);
}
static void
scif_nodeqp_msg_handler(struct scif_dev *scifdev,
struct scif_qp *qp, struct scifmsg *msg)
{
scif_display_message(scifdev, msg, "Rcvd");
if (msg->uop > (u32)scif_max_msg_id) {
dev_err(&scifdev->sdev->dev,
"Unknown message 0x%xn scifdev->node 0x%x\n",
msg->uop, scifdev->node);
return;
}
scif_intr_func[msg->uop](scifdev, msg);
}
void scif_nodeqp_intrhandler(struct scif_dev *scifdev, struct scif_qp *qp)
{
struct scifmsg msg;
int read_size;
do {
read_size = scif_rb_get_next(&qp->inbound_q, &msg, sizeof(msg));
if (!read_size)
break;
scif_nodeqp_msg_handler(scifdev, qp, &msg);
if (SCIF_EXIT_ACK == msg.uop)
break;
scif_rb_update_read_ptr(&qp->inbound_q);
} while (1);
}
static void scif_loopb_wq_handler(struct work_struct *unused)
{
struct scif_dev *scifdev = scif_info.loopb_dev;
struct scif_qp *qp = scifdev->qpairs;
struct scif_loopb_msg *msg;
do {
msg = NULL;
spin_lock(&qp->recv_lock);
if (!list_empty(&scif_info.loopb_recv_q)) {
msg = list_first_entry(&scif_info.loopb_recv_q,
struct scif_loopb_msg,
list);
list_del(&msg->list);
}
spin_unlock(&qp->recv_lock);
if (msg) {
scif_nodeqp_msg_handler(scifdev, qp, &msg->msg);
kfree(msg);
}
} while (msg);
}
int
scif_loopb_msg_handler(struct scif_dev *scifdev, struct scif_qp *qp)
{
int read_size;
struct scif_loopb_msg *msg;
do {
msg = kmalloc(sizeof(*msg), GFP_KERNEL);
if (!msg)
return -ENOMEM;
read_size = scif_rb_get_next(&qp->inbound_q, &msg->msg,
sizeof(struct scifmsg));
if (read_size != sizeof(struct scifmsg)) {
kfree(msg);
scif_rb_update_read_ptr(&qp->inbound_q);
break;
}
spin_lock(&qp->recv_lock);
list_add_tail(&msg->list, &scif_info.loopb_recv_q);
spin_unlock(&qp->recv_lock);
queue_work(scif_info.loopb_wq, &scif_info.loopb_work);
scif_rb_update_read_ptr(&qp->inbound_q);
} while (read_size == sizeof(struct scifmsg));
return read_size;
}
int scif_setup_loopback_qp(struct scif_dev *scifdev)
{
int err = 0;
void *local_q;
struct scif_qp *qp;
err = scif_setup_intr_wq(scifdev);
if (err)
goto exit;
INIT_LIST_HEAD(&scif_info.loopb_recv_q);
snprintf(scif_info.loopb_wqname, sizeof(scif_info.loopb_wqname),
"SCIF LOOPB %d", scifdev->node);
scif_info.loopb_wq =
alloc_ordered_workqueue(scif_info.loopb_wqname, 0);
if (!scif_info.loopb_wq) {
err = -ENOMEM;
goto destroy_intr;
}
INIT_WORK(&scif_info.loopb_work, scif_loopb_wq_handler);
scifdev->qpairs = kzalloc(sizeof(*scifdev->qpairs), GFP_KERNEL);
if (!scifdev->qpairs) {
err = -ENOMEM;
goto destroy_loopb_wq;
}
qp = scifdev->qpairs;
qp->magic = SCIFEP_MAGIC;
spin_lock_init(&qp->send_lock);
spin_lock_init(&qp->recv_lock);
local_q = kzalloc(SCIF_NODE_QP_SIZE, GFP_KERNEL);
if (!local_q) {
err = -ENOMEM;
goto free_qpairs;
}
scif_rb_init(&qp->outbound_q,
&qp->local_read,
&qp->local_write,
local_q, get_count_order(SCIF_NODE_QP_SIZE));
scif_rb_init(&qp->inbound_q,
&qp->local_read,
&qp->local_write,
local_q, get_count_order(SCIF_NODE_QP_SIZE));
scif_info.nodeid = scifdev->node;
scif_peer_register_device(scifdev);
scif_info.loopb_dev = scifdev;
return err;
free_qpairs:
kfree(scifdev->qpairs);
destroy_loopb_wq:
destroy_workqueue(scif_info.loopb_wq);
destroy_intr:
scif_destroy_intr_wq(scifdev);
exit:
return err;
}
int scif_destroy_loopback_qp(struct scif_dev *scifdev)
{
scif_peer_unregister_device(scifdev);
destroy_workqueue(scif_info.loopb_wq);
scif_destroy_intr_wq(scifdev);
kfree(scifdev->qpairs->outbound_q.rb_base);
kfree(scifdev->qpairs);
scifdev->sdev = NULL;
scif_info.loopb_dev = NULL;
return 0;
}
void scif_destroy_p2p(struct scif_dev *scifdev)
{
struct scif_dev *peer_dev;
struct scif_p2p_info *p2p;
struct list_head *pos, *tmp;
int bd;
mutex_lock(&scif_info.conflock);
list_for_each_safe(pos, tmp, &scifdev->p2p) {
p2p = list_entry(pos, struct scif_p2p_info, ppi_list);
dma_unmap_sg(&scifdev->sdev->dev, p2p->ppi_sg[SCIF_PPI_MMIO],
p2p->sg_nentries[SCIF_PPI_MMIO],
DMA_BIDIRECTIONAL);
dma_unmap_sg(&scifdev->sdev->dev, p2p->ppi_sg[SCIF_PPI_APER],
p2p->sg_nentries[SCIF_PPI_APER],
DMA_BIDIRECTIONAL);
scif_p2p_freesg(p2p->ppi_sg[SCIF_PPI_MMIO]);
scif_p2p_freesg(p2p->ppi_sg[SCIF_PPI_APER]);
list_del(pos);
kfree(p2p);
}
for (bd = SCIF_MGMT_NODE + 1; bd <= scif_info.maxid; bd++) {
peer_dev = &scif_dev[bd];
list_for_each_safe(pos, tmp, &peer_dev->p2p) {
p2p = list_entry(pos, struct scif_p2p_info, ppi_list);
if (p2p->ppi_peer_id == scifdev->node) {
dma_unmap_sg(&peer_dev->sdev->dev,
p2p->ppi_sg[SCIF_PPI_MMIO],
p2p->sg_nentries[SCIF_PPI_MMIO],
DMA_BIDIRECTIONAL);
dma_unmap_sg(&peer_dev->sdev->dev,
p2p->ppi_sg[SCIF_PPI_APER],
p2p->sg_nentries[SCIF_PPI_APER],
DMA_BIDIRECTIONAL);
scif_p2p_freesg(p2p->ppi_sg[SCIF_PPI_MMIO]);
scif_p2p_freesg(p2p->ppi_sg[SCIF_PPI_APER]);
list_del(pos);
kfree(p2p);
}
}
}
mutex_unlock(&scif_info.conflock);
}
