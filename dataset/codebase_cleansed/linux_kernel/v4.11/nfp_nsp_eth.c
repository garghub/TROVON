static unsigned int nfp_eth_rate(enum nfp_eth_rate rate)
{
unsigned int rate_xlate[] = {
[RATE_INVALID] = 0,
[RATE_10M] = SPEED_10,
[RATE_100M] = SPEED_100,
[RATE_1G] = SPEED_1000,
[RATE_10G] = SPEED_10000,
[RATE_25G] = SPEED_25000,
};
if (rate >= ARRAY_SIZE(rate_xlate))
return 0;
return rate_xlate[rate];
}
static void nfp_eth_copy_mac_reverse(u8 *dst, const u8 *src)
{
int i;
for (i = 0; i < ETH_ALEN; i++)
dst[ETH_ALEN - i - 1] = src[i];
}
static void
nfp_eth_port_translate(const struct eth_table_entry *src, unsigned int index,
struct nfp_eth_table_port *dst)
{
unsigned int rate;
u64 port, state;
port = le64_to_cpu(src->port);
state = le64_to_cpu(src->state);
dst->eth_index = FIELD_GET(NSP_ETH_PORT_INDEX, port);
dst->index = index;
dst->nbi = index / NSP_ETH_NBI_PORT_COUNT;
dst->base = index % NSP_ETH_NBI_PORT_COUNT;
dst->lanes = FIELD_GET(NSP_ETH_PORT_LANES, port);
dst->enabled = FIELD_GET(NSP_ETH_STATE_ENABLED, state);
dst->tx_enabled = FIELD_GET(NSP_ETH_STATE_TX_ENABLED, state);
dst->rx_enabled = FIELD_GET(NSP_ETH_STATE_RX_ENABLED, state);
rate = nfp_eth_rate(FIELD_GET(NSP_ETH_STATE_RATE, state));
dst->speed = dst->lanes * rate;
nfp_eth_copy_mac_reverse(dst->mac_addr, src->mac_addr);
snprintf(dst->label, sizeof(dst->label) - 1, "%llu.%llu",
FIELD_GET(NSP_ETH_PORT_PHYLABEL, port),
FIELD_GET(NSP_ETH_PORT_LABEL, port));
}
struct nfp_eth_table *nfp_eth_read_ports(struct nfp_cpp *cpp)
{
struct nfp_eth_table *ret;
struct nfp_nsp *nsp;
nsp = nfp_nsp_open(cpp);
if (IS_ERR(nsp))
return NULL;
ret = __nfp_eth_read_ports(cpp, nsp);
nfp_nsp_close(nsp);
return ret;
}
struct nfp_eth_table *
__nfp_eth_read_ports(struct nfp_cpp *cpp, struct nfp_nsp *nsp)
{
struct eth_table_entry *entries;
struct nfp_eth_table *table;
unsigned int cnt;
int i, j, ret;
entries = kzalloc(NSP_ETH_TABLE_SIZE, GFP_KERNEL);
if (!entries)
return NULL;
ret = nfp_nsp_read_eth_table(nsp, entries, NSP_ETH_TABLE_SIZE);
if (ret < 0) {
nfp_err(cpp, "reading port table failed %d\n", ret);
kfree(entries);
return NULL;
}
cnt = ret;
if (!cnt) {
for (i = 0; i < NSP_ETH_MAX_COUNT; i++)
if (entries[i].port & NSP_ETH_PORT_LANES_MASK)
cnt++;
}
table = kzalloc(sizeof(*table) +
sizeof(struct nfp_eth_table_port) * cnt, GFP_KERNEL);
if (!table) {
kfree(entries);
return NULL;
}
table->count = cnt;
for (i = 0, j = 0; i < NSP_ETH_MAX_COUNT; i++)
if (entries[i].port & NSP_ETH_PORT_LANES_MASK)
nfp_eth_port_translate(&entries[i], i,
&table->ports[j++]);
kfree(entries);
return table;
}
int nfp_eth_set_mod_enable(struct nfp_cpp *cpp, unsigned int idx, bool enable)
{
struct eth_table_entry *entries;
struct nfp_nsp *nsp;
u64 reg;
int ret;
entries = kzalloc(NSP_ETH_TABLE_SIZE, GFP_KERNEL);
if (!entries)
return -ENOMEM;
nsp = nfp_nsp_open(cpp);
if (IS_ERR(nsp)) {
kfree(entries);
return PTR_ERR(nsp);
}
ret = nfp_nsp_read_eth_table(nsp, entries, NSP_ETH_TABLE_SIZE);
if (ret < 0) {
nfp_err(cpp, "reading port table failed %d\n", ret);
goto exit_close_nsp;
}
if (!(entries[idx].port & NSP_ETH_PORT_LANES_MASK)) {
nfp_warn(cpp, "trying to set port state on disabled port %d\n",
idx);
ret = -EINVAL;
goto exit_close_nsp;
}
reg = le64_to_cpu(entries[idx].state);
if (enable == FIELD_GET(NSP_ETH_CTRL_ENABLED, reg)) {
ret = 0;
goto exit_close_nsp;
}
reg = le64_to_cpu(entries[idx].control);
reg &= ~NSP_ETH_CTRL_ENABLED;
reg |= FIELD_PREP(NSP_ETH_CTRL_ENABLED, enable);
entries[idx].control = cpu_to_le64(reg);
ret = nfp_nsp_write_eth_table(nsp, entries, NSP_ETH_TABLE_SIZE);
exit_close_nsp:
nfp_nsp_close(nsp);
kfree(entries);
return ret < 0 ? ret : 0;
}
