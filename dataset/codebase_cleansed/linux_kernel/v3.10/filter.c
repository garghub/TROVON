static u16 efx_filter_hash(u32 key)
{
u16 tmp;
tmp = 0x1fff ^ key >> 16;
tmp = tmp ^ tmp >> 3 ^ tmp >> 6;
tmp = tmp ^ tmp >> 9;
tmp = tmp ^ tmp << 13 ^ key;
tmp = tmp ^ tmp >> 3 ^ tmp >> 6;
return tmp ^ tmp >> 9;
}
static u16 efx_filter_increment(u32 key)
{
return key * 2 - 1;
}
static enum efx_filter_table_id
efx_filter_spec_table_id(const struct efx_filter_spec *spec)
{
BUILD_BUG_ON(EFX_FILTER_TABLE_RX_IP != (EFX_FILTER_TCP_FULL >> 2));
BUILD_BUG_ON(EFX_FILTER_TABLE_RX_IP != (EFX_FILTER_TCP_WILD >> 2));
BUILD_BUG_ON(EFX_FILTER_TABLE_RX_IP != (EFX_FILTER_UDP_FULL >> 2));
BUILD_BUG_ON(EFX_FILTER_TABLE_RX_IP != (EFX_FILTER_UDP_WILD >> 2));
BUILD_BUG_ON(EFX_FILTER_TABLE_RX_MAC != (EFX_FILTER_MAC_FULL >> 2));
BUILD_BUG_ON(EFX_FILTER_TABLE_RX_MAC != (EFX_FILTER_MAC_WILD >> 2));
BUILD_BUG_ON(EFX_FILTER_TABLE_TX_MAC != EFX_FILTER_TABLE_RX_MAC + 2);
EFX_BUG_ON_PARANOID(spec->type == EFX_FILTER_UNSPEC);
return (spec->type >> 2) + ((spec->flags & EFX_FILTER_FLAG_TX) ? 2 : 0);
}
static struct efx_filter_table *
efx_filter_spec_table(struct efx_filter_state *state,
const struct efx_filter_spec *spec)
{
if (spec->type == EFX_FILTER_UNSPEC)
return NULL;
else
return &state->table[efx_filter_spec_table_id(spec)];
}
static void efx_filter_table_reset_search_depth(struct efx_filter_table *table)
{
memset(table->search_depth, 0, sizeof(table->search_depth));
}
static void efx_filter_push_rx_config(struct efx_nic *efx)
{
struct efx_filter_state *state = efx->filter_state;
struct efx_filter_table *table;
efx_oword_t filter_ctl;
efx_reado(efx, &filter_ctl, FR_BZ_RX_FILTER_CTL);
table = &state->table[EFX_FILTER_TABLE_RX_IP];
EFX_SET_OWORD_FIELD(filter_ctl, FRF_BZ_TCP_FULL_SRCH_LIMIT,
table->search_depth[EFX_FILTER_TCP_FULL] +
FILTER_CTL_SRCH_FUDGE_FULL);
EFX_SET_OWORD_FIELD(filter_ctl, FRF_BZ_TCP_WILD_SRCH_LIMIT,
table->search_depth[EFX_FILTER_TCP_WILD] +
FILTER_CTL_SRCH_FUDGE_WILD);
EFX_SET_OWORD_FIELD(filter_ctl, FRF_BZ_UDP_FULL_SRCH_LIMIT,
table->search_depth[EFX_FILTER_UDP_FULL] +
FILTER_CTL_SRCH_FUDGE_FULL);
EFX_SET_OWORD_FIELD(filter_ctl, FRF_BZ_UDP_WILD_SRCH_LIMIT,
table->search_depth[EFX_FILTER_UDP_WILD] +
FILTER_CTL_SRCH_FUDGE_WILD);
table = &state->table[EFX_FILTER_TABLE_RX_MAC];
if (table->size) {
EFX_SET_OWORD_FIELD(
filter_ctl, FRF_CZ_ETHERNET_FULL_SEARCH_LIMIT,
table->search_depth[EFX_FILTER_MAC_FULL] +
FILTER_CTL_SRCH_FUDGE_FULL);
EFX_SET_OWORD_FIELD(
filter_ctl, FRF_CZ_ETHERNET_WILDCARD_SEARCH_LIMIT,
table->search_depth[EFX_FILTER_MAC_WILD] +
FILTER_CTL_SRCH_FUDGE_WILD);
}
table = &state->table[EFX_FILTER_TABLE_RX_DEF];
if (table->size) {
EFX_SET_OWORD_FIELD(
filter_ctl, FRF_CZ_UNICAST_NOMATCH_Q_ID,
table->spec[EFX_FILTER_INDEX_UC_DEF].dmaq_id);
EFX_SET_OWORD_FIELD(
filter_ctl, FRF_CZ_UNICAST_NOMATCH_RSS_ENABLED,
!!(table->spec[EFX_FILTER_INDEX_UC_DEF].flags &
EFX_FILTER_FLAG_RX_RSS));
EFX_SET_OWORD_FIELD(
filter_ctl, FRF_CZ_MULTICAST_NOMATCH_Q_ID,
table->spec[EFX_FILTER_INDEX_MC_DEF].dmaq_id);
EFX_SET_OWORD_FIELD(
filter_ctl, FRF_CZ_MULTICAST_NOMATCH_RSS_ENABLED,
!!(table->spec[EFX_FILTER_INDEX_MC_DEF].flags &
EFX_FILTER_FLAG_RX_RSS));
EFX_SET_OWORD_FIELD(
filter_ctl, FRF_BZ_SCATTER_ENBL_NO_MATCH_Q,
!!(table->spec[EFX_FILTER_INDEX_UC_DEF].flags &
table->spec[EFX_FILTER_INDEX_MC_DEF].flags &
EFX_FILTER_FLAG_RX_SCATTER));
} else if (efx_nic_rev(efx) >= EFX_REV_FALCON_B0) {
EFX_SET_OWORD_FIELD(
filter_ctl, FRF_BZ_SCATTER_ENBL_NO_MATCH_Q,
efx->rx_scatter);
}
efx_writeo(efx, &filter_ctl, FR_BZ_RX_FILTER_CTL);
}
static void efx_filter_push_tx_limits(struct efx_nic *efx)
{
struct efx_filter_state *state = efx->filter_state;
struct efx_filter_table *table;
efx_oword_t tx_cfg;
efx_reado(efx, &tx_cfg, FR_AZ_TX_CFG);
table = &state->table[EFX_FILTER_TABLE_TX_MAC];
if (table->size) {
EFX_SET_OWORD_FIELD(
tx_cfg, FRF_CZ_TX_ETH_FILTER_FULL_SEARCH_RANGE,
table->search_depth[EFX_FILTER_MAC_FULL] +
FILTER_CTL_SRCH_FUDGE_FULL);
EFX_SET_OWORD_FIELD(
tx_cfg, FRF_CZ_TX_ETH_FILTER_WILD_SEARCH_RANGE,
table->search_depth[EFX_FILTER_MAC_WILD] +
FILTER_CTL_SRCH_FUDGE_WILD);
}
efx_writeo(efx, &tx_cfg, FR_AZ_TX_CFG);
}
static inline void __efx_filter_set_ipv4(struct efx_filter_spec *spec,
__be32 host1, __be16 port1,
__be32 host2, __be16 port2)
{
spec->data[0] = ntohl(host1) << 16 | ntohs(port1);
spec->data[1] = ntohs(port2) << 16 | ntohl(host1) >> 16;
spec->data[2] = ntohl(host2);
}
static inline void __efx_filter_get_ipv4(const struct efx_filter_spec *spec,
__be32 *host1, __be16 *port1,
__be32 *host2, __be16 *port2)
{
*host1 = htonl(spec->data[0] >> 16 | spec->data[1] << 16);
*port1 = htons(spec->data[0]);
*host2 = htonl(spec->data[2]);
*port2 = htons(spec->data[1] >> 16);
}
int efx_filter_set_ipv4_local(struct efx_filter_spec *spec, u8 proto,
__be32 host, __be16 port)
{
__be32 host1;
__be16 port1;
EFX_BUG_ON_PARANOID(!(spec->flags & EFX_FILTER_FLAG_RX));
if (spec->type != EFX_FILTER_UNSPEC)
return -EPROTONOSUPPORT;
if (port == 0)
return -EINVAL;
switch (proto) {
case IPPROTO_TCP:
spec->type = EFX_FILTER_TCP_WILD;
break;
case IPPROTO_UDP:
spec->type = EFX_FILTER_UDP_WILD;
break;
default:
return -EPROTONOSUPPORT;
}
host1 = 0;
if (proto != IPPROTO_UDP) {
port1 = 0;
} else {
port1 = port;
port = 0;
}
__efx_filter_set_ipv4(spec, host1, port1, host, port);
return 0;
}
int efx_filter_get_ipv4_local(const struct efx_filter_spec *spec,
u8 *proto, __be32 *host, __be16 *port)
{
__be32 host1;
__be16 port1;
switch (spec->type) {
case EFX_FILTER_TCP_WILD:
*proto = IPPROTO_TCP;
__efx_filter_get_ipv4(spec, &host1, &port1, host, port);
return 0;
case EFX_FILTER_UDP_WILD:
*proto = IPPROTO_UDP;
__efx_filter_get_ipv4(spec, &host1, port, host, &port1);
return 0;
default:
return -EINVAL;
}
}
int efx_filter_set_ipv4_full(struct efx_filter_spec *spec, u8 proto,
__be32 host, __be16 port,
__be32 rhost, __be16 rport)
{
EFX_BUG_ON_PARANOID(!(spec->flags & EFX_FILTER_FLAG_RX));
if (spec->type != EFX_FILTER_UNSPEC)
return -EPROTONOSUPPORT;
if (port == 0 || rport == 0)
return -EINVAL;
switch (proto) {
case IPPROTO_TCP:
spec->type = EFX_FILTER_TCP_FULL;
break;
case IPPROTO_UDP:
spec->type = EFX_FILTER_UDP_FULL;
break;
default:
return -EPROTONOSUPPORT;
}
__efx_filter_set_ipv4(spec, rhost, rport, host, port);
return 0;
}
int efx_filter_get_ipv4_full(const struct efx_filter_spec *spec,
u8 *proto, __be32 *host, __be16 *port,
__be32 *rhost, __be16 *rport)
{
switch (spec->type) {
case EFX_FILTER_TCP_FULL:
*proto = IPPROTO_TCP;
break;
case EFX_FILTER_UDP_FULL:
*proto = IPPROTO_UDP;
break;
default:
return -EINVAL;
}
__efx_filter_get_ipv4(spec, rhost, rport, host, port);
return 0;
}
int efx_filter_set_eth_local(struct efx_filter_spec *spec,
u16 vid, const u8 *addr)
{
EFX_BUG_ON_PARANOID(!(spec->flags &
(EFX_FILTER_FLAG_RX | EFX_FILTER_FLAG_TX)));
if (spec->type != EFX_FILTER_UNSPEC)
return -EPROTONOSUPPORT;
if (vid == EFX_FILTER_VID_UNSPEC) {
spec->type = EFX_FILTER_MAC_WILD;
spec->data[0] = 0;
} else {
spec->type = EFX_FILTER_MAC_FULL;
spec->data[0] = vid;
}
spec->data[1] = addr[2] << 24 | addr[3] << 16 | addr[4] << 8 | addr[5];
spec->data[2] = addr[0] << 8 | addr[1];
return 0;
}
int efx_filter_set_uc_def(struct efx_filter_spec *spec)
{
EFX_BUG_ON_PARANOID(!(spec->flags &
(EFX_FILTER_FLAG_RX | EFX_FILTER_FLAG_TX)));
if (spec->type != EFX_FILTER_UNSPEC)
return -EINVAL;
spec->type = EFX_FILTER_UC_DEF;
memset(spec->data, 0, sizeof(spec->data));
return 0;
}
int efx_filter_set_mc_def(struct efx_filter_spec *spec)
{
EFX_BUG_ON_PARANOID(!(spec->flags &
(EFX_FILTER_FLAG_RX | EFX_FILTER_FLAG_TX)));
if (spec->type != EFX_FILTER_UNSPEC)
return -EINVAL;
spec->type = EFX_FILTER_MC_DEF;
memset(spec->data, 0, sizeof(spec->data));
return 0;
}
static void efx_filter_reset_rx_def(struct efx_nic *efx, unsigned filter_idx)
{
struct efx_filter_state *state = efx->filter_state;
struct efx_filter_table *table = &state->table[EFX_FILTER_TABLE_RX_DEF];
struct efx_filter_spec *spec = &table->spec[filter_idx];
enum efx_filter_flags flags = 0;
if (efx->n_rx_channels > 1)
flags |= EFX_FILTER_FLAG_RX_RSS;
if (efx->rx_scatter)
flags |= EFX_FILTER_FLAG_RX_SCATTER;
efx_filter_init_rx(spec, EFX_FILTER_PRI_MANUAL, flags, 0);
spec->type = EFX_FILTER_UC_DEF + filter_idx;
table->used_bitmap[0] |= 1 << filter_idx;
}
int efx_filter_get_eth_local(const struct efx_filter_spec *spec,
u16 *vid, u8 *addr)
{
switch (spec->type) {
case EFX_FILTER_MAC_WILD:
*vid = EFX_FILTER_VID_UNSPEC;
break;
case EFX_FILTER_MAC_FULL:
*vid = spec->data[0];
break;
default:
return -EINVAL;
}
addr[0] = spec->data[2] >> 8;
addr[1] = spec->data[2];
addr[2] = spec->data[1] >> 24;
addr[3] = spec->data[1] >> 16;
addr[4] = spec->data[1] >> 8;
addr[5] = spec->data[1];
return 0;
}
static u32 efx_filter_build(efx_oword_t *filter, struct efx_filter_spec *spec)
{
u32 data3;
switch (efx_filter_spec_table_id(spec)) {
case EFX_FILTER_TABLE_RX_IP: {
bool is_udp = (spec->type == EFX_FILTER_UDP_FULL ||
spec->type == EFX_FILTER_UDP_WILD);
EFX_POPULATE_OWORD_7(
*filter,
FRF_BZ_RSS_EN,
!!(spec->flags & EFX_FILTER_FLAG_RX_RSS),
FRF_BZ_SCATTER_EN,
!!(spec->flags & EFX_FILTER_FLAG_RX_SCATTER),
FRF_BZ_TCP_UDP, is_udp,
FRF_BZ_RXQ_ID, spec->dmaq_id,
EFX_DWORD_2, spec->data[2],
EFX_DWORD_1, spec->data[1],
EFX_DWORD_0, spec->data[0]);
data3 = is_udp;
break;
}
case EFX_FILTER_TABLE_RX_MAC: {
bool is_wild = spec->type == EFX_FILTER_MAC_WILD;
EFX_POPULATE_OWORD_7(
*filter,
FRF_CZ_RMFT_RSS_EN,
!!(spec->flags & EFX_FILTER_FLAG_RX_RSS),
FRF_CZ_RMFT_SCATTER_EN,
!!(spec->flags & EFX_FILTER_FLAG_RX_SCATTER),
FRF_CZ_RMFT_RXQ_ID, spec->dmaq_id,
FRF_CZ_RMFT_WILDCARD_MATCH, is_wild,
FRF_CZ_RMFT_DEST_MAC_HI, spec->data[2],
FRF_CZ_RMFT_DEST_MAC_LO, spec->data[1],
FRF_CZ_RMFT_VLAN_ID, spec->data[0]);
data3 = is_wild;
break;
}
case EFX_FILTER_TABLE_TX_MAC: {
bool is_wild = spec->type == EFX_FILTER_MAC_WILD;
EFX_POPULATE_OWORD_5(*filter,
FRF_CZ_TMFT_TXQ_ID, spec->dmaq_id,
FRF_CZ_TMFT_WILDCARD_MATCH, is_wild,
FRF_CZ_TMFT_SRC_MAC_HI, spec->data[2],
FRF_CZ_TMFT_SRC_MAC_LO, spec->data[1],
FRF_CZ_TMFT_VLAN_ID, spec->data[0]);
data3 = is_wild | spec->dmaq_id << 1;
break;
}
default:
BUG();
}
return spec->data[0] ^ spec->data[1] ^ spec->data[2] ^ data3;
}
static bool efx_filter_equal(const struct efx_filter_spec *left,
const struct efx_filter_spec *right)
{
if (left->type != right->type ||
memcmp(left->data, right->data, sizeof(left->data)))
return false;
if (left->flags & EFX_FILTER_FLAG_TX &&
left->dmaq_id != right->dmaq_id)
return false;
return true;
}
static inline u32
efx_filter_make_id(const struct efx_filter_spec *spec, unsigned int index)
{
unsigned int range;
range = efx_filter_type_match_pri[spec->type];
if (!(spec->flags & EFX_FILTER_FLAG_RX))
range += EFX_FILTER_MATCH_PRI_COUNT;
return range << EFX_FILTER_INDEX_WIDTH | index;
}
static inline enum efx_filter_table_id efx_filter_id_table_id(u32 id)
{
unsigned int range = id >> EFX_FILTER_INDEX_WIDTH;
if (range < ARRAY_SIZE(efx_filter_range_table))
return efx_filter_range_table[range];
else
return EFX_FILTER_TABLE_COUNT;
}
static inline unsigned int efx_filter_id_index(u32 id)
{
return id & EFX_FILTER_INDEX_MASK;
}
static inline u8 efx_filter_id_flags(u32 id)
{
unsigned int range = id >> EFX_FILTER_INDEX_WIDTH;
if (range < EFX_FILTER_MATCH_PRI_COUNT)
return EFX_FILTER_FLAG_RX;
else
return EFX_FILTER_FLAG_TX;
}
u32 efx_filter_get_rx_id_limit(struct efx_nic *efx)
{
struct efx_filter_state *state = efx->filter_state;
unsigned int range = EFX_FILTER_MATCH_PRI_COUNT - 1;
enum efx_filter_table_id table_id;
do {
table_id = efx_filter_range_table[range];
if (state->table[table_id].size != 0)
return range << EFX_FILTER_INDEX_WIDTH |
state->table[table_id].size;
} while (range--);
return 0;
}
s32 efx_filter_insert_filter(struct efx_nic *efx, struct efx_filter_spec *spec,
bool replace_equal)
{
struct efx_filter_state *state = efx->filter_state;
struct efx_filter_table *table = efx_filter_spec_table(state, spec);
efx_oword_t filter;
int rep_index, ins_index;
unsigned int depth = 0;
int rc;
if (!table || table->size == 0)
return -EINVAL;
netif_vdbg(efx, hw, efx->net_dev,
"%s: type %d search_depth=%d", __func__, spec->type,
table->search_depth[spec->type]);
if (table->id == EFX_FILTER_TABLE_RX_DEF) {
BUILD_BUG_ON(EFX_FILTER_INDEX_UC_DEF != 0);
BUILD_BUG_ON(EFX_FILTER_INDEX_MC_DEF !=
EFX_FILTER_MC_DEF - EFX_FILTER_UC_DEF);
rep_index = spec->type - EFX_FILTER_INDEX_UC_DEF;
ins_index = rep_index;
spin_lock_bh(&state->lock);
} else {
u32 key = efx_filter_build(&filter, spec);
unsigned int hash = efx_filter_hash(key);
unsigned int incr = efx_filter_increment(key);
unsigned int max_rep_depth = table->search_depth[spec->type];
unsigned int max_ins_depth =
spec->priority <= EFX_FILTER_PRI_HINT ?
FILTER_CTL_SRCH_HINT_MAX : FILTER_CTL_SRCH_MAX;
unsigned int i = hash & (table->size - 1);
ins_index = -1;
depth = 1;
spin_lock_bh(&state->lock);
for (;;) {
if (!test_bit(i, table->used_bitmap)) {
if (ins_index < 0)
ins_index = i;
} else if (efx_filter_equal(spec, &table->spec[i])) {
if (ins_index < 0)
ins_index = i;
rep_index = i;
break;
}
if (depth >= max_rep_depth &&
(ins_index >= 0 || depth >= max_ins_depth)) {
if (ins_index < 0) {
rc = -EBUSY;
goto out;
}
rep_index = -1;
break;
}
i = (i + incr) & (table->size - 1);
++depth;
}
}
if (rep_index >= 0) {
struct efx_filter_spec *saved_spec = &table->spec[rep_index];
if (spec->priority == saved_spec->priority && !replace_equal) {
rc = -EEXIST;
goto out;
}
if (spec->priority < saved_spec->priority) {
rc = -EPERM;
goto out;
}
}
if (ins_index != rep_index) {
__set_bit(ins_index, table->used_bitmap);
++table->used;
}
table->spec[ins_index] = *spec;
if (table->id == EFX_FILTER_TABLE_RX_DEF) {
efx_filter_push_rx_config(efx);
} else {
if (table->search_depth[spec->type] < depth) {
table->search_depth[spec->type] = depth;
if (spec->flags & EFX_FILTER_FLAG_TX)
efx_filter_push_tx_limits(efx);
else
efx_filter_push_rx_config(efx);
}
efx_writeo(efx, &filter,
table->offset + table->step * ins_index);
if (ins_index != rep_index && rep_index >= 0)
efx_filter_table_clear_entry(efx, table, rep_index);
}
netif_vdbg(efx, hw, efx->net_dev,
"%s: filter type %d index %d rxq %u set",
__func__, spec->type, ins_index, spec->dmaq_id);
rc = efx_filter_make_id(spec, ins_index);
out:
spin_unlock_bh(&state->lock);
return rc;
}
static void efx_filter_table_clear_entry(struct efx_nic *efx,
struct efx_filter_table *table,
unsigned int filter_idx)
{
static efx_oword_t filter;
if (table->id == EFX_FILTER_TABLE_RX_DEF) {
efx_filter_reset_rx_def(efx, filter_idx);
efx_filter_push_rx_config(efx);
} else if (test_bit(filter_idx, table->used_bitmap)) {
__clear_bit(filter_idx, table->used_bitmap);
--table->used;
memset(&table->spec[filter_idx], 0, sizeof(table->spec[0]));
efx_writeo(efx, &filter,
table->offset + table->step * filter_idx);
}
}
int efx_filter_remove_id_safe(struct efx_nic *efx,
enum efx_filter_priority priority,
u32 filter_id)
{
struct efx_filter_state *state = efx->filter_state;
enum efx_filter_table_id table_id;
struct efx_filter_table *table;
unsigned int filter_idx;
struct efx_filter_spec *spec;
u8 filter_flags;
int rc;
table_id = efx_filter_id_table_id(filter_id);
if ((unsigned int)table_id >= EFX_FILTER_TABLE_COUNT)
return -ENOENT;
table = &state->table[table_id];
filter_idx = efx_filter_id_index(filter_id);
if (filter_idx >= table->size)
return -ENOENT;
spec = &table->spec[filter_idx];
filter_flags = efx_filter_id_flags(filter_id);
spin_lock_bh(&state->lock);
if (test_bit(filter_idx, table->used_bitmap) &&
spec->priority == priority) {
efx_filter_table_clear_entry(efx, table, filter_idx);
if (table->used == 0)
efx_filter_table_reset_search_depth(table);
rc = 0;
} else {
rc = -ENOENT;
}
spin_unlock_bh(&state->lock);
return rc;
}
int efx_filter_get_filter_safe(struct efx_nic *efx,
enum efx_filter_priority priority,
u32 filter_id, struct efx_filter_spec *spec_buf)
{
struct efx_filter_state *state = efx->filter_state;
enum efx_filter_table_id table_id;
struct efx_filter_table *table;
struct efx_filter_spec *spec;
unsigned int filter_idx;
u8 filter_flags;
int rc;
table_id = efx_filter_id_table_id(filter_id);
if ((unsigned int)table_id >= EFX_FILTER_TABLE_COUNT)
return -ENOENT;
table = &state->table[table_id];
filter_idx = efx_filter_id_index(filter_id);
if (filter_idx >= table->size)
return -ENOENT;
spec = &table->spec[filter_idx];
filter_flags = efx_filter_id_flags(filter_id);
spin_lock_bh(&state->lock);
if (test_bit(filter_idx, table->used_bitmap) &&
spec->priority == priority) {
*spec_buf = *spec;
rc = 0;
} else {
rc = -ENOENT;
}
spin_unlock_bh(&state->lock);
return rc;
}
static void efx_filter_table_clear(struct efx_nic *efx,
enum efx_filter_table_id table_id,
enum efx_filter_priority priority)
{
struct efx_filter_state *state = efx->filter_state;
struct efx_filter_table *table = &state->table[table_id];
unsigned int filter_idx;
spin_lock_bh(&state->lock);
for (filter_idx = 0; filter_idx < table->size; ++filter_idx)
if (table->spec[filter_idx].priority <= priority)
efx_filter_table_clear_entry(efx, table, filter_idx);
if (table->used == 0)
efx_filter_table_reset_search_depth(table);
spin_unlock_bh(&state->lock);
}
void efx_filter_clear_rx(struct efx_nic *efx, enum efx_filter_priority priority)
{
efx_filter_table_clear(efx, EFX_FILTER_TABLE_RX_IP, priority);
efx_filter_table_clear(efx, EFX_FILTER_TABLE_RX_MAC, priority);
}
u32 efx_filter_count_rx_used(struct efx_nic *efx,
enum efx_filter_priority priority)
{
struct efx_filter_state *state = efx->filter_state;
enum efx_filter_table_id table_id;
struct efx_filter_table *table;
unsigned int filter_idx;
u32 count = 0;
spin_lock_bh(&state->lock);
for (table_id = EFX_FILTER_TABLE_RX_IP;
table_id <= EFX_FILTER_TABLE_RX_DEF;
table_id++) {
table = &state->table[table_id];
for (filter_idx = 0; filter_idx < table->size; filter_idx++) {
if (test_bit(filter_idx, table->used_bitmap) &&
table->spec[filter_idx].priority == priority)
++count;
}
}
spin_unlock_bh(&state->lock);
return count;
}
s32 efx_filter_get_rx_ids(struct efx_nic *efx,
enum efx_filter_priority priority,
u32 *buf, u32 size)
{
struct efx_filter_state *state = efx->filter_state;
enum efx_filter_table_id table_id;
struct efx_filter_table *table;
unsigned int filter_idx;
s32 count = 0;
spin_lock_bh(&state->lock);
for (table_id = EFX_FILTER_TABLE_RX_IP;
table_id <= EFX_FILTER_TABLE_RX_DEF;
table_id++) {
table = &state->table[table_id];
for (filter_idx = 0; filter_idx < table->size; filter_idx++) {
if (test_bit(filter_idx, table->used_bitmap) &&
table->spec[filter_idx].priority == priority) {
if (count == size) {
count = -EMSGSIZE;
goto out;
}
buf[count++] = efx_filter_make_id(
&table->spec[filter_idx], filter_idx);
}
}
}
out:
spin_unlock_bh(&state->lock);
return count;
}
void efx_restore_filters(struct efx_nic *efx)
{
struct efx_filter_state *state = efx->filter_state;
enum efx_filter_table_id table_id;
struct efx_filter_table *table;
efx_oword_t filter;
unsigned int filter_idx;
spin_lock_bh(&state->lock);
for (table_id = 0; table_id < EFX_FILTER_TABLE_COUNT; table_id++) {
table = &state->table[table_id];
if (table->step == 0)
continue;
for (filter_idx = 0; filter_idx < table->size; filter_idx++) {
if (!test_bit(filter_idx, table->used_bitmap))
continue;
efx_filter_build(&filter, &table->spec[filter_idx]);
efx_writeo(efx, &filter,
table->offset + table->step * filter_idx);
}
}
efx_filter_push_rx_config(efx);
efx_filter_push_tx_limits(efx);
spin_unlock_bh(&state->lock);
}
int efx_probe_filters(struct efx_nic *efx)
{
struct efx_filter_state *state;
struct efx_filter_table *table;
unsigned table_id;
state = kzalloc(sizeof(*efx->filter_state), GFP_KERNEL);
if (!state)
return -ENOMEM;
efx->filter_state = state;
spin_lock_init(&state->lock);
if (efx_nic_rev(efx) >= EFX_REV_FALCON_B0) {
#ifdef CONFIG_RFS_ACCEL
state->rps_flow_id = kcalloc(FR_BZ_RX_FILTER_TBL0_ROWS,
sizeof(*state->rps_flow_id),
GFP_KERNEL);
if (!state->rps_flow_id)
goto fail;
#endif
table = &state->table[EFX_FILTER_TABLE_RX_IP];
table->id = EFX_FILTER_TABLE_RX_IP;
table->offset = FR_BZ_RX_FILTER_TBL0;
table->size = FR_BZ_RX_FILTER_TBL0_ROWS;
table->step = FR_BZ_RX_FILTER_TBL0_STEP;
}
if (efx_nic_rev(efx) >= EFX_REV_SIENA_A0) {
table = &state->table[EFX_FILTER_TABLE_RX_MAC];
table->id = EFX_FILTER_TABLE_RX_MAC;
table->offset = FR_CZ_RX_MAC_FILTER_TBL0;
table->size = FR_CZ_RX_MAC_FILTER_TBL0_ROWS;
table->step = FR_CZ_RX_MAC_FILTER_TBL0_STEP;
table = &state->table[EFX_FILTER_TABLE_RX_DEF];
table->id = EFX_FILTER_TABLE_RX_DEF;
table->size = EFX_FILTER_SIZE_RX_DEF;
table = &state->table[EFX_FILTER_TABLE_TX_MAC];
table->id = EFX_FILTER_TABLE_TX_MAC;
table->offset = FR_CZ_TX_MAC_FILTER_TBL0;
table->size = FR_CZ_TX_MAC_FILTER_TBL0_ROWS;
table->step = FR_CZ_TX_MAC_FILTER_TBL0_STEP;
}
for (table_id = 0; table_id < EFX_FILTER_TABLE_COUNT; table_id++) {
table = &state->table[table_id];
if (table->size == 0)
continue;
table->used_bitmap = kcalloc(BITS_TO_LONGS(table->size),
sizeof(unsigned long),
GFP_KERNEL);
if (!table->used_bitmap)
goto fail;
table->spec = vzalloc(table->size * sizeof(*table->spec));
if (!table->spec)
goto fail;
}
if (state->table[EFX_FILTER_TABLE_RX_DEF].size) {
unsigned i;
for (i = 0; i < EFX_FILTER_SIZE_RX_DEF; i++)
efx_filter_reset_rx_def(efx, i);
}
efx_filter_push_rx_config(efx);
return 0;
fail:
efx_remove_filters(efx);
return -ENOMEM;
}
void efx_remove_filters(struct efx_nic *efx)
{
struct efx_filter_state *state = efx->filter_state;
enum efx_filter_table_id table_id;
for (table_id = 0; table_id < EFX_FILTER_TABLE_COUNT; table_id++) {
kfree(state->table[table_id].used_bitmap);
vfree(state->table[table_id].spec);
}
#ifdef CONFIG_RFS_ACCEL
kfree(state->rps_flow_id);
#endif
kfree(state);
}
void efx_filter_update_rx_scatter(struct efx_nic *efx)
{
struct efx_filter_state *state = efx->filter_state;
enum efx_filter_table_id table_id;
struct efx_filter_table *table;
efx_oword_t filter;
unsigned int filter_idx;
spin_lock_bh(&state->lock);
for (table_id = EFX_FILTER_TABLE_RX_IP;
table_id <= EFX_FILTER_TABLE_RX_DEF;
table_id++) {
table = &state->table[table_id];
for (filter_idx = 0; filter_idx < table->size; filter_idx++) {
if (!test_bit(filter_idx, table->used_bitmap) ||
table->spec[filter_idx].dmaq_id >=
efx->n_rx_channels)
continue;
if (efx->rx_scatter)
table->spec[filter_idx].flags |=
EFX_FILTER_FLAG_RX_SCATTER;
else
table->spec[filter_idx].flags &=
~EFX_FILTER_FLAG_RX_SCATTER;
if (table_id == EFX_FILTER_TABLE_RX_DEF)
continue;
efx_filter_build(&filter, &table->spec[filter_idx]);
efx_writeo(efx, &filter,
table->offset + table->step * filter_idx);
}
}
efx_filter_push_rx_config(efx);
spin_unlock_bh(&state->lock);
}
int efx_filter_rfs(struct net_device *net_dev, const struct sk_buff *skb,
u16 rxq_index, u32 flow_id)
{
struct efx_nic *efx = netdev_priv(net_dev);
struct efx_channel *channel;
struct efx_filter_state *state = efx->filter_state;
struct efx_filter_spec spec;
const struct iphdr *ip;
const __be16 *ports;
int nhoff;
int rc;
nhoff = skb_network_offset(skb);
if (skb->protocol != htons(ETH_P_IP))
return -EPROTONOSUPPORT;
EFX_BUG_ON_PARANOID(skb_headlen(skb) < nhoff + sizeof(*ip));
ip = (const struct iphdr *)(skb->data + nhoff);
if (ip_is_fragment(ip))
return -EPROTONOSUPPORT;
EFX_BUG_ON_PARANOID(skb_headlen(skb) < nhoff + 4 * ip->ihl + 4);
ports = (const __be16 *)(skb->data + nhoff + 4 * ip->ihl);
efx_filter_init_rx(&spec, EFX_FILTER_PRI_HINT, 0, rxq_index);
rc = efx_filter_set_ipv4_full(&spec, ip->protocol,
ip->daddr, ports[1], ip->saddr, ports[0]);
if (rc)
return rc;
rc = efx_filter_insert_filter(efx, &spec, true);
if (rc < 0)
return rc;
state->rps_flow_id[rc] = flow_id;
channel = efx_get_channel(efx, skb_get_rx_queue(skb));
++channel->rfs_filters_added;
netif_info(efx, rx_status, efx->net_dev,
"steering %s %pI4:%u:%pI4:%u to queue %u [flow %u filter %d]\n",
(ip->protocol == IPPROTO_TCP) ? "TCP" : "UDP",
&ip->saddr, ntohs(ports[0]), &ip->daddr, ntohs(ports[1]),
rxq_index, flow_id, rc);
return rc;
}
bool __efx_filter_rfs_expire(struct efx_nic *efx, unsigned quota)
{
struct efx_filter_state *state = efx->filter_state;
struct efx_filter_table *table = &state->table[EFX_FILTER_TABLE_RX_IP];
unsigned mask = table->size - 1;
unsigned index;
unsigned stop;
if (!spin_trylock_bh(&state->lock))
return false;
index = state->rps_expire_index;
stop = (index + quota) & mask;
while (index != stop) {
if (test_bit(index, table->used_bitmap) &&
table->spec[index].priority == EFX_FILTER_PRI_HINT &&
rps_may_expire_flow(efx->net_dev,
table->spec[index].dmaq_id,
state->rps_flow_id[index], index)) {
netif_info(efx, rx_status, efx->net_dev,
"expiring filter %d [flow %u]\n",
index, state->rps_flow_id[index]);
efx_filter_table_clear_entry(efx, table, index);
}
index = (index + 1) & mask;
}
state->rps_expire_index = stop;
if (table->used == 0)
efx_filter_table_reset_search_depth(table);
spin_unlock_bh(&state->lock);
return true;
}
