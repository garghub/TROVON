void
ws_buffer_init(Buffer* buffer, gsize space)
{
if G_UNLIKELY(!small_buffers) small_buffers = g_ptr_array_sized_new(1024);
if (space <= SMALL_BUFFER_SIZE) {
if (small_buffers->len > 0) {
buffer->data = (guint8*) g_ptr_array_remove_index(small_buffers, small_buffers->len - 1);
} else {
buffer->data = (guint8*)g_malloc(SMALL_BUFFER_SIZE);
}
buffer->allocated = SMALL_BUFFER_SIZE;
} else {
buffer->data = (guint8*)g_malloc(space);
buffer->allocated = space;
}
buffer->start = 0;
buffer->first_free = 0;
}
void
ws_buffer_free(Buffer* buffer)
{
if (buffer->allocated == SMALL_BUFFER_SIZE) {
g_ptr_array_add(small_buffers, buffer->data);
} else {
g_free(buffer->data);
}
buffer->data = NULL;
}
void
ws_buffer_assure_space(Buffer* buffer, gsize space)
{
gsize available_at_end = buffer->allocated - buffer->first_free;
gsize space_used;
gboolean space_at_beginning;
if (space <= available_at_end) {
return;
}
space_at_beginning = buffer->start >= space;
if (space_at_beginning || buffer->start > 0) {
space_used = buffer->first_free - buffer->start;
memmove(buffer->data, buffer->data + buffer->start, space_used);
buffer->start = 0;
buffer->first_free = space_used;
}
if (space_at_beginning) {
return;
}
buffer->allocated += space + 1024;
buffer->data = (guint8*)g_realloc(buffer->data, buffer->allocated);
}
void
ws_buffer_append(Buffer* buffer, guint8 *from, gsize bytes)
{
ws_buffer_assure_space(buffer, bytes);
memcpy(buffer->data + buffer->first_free, from, bytes);
buffer->first_free += bytes;
}
void
ws_buffer_remove_start(Buffer* buffer, gsize bytes)
{
if (buffer->start + bytes > buffer->first_free) {
g_error("ws_buffer_remove_start trying to remove %" G_GINT64_MODIFIER "u bytes. s=%" G_GINT64_MODIFIER "u ff=%" G_GINT64_MODIFIER "u!\n",
(guint64)bytes, (guint64)buffer->start,
(guint64)buffer->first_free);
}
buffer->start += bytes;
if (buffer->start == buffer->first_free) {
buffer->start = 0;
buffer->first_free = 0;
}
}
void
ws_buffer_clean(Buffer* buffer)
{
ws_buffer_remove_start(buffer, ws_buffer_length(buffer));
}
void
ws_buffer_increase_length(Buffer* buffer, gsize bytes)
{
buffer->first_free += bytes;
}
gsize
ws_buffer_length(Buffer* buffer)
{
return buffer->first_free - buffer->start;
}
guint8 *
ws_buffer_start_ptr(Buffer* buffer)
{
return buffer->data + buffer->start;
}
guint8 *
ws_buffer_end_ptr(Buffer* buffer)
{
return buffer->data + buffer->first_free;
}
void
ws_buffer_append_buffer(Buffer* buffer, Buffer* src_buffer)
{
ws_buffer_append(buffer, ws_buffer_start_ptr(src_buffer), ws_buffer_length(src_buffer));
}
void
ws_buffer_cleanup(void)
{
if (small_buffers) {
g_ptr_array_set_free_func(small_buffers, g_free);
g_ptr_array_free(small_buffers, TRUE);
small_buffers = NULL;
}
}
