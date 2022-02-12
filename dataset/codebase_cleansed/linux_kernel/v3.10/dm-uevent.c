static void dm_uevent_free(struct dm_uevent *event)
{
kmem_cache_free(_dm_event_cache, event);
}
static struct dm_uevent *dm_uevent_alloc(struct mapped_device *md)
{
struct dm_uevent *event;
event = kmem_cache_zalloc(_dm_event_cache, GFP_ATOMIC);
if (!event)
return NULL;
INIT_LIST_HEAD(&event->elist);
event->md = md;
return event;
}
static struct dm_uevent *dm_build_path_uevent(struct mapped_device *md,
struct dm_target *ti,
enum kobject_action action,
const char *dm_action,
const char *path,
unsigned nr_valid_paths)
{
struct dm_uevent *event;
event = dm_uevent_alloc(md);
if (!event) {
DMERR("%s: dm_uevent_alloc() failed", __func__);
goto err_nomem;
}
event->action = action;
if (add_uevent_var(&event->ku_env, "DM_TARGET=%s", ti->type->name)) {
DMERR("%s: add_uevent_var() for DM_TARGET failed",
__func__);
goto err_add;
}
if (add_uevent_var(&event->ku_env, "DM_ACTION=%s", dm_action)) {
DMERR("%s: add_uevent_var() for DM_ACTION failed",
__func__);
goto err_add;
}
if (add_uevent_var(&event->ku_env, "DM_SEQNUM=%u",
dm_next_uevent_seq(md))) {
DMERR("%s: add_uevent_var() for DM_SEQNUM failed",
__func__);
goto err_add;
}
if (add_uevent_var(&event->ku_env, "DM_PATH=%s", path)) {
DMERR("%s: add_uevent_var() for DM_PATH failed", __func__);
goto err_add;
}
if (add_uevent_var(&event->ku_env, "DM_NR_VALID_PATHS=%d",
nr_valid_paths)) {
DMERR("%s: add_uevent_var() for DM_NR_VALID_PATHS failed",
__func__);
goto err_add;
}
return event;
err_add:
dm_uevent_free(event);
err_nomem:
return ERR_PTR(-ENOMEM);
}
void dm_send_uevents(struct list_head *events, struct kobject *kobj)
{
int r;
struct dm_uevent *event, *next;
list_for_each_entry_safe(event, next, events, elist) {
list_del_init(&event->elist);
if (dm_copy_name_and_uuid(event->md, event->name,
event->uuid)) {
DMINFO("%s: skipping sending uevent for lost device",
__func__);
goto uevent_free;
}
if (add_uevent_var(&event->ku_env, "DM_NAME=%s", event->name)) {
DMERR("%s: add_uevent_var() for DM_NAME failed",
__func__);
goto uevent_free;
}
if (add_uevent_var(&event->ku_env, "DM_UUID=%s", event->uuid)) {
DMERR("%s: add_uevent_var() for DM_UUID failed",
__func__);
goto uevent_free;
}
r = kobject_uevent_env(kobj, event->action, event->ku_env.envp);
if (r)
DMERR("%s: kobject_uevent_env failed", __func__);
uevent_free:
dm_uevent_free(event);
}
}
void dm_path_uevent(enum dm_uevent_type event_type, struct dm_target *ti,
const char *path, unsigned nr_valid_paths)
{
struct mapped_device *md = dm_table_get_md(ti->table);
struct dm_uevent *event;
if (event_type >= ARRAY_SIZE(_dm_uevent_type_names)) {
DMERR("%s: Invalid event_type %d", __func__, event_type);
return;
}
event = dm_build_path_uevent(md, ti,
_dm_uevent_type_names[event_type].action,
_dm_uevent_type_names[event_type].name,
path, nr_valid_paths);
if (IS_ERR(event))
return;
dm_uevent_add(md, &event->elist);
}
int dm_uevent_init(void)
{
_dm_event_cache = KMEM_CACHE(dm_uevent, 0);
if (!_dm_event_cache)
return -ENOMEM;
DMINFO("version 1.0.3");
return 0;
}
void dm_uevent_exit(void)
{
kmem_cache_destroy(_dm_event_cache);
}
