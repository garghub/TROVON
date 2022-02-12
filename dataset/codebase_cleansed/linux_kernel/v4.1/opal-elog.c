static ssize_t elog_id_show(struct elog_obj *elog_obj,
struct elog_attribute *attr,
char *buf)
{
return sprintf(buf, "0x%llx\n", elog_obj->id);
}
static const char *elog_type_to_string(uint64_t type)
{
switch (type) {
case 0: return "PEL";
default: return "unknown";
}
}
static ssize_t elog_type_show(struct elog_obj *elog_obj,
struct elog_attribute *attr,
char *buf)
{
return sprintf(buf, "0x%llx %s\n",
elog_obj->type,
elog_type_to_string(elog_obj->type));
}
static ssize_t elog_ack_show(struct elog_obj *elog_obj,
struct elog_attribute *attr,
char *buf)
{
return sprintf(buf, "ack - acknowledge log message\n");
}
static ssize_t elog_ack_store(struct elog_obj *elog_obj,
struct elog_attribute *attr,
const char *buf,
size_t count)
{
opal_send_ack_elog(elog_obj->id);
sysfs_remove_file_self(&elog_obj->kobj, &attr->attr);
kobject_put(&elog_obj->kobj);
return count;
}
static ssize_t elog_attr_show(struct kobject *kobj,
struct attribute *attr,
char *buf)
{
struct elog_attribute *attribute;
struct elog_obj *elog;
attribute = to_elog_attr(attr);
elog = to_elog_obj(kobj);
if (!attribute->show)
return -EIO;
return attribute->show(elog, attribute, buf);
}
static ssize_t elog_attr_store(struct kobject *kobj,
struct attribute *attr,
const char *buf, size_t len)
{
struct elog_attribute *attribute;
struct elog_obj *elog;
attribute = to_elog_attr(attr);
elog = to_elog_obj(kobj);
if (!attribute->store)
return -EIO;
return attribute->store(elog, attribute, buf, len);
}
static void elog_release(struct kobject *kobj)
{
struct elog_obj *elog;
elog = to_elog_obj(kobj);
kfree(elog->buffer);
kfree(elog);
}
static ssize_t raw_attr_read(struct file *filep, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buffer, loff_t pos, size_t count)
{
int opal_rc;
struct elog_obj *elog = to_elog_obj(kobj);
if (!elog->buffer) {
elog->buffer = kzalloc(elog->size, GFP_KERNEL);
if (!elog->buffer)
return -EIO;
opal_rc = opal_read_elog(__pa(elog->buffer),
elog->size, elog->id);
if (opal_rc != OPAL_SUCCESS) {
pr_err("ELOG: log read failed for log-id=%llx\n",
elog->id);
kfree(elog->buffer);
elog->buffer = NULL;
return -EIO;
}
}
memcpy(buffer, elog->buffer + pos, count);
return count;
}
static struct elog_obj *create_elog_obj(uint64_t id, size_t size, uint64_t type)
{
struct elog_obj *elog;
int rc;
elog = kzalloc(sizeof(*elog), GFP_KERNEL);
if (!elog)
return NULL;
elog->kobj.kset = elog_kset;
kobject_init(&elog->kobj, &elog_ktype);
sysfs_bin_attr_init(&elog->raw_attr);
elog->raw_attr.attr.name = "raw";
elog->raw_attr.attr.mode = 0400;
elog->raw_attr.size = size;
elog->raw_attr.read = raw_attr_read;
elog->id = id;
elog->size = size;
elog->type = type;
elog->buffer = kzalloc(elog->size, GFP_KERNEL);
if (elog->buffer) {
rc = opal_read_elog(__pa(elog->buffer),
elog->size, elog->id);
if (rc != OPAL_SUCCESS) {
pr_err("ELOG: log read failed for log-id=%llx\n",
elog->id);
kfree(elog->buffer);
elog->buffer = NULL;
}
}
rc = kobject_add(&elog->kobj, NULL, "0x%llx", id);
if (rc) {
kobject_put(&elog->kobj);
return NULL;
}
rc = sysfs_create_bin_file(&elog->kobj, &elog->raw_attr);
if (rc) {
kobject_put(&elog->kobj);
return NULL;
}
kobject_uevent(&elog->kobj, KOBJ_ADD);
return elog;
}
static void elog_work_fn(struct work_struct *work)
{
__be64 size;
__be64 id;
__be64 type;
uint64_t elog_size;
uint64_t log_id;
uint64_t elog_type;
int rc;
char name[2+16+1];
rc = opal_get_elog_size(&id, &size, &type);
if (rc != OPAL_SUCCESS) {
pr_err("ELOG: OPAL log info read failed\n");
return;
}
elog_size = be64_to_cpu(size);
log_id = be64_to_cpu(id);
elog_type = be64_to_cpu(type);
WARN_ON(elog_size > OPAL_MAX_ERRLOG_SIZE);
if (elog_size >= OPAL_MAX_ERRLOG_SIZE)
elog_size = OPAL_MAX_ERRLOG_SIZE;
sprintf(name, "0x%llx", log_id);
if (kset_find_obj(elog_kset, name))
return;
create_elog_obj(log_id, elog_size, elog_type);
}
static int elog_event(struct notifier_block *nb,
unsigned long events, void *change)
{
if (events & OPAL_EVENT_ERROR_LOG_AVAIL)
schedule_work(&elog_work);
return 0;
}
int __init opal_elog_init(void)
{
int rc = 0;
if (!opal_check_token(OPAL_ELOG_READ))
return -1;
elog_kset = kset_create_and_add("elog", NULL, opal_kobj);
if (!elog_kset) {
pr_warn("%s: failed to create elog kset\n", __func__);
return -1;
}
rc = opal_notifier_register(&elog_nb);
if (rc) {
pr_err("%s: Can't register OPAL event notifier (%d)\n",
__func__, rc);
return rc;
}
if (opal_check_token(OPAL_ELOG_RESEND))
opal_resend_pending_logs();
return 0;
}
