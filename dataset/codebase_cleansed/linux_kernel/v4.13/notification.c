u32 fsnotify_get_cookie(void)
{
return atomic_inc_return(&fsnotify_sync_cookie);
}
bool fsnotify_notify_queue_is_empty(struct fsnotify_group *group)
{
assert_spin_locked(&group->notification_lock);
return list_empty(&group->notification_list) ? true : false;
}
void fsnotify_destroy_event(struct fsnotify_group *group,
struct fsnotify_event *event)
{
if (!event || event->mask == FS_Q_OVERFLOW)
return;
if (!list_empty(&event->list)) {
spin_lock(&group->notification_lock);
WARN_ON(!list_empty(&event->list));
spin_unlock(&group->notification_lock);
}
group->ops->free_event(event);
}
int fsnotify_add_event(struct fsnotify_group *group,
struct fsnotify_event *event,
int (*merge)(struct list_head *,
struct fsnotify_event *))
{
int ret = 0;
struct list_head *list = &group->notification_list;
pr_debug("%s: group=%p event=%p\n", __func__, group, event);
spin_lock(&group->notification_lock);
if (group->shutdown) {
spin_unlock(&group->notification_lock);
return 2;
}
if (group->q_len >= group->max_events) {
ret = 2;
if (!list_empty(&group->overflow_event->list)) {
spin_unlock(&group->notification_lock);
return ret;
}
event = group->overflow_event;
goto queue;
}
if (!list_empty(list) && merge) {
ret = merge(list, event);
if (ret) {
spin_unlock(&group->notification_lock);
return ret;
}
}
queue:
group->q_len++;
list_add_tail(&event->list, list);
spin_unlock(&group->notification_lock);
wake_up(&group->notification_waitq);
kill_fasync(&group->fsn_fa, SIGIO, POLL_IN);
return ret;
}
struct fsnotify_event *fsnotify_remove_first_event(struct fsnotify_group *group)
{
struct fsnotify_event *event;
assert_spin_locked(&group->notification_lock);
pr_debug("%s: group=%p\n", __func__, group);
event = list_first_entry(&group->notification_list,
struct fsnotify_event, list);
list_del_init(&event->list);
group->q_len--;
return event;
}
struct fsnotify_event *fsnotify_peek_first_event(struct fsnotify_group *group)
{
assert_spin_locked(&group->notification_lock);
return list_first_entry(&group->notification_list,
struct fsnotify_event, list);
}
void fsnotify_flush_notify(struct fsnotify_group *group)
{
struct fsnotify_event *event;
spin_lock(&group->notification_lock);
while (!fsnotify_notify_queue_is_empty(group)) {
event = fsnotify_remove_first_event(group);
spin_unlock(&group->notification_lock);
fsnotify_destroy_event(group, event);
spin_lock(&group->notification_lock);
}
spin_unlock(&group->notification_lock);
}
void fsnotify_init_event(struct fsnotify_event *event, struct inode *inode,
u32 mask)
{
INIT_LIST_HEAD(&event->list);
event->inode = inode;
event->mask = mask;
}
