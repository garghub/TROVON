static struct bpf_map *array_map_alloc(union bpf_attr *attr)
{
struct bpf_array *array;
u32 elem_size, array_size;
if (attr->max_entries == 0 || attr->key_size != 4 ||
attr->value_size == 0)
return ERR_PTR(-EINVAL);
elem_size = round_up(attr->value_size, 8);
if (elem_size == 0 ||
attr->max_entries > (U32_MAX - sizeof(*array)) / elem_size)
return ERR_PTR(-ENOMEM);
array_size = sizeof(*array) + attr->max_entries * elem_size;
array = kzalloc(array_size, GFP_USER | __GFP_NOWARN);
if (!array) {
array = vzalloc(array_size);
if (!array)
return ERR_PTR(-ENOMEM);
}
array->map.key_size = attr->key_size;
array->map.value_size = attr->value_size;
array->map.max_entries = attr->max_entries;
array->elem_size = elem_size;
return &array->map;
}
static void *array_map_lookup_elem(struct bpf_map *map, void *key)
{
struct bpf_array *array = container_of(map, struct bpf_array, map);
u32 index = *(u32 *)key;
if (index >= array->map.max_entries)
return NULL;
return array->value + array->elem_size * index;
}
static int array_map_get_next_key(struct bpf_map *map, void *key, void *next_key)
{
struct bpf_array *array = container_of(map, struct bpf_array, map);
u32 index = *(u32 *)key;
u32 *next = (u32 *)next_key;
if (index >= array->map.max_entries) {
*next = 0;
return 0;
}
if (index == array->map.max_entries - 1)
return -ENOENT;
*next = index + 1;
return 0;
}
static int array_map_update_elem(struct bpf_map *map, void *key, void *value,
u64 map_flags)
{
struct bpf_array *array = container_of(map, struct bpf_array, map);
u32 index = *(u32 *)key;
if (map_flags > BPF_EXIST)
return -EINVAL;
if (index >= array->map.max_entries)
return -E2BIG;
if (map_flags == BPF_NOEXIST)
return -EEXIST;
memcpy(array->value + array->elem_size * index, value, array->elem_size);
return 0;
}
static int array_map_delete_elem(struct bpf_map *map, void *key)
{
return -EINVAL;
}
static void array_map_free(struct bpf_map *map)
{
struct bpf_array *array = container_of(map, struct bpf_array, map);
synchronize_rcu();
kvfree(array);
}
static int __init register_array_map(void)
{
bpf_register_map_type(&array_type);
return 0;
}
static struct bpf_map *fd_array_map_alloc(union bpf_attr *attr)
{
if (attr->value_size != sizeof(u32))
return ERR_PTR(-EINVAL);
return array_map_alloc(attr);
}
static void fd_array_map_free(struct bpf_map *map)
{
struct bpf_array *array = container_of(map, struct bpf_array, map);
int i;
synchronize_rcu();
for (i = 0; i < array->map.max_entries; i++)
BUG_ON(array->ptrs[i] != NULL);
kvfree(array);
}
static void *fd_array_map_lookup_elem(struct bpf_map *map, void *key)
{
return NULL;
}
static int fd_array_map_update_elem(struct bpf_map *map, void *key,
void *value, u64 map_flags)
{
struct bpf_array *array = container_of(map, struct bpf_array, map);
void *new_ptr, *old_ptr;
u32 index = *(u32 *)key, ufd;
if (map_flags != BPF_ANY)
return -EINVAL;
if (index >= array->map.max_entries)
return -E2BIG;
ufd = *(u32 *)value;
new_ptr = map->ops->map_fd_get_ptr(map, ufd);
if (IS_ERR(new_ptr))
return PTR_ERR(new_ptr);
old_ptr = xchg(array->ptrs + index, new_ptr);
if (old_ptr)
map->ops->map_fd_put_ptr(old_ptr);
return 0;
}
static int fd_array_map_delete_elem(struct bpf_map *map, void *key)
{
struct bpf_array *array = container_of(map, struct bpf_array, map);
void *old_ptr;
u32 index = *(u32 *)key;
if (index >= array->map.max_entries)
return -E2BIG;
old_ptr = xchg(array->ptrs + index, NULL);
if (old_ptr) {
map->ops->map_fd_put_ptr(old_ptr);
return 0;
} else {
return -ENOENT;
}
}
static void *prog_fd_array_get_ptr(struct bpf_map *map, int fd)
{
struct bpf_array *array = container_of(map, struct bpf_array, map);
struct bpf_prog *prog = bpf_prog_get(fd);
if (IS_ERR(prog))
return prog;
if (!bpf_prog_array_compatible(array, prog)) {
bpf_prog_put(prog);
return ERR_PTR(-EINVAL);
}
return prog;
}
static void prog_fd_array_put_ptr(void *ptr)
{
struct bpf_prog *prog = ptr;
bpf_prog_put_rcu(prog);
}
void bpf_fd_array_map_clear(struct bpf_map *map)
{
struct bpf_array *array = container_of(map, struct bpf_array, map);
int i;
for (i = 0; i < array->map.max_entries; i++)
fd_array_map_delete_elem(map, &i);
}
static int __init register_prog_array_map(void)
{
bpf_register_map_type(&prog_array_type);
return 0;
}
static void perf_event_array_map_free(struct bpf_map *map)
{
bpf_fd_array_map_clear(map);
fd_array_map_free(map);
}
static void *perf_event_fd_array_get_ptr(struct bpf_map *map, int fd)
{
struct perf_event *event;
const struct perf_event_attr *attr;
event = perf_event_get(fd);
if (IS_ERR(event))
return event;
attr = perf_event_attrs(event);
if (IS_ERR(attr))
return (void *)attr;
if (attr->type != PERF_TYPE_RAW &&
attr->type != PERF_TYPE_HARDWARE) {
perf_event_release_kernel(event);
return ERR_PTR(-EINVAL);
}
return event;
}
static void perf_event_fd_array_put_ptr(void *ptr)
{
struct perf_event *event = ptr;
perf_event_release_kernel(event);
}
static int __init register_perf_event_array_map(void)
{
bpf_register_map_type(&perf_event_array_type);
return 0;
}
