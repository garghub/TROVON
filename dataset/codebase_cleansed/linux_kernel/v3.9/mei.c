static int microread_mei_enable(void *phy_id)
{
struct microread_mei_phy *phy = phy_id;
pr_info(DRIVER_DESC ": %s\n", __func__);
phy->powered = 1;
return 0;
}
static void microread_mei_disable(void *phy_id)
{
struct microread_mei_phy *phy = phy_id;
pr_info(DRIVER_DESC ": %s\n", __func__);
phy->powered = 0;
}
static int microread_mei_write(void *phy_id, struct sk_buff *skb)
{
struct microread_mei_phy *phy = phy_id;
int r;
MEI_DUMP_SKB_OUT("mei frame sent", skb);
r = mei_cl_send(phy->device, skb->data, skb->len);
if (r > 0)
r = 0;
return r;
}
static void microread_event_cb(struct mei_cl_device *device, u32 events,
void *context)
{
struct microread_mei_phy *phy = context;
if (phy->hard_fault != 0)
return;
if (events & BIT(MEI_CL_EVENT_RX)) {
struct sk_buff *skb;
int reply_size;
skb = alloc_skb(MEI_NFC_MAX_READ, GFP_KERNEL);
if (!skb)
return;
reply_size = mei_cl_recv(device, skb->data, MEI_NFC_MAX_READ);
if (reply_size < MEI_NFC_HEADER_SIZE) {
kfree(skb);
return;
}
skb_put(skb, reply_size);
skb_pull(skb, MEI_NFC_HEADER_SIZE);
MEI_DUMP_SKB_IN("mei frame read", skb);
nfc_hci_recv_frame(phy->hdev, skb);
}
}
static int microread_mei_probe(struct mei_cl_device *device,
const struct mei_cl_device_id *id)
{
struct microread_mei_phy *phy;
int r;
pr_info("Probing NFC microread\n");
phy = kzalloc(sizeof(struct microread_mei_phy), GFP_KERNEL);
if (!phy) {
pr_err("Cannot allocate memory for microread mei phy.\n");
return -ENOMEM;
}
phy->device = device;
mei_cl_set_drvdata(device, phy);
r = mei_cl_register_event_cb(device, microread_event_cb, phy);
if (r) {
pr_err(MICROREAD_DRIVER_NAME ": event cb registration failed\n");
goto err_out;
}
r = microread_probe(phy, &mei_phy_ops, LLC_NOP_NAME,
MEI_NFC_HEADER_SIZE, 0, MEI_NFC_MAX_HCI_PAYLOAD,
&phy->hdev);
if (r < 0)
goto err_out;
return 0;
err_out:
kfree(phy);
return r;
}
static int microread_mei_remove(struct mei_cl_device *device)
{
struct microread_mei_phy *phy = mei_cl_get_drvdata(device);
pr_info("Removing microread\n");
microread_remove(phy->hdev);
if (phy->powered)
microread_mei_disable(phy);
kfree(phy);
return 0;
}
static int microread_mei_init(void)
{
int r;
pr_debug(DRIVER_DESC ": %s\n", __func__);
r = mei_cl_driver_register(&microread_driver);
if (r) {
pr_err(MICROREAD_DRIVER_NAME ": driver registration failed\n");
return r;
}
return 0;
}
static void microread_mei_exit(void)
{
mei_cl_driver_unregister(&microread_driver);
}
