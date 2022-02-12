static unsigned int nfp_eth_rate2speed(enum nfp_eth_rate rate)
{
int i;
for (i = 0; i < ARRAY_SIZE(nsp_eth_rate_tbl); i++)
if (nsp_eth_rate_tbl[i].rate == rate)
return nsp_eth_rate_tbl[i].speed;
return 0;
}
static unsigned int nfp_eth_speed2rate(unsigned int speed)
{
int i;
for (i = 0; i < ARRAY_SIZE(nsp_eth_rate_tbl); i++)
if (nsp_eth_rate_tbl[i].speed == speed)
return nsp_eth_rate_tbl[i].rate;
return RATE_INVALID;
}
static void nfp_eth_copy_mac_reverse(u8 *dst, const u8 *src)
{
int i;
for (i = 0; i < ETH_ALEN; i++)
dst[ETH_ALEN - i - 1] = src[i];
}
static void
nfp_eth_port_translate(struct nfp_nsp *nsp, const union eth_table_entry *src,
unsigned int index, struct nfp_eth_table_port *dst)
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
rate = nfp_eth_rate2speed(FIELD_GET(NSP_ETH_STATE_RATE, state));
dst->speed = dst->lanes * rate;
dst->interface = FIELD_GET(NSP_ETH_STATE_INTERFACE, state);
dst->media = FIELD_GET(NSP_ETH_STATE_MEDIA, state);
nfp_eth_copy_mac_reverse(dst->mac_addr, src->mac_addr);
dst->label_port = FIELD_GET(NSP_ETH_PORT_PHYLABEL, port);
dst->label_subport = FIELD_GET(NSP_ETH_PORT_LABEL, port);
if (nfp_nsp_get_abi_ver_minor(nsp) < 17)
return;
dst->override_changed = FIELD_GET(NSP_ETH_STATE_OVRD_CHNG, state);
dst->aneg = FIELD_GET(NSP_ETH_STATE_ANEG, state);
}
static void
nfp_eth_calc_port_geometry(struct nfp_cpp *cpp, struct nfp_eth_table *table)
{
unsigned int i, j;
for (i = 0; i < table->count; i++) {
table->max_index = max(table->max_index, table->ports[i].index);
for (j = 0; j < table->count; j++) {
if (table->ports[i].label_port !=
table->ports[j].label_port)
continue;
table->ports[i].port_lanes += table->ports[j].lanes;
if (i == j)
continue;
if (table->ports[i].label_subport ==
table->ports[j].label_subport)
nfp_warn(cpp,
"Port %d subport %d is a duplicate\n",
table->ports[i].label_port,
table->ports[i].label_subport);
table->ports[i].is_split = true;
}
}
}
static void
nfp_eth_calc_port_type(struct nfp_cpp *cpp, struct nfp_eth_table_port *entry)
{
if (entry->interface == NFP_INTERFACE_NONE) {
entry->port_type = PORT_NONE;
return;
}
if (entry->media == NFP_MEDIA_FIBRE)
entry->port_type = PORT_FIBRE;
else
entry->port_type = PORT_DA;
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
union eth_table_entry *entries;
struct nfp_eth_table *table;
int i, j, ret, cnt = 0;
entries = kzalloc(NSP_ETH_TABLE_SIZE, GFP_KERNEL);
if (!entries)
return NULL;
ret = nfp_nsp_read_eth_table(nsp, entries, NSP_ETH_TABLE_SIZE);
if (ret < 0) {
nfp_err(cpp, "reading port table failed %d\n", ret);
goto err;
}
for (i = 0; i < NSP_ETH_MAX_COUNT; i++)
if (entries[i].port & NSP_ETH_PORT_LANES_MASK)
cnt++;
if (ret && ret != cnt) {
nfp_err(cpp, "table entry count reported (%d) does not match entries present (%d)\n",
ret, cnt);
goto err;
}
table = kzalloc(sizeof(*table) +
sizeof(struct nfp_eth_table_port) * cnt, GFP_KERNEL);
if (!table)
goto err;
table->count = cnt;
for (i = 0, j = 0; i < NSP_ETH_MAX_COUNT; i++)
if (entries[i].port & NSP_ETH_PORT_LANES_MASK)
nfp_eth_port_translate(nsp, &entries[i], i,
&table->ports[j++]);
nfp_eth_calc_port_geometry(cpp, table);
for (i = 0; i < table->count; i++)
nfp_eth_calc_port_type(cpp, &table->ports[i]);
kfree(entries);
return table;
err:
kfree(entries);
return NULL;
}
struct nfp_nsp *nfp_eth_config_start(struct nfp_cpp *cpp, unsigned int idx)
{
union eth_table_entry *entries;
struct nfp_nsp *nsp;
int ret;
entries = kzalloc(NSP_ETH_TABLE_SIZE, GFP_KERNEL);
if (!entries)
return ERR_PTR(-ENOMEM);
nsp = nfp_nsp_open(cpp);
if (IS_ERR(nsp)) {
kfree(entries);
return nsp;
}
ret = nfp_nsp_read_eth_table(nsp, entries, NSP_ETH_TABLE_SIZE);
if (ret < 0) {
nfp_err(cpp, "reading port table failed %d\n", ret);
goto err;
}
if (!(entries[idx].port & NSP_ETH_PORT_LANES_MASK)) {
nfp_warn(cpp, "trying to set port state on disabled port %d\n",
idx);
goto err;
}
nfp_nsp_config_set_state(nsp, entries, idx);
return nsp;
err:
nfp_nsp_close(nsp);
kfree(entries);
return ERR_PTR(-EIO);
}
void nfp_eth_config_cleanup_end(struct nfp_nsp *nsp)
{
union eth_table_entry *entries = nfp_nsp_config_entries(nsp);
nfp_nsp_config_set_modified(nsp, false);
nfp_nsp_config_clear_state(nsp);
nfp_nsp_close(nsp);
kfree(entries);
}
int nfp_eth_config_commit_end(struct nfp_nsp *nsp)
{
union eth_table_entry *entries = nfp_nsp_config_entries(nsp);
int ret = 1;
if (nfp_nsp_config_modified(nsp)) {
ret = nfp_nsp_write_eth_table(nsp, entries, NSP_ETH_TABLE_SIZE);
ret = ret < 0 ? ret : 0;
}
nfp_eth_config_cleanup_end(nsp);
return ret;
}
int nfp_eth_set_mod_enable(struct nfp_cpp *cpp, unsigned int idx, bool enable)
{
union eth_table_entry *entries;
struct nfp_nsp *nsp;
u64 reg;
nsp = nfp_eth_config_start(cpp, idx);
if (IS_ERR(nsp))
return PTR_ERR(nsp);
entries = nfp_nsp_config_entries(nsp);
reg = le64_to_cpu(entries[idx].state);
if (enable != FIELD_GET(NSP_ETH_CTRL_ENABLED, reg)) {
reg = le64_to_cpu(entries[idx].control);
reg &= ~NSP_ETH_CTRL_ENABLED;
reg |= FIELD_PREP(NSP_ETH_CTRL_ENABLED, enable);
entries[idx].control = cpu_to_le64(reg);
nfp_nsp_config_set_modified(nsp, true);
}
return nfp_eth_config_commit_end(nsp);
}
int nfp_eth_set_configured(struct nfp_cpp *cpp, unsigned int idx, bool configed)
{
union eth_table_entry *entries;
struct nfp_nsp *nsp;
u64 reg;
nsp = nfp_eth_config_start(cpp, idx);
if (IS_ERR(nsp))
return PTR_ERR(nsp);
if (nfp_nsp_get_abi_ver_minor(nsp) < 20) {
nfp_eth_config_cleanup_end(nsp);
return -EOPNOTSUPP;
}
entries = nfp_nsp_config_entries(nsp);
reg = le64_to_cpu(entries[idx].state);
if (configed != FIELD_GET(NSP_ETH_STATE_CONFIGURED, reg)) {
reg = le64_to_cpu(entries[idx].control);
reg &= ~NSP_ETH_CTRL_CONFIGURED;
reg |= FIELD_PREP(NSP_ETH_CTRL_CONFIGURED, configed);
entries[idx].control = cpu_to_le64(reg);
nfp_nsp_config_set_modified(nsp, true);
}
return nfp_eth_config_commit_end(nsp);
}
static __always_inline int
nfp_eth_set_bit_config(struct nfp_nsp *nsp, unsigned int raw_idx,
const u64 mask, unsigned int val, const u64 ctrl_bit)
{
union eth_table_entry *entries = nfp_nsp_config_entries(nsp);
unsigned int idx = nfp_nsp_config_idx(nsp);
u64 reg;
if (nfp_nsp_get_abi_ver_minor(nsp) < 17) {
nfp_err(nfp_nsp_cpp(nsp),
"set operations not supported, please update flash\n");
return -EOPNOTSUPP;
}
reg = le64_to_cpu(entries[idx].raw[raw_idx]);
if (val == FIELD_GET(mask, reg))
return 0;
reg &= ~mask;
reg |= FIELD_PREP(mask, val);
entries[idx].raw[raw_idx] = cpu_to_le64(reg);
entries[idx].control |= cpu_to_le64(ctrl_bit);
nfp_nsp_config_set_modified(nsp, true);
return 0;
}
int __nfp_eth_set_aneg(struct nfp_nsp *nsp, enum nfp_eth_aneg mode)
{
return nfp_eth_set_bit_config(nsp, NSP_ETH_RAW_STATE,
NSP_ETH_STATE_ANEG, mode,
NSP_ETH_CTRL_SET_ANEG);
}
int __nfp_eth_set_speed(struct nfp_nsp *nsp, unsigned int speed)
{
enum nfp_eth_rate rate;
rate = nfp_eth_speed2rate(speed);
if (rate == RATE_INVALID) {
nfp_warn(nfp_nsp_cpp(nsp),
"could not find matching lane rate for speed %u\n",
speed);
return -EINVAL;
}
return nfp_eth_set_bit_config(nsp, NSP_ETH_RAW_STATE,
NSP_ETH_STATE_RATE, rate,
NSP_ETH_CTRL_SET_RATE);
}
int __nfp_eth_set_split(struct nfp_nsp *nsp, unsigned int lanes)
{
return nfp_eth_set_bit_config(nsp, NSP_ETH_RAW_PORT, NSP_ETH_PORT_LANES,
lanes, NSP_ETH_CTRL_SET_LANES);
}
