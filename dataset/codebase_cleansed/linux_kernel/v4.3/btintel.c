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
void btintel_hw_error(struct hci_dev *hdev, u8 code)
{
struct sk_buff *skb;
u8 type = 0x00;
BT_ERR("%s: Hardware error 0x%2.2x", hdev->name, code);
skb = __hci_cmd_sync(hdev, HCI_OP_RESET, 0, NULL, HCI_INIT_TIMEOUT);
if (IS_ERR(skb)) {
BT_ERR("%s: Reset after hardware error failed (%ld)",
hdev->name, PTR_ERR(skb));
return;
}
kfree_skb(skb);
skb = __hci_cmd_sync(hdev, 0xfc22, 1, &type, HCI_INIT_TIMEOUT);
if (IS_ERR(skb)) {
BT_ERR("%s: Retrieving Intel exception info failed (%ld)",
hdev->name, PTR_ERR(skb));
return;
}
if (skb->len != 13) {
BT_ERR("%s: Exception info size mismatch", hdev->name);
kfree_skb(skb);
return;
}
BT_ERR("%s: Exception info %s", hdev->name, (char *)(skb->data + 1));
kfree_skb(skb);
}
void btintel_version_info(struct hci_dev *hdev, struct intel_version *ver)
{
const char *variant;
switch (ver->fw_variant) {
case 0x06:
variant = "Bootloader";
break;
case 0x23:
variant = "Firmware";
break;
default:
return;
}
BT_INFO("%s: %s revision %u.%u build %u week %u %u", hdev->name,
variant, ver->fw_revision >> 4, ver->fw_revision & 0x0f,
ver->fw_build_num, ver->fw_build_ww, 2000 + ver->fw_build_yy);
}
int btintel_secure_send(struct hci_dev *hdev, u8 fragment_type, u32 plen,
const void *param)
{
while (plen > 0) {
struct sk_buff *skb;
u8 cmd_param[253], fragment_len = (plen > 252) ? 252 : plen;
cmd_param[0] = fragment_type;
memcpy(cmd_param + 1, param, fragment_len);
skb = __hci_cmd_sync(hdev, 0xfc09, fragment_len + 1,
cmd_param, HCI_INIT_TIMEOUT);
if (IS_ERR(skb))
return PTR_ERR(skb);
kfree_skb(skb);
plen -= fragment_len;
param += fragment_len;
}
return 0;
}
