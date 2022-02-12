void
wmem_init_hashing(void)
{
x = g_random_int();
if G_UNLIKELY(x == 0)
x = 1;
preseed = g_random_int();
postseed = g_random_int();
}
static void
wmem_map_init_table(wmem_map_t *map)
{
map->count = 0;
map->capacity = WMEM_MAP_DEFAULT_CAPACITY;
map->table = wmem_alloc0_array(map->allocator, wmem_map_item_t*, CAPACITY(map));
}
wmem_map_t *
wmem_map_new(wmem_allocator_t *allocator,
GHashFunc hash_func, GEqualFunc eql_func)
{
wmem_map_t *map;
map = wmem_new(allocator, wmem_map_t);
map->hash_func = hash_func;
map->eql_func = eql_func;
map->master = allocator;
map->allocator = allocator;
map->count = 0;
map->table = NULL;
return map;
}
static gboolean
wmem_map_reset_cb(wmem_allocator_t *allocator _U_, wmem_cb_event_t event,
void *user_data)
{
wmem_map_t *map = (wmem_map_t*)user_data;
map->count = 0;
map->table = NULL;
if (event == WMEM_CB_DESTROY_EVENT) {
wmem_unregister_callback(map->master, map->master_cb_id);
wmem_free(map->master, map);
}
return TRUE;
}
static gboolean
wmem_map_destroy_cb(wmem_allocator_t *allocator _U_, wmem_cb_event_t event _U_,
void *user_data)
{
wmem_map_t *map = (wmem_map_t*)user_data;
wmem_unregister_callback(map->allocator, map->slave_cb_id);
return FALSE;
}
wmem_map_t *
wmem_map_new_autoreset(wmem_allocator_t *master, wmem_allocator_t *slave,
GHashFunc hash_func, GEqualFunc eql_func)
{
wmem_map_t *map;
map = wmem_new(master, wmem_map_t);
map->hash_func = hash_func;
map->eql_func = eql_func;
map->master = master;
map->allocator = slave;
map->count = 0;
map->table = NULL;
map->master_cb_id = wmem_register_callback(master, wmem_map_destroy_cb, map);
map->slave_cb_id = wmem_register_callback(slave, wmem_map_reset_cb, map);
return map;
}
static inline void
wmem_map_grow(wmem_map_t *map)
{
wmem_map_item_t **old_table, *cur, *nxt;
size_t old_cap, i;
guint slot;
old_table = map->table;
old_cap = CAPACITY(map);
map->capacity++;
map->table = wmem_alloc0_array(map->allocator, wmem_map_item_t*, CAPACITY(map));
for (i=0; i<old_cap; i++) {
cur = old_table[i];
while (cur) {
nxt = cur->next;
slot = HASH(map, cur->key);
cur->next = map->table[slot];
map->table[slot] = cur;
cur = nxt;
}
}
wmem_free(map->allocator, old_table);
}
void *
wmem_map_insert(wmem_map_t *map, const void *key, void *value)
{
wmem_map_item_t **item;
void *old_val;
if (map->table == NULL) {
wmem_map_init_table(map);
}
item = &(map->table[HASH(map, key)]);
while (*item) {
if (map->eql_func(key, (*item)->key)) {
old_val = (*item)->value;
(*item)->value = value;
return old_val;
}
item = &((*item)->next);
}
(*item) = wmem_new(map->allocator, wmem_map_item_t);
(*item)->key = key;
(*item)->value = value;
(*item)->next = NULL;
map->count++;
if (map->count >= CAPACITY(map)) {
wmem_map_grow(map);
}
return NULL;
}
void *
wmem_map_lookup(wmem_map_t *map, const void *key)
{
wmem_map_item_t *item;
if (map->table == NULL) {
return NULL;
}
item = map->table[HASH(map, key)];
while (item) {
if (map->eql_func(key, item->key)) {
return item->value;
}
item = item->next;
}
return NULL;
}
void *
wmem_map_remove(wmem_map_t *map, const void *key)
{
wmem_map_item_t **item, *tmp;
void *value;
if (map->table == NULL) {
return NULL;
}
item = &(map->table[HASH(map, key)]);
while (*item) {
if (map->eql_func(key, (*item)->key)) {
tmp = (*item);
value = tmp->value;
(*item) = tmp->next;
wmem_free(map->allocator, tmp);
map->count--;
return value;
}
item = &((*item)->next);
}
return NULL;
}
gboolean
wmem_map_steal(wmem_map_t *map, const void *key)
{
wmem_map_item_t **item, *tmp;
if (map->table == NULL) {
return FALSE;
}
item = &(map->table[HASH(map, key)]);
while (*item) {
if (map->eql_func(key, (*item)->key)) {
tmp = (*item);
(*item) = tmp->next;
map->count--;
return TRUE;
}
item = &((*item)->next);
}
return FALSE;
}
wmem_list_t*
wmem_map_get_keys(wmem_allocator_t *list_allocator, wmem_map_t *map)
{
size_t capacity, i;
wmem_map_item_t *cur;
wmem_list_t* list = wmem_list_new(list_allocator);
if (map->table != NULL) {
capacity = CAPACITY(map);
for (i=0; i<capacity; i++) {
cur = map->table[i];
while (cur) {
wmem_list_prepend(list, (void*)cur->key);
cur = cur->next;
}
}
}
return list;
}
void
wmem_map_foreach(wmem_map_t *map, GHFunc foreach_func, gpointer user_data)
{
wmem_map_item_t *cur;
unsigned i;
if (map->table == NULL) {
return;
}
for (i = 0; i < CAPACITY(map); i++) {
cur = map->table[i];
while (cur) {
foreach_func((gpointer)cur->key, (gpointer)cur->value, user_data);
cur = cur->next;
}
}
}
guint
wmem_map_size(wmem_map_t *map)
{
return map->count;
}
guint32
wmem_strong_hash(const guint8 *buf, const size_t len)
{
const guint8 * const end = (const guint8 *)buf + len;
guint32 hash = preseed + (guint32)len;
while (buf < end) {
hash += (hash << 10);
hash ^= (hash >> 6);
hash += *buf++;
}
hash += (hash << 10);
hash ^= (hash >> 6);
hash += ((guint8*)&postseed)[0];
hash += (hash << 10);
hash ^= (hash >> 6);
hash += ((guint8*)&postseed)[1];
hash += (hash << 10);
hash ^= (hash >> 6);
hash += ((guint8*)&postseed)[2];
hash += (hash << 10);
hash ^= (hash >> 6);
hash += ((guint8*)&postseed)[3];
hash += (hash << 10);
hash ^= (hash >> 6);
hash += (hash << 3);
hash ^= (hash >> 11);
return (hash + (hash << 15));
}
guint
wmem_str_hash(gconstpointer key)
{
return wmem_strong_hash((const guint8 *)key, strlen((const char *)key));
}
guint
wmem_int64_hash(gconstpointer key)
{
return wmem_strong_hash((const guint8 *)key, sizeof(guint64));
}
guint
wmem_double_hash(gconstpointer key)
{
return wmem_strong_hash((const guint8 *)key, sizeof(double));
}
