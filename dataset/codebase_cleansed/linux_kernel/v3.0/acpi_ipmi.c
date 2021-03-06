static struct acpi_ipmi_msg *acpi_alloc_ipmi_msg(struct acpi_ipmi_device *ipmi)
{
struct acpi_ipmi_msg *ipmi_msg;
struct pnp_dev *pnp_dev = ipmi->pnp_dev;
ipmi_msg = kzalloc(sizeof(struct acpi_ipmi_msg), GFP_KERNEL);
if (!ipmi_msg) {
dev_warn(&pnp_dev->dev, "Can't allocate memory for ipmi_msg\n");
return NULL;
}
init_completion(&ipmi_msg->tx_complete);
INIT_LIST_HEAD(&ipmi_msg->head);
ipmi_msg->device = ipmi;
return ipmi_msg;
}
static void acpi_format_ipmi_msg(struct acpi_ipmi_msg *tx_msg,
acpi_physical_address address,
acpi_integer *value)
{
struct kernel_ipmi_msg *msg;
struct acpi_ipmi_buffer *buffer;
struct acpi_ipmi_device *device;
msg = &tx_msg->tx_message;
msg->netfn = IPMI_OP_RGN_NETFN(address);
msg->cmd = IPMI_OP_RGN_CMD(address);
msg->data = tx_msg->tx_data;
buffer = (struct acpi_ipmi_buffer *)value;
msg->data_len = buffer->length;
memcpy(tx_msg->tx_data, buffer->data, msg->data_len);
tx_msg->addr.addr_type = IPMI_SYSTEM_INTERFACE_ADDR_TYPE;
tx_msg->addr.channel = IPMI_BMC_CHANNEL;
tx_msg->addr.data[0] = 0;
device = tx_msg->device;
mutex_lock(&device->tx_msg_lock);
device->curr_msgid++;
tx_msg->tx_msgid = device->curr_msgid;
mutex_unlock(&device->tx_msg_lock);
}
static void acpi_format_ipmi_response(struct acpi_ipmi_msg *msg,
acpi_integer *value, int rem_time)
{
struct acpi_ipmi_buffer *buffer;
buffer = (struct acpi_ipmi_buffer *)value;
if (!rem_time && !msg->msg_done) {
buffer->status = ACPI_IPMI_TIMEOUT;
return;
}
if (!msg->msg_done || !msg->rx_len) {
buffer->status = ACPI_IPMI_UNKNOWN;
return;
}
buffer->status = ACPI_IPMI_OK;
buffer->length = msg->rx_len;
memcpy(buffer->data, msg->rx_data, msg->rx_len);
}
static void ipmi_flush_tx_msg(struct acpi_ipmi_device *ipmi)
{
struct acpi_ipmi_msg *tx_msg, *temp;
int count = HZ / 10;
struct pnp_dev *pnp_dev = ipmi->pnp_dev;
list_for_each_entry_safe(tx_msg, temp, &ipmi->tx_msg_list, head) {
complete(&tx_msg->tx_complete);
}
while (count--) {
if (list_empty(&ipmi->tx_msg_list))
break;
schedule_timeout(1);
}
if (!list_empty(&ipmi->tx_msg_list))
dev_warn(&pnp_dev->dev, "tx msg list is not NULL\n");
}
static void ipmi_msg_handler(struct ipmi_recv_msg *msg, void *user_msg_data)
{
struct acpi_ipmi_device *ipmi_device = user_msg_data;
int msg_found = 0;
struct acpi_ipmi_msg *tx_msg;
struct pnp_dev *pnp_dev = ipmi_device->pnp_dev;
if (msg->user != ipmi_device->user_interface) {
dev_warn(&pnp_dev->dev, "Unexpected response is returned. "
"returned user %p, expected user %p\n",
msg->user, ipmi_device->user_interface);
ipmi_free_recv_msg(msg);
return;
}
mutex_lock(&ipmi_device->tx_msg_lock);
list_for_each_entry(tx_msg, &ipmi_device->tx_msg_list, head) {
if (msg->msgid == tx_msg->tx_msgid) {
msg_found = 1;
break;
}
}
mutex_unlock(&ipmi_device->tx_msg_lock);
if (!msg_found) {
dev_warn(&pnp_dev->dev, "Unexpected response (msg id %ld) is "
"returned.\n", msg->msgid);
ipmi_free_recv_msg(msg);
return;
}
if (msg->msg.data_len) {
memcpy(tx_msg->rx_data, msg->msg_data, msg->msg.data_len);
tx_msg->rx_len = msg->msg.data_len;
tx_msg->msg_done = 1;
}
complete(&tx_msg->tx_complete);
ipmi_free_recv_msg(msg);
}
static void ipmi_register_bmc(int iface, struct device *dev)
{
struct acpi_ipmi_device *ipmi_device, *temp;
struct pnp_dev *pnp_dev;
ipmi_user_t user;
int err;
struct ipmi_smi_info smi_data;
acpi_handle handle;
err = ipmi_get_smi_info(iface, &smi_data);
if (err)
return;
if (smi_data.addr_src != SI_ACPI) {
put_device(smi_data.dev);
return;
}
handle = smi_data.addr_info.acpi_info.acpi_handle;
mutex_lock(&driver_data.ipmi_lock);
list_for_each_entry(temp, &driver_data.ipmi_devices, head) {
if (temp->handle == handle)
goto out;
}
ipmi_device = kzalloc(sizeof(*ipmi_device), GFP_KERNEL);
if (!ipmi_device)
goto out;
pnp_dev = to_pnp_dev(smi_data.dev);
ipmi_device->handle = handle;
ipmi_device->pnp_dev = pnp_dev;
err = ipmi_create_user(iface, &driver_data.ipmi_hndlrs,
ipmi_device, &user);
if (err) {
dev_warn(&pnp_dev->dev, "Can't create IPMI user interface\n");
kfree(ipmi_device);
goto out;
}
acpi_add_ipmi_device(ipmi_device);
ipmi_device->user_interface = user;
ipmi_device->ipmi_ifnum = iface;
mutex_unlock(&driver_data.ipmi_lock);
memcpy(&ipmi_device->smi_data, &smi_data, sizeof(struct ipmi_smi_info));
return;
out:
mutex_unlock(&driver_data.ipmi_lock);
put_device(smi_data.dev);
return;
}
static void ipmi_bmc_gone(int iface)
{
struct acpi_ipmi_device *ipmi_device, *temp;
mutex_lock(&driver_data.ipmi_lock);
list_for_each_entry_safe(ipmi_device, temp,
&driver_data.ipmi_devices, head) {
if (ipmi_device->ipmi_ifnum != iface)
continue;
acpi_remove_ipmi_device(ipmi_device);
put_device(ipmi_device->smi_data.dev);
kfree(ipmi_device);
break;
}
mutex_unlock(&driver_data.ipmi_lock);
}
static acpi_status
acpi_ipmi_space_handler(u32 function, acpi_physical_address address,
u32 bits, acpi_integer *value,
void *handler_context, void *region_context)
{
struct acpi_ipmi_msg *tx_msg;
struct acpi_ipmi_device *ipmi_device = handler_context;
int err, rem_time;
acpi_status status;
if ((function & ACPI_IO_MASK) == ACPI_READ)
return AE_TYPE;
if (!ipmi_device->user_interface)
return AE_NOT_EXIST;
tx_msg = acpi_alloc_ipmi_msg(ipmi_device);
if (!tx_msg)
return AE_NO_MEMORY;
acpi_format_ipmi_msg(tx_msg, address, value);
mutex_lock(&ipmi_device->tx_msg_lock);
list_add_tail(&tx_msg->head, &ipmi_device->tx_msg_list);
mutex_unlock(&ipmi_device->tx_msg_lock);
err = ipmi_request_settime(ipmi_device->user_interface,
&tx_msg->addr,
tx_msg->tx_msgid,
&tx_msg->tx_message,
NULL, 0, 0, 0);
if (err) {
status = AE_ERROR;
goto end_label;
}
rem_time = wait_for_completion_timeout(&tx_msg->tx_complete,
IPMI_TIMEOUT);
acpi_format_ipmi_response(tx_msg, value, rem_time);
status = AE_OK;
end_label:
mutex_lock(&ipmi_device->tx_msg_lock);
list_del(&tx_msg->head);
mutex_unlock(&ipmi_device->tx_msg_lock);
kfree(tx_msg);
return status;
}
static void ipmi_remove_space_handler(struct acpi_ipmi_device *ipmi)
{
if (!test_bit(IPMI_FLAGS_HANDLER_INSTALL, &ipmi->flags))
return;
acpi_remove_address_space_handler(ipmi->handle,
ACPI_ADR_SPACE_IPMI, &acpi_ipmi_space_handler);
clear_bit(IPMI_FLAGS_HANDLER_INSTALL, &ipmi->flags);
}
static int ipmi_install_space_handler(struct acpi_ipmi_device *ipmi)
{
acpi_status status;
if (test_bit(IPMI_FLAGS_HANDLER_INSTALL, &ipmi->flags))
return 0;
status = acpi_install_address_space_handler(ipmi->handle,
ACPI_ADR_SPACE_IPMI,
&acpi_ipmi_space_handler,
NULL, ipmi);
if (ACPI_FAILURE(status)) {
struct pnp_dev *pnp_dev = ipmi->pnp_dev;
dev_warn(&pnp_dev->dev, "Can't register IPMI opregion space "
"handle\n");
return -EINVAL;
}
set_bit(IPMI_FLAGS_HANDLER_INSTALL, &ipmi->flags);
return 0;
}
static void acpi_add_ipmi_device(struct acpi_ipmi_device *ipmi_device)
{
INIT_LIST_HEAD(&ipmi_device->head);
mutex_init(&ipmi_device->tx_msg_lock);
INIT_LIST_HEAD(&ipmi_device->tx_msg_list);
ipmi_install_space_handler(ipmi_device);
list_add_tail(&ipmi_device->head, &driver_data.ipmi_devices);
}
static void acpi_remove_ipmi_device(struct acpi_ipmi_device *ipmi_device)
{
if (ipmi_device->user_interface) {
ipmi_destroy_user(ipmi_device->user_interface);
ipmi_device->user_interface = NULL;
}
if (!list_empty(&ipmi_device->tx_msg_list))
ipmi_flush_tx_msg(ipmi_device);
list_del(&ipmi_device->head);
ipmi_remove_space_handler(ipmi_device);
}
static int __init acpi_ipmi_init(void)
{
int result = 0;
if (acpi_disabled)
return result;
mutex_init(&driver_data.ipmi_lock);
result = ipmi_smi_watcher_register(&driver_data.bmc_events);
return result;
}
static void __exit acpi_ipmi_exit(void)
{
struct acpi_ipmi_device *ipmi_device, *temp;
if (acpi_disabled)
return;
ipmi_smi_watcher_unregister(&driver_data.bmc_events);
mutex_lock(&driver_data.ipmi_lock);
list_for_each_entry_safe(ipmi_device, temp,
&driver_data.ipmi_devices, head) {
acpi_remove_ipmi_device(ipmi_device);
put_device(ipmi_device->smi_data.dev);
kfree(ipmi_device);
}
mutex_unlock(&driver_data.ipmi_lock);
}
