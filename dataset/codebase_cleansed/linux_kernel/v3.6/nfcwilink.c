static inline struct sk_buff *nfcwilink_skb_alloc(unsigned int len, gfp_t how)
{
struct sk_buff *skb;
skb = alloc_skb(len + NFCWILINK_HDR_LEN, how);
if (skb)
skb_reserve(skb, NFCWILINK_HDR_LEN);
return skb;
}
static void nfcwilink_fw_download_receive(struct nfcwilink *drv,
struct sk_buff *skb)
{
struct nci_vs_nfcc_info_rsp *rsp = (void *)skb->data;
if ((skb->len > 3) && (rsp->gid == NCI_VS_NFCC_INFO_RSP_GID) &&
(rsp->oid == NCI_VS_NFCC_INFO_RSP_OID)) {
memcpy(&drv->nfcc_info, rsp,
sizeof(struct nci_vs_nfcc_info_rsp));
}
kfree_skb(skb);
complete(&drv->completed);
}
static int nfcwilink_get_bts_file_name(struct nfcwilink *drv, char *file_name)
{
struct nci_vs_nfcc_info_cmd *cmd;
struct sk_buff *skb;
unsigned long comp_ret;
int rc;
nfc_dev_dbg(&drv->pdev->dev, "get_bts_file_name entry");
skb = nfcwilink_skb_alloc(sizeof(struct nci_vs_nfcc_info_cmd),
GFP_KERNEL);
if (!skb) {
nfc_dev_err(&drv->pdev->dev,
"no memory for nci_vs_nfcc_info_cmd");
return -ENOMEM;
}
skb->dev = (void *)drv->ndev;
cmd = (struct nci_vs_nfcc_info_cmd *)
skb_put(skb, sizeof(struct nci_vs_nfcc_info_cmd));
cmd->gid = NCI_VS_NFCC_INFO_CMD_GID;
cmd->oid = NCI_VS_NFCC_INFO_CMD_OID;
cmd->plen = 0;
drv->nfcc_info.plen = 0;
rc = nfcwilink_send(skb);
if (rc)
return rc;
comp_ret = wait_for_completion_timeout(&drv->completed,
msecs_to_jiffies(NFCWILINK_CMD_TIMEOUT));
nfc_dev_dbg(&drv->pdev->dev, "wait_for_completion_timeout returned %ld",
comp_ret);
if (comp_ret == 0) {
nfc_dev_err(&drv->pdev->dev,
"timeout on wait_for_completion_timeout");
return -ETIMEDOUT;
}
nfc_dev_dbg(&drv->pdev->dev, "nci_vs_nfcc_info_rsp: plen %d, status %d",
drv->nfcc_info.plen,
drv->nfcc_info.status);
if ((drv->nfcc_info.plen != 5) || (drv->nfcc_info.status != 0)) {
nfc_dev_err(&drv->pdev->dev,
"invalid nci_vs_nfcc_info_rsp");
return -EINVAL;
}
snprintf(file_name, BTS_FILE_NAME_MAX_SIZE,
"TINfcInit_%d.%d.%d.%d.bts",
drv->nfcc_info.hw_id,
drv->nfcc_info.sw_ver_x,
drv->nfcc_info.sw_ver_z,
drv->nfcc_info.patch_id);
nfc_dev_info(&drv->pdev->dev, "nfcwilink FW file name: %s", file_name);
return 0;
}
static int nfcwilink_send_bts_cmd(struct nfcwilink *drv, __u8 *data, int len)
{
struct nfcwilink_hdr *hdr = (struct nfcwilink_hdr *)data;
struct sk_buff *skb;
unsigned long comp_ret;
int rc;
nfc_dev_dbg(&drv->pdev->dev, "send_bts_cmd entry");
if ((len <= sizeof(struct nfcwilink_hdr)) ||
(len > BTS_FILE_CMD_MAX_LEN) ||
(hdr->chnl != NFCWILINK_CHNL) ||
(hdr->opcode != NFCWILINK_OPCODE)) {
nfc_dev_err(&drv->pdev->dev,
"ignoring invalid bts cmd, len %d, chnl %d, opcode %d",
len, hdr->chnl, hdr->opcode);
return 0;
}
len -= sizeof(struct nfcwilink_hdr);
data += sizeof(struct nfcwilink_hdr);
skb = nfcwilink_skb_alloc(len, GFP_KERNEL);
if (!skb) {
nfc_dev_err(&drv->pdev->dev, "no memory for bts cmd");
return -ENOMEM;
}
skb->dev = (void *)drv->ndev;
memcpy(skb_put(skb, len), data, len);
rc = nfcwilink_send(skb);
if (rc)
return rc;
comp_ret = wait_for_completion_timeout(&drv->completed,
msecs_to_jiffies(NFCWILINK_CMD_TIMEOUT));
nfc_dev_dbg(&drv->pdev->dev, "wait_for_completion_timeout returned %ld",
comp_ret);
if (comp_ret == 0) {
nfc_dev_err(&drv->pdev->dev,
"timeout on wait_for_completion_timeout");
return -ETIMEDOUT;
}
return 0;
}
static int nfcwilink_download_fw(struct nfcwilink *drv)
{
unsigned char file_name[BTS_FILE_NAME_MAX_SIZE];
const struct firmware *fw;
__u16 action_type, action_len;
__u8 *ptr;
int len, rc;
nfc_dev_dbg(&drv->pdev->dev, "download_fw entry");
set_bit(NFCWILINK_FW_DOWNLOAD, &drv->flags);
rc = nfcwilink_get_bts_file_name(drv, file_name);
if (rc)
goto exit;
rc = request_firmware(&fw, file_name, &drv->pdev->dev);
if (rc) {
nfc_dev_err(&drv->pdev->dev, "request_firmware failed %d", rc);
if (rc == -ENOENT)
rc = 0;
goto exit;
}
len = fw->size;
ptr = (__u8 *)fw->data;
if ((len == 0) || (ptr == NULL)) {
nfc_dev_dbg(&drv->pdev->dev,
"request_firmware returned size %d", len);
goto release_fw;
}
if (__le32_to_cpu(((struct bts_file_hdr *)ptr)->magic) !=
BTS_FILE_HDR_MAGIC) {
nfc_dev_err(&drv->pdev->dev, "wrong bts magic number");
rc = -EINVAL;
goto release_fw;
}
len -= sizeof(struct bts_file_hdr);
ptr += sizeof(struct bts_file_hdr);
while (len > 0) {
action_type =
__le16_to_cpu(((struct bts_file_action *)ptr)->type);
action_len =
__le16_to_cpu(((struct bts_file_action *)ptr)->len);
nfc_dev_dbg(&drv->pdev->dev, "bts_file_action type %d, len %d",
action_type, action_len);
switch (action_type) {
case BTS_FILE_ACTION_TYPE_SEND_CMD:
rc = nfcwilink_send_bts_cmd(drv,
((struct bts_file_action *)ptr)->data,
action_len);
if (rc)
goto release_fw;
break;
}
len -= (sizeof(struct bts_file_action) + action_len);
ptr += (sizeof(struct bts_file_action) + action_len);
}
release_fw:
release_firmware(fw);
exit:
clear_bit(NFCWILINK_FW_DOWNLOAD, &drv->flags);
return rc;
}
static void nfcwilink_register_complete(void *priv_data, char data)
{
struct nfcwilink *drv = priv_data;
nfc_dev_dbg(&drv->pdev->dev, "register_complete entry");
drv->st_register_cb_status = data;
complete(&drv->completed);
}
static long nfcwilink_receive(void *priv_data, struct sk_buff *skb)
{
struct nfcwilink *drv = priv_data;
int rc;
nfc_dev_dbg(&drv->pdev->dev, "receive entry, len %d", skb->len);
if (!skb)
return -EFAULT;
if (!drv) {
kfree_skb(skb);
return -EFAULT;
}
skb_pull(skb, (NFCWILINK_HDR_LEN-1));
if (test_bit(NFCWILINK_FW_DOWNLOAD, &drv->flags)) {
nfcwilink_fw_download_receive(drv, skb);
return 0;
}
skb->dev = (void *) drv->ndev;
rc = nci_recv_frame(skb);
if (rc < 0) {
nfc_dev_err(&drv->pdev->dev, "nci_recv_frame failed %d", rc);
return rc;
}
return 0;
}
static int nfcwilink_open(struct nci_dev *ndev)
{
struct nfcwilink *drv = nci_get_drvdata(ndev);
unsigned long comp_ret;
int rc;
nfc_dev_dbg(&drv->pdev->dev, "open entry");
if (test_and_set_bit(NFCWILINK_RUNNING, &drv->flags)) {
rc = -EBUSY;
goto exit;
}
nfcwilink_proto.priv_data = drv;
init_completion(&drv->completed);
drv->st_register_cb_status = -EINPROGRESS;
rc = st_register(&nfcwilink_proto);
if (rc < 0) {
if (rc == -EINPROGRESS) {
comp_ret = wait_for_completion_timeout(
&drv->completed,
msecs_to_jiffies(NFCWILINK_REGISTER_TIMEOUT));
nfc_dev_dbg(&drv->pdev->dev,
"wait_for_completion_timeout returned %ld",
comp_ret);
if (comp_ret == 0) {
rc = -ETIMEDOUT;
goto clear_exit;
} else if (drv->st_register_cb_status != 0) {
rc = drv->st_register_cb_status;
nfc_dev_err(&drv->pdev->dev,
"st_register_cb failed %d", rc);
goto clear_exit;
}
} else {
nfc_dev_err(&drv->pdev->dev,
"st_register failed %d", rc);
goto clear_exit;
}
}
BUG_ON(nfcwilink_proto.write == NULL);
drv->st_write = nfcwilink_proto.write;
if (nfcwilink_download_fw(drv)) {
nfc_dev_err(&drv->pdev->dev, "nfcwilink_download_fw failed %d",
rc);
}
goto exit;
clear_exit:
clear_bit(NFCWILINK_RUNNING, &drv->flags);
exit:
return rc;
}
static int nfcwilink_close(struct nci_dev *ndev)
{
struct nfcwilink *drv = nci_get_drvdata(ndev);
int rc;
nfc_dev_dbg(&drv->pdev->dev, "close entry");
if (!test_and_clear_bit(NFCWILINK_RUNNING, &drv->flags))
return 0;
rc = st_unregister(&nfcwilink_proto);
if (rc)
nfc_dev_err(&drv->pdev->dev, "st_unregister failed %d", rc);
drv->st_write = NULL;
return rc;
}
static int nfcwilink_send(struct sk_buff *skb)
{
struct nci_dev *ndev = (struct nci_dev *)skb->dev;
struct nfcwilink *drv = nci_get_drvdata(ndev);
struct nfcwilink_hdr hdr = {NFCWILINK_CHNL, NFCWILINK_OPCODE, 0x0000};
long len;
nfc_dev_dbg(&drv->pdev->dev, "send entry, len %d", skb->len);
if (!test_bit(NFCWILINK_RUNNING, &drv->flags)) {
kfree_skb(skb);
return -EINVAL;
}
hdr.len = cpu_to_le16(skb->len);
memcpy(skb_push(skb, NFCWILINK_HDR_LEN), &hdr, NFCWILINK_HDR_LEN);
len = drv->st_write(skb);
if (len < 0) {
kfree_skb(skb);
nfc_dev_err(&drv->pdev->dev, "st_write failed %ld", len);
return -EFAULT;
}
return 0;
}
static int nfcwilink_probe(struct platform_device *pdev)
{
static struct nfcwilink *drv;
int rc;
__u32 protocols;
nfc_dev_dbg(&pdev->dev, "probe entry");
drv = kzalloc(sizeof(struct nfcwilink), GFP_KERNEL);
if (!drv) {
rc = -ENOMEM;
goto exit;
}
drv->pdev = pdev;
protocols = NFC_PROTO_JEWEL_MASK
| NFC_PROTO_MIFARE_MASK | NFC_PROTO_FELICA_MASK
| NFC_PROTO_ISO14443_MASK
| NFC_PROTO_ISO14443_B_MASK
| NFC_PROTO_NFC_DEP_MASK;
drv->ndev = nci_allocate_device(&nfcwilink_ops,
protocols,
NFCWILINK_HDR_LEN,
0);
if (!drv->ndev) {
nfc_dev_err(&pdev->dev, "nci_allocate_device failed");
rc = -ENOMEM;
goto free_exit;
}
nci_set_parent_dev(drv->ndev, &pdev->dev);
nci_set_drvdata(drv->ndev, drv);
rc = nci_register_device(drv->ndev);
if (rc < 0) {
nfc_dev_err(&pdev->dev, "nci_register_device failed %d", rc);
goto free_dev_exit;
}
dev_set_drvdata(&pdev->dev, drv);
goto exit;
free_dev_exit:
nci_free_device(drv->ndev);
free_exit:
kfree(drv);
exit:
return rc;
}
static int nfcwilink_remove(struct platform_device *pdev)
{
struct nfcwilink *drv = dev_get_drvdata(&pdev->dev);
struct nci_dev *ndev;
nfc_dev_dbg(&pdev->dev, "remove entry");
if (!drv)
return -EFAULT;
ndev = drv->ndev;
nci_unregister_device(ndev);
nci_free_device(ndev);
kfree(drv);
dev_set_drvdata(&pdev->dev, NULL);
return 0;
}
static int __init nfcwilink_init(void)
{
printk(KERN_INFO "NFC Driver for TI WiLink");
return platform_driver_register(&nfcwilink_driver);
}
static void __exit nfcwilink_exit(void)
{
platform_driver_unregister(&nfcwilink_driver);
}
