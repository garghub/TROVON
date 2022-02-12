static struct bpf_map *htab_map_alloc(union bpf_attr *attr)
{
struct bpf_htab *htab;
int err, i;
htab = kzalloc(sizeof(*htab), GFP_USER);
if (!htab)
return ERR_PTR(-ENOMEM);
htab->map.key_size = attr->key_size;
htab->map.value_size = attr->value_size;
htab->map.max_entries = attr->max_entries;
err = -EINVAL;
if (htab->map.max_entries == 0 || htab->map.key_size == 0 ||
htab->map.value_size == 0)
goto free_htab;
htab->n_buckets = roundup_pow_of_two(htab->map.max_entries);
err = -E2BIG;
if (htab->map.key_size > MAX_BPF_STACK)
goto free_htab;
if (htab->map.value_size >= (1 << (KMALLOC_SHIFT_MAX - 1)) -
MAX_BPF_STACK - sizeof(struct htab_elem))
goto free_htab;
htab->elem_size = sizeof(struct htab_elem) +
round_up(htab->map.key_size, 8) +
htab->map.value_size;
if (htab->n_buckets == 0 ||
htab->n_buckets > U32_MAX / sizeof(struct bucket))
goto free_htab;
if ((u64) htab->n_buckets * sizeof(struct bucket) +
(u64) htab->elem_size * htab->map.max_entries >=
U32_MAX - PAGE_SIZE)
goto free_htab;
htab->map.pages = round_up(htab->n_buckets * sizeof(struct bucket) +
htab->elem_size * htab->map.max_entries,
PAGE_SIZE) >> PAGE_SHIFT;
err = -ENOMEM;
htab->buckets = kmalloc_array(htab->n_buckets, sizeof(struct bucket),
GFP_USER | __GFP_NOWARN);
if (!htab->buckets) {
htab->buckets = vmalloc(htab->n_buckets * sizeof(struct bucket));
if (!htab->buckets)
goto free_htab;
}
for (i = 0; i < htab->n_buckets; i++) {
INIT_HLIST_HEAD(&htab->buckets[i].head);
raw_spin_lock_init(&htab->buckets[i].lock);
}
atomic_set(&htab->count, 0);
return &htab->map;
free_htab:
kfree(htab);
return ERR_PTR(err);
}
static inline u32 htab_map_hash(const void *key, u32 key_len)
{
return jhash(key, key_len, 0);
}
static inline struct bucket *__select_bucket(struct bpf_htab *htab, u32 hash)
{
return &htab->buckets[hash & (htab->n_buckets - 1)];
}
static inline struct hlist_head *select_bucket(struct bpf_htab *htab, u32 hash)
{
return &__select_bucket(htab, hash)->head;
}
static struct htab_elem *lookup_elem_raw(struct hlist_head *head, u32 hash,
void *key, u32 key_size)
{
struct htab_elem *l;
hlist_for_each_entry_rcu(l, head, hash_node)
if (l->hash == hash && !memcmp(&l->key, key, key_size))
return l;
return NULL;
}
static void *htab_map_lookup_elem(struct bpf_map *map, void *key)
{
struct bpf_htab *htab = container_of(map, struct bpf_htab, map);
struct hlist_head *head;
struct htab_elem *l;
u32 hash, key_size;
WARN_ON_ONCE(!rcu_read_lock_held());
key_size = map->key_size;
hash = htab_map_hash(key, key_size);
head = select_bucket(htab, hash);
l = lookup_elem_raw(head, hash, key, key_size);
if (l)
return l->key + round_up(map->key_size, 8);
return NULL;
}
static int htab_map_get_next_key(struct bpf_map *map, void *key, void *next_key)
{
struct bpf_htab *htab = container_of(map, struct bpf_htab, map);
struct hlist_head *head;
struct htab_elem *l, *next_l;
u32 hash, key_size;
int i;
WARN_ON_ONCE(!rcu_read_lock_held());
key_size = map->key_size;
hash = htab_map_hash(key, key_size);
head = select_bucket(htab, hash);
l = lookup_elem_raw(head, hash, key, key_size);
if (!l) {
i = 0;
goto find_first_elem;
}
next_l = hlist_entry_safe(rcu_dereference_raw(hlist_next_rcu(&l->hash_node)),
struct htab_elem, hash_node);
if (next_l) {
memcpy(next_key, next_l->key, key_size);
return 0;
}
i = hash & (htab->n_buckets - 1);
i++;
find_first_elem:
for (; i < htab->n_buckets; i++) {
head = select_bucket(htab, i);
next_l = hlist_entry_safe(rcu_dereference_raw(hlist_first_rcu(head)),
struct htab_elem, hash_node);
if (next_l) {
memcpy(next_key, next_l->key, key_size);
return 0;
}
}
return -ENOENT;
}
static int htab_map_update_elem(struct bpf_map *map, void *key, void *value,
u64 map_flags)
{
struct bpf_htab *htab = container_of(map, struct bpf_htab, map);
struct htab_elem *l_new, *l_old;
struct hlist_head *head;
struct bucket *b;
unsigned long flags;
u32 key_size;
int ret;
if (map_flags > BPF_EXIST)
return -EINVAL;
WARN_ON_ONCE(!rcu_read_lock_held());
l_new = kmalloc(htab->elem_size, GFP_ATOMIC | __GFP_NOWARN);
if (!l_new)
return -ENOMEM;
key_size = map->key_size;
memcpy(l_new->key, key, key_size);
memcpy(l_new->key + round_up(key_size, 8), value, map->value_size);
l_new->hash = htab_map_hash(l_new->key, key_size);
b = __select_bucket(htab, l_new->hash);
head = &b->head;
raw_spin_lock_irqsave(&b->lock, flags);
l_old = lookup_elem_raw(head, l_new->hash, key, key_size);
if (!l_old && unlikely(atomic_read(&htab->count) >= map->max_entries)) {
ret = -E2BIG;
goto err;
}
if (l_old && map_flags == BPF_NOEXIST) {
ret = -EEXIST;
goto err;
}
if (!l_old && map_flags == BPF_EXIST) {
ret = -ENOENT;
goto err;
}
hlist_add_head_rcu(&l_new->hash_node, head);
if (l_old) {
hlist_del_rcu(&l_old->hash_node);
kfree_rcu(l_old, rcu);
} else {
atomic_inc(&htab->count);
}
raw_spin_unlock_irqrestore(&b->lock, flags);
return 0;
err:
raw_spin_unlock_irqrestore(&b->lock, flags);
kfree(l_new);
return ret;
}
static int htab_map_delete_elem(struct bpf_map *map, void *key)
{
struct bpf_htab *htab = container_of(map, struct bpf_htab, map);
struct hlist_head *head;
struct bucket *b;
struct htab_elem *l;
unsigned long flags;
u32 hash, key_size;
int ret = -ENOENT;
WARN_ON_ONCE(!rcu_read_lock_held());
key_size = map->key_size;
hash = htab_map_hash(key, key_size);
b = __select_bucket(htab, hash);
head = &b->head;
raw_spin_lock_irqsave(&b->lock, flags);
l = lookup_elem_raw(head, hash, key, key_size);
if (l) {
hlist_del_rcu(&l->hash_node);
atomic_dec(&htab->count);
kfree_rcu(l, rcu);
ret = 0;
}
raw_spin_unlock_irqrestore(&b->lock, flags);
return ret;
}
static void delete_all_elements(struct bpf_htab *htab)
{
int i;
for (i = 0; i < htab->n_buckets; i++) {
struct hlist_head *head = select_bucket(htab, i);
struct hlist_node *n;
struct htab_elem *l;
hlist_for_each_entry_safe(l, n, head, hash_node) {
hlist_del_rcu(&l->hash_node);
atomic_dec(&htab->count);
kfree(l);
}
}
}
static void htab_map_free(struct bpf_map *map)
{
struct bpf_htab *htab = container_of(map, struct bpf_htab, map);
synchronize_rcu();
delete_all_elements(htab);
kvfree(htab->buckets);
kfree(htab);
}
static int __init register_htab_map(void)
{
bpf_register_map_type(&htab_type);
return 0;
}
