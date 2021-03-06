static ssize_t connect_type_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct usb_port *port_dev = to_usb_port(dev);
char *result;
switch (port_dev->connect_type) {
case USB_PORT_CONNECT_TYPE_HOT_PLUG:
result = "hotplug";
break;
case USB_PORT_CONNECT_TYPE_HARD_WIRED:
result = "hardwired";
break;
case USB_PORT_NOT_USED:
result = "not used";
break;
default:
result = "unknown";
break;
}
return sprintf(buf, "%s\n", result);
}
static ssize_t usb3_lpm_permit_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct usb_port *port_dev = to_usb_port(dev);
const char *p;
if (port_dev->usb3_lpm_u1_permit) {
if (port_dev->usb3_lpm_u2_permit)
p = "u1_u2";
else
p = "u1";
} else {
if (port_dev->usb3_lpm_u2_permit)
p = "u2";
else
p = "0";
}
return sprintf(buf, "%s\n", p);
}
static ssize_t usb3_lpm_permit_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct usb_port *port_dev = to_usb_port(dev);
struct usb_device *udev = port_dev->child;
struct usb_hcd *hcd;
if (!strncmp(buf, "u1_u2", 5)) {
port_dev->usb3_lpm_u1_permit = 1;
port_dev->usb3_lpm_u2_permit = 1;
} else if (!strncmp(buf, "u1", 2)) {
port_dev->usb3_lpm_u1_permit = 1;
port_dev->usb3_lpm_u2_permit = 0;
} else if (!strncmp(buf, "u2", 2)) {
port_dev->usb3_lpm_u1_permit = 0;
port_dev->usb3_lpm_u2_permit = 1;
} else if (!strncmp(buf, "0", 1)) {
port_dev->usb3_lpm_u1_permit = 0;
port_dev->usb3_lpm_u2_permit = 0;
} else
return -EINVAL;
if (udev) {
hcd = bus_to_hcd(udev->bus);
if (!hcd)
return -EINVAL;
usb_lock_device(udev);
mutex_lock(hcd->bandwidth_mutex);
if (!usb_disable_lpm(udev))
usb_enable_lpm(udev);
mutex_unlock(hcd->bandwidth_mutex);
usb_unlock_device(udev);
}
return count;
}
static void usb_port_device_release(struct device *dev)
{
struct usb_port *port_dev = to_usb_port(dev);
kfree(port_dev->req);
kfree(port_dev);
}
static int usb_port_runtime_resume(struct device *dev)
{
struct usb_port *port_dev = to_usb_port(dev);
struct usb_device *hdev = to_usb_device(dev->parent->parent);
struct usb_interface *intf = to_usb_interface(dev->parent);
struct usb_hub *hub = usb_hub_to_struct_hub(hdev);
struct usb_device *udev = port_dev->child;
struct usb_port *peer = port_dev->peer;
int port1 = port_dev->portnum;
int retval;
if (!hub)
return -EINVAL;
if (hub->in_reset) {
set_bit(port1, hub->power_bits);
return 0;
}
if (!port_dev->is_superspeed && peer)
pm_runtime_get_sync(&peer->dev);
usb_autopm_get_interface(intf);
retval = usb_hub_set_port_power(hdev, hub, port1, true);
msleep(hub_power_on_good_delay(hub));
if (udev && !retval) {
if (hub_port_debounce_be_connected(hub, port1) < 0) {
dev_dbg(&port_dev->dev, "reconnect timeout\n");
if (hub_is_superspeed(hdev))
set_bit(port1, hub->warm_reset_bits);
}
if (!test_and_set_bit(port1, hub->child_usage_bits)) {
pm_runtime_get_noresume(&port_dev->dev);
pm_request_resume(&udev->dev);
}
}
usb_autopm_put_interface(intf);
return retval;
}
static int usb_port_runtime_suspend(struct device *dev)
{
struct usb_port *port_dev = to_usb_port(dev);
struct usb_device *hdev = to_usb_device(dev->parent->parent);
struct usb_interface *intf = to_usb_interface(dev->parent);
struct usb_hub *hub = usb_hub_to_struct_hub(hdev);
struct usb_port *peer = port_dev->peer;
int port1 = port_dev->portnum;
int retval;
if (!hub)
return -EINVAL;
if (hub->in_reset)
return -EBUSY;
if (dev_pm_qos_flags(&port_dev->dev, PM_QOS_FLAG_NO_POWER_OFF)
== PM_QOS_FLAGS_ALL)
return -EAGAIN;
if (usb_port_block_power_off)
return -EBUSY;
usb_autopm_get_interface(intf);
retval = usb_hub_set_port_power(hdev, hub, port1, false);
usb_clear_port_feature(hdev, port1, USB_PORT_FEAT_C_CONNECTION);
if (!port_dev->is_superspeed)
usb_clear_port_feature(hdev, port1, USB_PORT_FEAT_C_ENABLE);
usb_autopm_put_interface(intf);
if (!port_dev->is_superspeed && peer)
pm_runtime_put(&peer->dev);
return retval;
}
static int usb_port_prepare(struct device *dev)
{
return 1;
}
static int link_peers(struct usb_port *left, struct usb_port *right)
{
struct usb_port *ss_port, *hs_port;
int rc;
if (left->peer == right && right->peer == left)
return 0;
if (left->peer || right->peer) {
struct usb_port *lpeer = left->peer;
struct usb_port *rpeer = right->peer;
char *method;
if (left->location && left->location == right->location)
method = "location";
else
method = "default";
pr_debug("usb: failed to peer %s and %s by %s (%s:%s) (%s:%s)\n",
dev_name(&left->dev), dev_name(&right->dev), method,
dev_name(&left->dev),
lpeer ? dev_name(&lpeer->dev) : "none",
dev_name(&right->dev),
rpeer ? dev_name(&rpeer->dev) : "none");
return -EBUSY;
}
rc = sysfs_create_link(&left->dev.kobj, &right->dev.kobj, "peer");
if (rc)
return rc;
rc = sysfs_create_link(&right->dev.kobj, &left->dev.kobj, "peer");
if (rc) {
sysfs_remove_link(&left->dev.kobj, "peer");
return rc;
}
if (left->is_superspeed) {
ss_port = left;
WARN_ON(right->is_superspeed);
hs_port = right;
} else {
ss_port = right;
WARN_ON(!right->is_superspeed);
hs_port = left;
}
pm_runtime_get_sync(&hs_port->dev);
left->peer = right;
right->peer = left;
pm_runtime_get_sync(&ss_port->dev);
pm_runtime_put(&hs_port->dev);
return 0;
}
static void link_peers_report(struct usb_port *left, struct usb_port *right)
{
int rc;
rc = link_peers(left, right);
if (rc == 0) {
dev_dbg(&left->dev, "peered to %s\n", dev_name(&right->dev));
} else {
dev_dbg(&left->dev, "failed to peer to %s (%d)\n",
dev_name(&right->dev), rc);
pr_warn_once("usb: port power management may be unreliable\n");
usb_port_block_power_off = 1;
}
}
static void unlink_peers(struct usb_port *left, struct usb_port *right)
{
struct usb_port *ss_port, *hs_port;
WARN(right->peer != left || left->peer != right,
"%s and %s are not peers?\n",
dev_name(&left->dev), dev_name(&right->dev));
if (left->is_superspeed) {
ss_port = left;
hs_port = right;
} else {
ss_port = right;
hs_port = left;
}
pm_runtime_get_sync(&hs_port->dev);
sysfs_remove_link(&left->dev.kobj, "peer");
right->peer = NULL;
sysfs_remove_link(&right->dev.kobj, "peer");
left->peer = NULL;
pm_runtime_put(&ss_port->dev);
pm_runtime_put(&hs_port->dev);
}
static int match_location(struct usb_device *peer_hdev, void *p)
{
int port1;
struct usb_hcd *hcd, *peer_hcd;
struct usb_port *port_dev = p, *peer;
struct usb_hub *peer_hub = usb_hub_to_struct_hub(peer_hdev);
struct usb_device *hdev = to_usb_device(port_dev->dev.parent->parent);
if (!peer_hub)
return 0;
hcd = bus_to_hcd(hdev->bus);
peer_hcd = bus_to_hcd(peer_hdev->bus);
if (peer_hcd != hcd->shared_hcd)
return 0;
for (port1 = 1; port1 <= peer_hdev->maxchild; port1++) {
peer = peer_hub->ports[port1 - 1];
if (peer && peer->location == port_dev->location) {
link_peers_report(port_dev, peer);
return 1;
}
}
return 0;
}
static void find_and_link_peer(struct usb_hub *hub, int port1)
{
struct usb_port *port_dev = hub->ports[port1 - 1], *peer;
struct usb_device *hdev = hub->hdev;
struct usb_device *peer_hdev;
struct usb_hub *peer_hub;
if (port_dev->location) {
usb_for_each_dev(port_dev, match_location);
return;
} else if (!hdev->parent) {
struct usb_hcd *hcd = bus_to_hcd(hdev->bus);
struct usb_hcd *peer_hcd = hcd->shared_hcd;
if (!peer_hcd)
return;
peer_hdev = peer_hcd->self.root_hub;
} else {
struct usb_port *upstream;
struct usb_device *parent = hdev->parent;
struct usb_hub *parent_hub = usb_hub_to_struct_hub(parent);
if (!parent_hub)
return;
upstream = parent_hub->ports[hdev->portnum - 1];
if (!upstream || !upstream->peer)
return;
peer_hdev = upstream->peer->child;
}
peer_hub = usb_hub_to_struct_hub(peer_hdev);
if (!peer_hub || port1 > peer_hdev->maxchild)
return;
peer = peer_hub->ports[port1 - 1];
if (peer && peer->location == 0)
link_peers_report(port_dev, peer);
}
int usb_hub_create_port_device(struct usb_hub *hub, int port1)
{
struct usb_port *port_dev;
struct usb_device *hdev = hub->hdev;
int retval;
port_dev = kzalloc(sizeof(*port_dev), GFP_KERNEL);
if (!port_dev)
return -ENOMEM;
port_dev->req = kzalloc(sizeof(*(port_dev->req)), GFP_KERNEL);
if (!port_dev->req) {
kfree(port_dev);
return -ENOMEM;
}
hub->ports[port1 - 1] = port_dev;
port_dev->portnum = port1;
set_bit(port1, hub->power_bits);
port_dev->dev.parent = hub->intfdev;
if (hub_is_superspeed(hdev)) {
port_dev->usb3_lpm_u1_permit = 1;
port_dev->usb3_lpm_u2_permit = 1;
port_dev->dev.groups = port_dev_usb3_group;
} else
port_dev->dev.groups = port_dev_group;
port_dev->dev.type = &usb_port_device_type;
port_dev->dev.driver = &usb_port_driver;
if (hub_is_superspeed(hub->hdev))
port_dev->is_superspeed = 1;
dev_set_name(&port_dev->dev, "%s-port%d", dev_name(&hub->hdev->dev),
port1);
mutex_init(&port_dev->status_lock);
retval = device_register(&port_dev->dev);
if (retval) {
put_device(&port_dev->dev);
return retval;
}
retval = dev_pm_qos_add_request(&port_dev->dev, port_dev->req,
DEV_PM_QOS_FLAGS, PM_QOS_FLAG_NO_POWER_OFF);
if (retval < 0) {
device_unregister(&port_dev->dev);
return retval;
}
find_and_link_peer(hub, port1);
pm_runtime_set_active(&port_dev->dev);
pm_runtime_get_noresume(&port_dev->dev);
pm_runtime_enable(&port_dev->dev);
device_enable_async_suspend(&port_dev->dev);
if (!hub_is_port_power_switchable(hub))
return 0;
retval = dev_pm_qos_expose_flags(&port_dev->dev,
PM_QOS_FLAG_NO_POWER_OFF);
if (retval < 0) {
dev_warn(&port_dev->dev, "failed to expose pm_qos_no_poweroff\n");
return 0;
}
retval = dev_pm_qos_remove_request(port_dev->req);
if (retval >= 0) {
kfree(port_dev->req);
port_dev->req = NULL;
}
return 0;
}
void usb_hub_remove_port_device(struct usb_hub *hub, int port1)
{
struct usb_port *port_dev = hub->ports[port1 - 1];
struct usb_port *peer;
peer = port_dev->peer;
if (peer)
unlink_peers(port_dev, peer);
device_unregister(&port_dev->dev);
}
