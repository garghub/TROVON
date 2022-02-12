static void
lpfc_jedec_to_ascii(int incr, char hdw[])
{
int i, j;
for (i = 0; i < 8; i++) {
j = (incr & 0xf);
if (j <= 9)
hdw[7 - i] = 0x30 + j;
else
hdw[7 - i] = 0x61 + j - 10;
incr = (incr >> 4);
}
hdw[8] = 0;
return;
}
static ssize_t
lpfc_drvr_version_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
return snprintf(buf, PAGE_SIZE, LPFC_MODULE_DESC "\n");
}
static ssize_t
lpfc_enable_fip_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
if (phba->hba_flag & HBA_FIP_SUPPORT)
return snprintf(buf, PAGE_SIZE, "1\n");
else
return snprintf(buf, PAGE_SIZE, "0\n");
}
static ssize_t
lpfc_nvme_info_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = shost_priv(shost);
struct lpfc_hba *phba = vport->phba;
struct lpfc_nvmet_tgtport *tgtp;
struct nvme_fc_local_port *localport;
struct lpfc_nvme_lport *lport;
struct lpfc_nvme_rport *rport;
struct nvme_fc_remote_port *nrport;
char *statep;
int len = 0;
if (!(phba->cfg_enable_fc4_type & LPFC_ENABLE_NVME)) {
len += snprintf(buf, PAGE_SIZE, "NVME Disabled\n");
return len;
}
if (phba->nvmet_support) {
if (!phba->targetport) {
len = snprintf(buf, PAGE_SIZE,
"NVME Target: x%llx is not allocated\n",
wwn_to_u64(vport->fc_portname.u.wwn));
return len;
}
if (phba->targetport->port_id)
statep = "REGISTERED";
else
statep = "INIT";
len += snprintf(buf + len, PAGE_SIZE - len,
"NVME Target: Enabled State %s\n",
statep);
len += snprintf(buf + len, PAGE_SIZE - len,
"%s%d WWPN x%llx WWNN x%llx DID x%06x\n",
"NVME Target: lpfc",
phba->brd_no,
wwn_to_u64(vport->fc_portname.u.wwn),
wwn_to_u64(vport->fc_nodename.u.wwn),
phba->targetport->port_id);
len += snprintf(buf + len, PAGE_SIZE - len,
"\nNVME Target: Statistics\n");
tgtp = (struct lpfc_nvmet_tgtport *)phba->targetport->private;
len += snprintf(buf+len, PAGE_SIZE-len,
"LS: Rcv %08x Drop %08x Abort %08x\n",
atomic_read(&tgtp->rcv_ls_req_in),
atomic_read(&tgtp->rcv_ls_req_drop),
atomic_read(&tgtp->xmt_ls_abort));
if (atomic_read(&tgtp->rcv_ls_req_in) !=
atomic_read(&tgtp->rcv_ls_req_out)) {
len += snprintf(buf+len, PAGE_SIZE-len,
"Rcv LS: in %08x != out %08x\n",
atomic_read(&tgtp->rcv_ls_req_in),
atomic_read(&tgtp->rcv_ls_req_out));
}
len += snprintf(buf+len, PAGE_SIZE-len,
"LS: Xmt %08x Drop %08x Cmpl %08x Err %08x\n",
atomic_read(&tgtp->xmt_ls_rsp),
atomic_read(&tgtp->xmt_ls_drop),
atomic_read(&tgtp->xmt_ls_rsp_cmpl),
atomic_read(&tgtp->xmt_ls_rsp_error));
len += snprintf(buf+len, PAGE_SIZE-len,
"FCP: Rcv %08x Release %08x Drop %08x\n",
atomic_read(&tgtp->rcv_fcp_cmd_in),
atomic_read(&tgtp->xmt_fcp_release),
atomic_read(&tgtp->rcv_fcp_cmd_drop));
if (atomic_read(&tgtp->rcv_fcp_cmd_in) !=
atomic_read(&tgtp->rcv_fcp_cmd_out)) {
len += snprintf(buf+len, PAGE_SIZE-len,
"Rcv FCP: in %08x != out %08x\n",
atomic_read(&tgtp->rcv_fcp_cmd_in),
atomic_read(&tgtp->rcv_fcp_cmd_out));
}
len += snprintf(buf+len, PAGE_SIZE-len,
"FCP Rsp: RD %08x rsp %08x WR %08x rsp %08x "
"drop %08x\n",
atomic_read(&tgtp->xmt_fcp_read),
atomic_read(&tgtp->xmt_fcp_read_rsp),
atomic_read(&tgtp->xmt_fcp_write),
atomic_read(&tgtp->xmt_fcp_rsp),
atomic_read(&tgtp->xmt_fcp_drop));
len += snprintf(buf+len, PAGE_SIZE-len,
"FCP Rsp Cmpl: %08x err %08x drop %08x\n",
atomic_read(&tgtp->xmt_fcp_rsp_cmpl),
atomic_read(&tgtp->xmt_fcp_rsp_error),
atomic_read(&tgtp->xmt_fcp_rsp_drop));
len += snprintf(buf+len, PAGE_SIZE-len,
"ABORT: Xmt %08x Cmpl %08x\n",
atomic_read(&tgtp->xmt_fcp_abort),
atomic_read(&tgtp->xmt_fcp_abort_cmpl));
len += snprintf(buf + len, PAGE_SIZE - len,
"ABORT: Sol %08x Usol %08x Err %08x Cmpl %08x",
atomic_read(&tgtp->xmt_abort_sol),
atomic_read(&tgtp->xmt_abort_unsol),
atomic_read(&tgtp->xmt_abort_rsp),
atomic_read(&tgtp->xmt_abort_rsp_error));
len += snprintf(buf + len, PAGE_SIZE - len,
"IO_CTX: %08x outstanding %08x total %x",
phba->sli4_hba.nvmet_ctx_cnt,
phba->sli4_hba.nvmet_io_wait_cnt,
phba->sli4_hba.nvmet_io_wait_total);
len += snprintf(buf+len, PAGE_SIZE-len, "\n");
return len;
}
localport = vport->localport;
if (!localport) {
len = snprintf(buf, PAGE_SIZE,
"NVME Initiator x%llx is not allocated\n",
wwn_to_u64(vport->fc_portname.u.wwn));
return len;
}
len = snprintf(buf, PAGE_SIZE, "NVME Initiator Enabled\n");
spin_lock_irq(shost->host_lock);
lport = (struct lpfc_nvme_lport *)localport->private;
if (localport->port_id)
statep = "ONLINE";
else
statep = "UNKNOWN ";
len += snprintf(buf + len, PAGE_SIZE - len,
"%s%d WWPN x%llx WWNN x%llx DID x%06x %s\n",
"NVME LPORT lpfc",
phba->brd_no,
wwn_to_u64(vport->fc_portname.u.wwn),
wwn_to_u64(vport->fc_nodename.u.wwn),
localport->port_id, statep);
list_for_each_entry(rport, &lport->rport_list, list) {
nrport = rport->remoteport;
switch (nrport->port_state) {
case FC_OBJSTATE_ONLINE:
statep = "ONLINE";
break;
case FC_OBJSTATE_UNKNOWN:
statep = "UNKNOWN ";
break;
default:
statep = "UNSUPPORTED";
break;
}
len += snprintf(buf + len, PAGE_SIZE - len,
"NVME RPORT ");
if (phba->brd_no >= 10)
len += snprintf(buf + len, PAGE_SIZE - len, " ");
len += snprintf(buf + len, PAGE_SIZE - len, "WWPN x%llx ",
nrport->port_name);
len += snprintf(buf + len, PAGE_SIZE - len, "WWNN x%llx ",
nrport->node_name);
len += snprintf(buf + len, PAGE_SIZE - len, "DID x%06x ",
nrport->port_id);
switch (nrport->port_role) {
case FC_PORT_ROLE_NVME_INITIATOR:
len += snprintf(buf + len, PAGE_SIZE - len,
"INITIATOR ");
break;
case FC_PORT_ROLE_NVME_TARGET:
len += snprintf(buf + len, PAGE_SIZE - len,
"TARGET ");
break;
case FC_PORT_ROLE_NVME_DISCOVERY:
len += snprintf(buf + len, PAGE_SIZE - len,
"DISCOVERY ");
break;
default:
len += snprintf(buf + len, PAGE_SIZE - len,
"UNKNOWN_ROLE x%x",
nrport->port_role);
break;
}
len += snprintf(buf + len, PAGE_SIZE - len, "%s ", statep);
len += snprintf(buf + len, PAGE_SIZE - len, "\n");
}
spin_unlock_irq(shost->host_lock);
len += snprintf(buf + len, PAGE_SIZE - len, "\nNVME Statistics\n");
len += snprintf(buf+len, PAGE_SIZE-len,
"LS: Xmt %016llx Cmpl %016llx\n",
phba->fc4NvmeLsRequests,
phba->fc4NvmeLsCmpls);
len += snprintf(buf+len, PAGE_SIZE-len,
"FCP: Rd %016llx Wr %016llx IO %016llx\n",
phba->fc4NvmeInputRequests,
phba->fc4NvmeOutputRequests,
phba->fc4NvmeControlRequests);
len += snprintf(buf+len, PAGE_SIZE-len,
" Cmpl %016llx\n", phba->fc4NvmeIoCmpls);
return len;
}
static ssize_t
lpfc_bg_info_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
if (phba->cfg_enable_bg)
if (phba->sli3_options & LPFC_SLI3_BG_ENABLED)
return snprintf(buf, PAGE_SIZE, "BlockGuard Enabled\n");
else
return snprintf(buf, PAGE_SIZE,
"BlockGuard Not Supported\n");
else
return snprintf(buf, PAGE_SIZE,
"BlockGuard Disabled\n");
}
static ssize_t
lpfc_bg_guard_err_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
return snprintf(buf, PAGE_SIZE, "%llu\n",
(unsigned long long)phba->bg_guard_err_cnt);
}
static ssize_t
lpfc_bg_apptag_err_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
return snprintf(buf, PAGE_SIZE, "%llu\n",
(unsigned long long)phba->bg_apptag_err_cnt);
}
static ssize_t
lpfc_bg_reftag_err_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
return snprintf(buf, PAGE_SIZE, "%llu\n",
(unsigned long long)phba->bg_reftag_err_cnt);
}
static ssize_t
lpfc_info_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *host = class_to_shost(dev);
return snprintf(buf, PAGE_SIZE, "%s\n",lpfc_info(host));
}
static ssize_t
lpfc_serialnum_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
return snprintf(buf, PAGE_SIZE, "%s\n",phba->SerialNumber);
}
static ssize_t
lpfc_temp_sensor_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
return snprintf(buf, PAGE_SIZE, "%d\n",phba->temp_sensor_support);
}
static ssize_t
lpfc_modeldesc_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
return snprintf(buf, PAGE_SIZE, "%s\n",phba->ModelDesc);
}
static ssize_t
lpfc_modelname_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
return snprintf(buf, PAGE_SIZE, "%s\n",phba->ModelName);
}
static ssize_t
lpfc_programtype_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
return snprintf(buf, PAGE_SIZE, "%s\n",phba->ProgramType);
}
static ssize_t
lpfc_mlomgmt_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *)shost->hostdata;
struct lpfc_hba *phba = vport->phba;
return snprintf(buf, PAGE_SIZE, "%d\n",
(phba->sli.sli_flag & LPFC_MENLO_MAINT));
}
static ssize_t
lpfc_vportnum_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
return snprintf(buf, PAGE_SIZE, "%s\n",phba->Port);
}
static ssize_t
lpfc_fwrev_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
uint32_t if_type;
uint8_t sli_family;
char fwrev[FW_REV_STR_SIZE];
int len;
lpfc_decode_firmware_rev(phba, fwrev, 1);
if_type = phba->sli4_hba.pc_sli4_params.if_type;
sli_family = phba->sli4_hba.pc_sli4_params.sli_family;
if (phba->sli_rev < LPFC_SLI_REV4)
len = snprintf(buf, PAGE_SIZE, "%s, sli-%d\n",
fwrev, phba->sli_rev);
else
len = snprintf(buf, PAGE_SIZE, "%s, sli-%d:%d:%x\n",
fwrev, phba->sli_rev, if_type, sli_family);
return len;
}
static ssize_t
lpfc_hdw_show(struct device *dev, struct device_attribute *attr, char *buf)
{
char hdw[9];
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
lpfc_vpd_t *vp = &phba->vpd;
lpfc_jedec_to_ascii(vp->rev.biuRev, hdw);
return snprintf(buf, PAGE_SIZE, "%s\n", hdw);
}
static ssize_t
lpfc_option_rom_version_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
char fwrev[FW_REV_STR_SIZE];
if (phba->sli_rev < LPFC_SLI_REV4)
return snprintf(buf, PAGE_SIZE, "%s\n", phba->OptionROMVersion);
lpfc_decode_firmware_rev(phba, fwrev, 1);
return snprintf(buf, PAGE_SIZE, "%s\n", fwrev);
}
static ssize_t
lpfc_link_state_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
int len = 0;
switch (phba->link_state) {
case LPFC_LINK_UNKNOWN:
case LPFC_WARM_START:
case LPFC_INIT_START:
case LPFC_INIT_MBX_CMDS:
case LPFC_LINK_DOWN:
case LPFC_HBA_ERROR:
if (phba->hba_flag & LINK_DISABLED)
len += snprintf(buf + len, PAGE_SIZE-len,
"Link Down - User disabled\n");
else
len += snprintf(buf + len, PAGE_SIZE-len,
"Link Down\n");
break;
case LPFC_LINK_UP:
case LPFC_CLEAR_LA:
case LPFC_HBA_READY:
len += snprintf(buf + len, PAGE_SIZE-len, "Link Up - ");
switch (vport->port_state) {
case LPFC_LOCAL_CFG_LINK:
len += snprintf(buf + len, PAGE_SIZE-len,
"Configuring Link\n");
break;
case LPFC_FDISC:
case LPFC_FLOGI:
case LPFC_FABRIC_CFG_LINK:
case LPFC_NS_REG:
case LPFC_NS_QRY:
case LPFC_BUILD_DISC_LIST:
case LPFC_DISC_AUTH:
len += snprintf(buf + len, PAGE_SIZE - len,
"Discovery\n");
break;
case LPFC_VPORT_READY:
len += snprintf(buf + len, PAGE_SIZE - len, "Ready\n");
break;
case LPFC_VPORT_FAILED:
len += snprintf(buf + len, PAGE_SIZE - len, "Failed\n");
break;
case LPFC_VPORT_UNKNOWN:
len += snprintf(buf + len, PAGE_SIZE - len,
"Unknown\n");
break;
}
if (phba->sli.sli_flag & LPFC_MENLO_MAINT)
len += snprintf(buf + len, PAGE_SIZE-len,
" Menlo Maint Mode\n");
else if (phba->fc_topology == LPFC_TOPOLOGY_LOOP) {
if (vport->fc_flag & FC_PUBLIC_LOOP)
len += snprintf(buf + len, PAGE_SIZE-len,
" Public Loop\n");
else
len += snprintf(buf + len, PAGE_SIZE-len,
" Private Loop\n");
} else {
if (vport->fc_flag & FC_FABRIC)
len += snprintf(buf + len, PAGE_SIZE-len,
" Fabric\n");
else
len += snprintf(buf + len, PAGE_SIZE-len,
" Point-2-Point\n");
}
}
return len;
}
static ssize_t
lpfc_sli4_protocol_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
if (phba->sli_rev < LPFC_SLI_REV4)
return snprintf(buf, PAGE_SIZE, "fc\n");
if (phba->sli4_hba.lnk_info.lnk_dv == LPFC_LNK_DAT_VAL) {
if (phba->sli4_hba.lnk_info.lnk_tp == LPFC_LNK_TYPE_GE)
return snprintf(buf, PAGE_SIZE, "fcoe\n");
if (phba->sli4_hba.lnk_info.lnk_tp == LPFC_LNK_TYPE_FC)
return snprintf(buf, PAGE_SIZE, "fc\n");
}
return snprintf(buf, PAGE_SIZE, "unknown\n");
}
static ssize_t
lpfc_oas_supported_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *)shost->hostdata;
struct lpfc_hba *phba = vport->phba;
return snprintf(buf, PAGE_SIZE, "%d\n",
phba->sli4_hba.pc_sli4_params.oas_supported);
}
static ssize_t
lpfc_link_state_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
int status = -EINVAL;
if ((strncmp(buf, "up", sizeof("up") - 1) == 0) &&
(phba->link_state == LPFC_LINK_DOWN))
status = phba->lpfc_hba_init_link(phba, MBX_NOWAIT);
else if ((strncmp(buf, "down", sizeof("down") - 1) == 0) &&
(phba->link_state >= LPFC_LINK_UP))
status = phba->lpfc_hba_down_link(phba, MBX_NOWAIT);
if (status == 0)
return strlen(buf);
else
return status;
}
static ssize_t
lpfc_num_discovered_ports_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
return snprintf(buf, PAGE_SIZE, "%d\n",
vport->fc_map_cnt + vport->fc_unmap_cnt);
}
static int
lpfc_issue_lip(struct Scsi_Host *shost)
{
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
LPFC_MBOXQ_t *pmboxq;
int mbxstatus = MBXERR_ERROR;
if ((vport->fc_flag & FC_OFFLINE_MODE) ||
(phba->sli.sli_flag & LPFC_BLOCK_MGMT_IO))
return -EPERM;
pmboxq = mempool_alloc(phba->mbox_mem_pool,GFP_KERNEL);
if (!pmboxq)
return -ENOMEM;
memset((void *)pmboxq, 0, sizeof (LPFC_MBOXQ_t));
pmboxq->u.mb.mbxCommand = MBX_DOWN_LINK;
pmboxq->u.mb.mbxOwner = OWN_HOST;
mbxstatus = lpfc_sli_issue_mbox_wait(phba, pmboxq, LPFC_MBOX_TMO * 2);
if ((mbxstatus == MBX_SUCCESS) &&
(pmboxq->u.mb.mbxStatus == 0 ||
pmboxq->u.mb.mbxStatus == MBXERR_LINK_DOWN)) {
memset((void *)pmboxq, 0, sizeof (LPFC_MBOXQ_t));
lpfc_init_link(phba, pmboxq, phba->cfg_topology,
phba->cfg_link_speed);
mbxstatus = lpfc_sli_issue_mbox_wait(phba, pmboxq,
phba->fc_ratov * 2);
if ((mbxstatus == MBX_SUCCESS) &&
(pmboxq->u.mb.mbxStatus == MBXERR_SEC_NO_PERMISSION))
lpfc_printf_log(phba, KERN_ERR, LOG_MBOX | LOG_SLI,
"2859 SLI authentication is required "
"for INIT_LINK but has not done yet\n");
}
lpfc_set_loopback_flag(phba);
if (mbxstatus != MBX_TIMEOUT)
mempool_free(pmboxq, phba->mbox_mem_pool);
if (mbxstatus == MBXERR_ERROR)
return -EIO;
return 0;
}
int
lpfc_emptyq_wait(struct lpfc_hba *phba, struct list_head *q, spinlock_t *lock)
{
int cnt = 0;
spin_lock_irq(lock);
while (!list_empty(q)) {
spin_unlock_irq(lock);
msleep(20);
if (cnt++ > 250) {
lpfc_printf_log(phba, KERN_WARNING, LOG_INIT,
"0466 %s %s\n",
"Outstanding IO when ",
"bringing Adapter offline\n");
return 0;
}
spin_lock_irq(lock);
}
spin_unlock_irq(lock);
return 1;
}
static int
lpfc_do_offline(struct lpfc_hba *phba, uint32_t type)
{
struct completion online_compl;
struct lpfc_queue *qp = NULL;
struct lpfc_sli_ring *pring;
struct lpfc_sli *psli;
int status = 0;
int i;
int rc;
init_completion(&online_compl);
rc = lpfc_workq_post_event(phba, &status, &online_compl,
LPFC_EVT_OFFLINE_PREP);
if (rc == 0)
return -ENOMEM;
wait_for_completion(&online_compl);
if (status != 0)
return -EIO;
psli = &phba->sli;
if (phba->sli_rev != LPFC_SLI_REV4) {
for (i = 0; i < psli->num_rings; i++) {
pring = &psli->sli3_ring[i];
if (!lpfc_emptyq_wait(phba, &pring->txcmplq,
&phba->hbalock))
goto out;
}
} else {
list_for_each_entry(qp, &phba->sli4_hba.lpfc_wq_list, wq_list) {
pring = qp->pring;
if (!pring)
continue;
if (!lpfc_emptyq_wait(phba, &pring->txcmplq,
&pring->ring_lock))
goto out;
}
}
out:
init_completion(&online_compl);
rc = lpfc_workq_post_event(phba, &status, &online_compl, type);
if (rc == 0)
return -ENOMEM;
wait_for_completion(&online_compl);
if (status != 0)
return -EIO;
return 0;
}
int
lpfc_selective_reset(struct lpfc_hba *phba)
{
struct completion online_compl;
int status = 0;
int rc;
if (!phba->cfg_enable_hba_reset)
return -EACCES;
if (!(phba->pport->fc_flag & FC_OFFLINE_MODE)) {
status = lpfc_do_offline(phba, LPFC_EVT_OFFLINE);
if (status != 0)
return status;
}
init_completion(&online_compl);
rc = lpfc_workq_post_event(phba, &status, &online_compl,
LPFC_EVT_ONLINE);
if (rc == 0)
return -ENOMEM;
wait_for_completion(&online_compl);
if (status != 0)
return -EIO;
return 0;
}
static ssize_t
lpfc_issue_reset(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
int status = -EINVAL;
if (!phba->cfg_enable_hba_reset)
return -EACCES;
if (strncmp(buf, "selective", sizeof("selective") - 1) == 0)
status = phba->lpfc_selective_reset(phba);
if (status == 0)
return strlen(buf);
else
return status;
}
int
lpfc_sli4_pdev_status_reg_wait(struct lpfc_hba *phba)
{
struct lpfc_register portstat_reg = {0};
int i;
msleep(100);
lpfc_readl(phba->sli4_hba.u.if_type2.STATUSregaddr,
&portstat_reg.word0);
if (!bf_get(lpfc_sliport_status_rn, &portstat_reg) &&
!bf_get(lpfc_sliport_status_err, &portstat_reg))
return -EPERM;
for (i = 0; i < LPFC_FW_RESET_MAXIMUM_WAIT_10MS_CNT; i++) {
msleep(10);
lpfc_readl(phba->sli4_hba.u.if_type2.STATUSregaddr,
&portstat_reg.word0);
if (!bf_get(lpfc_sliport_status_err, &portstat_reg))
continue;
if (!bf_get(lpfc_sliport_status_rn, &portstat_reg))
continue;
if (!bf_get(lpfc_sliport_status_rdy, &portstat_reg))
continue;
break;
}
if (i < LPFC_FW_RESET_MAXIMUM_WAIT_10MS_CNT)
return 0;
else
return -EIO;
}
static ssize_t
lpfc_sli4_pdev_reg_request(struct lpfc_hba *phba, uint32_t opcode)
{
struct completion online_compl;
struct pci_dev *pdev = phba->pcidev;
uint32_t before_fc_flag;
uint32_t sriov_nr_virtfn;
uint32_t reg_val;
int status = 0, rc = 0;
int job_posted = 1, sriov_err;
if (!phba->cfg_enable_hba_reset)
return -EACCES;
if ((phba->sli_rev < LPFC_SLI_REV4) ||
(bf_get(lpfc_sli_intf_if_type, &phba->sli4_hba.sli_intf) !=
LPFC_SLI_INTF_IF_TYPE_2))
return -EPERM;
before_fc_flag = phba->pport->fc_flag;
sriov_nr_virtfn = phba->cfg_sriov_nr_virtfn;
if (phba->cfg_sriov_nr_virtfn) {
pci_disable_sriov(pdev);
phba->cfg_sriov_nr_virtfn = 0;
}
if (opcode == LPFC_FW_DUMP)
phba->hba_flag |= HBA_FW_DUMP_OP;
status = lpfc_do_offline(phba, LPFC_EVT_OFFLINE);
if (status != 0) {
phba->hba_flag &= ~HBA_FW_DUMP_OP;
return status;
}
msleep(100);
reg_val = readl(phba->sli4_hba.conf_regs_memmap_p +
LPFC_CTL_PDEV_CTL_OFFSET);
if (opcode == LPFC_FW_DUMP)
reg_val |= LPFC_FW_DUMP_REQUEST;
else if (opcode == LPFC_FW_RESET)
reg_val |= LPFC_CTL_PDEV_CTL_FRST;
else if (opcode == LPFC_DV_RESET)
reg_val |= LPFC_CTL_PDEV_CTL_DRST;
writel(reg_val, phba->sli4_hba.conf_regs_memmap_p +
LPFC_CTL_PDEV_CTL_OFFSET);
readl(phba->sli4_hba.conf_regs_memmap_p + LPFC_CTL_PDEV_CTL_OFFSET);
rc = lpfc_sli4_pdev_status_reg_wait(phba);
if (rc == -EPERM) {
lpfc_printf_log(phba, KERN_ERR, LOG_SLI,
"3150 No privilege to perform the requested "
"access: x%x\n", reg_val);
} else if (rc == -EIO) {
lpfc_printf_log(phba, KERN_ERR, LOG_SLI,
"3153 Fail to perform the requested "
"access: x%x\n", reg_val);
return rc;
}
if (before_fc_flag & FC_OFFLINE_MODE)
goto out;
init_completion(&online_compl);
job_posted = lpfc_workq_post_event(phba, &status, &online_compl,
LPFC_EVT_ONLINE);
if (!job_posted)
goto out;
wait_for_completion(&online_compl);
out:
if (sriov_nr_virtfn) {
sriov_err =
lpfc_sli_probe_sriov_nr_virtfn(phba, sriov_nr_virtfn);
if (!sriov_err)
phba->cfg_sriov_nr_virtfn = sriov_nr_virtfn;
}
if (!rc) {
if (!job_posted)
rc = -ENOMEM;
else if (status)
rc = -EIO;
}
return rc;
}
static ssize_t
lpfc_nport_evt_cnt_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
return snprintf(buf, PAGE_SIZE, "%d\n", phba->nport_event_cnt);
}
static ssize_t
lpfc_board_mode_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
char * state;
if (phba->link_state == LPFC_HBA_ERROR)
state = "error";
else if (phba->link_state == LPFC_WARM_START)
state = "warm start";
else if (phba->link_state == LPFC_INIT_START)
state = "offline";
else
state = "online";
return snprintf(buf, PAGE_SIZE, "%s\n", state);
}
static ssize_t
lpfc_board_mode_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
struct completion online_compl;
char *board_mode_str = NULL;
int status = 0;
int rc;
if (!phba->cfg_enable_hba_reset) {
status = -EACCES;
goto board_mode_out;
}
lpfc_printf_vlog(vport, KERN_ERR, LOG_INIT,
"3050 lpfc_board_mode set to %s\n", buf);
init_completion(&online_compl);
if(strncmp(buf, "online", sizeof("online") - 1) == 0) {
rc = lpfc_workq_post_event(phba, &status, &online_compl,
LPFC_EVT_ONLINE);
if (rc == 0) {
status = -ENOMEM;
goto board_mode_out;
}
wait_for_completion(&online_compl);
} else if (strncmp(buf, "offline", sizeof("offline") - 1) == 0)
status = lpfc_do_offline(phba, LPFC_EVT_OFFLINE);
else if (strncmp(buf, "warm", sizeof("warm") - 1) == 0)
if (phba->sli_rev == LPFC_SLI_REV4)
status = -EINVAL;
else
status = lpfc_do_offline(phba, LPFC_EVT_WARM_START);
else if (strncmp(buf, "error", sizeof("error") - 1) == 0)
if (phba->sli_rev == LPFC_SLI_REV4)
status = -EINVAL;
else
status = lpfc_do_offline(phba, LPFC_EVT_KILL);
else if (strncmp(buf, "dump", sizeof("dump") - 1) == 0)
status = lpfc_sli4_pdev_reg_request(phba, LPFC_FW_DUMP);
else if (strncmp(buf, "fw_reset", sizeof("fw_reset") - 1) == 0)
status = lpfc_sli4_pdev_reg_request(phba, LPFC_FW_RESET);
else if (strncmp(buf, "dv_reset", sizeof("dv_reset") - 1) == 0)
status = lpfc_sli4_pdev_reg_request(phba, LPFC_DV_RESET);
else
status = -EINVAL;
board_mode_out:
if (!status)
return strlen(buf);
else {
board_mode_str = strchr(buf, '\n');
if (board_mode_str)
*board_mode_str = '\0';
lpfc_printf_vlog(vport, KERN_ERR, LOG_INIT,
"3097 Failed \"%s\", status(%d), "
"fc_flag(x%x)\n",
buf, status, phba->pport->fc_flag);
return status;
}
}
static int
lpfc_get_hba_info(struct lpfc_hba *phba,
uint32_t *mxri, uint32_t *axri,
uint32_t *mrpi, uint32_t *arpi,
uint32_t *mvpi, uint32_t *avpi)
{
struct lpfc_mbx_read_config *rd_config;
LPFC_MBOXQ_t *pmboxq;
MAILBOX_t *pmb;
int rc = 0;
uint32_t max_vpi;
if (phba->link_state < LPFC_LINK_DOWN ||
!phba->mbox_mem_pool ||
(phba->sli.sli_flag & LPFC_SLI_ACTIVE) == 0)
return 0;
if (phba->sli.sli_flag & LPFC_BLOCK_MGMT_IO)
return 0;
pmboxq = mempool_alloc(phba->mbox_mem_pool, GFP_KERNEL);
if (!pmboxq)
return 0;
memset(pmboxq, 0, sizeof (LPFC_MBOXQ_t));
pmb = &pmboxq->u.mb;
pmb->mbxCommand = MBX_READ_CONFIG;
pmb->mbxOwner = OWN_HOST;
pmboxq->context1 = NULL;
if (phba->pport->fc_flag & FC_OFFLINE_MODE)
rc = MBX_NOT_FINISHED;
else
rc = lpfc_sli_issue_mbox_wait(phba, pmboxq, phba->fc_ratov * 2);
if (rc != MBX_SUCCESS) {
if (rc != MBX_TIMEOUT)
mempool_free(pmboxq, phba->mbox_mem_pool);
return 0;
}
if (phba->sli_rev == LPFC_SLI_REV4) {
rd_config = &pmboxq->u.mqe.un.rd_config;
if (mrpi)
*mrpi = bf_get(lpfc_mbx_rd_conf_rpi_count, rd_config);
if (arpi)
*arpi = bf_get(lpfc_mbx_rd_conf_rpi_count, rd_config) -
phba->sli4_hba.max_cfg_param.rpi_used;
if (mxri)
*mxri = bf_get(lpfc_mbx_rd_conf_xri_count, rd_config);
if (axri)
*axri = bf_get(lpfc_mbx_rd_conf_xri_count, rd_config) -
phba->sli4_hba.max_cfg_param.xri_used;
max_vpi = (bf_get(lpfc_mbx_rd_conf_vpi_count, rd_config) > 0) ?
(bf_get(lpfc_mbx_rd_conf_vpi_count, rd_config) - 1) : 0;
if (mvpi)
*mvpi = max_vpi;
if (avpi)
*avpi = max_vpi - phba->sli4_hba.max_cfg_param.vpi_used;
} else {
if (mrpi)
*mrpi = pmb->un.varRdConfig.max_rpi;
if (arpi)
*arpi = pmb->un.varRdConfig.avail_rpi;
if (mxri)
*mxri = pmb->un.varRdConfig.max_xri;
if (axri)
*axri = pmb->un.varRdConfig.avail_xri;
if (mvpi)
*mvpi = pmb->un.varRdConfig.max_vpi;
if (avpi)
*avpi = pmb->un.varRdConfig.avail_vpi;
}
mempool_free(pmboxq, phba->mbox_mem_pool);
return 1;
}
static ssize_t
lpfc_max_rpi_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
uint32_t cnt;
if (lpfc_get_hba_info(phba, NULL, NULL, &cnt, NULL, NULL, NULL))
return snprintf(buf, PAGE_SIZE, "%d\n", cnt);
return snprintf(buf, PAGE_SIZE, "Unknown\n");
}
static ssize_t
lpfc_used_rpi_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
uint32_t cnt, acnt;
if (lpfc_get_hba_info(phba, NULL, NULL, &cnt, &acnt, NULL, NULL))
return snprintf(buf, PAGE_SIZE, "%d\n", (cnt - acnt));
return snprintf(buf, PAGE_SIZE, "Unknown\n");
}
static ssize_t
lpfc_max_xri_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
uint32_t cnt;
if (lpfc_get_hba_info(phba, &cnt, NULL, NULL, NULL, NULL, NULL))
return snprintf(buf, PAGE_SIZE, "%d\n", cnt);
return snprintf(buf, PAGE_SIZE, "Unknown\n");
}
static ssize_t
lpfc_used_xri_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
uint32_t cnt, acnt;
if (lpfc_get_hba_info(phba, &cnt, &acnt, NULL, NULL, NULL, NULL))
return snprintf(buf, PAGE_SIZE, "%d\n", (cnt - acnt));
return snprintf(buf, PAGE_SIZE, "Unknown\n");
}
static ssize_t
lpfc_max_vpi_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
uint32_t cnt;
if (lpfc_get_hba_info(phba, NULL, NULL, NULL, NULL, &cnt, NULL))
return snprintf(buf, PAGE_SIZE, "%d\n", cnt);
return snprintf(buf, PAGE_SIZE, "Unknown\n");
}
static ssize_t
lpfc_used_vpi_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
uint32_t cnt, acnt;
if (lpfc_get_hba_info(phba, NULL, NULL, NULL, NULL, &cnt, &acnt))
return snprintf(buf, PAGE_SIZE, "%d\n", (cnt - acnt));
return snprintf(buf, PAGE_SIZE, "Unknown\n");
}
static ssize_t
lpfc_npiv_info_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
if (!(phba->max_vpi))
return snprintf(buf, PAGE_SIZE, "NPIV Not Supported\n");
if (vport->port_type == LPFC_PHYSICAL_PORT)
return snprintf(buf, PAGE_SIZE, "NPIV Physical\n");
return snprintf(buf, PAGE_SIZE, "NPIV Virtual (VPI %d)\n", vport->vpi);
}
static ssize_t
lpfc_poll_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
return snprintf(buf, PAGE_SIZE, "%#x\n", phba->cfg_poll);
}
static ssize_t
lpfc_poll_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
uint32_t creg_val;
uint32_t old_val;
int val=0;
if (!isdigit(buf[0]))
return -EINVAL;
if (sscanf(buf, "%i", &val) != 1)
return -EINVAL;
if ((val & 0x3) != val)
return -EINVAL;
if (phba->sli_rev == LPFC_SLI_REV4)
val = 0;
lpfc_printf_vlog(vport, KERN_ERR, LOG_INIT,
"3051 lpfc_poll changed from %d to %d\n",
phba->cfg_poll, val);
spin_lock_irq(&phba->hbalock);
old_val = phba->cfg_poll;
if (val & ENABLE_FCP_RING_POLLING) {
if ((val & DISABLE_FCP_RING_INT) &&
!(old_val & DISABLE_FCP_RING_INT)) {
if (lpfc_readl(phba->HCregaddr, &creg_val)) {
spin_unlock_irq(&phba->hbalock);
return -EINVAL;
}
creg_val &= ~(HC_R0INT_ENA << LPFC_FCP_RING);
writel(creg_val, phba->HCregaddr);
readl(phba->HCregaddr);
lpfc_poll_start_timer(phba);
}
} else if (val != 0x0) {
spin_unlock_irq(&phba->hbalock);
return -EINVAL;
}
if (!(val & DISABLE_FCP_RING_INT) &&
(old_val & DISABLE_FCP_RING_INT))
{
spin_unlock_irq(&phba->hbalock);
del_timer(&phba->fcp_poll_timer);
spin_lock_irq(&phba->hbalock);
if (lpfc_readl(phba->HCregaddr, &creg_val)) {
spin_unlock_irq(&phba->hbalock);
return -EINVAL;
}
creg_val |= (HC_R0INT_ENA << LPFC_FCP_RING);
writel(creg_val, phba->HCregaddr);
readl(phba->HCregaddr);
}
phba->cfg_poll = val;
spin_unlock_irq(&phba->hbalock);
return strlen(buf);
}
static ssize_t
lpfc_fips_level_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
return snprintf(buf, PAGE_SIZE, "%d\n", phba->fips_level);
}
static ssize_t
lpfc_fips_rev_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
return snprintf(buf, PAGE_SIZE, "%d\n", phba->fips_spec_rev);
}
static ssize_t
lpfc_dss_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
return snprintf(buf, PAGE_SIZE, "%s - %sOperational\n",
(phba->cfg_enable_dss) ? "Enabled" : "Disabled",
(phba->sli3_options & LPFC_SLI3_DSS_ENABLED) ?
"" : "Not ");
}
static ssize_t
lpfc_sriov_hw_max_virtfn_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
uint16_t max_nr_virtfn;
max_nr_virtfn = lpfc_sli_sriov_nr_virtfn_get(phba);
return snprintf(buf, PAGE_SIZE, "%d\n", max_nr_virtfn);
}
static inline bool lpfc_rangecheck(uint val, uint min, uint max)
{
return val >= min && val <= max;
}
static size_t
lpfc_wwn_set(const char *buf, size_t cnt, char wwn[])
{
unsigned int i, j;
if (buf[cnt-1] == '\n')
cnt--;
if ((cnt < 16) || (cnt > 18) || ((cnt == 17) && (*buf++ != 'x')) ||
((cnt == 18) && ((*buf++ != '0') || (*buf++ != 'x'))))
return -EINVAL;
memset(wwn, 0, WWN_SZ);
for (i = 0, j = 0; i < 16; i++) {
if ((*buf >= 'a') && (*buf <= 'f'))
j = ((j << 4) | ((*buf++ - 'a') + 10));
else if ((*buf >= 'A') && (*buf <= 'F'))
j = ((j << 4) | ((*buf++ - 'A') + 10));
else if ((*buf >= '0') && (*buf <= '9'))
j = ((j << 4) | (*buf++ - '0'));
else
return -EINVAL;
if (i % 2) {
wwn[i/2] = j & 0xff;
j = 0;
}
}
return 0;
}
static ssize_t
lpfc_soft_wwn_enable_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
unsigned int cnt = count;
uint8_t vvvl = vport->fc_sparam.cmn.valid_vendor_ver_level;
u32 *fawwpn_key = (uint32_t *)&vport->fc_sparam.un.vendorVersion[0];
if (vvvl == 1 && cpu_to_be32(*fawwpn_key) == FAPWWN_KEY_VENDOR) {
lpfc_printf_log(phba, KERN_ERR, LOG_INIT,
"0051 "LPFC_DRIVER_NAME" soft wwpn can not"
" be enabled: fawwpn is enabled\n");
return -EINVAL;
}
if (buf[cnt-1] == '\n')
cnt--;
if ((cnt != strlen(lpfc_soft_wwn_key)) ||
(strncmp(buf, lpfc_soft_wwn_key, strlen(lpfc_soft_wwn_key)) != 0))
return -EINVAL;
phba->soft_wwn_enable = 1;
dev_printk(KERN_WARNING, &phba->pcidev->dev,
"lpfc%d: soft_wwpn assignment has been enabled.\n",
phba->brd_no);
dev_printk(KERN_WARNING, &phba->pcidev->dev,
" The soft_wwpn feature is not supported by Broadcom.");
return count;
}
static ssize_t
lpfc_soft_wwpn_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
return snprintf(buf, PAGE_SIZE, "0x%llx\n",
(unsigned long long)phba->cfg_soft_wwpn);
}
static ssize_t
lpfc_soft_wwpn_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
struct completion online_compl;
int stat1 = 0, stat2 = 0;
unsigned int cnt = count;
u8 wwpn[WWN_SZ];
int rc;
if (!phba->cfg_enable_hba_reset)
return -EACCES;
spin_lock_irq(&phba->hbalock);
if (phba->over_temp_state == HBA_OVER_TEMP) {
spin_unlock_irq(&phba->hbalock);
return -EACCES;
}
spin_unlock_irq(&phba->hbalock);
if (buf[cnt-1] == '\n')
cnt--;
if (!phba->soft_wwn_enable)
return -EINVAL;
phba->soft_wwn_enable = 0;
rc = lpfc_wwn_set(buf, cnt, wwpn);
if (rc) {
phba->soft_wwn_enable = 1;
return rc;
}
phba->cfg_soft_wwpn = wwn_to_u64(wwpn);
fc_host_port_name(shost) = phba->cfg_soft_wwpn;
if (phba->cfg_soft_wwnn)
fc_host_node_name(shost) = phba->cfg_soft_wwnn;
dev_printk(KERN_NOTICE, &phba->pcidev->dev,
"lpfc%d: Reinitializing to use soft_wwpn\n", phba->brd_no);
stat1 = lpfc_do_offline(phba, LPFC_EVT_OFFLINE);
if (stat1)
lpfc_printf_log(phba, KERN_ERR, LOG_INIT,
"0463 lpfc_soft_wwpn attribute set failed to "
"reinit adapter - %d\n", stat1);
init_completion(&online_compl);
rc = lpfc_workq_post_event(phba, &stat2, &online_compl,
LPFC_EVT_ONLINE);
if (rc == 0)
return -ENOMEM;
wait_for_completion(&online_compl);
if (stat2)
lpfc_printf_log(phba, KERN_ERR, LOG_INIT,
"0464 lpfc_soft_wwpn attribute set failed to "
"reinit adapter - %d\n", stat2);
return (stat1 || stat2) ? -EIO : count;
}
static ssize_t
lpfc_soft_wwnn_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_hba *phba = ((struct lpfc_vport *)shost->hostdata)->phba;
return snprintf(buf, PAGE_SIZE, "0x%llx\n",
(unsigned long long)phba->cfg_soft_wwnn);
}
static ssize_t
lpfc_soft_wwnn_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_hba *phba = ((struct lpfc_vport *)shost->hostdata)->phba;
unsigned int cnt = count;
u8 wwnn[WWN_SZ];
int rc;
if (buf[cnt-1] == '\n')
cnt--;
if (!phba->soft_wwn_enable)
return -EINVAL;
rc = lpfc_wwn_set(buf, cnt, wwnn);
if (rc) {
return rc;
}
phba->cfg_soft_wwnn = wwn_to_u64(wwnn);
dev_printk(KERN_NOTICE, &phba->pcidev->dev,
"lpfc%d: soft_wwnn set. Value will take effect upon "
"setting of the soft_wwpn\n", phba->brd_no);
return count;
}
static ssize_t
lpfc_oas_tgt_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_hba *phba = ((struct lpfc_vport *)shost->hostdata)->phba;
return snprintf(buf, PAGE_SIZE, "0x%llx\n",
wwn_to_u64(phba->cfg_oas_tgt_wwpn));
}
static ssize_t
lpfc_oas_tgt_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_hba *phba = ((struct lpfc_vport *)shost->hostdata)->phba;
unsigned int cnt = count;
uint8_t wwpn[WWN_SZ];
int rc;
if (!phba->cfg_fof)
return -EPERM;
if (buf[cnt-1] == '\n')
cnt--;
rc = lpfc_wwn_set(buf, cnt, wwpn);
if (rc)
return rc;
memcpy(phba->cfg_oas_tgt_wwpn, wwpn, (8 * sizeof(uint8_t)));
memcpy(phba->sli4_hba.oas_next_tgt_wwpn, wwpn, (8 * sizeof(uint8_t)));
if (wwn_to_u64(wwpn) == 0)
phba->cfg_oas_flags |= OAS_FIND_ANY_TARGET;
else
phba->cfg_oas_flags &= ~OAS_FIND_ANY_TARGET;
phba->cfg_oas_flags &= ~OAS_LUN_VALID;
phba->sli4_hba.oas_next_lun = FIND_FIRST_OAS_LUN;
return count;
}
static ssize_t
lpfc_oas_priority_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_hba *phba = ((struct lpfc_vport *)shost->hostdata)->phba;
return snprintf(buf, PAGE_SIZE, "%d\n", phba->cfg_oas_priority);
}
static ssize_t
lpfc_oas_priority_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_hba *phba = ((struct lpfc_vport *)shost->hostdata)->phba;
unsigned int cnt = count;
unsigned long val;
int ret;
if (!phba->cfg_fof)
return -EPERM;
if (buf[cnt-1] == '\n')
cnt--;
ret = kstrtoul(buf, 0, &val);
if (ret || (val > 0x7f))
return -EINVAL;
if (val)
phba->cfg_oas_priority = (uint8_t)val;
else
phba->cfg_oas_priority = phba->cfg_XLanePriority;
return count;
}
static ssize_t
lpfc_oas_vpt_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_hba *phba = ((struct lpfc_vport *)shost->hostdata)->phba;
return snprintf(buf, PAGE_SIZE, "0x%llx\n",
wwn_to_u64(phba->cfg_oas_vpt_wwpn));
}
static ssize_t
lpfc_oas_vpt_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_hba *phba = ((struct lpfc_vport *)shost->hostdata)->phba;
unsigned int cnt = count;
uint8_t wwpn[WWN_SZ];
int rc;
if (!phba->cfg_fof)
return -EPERM;
if (buf[cnt-1] == '\n')
cnt--;
rc = lpfc_wwn_set(buf, cnt, wwpn);
if (rc)
return rc;
memcpy(phba->cfg_oas_vpt_wwpn, wwpn, (8 * sizeof(uint8_t)));
memcpy(phba->sli4_hba.oas_next_vpt_wwpn, wwpn, (8 * sizeof(uint8_t)));
if (wwn_to_u64(wwpn) == 0)
phba->cfg_oas_flags |= OAS_FIND_ANY_VPORT;
else
phba->cfg_oas_flags &= ~OAS_FIND_ANY_VPORT;
phba->cfg_oas_flags &= ~OAS_LUN_VALID;
if (phba->cfg_oas_priority == 0)
phba->cfg_oas_priority = phba->cfg_XLanePriority;
phba->sli4_hba.oas_next_lun = FIND_FIRST_OAS_LUN;
return count;
}
static ssize_t
lpfc_oas_lun_state_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_hba *phba = ((struct lpfc_vport *)shost->hostdata)->phba;
return snprintf(buf, PAGE_SIZE, "%d\n", phba->cfg_oas_lun_state);
}
static ssize_t
lpfc_oas_lun_state_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_hba *phba = ((struct lpfc_vport *)shost->hostdata)->phba;
int val = 0;
if (!phba->cfg_fof)
return -EPERM;
if (!isdigit(buf[0]))
return -EINVAL;
if (sscanf(buf, "%i", &val) != 1)
return -EINVAL;
if ((val != 0) && (val != 1))
return -EINVAL;
phba->cfg_oas_lun_state = val;
return strlen(buf);
}
static ssize_t
lpfc_oas_lun_status_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_hba *phba = ((struct lpfc_vport *)shost->hostdata)->phba;
if (!(phba->cfg_oas_flags & OAS_LUN_VALID))
return -EFAULT;
return snprintf(buf, PAGE_SIZE, "%d\n", phba->cfg_oas_lun_status);
}
static size_t
lpfc_oas_lun_state_set(struct lpfc_hba *phba, uint8_t vpt_wwpn[],
uint8_t tgt_wwpn[], uint64_t lun,
uint32_t oas_state, uint8_t pri)
{
int rc = 0;
if (!phba->cfg_fof)
return -EPERM;
if (oas_state) {
if (!lpfc_enable_oas_lun(phba, (struct lpfc_name *)vpt_wwpn,
(struct lpfc_name *)tgt_wwpn,
lun, pri))
rc = -ENOMEM;
} else {
lpfc_disable_oas_lun(phba, (struct lpfc_name *)vpt_wwpn,
(struct lpfc_name *)tgt_wwpn, lun, pri);
}
return rc;
}
static uint64_t
lpfc_oas_lun_get_next(struct lpfc_hba *phba, uint8_t vpt_wwpn[],
uint8_t tgt_wwpn[], uint32_t *lun_status,
uint32_t *lun_pri)
{
uint64_t found_lun;
if (unlikely(!phba) || !vpt_wwpn || !tgt_wwpn)
return NOT_OAS_ENABLED_LUN;
if (lpfc_find_next_oas_lun(phba, (struct lpfc_name *)
phba->sli4_hba.oas_next_vpt_wwpn,
(struct lpfc_name *)
phba->sli4_hba.oas_next_tgt_wwpn,
&phba->sli4_hba.oas_next_lun,
(struct lpfc_name *)vpt_wwpn,
(struct lpfc_name *)tgt_wwpn,
&found_lun, lun_status, lun_pri))
return found_lun;
else
return NOT_OAS_ENABLED_LUN;
}
static ssize_t
lpfc_oas_lun_state_change(struct lpfc_hba *phba, uint8_t vpt_wwpn[],
uint8_t tgt_wwpn[], uint64_t lun,
uint32_t oas_state, uint8_t pri)
{
int rc;
rc = lpfc_oas_lun_state_set(phba, vpt_wwpn, tgt_wwpn, lun,
oas_state, pri);
return rc;
}
static ssize_t
lpfc_oas_lun_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_hba *phba = ((struct lpfc_vport *)shost->hostdata)->phba;
uint64_t oas_lun;
int len = 0;
if (!phba->cfg_fof)
return -EPERM;
if (wwn_to_u64(phba->cfg_oas_vpt_wwpn) == 0)
if (!(phba->cfg_oas_flags & OAS_FIND_ANY_VPORT))
return -EFAULT;
if (wwn_to_u64(phba->cfg_oas_tgt_wwpn) == 0)
if (!(phba->cfg_oas_flags & OAS_FIND_ANY_TARGET))
return -EFAULT;
oas_lun = lpfc_oas_lun_get_next(phba, phba->cfg_oas_vpt_wwpn,
phba->cfg_oas_tgt_wwpn,
&phba->cfg_oas_lun_status,
&phba->cfg_oas_priority);
if (oas_lun != NOT_OAS_ENABLED_LUN)
phba->cfg_oas_flags |= OAS_LUN_VALID;
len += snprintf(buf + len, PAGE_SIZE-len, "0x%llx", oas_lun);
return len;
}
static ssize_t
lpfc_oas_lun_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_hba *phba = ((struct lpfc_vport *)shost->hostdata)->phba;
uint64_t scsi_lun;
uint32_t pri;
ssize_t rc;
if (!phba->cfg_fof)
return -EPERM;
if (wwn_to_u64(phba->cfg_oas_vpt_wwpn) == 0)
return -EFAULT;
if (wwn_to_u64(phba->cfg_oas_tgt_wwpn) == 0)
return -EFAULT;
if (!isdigit(buf[0]))
return -EINVAL;
if (sscanf(buf, "0x%llx", &scsi_lun) != 1)
return -EINVAL;
pri = phba->cfg_oas_priority;
if (pri == 0)
pri = phba->cfg_XLanePriority;
lpfc_printf_log(phba, KERN_INFO, LOG_INIT,
"3372 Try to set vport 0x%llx target 0x%llx lun:0x%llx "
"priority 0x%x with oas state %d\n",
wwn_to_u64(phba->cfg_oas_vpt_wwpn),
wwn_to_u64(phba->cfg_oas_tgt_wwpn), scsi_lun,
pri, phba->cfg_oas_lun_state);
rc = lpfc_oas_lun_state_change(phba, phba->cfg_oas_vpt_wwpn,
phba->cfg_oas_tgt_wwpn, scsi_lun,
phba->cfg_oas_lun_state, pri);
if (rc)
return rc;
return count;
}
static ssize_t
lpfc_iocb_hw_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_hba *phba = ((struct lpfc_vport *) shost->hostdata)->phba;
return snprintf(buf, PAGE_SIZE, "%d\n", phba->iocb_max);
}
static ssize_t
lpfc_txq_hw_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_hba *phba = ((struct lpfc_vport *) shost->hostdata)->phba;
struct lpfc_sli_ring *pring = lpfc_phba_elsring(phba);
return snprintf(buf, PAGE_SIZE, "%d\n", pring->txq_max);
}
static ssize_t
lpfc_txcmplq_hw_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_hba *phba = ((struct lpfc_vport *) shost->hostdata)->phba;
struct lpfc_sli_ring *pring = lpfc_phba_elsring(phba);
return snprintf(buf, PAGE_SIZE, "%d\n", pring->txcmplq_max);
}
static ssize_t
lpfc_nodev_tmo_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
return snprintf(buf, PAGE_SIZE, "%d\n", vport->cfg_devloss_tmo);
}
static int
lpfc_nodev_tmo_init(struct lpfc_vport *vport, int val)
{
if (vport->cfg_devloss_tmo != LPFC_DEF_DEVLOSS_TMO) {
vport->cfg_nodev_tmo = vport->cfg_devloss_tmo;
if (val != LPFC_DEF_DEVLOSS_TMO)
lpfc_printf_vlog(vport, KERN_ERR, LOG_INIT,
"0407 Ignoring lpfc_nodev_tmo module "
"parameter because lpfc_devloss_tmo "
"is set.\n");
return 0;
}
if (val >= LPFC_MIN_DEVLOSS_TMO && val <= LPFC_MAX_DEVLOSS_TMO) {
vport->cfg_nodev_tmo = val;
vport->cfg_devloss_tmo = val;
return 0;
}
lpfc_printf_vlog(vport, KERN_ERR, LOG_INIT,
"0400 lpfc_nodev_tmo attribute cannot be set to"
" %d, allowed range is [%d, %d]\n",
val, LPFC_MIN_DEVLOSS_TMO, LPFC_MAX_DEVLOSS_TMO);
vport->cfg_nodev_tmo = LPFC_DEF_DEVLOSS_TMO;
return -EINVAL;
}
static void
lpfc_update_rport_devloss_tmo(struct lpfc_vport *vport)
{
struct Scsi_Host *shost;
struct lpfc_nodelist *ndlp;
shost = lpfc_shost_from_vport(vport);
spin_lock_irq(shost->host_lock);
list_for_each_entry(ndlp, &vport->fc_nodes, nlp_listp)
if (NLP_CHK_NODE_ACT(ndlp) && ndlp->rport)
ndlp->rport->dev_loss_tmo = vport->cfg_devloss_tmo;
spin_unlock_irq(shost->host_lock);
}
static int
lpfc_nodev_tmo_set(struct lpfc_vport *vport, int val)
{
if (vport->dev_loss_tmo_changed ||
(lpfc_devloss_tmo != LPFC_DEF_DEVLOSS_TMO)) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_INIT,
"0401 Ignoring change to lpfc_nodev_tmo "
"because lpfc_devloss_tmo is set.\n");
return 0;
}
if (val >= LPFC_MIN_DEVLOSS_TMO && val <= LPFC_MAX_DEVLOSS_TMO) {
vport->cfg_nodev_tmo = val;
vport->cfg_devloss_tmo = val;
fc_host_dev_loss_tmo(lpfc_shost_from_vport(vport)) = val;
lpfc_update_rport_devloss_tmo(vport);
return 0;
}
lpfc_printf_vlog(vport, KERN_ERR, LOG_INIT,
"0403 lpfc_nodev_tmo attribute cannot be set to "
"%d, allowed range is [%d, %d]\n",
val, LPFC_MIN_DEVLOSS_TMO, LPFC_MAX_DEVLOSS_TMO);
return -EINVAL;
}
static int
lpfc_devloss_tmo_set(struct lpfc_vport *vport, int val)
{
if (val >= LPFC_MIN_DEVLOSS_TMO && val <= LPFC_MAX_DEVLOSS_TMO) {
vport->cfg_nodev_tmo = val;
vport->cfg_devloss_tmo = val;
vport->dev_loss_tmo_changed = 1;
fc_host_dev_loss_tmo(lpfc_shost_from_vport(vport)) = val;
lpfc_update_rport_devloss_tmo(vport);
return 0;
}
lpfc_printf_vlog(vport, KERN_ERR, LOG_INIT,
"0404 lpfc_devloss_tmo attribute cannot be set to "
"%d, allowed range is [%d, %d]\n",
val, LPFC_MIN_DEVLOSS_TMO, LPFC_MAX_DEVLOSS_TMO);
return -EINVAL;
}
static int
lpfc_restrict_login_init(struct lpfc_vport *vport, int val)
{
if (val < 0 || val > 1) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_INIT,
"0422 lpfc_restrict_login attribute cannot "
"be set to %d, allowed range is [0, 1]\n",
val);
vport->cfg_restrict_login = 1;
return -EINVAL;
}
if (vport->port_type == LPFC_PHYSICAL_PORT) {
vport->cfg_restrict_login = 0;
return 0;
}
vport->cfg_restrict_login = val;
return 0;
}
static int
lpfc_restrict_login_set(struct lpfc_vport *vport, int val)
{
if (val < 0 || val > 1) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_INIT,
"0425 lpfc_restrict_login attribute cannot "
"be set to %d, allowed range is [0, 1]\n",
val);
vport->cfg_restrict_login = 1;
return -EINVAL;
}
if (vport->port_type == LPFC_PHYSICAL_PORT && val != 0) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_INIT,
"0468 lpfc_restrict_login must be 0 for "
"Physical ports.\n");
vport->cfg_restrict_login = 0;
return 0;
}
vport->cfg_restrict_login = val;
return 0;
}
static ssize_t
lpfc_topology_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
int val = 0;
int nolip = 0;
const char *val_buf = buf;
int err;
uint32_t prev_val;
if (!strncmp(buf, "nolip ", strlen("nolip "))) {
nolip = 1;
val_buf = &buf[strlen("nolip ")];
}
if (!isdigit(val_buf[0]))
return -EINVAL;
if (sscanf(val_buf, "%i", &val) != 1)
return -EINVAL;
if (val >= 0 && val <= 6) {
prev_val = phba->cfg_topology;
if (phba->cfg_link_speed == LPFC_USER_LINK_SPEED_16G &&
val == 4) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_INIT,
"3113 Loop mode not supported at speed %d\n",
val);
return -EINVAL;
}
if (phba->pcidev->device == PCI_DEVICE_ID_LANCER_G6_FC &&
val == 4) {
lpfc_printf_vlog(vport, KERN_ERR, LOG_INIT,
"3114 Loop mode not supported\n");
return -EINVAL;
}
phba->cfg_topology = val;
if (nolip)
return strlen(buf);
lpfc_printf_vlog(vport, KERN_ERR, LOG_INIT,
"3054 lpfc_topology changed from %d to %d\n",
prev_val, val);
if (prev_val != val && phba->sli_rev == LPFC_SLI_REV4)
phba->fc_topology_changed = 1;
err = lpfc_issue_lip(lpfc_shost_from_vport(phba->pport));
if (err) {
phba->cfg_topology = prev_val;
return -EINVAL;
} else
return strlen(buf);
}
lpfc_printf_log(phba, KERN_ERR, LOG_INIT,
"%d:0467 lpfc_topology attribute cannot be set to %d, "
"allowed range is [0, 6]\n",
phba->brd_no, val);
return -EINVAL;
}
static ssize_t
lpfc_static_vport_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
if (vport->vport_flag & STATIC_VPORT)
sprintf(buf, "1\n");
else
sprintf(buf, "0\n");
return strlen(buf);
}
static ssize_t
lpfc_stat_data_ctrl_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
#define LPFC_MAX_DATA_CTRL_LEN 1024
static char bucket_data[LPFC_MAX_DATA_CTRL_LEN];
unsigned long i;
char *str_ptr, *token;
struct lpfc_vport **vports;
struct Scsi_Host *v_shost;
char *bucket_type_str, *base_str, *step_str;
unsigned long base, step, bucket_type;
if (!strncmp(buf, "setbucket", strlen("setbucket"))) {
if (strlen(buf) > (LPFC_MAX_DATA_CTRL_LEN - 1))
return -EINVAL;
strncpy(bucket_data, buf, LPFC_MAX_DATA_CTRL_LEN);
str_ptr = &bucket_data[0];
token = strsep(&str_ptr, "\t ");
if (!token)
return -EINVAL;
bucket_type_str = strsep(&str_ptr, "\t ");
if (!bucket_type_str)
return -EINVAL;
if (!strncmp(bucket_type_str, "linear", strlen("linear")))
bucket_type = LPFC_LINEAR_BUCKET;
else if (!strncmp(bucket_type_str, "power2", strlen("power2")))
bucket_type = LPFC_POWER2_BUCKET;
else
return -EINVAL;
base_str = strsep(&str_ptr, "\t ");
if (!base_str)
return -EINVAL;
base = simple_strtoul(base_str, NULL, 0);
step_str = strsep(&str_ptr, "\t ");
if (!step_str)
return -EINVAL;
step = simple_strtoul(step_str, NULL, 0);
if (!step)
return -EINVAL;
vports = lpfc_create_vport_work_array(phba);
if (vports == NULL)
return -ENOMEM;
for (i = 0; i <= phba->max_vports && vports[i] != NULL; i++) {
v_shost = lpfc_shost_from_vport(vports[i]);
spin_lock_irq(v_shost->host_lock);
vports[i]->stat_data_blocked = 1;
if (vports[i]->stat_data_enabled)
lpfc_vport_reset_stat_data(vports[i]);
spin_unlock_irq(v_shost->host_lock);
}
phba->bucket_type = bucket_type;
phba->bucket_base = base;
phba->bucket_step = step;
for (i = 0; i <= phba->max_vports && vports[i] != NULL; i++) {
v_shost = lpfc_shost_from_vport(vports[i]);
spin_lock_irq(v_shost->host_lock);
vports[i]->stat_data_blocked = 0;
spin_unlock_irq(v_shost->host_lock);
}
lpfc_destroy_vport_work_array(phba, vports);
return strlen(buf);
}
if (!strncmp(buf, "destroybucket", strlen("destroybucket"))) {
vports = lpfc_create_vport_work_array(phba);
if (vports == NULL)
return -ENOMEM;
for (i = 0; i <= phba->max_vports && vports[i] != NULL; i++) {
v_shost = lpfc_shost_from_vport(vports[i]);
spin_lock_irq(shost->host_lock);
vports[i]->stat_data_blocked = 1;
lpfc_free_bucket(vport);
vport->stat_data_enabled = 0;
vports[i]->stat_data_blocked = 0;
spin_unlock_irq(shost->host_lock);
}
lpfc_destroy_vport_work_array(phba, vports);
phba->bucket_type = LPFC_NO_BUCKET;
phba->bucket_base = 0;
phba->bucket_step = 0;
return strlen(buf);
}
if (!strncmp(buf, "start", strlen("start"))) {
if (phba->bucket_type == LPFC_NO_BUCKET)
return -EINVAL;
spin_lock_irq(shost->host_lock);
if (vport->stat_data_enabled) {
spin_unlock_irq(shost->host_lock);
return strlen(buf);
}
lpfc_alloc_bucket(vport);
vport->stat_data_enabled = 1;
spin_unlock_irq(shost->host_lock);
return strlen(buf);
}
if (!strncmp(buf, "stop", strlen("stop"))) {
spin_lock_irq(shost->host_lock);
if (vport->stat_data_enabled == 0) {
spin_unlock_irq(shost->host_lock);
return strlen(buf);
}
lpfc_free_bucket(vport);
vport->stat_data_enabled = 0;
spin_unlock_irq(shost->host_lock);
return strlen(buf);
}
if (!strncmp(buf, "reset", strlen("reset"))) {
if ((phba->bucket_type == LPFC_NO_BUCKET)
|| !vport->stat_data_enabled)
return strlen(buf);
spin_lock_irq(shost->host_lock);
vport->stat_data_blocked = 1;
lpfc_vport_reset_stat_data(vport);
vport->stat_data_blocked = 0;
spin_unlock_irq(shost->host_lock);
return strlen(buf);
}
return -EINVAL;
}
static ssize_t
lpfc_stat_data_ctrl_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
int index = 0;
int i;
char *bucket_type;
unsigned long bucket_value;
switch (phba->bucket_type) {
case LPFC_LINEAR_BUCKET:
bucket_type = "linear";
break;
case LPFC_POWER2_BUCKET:
bucket_type = "power2";
break;
default:
bucket_type = "No Bucket";
break;
}
sprintf(&buf[index], "Statistical Data enabled :%d, "
"blocked :%d, Bucket type :%s, Bucket base :%d,"
" Bucket step :%d\nLatency Ranges :",
vport->stat_data_enabled, vport->stat_data_blocked,
bucket_type, phba->bucket_base, phba->bucket_step);
index = strlen(buf);
if (phba->bucket_type != LPFC_NO_BUCKET) {
for (i = 0; i < LPFC_MAX_BUCKET_COUNT; i++) {
if (phba->bucket_type == LPFC_LINEAR_BUCKET)
bucket_value = phba->bucket_base +
phba->bucket_step * i;
else
bucket_value = phba->bucket_base +
(1 << i) * phba->bucket_step;
if (index + 10 > PAGE_SIZE)
break;
sprintf(&buf[index], "%08ld ", bucket_value);
index = strlen(buf);
}
}
sprintf(&buf[index], "\n");
return strlen(buf);
}
static ssize_t
sysfs_drvr_stat_data_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t off, size_t count)
{
struct device *dev = container_of(kobj, struct device,
kobj);
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
int i = 0, index = 0;
unsigned long nport_index;
struct lpfc_nodelist *ndlp = NULL;
nport_index = (unsigned long)off /
MAX_STAT_DATA_SIZE_PER_TARGET;
if (!vport->stat_data_enabled || vport->stat_data_blocked
|| (phba->bucket_type == LPFC_NO_BUCKET))
return 0;
spin_lock_irq(shost->host_lock);
list_for_each_entry(ndlp, &vport->fc_nodes, nlp_listp) {
if (!NLP_CHK_NODE_ACT(ndlp) || !ndlp->lat_data)
continue;
if (nport_index > 0) {
nport_index--;
continue;
}
if ((index + MAX_STAT_DATA_SIZE_PER_TARGET)
> count)
break;
if (!ndlp->lat_data)
continue;
sprintf(&buf[index], "%02x%02x%02x%02x%02x%02x%02x%02x:",
ndlp->nlp_portname.u.wwn[0],
ndlp->nlp_portname.u.wwn[1],
ndlp->nlp_portname.u.wwn[2],
ndlp->nlp_portname.u.wwn[3],
ndlp->nlp_portname.u.wwn[4],
ndlp->nlp_portname.u.wwn[5],
ndlp->nlp_portname.u.wwn[6],
ndlp->nlp_portname.u.wwn[7]);
index = strlen(buf);
for (i = 0; i < LPFC_MAX_BUCKET_COUNT; i++) {
sprintf(&buf[index], "%010u,",
ndlp->lat_data[i].cmd_count);
index = strlen(buf);
}
sprintf(&buf[index], "\n");
index = strlen(buf);
}
spin_unlock_irq(shost->host_lock);
return index;
}
static ssize_t
lpfc_link_speed_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
int val = LPFC_USER_LINK_SPEED_AUTO;
int nolip = 0;
const char *val_buf = buf;
int err;
uint32_t prev_val, if_type;
if_type = bf_get(lpfc_sli_intf_if_type, &phba->sli4_hba.sli_intf);
if (if_type == LPFC_SLI_INTF_IF_TYPE_2 &&
phba->hba_flag & HBA_FORCED_LINK_SPEED)
return -EPERM;
if (!strncmp(buf, "nolip ", strlen("nolip "))) {
nolip = 1;
val_buf = &buf[strlen("nolip ")];
}
if (!isdigit(val_buf[0]))
return -EINVAL;
if (sscanf(val_buf, "%i", &val) != 1)
return -EINVAL;
lpfc_printf_vlog(vport, KERN_ERR, LOG_INIT,
"3055 lpfc_link_speed changed from %d to %d %s\n",
phba->cfg_link_speed, val, nolip ? "(nolip)" : "(lip)");
if (((val == LPFC_USER_LINK_SPEED_1G) && !(phba->lmt & LMT_1Gb)) ||
((val == LPFC_USER_LINK_SPEED_2G) && !(phba->lmt & LMT_2Gb)) ||
((val == LPFC_USER_LINK_SPEED_4G) && !(phba->lmt & LMT_4Gb)) ||
((val == LPFC_USER_LINK_SPEED_8G) && !(phba->lmt & LMT_8Gb)) ||
((val == LPFC_USER_LINK_SPEED_10G) && !(phba->lmt & LMT_10Gb)) ||
((val == LPFC_USER_LINK_SPEED_16G) && !(phba->lmt & LMT_16Gb)) ||
((val == LPFC_USER_LINK_SPEED_32G) && !(phba->lmt & LMT_32Gb))) {
lpfc_printf_log(phba, KERN_ERR, LOG_INIT,
"2879 lpfc_link_speed attribute cannot be set "
"to %d. Speed is not supported by this port.\n",
val);
return -EINVAL;
}
if (val == LPFC_USER_LINK_SPEED_16G &&
phba->fc_topology == LPFC_TOPOLOGY_LOOP) {
lpfc_printf_log(phba, KERN_ERR, LOG_INIT,
"3112 lpfc_link_speed attribute cannot be set "
"to %d. Speed is not supported in loop mode.\n",
val);
return -EINVAL;
}
if ((val >= 0) && (val <= LPFC_USER_LINK_SPEED_MAX) &&
(LPFC_USER_LINK_SPEED_BITMAP & (1 << val))) {
prev_val = phba->cfg_link_speed;
phba->cfg_link_speed = val;
if (nolip)
return strlen(buf);
err = lpfc_issue_lip(lpfc_shost_from_vport(phba->pport));
if (err) {
phba->cfg_link_speed = prev_val;
return -EINVAL;
} else
return strlen(buf);
}
lpfc_printf_log(phba, KERN_ERR, LOG_INIT,
"0469 lpfc_link_speed attribute cannot be set to %d, "
"allowed values are ["LPFC_LINK_SPEED_STRING"]\n", val);
return -EINVAL;
}
static int
lpfc_link_speed_init(struct lpfc_hba *phba, int val)
{
if (val == LPFC_USER_LINK_SPEED_16G && phba->cfg_topology == 4) {
lpfc_printf_log(phba, KERN_ERR, LOG_INIT,
"3111 lpfc_link_speed of %d cannot "
"support loop mode, setting topology to default.\n",
val);
phba->cfg_topology = 0;
}
if ((val >= 0) && (val <= LPFC_USER_LINK_SPEED_MAX) &&
(LPFC_USER_LINK_SPEED_BITMAP & (1 << val))) {
phba->cfg_link_speed = val;
return 0;
}
lpfc_printf_log(phba, KERN_ERR, LOG_INIT,
"0405 lpfc_link_speed attribute cannot "
"be set to %d, allowed values are "
"["LPFC_LINK_SPEED_STRING"]\n", val);
phba->cfg_link_speed = LPFC_USER_LINK_SPEED_AUTO;
return -EINVAL;
}
static ssize_t
lpfc_aer_support_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *)shost->hostdata;
struct lpfc_hba *phba = vport->phba;
int val = 0, rc = -EINVAL;
if (!isdigit(buf[0]))
return -EINVAL;
if (sscanf(buf, "%i", &val) != 1)
return -EINVAL;
switch (val) {
case 0:
if (phba->hba_flag & HBA_AER_ENABLED) {
rc = pci_disable_pcie_error_reporting(phba->pcidev);
if (!rc) {
spin_lock_irq(&phba->hbalock);
phba->hba_flag &= ~HBA_AER_ENABLED;
spin_unlock_irq(&phba->hbalock);
phba->cfg_aer_support = 0;
rc = strlen(buf);
} else
rc = -EPERM;
} else {
phba->cfg_aer_support = 0;
rc = strlen(buf);
}
break;
case 1:
if (!(phba->hba_flag & HBA_AER_ENABLED)) {
rc = pci_enable_pcie_error_reporting(phba->pcidev);
if (!rc) {
spin_lock_irq(&phba->hbalock);
phba->hba_flag |= HBA_AER_ENABLED;
spin_unlock_irq(&phba->hbalock);
phba->cfg_aer_support = 1;
rc = strlen(buf);
} else
rc = -EPERM;
} else {
phba->cfg_aer_support = 1;
rc = strlen(buf);
}
break;
default:
rc = -EINVAL;
break;
}
return rc;
}
static ssize_t
lpfc_aer_cleanup_state(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
int val, rc = -1;
if (!isdigit(buf[0]))
return -EINVAL;
if (sscanf(buf, "%i", &val) != 1)
return -EINVAL;
if (val != 1)
return -EINVAL;
if (phba->hba_flag & HBA_AER_ENABLED)
rc = pci_cleanup_aer_uncorrect_error_status(phba->pcidev);
if (rc == 0)
return strlen(buf);
else
return -EPERM;
}
static ssize_t
lpfc_sriov_nr_virtfn_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *)shost->hostdata;
struct lpfc_hba *phba = vport->phba;
struct pci_dev *pdev = phba->pcidev;
int val = 0, rc = -EINVAL;
if (!isdigit(buf[0]))
return -EINVAL;
if (sscanf(buf, "%i", &val) != 1)
return -EINVAL;
if (val < 0)
return -EINVAL;
if (val == 0) {
if (phba->cfg_sriov_nr_virtfn > 0) {
pci_disable_sriov(pdev);
phba->cfg_sriov_nr_virtfn = 0;
}
return strlen(buf);
}
if (phba->cfg_sriov_nr_virtfn > 0) {
lpfc_printf_log(phba, KERN_ERR, LOG_INIT,
"3018 There are %d virtual functions "
"enabled on physical function.\n",
phba->cfg_sriov_nr_virtfn);
return -EEXIST;
}
if (val <= LPFC_MAX_VFN_PER_PFN)
phba->cfg_sriov_nr_virtfn = val;
else {
lpfc_printf_log(phba, KERN_ERR, LOG_INIT,
"3019 Enabling %d virtual functions is not "
"allowed.\n", val);
return -EINVAL;
}
rc = lpfc_sli_probe_sriov_nr_virtfn(phba, phba->cfg_sriov_nr_virtfn);
if (rc) {
phba->cfg_sriov_nr_virtfn = 0;
rc = -EPERM;
} else
rc = strlen(buf);
return rc;
}
static ssize_t
lpfc_request_firmware_upgrade_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *)shost->hostdata;
struct lpfc_hba *phba = vport->phba;
int val = 0, rc = -EINVAL;
if (!isdigit(buf[0]))
return -EINVAL;
if (sscanf(buf, "%i", &val) != 1)
return -EINVAL;
if (val != 1)
return -EINVAL;
rc = lpfc_sli4_request_firmware_update(phba, RUN_FW_UPGRADE);
if (rc)
rc = -EPERM;
else
rc = strlen(buf);
return rc;
}
static int
lpfc_request_firmware_upgrade_init(struct lpfc_hba *phba, int val)
{
if (val >= 0 && val <= 1) {
phba->cfg_request_firmware_upgrade = val;
return 0;
}
return -EINVAL;
}
static ssize_t
lpfc_fcp_imax_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *)shost->hostdata;
struct lpfc_hba *phba = vport->phba;
int val = 0, i;
if (phba->sli_rev != LPFC_SLI_REV4)
return -EINVAL;
if (!isdigit(buf[0]))
return -EINVAL;
if (sscanf(buf, "%i", &val) != 1)
return -EINVAL;
if (val && (val < LPFC_MIN_IMAX || val > LPFC_MAX_IMAX))
return -EINVAL;
phba->cfg_fcp_imax = (uint32_t)val;
for (i = 0; i < phba->io_channel_irqs; i += LPFC_MAX_EQ_DELAY_EQID_CNT)
lpfc_modify_hba_eq_delay(phba, i);
return strlen(buf);
}
static int
lpfc_fcp_imax_init(struct lpfc_hba *phba, int val)
{
if (phba->sli_rev != LPFC_SLI_REV4) {
phba->cfg_fcp_imax = 0;
return 0;
}
if ((val >= LPFC_MIN_IMAX && val <= LPFC_MAX_IMAX) ||
(val == 0)) {
phba->cfg_fcp_imax = val;
return 0;
}
lpfc_printf_log(phba, KERN_ERR, LOG_INIT,
"3016 lpfc_fcp_imax: %d out of range, using default\n",
val);
phba->cfg_fcp_imax = LPFC_DEF_IMAX;
return 0;
}
static ssize_t
lpfc_fcp_cpu_map_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *)shost->hostdata;
struct lpfc_hba *phba = vport->phba;
struct lpfc_vector_map_info *cpup;
int len = 0;
if ((phba->sli_rev != LPFC_SLI_REV4) ||
(phba->intr_type != MSIX))
return len;
switch (phba->cfg_fcp_cpu_map) {
case 0:
len += snprintf(buf + len, PAGE_SIZE-len,
"fcp_cpu_map: No mapping (%d)\n",
phba->cfg_fcp_cpu_map);
return len;
case 1:
len += snprintf(buf + len, PAGE_SIZE-len,
"fcp_cpu_map: HBA centric mapping (%d): "
"%d online CPUs\n",
phba->cfg_fcp_cpu_map,
phba->sli4_hba.num_online_cpu);
break;
case 2:
len += snprintf(buf + len, PAGE_SIZE-len,
"fcp_cpu_map: Driver centric mapping (%d): "
"%d online CPUs\n",
phba->cfg_fcp_cpu_map,
phba->sli4_hba.num_online_cpu);
break;
}
while (phba->sli4_hba.curr_disp_cpu < phba->sli4_hba.num_present_cpu) {
cpup = &phba->sli4_hba.cpu_map[phba->sli4_hba.curr_disp_cpu];
if (cpup->irq == LPFC_VECTOR_MAP_EMPTY)
len += snprintf(buf + len, PAGE_SIZE-len,
"CPU %02d io_chan %02d "
"physid %d coreid %d\n",
phba->sli4_hba.curr_disp_cpu,
cpup->channel_id, cpup->phys_id,
cpup->core_id);
else
len += snprintf(buf + len, PAGE_SIZE-len,
"CPU %02d io_chan %02d "
"physid %d coreid %d IRQ %d\n",
phba->sli4_hba.curr_disp_cpu,
cpup->channel_id, cpup->phys_id,
cpup->core_id, cpup->irq);
phba->sli4_hba.curr_disp_cpu++;
if (phba->sli4_hba.curr_disp_cpu <
phba->sli4_hba.num_present_cpu &&
(len >= (PAGE_SIZE - 64))) {
len += snprintf(buf + len, PAGE_SIZE-len, "more...\n");
break;
}
}
if (phba->sli4_hba.curr_disp_cpu == phba->sli4_hba.num_present_cpu)
phba->sli4_hba.curr_disp_cpu = 0;
return len;
}
static ssize_t
lpfc_fcp_cpu_map_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int status = -EINVAL;
return status;
}
static int
lpfc_fcp_cpu_map_init(struct lpfc_hba *phba, int val)
{
if (phba->sli_rev != LPFC_SLI_REV4) {
phba->cfg_fcp_cpu_map = 0;
return 0;
}
if (val >= LPFC_MIN_CPU_MAP && val <= LPFC_MAX_CPU_MAP) {
phba->cfg_fcp_cpu_map = val;
return 0;
}
lpfc_printf_log(phba, KERN_ERR, LOG_INIT,
"3326 lpfc_fcp_cpu_map: %d out of range, using "
"default\n", val);
phba->cfg_fcp_cpu_map = LPFC_DRIVER_CPU_MAP;
return 0;
}
static int
lpfc_max_scsicmpl_time_set(struct lpfc_vport *vport, int val)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
struct lpfc_nodelist *ndlp, *next_ndlp;
if (val == vport->cfg_max_scsicmpl_time)
return 0;
if ((val < 0) || (val > 60000))
return -EINVAL;
vport->cfg_max_scsicmpl_time = val;
spin_lock_irq(shost->host_lock);
list_for_each_entry_safe(ndlp, next_ndlp, &vport->fc_nodes, nlp_listp) {
if (!NLP_CHK_NODE_ACT(ndlp))
continue;
if (ndlp->nlp_state == NLP_STE_UNUSED_NODE)
continue;
ndlp->cmd_qdepth = vport->cfg_tgt_queue_depth;
}
spin_unlock_irq(shost->host_lock);
return 0;
}
static ssize_t
sysfs_ctlreg_write(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t off, size_t count)
{
size_t buf_off;
struct device *dev = container_of(kobj, struct device, kobj);
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
if (phba->sli_rev >= LPFC_SLI_REV4)
return -EPERM;
if ((off + count) > FF_REG_AREA_SIZE)
return -ERANGE;
if (count <= LPFC_REG_WRITE_KEY_SIZE)
return 0;
if (off % 4 || count % 4 || (unsigned long)buf % 4)
return -EINVAL;
if (memcmp(buf, LPFC_REG_WRITE_KEY, LPFC_REG_WRITE_KEY_SIZE))
return -EINVAL;
if (!(vport->fc_flag & FC_OFFLINE_MODE))
return -EPERM;
spin_lock_irq(&phba->hbalock);
for (buf_off = 0; buf_off < count - LPFC_REG_WRITE_KEY_SIZE;
buf_off += sizeof(uint32_t))
writel(*((uint32_t *)(buf + buf_off + LPFC_REG_WRITE_KEY_SIZE)),
phba->ctrl_regs_memmap_p + off + buf_off);
spin_unlock_irq(&phba->hbalock);
return count;
}
static ssize_t
sysfs_ctlreg_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t off, size_t count)
{
size_t buf_off;
uint32_t * tmp_ptr;
struct device *dev = container_of(kobj, struct device, kobj);
struct Scsi_Host *shost = class_to_shost(dev);
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
if (phba->sli_rev >= LPFC_SLI_REV4)
return -EPERM;
if (off > FF_REG_AREA_SIZE)
return -ERANGE;
if ((off + count) > FF_REG_AREA_SIZE)
count = FF_REG_AREA_SIZE - off;
if (count == 0) return 0;
if (off % 4 || count % 4 || (unsigned long)buf % 4)
return -EINVAL;
spin_lock_irq(&phba->hbalock);
for (buf_off = 0; buf_off < count; buf_off += sizeof(uint32_t)) {
tmp_ptr = (uint32_t *)(buf + buf_off);
*tmp_ptr = readl(phba->ctrl_regs_memmap_p + off + buf_off);
}
spin_unlock_irq(&phba->hbalock);
return count;
}
static ssize_t
sysfs_mbox_write(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t off, size_t count)
{
return -EPERM;
}
static ssize_t
sysfs_mbox_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t off, size_t count)
{
return -EPERM;
}
int
lpfc_alloc_sysfs_attr(struct lpfc_vport *vport)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
int error;
error = sysfs_create_bin_file(&shost->shost_dev.kobj,
&sysfs_drvr_stat_data_attr);
if (error || vport->port_type == LPFC_NPIV_PORT)
goto out;
error = sysfs_create_bin_file(&shost->shost_dev.kobj,
&sysfs_ctlreg_attr);
if (error)
goto out_remove_stat_attr;
error = sysfs_create_bin_file(&shost->shost_dev.kobj,
&sysfs_mbox_attr);
if (error)
goto out_remove_ctlreg_attr;
return 0;
out_remove_ctlreg_attr:
sysfs_remove_bin_file(&shost->shost_dev.kobj, &sysfs_ctlreg_attr);
out_remove_stat_attr:
sysfs_remove_bin_file(&shost->shost_dev.kobj,
&sysfs_drvr_stat_data_attr);
out:
return error;
}
void
lpfc_free_sysfs_attr(struct lpfc_vport *vport)
{
struct Scsi_Host *shost = lpfc_shost_from_vport(vport);
sysfs_remove_bin_file(&shost->shost_dev.kobj,
&sysfs_drvr_stat_data_attr);
if (vport->port_type == LPFC_NPIV_PORT)
return;
sysfs_remove_bin_file(&shost->shost_dev.kobj, &sysfs_mbox_attr);
sysfs_remove_bin_file(&shost->shost_dev.kobj, &sysfs_ctlreg_attr);
}
static void
lpfc_get_host_symbolic_name(struct Scsi_Host *shost)
{
struct lpfc_vport *vport = (struct lpfc_vport *)shost->hostdata;
lpfc_vport_symbolic_node_name(vport, fc_host_symbolic_name(shost),
sizeof fc_host_symbolic_name(shost));
}
static void
lpfc_get_host_port_id(struct Scsi_Host *shost)
{
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
fc_host_port_id(shost) = vport->fc_myDID;
}
static void
lpfc_get_host_port_type(struct Scsi_Host *shost)
{
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
spin_lock_irq(shost->host_lock);
if (vport->port_type == LPFC_NPIV_PORT) {
fc_host_port_type(shost) = FC_PORTTYPE_NPIV;
} else if (lpfc_is_link_up(phba)) {
if (phba->fc_topology == LPFC_TOPOLOGY_LOOP) {
if (vport->fc_flag & FC_PUBLIC_LOOP)
fc_host_port_type(shost) = FC_PORTTYPE_NLPORT;
else
fc_host_port_type(shost) = FC_PORTTYPE_LPORT;
} else {
if (vport->fc_flag & FC_FABRIC)
fc_host_port_type(shost) = FC_PORTTYPE_NPORT;
else
fc_host_port_type(shost) = FC_PORTTYPE_PTP;
}
} else
fc_host_port_type(shost) = FC_PORTTYPE_UNKNOWN;
spin_unlock_irq(shost->host_lock);
}
static void
lpfc_get_host_port_state(struct Scsi_Host *shost)
{
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
spin_lock_irq(shost->host_lock);
if (vport->fc_flag & FC_OFFLINE_MODE)
fc_host_port_state(shost) = FC_PORTSTATE_OFFLINE;
else {
switch (phba->link_state) {
case LPFC_LINK_UNKNOWN:
case LPFC_LINK_DOWN:
fc_host_port_state(shost) = FC_PORTSTATE_LINKDOWN;
break;
case LPFC_LINK_UP:
case LPFC_CLEAR_LA:
case LPFC_HBA_READY:
if (vport->port_state < LPFC_VPORT_READY)
fc_host_port_state(shost) =
FC_PORTSTATE_BYPASSED;
else
fc_host_port_state(shost) =
FC_PORTSTATE_ONLINE;
break;
case LPFC_HBA_ERROR:
fc_host_port_state(shost) = FC_PORTSTATE_ERROR;
break;
default:
fc_host_port_state(shost) = FC_PORTSTATE_UNKNOWN;
break;
}
}
spin_unlock_irq(shost->host_lock);
}
static void
lpfc_get_host_speed(struct Scsi_Host *shost)
{
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
spin_lock_irq(shost->host_lock);
if ((lpfc_is_link_up(phba)) && (!(phba->hba_flag & HBA_FCOE_MODE))) {
switch(phba->fc_linkspeed) {
case LPFC_LINK_SPEED_1GHZ:
fc_host_speed(shost) = FC_PORTSPEED_1GBIT;
break;
case LPFC_LINK_SPEED_2GHZ:
fc_host_speed(shost) = FC_PORTSPEED_2GBIT;
break;
case LPFC_LINK_SPEED_4GHZ:
fc_host_speed(shost) = FC_PORTSPEED_4GBIT;
break;
case LPFC_LINK_SPEED_8GHZ:
fc_host_speed(shost) = FC_PORTSPEED_8GBIT;
break;
case LPFC_LINK_SPEED_10GHZ:
fc_host_speed(shost) = FC_PORTSPEED_10GBIT;
break;
case LPFC_LINK_SPEED_16GHZ:
fc_host_speed(shost) = FC_PORTSPEED_16GBIT;
break;
case LPFC_LINK_SPEED_32GHZ:
fc_host_speed(shost) = FC_PORTSPEED_32GBIT;
break;
default:
fc_host_speed(shost) = FC_PORTSPEED_UNKNOWN;
break;
}
} else
fc_host_speed(shost) = FC_PORTSPEED_UNKNOWN;
spin_unlock_irq(shost->host_lock);
}
static void
lpfc_get_host_fabric_name (struct Scsi_Host *shost)
{
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
u64 node_name;
spin_lock_irq(shost->host_lock);
if ((vport->port_state > LPFC_FLOGI) &&
((vport->fc_flag & FC_FABRIC) ||
((phba->fc_topology == LPFC_TOPOLOGY_LOOP) &&
(vport->fc_flag & FC_PUBLIC_LOOP))))
node_name = wwn_to_u64(phba->fc_fabparam.nodeName.u.wwn);
else
node_name = 0;
spin_unlock_irq(shost->host_lock);
fc_host_fabric_name(shost) = node_name;
}
static struct fc_host_statistics *
lpfc_get_stats(struct Scsi_Host *shost)
{
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
struct lpfc_sli *psli = &phba->sli;
struct fc_host_statistics *hs = &phba->link_stats;
struct lpfc_lnk_stat * lso = &psli->lnk_stat_offsets;
LPFC_MBOXQ_t *pmboxq;
MAILBOX_t *pmb;
unsigned long seconds;
int rc = 0;
if (phba->link_state < LPFC_LINK_DOWN ||
!phba->mbox_mem_pool ||
(phba->sli.sli_flag & LPFC_SLI_ACTIVE) == 0)
return NULL;
if (phba->sli.sli_flag & LPFC_BLOCK_MGMT_IO)
return NULL;
pmboxq = mempool_alloc(phba->mbox_mem_pool, GFP_KERNEL);
if (!pmboxq)
return NULL;
memset(pmboxq, 0, sizeof (LPFC_MBOXQ_t));
pmb = &pmboxq->u.mb;
pmb->mbxCommand = MBX_READ_STATUS;
pmb->mbxOwner = OWN_HOST;
pmboxq->context1 = NULL;
pmboxq->vport = vport;
if (vport->fc_flag & FC_OFFLINE_MODE)
rc = lpfc_sli_issue_mbox(phba, pmboxq, MBX_POLL);
else
rc = lpfc_sli_issue_mbox_wait(phba, pmboxq, phba->fc_ratov * 2);
if (rc != MBX_SUCCESS) {
if (rc != MBX_TIMEOUT)
mempool_free(pmboxq, phba->mbox_mem_pool);
return NULL;
}
memset(hs, 0, sizeof (struct fc_host_statistics));
hs->tx_frames = pmb->un.varRdStatus.xmitFrameCnt;
hs->tx_words = (uint64_t)
((uint64_t)pmb->un.varRdStatus.xmitByteCnt
* (uint64_t)256);
hs->rx_frames = pmb->un.varRdStatus.rcvFrameCnt;
hs->rx_words = (uint64_t)
((uint64_t)pmb->un.varRdStatus.rcvByteCnt
* (uint64_t)256);
memset(pmboxq, 0, sizeof (LPFC_MBOXQ_t));
pmb->mbxCommand = MBX_READ_LNK_STAT;
pmb->mbxOwner = OWN_HOST;
pmboxq->context1 = NULL;
pmboxq->vport = vport;
if (vport->fc_flag & FC_OFFLINE_MODE)
rc = lpfc_sli_issue_mbox(phba, pmboxq, MBX_POLL);
else
rc = lpfc_sli_issue_mbox_wait(phba, pmboxq, phba->fc_ratov * 2);
if (rc != MBX_SUCCESS) {
if (rc != MBX_TIMEOUT)
mempool_free(pmboxq, phba->mbox_mem_pool);
return NULL;
}
hs->link_failure_count = pmb->un.varRdLnk.linkFailureCnt;
hs->loss_of_sync_count = pmb->un.varRdLnk.lossSyncCnt;
hs->loss_of_signal_count = pmb->un.varRdLnk.lossSignalCnt;
hs->prim_seq_protocol_err_count = pmb->un.varRdLnk.primSeqErrCnt;
hs->invalid_tx_word_count = pmb->un.varRdLnk.invalidXmitWord;
hs->invalid_crc_count = pmb->un.varRdLnk.crcCnt;
hs->error_frames = pmb->un.varRdLnk.crcCnt;
hs->link_failure_count -= lso->link_failure_count;
hs->loss_of_sync_count -= lso->loss_of_sync_count;
hs->loss_of_signal_count -= lso->loss_of_signal_count;
hs->prim_seq_protocol_err_count -= lso->prim_seq_protocol_err_count;
hs->invalid_tx_word_count -= lso->invalid_tx_word_count;
hs->invalid_crc_count -= lso->invalid_crc_count;
hs->error_frames -= lso->error_frames;
if (phba->hba_flag & HBA_FCOE_MODE) {
hs->lip_count = -1;
hs->nos_count = (phba->link_events >> 1);
hs->nos_count -= lso->link_events;
} else if (phba->fc_topology == LPFC_TOPOLOGY_LOOP) {
hs->lip_count = (phba->fc_eventTag >> 1);
hs->lip_count -= lso->link_events;
hs->nos_count = -1;
} else {
hs->lip_count = -1;
hs->nos_count = (phba->fc_eventTag >> 1);
hs->nos_count -= lso->link_events;
}
hs->dumped_frames = -1;
seconds = get_seconds();
if (seconds < psli->stats_start)
hs->seconds_since_last_reset = seconds +
((unsigned long)-1 - psli->stats_start);
else
hs->seconds_since_last_reset = seconds - psli->stats_start;
mempool_free(pmboxq, phba->mbox_mem_pool);
return hs;
}
static void
lpfc_reset_stats(struct Scsi_Host *shost)
{
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_hba *phba = vport->phba;
struct lpfc_sli *psli = &phba->sli;
struct lpfc_lnk_stat *lso = &psli->lnk_stat_offsets;
LPFC_MBOXQ_t *pmboxq;
MAILBOX_t *pmb;
int rc = 0;
if (phba->sli.sli_flag & LPFC_BLOCK_MGMT_IO)
return;
pmboxq = mempool_alloc(phba->mbox_mem_pool, GFP_KERNEL);
if (!pmboxq)
return;
memset(pmboxq, 0, sizeof(LPFC_MBOXQ_t));
pmb = &pmboxq->u.mb;
pmb->mbxCommand = MBX_READ_STATUS;
pmb->mbxOwner = OWN_HOST;
pmb->un.varWords[0] = 0x1;
pmboxq->context1 = NULL;
pmboxq->vport = vport;
if ((vport->fc_flag & FC_OFFLINE_MODE) ||
(!(psli->sli_flag & LPFC_SLI_ACTIVE)))
rc = lpfc_sli_issue_mbox(phba, pmboxq, MBX_POLL);
else
rc = lpfc_sli_issue_mbox_wait(phba, pmboxq, phba->fc_ratov * 2);
if (rc != MBX_SUCCESS) {
if (rc != MBX_TIMEOUT)
mempool_free(pmboxq, phba->mbox_mem_pool);
return;
}
memset(pmboxq, 0, sizeof(LPFC_MBOXQ_t));
pmb->mbxCommand = MBX_READ_LNK_STAT;
pmb->mbxOwner = OWN_HOST;
pmboxq->context1 = NULL;
pmboxq->vport = vport;
if ((vport->fc_flag & FC_OFFLINE_MODE) ||
(!(psli->sli_flag & LPFC_SLI_ACTIVE)))
rc = lpfc_sli_issue_mbox(phba, pmboxq, MBX_POLL);
else
rc = lpfc_sli_issue_mbox_wait(phba, pmboxq, phba->fc_ratov * 2);
if (rc != MBX_SUCCESS) {
if (rc != MBX_TIMEOUT)
mempool_free( pmboxq, phba->mbox_mem_pool);
return;
}
lso->link_failure_count = pmb->un.varRdLnk.linkFailureCnt;
lso->loss_of_sync_count = pmb->un.varRdLnk.lossSyncCnt;
lso->loss_of_signal_count = pmb->un.varRdLnk.lossSignalCnt;
lso->prim_seq_protocol_err_count = pmb->un.varRdLnk.primSeqErrCnt;
lso->invalid_tx_word_count = pmb->un.varRdLnk.invalidXmitWord;
lso->invalid_crc_count = pmb->un.varRdLnk.crcCnt;
lso->error_frames = pmb->un.varRdLnk.crcCnt;
if (phba->hba_flag & HBA_FCOE_MODE)
lso->link_events = (phba->link_events >> 1);
else
lso->link_events = (phba->fc_eventTag >> 1);
psli->stats_start = get_seconds();
mempool_free(pmboxq, phba->mbox_mem_pool);
return;
}
static struct lpfc_nodelist *
lpfc_get_node_by_target(struct scsi_target *starget)
{
struct Scsi_Host *shost = dev_to_shost(starget->dev.parent);
struct lpfc_vport *vport = (struct lpfc_vport *) shost->hostdata;
struct lpfc_nodelist *ndlp;
spin_lock_irq(shost->host_lock);
list_for_each_entry(ndlp, &vport->fc_nodes, nlp_listp) {
if (NLP_CHK_NODE_ACT(ndlp) &&
ndlp->nlp_state == NLP_STE_MAPPED_NODE &&
starget->id == ndlp->nlp_sid) {
spin_unlock_irq(shost->host_lock);
return ndlp;
}
}
spin_unlock_irq(shost->host_lock);
return NULL;
}
static void
lpfc_get_starget_port_id(struct scsi_target *starget)
{
struct lpfc_nodelist *ndlp = lpfc_get_node_by_target(starget);
fc_starget_port_id(starget) = ndlp ? ndlp->nlp_DID : -1;
}
static void
lpfc_get_starget_node_name(struct scsi_target *starget)
{
struct lpfc_nodelist *ndlp = lpfc_get_node_by_target(starget);
fc_starget_node_name(starget) =
ndlp ? wwn_to_u64(ndlp->nlp_nodename.u.wwn) : 0;
}
static void
lpfc_get_starget_port_name(struct scsi_target *starget)
{
struct lpfc_nodelist *ndlp = lpfc_get_node_by_target(starget);
fc_starget_port_name(starget) =
ndlp ? wwn_to_u64(ndlp->nlp_portname.u.wwn) : 0;
}
static void
lpfc_set_rport_loss_tmo(struct fc_rport *rport, uint32_t timeout)
{
if (timeout)
rport->dev_loss_tmo = timeout;
else
rport->dev_loss_tmo = 1;
}
static void
lpfc_set_vport_symbolic_name(struct fc_vport *fc_vport)
{
struct lpfc_vport *vport = *(struct lpfc_vport **)fc_vport->dd_data;
if (vport->port_state == LPFC_VPORT_READY)
lpfc_ns_cmd(vport, SLI_CTNS_RSPN_ID, 0, 0);
}
static void
lpfc_hba_log_verbose_init(struct lpfc_hba *phba, uint32_t verbose)
{
phba->cfg_log_verbose = verbose;
}
void
lpfc_get_cfgparam(struct lpfc_hba *phba)
{
lpfc_fcp_io_sched_init(phba, lpfc_fcp_io_sched);
lpfc_fcp2_no_tgt_reset_init(phba, lpfc_fcp2_no_tgt_reset);
lpfc_cr_delay_init(phba, lpfc_cr_delay);
lpfc_cr_count_init(phba, lpfc_cr_count);
lpfc_multi_ring_support_init(phba, lpfc_multi_ring_support);
lpfc_multi_ring_rctl_init(phba, lpfc_multi_ring_rctl);
lpfc_multi_ring_type_init(phba, lpfc_multi_ring_type);
lpfc_ack0_init(phba, lpfc_ack0);
lpfc_topology_init(phba, lpfc_topology);
lpfc_link_speed_init(phba, lpfc_link_speed);
lpfc_poll_tmo_init(phba, lpfc_poll_tmo);
lpfc_task_mgmt_tmo_init(phba, lpfc_task_mgmt_tmo);
lpfc_enable_npiv_init(phba, lpfc_enable_npiv);
lpfc_fcf_failover_policy_init(phba, lpfc_fcf_failover_policy);
lpfc_enable_rrq_init(phba, lpfc_enable_rrq);
lpfc_fdmi_on_init(phba, lpfc_fdmi_on);
lpfc_enable_SmartSAN_init(phba, lpfc_enable_SmartSAN);
lpfc_use_msi_init(phba, lpfc_use_msi);
lpfc_nvme_oas_init(phba, lpfc_nvme_oas);
lpfc_fcp_imax_init(phba, lpfc_fcp_imax);
lpfc_fcp_cpu_map_init(phba, lpfc_fcp_cpu_map);
lpfc_enable_hba_reset_init(phba, lpfc_enable_hba_reset);
lpfc_enable_hba_heartbeat_init(phba, lpfc_enable_hba_heartbeat);
lpfc_EnableXLane_init(phba, lpfc_EnableXLane);
if (phba->sli_rev != LPFC_SLI_REV4)
phba->cfg_EnableXLane = 0;
lpfc_XLanePriority_init(phba, lpfc_XLanePriority);
memset(phba->cfg_oas_tgt_wwpn, 0, (8 * sizeof(uint8_t)));
memset(phba->cfg_oas_vpt_wwpn, 0, (8 * sizeof(uint8_t)));
phba->cfg_oas_lun_state = 0;
phba->cfg_oas_lun_status = 0;
phba->cfg_oas_flags = 0;
phba->cfg_oas_priority = 0;
lpfc_enable_bg_init(phba, lpfc_enable_bg);
lpfc_prot_mask_init(phba, lpfc_prot_mask);
lpfc_prot_guard_init(phba, lpfc_prot_guard);
if (phba->sli_rev == LPFC_SLI_REV4)
phba->cfg_poll = 0;
else
phba->cfg_poll = lpfc_poll;
lpfc_suppress_rsp_init(phba, lpfc_suppress_rsp);
lpfc_enable_fc4_type_init(phba, lpfc_enable_fc4_type);
lpfc_nvmet_mrq_init(phba, lpfc_nvmet_mrq);
lpfc_nvme_enable_fb_init(phba, lpfc_nvme_enable_fb);
lpfc_nvmet_fb_size_init(phba, lpfc_nvmet_fb_size);
lpfc_fcp_io_channel_init(phba, lpfc_fcp_io_channel);
lpfc_nvme_io_channel_init(phba, lpfc_nvme_io_channel);
if (phba->sli_rev != LPFC_SLI_REV4) {
phba->nvmet_support = 0;
phba->cfg_enable_fc4_type = LPFC_ENABLE_FCP;
} else {
if (!(phba->cfg_enable_fc4_type & LPFC_ENABLE_FCP))
phba->cfg_enable_fc4_type |= LPFC_ENABLE_FCP;
}
if (phba->cfg_fcp_io_channel == 0)
phba->cfg_fcp_io_channel = phba->sli4_hba.num_present_cpu;
if (phba->cfg_nvme_io_channel == 0)
phba->cfg_nvme_io_channel = phba->sli4_hba.num_present_cpu;
if (phba->cfg_enable_fc4_type == LPFC_ENABLE_NVME)
phba->cfg_fcp_io_channel = 0;
if (phba->cfg_enable_fc4_type == LPFC_ENABLE_FCP)
phba->cfg_nvme_io_channel = 0;
if (phba->cfg_fcp_io_channel > phba->cfg_nvme_io_channel)
phba->io_channel_irqs = phba->cfg_fcp_io_channel;
else
phba->io_channel_irqs = phba->cfg_nvme_io_channel;
phba->cfg_soft_wwnn = 0L;
phba->cfg_soft_wwpn = 0L;
lpfc_xri_split_init(phba, lpfc_xri_split);
lpfc_sg_seg_cnt_init(phba, lpfc_sg_seg_cnt);
lpfc_hba_queue_depth_init(phba, lpfc_hba_queue_depth);
lpfc_hba_log_verbose_init(phba, lpfc_log_verbose);
lpfc_aer_support_init(phba, lpfc_aer_support);
lpfc_sriov_nr_virtfn_init(phba, lpfc_sriov_nr_virtfn);
lpfc_request_firmware_upgrade_init(phba, lpfc_req_fw_upgrade);
lpfc_suppress_link_up_init(phba, lpfc_suppress_link_up);
lpfc_iocb_cnt_init(phba, lpfc_iocb_cnt);
lpfc_delay_discovery_init(phba, lpfc_delay_discovery);
lpfc_sli_mode_init(phba, lpfc_sli_mode);
phba->cfg_enable_dss = 1;
lpfc_enable_mds_diags_init(phba, lpfc_enable_mds_diags);
return;
}
void
lpfc_nvme_mod_param_dep(struct lpfc_hba *phba)
{
if (phba->cfg_nvme_io_channel > phba->sli4_hba.num_present_cpu)
phba->cfg_nvme_io_channel = phba->sli4_hba.num_present_cpu;
if (phba->cfg_fcp_io_channel > phba->sli4_hba.num_present_cpu)
phba->cfg_fcp_io_channel = phba->sli4_hba.num_present_cpu;
if (phba->cfg_enable_fc4_type & LPFC_ENABLE_NVME &&
phba->nvmet_support) {
phba->cfg_enable_fc4_type &= ~LPFC_ENABLE_FCP;
phba->cfg_fcp_io_channel = 0;
lpfc_printf_log(phba, KERN_INFO, LOG_NVME_DISC,
"6013 %s x%x fb_size x%x, fb_max x%x\n",
"NVME Target PRLI ACC enable_fb ",
phba->cfg_nvme_enable_fb,
phba->cfg_nvmet_fb_size,
LPFC_NVMET_FB_SZ_MAX);
if (phba->cfg_nvme_enable_fb == 0)
phba->cfg_nvmet_fb_size = 0;
else {
if (phba->cfg_nvmet_fb_size > LPFC_NVMET_FB_SZ_MAX)
phba->cfg_nvmet_fb_size = LPFC_NVMET_FB_SZ_MAX;
}
if (phba->cfg_nvmet_mrq > phba->cfg_nvme_io_channel) {
phba->cfg_nvmet_mrq = phba->cfg_nvme_io_channel;
lpfc_printf_log(phba, KERN_ERR, LOG_NVME_DISC,
"6018 Adjust lpfc_nvmet_mrq to %d\n",
phba->cfg_nvmet_mrq);
}
} else {
phba->nvmet_support = 0;
phba->cfg_nvmet_mrq = 0;
phba->cfg_nvmet_fb_size = 0;
}
if (phba->cfg_fcp_io_channel > phba->cfg_nvme_io_channel)
phba->io_channel_irqs = phba->cfg_fcp_io_channel;
else
phba->io_channel_irqs = phba->cfg_nvme_io_channel;
}
void
lpfc_get_vport_cfgparam(struct lpfc_vport *vport)
{
lpfc_log_verbose_init(vport, lpfc_log_verbose);
lpfc_lun_queue_depth_init(vport, lpfc_lun_queue_depth);
lpfc_tgt_queue_depth_init(vport, lpfc_tgt_queue_depth);
lpfc_devloss_tmo_init(vport, lpfc_devloss_tmo);
lpfc_nodev_tmo_init(vport, lpfc_nodev_tmo);
lpfc_peer_port_login_init(vport, lpfc_peer_port_login);
lpfc_restrict_login_init(vport, lpfc_restrict_login);
lpfc_fcp_class_init(vport, lpfc_fcp_class);
lpfc_use_adisc_init(vport, lpfc_use_adisc);
lpfc_first_burst_size_init(vport, lpfc_first_burst_size);
lpfc_max_scsicmpl_time_init(vport, lpfc_max_scsicmpl_time);
lpfc_discovery_threads_init(vport, lpfc_discovery_threads);
lpfc_max_luns_init(vport, lpfc_max_luns);
lpfc_scan_down_init(vport, lpfc_scan_down);
lpfc_enable_da_id_init(vport, lpfc_enable_da_id);
return;
}
