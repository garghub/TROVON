int digital_in_iso_dep_pull_sod(struct nfc_digital_dev *ddev,
struct sk_buff *skb)
{
u8 pcb;
u8 block_type;
if (skb->len < 1)
return -EIO;
pcb = *skb->data;
block_type = DIGITAL_ISO_DEP_PCB_TYPE(pcb);
if (block_type != DIGITAL_ISO_DEP_I_BLOCK) {
pr_err("ISO_DEP R-block and S-block not supported\n");
return -EIO;
}
if (DIGITAL_ISO_DEP_BLOCK_HAS_DID(pcb)) {
pr_err("DID field in ISO_DEP PCB not supported\n");
return -EIO;
}
skb_pull(skb, 1);
return 0;
}
int digital_in_iso_dep_push_sod(struct nfc_digital_dev *ddev,
struct sk_buff *skb)
{
if (skb->len + 3 > ddev->target_fsc)
return -EIO;
skb_push(skb, 1);
*skb->data = DIGITAL_ISO_DEP_I_PCB | ddev->curr_nfc_dep_pni;
ddev->curr_nfc_dep_pni =
DIGITAL_ISO_DEP_PNI(ddev->curr_nfc_dep_pni + 1);
return 0;
}
static void digital_in_recv_ats(struct nfc_digital_dev *ddev, void *arg,
struct sk_buff *resp)
{
struct nfc_target *target = arg;
u8 fsdi;
int rc;
if (IS_ERR(resp)) {
rc = PTR_ERR(resp);
resp = NULL;
goto exit;
}
if (resp->len < 2) {
rc = -EIO;
goto exit;
}
fsdi = DIGITAL_ATS_FSCI(resp->data[1]);
if (fsdi >= 8)
ddev->target_fsc = DIGITAL_ATS_MAX_FSC;
else
ddev->target_fsc = digital_ats_fsc[fsdi];
ddev->curr_nfc_dep_pni = 0;
rc = digital_target_found(ddev, target, NFC_PROTO_ISO14443);
exit:
dev_kfree_skb(resp);
kfree(target);
if (rc)
digital_poll_next_tech(ddev);
}
static int digital_in_send_rats(struct nfc_digital_dev *ddev,
struct nfc_target *target)
{
int rc;
struct sk_buff *skb;
skb = digital_skb_alloc(ddev, 2);
if (!skb)
return -ENOMEM;
*skb_put(skb, 1) = DIGITAL_RATS_BYTE1;
*skb_put(skb, 1) = DIGITAL_RATS_PARAM;
rc = digital_in_send_cmd(ddev, skb, 30, digital_in_recv_ats,
target);
if (rc)
kfree_skb(skb);
return rc;
}
static void digital_in_recv_sel_res(struct nfc_digital_dev *ddev, void *arg,
struct sk_buff *resp)
{
struct nfc_target *target = arg;
int rc;
u8 sel_res;
u8 nfc_proto;
if (IS_ERR(resp)) {
rc = PTR_ERR(resp);
resp = NULL;
goto exit;
}
if (!DIGITAL_DRV_CAPS_IN_CRC(ddev)) {
rc = digital_skb_check_crc_a(resp);
if (rc) {
PROTOCOL_ERR("4.4.1.3");
goto exit;
}
}
if (!resp->len) {
rc = -EIO;
goto exit;
}
sel_res = resp->data[0];
if (!DIGITAL_SEL_RES_NFCID1_COMPLETE(sel_res)) {
rc = digital_in_send_sdd_req(ddev, target);
if (rc)
goto exit;
goto exit_free_skb;
}
target->sel_res = sel_res;
if (DIGITAL_SEL_RES_IS_T2T(sel_res)) {
nfc_proto = NFC_PROTO_MIFARE;
} else if (DIGITAL_SEL_RES_IS_T4T(sel_res)) {
rc = digital_in_send_rats(ddev, target);
if (rc)
goto exit;
goto exit_free_skb;
} else if (DIGITAL_SEL_RES_IS_NFC_DEP(sel_res)) {
nfc_proto = NFC_PROTO_NFC_DEP;
} else {
rc = -EOPNOTSUPP;
goto exit;
}
rc = digital_target_found(ddev, target, nfc_proto);
exit:
kfree(target);
exit_free_skb:
dev_kfree_skb(resp);
if (rc)
digital_poll_next_tech(ddev);
}
static int digital_in_send_sel_req(struct nfc_digital_dev *ddev,
struct nfc_target *target,
struct digital_sdd_res *sdd_res)
{
struct sk_buff *skb;
struct digital_sel_req *sel_req;
u8 sel_cmd;
int rc;
skb = digital_skb_alloc(ddev, sizeof(struct digital_sel_req));
if (!skb)
return -ENOMEM;
skb_put(skb, sizeof(struct digital_sel_req));
sel_req = (struct digital_sel_req *)skb->data;
if (target->nfcid1_len <= 4)
sel_cmd = DIGITAL_CMD_SEL_REQ_CL1;
else if (target->nfcid1_len < 10)
sel_cmd = DIGITAL_CMD_SEL_REQ_CL2;
else
sel_cmd = DIGITAL_CMD_SEL_REQ_CL3;
sel_req->sel_cmd = sel_cmd;
sel_req->b2 = 0x70;
memcpy(sel_req->nfcid1, sdd_res->nfcid1, 4);
sel_req->bcc = sdd_res->bcc;
if (DIGITAL_DRV_CAPS_IN_CRC(ddev)) {
rc = digital_in_configure_hw(ddev, NFC_DIGITAL_CONFIG_FRAMING,
NFC_DIGITAL_FRAMING_NFCA_STANDARD_WITH_CRC_A);
if (rc)
goto exit;
} else {
digital_skb_add_crc_a(skb);
}
rc = digital_in_send_cmd(ddev, skb, 30, digital_in_recv_sel_res,
target);
exit:
if (rc)
kfree_skb(skb);
return rc;
}
static void digital_in_recv_sdd_res(struct nfc_digital_dev *ddev, void *arg,
struct sk_buff *resp)
{
struct nfc_target *target = arg;
struct digital_sdd_res *sdd_res;
int rc;
u8 offset, size;
u8 i, bcc;
if (IS_ERR(resp)) {
rc = PTR_ERR(resp);
resp = NULL;
goto exit;
}
if (resp->len < DIGITAL_SDD_RES_LEN) {
PROTOCOL_ERR("4.7.2.8");
rc = -EINVAL;
goto exit;
}
sdd_res = (struct digital_sdd_res *)resp->data;
for (i = 0, bcc = 0; i < 4; i++)
bcc ^= sdd_res->nfcid1[i];
if (bcc != sdd_res->bcc) {
PROTOCOL_ERR("4.7.2.6");
rc = -EINVAL;
goto exit;
}
if (sdd_res->nfcid1[0] == DIGITAL_SDD_RES_CT) {
offset = 1;
size = 3;
} else {
offset = 0;
size = 4;
}
memcpy(target->nfcid1 + target->nfcid1_len, sdd_res->nfcid1 + offset,
size);
target->nfcid1_len += size;
rc = digital_in_send_sel_req(ddev, target, sdd_res);
exit:
dev_kfree_skb(resp);
if (rc) {
kfree(target);
digital_poll_next_tech(ddev);
}
}
static int digital_in_send_sdd_req(struct nfc_digital_dev *ddev,
struct nfc_target *target)
{
int rc;
struct sk_buff *skb;
u8 sel_cmd;
rc = digital_in_configure_hw(ddev, NFC_DIGITAL_CONFIG_FRAMING,
NFC_DIGITAL_FRAMING_NFCA_STANDARD);
if (rc)
return rc;
skb = digital_skb_alloc(ddev, 2);
if (!skb)
return -ENOMEM;
if (target->nfcid1_len == 0)
sel_cmd = DIGITAL_CMD_SEL_REQ_CL1;
else if (target->nfcid1_len == 3)
sel_cmd = DIGITAL_CMD_SEL_REQ_CL2;
else
sel_cmd = DIGITAL_CMD_SEL_REQ_CL3;
*skb_put(skb, sizeof(u8)) = sel_cmd;
*skb_put(skb, sizeof(u8)) = DIGITAL_SDD_REQ_SEL_PAR;
return digital_in_send_cmd(ddev, skb, 30, digital_in_recv_sdd_res,
target);
}
static void digital_in_recv_sens_res(struct nfc_digital_dev *ddev, void *arg,
struct sk_buff *resp)
{
struct nfc_target *target = NULL;
int rc;
if (IS_ERR(resp)) {
rc = PTR_ERR(resp);
resp = NULL;
goto exit;
}
if (resp->len < sizeof(u16)) {
rc = -EIO;
goto exit;
}
target = kzalloc(sizeof(struct nfc_target), GFP_KERNEL);
if (!target) {
rc = -ENOMEM;
goto exit;
}
target->sens_res = __le16_to_cpu(*(__le16 *)resp->data);
if (!DIGITAL_SENS_RES_IS_VALID(target->sens_res)) {
PROTOCOL_ERR("4.6.3.3");
rc = -EINVAL;
goto exit;
}
if (DIGITAL_SENS_RES_IS_T1T(target->sens_res))
rc = digital_target_found(ddev, target, NFC_PROTO_JEWEL);
else
rc = digital_in_send_sdd_req(ddev, target);
exit:
dev_kfree_skb(resp);
if (rc) {
kfree(target);
digital_poll_next_tech(ddev);
}
}
int digital_in_send_sens_req(struct nfc_digital_dev *ddev, u8 rf_tech)
{
struct sk_buff *skb;
int rc;
rc = digital_in_configure_hw(ddev, NFC_DIGITAL_CONFIG_RF_TECH,
NFC_DIGITAL_RF_TECH_106A);
if (rc)
return rc;
rc = digital_in_configure_hw(ddev, NFC_DIGITAL_CONFIG_FRAMING,
NFC_DIGITAL_FRAMING_NFCA_SHORT);
if (rc)
return rc;
skb = digital_skb_alloc(ddev, 1);
if (!skb)
return -ENOMEM;
*skb_put(skb, sizeof(u8)) = DIGITAL_CMD_SENS_REQ;
rc = digital_in_send_cmd(ddev, skb, 30, digital_in_recv_sens_res, NULL);
if (rc)
kfree_skb(skb);
return rc;
}
int digital_in_recv_mifare_res(struct sk_buff *resp)
{
if (resp->len == DIGITAL_MIFARE_READ_RES_LEN + DIGITAL_CRC_LEN) {
if (digital_skb_check_crc_a(resp)) {
PROTOCOL_ERR("9.4.1.2");
return -EIO;
}
return 0;
}
if (resp->len == 1 && resp->data[0] == DIGITAL_MIFARE_ACK_RES) {
resp->data[0] = 0;
return 0;
}
return -EIO;
}
static void digital_in_recv_sensf_res(struct nfc_digital_dev *ddev, void *arg,
struct sk_buff *resp)
{
int rc;
u8 proto;
struct nfc_target target;
struct digital_sensf_res *sensf_res;
if (IS_ERR(resp)) {
rc = PTR_ERR(resp);
resp = NULL;
goto exit;
}
if (resp->len < DIGITAL_SENSF_RES_MIN_LENGTH) {
rc = -EIO;
goto exit;
}
if (!DIGITAL_DRV_CAPS_IN_CRC(ddev)) {
rc = digital_skb_check_crc_f(resp);
if (rc) {
PROTOCOL_ERR("6.4.1.8");
goto exit;
}
}
skb_pull(resp, 1);
memset(&target, 0, sizeof(struct nfc_target));
sensf_res = (struct digital_sensf_res *)resp->data;
memcpy(target.sensf_res, sensf_res, resp->len);
target.sensf_res_len = resp->len;
memcpy(target.nfcid2, sensf_res->nfcid2, NFC_NFCID2_MAXSIZE);
target.nfcid2_len = NFC_NFCID2_MAXSIZE;
if (target.nfcid2[0] == DIGITAL_SENSF_NFCID2_NFC_DEP_B1 &&
target.nfcid2[1] == DIGITAL_SENSF_NFCID2_NFC_DEP_B2)
proto = NFC_PROTO_NFC_DEP;
else
proto = NFC_PROTO_FELICA;
rc = digital_target_found(ddev, &target, proto);
exit:
dev_kfree_skb(resp);
if (rc)
digital_poll_next_tech(ddev);
}
int digital_in_send_sensf_req(struct nfc_digital_dev *ddev, u8 rf_tech)
{
struct digital_sensf_req *sensf_req;
struct sk_buff *skb;
int rc;
u8 size;
rc = digital_in_configure_hw(ddev, NFC_DIGITAL_CONFIG_RF_TECH, rf_tech);
if (rc)
return rc;
rc = digital_in_configure_hw(ddev, NFC_DIGITAL_CONFIG_FRAMING,
NFC_DIGITAL_FRAMING_NFCF);
if (rc)
return rc;
size = sizeof(struct digital_sensf_req);
skb = digital_skb_alloc(ddev, size);
if (!skb)
return -ENOMEM;
skb_put(skb, size);
sensf_req = (struct digital_sensf_req *)skb->data;
sensf_req->cmd = DIGITAL_CMD_SENSF_REQ;
sensf_req->sc1 = 0xFF;
sensf_req->sc2 = 0xFF;
sensf_req->rc = 0;
sensf_req->tsn = 0;
*skb_push(skb, 1) = size + 1;
if (!DIGITAL_DRV_CAPS_IN_CRC(ddev))
digital_skb_add_crc_f(skb);
rc = digital_in_send_cmd(ddev, skb, 30, digital_in_recv_sensf_res,
NULL);
if (rc)
kfree_skb(skb);
return rc;
}
static void digital_in_recv_iso15693_inv_res(struct nfc_digital_dev *ddev,
void *arg, struct sk_buff *resp)
{
struct digital_iso15693_inv_res *res;
struct nfc_target *target = NULL;
int rc;
if (IS_ERR(resp)) {
rc = PTR_ERR(resp);
resp = NULL;
goto out_free_skb;
}
if (resp->len != sizeof(*res)) {
rc = -EIO;
goto out_free_skb;
}
res = (struct digital_iso15693_inv_res *)resp->data;
if (!DIGITAL_ISO15693_RES_IS_VALID(res->flags)) {
PROTOCOL_ERR("ISO15693 - 10.3.1");
rc = -EINVAL;
goto out_free_skb;
}
target = kzalloc(sizeof(*target), GFP_KERNEL);
if (!target) {
rc = -ENOMEM;
goto out_free_skb;
}
target->is_iso15693 = 1;
target->iso15693_dsfid = res->dsfid;
memcpy(target->iso15693_uid, &res->uid, sizeof(target->iso15693_uid));
rc = digital_target_found(ddev, target, NFC_PROTO_ISO15693);
kfree(target);
out_free_skb:
dev_kfree_skb(resp);
if (rc)
digital_poll_next_tech(ddev);
}
int digital_in_send_iso15693_inv_req(struct nfc_digital_dev *ddev, u8 rf_tech)
{
struct digital_iso15693_inv_req *req;
struct sk_buff *skb;
int rc;
rc = digital_in_configure_hw(ddev, NFC_DIGITAL_CONFIG_RF_TECH,
NFC_DIGITAL_RF_TECH_ISO15693);
if (rc)
return rc;
rc = digital_in_configure_hw(ddev, NFC_DIGITAL_CONFIG_FRAMING,
NFC_DIGITAL_FRAMING_ISO15693_INVENTORY);
if (rc)
return rc;
skb = digital_skb_alloc(ddev, sizeof(*req));
if (!skb)
return -ENOMEM;
skb_put(skb, sizeof(*req) - sizeof(req->mask));
req = (struct digital_iso15693_inv_req *)skb->data;
req->flags = DIGITAL_ISO15693_REQ_FLAG_DATA_RATE |
DIGITAL_ISO15693_REQ_FLAG_INVENTORY |
DIGITAL_ISO15693_REQ_FLAG_NB_SLOTS;
req->cmd = DIGITAL_CMD_ISO15693_INVENTORY_REQ;
req->mask_len = 0;
rc = digital_in_send_cmd(ddev, skb, 30,
digital_in_recv_iso15693_inv_res, NULL);
if (rc)
kfree_skb(skb);
return rc;
}
static int digital_tg_send_sel_res(struct nfc_digital_dev *ddev)
{
struct sk_buff *skb;
int rc;
skb = digital_skb_alloc(ddev, 1);
if (!skb)
return -ENOMEM;
*skb_put(skb, 1) = DIGITAL_SEL_RES_NFC_DEP;
if (!DIGITAL_DRV_CAPS_TG_CRC(ddev))
digital_skb_add_crc_a(skb);
rc = digital_tg_send_cmd(ddev, skb, 300, digital_tg_recv_atr_req,
NULL);
if (rc)
kfree_skb(skb);
return rc;
}
static void digital_tg_recv_sel_req(struct nfc_digital_dev *ddev, void *arg,
struct sk_buff *resp)
{
int rc;
if (IS_ERR(resp)) {
rc = PTR_ERR(resp);
resp = NULL;
goto exit;
}
if (!DIGITAL_DRV_CAPS_TG_CRC(ddev)) {
rc = digital_skb_check_crc_a(resp);
if (rc) {
PROTOCOL_ERR("4.4.1.3");
goto exit;
}
}
rc = digital_tg_send_sel_res(ddev);
exit:
if (rc)
digital_poll_next_tech(ddev);
dev_kfree_skb(resp);
}
static int digital_tg_send_sdd_res(struct nfc_digital_dev *ddev)
{
struct sk_buff *skb;
struct digital_sdd_res *sdd_res;
int rc, i;
skb = digital_skb_alloc(ddev, sizeof(struct digital_sdd_res));
if (!skb)
return -ENOMEM;
skb_put(skb, sizeof(struct digital_sdd_res));
sdd_res = (struct digital_sdd_res *)skb->data;
sdd_res->nfcid1[0] = 0x08;
get_random_bytes(sdd_res->nfcid1 + 1, 3);
sdd_res->bcc = 0;
for (i = 0; i < 4; i++)
sdd_res->bcc ^= sdd_res->nfcid1[i];
rc = digital_tg_send_cmd(ddev, skb, 300, digital_tg_recv_sel_req,
NULL);
if (rc)
kfree_skb(skb);
return rc;
}
static void digital_tg_recv_sdd_req(struct nfc_digital_dev *ddev, void *arg,
struct sk_buff *resp)
{
u8 *sdd_req;
int rc;
if (IS_ERR(resp)) {
rc = PTR_ERR(resp);
resp = NULL;
goto exit;
}
sdd_req = resp->data;
if (resp->len < 2 || sdd_req[0] != DIGITAL_CMD_SEL_REQ_CL1 ||
sdd_req[1] != DIGITAL_SDD_REQ_SEL_PAR) {
rc = -EINVAL;
goto exit;
}
rc = digital_tg_send_sdd_res(ddev);
exit:
if (rc)
digital_poll_next_tech(ddev);
dev_kfree_skb(resp);
}
static int digital_tg_send_sens_res(struct nfc_digital_dev *ddev)
{
struct sk_buff *skb;
u8 *sens_res;
int rc;
skb = digital_skb_alloc(ddev, 2);
if (!skb)
return -ENOMEM;
sens_res = skb_put(skb, 2);
sens_res[0] = (DIGITAL_SENS_RES_NFC_DEP >> 8) & 0xFF;
sens_res[1] = DIGITAL_SENS_RES_NFC_DEP & 0xFF;
rc = digital_tg_send_cmd(ddev, skb, 300, digital_tg_recv_sdd_req,
NULL);
if (rc)
kfree_skb(skb);
return rc;
}
void digital_tg_recv_sens_req(struct nfc_digital_dev *ddev, void *arg,
struct sk_buff *resp)
{
u8 sens_req;
int rc;
if (IS_ERR(resp)) {
rc = PTR_ERR(resp);
resp = NULL;
goto exit;
}
sens_req = resp->data[0];
if (!resp->len || (sens_req != DIGITAL_CMD_SENS_REQ &&
sens_req != DIGITAL_CMD_ALL_REQ)) {
rc = -EINVAL;
goto exit;
}
rc = digital_tg_send_sens_res(ddev);
exit:
if (rc)
digital_poll_next_tech(ddev);
dev_kfree_skb(resp);
}
static int digital_tg_send_sensf_res(struct nfc_digital_dev *ddev,
struct digital_sensf_req *sensf_req)
{
struct sk_buff *skb;
u8 size;
int rc;
struct digital_sensf_res *sensf_res;
size = sizeof(struct digital_sensf_res);
if (sensf_req->rc != DIGITAL_SENSF_REQ_RC_NONE)
size -= sizeof(sensf_res->rd);
skb = digital_skb_alloc(ddev, size);
if (!skb)
return -ENOMEM;
skb_put(skb, size);
sensf_res = (struct digital_sensf_res *)skb->data;
memset(sensf_res, 0, size);
sensf_res->cmd = DIGITAL_CMD_SENSF_RES;
sensf_res->nfcid2[0] = DIGITAL_SENSF_NFCID2_NFC_DEP_B1;
sensf_res->nfcid2[1] = DIGITAL_SENSF_NFCID2_NFC_DEP_B2;
get_random_bytes(&sensf_res->nfcid2[2], 6);
switch (sensf_req->rc) {
case DIGITAL_SENSF_REQ_RC_SC:
sensf_res->rd[0] = sensf_req->sc1;
sensf_res->rd[1] = sensf_req->sc2;
break;
case DIGITAL_SENSF_REQ_RC_AP:
sensf_res->rd[0] = DIGITAL_SENSF_RES_RD_AP_B1;
sensf_res->rd[1] = DIGITAL_SENSF_RES_RD_AP_B2;
break;
}
*skb_push(skb, sizeof(u8)) = size + 1;
if (!DIGITAL_DRV_CAPS_TG_CRC(ddev))
digital_skb_add_crc_f(skb);
rc = digital_tg_send_cmd(ddev, skb, 300,
digital_tg_recv_atr_req, NULL);
if (rc)
kfree_skb(skb);
return rc;
}
void digital_tg_recv_sensf_req(struct nfc_digital_dev *ddev, void *arg,
struct sk_buff *resp)
{
struct digital_sensf_req *sensf_req;
int rc;
if (IS_ERR(resp)) {
rc = PTR_ERR(resp);
resp = NULL;
goto exit;
}
if (!DIGITAL_DRV_CAPS_TG_CRC(ddev)) {
rc = digital_skb_check_crc_f(resp);
if (rc) {
PROTOCOL_ERR("6.4.1.8");
goto exit;
}
}
if (resp->len != sizeof(struct digital_sensf_req) + 1) {
rc = -EINVAL;
goto exit;
}
skb_pull(resp, 1);
sensf_req = (struct digital_sensf_req *)resp->data;
if (sensf_req->cmd != DIGITAL_CMD_SENSF_REQ) {
rc = -EINVAL;
goto exit;
}
rc = digital_tg_send_sensf_res(ddev, sensf_req);
exit:
if (rc)
digital_poll_next_tech(ddev);
dev_kfree_skb(resp);
}
int digital_tg_listen_nfca(struct nfc_digital_dev *ddev, u8 rf_tech)
{
int rc;
rc = digital_tg_configure_hw(ddev, NFC_DIGITAL_CONFIG_RF_TECH, rf_tech);
if (rc)
return rc;
rc = digital_tg_configure_hw(ddev, NFC_DIGITAL_CONFIG_FRAMING,
NFC_DIGITAL_FRAMING_NFCA_NFC_DEP);
if (rc)
return rc;
return digital_tg_listen(ddev, 300, digital_tg_recv_sens_req, NULL);
}
int digital_tg_listen_nfcf(struct nfc_digital_dev *ddev, u8 rf_tech)
{
int rc;
u8 *nfcid2;
rc = digital_tg_configure_hw(ddev, NFC_DIGITAL_CONFIG_RF_TECH, rf_tech);
if (rc)
return rc;
rc = digital_tg_configure_hw(ddev, NFC_DIGITAL_CONFIG_FRAMING,
NFC_DIGITAL_FRAMING_NFCF_NFC_DEP);
if (rc)
return rc;
nfcid2 = kzalloc(NFC_NFCID2_MAXSIZE, GFP_KERNEL);
if (!nfcid2)
return -ENOMEM;
nfcid2[0] = DIGITAL_SENSF_NFCID2_NFC_DEP_B1;
nfcid2[1] = DIGITAL_SENSF_NFCID2_NFC_DEP_B2;
get_random_bytes(nfcid2 + 2, NFC_NFCID2_MAXSIZE - 2);
return digital_tg_listen(ddev, 300, digital_tg_recv_sensf_req, nfcid2);
}
