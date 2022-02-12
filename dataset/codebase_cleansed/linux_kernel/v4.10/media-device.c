static inline void __user *media_get_uptr(__u64 arg)
{
return (void __user *)(uintptr_t)arg;
}
static int media_device_open(struct file *filp)
{
return 0;
}
static int media_device_close(struct file *filp)
{
return 0;
}
static int media_device_get_info(struct media_device *dev,
struct media_device_info *info)
{
memset(info, 0, sizeof(*info));
if (dev->driver_name[0])
strlcpy(info->driver, dev->driver_name, sizeof(info->driver));
else
strlcpy(info->driver, dev->dev->driver->name,
sizeof(info->driver));
strlcpy(info->model, dev->model, sizeof(info->model));
strlcpy(info->serial, dev->serial, sizeof(info->serial));
strlcpy(info->bus_info, dev->bus_info, sizeof(info->bus_info));
info->media_version = MEDIA_API_VERSION;
info->hw_revision = dev->hw_revision;
info->driver_version = dev->driver_version;
return 0;
}
static struct media_entity *find_entity(struct media_device *mdev, u32 id)
{
struct media_entity *entity;
int next = id & MEDIA_ENT_ID_FLAG_NEXT;
id &= ~MEDIA_ENT_ID_FLAG_NEXT;
media_device_for_each_entity(entity, mdev) {
if (((media_entity_id(entity) == id) && !next) ||
((media_entity_id(entity) > id) && next)) {
return entity;
}
}
return NULL;
}
static long media_device_enum_entities(struct media_device *mdev,
struct media_entity_desc *entd)
{
struct media_entity *ent;
ent = find_entity(mdev, entd->id);
if (ent == NULL)
return -EINVAL;
memset(entd, 0, sizeof(*entd));
entd->id = media_entity_id(ent);
if (ent->name)
strlcpy(entd->name, ent->name, sizeof(entd->name));
entd->type = ent->function;
entd->revision = 0;
entd->flags = ent->flags;
entd->group_id = 0;
entd->pads = ent->num_pads;
entd->links = ent->num_links - ent->num_backlinks;
if (ent->function < MEDIA_ENT_F_OLD_BASE ||
ent->function > MEDIA_ENT_T_DEVNODE_UNKNOWN) {
if (is_media_entity_v4l2_subdev(ent))
entd->type = MEDIA_ENT_F_V4L2_SUBDEV_UNKNOWN;
else if (ent->function != MEDIA_ENT_F_IO_V4L)
entd->type = MEDIA_ENT_T_DEVNODE_UNKNOWN;
}
memcpy(&entd->raw, &ent->info, sizeof(ent->info));
return 0;
}
static void media_device_kpad_to_upad(const struct media_pad *kpad,
struct media_pad_desc *upad)
{
upad->entity = media_entity_id(kpad->entity);
upad->index = kpad->index;
upad->flags = kpad->flags;
}
static long media_device_enum_links(struct media_device *mdev,
struct media_links_enum *links)
{
struct media_entity *entity;
entity = find_entity(mdev, links->entity);
if (entity == NULL)
return -EINVAL;
if (links->pads) {
unsigned int p;
for (p = 0; p < entity->num_pads; p++) {
struct media_pad_desc pad;
memset(&pad, 0, sizeof(pad));
media_device_kpad_to_upad(&entity->pads[p], &pad);
if (copy_to_user(&links->pads[p], &pad, sizeof(pad)))
return -EFAULT;
}
}
if (links->links) {
struct media_link *link;
struct media_link_desc __user *ulink_desc = links->links;
list_for_each_entry(link, &entity->links, list) {
struct media_link_desc klink_desc;
if (link->source->entity != entity)
continue;
memset(&klink_desc, 0, sizeof(klink_desc));
media_device_kpad_to_upad(link->source,
&klink_desc.source);
media_device_kpad_to_upad(link->sink,
&klink_desc.sink);
klink_desc.flags = link->flags;
if (copy_to_user(ulink_desc, &klink_desc,
sizeof(*ulink_desc)))
return -EFAULT;
ulink_desc++;
}
}
return 0;
}
static long media_device_setup_link(struct media_device *mdev,
struct media_link_desc *linkd)
{
struct media_link *link = NULL;
struct media_entity *source;
struct media_entity *sink;
source = find_entity(mdev, linkd->source.entity);
sink = find_entity(mdev, linkd->sink.entity);
if (source == NULL || sink == NULL)
return -EINVAL;
if (linkd->source.index >= source->num_pads ||
linkd->sink.index >= sink->num_pads)
return -EINVAL;
link = media_entity_find_link(&source->pads[linkd->source.index],
&sink->pads[linkd->sink.index]);
if (link == NULL)
return -EINVAL;
return __media_entity_setup_link(link, linkd->flags);
}
static long media_device_get_topology(struct media_device *mdev,
struct media_v2_topology *topo)
{
struct media_entity *entity;
struct media_interface *intf;
struct media_pad *pad;
struct media_link *link;
struct media_v2_entity kentity, __user *uentity;
struct media_v2_interface kintf, __user *uintf;
struct media_v2_pad kpad, __user *upad;
struct media_v2_link klink, __user *ulink;
unsigned int i;
int ret = 0;
topo->topology_version = mdev->topology_version;
i = 0;
uentity = media_get_uptr(topo->ptr_entities);
media_device_for_each_entity(entity, mdev) {
i++;
if (ret || !uentity)
continue;
if (i > topo->num_entities) {
ret = -ENOSPC;
continue;
}
memset(&kentity, 0, sizeof(kentity));
kentity.id = entity->graph_obj.id;
kentity.function = entity->function;
strncpy(kentity.name, entity->name,
sizeof(kentity.name));
if (copy_to_user(uentity, &kentity, sizeof(kentity)))
ret = -EFAULT;
uentity++;
}
topo->num_entities = i;
i = 0;
uintf = media_get_uptr(topo->ptr_interfaces);
media_device_for_each_intf(intf, mdev) {
i++;
if (ret || !uintf)
continue;
if (i > topo->num_interfaces) {
ret = -ENOSPC;
continue;
}
memset(&kintf, 0, sizeof(kintf));
kintf.id = intf->graph_obj.id;
kintf.intf_type = intf->type;
kintf.flags = intf->flags;
if (media_type(&intf->graph_obj) == MEDIA_GRAPH_INTF_DEVNODE) {
struct media_intf_devnode *devnode;
devnode = intf_to_devnode(intf);
kintf.devnode.major = devnode->major;
kintf.devnode.minor = devnode->minor;
}
if (copy_to_user(uintf, &kintf, sizeof(kintf)))
ret = -EFAULT;
uintf++;
}
topo->num_interfaces = i;
i = 0;
upad = media_get_uptr(topo->ptr_pads);
media_device_for_each_pad(pad, mdev) {
i++;
if (ret || !upad)
continue;
if (i > topo->num_pads) {
ret = -ENOSPC;
continue;
}
memset(&kpad, 0, sizeof(kpad));
kpad.id = pad->graph_obj.id;
kpad.entity_id = pad->entity->graph_obj.id;
kpad.flags = pad->flags;
if (copy_to_user(upad, &kpad, sizeof(kpad)))
ret = -EFAULT;
upad++;
}
topo->num_pads = i;
i = 0;
ulink = media_get_uptr(topo->ptr_links);
media_device_for_each_link(link, mdev) {
if (link->is_backlink)
continue;
i++;
if (ret || !ulink)
continue;
if (i > topo->num_links) {
ret = -ENOSPC;
continue;
}
memset(&klink, 0, sizeof(klink));
klink.id = link->graph_obj.id;
klink.source_id = link->gobj0->id;
klink.sink_id = link->gobj1->id;
klink.flags = link->flags;
if (copy_to_user(ulink, &klink, sizeof(klink)))
ret = -EFAULT;
ulink++;
}
topo->num_links = i;
return ret;
}
static long copy_arg_from_user(void *karg, void __user *uarg, unsigned int cmd)
{
if (copy_from_user(karg, uarg, _IOC_SIZE(cmd)))
return -EFAULT;
return 0;
}
static long copy_arg_to_user(void __user *uarg, void *karg, unsigned int cmd)
{
if (copy_to_user(uarg, karg, _IOC_SIZE(cmd)))
return -EFAULT;
return 0;
}
static long media_device_ioctl(struct file *filp, unsigned int cmd,
unsigned long __arg)
{
struct media_devnode *devnode = media_devnode_data(filp);
struct media_device *dev = devnode->media_dev;
const struct media_ioctl_info *info;
void __user *arg = (void __user *)__arg;
char __karg[256], *karg = __karg;
long ret;
if (_IOC_NR(cmd) >= ARRAY_SIZE(ioctl_info)
|| ioctl_info[_IOC_NR(cmd)].cmd != cmd)
return -ENOIOCTLCMD;
info = &ioctl_info[_IOC_NR(cmd)];
if (_IOC_SIZE(info->cmd) > sizeof(__karg)) {
karg = kmalloc(_IOC_SIZE(info->cmd), GFP_KERNEL);
if (!karg)
return -ENOMEM;
}
if (info->arg_from_user) {
ret = info->arg_from_user(karg, arg, cmd);
if (ret)
goto out_free;
}
if (info->flags & MEDIA_IOC_FL_GRAPH_MUTEX)
mutex_lock(&dev->graph_mutex);
ret = info->fn(dev, karg);
if (info->flags & MEDIA_IOC_FL_GRAPH_MUTEX)
mutex_unlock(&dev->graph_mutex);
if (!ret && info->arg_to_user)
ret = info->arg_to_user(arg, karg, cmd);
out_free:
if (karg != __karg)
kfree(karg);
return ret;
}
static long media_device_enum_links32(struct media_device *mdev,
struct media_links_enum32 __user *ulinks)
{
struct media_links_enum links;
compat_uptr_t pads_ptr, links_ptr;
memset(&links, 0, sizeof(links));
if (get_user(links.entity, &ulinks->entity)
|| get_user(pads_ptr, &ulinks->pads)
|| get_user(links_ptr, &ulinks->links))
return -EFAULT;
links.pads = compat_ptr(pads_ptr);
links.links = compat_ptr(links_ptr);
return media_device_enum_links(mdev, &links);
}
static long media_device_compat_ioctl(struct file *filp, unsigned int cmd,
unsigned long arg)
{
struct media_devnode *devnode = media_devnode_data(filp);
struct media_device *dev = devnode->media_dev;
long ret;
switch (cmd) {
case MEDIA_IOC_ENUM_LINKS32:
mutex_lock(&dev->graph_mutex);
ret = media_device_enum_links32(dev,
(struct media_links_enum32 __user *)arg);
mutex_unlock(&dev->graph_mutex);
break;
default:
return media_device_ioctl(filp, cmd, arg);
}
return ret;
}
static ssize_t show_model(struct device *cd,
struct device_attribute *attr, char *buf)
{
struct media_devnode *devnode = to_media_devnode(cd);
struct media_device *mdev = devnode->media_dev;
return sprintf(buf, "%.*s\n", (int)sizeof(mdev->model), mdev->model);
}
static void media_device_release(struct media_devnode *mdev)
{
dev_dbg(mdev->parent, "Media device released\n");
}
int __must_check media_device_register_entity(struct media_device *mdev,
struct media_entity *entity)
{
struct media_entity_notify *notify, *next;
unsigned int i;
int ret;
if (entity->function == MEDIA_ENT_F_V4L2_SUBDEV_UNKNOWN ||
entity->function == MEDIA_ENT_F_UNKNOWN)
dev_warn(mdev->dev,
"Entity type for entity %s was not initialized!\n",
entity->name);
WARN_ON(entity->graph_obj.mdev != NULL);
entity->graph_obj.mdev = mdev;
INIT_LIST_HEAD(&entity->links);
entity->num_links = 0;
entity->num_backlinks = 0;
if (!ida_pre_get(&mdev->entity_internal_idx, GFP_KERNEL))
return -ENOMEM;
mutex_lock(&mdev->graph_mutex);
ret = ida_get_new_above(&mdev->entity_internal_idx, 1,
&entity->internal_idx);
if (ret < 0) {
mutex_unlock(&mdev->graph_mutex);
return ret;
}
mdev->entity_internal_idx_max =
max(mdev->entity_internal_idx_max, entity->internal_idx);
media_gobj_create(mdev, MEDIA_GRAPH_ENTITY, &entity->graph_obj);
for (i = 0; i < entity->num_pads; i++)
media_gobj_create(mdev, MEDIA_GRAPH_PAD,
&entity->pads[i].graph_obj);
list_for_each_entry_safe(notify, next, &mdev->entity_notify, list) {
(notify)->notify(entity, notify->notify_data);
}
if (mdev->entity_internal_idx_max
>= mdev->pm_count_walk.ent_enum.idx_max) {
struct media_entity_graph new = { .top = 0 };
ret = media_entity_graph_walk_init(&new, mdev);
if (ret) {
mutex_unlock(&mdev->graph_mutex);
return ret;
}
media_entity_graph_walk_cleanup(&mdev->pm_count_walk);
mdev->pm_count_walk = new;
}
mutex_unlock(&mdev->graph_mutex);
return 0;
}
static void __media_device_unregister_entity(struct media_entity *entity)
{
struct media_device *mdev = entity->graph_obj.mdev;
struct media_link *link, *tmp;
struct media_interface *intf;
unsigned int i;
ida_simple_remove(&mdev->entity_internal_idx, entity->internal_idx);
list_for_each_entry(intf, &mdev->interfaces, graph_obj.list) {
list_for_each_entry_safe(link, tmp, &intf->links, list) {
if (link->entity == entity)
__media_remove_intf_link(link);
}
}
__media_entity_remove_links(entity);
for (i = 0; i < entity->num_pads; i++)
media_gobj_destroy(&entity->pads[i].graph_obj);
media_gobj_destroy(&entity->graph_obj);
entity->graph_obj.mdev = NULL;
}
void media_device_unregister_entity(struct media_entity *entity)
{
struct media_device *mdev = entity->graph_obj.mdev;
if (mdev == NULL)
return;
mutex_lock(&mdev->graph_mutex);
__media_device_unregister_entity(entity);
mutex_unlock(&mdev->graph_mutex);
}
void media_device_init(struct media_device *mdev)
{
INIT_LIST_HEAD(&mdev->entities);
INIT_LIST_HEAD(&mdev->interfaces);
INIT_LIST_HEAD(&mdev->pads);
INIT_LIST_HEAD(&mdev->links);
INIT_LIST_HEAD(&mdev->entity_notify);
mutex_init(&mdev->graph_mutex);
ida_init(&mdev->entity_internal_idx);
dev_dbg(mdev->dev, "Media device initialized\n");
}
void media_device_cleanup(struct media_device *mdev)
{
ida_destroy(&mdev->entity_internal_idx);
mdev->entity_internal_idx_max = 0;
media_entity_graph_walk_cleanup(&mdev->pm_count_walk);
mutex_destroy(&mdev->graph_mutex);
}
int __must_check __media_device_register(struct media_device *mdev,
struct module *owner)
{
struct media_devnode *devnode;
int ret;
devnode = kzalloc(sizeof(*devnode), GFP_KERNEL);
if (!devnode)
return -ENOMEM;
mdev->devnode = devnode;
devnode->fops = &media_device_fops;
devnode->parent = mdev->dev;
devnode->release = media_device_release;
mdev->topology_version = 0;
ret = media_devnode_register(mdev, devnode, owner);
if (ret < 0) {
mdev->devnode = NULL;
return ret;
}
ret = device_create_file(&devnode->dev, &dev_attr_model);
if (ret < 0) {
mdev->devnode = NULL;
media_devnode_unregister_prepare(devnode);
media_devnode_unregister(devnode);
return ret;
}
dev_dbg(mdev->dev, "Media device registered\n");
return 0;
}
int __must_check media_device_register_entity_notify(struct media_device *mdev,
struct media_entity_notify *nptr)
{
mutex_lock(&mdev->graph_mutex);
list_add_tail(&nptr->list, &mdev->entity_notify);
mutex_unlock(&mdev->graph_mutex);
return 0;
}
static void __media_device_unregister_entity_notify(struct media_device *mdev,
struct media_entity_notify *nptr)
{
list_del(&nptr->list);
}
void media_device_unregister_entity_notify(struct media_device *mdev,
struct media_entity_notify *nptr)
{
mutex_lock(&mdev->graph_mutex);
__media_device_unregister_entity_notify(mdev, nptr);
mutex_unlock(&mdev->graph_mutex);
}
void media_device_unregister(struct media_device *mdev)
{
struct media_entity *entity;
struct media_entity *next;
struct media_interface *intf, *tmp_intf;
struct media_entity_notify *notify, *nextp;
if (mdev == NULL)
return;
mutex_lock(&mdev->graph_mutex);
if (!media_devnode_is_registered(mdev->devnode)) {
mutex_unlock(&mdev->graph_mutex);
return;
}
media_devnode_unregister_prepare(mdev->devnode);
list_for_each_entry_safe(entity, next, &mdev->entities, graph_obj.list)
__media_device_unregister_entity(entity);
list_for_each_entry_safe(notify, nextp, &mdev->entity_notify, list)
__media_device_unregister_entity_notify(mdev, notify);
list_for_each_entry_safe(intf, tmp_intf, &mdev->interfaces,
graph_obj.list) {
__media_remove_intf_links(intf);
media_gobj_destroy(&intf->graph_obj);
}
mutex_unlock(&mdev->graph_mutex);
dev_dbg(mdev->dev, "Media device unregistered\n");
device_remove_file(&mdev->devnode->dev, &dev_attr_model);
media_devnode_unregister(mdev->devnode);
mdev->devnode = NULL;
}
void media_device_pci_init(struct media_device *mdev,
struct pci_dev *pci_dev,
const char *name)
{
mdev->dev = &pci_dev->dev;
if (name)
strlcpy(mdev->model, name, sizeof(mdev->model));
else
strlcpy(mdev->model, pci_name(pci_dev), sizeof(mdev->model));
sprintf(mdev->bus_info, "PCI:%s", pci_name(pci_dev));
mdev->hw_revision = (pci_dev->subsystem_vendor << 16)
| pci_dev->subsystem_device;
mdev->driver_version = LINUX_VERSION_CODE;
media_device_init(mdev);
}
void __media_device_usb_init(struct media_device *mdev,
struct usb_device *udev,
const char *board_name,
const char *driver_name)
{
mdev->dev = &udev->dev;
if (driver_name)
strlcpy(mdev->driver_name, driver_name,
sizeof(mdev->driver_name));
if (board_name)
strlcpy(mdev->model, board_name, sizeof(mdev->model));
else if (udev->product)
strlcpy(mdev->model, udev->product, sizeof(mdev->model));
else
strlcpy(mdev->model, "unknown model", sizeof(mdev->model));
if (udev->serial)
strlcpy(mdev->serial, udev->serial, sizeof(mdev->serial));
usb_make_path(udev, mdev->bus_info, sizeof(mdev->bus_info));
mdev->hw_revision = le16_to_cpu(udev->descriptor.bcdDevice);
mdev->driver_version = LINUX_VERSION_CODE;
media_device_init(mdev);
}
