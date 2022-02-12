static void nfcwilink_register_complete(void *priv_data, char data)
{
struct nfcwilink *drv = priv_data;
nfc_dev_dbg(&drv->pdev->dev, "register_complete entry");
drv->st_register_cb_status = data;
complete(&drv->st_register_completed);
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
init_completion(&drv->st_register_completed);
drv->st_register_cb_status = -EINPROGRESS;
rc = st_register(&nfcwilink_proto);
if (rc < 0) {
if (rc == -EINPROGRESS) {
comp_ret = wait_for_completion_timeout(
&drv->st_register_completed,
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
if (!test_bit(NFCWILINK_RUNNING, &drv->flags))
return -EBUSY;
hdr.len = skb->len;
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
u32 protocols;
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
