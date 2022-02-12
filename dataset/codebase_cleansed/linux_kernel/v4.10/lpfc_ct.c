static void
lpfc_ct_ignore_hbq_buffer(struct lpfc_hba *phba, struct lpfc_iocbq *piocbq,
struct lpfc_dmabuf *mp, uint32_t size)
{
if (!mp) {
lpfc_printf_log(phba, KERN_INFO, LOG_ELS,
"0146 Ignoring unsolicited CT No HBQ "
"status = x%x\n",
piocbq->iocb.ulpStatus);
}
lpfc_printf_log(phba, KERN_INFO, LOG_ELS,
"0145 Ignoring unsolicted CT HBQ Size:%d "
"status = x%x\n",
size, piocbq->iocb.ulpStatus);
}
static void
lpfc_ct_unsol_buffer(struct lpfc_hba *phba, struct lpfc_iocbq *piocbq,
struct lpfc_dmabuf *mp, uint32_t size)
{
lpfc_ct_ignore_hbq_buffer(phba, piocbq, mp, size);
}
void
lpfc_ct_unsol_event(struct lpfc_hba *phba, struct lpfc_sli_ring *pring,
struct lpfc_iocbq *piocbq)
{
struct lpfc_dmabuf *mp = NULL;
IOCB_t *icmd = &piocbq->iocb;
int i;
struct lpfc_iocbq *iocbq;
dma_addr_t paddr;
uint32_t size;
struct list_head head;
struct lpfc_dmabuf *bdeBuf;
if (lpfc_bsg_ct_unsol_event(phba, pring, piocbq) == 0)
return;
if (unlikely(icmd->ulpStatus == IOSTAT_NEED_BUFFER)) {
lpfc_sli_hbqbuf_add_hbqs(phba, LPFC_ELS_HBQ);
} else if ((icmd->ulpStatus == IOSTAT_LOCAL_REJECT) &&
((icmd->un.ulpWord[4] & IOERR_PARAM_MASK) ==
IOERR_RCV_BUFFER_WAITING)) {
phba->fc_stat.NoRcvBuf++;
if (!(phba->sli3_options & LPFC_SLI3_HBQ_ENABLED))
lpfc_post_buffer(phba, pring, 2);
return;
}
if (icmd->ulpBdeCount == 0)
return;
if (phba->sli3_options & LPFC_SLI3_HBQ_ENABLED) {
INIT_LIST_HEAD(&head);
list_add_tail(&head, &piocbq->list);
list_for_each_entry(iocbq, &head, list) {
icmd = &iocbq->iocb;
if (icmd->ulpBdeCount == 0)
continue;
bdeBuf = iocbq->context2;
iocbq->context2 = NULL;
size = icmd->un.cont64[0].tus.f.bdeSize;
lpfc_ct_unsol_buffer(phba, piocbq, bdeBuf, size);
lpfc_in_buf_free(phba, bdeBuf);
if (icmd->ulpBdeCount == 2) {
bdeBuf = iocbq->context3;
iocbq->context3 = NULL;
size = icmd->unsli3.rcvsli3.bde2.tus.f.bdeSize;
lpfc_ct_unsol_buffer(phba, piocbq, bdeBuf,
size);
lpfc_in_buf_free(phba, bdeBuf);
}
}
list_del(&head);
} else {
INIT_LIST_HEAD(&head);
list_add_tail(&head, &piocbq->list);
list_for_each_entry(iocbq, &head, list) {
icmd = &iocbq->iocb;
if (icmd->ulpBdeCount == 0)
lpfc_ct_unsol_buffer(phba, iocbq, NULL, 0);
for (i = 0; i < icmd->ulpBdeCount; i++) {
paddr = getPaddr(icmd->un.cont64[i].addrHigh,
icmd->un.cont64[i].addrLow);
mp = lpfc_sli_ringpostbuf_get(phba, pring,
paddr);
size = icmd->un.cont64[i].tus.f.bdeSize;
lpfc_ct_unsol_buffer(phba, iocbq, mp, size);
lpfc_in_buf_free(phba, mp);
}
lpfc_post_buffer(phba, pring, i);
}
list_del(&head);
}
}
int
lpfc_ct_handle_unsol_abort(struct lpfc_hba *phba, struct hbq_dmabuf *dmabuf)
{
int handled;
handled = lpfc_bsg_ct_unsol_abort(phba, dmabuf);
return handled;
}
static void
lpfc_free_ct_rsp(struct lpfc_hba *phba, struct lpfc_dmabuf *mlist)
{
struct lpfc_dmabuf *mlast, *next_mlast;
list_for_each_entry_safe(mlast, next_mlast, &mlist->list, list) {
lpfc_mbuf_free(phba, mlast->virt, mlast->phys);
list_del(&mlast->list);
kfree(mlast);
}
lpfc_mbuf_free(phba, mlist->virt, mlist->phys);
kfree(mlist);
return;
}
static struct lpfc_dmabuf *
lpfc_alloc_ct_rsp(struct lpfc_hba *phba, int cmdcode, struct ulp_bde64 *bpl,
uint32_t size, int *entries)
{
struct lpfc_dmabuf *mlist = NULL;
struct lpfc_dmabuf *mp;
int cnt, i = 0;
cnt = size > FCELSSIZE ? FCELSSIZE: size;
while (size) {
mp = kmalloc(sizeof(struct lpfc_dmabuf), GFP_KERNEL);
if (!mp) {
if (mlist)
lpfc_free_ct_rsp(phba, mlist);
return NULL;
}
INIT_LIST_HEAD(&mp->list);
if (cmdcode == be16_to_cpu(SLI_CTNS_GID_FT) ||
cmdcode == be16_to_cpu(SLI_CTNS_GFF_ID))
mp->virt = lpfc_mbuf_alloc(phba, MEM_PRI, &(mp->phys));
else
mp->virt = lpfc_mbuf_alloc(phba, 0, &(mp->phys));
if (!mp->virt) {
kfree(mp);
if (mlist)
lpfc_free_ct_rsp(phba, mlist);
return NULL;
}
if (!mlist)
mlist = mp;
else
list_add_tail(&mp->list, &mlist->list);
bpl->tus.f.bdeFlags = BUFF_TYPE_BDE_64I;
bpl->addrLow = le32_to_cpu(putPaddrLow(mp->phys) );
bpl->addrHigh = le32_to_cpu(putPaddrHigh(mp->phys) );
bpl->tus.f.bdeSize = (uint16_t) cnt;
bpl->tus.w = le32_to_cpu(bpl->tus.w);
bpl++;
i++;
size -= cnt;
}
*entries = i;
return mlist;
}
int
lpfc_ct_free_iocb(struct lpfc_hba *phba, struct lpfc_iocbq *ctiocb)
{
struct lpfc_dmabuf *buf_ptr;
if (ctiocb->context_un.ndlp) {
lpfc_nlp_put(ctiocb->context_un.ndlp);
ctiocb->context_un.ndlp = NULL;
}
if (ctiocb->context1) {
buf_ptr = (struct lpfc_dmabuf *) ctiocb->context1;
lpfc_mbuf_free(phba, buf_ptr->virt, buf_ptr->phys);
kfree(buf_ptr);
ctiocb->context1 = NULL;
}
if (ctiocb->context2) {
lpfc_free_ct_rsp(phba, (struct lpfc_dmabuf *) ctiocb->context2);
ctiocb->context2 = NULL;
}
if (ctiocb->context3) {
buf_ptr = (struct lpfc_dmabuf *) ctiocb->context3;
lpfc_mbuf_free(phba, buf_ptr->virt, buf_ptr->phys);
kfree(buf_ptr);
ctiocb->context3 = NULL;
}
lpfc_sli_release_iocbq(phba, ctiocb);
return 0;
}
static int
lpfc_gen_req(struct lpfc_vport *vport, struct lpfc_dmabuf *bmp,
struct lpfc_dmabuf *inp, struct lpfc_dmabuf *outp,
void (*cmpl) (struct lpfc_hba *, struct lpfc_iocbq *,
struct lpfc_iocbq *),
struct lpfc_nodelist *ndlp, uint32_t usr_flg, uint32_t num_entry,
uint32_t tmo, uint8_t retry)
{
struct lpfc_hba *phba = vport->phba;
IOCB_t *icmd;
struct lpfc_iocbq *geniocb;
int rc;
geniocb = lpfc_sli_get_iocbq(phba);
if (geniocb == NULL)
return 1;
icmd = &geniocb->iocb;
icmd->un.genreq64.bdl.ulpIoTag32 = 0;
icmd->un.genreq64.bdl.addrHigh = putPaddrHigh(bmp->phys);
icmd->un.genreq64.bdl.addrLow = putPaddrLow(bmp->phys);
icmd->un.genreq64.bdl.bdeFlags = BUFF_TYPE_BLP_64;
icmd->un.genreq64.bdl.bdeSize = (num_entry * sizeof(struct ulp_bde64));
if (usr_flg)
geniocb->context3 = NULL;
else
geniocb->context3 = (uint8_t *) bmp;
geniocb->context1 = (uint8_t *) inp;
geniocb->context2 = (uint8_t *) outp;
geniocb->context_un.ndlp = lpfc_nlp_get(ndlp);
icmd->ulpCommand = CMD_GEN_REQUEST64_CR;
icmd->un.genreq64.w5.hcsw.Fctl = (SI | LA);
icmd->un.genreq64.w5.hcsw.Dfctl = 0;
icmd->un.genreq64.w5.hcsw.Rctl = FC_RCTL_DD_UNSOL_CTL;
icmd->un.genreq64.w5.hcsw.Type = FC_TYPE_CT;
if (!tmo) {
tmo = (3 * phba->fc_ratov);
}
icmd->ulpTimeout = tmo;
icmd->ulpBdeCount = 1;
icmd->ulpLe = 1;
icmd->ulpClass = CLASS3;
icmd->ulpContext = ndlp->nlp_rpi;
if (phba->sli_rev == LPFC_SLI_REV4)
icmd->ulpContext = phba->sli4_hba.rpi_ids[ndlp->nlp_rpi];
if (phba->sli3_options & LPFC_SLI3_NPIV_ENABLED) {
icmd->ulpCt_h = 0;
icmd->ulpCt_l = 0;
}
lpfc_printf_vlog(vport, KERN_INFO, LOG_ELS,
"0119 Issue GEN REQ IOCB to NPORT x%x "
"Data: x%x x%x\n",
ndlp->nlp_DID, icmd->ulpIoTag,
vport->port_state);
geniocb->iocb_cmpl = cmpl;
geniocb->drvrTimeout = icmd->ulpTimeout + LPFC_DRVR_TIMEOUT;
geniocb->vport = vport;
geniocb->retry = retry;
rc = lpfc_sli_issue_iocb(phba, LPFC_ELS_RING, geniocb, 0);
if (rc == IOCB_ERROR) {
lpfc_sli_release_iocbq(phba, geniocb);
return 1;
}
return 0;
}
static int
lpfc_ct_cmd(struct lpfc_vport *vport, struct lpfc_dmabuf *inmp,
struct lpfc_dmabuf *bmp, struct lpfc_nodelist *ndlp,
void (*cmpl) (struct lpfc_hba *, struct lpfc_iocbq *,
struct lpfc_iocbq *),
uint32_t rsp_size, uint8_t retry)
{
struct lpfc_hba *phba = vport->phba;
struct ulp_bde64 *bpl = (struct ulp_bde64 *) bmp->virt;
struct lpfc_dmabuf *outmp;
int cnt = 0, status;
int cmdcode = ((struct lpfc_sli_ct_request *) inmp->virt)->
CommandResponse.bits.CmdRsp;
bpl++;
outmp = lpfc_alloc_ct_rsp(phba, cmdcode, bpl, rsp_size, &cnt);
if (!outmp)
return -ENOMEM;
cnt += 1;
status = lpfc_gen_req(vport, bmp, inmp, outmp, cmpl, ndlp, 0,
cnt, 0, retry);
if (status) {
lpfc_free_ct_rsp(phba, outmp);
return -ENOMEM;
}
return 0;
}
struct lpfc_vport *
lpfc_find_vport_by_did(struct lpfc_hba *phba, uint32_t did) {
struct lpfc_vport *vport_curr;
unsigned long flags;
spin_lock_irqsave(&phba->hbalock, flags);
list_for_each_entry(vport_curr, &phba->port_list, listentry) {
if ((vport_curr->fc_myDID) && (vport_curr->fc_myDID == did)) {
spin_unlock_irqrestore(&phba->hbalock, flags);
return vport_curr;
}
}
spin_unlock_irqrestore(&phba->hbalock, flags);
return NULL;
}
static int
lpfc_ns_rsp(struct lpfc_vport *vport, struct lpfc_dmabuf *mp, uint32_t Size)
{
struct lpfc_hba *phba = vport->phba;
struct lpfc_sli_ct_request *Response =
(struct lpfc_sli_ct_request *) mp->virt;
struct lpfc_nodelist *ndlp = NULL;
struct lpfc_dmabuf *mlast, *next_mp;
uint32_t *ctptr = (uint32_t *) & Response->un.gid.PortType;
uint32_t Did, CTentry;
int Cnt;
struct list_head head;
lpfc_set_disctmo(vport);
vport->num_disc_nodes = 0;
vport->fc_ns_retry = 0;
list_add_tail(&head, &mp->list);
list_for_each_entry_safe(mp, next_mp, &head, list) {
mlast = mp;
Cnt = Size > FCELSSIZE ? FCELSSIZE : Size;
Size -= Cnt;
if (!ctptr) {
ctptr = (uint32_t *) mlast->virt;
} else
Cnt -= 16;
while (Cnt >= sizeof(uint32_t)) {
CTentry = *ctptr++;
Did = ((be32_to_cpu(CTentry)) & Mask_DID);
ndlp = NULL;
if ((Did != vport->fc_myDID) &&
((lpfc_find_vport_by_did(phba, Did) == NULL) ||
vport->cfg_peer_port_login)) {
if ((vport->port_type != LPFC_NPIV_PORT) ||
(!(vport->ct_flags & FC_CT_RFF_ID)) ||
(!vport->cfg_restrict_login)) {
ndlp = lpfc_setup_disc_node(vport, Did);
if (ndlp && NLP_CHK_NODE_ACT(ndlp)) {
lpfc_debugfs_disc_trc(vport,
LPFC_DISC_TRC_CT,
"Parse GID_FTrsp: "
"did:x%x flg:x%x x%x",
Did, ndlp->nlp_flag,
vport->fc_flag);
lpfc_printf_vlog(vport,
KERN_INFO,
LOG_DISCOVERY,
"0238 Process "
"x%x NameServer Rsp"
"Data: x%x x%x x%x\n",
Did, ndlp->nlp_flag,
vport->fc_flag,
vport->fc_rscn_id_cnt);
} else {
lpfc_debugfs_disc_trc(vport,
LPFC_DISC_TRC_CT,
"Skip1 GID_FTrsp: "
"did:x%x flg:x%x cnt:%d",
Did, vport->fc_flag,
vport->fc_rscn_id_cnt);
lpfc_printf_vlog(vport,
KERN_INFO,
LOG_DISCOVERY,
"0239 Skip x%x "
"NameServer Rsp Data: "
"x%x x%x\n",
Did, vport->fc_flag,
vport->fc_rscn_id_cnt);
}
} else {
if (!(vport->fc_flag & FC_RSCN_MODE) ||
(lpfc_rscn_payload_check(vport, Did))) {
lpfc_debugfs_disc_trc(vport,
LPFC_DISC_TRC_CT,
"Query GID_FTrsp: "
"did:x%x flg:x%x cnt:%d",
Did, vport->fc_flag,
vport->fc_rscn_id_cnt);
ndlp = lpfc_findnode_did(vport,
Did);
if (ndlp &&
NLP_CHK_NODE_ACT(ndlp)
&& (ndlp->nlp_type &
NLP_FCP_TARGET))
lpfc_setup_disc_node
(vport, Did);
else if (lpfc_ns_cmd(vport,
SLI_CTNS_GFF_ID,
0, Did) == 0)
vport->num_disc_nodes++;
else
lpfc_setup_disc_node
(vport, Did);
}
else {
lpfc_debugfs_disc_trc(vport,
LPFC_DISC_TRC_CT,
"Skip2 GID_FTrsp: "
"did:x%x flg:x%x cnt:%d",
Did, vport->fc_flag,
vport->fc_rscn_id_cnt);
lpfc_printf_vlog(vport,
KERN_INFO,
LOG_DISCOVERY,
"0245 Skip x%x "
"NameServer Rsp Data: "
"x%x x%x\n",
Did, vport->fc_flag,
vport->fc_rscn_id_cnt);
}
}
}
if (CTentry & (cpu_to_be32(SLI_CT_LAST_ENTRY)))
goto nsout1;
Cnt -= sizeof(uint32_t);
}
ctptr = NULL;
}
nsout1:
list_del(&head);
return 0;
}
static void
lpfc_cmpl_ct_cmd_gid_ft(struct lpfc_hba *phba, struct lpfc_iocbq *cmdiocb,
struct lpfc_iocbq *rspiocb)
{
struct lpfc_vport *vport = cmdiocb->vport;
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
IOCB_t *irsp;
struct lpfc_dmabuf *outp;
struct lpfc_sli_ct_request *CTrsp;
struct lpfc_nodelist *ndlp;
int rc;
ndlp = cmdiocb->context_un.ndlp;
cmdiocb->context_un.rsp_iocb = rspiocb;
outp = (struct lpfc_dmabuf *) cmdiocb->context2;
irsp = &rspiocb->iocb;
lpfc_debugfs_disc_trc(vport, LPFC_DISC_TRC_CT,
"GID_FT cmpl: status:x%x/x%x rtry:%d",
irsp->ulpStatus, irsp->un.ulpWord[4], vport->fc_ns_retry);
if (vport->load_flag & FC_UNLOADING) {
if (vport->fc_flag & FC_RSCN_MODE)
lpfc_els_flush_rscn(vport);
goto out;
}
if (lpfc_els_chk_latt(vport)) {
lpfc_printf_vlog(vport, KERN_INFO, LOG_DISCOVERY,
"0216 Link event during NS query\n");
if (vport->fc_flag & FC_RSCN_MODE)
lpfc_els_flush_rscn(vport);
lpfc_vport_set_state(vport, FC_VPORT_FAILED);
goto out;
}
if (lpfc_error_lost_link(irsp)) {
lpfc_printf_vlog(vport, KERN_INFO, LOG_DISCOVERY,
"0226 NS query failed due to link event\n");
if (vport->fc_flag & FC_RSCN_MODE)
lpfc_els_flush_rscn(vport);
goto out;
}
if (irsp->ulpStatus) {
if (vport->fc_ns_retry < LPFC_MAX_NS_RETRY) {
if (irsp->ulpStatus != IOSTAT_LOCAL_REJECT ||
(irsp->un.ulpWord[4] & IOERR_PARAM_MASK) !=
IOERR_NO_RESOURCES)
vport->fc_ns_retry++;
rc = lpfc_ns_cmd(vport, SLI_CTNS_GID_FT,
vport->fc_ns_retry, 0);
if (rc == 0)
goto out;
}
if (vport->fc_flag & FC_RSCN_MODE)
lpfc_els_flush_rscn(vport);
lpfc_vport_set_state(vport, FC_VPORT_FAILED);
lpfc_printf_vlog(vport, KERN_ERR, LOG_ELS,
"0257 GID_FT Query error: 0x%x 0x%x\n",
irsp->ulpStatus, vport->fc_ns_retry);
} else {
CTrsp = (struct lpfc_sli_ct_request *) outp->virt;
if (CTrsp->CommandResponse.bits.CmdRsp ==
cpu_to_be16(SLI_CT_RESPONSE_FS_ACC)) {
lpfc_printf_vlog(vport, KERN_INFO, LOG_DISCOVERY,
"0208 NameServer Rsp Data: x%x\n",
vport->fc_flag);
lpfc_ns_rsp(vport, outp,
(uint32_t) (irsp->un.genreq64.bdl.bdeSize));
} else if (CTrsp->CommandResponse.bits.CmdRsp ==
be16_to_cpu(SLI_CT_RESPONSE_FS_RJT)) {
if ((CTrsp->ReasonCode == SLI_CT_UNABLE_TO_PERFORM_REQ)
&& (CTrsp->Explanation == SLI_CT_NO_FC4_TYPES)) {
lpfc_printf_vlog(vport, KERN_INFO,
LOG_DISCOVERY,
"0269 No NameServer Entries "
"Data: x%x x%x x%x x%x\n",
CTrsp->CommandResponse.bits.CmdRsp,
(uint32_t) CTrsp->ReasonCode,
(uint32_t) CTrsp->Explanation,
vport->fc_flag);
lpfc_debugfs_disc_trc(vport, LPFC_DISC_TRC_CT,
"GID_FT no entry cmd:x%x rsn:x%x exp:x%x",
(uint32_t)CTrsp->CommandResponse.bits.CmdRsp,
(uint32_t) CTrsp->ReasonCode,
(uint32_t) CTrsp->Explanation);
} else {
lpfc_printf_vlog(vport, KERN_INFO,
LOG_DISCOVERY,
"0240 NameServer Rsp Error "
"Data: x%x x%x x%x x%x\n",
CTrsp->CommandResponse.bits.CmdRsp,
(uint32_t) CTrsp->ReasonCode,
(uint32_t) CTrsp->Explanation,
vport->fc_flag);
lpfc_debugfs_disc_trc(vport, LPFC_DISC_TRC_CT,
"GID_FT rsp err1 cmd:x%x rsn:x%x exp:x%x",
(uint32_t)CTrsp->CommandResponse.bits.CmdRsp,
(uint32_t) CTrsp->ReasonCode,
(uint32_t) CTrsp->Explanation);
}
} else {
lpfc_printf_vlog(vport, KERN_ERR, LOG_DISCOVERY,
"0241 NameServer Rsp Error "
"Data: x%x x%x x%x x%x\n",
CTrsp->CommandResponse.bits.CmdRsp,
(uint32_t) CTrsp->ReasonCode,
(uint32_t) CTrsp->Explanation,
vport->fc_flag);
lpfc_debugfs_disc_trc(vport, LPFC_DISC_TRC_CT,
"GID_FT rsp err2 cmd:x%x rsn:x%x exp:x%x",
(uint32_t)CTrsp->CommandResponse.bits.CmdRsp,
(uint32_t) CTrsp->ReasonCode,
(uint32_t) CTrsp->Explanation);
}
}
if (vport->num_disc_nodes == 0) {
if (vport->port_state >= LPFC_DISC_AUTH) {
if (vport->fc_flag & FC_RSCN_MODE) {
lpfc_els_flush_rscn(vport);
spin_lock_irq(shost->host_lock);
vport->fc_flag |= FC_RSCN_MODE;
spin_unlock_irq(shost->host_lock);
}
else
lpfc_els_flush_rscn(vport);
}
lpfc_disc_start(vport);
}
out:
cmdiocb->context_un.ndlp = ndlp;
lpfc_ct_free_iocb(phba, cmdiocb);
return;
}
static void
lpfc_cmpl_ct_cmd_gff_id(struct lpfc_hba *phba, struct lpfc_iocbq *cmdiocb,
struct lpfc_iocbq *rspiocb)
{
struct lpfc_vport *vport = cmdiocb->vport;
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
IOCB_t *irsp = &rspiocb->iocb;
struct lpfc_dmabuf *inp = (struct lpfc_dmabuf *) cmdiocb->context1;
struct lpfc_dmabuf *outp = (struct lpfc_dmabuf *) cmdiocb->context2;
struct lpfc_sli_ct_request *CTrsp;
int did, rc, retry;
uint8_t fbits;
struct lpfc_nodelist *ndlp;
did = ((struct lpfc_sli_ct_request *) inp->virt)->un.gff.PortId;
did = be32_to_cpu(did);
lpfc_debugfs_disc_trc(vport, LPFC_DISC_TRC_CT,
"GFF_ID cmpl: status:x%x/x%x did:x%x",
irsp->ulpStatus, irsp->un.ulpWord[4], did);
if (irsp->ulpStatus == IOSTAT_SUCCESS) {
CTrsp = (struct lpfc_sli_ct_request *) outp->virt;
fbits = CTrsp->un.gff_acc.fbits[FCP_TYPE_FEATURE_OFFSET];
if (CTrsp->CommandResponse.bits.CmdRsp ==
be16_to_cpu(SLI_CT_RESPONSE_FS_ACC)) {
if ((fbits & FC4_FEATURE_INIT) &&
!(fbits & FC4_FEATURE_TARGET)) {
lpfc_printf_vlog(vport, KERN_INFO,
LOG_DISCOVERY,
"0270 Skip x%x GFF "
"NameServer Rsp Data: (init) "
"x%x x%x\n", did, fbits,
vport->fc_rscn_id_cnt);
goto out;
}
}
}
else {
if (cmdiocb->retry < LPFC_MAX_NS_RETRY) {
retry = 1;
if (irsp->ulpStatus == IOSTAT_LOCAL_REJECT) {
switch ((irsp->un.ulpWord[4] &
IOERR_PARAM_MASK)) {
case IOERR_NO_RESOURCES:
break;
case IOERR_LINK_DOWN:
case IOERR_SLI_ABORTED:
case IOERR_SLI_DOWN:
retry = 0;
break;
default:
cmdiocb->retry++;
}
}
else
cmdiocb->retry++;
if (retry) {
rc = lpfc_ns_cmd(vport, SLI_CTNS_GFF_ID,
cmdiocb->retry, did);
if (rc == 0) {
lpfc_ct_free_iocb(phba, cmdiocb);
return;
}
}
}
lpfc_printf_vlog(vport, KERN_ERR, LOG_DISCOVERY,
"0267 NameServer GFF Rsp "
"x%x Error (%d %d) Data: x%x x%x\n",
did, irsp->ulpStatus, irsp->un.ulpWord[4],
vport->fc_flag, vport->fc_rscn_id_cnt);
}
ndlp = lpfc_setup_disc_node(vport, did);
if (ndlp && NLP_CHK_NODE_ACT(ndlp)) {
lpfc_printf_vlog(vport, KERN_INFO, LOG_DISCOVERY,
"0242 Process x%x GFF "
"NameServer Rsp Data: x%x x%x x%x\n",
did, ndlp->nlp_flag, vport->fc_flag,
vport->fc_rscn_id_cnt);
} else {
lpfc_printf_vlog(vport, KERN_INFO, LOG_DISCOVERY,
"0243 Skip x%x GFF "
"NameServer Rsp Data: x%x x%x\n", did,
vport->fc_flag, vport->fc_rscn_id_cnt);
}
out:
if (vport->num_disc_nodes)
vport->num_disc_nodes--;
if (vport->num_disc_nodes == 0) {
if (vport->port_state >= LPFC_DISC_AUTH) {
if (vport->fc_flag & FC_RSCN_MODE) {
lpfc_els_flush_rscn(vport);
spin_lock_irq(shost->host_lock);
vport->fc_flag |= FC_RSCN_MODE;
spin_unlock_irq(shost->host_lock);
}
else
lpfc_els_flush_rscn(vport);
}
lpfc_disc_start(vport);
}
lpfc_ct_free_iocb(phba, cmdiocb);
return;
}
static void
lpfc_cmpl_ct(struct lpfc_hba *phba, struct lpfc_iocbq *cmdiocb,
struct lpfc_iocbq *rspiocb)
{
struct lpfc_vport *vport = cmdiocb->vport;
struct lpfc_dmabuf *inp;
struct lpfc_dmabuf *outp;
IOCB_t *irsp;
struct lpfc_sli_ct_request *CTrsp;
struct lpfc_nodelist *ndlp;
int cmdcode, rc;
uint8_t retry;
uint32_t latt;
ndlp = cmdiocb->context_un.ndlp;
cmdiocb->context_un.rsp_iocb = rspiocb;
inp = (struct lpfc_dmabuf *) cmdiocb->context1;
outp = (struct lpfc_dmabuf *) cmdiocb->context2;
irsp = &rspiocb->iocb;
cmdcode = be16_to_cpu(((struct lpfc_sli_ct_request *) inp->virt)->
CommandResponse.bits.CmdRsp);
CTrsp = (struct lpfc_sli_ct_request *) outp->virt;
latt = lpfc_els_chk_latt(vport);
lpfc_printf_vlog(vport, KERN_INFO, LOG_DISCOVERY,
"0209 CT Request completes, latt %d, "
"ulpStatus x%x CmdRsp x%x, Context x%x, Tag x%x\n",
latt, irsp->ulpStatus,
CTrsp->CommandResponse.bits.CmdRsp,
cmdiocb->iocb.ulpContext, cmdiocb->iocb.ulpIoTag);
lpfc_debugfs_disc_trc(vport, LPFC_DISC_TRC_CT,
"CT cmd cmpl: status:x%x/x%x cmd:x%x",
irsp->ulpStatus, irsp->un.ulpWord[4], cmdcode);
if (irsp->ulpStatus) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_DISCOVERY,
"0268 NS cmd x%x Error (x%x x%x)\n",
cmdcode, irsp->ulpStatus, irsp->un.ulpWord[4]);
if ((irsp->ulpStatus == IOSTAT_LOCAL_REJECT) &&
(((irsp->un.ulpWord[4] & IOERR_PARAM_MASK) ==
IOERR_SLI_DOWN) ||
((irsp->un.ulpWord[4] & IOERR_PARAM_MASK) ==
IOERR_SLI_ABORTED)))
goto out;
retry = cmdiocb->retry;
if (retry >= LPFC_MAX_NS_RETRY)
goto out;
retry++;
lpfc_printf_vlog(vport, KERN_INFO, LOG_DISCOVERY,
"0250 Retrying NS cmd %x\n", cmdcode);
rc = lpfc_ns_cmd(vport, cmdcode, retry, 0);
if (rc == 0)
goto out;
}
out:
cmdiocb->context_un.ndlp = ndlp;
lpfc_ct_free_iocb(phba, cmdiocb);
return;
}
static void
lpfc_cmpl_ct_cmd_rft_id(struct lpfc_hba *phba, struct lpfc_iocbq *cmdiocb,
struct lpfc_iocbq *rspiocb)
{
IOCB_t *irsp = &rspiocb->iocb;
struct lpfc_vport *vport = cmdiocb->vport;
if (irsp->ulpStatus == IOSTAT_SUCCESS) {
struct lpfc_dmabuf *outp;
struct lpfc_sli_ct_request *CTrsp;
outp = (struct lpfc_dmabuf *) cmdiocb->context2;
CTrsp = (struct lpfc_sli_ct_request *) outp->virt;
if (CTrsp->CommandResponse.bits.CmdRsp ==
be16_to_cpu(SLI_CT_RESPONSE_FS_ACC))
vport->ct_flags |= FC_CT_RFT_ID;
}
lpfc_cmpl_ct(phba, cmdiocb, rspiocb);
return;
}
static void
lpfc_cmpl_ct_cmd_rnn_id(struct lpfc_hba *phba, struct lpfc_iocbq *cmdiocb,
struct lpfc_iocbq *rspiocb)
{
IOCB_t *irsp = &rspiocb->iocb;
struct lpfc_vport *vport = cmdiocb->vport;
if (irsp->ulpStatus == IOSTAT_SUCCESS) {
struct lpfc_dmabuf *outp;
struct lpfc_sli_ct_request *CTrsp;
outp = (struct lpfc_dmabuf *) cmdiocb->context2;
CTrsp = (struct lpfc_sli_ct_request *) outp->virt;
if (CTrsp->CommandResponse.bits.CmdRsp ==
be16_to_cpu(SLI_CT_RESPONSE_FS_ACC))
vport->ct_flags |= FC_CT_RNN_ID;
}
lpfc_cmpl_ct(phba, cmdiocb, rspiocb);
return;
}
static void
lpfc_cmpl_ct_cmd_rspn_id(struct lpfc_hba *phba, struct lpfc_iocbq *cmdiocb,
struct lpfc_iocbq *rspiocb)
{
IOCB_t *irsp = &rspiocb->iocb;
struct lpfc_vport *vport = cmdiocb->vport;
if (irsp->ulpStatus == IOSTAT_SUCCESS) {
struct lpfc_dmabuf *outp;
struct lpfc_sli_ct_request *CTrsp;
outp = (struct lpfc_dmabuf *) cmdiocb->context2;
CTrsp = (struct lpfc_sli_ct_request *) outp->virt;
if (CTrsp->CommandResponse.bits.CmdRsp ==
be16_to_cpu(SLI_CT_RESPONSE_FS_ACC))
vport->ct_flags |= FC_CT_RSPN_ID;
}
lpfc_cmpl_ct(phba, cmdiocb, rspiocb);
return;
}
static void
lpfc_cmpl_ct_cmd_rsnn_nn(struct lpfc_hba *phba, struct lpfc_iocbq *cmdiocb,
struct lpfc_iocbq *rspiocb)
{
IOCB_t *irsp = &rspiocb->iocb;
struct lpfc_vport *vport = cmdiocb->vport;
if (irsp->ulpStatus == IOSTAT_SUCCESS) {
struct lpfc_dmabuf *outp;
struct lpfc_sli_ct_request *CTrsp;
outp = (struct lpfc_dmabuf *) cmdiocb->context2;
CTrsp = (struct lpfc_sli_ct_request *) outp->virt;
if (CTrsp->CommandResponse.bits.CmdRsp ==
be16_to_cpu(SLI_CT_RESPONSE_FS_ACC))
vport->ct_flags |= FC_CT_RSNN_NN;
}
lpfc_cmpl_ct(phba, cmdiocb, rspiocb);
return;
}
static void
lpfc_cmpl_ct_cmd_da_id(struct lpfc_hba *phba, struct lpfc_iocbq *cmdiocb,
struct lpfc_iocbq *rspiocb)
{
struct lpfc_vport *vport = cmdiocb->vport;
vport->ct_flags = 0;
lpfc_cmpl_ct(phba, cmdiocb, rspiocb);
return;
}
static void
lpfc_cmpl_ct_cmd_rff_id(struct lpfc_hba *phba, struct lpfc_iocbq *cmdiocb,
struct lpfc_iocbq *rspiocb)
{
IOCB_t *irsp = &rspiocb->iocb;
struct lpfc_vport *vport = cmdiocb->vport;
if (irsp->ulpStatus == IOSTAT_SUCCESS) {
struct lpfc_dmabuf *outp;
struct lpfc_sli_ct_request *CTrsp;
outp = (struct lpfc_dmabuf *) cmdiocb->context2;
CTrsp = (struct lpfc_sli_ct_request *) outp->virt;
if (CTrsp->CommandResponse.bits.CmdRsp ==
be16_to_cpu(SLI_CT_RESPONSE_FS_ACC))
vport->ct_flags |= FC_CT_RFF_ID;
}
lpfc_cmpl_ct(phba, cmdiocb, rspiocb);
return;
}
int
lpfc_vport_symbolic_port_name(struct lpfc_vport *vport, char *symbol,
size_t size)
{
int n;
uint8_t *wwn = vport->phba->wwpn;
n = snprintf(symbol, size,
"Emulex PPN-%02x:%02x:%02x:%02x:%02x:%02x:%02x:%02x",
wwn[0], wwn[1], wwn[2], wwn[3],
wwn[4], wwn[5], wwn[6], wwn[7]);
if (vport->port_type == LPFC_PHYSICAL_PORT)
return n;
if (n < size)
n += snprintf(symbol + n, size - n, " VPort-%d", vport->vpi);
if (n < size &&
strlen(vport->fc_vport->symbolic_name))
n += snprintf(symbol + n, size - n, " VName-%s",
vport->fc_vport->symbolic_name);
return n;
}
int
lpfc_vport_symbolic_node_name(struct lpfc_vport *vport, char *symbol,
size_t size)
{
char fwrev[FW_REV_STR_SIZE];
int n;
lpfc_decode_firmware_rev(vport->phba, fwrev, 0);
n = snprintf(symbol, size, "Emulex %s", vport->phba->ModelName);
if (size < n)
return n;
n += snprintf(symbol + n, size - n, " FV%s", fwrev);
if (size < n)
return n;
n += snprintf(symbol + n, size - n, " DV%s", lpfc_release_version);
if (size < n)
return n;
n += snprintf(symbol + n, size - n, " HN:%s", init_utsname()->nodename);
if (size < n)
return n;
n += snprintf(symbol + n, size - n, " OS:%s", init_utsname()->sysname);
return n;
}
static uint32_t
lpfc_find_map_node(struct lpfc_vport *vport)
{
struct lpfc_nodelist *ndlp, *next_ndlp;
struct Scsi_Host *shost;
uint32_t cnt = 0;
shost = lpfc_shost_from_vport(vport);
spin_lock_irq(shost->host_lock);
list_for_each_entry_safe(ndlp, next_ndlp, &vport->fc_nodes, nlp_listp) {
if (ndlp->nlp_type & NLP_FABRIC)
continue;
if ((ndlp->nlp_state == NLP_STE_MAPPED_NODE) ||
(ndlp->nlp_state == NLP_STE_UNMAPPED_NODE))
cnt++;
}
spin_unlock_irq(shost->host_lock);
return cnt;
}
int
lpfc_ns_cmd(struct lpfc_vport *vport, int cmdcode,
uint8_t retry, uint32_t context)
{
struct lpfc_nodelist * ndlp;
struct lpfc_hba *phba = vport->phba;
struct lpfc_dmabuf *mp, *bmp;
struct lpfc_sli_ct_request *CtReq;
struct ulp_bde64 *bpl;
void (*cmpl) (struct lpfc_hba *, struct lpfc_iocbq *,
struct lpfc_iocbq *) = NULL;
uint32_t rsp_size = 1024;
size_t size;
int rc = 0;
ndlp = lpfc_findnode_did(vport, NameServer_DID);
if (!ndlp || !NLP_CHK_NODE_ACT(ndlp)
|| ndlp->nlp_state != NLP_STE_UNMAPPED_NODE) {
rc=1;
goto ns_cmd_exit;
}
mp = kmalloc(sizeof(struct lpfc_dmabuf), GFP_KERNEL);
if (!mp) {
rc=2;
goto ns_cmd_exit;
}
INIT_LIST_HEAD(&mp->list);
mp->virt = lpfc_mbuf_alloc(phba, MEM_PRI, &(mp->phys));
if (!mp->virt) {
rc=3;
goto ns_cmd_free_mp;
}
bmp = kmalloc(sizeof(struct lpfc_dmabuf), GFP_KERNEL);
if (!bmp) {
rc=4;
goto ns_cmd_free_mpvirt;
}
INIT_LIST_HEAD(&bmp->list);
bmp->virt = lpfc_mbuf_alloc(phba, MEM_PRI, &(bmp->phys));
if (!bmp->virt) {
rc=5;
goto ns_cmd_free_bmp;
}
lpfc_printf_vlog(vport, KERN_INFO ,LOG_DISCOVERY,
"0236 NameServer Req Data: x%x x%x x%x\n",
cmdcode, vport->fc_flag, vport->fc_rscn_id_cnt);
bpl = (struct ulp_bde64 *) bmp->virt;
memset(bpl, 0, sizeof(struct ulp_bde64));
bpl->addrHigh = le32_to_cpu(putPaddrHigh(mp->phys) );
bpl->addrLow = le32_to_cpu(putPaddrLow(mp->phys) );
bpl->tus.f.bdeFlags = 0;
if (cmdcode == SLI_CTNS_GID_FT)
bpl->tus.f.bdeSize = GID_REQUEST_SZ;
else if (cmdcode == SLI_CTNS_GFF_ID)
bpl->tus.f.bdeSize = GFF_REQUEST_SZ;
else if (cmdcode == SLI_CTNS_RFT_ID)
bpl->tus.f.bdeSize = RFT_REQUEST_SZ;
else if (cmdcode == SLI_CTNS_RNN_ID)
bpl->tus.f.bdeSize = RNN_REQUEST_SZ;
else if (cmdcode == SLI_CTNS_RSPN_ID)
bpl->tus.f.bdeSize = RSPN_REQUEST_SZ;
else if (cmdcode == SLI_CTNS_RSNN_NN)
bpl->tus.f.bdeSize = RSNN_REQUEST_SZ;
else if (cmdcode == SLI_CTNS_DA_ID)
bpl->tus.f.bdeSize = DA_ID_REQUEST_SZ;
else if (cmdcode == SLI_CTNS_RFF_ID)
bpl->tus.f.bdeSize = RFF_REQUEST_SZ;
else
bpl->tus.f.bdeSize = 0;
bpl->tus.w = le32_to_cpu(bpl->tus.w);
CtReq = (struct lpfc_sli_ct_request *) mp->virt;
memset(CtReq, 0, sizeof(struct lpfc_sli_ct_request));
CtReq->RevisionId.bits.Revision = SLI_CT_REVISION;
CtReq->RevisionId.bits.InId = 0;
CtReq->FsType = SLI_CT_DIRECTORY_SERVICE;
CtReq->FsSubType = SLI_CT_DIRECTORY_NAME_SERVER;
CtReq->CommandResponse.bits.Size = 0;
switch (cmdcode) {
case SLI_CTNS_GID_FT:
CtReq->CommandResponse.bits.CmdRsp =
cpu_to_be16(SLI_CTNS_GID_FT);
CtReq->un.gid.Fc4Type = SLI_CTPT_FCP;
if (vport->port_state < LPFC_NS_QRY)
vport->port_state = LPFC_NS_QRY;
lpfc_set_disctmo(vport);
cmpl = lpfc_cmpl_ct_cmd_gid_ft;
rsp_size = FC_MAX_NS_RSP;
break;
case SLI_CTNS_GFF_ID:
CtReq->CommandResponse.bits.CmdRsp =
cpu_to_be16(SLI_CTNS_GFF_ID);
CtReq->un.gff.PortId = cpu_to_be32(context);
cmpl = lpfc_cmpl_ct_cmd_gff_id;
break;
case SLI_CTNS_RFT_ID:
vport->ct_flags &= ~FC_CT_RFT_ID;
CtReq->CommandResponse.bits.CmdRsp =
cpu_to_be16(SLI_CTNS_RFT_ID);
CtReq->un.rft.PortId = cpu_to_be32(vport->fc_myDID);
CtReq->un.rft.fcpReg = 1;
cmpl = lpfc_cmpl_ct_cmd_rft_id;
break;
case SLI_CTNS_RNN_ID:
vport->ct_flags &= ~FC_CT_RNN_ID;
CtReq->CommandResponse.bits.CmdRsp =
cpu_to_be16(SLI_CTNS_RNN_ID);
CtReq->un.rnn.PortId = cpu_to_be32(vport->fc_myDID);
memcpy(CtReq->un.rnn.wwnn, &vport->fc_nodename,
sizeof(struct lpfc_name));
cmpl = lpfc_cmpl_ct_cmd_rnn_id;
break;
case SLI_CTNS_RSPN_ID:
vport->ct_flags &= ~FC_CT_RSPN_ID;
CtReq->CommandResponse.bits.CmdRsp =
cpu_to_be16(SLI_CTNS_RSPN_ID);
CtReq->un.rspn.PortId = cpu_to_be32(vport->fc_myDID);
size = sizeof(CtReq->un.rspn.symbname);
CtReq->un.rspn.len =
lpfc_vport_symbolic_port_name(vport,
CtReq->un.rspn.symbname, size);
cmpl = lpfc_cmpl_ct_cmd_rspn_id;
break;
case SLI_CTNS_RSNN_NN:
vport->ct_flags &= ~FC_CT_RSNN_NN;
CtReq->CommandResponse.bits.CmdRsp =
cpu_to_be16(SLI_CTNS_RSNN_NN);
memcpy(CtReq->un.rsnn.wwnn, &vport->fc_nodename,
sizeof(struct lpfc_name));
size = sizeof(CtReq->un.rsnn.symbname);
CtReq->un.rsnn.len =
lpfc_vport_symbolic_node_name(vport,
CtReq->un.rsnn.symbname, size);
cmpl = lpfc_cmpl_ct_cmd_rsnn_nn;
break;
case SLI_CTNS_DA_ID:
CtReq->CommandResponse.bits.CmdRsp =
cpu_to_be16(SLI_CTNS_DA_ID);
CtReq->un.da_id.port_id = cpu_to_be32(vport->fc_myDID);
cmpl = lpfc_cmpl_ct_cmd_da_id;
break;
case SLI_CTNS_RFF_ID:
vport->ct_flags &= ~FC_CT_RFF_ID;
CtReq->CommandResponse.bits.CmdRsp =
cpu_to_be16(SLI_CTNS_RFF_ID);
CtReq->un.rff.PortId = cpu_to_be32(vport->fc_myDID);
CtReq->un.rff.fbits = FC4_FEATURE_INIT;
CtReq->un.rff.type_code = FC_TYPE_FCP;
cmpl = lpfc_cmpl_ct_cmd_rff_id;
break;
}
if (!lpfc_ct_cmd(vport, mp, bmp, ndlp, cmpl, rsp_size, retry)) {
lpfc_debugfs_disc_trc(vport, LPFC_DISC_TRC_CT,
"Issue CT cmd: cmd:x%x did:x%x",
cmdcode, ndlp->nlp_DID, 0);
return 0;
}
rc=6;
lpfc_nlp_put(ndlp);
lpfc_mbuf_free(phba, bmp->virt, bmp->phys);
ns_cmd_free_bmp:
kfree(bmp);
ns_cmd_free_mpvirt:
lpfc_mbuf_free(phba, mp->virt, mp->phys);
ns_cmd_free_mp:
kfree(mp);
ns_cmd_exit:
lpfc_printf_vlog(vport, KERN_ERR, LOG_DISCOVERY,
"0266 Issue NameServer Req x%x err %d Data: x%x x%x\n",
cmdcode, rc, vport->fc_flag, vport->fc_rscn_id_cnt);
return 1;
}
static void
lpfc_cmpl_ct_disc_fdmi(struct lpfc_hba *phba, struct lpfc_iocbq *cmdiocb,
struct lpfc_iocbq *rspiocb)
{
struct lpfc_vport *vport = cmdiocb->vport;
struct lpfc_dmabuf *inp = cmdiocb->context1;
struct lpfc_dmabuf *outp = cmdiocb->context2;
struct lpfc_sli_ct_request *CTcmd = inp->virt;
struct lpfc_sli_ct_request *CTrsp = outp->virt;
uint16_t fdmi_cmd = CTcmd->CommandResponse.bits.CmdRsp;
uint16_t fdmi_rsp = CTrsp->CommandResponse.bits.CmdRsp;
IOCB_t *irsp = &rspiocb->iocb;
struct lpfc_nodelist *ndlp;
uint32_t latt, cmd, err;
latt = lpfc_els_chk_latt(vport);
lpfc_debugfs_disc_trc(vport, LPFC_DISC_TRC_CT,
"FDMI cmpl: status:x%x/x%x latt:%d",
irsp->ulpStatus, irsp->un.ulpWord[4], latt);
if (latt || irsp->ulpStatus) {
if (irsp->ulpStatus == IOSTAT_LOCAL_REJECT) {
switch ((irsp->un.ulpWord[4] & IOERR_PARAM_MASK)) {
case IOERR_SLI_ABORTED:
case IOERR_ABORT_IN_PROGRESS:
case IOERR_SEQUENCE_TIMEOUT:
case IOERR_ILLEGAL_FRAME:
case IOERR_NO_RESOURCES:
case IOERR_ILLEGAL_COMMAND:
cmdiocb->retry++;
if (cmdiocb->retry >= LPFC_FDMI_MAX_RETRY)
break;
err = lpfc_sli_issue_iocb(phba, LPFC_ELS_RING,
cmdiocb, 0);
if (err == IOCB_ERROR)
break;
return;
default:
break;
}
}
lpfc_printf_vlog(vport, KERN_INFO, LOG_DISCOVERY,
"0229 FDMI cmd %04x failed, latt = %d "
"ulpStatus: x%x, rid x%x\n",
be16_to_cpu(fdmi_cmd), latt, irsp->ulpStatus,
irsp->un.ulpWord[4]);
}
lpfc_ct_free_iocb(phba, cmdiocb);
ndlp = lpfc_findnode_did(vport, FDMI_DID);
if (!ndlp || !NLP_CHK_NODE_ACT(ndlp))
return;
cmd = be16_to_cpu(fdmi_cmd);
if (fdmi_rsp == cpu_to_be16(SLI_CT_RESPONSE_FS_RJT)) {
lpfc_printf_vlog(vport, KERN_INFO, LOG_DISCOVERY,
"0220 FDMI cmd failed FS_RJT Data: x%x", cmd);
switch (cmd) {
case SLI_MGMT_RHBA:
if (vport->fdmi_hba_mask == LPFC_FDMI2_HBA_ATTR) {
vport->fdmi_hba_mask = LPFC_FDMI1_HBA_ATTR;
vport->fdmi_port_mask = LPFC_FDMI1_PORT_ATTR;
lpfc_fdmi_cmd(vport, ndlp, SLI_MGMT_DHBA, 0);
}
return;
case SLI_MGMT_RPRT:
if (vport->fdmi_port_mask == LPFC_FDMI2_PORT_ATTR) {
vport->fdmi_port_mask = LPFC_FDMI1_PORT_ATTR;
lpfc_fdmi_cmd(vport, ndlp, cmd, 0);
}
if (vport->fdmi_port_mask == LPFC_FDMI2_SMART_ATTR) {
vport->fdmi_port_mask = LPFC_FDMI2_PORT_ATTR;
lpfc_fdmi_cmd(vport, ndlp, cmd, 0);
}
return;
case SLI_MGMT_RPA:
if (vport->fdmi_port_mask == LPFC_FDMI2_PORT_ATTR) {
vport->fdmi_hba_mask = LPFC_FDMI1_HBA_ATTR;
vport->fdmi_port_mask = LPFC_FDMI1_PORT_ATTR;
lpfc_fdmi_cmd(vport, ndlp, SLI_MGMT_DHBA, 0);
}
if (vport->fdmi_port_mask == LPFC_FDMI2_SMART_ATTR) {
vport->fdmi_port_mask = LPFC_FDMI2_PORT_ATTR;
lpfc_fdmi_cmd(vport, ndlp, cmd, 0);
}
return;
}
}
switch (cmd) {
case SLI_MGMT_RHBA:
lpfc_fdmi_cmd(vport, ndlp, SLI_MGMT_RPA, 0);
break;
case SLI_MGMT_DHBA:
lpfc_fdmi_cmd(vport, ndlp, SLI_MGMT_DPRT, 0);
break;
case SLI_MGMT_DPRT:
if (vport->port_type == LPFC_PHYSICAL_PORT)
lpfc_fdmi_cmd(vport, ndlp, SLI_MGMT_RHBA, 0);
else
lpfc_fdmi_cmd(vport, ndlp, SLI_MGMT_RPRT, 0);
break;
}
return;
}
void
lpfc_fdmi_num_disc_check(struct lpfc_vport *vport)
{
struct lpfc_hba *phba = vport->phba;
struct lpfc_nodelist *ndlp;
uint16_t cnt;
if (!lpfc_is_link_up(phba))
return;
if (!(vport->fc_flag & FC_FABRIC))
return;
if (!(vport->fdmi_port_mask & LPFC_FDMI_PORT_ATTR_num_disc))
return;
cnt = lpfc_find_map_node(vport);
if (cnt == vport->fdmi_num_disc)
return;
ndlp = lpfc_findnode_did(vport, FDMI_DID);
if (!ndlp || !NLP_CHK_NODE_ACT(ndlp))
return;
if (vport->port_type == LPFC_PHYSICAL_PORT) {
lpfc_fdmi_cmd(vport, ndlp, SLI_MGMT_RPA,
LPFC_FDMI_PORT_ATTR_num_disc);
} else {
lpfc_fdmi_cmd(vport, ndlp, SLI_MGMT_RPRT,
LPFC_FDMI_PORT_ATTR_num_disc);
}
}
static int
lpfc_fdmi_hba_attr_wwnn(struct lpfc_vport *vport, struct lpfc_fdmi_attr_def *ad)
{
struct lpfc_fdmi_attr_entry *ae;
uint32_t size;
ae = (struct lpfc_fdmi_attr_entry *)&ad->AttrValue;
memset(ae, 0, sizeof(struct lpfc_name));
memcpy(&ae->un.AttrWWN, &vport->fc_sparam.nodeName,
sizeof(struct lpfc_name));
size = FOURBYTES + sizeof(struct lpfc_name);
ad->AttrLen = cpu_to_be16(size);
ad->AttrType = cpu_to_be16(RHBA_NODENAME);
return size;
}
static int
lpfc_fdmi_hba_attr_manufacturer(struct lpfc_vport *vport,
struct lpfc_fdmi_attr_def *ad)
{
struct lpfc_fdmi_attr_entry *ae;
uint32_t len, size;
ae = (struct lpfc_fdmi_attr_entry *)&ad->AttrValue;
memset(ae, 0, 256);
strncpy(ae->un.AttrString,
"Emulex Corporation",
sizeof(ae->un.AttrString));
len = strnlen(ae->un.AttrString,
sizeof(ae->un.AttrString));
len += (len & 3) ? (4 - (len & 3)) : 4;
size = FOURBYTES + len;
ad->AttrLen = cpu_to_be16(size);
ad->AttrType = cpu_to_be16(RHBA_MANUFACTURER);
return size;
}
static int
lpfc_fdmi_hba_attr_sn(struct lpfc_vport *vport, struct lpfc_fdmi_attr_def *ad)
{
struct lpfc_hba *phba = vport->phba;
struct lpfc_fdmi_attr_entry *ae;
uint32_t len, size;
ae = (struct lpfc_fdmi_attr_entry *)&ad->AttrValue;
memset(ae, 0, 256);
strncpy(ae->un.AttrString, phba->SerialNumber,
sizeof(ae->un.AttrString));
len = strnlen(ae->un.AttrString,
sizeof(ae->un.AttrString));
len += (len & 3) ? (4 - (len & 3)) : 4;
size = FOURBYTES + len;
ad->AttrLen = cpu_to_be16(size);
ad->AttrType = cpu_to_be16(RHBA_SERIAL_NUMBER);
return size;
}
static int
lpfc_fdmi_hba_attr_model(struct lpfc_vport *vport,
struct lpfc_fdmi_attr_def *ad)
{
struct lpfc_hba *phba = vport->phba;
struct lpfc_fdmi_attr_entry *ae;
uint32_t len, size;
ae = (struct lpfc_fdmi_attr_entry *)&ad->AttrValue;
memset(ae, 0, 256);
strncpy(ae->un.AttrString, phba->ModelName,
sizeof(ae->un.AttrString));
len = strnlen(ae->un.AttrString, sizeof(ae->un.AttrString));
len += (len & 3) ? (4 - (len & 3)) : 4;
size = FOURBYTES + len;
ad->AttrLen = cpu_to_be16(size);
ad->AttrType = cpu_to_be16(RHBA_MODEL);
return size;
}
static int
lpfc_fdmi_hba_attr_description(struct lpfc_vport *vport,
struct lpfc_fdmi_attr_def *ad)
{
struct lpfc_hba *phba = vport->phba;
struct lpfc_fdmi_attr_entry *ae;
uint32_t len, size;
ae = (struct lpfc_fdmi_attr_entry *)&ad->AttrValue;
memset(ae, 0, 256);
strncpy(ae->un.AttrString, phba->ModelDesc,
sizeof(ae->un.AttrString));
len = strnlen(ae->un.AttrString,
sizeof(ae->un.AttrString));
len += (len & 3) ? (4 - (len & 3)) : 4;
size = FOURBYTES + len;
ad->AttrLen = cpu_to_be16(size);
ad->AttrType = cpu_to_be16(RHBA_MODEL_DESCRIPTION);
return size;
}
static int
lpfc_fdmi_hba_attr_hdw_ver(struct lpfc_vport *vport,
struct lpfc_fdmi_attr_def *ad)
{
struct lpfc_hba *phba = vport->phba;
lpfc_vpd_t *vp = &phba->vpd;
struct lpfc_fdmi_attr_entry *ae;
uint32_t i, j, incr, size;
ae = (struct lpfc_fdmi_attr_entry *)&ad->AttrValue;
memset(ae, 0, 256);
incr = vp->rev.biuRev;
for (i = 0; i < 8; i++) {
j = (incr & 0xf);
if (j <= 9)
ae->un.AttrString[7 - i] =
(char)((uint8_t) 0x30 +
(uint8_t) j);
else
ae->un.AttrString[7 - i] =
(char)((uint8_t) 0x61 +
(uint8_t) (j - 10));
incr = (incr >> 4);
}
size = FOURBYTES + 8;
ad->AttrLen = cpu_to_be16(size);
ad->AttrType = cpu_to_be16(RHBA_HARDWARE_VERSION);
return size;
}
static int
lpfc_fdmi_hba_attr_drvr_ver(struct lpfc_vport *vport,
struct lpfc_fdmi_attr_def *ad)
{
struct lpfc_fdmi_attr_entry *ae;
uint32_t len, size;
ae = (struct lpfc_fdmi_attr_entry *)&ad->AttrValue;
memset(ae, 0, 256);
strncpy(ae->un.AttrString, lpfc_release_version,
sizeof(ae->un.AttrString));
len = strnlen(ae->un.AttrString,
sizeof(ae->un.AttrString));
len += (len & 3) ? (4 - (len & 3)) : 4;
size = FOURBYTES + len;
ad->AttrLen = cpu_to_be16(size);
ad->AttrType = cpu_to_be16(RHBA_DRIVER_VERSION);
return size;
}
static int
lpfc_fdmi_hba_attr_rom_ver(struct lpfc_vport *vport,
struct lpfc_fdmi_attr_def *ad)
{
struct lpfc_hba *phba = vport->phba;
struct lpfc_fdmi_attr_entry *ae;
uint32_t len, size;
ae = (struct lpfc_fdmi_attr_entry *)&ad->AttrValue;
memset(ae, 0, 256);
if (phba->sli_rev == LPFC_SLI_REV4)
lpfc_decode_firmware_rev(phba, ae->un.AttrString, 1);
else
strncpy(ae->un.AttrString, phba->OptionROMVersion,
sizeof(ae->un.AttrString));
len = strnlen(ae->un.AttrString,
sizeof(ae->un.AttrString));
len += (len & 3) ? (4 - (len & 3)) : 4;
size = FOURBYTES + len;
ad->AttrLen = cpu_to_be16(size);
ad->AttrType = cpu_to_be16(RHBA_OPTION_ROM_VERSION);
return size;
}
static int
lpfc_fdmi_hba_attr_fmw_ver(struct lpfc_vport *vport,
struct lpfc_fdmi_attr_def *ad)
{
struct lpfc_hba *phba = vport->phba;
struct lpfc_fdmi_attr_entry *ae;
uint32_t len, size;
ae = (struct lpfc_fdmi_attr_entry *)&ad->AttrValue;
memset(ae, 0, 256);
lpfc_decode_firmware_rev(phba, ae->un.AttrString, 1);
len = strnlen(ae->un.AttrString,
sizeof(ae->un.AttrString));
len += (len & 3) ? (4 - (len & 3)) : 4;
size = FOURBYTES + len;
ad->AttrLen = cpu_to_be16(size);
ad->AttrType = cpu_to_be16(RHBA_FIRMWARE_VERSION);
return size;
}
static int
lpfc_fdmi_hba_attr_os_ver(struct lpfc_vport *vport,
struct lpfc_fdmi_attr_def *ad)
{
struct lpfc_fdmi_attr_entry *ae;
uint32_t len, size;
ae = (struct lpfc_fdmi_attr_entry *)&ad->AttrValue;
memset(ae, 0, 256);
snprintf(ae->un.AttrString, sizeof(ae->un.AttrString), "%s %s %s",
init_utsname()->sysname,
init_utsname()->release,
init_utsname()->version);
len = strnlen(ae->un.AttrString, sizeof(ae->un.AttrString));
len += (len & 3) ? (4 - (len & 3)) : 4;
size = FOURBYTES + len;
ad->AttrLen = cpu_to_be16(size);
ad->AttrType = cpu_to_be16(RHBA_OS_NAME_VERSION);
return size;
}
static int
lpfc_fdmi_hba_attr_ct_len(struct lpfc_vport *vport,
struct lpfc_fdmi_attr_def *ad)
{
struct lpfc_fdmi_attr_entry *ae;
uint32_t size;
ae = (struct lpfc_fdmi_attr_entry *)&ad->AttrValue;
ae->un.AttrInt = cpu_to_be32(LPFC_MAX_CT_SIZE);
size = FOURBYTES + sizeof(uint32_t);
ad->AttrLen = cpu_to_be16(size);
ad->AttrType = cpu_to_be16(RHBA_MAX_CT_PAYLOAD_LEN);
return size;
}
static int
lpfc_fdmi_hba_attr_symbolic_name(struct lpfc_vport *vport,
struct lpfc_fdmi_attr_def *ad)
{
struct lpfc_fdmi_attr_entry *ae;
uint32_t len, size;
ae = (struct lpfc_fdmi_attr_entry *)&ad->AttrValue;
memset(ae, 0, 256);
len = lpfc_vport_symbolic_node_name(vport,
ae->un.AttrString, 256);
len += (len & 3) ? (4 - (len & 3)) : 4;
size = FOURBYTES + len;
ad->AttrLen = cpu_to_be16(size);
ad->AttrType = cpu_to_be16(RHBA_SYM_NODENAME);
return size;
}
static int
lpfc_fdmi_hba_attr_vendor_info(struct lpfc_vport *vport,
struct lpfc_fdmi_attr_def *ad)
{
struct lpfc_fdmi_attr_entry *ae;
uint32_t size;
ae = (struct lpfc_fdmi_attr_entry *)&ad->AttrValue;
ae->un.AttrInt = cpu_to_be32(0);
size = FOURBYTES + sizeof(uint32_t);
ad->AttrLen = cpu_to_be16(size);
ad->AttrType = cpu_to_be16(RHBA_VENDOR_INFO);
return size;
}
static int
lpfc_fdmi_hba_attr_num_ports(struct lpfc_vport *vport,
struct lpfc_fdmi_attr_def *ad)
{
struct lpfc_fdmi_attr_entry *ae;
uint32_t size;
ae = (struct lpfc_fdmi_attr_entry *)&ad->AttrValue;
ae->un.AttrInt = cpu_to_be32(1);
size = FOURBYTES + sizeof(uint32_t);
ad->AttrLen = cpu_to_be16(size);
ad->AttrType = cpu_to_be16(RHBA_NUM_PORTS);
return size;
}
static int
lpfc_fdmi_hba_attr_fabric_wwnn(struct lpfc_vport *vport,
struct lpfc_fdmi_attr_def *ad)
{
struct lpfc_fdmi_attr_entry *ae;
uint32_t size;
ae = (struct lpfc_fdmi_attr_entry *)&ad->AttrValue;
memset(ae, 0, sizeof(struct lpfc_name));
memcpy(&ae->un.AttrWWN, &vport->fabric_nodename,
sizeof(struct lpfc_name));
size = FOURBYTES + sizeof(struct lpfc_name);
ad->AttrLen = cpu_to_be16(size);
ad->AttrType = cpu_to_be16(RHBA_FABRIC_WWNN);
return size;
}
static int
lpfc_fdmi_hba_attr_bios_ver(struct lpfc_vport *vport,
struct lpfc_fdmi_attr_def *ad)
{
struct lpfc_hba *phba = vport->phba;
struct lpfc_fdmi_attr_entry *ae;
uint32_t len, size;
ae = (struct lpfc_fdmi_attr_entry *)&ad->AttrValue;
memset(ae, 0, 256);
lpfc_decode_firmware_rev(phba, ae->un.AttrString, 1);
len = strnlen(ae->un.AttrString,
sizeof(ae->un.AttrString));
len += (len & 3) ? (4 - (len & 3)) : 4;
size = FOURBYTES + len;
ad->AttrLen = cpu_to_be16(size);
ad->AttrType = cpu_to_be16(RHBA_BIOS_VERSION);
return size;
}
static int
lpfc_fdmi_hba_attr_bios_state(struct lpfc_vport *vport,
struct lpfc_fdmi_attr_def *ad)
{
struct lpfc_fdmi_attr_entry *ae;
uint32_t size;
ae = (struct lpfc_fdmi_attr_entry *)&ad->AttrValue;
ae->un.AttrInt = cpu_to_be32(0);
size = FOURBYTES + sizeof(uint32_t);
ad->AttrLen = cpu_to_be16(size);
ad->AttrType = cpu_to_be16(RHBA_BIOS_STATE);
return size;
}
static int
lpfc_fdmi_hba_attr_vendor_id(struct lpfc_vport *vport,
struct lpfc_fdmi_attr_def *ad)
{
struct lpfc_fdmi_attr_entry *ae;
uint32_t len, size;
ae = (struct lpfc_fdmi_attr_entry *)&ad->AttrValue;
memset(ae, 0, 256);
strncpy(ae->un.AttrString, "EMULEX",
sizeof(ae->un.AttrString));
len = strnlen(ae->un.AttrString,
sizeof(ae->un.AttrString));
len += (len & 3) ? (4 - (len & 3)) : 4;
size = FOURBYTES + len;
ad->AttrLen = cpu_to_be16(size);
ad->AttrType = cpu_to_be16(RHBA_VENDOR_ID);
return size;
}
static int
lpfc_fdmi_port_attr_fc4type(struct lpfc_vport *vport,
struct lpfc_fdmi_attr_def *ad)
{
struct lpfc_fdmi_attr_entry *ae;
uint32_t size;
ae = (struct lpfc_fdmi_attr_entry *)&ad->AttrValue;
memset(ae, 0, 32);
ae->un.AttrTypes[3] = 0x02;
ae->un.AttrTypes[2] = 0x01;
ae->un.AttrTypes[7] = 0x01;
size = FOURBYTES + 32;
ad->AttrLen = cpu_to_be16(size);
ad->AttrType = cpu_to_be16(RPRT_SUPPORTED_FC4_TYPES);
return size;
}
static int
lpfc_fdmi_port_attr_support_speed(struct lpfc_vport *vport,
struct lpfc_fdmi_attr_def *ad)
{
struct lpfc_hba *phba = vport->phba;
struct lpfc_fdmi_attr_entry *ae;
uint32_t size;
ae = (struct lpfc_fdmi_attr_entry *)&ad->AttrValue;
ae->un.AttrInt = 0;
if (!(phba->hba_flag & HBA_FCOE_MODE)) {
if (phba->lmt & LMT_32Gb)
ae->un.AttrInt |= HBA_PORTSPEED_32GFC;
if (phba->lmt & LMT_16Gb)
ae->un.AttrInt |= HBA_PORTSPEED_16GFC;
if (phba->lmt & LMT_10Gb)
ae->un.AttrInt |= HBA_PORTSPEED_10GFC;
if (phba->lmt & LMT_8Gb)
ae->un.AttrInt |= HBA_PORTSPEED_8GFC;
if (phba->lmt & LMT_4Gb)
ae->un.AttrInt |= HBA_PORTSPEED_4GFC;
if (phba->lmt & LMT_2Gb)
ae->un.AttrInt |= HBA_PORTSPEED_2GFC;
if (phba->lmt & LMT_1Gb)
ae->un.AttrInt |= HBA_PORTSPEED_1GFC;
} else {
switch (phba->fc_linkspeed) {
case LPFC_ASYNC_LINK_SPEED_10GBPS:
ae->un.AttrInt = HBA_PORTSPEED_10GE;
break;
case LPFC_ASYNC_LINK_SPEED_25GBPS:
ae->un.AttrInt = HBA_PORTSPEED_25GE;
break;
case LPFC_ASYNC_LINK_SPEED_40GBPS:
ae->un.AttrInt = HBA_PORTSPEED_40GE;
break;
case LPFC_ASYNC_LINK_SPEED_100GBPS:
ae->un.AttrInt = HBA_PORTSPEED_100GE;
break;
}
}
ae->un.AttrInt = cpu_to_be32(ae->un.AttrInt);
size = FOURBYTES + sizeof(uint32_t);
ad->AttrLen = cpu_to_be16(size);
ad->AttrType = cpu_to_be16(RPRT_SUPPORTED_SPEED);
return size;
}
static int
lpfc_fdmi_port_attr_speed(struct lpfc_vport *vport,
struct lpfc_fdmi_attr_def *ad)
{
struct lpfc_hba *phba = vport->phba;
struct lpfc_fdmi_attr_entry *ae;
uint32_t size;
ae = (struct lpfc_fdmi_attr_entry *)&ad->AttrValue;
if (!(phba->hba_flag & HBA_FCOE_MODE)) {
switch (phba->fc_linkspeed) {
case LPFC_LINK_SPEED_1GHZ:
ae->un.AttrInt = HBA_PORTSPEED_1GFC;
break;
case LPFC_LINK_SPEED_2GHZ:
ae->un.AttrInt = HBA_PORTSPEED_2GFC;
break;
case LPFC_LINK_SPEED_4GHZ:
ae->un.AttrInt = HBA_PORTSPEED_4GFC;
break;
case LPFC_LINK_SPEED_8GHZ:
ae->un.AttrInt = HBA_PORTSPEED_8GFC;
break;
case LPFC_LINK_SPEED_10GHZ:
ae->un.AttrInt = HBA_PORTSPEED_10GFC;
break;
case LPFC_LINK_SPEED_16GHZ:
ae->un.AttrInt = HBA_PORTSPEED_16GFC;
break;
case LPFC_LINK_SPEED_32GHZ:
ae->un.AttrInt = HBA_PORTSPEED_32GFC;
break;
default:
ae->un.AttrInt = HBA_PORTSPEED_UNKNOWN;
break;
}
} else {
switch (phba->fc_linkspeed) {
case LPFC_ASYNC_LINK_SPEED_10GBPS:
ae->un.AttrInt = HBA_PORTSPEED_10GE;
break;
case LPFC_ASYNC_LINK_SPEED_25GBPS:
ae->un.AttrInt = HBA_PORTSPEED_25GE;
break;
case LPFC_ASYNC_LINK_SPEED_40GBPS:
ae->un.AttrInt = HBA_PORTSPEED_40GE;
break;
case LPFC_ASYNC_LINK_SPEED_100GBPS:
ae->un.AttrInt = HBA_PORTSPEED_100GE;
break;
default:
ae->un.AttrInt = HBA_PORTSPEED_UNKNOWN;
break;
}
}
ae->un.AttrInt = cpu_to_be32(ae->un.AttrInt);
size = FOURBYTES + sizeof(uint32_t);
ad->AttrLen = cpu_to_be16(size);
ad->AttrType = cpu_to_be16(RPRT_PORT_SPEED);
return size;
}
static int
lpfc_fdmi_port_attr_max_frame(struct lpfc_vport *vport,
struct lpfc_fdmi_attr_def *ad)
{
struct serv_parm *hsp;
struct lpfc_fdmi_attr_entry *ae;
uint32_t size;
ae = (struct lpfc_fdmi_attr_entry *)&ad->AttrValue;
hsp = (struct serv_parm *)&vport->fc_sparam;
ae->un.AttrInt = (((uint32_t) hsp->cmn.bbRcvSizeMsb) << 8) |
(uint32_t) hsp->cmn.bbRcvSizeLsb;
ae->un.AttrInt = cpu_to_be32(ae->un.AttrInt);
size = FOURBYTES + sizeof(uint32_t);
ad->AttrLen = cpu_to_be16(size);
ad->AttrType = cpu_to_be16(RPRT_MAX_FRAME_SIZE);
return size;
}
static int
lpfc_fdmi_port_attr_os_devname(struct lpfc_vport *vport,
struct lpfc_fdmi_attr_def *ad)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
struct lpfc_fdmi_attr_entry *ae;
uint32_t len, size;
ae = (struct lpfc_fdmi_attr_entry *)&ad->AttrValue;
memset(ae, 0, 256);
snprintf(ae->un.AttrString, sizeof(ae->un.AttrString),
"/sys/class/scsi_host/host%d", shost->host_no);
len = strnlen((char *)ae->un.AttrString,
sizeof(ae->un.AttrString));
len += (len & 3) ? (4 - (len & 3)) : 4;
size = FOURBYTES + len;
ad->AttrLen = cpu_to_be16(size);
ad->AttrType = cpu_to_be16(RPRT_OS_DEVICE_NAME);
return size;
}
static int
lpfc_fdmi_port_attr_host_name(struct lpfc_vport *vport,
struct lpfc_fdmi_attr_def *ad)
{
struct lpfc_fdmi_attr_entry *ae;
uint32_t len, size;
ae = (struct lpfc_fdmi_attr_entry *)&ad->AttrValue;
memset(ae, 0, 256);
snprintf(ae->un.AttrString, sizeof(ae->un.AttrString), "%s",
init_utsname()->nodename);
len = strnlen(ae->un.AttrString, sizeof(ae->un.AttrString));
len += (len & 3) ? (4 - (len & 3)) : 4;
size = FOURBYTES + len;
ad->AttrLen = cpu_to_be16(size);
ad->AttrType = cpu_to_be16(RPRT_HOST_NAME);
return size;
}
static int
lpfc_fdmi_port_attr_wwnn(struct lpfc_vport *vport,
struct lpfc_fdmi_attr_def *ad)
{
struct lpfc_fdmi_attr_entry *ae;
uint32_t size;
ae = (struct lpfc_fdmi_attr_entry *)&ad->AttrValue;
memset(ae, 0, sizeof(struct lpfc_name));
memcpy(&ae->un.AttrWWN, &vport->fc_sparam.nodeName,
sizeof(struct lpfc_name));
size = FOURBYTES + sizeof(struct lpfc_name);
ad->AttrLen = cpu_to_be16(size);
ad->AttrType = cpu_to_be16(RPRT_NODENAME);
return size;
}
static int
lpfc_fdmi_port_attr_wwpn(struct lpfc_vport *vport,
struct lpfc_fdmi_attr_def *ad)
{
struct lpfc_fdmi_attr_entry *ae;
uint32_t size;
ae = (struct lpfc_fdmi_attr_entry *)&ad->AttrValue;
memset(ae, 0, sizeof(struct lpfc_name));
memcpy(&ae->un.AttrWWN, &vport->fc_sparam.portName,
sizeof(struct lpfc_name));
size = FOURBYTES + sizeof(struct lpfc_name);
ad->AttrLen = cpu_to_be16(size);
ad->AttrType = cpu_to_be16(RPRT_PORTNAME);
return size;
}
static int
lpfc_fdmi_port_attr_symbolic_name(struct lpfc_vport *vport,
struct lpfc_fdmi_attr_def *ad)
{
struct lpfc_fdmi_attr_entry *ae;
uint32_t len, size;
ae = (struct lpfc_fdmi_attr_entry *)&ad->AttrValue;
memset(ae, 0, 256);
len = lpfc_vport_symbolic_port_name(vport, ae->un.AttrString, 256);
len += (len & 3) ? (4 - (len & 3)) : 4;
size = FOURBYTES + len;
ad->AttrLen = cpu_to_be16(size);
ad->AttrType = cpu_to_be16(RPRT_SYM_PORTNAME);
return size;
}
static int
lpfc_fdmi_port_attr_port_type(struct lpfc_vport *vport,
struct lpfc_fdmi_attr_def *ad)
{
struct lpfc_hba *phba = vport->phba;
struct lpfc_fdmi_attr_entry *ae;
uint32_t size;
ae = (struct lpfc_fdmi_attr_entry *)&ad->AttrValue;
if (phba->fc_topology == LPFC_TOPOLOGY_LOOP)
ae->un.AttrInt = cpu_to_be32(LPFC_FDMI_PORTTYPE_NLPORT);
else
ae->un.AttrInt = cpu_to_be32(LPFC_FDMI_PORTTYPE_NPORT);
size = FOURBYTES + sizeof(uint32_t);
ad->AttrLen = cpu_to_be16(size);
ad->AttrType = cpu_to_be16(RPRT_PORT_TYPE);
return size;
}
static int
lpfc_fdmi_port_attr_class(struct lpfc_vport *vport,
struct lpfc_fdmi_attr_def *ad)
{
struct lpfc_fdmi_attr_entry *ae;
uint32_t size;
ae = (struct lpfc_fdmi_attr_entry *)&ad->AttrValue;
ae->un.AttrInt = cpu_to_be32(FC_COS_CLASS2 | FC_COS_CLASS3);
size = FOURBYTES + sizeof(uint32_t);
ad->AttrLen = cpu_to_be16(size);
ad->AttrType = cpu_to_be16(RPRT_SUPPORTED_CLASS);
return size;
}
static int
lpfc_fdmi_port_attr_fabric_wwpn(struct lpfc_vport *vport,
struct lpfc_fdmi_attr_def *ad)
{
struct lpfc_fdmi_attr_entry *ae;
uint32_t size;
ae = (struct lpfc_fdmi_attr_entry *)&ad->AttrValue;
memset(ae, 0, sizeof(struct lpfc_name));
memcpy(&ae->un.AttrWWN, &vport->fabric_portname,
sizeof(struct lpfc_name));
size = FOURBYTES + sizeof(struct lpfc_name);
ad->AttrLen = cpu_to_be16(size);
ad->AttrType = cpu_to_be16(RPRT_FABRICNAME);
return size;
}
static int
lpfc_fdmi_port_attr_active_fc4type(struct lpfc_vport *vport,
struct lpfc_fdmi_attr_def *ad)
{
struct lpfc_fdmi_attr_entry *ae;
uint32_t size;
ae = (struct lpfc_fdmi_attr_entry *)&ad->AttrValue;
memset(ae, 0, 32);
ae->un.AttrTypes[3] = 0x02;
ae->un.AttrTypes[2] = 0x01;
ae->un.AttrTypes[7] = 0x01;
size = FOURBYTES + 32;
ad->AttrLen = cpu_to_be16(size);
ad->AttrType = cpu_to_be16(RPRT_ACTIVE_FC4_TYPES);
return size;
}
static int
lpfc_fdmi_port_attr_port_state(struct lpfc_vport *vport,
struct lpfc_fdmi_attr_def *ad)
{
struct lpfc_fdmi_attr_entry *ae;
uint32_t size;
ae = (struct lpfc_fdmi_attr_entry *)&ad->AttrValue;
ae->un.AttrInt = cpu_to_be32(LPFC_FDMI_PORTSTATE_ONLINE);
size = FOURBYTES + sizeof(uint32_t);
ad->AttrLen = cpu_to_be16(size);
ad->AttrType = cpu_to_be16(RPRT_PORT_STATE);
return size;
}
static int
lpfc_fdmi_port_attr_num_disc(struct lpfc_vport *vport,
struct lpfc_fdmi_attr_def *ad)
{
struct lpfc_fdmi_attr_entry *ae;
uint32_t size;
ae = (struct lpfc_fdmi_attr_entry *)&ad->AttrValue;
vport->fdmi_num_disc = lpfc_find_map_node(vport);
ae->un.AttrInt = cpu_to_be32(vport->fdmi_num_disc);
size = FOURBYTES + sizeof(uint32_t);
ad->AttrLen = cpu_to_be16(size);
ad->AttrType = cpu_to_be16(RPRT_DISC_PORT);
return size;
}
static int
lpfc_fdmi_port_attr_nportid(struct lpfc_vport *vport,
struct lpfc_fdmi_attr_def *ad)
{
struct lpfc_fdmi_attr_entry *ae;
uint32_t size;
ae = (struct lpfc_fdmi_attr_entry *)&ad->AttrValue;
ae->un.AttrInt = cpu_to_be32(vport->fc_myDID);
size = FOURBYTES + sizeof(uint32_t);
ad->AttrLen = cpu_to_be16(size);
ad->AttrType = cpu_to_be16(RPRT_PORT_ID);
return size;
}
static int
lpfc_fdmi_smart_attr_service(struct lpfc_vport *vport,
struct lpfc_fdmi_attr_def *ad)
{
struct lpfc_fdmi_attr_entry *ae;
uint32_t len, size;
ae = (struct lpfc_fdmi_attr_entry *)&ad->AttrValue;
memset(ae, 0, 256);
strncpy(ae->un.AttrString, "Smart SAN Initiator",
sizeof(ae->un.AttrString));
len = strnlen(ae->un.AttrString,
sizeof(ae->un.AttrString));
len += (len & 3) ? (4 - (len & 3)) : 4;
size = FOURBYTES + len;
ad->AttrLen = cpu_to_be16(size);
ad->AttrType = cpu_to_be16(RPRT_SMART_SERVICE);
return size;
}
static int
lpfc_fdmi_smart_attr_guid(struct lpfc_vport *vport,
struct lpfc_fdmi_attr_def *ad)
{
struct lpfc_fdmi_attr_entry *ae;
uint32_t size;
ae = (struct lpfc_fdmi_attr_entry *)&ad->AttrValue;
memset(ae, 0, 256);
memcpy(&ae->un.AttrString, &vport->fc_sparam.nodeName,
sizeof(struct lpfc_name));
memcpy((((uint8_t *)&ae->un.AttrString) +
sizeof(struct lpfc_name)),
&vport->fc_sparam.portName, sizeof(struct lpfc_name));
size = FOURBYTES + (2 * sizeof(struct lpfc_name));
ad->AttrLen = cpu_to_be16(size);
ad->AttrType = cpu_to_be16(RPRT_SMART_GUID);
return size;
}
static int
lpfc_fdmi_smart_attr_version(struct lpfc_vport *vport,
struct lpfc_fdmi_attr_def *ad)
{
struct lpfc_fdmi_attr_entry *ae;
uint32_t len, size;
ae = (struct lpfc_fdmi_attr_entry *)&ad->AttrValue;
memset(ae, 0, 256);
strncpy(ae->un.AttrString, "Smart SAN Version 2.0",
sizeof(ae->un.AttrString));
len = strnlen(ae->un.AttrString,
sizeof(ae->un.AttrString));
len += (len & 3) ? (4 - (len & 3)) : 4;
size = FOURBYTES + len;
ad->AttrLen = cpu_to_be16(size);
ad->AttrType = cpu_to_be16(RPRT_SMART_VERSION);
return size;
}
static int
lpfc_fdmi_smart_attr_model(struct lpfc_vport *vport,
struct lpfc_fdmi_attr_def *ad)
{
struct lpfc_hba *phba = vport->phba;
struct lpfc_fdmi_attr_entry *ae;
uint32_t len, size;
ae = (struct lpfc_fdmi_attr_entry *)&ad->AttrValue;
memset(ae, 0, 256);
strncpy(ae->un.AttrString, phba->ModelName,
sizeof(ae->un.AttrString));
len = strnlen(ae->un.AttrString, sizeof(ae->un.AttrString));
len += (len & 3) ? (4 - (len & 3)) : 4;
size = FOURBYTES + len;
ad->AttrLen = cpu_to_be16(size);
ad->AttrType = cpu_to_be16(RPRT_SMART_MODEL);
return size;
}
static int
lpfc_fdmi_smart_attr_port_info(struct lpfc_vport *vport,
struct lpfc_fdmi_attr_def *ad)
{
struct lpfc_fdmi_attr_entry *ae;
uint32_t size;
ae = (struct lpfc_fdmi_attr_entry *)&ad->AttrValue;
if (vport->vpi)
ae->un.AttrInt = cpu_to_be32(2);
else
ae->un.AttrInt = cpu_to_be32(1);
size = FOURBYTES + sizeof(uint32_t);
ad->AttrLen = cpu_to_be16(size);
ad->AttrType = cpu_to_be16(RPRT_SMART_PORT_INFO);
return size;
}
static int
lpfc_fdmi_smart_attr_qos(struct lpfc_vport *vport,
struct lpfc_fdmi_attr_def *ad)
{
struct lpfc_fdmi_attr_entry *ae;
uint32_t size;
ae = (struct lpfc_fdmi_attr_entry *)&ad->AttrValue;
ae->un.AttrInt = cpu_to_be32(0);
size = FOURBYTES + sizeof(uint32_t);
ad->AttrLen = cpu_to_be16(size);
ad->AttrType = cpu_to_be16(RPRT_SMART_QOS);
return size;
}
static int
lpfc_fdmi_smart_attr_security(struct lpfc_vport *vport,
struct lpfc_fdmi_attr_def *ad)
{
struct lpfc_fdmi_attr_entry *ae;
uint32_t size;
ae = (struct lpfc_fdmi_attr_entry *)&ad->AttrValue;
ae->un.AttrInt = cpu_to_be32(1);
size = FOURBYTES + sizeof(uint32_t);
ad->AttrLen = cpu_to_be16(size);
ad->AttrType = cpu_to_be16(RPRT_SMART_SECURITY);
return size;
}
int
lpfc_fdmi_cmd(struct lpfc_vport *vport, struct lpfc_nodelist *ndlp,
int cmdcode, uint32_t new_mask)
{
struct lpfc_hba *phba = vport->phba;
struct lpfc_dmabuf *mp, *bmp;
struct lpfc_sli_ct_request *CtReq;
struct ulp_bde64 *bpl;
uint32_t bit_pos;
uint32_t size;
uint32_t rsp_size;
uint32_t mask;
struct lpfc_fdmi_reg_hba *rh;
struct lpfc_fdmi_port_entry *pe;
struct lpfc_fdmi_reg_portattr *pab = NULL;
struct lpfc_fdmi_attr_block *ab = NULL;
int (*func)(struct lpfc_vport *vport, struct lpfc_fdmi_attr_def *ad);
void (*cmpl)(struct lpfc_hba *, struct lpfc_iocbq *,
struct lpfc_iocbq *);
if (!ndlp || !NLP_CHK_NODE_ACT(ndlp))
return 0;
cmpl = lpfc_cmpl_ct_disc_fdmi;
mp = kmalloc(sizeof(struct lpfc_dmabuf), GFP_KERNEL);
if (!mp)
goto fdmi_cmd_exit;
mp->virt = lpfc_mbuf_alloc(phba, 0, &(mp->phys));
if (!mp->virt)
goto fdmi_cmd_free_mp;
bmp = kmalloc(sizeof(struct lpfc_dmabuf), GFP_KERNEL);
if (!bmp)
goto fdmi_cmd_free_mpvirt;
bmp->virt = lpfc_mbuf_alloc(phba, 0, &(bmp->phys));
if (!bmp->virt)
goto fdmi_cmd_free_bmp;
INIT_LIST_HEAD(&mp->list);
INIT_LIST_HEAD(&bmp->list);
lpfc_printf_vlog(vport, KERN_INFO, LOG_DISCOVERY,
"0218 FDMI Request Data: x%x x%x x%x\n",
vport->fc_flag, vport->port_state, cmdcode);
CtReq = (struct lpfc_sli_ct_request *)mp->virt;
memset(CtReq, 0, sizeof(struct lpfc_sli_ct_request));
CtReq->RevisionId.bits.Revision = SLI_CT_REVISION;
CtReq->RevisionId.bits.InId = 0;
CtReq->FsType = SLI_CT_MANAGEMENT_SERVICE;
CtReq->FsSubType = SLI_CT_FDMI_Subtypes;
CtReq->CommandResponse.bits.CmdRsp = cpu_to_be16(cmdcode);
rsp_size = LPFC_BPL_SIZE;
size = 0;
switch (cmdcode) {
case SLI_MGMT_RHAT:
case SLI_MGMT_RHBA:
rh = (struct lpfc_fdmi_reg_hba *)&CtReq->un.PortID;
memcpy(&rh->hi.PortName, &phba->pport->fc_sparam.portName,
sizeof(struct lpfc_name));
if (cmdcode == SLI_MGMT_RHBA) {
rh->rpl.EntryCnt = cpu_to_be32(1);
memcpy(&rh->rpl.pe, &phba->pport->fc_sparam.portName,
sizeof(struct lpfc_name));
size = 2 * sizeof(struct lpfc_name) +
FOURBYTES;
} else {
size = sizeof(struct lpfc_name);
}
ab = (struct lpfc_fdmi_attr_block *)((uint8_t *)rh + size);
ab->EntryCnt = 0;
size += FOURBYTES;
bit_pos = 0;
if (new_mask)
mask = new_mask;
else
mask = vport->fdmi_hba_mask;
while (mask) {
if (mask & 0x1) {
func = lpfc_fdmi_hba_action[bit_pos];
size += func(vport,
(struct lpfc_fdmi_attr_def *)
((uint8_t *)rh + size));
ab->EntryCnt++;
if ((size + 256) >
(LPFC_BPL_SIZE - LPFC_CT_PREAMBLE))
goto hba_out;
}
mask = mask >> 1;
bit_pos++;
}
hba_out:
ab->EntryCnt = cpu_to_be32(ab->EntryCnt);
size = GID_REQUEST_SZ - 4 + size;
break;
case SLI_MGMT_RPRT:
case SLI_MGMT_RPA:
pab = (struct lpfc_fdmi_reg_portattr *)&CtReq->un.PortID;
if (cmdcode == SLI_MGMT_RPRT) {
rh = (struct lpfc_fdmi_reg_hba *)pab;
memcpy(&rh->hi.PortName,
&phba->pport->fc_sparam.portName,
sizeof(struct lpfc_name));
pab = (struct lpfc_fdmi_reg_portattr *)
((uint8_t *)pab + sizeof(struct lpfc_name));
}
memcpy((uint8_t *)&pab->PortName,
(uint8_t *)&vport->fc_sparam.portName,
sizeof(struct lpfc_name));
size += sizeof(struct lpfc_name) + FOURBYTES;
pab->ab.EntryCnt = 0;
bit_pos = 0;
if (new_mask)
mask = new_mask;
else
mask = vport->fdmi_port_mask;
while (mask) {
if (mask & 0x1) {
func = lpfc_fdmi_port_action[bit_pos];
size += func(vport,
(struct lpfc_fdmi_attr_def *)
((uint8_t *)pab + size));
pab->ab.EntryCnt++;
if ((size + 256) >
(LPFC_BPL_SIZE - LPFC_CT_PREAMBLE))
goto port_out;
}
mask = mask >> 1;
bit_pos++;
}
port_out:
pab->ab.EntryCnt = cpu_to_be32(pab->ab.EntryCnt);
if (cmdcode == SLI_MGMT_RPRT)
size += sizeof(struct lpfc_name);
size = GID_REQUEST_SZ - 4 + size;
break;
case SLI_MGMT_GHAT:
case SLI_MGMT_GRPL:
rsp_size = FC_MAX_NS_RSP;
case SLI_MGMT_DHBA:
case SLI_MGMT_DHAT:
pe = (struct lpfc_fdmi_port_entry *)&CtReq->un.PortID;
memcpy((uint8_t *)&pe->PortName,
(uint8_t *)&vport->fc_sparam.portName,
sizeof(struct lpfc_name));
size = GID_REQUEST_SZ - 4 + sizeof(struct lpfc_name);
break;
case SLI_MGMT_GPAT:
case SLI_MGMT_GPAS:
rsp_size = FC_MAX_NS_RSP;
case SLI_MGMT_DPRT:
case SLI_MGMT_DPA:
pe = (struct lpfc_fdmi_port_entry *)&CtReq->un.PortID;
memcpy((uint8_t *)&pe->PortName,
(uint8_t *)&vport->fc_sparam.portName,
sizeof(struct lpfc_name));
size = GID_REQUEST_SZ - 4 + sizeof(struct lpfc_name);
break;
case SLI_MGMT_GRHL:
size = GID_REQUEST_SZ - 4;
break;
default:
lpfc_printf_vlog(vport, KERN_WARNING, LOG_DISCOVERY,
"0298 FDMI cmdcode x%x not supported\n",
cmdcode);
goto fdmi_cmd_free_bmpvirt;
}
CtReq->CommandResponse.bits.Size = cpu_to_be16(rsp_size);
bpl = (struct ulp_bde64 *)bmp->virt;
bpl->addrHigh = le32_to_cpu(putPaddrHigh(mp->phys));
bpl->addrLow = le32_to_cpu(putPaddrLow(mp->phys));
bpl->tus.f.bdeFlags = 0;
bpl->tus.f.bdeSize = size;
if (!lpfc_ct_cmd(vport, mp, bmp, ndlp, cmpl, rsp_size, 0))
return 0;
lpfc_nlp_put(ndlp);
fdmi_cmd_free_bmpvirt:
lpfc_mbuf_free(phba, bmp->virt, bmp->phys);
fdmi_cmd_free_bmp:
kfree(bmp);
fdmi_cmd_free_mpvirt:
lpfc_mbuf_free(phba, mp->virt, mp->phys);
fdmi_cmd_free_mp:
kfree(mp);
fdmi_cmd_exit:
lpfc_printf_vlog(vport, KERN_INFO, LOG_DISCOVERY,
"0244 Issue FDMI request failed Data: x%x\n",
cmdcode);
return 1;
}
void
lpfc_delayed_disc_tmo(unsigned long ptr)
{
struct lpfc_vport *vport = (struct lpfc_vport *)ptr;
struct lpfc_hba *phba = vport->phba;
uint32_t tmo_posted;
unsigned long iflag;
spin_lock_irqsave(&vport->work_port_lock, iflag);
tmo_posted = vport->work_port_events & WORKER_DELAYED_DISC_TMO;
if (!tmo_posted)
vport->work_port_events |= WORKER_DELAYED_DISC_TMO;
spin_unlock_irqrestore(&vport->work_port_lock, iflag);
if (!tmo_posted)
lpfc_worker_wake_up(phba);
return;
}
void
lpfc_delayed_disc_timeout_handler(struct lpfc_vport *vport)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
spin_lock_irq(shost->host_lock);
if (!(vport->fc_flag & FC_DISC_DELAYED)) {
spin_unlock_irq(shost->host_lock);
return;
}
vport->fc_flag &= ~FC_DISC_DELAYED;
spin_unlock_irq(shost->host_lock);
lpfc_do_scr_ns_plogi(vport->phba, vport);
}
void
lpfc_decode_firmware_rev(struct lpfc_hba *phba, char *fwrevision, int flag)
{
struct lpfc_sli *psli = &phba->sli;
lpfc_vpd_t *vp = &phba->vpd;
uint32_t b1, b2, b3, b4, i, rev;
char c;
uint32_t *ptr, str[4];
uint8_t *fwname;
if (phba->sli_rev == LPFC_SLI_REV4)
snprintf(fwrevision, FW_REV_STR_SIZE, "%s", vp->rev.opFwName);
else if (vp->rev.rBit) {
if (psli->sli_flag & LPFC_SLI_ACTIVE)
rev = vp->rev.sli2FwRev;
else
rev = vp->rev.sli1FwRev;
b1 = (rev & 0x0000f000) >> 12;
b2 = (rev & 0x00000f00) >> 8;
b3 = (rev & 0x000000c0) >> 6;
b4 = (rev & 0x00000030) >> 4;
switch (b4) {
case 0:
c = 'N';
break;
case 1:
c = 'A';
break;
case 2:
c = 'B';
break;
case 3:
c = 'X';
break;
default:
c = 0;
break;
}
b4 = (rev & 0x0000000f);
if (psli->sli_flag & LPFC_SLI_ACTIVE)
fwname = vp->rev.sli2FwName;
else
fwname = vp->rev.sli1FwName;
for (i = 0; i < 16; i++)
if (fwname[i] == 0x20)
fwname[i] = 0;
ptr = (uint32_t*)fwname;
for (i = 0; i < 3; i++)
str[i] = be32_to_cpu(*ptr++);
if (c == 0) {
if (flag)
sprintf(fwrevision, "%d.%d%d (%s)",
b1, b2, b3, (char *)str);
else
sprintf(fwrevision, "%d.%d%d", b1,
b2, b3);
} else {
if (flag)
sprintf(fwrevision, "%d.%d%d%c%d (%s)",
b1, b2, b3, c,
b4, (char *)str);
else
sprintf(fwrevision, "%d.%d%d%c%d",
b1, b2, b3, c, b4);
}
} else {
rev = vp->rev.smFwRev;
b1 = (rev & 0xff000000) >> 24;
b2 = (rev & 0x00f00000) >> 20;
b3 = (rev & 0x000f0000) >> 16;
c = (rev & 0x0000ff00) >> 8;
b4 = (rev & 0x000000ff);
sprintf(fwrevision, "%d.%d%d%c%d", b1, b2, b3, c, b4);
}
return;
}
