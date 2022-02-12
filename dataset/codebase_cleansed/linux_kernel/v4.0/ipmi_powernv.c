static int ipmi_powernv_start_processing(void *send_info, ipmi_smi_t intf)
{
struct ipmi_smi_powernv *smi = send_info;
smi->intf = intf;
return 0;
}
static void send_error_reply(struct ipmi_smi_powernv *smi,
struct ipmi_smi_msg *msg, u8 completion_code)
{
msg->rsp[0] = msg->data[0] | 0x4;
msg->rsp[1] = msg->data[1];
msg->rsp[2] = completion_code;
msg->rsp_size = 3;
ipmi_smi_msg_received(smi->intf, msg);
}
static void ipmi_powernv_send(void *send_info, struct ipmi_smi_msg *msg)
{
struct ipmi_smi_powernv *smi = send_info;
struct opal_ipmi_msg *opal_msg;
unsigned long flags;
int comp, rc;
size_t size;
if (msg->data_size > IPMI_MAX_MSG_LENGTH) {
comp = IPMI_REQ_LEN_EXCEEDED_ERR;
goto err;
}
if (msg->data_size < 2) {
comp = IPMI_REQ_LEN_INVALID_ERR;
goto err;
}
spin_lock_irqsave(&smi->msg_lock, flags);
if (smi->cur_msg) {
comp = IPMI_NODE_BUSY_ERR;
goto err_unlock;
}
opal_msg = smi->opal_msg;
opal_msg->version = OPAL_IPMI_MSG_FORMAT_VERSION_1;
opal_msg->netfn = msg->data[0];
opal_msg->cmd = msg->data[1];
if (msg->data_size > 2)
memcpy(opal_msg->data, msg->data + 2, msg->data_size - 2);
size = sizeof(*opal_msg) + msg->data_size - 2;
pr_devel("%s: opal_ipmi_send(0x%llx, %p, %ld)\n", __func__,
smi->interface_id, opal_msg, size);
rc = opal_ipmi_send(smi->interface_id, opal_msg, size);
pr_devel("%s: -> %d\n", __func__, rc);
if (!rc) {
smi->cur_msg = msg;
spin_unlock_irqrestore(&smi->msg_lock, flags);
return;
}
comp = IPMI_ERR_UNSPECIFIED;
err_unlock:
spin_unlock_irqrestore(&smi->msg_lock, flags);
err:
send_error_reply(smi, msg, comp);
}
static int ipmi_powernv_recv(struct ipmi_smi_powernv *smi)
{
struct opal_ipmi_msg *opal_msg;
struct ipmi_smi_msg *msg;
unsigned long flags;
uint64_t size;
int rc;
pr_devel("%s: opal_ipmi_recv(%llx, msg, sz)\n", __func__,
smi->interface_id);
spin_lock_irqsave(&smi->msg_lock, flags);
if (!smi->cur_msg) {
spin_unlock_irqrestore(&smi->msg_lock, flags);
pr_warn("no current message?\n");
return 0;
}
msg = smi->cur_msg;
opal_msg = smi->opal_msg;
size = cpu_to_be64(sizeof(*opal_msg) + IPMI_MAX_MSG_LENGTH);
rc = opal_ipmi_recv(smi->interface_id,
opal_msg,
&size);
size = be64_to_cpu(size);
pr_devel("%s: -> %d (size %lld)\n", __func__,
rc, rc == 0 ? size : 0);
if (rc) {
spin_unlock_irqrestore(&smi->msg_lock, flags);
ipmi_free_smi_msg(msg);
return 0;
}
if (size < sizeof(*opal_msg)) {
spin_unlock_irqrestore(&smi->msg_lock, flags);
pr_warn("unexpected IPMI message size %lld\n", size);
return 0;
}
if (opal_msg->version != OPAL_IPMI_MSG_FORMAT_VERSION_1) {
spin_unlock_irqrestore(&smi->msg_lock, flags);
pr_warn("unexpected IPMI message format (version %d)\n",
opal_msg->version);
return 0;
}
msg->rsp[0] = opal_msg->netfn;
msg->rsp[1] = opal_msg->cmd;
if (size > sizeof(*opal_msg))
memcpy(&msg->rsp[2], opal_msg->data, size - sizeof(*opal_msg));
msg->rsp_size = 2 + size - sizeof(*opal_msg);
smi->cur_msg = NULL;
spin_unlock_irqrestore(&smi->msg_lock, flags);
ipmi_smi_msg_received(smi->intf, msg);
return 0;
}
static void ipmi_powernv_request_events(void *send_info)
{
}
static void ipmi_powernv_set_run_to_completion(void *send_info,
bool run_to_completion)
{
}
static void ipmi_powernv_poll(void *send_info)
{
struct ipmi_smi_powernv *smi = send_info;
ipmi_powernv_recv(smi);
}
static int ipmi_opal_event(struct notifier_block *nb,
unsigned long events, void *change)
{
struct ipmi_smi_powernv *smi = container_of(nb,
struct ipmi_smi_powernv, event_nb);
if (events & smi->event)
ipmi_powernv_recv(smi);
return 0;
}
static int ipmi_powernv_probe(struct platform_device *pdev)
{
struct ipmi_smi_powernv *ipmi;
struct device *dev;
u32 prop;
int rc;
if (!pdev || !pdev->dev.of_node)
return -ENODEV;
dev = &pdev->dev;
ipmi = devm_kzalloc(dev, sizeof(*ipmi), GFP_KERNEL);
if (!ipmi)
return -ENOMEM;
spin_lock_init(&ipmi->msg_lock);
rc = of_property_read_u32(dev->of_node, "ibm,ipmi-interface-id",
&prop);
if (rc) {
dev_warn(dev, "No interface ID property\n");
goto err_free;
}
ipmi->interface_id = prop;
rc = of_property_read_u32(dev->of_node, "interrupts", &prop);
if (rc) {
dev_warn(dev, "No interrupts property\n");
goto err_free;
}
ipmi->event = 1ull << prop;
ipmi->event_nb.notifier_call = ipmi_opal_event;
rc = opal_notifier_register(&ipmi->event_nb);
if (rc) {
dev_warn(dev, "OPAL notifier registration failed (%d)\n", rc);
goto err_free;
}
ipmi->opal_msg = devm_kmalloc(dev,
sizeof(*ipmi->opal_msg) + IPMI_MAX_MSG_LENGTH,
GFP_KERNEL);
if (!ipmi->opal_msg) {
rc = -ENOMEM;
goto err_unregister;
}
rc = ipmi_register_smi(&ipmi_powernv_smi_handlers, ipmi,
&ipmi->ipmi_id, dev, 0);
if (rc) {
dev_warn(dev, "IPMI SMI registration failed (%d)\n", rc);
goto err_free_msg;
}
dev_set_drvdata(dev, ipmi);
return 0;
err_free_msg:
devm_kfree(dev, ipmi->opal_msg);
err_unregister:
opal_notifier_unregister(&ipmi->event_nb);
err_free:
devm_kfree(dev, ipmi);
return rc;
}
static int ipmi_powernv_remove(struct platform_device *pdev)
{
struct ipmi_smi_powernv *smi = dev_get_drvdata(&pdev->dev);
ipmi_unregister_smi(smi->intf);
opal_notifier_unregister(&smi->event_nb);
return 0;
}
