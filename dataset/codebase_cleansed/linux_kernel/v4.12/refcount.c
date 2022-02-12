static struct ia_css_refcount_entry *refcount_find_entry(hrt_vaddress ptr,
bool firstfree)
{
uint32_t i;
if (ptr == 0)
return NULL;
if (myrefcount.items == NULL) {
ia_css_debug_dtrace(IA_CSS_DEBUG_ERROR,
"refcount_find_entry(): Ref count not initiliazed!\n");
return NULL;
}
for (i = 0; i < myrefcount.size; i++) {
if ((&myrefcount.items[i])->data == 0) {
if (firstfree) {
return &myrefcount.items[i];
}
}
if ((&myrefcount.items[i])->data == ptr) {
return &myrefcount.items[i];
}
}
return NULL;
}
enum ia_css_err ia_css_refcount_init(uint32_t size)
{
enum ia_css_err err = IA_CSS_SUCCESS;
if (size == 0) {
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_refcount_init(): Size of 0 for Ref count init!\n");
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
if (myrefcount.items != NULL) {
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_refcount_init(): Ref count is already initialized\n");
return IA_CSS_ERR_INTERNAL_ERROR;
}
myrefcount.items =
sh_css_malloc(sizeof(struct ia_css_refcount_entry) * size);
if (!myrefcount.items)
err = IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
if (err == IA_CSS_SUCCESS) {
memset(myrefcount.items, 0,
sizeof(struct ia_css_refcount_entry) * size);
myrefcount.size = size;
}
return err;
}
void ia_css_refcount_uninit(void)
{
struct ia_css_refcount_entry *entry;
uint32_t i;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_refcount_uninit() entry\n");
for (i = 0; i < myrefcount.size; i++) {
entry = myrefcount.items + i;
if (entry->data != mmgr_NULL) {
hmm_free(entry->data);
entry->data = mmgr_NULL;
entry->count = 0;
entry->id = 0;
}
}
sh_css_free(myrefcount.items);
myrefcount.items = NULL;
myrefcount.size = 0;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_refcount_uninit() leave\n");
}
hrt_vaddress ia_css_refcount_increment(int32_t id, hrt_vaddress ptr)
{
struct ia_css_refcount_entry *entry;
if (ptr == mmgr_NULL)
return ptr;
entry = refcount_find_entry(ptr, false);
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_refcount_increment(%x) 0x%x\n", id, ptr);
if (!entry) {
entry = refcount_find_entry(ptr, true);
assert(entry != NULL);
if (entry == NULL)
return mmgr_NULL;
entry->id = id;
}
if (entry->id != id) {
ia_css_debug_dtrace(IA_CSS_DEBUG_ERROR,
"ia_css_refcount_increment(): Ref count IDS do not match!\n");
return mmgr_NULL;
}
if (entry->data == ptr)
entry->count += 1;
else if (entry->data == mmgr_NULL) {
entry->data = ptr;
entry->count = 1;
} else
return mmgr_NULL;
return ptr;
}
bool ia_css_refcount_decrement(int32_t id, hrt_vaddress ptr)
{
struct ia_css_refcount_entry *entry;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_refcount_decrement(%x) 0x%x\n", id, ptr);
if (ptr == mmgr_NULL)
return false;
entry = refcount_find_entry(ptr, false);
if (entry) {
if (entry->id != id) {
ia_css_debug_dtrace(IA_CSS_DEBUG_ERROR,
"ia_css_refcount_decrement(): Ref count IDS do not match!\n");
return false;
}
if (entry->count > 0) {
entry->count -= 1;
if (entry->count == 0) {
hmm_free(ptr);
entry->data = mmgr_NULL;
entry->id = 0;
}
return true;
}
}
if (entry)
IA_CSS_ERROR("id %x, ptr 0x%x entry %p entry->id %x entry->count %d\n",
id, ptr, entry, entry->id, entry->count);
else
IA_CSS_ERROR("entry NULL\n");
#ifdef ISP2401
assert(false);
#endif
return false;
}
bool ia_css_refcount_is_single(hrt_vaddress ptr)
{
struct ia_css_refcount_entry *entry;
if (ptr == mmgr_NULL)
return false;
entry = refcount_find_entry(ptr, false);
if (entry)
return (entry->count == 1);
return true;
}
void ia_css_refcount_clear(int32_t id, clear_func clear_func_ptr)
{
struct ia_css_refcount_entry *entry;
uint32_t i;
uint32_t count = 0;
assert(clear_func_ptr != NULL);
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_refcount_clear(%x)\n",
id);
for (i = 0; i < myrefcount.size; i++) {
entry = myrefcount.items + i;
if ((entry->data != mmgr_NULL) && (entry->id == id)) {
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_refcount_clear:"
" %x: 0x%x\n", id, entry->data);
if (clear_func_ptr) {
clear_func_ptr(entry->data);
} else {
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_refcount_clear: "
"using hmm_free: "
"no clear_func\n");
hmm_free(entry->data);
}
#ifndef ISP2401
#else
assert(entry->count == 0);
#endif
if (entry->count != 0) {
IA_CSS_WARNING("Ref count for entry %x is not zero!", entry->id);
}
entry->data = mmgr_NULL;
entry->count = 0;
entry->id = 0;
count++;
}
}
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_refcount_clear(%x): cleared %d\n", id,
count);
}
bool ia_css_refcount_is_valid(hrt_vaddress ptr)
{
struct ia_css_refcount_entry *entry;
if (ptr == mmgr_NULL)
return false;
entry = refcount_find_entry(ptr, false);
return entry != NULL;
}
