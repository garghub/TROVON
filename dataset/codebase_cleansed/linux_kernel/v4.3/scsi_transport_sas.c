static struct sas_end_device *sas_sdev_to_rdev(struct scsi_device *sdev)
{
struct sas_rphy *rphy = target_to_rphy(sdev->sdev_target);
struct sas_end_device *rdev;
BUG_ON(rphy->identify.device_type != SAS_END_DEVICE);
rdev = rphy_to_end_device(rphy);
return rdev;
}
static void sas_smp_request(struct request_queue *q, struct Scsi_Host *shost,
struct sas_rphy *rphy)
{
struct request *req;
int ret;
int (*handler)(struct Scsi_Host *, struct sas_rphy *, struct request *);
while ((req = blk_fetch_request(q)) != NULL) {
spin_unlock_irq(q->queue_lock);
handler = to_sas_internal(shost->transportt)->f->smp_handler;
ret = handler(shost, rphy, req);
req->errors = ret;
blk_end_request_all(req, ret);
spin_lock_irq(q->queue_lock);
}
}
static void sas_host_smp_request(struct request_queue *q)
{
sas_smp_request(q, (struct Scsi_Host *)q->queuedata, NULL);
}
static void sas_non_host_smp_request(struct request_queue *q)
{
struct sas_rphy *rphy = q->queuedata;
sas_smp_request(q, rphy_to_shost(rphy), rphy);
}
static void sas_host_release(struct device *dev)
{
struct Scsi_Host *shost = dev_to_shost(dev);
struct sas_host_attrs *sas_host = to_sas_host_attrs(shost);
struct request_queue *q = sas_host->q;
if (q)
blk_cleanup_queue(q);
}
static int sas_bsg_initialize(struct Scsi_Host *shost, struct sas_rphy *rphy)
{
struct request_queue *q;
int error;
struct device *dev;
char namebuf[20];
const char *name;
void (*release)(struct device *);
if (!to_sas_internal(shost->transportt)->f->smp_handler) {
printk("%s can't handle SMP requests\n", shost->hostt->name);
return 0;
}
if (rphy) {
q = blk_init_queue(sas_non_host_smp_request, NULL);
dev = &rphy->dev;
name = dev_name(dev);
release = NULL;
} else {
q = blk_init_queue(sas_host_smp_request, NULL);
dev = &shost->shost_gendev;
snprintf(namebuf, sizeof(namebuf),
"sas_host%d", shost->host_no);
name = namebuf;
release = sas_host_release;
}
if (!q)
return -ENOMEM;
error = bsg_register_queue(q, dev, name, release);
if (error) {
blk_cleanup_queue(q);
return -ENOMEM;
}
if (rphy)
rphy->q = q;
else
to_sas_host_attrs(shost)->q = q;
if (rphy)
q->queuedata = rphy;
else
q->queuedata = shost;
queue_flag_set_unlocked(QUEUE_FLAG_BIDI, q);
return 0;
}
static void sas_bsg_remove(struct Scsi_Host *shost, struct sas_rphy *rphy)
{
struct request_queue *q;
if (rphy)
q = rphy->q;
else
q = to_sas_host_attrs(shost)->q;
if (!q)
return;
bsg_unregister_queue(q);
}
static int sas_host_setup(struct transport_container *tc, struct device *dev,
struct device *cdev)
{
struct Scsi_Host *shost = dev_to_shost(dev);
struct sas_host_attrs *sas_host = to_sas_host_attrs(shost);
INIT_LIST_HEAD(&sas_host->rphy_list);
mutex_init(&sas_host->lock);
sas_host->next_target_id = 0;
sas_host->next_expander_id = 0;
sas_host->next_port_id = 0;
if (sas_bsg_initialize(shost, NULL))
dev_printk(KERN_ERR, dev, "fail to a bsg device %d\n",
shost->host_no);
return 0;
}
static int sas_host_remove(struct transport_container *tc, struct device *dev,
struct device *cdev)
{
struct Scsi_Host *shost = dev_to_shost(dev);
sas_bsg_remove(shost, NULL);
return 0;
}
static int sas_host_match(struct attribute_container *cont,
struct device *dev)
{
struct Scsi_Host *shost;
struct sas_internal *i;
if (!scsi_is_host_device(dev))
return 0;
shost = dev_to_shost(dev);
if (!shost->transportt)
return 0;
if (shost->transportt->host_attrs.ac.class !=
&sas_host_class.class)
return 0;
i = to_sas_internal(shost->transportt);
return &i->t.host_attrs.ac == cont;
}
static int do_sas_phy_delete(struct device *dev, void *data)
{
int pass = (int)(unsigned long)data;
if (pass == 0 && scsi_is_sas_port(dev))
sas_port_delete(dev_to_sas_port(dev));
else if (pass == 1 && scsi_is_sas_phy(dev))
sas_phy_delete(dev_to_phy(dev));
return 0;
}
void sas_remove_children(struct device *dev)
{
device_for_each_child(dev, (void *)0, do_sas_phy_delete);
device_for_each_child(dev, (void *)1, do_sas_phy_delete);
}
void sas_remove_host(struct Scsi_Host *shost)
{
sas_remove_children(&shost->shost_gendev);
}
unsigned int
sas_tlr_supported(struct scsi_device *sdev)
{
const int vpd_len = 32;
struct sas_end_device *rdev = sas_sdev_to_rdev(sdev);
char *buffer = kzalloc(vpd_len, GFP_KERNEL);
int ret = 0;
if (scsi_get_vpd_page(sdev, 0x90, buffer, vpd_len))
goto out;
ret = buffer[12] & 0x01;
out:
kfree(buffer);
rdev->tlr_supported = ret;
return ret;
}
void
sas_disable_tlr(struct scsi_device *sdev)
{
struct sas_end_device *rdev = sas_sdev_to_rdev(sdev);
rdev->tlr_enabled = 0;
}
void sas_enable_tlr(struct scsi_device *sdev)
{
unsigned int tlr_supported = 0;
tlr_supported = sas_tlr_supported(sdev);
if (tlr_supported) {
struct sas_end_device *rdev = sas_sdev_to_rdev(sdev);
rdev->tlr_enabled = 1;
}
return;
}
unsigned int sas_is_tlr_enabled(struct scsi_device *sdev)
{
struct sas_end_device *rdev = sas_sdev_to_rdev(sdev);
return rdev->tlr_enabled;
}
static ssize_t
show_sas_device_type(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct sas_phy *phy = transport_class_to_phy(dev);
if (!phy->identify.device_type)
return snprintf(buf, 20, "none\n");
return get_sas_device_type_names(phy->identify.device_type, buf);
}
static ssize_t do_sas_phy_enable(struct device *dev,
size_t count, int enable)
{
struct sas_phy *phy = transport_class_to_phy(dev);
struct Scsi_Host *shost = dev_to_shost(phy->dev.parent);
struct sas_internal *i = to_sas_internal(shost->transportt);
int error;
error = i->f->phy_enable(phy, enable);
if (error)
return error;
phy->enabled = enable;
return count;
}
static ssize_t
store_sas_phy_enable(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
if (count < 1)
return -EINVAL;
switch (buf[0]) {
case '0':
do_sas_phy_enable(dev, count, 0);
break;
case '1':
do_sas_phy_enable(dev, count, 1);
break;
default:
return -EINVAL;
}
return count;
}
static ssize_t
show_sas_phy_enable(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sas_phy *phy = transport_class_to_phy(dev);
return snprintf(buf, 20, "%d", phy->enabled);
}
static ssize_t
do_sas_phy_reset(struct device *dev, size_t count, int hard_reset)
{
struct sas_phy *phy = transport_class_to_phy(dev);
struct Scsi_Host *shost = dev_to_shost(phy->dev.parent);
struct sas_internal *i = to_sas_internal(shost->transportt);
int error;
error = i->f->phy_reset(phy, hard_reset);
if (error)
return error;
phy->enabled = 1;
return count;
}
static ssize_t
store_sas_link_reset(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
return do_sas_phy_reset(dev, count, 0);
}
static ssize_t
store_sas_hard_reset(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
return do_sas_phy_reset(dev, count, 1);
}
static int sas_phy_setup(struct transport_container *tc, struct device *dev,
struct device *cdev)
{
struct sas_phy *phy = dev_to_phy(dev);
struct Scsi_Host *shost = dev_to_shost(phy->dev.parent);
struct sas_internal *i = to_sas_internal(shost->transportt);
if (i->f->phy_setup)
i->f->phy_setup(phy);
return 0;
}
static int sas_phy_match(struct attribute_container *cont, struct device *dev)
{
struct Scsi_Host *shost;
struct sas_internal *i;
if (!scsi_is_sas_phy(dev))
return 0;
shost = dev_to_shost(dev->parent);
if (!shost->transportt)
return 0;
if (shost->transportt->host_attrs.ac.class !=
&sas_host_class.class)
return 0;
i = to_sas_internal(shost->transportt);
return &i->phy_attr_cont.ac == cont;
}
static void sas_phy_release(struct device *dev)
{
struct sas_phy *phy = dev_to_phy(dev);
struct Scsi_Host *shost = dev_to_shost(phy->dev.parent);
struct sas_internal *i = to_sas_internal(shost->transportt);
if (i->f->phy_release)
i->f->phy_release(phy);
put_device(dev->parent);
kfree(phy);
}
struct sas_phy *sas_phy_alloc(struct device *parent, int number)
{
struct Scsi_Host *shost = dev_to_shost(parent);
struct sas_phy *phy;
phy = kzalloc(sizeof(*phy), GFP_KERNEL);
if (!phy)
return NULL;
phy->number = number;
phy->enabled = 1;
device_initialize(&phy->dev);
phy->dev.parent = get_device(parent);
phy->dev.release = sas_phy_release;
INIT_LIST_HEAD(&phy->port_siblings);
if (scsi_is_sas_expander_device(parent)) {
struct sas_rphy *rphy = dev_to_rphy(parent);
dev_set_name(&phy->dev, "phy-%d:%d:%d", shost->host_no,
rphy->scsi_target_id, number);
} else
dev_set_name(&phy->dev, "phy-%d:%d", shost->host_no, number);
transport_setup_device(&phy->dev);
return phy;
}
int sas_phy_add(struct sas_phy *phy)
{
int error;
error = device_add(&phy->dev);
if (!error) {
transport_add_device(&phy->dev);
transport_configure_device(&phy->dev);
}
return error;
}
void sas_phy_free(struct sas_phy *phy)
{
transport_destroy_device(&phy->dev);
put_device(&phy->dev);
}
void
sas_phy_delete(struct sas_phy *phy)
{
struct device *dev = &phy->dev;
BUG_ON(!list_empty(&phy->port_siblings));
transport_remove_device(dev);
device_del(dev);
transport_destroy_device(dev);
put_device(dev);
}
int scsi_is_sas_phy(const struct device *dev)
{
return dev->release == sas_phy_release;
}
static int sas_port_match(struct attribute_container *cont, struct device *dev)
{
struct Scsi_Host *shost;
struct sas_internal *i;
if (!scsi_is_sas_port(dev))
return 0;
shost = dev_to_shost(dev->parent);
if (!shost->transportt)
return 0;
if (shost->transportt->host_attrs.ac.class !=
&sas_host_class.class)
return 0;
i = to_sas_internal(shost->transportt);
return &i->port_attr_cont.ac == cont;
}
static void sas_port_release(struct device *dev)
{
struct sas_port *port = dev_to_sas_port(dev);
BUG_ON(!list_empty(&port->phy_list));
put_device(dev->parent);
kfree(port);
}
static void sas_port_create_link(struct sas_port *port,
struct sas_phy *phy)
{
int res;
res = sysfs_create_link(&port->dev.kobj, &phy->dev.kobj,
dev_name(&phy->dev));
if (res)
goto err;
res = sysfs_create_link(&phy->dev.kobj, &port->dev.kobj, "port");
if (res)
goto err;
return;
err:
printk(KERN_ERR "%s: Cannot create port links, err=%d\n",
__func__, res);
}
static void sas_port_delete_link(struct sas_port *port,
struct sas_phy *phy)
{
sysfs_remove_link(&port->dev.kobj, dev_name(&phy->dev));
sysfs_remove_link(&phy->dev.kobj, "port");
}
struct sas_port *sas_port_alloc(struct device *parent, int port_id)
{
struct Scsi_Host *shost = dev_to_shost(parent);
struct sas_port *port;
port = kzalloc(sizeof(*port), GFP_KERNEL);
if (!port)
return NULL;
port->port_identifier = port_id;
device_initialize(&port->dev);
port->dev.parent = get_device(parent);
port->dev.release = sas_port_release;
mutex_init(&port->phy_list_mutex);
INIT_LIST_HEAD(&port->phy_list);
if (scsi_is_sas_expander_device(parent)) {
struct sas_rphy *rphy = dev_to_rphy(parent);
dev_set_name(&port->dev, "port-%d:%d:%d", shost->host_no,
rphy->scsi_target_id, port->port_identifier);
} else
dev_set_name(&port->dev, "port-%d:%d", shost->host_no,
port->port_identifier);
transport_setup_device(&port->dev);
return port;
}
struct sas_port *sas_port_alloc_num(struct device *parent)
{
int index;
struct Scsi_Host *shost = dev_to_shost(parent);
struct sas_host_attrs *sas_host = to_sas_host_attrs(shost);
mutex_lock(&sas_host->lock);
if (scsi_is_sas_expander_device(parent)) {
struct sas_rphy *rphy = dev_to_rphy(parent);
struct sas_expander_device *exp = rphy_to_expander_device(rphy);
index = exp->next_port_id++;
} else
index = sas_host->next_port_id++;
mutex_unlock(&sas_host->lock);
return sas_port_alloc(parent, index);
}
int sas_port_add(struct sas_port *port)
{
int error;
BUG_ON(!list_empty(&port->phy_list));
error = device_add(&port->dev);
if (error)
return error;
transport_add_device(&port->dev);
transport_configure_device(&port->dev);
return 0;
}
void sas_port_free(struct sas_port *port)
{
transport_destroy_device(&port->dev);
put_device(&port->dev);
}
void sas_port_delete(struct sas_port *port)
{
struct device *dev = &port->dev;
struct sas_phy *phy, *tmp_phy;
if (port->rphy) {
sas_rphy_delete(port->rphy);
port->rphy = NULL;
}
mutex_lock(&port->phy_list_mutex);
list_for_each_entry_safe(phy, tmp_phy, &port->phy_list,
port_siblings) {
sas_port_delete_link(port, phy);
list_del_init(&phy->port_siblings);
}
mutex_unlock(&port->phy_list_mutex);
if (port->is_backlink) {
struct device *parent = port->dev.parent;
sysfs_remove_link(&port->dev.kobj, dev_name(parent));
port->is_backlink = 0;
}
transport_remove_device(dev);
device_del(dev);
transport_destroy_device(dev);
put_device(dev);
}
int scsi_is_sas_port(const struct device *dev)
{
return dev->release == sas_port_release;
}
struct sas_phy *sas_port_get_phy(struct sas_port *port)
{
struct sas_phy *phy;
mutex_lock(&port->phy_list_mutex);
if (list_empty(&port->phy_list))
phy = NULL;
else {
struct list_head *ent = port->phy_list.next;
phy = list_entry(ent, typeof(*phy), port_siblings);
get_device(&phy->dev);
}
mutex_unlock(&port->phy_list_mutex);
return phy;
}
void sas_port_add_phy(struct sas_port *port, struct sas_phy *phy)
{
mutex_lock(&port->phy_list_mutex);
if (unlikely(!list_empty(&phy->port_siblings))) {
struct sas_phy *tmp;
list_for_each_entry(tmp, &port->phy_list, port_siblings)
if (tmp == phy)
break;
if (unlikely(tmp != phy)) {
dev_printk(KERN_ERR, &port->dev, "trying to add phy %s fails: it's already part of another port\n",
dev_name(&phy->dev));
BUG();
}
} else {
sas_port_create_link(port, phy);
list_add_tail(&phy->port_siblings, &port->phy_list);
port->num_phys++;
}
mutex_unlock(&port->phy_list_mutex);
}
void sas_port_delete_phy(struct sas_port *port, struct sas_phy *phy)
{
mutex_lock(&port->phy_list_mutex);
sas_port_delete_link(port, phy);
list_del_init(&phy->port_siblings);
port->num_phys--;
mutex_unlock(&port->phy_list_mutex);
}
void sas_port_mark_backlink(struct sas_port *port)
{
int res;
struct device *parent = port->dev.parent->parent->parent;
if (port->is_backlink)
return;
port->is_backlink = 1;
res = sysfs_create_link(&port->dev.kobj, &parent->kobj,
dev_name(parent));
if (res)
goto err;
return;
err:
printk(KERN_ERR "%s: Cannot create port backlink, err=%d\n",
__func__, res);
}
static ssize_t
show_sas_rphy_device_type(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct sas_rphy *rphy = transport_class_to_rphy(dev);
if (!rphy->identify.device_type)
return snprintf(buf, 20, "none\n");
return get_sas_device_type_names(
rphy->identify.device_type, buf);
}
static ssize_t
show_sas_rphy_enclosure_identifier(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct sas_rphy *rphy = transport_class_to_rphy(dev);
struct sas_phy *phy = dev_to_phy(rphy->dev.parent);
struct Scsi_Host *shost = dev_to_shost(phy->dev.parent);
struct sas_internal *i = to_sas_internal(shost->transportt);
u64 identifier;
int error;
error = i->f->get_enclosure_identifier(rphy, &identifier);
if (error)
return error;
return sprintf(buf, "0x%llx\n", (unsigned long long)identifier);
}
static ssize_t
show_sas_rphy_bay_identifier(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct sas_rphy *rphy = transport_class_to_rphy(dev);
struct sas_phy *phy = dev_to_phy(rphy->dev.parent);
struct Scsi_Host *shost = dev_to_shost(phy->dev.parent);
struct sas_internal *i = to_sas_internal(shost->transportt);
int val;
val = i->f->get_bay_identifier(rphy);
if (val < 0)
return val;
return sprintf(buf, "%d\n", val);
}
int sas_read_port_mode_page(struct scsi_device *sdev)
{
char *buffer = kzalloc(BUF_SIZE, GFP_KERNEL), *msdata;
struct sas_end_device *rdev = sas_sdev_to_rdev(sdev);
struct scsi_mode_data mode_data;
int res, error;
if (!buffer)
return -ENOMEM;
res = scsi_mode_sense(sdev, 1, 0x19, buffer, BUF_SIZE, 30*HZ, 3,
&mode_data, NULL);
error = -EINVAL;
if (!scsi_status_is_good(res))
goto out;
msdata = buffer + mode_data.header_length +
mode_data.block_descriptor_length;
if (msdata - buffer > BUF_SIZE - 8)
goto out;
error = 0;
rdev->ready_led_meaning = msdata[2] & 0x10 ? 1 : 0;
rdev->I_T_nexus_loss_timeout = (msdata[4] << 8) + msdata[5];
rdev->initiator_response_timeout = (msdata[6] << 8) + msdata[7];
out:
kfree(buffer);
return error;
}
static int sas_rphy_match(struct attribute_container *cont, struct device *dev)
{
struct Scsi_Host *shost;
struct sas_internal *i;
if (!scsi_is_sas_rphy(dev))
return 0;
shost = dev_to_shost(dev->parent->parent);
if (!shost->transportt)
return 0;
if (shost->transportt->host_attrs.ac.class !=
&sas_host_class.class)
return 0;
i = to_sas_internal(shost->transportt);
return &i->rphy_attr_cont.ac == cont;
}
static int sas_end_dev_match(struct attribute_container *cont,
struct device *dev)
{
struct Scsi_Host *shost;
struct sas_internal *i;
struct sas_rphy *rphy;
if (!scsi_is_sas_rphy(dev))
return 0;
shost = dev_to_shost(dev->parent->parent);
rphy = dev_to_rphy(dev);
if (!shost->transportt)
return 0;
if (shost->transportt->host_attrs.ac.class !=
&sas_host_class.class)
return 0;
i = to_sas_internal(shost->transportt);
return &i->end_dev_attr_cont.ac == cont &&
rphy->identify.device_type == SAS_END_DEVICE;
}
static int sas_expander_match(struct attribute_container *cont,
struct device *dev)
{
struct Scsi_Host *shost;
struct sas_internal *i;
struct sas_rphy *rphy;
if (!scsi_is_sas_rphy(dev))
return 0;
shost = dev_to_shost(dev->parent->parent);
rphy = dev_to_rphy(dev);
if (!shost->transportt)
return 0;
if (shost->transportt->host_attrs.ac.class !=
&sas_host_class.class)
return 0;
i = to_sas_internal(shost->transportt);
return &i->expander_attr_cont.ac == cont &&
(rphy->identify.device_type == SAS_EDGE_EXPANDER_DEVICE ||
rphy->identify.device_type == SAS_FANOUT_EXPANDER_DEVICE);
}
static void sas_expander_release(struct device *dev)
{
struct sas_rphy *rphy = dev_to_rphy(dev);
struct sas_expander_device *edev = rphy_to_expander_device(rphy);
if (rphy->q)
blk_cleanup_queue(rphy->q);
put_device(dev->parent);
kfree(edev);
}
static void sas_end_device_release(struct device *dev)
{
struct sas_rphy *rphy = dev_to_rphy(dev);
struct sas_end_device *edev = rphy_to_end_device(rphy);
if (rphy->q)
blk_cleanup_queue(rphy->q);
put_device(dev->parent);
kfree(edev);
}
static void sas_rphy_initialize(struct sas_rphy *rphy)
{
INIT_LIST_HEAD(&rphy->list);
}
struct sas_rphy *sas_end_device_alloc(struct sas_port *parent)
{
struct Scsi_Host *shost = dev_to_shost(&parent->dev);
struct sas_end_device *rdev;
rdev = kzalloc(sizeof(*rdev), GFP_KERNEL);
if (!rdev) {
return NULL;
}
device_initialize(&rdev->rphy.dev);
rdev->rphy.dev.parent = get_device(&parent->dev);
rdev->rphy.dev.release = sas_end_device_release;
if (scsi_is_sas_expander_device(parent->dev.parent)) {
struct sas_rphy *rphy = dev_to_rphy(parent->dev.parent);
dev_set_name(&rdev->rphy.dev, "end_device-%d:%d:%d",
shost->host_no, rphy->scsi_target_id,
parent->port_identifier);
} else
dev_set_name(&rdev->rphy.dev, "end_device-%d:%d",
shost->host_no, parent->port_identifier);
rdev->rphy.identify.device_type = SAS_END_DEVICE;
sas_rphy_initialize(&rdev->rphy);
transport_setup_device(&rdev->rphy.dev);
return &rdev->rphy;
}
struct sas_rphy *sas_expander_alloc(struct sas_port *parent,
enum sas_device_type type)
{
struct Scsi_Host *shost = dev_to_shost(&parent->dev);
struct sas_expander_device *rdev;
struct sas_host_attrs *sas_host = to_sas_host_attrs(shost);
BUG_ON(type != SAS_EDGE_EXPANDER_DEVICE &&
type != SAS_FANOUT_EXPANDER_DEVICE);
rdev = kzalloc(sizeof(*rdev), GFP_KERNEL);
if (!rdev) {
return NULL;
}
device_initialize(&rdev->rphy.dev);
rdev->rphy.dev.parent = get_device(&parent->dev);
rdev->rphy.dev.release = sas_expander_release;
mutex_lock(&sas_host->lock);
rdev->rphy.scsi_target_id = sas_host->next_expander_id++;
mutex_unlock(&sas_host->lock);
dev_set_name(&rdev->rphy.dev, "expander-%d:%d",
shost->host_no, rdev->rphy.scsi_target_id);
rdev->rphy.identify.device_type = type;
sas_rphy_initialize(&rdev->rphy);
transport_setup_device(&rdev->rphy.dev);
return &rdev->rphy;
}
int sas_rphy_add(struct sas_rphy *rphy)
{
struct sas_port *parent = dev_to_sas_port(rphy->dev.parent);
struct Scsi_Host *shost = dev_to_shost(parent->dev.parent);
struct sas_host_attrs *sas_host = to_sas_host_attrs(shost);
struct sas_identify *identify = &rphy->identify;
int error;
if (parent->rphy)
return -ENXIO;
parent->rphy = rphy;
error = device_add(&rphy->dev);
if (error)
return error;
transport_add_device(&rphy->dev);
transport_configure_device(&rphy->dev);
if (sas_bsg_initialize(shost, rphy))
printk("fail to a bsg device %s\n", dev_name(&rphy->dev));
mutex_lock(&sas_host->lock);
list_add_tail(&rphy->list, &sas_host->rphy_list);
if (identify->device_type == SAS_END_DEVICE &&
(identify->target_port_protocols &
(SAS_PROTOCOL_SSP|SAS_PROTOCOL_STP|SAS_PROTOCOL_SATA)))
rphy->scsi_target_id = sas_host->next_target_id++;
else if (identify->device_type == SAS_END_DEVICE)
rphy->scsi_target_id = -1;
mutex_unlock(&sas_host->lock);
if (identify->device_type == SAS_END_DEVICE &&
rphy->scsi_target_id != -1) {
int lun;
if (identify->target_port_protocols & SAS_PROTOCOL_SSP)
lun = SCAN_WILD_CARD;
else
lun = 0;
scsi_scan_target(&rphy->dev, 0, rphy->scsi_target_id, lun, 0);
}
return 0;
}
void sas_rphy_free(struct sas_rphy *rphy)
{
struct device *dev = &rphy->dev;
struct Scsi_Host *shost = dev_to_shost(rphy->dev.parent->parent);
struct sas_host_attrs *sas_host = to_sas_host_attrs(shost);
mutex_lock(&sas_host->lock);
list_del(&rphy->list);
mutex_unlock(&sas_host->lock);
transport_destroy_device(dev);
put_device(dev);
}
void
sas_rphy_delete(struct sas_rphy *rphy)
{
sas_rphy_remove(rphy);
sas_rphy_free(rphy);
}
void sas_rphy_unlink(struct sas_rphy *rphy)
{
struct sas_port *parent = dev_to_sas_port(rphy->dev.parent);
parent->rphy = NULL;
}
void
sas_rphy_remove(struct sas_rphy *rphy)
{
struct device *dev = &rphy->dev;
switch (rphy->identify.device_type) {
case SAS_END_DEVICE:
scsi_remove_target(dev);
break;
case SAS_EDGE_EXPANDER_DEVICE:
case SAS_FANOUT_EXPANDER_DEVICE:
sas_remove_children(dev);
break;
default:
break;
}
sas_rphy_unlink(rphy);
sas_bsg_remove(NULL, rphy);
transport_remove_device(dev);
device_del(dev);
}
int scsi_is_sas_rphy(const struct device *dev)
{
return dev->release == sas_end_device_release ||
dev->release == sas_expander_release;
}
static int sas_user_scan(struct Scsi_Host *shost, uint channel,
uint id, u64 lun)
{
struct sas_host_attrs *sas_host = to_sas_host_attrs(shost);
struct sas_rphy *rphy;
mutex_lock(&sas_host->lock);
list_for_each_entry(rphy, &sas_host->rphy_list, list) {
if (rphy->identify.device_type != SAS_END_DEVICE ||
rphy->scsi_target_id == -1)
continue;
if ((channel == SCAN_WILD_CARD || channel == 0) &&
(id == SCAN_WILD_CARD || id == rphy->scsi_target_id)) {
scsi_scan_target(&rphy->dev, 0,
rphy->scsi_target_id, lun, 1);
}
}
mutex_unlock(&sas_host->lock);
return 0;
}
struct scsi_transport_template *
sas_attach_transport(struct sas_function_template *ft)
{
struct sas_internal *i;
int count;
i = kzalloc(sizeof(struct sas_internal), GFP_KERNEL);
if (!i)
return NULL;
i->t.user_scan = sas_user_scan;
i->t.host_attrs.ac.attrs = &i->host_attrs[0];
i->t.host_attrs.ac.class = &sas_host_class.class;
i->t.host_attrs.ac.match = sas_host_match;
transport_container_register(&i->t.host_attrs);
i->t.host_size = sizeof(struct sas_host_attrs);
i->phy_attr_cont.ac.class = &sas_phy_class.class;
i->phy_attr_cont.ac.attrs = &i->phy_attrs[0];
i->phy_attr_cont.ac.match = sas_phy_match;
transport_container_register(&i->phy_attr_cont);
i->port_attr_cont.ac.class = &sas_port_class.class;
i->port_attr_cont.ac.attrs = &i->port_attrs[0];
i->port_attr_cont.ac.match = sas_port_match;
transport_container_register(&i->port_attr_cont);
i->rphy_attr_cont.ac.class = &sas_rphy_class.class;
i->rphy_attr_cont.ac.attrs = &i->rphy_attrs[0];
i->rphy_attr_cont.ac.match = sas_rphy_match;
transport_container_register(&i->rphy_attr_cont);
i->end_dev_attr_cont.ac.class = &sas_end_dev_class.class;
i->end_dev_attr_cont.ac.attrs = &i->end_dev_attrs[0];
i->end_dev_attr_cont.ac.match = sas_end_dev_match;
transport_container_register(&i->end_dev_attr_cont);
i->expander_attr_cont.ac.class = &sas_expander_class.class;
i->expander_attr_cont.ac.attrs = &i->expander_attrs[0];
i->expander_attr_cont.ac.match = sas_expander_match;
transport_container_register(&i->expander_attr_cont);
i->f = ft;
count = 0;
SETUP_PHY_ATTRIBUTE(initiator_port_protocols);
SETUP_PHY_ATTRIBUTE(target_port_protocols);
SETUP_PHY_ATTRIBUTE(device_type);
SETUP_PHY_ATTRIBUTE(sas_address);
SETUP_PHY_ATTRIBUTE(phy_identifier);
SETUP_PHY_ATTRIBUTE(negotiated_linkrate);
SETUP_PHY_ATTRIBUTE(minimum_linkrate_hw);
SETUP_PHY_ATTRIBUTE_RW(minimum_linkrate);
SETUP_PHY_ATTRIBUTE(maximum_linkrate_hw);
SETUP_PHY_ATTRIBUTE_RW(maximum_linkrate);
SETUP_PHY_ATTRIBUTE(invalid_dword_count);
SETUP_PHY_ATTRIBUTE(running_disparity_error_count);
SETUP_PHY_ATTRIBUTE(loss_of_dword_sync_count);
SETUP_PHY_ATTRIBUTE(phy_reset_problem_count);
SETUP_OPTIONAL_PHY_ATTRIBUTE_WRONLY(link_reset, phy_reset);
SETUP_OPTIONAL_PHY_ATTRIBUTE_WRONLY(hard_reset, phy_reset);
SETUP_OPTIONAL_PHY_ATTRIBUTE_RW(enable, phy_enable);
i->phy_attrs[count] = NULL;
count = 0;
SETUP_PORT_ATTRIBUTE(num_phys);
i->port_attrs[count] = NULL;
count = 0;
SETUP_RPORT_ATTRIBUTE(rphy_initiator_port_protocols);
SETUP_RPORT_ATTRIBUTE(rphy_target_port_protocols);
SETUP_RPORT_ATTRIBUTE(rphy_device_type);
SETUP_RPORT_ATTRIBUTE(rphy_sas_address);
SETUP_RPORT_ATTRIBUTE(rphy_phy_identifier);
SETUP_OPTIONAL_RPORT_ATTRIBUTE(rphy_enclosure_identifier,
get_enclosure_identifier);
SETUP_OPTIONAL_RPORT_ATTRIBUTE(rphy_bay_identifier,
get_bay_identifier);
i->rphy_attrs[count] = NULL;
count = 0;
SETUP_END_DEV_ATTRIBUTE(end_dev_ready_led_meaning);
SETUP_END_DEV_ATTRIBUTE(end_dev_I_T_nexus_loss_timeout);
SETUP_END_DEV_ATTRIBUTE(end_dev_initiator_response_timeout);
SETUP_END_DEV_ATTRIBUTE(end_dev_tlr_supported);
SETUP_END_DEV_ATTRIBUTE(end_dev_tlr_enabled);
i->end_dev_attrs[count] = NULL;
count = 0;
SETUP_EXPANDER_ATTRIBUTE(vendor_id);
SETUP_EXPANDER_ATTRIBUTE(product_id);
SETUP_EXPANDER_ATTRIBUTE(product_rev);
SETUP_EXPANDER_ATTRIBUTE(component_vendor_id);
SETUP_EXPANDER_ATTRIBUTE(component_id);
SETUP_EXPANDER_ATTRIBUTE(component_revision_id);
SETUP_EXPANDER_ATTRIBUTE(level);
i->expander_attrs[count] = NULL;
return &i->t;
}
void sas_release_transport(struct scsi_transport_template *t)
{
struct sas_internal *i = to_sas_internal(t);
transport_container_unregister(&i->t.host_attrs);
transport_container_unregister(&i->phy_attr_cont);
transport_container_unregister(&i->port_attr_cont);
transport_container_unregister(&i->rphy_attr_cont);
transport_container_unregister(&i->end_dev_attr_cont);
transport_container_unregister(&i->expander_attr_cont);
kfree(i);
}
static __init int sas_transport_init(void)
{
int error;
error = transport_class_register(&sas_host_class);
if (error)
goto out;
error = transport_class_register(&sas_phy_class);
if (error)
goto out_unregister_transport;
error = transport_class_register(&sas_port_class);
if (error)
goto out_unregister_phy;
error = transport_class_register(&sas_rphy_class);
if (error)
goto out_unregister_port;
error = transport_class_register(&sas_end_dev_class);
if (error)
goto out_unregister_rphy;
error = transport_class_register(&sas_expander_class);
if (error)
goto out_unregister_end_dev;
return 0;
out_unregister_end_dev:
transport_class_unregister(&sas_end_dev_class);
out_unregister_rphy:
transport_class_unregister(&sas_rphy_class);
out_unregister_port:
transport_class_unregister(&sas_port_class);
out_unregister_phy:
transport_class_unregister(&sas_phy_class);
out_unregister_transport:
transport_class_unregister(&sas_host_class);
out:
return error;
}
static void __exit sas_transport_exit(void)
{
transport_class_unregister(&sas_host_class);
transport_class_unregister(&sas_phy_class);
transport_class_unregister(&sas_port_class);
transport_class_unregister(&sas_rphy_class);
transport_class_unregister(&sas_end_dev_class);
transport_class_unregister(&sas_expander_class);
}
