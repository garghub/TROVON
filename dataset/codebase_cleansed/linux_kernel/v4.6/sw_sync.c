struct fence *sw_sync_pt_create(struct sw_sync_timeline *obj, u32 value)
{
struct sw_sync_pt *pt;
pt = (struct sw_sync_pt *)
sync_pt_create(&obj->obj, sizeof(struct sw_sync_pt));
pt->value = value;
return (struct fence *)pt;
}
static int sw_sync_fence_has_signaled(struct fence *fence)
{
struct sw_sync_pt *pt = (struct sw_sync_pt *)fence;
struct sw_sync_timeline *obj =
(struct sw_sync_timeline *)fence_parent(fence);
return (pt->value > obj->value) ? 0 : 1;
}
static void sw_sync_timeline_value_str(struct sync_timeline *sync_timeline,
char *str, int size)
{
struct sw_sync_timeline *timeline =
(struct sw_sync_timeline *)sync_timeline;
snprintf(str, size, "%d", timeline->value);
}
static void sw_sync_fence_value_str(struct fence *fence, char *str, int size)
{
struct sw_sync_pt *pt = (struct sw_sync_pt *)fence;
snprintf(str, size, "%d", pt->value);
}
struct sw_sync_timeline *sw_sync_timeline_create(const char *name)
{
struct sw_sync_timeline *obj = (struct sw_sync_timeline *)
sync_timeline_create(&sw_sync_timeline_ops,
sizeof(struct sw_sync_timeline),
name);
return obj;
}
void sw_sync_timeline_inc(struct sw_sync_timeline *obj, u32 inc)
{
obj->value += inc;
sync_timeline_signal(&obj->obj);
}
