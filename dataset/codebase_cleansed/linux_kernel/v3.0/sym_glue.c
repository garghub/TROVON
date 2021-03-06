static void sym2_setup_params(void)
{
char *p = excl_string;
int xi = 0;
while (p && (xi < 8)) {
char *next_p;
int val = (int) simple_strtoul(p, &next_p, 0);
sym_driver_setup.excludes[xi++] = val;
p = next_p;
}
if (safe_string) {
if (*safe_string == 'y') {
sym_driver_setup.max_tag = 0;
sym_driver_setup.burst_order = 0;
sym_driver_setup.scsi_led = 0;
sym_driver_setup.scsi_diff = 1;
sym_driver_setup.irq_mode = 0;
sym_driver_setup.scsi_bus_check = 2;
sym_driver_setup.host_id = 7;
sym_driver_setup.verbose = 2;
sym_driver_setup.settle_delay = 10;
sym_driver_setup.use_nvram = 1;
} else if (*safe_string != 'n') {
printk(KERN_WARNING NAME53C8XX "Ignoring parameter %s"
" passed to safe option", safe_string);
}
}
}
void sym_xpt_done(struct sym_hcb *np, struct scsi_cmnd *cmd)
{
struct sym_ucmd *ucmd = SYM_UCMD_PTR(cmd);
BUILD_BUG_ON(sizeof(struct scsi_pointer) < sizeof(struct sym_ucmd));
if (ucmd->eh_done)
complete(ucmd->eh_done);
scsi_dma_unmap(cmd);
cmd->scsi_done(cmd);
}
void sym_xpt_async_bus_reset(struct sym_hcb *np)
{
printf_notice("%s: SCSI BUS has been reset.\n", sym_name(np));
np->s.settle_time = jiffies + sym_driver_setup.settle_delay * HZ;
np->s.settle_time_valid = 1;
if (sym_verbose >= 2)
printf_info("%s: command processing suspended for %d seconds\n",
sym_name(np), sym_driver_setup.settle_delay);
}
static int sym_xerr_cam_status(int cam_status, int x_status)
{
if (x_status) {
if (x_status & XE_PARITY_ERR)
cam_status = DID_PARITY;
else if (x_status &(XE_EXTRA_DATA|XE_SODL_UNRUN|XE_SWIDE_OVRUN))
cam_status = DID_ERROR;
else if (x_status & XE_BAD_PHASE)
cam_status = DID_ERROR;
else
cam_status = DID_ERROR;
}
return cam_status;
}
void sym_set_cam_result_error(struct sym_hcb *np, struct sym_ccb *cp, int resid)
{
struct scsi_cmnd *cmd = cp->cmd;
u_int cam_status, scsi_status, drv_status;
drv_status = 0;
cam_status = DID_OK;
scsi_status = cp->ssss_status;
if (cp->host_flags & HF_SENSE) {
scsi_status = cp->sv_scsi_status;
resid = cp->sv_resid;
if (sym_verbose && cp->sv_xerr_status)
sym_print_xerr(cmd, cp->sv_xerr_status);
if (cp->host_status == HS_COMPLETE &&
cp->ssss_status == S_GOOD &&
cp->xerr_status == 0) {
cam_status = sym_xerr_cam_status(DID_OK,
cp->sv_xerr_status);
drv_status = DRIVER_SENSE;
memset(cmd->sense_buffer, 0, SCSI_SENSE_BUFFERSIZE);
memcpy(cmd->sense_buffer, cp->sns_bbuf,
min(SCSI_SENSE_BUFFERSIZE, SYM_SNS_BBUF_LEN));
#if 0
if (1) {
u_char *p;
p = (u_char *) cmd->sense_data;
if (p[0]==0x70 && p[2]==0x6 && p[12]==0x29)
sym_clear_tasks(np, DID_ABORT,
cp->target,cp->lun, -1);
}
#endif
} else {
sym_reset_scsi_target(np, cmd->device->id);
cam_status = DID_ERROR;
}
} else if (cp->host_status == HS_COMPLETE)
cam_status = DID_OK;
else if (cp->host_status == HS_SEL_TIMEOUT)
cam_status = DID_NO_CONNECT;
else if (cp->host_status == HS_UNEXPECTED)
cam_status = DID_ERROR;
else {
if (sym_verbose) {
sym_print_addr(cmd, "COMMAND FAILED (%x %x %x).\n",
cp->host_status, cp->ssss_status,
cp->xerr_status);
}
cam_status = sym_xerr_cam_status(DID_ERROR, cp->xerr_status);
}
scsi_set_resid(cmd, resid);
cmd->result = (drv_status << 24) + (cam_status << 16) + scsi_status;
}
static int sym_scatter(struct sym_hcb *np, struct sym_ccb *cp, struct scsi_cmnd *cmd)
{
int segment;
int use_sg;
cp->data_len = 0;
use_sg = scsi_dma_map(cmd);
if (use_sg > 0) {
struct scatterlist *sg;
struct sym_tcb *tp = &np->target[cp->target];
struct sym_tblmove *data;
if (use_sg > SYM_CONF_MAX_SG) {
scsi_dma_unmap(cmd);
return -1;
}
data = &cp->phys.data[SYM_CONF_MAX_SG - use_sg];
scsi_for_each_sg(cmd, sg, use_sg, segment) {
dma_addr_t baddr = sg_dma_address(sg);
unsigned int len = sg_dma_len(sg);
if ((len & 1) && (tp->head.wval & EWS)) {
len++;
cp->odd_byte_adjustment++;
}
sym_build_sge(np, &data[segment], baddr, len);
cp->data_len += len;
}
} else {
segment = -2;
}
return segment;
}
static int sym_queue_command(struct sym_hcb *np, struct scsi_cmnd *cmd)
{
struct scsi_device *sdev = cmd->device;
struct sym_tcb *tp;
struct sym_lcb *lp;
struct sym_ccb *cp;
int order;
tp = &np->target[sdev->id];
lp = sym_lp(tp, sdev->lun);
order = (lp && lp->s.reqtags) ? M_SIMPLE_TAG : 0;
cp = sym_get_ccb(np, cmd, order);
if (!cp)
return 1;
sym_queue_scsiio(np, cmd, cp);
return 0;
}
static inline int sym_setup_cdb(struct sym_hcb *np, struct scsi_cmnd *cmd, struct sym_ccb *cp)
{
memcpy(cp->cdb_buf, cmd->cmnd, cmd->cmd_len);
cp->phys.cmd.addr = CCB_BA(cp, cdb_buf[0]);
cp->phys.cmd.size = cpu_to_scr(cmd->cmd_len);
return 0;
}
int sym_setup_data_and_start(struct sym_hcb *np, struct scsi_cmnd *cmd, struct sym_ccb *cp)
{
u32 lastp, goalp;
int dir;
if (sym_setup_cdb(np, cmd, cp))
goto out_abort;
dir = cmd->sc_data_direction;
if (dir != DMA_NONE) {
cp->segments = sym_scatter(np, cp, cmd);
if (cp->segments < 0) {
sym_set_cam_status(cmd, DID_ERROR);
goto out_abort;
}
if (!cp->segments)
dir = DMA_NONE;
} else {
cp->data_len = 0;
cp->segments = 0;
}
switch (dir) {
case DMA_BIDIRECTIONAL:
scmd_printk(KERN_INFO, cmd, "got DMA_BIDIRECTIONAL command");
sym_set_cam_status(cmd, DID_ERROR);
goto out_abort;
case DMA_TO_DEVICE:
goalp = SCRIPTA_BA(np, data_out2) + 8;
lastp = goalp - 8 - (cp->segments * (2*4));
break;
case DMA_FROM_DEVICE:
cp->host_flags |= HF_DATA_IN;
goalp = SCRIPTA_BA(np, data_in2) + 8;
lastp = goalp - 8 - (cp->segments * (2*4));
break;
case DMA_NONE:
default:
lastp = goalp = SCRIPTB_BA(np, no_data);
break;
}
cp->phys.head.lastp = cpu_to_scr(lastp);
cp->phys.head.savep = cpu_to_scr(lastp);
cp->startp = cp->phys.head.savep;
cp->goalp = cpu_to_scr(goalp);
#if 0
switch (cp->cdb_buf[0]) {
case 0x0A: case 0x2A: case 0xAA:
panic("XXXXXXXXXXXXX WRITE NOT YET ALLOWED XXXXXXXXXXXXXX\n");
break;
default:
break;
}
#endif
sym_put_start_queue(np, cp);
return 0;
out_abort:
sym_free_ccb(np, cp);
sym_xpt_done(np, cmd);
return 0;
}
static void sym_timer(struct sym_hcb *np)
{
unsigned long thistime = jiffies;
np->s.timer.expires = thistime + SYM_CONF_TIMER_INTERVAL;
add_timer(&np->s.timer);
if (np->s.settle_time_valid) {
if (time_before_eq(np->s.settle_time, thistime)) {
if (sym_verbose >= 2 )
printk("%s: command processing resumed\n",
sym_name(np));
np->s.settle_time_valid = 0;
}
return;
}
if (np->s.lasttime + 4*HZ < thistime) {
np->s.lasttime = thistime;
}
#ifdef SYM_CONF_PCIQ_MAY_MISS_COMPLETIONS
sym_wakeup_done(np);
#endif
}
void sym_log_bus_error(struct Scsi_Host *shost)
{
struct sym_data *sym_data = shost_priv(shost);
struct pci_dev *pdev = sym_data->pdev;
unsigned short pci_sts;
pci_read_config_word(pdev, PCI_STATUS, &pci_sts);
if (pci_sts & 0xf900) {
pci_write_config_word(pdev, PCI_STATUS, pci_sts);
shost_printk(KERN_WARNING, shost,
"PCI bus error: status = 0x%04x\n", pci_sts & 0xf900);
}
}
static int sym53c8xx_queue_command_lck(struct scsi_cmnd *cmd,
void (*done)(struct scsi_cmnd *))
{
struct sym_hcb *np = SYM_SOFTC_PTR(cmd);
struct sym_ucmd *ucp = SYM_UCMD_PTR(cmd);
int sts = 0;
cmd->scsi_done = done;
memset(ucp, 0, sizeof(*ucp));
if (np->s.settle_time_valid && cmd->request->timeout) {
unsigned long tlimit = jiffies + cmd->request->timeout;
tlimit -= SYM_CONF_TIMER_INTERVAL*2;
if (time_after(np->s.settle_time, tlimit)) {
np->s.settle_time = tlimit;
}
}
if (np->s.settle_time_valid)
return SCSI_MLQUEUE_HOST_BUSY;
sts = sym_queue_command(np, cmd);
if (sts)
return SCSI_MLQUEUE_HOST_BUSY;
return 0;
}
void sym53c8xx_timer(unsigned long npref)
{
struct sym_hcb *np = (struct sym_hcb *)npref;
unsigned long flags;
spin_lock_irqsave(np->s.host->host_lock, flags);
sym_timer(np);
spin_unlock_irqrestore(np->s.host->host_lock, flags);
}
static int sym_eh_handler(int op, char *opname, struct scsi_cmnd *cmd)
{
struct sym_ucmd *ucmd = SYM_UCMD_PTR(cmd);
struct Scsi_Host *shost = cmd->device->host;
struct sym_data *sym_data = shost_priv(shost);
struct pci_dev *pdev = sym_data->pdev;
struct sym_hcb *np = sym_data->ncb;
SYM_QUEHEAD *qp;
int cmd_queued = 0;
int sts = -1;
struct completion eh_done;
scmd_printk(KERN_WARNING, cmd, "%s operation started\n", opname);
#define WAIT_FOR_PCI_RECOVERY 35
if (pci_channel_offline(pdev)) {
int finished_reset = 0;
init_completion(&eh_done);
spin_lock_irq(shost->host_lock);
if (pci_channel_offline(pdev)) {
BUG_ON(sym_data->io_reset);
sym_data->io_reset = &eh_done;
} else {
finished_reset = 1;
}
spin_unlock_irq(shost->host_lock);
if (!finished_reset)
finished_reset = wait_for_completion_timeout
(sym_data->io_reset,
WAIT_FOR_PCI_RECOVERY*HZ);
spin_lock_irq(shost->host_lock);
sym_data->io_reset = NULL;
spin_unlock_irq(shost->host_lock);
if (!finished_reset)
return SCSI_FAILED;
}
spin_lock_irq(shost->host_lock);
FOR_EACH_QUEUED_ELEMENT(&np->busy_ccbq, qp) {
struct sym_ccb *cp = sym_que_entry(qp, struct sym_ccb, link_ccbq);
if (cp->cmd == cmd) {
cmd_queued = 1;
break;
}
}
sts = -1;
switch(op) {
case SYM_EH_ABORT:
sts = sym_abort_scsiio(np, cmd, 1);
break;
case SYM_EH_DEVICE_RESET:
sts = sym_reset_scsi_target(np, cmd->device->id);
break;
case SYM_EH_BUS_RESET:
sym_reset_scsi_bus(np, 1);
sts = 0;
break;
case SYM_EH_HOST_RESET:
sym_reset_scsi_bus(np, 0);
sym_start_up(shost, 1);
sts = 0;
break;
default:
break;
}
if (sts)
cmd_queued = 0;
if (cmd_queued) {
init_completion(&eh_done);
ucmd->eh_done = &eh_done;
spin_unlock_irq(shost->host_lock);
if (!wait_for_completion_timeout(&eh_done, 5*HZ)) {
ucmd->eh_done = NULL;
sts = -2;
}
} else {
spin_unlock_irq(shost->host_lock);
}
dev_warn(&cmd->device->sdev_gendev, "%s operation %s.\n", opname,
sts==0 ? "complete" :sts==-2 ? "timed-out" : "failed");
return sts ? SCSI_FAILED : SCSI_SUCCESS;
}
static int sym53c8xx_eh_abort_handler(struct scsi_cmnd *cmd)
{
return sym_eh_handler(SYM_EH_ABORT, "ABORT", cmd);
}
static int sym53c8xx_eh_device_reset_handler(struct scsi_cmnd *cmd)
{
return sym_eh_handler(SYM_EH_DEVICE_RESET, "DEVICE RESET", cmd);
}
static int sym53c8xx_eh_bus_reset_handler(struct scsi_cmnd *cmd)
{
return sym_eh_handler(SYM_EH_BUS_RESET, "BUS RESET", cmd);
}
static int sym53c8xx_eh_host_reset_handler(struct scsi_cmnd *cmd)
{
return sym_eh_handler(SYM_EH_HOST_RESET, "HOST RESET", cmd);
}
static void sym_tune_dev_queuing(struct sym_tcb *tp, int lun, u_short reqtags)
{
struct sym_lcb *lp = sym_lp(tp, lun);
u_short oldtags;
if (!lp)
return;
oldtags = lp->s.reqtags;
if (reqtags > lp->s.scdev_depth)
reqtags = lp->s.scdev_depth;
lp->s.reqtags = reqtags;
if (reqtags != oldtags) {
dev_info(&tp->starget->dev,
"tagged command queuing %s, command queue depth %d.\n",
lp->s.reqtags ? "enabled" : "disabled", reqtags);
}
}
static int sym53c8xx_slave_alloc(struct scsi_device *sdev)
{
struct sym_hcb *np = sym_get_hcb(sdev->host);
struct sym_tcb *tp = &np->target[sdev->id];
struct sym_lcb *lp;
unsigned long flags;
int error;
if (sdev->id >= SYM_CONF_MAX_TARGET || sdev->lun >= SYM_CONF_MAX_LUN)
return -ENXIO;
spin_lock_irqsave(np->s.host->host_lock, flags);
if (tp->usrflags & SYM_SCAN_BOOT_DISABLED) {
tp->usrflags &= ~SYM_SCAN_BOOT_DISABLED;
starget_printk(KERN_INFO, sdev->sdev_target,
"Scan at boot disabled in NVRAM\n");
error = -ENXIO;
goto out;
}
if (tp->usrflags & SYM_SCAN_LUNS_DISABLED) {
if (sdev->lun != 0) {
error = -ENXIO;
goto out;
}
starget_printk(KERN_INFO, sdev->sdev_target,
"Multiple LUNs disabled in NVRAM\n");
}
lp = sym_alloc_lcb(np, sdev->id, sdev->lun);
if (!lp) {
error = -ENOMEM;
goto out;
}
if (tp->nlcb == 1)
tp->starget = sdev->sdev_target;
spi_min_period(tp->starget) = tp->usr_period;
spi_max_width(tp->starget) = tp->usr_width;
error = 0;
out:
spin_unlock_irqrestore(np->s.host->host_lock, flags);
return error;
}
static int sym53c8xx_slave_configure(struct scsi_device *sdev)
{
struct sym_hcb *np = sym_get_hcb(sdev->host);
struct sym_tcb *tp = &np->target[sdev->id];
struct sym_lcb *lp = sym_lp(tp, sdev->lun);
int reqtags, depth_to_use;
lp->curr_flags = lp->user_flags;
reqtags = sym_driver_setup.max_tag;
if (reqtags > tp->usrtags)
reqtags = tp->usrtags;
if (!sdev->tagged_supported)
reqtags = 0;
if (reqtags > SYM_CONF_MAX_TAG)
reqtags = SYM_CONF_MAX_TAG;
depth_to_use = reqtags ? reqtags : 1;
scsi_adjust_queue_depth(sdev,
sdev->tagged_supported ? MSG_SIMPLE_TAG : 0,
depth_to_use);
lp->s.scdev_depth = depth_to_use;
sym_tune_dev_queuing(tp, sdev->lun, reqtags);
if (!spi_initial_dv(sdev->sdev_target))
spi_dv_device(sdev);
return 0;
}
static void sym53c8xx_slave_destroy(struct scsi_device *sdev)
{
struct sym_hcb *np = sym_get_hcb(sdev->host);
struct sym_tcb *tp = &np->target[sdev->id];
struct sym_lcb *lp = sym_lp(tp, sdev->lun);
unsigned long flags;
spin_lock_irqsave(np->s.host->host_lock, flags);
if (lp->busy_itlq || lp->busy_itl) {
starget_printk(KERN_WARNING, tp->starget,
"Removing busy LCB (%d)\n", sdev->lun);
sym_reset_scsi_bus(np, 1);
}
if (sym_free_lcb(np, sdev->id, sdev->lun) == 0) {
tp->head.sval = 0;
tp->head.wval = np->rv_scntl3;
tp->head.uval = 0;
tp->tgoal.check_nego = 1;
tp->starget = NULL;
}
spin_unlock_irqrestore(np->s.host->host_lock, flags);
}
static const char *sym53c8xx_info (struct Scsi_Host *host)
{
return SYM_DRIVER_NAME;
}
static void sym_exec_user_command (struct sym_hcb *np, struct sym_usrcmd *uc)
{
struct sym_tcb *tp;
int t, l;
switch (uc->cmd) {
case 0: return;
#ifdef SYM_LINUX_DEBUG_CONTROL_SUPPORT
case UC_SETDEBUG:
sym_debug_flags = uc->data;
break;
#endif
case UC_SETVERBOSE:
np->verbose = uc->data;
break;
default:
for (t = 0; t < SYM_CONF_MAX_TARGET; t++) {
if (!((uc->target >> t) & 1))
continue;
tp = &np->target[t];
if (!tp->nlcb)
continue;
switch (uc->cmd) {
case UC_SETSYNC:
if (!uc->data || uc->data >= 255) {
tp->tgoal.iu = tp->tgoal.dt =
tp->tgoal.qas = 0;
tp->tgoal.offset = 0;
} else if (uc->data <= 9 && np->minsync_dt) {
if (uc->data < np->minsync_dt)
uc->data = np->minsync_dt;
tp->tgoal.iu = tp->tgoal.dt =
tp->tgoal.qas = 1;
tp->tgoal.width = 1;
tp->tgoal.period = uc->data;
tp->tgoal.offset = np->maxoffs_dt;
} else {
if (uc->data < np->minsync)
uc->data = np->minsync;
tp->tgoal.iu = tp->tgoal.dt =
tp->tgoal.qas = 0;
tp->tgoal.period = uc->data;
tp->tgoal.offset = np->maxoffs;
}
tp->tgoal.check_nego = 1;
break;
case UC_SETWIDE:
tp->tgoal.width = uc->data ? 1 : 0;
tp->tgoal.check_nego = 1;
break;
case UC_SETTAGS:
for (l = 0; l < SYM_CONF_MAX_LUN; l++)
sym_tune_dev_queuing(tp, l, uc->data);
break;
case UC_RESETDEV:
tp->to_reset = 1;
np->istat_sem = SEM;
OUTB(np, nc_istat, SIGP|SEM);
break;
case UC_CLEARDEV:
for (l = 0; l < SYM_CONF_MAX_LUN; l++) {
struct sym_lcb *lp = sym_lp(tp, l);
if (lp) lp->to_clear = 1;
}
np->istat_sem = SEM;
OUTB(np, nc_istat, SIGP|SEM);
break;
case UC_SETFLAG:
tp->usrflags = uc->data;
break;
}
}
break;
}
}
static int sym_skip_spaces(char *ptr, int len)
{
int cnt, c;
for (cnt = len; cnt > 0 && (c = *ptr++) && isspace(c); cnt--);
return (len - cnt);
}
static int get_int_arg(char *ptr, int len, u_long *pv)
{
char *end;
*pv = simple_strtoul(ptr, &end, 10);
return (end - ptr);
}
static int is_keyword(char *ptr, int len, char *verb)
{
int verb_len = strlen(verb);
if (len >= verb_len && !memcmp(verb, ptr, verb_len))
return verb_len;
else
return 0;
}
static int sym_user_command(struct Scsi_Host *shost, char *buffer, int length)
{
struct sym_hcb *np = sym_get_hcb(shost);
char *ptr = buffer;
int len = length;
struct sym_usrcmd cmd, *uc = &cmd;
int arg_len;
u_long target;
memset(uc, 0, sizeof(*uc));
if (len > 0 && ptr[len-1] == '\n')
--len;
if ((arg_len = is_keyword(ptr, len, "setsync")) != 0)
uc->cmd = UC_SETSYNC;
else if ((arg_len = is_keyword(ptr, len, "settags")) != 0)
uc->cmd = UC_SETTAGS;
else if ((arg_len = is_keyword(ptr, len, "setverbose")) != 0)
uc->cmd = UC_SETVERBOSE;
else if ((arg_len = is_keyword(ptr, len, "setwide")) != 0)
uc->cmd = UC_SETWIDE;
#ifdef SYM_LINUX_DEBUG_CONTROL_SUPPORT
else if ((arg_len = is_keyword(ptr, len, "setdebug")) != 0)
uc->cmd = UC_SETDEBUG;
#endif
else if ((arg_len = is_keyword(ptr, len, "setflag")) != 0)
uc->cmd = UC_SETFLAG;
else if ((arg_len = is_keyword(ptr, len, "resetdev")) != 0)
uc->cmd = UC_RESETDEV;
else if ((arg_len = is_keyword(ptr, len, "cleardev")) != 0)
uc->cmd = UC_CLEARDEV;
else
arg_len = 0;
#ifdef DEBUG_PROC_INFO
printk("sym_user_command: arg_len=%d, cmd=%ld\n", arg_len, uc->cmd);
#endif
if (!arg_len)
return -EINVAL;
ptr += arg_len; len -= arg_len;
switch(uc->cmd) {
case UC_SETSYNC:
case UC_SETTAGS:
case UC_SETWIDE:
case UC_SETFLAG:
case UC_RESETDEV:
case UC_CLEARDEV:
SKIP_SPACES(ptr, len);
if ((arg_len = is_keyword(ptr, len, "all")) != 0) {
ptr += arg_len; len -= arg_len;
uc->target = ~0;
} else {
GET_INT_ARG(ptr, len, target);
uc->target = (1<<target);
#ifdef DEBUG_PROC_INFO
printk("sym_user_command: target=%ld\n", target);
#endif
}
break;
}
switch(uc->cmd) {
case UC_SETVERBOSE:
case UC_SETSYNC:
case UC_SETTAGS:
case UC_SETWIDE:
SKIP_SPACES(ptr, len);
GET_INT_ARG(ptr, len, uc->data);
#ifdef DEBUG_PROC_INFO
printk("sym_user_command: data=%ld\n", uc->data);
#endif
break;
#ifdef SYM_LINUX_DEBUG_CONTROL_SUPPORT
case UC_SETDEBUG:
while (len > 0) {
SKIP_SPACES(ptr, len);
if ((arg_len = is_keyword(ptr, len, "alloc")))
uc->data |= DEBUG_ALLOC;
else if ((arg_len = is_keyword(ptr, len, "phase")))
uc->data |= DEBUG_PHASE;
else if ((arg_len = is_keyword(ptr, len, "queue")))
uc->data |= DEBUG_QUEUE;
else if ((arg_len = is_keyword(ptr, len, "result")))
uc->data |= DEBUG_RESULT;
else if ((arg_len = is_keyword(ptr, len, "scatter")))
uc->data |= DEBUG_SCATTER;
else if ((arg_len = is_keyword(ptr, len, "script")))
uc->data |= DEBUG_SCRIPT;
else if ((arg_len = is_keyword(ptr, len, "tiny")))
uc->data |= DEBUG_TINY;
else if ((arg_len = is_keyword(ptr, len, "timing")))
uc->data |= DEBUG_TIMING;
else if ((arg_len = is_keyword(ptr, len, "nego")))
uc->data |= DEBUG_NEGO;
else if ((arg_len = is_keyword(ptr, len, "tags")))
uc->data |= DEBUG_TAGS;
else if ((arg_len = is_keyword(ptr, len, "pointer")))
uc->data |= DEBUG_POINTER;
else
return -EINVAL;
ptr += arg_len; len -= arg_len;
}
#ifdef DEBUG_PROC_INFO
printk("sym_user_command: data=%ld\n", uc->data);
#endif
break;
#endif
case UC_SETFLAG:
while (len > 0) {
SKIP_SPACES(ptr, len);
if ((arg_len = is_keyword(ptr, len, "no_disc")))
uc->data &= ~SYM_DISC_ENABLED;
else
return -EINVAL;
ptr += arg_len; len -= arg_len;
}
break;
default:
break;
}
if (len)
return -EINVAL;
else {
unsigned long flags;
spin_lock_irqsave(shost->host_lock, flags);
sym_exec_user_command(np, uc);
spin_unlock_irqrestore(shost->host_lock, flags);
}
return length;
}
static void copy_mem_info(struct info_str *info, char *data, int len)
{
if (info->pos + len > info->length)
len = info->length - info->pos;
if (info->pos + len < info->offset) {
info->pos += len;
return;
}
if (info->pos < info->offset) {
data += (info->offset - info->pos);
len -= (info->offset - info->pos);
}
if (len > 0) {
memcpy(info->buffer + info->pos, data, len);
info->pos += len;
}
}
static int copy_info(struct info_str *info, char *fmt, ...)
{
va_list args;
char buf[81];
int len;
va_start(args, fmt);
len = vsprintf(buf, fmt, args);
va_end(args);
copy_mem_info(info, buf, len);
return len;
}
static int sym_host_info(struct Scsi_Host *shost, char *ptr, off_t offset, int len)
{
struct sym_data *sym_data = shost_priv(shost);
struct pci_dev *pdev = sym_data->pdev;
struct sym_hcb *np = sym_data->ncb;
struct info_str info;
info.buffer = ptr;
info.length = len;
info.offset = offset;
info.pos = 0;
copy_info(&info, "Chip " NAME53C "%s, device id 0x%x, "
"revision id 0x%x\n", np->s.chip_name,
pdev->device, pdev->revision);
copy_info(&info, "At PCI address %s, IRQ %u\n",
pci_name(pdev), pdev->irq);
copy_info(&info, "Min. period factor %d, %s SCSI BUS%s\n",
(int) (np->minsync_dt ? np->minsync_dt : np->minsync),
np->maxwide ? "Wide" : "Narrow",
np->minsync_dt ? ", DT capable" : "");
copy_info(&info, "Max. started commands %d, "
"max. commands per LUN %d\n",
SYM_CONF_MAX_START, SYM_CONF_MAX_TAG);
return info.pos > info.offset? info.pos - info.offset : 0;
}
static int sym53c8xx_proc_info(struct Scsi_Host *shost, char *buffer,
char **start, off_t offset, int length, int func)
{
int retv;
if (func) {
#ifdef SYM_LINUX_USER_COMMAND_SUPPORT
retv = sym_user_command(shost, buffer, length);
#else
retv = -EINVAL;
#endif
} else {
if (start)
*start = buffer;
#ifdef SYM_LINUX_USER_INFO_SUPPORT
retv = sym_host_info(shost, buffer, offset, length);
#else
retv = -EINVAL;
#endif
}
return retv;
}
static void __devinit
sym_iounmap_device(struct sym_device *device)
{
if (device->s.ioaddr)
pci_iounmap(device->pdev, device->s.ioaddr);
if (device->s.ramaddr)
pci_iounmap(device->pdev, device->s.ramaddr);
}
static void sym_free_resources(struct sym_hcb *np, struct pci_dev *pdev,
int do_free_irq)
{
if (do_free_irq)
free_irq(pdev->irq, np->s.host);
if (np->s.ioaddr)
pci_iounmap(pdev, np->s.ioaddr);
if (np->s.ramaddr)
pci_iounmap(pdev, np->s.ramaddr);
sym_hcb_free(np);
sym_mfree_dma(np, sizeof(*np), "HCB");
}
static struct Scsi_Host * __devinit sym_attach(struct scsi_host_template *tpnt,
int unit, struct sym_device *dev)
{
struct sym_data *sym_data;
struct sym_hcb *np = NULL;
struct Scsi_Host *shost = NULL;
struct pci_dev *pdev = dev->pdev;
unsigned long flags;
struct sym_fw *fw;
int do_free_irq = 0;
printk(KERN_INFO "sym%d: <%s> rev 0x%x at pci %s irq %u\n",
unit, dev->chip.name, pdev->revision, pci_name(pdev),
pdev->irq);
fw = sym_find_firmware(&dev->chip);
if (!fw)
goto attach_failed;
shost = scsi_host_alloc(tpnt, sizeof(*sym_data));
if (!shost)
goto attach_failed;
sym_data = shost_priv(shost);
np = __sym_calloc_dma(&pdev->dev, sizeof(*np), "HCB");
if (!np)
goto attach_failed;
np->bus_dmat = &pdev->dev;
sym_data->ncb = np;
sym_data->pdev = pdev;
np->s.host = shost;
pci_set_drvdata(pdev, shost);
np->hcb_ba = vtobus(np);
np->verbose = sym_driver_setup.verbose;
np->s.unit = unit;
np->features = dev->chip.features;
np->clock_divn = dev->chip.nr_divisor;
np->maxoffs = dev->chip.offset_max;
np->maxburst = dev->chip.burst_max;
np->myaddr = dev->host_id;
np->mmio_ba = (u32)dev->mmio_base;
np->ram_ba = (u32)dev->ram_base;
np->s.ioaddr = dev->s.ioaddr;
np->s.ramaddr = dev->s.ramaddr;
strlcpy(np->s.chip_name, dev->chip.name, sizeof(np->s.chip_name));
sprintf(np->s.inst_name, "sym%d", np->s.unit);
if ((SYM_CONF_DMA_ADDRESSING_MODE > 0) && (np->features & FE_DAC) &&
!pci_set_dma_mask(pdev, DMA_DAC_MASK)) {
set_dac(np);
} else if (pci_set_dma_mask(pdev, DMA_BIT_MASK(32))) {
printf_warning("%s: No suitable DMA available\n", sym_name(np));
goto attach_failed;
}
if (sym_hcb_attach(shost, fw, dev->nvram))
goto attach_failed;
if (request_irq(pdev->irq, sym53c8xx_intr, IRQF_SHARED, NAME53C8XX,
shost)) {
printf_err("%s: request irq %u failure\n",
sym_name(np), pdev->irq);
goto attach_failed;
}
do_free_irq = 1;
spin_lock_irqsave(shost->host_lock, flags);
if (sym_reset_scsi_bus(np, 0))
goto reset_failed;
sym_start_up(shost, 1);
init_timer(&np->s.timer);
np->s.timer.data = (unsigned long) np;
np->s.timer.function = sym53c8xx_timer;
np->s.lasttime=0;
sym_timer (np);
shost->max_channel = 0;
shost->this_id = np->myaddr;
shost->max_id = np->maxwide ? 16 : 8;
shost->max_lun = SYM_CONF_MAX_LUN;
shost->unique_id = pci_resource_start(pdev, 0);
shost->cmd_per_lun = SYM_CONF_MAX_TAG;
shost->can_queue = (SYM_CONF_MAX_START-2);
shost->sg_tablesize = SYM_CONF_MAX_SG;
shost->max_cmd_len = 16;
BUG_ON(sym2_transport_template == NULL);
shost->transportt = sym2_transport_template;
if (pdev->device == PCI_DEVICE_ID_NCR_53C896 && pdev->revision < 2)
shost->dma_boundary = 0xFFFFFF;
spin_unlock_irqrestore(shost->host_lock, flags);
return shost;
reset_failed:
printf_err("%s: FATAL ERROR: CHECK SCSI BUS - CABLES, "
"TERMINATION, DEVICE POWER etc.!\n", sym_name(np));
spin_unlock_irqrestore(shost->host_lock, flags);
attach_failed:
printf_info("sym%d: giving up ...\n", unit);
if (np)
sym_free_resources(np, pdev, do_free_irq);
else
sym_iounmap_device(dev);
if (shost)
scsi_host_put(shost);
return NULL;
}
static void __devinit sym_get_nvram(struct sym_device *devp, struct sym_nvram *nvp)
{
devp->nvram = nvp;
nvp->type = 0;
sym_read_nvram(devp, nvp);
}
static inline void sym_get_nvram(struct sym_device *devp, struct sym_nvram *nvp)
{
}
static int __devinit sym_check_supported(struct sym_device *device)
{
struct sym_chip *chip;
struct pci_dev *pdev = device->pdev;
unsigned long io_port = pci_resource_start(pdev, 0);
int i;
if (io_port) {
for (i = 0 ; i < 8 ; i++) {
if (sym_driver_setup.excludes[i] == io_port)
return -ENODEV;
}
}
chip = sym_lookup_chip_table(pdev->device, pdev->revision);
if (!chip) {
dev_info(&pdev->dev, "device not supported\n");
return -ENODEV;
}
memcpy(&device->chip, chip, sizeof(device->chip));
return 0;
}
static int __devinit sym_check_raid(struct sym_device *device)
{
unsigned int ram_size, ram_val;
if (!device->s.ramaddr)
return 0;
if (device->chip.features & FE_RAM8K)
ram_size = 8192;
else
ram_size = 4096;
ram_val = readl(device->s.ramaddr + ram_size - 16);
if (ram_val != 0x52414944)
return 0;
dev_info(&device->pdev->dev,
"not initializing, driven by RAID controller.\n");
return -ENODEV;
}
static int __devinit sym_set_workarounds(struct sym_device *device)
{
struct sym_chip *chip = &device->chip;
struct pci_dev *pdev = device->pdev;
u_short status_reg;
if (pdev->device == PCI_DEVICE_ID_NCR_53C896 && pdev->revision < 0x4) {
chip->features |= (FE_WRIE | FE_CLSE);
}
if (chip->features & FE_WRIE) {
if (pci_set_mwi(pdev))
return -ENODEV;
}
pci_read_config_word(pdev, PCI_STATUS, &status_reg);
if (chip->features & FE_66MHZ) {
if (!(status_reg & PCI_STATUS_66MHZ))
chip->features &= ~FE_66MHZ;
} else {
if (status_reg & PCI_STATUS_66MHZ) {
status_reg = PCI_STATUS_66MHZ;
pci_write_config_word(pdev, PCI_STATUS, status_reg);
pci_read_config_word(pdev, PCI_STATUS, &status_reg);
}
}
return 0;
}
static int __devinit
sym_iomap_device(struct sym_device *device)
{
struct pci_dev *pdev = device->pdev;
struct pci_bus_region bus_addr;
int i = 2;
pcibios_resource_to_bus(pdev, &bus_addr, &pdev->resource[1]);
device->mmio_base = bus_addr.start;
if (device->chip.features & FE_RAM) {
if (!pdev->resource[i].flags)
i++;
pcibios_resource_to_bus(pdev, &bus_addr, &pdev->resource[i]);
device->ram_base = bus_addr.start;
}
#ifdef CONFIG_SCSI_SYM53C8XX_MMIO
if (device->mmio_base)
device->s.ioaddr = pci_iomap(pdev, 1,
pci_resource_len(pdev, 1));
#endif
if (!device->s.ioaddr)
device->s.ioaddr = pci_iomap(pdev, 0,
pci_resource_len(pdev, 0));
if (!device->s.ioaddr) {
dev_err(&pdev->dev, "could not map registers; giving up.\n");
return -EIO;
}
if (device->ram_base) {
device->s.ramaddr = pci_iomap(pdev, i,
pci_resource_len(pdev, i));
if (!device->s.ramaddr) {
dev_warn(&pdev->dev,
"could not map SRAM; continuing anyway.\n");
device->ram_base = 0;
}
}
return 0;
}
static void sym_config_pqs(struct pci_dev *pdev, struct sym_device *sym_dev)
{
int slot;
u8 tmp;
for (slot = 0; slot < 256; slot++) {
struct pci_dev *memc = pci_get_slot(pdev->bus, slot);
if (!memc || memc->vendor != 0x101a || memc->device == 0x0009) {
pci_dev_put(memc);
continue;
}
pci_read_config_byte(memc, 0x44, &tmp);
if ((tmp & 0x2) == 0) {
tmp |= 0x2;
pci_write_config_byte(memc, 0x44, tmp);
}
pci_read_config_byte(memc, 0x45, &tmp);
if ((tmp & 0x4) == 0) {
tmp |= 0x4;
pci_write_config_byte(memc, 0x45, tmp);
}
pci_dev_put(memc);
break;
}
pci_read_config_byte(pdev, 0x84, &tmp);
sym_dev->host_id = tmp;
}
static int sym_detach(struct Scsi_Host *shost, struct pci_dev *pdev)
{
struct sym_hcb *np = sym_get_hcb(shost);
printk("%s: detaching ...\n", sym_name(np));
del_timer_sync(&np->s.timer);
printk("%s: resetting chip\n", sym_name(np));
OUTB(np, nc_istat, SRST);
INB(np, nc_mbox1);
udelay(10);
OUTB(np, nc_istat, 0);
sym_free_resources(np, pdev, 1);
scsi_host_put(shost);
return 1;
}
static int __devinit sym2_probe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
struct sym_device sym_dev;
struct sym_nvram nvram;
struct Scsi_Host *shost;
int do_iounmap = 0;
int do_disable_device = 1;
memset(&sym_dev, 0, sizeof(sym_dev));
memset(&nvram, 0, sizeof(nvram));
sym_dev.pdev = pdev;
sym_dev.host_id = SYM_SETUP_HOST_ID;
if (pci_enable_device(pdev))
goto leave;
pci_set_master(pdev);
if (pci_request_regions(pdev, NAME53C8XX))
goto disable;
if (sym_check_supported(&sym_dev))
goto free;
if (sym_iomap_device(&sym_dev))
goto free;
do_iounmap = 1;
if (sym_check_raid(&sym_dev)) {
do_disable_device = 0;
goto free;
}
if (sym_set_workarounds(&sym_dev))
goto free;
sym_config_pqs(pdev, &sym_dev);
sym_get_nvram(&sym_dev, &nvram);
do_iounmap = 0;
shost = sym_attach(&sym2_template, attach_count, &sym_dev);
if (!shost)
goto free;
if (scsi_add_host(shost, &pdev->dev))
goto detach;
scsi_scan_host(shost);
attach_count++;
return 0;
detach:
sym_detach(pci_get_drvdata(pdev), pdev);
free:
if (do_iounmap)
sym_iounmap_device(&sym_dev);
pci_release_regions(pdev);
disable:
if (do_disable_device)
pci_disable_device(pdev);
leave:
return -ENODEV;
}
static void sym2_remove(struct pci_dev *pdev)
{
struct Scsi_Host *shost = pci_get_drvdata(pdev);
scsi_remove_host(shost);
sym_detach(shost, pdev);
pci_release_regions(pdev);
pci_disable_device(pdev);
attach_count--;
}
static pci_ers_result_t sym2_io_error_detected(struct pci_dev *pdev,
enum pci_channel_state state)
{
if (state == pci_channel_io_perm_failure) {
sym2_remove(pdev);
return PCI_ERS_RESULT_DISCONNECT;
}
disable_irq(pdev->irq);
pci_disable_device(pdev);
return PCI_ERS_RESULT_CAN_RECOVER;
}
static pci_ers_result_t sym2_io_slot_dump(struct pci_dev *pdev)
{
struct Scsi_Host *shost = pci_get_drvdata(pdev);
sym_dump_registers(shost);
return PCI_ERS_RESULT_NEED_RESET;
}
static void sym2_reset_workarounds(struct pci_dev *pdev)
{
u_short status_reg;
struct sym_chip *chip;
chip = sym_lookup_chip_table(pdev->device, pdev->revision);
pci_read_config_word(pdev, PCI_STATUS, &status_reg);
if (!(chip->features & FE_66MHZ) && (status_reg & PCI_STATUS_66MHZ)) {
status_reg = PCI_STATUS_66MHZ;
pci_write_config_word(pdev, PCI_STATUS, status_reg);
pci_read_config_word(pdev, PCI_STATUS, &status_reg);
}
}
static pci_ers_result_t sym2_io_slot_reset(struct pci_dev *pdev)
{
struct Scsi_Host *shost = pci_get_drvdata(pdev);
struct sym_hcb *np = sym_get_hcb(shost);
printk(KERN_INFO "%s: recovering from a PCI slot reset\n",
sym_name(np));
if (pci_enable_device(pdev)) {
printk(KERN_ERR "%s: Unable to enable after PCI reset\n",
sym_name(np));
return PCI_ERS_RESULT_DISCONNECT;
}
pci_set_master(pdev);
enable_irq(pdev->irq);
if (np->features & FE_WRIE) {
if (pci_set_mwi(pdev))
return PCI_ERS_RESULT_DISCONNECT;
}
sym2_reset_workarounds(pdev);
if (PCI_FUNC(pdev->devfn) == 0) {
if (sym_reset_scsi_bus(np, 0)) {
printk(KERN_ERR "%s: Unable to reset scsi host\n",
sym_name(np));
return PCI_ERS_RESULT_DISCONNECT;
}
sym_start_up(shost, 1);
}
return PCI_ERS_RESULT_RECOVERED;
}
static void sym2_io_resume(struct pci_dev *pdev)
{
struct Scsi_Host *shost = pci_get_drvdata(pdev);
struct sym_data *sym_data = shost_priv(shost);
spin_lock_irq(shost->host_lock);
if (sym_data->io_reset)
complete_all(sym_data->io_reset);
spin_unlock_irq(shost->host_lock);
}
static void sym2_get_signalling(struct Scsi_Host *shost)
{
struct sym_hcb *np = sym_get_hcb(shost);
enum spi_signal_type type;
switch (np->scsi_mode) {
case SMODE_SE:
type = SPI_SIGNAL_SE;
break;
case SMODE_LVD:
type = SPI_SIGNAL_LVD;
break;
case SMODE_HVD:
type = SPI_SIGNAL_HVD;
break;
default:
type = SPI_SIGNAL_UNKNOWN;
break;
}
spi_signalling(shost) = type;
}
static void sym2_set_offset(struct scsi_target *starget, int offset)
{
struct Scsi_Host *shost = dev_to_shost(starget->dev.parent);
struct sym_hcb *np = sym_get_hcb(shost);
struct sym_tcb *tp = &np->target[starget->id];
tp->tgoal.offset = offset;
tp->tgoal.check_nego = 1;
}
static void sym2_set_period(struct scsi_target *starget, int period)
{
struct Scsi_Host *shost = dev_to_shost(starget->dev.parent);
struct sym_hcb *np = sym_get_hcb(shost);
struct sym_tcb *tp = &np->target[starget->id];
if (period <= np->minsync && spi_width(starget))
tp->tgoal.dt = 1;
tp->tgoal.period = period;
tp->tgoal.check_nego = 1;
}
static void sym2_set_width(struct scsi_target *starget, int width)
{
struct Scsi_Host *shost = dev_to_shost(starget->dev.parent);
struct sym_hcb *np = sym_get_hcb(shost);
struct sym_tcb *tp = &np->target[starget->id];
if (width == 0)
tp->tgoal.iu = tp->tgoal.dt = tp->tgoal.qas = 0;
tp->tgoal.width = width;
tp->tgoal.check_nego = 1;
}
static void sym2_set_dt(struct scsi_target *starget, int dt)
{
struct Scsi_Host *shost = dev_to_shost(starget->dev.parent);
struct sym_hcb *np = sym_get_hcb(shost);
struct sym_tcb *tp = &np->target[starget->id];
if (dt)
tp->tgoal.dt = 1;
else
tp->tgoal.iu = tp->tgoal.dt = tp->tgoal.qas = 0;
tp->tgoal.check_nego = 1;
}
static int __init sym2_init(void)
{
int error;
sym2_setup_params();
sym2_transport_template = spi_attach_transport(&sym2_transport_functions);
if (!sym2_transport_template)
return -ENODEV;
error = pci_register_driver(&sym2_driver);
if (error)
spi_release_transport(sym2_transport_template);
return error;
}
static void __exit sym2_exit(void)
{
pci_unregister_driver(&sym2_driver);
spi_release_transport(sym2_transport_template);
}
