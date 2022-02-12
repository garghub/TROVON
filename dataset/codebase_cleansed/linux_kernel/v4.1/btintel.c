int btintel_check_bdaddr(struct hci_dev *hdev)
{
struct hci_rp_read_bd_addr *bda;
struct sk_buff *skb;
skb = __hci_cmd_sync(hdev, HCI_OP_READ_BD_ADDR, 0, NULL,
HCI_INIT_TIMEOUT);
if (IS_ERR(skb)) {
int err = PTR_ERR(skb);
BT_ERR("%s: Reading Intel device address failed (%d)",
hdev->name, err);
return err;
}
if (skb->len != sizeof(*bda)) {
BT_ERR("%s: Intel device address length mismatch", hdev->name);
kfree_skb(skb);
return -EIO;
}
bda = (struct hci_rp_read_bd_addr *)skb->data;
if (bda->status) {
BT_ERR("%s: Intel device address result failed (%02x)",
hdev->name, bda->status);
kfree_skb(skb);
return -bt_to_errno(bda->status);
}
if (!bacmp(&bda->bdaddr, BDADDR_INTEL)) {
BT_ERR("%s: Found Intel default device address (%pMR)",
hdev->name, &bda->bdaddr);
set_bit(HCI_QUIRK_INVALID_BDADDR, &hdev->quirks);
}
kfree_skb(skb);
return 0;
}
int btintel_set_bdaddr(struct hci_dev *hdev, const bdaddr_t *bdaddr)
{
struct sk_buff *skb;
int err;
skb = __hci_cmd_sync(hdev, 0xfc31, 6, bdaddr, HCI_INIT_TIMEOUT);
if (IS_ERR(skb)) {
err = PTR_ERR(skb);
BT_ERR("%s: Changing Intel device address failed (%d)",
hdev->name, err);
return err;
}
kfree_skb(skb);
return 0;
}
