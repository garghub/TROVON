static int gbaudio_request_jack(struct gbaudio_module_info *module,
struct gb_audio_jack_event_request *req)
{
int report;
struct snd_jack *jack = module->headset_jack.jack;
struct snd_jack *btn_jack = module->button_jack.jack;
if (!jack) {
dev_err_ratelimited(module->dev,
"Invalid jack event received:type: %u, event: %u\n",
req->jack_attribute, req->event);
return -EINVAL;
}
dev_warn_ratelimited(module->dev,
"Jack Event received: type: %u, event: %u\n",
req->jack_attribute, req->event);
if (req->event == GB_AUDIO_JACK_EVENT_REMOVAL) {
module->jack_type = 0;
if (btn_jack && module->button_status) {
snd_soc_jack_report(&module->button_jack, 0,
module->button_mask);
module->button_status = 0;
}
snd_soc_jack_report(&module->headset_jack, 0,
module->jack_mask);
return 0;
}
report = req->jack_attribute & module->jack_mask;
if (!report) {
dev_err_ratelimited(module->dev,
"Invalid jack event received:type: %u, event: %u\n",
req->jack_attribute, req->event);
return -EINVAL;
}
if (module->jack_type)
dev_warn_ratelimited(module->dev,
"Modifying jack from %d to %d\n",
module->jack_type, report);
module->jack_type = report;
snd_soc_jack_report(&module->headset_jack, report, module->jack_mask);
return 0;
}
static int gbaudio_request_button(struct gbaudio_module_info *module,
struct gb_audio_button_event_request *req)
{
int soc_button_id, report;
struct snd_jack *btn_jack = module->button_jack.jack;
if (!btn_jack) {
dev_err_ratelimited(module->dev,
"Invalid button event received:type: %u, event: %u\n",
req->button_id, req->event);
return -EINVAL;
}
dev_warn_ratelimited(module->dev,
"Button Event received: id: %u, event: %u\n",
req->button_id, req->event);
if (!module->jack_type) {
dev_err_ratelimited(module->dev,
"Jack not present. Bogus event!!\n");
return -EINVAL;
}
report = module->button_status & module->button_mask;
soc_button_id = 0;
switch (req->button_id) {
case 1:
soc_button_id = SND_JACK_BTN_0 & module->button_mask;
break;
case 2:
soc_button_id = SND_JACK_BTN_1 & module->button_mask;
break;
case 3:
soc_button_id = SND_JACK_BTN_2 & module->button_mask;
break;
case 4:
soc_button_id = SND_JACK_BTN_3 & module->button_mask;
break;
}
if (!soc_button_id) {
dev_err_ratelimited(module->dev,
"Invalid button request received\n");
return -EINVAL;
}
if (req->event == GB_AUDIO_BUTTON_EVENT_PRESS)
report = report | soc_button_id;
else
report = report & ~soc_button_id;
module->button_status = report;
snd_soc_jack_report(&module->button_jack, report, module->button_mask);
return 0;
}
static int gbaudio_request_stream(struct gbaudio_module_info *module,
struct gb_audio_streaming_event_request *req)
{
dev_warn(module->dev, "Audio Event received: cport: %u, event: %u\n",
req->data_cport, req->event);
return 0;
}
static int gbaudio_codec_request_handler(struct gb_operation *op)
{
struct gb_connection *connection = op->connection;
struct gbaudio_module_info *module =
greybus_get_drvdata(connection->bundle);
struct gb_operation_msg_hdr *header = op->request->header;
struct gb_audio_streaming_event_request *stream_req;
struct gb_audio_jack_event_request *jack_req;
struct gb_audio_button_event_request *button_req;
int ret;
switch (header->type) {
case GB_AUDIO_TYPE_STREAMING_EVENT:
stream_req = op->request->payload;
ret = gbaudio_request_stream(module, stream_req);
break;
case GB_AUDIO_TYPE_JACK_EVENT:
jack_req = op->request->payload;
ret = gbaudio_request_jack(module, jack_req);
break;
case GB_AUDIO_TYPE_BUTTON_EVENT:
button_req = op->request->payload;
ret = gbaudio_request_button(module, button_req);
break;
default:
dev_err_ratelimited(&connection->bundle->dev,
"Invalid Audio Event received\n");
return -EINVAL;
}
return ret;
}
static int gb_audio_add_mgmt_connection(struct gbaudio_module_info *gbmodule,
struct greybus_descriptor_cport *cport_desc,
struct gb_bundle *bundle)
{
struct gb_connection *connection;
if (gbmodule->mgmt_connection) {
dev_err(&bundle->dev,
"Can't have multiple Management connections\n");
return -ENODEV;
}
connection = gb_connection_create(bundle, le16_to_cpu(cport_desc->id),
gbaudio_codec_request_handler);
if (IS_ERR(connection))
return PTR_ERR(connection);
greybus_set_drvdata(bundle, gbmodule);
gbmodule->mgmt_connection = connection;
return 0;
}
static int gb_audio_add_data_connection(struct gbaudio_module_info *gbmodule,
struct greybus_descriptor_cport *cport_desc,
struct gb_bundle *bundle)
{
struct gb_connection *connection;
struct gbaudio_data_connection *dai;
dai = devm_kzalloc(gbmodule->dev, sizeof(*dai), GFP_KERNEL);
if (!dai)
return -ENOMEM;
connection = gb_connection_create_offloaded(bundle,
le16_to_cpu(cport_desc->id),
GB_CONNECTION_FLAG_CSD);
if (IS_ERR(connection)) {
devm_kfree(gbmodule->dev, dai);
return PTR_ERR(connection);
}
greybus_set_drvdata(bundle, gbmodule);
dai->id = 0;
dai->data_cport = connection->intf_cport_id;
dai->connection = connection;
list_add(&dai->list, &gbmodule->data_list);
return 0;
}
static int gb_audio_probe(struct gb_bundle *bundle,
const struct greybus_bundle_id *id)
{
struct device *dev = &bundle->dev;
struct gbaudio_module_info *gbmodule;
struct greybus_descriptor_cport *cport_desc;
struct gb_audio_manager_module_descriptor desc;
struct gbaudio_data_connection *dai, *_dai;
int ret, i;
struct gb_audio_topology *topology;
if (bundle->num_cports < 2)
return -ENODEV;
gbmodule = devm_kzalloc(dev, sizeof(*gbmodule), GFP_KERNEL);
if (!gbmodule)
return -ENOMEM;
gbmodule->num_data_connections = bundle->num_cports - 1;
INIT_LIST_HEAD(&gbmodule->data_list);
INIT_LIST_HEAD(&gbmodule->widget_list);
INIT_LIST_HEAD(&gbmodule->ctl_list);
INIT_LIST_HEAD(&gbmodule->widget_ctl_list);
gbmodule->dev = dev;
snprintf(gbmodule->name, NAME_SIZE, "%s.%s", dev->driver->name,
dev_name(dev));
greybus_set_drvdata(bundle, gbmodule);
for (i = 0; i < bundle->num_cports; i++) {
cport_desc = &bundle->cport_desc[i];
switch (cport_desc->protocol_id) {
case GREYBUS_PROTOCOL_AUDIO_MGMT:
ret = gb_audio_add_mgmt_connection(gbmodule, cport_desc,
bundle);
if (ret)
goto destroy_connections;
break;
case GREYBUS_PROTOCOL_AUDIO_DATA:
ret = gb_audio_add_data_connection(gbmodule, cport_desc,
bundle);
if (ret)
goto destroy_connections;
break;
default:
dev_err(dev, "Unsupported protocol: 0x%02x\n",
cport_desc->protocol_id);
ret = -ENODEV;
goto destroy_connections;
}
}
if (!gbmodule->mgmt_connection) {
ret = -EINVAL;
dev_err(dev, "Missing management connection\n");
goto destroy_connections;
}
ret = gb_connection_enable(gbmodule->mgmt_connection);
if (ret) {
dev_err(dev, "%d: Error while enabling mgmt connection\n", ret);
goto destroy_connections;
}
gbmodule->dev_id = gbmodule->mgmt_connection->intf->interface_id;
ret = gb_audio_gb_get_topology(gbmodule->mgmt_connection, &topology);
if (ret) {
dev_err(dev, "%d:Error while fetching topology\n", ret);
goto disable_connection;
}
ret = gbaudio_tplg_parse_data(gbmodule, topology);
if (ret) {
dev_err(dev, "%d:Error while parsing topology data\n",
ret);
goto free_topology;
}
gbmodule->topology = topology;
list_for_each_entry(dai, &gbmodule->data_list, list) {
ret = gb_connection_enable(dai->connection);
if (ret) {
dev_err(dev,
"%d:Error while enabling %d:data connection\n",
ret, dai->data_cport);
goto disable_data_connection;
}
}
ret = gbaudio_register_module(gbmodule);
if (ret)
goto disable_data_connection;
dev_dbg(dev, "Inform set_event:%d to above layer\n", 1);
strlcpy(desc.name, gbmodule->name, GB_AUDIO_MANAGER_MODULE_NAME_LEN);
desc.vid = 2;
desc.pid = 3;
desc.intf_id = gbmodule->dev_id;
desc.op_devices = gbmodule->op_devices;
desc.ip_devices = gbmodule->ip_devices;
gbmodule->manager_id = gb_audio_manager_add(&desc);
dev_dbg(dev, "Add GB Audio device:%s\n", gbmodule->name);
gb_pm_runtime_put_autosuspend(bundle);
return 0;
disable_data_connection:
list_for_each_entry_safe(dai, _dai, &gbmodule->data_list, list)
gb_connection_disable(dai->connection);
gbaudio_tplg_release(gbmodule);
gbmodule->topology = NULL;
free_topology:
kfree(topology);
disable_connection:
gb_connection_disable(gbmodule->mgmt_connection);
destroy_connections:
list_for_each_entry_safe(dai, _dai, &gbmodule->data_list, list) {
gb_connection_destroy(dai->connection);
list_del(&dai->list);
devm_kfree(dev, dai);
}
if (gbmodule->mgmt_connection)
gb_connection_destroy(gbmodule->mgmt_connection);
devm_kfree(dev, gbmodule);
return ret;
}
static void gb_audio_disconnect(struct gb_bundle *bundle)
{
struct gbaudio_module_info *gbmodule = greybus_get_drvdata(bundle);
struct gbaudio_data_connection *dai, *_dai;
gb_pm_runtime_get_sync(bundle);
gbaudio_unregister_module(gbmodule);
gb_audio_manager_remove(gbmodule->manager_id);
gbaudio_tplg_release(gbmodule);
kfree(gbmodule->topology);
gbmodule->topology = NULL;
gb_connection_disable(gbmodule->mgmt_connection);
list_for_each_entry_safe(dai, _dai, &gbmodule->data_list, list) {
gb_connection_disable(dai->connection);
gb_connection_destroy(dai->connection);
list_del(&dai->list);
devm_kfree(gbmodule->dev, dai);
}
gb_connection_destroy(gbmodule->mgmt_connection);
gbmodule->mgmt_connection = NULL;
devm_kfree(&bundle->dev, gbmodule);
}
static int gb_audio_suspend(struct device *dev)
{
struct gb_bundle *bundle = to_gb_bundle(dev);
struct gbaudio_module_info *gbmodule = greybus_get_drvdata(bundle);
struct gbaudio_data_connection *dai;
list_for_each_entry(dai, &gbmodule->data_list, list)
gb_connection_disable(dai->connection);
gb_connection_disable(gbmodule->mgmt_connection);
return 0;
}
static int gb_audio_resume(struct device *dev)
{
struct gb_bundle *bundle = to_gb_bundle(dev);
struct gbaudio_module_info *gbmodule = greybus_get_drvdata(bundle);
struct gbaudio_data_connection *dai;
int ret;
ret = gb_connection_enable(gbmodule->mgmt_connection);
if (ret) {
dev_err(dev, "%d:Error while enabling mgmt connection\n", ret);
return ret;
}
list_for_each_entry(dai, &gbmodule->data_list, list) {
ret = gb_connection_enable(dai->connection);
if (ret) {
dev_err(dev,
"%d:Error while enabling %d:data connection\n",
ret, dai->data_cport);
return ret;
}
}
return 0;
}
