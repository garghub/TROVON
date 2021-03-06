static void scif_intr_bh_handler(struct work_struct *work)
{
struct scif_dev *scifdev =
container_of(work, struct scif_dev, intr_bh);
if (scifdev_self(scifdev))
scif_loopb_msg_handler(scifdev, scifdev->qpairs);
else
scif_nodeqp_intrhandler(scifdev, scifdev->qpairs);
}
int scif_setup_intr_wq(struct scif_dev *scifdev)
{
if (!scifdev->intr_wq) {
snprintf(scifdev->intr_wqname, sizeof(scifdev->intr_wqname),
"SCIF INTR %d", scifdev->node);
scifdev->intr_wq =
alloc_ordered_workqueue(scifdev->intr_wqname, 0);
if (!scifdev->intr_wq)
return -ENOMEM;
INIT_WORK(&scifdev->intr_bh, scif_intr_bh_handler);
}
return 0;
}
void scif_destroy_intr_wq(struct scif_dev *scifdev)
{
if (scifdev->intr_wq) {
destroy_workqueue(scifdev->intr_wq);
scifdev->intr_wq = NULL;
}
}
irqreturn_t scif_intr_handler(int irq, void *data)
{
struct scif_dev *scifdev = data;
struct scif_hw_dev *sdev = scifdev->sdev;
sdev->hw_ops->ack_interrupt(sdev, scifdev->db);
queue_work(scifdev->intr_wq, &scifdev->intr_bh);
return IRQ_HANDLED;
}
static int scif_peer_probe(struct scif_peer_dev *spdev)
{
struct scif_dev *scifdev = &scif_dev[spdev->dnode];
mutex_lock(&scif_info.conflock);
scif_info.total++;
scif_info.maxid = max_t(u32, spdev->dnode, scif_info.maxid);
mutex_unlock(&scif_info.conflock);
rcu_assign_pointer(scifdev->spdev, spdev);
return 0;
}
static void scif_peer_remove(struct scif_peer_dev *spdev)
{
struct scif_dev *scifdev = &scif_dev[spdev->dnode];
spdev = rcu_dereference(scifdev->spdev);
if (spdev)
RCU_INIT_POINTER(scifdev->spdev, NULL);
synchronize_rcu();
mutex_lock(&scif_info.conflock);
scif_info.total--;
mutex_unlock(&scif_info.conflock);
}
static void scif_qp_setup_handler(struct work_struct *work)
{
struct scif_dev *scifdev = container_of(work, struct scif_dev,
qp_dwork.work);
struct scif_hw_dev *sdev = scifdev->sdev;
dma_addr_t da = 0;
int err;
if (scif_is_mgmt_node()) {
struct mic_bootparam *bp = sdev->dp;
da = bp->scif_card_dma_addr;
scifdev->rdb = bp->h2c_scif_db;
} else {
struct mic_bootparam __iomem *bp = sdev->rdp;
da = readq(&bp->scif_host_dma_addr);
scifdev->rdb = ioread8(&bp->c2h_scif_db);
}
if (da) {
err = scif_qp_response(da, scifdev);
if (err)
dev_err(&scifdev->sdev->dev,
"scif_qp_response err %d\n", err);
} else {
schedule_delayed_work(&scifdev->qp_dwork,
msecs_to_jiffies(1000));
}
}
static int scif_setup_scifdev(struct scif_hw_dev *sdev)
{
int i;
u8 num_nodes;
if (sdev->snode) {
struct mic_bootparam __iomem *bp = sdev->rdp;
num_nodes = ioread8(&bp->tot_nodes);
} else {
struct mic_bootparam *bp = sdev->dp;
num_nodes = bp->tot_nodes;
}
scif_dev = kcalloc(num_nodes, sizeof(*scif_dev), GFP_KERNEL);
if (!scif_dev)
return -ENOMEM;
for (i = 0; i < num_nodes; i++) {
struct scif_dev *scifdev = &scif_dev[i];
scifdev->node = i;
scifdev->exit = OP_IDLE;
init_waitqueue_head(&scifdev->disconn_wq);
mutex_init(&scifdev->lock);
INIT_WORK(&scifdev->init_msg_work, scif_qp_response_ack);
INIT_DELAYED_WORK(&scifdev->p2p_dwork,
scif_poll_qp_state);
INIT_DELAYED_WORK(&scifdev->qp_dwork,
scif_qp_setup_handler);
INIT_LIST_HEAD(&scifdev->p2p);
RCU_INIT_POINTER(scifdev->spdev, NULL);
}
return 0;
}
static void scif_destroy_scifdev(void)
{
kfree(scif_dev);
}
static int scif_probe(struct scif_hw_dev *sdev)
{
struct scif_dev *scifdev;
int rc;
dev_set_drvdata(&sdev->dev, sdev);
if (1 == atomic_add_return(1, &g_loopb_cnt)) {
struct scif_dev *loopb_dev;
rc = scif_setup_scifdev(sdev);
if (rc)
goto exit;
scifdev = &scif_dev[sdev->dnode];
scifdev->sdev = sdev;
loopb_dev = &scif_dev[sdev->snode];
loopb_dev->sdev = sdev;
rc = scif_setup_loopback_qp(loopb_dev);
if (rc)
goto free_sdev;
} else {
scifdev = &scif_dev[sdev->dnode];
scifdev->sdev = sdev;
}
rc = scif_setup_intr_wq(scifdev);
if (rc)
goto destroy_loopb;
rc = scif_setup_qp(scifdev);
if (rc)
goto destroy_intr;
scifdev->db = sdev->hw_ops->next_db(sdev);
scifdev->cookie = sdev->hw_ops->request_irq(sdev, scif_intr_handler,
"SCIF_INTR", scifdev,
scifdev->db);
if (IS_ERR(scifdev->cookie)) {
rc = PTR_ERR(scifdev->cookie);
goto free_qp;
}
if (scif_is_mgmt_node()) {
struct mic_bootparam *bp = sdev->dp;
bp->c2h_scif_db = scifdev->db;
bp->scif_host_dma_addr = scifdev->qp_dma_addr;
} else {
struct mic_bootparam __iomem *bp = sdev->rdp;
iowrite8(scifdev->db, &bp->h2c_scif_db);
writeq(scifdev->qp_dma_addr, &bp->scif_card_dma_addr);
}
schedule_delayed_work(&scifdev->qp_dwork,
msecs_to_jiffies(1000));
return rc;
free_qp:
scif_free_qp(scifdev);
destroy_intr:
scif_destroy_intr_wq(scifdev);
destroy_loopb:
if (atomic_dec_and_test(&g_loopb_cnt))
scif_destroy_loopback_qp(&scif_dev[sdev->snode]);
free_sdev:
scif_destroy_scifdev();
exit:
return rc;
}
void scif_stop(struct scif_dev *scifdev)
{
struct scif_dev *dev;
int i;
for (i = scif_info.maxid; i >= 0; i--) {
dev = &scif_dev[i];
if (scifdev_self(dev))
continue;
scif_handle_remove_node(i);
}
}
static void scif_remove(struct scif_hw_dev *sdev)
{
struct scif_dev *scifdev = &scif_dev[sdev->dnode];
if (scif_is_mgmt_node()) {
struct mic_bootparam *bp = sdev->dp;
bp->c2h_scif_db = -1;
bp->scif_host_dma_addr = 0x0;
} else {
struct mic_bootparam __iomem *bp = sdev->rdp;
iowrite8(-1, &bp->h2c_scif_db);
writeq(0x0, &bp->scif_card_dma_addr);
}
if (scif_is_mgmt_node()) {
scif_disconnect_node(scifdev->node, true);
} else {
scif_info.card_initiated_exit = true;
scif_stop(scifdev);
}
if (atomic_dec_and_test(&g_loopb_cnt))
scif_destroy_loopback_qp(&scif_dev[sdev->snode]);
if (scifdev->cookie) {
sdev->hw_ops->free_irq(sdev, scifdev->cookie, scifdev);
scifdev->cookie = NULL;
}
scif_destroy_intr_wq(scifdev);
cancel_delayed_work(&scifdev->qp_dwork);
scif_free_qp(scifdev);
scifdev->rdb = -1;
scifdev->sdev = NULL;
}
static int _scif_init(void)
{
spin_lock_init(&scif_info.eplock);
spin_lock_init(&scif_info.nb_connect_lock);
spin_lock_init(&scif_info.port_lock);
mutex_init(&scif_info.conflock);
mutex_init(&scif_info.connlock);
INIT_LIST_HEAD(&scif_info.uaccept);
INIT_LIST_HEAD(&scif_info.listen);
INIT_LIST_HEAD(&scif_info.zombie);
INIT_LIST_HEAD(&scif_info.connected);
INIT_LIST_HEAD(&scif_info.disconnected);
INIT_LIST_HEAD(&scif_info.nb_connect_list);
init_waitqueue_head(&scif_info.exitwq);
scif_info.en_msg_log = 0;
scif_info.p2p_enable = 1;
INIT_WORK(&scif_info.misc_work, scif_misc_handler);
INIT_WORK(&scif_info.conn_work, scif_conn_handler);
idr_init(&scif_ports);
return 0;
}
static void _scif_exit(void)
{
idr_destroy(&scif_ports);
scif_destroy_scifdev();
}
static int __init scif_init(void)
{
struct miscdevice *mdev = &scif_info.mdev;
int rc;
_scif_init();
rc = scif_peer_bus_init();
if (rc)
goto exit;
rc = scif_peer_register_driver(&scif_peer_driver);
if (rc)
goto peer_bus_exit;
rc = scif_register_driver(&scif_driver);
if (rc)
goto unreg_scif_peer;
rc = misc_register(mdev);
if (rc)
goto unreg_scif;
scif_init_debugfs();
return 0;
unreg_scif:
scif_unregister_driver(&scif_driver);
unreg_scif_peer:
scif_peer_unregister_driver(&scif_peer_driver);
peer_bus_exit:
scif_peer_bus_exit();
exit:
_scif_exit();
return rc;
}
static void __exit scif_exit(void)
{
scif_exit_debugfs();
misc_deregister(&scif_info.mdev);
scif_unregister_driver(&scif_driver);
scif_peer_unregister_driver(&scif_peer_driver);
scif_peer_bus_exit();
_scif_exit();
}
