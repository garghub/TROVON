static bool htab_is_lru(const struct bpf_htab *htab)
{
return htab->map.map_type == BPF_MAP_TYPE_LRU_HASH ||
htab->map.map_type == BPF_MAP_TYPE_LRU_PERCPU_HASH;
}
static bool htab_is_percpu(const struct bpf_htab *htab)
{
return htab->map.map_type == BPF_MAP_TYPE_PERCPU_HASH ||
htab->map.map_type == BPF_MAP_TYPE_LRU_PERCPU_HASH;
}
static bool htab_is_prealloc(const struct bpf_htab *htab)
{
return !(htab->map.map_flags & BPF_F_NO_PREALLOC);
}
static inline void htab_elem_set_ptr(struct htab_elem *l, u32 key_size,
void __percpu *pptr)
{
*(void __percpu **)(l->key + key_size) = pptr;
}
static inline void __percpu *htab_elem_get_ptr(struct htab_elem *l, u32 key_size)
{
return *(void __percpu **)(l->key + key_size);
}
static void *fd_htab_map_get_ptr(const struct bpf_map *map, struct htab_elem *l)
{
return *(void **)(l->key + roundup(map->key_size, 8));
}
static struct htab_elem *get_htab_elem(struct bpf_htab *htab, int i)
{
return (struct htab_elem *) (htab->elems + i * htab->elem_size);
}
static void htab_free_elems(struct bpf_htab *htab)
{
int i;
if (!htab_is_percpu(htab))
goto free_elems;
for (i = 0; i < htab->map.max_entries; i++) {
void __percpu *pptr;
pptr = htab_elem_get_ptr(get_htab_elem(htab, i),
htab->map.key_size);
free_percpu(pptr);
}
free_elems:
bpf_map_area_free(htab->elems);
}
static struct htab_elem *prealloc_lru_pop(struct bpf_htab *htab, void *key,
u32 hash)
{
struct bpf_lru_node *node = bpf_lru_pop_free(&htab->lru, hash);
struct htab_elem *l;
if (node) {
l = container_of(node, struct htab_elem, lru_node);
memcpy(l->key, key, htab->map.key_size);
return l;
}
return NULL;
}
static int prealloc_init(struct bpf_htab *htab)
{
u32 num_entries = htab->map.max_entries;
int err = -ENOMEM, i;
if (!htab_is_percpu(htab) && !htab_is_lru(htab))
num_entries += num_possible_cpus();
htab->elems = bpf_map_area_alloc(htab->elem_size * num_entries);
if (!htab->elems)
return -ENOMEM;
if (!htab_is_percpu(htab))
goto skip_percpu_elems;
for (i = 0; i < num_entries; i++) {
u32 size = round_up(htab->map.value_size, 8);
void __percpu *pptr;
pptr = __alloc_percpu_gfp(size, 8, GFP_USER | __GFP_NOWARN);
if (!pptr)
goto free_elems;
htab_elem_set_ptr(get_htab_elem(htab, i), htab->map.key_size,
pptr);
}
skip_percpu_elems:
if (htab_is_lru(htab))
err = bpf_lru_init(&htab->lru,
htab->map.map_flags & BPF_F_NO_COMMON_LRU,
offsetof(struct htab_elem, hash) -
offsetof(struct htab_elem, lru_node),
htab_lru_map_delete_node,
htab);
else
err = pcpu_freelist_init(&htab->freelist);
if (err)
goto free_elems;
if (htab_is_lru(htab))
bpf_lru_populate(&htab->lru, htab->elems,
offsetof(struct htab_elem, lru_node),
htab->elem_size, num_entries);
else
pcpu_freelist_populate(&htab->freelist,
htab->elems + offsetof(struct htab_elem, fnode),
htab->elem_size, num_entries);
return 0;
free_elems:
htab_free_elems(htab);
return err;
}
static void prealloc_destroy(struct bpf_htab *htab)
{
htab_free_elems(htab);
if (htab_is_lru(htab))
bpf_lru_destroy(&htab->lru);
else
pcpu_freelist_destroy(&htab->freelist);
}
static int alloc_extra_elems(struct bpf_htab *htab)
{
struct htab_elem *__percpu *pptr, *l_new;
struct pcpu_freelist_node *l;
int cpu;
pptr = __alloc_percpu_gfp(sizeof(struct htab_elem *), 8,
GFP_USER | __GFP_NOWARN);
if (!pptr)
return -ENOMEM;
for_each_possible_cpu(cpu) {
l = pcpu_freelist_pop(&htab->freelist);
l_new = container_of(l, struct htab_elem, fnode);
*per_cpu_ptr(pptr, cpu) = l_new;
}
htab->extra_elems = pptr;
return 0;
}
static struct bpf_map *htab_map_alloc(union bpf_attr *attr)
{
bool percpu = (attr->map_type == BPF_MAP_TYPE_PERCPU_HASH ||
attr->map_type == BPF_MAP_TYPE_LRU_PERCPU_HASH);
bool lru = (attr->map_type == BPF_MAP_TYPE_LRU_HASH ||
attr->map_type == BPF_MAP_TYPE_LRU_PERCPU_HASH);
bool percpu_lru = (attr->map_flags & BPF_F_NO_COMMON_LRU);
bool prealloc = !(attr->map_flags & BPF_F_NO_PREALLOC);
struct bpf_htab *htab;
int err, i;
u64 cost;
BUILD_BUG_ON(offsetof(struct htab_elem, htab) !=
offsetof(struct htab_elem, hash_node.pprev));
BUILD_BUG_ON(offsetof(struct htab_elem, fnode.next) !=
offsetof(struct htab_elem, hash_node.pprev));
if (lru && !capable(CAP_SYS_ADMIN))
return ERR_PTR(-EPERM);
if (attr->map_flags & ~(BPF_F_NO_PREALLOC | BPF_F_NO_COMMON_LRU))
return ERR_PTR(-EINVAL);
if (!lru && percpu_lru)
return ERR_PTR(-EINVAL);
if (lru && !prealloc)
return ERR_PTR(-ENOTSUPP);
htab = kzalloc(sizeof(*htab), GFP_USER);
if (!htab)
return ERR_PTR(-ENOMEM);
htab->map.map_type = attr->map_type;
htab->map.key_size = attr->key_size;
htab->map.value_size = attr->value_size;
htab->map.max_entries = attr->max_entries;
htab->map.map_flags = attr->map_flags;
err = -EINVAL;
if (htab->map.max_entries == 0 || htab->map.key_size == 0 ||
htab->map.value_size == 0)
goto free_htab;
if (percpu_lru) {
htab->map.max_entries = roundup(attr->max_entries,
num_possible_cpus());
if (htab->map.max_entries < attr->max_entries)
htab->map.max_entries = rounddown(attr->max_entries,
num_possible_cpus());
}
htab->n_buckets = roundup_pow_of_two(htab->map.max_entries);
err = -E2BIG;
if (htab->map.key_size > MAX_BPF_STACK)
goto free_htab;
if (htab->map.value_size >= KMALLOC_MAX_SIZE -
MAX_BPF_STACK - sizeof(struct htab_elem))
goto free_htab;
if (percpu && round_up(htab->map.value_size, 8) > PCPU_MIN_UNIT_SIZE)
goto free_htab;
htab->elem_size = sizeof(struct htab_elem) +
round_up(htab->map.key_size, 8);
if (percpu)
htab->elem_size += sizeof(void *);
else
htab->elem_size += round_up(htab->map.value_size, 8);
if (htab->n_buckets == 0 ||
htab->n_buckets > U32_MAX / sizeof(struct bucket))
goto free_htab;
cost = (u64) htab->n_buckets * sizeof(struct bucket) +
(u64) htab->elem_size * htab->map.max_entries;
if (percpu)
cost += (u64) round_up(htab->map.value_size, 8) *
num_possible_cpus() * htab->map.max_entries;
else
cost += (u64) htab->elem_size * num_possible_cpus();
if (cost >= U32_MAX - PAGE_SIZE)
goto free_htab;
htab->map.pages = round_up(cost, PAGE_SIZE) >> PAGE_SHIFT;
err = bpf_map_precharge_memlock(htab->map.pages);
if (err)
goto free_htab;
err = -ENOMEM;
htab->buckets = bpf_map_area_alloc(htab->n_buckets *
sizeof(struct bucket));
if (!htab->buckets)
goto free_htab;
for (i = 0; i < htab->n_buckets; i++) {
INIT_HLIST_NULLS_HEAD(&htab->buckets[i].head, i);
raw_spin_lock_init(&htab->buckets[i].lock);
}
if (prealloc) {
err = prealloc_init(htab);
if (err)
goto free_buckets;
if (!percpu && !lru) {
err = alloc_extra_elems(htab);
if (err)
goto free_prealloc;
}
}
return &htab->map;
free_prealloc:
prealloc_destroy(htab);
free_buckets:
bpf_map_area_free(htab->buckets);
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
static inline struct hlist_nulls_head *select_bucket(struct bpf_htab *htab, u32 hash)
{
return &__select_bucket(htab, hash)->head;
}
static struct htab_elem *lookup_elem_raw(struct hlist_nulls_head *head, u32 hash,
void *key, u32 key_size)
{
struct hlist_nulls_node *n;
struct htab_elem *l;
hlist_nulls_for_each_entry_rcu(l, n, head, hash_node)
if (l->hash == hash && !memcmp(&l->key, key, key_size))
return l;
return NULL;
}
static struct htab_elem *lookup_nulls_elem_raw(struct hlist_nulls_head *head,
u32 hash, void *key,
u32 key_size, u32 n_buckets)
{
struct hlist_nulls_node *n;
struct htab_elem *l;
again:
hlist_nulls_for_each_entry_rcu(l, n, head, hash_node)
if (l->hash == hash && !memcmp(&l->key, key, key_size))
return l;
if (unlikely(get_nulls_value(n) != (hash & (n_buckets - 1))))
goto again;
return NULL;
}
static void *__htab_map_lookup_elem(struct bpf_map *map, void *key)
{
struct bpf_htab *htab = container_of(map, struct bpf_htab, map);
struct hlist_nulls_head *head;
struct htab_elem *l;
u32 hash, key_size;
WARN_ON_ONCE(!rcu_read_lock_held());
key_size = map->key_size;
hash = htab_map_hash(key, key_size);
head = select_bucket(htab, hash);
l = lookup_nulls_elem_raw(head, hash, key, key_size, htab->n_buckets);
return l;
}
static void *htab_map_lookup_elem(struct bpf_map *map, void *key)
{
struct htab_elem *l = __htab_map_lookup_elem(map, key);
if (l)
return l->key + round_up(map->key_size, 8);
return NULL;
}
static u32 htab_map_gen_lookup(struct bpf_map *map, struct bpf_insn *insn_buf)
{
struct bpf_insn *insn = insn_buf;
const int ret = BPF_REG_0;
*insn++ = BPF_EMIT_CALL((u64 (*)(u64, u64, u64, u64, u64))__htab_map_lookup_elem);
*insn++ = BPF_JMP_IMM(BPF_JEQ, ret, 0, 1);
*insn++ = BPF_ALU64_IMM(BPF_ADD, ret,
offsetof(struct htab_elem, key) +
round_up(map->key_size, 8));
return insn - insn_buf;
}
static void *htab_lru_map_lookup_elem(struct bpf_map *map, void *key)
{
struct htab_elem *l = __htab_map_lookup_elem(map, key);
if (l) {
bpf_lru_node_set_ref(&l->lru_node);
return l->key + round_up(map->key_size, 8);
}
return NULL;
}
static bool htab_lru_map_delete_node(void *arg, struct bpf_lru_node *node)
{
struct bpf_htab *htab = (struct bpf_htab *)arg;
struct htab_elem *l = NULL, *tgt_l;
struct hlist_nulls_head *head;
struct hlist_nulls_node *n;
unsigned long flags;
struct bucket *b;
tgt_l = container_of(node, struct htab_elem, lru_node);
b = __select_bucket(htab, tgt_l->hash);
head = &b->head;
raw_spin_lock_irqsave(&b->lock, flags);
hlist_nulls_for_each_entry_rcu(l, n, head, hash_node)
if (l == tgt_l) {
hlist_nulls_del_rcu(&l->hash_node);
break;
}
raw_spin_unlock_irqrestore(&b->lock, flags);
return l == tgt_l;
}
static int htab_map_get_next_key(struct bpf_map *map, void *key, void *next_key)
{
struct bpf_htab *htab = container_of(map, struct bpf_htab, map);
struct hlist_nulls_head *head;
struct htab_elem *l, *next_l;
u32 hash, key_size;
int i = 0;
WARN_ON_ONCE(!rcu_read_lock_held());
key_size = map->key_size;
if (!key)
goto find_first_elem;
hash = htab_map_hash(key, key_size);
head = select_bucket(htab, hash);
l = lookup_nulls_elem_raw(head, hash, key, key_size, htab->n_buckets);
if (!l)
goto find_first_elem;
next_l = hlist_nulls_entry_safe(rcu_dereference_raw(hlist_nulls_next_rcu(&l->hash_node)),
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
next_l = hlist_nulls_entry_safe(rcu_dereference_raw(hlist_nulls_first_rcu(head)),
struct htab_elem, hash_node);
if (next_l) {
memcpy(next_key, next_l->key, key_size);
return 0;
}
}
return -ENOENT;
}
static void htab_elem_free(struct bpf_htab *htab, struct htab_elem *l)
{
if (htab->map.map_type == BPF_MAP_TYPE_PERCPU_HASH)
free_percpu(htab_elem_get_ptr(l, htab->map.key_size));
kfree(l);
}
static void htab_elem_free_rcu(struct rcu_head *head)
{
struct htab_elem *l = container_of(head, struct htab_elem, rcu);
struct bpf_htab *htab = l->htab;
preempt_disable();
__this_cpu_inc(bpf_prog_active);
htab_elem_free(htab, l);
__this_cpu_dec(bpf_prog_active);
preempt_enable();
}
static void free_htab_elem(struct bpf_htab *htab, struct htab_elem *l)
{
struct bpf_map *map = &htab->map;
if (map->ops->map_fd_put_ptr) {
void *ptr = fd_htab_map_get_ptr(map, l);
map->ops->map_fd_put_ptr(ptr);
}
if (htab_is_prealloc(htab)) {
pcpu_freelist_push(&htab->freelist, &l->fnode);
} else {
atomic_dec(&htab->count);
l->htab = htab;
call_rcu(&l->rcu, htab_elem_free_rcu);
}
}
static void pcpu_copy_value(struct bpf_htab *htab, void __percpu *pptr,
void *value, bool onallcpus)
{
if (!onallcpus) {
memcpy(this_cpu_ptr(pptr), value, htab->map.value_size);
} else {
u32 size = round_up(htab->map.value_size, 8);
int off = 0, cpu;
for_each_possible_cpu(cpu) {
bpf_long_memcpy(per_cpu_ptr(pptr, cpu),
value + off, size);
off += size;
}
}
}
static struct htab_elem *alloc_htab_elem(struct bpf_htab *htab, void *key,
void *value, u32 key_size, u32 hash,
bool percpu, bool onallcpus,
struct htab_elem *old_elem)
{
u32 size = htab->map.value_size;
bool prealloc = htab_is_prealloc(htab);
struct htab_elem *l_new, **pl_new;
void __percpu *pptr;
if (prealloc) {
if (old_elem) {
pl_new = this_cpu_ptr(htab->extra_elems);
l_new = *pl_new;
*pl_new = old_elem;
} else {
struct pcpu_freelist_node *l;
l = pcpu_freelist_pop(&htab->freelist);
if (!l)
return ERR_PTR(-E2BIG);
l_new = container_of(l, struct htab_elem, fnode);
}
} else {
if (atomic_inc_return(&htab->count) > htab->map.max_entries)
if (!old_elem) {
atomic_dec(&htab->count);
return ERR_PTR(-E2BIG);
}
l_new = kmalloc(htab->elem_size, GFP_ATOMIC | __GFP_NOWARN);
if (!l_new)
return ERR_PTR(-ENOMEM);
}
memcpy(l_new->key, key, key_size);
if (percpu) {
size = round_up(size, 8);
if (prealloc) {
pptr = htab_elem_get_ptr(l_new, key_size);
} else {
pptr = __alloc_percpu_gfp(size, 8,
GFP_ATOMIC | __GFP_NOWARN);
if (!pptr) {
kfree(l_new);
return ERR_PTR(-ENOMEM);
}
}
pcpu_copy_value(htab, pptr, value, onallcpus);
if (!prealloc)
htab_elem_set_ptr(l_new, key_size, pptr);
} else {
memcpy(l_new->key + round_up(key_size, 8), value, size);
}
l_new->hash = hash;
return l_new;
}
static int check_flags(struct bpf_htab *htab, struct htab_elem *l_old,
u64 map_flags)
{
if (l_old && map_flags == BPF_NOEXIST)
return -EEXIST;
if (!l_old && map_flags == BPF_EXIST)
return -ENOENT;
return 0;
}
static int htab_map_update_elem(struct bpf_map *map, void *key, void *value,
u64 map_flags)
{
struct bpf_htab *htab = container_of(map, struct bpf_htab, map);
struct htab_elem *l_new = NULL, *l_old;
struct hlist_nulls_head *head;
unsigned long flags;
struct bucket *b;
u32 key_size, hash;
int ret;
if (unlikely(map_flags > BPF_EXIST))
return -EINVAL;
WARN_ON_ONCE(!rcu_read_lock_held());
key_size = map->key_size;
hash = htab_map_hash(key, key_size);
b = __select_bucket(htab, hash);
head = &b->head;
raw_spin_lock_irqsave(&b->lock, flags);
l_old = lookup_elem_raw(head, hash, key, key_size);
ret = check_flags(htab, l_old, map_flags);
if (ret)
goto err;
l_new = alloc_htab_elem(htab, key, value, key_size, hash, false, false,
l_old);
if (IS_ERR(l_new)) {
ret = PTR_ERR(l_new);
goto err;
}
hlist_nulls_add_head_rcu(&l_new->hash_node, head);
if (l_old) {
hlist_nulls_del_rcu(&l_old->hash_node);
if (!htab_is_prealloc(htab))
free_htab_elem(htab, l_old);
}
ret = 0;
err:
raw_spin_unlock_irqrestore(&b->lock, flags);
return ret;
}
static int htab_lru_map_update_elem(struct bpf_map *map, void *key, void *value,
u64 map_flags)
{
struct bpf_htab *htab = container_of(map, struct bpf_htab, map);
struct htab_elem *l_new, *l_old = NULL;
struct hlist_nulls_head *head;
unsigned long flags;
struct bucket *b;
u32 key_size, hash;
int ret;
if (unlikely(map_flags > BPF_EXIST))
return -EINVAL;
WARN_ON_ONCE(!rcu_read_lock_held());
key_size = map->key_size;
hash = htab_map_hash(key, key_size);
b = __select_bucket(htab, hash);
head = &b->head;
l_new = prealloc_lru_pop(htab, key, hash);
if (!l_new)
return -ENOMEM;
memcpy(l_new->key + round_up(map->key_size, 8), value, map->value_size);
raw_spin_lock_irqsave(&b->lock, flags);
l_old = lookup_elem_raw(head, hash, key, key_size);
ret = check_flags(htab, l_old, map_flags);
if (ret)
goto err;
hlist_nulls_add_head_rcu(&l_new->hash_node, head);
if (l_old) {
bpf_lru_node_set_ref(&l_new->lru_node);
hlist_nulls_del_rcu(&l_old->hash_node);
}
ret = 0;
err:
raw_spin_unlock_irqrestore(&b->lock, flags);
if (ret)
bpf_lru_push_free(&htab->lru, &l_new->lru_node);
else if (l_old)
bpf_lru_push_free(&htab->lru, &l_old->lru_node);
return ret;
}
static int __htab_percpu_map_update_elem(struct bpf_map *map, void *key,
void *value, u64 map_flags,
bool onallcpus)
{
struct bpf_htab *htab = container_of(map, struct bpf_htab, map);
struct htab_elem *l_new = NULL, *l_old;
struct hlist_nulls_head *head;
unsigned long flags;
struct bucket *b;
u32 key_size, hash;
int ret;
if (unlikely(map_flags > BPF_EXIST))
return -EINVAL;
WARN_ON_ONCE(!rcu_read_lock_held());
key_size = map->key_size;
hash = htab_map_hash(key, key_size);
b = __select_bucket(htab, hash);
head = &b->head;
raw_spin_lock_irqsave(&b->lock, flags);
l_old = lookup_elem_raw(head, hash, key, key_size);
ret = check_flags(htab, l_old, map_flags);
if (ret)
goto err;
if (l_old) {
pcpu_copy_value(htab, htab_elem_get_ptr(l_old, key_size),
value, onallcpus);
} else {
l_new = alloc_htab_elem(htab, key, value, key_size,
hash, true, onallcpus, NULL);
if (IS_ERR(l_new)) {
ret = PTR_ERR(l_new);
goto err;
}
hlist_nulls_add_head_rcu(&l_new->hash_node, head);
}
ret = 0;
err:
raw_spin_unlock_irqrestore(&b->lock, flags);
return ret;
}
static int __htab_lru_percpu_map_update_elem(struct bpf_map *map, void *key,
void *value, u64 map_flags,
bool onallcpus)
{
struct bpf_htab *htab = container_of(map, struct bpf_htab, map);
struct htab_elem *l_new = NULL, *l_old;
struct hlist_nulls_head *head;
unsigned long flags;
struct bucket *b;
u32 key_size, hash;
int ret;
if (unlikely(map_flags > BPF_EXIST))
return -EINVAL;
WARN_ON_ONCE(!rcu_read_lock_held());
key_size = map->key_size;
hash = htab_map_hash(key, key_size);
b = __select_bucket(htab, hash);
head = &b->head;
if (map_flags != BPF_EXIST) {
l_new = prealloc_lru_pop(htab, key, hash);
if (!l_new)
return -ENOMEM;
}
raw_spin_lock_irqsave(&b->lock, flags);
l_old = lookup_elem_raw(head, hash, key, key_size);
ret = check_flags(htab, l_old, map_flags);
if (ret)
goto err;
if (l_old) {
bpf_lru_node_set_ref(&l_old->lru_node);
pcpu_copy_value(htab, htab_elem_get_ptr(l_old, key_size),
value, onallcpus);
} else {
pcpu_copy_value(htab, htab_elem_get_ptr(l_new, key_size),
value, onallcpus);
hlist_nulls_add_head_rcu(&l_new->hash_node, head);
l_new = NULL;
}
ret = 0;
err:
raw_spin_unlock_irqrestore(&b->lock, flags);
if (l_new)
bpf_lru_push_free(&htab->lru, &l_new->lru_node);
return ret;
}
static int htab_percpu_map_update_elem(struct bpf_map *map, void *key,
void *value, u64 map_flags)
{
return __htab_percpu_map_update_elem(map, key, value, map_flags, false);
}
static int htab_lru_percpu_map_update_elem(struct bpf_map *map, void *key,
void *value, u64 map_flags)
{
return __htab_lru_percpu_map_update_elem(map, key, value, map_flags,
false);
}
static int htab_map_delete_elem(struct bpf_map *map, void *key)
{
struct bpf_htab *htab = container_of(map, struct bpf_htab, map);
struct hlist_nulls_head *head;
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
hlist_nulls_del_rcu(&l->hash_node);
free_htab_elem(htab, l);
ret = 0;
}
raw_spin_unlock_irqrestore(&b->lock, flags);
return ret;
}
static int htab_lru_map_delete_elem(struct bpf_map *map, void *key)
{
struct bpf_htab *htab = container_of(map, struct bpf_htab, map);
struct hlist_nulls_head *head;
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
hlist_nulls_del_rcu(&l->hash_node);
ret = 0;
}
raw_spin_unlock_irqrestore(&b->lock, flags);
if (l)
bpf_lru_push_free(&htab->lru, &l->lru_node);
return ret;
}
static void delete_all_elements(struct bpf_htab *htab)
{
int i;
for (i = 0; i < htab->n_buckets; i++) {
struct hlist_nulls_head *head = select_bucket(htab, i);
struct hlist_nulls_node *n;
struct htab_elem *l;
hlist_nulls_for_each_entry_safe(l, n, head, hash_node) {
hlist_nulls_del_rcu(&l->hash_node);
htab_elem_free(htab, l);
}
}
}
static void htab_map_free(struct bpf_map *map)
{
struct bpf_htab *htab = container_of(map, struct bpf_htab, map);
synchronize_rcu();
rcu_barrier();
if (!htab_is_prealloc(htab))
delete_all_elements(htab);
else
prealloc_destroy(htab);
free_percpu(htab->extra_elems);
bpf_map_area_free(htab->buckets);
kfree(htab);
}
static void *htab_percpu_map_lookup_elem(struct bpf_map *map, void *key)
{
struct htab_elem *l = __htab_map_lookup_elem(map, key);
if (l)
return this_cpu_ptr(htab_elem_get_ptr(l, map->key_size));
else
return NULL;
}
static void *htab_lru_percpu_map_lookup_elem(struct bpf_map *map, void *key)
{
struct htab_elem *l = __htab_map_lookup_elem(map, key);
if (l) {
bpf_lru_node_set_ref(&l->lru_node);
return this_cpu_ptr(htab_elem_get_ptr(l, map->key_size));
}
return NULL;
}
int bpf_percpu_hash_copy(struct bpf_map *map, void *key, void *value)
{
struct bpf_htab *htab = container_of(map, struct bpf_htab, map);
struct htab_elem *l;
void __percpu *pptr;
int ret = -ENOENT;
int cpu, off = 0;
u32 size;
size = round_up(map->value_size, 8);
rcu_read_lock();
l = __htab_map_lookup_elem(map, key);
if (!l)
goto out;
if (htab_is_lru(htab))
bpf_lru_node_set_ref(&l->lru_node);
pptr = htab_elem_get_ptr(l, map->key_size);
for_each_possible_cpu(cpu) {
bpf_long_memcpy(value + off,
per_cpu_ptr(pptr, cpu), size);
off += size;
}
ret = 0;
out:
rcu_read_unlock();
return ret;
}
int bpf_percpu_hash_update(struct bpf_map *map, void *key, void *value,
u64 map_flags)
{
struct bpf_htab *htab = container_of(map, struct bpf_htab, map);
int ret;
rcu_read_lock();
if (htab_is_lru(htab))
ret = __htab_lru_percpu_map_update_elem(map, key, value,
map_flags, true);
else
ret = __htab_percpu_map_update_elem(map, key, value, map_flags,
true);
rcu_read_unlock();
return ret;
}
static struct bpf_map *fd_htab_map_alloc(union bpf_attr *attr)
{
struct bpf_map *map;
if (attr->value_size != sizeof(u32))
return ERR_PTR(-EINVAL);
attr->value_size = sizeof(void *);
map = htab_map_alloc(attr);
attr->value_size = sizeof(u32);
return map;
}
static void fd_htab_map_free(struct bpf_map *map)
{
struct bpf_htab *htab = container_of(map, struct bpf_htab, map);
struct hlist_nulls_node *n;
struct hlist_nulls_head *head;
struct htab_elem *l;
int i;
for (i = 0; i < htab->n_buckets; i++) {
head = select_bucket(htab, i);
hlist_nulls_for_each_entry_safe(l, n, head, hash_node) {
void *ptr = fd_htab_map_get_ptr(map, l);
map->ops->map_fd_put_ptr(ptr);
}
}
htab_map_free(map);
}
int bpf_fd_htab_map_update_elem(struct bpf_map *map, struct file *map_file,
void *key, void *value, u64 map_flags)
{
void *ptr;
int ret;
u32 ufd = *(u32 *)value;
ptr = map->ops->map_fd_get_ptr(map, map_file, ufd);
if (IS_ERR(ptr))
return PTR_ERR(ptr);
ret = htab_map_update_elem(map, key, &ptr, map_flags);
if (ret)
map->ops->map_fd_put_ptr(ptr);
return ret;
}
static struct bpf_map *htab_of_map_alloc(union bpf_attr *attr)
{
struct bpf_map *map, *inner_map_meta;
inner_map_meta = bpf_map_meta_alloc(attr->inner_map_fd);
if (IS_ERR(inner_map_meta))
return inner_map_meta;
map = fd_htab_map_alloc(attr);
if (IS_ERR(map)) {
bpf_map_meta_free(inner_map_meta);
return map;
}
map->inner_map_meta = inner_map_meta;
return map;
}
static void *htab_of_map_lookup_elem(struct bpf_map *map, void *key)
{
struct bpf_map **inner_map = htab_map_lookup_elem(map, key);
if (!inner_map)
return NULL;
return READ_ONCE(*inner_map);
}
static void htab_of_map_free(struct bpf_map *map)
{
bpf_map_meta_free(map->inner_map_meta);
fd_htab_map_free(map);
}
