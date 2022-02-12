static int prealloc_elems_and_freelist(struct bpf_stack_map *smap)
{
u32 elem_size = sizeof(struct stack_map_bucket) + smap->map.value_size;
int err;
smap->elems = vzalloc(elem_size * smap->map.max_entries);
if (!smap->elems)
return -ENOMEM;
err = pcpu_freelist_init(&smap->freelist);
if (err)
goto free_elems;
pcpu_freelist_populate(&smap->freelist, smap->elems, elem_size,
smap->map.max_entries);
return 0;
free_elems:
vfree(smap->elems);
return err;
}
static struct bpf_map *stack_map_alloc(union bpf_attr *attr)
{
u32 value_size = attr->value_size;
struct bpf_stack_map *smap;
u64 cost, n_buckets;
int err;
if (!capable(CAP_SYS_ADMIN))
return ERR_PTR(-EPERM);
if (attr->map_flags)
return ERR_PTR(-EINVAL);
if (attr->max_entries == 0 || attr->key_size != 4 ||
value_size < 8 || value_size % 8 ||
value_size / 8 > sysctl_perf_event_max_stack)
return ERR_PTR(-EINVAL);
n_buckets = roundup_pow_of_two(attr->max_entries);
cost = n_buckets * sizeof(struct stack_map_bucket *) + sizeof(*smap);
if (cost >= U32_MAX - PAGE_SIZE)
return ERR_PTR(-E2BIG);
smap = kzalloc(cost, GFP_USER | __GFP_NOWARN);
if (!smap) {
smap = vzalloc(cost);
if (!smap)
return ERR_PTR(-ENOMEM);
}
err = -E2BIG;
cost += n_buckets * (value_size + sizeof(struct stack_map_bucket));
if (cost >= U32_MAX - PAGE_SIZE)
goto free_smap;
smap->map.map_type = attr->map_type;
smap->map.key_size = attr->key_size;
smap->map.value_size = value_size;
smap->map.max_entries = attr->max_entries;
smap->n_buckets = n_buckets;
smap->map.pages = round_up(cost, PAGE_SIZE) >> PAGE_SHIFT;
err = bpf_map_precharge_memlock(smap->map.pages);
if (err)
goto free_smap;
err = get_callchain_buffers();
if (err)
goto free_smap;
err = prealloc_elems_and_freelist(smap);
if (err)
goto put_buffers;
return &smap->map;
put_buffers:
put_callchain_buffers();
free_smap:
kvfree(smap);
return ERR_PTR(err);
}
u64 bpf_get_stackid(u64 r1, u64 r2, u64 flags, u64 r4, u64 r5)
{
struct pt_regs *regs = (struct pt_regs *) (long) r1;
struct bpf_map *map = (struct bpf_map *) (long) r2;
struct bpf_stack_map *smap = container_of(map, struct bpf_stack_map, map);
struct perf_callchain_entry *trace;
struct stack_map_bucket *bucket, *new_bucket, *old_bucket;
u32 max_depth = map->value_size / 8;
u32 init_nr = sysctl_perf_event_max_stack - max_depth;
u32 skip = flags & BPF_F_SKIP_FIELD_MASK;
u32 hash, id, trace_nr, trace_len;
bool user = flags & BPF_F_USER_STACK;
bool kernel = !user;
u64 *ips;
if (unlikely(flags & ~(BPF_F_SKIP_FIELD_MASK | BPF_F_USER_STACK |
BPF_F_FAST_STACK_CMP | BPF_F_REUSE_STACKID)))
return -EINVAL;
trace = get_perf_callchain(regs, init_nr, kernel, user,
sysctl_perf_event_max_stack, false, false);
if (unlikely(!trace))
return -EFAULT;
trace_nr = trace->nr - init_nr;
if (trace_nr <= skip)
return -EFAULT;
trace_nr -= skip;
trace_len = trace_nr * sizeof(u64);
ips = trace->ip + skip + init_nr;
hash = jhash2((u32 *)ips, trace_len / sizeof(u32), 0);
id = hash & (smap->n_buckets - 1);
bucket = READ_ONCE(smap->buckets[id]);
if (bucket && bucket->hash == hash) {
if (flags & BPF_F_FAST_STACK_CMP)
return id;
if (bucket->nr == trace_nr &&
memcmp(bucket->ip, ips, trace_len) == 0)
return id;
}
if (bucket && !(flags & BPF_F_REUSE_STACKID))
return -EEXIST;
new_bucket = (struct stack_map_bucket *)
pcpu_freelist_pop(&smap->freelist);
if (unlikely(!new_bucket))
return -ENOMEM;
memcpy(new_bucket->ip, ips, trace_len);
new_bucket->hash = hash;
new_bucket->nr = trace_nr;
old_bucket = xchg(&smap->buckets[id], new_bucket);
if (old_bucket)
pcpu_freelist_push(&smap->freelist, &old_bucket->fnode);
return id;
}
static void *stack_map_lookup_elem(struct bpf_map *map, void *key)
{
return NULL;
}
int bpf_stackmap_copy(struct bpf_map *map, void *key, void *value)
{
struct bpf_stack_map *smap = container_of(map, struct bpf_stack_map, map);
struct stack_map_bucket *bucket, *old_bucket;
u32 id = *(u32 *)key, trace_len;
if (unlikely(id >= smap->n_buckets))
return -ENOENT;
bucket = xchg(&smap->buckets[id], NULL);
if (!bucket)
return -ENOENT;
trace_len = bucket->nr * sizeof(u64);
memcpy(value, bucket->ip, trace_len);
memset(value + trace_len, 0, map->value_size - trace_len);
old_bucket = xchg(&smap->buckets[id], bucket);
if (old_bucket)
pcpu_freelist_push(&smap->freelist, &old_bucket->fnode);
return 0;
}
static int stack_map_get_next_key(struct bpf_map *map, void *key, void *next_key)
{
return -EINVAL;
}
static int stack_map_update_elem(struct bpf_map *map, void *key, void *value,
u64 map_flags)
{
return -EINVAL;
}
static int stack_map_delete_elem(struct bpf_map *map, void *key)
{
struct bpf_stack_map *smap = container_of(map, struct bpf_stack_map, map);
struct stack_map_bucket *old_bucket;
u32 id = *(u32 *)key;
if (unlikely(id >= smap->n_buckets))
return -E2BIG;
old_bucket = xchg(&smap->buckets[id], NULL);
if (old_bucket) {
pcpu_freelist_push(&smap->freelist, &old_bucket->fnode);
return 0;
} else {
return -ENOENT;
}
}
static void stack_map_free(struct bpf_map *map)
{
struct bpf_stack_map *smap = container_of(map, struct bpf_stack_map, map);
synchronize_rcu();
vfree(smap->elems);
pcpu_freelist_destroy(&smap->freelist);
kvfree(smap);
put_callchain_buffers();
}
static int __init register_stack_map(void)
{
bpf_register_map_type(&stack_map_type);
return 0;
}
