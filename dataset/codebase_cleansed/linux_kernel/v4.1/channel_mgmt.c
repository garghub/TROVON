bool vmbus_prep_negotiate_resp(struct icmsg_hdr *icmsghdrp,
struct icmsg_negotiate *negop, u8 *buf,
int fw_version, int srv_version)
{
int icframe_major, icframe_minor;
int icmsg_major, icmsg_minor;
int fw_major, fw_minor;
int srv_major, srv_minor;
int i;
bool found_match = false;
icmsghdrp->icmsgsize = 0x10;
fw_major = (fw_version >> 16);
fw_minor = (fw_version & 0xFFFF);
srv_major = (srv_version >> 16);
srv_minor = (srv_version & 0xFFFF);
negop = (struct icmsg_negotiate *)&buf[
sizeof(struct vmbuspipe_hdr) +
sizeof(struct icmsg_hdr)];
icframe_major = negop->icframe_vercnt;
icframe_minor = 0;
icmsg_major = negop->icmsg_vercnt;
icmsg_minor = 0;
for (i = 0; i < negop->icframe_vercnt; i++) {
if ((negop->icversion_data[i].major == fw_major) &&
(negop->icversion_data[i].minor == fw_minor)) {
icframe_major = negop->icversion_data[i].major;
icframe_minor = negop->icversion_data[i].minor;
found_match = true;
}
}
if (!found_match)
goto fw_error;
found_match = false;
for (i = negop->icframe_vercnt;
(i < negop->icframe_vercnt + negop->icmsg_vercnt); i++) {
if ((negop->icversion_data[i].major == srv_major) &&
(negop->icversion_data[i].minor == srv_minor)) {
icmsg_major = negop->icversion_data[i].major;
icmsg_minor = negop->icversion_data[i].minor;
found_match = true;
}
}
fw_error:
if (!found_match) {
negop->icframe_vercnt = 0;
negop->icmsg_vercnt = 0;
} else {
negop->icframe_vercnt = 1;
negop->icmsg_vercnt = 1;
}
negop->icversion_data[0].major = icframe_major;
negop->icversion_data[0].minor = icframe_minor;
negop->icversion_data[1].major = icmsg_major;
negop->icversion_data[1].minor = icmsg_minor;
return found_match;
}
static struct vmbus_channel *alloc_channel(void)
{
static atomic_t chan_num = ATOMIC_INIT(0);
struct vmbus_channel *channel;
channel = kzalloc(sizeof(*channel), GFP_ATOMIC);
if (!channel)
return NULL;
channel->id = atomic_inc_return(&chan_num);
spin_lock_init(&channel->inbound_lock);
spin_lock_init(&channel->lock);
INIT_LIST_HEAD(&channel->sc_list);
INIT_LIST_HEAD(&channel->percpu_list);
return channel;
}
static void free_channel(struct vmbus_channel *channel)
{
kfree(channel);
}
static void percpu_channel_enq(void *arg)
{
struct vmbus_channel *channel = arg;
int cpu = smp_processor_id();
list_add_tail(&channel->percpu_list, &hv_context.percpu_list[cpu]);
}
static void percpu_channel_deq(void *arg)
{
struct vmbus_channel *channel = arg;
list_del(&channel->percpu_list);
}
void hv_process_channel_removal(struct vmbus_channel *channel, u32 relid)
{
struct vmbus_channel_relid_released msg;
unsigned long flags;
struct vmbus_channel *primary_channel;
memset(&msg, 0, sizeof(struct vmbus_channel_relid_released));
msg.child_relid = relid;
msg.header.msgtype = CHANNELMSG_RELID_RELEASED;
vmbus_post_msg(&msg, sizeof(struct vmbus_channel_relid_released));
if (channel == NULL)
return;
if (channel->target_cpu != get_cpu()) {
put_cpu();
smp_call_function_single(channel->target_cpu,
percpu_channel_deq, channel, true);
} else {
percpu_channel_deq(channel);
put_cpu();
}
if (channel->primary_channel == NULL) {
spin_lock_irqsave(&vmbus_connection.channel_lock, flags);
list_del(&channel->listentry);
spin_unlock_irqrestore(&vmbus_connection.channel_lock, flags);
} else {
primary_channel = channel->primary_channel;
spin_lock_irqsave(&primary_channel->lock, flags);
list_del(&channel->sc_list);
spin_unlock_irqrestore(&primary_channel->lock, flags);
}
free_channel(channel);
}
void vmbus_free_channels(void)
{
struct vmbus_channel *channel;
list_for_each_entry(channel, &vmbus_connection.chn_list, listentry) {
vmbus_device_unregister(channel->device_obj);
free_channel(channel);
}
}
static void vmbus_process_offer(struct vmbus_channel *newchannel)
{
struct vmbus_channel *channel;
bool fnew = true;
bool enq = false;
unsigned long flags;
spin_lock_irqsave(&vmbus_connection.channel_lock, flags);
list_for_each_entry(channel, &vmbus_connection.chn_list, listentry) {
if (!uuid_le_cmp(channel->offermsg.offer.if_type,
newchannel->offermsg.offer.if_type) &&
!uuid_le_cmp(channel->offermsg.offer.if_instance,
newchannel->offermsg.offer.if_instance)) {
fnew = false;
break;
}
}
if (fnew) {
list_add_tail(&newchannel->listentry,
&vmbus_connection.chn_list);
enq = true;
}
spin_unlock_irqrestore(&vmbus_connection.channel_lock, flags);
if (enq) {
if (newchannel->target_cpu != get_cpu()) {
put_cpu();
smp_call_function_single(newchannel->target_cpu,
percpu_channel_enq,
newchannel, true);
} else {
percpu_channel_enq(newchannel);
put_cpu();
}
}
if (!fnew) {
if (newchannel->offermsg.offer.sub_channel_index != 0) {
newchannel->primary_channel = channel;
spin_lock_irqsave(&channel->lock, flags);
list_add_tail(&newchannel->sc_list, &channel->sc_list);
spin_unlock_irqrestore(&channel->lock, flags);
if (newchannel->target_cpu != get_cpu()) {
put_cpu();
smp_call_function_single(newchannel->target_cpu,
percpu_channel_enq,
newchannel, true);
} else {
percpu_channel_enq(newchannel);
put_cpu();
}
newchannel->state = CHANNEL_OPEN_STATE;
channel->num_sc++;
if (channel->sc_creation_callback != NULL)
channel->sc_creation_callback(newchannel);
return;
}
goto err_free_chan;
}
newchannel->state = CHANNEL_OPEN_STATE;
newchannel->device_obj = vmbus_device_create(
&newchannel->offermsg.offer.if_type,
&newchannel->offermsg.offer.if_instance,
newchannel);
if (!newchannel->device_obj)
goto err_deq_chan;
if (vmbus_device_register(newchannel->device_obj) != 0) {
pr_err("unable to add child device object (relid %d)\n",
newchannel->offermsg.child_relid);
kfree(newchannel->device_obj);
goto err_deq_chan;
}
return;
err_deq_chan:
spin_lock_irqsave(&vmbus_connection.channel_lock, flags);
list_del(&newchannel->listentry);
spin_unlock_irqrestore(&vmbus_connection.channel_lock, flags);
if (newchannel->target_cpu != get_cpu()) {
put_cpu();
smp_call_function_single(newchannel->target_cpu,
percpu_channel_deq, newchannel, true);
} else {
percpu_channel_deq(newchannel);
put_cpu();
}
err_free_chan:
free_channel(newchannel);
}
static void init_vp_index(struct vmbus_channel *channel, const uuid_le *type_guid)
{
u32 cur_cpu;
int i;
bool perf_chn = false;
u32 max_cpus = num_online_cpus();
for (i = IDE; i < MAX_PERF_CHN; i++) {
if (!memcmp(type_guid->b, hp_devs[i].guid,
sizeof(uuid_le))) {
perf_chn = true;
break;
}
}
if ((vmbus_proto_version == VERSION_WS2008) ||
(vmbus_proto_version == VERSION_WIN7) || (!perf_chn)) {
channel->target_cpu = 0;
channel->target_vp = 0;
return;
}
cur_cpu = (++next_vp % max_cpus);
channel->target_cpu = cur_cpu;
channel->target_vp = hv_context.vp_index[cur_cpu];
}
static void vmbus_onoffer(struct vmbus_channel_message_header *hdr)
{
struct vmbus_channel_offer_channel *offer;
struct vmbus_channel *newchannel;
offer = (struct vmbus_channel_offer_channel *)hdr;
newchannel = alloc_channel();
if (!newchannel) {
pr_err("Unable to allocate channel object\n");
return;
}
newchannel->batched_reading = true;
newchannel->sig_event = (struct hv_input_signal_event *)
(ALIGN((unsigned long)
&newchannel->sig_buf,
HV_HYPERCALL_PARAM_ALIGN));
newchannel->sig_event->connectionid.asu32 = 0;
newchannel->sig_event->connectionid.u.id = VMBUS_EVENT_CONNECTION_ID;
newchannel->sig_event->flag_number = 0;
newchannel->sig_event->rsvdz = 0;
if (vmbus_proto_version != VERSION_WS2008) {
newchannel->is_dedicated_interrupt =
(offer->is_dedicated_interrupt != 0);
newchannel->sig_event->connectionid.u.id =
offer->connection_id;
}
init_vp_index(newchannel, &offer->offer.if_type);
memcpy(&newchannel->offermsg, offer,
sizeof(struct vmbus_channel_offer_channel));
newchannel->monitor_grp = (u8)offer->monitorid / 32;
newchannel->monitor_bit = (u8)offer->monitorid % 32;
vmbus_process_offer(newchannel);
}
static void vmbus_onoffer_rescind(struct vmbus_channel_message_header *hdr)
{
struct vmbus_channel_rescind_offer *rescind;
struct vmbus_channel *channel;
unsigned long flags;
struct device *dev;
rescind = (struct vmbus_channel_rescind_offer *)hdr;
channel = relid2channel(rescind->child_relid);
if (channel == NULL) {
hv_process_channel_removal(NULL, rescind->child_relid);
return;
}
spin_lock_irqsave(&channel->lock, flags);
channel->rescind = true;
spin_unlock_irqrestore(&channel->lock, flags);
if (channel->device_obj) {
dev = get_device(&channel->device_obj->device);
if (dev) {
vmbus_device_unregister(channel->device_obj);
put_device(dev);
}
} else {
hv_process_channel_removal(channel,
channel->offermsg.child_relid);
}
}
static void vmbus_onoffers_delivered(
struct vmbus_channel_message_header *hdr)
{
}
static void vmbus_onopen_result(struct vmbus_channel_message_header *hdr)
{
struct vmbus_channel_open_result *result;
struct vmbus_channel_msginfo *msginfo;
struct vmbus_channel_message_header *requestheader;
struct vmbus_channel_open_channel *openmsg;
unsigned long flags;
result = (struct vmbus_channel_open_result *)hdr;
spin_lock_irqsave(&vmbus_connection.channelmsg_lock, flags);
list_for_each_entry(msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
requestheader =
(struct vmbus_channel_message_header *)msginfo->msg;
if (requestheader->msgtype == CHANNELMSG_OPENCHANNEL) {
openmsg =
(struct vmbus_channel_open_channel *)msginfo->msg;
if (openmsg->child_relid == result->child_relid &&
openmsg->openid == result->openid) {
memcpy(&msginfo->response.open_result,
result,
sizeof(
struct vmbus_channel_open_result));
complete(&msginfo->waitevent);
break;
}
}
}
spin_unlock_irqrestore(&vmbus_connection.channelmsg_lock, flags);
}
static void vmbus_ongpadl_created(struct vmbus_channel_message_header *hdr)
{
struct vmbus_channel_gpadl_created *gpadlcreated;
struct vmbus_channel_msginfo *msginfo;
struct vmbus_channel_message_header *requestheader;
struct vmbus_channel_gpadl_header *gpadlheader;
unsigned long flags;
gpadlcreated = (struct vmbus_channel_gpadl_created *)hdr;
spin_lock_irqsave(&vmbus_connection.channelmsg_lock, flags);
list_for_each_entry(msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
requestheader =
(struct vmbus_channel_message_header *)msginfo->msg;
if (requestheader->msgtype == CHANNELMSG_GPADL_HEADER) {
gpadlheader =
(struct vmbus_channel_gpadl_header *)requestheader;
if ((gpadlcreated->child_relid ==
gpadlheader->child_relid) &&
(gpadlcreated->gpadl == gpadlheader->gpadl)) {
memcpy(&msginfo->response.gpadl_created,
gpadlcreated,
sizeof(
struct vmbus_channel_gpadl_created));
complete(&msginfo->waitevent);
break;
}
}
}
spin_unlock_irqrestore(&vmbus_connection.channelmsg_lock, flags);
}
static void vmbus_ongpadl_torndown(
struct vmbus_channel_message_header *hdr)
{
struct vmbus_channel_gpadl_torndown *gpadl_torndown;
struct vmbus_channel_msginfo *msginfo;
struct vmbus_channel_message_header *requestheader;
struct vmbus_channel_gpadl_teardown *gpadl_teardown;
unsigned long flags;
gpadl_torndown = (struct vmbus_channel_gpadl_torndown *)hdr;
spin_lock_irqsave(&vmbus_connection.channelmsg_lock, flags);
list_for_each_entry(msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
requestheader =
(struct vmbus_channel_message_header *)msginfo->msg;
if (requestheader->msgtype == CHANNELMSG_GPADL_TEARDOWN) {
gpadl_teardown =
(struct vmbus_channel_gpadl_teardown *)requestheader;
if (gpadl_torndown->gpadl == gpadl_teardown->gpadl) {
memcpy(&msginfo->response.gpadl_torndown,
gpadl_torndown,
sizeof(
struct vmbus_channel_gpadl_torndown));
complete(&msginfo->waitevent);
break;
}
}
}
spin_unlock_irqrestore(&vmbus_connection.channelmsg_lock, flags);
}
static void vmbus_onversion_response(
struct vmbus_channel_message_header *hdr)
{
struct vmbus_channel_msginfo *msginfo;
struct vmbus_channel_message_header *requestheader;
struct vmbus_channel_version_response *version_response;
unsigned long flags;
version_response = (struct vmbus_channel_version_response *)hdr;
spin_lock_irqsave(&vmbus_connection.channelmsg_lock, flags);
list_for_each_entry(msginfo, &vmbus_connection.chn_msg_list,
msglistentry) {
requestheader =
(struct vmbus_channel_message_header *)msginfo->msg;
if (requestheader->msgtype ==
CHANNELMSG_INITIATE_CONTACT) {
memcpy(&msginfo->response.version_response,
version_response,
sizeof(struct vmbus_channel_version_response));
complete(&msginfo->waitevent);
}
}
spin_unlock_irqrestore(&vmbus_connection.channelmsg_lock, flags);
}
void vmbus_onmessage(void *context)
{
struct hv_message *msg = context;
struct vmbus_channel_message_header *hdr;
int size;
hdr = (struct vmbus_channel_message_header *)msg->u.payload;
size = msg->header.payload_size;
if (hdr->msgtype >= CHANNELMSG_COUNT) {
pr_err("Received invalid channel message type %d size %d\n",
hdr->msgtype, size);
print_hex_dump_bytes("", DUMP_PREFIX_NONE,
(unsigned char *)msg->u.payload, size);
return;
}
if (channel_message_table[hdr->msgtype].message_handler)
channel_message_table[hdr->msgtype].message_handler(hdr);
else
pr_err("Unhandled channel message type %d\n", hdr->msgtype);
}
int vmbus_request_offers(void)
{
struct vmbus_channel_message_header *msg;
struct vmbus_channel_msginfo *msginfo;
int ret;
msginfo = kmalloc(sizeof(*msginfo) +
sizeof(struct vmbus_channel_message_header),
GFP_KERNEL);
if (!msginfo)
return -ENOMEM;
msg = (struct vmbus_channel_message_header *)msginfo->msg;
msg->msgtype = CHANNELMSG_REQUESTOFFERS;
ret = vmbus_post_msg(msg,
sizeof(struct vmbus_channel_message_header));
if (ret != 0) {
pr_err("Unable to request offers - %d\n", ret);
goto cleanup;
}
cleanup:
kfree(msginfo);
return ret;
}
struct vmbus_channel *vmbus_get_outgoing_channel(struct vmbus_channel *primary)
{
struct list_head *cur, *tmp;
int cur_cpu;
struct vmbus_channel *cur_channel;
struct vmbus_channel *outgoing_channel = primary;
int next_channel;
int i = 1;
if (list_empty(&primary->sc_list))
return outgoing_channel;
next_channel = primary->next_oc++;
if (next_channel > (primary->num_sc)) {
primary->next_oc = 0;
return outgoing_channel;
}
cur_cpu = hv_context.vp_index[get_cpu()];
put_cpu();
list_for_each_safe(cur, tmp, &primary->sc_list) {
cur_channel = list_entry(cur, struct vmbus_channel, sc_list);
if (cur_channel->state != CHANNEL_OPENED_STATE)
continue;
if (cur_channel->target_vp == cur_cpu)
return cur_channel;
if (i == next_channel)
return cur_channel;
i++;
}
return outgoing_channel;
}
static void invoke_sc_cb(struct vmbus_channel *primary_channel)
{
struct list_head *cur, *tmp;
struct vmbus_channel *cur_channel;
if (primary_channel->sc_creation_callback == NULL)
return;
list_for_each_safe(cur, tmp, &primary_channel->sc_list) {
cur_channel = list_entry(cur, struct vmbus_channel, sc_list);
primary_channel->sc_creation_callback(cur_channel);
}
}
void vmbus_set_sc_create_callback(struct vmbus_channel *primary_channel,
void (*sc_cr_cb)(struct vmbus_channel *new_sc))
{
primary_channel->sc_creation_callback = sc_cr_cb;
}
bool vmbus_are_subchannels_present(struct vmbus_channel *primary)
{
bool ret;
ret = !list_empty(&primary->sc_list);
if (ret) {
invoke_sc_cb(primary);
}
return ret;
}
