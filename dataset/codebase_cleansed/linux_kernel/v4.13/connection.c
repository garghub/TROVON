static __u32 vmbus_get_next_version(__u32 current_version)
{
switch (current_version) {
case (VERSION_WIN7):
return VERSION_WS2008;
case (VERSION_WIN8):
return VERSION_WIN7;
case (VERSION_WIN8_1):
return VERSION_WIN8;
case (VERSION_WIN10):
return VERSION_WIN8_1;
case (VERSION_WS2008):
default:
return VERSION_INVAL;
}
}
static int vmbus_negotiate_version(struct vmbus_channel_msginfo *msginfo,
__u32 version)
{
int ret = 0;
struct vmbus_channel_initiate_contact *msg;
unsigned long flags;
init_completion(&msginfo->waitevent);
msg = (struct vmbus_channel_initiate_contact *)msginfo->msg;
msg->header.msgtype = CHANNELMSG_INITIATE_CONTACT;
msg->vmbus_version_requested = version;
msg->interrupt_page = virt_to_phys(vmbus_connection.int_page);
msg->monitor_page1 = virt_to_phys(vmbus_connection.monitor_pages[0]);
msg->monitor_page2 = virt_to_phys(vmbus_connection.monitor_pages[1]);
if (version >= VERSION_WIN8_1) {
msg->target_vcpu = hv_context.vp_index[smp_processor_id()];
vmbus_connection.connect_cpu = smp_processor_id();
} else {
msg->target_vcpu = 0;
vmbus_connection.connect_cpu = 0;
}
spin_lock_irqsave(&vmbus_connection.channelmsg_lock, flags);
list_add_tail(&msginfo->msglistentry,
&vmbus_connection.chn_msg_list);
spin_unlock_irqrestore(&vmbus_connection.channelmsg_lock, flags);
ret = vmbus_post_msg(msg,
sizeof(struct vmbus_channel_initiate_contact),
true);
if (ret != 0) {
spin_lock_irqsave(&vmbus_connection.channelmsg_lock, flags);
list_del(&msginfo->msglistentry);
spin_unlock_irqrestore(&vmbus_connection.channelmsg_lock,
flags);
return ret;
}
wait_for_completion(&msginfo->waitevent);
spin_lock_irqsave(&vmbus_connection.channelmsg_lock, flags);
list_del(&msginfo->msglistentry);
spin_unlock_irqrestore(&vmbus_connection.channelmsg_lock, flags);
if (msginfo->response.version_response.version_supported) {
vmbus_connection.conn_state = CONNECTED;
} else {
return -ECONNREFUSED;
}
return ret;
}
int vmbus_connect(void)
{
int ret = 0;
struct vmbus_channel_msginfo *msginfo = NULL;
__u32 version;
vmbus_connection.conn_state = CONNECTING;
vmbus_connection.work_queue = create_workqueue("hv_vmbus_con");
if (!vmbus_connection.work_queue) {
ret = -ENOMEM;
goto cleanup;
}
INIT_LIST_HEAD(&vmbus_connection.chn_msg_list);
spin_lock_init(&vmbus_connection.channelmsg_lock);
INIT_LIST_HEAD(&vmbus_connection.chn_list);
mutex_init(&vmbus_connection.channel_mutex);
vmbus_connection.int_page =
(void *)__get_free_pages(GFP_KERNEL|__GFP_ZERO, 0);
if (vmbus_connection.int_page == NULL) {
ret = -ENOMEM;
goto cleanup;
}
vmbus_connection.recv_int_page = vmbus_connection.int_page;
vmbus_connection.send_int_page =
(void *)((unsigned long)vmbus_connection.int_page +
(PAGE_SIZE >> 1));
vmbus_connection.monitor_pages[0] = (void *)__get_free_pages((GFP_KERNEL|__GFP_ZERO), 0);
vmbus_connection.monitor_pages[1] = (void *)__get_free_pages((GFP_KERNEL|__GFP_ZERO), 0);
if ((vmbus_connection.monitor_pages[0] == NULL) ||
(vmbus_connection.monitor_pages[1] == NULL)) {
ret = -ENOMEM;
goto cleanup;
}
msginfo = kzalloc(sizeof(*msginfo) +
sizeof(struct vmbus_channel_initiate_contact),
GFP_KERNEL);
if (msginfo == NULL) {
ret = -ENOMEM;
goto cleanup;
}
version = VERSION_CURRENT;
do {
ret = vmbus_negotiate_version(msginfo, version);
if (ret == -ETIMEDOUT)
goto cleanup;
if (vmbus_connection.conn_state == CONNECTED)
break;
version = vmbus_get_next_version(version);
} while (version != VERSION_INVAL);
if (version == VERSION_INVAL)
goto cleanup;
vmbus_proto_version = version;
pr_info("Vmbus version:%d.%d\n",
version >> 16, version & 0xFFFF);
kfree(msginfo);
return 0;
cleanup:
pr_err("Unable to connect to host\n");
vmbus_connection.conn_state = DISCONNECTED;
vmbus_disconnect();
kfree(msginfo);
return ret;
}
void vmbus_disconnect(void)
{
vmbus_initiate_unload(false);
if (vmbus_connection.work_queue) {
drain_workqueue(vmbus_connection.work_queue);
destroy_workqueue(vmbus_connection.work_queue);
}
if (vmbus_connection.int_page) {
free_pages((unsigned long)vmbus_connection.int_page, 0);
vmbus_connection.int_page = NULL;
}
free_pages((unsigned long)vmbus_connection.monitor_pages[0], 0);
free_pages((unsigned long)vmbus_connection.monitor_pages[1], 0);
vmbus_connection.monitor_pages[0] = NULL;
vmbus_connection.monitor_pages[1] = NULL;
}
struct vmbus_channel *relid2channel(u32 relid)
{
struct vmbus_channel *channel;
struct vmbus_channel *found_channel = NULL;
struct list_head *cur, *tmp;
struct vmbus_channel *cur_sc;
BUG_ON(!mutex_is_locked(&vmbus_connection.channel_mutex));
list_for_each_entry(channel, &vmbus_connection.chn_list, listentry) {
if (channel->offermsg.child_relid == relid) {
found_channel = channel;
break;
} else if (!list_empty(&channel->sc_list)) {
list_for_each_safe(cur, tmp, &channel->sc_list) {
cur_sc = list_entry(cur, struct vmbus_channel,
sc_list);
if (cur_sc->offermsg.child_relid == relid) {
found_channel = cur_sc;
break;
}
}
}
}
return found_channel;
}
void vmbus_on_event(unsigned long data)
{
struct vmbus_channel *channel = (void *) data;
unsigned long time_limit = jiffies + 2;
do {
void (*callback_fn)(void *);
callback_fn = READ_ONCE(channel->onchannel_callback);
if (unlikely(callback_fn == NULL))
return;
(*callback_fn)(channel->channel_callback_context);
if (channel->callback_mode != HV_CALL_BATCHED)
return;
if (likely(hv_end_read(&channel->inbound) == 0))
return;
hv_begin_read(&channel->inbound);
} while (likely(time_before(jiffies, time_limit)));
tasklet_schedule(&channel->callback_event);
}
int vmbus_post_msg(void *buffer, size_t buflen, bool can_sleep)
{
union hv_connection_id conn_id;
int ret = 0;
int retries = 0;
u32 usec = 1;
conn_id.asu32 = 0;
conn_id.u.id = VMBUS_MESSAGE_CONNECTION_ID;
while (retries < 100) {
ret = hv_post_message(conn_id, 1, buffer, buflen);
switch (ret) {
case HV_STATUS_INVALID_CONNECTION_ID:
ret = -EAGAIN;
break;
case HV_STATUS_INSUFFICIENT_MEMORY:
case HV_STATUS_INSUFFICIENT_BUFFERS:
ret = -ENOBUFS;
break;
case HV_STATUS_SUCCESS:
return ret;
default:
pr_err("hv_post_msg() failed; error code:%d\n", ret);
return -EINVAL;
}
retries++;
if (can_sleep && usec > 1000)
msleep(usec / 1000);
else if (usec < MAX_UDELAY_MS * 1000)
udelay(usec);
else
mdelay(usec / 1000);
if (retries < 22)
usec *= 2;
}
return ret;
}
void vmbus_set_event(struct vmbus_channel *channel)
{
u32 child_relid = channel->offermsg.child_relid;
if (!channel->is_dedicated_interrupt)
vmbus_send_interrupt(child_relid);
hv_do_hypercall(HVCALL_SIGNAL_EVENT, channel->sig_event, NULL);
}
