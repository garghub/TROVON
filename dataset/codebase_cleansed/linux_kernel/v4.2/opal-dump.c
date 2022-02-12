static ssize_t dump_id_show(struct dump_obj *dump_obj,
struct dump_attribute *attr,
char *buf)
{
return sprintf(buf, "0x%x\n", dump_obj->id);
}
static const char* dump_type_to_string(uint32_t type)
{
switch (type) {
case 0x01: return "SP Dump";
case 0x02: return "System/Platform Dump";
case 0x03: return "SMA Dump";
default: return "unknown";
}
}
static ssize_t dump_type_show(struct dump_obj *dump_obj,
struct dump_attribute *attr,
char *buf)
{
return sprintf(buf, "0x%x %s\n", dump_obj->type,
dump_type_to_string(dump_obj->type));
}
static ssize_t dump_ack_show(struct dump_obj *dump_obj,
struct dump_attribute *attr,
char *buf)
{
return sprintf(buf, "ack - acknowledge dump\n");
}
static int64_t dump_send_ack(uint32_t dump_id)
{
int rc;
rc = opal_dump_ack(dump_id);
if (rc)
pr_warn("%s: Failed to send ack to Dump ID 0x%x (%d)\n",
__func__, dump_id, rc);
return rc;
}
static ssize_t dump_ack_store(struct dump_obj *dump_obj,
struct dump_attribute *attr,
const char *buf,
size_t count)
{
dump_send_ack(dump_obj->id);
sysfs_remove_file_self(&dump_obj->kobj, &attr->attr);
kobject_put(&dump_obj->kobj);
return count;
}
static ssize_t init_dump_show(struct dump_obj *dump_obj,
struct dump_attribute *attr,
char *buf)
{
return sprintf(buf, "1 - initiate Service Processor(FSP) dump\n");
}
static int64_t dump_fips_init(uint8_t type)
{
int rc;
rc = opal_dump_init(type);
if (rc)
pr_warn("%s: Failed to initiate FSP dump (%d)\n",
__func__, rc);
return rc;
}
static ssize_t init_dump_store(struct dump_obj *dump_obj,
struct dump_attribute *attr,
const char *buf,
size_t count)
{
int rc;
rc = dump_fips_init(DUMP_TYPE_FSP);
if (rc == OPAL_SUCCESS)
pr_info("%s: Initiated FSP dump\n", __func__);
return count;
}
static ssize_t dump_attr_show(struct kobject *kobj,
struct attribute *attr,
char *buf)
{
struct dump_attribute *attribute;
struct dump_obj *dump;
attribute = to_dump_attr(attr);
dump = to_dump_obj(kobj);
if (!attribute->show)
return -EIO;
return attribute->show(dump, attribute, buf);
}
static ssize_t dump_attr_store(struct kobject *kobj,
struct attribute *attr,
const char *buf, size_t len)
{
struct dump_attribute *attribute;
struct dump_obj *dump;
attribute = to_dump_attr(attr);
dump = to_dump_obj(kobj);
if (!attribute->store)
return -EIO;
return attribute->store(dump, attribute, buf, len);
}
static void dump_release(struct kobject *kobj)
{
struct dump_obj *dump;
dump = to_dump_obj(kobj);
vfree(dump->buffer);
kfree(dump);
}
static int64_t dump_read_info(uint32_t *dump_id, uint32_t *dump_size, uint32_t *dump_type)
{
__be32 id, size, type;
int rc;
type = cpu_to_be32(0xffffffff);
rc = opal_dump_info2(&id, &size, &type);
if (rc == OPAL_PARAMETER)
rc = opal_dump_info(&id, &size);
*dump_id = be32_to_cpu(id);
*dump_size = be32_to_cpu(size);
*dump_type = be32_to_cpu(type);
if (rc)
pr_warn("%s: Failed to get dump info (%d)\n",
__func__, rc);
return rc;
}
static int64_t dump_read_data(struct dump_obj *dump)
{
struct opal_sg_list *list;
uint64_t addr;
int64_t rc;
dump->buffer = vzalloc(PAGE_ALIGN(dump->size));
if (!dump->buffer) {
pr_err("%s : Failed to allocate memory\n", __func__);
rc = -ENOMEM;
goto out;
}
list = opal_vmalloc_to_sg_list(dump->buffer, dump->size);
if (!list) {
rc = -ENOMEM;
goto out;
}
addr = __pa(list);
rc = OPAL_BUSY_EVENT;
while (rc == OPAL_BUSY || rc == OPAL_BUSY_EVENT) {
rc = opal_dump_read(dump->id, addr);
if (rc == OPAL_BUSY_EVENT) {
opal_poll_events(NULL);
msleep(20);
}
}
if (rc != OPAL_SUCCESS && rc != OPAL_PARTIAL)
pr_warn("%s: Extract dump failed for ID 0x%x\n",
__func__, dump->id);
opal_free_sg_list(list);
out:
return rc;
}
static ssize_t dump_attr_read(struct file *filep, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buffer, loff_t pos, size_t count)
{
ssize_t rc;
struct dump_obj *dump = to_dump_obj(kobj);
if (!dump->buffer) {
rc = dump_read_data(dump);
if (rc != OPAL_SUCCESS && rc != OPAL_PARTIAL) {
vfree(dump->buffer);
dump->buffer = NULL;
return -EIO;
}
if (rc == OPAL_PARTIAL) {
pr_info("%s: Platform dump partially read. ID = 0x%x\n",
__func__, dump->id);
return -EIO;
}
}
memcpy(buffer, dump->buffer + pos, count);
return count;
}
static struct dump_obj *create_dump_obj(uint32_t id, size_t size,
uint32_t type)
{
struct dump_obj *dump;
int rc;
dump = kzalloc(sizeof(*dump), GFP_KERNEL);
if (!dump)
return NULL;
dump->kobj.kset = dump_kset;
kobject_init(&dump->kobj, &dump_ktype);
sysfs_bin_attr_init(&dump->dump_attr);
dump->dump_attr.attr.name = "dump";
dump->dump_attr.attr.mode = 0400;
dump->dump_attr.size = size;
dump->dump_attr.read = dump_attr_read;
dump->id = id;
dump->size = size;
dump->type = type;
rc = kobject_add(&dump->kobj, NULL, "0x%x-0x%x", type, id);
if (rc) {
kobject_put(&dump->kobj);
return NULL;
}
rc = sysfs_create_bin_file(&dump->kobj, &dump->dump_attr);
if (rc) {
kobject_put(&dump->kobj);
return NULL;
}
pr_info("%s: New platform dump. ID = 0x%x Size %u\n",
__func__, dump->id, dump->size);
kobject_uevent(&dump->kobj, KOBJ_ADD);
return dump;
}
static irqreturn_t process_dump(int irq, void *data)
{
int rc;
uint32_t dump_id, dump_size, dump_type;
struct dump_obj *dump;
char name[22];
rc = dump_read_info(&dump_id, &dump_size, &dump_type);
if (rc != OPAL_SUCCESS)
return rc;
sprintf(name, "0x%x-0x%x", dump_type, dump_id);
if (kset_find_obj(dump_kset, name))
return 0;
dump = create_dump_obj(dump_id, dump_size, dump_type);
if (!dump)
return -1;
return IRQ_HANDLED;
}
void __init opal_platform_dump_init(void)
{
int rc;
int dump_irq;
if (!opal_check_token(OPAL_DUMP_READ))
return;
dump_kset = kset_create_and_add("dump", NULL, opal_kobj);
if (!dump_kset) {
pr_warn("%s: Failed to create dump kset\n", __func__);
return;
}
rc = sysfs_create_group(&dump_kset->kobj, &initiate_attr_group);
if (rc) {
pr_warn("%s: Failed to create initiate dump attr group\n",
__func__);
kobject_put(&dump_kset->kobj);
return;
}
dump_irq = opal_event_request(ilog2(OPAL_EVENT_DUMP_AVAIL));
if (!dump_irq) {
pr_err("%s: Can't register OPAL event irq (%d)\n",
__func__, dump_irq);
return;
}
rc = request_threaded_irq(dump_irq, NULL, process_dump,
IRQF_TRIGGER_HIGH | IRQF_ONESHOT,
"opal-dump", NULL);
if (rc) {
pr_err("%s: Can't request OPAL event irq (%d)\n",
__func__, rc);
return;
}
if (opal_check_token(OPAL_DUMP_RESEND))
opal_dump_resend_notification();
}
