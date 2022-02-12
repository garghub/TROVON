static int st21nfca_hci_load_session(struct nfc_hci_dev *hdev)
{
int i, j, r;
struct sk_buff *skb_pipe_list, *skb_pipe_info;
struct st21nfca_pipe_info *info;
u8 pipe_list[] = { ST21NFCA_DM_GETINFO_PIPE_LIST,
NFC_HCI_TERMINAL_HOST_ID
};
u8 pipe_info[] = { ST21NFCA_DM_GETINFO_PIPE_INFO,
NFC_HCI_TERMINAL_HOST_ID, 0
};
skb_pipe_list = alloc_skb(ST21NFCA_HCI_LLC_MAX_SIZE, GFP_KERNEL);
if (!skb_pipe_list) {
r = -ENOMEM;
goto free_list;
}
skb_pipe_info = alloc_skb(ST21NFCA_HCI_LLC_MAX_SIZE, GFP_KERNEL);
if (!skb_pipe_info) {
r = -ENOMEM;
goto free_info;
}
r = nfc_hci_connect_gate(hdev, NFC_HCI_HOST_CONTROLLER_ID,
ST21NFCA_DEVICE_MGNT_GATE, ST21NFCA_DEVICE_MGNT_PIPE);
if (r < 0)
goto free_info;
r = nfc_hci_send_cmd(hdev, ST21NFCA_DEVICE_MGNT_GATE,
ST21NFCA_DM_GETINFO, pipe_list, sizeof(pipe_list),
&skb_pipe_list);
if (r < 0)
goto free_info;
for (i = 0; i < skb_pipe_list->len; i++) {
pipe_info[2] = skb_pipe_list->data[i];
r = nfc_hci_send_cmd(hdev, ST21NFCA_DEVICE_MGNT_GATE,
ST21NFCA_DM_GETINFO, pipe_info,
sizeof(pipe_info), &skb_pipe_info);
if (r)
continue;
info = (struct st21nfca_pipe_info *) skb_pipe_info->data;
for (j = 0; (j < ARRAY_SIZE(st21nfca_gates)) &&
(st21nfca_gates[j].gate != info->dst_gate_id);
j++)
;
if (j < ARRAY_SIZE(st21nfca_gates) &&
st21nfca_gates[j].gate == info->dst_gate_id &&
ST21NFCA_DM_IS_PIPE_OPEN(info->pipe_state)) {
st21nfca_gates[j].pipe = pipe_info[2];
hdev->gate2pipe[st21nfca_gates[j].gate] =
st21nfca_gates[j].pipe;
}
}
if (skb_pipe_list->len + 3 < ARRAY_SIZE(st21nfca_gates)) {
for (i = skb_pipe_list->len + 3;
i < ARRAY_SIZE(st21nfca_gates); i++) {
r = nfc_hci_connect_gate(hdev,
NFC_HCI_HOST_CONTROLLER_ID,
st21nfca_gates[i].gate,
st21nfca_gates[i].pipe);
if (r < 0)
goto free_info;
}
}
memcpy(hdev->init_data.gates, st21nfca_gates, sizeof(st21nfca_gates));
free_info:
kfree_skb(skb_pipe_info);
free_list:
kfree_skb(skb_pipe_list);
return r;
}
static int st21nfca_hci_open(struct nfc_hci_dev *hdev)
{
struct st21nfca_hci_info *info = nfc_hci_get_clientdata(hdev);
int r;
mutex_lock(&info->info_lock);
if (info->state != ST21NFCA_ST_COLD) {
r = -EBUSY;
goto out;
}
r = info->phy_ops->enable(info->phy_id);
if (r == 0)
info->state = ST21NFCA_ST_READY;
out:
mutex_unlock(&info->info_lock);
return r;
}
static void st21nfca_hci_close(struct nfc_hci_dev *hdev)
{
struct st21nfca_hci_info *info = nfc_hci_get_clientdata(hdev);
mutex_lock(&info->info_lock);
if (info->state == ST21NFCA_ST_COLD)
goto out;
info->phy_ops->disable(info->phy_id);
info->state = ST21NFCA_ST_COLD;
out:
mutex_unlock(&info->info_lock);
}
static int st21nfca_hci_ready(struct nfc_hci_dev *hdev)
{
struct sk_buff *skb;
u8 param;
int r;
param = NFC_HCI_UICC_HOST_ID;
r = nfc_hci_set_param(hdev, NFC_HCI_ADMIN_GATE,
NFC_HCI_ADMIN_WHITELIST, &param, 1);
if (r < 0)
return r;
r = nfc_hci_get_param(hdev, ST21NFCA_DEVICE_MGNT_GATE,
ST21NFCA_NFC_MODE, &skb);
if (r < 0)
return r;
if (skb->data[0] == 0) {
kfree_skb(skb);
param = 1;
r = nfc_hci_set_param(hdev, ST21NFCA_DEVICE_MGNT_GATE,
ST21NFCA_NFC_MODE, &param, 1);
if (r < 0)
return r;
}
r = nfc_hci_send_event(hdev, NFC_HCI_RF_READER_A_GATE,
NFC_HCI_EVT_END_OPERATION, NULL, 0);
if (r < 0)
return r;
r = nfc_hci_get_param(hdev, NFC_HCI_ID_MGMT_GATE,
NFC_HCI_ID_MGMT_VERSION_SW, &skb);
if (r < 0)
return r;
if (skb->len != FULL_VERSION_LEN) {
kfree_skb(skb);
return -EINVAL;
}
print_hex_dump(KERN_DEBUG, "FULL VERSION SOFTWARE INFO: ",
DUMP_PREFIX_NONE, 16, 1,
skb->data, FULL_VERSION_LEN, false);
kfree_skb(skb);
return 0;
}
static int st21nfca_hci_xmit(struct nfc_hci_dev *hdev, struct sk_buff *skb)
{
struct st21nfca_hci_info *info = nfc_hci_get_clientdata(hdev);
return info->phy_ops->write(info->phy_id, skb);
}
static int st21nfca_hci_start_poll(struct nfc_hci_dev *hdev,
u32 im_protocols, u32 tm_protocols)
{
int r;
pr_info(DRIVER_DESC ": %s protocols 0x%x 0x%x\n",
__func__, im_protocols, tm_protocols);
r = nfc_hci_send_event(hdev, NFC_HCI_RF_READER_A_GATE,
NFC_HCI_EVT_END_OPERATION, NULL, 0);
if (r < 0)
return r;
if (im_protocols) {
if ((NFC_HCI_RF_READER_B_GATE & im_protocols) == 0) {
r = nfc_hci_disconnect_gate(hdev,
NFC_HCI_RF_READER_B_GATE);
if (r < 0)
return r;
}
if ((NFC_HCI_RF_READER_A_GATE & im_protocols) == 0) {
r = nfc_hci_disconnect_gate(hdev,
NFC_HCI_RF_READER_A_GATE);
if (r < 0)
return r;
}
if ((ST21NFCA_RF_READER_F_GATE & im_protocols) == 0) {
r = nfc_hci_disconnect_gate(hdev,
ST21NFCA_RF_READER_F_GATE);
if (r < 0)
return r;
}
if ((ST21NFCA_RF_READER_14443_3_A_GATE & im_protocols) == 0) {
r = nfc_hci_disconnect_gate(hdev,
ST21NFCA_RF_READER_14443_3_A_GATE);
if (r < 0)
return r;
}
if ((ST21NFCA_RF_READER_ISO15693_GATE & im_protocols) == 0) {
r = nfc_hci_disconnect_gate(hdev,
ST21NFCA_RF_READER_ISO15693_GATE);
if (r < 0)
return r;
}
r = nfc_hci_send_event(hdev, NFC_HCI_RF_READER_A_GATE,
NFC_HCI_EVT_READER_REQUESTED, NULL, 0);
if (r < 0)
nfc_hci_send_event(hdev, NFC_HCI_RF_READER_A_GATE,
NFC_HCI_EVT_END_OPERATION, NULL, 0);
}
return r;
}
static int st21nfca_get_iso14443_3_atqa(struct nfc_hci_dev *hdev, u16 *atqa)
{
int r;
struct sk_buff *atqa_skb = NULL;
r = nfc_hci_get_param(hdev, ST21NFCA_RF_READER_14443_3_A_GATE,
ST21NFCA_RF_READER_14443_3_A_ATQA, &atqa_skb);
if (r < 0)
goto exit;
if (atqa_skb->len != 2) {
r = -EPROTO;
goto exit;
}
*atqa = be16_to_cpu(*(__be16 *) atqa_skb->data);
exit:
kfree_skb(atqa_skb);
return r;
}
static int st21nfca_get_iso14443_3_sak(struct nfc_hci_dev *hdev, u8 *sak)
{
int r;
struct sk_buff *sak_skb = NULL;
r = nfc_hci_get_param(hdev, ST21NFCA_RF_READER_14443_3_A_GATE,
ST21NFCA_RF_READER_14443_3_A_SAK, &sak_skb);
if (r < 0)
goto exit;
if (sak_skb->len != 1) {
r = -EPROTO;
goto exit;
}
*sak = sak_skb->data[0];
exit:
kfree_skb(sak_skb);
return r;
}
static int st21nfca_get_iso14443_3_uid(struct nfc_hci_dev *hdev, u8 *gate,
int *len)
{
int r;
struct sk_buff *uid_skb = NULL;
r = nfc_hci_get_param(hdev, ST21NFCA_RF_READER_14443_3_A_GATE,
ST21NFCA_RF_READER_14443_3_A_UID, &uid_skb);
if (r < 0)
goto exit;
if (uid_skb->len == 0 || uid_skb->len > NFC_NFCID1_MAXSIZE) {
r = -EPROTO;
goto exit;
}
gate = uid_skb->data;
*len = uid_skb->len;
exit:
kfree_skb(uid_skb);
return r;
}
static int st21nfca_get_iso15693_inventory(struct nfc_hci_dev *hdev,
struct nfc_target *target)
{
int r;
struct sk_buff *inventory_skb = NULL;
r = nfc_hci_get_param(hdev, ST21NFCA_RF_READER_ISO15693_GATE,
ST21NFCA_RF_READER_ISO15693_INVENTORY,
&inventory_skb);
if (r < 0)
goto exit;
skb_pull(inventory_skb, 2);
if (inventory_skb->len == 0 ||
inventory_skb->len > NFC_ISO15693_UID_MAXSIZE) {
r = -EPROTO;
goto exit;
}
memcpy(target->iso15693_uid, inventory_skb->data, inventory_skb->len);
target->iso15693_dsfid = inventory_skb->data[1];
target->is_iso15693 = 1;
exit:
kfree_skb(inventory_skb);
return r;
}
static int st21nfca_hci_target_from_gate(struct nfc_hci_dev *hdev, u8 gate,
struct nfc_target *target)
{
int r, len;
u16 atqa;
u8 sak;
u8 uid[NFC_NFCID1_MAXSIZE];
switch (gate) {
case ST21NFCA_RF_READER_F_GATE:
target->supported_protocols = NFC_PROTO_FELICA_MASK;
break;
case ST21NFCA_RF_READER_14443_3_A_GATE:
r = st21nfca_get_iso14443_3_atqa(hdev, &atqa);
if (r < 0)
return r;
if (atqa == 0x000c) {
target->supported_protocols = NFC_PROTO_JEWEL_MASK;
target->sens_res = 0x0c00;
} else {
r = st21nfca_get_iso14443_3_sak(hdev, &sak);
if (r < 0)
return r;
r = st21nfca_get_iso14443_3_uid(hdev, uid, &len);
if (r < 0)
return r;
target->supported_protocols =
nfc_hci_sak_to_protocol(sak);
if (target->supported_protocols == 0xffffffff)
return -EPROTO;
target->sens_res = atqa;
target->sel_res = sak;
memcpy(target->nfcid1, uid, len);
target->nfcid1_len = len;
}
break;
case ST21NFCA_RF_READER_ISO15693_GATE:
target->supported_protocols = NFC_PROTO_ISO15693_MASK;
r = st21nfca_get_iso15693_inventory(hdev, target);
if (r < 0)
return r;
break;
default:
return -EPROTO;
}
return 0;
}
static void st21nfca_hci_data_exchange_cb(void *context, struct sk_buff *skb,
int err)
{
struct st21nfca_hci_info *info = context;
switch (info->async_cb_type) {
case ST21NFCA_CB_TYPE_READER_ISO15693:
if (err == 0)
skb_trim(skb, skb->len - 1);
info->async_cb(info->async_cb_context, skb, err);
break;
default:
if (err == 0)
kfree_skb(skb);
break;
}
}
static int st21nfca_hci_im_transceive(struct nfc_hci_dev *hdev,
struct nfc_target *target,
struct sk_buff *skb,
data_exchange_cb_t cb, void *cb_context)
{
struct st21nfca_hci_info *info = nfc_hci_get_clientdata(hdev);
pr_info(DRIVER_DESC ": %s for gate=%d len=%d\n", __func__,
target->hci_reader_gate, skb->len);
switch (target->hci_reader_gate) {
case ST21NFCA_RF_READER_F_GATE:
*skb_push(skb, 1) = 0x1a;
return nfc_hci_send_cmd_async(hdev, target->hci_reader_gate,
ST21NFCA_WR_XCHG_DATA, skb->data,
skb->len, cb, cb_context);
case ST21NFCA_RF_READER_14443_3_A_GATE:
*skb_push(skb, 1) = 0x1a;
return nfc_hci_send_cmd_async(hdev, target->hci_reader_gate,
ST21NFCA_WR_XCHG_DATA, skb->data,
skb->len, cb, cb_context);
case ST21NFCA_RF_READER_ISO15693_GATE:
info->async_cb_type = ST21NFCA_CB_TYPE_READER_ISO15693;
info->async_cb = cb;
info->async_cb_context = cb_context;
*skb_push(skb, 1) = 0x17;
return nfc_hci_send_cmd_async(hdev, target->hci_reader_gate,
ST21NFCA_WR_XCHG_DATA, skb->data,
skb->len,
st21nfca_hci_data_exchange_cb,
info);
break;
default:
return 1;
}
}
static int st21nfca_hci_check_presence(struct nfc_hci_dev *hdev,
struct nfc_target *target)
{
u8 fwi = 0x11;
switch (target->hci_reader_gate) {
case NFC_HCI_RF_READER_A_GATE:
case NFC_HCI_RF_READER_B_GATE:
return nfc_hci_send_cmd(hdev, target->hci_reader_gate,
ST21NFCA_WR_XCHG_DATA, &fwi, 1, NULL);
case ST21NFCA_RF_READER_14443_3_A_GATE:
return nfc_hci_send_cmd(hdev, target->hci_reader_gate,
ST21NFCA_RF_READER_CMD_PRESENCE_CHECK,
NULL, 0, NULL);
default:
return -EOPNOTSUPP;
}
}
int st21nfca_hci_probe(void *phy_id, struct nfc_phy_ops *phy_ops,
char *llc_name, int phy_headroom, int phy_tailroom,
int phy_payload, struct nfc_hci_dev **hdev)
{
struct st21nfca_hci_info *info;
int r = 0;
int dev_num;
u32 protocols;
struct nfc_hci_init_data init_data;
unsigned long quirks = 0;
info = kzalloc(sizeof(struct st21nfca_hci_info), GFP_KERNEL);
if (!info) {
r = -ENOMEM;
goto err_alloc_hdev;
}
info->phy_ops = phy_ops;
info->phy_id = phy_id;
info->state = ST21NFCA_ST_COLD;
mutex_init(&info->info_lock);
init_data.gate_count = ARRAY_SIZE(st21nfca_gates);
memcpy(init_data.gates, st21nfca_gates, sizeof(st21nfca_gates));
dev_num = find_first_zero_bit(dev_mask, ST21NFCA_NUM_DEVICES);
if (dev_num >= ST21NFCA_NUM_DEVICES)
goto err_alloc_hdev;
scnprintf(init_data.session_id, sizeof(init_data.session_id), "%s%2x",
"ST21AH", dev_num);
protocols = NFC_PROTO_JEWEL_MASK |
NFC_PROTO_MIFARE_MASK |
NFC_PROTO_FELICA_MASK |
NFC_PROTO_ISO14443_MASK |
NFC_PROTO_ISO14443_B_MASK |
NFC_PROTO_ISO15693_MASK;
set_bit(NFC_HCI_QUIRK_SHORT_CLEAR, &quirks);
info->hdev =
nfc_hci_allocate_device(&st21nfca_hci_ops, &init_data, quirks,
protocols, llc_name,
phy_headroom + ST21NFCA_CMDS_HEADROOM,
phy_tailroom, phy_payload);
if (!info->hdev) {
pr_err("Cannot allocate nfc hdev.\n");
r = -ENOMEM;
goto err_alloc_hdev;
}
nfc_hci_set_clientdata(info->hdev, info);
r = nfc_hci_register_device(info->hdev);
if (r)
goto err_regdev;
*hdev = info->hdev;
return 0;
err_regdev:
nfc_hci_free_device(info->hdev);
err_alloc_hdev:
kfree(info);
return r;
}
void st21nfca_hci_remove(struct nfc_hci_dev *hdev)
{
struct st21nfca_hci_info *info = nfc_hci_get_clientdata(hdev);
nfc_hci_unregister_device(hdev);
nfc_hci_free_device(hdev);
kfree(info);
}
