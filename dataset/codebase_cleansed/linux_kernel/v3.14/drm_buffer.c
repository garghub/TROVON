int drm_buffer_alloc(struct drm_buffer **buf, int size)
{
int nr_pages = size / PAGE_SIZE + 1;
int idx;
*buf = kzalloc(sizeof(struct drm_buffer) + nr_pages*sizeof(char *),
GFP_KERNEL);
if (*buf == NULL) {
DRM_ERROR("Failed to allocate drm buffer object to hold"
" %d bytes in %d pages.\n",
size, nr_pages);
return -ENOMEM;
}
(*buf)->size = size;
for (idx = 0; idx < nr_pages; ++idx) {
(*buf)->data[idx] =
kmalloc(min(PAGE_SIZE, size - idx * PAGE_SIZE),
GFP_KERNEL);
if ((*buf)->data[idx] == NULL) {
DRM_ERROR("Failed to allocate %dth page for drm"
" buffer with %d bytes and %d pages.\n",
idx + 1, size, nr_pages);
goto error_out;
}
}
return 0;
error_out:
if ((*buf)->data[idx])
kfree((*buf)->data[idx]);
for (--idx; idx >= 0; --idx)
kfree((*buf)->data[idx]);
kfree(*buf);
return -ENOMEM;
}
int drm_buffer_copy_from_user(struct drm_buffer *buf,
void __user *user_data, int size)
{
int nr_pages = size / PAGE_SIZE + 1;
int idx;
if (size > buf->size) {
DRM_ERROR("Requesting to copy %d bytes to a drm buffer with"
" %d bytes space\n",
size, buf->size);
return -EFAULT;
}
for (idx = 0; idx < nr_pages; ++idx) {
if (copy_from_user(buf->data[idx],
user_data + idx * PAGE_SIZE,
min(PAGE_SIZE, size - idx * PAGE_SIZE))) {
DRM_ERROR("Failed to copy user data (%p) to drm buffer"
" (%p) %dth page.\n",
user_data, buf, idx);
return -EFAULT;
}
}
buf->iterator = 0;
return 0;
}
void drm_buffer_free(struct drm_buffer *buf)
{
if (buf != NULL) {
int nr_pages = buf->size / PAGE_SIZE + 1;
int idx;
for (idx = 0; idx < nr_pages; ++idx)
kfree(buf->data[idx]);
kfree(buf);
}
}
void *drm_buffer_read_object(struct drm_buffer *buf,
int objsize, void *stack_obj)
{
int idx = drm_buffer_index(buf);
int page = drm_buffer_page(buf);
void *obj = NULL;
if (idx + objsize <= PAGE_SIZE) {
obj = &buf->data[page][idx];
} else {
int beginsz = PAGE_SIZE - idx;
memcpy(stack_obj, &buf->data[page][idx], beginsz);
memcpy(stack_obj + beginsz, &buf->data[page + 1][0],
objsize - beginsz);
obj = stack_obj;
}
drm_buffer_advance(buf, objsize);
return obj;
}
