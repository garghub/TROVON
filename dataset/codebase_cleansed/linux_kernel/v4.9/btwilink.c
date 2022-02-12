static inline void ti_st_tx_complete(struct ti_st *hst, int pkt_type)
{
struct hci_dev *hdev = hst->hdev;
switch (pkt_type) {
case HCI_COMMAND_PKT:
hdev->stat.cmd_tx++;
break;
case HCI_ACLDATA_PKT:
hdev->stat.acl_tx++;
break;
case HCI_SCODATA_PKT:
hdev->stat.sco_tx++;
break;
}
}
static void st_reg_completion_cb(void *priv_data, int data)
{
struct ti_st *lhst = priv_data;
lhst->reg_status = data;
complete(&lhst->wait_reg_completion);
}
static long st_receive(void *priv_data, struct sk_buff *skb)
{
struct ti_st *lhst = priv_data;
int err;
if (!skb)
return -EFAULT;
if (!lhst) {
kfree_skb(skb);
return -EFAULT;
}
err = hci_recv_frame(lhst->hdev, skb);
if (err < 0) {
BT_ERR("Unable to push skb to HCI core(%d)", err);
return err;
}
lhst->hdev->stat.byte_rx += skb->len;
return 0;
}
static int ti_st_open(struct hci_dev *hdev)
{
unsigned long timeleft;
struct ti_st *hst;
int err, i;
BT_DBG("%s %p", hdev->name, hdev);
hst = hci_get_drvdata(hdev);
for (i = 0; i < MAX_BT_CHNL_IDS; i++) {
ti_st_proto[i].priv_data = hst;
ti_st_proto[i].max_frame_size = HCI_MAX_FRAME_SIZE;
ti_st_proto[i].recv = st_receive;
ti_st_proto[i].reg_complete_cb = st_reg_completion_cb;
init_completion(&hst->wait_reg_completion);
hst->reg_status = -EINPROGRESS;
err = st_register(&ti_st_proto[i]);
if (!err)
goto done;
if (err != -EINPROGRESS) {
BT_ERR("st_register failed %d", err);
return err;
}
BT_DBG("waiting for registration "
"completion signal from ST");
timeleft = wait_for_completion_timeout
(&hst->wait_reg_completion,
msecs_to_jiffies(BT_REGISTER_TIMEOUT));
if (!timeleft) {
BT_ERR("Timeout(%d sec),didn't get reg "
"completion signal from ST",
BT_REGISTER_TIMEOUT / 1000);
return -ETIMEDOUT;
}
if (hst->reg_status != 0) {
BT_ERR("ST registration completed with invalid "
"status %d", hst->reg_status);
return -EAGAIN;
}
done:
hst->st_write = ti_st_proto[i].write;
if (!hst->st_write) {
BT_ERR("undefined ST write function");
for (i = 0; i < MAX_BT_CHNL_IDS; i++) {
err = st_unregister(&ti_st_proto[i]);
if (err)
BT_ERR("st_unregister() failed with "
"error %d", err);
hst->st_write = NULL;
}
return -EIO;
}
}
return 0;
}
static int ti_st_close(struct hci_dev *hdev)
{
int err, i;
struct ti_st *hst = hci_get_drvdata(hdev);
for (i = MAX_BT_CHNL_IDS-1; i >= 0; i--) {
err = st_unregister(&ti_st_proto[i]);
if (err)
BT_ERR("st_unregister(%d) failed with error %d",
ti_st_proto[i].chnl_id, err);
}
hst->st_write = NULL;
return err;
}
static int ti_st_send_frame(struct hci_dev *hdev, struct sk_buff *skb)
{
struct ti_st *hst;
long len;
int pkt_type;
hst = hci_get_drvdata(hdev);
memcpy(skb_push(skb, 1), &hci_skb_pkt_type(skb), 1);
BT_DBG("%s: type %d len %d", hdev->name, hci_skb_pkt_type(skb),
skb->len);
pkt_type = hci_skb_pkt_type(skb);
len = hst->st_write(skb);
if (len < 0) {
kfree_skb(skb);
BT_ERR("ST write failed (%ld)", len);
return -EAGAIN;
}
hdev->stat.byte_tx += len;
ti_st_tx_complete(hst, pkt_type);
return 0;
}
static int bt_ti_probe(struct platform_device *pdev)
{
static struct ti_st *hst;
struct hci_dev *hdev;
int err;
hst = devm_kzalloc(&pdev->dev, sizeof(struct ti_st), GFP_KERNEL);
if (!hst)
return -ENOMEM;
hdev = hci_alloc_dev();
if (!hdev)
return -ENOMEM;
BT_DBG("hdev %p", hdev);
hst->hdev = hdev;
hdev->bus = HCI_UART;
hci_set_drvdata(hdev, hst);
hdev->open = ti_st_open;
hdev->close = ti_st_close;
hdev->flush = NULL;
hdev->send = ti_st_send_frame;
err = hci_register_dev(hdev);
if (err < 0) {
BT_ERR("Can't register HCI device error %d", err);
hci_free_dev(hdev);
return err;
}
BT_DBG("HCI device registered (hdev %p)", hdev);
dev_set_drvdata(&pdev->dev, hst);
return 0;
}
static int bt_ti_remove(struct platform_device *pdev)
{
struct hci_dev *hdev;
struct ti_st *hst = dev_get_drvdata(&pdev->dev);
if (!hst)
return -EFAULT;
BT_DBG("%s", hst->hdev->name);
hdev = hst->hdev;
ti_st_close(hdev);
hci_unregister_dev(hdev);
hci_free_dev(hdev);
dev_set_drvdata(&pdev->dev, NULL);
return 0;
}
