static int microread_mei_probe(struct mei_cl_device *device,
const struct mei_cl_device_id *id)
{
struct nfc_mei_phy *phy;
int r;
pr_info("Probing NFC microread\n");
phy = nfc_mei_phy_alloc(device);
if (!phy) {
pr_err("Cannot allocate memory for microread mei phy.\n");
return -ENOMEM;
}
r = microread_probe(phy, &mei_phy_ops, LLC_NOP_NAME,
MEI_NFC_HEADER_SIZE, 0, MEI_NFC_MAX_HCI_PAYLOAD,
&phy->hdev);
if (r < 0) {
nfc_mei_phy_free(phy);
return r;
}
return 0;
}
static int microread_mei_remove(struct mei_cl_device *device)
{
struct nfc_mei_phy *phy = mei_cl_get_drvdata(device);
pr_info("Removing microread\n");
microread_remove(phy->hdev);
nfc_mei_phy_free(phy);
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
