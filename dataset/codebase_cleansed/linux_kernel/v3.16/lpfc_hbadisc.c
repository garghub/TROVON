void
lpfc_terminate_rport_io(struct fc_rport *rport)
{
struct lpfc_rport_data *rdata;
struct lpfc_nodelist * ndlp;
struct lpfc_hba *phba;
rdata = rport->dd_data;
ndlp = rdata->pnode;
if (!ndlp || !NLP_CHK_NODE_ACT(ndlp)) {
if (rport->roles & FC_RPORT_ROLE_FCP_TARGET)
printk(KERN_ERR "Cannot find remote node"
" to terminate I/O Data x%x\n",
rport->port_id);
return;
}
phba = ndlp->phba;
lpfc_debugfs_disc_trc(ndlp->vport, LPFC_DISC_TRC_RPORT,
"rport terminate: sid:x%x did:x%x flg:x%x",
ndlp->nlp_sid, ndlp->nlp_DID, ndlp->nlp_flag);
if (ndlp->nlp_sid != NLP_NO_SID) {
lpfc_sli_abort_iocb(ndlp->vport,
&phba->sli.ring[phba->sli.fcp_ring],
ndlp->nlp_sid, 0, LPFC_CTX_TGT);
}
}
void
lpfc_dev_loss_tmo_callbk(struct fc_rport *rport)
{
struct lpfc_rport_data *rdata;
struct lpfc_nodelist * ndlp;
struct lpfc_vport *vport;
struct lpfc_hba *phba;
struct lpfc_work_evt *evtp;
int put_node;
int put_rport;
rdata = rport->dd_data;
ndlp = rdata->pnode;
if (!ndlp || !NLP_CHK_NODE_ACT(ndlp))
return;
vport = ndlp->vport;
phba = vport->phba;
lpfc_debugfs_disc_trc(vport, LPFC_DISC_TRC_RPORT,
"rport devlosscb: sid:x%x did:x%x flg:x%x",
ndlp->nlp_sid, ndlp->nlp_DID, ndlp->nlp_flag);
lpfc_printf_vlog(ndlp->vport, KERN_INFO, LOG_NODE,
"3181 dev_loss_callbk x%06x, rport %p flg x%x\n",
ndlp->nlp_DID, ndlp->rport, ndlp->nlp_flag);
if (vport->load_flag & FC_UNLOADING) {
put_node = rdata->pnode != NULL;
put_rport = ndlp->rport != NULL;
rdata->pnode = NULL;
ndlp->rport = NULL;
if (put_node)
lpfc_nlp_put(ndlp);
if (put_rport)
put_device(&rport->dev);
return;
}
if (ndlp->nlp_state == NLP_STE_MAPPED_NODE)
return;
if (ndlp->nlp_type & NLP_FABRIC) {
if (rport->port_name != wwn_to_u64(ndlp->nlp_portname.u.wwn)) {
put_device(&rport->dev);
return;
}
}
evtp = &ndlp->dev_loss_evt;
if (!list_empty(&evtp->evt_listp))
return;
evtp->evt_arg1 = lpfc_nlp_get(ndlp);
spin_lock_irq(&phba->hbalock);
if (evtp->evt_arg1) {
evtp->evt = LPFC_EVT_DEV_LOSS;
list_add_tail(&evtp->evt_listp, &phba->work_list);
lpfc_worker_wake_up(phba);
}
spin_unlock_irq(&phba->hbalock);
return;
}
static int
lpfc_dev_loss_tmo_handler(struct lpfc_nodelist *ndlp)
{
struct lpfc_rport_data *rdata;
struct fc_rport *rport;
struct lpfc_vport *vport;
struct lpfc_hba *phba;
uint8_t *name;
int put_node;
int put_rport;
int warn_on = 0;
int fcf_inuse = 0;
rport = ndlp->rport;
if (!rport)
return fcf_inuse;
rdata = rport->dd_data;
name = (uint8_t *) &ndlp->nlp_portname;
vport = ndlp->vport;
phba = vport->phba;
if (phba->sli_rev == LPFC_SLI_REV4)
fcf_inuse = lpfc_fcf_inuse(phba);
lpfc_debugfs_disc_trc(vport, LPFC_DISC_TRC_RPORT,
"rport devlosstmo:did:x%x type:x%x id:x%x",
ndlp->nlp_DID, ndlp->nlp_type, rport->scsi_target_id);
lpfc_printf_vlog(ndlp->vport, KERN_INFO, LOG_NODE,
"3182 dev_loss_tmo_handler x%06x, rport %p flg x%x\n",
ndlp->nlp_DID, ndlp->rport, ndlp->nlp_flag);
if (vport->load_flag & FC_UNLOADING) {
if (ndlp->nlp_sid != NLP_NO_SID) {
lpfc_sli_abort_iocb(vport,
&phba->sli.ring[phba->sli.fcp_ring],
ndlp->nlp_sid, 0, LPFC_CTX_TGT);
}
put_node = rdata->pnode != NULL;
put_rport = ndlp->rport != NULL;
rdata->pnode = NULL;
ndlp->rport = NULL;
if (put_node)
lpfc_nlp_put(ndlp);
if (put_rport)
put_device(&rport->dev);
return fcf_inuse;
}
if (ndlp->nlp_state == NLP_STE_MAPPED_NODE) {
lpfc_printf_vlog(vport, KERN_INFO, LOG_DISCOVERY,
"0284 Devloss timeout Ignored on "
"WWPN %x:%x:%x:%x:%x:%x:%x:%x "
"NPort x%x\n",
*name, *(name+1), *(name+2), *(name+3),
*(name+4), *(name+5), *(name+6), *(name+7),
ndlp->nlp_DID);
return fcf_inuse;
}
if (ndlp->nlp_type & NLP_FABRIC) {
put_node = rdata->pnode != NULL;
put_rport = ndlp->rport != NULL;
rdata->pnode = NULL;
ndlp->rport = NULL;
if (put_node)
lpfc_nlp_put(ndlp);
if (put_rport)
put_device(&rport->dev);
return fcf_inuse;
}
if (ndlp->nlp_sid != NLP_NO_SID) {
warn_on = 1;
lpfc_sli_abort_iocb(vport, &phba->sli.ring[phba->sli.fcp_ring],
ndlp->nlp_sid, 0, LPFC_CTX_TGT);
}
if (warn_on) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_DISCOVERY,
"0203 Devloss timeout on "
"WWPN %02x:%02x:%02x:%02x:%02x:%02x:%02x:%02x "
"NPort x%06x Data: x%x x%x x%x\n",
*name, *(name+1), *(name+2), *(name+3),
*(name+4), *(name+5), *(name+6), *(name+7),
ndlp->nlp_DID, ndlp->nlp_flag,
ndlp->nlp_state, ndlp->nlp_rpi);
} else {
lpfc_printf_vlog(vport, KERN_INFO, LOG_DISCOVERY,
"0204 Devloss timeout on "
"WWPN %02x:%02x:%02x:%02x:%02x:%02x:%02x:%02x "
"NPort x%06x Data: x%x x%x x%x\n",
*name, *(name+1), *(name+2), *(name+3),
*(name+4), *(name+5), *(name+6), *(name+7),
ndlp->nlp_DID, ndlp->nlp_flag,
ndlp->nlp_state, ndlp->nlp_rpi);
}
put_node = rdata->pnode != NULL;
put_rport = ndlp->rport != NULL;
rdata->pnode = NULL;
ndlp->rport = NULL;
if (put_node)
lpfc_nlp_put(ndlp);
if (put_rport)
put_device(&rport->dev);
if (!(vport->load_flag & FC_UNLOADING) &&
!(ndlp->nlp_flag & NLP_DELAY_TMO) &&
!(ndlp->nlp_flag & NLP_NPR_2B_DISC) &&
(ndlp->nlp_state != NLP_STE_UNMAPPED_NODE) &&
(ndlp->nlp_state != NLP_STE_REG_LOGIN_ISSUE) &&
(ndlp->nlp_state != NLP_STE_PRLI_ISSUE))
lpfc_disc_state_machine(vport, ndlp, NULL, NLP_EVT_DEVICE_RM);
return fcf_inuse;
}
static void
lpfc_sli4_post_dev_loss_tmo_handler(struct lpfc_hba *phba, int fcf_inuse,
uint32_t nlp_did)
{
if (!fcf_inuse)
return;
if ((phba->hba_flag & HBA_FIP_SUPPORT) && !lpfc_fcf_inuse(phba)) {
spin_lock_irq(&phba->hbalock);
if (phba->fcf.fcf_flag & FCF_DISCOVERY) {
if (phba->hba_flag & HBA_DEVLOSS_TMO) {
spin_unlock_irq(&phba->hbalock);
return;
}
phba->hba_flag |= HBA_DEVLOSS_TMO;
lpfc_printf_log(phba, KERN_INFO, LOG_FIP,
"2847 Last remote node (x%x) using "
"FCF devloss tmo\n", nlp_did);
}
if (phba->fcf.fcf_flag & FCF_REDISC_PROG) {
spin_unlock_irq(&phba->hbalock);
lpfc_printf_log(phba, KERN_INFO, LOG_FIP,
"2868 Devloss tmo to FCF rediscovery "
"in progress\n");
return;
}
if (!(phba->hba_flag & (FCF_TS_INPROG | FCF_RR_INPROG))) {
spin_unlock_irq(&phba->hbalock);
lpfc_printf_log(phba, KERN_INFO, LOG_FIP,
"2869 Devloss tmo to idle FIP engine, "
"unreg in-use FCF and rescan.\n");
lpfc_unregister_fcf_rescan(phba);
return;
}
spin_unlock_irq(&phba->hbalock);
if (phba->hba_flag & FCF_TS_INPROG)
lpfc_printf_log(phba, KERN_INFO, LOG_FIP,
"2870 FCF table scan in progress\n");
if (phba->hba_flag & FCF_RR_INPROG)
lpfc_printf_log(phba, KERN_INFO, LOG_FIP,
"2871 FLOGI roundrobin FCF failover "
"in progress\n");
}
lpfc_unregister_unused_fcf(phba);
}
struct lpfc_fast_path_event *
lpfc_alloc_fast_evt(struct lpfc_hba *phba) {
struct lpfc_fast_path_event *ret;
if (atomic_read(&phba->fast_event_count) > LPFC_MAX_EVT_COUNT)
return NULL;
ret = kzalloc(sizeof(struct lpfc_fast_path_event),
GFP_ATOMIC);
if (ret) {
atomic_inc(&phba->fast_event_count);
INIT_LIST_HEAD(&ret->work_evt.evt_listp);
ret->work_evt.evt = LPFC_EVT_FASTPATH_MGMT_EVT;
}
return ret;
}
void
lpfc_free_fast_evt(struct lpfc_hba *phba,
struct lpfc_fast_path_event *evt) {
atomic_dec(&phba->fast_event_count);
kfree(evt);
}
static void
lpfc_send_fastpath_evt(struct lpfc_hba *phba,
struct lpfc_work_evt *evtp)
{
unsigned long evt_category, evt_sub_category;
struct lpfc_fast_path_event *fast_evt_data;
char *evt_data;
uint32_t evt_data_size;
struct Scsi_Host *shost;
fast_evt_data = container_of(evtp, struct lpfc_fast_path_event,
work_evt);
evt_category = (unsigned long) fast_evt_data->un.fabric_evt.event_type;
evt_sub_category = (unsigned long) fast_evt_data->un.
fabric_evt.subcategory;
shost = lpfc_shost_from_vport(fast_evt_data->vport);
if (evt_category == FC_REG_FABRIC_EVENT) {
if (evt_sub_category == LPFC_EVENT_FCPRDCHKERR) {
evt_data = (char *) &fast_evt_data->un.read_check_error;
evt_data_size = sizeof(fast_evt_data->un.
read_check_error);
} else if ((evt_sub_category == LPFC_EVENT_FABRIC_BUSY) ||
(evt_sub_category == LPFC_EVENT_PORT_BUSY)) {
evt_data = (char *) &fast_evt_data->un.fabric_evt;
evt_data_size = sizeof(fast_evt_data->un.fabric_evt);
} else {
lpfc_free_fast_evt(phba, fast_evt_data);
return;
}
} else if (evt_category == FC_REG_SCSI_EVENT) {
switch (evt_sub_category) {
case LPFC_EVENT_QFULL:
case LPFC_EVENT_DEVBSY:
evt_data = (char *) &fast_evt_data->un.scsi_evt;
evt_data_size = sizeof(fast_evt_data->un.scsi_evt);
break;
case LPFC_EVENT_CHECK_COND:
evt_data = (char *) &fast_evt_data->un.check_cond_evt;
evt_data_size = sizeof(fast_evt_data->un.
check_cond_evt);
break;
case LPFC_EVENT_VARQUEDEPTH:
evt_data = (char *) &fast_evt_data->un.queue_depth_evt;
evt_data_size = sizeof(fast_evt_data->un.
queue_depth_evt);
break;
default:
lpfc_free_fast_evt(phba, fast_evt_data);
return;
}
} else {
lpfc_free_fast_evt(phba, fast_evt_data);
return;
}
fc_host_post_vendor_event(shost,
fc_get_event_number(),
evt_data_size,
evt_data,
LPFC_NL_VENDOR_ID);
lpfc_free_fast_evt(phba, fast_evt_data);
return;
}
static void
lpfc_work_list_done(struct lpfc_hba *phba)
{
struct lpfc_work_evt *evtp = NULL;
struct lpfc_nodelist *ndlp;
int free_evt;
int fcf_inuse;
uint32_t nlp_did;
spin_lock_irq(&phba->hbalock);
while (!list_empty(&phba->work_list)) {
list_remove_head((&phba->work_list), evtp, typeof(*evtp),
evt_listp);
spin_unlock_irq(&phba->hbalock);
free_evt = 1;
switch (evtp->evt) {
case LPFC_EVT_ELS_RETRY:
ndlp = (struct lpfc_nodelist *) (evtp->evt_arg1);
lpfc_els_retry_delay_handler(ndlp);
free_evt = 0;
lpfc_nlp_put(ndlp);
break;
case LPFC_EVT_DEV_LOSS:
ndlp = (struct lpfc_nodelist *)(evtp->evt_arg1);
fcf_inuse = lpfc_dev_loss_tmo_handler(ndlp);
free_evt = 0;
nlp_did = ndlp->nlp_DID;
lpfc_nlp_put(ndlp);
if (phba->sli_rev == LPFC_SLI_REV4)
lpfc_sli4_post_dev_loss_tmo_handler(phba,
fcf_inuse,
nlp_did);
break;
case LPFC_EVT_ONLINE:
if (phba->link_state < LPFC_LINK_DOWN)
*(int *) (evtp->evt_arg1) = lpfc_online(phba);
else
*(int *) (evtp->evt_arg1) = 0;
complete((struct completion *)(evtp->evt_arg2));
break;
case LPFC_EVT_OFFLINE_PREP:
if (phba->link_state >= LPFC_LINK_DOWN)
lpfc_offline_prep(phba, LPFC_MBX_WAIT);
*(int *)(evtp->evt_arg1) = 0;
complete((struct completion *)(evtp->evt_arg2));
break;
case LPFC_EVT_OFFLINE:
lpfc_offline(phba);
lpfc_sli_brdrestart(phba);
*(int *)(evtp->evt_arg1) =
lpfc_sli_brdready(phba, HS_FFRDY | HS_MBRDY);
lpfc_unblock_mgmt_io(phba);
complete((struct completion *)(evtp->evt_arg2));
break;
case LPFC_EVT_WARM_START:
lpfc_offline(phba);
lpfc_reset_barrier(phba);
lpfc_sli_brdreset(phba);
lpfc_hba_down_post(phba);
*(int *)(evtp->evt_arg1) =
lpfc_sli_brdready(phba, HS_MBRDY);
lpfc_unblock_mgmt_io(phba);
complete((struct completion *)(evtp->evt_arg2));
break;
case LPFC_EVT_KILL:
lpfc_offline(phba);
*(int *)(evtp->evt_arg1)
= (phba->pport->stopped)
? 0 : lpfc_sli_brdkill(phba);
lpfc_unblock_mgmt_io(phba);
complete((struct completion *)(evtp->evt_arg2));
break;
case LPFC_EVT_FASTPATH_MGMT_EVT:
lpfc_send_fastpath_evt(phba, evtp);
free_evt = 0;
break;
case LPFC_EVT_RESET_HBA:
if (!(phba->pport->load_flag & FC_UNLOADING))
lpfc_reset_hba(phba);
break;
}
if (free_evt)
kfree(evtp);
spin_lock_irq(&phba->hbalock);
}
spin_unlock_irq(&phba->hbalock);
}
static void
lpfc_work_done(struct lpfc_hba *phba)
{
struct lpfc_sli_ring *pring;
uint32_t ha_copy, status, control, work_port_events;
struct lpfc_vport **vports;
struct lpfc_vport *vport;
int i;
spin_lock_irq(&phba->hbalock);
ha_copy = phba->work_ha;
phba->work_ha = 0;
spin_unlock_irq(&phba->hbalock);
if (phba->pci_dev_grp == LPFC_PCI_DEV_OC)
lpfc_sli4_post_async_mbox(phba);
if (ha_copy & HA_ERATT)
lpfc_handle_eratt(phba);
if (ha_copy & HA_MBATT)
lpfc_sli_handle_mb_event(phba);
if (ha_copy & HA_LATT)
lpfc_handle_latt(phba);
if (phba->pci_dev_grp == LPFC_PCI_DEV_OC) {
if (phba->hba_flag & HBA_RRQ_ACTIVE)
lpfc_handle_rrq_active(phba);
if (phba->hba_flag & FCP_XRI_ABORT_EVENT)
lpfc_sli4_fcp_xri_abort_event_proc(phba);
if (phba->hba_flag & ELS_XRI_ABORT_EVENT)
lpfc_sli4_els_xri_abort_event_proc(phba);
if (phba->hba_flag & ASYNC_EVENT)
lpfc_sli4_async_event_proc(phba);
if (phba->hba_flag & HBA_POST_RECEIVE_BUFFER) {
spin_lock_irq(&phba->hbalock);
phba->hba_flag &= ~HBA_POST_RECEIVE_BUFFER;
spin_unlock_irq(&phba->hbalock);
lpfc_sli_hbqbuf_add_hbqs(phba, LPFC_ELS_HBQ);
}
if (phba->fcf.fcf_flag & FCF_REDISC_EVT)
lpfc_sli4_fcf_redisc_event_proc(phba);
}
vports = lpfc_create_vport_work_array(phba);
if (vports != NULL)
for (i = 0; i <= phba->max_vports; i++) {
if (vports[i] == NULL && i == 0)
vport = phba->pport;
else
vport = vports[i];
if (vport == NULL)
break;
spin_lock_irq(&vport->work_port_lock);
work_port_events = vport->work_port_events;
vport->work_port_events &= ~work_port_events;
spin_unlock_irq(&vport->work_port_lock);
if (work_port_events & WORKER_DISC_TMO)
lpfc_disc_timeout_handler(vport);
if (work_port_events & WORKER_ELS_TMO)
lpfc_els_timeout_handler(vport);
if (work_port_events & WORKER_HB_TMO)
lpfc_hb_timeout_handler(phba);
if (work_port_events & WORKER_MBOX_TMO)
lpfc_mbox_timeout_handler(phba);
if (work_port_events & WORKER_FABRIC_BLOCK_TMO)
lpfc_unblock_fabric_iocbs(phba);
if (work_port_events & WORKER_FDMI_TMO)
lpfc_fdmi_timeout_handler(vport);
if (work_port_events & WORKER_RAMP_DOWN_QUEUE)
lpfc_ramp_down_queue_handler(phba);
if (work_port_events & WORKER_DELAYED_DISC_TMO)
lpfc_delayed_disc_timeout_handler(vport);
}
lpfc_destroy_vport_work_array(phba, vports);
pring = &phba->sli.ring[LPFC_ELS_RING];
status = (ha_copy & (HA_RXMASK << (4*LPFC_ELS_RING)));
status >>= (4*LPFC_ELS_RING);
if ((status & HA_RXMASK) ||
(pring->flag & LPFC_DEFERRED_RING_EVENT) ||
(phba->hba_flag & HBA_SP_QUEUE_EVT)) {
if (pring->flag & LPFC_STOP_IOCB_EVENT) {
pring->flag |= LPFC_DEFERRED_RING_EVENT;
set_bit(LPFC_DATA_READY, &phba->data_flags);
} else {
if (phba->link_state >= LPFC_LINK_UP) {
pring->flag &= ~LPFC_DEFERRED_RING_EVENT;
lpfc_sli_handle_slow_ring_event(phba, pring,
(status &
HA_RXMASK));
}
}
if ((phba->sli_rev == LPFC_SLI_REV4) &
(!list_empty(&pring->txq)))
lpfc_drain_txq(phba);
if (phba->sli_rev <= LPFC_SLI_REV3) {
spin_lock_irq(&phba->hbalock);
control = readl(phba->HCregaddr);
if (!(control & (HC_R0INT_ENA << LPFC_ELS_RING))) {
lpfc_debugfs_slow_ring_trc(phba,
"WRK Enable ring: cntl:x%x hacopy:x%x",
control, ha_copy, 0);
control |= (HC_R0INT_ENA << LPFC_ELS_RING);
writel(control, phba->HCregaddr);
readl(phba->HCregaddr);
} else {
lpfc_debugfs_slow_ring_trc(phba,
"WRK Ring ok: cntl:x%x hacopy:x%x",
control, ha_copy, 0);
}
spin_unlock_irq(&phba->hbalock);
}
}
lpfc_work_list_done(phba);
}
int
lpfc_do_work(void *p)
{
struct lpfc_hba *phba = p;
int rc;
set_user_nice(current, MIN_NICE);
current->flags |= PF_NOFREEZE;
phba->data_flags = 0;
while (!kthread_should_stop()) {
rc = wait_event_interruptible(phba->work_waitq,
(test_and_clear_bit(LPFC_DATA_READY,
&phba->data_flags)
|| kthread_should_stop()));
if (rc) {
lpfc_printf_log(phba, KERN_ERR, LOG_ELS,
"0433 Wakeup on signal: rc=x%x\n", rc);
break;
}
lpfc_work_done(phba);
}
phba->worker_thread = NULL;
lpfc_printf_log(phba, KERN_INFO, LOG_ELS,
"0432 Worker thread stopped.\n");
return 0;
}
int
lpfc_workq_post_event(struct lpfc_hba *phba, void *arg1, void *arg2,
uint32_t evt)
{
struct lpfc_work_evt *evtp;
unsigned long flags;
evtp = kmalloc(sizeof(struct lpfc_work_evt), GFP_ATOMIC);
if (!evtp)
return 0;
evtp->evt_arg1 = arg1;
evtp->evt_arg2 = arg2;
evtp->evt = evt;
spin_lock_irqsave(&phba->hbalock, flags);
list_add_tail(&evtp->evt_listp, &phba->work_list);
spin_unlock_irqrestore(&phba->hbalock, flags);
lpfc_worker_wake_up(phba);
return 1;
}
void
lpfc_cleanup_rpis(struct lpfc_vport *vport, int remove)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
struct lpfc_hba *phba = vport->phba;
struct lpfc_nodelist *ndlp, *next_ndlp;
int rc;
list_for_each_entry_safe(ndlp, next_ndlp, &vport->fc_nodes, nlp_listp) {
if (!NLP_CHK_NODE_ACT(ndlp))
continue;
if (ndlp->nlp_state == NLP_STE_UNUSED_NODE)
continue;
if ((phba->sli3_options & LPFC_SLI3_VPORT_TEARDOWN) ||
((vport->port_type == LPFC_NPIV_PORT) &&
(ndlp->nlp_DID == NameServer_DID)))
lpfc_unreg_rpi(vport, ndlp);
if ((phba->sli_rev < LPFC_SLI_REV4) &&
(!remove && ndlp->nlp_type & NLP_FABRIC))
continue;
rc = lpfc_disc_state_machine(vport, ndlp, NULL,
remove
? NLP_EVT_DEVICE_RM
: NLP_EVT_DEVICE_RECOVERY);
}
if (phba->sli3_options & LPFC_SLI3_VPORT_TEARDOWN) {
if (phba->sli_rev == LPFC_SLI_REV4)
lpfc_sli4_unreg_all_rpis(vport);
lpfc_mbx_unreg_vpi(vport);
spin_lock_irq(shost->host_lock);
vport->fc_flag |= FC_VPORT_NEEDS_REG_VPI;
spin_unlock_irq(shost->host_lock);
}
}
void
lpfc_port_link_failure(struct lpfc_vport *vport)
{
lpfc_vport_set_state(vport, FC_VPORT_LINKDOWN);
lpfc_cleanup_rcv_buffers(vport);
lpfc_els_flush_rscn(vport);
lpfc_els_flush_cmd(vport);
lpfc_cleanup_rpis(vport, 0);
lpfc_can_disctmo(vport);
}
void
lpfc_linkdown_port(struct lpfc_vport *vport)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
fc_host_post_event(shost, fc_get_event_number(), FCH_EVT_LINKDOWN, 0);
lpfc_debugfs_disc_trc(vport, LPFC_DISC_TRC_ELS_CMD,
"Link Down: state:x%x rtry:x%x flg:x%x",
vport->port_state, vport->fc_ns_retry, vport->fc_flag);
lpfc_port_link_failure(vport);
spin_lock_irq(shost->host_lock);
vport->fc_flag &= ~FC_DISC_DELAYED;
spin_unlock_irq(shost->host_lock);
del_timer_sync(&vport->delayed_disc_tmo);
}
int
lpfc_linkdown(struct lpfc_hba *phba)
{
struct lpfc_vport *vport = phba->pport;
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
struct lpfc_vport **vports;
LPFC_MBOXQ_t *mb;
int i;
if (phba->link_state == LPFC_LINK_DOWN)
return 0;
lpfc_scsi_dev_block(phba);
spin_lock_irq(&phba->hbalock);
phba->fcf.fcf_flag &= ~(FCF_AVAILABLE | FCF_SCAN_DONE);
spin_unlock_irq(&phba->hbalock);
if (phba->link_state > LPFC_LINK_DOWN) {
phba->link_state = LPFC_LINK_DOWN;
spin_lock_irq(shost->host_lock);
phba->pport->fc_flag &= ~FC_LBIT;
spin_unlock_irq(shost->host_lock);
}
vports = lpfc_create_vport_work_array(phba);
if (vports != NULL)
for (i = 0; i <= phba->max_vports && vports[i] != NULL; i++) {
lpfc_linkdown_port(vports[i]);
}
lpfc_destroy_vport_work_array(phba, vports);
mb = mempool_alloc(phba->mbox_mem_pool, GFP_KERNEL);
if (mb) {
lpfc_unreg_did(phba, 0xffff, LPFC_UNREG_ALL_DFLT_RPIS, mb);
mb->vport = vport;
mb->mbox_cmpl = lpfc_sli_def_mbox_cmpl;
if (lpfc_sli_issue_mbox(phba, mb, MBX_NOWAIT)
== MBX_NOT_FINISHED) {
mempool_free(mb, phba->mbox_mem_pool);
}
}
if (phba->pport->fc_flag & FC_PT2PT) {
phba->pport->fc_myDID = 0;
mb = mempool_alloc(phba->mbox_mem_pool, GFP_KERNEL);
if (mb) {
lpfc_config_link(phba, mb);
mb->mbox_cmpl = lpfc_sli_def_mbox_cmpl;
mb->vport = vport;
if (lpfc_sli_issue_mbox(phba, mb, MBX_NOWAIT)
== MBX_NOT_FINISHED) {
mempool_free(mb, phba->mbox_mem_pool);
}
}
spin_lock_irq(shost->host_lock);
phba->pport->fc_flag &= ~(FC_PT2PT | FC_PT2PT_PLOGI);
spin_unlock_irq(shost->host_lock);
}
return 0;
}
static void
lpfc_linkup_cleanup_nodes(struct lpfc_vport *vport)
{
struct lpfc_nodelist *ndlp;
list_for_each_entry(ndlp, &vport->fc_nodes, nlp_listp) {
if (!NLP_CHK_NODE_ACT(ndlp))
continue;
if (ndlp->nlp_state == NLP_STE_UNUSED_NODE)
continue;
if (ndlp->nlp_type & NLP_FABRIC) {
if (ndlp->nlp_DID != Fabric_DID)
lpfc_unreg_rpi(vport, ndlp);
lpfc_nlp_set_state(vport, ndlp, NLP_STE_NPR_NODE);
} else if (!(ndlp->nlp_flag & NLP_NPR_ADISC)) {
lpfc_unreg_rpi(vport, ndlp);
}
}
}
static void
lpfc_linkup_port(struct lpfc_vport *vport)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
struct lpfc_hba *phba = vport->phba;
if ((vport->load_flag & FC_UNLOADING) != 0)
return;
lpfc_debugfs_disc_trc(vport, LPFC_DISC_TRC_ELS_CMD,
"Link Up: top:x%x speed:x%x flg:x%x",
phba->fc_topology, phba->fc_linkspeed, phba->link_flag);
if (!(phba->sli3_options & LPFC_SLI3_NPIV_ENABLED) &&
(vport != phba->pport))
return;
fc_host_post_event(shost, fc_get_event_number(), FCH_EVT_LINKUP, 0);
spin_lock_irq(shost->host_lock);
vport->fc_flag &= ~(FC_PT2PT | FC_PT2PT_PLOGI | FC_ABORT_DISCOVERY |
FC_RSCN_MODE | FC_NLP_MORE | FC_RSCN_DISCOVERY);
vport->fc_flag |= FC_NDISC_ACTIVE;
vport->fc_ns_retry = 0;
spin_unlock_irq(shost->host_lock);
if (vport->fc_flag & FC_LBIT)
lpfc_linkup_cleanup_nodes(vport);
}
static int
lpfc_linkup(struct lpfc_hba *phba)
{
struct lpfc_vport **vports;
int i;
lpfc_cleanup_wt_rrqs(phba);
phba->link_state = LPFC_LINK_UP;
clear_bit(FABRIC_COMANDS_BLOCKED, &phba->bit_flags);
del_timer_sync(&phba->fabric_block_timer);
vports = lpfc_create_vport_work_array(phba);
if (vports != NULL)
for (i = 0; i <= phba->max_vports && vports[i] != NULL; i++)
lpfc_linkup_port(vports[i]);
lpfc_destroy_vport_work_array(phba, vports);
return 0;
}
static void
lpfc_mbx_cmpl_clear_la(struct lpfc_hba *phba, LPFC_MBOXQ_t *pmb)
{
struct lpfc_vport *vport = pmb->vport;
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
struct lpfc_sli *psli = &phba->sli;
MAILBOX_t *mb = &pmb->u.mb;
uint32_t control;
psli->ring[psli->extra_ring].flag &= ~LPFC_STOP_IOCB_EVENT;
psli->ring[psli->fcp_ring].flag &= ~LPFC_STOP_IOCB_EVENT;
psli->ring[psli->next_ring].flag &= ~LPFC_STOP_IOCB_EVENT;
if ((mb->mbxStatus) && (mb->mbxStatus != 0x1601)) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_MBOX,
"0320 CLEAR_LA mbxStatus error x%x hba "
"state x%x\n",
mb->mbxStatus, vport->port_state);
phba->link_state = LPFC_HBA_ERROR;
goto out;
}
if (vport->port_type == LPFC_PHYSICAL_PORT)
phba->link_state = LPFC_HBA_READY;
spin_lock_irq(&phba->hbalock);
psli->sli_flag |= LPFC_PROCESS_LA;
control = readl(phba->HCregaddr);
control |= HC_LAINT_ENA;
writel(control, phba->HCregaddr);
readl(phba->HCregaddr);
spin_unlock_irq(&phba->hbalock);
mempool_free(pmb, phba->mbox_mem_pool);
return;
out:
lpfc_printf_vlog(vport, KERN_INFO, LOG_DISCOVERY,
"0225 Device Discovery completes\n");
mempool_free(pmb, phba->mbox_mem_pool);
spin_lock_irq(shost->host_lock);
vport->fc_flag &= ~FC_ABORT_DISCOVERY;
spin_unlock_irq(shost->host_lock);
lpfc_can_disctmo(vport);
spin_lock_irq(&phba->hbalock);
psli->sli_flag |= LPFC_PROCESS_LA;
control = readl(phba->HCregaddr);
control |= HC_LAINT_ENA;
writel(control, phba->HCregaddr);
readl(phba->HCregaddr);
spin_unlock_irq(&phba->hbalock);
return;
}
static void
lpfc_mbx_cmpl_local_config_link(struct lpfc_hba *phba, LPFC_MBOXQ_t *pmb)
{
struct lpfc_vport *vport = pmb->vport;
if (pmb->u.mb.mbxStatus)
goto out;
mempool_free(pmb, phba->mbox_mem_pool);
if ((phba->sli_rev == LPFC_SLI_REV4) &&
!(phba->hba_flag & HBA_FCOE_MODE) &&
(phba->link_flag & LS_LOOPBACK_MODE))
return;
if (phba->fc_topology == LPFC_TOPOLOGY_LOOP &&
vport->fc_flag & FC_PUBLIC_LOOP &&
!(vport->fc_flag & FC_LBIT)) {
lpfc_set_disctmo(vport);
return;
}
if (vport->port_state != LPFC_FLOGI || vport->fc_flag & FC_PT2PT_PLOGI)
lpfc_initial_flogi(vport);
return;
out:
lpfc_printf_vlog(vport, KERN_ERR, LOG_MBOX,
"0306 CONFIG_LINK mbxStatus error x%x "
"HBA state x%x\n",
pmb->u.mb.mbxStatus, vport->port_state);
mempool_free(pmb, phba->mbox_mem_pool);
lpfc_linkdown(phba);
lpfc_printf_vlog(vport, KERN_ERR, LOG_DISCOVERY,
"0200 CONFIG_LINK bad hba state x%x\n",
vport->port_state);
lpfc_issue_clear_la(phba, vport);
return;
}
void
lpfc_sli4_clear_fcf_rr_bmask(struct lpfc_hba *phba)
{
struct lpfc_fcf_pri *fcf_pri;
struct lpfc_fcf_pri *next_fcf_pri;
memset(phba->fcf.fcf_rr_bmask, 0, sizeof(*phba->fcf.fcf_rr_bmask));
spin_lock_irq(&phba->hbalock);
list_for_each_entry_safe(fcf_pri, next_fcf_pri,
&phba->fcf.fcf_pri_list, list) {
list_del_init(&fcf_pri->list);
fcf_pri->fcf_rec.flag = 0;
}
spin_unlock_irq(&phba->hbalock);
}
static void
lpfc_mbx_cmpl_reg_fcfi(struct lpfc_hba *phba, LPFC_MBOXQ_t *mboxq)
{
struct lpfc_vport *vport = mboxq->vport;
if (mboxq->u.mb.mbxStatus) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_MBOX,
"2017 REG_FCFI mbxStatus error x%x "
"HBA state x%x\n",
mboxq->u.mb.mbxStatus, vport->port_state);
goto fail_out;
}
phba->fcf.fcfi = bf_get(lpfc_reg_fcfi_fcfi, &mboxq->u.mqe.un.reg_fcfi);
spin_lock_irq(&phba->hbalock);
phba->fcf.fcf_flag |= FCF_REGISTERED;
spin_unlock_irq(&phba->hbalock);
if ((!(phba->hba_flag & FCF_RR_INPROG)) &&
lpfc_check_pending_fcoe_event(phba, LPFC_UNREG_FCF))
goto fail_out;
spin_lock_irq(&phba->hbalock);
phba->fcf.fcf_flag |= (FCF_SCAN_DONE | FCF_IN_USE);
phba->hba_flag &= ~FCF_TS_INPROG;
if (vport->port_state != LPFC_FLOGI) {
phba->hba_flag |= FCF_RR_INPROG;
spin_unlock_irq(&phba->hbalock);
lpfc_issue_init_vfi(vport);
goto out;
}
spin_unlock_irq(&phba->hbalock);
goto out;
fail_out:
spin_lock_irq(&phba->hbalock);
phba->hba_flag &= ~FCF_RR_INPROG;
spin_unlock_irq(&phba->hbalock);
out:
mempool_free(mboxq, phba->mbox_mem_pool);
}
static uint32_t
lpfc_fab_name_match(uint8_t *fab_name, struct fcf_record *new_fcf_record)
{
if (fab_name[0] != bf_get(lpfc_fcf_record_fab_name_0, new_fcf_record))
return 0;
if (fab_name[1] != bf_get(lpfc_fcf_record_fab_name_1, new_fcf_record))
return 0;
if (fab_name[2] != bf_get(lpfc_fcf_record_fab_name_2, new_fcf_record))
return 0;
if (fab_name[3] != bf_get(lpfc_fcf_record_fab_name_3, new_fcf_record))
return 0;
if (fab_name[4] != bf_get(lpfc_fcf_record_fab_name_4, new_fcf_record))
return 0;
if (fab_name[5] != bf_get(lpfc_fcf_record_fab_name_5, new_fcf_record))
return 0;
if (fab_name[6] != bf_get(lpfc_fcf_record_fab_name_6, new_fcf_record))
return 0;
if (fab_name[7] != bf_get(lpfc_fcf_record_fab_name_7, new_fcf_record))
return 0;
return 1;
}
static uint32_t
lpfc_sw_name_match(uint8_t *sw_name, struct fcf_record *new_fcf_record)
{
if (sw_name[0] != bf_get(lpfc_fcf_record_switch_name_0, new_fcf_record))
return 0;
if (sw_name[1] != bf_get(lpfc_fcf_record_switch_name_1, new_fcf_record))
return 0;
if (sw_name[2] != bf_get(lpfc_fcf_record_switch_name_2, new_fcf_record))
return 0;
if (sw_name[3] != bf_get(lpfc_fcf_record_switch_name_3, new_fcf_record))
return 0;
if (sw_name[4] != bf_get(lpfc_fcf_record_switch_name_4, new_fcf_record))
return 0;
if (sw_name[5] != bf_get(lpfc_fcf_record_switch_name_5, new_fcf_record))
return 0;
if (sw_name[6] != bf_get(lpfc_fcf_record_switch_name_6, new_fcf_record))
return 0;
if (sw_name[7] != bf_get(lpfc_fcf_record_switch_name_7, new_fcf_record))
return 0;
return 1;
}
static uint32_t
lpfc_mac_addr_match(uint8_t *mac_addr, struct fcf_record *new_fcf_record)
{
if (mac_addr[0] != bf_get(lpfc_fcf_record_mac_0, new_fcf_record))
return 0;
if (mac_addr[1] != bf_get(lpfc_fcf_record_mac_1, new_fcf_record))
return 0;
if (mac_addr[2] != bf_get(lpfc_fcf_record_mac_2, new_fcf_record))
return 0;
if (mac_addr[3] != bf_get(lpfc_fcf_record_mac_3, new_fcf_record))
return 0;
if (mac_addr[4] != bf_get(lpfc_fcf_record_mac_4, new_fcf_record))
return 0;
if (mac_addr[5] != bf_get(lpfc_fcf_record_mac_5, new_fcf_record))
return 0;
return 1;
}
static bool
lpfc_vlan_id_match(uint16_t curr_vlan_id, uint16_t new_vlan_id)
{
return (curr_vlan_id == new_vlan_id);
}
static void
__lpfc_update_fcf_record_pri(struct lpfc_hba *phba, uint16_t fcf_index,
struct fcf_record *new_fcf_record
)
{
struct lpfc_fcf_pri *fcf_pri;
fcf_pri = &phba->fcf.fcf_pri[fcf_index];
fcf_pri->fcf_rec.fcf_index = fcf_index;
fcf_pri->fcf_rec.priority = new_fcf_record->fip_priority;
}
static void
lpfc_copy_fcf_record(struct lpfc_fcf_rec *fcf_rec,
struct fcf_record *new_fcf_record)
{
fcf_rec->fabric_name[0] =
bf_get(lpfc_fcf_record_fab_name_0, new_fcf_record);
fcf_rec->fabric_name[1] =
bf_get(lpfc_fcf_record_fab_name_1, new_fcf_record);
fcf_rec->fabric_name[2] =
bf_get(lpfc_fcf_record_fab_name_2, new_fcf_record);
fcf_rec->fabric_name[3] =
bf_get(lpfc_fcf_record_fab_name_3, new_fcf_record);
fcf_rec->fabric_name[4] =
bf_get(lpfc_fcf_record_fab_name_4, new_fcf_record);
fcf_rec->fabric_name[5] =
bf_get(lpfc_fcf_record_fab_name_5, new_fcf_record);
fcf_rec->fabric_name[6] =
bf_get(lpfc_fcf_record_fab_name_6, new_fcf_record);
fcf_rec->fabric_name[7] =
bf_get(lpfc_fcf_record_fab_name_7, new_fcf_record);
fcf_rec->mac_addr[0] = bf_get(lpfc_fcf_record_mac_0, new_fcf_record);
fcf_rec->mac_addr[1] = bf_get(lpfc_fcf_record_mac_1, new_fcf_record);
fcf_rec->mac_addr[2] = bf_get(lpfc_fcf_record_mac_2, new_fcf_record);
fcf_rec->mac_addr[3] = bf_get(lpfc_fcf_record_mac_3, new_fcf_record);
fcf_rec->mac_addr[4] = bf_get(lpfc_fcf_record_mac_4, new_fcf_record);
fcf_rec->mac_addr[5] = bf_get(lpfc_fcf_record_mac_5, new_fcf_record);
fcf_rec->fcf_indx = bf_get(lpfc_fcf_record_fcf_index, new_fcf_record);
fcf_rec->priority = new_fcf_record->fip_priority;
fcf_rec->switch_name[0] =
bf_get(lpfc_fcf_record_switch_name_0, new_fcf_record);
fcf_rec->switch_name[1] =
bf_get(lpfc_fcf_record_switch_name_1, new_fcf_record);
fcf_rec->switch_name[2] =
bf_get(lpfc_fcf_record_switch_name_2, new_fcf_record);
fcf_rec->switch_name[3] =
bf_get(lpfc_fcf_record_switch_name_3, new_fcf_record);
fcf_rec->switch_name[4] =
bf_get(lpfc_fcf_record_switch_name_4, new_fcf_record);
fcf_rec->switch_name[5] =
bf_get(lpfc_fcf_record_switch_name_5, new_fcf_record);
fcf_rec->switch_name[6] =
bf_get(lpfc_fcf_record_switch_name_6, new_fcf_record);
fcf_rec->switch_name[7] =
bf_get(lpfc_fcf_record_switch_name_7, new_fcf_record);
}
static void
__lpfc_update_fcf_record(struct lpfc_hba *phba, struct lpfc_fcf_rec *fcf_rec,
struct fcf_record *new_fcf_record, uint32_t addr_mode,
uint16_t vlan_id, uint32_t flag)
{
lpfc_copy_fcf_record(fcf_rec, new_fcf_record);
fcf_rec->addr_mode = addr_mode;
fcf_rec->vlan_id = vlan_id;
fcf_rec->flag |= (flag | RECORD_VALID);
__lpfc_update_fcf_record_pri(phba,
bf_get(lpfc_fcf_record_fcf_index, new_fcf_record),
new_fcf_record);
}
static void
lpfc_register_fcf(struct lpfc_hba *phba)
{
LPFC_MBOXQ_t *fcf_mbxq;
int rc;
spin_lock_irq(&phba->hbalock);
if (!(phba->fcf.fcf_flag & FCF_AVAILABLE)) {
phba->hba_flag &= ~(FCF_TS_INPROG | FCF_RR_INPROG);
spin_unlock_irq(&phba->hbalock);
return;
}
if (phba->fcf.fcf_flag & FCF_REGISTERED) {
phba->fcf.fcf_flag |= (FCF_SCAN_DONE | FCF_IN_USE);
phba->hba_flag &= ~FCF_TS_INPROG;
if (phba->pport->port_state != LPFC_FLOGI &&
phba->pport->fc_flag & FC_FABRIC) {
phba->hba_flag |= FCF_RR_INPROG;
spin_unlock_irq(&phba->hbalock);
lpfc_initial_flogi(phba->pport);
return;
}
spin_unlock_irq(&phba->hbalock);
return;
}
spin_unlock_irq(&phba->hbalock);
fcf_mbxq = mempool_alloc(phba->mbox_mem_pool, GFP_KERNEL);
if (!fcf_mbxq) {
spin_lock_irq(&phba->hbalock);
phba->hba_flag &= ~(FCF_TS_INPROG | FCF_RR_INPROG);
spin_unlock_irq(&phba->hbalock);
return;
}
lpfc_reg_fcfi(phba, fcf_mbxq);
fcf_mbxq->vport = phba->pport;
fcf_mbxq->mbox_cmpl = lpfc_mbx_cmpl_reg_fcfi;
rc = lpfc_sli_issue_mbox(phba, fcf_mbxq, MBX_NOWAIT);
if (rc == MBX_NOT_FINISHED) {
spin_lock_irq(&phba->hbalock);
phba->hba_flag &= ~(FCF_TS_INPROG | FCF_RR_INPROG);
spin_unlock_irq(&phba->hbalock);
mempool_free(fcf_mbxq, phba->mbox_mem_pool);
}
return;
}
static int
lpfc_match_fcf_conn_list(struct lpfc_hba *phba,
struct fcf_record *new_fcf_record,
uint32_t *boot_flag, uint32_t *addr_mode,
uint16_t *vlan_id)
{
struct lpfc_fcf_conn_entry *conn_entry;
int i, j, fcf_vlan_id = 0;
for (i = 0; i < 512; i++) {
if (new_fcf_record->vlan_bitmap[i]) {
fcf_vlan_id = i * 8;
j = 0;
while (!((new_fcf_record->vlan_bitmap[i] >> j) & 1)) {
j++;
fcf_vlan_id++;
}
break;
}
}
if (!bf_get(lpfc_fcf_record_fcf_avail, new_fcf_record) ||
!bf_get(lpfc_fcf_record_fcf_valid, new_fcf_record) ||
bf_get(lpfc_fcf_record_fcf_sol, new_fcf_record))
return 0;
if (!(phba->hba_flag & HBA_FIP_SUPPORT)) {
*boot_flag = 0;
*addr_mode = bf_get(lpfc_fcf_record_mac_addr_prov,
new_fcf_record);
if (phba->valid_vlan)
*vlan_id = phba->vlan_id;
else
*vlan_id = LPFC_FCOE_NULL_VID;
return 1;
}
if (list_empty(&phba->fcf_conn_rec_list)) {
*boot_flag = 0;
*addr_mode = bf_get(lpfc_fcf_record_mac_addr_prov,
new_fcf_record);
if (*addr_mode & LPFC_FCF_FPMA)
*addr_mode = LPFC_FCF_FPMA;
if (fcf_vlan_id)
*vlan_id = fcf_vlan_id;
else
*vlan_id = LPFC_FCOE_NULL_VID;
return 1;
}
list_for_each_entry(conn_entry,
&phba->fcf_conn_rec_list, list) {
if (!(conn_entry->conn_rec.flags & FCFCNCT_VALID))
continue;
if ((conn_entry->conn_rec.flags & FCFCNCT_FBNM_VALID) &&
!lpfc_fab_name_match(conn_entry->conn_rec.fabric_name,
new_fcf_record))
continue;
if ((conn_entry->conn_rec.flags & FCFCNCT_SWNM_VALID) &&
!lpfc_sw_name_match(conn_entry->conn_rec.switch_name,
new_fcf_record))
continue;
if (conn_entry->conn_rec.flags & FCFCNCT_VLAN_VALID) {
if (!(new_fcf_record->vlan_bitmap
[conn_entry->conn_rec.vlan_tag / 8] &
(1 << (conn_entry->conn_rec.vlan_tag % 8))))
continue;
}
if (!(bf_get(lpfc_fcf_record_mac_addr_prov, new_fcf_record)
& (LPFC_FCF_FPMA | LPFC_FCF_SPMA)))
continue;
if ((conn_entry->conn_rec.flags & FCFCNCT_AM_VALID) &&
!(conn_entry->conn_rec.flags & FCFCNCT_AM_PREFERRED)) {
if ((conn_entry->conn_rec.flags & FCFCNCT_AM_SPMA) &&
!(bf_get(lpfc_fcf_record_mac_addr_prov,
new_fcf_record) & LPFC_FCF_SPMA))
continue;
if (!(conn_entry->conn_rec.flags & FCFCNCT_AM_SPMA) &&
!(bf_get(lpfc_fcf_record_mac_addr_prov,
new_fcf_record) & LPFC_FCF_FPMA))
continue;
}
if (conn_entry->conn_rec.flags & FCFCNCT_BOOT)
*boot_flag = 1;
else
*boot_flag = 0;
*addr_mode = bf_get(lpfc_fcf_record_mac_addr_prov,
new_fcf_record);
if ((conn_entry->conn_rec.flags & FCFCNCT_AM_VALID) &&
(!(conn_entry->conn_rec.flags & FCFCNCT_AM_PREFERRED)))
*addr_mode = (conn_entry->conn_rec.flags &
FCFCNCT_AM_SPMA) ?
LPFC_FCF_SPMA : LPFC_FCF_FPMA;
else if ((conn_entry->conn_rec.flags & FCFCNCT_AM_VALID) &&
(conn_entry->conn_rec.flags & FCFCNCT_AM_PREFERRED) &&
(conn_entry->conn_rec.flags & FCFCNCT_AM_SPMA) &&
(*addr_mode & LPFC_FCF_SPMA))
*addr_mode = LPFC_FCF_SPMA;
else if ((conn_entry->conn_rec.flags & FCFCNCT_AM_VALID) &&
(conn_entry->conn_rec.flags & FCFCNCT_AM_PREFERRED) &&
!(conn_entry->conn_rec.flags & FCFCNCT_AM_SPMA) &&
(*addr_mode & LPFC_FCF_FPMA))
*addr_mode = LPFC_FCF_FPMA;
if (conn_entry->conn_rec.flags & FCFCNCT_VLAN_VALID)
*vlan_id = conn_entry->conn_rec.vlan_tag;
else if (fcf_vlan_id)
*vlan_id = fcf_vlan_id;
else
*vlan_id = LPFC_FCOE_NULL_VID;
return 1;
}
return 0;
}
int
lpfc_check_pending_fcoe_event(struct lpfc_hba *phba, uint8_t unreg_fcf)
{
if ((phba->link_state >= LPFC_LINK_UP) &&
(phba->fcoe_eventtag == phba->fcoe_eventtag_at_fcf_scan))
return 0;
lpfc_printf_log(phba, KERN_INFO, LOG_FIP,
"2768 Pending link or FCF event during current "
"handling of the previous event: link_state:x%x, "
"evt_tag_at_scan:x%x, evt_tag_current:x%x\n",
phba->link_state, phba->fcoe_eventtag_at_fcf_scan,
phba->fcoe_eventtag);
spin_lock_irq(&phba->hbalock);
phba->fcf.fcf_flag &= ~FCF_AVAILABLE;
spin_unlock_irq(&phba->hbalock);
if (phba->link_state >= LPFC_LINK_UP) {
lpfc_printf_log(phba, KERN_INFO, LOG_FIP | LOG_DISCOVERY,
"2780 Restart FCF table scan due to "
"pending FCF event:evt_tag_at_scan:x%x, "
"evt_tag_current:x%x\n",
phba->fcoe_eventtag_at_fcf_scan,
phba->fcoe_eventtag);
lpfc_sli4_fcf_scan_read_fcf_rec(phba, LPFC_FCOE_FCF_GET_FIRST);
} else {
lpfc_printf_log(phba, KERN_INFO, LOG_FIP | LOG_DISCOVERY,
"2833 Stop FCF discovery process due to link "
"state change (x%x)\n", phba->link_state);
spin_lock_irq(&phba->hbalock);
phba->hba_flag &= ~(FCF_TS_INPROG | FCF_RR_INPROG);
phba->fcf.fcf_flag &= ~(FCF_REDISC_FOV | FCF_DISCOVERY);
spin_unlock_irq(&phba->hbalock);
}
if (unreg_fcf) {
spin_lock_irq(&phba->hbalock);
phba->fcf.fcf_flag &= ~FCF_REGISTERED;
spin_unlock_irq(&phba->hbalock);
lpfc_sli4_unregister_fcf(phba);
}
return 1;
}
static bool
lpfc_sli4_new_fcf_random_select(struct lpfc_hba *phba, uint32_t fcf_cnt)
{
uint32_t rand_num;
rand_num = 0xFFFF & prandom_u32();
if ((fcf_cnt * rand_num) < 0xFFFF)
return true;
else
return false;
}
static struct fcf_record *
lpfc_sli4_fcf_rec_mbox_parse(struct lpfc_hba *phba, LPFC_MBOXQ_t *mboxq,
uint16_t *next_fcf_index)
{
void *virt_addr;
dma_addr_t phys_addr;
struct lpfc_mbx_sge sge;
struct lpfc_mbx_read_fcf_tbl *read_fcf;
uint32_t shdr_status, shdr_add_status;
union lpfc_sli4_cfg_shdr *shdr;
struct fcf_record *new_fcf_record;
lpfc_sli4_mbx_sge_get(mboxq, 0, &sge);
phys_addr = getPaddr(sge.pa_hi, sge.pa_lo);
if (unlikely(!mboxq->sge_array)) {
lpfc_printf_log(phba, KERN_ERR, LOG_MBOX,
"2524 Failed to get the non-embedded SGE "
"virtual address\n");
return NULL;
}
virt_addr = mboxq->sge_array->addr[0];
shdr = (union lpfc_sli4_cfg_shdr *)virt_addr;
lpfc_sli_pcimem_bcopy(shdr, shdr,
sizeof(union lpfc_sli4_cfg_shdr));
shdr_status = bf_get(lpfc_mbox_hdr_status, &shdr->response);
shdr_add_status = bf_get(lpfc_mbox_hdr_add_status, &shdr->response);
if (shdr_status || shdr_add_status) {
if (shdr_status == STATUS_FCF_TABLE_EMPTY)
lpfc_printf_log(phba, KERN_ERR, LOG_FIP,
"2726 READ_FCF_RECORD Indicates empty "
"FCF table.\n");
else
lpfc_printf_log(phba, KERN_ERR, LOG_FIP,
"2521 READ_FCF_RECORD mailbox failed "
"with status x%x add_status x%x, "
"mbx\n", shdr_status, shdr_add_status);
return NULL;
}
read_fcf = (struct lpfc_mbx_read_fcf_tbl *)virt_addr;
lpfc_sli_pcimem_bcopy(read_fcf, read_fcf,
sizeof(struct lpfc_mbx_read_fcf_tbl));
*next_fcf_index = bf_get(lpfc_mbx_read_fcf_tbl_nxt_vindx, read_fcf);
new_fcf_record = (struct fcf_record *)(virt_addr +
sizeof(struct lpfc_mbx_read_fcf_tbl));
lpfc_sli_pcimem_bcopy(new_fcf_record, new_fcf_record,
offsetof(struct fcf_record, vlan_bitmap));
new_fcf_record->word137 = le32_to_cpu(new_fcf_record->word137);
new_fcf_record->word138 = le32_to_cpu(new_fcf_record->word138);
return new_fcf_record;
}
static void
lpfc_sli4_log_fcf_record_info(struct lpfc_hba *phba,
struct fcf_record *fcf_record,
uint16_t vlan_id,
uint16_t next_fcf_index)
{
lpfc_printf_log(phba, KERN_INFO, LOG_FIP,
"2764 READ_FCF_RECORD:\n"
"\tFCF_Index : x%x\n"
"\tFCF_Avail : x%x\n"
"\tFCF_Valid : x%x\n"
"\tFCF_SOL : x%x\n"
"\tFIP_Priority : x%x\n"
"\tMAC_Provider : x%x\n"
"\tLowest VLANID : x%x\n"
"\tFCF_MAC Addr : x%x:%x:%x:%x:%x:%x\n"
"\tFabric_Name : x%x:%x:%x:%x:%x:%x:%x:%x\n"
"\tSwitch_Name : x%x:%x:%x:%x:%x:%x:%x:%x\n"
"\tNext_FCF_Index: x%x\n",
bf_get(lpfc_fcf_record_fcf_index, fcf_record),
bf_get(lpfc_fcf_record_fcf_avail, fcf_record),
bf_get(lpfc_fcf_record_fcf_valid, fcf_record),
bf_get(lpfc_fcf_record_fcf_sol, fcf_record),
fcf_record->fip_priority,
bf_get(lpfc_fcf_record_mac_addr_prov, fcf_record),
vlan_id,
bf_get(lpfc_fcf_record_mac_0, fcf_record),
bf_get(lpfc_fcf_record_mac_1, fcf_record),
bf_get(lpfc_fcf_record_mac_2, fcf_record),
bf_get(lpfc_fcf_record_mac_3, fcf_record),
bf_get(lpfc_fcf_record_mac_4, fcf_record),
bf_get(lpfc_fcf_record_mac_5, fcf_record),
bf_get(lpfc_fcf_record_fab_name_0, fcf_record),
bf_get(lpfc_fcf_record_fab_name_1, fcf_record),
bf_get(lpfc_fcf_record_fab_name_2, fcf_record),
bf_get(lpfc_fcf_record_fab_name_3, fcf_record),
bf_get(lpfc_fcf_record_fab_name_4, fcf_record),
bf_get(lpfc_fcf_record_fab_name_5, fcf_record),
bf_get(lpfc_fcf_record_fab_name_6, fcf_record),
bf_get(lpfc_fcf_record_fab_name_7, fcf_record),
bf_get(lpfc_fcf_record_switch_name_0, fcf_record),
bf_get(lpfc_fcf_record_switch_name_1, fcf_record),
bf_get(lpfc_fcf_record_switch_name_2, fcf_record),
bf_get(lpfc_fcf_record_switch_name_3, fcf_record),
bf_get(lpfc_fcf_record_switch_name_4, fcf_record),
bf_get(lpfc_fcf_record_switch_name_5, fcf_record),
bf_get(lpfc_fcf_record_switch_name_6, fcf_record),
bf_get(lpfc_fcf_record_switch_name_7, fcf_record),
next_fcf_index);
}
static bool
lpfc_sli4_fcf_record_match(struct lpfc_hba *phba,
struct lpfc_fcf_rec *fcf_rec,
struct fcf_record *new_fcf_record,
uint16_t new_vlan_id)
{
if (new_vlan_id != LPFC_FCOE_IGNORE_VID)
if (!lpfc_vlan_id_match(fcf_rec->vlan_id, new_vlan_id))
return false;
if (!lpfc_mac_addr_match(fcf_rec->mac_addr, new_fcf_record))
return false;
if (!lpfc_sw_name_match(fcf_rec->switch_name, new_fcf_record))
return false;
if (!lpfc_fab_name_match(fcf_rec->fabric_name, new_fcf_record))
return false;
if (fcf_rec->priority != new_fcf_record->fip_priority)
return false;
return true;
}
int lpfc_sli4_fcf_rr_next_proc(struct lpfc_vport *vport, uint16_t fcf_index)
{
struct lpfc_hba *phba = vport->phba;
int rc;
if (fcf_index == LPFC_FCOE_FCF_NEXT_NONE) {
spin_lock_irq(&phba->hbalock);
if (phba->hba_flag & HBA_DEVLOSS_TMO) {
spin_unlock_irq(&phba->hbalock);
lpfc_printf_log(phba, KERN_INFO, LOG_FIP,
"2872 Devloss tmo with no eligible "
"FCF, unregister in-use FCF (x%x) "
"and rescan FCF table\n",
phba->fcf.current_rec.fcf_indx);
lpfc_unregister_fcf_rescan(phba);
goto stop_flogi_current_fcf;
}
phba->hba_flag &= ~FCF_RR_INPROG;
phba->fcf.fcf_flag &= ~(FCF_AVAILABLE | FCF_SCAN_DONE);
spin_unlock_irq(&phba->hbalock);
lpfc_printf_log(phba, KERN_INFO, LOG_FIP,
"2865 No FCF available, stop roundrobin FCF "
"failover and change port state:x%x/x%x\n",
phba->pport->port_state, LPFC_VPORT_UNKNOWN);
phba->pport->port_state = LPFC_VPORT_UNKNOWN;
goto stop_flogi_current_fcf;
} else {
lpfc_printf_log(phba, KERN_INFO, LOG_FIP | LOG_ELS,
"2794 Try FLOGI roundrobin FCF failover to "
"(x%x)\n", fcf_index);
rc = lpfc_sli4_fcf_rr_read_fcf_rec(phba, fcf_index);
if (rc)
lpfc_printf_log(phba, KERN_WARNING, LOG_FIP | LOG_ELS,
"2761 FLOGI roundrobin FCF failover "
"failed (rc:x%x) to read FCF (x%x)\n",
rc, phba->fcf.current_rec.fcf_indx);
else
goto stop_flogi_current_fcf;
}
return 0;
stop_flogi_current_fcf:
lpfc_can_disctmo(vport);
return 1;
}
static void lpfc_sli4_fcf_pri_list_del(struct lpfc_hba *phba,
uint16_t fcf_index)
{
struct lpfc_fcf_pri *new_fcf_pri;
new_fcf_pri = &phba->fcf.fcf_pri[fcf_index];
lpfc_printf_log(phba, KERN_INFO, LOG_FIP,
"3058 deleting idx x%x pri x%x flg x%x\n",
fcf_index, new_fcf_pri->fcf_rec.priority,
new_fcf_pri->fcf_rec.flag);
spin_lock_irq(&phba->hbalock);
if (new_fcf_pri->fcf_rec.flag & LPFC_FCF_ON_PRI_LIST) {
if (phba->fcf.current_rec.priority ==
new_fcf_pri->fcf_rec.priority)
phba->fcf.eligible_fcf_cnt--;
list_del_init(&new_fcf_pri->list);
new_fcf_pri->fcf_rec.flag &= ~LPFC_FCF_ON_PRI_LIST;
}
spin_unlock_irq(&phba->hbalock);
}
void
lpfc_sli4_set_fcf_flogi_fail(struct lpfc_hba *phba, uint16_t fcf_index)
{
struct lpfc_fcf_pri *new_fcf_pri;
new_fcf_pri = &phba->fcf.fcf_pri[fcf_index];
spin_lock_irq(&phba->hbalock);
new_fcf_pri->fcf_rec.flag |= LPFC_FCF_FLOGI_FAILED;
spin_unlock_irq(&phba->hbalock);
}
int lpfc_sli4_fcf_pri_list_add(struct lpfc_hba *phba, uint16_t fcf_index,
struct fcf_record *new_fcf_record)
{
uint16_t current_fcf_pri;
uint16_t last_index;
struct lpfc_fcf_pri *fcf_pri;
struct lpfc_fcf_pri *next_fcf_pri;
struct lpfc_fcf_pri *new_fcf_pri;
int ret;
new_fcf_pri = &phba->fcf.fcf_pri[fcf_index];
lpfc_printf_log(phba, KERN_INFO, LOG_FIP,
"3059 adding idx x%x pri x%x flg x%x\n",
fcf_index, new_fcf_record->fip_priority,
new_fcf_pri->fcf_rec.flag);
spin_lock_irq(&phba->hbalock);
if (new_fcf_pri->fcf_rec.flag & LPFC_FCF_ON_PRI_LIST)
list_del_init(&new_fcf_pri->list);
new_fcf_pri->fcf_rec.fcf_index = fcf_index;
new_fcf_pri->fcf_rec.priority = new_fcf_record->fip_priority;
if (list_empty(&phba->fcf.fcf_pri_list)) {
list_add(&new_fcf_pri->list, &phba->fcf.fcf_pri_list);
ret = lpfc_sli4_fcf_rr_index_set(phba,
new_fcf_pri->fcf_rec.fcf_index);
goto out;
}
last_index = find_first_bit(phba->fcf.fcf_rr_bmask,
LPFC_SLI4_FCF_TBL_INDX_MAX);
if (last_index >= LPFC_SLI4_FCF_TBL_INDX_MAX) {
ret = 0;
goto out;
}
current_fcf_pri = phba->fcf.fcf_pri[last_index].fcf_rec.priority;
if (new_fcf_pri->fcf_rec.priority <= current_fcf_pri) {
list_add(&new_fcf_pri->list, &phba->fcf.fcf_pri_list);
if (new_fcf_pri->fcf_rec.priority < current_fcf_pri) {
memset(phba->fcf.fcf_rr_bmask, 0,
sizeof(*phba->fcf.fcf_rr_bmask));
phba->fcf.eligible_fcf_cnt = 1;
} else
phba->fcf.eligible_fcf_cnt++;
ret = lpfc_sli4_fcf_rr_index_set(phba,
new_fcf_pri->fcf_rec.fcf_index);
goto out;
}
list_for_each_entry_safe(fcf_pri, next_fcf_pri,
&phba->fcf.fcf_pri_list, list) {
if (new_fcf_pri->fcf_rec.priority <=
fcf_pri->fcf_rec.priority) {
if (fcf_pri->list.prev == &phba->fcf.fcf_pri_list)
list_add(&new_fcf_pri->list,
&phba->fcf.fcf_pri_list);
else
list_add(&new_fcf_pri->list,
&((struct lpfc_fcf_pri *)
fcf_pri->list.prev)->list);
ret = 0;
goto out;
} else if (fcf_pri->list.next == &phba->fcf.fcf_pri_list
|| new_fcf_pri->fcf_rec.priority <
next_fcf_pri->fcf_rec.priority) {
list_add(&new_fcf_pri->list, &fcf_pri->list);
ret = 0;
goto out;
}
if (new_fcf_pri->fcf_rec.priority > fcf_pri->fcf_rec.priority)
continue;
}
ret = 1;
out:
new_fcf_pri->fcf_rec.flag = LPFC_FCF_ON_PRI_LIST;
spin_unlock_irq(&phba->hbalock);
return ret;
}
void
lpfc_mbx_cmpl_fcf_scan_read_fcf_rec(struct lpfc_hba *phba, LPFC_MBOXQ_t *mboxq)
{
struct fcf_record *new_fcf_record;
uint32_t boot_flag, addr_mode;
uint16_t fcf_index, next_fcf_index;
struct lpfc_fcf_rec *fcf_rec = NULL;
uint16_t vlan_id;
uint32_t seed;
bool select_new_fcf;
int rc;
if (lpfc_check_pending_fcoe_event(phba, LPFC_SKIP_UNREG_FCF)) {
lpfc_sli4_mbox_cmd_free(phba, mboxq);
return;
}
new_fcf_record = lpfc_sli4_fcf_rec_mbox_parse(phba, mboxq,
&next_fcf_index);
if (!new_fcf_record) {
lpfc_printf_log(phba, KERN_ERR, LOG_FIP,
"2765 Mailbox command READ_FCF_RECORD "
"failed to retrieve a FCF record.\n");
spin_lock_irq(&phba->hbalock);
phba->hba_flag &= ~FCF_TS_INPROG;
spin_unlock_irq(&phba->hbalock);
lpfc_sli4_mbox_cmd_free(phba, mboxq);
return;
}
rc = lpfc_match_fcf_conn_list(phba, new_fcf_record, &boot_flag,
&addr_mode, &vlan_id);
lpfc_sli4_log_fcf_record_info(phba, new_fcf_record, vlan_id,
next_fcf_index);
if (!rc) {
lpfc_sli4_fcf_pri_list_del(phba,
bf_get(lpfc_fcf_record_fcf_index,
new_fcf_record));
lpfc_printf_log(phba, KERN_WARNING, LOG_FIP,
"2781 FCF (x%x) failed connection "
"list check: (x%x/x%x/%x)\n",
bf_get(lpfc_fcf_record_fcf_index,
new_fcf_record),
bf_get(lpfc_fcf_record_fcf_avail,
new_fcf_record),
bf_get(lpfc_fcf_record_fcf_valid,
new_fcf_record),
bf_get(lpfc_fcf_record_fcf_sol,
new_fcf_record));
if ((phba->fcf.fcf_flag & FCF_IN_USE) &&
lpfc_sli4_fcf_record_match(phba, &phba->fcf.current_rec,
new_fcf_record, LPFC_FCOE_IGNORE_VID)) {
if (bf_get(lpfc_fcf_record_fcf_index, new_fcf_record) !=
phba->fcf.current_rec.fcf_indx) {
lpfc_printf_log(phba, KERN_ERR, LOG_FIP,
"2862 FCF (x%x) matches property "
"of in-use FCF (x%x)\n",
bf_get(lpfc_fcf_record_fcf_index,
new_fcf_record),
phba->fcf.current_rec.fcf_indx);
goto read_next_fcf;
}
if (!(phba->fcf.fcf_flag & FCF_REDISC_PEND) &&
!(phba->fcf.fcf_flag & FCF_REDISC_FOV)) {
lpfc_printf_log(phba, KERN_WARNING, LOG_FIP,
"2835 Invalid in-use FCF "
"(x%x), enter FCF failover "
"table scan.\n",
phba->fcf.current_rec.fcf_indx);
spin_lock_irq(&phba->hbalock);
phba->fcf.fcf_flag |= FCF_REDISC_FOV;
spin_unlock_irq(&phba->hbalock);
lpfc_sli4_mbox_cmd_free(phba, mboxq);
lpfc_sli4_fcf_scan_read_fcf_rec(phba,
LPFC_FCOE_FCF_GET_FIRST);
return;
}
}
goto read_next_fcf;
} else {
fcf_index = bf_get(lpfc_fcf_record_fcf_index, new_fcf_record);
rc = lpfc_sli4_fcf_pri_list_add(phba, fcf_index,
new_fcf_record);
if (rc)
goto read_next_fcf;
}
spin_lock_irq(&phba->hbalock);
if (phba->fcf.fcf_flag & FCF_IN_USE) {
if (phba->cfg_fcf_failover_policy == LPFC_FCF_FOV &&
lpfc_sli4_fcf_record_match(phba, &phba->fcf.current_rec,
new_fcf_record, vlan_id)) {
if (bf_get(lpfc_fcf_record_fcf_index, new_fcf_record) ==
phba->fcf.current_rec.fcf_indx) {
phba->fcf.fcf_flag |= FCF_AVAILABLE;
if (phba->fcf.fcf_flag & FCF_REDISC_PEND)
__lpfc_sli4_stop_fcf_redisc_wait_timer(
phba);
else if (phba->fcf.fcf_flag & FCF_REDISC_FOV)
phba->fcf.fcf_flag &= ~FCF_REDISC_FOV;
spin_unlock_irq(&phba->hbalock);
lpfc_printf_log(phba, KERN_INFO, LOG_FIP,
"2836 New FCF matches in-use "
"FCF (x%x), port_state:x%x, "
"fc_flag:x%x\n",
phba->fcf.current_rec.fcf_indx,
phba->pport->port_state,
phba->pport->fc_flag);
goto out;
} else
lpfc_printf_log(phba, KERN_ERR, LOG_FIP,
"2863 New FCF (x%x) matches "
"property of in-use FCF (x%x)\n",
bf_get(lpfc_fcf_record_fcf_index,
new_fcf_record),
phba->fcf.current_rec.fcf_indx);
}
if (!(phba->fcf.fcf_flag & FCF_REDISC_FOV)) {
spin_unlock_irq(&phba->hbalock);
goto read_next_fcf;
}
}
if (phba->fcf.fcf_flag & FCF_REDISC_FOV)
fcf_rec = &phba->fcf.failover_rec;
else
fcf_rec = &phba->fcf.current_rec;
if (phba->fcf.fcf_flag & FCF_AVAILABLE) {
if (boot_flag && !(fcf_rec->flag & BOOT_ENABLE)) {
lpfc_printf_log(phba, KERN_INFO, LOG_FIP,
"2837 Update current FCF record "
"(x%x) with new FCF record (x%x)\n",
fcf_rec->fcf_indx,
bf_get(lpfc_fcf_record_fcf_index,
new_fcf_record));
__lpfc_update_fcf_record(phba, fcf_rec, new_fcf_record,
addr_mode, vlan_id, BOOT_ENABLE);
spin_unlock_irq(&phba->hbalock);
goto read_next_fcf;
}
if (!boot_flag && (fcf_rec->flag & BOOT_ENABLE)) {
spin_unlock_irq(&phba->hbalock);
goto read_next_fcf;
}
if (new_fcf_record->fip_priority < fcf_rec->priority) {
lpfc_printf_log(phba, KERN_INFO, LOG_FIP,
"2838 Update current FCF record "
"(x%x) with new FCF record (x%x)\n",
fcf_rec->fcf_indx,
bf_get(lpfc_fcf_record_fcf_index,
new_fcf_record));
__lpfc_update_fcf_record(phba, fcf_rec, new_fcf_record,
addr_mode, vlan_id, 0);
phba->fcf.eligible_fcf_cnt = 1;
} else if (new_fcf_record->fip_priority == fcf_rec->priority) {
phba->fcf.eligible_fcf_cnt++;
select_new_fcf = lpfc_sli4_new_fcf_random_select(phba,
phba->fcf.eligible_fcf_cnt);
if (select_new_fcf) {
lpfc_printf_log(phba, KERN_INFO, LOG_FIP,
"2839 Update current FCF record "
"(x%x) with new FCF record (x%x)\n",
fcf_rec->fcf_indx,
bf_get(lpfc_fcf_record_fcf_index,
new_fcf_record));
__lpfc_update_fcf_record(phba, fcf_rec,
new_fcf_record,
addr_mode, vlan_id, 0);
}
}
spin_unlock_irq(&phba->hbalock);
goto read_next_fcf;
}
if (fcf_rec) {
lpfc_printf_log(phba, KERN_INFO, LOG_FIP,
"2840 Update initial FCF candidate "
"with FCF (x%x)\n",
bf_get(lpfc_fcf_record_fcf_index,
new_fcf_record));
__lpfc_update_fcf_record(phba, fcf_rec, new_fcf_record,
addr_mode, vlan_id, (boot_flag ?
BOOT_ENABLE : 0));
phba->fcf.fcf_flag |= FCF_AVAILABLE;
phba->fcf.eligible_fcf_cnt = 1;
seed = (uint32_t)(0xFFFFFFFF & jiffies);
prandom_seed(seed);
}
spin_unlock_irq(&phba->hbalock);
goto read_next_fcf;
read_next_fcf:
lpfc_sli4_mbox_cmd_free(phba, mboxq);
if (next_fcf_index == LPFC_FCOE_FCF_NEXT_NONE || next_fcf_index == 0) {
if (phba->fcf.fcf_flag & FCF_REDISC_FOV) {
if (!(phba->fcf.failover_rec.flag & RECORD_VALID)) {
lpfc_printf_log(phba, KERN_WARNING, LOG_FIP,
"2782 No suitable FCF found: "
"(x%x/x%x)\n",
phba->fcoe_eventtag_at_fcf_scan,
bf_get(lpfc_fcf_record_fcf_index,
new_fcf_record));
spin_lock_irq(&phba->hbalock);
if (phba->hba_flag & HBA_DEVLOSS_TMO) {
phba->hba_flag &= ~FCF_TS_INPROG;
spin_unlock_irq(&phba->hbalock);
lpfc_printf_log(phba, KERN_INFO,
LOG_FIP,
"2864 On devloss tmo "
"unreg in-use FCF and "
"rescan FCF table\n");
lpfc_unregister_fcf_rescan(phba);
return;
}
phba->hba_flag &= ~FCF_TS_INPROG;
spin_unlock_irq(&phba->hbalock);
return;
}
lpfc_unregister_fcf(phba);
lpfc_printf_log(phba, KERN_INFO, LOG_FIP,
"2842 Replace in-use FCF (x%x) "
"with failover FCF (x%x)\n",
phba->fcf.current_rec.fcf_indx,
phba->fcf.failover_rec.fcf_indx);
memcpy(&phba->fcf.current_rec,
&phba->fcf.failover_rec,
sizeof(struct lpfc_fcf_rec));
spin_lock_irq(&phba->hbalock);
phba->fcf.fcf_flag &= ~FCF_REDISC_FOV;
spin_unlock_irq(&phba->hbalock);
lpfc_register_fcf(phba);
} else {
if ((phba->fcf.fcf_flag & FCF_REDISC_EVT) ||
(phba->fcf.fcf_flag & FCF_REDISC_PEND))
return;
if (phba->cfg_fcf_failover_policy == LPFC_FCF_FOV &&
phba->fcf.fcf_flag & FCF_IN_USE) {
lpfc_printf_log(phba, KERN_INFO, LOG_FIP,
"2841 In-use FCF record (x%x) "
"not reported, entering fast "
"FCF failover mode scanning.\n",
phba->fcf.current_rec.fcf_indx);
spin_lock_irq(&phba->hbalock);
phba->fcf.fcf_flag |= FCF_REDISC_FOV;
spin_unlock_irq(&phba->hbalock);
lpfc_sli4_fcf_scan_read_fcf_rec(phba,
LPFC_FCOE_FCF_GET_FIRST);
return;
}
lpfc_register_fcf(phba);
}
} else
lpfc_sli4_fcf_scan_read_fcf_rec(phba, next_fcf_index);
return;
out:
lpfc_sli4_mbox_cmd_free(phba, mboxq);
lpfc_register_fcf(phba);
return;
}
void
lpfc_mbx_cmpl_fcf_rr_read_fcf_rec(struct lpfc_hba *phba, LPFC_MBOXQ_t *mboxq)
{
struct fcf_record *new_fcf_record;
uint32_t boot_flag, addr_mode;
uint16_t next_fcf_index, fcf_index;
uint16_t current_fcf_index;
uint16_t vlan_id;
int rc;
if (phba->link_state < LPFC_LINK_UP) {
spin_lock_irq(&phba->hbalock);
phba->fcf.fcf_flag &= ~FCF_DISCOVERY;
phba->hba_flag &= ~FCF_RR_INPROG;
spin_unlock_irq(&phba->hbalock);
goto out;
}
new_fcf_record = lpfc_sli4_fcf_rec_mbox_parse(phba, mboxq,
&next_fcf_index);
if (!new_fcf_record) {
lpfc_printf_log(phba, KERN_WARNING, LOG_FIP,
"2766 Mailbox command READ_FCF_RECORD "
"failed to retrieve a FCF record. "
"hba_flg x%x fcf_flg x%x\n", phba->hba_flag,
phba->fcf.fcf_flag);
lpfc_unregister_fcf_rescan(phba);
goto out;
}
rc = lpfc_match_fcf_conn_list(phba, new_fcf_record, &boot_flag,
&addr_mode, &vlan_id);
lpfc_sli4_log_fcf_record_info(phba, new_fcf_record, vlan_id,
next_fcf_index);
fcf_index = bf_get(lpfc_fcf_record_fcf_index, new_fcf_record);
if (!rc) {
lpfc_printf_log(phba, KERN_INFO, LOG_FIP,
"2848 Remove ineligible FCF (x%x) from "
"from roundrobin bmask\n", fcf_index);
lpfc_sli4_fcf_rr_index_clear(phba, fcf_index);
fcf_index = lpfc_sli4_fcf_rr_next_index_get(phba);
rc = lpfc_sli4_fcf_rr_next_proc(phba->pport, fcf_index);
if (rc)
goto out;
goto error_out;
}
if (fcf_index == phba->fcf.current_rec.fcf_indx) {
lpfc_printf_log(phba, KERN_INFO, LOG_FIP,
"2760 Perform FLOGI roundrobin FCF failover: "
"FCF (x%x) back to FCF (x%x)\n",
phba->fcf.current_rec.fcf_indx, fcf_index);
msleep(500);
lpfc_issue_init_vfi(phba->pport);
goto out;
}
lpfc_printf_log(phba, KERN_INFO, LOG_FIP,
"2834 Update current FCF (x%x) with new FCF (x%x)\n",
phba->fcf.failover_rec.fcf_indx, fcf_index);
spin_lock_irq(&phba->hbalock);
__lpfc_update_fcf_record(phba, &phba->fcf.failover_rec,
new_fcf_record, addr_mode, vlan_id,
(boot_flag ? BOOT_ENABLE : 0));
spin_unlock_irq(&phba->hbalock);
current_fcf_index = phba->fcf.current_rec.fcf_indx;
lpfc_unregister_fcf(phba);
memcpy(&phba->fcf.current_rec, &phba->fcf.failover_rec,
sizeof(struct lpfc_fcf_rec));
lpfc_printf_log(phba, KERN_INFO, LOG_FIP,
"2783 Perform FLOGI roundrobin FCF failover: FCF "
"(x%x) to FCF (x%x)\n", current_fcf_index, fcf_index);
error_out:
lpfc_register_fcf(phba);
out:
lpfc_sli4_mbox_cmd_free(phba, mboxq);
}
void
lpfc_mbx_cmpl_read_fcf_rec(struct lpfc_hba *phba, LPFC_MBOXQ_t *mboxq)
{
struct fcf_record *new_fcf_record;
uint32_t boot_flag, addr_mode;
uint16_t fcf_index, next_fcf_index;
uint16_t vlan_id;
int rc;
if (phba->link_state < LPFC_LINK_UP)
goto out;
if (!(phba->fcf.fcf_flag & FCF_DISCOVERY))
goto out;
new_fcf_record = lpfc_sli4_fcf_rec_mbox_parse(phba, mboxq,
&next_fcf_index);
if (!new_fcf_record) {
lpfc_printf_log(phba, KERN_INFO, LOG_FIP,
"2767 Mailbox command READ_FCF_RECORD "
"failed to retrieve a FCF record.\n");
goto out;
}
rc = lpfc_match_fcf_conn_list(phba, new_fcf_record, &boot_flag,
&addr_mode, &vlan_id);
lpfc_sli4_log_fcf_record_info(phba, new_fcf_record, vlan_id,
next_fcf_index);
if (!rc)
goto out;
fcf_index = bf_get(lpfc_fcf_record_fcf_index, new_fcf_record);
rc = lpfc_sli4_fcf_pri_list_add(phba, fcf_index, new_fcf_record);
out:
lpfc_sli4_mbox_cmd_free(phba, mboxq);
}
void
lpfc_init_vfi_cmpl(struct lpfc_hba *phba, LPFC_MBOXQ_t *mboxq)
{
struct lpfc_vport *vport = mboxq->vport;
if (mboxq->u.mb.mbxStatus &&
(bf_get(lpfc_sli_intf_if_type, &phba->sli4_hba.sli_intf) !=
LPFC_SLI_INTF_IF_TYPE_0) &&
mboxq->u.mb.mbxStatus != MBX_VFI_IN_USE) {
lpfc_printf_vlog(vport, KERN_ERR,
LOG_MBOX,
"2891 Init VFI mailbox failed 0x%x\n",
mboxq->u.mb.mbxStatus);
mempool_free(mboxq, phba->mbox_mem_pool);
lpfc_vport_set_state(vport, FC_VPORT_FAILED);
return;
}
lpfc_initial_flogi(vport);
mempool_free(mboxq, phba->mbox_mem_pool);
return;
}
void
lpfc_issue_init_vfi(struct lpfc_vport *vport)
{
LPFC_MBOXQ_t *mboxq;
int rc;
struct lpfc_hba *phba = vport->phba;
mboxq = mempool_alloc(phba->mbox_mem_pool, GFP_KERNEL);
if (!mboxq) {
lpfc_printf_vlog(vport, KERN_ERR,
LOG_MBOX, "2892 Failed to allocate "
"init_vfi mailbox\n");
return;
}
lpfc_init_vfi(mboxq, vport);
mboxq->mbox_cmpl = lpfc_init_vfi_cmpl;
rc = lpfc_sli_issue_mbox(phba, mboxq, MBX_NOWAIT);
if (rc == MBX_NOT_FINISHED) {
lpfc_printf_vlog(vport, KERN_ERR,
LOG_MBOX, "2893 Failed to issue init_vfi mailbox\n");
mempool_free(mboxq, vport->phba->mbox_mem_pool);
}
}
void
lpfc_init_vpi_cmpl(struct lpfc_hba *phba, LPFC_MBOXQ_t *mboxq)
{
struct lpfc_vport *vport = mboxq->vport;
struct lpfc_nodelist *ndlp;
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
if (mboxq->u.mb.mbxStatus) {
lpfc_printf_vlog(vport, KERN_ERR,
LOG_MBOX,
"2609 Init VPI mailbox failed 0x%x\n",
mboxq->u.mb.mbxStatus);
mempool_free(mboxq, phba->mbox_mem_pool);
lpfc_vport_set_state(vport, FC_VPORT_FAILED);
return;
}
spin_lock_irq(shost->host_lock);
vport->fc_flag &= ~FC_VPORT_NEEDS_INIT_VPI;
spin_unlock_irq(shost->host_lock);
if ((phba->pport == vport) || (vport->port_state == LPFC_FDISC)) {
ndlp = lpfc_findnode_did(vport, Fabric_DID);
if (!ndlp)
lpfc_printf_vlog(vport, KERN_ERR,
LOG_DISCOVERY,
"2731 Cannot find fabric "
"controller node\n");
else
lpfc_register_new_vport(phba, vport, ndlp);
mempool_free(mboxq, phba->mbox_mem_pool);
return;
}
if (phba->link_flag & LS_NPIV_FAB_SUPPORTED)
lpfc_initial_fdisc(vport);
else {
lpfc_vport_set_state(vport, FC_VPORT_NO_FABRIC_SUPP);
lpfc_printf_vlog(vport, KERN_ERR, LOG_ELS,
"2606 No NPIV Fabric support\n");
}
mempool_free(mboxq, phba->mbox_mem_pool);
return;
}
void
lpfc_issue_init_vpi(struct lpfc_vport *vport)
{
LPFC_MBOXQ_t *mboxq;
int rc, vpi;
if ((vport->port_type != LPFC_PHYSICAL_PORT) && (!vport->vpi)) {
vpi = lpfc_alloc_vpi(vport->phba);
if (!vpi) {
lpfc_printf_vlog(vport, KERN_ERR,
LOG_MBOX,
"3303 Failed to obtain vport vpi\n");
lpfc_vport_set_state(vport, FC_VPORT_FAILED);
return;
}
vport->vpi = vpi;
}
mboxq = mempool_alloc(vport->phba->mbox_mem_pool, GFP_KERNEL);
if (!mboxq) {
lpfc_printf_vlog(vport, KERN_ERR,
LOG_MBOX, "2607 Failed to allocate "
"init_vpi mailbox\n");
return;
}
lpfc_init_vpi(vport->phba, mboxq, vport->vpi);
mboxq->vport = vport;
mboxq->mbox_cmpl = lpfc_init_vpi_cmpl;
rc = lpfc_sli_issue_mbox(vport->phba, mboxq, MBX_NOWAIT);
if (rc == MBX_NOT_FINISHED) {
lpfc_printf_vlog(vport, KERN_ERR,
LOG_MBOX, "2608 Failed to issue init_vpi mailbox\n");
mempool_free(mboxq, vport->phba->mbox_mem_pool);
}
}
void
lpfc_start_fdiscs(struct lpfc_hba *phba)
{
struct lpfc_vport **vports;
int i;
vports = lpfc_create_vport_work_array(phba);
if (vports != NULL) {
for (i = 0; i <= phba->max_vports && vports[i] != NULL; i++) {
if (vports[i]->port_type == LPFC_PHYSICAL_PORT)
continue;
if (vports[i]->vpi > phba->max_vpi) {
lpfc_vport_set_state(vports[i],
FC_VPORT_FAILED);
continue;
}
if (phba->fc_topology == LPFC_TOPOLOGY_LOOP) {
lpfc_vport_set_state(vports[i],
FC_VPORT_LINKDOWN);
continue;
}
if (vports[i]->fc_flag & FC_VPORT_NEEDS_INIT_VPI) {
lpfc_issue_init_vpi(vports[i]);
continue;
}
if (phba->link_flag & LS_NPIV_FAB_SUPPORTED)
lpfc_initial_fdisc(vports[i]);
else {
lpfc_vport_set_state(vports[i],
FC_VPORT_NO_FABRIC_SUPP);
lpfc_printf_vlog(vports[i], KERN_ERR,
LOG_ELS,
"0259 No NPIV "
"Fabric support\n");
}
}
}
lpfc_destroy_vport_work_array(phba, vports);
}
void
lpfc_mbx_cmpl_reg_vfi(struct lpfc_hba *phba, LPFC_MBOXQ_t *mboxq)
{
struct lpfc_dmabuf *dmabuf = mboxq->context1;
struct lpfc_vport *vport = mboxq->vport;
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
if (mboxq->u.mb.mbxStatus &&
(bf_get(lpfc_sli_intf_if_type, &phba->sli4_hba.sli_intf) !=
LPFC_SLI_INTF_IF_TYPE_0) &&
mboxq->u.mb.mbxStatus != MBX_VFI_IN_USE) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_MBOX,
"2018 REG_VFI mbxStatus error x%x "
"HBA state x%x\n",
mboxq->u.mb.mbxStatus, vport->port_state);
if (phba->fc_topology == LPFC_TOPOLOGY_LOOP) {
lpfc_disc_list_loopmap(vport);
lpfc_disc_start(vport);
goto out_free_mem;
}
lpfc_vport_set_state(vport, FC_VPORT_FAILED);
goto out_free_mem;
}
if (vport->fc_flag & FC_VFI_REGISTERED)
if (!(phba->sli_rev == LPFC_SLI_REV4 &&
vport->fc_flag & FC_PT2PT))
goto out_free_mem;
spin_lock_irq(shost->host_lock);
vport->vpi_state |= LPFC_VPI_REGISTERED;
vport->fc_flag |= FC_VFI_REGISTERED;
vport->fc_flag &= ~FC_VPORT_NEEDS_REG_VPI;
vport->fc_flag &= ~FC_VPORT_NEEDS_INIT_VPI;
spin_unlock_irq(shost->host_lock);
if ((phba->sli_rev == LPFC_SLI_REV4) &&
(phba->link_flag & LS_LOOPBACK_MODE)) {
phba->link_state = LPFC_HBA_READY;
goto out_free_mem;
}
lpfc_printf_vlog(vport, KERN_INFO, LOG_SLI,
"3313 cmpl reg vfi port_state:%x fc_flag:%x myDid:%x "
"alpacnt:%d LinkState:%x topology:%x\n",
vport->port_state, vport->fc_flag, vport->fc_myDID,
vport->phba->alpa_map[0],
phba->link_state, phba->fc_topology);
if (vport->port_state == LPFC_FABRIC_CFG_LINK) {
if ((vport->fc_flag & FC_PT2PT) ||
((phba->fc_topology == LPFC_TOPOLOGY_LOOP) &&
!(vport->fc_flag & FC_PUBLIC_LOOP))) {
lpfc_disc_list_loopmap(vport);
if (vport->fc_flag & FC_PT2PT)
vport->port_state = LPFC_VPORT_READY;
else
lpfc_disc_start(vport);
} else {
lpfc_start_fdiscs(phba);
lpfc_do_scr_ns_plogi(phba, vport);
}
}
out_free_mem:
mempool_free(mboxq, phba->mbox_mem_pool);
lpfc_mbuf_free(phba, dmabuf->virt, dmabuf->phys);
kfree(dmabuf);
return;
}
static void
lpfc_mbx_cmpl_read_sparam(struct lpfc_hba *phba, LPFC_MBOXQ_t *pmb)
{
MAILBOX_t *mb = &pmb->u.mb;
struct lpfc_dmabuf *mp = (struct lpfc_dmabuf *) pmb->context1;
struct lpfc_vport *vport = pmb->vport;
if (mb->mbxStatus) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_MBOX,
"0319 READ_SPARAM mbxStatus error x%x "
"hba state x%x>\n",
mb->mbxStatus, vport->port_state);
lpfc_linkdown(phba);
goto out;
}
memcpy((uint8_t *) &vport->fc_sparam, (uint8_t *) mp->virt,
sizeof (struct serv_parm));
lpfc_update_vport_wwn(vport);
if (vport->port_type == LPFC_PHYSICAL_PORT) {
memcpy(&phba->wwnn, &vport->fc_nodename, sizeof(phba->wwnn));
memcpy(&phba->wwpn, &vport->fc_portname, sizeof(phba->wwnn));
}
lpfc_mbuf_free(phba, mp->virt, mp->phys);
kfree(mp);
mempool_free(pmb, phba->mbox_mem_pool);
return;
out:
pmb->context1 = NULL;
lpfc_mbuf_free(phba, mp->virt, mp->phys);
kfree(mp);
lpfc_issue_clear_la(phba, vport);
mempool_free(pmb, phba->mbox_mem_pool);
return;
}
static void
lpfc_mbx_process_link_up(struct lpfc_hba *phba, struct lpfc_mbx_read_top *la)
{
struct lpfc_vport *vport = phba->pport;
LPFC_MBOXQ_t *sparam_mbox, *cfglink_mbox = NULL;
struct Scsi_Host *shost;
int i;
struct lpfc_dmabuf *mp;
int rc;
struct fcf_record *fcf_record;
uint32_t fc_flags = 0;
spin_lock_irq(&phba->hbalock);
switch (bf_get(lpfc_mbx_read_top_link_spd, la)) {
case LPFC_LINK_SPEED_1GHZ:
case LPFC_LINK_SPEED_2GHZ:
case LPFC_LINK_SPEED_4GHZ:
case LPFC_LINK_SPEED_8GHZ:
case LPFC_LINK_SPEED_10GHZ:
case LPFC_LINK_SPEED_16GHZ:
phba->fc_linkspeed = bf_get(lpfc_mbx_read_top_link_spd, la);
break;
default:
phba->fc_linkspeed = LPFC_LINK_SPEED_UNKNOWN;
break;
}
if (phba->fc_topology &&
phba->fc_topology != bf_get(lpfc_mbx_read_top_topology, la)) {
lpfc_printf_log(phba, KERN_WARNING, LOG_SLI,
"3314 Toplogy changed was 0x%x is 0x%x\n",
phba->fc_topology,
bf_get(lpfc_mbx_read_top_topology, la));
phba->fc_topology_changed = 1;
}
phba->fc_topology = bf_get(lpfc_mbx_read_top_topology, la);
phba->link_flag &= ~LS_NPIV_FAB_SUPPORTED;
shost = lpfc_shost_from_vport(vport);
if (phba->fc_topology == LPFC_TOPOLOGY_LOOP) {
phba->sli3_options &= ~LPFC_SLI3_NPIV_ENABLED;
if (phba->cfg_enable_npiv && phba->max_vpi)
lpfc_printf_log(phba, KERN_ERR, LOG_LINK_EVENT,
"1309 Link Up Event npiv not supported in loop "
"topology\n");
if (bf_get(lpfc_mbx_read_top_il, la))
fc_flags |= FC_LBIT;
vport->fc_myDID = bf_get(lpfc_mbx_read_top_alpa_granted, la);
i = la->lilpBde64.tus.f.bdeSize;
if (i == 0) {
phba->alpa_map[0] = 0;
} else {
if (vport->cfg_log_verbose & LOG_LINK_EVENT) {
int numalpa, j, k;
union {
uint8_t pamap[16];
struct {
uint32_t wd1;
uint32_t wd2;
uint32_t wd3;
uint32_t wd4;
} pa;
} un;
numalpa = phba->alpa_map[0];
j = 0;
while (j < numalpa) {
memset(un.pamap, 0, 16);
for (k = 1; j < numalpa; k++) {
un.pamap[k - 1] =
phba->alpa_map[j + 1];
j++;
if (k == 16)
break;
}
lpfc_printf_log(phba,
KERN_WARNING,
LOG_LINK_EVENT,
"1304 Link Up Event "
"ALPA map Data: x%x "
"x%x x%x x%x\n",
un.pa.wd1, un.pa.wd2,
un.pa.wd3, un.pa.wd4);
}
}
}
} else {
if (!(phba->sli3_options & LPFC_SLI3_NPIV_ENABLED)) {
if (phba->max_vpi && phba->cfg_enable_npiv &&
(phba->sli_rev >= LPFC_SLI_REV3))
phba->sli3_options |= LPFC_SLI3_NPIV_ENABLED;
}
vport->fc_myDID = phba->fc_pref_DID;
fc_flags |= FC_LBIT;
}
spin_unlock_irq(&phba->hbalock);
if (fc_flags) {
spin_lock_irq(shost->host_lock);
vport->fc_flag |= fc_flags;
spin_unlock_irq(shost->host_lock);
}
lpfc_linkup(phba);
sparam_mbox = mempool_alloc(phba->mbox_mem_pool, GFP_KERNEL);
if (!sparam_mbox)
goto out;
rc = lpfc_read_sparam(phba, sparam_mbox, 0);
if (rc) {
mempool_free(sparam_mbox, phba->mbox_mem_pool);
goto out;
}
sparam_mbox->vport = vport;
sparam_mbox->mbox_cmpl = lpfc_mbx_cmpl_read_sparam;
rc = lpfc_sli_issue_mbox(phba, sparam_mbox, MBX_NOWAIT);
if (rc == MBX_NOT_FINISHED) {
mp = (struct lpfc_dmabuf *) sparam_mbox->context1;
lpfc_mbuf_free(phba, mp->virt, mp->phys);
kfree(mp);
mempool_free(sparam_mbox, phba->mbox_mem_pool);
goto out;
}
if (!(phba->hba_flag & HBA_FCOE_MODE)) {
cfglink_mbox = mempool_alloc(phba->mbox_mem_pool, GFP_KERNEL);
if (!cfglink_mbox)
goto out;
vport->port_state = LPFC_LOCAL_CFG_LINK;
lpfc_config_link(phba, cfglink_mbox);
cfglink_mbox->vport = vport;
cfglink_mbox->mbox_cmpl = lpfc_mbx_cmpl_local_config_link;
rc = lpfc_sli_issue_mbox(phba, cfglink_mbox, MBX_NOWAIT);
if (rc == MBX_NOT_FINISHED) {
mempool_free(cfglink_mbox, phba->mbox_mem_pool);
goto out;
}
} else {
vport->port_state = LPFC_VPORT_UNKNOWN;
if (!(phba->hba_flag & HBA_FIP_SUPPORT)) {
fcf_record = kzalloc(sizeof(struct fcf_record),
GFP_KERNEL);
if (unlikely(!fcf_record)) {
lpfc_printf_log(phba, KERN_ERR,
LOG_MBOX | LOG_SLI,
"2554 Could not allocate memory for "
"fcf record\n");
rc = -ENODEV;
goto out;
}
lpfc_sli4_build_dflt_fcf_record(phba, fcf_record,
LPFC_FCOE_FCF_DEF_INDEX);
rc = lpfc_sli4_add_fcf_record(phba, fcf_record);
if (unlikely(rc)) {
lpfc_printf_log(phba, KERN_ERR,
LOG_MBOX | LOG_SLI,
"2013 Could not manually add FCF "
"record 0, status %d\n", rc);
rc = -ENODEV;
kfree(fcf_record);
goto out;
}
kfree(fcf_record);
}
spin_lock_irq(&phba->hbalock);
if (phba->hba_flag & FCF_TS_INPROG) {
spin_unlock_irq(&phba->hbalock);
return;
}
phba->fcf.fcf_flag |= FCF_INIT_DISC;
spin_unlock_irq(&phba->hbalock);
lpfc_printf_log(phba, KERN_INFO, LOG_FIP | LOG_DISCOVERY,
"2778 Start FCF table scan at linkup\n");
rc = lpfc_sli4_fcf_scan_read_fcf_rec(phba,
LPFC_FCOE_FCF_GET_FIRST);
if (rc) {
spin_lock_irq(&phba->hbalock);
phba->fcf.fcf_flag &= ~FCF_INIT_DISC;
spin_unlock_irq(&phba->hbalock);
goto out;
}
lpfc_sli4_clear_fcf_rr_bmask(phba);
}
return;
out:
lpfc_vport_set_state(vport, FC_VPORT_FAILED);
lpfc_printf_vlog(vport, KERN_ERR, LOG_MBOX,
"0263 Discovery Mailbox error: state: 0x%x : %p %p\n",
vport->port_state, sparam_mbox, cfglink_mbox);
lpfc_issue_clear_la(phba, vport);
return;
}
static void
lpfc_enable_la(struct lpfc_hba *phba)
{
uint32_t control;
struct lpfc_sli *psli = &phba->sli;
spin_lock_irq(&phba->hbalock);
psli->sli_flag |= LPFC_PROCESS_LA;
if (phba->sli_rev <= LPFC_SLI_REV3) {
control = readl(phba->HCregaddr);
control |= HC_LAINT_ENA;
writel(control, phba->HCregaddr);
readl(phba->HCregaddr);
}
spin_unlock_irq(&phba->hbalock);
}
static void
lpfc_mbx_issue_link_down(struct lpfc_hba *phba)
{
lpfc_linkdown(phba);
lpfc_enable_la(phba);
lpfc_unregister_unused_fcf(phba);
}
void
lpfc_mbx_cmpl_read_topology(struct lpfc_hba *phba, LPFC_MBOXQ_t *pmb)
{
struct lpfc_vport *vport = pmb->vport;
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
struct lpfc_mbx_read_top *la;
MAILBOX_t *mb = &pmb->u.mb;
struct lpfc_dmabuf *mp = (struct lpfc_dmabuf *) (pmb->context1);
phba->sli.ring[LPFC_ELS_RING].flag &= ~LPFC_STOP_IOCB_EVENT;
if (mb->mbxStatus) {
lpfc_printf_log(phba, KERN_INFO, LOG_LINK_EVENT,
"1307 READ_LA mbox error x%x state x%x\n",
mb->mbxStatus, vport->port_state);
lpfc_mbx_issue_link_down(phba);
phba->link_state = LPFC_HBA_ERROR;
goto lpfc_mbx_cmpl_read_topology_free_mbuf;
}
la = (struct lpfc_mbx_read_top *) &pmb->u.mb.un.varReadTop;
memcpy(&phba->alpa_map[0], mp->virt, 128);
spin_lock_irq(shost->host_lock);
if (bf_get(lpfc_mbx_read_top_pb, la))
vport->fc_flag |= FC_BYPASSED_MODE;
else
vport->fc_flag &= ~FC_BYPASSED_MODE;
spin_unlock_irq(shost->host_lock);
if (phba->fc_eventTag <= la->eventTag) {
phba->fc_stat.LinkMultiEvent++;
if (bf_get(lpfc_mbx_read_top_att_type, la) == LPFC_ATT_LINK_UP)
if (phba->fc_eventTag != 0)
lpfc_linkdown(phba);
}
phba->fc_eventTag = la->eventTag;
if (phba->sli_rev < LPFC_SLI_REV4) {
spin_lock_irq(&phba->hbalock);
if (bf_get(lpfc_mbx_read_top_mm, la))
phba->sli.sli_flag |= LPFC_MENLO_MAINT;
else
phba->sli.sli_flag &= ~LPFC_MENLO_MAINT;
spin_unlock_irq(&phba->hbalock);
}
phba->link_events++;
if ((bf_get(lpfc_mbx_read_top_att_type, la) == LPFC_ATT_LINK_UP) &&
!(phba->sli.sli_flag & LPFC_MENLO_MAINT)) {
phba->fc_stat.LinkUp++;
if (phba->link_flag & LS_LOOPBACK_MODE) {
lpfc_printf_log(phba, KERN_ERR, LOG_LINK_EVENT,
"1306 Link Up Event in loop back mode "
"x%x received Data: x%x x%x x%x x%x\n",
la->eventTag, phba->fc_eventTag,
bf_get(lpfc_mbx_read_top_alpa_granted,
la),
bf_get(lpfc_mbx_read_top_link_spd, la),
phba->alpa_map[0]);
} else {
lpfc_printf_log(phba, KERN_ERR, LOG_LINK_EVENT,
"1303 Link Up Event x%x received "
"Data: x%x x%x x%x x%x x%x x%x %d\n",
la->eventTag, phba->fc_eventTag,
bf_get(lpfc_mbx_read_top_alpa_granted,
la),
bf_get(lpfc_mbx_read_top_link_spd, la),
phba->alpa_map[0],
bf_get(lpfc_mbx_read_top_mm, la),
bf_get(lpfc_mbx_read_top_fa, la),
phba->wait_4_mlo_maint_flg);
}
lpfc_mbx_process_link_up(phba, la);
} else if (bf_get(lpfc_mbx_read_top_att_type, la) ==
LPFC_ATT_LINK_DOWN) {
phba->fc_stat.LinkDown++;
if (phba->link_flag & LS_LOOPBACK_MODE)
lpfc_printf_log(phba, KERN_ERR, LOG_LINK_EVENT,
"1308 Link Down Event in loop back mode "
"x%x received "
"Data: x%x x%x x%x\n",
la->eventTag, phba->fc_eventTag,
phba->pport->port_state, vport->fc_flag);
else
lpfc_printf_log(phba, KERN_ERR, LOG_LINK_EVENT,
"1305 Link Down Event x%x received "
"Data: x%x x%x x%x x%x x%x\n",
la->eventTag, phba->fc_eventTag,
phba->pport->port_state, vport->fc_flag,
bf_get(lpfc_mbx_read_top_mm, la),
bf_get(lpfc_mbx_read_top_fa, la));
lpfc_mbx_issue_link_down(phba);
}
if ((phba->sli.sli_flag & LPFC_MENLO_MAINT) &&
((bf_get(lpfc_mbx_read_top_att_type, la) == LPFC_ATT_LINK_UP))) {
if (phba->link_state != LPFC_LINK_DOWN) {
phba->fc_stat.LinkDown++;
lpfc_printf_log(phba, KERN_ERR, LOG_LINK_EVENT,
"1312 Link Down Event x%x received "
"Data: x%x x%x x%x\n",
la->eventTag, phba->fc_eventTag,
phba->pport->port_state, vport->fc_flag);
lpfc_mbx_issue_link_down(phba);
} else
lpfc_enable_la(phba);
lpfc_printf_log(phba, KERN_ERR, LOG_LINK_EVENT,
"1310 Menlo Maint Mode Link up Event x%x rcvd "
"Data: x%x x%x x%x\n",
la->eventTag, phba->fc_eventTag,
phba->pport->port_state, vport->fc_flag);
if (phba->wait_4_mlo_maint_flg) {
phba->wait_4_mlo_maint_flg = 0;
wake_up_interruptible(&phba->wait_4_mlo_m_q);
}
}
if ((phba->sli_rev < LPFC_SLI_REV4) &&
bf_get(lpfc_mbx_read_top_fa, la)) {
if (phba->sli.sli_flag & LPFC_MENLO_MAINT)
lpfc_issue_clear_la(phba, vport);
lpfc_printf_log(phba, KERN_INFO, LOG_LINK_EVENT,
"1311 fa %d\n",
bf_get(lpfc_mbx_read_top_fa, la));
}
lpfc_mbx_cmpl_read_topology_free_mbuf:
lpfc_mbuf_free(phba, mp->virt, mp->phys);
kfree(mp);
mempool_free(pmb, phba->mbox_mem_pool);
return;
}
void
lpfc_mbx_cmpl_reg_login(struct lpfc_hba *phba, LPFC_MBOXQ_t *pmb)
{
struct lpfc_vport *vport = pmb->vport;
struct lpfc_dmabuf *mp = (struct lpfc_dmabuf *) (pmb->context1);
struct lpfc_nodelist *ndlp = (struct lpfc_nodelist *) pmb->context2;
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
pmb->context1 = NULL;
pmb->context2 = NULL;
if (ndlp->nlp_flag & NLP_REG_LOGIN_SEND)
ndlp->nlp_flag &= ~NLP_REG_LOGIN_SEND;
if (ndlp->nlp_flag & NLP_IGNR_REG_CMPL ||
ndlp->nlp_state != NLP_STE_REG_LOGIN_ISSUE) {
spin_lock_irq(shost->host_lock);
ndlp->nlp_flag &= ~NLP_IGNR_REG_CMPL;
spin_unlock_irq(shost->host_lock);
} else
lpfc_disc_state_machine(vport, ndlp, pmb,
NLP_EVT_CMPL_REG_LOGIN);
lpfc_mbuf_free(phba, mp->virt, mp->phys);
kfree(mp);
mempool_free(pmb, phba->mbox_mem_pool);
lpfc_nlp_put(ndlp);
return;
}
static void
lpfc_mbx_cmpl_unreg_vpi(struct lpfc_hba *phba, LPFC_MBOXQ_t *pmb)
{
MAILBOX_t *mb = &pmb->u.mb;
struct lpfc_vport *vport = pmb->vport;
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
switch (mb->mbxStatus) {
case 0x0011:
case 0x0020:
lpfc_printf_vlog(vport, KERN_INFO, LOG_NODE,
"0911 cmpl_unreg_vpi, mb status = 0x%x\n",
mb->mbxStatus);
break;
case 0x9700:
lpfc_printf_vlog(vport, KERN_ERR, LOG_NODE,
"2798 Unreg_vpi failed vpi 0x%x, mb status = 0x%x\n",
vport->vpi, mb->mbxStatus);
if (!(phba->pport->load_flag & FC_UNLOADING))
lpfc_workq_post_event(phba, NULL, NULL,
LPFC_EVT_RESET_HBA);
}
spin_lock_irq(shost->host_lock);
vport->vpi_state &= ~LPFC_VPI_REGISTERED;
vport->fc_flag |= FC_VPORT_NEEDS_REG_VPI;
spin_unlock_irq(shost->host_lock);
vport->unreg_vpi_cmpl = VPORT_OK;
mempool_free(pmb, phba->mbox_mem_pool);
lpfc_cleanup_vports_rrqs(vport, NULL);
if ((vport->load_flag & FC_UNLOADING) && (vport != phba->pport))
scsi_host_put(shost);
}
int
lpfc_mbx_unreg_vpi(struct lpfc_vport *vport)
{
struct lpfc_hba *phba = vport->phba;
LPFC_MBOXQ_t *mbox;
int rc;
mbox = mempool_alloc(phba->mbox_mem_pool, GFP_KERNEL);
if (!mbox)
return 1;
lpfc_unreg_vpi(phba, vport->vpi, mbox);
mbox->vport = vport;
mbox->mbox_cmpl = lpfc_mbx_cmpl_unreg_vpi;
rc = lpfc_sli_issue_mbox(phba, mbox, MBX_NOWAIT);
if (rc == MBX_NOT_FINISHED) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_MBOX | LOG_VPORT,
"1800 Could not issue unreg_vpi\n");
mempool_free(mbox, phba->mbox_mem_pool);
vport->unreg_vpi_cmpl = VPORT_ERROR;
return rc;
}
return 0;
}
static void
lpfc_mbx_cmpl_reg_vpi(struct lpfc_hba *phba, LPFC_MBOXQ_t *pmb)
{
struct lpfc_vport *vport = pmb->vport;
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
MAILBOX_t *mb = &pmb->u.mb;
switch (mb->mbxStatus) {
case 0x0011:
case 0x9601:
case 0x9602:
lpfc_printf_vlog(vport, KERN_INFO, LOG_NODE,
"0912 cmpl_reg_vpi, mb status = 0x%x\n",
mb->mbxStatus);
lpfc_vport_set_state(vport, FC_VPORT_FAILED);
spin_lock_irq(shost->host_lock);
vport->fc_flag &= ~(FC_FABRIC | FC_PUBLIC_LOOP);
spin_unlock_irq(shost->host_lock);
vport->fc_myDID = 0;
goto out;
}
spin_lock_irq(shost->host_lock);
vport->vpi_state |= LPFC_VPI_REGISTERED;
vport->fc_flag &= ~FC_VPORT_NEEDS_REG_VPI;
spin_unlock_irq(shost->host_lock);
vport->num_disc_nodes = 0;
if (vport->fc_npr_cnt)
lpfc_els_disc_plogi(vport);
if (!vport->num_disc_nodes) {
spin_lock_irq(shost->host_lock);
vport->fc_flag &= ~FC_NDISC_ACTIVE;
spin_unlock_irq(shost->host_lock);
lpfc_can_disctmo(vport);
}
vport->port_state = LPFC_VPORT_READY;
out:
mempool_free(pmb, phba->mbox_mem_pool);
return;
}
void
lpfc_create_static_vport(struct lpfc_hba *phba)
{
LPFC_MBOXQ_t *pmb = NULL;
MAILBOX_t *mb;
struct static_vport_info *vport_info;
int mbx_wait_rc = 0, i;
struct fc_vport_identifiers vport_id;
struct fc_vport *new_fc_vport;
struct Scsi_Host *shost;
struct lpfc_vport *vport;
uint16_t offset = 0;
uint8_t *vport_buff;
struct lpfc_dmabuf *mp;
uint32_t byte_count = 0;
pmb = mempool_alloc(phba->mbox_mem_pool, GFP_KERNEL);
if (!pmb) {
lpfc_printf_log(phba, KERN_ERR, LOG_INIT,
"0542 lpfc_create_static_vport failed to"
" allocate mailbox memory\n");
return;
}
memset(pmb, 0, sizeof(LPFC_MBOXQ_t));
mb = &pmb->u.mb;
vport_info = kzalloc(sizeof(struct static_vport_info), GFP_KERNEL);
if (!vport_info) {
lpfc_printf_log(phba, KERN_ERR, LOG_INIT,
"0543 lpfc_create_static_vport failed to"
" allocate vport_info\n");
mempool_free(pmb, phba->mbox_mem_pool);
return;
}
vport_buff = (uint8_t *) vport_info;
do {
if (pmb->context1) {
mp = (struct lpfc_dmabuf *)pmb->context1;
lpfc_mbuf_free(phba, mp->virt, mp->phys);
kfree(mp);
}
if (lpfc_dump_static_vport(phba, pmb, offset))
goto out;
pmb->vport = phba->pport;
mbx_wait_rc = lpfc_sli_issue_mbox_wait(phba, pmb,
LPFC_MBOX_TMO);
if ((mbx_wait_rc != MBX_SUCCESS) || mb->mbxStatus) {
lpfc_printf_log(phba, KERN_WARNING, LOG_INIT,
"0544 lpfc_create_static_vport failed to"
" issue dump mailbox command ret 0x%x "
"status 0x%x\n",
mbx_wait_rc, mb->mbxStatus);
goto out;
}
if (phba->sli_rev == LPFC_SLI_REV4) {
byte_count = pmb->u.mqe.un.mb_words[5];
mp = (struct lpfc_dmabuf *)pmb->context1;
if (byte_count > sizeof(struct static_vport_info) -
offset)
byte_count = sizeof(struct static_vport_info)
- offset;
memcpy(vport_buff + offset, mp->virt, byte_count);
offset += byte_count;
} else {
if (mb->un.varDmp.word_cnt >
sizeof(struct static_vport_info) - offset)
mb->un.varDmp.word_cnt =
sizeof(struct static_vport_info)
- offset;
byte_count = mb->un.varDmp.word_cnt;
lpfc_sli_pcimem_bcopy(((uint8_t *)mb) + DMP_RSP_OFFSET,
vport_buff + offset,
byte_count);
offset += byte_count;
}
} while (byte_count &&
offset < sizeof(struct static_vport_info));
if ((le32_to_cpu(vport_info->signature) != VPORT_INFO_SIG) ||
((le32_to_cpu(vport_info->rev) & VPORT_INFO_REV_MASK)
!= VPORT_INFO_REV)) {
lpfc_printf_log(phba, KERN_ERR, LOG_INIT,
"0545 lpfc_create_static_vport bad"
" information header 0x%x 0x%x\n",
le32_to_cpu(vport_info->signature),
le32_to_cpu(vport_info->rev) & VPORT_INFO_REV_MASK);
goto out;
}
shost = lpfc_shost_from_vport(phba->pport);
for (i = 0; i < MAX_STATIC_VPORT_COUNT; i++) {
memset(&vport_id, 0, sizeof(vport_id));
vport_id.port_name = wwn_to_u64(vport_info->vport_list[i].wwpn);
vport_id.node_name = wwn_to_u64(vport_info->vport_list[i].wwnn);
if (!vport_id.port_name || !vport_id.node_name)
continue;
vport_id.roles = FC_PORT_ROLE_FCP_INITIATOR;
vport_id.vport_type = FC_PORTTYPE_NPIV;
vport_id.disable = false;
new_fc_vport = fc_vport_create(shost, 0, &vport_id);
if (!new_fc_vport) {
lpfc_printf_log(phba, KERN_WARNING, LOG_INIT,
"0546 lpfc_create_static_vport failed to"
" create vport\n");
continue;
}
vport = *(struct lpfc_vport **)new_fc_vport->dd_data;
vport->vport_flag |= STATIC_VPORT;
}
out:
kfree(vport_info);
if (mbx_wait_rc != MBX_TIMEOUT) {
if (pmb->context1) {
mp = (struct lpfc_dmabuf *)pmb->context1;
lpfc_mbuf_free(phba, mp->virt, mp->phys);
kfree(mp);
}
mempool_free(pmb, phba->mbox_mem_pool);
}
return;
}
void
lpfc_mbx_cmpl_fabric_reg_login(struct lpfc_hba *phba, LPFC_MBOXQ_t *pmb)
{
struct lpfc_vport *vport = pmb->vport;
MAILBOX_t *mb = &pmb->u.mb;
struct lpfc_dmabuf *mp = (struct lpfc_dmabuf *) (pmb->context1);
struct lpfc_nodelist *ndlp;
struct Scsi_Host *shost;
ndlp = (struct lpfc_nodelist *) pmb->context2;
pmb->context1 = NULL;
pmb->context2 = NULL;
if (mb->mbxStatus) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_MBOX,
"0258 Register Fabric login error: 0x%x\n",
mb->mbxStatus);
lpfc_mbuf_free(phba, mp->virt, mp->phys);
kfree(mp);
mempool_free(pmb, phba->mbox_mem_pool);
if (phba->fc_topology == LPFC_TOPOLOGY_LOOP) {
lpfc_disc_list_loopmap(vport);
lpfc_disc_start(vport);
lpfc_nlp_put(ndlp);
return;
}
lpfc_vport_set_state(vport, FC_VPORT_FAILED);
lpfc_nlp_put(ndlp);
return;
}
if (phba->sli_rev < LPFC_SLI_REV4)
ndlp->nlp_rpi = mb->un.varWords[0];
ndlp->nlp_flag |= NLP_RPI_REGISTERED;
ndlp->nlp_type |= NLP_FABRIC;
lpfc_nlp_set_state(vport, ndlp, NLP_STE_UNMAPPED_NODE);
if (vport->port_state == LPFC_FABRIC_CFG_LINK) {
if (!(vport->fc_flag & FC_LOGO_RCVD_DID_CHNG))
lpfc_start_fdiscs(phba);
else {
shost = lpfc_shost_from_vport(vport);
spin_lock_irq(shost->host_lock);
vport->fc_flag &= ~FC_LOGO_RCVD_DID_CHNG ;
spin_unlock_irq(shost->host_lock);
}
lpfc_do_scr_ns_plogi(phba, vport);
}
lpfc_mbuf_free(phba, mp->virt, mp->phys);
kfree(mp);
mempool_free(pmb, phba->mbox_mem_pool);
lpfc_nlp_put(ndlp);
return;
}
void
lpfc_mbx_cmpl_ns_reg_login(struct lpfc_hba *phba, LPFC_MBOXQ_t *pmb)
{
MAILBOX_t *mb = &pmb->u.mb;
struct lpfc_dmabuf *mp = (struct lpfc_dmabuf *) (pmb->context1);
struct lpfc_nodelist *ndlp = (struct lpfc_nodelist *) pmb->context2;
struct lpfc_vport *vport = pmb->vport;
pmb->context1 = NULL;
pmb->context2 = NULL;
if (mb->mbxStatus) {
out:
lpfc_printf_vlog(vport, KERN_ERR, LOG_ELS,
"0260 Register NameServer error: 0x%x\n",
mb->mbxStatus);
lpfc_nlp_put(ndlp);
lpfc_mbuf_free(phba, mp->virt, mp->phys);
kfree(mp);
mempool_free(pmb, phba->mbox_mem_pool);
lpfc_nlp_not_used(ndlp);
if (phba->fc_topology == LPFC_TOPOLOGY_LOOP) {
lpfc_disc_list_loopmap(vport);
lpfc_disc_start(vport);
return;
}
lpfc_vport_set_state(vport, FC_VPORT_FAILED);
return;
}
if (phba->sli_rev < LPFC_SLI_REV4)
ndlp->nlp_rpi = mb->un.varWords[0];
ndlp->nlp_flag |= NLP_RPI_REGISTERED;
ndlp->nlp_type |= NLP_FABRIC;
lpfc_nlp_set_state(vport, ndlp, NLP_STE_UNMAPPED_NODE);
if (vport->port_state < LPFC_VPORT_READY) {
lpfc_ns_cmd(vport, SLI_CTNS_RFF_ID, 0, 0);
lpfc_ns_cmd(vport, SLI_CTNS_RNN_ID, 0, 0);
lpfc_ns_cmd(vport, SLI_CTNS_RSNN_NN, 0, 0);
lpfc_ns_cmd(vport, SLI_CTNS_RSPN_ID, 0, 0);
lpfc_ns_cmd(vport, SLI_CTNS_RFT_ID, 0, 0);
lpfc_issue_els_scr(vport, SCR_DID, 0);
}
vport->fc_ns_retry = 0;
if (lpfc_ns_cmd(vport, SLI_CTNS_GID_FT, 0, 0)) {
goto out;
}
lpfc_nlp_put(ndlp);
lpfc_mbuf_free(phba, mp->virt, mp->phys);
kfree(mp);
mempool_free(pmb, phba->mbox_mem_pool);
return;
}
static void
lpfc_register_remote_port(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
struct fc_rport *rport;
struct lpfc_rport_data *rdata;
struct fc_rport_identifiers rport_ids;
struct lpfc_hba *phba = vport->phba;
rport_ids.node_name = wwn_to_u64(ndlp->nlp_nodename.u.wwn);
rport_ids.port_name = wwn_to_u64(ndlp->nlp_portname.u.wwn);
rport_ids.port_id = ndlp->nlp_DID;
rport_ids.roles = FC_RPORT_ROLE_UNKNOWN;
if (ndlp->rport && ndlp->rport->dd_data &&
((struct lpfc_rport_data *) ndlp->rport->dd_data)->pnode == ndlp)
lpfc_nlp_put(ndlp);
lpfc_debugfs_disc_trc(vport, LPFC_DISC_TRC_RPORT,
"rport add: did:x%x flg:x%x type x%x",
ndlp->nlp_DID, ndlp->nlp_flag, ndlp->nlp_type);
if (vport->load_flag & FC_UNLOADING)
return;
ndlp->rport = rport = fc_remote_port_add(shost, 0, &rport_ids);
if (!rport || !get_device(&rport->dev)) {
dev_printk(KERN_WARNING, &phba->pcidev->dev,
"Warning: fc_remote_port_add failed\n");
return;
}
rport->maxframe_size = ndlp->nlp_maxframe;
rport->supported_classes = ndlp->nlp_class_sup;
rdata = rport->dd_data;
rdata->pnode = lpfc_nlp_get(ndlp);
if (ndlp->nlp_type & NLP_FCP_TARGET)
rport_ids.roles |= FC_RPORT_ROLE_FCP_TARGET;
if (ndlp->nlp_type & NLP_FCP_INITIATOR)
rport_ids.roles |= FC_RPORT_ROLE_FCP_INITIATOR;
if (rport_ids.roles != FC_RPORT_ROLE_UNKNOWN)
fc_remote_port_rolechg(rport, rport_ids.roles);
lpfc_printf_vlog(ndlp->vport, KERN_INFO, LOG_NODE,
"3183 rport register x%06x, rport %p role x%x\n",
ndlp->nlp_DID, rport, rport_ids.roles);
if ((rport->scsi_target_id != -1) &&
(rport->scsi_target_id < LPFC_MAX_TARGET)) {
ndlp->nlp_sid = rport->scsi_target_id;
}
return;
}
static void
lpfc_unregister_remote_port(struct lpfc_nodelist *ndlp)
{
struct fc_rport *rport = ndlp->rport;
lpfc_debugfs_disc_trc(ndlp->vport, LPFC_DISC_TRC_RPORT,
"rport delete: did:x%x flg:x%x type x%x",
ndlp->nlp_DID, ndlp->nlp_flag, ndlp->nlp_type);
lpfc_printf_vlog(ndlp->vport, KERN_INFO, LOG_NODE,
"3184 rport unregister x%06x, rport %p\n",
ndlp->nlp_DID, rport);
fc_remote_port_delete(rport);
return;
}
static void
lpfc_nlp_counters(struct lpfc_vport *vport, int state, int count)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
spin_lock_irq(shost->host_lock);
switch (state) {
case NLP_STE_UNUSED_NODE:
vport->fc_unused_cnt += count;
break;
case NLP_STE_PLOGI_ISSUE:
vport->fc_plogi_cnt += count;
break;
case NLP_STE_ADISC_ISSUE:
vport->fc_adisc_cnt += count;
break;
case NLP_STE_REG_LOGIN_ISSUE:
vport->fc_reglogin_cnt += count;
break;
case NLP_STE_PRLI_ISSUE:
vport->fc_prli_cnt += count;
break;
case NLP_STE_UNMAPPED_NODE:
vport->fc_unmap_cnt += count;
break;
case NLP_STE_MAPPED_NODE:
vport->fc_map_cnt += count;
break;
case NLP_STE_NPR_NODE:
if (vport->fc_npr_cnt == 0 && count == -1)
vport->fc_npr_cnt = 0;
else
vport->fc_npr_cnt += count;
break;
}
spin_unlock_irq(shost->host_lock);
}
static void
lpfc_nlp_state_cleanup(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
int old_state, int new_state)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
if (new_state == NLP_STE_UNMAPPED_NODE) {
ndlp->nlp_flag &= ~NLP_NODEV_REMOVE;
ndlp->nlp_type |= NLP_FC_NODE;
}
if (new_state == NLP_STE_MAPPED_NODE)
ndlp->nlp_flag &= ~NLP_NODEV_REMOVE;
if (new_state == NLP_STE_NPR_NODE)
ndlp->nlp_flag &= ~NLP_RCV_PLOGI;
if (ndlp->rport && (old_state == NLP_STE_MAPPED_NODE ||
old_state == NLP_STE_UNMAPPED_NODE)) {
vport->phba->nport_event_cnt++;
lpfc_unregister_remote_port(ndlp);
}
if (new_state == NLP_STE_MAPPED_NODE ||
new_state == NLP_STE_UNMAPPED_NODE) {
vport->phba->nport_event_cnt++;
lpfc_register_remote_port(vport, ndlp);
}
if ((new_state == NLP_STE_MAPPED_NODE) &&
(vport->stat_data_enabled)) {
ndlp->lat_data = kcalloc(LPFC_MAX_BUCKET_COUNT,
sizeof(struct lpfc_scsicmd_bkt),
GFP_KERNEL);
if (!ndlp->lat_data)
lpfc_printf_vlog(vport, KERN_ERR, LOG_NODE,
"0286 lpfc_nlp_state_cleanup failed to "
"allocate statistical data buffer DID "
"0x%x\n", ndlp->nlp_DID);
}
if (new_state == NLP_STE_MAPPED_NODE &&
(!ndlp->rport ||
ndlp->rport->scsi_target_id == -1 ||
ndlp->rport->scsi_target_id >= LPFC_MAX_TARGET)) {
spin_lock_irq(shost->host_lock);
ndlp->nlp_flag |= NLP_TGT_NO_SCSIID;
spin_unlock_irq(shost->host_lock);
lpfc_nlp_set_state(vport, ndlp, NLP_STE_UNMAPPED_NODE);
}
}
static char *
lpfc_nlp_state_name(char *buffer, size_t size, int state)
{
static char *states[] = {
[NLP_STE_UNUSED_NODE] = "UNUSED",
[NLP_STE_PLOGI_ISSUE] = "PLOGI",
[NLP_STE_ADISC_ISSUE] = "ADISC",
[NLP_STE_REG_LOGIN_ISSUE] = "REGLOGIN",
[NLP_STE_PRLI_ISSUE] = "PRLI",
[NLP_STE_LOGO_ISSUE] = "LOGO",
[NLP_STE_UNMAPPED_NODE] = "UNMAPPED",
[NLP_STE_MAPPED_NODE] = "MAPPED",
[NLP_STE_NPR_NODE] = "NPR",
};
if (state < NLP_STE_MAX_STATE && states[state])
strlcpy(buffer, states[state], size);
else
snprintf(buffer, size, "unknown (%d)", state);
return buffer;
}
void
lpfc_nlp_set_state(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
int state)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
int old_state = ndlp->nlp_state;
char name1[16], name2[16];
lpfc_printf_vlog(vport, KERN_INFO, LOG_NODE,
"0904 NPort state transition x%06x, %s -> %s\n",
ndlp->nlp_DID,
lpfc_nlp_state_name(name1, sizeof(name1), old_state),
lpfc_nlp_state_name(name2, sizeof(name2), state));
lpfc_debugfs_disc_trc(vport, LPFC_DISC_TRC_NODE,
"node statechg did:x%x old:%d ste:%d",
ndlp->nlp_DID, old_state, state);
if (old_state == NLP_STE_NPR_NODE &&
state != NLP_STE_NPR_NODE)
lpfc_cancel_retry_delay_tmo(vport, ndlp);
if (old_state == NLP_STE_UNMAPPED_NODE) {
ndlp->nlp_flag &= ~NLP_TGT_NO_SCSIID;
ndlp->nlp_type &= ~NLP_FC_NODE;
}
if (list_empty(&ndlp->nlp_listp)) {
spin_lock_irq(shost->host_lock);
list_add_tail(&ndlp->nlp_listp, &vport->fc_nodes);
spin_unlock_irq(shost->host_lock);
} else if (old_state)
lpfc_nlp_counters(vport, old_state, -1);
ndlp->nlp_state = state;
lpfc_nlp_counters(vport, state, 1);
lpfc_nlp_state_cleanup(vport, ndlp, old_state, state);
}
void
lpfc_enqueue_node(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
if (list_empty(&ndlp->nlp_listp)) {
spin_lock_irq(shost->host_lock);
list_add_tail(&ndlp->nlp_listp, &vport->fc_nodes);
spin_unlock_irq(shost->host_lock);
}
}
void
lpfc_dequeue_node(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
lpfc_cancel_retry_delay_tmo(vport, ndlp);
if (ndlp->nlp_state && !list_empty(&ndlp->nlp_listp))
lpfc_nlp_counters(vport, ndlp->nlp_state, -1);
spin_lock_irq(shost->host_lock);
list_del_init(&ndlp->nlp_listp);
spin_unlock_irq(shost->host_lock);
lpfc_nlp_state_cleanup(vport, ndlp, ndlp->nlp_state,
NLP_STE_UNUSED_NODE);
}
static void
lpfc_disable_node(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp)
{
lpfc_cancel_retry_delay_tmo(vport, ndlp);
if (ndlp->nlp_state && !list_empty(&ndlp->nlp_listp))
lpfc_nlp_counters(vport, ndlp->nlp_state, -1);
lpfc_nlp_state_cleanup(vport, ndlp, ndlp->nlp_state,
NLP_STE_UNUSED_NODE);
}
static inline void
lpfc_initialize_node(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
uint32_t did)
{
INIT_LIST_HEAD(&ndlp->els_retry_evt.evt_listp);
INIT_LIST_HEAD(&ndlp->dev_loss_evt.evt_listp);
init_timer(&ndlp->nlp_delayfunc);
ndlp->nlp_delayfunc.function = lpfc_els_retry_delay;
ndlp->nlp_delayfunc.data = (unsigned long)ndlp;
ndlp->nlp_DID = did;
ndlp->vport = vport;
ndlp->phba = vport->phba;
ndlp->nlp_sid = NLP_NO_SID;
kref_init(&ndlp->kref);
NLP_INT_NODE_ACT(ndlp);
atomic_set(&ndlp->cmd_pending, 0);
ndlp->cmd_qdepth = vport->cfg_tgt_queue_depth;
}
struct lpfc_nodelist *
lpfc_enable_node(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
int state)
{
struct lpfc_hba *phba = vport->phba;
uint32_t did;
unsigned long flags;
unsigned long *active_rrqs_xri_bitmap = NULL;
if (!ndlp)
return NULL;
spin_lock_irqsave(&phba->ndlp_lock, flags);
if (NLP_CHK_FREE_REQ(ndlp)) {
spin_unlock_irqrestore(&phba->ndlp_lock, flags);
lpfc_printf_vlog(vport, KERN_WARNING, LOG_NODE,
"0277 lpfc_enable_node: ndlp:x%p "
"usgmap:x%x refcnt:%d\n",
(void *)ndlp, ndlp->nlp_usg_map,
atomic_read(&ndlp->kref.refcount));
return NULL;
}
if (NLP_CHK_NODE_ACT(ndlp)) {
spin_unlock_irqrestore(&phba->ndlp_lock, flags);
lpfc_printf_vlog(vport, KERN_WARNING, LOG_NODE,
"0278 lpfc_enable_node: ndlp:x%p "
"usgmap:x%x refcnt:%d\n",
(void *)ndlp, ndlp->nlp_usg_map,
atomic_read(&ndlp->kref.refcount));
return NULL;
}
did = ndlp->nlp_DID;
if (phba->sli_rev == LPFC_SLI_REV4)
active_rrqs_xri_bitmap = ndlp->active_rrqs_xri_bitmap;
memset((((char *)ndlp) + sizeof (struct list_head)), 0,
sizeof (struct lpfc_nodelist) - sizeof (struct list_head));
lpfc_initialize_node(vport, ndlp, did);
if (phba->sli_rev == LPFC_SLI_REV4)
ndlp->active_rrqs_xri_bitmap = active_rrqs_xri_bitmap;
spin_unlock_irqrestore(&phba->ndlp_lock, flags);
if (vport->phba->sli_rev == LPFC_SLI_REV4)
ndlp->nlp_rpi = lpfc_sli4_alloc_rpi(vport->phba);
if (state != NLP_STE_UNUSED_NODE)
lpfc_nlp_set_state(vport, ndlp, state);
lpfc_debugfs_disc_trc(vport, LPFC_DISC_TRC_NODE,
"node enable: did:x%x",
ndlp->nlp_DID, 0, 0);
return ndlp;
}
void
lpfc_drop_node(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp)
{
if (ndlp->nlp_state == NLP_STE_UNUSED_NODE)
return;
lpfc_nlp_set_state(vport, ndlp, NLP_STE_UNUSED_NODE);
if (vport->phba->sli_rev == LPFC_SLI_REV4)
lpfc_cleanup_vports_rrqs(vport, ndlp);
lpfc_nlp_put(ndlp);
return;
}
void
lpfc_set_disctmo(struct lpfc_vport *vport)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
struct lpfc_hba *phba = vport->phba;
uint32_t tmo;
if (vport->port_state == LPFC_LOCAL_CFG_LINK) {
tmo = (((phba->fc_edtov + 999) / 1000) + 1);
} else {
tmo = ((phba->fc_ratov * 3) + 3);
}
if (!timer_pending(&vport->fc_disctmo)) {
lpfc_debugfs_disc_trc(vport, LPFC_DISC_TRC_ELS_CMD,
"set disc timer: tmo:x%x state:x%x flg:x%x",
tmo, vport->port_state, vport->fc_flag);
}
mod_timer(&vport->fc_disctmo, jiffies + msecs_to_jiffies(1000 * tmo));
spin_lock_irq(shost->host_lock);
vport->fc_flag |= FC_DISC_TMO;
spin_unlock_irq(shost->host_lock);
lpfc_printf_vlog(vport, KERN_INFO, LOG_DISCOVERY,
"0247 Start Discovery Timer state x%x "
"Data: x%x x%lx x%x x%x\n",
vport->port_state, tmo,
(unsigned long)&vport->fc_disctmo, vport->fc_plogi_cnt,
vport->fc_adisc_cnt);
return;
}
int
lpfc_can_disctmo(struct lpfc_vport *vport)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
unsigned long iflags;
lpfc_debugfs_disc_trc(vport, LPFC_DISC_TRC_ELS_CMD,
"can disc timer: state:x%x rtry:x%x flg:x%x",
vport->port_state, vport->fc_ns_retry, vport->fc_flag);
if (vport->fc_flag & FC_DISC_TMO) {
spin_lock_irqsave(shost->host_lock, iflags);
vport->fc_flag &= ~FC_DISC_TMO;
spin_unlock_irqrestore(shost->host_lock, iflags);
del_timer_sync(&vport->fc_disctmo);
spin_lock_irqsave(&vport->work_port_lock, iflags);
vport->work_port_events &= ~WORKER_DISC_TMO;
spin_unlock_irqrestore(&vport->work_port_lock, iflags);
}
lpfc_printf_vlog(vport, KERN_INFO, LOG_DISCOVERY,
"0248 Cancel Discovery Timer state x%x "
"Data: x%x x%x x%x\n",
vport->port_state, vport->fc_flag,
vport->fc_plogi_cnt, vport->fc_adisc_cnt);
return 0;
}
int
lpfc_check_sli_ndlp(struct lpfc_hba *phba,
struct lpfc_sli_ring *pring,
struct lpfc_iocbq *iocb,
struct lpfc_nodelist *ndlp)
{
struct lpfc_sli *psli = &phba->sli;
IOCB_t *icmd = &iocb->iocb;
struct lpfc_vport *vport = ndlp->vport;
if (iocb->vport != vport)
return 0;
if (pring->ringno == LPFC_ELS_RING) {
switch (icmd->ulpCommand) {
case CMD_GEN_REQUEST64_CR:
if (iocb->context_un.ndlp == ndlp)
return 1;
case CMD_ELS_REQUEST64_CR:
if (icmd->un.elsreq64.remoteID == ndlp->nlp_DID)
return 1;
case CMD_XMIT_ELS_RSP64_CX:
if (iocb->context1 == (uint8_t *) ndlp)
return 1;
}
} else if (pring->ringno == psli->extra_ring) {
} else if (pring->ringno == psli->fcp_ring) {
if ((ndlp->nlp_type & NLP_FCP_TARGET) &&
(ndlp->nlp_flag & NLP_DELAY_TMO)) {
return 0;
}
if (icmd->ulpContext == (volatile ushort)ndlp->nlp_rpi) {
return 1;
}
} else if (pring->ringno == psli->next_ring) {
}
return 0;
}
static int
lpfc_no_rpi(struct lpfc_hba *phba, struct lpfc_nodelist *ndlp)
{
LIST_HEAD(completions);
struct lpfc_sli *psli;
struct lpfc_sli_ring *pring;
struct lpfc_iocbq *iocb, *next_iocb;
uint32_t i;
lpfc_fabric_abort_nport(ndlp);
psli = &phba->sli;
if (ndlp->nlp_flag & NLP_RPI_REGISTERED) {
for (i = 0; i < psli->num_rings; i++) {
pring = &psli->ring[i];
spin_lock_irq(&phba->hbalock);
list_for_each_entry_safe(iocb, next_iocb, &pring->txq,
list) {
if ((lpfc_check_sli_ndlp(phba, pring, iocb,
ndlp))) {
list_move_tail(&iocb->list,
&completions);
}
}
spin_unlock_irq(&phba->hbalock);
}
}
lpfc_sli_cancel_iocbs(phba, &completions, IOSTAT_LOCAL_REJECT,
IOERR_SLI_ABORTED);
return 0;
}
void
lpfc_nlp_logo_unreg(struct lpfc_hba *phba, LPFC_MBOXQ_t *pmb)
{
struct lpfc_vport *vport = pmb->vport;
struct lpfc_nodelist *ndlp;
ndlp = (struct lpfc_nodelist *)(pmb->context1);
if (!ndlp)
return;
lpfc_issue_els_logo(vport, ndlp, 0);
mempool_free(pmb, phba->mbox_mem_pool);
}
int
lpfc_unreg_rpi(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp)
{
struct lpfc_hba *phba = vport->phba;
LPFC_MBOXQ_t *mbox;
int rc;
uint16_t rpi;
if (ndlp->nlp_flag & NLP_RPI_REGISTERED ||
ndlp->nlp_flag & NLP_REG_LOGIN_SEND) {
if (ndlp->nlp_flag & NLP_REG_LOGIN_SEND)
lpfc_printf_vlog(vport, KERN_INFO, LOG_SLI,
"3366 RPI x%x needs to be "
"unregistered nlp_flag x%x "
"did x%x\n",
ndlp->nlp_rpi, ndlp->nlp_flag,
ndlp->nlp_DID);
mbox = mempool_alloc(phba->mbox_mem_pool, GFP_KERNEL);
if (mbox) {
rpi = ndlp->nlp_rpi;
if (phba->sli_rev == LPFC_SLI_REV4)
rpi = phba->sli4_hba.rpi_ids[ndlp->nlp_rpi];
lpfc_unreg_login(phba, vport->vpi, rpi, mbox);
mbox->vport = vport;
if (ndlp->nlp_flag & NLP_ISSUE_LOGO) {
mbox->context1 = ndlp;
mbox->mbox_cmpl = lpfc_nlp_logo_unreg;
} else {
mbox->mbox_cmpl = lpfc_sli_def_mbox_cmpl;
}
rc = lpfc_sli_issue_mbox(phba, mbox, MBX_NOWAIT);
if (rc == MBX_NOT_FINISHED)
mempool_free(mbox, phba->mbox_mem_pool);
}
lpfc_no_rpi(phba, ndlp);
if (phba->sli_rev != LPFC_SLI_REV4)
ndlp->nlp_rpi = 0;
ndlp->nlp_flag &= ~NLP_RPI_REGISTERED;
ndlp->nlp_flag &= ~NLP_NPR_ADISC;
return 1;
}
return 0;
}
void
lpfc_unreg_hba_rpis(struct lpfc_hba *phba)
{
struct lpfc_vport **vports;
struct lpfc_nodelist *ndlp;
struct Scsi_Host *shost;
int i;
vports = lpfc_create_vport_work_array(phba);
if (!vports) {
lpfc_printf_log(phba, KERN_ERR, LOG_DISCOVERY,
"2884 Vport array allocation failed \n");
return;
}
for (i = 0; i <= phba->max_vports && vports[i] != NULL; i++) {
shost = lpfc_shost_from_vport(vports[i]);
spin_lock_irq(shost->host_lock);
list_for_each_entry(ndlp, &vports[i]->fc_nodes, nlp_listp) {
if (ndlp->nlp_flag & NLP_RPI_REGISTERED) {
spin_unlock_irq(shost->host_lock);
lpfc_unreg_rpi(vports[i], ndlp);
spin_lock_irq(shost->host_lock);
}
}
spin_unlock_irq(shost->host_lock);
}
lpfc_destroy_vport_work_array(phba, vports);
}
void
lpfc_unreg_all_rpis(struct lpfc_vport *vport)
{
struct lpfc_hba *phba = vport->phba;
LPFC_MBOXQ_t *mbox;
int rc;
if (phba->sli_rev == LPFC_SLI_REV4) {
lpfc_sli4_unreg_all_rpis(vport);
return;
}
mbox = mempool_alloc(phba->mbox_mem_pool, GFP_KERNEL);
if (mbox) {
lpfc_unreg_login(phba, vport->vpi, LPFC_UNREG_ALL_RPIS_VPORT,
mbox);
mbox->vport = vport;
mbox->mbox_cmpl = lpfc_sli_def_mbox_cmpl;
mbox->context1 = NULL;
rc = lpfc_sli_issue_mbox_wait(phba, mbox, LPFC_MBOX_TMO);
if (rc != MBX_TIMEOUT)
mempool_free(mbox, phba->mbox_mem_pool);
if ((rc == MBX_TIMEOUT) || (rc == MBX_NOT_FINISHED))
lpfc_printf_vlog(vport, KERN_ERR, LOG_MBOX | LOG_VPORT,
"1836 Could not issue "
"unreg_login(all_rpis) status %d\n", rc);
}
}
void
lpfc_unreg_default_rpis(struct lpfc_vport *vport)
{
struct lpfc_hba *phba = vport->phba;
LPFC_MBOXQ_t *mbox;
int rc;
mbox = mempool_alloc(phba->mbox_mem_pool, GFP_KERNEL);
if (mbox) {
lpfc_unreg_did(phba, vport->vpi, LPFC_UNREG_ALL_DFLT_RPIS,
mbox);
mbox->vport = vport;
mbox->mbox_cmpl = lpfc_sli_def_mbox_cmpl;
mbox->context1 = NULL;
rc = lpfc_sli_issue_mbox_wait(phba, mbox, LPFC_MBOX_TMO);
if (rc != MBX_TIMEOUT)
mempool_free(mbox, phba->mbox_mem_pool);
if ((rc == MBX_TIMEOUT) || (rc == MBX_NOT_FINISHED))
lpfc_printf_vlog(vport, KERN_ERR, LOG_MBOX | LOG_VPORT,
"1815 Could not issue "
"unreg_did (default rpis) status %d\n",
rc);
}
}
static int
lpfc_cleanup_node(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
struct lpfc_hba *phba = vport->phba;
LPFC_MBOXQ_t *mb, *nextmb;
struct lpfc_dmabuf *mp;
lpfc_printf_vlog(vport, KERN_INFO, LOG_NODE,
"0900 Cleanup node for NPort x%x "
"Data: x%x x%x x%x\n",
ndlp->nlp_DID, ndlp->nlp_flag,
ndlp->nlp_state, ndlp->nlp_rpi);
if (NLP_CHK_FREE_REQ(ndlp)) {
lpfc_printf_vlog(vport, KERN_WARNING, LOG_NODE,
"0280 lpfc_cleanup_node: ndlp:x%p "
"usgmap:x%x refcnt:%d\n",
(void *)ndlp, ndlp->nlp_usg_map,
atomic_read(&ndlp->kref.refcount));
lpfc_dequeue_node(vport, ndlp);
} else {
lpfc_printf_vlog(vport, KERN_WARNING, LOG_NODE,
"0281 lpfc_cleanup_node: ndlp:x%p "
"usgmap:x%x refcnt:%d\n",
(void *)ndlp, ndlp->nlp_usg_map,
atomic_read(&ndlp->kref.refcount));
lpfc_disable_node(vport, ndlp);
}
if ((mb = phba->sli.mbox_active)) {
if ((mb->u.mb.mbxCommand == MBX_REG_LOGIN64) &&
!(mb->mbox_flag & LPFC_MBX_IMED_UNREG) &&
(ndlp == (struct lpfc_nodelist *) mb->context2)) {
mb->context2 = NULL;
mb->mbox_cmpl = lpfc_sli_def_mbox_cmpl;
}
}
spin_lock_irq(&phba->hbalock);
list_for_each_entry(mb, &phba->sli.mboxq_cmpl, list) {
if ((mb->u.mb.mbxCommand != MBX_REG_LOGIN64) ||
(mb->mbox_flag & LPFC_MBX_IMED_UNREG) ||
(ndlp != (struct lpfc_nodelist *) mb->context2))
continue;
mb->context2 = NULL;
mb->mbox_cmpl = lpfc_sli_def_mbox_cmpl;
}
list_for_each_entry_safe(mb, nextmb, &phba->sli.mboxq, list) {
if ((mb->u.mb.mbxCommand == MBX_REG_LOGIN64) &&
!(mb->mbox_flag & LPFC_MBX_IMED_UNREG) &&
(ndlp == (struct lpfc_nodelist *) mb->context2)) {
mp = (struct lpfc_dmabuf *) (mb->context1);
if (mp) {
__lpfc_mbuf_free(phba, mp->virt, mp->phys);
kfree(mp);
}
list_del(&mb->list);
mempool_free(mb, phba->mbox_mem_pool);
}
}
spin_unlock_irq(&phba->hbalock);
lpfc_els_abort(phba, ndlp);
spin_lock_irq(shost->host_lock);
ndlp->nlp_flag &= ~NLP_DELAY_TMO;
spin_unlock_irq(shost->host_lock);
ndlp->nlp_last_elscmd = 0;
del_timer_sync(&ndlp->nlp_delayfunc);
list_del_init(&ndlp->els_retry_evt.evt_listp);
list_del_init(&ndlp->dev_loss_evt.evt_listp);
lpfc_cleanup_vports_rrqs(vport, ndlp);
lpfc_unreg_rpi(vport, ndlp);
return 0;
}
static void
lpfc_nlp_remove(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp)
{
struct lpfc_hba *phba = vport->phba;
struct lpfc_rport_data *rdata;
LPFC_MBOXQ_t *mbox;
int rc;
lpfc_cancel_retry_delay_tmo(vport, ndlp);
if ((ndlp->nlp_flag & NLP_DEFER_RM) &&
!(ndlp->nlp_flag & NLP_REG_LOGIN_SEND) &&
!(ndlp->nlp_flag & NLP_RPI_REGISTERED)) {
if ((mbox = mempool_alloc(phba->mbox_mem_pool, GFP_KERNEL))
!= NULL) {
rc = lpfc_reg_rpi(phba, vport->vpi, ndlp->nlp_DID,
(uint8_t *) &vport->fc_sparam, mbox, ndlp->nlp_rpi);
if (rc) {
mempool_free(mbox, phba->mbox_mem_pool);
}
else {
mbox->mbox_flag |= LPFC_MBX_IMED_UNREG;
mbox->mbox_cmpl = lpfc_mbx_cmpl_dflt_rpi;
mbox->vport = vport;
mbox->context2 = ndlp;
rc =lpfc_sli_issue_mbox(phba, mbox, MBX_NOWAIT);
if (rc == MBX_NOT_FINISHED) {
mempool_free(mbox, phba->mbox_mem_pool);
}
}
}
}
lpfc_cleanup_node(vport, ndlp);
if (ndlp->rport) {
rdata = ndlp->rport->dd_data;
rdata->pnode = NULL;
ndlp->rport = NULL;
}
}
static int
lpfc_matchdid(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
uint32_t did)
{
D_ID mydid, ndlpdid, matchdid;
if (did == Bcast_DID)
return 0;
if (ndlp->nlp_DID == did)
return 1;
mydid.un.word = vport->fc_myDID;
if ((mydid.un.b.domain == 0) && (mydid.un.b.area == 0)) {
return 0;
}
matchdid.un.word = did;
ndlpdid.un.word = ndlp->nlp_DID;
if (matchdid.un.b.id == ndlpdid.un.b.id) {
if ((mydid.un.b.domain == matchdid.un.b.domain) &&
(mydid.un.b.area == matchdid.un.b.area)) {
if ((ndlpdid.un.b.domain == 0) &&
(ndlpdid.un.b.area == 0)) {
if (ndlpdid.un.b.id)
return 1;
}
return 0;
}
matchdid.un.word = ndlp->nlp_DID;
if ((mydid.un.b.domain == ndlpdid.un.b.domain) &&
(mydid.un.b.area == ndlpdid.un.b.area)) {
if ((matchdid.un.b.domain == 0) &&
(matchdid.un.b.area == 0)) {
if (matchdid.un.b.id)
return 1;
}
}
}
return 0;
}
static struct lpfc_nodelist *
__lpfc_findnode_did(struct lpfc_vport *vport, uint32_t did)
{
struct lpfc_nodelist *ndlp;
uint32_t data1;
list_for_each_entry(ndlp, &vport->fc_nodes, nlp_listp) {
if (lpfc_matchdid(vport, ndlp, did)) {
data1 = (((uint32_t) ndlp->nlp_state << 24) |
((uint32_t) ndlp->nlp_xri << 16) |
((uint32_t) ndlp->nlp_type << 8) |
((uint32_t) ndlp->nlp_rpi & 0xff));
lpfc_printf_vlog(vport, KERN_INFO, LOG_NODE,
"0929 FIND node DID "
"Data: x%p x%x x%x x%x %p\n",
ndlp, ndlp->nlp_DID,
ndlp->nlp_flag, data1,
ndlp->active_rrqs_xri_bitmap);
return ndlp;
}
}
lpfc_printf_vlog(vport, KERN_INFO, LOG_NODE,
"0932 FIND node did x%x NOT FOUND.\n", did);
return NULL;
}
struct lpfc_nodelist *
lpfc_findnode_did(struct lpfc_vport *vport, uint32_t did)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
struct lpfc_nodelist *ndlp;
unsigned long iflags;
spin_lock_irqsave(shost->host_lock, iflags);
ndlp = __lpfc_findnode_did(vport, did);
spin_unlock_irqrestore(shost->host_lock, iflags);
return ndlp;
}
struct lpfc_nodelist *
lpfc_setup_disc_node(struct lpfc_vport *vport, uint32_t did)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
struct lpfc_nodelist *ndlp;
ndlp = lpfc_findnode_did(vport, did);
if (!ndlp) {
if ((vport->fc_flag & FC_RSCN_MODE) != 0 &&
lpfc_rscn_payload_check(vport, did) == 0)
return NULL;
ndlp = (struct lpfc_nodelist *)
mempool_alloc(vport->phba->nlp_mem_pool, GFP_KERNEL);
if (!ndlp)
return NULL;
lpfc_nlp_init(vport, ndlp, did);
lpfc_nlp_set_state(vport, ndlp, NLP_STE_NPR_NODE);
spin_lock_irq(shost->host_lock);
ndlp->nlp_flag |= NLP_NPR_2B_DISC;
spin_unlock_irq(shost->host_lock);
return ndlp;
} else if (!NLP_CHK_NODE_ACT(ndlp)) {
ndlp = lpfc_enable_node(vport, ndlp, NLP_STE_NPR_NODE);
if (!ndlp)
return NULL;
spin_lock_irq(shost->host_lock);
ndlp->nlp_flag |= NLP_NPR_2B_DISC;
spin_unlock_irq(shost->host_lock);
return ndlp;
}
if ((vport->fc_flag & FC_RSCN_MODE) &&
!(vport->fc_flag & FC_NDISC_ACTIVE)) {
if (lpfc_rscn_payload_check(vport, did)) {
if (ndlp->nlp_flag & NLP_RCV_PLOGI)
return NULL;
lpfc_cancel_retry_delay_tmo(vport, ndlp);
spin_lock_irq(shost->host_lock);
ndlp->nlp_flag |= NLP_NPR_2B_DISC;
spin_unlock_irq(shost->host_lock);
} else
ndlp = NULL;
} else {
if (ndlp->nlp_state == NLP_STE_ADISC_ISSUE ||
ndlp->nlp_state == NLP_STE_PLOGI_ISSUE ||
ndlp->nlp_flag & NLP_RCV_PLOGI)
return NULL;
lpfc_nlp_set_state(vport, ndlp, NLP_STE_NPR_NODE);
spin_lock_irq(shost->host_lock);
ndlp->nlp_flag |= NLP_NPR_2B_DISC;
spin_unlock_irq(shost->host_lock);
}
return ndlp;
}
void
lpfc_disc_list_loopmap(struct lpfc_vport *vport)
{
struct lpfc_hba *phba = vport->phba;
int j;
uint32_t alpa, index;
if (!lpfc_is_link_up(phba))
return;
if (phba->fc_topology != LPFC_TOPOLOGY_LOOP)
return;
if (phba->alpa_map[0]) {
for (j = 1; j <= phba->alpa_map[0]; j++) {
alpa = phba->alpa_map[j];
if (((vport->fc_myDID & 0xff) == alpa) || (alpa == 0))
continue;
lpfc_setup_disc_node(vport, alpa);
}
} else {
for (j = 0; j < FC_MAXLOOP; j++) {
if (vport->cfg_scan_down)
index = j;
else
index = FC_MAXLOOP - j - 1;
alpa = lpfcAlpaArray[index];
if ((vport->fc_myDID & 0xff) == alpa)
continue;
lpfc_setup_disc_node(vport, alpa);
}
}
return;
}
void
lpfc_issue_clear_la(struct lpfc_hba *phba, struct lpfc_vport *vport)
{
LPFC_MBOXQ_t *mbox;
struct lpfc_sli *psli = &phba->sli;
struct lpfc_sli_ring *extra_ring = &psli->ring[psli->extra_ring];
struct lpfc_sli_ring *fcp_ring = &psli->ring[psli->fcp_ring];
struct lpfc_sli_ring *next_ring = &psli->ring[psli->next_ring];
int rc;
if ((phba->link_state >= LPFC_CLEAR_LA) ||
(vport->port_type != LPFC_PHYSICAL_PORT) ||
(phba->sli_rev == LPFC_SLI_REV4))
return;
if ((mbox = mempool_alloc(phba->mbox_mem_pool, GFP_KERNEL)) != NULL) {
phba->link_state = LPFC_CLEAR_LA;
lpfc_clear_la(phba, mbox);
mbox->mbox_cmpl = lpfc_mbx_cmpl_clear_la;
mbox->vport = vport;
rc = lpfc_sli_issue_mbox(phba, mbox, MBX_NOWAIT);
if (rc == MBX_NOT_FINISHED) {
mempool_free(mbox, phba->mbox_mem_pool);
lpfc_disc_flush_list(vport);
extra_ring->flag &= ~LPFC_STOP_IOCB_EVENT;
fcp_ring->flag &= ~LPFC_STOP_IOCB_EVENT;
next_ring->flag &= ~LPFC_STOP_IOCB_EVENT;
phba->link_state = LPFC_HBA_ERROR;
}
}
}
void
lpfc_issue_reg_vpi(struct lpfc_hba *phba, struct lpfc_vport *vport)
{
LPFC_MBOXQ_t *regvpimbox;
regvpimbox = mempool_alloc(phba->mbox_mem_pool, GFP_KERNEL);
if (regvpimbox) {
lpfc_reg_vpi(vport, regvpimbox);
regvpimbox->mbox_cmpl = lpfc_mbx_cmpl_reg_vpi;
regvpimbox->vport = vport;
if (lpfc_sli_issue_mbox(phba, regvpimbox, MBX_NOWAIT)
== MBX_NOT_FINISHED) {
mempool_free(regvpimbox, phba->mbox_mem_pool);
}
}
}
void
lpfc_disc_start(struct lpfc_vport *vport)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
struct lpfc_hba *phba = vport->phba;
uint32_t num_sent;
uint32_t clear_la_pending;
int did_changed;
if (!lpfc_is_link_up(phba)) {
lpfc_printf_vlog(vport, KERN_INFO, LOG_SLI,
"3315 Link is not up %x\n",
phba->link_state);
return;
}
if (phba->link_state == LPFC_CLEAR_LA)
clear_la_pending = 1;
else
clear_la_pending = 0;
if (vport->port_state < LPFC_VPORT_READY)
vport->port_state = LPFC_DISC_AUTH;
lpfc_set_disctmo(vport);
if (vport->fc_prevDID == vport->fc_myDID)
did_changed = 0;
else
did_changed = 1;
vport->fc_prevDID = vport->fc_myDID;
vport->num_disc_nodes = 0;
lpfc_printf_vlog(vport, KERN_INFO, LOG_DISCOVERY,
"0202 Start Discovery hba state x%x "
"Data: x%x x%x x%x\n",
vport->port_state, vport->fc_flag, vport->fc_plogi_cnt,
vport->fc_adisc_cnt);
num_sent = lpfc_els_disc_adisc(vport);
if (num_sent)
return;
if ((phba->sli3_options & LPFC_SLI3_NPIV_ENABLED) &&
!(vport->fc_flag & FC_PT2PT) &&
!(vport->fc_flag & FC_RSCN_MODE) &&
(phba->sli_rev < LPFC_SLI_REV4)) {
if (vport->port_type == LPFC_PHYSICAL_PORT)
lpfc_issue_clear_la(phba, vport);
lpfc_issue_reg_vpi(phba, vport);
return;
}
if (vport->port_state < LPFC_VPORT_READY && !clear_la_pending) {
if (vport->port_type == LPFC_PHYSICAL_PORT)
lpfc_issue_clear_la(phba, vport);
if (!(vport->fc_flag & FC_ABORT_DISCOVERY)) {
vport->num_disc_nodes = 0;
if (vport->fc_npr_cnt)
lpfc_els_disc_plogi(vport);
if (!vport->num_disc_nodes) {
spin_lock_irq(shost->host_lock);
vport->fc_flag &= ~FC_NDISC_ACTIVE;
spin_unlock_irq(shost->host_lock);
lpfc_can_disctmo(vport);
}
}
vport->port_state = LPFC_VPORT_READY;
} else {
num_sent = lpfc_els_disc_plogi(vport);
if (num_sent)
return;
if (vport->fc_flag & FC_RSCN_MODE) {
if ((vport->fc_rscn_id_cnt == 0) &&
(!(vport->fc_flag & FC_RSCN_DISCOVERY))) {
spin_lock_irq(shost->host_lock);
vport->fc_flag &= ~FC_RSCN_MODE;
spin_unlock_irq(shost->host_lock);
lpfc_can_disctmo(vport);
} else
lpfc_els_handle_rscn(vport);
}
}
return;
}
static void
lpfc_free_tx(struct lpfc_hba *phba, struct lpfc_nodelist *ndlp)
{
LIST_HEAD(completions);
struct lpfc_sli *psli;
IOCB_t *icmd;
struct lpfc_iocbq *iocb, *next_iocb;
struct lpfc_sli_ring *pring;
psli = &phba->sli;
pring = &psli->ring[LPFC_ELS_RING];
spin_lock_irq(&phba->hbalock);
list_for_each_entry_safe(iocb, next_iocb, &pring->txq, list) {
if (iocb->context1 != ndlp) {
continue;
}
icmd = &iocb->iocb;
if ((icmd->ulpCommand == CMD_ELS_REQUEST64_CR) ||
(icmd->ulpCommand == CMD_XMIT_ELS_RSP64_CX)) {
list_move_tail(&iocb->list, &completions);
}
}
list_for_each_entry_safe(iocb, next_iocb, &pring->txcmplq, list) {
if (iocb->context1 != ndlp) {
continue;
}
icmd = &iocb->iocb;
if (icmd->ulpCommand == CMD_ELS_REQUEST64_CR ||
icmd->ulpCommand == CMD_XMIT_ELS_RSP64_CX) {
lpfc_sli_issue_abort_iotag(phba, pring, iocb);
}
}
spin_unlock_irq(&phba->hbalock);
lpfc_sli_cancel_iocbs(phba, &completions, IOSTAT_LOCAL_REJECT,
IOERR_SLI_ABORTED);
}
static void
lpfc_disc_flush_list(struct lpfc_vport *vport)
{
struct lpfc_nodelist *ndlp, *next_ndlp;
struct lpfc_hba *phba = vport->phba;
if (vport->fc_plogi_cnt || vport->fc_adisc_cnt) {
list_for_each_entry_safe(ndlp, next_ndlp, &vport->fc_nodes,
nlp_listp) {
if (!NLP_CHK_NODE_ACT(ndlp))
continue;
if (ndlp->nlp_state == NLP_STE_PLOGI_ISSUE ||
ndlp->nlp_state == NLP_STE_ADISC_ISSUE) {
lpfc_free_tx(phba, ndlp);
}
}
}
}
void
lpfc_cleanup_discovery_resources(struct lpfc_vport *vport)
{
lpfc_els_flush_rscn(vport);
lpfc_els_flush_cmd(vport);
lpfc_disc_flush_list(vport);
}
void
lpfc_disc_timeout(unsigned long ptr)
{
struct lpfc_vport *vport = (struct lpfc_vport *) ptr;
struct lpfc_hba *phba = vport->phba;
uint32_t tmo_posted;
unsigned long flags = 0;
if (unlikely(!phba))
return;
spin_lock_irqsave(&vport->work_port_lock, flags);
tmo_posted = vport->work_port_events & WORKER_DISC_TMO;
if (!tmo_posted)
vport->work_port_events |= WORKER_DISC_TMO;
spin_unlock_irqrestore(&vport->work_port_lock, flags);
if (!tmo_posted)
lpfc_worker_wake_up(phba);
return;
}
static void
lpfc_disc_timeout_handler(struct lpfc_vport *vport)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
struct lpfc_hba *phba = vport->phba;
struct lpfc_sli *psli = &phba->sli;
struct lpfc_nodelist *ndlp, *next_ndlp;
LPFC_MBOXQ_t *initlinkmbox;
int rc, clrlaerr = 0;
if (!(vport->fc_flag & FC_DISC_TMO))
return;
spin_lock_irq(shost->host_lock);
vport->fc_flag &= ~FC_DISC_TMO;
spin_unlock_irq(shost->host_lock);
lpfc_debugfs_disc_trc(vport, LPFC_DISC_TRC_ELS_CMD,
"disc timeout: state:x%x rtry:x%x flg:x%x",
vport->port_state, vport->fc_ns_retry, vport->fc_flag);
switch (vport->port_state) {
case LPFC_LOCAL_CFG_LINK:
lpfc_printf_vlog(vport, KERN_WARNING, LOG_DISCOVERY,
"0221 FAN timeout\n");
list_for_each_entry_safe(ndlp, next_ndlp, &vport->fc_nodes,
nlp_listp) {
if (!NLP_CHK_NODE_ACT(ndlp))
continue;
if (ndlp->nlp_state != NLP_STE_NPR_NODE)
continue;
if (ndlp->nlp_type & NLP_FABRIC) {
lpfc_drop_node(vport, ndlp);
} else if (!(ndlp->nlp_flag & NLP_NPR_ADISC)) {
lpfc_unreg_rpi(vport, ndlp);
}
}
if (vport->port_state != LPFC_FLOGI) {
if (phba->sli_rev <= LPFC_SLI_REV3)
lpfc_initial_flogi(vport);
else
lpfc_issue_init_vfi(vport);
return;
}
break;
case LPFC_FDISC:
case LPFC_FLOGI:
lpfc_printf_vlog(vport, KERN_ERR, LOG_DISCOVERY,
"0222 Initial %s timeout\n",
vport->vpi ? "FDISC" : "FLOGI");
lpfc_disc_list_loopmap(vport);
lpfc_disc_start(vport);
break;
case LPFC_FABRIC_CFG_LINK:
lpfc_printf_vlog(vport, KERN_ERR, LOG_DISCOVERY,
"0223 Timeout while waiting for "
"NameServer login\n");
ndlp = lpfc_findnode_did(vport, NameServer_DID);
if (ndlp && NLP_CHK_NODE_ACT(ndlp))
lpfc_els_abort(phba, ndlp);
goto restart_disc;
case LPFC_NS_QRY:
lpfc_printf_vlog(vport, KERN_ERR, LOG_DISCOVERY,
"0224 NameServer Query timeout "
"Data: x%x x%x\n",
vport->fc_ns_retry, LPFC_MAX_NS_RETRY);
if (vport->fc_ns_retry < LPFC_MAX_NS_RETRY) {
vport->fc_ns_retry++;
rc = lpfc_ns_cmd(vport, SLI_CTNS_GID_FT,
vport->fc_ns_retry, 0);
if (rc == 0)
break;
}
vport->fc_ns_retry = 0;
restart_disc:
if (phba->sli_rev < LPFC_SLI_REV4) {
if (phba->sli3_options & LPFC_SLI3_NPIV_ENABLED)
lpfc_issue_reg_vpi(phba, vport);
else {
lpfc_issue_clear_la(phba, vport);
vport->port_state = LPFC_VPORT_READY;
}
}
initlinkmbox = mempool_alloc(phba->mbox_mem_pool, GFP_KERNEL);
if (!initlinkmbox) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_DISCOVERY,
"0206 Device Discovery "
"completion error\n");
phba->link_state = LPFC_HBA_ERROR;
break;
}
lpfc_linkdown(phba);
lpfc_init_link(phba, initlinkmbox, phba->cfg_topology,
phba->cfg_link_speed);
initlinkmbox->u.mb.un.varInitLnk.lipsr_AL_PA = 0;
initlinkmbox->vport = vport;
initlinkmbox->mbox_cmpl = lpfc_sli_def_mbox_cmpl;
rc = lpfc_sli_issue_mbox(phba, initlinkmbox, MBX_NOWAIT);
lpfc_set_loopback_flag(phba);
if (rc == MBX_NOT_FINISHED)
mempool_free(initlinkmbox, phba->mbox_mem_pool);
break;
case LPFC_DISC_AUTH:
lpfc_printf_vlog(vport, KERN_ERR, LOG_DISCOVERY,
"0227 Node Authentication timeout\n");
lpfc_disc_flush_list(vport);
if (phba->sli_rev < LPFC_SLI_REV4) {
if (phba->sli3_options & LPFC_SLI3_NPIV_ENABLED)
lpfc_issue_reg_vpi(phba, vport);
else {
lpfc_issue_clear_la(phba, vport);
vport->port_state = LPFC_VPORT_READY;
}
}
break;
case LPFC_VPORT_READY:
if (vport->fc_flag & FC_RSCN_MODE) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_DISCOVERY,
"0231 RSCN timeout Data: x%x "
"x%x\n",
vport->fc_ns_retry, LPFC_MAX_NS_RETRY);
lpfc_els_flush_cmd(vport);
lpfc_els_flush_rscn(vport);
lpfc_disc_flush_list(vport);
}
break;
default:
lpfc_printf_vlog(vport, KERN_ERR, LOG_DISCOVERY,
"0273 Unexpected discovery timeout, "
"vport State x%x\n", vport->port_state);
break;
}
switch (phba->link_state) {
case LPFC_CLEAR_LA:
lpfc_printf_vlog(vport, KERN_ERR, LOG_DISCOVERY,
"0228 CLEAR LA timeout\n");
clrlaerr = 1;
break;
case LPFC_LINK_UP:
lpfc_issue_clear_la(phba, vport);
case LPFC_LINK_UNKNOWN:
case LPFC_WARM_START:
case LPFC_INIT_START:
case LPFC_INIT_MBX_CMDS:
case LPFC_LINK_DOWN:
case LPFC_HBA_ERROR:
lpfc_printf_vlog(vport, KERN_ERR, LOG_DISCOVERY,
"0230 Unexpected timeout, hba link "
"state x%x\n", phba->link_state);
clrlaerr = 1;
break;
case LPFC_HBA_READY:
break;
}
if (clrlaerr) {
lpfc_disc_flush_list(vport);
psli->ring[(psli->extra_ring)].flag &= ~LPFC_STOP_IOCB_EVENT;
psli->ring[(psli->fcp_ring)].flag &= ~LPFC_STOP_IOCB_EVENT;
psli->ring[(psli->next_ring)].flag &= ~LPFC_STOP_IOCB_EVENT;
vport->port_state = LPFC_VPORT_READY;
}
return;
}
void
lpfc_mbx_cmpl_fdmi_reg_login(struct lpfc_hba *phba, LPFC_MBOXQ_t *pmb)
{
MAILBOX_t *mb = &pmb->u.mb;
struct lpfc_dmabuf *mp = (struct lpfc_dmabuf *) (pmb->context1);
struct lpfc_nodelist *ndlp = (struct lpfc_nodelist *) pmb->context2;
struct lpfc_vport *vport = pmb->vport;
pmb->context1 = NULL;
pmb->context2 = NULL;
if (phba->sli_rev < LPFC_SLI_REV4)
ndlp->nlp_rpi = mb->un.varWords[0];
ndlp->nlp_flag |= NLP_RPI_REGISTERED;
ndlp->nlp_type |= NLP_FABRIC;
lpfc_nlp_set_state(vport, ndlp, NLP_STE_UNMAPPED_NODE);
if (vport->cfg_fdmi_on == 1)
lpfc_fdmi_cmd(vport, ndlp, SLI_MGMT_DHBA);
else
mod_timer(&vport->fc_fdmitmo,
jiffies + msecs_to_jiffies(1000 * 60));
lpfc_nlp_put(ndlp);
lpfc_mbuf_free(phba, mp->virt, mp->phys);
kfree(mp);
mempool_free(pmb, phba->mbox_mem_pool);
return;
}
static int
lpfc_filter_by_rpi(struct lpfc_nodelist *ndlp, void *param)
{
uint16_t *rpi = param;
if (!NLP_CHK_NODE_ACT(ndlp))
return 0;
return ndlp->nlp_rpi == *rpi;
}
static int
lpfc_filter_by_wwpn(struct lpfc_nodelist *ndlp, void *param)
{
return memcmp(&ndlp->nlp_portname, param,
sizeof(ndlp->nlp_portname)) == 0;
}
static struct lpfc_nodelist *
__lpfc_find_node(struct lpfc_vport *vport, node_filter filter, void *param)
{
struct lpfc_nodelist *ndlp;
list_for_each_entry(ndlp, &vport->fc_nodes, nlp_listp) {
if (filter(ndlp, param)) {
lpfc_printf_vlog(vport, KERN_INFO, LOG_NODE,
"3185 FIND node filter %p DID "
"Data: x%p x%x x%x\n",
filter, ndlp, ndlp->nlp_DID,
ndlp->nlp_flag);
return ndlp;
}
}
lpfc_printf_vlog(vport, KERN_INFO, LOG_NODE,
"3186 FIND node filter %p NOT FOUND.\n", filter);
return NULL;
}
struct lpfc_nodelist *
__lpfc_findnode_rpi(struct lpfc_vport *vport, uint16_t rpi)
{
return __lpfc_find_node(vport, lpfc_filter_by_rpi, &rpi);
}
struct lpfc_nodelist *
lpfc_findnode_wwpn(struct lpfc_vport *vport, struct lpfc_name *wwpn)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
struct lpfc_nodelist *ndlp;
spin_lock_irq(shost->host_lock);
ndlp = __lpfc_find_node(vport, lpfc_filter_by_wwpn, wwpn);
spin_unlock_irq(shost->host_lock);
return ndlp;
}
struct lpfc_nodelist *
lpfc_findnode_rpi(struct lpfc_vport *vport, uint16_t rpi)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
struct lpfc_nodelist *ndlp;
spin_lock_irq(shost->host_lock);
ndlp = __lpfc_findnode_rpi(vport, rpi);
spin_unlock_irq(shost->host_lock);
return ndlp;
}
struct lpfc_vport *
lpfc_find_vport_by_vpid(struct lpfc_hba *phba, uint16_t vpi)
{
struct lpfc_vport *vport;
unsigned long flags;
int i = 0;
if (vpi > 0) {
for (i = 0; i < phba->max_vpi; i++) {
if (vpi == phba->vpi_ids[i])
break;
}
if (i >= phba->max_vpi) {
lpfc_printf_log(phba, KERN_ERR, LOG_ELS,
"2936 Could not find Vport mapped "
"to vpi %d\n", vpi);
return NULL;
}
}
spin_lock_irqsave(&phba->hbalock, flags);
list_for_each_entry(vport, &phba->port_list, listentry) {
if (vport->vpi == i) {
spin_unlock_irqrestore(&phba->hbalock, flags);
return vport;
}
}
spin_unlock_irqrestore(&phba->hbalock, flags);
return NULL;
}
void
lpfc_nlp_init(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
uint32_t did)
{
memset(ndlp, 0, sizeof (struct lpfc_nodelist));
lpfc_initialize_node(vport, ndlp, did);
INIT_LIST_HEAD(&ndlp->nlp_listp);
if (vport->phba->sli_rev == LPFC_SLI_REV4) {
ndlp->nlp_rpi = lpfc_sli4_alloc_rpi(vport->phba);
ndlp->active_rrqs_xri_bitmap =
mempool_alloc(vport->phba->active_rrq_pool,
GFP_KERNEL);
if (ndlp->active_rrqs_xri_bitmap)
memset(ndlp->active_rrqs_xri_bitmap, 0,
ndlp->phba->cfg_rrq_xri_bitmap_sz);
}
lpfc_debugfs_disc_trc(vport, LPFC_DISC_TRC_NODE,
"node init: did:x%x",
ndlp->nlp_DID, 0, 0);
return;
}
static void
lpfc_nlp_release(struct kref *kref)
{
struct lpfc_hba *phba;
unsigned long flags;
struct lpfc_nodelist *ndlp = container_of(kref, struct lpfc_nodelist,
kref);
lpfc_debugfs_disc_trc(ndlp->vport, LPFC_DISC_TRC_NODE,
"node release: did:x%x flg:x%x type:x%x",
ndlp->nlp_DID, ndlp->nlp_flag, ndlp->nlp_type);
lpfc_printf_vlog(ndlp->vport, KERN_INFO, LOG_NODE,
"0279 lpfc_nlp_release: ndlp:x%p did %x "
"usgmap:x%x refcnt:%d\n",
(void *)ndlp, ndlp->nlp_DID, ndlp->nlp_usg_map,
atomic_read(&ndlp->kref.refcount));
lpfc_nlp_remove(ndlp->vport, ndlp);
phba = ndlp->phba;
spin_lock_irqsave(&phba->ndlp_lock, flags);
NLP_CLR_NODE_ACT(ndlp);
spin_unlock_irqrestore(&phba->ndlp_lock, flags);
if (phba->sli_rev == LPFC_SLI_REV4)
lpfc_sli4_free_rpi(phba, ndlp->nlp_rpi);
if (NLP_CHK_FREE_REQ(ndlp)) {
kfree(ndlp->lat_data);
if (phba->sli_rev == LPFC_SLI_REV4)
mempool_free(ndlp->active_rrqs_xri_bitmap,
ndlp->phba->active_rrq_pool);
mempool_free(ndlp, ndlp->phba->nlp_mem_pool);
}
}
struct lpfc_nodelist *
lpfc_nlp_get(struct lpfc_nodelist *ndlp)
{
struct lpfc_hba *phba;
unsigned long flags;
if (ndlp) {
lpfc_debugfs_disc_trc(ndlp->vport, LPFC_DISC_TRC_NODE,
"node get: did:x%x flg:x%x refcnt:x%x",
ndlp->nlp_DID, ndlp->nlp_flag,
atomic_read(&ndlp->kref.refcount));
phba = ndlp->phba;
spin_lock_irqsave(&phba->ndlp_lock, flags);
if (!NLP_CHK_NODE_ACT(ndlp) || NLP_CHK_FREE_ACK(ndlp)) {
spin_unlock_irqrestore(&phba->ndlp_lock, flags);
lpfc_printf_vlog(ndlp->vport, KERN_WARNING, LOG_NODE,
"0276 lpfc_nlp_get: ndlp:x%p "
"usgmap:x%x refcnt:%d\n",
(void *)ndlp, ndlp->nlp_usg_map,
atomic_read(&ndlp->kref.refcount));
return NULL;
} else
kref_get(&ndlp->kref);
spin_unlock_irqrestore(&phba->ndlp_lock, flags);
}
return ndlp;
}
int
lpfc_nlp_put(struct lpfc_nodelist *ndlp)
{
struct lpfc_hba *phba;
unsigned long flags;
if (!ndlp)
return 1;
lpfc_debugfs_disc_trc(ndlp->vport, LPFC_DISC_TRC_NODE,
"node put: did:x%x flg:x%x refcnt:x%x",
ndlp->nlp_DID, ndlp->nlp_flag,
atomic_read(&ndlp->kref.refcount));
phba = ndlp->phba;
spin_lock_irqsave(&phba->ndlp_lock, flags);
if (NLP_CHK_FREE_ACK(ndlp)) {
spin_unlock_irqrestore(&phba->ndlp_lock, flags);
lpfc_printf_vlog(ndlp->vport, KERN_WARNING, LOG_NODE,
"0274 lpfc_nlp_put: ndlp:x%p "
"usgmap:x%x refcnt:%d\n",
(void *)ndlp, ndlp->nlp_usg_map,
atomic_read(&ndlp->kref.refcount));
return 1;
}
if (NLP_CHK_IACT_REQ(ndlp)) {
spin_unlock_irqrestore(&phba->ndlp_lock, flags);
lpfc_printf_vlog(ndlp->vport, KERN_WARNING, LOG_NODE,
"0275 lpfc_nlp_put: ndlp:x%p "
"usgmap:x%x refcnt:%d\n",
(void *)ndlp, ndlp->nlp_usg_map,
atomic_read(&ndlp->kref.refcount));
return 1;
}
if (atomic_read(&ndlp->kref.refcount) == 1) {
NLP_SET_IACT_REQ(ndlp);
if (NLP_CHK_FREE_REQ(ndlp))
NLP_SET_FREE_ACK(ndlp);
}
spin_unlock_irqrestore(&phba->ndlp_lock, flags);
return kref_put(&ndlp->kref, lpfc_nlp_release);
}
int
lpfc_nlp_not_used(struct lpfc_nodelist *ndlp)
{
lpfc_debugfs_disc_trc(ndlp->vport, LPFC_DISC_TRC_NODE,
"node not used: did:x%x flg:x%x refcnt:x%x",
ndlp->nlp_DID, ndlp->nlp_flag,
atomic_read(&ndlp->kref.refcount));
if (atomic_read(&ndlp->kref.refcount) == 1)
if (lpfc_nlp_put(ndlp))
return 1;
return 0;
}
static int
lpfc_fcf_inuse(struct lpfc_hba *phba)
{
struct lpfc_vport **vports;
int i, ret = 0;
struct lpfc_nodelist *ndlp;
struct Scsi_Host *shost;
vports = lpfc_create_vport_work_array(phba);
if (!vports)
return 1;
for (i = 0; i <= phba->max_vports && vports[i] != NULL; i++) {
shost = lpfc_shost_from_vport(vports[i]);
spin_lock_irq(shost->host_lock);
if (!(vports[i]->fc_flag & FC_VPORT_CVL_RCVD)) {
spin_unlock_irq(shost->host_lock);
ret = 1;
goto out;
}
list_for_each_entry(ndlp, &vports[i]->fc_nodes, nlp_listp) {
if (NLP_CHK_NODE_ACT(ndlp) && ndlp->rport &&
(ndlp->rport->roles & FC_RPORT_ROLE_FCP_TARGET)) {
ret = 1;
spin_unlock_irq(shost->host_lock);
goto out;
} else if (ndlp->nlp_flag & NLP_RPI_REGISTERED) {
ret = 1;
lpfc_printf_log(phba, KERN_INFO, LOG_ELS,
"2624 RPI %x DID %x flag %x "
"still logged in\n",
ndlp->nlp_rpi, ndlp->nlp_DID,
ndlp->nlp_flag);
}
}
spin_unlock_irq(shost->host_lock);
}
out:
lpfc_destroy_vport_work_array(phba, vports);
return ret;
}
void
lpfc_unregister_vfi_cmpl(struct lpfc_hba *phba, LPFC_MBOXQ_t *mboxq)
{
struct lpfc_vport *vport = mboxq->vport;
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
if (mboxq->u.mb.mbxStatus) {
lpfc_printf_log(phba, KERN_ERR, LOG_DISCOVERY|LOG_MBOX,
"2555 UNREG_VFI mbxStatus error x%x "
"HBA state x%x\n",
mboxq->u.mb.mbxStatus, vport->port_state);
}
spin_lock_irq(shost->host_lock);
phba->pport->fc_flag &= ~FC_VFI_REGISTERED;
spin_unlock_irq(shost->host_lock);
mempool_free(mboxq, phba->mbox_mem_pool);
return;
}
static void
lpfc_unregister_fcfi_cmpl(struct lpfc_hba *phba, LPFC_MBOXQ_t *mboxq)
{
struct lpfc_vport *vport = mboxq->vport;
if (mboxq->u.mb.mbxStatus) {
lpfc_printf_log(phba, KERN_ERR, LOG_DISCOVERY|LOG_MBOX,
"2550 UNREG_FCFI mbxStatus error x%x "
"HBA state x%x\n",
mboxq->u.mb.mbxStatus, vport->port_state);
}
mempool_free(mboxq, phba->mbox_mem_pool);
return;
}
int
lpfc_unregister_fcf_prep(struct lpfc_hba *phba)
{
struct lpfc_vport **vports;
struct lpfc_nodelist *ndlp;
struct Scsi_Host *shost;
int i = 0, rc;
if (lpfc_fcf_inuse(phba))
lpfc_unreg_hba_rpis(phba);
phba->pport->port_state = LPFC_VPORT_UNKNOWN;
vports = lpfc_create_vport_work_array(phba);
if (vports && (phba->sli3_options & LPFC_SLI3_NPIV_ENABLED))
for (i = 0; i <= phba->max_vports && vports[i] != NULL; i++) {
ndlp = lpfc_findnode_did(vports[i], Fabric_DID);
if (ndlp)
lpfc_cancel_retry_delay_tmo(vports[i], ndlp);
lpfc_cleanup_pending_mbox(vports[i]);
if (phba->sli_rev == LPFC_SLI_REV4)
lpfc_sli4_unreg_all_rpis(vports[i]);
lpfc_mbx_unreg_vpi(vports[i]);
shost = lpfc_shost_from_vport(vports[i]);
spin_lock_irq(shost->host_lock);
vports[i]->fc_flag |= FC_VPORT_NEEDS_INIT_VPI;
vports[i]->vpi_state &= ~LPFC_VPI_REGISTERED;
spin_unlock_irq(shost->host_lock);
}
lpfc_destroy_vport_work_array(phba, vports);
if (i == 0 && (!(phba->sli3_options & LPFC_SLI3_NPIV_ENABLED))) {
ndlp = lpfc_findnode_did(phba->pport, Fabric_DID);
if (ndlp)
lpfc_cancel_retry_delay_tmo(phba->pport, ndlp);
lpfc_cleanup_pending_mbox(phba->pport);
if (phba->sli_rev == LPFC_SLI_REV4)
lpfc_sli4_unreg_all_rpis(phba->pport);
lpfc_mbx_unreg_vpi(phba->pport);
shost = lpfc_shost_from_vport(phba->pport);
spin_lock_irq(shost->host_lock);
phba->pport->fc_flag |= FC_VPORT_NEEDS_INIT_VPI;
phba->pport->vpi_state &= ~LPFC_VPI_REGISTERED;
spin_unlock_irq(shost->host_lock);
}
lpfc_els_flush_all_cmd(phba);
rc = lpfc_issue_unreg_vfi(phba->pport);
return rc;
}
int
lpfc_sli4_unregister_fcf(struct lpfc_hba *phba)
{
LPFC_MBOXQ_t *mbox;
int rc;
mbox = mempool_alloc(phba->mbox_mem_pool, GFP_KERNEL);
if (!mbox) {
lpfc_printf_log(phba, KERN_ERR, LOG_DISCOVERY|LOG_MBOX,
"2551 UNREG_FCFI mbox allocation failed"
"HBA state x%x\n", phba->pport->port_state);
return -ENOMEM;
}
lpfc_unreg_fcfi(mbox, phba->fcf.fcfi);
mbox->vport = phba->pport;
mbox->mbox_cmpl = lpfc_unregister_fcfi_cmpl;
rc = lpfc_sli_issue_mbox(phba, mbox, MBX_NOWAIT);
if (rc == MBX_NOT_FINISHED) {
lpfc_printf_log(phba, KERN_ERR, LOG_SLI,
"2552 Unregister FCFI command failed rc x%x "
"HBA state x%x\n",
rc, phba->pport->port_state);
return -EINVAL;
}
return 0;
}
void
lpfc_unregister_fcf_rescan(struct lpfc_hba *phba)
{
int rc;
rc = lpfc_unregister_fcf_prep(phba);
if (rc) {
lpfc_printf_log(phba, KERN_ERR, LOG_DISCOVERY,
"2748 Failed to prepare for unregistering "
"HBA's FCF record: rc=%d\n", rc);
return;
}
rc = lpfc_sli4_unregister_fcf(phba);
if (rc)
return;
phba->fcf.fcf_flag = 0;
phba->fcf.current_rec.flag = 0;
if ((phba->pport->load_flag & FC_UNLOADING) ||
(phba->link_state < LPFC_LINK_UP))
return;
spin_lock_irq(&phba->hbalock);
phba->fcf.fcf_flag |= FCF_INIT_DISC;
spin_unlock_irq(&phba->hbalock);
lpfc_sli4_clear_fcf_rr_bmask(phba);
rc = lpfc_sli4_fcf_scan_read_fcf_rec(phba, LPFC_FCOE_FCF_GET_FIRST);
if (rc) {
spin_lock_irq(&phba->hbalock);
phba->fcf.fcf_flag &= ~FCF_INIT_DISC;
spin_unlock_irq(&phba->hbalock);
lpfc_printf_log(phba, KERN_ERR, LOG_DISCOVERY|LOG_MBOX,
"2553 lpfc_unregister_unused_fcf failed "
"to read FCF record HBA state x%x\n",
phba->pport->port_state);
}
}
void
lpfc_unregister_fcf(struct lpfc_hba *phba)
{
int rc;
rc = lpfc_unregister_fcf_prep(phba);
if (rc) {
lpfc_printf_log(phba, KERN_ERR, LOG_DISCOVERY,
"2749 Failed to prepare for unregistering "
"HBA's FCF record: rc=%d\n", rc);
return;
}
rc = lpfc_sli4_unregister_fcf(phba);
if (rc)
return;
spin_lock_irq(&phba->hbalock);
phba->fcf.fcf_flag &= ~FCF_REGISTERED;
spin_unlock_irq(&phba->hbalock);
}
void
lpfc_unregister_unused_fcf(struct lpfc_hba *phba)
{
spin_lock_irq(&phba->hbalock);
if (!(phba->hba_flag & HBA_FCOE_MODE) ||
!(phba->fcf.fcf_flag & FCF_REGISTERED) ||
!(phba->hba_flag & HBA_FIP_SUPPORT) ||
(phba->fcf.fcf_flag & FCF_DISCOVERY) ||
(phba->pport->port_state == LPFC_FLOGI)) {
spin_unlock_irq(&phba->hbalock);
return;
}
spin_unlock_irq(&phba->hbalock);
if (lpfc_fcf_inuse(phba))
return;
lpfc_unregister_fcf_rescan(phba);
}
static void
lpfc_read_fcf_conn_tbl(struct lpfc_hba *phba,
uint8_t *buff)
{
struct lpfc_fcf_conn_entry *conn_entry, *next_conn_entry;
struct lpfc_fcf_conn_hdr *conn_hdr;
struct lpfc_fcf_conn_rec *conn_rec;
uint32_t record_count;
int i;
list_for_each_entry_safe(conn_entry, next_conn_entry,
&phba->fcf_conn_rec_list, list) {
list_del_init(&conn_entry->list);
kfree(conn_entry);
}
conn_hdr = (struct lpfc_fcf_conn_hdr *) buff;
record_count = conn_hdr->length * sizeof(uint32_t)/
sizeof(struct lpfc_fcf_conn_rec);
conn_rec = (struct lpfc_fcf_conn_rec *)
(buff + sizeof(struct lpfc_fcf_conn_hdr));
for (i = 0; i < record_count; i++) {
if (!(conn_rec[i].flags & FCFCNCT_VALID))
continue;
conn_entry = kzalloc(sizeof(struct lpfc_fcf_conn_entry),
GFP_KERNEL);
if (!conn_entry) {
lpfc_printf_log(phba, KERN_ERR, LOG_INIT,
"2566 Failed to allocate connection"
" table entry\n");
return;
}
memcpy(&conn_entry->conn_rec, &conn_rec[i],
sizeof(struct lpfc_fcf_conn_rec));
list_add_tail(&conn_entry->list,
&phba->fcf_conn_rec_list);
}
if (!list_empty(&phba->fcf_conn_rec_list)) {
i = 0;
list_for_each_entry(conn_entry, &phba->fcf_conn_rec_list,
list) {
conn_rec = &conn_entry->conn_rec;
lpfc_printf_log(phba, KERN_INFO, LOG_INIT,
"3345 FCF connection list rec[%02d]: "
"flags:x%04x, vtag:x%04x, "
"fabric_name:x%02x:%02x:%02x:%02x:"
"%02x:%02x:%02x:%02x, "
"switch_name:x%02x:%02x:%02x:%02x:"
"%02x:%02x:%02x:%02x\n", i++,
conn_rec->flags, conn_rec->vlan_tag,
conn_rec->fabric_name[0],
conn_rec->fabric_name[1],
conn_rec->fabric_name[2],
conn_rec->fabric_name[3],
conn_rec->fabric_name[4],
conn_rec->fabric_name[5],
conn_rec->fabric_name[6],
conn_rec->fabric_name[7],
conn_rec->switch_name[0],
conn_rec->switch_name[1],
conn_rec->switch_name[2],
conn_rec->switch_name[3],
conn_rec->switch_name[4],
conn_rec->switch_name[5],
conn_rec->switch_name[6],
conn_rec->switch_name[7]);
}
}
}
static void
lpfc_read_fcoe_param(struct lpfc_hba *phba,
uint8_t *buff)
{
struct lpfc_fip_param_hdr *fcoe_param_hdr;
struct lpfc_fcoe_params *fcoe_param;
fcoe_param_hdr = (struct lpfc_fip_param_hdr *)
buff;
fcoe_param = (struct lpfc_fcoe_params *)
(buff + sizeof(struct lpfc_fip_param_hdr));
if ((fcoe_param_hdr->parm_version != FIPP_VERSION) ||
(fcoe_param_hdr->length != FCOE_PARAM_LENGTH))
return;
if (fcoe_param_hdr->parm_flags & FIPP_VLAN_VALID) {
phba->valid_vlan = 1;
phba->vlan_id = le16_to_cpu(fcoe_param->vlan_tag) &
0xFFF;
}
phba->fc_map[0] = fcoe_param->fc_map[0];
phba->fc_map[1] = fcoe_param->fc_map[1];
phba->fc_map[2] = fcoe_param->fc_map[2];
return;
}
static uint8_t *
lpfc_get_rec_conf23(uint8_t *buff, uint32_t size, uint8_t rec_type)
{
uint32_t offset = 0, rec_length;
if ((buff[0] == LPFC_REGION23_LAST_REC) ||
(size < sizeof(uint32_t)))
return NULL;
rec_length = buff[offset + 1];
while ((offset + rec_length * sizeof(uint32_t) + sizeof(uint32_t))
<= size) {
if (buff[offset] == rec_type)
return &buff[offset];
if (buff[offset] == LPFC_REGION23_LAST_REC)
return NULL;
offset += rec_length * sizeof(uint32_t) + sizeof(uint32_t);
rec_length = buff[offset + 1];
}
return NULL;
}
void
lpfc_parse_fcoe_conf(struct lpfc_hba *phba,
uint8_t *buff,
uint32_t size)
{
uint32_t offset = 0, rec_length;
uint8_t *rec_ptr;
if (size < 2*sizeof(uint32_t))
return;
if (memcmp(buff, LPFC_REGION23_SIGNATURE, 4)) {
lpfc_printf_log(phba, KERN_ERR, LOG_INIT,
"2567 Config region 23 has bad signature\n");
return;
}
offset += 4;
if (buff[offset] != LPFC_REGION23_VERSION) {
lpfc_printf_log(phba, KERN_ERR, LOG_INIT,
"2568 Config region 23 has bad version\n");
return;
}
offset += 4;
rec_length = buff[offset + 1];
rec_ptr = lpfc_get_rec_conf23(&buff[offset],
size - offset, FCOE_PARAM_TYPE);
if (rec_ptr)
lpfc_read_fcoe_param(phba, rec_ptr);
rec_ptr = lpfc_get_rec_conf23(&buff[offset],
size - offset, FCOE_CONN_TBL_TYPE);
if (rec_ptr)
lpfc_read_fcf_conn_tbl(phba, rec_ptr);
}
