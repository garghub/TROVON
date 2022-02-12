static int
lpfc_nvme_create_queue(struct nvme_fc_local_port *pnvme_lport,
unsigned int qidx, u16 qsize,
void **handle)
{
struct lpfc_nvme_lport *lport;
struct lpfc_vport *vport;
struct lpfc_nvme_qhandle *qhandle;
char *str;
lport = (struct lpfc_nvme_lport *)pnvme_lport->private;
vport = lport->vport;
qhandle = kzalloc(sizeof(struct lpfc_nvme_qhandle), GFP_KERNEL);
if (qhandle == NULL)
return -ENOMEM;
qhandle->cpu_id = smp_processor_id();
qhandle->qidx = qidx;
if (qidx) {
str = "IO ";
qhandle->index = ((qidx - 1) %
vport->phba->cfg_nvme_io_channel);
} else {
str = "ADM";
qhandle->index = qidx;
}
lpfc_printf_vlog(vport, KERN_ERR, LOG_NVME,
"6073 Binding %s HdwQueue %d (cpu %d) to "
"io_channel %d qhandle %p\n", str,
qidx, qhandle->cpu_id, qhandle->index, qhandle);
*handle = (void *)qhandle;
return 0;
}
static void
lpfc_nvme_delete_queue(struct nvme_fc_local_port *pnvme_lport,
unsigned int qidx,
void *handle)
{
struct lpfc_nvme_lport *lport;
struct lpfc_vport *vport;
lport = (struct lpfc_nvme_lport *)pnvme_lport->private;
vport = lport->vport;
lpfc_printf_vlog(vport, KERN_INFO, LOG_NVME,
"6001 ENTER. lpfc_pnvme %p, qidx x%xi qhandle %p\n",
lport, qidx, handle);
kfree(handle);
}
static void
lpfc_nvme_localport_delete(struct nvme_fc_local_port *localport)
{
struct lpfc_nvme_lport *lport = localport->private;
complete(&lport->lport_unreg_done);
}
void
lpfc_nvme_remoteport_delete(struct nvme_fc_remote_port *remoteport)
{
struct lpfc_nvme_rport *rport = remoteport->private;
struct lpfc_vport *vport;
struct lpfc_nodelist *ndlp;
ndlp = rport->ndlp;
if (!ndlp)
goto rport_err;
vport = ndlp->vport;
if (!vport)
goto rport_err;
lpfc_printf_vlog(vport, KERN_INFO, LOG_NVME_DISC,
"6146 remoteport delete complete %p\n",
remoteport);
list_del(&rport->list);
lpfc_nlp_put(ndlp);
rport_err:
complete(&rport->rport_unreg_done);
}
static void
lpfc_nvme_cmpl_gen_req(struct lpfc_hba *phba, struct lpfc_iocbq *cmdwqe,
struct lpfc_wcqe_complete *wcqe)
{
struct lpfc_vport *vport = cmdwqe->vport;
uint32_t status;
struct nvmefc_ls_req *pnvme_lsreq;
struct lpfc_dmabuf *buf_ptr;
struct lpfc_nodelist *ndlp;
vport->phba->fc4NvmeLsCmpls++;
pnvme_lsreq = (struct nvmefc_ls_req *)cmdwqe->context2;
status = bf_get(lpfc_wcqe_c_status, wcqe) & LPFC_IOCB_STATUS_MASK;
ndlp = (struct lpfc_nodelist *)cmdwqe->context1;
lpfc_printf_vlog(vport, KERN_INFO, LOG_NVME_DISC,
"6047 nvme cmpl Enter "
"Data %p DID %x Xri: %x status %x cmd:%p lsreg:%p "
"bmp:%p ndlp:%p\n",
pnvme_lsreq, ndlp ? ndlp->nlp_DID : 0,
cmdwqe->sli4_xritag, status,
cmdwqe, pnvme_lsreq, cmdwqe->context3, ndlp);
lpfc_nvmeio_data(phba, "NVME LS CMPL: xri x%x stat x%x parm x%x\n",
cmdwqe->sli4_xritag, status, wcqe->parameter);
if (cmdwqe->context3) {
buf_ptr = (struct lpfc_dmabuf *)cmdwqe->context3;
lpfc_mbuf_free(phba, buf_ptr->virt, buf_ptr->phys);
kfree(buf_ptr);
cmdwqe->context3 = NULL;
}
if (pnvme_lsreq->done)
pnvme_lsreq->done(pnvme_lsreq, status);
else
lpfc_printf_vlog(vport, KERN_ERR, LOG_NVME_DISC,
"6046 nvme cmpl without done call back? "
"Data %p DID %x Xri: %x status %x\n",
pnvme_lsreq, ndlp ? ndlp->nlp_DID : 0,
cmdwqe->sli4_xritag, status);
if (ndlp) {
lpfc_nlp_put(ndlp);
cmdwqe->context1 = NULL;
}
lpfc_sli_release_iocbq(phba, cmdwqe);
}
static int
lpfc_nvme_gen_req(struct lpfc_vport *vport, struct lpfc_dmabuf *bmp,
struct lpfc_dmabuf *inp,
struct nvmefc_ls_req *pnvme_lsreq,
void (*cmpl)(struct lpfc_hba *, struct lpfc_iocbq *,
struct lpfc_wcqe_complete *),
struct lpfc_nodelist *ndlp, uint32_t num_entry,
uint32_t tmo, uint8_t retry)
{
struct lpfc_hba *phba = vport->phba;
union lpfc_wqe *wqe;
struct lpfc_iocbq *genwqe;
struct ulp_bde64 *bpl;
struct ulp_bde64 bde;
int i, rc, xmit_len, first_len;
genwqe = lpfc_sli_get_iocbq(phba);
if (genwqe == NULL)
return 1;
wqe = &genwqe->wqe;
memset(wqe, 0, sizeof(union lpfc_wqe));
genwqe->context3 = (uint8_t *)bmp;
genwqe->iocb_flag |= LPFC_IO_NVME_LS;
genwqe->context1 = lpfc_nlp_get(ndlp);
genwqe->context2 = (uint8_t *)pnvme_lsreq;
if (!tmo)
tmo = (3 * phba->fc_ratov);
xmit_len = 0;
first_len = 0;
bpl = (struct ulp_bde64 *)bmp->virt;
for (i = 0; i < num_entry; i++) {
bde.tus.w = bpl[i].tus.w;
if (bde.tus.f.bdeFlags != BUFF_TYPE_BDE_64)
break;
xmit_len += bde.tus.f.bdeSize;
if (i == 0)
first_len = xmit_len;
}
genwqe->rsvd2 = num_entry;
genwqe->hba_wqidx = 0;
wqe->generic.bde.tus.f.bdeFlags = BUFF_TYPE_BDE_64;
wqe->generic.bde.tus.f.bdeSize = first_len;
wqe->generic.bde.addrLow = bpl[0].addrLow;
wqe->generic.bde.addrHigh = bpl[0].addrHigh;
wqe->gen_req.request_payload_len = first_len;
bf_set(wqe_dfctl, &wqe->gen_req.wge_ctl, 0);
bf_set(wqe_si, &wqe->gen_req.wge_ctl, 1);
bf_set(wqe_la, &wqe->gen_req.wge_ctl, 1);
bf_set(wqe_rctl, &wqe->gen_req.wge_ctl, FC_RCTL_ELS4_REQ);
bf_set(wqe_type, &wqe->gen_req.wge_ctl, FC_TYPE_NVME);
bf_set(wqe_ctxt_tag, &wqe->gen_req.wqe_com,
phba->sli4_hba.rpi_ids[ndlp->nlp_rpi]);
bf_set(wqe_xri_tag, &wqe->gen_req.wqe_com, genwqe->sli4_xritag);
bf_set(wqe_tmo, &wqe->gen_req.wqe_com, (vport->phba->fc_ratov-1));
bf_set(wqe_class, &wqe->gen_req.wqe_com, CLASS3);
bf_set(wqe_cmnd, &wqe->gen_req.wqe_com, CMD_GEN_REQUEST64_WQE);
bf_set(wqe_ct, &wqe->gen_req.wqe_com, SLI4_CT_RPI);
wqe->gen_req.wqe_com.abort_tag = genwqe->iotag;
bf_set(wqe_reqtag, &wqe->gen_req.wqe_com, genwqe->iotag);
bf_set(wqe_dbde, &wqe->gen_req.wqe_com, 1);
bf_set(wqe_iod, &wqe->gen_req.wqe_com, LPFC_WQE_IOD_READ);
bf_set(wqe_qosd, &wqe->gen_req.wqe_com, 1);
bf_set(wqe_lenloc, &wqe->gen_req.wqe_com, LPFC_WQE_LENLOC_NONE);
bf_set(wqe_ebde_cnt, &wqe->gen_req.wqe_com, 0);
bf_set(wqe_cqid, &wqe->gen_req.wqe_com, LPFC_WQE_CQ_ID_DEFAULT);
bf_set(wqe_cmd_type, &wqe->gen_req.wqe_com, OTHER_COMMAND);
lpfc_printf_vlog(vport, KERN_INFO, LOG_ELS,
"6050 Issue GEN REQ WQE to NPORT x%x "
"Data: x%x x%x wq:%p lsreq:%p bmp:%p xmit:%d 1st:%d\n",
ndlp->nlp_DID, genwqe->iotag,
vport->port_state,
genwqe, pnvme_lsreq, bmp, xmit_len, first_len);
genwqe->wqe_cmpl = cmpl;
genwqe->iocb_cmpl = NULL;
genwqe->drvrTimeout = tmo + LPFC_DRVR_TIMEOUT;
genwqe->vport = vport;
genwqe->retry = retry;
lpfc_nvmeio_data(phba, "NVME LS XMIT: xri x%x iotag x%x to x%06x\n",
genwqe->sli4_xritag, genwqe->iotag, ndlp->nlp_DID);
rc = lpfc_sli4_issue_wqe(phba, LPFC_ELS_RING, genwqe);
if (rc == WQE_ERROR) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_ELS,
"6045 Issue GEN REQ WQE to NPORT x%x "
"Data: x%x x%x\n",
ndlp->nlp_DID, genwqe->iotag,
vport->port_state);
lpfc_sli_release_iocbq(phba, genwqe);
return 1;
}
return 0;
}
static int
lpfc_nvme_ls_req(struct nvme_fc_local_port *pnvme_lport,
struct nvme_fc_remote_port *pnvme_rport,
struct nvmefc_ls_req *pnvme_lsreq)
{
int ret = 0;
struct lpfc_nvme_lport *lport;
struct lpfc_vport *vport;
struct lpfc_nodelist *ndlp;
struct ulp_bde64 *bpl;
struct lpfc_dmabuf *bmp;
uint16_t ntype, nstate;
lport = (struct lpfc_nvme_lport *)pnvme_lport->private;
vport = lport->vport;
ndlp = lpfc_findnode_did(vport, pnvme_rport->port_id);
if (!ndlp || !NLP_CHK_NODE_ACT(ndlp)) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_NODE | LOG_NVME_IOERR,
"6051 DID x%06x not an active rport.\n",
pnvme_rport->port_id);
return -ENODEV;
}
ntype = ndlp->nlp_type;
nstate = ndlp->nlp_state;
if ((ntype & NLP_NVME_TARGET && nstate != NLP_STE_MAPPED_NODE) ||
(ntype & NLP_NVME_INITIATOR && nstate != NLP_STE_UNMAPPED_NODE)) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_NODE | LOG_NVME_IOERR,
"6088 DID x%06x not ready for "
"IO. State x%x, Type x%x\n",
pnvme_rport->port_id,
ndlp->nlp_state, ndlp->nlp_type);
return -ENODEV;
}
bmp = kmalloc(sizeof(struct lpfc_dmabuf), GFP_KERNEL);
if (!bmp) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_NVME_DISC,
"6044 Could not find node for DID %x\n",
pnvme_rport->port_id);
return 2;
}
INIT_LIST_HEAD(&bmp->list);
bmp->virt = lpfc_mbuf_alloc(vport->phba, MEM_PRI, &(bmp->phys));
if (!bmp->virt) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_NVME_DISC,
"6042 Could not find node for DID %x\n",
pnvme_rport->port_id);
kfree(bmp);
return 3;
}
bpl = (struct ulp_bde64 *)bmp->virt;
bpl->addrHigh = le32_to_cpu(putPaddrHigh(pnvme_lsreq->rqstdma));
bpl->addrLow = le32_to_cpu(putPaddrLow(pnvme_lsreq->rqstdma));
bpl->tus.f.bdeFlags = 0;
bpl->tus.f.bdeSize = pnvme_lsreq->rqstlen;
bpl->tus.w = le32_to_cpu(bpl->tus.w);
bpl++;
bpl->addrHigh = le32_to_cpu(putPaddrHigh(pnvme_lsreq->rspdma));
bpl->addrLow = le32_to_cpu(putPaddrLow(pnvme_lsreq->rspdma));
bpl->tus.f.bdeFlags = BUFF_TYPE_BDE_64I;
bpl->tus.f.bdeSize = pnvme_lsreq->rsplen;
bpl->tus.w = le32_to_cpu(bpl->tus.w);
lpfc_printf_vlog(vport, KERN_INFO, LOG_NVME_DISC,
"6149 ENTER. lport %p, rport %p lsreq%p rqstlen:%d "
"rsplen:%d %pad %pad\n",
pnvme_lport, pnvme_rport,
pnvme_lsreq, pnvme_lsreq->rqstlen,
pnvme_lsreq->rsplen, &pnvme_lsreq->rqstdma,
&pnvme_lsreq->rspdma);
vport->phba->fc4NvmeLsRequests++;
ret = lpfc_nvme_gen_req(vport, bmp, pnvme_lsreq->rqstaddr,
pnvme_lsreq, lpfc_nvme_cmpl_gen_req,
ndlp, 2, 30, 0);
if (ret != WQE_SUCCESS) {
lpfc_printf_vlog(vport, KERN_INFO, LOG_NVME_DISC,
"6052 EXIT. issue ls wqe failed lport %p, "
"rport %p lsreq%p Status %x DID %x\n",
pnvme_lport, pnvme_rport, pnvme_lsreq,
ret, ndlp->nlp_DID);
lpfc_mbuf_free(vport->phba, bmp->virt, bmp->phys);
kfree(bmp);
return ret;
}
return ret;
}
static void
lpfc_nvme_ls_abort(struct nvme_fc_local_port *pnvme_lport,
struct nvme_fc_remote_port *pnvme_rport,
struct nvmefc_ls_req *pnvme_lsreq)
{
struct lpfc_nvme_lport *lport;
struct lpfc_vport *vport;
struct lpfc_hba *phba;
struct lpfc_nodelist *ndlp;
LIST_HEAD(abort_list);
struct lpfc_sli_ring *pring;
struct lpfc_iocbq *wqe, *next_wqe;
lport = (struct lpfc_nvme_lport *)pnvme_lport->private;
vport = lport->vport;
phba = vport->phba;
ndlp = lpfc_findnode_did(vport, pnvme_rport->port_id);
if (!ndlp) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_NVME_ABTS,
"6049 Could not find node for DID %x\n",
pnvme_rport->port_id);
return;
}
lpfc_printf_vlog(vport, KERN_INFO, LOG_NVME_ABTS,
"6040 ENTER. lport %p, rport %p lsreq %p rqstlen:%d "
"rsplen:%d %pad %pad\n",
pnvme_lport, pnvme_rport,
pnvme_lsreq, pnvme_lsreq->rqstlen,
pnvme_lsreq->rsplen, &pnvme_lsreq->rqstdma,
&pnvme_lsreq->rspdma);
pring = phba->sli4_hba.nvmels_wq->pring;
spin_lock_irq(&phba->hbalock);
spin_lock(&pring->ring_lock);
list_for_each_entry_safe(wqe, next_wqe, &pring->txcmplq, list) {
if (lpfc_check_sli_ndlp(phba, pring, wqe, ndlp)) {
wqe->iocb_flag |= LPFC_DRIVER_ABORTED;
list_add_tail(&wqe->dlist, &abort_list);
}
}
spin_unlock(&pring->ring_lock);
spin_unlock_irq(&phba->hbalock);
list_for_each_entry_safe(wqe, next_wqe, &abort_list, dlist) {
spin_lock_irq(&phba->hbalock);
list_del_init(&wqe->dlist);
lpfc_sli_issue_abort_iotag(phba, pring, wqe);
spin_unlock_irq(&phba->hbalock);
}
}
static void
lpfc_nvme_adj_fcp_sgls(struct lpfc_vport *vport,
struct lpfc_nvme_buf *lpfc_ncmd,
struct nvmefc_fcp_req *nCmd)
{
struct sli4_sge *sgl;
union lpfc_wqe128 *wqe;
uint32_t *wptr, *dptr;
sgl = lpfc_ncmd->nvme_sgl;
sgl->sge_len = cpu_to_le32(nCmd->cmdlen);
sgl++;
sgl->addr_hi = cpu_to_le32(putPaddrHigh(nCmd->rspdma));
sgl->addr_lo = cpu_to_le32(putPaddrLow(nCmd->rspdma));
sgl->word2 = le32_to_cpu(sgl->word2);
if (nCmd->sg_cnt)
bf_set(lpfc_sli4_sge_last, sgl, 0);
else
bf_set(lpfc_sli4_sge_last, sgl, 1);
sgl->word2 = cpu_to_le32(sgl->word2);
sgl->sge_len = cpu_to_le32(nCmd->rsplen);
wqe = (union lpfc_wqe128 *)&lpfc_ncmd->cur_iocbq.wqe;
wqe->generic.bde.tus.f.bdeFlags = BUFF_TYPE_BDE_IMMED;
wqe->generic.bde.tus.f.bdeSize = 60;
wqe->generic.bde.addrHigh = 0;
wqe->generic.bde.addrLow = 64;
bf_set(payload_offset_len, &wqe->fcp_icmd,
(nCmd->rsplen + nCmd->cmdlen));
bf_set(wqe_nvme, &wqe->fcp_icmd.wqe_com, 1);
bf_set(wqe_wqes, &wqe->fcp_icmd.wqe_com, 1);
wptr = &wqe->words[16];
dptr = (uint32_t *)nCmd->cmdaddr;
dptr++;
*wptr++ = *dptr++;
*wptr++ = *dptr++;
*wptr++ = *dptr++;
*wptr++ = *dptr++;
dptr++;
*wptr++ = *dptr++;
*wptr++ = *dptr++;
dptr += 8;
*wptr++ = *dptr++;
*wptr++ = *dptr++;
*wptr++ = *dptr++;
*wptr++ = *dptr++;
*wptr++ = *dptr++;
*wptr++ = *dptr++;
*wptr++ = *dptr++;
*wptr = *dptr;
}
static void
lpfc_nvme_ktime(struct lpfc_hba *phba,
struct lpfc_nvme_buf *lpfc_ncmd)
{
uint64_t seg1, seg2, seg3, seg4;
if (!phba->ktime_on)
return;
if (!lpfc_ncmd->ts_last_cmd ||
!lpfc_ncmd->ts_cmd_start ||
!lpfc_ncmd->ts_cmd_wqput ||
!lpfc_ncmd->ts_isr_cmpl ||
!lpfc_ncmd->ts_data_nvme)
return;
if (lpfc_ncmd->ts_cmd_start < lpfc_ncmd->ts_last_cmd)
return;
if (lpfc_ncmd->ts_cmd_wqput < lpfc_ncmd->ts_cmd_start)
return;
if (lpfc_ncmd->ts_isr_cmpl < lpfc_ncmd->ts_cmd_wqput)
return;
if (lpfc_ncmd->ts_data_nvme < lpfc_ncmd->ts_isr_cmpl)
return;
seg1 = lpfc_ncmd->ts_cmd_start - lpfc_ncmd->ts_last_cmd;
if (seg1 > 5000000)
return;
seg2 = (lpfc_ncmd->ts_cmd_wqput - lpfc_ncmd->ts_cmd_start);
seg3 = (lpfc_ncmd->ts_isr_cmpl -
lpfc_ncmd->ts_cmd_start) - seg2;
seg4 = (lpfc_ncmd->ts_data_nvme -
lpfc_ncmd->ts_cmd_start) - seg2 - seg3;
phba->ktime_data_samples++;
phba->ktime_seg1_total += seg1;
if (seg1 < phba->ktime_seg1_min)
phba->ktime_seg1_min = seg1;
else if (seg1 > phba->ktime_seg1_max)
phba->ktime_seg1_max = seg1;
phba->ktime_seg2_total += seg2;
if (seg2 < phba->ktime_seg2_min)
phba->ktime_seg2_min = seg2;
else if (seg2 > phba->ktime_seg2_max)
phba->ktime_seg2_max = seg2;
phba->ktime_seg3_total += seg3;
if (seg3 < phba->ktime_seg3_min)
phba->ktime_seg3_min = seg3;
else if (seg3 > phba->ktime_seg3_max)
phba->ktime_seg3_max = seg3;
phba->ktime_seg4_total += seg4;
if (seg4 < phba->ktime_seg4_min)
phba->ktime_seg4_min = seg4;
else if (seg4 > phba->ktime_seg4_max)
phba->ktime_seg4_max = seg4;
lpfc_ncmd->ts_last_cmd = 0;
lpfc_ncmd->ts_cmd_start = 0;
lpfc_ncmd->ts_cmd_wqput = 0;
lpfc_ncmd->ts_isr_cmpl = 0;
lpfc_ncmd->ts_data_nvme = 0;
}
static void
lpfc_nvme_io_cmd_wqe_cmpl(struct lpfc_hba *phba, struct lpfc_iocbq *pwqeIn,
struct lpfc_wcqe_complete *wcqe)
{
struct lpfc_nvme_buf *lpfc_ncmd =
(struct lpfc_nvme_buf *)pwqeIn->context1;
struct lpfc_vport *vport = pwqeIn->vport;
struct nvmefc_fcp_req *nCmd;
struct nvme_fc_ersp_iu *ep;
struct nvme_fc_cmd_iu *cp;
struct lpfc_nvme_rport *rport;
struct lpfc_nodelist *ndlp;
struct lpfc_nvme_fcpreq_priv *freqpriv;
unsigned long flags;
uint32_t code;
uint16_t cid, sqhd, data;
uint32_t *ptr;
if (!lpfc_ncmd || !lpfc_ncmd->nvmeCmd || !lpfc_ncmd->nrport) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_NODE | LOG_NVME_IOERR,
"6071 Completion pointers bad on wqe %p.\n",
wcqe);
return;
}
phba->fc4NvmeIoCmpls++;
nCmd = lpfc_ncmd->nvmeCmd;
rport = lpfc_ncmd->nrport;
lpfc_nvmeio_data(phba, "NVME FCP CMPL: xri x%x stat x%x parm x%x\n",
lpfc_ncmd->cur_iocbq.sli4_xritag,
bf_get(lpfc_wcqe_c_status, wcqe), wcqe->parameter);
ndlp = rport->ndlp;
if (!ndlp || !NLP_CHK_NODE_ACT(ndlp)) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_NODE | LOG_NVME_IOERR,
"6061 rport %p, DID x%06x node not ready.\n",
rport, rport->remoteport->port_id);
ndlp = lpfc_findnode_did(vport, rport->remoteport->port_id);
if (!ndlp) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_NVME_IOERR,
"6062 Ignoring NVME cmpl. No ndlp\n");
goto out_err;
}
}
code = bf_get(lpfc_wcqe_c_code, wcqe);
if (code == CQE_CODE_NVME_ERSP) {
ep = (struct nvme_fc_ersp_iu *)nCmd->rspaddr;
cp = (struct nvme_fc_cmd_iu *)nCmd->cmdaddr;
cid = cp->sqe.common.command_id;
sqhd = bf_get(lpfc_wcqe_c_sqhead, wcqe);
ep->iu_len = cpu_to_be16(8);
ep->rsn = wcqe->parameter;
ep->xfrd_len = cpu_to_be32(nCmd->payload_length);
ep->rsvd12 = 0;
ptr = (uint32_t *)&ep->cqe.result.u64;
*ptr++ = wcqe->total_data_placed;
data = bf_get(lpfc_wcqe_c_ersp0, wcqe);
*ptr = (uint32_t)data;
ep->cqe.sq_head = sqhd;
ep->cqe.sq_id = nCmd->sqid;
ep->cqe.command_id = cid;
ep->cqe.status = 0;
lpfc_ncmd->status = IOSTAT_SUCCESS;
lpfc_ncmd->result = 0;
nCmd->rcv_rsplen = LPFC_NVME_ERSP_LEN;
nCmd->transferred_length = nCmd->payload_length;
} else {
lpfc_ncmd->status = (bf_get(lpfc_wcqe_c_status, wcqe) &
LPFC_IOCB_STATUS_MASK);
lpfc_ncmd->result = wcqe->parameter;
switch (lpfc_ncmd->status) {
case IOSTAT_SUCCESS:
nCmd->transferred_length = wcqe->total_data_placed;
nCmd->rcv_rsplen = 0;
nCmd->status = 0;
break;
case IOSTAT_FCP_RSP_ERROR:
nCmd->transferred_length = wcqe->total_data_placed;
nCmd->rcv_rsplen = wcqe->parameter;
nCmd->status = 0;
if (nCmd->rcv_rsplen == LPFC_NVME_ERSP_LEN)
break;
lpfc_printf_vlog(vport, KERN_ERR, LOG_NVME_IOERR,
"6081 NVME Completion Protocol Error: "
"xri %x status x%x result x%x "
"placed x%x\n",
lpfc_ncmd->cur_iocbq.sli4_xritag,
lpfc_ncmd->status, lpfc_ncmd->result,
wcqe->total_data_placed);
break;
default:
out_err:
lpfc_printf_vlog(vport, KERN_ERR, LOG_NVME_IOERR,
"6072 NVME Completion Error: xri %x "
"status x%x result x%x placed x%x\n",
lpfc_ncmd->cur_iocbq.sli4_xritag,
lpfc_ncmd->status, lpfc_ncmd->result,
wcqe->total_data_placed);
nCmd->transferred_length = 0;
nCmd->rcv_rsplen = 0;
nCmd->status = NVME_SC_FC_TRANSPORT_ERROR;
}
}
if (bf_get(lpfc_wcqe_c_xb, wcqe))
lpfc_ncmd->flags |= LPFC_SBUF_XBUSY;
else
lpfc_ncmd->flags &= ~LPFC_SBUF_XBUSY;
if (ndlp && NLP_CHK_NODE_ACT(ndlp))
atomic_dec(&ndlp->cmd_pending);
#ifdef CONFIG_SCSI_LPFC_DEBUG_FS
if (phba->ktime_on) {
lpfc_ncmd->ts_isr_cmpl = pwqeIn->isr_timestamp;
lpfc_ncmd->ts_data_nvme = ktime_get_ns();
phba->ktime_last_cmd = lpfc_ncmd->ts_data_nvme;
lpfc_nvme_ktime(phba, lpfc_ncmd);
}
if (phba->cpucheck_on & LPFC_CHECK_NVME_IO) {
if (lpfc_ncmd->cpu != smp_processor_id())
lpfc_printf_vlog(vport, KERN_ERR, LOG_NVME_IOERR,
"6701 CPU Check cmpl: "
"cpu %d expect %d\n",
smp_processor_id(), lpfc_ncmd->cpu);
if (lpfc_ncmd->cpu < LPFC_CHECK_CPU_CNT)
phba->cpucheck_cmpl_io[lpfc_ncmd->cpu]++;
}
#endif
freqpriv = nCmd->private;
freqpriv->nvme_buf = NULL;
nCmd->done(nCmd);
spin_lock_irqsave(&phba->hbalock, flags);
lpfc_ncmd->nrport = NULL;
spin_unlock_irqrestore(&phba->hbalock, flags);
lpfc_release_nvme_buf(phba, lpfc_ncmd);
}
static int
lpfc_nvme_prep_io_cmd(struct lpfc_vport *vport,
struct lpfc_nvme_buf *lpfc_ncmd,
struct lpfc_nodelist *pnode)
{
struct lpfc_hba *phba = vport->phba;
struct nvmefc_fcp_req *nCmd = lpfc_ncmd->nvmeCmd;
struct lpfc_iocbq *pwqeq = &(lpfc_ncmd->cur_iocbq);
union lpfc_wqe128 *wqe = (union lpfc_wqe128 *)&pwqeq->wqe;
uint32_t req_len;
if (!pnode || !NLP_CHK_NODE_ACT(pnode))
return -EINVAL;
wqe->fcp_iwrite.initial_xfer_len = 0;
if (nCmd->sg_cnt) {
if (nCmd->io_dir == NVMEFC_FCP_WRITE) {
if ((phba->cfg_nvme_enable_fb) &&
(pnode->nlp_flag & NLP_FIRSTBURST)) {
req_len = lpfc_ncmd->nvmeCmd->payload_length;
if (req_len < pnode->nvme_fb_size)
wqe->fcp_iwrite.initial_xfer_len =
req_len;
else
wqe->fcp_iwrite.initial_xfer_len =
pnode->nvme_fb_size;
}
bf_set(wqe_cmnd, &wqe->generic.wqe_com,
CMD_FCP_IWRITE64_WQE);
bf_set(wqe_pu, &wqe->generic.wqe_com,
PARM_READ_CHECK);
bf_set(wqe_qosd, &wqe->fcp_iwrite.wqe_com, 0);
bf_set(wqe_iod, &wqe->fcp_iwrite.wqe_com,
LPFC_WQE_IOD_WRITE);
bf_set(wqe_lenloc, &wqe->fcp_iwrite.wqe_com,
LPFC_WQE_LENLOC_WORD4);
if (phba->cfg_nvme_oas)
bf_set(wqe_oas, &wqe->fcp_iwrite.wqe_com, 1);
bf_set(wqe_cmd_type, &wqe->generic.wqe_com,
NVME_WRITE_CMD);
phba->fc4NvmeOutputRequests++;
} else {
bf_set(wqe_cmnd, &wqe->generic.wqe_com,
CMD_FCP_IREAD64_WQE);
bf_set(wqe_pu, &wqe->generic.wqe_com,
PARM_READ_CHECK);
bf_set(wqe_qosd, &wqe->fcp_iread.wqe_com, 0);
bf_set(wqe_iod, &wqe->fcp_iread.wqe_com,
LPFC_WQE_IOD_READ);
bf_set(wqe_lenloc, &wqe->fcp_iread.wqe_com,
LPFC_WQE_LENLOC_WORD4);
if (phba->cfg_nvme_oas)
bf_set(wqe_oas, &wqe->fcp_iread.wqe_com, 1);
bf_set(wqe_cmd_type, &wqe->generic.wqe_com,
NVME_READ_CMD);
phba->fc4NvmeInputRequests++;
}
} else {
wqe->fcp_icmd.rsrvd4 = 0;
bf_set(wqe_cmnd, &wqe->generic.wqe_com, CMD_FCP_ICMND64_WQE);
bf_set(wqe_pu, &wqe->generic.wqe_com, 0);
bf_set(wqe_qosd, &wqe->fcp_icmd.wqe_com, 1);
bf_set(wqe_iod, &wqe->fcp_icmd.wqe_com, LPFC_WQE_IOD_WRITE);
bf_set(wqe_lenloc, &wqe->fcp_icmd.wqe_com,
LPFC_WQE_LENLOC_NONE);
if (phba->cfg_nvme_oas)
bf_set(wqe_oas, &wqe->fcp_icmd.wqe_com, 1);
bf_set(wqe_cmd_type, &wqe->generic.wqe_com, NVME_READ_CMD);
phba->fc4NvmeControlRequests++;
}
bf_set(wqe_ctxt_tag, &wqe->generic.wqe_com,
phba->sli4_hba.rpi_ids[pnode->nlp_rpi]);
bf_set(wqe_xri_tag, &wqe->generic.wqe_com, pwqeq->sli4_xritag);
bf_set(wqe_class, &wqe->generic.wqe_com,
(pnode->nlp_fcp_info & 0x0f));
wqe->generic.wqe_com.abort_tag = pwqeq->iotag;
bf_set(wqe_reqtag, &wqe->generic.wqe_com, pwqeq->iotag);
bf_set(wqe_cqid, &wqe->generic.wqe_com, LPFC_WQE_CQ_ID_DEFAULT);
pwqeq->vport = vport;
return 0;
}
static int
lpfc_nvme_prep_io_dma(struct lpfc_vport *vport,
struct lpfc_nvme_buf *lpfc_ncmd)
{
struct lpfc_hba *phba = vport->phba;
struct nvmefc_fcp_req *nCmd = lpfc_ncmd->nvmeCmd;
union lpfc_wqe128 *wqe = (union lpfc_wqe128 *)&lpfc_ncmd->cur_iocbq.wqe;
struct sli4_sge *sgl = lpfc_ncmd->nvme_sgl;
struct scatterlist *data_sg;
struct sli4_sge *first_data_sgl;
dma_addr_t physaddr;
uint32_t num_bde = 0;
uint32_t dma_len;
uint32_t dma_offset = 0;
int nseg, i;
lpfc_nvme_adj_fcp_sgls(vport, lpfc_ncmd, nCmd);
if (nCmd->sg_cnt) {
sgl += 2;
first_data_sgl = sgl;
lpfc_ncmd->seg_cnt = nCmd->sg_cnt;
if (lpfc_ncmd->seg_cnt > phba->cfg_nvme_seg_cnt) {
lpfc_printf_log(phba, KERN_ERR, LOG_NVME_IOERR,
"6058 Too many sg segments from "
"NVME Transport. Max %d, "
"nvmeIO sg_cnt %d\n",
phba->cfg_nvme_seg_cnt,
lpfc_ncmd->seg_cnt);
lpfc_ncmd->seg_cnt = 0;
return 1;
}
nseg = nCmd->sg_cnt;
data_sg = nCmd->first_sgl;
for (i = 0; i < nseg; i++) {
if (data_sg == NULL) {
lpfc_printf_log(phba, KERN_ERR, LOG_NVME_IOERR,
"6059 dptr err %d, nseg %d\n",
i, nseg);
lpfc_ncmd->seg_cnt = 0;
return 1;
}
physaddr = data_sg->dma_address;
dma_len = data_sg->length;
sgl->addr_lo = cpu_to_le32(putPaddrLow(physaddr));
sgl->addr_hi = cpu_to_le32(putPaddrHigh(physaddr));
sgl->word2 = le32_to_cpu(sgl->word2);
if ((num_bde + 1) == nseg)
bf_set(lpfc_sli4_sge_last, sgl, 1);
else
bf_set(lpfc_sli4_sge_last, sgl, 0);
bf_set(lpfc_sli4_sge_offset, sgl, dma_offset);
bf_set(lpfc_sli4_sge_type, sgl, LPFC_SGE_TYPE_DATA);
sgl->word2 = cpu_to_le32(sgl->word2);
sgl->sge_len = cpu_to_le32(dma_len);
dma_offset += dma_len;
data_sg = sg_next(data_sg);
sgl++;
}
} else {
if (nCmd->payload_length != 0) {
lpfc_printf_log(phba, KERN_ERR, LOG_NVME_IOERR,
"6063 NVME DMA Prep Err: sg_cnt %d "
"payload_length x%x\n",
nCmd->sg_cnt, nCmd->payload_length);
return 1;
}
}
wqe->fcp_iread.total_xfer_len = nCmd->payload_length;
return 0;
}
static int
lpfc_nvme_fcp_io_submit(struct nvme_fc_local_port *pnvme_lport,
struct nvme_fc_remote_port *pnvme_rport,
void *hw_queue_handle,
struct nvmefc_fcp_req *pnvme_fcreq)
{
int ret = 0;
struct lpfc_nvme_lport *lport;
struct lpfc_vport *vport;
struct lpfc_hba *phba;
struct lpfc_nodelist *ndlp;
struct lpfc_nvme_buf *lpfc_ncmd;
struct lpfc_nvme_rport *rport;
struct lpfc_nvme_qhandle *lpfc_queue_info;
struct lpfc_nvme_fcpreq_priv *freqpriv = pnvme_fcreq->private;
#ifdef CONFIG_SCSI_LPFC_DEBUG_FS
uint64_t start = 0;
#endif
lport = (struct lpfc_nvme_lport *)pnvme_lport->private;
vport = lport->vport;
phba = vport->phba;
#ifdef CONFIG_SCSI_LPFC_DEBUG_FS
if (phba->ktime_on)
start = ktime_get_ns();
#endif
rport = (struct lpfc_nvme_rport *)pnvme_rport->private;
lpfc_queue_info = (struct lpfc_nvme_qhandle *)hw_queue_handle;
ndlp = rport->ndlp;
if (!ndlp || !NLP_CHK_NODE_ACT(ndlp)) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_NODE | LOG_NVME_IOERR,
"6053 rport %p, ndlp %p, DID x%06x "
"ndlp not ready.\n",
rport, ndlp, pnvme_rport->port_id);
ndlp = lpfc_findnode_did(vport, pnvme_rport->port_id);
if (!ndlp) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_NVME_IOERR,
"6066 Missing node for DID %x\n",
pnvme_rport->port_id);
ret = -ENODEV;
goto out_fail;
}
}
if ((ndlp->nlp_type & NLP_NVME_TARGET) &&
(ndlp->nlp_state != NLP_STE_MAPPED_NODE)) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_NODE | LOG_NVME_IOERR,
"6036 rport %p, DID x%06x not ready for "
"IO. State x%x, Type x%x\n",
rport, pnvme_rport->port_id,
ndlp->nlp_state, ndlp->nlp_type);
ret = -ENODEV;
goto out_fail;
}
if (atomic_read(&ndlp->cmd_pending) >= ndlp->cmd_qdepth) {
ret = -EAGAIN;
goto out_fail;
}
lpfc_ncmd = lpfc_get_nvme_buf(phba, ndlp);
if (lpfc_ncmd == NULL) {
lpfc_printf_vlog(vport, KERN_INFO, LOG_NVME_IOERR,
"6065 driver's buffer pool is empty, "
"IO failed\n");
ret = -ENOMEM;
goto out_fail;
}
#ifdef CONFIG_SCSI_LPFC_DEBUG_FS
if (phba->ktime_on) {
lpfc_ncmd->ts_cmd_start = start;
lpfc_ncmd->ts_last_cmd = phba->ktime_last_cmd;
}
#endif
freqpriv->nvme_buf = lpfc_ncmd;
lpfc_ncmd->nvmeCmd = pnvme_fcreq;
lpfc_ncmd->nrport = rport;
lpfc_ncmd->ndlp = ndlp;
lpfc_ncmd->start_time = jiffies;
lpfc_nvme_prep_io_cmd(vport, lpfc_ncmd, ndlp);
ret = lpfc_nvme_prep_io_dma(vport, lpfc_ncmd);
if (ret) {
ret = -ENOMEM;
goto out_free_nvme_buf;
}
atomic_inc(&ndlp->cmd_pending);
lpfc_ncmd->cur_iocbq.hba_wqidx = lpfc_queue_info->index;
lpfc_nvmeio_data(phba, "NVME FCP XMIT: xri x%x idx %d to %06x\n",
lpfc_ncmd->cur_iocbq.sli4_xritag,
lpfc_queue_info->index, ndlp->nlp_DID);
ret = lpfc_sli4_issue_wqe(phba, LPFC_FCP_RING, &lpfc_ncmd->cur_iocbq);
if (ret) {
atomic_dec(&ndlp->cmd_pending);
lpfc_printf_vlog(vport, KERN_ERR, LOG_NVME_IOERR,
"6113 FCP could not issue WQE err %x "
"sid: x%x did: x%x oxid: x%x\n",
ret, vport->fc_myDID, ndlp->nlp_DID,
lpfc_ncmd->cur_iocbq.sli4_xritag);
ret = -EBUSY;
goto out_free_nvme_buf;
}
#ifdef CONFIG_SCSI_LPFC_DEBUG_FS
if (phba->ktime_on)
lpfc_ncmd->ts_cmd_wqput = ktime_get_ns();
if (phba->cpucheck_on & LPFC_CHECK_NVME_IO) {
lpfc_ncmd->cpu = smp_processor_id();
if (lpfc_ncmd->cpu != lpfc_queue_info->index) {
if (lpfc_queue_info->qidx) {
lpfc_printf_vlog(vport,
KERN_ERR, LOG_NVME_IOERR,
"6702 CPU Check cmd: "
"cpu %d wq %d\n",
lpfc_ncmd->cpu,
lpfc_queue_info->index);
}
lpfc_ncmd->cpu = lpfc_queue_info->index;
}
if (lpfc_ncmd->cpu < LPFC_CHECK_CPU_CNT)
phba->cpucheck_xmt_io[lpfc_ncmd->cpu]++;
}
#endif
return 0;
out_free_nvme_buf:
lpfc_release_nvme_buf(phba, lpfc_ncmd);
out_fail:
return ret;
}
void
lpfc_nvme_abort_fcreq_cmpl(struct lpfc_hba *phba, struct lpfc_iocbq *cmdiocb,
struct lpfc_wcqe_complete *abts_cmpl)
{
lpfc_printf_log(phba, KERN_ERR, LOG_NVME,
"6145 ABORT_XRI_CN completing on rpi x%x "
"original iotag x%x, abort cmd iotag x%x "
"req_tag x%x, status x%x, hwstatus x%x\n",
cmdiocb->iocb.un.acxri.abortContextTag,
cmdiocb->iocb.un.acxri.abortIoTag,
cmdiocb->iotag,
bf_get(lpfc_wcqe_c_request_tag, abts_cmpl),
bf_get(lpfc_wcqe_c_status, abts_cmpl),
bf_get(lpfc_wcqe_c_hw_status, abts_cmpl));
lpfc_sli_release_iocbq(phba, cmdiocb);
}
static void
lpfc_nvme_fcp_abort(struct nvme_fc_local_port *pnvme_lport,
struct nvme_fc_remote_port *pnvme_rport,
void *hw_queue_handle,
struct nvmefc_fcp_req *pnvme_fcreq)
{
struct lpfc_nvme_lport *lport;
struct lpfc_vport *vport;
struct lpfc_hba *phba;
struct lpfc_nodelist *ndlp;
struct lpfc_nvme_rport *rport;
struct lpfc_nvme_buf *lpfc_nbuf;
struct lpfc_iocbq *abts_buf;
struct lpfc_iocbq *nvmereq_wqe;
struct lpfc_nvme_fcpreq_priv *freqpriv = pnvme_fcreq->private;
union lpfc_wqe *abts_wqe;
unsigned long flags;
int ret_val;
lport = (struct lpfc_nvme_lport *)pnvme_lport->private;
rport = (struct lpfc_nvme_rport *)pnvme_rport->private;
vport = lport->vport;
phba = vport->phba;
lpfc_printf_vlog(vport, KERN_INFO, LOG_NVME_ABTS,
"6002 Abort Request to rport DID x%06x "
"for nvme_fc_req %p\n",
pnvme_rport->port_id,
pnvme_fcreq);
ndlp = rport->ndlp;
if (!ndlp || !NLP_CHK_NODE_ACT(ndlp)) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_NODE | LOG_NVME_ABTS,
"6054 rport %p, ndlp %p, DID x%06x ndlp "
" not ready.\n",
rport, ndlp, pnvme_rport->port_id);
ndlp = lpfc_findnode_did(vport, pnvme_rport->port_id);
if (!ndlp) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_NVME_ABTS,
"6055 Could not find node for "
"DID %x\n",
pnvme_rport->port_id);
return;
}
}
if ((ndlp->nlp_state != NLP_STE_MAPPED_NODE) &&
!(ndlp->nlp_type & NLP_NVME_TARGET)) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_NVME_ABTS,
"6048 rport %p, DID x%06x not ready for "
"IO. State x%x, Type x%x\n",
rport, pnvme_rport->port_id,
ndlp->nlp_state, ndlp->nlp_type);
return;
}
spin_lock_irqsave(&phba->hbalock, flags);
if (phba->hba_flag & HBA_NVME_IOQ_FLUSH) {
spin_unlock_irqrestore(&phba->hbalock, flags);
lpfc_printf_vlog(vport, KERN_ERR, LOG_NVME_ABTS,
"6139 Driver in reset cleanup - flushing "
"NVME Req now. hba_flag x%x\n",
phba->hba_flag);
return;
}
lpfc_nbuf = freqpriv->nvme_buf;
if (!lpfc_nbuf) {
spin_unlock_irqrestore(&phba->hbalock, flags);
lpfc_printf_vlog(vport, KERN_ERR, LOG_NVME_ABTS,
"6140 NVME IO req has no matching lpfc nvme "
"io buffer. Skipping abort req.\n");
return;
} else if (!lpfc_nbuf->nvmeCmd) {
spin_unlock_irqrestore(&phba->hbalock, flags);
lpfc_printf_vlog(vport, KERN_ERR, LOG_NVME_ABTS,
"6141 lpfc NVME IO req has no nvme_fcreq "
"io buffer. Skipping abort req.\n");
return;
}
nvmereq_wqe = &lpfc_nbuf->cur_iocbq;
if (lpfc_nbuf->nvmeCmd != pnvme_fcreq) {
spin_unlock_irqrestore(&phba->hbalock, flags);
lpfc_printf_vlog(vport, KERN_ERR, LOG_NVME_ABTS,
"6143 NVME req mismatch: "
"lpfc_nbuf %p nvmeCmd %p, "
"pnvme_fcreq %p. Skipping Abort xri x%x\n",
lpfc_nbuf, lpfc_nbuf->nvmeCmd,
pnvme_fcreq, nvmereq_wqe->sli4_xritag);
return;
}
if (!(nvmereq_wqe->iocb_flag & LPFC_IO_ON_TXCMPLQ)) {
spin_unlock_irqrestore(&phba->hbalock, flags);
lpfc_printf_vlog(vport, KERN_ERR, LOG_NVME_ABTS,
"6142 NVME IO req %p not queued - skipping "
"abort req xri x%x\n",
pnvme_fcreq, nvmereq_wqe->sli4_xritag);
return;
}
lpfc_nvmeio_data(phba, "NVME FCP ABORT: xri x%x idx %d to %06x\n",
nvmereq_wqe->sli4_xritag,
nvmereq_wqe->hba_wqidx, ndlp->nlp_DID);
if (nvmereq_wqe->iocb_flag & LPFC_DRIVER_ABORTED) {
spin_unlock_irqrestore(&phba->hbalock, flags);
lpfc_printf_vlog(vport, KERN_ERR, LOG_NVME_ABTS,
"6144 Outstanding NVME I/O Abort Request "
"still pending on nvme_fcreq %p, "
"lpfc_ncmd %p xri x%x\n",
pnvme_fcreq, lpfc_nbuf,
nvmereq_wqe->sli4_xritag);
return;
}
abts_buf = __lpfc_sli_get_iocbq(phba);
if (!abts_buf) {
spin_unlock_irqrestore(&phba->hbalock, flags);
lpfc_printf_vlog(vport, KERN_ERR, LOG_NVME_ABTS,
"6136 No available abort wqes. Skipping "
"Abts req for nvme_fcreq %p xri x%x\n",
pnvme_fcreq, nvmereq_wqe->sli4_xritag);
return;
}
nvmereq_wqe->iocb_flag |= LPFC_DRIVER_ABORTED;
abts_wqe = &abts_buf->wqe;
memset(abts_wqe, 0, sizeof(union lpfc_wqe));
bf_set(abort_cmd_criteria, &abts_wqe->abort_cmd, T_XRI_TAG);
bf_set(wqe_ct, &abts_wqe->abort_cmd.wqe_com, 0);
bf_set(wqe_cmnd, &abts_wqe->abort_cmd.wqe_com, CMD_ABORT_XRI_CX);
bf_set(wqe_class, &abts_wqe->abort_cmd.wqe_com,
nvmereq_wqe->iocb.ulpClass);
abts_wqe->abort_cmd.wqe_com.abort_tag = nvmereq_wqe->sli4_xritag;
bf_set(wqe_reqtag, &abts_wqe->abort_cmd.wqe_com,
abts_buf->iotag);
bf_set(wqe_wqid, &abts_wqe->abort_cmd.wqe_com, nvmereq_wqe->hba_wqidx);
bf_set(wqe_qosd, &abts_wqe->abort_cmd.wqe_com, 1);
bf_set(wqe_lenloc, &abts_wqe->abort_cmd.wqe_com, LPFC_WQE_LENLOC_NONE);
bf_set(wqe_cmd_type, &abts_wqe->abort_cmd.wqe_com, OTHER_COMMAND);
bf_set(wqe_wqec, &abts_wqe->abort_cmd.wqe_com, 1);
bf_set(wqe_cqid, &abts_wqe->abort_cmd.wqe_com, LPFC_WQE_CQ_ID_DEFAULT);
abts_buf->iocb_flag |= LPFC_IO_NVME;
abts_buf->hba_wqidx = nvmereq_wqe->hba_wqidx;
abts_buf->vport = vport;
abts_buf->wqe_cmpl = lpfc_nvme_abort_fcreq_cmpl;
ret_val = lpfc_sli4_issue_wqe(phba, LPFC_FCP_RING, abts_buf);
spin_unlock_irqrestore(&phba->hbalock, flags);
if (ret_val == IOCB_ERROR) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_NVME_ABTS,
"6137 Failed abts issue_wqe with status x%x "
"for nvme_fcreq %p.\n",
ret_val, pnvme_fcreq);
lpfc_sli_release_iocbq(phba, abts_buf);
return;
}
lpfc_printf_vlog(vport, KERN_INFO, LOG_NVME_ABTS,
"6138 Transport Abort NVME Request Issued for "
"ox_id x%x on reqtag x%x\n",
nvmereq_wqe->sli4_xritag,
abts_buf->iotag);
}
static int
lpfc_sli4_post_nvme_sgl_block(struct lpfc_hba *phba,
struct list_head *nblist,
int count)
{
struct lpfc_nvme_buf *lpfc_ncmd;
struct lpfc_mbx_post_uembed_sgl_page1 *sgl;
struct sgl_page_pairs *sgl_pg_pairs;
void *viraddr;
LPFC_MBOXQ_t *mbox;
uint32_t reqlen, alloclen, pg_pairs;
uint32_t mbox_tmo;
uint16_t xritag_start = 0;
int rc = 0;
uint32_t shdr_status, shdr_add_status;
dma_addr_t pdma_phys_bpl1;
union lpfc_sli4_cfg_shdr *shdr;
reqlen = count * sizeof(struct sgl_page_pairs) +
sizeof(union lpfc_sli4_cfg_shdr) + sizeof(uint32_t);
if (reqlen > SLI4_PAGE_SIZE) {
lpfc_printf_log(phba, KERN_WARNING, LOG_INIT,
"6118 Block sgl registration required DMA "
"size (%d) great than a page\n", reqlen);
return -ENOMEM;
}
mbox = mempool_alloc(phba->mbox_mem_pool, GFP_KERNEL);
if (!mbox) {
lpfc_printf_log(phba, KERN_ERR, LOG_INIT,
"6119 Failed to allocate mbox cmd memory\n");
return -ENOMEM;
}
alloclen = lpfc_sli4_config(phba, mbox, LPFC_MBOX_SUBSYSTEM_FCOE,
LPFC_MBOX_OPCODE_FCOE_POST_SGL_PAGES, reqlen,
LPFC_SLI4_MBX_NEMBED);
if (alloclen < reqlen) {
lpfc_printf_log(phba, KERN_ERR, LOG_INIT,
"6120 Allocated DMA memory size (%d) is "
"less than the requested DMA memory "
"size (%d)\n", alloclen, reqlen);
lpfc_sli4_mbox_cmd_free(phba, mbox);
return -ENOMEM;
}
viraddr = mbox->sge_array->addr[0];
sgl = (struct lpfc_mbx_post_uembed_sgl_page1 *)viraddr;
sgl_pg_pairs = &sgl->sgl_pg_pairs;
pg_pairs = 0;
list_for_each_entry(lpfc_ncmd, nblist, list) {
sgl_pg_pairs->sgl_pg0_addr_lo =
cpu_to_le32(putPaddrLow(lpfc_ncmd->dma_phys_sgl));
sgl_pg_pairs->sgl_pg0_addr_hi =
cpu_to_le32(putPaddrHigh(lpfc_ncmd->dma_phys_sgl));
if (phba->cfg_sg_dma_buf_size > SGL_PAGE_SIZE)
pdma_phys_bpl1 = lpfc_ncmd->dma_phys_sgl +
SGL_PAGE_SIZE;
else
pdma_phys_bpl1 = 0;
sgl_pg_pairs->sgl_pg1_addr_lo =
cpu_to_le32(putPaddrLow(pdma_phys_bpl1));
sgl_pg_pairs->sgl_pg1_addr_hi =
cpu_to_le32(putPaddrHigh(pdma_phys_bpl1));
if (pg_pairs == 0)
xritag_start = lpfc_ncmd->cur_iocbq.sli4_xritag;
sgl_pg_pairs++;
pg_pairs++;
}
bf_set(lpfc_post_sgl_pages_xri, sgl, xritag_start);
bf_set(lpfc_post_sgl_pages_xricnt, sgl, pg_pairs);
sgl->word0 = cpu_to_le32(sgl->word0);
if (!phba->sli4_hba.intr_enable)
rc = lpfc_sli_issue_mbox(phba, mbox, MBX_POLL);
else {
mbox_tmo = lpfc_mbox_tmo_val(phba, mbox);
rc = lpfc_sli_issue_mbox_wait(phba, mbox, mbox_tmo);
}
shdr = (union lpfc_sli4_cfg_shdr *)&sgl->cfg_shdr;
shdr_status = bf_get(lpfc_mbox_hdr_status, &shdr->response);
shdr_add_status = bf_get(lpfc_mbox_hdr_add_status, &shdr->response);
if (rc != MBX_TIMEOUT)
lpfc_sli4_mbox_cmd_free(phba, mbox);
if (shdr_status || shdr_add_status || rc) {
lpfc_printf_log(phba, KERN_ERR, LOG_SLI,
"6125 POST_SGL_BLOCK mailbox command failed "
"status x%x add_status x%x mbx status x%x\n",
shdr_status, shdr_add_status, rc);
rc = -ENXIO;
}
return rc;
}
static int
lpfc_post_nvme_sgl_list(struct lpfc_hba *phba,
struct list_head *post_nblist, int sb_count)
{
struct lpfc_nvme_buf *lpfc_ncmd, *lpfc_ncmd_next;
int status, sgl_size;
int post_cnt = 0, block_cnt = 0, num_posting = 0, num_posted = 0;
dma_addr_t pdma_phys_sgl1;
int last_xritag = NO_XRI;
int cur_xritag;
LIST_HEAD(prep_nblist);
LIST_HEAD(blck_nblist);
LIST_HEAD(nvme_nblist);
if (sb_count <= 0)
return -EINVAL;
sgl_size = phba->cfg_sg_dma_buf_size;
list_for_each_entry_safe(lpfc_ncmd, lpfc_ncmd_next, post_nblist, list) {
list_del_init(&lpfc_ncmd->list);
block_cnt++;
if ((last_xritag != NO_XRI) &&
(lpfc_ncmd->cur_iocbq.sli4_xritag != last_xritag + 1)) {
list_splice_init(&prep_nblist, &blck_nblist);
post_cnt = block_cnt - 1;
list_add_tail(&lpfc_ncmd->list, &prep_nblist);
block_cnt = 1;
} else {
list_add_tail(&lpfc_ncmd->list, &prep_nblist);
if (block_cnt == LPFC_NEMBED_MBOX_SGL_CNT) {
list_splice_init(&prep_nblist, &blck_nblist);
post_cnt = block_cnt;
block_cnt = 0;
}
}
num_posting++;
last_xritag = lpfc_ncmd->cur_iocbq.sli4_xritag;
if (num_posting == sb_count) {
if (post_cnt == 0) {
list_splice_init(&prep_nblist, &blck_nblist);
post_cnt = block_cnt;
} else if (block_cnt == 1) {
if (sgl_size > SGL_PAGE_SIZE)
pdma_phys_sgl1 =
lpfc_ncmd->dma_phys_sgl +
SGL_PAGE_SIZE;
else
pdma_phys_sgl1 = 0;
cur_xritag = lpfc_ncmd->cur_iocbq.sli4_xritag;
status = lpfc_sli4_post_sgl(phba,
lpfc_ncmd->dma_phys_sgl,
pdma_phys_sgl1, cur_xritag);
if (status) {
lpfc_ncmd->flags |= LPFC_SBUF_XBUSY;
} else {
lpfc_ncmd->flags &= ~LPFC_SBUF_XBUSY;
lpfc_ncmd->status = IOSTAT_SUCCESS;
num_posted++;
}
list_add_tail(&lpfc_ncmd->list, &nvme_nblist);
}
}
if (post_cnt == 0)
continue;
status = lpfc_sli4_post_nvme_sgl_block(phba, &blck_nblist,
post_cnt);
if (block_cnt == 0)
last_xritag = NO_XRI;
post_cnt = 0;
while (!list_empty(&blck_nblist)) {
list_remove_head(&blck_nblist, lpfc_ncmd,
struct lpfc_nvme_buf, list);
if (status) {
lpfc_ncmd->flags |= LPFC_SBUF_XBUSY;
} else {
lpfc_ncmd->flags &= ~LPFC_SBUF_XBUSY;
lpfc_ncmd->status = IOSTAT_SUCCESS;
num_posted++;
}
list_add_tail(&lpfc_ncmd->list, &nvme_nblist);
}
}
while (!list_empty(&nvme_nblist)) {
list_remove_head(&nvme_nblist, lpfc_ncmd,
struct lpfc_nvme_buf, list);
lpfc_release_nvme_buf(phba, lpfc_ncmd);
}
return num_posted;
}
int
lpfc_repost_nvme_sgl_list(struct lpfc_hba *phba)
{
LIST_HEAD(post_nblist);
int num_posted, rc = 0;
spin_lock_irq(&phba->nvme_buf_list_get_lock);
spin_lock(&phba->nvme_buf_list_put_lock);
list_splice_init(&phba->lpfc_nvme_buf_list_get, &post_nblist);
list_splice(&phba->lpfc_nvme_buf_list_put, &post_nblist);
spin_unlock(&phba->nvme_buf_list_put_lock);
spin_unlock_irq(&phba->nvme_buf_list_get_lock);
if (!list_empty(&post_nblist)) {
num_posted = lpfc_post_nvme_sgl_list(phba, &post_nblist,
phba->sli4_hba.nvme_xri_cnt);
if (num_posted == 0)
rc = -EIO;
}
return rc;
}
static int
lpfc_new_nvme_buf(struct lpfc_vport *vport, int num_to_alloc)
{
struct lpfc_hba *phba = vport->phba;
struct lpfc_nvme_buf *lpfc_ncmd;
struct lpfc_iocbq *pwqeq;
union lpfc_wqe128 *wqe;
struct sli4_sge *sgl;
dma_addr_t pdma_phys_sgl;
uint16_t iotag, lxri = 0;
int bcnt, num_posted, sgl_size;
LIST_HEAD(prep_nblist);
LIST_HEAD(post_nblist);
LIST_HEAD(nvme_nblist);
sgl_size = phba->cfg_sg_dma_buf_size;
for (bcnt = 0; bcnt < num_to_alloc; bcnt++) {
lpfc_ncmd = kzalloc(sizeof(struct lpfc_nvme_buf), GFP_KERNEL);
if (!lpfc_ncmd)
break;
lpfc_ncmd->data = pci_pool_alloc(phba->lpfc_sg_dma_buf_pool,
GFP_KERNEL,
&lpfc_ncmd->dma_handle);
if (!lpfc_ncmd->data) {
kfree(lpfc_ncmd);
break;
}
memset(lpfc_ncmd->data, 0, phba->cfg_sg_dma_buf_size);
lxri = lpfc_sli4_next_xritag(phba);
if (lxri == NO_XRI) {
pci_pool_free(phba->lpfc_sg_dma_buf_pool,
lpfc_ncmd->data, lpfc_ncmd->dma_handle);
kfree(lpfc_ncmd);
break;
}
pwqeq = &(lpfc_ncmd->cur_iocbq);
wqe = (union lpfc_wqe128 *)&pwqeq->wqe;
iotag = lpfc_sli_next_iotag(phba, pwqeq);
if (iotag == 0) {
pci_pool_free(phba->lpfc_sg_dma_buf_pool,
lpfc_ncmd->data, lpfc_ncmd->dma_handle);
kfree(lpfc_ncmd);
lpfc_printf_log(phba, KERN_ERR, LOG_NVME_IOERR,
"6121 Failed to allocated IOTAG for"
" XRI:0x%x\n", lxri);
lpfc_sli4_free_xri(phba, lxri);
break;
}
pwqeq->sli4_lxritag = lxri;
pwqeq->sli4_xritag = phba->sli4_hba.xri_ids[lxri];
pwqeq->iocb_flag |= LPFC_IO_NVME;
pwqeq->context1 = lpfc_ncmd;
pwqeq->wqe_cmpl = lpfc_nvme_io_cmd_wqe_cmpl;
lpfc_ncmd->nvme_sgl = lpfc_ncmd->data;
sgl = lpfc_ncmd->nvme_sgl;
pdma_phys_sgl = lpfc_ncmd->dma_handle;
lpfc_ncmd->dma_phys_sgl = pdma_phys_sgl;
bf_set(lpfc_sli4_sge_type, sgl, LPFC_SGE_TYPE_SKIP);
bf_set(lpfc_sli4_sge_last, sgl, 0);
sgl->word2 = cpu_to_le32(sgl->word2);
lpfc_ncmd->cur_iocbq.context1 = lpfc_ncmd;
bf_set(wqe_erp, &wqe->generic.wqe_com, 0);
bf_set(wqe_tmo, &wqe->generic.wqe_com, 0);
bf_set(wqe_ebde_cnt, &wqe->generic.wqe_com, 0);
bf_set(wqe_dbde, &wqe->generic.wqe_com, 1);
list_add_tail(&lpfc_ncmd->list, &post_nblist);
spin_lock_irq(&phba->nvme_buf_list_get_lock);
phba->sli4_hba.nvme_xri_cnt++;
spin_unlock_irq(&phba->nvme_buf_list_get_lock);
}
lpfc_printf_log(phba, KERN_INFO, LOG_NVME,
"6114 Allocate %d out of %d requested new NVME "
"buffers\n", bcnt, num_to_alloc);
if (!list_empty(&post_nblist))
num_posted = lpfc_post_nvme_sgl_list(phba,
&post_nblist, bcnt);
else
num_posted = 0;
return num_posted;
}
static struct lpfc_nvme_buf *
lpfc_get_nvme_buf(struct lpfc_hba *phba, struct lpfc_nodelist *ndlp)
{
struct lpfc_nvme_buf *lpfc_ncmd, *lpfc_ncmd_next;
unsigned long iflag = 0;
int found = 0;
spin_lock_irqsave(&phba->nvme_buf_list_get_lock, iflag);
list_for_each_entry_safe(lpfc_ncmd, lpfc_ncmd_next,
&phba->lpfc_nvme_buf_list_get, list) {
if (lpfc_test_rrq_active(phba, ndlp,
lpfc_ncmd->cur_iocbq.sli4_lxritag))
continue;
list_del_init(&lpfc_ncmd->list);
found = 1;
break;
}
if (!found) {
spin_lock(&phba->nvme_buf_list_put_lock);
list_splice(&phba->lpfc_nvme_buf_list_put,
&phba->lpfc_nvme_buf_list_get);
INIT_LIST_HEAD(&phba->lpfc_nvme_buf_list_put);
spin_unlock(&phba->nvme_buf_list_put_lock);
list_for_each_entry_safe(lpfc_ncmd, lpfc_ncmd_next,
&phba->lpfc_nvme_buf_list_get, list) {
if (lpfc_test_rrq_active(
phba, ndlp, lpfc_ncmd->cur_iocbq.sli4_lxritag))
continue;
list_del_init(&lpfc_ncmd->list);
found = 1;
break;
}
}
spin_unlock_irqrestore(&phba->nvme_buf_list_get_lock, iflag);
if (!found)
return NULL;
return lpfc_ncmd;
}
static void
lpfc_release_nvme_buf(struct lpfc_hba *phba, struct lpfc_nvme_buf *lpfc_ncmd)
{
unsigned long iflag = 0;
lpfc_ncmd->nonsg_phys = 0;
if (lpfc_ncmd->flags & LPFC_SBUF_XBUSY) {
lpfc_printf_log(phba, KERN_INFO, LOG_NVME_ABTS,
"6310 XB release deferred for "
"ox_id x%x on reqtag x%x\n",
lpfc_ncmd->cur_iocbq.sli4_xritag,
lpfc_ncmd->cur_iocbq.iotag);
spin_lock_irqsave(&phba->sli4_hba.abts_nvme_buf_list_lock,
iflag);
lpfc_ncmd->nvmeCmd = NULL;
list_add_tail(&lpfc_ncmd->list,
&phba->sli4_hba.lpfc_abts_nvme_buf_list);
spin_unlock_irqrestore(&phba->sli4_hba.abts_nvme_buf_list_lock,
iflag);
} else {
lpfc_ncmd->nvmeCmd = NULL;
lpfc_ncmd->cur_iocbq.iocb_flag = LPFC_IO_NVME;
spin_lock_irqsave(&phba->nvme_buf_list_put_lock, iflag);
list_add_tail(&lpfc_ncmd->list, &phba->lpfc_nvme_buf_list_put);
spin_unlock_irqrestore(&phba->nvme_buf_list_put_lock, iflag);
}
}
int
lpfc_nvme_create_localport(struct lpfc_vport *vport)
{
int ret = 0;
struct lpfc_hba *phba = vport->phba;
struct nvme_fc_port_info nfcp_info;
struct nvme_fc_local_port *localport;
struct lpfc_nvme_lport *lport;
int len;
memset(&nfcp_info, 0, sizeof(struct nvme_fc_port_info));
nfcp_info.port_role = FC_PORT_ROLE_NVME_INITIATOR;
nfcp_info.node_name = wwn_to_u64(vport->fc_nodename.u.wwn);
nfcp_info.port_name = wwn_to_u64(vport->fc_portname.u.wwn);
if (phba->cfg_sg_seg_cnt > LPFC_MAX_NVME_SEG_CNT) {
lpfc_printf_vlog(vport, KERN_INFO, LOG_NVME | LOG_INIT,
"6300 Reducing sg segment cnt to %d\n",
LPFC_MAX_NVME_SEG_CNT);
phba->cfg_nvme_seg_cnt = LPFC_MAX_NVME_SEG_CNT;
} else {
phba->cfg_nvme_seg_cnt = phba->cfg_sg_seg_cnt;
}
lpfc_nvme_template.max_sgl_segments = phba->cfg_nvme_seg_cnt + 1;
lpfc_nvme_template.max_hw_queues = phba->cfg_nvme_io_channel;
#if (IS_ENABLED(CONFIG_NVME_FC))
ret = nvme_fc_register_localport(&nfcp_info, &lpfc_nvme_template,
&vport->phba->pcidev->dev, &localport);
#else
ret = -ENOMEM;
#endif
if (!ret) {
lpfc_printf_vlog(vport, KERN_INFO, LOG_NVME | LOG_NVME_DISC,
"6005 Successfully registered local "
"NVME port num %d, localP %p, private %p, "
"sg_seg %d\n",
localport->port_num, localport,
localport->private,
lpfc_nvme_template.max_sgl_segments);
lport = (struct lpfc_nvme_lport *)localport->private;
vport->localport = localport;
lport->vport = vport;
INIT_LIST_HEAD(&lport->rport_list);
vport->nvmei_support = 1;
len = lpfc_new_nvme_buf(vport, phba->sli4_hba.nvme_xri_max);
vport->phba->total_nvme_bufs += len;
}
return ret;
}
void
lpfc_nvme_destroy_localport(struct lpfc_vport *vport)
{
#if (IS_ENABLED(CONFIG_NVME_FC))
struct nvme_fc_local_port *localport;
struct lpfc_nvme_lport *lport;
struct lpfc_nvme_rport *rport = NULL, *rport_next = NULL;
int ret;
if (vport->nvmei_support == 0)
return;
localport = vport->localport;
vport->localport = NULL;
lport = (struct lpfc_nvme_lport *)localport->private;
lpfc_printf_vlog(vport, KERN_INFO, LOG_NVME,
"6011 Destroying NVME localport %p\n",
localport);
list_for_each_entry_safe(rport, rport_next, &lport->rport_list, list) {
list_del(&rport->list);
init_completion(&rport->rport_unreg_done);
ret = nvme_fc_unregister_remoteport(rport->remoteport);
if (ret)
lpfc_printf_vlog(vport, KERN_ERR, LOG_NVME_DISC,
"6008 rport fail destroy %x\n", ret);
wait_for_completion_timeout(&rport->rport_unreg_done, 5);
}
init_completion(&lport->lport_unreg_done);
ret = nvme_fc_unregister_localport(localport);
wait_for_completion_timeout(&lport->lport_unreg_done, 5);
vport->nvmei_support = 0;
if (ret == 0) {
lpfc_printf_vlog(vport,
KERN_INFO, LOG_NVME_DISC,
"6009 Unregistered lport Success\n");
} else {
lpfc_printf_vlog(vport,
KERN_INFO, LOG_NVME_DISC,
"6010 Unregistered lport "
"Failed, status x%x\n",
ret);
}
#endif
}
void
lpfc_nvme_update_localport(struct lpfc_vport *vport)
{
#if (IS_ENABLED(CONFIG_NVME_FC))
struct nvme_fc_local_port *localport;
struct lpfc_nvme_lport *lport;
localport = vport->localport;
if (!localport) {
lpfc_printf_vlog(vport, KERN_WARNING, LOG_NVME,
"6710 Update NVME fail. No localport\n");
return;
}
lport = (struct lpfc_nvme_lport *)localport->private;
if (!lport) {
lpfc_printf_vlog(vport, KERN_WARNING, LOG_NVME,
"6171 Update NVME fail. localP %p, No lport\n",
localport);
return;
}
lpfc_printf_vlog(vport, KERN_INFO, LOG_NVME,
"6012 Update NVME lport %p did x%x\n",
localport, vport->fc_myDID);
localport->port_id = vport->fc_myDID;
if (localport->port_id == 0)
localport->port_role = FC_PORT_ROLE_NVME_DISCOVERY;
else
localport->port_role = FC_PORT_ROLE_NVME_INITIATOR;
lpfc_printf_vlog(vport, KERN_INFO, LOG_NVME_DISC,
"6030 bound lport %p to DID x%06x\n",
lport, localport->port_id);
#endif
}
int
lpfc_nvme_register_port(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp)
{
#if (IS_ENABLED(CONFIG_NVME_FC))
int ret = 0;
struct nvme_fc_local_port *localport;
struct lpfc_nvme_lport *lport;
struct lpfc_nvme_rport *rport;
struct nvme_fc_remote_port *remote_port;
struct nvme_fc_port_info rpinfo;
lpfc_printf_vlog(ndlp->vport, KERN_INFO, LOG_NVME_DISC,
"6006 Register NVME PORT. DID x%06x nlptype x%x\n",
ndlp->nlp_DID, ndlp->nlp_type);
localport = vport->localport;
lport = (struct lpfc_nvme_lport *)localport->private;
if (ndlp->nlp_type & (NLP_NVME_TARGET | NLP_NVME_INITIATOR)) {
list_for_each_entry(rport, &lport->rport_list, list) {
if (rport->remoteport->port_name !=
wwn_to_u64(ndlp->nlp_portname.u.wwn))
continue;
lpfc_printf_vlog(ndlp->vport, KERN_INFO, LOG_NVME_DISC,
"6035 lport %p, found matching rport "
"at wwpn 0x%llx, Data: x%x x%x x%x "
"x%06x\n",
lport,
rport->remoteport->port_name,
rport->remoteport->port_id,
rport->remoteport->port_role,
ndlp->nlp_type,
ndlp->nlp_DID);
remote_port = rport->remoteport;
if ((remote_port->port_id == 0) &&
(remote_port->port_role ==
FC_PORT_ROLE_NVME_DISCOVERY)) {
remote_port->port_id = ndlp->nlp_DID;
remote_port->port_role &=
~FC_PORT_ROLE_NVME_DISCOVERY;
if (ndlp->nlp_type & NLP_NVME_TARGET)
remote_port->port_role |=
FC_PORT_ROLE_NVME_TARGET;
if (ndlp->nlp_type & NLP_NVME_INITIATOR)
remote_port->port_role |=
FC_PORT_ROLE_NVME_INITIATOR;
lpfc_printf_vlog(ndlp->vport, KERN_INFO,
LOG_NVME_DISC,
"6014 Rebinding lport to "
"rport wwpn 0x%llx, "
"Data: x%x x%x x%x x%06x\n",
remote_port->port_name,
remote_port->port_id,
remote_port->port_role,
ndlp->nlp_type,
ndlp->nlp_DID);
}
return 0;
}
rpinfo.port_id = ndlp->nlp_DID;
rpinfo.port_role = 0;
if (ndlp->nlp_type & NLP_NVME_TARGET)
rpinfo.port_role |= FC_PORT_ROLE_NVME_TARGET;
if (ndlp->nlp_type & NLP_NVME_INITIATOR)
rpinfo.port_role |= FC_PORT_ROLE_NVME_INITIATOR;
rpinfo.port_name = wwn_to_u64(ndlp->nlp_portname.u.wwn);
rpinfo.node_name = wwn_to_u64(ndlp->nlp_nodename.u.wwn);
ret = nvme_fc_register_remoteport(localport, &rpinfo,
&remote_port);
if (!ret) {
rport = remote_port->private;
rport->remoteport = remote_port;
rport->lport = lport;
rport->ndlp = lpfc_nlp_get(ndlp);
if (!rport->ndlp)
return -1;
ndlp->nrport = rport;
INIT_LIST_HEAD(&rport->list);
list_add_tail(&rport->list, &lport->rport_list);
lpfc_printf_vlog(vport, KERN_INFO,
LOG_NVME_DISC | LOG_NODE,
"6022 Binding new rport to lport %p "
"Rport WWNN 0x%llx, Rport WWPN 0x%llx "
"DID x%06x Role x%x\n",
lport,
rpinfo.node_name, rpinfo.port_name,
rpinfo.port_id, rpinfo.port_role);
} else {
lpfc_printf_vlog(vport, KERN_ERR,
LOG_NVME_DISC | LOG_NODE,
"6031 RemotePort Registration failed "
"err: %d, DID x%06x\n",
ret, ndlp->nlp_DID);
}
} else {
ret = -EINVAL;
lpfc_printf_vlog(vport, KERN_INFO, LOG_NVME_DISC,
"6027 Unknown nlp_type x%x on DID x%06x "
"ndlp %p. Not Registering nvme rport\n",
ndlp->nlp_type, ndlp->nlp_DID, ndlp);
}
return ret;
#else
return 0;
#endif
}
void
lpfc_nvme_unregister_port(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp)
{
#if (IS_ENABLED(CONFIG_NVME_FC))
int ret;
struct nvme_fc_local_port *localport;
struct lpfc_nvme_lport *lport;
struct lpfc_nvme_rport *rport;
struct nvme_fc_remote_port *remoteport;
unsigned long wait_tmo;
localport = vport->localport;
if (!localport)
return;
lport = (struct lpfc_nvme_lport *)localport->private;
if (!lport)
goto input_err;
rport = ndlp->nrport;
if (!rport)
goto input_err;
remoteport = rport->remoteport;
lpfc_printf_vlog(vport, KERN_INFO, LOG_NVME_DISC,
"6033 Unreg nvme remoteport %p, portname x%llx, "
"port_id x%06x, portstate x%x port type x%x\n",
remoteport, remoteport->port_name,
remoteport->port_id, remoteport->port_state,
ndlp->nlp_type);
if (ndlp->nlp_type & (NLP_NVME_TARGET | NLP_NVME_INITIATOR)) {
init_completion(&rport->rport_unreg_done);
ret = nvme_fc_unregister_remoteport(remoteport);
if (ret != 0) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_NVME_DISC,
"6167 NVME unregister failed %d "
"port_state x%x\n",
ret, remoteport->port_state);
}
wait_tmo = msecs_to_jiffies(5000);
ret = wait_for_completion_timeout(&rport->rport_unreg_done,
wait_tmo);
if (ret == 0) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_NVME_DISC,
"6169 Unreg nvme wait timeout\n");
}
}
return;
input_err:
#endif
lpfc_printf_vlog(vport, KERN_ERR, LOG_NVME_DISC,
"6168 State error: lport %p, rport%p FCID x%06x\n",
vport->localport, ndlp->rport, ndlp->nlp_DID);
}
void
lpfc_sli4_nvme_xri_aborted(struct lpfc_hba *phba,
struct sli4_wcqe_xri_aborted *axri)
{
uint16_t xri = bf_get(lpfc_wcqe_xa_xri, axri);
uint16_t rxid = bf_get(lpfc_wcqe_xa_remote_xid, axri);
struct lpfc_nvme_buf *lpfc_ncmd, *next_lpfc_ncmd;
struct lpfc_nodelist *ndlp;
unsigned long iflag = 0;
int rrq_empty = 0;
if (!(phba->cfg_enable_fc4_type & LPFC_ENABLE_NVME))
return;
spin_lock_irqsave(&phba->hbalock, iflag);
spin_lock(&phba->sli4_hba.abts_nvme_buf_list_lock);
list_for_each_entry_safe(lpfc_ncmd, next_lpfc_ncmd,
&phba->sli4_hba.lpfc_abts_nvme_buf_list,
list) {
if (lpfc_ncmd->cur_iocbq.sli4_xritag == xri) {
list_del_init(&lpfc_ncmd->list);
lpfc_ncmd->flags &= ~LPFC_SBUF_XBUSY;
lpfc_ncmd->status = IOSTAT_SUCCESS;
spin_unlock(
&phba->sli4_hba.abts_nvme_buf_list_lock);
rrq_empty = list_empty(&phba->active_rrq_list);
spin_unlock_irqrestore(&phba->hbalock, iflag);
ndlp = lpfc_ncmd->ndlp;
if (ndlp) {
lpfc_set_rrq_active(
phba, ndlp,
lpfc_ncmd->cur_iocbq.sli4_lxritag,
rxid, 1);
lpfc_sli4_abts_err_handler(phba, ndlp, axri);
}
lpfc_printf_log(phba, KERN_INFO, LOG_NVME_ABTS,
"6311 XRI Aborted xri x%x tag x%x "
"released\n",
xri, lpfc_ncmd->cur_iocbq.iotag);
lpfc_release_nvme_buf(phba, lpfc_ncmd);
if (rrq_empty)
lpfc_worker_wake_up(phba);
return;
}
}
spin_unlock(&phba->sli4_hba.abts_nvme_buf_list_lock);
spin_unlock_irqrestore(&phba->hbalock, iflag);
lpfc_printf_log(phba, KERN_INFO, LOG_NVME_ABTS,
"6312 XRI Aborted xri x%x not found\n", xri);
}
