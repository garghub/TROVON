static ibuf_handle_t *getHandle(uint16_t index)
{
ibuf_handle_t *handle = NULL;
if (index < MAX_IBUF_HANDLES)
handle = &ibuf_rsrc.handles[index];
return handle;
}
void ia_css_isys_ibuf_rmgr_init(void)
{
memset(&ibuf_rsrc, 0, sizeof(ibuf_rsrc));
ibuf_rsrc.free_size = MAX_INPUT_BUFFER_SIZE;
}
void ia_css_isys_ibuf_rmgr_uninit(void)
{
memset(&ibuf_rsrc, 0, sizeof(ibuf_rsrc));
ibuf_rsrc.free_size = MAX_INPUT_BUFFER_SIZE;
}
bool ia_css_isys_ibuf_rmgr_acquire(
uint32_t size,
uint32_t *start_addr)
{
bool retval = false;
bool input_buffer_found = false;
uint32_t aligned_size;
ibuf_handle_t *handle = NULL;
uint16_t i;
assert(start_addr != NULL);
assert(size > 0);
aligned_size = (size + (IBUF_ALIGN - 1)) & ~(IBUF_ALIGN - 1);
if (ibuf_rsrc.num_active < ibuf_rsrc.num_allocated) {
for (i = 0; i < ibuf_rsrc.num_allocated; i++) {
handle = getHandle(i);
if (!handle->active) {
if (handle->size >= aligned_size) {
handle->active = true;
input_buffer_found = true;
ibuf_rsrc.num_active++;
break;
}
}
}
}
if (!input_buffer_found) {
if ((ibuf_rsrc.num_allocated < MAX_IBUF_HANDLES) &&
(ibuf_rsrc.free_size >= aligned_size)) {
handle = getHandle(ibuf_rsrc.num_allocated);
handle->start_addr = ibuf_rsrc.free_start_addr;
handle->size = aligned_size;
handle->active = true;
ibuf_rsrc.free_start_addr += aligned_size;
ibuf_rsrc.free_size -= aligned_size;
ibuf_rsrc.num_active++;
ibuf_rsrc.num_allocated++;
input_buffer_found = true;
}
}
if (input_buffer_found && handle) {
*start_addr = handle->start_addr;
retval = true;
}
return retval;
}
void ia_css_isys_ibuf_rmgr_release(
uint32_t *start_addr)
{
uint16_t i;
ibuf_handle_t *handle = NULL;
assert(start_addr != NULL);
for (i = 0; i < ibuf_rsrc.num_allocated; i++) {
handle = getHandle(i);
if (handle->active && handle->start_addr == *start_addr) {
handle->active = false;
ibuf_rsrc.num_active--;
break;
}
}
}
