void tracing_map_update_sum(struct tracing_map_elt *elt, unsigned int i, u64 n)
{
atomic64_add(n, &elt->fields[i].sum);
}
u64 tracing_map_read_sum(struct tracing_map_elt *elt, unsigned int i)
{
return (u64)atomic64_read(&elt->fields[i].sum);
}
int tracing_map_cmp_string(void *val_a, void *val_b)
{
char *a = val_a;
char *b = val_b;
return strcmp(a, b);
}
int tracing_map_cmp_none(void *val_a, void *val_b)
{
return 0;
}
static int tracing_map_cmp_atomic64(void *val_a, void *val_b)
{
u64 a = atomic64_read((atomic64_t *)val_a);
u64 b = atomic64_read((atomic64_t *)val_b);
return (a > b) ? 1 : ((a < b) ? -1 : 0);
}
tracing_map_cmp_fn_t tracing_map_cmp_num(int field_size,
int field_is_signed)
{
tracing_map_cmp_fn_t fn = tracing_map_cmp_none;
switch (field_size) {
case 8:
if (field_is_signed)
fn = tracing_map_cmp_s64;
else
fn = tracing_map_cmp_u64;
break;
case 4:
if (field_is_signed)
fn = tracing_map_cmp_s32;
else
fn = tracing_map_cmp_u32;
break;
case 2:
if (field_is_signed)
fn = tracing_map_cmp_s16;
else
fn = tracing_map_cmp_u16;
break;
case 1:
if (field_is_signed)
fn = tracing_map_cmp_s8;
else
fn = tracing_map_cmp_u8;
break;
}
return fn;
}
static int tracing_map_add_field(struct tracing_map *map,
tracing_map_cmp_fn_t cmp_fn)
{
int ret = -EINVAL;
if (map->n_fields < TRACING_MAP_FIELDS_MAX) {
ret = map->n_fields;
map->fields[map->n_fields++].cmp_fn = cmp_fn;
}
return ret;
}
int tracing_map_add_sum_field(struct tracing_map *map)
{
return tracing_map_add_field(map, tracing_map_cmp_atomic64);
}
int tracing_map_add_key_field(struct tracing_map *map,
unsigned int offset,
tracing_map_cmp_fn_t cmp_fn)
{
int idx = tracing_map_add_field(map, cmp_fn);
if (idx < 0)
return idx;
map->fields[idx].offset = offset;
map->key_idx[map->n_keys++] = idx;
return idx;
}
void tracing_map_array_clear(struct tracing_map_array *a)
{
unsigned int i;
if (!a->pages)
return;
for (i = 0; i < a->n_pages; i++)
memset(a->pages[i], 0, PAGE_SIZE);
}
void tracing_map_array_free(struct tracing_map_array *a)
{
unsigned int i;
if (!a)
return;
if (!a->pages) {
kfree(a);
return;
}
for (i = 0; i < a->n_pages; i++) {
if (!a->pages[i])
break;
free_page((unsigned long)a->pages[i]);
}
}
struct tracing_map_array *tracing_map_array_alloc(unsigned int n_elts,
unsigned int entry_size)
{
struct tracing_map_array *a;
unsigned int i;
a = kzalloc(sizeof(*a), GFP_KERNEL);
if (!a)
return NULL;
a->entry_size_shift = fls(roundup_pow_of_two(entry_size) - 1);
a->entries_per_page = PAGE_SIZE / (1 << a->entry_size_shift);
a->n_pages = n_elts / a->entries_per_page;
if (!a->n_pages)
a->n_pages = 1;
a->entry_shift = fls(a->entries_per_page) - 1;
a->entry_mask = (1 << a->entry_shift) - 1;
a->pages = kcalloc(a->n_pages, sizeof(void *), GFP_KERNEL);
if (!a->pages)
goto free;
for (i = 0; i < a->n_pages; i++) {
a->pages[i] = (void *)get_zeroed_page(GFP_KERNEL);
if (!a->pages[i])
goto free;
}
out:
return a;
free:
tracing_map_array_free(a);
a = NULL;
goto out;
}
static void tracing_map_elt_clear(struct tracing_map_elt *elt)
{
unsigned i;
for (i = 0; i < elt->map->n_fields; i++)
if (elt->fields[i].cmp_fn == tracing_map_cmp_atomic64)
atomic64_set(&elt->fields[i].sum, 0);
if (elt->map->ops && elt->map->ops->elt_clear)
elt->map->ops->elt_clear(elt);
}
static void tracing_map_elt_init_fields(struct tracing_map_elt *elt)
{
unsigned int i;
tracing_map_elt_clear(elt);
for (i = 0; i < elt->map->n_fields; i++) {
elt->fields[i].cmp_fn = elt->map->fields[i].cmp_fn;
if (elt->fields[i].cmp_fn != tracing_map_cmp_atomic64)
elt->fields[i].offset = elt->map->fields[i].offset;
}
}
static void tracing_map_elt_free(struct tracing_map_elt *elt)
{
if (!elt)
return;
if (elt->map->ops && elt->map->ops->elt_free)
elt->map->ops->elt_free(elt);
kfree(elt->fields);
kfree(elt->key);
kfree(elt);
}
static struct tracing_map_elt *tracing_map_elt_alloc(struct tracing_map *map)
{
struct tracing_map_elt *elt;
int err = 0;
elt = kzalloc(sizeof(*elt), GFP_KERNEL);
if (!elt)
return ERR_PTR(-ENOMEM);
elt->map = map;
elt->key = kzalloc(map->key_size, GFP_KERNEL);
if (!elt->key) {
err = -ENOMEM;
goto free;
}
elt->fields = kcalloc(map->n_fields, sizeof(*elt->fields), GFP_KERNEL);
if (!elt->fields) {
err = -ENOMEM;
goto free;
}
tracing_map_elt_init_fields(elt);
if (map->ops && map->ops->elt_alloc) {
err = map->ops->elt_alloc(elt);
if (err)
goto free;
}
return elt;
free:
tracing_map_elt_free(elt);
return ERR_PTR(err);
}
static struct tracing_map_elt *get_free_elt(struct tracing_map *map)
{
struct tracing_map_elt *elt = NULL;
int idx;
idx = atomic_inc_return(&map->next_elt);
if (idx < map->max_elts) {
elt = *(TRACING_MAP_ELT(map->elts, idx));
if (map->ops && map->ops->elt_init)
map->ops->elt_init(elt);
}
return elt;
}
static void tracing_map_free_elts(struct tracing_map *map)
{
unsigned int i;
if (!map->elts)
return;
for (i = 0; i < map->max_elts; i++) {
tracing_map_elt_free(*(TRACING_MAP_ELT(map->elts, i)));
*(TRACING_MAP_ELT(map->elts, i)) = NULL;
}
tracing_map_array_free(map->elts);
map->elts = NULL;
}
static int tracing_map_alloc_elts(struct tracing_map *map)
{
unsigned int i;
map->elts = tracing_map_array_alloc(map->max_elts,
sizeof(struct tracing_map_elt *));
if (!map->elts)
return -ENOMEM;
for (i = 0; i < map->max_elts; i++) {
*(TRACING_MAP_ELT(map->elts, i)) = tracing_map_elt_alloc(map);
if (IS_ERR(*(TRACING_MAP_ELT(map->elts, i)))) {
*(TRACING_MAP_ELT(map->elts, i)) = NULL;
tracing_map_free_elts(map);
return -ENOMEM;
}
}
return 0;
}
static inline bool keys_match(void *key, void *test_key, unsigned key_size)
{
bool match = true;
if (memcmp(key, test_key, key_size))
match = false;
return match;
}
static inline struct tracing_map_elt *
__tracing_map_insert(struct tracing_map *map, void *key, bool lookup_only)
{
u32 idx, key_hash, test_key;
struct tracing_map_entry *entry;
key_hash = jhash(key, map->key_size, 0);
if (key_hash == 0)
key_hash = 1;
idx = key_hash >> (32 - (map->map_bits + 1));
while (1) {
idx &= (map->map_size - 1);
entry = TRACING_MAP_ENTRY(map->map, idx);
test_key = entry->key;
if (test_key && test_key == key_hash && entry->val &&
keys_match(key, entry->val->key, map->key_size)) {
atomic64_inc(&map->hits);
return entry->val;
}
if (!test_key) {
if (lookup_only)
break;
if (!cmpxchg(&entry->key, 0, key_hash)) {
struct tracing_map_elt *elt;
elt = get_free_elt(map);
if (!elt) {
atomic64_inc(&map->drops);
entry->key = 0;
break;
}
memcpy(elt->key, key, map->key_size);
entry->val = elt;
atomic64_inc(&map->hits);
return entry->val;
}
}
idx++;
}
return NULL;
}
struct tracing_map_elt *tracing_map_insert(struct tracing_map *map, void *key)
{
return __tracing_map_insert(map, key, false);
}
struct tracing_map_elt *tracing_map_lookup(struct tracing_map *map, void *key)
{
return __tracing_map_insert(map, key, true);
}
void tracing_map_destroy(struct tracing_map *map)
{
if (!map)
return;
tracing_map_free_elts(map);
tracing_map_array_free(map->map);
kfree(map);
}
void tracing_map_clear(struct tracing_map *map)
{
unsigned int i;
atomic_set(&map->next_elt, -1);
atomic64_set(&map->hits, 0);
atomic64_set(&map->drops, 0);
tracing_map_array_clear(map->map);
for (i = 0; i < map->max_elts; i++)
tracing_map_elt_clear(*(TRACING_MAP_ELT(map->elts, i)));
}
static void set_sort_key(struct tracing_map *map,
struct tracing_map_sort_key *sort_key)
{
map->sort_key = *sort_key;
}
struct tracing_map *tracing_map_create(unsigned int map_bits,
unsigned int key_size,
const struct tracing_map_ops *ops,
void *private_data)
{
struct tracing_map *map;
unsigned int i;
if (map_bits < TRACING_MAP_BITS_MIN ||
map_bits > TRACING_MAP_BITS_MAX)
return ERR_PTR(-EINVAL);
map = kzalloc(sizeof(*map), GFP_KERNEL);
if (!map)
return ERR_PTR(-ENOMEM);
map->map_bits = map_bits;
map->max_elts = (1 << map_bits);
atomic_set(&map->next_elt, -1);
map->map_size = (1 << (map_bits + 1));
map->ops = ops;
map->private_data = private_data;
map->map = tracing_map_array_alloc(map->map_size,
sizeof(struct tracing_map_entry));
if (!map->map)
goto free;
map->key_size = key_size;
for (i = 0; i < TRACING_MAP_KEYS_MAX; i++)
map->key_idx[i] = -1;
out:
return map;
free:
tracing_map_destroy(map);
map = ERR_PTR(-ENOMEM);
goto out;
}
int tracing_map_init(struct tracing_map *map)
{
int err;
if (map->n_fields < 2)
return -EINVAL;
err = tracing_map_alloc_elts(map);
if (err)
return err;
tracing_map_clear(map);
return err;
}
static int cmp_entries_dup(const struct tracing_map_sort_entry **a,
const struct tracing_map_sort_entry **b)
{
int ret = 0;
if (memcmp((*a)->key, (*b)->key, (*a)->elt->map->key_size))
ret = 1;
return ret;
}
static int cmp_entries_sum(const struct tracing_map_sort_entry **a,
const struct tracing_map_sort_entry **b)
{
const struct tracing_map_elt *elt_a, *elt_b;
struct tracing_map_sort_key *sort_key;
struct tracing_map_field *field;
tracing_map_cmp_fn_t cmp_fn;
void *val_a, *val_b;
int ret = 0;
elt_a = (*a)->elt;
elt_b = (*b)->elt;
sort_key = &elt_a->map->sort_key;
field = &elt_a->fields[sort_key->field_idx];
cmp_fn = field->cmp_fn;
val_a = &elt_a->fields[sort_key->field_idx].sum;
val_b = &elt_b->fields[sort_key->field_idx].sum;
ret = cmp_fn(val_a, val_b);
if (sort_key->descending)
ret = -ret;
return ret;
}
static int cmp_entries_key(const struct tracing_map_sort_entry **a,
const struct tracing_map_sort_entry **b)
{
const struct tracing_map_elt *elt_a, *elt_b;
struct tracing_map_sort_key *sort_key;
struct tracing_map_field *field;
tracing_map_cmp_fn_t cmp_fn;
void *val_a, *val_b;
int ret = 0;
elt_a = (*a)->elt;
elt_b = (*b)->elt;
sort_key = &elt_a->map->sort_key;
field = &elt_a->fields[sort_key->field_idx];
cmp_fn = field->cmp_fn;
val_a = elt_a->key + field->offset;
val_b = elt_b->key + field->offset;
ret = cmp_fn(val_a, val_b);
if (sort_key->descending)
ret = -ret;
return ret;
}
static void destroy_sort_entry(struct tracing_map_sort_entry *entry)
{
if (!entry)
return;
if (entry->elt_copied)
tracing_map_elt_free(entry->elt);
kfree(entry);
}
void tracing_map_destroy_sort_entries(struct tracing_map_sort_entry **entries,
unsigned int n_entries)
{
unsigned int i;
for (i = 0; i < n_entries; i++)
destroy_sort_entry(entries[i]);
vfree(entries);
}
static struct tracing_map_sort_entry *
create_sort_entry(void *key, struct tracing_map_elt *elt)
{
struct tracing_map_sort_entry *sort_entry;
sort_entry = kzalloc(sizeof(*sort_entry), GFP_KERNEL);
if (!sort_entry)
return NULL;
sort_entry->key = key;
sort_entry->elt = elt;
return sort_entry;
}
static struct tracing_map_elt *copy_elt(struct tracing_map_elt *elt)
{
struct tracing_map_elt *dup_elt;
unsigned int i;
dup_elt = tracing_map_elt_alloc(elt->map);
if (IS_ERR(dup_elt))
return NULL;
if (elt->map->ops && elt->map->ops->elt_copy)
elt->map->ops->elt_copy(dup_elt, elt);
dup_elt->private_data = elt->private_data;
memcpy(dup_elt->key, elt->key, elt->map->key_size);
for (i = 0; i < elt->map->n_fields; i++) {
atomic64_set(&dup_elt->fields[i].sum,
atomic64_read(&elt->fields[i].sum));
dup_elt->fields[i].cmp_fn = elt->fields[i].cmp_fn;
}
return dup_elt;
}
static int merge_dup(struct tracing_map_sort_entry **sort_entries,
unsigned int target, unsigned int dup)
{
struct tracing_map_elt *target_elt, *elt;
bool first_dup = (target - dup) == 1;
int i;
if (first_dup) {
elt = sort_entries[target]->elt;
target_elt = copy_elt(elt);
if (!target_elt)
return -ENOMEM;
sort_entries[target]->elt = target_elt;
sort_entries[target]->elt_copied = true;
} else
target_elt = sort_entries[target]->elt;
elt = sort_entries[dup]->elt;
for (i = 0; i < elt->map->n_fields; i++)
atomic64_add(atomic64_read(&elt->fields[i].sum),
&target_elt->fields[i].sum);
sort_entries[dup]->dup = true;
return 0;
}
static int merge_dups(struct tracing_map_sort_entry **sort_entries,
int n_entries, unsigned int key_size)
{
unsigned int dups = 0, total_dups = 0;
int err, i, j;
void *key;
if (n_entries < 2)
return total_dups;
sort(sort_entries, n_entries, sizeof(struct tracing_map_sort_entry *),
(int (*)(const void *, const void *))cmp_entries_dup, NULL);
key = sort_entries[0]->key;
for (i = 1; i < n_entries; i++) {
if (!memcmp(sort_entries[i]->key, key, key_size)) {
dups++; total_dups++;
err = merge_dup(sort_entries, i - dups, i);
if (err)
return err;
continue;
}
key = sort_entries[i]->key;
dups = 0;
}
if (!total_dups)
return total_dups;
for (i = 0, j = 0; i < n_entries; i++) {
if (!sort_entries[i]->dup) {
sort_entries[j] = sort_entries[i];
if (j++ != i)
sort_entries[i] = NULL;
} else {
destroy_sort_entry(sort_entries[i]);
sort_entries[i] = NULL;
}
}
return total_dups;
}
static bool is_key(struct tracing_map *map, unsigned int field_idx)
{
unsigned int i;
for (i = 0; i < map->n_keys; i++)
if (map->key_idx[i] == field_idx)
return true;
return false;
}
static void sort_secondary(struct tracing_map *map,
const struct tracing_map_sort_entry **entries,
unsigned int n_entries,
struct tracing_map_sort_key *primary_key,
struct tracing_map_sort_key *secondary_key)
{
int (*primary_fn)(const struct tracing_map_sort_entry **,
const struct tracing_map_sort_entry **);
int (*secondary_fn)(const struct tracing_map_sort_entry **,
const struct tracing_map_sort_entry **);
unsigned i, start = 0, n_sub = 1;
if (is_key(map, primary_key->field_idx))
primary_fn = cmp_entries_key;
else
primary_fn = cmp_entries_sum;
if (is_key(map, secondary_key->field_idx))
secondary_fn = cmp_entries_key;
else
secondary_fn = cmp_entries_sum;
for (i = 0; i < n_entries - 1; i++) {
const struct tracing_map_sort_entry **a = &entries[i];
const struct tracing_map_sort_entry **b = &entries[i + 1];
if (primary_fn(a, b) == 0) {
n_sub++;
if (i < n_entries - 2)
continue;
}
if (n_sub < 2) {
start = i + 1;
n_sub = 1;
continue;
}
set_sort_key(map, secondary_key);
sort(&entries[start], n_sub,
sizeof(struct tracing_map_sort_entry *),
(int (*)(const void *, const void *))secondary_fn, NULL);
set_sort_key(map, primary_key);
start = i + 1;
n_sub = 1;
}
}
int tracing_map_sort_entries(struct tracing_map *map,
struct tracing_map_sort_key *sort_keys,
unsigned int n_sort_keys,
struct tracing_map_sort_entry ***sort_entries)
{
int (*cmp_entries_fn)(const struct tracing_map_sort_entry **,
const struct tracing_map_sort_entry **);
struct tracing_map_sort_entry *sort_entry, **entries;
int i, n_entries, ret;
entries = vmalloc(map->max_elts * sizeof(sort_entry));
if (!entries)
return -ENOMEM;
for (i = 0, n_entries = 0; i < map->map_size; i++) {
struct tracing_map_entry *entry;
entry = TRACING_MAP_ENTRY(map->map, i);
if (!entry->key || !entry->val)
continue;
entries[n_entries] = create_sort_entry(entry->val->key,
entry->val);
if (!entries[n_entries++]) {
ret = -ENOMEM;
goto free;
}
}
if (n_entries == 0) {
ret = 0;
goto free;
}
if (n_entries == 1) {
*sort_entries = entries;
return 1;
}
ret = merge_dups(entries, n_entries, map->key_size);
if (ret < 0)
goto free;
n_entries -= ret;
if (is_key(map, sort_keys[0].field_idx))
cmp_entries_fn = cmp_entries_key;
else
cmp_entries_fn = cmp_entries_sum;
set_sort_key(map, &sort_keys[0]);
sort(entries, n_entries, sizeof(struct tracing_map_sort_entry *),
(int (*)(const void *, const void *))cmp_entries_fn, NULL);
if (n_sort_keys > 1)
sort_secondary(map,
(const struct tracing_map_sort_entry **)entries,
n_entries,
&sort_keys[0],
&sort_keys[1]);
*sort_entries = entries;
return n_entries;
free:
tracing_map_destroy_sort_entries(entries, n_entries);
return ret;
}
