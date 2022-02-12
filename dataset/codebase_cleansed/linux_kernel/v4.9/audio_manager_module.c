static ssize_t gb_audio_module_attr_show(
struct kobject *kobj, struct attribute *attr, char *buf)
{
struct gb_audio_manager_module_attribute *attribute;
struct gb_audio_manager_module *module;
attribute = to_gb_audio_module_attr(attr);
module = to_gb_audio_module(kobj);
if (!attribute->show)
return -EIO;
return attribute->show(module, attribute, buf);
}
static ssize_t gb_audio_module_attr_store(struct kobject *kobj,
struct attribute *attr,
const char *buf, size_t len)
{
struct gb_audio_manager_module_attribute *attribute;
struct gb_audio_manager_module *module;
attribute = to_gb_audio_module_attr(attr);
module = to_gb_audio_module(kobj);
if (!attribute->store)
return -EIO;
return attribute->store(module, attribute, buf, len);
}
static void gb_audio_module_release(struct kobject *kobj)
{
struct gb_audio_manager_module *module = to_gb_audio_module(kobj);
pr_info("Destroying audio module #%d\n", module->id);
kfree(module);
}
static ssize_t gb_audio_module_name_show(
struct gb_audio_manager_module *module,
struct gb_audio_manager_module_attribute *attr, char *buf)
{
return sprintf(buf, "%s", module->desc.name);
}
static ssize_t gb_audio_module_slot_show(
struct gb_audio_manager_module *module,
struct gb_audio_manager_module_attribute *attr, char *buf)
{
return sprintf(buf, "%d", module->desc.slot);
}
static ssize_t gb_audio_module_vid_show(
struct gb_audio_manager_module *module,
struct gb_audio_manager_module_attribute *attr, char *buf)
{
return sprintf(buf, "%d", module->desc.vid);
}
static ssize_t gb_audio_module_pid_show(
struct gb_audio_manager_module *module,
struct gb_audio_manager_module_attribute *attr, char *buf)
{
return sprintf(buf, "%d", module->desc.pid);
}
static ssize_t gb_audio_module_cport_show(
struct gb_audio_manager_module *module,
struct gb_audio_manager_module_attribute *attr, char *buf)
{
return sprintf(buf, "%d", module->desc.cport);
}
static ssize_t gb_audio_module_ip_devices_show(
struct gb_audio_manager_module *module,
struct gb_audio_manager_module_attribute *attr, char *buf)
{
return sprintf(buf, "0x%X", module->desc.ip_devices);
}
static ssize_t gb_audio_module_op_devices_show(
struct gb_audio_manager_module *module,
struct gb_audio_manager_module_attribute *attr, char *buf)
{
return sprintf(buf, "0x%X", module->desc.op_devices);
}
static void send_add_uevent(struct gb_audio_manager_module *module)
{
char name_string[128];
char slot_string[64];
char vid_string[64];
char pid_string[64];
char cport_string[64];
char ip_devices_string[64];
char op_devices_string[64];
char *envp[] = {
name_string,
slot_string,
vid_string,
pid_string,
cport_string,
ip_devices_string,
op_devices_string,
NULL
};
snprintf(name_string, 128, "NAME=%s", module->desc.name);
snprintf(slot_string, 64, "SLOT=%d", module->desc.slot);
snprintf(vid_string, 64, "VID=%d", module->desc.vid);
snprintf(pid_string, 64, "PID=%d", module->desc.pid);
snprintf(cport_string, 64, "CPORT=%d", module->desc.cport);
snprintf(ip_devices_string, 64, "I/P DEVICES=0x%X",
module->desc.ip_devices);
snprintf(op_devices_string, 64, "O/P DEVICES=0x%X",
module->desc.op_devices);
kobject_uevent_env(&module->kobj, KOBJ_ADD, envp);
}
int gb_audio_manager_module_create(
struct gb_audio_manager_module **module,
struct kset *manager_kset,
int id, struct gb_audio_manager_module_descriptor *desc)
{
int err;
struct gb_audio_manager_module *m;
m = kzalloc(sizeof(*m), GFP_ATOMIC);
if (!m)
return -ENOMEM;
INIT_LIST_HEAD(&m->list);
m->id = id;
memcpy(&m->desc, desc, sizeof(*desc));
m->kobj.kset = manager_kset;
err = kobject_init_and_add(&m->kobj, &gb_audio_module_type, NULL, "%d",
id);
if (err) {
pr_err("failed initializing kobject for audio module #%d\n",
id);
kobject_put(&m->kobj);
return err;
}
send_add_uevent(m);
*module = m;
pr_info("Created audio module #%d\n", id);
return 0;
}
void gb_audio_manager_module_dump(struct gb_audio_manager_module *module)
{
pr_info("audio module #%d name=%s slot=%d vid=%d pid=%d cport=%d i/p devices=0x%X o/p devices=0x%X\n",
module->id,
module->desc.name,
module->desc.slot,
module->desc.vid,
module->desc.pid,
module->desc.cport,
module->desc.ip_devices,
module->desc.op_devices);
}
