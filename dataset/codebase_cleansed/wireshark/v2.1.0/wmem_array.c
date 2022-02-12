wmem_array_t *
wmem_array_sized_new(wmem_allocator_t *allocator, gsize elem_size,
guint alloc_count)
{
wmem_array_t *array;
array = wmem_new(allocator, wmem_array_t);
array->allocator = allocator;
array->elem_size = elem_size;
array->elem_count = 0;
array->alloc_count = alloc_count ? alloc_count : 1;
array->null_terminated = FALSE;
array->buf = (guint8 *)wmem_alloc(array->allocator,
array->elem_size * array->alloc_count);
return array;
}
wmem_array_t *
wmem_array_new(wmem_allocator_t *allocator, const gsize elem_size)
{
wmem_array_t *array;
array = wmem_array_sized_new(allocator, elem_size, 1);
return array;
}
static void
wmem_array_grow(wmem_array_t *array, const guint to_add)
{
guint new_alloc_count, new_count;
new_alloc_count = array->alloc_count;
new_count = array->elem_count + to_add;
while (new_alloc_count < new_count) {
new_alloc_count *= 2;
}
if (new_alloc_count == array->alloc_count) {
return;
}
array->buf = (guint8 *)wmem_realloc(array->allocator, array->buf,
new_alloc_count * array->elem_size);
array->alloc_count = new_alloc_count;
}
static void
wmem_array_write_null_terminator(wmem_array_t *array)
{
if (array->null_terminated) {
wmem_array_grow(array, 1);
memset(&array->buf[array->elem_count * array->elem_size], 0x0, array->elem_size);
}
}
void
wmem_array_set_null_terminator(wmem_array_t *array)
{
array->null_terminated = TRUE;
wmem_array_write_null_terminator(array);
}
void
wmem_array_bzero(wmem_array_t *array)
{
memset(array->buf, 0x0, array->elem_size * array->elem_count);
}
void
wmem_array_append(wmem_array_t *array, const void *in, guint count)
{
wmem_array_grow(array, count);
memcpy(&array->buf[array->elem_count * array->elem_size], in,
count * array->elem_size);
array->elem_count += count;
wmem_array_write_null_terminator(array);
}
void *
wmem_array_index(wmem_array_t *array, guint array_index)
{
g_assert(array_index < array->elem_count);
return &array->buf[array_index * array->elem_size];
}
void
wmem_array_sort(wmem_array_t *array, int (*compar)(const void*,const void*))
{
qsort(array->buf, array->elem_count, array->elem_size, compar);
}
void *
wmem_array_get_raw(wmem_array_t *array)
{
return array->buf;
}
guint
wmem_array_get_count(wmem_array_t *array)
{
return array->elem_count;
}
