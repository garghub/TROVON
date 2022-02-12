static int fdp_nci_create_conn(struct nci_dev *ndev)
{
struct fdp_nci_info *info = nci_get_drvdata(ndev);
struct core_conn_create_dest_spec_params param;
int r;
param.type = FDP_PATCH_CONN_PARAM_TYPE;
param.length = 0x00;
r = nci_core_conn_create(info->ndev, FDP_PATCH_CONN_DEST, 1,
sizeof(param), &param);
if (r)
return r;
return nci_get_conn_info_by_dest_type_params(ndev,
FDP_PATCH_CONN_DEST, NULL);
}
static inline int fdp_nci_get_versions(struct nci_dev *ndev)
{
return nci_core_cmd(ndev, NCI_OP_CORE_GET_CONFIG_CMD,
sizeof(nci_core_get_config_otp_ram_version),
(__u8 *) &nci_core_get_config_otp_ram_version);
}
static inline int fdp_nci_patch_cmd(struct nci_dev *ndev, u8 type)
{
return nci_prop_cmd(ndev, NCI_OP_PROP_PATCH_OID, sizeof(type), &type);
}
static inline int fdp_nci_set_production_data(struct nci_dev *ndev, u8 len,
char *data)
{
return nci_prop_cmd(ndev, NCI_OP_PROP_SET_PDATA_OID, len, data);
}
static int fdp_nci_set_clock(struct nci_dev *ndev, u8 clock_type,
u32 clock_freq)
{
u32 fc = 13560;
u32 nd, num, delta;
char data[9];
nd = (24 * fc) / clock_freq;
delta = 24 * fc - nd * clock_freq;
num = (32768 * delta) / clock_freq;
data[0] = 0x00;
data[1] = 0x00;
data[2] = 0x00;
data[3] = 0x10;
data[4] = 0x04;
data[5] = num & 0xFF;
data[6] = (num >> 8) & 0xff;
data[7] = nd;
data[8] = clock_type;
return fdp_nci_set_production_data(ndev, 9, data);
}
static void fdp_nci_send_patch_cb(struct nci_dev *ndev)
{
struct fdp_nci_info *info = nci_get_drvdata(ndev);
info->setup_patch_sent = 1;
wake_up(&info->setup_wq);
}
static void fdp_nci_set_data_pkt_counter(struct nci_dev *ndev,
void (*cb)(struct nci_dev *ndev), int count)
{
struct fdp_nci_info *info = nci_get_drvdata(ndev);
struct device *dev = &info->phy->i2c_dev->dev;
dev_dbg(dev, "NCI data pkt counter %d\n", count);
atomic_set(&info->data_pkt_counter, count);
info->data_pkt_counter_cb = cb;
}
static int fdp_nci_send_patch(struct nci_dev *ndev, u8 conn_id, u8 type)
{
struct fdp_nci_info *info = nci_get_drvdata(ndev);
const struct firmware *fw;
struct sk_buff *skb;
unsigned long len;
u8 max_size, payload_size;
int rc = 0;
if ((type == NCI_PATCH_TYPE_OTP && !info->otp_patch) ||
(type == NCI_PATCH_TYPE_RAM && !info->ram_patch))
return -EINVAL;
if (type == NCI_PATCH_TYPE_OTP)
fw = info->otp_patch;
else
fw = info->ram_patch;
max_size = nci_conn_max_data_pkt_payload_size(ndev, conn_id);
if (max_size <= 0)
return -EINVAL;
len = fw->size;
fdp_nci_set_data_pkt_counter(ndev, fdp_nci_send_patch_cb,
DIV_ROUND_UP(fw->size, max_size));
while (len) {
payload_size = min_t(unsigned long, (unsigned long) max_size,
len);
skb = nci_skb_alloc(ndev, (NCI_CTRL_HDR_SIZE + payload_size),
GFP_KERNEL);
if (!skb) {
fdp_nci_set_data_pkt_counter(ndev, NULL, 0);
return -ENOMEM;
}
skb_reserve(skb, NCI_CTRL_HDR_SIZE);
memcpy(skb_put(skb, payload_size), fw->data + (fw->size - len),
payload_size);
rc = nci_send_data(ndev, conn_id, skb);
if (rc) {
fdp_nci_set_data_pkt_counter(ndev, NULL, 0);
return rc;
}
len -= payload_size;
}
return rc;
}
static int fdp_nci_open(struct nci_dev *ndev)
{
int r;
struct fdp_nci_info *info = nci_get_drvdata(ndev);
struct device *dev = &info->phy->i2c_dev->dev;
dev_dbg(dev, "%s\n", __func__);
r = info->phy_ops->enable(info->phy);
return r;
}
static int fdp_nci_close(struct nci_dev *ndev)
{
struct fdp_nci_info *info = nci_get_drvdata(ndev);
struct device *dev = &info->phy->i2c_dev->dev;
dev_dbg(dev, "%s\n", __func__);
return 0;
}
static int fdp_nci_send(struct nci_dev *ndev, struct sk_buff *skb)
{
struct fdp_nci_info *info = nci_get_drvdata(ndev);
struct device *dev = &info->phy->i2c_dev->dev;
dev_dbg(dev, "%s\n", __func__);
if (atomic_dec_and_test(&info->data_pkt_counter))
info->data_pkt_counter_cb(ndev);
return info->phy_ops->write(info->phy, skb);
}
int fdp_nci_recv_frame(struct nci_dev *ndev, struct sk_buff *skb)
{
struct fdp_nci_info *info = nci_get_drvdata(ndev);
struct device *dev = &info->phy->i2c_dev->dev;
dev_dbg(dev, "%s\n", __func__);
return nci_recv_frame(ndev, skb);
}
static int fdp_nci_request_firmware(struct nci_dev *ndev)
{
struct fdp_nci_info *info = nci_get_drvdata(ndev);
struct device *dev = &info->phy->i2c_dev->dev;
u8 *data;
int r;
r = request_firmware(&info->ram_patch, FDP_RAM_PATCH_NAME, dev);
if (r < 0) {
nfc_err(dev, "RAM patch request error\n");
goto error;
}
data = (u8 *) info->ram_patch->data;
info->ram_patch_version =
data[FDP_FW_HEADER_SIZE] |
(data[FDP_FW_HEADER_SIZE + 1] << 8) |
(data[FDP_FW_HEADER_SIZE + 2] << 16) |
(data[FDP_FW_HEADER_SIZE + 3] << 24);
dev_dbg(dev, "RAM patch version: %d, size: %d\n",
info->ram_patch_version, (int) info->ram_patch->size);
r = request_firmware(&info->otp_patch, FDP_OTP_PATCH_NAME, dev);
if (r < 0) {
nfc_err(dev, "OTP patch request error\n");
goto out;
}
data = (u8 *) info->otp_patch->data;
info->otp_patch_version =
data[FDP_FW_HEADER_SIZE] |
(data[FDP_FW_HEADER_SIZE + 1] << 8) |
(data[FDP_FW_HEADER_SIZE+2] << 16) |
(data[FDP_FW_HEADER_SIZE+3] << 24);
dev_dbg(dev, "OTP patch version: %d, size: %d\n",
info->otp_patch_version, (int) info->otp_patch->size);
out:
return 0;
error:
return r;
}
static void fdp_nci_release_firmware(struct nci_dev *ndev)
{
struct fdp_nci_info *info = nci_get_drvdata(ndev);
if (info->otp_patch) {
release_firmware(info->otp_patch);
info->otp_patch = NULL;
}
if (info->ram_patch) {
release_firmware(info->ram_patch);
info->otp_patch = NULL;
}
}
static int fdp_nci_patch_otp(struct nci_dev *ndev)
{
struct fdp_nci_info *info = nci_get_drvdata(ndev);
struct device *dev = &info->phy->i2c_dev->dev;
u8 conn_id;
int r = 0;
if (info->otp_version >= info->otp_patch_version)
goto out;
info->setup_patch_sent = 0;
info->setup_reset_ntf = 0;
info->setup_patch_ntf = 0;
r = fdp_nci_patch_cmd(ndev, NCI_PATCH_TYPE_OTP);
if (r)
goto out;
conn_id = fdp_nci_create_conn(ndev);
if (conn_id < 0) {
r = conn_id;
goto out;
}
r = fdp_nci_send_patch(ndev, conn_id, NCI_PATCH_TYPE_OTP);
if (r)
goto out;
wait_event_interruptible(info->setup_wq,
info->setup_patch_sent == 1);
msleep(FDP_FW_UPDATE_SLEEP);
r = nci_core_conn_close(info->ndev, conn_id);
if (r)
goto out;
if (fdp_nci_patch_cmd(ndev, NCI_PATCH_TYPE_EOT)) {
nfc_err(dev, "OTP patch error 0x%x\n", r);
r = -EINVAL;
goto out;
}
wait_event_interruptible(info->setup_wq, info->setup_patch_ntf);
r = info->setup_patch_status;
if (r) {
nfc_err(dev, "OTP patch error 0x%x\n", r);
r = -EINVAL;
goto out;
}
wait_event_interruptible(info->setup_wq, info->setup_reset_ntf);
out:
return r;
}
static int fdp_nci_patch_ram(struct nci_dev *ndev)
{
struct fdp_nci_info *info = nci_get_drvdata(ndev);
struct device *dev = &info->phy->i2c_dev->dev;
u8 conn_id;
int r = 0;
if (info->ram_version >= info->ram_patch_version)
goto out;
info->setup_patch_sent = 0;
info->setup_reset_ntf = 0;
info->setup_patch_ntf = 0;
r = fdp_nci_patch_cmd(ndev, NCI_PATCH_TYPE_RAM);
if (r)
goto out;
conn_id = fdp_nci_create_conn(ndev);
if (conn_id < 0) {
r = conn_id;
goto out;
}
r = fdp_nci_send_patch(ndev, conn_id, NCI_PATCH_TYPE_RAM);
if (r)
goto out;
wait_event_interruptible(info->setup_wq,
info->setup_patch_sent == 1);
msleep(FDP_FW_UPDATE_SLEEP);
r = nci_core_conn_close(info->ndev, conn_id);
if (r)
goto out;
if (fdp_nci_patch_cmd(ndev, NCI_PATCH_TYPE_EOT)) {
nfc_err(dev, "RAM patch error 0x%x\n", r);
r = -EINVAL;
goto out;
}
wait_event_interruptible(info->setup_wq, info->setup_patch_ntf);
r = info->setup_patch_status;
if (r) {
nfc_err(dev, "RAM patch error 0x%x\n", r);
r = -EINVAL;
goto out;
}
wait_event_interruptible(info->setup_wq, info->setup_reset_ntf);
out:
return r;
}
static int fdp_nci_setup(struct nci_dev *ndev)
{
struct fdp_nci_info *info = nci_get_drvdata(ndev);
struct device *dev = &info->phy->i2c_dev->dev;
int r;
u8 patched = 0;
dev_dbg(dev, "%s\n", __func__);
r = nci_core_init(ndev);
if (r)
goto error;
r = fdp_nci_get_versions(ndev);
if (r)
goto error;
r = fdp_nci_request_firmware(ndev);
if (r)
goto error;
if (info->otp_version < info->otp_patch_version) {
r = fdp_nci_patch_otp(ndev);
if (r)
goto error;
patched = 1;
}
if (info->ram_version < info->ram_patch_version) {
r = fdp_nci_patch_ram(ndev);
if (r)
goto error;
patched = 1;
}
fdp_nci_release_firmware(ndev);
if (patched) {
r = nci_core_init(ndev);
if (r)
goto error;
r = fdp_nci_get_versions(ndev);
if (r)
goto error;
if (info->otp_version != info->otp_patch_version ||
info->ram_version != info->ram_patch_version) {
nfc_err(dev, "Firmware update failed");
r = -EINVAL;
goto error;
}
}
return nci_core_reset(ndev);
error:
fdp_nci_release_firmware(ndev);
nfc_err(dev, "Setup error %d\n", r);
return r;
}
static int fdp_nci_post_setup(struct nci_dev *ndev)
{
struct fdp_nci_info *info = nci_get_drvdata(ndev);
struct device *dev = &info->phy->i2c_dev->dev;
int r;
if (info->fw_vsc_cfg && info->fw_vsc_cfg[0]) {
r = fdp_nci_set_production_data(ndev, info->fw_vsc_cfg[3],
&info->fw_vsc_cfg[4]);
if (r) {
nfc_err(dev, "Vendor specific config set error %d\n",
r);
return r;
}
}
r = fdp_nci_set_clock(ndev, info->clock_type, info->clock_freq);
if (r) {
nfc_err(dev, "Clock set error %d\n", r);
return r;
}
r = nci_core_reset(ndev);
if (r)
return r;
return nci_core_init(ndev);
}
static int fdp_nci_core_reset_ntf_packet(struct nci_dev *ndev,
struct sk_buff *skb)
{
struct fdp_nci_info *info = nci_get_drvdata(ndev);
struct device *dev = &info->phy->i2c_dev->dev;
dev_dbg(dev, "%s\n", __func__);
info->setup_reset_ntf = 1;
wake_up(&info->setup_wq);
return 0;
}
static int fdp_nci_prop_patch_ntf_packet(struct nci_dev *ndev,
struct sk_buff *skb)
{
struct fdp_nci_info *info = nci_get_drvdata(ndev);
struct device *dev = &info->phy->i2c_dev->dev;
dev_dbg(dev, "%s\n", __func__);
info->setup_patch_ntf = 1;
info->setup_patch_status = skb->data[0];
wake_up(&info->setup_wq);
return 0;
}
static int fdp_nci_prop_patch_rsp_packet(struct nci_dev *ndev,
struct sk_buff *skb)
{
struct fdp_nci_info *info = nci_get_drvdata(ndev);
struct device *dev = &info->phy->i2c_dev->dev;
u8 status = skb->data[0];
dev_dbg(dev, "%s: status 0x%x\n", __func__, status);
nci_req_complete(ndev, status);
return 0;
}
static int fdp_nci_prop_set_production_data_rsp_packet(struct nci_dev *ndev,
struct sk_buff *skb)
{
struct fdp_nci_info *info = nci_get_drvdata(ndev);
struct device *dev = &info->phy->i2c_dev->dev;
u8 status = skb->data[0];
dev_dbg(dev, "%s: status 0x%x\n", __func__, status);
nci_req_complete(ndev, status);
return 0;
}
static int fdp_nci_core_get_config_rsp_packet(struct nci_dev *ndev,
struct sk_buff *skb)
{
struct fdp_nci_info *info = nci_get_drvdata(ndev);
struct device *dev = &info->phy->i2c_dev->dev;
struct nci_core_get_config_rsp *rsp = (void *) skb->data;
u8 i, *p;
if (rsp->status == NCI_STATUS_OK) {
p = rsp->data;
for (i = 0; i < 4; i++) {
switch (*p++) {
case NCI_PARAM_ID_FW_RAM_VERSION:
p++;
info->ram_version = le32_to_cpup((__le32 *) p);
p += 4;
break;
case NCI_PARAM_ID_FW_OTP_VERSION:
p++;
info->otp_version = le32_to_cpup((__le32 *) p);
p += 4;
break;
case NCI_PARAM_ID_OTP_LIMITED_VERSION:
p++;
info->otp_version = le32_to_cpup((__le32 *) p);
p += 4;
break;
case NCI_PARAM_ID_KEY_INDEX_ID:
p++;
info->key_index = *p++;
}
}
}
dev_dbg(dev, "OTP version %d\n", info->otp_version);
dev_dbg(dev, "RAM version %d\n", info->ram_version);
dev_dbg(dev, "key index %d\n", info->key_index);
dev_dbg(dev, "%s: status 0x%x\n", __func__, rsp->status);
nci_req_complete(ndev, rsp->status);
return 0;
}
int fdp_nci_probe(struct fdp_i2c_phy *phy, struct nfc_phy_ops *phy_ops,
struct nci_dev **ndevp, int tx_headroom,
int tx_tailroom, u8 clock_type, u32 clock_freq,
u8 *fw_vsc_cfg)
{
struct device *dev = &phy->i2c_dev->dev;
struct fdp_nci_info *info;
struct nci_dev *ndev;
u32 protocols;
int r;
info = kzalloc(sizeof(struct fdp_nci_info), GFP_KERNEL);
if (!info) {
r = -ENOMEM;
goto err_info_alloc;
}
info->phy = phy;
info->phy_ops = phy_ops;
info->clock_type = clock_type;
info->clock_freq = clock_freq;
info->fw_vsc_cfg = fw_vsc_cfg;
init_waitqueue_head(&info->setup_wq);
protocols = NFC_PROTO_JEWEL_MASK |
NFC_PROTO_MIFARE_MASK |
NFC_PROTO_FELICA_MASK |
NFC_PROTO_ISO14443_MASK |
NFC_PROTO_ISO14443_B_MASK |
NFC_PROTO_NFC_DEP_MASK |
NFC_PROTO_ISO15693_MASK;
ndev = nci_allocate_device(&nci_ops, protocols, tx_headroom,
tx_tailroom);
if (!ndev) {
nfc_err(dev, "Cannot allocate nfc ndev\n");
r = -ENOMEM;
goto err_alloc_ndev;
}
r = nci_register_device(ndev);
if (r)
goto err_regdev;
*ndevp = ndev;
info->ndev = ndev;
nci_set_drvdata(ndev, info);
return 0;
err_regdev:
nci_free_device(ndev);
err_alloc_ndev:
kfree(info);
err_info_alloc:
return r;
}
void fdp_nci_remove(struct nci_dev *ndev)
{
struct fdp_nci_info *info = nci_get_drvdata(ndev);
struct device *dev = &info->phy->i2c_dev->dev;
dev_dbg(dev, "%s\n", __func__);
nci_unregister_device(ndev);
nci_free_device(ndev);
kfree(info);
}
