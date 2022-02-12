int bpf_prog1(struct pt_regs *ctx)
{
long rq = ctx->di;
u64 val = bpf_ktime_get_ns();
bpf_map_update_elem(&my_map, &rq, &val, BPF_ANY);
return 0;
}
static unsigned int log2l(unsigned long long n)
{
#define S(k) if (n >= (1ull << k)) { i += k; n >>= k; }
int i = -(n == 0);
S(32); S(16); S(8); S(4); S(2); S(1);
return i;
#undef S
}
int bpf_prog2(struct pt_regs *ctx)
{
long rq = ctx->di;
u64 *value, l, base;
u32 index;
value = bpf_map_lookup_elem(&my_map, &rq);
if (!value)
return 0;
u64 cur_time = bpf_ktime_get_ns();
u64 delta = cur_time - *value;
bpf_map_delete_elem(&my_map, &rq);
l = log2l(delta);
base = 1ll << l;
index = (l * 64 + (delta - base) * 64 / base) * 3 / 64;
if (index >= SLOTS)
index = SLOTS - 1;
value = bpf_map_lookup_elem(&lat_map, &index);
if (value)
__sync_fetch_and_add((long *)value, 1);
return 0;
}
