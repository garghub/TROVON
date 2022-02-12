void
wmem_call_callbacks(wmem_allocator_t *allocator, wmem_cb_event_t event)
{
wmem_user_cb_container_t **prev, *cur;
gboolean again;
prev = &(allocator->callbacks);
cur = allocator->callbacks;
while (cur) {
again = cur->cb(allocator, event, cur->user_data);
if (! again || event == WMEM_CB_DESTROY_EVENT) {
*prev = cur->next;
wmem_free(NULL, cur);
cur = *prev;
}
else {
prev = &(cur->next);
cur = cur->next;
}
}
}
guint
wmem_register_callback(wmem_allocator_t *allocator,
wmem_user_cb_t callback, void *user_data)
{
wmem_user_cb_container_t *container;
static guint next_id = 1;
container = wmem_new(NULL, wmem_user_cb_container_t);
container->cb = callback;
container->user_data = user_data;
container->next = allocator->callbacks;
container->id = next_id++;
allocator->callbacks = container;
return container->id;
}
void
wmem_unregister_callback(wmem_allocator_t *allocator, guint id)
{
wmem_user_cb_container_t **prev, *cur;
prev = &(allocator->callbacks);
cur = allocator->callbacks;
while (cur) {
if (cur->id == id) {
*prev = cur->next;
wmem_free(NULL, cur);
return;
}
prev = &(cur->next);
cur = cur->next;
}
}
