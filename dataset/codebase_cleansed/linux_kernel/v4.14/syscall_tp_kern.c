static __always_inline void count(void *map)
{
u32 key = 0;
u32 *value, init_val = 1;
value = bpf_map_lookup_elem(map, &key);
if (value)
*value += 1;
else
bpf_map_update_elem(map, &key, &init_val, BPF_NOEXIST);
}
int trace_enter_open(struct syscalls_enter_open_args *ctx)
{
count((void *)&enter_open_map);
return 0;
}
int trace_enter_exit(struct syscalls_exit_open_args *ctx)
{
count((void *)&exit_open_map);
return 0;
}
