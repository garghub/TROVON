static int iwm_nonwifi_cmd_init(struct iwm_priv *iwm,
struct iwm_nonwifi_cmd *cmd,
struct iwm_udma_nonwifi_cmd *udma_cmd)
{
INIT_LIST_HEAD(&cmd->pending);
spin_lock(&iwm->cmd_lock);
cmd->resp_received = 0;
cmd->seq_num = iwm->nonwifi_seq_num;
udma_cmd->seq_num = cpu_to_le16(cmd->seq_num);
iwm->nonwifi_seq_num++;
iwm->nonwifi_seq_num %= UMAC_NONWIFI_SEQ_NUM_MAX;
if (udma_cmd->resp)
list_add_tail(&cmd->pending, &iwm->nonwifi_pending_cmd);
spin_unlock(&iwm->cmd_lock);
cmd->buf.start = cmd->buf.payload;
cmd->buf.len = 0;
memcpy(&cmd->udma_cmd, udma_cmd, sizeof(*udma_cmd));
return cmd->seq_num;
}
u16 iwm_alloc_wifi_cmd_seq(struct iwm_priv *iwm)
{
u16 seq_num = iwm->wifi_seq_num;
iwm->wifi_seq_num++;
iwm->wifi_seq_num %= UMAC_WIFI_SEQ_NUM_MAX;
return seq_num;
}
static void iwm_wifi_cmd_init(struct iwm_priv *iwm,
struct iwm_wifi_cmd *cmd,
struct iwm_udma_wifi_cmd *udma_cmd,
struct iwm_umac_cmd *umac_cmd,
struct iwm_lmac_cmd *lmac_cmd,
u16 payload_size)
{
INIT_LIST_HEAD(&cmd->pending);
spin_lock(&iwm->cmd_lock);
cmd->seq_num = iwm_alloc_wifi_cmd_seq(iwm);
umac_cmd->seq_num = cpu_to_le16(cmd->seq_num);
if (umac_cmd->resp)
list_add_tail(&cmd->pending, &iwm->wifi_pending_cmd);
spin_unlock(&iwm->cmd_lock);
cmd->buf.start = cmd->buf.payload;
cmd->buf.len = 0;
if (lmac_cmd) {
cmd->buf.start -= sizeof(struct iwm_lmac_hdr);
lmac_cmd->seq_num = cpu_to_le16(cmd->seq_num);
lmac_cmd->count = cpu_to_le16(payload_size);
memcpy(&cmd->lmac_cmd, lmac_cmd, sizeof(*lmac_cmd));
umac_cmd->count = cpu_to_le16(sizeof(struct iwm_lmac_hdr));
} else
umac_cmd->count = 0;
umac_cmd->count = cpu_to_le16(payload_size +
le16_to_cpu(umac_cmd->count));
udma_cmd->count = cpu_to_le16(sizeof(struct iwm_umac_fw_cmd_hdr) +
le16_to_cpu(umac_cmd->count));
memcpy(&cmd->udma_cmd, udma_cmd, sizeof(*udma_cmd));
memcpy(&cmd->umac_cmd, umac_cmd, sizeof(*umac_cmd));
}
void iwm_cmd_flush(struct iwm_priv *iwm)
{
struct iwm_wifi_cmd *wcmd, *wnext;
struct iwm_nonwifi_cmd *nwcmd, *nwnext;
list_for_each_entry_safe(wcmd, wnext, &iwm->wifi_pending_cmd, pending) {
list_del(&wcmd->pending);
kfree(wcmd);
}
list_for_each_entry_safe(nwcmd, nwnext, &iwm->nonwifi_pending_cmd,
pending) {
list_del(&nwcmd->pending);
kfree(nwcmd);
}
}
struct iwm_wifi_cmd *iwm_get_pending_wifi_cmd(struct iwm_priv *iwm, u16 seq_num)
{
struct iwm_wifi_cmd *cmd;
list_for_each_entry(cmd, &iwm->wifi_pending_cmd, pending)
if (cmd->seq_num == seq_num) {
list_del(&cmd->pending);
return cmd;
}
return NULL;
}
struct iwm_nonwifi_cmd *iwm_get_pending_nonwifi_cmd(struct iwm_priv *iwm,
u8 seq_num, u8 cmd_opcode)
{
struct iwm_nonwifi_cmd *cmd;
list_for_each_entry(cmd, &iwm->nonwifi_pending_cmd, pending)
if ((cmd->seq_num == seq_num) &&
(cmd->udma_cmd.opcode == cmd_opcode) &&
(cmd->resp_received)) {
list_del(&cmd->pending);
return cmd;
}
return NULL;
}
static void iwm_build_udma_nonwifi_hdr(struct iwm_priv *iwm,
struct iwm_udma_out_nonwifi_hdr *hdr,
struct iwm_udma_nonwifi_cmd *cmd)
{
memset(hdr, 0, sizeof(*hdr));
SET_VAL32(hdr->cmd, UMAC_HDI_OUT_CMD_OPCODE, cmd->opcode);
SET_VAL32(hdr->cmd, UDMA_HDI_OUT_NW_CMD_RESP, cmd->resp);
SET_VAL32(hdr->cmd, UMAC_HDI_OUT_CMD_EOT, 1);
SET_VAL32(hdr->cmd, UDMA_HDI_OUT_NW_CMD_HANDLE_BY_HW,
cmd->handle_by_hw);
SET_VAL32(hdr->cmd, UMAC_HDI_OUT_CMD_SIGNATURE, UMAC_HDI_OUT_SIGNATURE);
SET_VAL32(hdr->cmd, UDMA_HDI_OUT_CMD_NON_WIFI_HW_SEQ_NUM,
le16_to_cpu(cmd->seq_num));
hdr->addr = cmd->addr;
hdr->op1_sz = cmd->op1_sz;
hdr->op2 = cmd->op2;
}
static int iwm_send_udma_nonwifi_cmd(struct iwm_priv *iwm,
struct iwm_nonwifi_cmd *cmd)
{
struct iwm_udma_out_nonwifi_hdr *udma_hdr;
struct iwm_nonwifi_cmd_buff *buf;
struct iwm_udma_nonwifi_cmd *udma_cmd = &cmd->udma_cmd;
buf = &cmd->buf;
buf->start -= sizeof(struct iwm_umac_nonwifi_out_hdr);
buf->len += sizeof(struct iwm_umac_nonwifi_out_hdr);
udma_hdr = (struct iwm_udma_out_nonwifi_hdr *)(buf->start);
iwm_build_udma_nonwifi_hdr(iwm, udma_hdr, udma_cmd);
IWM_DBG_CMD(iwm, DBG,
"Send UDMA nonwifi cmd: opcode = 0x%x, resp = 0x%x, "
"hw = 0x%x, seqnum = %d, addr = 0x%x, op1_sz = 0x%x, "
"op2 = 0x%x\n", udma_cmd->opcode, udma_cmd->resp,
udma_cmd->handle_by_hw, cmd->seq_num, udma_cmd->addr,
udma_cmd->op1_sz, udma_cmd->op2);
trace_iwm_tx_nonwifi_cmd(iwm, udma_hdr);
return iwm_bus_send_chunk(iwm, buf->start, buf->len);
}
void iwm_udma_wifi_hdr_set_eop(struct iwm_priv *iwm, u8 *buf, u8 eop)
{
struct iwm_udma_out_wifi_hdr *hdr = (struct iwm_udma_out_wifi_hdr *)buf;
SET_VAL32(hdr->cmd, UMAC_HDI_OUT_CMD_EOT, eop);
}
void iwm_build_udma_wifi_hdr(struct iwm_priv *iwm,
struct iwm_udma_out_wifi_hdr *hdr,
struct iwm_udma_wifi_cmd *cmd)
{
memset(hdr, 0, sizeof(*hdr));
SET_VAL32(hdr->cmd, UMAC_HDI_OUT_CMD_OPCODE, UMAC_HDI_OUT_OPCODE_WIFI);
SET_VAL32(hdr->cmd, UMAC_HDI_OUT_CMD_EOT, cmd->eop);
SET_VAL32(hdr->cmd, UMAC_HDI_OUT_CMD_SIGNATURE, UMAC_HDI_OUT_SIGNATURE);
SET_VAL32(hdr->meta_data, UMAC_HDI_OUT_BYTE_COUNT,
le16_to_cpu(cmd->count));
SET_VAL32(hdr->meta_data, UMAC_HDI_OUT_CREDIT_GRP, cmd->credit_group);
SET_VAL32(hdr->meta_data, UMAC_HDI_OUT_RATID, cmd->ra_tid);
SET_VAL32(hdr->meta_data, UMAC_HDI_OUT_LMAC_OFFSET, cmd->lmac_offset);
}
void iwm_build_umac_hdr(struct iwm_priv *iwm,
struct iwm_umac_fw_cmd_hdr *hdr,
struct iwm_umac_cmd *cmd)
{
memset(hdr, 0, sizeof(*hdr));
SET_VAL32(hdr->meta_data, UMAC_FW_CMD_BYTE_COUNT,
le16_to_cpu(cmd->count));
SET_VAL32(hdr->meta_data, UMAC_FW_CMD_TX_STA_COLOR, cmd->color);
SET_VAL8(hdr->cmd.flags, UMAC_DEV_CMD_FLAGS_RESP_REQ, cmd->resp);
hdr->cmd.cmd = cmd->id;
hdr->cmd.seq_num = cmd->seq_num;
}
static int iwm_send_udma_wifi_cmd(struct iwm_priv *iwm,
struct iwm_wifi_cmd *cmd)
{
struct iwm_umac_wifi_out_hdr *umac_hdr;
struct iwm_wifi_cmd_buff *buf;
struct iwm_udma_wifi_cmd *udma_cmd = &cmd->udma_cmd;
struct iwm_umac_cmd *umac_cmd = &cmd->umac_cmd;
int ret;
buf = &cmd->buf;
buf->start -= sizeof(struct iwm_umac_wifi_out_hdr);
buf->len += sizeof(struct iwm_umac_wifi_out_hdr);
umac_hdr = (struct iwm_umac_wifi_out_hdr *)(buf->start);
iwm_build_udma_wifi_hdr(iwm, &umac_hdr->hw_hdr, udma_cmd);
iwm_build_umac_hdr(iwm, &umac_hdr->sw_hdr, umac_cmd);
IWM_DBG_CMD(iwm, DBG,
"Send UDMA wifi cmd: opcode = 0x%x, UMAC opcode = 0x%x, "
"eop = 0x%x, count = 0x%x, credit_group = 0x%x, "
"ra_tid = 0x%x, lmac_offset = 0x%x, seqnum = %d\n",
UMAC_HDI_OUT_OPCODE_WIFI, umac_cmd->id,
udma_cmd->eop, udma_cmd->count, udma_cmd->credit_group,
udma_cmd->ra_tid, udma_cmd->lmac_offset, cmd->seq_num);
if (umac_cmd->id == UMAC_CMD_OPCODE_WIFI_PASS_THROUGH)
IWM_DBG_CMD(iwm, DBG, "\tLMAC opcode: 0x%x\n",
cmd->lmac_cmd.id);
ret = iwm_tx_credit_alloc(iwm, udma_cmd->credit_group, buf->len);
if (ret && (umac_cmd->id != UMAC_CMD_OPCODE_RESET)) {
IWM_DBG_TX(iwm, DBG, "Failed to alloc tx credit for cmd %d\n",
umac_cmd->id);
return ret;
}
trace_iwm_tx_wifi_cmd(iwm, umac_hdr);
return iwm_bus_send_chunk(iwm, buf->start, buf->len);
}
int iwm_hal_send_target_cmd(struct iwm_priv *iwm,
struct iwm_udma_nonwifi_cmd *udma_cmd,
const void *payload)
{
struct iwm_nonwifi_cmd *cmd;
int ret, seq_num;
cmd = kzalloc(sizeof(struct iwm_nonwifi_cmd), GFP_KERNEL);
if (!cmd) {
IWM_ERR(iwm, "Couldn't alloc memory for hal cmd\n");
return -ENOMEM;
}
seq_num = iwm_nonwifi_cmd_init(iwm, cmd, udma_cmd);
if (cmd->udma_cmd.opcode == UMAC_HDI_OUT_OPCODE_WRITE ||
cmd->udma_cmd.opcode == UMAC_HDI_OUT_OPCODE_WRITE_PERSISTENT) {
cmd->buf.len = le32_to_cpu(cmd->udma_cmd.op1_sz);
memcpy(&cmd->buf.payload, payload, cmd->buf.len);
}
ret = iwm_send_udma_nonwifi_cmd(iwm, cmd);
if (!udma_cmd->resp)
kfree(cmd);
if (ret < 0)
return ret;
return seq_num;
}
static void iwm_build_lmac_hdr(struct iwm_priv *iwm, struct iwm_lmac_hdr *hdr,
struct iwm_lmac_cmd *cmd)
{
memset(hdr, 0, sizeof(*hdr));
hdr->id = cmd->id;
hdr->flags = 0;
hdr->seq_num = cmd->seq_num;
}
int iwm_hal_send_host_cmd(struct iwm_priv *iwm,
struct iwm_udma_wifi_cmd *udma_cmd,
struct iwm_umac_cmd *umac_cmd,
struct iwm_lmac_cmd *lmac_cmd,
const void *payload, u16 payload_size)
{
struct iwm_wifi_cmd *cmd;
struct iwm_lmac_hdr *hdr;
int lmac_hdr_len = 0;
int ret;
cmd = kzalloc(sizeof(struct iwm_wifi_cmd), GFP_KERNEL);
if (!cmd) {
IWM_ERR(iwm, "Couldn't alloc memory for wifi hal cmd\n");
return -ENOMEM;
}
iwm_wifi_cmd_init(iwm, cmd, udma_cmd, umac_cmd, lmac_cmd, payload_size);
if (lmac_cmd) {
hdr = (struct iwm_lmac_hdr *)(cmd->buf.start);
iwm_build_lmac_hdr(iwm, hdr, &cmd->lmac_cmd);
lmac_hdr_len = sizeof(struct iwm_lmac_hdr);
}
memcpy(cmd->buf.payload, payload, payload_size);
cmd->buf.len = le16_to_cpu(umac_cmd->count);
ret = iwm_send_udma_wifi_cmd(iwm, cmd);
if (!umac_cmd->resp)
kfree(cmd);
return ret;
}
int iwm_hal_send_umac_cmd(struct iwm_priv *iwm,
struct iwm_udma_wifi_cmd *udma_cmd,
struct iwm_umac_cmd *umac_cmd,
const void *payload, u16 payload_size)
{
return iwm_hal_send_host_cmd(iwm, udma_cmd, umac_cmd, NULL,
payload, payload_size);
}
