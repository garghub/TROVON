static int coresight_id_match(struct device *dev, void *data)
{
int trace_id, i_trace_id;
struct coresight_device *csdev, *i_csdev;
csdev = data;
i_csdev = to_coresight_device(dev);
if (i_csdev == csdev || !i_csdev->enable ||
i_csdev->type != CORESIGHT_DEV_TYPE_SOURCE)
return 0;
trace_id = source_ops(csdev)->trace_id(csdev);
i_trace_id = source_ops(i_csdev)->trace_id(i_csdev);
if (trace_id == i_trace_id)
return 1;
return 0;
}
static int coresight_source_is_unique(struct coresight_device *csdev)
{
int trace_id = source_ops(csdev)->trace_id(csdev);
if (trace_id < 0)
return 0;
return !bus_for_each_dev(&coresight_bustype, NULL,
csdev, coresight_id_match);
}
static int coresight_find_link_inport(struct coresight_device *csdev,
struct coresight_device *parent)
{
int i;
struct coresight_connection *conn;
for (i = 0; i < parent->nr_outport; i++) {
conn = &parent->conns[i];
if (conn->child_dev == csdev)
return conn->child_port;
}
dev_err(&csdev->dev, "couldn't find inport, parent: %s, child: %s\n",
dev_name(&parent->dev), dev_name(&csdev->dev));
return 0;
}
static int coresight_find_link_outport(struct coresight_device *csdev,
struct coresight_device *child)
{
int i;
struct coresight_connection *conn;
for (i = 0; i < csdev->nr_outport; i++) {
conn = &csdev->conns[i];
if (conn->child_dev == child)
return conn->outport;
}
dev_err(&csdev->dev, "couldn't find outport, parent: %s, child: %s\n",
dev_name(&csdev->dev), dev_name(&child->dev));
return 0;
}
static int coresight_enable_sink(struct coresight_device *csdev, u32 mode)
{
int ret;
if (!csdev->enable) {
if (sink_ops(csdev)->enable) {
ret = sink_ops(csdev)->enable(csdev, mode);
if (ret)
return ret;
}
csdev->enable = true;
}
atomic_inc(csdev->refcnt);
return 0;
}
static void coresight_disable_sink(struct coresight_device *csdev)
{
if (atomic_dec_return(csdev->refcnt) == 0) {
if (sink_ops(csdev)->disable) {
sink_ops(csdev)->disable(csdev);
csdev->enable = false;
}
}
}
static int coresight_enable_link(struct coresight_device *csdev,
struct coresight_device *parent,
struct coresight_device *child)
{
int ret;
int link_subtype;
int refport, inport, outport;
if (!parent || !child)
return -EINVAL;
inport = coresight_find_link_inport(csdev, parent);
outport = coresight_find_link_outport(csdev, child);
link_subtype = csdev->subtype.link_subtype;
if (link_subtype == CORESIGHT_DEV_SUBTYPE_LINK_MERG)
refport = inport;
else if (link_subtype == CORESIGHT_DEV_SUBTYPE_LINK_SPLIT)
refport = outport;
else
refport = 0;
if (atomic_inc_return(&csdev->refcnt[refport]) == 1) {
if (link_ops(csdev)->enable) {
ret = link_ops(csdev)->enable(csdev, inport, outport);
if (ret)
return ret;
}
}
csdev->enable = true;
return 0;
}
static void coresight_disable_link(struct coresight_device *csdev,
struct coresight_device *parent,
struct coresight_device *child)
{
int i, nr_conns;
int link_subtype;
int refport, inport, outport;
if (!parent || !child)
return;
inport = coresight_find_link_inport(csdev, parent);
outport = coresight_find_link_outport(csdev, child);
link_subtype = csdev->subtype.link_subtype;
if (link_subtype == CORESIGHT_DEV_SUBTYPE_LINK_MERG) {
refport = inport;
nr_conns = csdev->nr_inport;
} else if (link_subtype == CORESIGHT_DEV_SUBTYPE_LINK_SPLIT) {
refport = outport;
nr_conns = csdev->nr_outport;
} else {
refport = 0;
nr_conns = 1;
}
if (atomic_dec_return(&csdev->refcnt[refport]) == 0) {
if (link_ops(csdev)->disable)
link_ops(csdev)->disable(csdev, inport, outport);
}
for (i = 0; i < nr_conns; i++)
if (atomic_read(&csdev->refcnt[i]) != 0)
return;
csdev->enable = false;
}
static int coresight_enable_source(struct coresight_device *csdev, u32 mode)
{
int ret;
if (!coresight_source_is_unique(csdev)) {
dev_warn(&csdev->dev, "traceID %d not unique\n",
source_ops(csdev)->trace_id(csdev));
return -EINVAL;
}
if (!csdev->enable) {
if (source_ops(csdev)->enable) {
ret = source_ops(csdev)->enable(csdev, NULL, mode);
if (ret)
return ret;
}
csdev->enable = true;
}
atomic_inc(csdev->refcnt);
return 0;
}
static void coresight_disable_source(struct coresight_device *csdev)
{
if (atomic_dec_return(csdev->refcnt) == 0) {
if (source_ops(csdev)->disable) {
source_ops(csdev)->disable(csdev, NULL);
csdev->enable = false;
}
}
}
void coresight_disable_path(struct list_head *path)
{
u32 type;
struct coresight_node *nd;
struct coresight_device *csdev, *parent, *child;
list_for_each_entry(nd, path, link) {
csdev = nd->csdev;
type = csdev->type;
if (type == CORESIGHT_DEV_TYPE_LINKSINK)
type = (csdev == coresight_get_sink(path)) ?
CORESIGHT_DEV_TYPE_SINK :
CORESIGHT_DEV_TYPE_LINK;
switch (type) {
case CORESIGHT_DEV_TYPE_SINK:
coresight_disable_sink(csdev);
break;
case CORESIGHT_DEV_TYPE_SOURCE:
break;
case CORESIGHT_DEV_TYPE_LINK:
parent = list_prev_entry(nd, link)->csdev;
child = list_next_entry(nd, link)->csdev;
coresight_disable_link(csdev, parent, child);
break;
default:
break;
}
}
}
int coresight_enable_path(struct list_head *path, u32 mode)
{
int ret = 0;
u32 type;
struct coresight_node *nd;
struct coresight_device *csdev, *parent, *child;
list_for_each_entry_reverse(nd, path, link) {
csdev = nd->csdev;
type = csdev->type;
if (type == CORESIGHT_DEV_TYPE_LINKSINK)
type = (csdev == coresight_get_sink(path)) ?
CORESIGHT_DEV_TYPE_SINK :
CORESIGHT_DEV_TYPE_LINK;
switch (type) {
case CORESIGHT_DEV_TYPE_SINK:
ret = coresight_enable_sink(csdev, mode);
if (ret)
goto err;
break;
case CORESIGHT_DEV_TYPE_SOURCE:
break;
case CORESIGHT_DEV_TYPE_LINK:
parent = list_prev_entry(nd, link)->csdev;
child = list_next_entry(nd, link)->csdev;
ret = coresight_enable_link(csdev, parent, child);
if (ret)
goto err;
break;
default:
goto err;
}
}
out:
return ret;
err:
coresight_disable_path(path);
goto out;
}
struct coresight_device *coresight_get_sink(struct list_head *path)
{
struct coresight_device *csdev;
if (!path)
return NULL;
csdev = list_last_entry(path, struct coresight_node, link)->csdev;
if (csdev->type != CORESIGHT_DEV_TYPE_SINK &&
csdev->type != CORESIGHT_DEV_TYPE_LINKSINK)
return NULL;
return csdev;
}
static int _coresight_build_path(struct coresight_device *csdev,
struct list_head *path)
{
int i;
bool found = false;
struct coresight_node *node;
if ((csdev->type == CORESIGHT_DEV_TYPE_SINK ||
csdev->type == CORESIGHT_DEV_TYPE_LINKSINK) && csdev->activated)
goto out;
for (i = 0; i < csdev->nr_outport; i++) {
struct coresight_device *child_dev = csdev->conns[i].child_dev;
if (child_dev && _coresight_build_path(child_dev, path) == 0) {
found = true;
break;
}
}
if (!found)
return -ENODEV;
out:
node = kzalloc(sizeof(struct coresight_node), GFP_KERNEL);
if (!node)
return -ENOMEM;
node->csdev = csdev;
list_add(&node->link, path);
pm_runtime_get_sync(csdev->dev.parent);
return 0;
}
struct list_head *coresight_build_path(struct coresight_device *csdev)
{
struct list_head *path;
int rc;
path = kzalloc(sizeof(struct list_head), GFP_KERNEL);
if (!path)
return ERR_PTR(-ENOMEM);
INIT_LIST_HEAD(path);
rc = _coresight_build_path(csdev, path);
if (rc) {
kfree(path);
return ERR_PTR(rc);
}
return path;
}
void coresight_release_path(struct list_head *path)
{
struct coresight_device *csdev;
struct coresight_node *nd, *next;
list_for_each_entry_safe(nd, next, path, link) {
csdev = nd->csdev;
pm_runtime_put_sync(csdev->dev.parent);
list_del(&nd->link);
kfree(nd);
}
kfree(path);
path = NULL;
}
static int coresight_validate_source(struct coresight_device *csdev,
const char *function)
{
u32 type, subtype;
type = csdev->type;
subtype = csdev->subtype.source_subtype;
if (type != CORESIGHT_DEV_TYPE_SOURCE) {
dev_err(&csdev->dev, "wrong device type in %s\n", function);
return -EINVAL;
}
if (subtype != CORESIGHT_DEV_SUBTYPE_SOURCE_PROC &&
subtype != CORESIGHT_DEV_SUBTYPE_SOURCE_SOFTWARE) {
dev_err(&csdev->dev, "wrong device subtype in %s\n", function);
return -EINVAL;
}
return 0;
}
int coresight_enable(struct coresight_device *csdev)
{
int cpu, ret = 0;
struct list_head *path;
mutex_lock(&coresight_mutex);
ret = coresight_validate_source(csdev, __func__);
if (ret)
goto out;
if (csdev->enable)
goto out;
path = coresight_build_path(csdev);
if (IS_ERR(path)) {
pr_err("building path(s) failed\n");
ret = PTR_ERR(path);
goto out;
}
ret = coresight_enable_path(path, CS_MODE_SYSFS);
if (ret)
goto err_path;
ret = coresight_enable_source(csdev, CS_MODE_SYSFS);
if (ret)
goto err_source;
switch (csdev->subtype.source_subtype) {
case CORESIGHT_DEV_SUBTYPE_SOURCE_PROC:
cpu = source_ops(csdev)->cpu_id(csdev);
per_cpu(tracer_path, cpu) = path;
break;
case CORESIGHT_DEV_SUBTYPE_SOURCE_SOFTWARE:
stm_path = path;
break;
default:
break;
}
out:
mutex_unlock(&coresight_mutex);
return ret;
err_source:
coresight_disable_path(path);
err_path:
coresight_release_path(path);
goto out;
}
void coresight_disable(struct coresight_device *csdev)
{
int cpu, ret;
struct list_head *path = NULL;
mutex_lock(&coresight_mutex);
ret = coresight_validate_source(csdev, __func__);
if (ret)
goto out;
if (!csdev->enable)
goto out;
switch (csdev->subtype.source_subtype) {
case CORESIGHT_DEV_SUBTYPE_SOURCE_PROC:
cpu = source_ops(csdev)->cpu_id(csdev);
path = per_cpu(tracer_path, cpu);
per_cpu(tracer_path, cpu) = NULL;
break;
case CORESIGHT_DEV_SUBTYPE_SOURCE_SOFTWARE:
path = stm_path;
stm_path = NULL;
break;
default:
break;
}
coresight_disable_source(csdev);
coresight_disable_path(path);
coresight_release_path(path);
out:
mutex_unlock(&coresight_mutex);
}
static ssize_t enable_sink_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct coresight_device *csdev = to_coresight_device(dev);
return scnprintf(buf, PAGE_SIZE, "%u\n", csdev->activated);
}
static ssize_t enable_sink_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
int ret;
unsigned long val;
struct coresight_device *csdev = to_coresight_device(dev);
ret = kstrtoul(buf, 10, &val);
if (ret)
return ret;
if (val)
csdev->activated = true;
else
csdev->activated = false;
return size;
}
static ssize_t enable_source_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct coresight_device *csdev = to_coresight_device(dev);
return scnprintf(buf, PAGE_SIZE, "%u\n", csdev->enable);
}
static ssize_t enable_source_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
int ret = 0;
unsigned long val;
struct coresight_device *csdev = to_coresight_device(dev);
ret = kstrtoul(buf, 10, &val);
if (ret)
return ret;
if (val) {
ret = coresight_enable(csdev);
if (ret)
return ret;
} else {
coresight_disable(csdev);
}
return size;
}
static void coresight_device_release(struct device *dev)
{
struct coresight_device *csdev = to_coresight_device(dev);
kfree(csdev->conns);
kfree(csdev->refcnt);
kfree(csdev);
}
static int coresight_orphan_match(struct device *dev, void *data)
{
int i;
bool still_orphan = false;
struct coresight_device *csdev, *i_csdev;
struct coresight_connection *conn;
csdev = data;
i_csdev = to_coresight_device(dev);
if (csdev == i_csdev)
return 0;
if (!i_csdev->orphan)
return 0;
for (i = 0; i < i_csdev->nr_outport; i++) {
conn = &i_csdev->conns[i];
if (conn->child_dev == NULL) {
if (conn->child_name &&
!strcmp(dev_name(&csdev->dev), conn->child_name)) {
conn->child_dev = csdev;
} else {
still_orphan = true;
}
}
}
i_csdev->orphan = still_orphan;
return 0;
}
static void coresight_fixup_orphan_conns(struct coresight_device *csdev)
{
bus_for_each_dev(&coresight_bustype, NULL,
csdev, coresight_orphan_match);
}
static int coresight_name_match(struct device *dev, void *data)
{
char *to_match;
struct coresight_device *i_csdev;
to_match = data;
i_csdev = to_coresight_device(dev);
if (to_match && !strcmp(to_match, dev_name(&i_csdev->dev)))
return 1;
return 0;
}
static void coresight_fixup_device_conns(struct coresight_device *csdev)
{
int i;
struct device *dev = NULL;
struct coresight_connection *conn;
for (i = 0; i < csdev->nr_outport; i++) {
conn = &csdev->conns[i];
dev = bus_find_device(&coresight_bustype, NULL,
(void *)conn->child_name,
coresight_name_match);
if (dev) {
conn->child_dev = to_coresight_device(dev);
put_device(dev);
} else {
csdev->orphan = true;
conn->child_dev = NULL;
}
}
}
static int coresight_remove_match(struct device *dev, void *data)
{
int i;
struct coresight_device *csdev, *iterator;
struct coresight_connection *conn;
csdev = data;
iterator = to_coresight_device(dev);
if (csdev == iterator)
return 0;
for (i = 0; i < iterator->nr_outport; i++) {
conn = &iterator->conns[i];
if (conn->child_dev == NULL)
continue;
if (!strcmp(dev_name(&csdev->dev), conn->child_name)) {
iterator->orphan = true;
conn->child_dev = NULL;
break;
}
}
return 0;
}
static void coresight_remove_conns(struct coresight_device *csdev)
{
bus_for_each_dev(&coresight_bustype, NULL,
csdev, coresight_remove_match);
}
int coresight_timeout(void __iomem *addr, u32 offset, int position, int value)
{
int i;
u32 val;
for (i = TIMEOUT_US; i > 0; i--) {
val = __raw_readl(addr + offset);
if (value) {
if (val & BIT(position))
return 0;
} else {
if (!(val & BIT(position)))
return 0;
}
if (i - 1)
udelay(1);
}
return -EAGAIN;
}
static int __init coresight_init(void)
{
return bus_register(&coresight_bustype);
}
struct coresight_device *coresight_register(struct coresight_desc *desc)
{
int i;
int ret;
int link_subtype;
int nr_refcnts = 1;
atomic_t *refcnts = NULL;
struct coresight_device *csdev;
struct coresight_connection *conns = NULL;
csdev = kzalloc(sizeof(*csdev), GFP_KERNEL);
if (!csdev) {
ret = -ENOMEM;
goto err_kzalloc_csdev;
}
if (desc->type == CORESIGHT_DEV_TYPE_LINK ||
desc->type == CORESIGHT_DEV_TYPE_LINKSINK) {
link_subtype = desc->subtype.link_subtype;
if (link_subtype == CORESIGHT_DEV_SUBTYPE_LINK_MERG)
nr_refcnts = desc->pdata->nr_inport;
else if (link_subtype == CORESIGHT_DEV_SUBTYPE_LINK_SPLIT)
nr_refcnts = desc->pdata->nr_outport;
}
refcnts = kcalloc(nr_refcnts, sizeof(*refcnts), GFP_KERNEL);
if (!refcnts) {
ret = -ENOMEM;
goto err_kzalloc_refcnts;
}
csdev->refcnt = refcnts;
csdev->nr_inport = desc->pdata->nr_inport;
csdev->nr_outport = desc->pdata->nr_outport;
if (csdev->nr_outport) {
conns = kcalloc(csdev->nr_outport, sizeof(*conns), GFP_KERNEL);
if (!conns) {
ret = -ENOMEM;
goto err_kzalloc_conns;
}
for (i = 0; i < csdev->nr_outport; i++) {
conns[i].outport = desc->pdata->outports[i];
conns[i].child_name = desc->pdata->child_names[i];
conns[i].child_port = desc->pdata->child_ports[i];
}
}
csdev->conns = conns;
csdev->type = desc->type;
csdev->subtype = desc->subtype;
csdev->ops = desc->ops;
csdev->orphan = false;
csdev->dev.type = &coresight_dev_type[desc->type];
csdev->dev.groups = desc->groups;
csdev->dev.parent = desc->dev;
csdev->dev.release = coresight_device_release;
csdev->dev.bus = &coresight_bustype;
dev_set_name(&csdev->dev, "%s", desc->pdata->name);
ret = device_register(&csdev->dev);
if (ret)
goto err_device_register;
mutex_lock(&coresight_mutex);
coresight_fixup_device_conns(csdev);
coresight_fixup_orphan_conns(csdev);
mutex_unlock(&coresight_mutex);
return csdev;
err_device_register:
kfree(conns);
err_kzalloc_conns:
kfree(refcnts);
err_kzalloc_refcnts:
kfree(csdev);
err_kzalloc_csdev:
return ERR_PTR(ret);
}
void coresight_unregister(struct coresight_device *csdev)
{
coresight_remove_conns(csdev);
device_unregister(&csdev->dev);
}
