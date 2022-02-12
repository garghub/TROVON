void
wmem_init_hashing(void)
{
x = g_random_int();
if G_UNLIKELY(x == 0)
x = 1;
preseed = g_random_int();
postseed = g_random_int();
}
wmem_map_t *
wmem_map_new(wmem_allocator_t *allocator,
GHashFunc hash_func, GEqualFunc eql_func)
{
wmem_map_t *map;
map = wmem_new(allocator, wmem_map_t);
map->count = 0;
map->capacity = WMEM_MAP_DEFAULT_CAPACITY;
map->table = wmem_alloc0_array(allocator, wmem_map_item_t*, CAPACITY(map));
map->hash_func = hash_func;
map->eql_func = eql_func;
map->allocator = allocator;
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
void
wmem_map_foreach(wmem_map_t *map, GHFunc foreach_func, gpointer user_data)
{
wmem_map_item_t *cur;
unsigned i;
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
