static void octeon_droq_bh(unsigned long pdev)
{
int q_no;
int reschedule = 0;
struct octeon_device *oct = (struct octeon_device *)pdev;
struct octeon_device_priv *oct_priv =
(struct octeon_device_priv *)oct->priv;
for (q_no = 0; q_no < MAX_OCTEON_OUTPUT_QUEUES(oct); q_no++) {
if (!(oct->io_qmask.oq & BIT_ULL(q_no)))
continue;
reschedule |= octeon_droq_process_packets(oct, oct->droq[q_no],
MAX_PACKET_BUDGET);
lio_enable_irq(oct->droq[q_no], NULL);
if (OCTEON_CN23XX_PF(oct) && oct->msix_on) {
int adjusted_q_no = q_no + oct->sriov_info.pf_srn;
octeon_write_csr64(
oct, CN23XX_SLI_OQ_PKT_INT_LEVELS(adjusted_q_no),
0x5700000040ULL);
octeon_write_csr64(
oct, CN23XX_SLI_OQ_PKTS_SENT(adjusted_q_no), 0);
}
}
if (reschedule)
tasklet_schedule(&oct_priv->droq_tasklet);
}
static int lio_wait_for_oq_pkts(struct octeon_device *oct)
{
struct octeon_device_priv *oct_priv =
(struct octeon_device_priv *)oct->priv;
int retry = 100, pkt_cnt = 0, pending_pkts = 0;
int i;
do {
pending_pkts = 0;
for (i = 0; i < MAX_OCTEON_OUTPUT_QUEUES(oct); i++) {
if (!(oct->io_qmask.oq & BIT_ULL(i)))
continue;
pkt_cnt += octeon_droq_check_hw_for_pkts(oct->droq[i]);
}
if (pkt_cnt > 0) {
pending_pkts += pkt_cnt;
tasklet_schedule(&oct_priv->droq_tasklet);
}
pkt_cnt = 0;
schedule_timeout_uninterruptible(1);
} while (retry-- && pending_pkts);
return pkt_cnt;
}
static void force_io_queues_off(struct octeon_device *oct)
{
if ((oct->chip_id == OCTEON_CN66XX) ||
(oct->chip_id == OCTEON_CN68XX)) {
octeon_write_csr(oct, CN6XXX_SLI_PKT_INSTR_ENB, 0);
octeon_write_csr(oct, CN6XXX_SLI_PKT_OUT_ENB, 0);
}
}
static int wait_for_pending_requests(struct octeon_device *oct)
{
int i, pcount = 0;
for (i = 0; i < 100; i++) {
pcount =
atomic_read(&oct->response_list
[OCTEON_ORDERED_SC_LIST].pending_req_count);
if (pcount)
schedule_timeout_uninterruptible(HZ / 10);
else
break;
}
if (pcount)
return 1;
return 0;
}
static inline void pcierror_quiesce_device(struct octeon_device *oct)
{
int i;
force_io_queues_off(oct);
schedule_timeout_uninterruptible(100);
if (wait_for_pending_requests(oct))
dev_err(&oct->pci_dev->dev, "There were pending requests\n");
for (i = 0; i < MAX_OCTEON_INSTR_QUEUES(oct); i++) {
struct octeon_instr_queue *iq;
if (!(oct->io_qmask.iq & BIT_ULL(i)))
continue;
iq = oct->instr_queue[i];
if (atomic_read(&iq->instr_pending)) {
spin_lock_bh(&iq->lock);
iq->fill_cnt = 0;
iq->octeon_read_index = iq->host_write_index;
iq->stats.instr_processed +=
atomic_read(&iq->instr_pending);
lio_process_iq_request_list(oct, iq, 0);
spin_unlock_bh(&iq->lock);
}
}
lio_process_ordered_list(oct, 1);
}
static void cleanup_aer_uncorrect_error_status(struct pci_dev *dev)
{
int pos = 0x100;
u32 status, mask;
pr_info("%s :\n", __func__);
pci_read_config_dword(dev, pos + PCI_ERR_UNCOR_STATUS, &status);
pci_read_config_dword(dev, pos + PCI_ERR_UNCOR_SEVER, &mask);
if (dev->error_state == pci_channel_io_normal)
status &= ~mask;
else
status &= mask;
pci_write_config_dword(dev, pos + PCI_ERR_UNCOR_STATUS, status);
}
static void stop_pci_io(struct octeon_device *oct)
{
atomic_set(&oct->status, OCT_DEV_IN_RESET);
pci_disable_device(oct->pci_dev);
oct->fn_list.disable_interrupt(oct, OCTEON_ALL_INTR);
pcierror_quiesce_device(oct);
free_irq(oct->pci_dev->irq, oct);
if (oct->flags & LIO_FLAG_MSI_ENABLED)
pci_disable_msi(oct->pci_dev);
dev_dbg(&oct->pci_dev->dev, "Device state is now %s\n",
lio_get_state_string(&oct->status));
cleanup_aer_uncorrect_error_status(oct->pci_dev);
}
static pci_ers_result_t liquidio_pcie_error_detected(struct pci_dev *pdev,
pci_channel_state_t state)
{
struct octeon_device *oct = pci_get_drvdata(pdev);
if (state == pci_channel_io_normal) {
dev_err(&oct->pci_dev->dev, "Non-correctable non-fatal error reported:\n");
cleanup_aer_uncorrect_error_status(oct->pci_dev);
return PCI_ERS_RESULT_CAN_RECOVER;
}
dev_err(&oct->pci_dev->dev, "Non-correctable FATAL reported by PCI AER driver\n");
stop_pci_io(oct);
return PCI_ERS_RESULT_DISCONNECT;
}
static int liquidio_init_pci(void)
{
return pci_register_driver(&liquidio_pci_driver);
}
static void liquidio_deinit_pci(void)
{
pci_unregister_driver(&liquidio_pci_driver);
}
static inline int ifstate_check(struct lio *lio, int state_flag)
{
return atomic_read(&lio->ifstate) & state_flag;
}
static inline void ifstate_set(struct lio *lio, int state_flag)
{
atomic_set(&lio->ifstate, (atomic_read(&lio->ifstate) | state_flag));
}
static inline void ifstate_reset(struct lio *lio, int state_flag)
{
atomic_set(&lio->ifstate, (atomic_read(&lio->ifstate) & ~(state_flag)));
}
static inline void txqs_stop(struct net_device *netdev)
{
if (netif_is_multiqueue(netdev)) {
int i;
for (i = 0; i < netdev->num_tx_queues; i++)
netif_stop_subqueue(netdev, i);
} else {
netif_stop_queue(netdev);
}
}
static inline void txqs_start(struct net_device *netdev)
{
if (netif_is_multiqueue(netdev)) {
int i;
for (i = 0; i < netdev->num_tx_queues; i++)
netif_start_subqueue(netdev, i);
} else {
netif_start_queue(netdev);
}
}
static inline void txqs_wake(struct net_device *netdev)
{
struct lio *lio = GET_LIO(netdev);
if (netif_is_multiqueue(netdev)) {
int i;
for (i = 0; i < netdev->num_tx_queues; i++) {
int qno = lio->linfo.txpciq[i %
(lio->linfo.num_txpciq)].s.q_no;
if (__netif_subqueue_stopped(netdev, i)) {
INCR_INSTRQUEUE_PKT_COUNT(lio->oct_dev, qno,
tx_restart, 1);
netif_wake_subqueue(netdev, i);
}
}
} else {
INCR_INSTRQUEUE_PKT_COUNT(lio->oct_dev, lio->txq,
tx_restart, 1);
netif_wake_queue(netdev);
}
}
static void stop_txq(struct net_device *netdev)
{
txqs_stop(netdev);
}
static void start_txq(struct net_device *netdev)
{
struct lio *lio = GET_LIO(netdev);
if (lio->linfo.link.s.link_up) {
txqs_start(netdev);
return;
}
}
static inline void wake_q(struct net_device *netdev, int q)
{
if (netif_is_multiqueue(netdev))
netif_wake_subqueue(netdev, q);
else
netif_wake_queue(netdev);
}
static inline void stop_q(struct net_device *netdev, int q)
{
if (netif_is_multiqueue(netdev))
netif_stop_subqueue(netdev, q);
else
netif_stop_queue(netdev);
}
static inline int check_txq_status(struct lio *lio)
{
int ret_val = 0;
if (netif_is_multiqueue(lio->netdev)) {
int numqs = lio->netdev->num_tx_queues;
int q, iq = 0;
for (q = 0; q < numqs; q++) {
iq = lio->linfo.txpciq[q %
(lio->linfo.num_txpciq)].s.q_no;
if (octnet_iq_is_full(lio->oct_dev, iq))
continue;
if (__netif_subqueue_stopped(lio->netdev, q)) {
wake_q(lio->netdev, q);
INCR_INSTRQUEUE_PKT_COUNT(lio->oct_dev, iq,
tx_restart, 1);
ret_val++;
}
}
} else {
if (octnet_iq_is_full(lio->oct_dev, lio->txq))
return 0;
wake_q(lio->netdev, lio->txq);
INCR_INSTRQUEUE_PKT_COUNT(lio->oct_dev, lio->txq,
tx_restart, 1);
ret_val = 1;
}
return ret_val;
}
static inline struct list_head *list_delete_head(struct list_head *root)
{
struct list_head *node;
if ((root->prev == root) && (root->next == root))
node = NULL;
else
node = root->next;
if (node)
list_del(node);
return node;
}
static void delete_glists(struct lio *lio)
{
struct octnic_gather *g;
int i;
if (!lio->glist)
return;
for (i = 0; i < lio->linfo.num_txpciq; i++) {
do {
g = (struct octnic_gather *)
list_delete_head(&lio->glist[i]);
if (g) {
if (g->sg) {
dma_unmap_single(&lio->oct_dev->
pci_dev->dev,
g->sg_dma_ptr,
g->sg_size,
DMA_TO_DEVICE);
kfree((void *)((unsigned long)g->sg -
g->adjust));
}
kfree(g);
}
} while (g);
}
kfree((void *)lio->glist);
kfree((void *)lio->glist_lock);
}
static int setup_glists(struct octeon_device *oct, struct lio *lio, int num_iqs)
{
int i, j;
struct octnic_gather *g;
lio->glist_lock = kcalloc(num_iqs, sizeof(*lio->glist_lock),
GFP_KERNEL);
if (!lio->glist_lock)
return 1;
lio->glist = kcalloc(num_iqs, sizeof(*lio->glist),
GFP_KERNEL);
if (!lio->glist) {
kfree((void *)lio->glist_lock);
return 1;
}
for (i = 0; i < num_iqs; i++) {
int numa_node = cpu_to_node(i % num_online_cpus());
spin_lock_init(&lio->glist_lock[i]);
INIT_LIST_HEAD(&lio->glist[i]);
for (j = 0; j < lio->tx_qsize; j++) {
g = kzalloc_node(sizeof(*g), GFP_KERNEL,
numa_node);
if (!g)
g = kzalloc(sizeof(*g), GFP_KERNEL);
if (!g)
break;
g->sg_size = ((ROUNDUP4(OCTNIC_MAX_SG) >> 2) *
OCT_SG_ENTRY_SIZE);
g->sg = kmalloc_node(g->sg_size + 8,
GFP_KERNEL, numa_node);
if (!g->sg)
g->sg = kmalloc(g->sg_size + 8, GFP_KERNEL);
if (!g->sg) {
kfree(g);
break;
}
if (((unsigned long)g->sg) & 7) {
g->adjust = 8 - (((unsigned long)g->sg) & 7);
g->sg = (struct octeon_sg_entry *)
((unsigned long)g->sg + g->adjust);
}
g->sg_dma_ptr = dma_map_single(&oct->pci_dev->dev,
g->sg, g->sg_size,
DMA_TO_DEVICE);
if (dma_mapping_error(&oct->pci_dev->dev,
g->sg_dma_ptr)) {
kfree((void *)((unsigned long)g->sg -
g->adjust));
kfree(g);
break;
}
list_add_tail(&g->list, &lio->glist[i]);
}
if (j != lio->tx_qsize) {
delete_glists(lio);
return 1;
}
}
return 0;
}
static void print_link_info(struct net_device *netdev)
{
struct lio *lio = GET_LIO(netdev);
if (atomic_read(&lio->ifstate) & LIO_IFSTATE_REGISTERED) {
struct oct_link_info *linfo = &lio->linfo;
if (linfo->link.s.link_up) {
netif_info(lio, link, lio->netdev, "%d Mbps %s Duplex UP\n",
linfo->link.s.speed,
(linfo->link.s.duplex) ? "Full" : "Half");
} else {
netif_info(lio, link, lio->netdev, "Link Down\n");
}
}
}
static void octnet_link_status_change(struct work_struct *work)
{
struct cavium_wk *wk = (struct cavium_wk *)work;
struct lio *lio = (struct lio *)wk->ctxptr;
rtnl_lock();
call_netdevice_notifiers(NETDEV_CHANGEMTU, lio->netdev);
rtnl_unlock();
}
static inline int setup_link_status_change_wq(struct net_device *netdev)
{
struct lio *lio = GET_LIO(netdev);
struct octeon_device *oct = lio->oct_dev;
lio->link_status_wq.wq = alloc_workqueue("link-status",
WQ_MEM_RECLAIM, 0);
if (!lio->link_status_wq.wq) {
dev_err(&oct->pci_dev->dev, "unable to create cavium link status wq\n");
return -1;
}
INIT_DELAYED_WORK(&lio->link_status_wq.wk.work,
octnet_link_status_change);
lio->link_status_wq.wk.ctxptr = lio;
return 0;
}
static inline void cleanup_link_status_change_wq(struct net_device *netdev)
{
struct lio *lio = GET_LIO(netdev);
if (lio->link_status_wq.wq) {
cancel_delayed_work_sync(&lio->link_status_wq.wk.work);
destroy_workqueue(lio->link_status_wq.wq);
}
}
static inline void update_link_status(struct net_device *netdev,
union oct_link_status *ls)
{
struct lio *lio = GET_LIO(netdev);
int changed = (lio->linfo.link.u64 != ls->u64);
lio->linfo.link.u64 = ls->u64;
if ((lio->intf_open) && (changed)) {
print_link_info(netdev);
lio->link_changes++;
if (lio->linfo.link.s.link_up) {
netif_carrier_on(netdev);
txqs_wake(netdev);
} else {
netif_carrier_off(netdev);
stop_txq(netdev);
}
}
}
static void update_txq_status(struct octeon_device *oct, int iq_num)
{
struct net_device *netdev;
struct lio *lio;
struct octeon_instr_queue *iq = oct->instr_queue[iq_num];
netdev = oct->props[iq->ifidx].netdev;
if (!netdev)
return;
lio = GET_LIO(netdev);
if (netif_is_multiqueue(netdev)) {
if (__netif_subqueue_stopped(netdev, iq->q_index) &&
lio->linfo.link.s.link_up &&
(!octnet_iq_is_full(oct, iq_num))) {
INCR_INSTRQUEUE_PKT_COUNT(lio->oct_dev, iq_num,
tx_restart, 1);
netif_wake_subqueue(netdev, iq->q_index);
} else {
if (!octnet_iq_is_full(oct, lio->txq)) {
INCR_INSTRQUEUE_PKT_COUNT(lio->oct_dev,
lio->txq,
tx_restart, 1);
wake_q(netdev, lio->txq);
}
}
}
}
static
int liquidio_schedule_msix_droq_pkt_handler(struct octeon_droq *droq, u64 ret)
{
struct octeon_device *oct = droq->oct_dev;
struct octeon_device_priv *oct_priv =
(struct octeon_device_priv *)oct->priv;
if (droq->ops.poll_mode) {
droq->ops.napi_fn(droq);
} else {
if (ret & MSIX_PO_INT) {
tasklet_schedule(&oct_priv->droq_tasklet);
return 1;
}
if (ret & MSIX_PI_INT)
return 0;
}
return 0;
}
static void liquidio_schedule_droq_pkt_handlers(struct octeon_device *oct)
{
struct octeon_device_priv *oct_priv =
(struct octeon_device_priv *)oct->priv;
u64 oq_no;
struct octeon_droq *droq;
if (oct->int_status & OCT_DEV_INTR_PKT_DATA) {
for (oq_no = 0; oq_no < MAX_OCTEON_OUTPUT_QUEUES(oct);
oq_no++) {
if (!(oct->droq_intr & BIT_ULL(oq_no)))
continue;
droq = oct->droq[oq_no];
if (droq->ops.poll_mode) {
droq->ops.napi_fn(droq);
oct_priv->napi_mask |= (1 << oq_no);
} else {
tasklet_schedule(&oct_priv->droq_tasklet);
}
}
}
}
static int octeon_setup_interrupt(struct octeon_device *oct)
{
int irqret, err;
struct msix_entry *msix_entries;
int i;
int num_ioq_vectors;
int num_alloc_ioq_vectors;
if (OCTEON_CN23XX_PF(oct) && oct->msix_on) {
oct->num_msix_irqs = oct->sriov_info.num_pf_rings;
oct->num_msix_irqs += 1;
oct->msix_entries = kcalloc(
oct->num_msix_irqs, sizeof(struct msix_entry), GFP_KERNEL);
if (!oct->msix_entries)
return 1;
msix_entries = (struct msix_entry *)oct->msix_entries;
for (i = 0; i < oct->num_msix_irqs - 1; i++)
msix_entries[i].entry = oct->sriov_info.pf_srn + i;
msix_entries[oct->num_msix_irqs - 1].entry =
oct->sriov_info.trs;
num_alloc_ioq_vectors = pci_enable_msix_range(
oct->pci_dev, msix_entries,
oct->num_msix_irqs,
oct->num_msix_irqs);
if (num_alloc_ioq_vectors < 0) {
dev_err(&oct->pci_dev->dev, "unable to Allocate MSI-X interrupts\n");
kfree(oct->msix_entries);
oct->msix_entries = NULL;
return 1;
}
dev_dbg(&oct->pci_dev->dev, "OCTEON: Enough MSI-X interrupts are allocated...\n");
num_ioq_vectors = oct->num_msix_irqs;
num_ioq_vectors -= 1;
irqret = request_irq(msix_entries[num_ioq_vectors].vector,
liquidio_legacy_intr_handler, 0, "octeon",
oct);
if (irqret) {
dev_err(&oct->pci_dev->dev,
"OCTEON: Request_irq failed for MSIX interrupt Error: %d\n",
irqret);
pci_disable_msix(oct->pci_dev);
kfree(oct->msix_entries);
oct->msix_entries = NULL;
return 1;
}
for (i = 0; i < num_ioq_vectors; i++) {
irqret = request_irq(msix_entries[i].vector,
liquidio_msix_intr_handler, 0,
"octeon", &oct->ioq_vector[i]);
if (irqret) {
dev_err(&oct->pci_dev->dev,
"OCTEON: Request_irq failed for MSIX interrupt Error: %d\n",
irqret);
free_irq(msix_entries[num_ioq_vectors].vector,
oct);
while (i) {
i--;
irq_set_affinity_hint(
msix_entries[i].vector, NULL);
free_irq(msix_entries[i].vector,
&oct->ioq_vector[i]);
}
pci_disable_msix(oct->pci_dev);
kfree(oct->msix_entries);
oct->msix_entries = NULL;
return 1;
}
oct->ioq_vector[i].vector = msix_entries[i].vector;
irq_set_affinity_hint(
msix_entries[i].vector,
(&oct->ioq_vector[i].affinity_mask));
}
dev_dbg(&oct->pci_dev->dev, "OCTEON[%d]: MSI-X enabled\n",
oct->octeon_id);
} else {
err = pci_enable_msi(oct->pci_dev);
if (err)
dev_warn(&oct->pci_dev->dev, "Reverting to legacy interrupts. Error: %d\n",
err);
else
oct->flags |= LIO_FLAG_MSI_ENABLED;
irqret = request_irq(oct->pci_dev->irq,
liquidio_legacy_intr_handler, IRQF_SHARED,
"octeon", oct);
if (irqret) {
if (oct->flags & LIO_FLAG_MSI_ENABLED)
pci_disable_msi(oct->pci_dev);
dev_err(&oct->pci_dev->dev, "Request IRQ failed with code: %d\n",
irqret);
return 1;
}
}
return 0;
}
static int liquidio_watchdog(void *param)
{
u64 wdog;
u16 mask_of_stuck_cores = 0;
u16 mask_of_crashed_cores = 0;
int core_num;
u8 core_is_stuck[LIO_MAX_CORES];
u8 core_crashed[LIO_MAX_CORES];
struct octeon_device *oct = param;
memset(core_is_stuck, 0, sizeof(core_is_stuck));
memset(core_crashed, 0, sizeof(core_crashed));
while (!kthread_should_stop()) {
mask_of_crashed_cores =
(u16)octeon_read_csr64(oct, CN23XX_SLI_SCRATCH2);
for (core_num = 0; core_num < LIO_MAX_CORES; core_num++) {
if (!core_is_stuck[core_num]) {
wdog = lio_pci_readq(oct, CIU3_WDOG(core_num));
wdog &= CIU3_WDOG_MASK;
if (wdog) {
core_is_stuck[core_num] =
LIO_MONITOR_WDOG_EXPIRE;
mask_of_stuck_cores |= (1 << core_num);
}
}
if (!core_crashed[core_num])
core_crashed[core_num] =
(mask_of_crashed_cores >> core_num) & 1;
}
if (mask_of_stuck_cores) {
for (core_num = 0; core_num < LIO_MAX_CORES;
core_num++) {
if (core_is_stuck[core_num] == 1) {
dev_err(&oct->pci_dev->dev,
"ERROR: Octeon core %d is stuck!\n",
core_num);
core_is_stuck[core_num] =
LIO_MONITOR_CORE_STUCK_MSGD;
}
}
}
if (mask_of_crashed_cores) {
for (core_num = 0; core_num < LIO_MAX_CORES;
core_num++) {
if (core_crashed[core_num] == 1) {
dev_err(&oct->pci_dev->dev,
"ERROR: Octeon core %d crashed! See oct-fwdump for details.\n",
core_num);
core_crashed[core_num] =
LIO_MONITOR_CORE_STUCK_MSGD;
}
}
}
#ifdef CONFIG_MODULE_UNLOAD
if (mask_of_stuck_cores || mask_of_crashed_cores) {
long refcount;
refcount = module_refcount(THIS_MODULE);
while (refcount > 0) {
module_put(THIS_MODULE);
refcount = module_refcount(THIS_MODULE);
}
while (refcount < 0) {
try_module_get(THIS_MODULE);
refcount = module_refcount(THIS_MODULE);
}
}
#endif
set_current_state(TASK_INTERRUPTIBLE);
schedule_timeout(2 * HZ);
}
return 0;
}
static void octeon_destroy_resources(struct octeon_device *oct)
{
int i;
struct msix_entry *msix_entries;
struct octeon_device_priv *oct_priv =
(struct octeon_device_priv *)oct->priv;
struct handshake *hs;
switch (atomic_read(&oct->status)) {
case OCT_DEV_RUNNING:
case OCT_DEV_CORE_OK:
atomic_set(&oct->status, OCT_DEV_IN_RESET);
oct->app_mode = CVM_DRV_INVALID_APP;
dev_dbg(&oct->pci_dev->dev, "Device state is now %s\n",
lio_get_state_string(&oct->status));
schedule_timeout_uninterruptible(HZ / 10);
case OCT_DEV_HOST_OK:
case OCT_DEV_CONSOLE_INIT_DONE:
octeon_remove_consoles(oct);
case OCT_DEV_IO_QUEUES_DONE:
if (wait_for_pending_requests(oct))
dev_err(&oct->pci_dev->dev, "There were pending requests\n");
if (lio_wait_for_instr_fetch(oct))
dev_err(&oct->pci_dev->dev, "IQ had pending instructions\n");
oct->fn_list.disable_io_queues(oct);
if (lio_wait_for_oq_pkts(oct))
dev_err(&oct->pci_dev->dev, "OQ had pending packets\n");
case OCT_DEV_INTR_SET_DONE:
oct->fn_list.disable_interrupt(oct, OCTEON_ALL_INTR);
if (oct->msix_on) {
msix_entries = (struct msix_entry *)oct->msix_entries;
for (i = 0; i < oct->num_msix_irqs - 1; i++) {
irq_set_affinity_hint(msix_entries[i].vector,
NULL);
free_irq(msix_entries[i].vector,
&oct->ioq_vector[i]);
}
free_irq(msix_entries[i].vector, oct);
pci_disable_msix(oct->pci_dev);
kfree(oct->msix_entries);
oct->msix_entries = NULL;
} else {
free_irq(oct->pci_dev->irq, oct);
if (oct->flags & LIO_FLAG_MSI_ENABLED)
pci_disable_msi(oct->pci_dev);
}
case OCT_DEV_MSIX_ALLOC_VECTOR_DONE:
if (OCTEON_CN23XX_PF(oct))
octeon_free_ioq_vector(oct);
case OCT_DEV_MBOX_SETUP_DONE:
if (OCTEON_CN23XX_PF(oct))
oct->fn_list.free_mbox(oct);
case OCT_DEV_IN_RESET:
case OCT_DEV_DROQ_INIT_DONE:
mdelay(100);
for (i = 0; i < MAX_OCTEON_OUTPUT_QUEUES(oct); i++) {
if (!(oct->io_qmask.oq & BIT_ULL(i)))
continue;
octeon_delete_droq(oct, i);
}
for (i = 0; i < MAX_OCTEON_DEVICES; i++) {
hs = &handshake[i];
if (hs->pci_dev) {
handshake[oct->octeon_id].init_ok = 0;
complete(&handshake[oct->octeon_id].init);
handshake[oct->octeon_id].started_ok = 0;
complete(&handshake[oct->octeon_id].started);
}
}
case OCT_DEV_RESP_LIST_INIT_DONE:
octeon_delete_response_list(oct);
case OCT_DEV_INSTR_QUEUE_INIT_DONE:
for (i = 0; i < MAX_OCTEON_INSTR_QUEUES(oct); i++) {
if (!(oct->io_qmask.iq & BIT_ULL(i)))
continue;
octeon_delete_instr_queue(oct, i);
}
#ifdef CONFIG_PCI_IOV
if (oct->sriov_info.sriov_enabled)
pci_disable_sriov(oct->pci_dev);
#endif
case OCT_DEV_SC_BUFF_POOL_INIT_DONE:
octeon_free_sc_buffer_pool(oct);
case OCT_DEV_DISPATCH_INIT_DONE:
octeon_delete_dispatch_list(oct);
cancel_delayed_work_sync(&oct->nic_poll_work.work);
case OCT_DEV_PCI_MAP_DONE:
if ((!OCTEON_CN23XX_PF(oct)) || !oct->octeon_id)
oct->fn_list.soft_reset(oct);
octeon_unmap_pci_barx(oct, 0);
octeon_unmap_pci_barx(oct, 1);
case OCT_DEV_PCI_ENABLE_DONE:
pci_clear_master(oct->pci_dev);
pci_disable_device(oct->pci_dev);
case OCT_DEV_BEGIN_STATE:
break;
}
tasklet_kill(&oct_priv->droq_tasklet);
}
static void rx_ctl_callback(struct octeon_device *oct,
u32 status,
void *buf)
{
struct octeon_soft_command *sc = (struct octeon_soft_command *)buf;
struct liquidio_rx_ctl_context *ctx;
ctx = (struct liquidio_rx_ctl_context *)sc->ctxptr;
oct = lio_get_device(ctx->octeon_id);
if (status)
dev_err(&oct->pci_dev->dev, "rx ctl instruction failed. Status: %llx\n",
CVM_CAST64(status));
WRITE_ONCE(ctx->cond, 1);
wmb();
wake_up_interruptible(&ctx->wc);
}
static void send_rx_ctrl_cmd(struct lio *lio, int start_stop)
{
struct octeon_soft_command *sc;
struct liquidio_rx_ctl_context *ctx;
union octnet_cmd *ncmd;
int ctx_size = sizeof(struct liquidio_rx_ctl_context);
struct octeon_device *oct = (struct octeon_device *)lio->oct_dev;
int retval;
if (oct->props[lio->ifidx].rx_on == start_stop)
return;
sc = (struct octeon_soft_command *)
octeon_alloc_soft_command(oct, OCTNET_CMD_SIZE,
16, ctx_size);
ncmd = (union octnet_cmd *)sc->virtdptr;
ctx = (struct liquidio_rx_ctl_context *)sc->ctxptr;
WRITE_ONCE(ctx->cond, 0);
ctx->octeon_id = lio_get_device_id(oct);
init_waitqueue_head(&ctx->wc);
ncmd->u64 = 0;
ncmd->s.cmd = OCTNET_CMD_RX_CTL;
ncmd->s.param1 = start_stop;
octeon_swap_8B_data((u64 *)ncmd, (OCTNET_CMD_SIZE >> 3));
sc->iq_no = lio->linfo.txpciq[0].s.q_no;
octeon_prepare_soft_command(oct, sc, OPCODE_NIC,
OPCODE_NIC_CMD, 0, 0, 0);
sc->callback = rx_ctl_callback;
sc->callback_arg = sc;
sc->wait_time = 5000;
retval = octeon_send_soft_command(oct, sc);
if (retval == IQ_SEND_FAILED) {
netif_info(lio, rx_err, lio->netdev, "Failed to send RX Control message\n");
} else {
if (sleep_cond(&ctx->wc, &ctx->cond) == -EINTR)
return;
oct->props[lio->ifidx].rx_on = start_stop;
}
octeon_free_soft_command(oct, sc);
}
static void liquidio_destroy_nic_device(struct octeon_device *oct, int ifidx)
{
struct net_device *netdev = oct->props[ifidx].netdev;
struct lio *lio;
struct napi_struct *napi, *n;
if (!netdev) {
dev_err(&oct->pci_dev->dev, "%s No netdevice ptr for index %d\n",
__func__, ifidx);
return;
}
lio = GET_LIO(netdev);
dev_dbg(&oct->pci_dev->dev, "NIC device cleanup\n");
if (atomic_read(&lio->ifstate) & LIO_IFSTATE_RUNNING)
liquidio_stop(netdev);
if (oct->props[lio->ifidx].napi_enabled == 1) {
list_for_each_entry_safe(napi, n, &netdev->napi_list, dev_list)
napi_disable(napi);
oct->props[lio->ifidx].napi_enabled = 0;
if (OCTEON_CN23XX_PF(oct))
oct->droq[0]->ops.poll_mode = 0;
}
if (atomic_read(&lio->ifstate) & LIO_IFSTATE_REGISTERED)
unregister_netdev(netdev);
cleanup_link_status_change_wq(netdev);
delete_glists(lio);
free_netdev(netdev);
oct->props[ifidx].gmxport = -1;
oct->props[ifidx].netdev = NULL;
}
static int liquidio_stop_nic_module(struct octeon_device *oct)
{
int i, j;
struct lio *lio;
dev_dbg(&oct->pci_dev->dev, "Stopping network interfaces\n");
if (!oct->ifcount) {
dev_err(&oct->pci_dev->dev, "Init for Octeon was not completed\n");
return 1;
}
spin_lock_bh(&oct->cmd_resp_wqlock);
oct->cmd_resp_state = OCT_DRV_OFFLINE;
spin_unlock_bh(&oct->cmd_resp_wqlock);
for (i = 0; i < oct->ifcount; i++) {
lio = GET_LIO(oct->props[i].netdev);
for (j = 0; j < lio->linfo.num_rxpciq; j++)
octeon_unregister_droq_ops(oct,
lio->linfo.rxpciq[j].s.q_no);
}
for (i = 0; i < oct->ifcount; i++)
liquidio_destroy_nic_device(oct, i);
dev_dbg(&oct->pci_dev->dev, "Network interfaces stopped\n");
return 0;
}
static void liquidio_remove(struct pci_dev *pdev)
{
struct octeon_device *oct_dev = pci_get_drvdata(pdev);
dev_dbg(&oct_dev->pci_dev->dev, "Stopping device\n");
if (oct_dev->watchdog_task)
kthread_stop(oct_dev->watchdog_task);
if (oct_dev->app_mode && (oct_dev->app_mode == CVM_DRV_NIC_APP))
liquidio_stop_nic_module(oct_dev);
octeon_destroy_resources(oct_dev);
dev_info(&oct_dev->pci_dev->dev, "Device removed\n");
octeon_free_device_mem(oct_dev);
}
static int octeon_chip_specific_setup(struct octeon_device *oct)
{
u32 dev_id, rev_id;
int ret = 1;
char *s;
pci_read_config_dword(oct->pci_dev, 0, &dev_id);
pci_read_config_dword(oct->pci_dev, 8, &rev_id);
oct->rev_id = rev_id & 0xff;
switch (dev_id) {
case OCTEON_CN68XX_PCIID:
oct->chip_id = OCTEON_CN68XX;
ret = lio_setup_cn68xx_octeon_device(oct);
s = "CN68XX";
break;
case OCTEON_CN66XX_PCIID:
oct->chip_id = OCTEON_CN66XX;
ret = lio_setup_cn66xx_octeon_device(oct);
s = "CN66XX";
break;
case OCTEON_CN23XX_PCIID_PF:
oct->chip_id = OCTEON_CN23XX_PF_VID;
ret = setup_cn23xx_octeon_pf_device(oct);
s = "CN23XX";
break;
default:
s = "?";
dev_err(&oct->pci_dev->dev, "Unknown device found (dev_id: %x)\n",
dev_id);
}
if (!ret)
dev_info(&oct->pci_dev->dev, "%s PASS%d.%d %s Version: %s\n", s,
OCTEON_MAJOR_REV(oct),
OCTEON_MINOR_REV(oct),
octeon_get_conf(oct)->card_name,
LIQUIDIO_VERSION);
return ret;
}
static int octeon_pci_os_setup(struct octeon_device *oct)
{
if (pci_enable_device(oct->pci_dev)) {
dev_err(&oct->pci_dev->dev, "pci_enable_device failed\n");
return 1;
}
if (dma_set_mask_and_coherent(&oct->pci_dev->dev, DMA_BIT_MASK(64))) {
dev_err(&oct->pci_dev->dev, "Unexpected DMA device capability\n");
pci_disable_device(oct->pci_dev);
return 1;
}
pci_set_master(oct->pci_dev);
return 0;
}
static inline int skb_iq(struct lio *lio, struct sk_buff *skb)
{
int q = 0;
if (netif_is_multiqueue(lio->netdev))
q = skb->queue_mapping % lio->linfo.num_txpciq;
return q;
}
static inline int check_txq_state(struct lio *lio, struct sk_buff *skb)
{
int q = 0, iq = 0;
if (netif_is_multiqueue(lio->netdev)) {
q = skb->queue_mapping;
iq = lio->linfo.txpciq[(q % (lio->linfo.num_txpciq))].s.q_no;
} else {
iq = lio->txq;
q = iq;
}
if (octnet_iq_is_full(lio->oct_dev, iq))
return 0;
if (__netif_subqueue_stopped(lio->netdev, q)) {
INCR_INSTRQUEUE_PKT_COUNT(lio->oct_dev, iq, tx_restart, 1);
wake_q(lio->netdev, q);
}
return 1;
}
static void free_netbuf(void *buf)
{
struct sk_buff *skb;
struct octnet_buf_free_info *finfo;
struct lio *lio;
finfo = (struct octnet_buf_free_info *)buf;
skb = finfo->skb;
lio = finfo->lio;
dma_unmap_single(&lio->oct_dev->pci_dev->dev, finfo->dptr, skb->len,
DMA_TO_DEVICE);
check_txq_state(lio, skb);
tx_buffer_free(skb);
}
static void free_netsgbuf(void *buf)
{
struct octnet_buf_free_info *finfo;
struct sk_buff *skb;
struct lio *lio;
struct octnic_gather *g;
int i, frags, iq;
finfo = (struct octnet_buf_free_info *)buf;
skb = finfo->skb;
lio = finfo->lio;
g = finfo->g;
frags = skb_shinfo(skb)->nr_frags;
dma_unmap_single(&lio->oct_dev->pci_dev->dev,
g->sg[0].ptr[0], (skb->len - skb->data_len),
DMA_TO_DEVICE);
i = 1;
while (frags--) {
struct skb_frag_struct *frag = &skb_shinfo(skb)->frags[i - 1];
pci_unmap_page((lio->oct_dev)->pci_dev,
g->sg[(i >> 2)].ptr[(i & 3)],
frag->size, DMA_TO_DEVICE);
i++;
}
dma_sync_single_for_cpu(&lio->oct_dev->pci_dev->dev,
g->sg_dma_ptr, g->sg_size, DMA_TO_DEVICE);
iq = skb_iq(lio, skb);
spin_lock(&lio->glist_lock[iq]);
list_add_tail(&g->list, &lio->glist[iq]);
spin_unlock(&lio->glist_lock[iq]);
check_txq_state(lio, skb);
tx_buffer_free(skb);
}
static void free_netsgbuf_with_resp(void *buf)
{
struct octeon_soft_command *sc;
struct octnet_buf_free_info *finfo;
struct sk_buff *skb;
struct lio *lio;
struct octnic_gather *g;
int i, frags, iq;
sc = (struct octeon_soft_command *)buf;
skb = (struct sk_buff *)sc->callback_arg;
finfo = (struct octnet_buf_free_info *)&skb->cb;
lio = finfo->lio;
g = finfo->g;
frags = skb_shinfo(skb)->nr_frags;
dma_unmap_single(&lio->oct_dev->pci_dev->dev,
g->sg[0].ptr[0], (skb->len - skb->data_len),
DMA_TO_DEVICE);
i = 1;
while (frags--) {
struct skb_frag_struct *frag = &skb_shinfo(skb)->frags[i - 1];
pci_unmap_page((lio->oct_dev)->pci_dev,
g->sg[(i >> 2)].ptr[(i & 3)],
frag->size, DMA_TO_DEVICE);
i++;
}
dma_sync_single_for_cpu(&lio->oct_dev->pci_dev->dev,
g->sg_dma_ptr, g->sg_size, DMA_TO_DEVICE);
iq = skb_iq(lio, skb);
spin_lock(&lio->glist_lock[iq]);
list_add_tail(&g->list, &lio->glist[iq]);
spin_unlock(&lio->glist_lock[iq]);
check_txq_state(lio, skb);
}
static int liquidio_ptp_adjfreq(struct ptp_clock_info *ptp, s32 ppb)
{
struct lio *lio = container_of(ptp, struct lio, ptp_info);
struct octeon_device *oct = (struct octeon_device *)lio->oct_dev;
u64 comp, delta;
unsigned long flags;
bool neg_adj = false;
if (ppb < 0) {
neg_adj = true;
ppb = -ppb;
}
delta = (u64)ppb << 32;
do_div(delta, oct->coproc_clock_rate);
spin_lock_irqsave(&lio->ptp_lock, flags);
comp = lio_pci_readq(oct, CN6XXX_MIO_PTP_CLOCK_COMP);
if (neg_adj)
comp -= delta;
else
comp += delta;
lio_pci_writeq(oct, comp, CN6XXX_MIO_PTP_CLOCK_COMP);
spin_unlock_irqrestore(&lio->ptp_lock, flags);
return 0;
}
static int liquidio_ptp_adjtime(struct ptp_clock_info *ptp, s64 delta)
{
unsigned long flags;
struct lio *lio = container_of(ptp, struct lio, ptp_info);
spin_lock_irqsave(&lio->ptp_lock, flags);
lio->ptp_adjust += delta;
spin_unlock_irqrestore(&lio->ptp_lock, flags);
return 0;
}
static int liquidio_ptp_gettime(struct ptp_clock_info *ptp,
struct timespec64 *ts)
{
u64 ns;
unsigned long flags;
struct lio *lio = container_of(ptp, struct lio, ptp_info);
struct octeon_device *oct = (struct octeon_device *)lio->oct_dev;
spin_lock_irqsave(&lio->ptp_lock, flags);
ns = lio_pci_readq(oct, CN6XXX_MIO_PTP_CLOCK_HI);
ns += lio->ptp_adjust;
spin_unlock_irqrestore(&lio->ptp_lock, flags);
*ts = ns_to_timespec64(ns);
return 0;
}
static int liquidio_ptp_settime(struct ptp_clock_info *ptp,
const struct timespec64 *ts)
{
u64 ns;
unsigned long flags;
struct lio *lio = container_of(ptp, struct lio, ptp_info);
struct octeon_device *oct = (struct octeon_device *)lio->oct_dev;
ns = timespec_to_ns(ts);
spin_lock_irqsave(&lio->ptp_lock, flags);
lio_pci_writeq(oct, ns, CN6XXX_MIO_PTP_CLOCK_HI);
lio->ptp_adjust = 0;
spin_unlock_irqrestore(&lio->ptp_lock, flags);
return 0;
}
static void oct_ptp_open(struct net_device *netdev)
{
struct lio *lio = GET_LIO(netdev);
struct octeon_device *oct = (struct octeon_device *)lio->oct_dev;
spin_lock_init(&lio->ptp_lock);
snprintf(lio->ptp_info.name, 16, "%s", netdev->name);
lio->ptp_info.owner = THIS_MODULE;
lio->ptp_info.max_adj = 250000000;
lio->ptp_info.n_alarm = 0;
lio->ptp_info.n_ext_ts = 0;
lio->ptp_info.n_per_out = 0;
lio->ptp_info.pps = 0;
lio->ptp_info.adjfreq = liquidio_ptp_adjfreq;
lio->ptp_info.adjtime = liquidio_ptp_adjtime;
lio->ptp_info.gettime64 = liquidio_ptp_gettime;
lio->ptp_info.settime64 = liquidio_ptp_settime;
lio->ptp_info.enable = liquidio_ptp_enable;
lio->ptp_adjust = 0;
lio->ptp_clock = ptp_clock_register(&lio->ptp_info,
&oct->pci_dev->dev);
if (IS_ERR(lio->ptp_clock))
lio->ptp_clock = NULL;
}
static void liquidio_ptp_init(struct octeon_device *oct)
{
u64 clock_comp, cfg;
clock_comp = (u64)NSEC_PER_SEC << 32;
do_div(clock_comp, oct->coproc_clock_rate);
lio_pci_writeq(oct, clock_comp, CN6XXX_MIO_PTP_CLOCK_COMP);
cfg = lio_pci_readq(oct, CN6XXX_MIO_PTP_CLOCK_CFG);
lio_pci_writeq(oct, cfg | 0x01, CN6XXX_MIO_PTP_CLOCK_CFG);
}
static int load_firmware(struct octeon_device *oct)
{
int ret = 0;
const struct firmware *fw;
char fw_name[LIO_MAX_FW_FILENAME_LEN];
char *tmp_fw_type;
if (strncmp(fw_type, LIO_FW_NAME_TYPE_NONE,
sizeof(LIO_FW_NAME_TYPE_NONE)) == 0) {
dev_info(&oct->pci_dev->dev, "Skipping firmware load\n");
return ret;
}
if (fw_type[0] == '\0')
tmp_fw_type = LIO_FW_NAME_TYPE_NIC;
else
tmp_fw_type = fw_type;
sprintf(fw_name, "%s%s%s_%s%s", LIO_FW_DIR, LIO_FW_BASE_NAME,
octeon_get_conf(oct)->card_name, tmp_fw_type,
LIO_FW_NAME_SUFFIX);
ret = request_firmware(&fw, fw_name, &oct->pci_dev->dev);
if (ret) {
dev_err(&oct->pci_dev->dev, "Request firmware failed. Could not find file %s.\n.",
fw_name);
release_firmware(fw);
return ret;
}
ret = octeon_download_firmware(oct, fw->data, fw->size);
release_firmware(fw);
return ret;
}
static int octeon_setup_droq(struct octeon_device *oct, int q_no, int num_descs,
int desc_size, void *app_ctx)
{
int ret_val = 0;
dev_dbg(&oct->pci_dev->dev, "Creating Droq: %d\n", q_no);
ret_val = octeon_create_droq(oct, q_no, num_descs, desc_size, app_ctx);
if (ret_val < 0)
return ret_val;
if (ret_val == 1) {
dev_dbg(&oct->pci_dev->dev, "Using default droq %d\n", q_no);
return 0;
}
octeon_set_droq_pkt_op(oct, q_no, 1);
writel(oct->droq[q_no]->max_count,
oct->droq[q_no]->pkts_credit_reg);
return ret_val;
}
static void napi_schedule_wrapper(void *param)
{
struct napi_struct *napi = param;
napi_schedule(napi);
}
static void liquidio_napi_drv_callback(void *arg)
{
struct octeon_device *oct;
struct octeon_droq *droq = arg;
int this_cpu = smp_processor_id();
oct = droq->oct_dev;
if (OCTEON_CN23XX_PF(oct) || droq->cpu_id == this_cpu) {
napi_schedule_irqoff(&droq->napi);
} else {
struct call_single_data *csd = &droq->csd;
csd->func = napi_schedule_wrapper;
csd->info = &droq->napi;
csd->flags = 0;
smp_call_function_single_async(droq->cpu_id, csd);
}
}
static int liquidio_napi_poll(struct napi_struct *napi, int budget)
{
struct octeon_droq *droq;
int work_done;
int tx_done = 0, iq_no;
struct octeon_instr_queue *iq;
struct octeon_device *oct;
droq = container_of(napi, struct octeon_droq, napi);
oct = droq->oct_dev;
iq_no = droq->q_no;
work_done = octeon_process_droq_poll_cmd(oct, droq->q_no,
POLL_EVENT_PROCESS_PKTS,
budget);
iq = oct->instr_queue[iq_no];
if (iq) {
tx_done = octeon_flush_iq(oct, iq, 1, budget);
update_txq_status(oct, iq_no);
} else {
dev_err(&oct->pci_dev->dev, "%s: iq (%d) num invalid\n",
__func__, iq_no);
}
if ((work_done < budget) && (tx_done)) {
napi_complete(napi);
octeon_process_droq_poll_cmd(droq->oct_dev, droq->q_no,
POLL_EVENT_ENABLE_INTR, 0);
return 0;
}
return (!tx_done) ? (budget) : (work_done);
}
static inline int setup_io_queues(struct octeon_device *octeon_dev,
int ifidx)
{
struct octeon_droq_ops droq_ops;
struct net_device *netdev;
static int cpu_id;
static int cpu_id_modulus;
struct octeon_droq *droq;
struct napi_struct *napi;
int q, q_no, retval = 0;
struct lio *lio;
int num_tx_descs;
netdev = octeon_dev->props[ifidx].netdev;
lio = GET_LIO(netdev);
memset(&droq_ops, 0, sizeof(struct octeon_droq_ops));
droq_ops.fptr = liquidio_push_packet;
droq_ops.farg = (void *)netdev;
droq_ops.poll_mode = 1;
droq_ops.napi_fn = liquidio_napi_drv_callback;
cpu_id = 0;
cpu_id_modulus = num_present_cpus();
for (q = 0; q < lio->linfo.num_rxpciq; q++) {
q_no = lio->linfo.rxpciq[q].s.q_no;
dev_dbg(&octeon_dev->pci_dev->dev,
"setup_io_queues index:%d linfo.rxpciq.s.q_no:%d\n",
q, q_no);
retval = octeon_setup_droq(octeon_dev, q_no,
CFG_GET_NUM_RX_DESCS_NIC_IF
(octeon_get_conf(octeon_dev),
lio->ifidx),
CFG_GET_NUM_RX_BUF_SIZE_NIC_IF
(octeon_get_conf(octeon_dev),
lio->ifidx), NULL);
if (retval) {
dev_err(&octeon_dev->pci_dev->dev,
"%s : Runtime DROQ(RxQ) creation failed.\n",
__func__);
return 1;
}
droq = octeon_dev->droq[q_no];
napi = &droq->napi;
dev_dbg(&octeon_dev->pci_dev->dev, "netif_napi_add netdev:%llx oct:%llx pf_num:%d\n",
(u64)netdev, (u64)octeon_dev, octeon_dev->pf_num);
netif_napi_add(netdev, napi, liquidio_napi_poll, 64);
droq->cpu_id = cpu_id;
cpu_id++;
if (cpu_id >= cpu_id_modulus)
cpu_id = 0;
octeon_register_droq_ops(octeon_dev, q_no, &droq_ops);
}
if (OCTEON_CN23XX_PF(octeon_dev)) {
octeon_dev->droq[0]->ops.poll_mode = 0;
}
for (q = 0; q < lio->linfo.num_txpciq; q++) {
num_tx_descs = CFG_GET_NUM_TX_DESCS_NIC_IF(octeon_get_conf
(octeon_dev),
lio->ifidx);
retval = octeon_setup_iq(octeon_dev, ifidx, q,
lio->linfo.txpciq[q], num_tx_descs,
netdev_get_tx_queue(netdev, q));
if (retval) {
dev_err(&octeon_dev->pci_dev->dev,
" %s : Runtime IQ(TxQ) creation failed.\n",
__func__);
return 1;
}
}
return 0;
}
static void octnet_poll_check_txq_status(struct work_struct *work)
{
struct cavium_wk *wk = (struct cavium_wk *)work;
struct lio *lio = (struct lio *)wk->ctxptr;
if (!ifstate_check(lio, LIO_IFSTATE_RUNNING))
return;
check_txq_status(lio);
queue_delayed_work(lio->txq_status_wq.wq,
&lio->txq_status_wq.wk.work, msecs_to_jiffies(1));
}
static inline int setup_tx_poll_fn(struct net_device *netdev)
{
struct lio *lio = GET_LIO(netdev);
struct octeon_device *oct = lio->oct_dev;
lio->txq_status_wq.wq = alloc_workqueue("txq-status",
WQ_MEM_RECLAIM, 0);
if (!lio->txq_status_wq.wq) {
dev_err(&oct->pci_dev->dev, "unable to create cavium txq status wq\n");
return -1;
}
INIT_DELAYED_WORK(&lio->txq_status_wq.wk.work,
octnet_poll_check_txq_status);
lio->txq_status_wq.wk.ctxptr = lio;
queue_delayed_work(lio->txq_status_wq.wq,
&lio->txq_status_wq.wk.work, msecs_to_jiffies(1));
return 0;
}
static inline void cleanup_tx_poll_fn(struct net_device *netdev)
{
struct lio *lio = GET_LIO(netdev);
if (lio->txq_status_wq.wq) {
cancel_delayed_work_sync(&lio->txq_status_wq.wk.work);
destroy_workqueue(lio->txq_status_wq.wq);
}
}
static int liquidio_open(struct net_device *netdev)
{
struct lio *lio = GET_LIO(netdev);
struct octeon_device *oct = lio->oct_dev;
struct napi_struct *napi, *n;
if (oct->props[lio->ifidx].napi_enabled == 0) {
list_for_each_entry_safe(napi, n, &netdev->napi_list, dev_list)
napi_enable(napi);
oct->props[lio->ifidx].napi_enabled = 1;
if (OCTEON_CN23XX_PF(oct))
oct->droq[0]->ops.poll_mode = 1;
}
oct_ptp_open(netdev);
ifstate_set(lio, LIO_IFSTATE_RUNNING);
lio->intf_open = 1;
netif_info(lio, ifup, lio->netdev, "Interface Open, ready for traffic\n");
if (OCTEON_CN23XX_PF(oct)) {
if (!oct->msix_on)
if (setup_tx_poll_fn(netdev))
return -1;
} else {
if (setup_tx_poll_fn(netdev))
return -1;
}
start_txq(netdev);
send_rx_ctrl_cmd(lio, 1);
dev_info(&oct->pci_dev->dev, "%s interface is opened\n",
netdev->name);
return 0;
}
static int liquidio_stop(struct net_device *netdev)
{
struct lio *lio = GET_LIO(netdev);
struct octeon_device *oct = lio->oct_dev;
ifstate_reset(lio, LIO_IFSTATE_RUNNING);
netif_tx_disable(netdev);
netif_carrier_off(netdev);
lio->intf_open = 0;
lio->linfo.link.s.link_up = 0;
lio->link_changes++;
set_current_state(TASK_INTERRUPTIBLE);
schedule_timeout(msecs_to_jiffies(100));
send_rx_ctrl_cmd(lio, 0);
if (OCTEON_CN23XX_PF(oct)) {
if (!oct->msix_on)
cleanup_tx_poll_fn(netdev);
} else {
cleanup_tx_poll_fn(netdev);
}
if (lio->ptp_clock) {
ptp_clock_unregister(lio->ptp_clock);
lio->ptp_clock = NULL;
}
dev_info(&oct->pci_dev->dev, "%s interface is stopped\n", netdev->name);
return 0;
}
static inline enum octnet_ifflags get_new_flags(struct net_device *netdev)
{
enum octnet_ifflags f = OCTNET_IFFLAG_UNICAST;
if (netdev->flags & IFF_PROMISC)
f |= OCTNET_IFFLAG_PROMISC;
if (netdev->flags & IFF_ALLMULTI)
f |= OCTNET_IFFLAG_ALLMULTI;
if (netdev->flags & IFF_MULTICAST) {
f |= OCTNET_IFFLAG_MULTICAST;
if (netdev_mc_count(netdev) > MAX_OCTEON_MULTICAST_ADDR)
f |= OCTNET_IFFLAG_ALLMULTI;
}
if (netdev->flags & IFF_BROADCAST)
f |= OCTNET_IFFLAG_BROADCAST;
return f;
}
static void liquidio_set_mcast_list(struct net_device *netdev)
{
struct lio *lio = GET_LIO(netdev);
struct octeon_device *oct = lio->oct_dev;
struct octnic_ctrl_pkt nctrl;
struct netdev_hw_addr *ha;
u64 *mc;
int ret;
int mc_count = min(netdev_mc_count(netdev), MAX_OCTEON_MULTICAST_ADDR);
memset(&nctrl, 0, sizeof(struct octnic_ctrl_pkt));
nctrl.ncmd.u64 = 0;
nctrl.ncmd.s.cmd = OCTNET_CMD_SET_MULTI_LIST;
nctrl.ncmd.s.param1 = get_new_flags(netdev);
nctrl.ncmd.s.param2 = mc_count;
nctrl.ncmd.s.more = mc_count;
nctrl.iq_no = lio->linfo.txpciq[0].s.q_no;
nctrl.netpndev = (u64)netdev;
nctrl.cb_fn = liquidio_link_ctrl_cmd_completion;
mc = &nctrl.udd[0];
netdev_for_each_mc_addr(ha, netdev) {
*mc = 0;
memcpy(((u8 *)mc) + 2, ha->addr, ETH_ALEN);
if (++mc > &nctrl.udd[mc_count])
break;
}
nctrl.wait_time = 0;
ret = octnet_send_nic_ctrl_pkt(lio->oct_dev, &nctrl);
if (ret < 0) {
dev_err(&oct->pci_dev->dev, "DEVFLAGS change failed in core (ret: 0x%x)\n",
ret);
}
}
static int liquidio_set_mac(struct net_device *netdev, void *p)
{
int ret = 0;
struct lio *lio = GET_LIO(netdev);
struct octeon_device *oct = lio->oct_dev;
struct sockaddr *addr = (struct sockaddr *)p;
struct octnic_ctrl_pkt nctrl;
if (!is_valid_ether_addr(addr->sa_data))
return -EADDRNOTAVAIL;
memset(&nctrl, 0, sizeof(struct octnic_ctrl_pkt));
nctrl.ncmd.u64 = 0;
nctrl.ncmd.s.cmd = OCTNET_CMD_CHANGE_MACADDR;
nctrl.ncmd.s.param1 = 0;
nctrl.ncmd.s.more = 1;
nctrl.iq_no = lio->linfo.txpciq[0].s.q_no;
nctrl.netpndev = (u64)netdev;
nctrl.cb_fn = liquidio_link_ctrl_cmd_completion;
nctrl.wait_time = 100;
nctrl.udd[0] = 0;
memcpy((u8 *)&nctrl.udd[0] + 2, addr->sa_data, ETH_ALEN);
ret = octnet_send_nic_ctrl_pkt(lio->oct_dev, &nctrl);
if (ret < 0) {
dev_err(&oct->pci_dev->dev, "MAC Address change failed\n");
return -ENOMEM;
}
memcpy(netdev->dev_addr, addr->sa_data, netdev->addr_len);
memcpy(((u8 *)&lio->linfo.hw_addr) + 2, addr->sa_data, ETH_ALEN);
return 0;
}
static struct net_device_stats *liquidio_get_stats(struct net_device *netdev)
{
struct lio *lio = GET_LIO(netdev);
struct net_device_stats *stats = &netdev->stats;
struct octeon_device *oct;
u64 pkts = 0, drop = 0, bytes = 0;
struct oct_droq_stats *oq_stats;
struct oct_iq_stats *iq_stats;
int i, iq_no, oq_no;
oct = lio->oct_dev;
for (i = 0; i < lio->linfo.num_txpciq; i++) {
iq_no = lio->linfo.txpciq[i].s.q_no;
iq_stats = &oct->instr_queue[iq_no]->stats;
pkts += iq_stats->tx_done;
drop += iq_stats->tx_dropped;
bytes += iq_stats->tx_tot_bytes;
}
stats->tx_packets = pkts;
stats->tx_bytes = bytes;
stats->tx_dropped = drop;
pkts = 0;
drop = 0;
bytes = 0;
for (i = 0; i < lio->linfo.num_rxpciq; i++) {
oq_no = lio->linfo.rxpciq[i].s.q_no;
oq_stats = &oct->droq[oq_no]->stats;
pkts += oq_stats->rx_pkts_received;
drop += (oq_stats->rx_dropped +
oq_stats->dropped_nodispatch +
oq_stats->dropped_toomany +
oq_stats->dropped_nomem);
bytes += oq_stats->rx_bytes_received;
}
stats->rx_bytes = bytes;
stats->rx_packets = pkts;
stats->rx_dropped = drop;
return stats;
}
static int liquidio_change_mtu(struct net_device *netdev, int new_mtu)
{
struct lio *lio = GET_LIO(netdev);
struct octeon_device *oct = lio->oct_dev;
struct octnic_ctrl_pkt nctrl;
int ret = 0;
memset(&nctrl, 0, sizeof(struct octnic_ctrl_pkt));
nctrl.ncmd.u64 = 0;
nctrl.ncmd.s.cmd = OCTNET_CMD_CHANGE_MTU;
nctrl.ncmd.s.param1 = new_mtu;
nctrl.iq_no = lio->linfo.txpciq[0].s.q_no;
nctrl.wait_time = 100;
nctrl.netpndev = (u64)netdev;
nctrl.cb_fn = liquidio_link_ctrl_cmd_completion;
ret = octnet_send_nic_ctrl_pkt(lio->oct_dev, &nctrl);
if (ret < 0) {
dev_err(&oct->pci_dev->dev, "Failed to set MTU\n");
return -1;
}
lio->mtu = new_mtu;
return 0;
}
static int hwtstamp_ioctl(struct net_device *netdev, struct ifreq *ifr)
{
struct hwtstamp_config conf;
struct lio *lio = GET_LIO(netdev);
if (copy_from_user(&conf, ifr->ifr_data, sizeof(conf)))
return -EFAULT;
if (conf.flags)
return -EINVAL;
switch (conf.tx_type) {
case HWTSTAMP_TX_ON:
case HWTSTAMP_TX_OFF:
break;
default:
return -ERANGE;
}
switch (conf.rx_filter) {
case HWTSTAMP_FILTER_NONE:
break;
case HWTSTAMP_FILTER_ALL:
case HWTSTAMP_FILTER_SOME:
case HWTSTAMP_FILTER_PTP_V1_L4_EVENT:
case HWTSTAMP_FILTER_PTP_V1_L4_SYNC:
case HWTSTAMP_FILTER_PTP_V1_L4_DELAY_REQ:
case HWTSTAMP_FILTER_PTP_V2_L4_EVENT:
case HWTSTAMP_FILTER_PTP_V2_L4_SYNC:
case HWTSTAMP_FILTER_PTP_V2_L4_DELAY_REQ:
case HWTSTAMP_FILTER_PTP_V2_L2_EVENT:
case HWTSTAMP_FILTER_PTP_V2_L2_SYNC:
case HWTSTAMP_FILTER_PTP_V2_L2_DELAY_REQ:
case HWTSTAMP_FILTER_PTP_V2_EVENT:
case HWTSTAMP_FILTER_PTP_V2_SYNC:
case HWTSTAMP_FILTER_PTP_V2_DELAY_REQ:
conf.rx_filter = HWTSTAMP_FILTER_ALL;
break;
default:
return -ERANGE;
}
if (conf.rx_filter == HWTSTAMP_FILTER_ALL)
ifstate_set(lio, LIO_IFSTATE_RX_TIMESTAMP_ENABLED);
else
ifstate_reset(lio, LIO_IFSTATE_RX_TIMESTAMP_ENABLED);
return copy_to_user(ifr->ifr_data, &conf, sizeof(conf)) ? -EFAULT : 0;
}
static int liquidio_ioctl(struct net_device *netdev, struct ifreq *ifr, int cmd)
{
switch (cmd) {
case SIOCSHWTSTAMP:
return hwtstamp_ioctl(netdev, ifr);
default:
return -EOPNOTSUPP;
}
}
static void handle_timestamp(struct octeon_device *oct,
u32 status,
void *buf)
{
struct octnet_buf_free_info *finfo;
struct octeon_soft_command *sc;
struct oct_timestamp_resp *resp;
struct lio *lio;
struct sk_buff *skb = (struct sk_buff *)buf;
finfo = (struct octnet_buf_free_info *)skb->cb;
lio = finfo->lio;
sc = finfo->sc;
oct = lio->oct_dev;
resp = (struct oct_timestamp_resp *)sc->virtrptr;
if (status != OCTEON_REQUEST_DONE) {
dev_err(&oct->pci_dev->dev, "Tx timestamp instruction failed. Status: %llx\n",
CVM_CAST64(status));
resp->timestamp = 0;
}
octeon_swap_8B_data(&resp->timestamp, 1);
if (unlikely((skb_shinfo(skb)->tx_flags & SKBTX_IN_PROGRESS) != 0)) {
struct skb_shared_hwtstamps ts;
u64 ns = resp->timestamp;
netif_info(lio, tx_done, lio->netdev,
"Got resulting SKBTX_HW_TSTAMP skb=%p ns=%016llu\n",
skb, (unsigned long long)ns);
ts.hwtstamp = ns_to_ktime(ns + lio->ptp_adjust);
skb_tstamp_tx(skb, &ts);
}
octeon_free_soft_command(oct, sc);
tx_buffer_free(skb);
}
static inline int send_nic_timestamp_pkt(struct octeon_device *oct,
struct octnic_data_pkt *ndata,
struct octnet_buf_free_info *finfo)
{
int retval;
struct octeon_soft_command *sc;
struct lio *lio;
int ring_doorbell;
u32 len;
lio = finfo->lio;
sc = octeon_alloc_soft_command_resp(oct, &ndata->cmd,
sizeof(struct oct_timestamp_resp));
finfo->sc = sc;
if (!sc) {
dev_err(&oct->pci_dev->dev, "No memory for timestamped data packet\n");
return IQ_SEND_FAILED;
}
if (ndata->reqtype == REQTYPE_NORESP_NET)
ndata->reqtype = REQTYPE_RESP_NET;
else if (ndata->reqtype == REQTYPE_NORESP_NET_SG)
ndata->reqtype = REQTYPE_RESP_NET_SG;
sc->callback = handle_timestamp;
sc->callback_arg = finfo->skb;
sc->iq_no = ndata->q_no;
if (OCTEON_CN23XX_PF(oct))
len = (u32)((struct octeon_instr_ih3 *)
(&sc->cmd.cmd3.ih3))->dlengsz;
else
len = (u32)((struct octeon_instr_ih2 *)
(&sc->cmd.cmd2.ih2))->dlengsz;
ring_doorbell = 1;
retval = octeon_send_command(oct, sc->iq_no, ring_doorbell, &sc->cmd,
sc, len, ndata->reqtype);
if (retval == IQ_SEND_FAILED) {
dev_err(&oct->pci_dev->dev, "timestamp data packet failed status: %x\n",
retval);
octeon_free_soft_command(oct, sc);
} else {
netif_info(lio, tx_queued, lio->netdev, "Queued timestamp packet\n");
}
return retval;
}
static int liquidio_xmit(struct sk_buff *skb, struct net_device *netdev)
{
struct lio *lio;
struct octnet_buf_free_info *finfo;
union octnic_cmd_setup cmdsetup;
struct octnic_data_pkt ndata;
struct octeon_device *oct;
struct oct_iq_stats *stats;
struct octeon_instr_irh *irh;
union tx_info *tx_info;
int status = 0;
int q_idx = 0, iq_no = 0;
int j;
u64 dptr = 0;
u32 tag = 0;
lio = GET_LIO(netdev);
oct = lio->oct_dev;
if (netif_is_multiqueue(netdev)) {
q_idx = skb->queue_mapping;
q_idx = (q_idx % (lio->linfo.num_txpciq));
tag = q_idx;
iq_no = lio->linfo.txpciq[q_idx].s.q_no;
} else {
iq_no = lio->txq;
}
stats = &oct->instr_queue[iq_no]->stats;
if (!(atomic_read(&lio->ifstate) & LIO_IFSTATE_RUNNING) ||
(!lio->linfo.link.s.link_up) ||
(skb->len <= 0)) {
netif_info(lio, tx_err, lio->netdev,
"Transmit failed link_status : %d\n",
lio->linfo.link.s.link_up);
goto lio_xmit_failed;
}
finfo = (struct octnet_buf_free_info *)skb->cb;
finfo->lio = lio;
finfo->skb = skb;
finfo->sc = NULL;
memset(&ndata, 0, sizeof(struct octnic_data_pkt));
ndata.buf = (void *)finfo;
ndata.q_no = iq_no;
if (netif_is_multiqueue(netdev)) {
if (octnet_iq_is_full(oct, ndata.q_no)) {
netif_info(lio, tx_err, lio->netdev, "Transmit failed iq:%d full\n",
ndata.q_no);
stats->tx_iq_busy++;
return NETDEV_TX_BUSY;
}
} else {
if (octnet_iq_is_full(oct, lio->txq)) {
stats->tx_iq_busy++;
netif_info(lio, tx_err, lio->netdev, "Transmit failed iq:%d full\n",
lio->txq);
return NETDEV_TX_BUSY;
}
}
ndata.datasize = skb->len;
cmdsetup.u64 = 0;
cmdsetup.s.iq_no = iq_no;
if (skb->ip_summed == CHECKSUM_PARTIAL) {
if (skb->encapsulation) {
cmdsetup.s.tnl_csum = 1;
stats->tx_vxlan++;
} else {
cmdsetup.s.transport_csum = 1;
}
}
if (unlikely(skb_shinfo(skb)->tx_flags & SKBTX_HW_TSTAMP)) {
skb_shinfo(skb)->tx_flags |= SKBTX_IN_PROGRESS;
cmdsetup.s.timestamp = 1;
}
if (skb_shinfo(skb)->nr_frags == 0) {
cmdsetup.s.u.datasize = skb->len;
octnet_prepare_pci_cmd(oct, &ndata.cmd, &cmdsetup, tag);
dptr = dma_map_single(&oct->pci_dev->dev,
skb->data,
skb->len,
DMA_TO_DEVICE);
if (dma_mapping_error(&oct->pci_dev->dev, dptr)) {
dev_err(&oct->pci_dev->dev, "%s DMA mapping error 1\n",
__func__);
return NETDEV_TX_BUSY;
}
if (OCTEON_CN23XX_PF(oct))
ndata.cmd.cmd3.dptr = dptr;
else
ndata.cmd.cmd2.dptr = dptr;
finfo->dptr = dptr;
ndata.reqtype = REQTYPE_NORESP_NET;
} else {
int i, frags;
struct skb_frag_struct *frag;
struct octnic_gather *g;
spin_lock(&lio->glist_lock[q_idx]);
g = (struct octnic_gather *)
list_delete_head(&lio->glist[q_idx]);
spin_unlock(&lio->glist_lock[q_idx]);
if (!g) {
netif_info(lio, tx_err, lio->netdev,
"Transmit scatter gather: glist null!\n");
goto lio_xmit_failed;
}
cmdsetup.s.gather = 1;
cmdsetup.s.u.gatherptrs = (skb_shinfo(skb)->nr_frags + 1);
octnet_prepare_pci_cmd(oct, &ndata.cmd, &cmdsetup, tag);
memset(g->sg, 0, g->sg_size);
g->sg[0].ptr[0] = dma_map_single(&oct->pci_dev->dev,
skb->data,
(skb->len - skb->data_len),
DMA_TO_DEVICE);
if (dma_mapping_error(&oct->pci_dev->dev, g->sg[0].ptr[0])) {
dev_err(&oct->pci_dev->dev, "%s DMA mapping error 2\n",
__func__);
return NETDEV_TX_BUSY;
}
add_sg_size(&g->sg[0], (skb->len - skb->data_len), 0);
frags = skb_shinfo(skb)->nr_frags;
i = 1;
while (frags--) {
frag = &skb_shinfo(skb)->frags[i - 1];
g->sg[(i >> 2)].ptr[(i & 3)] =
dma_map_page(&oct->pci_dev->dev,
frag->page.p,
frag->page_offset,
frag->size,
DMA_TO_DEVICE);
if (dma_mapping_error(&oct->pci_dev->dev,
g->sg[i >> 2].ptr[i & 3])) {
dma_unmap_single(&oct->pci_dev->dev,
g->sg[0].ptr[0],
skb->len - skb->data_len,
DMA_TO_DEVICE);
for (j = 1; j < i; j++) {
frag = &skb_shinfo(skb)->frags[j - 1];
dma_unmap_page(&oct->pci_dev->dev,
g->sg[j >> 2].ptr[j & 3],
frag->size,
DMA_TO_DEVICE);
}
dev_err(&oct->pci_dev->dev, "%s DMA mapping error 3\n",
__func__);
return NETDEV_TX_BUSY;
}
add_sg_size(&g->sg[(i >> 2)], frag->size, (i & 3));
i++;
}
dma_sync_single_for_device(&oct->pci_dev->dev, g->sg_dma_ptr,
g->sg_size, DMA_TO_DEVICE);
dptr = g->sg_dma_ptr;
if (OCTEON_CN23XX_PF(oct))
ndata.cmd.cmd3.dptr = dptr;
else
ndata.cmd.cmd2.dptr = dptr;
finfo->dptr = dptr;
finfo->g = g;
ndata.reqtype = REQTYPE_NORESP_NET_SG;
}
if (OCTEON_CN23XX_PF(oct)) {
irh = (struct octeon_instr_irh *)&ndata.cmd.cmd3.irh;
tx_info = (union tx_info *)&ndata.cmd.cmd3.ossp[0];
} else {
irh = (struct octeon_instr_irh *)&ndata.cmd.cmd2.irh;
tx_info = (union tx_info *)&ndata.cmd.cmd2.ossp[0];
}
if (skb_shinfo(skb)->gso_size) {
tx_info->s.gso_size = skb_shinfo(skb)->gso_size;
tx_info->s.gso_segs = skb_shinfo(skb)->gso_segs;
stats->tx_gso++;
}
if (skb_vlan_tag_present(skb)) {
irh->priority = skb_vlan_tag_get(skb) >> 13;
irh->vlan = skb_vlan_tag_get(skb) & 0xfff;
}
if (unlikely(cmdsetup.s.timestamp))
status = send_nic_timestamp_pkt(oct, &ndata, finfo);
else
status = octnet_send_nic_data_pkt(oct, &ndata);
if (status == IQ_SEND_FAILED)
goto lio_xmit_failed;
netif_info(lio, tx_queued, lio->netdev, "Transmit queued successfully\n");
if (status == IQ_SEND_STOP)
stop_q(lio->netdev, q_idx);
netif_trans_update(netdev);
if (skb_shinfo(skb)->gso_size)
stats->tx_done += skb_shinfo(skb)->gso_segs;
else
stats->tx_done++;
stats->tx_tot_bytes += skb->len;
return NETDEV_TX_OK;
lio_xmit_failed:
stats->tx_dropped++;
netif_info(lio, tx_err, lio->netdev, "IQ%d Transmit dropped:%llu\n",
iq_no, stats->tx_dropped);
if (dptr)
dma_unmap_single(&oct->pci_dev->dev, dptr,
ndata.datasize, DMA_TO_DEVICE);
tx_buffer_free(skb);
return NETDEV_TX_OK;
}
static void liquidio_tx_timeout(struct net_device *netdev)
{
struct lio *lio;
lio = GET_LIO(netdev);
netif_info(lio, tx_err, lio->netdev,
"Transmit timeout tx_dropped:%ld, waking up queues now!!\n",
netdev->stats.tx_dropped);
netif_trans_update(netdev);
txqs_wake(netdev);
}
static int liquidio_set_rxcsum_command(struct net_device *netdev, int command,
u8 rx_cmd)
{
struct lio *lio = GET_LIO(netdev);
struct octeon_device *oct = lio->oct_dev;
struct octnic_ctrl_pkt nctrl;
int ret = 0;
nctrl.ncmd.u64 = 0;
nctrl.ncmd.s.cmd = command;
nctrl.ncmd.s.param1 = rx_cmd;
nctrl.iq_no = lio->linfo.txpciq[0].s.q_no;
nctrl.wait_time = 100;
nctrl.netpndev = (u64)netdev;
nctrl.cb_fn = liquidio_link_ctrl_cmd_completion;
ret = octnet_send_nic_ctrl_pkt(lio->oct_dev, &nctrl);
if (ret < 0) {
dev_err(&oct->pci_dev->dev,
"DEVFLAGS RXCSUM change failed in core(ret:0x%x)\n",
ret);
}
return ret;
}
static int liquidio_vxlan_port_command(struct net_device *netdev, int command,
u16 vxlan_port, u8 vxlan_cmd_bit)
{
struct lio *lio = GET_LIO(netdev);
struct octeon_device *oct = lio->oct_dev;
struct octnic_ctrl_pkt nctrl;
int ret = 0;
nctrl.ncmd.u64 = 0;
nctrl.ncmd.s.cmd = command;
nctrl.ncmd.s.more = vxlan_cmd_bit;
nctrl.ncmd.s.param1 = vxlan_port;
nctrl.iq_no = lio->linfo.txpciq[0].s.q_no;
nctrl.wait_time = 100;
nctrl.netpndev = (u64)netdev;
nctrl.cb_fn = liquidio_link_ctrl_cmd_completion;
ret = octnet_send_nic_ctrl_pkt(lio->oct_dev, &nctrl);
if (ret < 0) {
dev_err(&oct->pci_dev->dev,
"VxLAN port add/delete failed in core (ret:0x%x)\n",
ret);
}
return ret;
}
static netdev_features_t liquidio_fix_features(struct net_device *netdev,
netdev_features_t request)
{
struct lio *lio = netdev_priv(netdev);
if ((request & NETIF_F_RXCSUM) &&
!(lio->dev_capability & NETIF_F_RXCSUM))
request &= ~NETIF_F_RXCSUM;
if ((request & NETIF_F_HW_CSUM) &&
!(lio->dev_capability & NETIF_F_HW_CSUM))
request &= ~NETIF_F_HW_CSUM;
if ((request & NETIF_F_TSO) && !(lio->dev_capability & NETIF_F_TSO))
request &= ~NETIF_F_TSO;
if ((request & NETIF_F_TSO6) && !(lio->dev_capability & NETIF_F_TSO6))
request &= ~NETIF_F_TSO6;
if ((request & NETIF_F_LRO) && !(lio->dev_capability & NETIF_F_LRO))
request &= ~NETIF_F_LRO;
if (!(request & NETIF_F_RXCSUM) && (netdev->features & NETIF_F_LRO) &&
(lio->dev_capability & NETIF_F_LRO))
request &= ~NETIF_F_LRO;
return request;
}
static int liquidio_set_features(struct net_device *netdev,
netdev_features_t features)
{
struct lio *lio = netdev_priv(netdev);
if (!((netdev->features ^ features) & NETIF_F_LRO))
return 0;
if ((features & NETIF_F_LRO) && (lio->dev_capability & NETIF_F_LRO))
liquidio_set_feature(netdev, OCTNET_CMD_LRO_ENABLE,
OCTNIC_LROIPV4 | OCTNIC_LROIPV6);
else if (!(features & NETIF_F_LRO) &&
(lio->dev_capability & NETIF_F_LRO))
liquidio_set_feature(netdev, OCTNET_CMD_LRO_DISABLE,
OCTNIC_LROIPV4 | OCTNIC_LROIPV6);
if (!(netdev->features & NETIF_F_RXCSUM) &&
(lio->enc_dev_capability & NETIF_F_RXCSUM) &&
(features & NETIF_F_RXCSUM))
liquidio_set_rxcsum_command(netdev,
OCTNET_CMD_TNL_RX_CSUM_CTL,
OCTNET_CMD_RXCSUM_ENABLE);
else if ((netdev->features & NETIF_F_RXCSUM) &&
(lio->enc_dev_capability & NETIF_F_RXCSUM) &&
!(features & NETIF_F_RXCSUM))
liquidio_set_rxcsum_command(netdev, OCTNET_CMD_TNL_RX_CSUM_CTL,
OCTNET_CMD_RXCSUM_DISABLE);
return 0;
}
static void liquidio_add_vxlan_port(struct net_device *netdev,
struct udp_tunnel_info *ti)
{
if (ti->type != UDP_TUNNEL_TYPE_VXLAN)
return;
liquidio_vxlan_port_command(netdev,
OCTNET_CMD_VXLAN_PORT_CONFIG,
htons(ti->port),
OCTNET_CMD_VXLAN_PORT_ADD);
}
static void liquidio_del_vxlan_port(struct net_device *netdev,
struct udp_tunnel_info *ti)
{
if (ti->type != UDP_TUNNEL_TYPE_VXLAN)
return;
liquidio_vxlan_port_command(netdev,
OCTNET_CMD_VXLAN_PORT_CONFIG,
htons(ti->port),
OCTNET_CMD_VXLAN_PORT_DEL);
}
static int __liquidio_set_vf_mac(struct net_device *netdev, int vfidx,
u8 *mac, bool is_admin_assigned)
{
struct lio *lio = GET_LIO(netdev);
struct octeon_device *oct = lio->oct_dev;
struct octnic_ctrl_pkt nctrl;
if (!is_valid_ether_addr(mac))
return -EINVAL;
if (vfidx < 0 || vfidx >= oct->sriov_info.max_vfs)
return -EINVAL;
memset(&nctrl, 0, sizeof(struct octnic_ctrl_pkt));
nctrl.ncmd.u64 = 0;
nctrl.ncmd.s.cmd = OCTNET_CMD_CHANGE_MACADDR;
nctrl.ncmd.s.param1 = vfidx + 1;
nctrl.ncmd.s.param2 = (is_admin_assigned ? 1 : 0);
nctrl.ncmd.s.more = 1;
nctrl.iq_no = lio->linfo.txpciq[0].s.q_no;
nctrl.cb_fn = 0;
nctrl.wait_time = LIO_CMD_WAIT_TM;
nctrl.udd[0] = 0;
ether_addr_copy((u8 *)&nctrl.udd[0] + 2, mac);
oct->sriov_info.vf_macaddr[vfidx] = nctrl.udd[0];
octnet_send_nic_ctrl_pkt(oct, &nctrl);
return 0;
}
static int liquidio_set_vf_mac(struct net_device *netdev, int vfidx, u8 *mac)
{
struct lio *lio = GET_LIO(netdev);
struct octeon_device *oct = lio->oct_dev;
int retval;
retval = __liquidio_set_vf_mac(netdev, vfidx, mac, true);
if (!retval)
cn23xx_tell_vf_its_macaddr_changed(oct, vfidx, mac);
return retval;
}
static int liquidio_set_vf_vlan(struct net_device *netdev, int vfidx,
u16 vlan, u8 qos, __be16 vlan_proto)
{
struct lio *lio = GET_LIO(netdev);
struct octeon_device *oct = lio->oct_dev;
struct octnic_ctrl_pkt nctrl;
u16 vlantci;
if (vfidx < 0 || vfidx >= oct->sriov_info.num_vfs_alloced)
return -EINVAL;
if (vlan_proto != htons(ETH_P_8021Q))
return -EPROTONOSUPPORT;
if (vlan >= VLAN_N_VID || qos > 7)
return -EINVAL;
if (vlan)
vlantci = vlan | (u16)qos << VLAN_PRIO_SHIFT;
else
vlantci = 0;
if (oct->sriov_info.vf_vlantci[vfidx] == vlantci)
return 0;
memset(&nctrl, 0, sizeof(struct octnic_ctrl_pkt));
if (vlan)
nctrl.ncmd.s.cmd = OCTNET_CMD_ADD_VLAN_FILTER;
else
nctrl.ncmd.s.cmd = OCTNET_CMD_DEL_VLAN_FILTER;
nctrl.ncmd.s.param1 = vlantci;
nctrl.ncmd.s.param2 =
vfidx + 1;
nctrl.ncmd.s.more = 0;
nctrl.iq_no = lio->linfo.txpciq[0].s.q_no;
nctrl.cb_fn = 0;
nctrl.wait_time = LIO_CMD_WAIT_TM;
octnet_send_nic_ctrl_pkt(oct, &nctrl);
oct->sriov_info.vf_vlantci[vfidx] = vlantci;
return 0;
}
static int liquidio_get_vf_config(struct net_device *netdev, int vfidx,
struct ifla_vf_info *ivi)
{
struct lio *lio = GET_LIO(netdev);
struct octeon_device *oct = lio->oct_dev;
u8 *macaddr;
if (vfidx < 0 || vfidx >= oct->sriov_info.num_vfs_alloced)
return -EINVAL;
ivi->vf = vfidx;
macaddr = 2 + (u8 *)&oct->sriov_info.vf_macaddr[vfidx];
ether_addr_copy(&ivi->mac[0], macaddr);
ivi->vlan = oct->sriov_info.vf_vlantci[vfidx] & VLAN_VID_MASK;
ivi->qos = oct->sriov_info.vf_vlantci[vfidx] >> VLAN_PRIO_SHIFT;
ivi->linkstate = oct->sriov_info.vf_linkstate[vfidx];
return 0;
}
static int liquidio_set_vf_link_state(struct net_device *netdev, int vfidx,
int linkstate)
{
struct lio *lio = GET_LIO(netdev);
struct octeon_device *oct = lio->oct_dev;
struct octnic_ctrl_pkt nctrl;
if (vfidx < 0 || vfidx >= oct->sriov_info.num_vfs_alloced)
return -EINVAL;
if (oct->sriov_info.vf_linkstate[vfidx] == linkstate)
return 0;
memset(&nctrl, 0, sizeof(struct octnic_ctrl_pkt));
nctrl.ncmd.s.cmd = OCTNET_CMD_SET_VF_LINKSTATE;
nctrl.ncmd.s.param1 =
vfidx + 1;
nctrl.ncmd.s.param2 = linkstate;
nctrl.ncmd.s.more = 0;
nctrl.iq_no = lio->linfo.txpciq[0].s.q_no;
nctrl.cb_fn = 0;
nctrl.wait_time = LIO_CMD_WAIT_TM;
octnet_send_nic_ctrl_pkt(oct, &nctrl);
oct->sriov_info.vf_linkstate[vfidx] = linkstate;
return 0;
}
static int __init liquidio_init(void)
{
int i;
struct handshake *hs;
init_completion(&first_stage);
octeon_init_device_list(OCTEON_CONFIG_TYPE_DEFAULT);
if (liquidio_init_pci())
return -EINVAL;
wait_for_completion_timeout(&first_stage, msecs_to_jiffies(1000));
for (i = 0; i < MAX_OCTEON_DEVICES; i++) {
hs = &handshake[i];
if (hs->pci_dev) {
wait_for_completion(&hs->init);
if (!hs->init_ok) {
dev_err(&hs->pci_dev->dev,
"Failed to init device\n");
liquidio_deinit_pci();
return -EIO;
}
}
}
for (i = 0; i < MAX_OCTEON_DEVICES; i++) {
hs = &handshake[i];
if (hs->pci_dev) {
wait_for_completion_timeout(&hs->started,
msecs_to_jiffies(30000));
if (!hs->started_ok) {
dev_err(&hs->pci_dev->dev,
"Firmware failed to start\n");
liquidio_deinit_pci();
return -EIO;
}
}
}
return 0;
}
static int lio_nic_info(struct octeon_recv_info *recv_info, void *buf)
{
struct octeon_device *oct = (struct octeon_device *)buf;
struct octeon_recv_pkt *recv_pkt = recv_info->recv_pkt;
int gmxport = 0;
union oct_link_status *ls;
int i;
if (recv_pkt->buffer_size[0] != sizeof(*ls)) {
dev_err(&oct->pci_dev->dev, "Malformed NIC_INFO, len=%d, ifidx=%d\n",
recv_pkt->buffer_size[0],
recv_pkt->rh.r_nic_info.gmxport);
goto nic_info_err;
}
gmxport = recv_pkt->rh.r_nic_info.gmxport;
ls = (union oct_link_status *)get_rbd(recv_pkt->buffer_ptr[0]);
octeon_swap_8B_data((u64 *)ls, (sizeof(union oct_link_status)) >> 3);
for (i = 0; i < oct->ifcount; i++) {
if (oct->props[i].gmxport == gmxport) {
update_link_status(oct->props[i].netdev, ls);
break;
}
}
nic_info_err:
for (i = 0; i < recv_pkt->buffer_count; i++)
recv_buffer_free(recv_pkt->buffer_ptr[i]);
octeon_free_recv_info(recv_info);
return 0;
}
static int setup_nic_devices(struct octeon_device *octeon_dev)
{
struct lio *lio = NULL;
struct net_device *netdev;
u8 mac[6], i, j;
struct octeon_soft_command *sc;
struct liquidio_if_cfg_context *ctx;
struct liquidio_if_cfg_resp *resp;
struct octdev_props *props;
int retval, num_iqueues, num_oqueues;
union oct_nic_if_cfg if_cfg;
unsigned int base_queue;
unsigned int gmx_port_id;
u32 resp_size, ctx_size, data_size;
u32 ifidx_or_pfnum;
struct lio_version *vdata;
octeon_register_dispatch_fn(octeon_dev, OPCODE_NIC,
OPCODE_NIC_INFO,
lio_nic_info, octeon_dev);
octeon_register_reqtype_free_fn(octeon_dev, REQTYPE_NORESP_NET,
free_netbuf);
octeon_register_reqtype_free_fn(octeon_dev, REQTYPE_NORESP_NET_SG,
free_netsgbuf);
octeon_register_reqtype_free_fn(octeon_dev, REQTYPE_RESP_NET_SG,
free_netsgbuf_with_resp);
for (i = 0; i < octeon_dev->ifcount; i++) {
resp_size = sizeof(struct liquidio_if_cfg_resp);
ctx_size = sizeof(struct liquidio_if_cfg_context);
data_size = sizeof(struct lio_version);
sc = (struct octeon_soft_command *)
octeon_alloc_soft_command(octeon_dev, data_size,
resp_size, ctx_size);
resp = (struct liquidio_if_cfg_resp *)sc->virtrptr;
ctx = (struct liquidio_if_cfg_context *)sc->ctxptr;
vdata = (struct lio_version *)sc->virtdptr;
*((u64 *)vdata) = 0;
vdata->major = cpu_to_be16(LIQUIDIO_BASE_MAJOR_VERSION);
vdata->minor = cpu_to_be16(LIQUIDIO_BASE_MINOR_VERSION);
vdata->micro = cpu_to_be16(LIQUIDIO_BASE_MICRO_VERSION);
if (OCTEON_CN23XX_PF(octeon_dev)) {
num_iqueues = octeon_dev->sriov_info.num_pf_rings;
num_oqueues = octeon_dev->sriov_info.num_pf_rings;
base_queue = octeon_dev->sriov_info.pf_srn;
gmx_port_id = octeon_dev->pf_num;
ifidx_or_pfnum = octeon_dev->pf_num;
} else {
num_iqueues = CFG_GET_NUM_TXQS_NIC_IF(
octeon_get_conf(octeon_dev), i);
num_oqueues = CFG_GET_NUM_RXQS_NIC_IF(
octeon_get_conf(octeon_dev), i);
base_queue = CFG_GET_BASE_QUE_NIC_IF(
octeon_get_conf(octeon_dev), i);
gmx_port_id = CFG_GET_GMXID_NIC_IF(
octeon_get_conf(octeon_dev), i);
ifidx_or_pfnum = i;
}
dev_dbg(&octeon_dev->pci_dev->dev,
"requesting config for interface %d, iqs %d, oqs %d\n",
ifidx_or_pfnum, num_iqueues, num_oqueues);
WRITE_ONCE(ctx->cond, 0);
ctx->octeon_id = lio_get_device_id(octeon_dev);
init_waitqueue_head(&ctx->wc);
if_cfg.u64 = 0;
if_cfg.s.num_iqueues = num_iqueues;
if_cfg.s.num_oqueues = num_oqueues;
if_cfg.s.base_queue = base_queue;
if_cfg.s.gmx_port_id = gmx_port_id;
sc->iq_no = 0;
octeon_prepare_soft_command(octeon_dev, sc, OPCODE_NIC,
OPCODE_NIC_IF_CFG, 0,
if_cfg.u64, 0);
sc->callback = if_cfg_callback;
sc->callback_arg = sc;
sc->wait_time = 3000;
retval = octeon_send_soft_command(octeon_dev, sc);
if (retval == IQ_SEND_FAILED) {
dev_err(&octeon_dev->pci_dev->dev,
"iq/oq config failed status: %x\n",
retval);
goto setup_nic_dev_fail;
}
if (sleep_cond(&ctx->wc, &ctx->cond) == -EINTR) {
dev_err(&octeon_dev->pci_dev->dev, "Wait interrupted\n");
goto setup_nic_wait_intr;
}
retval = resp->status;
if (retval) {
dev_err(&octeon_dev->pci_dev->dev, "iq/oq config failed\n");
goto setup_nic_dev_fail;
}
octeon_swap_8B_data((u64 *)(&resp->cfg_info),
(sizeof(struct liquidio_if_cfg_info)) >> 3);
num_iqueues = hweight64(resp->cfg_info.iqmask);
num_oqueues = hweight64(resp->cfg_info.oqmask);
if (!(num_iqueues) || !(num_oqueues)) {
dev_err(&octeon_dev->pci_dev->dev,
"Got bad iqueues (%016llx) or oqueues (%016llx) from firmware.\n",
resp->cfg_info.iqmask,
resp->cfg_info.oqmask);
goto setup_nic_dev_fail;
}
dev_dbg(&octeon_dev->pci_dev->dev,
"interface %d, iqmask %016llx, oqmask %016llx, numiqueues %d, numoqueues %d\n",
i, resp->cfg_info.iqmask, resp->cfg_info.oqmask,
num_iqueues, num_oqueues);
netdev = alloc_etherdev_mq(LIO_SIZE, num_iqueues);
if (!netdev) {
dev_err(&octeon_dev->pci_dev->dev, "Device allocation failed\n");
goto setup_nic_dev_fail;
}
SET_NETDEV_DEV(netdev, &octeon_dev->pci_dev->dev);
netdev->netdev_ops = &lionetdevops;
lio = GET_LIO(netdev);
memset(lio, 0, sizeof(struct lio));
lio->ifidx = ifidx_or_pfnum;
props = &octeon_dev->props[i];
props->gmxport = resp->cfg_info.linfo.gmxport;
props->netdev = netdev;
lio->linfo.num_rxpciq = num_oqueues;
lio->linfo.num_txpciq = num_iqueues;
for (j = 0; j < num_oqueues; j++) {
lio->linfo.rxpciq[j].u64 =
resp->cfg_info.linfo.rxpciq[j].u64;
}
for (j = 0; j < num_iqueues; j++) {
lio->linfo.txpciq[j].u64 =
resp->cfg_info.linfo.txpciq[j].u64;
}
lio->linfo.hw_addr = resp->cfg_info.linfo.hw_addr;
lio->linfo.gmxport = resp->cfg_info.linfo.gmxport;
lio->linfo.link.u64 = resp->cfg_info.linfo.link.u64;
lio->msg_enable = netif_msg_init(debug, DEFAULT_MSG_ENABLE);
if (OCTEON_CN23XX_PF(octeon_dev) ||
OCTEON_CN6XXX(octeon_dev)) {
lio->dev_capability = NETIF_F_HIGHDMA
| NETIF_F_IP_CSUM
| NETIF_F_IPV6_CSUM
| NETIF_F_SG | NETIF_F_RXCSUM
| NETIF_F_GRO
| NETIF_F_TSO | NETIF_F_TSO6
| NETIF_F_LRO;
}
netif_set_gso_max_size(netdev, OCTNIC_GSO_MAX_SIZE);
lio->enc_dev_capability = NETIF_F_IP_CSUM
| NETIF_F_IPV6_CSUM
| NETIF_F_GSO_UDP_TUNNEL
| NETIF_F_HW_CSUM | NETIF_F_SG
| NETIF_F_RXCSUM
| NETIF_F_TSO | NETIF_F_TSO6
| NETIF_F_LRO;
netdev->hw_enc_features = (lio->enc_dev_capability &
~NETIF_F_LRO);
lio->dev_capability |= NETIF_F_GSO_UDP_TUNNEL;
netdev->vlan_features = lio->dev_capability;
lio->dev_capability |= NETIF_F_HW_VLAN_CTAG_FILTER |
NETIF_F_HW_VLAN_CTAG_RX |
NETIF_F_HW_VLAN_CTAG_TX;
netdev->features = (lio->dev_capability & ~NETIF_F_LRO);
netdev->hw_features = lio->dev_capability;
netdev->hw_features = netdev->hw_features &
~NETIF_F_HW_VLAN_CTAG_RX;
netdev->min_mtu = LIO_MIN_MTU_SIZE;
netdev->max_mtu = LIO_MAX_MTU_SIZE;
lio->oct_dev = octeon_dev;
lio->octprops = props;
lio->netdev = netdev;
dev_dbg(&octeon_dev->pci_dev->dev,
"if%d gmx: %d hw_addr: 0x%llx\n", i,
lio->linfo.gmxport, CVM_CAST64(lio->linfo.hw_addr));
for (j = 0; j < octeon_dev->sriov_info.max_vfs; j++) {
u8 vfmac[ETH_ALEN];
random_ether_addr(&vfmac[0]);
if (__liquidio_set_vf_mac(netdev, j,
&vfmac[0], false)) {
dev_err(&octeon_dev->pci_dev->dev,
"Error setting VF%d MAC address\n",
j);
goto setup_nic_dev_fail;
}
}
octeon_swap_8B_data(&lio->linfo.hw_addr, 1);
for (j = 0; j < 6; j++)
mac[j] = *((u8 *)(((u8 *)&lio->linfo.hw_addr) + 2 + j));
ether_addr_copy(netdev->dev_addr, mac);
lio->txq = lio->linfo.txpciq[0].s.q_no;
lio->rxq = lio->linfo.rxpciq[0].s.q_no;
if (setup_io_queues(octeon_dev, i)) {
dev_err(&octeon_dev->pci_dev->dev, "I/O queues creation failed\n");
goto setup_nic_dev_fail;
}
ifstate_set(lio, LIO_IFSTATE_DROQ_OPS);
lio->tx_qsize = octeon_get_tx_qsize(octeon_dev, lio->txq);
lio->rx_qsize = octeon_get_rx_qsize(octeon_dev, lio->rxq);
if (setup_glists(octeon_dev, lio, num_iqueues)) {
dev_err(&octeon_dev->pci_dev->dev,
"Gather list allocation failed\n");
goto setup_nic_dev_fail;
}
liquidio_set_ethtool_ops(netdev);
if (lio->oct_dev->chip_id == OCTEON_CN23XX_PF_VID)
octeon_dev->priv_flags = OCT_PRIV_FLAG_DEFAULT;
else
octeon_dev->priv_flags = 0x0;
if (netdev->features & NETIF_F_LRO)
liquidio_set_feature(netdev, OCTNET_CMD_LRO_ENABLE,
OCTNIC_LROIPV4 | OCTNIC_LROIPV6);
liquidio_set_feature(netdev, OCTNET_CMD_ENABLE_VLAN_FILTER, 0);
if ((debug != -1) && (debug & NETIF_MSG_HW))
liquidio_set_feature(netdev,
OCTNET_CMD_VERBOSE_ENABLE, 0);
if (setup_link_status_change_wq(netdev))
goto setup_nic_dev_fail;
if (register_netdev(netdev)) {
dev_err(&octeon_dev->pci_dev->dev, "Device registration failed\n");
goto setup_nic_dev_fail;
}
dev_dbg(&octeon_dev->pci_dev->dev,
"Setup NIC ifidx:%d mac:%02x%02x%02x%02x%02x%02x\n",
i, mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
netif_carrier_off(netdev);
lio->link_changes++;
ifstate_set(lio, LIO_IFSTATE_REGISTERED);
liquidio_set_rxcsum_command(netdev, OCTNET_CMD_TNL_RX_CSUM_CTL,
OCTNET_CMD_RXCSUM_ENABLE);
liquidio_set_feature(netdev, OCTNET_CMD_TNL_TX_CSUM_CTL,
OCTNET_CMD_TXCSUM_ENABLE);
dev_dbg(&octeon_dev->pci_dev->dev,
"NIC ifidx:%d Setup successful\n", i);
octeon_free_soft_command(octeon_dev, sc);
}
return 0;
setup_nic_dev_fail:
octeon_free_soft_command(octeon_dev, sc);
setup_nic_wait_intr:
while (i--) {
dev_err(&octeon_dev->pci_dev->dev,
"NIC ifidx:%d Setup failed\n", i);
liquidio_destroy_nic_device(octeon_dev, i);
}
return -ENODEV;
}
static int octeon_enable_sriov(struct octeon_device *oct)
{
unsigned int num_vfs_alloced = oct->sriov_info.num_vfs_alloced;
struct pci_dev *vfdev;
int err;
u32 u;
if (OCTEON_CN23XX_PF(oct) && num_vfs_alloced) {
err = pci_enable_sriov(oct->pci_dev,
oct->sriov_info.num_vfs_alloced);
if (err) {
dev_err(&oct->pci_dev->dev,
"OCTEON: Failed to enable PCI sriov: %d\n",
err);
oct->sriov_info.num_vfs_alloced = 0;
return err;
}
oct->sriov_info.sriov_enabled = 1;
u = 0;
vfdev = pci_get_device(PCI_VENDOR_ID_CAVIUM,
OCTEON_CN23XX_VF_VID, NULL);
while (vfdev) {
if (vfdev->is_virtfn &&
(vfdev->physfn == oct->pci_dev)) {
oct->sriov_info.dpiring_to_vfpcidev_lut[u] =
vfdev;
u += oct->sriov_info.rings_per_vf;
}
vfdev = pci_get_device(PCI_VENDOR_ID_CAVIUM,
OCTEON_CN23XX_VF_VID, vfdev);
}
}
return num_vfs_alloced;
}
static int lio_pci_sriov_disable(struct octeon_device *oct)
{
int u;
if (pci_vfs_assigned(oct->pci_dev)) {
dev_err(&oct->pci_dev->dev, "VFs are still assigned to VMs.\n");
return -EPERM;
}
pci_disable_sriov(oct->pci_dev);
u = 0;
while (u < MAX_POSSIBLE_VFS) {
oct->sriov_info.dpiring_to_vfpcidev_lut[u] = NULL;
u += oct->sriov_info.rings_per_vf;
}
oct->sriov_info.num_vfs_alloced = 0;
dev_info(&oct->pci_dev->dev, "oct->pf_num:%d disabled VFs\n",
oct->pf_num);
return 0;
}
static int liquidio_enable_sriov(struct pci_dev *dev, int num_vfs)
{
struct octeon_device *oct = pci_get_drvdata(dev);
int ret = 0;
if ((num_vfs == oct->sriov_info.num_vfs_alloced) &&
(oct->sriov_info.sriov_enabled)) {
dev_info(&oct->pci_dev->dev, "oct->pf_num:%d already enabled num_vfs:%d\n",
oct->pf_num, num_vfs);
return 0;
}
if (!num_vfs) {
ret = lio_pci_sriov_disable(oct);
} else if (num_vfs > oct->sriov_info.max_vfs) {
dev_err(&oct->pci_dev->dev,
"OCTEON: Max allowed VFs:%d user requested:%d",
oct->sriov_info.max_vfs, num_vfs);
ret = -EPERM;
} else {
oct->sriov_info.num_vfs_alloced = num_vfs;
ret = octeon_enable_sriov(oct);
dev_info(&oct->pci_dev->dev, "oct->pf_num:%d num_vfs:%d\n",
oct->pf_num, num_vfs);
}
return ret;
}
static int liquidio_init_nic_module(struct octeon_device *oct)
{
struct oct_intrmod_cfg *intrmod_cfg;
int i, retval = 0;
int num_nic_ports = CFG_GET_NUM_NIC_PORTS(octeon_get_conf(oct));
dev_dbg(&oct->pci_dev->dev, "Initializing network interfaces\n");
oct->ifcount = num_nic_ports;
memset(oct->props, 0, sizeof(struct octdev_props) * num_nic_ports);
for (i = 0; i < MAX_OCTEON_LINKS; i++)
oct->props[i].gmxport = -1;
retval = setup_nic_devices(oct);
if (retval) {
dev_err(&oct->pci_dev->dev, "Setup NIC devices failed\n");
goto octnet_init_failure;
}
liquidio_ptp_init(oct);
intrmod_cfg = &((struct octeon_device *)oct)->intrmod;
intrmod_cfg->rx_enable = 1;
intrmod_cfg->check_intrvl = LIO_INTRMOD_CHECK_INTERVAL;
intrmod_cfg->maxpkt_ratethr = LIO_INTRMOD_MAXPKT_RATETHR;
intrmod_cfg->minpkt_ratethr = LIO_INTRMOD_MINPKT_RATETHR;
intrmod_cfg->rx_maxcnt_trigger = LIO_INTRMOD_RXMAXCNT_TRIGGER;
intrmod_cfg->rx_maxtmr_trigger = LIO_INTRMOD_RXMAXTMR_TRIGGER;
intrmod_cfg->rx_mintmr_trigger = LIO_INTRMOD_RXMINTMR_TRIGGER;
intrmod_cfg->rx_mincnt_trigger = LIO_INTRMOD_RXMINCNT_TRIGGER;
intrmod_cfg->tx_enable = 1;
intrmod_cfg->tx_maxcnt_trigger = LIO_INTRMOD_TXMAXCNT_TRIGGER;
intrmod_cfg->tx_mincnt_trigger = LIO_INTRMOD_TXMINCNT_TRIGGER;
intrmod_cfg->rx_frames = CFG_GET_OQ_INTR_PKT(octeon_get_conf(oct));
intrmod_cfg->rx_usecs = CFG_GET_OQ_INTR_TIME(octeon_get_conf(oct));
intrmod_cfg->tx_frames = CFG_GET_IQ_INTR_PKT(octeon_get_conf(oct));
dev_dbg(&oct->pci_dev->dev, "Network interfaces ready\n");
return retval;
octnet_init_failure:
oct->ifcount = 0;
return retval;
}
static void nic_starter(struct work_struct *work)
{
struct octeon_device *oct;
struct cavium_wk *wk = (struct cavium_wk *)work;
oct = (struct octeon_device *)wk->ctxptr;
if (atomic_read(&oct->status) == OCT_DEV_RUNNING)
return;
if (atomic_read(&oct->status) != OCT_DEV_CORE_OK) {
schedule_delayed_work(&oct->nic_poll_work.work,
LIQUIDIO_STARTER_POLL_INTERVAL_MS);
return;
}
atomic_set(&oct->status, OCT_DEV_RUNNING);
if (oct->app_mode && oct->app_mode == CVM_DRV_NIC_APP) {
dev_dbg(&oct->pci_dev->dev, "Starting NIC module\n");
if (liquidio_init_nic_module(oct))
dev_err(&oct->pci_dev->dev, "NIC initialization failed\n");
else
handshake[oct->octeon_id].started_ok = 1;
} else {
dev_err(&oct->pci_dev->dev,
"Unexpected application running on NIC (%d). Check firmware.\n",
oct->app_mode);
}
complete(&handshake[oct->octeon_id].started);
}
static int
octeon_recv_vf_drv_notice(struct octeon_recv_info *recv_info, void *buf)
{
struct octeon_device *oct = (struct octeon_device *)buf;
struct octeon_recv_pkt *recv_pkt = recv_info->recv_pkt;
int i, notice, vf_idx;
u64 *data, vf_num;
notice = recv_pkt->rh.r.ossp;
data = (u64 *)get_rbd(recv_pkt->buffer_ptr[0]);
vf_num = data[0];
octeon_swap_8B_data(&vf_num, 1);
vf_idx = (int)vf_num - 1;
if (notice == VF_DRV_LOADED) {
if (!(oct->sriov_info.vf_drv_loaded_mask & BIT_ULL(vf_idx))) {
oct->sriov_info.vf_drv_loaded_mask |= BIT_ULL(vf_idx);
dev_info(&oct->pci_dev->dev,
"driver for VF%d was loaded\n", vf_idx);
try_module_get(THIS_MODULE);
}
} else if (notice == VF_DRV_REMOVED) {
if (oct->sriov_info.vf_drv_loaded_mask & BIT_ULL(vf_idx)) {
oct->sriov_info.vf_drv_loaded_mask &= ~BIT_ULL(vf_idx);
dev_info(&oct->pci_dev->dev,
"driver for VF%d was removed\n", vf_idx);
module_put(THIS_MODULE);
}
} else if (notice == VF_DRV_MACADDR_CHANGED) {
u8 *b = (u8 *)&data[1];
oct->sriov_info.vf_macaddr[vf_idx] = data[1];
dev_info(&oct->pci_dev->dev,
"VF driver changed VF%d's MAC address to %pM\n",
vf_idx, b + 2);
}
for (i = 0; i < recv_pkt->buffer_count; i++)
recv_buffer_free(recv_pkt->buffer_ptr[i]);
octeon_free_recv_info(recv_info);
return 0;
}
static int octeon_device_init(struct octeon_device *octeon_dev)
{
int j, ret;
int fw_loaded = 0;
char bootcmd[] = "\n";
struct octeon_device_priv *oct_priv =
(struct octeon_device_priv *)octeon_dev->priv;
atomic_set(&octeon_dev->status, OCT_DEV_BEGIN_STATE);
if (octeon_pci_os_setup(octeon_dev))
return 1;
atomic_set(&octeon_dev->status, OCT_DEV_PCI_ENABLE_DONE);
if (octeon_chip_specific_setup(octeon_dev)) {
dev_err(&octeon_dev->pci_dev->dev, "Chip specific setup failed\n");
return 1;
}
atomic_set(&octeon_dev->status, OCT_DEV_PCI_MAP_DONE);
octeon_dev->app_mode = CVM_DRV_INVALID_APP;
if (OCTEON_CN23XX_PF(octeon_dev)) {
if (!cn23xx_fw_loaded(octeon_dev)) {
fw_loaded = 0;
if (octeon_dev->fn_list.soft_reset(octeon_dev))
return 1;
if (!cn23xx_fw_loaded(octeon_dev))
fw_loaded = 0;
else
fw_loaded = 1;
} else {
fw_loaded = 1;
}
} else if (octeon_dev->fn_list.soft_reset(octeon_dev)) {
return 1;
}
if (octeon_init_dispatch_list(octeon_dev))
return 1;
octeon_register_dispatch_fn(octeon_dev, OPCODE_NIC,
OPCODE_NIC_CORE_DRV_ACTIVE,
octeon_core_drv_init,
octeon_dev);
octeon_register_dispatch_fn(octeon_dev, OPCODE_NIC,
OPCODE_NIC_VF_DRV_NOTICE,
octeon_recv_vf_drv_notice, octeon_dev);
INIT_DELAYED_WORK(&octeon_dev->nic_poll_work.work, nic_starter);
octeon_dev->nic_poll_work.ctxptr = (void *)octeon_dev;
schedule_delayed_work(&octeon_dev->nic_poll_work.work,
LIQUIDIO_STARTER_POLL_INTERVAL_MS);
atomic_set(&octeon_dev->status, OCT_DEV_DISPATCH_INIT_DONE);
if (octeon_set_io_queues_off(octeon_dev)) {
dev_err(&octeon_dev->pci_dev->dev, "setting io queues off failed\n");
return 1;
}
if (OCTEON_CN23XX_PF(octeon_dev)) {
ret = octeon_dev->fn_list.setup_device_regs(octeon_dev);
if (ret) {
dev_err(&octeon_dev->pci_dev->dev, "OCTEON: Failed to configure device registers\n");
return ret;
}
}
if (octeon_setup_sc_buffer_pool(octeon_dev)) {
dev_err(&octeon_dev->pci_dev->dev, "sc buffer pool allocation failed\n");
return 1;
}
atomic_set(&octeon_dev->status, OCT_DEV_SC_BUFF_POOL_INIT_DONE);
if (octeon_setup_instr_queues(octeon_dev)) {
dev_err(&octeon_dev->pci_dev->dev,
"instruction queue initialization failed\n");
return 1;
}
atomic_set(&octeon_dev->status, OCT_DEV_INSTR_QUEUE_INIT_DONE);
if (octeon_setup_response_list(octeon_dev)) {
dev_err(&octeon_dev->pci_dev->dev, "Response list allocation failed\n");
return 1;
}
atomic_set(&octeon_dev->status, OCT_DEV_RESP_LIST_INIT_DONE);
if (octeon_setup_output_queues(octeon_dev)) {
dev_err(&octeon_dev->pci_dev->dev, "Output queue initialization failed\n");
return 1;
}
atomic_set(&octeon_dev->status, OCT_DEV_DROQ_INIT_DONE);
if (OCTEON_CN23XX_PF(octeon_dev)) {
if (octeon_dev->fn_list.setup_mbox(octeon_dev)) {
dev_err(&octeon_dev->pci_dev->dev, "OCTEON: Mailbox setup failed\n");
return 1;
}
atomic_set(&octeon_dev->status, OCT_DEV_MBOX_SETUP_DONE);
if (octeon_allocate_ioq_vector(octeon_dev)) {
dev_err(&octeon_dev->pci_dev->dev, "OCTEON: ioq vector allocation failed\n");
return 1;
}
atomic_set(&octeon_dev->status, OCT_DEV_MSIX_ALLOC_VECTOR_DONE);
} else {
ret = octeon_dev->fn_list.setup_device_regs(octeon_dev);
if (ret) {
dev_err(&octeon_dev->pci_dev->dev,
"Failed to configure device registers\n");
return ret;
}
}
dev_dbg(&octeon_dev->pci_dev->dev, "Initializing droq tasklet\n");
tasklet_init(&oct_priv->droq_tasklet, octeon_droq_bh,
(unsigned long)octeon_dev);
if (octeon_setup_interrupt(octeon_dev))
return 1;
octeon_dev->fn_list.enable_interrupt(octeon_dev, OCTEON_ALL_INTR);
atomic_set(&octeon_dev->status, OCT_DEV_INTR_SET_DONE);
ret = octeon_dev->fn_list.enable_io_queues(octeon_dev);
if (ret) {
dev_err(&octeon_dev->pci_dev->dev, "Failed to enable input/output queues");
return ret;
}
atomic_set(&octeon_dev->status, OCT_DEV_IO_QUEUES_DONE);
if ((!OCTEON_CN23XX_PF(octeon_dev)) || !fw_loaded) {
dev_dbg(&octeon_dev->pci_dev->dev, "Waiting for DDR initialization...\n");
if (!ddr_timeout) {
dev_info(&octeon_dev->pci_dev->dev,
"WAITING. Set ddr_timeout to non-zero value to proceed with initialization.\n");
}
schedule_timeout_uninterruptible(HZ * LIO_RESET_SECS);
while (!ddr_timeout) {
set_current_state(TASK_INTERRUPTIBLE);
if (schedule_timeout(HZ / 10)) {
return 1;
}
}
ret = octeon_wait_for_ddr_init(octeon_dev, &ddr_timeout);
if (ret) {
dev_err(&octeon_dev->pci_dev->dev,
"DDR not initialized. Please confirm that board is configured to boot from Flash, ret: %d\n",
ret);
return 1;
}
if (octeon_wait_for_bootloader(octeon_dev, 1000)) {
dev_err(&octeon_dev->pci_dev->dev, "Board not responding\n");
return 1;
}
ret = octeon_console_send_cmd(octeon_dev, bootcmd, 50);
dev_dbg(&octeon_dev->pci_dev->dev, "Initializing consoles\n");
ret = octeon_init_consoles(octeon_dev);
if (ret) {
dev_err(&octeon_dev->pci_dev->dev, "Could not access board consoles\n");
return 1;
}
ret = octeon_add_console(octeon_dev, 0);
if (ret) {
dev_err(&octeon_dev->pci_dev->dev, "Could not access board console\n");
return 1;
}
atomic_set(&octeon_dev->status, OCT_DEV_CONSOLE_INIT_DONE);
dev_dbg(&octeon_dev->pci_dev->dev, "Loading firmware\n");
ret = load_firmware(octeon_dev);
if (ret) {
dev_err(&octeon_dev->pci_dev->dev, "Could not load firmware to board\n");
return 1;
}
if (OCTEON_CN23XX_PF(octeon_dev))
octeon_write_csr64(octeon_dev, CN23XX_SLI_SCRATCH1,
2ULL);
}
handshake[octeon_dev->octeon_id].init_ok = 1;
complete(&handshake[octeon_dev->octeon_id].init);
atomic_set(&octeon_dev->status, OCT_DEV_HOST_OK);
for (j = 0; j < octeon_dev->num_oqs; j++)
writel(octeon_dev->droq[j]->max_count,
octeon_dev->droq[j]->pkts_credit_reg);
return 0;
}
static void __exit liquidio_exit(void)
{
liquidio_deinit_pci();
pr_info("LiquidIO network module is now unloaded\n");
}
