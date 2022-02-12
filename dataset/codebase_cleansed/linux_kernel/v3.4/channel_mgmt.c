void vmbus_prep_negotiate_resp(struct icmsg_hdr *icmsghdrp,
struct icmsg_negotiate *negop, u8 *buf)
{
if (icmsghdrp->icmsgtype == ICMSGTYPE_NEGOTIATE) {
icmsghdrp->icmsgsize = 0x10;
negop = (struct icmsg_negotiate *)&buf[
sizeof(struct vmbuspipe_hdr) +
sizeof(struct icmsg_hdr)];
if (negop->icframe_vercnt == 2 &&
negop->icversion_data[1].major == 3) {
negop->icversion_data[0].major = 3;
negop->icversion_data[0].minor = 0;
negop->icversion_data[1].major = 3;
negop->icversion_data[1].minor = 0;
} else {
negop->icversion_data[0].major = 1;
negop->icversion_data[0].minor = 0;
negop->icversion_data[1].major = 1;
negop->icversion_data[1].minor = 0;
}
negop->icframe_vercnt = 1;
negop->icmsg_vercnt = 1;
}
}
static struct vmbus_channel *alloc_channel(void)
{
struct vmbus_channel *channel;
channel = kzalloc(sizeof(*channel), GFP_ATOMIC);
if (!channel)
return NULL;
spin_lock_init(&channel->inbound_lock);
channel->controlwq = create_workqueue("hv_vmbus_ctl");
if (!channel->controlwq) {
kfree(channel);
return NULL;
}
return channel;
}
static void release_channel(struct work_struct *work)
{
struct vmbus_channel *channel = container_of(work,
struct vmbus_channel,
work);
destroy_workqueue(channel->controlwq);
kfree(channel);
}
static void free_channel(struct vmbus_channel *channel)
{
INIT_WORK(&channel->work, release_channel);
queue_work(vmbus_connection.work_queue, &channel->work);
}
static void vmbus_process_rescind_offer(struct work_struct *work)
{
struct vmbus_channel *channel = container_of(work,
struct vmbus_channel,
work);
vmbus_device_unregister(channel->device_obj);
}
void vmbus_free_channels(void)
{
struct vmbus_channel *channel;
list_for_each_entry(channel, &vmbus_connection.chn_list, listentry) {
vmbus_device_unregister(channel->device_obj);
kfree(channel->device_obj);
free_channel(channel);
}
}
static void vmbus_process_offer(struct work_struct *work)
{
struct vmbus_channel *newchannel = container_of(work,
struct vmbus_channel,
work);
struct vmbus_channel *channel;
bool fnew = true;
int ret;
unsigned long flags;
INIT_WORK(&newchannel->work, vmbus_process_rescind_offer);
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
if (fnew)
list_add_tail(&newchannel->listentry,
&vmbus_connection.chn_list);
spin_unlock_irqrestore(&vmbus_connection.channel_lock, flags);
if (!fnew) {
free_channel(newchannel);
return;
}
newchannel->device_obj = vmbus_device_create(
&newchannel->offermsg.offer.if_type,
&newchannel->offermsg.offer.if_instance,
newchannel);
ret = vmbus_device_register(newchannel->device_obj);
if (ret != 0) {
pr_err("unable to add child device object (relid %d)\n",
newchannel->offermsg.child_relid);
spin_lock_irqsave(&vmbus_connection.channel_lock, flags);
list_del(&newchannel->listentry);
spin_unlock_irqrestore(&vmbus_connection.channel_lock, flags);
kfree(newchannel->device_obj);
free_channel(newchannel);
} else {
newchannel->state = CHANNEL_OPEN_STATE;
}
}
static void vmbus_onoffer(struct vmbus_channel_message_header *hdr)
{
struct vmbus_channel_offer_channel *offer;
struct vmbus_channel *newchannel;
uuid_le *guidtype;
uuid_le *guidinstance;
offer = (struct vmbus_channel_offer_channel *)hdr;
guidtype = &offer->offer.if_type;
guidinstance = &offer->offer.if_instance;
newchannel = alloc_channel();
if (!newchannel) {
pr_err("Unable to allocate channel object\n");
return;
}
memcpy(&newchannel->offermsg, offer,
sizeof(struct vmbus_channel_offer_channel));
newchannel->monitor_grp = (u8)offer->monitorid / 32;
newchannel->monitor_bit = (u8)offer->monitorid % 32;
INIT_WORK(&newchannel->work, vmbus_process_offer);
queue_work(newchannel->controlwq, &newchannel->work);
}
static void vmbus_onoffer_rescind(struct vmbus_channel_message_header *hdr)
{
struct vmbus_channel_rescind_offer *rescind;
struct vmbus_channel *channel;
rescind = (struct vmbus_channel_rescind_offer *)hdr;
channel = relid2channel(rescind->child_relid);
if (channel == NULL)
return;
queue_work(channel->controlwq, &channel->work);
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
struct vmbus_channel_initiate_contact *initiate;
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
initiate =
(struct vmbus_channel_initiate_contact *)requestheader;
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
int ret, t;
msginfo = kmalloc(sizeof(*msginfo) +
sizeof(struct vmbus_channel_message_header),
GFP_KERNEL);
if (!msginfo)
return -ENOMEM;
init_completion(&msginfo->waitevent);
msg = (struct vmbus_channel_message_header *)msginfo->msg;
msg->msgtype = CHANNELMSG_REQUESTOFFERS;
ret = vmbus_post_msg(msg,
sizeof(struct vmbus_channel_message_header));
if (ret != 0) {
pr_err("Unable to request offers - %d\n", ret);
goto cleanup;
}
t = wait_for_completion_timeout(&msginfo->waitevent, 5*HZ);
if (t == 0) {
ret = -ETIMEDOUT;
goto cleanup;
}
cleanup:
kfree(msginfo);
return ret;
}
