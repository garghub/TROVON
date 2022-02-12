static void swap_src_dst_mac(void *data)
{
unsigned short *p = data;
unsigned short dst[3];
dst[0] = p[0];
dst[1] = p[1];
dst[2] = p[2];
p[0] = p[3];
p[1] = p[4];
p[2] = p[5];
p[3] = dst[0];
p[4] = dst[1];
p[5] = dst[2];
}
int xdp_redirect_map_prog(struct xdp_md *ctx)
{
void *data_end = (void *)(long)ctx->data_end;
void *data = (void *)(long)ctx->data;
struct ethhdr *eth = data;
int rc = XDP_DROP;
int vport, port = 0, m = 0;
long *value;
u32 key = 0;
u64 nh_off;
nh_off = sizeof(*eth);
if (data + nh_off > data_end)
return rc;
vport = 0;
value = bpf_map_lookup_elem(&rxcnt, &key);
if (value)
*value += 1;
swap_src_dst_mac(data);
return bpf_redirect_map(&tx_port, vport, 0);
}
int xdp_redirect_dummy_prog(struct xdp_md *ctx)
{
return XDP_PASS;
}
