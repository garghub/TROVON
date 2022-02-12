const STORE_METHOD *STORE_Memory(void)
{
return &store_memory;
}
static int mem_init(STORE *s)
{
return 1;
}
static void mem_clean(STORE *s)
{
return;
}
static STORE_OBJECT *mem_generate(STORE *s, STORE_OBJECT_TYPES type,
OPENSSL_ITEM attributes[],
OPENSSL_ITEM parameters[])
{
STOREerr(STORE_F_MEM_GENERATE, STORE_R_NOT_IMPLEMENTED);
return 0;
}
static STORE_OBJECT *mem_get(STORE *s, STORE_OBJECT_TYPES type,
OPENSSL_ITEM attributes[],
OPENSSL_ITEM parameters[])
{
void *context = mem_list_start(s, type, attributes, parameters);
if (context) {
STORE_OBJECT *object = mem_list_next(s, context);
if (mem_list_end(s, context))
return object;
}
return NULL;
}
static int mem_store(STORE *s, STORE_OBJECT_TYPES type,
STORE_OBJECT *data, OPENSSL_ITEM attributes[],
OPENSSL_ITEM parameters[])
{
STOREerr(STORE_F_MEM_STORE, STORE_R_NOT_IMPLEMENTED);
return 0;
}
static int mem_modify(STORE *s, STORE_OBJECT_TYPES type,
OPENSSL_ITEM search_attributes[],
OPENSSL_ITEM add_attributes[],
OPENSSL_ITEM modify_attributes[],
OPENSSL_ITEM delete_attributes[],
OPENSSL_ITEM parameters[])
{
STOREerr(STORE_F_MEM_MODIFY, STORE_R_NOT_IMPLEMENTED);
return 0;
}
static int mem_delete(STORE *s, STORE_OBJECT_TYPES type,
OPENSSL_ITEM attributes[], OPENSSL_ITEM parameters[])
{
STOREerr(STORE_F_MEM_DELETE, STORE_R_NOT_IMPLEMENTED);
return 0;
}
static void *mem_list_start(STORE *s, STORE_OBJECT_TYPES type,
OPENSSL_ITEM attributes[],
OPENSSL_ITEM parameters[])
{
struct mem_ctx_st *context =
(struct mem_ctx_st *)OPENSSL_malloc(sizeof(struct mem_ctx_st));
void *attribute_context = NULL;
STORE_ATTR_INFO *attrs = NULL;
if (!context) {
STOREerr(STORE_F_MEM_LIST_START, ERR_R_MALLOC_FAILURE);
return 0;
}
memset(context, 0, sizeof(struct mem_ctx_st));
attribute_context = STORE_parse_attrs_start(attributes);
if (!attribute_context) {
STOREerr(STORE_F_MEM_LIST_START, ERR_R_STORE_LIB);
goto err;
}
while ((attrs = STORE_parse_attrs_next(attribute_context))) {
if (context->search_attributes == NULL) {
context->search_attributes =
sk_STORE_ATTR_INFO_new(STORE_ATTR_INFO_compare);
if (!context->search_attributes) {
STOREerr(STORE_F_MEM_LIST_START, ERR_R_MALLOC_FAILURE);
goto err;
}
}
sk_STORE_ATTR_INFO_push(context->search_attributes, attrs);
}
if (!STORE_parse_attrs_endp(attribute_context))
goto err;
STORE_parse_attrs_end(attribute_context);
context->search_index = -1;
context->index = -1;
return context;
err:
if (attribute_context)
STORE_parse_attrs_end(attribute_context);
mem_list_end(s, context);
return NULL;
}
static STORE_OBJECT *mem_list_next(STORE *s, void *handle)
{
int i;
struct mem_ctx_st *context = (struct mem_ctx_st *)handle;
struct mem_object_data_st key = { 0, 0, 1 };
struct mem_data_st *store = (struct mem_data_st *)STORE_get_ex_data(s, 1);
int srch;
int cres = 0;
if (!context) {
STOREerr(STORE_F_MEM_LIST_NEXT, ERR_R_PASSED_NULL_PARAMETER);
return NULL;
}
if (!store) {
STOREerr(STORE_F_MEM_LIST_NEXT, STORE_R_NO_STORE);
return NULL;
}
if (context->search_index == -1) {
for (i = 0;
i < sk_STORE_ATTR_INFO_num(context->search_attributes); i++) {
key.attr_info
= sk_STORE_ATTR_INFO_value(context->search_attributes, i);
srch = sk_MEM_OBJECT_DATA_find_ex(store->data, &key);
if (srch >= 0) {
context->search_index = srch;
break;
}
}
}
if (context->search_index < 0)
return NULL;
key.attr_info =
sk_STORE_ATTR_INFO_value(context->search_attributes,
context->search_index);
for (srch = context->search_index;
srch < sk_MEM_OBJECT_DATA_num(store->data)
&& STORE_ATTR_INFO_in_range(key.attr_info,
sk_MEM_OBJECT_DATA_value(store->data,
srch)->attr_info)
&& !(cres =
STORE_ATTR_INFO_in_ex(key.attr_info,
sk_MEM_OBJECT_DATA_value(store->data,
srch)->attr_info));
srch++) ;
context->search_index = srch;
if (cres)
return (sk_MEM_OBJECT_DATA_value(store->data, srch))->object;
return NULL;
}
static int mem_list_end(STORE *s, void *handle)
{
struct mem_ctx_st *context = (struct mem_ctx_st *)handle;
if (!context) {
STOREerr(STORE_F_MEM_LIST_END, ERR_R_PASSED_NULL_PARAMETER);
return 0;
}
if (context && context->search_attributes)
sk_STORE_ATTR_INFO_free(context->search_attributes);
if (context)
OPENSSL_free(context);
return 1;
}
static int mem_list_endp(STORE *s, void *handle)
{
struct mem_ctx_st *context = (struct mem_ctx_st *)handle;
if (!context
|| context->search_index
== sk_STORE_ATTR_INFO_num(context->search_attributes))
return 1;
return 0;
}
static int mem_lock(STORE *s, OPENSSL_ITEM attributes[],
OPENSSL_ITEM parameters[])
{
return 1;
}
static int mem_unlock(STORE *s, OPENSSL_ITEM attributes[],
OPENSSL_ITEM parameters[])
{
return 1;
}
static int mem_ctrl(STORE *s, int cmd, long l, void *p, void (*f) (void))
{
return 1;
}
