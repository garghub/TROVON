static ssize_t modalias_show(struct device *dev,
struct device_attribute *a __maybe_unused, char *buf)
{
return sprintf(buf, "hsi:%s\n", dev_name(dev));
}
static int hsi_bus_uevent(struct device *dev, struct kobj_uevent_env *env)
{
add_uevent_var(env, "MODALIAS=hsi:%s", dev_name(dev));
return 0;
}
static int hsi_bus_match(struct device *dev, struct device_driver *driver)
{
if (of_driver_match_device(dev, driver))
return true;
if (strcmp(dev_name(dev), driver->name) == 0)
return true;
return false;
}
static void hsi_client_release(struct device *dev)
{
struct hsi_client *cl = to_hsi_client(dev);
kfree(cl->tx_cfg.channels);
kfree(cl->rx_cfg.channels);
kfree(cl);
}
struct hsi_client *hsi_new_client(struct hsi_port *port,
struct hsi_board_info *info)
{
struct hsi_client *cl;
size_t size;
cl = kzalloc(sizeof(*cl), GFP_KERNEL);
if (!cl)
return NULL;
cl->tx_cfg = info->tx_cfg;
if (cl->tx_cfg.channels) {
size = cl->tx_cfg.num_channels * sizeof(*cl->tx_cfg.channels);
cl->tx_cfg.channels = kzalloc(size , GFP_KERNEL);
memcpy(cl->tx_cfg.channels, info->tx_cfg.channels, size);
}
cl->rx_cfg = info->rx_cfg;
if (cl->rx_cfg.channels) {
size = cl->rx_cfg.num_channels * sizeof(*cl->rx_cfg.channels);
cl->rx_cfg.channels = kzalloc(size , GFP_KERNEL);
memcpy(cl->rx_cfg.channels, info->rx_cfg.channels, size);
}
cl->device.bus = &hsi_bus_type;
cl->device.parent = &port->device;
cl->device.release = hsi_client_release;
dev_set_name(&cl->device, "%s", info->name);
cl->device.platform_data = info->platform_data;
if (info->archdata)
cl->device.archdata = *info->archdata;
if (device_register(&cl->device) < 0) {
pr_err("hsi: failed to register client: %s\n", info->name);
put_device(&cl->device);
}
return cl;
}
static void hsi_scan_board_info(struct hsi_controller *hsi)
{
struct hsi_cl_info *cl_info;
struct hsi_port *p;
list_for_each_entry(cl_info, &hsi_board_list, list)
if (cl_info->info.hsi_id == hsi->id) {
p = hsi_find_port_num(hsi, cl_info->info.port);
if (!p)
continue;
hsi_new_client(p, &cl_info->info);
}
}
static int hsi_of_property_parse_mode(struct device_node *client, char *name,
unsigned int *result)
{
const char *mode;
int err;
err = of_property_read_string(client, name, &mode);
if (err < 0)
return err;
if (strcmp(mode, "stream") == 0)
*result = HSI_MODE_STREAM;
else if (strcmp(mode, "frame") == 0)
*result = HSI_MODE_FRAME;
else
return -EINVAL;
return 0;
}
static int hsi_of_property_parse_flow(struct device_node *client, char *name,
unsigned int *result)
{
const char *flow;
int err;
err = of_property_read_string(client, name, &flow);
if (err < 0)
return err;
if (strcmp(flow, "synchronized") == 0)
*result = HSI_FLOW_SYNC;
else if (strcmp(flow, "pipeline") == 0)
*result = HSI_FLOW_PIPE;
else
return -EINVAL;
return 0;
}
static int hsi_of_property_parse_arb_mode(struct device_node *client,
char *name, unsigned int *result)
{
const char *arb_mode;
int err;
err = of_property_read_string(client, name, &arb_mode);
if (err < 0)
return err;
if (strcmp(arb_mode, "round-robin") == 0)
*result = HSI_ARB_RR;
else if (strcmp(arb_mode, "priority") == 0)
*result = HSI_ARB_PRIO;
else
return -EINVAL;
return 0;
}
static void hsi_add_client_from_dt(struct hsi_port *port,
struct device_node *client)
{
struct hsi_client *cl;
struct hsi_channel channel;
struct property *prop;
char name[32];
int length, cells, err, i, max_chan, mode;
cl = kzalloc(sizeof(*cl), GFP_KERNEL);
if (!cl)
return;
err = of_modalias_node(client, name, sizeof(name));
if (err)
goto err;
dev_set_name(&cl->device, "%s", name);
err = hsi_of_property_parse_mode(client, "hsi-mode", &mode);
if (err) {
err = hsi_of_property_parse_mode(client, "hsi-rx-mode",
&cl->rx_cfg.mode);
if (err)
goto err;
err = hsi_of_property_parse_mode(client, "hsi-tx-mode",
&cl->tx_cfg.mode);
if (err)
goto err;
} else {
cl->rx_cfg.mode = mode;
cl->tx_cfg.mode = mode;
}
err = of_property_read_u32(client, "hsi-speed-kbps",
&cl->tx_cfg.speed);
if (err)
goto err;
cl->rx_cfg.speed = cl->tx_cfg.speed;
err = hsi_of_property_parse_flow(client, "hsi-flow",
&cl->rx_cfg.flow);
if (err)
goto err;
err = hsi_of_property_parse_arb_mode(client, "hsi-arb-mode",
&cl->rx_cfg.arb_mode);
if (err)
goto err;
prop = of_find_property(client, "hsi-channel-ids", &length);
if (!prop) {
err = -EINVAL;
goto err;
}
cells = length / sizeof(u32);
cl->rx_cfg.num_channels = cells;
cl->tx_cfg.num_channels = cells;
cl->rx_cfg.channels = kzalloc(cells * sizeof(channel), GFP_KERNEL);
if (!cl->rx_cfg.channels) {
err = -ENOMEM;
goto err;
}
cl->tx_cfg.channels = kzalloc(cells * sizeof(channel), GFP_KERNEL);
if (!cl->tx_cfg.channels) {
err = -ENOMEM;
goto err2;
}
max_chan = 0;
for (i = 0; i < cells; i++) {
err = of_property_read_u32_index(client, "hsi-channel-ids", i,
&channel.id);
if (err)
goto err3;
err = of_property_read_string_index(client, "hsi-channel-names",
i, &channel.name);
if (err)
channel.name = NULL;
if (channel.id > max_chan)
max_chan = channel.id;
cl->rx_cfg.channels[i] = channel;
cl->tx_cfg.channels[i] = channel;
}
cl->rx_cfg.num_hw_channels = max_chan + 1;
cl->tx_cfg.num_hw_channels = max_chan + 1;
cl->device.bus = &hsi_bus_type;
cl->device.parent = &port->device;
cl->device.release = hsi_client_release;
cl->device.of_node = client;
if (device_register(&cl->device) < 0) {
pr_err("hsi: failed to register client: %s\n", name);
put_device(&cl->device);
goto err3;
}
return;
err3:
kfree(cl->tx_cfg.channels);
err2:
kfree(cl->rx_cfg.channels);
err:
kfree(cl);
pr_err("hsi client: missing or incorrect of property: err=%d\n", err);
}
void hsi_add_clients_from_dt(struct hsi_port *port, struct device_node *clients)
{
struct device_node *child;
hsi_new_client(port, &hsi_char_dev_info);
for_each_available_child_of_node(clients, child)
hsi_add_client_from_dt(port, child);
}
int hsi_remove_client(struct device *dev, void *data __maybe_unused)
{
device_unregister(dev);
return 0;
}
static int hsi_remove_port(struct device *dev, void *data __maybe_unused)
{
device_for_each_child(dev, NULL, hsi_remove_client);
device_unregister(dev);
return 0;
}
static void hsi_controller_release(struct device *dev)
{
struct hsi_controller *hsi = to_hsi_controller(dev);
kfree(hsi->port);
kfree(hsi);
}
static void hsi_port_release(struct device *dev)
{
kfree(to_hsi_port(dev));
}
void hsi_port_unregister_clients(struct hsi_port *port)
{
device_for_each_child(&port->device, NULL, hsi_remove_client);
}
void hsi_unregister_controller(struct hsi_controller *hsi)
{
device_for_each_child(&hsi->device, NULL, hsi_remove_port);
device_unregister(&hsi->device);
}
int hsi_register_controller(struct hsi_controller *hsi)
{
unsigned int i;
int err;
err = device_add(&hsi->device);
if (err < 0)
return err;
for (i = 0; i < hsi->num_ports; i++) {
hsi->port[i]->device.parent = &hsi->device;
err = device_add(&hsi->port[i]->device);
if (err < 0)
goto out;
}
hsi_scan_board_info(hsi);
return 0;
out:
while (i-- > 0)
device_del(&hsi->port[i]->device);
device_del(&hsi->device);
return err;
}
int hsi_register_client_driver(struct hsi_client_driver *drv)
{
drv->driver.bus = &hsi_bus_type;
return driver_register(&drv->driver);
}
static inline int hsi_dummy_msg(struct hsi_msg *msg __maybe_unused)
{
return 0;
}
static inline int hsi_dummy_cl(struct hsi_client *cl __maybe_unused)
{
return 0;
}
void hsi_put_controller(struct hsi_controller *hsi)
{
unsigned int i;
if (!hsi)
return;
for (i = 0; i < hsi->num_ports; i++)
if (hsi->port && hsi->port[i])
put_device(&hsi->port[i]->device);
put_device(&hsi->device);
}
struct hsi_controller *hsi_alloc_controller(unsigned int n_ports, gfp_t flags)
{
struct hsi_controller *hsi;
struct hsi_port **port;
unsigned int i;
if (!n_ports)
return NULL;
hsi = kzalloc(sizeof(*hsi), flags);
if (!hsi)
return NULL;
port = kzalloc(sizeof(*port)*n_ports, flags);
if (!port) {
kfree(hsi);
return NULL;
}
hsi->num_ports = n_ports;
hsi->port = port;
hsi->device.release = hsi_controller_release;
device_initialize(&hsi->device);
for (i = 0; i < n_ports; i++) {
port[i] = kzalloc(sizeof(**port), flags);
if (port[i] == NULL)
goto out;
port[i]->num = i;
port[i]->async = hsi_dummy_msg;
port[i]->setup = hsi_dummy_cl;
port[i]->flush = hsi_dummy_cl;
port[i]->start_tx = hsi_dummy_cl;
port[i]->stop_tx = hsi_dummy_cl;
port[i]->release = hsi_dummy_cl;
mutex_init(&port[i]->lock);
ATOMIC_INIT_NOTIFIER_HEAD(&port[i]->n_head);
dev_set_name(&port[i]->device, "port%d", i);
hsi->port[i]->device.release = hsi_port_release;
device_initialize(&hsi->port[i]->device);
}
return hsi;
out:
hsi_put_controller(hsi);
return NULL;
}
void hsi_free_msg(struct hsi_msg *msg)
{
if (!msg)
return;
sg_free_table(&msg->sgt);
kfree(msg);
}
struct hsi_msg *hsi_alloc_msg(unsigned int nents, gfp_t flags)
{
struct hsi_msg *msg;
int err;
msg = kzalloc(sizeof(*msg), flags);
if (!msg)
return NULL;
if (!nents)
return msg;
err = sg_alloc_table(&msg->sgt, nents, flags);
if (unlikely(err)) {
kfree(msg);
msg = NULL;
}
return msg;
}
int hsi_async(struct hsi_client *cl, struct hsi_msg *msg)
{
struct hsi_port *port = hsi_get_port(cl);
if (!hsi_port_claimed(cl))
return -EACCES;
WARN_ON_ONCE(!msg->destructor || !msg->complete);
msg->cl = cl;
return port->async(msg);
}
int hsi_claim_port(struct hsi_client *cl, unsigned int share)
{
struct hsi_port *port = hsi_get_port(cl);
int err = 0;
mutex_lock(&port->lock);
if ((port->claimed) && (!port->shared || !share)) {
err = -EBUSY;
goto out;
}
if (!try_module_get(to_hsi_controller(port->device.parent)->owner)) {
err = -ENODEV;
goto out;
}
port->claimed++;
port->shared = !!share;
cl->pclaimed = 1;
out:
mutex_unlock(&port->lock);
return err;
}
void hsi_release_port(struct hsi_client *cl)
{
struct hsi_port *port = hsi_get_port(cl);
mutex_lock(&port->lock);
port->release(cl);
if (cl->pclaimed)
port->claimed--;
BUG_ON(port->claimed < 0);
cl->pclaimed = 0;
if (!port->claimed)
port->shared = 0;
module_put(to_hsi_controller(port->device.parent)->owner);
mutex_unlock(&port->lock);
}
static int hsi_event_notifier_call(struct notifier_block *nb,
unsigned long event, void *data __maybe_unused)
{
struct hsi_client *cl = container_of(nb, struct hsi_client, nb);
(*cl->ehandler)(cl, event);
return 0;
}
int hsi_register_port_event(struct hsi_client *cl,
void (*handler)(struct hsi_client *, unsigned long))
{
struct hsi_port *port = hsi_get_port(cl);
if (!handler || cl->ehandler)
return -EINVAL;
if (!hsi_port_claimed(cl))
return -EACCES;
cl->ehandler = handler;
cl->nb.notifier_call = hsi_event_notifier_call;
return atomic_notifier_chain_register(&port->n_head, &cl->nb);
}
int hsi_unregister_port_event(struct hsi_client *cl)
{
struct hsi_port *port = hsi_get_port(cl);
int err;
WARN_ON(!hsi_port_claimed(cl));
err = atomic_notifier_chain_unregister(&port->n_head, &cl->nb);
if (!err)
cl->ehandler = NULL;
return err;
}
int hsi_event(struct hsi_port *port, unsigned long event)
{
return atomic_notifier_call_chain(&port->n_head, event, NULL);
}
int hsi_get_channel_id_by_name(struct hsi_client *cl, char *name)
{
int i;
if (!cl->rx_cfg.channels)
return -ENOENT;
for (i = 0; i < cl->rx_cfg.num_channels; i++)
if (!strcmp(cl->rx_cfg.channels[i].name, name))
return cl->rx_cfg.channels[i].id;
return -ENXIO;
}
static int __init hsi_init(void)
{
return bus_register(&hsi_bus_type);
}
static void __exit hsi_exit(void)
{
bus_unregister(&hsi_bus_type);
}
