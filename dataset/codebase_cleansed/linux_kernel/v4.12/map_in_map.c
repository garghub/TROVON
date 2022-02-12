struct bpf_map *bpf_map_meta_alloc(int inner_map_ufd)
{
struct bpf_map *inner_map, *inner_map_meta;
struct fd f;
f = fdget(inner_map_ufd);
inner_map = __bpf_map_get(f);
if (IS_ERR(inner_map))
return inner_map;
if (inner_map->map_type == BPF_MAP_TYPE_PROG_ARRAY) {
fdput(f);
return ERR_PTR(-ENOTSUPP);
}
if (inner_map->inner_map_meta) {
fdput(f);
return ERR_PTR(-EINVAL);
}
inner_map_meta = kzalloc(sizeof(*inner_map_meta), GFP_USER);
if (!inner_map_meta) {
fdput(f);
return ERR_PTR(-ENOMEM);
}
inner_map_meta->map_type = inner_map->map_type;
inner_map_meta->key_size = inner_map->key_size;
inner_map_meta->value_size = inner_map->value_size;
inner_map_meta->map_flags = inner_map->map_flags;
inner_map_meta->ops = inner_map->ops;
inner_map_meta->max_entries = inner_map->max_entries;
fdput(f);
return inner_map_meta;
}
void bpf_map_meta_free(struct bpf_map *map_meta)
{
kfree(map_meta);
}
bool bpf_map_meta_equal(const struct bpf_map *meta0,
const struct bpf_map *meta1)
{
return meta0->map_type == meta1->map_type &&
meta0->key_size == meta1->key_size &&
meta0->value_size == meta1->value_size &&
meta0->map_flags == meta1->map_flags &&
meta0->max_entries == meta1->max_entries;
}
void *bpf_map_fd_get_ptr(struct bpf_map *map,
struct file *map_file ,
int ufd)
{
struct bpf_map *inner_map;
struct fd f;
f = fdget(ufd);
inner_map = __bpf_map_get(f);
if (IS_ERR(inner_map))
return inner_map;
if (bpf_map_meta_equal(map->inner_map_meta, inner_map))
inner_map = bpf_map_inc(inner_map, false);
else
inner_map = ERR_PTR(-EINVAL);
fdput(f);
return inner_map;
}
void bpf_map_fd_put_ptr(void *ptr)
{
bpf_map_put(ptr);
}
