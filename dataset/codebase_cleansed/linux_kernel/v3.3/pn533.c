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
static void pn533_tasklet_cmd_complete(unsigned long arg)
{
struct pn533 *dev = (struct pn533 *) arg;
struct pn533_frame *in_frame = dev->tklt_in_frame;
int rc;
if (dev->tklt_in_error)
rc = dev->cmd_complete(dev, dev->cmd_complete_arg, NULL,
dev->tklt_in_error);
else
rc = dev->cmd_complete(dev, dev->cmd_complete_arg,
PN533_FRAME_CMD_PARAMS_PTR(in_frame),
PN533_FRAME_CMD_PARAMS_LEN(in_frame));
if (rc != -EINPROGRESS)
up(&dev->cmd_lock);
}
static void pn533_recv_response(struct urb *urb)
{
struct pn533 *dev = urb->context;
struct pn533_frame *in_frame;
dev->tklt_in_frame = NULL;
switch (urb->status) {
case 0:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
nfc_dev_dbg(&dev->interface->dev, "Urb shutting down with"
" status: %d", urb->status);
dev->tklt_in_error = urb->status;
goto sched_tasklet;
default:
nfc_dev_err(&dev->interface->dev, "Nonzero urb status received:"
" %d", urb->status);
dev->tklt_in_error = urb->status;
goto sched_tasklet;
}
in_frame = dev->in_urb->transfer_buffer;
if (!pn533_rx_frame_is_valid(in_frame)) {
nfc_dev_err(&dev->interface->dev, "Received an invalid frame");
dev->tklt_in_error = -EIO;
goto sched_tasklet;
}
if (!pn533_rx_frame_is_cmd_response(in_frame, dev->cmd)) {
nfc_dev_err(&dev->interface->dev, "The received frame is not "
"response to the last command");
dev->tklt_in_error = -EIO;
goto sched_tasklet;
}
nfc_dev_dbg(&dev->interface->dev, "Received a valid frame");
dev->tklt_in_error = 0;
dev->tklt_in_frame = in_frame;
sched_tasklet:
tasklet_schedule(&dev->tasklet);
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
dev->tklt_in_error = urb->status;
goto sched_tasklet;
default:
nfc_dev_err(&dev->interface->dev, "Nonzero urb status received:"
" %d", urb->status);
dev->tklt_in_error = urb->status;
goto sched_tasklet;
}
in_frame = dev->in_urb->transfer_buffer;
if (!pn533_rx_frame_is_ack(in_frame)) {
nfc_dev_err(&dev->interface->dev, "Received an invalid ack");
dev->tklt_in_error = -EIO;
goto sched_tasklet;
}
nfc_dev_dbg(&dev->interface->dev, "Received a valid ack");
rc = pn533_submit_urb_for_response(dev, GFP_ATOMIC);
if (rc) {
nfc_dev_err(&dev->interface->dev, "usb_submit_urb failed with"
" result %d", rc);
dev->tklt_in_error = rc;
goto sched_tasklet;
}
return;
sched_tasklet:
dev->tklt_in_frame = NULL;
tasklet_schedule(&dev->tasklet);
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
static int pn533_send_cmd_frame_async(struct pn533 *dev,
struct pn533_frame *out_frame,
struct pn533_frame *in_frame,
int in_frame_len,
pn533_cmd_complete_t cmd_complete,
void *arg, gfp_t flags)
{
int rc;
nfc_dev_dbg(&dev->interface->dev, "%s", __func__);
if (down_trylock(&dev->cmd_lock))
return -EBUSY;
rc = __pn533_send_cmd_frame_async(dev, out_frame, in_frame,
in_frame_len, cmd_complete, arg, flags);
if (rc)
goto error;
return 0;
error:
up(&dev->cmd_lock);
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
nfc_tgt->supported_protocols = NFC_PROTO_ISO14443_MASK;
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
static void pn533_poll_create_mod_list(struct pn533 *dev, u32 protocols)
{
pn533_poll_reset_mod_list(dev);
if (protocols & NFC_PROTO_MIFARE_MASK
|| protocols & NFC_PROTO_ISO14443_MASK
|| protocols & NFC_PROTO_NFC_DEP_MASK)
pn533_poll_add_mod(dev, PN533_POLL_MOD_106KBPS_A);
if (protocols & NFC_PROTO_FELICA_MASK
|| protocols & NFC_PROTO_NFC_DEP_MASK) {
pn533_poll_add_mod(dev, PN533_POLL_MOD_212KBPS_FELICA);
pn533_poll_add_mod(dev, PN533_POLL_MOD_424KBPS_FELICA);
}
if (protocols & NFC_PROTO_JEWEL_MASK)
pn533_poll_add_mod(dev, PN533_POLL_MOD_106KBPS_JEWEL);
if (protocols & NFC_PROTO_ISO14443_MASK)
pn533_poll_add_mod(dev, PN533_POLL_MOD_847KBPS_B);
}
static void pn533_start_poll_frame(struct pn533_frame *frame,
struct pn533_poll_modulations *mod)
{
pn533_tx_frame_init(frame, PN533_CMD_IN_LIST_PASSIVE_TARGET);
memcpy(PN533_FRAME_CMD_PARAMS_PTR(frame), &mod->data, mod->len);
frame->datalen += mod->len;
pn533_tx_frame_finish(frame);
}
static int pn533_start_poll_complete(struct pn533 *dev, void *arg,
u8 *params, int params_len)
{
struct pn533_poll_response *resp;
struct pn533_poll_modulations *next_mod;
int rc;
nfc_dev_dbg(&dev->interface->dev, "%s", __func__);
if (params_len == -ENOENT) {
nfc_dev_dbg(&dev->interface->dev, "Polling operation has been"
" stopped");
goto stop_poll;
}
if (params_len < 0) {
nfc_dev_err(&dev->interface->dev, "Error %d when running poll",
params_len);
goto stop_poll;
}
resp = (struct pn533_poll_response *) params;
if (resp->nbtg) {
rc = pn533_target_found(dev, resp, params_len);
if (rc == 0)
goto stop_poll;
if (rc != -EAGAIN)
nfc_dev_err(&dev->interface->dev, "The target found is"
" not valid - continuing to poll");
}
dev->poll_mod_curr = (dev->poll_mod_curr + 1) % dev->poll_mod_count;
next_mod = dev->poll_mod_active[dev->poll_mod_curr];
nfc_dev_dbg(&dev->interface->dev, "Polling next modulation (0x%x)",
dev->poll_mod_curr);
pn533_start_poll_frame(dev->out_frame, next_mod);
rc = __pn533_send_cmd_frame_async(dev, dev->out_frame, dev->in_frame,
dev->in_maxlen, pn533_start_poll_complete,
NULL, GFP_ATOMIC);
if (rc == -EPERM) {
nfc_dev_dbg(&dev->interface->dev, "Cannot poll next modulation"
" because poll has been stopped");
goto stop_poll;
}
if (rc) {
nfc_dev_err(&dev->interface->dev, "Error %d when trying to poll"
" next modulation", rc);
goto stop_poll;
}
return -EINPROGRESS;
stop_poll:
pn533_poll_reset_mod_list(dev);
dev->poll_protocols = 0;
return 0;
}
static int pn533_start_poll(struct nfc_dev *nfc_dev, u32 protocols)
{
struct pn533 *dev = nfc_get_drvdata(nfc_dev);
struct pn533_poll_modulations *start_mod;
int rc;
nfc_dev_dbg(&dev->interface->dev, "%s - protocols=0x%x", __func__,
protocols);
if (dev->poll_mod_count) {
nfc_dev_err(&dev->interface->dev, "Polling operation already"
" active");
return -EBUSY;
}
if (dev->tgt_active_prot) {
nfc_dev_err(&dev->interface->dev, "Cannot poll with a target"
" already activated");
return -EBUSY;
}
pn533_poll_create_mod_list(dev, protocols);
if (!dev->poll_mod_count) {
nfc_dev_err(&dev->interface->dev, "No valid protocols"
" specified");
rc = -EINVAL;
goto error;
}
nfc_dev_dbg(&dev->interface->dev, "It will poll %d modulations types",
dev->poll_mod_count);
dev->poll_mod_curr = 0;
start_mod = dev->poll_mod_active[dev->poll_mod_curr];
pn533_start_poll_frame(dev->out_frame, start_mod);
rc = pn533_send_cmd_frame_async(dev, dev->out_frame, dev->in_frame,
dev->in_maxlen, pn533_start_poll_complete,
NULL, GFP_KERNEL);
if (rc) {
nfc_dev_err(&dev->interface->dev, "Error %d when trying to"
" start poll", rc);
goto error;
}
dev->poll_protocols = protocols;
return 0;
error:
pn533_poll_reset_mod_list(dev);
return rc;
}
static void pn533_stop_poll(struct nfc_dev *nfc_dev)
{
struct pn533 *dev = nfc_get_drvdata(nfc_dev);
nfc_dev_dbg(&dev->interface->dev, "%s", __func__);
if (!dev->poll_mod_count) {
nfc_dev_dbg(&dev->interface->dev, "Polling operation was not"
" running");
return;
}
pn533_send_ack(dev, GFP_KERNEL);
usb_kill_urb(dev->in_urb);
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
static int pn533_activate_target(struct nfc_dev *nfc_dev, u32 target_idx,
u32 protocol)
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
static void pn533_deactivate_target(struct nfc_dev *nfc_dev, u32 target_idx)
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
struct pn533_cmd_jump_dep *cmd;
struct pn533_cmd_jump_dep_response *resp;
struct nfc_target nfc_target;
u8 target_gt_len;
int rc;
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
cmd = (struct pn533_cmd_jump_dep *) arg;
rc = resp->status & PN533_CMD_RET_MASK;
if (rc != PN533_CMD_RET_SUCCESS) {
nfc_dev_err(&dev->interface->dev,
"Bringing DEP link up failed %d", rc);
return 0;
}
if (!dev->tgt_available_prots) {
nfc_dev_dbg(&dev->interface->dev, "Creating new target");
nfc_target.supported_protocols = NFC_PROTO_NFC_DEP_MASK;
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
!cmd->active, NFC_RF_INITIATOR);
return 0;
}
static int pn533_dep_link_up(struct nfc_dev *nfc_dev, int target_idx,
u8 comm_mode, u8 rf_mode)
{
struct pn533 *dev = nfc_get_drvdata(nfc_dev);
struct pn533_cmd_jump_dep *cmd;
u8 cmd_len, local_gt_len, *local_gt;
int rc;
nfc_dev_dbg(&dev->interface->dev, "%s", __func__);
if (rf_mode == NFC_RF_TARGET) {
nfc_dev_err(&dev->interface->dev, "Target mode not supported");
return -EOPNOTSUPP;
}
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
local_gt = nfc_get_local_general_bytes(dev->nfc_dev, &local_gt_len);
if (local_gt_len > NFC_MAX_GT_LEN)
return -EINVAL;
cmd_len = sizeof(struct pn533_cmd_jump_dep) + local_gt_len;
cmd = kzalloc(cmd_len, GFP_KERNEL);
if (cmd == NULL)
return -ENOMEM;
pn533_tx_frame_init(dev->out_frame, PN533_CMD_IN_JUMP_FOR_DEP);
cmd->active = !comm_mode;
cmd->baud = 0;
if (local_gt != NULL) {
cmd->next = 4;
memcpy(cmd->gt, local_gt, local_gt_len);
} else {
cmd->next = 0;
}
memcpy(PN533_FRAME_CMD_PARAMS_PTR(dev->out_frame), cmd, cmd_len);
dev->out_frame->datalen += cmd_len;
pn533_tx_frame_finish(dev->out_frame);
rc = pn533_send_cmd_frame_async(dev, dev->out_frame, dev->in_frame,
dev->in_maxlen, pn533_in_dep_link_up_complete,
cmd, GFP_KERNEL);
if (rc)
goto out;
out:
kfree(cmd);
return rc;
}
static int pn533_dep_link_down(struct nfc_dev *nfc_dev)
{
pn533_deactivate_target(nfc_dev, 0);
return 0;
}
static int pn533_data_exchange_tx_frame(struct pn533 *dev, struct sk_buff *skb)
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
skb_push(skb, PN533_CMD_DATAEXCH_HEAD_LEN);
out_frame = (struct pn533_frame *) skb->data;
pn533_tx_frame_init(out_frame, PN533_CMD_IN_DATA_EXCHANGE);
tg = 1;
memcpy(PN533_FRAME_CMD_PARAMS_PTR(out_frame), &tg, sizeof(u8));
out_frame->datalen += sizeof(u8);
out_frame->datalen += payload_len;
pn533_tx_frame_finish(out_frame);
skb_put(skb, PN533_FRAME_TAIL_SIZE);
return 0;
}
static int pn533_data_exchange_complete(struct pn533 *dev, void *_arg,
u8 *params, int params_len)
{
struct pn533_data_exchange_arg *arg = _arg;
struct sk_buff *skb_resp = arg->skb_resp;
struct pn533_frame *in_frame = (struct pn533_frame *) skb_resp->data;
int err = 0;
u8 status;
u8 cmd_ret;
nfc_dev_dbg(&dev->interface->dev, "%s", __func__);
dev_kfree_skb_irq(arg->skb_out);
if (params_len < 0) {
err = params_len;
goto error;
}
skb_put(skb_resp, PN533_FRAME_SIZE(in_frame));
status = params[0];
cmd_ret = status & PN533_CMD_RET_MASK;
if (cmd_ret != PN533_CMD_RET_SUCCESS) {
nfc_dev_err(&dev->interface->dev, "PN533 reported error %d when"
" exchanging data", cmd_ret);
err = -EIO;
goto error;
}
if (status & PN533_CMD_MI_MASK) {
nfc_dev_err(&dev->interface->dev, "Multi-part message not yet"
" supported");
pn533_send_ack(dev, GFP_ATOMIC);
err = -ENOSYS;
goto error;
}
skb_pull(skb_resp, PN533_CMD_DATAEXCH_HEAD_LEN);
skb_trim(skb_resp, skb_resp->len - PN533_FRAME_TAIL_SIZE);
arg->cb(arg->cb_context, skb_resp, 0);
kfree(arg);
return 0;
error:
dev_kfree_skb_irq(skb_resp);
arg->cb(arg->cb_context, NULL, err);
kfree(arg);
return 0;
}
static int pn533_data_exchange(struct nfc_dev *nfc_dev, u32 target_idx,
struct sk_buff *skb,
data_exchange_cb_t cb,
void *cb_context)
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
rc = pn533_data_exchange_tx_frame(dev, skb);
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
static int pn533_probe(struct usb_interface *interface,
const struct usb_device_id *id)
{
struct pn533_fw_version *fw_ver;
struct pn533 *dev;
struct usb_host_interface *iface_desc;
struct usb_endpoint_descriptor *endpoint;
struct pn533_config_max_retries max_retries;
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
sema_init(&dev->cmd_lock, 1);
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
dev->in_frame = kmalloc(dev->in_maxlen, GFP_KERNEL);
dev->in_urb = usb_alloc_urb(0, GFP_KERNEL);
dev->out_frame = kmalloc(dev->out_maxlen, GFP_KERNEL);
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
tasklet_init(&dev->tasklet, pn533_tasklet_cmd_complete, (ulong)dev);
usb_set_intfdata(interface, dev);
pn533_tx_frame_init(dev->out_frame, PN533_CMD_GET_FIRMWARE_VERSION);
pn533_tx_frame_finish(dev->out_frame);
rc = pn533_send_cmd_frame_sync(dev, dev->out_frame, dev->in_frame,
dev->in_maxlen);
if (rc)
goto kill_tasklet;
fw_ver = (struct pn533_fw_version *)
PN533_FRAME_CMD_PARAMS_PTR(dev->in_frame);
nfc_dev_info(&dev->interface->dev, "NXP PN533 firmware ver %d.%d now"
" attached", fw_ver->ver, fw_ver->rev);
protocols = NFC_PROTO_JEWEL_MASK
| NFC_PROTO_MIFARE_MASK | NFC_PROTO_FELICA_MASK
| NFC_PROTO_ISO14443_MASK
| NFC_PROTO_NFC_DEP_MASK;
dev->nfc_dev = nfc_allocate_device(&pn533_nfc_ops, protocols,
PN533_CMD_DATAEXCH_HEAD_LEN,
PN533_FRAME_TAIL_SIZE);
if (!dev->nfc_dev)
goto kill_tasklet;
nfc_set_parent_dev(dev->nfc_dev, &interface->dev);
nfc_set_drvdata(dev->nfc_dev, dev);
rc = nfc_register_device(dev->nfc_dev);
if (rc)
goto free_nfc_dev;
max_retries.mx_rty_atr = PN533_CONFIG_MAX_RETRIES_ENDLESS;
max_retries.mx_rty_psl = 2;
max_retries.mx_rty_passive_act = PN533_CONFIG_MAX_RETRIES_NO_RETRY;
rc = pn533_set_configuration(dev, PN533_CFGITEM_MAX_RETRIES,
(u8 *) &max_retries, sizeof(max_retries));
if (rc) {
nfc_dev_err(&dev->interface->dev, "Error on setting MAX_RETRIES"
" config");
goto free_nfc_dev;
}
return 0;
free_nfc_dev:
nfc_free_device(dev->nfc_dev);
kill_tasklet:
tasklet_kill(&dev->tasklet);
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
dev = usb_get_intfdata(interface);
usb_set_intfdata(interface, NULL);
nfc_unregister_device(dev->nfc_dev);
nfc_free_device(dev->nfc_dev);
usb_kill_urb(dev->in_urb);
usb_kill_urb(dev->out_urb);
tasklet_kill(&dev->tasklet);
kfree(dev->in_frame);
usb_free_urb(dev->in_urb);
kfree(dev->out_frame);
usb_free_urb(dev->out_urb);
kfree(dev);
nfc_dev_info(&interface->dev, "NXP PN533 NFC device disconnected");
}
