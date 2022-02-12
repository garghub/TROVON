int nfc_mei_phy_enable(void *phy_id)
{
int r;
struct nfc_mei_phy *phy = phy_id;
pr_info("%s\n", __func__);
if (phy->powered == 1)
return 0;
r = mei_cl_enable_device(phy->device);
if (r < 0) {
pr_err("Could not enable device\n");
return r;
}
r = mei_cl_register_event_cb(phy->device, nfc_mei_event_cb, phy);
if (r) {
pr_err("Event cb registration failed\n");
mei_cl_disable_device(phy->device);
phy->powered = 0;
return r;
}
phy->powered = 1;
return 0;
}
void nfc_mei_phy_disable(void *phy_id)
{
struct nfc_mei_phy *phy = phy_id;
pr_info("%s\n", __func__);
mei_cl_disable_device(phy->device);
phy->powered = 0;
}
static int nfc_mei_phy_write(void *phy_id, struct sk_buff *skb)
{
struct nfc_mei_phy *phy = phy_id;
int r;
MEI_DUMP_SKB_OUT("mei frame sent", skb);
r = mei_cl_send(phy->device, skb->data, skb->len);
if (r > 0)
r = 0;
return r;
}
void nfc_mei_event_cb(struct mei_cl_device *device, u32 events, void *context)
{
struct nfc_mei_phy *phy = context;
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
struct nfc_mei_phy *nfc_mei_phy_alloc(struct mei_cl_device *device)
{
struct nfc_mei_phy *phy;
phy = kzalloc(sizeof(struct nfc_mei_phy), GFP_KERNEL);
if (!phy)
return NULL;
phy->device = device;
mei_cl_set_drvdata(device, phy);
return phy;
}
void nfc_mei_phy_free(struct nfc_mei_phy *phy)
{
kfree(phy);
}
