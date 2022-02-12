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
int xdp_redirect_prog(struct xdp_md *ctx)
{
void *data_end = (void *)(long)ctx->data_end;
void *data = (void *)(long)ctx->data;
struct ethhdr *eth = data;
int rc = XDP_DROP;
int *ifindex, port = 0;
long *value;
u32 key = 0;
u64 nh_off;
nh_off = sizeof(*eth);
if (data + nh_off > data_end)
return rc;
ifindex = bpf_map_lookup_elem(&tx_port, &port);
if (!ifindex)
return rc;
value = bpf_map_lookup_elem(&rxcnt, &key);
if (value)
*value += 1;
swap_src_dst_mac(data);
return bpf_redirect(*ifindex, 0);
}
int xdp_redirect_dummy_prog(struct xdp_md *ctx)
{
return XDP_PASS;
}
