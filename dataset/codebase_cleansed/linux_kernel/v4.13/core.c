static int nxp_nci_open(struct nci_dev *ndev)
{
struct nxp_nci_info *info = nci_get_drvdata(ndev);
int r = 0;
mutex_lock(&info->info_lock);
if (info->mode != NXP_NCI_MODE_COLD) {
r = -EBUSY;
goto open_exit;
}
if (info->phy_ops->set_mode)
r = info->phy_ops->set_mode(info->phy_id, NXP_NCI_MODE_NCI);
info->mode = NXP_NCI_MODE_NCI;
open_exit:
mutex_unlock(&info->info_lock);
return r;
}
static int nxp_nci_close(struct nci_dev *ndev)
{
struct nxp_nci_info *info = nci_get_drvdata(ndev);
int r = 0;
mutex_lock(&info->info_lock);
if (info->phy_ops->set_mode)
r = info->phy_ops->set_mode(info->phy_id, NXP_NCI_MODE_COLD);
info->mode = NXP_NCI_MODE_COLD;
mutex_unlock(&info->info_lock);
return r;
}
static int nxp_nci_send(struct nci_dev *ndev, struct sk_buff *skb)
{
struct nxp_nci_info *info = nci_get_drvdata(ndev);
int r;
if (!info->phy_ops->write) {
r = -ENOTSUPP;
goto send_exit;
}
if (info->mode != NXP_NCI_MODE_NCI) {
r = -EINVAL;
goto send_exit;
}
r = info->phy_ops->write(info->phy_id, skb);
if (r < 0)
kfree_skb(skb);
send_exit:
return r;
}
int nxp_nci_probe(void *phy_id, struct device *pdev,
const struct nxp_nci_phy_ops *phy_ops,
unsigned int max_payload,
struct nci_dev **ndev)
{
struct nxp_nci_info *info;
int r;
info = devm_kzalloc(pdev, sizeof(struct nxp_nci_info), GFP_KERNEL);
if (!info) {
r = -ENOMEM;
goto probe_exit;
}
info->phy_id = phy_id;
info->pdev = pdev;
info->phy_ops = phy_ops;
info->max_payload = max_payload;
INIT_WORK(&info->fw_info.work, nxp_nci_fw_work);
init_completion(&info->fw_info.cmd_completion);
mutex_init(&info->info_lock);
if (info->phy_ops->set_mode) {
r = info->phy_ops->set_mode(info->phy_id, NXP_NCI_MODE_COLD);
if (r < 0)
goto probe_exit;
}
info->mode = NXP_NCI_MODE_COLD;
info->ndev = nci_allocate_device(&nxp_nci_ops, NXP_NCI_NFC_PROTOCOLS,
NXP_NCI_HDR_LEN, 0);
if (!info->ndev) {
r = -ENOMEM;
goto probe_exit;
}
nci_set_parent_dev(info->ndev, pdev);
nci_set_drvdata(info->ndev, info);
r = nci_register_device(info->ndev);
if (r < 0)
goto probe_exit_free_nci;
*ndev = info->ndev;
goto probe_exit;
probe_exit_free_nci:
nci_free_device(info->ndev);
probe_exit:
return r;
}
void nxp_nci_remove(struct nci_dev *ndev)
{
struct nxp_nci_info *info = nci_get_drvdata(ndev);
if (info->mode == NXP_NCI_MODE_FW)
nxp_nci_fw_work_complete(info, -ESHUTDOWN);
cancel_work_sync(&info->fw_info.work);
mutex_lock(&info->info_lock);
if (info->phy_ops->set_mode)
info->phy_ops->set_mode(info->phy_id, NXP_NCI_MODE_COLD);
nci_unregister_device(ndev);
nci_free_device(ndev);
mutex_unlock(&info->info_lock);
}
