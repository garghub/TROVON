static inline enum ufs_dev_pwr_mode
ufs_get_pm_lvl_to_dev_pwr_mode(enum ufs_pm_level lvl)
{
return ufs_pm_lvl_states[lvl].dev_state;
}
static inline enum uic_link_state
ufs_get_pm_lvl_to_link_pwr_state(enum ufs_pm_level lvl)
{
return ufs_pm_lvl_states[lvl].link_state;
}
static inline int ufshcd_enable_irq(struct ufs_hba *hba)
{
int ret = 0;
if (!hba->is_irq_enabled) {
ret = request_irq(hba->irq, ufshcd_intr, IRQF_SHARED, UFSHCD,
hba);
if (ret)
dev_err(hba->dev, "%s: request_irq failed, ret=%d\n",
__func__, ret);
hba->is_irq_enabled = true;
}
return ret;
}
static inline void ufshcd_disable_irq(struct ufs_hba *hba)
{
if (hba->is_irq_enabled) {
free_irq(hba->irq, hba);
hba->is_irq_enabled = false;
}
}
static int ufshcd_wait_for_register(struct ufs_hba *hba, u32 reg, u32 mask,
u32 val, unsigned long interval_us, unsigned long timeout_ms)
{
int err = 0;
unsigned long timeout = jiffies + msecs_to_jiffies(timeout_ms);
val = val & mask;
while ((ufshcd_readl(hba, reg) & mask) != val) {
usleep_range(interval_us, interval_us + 50);
if (time_after(jiffies, timeout)) {
if ((ufshcd_readl(hba, reg) & mask) != val)
err = -ETIMEDOUT;
break;
}
}
return err;
}
static inline u32 ufshcd_get_intr_mask(struct ufs_hba *hba)
{
if (hba->ufs_version == UFSHCI_VERSION_10)
return INTERRUPT_MASK_ALL_VER_10;
else
return INTERRUPT_MASK_ALL_VER_11;
}
static inline u32 ufshcd_get_ufs_version(struct ufs_hba *hba)
{
if (hba->quirks & UFSHCD_QUIRK_BROKEN_UFS_HCI_VERSION) {
if (hba->vops && hba->vops->get_ufs_hci_version)
return hba->vops->get_ufs_hci_version(hba);
}
return ufshcd_readl(hba, REG_UFS_VERSION);
}
static inline int ufshcd_is_device_present(struct ufs_hba *hba)
{
return (ufshcd_readl(hba, REG_CONTROLLER_STATUS) &
DEVICE_PRESENT) ? 1 : 0;
}
static inline int ufshcd_get_tr_ocs(struct ufshcd_lrb *lrbp)
{
return le32_to_cpu(lrbp->utr_descriptor_ptr->header.dword_2) & MASK_OCS;
}
static inline int
ufshcd_get_tmr_ocs(struct utp_task_req_desc *task_req_descp)
{
return le32_to_cpu(task_req_descp->header.dword_2) & MASK_OCS;
}
static bool ufshcd_get_tm_free_slot(struct ufs_hba *hba, int *free_slot)
{
int tag;
bool ret = false;
if (!free_slot)
goto out;
do {
tag = find_first_zero_bit(&hba->tm_slots_in_use, hba->nutmrs);
if (tag >= hba->nutmrs)
goto out;
} while (test_and_set_bit_lock(tag, &hba->tm_slots_in_use));
*free_slot = tag;
ret = true;
out:
return ret;
}
static inline void ufshcd_put_tm_slot(struct ufs_hba *hba, int slot)
{
clear_bit_unlock(slot, &hba->tm_slots_in_use);
}
static inline void ufshcd_utrl_clear(struct ufs_hba *hba, u32 pos)
{
ufshcd_writel(hba, ~(1 << pos), REG_UTP_TRANSFER_REQ_LIST_CLEAR);
}
static inline int ufshcd_get_lists_status(u32 reg)
{
return (((reg) & (0xFF)) >> 1) ^ (0x07);
}
static inline int ufshcd_get_uic_cmd_result(struct ufs_hba *hba)
{
return ufshcd_readl(hba, REG_UIC_COMMAND_ARG_2) &
MASK_UIC_COMMAND_RESULT;
}
static inline u32 ufshcd_get_dme_attr_val(struct ufs_hba *hba)
{
return ufshcd_readl(hba, REG_UIC_COMMAND_ARG_3);
}
static inline int
ufshcd_get_req_rsp(struct utp_upiu_rsp *ucd_rsp_ptr)
{
return be32_to_cpu(ucd_rsp_ptr->header.dword_0) >> 24;
}
static inline int
ufshcd_get_rsp_upiu_result(struct utp_upiu_rsp *ucd_rsp_ptr)
{
return be32_to_cpu(ucd_rsp_ptr->header.dword_1) & MASK_RSP_UPIU_RESULT;
}
static inline unsigned int
ufshcd_get_rsp_upiu_data_seg_len(struct utp_upiu_rsp *ucd_rsp_ptr)
{
return be32_to_cpu(ucd_rsp_ptr->header.dword_2) &
MASK_RSP_UPIU_DATA_SEG_LEN;
}
static inline bool ufshcd_is_exception_event(struct utp_upiu_rsp *ucd_rsp_ptr)
{
return be32_to_cpu(ucd_rsp_ptr->header.dword_2) &
MASK_RSP_EXCEPTION_EVENT ? true : false;
}
static inline void
ufshcd_reset_intr_aggr(struct ufs_hba *hba)
{
ufshcd_writel(hba, INT_AGGR_ENABLE |
INT_AGGR_COUNTER_AND_TIMER_RESET,
REG_UTP_TRANSFER_REQ_INT_AGG_CONTROL);
}
static inline void
ufshcd_config_intr_aggr(struct ufs_hba *hba, u8 cnt, u8 tmout)
{
ufshcd_writel(hba, INT_AGGR_ENABLE | INT_AGGR_PARAM_WRITE |
INT_AGGR_COUNTER_THLD_VAL(cnt) |
INT_AGGR_TIMEOUT_VAL(tmout),
REG_UTP_TRANSFER_REQ_INT_AGG_CONTROL);
}
static inline void ufshcd_disable_intr_aggr(struct ufs_hba *hba)
{
ufshcd_writel(hba, 0, REG_UTP_TRANSFER_REQ_INT_AGG_CONTROL);
}
static void ufshcd_enable_run_stop_reg(struct ufs_hba *hba)
{
ufshcd_writel(hba, UTP_TASK_REQ_LIST_RUN_STOP_BIT,
REG_UTP_TASK_REQ_LIST_RUN_STOP);
ufshcd_writel(hba, UTP_TRANSFER_REQ_LIST_RUN_STOP_BIT,
REG_UTP_TRANSFER_REQ_LIST_RUN_STOP);
}
static inline void ufshcd_hba_start(struct ufs_hba *hba)
{
ufshcd_writel(hba, CONTROLLER_ENABLE, REG_CONTROLLER_ENABLE);
}
static inline int ufshcd_is_hba_active(struct ufs_hba *hba)
{
return (ufshcd_readl(hba, REG_CONTROLLER_ENABLE) & 0x1) ? 0 : 1;
}
static void ufshcd_ungate_work(struct work_struct *work)
{
int ret;
unsigned long flags;
struct ufs_hba *hba = container_of(work, struct ufs_hba,
clk_gating.ungate_work);
cancel_delayed_work_sync(&hba->clk_gating.gate_work);
spin_lock_irqsave(hba->host->host_lock, flags);
if (hba->clk_gating.state == CLKS_ON) {
spin_unlock_irqrestore(hba->host->host_lock, flags);
goto unblock_reqs;
}
spin_unlock_irqrestore(hba->host->host_lock, flags);
ufshcd_setup_clocks(hba, true);
if (ufshcd_can_hibern8_during_gating(hba)) {
hba->clk_gating.is_suspended = true;
if (ufshcd_is_link_hibern8(hba)) {
ret = ufshcd_uic_hibern8_exit(hba);
if (ret)
dev_err(hba->dev, "%s: hibern8 exit failed %d\n",
__func__, ret);
else
ufshcd_set_link_active(hba);
}
hba->clk_gating.is_suspended = false;
}
unblock_reqs:
if (ufshcd_is_clkscaling_enabled(hba))
devfreq_resume_device(hba->devfreq);
scsi_unblock_requests(hba->host);
}
int ufshcd_hold(struct ufs_hba *hba, bool async)
{
int rc = 0;
unsigned long flags;
if (!ufshcd_is_clkgating_allowed(hba))
goto out;
spin_lock_irqsave(hba->host->host_lock, flags);
hba->clk_gating.active_reqs++;
start:
switch (hba->clk_gating.state) {
case CLKS_ON:
break;
case REQ_CLKS_OFF:
if (cancel_delayed_work(&hba->clk_gating.gate_work)) {
hba->clk_gating.state = CLKS_ON;
break;
}
case CLKS_OFF:
scsi_block_requests(hba->host);
hba->clk_gating.state = REQ_CLKS_ON;
schedule_work(&hba->clk_gating.ungate_work);
case REQ_CLKS_ON:
if (async) {
rc = -EAGAIN;
hba->clk_gating.active_reqs--;
break;
}
spin_unlock_irqrestore(hba->host->host_lock, flags);
flush_work(&hba->clk_gating.ungate_work);
spin_lock_irqsave(hba->host->host_lock, flags);
goto start;
default:
dev_err(hba->dev, "%s: clk gating is in invalid state %d\n",
__func__, hba->clk_gating.state);
break;
}
spin_unlock_irqrestore(hba->host->host_lock, flags);
out:
return rc;
}
static void ufshcd_gate_work(struct work_struct *work)
{
struct ufs_hba *hba = container_of(work, struct ufs_hba,
clk_gating.gate_work.work);
unsigned long flags;
spin_lock_irqsave(hba->host->host_lock, flags);
if (hba->clk_gating.is_suspended) {
hba->clk_gating.state = CLKS_ON;
goto rel_lock;
}
if (hba->clk_gating.active_reqs
|| hba->ufshcd_state != UFSHCD_STATE_OPERATIONAL
|| hba->lrb_in_use || hba->outstanding_tasks
|| hba->active_uic_cmd || hba->uic_async_done)
goto rel_lock;
spin_unlock_irqrestore(hba->host->host_lock, flags);
if (ufshcd_can_hibern8_during_gating(hba)) {
if (ufshcd_uic_hibern8_enter(hba)) {
hba->clk_gating.state = CLKS_ON;
goto out;
}
ufshcd_set_link_hibern8(hba);
}
if (ufshcd_is_clkscaling_enabled(hba)) {
devfreq_suspend_device(hba->devfreq);
hba->clk_scaling.window_start_t = 0;
}
if (!ufshcd_is_link_active(hba))
ufshcd_setup_clocks(hba, false);
else
__ufshcd_setup_clocks(hba, false, true);
spin_lock_irqsave(hba->host->host_lock, flags);
if (hba->clk_gating.state == REQ_CLKS_OFF)
hba->clk_gating.state = CLKS_OFF;
rel_lock:
spin_unlock_irqrestore(hba->host->host_lock, flags);
out:
return;
}
static void __ufshcd_release(struct ufs_hba *hba)
{
if (!ufshcd_is_clkgating_allowed(hba))
return;
hba->clk_gating.active_reqs--;
if (hba->clk_gating.active_reqs || hba->clk_gating.is_suspended
|| hba->ufshcd_state != UFSHCD_STATE_OPERATIONAL
|| hba->lrb_in_use || hba->outstanding_tasks
|| hba->active_uic_cmd || hba->uic_async_done)
return;
hba->clk_gating.state = REQ_CLKS_OFF;
schedule_delayed_work(&hba->clk_gating.gate_work,
msecs_to_jiffies(hba->clk_gating.delay_ms));
}
void ufshcd_release(struct ufs_hba *hba)
{
unsigned long flags;
spin_lock_irqsave(hba->host->host_lock, flags);
__ufshcd_release(hba);
spin_unlock_irqrestore(hba->host->host_lock, flags);
}
static ssize_t ufshcd_clkgate_delay_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ufs_hba *hba = dev_get_drvdata(dev);
return snprintf(buf, PAGE_SIZE, "%lu\n", hba->clk_gating.delay_ms);
}
static ssize_t ufshcd_clkgate_delay_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct ufs_hba *hba = dev_get_drvdata(dev);
unsigned long flags, value;
if (kstrtoul(buf, 0, &value))
return -EINVAL;
spin_lock_irqsave(hba->host->host_lock, flags);
hba->clk_gating.delay_ms = value;
spin_unlock_irqrestore(hba->host->host_lock, flags);
return count;
}
static void ufshcd_init_clk_gating(struct ufs_hba *hba)
{
if (!ufshcd_is_clkgating_allowed(hba))
return;
hba->clk_gating.delay_ms = 150;
INIT_DELAYED_WORK(&hba->clk_gating.gate_work, ufshcd_gate_work);
INIT_WORK(&hba->clk_gating.ungate_work, ufshcd_ungate_work);
hba->clk_gating.delay_attr.show = ufshcd_clkgate_delay_show;
hba->clk_gating.delay_attr.store = ufshcd_clkgate_delay_store;
sysfs_attr_init(&hba->clk_gating.delay_attr.attr);
hba->clk_gating.delay_attr.attr.name = "clkgate_delay_ms";
hba->clk_gating.delay_attr.attr.mode = S_IRUGO | S_IWUSR;
if (device_create_file(hba->dev, &hba->clk_gating.delay_attr))
dev_err(hba->dev, "Failed to create sysfs for clkgate_delay\n");
}
static void ufshcd_exit_clk_gating(struct ufs_hba *hba)
{
if (!ufshcd_is_clkgating_allowed(hba))
return;
device_remove_file(hba->dev, &hba->clk_gating.delay_attr);
cancel_work_sync(&hba->clk_gating.ungate_work);
cancel_delayed_work_sync(&hba->clk_gating.gate_work);
}
static void ufshcd_clk_scaling_start_busy(struct ufs_hba *hba)
{
if (!ufshcd_is_clkscaling_enabled(hba))
return;
if (!hba->clk_scaling.is_busy_started) {
hba->clk_scaling.busy_start_t = ktime_get();
hba->clk_scaling.is_busy_started = true;
}
}
static void ufshcd_clk_scaling_update_busy(struct ufs_hba *hba)
{
struct ufs_clk_scaling *scaling = &hba->clk_scaling;
if (!ufshcd_is_clkscaling_enabled(hba))
return;
if (!hba->outstanding_reqs && scaling->is_busy_started) {
scaling->tot_busy_t += ktime_to_us(ktime_sub(ktime_get(),
scaling->busy_start_t));
scaling->busy_start_t = ktime_set(0, 0);
scaling->is_busy_started = false;
}
}
static inline
void ufshcd_send_command(struct ufs_hba *hba, unsigned int task_tag)
{
ufshcd_clk_scaling_start_busy(hba);
__set_bit(task_tag, &hba->outstanding_reqs);
ufshcd_writel(hba, 1 << task_tag, REG_UTP_TRANSFER_REQ_DOOR_BELL);
}
static inline void ufshcd_copy_sense_data(struct ufshcd_lrb *lrbp)
{
int len;
if (lrbp->sense_buffer &&
ufshcd_get_rsp_upiu_data_seg_len(lrbp->ucd_rsp_ptr)) {
len = be16_to_cpu(lrbp->ucd_rsp_ptr->sr.sense_data_len);
memcpy(lrbp->sense_buffer,
lrbp->ucd_rsp_ptr->sr.sense_data,
min_t(int, len, SCSI_SENSE_BUFFERSIZE));
}
}
static
int ufshcd_copy_query_response(struct ufs_hba *hba, struct ufshcd_lrb *lrbp)
{
struct ufs_query_res *query_res = &hba->dev_cmd.query.response;
memcpy(&query_res->upiu_res, &lrbp->ucd_rsp_ptr->qr, QUERY_OSF_SIZE);
if (lrbp->ucd_rsp_ptr->qr.opcode == UPIU_QUERY_OPCODE_READ_DESC) {
u8 *descp = (u8 *)lrbp->ucd_rsp_ptr +
GENERAL_UPIU_REQUEST_SIZE;
u16 resp_len;
u16 buf_len;
resp_len = be32_to_cpu(lrbp->ucd_rsp_ptr->header.dword_2) &
MASK_QUERY_DATA_SEG_LEN;
buf_len = be16_to_cpu(
hba->dev_cmd.query.request.upiu_req.length);
if (likely(buf_len >= resp_len)) {
memcpy(hba->dev_cmd.query.descriptor, descp, resp_len);
} else {
dev_warn(hba->dev,
"%s: Response size is bigger than buffer",
__func__);
return -EINVAL;
}
}
return 0;
}
static inline void ufshcd_hba_capabilities(struct ufs_hba *hba)
{
hba->capabilities = ufshcd_readl(hba, REG_CONTROLLER_CAPABILITIES);
hba->nutrs = (hba->capabilities & MASK_TRANSFER_REQUESTS_SLOTS) + 1;
hba->nutmrs =
((hba->capabilities & MASK_TASK_MANAGEMENT_REQUEST_SLOTS) >> 16) + 1;
}
static inline bool ufshcd_ready_for_uic_cmd(struct ufs_hba *hba)
{
if (ufshcd_readl(hba, REG_CONTROLLER_STATUS) & UIC_COMMAND_READY)
return true;
else
return false;
}
static inline u8 ufshcd_get_upmcrs(struct ufs_hba *hba)
{
return (ufshcd_readl(hba, REG_CONTROLLER_STATUS) >> 8) & 0x7;
}
static inline void
ufshcd_dispatch_uic_cmd(struct ufs_hba *hba, struct uic_command *uic_cmd)
{
WARN_ON(hba->active_uic_cmd);
hba->active_uic_cmd = uic_cmd;
ufshcd_writel(hba, uic_cmd->argument1, REG_UIC_COMMAND_ARG_1);
ufshcd_writel(hba, uic_cmd->argument2, REG_UIC_COMMAND_ARG_2);
ufshcd_writel(hba, uic_cmd->argument3, REG_UIC_COMMAND_ARG_3);
ufshcd_writel(hba, uic_cmd->command & COMMAND_OPCODE_MASK,
REG_UIC_COMMAND);
}
static int
ufshcd_wait_for_uic_cmd(struct ufs_hba *hba, struct uic_command *uic_cmd)
{
int ret;
unsigned long flags;
if (wait_for_completion_timeout(&uic_cmd->done,
msecs_to_jiffies(UIC_CMD_TIMEOUT)))
ret = uic_cmd->argument2 & MASK_UIC_COMMAND_RESULT;
else
ret = -ETIMEDOUT;
spin_lock_irqsave(hba->host->host_lock, flags);
hba->active_uic_cmd = NULL;
spin_unlock_irqrestore(hba->host->host_lock, flags);
return ret;
}
static int
__ufshcd_send_uic_cmd(struct ufs_hba *hba, struct uic_command *uic_cmd)
{
if (!ufshcd_ready_for_uic_cmd(hba)) {
dev_err(hba->dev,
"Controller not ready to accept UIC commands\n");
return -EIO;
}
init_completion(&uic_cmd->done);
ufshcd_dispatch_uic_cmd(hba, uic_cmd);
return 0;
}
static int
ufshcd_send_uic_cmd(struct ufs_hba *hba, struct uic_command *uic_cmd)
{
int ret;
unsigned long flags;
ufshcd_hold(hba, false);
mutex_lock(&hba->uic_cmd_mutex);
ufshcd_add_delay_before_dme_cmd(hba);
spin_lock_irqsave(hba->host->host_lock, flags);
ret = __ufshcd_send_uic_cmd(hba, uic_cmd);
spin_unlock_irqrestore(hba->host->host_lock, flags);
if (!ret)
ret = ufshcd_wait_for_uic_cmd(hba, uic_cmd);
mutex_unlock(&hba->uic_cmd_mutex);
ufshcd_release(hba);
return ret;
}
static int ufshcd_map_sg(struct ufshcd_lrb *lrbp)
{
struct ufshcd_sg_entry *prd_table;
struct scatterlist *sg;
struct scsi_cmnd *cmd;
int sg_segments;
int i;
cmd = lrbp->cmd;
sg_segments = scsi_dma_map(cmd);
if (sg_segments < 0)
return sg_segments;
if (sg_segments) {
lrbp->utr_descriptor_ptr->prd_table_length =
cpu_to_le16((u16) (sg_segments));
prd_table = (struct ufshcd_sg_entry *)lrbp->ucd_prdt_ptr;
scsi_for_each_sg(cmd, sg, sg_segments, i) {
prd_table[i].size =
cpu_to_le32(((u32) sg_dma_len(sg))-1);
prd_table[i].base_addr =
cpu_to_le32(lower_32_bits(sg->dma_address));
prd_table[i].upper_addr =
cpu_to_le32(upper_32_bits(sg->dma_address));
}
} else {
lrbp->utr_descriptor_ptr->prd_table_length = 0;
}
return 0;
}
static void ufshcd_enable_intr(struct ufs_hba *hba, u32 intrs)
{
u32 set = ufshcd_readl(hba, REG_INTERRUPT_ENABLE);
if (hba->ufs_version == UFSHCI_VERSION_10) {
u32 rw;
rw = set & INTERRUPT_MASK_RW_VER_10;
set = rw | ((set ^ intrs) & intrs);
} else {
set |= intrs;
}
ufshcd_writel(hba, set, REG_INTERRUPT_ENABLE);
}
static void ufshcd_disable_intr(struct ufs_hba *hba, u32 intrs)
{
u32 set = ufshcd_readl(hba, REG_INTERRUPT_ENABLE);
if (hba->ufs_version == UFSHCI_VERSION_10) {
u32 rw;
rw = (set & INTERRUPT_MASK_RW_VER_10) &
~(intrs & INTERRUPT_MASK_RW_VER_10);
set = rw | ((set & intrs) & ~INTERRUPT_MASK_RW_VER_10);
} else {
set &= ~intrs;
}
ufshcd_writel(hba, set, REG_INTERRUPT_ENABLE);
}
static void ufshcd_prepare_req_desc_hdr(struct ufshcd_lrb *lrbp,
u32 *upiu_flags, enum dma_data_direction cmd_dir)
{
struct utp_transfer_req_desc *req_desc = lrbp->utr_descriptor_ptr;
u32 data_direction;
u32 dword_0;
if (cmd_dir == DMA_FROM_DEVICE) {
data_direction = UTP_DEVICE_TO_HOST;
*upiu_flags = UPIU_CMD_FLAGS_READ;
} else if (cmd_dir == DMA_TO_DEVICE) {
data_direction = UTP_HOST_TO_DEVICE;
*upiu_flags = UPIU_CMD_FLAGS_WRITE;
} else {
data_direction = UTP_NO_DATA_TRANSFER;
*upiu_flags = UPIU_CMD_FLAGS_NONE;
}
dword_0 = data_direction | (lrbp->command_type
<< UPIU_COMMAND_TYPE_OFFSET);
if (lrbp->intr_cmd)
dword_0 |= UTP_REQ_DESC_INT_CMD;
req_desc->header.dword_0 = cpu_to_le32(dword_0);
req_desc->header.dword_2 =
cpu_to_le32(OCS_INVALID_COMMAND_STATUS);
}
static
void ufshcd_prepare_utp_scsi_cmd_upiu(struct ufshcd_lrb *lrbp, u32 upiu_flags)
{
struct utp_upiu_req *ucd_req_ptr = lrbp->ucd_req_ptr;
ucd_req_ptr->header.dword_0 = UPIU_HEADER_DWORD(
UPIU_TRANSACTION_COMMAND, upiu_flags,
lrbp->lun, lrbp->task_tag);
ucd_req_ptr->header.dword_1 = UPIU_HEADER_DWORD(
UPIU_COMMAND_SET_TYPE_SCSI, 0, 0, 0);
ucd_req_ptr->header.dword_2 = 0;
ucd_req_ptr->sc.exp_data_transfer_len =
cpu_to_be32(lrbp->cmd->sdb.length);
memcpy(ucd_req_ptr->sc.cdb, lrbp->cmd->cmnd,
(min_t(unsigned short, lrbp->cmd->cmd_len, MAX_CDB_SIZE)));
}
static void ufshcd_prepare_utp_query_req_upiu(struct ufs_hba *hba,
struct ufshcd_lrb *lrbp, u32 upiu_flags)
{
struct utp_upiu_req *ucd_req_ptr = lrbp->ucd_req_ptr;
struct ufs_query *query = &hba->dev_cmd.query;
u16 len = be16_to_cpu(query->request.upiu_req.length);
u8 *descp = (u8 *)lrbp->ucd_req_ptr + GENERAL_UPIU_REQUEST_SIZE;
ucd_req_ptr->header.dword_0 = UPIU_HEADER_DWORD(
UPIU_TRANSACTION_QUERY_REQ, upiu_flags,
lrbp->lun, lrbp->task_tag);
ucd_req_ptr->header.dword_1 = UPIU_HEADER_DWORD(
0, query->request.query_func, 0, 0);
ucd_req_ptr->header.dword_2 = UPIU_HEADER_DWORD(
0, 0, len >> 8, (u8)len);
memcpy(&ucd_req_ptr->qr, &query->request.upiu_req,
QUERY_OSF_SIZE);
if (query->request.upiu_req.opcode == UPIU_QUERY_OPCODE_WRITE_DESC)
memcpy(descp, query->descriptor, len);
}
static inline void ufshcd_prepare_utp_nop_upiu(struct ufshcd_lrb *lrbp)
{
struct utp_upiu_req *ucd_req_ptr = lrbp->ucd_req_ptr;
memset(ucd_req_ptr, 0, sizeof(struct utp_upiu_req));
ucd_req_ptr->header.dword_0 =
UPIU_HEADER_DWORD(
UPIU_TRANSACTION_NOP_OUT, 0, 0, lrbp->task_tag);
}
static int ufshcd_compose_upiu(struct ufs_hba *hba, struct ufshcd_lrb *lrbp)
{
u32 upiu_flags;
int ret = 0;
switch (lrbp->command_type) {
case UTP_CMD_TYPE_SCSI:
if (likely(lrbp->cmd)) {
ufshcd_prepare_req_desc_hdr(lrbp, &upiu_flags,
lrbp->cmd->sc_data_direction);
ufshcd_prepare_utp_scsi_cmd_upiu(lrbp, upiu_flags);
} else {
ret = -EINVAL;
}
break;
case UTP_CMD_TYPE_DEV_MANAGE:
ufshcd_prepare_req_desc_hdr(lrbp, &upiu_flags, DMA_NONE);
if (hba->dev_cmd.type == DEV_CMD_TYPE_QUERY)
ufshcd_prepare_utp_query_req_upiu(
hba, lrbp, upiu_flags);
else if (hba->dev_cmd.type == DEV_CMD_TYPE_NOP)
ufshcd_prepare_utp_nop_upiu(lrbp);
else
ret = -EINVAL;
break;
case UTP_CMD_TYPE_UFS:
ret = -ENOTSUPP;
dev_err(hba->dev, "%s: UFS native command are not supported\n",
__func__);
break;
default:
ret = -ENOTSUPP;
dev_err(hba->dev, "%s: unknown command type: 0x%x\n",
__func__, lrbp->command_type);
break;
}
return ret;
}
static inline u8 ufshcd_scsi_to_upiu_lun(unsigned int scsi_lun)
{
if (scsi_is_wlun(scsi_lun))
return (scsi_lun & UFS_UPIU_MAX_UNIT_NUM_ID)
| UFS_UPIU_WLUN_ID;
else
return scsi_lun & UFS_UPIU_MAX_UNIT_NUM_ID;
}
static inline u16 ufshcd_upiu_wlun_to_scsi_wlun(u8 upiu_wlun_id)
{
return (upiu_wlun_id & ~UFS_UPIU_WLUN_ID) | SCSI_W_LUN_BASE;
}
static int ufshcd_queuecommand(struct Scsi_Host *host, struct scsi_cmnd *cmd)
{
struct ufshcd_lrb *lrbp;
struct ufs_hba *hba;
unsigned long flags;
int tag;
int err = 0;
hba = shost_priv(host);
tag = cmd->request->tag;
spin_lock_irqsave(hba->host->host_lock, flags);
switch (hba->ufshcd_state) {
case UFSHCD_STATE_OPERATIONAL:
break;
case UFSHCD_STATE_RESET:
err = SCSI_MLQUEUE_HOST_BUSY;
goto out_unlock;
case UFSHCD_STATE_ERROR:
set_host_byte(cmd, DID_ERROR);
cmd->scsi_done(cmd);
goto out_unlock;
default:
dev_WARN_ONCE(hba->dev, 1, "%s: invalid state %d\n",
__func__, hba->ufshcd_state);
set_host_byte(cmd, DID_BAD_TARGET);
cmd->scsi_done(cmd);
goto out_unlock;
}
spin_unlock_irqrestore(hba->host->host_lock, flags);
if (test_and_set_bit_lock(tag, &hba->lrb_in_use)) {
err = SCSI_MLQUEUE_HOST_BUSY;
goto out;
}
err = ufshcd_hold(hba, true);
if (err) {
err = SCSI_MLQUEUE_HOST_BUSY;
clear_bit_unlock(tag, &hba->lrb_in_use);
goto out;
}
WARN_ON(hba->clk_gating.state != CLKS_ON);
lrbp = &hba->lrb[tag];
WARN_ON(lrbp->cmd);
lrbp->cmd = cmd;
lrbp->sense_bufflen = SCSI_SENSE_BUFFERSIZE;
lrbp->sense_buffer = cmd->sense_buffer;
lrbp->task_tag = tag;
lrbp->lun = ufshcd_scsi_to_upiu_lun(cmd->device->lun);
lrbp->intr_cmd = !ufshcd_is_intr_aggr_allowed(hba) ? true : false;
lrbp->command_type = UTP_CMD_TYPE_SCSI;
ufshcd_compose_upiu(hba, lrbp);
err = ufshcd_map_sg(lrbp);
if (err) {
lrbp->cmd = NULL;
clear_bit_unlock(tag, &hba->lrb_in_use);
goto out;
}
spin_lock_irqsave(hba->host->host_lock, flags);
ufshcd_send_command(hba, tag);
out_unlock:
spin_unlock_irqrestore(hba->host->host_lock, flags);
out:
return err;
}
static int ufshcd_compose_dev_cmd(struct ufs_hba *hba,
struct ufshcd_lrb *lrbp, enum dev_cmd_type cmd_type, int tag)
{
lrbp->cmd = NULL;
lrbp->sense_bufflen = 0;
lrbp->sense_buffer = NULL;
lrbp->task_tag = tag;
lrbp->lun = 0;
lrbp->command_type = UTP_CMD_TYPE_DEV_MANAGE;
lrbp->intr_cmd = true;
hba->dev_cmd.type = cmd_type;
return ufshcd_compose_upiu(hba, lrbp);
}
static int
ufshcd_clear_cmd(struct ufs_hba *hba, int tag)
{
int err = 0;
unsigned long flags;
u32 mask = 1 << tag;
spin_lock_irqsave(hba->host->host_lock, flags);
ufshcd_utrl_clear(hba, tag);
spin_unlock_irqrestore(hba->host->host_lock, flags);
err = ufshcd_wait_for_register(hba,
REG_UTP_TRANSFER_REQ_DOOR_BELL,
mask, ~mask, 1000, 1000);
return err;
}
static int
ufshcd_check_query_response(struct ufs_hba *hba, struct ufshcd_lrb *lrbp)
{
struct ufs_query_res *query_res = &hba->dev_cmd.query.response;
query_res->response = ufshcd_get_rsp_upiu_result(lrbp->ucd_rsp_ptr) >>
UPIU_RSP_CODE_OFFSET;
return query_res->response;
}
static int
ufshcd_dev_cmd_completion(struct ufs_hba *hba, struct ufshcd_lrb *lrbp)
{
int resp;
int err = 0;
resp = ufshcd_get_req_rsp(lrbp->ucd_rsp_ptr);
switch (resp) {
case UPIU_TRANSACTION_NOP_IN:
if (hba->dev_cmd.type != DEV_CMD_TYPE_NOP) {
err = -EINVAL;
dev_err(hba->dev, "%s: unexpected response %x\n",
__func__, resp);
}
break;
case UPIU_TRANSACTION_QUERY_RSP:
err = ufshcd_check_query_response(hba, lrbp);
if (!err)
err = ufshcd_copy_query_response(hba, lrbp);
break;
case UPIU_TRANSACTION_REJECT_UPIU:
err = -EPERM;
dev_err(hba->dev, "%s: Reject UPIU not fully implemented\n",
__func__);
break;
default:
err = -EINVAL;
dev_err(hba->dev, "%s: Invalid device management cmd response: %x\n",
__func__, resp);
break;
}
return err;
}
static int ufshcd_wait_for_dev_cmd(struct ufs_hba *hba,
struct ufshcd_lrb *lrbp, int max_timeout)
{
int err = 0;
unsigned long time_left;
unsigned long flags;
time_left = wait_for_completion_timeout(hba->dev_cmd.complete,
msecs_to_jiffies(max_timeout));
spin_lock_irqsave(hba->host->host_lock, flags);
hba->dev_cmd.complete = NULL;
if (likely(time_left)) {
err = ufshcd_get_tr_ocs(lrbp);
if (!err)
err = ufshcd_dev_cmd_completion(hba, lrbp);
}
spin_unlock_irqrestore(hba->host->host_lock, flags);
if (!time_left) {
err = -ETIMEDOUT;
if (!ufshcd_clear_cmd(hba, lrbp->task_tag))
err = -EAGAIN;
}
return err;
}
static bool ufshcd_get_dev_cmd_tag(struct ufs_hba *hba, int *tag_out)
{
int tag;
bool ret = false;
unsigned long tmp;
if (!tag_out)
goto out;
do {
tmp = ~hba->lrb_in_use;
tag = find_last_bit(&tmp, hba->nutrs);
if (tag >= hba->nutrs)
goto out;
} while (test_and_set_bit_lock(tag, &hba->lrb_in_use));
*tag_out = tag;
ret = true;
out:
return ret;
}
static inline void ufshcd_put_dev_cmd_tag(struct ufs_hba *hba, int tag)
{
clear_bit_unlock(tag, &hba->lrb_in_use);
}
static int ufshcd_exec_dev_cmd(struct ufs_hba *hba,
enum dev_cmd_type cmd_type, int timeout)
{
struct ufshcd_lrb *lrbp;
int err;
int tag;
struct completion wait;
unsigned long flags;
wait_event(hba->dev_cmd.tag_wq, ufshcd_get_dev_cmd_tag(hba, &tag));
init_completion(&wait);
lrbp = &hba->lrb[tag];
WARN_ON(lrbp->cmd);
err = ufshcd_compose_dev_cmd(hba, lrbp, cmd_type, tag);
if (unlikely(err))
goto out_put_tag;
hba->dev_cmd.complete = &wait;
spin_lock_irqsave(hba->host->host_lock, flags);
ufshcd_send_command(hba, tag);
spin_unlock_irqrestore(hba->host->host_lock, flags);
err = ufshcd_wait_for_dev_cmd(hba, lrbp, timeout);
out_put_tag:
ufshcd_put_dev_cmd_tag(hba, tag);
wake_up(&hba->dev_cmd.tag_wq);
return err;
}
static inline void ufshcd_init_query(struct ufs_hba *hba,
struct ufs_query_req **request, struct ufs_query_res **response,
enum query_opcode opcode, u8 idn, u8 index, u8 selector)
{
*request = &hba->dev_cmd.query.request;
*response = &hba->dev_cmd.query.response;
memset(*request, 0, sizeof(struct ufs_query_req));
memset(*response, 0, sizeof(struct ufs_query_res));
(*request)->upiu_req.opcode = opcode;
(*request)->upiu_req.idn = idn;
(*request)->upiu_req.index = index;
(*request)->upiu_req.selector = selector;
}
static int ufshcd_query_flag(struct ufs_hba *hba, enum query_opcode opcode,
enum flag_idn idn, bool *flag_res)
{
struct ufs_query_req *request = NULL;
struct ufs_query_res *response = NULL;
int err, index = 0, selector = 0;
BUG_ON(!hba);
ufshcd_hold(hba, false);
mutex_lock(&hba->dev_cmd.lock);
ufshcd_init_query(hba, &request, &response, opcode, idn, index,
selector);
switch (opcode) {
case UPIU_QUERY_OPCODE_SET_FLAG:
case UPIU_QUERY_OPCODE_CLEAR_FLAG:
case UPIU_QUERY_OPCODE_TOGGLE_FLAG:
request->query_func = UPIU_QUERY_FUNC_STANDARD_WRITE_REQUEST;
break;
case UPIU_QUERY_OPCODE_READ_FLAG:
request->query_func = UPIU_QUERY_FUNC_STANDARD_READ_REQUEST;
if (!flag_res) {
dev_err(hba->dev, "%s: Invalid argument for read request\n",
__func__);
err = -EINVAL;
goto out_unlock;
}
break;
default:
dev_err(hba->dev,
"%s: Expected query flag opcode but got = %d\n",
__func__, opcode);
err = -EINVAL;
goto out_unlock;
}
err = ufshcd_exec_dev_cmd(hba, DEV_CMD_TYPE_QUERY, QUERY_REQ_TIMEOUT);
if (err) {
dev_err(hba->dev,
"%s: Sending flag query for idn %d failed, err = %d\n",
__func__, idn, err);
goto out_unlock;
}
if (flag_res)
*flag_res = (be32_to_cpu(response->upiu_res.value) &
MASK_QUERY_UPIU_FLAG_LOC) & 0x1;
out_unlock:
mutex_unlock(&hba->dev_cmd.lock);
ufshcd_release(hba);
return err;
}
static int ufshcd_query_attr(struct ufs_hba *hba, enum query_opcode opcode,
enum attr_idn idn, u8 index, u8 selector, u32 *attr_val)
{
struct ufs_query_req *request = NULL;
struct ufs_query_res *response = NULL;
int err;
BUG_ON(!hba);
ufshcd_hold(hba, false);
if (!attr_val) {
dev_err(hba->dev, "%s: attribute value required for opcode 0x%x\n",
__func__, opcode);
err = -EINVAL;
goto out;
}
mutex_lock(&hba->dev_cmd.lock);
ufshcd_init_query(hba, &request, &response, opcode, idn, index,
selector);
switch (opcode) {
case UPIU_QUERY_OPCODE_WRITE_ATTR:
request->query_func = UPIU_QUERY_FUNC_STANDARD_WRITE_REQUEST;
request->upiu_req.value = cpu_to_be32(*attr_val);
break;
case UPIU_QUERY_OPCODE_READ_ATTR:
request->query_func = UPIU_QUERY_FUNC_STANDARD_READ_REQUEST;
break;
default:
dev_err(hba->dev, "%s: Expected query attr opcode but got = 0x%.2x\n",
__func__, opcode);
err = -EINVAL;
goto out_unlock;
}
err = ufshcd_exec_dev_cmd(hba, DEV_CMD_TYPE_QUERY, QUERY_REQ_TIMEOUT);
if (err) {
dev_err(hba->dev, "%s: opcode 0x%.2x for idn %d failed, err = %d\n",
__func__, opcode, idn, err);
goto out_unlock;
}
*attr_val = be32_to_cpu(response->upiu_res.value);
out_unlock:
mutex_unlock(&hba->dev_cmd.lock);
out:
ufshcd_release(hba);
return err;
}
static int ufshcd_query_descriptor(struct ufs_hba *hba,
enum query_opcode opcode, enum desc_idn idn, u8 index,
u8 selector, u8 *desc_buf, int *buf_len)
{
struct ufs_query_req *request = NULL;
struct ufs_query_res *response = NULL;
int err;
BUG_ON(!hba);
ufshcd_hold(hba, false);
if (!desc_buf) {
dev_err(hba->dev, "%s: descriptor buffer required for opcode 0x%x\n",
__func__, opcode);
err = -EINVAL;
goto out;
}
if (*buf_len <= QUERY_DESC_MIN_SIZE || *buf_len > QUERY_DESC_MAX_SIZE) {
dev_err(hba->dev, "%s: descriptor buffer size (%d) is out of range\n",
__func__, *buf_len);
err = -EINVAL;
goto out;
}
mutex_lock(&hba->dev_cmd.lock);
ufshcd_init_query(hba, &request, &response, opcode, idn, index,
selector);
hba->dev_cmd.query.descriptor = desc_buf;
request->upiu_req.length = cpu_to_be16(*buf_len);
switch (opcode) {
case UPIU_QUERY_OPCODE_WRITE_DESC:
request->query_func = UPIU_QUERY_FUNC_STANDARD_WRITE_REQUEST;
break;
case UPIU_QUERY_OPCODE_READ_DESC:
request->query_func = UPIU_QUERY_FUNC_STANDARD_READ_REQUEST;
break;
default:
dev_err(hba->dev,
"%s: Expected query descriptor opcode but got = 0x%.2x\n",
__func__, opcode);
err = -EINVAL;
goto out_unlock;
}
err = ufshcd_exec_dev_cmd(hba, DEV_CMD_TYPE_QUERY, QUERY_REQ_TIMEOUT);
if (err) {
dev_err(hba->dev, "%s: opcode 0x%.2x for idn %d failed, err = %d\n",
__func__, opcode, idn, err);
goto out_unlock;
}
hba->dev_cmd.query.descriptor = NULL;
*buf_len = be16_to_cpu(response->upiu_res.length);
out_unlock:
mutex_unlock(&hba->dev_cmd.lock);
out:
ufshcd_release(hba);
return err;
}
static int ufshcd_read_desc_param(struct ufs_hba *hba,
enum desc_idn desc_id,
int desc_index,
u32 param_offset,
u8 *param_read_buf,
u32 param_size)
{
int ret;
u8 *desc_buf;
u32 buff_len;
bool is_kmalloc = true;
if (desc_id >= QUERY_DESC_IDN_MAX)
return -EINVAL;
buff_len = ufs_query_desc_max_size[desc_id];
if ((param_offset + param_size) > buff_len)
return -EINVAL;
if (!param_offset && (param_size == buff_len)) {
desc_buf = param_read_buf;
is_kmalloc = false;
} else {
desc_buf = kmalloc(buff_len, GFP_KERNEL);
if (!desc_buf)
return -ENOMEM;
}
ret = ufshcd_query_descriptor(hba, UPIU_QUERY_OPCODE_READ_DESC,
desc_id, desc_index, 0, desc_buf,
&buff_len);
if (ret || (buff_len < ufs_query_desc_max_size[desc_id]) ||
(desc_buf[QUERY_DESC_LENGTH_OFFSET] !=
ufs_query_desc_max_size[desc_id])
|| (desc_buf[QUERY_DESC_DESC_TYPE_OFFSET] != desc_id)) {
dev_err(hba->dev, "%s: Failed reading descriptor. desc_id %d param_offset %d buff_len %d ret %d",
__func__, desc_id, param_offset, buff_len, ret);
if (!ret)
ret = -EINVAL;
goto out;
}
if (is_kmalloc)
memcpy(param_read_buf, &desc_buf[param_offset], param_size);
out:
if (is_kmalloc)
kfree(desc_buf);
return ret;
}
static inline int ufshcd_read_desc(struct ufs_hba *hba,
enum desc_idn desc_id,
int desc_index,
u8 *buf,
u32 size)
{
return ufshcd_read_desc_param(hba, desc_id, desc_index, 0, buf, size);
}
static inline int ufshcd_read_power_desc(struct ufs_hba *hba,
u8 *buf,
u32 size)
{
return ufshcd_read_desc(hba, QUERY_DESC_IDN_POWER, 0, buf, size);
}
static inline int ufshcd_read_unit_desc_param(struct ufs_hba *hba,
int lun,
enum unit_desc_param param_offset,
u8 *param_read_buf,
u32 param_size)
{
if (lun != UFS_UPIU_RPMB_WLUN && (lun >= UFS_UPIU_MAX_GENERAL_LUN))
return -EOPNOTSUPP;
return ufshcd_read_desc_param(hba, QUERY_DESC_IDN_UNIT, lun,
param_offset, param_read_buf, param_size);
}
static int ufshcd_memory_alloc(struct ufs_hba *hba)
{
size_t utmrdl_size, utrdl_size, ucdl_size;
ucdl_size = (sizeof(struct utp_transfer_cmd_desc) * hba->nutrs);
hba->ucdl_base_addr = dmam_alloc_coherent(hba->dev,
ucdl_size,
&hba->ucdl_dma_addr,
GFP_KERNEL);
if (!hba->ucdl_base_addr ||
WARN_ON(hba->ucdl_dma_addr & (PAGE_SIZE - 1))) {
dev_err(hba->dev,
"Command Descriptor Memory allocation failed\n");
goto out;
}
utrdl_size = (sizeof(struct utp_transfer_req_desc) * hba->nutrs);
hba->utrdl_base_addr = dmam_alloc_coherent(hba->dev,
utrdl_size,
&hba->utrdl_dma_addr,
GFP_KERNEL);
if (!hba->utrdl_base_addr ||
WARN_ON(hba->utrdl_dma_addr & (PAGE_SIZE - 1))) {
dev_err(hba->dev,
"Transfer Descriptor Memory allocation failed\n");
goto out;
}
utmrdl_size = sizeof(struct utp_task_req_desc) * hba->nutmrs;
hba->utmrdl_base_addr = dmam_alloc_coherent(hba->dev,
utmrdl_size,
&hba->utmrdl_dma_addr,
GFP_KERNEL);
if (!hba->utmrdl_base_addr ||
WARN_ON(hba->utmrdl_dma_addr & (PAGE_SIZE - 1))) {
dev_err(hba->dev,
"Task Management Descriptor Memory allocation failed\n");
goto out;
}
hba->lrb = devm_kzalloc(hba->dev,
hba->nutrs * sizeof(struct ufshcd_lrb),
GFP_KERNEL);
if (!hba->lrb) {
dev_err(hba->dev, "LRB Memory allocation failed\n");
goto out;
}
return 0;
out:
return -ENOMEM;
}
static void ufshcd_host_memory_configure(struct ufs_hba *hba)
{
struct utp_transfer_cmd_desc *cmd_descp;
struct utp_transfer_req_desc *utrdlp;
dma_addr_t cmd_desc_dma_addr;
dma_addr_t cmd_desc_element_addr;
u16 response_offset;
u16 prdt_offset;
int cmd_desc_size;
int i;
utrdlp = hba->utrdl_base_addr;
cmd_descp = hba->ucdl_base_addr;
response_offset =
offsetof(struct utp_transfer_cmd_desc, response_upiu);
prdt_offset =
offsetof(struct utp_transfer_cmd_desc, prd_table);
cmd_desc_size = sizeof(struct utp_transfer_cmd_desc);
cmd_desc_dma_addr = hba->ucdl_dma_addr;
for (i = 0; i < hba->nutrs; i++) {
cmd_desc_element_addr =
(cmd_desc_dma_addr + (cmd_desc_size * i));
utrdlp[i].command_desc_base_addr_lo =
cpu_to_le32(lower_32_bits(cmd_desc_element_addr));
utrdlp[i].command_desc_base_addr_hi =
cpu_to_le32(upper_32_bits(cmd_desc_element_addr));
utrdlp[i].response_upiu_offset =
cpu_to_le16((response_offset >> 2));
utrdlp[i].prd_table_offset =
cpu_to_le16((prdt_offset >> 2));
utrdlp[i].response_upiu_length =
cpu_to_le16(ALIGNED_UPIU_SIZE >> 2);
hba->lrb[i].utr_descriptor_ptr = (utrdlp + i);
hba->lrb[i].ucd_req_ptr =
(struct utp_upiu_req *)(cmd_descp + i);
hba->lrb[i].ucd_rsp_ptr =
(struct utp_upiu_rsp *)cmd_descp[i].response_upiu;
hba->lrb[i].ucd_prdt_ptr =
(struct ufshcd_sg_entry *)cmd_descp[i].prd_table;
}
}
static int ufshcd_dme_link_startup(struct ufs_hba *hba)
{
struct uic_command uic_cmd = {0};
int ret;
uic_cmd.command = UIC_CMD_DME_LINK_STARTUP;
ret = ufshcd_send_uic_cmd(hba, &uic_cmd);
if (ret)
dev_err(hba->dev,
"dme-link-startup: error code %d\n", ret);
return ret;
}
static inline void ufshcd_add_delay_before_dme_cmd(struct ufs_hba *hba)
{
#define MIN_DELAY_BEFORE_DME_CMDS_US 1000
unsigned long min_sleep_time_us;
if (!(hba->quirks & UFSHCD_QUIRK_DELAY_BEFORE_DME_CMDS))
return;
if (unlikely(!ktime_to_us(hba->last_dme_cmd_tstamp))) {
min_sleep_time_us = MIN_DELAY_BEFORE_DME_CMDS_US;
} else {
unsigned long delta =
(unsigned long) ktime_to_us(
ktime_sub(ktime_get(),
hba->last_dme_cmd_tstamp));
if (delta < MIN_DELAY_BEFORE_DME_CMDS_US)
min_sleep_time_us =
MIN_DELAY_BEFORE_DME_CMDS_US - delta;
else
return;
}
usleep_range(min_sleep_time_us, min_sleep_time_us + 50);
}
int ufshcd_dme_set_attr(struct ufs_hba *hba, u32 attr_sel,
u8 attr_set, u32 mib_val, u8 peer)
{
struct uic_command uic_cmd = {0};
static const char *const action[] = {
"dme-set",
"dme-peer-set"
};
const char *set = action[!!peer];
int ret;
uic_cmd.command = peer ?
UIC_CMD_DME_PEER_SET : UIC_CMD_DME_SET;
uic_cmd.argument1 = attr_sel;
uic_cmd.argument2 = UIC_ARG_ATTR_TYPE(attr_set);
uic_cmd.argument3 = mib_val;
ret = ufshcd_send_uic_cmd(hba, &uic_cmd);
if (ret)
dev_err(hba->dev, "%s: attr-id 0x%x val 0x%x error code %d\n",
set, UIC_GET_ATTR_ID(attr_sel), mib_val, ret);
return ret;
}
int ufshcd_dme_get_attr(struct ufs_hba *hba, u32 attr_sel,
u32 *mib_val, u8 peer)
{
struct uic_command uic_cmd = {0};
static const char *const action[] = {
"dme-get",
"dme-peer-get"
};
const char *get = action[!!peer];
int ret;
struct ufs_pa_layer_attr orig_pwr_info;
struct ufs_pa_layer_attr temp_pwr_info;
bool pwr_mode_change = false;
if (peer && (hba->quirks & UFSHCD_QUIRK_DME_PEER_ACCESS_AUTO_MODE)) {
orig_pwr_info = hba->pwr_info;
temp_pwr_info = orig_pwr_info;
if (orig_pwr_info.pwr_tx == FAST_MODE ||
orig_pwr_info.pwr_rx == FAST_MODE) {
temp_pwr_info.pwr_tx = FASTAUTO_MODE;
temp_pwr_info.pwr_rx = FASTAUTO_MODE;
pwr_mode_change = true;
} else if (orig_pwr_info.pwr_tx == SLOW_MODE ||
orig_pwr_info.pwr_rx == SLOW_MODE) {
temp_pwr_info.pwr_tx = SLOWAUTO_MODE;
temp_pwr_info.pwr_rx = SLOWAUTO_MODE;
pwr_mode_change = true;
}
if (pwr_mode_change) {
ret = ufshcd_change_power_mode(hba, &temp_pwr_info);
if (ret)
goto out;
}
}
uic_cmd.command = peer ?
UIC_CMD_DME_PEER_GET : UIC_CMD_DME_GET;
uic_cmd.argument1 = attr_sel;
ret = ufshcd_send_uic_cmd(hba, &uic_cmd);
if (ret) {
dev_err(hba->dev, "%s: attr-id 0x%x error code %d\n",
get, UIC_GET_ATTR_ID(attr_sel), ret);
goto out;
}
if (mib_val)
*mib_val = uic_cmd.argument3;
if (peer && (hba->quirks & UFSHCD_QUIRK_DME_PEER_ACCESS_AUTO_MODE)
&& pwr_mode_change)
ufshcd_change_power_mode(hba, &orig_pwr_info);
out:
return ret;
}
static int ufshcd_uic_pwr_ctrl(struct ufs_hba *hba, struct uic_command *cmd)
{
struct completion uic_async_done;
unsigned long flags;
u8 status;
int ret;
mutex_lock(&hba->uic_cmd_mutex);
init_completion(&uic_async_done);
ufshcd_add_delay_before_dme_cmd(hba);
spin_lock_irqsave(hba->host->host_lock, flags);
hba->uic_async_done = &uic_async_done;
ret = __ufshcd_send_uic_cmd(hba, cmd);
spin_unlock_irqrestore(hba->host->host_lock, flags);
if (ret) {
dev_err(hba->dev,
"pwr ctrl cmd 0x%x with mode 0x%x uic error %d\n",
cmd->command, cmd->argument3, ret);
goto out;
}
ret = ufshcd_wait_for_uic_cmd(hba, cmd);
if (ret) {
dev_err(hba->dev,
"pwr ctrl cmd 0x%x with mode 0x%x uic error %d\n",
cmd->command, cmd->argument3, ret);
goto out;
}
if (!wait_for_completion_timeout(hba->uic_async_done,
msecs_to_jiffies(UIC_CMD_TIMEOUT))) {
dev_err(hba->dev,
"pwr ctrl cmd 0x%x with mode 0x%x completion timeout\n",
cmd->command, cmd->argument3);
ret = -ETIMEDOUT;
goto out;
}
status = ufshcd_get_upmcrs(hba);
if (status != PWR_LOCAL) {
dev_err(hba->dev,
"pwr ctrl cmd 0x%0x failed, host umpcrs:0x%x\n",
cmd->command, status);
ret = (status != PWR_OK) ? status : -1;
}
out:
spin_lock_irqsave(hba->host->host_lock, flags);
hba->uic_async_done = NULL;
spin_unlock_irqrestore(hba->host->host_lock, flags);
mutex_unlock(&hba->uic_cmd_mutex);
return ret;
}
static int ufshcd_uic_change_pwr_mode(struct ufs_hba *hba, u8 mode)
{
struct uic_command uic_cmd = {0};
int ret;
if (hba->quirks & UFSHCD_QUIRK_BROKEN_PA_RXHSUNTERMCAP) {
ret = ufshcd_dme_set(hba,
UIC_ARG_MIB_SEL(PA_RXHSUNTERMCAP, 0), 1);
if (ret) {
dev_err(hba->dev, "%s: failed to enable PA_RXHSUNTERMCAP ret %d\n",
__func__, ret);
goto out;
}
}
uic_cmd.command = UIC_CMD_DME_SET;
uic_cmd.argument1 = UIC_ARG_MIB(PA_PWRMODE);
uic_cmd.argument3 = mode;
ufshcd_hold(hba, false);
ret = ufshcd_uic_pwr_ctrl(hba, &uic_cmd);
ufshcd_release(hba);
out:
return ret;
}
static int ufshcd_uic_hibern8_enter(struct ufs_hba *hba)
{
struct uic_command uic_cmd = {0};
uic_cmd.command = UIC_CMD_DME_HIBER_ENTER;
return ufshcd_uic_pwr_ctrl(hba, &uic_cmd);
}
static int ufshcd_uic_hibern8_exit(struct ufs_hba *hba)
{
struct uic_command uic_cmd = {0};
int ret;
uic_cmd.command = UIC_CMD_DME_HIBER_EXIT;
ret = ufshcd_uic_pwr_ctrl(hba, &uic_cmd);
if (ret) {
ufshcd_set_link_off(hba);
ret = ufshcd_host_reset_and_restore(hba);
}
return ret;
}
static void ufshcd_init_pwr_info(struct ufs_hba *hba)
{
hba->pwr_info.gear_rx = UFS_PWM_G1;
hba->pwr_info.gear_tx = UFS_PWM_G1;
hba->pwr_info.lane_rx = 1;
hba->pwr_info.lane_tx = 1;
hba->pwr_info.pwr_rx = SLOWAUTO_MODE;
hba->pwr_info.pwr_tx = SLOWAUTO_MODE;
hba->pwr_info.hs_rate = 0;
}
static int ufshcd_get_max_pwr_mode(struct ufs_hba *hba)
{
struct ufs_pa_layer_attr *pwr_info = &hba->max_pwr_info.info;
if (hba->max_pwr_info.is_valid)
return 0;
pwr_info->pwr_tx = FASTAUTO_MODE;
pwr_info->pwr_rx = FASTAUTO_MODE;
pwr_info->hs_rate = PA_HS_MODE_B;
ufshcd_dme_get(hba, UIC_ARG_MIB(PA_CONNECTEDRXDATALANES),
&pwr_info->lane_rx);
ufshcd_dme_get(hba, UIC_ARG_MIB(PA_CONNECTEDTXDATALANES),
&pwr_info->lane_tx);
if (!pwr_info->lane_rx || !pwr_info->lane_tx) {
dev_err(hba->dev, "%s: invalid connected lanes value. rx=%d, tx=%d\n",
__func__,
pwr_info->lane_rx,
pwr_info->lane_tx);
return -EINVAL;
}
ufshcd_dme_get(hba, UIC_ARG_MIB(PA_MAXRXHSGEAR), &pwr_info->gear_rx);
if (!pwr_info->gear_rx) {
ufshcd_dme_get(hba, UIC_ARG_MIB(PA_MAXRXPWMGEAR),
&pwr_info->gear_rx);
if (!pwr_info->gear_rx) {
dev_err(hba->dev, "%s: invalid max pwm rx gear read = %d\n",
__func__, pwr_info->gear_rx);
return -EINVAL;
}
pwr_info->pwr_rx = SLOWAUTO_MODE;
}
ufshcd_dme_peer_get(hba, UIC_ARG_MIB(PA_MAXRXHSGEAR),
&pwr_info->gear_tx);
if (!pwr_info->gear_tx) {
ufshcd_dme_peer_get(hba, UIC_ARG_MIB(PA_MAXRXPWMGEAR),
&pwr_info->gear_tx);
if (!pwr_info->gear_tx) {
dev_err(hba->dev, "%s: invalid max pwm tx gear read = %d\n",
__func__, pwr_info->gear_tx);
return -EINVAL;
}
pwr_info->pwr_tx = SLOWAUTO_MODE;
}
hba->max_pwr_info.is_valid = true;
return 0;
}
static int ufshcd_change_power_mode(struct ufs_hba *hba,
struct ufs_pa_layer_attr *pwr_mode)
{
int ret;
if (pwr_mode->gear_rx == hba->pwr_info.gear_rx &&
pwr_mode->gear_tx == hba->pwr_info.gear_tx &&
pwr_mode->lane_rx == hba->pwr_info.lane_rx &&
pwr_mode->lane_tx == hba->pwr_info.lane_tx &&
pwr_mode->pwr_rx == hba->pwr_info.pwr_rx &&
pwr_mode->pwr_tx == hba->pwr_info.pwr_tx &&
pwr_mode->hs_rate == hba->pwr_info.hs_rate) {
dev_dbg(hba->dev, "%s: power already configured\n", __func__);
return 0;
}
ufshcd_dme_set(hba, UIC_ARG_MIB(PA_RXGEAR), pwr_mode->gear_rx);
ufshcd_dme_set(hba, UIC_ARG_MIB(PA_ACTIVERXDATALANES),
pwr_mode->lane_rx);
if (pwr_mode->pwr_rx == FASTAUTO_MODE ||
pwr_mode->pwr_rx == FAST_MODE)
ufshcd_dme_set(hba, UIC_ARG_MIB(PA_RXTERMINATION), TRUE);
else
ufshcd_dme_set(hba, UIC_ARG_MIB(PA_RXTERMINATION), FALSE);
ufshcd_dme_set(hba, UIC_ARG_MIB(PA_TXGEAR), pwr_mode->gear_tx);
ufshcd_dme_set(hba, UIC_ARG_MIB(PA_ACTIVETXDATALANES),
pwr_mode->lane_tx);
if (pwr_mode->pwr_tx == FASTAUTO_MODE ||
pwr_mode->pwr_tx == FAST_MODE)
ufshcd_dme_set(hba, UIC_ARG_MIB(PA_TXTERMINATION), TRUE);
else
ufshcd_dme_set(hba, UIC_ARG_MIB(PA_TXTERMINATION), FALSE);
if (pwr_mode->pwr_rx == FASTAUTO_MODE ||
pwr_mode->pwr_tx == FASTAUTO_MODE ||
pwr_mode->pwr_rx == FAST_MODE ||
pwr_mode->pwr_tx == FAST_MODE)
ufshcd_dme_set(hba, UIC_ARG_MIB(PA_HSSERIES),
pwr_mode->hs_rate);
ret = ufshcd_uic_change_pwr_mode(hba, pwr_mode->pwr_rx << 4
| pwr_mode->pwr_tx);
if (ret) {
dev_err(hba->dev,
"%s: power mode change failed %d\n", __func__, ret);
} else {
if (hba->vops && hba->vops->pwr_change_notify)
hba->vops->pwr_change_notify(hba,
POST_CHANGE, NULL, pwr_mode);
memcpy(&hba->pwr_info, pwr_mode,
sizeof(struct ufs_pa_layer_attr));
}
return ret;
}
static int ufshcd_config_pwr_mode(struct ufs_hba *hba,
struct ufs_pa_layer_attr *desired_pwr_mode)
{
struct ufs_pa_layer_attr final_params = { 0 };
int ret;
if (hba->vops && hba->vops->pwr_change_notify)
hba->vops->pwr_change_notify(hba,
PRE_CHANGE, desired_pwr_mode, &final_params);
else
memcpy(&final_params, desired_pwr_mode, sizeof(final_params));
ret = ufshcd_change_power_mode(hba, &final_params);
return ret;
}
static int ufshcd_complete_dev_init(struct ufs_hba *hba)
{
int i, retries, err = 0;
bool flag_res = 1;
for (retries = QUERY_REQ_RETRIES; retries > 0; retries--) {
err = ufshcd_query_flag(hba, UPIU_QUERY_OPCODE_SET_FLAG,
QUERY_FLAG_IDN_FDEVICEINIT, NULL);
if (!err || err == -ETIMEDOUT)
break;
dev_dbg(hba->dev, "%s: error %d retrying\n", __func__, err);
}
if (err) {
dev_err(hba->dev,
"%s setting fDeviceInit flag failed with error %d\n",
__func__, err);
goto out;
}
for (i = 0; i < 100 && !err && flag_res; i++) {
for (retries = QUERY_REQ_RETRIES; retries > 0; retries--) {
err = ufshcd_query_flag(hba,
UPIU_QUERY_OPCODE_READ_FLAG,
QUERY_FLAG_IDN_FDEVICEINIT, &flag_res);
if (!err || err == -ETIMEDOUT)
break;
dev_dbg(hba->dev, "%s: error %d retrying\n", __func__,
err);
}
}
if (err)
dev_err(hba->dev,
"%s reading fDeviceInit flag failed with error %d\n",
__func__, err);
else if (flag_res)
dev_err(hba->dev,
"%s fDeviceInit was not cleared by the device\n",
__func__);
out:
return err;
}
static int ufshcd_make_hba_operational(struct ufs_hba *hba)
{
int err = 0;
u32 reg;
ufshcd_enable_intr(hba, UFSHCD_ENABLE_INTRS);
if (ufshcd_is_intr_aggr_allowed(hba))
ufshcd_config_intr_aggr(hba, hba->nutrs - 1, INT_AGGR_DEF_TO);
else
ufshcd_disable_intr_aggr(hba);
ufshcd_writel(hba, lower_32_bits(hba->utrdl_dma_addr),
REG_UTP_TRANSFER_REQ_LIST_BASE_L);
ufshcd_writel(hba, upper_32_bits(hba->utrdl_dma_addr),
REG_UTP_TRANSFER_REQ_LIST_BASE_H);
ufshcd_writel(hba, lower_32_bits(hba->utmrdl_dma_addr),
REG_UTP_TASK_REQ_LIST_BASE_L);
ufshcd_writel(hba, upper_32_bits(hba->utmrdl_dma_addr),
REG_UTP_TASK_REQ_LIST_BASE_H);
reg = ufshcd_readl(hba, REG_CONTROLLER_STATUS);
if (!(ufshcd_get_lists_status(reg))) {
ufshcd_enable_run_stop_reg(hba);
} else {
dev_err(hba->dev,
"Host controller not ready to process requests");
err = -EIO;
goto out;
}
out:
return err;
}
static int ufshcd_hba_enable(struct ufs_hba *hba)
{
int retry;
if (!ufshcd_is_hba_active(hba)) {
ufshcd_hba_stop(hba);
msleep(5);
}
ufshcd_set_link_off(hba);
if (hba->vops && hba->vops->hce_enable_notify)
hba->vops->hce_enable_notify(hba, PRE_CHANGE);
ufshcd_hba_start(hba);
msleep(1);
retry = 10;
while (ufshcd_is_hba_active(hba)) {
if (retry) {
retry--;
} else {
dev_err(hba->dev,
"Controller enable failed\n");
return -EIO;
}
msleep(5);
}
ufshcd_enable_intr(hba, UFSHCD_UIC_MASK);
if (hba->vops && hba->vops->hce_enable_notify)
hba->vops->hce_enable_notify(hba, POST_CHANGE);
return 0;
}
static int ufshcd_disable_tx_lcc(struct ufs_hba *hba, bool peer)
{
int tx_lanes, i, err = 0;
if (!peer)
ufshcd_dme_get(hba, UIC_ARG_MIB(PA_CONNECTEDTXDATALANES),
&tx_lanes);
else
ufshcd_dme_peer_get(hba, UIC_ARG_MIB(PA_CONNECTEDTXDATALANES),
&tx_lanes);
for (i = 0; i < tx_lanes; i++) {
if (!peer)
err = ufshcd_dme_set(hba,
UIC_ARG_MIB_SEL(TX_LCC_ENABLE,
UIC_ARG_MPHY_TX_GEN_SEL_INDEX(i)),
0);
else
err = ufshcd_dme_peer_set(hba,
UIC_ARG_MIB_SEL(TX_LCC_ENABLE,
UIC_ARG_MPHY_TX_GEN_SEL_INDEX(i)),
0);
if (err) {
dev_err(hba->dev, "%s: TX LCC Disable failed, peer = %d, lane = %d, err = %d",
__func__, peer, i, err);
break;
}
}
return err;
}
static inline int ufshcd_disable_device_tx_lcc(struct ufs_hba *hba)
{
return ufshcd_disable_tx_lcc(hba, true);
}
static int ufshcd_link_startup(struct ufs_hba *hba)
{
int ret;
int retries = DME_LINKSTARTUP_RETRIES;
do {
if (hba->vops && hba->vops->link_startup_notify)
hba->vops->link_startup_notify(hba, PRE_CHANGE);
ret = ufshcd_dme_link_startup(hba);
if (!ret && !ufshcd_is_device_present(hba)) {
dev_err(hba->dev, "%s: Device not present\n", __func__);
ret = -ENXIO;
goto out;
}
if (ret && ufshcd_hba_enable(hba))
goto out;
} while (ret && retries--);
if (ret)
goto out;
if (hba->quirks & UFSHCD_QUIRK_BROKEN_LCC) {
ret = ufshcd_disable_device_tx_lcc(hba);
if (ret)
goto out;
}
if (hba->vops && hba->vops->link_startup_notify) {
ret = hba->vops->link_startup_notify(hba, POST_CHANGE);
if (ret)
goto out;
}
ret = ufshcd_make_hba_operational(hba);
out:
if (ret)
dev_err(hba->dev, "link startup failed %d\n", ret);
return ret;
}
static int ufshcd_verify_dev_init(struct ufs_hba *hba)
{
int err = 0;
int retries;
ufshcd_hold(hba, false);
mutex_lock(&hba->dev_cmd.lock);
for (retries = NOP_OUT_RETRIES; retries > 0; retries--) {
err = ufshcd_exec_dev_cmd(hba, DEV_CMD_TYPE_NOP,
NOP_OUT_TIMEOUT);
if (!err || err == -ETIMEDOUT)
break;
dev_dbg(hba->dev, "%s: error %d retrying\n", __func__, err);
}
mutex_unlock(&hba->dev_cmd.lock);
ufshcd_release(hba);
if (err)
dev_err(hba->dev, "%s: NOP OUT failed %d\n", __func__, err);
return err;
}
static void ufshcd_set_queue_depth(struct scsi_device *sdev)
{
int ret = 0;
u8 lun_qdepth;
struct ufs_hba *hba;
hba = shost_priv(sdev->host);
lun_qdepth = hba->nutrs;
ret = ufshcd_read_unit_desc_param(hba,
ufshcd_scsi_to_upiu_lun(sdev->lun),
UNIT_DESC_PARAM_LU_Q_DEPTH,
&lun_qdepth,
sizeof(lun_qdepth));
if (ret == -EOPNOTSUPP)
lun_qdepth = 1;
else if (!lun_qdepth)
lun_qdepth = hba->nutrs;
else
lun_qdepth = min_t(int, lun_qdepth, hba->nutrs);
dev_dbg(hba->dev, "%s: activate tcq with queue depth %d\n",
__func__, lun_qdepth);
scsi_change_queue_depth(sdev, lun_qdepth);
}
static int ufshcd_get_lu_wp(struct ufs_hba *hba,
u8 lun,
u8 *b_lu_write_protect)
{
int ret;
if (!b_lu_write_protect)
ret = -EINVAL;
else if (lun >= UFS_UPIU_MAX_GENERAL_LUN)
ret = -ENOTSUPP;
else
ret = ufshcd_read_unit_desc_param(hba,
lun,
UNIT_DESC_PARAM_LU_WR_PROTECT,
b_lu_write_protect,
sizeof(*b_lu_write_protect));
return ret;
}
static inline void ufshcd_get_lu_power_on_wp_status(struct ufs_hba *hba,
struct scsi_device *sdev)
{
if (hba->dev_info.f_power_on_wp_en &&
!hba->dev_info.is_lu_power_on_wp) {
u8 b_lu_write_protect;
if (!ufshcd_get_lu_wp(hba, ufshcd_scsi_to_upiu_lun(sdev->lun),
&b_lu_write_protect) &&
(b_lu_write_protect == UFS_LU_POWER_ON_WP))
hba->dev_info.is_lu_power_on_wp = true;
}
}
static int ufshcd_slave_alloc(struct scsi_device *sdev)
{
struct ufs_hba *hba;
hba = shost_priv(sdev->host);
sdev->use_10_for_ms = 1;
sdev->allow_restart = 1;
sdev->no_report_opcodes = 1;
ufshcd_set_queue_depth(sdev);
ufshcd_get_lu_power_on_wp_status(hba, sdev);
return 0;
}
static int ufshcd_change_queue_depth(struct scsi_device *sdev, int depth)
{
struct ufs_hba *hba = shost_priv(sdev->host);
if (depth > hba->nutrs)
depth = hba->nutrs;
return scsi_change_queue_depth(sdev, depth);
}
static int ufshcd_slave_configure(struct scsi_device *sdev)
{
struct request_queue *q = sdev->request_queue;
blk_queue_update_dma_pad(q, PRDT_DATA_BYTE_COUNT_PAD - 1);
blk_queue_max_segment_size(q, PRDT_DATA_BYTE_COUNT_MAX);
return 0;
}
static void ufshcd_slave_destroy(struct scsi_device *sdev)
{
struct ufs_hba *hba;
hba = shost_priv(sdev->host);
if (ufshcd_scsi_to_upiu_lun(sdev->lun) == UFS_UPIU_UFS_DEVICE_WLUN) {
unsigned long flags;
spin_lock_irqsave(hba->host->host_lock, flags);
hba->sdev_ufs_device = NULL;
spin_unlock_irqrestore(hba->host->host_lock, flags);
}
}
static int ufshcd_task_req_compl(struct ufs_hba *hba, u32 index, u8 *resp)
{
struct utp_task_req_desc *task_req_descp;
struct utp_upiu_task_rsp *task_rsp_upiup;
unsigned long flags;
int ocs_value;
int task_result;
spin_lock_irqsave(hba->host->host_lock, flags);
__clear_bit(index, &hba->outstanding_tasks);
task_req_descp = hba->utmrdl_base_addr;
ocs_value = ufshcd_get_tmr_ocs(&task_req_descp[index]);
if (ocs_value == OCS_SUCCESS) {
task_rsp_upiup = (struct utp_upiu_task_rsp *)
task_req_descp[index].task_rsp_upiu;
task_result = be32_to_cpu(task_rsp_upiup->header.dword_1);
task_result = ((task_result & MASK_TASK_RESPONSE) >> 8);
if (resp)
*resp = (u8)task_result;
} else {
dev_err(hba->dev, "%s: failed, ocs = 0x%x\n",
__func__, ocs_value);
}
spin_unlock_irqrestore(hba->host->host_lock, flags);
return ocs_value;
}
static inline int
ufshcd_scsi_cmd_status(struct ufshcd_lrb *lrbp, int scsi_status)
{
int result = 0;
switch (scsi_status) {
case SAM_STAT_CHECK_CONDITION:
ufshcd_copy_sense_data(lrbp);
case SAM_STAT_GOOD:
result |= DID_OK << 16 |
COMMAND_COMPLETE << 8 |
scsi_status;
break;
case SAM_STAT_TASK_SET_FULL:
case SAM_STAT_BUSY:
case SAM_STAT_TASK_ABORTED:
ufshcd_copy_sense_data(lrbp);
result |= scsi_status;
break;
default:
result |= DID_ERROR << 16;
break;
}
return result;
}
static inline int
ufshcd_transfer_rsp_status(struct ufs_hba *hba, struct ufshcd_lrb *lrbp)
{
int result = 0;
int scsi_status;
int ocs;
ocs = ufshcd_get_tr_ocs(lrbp);
switch (ocs) {
case OCS_SUCCESS:
result = ufshcd_get_req_rsp(lrbp->ucd_rsp_ptr);
switch (result) {
case UPIU_TRANSACTION_RESPONSE:
result = ufshcd_get_rsp_upiu_result(lrbp->ucd_rsp_ptr);
scsi_status = result & MASK_SCSI_STATUS;
result = ufshcd_scsi_cmd_status(lrbp, scsi_status);
if (ufshcd_is_exception_event(lrbp->ucd_rsp_ptr))
schedule_work(&hba->eeh_work);
break;
case UPIU_TRANSACTION_REJECT_UPIU:
result = DID_ERROR << 16;
dev_err(hba->dev,
"Reject UPIU not fully implemented\n");
break;
default:
result = DID_ERROR << 16;
dev_err(hba->dev,
"Unexpected request response code = %x\n",
result);
break;
}
break;
case OCS_ABORTED:
result |= DID_ABORT << 16;
break;
case OCS_INVALID_COMMAND_STATUS:
result |= DID_REQUEUE << 16;
break;
case OCS_INVALID_CMD_TABLE_ATTR:
case OCS_INVALID_PRDT_ATTR:
case OCS_MISMATCH_DATA_BUF_SIZE:
case OCS_MISMATCH_RESP_UPIU_SIZE:
case OCS_PEER_COMM_FAILURE:
case OCS_FATAL_ERROR:
default:
result |= DID_ERROR << 16;
dev_err(hba->dev,
"OCS error from controller = %x\n", ocs);
break;
}
return result;
}
static void ufshcd_uic_cmd_compl(struct ufs_hba *hba, u32 intr_status)
{
if ((intr_status & UIC_COMMAND_COMPL) && hba->active_uic_cmd) {
hba->active_uic_cmd->argument2 |=
ufshcd_get_uic_cmd_result(hba);
hba->active_uic_cmd->argument3 =
ufshcd_get_dme_attr_val(hba);
complete(&hba->active_uic_cmd->done);
}
if ((intr_status & UFSHCD_UIC_PWR_MASK) && hba->uic_async_done)
complete(hba->uic_async_done);
}
static void ufshcd_transfer_req_compl(struct ufs_hba *hba)
{
struct ufshcd_lrb *lrbp;
struct scsi_cmnd *cmd;
unsigned long completed_reqs;
u32 tr_doorbell;
int result;
int index;
if (ufshcd_is_intr_aggr_allowed(hba))
ufshcd_reset_intr_aggr(hba);
tr_doorbell = ufshcd_readl(hba, REG_UTP_TRANSFER_REQ_DOOR_BELL);
completed_reqs = tr_doorbell ^ hba->outstanding_reqs;
for_each_set_bit(index, &completed_reqs, hba->nutrs) {
lrbp = &hba->lrb[index];
cmd = lrbp->cmd;
if (cmd) {
result = ufshcd_transfer_rsp_status(hba, lrbp);
scsi_dma_unmap(cmd);
cmd->result = result;
lrbp->cmd = NULL;
clear_bit_unlock(index, &hba->lrb_in_use);
cmd->scsi_done(cmd);
__ufshcd_release(hba);
} else if (lrbp->command_type == UTP_CMD_TYPE_DEV_MANAGE) {
if (hba->dev_cmd.complete)
complete(hba->dev_cmd.complete);
}
}
hba->outstanding_reqs ^= completed_reqs;
ufshcd_clk_scaling_update_busy(hba);
wake_up(&hba->dev_cmd.tag_wq);
}
static int ufshcd_disable_ee(struct ufs_hba *hba, u16 mask)
{
int err = 0;
u32 val;
if (!(hba->ee_ctrl_mask & mask))
goto out;
val = hba->ee_ctrl_mask & ~mask;
val &= 0xFFFF;
err = ufshcd_query_attr(hba, UPIU_QUERY_OPCODE_WRITE_ATTR,
QUERY_ATTR_IDN_EE_CONTROL, 0, 0, &val);
if (!err)
hba->ee_ctrl_mask &= ~mask;
out:
return err;
}
static int ufshcd_enable_ee(struct ufs_hba *hba, u16 mask)
{
int err = 0;
u32 val;
if (hba->ee_ctrl_mask & mask)
goto out;
val = hba->ee_ctrl_mask | mask;
val &= 0xFFFF;
err = ufshcd_query_attr(hba, UPIU_QUERY_OPCODE_WRITE_ATTR,
QUERY_ATTR_IDN_EE_CONTROL, 0, 0, &val);
if (!err)
hba->ee_ctrl_mask |= mask;
out:
return err;
}
static int ufshcd_enable_auto_bkops(struct ufs_hba *hba)
{
int err = 0;
if (hba->auto_bkops_enabled)
goto out;
err = ufshcd_query_flag(hba, UPIU_QUERY_OPCODE_SET_FLAG,
QUERY_FLAG_IDN_BKOPS_EN, NULL);
if (err) {
dev_err(hba->dev, "%s: failed to enable bkops %d\n",
__func__, err);
goto out;
}
hba->auto_bkops_enabled = true;
err = ufshcd_disable_ee(hba, MASK_EE_URGENT_BKOPS);
if (err)
dev_err(hba->dev, "%s: failed to disable exception event %d\n",
__func__, err);
out:
return err;
}
static int ufshcd_disable_auto_bkops(struct ufs_hba *hba)
{
int err = 0;
if (!hba->auto_bkops_enabled)
goto out;
err = ufshcd_enable_ee(hba, MASK_EE_URGENT_BKOPS);
if (err) {
dev_err(hba->dev, "%s: failed to enable exception event %d\n",
__func__, err);
goto out;
}
err = ufshcd_query_flag(hba, UPIU_QUERY_OPCODE_CLEAR_FLAG,
QUERY_FLAG_IDN_BKOPS_EN, NULL);
if (err) {
dev_err(hba->dev, "%s: failed to disable bkops %d\n",
__func__, err);
ufshcd_disable_ee(hba, MASK_EE_URGENT_BKOPS);
goto out;
}
hba->auto_bkops_enabled = false;
out:
return err;
}
static void ufshcd_force_reset_auto_bkops(struct ufs_hba *hba)
{
hba->auto_bkops_enabled = false;
hba->ee_ctrl_mask |= MASK_EE_URGENT_BKOPS;
ufshcd_enable_auto_bkops(hba);
}
static inline int ufshcd_get_bkops_status(struct ufs_hba *hba, u32 *status)
{
return ufshcd_query_attr(hba, UPIU_QUERY_OPCODE_READ_ATTR,
QUERY_ATTR_IDN_BKOPS_STATUS, 0, 0, status);
}
static int ufshcd_bkops_ctrl(struct ufs_hba *hba,
enum bkops_status status)
{
int err;
u32 curr_status = 0;
err = ufshcd_get_bkops_status(hba, &curr_status);
if (err) {
dev_err(hba->dev, "%s: failed to get BKOPS status %d\n",
__func__, err);
goto out;
} else if (curr_status > BKOPS_STATUS_MAX) {
dev_err(hba->dev, "%s: invalid BKOPS status %d\n",
__func__, curr_status);
err = -EINVAL;
goto out;
}
if (curr_status >= status)
err = ufshcd_enable_auto_bkops(hba);
else
err = ufshcd_disable_auto_bkops(hba);
out:
return err;
}
static int ufshcd_urgent_bkops(struct ufs_hba *hba)
{
return ufshcd_bkops_ctrl(hba, BKOPS_STATUS_PERF_IMPACT);
}
static inline int ufshcd_get_ee_status(struct ufs_hba *hba, u32 *status)
{
return ufshcd_query_attr(hba, UPIU_QUERY_OPCODE_READ_ATTR,
QUERY_ATTR_IDN_EE_STATUS, 0, 0, status);
}
static void ufshcd_exception_event_handler(struct work_struct *work)
{
struct ufs_hba *hba;
int err;
u32 status = 0;
hba = container_of(work, struct ufs_hba, eeh_work);
pm_runtime_get_sync(hba->dev);
err = ufshcd_get_ee_status(hba, &status);
if (err) {
dev_err(hba->dev, "%s: failed to get exception status %d\n",
__func__, err);
goto out;
}
status &= hba->ee_ctrl_mask;
if (status & MASK_EE_URGENT_BKOPS) {
err = ufshcd_urgent_bkops(hba);
if (err < 0)
dev_err(hba->dev, "%s: failed to handle urgent bkops %d\n",
__func__, err);
}
out:
pm_runtime_put_sync(hba->dev);
return;
}
static void ufshcd_err_handler(struct work_struct *work)
{
struct ufs_hba *hba;
unsigned long flags;
u32 err_xfer = 0;
u32 err_tm = 0;
int err = 0;
int tag;
hba = container_of(work, struct ufs_hba, eh_work);
pm_runtime_get_sync(hba->dev);
ufshcd_hold(hba, false);
spin_lock_irqsave(hba->host->host_lock, flags);
if (hba->ufshcd_state == UFSHCD_STATE_RESET) {
spin_unlock_irqrestore(hba->host->host_lock, flags);
goto out;
}
hba->ufshcd_state = UFSHCD_STATE_RESET;
ufshcd_set_eh_in_progress(hba);
ufshcd_transfer_req_compl(hba);
ufshcd_tmc_handler(hba);
spin_unlock_irqrestore(hba->host->host_lock, flags);
for_each_set_bit(tag, &hba->outstanding_reqs, hba->nutrs)
if (ufshcd_clear_cmd(hba, tag))
err_xfer |= 1 << tag;
for_each_set_bit(tag, &hba->outstanding_tasks, hba->nutmrs)
if (ufshcd_clear_tm_cmd(hba, tag))
err_tm |= 1 << tag;
spin_lock_irqsave(hba->host->host_lock, flags);
ufshcd_transfer_req_compl(hba);
ufshcd_tmc_handler(hba);
spin_unlock_irqrestore(hba->host->host_lock, flags);
if (err_xfer || err_tm || (hba->saved_err & INT_FATAL_ERRORS) ||
((hba->saved_err & UIC_ERROR) &&
(hba->saved_uic_err & UFSHCD_UIC_DL_PA_INIT_ERROR))) {
err = ufshcd_reset_and_restore(hba);
if (err) {
dev_err(hba->dev, "%s: reset and restore failed\n",
__func__);
hba->ufshcd_state = UFSHCD_STATE_ERROR;
}
scsi_report_bus_reset(hba->host, 0);
hba->saved_err = 0;
hba->saved_uic_err = 0;
}
ufshcd_clear_eh_in_progress(hba);
out:
scsi_unblock_requests(hba->host);
ufshcd_release(hba);
pm_runtime_put_sync(hba->dev);
}
static void ufshcd_update_uic_error(struct ufs_hba *hba)
{
u32 reg;
reg = ufshcd_readl(hba, REG_UIC_ERROR_CODE_DATA_LINK_LAYER);
if (reg & UIC_DATA_LINK_LAYER_ERROR_PA_INIT)
hba->uic_error |= UFSHCD_UIC_DL_PA_INIT_ERROR;
reg = ufshcd_readl(hba, REG_UIC_ERROR_CODE_NETWORK_LAYER);
if (reg)
hba->uic_error |= UFSHCD_UIC_NL_ERROR;
reg = ufshcd_readl(hba, REG_UIC_ERROR_CODE_TRANSPORT_LAYER);
if (reg)
hba->uic_error |= UFSHCD_UIC_TL_ERROR;
reg = ufshcd_readl(hba, REG_UIC_ERROR_CODE_DME);
if (reg)
hba->uic_error |= UFSHCD_UIC_DME_ERROR;
dev_dbg(hba->dev, "%s: UIC error flags = 0x%08x\n",
__func__, hba->uic_error);
}
static void ufshcd_check_errors(struct ufs_hba *hba)
{
bool queue_eh_work = false;
if (hba->errors & INT_FATAL_ERRORS)
queue_eh_work = true;
if (hba->errors & UIC_ERROR) {
hba->uic_error = 0;
ufshcd_update_uic_error(hba);
if (hba->uic_error)
queue_eh_work = true;
}
if (queue_eh_work) {
if (hba->ufshcd_state == UFSHCD_STATE_OPERATIONAL) {
scsi_block_requests(hba->host);
hba->saved_err |= hba->errors;
hba->saved_uic_err |= hba->uic_error;
hba->ufshcd_state = UFSHCD_STATE_ERROR;
schedule_work(&hba->eh_work);
}
}
}
static void ufshcd_tmc_handler(struct ufs_hba *hba)
{
u32 tm_doorbell;
tm_doorbell = ufshcd_readl(hba, REG_UTP_TASK_REQ_DOOR_BELL);
hba->tm_condition = tm_doorbell ^ hba->outstanding_tasks;
wake_up(&hba->tm_wq);
}
static void ufshcd_sl_intr(struct ufs_hba *hba, u32 intr_status)
{
hba->errors = UFSHCD_ERROR_MASK & intr_status;
if (hba->errors)
ufshcd_check_errors(hba);
if (intr_status & UFSHCD_UIC_MASK)
ufshcd_uic_cmd_compl(hba, intr_status);
if (intr_status & UTP_TASK_REQ_COMPL)
ufshcd_tmc_handler(hba);
if (intr_status & UTP_TRANSFER_REQ_COMPL)
ufshcd_transfer_req_compl(hba);
}
static irqreturn_t ufshcd_intr(int irq, void *__hba)
{
u32 intr_status;
irqreturn_t retval = IRQ_NONE;
struct ufs_hba *hba = __hba;
spin_lock(hba->host->host_lock);
intr_status = ufshcd_readl(hba, REG_INTERRUPT_STATUS);
if (intr_status) {
ufshcd_writel(hba, intr_status, REG_INTERRUPT_STATUS);
ufshcd_sl_intr(hba, intr_status);
retval = IRQ_HANDLED;
}
spin_unlock(hba->host->host_lock);
return retval;
}
static int ufshcd_clear_tm_cmd(struct ufs_hba *hba, int tag)
{
int err = 0;
u32 mask = 1 << tag;
unsigned long flags;
if (!test_bit(tag, &hba->outstanding_tasks))
goto out;
spin_lock_irqsave(hba->host->host_lock, flags);
ufshcd_writel(hba, ~(1 << tag), REG_UTP_TASK_REQ_LIST_CLEAR);
spin_unlock_irqrestore(hba->host->host_lock, flags);
err = ufshcd_wait_for_register(hba,
REG_UTP_TASK_REQ_DOOR_BELL,
mask, 0, 1000, 1000);
out:
return err;
}
static int ufshcd_issue_tm_cmd(struct ufs_hba *hba, int lun_id, int task_id,
u8 tm_function, u8 *tm_response)
{
struct utp_task_req_desc *task_req_descp;
struct utp_upiu_task_req *task_req_upiup;
struct Scsi_Host *host;
unsigned long flags;
int free_slot;
int err;
int task_tag;
host = hba->host;
wait_event(hba->tm_tag_wq, ufshcd_get_tm_free_slot(hba, &free_slot));
ufshcd_hold(hba, false);
spin_lock_irqsave(host->host_lock, flags);
task_req_descp = hba->utmrdl_base_addr;
task_req_descp += free_slot;
task_req_descp->header.dword_0 = cpu_to_le32(UTP_REQ_DESC_INT_CMD);
task_req_descp->header.dword_2 =
cpu_to_le32(OCS_INVALID_COMMAND_STATUS);
task_req_upiup =
(struct utp_upiu_task_req *) task_req_descp->task_req_upiu;
task_tag = hba->nutrs + free_slot;
task_req_upiup->header.dword_0 =
UPIU_HEADER_DWORD(UPIU_TRANSACTION_TASK_REQ, 0,
lun_id, task_tag);
task_req_upiup->header.dword_1 =
UPIU_HEADER_DWORD(0, tm_function, 0, 0);
task_req_upiup->input_param1 = cpu_to_be32(lun_id);
task_req_upiup->input_param2 = cpu_to_be32(task_id);
__set_bit(free_slot, &hba->outstanding_tasks);
ufshcd_writel(hba, 1 << free_slot, REG_UTP_TASK_REQ_DOOR_BELL);
spin_unlock_irqrestore(host->host_lock, flags);
err = wait_event_timeout(hba->tm_wq,
test_bit(free_slot, &hba->tm_condition),
msecs_to_jiffies(TM_CMD_TIMEOUT));
if (!err) {
dev_err(hba->dev, "%s: task management cmd 0x%.2x timed-out\n",
__func__, tm_function);
if (ufshcd_clear_tm_cmd(hba, free_slot))
dev_WARN(hba->dev, "%s: unable clear tm cmd (slot %d) after timeout\n",
__func__, free_slot);
err = -ETIMEDOUT;
} else {
err = ufshcd_task_req_compl(hba, free_slot, tm_response);
}
clear_bit(free_slot, &hba->tm_condition);
ufshcd_put_tm_slot(hba, free_slot);
wake_up(&hba->tm_tag_wq);
ufshcd_release(hba);
return err;
}
static int ufshcd_eh_device_reset_handler(struct scsi_cmnd *cmd)
{
struct Scsi_Host *host;
struct ufs_hba *hba;
unsigned int tag;
u32 pos;
int err;
u8 resp = 0xF;
struct ufshcd_lrb *lrbp;
unsigned long flags;
host = cmd->device->host;
hba = shost_priv(host);
tag = cmd->request->tag;
lrbp = &hba->lrb[tag];
err = ufshcd_issue_tm_cmd(hba, lrbp->lun, 0, UFS_LOGICAL_RESET, &resp);
if (err || resp != UPIU_TASK_MANAGEMENT_FUNC_COMPL) {
if (!err)
err = resp;
goto out;
}
for_each_set_bit(pos, &hba->outstanding_reqs, hba->nutrs) {
if (hba->lrb[pos].lun == lrbp->lun) {
err = ufshcd_clear_cmd(hba, pos);
if (err)
break;
}
}
spin_lock_irqsave(host->host_lock, flags);
ufshcd_transfer_req_compl(hba);
spin_unlock_irqrestore(host->host_lock, flags);
out:
if (!err) {
err = SUCCESS;
} else {
dev_err(hba->dev, "%s: failed with err %d\n", __func__, err);
err = FAILED;
}
return err;
}
static int ufshcd_abort(struct scsi_cmnd *cmd)
{
struct Scsi_Host *host;
struct ufs_hba *hba;
unsigned long flags;
unsigned int tag;
int err = 0;
int poll_cnt;
u8 resp = 0xF;
struct ufshcd_lrb *lrbp;
u32 reg;
host = cmd->device->host;
hba = shost_priv(host);
tag = cmd->request->tag;
ufshcd_hold(hba, false);
if (!(test_bit(tag, &hba->outstanding_reqs)))
goto out;
reg = ufshcd_readl(hba, REG_UTP_TRANSFER_REQ_DOOR_BELL);
if (!(reg & (1 << tag))) {
dev_err(hba->dev,
"%s: cmd was completed, but without a notifying intr, tag = %d",
__func__, tag);
}
lrbp = &hba->lrb[tag];
for (poll_cnt = 100; poll_cnt; poll_cnt--) {
err = ufshcd_issue_tm_cmd(hba, lrbp->lun, lrbp->task_tag,
UFS_QUERY_TASK, &resp);
if (!err && resp == UPIU_TASK_MANAGEMENT_FUNC_SUCCEEDED) {
break;
} else if (!err && resp == UPIU_TASK_MANAGEMENT_FUNC_COMPL) {
reg = ufshcd_readl(hba, REG_UTP_TRANSFER_REQ_DOOR_BELL);
if (reg & (1 << tag)) {
usleep_range(100, 200);
continue;
}
goto out;
} else {
if (!err)
err = resp;
goto out;
}
}
if (!poll_cnt) {
err = -EBUSY;
goto out;
}
err = ufshcd_issue_tm_cmd(hba, lrbp->lun, lrbp->task_tag,
UFS_ABORT_TASK, &resp);
if (err || resp != UPIU_TASK_MANAGEMENT_FUNC_COMPL) {
if (!err)
err = resp;
goto out;
}
err = ufshcd_clear_cmd(hba, tag);
if (err)
goto out;
scsi_dma_unmap(cmd);
spin_lock_irqsave(host->host_lock, flags);
__clear_bit(tag, &hba->outstanding_reqs);
hba->lrb[tag].cmd = NULL;
spin_unlock_irqrestore(host->host_lock, flags);
clear_bit_unlock(tag, &hba->lrb_in_use);
wake_up(&hba->dev_cmd.tag_wq);
out:
if (!err) {
err = SUCCESS;
} else {
dev_err(hba->dev, "%s: failed with err %d\n", __func__, err);
err = FAILED;
}
ufshcd_release(hba);
return err;
}
static int ufshcd_host_reset_and_restore(struct ufs_hba *hba)
{
int err;
unsigned long flags;
spin_lock_irqsave(hba->host->host_lock, flags);
ufshcd_hba_stop(hba);
spin_unlock_irqrestore(hba->host->host_lock, flags);
err = ufshcd_hba_enable(hba);
if (err)
goto out;
err = ufshcd_probe_hba(hba);
if (!err && (hba->ufshcd_state != UFSHCD_STATE_OPERATIONAL))
err = -EIO;
out:
if (err)
dev_err(hba->dev, "%s: Host init failed %d\n", __func__, err);
return err;
}
static int ufshcd_reset_and_restore(struct ufs_hba *hba)
{
int err = 0;
unsigned long flags;
int retries = MAX_HOST_RESET_RETRIES;
do {
err = ufshcd_host_reset_and_restore(hba);
} while (err && --retries);
spin_lock_irqsave(hba->host->host_lock, flags);
ufshcd_transfer_req_compl(hba);
ufshcd_tmc_handler(hba);
spin_unlock_irqrestore(hba->host->host_lock, flags);
return err;
}
static int ufshcd_eh_host_reset_handler(struct scsi_cmnd *cmd)
{
int err;
unsigned long flags;
struct ufs_hba *hba;
hba = shost_priv(cmd->device->host);
ufshcd_hold(hba, false);
do {
spin_lock_irqsave(hba->host->host_lock, flags);
if (!(work_pending(&hba->eh_work) ||
hba->ufshcd_state == UFSHCD_STATE_RESET))
break;
spin_unlock_irqrestore(hba->host->host_lock, flags);
dev_dbg(hba->dev, "%s: reset in progress\n", __func__);
flush_work(&hba->eh_work);
} while (1);
hba->ufshcd_state = UFSHCD_STATE_RESET;
ufshcd_set_eh_in_progress(hba);
spin_unlock_irqrestore(hba->host->host_lock, flags);
err = ufshcd_reset_and_restore(hba);
spin_lock_irqsave(hba->host->host_lock, flags);
if (!err) {
err = SUCCESS;
hba->ufshcd_state = UFSHCD_STATE_OPERATIONAL;
} else {
err = FAILED;
hba->ufshcd_state = UFSHCD_STATE_ERROR;
}
ufshcd_clear_eh_in_progress(hba);
spin_unlock_irqrestore(hba->host->host_lock, flags);
ufshcd_release(hba);
return err;
}
static u32 ufshcd_get_max_icc_level(int sup_curr_uA, u32 start_scan, char *buff)
{
int i;
int curr_uA;
u16 data;
u16 unit;
for (i = start_scan; i >= 0; i--) {
data = be16_to_cpu(*((u16 *)(buff + 2*i)));
unit = (data & ATTR_ICC_LVL_UNIT_MASK) >>
ATTR_ICC_LVL_UNIT_OFFSET;
curr_uA = data & ATTR_ICC_LVL_VALUE_MASK;
switch (unit) {
case UFSHCD_NANO_AMP:
curr_uA = curr_uA / 1000;
break;
case UFSHCD_MILI_AMP:
curr_uA = curr_uA * 1000;
break;
case UFSHCD_AMP:
curr_uA = curr_uA * 1000 * 1000;
break;
case UFSHCD_MICRO_AMP:
default:
break;
}
if (sup_curr_uA >= curr_uA)
break;
}
if (i < 0) {
i = 0;
pr_err("%s: Couldn't find valid icc_level = %d", __func__, i);
}
return (u32)i;
}
static u32 ufshcd_find_max_sup_active_icc_level(struct ufs_hba *hba,
u8 *desc_buf, int len)
{
u32 icc_level = 0;
if (!hba->vreg_info.vcc || !hba->vreg_info.vccq ||
!hba->vreg_info.vccq2) {
dev_err(hba->dev,
"%s: Regulator capability was not set, actvIccLevel=%d",
__func__, icc_level);
goto out;
}
if (hba->vreg_info.vcc)
icc_level = ufshcd_get_max_icc_level(
hba->vreg_info.vcc->max_uA,
POWER_DESC_MAX_ACTV_ICC_LVLS - 1,
&desc_buf[PWR_DESC_ACTIVE_LVLS_VCC_0]);
if (hba->vreg_info.vccq)
icc_level = ufshcd_get_max_icc_level(
hba->vreg_info.vccq->max_uA,
icc_level,
&desc_buf[PWR_DESC_ACTIVE_LVLS_VCCQ_0]);
if (hba->vreg_info.vccq2)
icc_level = ufshcd_get_max_icc_level(
hba->vreg_info.vccq2->max_uA,
icc_level,
&desc_buf[PWR_DESC_ACTIVE_LVLS_VCCQ2_0]);
out:
return icc_level;
}
static void ufshcd_init_icc_levels(struct ufs_hba *hba)
{
int ret;
int buff_len = QUERY_DESC_POWER_MAX_SIZE;
u8 desc_buf[QUERY_DESC_POWER_MAX_SIZE];
ret = ufshcd_read_power_desc(hba, desc_buf, buff_len);
if (ret) {
dev_err(hba->dev,
"%s: Failed reading power descriptor.len = %d ret = %d",
__func__, buff_len, ret);
return;
}
hba->init_prefetch_data.icc_level =
ufshcd_find_max_sup_active_icc_level(hba,
desc_buf, buff_len);
dev_dbg(hba->dev, "%s: setting icc_level 0x%x",
__func__, hba->init_prefetch_data.icc_level);
ret = ufshcd_query_attr(hba, UPIU_QUERY_OPCODE_WRITE_ATTR,
QUERY_ATTR_IDN_ACTIVE_ICC_LVL, 0, 0,
&hba->init_prefetch_data.icc_level);
if (ret)
dev_err(hba->dev,
"%s: Failed configuring bActiveICCLevel = %d ret = %d",
__func__, hba->init_prefetch_data.icc_level , ret);
}
static int ufshcd_scsi_add_wlus(struct ufs_hba *hba)
{
int ret = 0;
struct scsi_device *sdev_rpmb;
struct scsi_device *sdev_boot;
hba->sdev_ufs_device = __scsi_add_device(hba->host, 0, 0,
ufshcd_upiu_wlun_to_scsi_wlun(UFS_UPIU_UFS_DEVICE_WLUN), NULL);
if (IS_ERR(hba->sdev_ufs_device)) {
ret = PTR_ERR(hba->sdev_ufs_device);
hba->sdev_ufs_device = NULL;
goto out;
}
scsi_device_put(hba->sdev_ufs_device);
sdev_boot = __scsi_add_device(hba->host, 0, 0,
ufshcd_upiu_wlun_to_scsi_wlun(UFS_UPIU_BOOT_WLUN), NULL);
if (IS_ERR(sdev_boot)) {
ret = PTR_ERR(sdev_boot);
goto remove_sdev_ufs_device;
}
scsi_device_put(sdev_boot);
sdev_rpmb = __scsi_add_device(hba->host, 0, 0,
ufshcd_upiu_wlun_to_scsi_wlun(UFS_UPIU_RPMB_WLUN), NULL);
if (IS_ERR(sdev_rpmb)) {
ret = PTR_ERR(sdev_rpmb);
goto remove_sdev_boot;
}
scsi_device_put(sdev_rpmb);
goto out;
remove_sdev_boot:
scsi_remove_device(sdev_boot);
remove_sdev_ufs_device:
scsi_remove_device(hba->sdev_ufs_device);
out:
return ret;
}
static int ufshcd_probe_hba(struct ufs_hba *hba)
{
int ret;
ret = ufshcd_link_startup(hba);
if (ret)
goto out;
ufshcd_init_pwr_info(hba);
ufshcd_set_link_active(hba);
ret = ufshcd_verify_dev_init(hba);
if (ret)
goto out;
ret = ufshcd_complete_dev_init(hba);
if (ret)
goto out;
ufshcd_set_ufs_dev_active(hba);
ufshcd_force_reset_auto_bkops(hba);
hba->ufshcd_state = UFSHCD_STATE_OPERATIONAL;
hba->wlun_dev_clr_ua = true;
if (ufshcd_get_max_pwr_mode(hba)) {
dev_err(hba->dev,
"%s: Failed getting max supported power mode\n",
__func__);
} else {
ret = ufshcd_config_pwr_mode(hba, &hba->max_pwr_info.info);
if (ret)
dev_err(hba->dev, "%s: Failed setting power mode, err = %d\n",
__func__, ret);
}
if (!ufshcd_eh_in_progress(hba) && !hba->pm_op_in_progress) {
bool flag;
memset(&hba->dev_info, 0, sizeof(hba->dev_info));
if (!ufshcd_query_flag(hba, UPIU_QUERY_OPCODE_READ_FLAG,
QUERY_FLAG_IDN_PWR_ON_WPE, &flag))
hba->dev_info.f_power_on_wp_en = flag;
if (!hba->is_init_prefetch)
ufshcd_init_icc_levels(hba);
if (ufshcd_scsi_add_wlus(hba))
goto out;
scsi_scan_host(hba->host);
pm_runtime_put_sync(hba->dev);
}
if (!hba->is_init_prefetch)
hba->is_init_prefetch = true;
if (ufshcd_is_clkscaling_enabled(hba))
devfreq_resume_device(hba->devfreq);
out:
if (ret && !ufshcd_eh_in_progress(hba) && !hba->pm_op_in_progress) {
pm_runtime_put_sync(hba->dev);
ufshcd_hba_exit(hba);
}
return ret;
}
static void ufshcd_async_scan(void *data, async_cookie_t cookie)
{
struct ufs_hba *hba = (struct ufs_hba *)data;
ufshcd_probe_hba(hba);
}
static int ufshcd_config_vreg_load(struct device *dev, struct ufs_vreg *vreg,
int ua)
{
int ret;
if (!vreg)
return 0;
ret = regulator_set_load(vreg->reg, ua);
if (ret < 0) {
dev_err(dev, "%s: %s set load (ua=%d) failed, err=%d\n",
__func__, vreg->name, ua, ret);
}
return ret;
}
static inline int ufshcd_config_vreg_lpm(struct ufs_hba *hba,
struct ufs_vreg *vreg)
{
return ufshcd_config_vreg_load(hba->dev, vreg, UFS_VREG_LPM_LOAD_UA);
}
static inline int ufshcd_config_vreg_hpm(struct ufs_hba *hba,
struct ufs_vreg *vreg)
{
return ufshcd_config_vreg_load(hba->dev, vreg, vreg->max_uA);
}
static int ufshcd_config_vreg(struct device *dev,
struct ufs_vreg *vreg, bool on)
{
int ret = 0;
struct regulator *reg = vreg->reg;
const char *name = vreg->name;
int min_uV, uA_load;
BUG_ON(!vreg);
if (regulator_count_voltages(reg) > 0) {
min_uV = on ? vreg->min_uV : 0;
ret = regulator_set_voltage(reg, min_uV, vreg->max_uV);
if (ret) {
dev_err(dev, "%s: %s set voltage failed, err=%d\n",
__func__, name, ret);
goto out;
}
uA_load = on ? vreg->max_uA : 0;
ret = ufshcd_config_vreg_load(dev, vreg, uA_load);
if (ret)
goto out;
}
out:
return ret;
}
static int ufshcd_enable_vreg(struct device *dev, struct ufs_vreg *vreg)
{
int ret = 0;
if (!vreg || vreg->enabled)
goto out;
ret = ufshcd_config_vreg(dev, vreg, true);
if (!ret)
ret = regulator_enable(vreg->reg);
if (!ret)
vreg->enabled = true;
else
dev_err(dev, "%s: %s enable failed, err=%d\n",
__func__, vreg->name, ret);
out:
return ret;
}
static int ufshcd_disable_vreg(struct device *dev, struct ufs_vreg *vreg)
{
int ret = 0;
if (!vreg || !vreg->enabled)
goto out;
ret = regulator_disable(vreg->reg);
if (!ret) {
ufshcd_config_vreg(dev, vreg, false);
vreg->enabled = false;
} else {
dev_err(dev, "%s: %s disable failed, err=%d\n",
__func__, vreg->name, ret);
}
out:
return ret;
}
static int ufshcd_setup_vreg(struct ufs_hba *hba, bool on)
{
int ret = 0;
struct device *dev = hba->dev;
struct ufs_vreg_info *info = &hba->vreg_info;
if (!info)
goto out;
ret = ufshcd_toggle_vreg(dev, info->vcc, on);
if (ret)
goto out;
ret = ufshcd_toggle_vreg(dev, info->vccq, on);
if (ret)
goto out;
ret = ufshcd_toggle_vreg(dev, info->vccq2, on);
if (ret)
goto out;
out:
if (ret) {
ufshcd_toggle_vreg(dev, info->vccq2, false);
ufshcd_toggle_vreg(dev, info->vccq, false);
ufshcd_toggle_vreg(dev, info->vcc, false);
}
return ret;
}
static int ufshcd_setup_hba_vreg(struct ufs_hba *hba, bool on)
{
struct ufs_vreg_info *info = &hba->vreg_info;
if (info)
return ufshcd_toggle_vreg(hba->dev, info->vdd_hba, on);
return 0;
}
static int ufshcd_get_vreg(struct device *dev, struct ufs_vreg *vreg)
{
int ret = 0;
if (!vreg)
goto out;
vreg->reg = devm_regulator_get(dev, vreg->name);
if (IS_ERR(vreg->reg)) {
ret = PTR_ERR(vreg->reg);
dev_err(dev, "%s: %s get failed, err=%d\n",
__func__, vreg->name, ret);
}
out:
return ret;
}
static int ufshcd_init_vreg(struct ufs_hba *hba)
{
int ret = 0;
struct device *dev = hba->dev;
struct ufs_vreg_info *info = &hba->vreg_info;
if (!info)
goto out;
ret = ufshcd_get_vreg(dev, info->vcc);
if (ret)
goto out;
ret = ufshcd_get_vreg(dev, info->vccq);
if (ret)
goto out;
ret = ufshcd_get_vreg(dev, info->vccq2);
out:
return ret;
}
static int ufshcd_init_hba_vreg(struct ufs_hba *hba)
{
struct ufs_vreg_info *info = &hba->vreg_info;
if (info)
return ufshcd_get_vreg(hba->dev, info->vdd_hba);
return 0;
}
static int __ufshcd_setup_clocks(struct ufs_hba *hba, bool on,
bool skip_ref_clk)
{
int ret = 0;
struct ufs_clk_info *clki;
struct list_head *head = &hba->clk_list_head;
unsigned long flags;
if (!head || list_empty(head))
goto out;
list_for_each_entry(clki, head, list) {
if (!IS_ERR_OR_NULL(clki->clk)) {
if (skip_ref_clk && !strcmp(clki->name, "ref_clk"))
continue;
if (on && !clki->enabled) {
ret = clk_prepare_enable(clki->clk);
if (ret) {
dev_err(hba->dev, "%s: %s prepare enable failed, %d\n",
__func__, clki->name, ret);
goto out;
}
} else if (!on && clki->enabled) {
clk_disable_unprepare(clki->clk);
}
clki->enabled = on;
dev_dbg(hba->dev, "%s: clk: %s %sabled\n", __func__,
clki->name, on ? "en" : "dis");
}
}
if (hba->vops && hba->vops->setup_clocks)
ret = hba->vops->setup_clocks(hba, on);
out:
if (ret) {
list_for_each_entry(clki, head, list) {
if (!IS_ERR_OR_NULL(clki->clk) && clki->enabled)
clk_disable_unprepare(clki->clk);
}
} else if (on) {
spin_lock_irqsave(hba->host->host_lock, flags);
hba->clk_gating.state = CLKS_ON;
spin_unlock_irqrestore(hba->host->host_lock, flags);
}
return ret;
}
static int ufshcd_setup_clocks(struct ufs_hba *hba, bool on)
{
return __ufshcd_setup_clocks(hba, on, false);
}
static int ufshcd_init_clocks(struct ufs_hba *hba)
{
int ret = 0;
struct ufs_clk_info *clki;
struct device *dev = hba->dev;
struct list_head *head = &hba->clk_list_head;
if (!head || list_empty(head))
goto out;
list_for_each_entry(clki, head, list) {
if (!clki->name)
continue;
clki->clk = devm_clk_get(dev, clki->name);
if (IS_ERR(clki->clk)) {
ret = PTR_ERR(clki->clk);
dev_err(dev, "%s: %s clk get failed, %d\n",
__func__, clki->name, ret);
goto out;
}
if (clki->max_freq) {
ret = clk_set_rate(clki->clk, clki->max_freq);
if (ret) {
dev_err(hba->dev, "%s: %s clk set rate(%dHz) failed, %d\n",
__func__, clki->name,
clki->max_freq, ret);
goto out;
}
clki->curr_freq = clki->max_freq;
}
dev_dbg(dev, "%s: clk: %s, rate: %lu\n", __func__,
clki->name, clk_get_rate(clki->clk));
}
out:
return ret;
}
static int ufshcd_variant_hba_init(struct ufs_hba *hba)
{
int err = 0;
if (!hba->vops)
goto out;
if (hba->vops->init) {
err = hba->vops->init(hba);
if (err)
goto out;
}
if (hba->vops->setup_regulators) {
err = hba->vops->setup_regulators(hba, true);
if (err)
goto out_exit;
}
goto out;
out_exit:
if (hba->vops->exit)
hba->vops->exit(hba);
out:
if (err)
dev_err(hba->dev, "%s: variant %s init failed err %d\n",
__func__, hba->vops ? hba->vops->name : "", err);
return err;
}
static void ufshcd_variant_hba_exit(struct ufs_hba *hba)
{
if (!hba->vops)
return;
if (hba->vops->setup_clocks)
hba->vops->setup_clocks(hba, false);
if (hba->vops->setup_regulators)
hba->vops->setup_regulators(hba, false);
if (hba->vops->exit)
hba->vops->exit(hba);
}
static int ufshcd_hba_init(struct ufs_hba *hba)
{
int err;
err = ufshcd_init_hba_vreg(hba);
if (err)
goto out;
err = ufshcd_setup_hba_vreg(hba, true);
if (err)
goto out;
err = ufshcd_init_clocks(hba);
if (err)
goto out_disable_hba_vreg;
err = ufshcd_setup_clocks(hba, true);
if (err)
goto out_disable_hba_vreg;
err = ufshcd_init_vreg(hba);
if (err)
goto out_disable_clks;
err = ufshcd_setup_vreg(hba, true);
if (err)
goto out_disable_clks;
err = ufshcd_variant_hba_init(hba);
if (err)
goto out_disable_vreg;
hba->is_powered = true;
goto out;
out_disable_vreg:
ufshcd_setup_vreg(hba, false);
out_disable_clks:
ufshcd_setup_clocks(hba, false);
out_disable_hba_vreg:
ufshcd_setup_hba_vreg(hba, false);
out:
return err;
}
static void ufshcd_hba_exit(struct ufs_hba *hba)
{
if (hba->is_powered) {
ufshcd_variant_hba_exit(hba);
ufshcd_setup_vreg(hba, false);
ufshcd_setup_clocks(hba, false);
ufshcd_setup_hba_vreg(hba, false);
hba->is_powered = false;
}
}
static int
ufshcd_send_request_sense(struct ufs_hba *hba, struct scsi_device *sdp)
{
unsigned char cmd[6] = {REQUEST_SENSE,
0,
0,
0,
SCSI_SENSE_BUFFERSIZE,
0};
char *buffer;
int ret;
buffer = kzalloc(SCSI_SENSE_BUFFERSIZE, GFP_KERNEL);
if (!buffer) {
ret = -ENOMEM;
goto out;
}
ret = scsi_execute_req_flags(sdp, cmd, DMA_FROM_DEVICE, buffer,
SCSI_SENSE_BUFFERSIZE, NULL,
msecs_to_jiffies(1000), 3, NULL, REQ_PM);
if (ret)
pr_err("%s: failed with err %d\n", __func__, ret);
kfree(buffer);
out:
return ret;
}
static int ufshcd_set_dev_pwr_mode(struct ufs_hba *hba,
enum ufs_dev_pwr_mode pwr_mode)
{
unsigned char cmd[6] = { START_STOP };
struct scsi_sense_hdr sshdr;
struct scsi_device *sdp;
unsigned long flags;
int ret;
spin_lock_irqsave(hba->host->host_lock, flags);
sdp = hba->sdev_ufs_device;
if (sdp) {
ret = scsi_device_get(sdp);
if (!ret && !scsi_device_online(sdp)) {
ret = -ENODEV;
scsi_device_put(sdp);
}
} else {
ret = -ENODEV;
}
spin_unlock_irqrestore(hba->host->host_lock, flags);
if (ret)
return ret;
hba->host->eh_noresume = 1;
if (hba->wlun_dev_clr_ua) {
ret = ufshcd_send_request_sense(hba, sdp);
if (ret)
goto out;
hba->wlun_dev_clr_ua = false;
}
cmd[4] = pwr_mode << 4;
ret = scsi_execute_req_flags(sdp, cmd, DMA_NONE, NULL, 0, &sshdr,
START_STOP_TIMEOUT, 0, NULL, REQ_PM);
if (ret) {
sdev_printk(KERN_WARNING, sdp,
"START_STOP failed for power mode: %d, result %x\n",
pwr_mode, ret);
if (driver_byte(ret) & DRIVER_SENSE)
scsi_print_sense_hdr(sdp, NULL, &sshdr);
}
if (!ret)
hba->curr_dev_pwr_mode = pwr_mode;
out:
scsi_device_put(sdp);
hba->host->eh_noresume = 0;
return ret;
}
static int ufshcd_link_state_transition(struct ufs_hba *hba,
enum uic_link_state req_link_state,
int check_for_bkops)
{
int ret = 0;
if (req_link_state == hba->uic_link_state)
return 0;
if (req_link_state == UIC_LINK_HIBERN8_STATE) {
ret = ufshcd_uic_hibern8_enter(hba);
if (!ret)
ufshcd_set_link_hibern8(hba);
else
goto out;
}
else if ((req_link_state == UIC_LINK_OFF_STATE) &&
(!check_for_bkops || (check_for_bkops &&
!hba->auto_bkops_enabled))) {
ufshcd_hba_stop(hba);
ufshcd_set_link_off(hba);
}
out:
return ret;
}
static void ufshcd_vreg_set_lpm(struct ufs_hba *hba)
{
if (ufshcd_is_ufs_dev_poweroff(hba) && ufshcd_is_link_off(hba) &&
!hba->dev_info.is_lu_power_on_wp) {
ufshcd_setup_vreg(hba, false);
} else if (!ufshcd_is_ufs_dev_active(hba)) {
ufshcd_toggle_vreg(hba->dev, hba->vreg_info.vcc, false);
if (!ufshcd_is_link_active(hba)) {
ufshcd_config_vreg_lpm(hba, hba->vreg_info.vccq);
ufshcd_config_vreg_lpm(hba, hba->vreg_info.vccq2);
}
}
}
static int ufshcd_vreg_set_hpm(struct ufs_hba *hba)
{
int ret = 0;
if (ufshcd_is_ufs_dev_poweroff(hba) && ufshcd_is_link_off(hba) &&
!hba->dev_info.is_lu_power_on_wp) {
ret = ufshcd_setup_vreg(hba, true);
} else if (!ufshcd_is_ufs_dev_active(hba)) {
ret = ufshcd_toggle_vreg(hba->dev, hba->vreg_info.vcc, true);
if (!ret && !ufshcd_is_link_active(hba)) {
ret = ufshcd_config_vreg_hpm(hba, hba->vreg_info.vccq);
if (ret)
goto vcc_disable;
ret = ufshcd_config_vreg_hpm(hba, hba->vreg_info.vccq2);
if (ret)
goto vccq_lpm;
}
}
goto out;
vccq_lpm:
ufshcd_config_vreg_lpm(hba, hba->vreg_info.vccq);
vcc_disable:
ufshcd_toggle_vreg(hba->dev, hba->vreg_info.vcc, false);
out:
return ret;
}
static void ufshcd_hba_vreg_set_lpm(struct ufs_hba *hba)
{
if (ufshcd_is_link_off(hba))
ufshcd_setup_hba_vreg(hba, false);
}
static void ufshcd_hba_vreg_set_hpm(struct ufs_hba *hba)
{
if (ufshcd_is_link_off(hba))
ufshcd_setup_hba_vreg(hba, true);
}
static int ufshcd_suspend(struct ufs_hba *hba, enum ufs_pm_op pm_op)
{
int ret = 0;
enum ufs_pm_level pm_lvl;
enum ufs_dev_pwr_mode req_dev_pwr_mode;
enum uic_link_state req_link_state;
hba->pm_op_in_progress = 1;
if (!ufshcd_is_shutdown_pm(pm_op)) {
pm_lvl = ufshcd_is_runtime_pm(pm_op) ?
hba->rpm_lvl : hba->spm_lvl;
req_dev_pwr_mode = ufs_get_pm_lvl_to_dev_pwr_mode(pm_lvl);
req_link_state = ufs_get_pm_lvl_to_link_pwr_state(pm_lvl);
} else {
req_dev_pwr_mode = UFS_POWERDOWN_PWR_MODE;
req_link_state = UIC_LINK_OFF_STATE;
}
ufshcd_hold(hba, false);
hba->clk_gating.is_suspended = true;
if (req_dev_pwr_mode == UFS_ACTIVE_PWR_MODE &&
req_link_state == UIC_LINK_ACTIVE_STATE) {
goto disable_clks;
}
if ((req_dev_pwr_mode == hba->curr_dev_pwr_mode) &&
(req_link_state == hba->uic_link_state))
goto out;
if (!ufshcd_is_ufs_dev_active(hba) || !ufshcd_is_link_active(hba)) {
ret = -EINVAL;
goto out;
}
if (ufshcd_is_runtime_pm(pm_op)) {
if (ufshcd_can_autobkops_during_suspend(hba)) {
ret = ufshcd_urgent_bkops(hba);
if (ret)
goto enable_gating;
} else {
ufshcd_disable_auto_bkops(hba);
}
}
if ((req_dev_pwr_mode != hba->curr_dev_pwr_mode) &&
((ufshcd_is_runtime_pm(pm_op) && !hba->auto_bkops_enabled) ||
!ufshcd_is_runtime_pm(pm_op))) {
ufshcd_disable_auto_bkops(hba);
ret = ufshcd_set_dev_pwr_mode(hba, req_dev_pwr_mode);
if (ret)
goto enable_gating;
}
ret = ufshcd_link_state_transition(hba, req_link_state, 1);
if (ret)
goto set_dev_active;
ufshcd_vreg_set_lpm(hba);
disable_clks:
if (ufshcd_is_clkscaling_enabled(hba)) {
devfreq_suspend_device(hba->devfreq);
hba->clk_scaling.window_start_t = 0;
}
if (hba->vops && hba->vops->suspend) {
ret = hba->vops->suspend(hba, pm_op);
if (ret)
goto set_link_active;
}
if (hba->vops && hba->vops->setup_clocks) {
ret = hba->vops->setup_clocks(hba, false);
if (ret)
goto vops_resume;
}
if (!ufshcd_is_link_active(hba))
ufshcd_setup_clocks(hba, false);
else
__ufshcd_setup_clocks(hba, false, true);
hba->clk_gating.state = CLKS_OFF;
ufshcd_disable_irq(hba);
ufshcd_hba_vreg_set_lpm(hba);
goto out;
vops_resume:
if (hba->vops && hba->vops->resume)
hba->vops->resume(hba, pm_op);
set_link_active:
ufshcd_vreg_set_hpm(hba);
if (ufshcd_is_link_hibern8(hba) && !ufshcd_uic_hibern8_exit(hba))
ufshcd_set_link_active(hba);
else if (ufshcd_is_link_off(hba))
ufshcd_host_reset_and_restore(hba);
set_dev_active:
if (!ufshcd_set_dev_pwr_mode(hba, UFS_ACTIVE_PWR_MODE))
ufshcd_disable_auto_bkops(hba);
enable_gating:
hba->clk_gating.is_suspended = false;
ufshcd_release(hba);
out:
hba->pm_op_in_progress = 0;
return ret;
}
static int ufshcd_resume(struct ufs_hba *hba, enum ufs_pm_op pm_op)
{
int ret;
enum uic_link_state old_link_state;
hba->pm_op_in_progress = 1;
old_link_state = hba->uic_link_state;
ufshcd_hba_vreg_set_hpm(hba);
ret = ufshcd_setup_clocks(hba, true);
if (ret)
goto out;
ret = ufshcd_enable_irq(hba);
if (ret)
goto disable_irq_and_vops_clks;
ret = ufshcd_vreg_set_hpm(hba);
if (ret)
goto disable_irq_and_vops_clks;
if (hba->vops && hba->vops->resume) {
ret = hba->vops->resume(hba, pm_op);
if (ret)
goto disable_vreg;
}
if (ufshcd_is_link_hibern8(hba)) {
ret = ufshcd_uic_hibern8_exit(hba);
if (!ret)
ufshcd_set_link_active(hba);
else
goto vendor_suspend;
} else if (ufshcd_is_link_off(hba)) {
ret = ufshcd_host_reset_and_restore(hba);
if (ret || !ufshcd_is_link_active(hba))
goto vendor_suspend;
}
if (!ufshcd_is_ufs_dev_active(hba)) {
ret = ufshcd_set_dev_pwr_mode(hba, UFS_ACTIVE_PWR_MODE);
if (ret)
goto set_old_link_state;
}
ufshcd_urgent_bkops(hba);
hba->clk_gating.is_suspended = false;
if (ufshcd_is_clkscaling_enabled(hba))
devfreq_resume_device(hba->devfreq);
ufshcd_release(hba);
goto out;
set_old_link_state:
ufshcd_link_state_transition(hba, old_link_state, 0);
vendor_suspend:
if (hba->vops && hba->vops->suspend)
hba->vops->suspend(hba, pm_op);
disable_vreg:
ufshcd_vreg_set_lpm(hba);
disable_irq_and_vops_clks:
ufshcd_disable_irq(hba);
ufshcd_setup_clocks(hba, false);
out:
hba->pm_op_in_progress = 0;
return ret;
}
int ufshcd_system_suspend(struct ufs_hba *hba)
{
int ret = 0;
if (!hba || !hba->is_powered)
return 0;
if (pm_runtime_suspended(hba->dev)) {
if (hba->rpm_lvl == hba->spm_lvl)
if ((ufs_get_pm_lvl_to_dev_pwr_mode(hba->spm_lvl) ==
hba->curr_dev_pwr_mode) && !hba->auto_bkops_enabled)
goto out;
ret = ufshcd_runtime_resume(hba);
if (ret)
goto out;
}
ret = ufshcd_suspend(hba, UFS_SYSTEM_PM);
out:
if (!ret)
hba->is_sys_suspended = true;
return ret;
}
int ufshcd_system_resume(struct ufs_hba *hba)
{
if (!hba || !hba->is_powered || pm_runtime_suspended(hba->dev))
return 0;
return ufshcd_resume(hba, UFS_SYSTEM_PM);
}
int ufshcd_runtime_suspend(struct ufs_hba *hba)
{
if (!hba || !hba->is_powered)
return 0;
return ufshcd_suspend(hba, UFS_RUNTIME_PM);
}
int ufshcd_runtime_resume(struct ufs_hba *hba)
{
if (!hba || !hba->is_powered)
return 0;
else
return ufshcd_resume(hba, UFS_RUNTIME_PM);
}
int ufshcd_runtime_idle(struct ufs_hba *hba)
{
return 0;
}
int ufshcd_shutdown(struct ufs_hba *hba)
{
int ret = 0;
if (ufshcd_is_ufs_dev_poweroff(hba) && ufshcd_is_link_off(hba))
goto out;
if (pm_runtime_suspended(hba->dev)) {
ret = ufshcd_runtime_resume(hba);
if (ret)
goto out;
}
ret = ufshcd_suspend(hba, UFS_SHUTDOWN_PM);
out:
if (ret)
dev_err(hba->dev, "%s failed, err %d\n", __func__, ret);
return 0;
}
void ufshcd_remove(struct ufs_hba *hba)
{
scsi_remove_host(hba->host);
ufshcd_disable_intr(hba, hba->intr_mask);
ufshcd_hba_stop(hba);
scsi_host_put(hba->host);
ufshcd_exit_clk_gating(hba);
if (ufshcd_is_clkscaling_enabled(hba))
devfreq_remove_device(hba->devfreq);
ufshcd_hba_exit(hba);
}
static int ufshcd_set_dma_mask(struct ufs_hba *hba)
{
if (hba->capabilities & MASK_64_ADDRESSING_SUPPORT) {
if (!dma_set_mask_and_coherent(hba->dev, DMA_BIT_MASK(64)))
return 0;
}
return dma_set_mask_and_coherent(hba->dev, DMA_BIT_MASK(32));
}
int ufshcd_alloc_host(struct device *dev, struct ufs_hba **hba_handle)
{
struct Scsi_Host *host;
struct ufs_hba *hba;
int err = 0;
if (!dev) {
dev_err(dev,
"Invalid memory reference for dev is NULL\n");
err = -ENODEV;
goto out_error;
}
host = scsi_host_alloc(&ufshcd_driver_template,
sizeof(struct ufs_hba));
if (!host) {
dev_err(dev, "scsi_host_alloc failed\n");
err = -ENOMEM;
goto out_error;
}
hba = shost_priv(host);
hba->host = host;
hba->dev = dev;
*hba_handle = hba;
out_error:
return err;
}
static int ufshcd_scale_clks(struct ufs_hba *hba, bool scale_up)
{
int ret = 0;
struct ufs_clk_info *clki;
struct list_head *head = &hba->clk_list_head;
if (!head || list_empty(head))
goto out;
list_for_each_entry(clki, head, list) {
if (!IS_ERR_OR_NULL(clki->clk)) {
if (scale_up && clki->max_freq) {
if (clki->curr_freq == clki->max_freq)
continue;
ret = clk_set_rate(clki->clk, clki->max_freq);
if (ret) {
dev_err(hba->dev, "%s: %s clk set rate(%dHz) failed, %d\n",
__func__, clki->name,
clki->max_freq, ret);
break;
}
clki->curr_freq = clki->max_freq;
} else if (!scale_up && clki->min_freq) {
if (clki->curr_freq == clki->min_freq)
continue;
ret = clk_set_rate(clki->clk, clki->min_freq);
if (ret) {
dev_err(hba->dev, "%s: %s clk set rate(%dHz) failed, %d\n",
__func__, clki->name,
clki->min_freq, ret);
break;
}
clki->curr_freq = clki->min_freq;
}
}
dev_dbg(hba->dev, "%s: clk: %s, rate: %lu\n", __func__,
clki->name, clk_get_rate(clki->clk));
}
if (hba->vops->clk_scale_notify)
hba->vops->clk_scale_notify(hba);
out:
return ret;
}
static int ufshcd_devfreq_target(struct device *dev,
unsigned long *freq, u32 flags)
{
int err = 0;
struct ufs_hba *hba = dev_get_drvdata(dev);
if (!ufshcd_is_clkscaling_enabled(hba))
return -EINVAL;
if (*freq == UINT_MAX)
err = ufshcd_scale_clks(hba, true);
else if (*freq == 0)
err = ufshcd_scale_clks(hba, false);
return err;
}
static int ufshcd_devfreq_get_dev_status(struct device *dev,
struct devfreq_dev_status *stat)
{
struct ufs_hba *hba = dev_get_drvdata(dev);
struct ufs_clk_scaling *scaling = &hba->clk_scaling;
unsigned long flags;
if (!ufshcd_is_clkscaling_enabled(hba))
return -EINVAL;
memset(stat, 0, sizeof(*stat));
spin_lock_irqsave(hba->host->host_lock, flags);
if (!scaling->window_start_t)
goto start_window;
if (scaling->is_busy_started)
scaling->tot_busy_t += ktime_to_us(ktime_sub(ktime_get(),
scaling->busy_start_t));
stat->total_time = jiffies_to_usecs((long)jiffies -
(long)scaling->window_start_t);
stat->busy_time = scaling->tot_busy_t;
start_window:
scaling->window_start_t = jiffies;
scaling->tot_busy_t = 0;
if (hba->outstanding_reqs) {
scaling->busy_start_t = ktime_get();
scaling->is_busy_started = true;
} else {
scaling->busy_start_t = ktime_set(0, 0);
scaling->is_busy_started = false;
}
spin_unlock_irqrestore(hba->host->host_lock, flags);
return 0;
}
int ufshcd_init(struct ufs_hba *hba, void __iomem *mmio_base, unsigned int irq)
{
int err;
struct Scsi_Host *host = hba->host;
struct device *dev = hba->dev;
if (!mmio_base) {
dev_err(hba->dev,
"Invalid memory reference for mmio_base is NULL\n");
err = -ENODEV;
goto out_error;
}
hba->mmio_base = mmio_base;
hba->irq = irq;
err = ufshcd_hba_init(hba);
if (err)
goto out_error;
ufshcd_hba_capabilities(hba);
hba->ufs_version = ufshcd_get_ufs_version(hba);
hba->intr_mask = ufshcd_get_intr_mask(hba);
err = ufshcd_set_dma_mask(hba);
if (err) {
dev_err(hba->dev, "set dma mask failed\n");
goto out_disable;
}
err = ufshcd_memory_alloc(hba);
if (err) {
dev_err(hba->dev, "Memory allocation failed\n");
goto out_disable;
}
ufshcd_host_memory_configure(hba);
host->can_queue = hba->nutrs;
host->cmd_per_lun = hba->nutrs;
host->max_id = UFSHCD_MAX_ID;
host->max_lun = UFS_MAX_LUNS;
host->max_channel = UFSHCD_MAX_CHANNEL;
host->unique_id = host->host_no;
host->max_cmd_len = MAX_CDB_SIZE;
hba->max_pwr_info.is_valid = false;
init_waitqueue_head(&hba->tm_wq);
init_waitqueue_head(&hba->tm_tag_wq);
INIT_WORK(&hba->eh_work, ufshcd_err_handler);
INIT_WORK(&hba->eeh_work, ufshcd_exception_event_handler);
mutex_init(&hba->uic_cmd_mutex);
mutex_init(&hba->dev_cmd.lock);
init_waitqueue_head(&hba->dev_cmd.tag_wq);
ufshcd_init_clk_gating(hba);
err = devm_request_irq(dev, irq, ufshcd_intr, IRQF_SHARED, UFSHCD, hba);
if (err) {
dev_err(hba->dev, "request irq failed\n");
goto exit_gating;
} else {
hba->is_irq_enabled = true;
}
err = scsi_init_shared_tag_map(host, host->can_queue);
if (err) {
dev_err(hba->dev, "init shared queue failed\n");
goto exit_gating;
}
err = scsi_add_host(host, hba->dev);
if (err) {
dev_err(hba->dev, "scsi_add_host failed\n");
goto exit_gating;
}
err = ufshcd_hba_enable(hba);
if (err) {
dev_err(hba->dev, "Host controller enable failed\n");
goto out_remove_scsi_host;
}
if (ufshcd_is_clkscaling_enabled(hba)) {
hba->devfreq = devfreq_add_device(dev, &ufs_devfreq_profile,
"simple_ondemand", NULL);
if (IS_ERR(hba->devfreq)) {
dev_err(hba->dev, "Unable to register with devfreq %ld\n",
PTR_ERR(hba->devfreq));
goto out_remove_scsi_host;
}
devfreq_suspend_device(hba->devfreq);
hba->clk_scaling.window_start_t = 0;
}
pm_runtime_get_sync(dev);
ufshcd_set_ufs_dev_poweroff(hba);
async_schedule(ufshcd_async_scan, hba);
return 0;
out_remove_scsi_host:
scsi_remove_host(hba->host);
exit_gating:
ufshcd_exit_clk_gating(hba);
out_disable:
hba->is_irq_enabled = false;
scsi_host_put(host);
ufshcd_hba_exit(hba);
out_error:
return err;
}
