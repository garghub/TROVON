static inline char *link_typetostr(int type)
{
switch (type) {
case ACL_LINK:
return "ACL";
case SCO_LINK:
return "SCO";
case ESCO_LINK:
return "eSCO";
case LE_LINK:
return "LE";
default:
return "UNKNOWN";
}
}
static ssize_t show_link_type(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct hci_conn *conn = to_hci_conn(dev);
return sprintf(buf, "%s\n", link_typetostr(conn->type));
}
static ssize_t show_link_address(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct hci_conn *conn = to_hci_conn(dev);
return sprintf(buf, "%pMR\n", &conn->dst);
}
static void bt_link_release(struct device *dev)
{
struct hci_conn *conn = to_hci_conn(dev);
kfree(conn);
}
static int __match_tty(struct device *dev, void *data)
{
return !strncmp(dev_name(dev), "rfcomm", 6);
}
void hci_conn_init_sysfs(struct hci_conn *conn)
{
struct hci_dev *hdev = conn->hdev;
BT_DBG("conn %p", conn);
conn->dev.type = &bt_link;
conn->dev.class = bt_class;
conn->dev.parent = &hdev->dev;
device_initialize(&conn->dev);
}
void hci_conn_add_sysfs(struct hci_conn *conn)
{
struct hci_dev *hdev = conn->hdev;
BT_DBG("conn %p", conn);
dev_set_name(&conn->dev, "%s:%d", hdev->name, conn->handle);
if (device_add(&conn->dev) < 0) {
BT_ERR("Failed to register connection device");
return;
}
hci_dev_hold(hdev);
}
void hci_conn_del_sysfs(struct hci_conn *conn)
{
struct hci_dev *hdev = conn->hdev;
if (!device_is_registered(&conn->dev))
return;
while (1) {
struct device *dev;
dev = device_find_child(&conn->dev, NULL, __match_tty);
if (!dev)
break;
device_move(dev, NULL, DPM_ORDER_DEV_LAST);
put_device(dev);
}
device_del(&conn->dev);
hci_dev_put(hdev);
}
static inline char *host_typetostr(int type)
{
switch (type) {
case HCI_BREDR:
return "BR/EDR";
case HCI_AMP:
return "AMP";
default:
return "UNKNOWN";
}
}
static ssize_t show_type(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct hci_dev *hdev = to_hci_dev(dev);
return sprintf(buf, "%s\n", host_typetostr(hdev->dev_type));
}
static ssize_t show_name(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct hci_dev *hdev = to_hci_dev(dev);
char name[HCI_MAX_NAME_LENGTH + 1];
int i;
for (i = 0; i < HCI_MAX_NAME_LENGTH; i++)
name[i] = hdev->dev_name[i];
name[HCI_MAX_NAME_LENGTH] = '\0';
return sprintf(buf, "%s\n", name);
}
static ssize_t show_address(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct hci_dev *hdev = to_hci_dev(dev);
return sprintf(buf, "%pMR\n", &hdev->bdaddr);
}
static void bt_host_release(struct device *dev)
{
struct hci_dev *hdev = to_hci_dev(dev);
kfree(hdev);
module_put(THIS_MODULE);
}
void hci_init_sysfs(struct hci_dev *hdev)
{
struct device *dev = &hdev->dev;
dev->type = &bt_host;
dev->class = bt_class;
__module_get(THIS_MODULE);
device_initialize(dev);
}
int __init bt_sysfs_init(void)
{
bt_class = class_create(THIS_MODULE, "bluetooth");
return PTR_ERR_OR_ZERO(bt_class);
}
void bt_sysfs_cleanup(void)
{
class_destroy(bt_class);
}
