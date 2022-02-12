static int media_device_open(struct file *filp)
{
return 0;
}
static int media_device_close(struct file *filp)
{
return 0;
}
static int media_device_get_info(struct media_device *dev,
struct media_device_info __user *__info)
{
struct media_device_info info;
memset(&info, 0, sizeof(info));
strlcpy(info.driver, dev->dev->driver->name, sizeof(info.driver));
strlcpy(info.model, dev->model, sizeof(info.model));
strlcpy(info.serial, dev->serial, sizeof(info.serial));
strlcpy(info.bus_info, dev->bus_info, sizeof(info.bus_info));
info.media_version = MEDIA_API_VERSION;
info.hw_revision = dev->hw_revision;
info.driver_version = dev->driver_version;
if (copy_to_user(__info, &info, sizeof(*__info)))
return -EFAULT;
return 0;
}
static struct media_entity *find_entity(struct media_device *mdev, u32 id)
{
struct media_entity *entity;
int next = id & MEDIA_ENT_ID_FLAG_NEXT;
id &= ~MEDIA_ENT_ID_FLAG_NEXT;
spin_lock(&mdev->lock);
media_device_for_each_entity(entity, mdev) {
if (((media_entity_id(entity) == id) && !next) ||
((media_entity_id(entity) > id) && next)) {
spin_unlock(&mdev->lock);
return entity;
}
}
spin_unlock(&mdev->lock);
return NULL;
}
static long media_device_enum_entities(struct media_device *mdev,
struct media_entity_desc __user *uent)
{
struct media_entity *ent;
struct media_entity_desc u_ent;
memset(&u_ent, 0, sizeof(u_ent));
if (copy_from_user(&u_ent.id, &uent->id, sizeof(u_ent.id)))
return -EFAULT;
ent = find_entity(mdev, u_ent.id);
if (ent == NULL)
return -EINVAL;
u_ent.id = media_entity_id(ent);
if (ent->name)
strlcpy(u_ent.name, ent->name, sizeof(u_ent.name));
u_ent.type = ent->function;
u_ent.revision = 0;
u_ent.flags = ent->flags;
u_ent.group_id = 0;
u_ent.pads = ent->num_pads;
u_ent.links = ent->num_links - ent->num_backlinks;
if (ent->function < MEDIA_ENT_F_OLD_BASE ||
ent->function > MEDIA_ENT_T_DEVNODE_UNKNOWN) {
if (is_media_entity_v4l2_subdev(ent))
u_ent.type = MEDIA_ENT_F_V4L2_SUBDEV_UNKNOWN;
else if (ent->function != MEDIA_ENT_F_IO_V4L)
u_ent.type = MEDIA_ENT_T_DEVNODE_UNKNOWN;
}
memcpy(&u_ent.raw, &ent->info, sizeof(ent->info));
if (copy_to_user(uent, &u_ent, sizeof(u_ent)))
return -EFAULT;
return 0;
}
static void media_device_kpad_to_upad(const struct media_pad *kpad,
struct media_pad_desc *upad)
{
upad->entity = media_entity_id(kpad->entity);
upad->index = kpad->index;
upad->flags = kpad->flags;
}
static long __media_device_enum_links(struct media_device *mdev,
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
static long media_device_enum_links(struct media_device *mdev,
struct media_links_enum __user *ulinks)
{
struct media_links_enum links;
int rval;
if (copy_from_user(&links, ulinks, sizeof(links)))
return -EFAULT;
rval = __media_device_enum_links(mdev, &links);
if (rval < 0)
return rval;
if (copy_to_user(ulinks, &links, sizeof(*ulinks)))
return -EFAULT;
return 0;
}
static long media_device_setup_link(struct media_device *mdev,
struct media_link_desc __user *_ulink)
{
struct media_link *link = NULL;
struct media_link_desc ulink;
struct media_entity *source;
struct media_entity *sink;
int ret;
if (copy_from_user(&ulink, _ulink, sizeof(ulink)))
return -EFAULT;
source = find_entity(mdev, ulink.source.entity);
sink = find_entity(mdev, ulink.sink.entity);
if (source == NULL || sink == NULL)
return -EINVAL;
if (ulink.source.index >= source->num_pads ||
ulink.sink.index >= sink->num_pads)
return -EINVAL;
link = media_entity_find_link(&source->pads[ulink.source.index],
&sink->pads[ulink.sink.index]);
if (link == NULL)
return -EINVAL;
ret = __media_entity_setup_link(link, ulink.flags);
if (copy_to_user(_ulink, &ulink, sizeof(ulink)))
return -EFAULT;
return ret;
}
static long media_device_ioctl(struct file *filp, unsigned int cmd,
unsigned long arg)
{
struct media_devnode *devnode = media_devnode_data(filp);
struct media_device *dev = to_media_device(devnode);
long ret;
switch (cmd) {
case MEDIA_IOC_DEVICE_INFO:
ret = media_device_get_info(dev,
(struct media_device_info __user *)arg);
break;
case MEDIA_IOC_ENUM_ENTITIES:
ret = media_device_enum_entities(dev,
(struct media_entity_desc __user *)arg);
break;
case MEDIA_IOC_ENUM_LINKS:
mutex_lock(&dev->graph_mutex);
ret = media_device_enum_links(dev,
(struct media_links_enum __user *)arg);
mutex_unlock(&dev->graph_mutex);
break;
case MEDIA_IOC_SETUP_LINK:
mutex_lock(&dev->graph_mutex);
ret = media_device_setup_link(dev,
(struct media_link_desc __user *)arg);
mutex_unlock(&dev->graph_mutex);
break;
#if 0
case MEDIA_IOC_G_TOPOLOGY:
mutex_lock(&dev->graph_mutex);
ret = media_device_get_topology(dev,
(struct media_v2_topology __user *)arg);
mutex_unlock(&dev->graph_mutex);
break;
#endif
default:
ret = -ENOIOCTLCMD;
}
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
return __media_device_enum_links(mdev, &links);
}
static long media_device_compat_ioctl(struct file *filp, unsigned int cmd,
unsigned long arg)
{
struct media_devnode *devnode = media_devnode_data(filp);
struct media_device *dev = to_media_device(devnode);
long ret;
switch (cmd) {
case MEDIA_IOC_DEVICE_INFO:
case MEDIA_IOC_ENUM_ENTITIES:
case MEDIA_IOC_SETUP_LINK:
#if 0
case MEDIA_IOC_G_TOPOLOGY:
#endif
return media_device_ioctl(filp, cmd, arg);
case MEDIA_IOC_ENUM_LINKS32:
mutex_lock(&dev->graph_mutex);
ret = media_device_enum_links32(dev,
(struct media_links_enum32 __user *)arg);
mutex_unlock(&dev->graph_mutex);
break;
default:
ret = -ENOIOCTLCMD;
}
return ret;
}
static ssize_t show_model(struct device *cd,
struct device_attribute *attr, char *buf)
{
struct media_device *mdev = to_media_device(to_media_devnode(cd));
return sprintf(buf, "%.*s\n", (int)sizeof(mdev->model), mdev->model);
}
static void media_device_release(struct media_devnode *mdev)
{
dev_dbg(mdev->parent, "Media device released\n");
}
int __must_check media_device_register_entity(struct media_device *mdev,
struct media_entity *entity)
{
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
spin_lock(&mdev->lock);
ret = ida_get_new_above(&mdev->entity_internal_idx, 1,
&entity->internal_idx);
if (ret < 0) {
spin_unlock(&mdev->lock);
return ret;
}
mdev->entity_internal_idx_max =
max(mdev->entity_internal_idx_max, entity->internal_idx);
media_gobj_create(mdev, MEDIA_GRAPH_ENTITY, &entity->graph_obj);
for (i = 0; i < entity->num_pads; i++)
media_gobj_create(mdev, MEDIA_GRAPH_PAD,
&entity->pads[i].graph_obj);
spin_unlock(&mdev->lock);
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
spin_lock(&mdev->lock);
__media_device_unregister_entity(entity);
spin_unlock(&mdev->lock);
}
void media_device_init(struct media_device *mdev)
{
INIT_LIST_HEAD(&mdev->entities);
INIT_LIST_HEAD(&mdev->interfaces);
INIT_LIST_HEAD(&mdev->pads);
INIT_LIST_HEAD(&mdev->links);
spin_lock_init(&mdev->lock);
mutex_init(&mdev->graph_mutex);
ida_init(&mdev->entity_internal_idx);
dev_dbg(mdev->dev, "Media device initialized\n");
}
void media_device_cleanup(struct media_device *mdev)
{
ida_destroy(&mdev->entity_internal_idx);
mdev->entity_internal_idx_max = 0;
mutex_destroy(&mdev->graph_mutex);
}
int __must_check __media_device_register(struct media_device *mdev,
struct module *owner)
{
int ret;
mdev->devnode.fops = &media_device_fops;
mdev->devnode.parent = mdev->dev;
mdev->devnode.release = media_device_release;
mdev->topology_version = 0;
ret = media_devnode_register(&mdev->devnode, owner);
if (ret < 0)
return ret;
ret = device_create_file(&mdev->devnode.dev, &dev_attr_model);
if (ret < 0) {
media_devnode_unregister(&mdev->devnode);
return ret;
}
dev_dbg(mdev->dev, "Media device registered\n");
return 0;
}
void media_device_unregister(struct media_device *mdev)
{
struct media_entity *entity;
struct media_entity *next;
struct media_interface *intf, *tmp_intf;
if (mdev == NULL)
return;
spin_lock(&mdev->lock);
if (!media_devnode_is_registered(&mdev->devnode)) {
spin_unlock(&mdev->lock);
return;
}
list_for_each_entry_safe(entity, next, &mdev->entities, graph_obj.list)
__media_device_unregister_entity(entity);
list_for_each_entry_safe(intf, tmp_intf, &mdev->interfaces,
graph_obj.list) {
__media_remove_intf_links(intf);
media_gobj_destroy(&intf->graph_obj);
kfree(intf);
}
spin_unlock(&mdev->lock);
device_remove_file(&mdev->devnode.dev, &dev_attr_model);
media_devnode_unregister(&mdev->devnode);
dev_dbg(mdev->dev, "Media device unregistered\n");
}
static void media_device_release_devres(struct device *dev, void *res)
{
}
struct media_device *media_device_get_devres(struct device *dev)
{
struct media_device *mdev;
mdev = devres_find(dev, media_device_release_devres, NULL, NULL);
if (mdev)
return mdev;
mdev = devres_alloc(media_device_release_devres,
sizeof(struct media_device), GFP_KERNEL);
if (!mdev)
return NULL;
return devres_get(dev, mdev, NULL, NULL);
}
struct media_device *media_device_find_devres(struct device *dev)
{
return devres_find(dev, media_device_release_devres, NULL, NULL);
}
