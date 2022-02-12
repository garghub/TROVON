static void rmgr_refcount_init_vbuf(void)
{
memset(&handle_table, 0, sizeof(handle_table));
}
void ia_css_rmgr_refcount_retain_vbuf(struct ia_css_rmgr_vbuf_handle **handle)
{
int i;
struct ia_css_rmgr_vbuf_handle *h;
if ((handle == NULL) || (*handle == NULL)) {
IA_CSS_LOG("Invalid inputs");
return;
}
if ((*handle)->count == 0) {
h = *handle;
*handle = NULL;
for (i = 0; i < NUM_HANDLES; i++) {
if (handle_table[i].count == 0) {
*handle = &handle_table[i];
break;
}
}
if (*handle == NULL) {
ia_css_debug_dtrace(IA_CSS_DEBUG_ERROR,
"ia_css_i_host_refcount_retain_vbuf() failed to find empty slot!\n");
return;
}
(*handle)->vptr = h->vptr;
(*handle)->size = h->size;
}
(*handle)->count++;
}
void ia_css_rmgr_refcount_release_vbuf(struct ia_css_rmgr_vbuf_handle **handle)
{
if ((handle == NULL) || ((*handle) == NULL) || (((*handle)->count) == 0)) {
ia_css_debug_dtrace(IA_CSS_DEBUG_ERROR,
"ia_css_rmgr_refcount_release_vbuf() invalid arguments!\n");
return;
}
(*handle)->count--;
if ((*handle)->count == 0) {
(*handle)->vptr = 0x0;
(*handle)->size = 0;
*handle = NULL;
}
}
enum ia_css_err ia_css_rmgr_init_vbuf(struct ia_css_rmgr_vbuf_pool *pool)
{
enum ia_css_err err = IA_CSS_SUCCESS;
size_t bytes_needed;
rmgr_refcount_init_vbuf();
assert(pool != NULL);
if (pool == NULL)
return IA_CSS_ERR_INVALID_ARGUMENTS;
if (pool->recycle && pool->size) {
bytes_needed =
sizeof(void *) *
pool->size;
pool->handles = sh_css_malloc(bytes_needed);
if (pool->handles != NULL)
memset(pool->handles, 0, bytes_needed);
else
err = IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
} else {
pool->size = 0;
pool->handles = NULL;
}
return err;
}
void ia_css_rmgr_uninit_vbuf(struct ia_css_rmgr_vbuf_pool *pool)
{
uint32_t i;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_rmgr_uninit_vbuf()\n");
if (pool == NULL) {
ia_css_debug_dtrace(IA_CSS_DEBUG_ERROR, "ia_css_rmgr_uninit_vbuf(): NULL argument\n");
return;
}
if (pool->handles != NULL) {
for (i = 0; i < pool->size; i++) {
if (pool->handles[i] != NULL) {
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
" freeing/releasing %x (count=%d)\n",
pool->handles[i]->vptr,
pool->handles[i]->count);
hmm_free(pool->handles[i]->vptr);
ia_css_rmgr_refcount_release_vbuf(
&pool->handles[i]);
}
}
sh_css_free(pool->handles);
pool->handles = NULL;
}
}
static
void rmgr_push_handle(struct ia_css_rmgr_vbuf_pool *pool,
struct ia_css_rmgr_vbuf_handle **handle)
{
uint32_t i;
bool succes = false;
assert(pool != NULL);
assert(pool->recycle);
assert(pool->handles != NULL);
assert(handle != NULL);
for (i = 0; i < pool->size; i++) {
if (pool->handles[i] == NULL) {
ia_css_rmgr_refcount_retain_vbuf(handle);
pool->handles[i] = *handle;
succes = true;
break;
}
}
assert(succes);
}
static
void rmgr_pop_handle(struct ia_css_rmgr_vbuf_pool *pool,
struct ia_css_rmgr_vbuf_handle **handle)
{
uint32_t i;
bool succes = false;
assert(pool != NULL);
assert(pool->recycle);
assert(pool->handles != NULL);
assert(handle != NULL);
assert(*handle != NULL);
for (i = 0; i < pool->size; i++) {
if ((pool->handles[i] != NULL) &&
(pool->handles[i]->size == (*handle)->size)) {
*handle = pool->handles[i];
pool->handles[i] = NULL;
succes = true;
break;
}
}
}
void ia_css_rmgr_acq_vbuf(struct ia_css_rmgr_vbuf_pool *pool,
struct ia_css_rmgr_vbuf_handle **handle)
{
struct ia_css_rmgr_vbuf_handle h;
if ((pool == NULL) || (handle == NULL) || (*handle == NULL)) {
IA_CSS_LOG("Invalid inputs");
return;
}
if (pool->copy_on_write) {
if ((*handle)->count == 1)
return;
if ((*handle)->count > 1) {
h.vptr = 0x0;
h.size = (*handle)->size;
ia_css_rmgr_refcount_release_vbuf(handle);
*handle = &h;
}
if ((*handle)->vptr == 0x0) {
if (pool->recycle) {
rmgr_pop_handle(pool, handle);
}
if ((*handle)->vptr == 0x0) {
(*handle)->vptr = mmgr_malloc((*handle)->size);
} else {
return;
}
}
}
ia_css_rmgr_refcount_retain_vbuf(handle);
}
void ia_css_rmgr_rel_vbuf(struct ia_css_rmgr_vbuf_pool *pool,
struct ia_css_rmgr_vbuf_handle **handle)
{
if ((pool == NULL) || (handle == NULL) || (*handle == NULL)) {
IA_CSS_LOG("Invalid inputs");
return;
}
if ((*handle)->count == 1) {
if (!pool->recycle) {
hmm_free((*handle)->vptr);
} else {
rmgr_push_handle(pool, handle);
}
}
ia_css_rmgr_refcount_release_vbuf(handle);
*handle = NULL;
}
