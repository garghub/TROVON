int
media_entity_init(struct media_entity *entity, u16 num_pads,
struct media_pad *pads, u16 extra_links)
{
struct media_link *links;
unsigned int max_links = num_pads + extra_links;
unsigned int i;
links = kzalloc(max_links * sizeof(links[0]), GFP_KERNEL);
if (links == NULL)
return -ENOMEM;
entity->group_id = 0;
entity->max_links = max_links;
entity->num_links = 0;
entity->num_backlinks = 0;
entity->num_pads = num_pads;
entity->pads = pads;
entity->links = links;
for (i = 0; i < num_pads; i++) {
pads[i].entity = entity;
pads[i].index = i;
}
return 0;
}
void
media_entity_cleanup(struct media_entity *entity)
{
kfree(entity->links);
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
graph->stack[graph->top].link = 0;
graph->stack[graph->top].entity = entity;
}
static struct media_entity *stack_pop(struct media_entity_graph *graph)
{
struct media_entity *entity;
entity = graph->stack[graph->top].entity;
graph->top--;
return entity;
}
void media_entity_graph_walk_start(struct media_entity_graph *graph,
struct media_entity *entity)
{
graph->top = 0;
graph->stack[graph->top].entity = NULL;
bitmap_zero(graph->entities, MEDIA_ENTITY_ENUM_MAX_ID);
if (WARN_ON(entity->id >= MEDIA_ENTITY_ENUM_MAX_ID))
return;
__set_bit(entity->id, graph->entities);
stack_push(graph, entity);
}
struct media_entity *
media_entity_graph_walk_next(struct media_entity_graph *graph)
{
if (stack_top(graph) == NULL)
return NULL;
while (link_top(graph) < stack_top(graph)->num_links) {
struct media_entity *entity = stack_top(graph);
struct media_link *link = &entity->links[link_top(graph)];
struct media_entity *next;
if (!(link->flags & MEDIA_LNK_FL_ENABLED)) {
link_top(graph)++;
continue;
}
next = media_entity_other(entity, link);
if (WARN_ON(next->id >= MEDIA_ENTITY_ENUM_MAX_ID))
return NULL;
if (__test_and_set_bit(next->id, graph->entities)) {
link_top(graph)++;
continue;
}
link_top(graph)++;
stack_push(graph, next);
}
return stack_pop(graph);
}
__must_check int media_entity_pipeline_start(struct media_entity *entity,
struct media_pipeline *pipe)
{
struct media_device *mdev = entity->parent;
struct media_entity_graph graph;
struct media_entity *entity_err = entity;
int ret;
mutex_lock(&mdev->graph_mutex);
media_entity_graph_walk_start(&graph, entity);
while ((entity = media_entity_graph_walk_next(&graph))) {
unsigned int i;
entity->stream_count++;
WARN_ON(entity->pipe && entity->pipe != pipe);
entity->pipe = pipe;
if (entity->stream_count > 1)
continue;
if (!entity->ops || !entity->ops->link_validate)
continue;
for (i = 0; i < entity->num_links; i++) {
struct media_link *link = &entity->links[i];
if (!(link->flags & MEDIA_LNK_FL_ENABLED))
continue;
if (link->sink->entity != entity)
continue;
ret = entity->ops->link_validate(link);
if (ret < 0 && ret != -ENOIOCTLCMD)
goto error;
}
}
mutex_unlock(&mdev->graph_mutex);
return 0;
error:
media_entity_graph_walk_start(&graph, entity_err);
while ((entity_err = media_entity_graph_walk_next(&graph))) {
entity_err->stream_count--;
if (entity_err->stream_count == 0)
entity_err->pipe = NULL;
if (entity_err == entity)
break;
}
mutex_unlock(&mdev->graph_mutex);
return ret;
}
void media_entity_pipeline_stop(struct media_entity *entity)
{
struct media_device *mdev = entity->parent;
struct media_entity_graph graph;
mutex_lock(&mdev->graph_mutex);
media_entity_graph_walk_start(&graph, entity);
while ((entity = media_entity_graph_walk_next(&graph))) {
entity->stream_count--;
if (entity->stream_count == 0)
entity->pipe = NULL;
}
mutex_unlock(&mdev->graph_mutex);
}
struct media_entity *media_entity_get(struct media_entity *entity)
{
if (entity == NULL)
return NULL;
if (entity->parent->dev &&
!try_module_get(entity->parent->dev->driver->owner))
return NULL;
return entity;
}
void media_entity_put(struct media_entity *entity)
{
if (entity == NULL)
return;
if (entity->parent->dev)
module_put(entity->parent->dev->driver->owner);
}
static struct media_link *media_entity_add_link(struct media_entity *entity)
{
if (entity->num_links >= entity->max_links) {
struct media_link *links = entity->links;
unsigned int max_links = entity->max_links + 2;
unsigned int i;
links = krealloc(links, max_links * sizeof(*links), GFP_KERNEL);
if (links == NULL)
return NULL;
for (i = 0; i < entity->num_links; i++)
links[i].reverse->reverse = &links[i];
entity->max_links = max_links;
entity->links = links;
}
return &entity->links[entity->num_links++];
}
int
media_entity_create_link(struct media_entity *source, u16 source_pad,
struct media_entity *sink, u16 sink_pad, u32 flags)
{
struct media_link *link;
struct media_link *backlink;
BUG_ON(source == NULL || sink == NULL);
BUG_ON(source_pad >= source->num_pads);
BUG_ON(sink_pad >= sink->num_pads);
link = media_entity_add_link(source);
if (link == NULL)
return -ENOMEM;
link->source = &source->pads[source_pad];
link->sink = &sink->pads[sink_pad];
link->flags = flags;
backlink = media_entity_add_link(sink);
if (backlink == NULL) {
source->num_links--;
return -ENOMEM;
}
backlink->source = &source->pads[source_pad];
backlink->sink = &sink->pads[sink_pad];
backlink->flags = flags;
link->reverse = backlink;
backlink->reverse = link;
sink->num_backlinks++;
return 0;
}
void __media_entity_remove_links(struct media_entity *entity)
{
unsigned int i;
for (i = 0; i < entity->num_links; i++) {
struct media_link *link = &entity->links[i];
struct media_entity *remote;
unsigned int r = 0;
if (link->source->entity == entity)
remote = link->sink->entity;
else
remote = link->source->entity;
while (r < remote->num_links) {
struct media_link *rlink = &remote->links[r];
if (rlink != link->reverse) {
r++;
continue;
}
if (link->source->entity == entity)
remote->num_backlinks--;
if (--remote->num_links == 0)
break;
*rlink = remote->links[remote->num_links];
}
}
entity->num_links = 0;
entity->num_backlinks = 0;
}
void media_entity_remove_links(struct media_entity *entity)
{
if (entity->parent == NULL)
return;
mutex_lock(&entity->parent->graph_mutex);
__media_entity_remove_links(entity);
mutex_unlock(&entity->parent->graph_mutex);
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
mdev = source->parent;
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
mutex_lock(&link->source->entity->parent->graph_mutex);
ret = __media_entity_setup_link(link, flags);
mutex_unlock(&link->source->entity->parent->graph_mutex);
return ret;
}
struct media_link *
media_entity_find_link(struct media_pad *source, struct media_pad *sink)
{
struct media_link *link;
unsigned int i;
for (i = 0; i < source->entity->num_links; ++i) {
link = &source->entity->links[i];
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
unsigned int i;
for (i = 0; i < pad->entity->num_links; i++) {
struct media_link *link = &pad->entity->links[i];
if (!(link->flags & MEDIA_LNK_FL_ENABLED))
continue;
if (link->source == pad)
return link->sink;
if (link->sink == pad)
return link->source;
}
return NULL;
}
