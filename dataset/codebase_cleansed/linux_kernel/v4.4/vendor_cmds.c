static int st_nci_factory_mode(struct nfc_dev *dev, void *data,
size_t data_len)
{
struct nci_dev *ndev = nfc_get_drvdata(dev);
struct st_nci_info *info = nci_get_drvdata(ndev);
if (data_len != 1)
return -EINVAL;
pr_debug("factory mode: %x\n", ((u8 *)data)[0]);
switch (((u8 *)data)[0]) {
case ST_NCI_FACTORY_MODE_ON:
test_and_set_bit(ST_NCI_FACTORY_MODE, &info->flags);
break;
case ST_NCI_FACTORY_MODE_OFF:
clear_bit(ST_NCI_FACTORY_MODE, &info->flags);
break;
default:
return -EINVAL;
}
return 0;
}
static int st_nci_hci_clear_all_pipes(struct nfc_dev *dev, void *data,
size_t data_len)
{
struct nci_dev *ndev = nfc_get_drvdata(dev);
return nci_hci_clear_all_pipes(ndev);
}
static int st_nci_hci_dm_put_data(struct nfc_dev *dev, void *data,
size_t data_len)
{
struct nci_dev *ndev = nfc_get_drvdata(dev);
return nci_hci_send_cmd(ndev, ST_NCI_DEVICE_MGNT_GATE,
ST_NCI_HCI_DM_PUTDATA, data,
data_len, NULL);
}
static int st_nci_hci_dm_update_aid(struct nfc_dev *dev, void *data,
size_t data_len)
{
struct nci_dev *ndev = nfc_get_drvdata(dev);
return nci_hci_send_cmd(ndev, ST_NCI_DEVICE_MGNT_GATE,
ST_NCI_HCI_DM_UPDATE_AID, data, data_len, NULL);
}
static int st_nci_hci_dm_get_info(struct nfc_dev *dev, void *data,
size_t data_len)
{
int r;
struct sk_buff *msg, *skb;
struct nci_dev *ndev = nfc_get_drvdata(dev);
r = nci_hci_send_cmd(ndev, ST_NCI_DEVICE_MGNT_GATE, ST_NCI_HCI_DM_GETINFO,
data, data_len, &skb);
if (r)
goto exit;
msg = nfc_vendor_cmd_alloc_reply_skb(dev, ST_NCI_VENDOR_OUI,
HCI_DM_GET_INFO, skb->len);
if (!msg) {
r = -ENOMEM;
goto free_skb;
}
if (nla_put(msg, NFC_ATTR_VENDOR_DATA, skb->len, skb->data)) {
kfree_skb(msg);
r = -ENOBUFS;
goto free_skb;
}
r = nfc_vendor_cmd_reply(msg);
free_skb:
kfree_skb(skb);
exit:
return r;
}
static int st_nci_hci_dm_get_data(struct nfc_dev *dev, void *data,
size_t data_len)
{
int r;
struct sk_buff *msg, *skb;
struct nci_dev *ndev = nfc_get_drvdata(dev);
r = nci_hci_send_cmd(ndev, ST_NCI_DEVICE_MGNT_GATE, ST_NCI_HCI_DM_GETDATA,
data, data_len, &skb);
if (r)
goto exit;
msg = nfc_vendor_cmd_alloc_reply_skb(dev, ST_NCI_VENDOR_OUI,
HCI_DM_GET_DATA, skb->len);
if (!msg) {
r = -ENOMEM;
goto free_skb;
}
if (nla_put(msg, NFC_ATTR_VENDOR_DATA, skb->len, skb->data)) {
kfree_skb(msg);
r = -ENOBUFS;
goto free_skb;
}
r = nfc_vendor_cmd_reply(msg);
free_skb:
kfree_skb(skb);
exit:
return r;
}
static int st_nci_hci_dm_fwupd_start(struct nfc_dev *dev, void *data,
size_t data_len)
{
int r;
struct nci_dev *ndev = nfc_get_drvdata(dev);
dev->fw_download_in_progress = true;
r = nci_hci_send_cmd(ndev, ST_NCI_DEVICE_MGNT_GATE,
ST_NCI_HCI_DM_FWUPD_START, data, data_len, NULL);
if (r)
dev->fw_download_in_progress = false;
return r;
}
static int st_nci_hci_dm_fwupd_end(struct nfc_dev *dev, void *data,
size_t data_len)
{
struct nci_dev *ndev = nfc_get_drvdata(dev);
return nci_hci_send_cmd(ndev, ST_NCI_DEVICE_MGNT_GATE,
ST_NCI_HCI_DM_FWUPD_STOP, data, data_len, NULL);
}
static int st_nci_hci_dm_direct_load(struct nfc_dev *dev, void *data,
size_t data_len)
{
struct nci_dev *ndev = nfc_get_drvdata(dev);
if (dev->fw_download_in_progress) {
dev->fw_download_in_progress = false;
return nci_hci_send_cmd(ndev, ST_NCI_DEVICE_MGNT_GATE,
ST_NCI_HCI_DM_LOAD, data, data_len, NULL);
}
return -EPROTO;
}
static int st_nci_hci_dm_reset(struct nfc_dev *dev, void *data,
size_t data_len)
{
struct nci_dev *ndev = nfc_get_drvdata(dev);
nci_hci_send_cmd(ndev, ST_NCI_DEVICE_MGNT_GATE,
ST_NCI_HCI_DM_RESET, data, data_len, NULL);
msleep(200);
return 0;
}
static int st_nci_hci_get_param(struct nfc_dev *dev, void *data,
size_t data_len)
{
int r;
struct sk_buff *msg, *skb;
struct nci_dev *ndev = nfc_get_drvdata(dev);
struct get_param_data *param = (struct get_param_data *)data;
if (data_len < sizeof(struct get_param_data))
return -EPROTO;
r = nci_hci_get_param(ndev, param->gate, param->data, &skb);
if (r)
goto exit;
msg = nfc_vendor_cmd_alloc_reply_skb(dev, ST_NCI_VENDOR_OUI,
HCI_GET_PARAM, skb->len);
if (!msg) {
r = -ENOMEM;
goto free_skb;
}
if (nla_put(msg, NFC_ATTR_VENDOR_DATA, skb->len, skb->data)) {
kfree_skb(msg);
r = -ENOBUFS;
goto free_skb;
}
r = nfc_vendor_cmd_reply(msg);
free_skb:
kfree_skb(skb);
exit:
return r;
}
static int st_nci_hci_dm_field_generator(struct nfc_dev *dev, void *data,
size_t data_len)
{
struct nci_dev *ndev = nfc_get_drvdata(dev);
return nci_hci_send_cmd(ndev, ST_NCI_DEVICE_MGNT_GATE,
ST_NCI_HCI_DM_FIELD_GENERATOR, data, data_len, NULL);
}
static int st_nci_hci_dm_vdc_measurement_value(struct nfc_dev *dev, void *data,
size_t data_len)
{
int r;
struct sk_buff *msg, *skb;
struct nci_dev *ndev = nfc_get_drvdata(dev);
if (data_len != 4)
return -EPROTO;
r = nci_hci_send_cmd(ndev, ST_NCI_DEVICE_MGNT_GATE,
ST_NCI_HCI_DM_VDC_MEASUREMENT_VALUE,
data, data_len, &skb);
if (r)
goto exit;
msg = nfc_vendor_cmd_alloc_reply_skb(dev, ST_NCI_VENDOR_OUI,
HCI_DM_VDC_MEASUREMENT_VALUE, skb->len);
if (!msg) {
r = -ENOMEM;
goto free_skb;
}
if (nla_put(msg, NFC_ATTR_VENDOR_DATA, skb->len, skb->data)) {
kfree_skb(msg);
r = -ENOBUFS;
goto free_skb;
}
r = nfc_vendor_cmd_reply(msg);
free_skb:
kfree_skb(skb);
exit:
return r;
}
static int st_nci_hci_dm_vdc_value_comparison(struct nfc_dev *dev, void *data,
size_t data_len)
{
int r;
struct sk_buff *msg, *skb;
struct nci_dev *ndev = nfc_get_drvdata(dev);
if (data_len != 2)
return -EPROTO;
r = nci_hci_send_cmd(ndev, ST_NCI_DEVICE_MGNT_GATE,
ST_NCI_HCI_DM_VDC_VALUE_COMPARISON,
data, data_len, &skb);
if (r)
goto exit;
msg = nfc_vendor_cmd_alloc_reply_skb(dev, ST_NCI_VENDOR_OUI,
HCI_DM_VDC_VALUE_COMPARISON, skb->len);
if (!msg) {
r = -ENOMEM;
goto free_skb;
}
if (nla_put(msg, NFC_ATTR_VENDOR_DATA, skb->len, skb->data)) {
kfree_skb(msg);
r = -ENOBUFS;
goto free_skb;
}
r = nfc_vendor_cmd_reply(msg);
free_skb:
kfree_skb(skb);
exit:
return r;
}
void st_nci_hci_loopback_event_received(struct nci_dev *ndev, u8 event,
struct sk_buff *skb)
{
struct st_nci_info *info = nci_get_drvdata(ndev);
switch (event) {
case ST_NCI_EVT_POST_DATA:
info->vendor_info.rx_skb = skb;
break;
default:
nfc_err(&ndev->nfc_dev->dev, "Unexpected event on loopback gate\n");
}
complete(&info->vendor_info.req_completion);
}
static int st_nci_hci_loopback(struct nfc_dev *dev, void *data,
size_t data_len)
{
int r;
struct sk_buff *msg;
struct nci_dev *ndev = nfc_get_drvdata(dev);
struct st_nci_info *info = nci_get_drvdata(ndev);
if (data_len <= 0)
return -EPROTO;
reinit_completion(&info->vendor_info.req_completion);
info->vendor_info.rx_skb = NULL;
r = nci_hci_send_event(ndev, NCI_HCI_LOOPBACK_GATE,
ST_NCI_EVT_POST_DATA, data, data_len);
if (r != data_len) {
r = -EPROTO;
goto exit;
}
wait_for_completion_interruptible(&info->vendor_info.req_completion);
if (!info->vendor_info.rx_skb ||
info->vendor_info.rx_skb->len != data_len) {
r = -EPROTO;
goto exit;
}
msg = nfc_vendor_cmd_alloc_reply_skb(ndev->nfc_dev,
ST_NCI_VENDOR_OUI,
HCI_LOOPBACK,
info->vendor_info.rx_skb->len);
if (!msg) {
r = -ENOMEM;
goto free_skb;
}
if (nla_put(msg, NFC_ATTR_VENDOR_DATA, info->vendor_info.rx_skb->len,
info->vendor_info.rx_skb->data)) {
kfree_skb(msg);
r = -ENOBUFS;
goto free_skb;
}
r = nfc_vendor_cmd_reply(msg);
free_skb:
kfree_skb(info->vendor_info.rx_skb);
exit:
return r;
}
static int st_nci_manufacturer_specific(struct nfc_dev *dev, void *data,
size_t data_len)
{
struct sk_buff *msg;
struct nci_dev *ndev = nfc_get_drvdata(dev);
msg = nfc_vendor_cmd_alloc_reply_skb(dev, ST_NCI_VENDOR_OUI,
MANUFACTURER_SPECIFIC,
sizeof(ndev->manufact_specific_info));
if (!msg)
return -ENOMEM;
if (nla_put(msg, NFC_ATTR_VENDOR_DATA, sizeof(ndev->manufact_specific_info),
&ndev->manufact_specific_info)) {
kfree_skb(msg);
return -ENOBUFS;
}
return nfc_vendor_cmd_reply(msg);
}
int st_nci_vendor_cmds_init(struct nci_dev *ndev)
{
struct st_nci_info *info = nci_get_drvdata(ndev);
init_completion(&info->vendor_info.req_completion);
return nfc_set_vendor_cmds(ndev->nfc_dev, st_nci_vendor_cmds,
sizeof(st_nci_vendor_cmds));
}
