guint
wmem_slist_count(const wmem_slist_t *slist)
{
return slist->count;
}
wmem_slist_frame_t *
wmem_slist_front(const wmem_slist_t *slist)
{
return slist->front;
}
wmem_slist_frame_t *
wmem_slist_frame_next(const wmem_slist_frame_t *frame)
{
return frame->next;
}
void *
wmem_slist_frame_data(const wmem_slist_frame_t *frame)
{
return frame->data;
}
static wmem_slist_frame_t **
wmem_slist_find(wmem_slist_t *slist, void *data)
{
wmem_slist_frame_t **cur;
cur = &(slist->front);
while (*cur && (*cur)->data != data) {
cur = &((*cur)->next);
}
return cur;
}
void
wmem_slist_remove(wmem_slist_t *slist, void *data)
{
wmem_slist_frame_t *frame;
wmem_slist_frame_t **link;
link = wmem_slist_find(slist, data);
frame = *link;
if (frame == NULL) {
return;
}
*link = frame->next;
slist->count--;
wmem_free(slist->allocator, frame);
}
void
wmem_slist_prepend(wmem_slist_t *slist, void *data)
{
wmem_slist_frame_t *new_frame;
new_frame = wmem_new(slist->allocator, wmem_slist_frame_t);
new_frame->data = data;
new_frame->next = slist->front;
slist->front = new_frame;
slist->count++;
}
wmem_slist_t *
wmem_slist_new(wmem_allocator_t *allocator)
{
wmem_slist_t *slist;
slist = (wmem_slist_t *) wmem_alloc(allocator, sizeof(wmem_slist_t));
slist->count = 0;
slist->front = NULL;
slist->allocator = allocator;
return slist;
}
