static int
lpfc_check_adisc(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
struct lpfc_name *nn, struct lpfc_name *pn)
{
if (!(ndlp->nlp_flag & NLP_RPI_REGISTERED))
return 0;
if (memcmp(nn, &ndlp->nlp_nodename, sizeof (struct lpfc_name)))
return 0;
if (memcmp(pn, &ndlp->nlp_portname, sizeof (struct lpfc_name)))
return 0;
return 1;
}
int
lpfc_check_sparm(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
struct serv_parm *sp, uint32_t class, int flogi)
{
volatile struct serv_parm *hsp = &vport->fc_sparam;
uint16_t hsp_value, ssp_value = 0;
if (sp->cls1.classValid) {
if (!flogi) {
hsp_value = ((hsp->cls1.rcvDataSizeMsb << 8) |
hsp->cls1.rcvDataSizeLsb);
ssp_value = ((sp->cls1.rcvDataSizeMsb << 8) |
sp->cls1.rcvDataSizeLsb);
if (!ssp_value)
goto bad_service_param;
if (ssp_value > hsp_value) {
sp->cls1.rcvDataSizeLsb =
hsp->cls1.rcvDataSizeLsb;
sp->cls1.rcvDataSizeMsb =
hsp->cls1.rcvDataSizeMsb;
}
}
} else if (class == CLASS1)
goto bad_service_param;
if (sp->cls2.classValid) {
if (!flogi) {
hsp_value = ((hsp->cls2.rcvDataSizeMsb << 8) |
hsp->cls2.rcvDataSizeLsb);
ssp_value = ((sp->cls2.rcvDataSizeMsb << 8) |
sp->cls2.rcvDataSizeLsb);
if (!ssp_value)
goto bad_service_param;
if (ssp_value > hsp_value) {
sp->cls2.rcvDataSizeLsb =
hsp->cls2.rcvDataSizeLsb;
sp->cls2.rcvDataSizeMsb =
hsp->cls2.rcvDataSizeMsb;
}
}
} else if (class == CLASS2)
goto bad_service_param;
if (sp->cls3.classValid) {
if (!flogi) {
hsp_value = ((hsp->cls3.rcvDataSizeMsb << 8) |
hsp->cls3.rcvDataSizeLsb);
ssp_value = ((sp->cls3.rcvDataSizeMsb << 8) |
sp->cls3.rcvDataSizeLsb);
if (!ssp_value)
goto bad_service_param;
if (ssp_value > hsp_value) {
sp->cls3.rcvDataSizeLsb =
hsp->cls3.rcvDataSizeLsb;
sp->cls3.rcvDataSizeMsb =
hsp->cls3.rcvDataSizeMsb;
}
}
} else if (class == CLASS3)
goto bad_service_param;
hsp_value = (hsp->cmn.bbRcvSizeMsb << 8) | hsp->cmn.bbRcvSizeLsb;
ssp_value = (sp->cmn.bbRcvSizeMsb << 8) | sp->cmn.bbRcvSizeLsb;
if (ssp_value > hsp_value) {
sp->cmn.bbRcvSizeLsb = hsp->cmn.bbRcvSizeLsb;
sp->cmn.bbRcvSizeMsb = (sp->cmn.bbRcvSizeMsb & 0xF0) |
(hsp->cmn.bbRcvSizeMsb & 0x0F);
}
memcpy(&ndlp->nlp_nodename, &sp->nodeName, sizeof (struct lpfc_name));
memcpy(&ndlp->nlp_portname, &sp->portName, sizeof (struct lpfc_name));
return 1;
bad_service_param:
lpfc_printf_vlog(vport, KERN_ERR, LOG_DISCOVERY,
"0207 Device %x "
"(%02x:%02x:%02x:%02x:%02x:%02x:%02x:%02x) sent "
"invalid service parameters. Ignoring device.\n",
ndlp->nlp_DID,
sp->nodeName.u.wwn[0], sp->nodeName.u.wwn[1],
sp->nodeName.u.wwn[2], sp->nodeName.u.wwn[3],
sp->nodeName.u.wwn[4], sp->nodeName.u.wwn[5],
sp->nodeName.u.wwn[6], sp->nodeName.u.wwn[7]);
return 0;
}
static void *
lpfc_check_elscmpl_iocb(struct lpfc_hba *phba, struct lpfc_iocbq *cmdiocb,
struct lpfc_iocbq *rspiocb)
{
struct lpfc_dmabuf *pcmd, *prsp;
uint32_t *lp;
void *ptr = NULL;
IOCB_t *irsp;
irsp = &rspiocb->iocb;
pcmd = (struct lpfc_dmabuf *) cmdiocb->context2;
if (pcmd) {
prsp = list_get_first(&pcmd->list, struct lpfc_dmabuf,
list);
if (prsp) {
lp = (uint32_t *) prsp->virt;
ptr = (void *)((uint8_t *)lp + sizeof(uint32_t));
}
} else {
if (!(irsp->ulpStatus)) {
irsp->ulpStatus = IOSTAT_LOCAL_REJECT;
irsp->un.ulpWord[4] = IOERR_SLI_ABORTED;
}
ptr = NULL;
}
return ptr;
}
int
lpfc_els_abort(struct lpfc_hba *phba, struct lpfc_nodelist *ndlp)
{
LIST_HEAD(abort_list);
struct lpfc_sli *psli = &phba->sli;
struct lpfc_sli_ring *pring = &psli->ring[LPFC_ELS_RING];
struct lpfc_iocbq *iocb, *next_iocb;
lpfc_printf_vlog(ndlp->vport, KERN_INFO, LOG_DISCOVERY,
"2819 Abort outstanding I/O on NPort x%x "
"Data: x%x x%x x%x\n",
ndlp->nlp_DID, ndlp->nlp_flag, ndlp->nlp_state,
ndlp->nlp_rpi);
lpfc_fabric_abort_nport(ndlp);
spin_lock_irq(&phba->hbalock);
if (phba->sli_rev == LPFC_SLI_REV4)
spin_lock(&pring->ring_lock);
list_for_each_entry_safe(iocb, next_iocb, &pring->txcmplq, list) {
if (lpfc_check_sli_ndlp(phba, pring, iocb, ndlp))
list_add_tail(&iocb->dlist, &abort_list);
}
if (phba->sli_rev == LPFC_SLI_REV4)
spin_unlock(&pring->ring_lock);
spin_unlock_irq(&phba->hbalock);
list_for_each_entry_safe(iocb, next_iocb, &abort_list, dlist) {
spin_lock_irq(&phba->hbalock);
list_del_init(&iocb->dlist);
lpfc_sli_issue_abort_iotag(phba, pring, iocb);
spin_unlock_irq(&phba->hbalock);
}
INIT_LIST_HEAD(&abort_list);
spin_lock_irq(&phba->hbalock);
if (phba->sli_rev == LPFC_SLI_REV4)
spin_lock(&pring->ring_lock);
list_for_each_entry_safe(iocb, next_iocb, &pring->txq, list) {
if (lpfc_check_sli_ndlp(phba, pring, iocb, ndlp)) {
list_del_init(&iocb->list);
list_add_tail(&iocb->list, &abort_list);
}
}
if (phba->sli_rev == LPFC_SLI_REV4)
spin_unlock(&pring->ring_lock);
spin_unlock_irq(&phba->hbalock);
lpfc_sli_cancel_iocbs(phba, &abort_list,
IOSTAT_LOCAL_REJECT, IOERR_SLI_ABORTED);
lpfc_cancel_retry_delay_tmo(phba->pport, ndlp);
return 0;
}
static int
lpfc_rcv_plogi(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
struct lpfc_iocbq *cmdiocb)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
struct lpfc_hba *phba = vport->phba;
struct lpfc_dmabuf *pcmd;
uint64_t nlp_portwwn = 0;
uint32_t *lp;
IOCB_t *icmd;
struct serv_parm *sp;
uint32_t ed_tov;
LPFC_MBOXQ_t *mbox;
struct ls_rjt stat;
int rc;
memset(&stat, 0, sizeof (struct ls_rjt));
pcmd = (struct lpfc_dmabuf *) cmdiocb->context2;
lp = (uint32_t *) pcmd->virt;
sp = (struct serv_parm *) ((uint8_t *) lp + sizeof (uint32_t));
if (wwn_to_u64(sp->portName.u.wwn) == 0) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_ELS,
"0140 PLOGI Reject: invalid nname\n");
stat.un.b.lsRjtRsnCode = LSRJT_UNABLE_TPC;
stat.un.b.lsRjtRsnCodeExp = LSEXP_INVALID_PNAME;
lpfc_els_rsp_reject(vport, stat.un.lsRjtError, cmdiocb, ndlp,
NULL);
return 0;
}
if (wwn_to_u64(sp->nodeName.u.wwn) == 0) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_ELS,
"0141 PLOGI Reject: invalid pname\n");
stat.un.b.lsRjtRsnCode = LSRJT_UNABLE_TPC;
stat.un.b.lsRjtRsnCodeExp = LSEXP_INVALID_NNAME;
lpfc_els_rsp_reject(vport, stat.un.lsRjtError, cmdiocb, ndlp,
NULL);
return 0;
}
nlp_portwwn = wwn_to_u64(ndlp->nlp_portname.u.wwn);
if ((lpfc_check_sparm(vport, ndlp, sp, CLASS3, 0) == 0)) {
stat.un.b.lsRjtRsnCode = LSRJT_UNABLE_TPC;
stat.un.b.lsRjtRsnCodeExp = LSEXP_SPARM_OPTIONS;
lpfc_els_rsp_reject(vport, stat.un.lsRjtError, cmdiocb, ndlp,
NULL);
return 0;
}
icmd = &cmdiocb->iocb;
lpfc_printf_vlog(vport, KERN_INFO, LOG_ELS,
"0114 PLOGI chkparm OK Data: x%x x%x x%x "
"x%x x%x x%x\n",
ndlp->nlp_DID, ndlp->nlp_state, ndlp->nlp_flag,
ndlp->nlp_rpi, vport->port_state,
vport->fc_flag);
if (vport->cfg_fcp_class == 2 && sp->cls2.classValid)
ndlp->nlp_fcp_info |= CLASS2;
else
ndlp->nlp_fcp_info |= CLASS3;
ndlp->nlp_class_sup = 0;
if (sp->cls1.classValid)
ndlp->nlp_class_sup |= FC_COS_CLASS1;
if (sp->cls2.classValid)
ndlp->nlp_class_sup |= FC_COS_CLASS2;
if (sp->cls3.classValid)
ndlp->nlp_class_sup |= FC_COS_CLASS3;
if (sp->cls4.classValid)
ndlp->nlp_class_sup |= FC_COS_CLASS4;
ndlp->nlp_maxframe =
((sp->cmn.bbRcvSizeMsb & 0x0F) << 8) | sp->cmn.bbRcvSizeLsb;
switch (ndlp->nlp_state) {
case NLP_STE_NPR_NODE:
if (!(ndlp->nlp_flag & NLP_NPR_ADISC))
break;
case NLP_STE_REG_LOGIN_ISSUE:
case NLP_STE_PRLI_ISSUE:
case NLP_STE_UNMAPPED_NODE:
case NLP_STE_MAPPED_NODE:
if (!(ndlp->nlp_type & NLP_FABRIC)) {
lpfc_els_rsp_acc(vport, ELS_CMD_PLOGI, cmdiocb,
ndlp, NULL);
return 1;
}
if (nlp_portwwn != 0 &&
nlp_portwwn != wwn_to_u64(sp->portName.u.wwn))
lpfc_printf_vlog(vport, KERN_ERR, LOG_ELS,
"0143 PLOGI recv'd from DID: x%x "
"WWPN changed: old %llx new %llx\n",
ndlp->nlp_DID,
(unsigned long long)nlp_portwwn,
(unsigned long long)
wwn_to_u64(sp->portName.u.wwn));
ndlp->nlp_prev_state = ndlp->nlp_state;
lpfc_nlp_set_state(vport, ndlp, NLP_STE_NPR_NODE);
break;
}
if ((vport->fc_flag & FC_PT2PT) &&
!(vport->fc_flag & FC_PT2PT_PLOGI)) {
vport->fc_myDID = icmd->un.rcvels.parmRo;
ed_tov = be32_to_cpu(sp->cmn.e_d_tov);
if (sp->cmn.edtovResolution) {
ed_tov = (phba->fc_edtov + 999999) / 1000000;
}
if (ed_tov > phba->fc_edtov)
phba->fc_edtov = ed_tov;
phba->fc_ratov = (2 * phba->fc_edtov) / 1000;
memcpy(&phba->fc_fabparam, sp, sizeof(struct serv_parm));
if (phba->sli_rev == LPFC_SLI_REV4)
lpfc_issue_reg_vfi(vport);
else {
mbox = mempool_alloc(phba->mbox_mem_pool, GFP_KERNEL);
if (mbox == NULL)
goto out;
lpfc_config_link(phba, mbox);
mbox->mbox_cmpl = lpfc_sli_def_mbox_cmpl;
mbox->vport = vport;
rc = lpfc_sli_issue_mbox(phba, mbox, MBX_NOWAIT);
if (rc == MBX_NOT_FINISHED) {
mempool_free(mbox, phba->mbox_mem_pool);
goto out;
}
}
lpfc_can_disctmo(vport);
}
mbox = mempool_alloc(phba->mbox_mem_pool, GFP_KERNEL);
if (!mbox)
goto out;
if (phba->sli_rev == LPFC_SLI_REV4)
lpfc_unreg_rpi(vport, ndlp);
rc = lpfc_reg_rpi(phba, vport->vpi, icmd->un.rcvels.remoteID,
(uint8_t *) sp, mbox, ndlp->nlp_rpi);
if (rc) {
mempool_free(mbox, phba->mbox_mem_pool);
goto out;
}
mbox->mbox_cmpl = lpfc_mbx_cmpl_reg_login;
mbox->vport = vport;
spin_lock_irq(shost->host_lock);
ndlp->nlp_flag |= (NLP_ACC_REGLOGIN | NLP_RCV_PLOGI);
spin_unlock_irq(shost->host_lock);
if (ndlp->nlp_state == NLP_STE_PLOGI_ISSUE) {
lpfc_els_abort(phba, ndlp);
}
if ((vport->port_type == LPFC_NPIV_PORT &&
vport->cfg_restrict_login)) {
spin_lock_irq(shost->host_lock);
ndlp->nlp_flag |= NLP_RM_DFLT_RPI;
spin_unlock_irq(shost->host_lock);
stat.un.b.lsRjtRsnCode = LSRJT_INVALID_CMD;
stat.un.b.lsRjtRsnCodeExp = LSEXP_NOTHING_MORE;
rc = lpfc_els_rsp_reject(vport, stat.un.lsRjtError, cmdiocb,
ndlp, mbox);
if (rc)
mempool_free(mbox, phba->mbox_mem_pool);
return 1;
}
rc = lpfc_els_rsp_acc(vport, ELS_CMD_PLOGI, cmdiocb, ndlp, mbox);
if (rc)
mempool_free(mbox, phba->mbox_mem_pool);
return 1;
out:
stat.un.b.lsRjtRsnCode = LSRJT_UNABLE_TPC;
stat.un.b.lsRjtRsnCodeExp = LSEXP_OUT_OF_RESOURCE;
lpfc_els_rsp_reject(vport, stat.un.lsRjtError, cmdiocb, ndlp, NULL);
return 0;
}
static void
lpfc_mbx_cmpl_resume_rpi(struct lpfc_hba *phba, LPFC_MBOXQ_t *mboxq)
{
struct lpfc_vport *vport;
struct lpfc_iocbq *elsiocb;
struct lpfc_nodelist *ndlp;
uint32_t cmd;
elsiocb = (struct lpfc_iocbq *)mboxq->context1;
ndlp = (struct lpfc_nodelist *) mboxq->context2;
vport = mboxq->vport;
cmd = elsiocb->drvrTimeout;
if (cmd == ELS_CMD_ADISC) {
lpfc_els_rsp_adisc_acc(vport, elsiocb, ndlp);
} else {
lpfc_els_rsp_acc(vport, ELS_CMD_PLOGI, elsiocb,
ndlp, NULL);
}
kfree(elsiocb);
mempool_free(mboxq, phba->mbox_mem_pool);
}
static int
lpfc_rcv_padisc(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
struct lpfc_iocbq *cmdiocb)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
struct lpfc_iocbq *elsiocb;
struct lpfc_dmabuf *pcmd;
struct serv_parm *sp;
struct lpfc_name *pnn, *ppn;
struct ls_rjt stat;
ADISC *ap;
IOCB_t *icmd;
uint32_t *lp;
uint32_t cmd;
pcmd = (struct lpfc_dmabuf *) cmdiocb->context2;
lp = (uint32_t *) pcmd->virt;
cmd = *lp++;
if (cmd == ELS_CMD_ADISC) {
ap = (ADISC *) lp;
pnn = (struct lpfc_name *) & ap->nodeName;
ppn = (struct lpfc_name *) & ap->portName;
} else {
sp = (struct serv_parm *) lp;
pnn = (struct lpfc_name *) & sp->nodeName;
ppn = (struct lpfc_name *) & sp->portName;
}
icmd = &cmdiocb->iocb;
if (icmd->ulpStatus == 0 && lpfc_check_adisc(vport, ndlp, pnn, ppn)) {
if (vport->phba->sli_rev == LPFC_SLI_REV4) {
elsiocb = kmalloc(sizeof(struct lpfc_iocbq),
GFP_KERNEL);
if (elsiocb) {
memcpy((uint8_t *)elsiocb, (uint8_t *)cmdiocb,
sizeof(struct lpfc_iocbq));
elsiocb->drvrTimeout = cmd;
lpfc_sli4_resume_rpi(ndlp,
lpfc_mbx_cmpl_resume_rpi, elsiocb);
goto out;
}
}
if (cmd == ELS_CMD_ADISC) {
lpfc_els_rsp_adisc_acc(vport, cmdiocb, ndlp);
} else {
lpfc_els_rsp_acc(vport, ELS_CMD_PLOGI, cmdiocb,
ndlp, NULL);
}
out:
if (ndlp->nlp_type & NLP_FCP_TARGET)
lpfc_nlp_set_state(vport, ndlp, NLP_STE_MAPPED_NODE);
else
lpfc_nlp_set_state(vport, ndlp, NLP_STE_UNMAPPED_NODE);
return 1;
}
stat.un.b.lsRjtRsvd0 = 0;
stat.un.b.lsRjtRsnCode = LSRJT_UNABLE_TPC;
stat.un.b.lsRjtRsnCodeExp = LSEXP_SPARM_OPTIONS;
stat.un.b.vendorUnique = 0;
lpfc_els_rsp_reject(vport, stat.un.lsRjtError, cmdiocb, ndlp, NULL);
mod_timer(&ndlp->nlp_delayfunc, jiffies + msecs_to_jiffies(1000));
spin_lock_irq(shost->host_lock);
ndlp->nlp_flag |= NLP_DELAY_TMO;
spin_unlock_irq(shost->host_lock);
ndlp->nlp_last_elscmd = ELS_CMD_PLOGI;
ndlp->nlp_prev_state = ndlp->nlp_state;
lpfc_nlp_set_state(vport, ndlp, NLP_STE_NPR_NODE);
return 0;
}
static int
lpfc_rcv_logo(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
struct lpfc_iocbq *cmdiocb, uint32_t els_cmd)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
struct lpfc_hba *phba = vport->phba;
struct lpfc_vport **vports;
int i, active_vlink_present = 0 ;
spin_lock_irq(shost->host_lock);
ndlp->nlp_flag |= NLP_LOGO_ACC;
spin_unlock_irq(shost->host_lock);
if (els_cmd == ELS_CMD_PRLO)
lpfc_els_rsp_acc(vport, ELS_CMD_PRLO, cmdiocb, ndlp, NULL);
else
lpfc_els_rsp_acc(vport, ELS_CMD_ACC, cmdiocb, ndlp, NULL);
if (ndlp->nlp_DID == Fabric_DID) {
if (vport->port_state <= LPFC_FDISC)
goto out;
lpfc_linkdown_port(vport);
spin_lock_irq(shost->host_lock);
vport->fc_flag |= FC_VPORT_LOGO_RCVD;
spin_unlock_irq(shost->host_lock);
vports = lpfc_create_vport_work_array(phba);
if (vports) {
for (i = 0; i <= phba->max_vports && vports[i] != NULL;
i++) {
if ((!(vports[i]->fc_flag &
FC_VPORT_LOGO_RCVD)) &&
(vports[i]->port_state > LPFC_FDISC)) {
active_vlink_present = 1;
break;
}
}
lpfc_destroy_vport_work_array(phba, vports);
}
if (!(vport->load_flag & FC_UNLOADING) &&
active_vlink_present) {
mod_timer(&ndlp->nlp_delayfunc,
jiffies + msecs_to_jiffies(1000));
spin_lock_irq(shost->host_lock);
ndlp->nlp_flag |= NLP_DELAY_TMO;
spin_unlock_irq(shost->host_lock);
ndlp->nlp_last_elscmd = ELS_CMD_FDISC;
vport->port_state = LPFC_FDISC;
} else {
spin_lock_irq(shost->host_lock);
phba->pport->fc_flag &= ~FC_LOGO_RCVD_DID_CHNG;
spin_unlock_irq(shost->host_lock);
lpfc_retry_pport_discovery(phba);
}
} else if ((!(ndlp->nlp_type & NLP_FABRIC) &&
((ndlp->nlp_type & NLP_FCP_TARGET) ||
!(ndlp->nlp_type & NLP_FCP_INITIATOR))) ||
(ndlp->nlp_state == NLP_STE_ADISC_ISSUE)) {
mod_timer(&ndlp->nlp_delayfunc,
jiffies + msecs_to_jiffies(1000 * 1));
spin_lock_irq(shost->host_lock);
ndlp->nlp_flag |= NLP_DELAY_TMO;
spin_unlock_irq(shost->host_lock);
ndlp->nlp_last_elscmd = ELS_CMD_PLOGI;
}
out:
ndlp->nlp_prev_state = ndlp->nlp_state;
lpfc_nlp_set_state(vport, ndlp, NLP_STE_NPR_NODE);
spin_lock_irq(shost->host_lock);
ndlp->nlp_flag &= ~NLP_NPR_ADISC;
spin_unlock_irq(shost->host_lock);
return 0;
}
static void
lpfc_rcv_prli(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
struct lpfc_iocbq *cmdiocb)
{
struct lpfc_dmabuf *pcmd;
uint32_t *lp;
PRLI *npr;
struct fc_rport *rport = ndlp->rport;
u32 roles;
pcmd = (struct lpfc_dmabuf *) cmdiocb->context2;
lp = (uint32_t *) pcmd->virt;
npr = (PRLI *) ((uint8_t *) lp + sizeof (uint32_t));
ndlp->nlp_type &= ~(NLP_FCP_TARGET | NLP_FCP_INITIATOR);
ndlp->nlp_fcp_info &= ~NLP_FCP_2_DEVICE;
ndlp->nlp_flag &= ~NLP_FIRSTBURST;
if (npr->prliType == PRLI_FCP_TYPE) {
if (npr->initiatorFunc)
ndlp->nlp_type |= NLP_FCP_INITIATOR;
if (npr->targetFunc) {
ndlp->nlp_type |= NLP_FCP_TARGET;
if (npr->writeXferRdyDis)
ndlp->nlp_flag |= NLP_FIRSTBURST;
}
if (npr->Retry)
ndlp->nlp_fcp_info |= NLP_FCP_2_DEVICE;
}
if (rport) {
roles = FC_RPORT_ROLE_UNKNOWN;
if (ndlp->nlp_type & NLP_FCP_INITIATOR)
roles |= FC_RPORT_ROLE_FCP_INITIATOR;
if (ndlp->nlp_type & NLP_FCP_TARGET)
roles |= FC_RPORT_ROLE_FCP_TARGET;
lpfc_debugfs_disc_trc(vport, LPFC_DISC_TRC_RPORT,
"rport rolechg: role:x%x did:x%x flg:x%x",
roles, ndlp->nlp_DID, ndlp->nlp_flag);
fc_remote_port_rolechg(rport, roles);
}
}
static uint32_t
lpfc_disc_set_adisc(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
if (!(ndlp->nlp_flag & NLP_RPI_REGISTERED)) {
ndlp->nlp_flag &= ~NLP_NPR_ADISC;
return 0;
}
if (!(vport->fc_flag & FC_PT2PT)) {
if ((vport->cfg_use_adisc && (vport->fc_flag & FC_RSCN_MODE)) ||
((ndlp->nlp_fcp_info & NLP_FCP_2_DEVICE) &&
(ndlp->nlp_type & NLP_FCP_TARGET))) {
spin_lock_irq(shost->host_lock);
ndlp->nlp_flag |= NLP_NPR_ADISC;
spin_unlock_irq(shost->host_lock);
return 1;
}
}
ndlp->nlp_flag &= ~NLP_NPR_ADISC;
lpfc_unreg_rpi(vport, ndlp);
return 0;
}
void
lpfc_release_rpi(struct lpfc_hba *phba,
struct lpfc_vport *vport,
uint16_t rpi)
{
LPFC_MBOXQ_t *pmb;
int rc;
pmb = (LPFC_MBOXQ_t *) mempool_alloc(phba->mbox_mem_pool,
GFP_KERNEL);
if (!pmb)
lpfc_printf_vlog(vport, KERN_ERR, LOG_MBOX,
"2796 mailbox memory allocation failed \n");
else {
lpfc_unreg_login(phba, vport->vpi, rpi, pmb);
pmb->mbox_cmpl = lpfc_sli_def_mbox_cmpl;
rc = lpfc_sli_issue_mbox(phba, pmb, MBX_NOWAIT);
if (rc == MBX_NOT_FINISHED)
mempool_free(pmb, phba->mbox_mem_pool);
}
}
static uint32_t
lpfc_disc_illegal(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
struct lpfc_hba *phba;
LPFC_MBOXQ_t *pmb = (LPFC_MBOXQ_t *) arg;
uint16_t rpi;
phba = vport->phba;
if (!(phba->pport->load_flag & FC_UNLOADING) &&
(evt == NLP_EVT_CMPL_REG_LOGIN) &&
(!pmb->u.mb.mbxStatus)) {
rpi = pmb->u.mb.un.varWords[0];
lpfc_release_rpi(phba, vport, rpi);
}
lpfc_printf_vlog(vport, KERN_ERR, LOG_DISCOVERY,
"0271 Illegal State Transition: node x%x "
"event x%x, state x%x Data: x%x x%x\n",
ndlp->nlp_DID, evt, ndlp->nlp_state, ndlp->nlp_rpi,
ndlp->nlp_flag);
return ndlp->nlp_state;
}
static uint32_t
lpfc_cmpl_plogi_illegal(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
if (!(ndlp->nlp_flag & NLP_RCV_PLOGI)) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_DISCOVERY,
"0272 Illegal State Transition: node x%x "
"event x%x, state x%x Data: x%x x%x\n",
ndlp->nlp_DID, evt, ndlp->nlp_state, ndlp->nlp_rpi,
ndlp->nlp_flag);
}
return ndlp->nlp_state;
}
static uint32_t
lpfc_rcv_plogi_unused_node(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
struct lpfc_iocbq *cmdiocb;
cmdiocb = (struct lpfc_iocbq *) arg;
if (lpfc_rcv_plogi(vport, ndlp, cmdiocb)) {
return ndlp->nlp_state;
}
return NLP_STE_FREED_NODE;
}
static uint32_t
lpfc_rcv_els_unused_node(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
lpfc_issue_els_logo(vport, ndlp, 0);
return ndlp->nlp_state;
}
static uint32_t
lpfc_rcv_logo_unused_node(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
struct lpfc_iocbq *cmdiocb = (struct lpfc_iocbq *) arg;
spin_lock_irq(shost->host_lock);
ndlp->nlp_flag |= NLP_LOGO_ACC;
spin_unlock_irq(shost->host_lock);
lpfc_els_rsp_acc(vport, ELS_CMD_ACC, cmdiocb, ndlp, NULL);
return ndlp->nlp_state;
}
static uint32_t
lpfc_cmpl_logo_unused_node(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
return NLP_STE_FREED_NODE;
}
static uint32_t
lpfc_device_rm_unused_node(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
return NLP_STE_FREED_NODE;
}
static uint32_t
lpfc_device_recov_unused_node(struct lpfc_vport *vport,
struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
return ndlp->nlp_state;
}
static uint32_t
lpfc_rcv_plogi_plogi_issue(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
struct lpfc_hba *phba = vport->phba;
struct lpfc_iocbq *cmdiocb = arg;
struct lpfc_dmabuf *pcmd = (struct lpfc_dmabuf *) cmdiocb->context2;
uint32_t *lp = (uint32_t *) pcmd->virt;
struct serv_parm *sp = (struct serv_parm *) (lp + 1);
struct ls_rjt stat;
int port_cmp;
memset(&stat, 0, sizeof (struct ls_rjt));
phba->fc_stat.elsLogiCol++;
port_cmp = memcmp(&vport->fc_portname, &sp->portName,
sizeof(struct lpfc_name));
if (port_cmp >= 0) {
stat.un.b.lsRjtRsnCode = LSRJT_UNABLE_TPC;
stat.un.b.lsRjtRsnCodeExp = LSEXP_CMD_IN_PROGRESS;
lpfc_els_rsp_reject(vport, stat.un.lsRjtError, cmdiocb, ndlp,
NULL);
} else {
if (lpfc_rcv_plogi(vport, ndlp, cmdiocb) &&
(ndlp->nlp_flag & NLP_NPR_2B_DISC) &&
(vport->num_disc_nodes)) {
spin_lock_irq(shost->host_lock);
ndlp->nlp_flag &= ~NLP_NPR_2B_DISC;
spin_unlock_irq(shost->host_lock);
lpfc_more_plogi(vport);
if (vport->num_disc_nodes == 0) {
spin_lock_irq(shost->host_lock);
vport->fc_flag &= ~FC_NDISC_ACTIVE;
spin_unlock_irq(shost->host_lock);
lpfc_can_disctmo(vport);
lpfc_end_rscn(vport);
}
}
}
return ndlp->nlp_state;
}
static uint32_t
lpfc_rcv_prli_plogi_issue(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
struct lpfc_iocbq *cmdiocb = (struct lpfc_iocbq *) arg;
struct ls_rjt stat;
memset(&stat, 0, sizeof (struct ls_rjt));
stat.un.b.lsRjtRsnCode = LSRJT_LOGICAL_BSY;
stat.un.b.lsRjtRsnCodeExp = LSEXP_NOTHING_MORE;
lpfc_els_rsp_reject(vport, stat.un.lsRjtError, cmdiocb, ndlp, NULL);
return ndlp->nlp_state;
}
static uint32_t
lpfc_rcv_logo_plogi_issue(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
struct lpfc_iocbq *cmdiocb = (struct lpfc_iocbq *) arg;
lpfc_els_abort(vport->phba, ndlp);
lpfc_rcv_logo(vport, ndlp, cmdiocb, ELS_CMD_LOGO);
return ndlp->nlp_state;
}
static uint32_t
lpfc_rcv_els_plogi_issue(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
struct lpfc_hba *phba = vport->phba;
struct lpfc_iocbq *cmdiocb = (struct lpfc_iocbq *) arg;
lpfc_els_abort(phba, ndlp);
if (evt == NLP_EVT_RCV_LOGO) {
lpfc_els_rsp_acc(vport, ELS_CMD_ACC, cmdiocb, ndlp, NULL);
} else {
lpfc_issue_els_logo(vport, ndlp, 0);
}
mod_timer(&ndlp->nlp_delayfunc, jiffies + msecs_to_jiffies(1000 * 1));
spin_lock_irq(shost->host_lock);
ndlp->nlp_flag |= NLP_DELAY_TMO;
spin_unlock_irq(shost->host_lock);
ndlp->nlp_last_elscmd = ELS_CMD_PLOGI;
ndlp->nlp_prev_state = NLP_STE_PLOGI_ISSUE;
lpfc_nlp_set_state(vport, ndlp, NLP_STE_NPR_NODE);
return ndlp->nlp_state;
}
static uint32_t
lpfc_cmpl_plogi_plogi_issue(struct lpfc_vport *vport,
struct lpfc_nodelist *ndlp,
void *arg,
uint32_t evt)
{
struct lpfc_hba *phba = vport->phba;
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
struct lpfc_iocbq *cmdiocb, *rspiocb;
struct lpfc_dmabuf *pcmd, *prsp, *mp;
uint32_t *lp;
IOCB_t *irsp;
struct serv_parm *sp;
uint32_t ed_tov;
LPFC_MBOXQ_t *mbox;
int rc;
cmdiocb = (struct lpfc_iocbq *) arg;
rspiocb = cmdiocb->context_un.rsp_iocb;
if (ndlp->nlp_flag & NLP_ACC_REGLOGIN) {
return ndlp->nlp_state;
}
irsp = &rspiocb->iocb;
if (irsp->ulpStatus)
goto out;
pcmd = (struct lpfc_dmabuf *) cmdiocb->context2;
prsp = list_get_first(&pcmd->list, struct lpfc_dmabuf, list);
if (!prsp)
goto out;
lp = (uint32_t *) prsp->virt;
sp = (struct serv_parm *) ((uint8_t *) lp + sizeof (uint32_t));
if ((ndlp->nlp_DID != FDMI_DID) &&
(wwn_to_u64(sp->portName.u.wwn) == 0 ||
wwn_to_u64(sp->nodeName.u.wwn) == 0)) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_ELS,
"0142 PLOGI RSP: Invalid WWN.\n");
goto out;
}
if (!lpfc_check_sparm(vport, ndlp, sp, CLASS3, 0))
goto out;
lpfc_printf_vlog(vport, KERN_INFO, LOG_ELS,
"0121 PLOGI chkparm OK Data: x%x x%x x%x x%x\n",
ndlp->nlp_DID, ndlp->nlp_state,
ndlp->nlp_flag, ndlp->nlp_rpi);
if (vport->cfg_fcp_class == 2 && (sp->cls2.classValid))
ndlp->nlp_fcp_info |= CLASS2;
else
ndlp->nlp_fcp_info |= CLASS3;
ndlp->nlp_class_sup = 0;
if (sp->cls1.classValid)
ndlp->nlp_class_sup |= FC_COS_CLASS1;
if (sp->cls2.classValid)
ndlp->nlp_class_sup |= FC_COS_CLASS2;
if (sp->cls3.classValid)
ndlp->nlp_class_sup |= FC_COS_CLASS3;
if (sp->cls4.classValid)
ndlp->nlp_class_sup |= FC_COS_CLASS4;
ndlp->nlp_maxframe =
((sp->cmn.bbRcvSizeMsb & 0x0F) << 8) | sp->cmn.bbRcvSizeLsb;
if ((vport->fc_flag & FC_PT2PT) &&
(vport->fc_flag & FC_PT2PT_PLOGI)) {
ed_tov = be32_to_cpu(sp->cmn.e_d_tov);
if (sp->cmn.edtovResolution) {
ed_tov = (phba->fc_edtov + 999999) / 1000000;
}
if (ed_tov > phba->fc_edtov)
phba->fc_edtov = ed_tov;
phba->fc_ratov = (2 * phba->fc_edtov) / 1000;
memcpy(&phba->fc_fabparam, sp, sizeof(struct serv_parm));
if (phba->sli_rev == LPFC_SLI_REV4) {
lpfc_issue_reg_vfi(vport);
} else {
mbox = mempool_alloc(phba->mbox_mem_pool, GFP_KERNEL);
if (!mbox) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_ELS,
"0133 PLOGI: no memory "
"for config_link "
"Data: x%x x%x x%x x%x\n",
ndlp->nlp_DID, ndlp->nlp_state,
ndlp->nlp_flag, ndlp->nlp_rpi);
goto out;
}
lpfc_config_link(phba, mbox);
mbox->mbox_cmpl = lpfc_sli_def_mbox_cmpl;
mbox->vport = vport;
rc = lpfc_sli_issue_mbox(phba, mbox, MBX_NOWAIT);
if (rc == MBX_NOT_FINISHED) {
mempool_free(mbox, phba->mbox_mem_pool);
goto out;
}
}
}
lpfc_unreg_rpi(vport, ndlp);
mbox = mempool_alloc(phba->mbox_mem_pool, GFP_KERNEL);
if (!mbox) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_ELS,
"0018 PLOGI: no memory for reg_login "
"Data: x%x x%x x%x x%x\n",
ndlp->nlp_DID, ndlp->nlp_state,
ndlp->nlp_flag, ndlp->nlp_rpi);
goto out;
}
if (lpfc_reg_rpi(phba, vport->vpi, irsp->un.elsreq64.remoteID,
(uint8_t *) sp, mbox, ndlp->nlp_rpi) == 0) {
switch (ndlp->nlp_DID) {
case NameServer_DID:
mbox->mbox_cmpl = lpfc_mbx_cmpl_ns_reg_login;
break;
case FDMI_DID:
mbox->mbox_cmpl = lpfc_mbx_cmpl_fdmi_reg_login;
break;
default:
ndlp->nlp_flag |= NLP_REG_LOGIN_SEND;
mbox->mbox_cmpl = lpfc_mbx_cmpl_reg_login;
}
mbox->context2 = lpfc_nlp_get(ndlp);
mbox->vport = vport;
if (lpfc_sli_issue_mbox(phba, mbox, MBX_NOWAIT)
!= MBX_NOT_FINISHED) {
lpfc_nlp_set_state(vport, ndlp,
NLP_STE_REG_LOGIN_ISSUE);
return ndlp->nlp_state;
}
if (ndlp->nlp_flag & NLP_REG_LOGIN_SEND)
ndlp->nlp_flag &= ~NLP_REG_LOGIN_SEND;
lpfc_nlp_put(ndlp);
mp = (struct lpfc_dmabuf *) mbox->context1;
lpfc_mbuf_free(phba, mp->virt, mp->phys);
kfree(mp);
mempool_free(mbox, phba->mbox_mem_pool);
lpfc_printf_vlog(vport, KERN_ERR, LOG_ELS,
"0134 PLOGI: cannot issue reg_login "
"Data: x%x x%x x%x x%x\n",
ndlp->nlp_DID, ndlp->nlp_state,
ndlp->nlp_flag, ndlp->nlp_rpi);
} else {
mempool_free(mbox, phba->mbox_mem_pool);
lpfc_printf_vlog(vport, KERN_ERR, LOG_ELS,
"0135 PLOGI: cannot format reg_login "
"Data: x%x x%x x%x x%x\n",
ndlp->nlp_DID, ndlp->nlp_state,
ndlp->nlp_flag, ndlp->nlp_rpi);
}
out:
if (ndlp->nlp_DID == NameServer_DID) {
lpfc_vport_set_state(vport, FC_VPORT_FAILED);
lpfc_printf_vlog(vport, KERN_ERR, LOG_ELS,
"0261 Cannot Register NameServer login\n");
}
ndlp->nlp_prev_state = ndlp->nlp_state;
lpfc_nlp_set_state(vport, ndlp, NLP_STE_NPR_NODE);
spin_lock_irq(shost->host_lock);
ndlp->nlp_flag |= NLP_DEFER_RM;
spin_unlock_irq(shost->host_lock);
return NLP_STE_FREED_NODE;
}
static uint32_t
lpfc_cmpl_logo_plogi_issue(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
return ndlp->nlp_state;
}
static uint32_t
lpfc_cmpl_reglogin_plogi_issue(struct lpfc_vport *vport,
struct lpfc_nodelist *ndlp, void *arg, uint32_t evt)
{
struct lpfc_hba *phba;
LPFC_MBOXQ_t *pmb = (LPFC_MBOXQ_t *) arg;
MAILBOX_t *mb = &pmb->u.mb;
uint16_t rpi;
phba = vport->phba;
if (!(phba->pport->load_flag & FC_UNLOADING) &&
!mb->mbxStatus) {
rpi = pmb->u.mb.un.varWords[0];
lpfc_release_rpi(phba, vport, rpi);
}
return ndlp->nlp_state;
}
static uint32_t
lpfc_device_rm_plogi_issue(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
if (ndlp->nlp_flag & NLP_NPR_2B_DISC) {
spin_lock_irq(shost->host_lock);
ndlp->nlp_flag |= NLP_NODEV_REMOVE;
spin_unlock_irq(shost->host_lock);
return ndlp->nlp_state;
} else {
lpfc_els_abort(vport->phba, ndlp);
lpfc_drop_node(vport, ndlp);
return NLP_STE_FREED_NODE;
}
}
static uint32_t
lpfc_device_recov_plogi_issue(struct lpfc_vport *vport,
struct lpfc_nodelist *ndlp,
void *arg,
uint32_t evt)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
struct lpfc_hba *phba = vport->phba;
if (vport->fc_flag & FC_RSCN_DEFERRED)
return ndlp->nlp_state;
lpfc_els_abort(phba, ndlp);
ndlp->nlp_prev_state = NLP_STE_PLOGI_ISSUE;
lpfc_nlp_set_state(vport, ndlp, NLP_STE_NPR_NODE);
spin_lock_irq(shost->host_lock);
ndlp->nlp_flag &= ~(NLP_NODEV_REMOVE | NLP_NPR_2B_DISC);
spin_unlock_irq(shost->host_lock);
return ndlp->nlp_state;
}
static uint32_t
lpfc_rcv_plogi_adisc_issue(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
struct lpfc_hba *phba = vport->phba;
struct lpfc_iocbq *cmdiocb;
lpfc_els_abort(phba, ndlp);
cmdiocb = (struct lpfc_iocbq *) arg;
if (lpfc_rcv_plogi(vport, ndlp, cmdiocb)) {
if (ndlp->nlp_flag & NLP_NPR_2B_DISC) {
spin_lock_irq(shost->host_lock);
ndlp->nlp_flag &= ~NLP_NPR_2B_DISC;
spin_unlock_irq(shost->host_lock);
if (vport->num_disc_nodes)
lpfc_more_adisc(vport);
}
return ndlp->nlp_state;
}
ndlp->nlp_prev_state = NLP_STE_ADISC_ISSUE;
lpfc_issue_els_plogi(vport, ndlp->nlp_DID, 0);
lpfc_nlp_set_state(vport, ndlp, NLP_STE_PLOGI_ISSUE);
return ndlp->nlp_state;
}
static uint32_t
lpfc_rcv_prli_adisc_issue(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
struct lpfc_iocbq *cmdiocb = (struct lpfc_iocbq *) arg;
lpfc_els_rsp_prli_acc(vport, cmdiocb, ndlp);
return ndlp->nlp_state;
}
static uint32_t
lpfc_rcv_logo_adisc_issue(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
struct lpfc_hba *phba = vport->phba;
struct lpfc_iocbq *cmdiocb;
cmdiocb = (struct lpfc_iocbq *) arg;
lpfc_els_abort(phba, ndlp);
lpfc_rcv_logo(vport, ndlp, cmdiocb, ELS_CMD_LOGO);
return ndlp->nlp_state;
}
static uint32_t
lpfc_rcv_padisc_adisc_issue(struct lpfc_vport *vport,
struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
struct lpfc_iocbq *cmdiocb;
cmdiocb = (struct lpfc_iocbq *) arg;
lpfc_rcv_padisc(vport, ndlp, cmdiocb);
return ndlp->nlp_state;
}
static uint32_t
lpfc_rcv_prlo_adisc_issue(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
struct lpfc_iocbq *cmdiocb;
cmdiocb = (struct lpfc_iocbq *) arg;
lpfc_rcv_logo(vport, ndlp, cmdiocb, ELS_CMD_PRLO);
return ndlp->nlp_state;
}
static uint32_t
lpfc_cmpl_adisc_adisc_issue(struct lpfc_vport *vport,
struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
struct lpfc_hba *phba = vport->phba;
struct lpfc_iocbq *cmdiocb, *rspiocb;
IOCB_t *irsp;
ADISC *ap;
int rc;
cmdiocb = (struct lpfc_iocbq *) arg;
rspiocb = cmdiocb->context_un.rsp_iocb;
ap = (ADISC *)lpfc_check_elscmpl_iocb(phba, cmdiocb, rspiocb);
irsp = &rspiocb->iocb;
if ((irsp->ulpStatus) ||
(!lpfc_check_adisc(vport, ndlp, &ap->nodeName, &ap->portName))) {
mod_timer(&ndlp->nlp_delayfunc,
jiffies + msecs_to_jiffies(1000));
spin_lock_irq(shost->host_lock);
ndlp->nlp_flag |= NLP_DELAY_TMO;
spin_unlock_irq(shost->host_lock);
ndlp->nlp_last_elscmd = ELS_CMD_PLOGI;
memset(&ndlp->nlp_nodename, 0, sizeof(struct lpfc_name));
memset(&ndlp->nlp_portname, 0, sizeof(struct lpfc_name));
ndlp->nlp_prev_state = NLP_STE_ADISC_ISSUE;
lpfc_nlp_set_state(vport, ndlp, NLP_STE_NPR_NODE);
lpfc_unreg_rpi(vport, ndlp);
return ndlp->nlp_state;
}
if (phba->sli_rev == LPFC_SLI_REV4) {
rc = lpfc_sli4_resume_rpi(ndlp, NULL, NULL);
if (rc) {
ndlp->nlp_prev_state = NLP_STE_ADISC_ISSUE;
return ndlp->nlp_state;
}
}
if (ndlp->nlp_type & NLP_FCP_TARGET) {
ndlp->nlp_prev_state = NLP_STE_ADISC_ISSUE;
lpfc_nlp_set_state(vport, ndlp, NLP_STE_MAPPED_NODE);
} else {
ndlp->nlp_prev_state = NLP_STE_ADISC_ISSUE;
lpfc_nlp_set_state(vport, ndlp, NLP_STE_UNMAPPED_NODE);
}
return ndlp->nlp_state;
}
static uint32_t
lpfc_device_rm_adisc_issue(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
if (ndlp->nlp_flag & NLP_NPR_2B_DISC) {
spin_lock_irq(shost->host_lock);
ndlp->nlp_flag |= NLP_NODEV_REMOVE;
spin_unlock_irq(shost->host_lock);
return ndlp->nlp_state;
} else {
lpfc_els_abort(vport->phba, ndlp);
lpfc_drop_node(vport, ndlp);
return NLP_STE_FREED_NODE;
}
}
static uint32_t
lpfc_device_recov_adisc_issue(struct lpfc_vport *vport,
struct lpfc_nodelist *ndlp,
void *arg,
uint32_t evt)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
struct lpfc_hba *phba = vport->phba;
if (vport->fc_flag & FC_RSCN_DEFERRED)
return ndlp->nlp_state;
lpfc_els_abort(phba, ndlp);
ndlp->nlp_prev_state = NLP_STE_ADISC_ISSUE;
lpfc_nlp_set_state(vport, ndlp, NLP_STE_NPR_NODE);
spin_lock_irq(shost->host_lock);
ndlp->nlp_flag &= ~(NLP_NODEV_REMOVE | NLP_NPR_2B_DISC);
spin_unlock_irq(shost->host_lock);
lpfc_disc_set_adisc(vport, ndlp);
return ndlp->nlp_state;
}
static uint32_t
lpfc_rcv_plogi_reglogin_issue(struct lpfc_vport *vport,
struct lpfc_nodelist *ndlp,
void *arg,
uint32_t evt)
{
struct lpfc_iocbq *cmdiocb = (struct lpfc_iocbq *) arg;
lpfc_rcv_plogi(vport, ndlp, cmdiocb);
return ndlp->nlp_state;
}
static uint32_t
lpfc_rcv_prli_reglogin_issue(struct lpfc_vport *vport,
struct lpfc_nodelist *ndlp,
void *arg,
uint32_t evt)
{
struct lpfc_iocbq *cmdiocb = (struct lpfc_iocbq *) arg;
lpfc_els_rsp_prli_acc(vport, cmdiocb, ndlp);
return ndlp->nlp_state;
}
static uint32_t
lpfc_rcv_logo_reglogin_issue(struct lpfc_vport *vport,
struct lpfc_nodelist *ndlp,
void *arg,
uint32_t evt)
{
struct lpfc_hba *phba = vport->phba;
struct lpfc_iocbq *cmdiocb = (struct lpfc_iocbq *) arg;
LPFC_MBOXQ_t *mb;
LPFC_MBOXQ_t *nextmb;
struct lpfc_dmabuf *mp;
cmdiocb = (struct lpfc_iocbq *) arg;
if ((mb = phba->sli.mbox_active)) {
if ((mb->u.mb.mbxCommand == MBX_REG_LOGIN64) &&
(ndlp == (struct lpfc_nodelist *) mb->context2)) {
lpfc_nlp_put(ndlp);
mb->context2 = NULL;
mb->mbox_cmpl = lpfc_sli_def_mbox_cmpl;
}
}
spin_lock_irq(&phba->hbalock);
list_for_each_entry_safe(mb, nextmb, &phba->sli.mboxq, list) {
if ((mb->u.mb.mbxCommand == MBX_REG_LOGIN64) &&
(ndlp == (struct lpfc_nodelist *) mb->context2)) {
mp = (struct lpfc_dmabuf *) (mb->context1);
if (mp) {
__lpfc_mbuf_free(phba, mp->virt, mp->phys);
kfree(mp);
}
lpfc_nlp_put(ndlp);
list_del(&mb->list);
phba->sli.mboxq_cnt--;
mempool_free(mb, phba->mbox_mem_pool);
}
}
spin_unlock_irq(&phba->hbalock);
lpfc_rcv_logo(vport, ndlp, cmdiocb, ELS_CMD_LOGO);
return ndlp->nlp_state;
}
static uint32_t
lpfc_rcv_padisc_reglogin_issue(struct lpfc_vport *vport,
struct lpfc_nodelist *ndlp,
void *arg,
uint32_t evt)
{
struct lpfc_iocbq *cmdiocb = (struct lpfc_iocbq *) arg;
lpfc_rcv_padisc(vport, ndlp, cmdiocb);
return ndlp->nlp_state;
}
static uint32_t
lpfc_rcv_prlo_reglogin_issue(struct lpfc_vport *vport,
struct lpfc_nodelist *ndlp,
void *arg,
uint32_t evt)
{
struct lpfc_iocbq *cmdiocb;
cmdiocb = (struct lpfc_iocbq *) arg;
lpfc_els_rsp_acc(vport, ELS_CMD_PRLO, cmdiocb, ndlp, NULL);
return ndlp->nlp_state;
}
static uint32_t
lpfc_cmpl_reglogin_reglogin_issue(struct lpfc_vport *vport,
struct lpfc_nodelist *ndlp,
void *arg,
uint32_t evt)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
LPFC_MBOXQ_t *pmb = (LPFC_MBOXQ_t *) arg;
MAILBOX_t *mb = &pmb->u.mb;
uint32_t did = mb->un.varWords[1];
if (mb->mbxStatus) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_DISCOVERY,
"0246 RegLogin failed Data: x%x x%x x%x x%x "
"x%x\n",
did, mb->mbxStatus, vport->port_state,
mb->un.varRegLogin.vpi,
mb->un.varRegLogin.rpi);
if (mb->mbxStatus == MBXERR_RPI_FULL) {
ndlp->nlp_prev_state = NLP_STE_REG_LOGIN_ISSUE;
lpfc_nlp_set_state(vport, ndlp, NLP_STE_NPR_NODE);
return ndlp->nlp_state;
}
mod_timer(&ndlp->nlp_delayfunc,
jiffies + msecs_to_jiffies(1000 * 1));
spin_lock_irq(shost->host_lock);
ndlp->nlp_flag |= NLP_DELAY_TMO;
spin_unlock_irq(shost->host_lock);
ndlp->nlp_last_elscmd = ELS_CMD_PLOGI;
lpfc_issue_els_logo(vport, ndlp, 0);
ndlp->nlp_prev_state = NLP_STE_REG_LOGIN_ISSUE;
lpfc_nlp_set_state(vport, ndlp, NLP_STE_NPR_NODE);
return ndlp->nlp_state;
}
if (vport->phba->sli_rev < LPFC_SLI_REV4)
ndlp->nlp_rpi = mb->un.varWords[0];
ndlp->nlp_flag |= NLP_RPI_REGISTERED;
if (!(ndlp->nlp_type & NLP_FABRIC)) {
ndlp->nlp_prev_state = NLP_STE_REG_LOGIN_ISSUE;
lpfc_nlp_set_state(vport, ndlp, NLP_STE_PRLI_ISSUE);
lpfc_issue_els_prli(vport, ndlp, 0);
} else {
ndlp->nlp_prev_state = NLP_STE_REG_LOGIN_ISSUE;
lpfc_nlp_set_state(vport, ndlp, NLP_STE_UNMAPPED_NODE);
}
return ndlp->nlp_state;
}
static uint32_t
lpfc_device_rm_reglogin_issue(struct lpfc_vport *vport,
struct lpfc_nodelist *ndlp,
void *arg,
uint32_t evt)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
if (ndlp->nlp_flag & NLP_NPR_2B_DISC) {
spin_lock_irq(shost->host_lock);
ndlp->nlp_flag |= NLP_NODEV_REMOVE;
spin_unlock_irq(shost->host_lock);
return ndlp->nlp_state;
} else {
lpfc_drop_node(vport, ndlp);
return NLP_STE_FREED_NODE;
}
}
static uint32_t
lpfc_device_recov_reglogin_issue(struct lpfc_vport *vport,
struct lpfc_nodelist *ndlp,
void *arg,
uint32_t evt)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
if (vport->fc_flag & FC_RSCN_DEFERRED)
return ndlp->nlp_state;
ndlp->nlp_prev_state = NLP_STE_REG_LOGIN_ISSUE;
lpfc_nlp_set_state(vport, ndlp, NLP_STE_NPR_NODE);
spin_lock_irq(shost->host_lock);
ndlp->nlp_flag |= NLP_IGNR_REG_CMPL;
ndlp->nlp_flag &= ~(NLP_NODEV_REMOVE | NLP_NPR_2B_DISC);
spin_unlock_irq(shost->host_lock);
lpfc_disc_set_adisc(vport, ndlp);
return ndlp->nlp_state;
}
static uint32_t
lpfc_rcv_plogi_prli_issue(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
struct lpfc_iocbq *cmdiocb;
cmdiocb = (struct lpfc_iocbq *) arg;
lpfc_rcv_plogi(vport, ndlp, cmdiocb);
return ndlp->nlp_state;
}
static uint32_t
lpfc_rcv_prli_prli_issue(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
struct lpfc_iocbq *cmdiocb = (struct lpfc_iocbq *) arg;
lpfc_els_rsp_prli_acc(vport, cmdiocb, ndlp);
return ndlp->nlp_state;
}
static uint32_t
lpfc_rcv_logo_prli_issue(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
struct lpfc_iocbq *cmdiocb = (struct lpfc_iocbq *) arg;
lpfc_els_abort(vport->phba, ndlp);
lpfc_rcv_logo(vport, ndlp, cmdiocb, ELS_CMD_LOGO);
return ndlp->nlp_state;
}
static uint32_t
lpfc_rcv_padisc_prli_issue(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
struct lpfc_iocbq *cmdiocb = (struct lpfc_iocbq *) arg;
lpfc_rcv_padisc(vport, ndlp, cmdiocb);
return ndlp->nlp_state;
}
static uint32_t
lpfc_rcv_prlo_prli_issue(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
struct lpfc_iocbq *cmdiocb = (struct lpfc_iocbq *) arg;
lpfc_els_rsp_acc(vport, ELS_CMD_PRLO, cmdiocb, ndlp, NULL);
return ndlp->nlp_state;
}
static uint32_t
lpfc_cmpl_prli_prli_issue(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
struct lpfc_iocbq *cmdiocb, *rspiocb;
struct lpfc_hba *phba = vport->phba;
IOCB_t *irsp;
PRLI *npr;
cmdiocb = (struct lpfc_iocbq *) arg;
rspiocb = cmdiocb->context_un.rsp_iocb;
npr = (PRLI *)lpfc_check_elscmpl_iocb(phba, cmdiocb, rspiocb);
irsp = &rspiocb->iocb;
if (irsp->ulpStatus) {
if ((vport->port_type == LPFC_NPIV_PORT) &&
vport->cfg_restrict_login) {
goto out;
}
ndlp->nlp_prev_state = NLP_STE_PRLI_ISSUE;
lpfc_nlp_set_state(vport, ndlp, NLP_STE_UNMAPPED_NODE);
return ndlp->nlp_state;
}
ndlp->nlp_type &= ~(NLP_FCP_TARGET | NLP_FCP_INITIATOR);
ndlp->nlp_fcp_info &= ~NLP_FCP_2_DEVICE;
ndlp->nlp_flag &= ~NLP_FIRSTBURST;
if ((npr->acceptRspCode == PRLI_REQ_EXECUTED) &&
(npr->prliType == PRLI_FCP_TYPE)) {
if (npr->initiatorFunc)
ndlp->nlp_type |= NLP_FCP_INITIATOR;
if (npr->targetFunc) {
ndlp->nlp_type |= NLP_FCP_TARGET;
if (npr->writeXferRdyDis)
ndlp->nlp_flag |= NLP_FIRSTBURST;
}
if (npr->Retry)
ndlp->nlp_fcp_info |= NLP_FCP_2_DEVICE;
}
if (!(ndlp->nlp_type & NLP_FCP_TARGET) &&
(vport->port_type == LPFC_NPIV_PORT) &&
vport->cfg_restrict_login) {
out:
spin_lock_irq(shost->host_lock);
ndlp->nlp_flag |= NLP_TARGET_REMOVE;
spin_unlock_irq(shost->host_lock);
lpfc_issue_els_logo(vport, ndlp, 0);
ndlp->nlp_prev_state = NLP_STE_PRLI_ISSUE;
lpfc_nlp_set_state(vport, ndlp, NLP_STE_NPR_NODE);
return ndlp->nlp_state;
}
ndlp->nlp_prev_state = NLP_STE_PRLI_ISSUE;
if (ndlp->nlp_type & NLP_FCP_TARGET)
lpfc_nlp_set_state(vport, ndlp, NLP_STE_MAPPED_NODE);
else
lpfc_nlp_set_state(vport, ndlp, NLP_STE_UNMAPPED_NODE);
return ndlp->nlp_state;
}
static uint32_t
lpfc_device_rm_prli_issue(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
if (ndlp->nlp_flag & NLP_NPR_2B_DISC) {
spin_lock_irq(shost->host_lock);
ndlp->nlp_flag |= NLP_NODEV_REMOVE;
spin_unlock_irq(shost->host_lock);
return ndlp->nlp_state;
} else {
lpfc_els_abort(vport->phba, ndlp);
lpfc_drop_node(vport, ndlp);
return NLP_STE_FREED_NODE;
}
}
static uint32_t
lpfc_device_recov_prli_issue(struct lpfc_vport *vport,
struct lpfc_nodelist *ndlp,
void *arg,
uint32_t evt)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
struct lpfc_hba *phba = vport->phba;
if (vport->fc_flag & FC_RSCN_DEFERRED)
return ndlp->nlp_state;
lpfc_els_abort(phba, ndlp);
ndlp->nlp_prev_state = NLP_STE_PRLI_ISSUE;
lpfc_nlp_set_state(vport, ndlp, NLP_STE_NPR_NODE);
spin_lock_irq(shost->host_lock);
ndlp->nlp_flag &= ~(NLP_NODEV_REMOVE | NLP_NPR_2B_DISC);
spin_unlock_irq(shost->host_lock);
lpfc_disc_set_adisc(vport, ndlp);
return ndlp->nlp_state;
}
static uint32_t
lpfc_rcv_plogi_logo_issue(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
struct lpfc_iocbq *cmdiocb = (struct lpfc_iocbq *)arg;
struct ls_rjt stat;
memset(&stat, 0, sizeof(struct ls_rjt));
stat.un.b.lsRjtRsnCode = LSRJT_UNABLE_TPC;
stat.un.b.lsRjtRsnCodeExp = LSEXP_NOTHING_MORE;
lpfc_els_rsp_reject(vport, stat.un.lsRjtError, cmdiocb, ndlp, NULL);
return ndlp->nlp_state;
}
static uint32_t
lpfc_rcv_prli_logo_issue(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
struct lpfc_iocbq *cmdiocb = (struct lpfc_iocbq *)arg;
struct ls_rjt stat;
memset(&stat, 0, sizeof(struct ls_rjt));
stat.un.b.lsRjtRsnCode = LSRJT_UNABLE_TPC;
stat.un.b.lsRjtRsnCodeExp = LSEXP_NOTHING_MORE;
lpfc_els_rsp_reject(vport, stat.un.lsRjtError, cmdiocb, ndlp, NULL);
return ndlp->nlp_state;
}
static uint32_t
lpfc_rcv_logo_logo_issue(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
struct lpfc_iocbq *cmdiocb = (struct lpfc_iocbq *)arg;
spin_lock_irq(shost->host_lock);
ndlp->nlp_flag |= NLP_LOGO_ACC;
spin_unlock_irq(shost->host_lock);
lpfc_els_rsp_acc(vport, ELS_CMD_ACC, cmdiocb, ndlp, NULL);
return ndlp->nlp_state;
}
static uint32_t
lpfc_rcv_padisc_logo_issue(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
struct lpfc_iocbq *cmdiocb = (struct lpfc_iocbq *)arg;
struct ls_rjt stat;
memset(&stat, 0, sizeof(struct ls_rjt));
stat.un.b.lsRjtRsnCode = LSRJT_UNABLE_TPC;
stat.un.b.lsRjtRsnCodeExp = LSEXP_NOTHING_MORE;
lpfc_els_rsp_reject(vport, stat.un.lsRjtError, cmdiocb, ndlp, NULL);
return ndlp->nlp_state;
}
static uint32_t
lpfc_rcv_prlo_logo_issue(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
struct lpfc_iocbq *cmdiocb = (struct lpfc_iocbq *)arg;
struct ls_rjt stat;
memset(&stat, 0, sizeof(struct ls_rjt));
stat.un.b.lsRjtRsnCode = LSRJT_UNABLE_TPC;
stat.un.b.lsRjtRsnCodeExp = LSEXP_NOTHING_MORE;
lpfc_els_rsp_reject(vport, stat.un.lsRjtError, cmdiocb, ndlp, NULL);
return ndlp->nlp_state;
}
static uint32_t
lpfc_cmpl_logo_logo_issue(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
ndlp->nlp_prev_state = NLP_STE_LOGO_ISSUE;
lpfc_nlp_set_state(vport, ndlp, NLP_STE_NPR_NODE);
spin_lock_irq(shost->host_lock);
ndlp->nlp_flag &= ~(NLP_NODEV_REMOVE | NLP_NPR_2B_DISC);
spin_unlock_irq(shost->host_lock);
lpfc_disc_set_adisc(vport, ndlp);
return ndlp->nlp_state;
}
static uint32_t
lpfc_device_rm_logo_issue(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
return ndlp->nlp_state;
}
static uint32_t
lpfc_device_recov_logo_issue(struct lpfc_vport *vport,
struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
return ndlp->nlp_state;
}
static uint32_t
lpfc_rcv_plogi_unmap_node(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
struct lpfc_iocbq *cmdiocb = (struct lpfc_iocbq *) arg;
lpfc_rcv_plogi(vport, ndlp, cmdiocb);
return ndlp->nlp_state;
}
static uint32_t
lpfc_rcv_prli_unmap_node(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
struct lpfc_iocbq *cmdiocb = (struct lpfc_iocbq *) arg;
lpfc_rcv_prli(vport, ndlp, cmdiocb);
lpfc_els_rsp_prli_acc(vport, cmdiocb, ndlp);
return ndlp->nlp_state;
}
static uint32_t
lpfc_rcv_logo_unmap_node(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
struct lpfc_iocbq *cmdiocb = (struct lpfc_iocbq *) arg;
lpfc_rcv_logo(vport, ndlp, cmdiocb, ELS_CMD_LOGO);
return ndlp->nlp_state;
}
static uint32_t
lpfc_rcv_padisc_unmap_node(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
struct lpfc_iocbq *cmdiocb = (struct lpfc_iocbq *) arg;
lpfc_rcv_padisc(vport, ndlp, cmdiocb);
return ndlp->nlp_state;
}
static uint32_t
lpfc_rcv_prlo_unmap_node(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
struct lpfc_iocbq *cmdiocb = (struct lpfc_iocbq *) arg;
lpfc_els_rsp_acc(vport, ELS_CMD_PRLO, cmdiocb, ndlp, NULL);
return ndlp->nlp_state;
}
static uint32_t
lpfc_device_recov_unmap_node(struct lpfc_vport *vport,
struct lpfc_nodelist *ndlp,
void *arg,
uint32_t evt)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
ndlp->nlp_prev_state = NLP_STE_UNMAPPED_NODE;
lpfc_nlp_set_state(vport, ndlp, NLP_STE_NPR_NODE);
spin_lock_irq(shost->host_lock);
ndlp->nlp_flag &= ~(NLP_NODEV_REMOVE | NLP_NPR_2B_DISC);
spin_unlock_irq(shost->host_lock);
lpfc_disc_set_adisc(vport, ndlp);
return ndlp->nlp_state;
}
static uint32_t
lpfc_rcv_plogi_mapped_node(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
struct lpfc_iocbq *cmdiocb = (struct lpfc_iocbq *) arg;
lpfc_rcv_plogi(vport, ndlp, cmdiocb);
return ndlp->nlp_state;
}
static uint32_t
lpfc_rcv_prli_mapped_node(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
struct lpfc_iocbq *cmdiocb = (struct lpfc_iocbq *) arg;
lpfc_els_rsp_prli_acc(vport, cmdiocb, ndlp);
return ndlp->nlp_state;
}
static uint32_t
lpfc_rcv_logo_mapped_node(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
struct lpfc_iocbq *cmdiocb = (struct lpfc_iocbq *) arg;
lpfc_rcv_logo(vport, ndlp, cmdiocb, ELS_CMD_LOGO);
return ndlp->nlp_state;
}
static uint32_t
lpfc_rcv_padisc_mapped_node(struct lpfc_vport *vport,
struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
struct lpfc_iocbq *cmdiocb = (struct lpfc_iocbq *) arg;
lpfc_rcv_padisc(vport, ndlp, cmdiocb);
return ndlp->nlp_state;
}
static uint32_t
lpfc_rcv_prlo_mapped_node(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
struct lpfc_hba *phba = vport->phba;
struct lpfc_iocbq *cmdiocb = (struct lpfc_iocbq *) arg;
lpfc_sli_abort_iocb(vport, &phba->sli.ring[phba->sli.fcp_ring],
ndlp->nlp_sid, 0, LPFC_CTX_TGT);
lpfc_rcv_logo(vport, ndlp, cmdiocb, ELS_CMD_PRLO);
return ndlp->nlp_state;
}
static uint32_t
lpfc_device_recov_mapped_node(struct lpfc_vport *vport,
struct lpfc_nodelist *ndlp,
void *arg,
uint32_t evt)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
ndlp->nlp_prev_state = NLP_STE_MAPPED_NODE;
lpfc_nlp_set_state(vport, ndlp, NLP_STE_NPR_NODE);
spin_lock_irq(shost->host_lock);
ndlp->nlp_flag &= ~(NLP_NODEV_REMOVE | NLP_NPR_2B_DISC);
spin_unlock_irq(shost->host_lock);
lpfc_disc_set_adisc(vport, ndlp);
return ndlp->nlp_state;
}
static uint32_t
lpfc_rcv_plogi_npr_node(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
struct lpfc_iocbq *cmdiocb = (struct lpfc_iocbq *) arg;
if (ndlp->nlp_flag & (NLP_LOGO_SND | NLP_LOGO_ACC))
return ndlp->nlp_state;
if (lpfc_rcv_plogi(vport, ndlp, cmdiocb)) {
lpfc_cancel_retry_delay_tmo(vport, ndlp);
spin_lock_irq(shost->host_lock);
ndlp->nlp_flag &= ~(NLP_NPR_ADISC | NLP_NPR_2B_DISC);
spin_unlock_irq(shost->host_lock);
} else if (!(ndlp->nlp_flag & NLP_NPR_2B_DISC)) {
if (!(ndlp->nlp_flag & NLP_DELAY_TMO)) {
ndlp->nlp_prev_state = NLP_STE_NPR_NODE;
lpfc_nlp_set_state(vport, ndlp, NLP_STE_PLOGI_ISSUE);
lpfc_issue_els_plogi(vport, ndlp->nlp_DID, 0);
}
}
return ndlp->nlp_state;
}
static uint32_t
lpfc_rcv_prli_npr_node(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
struct lpfc_iocbq *cmdiocb = (struct lpfc_iocbq *) arg;
struct ls_rjt stat;
memset(&stat, 0, sizeof (struct ls_rjt));
stat.un.b.lsRjtRsnCode = LSRJT_UNABLE_TPC;
stat.un.b.lsRjtRsnCodeExp = LSEXP_NOTHING_MORE;
lpfc_els_rsp_reject(vport, stat.un.lsRjtError, cmdiocb, ndlp, NULL);
if (!(ndlp->nlp_flag & NLP_DELAY_TMO)) {
if (ndlp->nlp_flag & NLP_NPR_ADISC) {
spin_lock_irq(shost->host_lock);
ndlp->nlp_flag &= ~NLP_NPR_ADISC;
ndlp->nlp_prev_state = NLP_STE_NPR_NODE;
spin_unlock_irq(shost->host_lock);
lpfc_nlp_set_state(vport, ndlp, NLP_STE_ADISC_ISSUE);
lpfc_issue_els_adisc(vport, ndlp, 0);
} else {
ndlp->nlp_prev_state = NLP_STE_NPR_NODE;
lpfc_nlp_set_state(vport, ndlp, NLP_STE_PLOGI_ISSUE);
lpfc_issue_els_plogi(vport, ndlp->nlp_DID, 0);
}
}
return ndlp->nlp_state;
}
static uint32_t
lpfc_rcv_logo_npr_node(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
struct lpfc_iocbq *cmdiocb = (struct lpfc_iocbq *) arg;
lpfc_rcv_logo(vport, ndlp, cmdiocb, ELS_CMD_LOGO);
return ndlp->nlp_state;
}
static uint32_t
lpfc_rcv_padisc_npr_node(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
struct lpfc_iocbq *cmdiocb = (struct lpfc_iocbq *) arg;
lpfc_rcv_padisc(vport, ndlp, cmdiocb);
if (!(ndlp->nlp_flag & NLP_DELAY_TMO) &&
!(ndlp->nlp_flag & NLP_NPR_2B_DISC)) {
if (ndlp->nlp_flag & NLP_NPR_ADISC) {
ndlp->nlp_flag &= ~NLP_NPR_ADISC;
ndlp->nlp_prev_state = NLP_STE_NPR_NODE;
lpfc_nlp_set_state(vport, ndlp, NLP_STE_ADISC_ISSUE);
lpfc_issue_els_adisc(vport, ndlp, 0);
} else {
ndlp->nlp_prev_state = NLP_STE_NPR_NODE;
lpfc_nlp_set_state(vport, ndlp, NLP_STE_PLOGI_ISSUE);
lpfc_issue_els_plogi(vport, ndlp->nlp_DID, 0);
}
}
return ndlp->nlp_state;
}
static uint32_t
lpfc_rcv_prlo_npr_node(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
struct lpfc_iocbq *cmdiocb = (struct lpfc_iocbq *) arg;
spin_lock_irq(shost->host_lock);
ndlp->nlp_flag |= NLP_LOGO_ACC;
spin_unlock_irq(shost->host_lock);
lpfc_els_rsp_acc(vport, ELS_CMD_ACC, cmdiocb, ndlp, NULL);
if ((ndlp->nlp_flag & NLP_DELAY_TMO) == 0) {
mod_timer(&ndlp->nlp_delayfunc,
jiffies + msecs_to_jiffies(1000 * 1));
spin_lock_irq(shost->host_lock);
ndlp->nlp_flag |= NLP_DELAY_TMO;
ndlp->nlp_flag &= ~NLP_NPR_ADISC;
spin_unlock_irq(shost->host_lock);
ndlp->nlp_last_elscmd = ELS_CMD_PLOGI;
} else {
spin_lock_irq(shost->host_lock);
ndlp->nlp_flag &= ~NLP_NPR_ADISC;
spin_unlock_irq(shost->host_lock);
}
return ndlp->nlp_state;
}
static uint32_t
lpfc_cmpl_plogi_npr_node(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
struct lpfc_iocbq *cmdiocb, *rspiocb;
IOCB_t *irsp;
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
cmdiocb = (struct lpfc_iocbq *) arg;
rspiocb = cmdiocb->context_un.rsp_iocb;
irsp = &rspiocb->iocb;
if (irsp->ulpStatus) {
spin_lock_irq(shost->host_lock);
ndlp->nlp_flag |= NLP_DEFER_RM;
spin_unlock_irq(shost->host_lock);
return NLP_STE_FREED_NODE;
}
return ndlp->nlp_state;
}
static uint32_t
lpfc_cmpl_prli_npr_node(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
struct lpfc_iocbq *cmdiocb, *rspiocb;
IOCB_t *irsp;
cmdiocb = (struct lpfc_iocbq *) arg;
rspiocb = cmdiocb->context_un.rsp_iocb;
irsp = &rspiocb->iocb;
if (irsp->ulpStatus && (ndlp->nlp_flag & NLP_NODEV_REMOVE)) {
lpfc_drop_node(vport, ndlp);
return NLP_STE_FREED_NODE;
}
return ndlp->nlp_state;
}
static uint32_t
lpfc_cmpl_logo_npr_node(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
if (ndlp->nlp_DID == Fabric_DID) {
spin_lock_irq(shost->host_lock);
vport->fc_flag &= ~(FC_FABRIC | FC_PUBLIC_LOOP);
spin_unlock_irq(shost->host_lock);
}
lpfc_unreg_rpi(vport, ndlp);
return ndlp->nlp_state;
}
static uint32_t
lpfc_cmpl_adisc_npr_node(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
struct lpfc_iocbq *cmdiocb, *rspiocb;
IOCB_t *irsp;
cmdiocb = (struct lpfc_iocbq *) arg;
rspiocb = cmdiocb->context_un.rsp_iocb;
irsp = &rspiocb->iocb;
if (irsp->ulpStatus && (ndlp->nlp_flag & NLP_NODEV_REMOVE)) {
lpfc_drop_node(vport, ndlp);
return NLP_STE_FREED_NODE;
}
return ndlp->nlp_state;
}
static uint32_t
lpfc_cmpl_reglogin_npr_node(struct lpfc_vport *vport,
struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
LPFC_MBOXQ_t *pmb = (LPFC_MBOXQ_t *) arg;
MAILBOX_t *mb = &pmb->u.mb;
if (!mb->mbxStatus) {
if (vport->phba->sli_rev < LPFC_SLI_REV4)
ndlp->nlp_rpi = mb->un.varWords[0];
ndlp->nlp_flag |= NLP_RPI_REGISTERED;
if (ndlp->nlp_flag & NLP_LOGO_ACC) {
lpfc_unreg_rpi(vport, ndlp);
}
} else {
if (ndlp->nlp_flag & NLP_NODEV_REMOVE) {
lpfc_drop_node(vport, ndlp);
return NLP_STE_FREED_NODE;
}
}
return ndlp->nlp_state;
}
static uint32_t
lpfc_device_rm_npr_node(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
if (ndlp->nlp_flag & NLP_NPR_2B_DISC) {
spin_lock_irq(shost->host_lock);
ndlp->nlp_flag |= NLP_NODEV_REMOVE;
spin_unlock_irq(shost->host_lock);
return ndlp->nlp_state;
}
lpfc_drop_node(vport, ndlp);
return NLP_STE_FREED_NODE;
}
static uint32_t
lpfc_device_recov_npr_node(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
if (vport->fc_flag & FC_RSCN_DEFERRED)
return ndlp->nlp_state;
lpfc_cancel_retry_delay_tmo(vport, ndlp);
spin_lock_irq(shost->host_lock);
ndlp->nlp_flag &= ~(NLP_NODEV_REMOVE | NLP_NPR_2B_DISC);
spin_unlock_irq(shost->host_lock);
return ndlp->nlp_state;
}
int
lpfc_disc_state_machine(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
void *arg, uint32_t evt)
{
uint32_t cur_state, rc;
uint32_t(*func) (struct lpfc_vport *, struct lpfc_nodelist *, void *,
uint32_t);
uint32_t got_ndlp = 0;
if (lpfc_nlp_get(ndlp))
got_ndlp = 1;
cur_state = ndlp->nlp_state;
lpfc_printf_vlog(vport, KERN_INFO, LOG_DISCOVERY,
"0211 DSM in event x%x on NPort x%x in "
"state %d Data: x%x\n",
evt, ndlp->nlp_DID, cur_state, ndlp->nlp_flag);
lpfc_debugfs_disc_trc(vport, LPFC_DISC_TRC_DSM,
"DSM in: evt:%d ste:%d did:x%x",
evt, cur_state, ndlp->nlp_DID);
func = lpfc_disc_action[(cur_state * NLP_EVT_MAX_EVENT) + evt];
rc = (func) (vport, ndlp, arg, evt);
if (got_ndlp) {
lpfc_printf_vlog(vport, KERN_INFO, LOG_DISCOVERY,
"0212 DSM out state %d on NPort x%x Data: x%x\n",
rc, ndlp->nlp_DID, ndlp->nlp_flag);
lpfc_debugfs_disc_trc(vport, LPFC_DISC_TRC_DSM,
"DSM out: ste:%d did:x%x flg:x%x",
rc, ndlp->nlp_DID, ndlp->nlp_flag);
lpfc_nlp_put(ndlp);
} else {
lpfc_printf_vlog(vport, KERN_INFO, LOG_DISCOVERY,
"0213 DSM out state %d on NPort free\n", rc);
lpfc_debugfs_disc_trc(vport, LPFC_DISC_TRC_DSM,
"DSM out: ste:%d did:x%x flg:x%x",
rc, 0, 0);
}
return rc;
}
