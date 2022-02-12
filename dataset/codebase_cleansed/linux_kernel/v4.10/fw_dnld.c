static struct sk_buff *alloc_lc_skb(struct nfcmrvl_private *priv, uint8_t plen)
{
struct sk_buff *skb;
struct nci_data_hdr *hdr;
skb = nci_skb_alloc(priv->ndev, (NCI_DATA_HDR_SIZE + plen), GFP_KERNEL);
if (!skb) {
pr_err("no memory for data\n");
return NULL;
}
hdr = (struct nci_data_hdr *) skb_put(skb, NCI_DATA_HDR_SIZE);
hdr->conn_id = NCI_CORE_LC_CONNID_PROP_FW_DL;
hdr->rfu = 0;
hdr->plen = plen;
nci_mt_set((__u8 *)hdr, NCI_MT_DATA_PKT);
nci_pbf_set((__u8 *)hdr, NCI_PBF_LAST);
return skb;
}
static void fw_dnld_over(struct nfcmrvl_private *priv, u32 error)
{
if (priv->fw_dnld.fw) {
release_firmware(priv->fw_dnld.fw);
priv->fw_dnld.fw = NULL;
priv->fw_dnld.header = NULL;
priv->fw_dnld.binary_config = NULL;
}
atomic_set(&priv->ndev->cmd_cnt, 0);
if (timer_pending(&priv->ndev->cmd_timer))
del_timer_sync(&priv->ndev->cmd_timer);
if (timer_pending(&priv->fw_dnld.timer))
del_timer_sync(&priv->fw_dnld.timer);
nfc_info(priv->dev, "FW loading over (%d)]\n", error);
if (error != 0) {
nfcmrvl_chip_halt(priv);
}
nfc_fw_download_done(priv->ndev->nfc_dev, priv->fw_dnld.name, error);
}
static void fw_dnld_timeout(unsigned long arg)
{
struct nfcmrvl_private *priv = (struct nfcmrvl_private *) arg;
nfc_err(priv->dev, "FW loading timeout");
priv->fw_dnld.state = STATE_RESET;
fw_dnld_over(priv, -ETIMEDOUT);
}
static int process_state_reset(struct nfcmrvl_private *priv,
struct sk_buff *skb)
{
if (sizeof(nci_pattern_core_reset_ntf) != skb->len ||
memcmp(skb->data, nci_pattern_core_reset_ntf,
sizeof(nci_pattern_core_reset_ntf)))
return -EINVAL;
nfc_info(priv->dev, "BootROM reset, start fw download\n");
priv->fw_dnld.state = STATE_INIT;
nci_send_cmd(priv->ndev, NCI_OP_CORE_INIT_CMD, 0, NULL);
return 0;
}
static int process_state_init(struct nfcmrvl_private *priv, struct sk_buff *skb)
{
struct nci_core_set_config_cmd cmd;
if (sizeof(nci_pattern_core_init_rsp) >= skb->len ||
memcmp(skb->data, nci_pattern_core_init_rsp,
sizeof(nci_pattern_core_init_rsp)))
return -EINVAL;
cmd.num_params = 1;
cmd.param.id = NFCMRVL_PROP_REF_CLOCK;
cmd.param.len = 4;
memcpy(cmd.param.val, &priv->fw_dnld.header->ref_clock, 4);
nci_send_cmd(priv->ndev, NCI_OP_CORE_SET_CONFIG_CMD, 3 + cmd.param.len,
&cmd);
priv->fw_dnld.state = STATE_SET_REF_CLOCK;
return 0;
}
static void create_lc(struct nfcmrvl_private *priv)
{
uint8_t param[2] = { NCI_CORE_LC_PROP_FW_DL, 0x0 };
priv->fw_dnld.state = STATE_OPEN_LC;
nci_send_cmd(priv->ndev, NCI_OP_CORE_CONN_CREATE_CMD, 2, param);
}
static int process_state_set_ref_clock(struct nfcmrvl_private *priv,
struct sk_buff *skb)
{
struct nci_core_set_config_cmd cmd;
if (sizeof(nci_pattern_core_set_config_rsp) != skb->len ||
memcmp(skb->data, nci_pattern_core_set_config_rsp, skb->len))
return -EINVAL;
cmd.num_params = 1;
cmd.param.id = NFCMRVL_PROP_SET_HI_CONFIG;
switch (priv->phy) {
case NFCMRVL_PHY_UART:
cmd.param.len = 5;
memcpy(cmd.param.val,
&priv->fw_dnld.binary_config->uart.baudrate,
4);
cmd.param.val[4] =
priv->fw_dnld.binary_config->uart.flow_control;
break;
case NFCMRVL_PHY_I2C:
cmd.param.len = 5;
memcpy(cmd.param.val,
&priv->fw_dnld.binary_config->i2c.clk,
4);
cmd.param.val[4] = 0;
break;
case NFCMRVL_PHY_SPI:
cmd.param.len = 5;
memcpy(cmd.param.val,
&priv->fw_dnld.binary_config->spi.clk,
4);
cmd.param.val[4] = 0;
break;
default:
create_lc(priv);
return 0;
}
priv->fw_dnld.state = STATE_SET_HI_CONFIG;
nci_send_cmd(priv->ndev, NCI_OP_CORE_SET_CONFIG_CMD, 3 + cmd.param.len,
&cmd);
return 0;
}
static int process_state_set_hi_config(struct nfcmrvl_private *priv,
struct sk_buff *skb)
{
if (sizeof(nci_pattern_core_set_config_rsp) != skb->len ||
memcmp(skb->data, nci_pattern_core_set_config_rsp, skb->len))
return -EINVAL;
create_lc(priv);
return 0;
}
static int process_state_open_lc(struct nfcmrvl_private *priv,
struct sk_buff *skb)
{
if (sizeof(nci_pattern_core_conn_create_rsp) >= skb->len ||
memcmp(skb->data, nci_pattern_core_conn_create_rsp,
sizeof(nci_pattern_core_conn_create_rsp)))
return -EINVAL;
priv->fw_dnld.state = STATE_FW_DNLD;
priv->fw_dnld.substate = SUBSTATE_WAIT_COMMAND;
priv->fw_dnld.offset = priv->fw_dnld.binary_config->offset;
return 0;
}
static int process_state_fw_dnld(struct nfcmrvl_private *priv,
struct sk_buff *skb)
{
uint16_t len;
uint16_t comp_len;
struct sk_buff *out_skb;
switch (priv->fw_dnld.substate) {
case SUBSTATE_WAIT_COMMAND:
skb_pull(skb, 3);
if (skb->data[0] != HELPER_CMD_PACKET_FORMAT || skb->len != 5) {
nfc_err(priv->dev, "bad command");
return -EINVAL;
}
skb_pull(skb, 1);
memcpy(&len, skb->data, 2);
skb_pull(skb, 2);
memcpy(&comp_len, skb->data, 2);
skb_pull(skb, 2);
len = get_unaligned_le16(&len);
comp_len = get_unaligned_le16(&comp_len);
if (((~len) & 0xFFFF) != comp_len) {
nfc_err(priv->dev, "bad len complement: %x %x %x",
len, comp_len, (~len & 0xFFFF));
out_skb = alloc_lc_skb(priv, 1);
if (!out_skb)
return -ENOMEM;
*skb_put(out_skb, 1) = 0xBF;
nci_send_frame(priv->ndev, out_skb);
priv->fw_dnld.substate = SUBSTATE_WAIT_NACK_CREDIT;
return 0;
}
priv->fw_dnld.chunk_len = len;
out_skb = alloc_lc_skb(priv, 1);
if (!out_skb)
return -ENOMEM;
*skb_put(out_skb, 1) = HELPER_ACK_PACKET_FORMAT;
nci_send_frame(priv->ndev, out_skb);
priv->fw_dnld.substate = SUBSTATE_WAIT_ACK_CREDIT;
break;
case SUBSTATE_WAIT_ACK_CREDIT:
if (sizeof(nci_pattern_core_conn_credits_ntf) != skb->len ||
memcmp(nci_pattern_core_conn_credits_ntf, skb->data,
skb->len)) {
nfc_err(priv->dev, "bad packet: waiting for credit");
return -EINVAL;
}
if (priv->fw_dnld.chunk_len == 0) {
uint8_t conn_id = NCI_CORE_LC_CONNID_PROP_FW_DL;
priv->fw_dnld.state = STATE_CLOSE_LC;
nci_send_cmd(priv->ndev, NCI_OP_CORE_CONN_CLOSE_CMD,
1, &conn_id);
} else {
out_skb = alloc_lc_skb(priv, priv->fw_dnld.chunk_len);
if (!out_skb)
return -ENOMEM;
memcpy(skb_put(out_skb, priv->fw_dnld.chunk_len),
((uint8_t *)priv->fw_dnld.fw->data) +
priv->fw_dnld.offset,
priv->fw_dnld.chunk_len);
nci_send_frame(priv->ndev, out_skb);
priv->fw_dnld.substate = SUBSTATE_WAIT_DATA_CREDIT;
}
break;
case SUBSTATE_WAIT_DATA_CREDIT:
if (sizeof(nci_pattern_core_conn_credits_ntf) != skb->len ||
memcmp(nci_pattern_core_conn_credits_ntf, skb->data,
skb->len)) {
nfc_err(priv->dev, "bad packet: waiting for credit");
return -EINVAL;
}
priv->fw_dnld.offset += priv->fw_dnld.chunk_len;
priv->fw_dnld.chunk_len = 0;
priv->fw_dnld.substate = SUBSTATE_WAIT_COMMAND;
break;
case SUBSTATE_WAIT_NACK_CREDIT:
if (sizeof(nci_pattern_core_conn_credits_ntf) != skb->len ||
memcmp(nci_pattern_core_conn_credits_ntf, skb->data,
skb->len)) {
nfc_err(priv->dev, "bad packet: waiting for credit");
return -EINVAL;
}
priv->fw_dnld.substate = SUBSTATE_WAIT_COMMAND;
break;
}
return 0;
}
static int process_state_close_lc(struct nfcmrvl_private *priv,
struct sk_buff *skb)
{
if (sizeof(nci_pattern_core_conn_close_rsp) != skb->len ||
memcmp(skb->data, nci_pattern_core_conn_close_rsp, skb->len))
return -EINVAL;
priv->fw_dnld.state = STATE_BOOT;
nci_send_cmd(priv->ndev, NCI_OP_PROPRIETARY_BOOT_CMD, 0, NULL);
return 0;
}
static int process_state_boot(struct nfcmrvl_private *priv, struct sk_buff *skb)
{
if (sizeof(nci_pattern_proprietary_boot_rsp) != skb->len ||
memcmp(skb->data, nci_pattern_proprietary_boot_rsp, skb->len))
return -EINVAL;
priv->if_ops->nci_update_config(priv,
&priv->fw_dnld.binary_config->config);
if (priv->fw_dnld.binary_config == &priv->fw_dnld.header->helper) {
priv->fw_dnld.state = STATE_RESET;
priv->fw_dnld.binary_config = &priv->fw_dnld.header->firmware;
nfc_info(priv->dev, "FW loading: helper loaded");
} else {
nfc_info(priv->dev, "FW loading: firmware loaded");
fw_dnld_over(priv, 0);
}
return 0;
}
static void fw_dnld_rx_work(struct work_struct *work)
{
int ret;
struct sk_buff *skb;
struct nfcmrvl_fw_dnld *fw_dnld = container_of(work,
struct nfcmrvl_fw_dnld,
rx_work);
struct nfcmrvl_private *priv = container_of(fw_dnld,
struct nfcmrvl_private,
fw_dnld);
while ((skb = skb_dequeue(&fw_dnld->rx_q))) {
nfc_send_to_raw_sock(priv->ndev->nfc_dev, skb,
RAW_PAYLOAD_NCI, NFC_DIRECTION_RX);
switch (fw_dnld->state) {
case STATE_RESET:
ret = process_state_reset(priv, skb);
break;
case STATE_INIT:
ret = process_state_init(priv, skb);
break;
case STATE_SET_REF_CLOCK:
ret = process_state_set_ref_clock(priv, skb);
break;
case STATE_SET_HI_CONFIG:
ret = process_state_set_hi_config(priv, skb);
break;
case STATE_OPEN_LC:
ret = process_state_open_lc(priv, skb);
break;
case STATE_FW_DNLD:
ret = process_state_fw_dnld(priv, skb);
break;
case STATE_CLOSE_LC:
ret = process_state_close_lc(priv, skb);
break;
case STATE_BOOT:
ret = process_state_boot(priv, skb);
break;
default:
ret = -EFAULT;
}
kfree_skb(skb);
if (ret != 0) {
nfc_err(priv->dev, "FW loading error");
fw_dnld_over(priv, ret);
break;
}
}
}
int nfcmrvl_fw_dnld_init(struct nfcmrvl_private *priv)
{
char name[32];
INIT_WORK(&priv->fw_dnld.rx_work, fw_dnld_rx_work);
snprintf(name, sizeof(name), "%s_nfcmrvl_fw_dnld_rx_wq",
dev_name(priv->dev));
priv->fw_dnld.rx_wq = create_singlethread_workqueue(name);
if (!priv->fw_dnld.rx_wq)
return -ENOMEM;
skb_queue_head_init(&priv->fw_dnld.rx_q);
return 0;
}
void nfcmrvl_fw_dnld_deinit(struct nfcmrvl_private *priv)
{
destroy_workqueue(priv->fw_dnld.rx_wq);
}
void nfcmrvl_fw_dnld_recv_frame(struct nfcmrvl_private *priv,
struct sk_buff *skb)
{
if (timer_pending(&priv->ndev->cmd_timer))
del_timer_sync(&priv->ndev->cmd_timer);
atomic_set(&priv->ndev->cmd_cnt, 1);
skb_queue_tail(&priv->fw_dnld.rx_q, skb);
queue_work(priv->fw_dnld.rx_wq, &priv->fw_dnld.rx_work);
}
void nfcmrvl_fw_dnld_abort(struct nfcmrvl_private *priv)
{
fw_dnld_over(priv, -EHOSTDOWN);
}
int nfcmrvl_fw_dnld_start(struct nci_dev *ndev, const char *firmware_name)
{
struct nfcmrvl_private *priv = nci_get_drvdata(ndev);
struct nfcmrvl_fw_dnld *fw_dnld = &priv->fw_dnld;
if (!priv->support_fw_dnld)
return -ENOTSUPP;
if (!firmware_name || !firmware_name[0])
return -EINVAL;
strcpy(fw_dnld->name, firmware_name);
if (request_firmware(&fw_dnld->fw, firmware_name, priv->dev) < 0) {
nfc_err(priv->dev, "failed to retrieve FW %s", firmware_name);
return -ENOENT;
}
fw_dnld->header = (const struct nfcmrvl_fw *) priv->fw_dnld.fw->data;
if (fw_dnld->header->magic != NFCMRVL_FW_MAGIC ||
fw_dnld->header->phy != priv->phy) {
nfc_err(priv->dev, "bad firmware binary %s magic=0x%x phy=%d",
firmware_name, fw_dnld->header->magic,
fw_dnld->header->phy);
release_firmware(fw_dnld->fw);
fw_dnld->header = NULL;
return -EINVAL;
}
if (fw_dnld->header->helper.offset != 0) {
nfc_info(priv->dev, "loading helper");
fw_dnld->binary_config = &fw_dnld->header->helper;
} else {
nfc_info(priv->dev, "loading firmware");
fw_dnld->binary_config = &fw_dnld->header->firmware;
}
setup_timer(&priv->fw_dnld.timer, fw_dnld_timeout,
(unsigned long) priv);
mod_timer(&priv->fw_dnld.timer,
jiffies + msecs_to_jiffies(FW_DNLD_TIMEOUT));
priv->if_ops->nci_update_config(priv,
&fw_dnld->header->bootrom.config);
atomic_set(&priv->ndev->cmd_cnt, 1);
priv->fw_dnld.state = STATE_RESET;
nfcmrvl_chip_reset(priv);
return 0;
}
