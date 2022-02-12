static u8 st21nfca_se_get_bwi(struct nfc_hci_dev *hdev)
{
int i;
u8 td;
struct st21nfca_hci_info *info = nfc_hci_get_clientdata(hdev);
for (i = 1; i < ST21NFCA_ESE_MAX_LENGTH; i++) {
td = ST21NFCA_ATR_GET_Y_FROM_TD(info->se_info.atr[i]);
if (ST21NFCA_ATR_TA_PRESENT(td))
i++;
if (ST21NFCA_ATR_TB_PRESENT(td)) {
i++;
return info->se_info.atr[i] >> 4;
}
}
return ST21NFCA_ATR_DEFAULT_BWI;
}
static void st21nfca_se_get_atr(struct nfc_hci_dev *hdev)
{
int r;
struct sk_buff *skb;
struct st21nfca_hci_info *info = nfc_hci_get_clientdata(hdev);
r = nfc_hci_get_param(hdev, ST21NFCA_APDU_READER_GATE,
ST21NFCA_PARAM_ATR, &skb);
if (r < 0)
return;
if (skb->len <= ST21NFCA_ESE_MAX_LENGTH) {
memcpy(info->se_info.atr, skb->data, skb->len);
info->se_info.wt_timeout =
ST21NFCA_BWI_TO_TIMEOUT(st21nfca_se_get_bwi(hdev));
}
kfree_skb(skb);
}
static int st21nfca_hci_control_se(struct nfc_hci_dev *hdev, u32 se_idx,
u8 state)
{
struct st21nfca_hci_info *info = nfc_hci_get_clientdata(hdev);
int r;
struct sk_buff *sk_host_list;
u8 se_event, host_id;
switch (se_idx) {
case NFC_HCI_UICC_HOST_ID:
se_event = (state == ST21NFCA_SE_MODE_ON ?
ST21NFCA_EVT_UICC_ACTIVATE :
ST21NFCA_EVT_UICC_DEACTIVATE);
info->se_info.count_pipes = 0;
info->se_info.expected_pipes = ST21NFCA_SE_COUNT_PIPE_UICC;
break;
case ST21NFCA_ESE_HOST_ID:
se_event = (state == ST21NFCA_SE_MODE_ON ?
ST21NFCA_EVT_SE_ACTIVATE :
ST21NFCA_EVT_SE_DEACTIVATE);
info->se_info.count_pipes = 0;
info->se_info.expected_pipes = ST21NFCA_SE_COUNT_PIPE_EMBEDDED;
break;
default:
return -EINVAL;
}
reinit_completion(&info->se_info.req_completion);
r = nfc_hci_send_event(hdev, ST21NFCA_DEVICE_MGNT_GATE, se_event,
NULL, 0);
if (r < 0)
return r;
mod_timer(&info->se_info.se_active_timer, jiffies +
msecs_to_jiffies(ST21NFCA_SE_TO_HOT_PLUG));
info->se_info.se_active = true;
wait_for_completion_interruptible(&info->se_info.req_completion);
r = nfc_hci_get_param(hdev, NFC_HCI_ADMIN_GATE,
NFC_HCI_ADMIN_HOST_LIST,
&sk_host_list);
if (r < 0)
return r;
host_id = sk_host_list->data[sk_host_list->len - 1];
kfree_skb(sk_host_list);
if (state == ST21NFCA_SE_MODE_ON && host_id == se_idx)
return se_idx;
else if (state == ST21NFCA_SE_MODE_OFF && host_id != se_idx)
return se_idx;
return -1;
}
int st21nfca_hci_discover_se(struct nfc_hci_dev *hdev)
{
struct st21nfca_hci_info *info = nfc_hci_get_clientdata(hdev);
int se_count = 0;
if (info->se_status->is_uicc_present) {
nfc_add_se(hdev->ndev, NFC_HCI_UICC_HOST_ID, NFC_SE_UICC);
se_count++;
}
if (info->se_status->is_ese_present) {
nfc_add_se(hdev->ndev, ST21NFCA_ESE_HOST_ID, NFC_SE_EMBEDDED);
se_count++;
}
return !se_count;
}
int st21nfca_hci_enable_se(struct nfc_hci_dev *hdev, u32 se_idx)
{
int r;
r = st21nfca_hci_control_se(hdev, se_idx, ST21NFCA_SE_MODE_ON);
if (r == ST21NFCA_ESE_HOST_ID) {
st21nfca_se_get_atr(hdev);
r = nfc_hci_send_event(hdev, ST21NFCA_APDU_READER_GATE,
ST21NFCA_EVT_SE_SOFT_RESET, NULL, 0);
if (r < 0)
return r;
} else if (r < 0) {
nfc_remove_se(hdev->ndev, se_idx);
return r;
}
return 0;
}
int st21nfca_hci_disable_se(struct nfc_hci_dev *hdev, u32 se_idx)
{
int r;
r = st21nfca_hci_control_se(hdev, se_idx, ST21NFCA_SE_MODE_OFF);
if (r < 0)
return r;
return 0;
}
int st21nfca_hci_se_io(struct nfc_hci_dev *hdev, u32 se_idx,
u8 *apdu, size_t apdu_length,
se_io_cb_t cb, void *cb_context)
{
struct st21nfca_hci_info *info = nfc_hci_get_clientdata(hdev);
pr_debug("se_io %x\n", se_idx);
switch (se_idx) {
case ST21NFCA_ESE_HOST_ID:
info->se_info.cb = cb;
info->se_info.cb_context = cb_context;
mod_timer(&info->se_info.bwi_timer, jiffies +
msecs_to_jiffies(info->se_info.wt_timeout));
info->se_info.bwi_active = true;
return nfc_hci_send_event(hdev, ST21NFCA_APDU_READER_GATE,
ST21NFCA_EVT_TRANSMIT_DATA,
apdu, apdu_length);
default:
return -ENODEV;
}
}
static void st21nfca_se_wt_timeout(unsigned long data)
{
u8 param = 0x01;
struct st21nfca_hci_info *info = (struct st21nfca_hci_info *) data;
pr_debug("\n");
info->se_info.bwi_active = false;
if (!info->se_info.xch_error) {
info->se_info.xch_error = true;
nfc_hci_send_event(info->hdev, ST21NFCA_APDU_READER_GATE,
ST21NFCA_EVT_SE_SOFT_RESET, NULL, 0);
} else {
info->se_info.xch_error = false;
nfc_hci_send_event(info->hdev, ST21NFCA_DEVICE_MGNT_GATE,
ST21NFCA_EVT_SE_HARD_RESET, &param, 1);
}
info->se_info.cb(info->se_info.cb_context, NULL, 0, -ETIME);
}
static void st21nfca_se_activation_timeout(unsigned long data)
{
struct st21nfca_hci_info *info = (struct st21nfca_hci_info *) data;
pr_debug("\n");
info->se_info.se_active = false;
complete(&info->se_info.req_completion);
}
int st21nfca_connectivity_event_received(struct nfc_hci_dev *hdev, u8 host,
u8 event, struct sk_buff *skb)
{
int r = 0;
struct device *dev = &hdev->ndev->dev;
struct nfc_evt_transaction *transaction;
pr_debug("connectivity gate event: %x\n", event);
switch (event) {
case ST21NFCA_EVT_CONNECTIVITY:
break;
case ST21NFCA_EVT_TRANSACTION:
if (skb->len < NFC_MIN_AID_LENGTH + 2 &&
skb->data[0] != NFC_EVT_TRANSACTION_AID_TAG)
return -EPROTO;
transaction = (struct nfc_evt_transaction *)devm_kzalloc(dev,
skb->len - 2, GFP_KERNEL);
transaction->aid_len = skb->data[1];
memcpy(transaction->aid, &skb->data[2], skb->data[1]);
if (skb->data[transaction->aid_len + 2] !=
NFC_EVT_TRANSACTION_PARAMS_TAG)
return -EPROTO;
transaction->params_len = skb->data[transaction->aid_len + 3];
memcpy(transaction->params, skb->data +
transaction->aid_len + 4, transaction->params_len);
r = nfc_se_transaction(hdev->ndev, host, transaction);
break;
default:
return 1;
}
kfree_skb(skb);
return r;
}
int st21nfca_apdu_reader_event_received(struct nfc_hci_dev *hdev,
u8 event, struct sk_buff *skb)
{
int r = 0;
struct st21nfca_hci_info *info = nfc_hci_get_clientdata(hdev);
pr_debug("apdu reader gate event: %x\n", event);
switch (event) {
case ST21NFCA_EVT_TRANSMIT_DATA:
del_timer_sync(&info->se_info.bwi_timer);
info->se_info.bwi_active = false;
r = nfc_hci_send_event(hdev, ST21NFCA_DEVICE_MGNT_GATE,
ST21NFCA_EVT_SE_END_OF_APDU_TRANSFER, NULL, 0);
if (r < 0)
goto exit;
info->se_info.cb(info->se_info.cb_context,
skb->data, skb->len, 0);
break;
case ST21NFCA_EVT_WTX_REQUEST:
mod_timer(&info->se_info.bwi_timer, jiffies +
msecs_to_jiffies(info->se_info.wt_timeout));
break;
}
exit:
kfree_skb(skb);
return r;
}
void st21nfca_se_init(struct nfc_hci_dev *hdev)
{
struct st21nfca_hci_info *info = nfc_hci_get_clientdata(hdev);
init_completion(&info->se_info.req_completion);
init_timer(&info->se_info.bwi_timer);
info->se_info.bwi_timer.data = (unsigned long)info;
info->se_info.bwi_timer.function = st21nfca_se_wt_timeout;
info->se_info.bwi_active = false;
init_timer(&info->se_info.se_active_timer);
info->se_info.se_active_timer.data = (unsigned long)info;
info->se_info.se_active_timer.function = st21nfca_se_activation_timeout;
info->se_info.se_active = false;
info->se_info.count_pipes = 0;
info->se_info.expected_pipes = 0;
info->se_info.xch_error = false;
info->se_info.wt_timeout =
ST21NFCA_BWI_TO_TIMEOUT(ST21NFCA_ATR_DEFAULT_BWI);
}
void st21nfca_se_deinit(struct nfc_hci_dev *hdev)
{
struct st21nfca_hci_info *info = nfc_hci_get_clientdata(hdev);
if (info->se_info.bwi_active)
del_timer_sync(&info->se_info.bwi_timer);
if (info->se_info.se_active)
del_timer_sync(&info->se_info.se_active_timer);
info->se_info.bwi_active = false;
info->se_info.se_active = false;
}
