static ssize_t orangefs_attr_show(struct kobject *kobj,
struct attribute *attr,
char *buf)
{
struct orangefs_attribute *attribute;
struct orangefs_obj *orangefs_obj;
int rc;
attribute = container_of(attr, struct orangefs_attribute, attr);
orangefs_obj = container_of(kobj, struct orangefs_obj, kobj);
if (!attribute->show) {
rc = -EIO;
goto out;
}
rc = attribute->show(orangefs_obj, attribute, buf);
out:
return rc;
}
static ssize_t orangefs_attr_store(struct kobject *kobj,
struct attribute *attr,
const char *buf,
size_t len)
{
struct orangefs_attribute *attribute;
struct orangefs_obj *orangefs_obj;
int rc;
gossip_debug(GOSSIP_SYSFS_DEBUG,
"orangefs_attr_store: start\n");
attribute = container_of(attr, struct orangefs_attribute, attr);
orangefs_obj = container_of(kobj, struct orangefs_obj, kobj);
if (!attribute->store) {
rc = -EIO;
goto out;
}
rc = attribute->store(orangefs_obj, attribute, buf, len);
out:
return rc;
}
static ssize_t acache_orangefs_attr_show(struct kobject *kobj,
struct attribute *attr,
char *buf)
{
struct acache_orangefs_attribute *attribute;
struct acache_orangefs_obj *acache_orangefs_obj;
int rc;
attribute = container_of(attr, struct acache_orangefs_attribute, attr);
acache_orangefs_obj =
container_of(kobj, struct acache_orangefs_obj, kobj);
if (!attribute->show) {
rc = -EIO;
goto out;
}
rc = attribute->show(acache_orangefs_obj, attribute, buf);
out:
return rc;
}
static ssize_t acache_orangefs_attr_store(struct kobject *kobj,
struct attribute *attr,
const char *buf,
size_t len)
{
struct acache_orangefs_attribute *attribute;
struct acache_orangefs_obj *acache_orangefs_obj;
int rc;
gossip_debug(GOSSIP_SYSFS_DEBUG,
"acache_orangefs_attr_store: start\n");
attribute = container_of(attr, struct acache_orangefs_attribute, attr);
acache_orangefs_obj =
container_of(kobj, struct acache_orangefs_obj, kobj);
if (!attribute->store) {
rc = -EIO;
goto out;
}
rc = attribute->store(acache_orangefs_obj, attribute, buf, len);
out:
return rc;
}
static ssize_t capcache_orangefs_attr_show(struct kobject *kobj,
struct attribute *attr,
char *buf)
{
struct capcache_orangefs_attribute *attribute;
struct capcache_orangefs_obj *capcache_orangefs_obj;
int rc;
attribute =
container_of(attr, struct capcache_orangefs_attribute, attr);
capcache_orangefs_obj =
container_of(kobj, struct capcache_orangefs_obj, kobj);
if (!attribute->show) {
rc = -EIO;
goto out;
}
rc = attribute->show(capcache_orangefs_obj, attribute, buf);
out:
return rc;
}
static ssize_t capcache_orangefs_attr_store(struct kobject *kobj,
struct attribute *attr,
const char *buf,
size_t len)
{
struct capcache_orangefs_attribute *attribute;
struct capcache_orangefs_obj *capcache_orangefs_obj;
int rc;
gossip_debug(GOSSIP_SYSFS_DEBUG,
"capcache_orangefs_attr_store: start\n");
attribute =
container_of(attr, struct capcache_orangefs_attribute, attr);
capcache_orangefs_obj =
container_of(kobj, struct capcache_orangefs_obj, kobj);
if (!attribute->store) {
rc = -EIO;
goto out;
}
rc = attribute->store(capcache_orangefs_obj, attribute, buf, len);
out:
return rc;
}
static ssize_t ccache_orangefs_attr_show(struct kobject *kobj,
struct attribute *attr,
char *buf)
{
struct ccache_orangefs_attribute *attribute;
struct ccache_orangefs_obj *ccache_orangefs_obj;
int rc;
attribute =
container_of(attr, struct ccache_orangefs_attribute, attr);
ccache_orangefs_obj =
container_of(kobj, struct ccache_orangefs_obj, kobj);
if (!attribute->show) {
rc = -EIO;
goto out;
}
rc = attribute->show(ccache_orangefs_obj, attribute, buf);
out:
return rc;
}
static ssize_t ccache_orangefs_attr_store(struct kobject *kobj,
struct attribute *attr,
const char *buf,
size_t len)
{
struct ccache_orangefs_attribute *attribute;
struct ccache_orangefs_obj *ccache_orangefs_obj;
int rc;
gossip_debug(GOSSIP_SYSFS_DEBUG,
"ccache_orangefs_attr_store: start\n");
attribute =
container_of(attr, struct ccache_orangefs_attribute, attr);
ccache_orangefs_obj =
container_of(kobj, struct ccache_orangefs_obj, kobj);
if (!attribute->store) {
rc = -EIO;
goto out;
}
rc = attribute->store(ccache_orangefs_obj, attribute, buf, len);
out:
return rc;
}
static ssize_t ncache_orangefs_attr_show(struct kobject *kobj,
struct attribute *attr,
char *buf)
{
struct ncache_orangefs_attribute *attribute;
struct ncache_orangefs_obj *ncache_orangefs_obj;
int rc;
attribute = container_of(attr, struct ncache_orangefs_attribute, attr);
ncache_orangefs_obj =
container_of(kobj, struct ncache_orangefs_obj, kobj);
if (!attribute->show) {
rc = -EIO;
goto out;
}
rc = attribute->show(ncache_orangefs_obj, attribute, buf);
out:
return rc;
}
static ssize_t ncache_orangefs_attr_store(struct kobject *kobj,
struct attribute *attr,
const char *buf,
size_t len)
{
struct ncache_orangefs_attribute *attribute;
struct ncache_orangefs_obj *ncache_orangefs_obj;
int rc;
gossip_debug(GOSSIP_SYSFS_DEBUG,
"ncache_orangefs_attr_store: start\n");
attribute = container_of(attr, struct ncache_orangefs_attribute, attr);
ncache_orangefs_obj =
container_of(kobj, struct ncache_orangefs_obj, kobj);
if (!attribute->store) {
rc = -EIO;
goto out;
}
rc = attribute->store(ncache_orangefs_obj, attribute, buf, len);
out:
return rc;
}
static ssize_t pc_orangefs_attr_show(struct kobject *kobj,
struct attribute *attr,
char *buf)
{
struct pc_orangefs_attribute *attribute;
struct pc_orangefs_obj *pc_orangefs_obj;
int rc;
attribute = container_of(attr, struct pc_orangefs_attribute, attr);
pc_orangefs_obj =
container_of(kobj, struct pc_orangefs_obj, kobj);
if (!attribute->show) {
rc = -EIO;
goto out;
}
rc = attribute->show(pc_orangefs_obj, attribute, buf);
out:
return rc;
}
static ssize_t stats_orangefs_attr_show(struct kobject *kobj,
struct attribute *attr,
char *buf)
{
struct stats_orangefs_attribute *attribute;
struct stats_orangefs_obj *stats_orangefs_obj;
int rc;
attribute = container_of(attr, struct stats_orangefs_attribute, attr);
stats_orangefs_obj =
container_of(kobj, struct stats_orangefs_obj, kobj);
if (!attribute->show) {
rc = -EIO;
goto out;
}
rc = attribute->show(stats_orangefs_obj, attribute, buf);
out:
return rc;
}
static void orangefs_release(struct kobject *kobj)
{
struct orangefs_obj *orangefs_obj;
orangefs_obj = container_of(kobj, struct orangefs_obj, kobj);
kfree(orangefs_obj);
}
static void acache_orangefs_release(struct kobject *kobj)
{
struct acache_orangefs_obj *acache_orangefs_obj;
acache_orangefs_obj =
container_of(kobj, struct acache_orangefs_obj, kobj);
kfree(acache_orangefs_obj);
}
static void capcache_orangefs_release(struct kobject *kobj)
{
struct capcache_orangefs_obj *capcache_orangefs_obj;
capcache_orangefs_obj =
container_of(kobj, struct capcache_orangefs_obj, kobj);
kfree(capcache_orangefs_obj);
}
static void ccache_orangefs_release(struct kobject *kobj)
{
struct ccache_orangefs_obj *ccache_orangefs_obj;
ccache_orangefs_obj =
container_of(kobj, struct ccache_orangefs_obj, kobj);
kfree(ccache_orangefs_obj);
}
static void ncache_orangefs_release(struct kobject *kobj)
{
struct ncache_orangefs_obj *ncache_orangefs_obj;
ncache_orangefs_obj =
container_of(kobj, struct ncache_orangefs_obj, kobj);
kfree(ncache_orangefs_obj);
}
static void pc_orangefs_release(struct kobject *kobj)
{
struct pc_orangefs_obj *pc_orangefs_obj;
pc_orangefs_obj =
container_of(kobj, struct pc_orangefs_obj, kobj);
kfree(pc_orangefs_obj);
}
static void stats_orangefs_release(struct kobject *kobj)
{
struct stats_orangefs_obj *stats_orangefs_obj;
stats_orangefs_obj =
container_of(kobj, struct stats_orangefs_obj, kobj);
kfree(stats_orangefs_obj);
}
static ssize_t sysfs_int_show(char *kobj_id, char *buf, void *attr)
{
int rc = -EIO;
struct orangefs_attribute *orangefs_attr;
struct stats_orangefs_attribute *stats_orangefs_attr;
gossip_debug(GOSSIP_SYSFS_DEBUG, "sysfs_int_show: id:%s:\n", kobj_id);
if (!strcmp(kobj_id, ORANGEFS_KOBJ_ID)) {
orangefs_attr = (struct orangefs_attribute *)attr;
if (!strcmp(orangefs_attr->attr.name, "op_timeout_secs")) {
rc = scnprintf(buf,
PAGE_SIZE,
"%d\n",
op_timeout_secs);
goto out;
} else if (!strcmp(orangefs_attr->attr.name,
"slot_timeout_secs")) {
rc = scnprintf(buf,
PAGE_SIZE,
"%d\n",
slot_timeout_secs);
goto out;
} else {
goto out;
}
} else if (!strcmp(kobj_id, STATS_KOBJ_ID)) {
stats_orangefs_attr = (struct stats_orangefs_attribute *)attr;
if (!strcmp(stats_orangefs_attr->attr.name, "reads")) {
rc = scnprintf(buf,
PAGE_SIZE,
"%lu\n",
g_orangefs_stats.reads);
goto out;
} else if (!strcmp(stats_orangefs_attr->attr.name, "writes")) {
rc = scnprintf(buf,
PAGE_SIZE,
"%lu\n",
g_orangefs_stats.writes);
goto out;
} else {
goto out;
}
}
out:
return rc;
}
static ssize_t int_orangefs_show(struct orangefs_obj *orangefs_obj,
struct orangefs_attribute *attr,
char *buf)
{
int rc;
gossip_debug(GOSSIP_SYSFS_DEBUG,
"int_orangefs_show:start attr->attr.name:%s:\n",
attr->attr.name);
rc = sysfs_int_show(ORANGEFS_KOBJ_ID, buf, (void *) attr);
return rc;
}
static ssize_t int_stats_show(struct stats_orangefs_obj *stats_orangefs_obj,
struct stats_orangefs_attribute *attr,
char *buf)
{
int rc;
gossip_debug(GOSSIP_SYSFS_DEBUG,
"int_stats_show:start attr->attr.name:%s:\n",
attr->attr.name);
rc = sysfs_int_show(STATS_KOBJ_ID, buf, (void *) attr);
return rc;
}
static ssize_t int_store(struct orangefs_obj *orangefs_obj,
struct orangefs_attribute *attr,
const char *buf,
size_t count)
{
int rc = 0;
gossip_debug(GOSSIP_SYSFS_DEBUG,
"int_store: start attr->attr.name:%s: buf:%s:\n",
attr->attr.name, buf);
if (!strcmp(attr->attr.name, "op_timeout_secs")) {
rc = kstrtoint(buf, 0, &op_timeout_secs);
goto out;
} else if (!strcmp(attr->attr.name, "slot_timeout_secs")) {
rc = kstrtoint(buf, 0, &slot_timeout_secs);
goto out;
} else {
goto out;
}
out:
if (rc)
rc = -EINVAL;
else
rc = count;
return rc;
}
static int sysfs_service_op_show(char *kobj_id, char *buf, void *attr)
{
struct orangefs_kernel_op_s *new_op = NULL;
int rc = 0;
char *ser_op_type = NULL;
struct orangefs_attribute *orangefs_attr;
struct acache_orangefs_attribute *acache_attr;
struct capcache_orangefs_attribute *capcache_attr;
struct ccache_orangefs_attribute *ccache_attr;
struct ncache_orangefs_attribute *ncache_attr;
struct pc_orangefs_attribute *pc_attr;
__u32 op_alloc_type;
gossip_debug(GOSSIP_SYSFS_DEBUG,
"sysfs_service_op_show: id:%s:\n",
kobj_id);
if (strcmp(kobj_id, PC_KOBJ_ID))
op_alloc_type = ORANGEFS_VFS_OP_PARAM;
else
op_alloc_type = ORANGEFS_VFS_OP_PERF_COUNT;
new_op = op_alloc(op_alloc_type);
if (!new_op)
return -ENOMEM;
rc = is_daemon_in_service();
if (rc) {
pr_info("%s: Client not running :%d:\n",
__func__,
is_daemon_in_service());
goto out;
}
if (strcmp(kobj_id, PC_KOBJ_ID))
new_op->upcall.req.param.type = ORANGEFS_PARAM_REQUEST_GET;
if (!strcmp(kobj_id, ORANGEFS_KOBJ_ID)) {
orangefs_attr = (struct orangefs_attribute *)attr;
if (!strcmp(orangefs_attr->attr.name, "perf_history_size"))
new_op->upcall.req.param.op =
ORANGEFS_PARAM_REQUEST_OP_PERF_HISTORY_SIZE;
else if (!strcmp(orangefs_attr->attr.name,
"perf_time_interval_secs"))
new_op->upcall.req.param.op =
ORANGEFS_PARAM_REQUEST_OP_PERF_TIME_INTERVAL_SECS;
else if (!strcmp(orangefs_attr->attr.name,
"perf_counter_reset"))
new_op->upcall.req.param.op =
ORANGEFS_PARAM_REQUEST_OP_PERF_RESET;
} else if (!strcmp(kobj_id, ACACHE_KOBJ_ID)) {
acache_attr = (struct acache_orangefs_attribute *)attr;
if (!strcmp(acache_attr->attr.name, "timeout_msecs"))
new_op->upcall.req.param.op =
ORANGEFS_PARAM_REQUEST_OP_ACACHE_TIMEOUT_MSECS;
if (!strcmp(acache_attr->attr.name, "hard_limit"))
new_op->upcall.req.param.op =
ORANGEFS_PARAM_REQUEST_OP_ACACHE_HARD_LIMIT;
if (!strcmp(acache_attr->attr.name, "soft_limit"))
new_op->upcall.req.param.op =
ORANGEFS_PARAM_REQUEST_OP_ACACHE_SOFT_LIMIT;
if (!strcmp(acache_attr->attr.name, "reclaim_percentage"))
new_op->upcall.req.param.op =
ORANGEFS_PARAM_REQUEST_OP_ACACHE_RECLAIM_PERCENTAGE;
} else if (!strcmp(kobj_id, CAPCACHE_KOBJ_ID)) {
capcache_attr = (struct capcache_orangefs_attribute *)attr;
if (!strcmp(capcache_attr->attr.name, "timeout_secs"))
new_op->upcall.req.param.op =
ORANGEFS_PARAM_REQUEST_OP_CAPCACHE_TIMEOUT_SECS;
if (!strcmp(capcache_attr->attr.name, "hard_limit"))
new_op->upcall.req.param.op =
ORANGEFS_PARAM_REQUEST_OP_CAPCACHE_HARD_LIMIT;
if (!strcmp(capcache_attr->attr.name, "soft_limit"))
new_op->upcall.req.param.op =
ORANGEFS_PARAM_REQUEST_OP_CAPCACHE_SOFT_LIMIT;
if (!strcmp(capcache_attr->attr.name, "reclaim_percentage"))
new_op->upcall.req.param.op =
ORANGEFS_PARAM_REQUEST_OP_CAPCACHE_RECLAIM_PERCENTAGE;
} else if (!strcmp(kobj_id, CCACHE_KOBJ_ID)) {
ccache_attr = (struct ccache_orangefs_attribute *)attr;
if (!strcmp(ccache_attr->attr.name, "timeout_secs"))
new_op->upcall.req.param.op =
ORANGEFS_PARAM_REQUEST_OP_CCACHE_TIMEOUT_SECS;
if (!strcmp(ccache_attr->attr.name, "hard_limit"))
new_op->upcall.req.param.op =
ORANGEFS_PARAM_REQUEST_OP_CCACHE_HARD_LIMIT;
if (!strcmp(ccache_attr->attr.name, "soft_limit"))
new_op->upcall.req.param.op =
ORANGEFS_PARAM_REQUEST_OP_CCACHE_SOFT_LIMIT;
if (!strcmp(ccache_attr->attr.name, "reclaim_percentage"))
new_op->upcall.req.param.op =
ORANGEFS_PARAM_REQUEST_OP_CCACHE_RECLAIM_PERCENTAGE;
} else if (!strcmp(kobj_id, NCACHE_KOBJ_ID)) {
ncache_attr = (struct ncache_orangefs_attribute *)attr;
if (!strcmp(ncache_attr->attr.name, "timeout_msecs"))
new_op->upcall.req.param.op =
ORANGEFS_PARAM_REQUEST_OP_NCACHE_TIMEOUT_MSECS;
if (!strcmp(ncache_attr->attr.name, "hard_limit"))
new_op->upcall.req.param.op =
ORANGEFS_PARAM_REQUEST_OP_NCACHE_HARD_LIMIT;
if (!strcmp(ncache_attr->attr.name, "soft_limit"))
new_op->upcall.req.param.op =
ORANGEFS_PARAM_REQUEST_OP_NCACHE_SOFT_LIMIT;
if (!strcmp(ncache_attr->attr.name, "reclaim_percentage"))
new_op->upcall.req.param.op =
ORANGEFS_PARAM_REQUEST_OP_NCACHE_RECLAIM_PERCENTAGE;
} else if (!strcmp(kobj_id, PC_KOBJ_ID)) {
pc_attr = (struct pc_orangefs_attribute *)attr;
if (!strcmp(pc_attr->attr.name, ACACHE_KOBJ_ID))
new_op->upcall.req.perf_count.type =
ORANGEFS_PERF_COUNT_REQUEST_ACACHE;
if (!strcmp(pc_attr->attr.name, CAPCACHE_KOBJ_ID))
new_op->upcall.req.perf_count.type =
ORANGEFS_PERF_COUNT_REQUEST_CAPCACHE;
if (!strcmp(pc_attr->attr.name, NCACHE_KOBJ_ID))
new_op->upcall.req.perf_count.type =
ORANGEFS_PERF_COUNT_REQUEST_NCACHE;
} else {
gossip_err("sysfs_service_op_show: unknown kobj_id:%s:\n",
kobj_id);
rc = -EINVAL;
goto out;
}
if (strcmp(kobj_id, PC_KOBJ_ID))
ser_op_type = "orangefs_param";
else
ser_op_type = "orangefs_perf_count";
rc = service_operation(new_op, ser_op_type, ORANGEFS_OP_INTERRUPTIBLE);
out:
if (!rc) {
if (strcmp(kobj_id, PC_KOBJ_ID)) {
rc = scnprintf(buf,
PAGE_SIZE,
"%d\n",
(int)new_op->downcall.resp.param.value);
} else {
rc = scnprintf(
buf,
PAGE_SIZE,
"%s",
new_op->downcall.resp.perf_count.buffer);
}
}
op_release(new_op);
return rc;
}
static ssize_t service_orangefs_show(struct orangefs_obj *orangefs_obj,
struct orangefs_attribute *attr,
char *buf)
{
int rc = 0;
rc = sysfs_service_op_show(ORANGEFS_KOBJ_ID, buf, (void *)attr);
return rc;
}
static ssize_t
service_acache_show(struct acache_orangefs_obj *acache_orangefs_obj,
struct acache_orangefs_attribute *attr,
char *buf)
{
int rc = 0;
rc = sysfs_service_op_show(ACACHE_KOBJ_ID, buf, (void *)attr);
return rc;
}
static ssize_t service_capcache_show(struct capcache_orangefs_obj
*capcache_orangefs_obj,
struct capcache_orangefs_attribute *attr,
char *buf)
{
int rc = 0;
rc = sysfs_service_op_show(CAPCACHE_KOBJ_ID, buf, (void *)attr);
return rc;
}
static ssize_t service_ccache_show(struct ccache_orangefs_obj
*ccache_orangefs_obj,
struct ccache_orangefs_attribute *attr,
char *buf)
{
int rc = 0;
rc = sysfs_service_op_show(CCACHE_KOBJ_ID, buf, (void *)attr);
return rc;
}
static ssize_t
service_ncache_show(struct ncache_orangefs_obj *ncache_orangefs_obj,
struct ncache_orangefs_attribute *attr,
char *buf)
{
int rc = 0;
rc = sysfs_service_op_show(NCACHE_KOBJ_ID, buf, (void *)attr);
return rc;
}
static ssize_t
service_pc_show(struct pc_orangefs_obj *pc_orangefs_obj,
struct pc_orangefs_attribute *attr,
char *buf)
{
int rc = 0;
rc = sysfs_service_op_show(PC_KOBJ_ID, buf, (void *)attr);
return rc;
}
static int sysfs_service_op_store(char *kobj_id, const char *buf, void *attr)
{
struct orangefs_kernel_op_s *new_op = NULL;
int val = 0;
int rc = 0;
struct orangefs_attribute *orangefs_attr;
struct acache_orangefs_attribute *acache_attr;
struct capcache_orangefs_attribute *capcache_attr;
struct ccache_orangefs_attribute *ccache_attr;
struct ncache_orangefs_attribute *ncache_attr;
gossip_debug(GOSSIP_SYSFS_DEBUG,
"sysfs_service_op_store: id:%s:\n",
kobj_id);
new_op = op_alloc(ORANGEFS_VFS_OP_PARAM);
if (!new_op)
return -EINVAL;
rc = is_daemon_in_service();
if (rc) {
pr_info("%s: Client not running :%d:\n",
__func__,
is_daemon_in_service());
goto out;
}
rc = kstrtoint(buf, 0, &val);
if (rc)
goto out;
if (!strcmp(kobj_id, ORANGEFS_KOBJ_ID)) {
orangefs_attr = (struct orangefs_attribute *)attr;
if (!strcmp(orangefs_attr->attr.name, "perf_history_size")) {
if (val > 0) {
new_op->upcall.req.param.op =
ORANGEFS_PARAM_REQUEST_OP_PERF_HISTORY_SIZE;
} else {
rc = 0;
goto out;
}
} else if (!strcmp(orangefs_attr->attr.name,
"perf_time_interval_secs")) {
if (val > 0) {
new_op->upcall.req.param.op =
ORANGEFS_PARAM_REQUEST_OP_PERF_TIME_INTERVAL_SECS;
} else {
rc = 0;
goto out;
}
} else if (!strcmp(orangefs_attr->attr.name,
"perf_counter_reset")) {
if ((val == 0) || (val == 1)) {
new_op->upcall.req.param.op =
ORANGEFS_PARAM_REQUEST_OP_PERF_RESET;
} else {
rc = 0;
goto out;
}
}
} else if (!strcmp(kobj_id, ACACHE_KOBJ_ID)) {
acache_attr = (struct acache_orangefs_attribute *)attr;
if (!strcmp(acache_attr->attr.name, "hard_limit")) {
if (val > -1) {
new_op->upcall.req.param.op =
ORANGEFS_PARAM_REQUEST_OP_ACACHE_HARD_LIMIT;
} else {
rc = 0;
goto out;
}
} else if (!strcmp(acache_attr->attr.name, "soft_limit")) {
if (val > -1) {
new_op->upcall.req.param.op =
ORANGEFS_PARAM_REQUEST_OP_ACACHE_SOFT_LIMIT;
} else {
rc = 0;
goto out;
}
} else if (!strcmp(acache_attr->attr.name,
"reclaim_percentage")) {
if ((val > -1) && (val < 101)) {
new_op->upcall.req.param.op =
ORANGEFS_PARAM_REQUEST_OP_ACACHE_RECLAIM_PERCENTAGE;
} else {
rc = 0;
goto out;
}
} else if (!strcmp(acache_attr->attr.name, "timeout_msecs")) {
if (val > -1) {
new_op->upcall.req.param.op =
ORANGEFS_PARAM_REQUEST_OP_ACACHE_TIMEOUT_MSECS;
} else {
rc = 0;
goto out;
}
}
} else if (!strcmp(kobj_id, CAPCACHE_KOBJ_ID)) {
capcache_attr = (struct capcache_orangefs_attribute *)attr;
if (!strcmp(capcache_attr->attr.name, "hard_limit")) {
if (val > -1) {
new_op->upcall.req.param.op =
ORANGEFS_PARAM_REQUEST_OP_CAPCACHE_HARD_LIMIT;
} else {
rc = 0;
goto out;
}
} else if (!strcmp(capcache_attr->attr.name, "soft_limit")) {
if (val > -1) {
new_op->upcall.req.param.op =
ORANGEFS_PARAM_REQUEST_OP_CAPCACHE_SOFT_LIMIT;
} else {
rc = 0;
goto out;
}
} else if (!strcmp(capcache_attr->attr.name,
"reclaim_percentage")) {
if ((val > -1) && (val < 101)) {
new_op->upcall.req.param.op =
ORANGEFS_PARAM_REQUEST_OP_CAPCACHE_RECLAIM_PERCENTAGE;
} else {
rc = 0;
goto out;
}
} else if (!strcmp(capcache_attr->attr.name, "timeout_secs")) {
if (val > -1) {
new_op->upcall.req.param.op =
ORANGEFS_PARAM_REQUEST_OP_CAPCACHE_TIMEOUT_SECS;
} else {
rc = 0;
goto out;
}
}
} else if (!strcmp(kobj_id, CCACHE_KOBJ_ID)) {
ccache_attr = (struct ccache_orangefs_attribute *)attr;
if (!strcmp(ccache_attr->attr.name, "hard_limit")) {
if (val > -1) {
new_op->upcall.req.param.op =
ORANGEFS_PARAM_REQUEST_OP_CCACHE_HARD_LIMIT;
} else {
rc = 0;
goto out;
}
} else if (!strcmp(ccache_attr->attr.name, "soft_limit")) {
if (val > -1) {
new_op->upcall.req.param.op =
ORANGEFS_PARAM_REQUEST_OP_CCACHE_SOFT_LIMIT;
} else {
rc = 0;
goto out;
}
} else if (!strcmp(ccache_attr->attr.name,
"reclaim_percentage")) {
if ((val > -1) && (val < 101)) {
new_op->upcall.req.param.op =
ORANGEFS_PARAM_REQUEST_OP_CCACHE_RECLAIM_PERCENTAGE;
} else {
rc = 0;
goto out;
}
} else if (!strcmp(ccache_attr->attr.name, "timeout_secs")) {
if (val > -1) {
new_op->upcall.req.param.op =
ORANGEFS_PARAM_REQUEST_OP_CCACHE_TIMEOUT_SECS;
} else {
rc = 0;
goto out;
}
}
} else if (!strcmp(kobj_id, NCACHE_KOBJ_ID)) {
ncache_attr = (struct ncache_orangefs_attribute *)attr;
if (!strcmp(ncache_attr->attr.name, "hard_limit")) {
if (val > -1) {
new_op->upcall.req.param.op =
ORANGEFS_PARAM_REQUEST_OP_NCACHE_HARD_LIMIT;
} else {
rc = 0;
goto out;
}
} else if (!strcmp(ncache_attr->attr.name, "soft_limit")) {
if (val > -1) {
new_op->upcall.req.param.op =
ORANGEFS_PARAM_REQUEST_OP_NCACHE_SOFT_LIMIT;
} else {
rc = 0;
goto out;
}
} else if (!strcmp(ncache_attr->attr.name,
"reclaim_percentage")) {
if ((val > -1) && (val < 101)) {
new_op->upcall.req.param.op =
ORANGEFS_PARAM_REQUEST_OP_NCACHE_RECLAIM_PERCENTAGE;
} else {
rc = 0;
goto out;
}
} else if (!strcmp(ncache_attr->attr.name, "timeout_msecs")) {
if (val > -1) {
new_op->upcall.req.param.op =
ORANGEFS_PARAM_REQUEST_OP_NCACHE_TIMEOUT_MSECS;
} else {
rc = 0;
goto out;
}
}
} else {
gossip_err("sysfs_service_op_store: unknown kobj_id:%s:\n",
kobj_id);
rc = -EINVAL;
goto out;
}
new_op->upcall.req.param.type = ORANGEFS_PARAM_REQUEST_SET;
new_op->upcall.req.param.value = val;
rc = service_operation(new_op, "orangefs_param", ORANGEFS_OP_INTERRUPTIBLE);
if (rc < 0) {
gossip_err("sysfs_service_op_store: service op returned:%d:\n",
rc);
rc = 0;
} else {
rc = 1;
}
out:
op_release(new_op);
if (rc == -ENOMEM || rc == 0)
rc = -EINVAL;
return rc;
}
static ssize_t
service_orangefs_store(struct orangefs_obj *orangefs_obj,
struct orangefs_attribute *attr,
const char *buf,
size_t count)
{
int rc = 0;
rc = sysfs_service_op_store(ORANGEFS_KOBJ_ID, buf, (void *) attr);
if (rc == 1)
rc = count;
return rc;
}
static ssize_t
service_acache_store(struct acache_orangefs_obj *acache_orangefs_obj,
struct acache_orangefs_attribute *attr,
const char *buf,
size_t count)
{
int rc = 0;
rc = sysfs_service_op_store(ACACHE_KOBJ_ID, buf, (void *) attr);
if (rc == 1)
rc = count;
return rc;
}
static ssize_t
service_capcache_store(struct capcache_orangefs_obj
*capcache_orangefs_obj,
struct capcache_orangefs_attribute *attr,
const char *buf,
size_t count)
{
int rc = 0;
rc = sysfs_service_op_store(CAPCACHE_KOBJ_ID, buf, (void *) attr);
if (rc == 1)
rc = count;
return rc;
}
static ssize_t service_ccache_store(struct ccache_orangefs_obj
*ccache_orangefs_obj,
struct ccache_orangefs_attribute *attr,
const char *buf,
size_t count)
{
int rc = 0;
rc = sysfs_service_op_store(CCACHE_KOBJ_ID, buf, (void *) attr);
if (rc == 1)
rc = count;
return rc;
}
static ssize_t
service_ncache_store(struct ncache_orangefs_obj *ncache_orangefs_obj,
struct ncache_orangefs_attribute *attr,
const char *buf,
size_t count)
{
int rc = 0;
rc = sysfs_service_op_store(NCACHE_KOBJ_ID, buf, (void *) attr);
if (rc == 1)
rc = count;
return rc;
}
int orangefs_sysfs_init(void)
{
int rc = -EINVAL;
gossip_debug(GOSSIP_SYSFS_DEBUG, "orangefs_sysfs_init: start\n");
orangefs_obj = kzalloc(sizeof(*orangefs_obj), GFP_KERNEL);
if (!orangefs_obj)
goto out;
rc = kobject_init_and_add(&orangefs_obj->kobj,
&orangefs_ktype,
fs_kobj,
ORANGEFS_KOBJ_ID);
if (rc)
goto ofs_obj_bail;
kobject_uevent(&orangefs_obj->kobj, KOBJ_ADD);
acache_orangefs_obj = kzalloc(sizeof(*acache_orangefs_obj), GFP_KERNEL);
if (!acache_orangefs_obj) {
rc = -EINVAL;
goto ofs_obj_bail;
}
rc = kobject_init_and_add(&acache_orangefs_obj->kobj,
&acache_orangefs_ktype,
&orangefs_obj->kobj,
ACACHE_KOBJ_ID);
if (rc)
goto acache_obj_bail;
kobject_uevent(&acache_orangefs_obj->kobj, KOBJ_ADD);
capcache_orangefs_obj =
kzalloc(sizeof(*capcache_orangefs_obj), GFP_KERNEL);
if (!capcache_orangefs_obj) {
rc = -EINVAL;
goto acache_obj_bail;
}
rc = kobject_init_and_add(&capcache_orangefs_obj->kobj,
&capcache_orangefs_ktype,
&orangefs_obj->kobj,
CAPCACHE_KOBJ_ID);
if (rc)
goto capcache_obj_bail;
kobject_uevent(&capcache_orangefs_obj->kobj, KOBJ_ADD);
ccache_orangefs_obj =
kzalloc(sizeof(*ccache_orangefs_obj), GFP_KERNEL);
if (!ccache_orangefs_obj) {
rc = -EINVAL;
goto capcache_obj_bail;
}
rc = kobject_init_and_add(&ccache_orangefs_obj->kobj,
&ccache_orangefs_ktype,
&orangefs_obj->kobj,
CCACHE_KOBJ_ID);
if (rc)
goto ccache_obj_bail;
kobject_uevent(&ccache_orangefs_obj->kobj, KOBJ_ADD);
ncache_orangefs_obj = kzalloc(sizeof(*ncache_orangefs_obj), GFP_KERNEL);
if (!ncache_orangefs_obj) {
rc = -EINVAL;
goto ccache_obj_bail;
}
rc = kobject_init_and_add(&ncache_orangefs_obj->kobj,
&ncache_orangefs_ktype,
&orangefs_obj->kobj,
NCACHE_KOBJ_ID);
if (rc)
goto ncache_obj_bail;
kobject_uevent(&ncache_orangefs_obj->kobj, KOBJ_ADD);
pc_orangefs_obj = kzalloc(sizeof(*pc_orangefs_obj), GFP_KERNEL);
if (!pc_orangefs_obj) {
rc = -EINVAL;
goto ncache_obj_bail;
}
rc = kobject_init_and_add(&pc_orangefs_obj->kobj,
&pc_orangefs_ktype,
&orangefs_obj->kobj,
"perf_counters");
if (rc)
goto pc_obj_bail;
kobject_uevent(&pc_orangefs_obj->kobj, KOBJ_ADD);
stats_orangefs_obj = kzalloc(sizeof(*stats_orangefs_obj), GFP_KERNEL);
if (!stats_orangefs_obj) {
rc = -EINVAL;
goto pc_obj_bail;
}
rc = kobject_init_and_add(&stats_orangefs_obj->kobj,
&stats_orangefs_ktype,
&orangefs_obj->kobj,
STATS_KOBJ_ID);
if (rc)
goto stats_obj_bail;
kobject_uevent(&stats_orangefs_obj->kobj, KOBJ_ADD);
goto out;
stats_obj_bail:
kobject_put(&stats_orangefs_obj->kobj);
pc_obj_bail:
kobject_put(&pc_orangefs_obj->kobj);
ncache_obj_bail:
kobject_put(&ncache_orangefs_obj->kobj);
ccache_obj_bail:
kobject_put(&ccache_orangefs_obj->kobj);
capcache_obj_bail:
kobject_put(&capcache_orangefs_obj->kobj);
acache_obj_bail:
kobject_put(&acache_orangefs_obj->kobj);
ofs_obj_bail:
kobject_put(&orangefs_obj->kobj);
out:
return rc;
}
void orangefs_sysfs_exit(void)
{
gossip_debug(GOSSIP_SYSFS_DEBUG, "orangefs_sysfs_exit: start\n");
kobject_put(&acache_orangefs_obj->kobj);
kobject_put(&capcache_orangefs_obj->kobj);
kobject_put(&ccache_orangefs_obj->kobj);
kobject_put(&ncache_orangefs_obj->kobj);
kobject_put(&pc_orangefs_obj->kobj);
kobject_put(&stats_orangefs_obj->kobj);
kobject_put(&orangefs_obj->kobj);
}
