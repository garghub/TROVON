static int st21nfcb_nci_open(struct nci_dev *ndev)
{
struct st21nfcb_nci_info *info = nci_get_drvdata(ndev);
int r;
if (test_and_set_bit(ST21NFCB_NCI_RUNNING, &info->flags))
return 0;
r = ndlc_open(info->ndlc);
if (r)
clear_bit(ST21NFCB_NCI_RUNNING, &info->flags);
return r;
}
static int st21nfcb_nci_close(struct nci_dev *ndev)
{
struct st21nfcb_nci_info *info = nci_get_drvdata(ndev);
if (!test_and_clear_bit(ST21NFCB_NCI_RUNNING, &info->flags))
return 0;
ndlc_close(info->ndlc);
return 0;
}
static int st21nfcb_nci_send(struct nci_dev *ndev, struct sk_buff *skb)
{
struct st21nfcb_nci_info *info = nci_get_drvdata(ndev);
skb->dev = (void *)ndev;
if (!test_bit(ST21NFCB_NCI_RUNNING, &info->flags))
return -EBUSY;
return ndlc_send(info->ndlc, skb);
}
int st21nfcb_nci_probe(struct llt_ndlc *ndlc, int phy_headroom,
int phy_tailroom)
{
struct st21nfcb_nci_info *info;
int r;
u32 protocols;
info = devm_kzalloc(ndlc->dev,
sizeof(struct st21nfcb_nci_info), GFP_KERNEL);
if (!info)
return -ENOMEM;
protocols = NFC_PROTO_JEWEL_MASK
| NFC_PROTO_MIFARE_MASK
| NFC_PROTO_FELICA_MASK
| NFC_PROTO_ISO14443_MASK
| NFC_PROTO_ISO14443_B_MASK
| NFC_PROTO_NFC_DEP_MASK;
ndlc->ndev = nci_allocate_device(&st21nfcb_nci_ops, protocols,
phy_headroom, phy_tailroom);
if (!ndlc->ndev) {
pr_err("Cannot allocate nfc ndev\n");
r = -ENOMEM;
goto err_alloc_ndev;
}
info->ndlc = ndlc;
nci_set_drvdata(ndlc->ndev, info);
r = nci_register_device(ndlc->ndev);
if (r)
goto err_regdev;
return r;
err_regdev:
nci_free_device(ndlc->ndev);
err_alloc_ndev:
kfree(info);
return r;
}
void st21nfcb_nci_remove(struct nci_dev *ndev)
{
struct st21nfcb_nci_info *info = nci_get_drvdata(ndev);
nci_unregister_device(ndev);
nci_free_device(ndev);
kfree(info);
}
