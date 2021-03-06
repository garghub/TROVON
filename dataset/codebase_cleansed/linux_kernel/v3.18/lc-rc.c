static int uwb_rc_index_match(struct device *dev, const void *data)
{
const int *index = data;
struct uwb_rc *rc = dev_get_drvdata(dev);
if (rc->index == *index)
return 1;
return 0;
}
static struct uwb_rc *uwb_rc_find_by_index(int index)
{
struct device *dev;
struct uwb_rc *rc = NULL;
dev = class_find_device(&uwb_rc_class, NULL, &index, uwb_rc_index_match);
if (dev)
rc = dev_get_drvdata(dev);
return rc;
}
static int uwb_rc_new_index(void)
{
int index = 0;
for (;;) {
if (!uwb_rc_find_by_index(index))
return index;
if (++index < 0)
index = 0;
}
}
static void uwb_rc_sys_release(struct device *dev)
{
struct uwb_dev *uwb_dev = container_of(dev, struct uwb_dev, dev);
struct uwb_rc *rc = container_of(uwb_dev, struct uwb_rc, uwb_dev);
uwb_rc_ie_release(rc);
kfree(rc);
}
void uwb_rc_init(struct uwb_rc *rc)
{
struct uwb_dev *uwb_dev = &rc->uwb_dev;
uwb_dev_init(uwb_dev);
rc->uwb_dev.dev.class = &uwb_rc_class;
rc->uwb_dev.dev.release = uwb_rc_sys_release;
uwb_rc_neh_create(rc);
rc->beaconing = -1;
rc->scan_type = UWB_SCAN_DISABLED;
INIT_LIST_HEAD(&rc->notifs_chain.list);
mutex_init(&rc->notifs_chain.mutex);
INIT_LIST_HEAD(&rc->uwb_beca.list);
mutex_init(&rc->uwb_beca.mutex);
uwb_drp_avail_init(rc);
uwb_rc_ie_init(rc);
uwb_rsv_init(rc);
uwb_rc_pal_init(rc);
}
struct uwb_rc *uwb_rc_alloc(void)
{
struct uwb_rc *rc;
rc = kzalloc(sizeof(*rc), GFP_KERNEL);
if (rc == NULL)
return NULL;
uwb_rc_init(rc);
return rc;
}
static ssize_t ASIE_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct uwb_dev *uwb_dev = to_uwb_dev(dev);
struct uwb_rc *rc = uwb_dev->rc;
struct uwb_ie_hdr *ie;
void *ptr;
size_t len;
int result = 0;
result = scnprintf(buf, PAGE_SIZE, "\n");
mutex_lock(&rc->ies_mutex);
ptr = rc->ies->IEData;
len = le16_to_cpu(rc->ies->wIELength);
for (;;) {
ie = uwb_ie_next(&ptr, &len);
if (!ie)
break;
if (ie->element_id == UWB_APP_SPEC_IE) {
result = uwb_ie_dump_hex(ie,
ie->length + sizeof(struct uwb_ie_hdr),
buf, PAGE_SIZE);
break;
}
}
mutex_unlock(&rc->ies_mutex);
return result;
}
static ssize_t ASIE_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
struct uwb_dev *uwb_dev = to_uwb_dev(dev);
struct uwb_rc *rc = uwb_dev->rc;
char ie_buf[255];
int result, ie_len = 0;
const char *cur_ptr = buf;
struct uwb_ie_hdr *ie;
if (strlen(buf) <= 1) {
uwb_rc_ie_rm(rc, UWB_APP_SPEC_IE);
return size;
}
while (ie_len < sizeof(ie_buf)) {
int char_count;
if (sscanf(cur_ptr, " %02hhX %n",
&(ie_buf[ie_len]), &char_count) > 0) {
++ie_len;
cur_ptr += char_count;
} else {
break;
}
}
if (ie_len < sizeof(struct uwb_ie_hdr)) {
dev_err(dev, "%s: Invalid ASIE size %d.\n", __func__, ie_len);
return -EINVAL;
}
ie = (struct uwb_ie_hdr *)ie_buf;
if (ie->element_id != UWB_APP_SPEC_IE) {
dev_err(dev, "%s: Invalid IE element type size = 0x%02X.\n",
__func__, ie->element_id);
return -EINVAL;
}
if (ie->length > (ie_len - sizeof(struct uwb_ie_hdr)))
ie->length = ie_len - sizeof(struct uwb_ie_hdr);
uwb_rc_ie_rm(rc, UWB_APP_SPEC_IE);
result = uwb_rc_ie_add(rc, ie, ie->length + sizeof(struct uwb_ie_hdr));
return result >= 0 ? size : result;
}
static int uwb_rc_sys_add(struct uwb_rc *rc)
{
return sysfs_create_group(&rc->uwb_dev.dev.kobj, &rc_attr_group);
}
static void __uwb_rc_sys_rm(struct uwb_rc *rc)
{
sysfs_remove_group(&rc->uwb_dev.dev.kobj, &rc_attr_group);
}
static
int uwb_rc_mac_addr_setup(struct uwb_rc *rc)
{
int result;
struct device *dev = &rc->uwb_dev.dev;
struct uwb_dev *uwb_dev = &rc->uwb_dev;
char devname[UWB_ADDR_STRSIZE];
struct uwb_mac_addr addr;
result = uwb_rc_mac_addr_get(rc, &addr);
if (result < 0) {
dev_err(dev, "cannot retrieve UWB EUI-48 address: %d\n", result);
return result;
}
if (uwb_mac_addr_unset(&addr) || uwb_mac_addr_bcast(&addr)) {
addr.data[0] = 0x02;
get_random_bytes(&addr.data[1], sizeof(addr.data)-1);
result = uwb_rc_mac_addr_set(rc, &addr);
if (result < 0) {
uwb_mac_addr_print(devname, sizeof(devname), &addr);
dev_err(dev, "cannot set EUI-48 address %s: %d\n",
devname, result);
return result;
}
}
uwb_dev->mac_addr = addr;
return 0;
}
static int uwb_rc_setup(struct uwb_rc *rc)
{
int result;
struct device *dev = &rc->uwb_dev.dev;
result = uwb_radio_setup(rc);
if (result < 0) {
dev_err(dev, "cannot setup UWB radio: %d\n", result);
goto error;
}
result = uwb_rc_mac_addr_setup(rc);
if (result < 0) {
dev_err(dev, "cannot setup UWB MAC address: %d\n", result);
goto error;
}
result = uwb_rc_dev_addr_assign(rc);
if (result < 0) {
dev_err(dev, "cannot assign UWB DevAddr: %d\n", result);
goto error;
}
result = uwb_rc_ie_setup(rc);
if (result < 0) {
dev_err(dev, "cannot setup IE subsystem: %d\n", result);
goto error_ie_setup;
}
result = uwb_rsv_setup(rc);
if (result < 0) {
dev_err(dev, "cannot setup reservation subsystem: %d\n", result);
goto error_rsv_setup;
}
uwb_dbg_add_rc(rc);
return 0;
error_rsv_setup:
uwb_rc_ie_release(rc);
error_ie_setup:
error:
return result;
}
int uwb_rc_add(struct uwb_rc *rc, struct device *parent_dev, void *priv)
{
int result;
struct device *dev;
char macbuf[UWB_ADDR_STRSIZE], devbuf[UWB_ADDR_STRSIZE];
rc->index = uwb_rc_new_index();
dev = &rc->uwb_dev.dev;
dev_set_name(dev, "uwb%d", rc->index);
rc->priv = priv;
init_waitqueue_head(&rc->uwbd.wq);
INIT_LIST_HEAD(&rc->uwbd.event_list);
spin_lock_init(&rc->uwbd.event_list_lock);
uwbd_start(rc);
result = rc->start(rc);
if (result < 0)
goto error_rc_start;
result = uwb_rc_setup(rc);
if (result < 0) {
dev_err(dev, "cannot setup UWB radio controller: %d\n", result);
goto error_rc_setup;
}
result = uwb_dev_add(&rc->uwb_dev, parent_dev, rc);
if (result < 0 && result != -EADDRNOTAVAIL)
goto error_dev_add;
result = uwb_rc_sys_add(rc);
if (result < 0) {
dev_err(parent_dev, "cannot register UWB radio controller "
"dev attributes: %d\n", result);
goto error_sys_add;
}
uwb_mac_addr_print(macbuf, sizeof(macbuf), &rc->uwb_dev.mac_addr);
uwb_dev_addr_print(devbuf, sizeof(devbuf), &rc->uwb_dev.dev_addr);
dev_info(dev,
"new uwb radio controller (mac %s dev %s) on %s %s\n",
macbuf, devbuf, parent_dev->bus->name, dev_name(parent_dev));
rc->ready = 1;
return 0;
error_sys_add:
uwb_dev_rm(&rc->uwb_dev);
error_dev_add:
error_rc_setup:
rc->stop(rc);
error_rc_start:
uwbd_stop(rc);
return result;
}
static int uwb_dev_offair_helper(struct device *dev, void *priv)
{
struct uwb_dev *uwb_dev = to_uwb_dev(dev);
return __uwb_dev_offair(uwb_dev, uwb_dev->rc);
}
void uwb_rc_rm(struct uwb_rc *rc)
{
rc->ready = 0;
uwb_dbg_del_rc(rc);
uwb_rsv_remove_all(rc);
uwb_radio_shutdown(rc);
rc->stop(rc);
uwbd_stop(rc);
uwb_rc_neh_destroy(rc);
uwb_dev_lock(&rc->uwb_dev);
rc->priv = NULL;
rc->cmd = NULL;
uwb_dev_unlock(&rc->uwb_dev);
mutex_lock(&rc->uwb_beca.mutex);
uwb_dev_for_each(rc, uwb_dev_offair_helper, NULL);
__uwb_rc_sys_rm(rc);
mutex_unlock(&rc->uwb_beca.mutex);
uwb_rsv_cleanup(rc);
uwb_beca_release(rc);
uwb_dev_rm(&rc->uwb_dev);
}
static int find_rc_try_get(struct device *dev, const void *data)
{
const struct uwb_rc *target_rc = data;
struct uwb_rc *rc = dev_get_drvdata(dev);
if (rc == NULL) {
WARN_ON(1);
return 0;
}
if (rc == target_rc) {
if (rc->ready == 0)
return 0;
else
return 1;
}
return 0;
}
struct uwb_rc *__uwb_rc_try_get(struct uwb_rc *target_rc)
{
struct device *dev;
struct uwb_rc *rc = NULL;
dev = class_find_device(&uwb_rc_class, NULL, target_rc,
find_rc_try_get);
if (dev) {
rc = dev_get_drvdata(dev);
__uwb_rc_get(rc);
}
return rc;
}
static inline struct uwb_rc *uwb_rc_get(struct uwb_rc *rc)
{
if (rc->ready == 0)
return NULL;
uwb_dev_get(&rc->uwb_dev);
return rc;
}
static int find_rc_grandpa(struct device *dev, const void *data)
{
const struct device *grandpa_dev = data;
struct uwb_rc *rc = dev_get_drvdata(dev);
if (rc->uwb_dev.dev.parent->parent == grandpa_dev) {
rc = uwb_rc_get(rc);
return 1;
}
return 0;
}
struct uwb_rc *uwb_rc_get_by_grandpa(const struct device *grandpa_dev)
{
struct device *dev;
struct uwb_rc *rc = NULL;
dev = class_find_device(&uwb_rc_class, NULL, grandpa_dev,
find_rc_grandpa);
if (dev)
rc = dev_get_drvdata(dev);
return rc;
}
static int find_rc_dev(struct device *dev, const void *data)
{
const struct uwb_dev_addr *addr = data;
struct uwb_rc *rc = dev_get_drvdata(dev);
if (rc == NULL) {
WARN_ON(1);
return 0;
}
if (!uwb_dev_addr_cmp(&rc->uwb_dev.dev_addr, addr)) {
rc = uwb_rc_get(rc);
return 1;
}
return 0;
}
struct uwb_rc *uwb_rc_get_by_dev(const struct uwb_dev_addr *addr)
{
struct device *dev;
struct uwb_rc *rc = NULL;
dev = class_find_device(&uwb_rc_class, NULL, addr, find_rc_dev);
if (dev)
rc = dev_get_drvdata(dev);
return rc;
}
void uwb_rc_put(struct uwb_rc *rc)
{
__uwb_rc_put(rc);
}
