static inline char *link_typetostr(int type)
{
switch (type) {
case ACL_LINK:
return "ACL";
case SCO_LINK:
return "SCO";
case ESCO_LINK:
return "eSCO";
default:
return "UNKNOWN";
}
}
static ssize_t show_link_type(struct device *dev, struct device_attribute *attr, char *buf)
{
struct hci_conn *conn = dev_get_drvdata(dev);
return sprintf(buf, "%s\n", link_typetostr(conn->type));
}
static ssize_t show_link_address(struct device *dev, struct device_attribute *attr, char *buf)
{
struct hci_conn *conn = dev_get_drvdata(dev);
return sprintf(buf, "%s\n", batostr(&conn->dst));
}
static ssize_t show_link_features(struct device *dev, struct device_attribute *attr, char *buf)
{
struct hci_conn *conn = dev_get_drvdata(dev);
return sprintf(buf, "0x%02x%02x%02x%02x%02x%02x%02x%02x\n",
conn->features[0], conn->features[1],
conn->features[2], conn->features[3],
conn->features[4], conn->features[5],
conn->features[6], conn->features[7]);
}
static void bt_link_release(struct device *dev)
{
void *data = dev_get_drvdata(dev);
kfree(data);
}
static void add_conn(struct work_struct *work)
{
struct hci_conn *conn = container_of(work, struct hci_conn, work_add);
struct hci_dev *hdev = conn->hdev;
dev_set_name(&conn->dev, "%s:%d", hdev->name, conn->handle);
dev_set_drvdata(&conn->dev, conn);
if (device_add(&conn->dev) < 0) {
BT_ERR("Failed to register connection device");
return;
}
hci_dev_hold(hdev);
}
static int __match_tty(struct device *dev, void *data)
{
return !strncmp(dev_name(dev), "rfcomm", 6);
}
static void del_conn(struct work_struct *work)
{
struct hci_conn *conn = container_of(work, struct hci_conn, work_del);
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
put_device(&conn->dev);
hci_dev_put(hdev);
}
void hci_conn_init_sysfs(struct hci_conn *conn)
{
struct hci_dev *hdev = conn->hdev;
BT_DBG("conn %p", conn);
conn->dev.type = &bt_link;
conn->dev.class = bt_class;
conn->dev.parent = &hdev->dev;
device_initialize(&conn->dev);
INIT_WORK(&conn->work_add, add_conn);
INIT_WORK(&conn->work_del, del_conn);
}
void hci_conn_add_sysfs(struct hci_conn *conn)
{
BT_DBG("conn %p", conn);
queue_work(conn->hdev->workqueue, &conn->work_add);
}
void hci_conn_del_sysfs(struct hci_conn *conn)
{
BT_DBG("conn %p", conn);
queue_work(conn->hdev->workqueue, &conn->work_del);
}
static inline char *host_bustostr(int bus)
{
switch (bus) {
case HCI_VIRTUAL:
return "VIRTUAL";
case HCI_USB:
return "USB";
case HCI_PCCARD:
return "PCCARD";
case HCI_UART:
return "UART";
case HCI_RS232:
return "RS232";
case HCI_PCI:
return "PCI";
case HCI_SDIO:
return "SDIO";
default:
return "UNKNOWN";
}
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
static ssize_t show_bus(struct device *dev, struct device_attribute *attr, char *buf)
{
struct hci_dev *hdev = dev_get_drvdata(dev);
return sprintf(buf, "%s\n", host_bustostr(hdev->bus));
}
static ssize_t show_type(struct device *dev, struct device_attribute *attr, char *buf)
{
struct hci_dev *hdev = dev_get_drvdata(dev);
return sprintf(buf, "%s\n", host_typetostr(hdev->dev_type));
}
static ssize_t show_name(struct device *dev, struct device_attribute *attr, char *buf)
{
struct hci_dev *hdev = dev_get_drvdata(dev);
char name[HCI_MAX_NAME_LENGTH + 1];
int i;
for (i = 0; i < HCI_MAX_NAME_LENGTH; i++)
name[i] = hdev->dev_name[i];
name[HCI_MAX_NAME_LENGTH] = '\0';
return sprintf(buf, "%s\n", name);
}
static ssize_t show_class(struct device *dev, struct device_attribute *attr, char *buf)
{
struct hci_dev *hdev = dev_get_drvdata(dev);
return sprintf(buf, "0x%.2x%.2x%.2x\n",
hdev->dev_class[2], hdev->dev_class[1], hdev->dev_class[0]);
}
static ssize_t show_address(struct device *dev, struct device_attribute *attr, char *buf)
{
struct hci_dev *hdev = dev_get_drvdata(dev);
return sprintf(buf, "%s\n", batostr(&hdev->bdaddr));
}
static ssize_t show_features(struct device *dev, struct device_attribute *attr, char *buf)
{
struct hci_dev *hdev = dev_get_drvdata(dev);
return sprintf(buf, "0x%02x%02x%02x%02x%02x%02x%02x%02x\n",
hdev->features[0], hdev->features[1],
hdev->features[2], hdev->features[3],
hdev->features[4], hdev->features[5],
hdev->features[6], hdev->features[7]);
}
static ssize_t show_manufacturer(struct device *dev, struct device_attribute *attr, char *buf)
{
struct hci_dev *hdev = dev_get_drvdata(dev);
return sprintf(buf, "%d\n", hdev->manufacturer);
}
static ssize_t show_hci_version(struct device *dev, struct device_attribute *attr, char *buf)
{
struct hci_dev *hdev = dev_get_drvdata(dev);
return sprintf(buf, "%d\n", hdev->hci_ver);
}
static ssize_t show_hci_revision(struct device *dev, struct device_attribute *attr, char *buf)
{
struct hci_dev *hdev = dev_get_drvdata(dev);
return sprintf(buf, "%d\n", hdev->hci_rev);
}
static ssize_t show_idle_timeout(struct device *dev, struct device_attribute *attr, char *buf)
{
struct hci_dev *hdev = dev_get_drvdata(dev);
return sprintf(buf, "%d\n", hdev->idle_timeout);
}
static ssize_t store_idle_timeout(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
struct hci_dev *hdev = dev_get_drvdata(dev);
unsigned int val;
int rv;
rv = kstrtouint(buf, 0, &val);
if (rv < 0)
return rv;
if (val != 0 && (val < 500 || val > 3600000))
return -EINVAL;
hdev->idle_timeout = val;
return count;
}
static ssize_t show_sniff_max_interval(struct device *dev, struct device_attribute *attr, char *buf)
{
struct hci_dev *hdev = dev_get_drvdata(dev);
return sprintf(buf, "%d\n", hdev->sniff_max_interval);
}
static ssize_t store_sniff_max_interval(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
struct hci_dev *hdev = dev_get_drvdata(dev);
u16 val;
int rv;
rv = kstrtou16(buf, 0, &val);
if (rv < 0)
return rv;
if (val == 0 || val % 2 || val < hdev->sniff_min_interval)
return -EINVAL;
hdev->sniff_max_interval = val;
return count;
}
static ssize_t show_sniff_min_interval(struct device *dev, struct device_attribute *attr, char *buf)
{
struct hci_dev *hdev = dev_get_drvdata(dev);
return sprintf(buf, "%d\n", hdev->sniff_min_interval);
}
static ssize_t store_sniff_min_interval(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
struct hci_dev *hdev = dev_get_drvdata(dev);
u16 val;
int rv;
rv = kstrtou16(buf, 0, &val);
if (rv < 0)
return rv;
if (val == 0 || val % 2 || val > hdev->sniff_max_interval)
return -EINVAL;
hdev->sniff_min_interval = val;
return count;
}
static void bt_host_release(struct device *dev)
{
void *data = dev_get_drvdata(dev);
kfree(data);
}
static int inquiry_cache_show(struct seq_file *f, void *p)
{
struct hci_dev *hdev = f->private;
struct inquiry_cache *cache = &hdev->inq_cache;
struct inquiry_entry *e;
hci_dev_lock_bh(hdev);
for (e = cache->list; e; e = e->next) {
struct inquiry_data *data = &e->data;
seq_printf(f, "%s %d %d %d 0x%.2x%.2x%.2x 0x%.4x %d %d %u\n",
batostr(&data->bdaddr),
data->pscan_rep_mode, data->pscan_period_mode,
data->pscan_mode, data->dev_class[2],
data->dev_class[1], data->dev_class[0],
__le16_to_cpu(data->clock_offset),
data->rssi, data->ssp_mode, e->timestamp);
}
hci_dev_unlock_bh(hdev);
return 0;
}
static int inquiry_cache_open(struct inode *inode, struct file *file)
{
return single_open(file, inquiry_cache_show, inode->i_private);
}
static int blacklist_show(struct seq_file *f, void *p)
{
struct hci_dev *hdev = f->private;
struct list_head *l;
hci_dev_lock_bh(hdev);
list_for_each(l, &hdev->blacklist) {
struct bdaddr_list *b;
b = list_entry(l, struct bdaddr_list, list);
seq_printf(f, "%s\n", batostr(&b->bdaddr));
}
hci_dev_unlock_bh(hdev);
return 0;
}
static int blacklist_open(struct inode *inode, struct file *file)
{
return single_open(file, blacklist_show, inode->i_private);
}
static void print_bt_uuid(struct seq_file *f, u8 *uuid)
{
u32 data0, data4;
u16 data1, data2, data3, data5;
memcpy(&data0, &uuid[0], 4);
memcpy(&data1, &uuid[4], 2);
memcpy(&data2, &uuid[6], 2);
memcpy(&data3, &uuid[8], 2);
memcpy(&data4, &uuid[10], 4);
memcpy(&data5, &uuid[14], 2);
seq_printf(f, "%.8x-%.4x-%.4x-%.4x-%.8x%.4x\n",
ntohl(data0), ntohs(data1), ntohs(data2),
ntohs(data3), ntohl(data4), ntohs(data5));
}
static int uuids_show(struct seq_file *f, void *p)
{
struct hci_dev *hdev = f->private;
struct list_head *l;
hci_dev_lock_bh(hdev);
list_for_each(l, &hdev->uuids) {
struct bt_uuid *uuid;
uuid = list_entry(l, struct bt_uuid, list);
print_bt_uuid(f, uuid->uuid);
}
hci_dev_unlock_bh(hdev);
return 0;
}
static int uuids_open(struct inode *inode, struct file *file)
{
return single_open(file, uuids_show, inode->i_private);
}
static int auto_accept_delay_set(void *data, u64 val)
{
struct hci_dev *hdev = data;
hci_dev_lock_bh(hdev);
hdev->auto_accept_delay = val;
hci_dev_unlock_bh(hdev);
return 0;
}
static int auto_accept_delay_get(void *data, u64 *val)
{
struct hci_dev *hdev = data;
hci_dev_lock_bh(hdev);
*val = hdev->auto_accept_delay;
hci_dev_unlock_bh(hdev);
return 0;
}
int hci_register_sysfs(struct hci_dev *hdev)
{
struct device *dev = &hdev->dev;
int err;
BT_DBG("%p name %s bus %d", hdev, hdev->name, hdev->bus);
dev->type = &bt_host;
dev->class = bt_class;
dev->parent = hdev->parent;
dev_set_name(dev, "%s", hdev->name);
dev_set_drvdata(dev, hdev);
err = device_register(dev);
if (err < 0)
return err;
if (!bt_debugfs)
return 0;
hdev->debugfs = debugfs_create_dir(hdev->name, bt_debugfs);
if (!hdev->debugfs)
return 0;
debugfs_create_file("inquiry_cache", 0444, hdev->debugfs,
hdev, &inquiry_cache_fops);
debugfs_create_file("blacklist", 0444, hdev->debugfs,
hdev, &blacklist_fops);
debugfs_create_file("uuids", 0444, hdev->debugfs, hdev, &uuids_fops);
debugfs_create_file("auto_accept_delay", 0444, hdev->debugfs, hdev,
&auto_accept_delay_fops);
return 0;
}
void hci_unregister_sysfs(struct hci_dev *hdev)
{
BT_DBG("%p name %s bus %d", hdev, hdev->name, hdev->bus);
debugfs_remove_recursive(hdev->debugfs);
device_del(&hdev->dev);
}
int __init bt_sysfs_init(void)
{
bt_debugfs = debugfs_create_dir("bluetooth", NULL);
bt_class = class_create(THIS_MODULE, "bluetooth");
if (IS_ERR(bt_class))
return PTR_ERR(bt_class);
return 0;
}
void bt_sysfs_cleanup(void)
{
class_destroy(bt_class);
debugfs_remove_recursive(bt_debugfs);
}
