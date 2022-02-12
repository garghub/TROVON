int hinic_alloc_cmdq_buf(struct hinic_cmdqs *cmdqs,
struct hinic_cmdq_buf *cmdq_buf)
{
struct hinic_hwif *hwif = cmdqs->hwif;
struct pci_dev *pdev = hwif->pdev;
cmdq_buf->buf = pci_pool_alloc(cmdqs->cmdq_buf_pool, GFP_KERNEL,
&cmdq_buf->dma_addr);
if (!cmdq_buf->buf) {
dev_err(&pdev->dev, "Failed to allocate cmd from the pool\n");
return -ENOMEM;
}
return 0;
}
void hinic_free_cmdq_buf(struct hinic_cmdqs *cmdqs,
struct hinic_cmdq_buf *cmdq_buf)
{
pci_pool_free(cmdqs->cmdq_buf_pool, cmdq_buf->buf, cmdq_buf->dma_addr);
}
static unsigned int cmdq_wqe_size_from_bdlen(enum bufdesc_len len)
{
unsigned int wqe_size = 0;
switch (len) {
case BUFDESC_LCMD_LEN:
wqe_size = WQE_LCMD_SIZE;
break;
case BUFDESC_SCMD_LEN:
wqe_size = WQE_SCMD_SIZE;
break;
}
return wqe_size;
}
static void cmdq_set_sge_completion(struct hinic_cmdq_completion *completion,
struct hinic_cmdq_buf *buf_out)
{
struct hinic_sge_resp *sge_resp = &completion->sge_resp;
hinic_set_sge(&sge_resp->sge, buf_out->dma_addr, buf_out->size);
}
static void cmdq_prepare_wqe_ctrl(struct hinic_cmdq_wqe *wqe, int wrapped,
enum hinic_cmd_ack_type ack_type,
enum hinic_mod_type mod, u8 cmd, u16 prod_idx,
enum completion_format complete_format,
enum data_format data_format,
enum bufdesc_len buf_len)
{
struct hinic_cmdq_wqe_lcmd *wqe_lcmd;
struct hinic_cmdq_wqe_scmd *wqe_scmd;
enum ctrl_sect_len ctrl_len;
struct hinic_ctrl *ctrl;
u32 saved_data;
if (data_format == DATA_SGE) {
wqe_lcmd = &wqe->wqe_lcmd;
wqe_lcmd->status.status_info = 0;
ctrl = &wqe_lcmd->ctrl;
ctrl_len = CTRL_SECT_LEN;
} else {
wqe_scmd = &wqe->direct_wqe.wqe_scmd;
wqe_scmd->status.status_info = 0;
ctrl = &wqe_scmd->ctrl;
ctrl_len = CTRL_DIRECT_SECT_LEN;
}
ctrl->ctrl_info = HINIC_CMDQ_CTRL_SET(prod_idx, PI) |
HINIC_CMDQ_CTRL_SET(cmd, CMD) |
HINIC_CMDQ_CTRL_SET(mod, MOD) |
HINIC_CMDQ_CTRL_SET(ack_type, ACK_TYPE);
CMDQ_WQE_HEADER(wqe)->header_info =
HINIC_CMDQ_WQE_HEADER_SET(buf_len, BUFDESC_LEN) |
HINIC_CMDQ_WQE_HEADER_SET(complete_format, COMPLETE_FMT) |
HINIC_CMDQ_WQE_HEADER_SET(data_format, DATA_FMT) |
HINIC_CMDQ_WQE_HEADER_SET(CEQ_SET, COMPLETE_REQ) |
HINIC_CMDQ_WQE_HEADER_SET(COMPLETE_LEN, COMPLETE_SECT_LEN) |
HINIC_CMDQ_WQE_HEADER_SET(ctrl_len, CTRL_LEN) |
HINIC_CMDQ_WQE_HEADER_SET(wrapped, TOGGLED_WRAPPED);
saved_data = CMDQ_WQE_HEADER(wqe)->saved_data;
saved_data = HINIC_SAVED_DATA_CLEAR(saved_data, ARM);
if ((cmd == CMDQ_SET_ARM_CMD) && (mod == HINIC_MOD_COMM))
CMDQ_WQE_HEADER(wqe)->saved_data |=
HINIC_SAVED_DATA_SET(1, ARM);
else
CMDQ_WQE_HEADER(wqe)->saved_data = saved_data;
}
static void cmdq_set_lcmd_bufdesc(struct hinic_cmdq_wqe_lcmd *wqe_lcmd,
struct hinic_cmdq_buf *buf_in)
{
hinic_set_sge(&wqe_lcmd->buf_desc.sge, buf_in->dma_addr, buf_in->size);
}
static void cmdq_set_direct_wqe_data(struct hinic_cmdq_direct_wqe *wqe,
void *buf_in, u32 in_size)
{
struct hinic_cmdq_wqe_scmd *wqe_scmd = &wqe->wqe_scmd;
wqe_scmd->buf_desc.buf_len = in_size;
memcpy(wqe_scmd->buf_desc.data, buf_in, in_size);
}
static void cmdq_set_lcmd_wqe(struct hinic_cmdq_wqe *wqe,
enum cmdq_cmd_type cmd_type,
struct hinic_cmdq_buf *buf_in,
struct hinic_cmdq_buf *buf_out, int wrapped,
enum hinic_cmd_ack_type ack_type,
enum hinic_mod_type mod, u8 cmd, u16 prod_idx)
{
struct hinic_cmdq_wqe_lcmd *wqe_lcmd = &wqe->wqe_lcmd;
enum completion_format complete_format;
switch (cmd_type) {
case CMDQ_CMD_SYNC_SGE_RESP:
complete_format = COMPLETE_SGE;
cmdq_set_sge_completion(&wqe_lcmd->completion, buf_out);
break;
case CMDQ_CMD_SYNC_DIRECT_RESP:
complete_format = COMPLETE_DIRECT;
wqe_lcmd->completion.direct_resp = 0;
break;
}
cmdq_prepare_wqe_ctrl(wqe, wrapped, ack_type, mod, cmd,
prod_idx, complete_format, DATA_SGE,
BUFDESC_LCMD_LEN);
cmdq_set_lcmd_bufdesc(wqe_lcmd, buf_in);
}
static void cmdq_set_direct_wqe(struct hinic_cmdq_wqe *wqe,
enum cmdq_cmd_type cmd_type,
void *buf_in, u16 in_size,
struct hinic_cmdq_buf *buf_out, int wrapped,
enum hinic_cmd_ack_type ack_type,
enum hinic_mod_type mod, u8 cmd, u16 prod_idx)
{
struct hinic_cmdq_direct_wqe *direct_wqe = &wqe->direct_wqe;
enum completion_format complete_format;
struct hinic_cmdq_wqe_scmd *wqe_scmd;
wqe_scmd = &direct_wqe->wqe_scmd;
switch (cmd_type) {
case CMDQ_CMD_SYNC_SGE_RESP:
complete_format = COMPLETE_SGE;
cmdq_set_sge_completion(&wqe_scmd->completion, buf_out);
break;
case CMDQ_CMD_SYNC_DIRECT_RESP:
complete_format = COMPLETE_DIRECT;
wqe_scmd->completion.direct_resp = 0;
break;
}
cmdq_prepare_wqe_ctrl(wqe, wrapped, ack_type, mod, cmd, prod_idx,
complete_format, DATA_DIRECT, BUFDESC_SCMD_LEN);
cmdq_set_direct_wqe_data(direct_wqe, buf_in, in_size);
}
static void cmdq_wqe_fill(void *dst, void *src)
{
memcpy(dst + FIRST_DATA_TO_WRITE_LAST, src + FIRST_DATA_TO_WRITE_LAST,
CMDQ_WQE_SIZE - FIRST_DATA_TO_WRITE_LAST);
wmb();
*(u64 *)dst = *(u64 *)src;
}
static void cmdq_fill_db(u32 *db_info,
enum hinic_cmdq_type cmdq_type, u16 prod_idx)
{
*db_info = HINIC_CMDQ_DB_INFO_SET(UPPER_8_BITS(prod_idx), HI_PROD_IDX) |
HINIC_CMDQ_DB_INFO_SET(HINIC_CTRL_PATH, PATH) |
HINIC_CMDQ_DB_INFO_SET(cmdq_type, CMDQ_TYPE) |
HINIC_CMDQ_DB_INFO_SET(HINIC_DB_CMDQ_TYPE, DB_TYPE);
}
static void cmdq_set_db(struct hinic_cmdq *cmdq,
enum hinic_cmdq_type cmdq_type, u16 prod_idx)
{
u32 db_info;
cmdq_fill_db(&db_info, cmdq_type, prod_idx);
db_info = cpu_to_be32(db_info);
wmb();
writel(db_info, CMDQ_DB_ADDR(cmdq->db_base, prod_idx));
}
static int cmdq_sync_cmd_direct_resp(struct hinic_cmdq *cmdq,
enum hinic_mod_type mod, u8 cmd,
struct hinic_cmdq_buf *buf_in,
u64 *resp)
{
struct hinic_cmdq_wqe *curr_cmdq_wqe, cmdq_wqe;
u16 curr_prod_idx, next_prod_idx;
int errcode, wrapped, num_wqebbs;
struct hinic_wq *wq = cmdq->wq;
struct hinic_hw_wqe *hw_wqe;
struct completion done;
spin_lock_bh(&cmdq->cmdq_lock);
hw_wqe = hinic_get_wqe(wq, WQE_LCMD_SIZE, &curr_prod_idx);
if (IS_ERR(hw_wqe)) {
spin_unlock_bh(&cmdq->cmdq_lock);
return -EBUSY;
}
curr_cmdq_wqe = &hw_wqe->cmdq_wqe;
wrapped = cmdq->wrapped;
num_wqebbs = ALIGN(WQE_LCMD_SIZE, wq->wqebb_size) / wq->wqebb_size;
next_prod_idx = curr_prod_idx + num_wqebbs;
if (next_prod_idx >= wq->q_depth) {
cmdq->wrapped = !cmdq->wrapped;
next_prod_idx -= wq->q_depth;
}
cmdq->errcode[curr_prod_idx] = &errcode;
init_completion(&done);
cmdq->done[curr_prod_idx] = &done;
cmdq_set_lcmd_wqe(&cmdq_wqe, CMDQ_CMD_SYNC_DIRECT_RESP, buf_in, NULL,
wrapped, HINIC_CMD_ACK_TYPE_CMDQ, mod, cmd,
curr_prod_idx);
hinic_cpu_to_be32(&cmdq_wqe, WQE_LCMD_SIZE);
cmdq_wqe_fill(curr_cmdq_wqe, &cmdq_wqe);
cmdq_set_db(cmdq, HINIC_CMDQ_SYNC, next_prod_idx);
spin_unlock_bh(&cmdq->cmdq_lock);
if (!wait_for_completion_timeout(&done, CMDQ_TIMEOUT)) {
spin_lock_bh(&cmdq->cmdq_lock);
if (cmdq->errcode[curr_prod_idx] == &errcode)
cmdq->errcode[curr_prod_idx] = NULL;
if (cmdq->done[curr_prod_idx] == &done)
cmdq->done[curr_prod_idx] = NULL;
spin_unlock_bh(&cmdq->cmdq_lock);
return -ETIMEDOUT;
}
smp_rmb();
if (resp) {
struct hinic_cmdq_wqe_lcmd *wqe_lcmd = &curr_cmdq_wqe->wqe_lcmd;
*resp = cpu_to_be64(wqe_lcmd->completion.direct_resp);
}
if (errcode != 0)
return -EFAULT;
return 0;
}
static int cmdq_set_arm_bit(struct hinic_cmdq *cmdq, void *buf_in,
u16 in_size)
{
struct hinic_cmdq_wqe *curr_cmdq_wqe, cmdq_wqe;
u16 curr_prod_idx, next_prod_idx;
struct hinic_wq *wq = cmdq->wq;
struct hinic_hw_wqe *hw_wqe;
int wrapped, num_wqebbs;
spin_lock(&cmdq->cmdq_lock);
hw_wqe = hinic_get_wqe(wq, WQE_SCMD_SIZE, &curr_prod_idx);
if (IS_ERR(hw_wqe)) {
spin_unlock(&cmdq->cmdq_lock);
return -EBUSY;
}
curr_cmdq_wqe = &hw_wqe->cmdq_wqe;
wrapped = cmdq->wrapped;
num_wqebbs = ALIGN(WQE_SCMD_SIZE, wq->wqebb_size) / wq->wqebb_size;
next_prod_idx = curr_prod_idx + num_wqebbs;
if (next_prod_idx >= wq->q_depth) {
cmdq->wrapped = !cmdq->wrapped;
next_prod_idx -= wq->q_depth;
}
cmdq_set_direct_wqe(&cmdq_wqe, CMDQ_CMD_SYNC_DIRECT_RESP, buf_in,
in_size, NULL, wrapped, HINIC_CMD_ACK_TYPE_CMDQ,
HINIC_MOD_COMM, CMDQ_SET_ARM_CMD, curr_prod_idx);
hinic_cpu_to_be32(&cmdq_wqe, WQE_SCMD_SIZE);
cmdq_wqe_fill(curr_cmdq_wqe, &cmdq_wqe);
cmdq_set_db(cmdq, HINIC_CMDQ_SYNC, next_prod_idx);
spin_unlock(&cmdq->cmdq_lock);
return 0;
}
static int cmdq_params_valid(struct hinic_cmdq_buf *buf_in)
{
if (buf_in->size > HINIC_CMDQ_MAX_DATA_SIZE)
return -EINVAL;
return 0;
}
int hinic_cmdq_direct_resp(struct hinic_cmdqs *cmdqs,
enum hinic_mod_type mod, u8 cmd,
struct hinic_cmdq_buf *buf_in, u64 *resp)
{
struct hinic_hwif *hwif = cmdqs->hwif;
struct pci_dev *pdev = hwif->pdev;
int err;
err = cmdq_params_valid(buf_in);
if (err) {
dev_err(&pdev->dev, "Invalid CMDQ parameters\n");
return err;
}
return cmdq_sync_cmd_direct_resp(&cmdqs->cmdq[HINIC_CMDQ_SYNC],
mod, cmd, buf_in, resp);
}
int hinic_set_arm_bit(struct hinic_cmdqs *cmdqs,
enum hinic_set_arm_qtype q_type, u32 q_id)
{
struct hinic_cmdq *cmdq = &cmdqs->cmdq[HINIC_CMDQ_SYNC];
struct hinic_hwif *hwif = cmdqs->hwif;
struct pci_dev *pdev = hwif->pdev;
struct hinic_cmdq_arm_bit arm_bit;
int err;
arm_bit.q_type = q_type;
arm_bit.q_id = q_id;
err = cmdq_set_arm_bit(cmdq, &arm_bit, sizeof(arm_bit));
if (err) {
dev_err(&pdev->dev, "Failed to set arm for qid %d\n", q_id);
return err;
}
return 0;
}
static void clear_wqe_complete_bit(struct hinic_cmdq *cmdq,
struct hinic_cmdq_wqe *wqe)
{
u32 header_info = be32_to_cpu(CMDQ_WQE_HEADER(wqe)->header_info);
unsigned int bufdesc_len, wqe_size;
struct hinic_ctrl *ctrl;
bufdesc_len = HINIC_CMDQ_WQE_HEADER_GET(header_info, BUFDESC_LEN);
wqe_size = cmdq_wqe_size_from_bdlen(bufdesc_len);
if (wqe_size == WQE_LCMD_SIZE) {
struct hinic_cmdq_wqe_lcmd *wqe_lcmd = &wqe->wqe_lcmd;
ctrl = &wqe_lcmd->ctrl;
} else {
struct hinic_cmdq_direct_wqe *direct_wqe = &wqe->direct_wqe;
struct hinic_cmdq_wqe_scmd *wqe_scmd;
wqe_scmd = &direct_wqe->wqe_scmd;
ctrl = &wqe_scmd->ctrl;
}
ctrl->ctrl_info = 0;
wmb();
}
static int cmdq_arm_ceq_handler(struct hinic_cmdq *cmdq,
struct hinic_cmdq_wqe *wqe)
{
struct hinic_cmdq_direct_wqe *direct_wqe = &wqe->direct_wqe;
struct hinic_cmdq_wqe_scmd *wqe_scmd;
struct hinic_ctrl *ctrl;
u32 ctrl_info;
wqe_scmd = &direct_wqe->wqe_scmd;
ctrl = &wqe_scmd->ctrl;
ctrl_info = be32_to_cpu(ctrl->ctrl_info);
if (!CMDQ_WQE_COMPLETED(ctrl_info))
return -EBUSY;
clear_wqe_complete_bit(cmdq, wqe);
hinic_put_wqe(cmdq->wq, WQE_SCMD_SIZE);
return 0;
}
static void cmdq_update_errcode(struct hinic_cmdq *cmdq, u16 prod_idx,
int errcode)
{
if (cmdq->errcode[prod_idx])
*cmdq->errcode[prod_idx] = errcode;
}
static void cmdq_sync_cmd_handler(struct hinic_cmdq *cmdq, u16 cons_idx,
int errcode)
{
u16 prod_idx = cons_idx;
spin_lock(&cmdq->cmdq_lock);
cmdq_update_errcode(cmdq, prod_idx, errcode);
wmb();
if (cmdq->done[prod_idx])
complete(cmdq->done[prod_idx]);
spin_unlock(&cmdq->cmdq_lock);
}
static int cmdq_cmd_ceq_handler(struct hinic_cmdq *cmdq, u16 ci,
struct hinic_cmdq_wqe *cmdq_wqe)
{
struct hinic_cmdq_wqe_lcmd *wqe_lcmd = &cmdq_wqe->wqe_lcmd;
struct hinic_status *status = &wqe_lcmd->status;
struct hinic_ctrl *ctrl = &wqe_lcmd->ctrl;
int errcode;
if (!CMDQ_WQE_COMPLETED(be32_to_cpu(ctrl->ctrl_info)))
return -EBUSY;
errcode = CMDQ_WQE_ERRCODE_GET(be32_to_cpu(status->status_info), VAL);
cmdq_sync_cmd_handler(cmdq, ci, errcode);
clear_wqe_complete_bit(cmdq, cmdq_wqe);
hinic_put_wqe(cmdq->wq, WQE_LCMD_SIZE);
return 0;
}
static void cmdq_ceq_handler(void *handle, u32 ceqe_data)
{
enum hinic_cmdq_type cmdq_type = CMDQ_CEQE_GET(ceqe_data, TYPE);
struct hinic_cmdqs *cmdqs = (struct hinic_cmdqs *)handle;
struct hinic_cmdq *cmdq = &cmdqs->cmdq[cmdq_type];
struct hinic_cmdq_header *header;
struct hinic_hw_wqe *hw_wqe;
int err, set_arm = 0;
u32 saved_data;
u16 ci;
while ((hw_wqe = hinic_read_wqe(cmdq->wq, WQE_SCMD_SIZE, &ci))) {
if (IS_ERR(hw_wqe))
break;
header = CMDQ_WQE_HEADER(&hw_wqe->cmdq_wqe);
saved_data = be32_to_cpu(header->saved_data);
if (HINIC_SAVED_DATA_GET(saved_data, ARM)) {
set_arm = 0;
if (cmdq_arm_ceq_handler(cmdq, &hw_wqe->cmdq_wqe))
break;
} else {
set_arm = 1;
hw_wqe = hinic_read_wqe(cmdq->wq, WQE_LCMD_SIZE, &ci);
if (IS_ERR(hw_wqe))
break;
if (cmdq_cmd_ceq_handler(cmdq, ci, &hw_wqe->cmdq_wqe))
break;
}
}
if (set_arm) {
struct hinic_hwif *hwif = cmdqs->hwif;
struct pci_dev *pdev = hwif->pdev;
err = hinic_set_arm_bit(cmdqs, HINIC_SET_ARM_CMDQ, cmdq_type);
if (err)
dev_err(&pdev->dev, "Failed to set arm for CMDQ\n");
}
}
static void cmdq_init_queue_ctxt(struct hinic_cmdq_ctxt *cmdq_ctxt,
struct hinic_cmdq *cmdq,
struct hinic_cmdq_pages *cmdq_pages)
{
struct hinic_cmdq_ctxt_info *ctxt_info = &cmdq_ctxt->ctxt_info;
u64 wq_first_page_paddr, cmdq_first_block_paddr, pfn;
struct hinic_cmdqs *cmdqs = cmdq_to_cmdqs(cmdq);
struct hinic_wq *wq = cmdq->wq;
wq_first_page_paddr = be64_to_cpu(*wq->block_vaddr);
pfn = CMDQ_PFN(wq_first_page_paddr, wq->wq_page_size);
ctxt_info->curr_wqe_page_pfn =
HINIC_CMDQ_CTXT_PAGE_INFO_SET(pfn, CURR_WQE_PAGE_PFN) |
HINIC_CMDQ_CTXT_PAGE_INFO_SET(HINIC_CEQ_ID_CMDQ, EQ_ID) |
HINIC_CMDQ_CTXT_PAGE_INFO_SET(1, CEQ_ARM) |
HINIC_CMDQ_CTXT_PAGE_INFO_SET(1, CEQ_EN) |
HINIC_CMDQ_CTXT_PAGE_INFO_SET(cmdq->wrapped, WRAPPED);
cmdq_first_block_paddr = cmdq_pages->page_paddr;
pfn = CMDQ_PFN(cmdq_first_block_paddr, wq->wq_page_size);
ctxt_info->wq_block_pfn =
HINIC_CMDQ_CTXT_BLOCK_INFO_SET(pfn, WQ_BLOCK_PFN) |
HINIC_CMDQ_CTXT_BLOCK_INFO_SET(atomic_read(&wq->cons_idx), CI);
cmdq_ctxt->func_idx = HINIC_HWIF_FUNC_IDX(cmdqs->hwif);
cmdq_ctxt->cmdq_type = cmdq->cmdq_type;
}
static int init_cmdq(struct hinic_cmdq *cmdq, struct hinic_wq *wq,
enum hinic_cmdq_type q_type, void __iomem *db_area)
{
int err;
cmdq->wq = wq;
cmdq->cmdq_type = q_type;
cmdq->wrapped = 1;
spin_lock_init(&cmdq->cmdq_lock);
cmdq->done = vzalloc(wq->q_depth * sizeof(*cmdq->done));
if (!cmdq->done)
return -ENOMEM;
cmdq->errcode = vzalloc(wq->q_depth * sizeof(*cmdq->errcode));
if (!cmdq->errcode) {
err = -ENOMEM;
goto err_errcode;
}
cmdq->db_base = db_area + CMDQ_DB_OFF;
return 0;
err_errcode:
vfree(cmdq->done);
return err;
}
static void free_cmdq(struct hinic_cmdq *cmdq)
{
vfree(cmdq->errcode);
vfree(cmdq->done);
}
static int init_cmdqs_ctxt(struct hinic_hwdev *hwdev,
struct hinic_cmdqs *cmdqs, void __iomem **db_area)
{
struct hinic_hwif *hwif = hwdev->hwif;
enum hinic_cmdq_type type, cmdq_type;
struct hinic_cmdq_ctxt *cmdq_ctxts;
struct pci_dev *pdev = hwif->pdev;
struct hinic_pfhwdev *pfhwdev;
size_t cmdq_ctxts_size;
int err;
if (!HINIC_IS_PF(hwif) && !HINIC_IS_PPF(hwif)) {
dev_err(&pdev->dev, "Unsupported PCI function type\n");
return -EINVAL;
}
cmdq_ctxts_size = HINIC_MAX_CMDQ_TYPES * sizeof(*cmdq_ctxts);
cmdq_ctxts = devm_kzalloc(&pdev->dev, cmdq_ctxts_size, GFP_KERNEL);
if (!cmdq_ctxts)
return -ENOMEM;
pfhwdev = container_of(hwdev, struct hinic_pfhwdev, hwdev);
cmdq_type = HINIC_CMDQ_SYNC;
for (; cmdq_type < HINIC_MAX_CMDQ_TYPES; cmdq_type++) {
err = init_cmdq(&cmdqs->cmdq[cmdq_type],
&cmdqs->saved_wqs[cmdq_type], cmdq_type,
db_area[cmdq_type]);
if (err) {
dev_err(&pdev->dev, "Failed to initialize cmdq\n");
goto err_init_cmdq;
}
cmdq_init_queue_ctxt(&cmdq_ctxts[cmdq_type],
&cmdqs->cmdq[cmdq_type],
&cmdqs->cmdq_pages);
}
cmdq_type = HINIC_CMDQ_SYNC;
for (; cmdq_type < HINIC_MAX_CMDQ_TYPES; cmdq_type++) {
err = hinic_msg_to_mgmt(&pfhwdev->pf_to_mgmt, HINIC_MOD_COMM,
HINIC_COMM_CMD_CMDQ_CTXT_SET,
&cmdq_ctxts[cmdq_type],
sizeof(cmdq_ctxts[cmdq_type]),
NULL, NULL, HINIC_MGMT_MSG_SYNC);
if (err) {
dev_err(&pdev->dev, "Failed to set CMDQ CTXT type = %d\n",
cmdq_type);
goto err_write_cmdq_ctxt;
}
}
devm_kfree(&pdev->dev, cmdq_ctxts);
return 0;
err_write_cmdq_ctxt:
cmdq_type = HINIC_MAX_CMDQ_TYPES;
err_init_cmdq:
for (type = HINIC_CMDQ_SYNC; type < cmdq_type; type++)
free_cmdq(&cmdqs->cmdq[type]);
devm_kfree(&pdev->dev, cmdq_ctxts);
return err;
}
int hinic_init_cmdqs(struct hinic_cmdqs *cmdqs, struct hinic_hwif *hwif,
void __iomem **db_area)
{
struct hinic_func_to_io *func_to_io = cmdqs_to_func_to_io(cmdqs);
struct pci_dev *pdev = hwif->pdev;
struct hinic_hwdev *hwdev;
size_t saved_wqs_size;
u16 max_wqe_size;
int err;
cmdqs->hwif = hwif;
cmdqs->cmdq_buf_pool = pci_pool_create("hinic_cmdq", pdev,
HINIC_CMDQ_BUF_SIZE,
HINIC_CMDQ_BUF_SIZE, 0);
if (!cmdqs->cmdq_buf_pool)
return -ENOMEM;
saved_wqs_size = HINIC_MAX_CMDQ_TYPES * sizeof(struct hinic_wq);
cmdqs->saved_wqs = devm_kzalloc(&pdev->dev, saved_wqs_size, GFP_KERNEL);
if (!cmdqs->saved_wqs) {
err = -ENOMEM;
goto err_saved_wqs;
}
max_wqe_size = WQE_LCMD_SIZE;
err = hinic_wqs_cmdq_alloc(&cmdqs->cmdq_pages, cmdqs->saved_wqs, hwif,
HINIC_MAX_CMDQ_TYPES, CMDQ_WQEBB_SIZE,
CMDQ_WQ_PAGE_SIZE, CMDQ_DEPTH, max_wqe_size);
if (err) {
dev_err(&pdev->dev, "Failed to allocate CMDQ wqs\n");
goto err_cmdq_wqs;
}
hwdev = container_of(func_to_io, struct hinic_hwdev, func_to_io);
err = init_cmdqs_ctxt(hwdev, cmdqs, db_area);
if (err) {
dev_err(&pdev->dev, "Failed to write cmdq ctxt\n");
goto err_cmdq_ctxt;
}
hinic_ceq_register_cb(&func_to_io->ceqs, HINIC_CEQ_CMDQ, cmdqs,
cmdq_ceq_handler);
return 0;
err_cmdq_ctxt:
hinic_wqs_cmdq_free(&cmdqs->cmdq_pages, cmdqs->saved_wqs,
HINIC_MAX_CMDQ_TYPES);
err_cmdq_wqs:
devm_kfree(&pdev->dev, cmdqs->saved_wqs);
err_saved_wqs:
pci_pool_destroy(cmdqs->cmdq_buf_pool);
return err;
}
void hinic_free_cmdqs(struct hinic_cmdqs *cmdqs)
{
struct hinic_func_to_io *func_to_io = cmdqs_to_func_to_io(cmdqs);
struct hinic_hwif *hwif = cmdqs->hwif;
struct pci_dev *pdev = hwif->pdev;
enum hinic_cmdq_type cmdq_type;
hinic_ceq_unregister_cb(&func_to_io->ceqs, HINIC_CEQ_CMDQ);
cmdq_type = HINIC_CMDQ_SYNC;
for (; cmdq_type < HINIC_MAX_CMDQ_TYPES; cmdq_type++)
free_cmdq(&cmdqs->cmdq[cmdq_type]);
hinic_wqs_cmdq_free(&cmdqs->cmdq_pages, cmdqs->saved_wqs,
HINIC_MAX_CMDQ_TYPES);
devm_kfree(&pdev->dev, cmdqs->saved_wqs);
pci_pool_destroy(cmdqs->cmdq_buf_pool);
}
