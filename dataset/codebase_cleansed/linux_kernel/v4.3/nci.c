static int s3fwrn5_nci_prop_rsp(struct nci_dev *ndev, struct sk_buff *skb)
{
__u8 status = skb->data[0];
nci_req_complete(ndev, status);
return 0;
}
void s3fwrn5_nci_get_prop_ops(struct nci_prop_ops **ops, size_t *n)
{
*ops = s3fwrn5_nci_prop_ops;
*n = ARRAY_SIZE(s3fwrn5_nci_prop_ops);
}
int s3fwrn5_nci_rf_configure(struct s3fwrn5_info *info, const char *fw_name)
{
const struct firmware *fw;
struct nci_prop_fw_cfg_cmd fw_cfg;
struct nci_prop_set_rfreg_cmd set_rfreg;
struct nci_prop_stop_rfreg_cmd stop_rfreg;
u32 checksum;
int i, len;
int ret;
ret = request_firmware(&fw, fw_name, &info->ndev->nfc_dev->dev);
if (ret < 0)
return ret;
checksum = 0;
for (i = 0; i < fw->size; i += 4)
checksum += *((u32 *)(fw->data+i));
fw_cfg.clk_type = 0x01;
fw_cfg.clk_speed = 0xff;
fw_cfg.clk_req = 0xff;
ret = nci_prop_cmd(info->ndev, NCI_PROP_FW_CFG,
sizeof(fw_cfg), (__u8 *)&fw_cfg);
if (ret < 0)
goto out;
dev_info(&info->ndev->nfc_dev->dev,
"rfreg configuration update: %s\n", fw_name);
ret = nci_prop_cmd(info->ndev, NCI_PROP_START_RFREG, 0, NULL);
if (ret < 0) {
dev_err(&info->ndev->nfc_dev->dev,
"Unable to start rfreg update\n");
goto out;
}
set_rfreg.index = 0;
for (i = 0; i < fw->size; i += S3FWRN5_RFREG_SECTION_SIZE) {
len = (fw->size - i < S3FWRN5_RFREG_SECTION_SIZE) ?
(fw->size - i) : S3FWRN5_RFREG_SECTION_SIZE;
memcpy(set_rfreg.data, fw->data+i, len);
ret = nci_prop_cmd(info->ndev, NCI_PROP_SET_RFREG,
len+1, (__u8 *)&set_rfreg);
if (ret < 0) {
dev_err(&info->ndev->nfc_dev->dev,
"rfreg update error (code=%d)\n", ret);
goto out;
}
set_rfreg.index++;
}
stop_rfreg.checksum = checksum & 0xffff;
ret = nci_prop_cmd(info->ndev, NCI_PROP_STOP_RFREG,
sizeof(stop_rfreg), (__u8 *)&stop_rfreg);
if (ret < 0) {
dev_err(&info->ndev->nfc_dev->dev,
"Unable to stop rfreg update\n");
goto out;
}
dev_info(&info->ndev->nfc_dev->dev,
"rfreg configuration update: success\n");
out:
release_firmware(fw);
return ret;
}
