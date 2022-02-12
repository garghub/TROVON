static ssize_t edac_device_ctl_log_ue_show(struct edac_device_ctl_info
*ctl_info, char *data)
{
return sprintf(data, "%u\n", ctl_info->log_ue);
}
static ssize_t edac_device_ctl_log_ue_store(struct edac_device_ctl_info
*ctl_info, const char *data,
size_t count)
{
ctl_info->log_ue = (simple_strtoul(data, NULL, 0) != 0);
return count;
}
static ssize_t edac_device_ctl_log_ce_show(struct edac_device_ctl_info
*ctl_info, char *data)
{
return sprintf(data, "%u\n", ctl_info->log_ce);
}
static ssize_t edac_device_ctl_log_ce_store(struct edac_device_ctl_info
*ctl_info, const char *data,
size_t count)
{
ctl_info->log_ce = (simple_strtoul(data, NULL, 0) != 0);
return count;
}
static ssize_t edac_device_ctl_panic_on_ue_show(struct edac_device_ctl_info
*ctl_info, char *data)
{
return sprintf(data, "%u\n", ctl_info->panic_on_ue);
}
static ssize_t edac_device_ctl_panic_on_ue_store(struct edac_device_ctl_info
*ctl_info, const char *data,
size_t count)
{
ctl_info->panic_on_ue = (simple_strtoul(data, NULL, 0) != 0);
return count;
}
static ssize_t edac_device_ctl_poll_msec_show(struct edac_device_ctl_info
*ctl_info, char *data)
{
return sprintf(data, "%u\n", ctl_info->poll_msec);
}
static ssize_t edac_device_ctl_poll_msec_store(struct edac_device_ctl_info
*ctl_info, const char *data,
size_t count)
{
unsigned long value;
value = simple_strtoul(data, NULL, 0);
edac_device_reset_delay_period(ctl_info, value);
return count;
}
static ssize_t edac_dev_ctl_info_show(struct kobject *kobj,
struct attribute *attr, char *buffer)
{
struct edac_device_ctl_info *edac_dev = to_ctl_info(kobj);
struct ctl_info_attribute *ctl_info_attr = to_ctl_info_attr(attr);
if (ctl_info_attr->show)
return ctl_info_attr->show(edac_dev, buffer);
return -EIO;
}
static ssize_t edac_dev_ctl_info_store(struct kobject *kobj,
struct attribute *attr,
const char *buffer, size_t count)
{
struct edac_device_ctl_info *edac_dev = to_ctl_info(kobj);
struct ctl_info_attribute *ctl_info_attr = to_ctl_info_attr(attr);
if (ctl_info_attr->store)
return ctl_info_attr->store(edac_dev, buffer, count);
return -EIO;
}
static void edac_device_ctrl_master_release(struct kobject *kobj)
{
struct edac_device_ctl_info *edac_dev = to_edacdev(kobj);
edac_dbg(4, "control index=%d\n", edac_dev->dev_idx);
module_put(edac_dev->owner);
kfree(edac_dev);
}
int edac_device_register_sysfs_main_kobj(struct edac_device_ctl_info *edac_dev)
{
struct bus_type *edac_subsys;
int err;
edac_dbg(1, "\n");
edac_subsys = edac_get_sysfs_subsys();
if (edac_subsys == NULL) {
edac_dbg(1, "no edac_subsys error\n");
err = -ENODEV;
goto err_out;
}
edac_dev->edac_subsys = edac_subsys;
memset(&edac_dev->kobj, 0, sizeof(struct kobject));
edac_dev->owner = THIS_MODULE;
if (!try_module_get(edac_dev->owner)) {
err = -ENODEV;
goto err_mod_get;
}
err = kobject_init_and_add(&edac_dev->kobj, &ktype_device_ctrl,
&edac_subsys->dev_root->kobj,
"%s", edac_dev->name);
if (err) {
edac_dbg(1, "Failed to register '.../edac/%s'\n",
edac_dev->name);
goto err_kobj_reg;
}
kobject_uevent(&edac_dev->kobj, KOBJ_ADD);
edac_dbg(4, "Registered '.../edac/%s' kobject\n", edac_dev->name);
return 0;
err_kobj_reg:
module_put(edac_dev->owner);
err_mod_get:
edac_put_sysfs_subsys();
err_out:
return err;
}
void edac_device_unregister_sysfs_main_kobj(struct edac_device_ctl_info *dev)
{
edac_dbg(0, "\n");
edac_dbg(4, "name of kobject is: %s\n", kobject_name(&dev->kobj));
kobject_put(&dev->kobj);
edac_put_sysfs_subsys();
}
static ssize_t instance_ue_count_show(struct edac_device_instance *instance,
char *data)
{
return sprintf(data, "%u\n", instance->counters.ue_count);
}
static ssize_t instance_ce_count_show(struct edac_device_instance *instance,
char *data)
{
return sprintf(data, "%u\n", instance->counters.ce_count);
}
static void edac_device_ctrl_instance_release(struct kobject *kobj)
{
struct edac_device_instance *instance;
edac_dbg(1, "\n");
instance = to_instance(kobj);
kobject_put(&instance->ctl->kobj);
}
static ssize_t edac_dev_instance_show(struct kobject *kobj,
struct attribute *attr, char *buffer)
{
struct edac_device_instance *instance = to_instance(kobj);
struct instance_attribute *instance_attr = to_instance_attr(attr);
if (instance_attr->show)
return instance_attr->show(instance, buffer);
return -EIO;
}
static ssize_t edac_dev_instance_store(struct kobject *kobj,
struct attribute *attr,
const char *buffer, size_t count)
{
struct edac_device_instance *instance = to_instance(kobj);
struct instance_attribute *instance_attr = to_instance_attr(attr);
if (instance_attr->store)
return instance_attr->store(instance, buffer, count);
return -EIO;
}
static ssize_t block_ue_count_show(struct kobject *kobj,
struct attribute *attr, char *data)
{
struct edac_device_block *block = to_block(kobj);
return sprintf(data, "%u\n", block->counters.ue_count);
}
static ssize_t block_ce_count_show(struct kobject *kobj,
struct attribute *attr, char *data)
{
struct edac_device_block *block = to_block(kobj);
return sprintf(data, "%u\n", block->counters.ce_count);
}
static void edac_device_ctrl_block_release(struct kobject *kobj)
{
struct edac_device_block *block;
edac_dbg(1, "\n");
block = to_block(kobj);
kobject_put(&block->instance->ctl->kobj);
}
static ssize_t edac_dev_block_show(struct kobject *kobj,
struct attribute *attr, char *buffer)
{
struct edac_dev_sysfs_block_attribute *block_attr =
to_block_attr(attr);
if (block_attr->show)
return block_attr->show(kobj, attr, buffer);
return -EIO;
}
static ssize_t edac_dev_block_store(struct kobject *kobj,
struct attribute *attr,
const char *buffer, size_t count)
{
struct edac_dev_sysfs_block_attribute *block_attr;
block_attr = to_block_attr(attr);
if (block_attr->store)
return block_attr->store(kobj, attr, buffer, count);
return -EIO;
}
static int edac_device_create_block(struct edac_device_ctl_info *edac_dev,
struct edac_device_instance *instance,
struct edac_device_block *block)
{
int i;
int err;
struct edac_dev_sysfs_block_attribute *sysfs_attrib;
struct kobject *main_kobj;
edac_dbg(4, "Instance '%s' inst_p=%p block '%s' block_p=%p\n",
instance->name, instance, block->name, block);
edac_dbg(4, "block kobj=%p block kobj->parent=%p\n",
&block->kobj, &block->kobj.parent);
memset(&block->kobj, 0, sizeof(struct kobject));
main_kobj = kobject_get(&edac_dev->kobj);
if (!main_kobj) {
err = -ENODEV;
goto err_out;
}
err = kobject_init_and_add(&block->kobj, &ktype_block_ctrl,
&instance->kobj,
"%s", block->name);
if (err) {
edac_dbg(1, "Failed to register instance '%s'\n", block->name);
kobject_put(main_kobj);
err = -ENODEV;
goto err_out;
}
sysfs_attrib = block->block_attributes;
if (sysfs_attrib && block->nr_attribs) {
for (i = 0; i < block->nr_attribs; i++, sysfs_attrib++) {
edac_dbg(4, "creating block attrib='%s' attrib->%p to kobj=%p\n",
sysfs_attrib->attr.name,
sysfs_attrib, &block->kobj);
err = sysfs_create_file(&block->kobj,
&sysfs_attrib->attr);
if (err)
goto err_on_attrib;
}
}
kobject_uevent(&block->kobj, KOBJ_ADD);
return 0;
err_on_attrib:
kobject_put(&block->kobj);
err_out:
return err;
}
static void edac_device_delete_block(struct edac_device_ctl_info *edac_dev,
struct edac_device_block *block)
{
struct edac_dev_sysfs_block_attribute *sysfs_attrib;
int i;
sysfs_attrib = block->block_attributes;
if (sysfs_attrib && block->nr_attribs) {
for (i = 0; i < block->nr_attribs; i++, sysfs_attrib++) {
sysfs_remove_file(&block->kobj,
(struct attribute *) sysfs_attrib);
}
}
kobject_put(&block->kobj);
}
static int edac_device_create_instance(struct edac_device_ctl_info *edac_dev,
int idx)
{
int i, j;
int err;
struct edac_device_instance *instance;
struct kobject *main_kobj;
instance = &edac_dev->instances[idx];
memset(&instance->kobj, 0, sizeof(struct kobject));
instance->ctl = edac_dev;
main_kobj = kobject_get(&edac_dev->kobj);
if (!main_kobj) {
err = -ENODEV;
goto err_out;
}
err = kobject_init_and_add(&instance->kobj, &ktype_instance_ctrl,
&edac_dev->kobj, "%s", instance->name);
if (err != 0) {
edac_dbg(2, "Failed to register instance '%s'\n",
instance->name);
kobject_put(main_kobj);
goto err_out;
}
edac_dbg(4, "now register '%d' blocks for instance %d\n",
instance->nr_blocks, idx);
for (i = 0; i < instance->nr_blocks; i++) {
err = edac_device_create_block(edac_dev, instance,
&instance->blocks[i]);
if (err) {
for (j = 0; j < i; j++)
edac_device_delete_block(edac_dev,
&instance->blocks[j]);
goto err_release_instance_kobj;
}
}
kobject_uevent(&instance->kobj, KOBJ_ADD);
edac_dbg(4, "Registered instance %d '%s' kobject\n",
idx, instance->name);
return 0;
err_release_instance_kobj:
kobject_put(&instance->kobj);
err_out:
return err;
}
static void edac_device_delete_instance(struct edac_device_ctl_info *edac_dev,
int idx)
{
struct edac_device_instance *instance;
int i;
instance = &edac_dev->instances[idx];
for (i = 0; i < instance->nr_blocks; i++)
edac_device_delete_block(edac_dev, &instance->blocks[i]);
kobject_put(&instance->kobj);
}
static int edac_device_create_instances(struct edac_device_ctl_info *edac_dev)
{
int i, j;
int err;
edac_dbg(0, "\n");
for (i = 0; i < edac_dev->nr_instances; i++) {
err = edac_device_create_instance(edac_dev, i);
if (err) {
for (j = 0; j < i; j++)
edac_device_delete_instance(edac_dev, j);
return err;
}
}
return 0;
}
static void edac_device_delete_instances(struct edac_device_ctl_info *edac_dev)
{
int i;
for (i = 0; i < edac_dev->nr_instances; i++)
edac_device_delete_instance(edac_dev, i);
}
static int edac_device_add_main_sysfs_attributes(
struct edac_device_ctl_info *edac_dev)
{
struct edac_dev_sysfs_attribute *sysfs_attrib;
int err = 0;
sysfs_attrib = edac_dev->sysfs_attributes;
if (sysfs_attrib) {
while (sysfs_attrib->attr.name != NULL) {
err = sysfs_create_file(&edac_dev->kobj,
(struct attribute*) sysfs_attrib);
if (err)
goto err_out;
sysfs_attrib++;
}
}
err_out:
return err;
}
static void edac_device_remove_main_sysfs_attributes(
struct edac_device_ctl_info *edac_dev)
{
struct edac_dev_sysfs_attribute *sysfs_attrib;
sysfs_attrib = edac_dev->sysfs_attributes;
if (sysfs_attrib) {
while (sysfs_attrib->attr.name != NULL) {
sysfs_remove_file(&edac_dev->kobj,
(struct attribute *) sysfs_attrib);
sysfs_attrib++;
}
}
}
int edac_device_create_sysfs(struct edac_device_ctl_info *edac_dev)
{
int err;
struct kobject *edac_kobj = &edac_dev->kobj;
edac_dbg(0, "idx=%d\n", edac_dev->dev_idx);
err = edac_device_add_main_sysfs_attributes(edac_dev);
if (err) {
edac_dbg(0, "failed to add sysfs attribs\n");
goto err_out;
}
err = sysfs_create_link(edac_kobj,
&edac_dev->dev->kobj, EDAC_DEVICE_SYMLINK);
if (err) {
edac_dbg(0, "sysfs_create_link() returned err= %d\n", err);
goto err_remove_main_attribs;
}
err = edac_device_create_instances(edac_dev);
if (err) {
edac_dbg(0, "edac_device_create_instances() returned err= %d\n",
err);
goto err_remove_link;
}
edac_dbg(4, "create-instances done, idx=%d\n", edac_dev->dev_idx);
return 0;
err_remove_link:
sysfs_remove_link(&edac_dev->kobj, EDAC_DEVICE_SYMLINK);
err_remove_main_attribs:
edac_device_remove_main_sysfs_attributes(edac_dev);
err_out:
return err;
}
void edac_device_remove_sysfs(struct edac_device_ctl_info *edac_dev)
{
edac_dbg(0, "\n");
edac_device_remove_main_sysfs_attributes(edac_dev);
sysfs_remove_link(&edac_dev->kobj, EDAC_DEVICE_SYMLINK);
edac_device_delete_instances(edac_dev);
}
