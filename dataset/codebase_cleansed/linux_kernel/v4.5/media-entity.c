static inline const char *gobj_type(enum media_gobj_type type)
{
switch (type) {
case MEDIA_GRAPH_ENTITY:
return "entity";
case MEDIA_GRAPH_PAD:
return "pad";
case MEDIA_GRAPH_LINK:
return "link";
case MEDIA_GRAPH_INTF_DEVNODE:
return "intf-devnode";
default:
return "unknown";
}
}
static inline const char *intf_type(struct media_interface *intf)
{
switch (intf->type) {
case MEDIA_INTF_T_DVB_FE:
return "frontend";
case MEDIA_INTF_T_DVB_DEMUX:
return "demux";
case MEDIA_INTF_T_DVB_DVR:
return "DVR";
case MEDIA_INTF_T_DVB_CA:
return "CA";
case MEDIA_INTF_T_DVB_NET:
return "dvbnet";
case MEDIA_INTF_T_V4L_VIDEO:
return "video";
case MEDIA_INTF_T_V4L_VBI:
return "vbi";
case MEDIA_INTF_T_V4L_RADIO:
return "radio";
case MEDIA_INTF_T_V4L_SUBDEV:
return "v4l2-subdev";
case MEDIA_INTF_T_V4L_SWRADIO:
return "swradio";
default:
return "unknown-intf";
}
}
__must_check int __media_entity_enum_init(struct media_entity_enum *ent_enum,
int idx_max)
{
ent_enum->bmap = kcalloc(DIV_ROUND_UP(idx_max, BITS_PER_LONG),
sizeof(long), GFP_KERNEL);
if (!ent_enum->bmap)
return -ENOMEM;
bitmap_zero(ent_enum->bmap, idx_max);
ent_enum->idx_max = idx_max;
return 0;
}
void media_entity_enum_cleanup(struct media_entity_enum *ent_enum)
{
kfree(ent_enum->bmap);
}
static void dev_dbg_obj(const char *event_name, struct media_gobj *gobj)
{
#if defined(DEBUG) || defined (CONFIG_DYNAMIC_DEBUG)
switch (media_type(gobj)) {
case MEDIA_GRAPH_ENTITY:
dev_dbg(gobj->mdev->dev,
"%s id %u: entity '%s'\n",
event_name, media_id(gobj),
gobj_to_entity(gobj)->name);
break;
case MEDIA_GRAPH_LINK:
{
struct media_link *link = gobj_to_link(gobj);
dev_dbg(gobj->mdev->dev,
"%s id %u: %s link id %u ==> id %u\n",
event_name, media_id(gobj),
media_type(link->gobj0) == MEDIA_GRAPH_PAD ?
"data" : "interface",
media_id(link->gobj0),
media_id(link->gobj1));
break;
}
case MEDIA_GRAPH_PAD:
{
struct media_pad *pad = gobj_to_pad(gobj);
dev_dbg(gobj->mdev->dev,
"%s id %u: %s%spad '%s':%d\n",
event_name, media_id(gobj),
pad->flags & MEDIA_PAD_FL_SINK ? "sink " : "",
pad->flags & MEDIA_PAD_FL_SOURCE ? "source " : "",
pad->entity->name, pad->index);
break;
}
case MEDIA_GRAPH_INTF_DEVNODE:
{
struct media_interface *intf = gobj_to_intf(gobj);
struct media_intf_devnode *devnode = intf_to_devnode(intf);
dev_dbg(gobj->mdev->dev,
"%s id %u: intf_devnode %s - major: %d, minor: %d\n",
event_name, media_id(gobj),
intf_type(intf),
devnode->major, devnode->minor);
break;
}
}
#endif
}
void media_gobj_create(struct media_device *mdev,
enum media_gobj_type type,
struct media_gobj *gobj)
{
BUG_ON(!mdev);
gobj->mdev = mdev;
gobj->id = media_gobj_gen_id(type, ++mdev->id);
switch (type) {
case MEDIA_GRAPH_ENTITY:
list_add_tail(&gobj->list, &mdev->entities);
break;
case MEDIA_GRAPH_PAD:
list_add_tail(&gobj->list, &mdev->pads);
break;
case MEDIA_GRAPH_LINK:
list_add_tail(&gobj->list, &mdev->links);
break;
case MEDIA_GRAPH_INTF_DEVNODE:
list_add_tail(&gobj->list, &mdev->interfaces);
break;
}
mdev->topology_version++;
dev_dbg_obj(__func__, gobj);
}
void media_gobj_destroy(struct media_gobj *gobj)
{
dev_dbg_obj(__func__, gobj);
gobj->mdev->topology_version++;
list_del(&gobj->list);
}
int media_entity_pads_init(struct media_entity *entity, u16 num_pads,
struct media_pad *pads)
{
struct media_device *mdev = entity->graph_obj.mdev;
unsigned int i;
entity->num_pads = num_pads;
entity->pads = pads;
if (mdev)
spin_lock(&mdev->lock);
for (i = 0; i < num_pads; i++) {
pads[i].entity = entity;
pads[i].index = i;
if (mdev)
media_gobj_create(mdev, MEDIA_GRAPH_PAD,
&entity->pads[i].graph_obj);
}
if (mdev)
spin_unlock(&mdev->lock);
return 0;
}
static struct media_entity *
media_entity_other(struct media_entity *entity, struct media_link *link)
{
if (link->source->entity == entity)
return link->sink->entity;
else
return link->source->entity;
}
static void stack_push(struct media_entity_graph *graph,
struct media_entity *entity)
{
if (graph->top == MEDIA_ENTITY_ENUM_MAX_DEPTH - 1) {
WARN_ON(1);
return;
}
graph->top++;
graph->stack[graph->top].link = entity->links.next;
graph->stack[graph->top].entity = entity;
}
static struct media_entity *stack_pop(struct media_entity_graph *graph)
{
struct media_entity *entity;
entity = graph->stack[graph->top].entity;
graph->top--;
return entity;
}
__must_check int media_entity_graph_walk_init(
struct media_entity_graph *graph, struct media_device *mdev)
{
return media_entity_enum_init(&graph->ent_enum, mdev);
}
void media_entity_graph_walk_cleanup(struct media_entity_graph *graph)
{
media_entity_enum_cleanup(&graph->ent_enum);
}
void media_entity_graph_walk_start(struct media_entity_graph *graph,
struct media_entity *entity)
{
media_entity_enum_zero(&graph->ent_enum);
media_entity_enum_set(&graph->ent_enum, entity);
graph->top = 0;
graph->stack[graph->top].entity = NULL;
stack_push(graph, entity);
}
struct media_entity *
media_entity_graph_walk_next(struct media_entity_graph *graph)
{
if (stack_top(graph) == NULL)
return NULL;
while (link_top(graph) != &stack_top(graph)->links) {
struct media_entity *entity = stack_top(graph);
struct media_link *link;
struct media_entity *next;
link = list_entry(link_top(graph), typeof(*link), list);
if (!(link->flags & MEDIA_LNK_FL_ENABLED)) {
link_top(graph) = link_top(graph)->next;
continue;
}
next = media_entity_other(entity, link);
if (media_entity_enum_test_and_set(&graph->ent_enum, next)) {
link_top(graph) = link_top(graph)->next;
continue;
}
link_top(graph) = link_top(graph)->next;
stack_push(graph, next);
}
return stack_pop(graph);
}
__must_check int media_entity_pipeline_start(struct media_entity *entity,
struct media_pipeline *pipe)
{
struct media_device *mdev = entity->graph_obj.mdev;
struct media_entity_graph *graph = &pipe->graph;
struct media_entity *entity_err = entity;
struct media_link *link;
int ret;
mutex_lock(&mdev->graph_mutex);
if (!pipe->streaming_count++) {
ret = media_entity_graph_walk_init(&pipe->graph, mdev);
if (ret)
goto error_graph_walk_start;
}
media_entity_graph_walk_start(&pipe->graph, entity);
while ((entity = media_entity_graph_walk_next(graph))) {
DECLARE_BITMAP(active, MEDIA_ENTITY_MAX_PADS);
DECLARE_BITMAP(has_no_links, MEDIA_ENTITY_MAX_PADS);
entity->stream_count++;
if (WARN_ON(entity->pipe && entity->pipe != pipe)) {
ret = -EBUSY;
goto error;
}
entity->pipe = pipe;
if (entity->stream_count > 1)
continue;
if (!entity->ops || !entity->ops->link_validate)
continue;
bitmap_zero(active, entity->num_pads);
bitmap_fill(has_no_links, entity->num_pads);
list_for_each_entry(link, &entity->links, list) {
struct media_pad *pad = link->sink->entity == entity
? link->sink : link->source;
bitmap_clear(has_no_links, pad->index, 1);
if (!(pad->flags & MEDIA_PAD_FL_MUST_CONNECT) ||
link->flags & MEDIA_LNK_FL_ENABLED)
bitmap_set(active, pad->index, 1);
if (link->sink != pad ||
!(link->flags & MEDIA_LNK_FL_ENABLED))
continue;
ret = entity->ops->link_validate(link);
if (ret < 0 && ret != -ENOIOCTLCMD) {
dev_dbg(entity->graph_obj.mdev->dev,
"link validation failed for \"%s\":%u -> \"%s\":%u, error %d\n",
link->source->entity->name,
link->source->index,
entity->name, link->sink->index, ret);
goto error;
}
}
bitmap_or(active, active, has_no_links, entity->num_pads);
if (!bitmap_full(active, entity->num_pads)) {
ret = -EPIPE;
dev_dbg(entity->graph_obj.mdev->dev,
"\"%s\":%u must be connected by an enabled link\n",
entity->name,
(unsigned)find_first_zero_bit(
active, entity->num_pads));
goto error;
}
}
mutex_unlock(&mdev->graph_mutex);
return 0;
error:
media_entity_graph_walk_start(graph, entity_err);
while ((entity_err = media_entity_graph_walk_next(graph))) {
entity_err->stream_count--;
if (entity_err->stream_count == 0)
entity_err->pipe = NULL;
if (entity_err == entity)
break;
}
error_graph_walk_start:
if (!--pipe->streaming_count)
media_entity_graph_walk_cleanup(graph);
mutex_unlock(&mdev->graph_mutex);
return ret;
}
void media_entity_pipeline_stop(struct media_entity *entity)
{
struct media_device *mdev = entity->graph_obj.mdev;
struct media_entity_graph *graph = &entity->pipe->graph;
struct media_pipeline *pipe = entity->pipe;
mutex_lock(&mdev->graph_mutex);
WARN_ON(!pipe->streaming_count);
media_entity_graph_walk_start(graph, entity);
while ((entity = media_entity_graph_walk_next(graph))) {
entity->stream_count--;
if (entity->stream_count == 0)
entity->pipe = NULL;
}
if (!--pipe->streaming_count)
media_entity_graph_walk_cleanup(graph);
mutex_unlock(&mdev->graph_mutex);
}
struct media_entity *media_entity_get(struct media_entity *entity)
{
if (entity == NULL)
return NULL;
if (entity->graph_obj.mdev->dev &&
!try_module_get(entity->graph_obj.mdev->dev->driver->owner))
return NULL;
return entity;
}
void media_entity_put(struct media_entity *entity)
{
if (entity == NULL)
return;
if (entity->graph_obj.mdev->dev)
module_put(entity->graph_obj.mdev->dev->driver->owner);
}
static struct media_link *media_add_link(struct list_head *head)
{
struct media_link *link;
link = kzalloc(sizeof(*link), GFP_KERNEL);
if (link == NULL)
return NULL;
list_add_tail(&link->list, head);
return link;
}
static void __media_entity_remove_link(struct media_entity *entity,
struct media_link *link)
{
struct media_link *rlink, *tmp;
struct media_entity *remote;
if (link->source->entity == entity)
remote = link->sink->entity;
else
remote = link->source->entity;
list_for_each_entry_safe(rlink, tmp, &remote->links, list) {
if (rlink != link->reverse)
continue;
if (link->source->entity == entity)
remote->num_backlinks--;
list_del(&rlink->list);
media_gobj_destroy(&rlink->graph_obj);
kfree(rlink);
if (--remote->num_links == 0)
break;
}
list_del(&link->list);
media_gobj_destroy(&link->graph_obj);
kfree(link);
}
int
media_create_pad_link(struct media_entity *source, u16 source_pad,
struct media_entity *sink, u16 sink_pad, u32 flags)
{
struct media_link *link;
struct media_link *backlink;
BUG_ON(source == NULL || sink == NULL);
BUG_ON(source_pad >= source->num_pads);
BUG_ON(sink_pad >= sink->num_pads);
link = media_add_link(&source->links);
if (link == NULL)
return -ENOMEM;
link->source = &source->pads[source_pad];
link->sink = &sink->pads[sink_pad];
link->flags = flags & ~MEDIA_LNK_FL_INTERFACE_LINK;
media_gobj_create(source->graph_obj.mdev, MEDIA_GRAPH_LINK,
&link->graph_obj);
backlink = media_add_link(&sink->links);
if (backlink == NULL) {
__media_entity_remove_link(source, link);
return -ENOMEM;
}
backlink->source = &source->pads[source_pad];
backlink->sink = &sink->pads[sink_pad];
backlink->flags = flags;
backlink->is_backlink = true;
media_gobj_create(sink->graph_obj.mdev, MEDIA_GRAPH_LINK,
&backlink->graph_obj);
link->reverse = backlink;
backlink->reverse = link;
sink->num_backlinks++;
sink->num_links++;
source->num_links++;
return 0;
}
int media_create_pad_links(const struct media_device *mdev,
const u32 source_function,
struct media_entity *source,
const u16 source_pad,
const u32 sink_function,
struct media_entity *sink,
const u16 sink_pad,
u32 flags,
const bool allow_both_undefined)
{
struct media_entity *entity;
unsigned function;
int ret;
if (source && sink)
return media_create_pad_link(source, source_pad,
sink, sink_pad, flags);
if (!source && !sink) {
if (!allow_both_undefined)
return 0;
media_device_for_each_entity(source, mdev) {
if (source->function != source_function)
continue;
media_device_for_each_entity(sink, mdev) {
if (sink->function != sink_function)
continue;
ret = media_create_pad_link(source, source_pad,
sink, sink_pad,
flags);
if (ret)
return ret;
flags &= ~(MEDIA_LNK_FL_ENABLED |
MEDIA_LNK_FL_IMMUTABLE);
}
}
return 0;
}
if (source)
function = sink_function;
else
function = source_function;
media_device_for_each_entity(entity, mdev) {
if (entity->function != function)
continue;
if (source)
ret = media_create_pad_link(source, source_pad,
entity, sink_pad, flags);
else
ret = media_create_pad_link(entity, source_pad,
sink, sink_pad, flags);
if (ret)
return ret;
flags &= ~(MEDIA_LNK_FL_ENABLED | MEDIA_LNK_FL_IMMUTABLE);
}
return 0;
}
void __media_entity_remove_links(struct media_entity *entity)
{
struct media_link *link, *tmp;
list_for_each_entry_safe(link, tmp, &entity->links, list)
__media_entity_remove_link(entity, link);
entity->num_links = 0;
entity->num_backlinks = 0;
}
void media_entity_remove_links(struct media_entity *entity)
{
struct media_device *mdev = entity->graph_obj.mdev;
if (mdev == NULL)
return;
spin_lock(&mdev->lock);
__media_entity_remove_links(entity);
spin_unlock(&mdev->lock);
}
static int __media_entity_setup_link_notify(struct media_link *link, u32 flags)
{
int ret;
ret = media_entity_call(link->source->entity, link_setup,
link->source, link->sink, flags);
if (ret < 0 && ret != -ENOIOCTLCMD)
return ret;
ret = media_entity_call(link->sink->entity, link_setup,
link->sink, link->source, flags);
if (ret < 0 && ret != -ENOIOCTLCMD) {
media_entity_call(link->source->entity, link_setup,
link->source, link->sink, link->flags);
return ret;
}
link->flags = flags;
link->reverse->flags = link->flags;
return 0;
}
int __media_entity_setup_link(struct media_link *link, u32 flags)
{
const u32 mask = MEDIA_LNK_FL_ENABLED;
struct media_device *mdev;
struct media_entity *source, *sink;
int ret = -EBUSY;
if (link == NULL)
return -EINVAL;
if ((link->flags & ~mask) != (flags & ~mask))
return -EINVAL;
if (link->flags & MEDIA_LNK_FL_IMMUTABLE)
return link->flags == flags ? 0 : -EINVAL;
if (link->flags == flags)
return 0;
source = link->source->entity;
sink = link->sink->entity;
if (!(link->flags & MEDIA_LNK_FL_DYNAMIC) &&
(source->stream_count || sink->stream_count))
return -EBUSY;
mdev = source->graph_obj.mdev;
if (mdev->link_notify) {
ret = mdev->link_notify(link, flags,
MEDIA_DEV_NOTIFY_PRE_LINK_CH);
if (ret < 0)
return ret;
}
ret = __media_entity_setup_link_notify(link, flags);
if (mdev->link_notify)
mdev->link_notify(link, flags, MEDIA_DEV_NOTIFY_POST_LINK_CH);
return ret;
}
int media_entity_setup_link(struct media_link *link, u32 flags)
{
int ret;
mutex_lock(&link->graph_obj.mdev->graph_mutex);
ret = __media_entity_setup_link(link, flags);
mutex_unlock(&link->graph_obj.mdev->graph_mutex);
return ret;
}
struct media_link *
media_entity_find_link(struct media_pad *source, struct media_pad *sink)
{
struct media_link *link;
list_for_each_entry(link, &source->entity->links, list) {
if (link->source->entity == source->entity &&
link->source->index == source->index &&
link->sink->entity == sink->entity &&
link->sink->index == sink->index)
return link;
}
return NULL;
}
struct media_pad *media_entity_remote_pad(struct media_pad *pad)
{
struct media_link *link;
list_for_each_entry(link, &pad->entity->links, list) {
if (!(link->flags & MEDIA_LNK_FL_ENABLED))
continue;
if (link->source == pad)
return link->sink;
if (link->sink == pad)
return link->source;
}
return NULL;
}
static void media_interface_init(struct media_device *mdev,
struct media_interface *intf,
u32 gobj_type,
u32 intf_type, u32 flags)
{
intf->type = intf_type;
intf->flags = flags;
INIT_LIST_HEAD(&intf->links);
media_gobj_create(mdev, gobj_type, &intf->graph_obj);
}
struct media_intf_devnode *media_devnode_create(struct media_device *mdev,
u32 type, u32 flags,
u32 major, u32 minor)
{
struct media_intf_devnode *devnode;
devnode = kzalloc(sizeof(*devnode), GFP_KERNEL);
if (!devnode)
return NULL;
devnode->major = major;
devnode->minor = minor;
media_interface_init(mdev, &devnode->intf, MEDIA_GRAPH_INTF_DEVNODE,
type, flags);
return devnode;
}
void media_devnode_remove(struct media_intf_devnode *devnode)
{
media_remove_intf_links(&devnode->intf);
media_gobj_destroy(&devnode->intf.graph_obj);
kfree(devnode);
}
struct media_link *media_create_intf_link(struct media_entity *entity,
struct media_interface *intf,
u32 flags)
{
struct media_link *link;
link = media_add_link(&intf->links);
if (link == NULL)
return NULL;
link->intf = intf;
link->entity = entity;
link->flags = flags | MEDIA_LNK_FL_INTERFACE_LINK;
media_gobj_create(intf->graph_obj.mdev, MEDIA_GRAPH_LINK,
&link->graph_obj);
return link;
}
void __media_remove_intf_link(struct media_link *link)
{
list_del(&link->list);
media_gobj_destroy(&link->graph_obj);
kfree(link);
}
void media_remove_intf_link(struct media_link *link)
{
struct media_device *mdev = link->graph_obj.mdev;
if (mdev == NULL)
return;
spin_lock(&mdev->lock);
__media_remove_intf_link(link);
spin_unlock(&mdev->lock);
}
void __media_remove_intf_links(struct media_interface *intf)
{
struct media_link *link, *tmp;
list_for_each_entry_safe(link, tmp, &intf->links, list)
__media_remove_intf_link(link);
}
void media_remove_intf_links(struct media_interface *intf)
{
struct media_device *mdev = intf->graph_obj.mdev;
if (mdev == NULL)
return;
spin_lock(&mdev->lock);
__media_remove_intf_links(intf);
spin_unlock(&mdev->lock);
}
