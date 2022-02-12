static ssize_t show_status(struct device *dev, struct device_attribute *attr,
char *out)
{
char *s = out;
int i = 0;
BUG_ON(!the_controller || !out);
spin_lock(&the_controller->lock);
out += sprintf(out, "prt sta spd bus dev socket "
"local_busid\n");
for (i = 0; i < VHCI_NPORTS; i++) {
struct vhci_device *vdev = port_to_vdev(i);
spin_lock(&vdev->ud.lock);
out += sprintf(out, "%03u %03u ", i, vdev->ud.status);
if (vdev->ud.status == VDEV_ST_USED) {
out += sprintf(out, "%03u %08x ",
vdev->speed, vdev->devid);
out += sprintf(out, "%16p ", vdev->ud.tcp_socket);
out += sprintf(out, "%s", dev_name(&vdev->udev->dev));
} else {
out += sprintf(out, "000 000 000 0000000000000000 0-0");
}
out += sprintf(out, "\n");
spin_unlock(&vdev->ud.lock);
}
spin_unlock(&the_controller->lock);
return out - s;
}
static int vhci_port_disconnect(__u32 rhport)
{
struct vhci_device *vdev;
usbip_dbg_vhci_sysfs("enter\n");
spin_lock(&the_controller->lock);
vdev = port_to_vdev(rhport);
spin_lock(&vdev->ud.lock);
if (vdev->ud.status == VDEV_ST_NULL) {
pr_err("not connected %d\n", vdev->ud.status);
spin_unlock(&vdev->ud.lock);
spin_unlock(&the_controller->lock);
return -EINVAL;
}
spin_unlock(&vdev->ud.lock);
spin_unlock(&the_controller->lock);
usbip_event_add(&vdev->ud, VDEV_EVENT_DOWN);
return 0;
}
static ssize_t store_detach(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int err;
__u32 rhport = 0;
sscanf(buf, "%u", &rhport);
if (rhport >= VHCI_NPORTS) {
dev_err(dev, "invalid port %u\n", rhport);
return -EINVAL;
}
err = vhci_port_disconnect(rhport);
if (err < 0)
return -EINVAL;
usbip_dbg_vhci_sysfs("Leave\n");
return count;
}
static int valid_args(__u32 rhport, enum usb_device_speed speed)
{
if (rhport >= VHCI_NPORTS) {
pr_err("port %u\n", rhport);
return -EINVAL;
}
switch (speed) {
case USB_SPEED_LOW:
case USB_SPEED_FULL:
case USB_SPEED_HIGH:
case USB_SPEED_WIRELESS:
break;
default:
pr_err("speed %d\n", speed);
return -EINVAL;
}
return 0;
}
static ssize_t store_attach(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct vhci_device *vdev;
struct socket *socket;
int sockfd = 0;
__u32 rhport = 0, devid = 0, speed = 0;
sscanf(buf, "%u %u %u %u", &rhport, &sockfd, &devid, &speed);
usbip_dbg_vhci_sysfs("rhport(%u) sockfd(%u) devid(%u) speed(%u)\n",
rhport, sockfd, devid, speed);
if (valid_args(rhport, speed) < 0)
return -EINVAL;
socket = sockfd_to_socket(sockfd);
if (!socket)
return -EINVAL;
spin_lock(&the_controller->lock);
vdev = port_to_vdev(rhport);
spin_lock(&vdev->ud.lock);
if (vdev->ud.status != VDEV_ST_NULL) {
spin_unlock(&vdev->ud.lock);
spin_unlock(&the_controller->lock);
fput(socket->file);
dev_err(dev, "port %d already used\n", rhport);
return -EINVAL;
}
dev_info(dev, "rhport(%u) sockfd(%d) devid(%u) speed(%u)\n",
rhport, sockfd, devid, speed);
vdev->devid = devid;
vdev->speed = speed;
vdev->ud.tcp_socket = socket;
vdev->ud.status = VDEV_ST_NOTASSIGNED;
spin_unlock(&vdev->ud.lock);
spin_unlock(&the_controller->lock);
vdev->ud.tcp_rx = kthread_get_run(vhci_rx_loop, &vdev->ud, "vhci_rx");
vdev->ud.tcp_tx = kthread_get_run(vhci_tx_loop, &vdev->ud, "vhci_tx");
rh_port_connect(rhport, speed);
return count;
}
