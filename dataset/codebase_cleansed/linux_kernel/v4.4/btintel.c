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
int btintel_set_diag(struct hci_dev *hdev, bool enable)
{
struct sk_buff *skb;
u8 param[3];
int err;
if (enable) {
param[0] = 0x03;
param[1] = 0x03;
param[2] = 0x03;
} else {
param[0] = 0x00;
param[1] = 0x00;
param[2] = 0x00;
}
skb = __hci_cmd_sync(hdev, 0xfc43, 3, param, HCI_INIT_TIMEOUT);
if (IS_ERR(skb)) {
err = PTR_ERR(skb);
if (err == -ENODATA)
goto done;
BT_ERR("%s: Changing Intel diagnostic mode failed (%d)",
hdev->name, err);
return err;
}
kfree_skb(skb);
done:
btintel_set_event_mask(hdev, enable);
return 0;
}
int btintel_set_diag_mfg(struct hci_dev *hdev, bool enable)
{
struct sk_buff *skb;
u8 param[2];
int err;
param[0] = 0x01;
param[1] = 0x00;
skb = __hci_cmd_sync(hdev, 0xfc11, 2, param, HCI_INIT_TIMEOUT);
if (IS_ERR(skb)) {
err = PTR_ERR(skb);
BT_ERR("%s: Entering Intel manufacturer mode failed (%d)",
hdev->name, err);
return PTR_ERR(skb);
}
kfree_skb(skb);
err = btintel_set_diag(hdev, enable);
param[0] = 0x00;
param[1] = 0x00;
skb = __hci_cmd_sync(hdev, 0xfc11, 2, param, HCI_INIT_TIMEOUT);
if (IS_ERR(skb)) {
err = PTR_ERR(skb);
BT_ERR("%s: Leaving Intel manufacturer mode failed (%d)",
hdev->name, err);
return PTR_ERR(skb);
}
kfree_skb(skb);
return err;
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
int btintel_load_ddc_config(struct hci_dev *hdev, const char *ddc_name)
{
const struct firmware *fw;
struct sk_buff *skb;
const u8 *fw_ptr;
int err;
err = request_firmware_direct(&fw, ddc_name, &hdev->dev);
if (err < 0) {
bt_dev_err(hdev, "Failed to load Intel DDC file %s (%d)",
ddc_name, err);
return err;
}
bt_dev_info(hdev, "Found Intel DDC parameters: %s", ddc_name);
fw_ptr = fw->data;
while (fw->size > fw_ptr - fw->data) {
u8 cmd_plen = fw_ptr[0] + sizeof(u8);
skb = __hci_cmd_sync(hdev, 0xfc8b, cmd_plen, fw_ptr,
HCI_INIT_TIMEOUT);
if (IS_ERR(skb)) {
bt_dev_err(hdev, "Failed to send Intel_Write_DDC (%ld)",
PTR_ERR(skb));
release_firmware(fw);
return PTR_ERR(skb);
}
fw_ptr += cmd_plen;
kfree_skb(skb);
}
release_firmware(fw);
bt_dev_info(hdev, "Applying Intel DDC parameters completed");
return 0;
}
int btintel_set_event_mask(struct hci_dev *hdev, bool debug)
{
u8 mask[8] = { 0x87, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
struct sk_buff *skb;
int err;
if (debug)
mask[1] |= 0x62;
skb = __hci_cmd_sync(hdev, 0xfc52, 8, mask, HCI_INIT_TIMEOUT);
if (IS_ERR(skb)) {
err = PTR_ERR(skb);
BT_ERR("%s: Setting Intel event mask failed (%d)",
hdev->name, err);
return err;
}
kfree_skb(skb);
return 0;
}
int btintel_set_event_mask_mfg(struct hci_dev *hdev, bool debug)
{
struct sk_buff *skb;
u8 param[2];
int err;
param[0] = 0x01;
param[1] = 0x00;
skb = __hci_cmd_sync(hdev, 0xfc11, 2, param, HCI_INIT_TIMEOUT);
if (IS_ERR(skb)) {
err = PTR_ERR(skb);
BT_ERR("%s: Entering Intel manufacturer mode failed (%d)",
hdev->name, err);
return PTR_ERR(skb);
}
kfree_skb(skb);
err = btintel_set_event_mask(hdev, debug);
param[0] = 0x00;
param[1] = 0x00;
skb = __hci_cmd_sync(hdev, 0xfc11, 2, param, HCI_INIT_TIMEOUT);
if (IS_ERR(skb)) {
err = PTR_ERR(skb);
BT_ERR("%s: Leaving Intel manufacturer mode failed (%d)",
hdev->name, err);
return PTR_ERR(skb);
}
kfree_skb(skb);
return err;
}
static int regmap_ibt_read(void *context, const void *addr, size_t reg_size,
void *val, size_t val_size)
{
struct regmap_ibt_context *ctx = context;
struct ibt_cp_reg_access cp;
struct ibt_rp_reg_access *rp;
struct sk_buff *skb;
int err = 0;
if (reg_size != sizeof(__le32))
return -EINVAL;
switch (val_size) {
case 1:
cp.mode = IBT_REG_MODE_8BIT;
break;
case 2:
cp.mode = IBT_REG_MODE_16BIT;
break;
case 4:
cp.mode = IBT_REG_MODE_32BIT;
break;
default:
return -EINVAL;
}
cp.addr = *(__le32 *)addr;
cp.len = val_size;
bt_dev_dbg(ctx->hdev, "Register (0x%x) read", le32_to_cpu(cp.addr));
skb = hci_cmd_sync(ctx->hdev, ctx->op_read, sizeof(cp), &cp,
HCI_CMD_TIMEOUT);
if (IS_ERR(skb)) {
err = PTR_ERR(skb);
bt_dev_err(ctx->hdev, "regmap: Register (0x%x) read error (%d)",
le32_to_cpu(cp.addr), err);
return err;
}
if (skb->len != sizeof(*rp) + val_size) {
bt_dev_err(ctx->hdev, "regmap: Register (0x%x) read error, bad len",
le32_to_cpu(cp.addr));
err = -EINVAL;
goto done;
}
rp = (struct ibt_rp_reg_access *)skb->data;
if (rp->addr != cp.addr) {
bt_dev_err(ctx->hdev, "regmap: Register (0x%x) read error, bad addr",
le32_to_cpu(rp->addr));
err = -EINVAL;
goto done;
}
memcpy(val, rp->data, val_size);
done:
kfree_skb(skb);
return err;
}
static int regmap_ibt_gather_write(void *context,
const void *addr, size_t reg_size,
const void *val, size_t val_size)
{
struct regmap_ibt_context *ctx = context;
struct ibt_cp_reg_access *cp;
struct sk_buff *skb;
int plen = sizeof(*cp) + val_size;
u8 mode;
int err = 0;
if (reg_size != sizeof(__le32))
return -EINVAL;
switch (val_size) {
case 1:
mode = IBT_REG_MODE_8BIT;
break;
case 2:
mode = IBT_REG_MODE_16BIT;
break;
case 4:
mode = IBT_REG_MODE_32BIT;
break;
default:
return -EINVAL;
}
cp = kmalloc(plen, GFP_KERNEL);
if (!cp)
return -ENOMEM;
cp->addr = *(__le32 *)addr;
cp->mode = mode;
cp->len = val_size;
memcpy(&cp->data, val, val_size);
bt_dev_dbg(ctx->hdev, "Register (0x%x) write", le32_to_cpu(cp->addr));
skb = hci_cmd_sync(ctx->hdev, ctx->op_write, plen, cp, HCI_CMD_TIMEOUT);
if (IS_ERR(skb)) {
err = PTR_ERR(skb);
bt_dev_err(ctx->hdev, "regmap: Register (0x%x) write error (%d)",
le32_to_cpu(cp->addr), err);
goto done;
}
kfree_skb(skb);
done:
kfree(cp);
return err;
}
static int regmap_ibt_write(void *context, const void *data, size_t count)
{
if (WARN_ONCE(count < 4, "Invalid register access"))
return -EINVAL;
return regmap_ibt_gather_write(context, data, 4, data + 4, count - 4);
}
static void regmap_ibt_free_context(void *context)
{
kfree(context);
}
struct regmap *btintel_regmap_init(struct hci_dev *hdev, u16 opcode_read,
u16 opcode_write)
{
struct regmap_ibt_context *ctx;
bt_dev_info(hdev, "regmap: Init R%x-W%x region", opcode_read,
opcode_write);
ctx = kzalloc(sizeof(*ctx), GFP_KERNEL);
if (!ctx)
return ERR_PTR(-ENOMEM);
ctx->op_read = opcode_read;
ctx->op_write = opcode_write;
ctx->hdev = hdev;
return regmap_init(&hdev->dev, &regmap_ibt, ctx, &regmap_ibt_cfg);
}
