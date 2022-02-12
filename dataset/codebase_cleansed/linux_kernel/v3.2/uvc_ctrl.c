static __s32 uvc_ctrl_get_zoom(struct uvc_control_mapping *mapping,
__u8 query, const __u8 *data)
{
__s8 zoom = (__s8)data[0];
switch (query) {
case UVC_GET_CUR:
return (zoom == 0) ? 0 : (zoom > 0 ? data[2] : -data[2]);
case UVC_GET_MIN:
case UVC_GET_MAX:
case UVC_GET_RES:
case UVC_GET_DEF:
default:
return data[2];
}
}
static void uvc_ctrl_set_zoom(struct uvc_control_mapping *mapping,
__s32 value, __u8 *data)
{
data[0] = value == 0 ? 0 : (value > 0) ? 1 : 0xff;
data[2] = min((int)abs(value), 0xff);
}
static inline __u8 *uvc_ctrl_data(struct uvc_control *ctrl, int id)
{
return ctrl->uvc_data + id * ctrl->info.size;
}
static inline int uvc_test_bit(const __u8 *data, int bit)
{
return (data[bit >> 3] >> (bit & 7)) & 1;
}
static inline void uvc_clear_bit(__u8 *data, int bit)
{
data[bit >> 3] &= ~(1 << (bit & 7));
}
static __s32 uvc_get_le_value(struct uvc_control_mapping *mapping,
__u8 query, const __u8 *data)
{
int bits = mapping->size;
int offset = mapping->offset;
__s32 value = 0;
__u8 mask;
data += offset / 8;
offset &= 7;
mask = ((1LL << bits) - 1) << offset;
for (; bits > 0; data++) {
__u8 byte = *data & mask;
value |= offset > 0 ? (byte >> offset) : (byte << (-offset));
bits -= 8 - (offset > 0 ? offset : 0);
offset -= 8;
mask = (1 << bits) - 1;
}
if (mapping->data_type == UVC_CTRL_DATA_TYPE_SIGNED)
value |= -(value & (1 << (mapping->size - 1)));
return value;
}
static void uvc_set_le_value(struct uvc_control_mapping *mapping,
__s32 value, __u8 *data)
{
int bits = mapping->size;
int offset = mapping->offset;
__u8 mask;
if (mapping->v4l2_type == V4L2_CTRL_TYPE_BUTTON)
value = -1;
data += offset / 8;
offset &= 7;
for (; bits > 0; data++) {
mask = ((1LL << bits) - 1) << offset;
*data = (*data & ~mask) | ((value << offset) & mask);
value >>= offset ? offset : 8;
bits -= 8 - offset;
offset = 0;
}
}
static int uvc_entity_match_guid(const struct uvc_entity *entity,
const __u8 guid[16])
{
switch (UVC_ENTITY_TYPE(entity)) {
case UVC_ITT_CAMERA:
return memcmp(uvc_camera_guid, guid, 16) == 0;
case UVC_ITT_MEDIA_TRANSPORT_INPUT:
return memcmp(uvc_media_transport_input_guid, guid, 16) == 0;
case UVC_VC_PROCESSING_UNIT:
return memcmp(uvc_processing_guid, guid, 16) == 0;
case UVC_VC_EXTENSION_UNIT:
return memcmp(entity->extension.guidExtensionCode,
guid, 16) == 0;
default:
return 0;
}
}
static void __uvc_find_control(struct uvc_entity *entity, __u32 v4l2_id,
struct uvc_control_mapping **mapping, struct uvc_control **control,
int next)
{
struct uvc_control *ctrl;
struct uvc_control_mapping *map;
unsigned int i;
if (entity == NULL)
return;
for (i = 0; i < entity->ncontrols; ++i) {
ctrl = &entity->controls[i];
if (!ctrl->initialized)
continue;
list_for_each_entry(map, &ctrl->info.mappings, list) {
if ((map->id == v4l2_id) && !next) {
*control = ctrl;
*mapping = map;
return;
}
if ((*mapping == NULL || (*mapping)->id > map->id) &&
(map->id > v4l2_id) && next) {
*control = ctrl;
*mapping = map;
}
}
}
}
static struct uvc_control *uvc_find_control(struct uvc_video_chain *chain,
__u32 v4l2_id, struct uvc_control_mapping **mapping)
{
struct uvc_control *ctrl = NULL;
struct uvc_entity *entity;
int next = v4l2_id & V4L2_CTRL_FLAG_NEXT_CTRL;
*mapping = NULL;
v4l2_id &= V4L2_CTRL_ID_MASK;
list_for_each_entry(entity, &chain->entities, chain) {
__uvc_find_control(entity, v4l2_id, mapping, &ctrl, next);
if (ctrl && !next)
return ctrl;
}
if (ctrl == NULL && !next)
uvc_trace(UVC_TRACE_CONTROL, "Control 0x%08x not found.\n",
v4l2_id);
return ctrl;
}
static int uvc_ctrl_populate_cache(struct uvc_video_chain *chain,
struct uvc_control *ctrl)
{
int ret;
if (ctrl->info.flags & UVC_CTRL_FLAG_GET_DEF) {
ret = uvc_query_ctrl(chain->dev, UVC_GET_DEF, ctrl->entity->id,
chain->dev->intfnum, ctrl->info.selector,
uvc_ctrl_data(ctrl, UVC_CTRL_DATA_DEF),
ctrl->info.size);
if (ret < 0)
return ret;
}
if (ctrl->info.flags & UVC_CTRL_FLAG_GET_MIN) {
ret = uvc_query_ctrl(chain->dev, UVC_GET_MIN, ctrl->entity->id,
chain->dev->intfnum, ctrl->info.selector,
uvc_ctrl_data(ctrl, UVC_CTRL_DATA_MIN),
ctrl->info.size);
if (ret < 0)
return ret;
}
if (ctrl->info.flags & UVC_CTRL_FLAG_GET_MAX) {
ret = uvc_query_ctrl(chain->dev, UVC_GET_MAX, ctrl->entity->id,
chain->dev->intfnum, ctrl->info.selector,
uvc_ctrl_data(ctrl, UVC_CTRL_DATA_MAX),
ctrl->info.size);
if (ret < 0)
return ret;
}
if (ctrl->info.flags & UVC_CTRL_FLAG_GET_RES) {
ret = uvc_query_ctrl(chain->dev, UVC_GET_RES, ctrl->entity->id,
chain->dev->intfnum, ctrl->info.selector,
uvc_ctrl_data(ctrl, UVC_CTRL_DATA_RES),
ctrl->info.size);
if (ret < 0)
return ret;
}
ctrl->cached = 1;
return 0;
}
int uvc_query_v4l2_ctrl(struct uvc_video_chain *chain,
struct v4l2_queryctrl *v4l2_ctrl)
{
struct uvc_control *ctrl;
struct uvc_control_mapping *mapping;
struct uvc_menu_info *menu;
unsigned int i;
int ret;
ret = mutex_lock_interruptible(&chain->ctrl_mutex);
if (ret < 0)
return -ERESTARTSYS;
ctrl = uvc_find_control(chain, v4l2_ctrl->id, &mapping);
if (ctrl == NULL) {
ret = -EINVAL;
goto done;
}
memset(v4l2_ctrl, 0, sizeof *v4l2_ctrl);
v4l2_ctrl->id = mapping->id;
v4l2_ctrl->type = mapping->v4l2_type;
strlcpy(v4l2_ctrl->name, mapping->name, sizeof v4l2_ctrl->name);
v4l2_ctrl->flags = 0;
if (!(ctrl->info.flags & UVC_CTRL_FLAG_GET_CUR))
v4l2_ctrl->flags |= V4L2_CTRL_FLAG_WRITE_ONLY;
if (!(ctrl->info.flags & UVC_CTRL_FLAG_SET_CUR))
v4l2_ctrl->flags |= V4L2_CTRL_FLAG_READ_ONLY;
if (!ctrl->cached) {
ret = uvc_ctrl_populate_cache(chain, ctrl);
if (ret < 0)
goto done;
}
if (ctrl->info.flags & UVC_CTRL_FLAG_GET_DEF) {
v4l2_ctrl->default_value = mapping->get(mapping, UVC_GET_DEF,
uvc_ctrl_data(ctrl, UVC_CTRL_DATA_DEF));
}
switch (mapping->v4l2_type) {
case V4L2_CTRL_TYPE_MENU:
v4l2_ctrl->minimum = 0;
v4l2_ctrl->maximum = mapping->menu_count - 1;
v4l2_ctrl->step = 1;
menu = mapping->menu_info;
for (i = 0; i < mapping->menu_count; ++i, ++menu) {
if (menu->value == v4l2_ctrl->default_value) {
v4l2_ctrl->default_value = i;
break;
}
}
goto done;
case V4L2_CTRL_TYPE_BOOLEAN:
v4l2_ctrl->minimum = 0;
v4l2_ctrl->maximum = 1;
v4l2_ctrl->step = 1;
goto done;
case V4L2_CTRL_TYPE_BUTTON:
v4l2_ctrl->minimum = 0;
v4l2_ctrl->maximum = 0;
v4l2_ctrl->step = 0;
goto done;
default:
break;
}
if (ctrl->info.flags & UVC_CTRL_FLAG_GET_MIN)
v4l2_ctrl->minimum = mapping->get(mapping, UVC_GET_MIN,
uvc_ctrl_data(ctrl, UVC_CTRL_DATA_MIN));
if (ctrl->info.flags & UVC_CTRL_FLAG_GET_MAX)
v4l2_ctrl->maximum = mapping->get(mapping, UVC_GET_MAX,
uvc_ctrl_data(ctrl, UVC_CTRL_DATA_MAX));
if (ctrl->info.flags & UVC_CTRL_FLAG_GET_RES)
v4l2_ctrl->step = mapping->get(mapping, UVC_GET_RES,
uvc_ctrl_data(ctrl, UVC_CTRL_DATA_RES));
done:
mutex_unlock(&chain->ctrl_mutex);
return ret;
}
int uvc_query_v4l2_menu(struct uvc_video_chain *chain,
struct v4l2_querymenu *query_menu)
{
struct uvc_menu_info *menu_info;
struct uvc_control_mapping *mapping;
struct uvc_control *ctrl;
u32 index = query_menu->index;
u32 id = query_menu->id;
int ret;
memset(query_menu, 0, sizeof(*query_menu));
query_menu->id = id;
query_menu->index = index;
ret = mutex_lock_interruptible(&chain->ctrl_mutex);
if (ret < 0)
return -ERESTARTSYS;
ctrl = uvc_find_control(chain, query_menu->id, &mapping);
if (ctrl == NULL || mapping->v4l2_type != V4L2_CTRL_TYPE_MENU) {
ret = -EINVAL;
goto done;
}
if (query_menu->index >= mapping->menu_count) {
ret = -EINVAL;
goto done;
}
menu_info = &mapping->menu_info[query_menu->index];
if (mapping->data_type == UVC_CTRL_DATA_TYPE_BITMASK &&
(ctrl->info.flags & UVC_CTRL_FLAG_GET_RES)) {
s32 bitmap;
if (!ctrl->cached) {
ret = uvc_ctrl_populate_cache(chain, ctrl);
if (ret < 0)
goto done;
}
bitmap = mapping->get(mapping, UVC_GET_RES,
uvc_ctrl_data(ctrl, UVC_CTRL_DATA_RES));
if (!(bitmap & menu_info->value)) {
ret = -EINVAL;
goto done;
}
}
strlcpy(query_menu->name, menu_info->name, sizeof query_menu->name);
done:
mutex_unlock(&chain->ctrl_mutex);
return ret;
}
int uvc_ctrl_begin(struct uvc_video_chain *chain)
{
return mutex_lock_interruptible(&chain->ctrl_mutex) ? -ERESTARTSYS : 0;
}
static int uvc_ctrl_commit_entity(struct uvc_device *dev,
struct uvc_entity *entity, int rollback)
{
struct uvc_control *ctrl;
unsigned int i;
int ret;
if (entity == NULL)
return 0;
for (i = 0; i < entity->ncontrols; ++i) {
ctrl = &entity->controls[i];
if (!ctrl->initialized)
continue;
if (ctrl->info.flags & UVC_CTRL_FLAG_AUTO_UPDATE)
ctrl->loaded = 0;
if (!ctrl->dirty)
continue;
if (!rollback)
ret = uvc_query_ctrl(dev, UVC_SET_CUR, ctrl->entity->id,
dev->intfnum, ctrl->info.selector,
uvc_ctrl_data(ctrl, UVC_CTRL_DATA_CURRENT),
ctrl->info.size);
else
ret = 0;
if (rollback || ret < 0)
memcpy(uvc_ctrl_data(ctrl, UVC_CTRL_DATA_CURRENT),
uvc_ctrl_data(ctrl, UVC_CTRL_DATA_BACKUP),
ctrl->info.size);
ctrl->dirty = 0;
if (ret < 0)
return ret;
}
return 0;
}
int __uvc_ctrl_commit(struct uvc_video_chain *chain, int rollback)
{
struct uvc_entity *entity;
int ret = 0;
list_for_each_entry(entity, &chain->entities, chain) {
ret = uvc_ctrl_commit_entity(chain->dev, entity, rollback);
if (ret < 0)
goto done;
}
done:
mutex_unlock(&chain->ctrl_mutex);
return ret;
}
int uvc_ctrl_get(struct uvc_video_chain *chain,
struct v4l2_ext_control *xctrl)
{
struct uvc_control *ctrl;
struct uvc_control_mapping *mapping;
struct uvc_menu_info *menu;
unsigned int i;
int ret;
ctrl = uvc_find_control(chain, xctrl->id, &mapping);
if (ctrl == NULL || (ctrl->info.flags & UVC_CTRL_FLAG_GET_CUR) == 0)
return -EINVAL;
if (!ctrl->loaded) {
ret = uvc_query_ctrl(chain->dev, UVC_GET_CUR, ctrl->entity->id,
chain->dev->intfnum, ctrl->info.selector,
uvc_ctrl_data(ctrl, UVC_CTRL_DATA_CURRENT),
ctrl->info.size);
if (ret < 0)
return ret;
ctrl->loaded = 1;
}
xctrl->value = mapping->get(mapping, UVC_GET_CUR,
uvc_ctrl_data(ctrl, UVC_CTRL_DATA_CURRENT));
if (mapping->v4l2_type == V4L2_CTRL_TYPE_MENU) {
menu = mapping->menu_info;
for (i = 0; i < mapping->menu_count; ++i, ++menu) {
if (menu->value == xctrl->value) {
xctrl->value = i;
break;
}
}
}
return 0;
}
int uvc_ctrl_set(struct uvc_video_chain *chain,
struct v4l2_ext_control *xctrl)
{
struct uvc_control *ctrl;
struct uvc_control_mapping *mapping;
s32 value;
u32 step;
s32 min;
s32 max;
int ret;
ctrl = uvc_find_control(chain, xctrl->id, &mapping);
if (ctrl == NULL || (ctrl->info.flags & UVC_CTRL_FLAG_SET_CUR) == 0)
return -EINVAL;
switch (mapping->v4l2_type) {
case V4L2_CTRL_TYPE_INTEGER:
if (!ctrl->cached) {
ret = uvc_ctrl_populate_cache(chain, ctrl);
if (ret < 0)
return ret;
}
min = mapping->get(mapping, UVC_GET_MIN,
uvc_ctrl_data(ctrl, UVC_CTRL_DATA_MIN));
max = mapping->get(mapping, UVC_GET_MAX,
uvc_ctrl_data(ctrl, UVC_CTRL_DATA_MAX));
step = mapping->get(mapping, UVC_GET_RES,
uvc_ctrl_data(ctrl, UVC_CTRL_DATA_RES));
if (step == 0)
step = 1;
xctrl->value = min + (xctrl->value - min + step/2) / step * step;
xctrl->value = clamp(xctrl->value, min, max);
value = xctrl->value;
break;
case V4L2_CTRL_TYPE_BOOLEAN:
xctrl->value = clamp(xctrl->value, 0, 1);
value = xctrl->value;
break;
case V4L2_CTRL_TYPE_MENU:
if (xctrl->value < 0 || xctrl->value >= mapping->menu_count)
return -ERANGE;
value = mapping->menu_info[xctrl->value].value;
if (mapping->data_type == UVC_CTRL_DATA_TYPE_BITMASK &&
(ctrl->info.flags & UVC_CTRL_FLAG_GET_RES)) {
if (!ctrl->cached) {
ret = uvc_ctrl_populate_cache(chain, ctrl);
if (ret < 0)
return ret;
}
step = mapping->get(mapping, UVC_GET_RES,
uvc_ctrl_data(ctrl, UVC_CTRL_DATA_RES));
if (!(step & value))
return -ERANGE;
}
break;
default:
value = xctrl->value;
break;
}
if (!ctrl->loaded && (ctrl->info.size * 8) != mapping->size) {
if ((ctrl->info.flags & UVC_CTRL_FLAG_GET_CUR) == 0) {
memset(uvc_ctrl_data(ctrl, UVC_CTRL_DATA_CURRENT),
0, ctrl->info.size);
} else {
ret = uvc_query_ctrl(chain->dev, UVC_GET_CUR,
ctrl->entity->id, chain->dev->intfnum,
ctrl->info.selector,
uvc_ctrl_data(ctrl, UVC_CTRL_DATA_CURRENT),
ctrl->info.size);
if (ret < 0)
return ret;
}
ctrl->loaded = 1;
}
if (!ctrl->dirty) {
memcpy(uvc_ctrl_data(ctrl, UVC_CTRL_DATA_BACKUP),
uvc_ctrl_data(ctrl, UVC_CTRL_DATA_CURRENT),
ctrl->info.size);
}
mapping->set(mapping, value,
uvc_ctrl_data(ctrl, UVC_CTRL_DATA_CURRENT));
ctrl->dirty = 1;
ctrl->modified = 1;
return 0;
}
static void uvc_ctrl_fixup_xu_info(struct uvc_device *dev,
const struct uvc_control *ctrl, struct uvc_control_info *info)
{
struct uvc_ctrl_fixup {
struct usb_device_id id;
u8 entity;
u8 selector;
u8 flags;
};
static const struct uvc_ctrl_fixup fixups[] = {
{ { USB_DEVICE(0x046d, 0x08c2) }, 9, 1,
UVC_CTRL_FLAG_GET_MIN | UVC_CTRL_FLAG_GET_MAX |
UVC_CTRL_FLAG_GET_DEF | UVC_CTRL_FLAG_SET_CUR |
UVC_CTRL_FLAG_AUTO_UPDATE },
{ { USB_DEVICE(0x046d, 0x08cc) }, 9, 1,
UVC_CTRL_FLAG_GET_MIN | UVC_CTRL_FLAG_GET_MAX |
UVC_CTRL_FLAG_GET_DEF | UVC_CTRL_FLAG_SET_CUR |
UVC_CTRL_FLAG_AUTO_UPDATE },
{ { USB_DEVICE(0x046d, 0x0994) }, 9, 1,
UVC_CTRL_FLAG_GET_MIN | UVC_CTRL_FLAG_GET_MAX |
UVC_CTRL_FLAG_GET_DEF | UVC_CTRL_FLAG_SET_CUR |
UVC_CTRL_FLAG_AUTO_UPDATE },
};
unsigned int i;
for (i = 0; i < ARRAY_SIZE(fixups); ++i) {
if (!usb_match_one_id(dev->intf, &fixups[i].id))
continue;
if (fixups[i].entity == ctrl->entity->id &&
fixups[i].selector == info->selector) {
info->flags = fixups[i].flags;
return;
}
}
}
static int uvc_ctrl_fill_xu_info(struct uvc_device *dev,
const struct uvc_control *ctrl, struct uvc_control_info *info)
{
u8 *data;
int ret;
data = kmalloc(2, GFP_KERNEL);
if (data == NULL)
return -ENOMEM;
memcpy(info->entity, ctrl->entity->extension.guidExtensionCode,
sizeof(info->entity));
info->index = ctrl->index;
info->selector = ctrl->index + 1;
ret = uvc_query_ctrl(dev, UVC_GET_LEN, ctrl->entity->id, dev->intfnum,
info->selector, data, 2);
if (ret < 0) {
uvc_trace(UVC_TRACE_CONTROL,
"GET_LEN failed on control %pUl/%u (%d).\n",
info->entity, info->selector, ret);
goto done;
}
info->size = le16_to_cpup((__le16 *)data);
ret = uvc_query_ctrl(dev, UVC_GET_INFO, ctrl->entity->id, dev->intfnum,
info->selector, data, 1);
if (ret < 0) {
uvc_trace(UVC_TRACE_CONTROL,
"GET_INFO failed on control %pUl/%u (%d).\n",
info->entity, info->selector, ret);
goto done;
}
info->flags = UVC_CTRL_FLAG_GET_MIN | UVC_CTRL_FLAG_GET_MAX
| UVC_CTRL_FLAG_GET_RES | UVC_CTRL_FLAG_GET_DEF
| (data[0] & UVC_CONTROL_CAP_GET ?
UVC_CTRL_FLAG_GET_CUR : 0)
| (data[0] & UVC_CONTROL_CAP_SET ?
UVC_CTRL_FLAG_SET_CUR : 0)
| (data[0] & UVC_CONTROL_CAP_AUTOUPDATE ?
UVC_CTRL_FLAG_AUTO_UPDATE : 0);
uvc_ctrl_fixup_xu_info(dev, ctrl, info);
uvc_trace(UVC_TRACE_CONTROL, "XU control %pUl/%u queried: len %u, "
"flags { get %u set %u auto %u }.\n",
info->entity, info->selector, info->size,
(info->flags & UVC_CTRL_FLAG_GET_CUR) ? 1 : 0,
(info->flags & UVC_CTRL_FLAG_SET_CUR) ? 1 : 0,
(info->flags & UVC_CTRL_FLAG_AUTO_UPDATE) ? 1 : 0);
done:
kfree(data);
return ret;
}
static int uvc_ctrl_init_xu_ctrl(struct uvc_device *dev,
struct uvc_control *ctrl)
{
struct uvc_control_info info;
int ret;
if (ctrl->initialized)
return 0;
ret = uvc_ctrl_fill_xu_info(dev, ctrl, &info);
if (ret < 0)
return ret;
ret = uvc_ctrl_add_info(dev, ctrl, &info);
if (ret < 0)
uvc_trace(UVC_TRACE_CONTROL, "Failed to initialize control "
"%pUl/%u on device %s entity %u\n", info.entity,
info.selector, dev->udev->devpath, ctrl->entity->id);
return ret;
}
int uvc_xu_ctrl_query(struct uvc_video_chain *chain,
struct uvc_xu_control_query *xqry)
{
struct uvc_entity *entity;
struct uvc_control *ctrl;
unsigned int i, found = 0;
__u32 reqflags;
__u16 size;
__u8 *data = NULL;
int ret;
list_for_each_entry(entity, &chain->entities, chain) {
if (UVC_ENTITY_TYPE(entity) == UVC_VC_EXTENSION_UNIT &&
entity->id == xqry->unit)
break;
}
if (entity->id != xqry->unit) {
uvc_trace(UVC_TRACE_CONTROL, "Extension unit %u not found.\n",
xqry->unit);
return -ENOENT;
}
for (i = 0; i < entity->ncontrols; ++i) {
ctrl = &entity->controls[i];
if (ctrl->index == xqry->selector - 1) {
found = 1;
break;
}
}
if (!found) {
uvc_trace(UVC_TRACE_CONTROL, "Control %pUl/%u not found.\n",
entity->extension.guidExtensionCode, xqry->selector);
return -ENOENT;
}
if (mutex_lock_interruptible(&chain->ctrl_mutex))
return -ERESTARTSYS;
ret = uvc_ctrl_init_xu_ctrl(chain->dev, ctrl);
if (ret < 0) {
ret = -ENOENT;
goto done;
}
reqflags = 0;
size = ctrl->info.size;
switch (xqry->query) {
case UVC_GET_CUR:
reqflags = UVC_CTRL_FLAG_GET_CUR;
break;
case UVC_GET_MIN:
reqflags = UVC_CTRL_FLAG_GET_MIN;
break;
case UVC_GET_MAX:
reqflags = UVC_CTRL_FLAG_GET_MAX;
break;
case UVC_GET_DEF:
reqflags = UVC_CTRL_FLAG_GET_DEF;
break;
case UVC_GET_RES:
reqflags = UVC_CTRL_FLAG_GET_RES;
break;
case UVC_SET_CUR:
reqflags = UVC_CTRL_FLAG_SET_CUR;
break;
case UVC_GET_LEN:
size = 2;
break;
case UVC_GET_INFO:
size = 1;
break;
default:
ret = -EINVAL;
goto done;
}
if (size != xqry->size) {
ret = -ENOBUFS;
goto done;
}
if (reqflags && !(ctrl->info.flags & reqflags)) {
ret = -EBADRQC;
goto done;
}
data = kmalloc(size, GFP_KERNEL);
if (data == NULL) {
ret = -ENOMEM;
goto done;
}
if (xqry->query == UVC_SET_CUR &&
copy_from_user(data, xqry->data, size)) {
ret = -EFAULT;
goto done;
}
ret = uvc_query_ctrl(chain->dev, xqry->query, xqry->unit,
chain->dev->intfnum, xqry->selector, data, size);
if (ret < 0)
goto done;
if (xqry->query != UVC_SET_CUR &&
copy_to_user(xqry->data, data, size))
ret = -EFAULT;
done:
kfree(data);
mutex_unlock(&chain->ctrl_mutex);
return ret;
}
int uvc_ctrl_resume_device(struct uvc_device *dev)
{
struct uvc_control *ctrl;
struct uvc_entity *entity;
unsigned int i;
int ret;
list_for_each_entry(entity, &dev->entities, list) {
for (i = 0; i < entity->ncontrols; ++i) {
ctrl = &entity->controls[i];
if (!ctrl->initialized || !ctrl->modified ||
(ctrl->info.flags & UVC_CTRL_FLAG_RESTORE) == 0)
continue;
printk(KERN_INFO "restoring control %pUl/%u/%u\n",
ctrl->info.entity, ctrl->info.index,
ctrl->info.selector);
ctrl->dirty = 1;
}
ret = uvc_ctrl_commit_entity(dev, entity, 0);
if (ret < 0)
return ret;
}
return 0;
}
static int uvc_ctrl_add_info(struct uvc_device *dev, struct uvc_control *ctrl,
const struct uvc_control_info *info)
{
int ret = 0;
memcpy(&ctrl->info, info, sizeof(*info));
INIT_LIST_HEAD(&ctrl->info.mappings);
ctrl->uvc_data = kzalloc(ctrl->info.size * UVC_CTRL_DATA_LAST + 1,
GFP_KERNEL);
if (ctrl->uvc_data == NULL) {
ret = -ENOMEM;
goto done;
}
ctrl->initialized = 1;
uvc_trace(UVC_TRACE_CONTROL, "Added control %pUl/%u to device %s "
"entity %u\n", ctrl->info.entity, ctrl->info.selector,
dev->udev->devpath, ctrl->entity->id);
done:
if (ret < 0)
kfree(ctrl->uvc_data);
return ret;
}
static int __uvc_ctrl_add_mapping(struct uvc_device *dev,
struct uvc_control *ctrl, const struct uvc_control_mapping *mapping)
{
struct uvc_control_mapping *map;
unsigned int size;
map = kmemdup(mapping, sizeof(*mapping), GFP_KERNEL);
if (map == NULL)
return -ENOMEM;
size = sizeof(*mapping->menu_info) * mapping->menu_count;
map->menu_info = kmemdup(mapping->menu_info, size, GFP_KERNEL);
if (map->menu_info == NULL) {
kfree(map);
return -ENOMEM;
}
if (map->get == NULL)
map->get = uvc_get_le_value;
if (map->set == NULL)
map->set = uvc_set_le_value;
map->ctrl = &ctrl->info;
list_add_tail(&map->list, &ctrl->info.mappings);
uvc_trace(UVC_TRACE_CONTROL,
"Adding mapping '%s' to control %pUl/%u.\n",
map->name, ctrl->info.entity, ctrl->info.selector);
return 0;
}
int uvc_ctrl_add_mapping(struct uvc_video_chain *chain,
const struct uvc_control_mapping *mapping)
{
struct uvc_device *dev = chain->dev;
struct uvc_control_mapping *map;
struct uvc_entity *entity;
struct uvc_control *ctrl;
int found = 0;
int ret;
if (mapping->id & ~V4L2_CTRL_ID_MASK) {
uvc_trace(UVC_TRACE_CONTROL, "Can't add mapping '%s', control "
"id 0x%08x is invalid.\n", mapping->name,
mapping->id);
return -EINVAL;
}
list_for_each_entry(entity, &chain->entities, chain) {
unsigned int i;
if (UVC_ENTITY_TYPE(entity) != UVC_VC_EXTENSION_UNIT ||
!uvc_entity_match_guid(entity, mapping->entity))
continue;
for (i = 0; i < entity->ncontrols; ++i) {
ctrl = &entity->controls[i];
if (ctrl->index == mapping->selector - 1) {
found = 1;
break;
}
}
if (found)
break;
}
if (!found)
return -ENOENT;
if (mutex_lock_interruptible(&chain->ctrl_mutex))
return -ERESTARTSYS;
ret = uvc_ctrl_init_xu_ctrl(dev, ctrl);
if (ret < 0) {
ret = -ENOENT;
goto done;
}
list_for_each_entry(map, &ctrl->info.mappings, list) {
if (mapping->id == map->id) {
uvc_trace(UVC_TRACE_CONTROL, "Can't add mapping '%s', "
"control id 0x%08x already exists.\n",
mapping->name, mapping->id);
ret = -EEXIST;
goto done;
}
}
if (atomic_inc_return(&dev->nmappings) > UVC_MAX_CONTROL_MAPPINGS) {
atomic_dec(&dev->nmappings);
uvc_trace(UVC_TRACE_CONTROL, "Can't add mapping '%s', maximum "
"mappings count (%u) exceeded.\n", mapping->name,
UVC_MAX_CONTROL_MAPPINGS);
ret = -ENOMEM;
goto done;
}
ret = __uvc_ctrl_add_mapping(dev, ctrl, mapping);
if (ret < 0)
atomic_dec(&dev->nmappings);
done:
mutex_unlock(&chain->ctrl_mutex);
return ret;
}
static void uvc_ctrl_prune_entity(struct uvc_device *dev,
struct uvc_entity *entity)
{
struct uvc_ctrl_blacklist {
struct usb_device_id id;
u8 index;
};
static const struct uvc_ctrl_blacklist processing_blacklist[] = {
{ { USB_DEVICE(0x13d3, 0x509b) }, 9 },
{ { USB_DEVICE(0x1c4f, 0x3000) }, 6 },
{ { USB_DEVICE(0x5986, 0x0241) }, 2 },
};
static const struct uvc_ctrl_blacklist camera_blacklist[] = {
{ { USB_DEVICE(0x06f8, 0x3005) }, 9 },
};
const struct uvc_ctrl_blacklist *blacklist;
unsigned int size;
unsigned int count;
unsigned int i;
u8 *controls;
switch (UVC_ENTITY_TYPE(entity)) {
case UVC_VC_PROCESSING_UNIT:
blacklist = processing_blacklist;
count = ARRAY_SIZE(processing_blacklist);
controls = entity->processing.bmControls;
size = entity->processing.bControlSize;
break;
case UVC_ITT_CAMERA:
blacklist = camera_blacklist;
count = ARRAY_SIZE(camera_blacklist);
controls = entity->camera.bmControls;
size = entity->camera.bControlSize;
break;
default:
return;
}
for (i = 0; i < count; ++i) {
if (!usb_match_one_id(dev->intf, &blacklist[i].id))
continue;
if (blacklist[i].index >= 8 * size ||
!uvc_test_bit(controls, blacklist[i].index))
continue;
uvc_trace(UVC_TRACE_CONTROL, "%u/%u control is black listed, "
"removing it.\n", entity->id, blacklist[i].index);
uvc_clear_bit(controls, blacklist[i].index);
}
}
static void uvc_ctrl_init_ctrl(struct uvc_device *dev, struct uvc_control *ctrl)
{
const struct uvc_control_info *info = uvc_ctrls;
const struct uvc_control_info *iend = info + ARRAY_SIZE(uvc_ctrls);
const struct uvc_control_mapping *mapping = uvc_ctrl_mappings;
const struct uvc_control_mapping *mend =
mapping + ARRAY_SIZE(uvc_ctrl_mappings);
if (UVC_ENTITY_TYPE(ctrl->entity) == UVC_VC_EXTENSION_UNIT)
return;
for (; info < iend; ++info) {
if (uvc_entity_match_guid(ctrl->entity, info->entity) &&
ctrl->index == info->index) {
uvc_ctrl_add_info(dev, ctrl, info);
break;
}
}
if (!ctrl->initialized)
return;
for (; mapping < mend; ++mapping) {
if (uvc_entity_match_guid(ctrl->entity, mapping->entity) &&
ctrl->info.selector == mapping->selector)
__uvc_ctrl_add_mapping(dev, ctrl, mapping);
}
}
int uvc_ctrl_init_device(struct uvc_device *dev)
{
struct uvc_entity *entity;
unsigned int i;
list_for_each_entry(entity, &dev->entities, list) {
struct uvc_control *ctrl;
unsigned int bControlSize = 0, ncontrols = 0;
__u8 *bmControls = NULL;
if (UVC_ENTITY_TYPE(entity) == UVC_VC_EXTENSION_UNIT) {
bmControls = entity->extension.bmControls;
bControlSize = entity->extension.bControlSize;
} else if (UVC_ENTITY_TYPE(entity) == UVC_VC_PROCESSING_UNIT) {
bmControls = entity->processing.bmControls;
bControlSize = entity->processing.bControlSize;
} else if (UVC_ENTITY_TYPE(entity) == UVC_ITT_CAMERA) {
bmControls = entity->camera.bmControls;
bControlSize = entity->camera.bControlSize;
}
uvc_ctrl_prune_entity(dev, entity);
for (i = 0; i < bControlSize; ++i)
ncontrols += hweight8(bmControls[i]);
if (ncontrols == 0)
continue;
entity->controls = kzalloc(ncontrols * sizeof(*ctrl),
GFP_KERNEL);
if (entity->controls == NULL)
return -ENOMEM;
entity->ncontrols = ncontrols;
ctrl = entity->controls;
for (i = 0; i < bControlSize * 8; ++i) {
if (uvc_test_bit(bmControls, i) == 0)
continue;
ctrl->entity = entity;
ctrl->index = i;
uvc_ctrl_init_ctrl(dev, ctrl);
ctrl++;
}
}
return 0;
}
static void uvc_ctrl_cleanup_mappings(struct uvc_device *dev,
struct uvc_control *ctrl)
{
struct uvc_control_mapping *mapping, *nm;
list_for_each_entry_safe(mapping, nm, &ctrl->info.mappings, list) {
list_del(&mapping->list);
kfree(mapping->menu_info);
kfree(mapping);
}
}
void uvc_ctrl_cleanup_device(struct uvc_device *dev)
{
struct uvc_entity *entity;
unsigned int i;
list_for_each_entry(entity, &dev->entities, list) {
for (i = 0; i < entity->ncontrols; ++i) {
struct uvc_control *ctrl = &entity->controls[i];
if (!ctrl->initialized)
continue;
uvc_ctrl_cleanup_mappings(dev, ctrl);
kfree(ctrl->uvc_data);
}
kfree(entity->controls);
}
}
