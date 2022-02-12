static void pn544_hci_platform_init(struct pn544_hci_info *info)
{
int polarity, retry, ret;
char rset_cmd[] = { 0x05, 0xF9, 0x04, 0x00, 0xC3, 0xE5 };
int count = sizeof(rset_cmd);
pr_info(DRIVER_DESC ": %s\n", __func__);
dev_info(&info->i2c_dev->dev, "Detecting nfc_en polarity\n");
gpio_set_value(info->gpio_fw, 0);
for (polarity = 0; polarity < 2; polarity++) {
info->en_polarity = polarity;
retry = 3;
while (retry--) {
gpio_set_value(info->gpio_en, !info->en_polarity);
usleep_range(10000, 15000);
gpio_set_value(info->gpio_en, info->en_polarity);
usleep_range(10000, 15000);
dev_dbg(&info->i2c_dev->dev, "Sending reset cmd\n");
ret = i2c_master_send(info->i2c_dev, rset_cmd, count);
if (ret == count) {
dev_info(&info->i2c_dev->dev,
"nfc_en polarity : active %s\n",
(polarity == 0 ? "low" : "high"));
goto out;
}
}
}
dev_err(&info->i2c_dev->dev,
"Could not detect nfc_en polarity, fallback to active high\n");
out:
gpio_set_value(info->gpio_en, !info->en_polarity);
}
static int pn544_hci_enable(struct pn544_hci_info *info, int mode)
{
pr_info(DRIVER_DESC ": %s\n", __func__);
gpio_set_value(info->gpio_fw, 0);
gpio_set_value(info->gpio_en, info->en_polarity);
usleep_range(10000, 15000);
return 0;
}
static void pn544_hci_disable(struct pn544_hci_info *info)
{
pr_info(DRIVER_DESC ": %s\n", __func__);
gpio_set_value(info->gpio_fw, 0);
gpio_set_value(info->gpio_en, !info->en_polarity);
usleep_range(10000, 15000);
gpio_set_value(info->gpio_en, info->en_polarity);
usleep_range(10000, 15000);
gpio_set_value(info->gpio_en, !info->en_polarity);
usleep_range(10000, 15000);
}
static int pn544_hci_i2c_write(struct i2c_client *client, u8 *buf, int len)
{
int r;
usleep_range(3000, 6000);
r = i2c_master_send(client, buf, len);
if (r == -EREMOTEIO) {
usleep_range(6000, 10000);
r = i2c_master_send(client, buf, len);
}
if (r >= 0 && r != len)
r = -EREMOTEIO;
return r;
}
static int check_crc(u8 *buf, int buflen)
{
int len;
u16 crc;
len = buf[0] + 1;
crc = crc_ccitt(0xffff, buf, len - 2);
crc = ~crc;
if (buf[len - 2] != (crc & 0xff) || buf[len - 1] != (crc >> 8)) {
pr_err(PN544_HCI_DRIVER_NAME ": CRC error 0x%x != 0x%x 0x%x\n",
crc, buf[len - 1], buf[len - 2]);
pr_info(DRIVER_DESC ": %s : BAD CRC\n", __func__);
print_hex_dump(KERN_DEBUG, "crc: ", DUMP_PREFIX_NONE,
16, 2, buf, buflen, false);
return -EPERM;
}
return 0;
}
static int pn544_hci_i2c_read(struct i2c_client *client, struct sk_buff **skb)
{
int r;
u8 len;
u8 tmp[PN544_HCI_LLC_MAX_SIZE - 1];
r = i2c_master_recv(client, &len, 1);
if (r != 1) {
dev_err(&client->dev, "cannot read len byte\n");
return -EREMOTEIO;
}
if ((len < (PN544_HCI_LLC_MIN_SIZE - 1)) ||
(len > (PN544_HCI_LLC_MAX_SIZE - 1))) {
dev_err(&client->dev, "invalid len byte\n");
r = -EBADMSG;
goto flush;
}
*skb = alloc_skb(1 + len, GFP_KERNEL);
if (*skb == NULL) {
r = -ENOMEM;
goto flush;
}
*skb_put(*skb, 1) = len;
r = i2c_master_recv(client, skb_put(*skb, len), len);
if (r != len) {
kfree_skb(*skb);
return -EREMOTEIO;
}
r = check_crc((*skb)->data, (*skb)->len);
if (r != 0) {
kfree_skb(*skb);
r = -EBADMSG;
goto flush;
}
skb_pull(*skb, 1);
skb_trim(*skb, (*skb)->len - 2);
usleep_range(3000, 6000);
return 0;
flush:
if (i2c_master_recv(client, tmp, sizeof(tmp)) < 0)
r = -EREMOTEIO;
usleep_range(3000, 6000);
return r;
}
static irqreturn_t pn544_hci_irq_thread_fn(int irq, void *dev_id)
{
struct pn544_hci_info *info = dev_id;
struct i2c_client *client = info->i2c_dev;
struct sk_buff *skb = NULL;
int r;
BUG_ON(!info);
BUG_ON(irq != info->i2c_dev->irq);
dev_dbg(&client->dev, "IRQ\n");
if (info->hard_fault != 0)
return IRQ_HANDLED;
r = pn544_hci_i2c_read(client, &skb);
if (r == -EREMOTEIO) {
info->hard_fault = r;
nfc_shdlc_recv_frame(info->shdlc, NULL);
return IRQ_HANDLED;
} else if ((r == -ENOMEM) || (r == -EBADMSG)) {
return IRQ_HANDLED;
}
nfc_shdlc_recv_frame(info->shdlc, skb);
return IRQ_HANDLED;
}
static int pn544_hci_open(struct nfc_shdlc *shdlc)
{
struct pn544_hci_info *info = nfc_shdlc_get_clientdata(shdlc);
int r = 0;
mutex_lock(&info->info_lock);
if (info->state != PN544_ST_COLD) {
r = -EBUSY;
goto out;
}
r = pn544_hci_enable(info, HCI_MODE);
if (r == 0)
info->state = PN544_ST_READY;
out:
mutex_unlock(&info->info_lock);
return r;
}
static void pn544_hci_close(struct nfc_shdlc *shdlc)
{
struct pn544_hci_info *info = nfc_shdlc_get_clientdata(shdlc);
mutex_lock(&info->info_lock);
if (info->state == PN544_ST_COLD)
goto out;
pn544_hci_disable(info);
info->state = PN544_ST_COLD;
out:
mutex_unlock(&info->info_lock);
}
static int pn544_hci_ready(struct nfc_shdlc *shdlc)
{
struct nfc_hci_dev *hdev = nfc_shdlc_get_hci_dev(shdlc);
struct sk_buff *skb;
static struct hw_config {
u8 adr[2];
u8 value;
} hw_config[] = {
{{0x9f, 0x9a}, 0x00},
{{0x98, 0x10}, 0xbc},
{{0x9e, 0x71}, 0x00},
{{0x98, 0x09}, 0x00},
{{0x9e, 0xb4}, 0x00},
{{0x9e, 0xd9}, 0xff},
{{0x9e, 0xda}, 0xff},
{{0x9e, 0xdb}, 0x23},
{{0x9e, 0xdc}, 0x21},
{{0x9e, 0xdd}, 0x22},
{{0x9e, 0xde}, 0x24},
{{0x9c, 0x01}, 0x08},
{{0x9e, 0xaa}, 0x01},
{{0x9b, 0xd1}, 0x0d},
{{0x9b, 0xd2}, 0x24},
{{0x9b, 0xd3}, 0x0a},
{{0x9b, 0xd4}, 0x22},
{{0x9b, 0xd5}, 0x08},
{{0x9b, 0xd6}, 0x1e},
{{0x9b, 0xdd}, 0x1c},
{{0x9b, 0x84}, 0x13},
{{0x99, 0x81}, 0x7f},
{{0x99, 0x31}, 0x70},
{{0x98, 0x00}, 0x3f},
{{0x9f, 0x09}, 0x00},
{{0x9f, 0x0a}, 0x05},
{{0x9e, 0xd1}, 0xa1},
{{0x99, 0x23}, 0x00},
{{0x9e, 0x74}, 0x80},
{{0x9f, 0x28}, 0x10},
{{0x9f, 0x35}, 0x14},
{{0x9f, 0x36}, 0x60},
{{0x9c, 0x31}, 0x00},
{{0x9c, 0x32}, 0xc8},
{{0x9c, 0x19}, 0x40},
{{0x9c, 0x1a}, 0x40},
{{0x9c, 0x0c}, 0x00},
{{0x9c, 0x0d}, 0x00},
{{0x9c, 0x12}, 0x00},
{{0x9c, 0x13}, 0x00},
{{0x98, 0xa2}, 0x0e},
{{0x98, 0x93}, 0x40},
{{0x98, 0x7d}, 0x02},
{{0x98, 0x7e}, 0x00},
{{0x9f, 0xc8}, 0x01},
};
struct hw_config *p = hw_config;
int count = ARRAY_SIZE(hw_config);
struct sk_buff *res_skb;
u8 param[4];
int r;
param[0] = 0;
while (count--) {
param[1] = p->adr[0];
param[2] = p->adr[1];
param[3] = p->value;
r = nfc_hci_send_cmd(hdev, PN544_SYS_MGMT_GATE, PN544_WRITE,
param, 4, &res_skb);
if (r < 0)
return r;
if (res_skb->len != 1) {
kfree_skb(res_skb);
return -EPROTO;
}
if (res_skb->data[0] != p->value) {
kfree_skb(res_skb);
return -EIO;
}
kfree_skb(res_skb);
p++;
}
param[0] = NFC_HCI_UICC_HOST_ID;
r = nfc_hci_set_param(hdev, NFC_HCI_ADMIN_GATE,
NFC_HCI_ADMIN_WHITELIST, param, 1);
if (r < 0)
return r;
param[0] = 0x3d;
r = nfc_hci_set_param(hdev, PN544_SYS_MGMT_GATE,
PN544_SYS_MGMT_INFO_NOTIFICATION, param, 1);
if (r < 0)
return r;
param[0] = 0x0;
r = nfc_hci_set_param(hdev, NFC_HCI_RF_READER_A_GATE,
PN544_RF_READER_A_AUTO_ACTIVATION, param, 1);
if (r < 0)
return r;
r = nfc_hci_send_event(hdev, NFC_HCI_RF_READER_A_GATE,
NFC_HCI_EVT_END_OPERATION, NULL, 0);
if (r < 0)
return r;
param[0] = 0x1;
r = nfc_hci_set_param(hdev, PN544_POLLING_LOOP_MGMT_GATE,
PN544_PL_NFCT_DEACTIVATED, param, 1);
if (r < 0)
return r;
param[0] = 0x0;
r = nfc_hci_set_param(hdev, PN544_POLLING_LOOP_MGMT_GATE,
PN544_PL_RDPHASES, param, 1);
if (r < 0)
return r;
r = nfc_hci_get_param(hdev, NFC_HCI_ID_MGMT_GATE,
PN544_ID_MGMT_FULL_VERSION_SW, &skb);
if (r < 0)
return r;
if (skb->len != FULL_VERSION_LEN) {
kfree_skb(skb);
return -EINVAL;
}
print_hex_dump(KERN_DEBUG, "FULL VERSION SOFTWARE INFO: ",
DUMP_PREFIX_NONE, 16, 1,
skb->data, FULL_VERSION_LEN, false);
kfree_skb(skb);
return 0;
}
static int pn544_hci_xmit(struct nfc_shdlc *shdlc, struct sk_buff *skb)
{
struct pn544_hci_info *info = nfc_shdlc_get_clientdata(shdlc);
struct i2c_client *client = info->i2c_dev;
if (info->hard_fault != 0)
return info->hard_fault;
return pn544_hci_i2c_write(client, skb->data, skb->len);
}
static int pn544_hci_start_poll(struct nfc_shdlc *shdlc,
u32 im_protocols, u32 tm_protocols)
{
struct nfc_hci_dev *hdev = nfc_shdlc_get_hci_dev(shdlc);
u8 phases = 0;
int r;
u8 duration[2];
u8 activated;
pr_info(DRIVER_DESC ": %s protocols 0x%x 0x%x\n",
__func__, im_protocols, tm_protocols);
r = nfc_hci_send_event(hdev, NFC_HCI_RF_READER_A_GATE,
NFC_HCI_EVT_END_OPERATION, NULL, 0);
if (r < 0)
return r;
duration[0] = 0x18;
duration[1] = 0x6a;
r = nfc_hci_set_param(hdev, PN544_POLLING_LOOP_MGMT_GATE,
PN544_PL_EMULATION, duration, 2);
if (r < 0)
return r;
activated = 0;
r = nfc_hci_set_param(hdev, PN544_POLLING_LOOP_MGMT_GATE,
PN544_PL_NFCT_DEACTIVATED, &activated, 1);
if (r < 0)
return r;
if (im_protocols & (NFC_PROTO_ISO14443_MASK | NFC_PROTO_MIFARE_MASK |
NFC_PROTO_JEWEL_MASK))
phases |= 1;
if (im_protocols & NFC_PROTO_FELICA_MASK) {
phases |= (1 << 2);
phases |= (1 << 3);
}
phases |= (1 << 5);
r = nfc_hci_set_param(hdev, PN544_POLLING_LOOP_MGMT_GATE,
PN544_PL_RDPHASES, &phases, 1);
if (r < 0)
return r;
r = nfc_hci_send_event(hdev, NFC_HCI_RF_READER_A_GATE,
NFC_HCI_EVT_READER_REQUESTED, NULL, 0);
if (r < 0)
nfc_hci_send_event(hdev, NFC_HCI_RF_READER_A_GATE,
NFC_HCI_EVT_END_OPERATION, NULL, 0);
return r;
}
static int pn544_hci_target_from_gate(struct nfc_shdlc *shdlc, u8 gate,
struct nfc_target *target)
{
switch (gate) {
case PN544_RF_READER_F_GATE:
target->supported_protocols = NFC_PROTO_FELICA_MASK;
break;
case PN544_RF_READER_JEWEL_GATE:
target->supported_protocols = NFC_PROTO_JEWEL_MASK;
target->sens_res = 0x0c00;
break;
default:
return -EPROTO;
}
return 0;
}
static int pn544_hci_complete_target_discovered(struct nfc_shdlc *shdlc,
u8 gate,
struct nfc_target *target)
{
struct nfc_hci_dev *hdev = nfc_shdlc_get_hci_dev(shdlc);
struct sk_buff *uid_skb;
int r = 0;
if (target->supported_protocols & NFC_PROTO_MIFARE_MASK) {
if (target->nfcid1_len != 4 && target->nfcid1_len != 7 &&
target->nfcid1_len != 10)
return -EPROTO;
r = nfc_hci_send_cmd(hdev, NFC_HCI_RF_READER_A_GATE,
PN544_RF_READER_CMD_ACTIVATE_NEXT,
target->nfcid1, target->nfcid1_len, NULL);
} else if (target->supported_protocols & NFC_PROTO_FELICA_MASK) {
r = nfc_hci_get_param(hdev, PN544_RF_READER_F_GATE,
PN544_FELICA_ID, &uid_skb);
if (r < 0)
return r;
if (uid_skb->len != 8) {
kfree_skb(uid_skb);
return -EPROTO;
}
r = nfc_hci_send_cmd(hdev, PN544_RF_READER_F_GATE,
PN544_RF_READER_CMD_ACTIVATE_NEXT,
uid_skb->data, uid_skb->len, NULL);
kfree_skb(uid_skb);
} else if (target->supported_protocols & NFC_PROTO_ISO14443_MASK) {
if (target->sens_res == 0x4403)
r = nfc_hci_send_cmd(hdev, NFC_HCI_RF_READER_A_GATE,
PN544_RF_READER_A_CMD_CONTINUE_ACTIVATION,
NULL, 0, NULL);
}
return r;
}
static int pn544_hci_data_exchange(struct nfc_shdlc *shdlc,
struct nfc_target *target,
struct sk_buff *skb,
struct sk_buff **res_skb)
{
struct nfc_hci_dev *hdev = nfc_shdlc_get_hci_dev(shdlc);
int r;
pr_info(DRIVER_DESC ": %s for gate=%d\n", __func__,
target->hci_reader_gate);
switch (target->hci_reader_gate) {
case NFC_HCI_RF_READER_A_GATE:
if (target->supported_protocols & NFC_PROTO_MIFARE_MASK) {
if (skb->len == MIFARE_CMD_LEN &&
(skb->data[0] == MIFARE_CMD_AUTH_KEY_A ||
skb->data[0] == MIFARE_CMD_AUTH_KEY_B)) {
u8 uid[MIFARE_UID_LEN];
u8 *data = skb->data + MIFARE_CMD_HEADER;
memcpy(uid, data + MIFARE_KEY_LEN,
MIFARE_UID_LEN);
memmove(data + MIFARE_UID_LEN, data,
MIFARE_KEY_LEN);
memcpy(data, uid, MIFARE_UID_LEN);
}
return nfc_hci_send_cmd(hdev, target->hci_reader_gate,
PN544_MIFARE_CMD,
skb->data, skb->len, res_skb);
} else
return 1;
case PN544_RF_READER_F_GATE:
*skb_push(skb, 1) = 0;
*skb_push(skb, 1) = 0;
r = nfc_hci_send_cmd(hdev, target->hci_reader_gate,
PN544_FELICA_RAW,
skb->data, skb->len, res_skb);
if (r == 0)
skb_pull(*res_skb, 1);
return r;
case PN544_RF_READER_JEWEL_GATE:
return nfc_hci_send_cmd(hdev, target->hci_reader_gate,
PN544_JEWEL_RAW_CMD,
skb->data, skb->len, res_skb);
default:
return 1;
}
}
static int pn544_hci_check_presence(struct nfc_shdlc *shdlc,
struct nfc_target *target)
{
struct nfc_hci_dev *hdev = nfc_shdlc_get_hci_dev(shdlc);
return nfc_hci_send_cmd(hdev, target->hci_reader_gate,
PN544_RF_READER_CMD_PRESENCE_CHECK,
NULL, 0, NULL);
}
static int __devinit pn544_hci_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct pn544_hci_info *info;
struct pn544_nfc_platform_data *pdata;
int r = 0;
u32 protocols;
struct nfc_hci_init_data init_data;
dev_dbg(&client->dev, "%s\n", __func__);
dev_dbg(&client->dev, "IRQ: %d\n", client->irq);
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C)) {
dev_err(&client->dev, "Need I2C_FUNC_I2C\n");
return -ENODEV;
}
info = kzalloc(sizeof(struct pn544_hci_info), GFP_KERNEL);
if (!info) {
dev_err(&client->dev,
"Cannot allocate memory for pn544_hci_info.\n");
r = -ENOMEM;
goto err_info_alloc;
}
info->i2c_dev = client;
info->state = PN544_ST_COLD;
mutex_init(&info->info_lock);
i2c_set_clientdata(client, info);
pdata = client->dev.platform_data;
if (pdata == NULL) {
dev_err(&client->dev, "No platform data\n");
r = -EINVAL;
goto err_pdata;
}
if (pdata->request_resources == NULL) {
dev_err(&client->dev, "request_resources() missing\n");
r = -EINVAL;
goto err_pdata;
}
r = pdata->request_resources(client);
if (r) {
dev_err(&client->dev, "Cannot get platform resources\n");
goto err_pdata;
}
info->gpio_en = pdata->get_gpio(NFC_GPIO_ENABLE);
info->gpio_fw = pdata->get_gpio(NFC_GPIO_FW_RESET);
info->gpio_irq = pdata->get_gpio(NFC_GPIO_IRQ);
pn544_hci_platform_init(info);
r = request_threaded_irq(client->irq, NULL, pn544_hci_irq_thread_fn,
IRQF_TRIGGER_RISING, PN544_HCI_DRIVER_NAME,
info);
if (r < 0) {
dev_err(&client->dev, "Unable to register IRQ handler\n");
goto err_rti;
}
init_data.gate_count = ARRAY_SIZE(pn544_gates);
memcpy(init_data.gates, pn544_gates, sizeof(pn544_gates));
strcpy(init_data.session_id, "ID544HCI");
protocols = NFC_PROTO_JEWEL_MASK |
NFC_PROTO_MIFARE_MASK |
NFC_PROTO_FELICA_MASK |
NFC_PROTO_ISO14443_MASK |
NFC_PROTO_ISO14443_B_MASK |
NFC_PROTO_NFC_DEP_MASK;
info->shdlc = nfc_shdlc_allocate(&pn544_shdlc_ops,
&init_data, protocols,
PN544_CMDS_HEADROOM, 0,
PN544_HCI_LLC_MAX_PAYLOAD,
dev_name(&client->dev));
if (!info->shdlc) {
dev_err(&client->dev, "Cannot allocate nfc shdlc.\n");
r = -ENOMEM;
goto err_allocshdlc;
}
nfc_shdlc_set_clientdata(info->shdlc, info);
return 0;
err_allocshdlc:
free_irq(client->irq, info);
err_rti:
if (pdata->free_resources != NULL)
pdata->free_resources();
err_pdata:
kfree(info);
err_info_alloc:
return r;
}
static __devexit int pn544_hci_remove(struct i2c_client *client)
{
struct pn544_hci_info *info = i2c_get_clientdata(client);
struct pn544_nfc_platform_data *pdata = client->dev.platform_data;
dev_dbg(&client->dev, "%s\n", __func__);
nfc_shdlc_free(info->shdlc);
if (info->state != PN544_ST_COLD) {
if (pdata->disable)
pdata->disable();
}
free_irq(client->irq, info);
if (pdata->free_resources)
pdata->free_resources();
kfree(info);
return 0;
}
static int __init pn544_hci_init(void)
{
int r;
pr_debug(DRIVER_DESC ": %s\n", __func__);
r = i2c_add_driver(&pn544_hci_driver);
if (r) {
pr_err(PN544_HCI_DRIVER_NAME ": driver registration failed\n");
return r;
}
return 0;
}
static void __exit pn544_hci_exit(void)
{
i2c_del_driver(&pn544_hci_driver);
}
