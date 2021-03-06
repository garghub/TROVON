static inline u8 pn533_checksum(u8 value)
{
return ~value + 1;
}
static u8 pn533_data_checksum(u8 *data, int datalen)
{
u8 sum = 0;
int i;
for (i = 0; i < datalen; i++)
sum += data[i];
return pn533_checksum(sum);
}
static void pn533_tx_frame_ack(struct pn533_frame *frame)
{
frame->preamble = 0;
frame->start_frame = cpu_to_be16(PN533_SOF);
frame->datalen = 0;
frame->datalen_checksum = 0xFF;
frame->data[0] = 0;
}
static void pn533_tx_frame_init(struct pn533_frame *frame, u8 cmd)
{
frame->preamble = 0;
frame->start_frame = cpu_to_be16(PN533_SOF);
PN533_FRAME_IDENTIFIER(frame) = PN533_DIR_OUT;
PN533_FRAME_CMD(frame) = cmd;
frame->datalen = 2;
}
static void pn533_tx_frame_finish(struct pn533_frame *frame)
{
frame->datalen_checksum = pn533_checksum(frame->datalen);
PN533_FRAME_CHECKSUM(frame) =
pn533_data_checksum(frame->data, frame->datalen);
PN533_FRAME_POSTAMBLE(frame) = 0;
}
static bool pn533_rx_frame_is_valid(struct pn533_frame *frame)
{
u8 checksum;
if (frame->start_frame != cpu_to_be16(PN533_SOF))
return false;
checksum = pn533_checksum(frame->datalen);
if (checksum != frame->datalen_checksum)
return false;
checksum = pn533_data_checksum(frame->data, frame->datalen);
if (checksum != PN533_FRAME_CHECKSUM(frame))
return false;
return true;
}
static bool pn533_rx_frame_is_ack(struct pn533_frame *frame)
{
if (frame->start_frame != cpu_to_be16(PN533_SOF))
return false;
if (frame->datalen != 0 || frame->datalen_checksum != 0xFF)
return false;
return true;
}
static bool pn533_rx_frame_is_cmd_response(struct pn533_frame *frame, u8 cmd)
{
return (PN533_FRAME_CMD(frame) == PN533_CMD_RESPONSE(cmd));
}
static void pn533_wq_cmd_complete(struct work_struct *work)
{
struct pn533 *dev = container_of(work, struct pn533, cmd_complete_work);
struct pn533_frame *in_frame;
int rc;
in_frame = dev->wq_in_frame;
if (dev->wq_in_error)
rc = dev->cmd_complete(dev, dev->cmd_complete_arg, NULL,
dev->wq_in_error);
else
rc = dev->cmd_complete(dev, dev->cmd_complete_arg,
PN533_FRAME_CMD_PARAMS_PTR(in_frame),
PN533_FRAME_CMD_PARAMS_LEN(in_frame));
if (rc != -EINPROGRESS)
queue_work(dev->wq, &dev->cmd_work);
}
static void pn533_recv_response(struct urb *urb)
{
struct pn533 *dev = urb->context;
struct pn533_frame *in_frame;
dev->wq_in_frame = NULL;
switch (urb->status) {
case 0:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
nfc_dev_dbg(&dev->interface->dev, "Urb shutting down with"
" status: %d", urb->status);
dev->wq_in_error = urb->status;
goto sched_wq;
default:
nfc_dev_err(&dev->interface->dev, "Nonzero urb status received:"
" %d", urb->status);
dev->wq_in_error = urb->status;
goto sched_wq;
}
in_frame = dev->in_urb->transfer_buffer;
if (!pn533_rx_frame_is_valid(in_frame)) {
nfc_dev_err(&dev->interface->dev, "Received an invalid frame");
dev->wq_in_error = -EIO;
goto sched_wq;
}
if (!pn533_rx_frame_is_cmd_response(in_frame, dev->cmd)) {
nfc_dev_err(&dev->interface->dev, "The received frame is not "
"response to the last command");
dev->wq_in_error = -EIO;
goto sched_wq;
}
nfc_dev_dbg(&dev->interface->dev, "Received a valid frame");
dev->wq_in_error = 0;
dev->wq_in_frame = in_frame;
sched_wq:
queue_work(dev->wq, &dev->cmd_complete_work);
}
static int pn533_submit_urb_for_response(struct pn533 *dev, gfp_t flags)
{
dev->in_urb->complete = pn533_recv_response;
return usb_submit_urb(dev->in_urb, flags);
}
static void pn533_recv_ack(struct urb *urb)
{
struct pn533 *dev = urb->context;
struct pn533_frame *in_frame;
int rc;
switch (urb->status) {
case 0:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
nfc_dev_dbg(&dev->interface->dev, "Urb shutting down with"
" status: %d", urb->status);
dev->wq_in_error = urb->status;
goto sched_wq;
default:
nfc_dev_err(&dev->interface->dev, "Nonzero urb status received:"
" %d", urb->status);
dev->wq_in_error = urb->status;
goto sched_wq;
}
in_frame = dev->in_urb->transfer_buffer;
if (!pn533_rx_frame_is_ack(in_frame)) {
nfc_dev_err(&dev->interface->dev, "Received an invalid ack");
dev->wq_in_error = -EIO;
goto sched_wq;
}
nfc_dev_dbg(&dev->interface->dev, "Received a valid ack");
rc = pn533_submit_urb_for_response(dev, GFP_ATOMIC);
if (rc) {
nfc_dev_err(&dev->interface->dev, "usb_submit_urb failed with"
" result %d", rc);
dev->wq_in_error = rc;
goto sched_wq;
}
return;
sched_wq:
dev->wq_in_frame = NULL;
queue_work(dev->wq, &dev->cmd_complete_work);
}
static int pn533_submit_urb_for_ack(struct pn533 *dev, gfp_t flags)
{
dev->in_urb->complete = pn533_recv_ack;
return usb_submit_urb(dev->in_urb, flags);
}
static int pn533_send_ack(struct pn533 *dev, gfp_t flags)
{
int rc;
nfc_dev_dbg(&dev->interface->dev, "%s", __func__);
pn533_tx_frame_ack(dev->out_frame);
dev->out_urb->transfer_buffer = dev->out_frame;
dev->out_urb->transfer_buffer_length = PN533_FRAME_ACK_SIZE;
rc = usb_submit_urb(dev->out_urb, flags);
return rc;
}
static int __pn533_send_cmd_frame_async(struct pn533 *dev,
struct pn533_frame *out_frame,
struct pn533_frame *in_frame,
int in_frame_len,
pn533_cmd_complete_t cmd_complete,
void *arg, gfp_t flags)
{
int rc;
nfc_dev_dbg(&dev->interface->dev, "Sending command 0x%x",
PN533_FRAME_CMD(out_frame));
dev->cmd = PN533_FRAME_CMD(out_frame);
dev->cmd_complete = cmd_complete;
dev->cmd_complete_arg = arg;
dev->out_urb->transfer_buffer = out_frame;
dev->out_urb->transfer_buffer_length =
PN533_FRAME_SIZE(out_frame);
dev->in_urb->transfer_buffer = in_frame;
dev->in_urb->transfer_buffer_length = in_frame_len;
rc = usb_submit_urb(dev->out_urb, flags);
if (rc)
return rc;
rc = pn533_submit_urb_for_ack(dev, flags);
if (rc)
goto error;
return 0;
error:
usb_unlink_urb(dev->out_urb);
return rc;
}
static void pn533_wq_cmd(struct work_struct *work)
{
struct pn533 *dev = container_of(work, struct pn533, cmd_work);
struct pn533_cmd *cmd;
mutex_lock(&dev->cmd_lock);
if (list_empty(&dev->cmd_queue)) {
dev->cmd_pending = 0;
mutex_unlock(&dev->cmd_lock);
return;
}
cmd = list_first_entry(&dev->cmd_queue, struct pn533_cmd, queue);
list_del(&cmd->queue);
mutex_unlock(&dev->cmd_lock);
__pn533_send_cmd_frame_async(dev, cmd->out_frame, cmd->in_frame,
cmd->in_frame_len, cmd->cmd_complete,
cmd->arg, cmd->flags);
kfree(cmd);
}
static int pn533_send_cmd_frame_async(struct pn533 *dev,
struct pn533_frame *out_frame,
struct pn533_frame *in_frame,
int in_frame_len,
pn533_cmd_complete_t cmd_complete,
void *arg, gfp_t flags)
{
struct pn533_cmd *cmd;
int rc = 0;
nfc_dev_dbg(&dev->interface->dev, "%s", __func__);
mutex_lock(&dev->cmd_lock);
if (!dev->cmd_pending) {
rc = __pn533_send_cmd_frame_async(dev, out_frame, in_frame,
in_frame_len, cmd_complete,
arg, flags);
if (!rc)
dev->cmd_pending = 1;
goto unlock;
}
nfc_dev_dbg(&dev->interface->dev, "%s Queueing command", __func__);
cmd = kzalloc(sizeof(struct pn533_cmd), flags);
if (!cmd) {
rc = -ENOMEM;
goto unlock;
}
INIT_LIST_HEAD(&cmd->queue);
cmd->out_frame = out_frame;
cmd->in_frame = in_frame;
cmd->in_frame_len = in_frame_len;
cmd->cmd_complete = cmd_complete;
cmd->arg = arg;
cmd->flags = flags;
list_add_tail(&cmd->queue, &dev->cmd_queue);
unlock:
mutex_unlock(&dev->cmd_lock);
return rc;
}
static int pn533_sync_cmd_complete(struct pn533 *dev, void *_arg,
u8 *params, int params_len)
{
struct pn533_sync_cmd_response *arg = _arg;
nfc_dev_dbg(&dev->interface->dev, "%s", __func__);
arg->rc = 0;
if (params_len < 0)
arg->rc = params_len;
complete(&arg->done);
return 0;
}
static int pn533_send_cmd_frame_sync(struct pn533 *dev,
struct pn533_frame *out_frame,
struct pn533_frame *in_frame,
int in_frame_len)
{
int rc;
struct pn533_sync_cmd_response arg;
nfc_dev_dbg(&dev->interface->dev, "%s", __func__);
init_completion(&arg.done);
rc = pn533_send_cmd_frame_async(dev, out_frame, in_frame, in_frame_len,
pn533_sync_cmd_complete, &arg, GFP_KERNEL);
if (rc)
return rc;
wait_for_completion(&arg.done);
return arg.rc;
}
static void pn533_send_complete(struct urb *urb)
{
struct pn533 *dev = urb->context;
nfc_dev_dbg(&dev->interface->dev, "%s", __func__);
switch (urb->status) {
case 0:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
nfc_dev_dbg(&dev->interface->dev, "Urb shutting down with"
" status: %d", urb->status);
break;
default:
nfc_dev_dbg(&dev->interface->dev, "Nonzero urb status received:"
" %d", urb->status);
}
}
static bool pn533_target_type_a_is_valid(struct pn533_target_type_a *type_a,
int target_data_len)
{
u8 ssd;
u8 platconf;
if (target_data_len < sizeof(struct pn533_target_type_a))
return false;
ssd = PN533_TYPE_A_SENS_RES_SSD(type_a->sens_res);
platconf = PN533_TYPE_A_SENS_RES_PLATCONF(type_a->sens_res);
if ((ssd == PN533_TYPE_A_SENS_RES_SSD_JEWEL &&
platconf != PN533_TYPE_A_SENS_RES_PLATCONF_JEWEL) ||
(ssd != PN533_TYPE_A_SENS_RES_SSD_JEWEL &&
platconf == PN533_TYPE_A_SENS_RES_PLATCONF_JEWEL))
return false;
if (PN533_TYPE_A_SEL_CASCADE(type_a->sel_res) != 0)
return false;
return true;
}
static int pn533_target_found_type_a(struct nfc_target *nfc_tgt, u8 *tgt_data,
int tgt_data_len)
{
struct pn533_target_type_a *tgt_type_a;
tgt_type_a = (struct pn533_target_type_a *) tgt_data;
if (!pn533_target_type_a_is_valid(tgt_type_a, tgt_data_len))
return -EPROTO;
switch (PN533_TYPE_A_SEL_PROT(tgt_type_a->sel_res)) {
case PN533_TYPE_A_SEL_PROT_MIFARE:
nfc_tgt->supported_protocols = NFC_PROTO_MIFARE_MASK;
break;
case PN533_TYPE_A_SEL_PROT_ISO14443:
nfc_tgt->supported_protocols = NFC_PROTO_ISO14443_MASK;
break;
case PN533_TYPE_A_SEL_PROT_DEP:
nfc_tgt->supported_protocols = NFC_PROTO_NFC_DEP_MASK;
break;
case PN533_TYPE_A_SEL_PROT_ISO14443_DEP:
nfc_tgt->supported_protocols = NFC_PROTO_ISO14443_MASK |
NFC_PROTO_NFC_DEP_MASK;
break;
}
nfc_tgt->sens_res = be16_to_cpu(tgt_type_a->sens_res);
nfc_tgt->sel_res = tgt_type_a->sel_res;
nfc_tgt->nfcid1_len = tgt_type_a->nfcid_len;
memcpy(nfc_tgt->nfcid1, tgt_type_a->nfcid_data, nfc_tgt->nfcid1_len);
return 0;
}
static bool pn533_target_felica_is_valid(struct pn533_target_felica *felica,
int target_data_len)
{
if (target_data_len < sizeof(struct pn533_target_felica))
return false;
if (felica->opcode != PN533_FELICA_OPC_SENSF_RES)
return false;
return true;
}
static int pn533_target_found_felica(struct nfc_target *nfc_tgt, u8 *tgt_data,
int tgt_data_len)
{
struct pn533_target_felica *tgt_felica;
tgt_felica = (struct pn533_target_felica *) tgt_data;
if (!pn533_target_felica_is_valid(tgt_felica, tgt_data_len))
return -EPROTO;
if (tgt_felica->nfcid2[0] == PN533_FELICA_SENSF_NFCID2_DEP_B1 &&
tgt_felica->nfcid2[1] ==
PN533_FELICA_SENSF_NFCID2_DEP_B2)
nfc_tgt->supported_protocols = NFC_PROTO_NFC_DEP_MASK;
else
nfc_tgt->supported_protocols = NFC_PROTO_FELICA_MASK;
memcpy(nfc_tgt->sensf_res, &tgt_felica->opcode, 9);
nfc_tgt->sensf_res_len = 9;
return 0;
}
static bool pn533_target_jewel_is_valid(struct pn533_target_jewel *jewel,
int target_data_len)
{
u8 ssd;
u8 platconf;
if (target_data_len < sizeof(struct pn533_target_jewel))
return false;
ssd = PN533_TYPE_A_SENS_RES_SSD(jewel->sens_res);
platconf = PN533_TYPE_A_SENS_RES_PLATCONF(jewel->sens_res);
if ((ssd == PN533_TYPE_A_SENS_RES_SSD_JEWEL &&
platconf != PN533_TYPE_A_SENS_RES_PLATCONF_JEWEL) ||
(ssd != PN533_TYPE_A_SENS_RES_SSD_JEWEL &&
platconf == PN533_TYPE_A_SENS_RES_PLATCONF_JEWEL))
return false;
return true;
}
static int pn533_target_found_jewel(struct nfc_target *nfc_tgt, u8 *tgt_data,
int tgt_data_len)
{
struct pn533_target_jewel *tgt_jewel;
tgt_jewel = (struct pn533_target_jewel *) tgt_data;
if (!pn533_target_jewel_is_valid(tgt_jewel, tgt_data_len))
return -EPROTO;
nfc_tgt->supported_protocols = NFC_PROTO_JEWEL_MASK;
nfc_tgt->sens_res = be16_to_cpu(tgt_jewel->sens_res);
nfc_tgt->nfcid1_len = 4;
memcpy(nfc_tgt->nfcid1, tgt_jewel->jewelid, nfc_tgt->nfcid1_len);
return 0;
}
static bool pn533_target_type_b_is_valid(struct pn533_target_type_b *type_b,
int target_data_len)
{
if (target_data_len < sizeof(struct pn533_target_type_b))
return false;
if (type_b->sensb_res.opcode != PN533_TYPE_B_OPC_SENSB_RES)
return false;
if (PN533_TYPE_B_PROT_TYPE(type_b->sensb_res.prot_info.fsci_type) &
PN533_TYPE_B_PROT_TYPE_RFU_MASK)
return false;
return true;
}
static int pn533_target_found_type_b(struct nfc_target *nfc_tgt, u8 *tgt_data,
int tgt_data_len)
{
struct pn533_target_type_b *tgt_type_b;
tgt_type_b = (struct pn533_target_type_b *) tgt_data;
if (!pn533_target_type_b_is_valid(tgt_type_b, tgt_data_len))
return -EPROTO;
nfc_tgt->supported_protocols = NFC_PROTO_ISO14443_B_MASK;
return 0;
}
static int pn533_target_found(struct pn533 *dev,
struct pn533_poll_response *resp, int resp_len)
{
int target_data_len;
struct nfc_target nfc_tgt;
int rc;
nfc_dev_dbg(&dev->interface->dev, "%s - modulation=%d", __func__,
dev->poll_mod_curr);
if (resp->tg != 1)
return -EPROTO;
memset(&nfc_tgt, 0, sizeof(struct nfc_target));
target_data_len = resp_len - sizeof(struct pn533_poll_response);
switch (dev->poll_mod_curr) {
case PN533_POLL_MOD_106KBPS_A:
rc = pn533_target_found_type_a(&nfc_tgt, resp->target_data,
target_data_len);
break;
case PN533_POLL_MOD_212KBPS_FELICA:
case PN533_POLL_MOD_424KBPS_FELICA:
rc = pn533_target_found_felica(&nfc_tgt, resp->target_data,
target_data_len);
break;
case PN533_POLL_MOD_106KBPS_JEWEL:
rc = pn533_target_found_jewel(&nfc_tgt, resp->target_data,
target_data_len);
break;
case PN533_POLL_MOD_847KBPS_B:
rc = pn533_target_found_type_b(&nfc_tgt, resp->target_data,
target_data_len);
break;
default:
nfc_dev_err(&dev->interface->dev, "Unknown current poll"
" modulation");
return -EPROTO;
}
if (rc)
return rc;
if (!(nfc_tgt.supported_protocols & dev->poll_protocols)) {
nfc_dev_dbg(&dev->interface->dev, "The target found does not"
" have the desired protocol");
return -EAGAIN;
}
nfc_dev_dbg(&dev->interface->dev, "Target found - supported protocols: "
"0x%x", nfc_tgt.supported_protocols);
dev->tgt_available_prots = nfc_tgt.supported_protocols;
nfc_targets_found(dev->nfc_dev, &nfc_tgt, 1);
return 0;
}
static inline void pn533_poll_next_mod(struct pn533 *dev)
{
dev->poll_mod_curr = (dev->poll_mod_curr + 1) % dev->poll_mod_count;
}
static void pn533_poll_reset_mod_list(struct pn533 *dev)
{
dev->poll_mod_count = 0;
}
static void pn533_poll_add_mod(struct pn533 *dev, u8 mod_index)
{
dev->poll_mod_active[dev->poll_mod_count] =
(struct pn533_poll_modulations *) &poll_mod[mod_index];
dev->poll_mod_count++;
}
static void pn533_poll_create_mod_list(struct pn533 *dev,
u32 im_protocols, u32 tm_protocols)
{
pn533_poll_reset_mod_list(dev);
if (im_protocols & NFC_PROTO_MIFARE_MASK
|| im_protocols & NFC_PROTO_ISO14443_MASK
|| im_protocols & NFC_PROTO_NFC_DEP_MASK)
pn533_poll_add_mod(dev, PN533_POLL_MOD_106KBPS_A);
if (im_protocols & NFC_PROTO_FELICA_MASK
|| im_protocols & NFC_PROTO_NFC_DEP_MASK) {
pn533_poll_add_mod(dev, PN533_POLL_MOD_212KBPS_FELICA);
pn533_poll_add_mod(dev, PN533_POLL_MOD_424KBPS_FELICA);
}
if (im_protocols & NFC_PROTO_JEWEL_MASK)
pn533_poll_add_mod(dev, PN533_POLL_MOD_106KBPS_JEWEL);
if (im_protocols & NFC_PROTO_ISO14443_B_MASK)
pn533_poll_add_mod(dev, PN533_POLL_MOD_847KBPS_B);
if (tm_protocols)
pn533_poll_add_mod(dev, PN533_LISTEN_MOD);
}
static int pn533_start_poll_complete(struct pn533 *dev, u8 *params, int params_len)
{
struct pn533_poll_response *resp;
int rc;
nfc_dev_dbg(&dev->interface->dev, "%s", __func__);
resp = (struct pn533_poll_response *) params;
if (resp->nbtg) {
rc = pn533_target_found(dev, resp, params_len);
if (rc == 0) {
pn533_poll_reset_mod_list(dev);
return 0;
}
}
return -EAGAIN;
}
static int pn533_init_target_frame(struct pn533_frame *frame,
u8 *gb, size_t gb_len)
{
struct pn533_cmd_init_target *cmd;
size_t cmd_len;
u8 felica_params[18] = {0x1, 0xfe,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0xff, 0xff};
u8 mifare_params[6] = {0x1, 0x1,
0x0, 0x0, 0x0,
0x40};
cmd_len = sizeof(struct pn533_cmd_init_target) + gb_len + 1;
cmd = kzalloc(cmd_len, GFP_KERNEL);
if (cmd == NULL)
return -ENOMEM;
pn533_tx_frame_init(frame, PN533_CMD_TG_INIT_AS_TARGET);
cmd->mode |= PN533_INIT_TARGET_DEP;
memcpy(cmd->felica, felica_params, 18);
get_random_bytes(cmd->felica + 2, 6);
memset(cmd->nfcid3, 0, 10);
memcpy(cmd->nfcid3, cmd->felica, 8);
memcpy(cmd->mifare, mifare_params, 6);
cmd->gb_len = gb_len;
memcpy(cmd->gb, gb, gb_len);
cmd->gb[gb_len] = 0;
memcpy(PN533_FRAME_CMD_PARAMS_PTR(frame), cmd, cmd_len);
frame->datalen += cmd_len;
pn533_tx_frame_finish(frame);
kfree(cmd);
return 0;
}
static int pn533_tm_get_data_complete(struct pn533 *dev, void *arg,
u8 *params, int params_len)
{
struct sk_buff *skb_resp = arg;
struct pn533_frame *in_frame = (struct pn533_frame *) skb_resp->data;
nfc_dev_dbg(&dev->interface->dev, "%s", __func__);
if (params_len < 0) {
nfc_dev_err(&dev->interface->dev,
"Error %d when starting as a target",
params_len);
return params_len;
}
if (params_len > 0 && params[0] != 0) {
nfc_tm_deactivated(dev->nfc_dev);
dev->tgt_mode = 0;
kfree_skb(skb_resp);
return 0;
}
skb_put(skb_resp, PN533_FRAME_SIZE(in_frame));
skb_pull(skb_resp, PN533_CMD_DATAEXCH_HEAD_LEN);
skb_trim(skb_resp, skb_resp->len - PN533_FRAME_TAIL_SIZE);
return nfc_tm_data_received(dev->nfc_dev, skb_resp);
}
static void pn533_wq_tg_get_data(struct work_struct *work)
{
struct pn533 *dev = container_of(work, struct pn533, tg_work);
struct pn533_frame *in_frame;
struct sk_buff *skb_resp;
size_t skb_resp_len;
nfc_dev_dbg(&dev->interface->dev, "%s", __func__);
skb_resp_len = PN533_CMD_DATAEXCH_HEAD_LEN +
PN533_CMD_DATAEXCH_DATA_MAXLEN +
PN533_FRAME_TAIL_SIZE;
skb_resp = nfc_alloc_recv_skb(skb_resp_len, GFP_KERNEL);
if (!skb_resp)
return;
in_frame = (struct pn533_frame *)skb_resp->data;
pn533_tx_frame_init(dev->out_frame, PN533_CMD_TG_GET_DATA);
pn533_tx_frame_finish(dev->out_frame);
pn533_send_cmd_frame_async(dev, dev->out_frame, in_frame,
skb_resp_len,
pn533_tm_get_data_complete,
skb_resp, GFP_KERNEL);
return;
}
static int pn533_init_target_complete(struct pn533 *dev, u8 *params, int params_len)
{
struct pn533_cmd_init_target_response *resp;
u8 frame, comm_mode = NFC_COMM_PASSIVE, *gb;
size_t gb_len;
int rc;
nfc_dev_dbg(&dev->interface->dev, "%s", __func__);
if (params_len < 0) {
nfc_dev_err(&dev->interface->dev,
"Error %d when starting as a target",
params_len);
return params_len;
}
if (params_len < ATR_REQ_GB_OFFSET + 1)
return -EINVAL;
resp = (struct pn533_cmd_init_target_response *) params;
nfc_dev_dbg(&dev->interface->dev, "Target mode 0x%x param len %d\n",
resp->mode, params_len);
frame = resp->mode & PN533_INIT_TARGET_RESP_FRAME_MASK;
if (frame == PN533_INIT_TARGET_RESP_ACTIVE)
comm_mode = NFC_COMM_ACTIVE;
if ((resp->mode & PN533_INIT_TARGET_RESP_DEP) == 0)
return -EOPNOTSUPP;
gb = resp->cmd + ATR_REQ_GB_OFFSET;
gb_len = params_len - (ATR_REQ_GB_OFFSET + 1);
rc = nfc_tm_activated(dev->nfc_dev, NFC_PROTO_NFC_DEP_MASK,
comm_mode, gb, gb_len);
if (rc < 0) {
nfc_dev_err(&dev->interface->dev,
"Error when signaling target activation");
return rc;
}
dev->tgt_mode = 1;
queue_work(dev->wq, &dev->tg_work);
return 0;
}
static void pn533_listen_mode_timer(unsigned long data)
{
struct pn533 *dev = (struct pn533 *) data;
nfc_dev_dbg(&dev->interface->dev, "Listen mode timeout");
pn533_send_ack(dev, GFP_ATOMIC);
dev->cancel_listen = 1;
pn533_poll_next_mod(dev);
queue_work(dev->wq, &dev->poll_work);
}
static int pn533_poll_complete(struct pn533 *dev, void *arg,
u8 *params, int params_len)
{
struct pn533_poll_modulations *cur_mod;
int rc;
nfc_dev_dbg(&dev->interface->dev, "%s", __func__);
if (params_len == -ENOENT) {
if (dev->poll_mod_count != 0)
return 0;
nfc_dev_err(&dev->interface->dev,
"Polling operation has been stopped");
goto stop_poll;
}
if (params_len < 0) {
nfc_dev_err(&dev->interface->dev,
"Error %d when running poll", params_len);
goto stop_poll;
}
cur_mod = dev->poll_mod_active[dev->poll_mod_curr];
if (cur_mod->len == 0) {
del_timer(&dev->listen_timer);
return pn533_init_target_complete(dev, params, params_len);
} else {
rc = pn533_start_poll_complete(dev, params, params_len);
if (!rc)
return rc;
}
pn533_poll_next_mod(dev);
queue_work(dev->wq, &dev->poll_work);
return 0;
stop_poll:
pn533_poll_reset_mod_list(dev);
dev->poll_protocols = 0;
return 0;
}
static void pn533_build_poll_frame(struct pn533 *dev,
struct pn533_frame *frame,
struct pn533_poll_modulations *mod)
{
nfc_dev_dbg(&dev->interface->dev, "mod len %d\n", mod->len);
if (mod->len == 0) {
pn533_init_target_frame(frame, dev->gb, dev->gb_len);
} else {
pn533_tx_frame_init(frame, PN533_CMD_IN_LIST_PASSIVE_TARGET);
memcpy(PN533_FRAME_CMD_PARAMS_PTR(frame), &mod->data, mod->len);
frame->datalen += mod->len;
pn533_tx_frame_finish(frame);
}
}
static int pn533_send_poll_frame(struct pn533 *dev)
{
struct pn533_poll_modulations *cur_mod;
int rc;
cur_mod = dev->poll_mod_active[dev->poll_mod_curr];
pn533_build_poll_frame(dev, dev->out_frame, cur_mod);
rc = pn533_send_cmd_frame_async(dev, dev->out_frame, dev->in_frame,
dev->in_maxlen, pn533_poll_complete,
NULL, GFP_KERNEL);
if (rc)
nfc_dev_err(&dev->interface->dev, "Polling loop error %d", rc);
return rc;
}
static void pn533_wq_poll(struct work_struct *work)
{
struct pn533 *dev = container_of(work, struct pn533, poll_work);
struct pn533_poll_modulations *cur_mod;
int rc;
cur_mod = dev->poll_mod_active[dev->poll_mod_curr];
nfc_dev_dbg(&dev->interface->dev,
"%s cancel_listen %d modulation len %d",
__func__, dev->cancel_listen, cur_mod->len);
if (dev->cancel_listen == 1) {
dev->cancel_listen = 0;
usb_kill_urb(dev->in_urb);
}
rc = pn533_send_poll_frame(dev);
if (rc)
return;
if (cur_mod->len == 0 && dev->poll_mod_count > 1)
mod_timer(&dev->listen_timer, jiffies + PN533_LISTEN_TIME * HZ);
return;
}
static int pn533_start_poll(struct nfc_dev *nfc_dev,
u32 im_protocols, u32 tm_protocols)
{
struct pn533 *dev = nfc_get_drvdata(nfc_dev);
nfc_dev_dbg(&dev->interface->dev,
"%s: im protocols 0x%x tm protocols 0x%x",
__func__, im_protocols, tm_protocols);
if (dev->tgt_active_prot) {
nfc_dev_err(&dev->interface->dev,
"Cannot poll with a target already activated");
return -EBUSY;
}
if (dev->tgt_mode) {
nfc_dev_err(&dev->interface->dev,
"Cannot poll while already being activated");
return -EBUSY;
}
if (tm_protocols) {
dev->gb = nfc_get_local_general_bytes(nfc_dev, &dev->gb_len);
if (dev->gb == NULL)
tm_protocols = 0;
}
dev->poll_mod_curr = 0;
pn533_poll_create_mod_list(dev, im_protocols, tm_protocols);
dev->poll_protocols = im_protocols;
dev->listen_protocols = tm_protocols;
return pn533_send_poll_frame(dev);
}
static void pn533_stop_poll(struct nfc_dev *nfc_dev)
{
struct pn533 *dev = nfc_get_drvdata(nfc_dev);
nfc_dev_dbg(&dev->interface->dev, "%s", __func__);
del_timer(&dev->listen_timer);
if (!dev->poll_mod_count) {
nfc_dev_dbg(&dev->interface->dev, "Polling operation was not"
" running");
return;
}
pn533_send_ack(dev, GFP_KERNEL);
usb_kill_urb(dev->in_urb);
pn533_poll_reset_mod_list(dev);
}
static int pn533_activate_target_nfcdep(struct pn533 *dev)
{
struct pn533_cmd_activate_param param;
struct pn533_cmd_activate_response *resp;
u16 gt_len;
int rc;
nfc_dev_dbg(&dev->interface->dev, "%s", __func__);
pn533_tx_frame_init(dev->out_frame, PN533_CMD_IN_ATR);
param.tg = 1;
param.next = 0;
memcpy(PN533_FRAME_CMD_PARAMS_PTR(dev->out_frame), &param,
sizeof(struct pn533_cmd_activate_param));
dev->out_frame->datalen += sizeof(struct pn533_cmd_activate_param);
pn533_tx_frame_finish(dev->out_frame);
rc = pn533_send_cmd_frame_sync(dev, dev->out_frame, dev->in_frame,
dev->in_maxlen);
if (rc)
return rc;
resp = (struct pn533_cmd_activate_response *)
PN533_FRAME_CMD_PARAMS_PTR(dev->in_frame);
rc = resp->status & PN533_CMD_RET_MASK;
if (rc != PN533_CMD_RET_SUCCESS)
return -EIO;
gt_len = PN533_FRAME_CMD_PARAMS_LEN(dev->in_frame) - 16;
rc = nfc_set_remote_general_bytes(dev->nfc_dev, resp->gt, gt_len);
return rc;
}
static int pn533_activate_target(struct nfc_dev *nfc_dev,
struct nfc_target *target, u32 protocol)
{
struct pn533 *dev = nfc_get_drvdata(nfc_dev);
int rc;
nfc_dev_dbg(&dev->interface->dev, "%s - protocol=%u", __func__,
protocol);
if (dev->poll_mod_count) {
nfc_dev_err(&dev->interface->dev, "Cannot activate while"
" polling");
return -EBUSY;
}
if (dev->tgt_active_prot) {
nfc_dev_err(&dev->interface->dev, "There is already an active"
" target");
return -EBUSY;
}
if (!dev->tgt_available_prots) {
nfc_dev_err(&dev->interface->dev, "There is no available target"
" to activate");
return -EINVAL;
}
if (!(dev->tgt_available_prots & (1 << protocol))) {
nfc_dev_err(&dev->interface->dev, "The target does not support"
" the requested protocol %u", protocol);
return -EINVAL;
}
if (protocol == NFC_PROTO_NFC_DEP) {
rc = pn533_activate_target_nfcdep(dev);
if (rc) {
nfc_dev_err(&dev->interface->dev, "Error %d when"
" activating target with"
" NFC_DEP protocol", rc);
return rc;
}
}
dev->tgt_active_prot = protocol;
dev->tgt_available_prots = 0;
return 0;
}
static void pn533_deactivate_target(struct nfc_dev *nfc_dev,
struct nfc_target *target)
{
struct pn533 *dev = nfc_get_drvdata(nfc_dev);
u8 tg;
u8 status;
int rc;
nfc_dev_dbg(&dev->interface->dev, "%s", __func__);
if (!dev->tgt_active_prot) {
nfc_dev_err(&dev->interface->dev, "There is no active target");
return;
}
dev->tgt_active_prot = 0;
skb_queue_purge(&dev->resp_q);
pn533_tx_frame_init(dev->out_frame, PN533_CMD_IN_RELEASE);
tg = 1;
memcpy(PN533_FRAME_CMD_PARAMS_PTR(dev->out_frame), &tg, sizeof(u8));
dev->out_frame->datalen += sizeof(u8);
pn533_tx_frame_finish(dev->out_frame);
rc = pn533_send_cmd_frame_sync(dev, dev->out_frame, dev->in_frame,
dev->in_maxlen);
if (rc) {
nfc_dev_err(&dev->interface->dev, "Error when sending release"
" command to the controller");
return;
}
status = PN533_FRAME_CMD_PARAMS_PTR(dev->in_frame)[0];
rc = status & PN533_CMD_RET_MASK;
if (rc != PN533_CMD_RET_SUCCESS)
nfc_dev_err(&dev->interface->dev, "Error 0x%x when releasing"
" the target", rc);
return;
}
static int pn533_in_dep_link_up_complete(struct pn533 *dev, void *arg,
u8 *params, int params_len)
{
struct pn533_cmd_jump_dep_response *resp;
struct nfc_target nfc_target;
u8 target_gt_len;
int rc;
struct pn533_cmd_jump_dep *cmd = (struct pn533_cmd_jump_dep *)arg;
u8 active = cmd->active;
kfree(arg);
if (params_len == -ENOENT) {
nfc_dev_dbg(&dev->interface->dev, "");
return 0;
}
if (params_len < 0) {
nfc_dev_err(&dev->interface->dev,
"Error %d when bringing DEP link up",
params_len);
return 0;
}
if (dev->tgt_available_prots &&
!(dev->tgt_available_prots & (1 << NFC_PROTO_NFC_DEP))) {
nfc_dev_err(&dev->interface->dev,
"The target does not support DEP");
return -EINVAL;
}
resp = (struct pn533_cmd_jump_dep_response *) params;
rc = resp->status & PN533_CMD_RET_MASK;
if (rc != PN533_CMD_RET_SUCCESS) {
nfc_dev_err(&dev->interface->dev,
"Bringing DEP link up failed %d", rc);
return 0;
}
if (!dev->tgt_available_prots) {
nfc_dev_dbg(&dev->interface->dev, "Creating new target");
nfc_target.supported_protocols = NFC_PROTO_NFC_DEP_MASK;
nfc_target.nfcid1_len = 10;
memcpy(nfc_target.nfcid1, resp->nfcid3t, nfc_target.nfcid1_len);
rc = nfc_targets_found(dev->nfc_dev, &nfc_target, 1);
if (rc)
return 0;
dev->tgt_available_prots = 0;
}
dev->tgt_active_prot = NFC_PROTO_NFC_DEP;
target_gt_len = PN533_FRAME_CMD_PARAMS_LEN(dev->in_frame) - 17;
rc = nfc_set_remote_general_bytes(dev->nfc_dev,
resp->gt, target_gt_len);
if (rc == 0)
rc = nfc_dep_link_is_up(dev->nfc_dev,
dev->nfc_dev->targets[0].idx,
!active, NFC_RF_INITIATOR);
return 0;
}
static int pn533_mod_to_baud(struct pn533 *dev)
{
switch (dev->poll_mod_curr) {
case PN533_POLL_MOD_106KBPS_A:
return 0;
case PN533_POLL_MOD_212KBPS_FELICA:
return 1;
case PN533_POLL_MOD_424KBPS_FELICA:
return 2;
default:
return -EINVAL;
}
}
static int pn533_dep_link_up(struct nfc_dev *nfc_dev, struct nfc_target *target,
u8 comm_mode, u8* gb, size_t gb_len)
{
struct pn533 *dev = nfc_get_drvdata(nfc_dev);
struct pn533_cmd_jump_dep *cmd;
u8 cmd_len, *data_ptr;
u8 passive_data[PASSIVE_DATA_LEN] = {0x00, 0xff, 0xff, 0x00, 0x3};
int rc, baud;
nfc_dev_dbg(&dev->interface->dev, "%s", __func__);
if (dev->poll_mod_count) {
nfc_dev_err(&dev->interface->dev,
"Cannot bring the DEP link up while polling");
return -EBUSY;
}
if (dev->tgt_active_prot) {
nfc_dev_err(&dev->interface->dev,
"There is already an active target");
return -EBUSY;
}
baud = pn533_mod_to_baud(dev);
if (baud < 0) {
nfc_dev_err(&dev->interface->dev,
"Invalid curr modulation %d", dev->poll_mod_curr);
return baud;
}
cmd_len = sizeof(struct pn533_cmd_jump_dep) + gb_len;
if (comm_mode == NFC_COMM_PASSIVE)
cmd_len += PASSIVE_DATA_LEN;
cmd = kzalloc(cmd_len, GFP_KERNEL);
if (cmd == NULL)
return -ENOMEM;
pn533_tx_frame_init(dev->out_frame, PN533_CMD_IN_JUMP_FOR_DEP);
cmd->active = !comm_mode;
cmd->next = 0;
cmd->baud = baud;
data_ptr = cmd->data;
if (comm_mode == NFC_COMM_PASSIVE && cmd->baud > 0) {
memcpy(data_ptr, passive_data, PASSIVE_DATA_LEN);
cmd->next |= 1;
data_ptr += PASSIVE_DATA_LEN;
}
if (gb != NULL && gb_len > 0) {
cmd->next |= 4;
memcpy(data_ptr, gb, gb_len);
} else {
cmd->next = 0;
}
memcpy(PN533_FRAME_CMD_PARAMS_PTR(dev->out_frame), cmd, cmd_len);
dev->out_frame->datalen += cmd_len;
pn533_tx_frame_finish(dev->out_frame);
rc = pn533_send_cmd_frame_async(dev, dev->out_frame, dev->in_frame,
dev->in_maxlen, pn533_in_dep_link_up_complete,
cmd, GFP_KERNEL);
if (rc < 0)
kfree(cmd);
return rc;
}
static int pn533_dep_link_down(struct nfc_dev *nfc_dev)
{
struct pn533 *dev = nfc_get_drvdata(nfc_dev);
pn533_poll_reset_mod_list(dev);
if (dev->tgt_mode || dev->tgt_active_prot) {
pn533_send_ack(dev, GFP_KERNEL);
usb_kill_urb(dev->in_urb);
}
dev->tgt_active_prot = 0;
dev->tgt_mode = 0;
skb_queue_purge(&dev->resp_q);
return 0;
}
static int pn533_build_tx_frame(struct pn533 *dev, struct sk_buff *skb,
bool target)
{
int payload_len = skb->len;
struct pn533_frame *out_frame;
u8 tg;
nfc_dev_dbg(&dev->interface->dev, "%s - Sending %d bytes", __func__,
payload_len);
if (payload_len > PN533_CMD_DATAEXCH_DATA_MAXLEN) {
nfc_dev_err(&dev->interface->dev, "Data length greater than the"
" max allowed: %d",
PN533_CMD_DATAEXCH_DATA_MAXLEN);
return -ENOSYS;
}
if (target == true) {
switch (dev->device_type) {
case PN533_DEVICE_PASORI:
if (dev->tgt_active_prot == NFC_PROTO_FELICA) {
skb_push(skb, PN533_CMD_DATAEXCH_HEAD_LEN - 1);
out_frame = (struct pn533_frame *) skb->data;
pn533_tx_frame_init(out_frame,
PN533_CMD_IN_COMM_THRU);
break;
}
default:
skb_push(skb, PN533_CMD_DATAEXCH_HEAD_LEN);
out_frame = (struct pn533_frame *) skb->data;
pn533_tx_frame_init(out_frame,
PN533_CMD_IN_DATA_EXCHANGE);
tg = 1;
memcpy(PN533_FRAME_CMD_PARAMS_PTR(out_frame),
&tg, sizeof(u8));
out_frame->datalen += sizeof(u8);
break;
}
} else {
skb_push(skb, PN533_CMD_DATAEXCH_HEAD_LEN - 1);
out_frame = (struct pn533_frame *) skb->data;
pn533_tx_frame_init(out_frame, PN533_CMD_TG_SET_DATA);
}
out_frame->datalen += payload_len;
pn533_tx_frame_finish(out_frame);
skb_put(skb, PN533_FRAME_TAIL_SIZE);
return 0;
}
static struct sk_buff *pn533_build_response(struct pn533 *dev)
{
struct sk_buff *skb, *tmp, *t;
unsigned int skb_len = 0, tmp_len = 0;
nfc_dev_dbg(&dev->interface->dev, "%s\n", __func__);
if (skb_queue_empty(&dev->resp_q))
return NULL;
if (skb_queue_len(&dev->resp_q) == 1) {
skb = skb_dequeue(&dev->resp_q);
goto out;
}
skb_queue_walk_safe(&dev->resp_q, tmp, t)
skb_len += tmp->len;
nfc_dev_dbg(&dev->interface->dev, "%s total length %d\n",
__func__, skb_len);
skb = alloc_skb(skb_len, GFP_KERNEL);
if (skb == NULL)
goto out;
skb_put(skb, skb_len);
skb_queue_walk_safe(&dev->resp_q, tmp, t) {
memcpy(skb->data + tmp_len, tmp->data, tmp->len);
tmp_len += tmp->len;
}
out:
skb_queue_purge(&dev->resp_q);
return skb;
}
static int pn533_data_exchange_complete(struct pn533 *dev, void *_arg,
u8 *params, int params_len)
{
struct pn533_data_exchange_arg *arg = _arg;
struct sk_buff *skb = NULL, *skb_resp = arg->skb_resp;
struct pn533_frame *in_frame = (struct pn533_frame *) skb_resp->data;
int err = 0;
u8 status;
u8 cmd_ret;
nfc_dev_dbg(&dev->interface->dev, "%s", __func__);
dev_kfree_skb(arg->skb_out);
if (params_len < 0) {
err = params_len;
goto error;
}
status = params[0];
cmd_ret = status & PN533_CMD_RET_MASK;
if (cmd_ret != PN533_CMD_RET_SUCCESS) {
nfc_dev_err(&dev->interface->dev, "PN533 reported error %d when"
" exchanging data", cmd_ret);
err = -EIO;
goto error;
}
skb_put(skb_resp, PN533_FRAME_SIZE(in_frame));
skb_pull(skb_resp, PN533_CMD_DATAEXCH_HEAD_LEN);
skb_trim(skb_resp, skb_resp->len - PN533_FRAME_TAIL_SIZE);
skb_queue_tail(&dev->resp_q, skb_resp);
if (status & PN533_CMD_MI_MASK) {
queue_work(dev->wq, &dev->mi_work);
return -EINPROGRESS;
}
skb = pn533_build_response(dev);
if (skb == NULL)
goto error;
arg->cb(arg->cb_context, skb, 0);
kfree(arg);
return 0;
error:
skb_queue_purge(&dev->resp_q);
dev_kfree_skb(skb_resp);
arg->cb(arg->cb_context, NULL, err);
kfree(arg);
return 0;
}
static int pn533_transceive(struct nfc_dev *nfc_dev,
struct nfc_target *target, struct sk_buff *skb,
data_exchange_cb_t cb, void *cb_context)
{
struct pn533 *dev = nfc_get_drvdata(nfc_dev);
struct pn533_frame *out_frame, *in_frame;
struct pn533_data_exchange_arg *arg;
struct sk_buff *skb_resp;
int skb_resp_len;
int rc;
nfc_dev_dbg(&dev->interface->dev, "%s", __func__);
if (!dev->tgt_active_prot) {
nfc_dev_err(&dev->interface->dev, "Cannot exchange data if"
" there is no active target");
rc = -EINVAL;
goto error;
}
rc = pn533_build_tx_frame(dev, skb, true);
if (rc)
goto error;
skb_resp_len = PN533_CMD_DATAEXCH_HEAD_LEN +
PN533_CMD_DATAEXCH_DATA_MAXLEN +
PN533_FRAME_TAIL_SIZE;
skb_resp = nfc_alloc_recv_skb(skb_resp_len, GFP_KERNEL);
if (!skb_resp) {
rc = -ENOMEM;
goto error;
}
in_frame = (struct pn533_frame *) skb_resp->data;
out_frame = (struct pn533_frame *) skb->data;
arg = kmalloc(sizeof(struct pn533_data_exchange_arg), GFP_KERNEL);
if (!arg) {
rc = -ENOMEM;
goto free_skb_resp;
}
arg->skb_resp = skb_resp;
arg->skb_out = skb;
arg->cb = cb;
arg->cb_context = cb_context;
rc = pn533_send_cmd_frame_async(dev, out_frame, in_frame, skb_resp_len,
pn533_data_exchange_complete, arg,
GFP_KERNEL);
if (rc) {
nfc_dev_err(&dev->interface->dev, "Error %d when trying to"
" perform data_exchange", rc);
goto free_arg;
}
return 0;
free_arg:
kfree(arg);
free_skb_resp:
kfree_skb(skb_resp);
error:
kfree_skb(skb);
return rc;
}
static int pn533_tm_send_complete(struct pn533 *dev, void *arg,
u8 *params, int params_len)
{
struct sk_buff *skb_out = arg;
nfc_dev_dbg(&dev->interface->dev, "%s", __func__);
dev_kfree_skb(skb_out);
if (params_len < 0) {
nfc_dev_err(&dev->interface->dev,
"Error %d when sending data",
params_len);
return params_len;
}
if (params_len > 0 && params[0] != 0) {
nfc_tm_deactivated(dev->nfc_dev);
dev->tgt_mode = 0;
return 0;
}
queue_work(dev->wq, &dev->tg_work);
return 0;
}
static int pn533_tm_send(struct nfc_dev *nfc_dev, struct sk_buff *skb)
{
struct pn533 *dev = nfc_get_drvdata(nfc_dev);
struct pn533_frame *out_frame;
int rc;
nfc_dev_dbg(&dev->interface->dev, "%s", __func__);
rc = pn533_build_tx_frame(dev, skb, false);
if (rc)
goto error;
out_frame = (struct pn533_frame *) skb->data;
rc = pn533_send_cmd_frame_async(dev, out_frame, dev->in_frame,
dev->in_maxlen, pn533_tm_send_complete,
skb, GFP_KERNEL);
if (rc) {
nfc_dev_err(&dev->interface->dev,
"Error %d when trying to send data", rc);
goto error;
}
return 0;
error:
kfree_skb(skb);
return rc;
}
static void pn533_wq_mi_recv(struct work_struct *work)
{
struct pn533 *dev = container_of(work, struct pn533, mi_work);
struct sk_buff *skb_cmd;
struct pn533_data_exchange_arg *arg = dev->cmd_complete_arg;
struct pn533_frame *out_frame, *in_frame;
struct sk_buff *skb_resp;
int skb_resp_len;
int rc;
nfc_dev_dbg(&dev->interface->dev, "%s", __func__);
skb_cmd = alloc_skb(PN533_CMD_DATAEXCH_HEAD_LEN + PN533_FRAME_TAIL_SIZE,
GFP_KERNEL);
if (skb_cmd == NULL)
goto error_cmd;
skb_reserve(skb_cmd, PN533_CMD_DATAEXCH_HEAD_LEN);
rc = pn533_build_tx_frame(dev, skb_cmd, true);
if (rc)
goto error_frame;
skb_resp_len = PN533_CMD_DATAEXCH_HEAD_LEN +
PN533_CMD_DATAEXCH_DATA_MAXLEN +
PN533_FRAME_TAIL_SIZE;
skb_resp = alloc_skb(skb_resp_len, GFP_KERNEL);
if (!skb_resp) {
rc = -ENOMEM;
goto error_frame;
}
in_frame = (struct pn533_frame *) skb_resp->data;
out_frame = (struct pn533_frame *) skb_cmd->data;
arg->skb_resp = skb_resp;
arg->skb_out = skb_cmd;
rc = __pn533_send_cmd_frame_async(dev, out_frame, in_frame,
skb_resp_len,
pn533_data_exchange_complete,
dev->cmd_complete_arg, GFP_KERNEL);
if (!rc)
return;
nfc_dev_err(&dev->interface->dev, "Error %d when trying to"
" perform data_exchange", rc);
kfree_skb(skb_resp);
error_frame:
kfree_skb(skb_cmd);
error_cmd:
pn533_send_ack(dev, GFP_KERNEL);
kfree(arg);
queue_work(dev->wq, &dev->cmd_work);
}
static int pn533_set_configuration(struct pn533 *dev, u8 cfgitem, u8 *cfgdata,
u8 cfgdata_len)
{
int rc;
u8 *params;
nfc_dev_dbg(&dev->interface->dev, "%s", __func__);
pn533_tx_frame_init(dev->out_frame, PN533_CMD_RF_CONFIGURATION);
params = PN533_FRAME_CMD_PARAMS_PTR(dev->out_frame);
params[0] = cfgitem;
memcpy(&params[1], cfgdata, cfgdata_len);
dev->out_frame->datalen += (1 + cfgdata_len);
pn533_tx_frame_finish(dev->out_frame);
rc = pn533_send_cmd_frame_sync(dev, dev->out_frame, dev->in_frame,
dev->in_maxlen);
return rc;
}
static int pn533_fw_reset(struct pn533 *dev)
{
int rc;
u8 *params;
nfc_dev_dbg(&dev->interface->dev, "%s", __func__);
pn533_tx_frame_init(dev->out_frame, 0x18);
params = PN533_FRAME_CMD_PARAMS_PTR(dev->out_frame);
params[0] = 0x1;
dev->out_frame->datalen += 1;
pn533_tx_frame_finish(dev->out_frame);
rc = pn533_send_cmd_frame_sync(dev, dev->out_frame, dev->in_frame,
dev->in_maxlen);
return rc;
}
static int pn533_setup(struct pn533 *dev)
{
struct pn533_config_max_retries max_retries;
struct pn533_config_timing timing;
u8 pasori_cfg[3] = {0x08, 0x01, 0x08};
int rc;
switch (dev->device_type) {
case PN533_DEVICE_STD:
max_retries.mx_rty_atr = PN533_CONFIG_MAX_RETRIES_ENDLESS;
max_retries.mx_rty_psl = 2;
max_retries.mx_rty_passive_act =
PN533_CONFIG_MAX_RETRIES_NO_RETRY;
timing.rfu = PN533_CONFIG_TIMING_102;
timing.atr_res_timeout = PN533_CONFIG_TIMING_204;
timing.dep_timeout = PN533_CONFIG_TIMING_409;
break;
case PN533_DEVICE_PASORI:
max_retries.mx_rty_atr = 0x2;
max_retries.mx_rty_psl = 0x1;
max_retries.mx_rty_passive_act =
PN533_CONFIG_MAX_RETRIES_NO_RETRY;
timing.rfu = PN533_CONFIG_TIMING_102;
timing.atr_res_timeout = PN533_CONFIG_TIMING_102;
timing.dep_timeout = PN533_CONFIG_TIMING_204;
break;
default:
nfc_dev_err(&dev->interface->dev, "Unknown device type %d\n",
dev->device_type);
return -EINVAL;
}
rc = pn533_set_configuration(dev, PN533_CFGITEM_MAX_RETRIES,
(u8 *)&max_retries, sizeof(max_retries));
if (rc) {
nfc_dev_err(&dev->interface->dev,
"Error on setting MAX_RETRIES config");
return rc;
}
rc = pn533_set_configuration(dev, PN533_CFGITEM_TIMING,
(u8 *)&timing, sizeof(timing));
if (rc) {
nfc_dev_err(&dev->interface->dev,
"Error on setting RF timings");
return rc;
}
switch (dev->device_type) {
case PN533_DEVICE_STD:
break;
case PN533_DEVICE_PASORI:
pn533_fw_reset(dev);
rc = pn533_set_configuration(dev, PN533_CFGITEM_PASORI,
pasori_cfg, 3);
if (rc) {
nfc_dev_err(&dev->interface->dev,
"Error while settings PASORI config");
return rc;
}
pn533_fw_reset(dev);
break;
}
return 0;
}
static int pn533_probe(struct usb_interface *interface,
const struct usb_device_id *id)
{
struct pn533_fw_version *fw_ver;
struct pn533 *dev;
struct usb_host_interface *iface_desc;
struct usb_endpoint_descriptor *endpoint;
int in_endpoint = 0;
int out_endpoint = 0;
int rc = -ENOMEM;
int i;
u32 protocols;
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (!dev)
return -ENOMEM;
dev->udev = usb_get_dev(interface_to_usbdev(interface));
dev->interface = interface;
mutex_init(&dev->cmd_lock);
iface_desc = interface->cur_altsetting;
for (i = 0; i < iface_desc->desc.bNumEndpoints; ++i) {
endpoint = &iface_desc->endpoint[i].desc;
if (!in_endpoint && usb_endpoint_is_bulk_in(endpoint)) {
dev->in_maxlen = le16_to_cpu(endpoint->wMaxPacketSize);
in_endpoint = endpoint->bEndpointAddress;
}
if (!out_endpoint && usb_endpoint_is_bulk_out(endpoint)) {
dev->out_maxlen =
le16_to_cpu(endpoint->wMaxPacketSize);
out_endpoint = endpoint->bEndpointAddress;
}
}
if (!in_endpoint || !out_endpoint) {
nfc_dev_err(&interface->dev, "Could not find bulk-in or"
" bulk-out endpoint");
rc = -ENODEV;
goto error;
}
dev->in_frame = kmalloc(PN533_NORMAL_FRAME_MAX_LEN, GFP_KERNEL);
dev->in_urb = usb_alloc_urb(0, GFP_KERNEL);
dev->out_frame = kmalloc(PN533_NORMAL_FRAME_MAX_LEN, GFP_KERNEL);
dev->out_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!dev->in_frame || !dev->out_frame ||
!dev->in_urb || !dev->out_urb)
goto error;
usb_fill_bulk_urb(dev->in_urb, dev->udev,
usb_rcvbulkpipe(dev->udev, in_endpoint),
NULL, 0, NULL, dev);
usb_fill_bulk_urb(dev->out_urb, dev->udev,
usb_sndbulkpipe(dev->udev, out_endpoint),
NULL, 0,
pn533_send_complete, dev);
INIT_WORK(&dev->cmd_work, pn533_wq_cmd);
INIT_WORK(&dev->cmd_complete_work, pn533_wq_cmd_complete);
INIT_WORK(&dev->mi_work, pn533_wq_mi_recv);
INIT_WORK(&dev->tg_work, pn533_wq_tg_get_data);
INIT_WORK(&dev->poll_work, pn533_wq_poll);
dev->wq = alloc_ordered_workqueue("pn533", 0);
if (dev->wq == NULL)
goto error;
init_timer(&dev->listen_timer);
dev->listen_timer.data = (unsigned long) dev;
dev->listen_timer.function = pn533_listen_mode_timer;
skb_queue_head_init(&dev->resp_q);
INIT_LIST_HEAD(&dev->cmd_queue);
usb_set_intfdata(interface, dev);
pn533_tx_frame_init(dev->out_frame, PN533_CMD_GET_FIRMWARE_VERSION);
pn533_tx_frame_finish(dev->out_frame);
rc = pn533_send_cmd_frame_sync(dev, dev->out_frame, dev->in_frame,
dev->in_maxlen);
if (rc)
goto destroy_wq;
fw_ver = (struct pn533_fw_version *)
PN533_FRAME_CMD_PARAMS_PTR(dev->in_frame);
nfc_dev_info(&dev->interface->dev, "NXP PN533 firmware ver %d.%d now"
" attached", fw_ver->ver, fw_ver->rev);
dev->device_type = id->driver_info;
switch (dev->device_type) {
case PN533_DEVICE_STD:
protocols = PN533_ALL_PROTOCOLS;
break;
case PN533_DEVICE_PASORI:
protocols = PN533_NO_TYPE_B_PROTOCOLS;
break;
default:
nfc_dev_err(&dev->interface->dev, "Unknown device type %d\n",
dev->device_type);
rc = -EINVAL;
goto destroy_wq;
}
dev->nfc_dev = nfc_allocate_device(&pn533_nfc_ops, protocols,
PN533_CMD_DATAEXCH_HEAD_LEN,
PN533_FRAME_TAIL_SIZE);
if (!dev->nfc_dev)
goto destroy_wq;
nfc_set_parent_dev(dev->nfc_dev, &interface->dev);
nfc_set_drvdata(dev->nfc_dev, dev);
rc = nfc_register_device(dev->nfc_dev);
if (rc)
goto free_nfc_dev;
rc = pn533_setup(dev);
if (rc)
goto unregister_nfc_dev;
return 0;
unregister_nfc_dev:
nfc_unregister_device(dev->nfc_dev);
free_nfc_dev:
nfc_free_device(dev->nfc_dev);
destroy_wq:
destroy_workqueue(dev->wq);
error:
kfree(dev->in_frame);
usb_free_urb(dev->in_urb);
kfree(dev->out_frame);
usb_free_urb(dev->out_urb);
kfree(dev);
return rc;
}
static void pn533_disconnect(struct usb_interface *interface)
{
struct pn533 *dev;
struct pn533_cmd *cmd, *n;
dev = usb_get_intfdata(interface);
usb_set_intfdata(interface, NULL);
nfc_unregister_device(dev->nfc_dev);
nfc_free_device(dev->nfc_dev);
usb_kill_urb(dev->in_urb);
usb_kill_urb(dev->out_urb);
destroy_workqueue(dev->wq);
skb_queue_purge(&dev->resp_q);
del_timer(&dev->listen_timer);
list_for_each_entry_safe(cmd, n, &dev->cmd_queue, queue) {
list_del(&cmd->queue);
kfree(cmd);
}
kfree(dev->in_frame);
usb_free_urb(dev->in_urb);
kfree(dev->out_frame);
usb_free_urb(dev->out_urb);
kfree(dev);
nfc_dev_info(&interface->dev, "NXP PN533 NFC device disconnected");
}
