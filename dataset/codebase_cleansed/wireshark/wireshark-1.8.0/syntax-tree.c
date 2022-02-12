void
sttype_init(void)
{
sttype_register_function();
sttype_register_integer();
sttype_register_pointer();
sttype_register_range();
sttype_register_string();
sttype_register_test();
}
void
sttype_cleanup(void)
{
}
void
sttype_register(sttype_t *type)
{
sttype_id_t type_id;
type_id = type->id;
g_assert(type_id < STTYPE_NUM_TYPES);
g_assert(type_list[type_id] == NULL);
type_list[type_id] = type;
}
static sttype_t*
sttype_lookup(sttype_id_t type_id)
{
sttype_t *result;
g_assert(type_id < STTYPE_NUM_TYPES);
result = type_list[type_id];
g_assert(result != NULL);
return result;
}
stnode_t*
stnode_new(sttype_id_t type_id, gpointer data)
{
sttype_t *type;
stnode_t *node;
node = g_new(stnode_t, 1);
node->magic = STNODE_MAGIC;
node->deprecated_token = NULL;
if (type_id == STTYPE_UNINITIALIZED) {
node->type = NULL;
node->data = NULL;
}
else {
type = sttype_lookup(type_id);
g_assert(type);
node->type = type;
if (type->func_new) {
node->data = type->func_new(data);
}
else {
node->data = data;
}
}
return node;
}
void
stnode_init(stnode_t *node, sttype_id_t type_id, gpointer data)
{
sttype_t *type;
assert_magic(node, STNODE_MAGIC);
g_assert(!node->type);
g_assert(!node->data);
type = sttype_lookup(type_id);
g_assert(type);
node->type = type;
if (type->func_new) {
node->data = type->func_new(data);
}
else {
node->data = data;
}
}
void
stnode_init_int(stnode_t *node, sttype_id_t type_id, gint32 value)
{
stnode_init(node, type_id, NULL);
node->value = value;
}
void
stnode_free(stnode_t *node)
{
assert_magic(node, STNODE_MAGIC);
if (node->type) {
if (node->type->func_free) {
node->type->func_free(node->data);
}
}
else {
g_assert(!node->data);
}
g_free(node);
}
const char*
stnode_type_name(stnode_t *node)
{
assert_magic(node, STNODE_MAGIC);
if (node->type)
return node->type->name;
else
return "UNINITIALIZED";
}
sttype_id_t
stnode_type_id(stnode_t *node)
{
assert_magic(node, STNODE_MAGIC);
if (node->type)
return node->type->id;
else
return STTYPE_UNINITIALIZED;
}
gpointer
stnode_data(stnode_t *node)
{
assert_magic(node, STNODE_MAGIC);
return node->data;
}
gint32
stnode_value(stnode_t *node)
{
assert_magic(node, STNODE_MAGIC);
return node->value;
}
const char *
stnode_deprecated(stnode_t *node)
{
if (!node) {
return NULL;
}
return node->deprecated_token;
}
