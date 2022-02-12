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
return ufshcd_readl(hba, REG_UFS_VERSION);
}
static inline int ufshcd_is_device_present(u32 reg_hcs)
{
return (DEVICE_PRESENT & reg_hcs) ? 1 : 0;
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
static inline
void ufshcd_send_command(struct ufs_hba *hba, unsigned int task_tag)
{
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
void ufshcd_copy_query_response(struct ufs_hba *hba, struct ufshcd_lrb *lrbp)
{
struct ufs_query_res *query_res = &hba->dev_cmd.query.response;
query_res->response = ufshcd_get_rsp_upiu_result(lrbp->ucd_rsp_ptr) >>
UPIU_RSP_CODE_OFFSET;
memcpy(&query_res->upiu_res, &lrbp->ucd_rsp_ptr->qr, QUERY_OSF_SIZE);
if (lrbp->ucd_rsp_ptr->qr.opcode == UPIU_QUERY_OPCODE_READ_DESC) {
u8 *descp = (u8 *)&lrbp->ucd_rsp_ptr +
GENERAL_UPIU_REQUEST_SIZE;
u16 len;
len = be32_to_cpu(lrbp->ucd_rsp_ptr->header.dword_2) &
MASK_QUERY_DATA_SEG_LEN;
memcpy(hba->dev_cmd.query.descriptor, descp,
min_t(u16, len, QUERY_DESC_MAX_SIZE));
}
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
int ret;
unsigned long flags;
if (!ufshcd_ready_for_uic_cmd(hba)) {
dev_err(hba->dev,
"Controller not ready to accept UIC commands\n");
return -EIO;
}
init_completion(&uic_cmd->done);
spin_lock_irqsave(hba->host->host_lock, flags);
ufshcd_dispatch_uic_cmd(hba, uic_cmd);
spin_unlock_irqrestore(hba->host->host_lock, flags);
ret = ufshcd_wait_for_uic_cmd(hba, uic_cmd);
return ret;
}
static int
ufshcd_send_uic_cmd(struct ufs_hba *hba, struct uic_command *uic_cmd)
{
int ret;
mutex_lock(&hba->uic_cmd_mutex);
ret = __ufshcd_send_uic_cmd(hba, uic_cmd);
mutex_unlock(&hba->uic_cmd_mutex);
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
if ((len > 0) && (query->request.upiu_req.opcode ==
UPIU_QUERY_OPCODE_WRITE_DESC)) {
memcpy(descp, query->descriptor,
min_t(u16, len, QUERY_DESC_MAX_SIZE));
}
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
lrbp = &hba->lrb[tag];
WARN_ON(lrbp->cmd);
lrbp->cmd = cmd;
lrbp->sense_bufflen = SCSI_SENSE_BUFFERSIZE;
lrbp->sense_buffer = cmd->sense_buffer;
lrbp->task_tag = tag;
lrbp->lun = cmd->device->lun;
lrbp->intr_cmd = false;
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
ufshcd_copy_query_response(hba, lrbp);
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
static int ufshcd_query_flag(struct ufs_hba *hba, enum query_opcode opcode,
enum flag_idn idn, bool *flag_res)
{
struct ufs_query_req *request;
struct ufs_query_res *response;
int err;
BUG_ON(!hba);
mutex_lock(&hba->dev_cmd.lock);
request = &hba->dev_cmd.query.request;
response = &hba->dev_cmd.query.response;
memset(request, 0, sizeof(struct ufs_query_req));
memset(response, 0, sizeof(struct ufs_query_res));
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
request->upiu_req.opcode = opcode;
request->upiu_req.idn = idn;
err = ufshcd_exec_dev_cmd(hba, DEV_CMD_TYPE_QUERY,
QUERY_REQ_TIMEOUT);
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
return err;
}
static int ufshcd_query_attr(struct ufs_hba *hba, enum query_opcode opcode,
enum attr_idn idn, u8 index, u8 selector, u32 *attr_val)
{
struct ufs_query_req *request;
struct ufs_query_res *response;
int err;
BUG_ON(!hba);
if (!attr_val) {
dev_err(hba->dev, "%s: attribute value required for opcode 0x%x\n",
__func__, opcode);
err = -EINVAL;
goto out;
}
mutex_lock(&hba->dev_cmd.lock);
request = &hba->dev_cmd.query.request;
response = &hba->dev_cmd.query.response;
memset(request, 0, sizeof(struct ufs_query_req));
memset(response, 0, sizeof(struct ufs_query_res));
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
request->upiu_req.opcode = opcode;
request->upiu_req.idn = idn;
request->upiu_req.index = index;
request->upiu_req.selector = selector;
err = ufshcd_exec_dev_cmd(hba, DEV_CMD_TYPE_QUERY,
QUERY_REQ_TIMEOUT);
if (err) {
dev_err(hba->dev, "%s: opcode 0x%.2x for idn %d failed, err = %d\n",
__func__, opcode, idn, err);
goto out_unlock;
}
*attr_val = be32_to_cpu(response->upiu_res.value);
out_unlock:
mutex_unlock(&hba->dev_cmd.lock);
out:
return err;
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
out:
return ret;
}
static int ufshcd_uic_change_pwr_mode(struct ufs_hba *hba, u8 mode)
{
struct uic_command uic_cmd = {0};
struct completion pwr_done;
unsigned long flags;
u8 status;
int ret;
uic_cmd.command = UIC_CMD_DME_SET;
uic_cmd.argument1 = UIC_ARG_MIB(PA_PWRMODE);
uic_cmd.argument3 = mode;
init_completion(&pwr_done);
mutex_lock(&hba->uic_cmd_mutex);
spin_lock_irqsave(hba->host->host_lock, flags);
hba->pwr_done = &pwr_done;
spin_unlock_irqrestore(hba->host->host_lock, flags);
ret = __ufshcd_send_uic_cmd(hba, &uic_cmd);
if (ret) {
dev_err(hba->dev,
"pwr mode change with mode 0x%x uic error %d\n",
mode, ret);
goto out;
}
if (!wait_for_completion_timeout(hba->pwr_done,
msecs_to_jiffies(UIC_CMD_TIMEOUT))) {
dev_err(hba->dev,
"pwr mode change with mode 0x%x completion timeout\n",
mode);
ret = -ETIMEDOUT;
goto out;
}
status = ufshcd_get_upmcrs(hba);
if (status != PWR_LOCAL) {
dev_err(hba->dev,
"pwr mode change failed, host umpcrs:0x%x\n",
status);
ret = (status != PWR_OK) ? status : -1;
}
out:
spin_lock_irqsave(hba->host->host_lock, flags);
hba->pwr_done = NULL;
spin_unlock_irqrestore(hba->host->host_lock, flags);
mutex_unlock(&hba->uic_cmd_mutex);
return ret;
}
static int ufshcd_config_max_pwr_mode(struct ufs_hba *hba)
{
enum {RX = 0, TX = 1};
u32 lanes[] = {1, 1};
u32 gear[] = {1, 1};
u8 pwr[] = {FASTAUTO_MODE, FASTAUTO_MODE};
int ret;
ufshcd_dme_get(hba, UIC_ARG_MIB(PA_CONNECTEDRXDATALANES), &lanes[RX]);
ufshcd_dme_get(hba, UIC_ARG_MIB(PA_CONNECTEDTXDATALANES), &lanes[TX]);
ufshcd_dme_get(hba, UIC_ARG_MIB(PA_MAXRXHSGEAR), &gear[RX]);
if (!gear[RX]) {
ufshcd_dme_get(hba, UIC_ARG_MIB(PA_MAXRXPWMGEAR), &gear[RX]);
pwr[RX] = SLOWAUTO_MODE;
}
ufshcd_dme_peer_get(hba, UIC_ARG_MIB(PA_MAXRXHSGEAR), &gear[TX]);
if (!gear[TX]) {
ufshcd_dme_peer_get(hba, UIC_ARG_MIB(PA_MAXRXPWMGEAR),
&gear[TX]);
pwr[TX] = SLOWAUTO_MODE;
}
ufshcd_dme_set(hba, UIC_ARG_MIB(PA_RXGEAR), gear[RX]);
ufshcd_dme_set(hba, UIC_ARG_MIB(PA_ACTIVERXDATALANES), lanes[RX]);
if (pwr[RX] == FASTAUTO_MODE)
ufshcd_dme_set(hba, UIC_ARG_MIB(PA_RXTERMINATION), TRUE);
ufshcd_dme_set(hba, UIC_ARG_MIB(PA_TXGEAR), gear[TX]);
ufshcd_dme_set(hba, UIC_ARG_MIB(PA_ACTIVETXDATALANES), lanes[TX]);
if (pwr[TX] == FASTAUTO_MODE)
ufshcd_dme_set(hba, UIC_ARG_MIB(PA_TXTERMINATION), TRUE);
if (pwr[RX] == FASTAUTO_MODE || pwr[TX] == FASTAUTO_MODE)
ufshcd_dme_set(hba, UIC_ARG_MIB(PA_HSSERIES), PA_HS_MODE_B);
ret = ufshcd_uic_change_pwr_mode(hba, pwr[RX] << 4 | pwr[TX]);
if (ret)
dev_err(hba->dev,
"pwr_mode: power mode change failed %d\n", ret);
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
reg = ufshcd_readl(hba, REG_CONTROLLER_STATUS);
if (!ufshcd_is_device_present(reg)) {
dev_err(hba->dev, "cc: Device not present\n");
err = -ENXIO;
goto out;
}
ufshcd_enable_intr(hba, UFSHCD_ENABLE_INTRS);
ufshcd_config_intr_aggr(hba, hba->nutrs - 1, INT_AGGR_DEF_TO);
ufshcd_writel(hba, lower_32_bits(hba->utrdl_dma_addr),
REG_UTP_TRANSFER_REQ_LIST_BASE_L);
ufshcd_writel(hba, upper_32_bits(hba->utrdl_dma_addr),
REG_UTP_TRANSFER_REQ_LIST_BASE_H);
ufshcd_writel(hba, lower_32_bits(hba->utmrdl_dma_addr),
REG_UTP_TASK_REQ_LIST_BASE_L);
ufshcd_writel(hba, upper_32_bits(hba->utmrdl_dma_addr),
REG_UTP_TASK_REQ_LIST_BASE_H);
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
return 0;
}
static int ufshcd_link_startup(struct ufs_hba *hba)
{
int ret;
ufshcd_enable_intr(hba, UIC_COMMAND_COMPL);
ret = ufshcd_dme_link_startup(hba);
if (ret)
goto out;
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
mutex_lock(&hba->dev_cmd.lock);
for (retries = NOP_OUT_RETRIES; retries > 0; retries--) {
err = ufshcd_exec_dev_cmd(hba, DEV_CMD_TYPE_NOP,
NOP_OUT_TIMEOUT);
if (!err || err == -ETIMEDOUT)
break;
dev_dbg(hba->dev, "%s: error %d retrying\n", __func__, err);
}
mutex_unlock(&hba->dev_cmd.lock);
if (err)
dev_err(hba->dev, "%s: NOP OUT failed %d\n", __func__, err);
return err;
}
static int ufshcd_slave_alloc(struct scsi_device *sdev)
{
struct ufs_hba *hba;
hba = shost_priv(sdev->host);
sdev->tagged_supported = 1;
sdev->use_10_for_ms = 1;
scsi_set_tag_type(sdev, MSG_SIMPLE_TAG);
sdev->allow_restart = 1;
scsi_activate_tcq(sdev, hba->nutrs);
return 0;
}
static void ufshcd_slave_destroy(struct scsi_device *sdev)
{
struct ufs_hba *hba;
hba = shost_priv(sdev->host);
scsi_deactivate_tcq(sdev, hba->nutrs);
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
static void ufshcd_adjust_lun_qdepth(struct scsi_cmnd *cmd)
{
struct ufs_hba *hba;
int i;
int lun_qdepth = 0;
hba = shost_priv(cmd->device->host);
for (i = 0; i < hba->nutrs; i++) {
if (test_bit(i, &hba->outstanding_reqs)) {
if (cmd->device->lun == hba->lrb[i].lun)
lun_qdepth++;
}
}
scsi_adjust_queue_depth(cmd->device, MSG_SIMPLE_TAG, lun_qdepth - 1);
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
ufshcd_adjust_lun_qdepth(lrbp->cmd);
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
if ((intr_status & UIC_POWER_MODE) && hba->pwr_done)
complete(hba->pwr_done);
}
static void ufshcd_transfer_req_compl(struct ufs_hba *hba)
{
struct ufshcd_lrb *lrbp;
struct scsi_cmnd *cmd;
unsigned long completed_reqs;
u32 tr_doorbell;
int result;
int index;
bool int_aggr_reset = false;
tr_doorbell = ufshcd_readl(hba, REG_UTP_TRANSFER_REQ_DOOR_BELL);
completed_reqs = tr_doorbell ^ hba->outstanding_reqs;
for (index = 0; index < hba->nutrs; index++) {
if (test_bit(index, &completed_reqs)) {
lrbp = &hba->lrb[index];
cmd = lrbp->cmd;
int_aggr_reset |= !lrbp->intr_cmd;
if (cmd) {
result = ufshcd_transfer_rsp_status(hba, lrbp);
scsi_dma_unmap(cmd);
cmd->result = result;
lrbp->cmd = NULL;
clear_bit_unlock(index, &hba->lrb_in_use);
cmd->scsi_done(cmd);
} else if (lrbp->command_type ==
UTP_CMD_TYPE_DEV_MANAGE) {
if (hba->dev_cmd.complete)
complete(hba->dev_cmd.complete);
}
}
}
hba->outstanding_reqs ^= completed_reqs;
wake_up(&hba->dev_cmd.tag_wq);
if (int_aggr_reset)
ufshcd_reset_intr_aggr(hba);
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
static int ufshcd_urgent_bkops(struct ufs_hba *hba)
{
int err;
u32 status = 0;
err = ufshcd_get_bkops_status(hba, &status);
if (err) {
dev_err(hba->dev, "%s: failed to get BKOPS status %d\n",
__func__, err);
goto out;
}
status = status & 0xF;
if (status >= BKOPS_STATUS_PERF_IMPACT)
err = ufshcd_enable_auto_bkops(hba);
out:
return err;
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
if (err)
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
host = cmd->device->host;
hba = shost_priv(host);
tag = cmd->request->tag;
if (!(test_bit(tag, &hba->outstanding_reqs)))
goto out;
lrbp = &hba->lrb[tag];
for (poll_cnt = 100; poll_cnt; poll_cnt--) {
err = ufshcd_issue_tm_cmd(hba, lrbp->lun, lrbp->task_tag,
UFS_QUERY_TASK, &resp);
if (!err && resp == UPIU_TASK_MANAGEMENT_FUNC_SUCCEEDED) {
break;
} else if (!err && resp == UPIU_TASK_MANAGEMENT_FUNC_COMPL) {
u32 reg;
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
return err;
}
static int ufshcd_host_reset_and_restore(struct ufs_hba *hba)
{
int err;
async_cookie_t cookie;
unsigned long flags;
spin_lock_irqsave(hba->host->host_lock, flags);
ufshcd_hba_stop(hba);
spin_unlock_irqrestore(hba->host->host_lock, flags);
err = ufshcd_hba_enable(hba);
if (err)
goto out;
cookie = async_schedule(ufshcd_async_scan, hba);
async_synchronize_cookie(++cookie);
if (hba->ufshcd_state != UFSHCD_STATE_OPERATIONAL)
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
err = ufshcd_host_reset_and_restore(hba);
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
return err;
}
static void ufshcd_async_scan(void *data, async_cookie_t cookie)
{
struct ufs_hba *hba = (struct ufs_hba *)data;
int ret;
ret = ufshcd_link_startup(hba);
if (ret)
goto out;
ufshcd_config_max_pwr_mode(hba);
ret = ufshcd_verify_dev_init(hba);
if (ret)
goto out;
ret = ufshcd_complete_dev_init(hba);
if (ret)
goto out;
ufshcd_force_reset_auto_bkops(hba);
hba->ufshcd_state = UFSHCD_STATE_OPERATIONAL;
if (!ufshcd_eh_in_progress(hba)) {
scsi_scan_host(hba->host);
pm_runtime_put_sync(hba->dev);
}
out:
return;
}
int ufshcd_suspend(struct ufs_hba *hba, pm_message_t state)
{
return -ENOSYS;
}
int ufshcd_resume(struct ufs_hba *hba)
{
return -ENOSYS;
}
int ufshcd_runtime_suspend(struct ufs_hba *hba)
{
if (!hba)
return 0;
return ufshcd_enable_auto_bkops(hba);
}
int ufshcd_runtime_resume(struct ufs_hba *hba)
{
if (!hba)
return 0;
return ufshcd_disable_auto_bkops(hba);
}
int ufshcd_runtime_idle(struct ufs_hba *hba)
{
return 0;
}
void ufshcd_remove(struct ufs_hba *hba)
{
scsi_remove_host(hba->host);
ufshcd_disable_intr(hba, hba->intr_mask);
ufshcd_hba_stop(hba);
scsi_host_put(hba->host);
}
int ufshcd_init(struct device *dev, struct ufs_hba **hba_handle,
void __iomem *mmio_base, unsigned int irq)
{
struct Scsi_Host *host;
struct ufs_hba *hba;
int err;
if (!dev) {
dev_err(dev,
"Invalid memory reference for dev is NULL\n");
err = -ENODEV;
goto out_error;
}
if (!mmio_base) {
dev_err(dev,
"Invalid memory reference for mmio_base is NULL\n");
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
hba->mmio_base = mmio_base;
hba->irq = irq;
ufshcd_hba_capabilities(hba);
hba->ufs_version = ufshcd_get_ufs_version(hba);
hba->intr_mask = ufshcd_get_intr_mask(hba);
err = ufshcd_memory_alloc(hba);
if (err) {
dev_err(hba->dev, "Memory allocation failed\n");
goto out_disable;
}
ufshcd_host_memory_configure(hba);
host->can_queue = hba->nutrs;
host->cmd_per_lun = hba->nutrs;
host->max_id = UFSHCD_MAX_ID;
host->max_lun = UFSHCD_MAX_LUNS;
host->max_channel = UFSHCD_MAX_CHANNEL;
host->unique_id = host->host_no;
host->max_cmd_len = MAX_CDB_SIZE;
init_waitqueue_head(&hba->tm_wq);
init_waitqueue_head(&hba->tm_tag_wq);
INIT_WORK(&hba->eh_work, ufshcd_err_handler);
INIT_WORK(&hba->eeh_work, ufshcd_exception_event_handler);
mutex_init(&hba->uic_cmd_mutex);
mutex_init(&hba->dev_cmd.lock);
init_waitqueue_head(&hba->dev_cmd.tag_wq);
err = devm_request_irq(dev, irq, ufshcd_intr, IRQF_SHARED, UFSHCD, hba);
if (err) {
dev_err(hba->dev, "request irq failed\n");
goto out_disable;
}
err = scsi_init_shared_tag_map(host, host->can_queue);
if (err) {
dev_err(hba->dev, "init shared queue failed\n");
goto out_disable;
}
err = scsi_add_host(host, hba->dev);
if (err) {
dev_err(hba->dev, "scsi_add_host failed\n");
goto out_disable;
}
err = ufshcd_hba_enable(hba);
if (err) {
dev_err(hba->dev, "Host controller enable failed\n");
goto out_remove_scsi_host;
}
*hba_handle = hba;
pm_runtime_get_sync(dev);
async_schedule(ufshcd_async_scan, hba);
return 0;
out_remove_scsi_host:
scsi_remove_host(hba->host);
out_disable:
scsi_host_put(host);
out_error:
return err;
}
