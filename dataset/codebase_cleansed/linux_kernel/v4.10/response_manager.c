int octeon_setup_response_list(struct octeon_device *oct)
{
int i, ret = 0;
struct cavium_wq *cwq;
for (i = 0; i < MAX_RESPONSE_LISTS; i++) {
INIT_LIST_HEAD(&oct->response_list[i].head);
spin_lock_init(&oct->response_list[i].lock);
atomic_set(&oct->response_list[i].pending_req_count, 0);
}
spin_lock_init(&oct->cmd_resp_wqlock);
oct->dma_comp_wq.wq = alloc_workqueue("dma-comp", WQ_MEM_RECLAIM, 0);
if (!oct->dma_comp_wq.wq) {
dev_err(&oct->pci_dev->dev, "failed to create wq thread\n");
return -ENOMEM;
}
cwq = &oct->dma_comp_wq;
INIT_DELAYED_WORK(&cwq->wk.work, oct_poll_req_completion);
cwq->wk.ctxptr = oct;
oct->cmd_resp_state = OCT_DRV_ONLINE;
queue_delayed_work(cwq->wq, &cwq->wk.work, msecs_to_jiffies(50));
return ret;
}
void octeon_delete_response_list(struct octeon_device *oct)
{
cancel_delayed_work_sync(&oct->dma_comp_wq.wk.work);
destroy_workqueue(oct->dma_comp_wq.wq);
}
int lio_process_ordered_list(struct octeon_device *octeon_dev,
u32 force_quit)
{
struct octeon_response_list *ordered_sc_list;
struct octeon_soft_command *sc;
int request_complete = 0;
int resp_to_process = MAX_ORD_REQS_TO_PROCESS;
u32 status;
u64 status64;
struct octeon_instr_rdp *rdp;
u64 rptr;
ordered_sc_list = &octeon_dev->response_list[OCTEON_ORDERED_SC_LIST];
do {
spin_lock_bh(&ordered_sc_list->lock);
if (ordered_sc_list->head.next == &ordered_sc_list->head) {
spin_unlock_bh(&ordered_sc_list->lock);
return 1;
}
sc = (struct octeon_soft_command *)ordered_sc_list->
head.next;
if (OCTEON_CN23XX_PF(octeon_dev) ||
OCTEON_CN23XX_VF(octeon_dev)) {
rdp = (struct octeon_instr_rdp *)&sc->cmd.cmd3.rdp;
rptr = sc->cmd.cmd3.rptr;
} else {
rdp = (struct octeon_instr_rdp *)&sc->cmd.cmd2.rdp;
rptr = sc->cmd.cmd2.rptr;
}
status = OCTEON_REQUEST_PENDING;
dma_sync_single_for_cpu(&octeon_dev->pci_dev->dev,
rptr, rdp->rlen,
DMA_FROM_DEVICE);
status64 = *sc->status_word;
if (status64 != COMPLETION_WORD_INIT) {
if ((status64 & 0xff) != 0xff) {
octeon_swap_8B_data(&status64, 1);
if (((status64 & 0xff) != 0xff)) {
status = (u32)(status64 &
0xffffffffULL);
}
}
} else if (force_quit || (sc->timeout &&
time_after(jiffies, (unsigned long)sc->timeout))) {
status = OCTEON_REQUEST_TIMEOUT;
}
if (status != OCTEON_REQUEST_PENDING) {
list_del(&sc->node);
atomic_dec(&octeon_dev->response_list
[OCTEON_ORDERED_SC_LIST].
pending_req_count);
spin_unlock_bh
(&ordered_sc_list->lock);
if (sc->callback)
sc->callback(octeon_dev, status,
sc->callback_arg);
request_complete++;
} else {
request_complete = 0;
spin_unlock_bh
(&ordered_sc_list->lock);
}
if (request_complete >= resp_to_process)
break;
} while (request_complete);
return 0;
}
static void oct_poll_req_completion(struct work_struct *work)
{
struct cavium_wk *wk = (struct cavium_wk *)work;
struct octeon_device *oct = (struct octeon_device *)wk->ctxptr;
struct cavium_wq *cwq = &oct->dma_comp_wq;
lio_process_ordered_list(oct, 0);
queue_delayed_work(cwq->wq, &cwq->wk.work, msecs_to_jiffies(50));
}
