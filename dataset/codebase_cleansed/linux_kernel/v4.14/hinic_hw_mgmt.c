void hinic_register_mgmt_msg_cb(struct hinic_pf_to_mgmt *pf_to_mgmt,
enum hinic_mod_type mod,
void *handle,
void (*callback)(void *handle,
u8 cmd, void *buf_in,
u16 in_size, void *buf_out,
u16 *out_size))
{
struct hinic_mgmt_cb *mgmt_cb = &pf_to_mgmt->mgmt_cb[mod];
mgmt_cb->cb = callback;
mgmt_cb->handle = handle;
mgmt_cb->state = HINIC_MGMT_CB_ENABLED;
}
void hinic_unregister_mgmt_msg_cb(struct hinic_pf_to_mgmt *pf_to_mgmt,
enum hinic_mod_type mod)
{
struct hinic_mgmt_cb *mgmt_cb = &pf_to_mgmt->mgmt_cb[mod];
mgmt_cb->state &= ~HINIC_MGMT_CB_ENABLED;
while (mgmt_cb->state & HINIC_MGMT_CB_RUNNING)
schedule();
mgmt_cb->cb = NULL;
}
static u64 prepare_header(struct hinic_pf_to_mgmt *pf_to_mgmt,
u16 msg_len, enum hinic_mod_type mod,
enum msg_ack_type ack_type,
enum mgmt_direction_type direction,
u16 cmd, u16 msg_id)
{
struct hinic_hwif *hwif = pf_to_mgmt->hwif;
return HINIC_MSG_HEADER_SET(msg_len, MSG_LEN) |
HINIC_MSG_HEADER_SET(mod, MODULE) |
HINIC_MSG_HEADER_SET(SEGMENT_LEN, SEG_LEN) |
HINIC_MSG_HEADER_SET(ack_type, NO_ACK) |
HINIC_MSG_HEADER_SET(0, ASYNC_MGMT_TO_PF) |
HINIC_MSG_HEADER_SET(0, SEQID) |
HINIC_MSG_HEADER_SET(LAST_SEGMENT, LAST) |
HINIC_MSG_HEADER_SET(direction, DIRECTION) |
HINIC_MSG_HEADER_SET(cmd, CMD) |
HINIC_MSG_HEADER_SET(HINIC_HWIF_PCI_INTF(hwif), PCI_INTF) |
HINIC_MSG_HEADER_SET(HINIC_HWIF_PF_IDX(hwif), PF_IDX) |
HINIC_MSG_HEADER_SET(msg_id, MSG_ID);
}
static void prepare_mgmt_cmd(u8 *mgmt_cmd, u64 *header, u8 *msg, u16 msg_len)
{
memset(mgmt_cmd, 0, MGMT_MSG_RSVD_FOR_DEV);
mgmt_cmd += MGMT_MSG_RSVD_FOR_DEV;
memcpy(mgmt_cmd, header, sizeof(*header));
mgmt_cmd += sizeof(*header);
memcpy(mgmt_cmd, msg, msg_len);
}
static u16 mgmt_msg_len(u16 msg_data_len)
{
u16 msg_len = MGMT_MSG_RSVD_FOR_DEV + sizeof(u64) + msg_data_len;
if (msg_len > MGMT_MSG_LEN_MIN)
msg_len = MGMT_MSG_LEN_MIN +
ALIGN((msg_len - MGMT_MSG_LEN_MIN),
MGMT_MSG_LEN_STEP);
else
msg_len = MGMT_MSG_LEN_MIN;
return msg_len;
}
static int send_msg_to_mgmt(struct hinic_pf_to_mgmt *pf_to_mgmt,
enum hinic_mod_type mod, u8 cmd,
u8 *data, u16 data_len,
enum msg_ack_type ack_type,
enum mgmt_direction_type direction,
u16 resp_msg_id)
{
struct hinic_api_cmd_chain *chain;
u64 header;
u16 msg_id;
msg_id = SYNC_MSG_ID(pf_to_mgmt);
if (direction == MGMT_RESP) {
header = prepare_header(pf_to_mgmt, data_len, mod, ack_type,
direction, cmd, resp_msg_id);
} else {
SYNC_MSG_ID_INC(pf_to_mgmt);
header = prepare_header(pf_to_mgmt, data_len, mod, ack_type,
direction, cmd, msg_id);
}
prepare_mgmt_cmd(pf_to_mgmt->sync_msg_buf, &header, data, data_len);
chain = pf_to_mgmt->cmd_chain[HINIC_API_CMD_WRITE_TO_MGMT_CPU];
return hinic_api_cmd_write(chain, HINIC_NODE_ID_MGMT,
pf_to_mgmt->sync_msg_buf,
mgmt_msg_len(data_len));
}
static int msg_to_mgmt_sync(struct hinic_pf_to_mgmt *pf_to_mgmt,
enum hinic_mod_type mod, u8 cmd,
u8 *buf_in, u16 in_size,
u8 *buf_out, u16 *out_size,
enum mgmt_direction_type direction,
u16 resp_msg_id)
{
struct hinic_hwif *hwif = pf_to_mgmt->hwif;
struct pci_dev *pdev = hwif->pdev;
struct hinic_recv_msg *recv_msg;
struct completion *recv_done;
u16 msg_id;
int err;
down(&pf_to_mgmt->sync_msg_lock);
recv_msg = &pf_to_mgmt->recv_resp_msg_from_mgmt;
recv_done = &recv_msg->recv_done;
if (resp_msg_id == MSG_NOT_RESP)
msg_id = SYNC_MSG_ID(pf_to_mgmt);
else
msg_id = resp_msg_id;
init_completion(recv_done);
err = send_msg_to_mgmt(pf_to_mgmt, mod, cmd, buf_in, in_size,
MSG_ACK, direction, resp_msg_id);
if (err) {
dev_err(&pdev->dev, "Failed to send sync msg to mgmt\n");
goto unlock_sync_msg;
}
if (!wait_for_completion_timeout(recv_done, MGMT_MSG_TIMEOUT)) {
dev_err(&pdev->dev, "MGMT timeout, MSG id = %d\n", msg_id);
err = -ETIMEDOUT;
goto unlock_sync_msg;
}
smp_rmb();
if (recv_msg->msg_id != msg_id) {
dev_err(&pdev->dev, "incorrect MSG for id = %d\n", msg_id);
err = -EFAULT;
goto unlock_sync_msg;
}
if ((buf_out) && (recv_msg->msg_len <= MAX_PF_MGMT_BUF_SIZE)) {
memcpy(buf_out, recv_msg->msg, recv_msg->msg_len);
*out_size = recv_msg->msg_len;
}
unlock_sync_msg:
up(&pf_to_mgmt->sync_msg_lock);
return err;
}
static int msg_to_mgmt_async(struct hinic_pf_to_mgmt *pf_to_mgmt,
enum hinic_mod_type mod, u8 cmd,
u8 *buf_in, u16 in_size,
enum mgmt_direction_type direction,
u16 resp_msg_id)
{
int err;
down(&pf_to_mgmt->sync_msg_lock);
err = send_msg_to_mgmt(pf_to_mgmt, mod, cmd, buf_in, in_size,
MSG_NO_ACK, direction, resp_msg_id);
up(&pf_to_mgmt->sync_msg_lock);
return err;
}
int hinic_msg_to_mgmt(struct hinic_pf_to_mgmt *pf_to_mgmt,
enum hinic_mod_type mod, u8 cmd,
void *buf_in, u16 in_size, void *buf_out, u16 *out_size,
enum hinic_mgmt_msg_type sync)
{
struct hinic_hwif *hwif = pf_to_mgmt->hwif;
struct pci_dev *pdev = hwif->pdev;
if (sync != HINIC_MGMT_MSG_SYNC) {
dev_err(&pdev->dev, "Invalid MGMT msg type\n");
return -EINVAL;
}
if (!MSG_SZ_IS_VALID(in_size)) {
dev_err(&pdev->dev, "Invalid MGMT msg buffer size\n");
return -EINVAL;
}
return msg_to_mgmt_sync(pf_to_mgmt, mod, cmd, buf_in, in_size,
buf_out, out_size, MGMT_DIRECT_SEND,
MSG_NOT_RESP);
}
static void mgmt_recv_msg_handler(struct hinic_pf_to_mgmt *pf_to_mgmt,
struct hinic_recv_msg *recv_msg)
{
struct hinic_hwif *hwif = pf_to_mgmt->hwif;
struct pci_dev *pdev = hwif->pdev;
u8 *buf_out = recv_msg->buf_out;
struct hinic_mgmt_cb *mgmt_cb;
unsigned long cb_state;
u16 out_size = 0;
if (recv_msg->mod >= HINIC_MOD_MAX) {
dev_err(&pdev->dev, "Unknown MGMT MSG module = %d\n",
recv_msg->mod);
return;
}
mgmt_cb = &pf_to_mgmt->mgmt_cb[recv_msg->mod];
cb_state = cmpxchg(&mgmt_cb->state,
HINIC_MGMT_CB_ENABLED,
HINIC_MGMT_CB_ENABLED | HINIC_MGMT_CB_RUNNING);
if ((cb_state == HINIC_MGMT_CB_ENABLED) && (mgmt_cb->cb))
mgmt_cb->cb(mgmt_cb->handle, recv_msg->cmd,
recv_msg->msg, recv_msg->msg_len,
buf_out, &out_size);
else
dev_err(&pdev->dev, "No MGMT msg handler, mod = %d\n",
recv_msg->mod);
mgmt_cb->state &= ~HINIC_MGMT_CB_RUNNING;
if (!recv_msg->async_mgmt_to_pf)
msg_to_mgmt_async(pf_to_mgmt, recv_msg->mod, recv_msg->cmd,
buf_out, out_size, MGMT_RESP,
recv_msg->msg_id);
}
static void mgmt_resp_msg_handler(struct hinic_pf_to_mgmt *pf_to_mgmt,
struct hinic_recv_msg *recv_msg)
{
wmb();
complete(&recv_msg->recv_done);
}
static void recv_mgmt_msg_handler(struct hinic_pf_to_mgmt *pf_to_mgmt,
u64 *header, struct hinic_recv_msg *recv_msg)
{
struct hinic_hwif *hwif = pf_to_mgmt->hwif;
struct pci_dev *pdev = hwif->pdev;
int seq_id, seg_len;
u8 *msg_body;
seq_id = HINIC_MSG_HEADER_GET(*header, SEQID);
seg_len = HINIC_MSG_HEADER_GET(*header, SEG_LEN);
if (seq_id >= (MAX_MSG_LEN / SEGMENT_LEN)) {
dev_err(&pdev->dev, "recv big mgmt msg\n");
return;
}
msg_body = (u8 *)header + sizeof(*header);
memcpy(recv_msg->msg + seq_id * SEGMENT_LEN, msg_body, seg_len);
if (!HINIC_MSG_HEADER_GET(*header, LAST))
return;
recv_msg->cmd = HINIC_MSG_HEADER_GET(*header, CMD);
recv_msg->mod = HINIC_MSG_HEADER_GET(*header, MODULE);
recv_msg->async_mgmt_to_pf = HINIC_MSG_HEADER_GET(*header,
ASYNC_MGMT_TO_PF);
recv_msg->msg_len = HINIC_MSG_HEADER_GET(*header, MSG_LEN);
recv_msg->msg_id = HINIC_MSG_HEADER_GET(*header, MSG_ID);
if (HINIC_MSG_HEADER_GET(*header, DIRECTION) == MGMT_RESP)
mgmt_resp_msg_handler(pf_to_mgmt, recv_msg);
else
mgmt_recv_msg_handler(pf_to_mgmt, recv_msg);
}
static void mgmt_msg_aeqe_handler(void *handle, void *data, u8 size)
{
struct hinic_pf_to_mgmt *pf_to_mgmt = handle;
struct hinic_recv_msg *recv_msg;
u64 *header = (u64 *)data;
recv_msg = HINIC_MSG_HEADER_GET(*header, DIRECTION) ==
MGMT_DIRECT_SEND ?
&pf_to_mgmt->recv_msg_from_mgmt :
&pf_to_mgmt->recv_resp_msg_from_mgmt;
recv_mgmt_msg_handler(pf_to_mgmt, header, recv_msg);
}
static int alloc_recv_msg(struct hinic_pf_to_mgmt *pf_to_mgmt,
struct hinic_recv_msg *recv_msg)
{
struct hinic_hwif *hwif = pf_to_mgmt->hwif;
struct pci_dev *pdev = hwif->pdev;
recv_msg->msg = devm_kzalloc(&pdev->dev, MAX_PF_MGMT_BUF_SIZE,
GFP_KERNEL);
if (!recv_msg->msg)
return -ENOMEM;
recv_msg->buf_out = devm_kzalloc(&pdev->dev, MAX_PF_MGMT_BUF_SIZE,
GFP_KERNEL);
if (!recv_msg->buf_out)
return -ENOMEM;
return 0;
}
static int alloc_msg_buf(struct hinic_pf_to_mgmt *pf_to_mgmt)
{
struct hinic_hwif *hwif = pf_to_mgmt->hwif;
struct pci_dev *pdev = hwif->pdev;
int err;
err = alloc_recv_msg(pf_to_mgmt,
&pf_to_mgmt->recv_msg_from_mgmt);
if (err) {
dev_err(&pdev->dev, "Failed to allocate recv msg\n");
return err;
}
err = alloc_recv_msg(pf_to_mgmt,
&pf_to_mgmt->recv_resp_msg_from_mgmt);
if (err) {
dev_err(&pdev->dev, "Failed to allocate resp recv msg\n");
return err;
}
pf_to_mgmt->sync_msg_buf = devm_kzalloc(&pdev->dev,
MAX_PF_MGMT_BUF_SIZE,
GFP_KERNEL);
if (!pf_to_mgmt->sync_msg_buf)
return -ENOMEM;
return 0;
}
int hinic_pf_to_mgmt_init(struct hinic_pf_to_mgmt *pf_to_mgmt,
struct hinic_hwif *hwif)
{
struct hinic_pfhwdev *pfhwdev = mgmt_to_pfhwdev(pf_to_mgmt);
struct hinic_hwdev *hwdev = &pfhwdev->hwdev;
struct pci_dev *pdev = hwif->pdev;
int err;
pf_to_mgmt->hwif = hwif;
sema_init(&pf_to_mgmt->sync_msg_lock, 1);
pf_to_mgmt->sync_msg_id = 0;
err = alloc_msg_buf(pf_to_mgmt);
if (err) {
dev_err(&pdev->dev, "Failed to allocate msg buffers\n");
return err;
}
err = hinic_api_cmd_init(pf_to_mgmt->cmd_chain, hwif);
if (err) {
dev_err(&pdev->dev, "Failed to initialize cmd chains\n");
return err;
}
hinic_aeq_register_hw_cb(&hwdev->aeqs, HINIC_MSG_FROM_MGMT_CPU,
pf_to_mgmt,
mgmt_msg_aeqe_handler);
return 0;
}
void hinic_pf_to_mgmt_free(struct hinic_pf_to_mgmt *pf_to_mgmt)
{
struct hinic_pfhwdev *pfhwdev = mgmt_to_pfhwdev(pf_to_mgmt);
struct hinic_hwdev *hwdev = &pfhwdev->hwdev;
hinic_aeq_unregister_hw_cb(&hwdev->aeqs, HINIC_MSG_FROM_MGMT_CPU);
hinic_api_cmd_free(pf_to_mgmt->cmd_chain);
}
