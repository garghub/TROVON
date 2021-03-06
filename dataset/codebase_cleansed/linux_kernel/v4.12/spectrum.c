int mlxsw_sp_flow_counter_get(struct mlxsw_sp *mlxsw_sp,
unsigned int counter_index, u64 *packets,
u64 *bytes)
{
char mgpc_pl[MLXSW_REG_MGPC_LEN];
int err;
mlxsw_reg_mgpc_pack(mgpc_pl, counter_index, MLXSW_REG_MGPC_OPCODE_NOP,
MLXSW_REG_MGPC_COUNTER_SET_TYPE_PACKETS_BYTES);
err = mlxsw_reg_query(mlxsw_sp->core, MLXSW_REG(mgpc), mgpc_pl);
if (err)
return err;
*packets = mlxsw_reg_mgpc_packet_counter_get(mgpc_pl);
*bytes = mlxsw_reg_mgpc_byte_counter_get(mgpc_pl);
return 0;
}
static int mlxsw_sp_flow_counter_clear(struct mlxsw_sp *mlxsw_sp,
unsigned int counter_index)
{
char mgpc_pl[MLXSW_REG_MGPC_LEN];
mlxsw_reg_mgpc_pack(mgpc_pl, counter_index, MLXSW_REG_MGPC_OPCODE_CLEAR,
MLXSW_REG_MGPC_COUNTER_SET_TYPE_PACKETS_BYTES);
return mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(mgpc), mgpc_pl);
}
int mlxsw_sp_flow_counter_alloc(struct mlxsw_sp *mlxsw_sp,
unsigned int *p_counter_index)
{
int err;
err = mlxsw_sp_counter_alloc(mlxsw_sp, MLXSW_SP_COUNTER_SUB_POOL_FLOW,
p_counter_index);
if (err)
return err;
err = mlxsw_sp_flow_counter_clear(mlxsw_sp, *p_counter_index);
if (err)
goto err_counter_clear;
return 0;
err_counter_clear:
mlxsw_sp_counter_free(mlxsw_sp, MLXSW_SP_COUNTER_SUB_POOL_FLOW,
*p_counter_index);
return err;
}
void mlxsw_sp_flow_counter_free(struct mlxsw_sp *mlxsw_sp,
unsigned int counter_index)
{
mlxsw_sp_counter_free(mlxsw_sp, MLXSW_SP_COUNTER_SUB_POOL_FLOW,
counter_index);
}
static void mlxsw_sp_txhdr_construct(struct sk_buff *skb,
const struct mlxsw_tx_info *tx_info)
{
char *txhdr = skb_push(skb, MLXSW_TXHDR_LEN);
memset(txhdr, 0, MLXSW_TXHDR_LEN);
mlxsw_tx_hdr_version_set(txhdr, MLXSW_TXHDR_VERSION_1);
mlxsw_tx_hdr_ctl_set(txhdr, MLXSW_TXHDR_ETH_CTL);
mlxsw_tx_hdr_proto_set(txhdr, MLXSW_TXHDR_PROTO_ETH);
mlxsw_tx_hdr_swid_set(txhdr, 0);
mlxsw_tx_hdr_control_tclass_set(txhdr, 1);
mlxsw_tx_hdr_port_mid_set(txhdr, tx_info->local_port);
mlxsw_tx_hdr_type_set(txhdr, MLXSW_TXHDR_TYPE_CONTROL);
}
static int mlxsw_sp_base_mac_get(struct mlxsw_sp *mlxsw_sp)
{
char spad_pl[MLXSW_REG_SPAD_LEN] = {0};
int err;
err = mlxsw_reg_query(mlxsw_sp->core, MLXSW_REG(spad), spad_pl);
if (err)
return err;
mlxsw_reg_spad_base_mac_memcpy_from(spad_pl, mlxsw_sp->base_mac);
return 0;
}
static int mlxsw_sp_span_init(struct mlxsw_sp *mlxsw_sp)
{
int i;
if (!MLXSW_CORE_RES_VALID(mlxsw_sp->core, MAX_SPAN))
return -EIO;
mlxsw_sp->span.entries_count = MLXSW_CORE_RES_GET(mlxsw_sp->core,
MAX_SPAN);
mlxsw_sp->span.entries = kcalloc(mlxsw_sp->span.entries_count,
sizeof(struct mlxsw_sp_span_entry),
GFP_KERNEL);
if (!mlxsw_sp->span.entries)
return -ENOMEM;
for (i = 0; i < mlxsw_sp->span.entries_count; i++)
INIT_LIST_HEAD(&mlxsw_sp->span.entries[i].bound_ports_list);
return 0;
}
static void mlxsw_sp_span_fini(struct mlxsw_sp *mlxsw_sp)
{
int i;
for (i = 0; i < mlxsw_sp->span.entries_count; i++) {
struct mlxsw_sp_span_entry *curr = &mlxsw_sp->span.entries[i];
WARN_ON_ONCE(!list_empty(&curr->bound_ports_list));
}
kfree(mlxsw_sp->span.entries);
}
static struct mlxsw_sp_span_entry *
mlxsw_sp_span_entry_create(struct mlxsw_sp_port *port)
{
struct mlxsw_sp *mlxsw_sp = port->mlxsw_sp;
struct mlxsw_sp_span_entry *span_entry;
char mpat_pl[MLXSW_REG_MPAT_LEN];
u8 local_port = port->local_port;
int index;
int i;
int err;
index = -1;
for (i = 0; i < mlxsw_sp->span.entries_count; i++) {
if (!mlxsw_sp->span.entries[i].used) {
index = i;
span_entry = &mlxsw_sp->span.entries[i];
break;
}
}
if (index < 0)
return NULL;
mlxsw_reg_mpat_pack(mpat_pl, index, local_port, true);
err = mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(mpat), mpat_pl);
if (err)
return NULL;
span_entry->used = true;
span_entry->id = index;
span_entry->ref_count = 1;
span_entry->local_port = local_port;
return span_entry;
}
static void mlxsw_sp_span_entry_destroy(struct mlxsw_sp *mlxsw_sp,
struct mlxsw_sp_span_entry *span_entry)
{
u8 local_port = span_entry->local_port;
char mpat_pl[MLXSW_REG_MPAT_LEN];
int pa_id = span_entry->id;
mlxsw_reg_mpat_pack(mpat_pl, pa_id, local_port, false);
mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(mpat), mpat_pl);
span_entry->used = false;
}
static struct mlxsw_sp_span_entry *
mlxsw_sp_span_entry_find(struct mlxsw_sp_port *port)
{
struct mlxsw_sp *mlxsw_sp = port->mlxsw_sp;
int i;
for (i = 0; i < mlxsw_sp->span.entries_count; i++) {
struct mlxsw_sp_span_entry *curr = &mlxsw_sp->span.entries[i];
if (curr->used && curr->local_port == port->local_port)
return curr;
}
return NULL;
}
static struct mlxsw_sp_span_entry
*mlxsw_sp_span_entry_get(struct mlxsw_sp_port *port)
{
struct mlxsw_sp_span_entry *span_entry;
span_entry = mlxsw_sp_span_entry_find(port);
if (span_entry) {
span_entry->ref_count++;
return span_entry;
}
return mlxsw_sp_span_entry_create(port);
}
static int mlxsw_sp_span_entry_put(struct mlxsw_sp *mlxsw_sp,
struct mlxsw_sp_span_entry *span_entry)
{
WARN_ON(!span_entry->ref_count);
if (--span_entry->ref_count == 0)
mlxsw_sp_span_entry_destroy(mlxsw_sp, span_entry);
return 0;
}
static bool mlxsw_sp_span_is_egress_mirror(struct mlxsw_sp_port *port)
{
struct mlxsw_sp *mlxsw_sp = port->mlxsw_sp;
struct mlxsw_sp_span_inspected_port *p;
int i;
for (i = 0; i < mlxsw_sp->span.entries_count; i++) {
struct mlxsw_sp_span_entry *curr = &mlxsw_sp->span.entries[i];
list_for_each_entry(p, &curr->bound_ports_list, list)
if (p->local_port == port->local_port &&
p->type == MLXSW_SP_SPAN_EGRESS)
return true;
}
return false;
}
static int mlxsw_sp_span_mtu_to_buffsize(const struct mlxsw_sp *mlxsw_sp,
int mtu)
{
return mlxsw_sp_bytes_cells(mlxsw_sp, mtu * 5 / 2) + 1;
}
static int mlxsw_sp_span_port_mtu_update(struct mlxsw_sp_port *port, u16 mtu)
{
struct mlxsw_sp *mlxsw_sp = port->mlxsw_sp;
char sbib_pl[MLXSW_REG_SBIB_LEN];
int err;
if (mlxsw_sp_span_is_egress_mirror(port)) {
u32 buffsize = mlxsw_sp_span_mtu_to_buffsize(mlxsw_sp, mtu);
mlxsw_reg_sbib_pack(sbib_pl, port->local_port, buffsize);
err = mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(sbib), sbib_pl);
if (err) {
netdev_err(port->dev, "Could not update shared buffer for mirroring\n");
return err;
}
}
return 0;
}
static struct mlxsw_sp_span_inspected_port *
mlxsw_sp_span_entry_bound_port_find(struct mlxsw_sp_port *port,
struct mlxsw_sp_span_entry *span_entry)
{
struct mlxsw_sp_span_inspected_port *p;
list_for_each_entry(p, &span_entry->bound_ports_list, list)
if (port->local_port == p->local_port)
return p;
return NULL;
}
static int
mlxsw_sp_span_inspected_port_bind(struct mlxsw_sp_port *port,
struct mlxsw_sp_span_entry *span_entry,
enum mlxsw_sp_span_type type)
{
struct mlxsw_sp_span_inspected_port *inspected_port;
struct mlxsw_sp *mlxsw_sp = port->mlxsw_sp;
char mpar_pl[MLXSW_REG_MPAR_LEN];
char sbib_pl[MLXSW_REG_SBIB_LEN];
int pa_id = span_entry->id;
int err;
if (type == MLXSW_SP_SPAN_EGRESS) {
u32 buffsize = mlxsw_sp_span_mtu_to_buffsize(mlxsw_sp,
port->dev->mtu);
mlxsw_reg_sbib_pack(sbib_pl, port->local_port, buffsize);
err = mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(sbib), sbib_pl);
if (err) {
netdev_err(port->dev, "Could not create shared buffer for mirroring\n");
return err;
}
}
mlxsw_reg_mpar_pack(mpar_pl, port->local_port,
(enum mlxsw_reg_mpar_i_e) type, true, pa_id);
err = mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(mpar), mpar_pl);
if (err)
goto err_mpar_reg_write;
inspected_port = kzalloc(sizeof(*inspected_port), GFP_KERNEL);
if (!inspected_port) {
err = -ENOMEM;
goto err_inspected_port_alloc;
}
inspected_port->local_port = port->local_port;
inspected_port->type = type;
list_add_tail(&inspected_port->list, &span_entry->bound_ports_list);
return 0;
err_mpar_reg_write:
err_inspected_port_alloc:
if (type == MLXSW_SP_SPAN_EGRESS) {
mlxsw_reg_sbib_pack(sbib_pl, port->local_port, 0);
mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(sbib), sbib_pl);
}
return err;
}
static void
mlxsw_sp_span_inspected_port_unbind(struct mlxsw_sp_port *port,
struct mlxsw_sp_span_entry *span_entry,
enum mlxsw_sp_span_type type)
{
struct mlxsw_sp_span_inspected_port *inspected_port;
struct mlxsw_sp *mlxsw_sp = port->mlxsw_sp;
char mpar_pl[MLXSW_REG_MPAR_LEN];
char sbib_pl[MLXSW_REG_SBIB_LEN];
int pa_id = span_entry->id;
inspected_port = mlxsw_sp_span_entry_bound_port_find(port, span_entry);
if (!inspected_port)
return;
mlxsw_reg_mpar_pack(mpar_pl, port->local_port,
(enum mlxsw_reg_mpar_i_e) type, false, pa_id);
mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(mpar), mpar_pl);
if (type == MLXSW_SP_SPAN_EGRESS) {
mlxsw_reg_sbib_pack(sbib_pl, port->local_port, 0);
mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(sbib), sbib_pl);
}
mlxsw_sp_span_entry_put(mlxsw_sp, span_entry);
list_del(&inspected_port->list);
kfree(inspected_port);
}
static int mlxsw_sp_span_mirror_add(struct mlxsw_sp_port *from,
struct mlxsw_sp_port *to,
enum mlxsw_sp_span_type type)
{
struct mlxsw_sp *mlxsw_sp = from->mlxsw_sp;
struct mlxsw_sp_span_entry *span_entry;
int err;
span_entry = mlxsw_sp_span_entry_get(to);
if (!span_entry)
return -ENOENT;
netdev_dbg(from->dev, "Adding inspected port to SPAN entry %d\n",
span_entry->id);
err = mlxsw_sp_span_inspected_port_bind(from, span_entry, type);
if (err)
goto err_port_bind;
return 0;
err_port_bind:
mlxsw_sp_span_entry_put(mlxsw_sp, span_entry);
return err;
}
static void mlxsw_sp_span_mirror_remove(struct mlxsw_sp_port *from,
struct mlxsw_sp_port *to,
enum mlxsw_sp_span_type type)
{
struct mlxsw_sp_span_entry *span_entry;
span_entry = mlxsw_sp_span_entry_find(to);
if (!span_entry) {
netdev_err(from->dev, "no span entry found\n");
return;
}
netdev_dbg(from->dev, "removing inspected port from SPAN entry %d\n",
span_entry->id);
mlxsw_sp_span_inspected_port_unbind(from, span_entry, type);
}
static int mlxsw_sp_port_sample_set(struct mlxsw_sp_port *mlxsw_sp_port,
bool enable, u32 rate)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
char mpsc_pl[MLXSW_REG_MPSC_LEN];
mlxsw_reg_mpsc_pack(mpsc_pl, mlxsw_sp_port->local_port, enable, rate);
return mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(mpsc), mpsc_pl);
}
static int mlxsw_sp_port_admin_status_set(struct mlxsw_sp_port *mlxsw_sp_port,
bool is_up)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
char paos_pl[MLXSW_REG_PAOS_LEN];
mlxsw_reg_paos_pack(paos_pl, mlxsw_sp_port->local_port,
is_up ? MLXSW_PORT_ADMIN_STATUS_UP :
MLXSW_PORT_ADMIN_STATUS_DOWN);
return mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(paos), paos_pl);
}
static int mlxsw_sp_port_dev_addr_set(struct mlxsw_sp_port *mlxsw_sp_port,
unsigned char *addr)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
char ppad_pl[MLXSW_REG_PPAD_LEN];
mlxsw_reg_ppad_pack(ppad_pl, true, mlxsw_sp_port->local_port);
mlxsw_reg_ppad_mac_memcpy_to(ppad_pl, addr);
return mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(ppad), ppad_pl);
}
static int mlxsw_sp_port_dev_addr_init(struct mlxsw_sp_port *mlxsw_sp_port)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
unsigned char *addr = mlxsw_sp_port->dev->dev_addr;
ether_addr_copy(addr, mlxsw_sp->base_mac);
addr[ETH_ALEN - 1] += mlxsw_sp_port->local_port;
return mlxsw_sp_port_dev_addr_set(mlxsw_sp_port, addr);
}
static int mlxsw_sp_port_mtu_set(struct mlxsw_sp_port *mlxsw_sp_port, u16 mtu)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
char pmtu_pl[MLXSW_REG_PMTU_LEN];
int max_mtu;
int err;
mtu += MLXSW_TXHDR_LEN + ETH_HLEN;
mlxsw_reg_pmtu_pack(pmtu_pl, mlxsw_sp_port->local_port, 0);
err = mlxsw_reg_query(mlxsw_sp->core, MLXSW_REG(pmtu), pmtu_pl);
if (err)
return err;
max_mtu = mlxsw_reg_pmtu_max_mtu_get(pmtu_pl);
if (mtu > max_mtu)
return -EINVAL;
mlxsw_reg_pmtu_pack(pmtu_pl, mlxsw_sp_port->local_port, mtu);
return mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(pmtu), pmtu_pl);
}
static int __mlxsw_sp_port_swid_set(struct mlxsw_sp *mlxsw_sp, u8 local_port,
u8 swid)
{
char pspa_pl[MLXSW_REG_PSPA_LEN];
mlxsw_reg_pspa_pack(pspa_pl, swid, local_port);
return mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(pspa), pspa_pl);
}
static int mlxsw_sp_port_swid_set(struct mlxsw_sp_port *mlxsw_sp_port, u8 swid)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
return __mlxsw_sp_port_swid_set(mlxsw_sp, mlxsw_sp_port->local_port,
swid);
}
static int mlxsw_sp_port_vp_mode_set(struct mlxsw_sp_port *mlxsw_sp_port,
bool enable)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
char svpe_pl[MLXSW_REG_SVPE_LEN];
mlxsw_reg_svpe_pack(svpe_pl, mlxsw_sp_port->local_port, enable);
return mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(svpe), svpe_pl);
}
int mlxsw_sp_port_vid_to_fid_set(struct mlxsw_sp_port *mlxsw_sp_port,
enum mlxsw_reg_svfa_mt mt, bool valid, u16 fid,
u16 vid)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
char svfa_pl[MLXSW_REG_SVFA_LEN];
mlxsw_reg_svfa_pack(svfa_pl, mlxsw_sp_port->local_port, mt, valid,
fid, vid);
return mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(svfa), svfa_pl);
}
int __mlxsw_sp_port_vid_learning_set(struct mlxsw_sp_port *mlxsw_sp_port,
u16 vid_begin, u16 vid_end,
bool learn_enable)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
char *spvmlr_pl;
int err;
spvmlr_pl = kmalloc(MLXSW_REG_SPVMLR_LEN, GFP_KERNEL);
if (!spvmlr_pl)
return -ENOMEM;
mlxsw_reg_spvmlr_pack(spvmlr_pl, mlxsw_sp_port->local_port, vid_begin,
vid_end, learn_enable);
err = mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(spvmlr), spvmlr_pl);
kfree(spvmlr_pl);
return err;
}
static int mlxsw_sp_port_vid_learning_set(struct mlxsw_sp_port *mlxsw_sp_port,
u16 vid, bool learn_enable)
{
return __mlxsw_sp_port_vid_learning_set(mlxsw_sp_port, vid, vid,
learn_enable);
}
static int
mlxsw_sp_port_system_port_mapping_set(struct mlxsw_sp_port *mlxsw_sp_port)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
char sspr_pl[MLXSW_REG_SSPR_LEN];
mlxsw_reg_sspr_pack(sspr_pl, mlxsw_sp_port->local_port);
return mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(sspr), sspr_pl);
}
static int mlxsw_sp_port_module_info_get(struct mlxsw_sp *mlxsw_sp,
u8 local_port, u8 *p_module,
u8 *p_width, u8 *p_lane)
{
char pmlp_pl[MLXSW_REG_PMLP_LEN];
int err;
mlxsw_reg_pmlp_pack(pmlp_pl, local_port);
err = mlxsw_reg_query(mlxsw_sp->core, MLXSW_REG(pmlp), pmlp_pl);
if (err)
return err;
*p_module = mlxsw_reg_pmlp_module_get(pmlp_pl, 0);
*p_width = mlxsw_reg_pmlp_width_get(pmlp_pl);
*p_lane = mlxsw_reg_pmlp_tx_lane_get(pmlp_pl, 0);
return 0;
}
static int mlxsw_sp_port_module_map(struct mlxsw_sp *mlxsw_sp, u8 local_port,
u8 module, u8 width, u8 lane)
{
char pmlp_pl[MLXSW_REG_PMLP_LEN];
int i;
mlxsw_reg_pmlp_pack(pmlp_pl, local_port);
mlxsw_reg_pmlp_width_set(pmlp_pl, width);
for (i = 0; i < width; i++) {
mlxsw_reg_pmlp_module_set(pmlp_pl, i, module);
mlxsw_reg_pmlp_tx_lane_set(pmlp_pl, i, lane + i);
}
return mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(pmlp), pmlp_pl);
}
static int mlxsw_sp_port_module_unmap(struct mlxsw_sp *mlxsw_sp, u8 local_port)
{
char pmlp_pl[MLXSW_REG_PMLP_LEN];
mlxsw_reg_pmlp_pack(pmlp_pl, local_port);
mlxsw_reg_pmlp_width_set(pmlp_pl, 0);
return mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(pmlp), pmlp_pl);
}
static int mlxsw_sp_port_open(struct net_device *dev)
{
struct mlxsw_sp_port *mlxsw_sp_port = netdev_priv(dev);
int err;
err = mlxsw_sp_port_admin_status_set(mlxsw_sp_port, true);
if (err)
return err;
netif_start_queue(dev);
return 0;
}
static int mlxsw_sp_port_stop(struct net_device *dev)
{
struct mlxsw_sp_port *mlxsw_sp_port = netdev_priv(dev);
netif_stop_queue(dev);
return mlxsw_sp_port_admin_status_set(mlxsw_sp_port, false);
}
static netdev_tx_t mlxsw_sp_port_xmit(struct sk_buff *skb,
struct net_device *dev)
{
struct mlxsw_sp_port *mlxsw_sp_port = netdev_priv(dev);
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
struct mlxsw_sp_port_pcpu_stats *pcpu_stats;
const struct mlxsw_tx_info tx_info = {
.local_port = mlxsw_sp_port->local_port,
.is_emad = false,
};
u64 len;
int err;
if (mlxsw_core_skb_transmit_busy(mlxsw_sp->core, &tx_info))
return NETDEV_TX_BUSY;
if (unlikely(skb_headroom(skb) < MLXSW_TXHDR_LEN)) {
struct sk_buff *skb_orig = skb;
skb = skb_realloc_headroom(skb, MLXSW_TXHDR_LEN);
if (!skb) {
this_cpu_inc(mlxsw_sp_port->pcpu_stats->tx_dropped);
dev_kfree_skb_any(skb_orig);
return NETDEV_TX_OK;
}
dev_consume_skb_any(skb_orig);
}
if (eth_skb_pad(skb)) {
this_cpu_inc(mlxsw_sp_port->pcpu_stats->tx_dropped);
return NETDEV_TX_OK;
}
mlxsw_sp_txhdr_construct(skb, &tx_info);
len = skb->len - MLXSW_TXHDR_LEN;
err = mlxsw_core_skb_transmit(mlxsw_sp->core, skb, &tx_info);
if (!err) {
pcpu_stats = this_cpu_ptr(mlxsw_sp_port->pcpu_stats);
u64_stats_update_begin(&pcpu_stats->syncp);
pcpu_stats->tx_packets++;
pcpu_stats->tx_bytes += len;
u64_stats_update_end(&pcpu_stats->syncp);
} else {
this_cpu_inc(mlxsw_sp_port->pcpu_stats->tx_dropped);
dev_kfree_skb_any(skb);
}
return NETDEV_TX_OK;
}
static void mlxsw_sp_set_rx_mode(struct net_device *dev)
{
}
static int mlxsw_sp_port_set_mac_address(struct net_device *dev, void *p)
{
struct mlxsw_sp_port *mlxsw_sp_port = netdev_priv(dev);
struct sockaddr *addr = p;
int err;
if (!is_valid_ether_addr(addr->sa_data))
return -EADDRNOTAVAIL;
err = mlxsw_sp_port_dev_addr_set(mlxsw_sp_port, addr->sa_data);
if (err)
return err;
memcpy(dev->dev_addr, addr->sa_data, dev->addr_len);
return 0;
}
static u16 mlxsw_sp_pg_buf_threshold_get(const struct mlxsw_sp *mlxsw_sp,
int mtu)
{
return 2 * mlxsw_sp_bytes_cells(mlxsw_sp, mtu);
}
static u16 mlxsw_sp_pfc_delay_get(const struct mlxsw_sp *mlxsw_sp, int mtu,
u16 delay)
{
delay = mlxsw_sp_bytes_cells(mlxsw_sp, DIV_ROUND_UP(delay,
BITS_PER_BYTE));
return MLXSW_SP_CELL_FACTOR * delay + mlxsw_sp_bytes_cells(mlxsw_sp,
mtu);
}
static u16 mlxsw_sp_pg_buf_delay_get(const struct mlxsw_sp *mlxsw_sp, int mtu,
u16 delay, bool pfc, bool pause)
{
if (pfc)
return mlxsw_sp_pfc_delay_get(mlxsw_sp, mtu, delay);
else if (pause)
return mlxsw_sp_bytes_cells(mlxsw_sp, MLXSW_SP_PAUSE_DELAY);
else
return 0;
}
static void mlxsw_sp_pg_buf_pack(char *pbmc_pl, int index, u16 size, u16 thres,
bool lossy)
{
if (lossy)
mlxsw_reg_pbmc_lossy_buffer_pack(pbmc_pl, index, size);
else
mlxsw_reg_pbmc_lossless_buffer_pack(pbmc_pl, index, size,
thres);
}
int __mlxsw_sp_port_headroom_set(struct mlxsw_sp_port *mlxsw_sp_port, int mtu,
u8 *prio_tc, bool pause_en,
struct ieee_pfc *my_pfc)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
u8 pfc_en = !!my_pfc ? my_pfc->pfc_en : 0;
u16 delay = !!my_pfc ? my_pfc->delay : 0;
char pbmc_pl[MLXSW_REG_PBMC_LEN];
int i, j, err;
mlxsw_reg_pbmc_pack(pbmc_pl, mlxsw_sp_port->local_port, 0, 0);
err = mlxsw_reg_query(mlxsw_sp->core, MLXSW_REG(pbmc), pbmc_pl);
if (err)
return err;
for (i = 0; i < IEEE_8021QAZ_MAX_TCS; i++) {
bool configure = false;
bool pfc = false;
bool lossy;
u16 thres;
for (j = 0; j < IEEE_8021QAZ_MAX_TCS; j++) {
if (prio_tc[j] == i) {
pfc = pfc_en & BIT(j);
configure = true;
break;
}
}
if (!configure)
continue;
lossy = !(pfc || pause_en);
thres = mlxsw_sp_pg_buf_threshold_get(mlxsw_sp, mtu);
delay = mlxsw_sp_pg_buf_delay_get(mlxsw_sp, mtu, delay, pfc,
pause_en);
mlxsw_sp_pg_buf_pack(pbmc_pl, i, thres + delay, thres, lossy);
}
return mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(pbmc), pbmc_pl);
}
static int mlxsw_sp_port_headroom_set(struct mlxsw_sp_port *mlxsw_sp_port,
int mtu, bool pause_en)
{
u8 def_prio_tc[IEEE_8021QAZ_MAX_TCS] = {0};
bool dcb_en = !!mlxsw_sp_port->dcb.ets;
struct ieee_pfc *my_pfc;
u8 *prio_tc;
prio_tc = dcb_en ? mlxsw_sp_port->dcb.ets->prio_tc : def_prio_tc;
my_pfc = dcb_en ? mlxsw_sp_port->dcb.pfc : NULL;
return __mlxsw_sp_port_headroom_set(mlxsw_sp_port, mtu, prio_tc,
pause_en, my_pfc);
}
static int mlxsw_sp_port_change_mtu(struct net_device *dev, int mtu)
{
struct mlxsw_sp_port *mlxsw_sp_port = netdev_priv(dev);
bool pause_en = mlxsw_sp_port_is_pause_en(mlxsw_sp_port);
int err;
err = mlxsw_sp_port_headroom_set(mlxsw_sp_port, mtu, pause_en);
if (err)
return err;
err = mlxsw_sp_span_port_mtu_update(mlxsw_sp_port, mtu);
if (err)
goto err_span_port_mtu_update;
err = mlxsw_sp_port_mtu_set(mlxsw_sp_port, mtu);
if (err)
goto err_port_mtu_set;
dev->mtu = mtu;
return 0;
err_port_mtu_set:
mlxsw_sp_span_port_mtu_update(mlxsw_sp_port, dev->mtu);
err_span_port_mtu_update:
mlxsw_sp_port_headroom_set(mlxsw_sp_port, dev->mtu, pause_en);
return err;
}
static int
mlxsw_sp_port_get_sw_stats64(const struct net_device *dev,
struct rtnl_link_stats64 *stats)
{
struct mlxsw_sp_port *mlxsw_sp_port = netdev_priv(dev);
struct mlxsw_sp_port_pcpu_stats *p;
u64 rx_packets, rx_bytes, tx_packets, tx_bytes;
u32 tx_dropped = 0;
unsigned int start;
int i;
for_each_possible_cpu(i) {
p = per_cpu_ptr(mlxsw_sp_port->pcpu_stats, i);
do {
start = u64_stats_fetch_begin_irq(&p->syncp);
rx_packets = p->rx_packets;
rx_bytes = p->rx_bytes;
tx_packets = p->tx_packets;
tx_bytes = p->tx_bytes;
} while (u64_stats_fetch_retry_irq(&p->syncp, start));
stats->rx_packets += rx_packets;
stats->rx_bytes += rx_bytes;
stats->tx_packets += tx_packets;
stats->tx_bytes += tx_bytes;
tx_dropped += p->tx_dropped;
}
stats->tx_dropped = tx_dropped;
return 0;
}
static bool mlxsw_sp_port_has_offload_stats(const struct net_device *dev, int attr_id)
{
switch (attr_id) {
case IFLA_OFFLOAD_XSTATS_CPU_HIT:
return true;
}
return false;
}
static int mlxsw_sp_port_get_offload_stats(int attr_id, const struct net_device *dev,
void *sp)
{
switch (attr_id) {
case IFLA_OFFLOAD_XSTATS_CPU_HIT:
return mlxsw_sp_port_get_sw_stats64(dev, sp);
}
return -EINVAL;
}
static int mlxsw_sp_port_get_stats_raw(struct net_device *dev, int grp,
int prio, char *ppcnt_pl)
{
struct mlxsw_sp_port *mlxsw_sp_port = netdev_priv(dev);
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
mlxsw_reg_ppcnt_pack(ppcnt_pl, mlxsw_sp_port->local_port, grp, prio);
return mlxsw_reg_query(mlxsw_sp->core, MLXSW_REG(ppcnt), ppcnt_pl);
}
static int mlxsw_sp_port_get_hw_stats(struct net_device *dev,
struct rtnl_link_stats64 *stats)
{
char ppcnt_pl[MLXSW_REG_PPCNT_LEN];
int err;
err = mlxsw_sp_port_get_stats_raw(dev, MLXSW_REG_PPCNT_IEEE_8023_CNT,
0, ppcnt_pl);
if (err)
goto out;
stats->tx_packets =
mlxsw_reg_ppcnt_a_frames_transmitted_ok_get(ppcnt_pl);
stats->rx_packets =
mlxsw_reg_ppcnt_a_frames_received_ok_get(ppcnt_pl);
stats->tx_bytes =
mlxsw_reg_ppcnt_a_octets_transmitted_ok_get(ppcnt_pl);
stats->rx_bytes =
mlxsw_reg_ppcnt_a_octets_received_ok_get(ppcnt_pl);
stats->multicast =
mlxsw_reg_ppcnt_a_multicast_frames_received_ok_get(ppcnt_pl);
stats->rx_crc_errors =
mlxsw_reg_ppcnt_a_frame_check_sequence_errors_get(ppcnt_pl);
stats->rx_frame_errors =
mlxsw_reg_ppcnt_a_alignment_errors_get(ppcnt_pl);
stats->rx_length_errors = (
mlxsw_reg_ppcnt_a_in_range_length_errors_get(ppcnt_pl) +
mlxsw_reg_ppcnt_a_out_of_range_length_field_get(ppcnt_pl) +
mlxsw_reg_ppcnt_a_frame_too_long_errors_get(ppcnt_pl));
stats->rx_errors = (stats->rx_crc_errors +
stats->rx_frame_errors + stats->rx_length_errors);
out:
return err;
}
static void update_stats_cache(struct work_struct *work)
{
struct mlxsw_sp_port *mlxsw_sp_port =
container_of(work, struct mlxsw_sp_port,
hw_stats.update_dw.work);
if (!netif_carrier_ok(mlxsw_sp_port->dev))
goto out;
mlxsw_sp_port_get_hw_stats(mlxsw_sp_port->dev,
mlxsw_sp_port->hw_stats.cache);
out:
mlxsw_core_schedule_dw(&mlxsw_sp_port->hw_stats.update_dw,
MLXSW_HW_STATS_UPDATE_TIME);
}
static void
mlxsw_sp_port_get_stats64(struct net_device *dev,
struct rtnl_link_stats64 *stats)
{
struct mlxsw_sp_port *mlxsw_sp_port = netdev_priv(dev);
memcpy(stats, mlxsw_sp_port->hw_stats.cache, sizeof(*stats));
}
static int __mlxsw_sp_port_vlan_set(struct mlxsw_sp_port *mlxsw_sp_port,
u16 vid_begin, u16 vid_end,
bool is_member, bool untagged)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
char *spvm_pl;
int err;
spvm_pl = kmalloc(MLXSW_REG_SPVM_LEN, GFP_KERNEL);
if (!spvm_pl)
return -ENOMEM;
mlxsw_reg_spvm_pack(spvm_pl, mlxsw_sp_port->local_port, vid_begin,
vid_end, is_member, untagged);
err = mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(spvm), spvm_pl);
kfree(spvm_pl);
return err;
}
int mlxsw_sp_port_vlan_set(struct mlxsw_sp_port *mlxsw_sp_port, u16 vid_begin,
u16 vid_end, bool is_member, bool untagged)
{
u16 vid, vid_e;
int err;
for (vid = vid_begin; vid <= vid_end;
vid += MLXSW_REG_SPVM_REC_MAX_COUNT) {
vid_e = min((u16) (vid + MLXSW_REG_SPVM_REC_MAX_COUNT - 1),
vid_end);
err = __mlxsw_sp_port_vlan_set(mlxsw_sp_port, vid, vid_e,
is_member, untagged);
if (err)
return err;
}
return 0;
}
static int mlxsw_sp_port_vp_mode_trans(struct mlxsw_sp_port *mlxsw_sp_port)
{
enum mlxsw_reg_svfa_mt mt = MLXSW_REG_SVFA_MT_PORT_VID_TO_FID;
u16 vid, last_visited_vid;
int err;
for_each_set_bit(vid, mlxsw_sp_port->active_vlans, VLAN_N_VID) {
err = mlxsw_sp_port_vid_to_fid_set(mlxsw_sp_port, mt, true, vid,
vid);
if (err) {
last_visited_vid = vid;
goto err_port_vid_to_fid_set;
}
}
err = mlxsw_sp_port_vp_mode_set(mlxsw_sp_port, true);
if (err) {
last_visited_vid = VLAN_N_VID;
goto err_port_vid_to_fid_set;
}
return 0;
err_port_vid_to_fid_set:
for_each_set_bit(vid, mlxsw_sp_port->active_vlans, last_visited_vid)
mlxsw_sp_port_vid_to_fid_set(mlxsw_sp_port, mt, false, vid,
vid);
return err;
}
static int mlxsw_sp_port_vlan_mode_trans(struct mlxsw_sp_port *mlxsw_sp_port)
{
enum mlxsw_reg_svfa_mt mt = MLXSW_REG_SVFA_MT_PORT_VID_TO_FID;
u16 vid;
int err;
err = mlxsw_sp_port_vp_mode_set(mlxsw_sp_port, false);
if (err)
return err;
for_each_set_bit(vid, mlxsw_sp_port->active_vlans, VLAN_N_VID) {
err = mlxsw_sp_port_vid_to_fid_set(mlxsw_sp_port, mt, false,
vid, vid);
if (err)
return err;
}
return 0;
}
static struct mlxsw_sp_port *
mlxsw_sp_port_vport_create(struct mlxsw_sp_port *mlxsw_sp_port, u16 vid)
{
struct mlxsw_sp_port *mlxsw_sp_vport;
mlxsw_sp_vport = kzalloc(sizeof(*mlxsw_sp_vport), GFP_KERNEL);
if (!mlxsw_sp_vport)
return NULL;
mlxsw_sp_vport->dev = mlxsw_sp_port->dev;
mlxsw_sp_vport->mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
mlxsw_sp_vport->local_port = mlxsw_sp_port->local_port;
mlxsw_sp_vport->stp_state = BR_STATE_FORWARDING;
mlxsw_sp_vport->lagged = mlxsw_sp_port->lagged;
mlxsw_sp_vport->lag_id = mlxsw_sp_port->lag_id;
mlxsw_sp_vport->vport.vid = vid;
list_add(&mlxsw_sp_vport->vport.list, &mlxsw_sp_port->vports_list);
return mlxsw_sp_vport;
}
static void mlxsw_sp_port_vport_destroy(struct mlxsw_sp_port *mlxsw_sp_vport)
{
list_del(&mlxsw_sp_vport->vport.list);
kfree(mlxsw_sp_vport);
}
static int mlxsw_sp_port_add_vid(struct net_device *dev,
__be16 __always_unused proto, u16 vid)
{
struct mlxsw_sp_port *mlxsw_sp_port = netdev_priv(dev);
struct mlxsw_sp_port *mlxsw_sp_vport;
bool untagged = vid == 1;
int err;
if (!vid)
return 0;
if (mlxsw_sp_port_vport_find(mlxsw_sp_port, vid))
return 0;
mlxsw_sp_vport = mlxsw_sp_port_vport_create(mlxsw_sp_port, vid);
if (!mlxsw_sp_vport)
return -ENOMEM;
if (list_is_singular(&mlxsw_sp_port->vports_list)) {
err = mlxsw_sp_port_vp_mode_trans(mlxsw_sp_port);
if (err)
goto err_port_vp_mode_trans;
}
err = mlxsw_sp_port_vlan_set(mlxsw_sp_vport, vid, vid, true, untagged);
if (err)
goto err_port_add_vid;
return 0;
err_port_add_vid:
if (list_is_singular(&mlxsw_sp_port->vports_list))
mlxsw_sp_port_vlan_mode_trans(mlxsw_sp_port);
err_port_vp_mode_trans:
mlxsw_sp_port_vport_destroy(mlxsw_sp_vport);
return err;
}
static int mlxsw_sp_port_kill_vid(struct net_device *dev,
__be16 __always_unused proto, u16 vid)
{
struct mlxsw_sp_port *mlxsw_sp_port = netdev_priv(dev);
struct mlxsw_sp_port *mlxsw_sp_vport;
struct mlxsw_sp_fid *f;
if (!vid)
return 0;
mlxsw_sp_vport = mlxsw_sp_port_vport_find(mlxsw_sp_port, vid);
if (WARN_ON(!mlxsw_sp_vport))
return 0;
mlxsw_sp_port_vlan_set(mlxsw_sp_vport, vid, vid, false, false);
f = mlxsw_sp_vport_fid_get(mlxsw_sp_vport);
if (f && !WARN_ON(!f->leave))
f->leave(mlxsw_sp_vport);
if (list_is_singular(&mlxsw_sp_port->vports_list))
mlxsw_sp_port_vlan_mode_trans(mlxsw_sp_port);
mlxsw_sp_port_vport_destroy(mlxsw_sp_vport);
return 0;
}
static int mlxsw_sp_port_get_phys_port_name(struct net_device *dev, char *name,
size_t len)
{
struct mlxsw_sp_port *mlxsw_sp_port = netdev_priv(dev);
u8 module = mlxsw_sp_port->mapping.module;
u8 width = mlxsw_sp_port->mapping.width;
u8 lane = mlxsw_sp_port->mapping.lane;
int err;
if (!mlxsw_sp_port->split)
err = snprintf(name, len, "p%d", module + 1);
else
err = snprintf(name, len, "p%ds%d", module + 1,
lane / width);
if (err >= len)
return -EINVAL;
return 0;
}
static struct mlxsw_sp_port_mall_tc_entry *
mlxsw_sp_port_mall_tc_entry_find(struct mlxsw_sp_port *port,
unsigned long cookie) {
struct mlxsw_sp_port_mall_tc_entry *mall_tc_entry;
list_for_each_entry(mall_tc_entry, &port->mall_tc_list, list)
if (mall_tc_entry->cookie == cookie)
return mall_tc_entry;
return NULL;
}
static int
mlxsw_sp_port_add_cls_matchall_mirror(struct mlxsw_sp_port *mlxsw_sp_port,
struct mlxsw_sp_port_mall_mirror_tc_entry *mirror,
const struct tc_action *a,
bool ingress)
{
struct net *net = dev_net(mlxsw_sp_port->dev);
enum mlxsw_sp_span_type span_type;
struct mlxsw_sp_port *to_port;
struct net_device *to_dev;
int ifindex;
ifindex = tcf_mirred_ifindex(a);
to_dev = __dev_get_by_index(net, ifindex);
if (!to_dev) {
netdev_err(mlxsw_sp_port->dev, "Could not find requested device\n");
return -EINVAL;
}
if (!mlxsw_sp_port_dev_check(to_dev)) {
netdev_err(mlxsw_sp_port->dev, "Cannot mirror to a non-spectrum port");
return -EOPNOTSUPP;
}
to_port = netdev_priv(to_dev);
mirror->to_local_port = to_port->local_port;
mirror->ingress = ingress;
span_type = ingress ? MLXSW_SP_SPAN_INGRESS : MLXSW_SP_SPAN_EGRESS;
return mlxsw_sp_span_mirror_add(mlxsw_sp_port, to_port, span_type);
}
static void
mlxsw_sp_port_del_cls_matchall_mirror(struct mlxsw_sp_port *mlxsw_sp_port,
struct mlxsw_sp_port_mall_mirror_tc_entry *mirror)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
enum mlxsw_sp_span_type span_type;
struct mlxsw_sp_port *to_port;
to_port = mlxsw_sp->ports[mirror->to_local_port];
span_type = mirror->ingress ?
MLXSW_SP_SPAN_INGRESS : MLXSW_SP_SPAN_EGRESS;
mlxsw_sp_span_mirror_remove(mlxsw_sp_port, to_port, span_type);
}
static int
mlxsw_sp_port_add_cls_matchall_sample(struct mlxsw_sp_port *mlxsw_sp_port,
struct tc_cls_matchall_offload *cls,
const struct tc_action *a,
bool ingress)
{
int err;
if (!mlxsw_sp_port->sample)
return -EOPNOTSUPP;
if (rtnl_dereference(mlxsw_sp_port->sample->psample_group)) {
netdev_err(mlxsw_sp_port->dev, "sample already active\n");
return -EEXIST;
}
if (tcf_sample_rate(a) > MLXSW_REG_MPSC_RATE_MAX) {
netdev_err(mlxsw_sp_port->dev, "sample rate not supported\n");
return -EOPNOTSUPP;
}
rcu_assign_pointer(mlxsw_sp_port->sample->psample_group,
tcf_sample_psample_group(a));
mlxsw_sp_port->sample->truncate = tcf_sample_truncate(a);
mlxsw_sp_port->sample->trunc_size = tcf_sample_trunc_size(a);
mlxsw_sp_port->sample->rate = tcf_sample_rate(a);
err = mlxsw_sp_port_sample_set(mlxsw_sp_port, true, tcf_sample_rate(a));
if (err)
goto err_port_sample_set;
return 0;
err_port_sample_set:
RCU_INIT_POINTER(mlxsw_sp_port->sample->psample_group, NULL);
return err;
}
static void
mlxsw_sp_port_del_cls_matchall_sample(struct mlxsw_sp_port *mlxsw_sp_port)
{
if (!mlxsw_sp_port->sample)
return;
mlxsw_sp_port_sample_set(mlxsw_sp_port, false, 1);
RCU_INIT_POINTER(mlxsw_sp_port->sample->psample_group, NULL);
}
static int mlxsw_sp_port_add_cls_matchall(struct mlxsw_sp_port *mlxsw_sp_port,
__be16 protocol,
struct tc_cls_matchall_offload *cls,
bool ingress)
{
struct mlxsw_sp_port_mall_tc_entry *mall_tc_entry;
const struct tc_action *a;
LIST_HEAD(actions);
int err;
if (!tc_single_action(cls->exts)) {
netdev_err(mlxsw_sp_port->dev, "only singular actions are supported\n");
return -EOPNOTSUPP;
}
mall_tc_entry = kzalloc(sizeof(*mall_tc_entry), GFP_KERNEL);
if (!mall_tc_entry)
return -ENOMEM;
mall_tc_entry->cookie = cls->cookie;
tcf_exts_to_list(cls->exts, &actions);
a = list_first_entry(&actions, struct tc_action, list);
if (is_tcf_mirred_egress_mirror(a) && protocol == htons(ETH_P_ALL)) {
struct mlxsw_sp_port_mall_mirror_tc_entry *mirror;
mall_tc_entry->type = MLXSW_SP_PORT_MALL_MIRROR;
mirror = &mall_tc_entry->mirror;
err = mlxsw_sp_port_add_cls_matchall_mirror(mlxsw_sp_port,
mirror, a, ingress);
} else if (is_tcf_sample(a) && protocol == htons(ETH_P_ALL)) {
mall_tc_entry->type = MLXSW_SP_PORT_MALL_SAMPLE;
err = mlxsw_sp_port_add_cls_matchall_sample(mlxsw_sp_port, cls,
a, ingress);
} else {
err = -EOPNOTSUPP;
}
if (err)
goto err_add_action;
list_add_tail(&mall_tc_entry->list, &mlxsw_sp_port->mall_tc_list);
return 0;
err_add_action:
kfree(mall_tc_entry);
return err;
}
static void mlxsw_sp_port_del_cls_matchall(struct mlxsw_sp_port *mlxsw_sp_port,
struct tc_cls_matchall_offload *cls)
{
struct mlxsw_sp_port_mall_tc_entry *mall_tc_entry;
mall_tc_entry = mlxsw_sp_port_mall_tc_entry_find(mlxsw_sp_port,
cls->cookie);
if (!mall_tc_entry) {
netdev_dbg(mlxsw_sp_port->dev, "tc entry not found on port\n");
return;
}
list_del(&mall_tc_entry->list);
switch (mall_tc_entry->type) {
case MLXSW_SP_PORT_MALL_MIRROR:
mlxsw_sp_port_del_cls_matchall_mirror(mlxsw_sp_port,
&mall_tc_entry->mirror);
break;
case MLXSW_SP_PORT_MALL_SAMPLE:
mlxsw_sp_port_del_cls_matchall_sample(mlxsw_sp_port);
break;
default:
WARN_ON(1);
}
kfree(mall_tc_entry);
}
static int mlxsw_sp_setup_tc(struct net_device *dev, u32 handle,
__be16 proto, struct tc_to_netdev *tc)
{
struct mlxsw_sp_port *mlxsw_sp_port = netdev_priv(dev);
bool ingress = TC_H_MAJ(handle) == TC_H_MAJ(TC_H_INGRESS);
switch (tc->type) {
case TC_SETUP_MATCHALL:
switch (tc->cls_mall->command) {
case TC_CLSMATCHALL_REPLACE:
return mlxsw_sp_port_add_cls_matchall(mlxsw_sp_port,
proto,
tc->cls_mall,
ingress);
case TC_CLSMATCHALL_DESTROY:
mlxsw_sp_port_del_cls_matchall(mlxsw_sp_port,
tc->cls_mall);
return 0;
default:
return -EOPNOTSUPP;
}
case TC_SETUP_CLSFLOWER:
switch (tc->cls_flower->command) {
case TC_CLSFLOWER_REPLACE:
return mlxsw_sp_flower_replace(mlxsw_sp_port, ingress,
proto, tc->cls_flower);
case TC_CLSFLOWER_DESTROY:
mlxsw_sp_flower_destroy(mlxsw_sp_port, ingress,
tc->cls_flower);
return 0;
case TC_CLSFLOWER_STATS:
return mlxsw_sp_flower_stats(mlxsw_sp_port, ingress,
tc->cls_flower);
default:
return -EOPNOTSUPP;
}
}
return -EOPNOTSUPP;
}
static void mlxsw_sp_port_get_drvinfo(struct net_device *dev,
struct ethtool_drvinfo *drvinfo)
{
struct mlxsw_sp_port *mlxsw_sp_port = netdev_priv(dev);
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
strlcpy(drvinfo->driver, mlxsw_sp_driver_name, sizeof(drvinfo->driver));
strlcpy(drvinfo->version, mlxsw_sp_driver_version,
sizeof(drvinfo->version));
snprintf(drvinfo->fw_version, sizeof(drvinfo->fw_version),
"%d.%d.%d",
mlxsw_sp->bus_info->fw_rev.major,
mlxsw_sp->bus_info->fw_rev.minor,
mlxsw_sp->bus_info->fw_rev.subminor);
strlcpy(drvinfo->bus_info, mlxsw_sp->bus_info->device_name,
sizeof(drvinfo->bus_info));
}
static void mlxsw_sp_port_get_pauseparam(struct net_device *dev,
struct ethtool_pauseparam *pause)
{
struct mlxsw_sp_port *mlxsw_sp_port = netdev_priv(dev);
pause->rx_pause = mlxsw_sp_port->link.rx_pause;
pause->tx_pause = mlxsw_sp_port->link.tx_pause;
}
static int mlxsw_sp_port_pause_set(struct mlxsw_sp_port *mlxsw_sp_port,
struct ethtool_pauseparam *pause)
{
char pfcc_pl[MLXSW_REG_PFCC_LEN];
mlxsw_reg_pfcc_pack(pfcc_pl, mlxsw_sp_port->local_port);
mlxsw_reg_pfcc_pprx_set(pfcc_pl, pause->rx_pause);
mlxsw_reg_pfcc_pptx_set(pfcc_pl, pause->tx_pause);
return mlxsw_reg_write(mlxsw_sp_port->mlxsw_sp->core, MLXSW_REG(pfcc),
pfcc_pl);
}
static int mlxsw_sp_port_set_pauseparam(struct net_device *dev,
struct ethtool_pauseparam *pause)
{
struct mlxsw_sp_port *mlxsw_sp_port = netdev_priv(dev);
bool pause_en = pause->tx_pause || pause->rx_pause;
int err;
if (mlxsw_sp_port->dcb.pfc && mlxsw_sp_port->dcb.pfc->pfc_en) {
netdev_err(dev, "PFC already enabled on port\n");
return -EINVAL;
}
if (pause->autoneg) {
netdev_err(dev, "PAUSE frames autonegotiation isn't supported\n");
return -EINVAL;
}
err = mlxsw_sp_port_headroom_set(mlxsw_sp_port, dev->mtu, pause_en);
if (err) {
netdev_err(dev, "Failed to configure port's headroom\n");
return err;
}
err = mlxsw_sp_port_pause_set(mlxsw_sp_port, pause);
if (err) {
netdev_err(dev, "Failed to set PAUSE parameters\n");
goto err_port_pause_configure;
}
mlxsw_sp_port->link.rx_pause = pause->rx_pause;
mlxsw_sp_port->link.tx_pause = pause->tx_pause;
return 0;
err_port_pause_configure:
pause_en = mlxsw_sp_port_is_pause_en(mlxsw_sp_port);
mlxsw_sp_port_headroom_set(mlxsw_sp_port, dev->mtu, pause_en);
return err;
}
static void mlxsw_sp_port_get_prio_strings(u8 **p, int prio)
{
int i;
for (i = 0; i < MLXSW_SP_PORT_HW_PRIO_STATS_LEN; i++) {
snprintf(*p, ETH_GSTRING_LEN, "%s_%d",
mlxsw_sp_port_hw_prio_stats[i].str, prio);
*p += ETH_GSTRING_LEN;
}
}
static void mlxsw_sp_port_get_tc_strings(u8 **p, int tc)
{
int i;
for (i = 0; i < MLXSW_SP_PORT_HW_TC_STATS_LEN; i++) {
snprintf(*p, ETH_GSTRING_LEN, "%s_%d",
mlxsw_sp_port_hw_tc_stats[i].str, tc);
*p += ETH_GSTRING_LEN;
}
}
static void mlxsw_sp_port_get_strings(struct net_device *dev,
u32 stringset, u8 *data)
{
u8 *p = data;
int i;
switch (stringset) {
case ETH_SS_STATS:
for (i = 0; i < MLXSW_SP_PORT_HW_STATS_LEN; i++) {
memcpy(p, mlxsw_sp_port_hw_stats[i].str,
ETH_GSTRING_LEN);
p += ETH_GSTRING_LEN;
}
for (i = 0; i < IEEE_8021QAZ_MAX_TCS; i++)
mlxsw_sp_port_get_prio_strings(&p, i);
for (i = 0; i < IEEE_8021QAZ_MAX_TCS; i++)
mlxsw_sp_port_get_tc_strings(&p, i);
break;
}
}
static int mlxsw_sp_port_set_phys_id(struct net_device *dev,
enum ethtool_phys_id_state state)
{
struct mlxsw_sp_port *mlxsw_sp_port = netdev_priv(dev);
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
char mlcr_pl[MLXSW_REG_MLCR_LEN];
bool active;
switch (state) {
case ETHTOOL_ID_ACTIVE:
active = true;
break;
case ETHTOOL_ID_INACTIVE:
active = false;
break;
default:
return -EOPNOTSUPP;
}
mlxsw_reg_mlcr_pack(mlcr_pl, mlxsw_sp_port->local_port, active);
return mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(mlcr), mlcr_pl);
}
static int
mlxsw_sp_get_hw_stats_by_group(struct mlxsw_sp_port_hw_stats **p_hw_stats,
int *p_len, enum mlxsw_reg_ppcnt_grp grp)
{
switch (grp) {
case MLXSW_REG_PPCNT_IEEE_8023_CNT:
*p_hw_stats = mlxsw_sp_port_hw_stats;
*p_len = MLXSW_SP_PORT_HW_STATS_LEN;
break;
case MLXSW_REG_PPCNT_PRIO_CNT:
*p_hw_stats = mlxsw_sp_port_hw_prio_stats;
*p_len = MLXSW_SP_PORT_HW_PRIO_STATS_LEN;
break;
case MLXSW_REG_PPCNT_TC_CNT:
*p_hw_stats = mlxsw_sp_port_hw_tc_stats;
*p_len = MLXSW_SP_PORT_HW_TC_STATS_LEN;
break;
default:
WARN_ON(1);
return -EOPNOTSUPP;
}
return 0;
}
static void __mlxsw_sp_port_get_stats(struct net_device *dev,
enum mlxsw_reg_ppcnt_grp grp, int prio,
u64 *data, int data_index)
{
struct mlxsw_sp_port *mlxsw_sp_port = netdev_priv(dev);
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
struct mlxsw_sp_port_hw_stats *hw_stats;
char ppcnt_pl[MLXSW_REG_PPCNT_LEN];
int i, len;
int err;
err = mlxsw_sp_get_hw_stats_by_group(&hw_stats, &len, grp);
if (err)
return;
mlxsw_sp_port_get_stats_raw(dev, grp, prio, ppcnt_pl);
for (i = 0; i < len; i++) {
data[data_index + i] = hw_stats[i].getter(ppcnt_pl);
if (!hw_stats[i].cells_bytes)
continue;
data[data_index + i] = mlxsw_sp_cells_bytes(mlxsw_sp,
data[data_index + i]);
}
}
static void mlxsw_sp_port_get_stats(struct net_device *dev,
struct ethtool_stats *stats, u64 *data)
{
int i, data_index = 0;
__mlxsw_sp_port_get_stats(dev, MLXSW_REG_PPCNT_IEEE_8023_CNT, 0,
data, data_index);
data_index = MLXSW_SP_PORT_HW_STATS_LEN;
for (i = 0; i < IEEE_8021QAZ_MAX_TCS; i++) {
__mlxsw_sp_port_get_stats(dev, MLXSW_REG_PPCNT_PRIO_CNT, i,
data, data_index);
data_index += MLXSW_SP_PORT_HW_PRIO_STATS_LEN;
}
for (i = 0; i < IEEE_8021QAZ_MAX_TCS; i++) {
__mlxsw_sp_port_get_stats(dev, MLXSW_REG_PPCNT_TC_CNT, i,
data, data_index);
data_index += MLXSW_SP_PORT_HW_TC_STATS_LEN;
}
}
static int mlxsw_sp_port_get_sset_count(struct net_device *dev, int sset)
{
switch (sset) {
case ETH_SS_STATS:
return MLXSW_SP_PORT_ETHTOOL_STATS_LEN;
default:
return -EOPNOTSUPP;
}
}
static void
mlxsw_sp_from_ptys_supported_port(u32 ptys_eth_proto,
struct ethtool_link_ksettings *cmd)
{
if (ptys_eth_proto & (MLXSW_REG_PTYS_ETH_SPEED_10GBASE_CR |
MLXSW_REG_PTYS_ETH_SPEED_10GBASE_SR |
MLXSW_REG_PTYS_ETH_SPEED_40GBASE_CR4 |
MLXSW_REG_PTYS_ETH_SPEED_40GBASE_SR4 |
MLXSW_REG_PTYS_ETH_SPEED_100GBASE_SR4 |
MLXSW_REG_PTYS_ETH_SPEED_SGMII))
ethtool_link_ksettings_add_link_mode(cmd, supported, FIBRE);
if (ptys_eth_proto & (MLXSW_REG_PTYS_ETH_SPEED_10GBASE_KR |
MLXSW_REG_PTYS_ETH_SPEED_10GBASE_KX4 |
MLXSW_REG_PTYS_ETH_SPEED_40GBASE_KR4 |
MLXSW_REG_PTYS_ETH_SPEED_100GBASE_KR4 |
MLXSW_REG_PTYS_ETH_SPEED_1000BASE_KX))
ethtool_link_ksettings_add_link_mode(cmd, supported, Backplane);
}
static void mlxsw_sp_from_ptys_link(u32 ptys_eth_proto, unsigned long *mode)
{
int i;
for (i = 0; i < MLXSW_SP_PORT_LINK_MODE_LEN; i++) {
if (ptys_eth_proto & mlxsw_sp_port_link_mode[i].mask)
__set_bit(mlxsw_sp_port_link_mode[i].mask_ethtool,
mode);
}
}
static void mlxsw_sp_from_ptys_speed_duplex(bool carrier_ok, u32 ptys_eth_proto,
struct ethtool_link_ksettings *cmd)
{
u32 speed = SPEED_UNKNOWN;
u8 duplex = DUPLEX_UNKNOWN;
int i;
if (!carrier_ok)
goto out;
for (i = 0; i < MLXSW_SP_PORT_LINK_MODE_LEN; i++) {
if (ptys_eth_proto & mlxsw_sp_port_link_mode[i].mask) {
speed = mlxsw_sp_port_link_mode[i].speed;
duplex = DUPLEX_FULL;
break;
}
}
out:
cmd->base.speed = speed;
cmd->base.duplex = duplex;
}
static u8 mlxsw_sp_port_connector_port(u32 ptys_eth_proto)
{
if (ptys_eth_proto & (MLXSW_REG_PTYS_ETH_SPEED_10GBASE_SR |
MLXSW_REG_PTYS_ETH_SPEED_40GBASE_SR4 |
MLXSW_REG_PTYS_ETH_SPEED_100GBASE_SR4 |
MLXSW_REG_PTYS_ETH_SPEED_SGMII))
return PORT_FIBRE;
if (ptys_eth_proto & (MLXSW_REG_PTYS_ETH_SPEED_10GBASE_CR |
MLXSW_REG_PTYS_ETH_SPEED_40GBASE_CR4 |
MLXSW_REG_PTYS_ETH_SPEED_100GBASE_CR4))
return PORT_DA;
if (ptys_eth_proto & (MLXSW_REG_PTYS_ETH_SPEED_10GBASE_KR |
MLXSW_REG_PTYS_ETH_SPEED_10GBASE_KX4 |
MLXSW_REG_PTYS_ETH_SPEED_40GBASE_KR4 |
MLXSW_REG_PTYS_ETH_SPEED_100GBASE_KR4))
return PORT_NONE;
return PORT_OTHER;
}
static u32
mlxsw_sp_to_ptys_advert_link(const struct ethtool_link_ksettings *cmd)
{
u32 ptys_proto = 0;
int i;
for (i = 0; i < MLXSW_SP_PORT_LINK_MODE_LEN; i++) {
if (test_bit(mlxsw_sp_port_link_mode[i].mask_ethtool,
cmd->link_modes.advertising))
ptys_proto |= mlxsw_sp_port_link_mode[i].mask;
}
return ptys_proto;
}
static u32 mlxsw_sp_to_ptys_speed(u32 speed)
{
u32 ptys_proto = 0;
int i;
for (i = 0; i < MLXSW_SP_PORT_LINK_MODE_LEN; i++) {
if (speed == mlxsw_sp_port_link_mode[i].speed)
ptys_proto |= mlxsw_sp_port_link_mode[i].mask;
}
return ptys_proto;
}
static u32 mlxsw_sp_to_ptys_upper_speed(u32 upper_speed)
{
u32 ptys_proto = 0;
int i;
for (i = 0; i < MLXSW_SP_PORT_LINK_MODE_LEN; i++) {
if (mlxsw_sp_port_link_mode[i].speed <= upper_speed)
ptys_proto |= mlxsw_sp_port_link_mode[i].mask;
}
return ptys_proto;
}
static void mlxsw_sp_port_get_link_supported(u32 eth_proto_cap,
struct ethtool_link_ksettings *cmd)
{
ethtool_link_ksettings_add_link_mode(cmd, supported, Asym_Pause);
ethtool_link_ksettings_add_link_mode(cmd, supported, Autoneg);
ethtool_link_ksettings_add_link_mode(cmd, supported, Pause);
mlxsw_sp_from_ptys_supported_port(eth_proto_cap, cmd);
mlxsw_sp_from_ptys_link(eth_proto_cap, cmd->link_modes.supported);
}
static void mlxsw_sp_port_get_link_advertise(u32 eth_proto_admin, bool autoneg,
struct ethtool_link_ksettings *cmd)
{
if (!autoneg)
return;
ethtool_link_ksettings_add_link_mode(cmd, advertising, Autoneg);
mlxsw_sp_from_ptys_link(eth_proto_admin, cmd->link_modes.advertising);
}
static void
mlxsw_sp_port_get_link_lp_advertise(u32 eth_proto_lp, u8 autoneg_status,
struct ethtool_link_ksettings *cmd)
{
if (autoneg_status != MLXSW_REG_PTYS_AN_STATUS_OK || !eth_proto_lp)
return;
ethtool_link_ksettings_add_link_mode(cmd, lp_advertising, Autoneg);
mlxsw_sp_from_ptys_link(eth_proto_lp, cmd->link_modes.lp_advertising);
}
static int mlxsw_sp_port_get_link_ksettings(struct net_device *dev,
struct ethtool_link_ksettings *cmd)
{
u32 eth_proto_cap, eth_proto_admin, eth_proto_oper, eth_proto_lp;
struct mlxsw_sp_port *mlxsw_sp_port = netdev_priv(dev);
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
char ptys_pl[MLXSW_REG_PTYS_LEN];
u8 autoneg_status;
bool autoneg;
int err;
autoneg = mlxsw_sp_port->link.autoneg;
mlxsw_reg_ptys_eth_pack(ptys_pl, mlxsw_sp_port->local_port, 0);
err = mlxsw_reg_query(mlxsw_sp->core, MLXSW_REG(ptys), ptys_pl);
if (err)
return err;
mlxsw_reg_ptys_eth_unpack(ptys_pl, &eth_proto_cap, &eth_proto_admin,
&eth_proto_oper);
mlxsw_sp_port_get_link_supported(eth_proto_cap, cmd);
mlxsw_sp_port_get_link_advertise(eth_proto_admin, autoneg, cmd);
eth_proto_lp = mlxsw_reg_ptys_eth_proto_lp_advertise_get(ptys_pl);
autoneg_status = mlxsw_reg_ptys_an_status_get(ptys_pl);
mlxsw_sp_port_get_link_lp_advertise(eth_proto_lp, autoneg_status, cmd);
cmd->base.autoneg = autoneg ? AUTONEG_ENABLE : AUTONEG_DISABLE;
cmd->base.port = mlxsw_sp_port_connector_port(eth_proto_oper);
mlxsw_sp_from_ptys_speed_duplex(netif_carrier_ok(dev), eth_proto_oper,
cmd);
return 0;
}
static int
mlxsw_sp_port_set_link_ksettings(struct net_device *dev,
const struct ethtool_link_ksettings *cmd)
{
struct mlxsw_sp_port *mlxsw_sp_port = netdev_priv(dev);
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
char ptys_pl[MLXSW_REG_PTYS_LEN];
u32 eth_proto_cap, eth_proto_new;
bool autoneg;
int err;
mlxsw_reg_ptys_eth_pack(ptys_pl, mlxsw_sp_port->local_port, 0);
err = mlxsw_reg_query(mlxsw_sp->core, MLXSW_REG(ptys), ptys_pl);
if (err)
return err;
mlxsw_reg_ptys_eth_unpack(ptys_pl, &eth_proto_cap, NULL, NULL);
autoneg = cmd->base.autoneg == AUTONEG_ENABLE;
eth_proto_new = autoneg ?
mlxsw_sp_to_ptys_advert_link(cmd) :
mlxsw_sp_to_ptys_speed(cmd->base.speed);
eth_proto_new = eth_proto_new & eth_proto_cap;
if (!eth_proto_new) {
netdev_err(dev, "No supported speed requested\n");
return -EINVAL;
}
mlxsw_reg_ptys_eth_pack(ptys_pl, mlxsw_sp_port->local_port,
eth_proto_new);
err = mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(ptys), ptys_pl);
if (err)
return err;
if (!netif_running(dev))
return 0;
mlxsw_sp_port->link.autoneg = autoneg;
mlxsw_sp_port_admin_status_set(mlxsw_sp_port, false);
mlxsw_sp_port_admin_status_set(mlxsw_sp_port, true);
return 0;
}
static int
mlxsw_sp_port_speed_by_width_set(struct mlxsw_sp_port *mlxsw_sp_port, u8 width)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
u32 upper_speed = MLXSW_SP_PORT_BASE_SPEED * width;
char ptys_pl[MLXSW_REG_PTYS_LEN];
u32 eth_proto_admin;
eth_proto_admin = mlxsw_sp_to_ptys_upper_speed(upper_speed);
mlxsw_reg_ptys_eth_pack(ptys_pl, mlxsw_sp_port->local_port,
eth_proto_admin);
return mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(ptys), ptys_pl);
}
int mlxsw_sp_port_ets_set(struct mlxsw_sp_port *mlxsw_sp_port,
enum mlxsw_reg_qeec_hr hr, u8 index, u8 next_index,
bool dwrr, u8 dwrr_weight)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
char qeec_pl[MLXSW_REG_QEEC_LEN];
mlxsw_reg_qeec_pack(qeec_pl, mlxsw_sp_port->local_port, hr, index,
next_index);
mlxsw_reg_qeec_de_set(qeec_pl, true);
mlxsw_reg_qeec_dwrr_set(qeec_pl, dwrr);
mlxsw_reg_qeec_dwrr_weight_set(qeec_pl, dwrr_weight);
return mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(qeec), qeec_pl);
}
int mlxsw_sp_port_ets_maxrate_set(struct mlxsw_sp_port *mlxsw_sp_port,
enum mlxsw_reg_qeec_hr hr, u8 index,
u8 next_index, u32 maxrate)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
char qeec_pl[MLXSW_REG_QEEC_LEN];
mlxsw_reg_qeec_pack(qeec_pl, mlxsw_sp_port->local_port, hr, index,
next_index);
mlxsw_reg_qeec_mase_set(qeec_pl, true);
mlxsw_reg_qeec_max_shaper_rate_set(qeec_pl, maxrate);
return mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(qeec), qeec_pl);
}
int mlxsw_sp_port_prio_tc_set(struct mlxsw_sp_port *mlxsw_sp_port,
u8 switch_prio, u8 tclass)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
char qtct_pl[MLXSW_REG_QTCT_LEN];
mlxsw_reg_qtct_pack(qtct_pl, mlxsw_sp_port->local_port, switch_prio,
tclass);
return mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(qtct), qtct_pl);
}
static int mlxsw_sp_port_ets_init(struct mlxsw_sp_port *mlxsw_sp_port)
{
int err, i;
err = mlxsw_sp_port_ets_set(mlxsw_sp_port,
MLXSW_REG_QEEC_HIERARCY_GROUP, 0, 0, false,
0);
if (err)
return err;
for (i = 0; i < IEEE_8021QAZ_MAX_TCS; i++) {
err = mlxsw_sp_port_ets_set(mlxsw_sp_port,
MLXSW_REG_QEEC_HIERARCY_SUBGROUP, i,
0, false, 0);
if (err)
return err;
}
for (i = 0; i < IEEE_8021QAZ_MAX_TCS; i++) {
err = mlxsw_sp_port_ets_set(mlxsw_sp_port,
MLXSW_REG_QEEC_HIERARCY_TC, i, i,
false, 0);
if (err)
return err;
}
err = mlxsw_sp_port_ets_maxrate_set(mlxsw_sp_port,
MLXSW_REG_QEEC_HIERARCY_PORT, 0, 0,
MLXSW_REG_QEEC_MAS_DIS);
if (err)
return err;
for (i = 0; i < IEEE_8021QAZ_MAX_TCS; i++) {
err = mlxsw_sp_port_ets_maxrate_set(mlxsw_sp_port,
MLXSW_REG_QEEC_HIERARCY_SUBGROUP,
i, 0,
MLXSW_REG_QEEC_MAS_DIS);
if (err)
return err;
}
for (i = 0; i < IEEE_8021QAZ_MAX_TCS; i++) {
err = mlxsw_sp_port_ets_maxrate_set(mlxsw_sp_port,
MLXSW_REG_QEEC_HIERARCY_TC,
i, i,
MLXSW_REG_QEEC_MAS_DIS);
if (err)
return err;
}
for (i = 0; i < IEEE_8021QAZ_MAX_TCS; i++) {
err = mlxsw_sp_port_prio_tc_set(mlxsw_sp_port, i, 0);
if (err)
return err;
}
return 0;
}
static int mlxsw_sp_port_pvid_vport_create(struct mlxsw_sp_port *mlxsw_sp_port)
{
mlxsw_sp_port->pvid = 1;
return mlxsw_sp_port_add_vid(mlxsw_sp_port->dev, 0, 1);
}
static int mlxsw_sp_port_pvid_vport_destroy(struct mlxsw_sp_port *mlxsw_sp_port)
{
return mlxsw_sp_port_kill_vid(mlxsw_sp_port->dev, 0, 1);
}
static int __mlxsw_sp_port_create(struct mlxsw_sp *mlxsw_sp, u8 local_port,
bool split, u8 module, u8 width, u8 lane)
{
struct mlxsw_sp_port *mlxsw_sp_port;
struct net_device *dev;
size_t bytes;
int err;
dev = alloc_etherdev(sizeof(struct mlxsw_sp_port));
if (!dev)
return -ENOMEM;
SET_NETDEV_DEV(dev, mlxsw_sp->bus_info->dev);
mlxsw_sp_port = netdev_priv(dev);
mlxsw_sp_port->dev = dev;
mlxsw_sp_port->mlxsw_sp = mlxsw_sp;
mlxsw_sp_port->local_port = local_port;
mlxsw_sp_port->split = split;
mlxsw_sp_port->mapping.module = module;
mlxsw_sp_port->mapping.width = width;
mlxsw_sp_port->mapping.lane = lane;
mlxsw_sp_port->link.autoneg = 1;
bytes = DIV_ROUND_UP(VLAN_N_VID, BITS_PER_BYTE);
mlxsw_sp_port->active_vlans = kzalloc(bytes, GFP_KERNEL);
if (!mlxsw_sp_port->active_vlans) {
err = -ENOMEM;
goto err_port_active_vlans_alloc;
}
mlxsw_sp_port->untagged_vlans = kzalloc(bytes, GFP_KERNEL);
if (!mlxsw_sp_port->untagged_vlans) {
err = -ENOMEM;
goto err_port_untagged_vlans_alloc;
}
INIT_LIST_HEAD(&mlxsw_sp_port->vports_list);
INIT_LIST_HEAD(&mlxsw_sp_port->mall_tc_list);
mlxsw_sp_port->pcpu_stats =
netdev_alloc_pcpu_stats(struct mlxsw_sp_port_pcpu_stats);
if (!mlxsw_sp_port->pcpu_stats) {
err = -ENOMEM;
goto err_alloc_stats;
}
mlxsw_sp_port->sample = kzalloc(sizeof(*mlxsw_sp_port->sample),
GFP_KERNEL);
if (!mlxsw_sp_port->sample) {
err = -ENOMEM;
goto err_alloc_sample;
}
mlxsw_sp_port->hw_stats.cache =
kzalloc(sizeof(*mlxsw_sp_port->hw_stats.cache), GFP_KERNEL);
if (!mlxsw_sp_port->hw_stats.cache) {
err = -ENOMEM;
goto err_alloc_hw_stats;
}
INIT_DELAYED_WORK(&mlxsw_sp_port->hw_stats.update_dw,
&update_stats_cache);
dev->netdev_ops = &mlxsw_sp_port_netdev_ops;
dev->ethtool_ops = &mlxsw_sp_port_ethtool_ops;
err = mlxsw_sp_port_swid_set(mlxsw_sp_port, 0);
if (err) {
dev_err(mlxsw_sp->bus_info->dev, "Port %d: Failed to set SWID\n",
mlxsw_sp_port->local_port);
goto err_port_swid_set;
}
err = mlxsw_sp_port_dev_addr_init(mlxsw_sp_port);
if (err) {
dev_err(mlxsw_sp->bus_info->dev, "Port %d: Unable to init port mac address\n",
mlxsw_sp_port->local_port);
goto err_dev_addr_init;
}
netif_carrier_off(dev);
dev->features |= NETIF_F_NETNS_LOCAL | NETIF_F_LLTX | NETIF_F_SG |
NETIF_F_HW_VLAN_CTAG_FILTER | NETIF_F_HW_TC;
dev->hw_features |= NETIF_F_HW_TC;
dev->min_mtu = 0;
dev->max_mtu = ETH_MAX_MTU;
dev->needed_headroom = MLXSW_TXHDR_LEN;
err = mlxsw_sp_port_system_port_mapping_set(mlxsw_sp_port);
if (err) {
dev_err(mlxsw_sp->bus_info->dev, "Port %d: Failed to set system port mapping\n",
mlxsw_sp_port->local_port);
goto err_port_system_port_mapping_set;
}
err = mlxsw_sp_port_speed_by_width_set(mlxsw_sp_port, width);
if (err) {
dev_err(mlxsw_sp->bus_info->dev, "Port %d: Failed to enable speeds\n",
mlxsw_sp_port->local_port);
goto err_port_speed_by_width_set;
}
err = mlxsw_sp_port_mtu_set(mlxsw_sp_port, ETH_DATA_LEN);
if (err) {
dev_err(mlxsw_sp->bus_info->dev, "Port %d: Failed to set MTU\n",
mlxsw_sp_port->local_port);
goto err_port_mtu_set;
}
err = mlxsw_sp_port_admin_status_set(mlxsw_sp_port, false);
if (err)
goto err_port_admin_status_set;
err = mlxsw_sp_port_buffers_init(mlxsw_sp_port);
if (err) {
dev_err(mlxsw_sp->bus_info->dev, "Port %d: Failed to initialize buffers\n",
mlxsw_sp_port->local_port);
goto err_port_buffers_init;
}
err = mlxsw_sp_port_ets_init(mlxsw_sp_port);
if (err) {
dev_err(mlxsw_sp->bus_info->dev, "Port %d: Failed to initialize ETS\n",
mlxsw_sp_port->local_port);
goto err_port_ets_init;
}
err = mlxsw_sp_port_dcb_init(mlxsw_sp_port);
if (err) {
dev_err(mlxsw_sp->bus_info->dev, "Port %d: Failed to initialize DCB\n",
mlxsw_sp_port->local_port);
goto err_port_dcb_init;
}
err = mlxsw_sp_port_pvid_vport_create(mlxsw_sp_port);
if (err) {
dev_err(mlxsw_sp->bus_info->dev, "Port %d: Failed to create PVID vPort\n",
mlxsw_sp_port->local_port);
goto err_port_pvid_vport_create;
}
mlxsw_sp_port_switchdev_init(mlxsw_sp_port);
mlxsw_sp->ports[local_port] = mlxsw_sp_port;
err = register_netdev(dev);
if (err) {
dev_err(mlxsw_sp->bus_info->dev, "Port %d: Failed to register netdev\n",
mlxsw_sp_port->local_port);
goto err_register_netdev;
}
mlxsw_core_port_eth_set(mlxsw_sp->core, mlxsw_sp_port->local_port,
mlxsw_sp_port, dev, mlxsw_sp_port->split,
module);
mlxsw_core_schedule_dw(&mlxsw_sp_port->hw_stats.update_dw, 0);
return 0;
err_register_netdev:
mlxsw_sp->ports[local_port] = NULL;
mlxsw_sp_port_switchdev_fini(mlxsw_sp_port);
mlxsw_sp_port_pvid_vport_destroy(mlxsw_sp_port);
err_port_pvid_vport_create:
mlxsw_sp_port_dcb_fini(mlxsw_sp_port);
err_port_dcb_init:
err_port_ets_init:
err_port_buffers_init:
err_port_admin_status_set:
err_port_mtu_set:
err_port_speed_by_width_set:
err_port_system_port_mapping_set:
err_dev_addr_init:
mlxsw_sp_port_swid_set(mlxsw_sp_port, MLXSW_PORT_SWID_DISABLED_PORT);
err_port_swid_set:
kfree(mlxsw_sp_port->hw_stats.cache);
err_alloc_hw_stats:
kfree(mlxsw_sp_port->sample);
err_alloc_sample:
free_percpu(mlxsw_sp_port->pcpu_stats);
err_alloc_stats:
kfree(mlxsw_sp_port->untagged_vlans);
err_port_untagged_vlans_alloc:
kfree(mlxsw_sp_port->active_vlans);
err_port_active_vlans_alloc:
free_netdev(dev);
return err;
}
static int mlxsw_sp_port_create(struct mlxsw_sp *mlxsw_sp, u8 local_port,
bool split, u8 module, u8 width, u8 lane)
{
int err;
err = mlxsw_core_port_init(mlxsw_sp->core, local_port);
if (err) {
dev_err(mlxsw_sp->bus_info->dev, "Port %d: Failed to init core port\n",
local_port);
return err;
}
err = __mlxsw_sp_port_create(mlxsw_sp, local_port, split,
module, width, lane);
if (err)
goto err_port_create;
return 0;
err_port_create:
mlxsw_core_port_fini(mlxsw_sp->core, local_port);
return err;
}
static void __mlxsw_sp_port_remove(struct mlxsw_sp *mlxsw_sp, u8 local_port)
{
struct mlxsw_sp_port *mlxsw_sp_port = mlxsw_sp->ports[local_port];
cancel_delayed_work_sync(&mlxsw_sp_port->hw_stats.update_dw);
mlxsw_core_port_clear(mlxsw_sp->core, local_port, mlxsw_sp);
unregister_netdev(mlxsw_sp_port->dev);
mlxsw_sp->ports[local_port] = NULL;
mlxsw_sp_port_switchdev_fini(mlxsw_sp_port);
mlxsw_sp_port_pvid_vport_destroy(mlxsw_sp_port);
mlxsw_sp_port_dcb_fini(mlxsw_sp_port);
mlxsw_sp_port_swid_set(mlxsw_sp_port, MLXSW_PORT_SWID_DISABLED_PORT);
mlxsw_sp_port_module_unmap(mlxsw_sp, mlxsw_sp_port->local_port);
kfree(mlxsw_sp_port->hw_stats.cache);
kfree(mlxsw_sp_port->sample);
free_percpu(mlxsw_sp_port->pcpu_stats);
kfree(mlxsw_sp_port->untagged_vlans);
kfree(mlxsw_sp_port->active_vlans);
WARN_ON_ONCE(!list_empty(&mlxsw_sp_port->vports_list));
free_netdev(mlxsw_sp_port->dev);
}
static void mlxsw_sp_port_remove(struct mlxsw_sp *mlxsw_sp, u8 local_port)
{
__mlxsw_sp_port_remove(mlxsw_sp, local_port);
mlxsw_core_port_fini(mlxsw_sp->core, local_port);
}
static bool mlxsw_sp_port_created(struct mlxsw_sp *mlxsw_sp, u8 local_port)
{
return mlxsw_sp->ports[local_port] != NULL;
}
static void mlxsw_sp_ports_remove(struct mlxsw_sp *mlxsw_sp)
{
int i;
for (i = 1; i < mlxsw_core_max_ports(mlxsw_sp->core); i++)
if (mlxsw_sp_port_created(mlxsw_sp, i))
mlxsw_sp_port_remove(mlxsw_sp, i);
kfree(mlxsw_sp->port_to_module);
kfree(mlxsw_sp->ports);
}
static int mlxsw_sp_ports_create(struct mlxsw_sp *mlxsw_sp)
{
unsigned int max_ports = mlxsw_core_max_ports(mlxsw_sp->core);
u8 module, width, lane;
size_t alloc_size;
int i;
int err;
alloc_size = sizeof(struct mlxsw_sp_port *) * max_ports;
mlxsw_sp->ports = kzalloc(alloc_size, GFP_KERNEL);
if (!mlxsw_sp->ports)
return -ENOMEM;
mlxsw_sp->port_to_module = kcalloc(max_ports, sizeof(u8), GFP_KERNEL);
if (!mlxsw_sp->port_to_module) {
err = -ENOMEM;
goto err_port_to_module_alloc;
}
for (i = 1; i < max_ports; i++) {
err = mlxsw_sp_port_module_info_get(mlxsw_sp, i, &module,
&width, &lane);
if (err)
goto err_port_module_info_get;
if (!width)
continue;
mlxsw_sp->port_to_module[i] = module;
err = mlxsw_sp_port_create(mlxsw_sp, i, false,
module, width, lane);
if (err)
goto err_port_create;
}
return 0;
err_port_create:
err_port_module_info_get:
for (i--; i >= 1; i--)
if (mlxsw_sp_port_created(mlxsw_sp, i))
mlxsw_sp_port_remove(mlxsw_sp, i);
kfree(mlxsw_sp->port_to_module);
err_port_to_module_alloc:
kfree(mlxsw_sp->ports);
return err;
}
static u8 mlxsw_sp_cluster_base_port_get(u8 local_port)
{
u8 offset = (local_port - 1) % MLXSW_SP_PORTS_PER_CLUSTER_MAX;
return local_port - offset;
}
static int mlxsw_sp_port_split_create(struct mlxsw_sp *mlxsw_sp, u8 base_port,
u8 module, unsigned int count)
{
u8 width = MLXSW_PORT_MODULE_MAX_WIDTH / count;
int err, i;
for (i = 0; i < count; i++) {
err = mlxsw_sp_port_module_map(mlxsw_sp, base_port + i, module,
width, i * width);
if (err)
goto err_port_module_map;
}
for (i = 0; i < count; i++) {
err = __mlxsw_sp_port_swid_set(mlxsw_sp, base_port + i, 0);
if (err)
goto err_port_swid_set;
}
for (i = 0; i < count; i++) {
err = mlxsw_sp_port_create(mlxsw_sp, base_port + i, true,
module, width, i * width);
if (err)
goto err_port_create;
}
return 0;
err_port_create:
for (i--; i >= 0; i--)
if (mlxsw_sp_port_created(mlxsw_sp, base_port + i))
mlxsw_sp_port_remove(mlxsw_sp, base_port + i);
i = count;
err_port_swid_set:
for (i--; i >= 0; i--)
__mlxsw_sp_port_swid_set(mlxsw_sp, base_port + i,
MLXSW_PORT_SWID_DISABLED_PORT);
i = count;
err_port_module_map:
for (i--; i >= 0; i--)
mlxsw_sp_port_module_unmap(mlxsw_sp, base_port + i);
return err;
}
static void mlxsw_sp_port_unsplit_create(struct mlxsw_sp *mlxsw_sp,
u8 base_port, unsigned int count)
{
u8 local_port, module, width = MLXSW_PORT_MODULE_MAX_WIDTH;
int i;
count = count / 2;
for (i = 0; i < count; i++) {
local_port = base_port + i * 2;
module = mlxsw_sp->port_to_module[local_port];
mlxsw_sp_port_module_map(mlxsw_sp, local_port, module, width,
0);
}
for (i = 0; i < count; i++)
__mlxsw_sp_port_swid_set(mlxsw_sp, base_port + i * 2, 0);
for (i = 0; i < count; i++) {
local_port = base_port + i * 2;
module = mlxsw_sp->port_to_module[local_port];
mlxsw_sp_port_create(mlxsw_sp, local_port, false, module,
width, 0);
}
}
static int mlxsw_sp_port_split(struct mlxsw_core *mlxsw_core, u8 local_port,
unsigned int count)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_core_driver_priv(mlxsw_core);
struct mlxsw_sp_port *mlxsw_sp_port;
u8 module, cur_width, base_port;
int i;
int err;
mlxsw_sp_port = mlxsw_sp->ports[local_port];
if (!mlxsw_sp_port) {
dev_err(mlxsw_sp->bus_info->dev, "Port number \"%d\" does not exist\n",
local_port);
return -EINVAL;
}
module = mlxsw_sp_port->mapping.module;
cur_width = mlxsw_sp_port->mapping.width;
if (count != 2 && count != 4) {
netdev_err(mlxsw_sp_port->dev, "Port can only be split into 2 or 4 ports\n");
return -EINVAL;
}
if (cur_width != MLXSW_PORT_MODULE_MAX_WIDTH) {
netdev_err(mlxsw_sp_port->dev, "Port cannot be split further\n");
return -EINVAL;
}
if (count == 2) {
base_port = local_port;
if (mlxsw_sp->ports[base_port + 1]) {
netdev_err(mlxsw_sp_port->dev, "Invalid split configuration\n");
return -EINVAL;
}
} else {
base_port = mlxsw_sp_cluster_base_port_get(local_port);
if (mlxsw_sp->ports[base_port + 1] ||
mlxsw_sp->ports[base_port + 3]) {
netdev_err(mlxsw_sp_port->dev, "Invalid split configuration\n");
return -EINVAL;
}
}
for (i = 0; i < count; i++)
if (mlxsw_sp_port_created(mlxsw_sp, base_port + i))
mlxsw_sp_port_remove(mlxsw_sp, base_port + i);
err = mlxsw_sp_port_split_create(mlxsw_sp, base_port, module, count);
if (err) {
dev_err(mlxsw_sp->bus_info->dev, "Failed to create split ports\n");
goto err_port_split_create;
}
return 0;
err_port_split_create:
mlxsw_sp_port_unsplit_create(mlxsw_sp, base_port, count);
return err;
}
static int mlxsw_sp_port_unsplit(struct mlxsw_core *mlxsw_core, u8 local_port)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_core_driver_priv(mlxsw_core);
struct mlxsw_sp_port *mlxsw_sp_port;
u8 cur_width, base_port;
unsigned int count;
int i;
mlxsw_sp_port = mlxsw_sp->ports[local_port];
if (!mlxsw_sp_port) {
dev_err(mlxsw_sp->bus_info->dev, "Port number \"%d\" does not exist\n",
local_port);
return -EINVAL;
}
if (!mlxsw_sp_port->split) {
netdev_err(mlxsw_sp_port->dev, "Port wasn't split\n");
return -EINVAL;
}
cur_width = mlxsw_sp_port->mapping.width;
count = cur_width == 1 ? 4 : 2;
base_port = mlxsw_sp_cluster_base_port_get(local_port);
if (count == 2 && local_port >= base_port + 2)
base_port = base_port + 2;
for (i = 0; i < count; i++)
if (mlxsw_sp_port_created(mlxsw_sp, base_port + i))
mlxsw_sp_port_remove(mlxsw_sp, base_port + i);
mlxsw_sp_port_unsplit_create(mlxsw_sp, base_port, count);
return 0;
}
static void mlxsw_sp_pude_event_func(const struct mlxsw_reg_info *reg,
char *pude_pl, void *priv)
{
struct mlxsw_sp *mlxsw_sp = priv;
struct mlxsw_sp_port *mlxsw_sp_port;
enum mlxsw_reg_pude_oper_status status;
u8 local_port;
local_port = mlxsw_reg_pude_local_port_get(pude_pl);
mlxsw_sp_port = mlxsw_sp->ports[local_port];
if (!mlxsw_sp_port)
return;
status = mlxsw_reg_pude_oper_status_get(pude_pl);
if (status == MLXSW_PORT_OPER_STATUS_UP) {
netdev_info(mlxsw_sp_port->dev, "link up\n");
netif_carrier_on(mlxsw_sp_port->dev);
} else {
netdev_info(mlxsw_sp_port->dev, "link down\n");
netif_carrier_off(mlxsw_sp_port->dev);
}
}
static void mlxsw_sp_rx_listener_no_mark_func(struct sk_buff *skb,
u8 local_port, void *priv)
{
struct mlxsw_sp *mlxsw_sp = priv;
struct mlxsw_sp_port *mlxsw_sp_port = mlxsw_sp->ports[local_port];
struct mlxsw_sp_port_pcpu_stats *pcpu_stats;
if (unlikely(!mlxsw_sp_port)) {
dev_warn_ratelimited(mlxsw_sp->bus_info->dev, "Port %d: skb received for non-existent port\n",
local_port);
return;
}
skb->dev = mlxsw_sp_port->dev;
pcpu_stats = this_cpu_ptr(mlxsw_sp_port->pcpu_stats);
u64_stats_update_begin(&pcpu_stats->syncp);
pcpu_stats->rx_packets++;
pcpu_stats->rx_bytes += skb->len;
u64_stats_update_end(&pcpu_stats->syncp);
skb->protocol = eth_type_trans(skb, skb->dev);
netif_receive_skb(skb);
}
static void mlxsw_sp_rx_listener_mark_func(struct sk_buff *skb, u8 local_port,
void *priv)
{
skb->offload_fwd_mark = 1;
return mlxsw_sp_rx_listener_no_mark_func(skb, local_port, priv);
}
static void mlxsw_sp_rx_listener_sample_func(struct sk_buff *skb, u8 local_port,
void *priv)
{
struct mlxsw_sp *mlxsw_sp = priv;
struct mlxsw_sp_port *mlxsw_sp_port = mlxsw_sp->ports[local_port];
struct psample_group *psample_group;
u32 size;
if (unlikely(!mlxsw_sp_port)) {
dev_warn_ratelimited(mlxsw_sp->bus_info->dev, "Port %d: sample skb received for non-existent port\n",
local_port);
goto out;
}
if (unlikely(!mlxsw_sp_port->sample)) {
dev_warn_ratelimited(mlxsw_sp->bus_info->dev, "Port %d: sample skb received on unsupported port\n",
local_port);
goto out;
}
size = mlxsw_sp_port->sample->truncate ?
mlxsw_sp_port->sample->trunc_size : skb->len;
rcu_read_lock();
psample_group = rcu_dereference(mlxsw_sp_port->sample->psample_group);
if (!psample_group)
goto out_unlock;
psample_sample_packet(psample_group, skb, size,
mlxsw_sp_port->dev->ifindex, 0,
mlxsw_sp_port->sample->rate);
out_unlock:
rcu_read_unlock();
out:
consume_skb(skb);
}
static int mlxsw_sp_cpu_policers_set(struct mlxsw_core *mlxsw_core)
{
char qpcr_pl[MLXSW_REG_QPCR_LEN];
enum mlxsw_reg_qpcr_ir_units ir_units;
int max_cpu_policers;
bool is_bytes;
u8 burst_size;
u32 rate;
int i, err;
if (!MLXSW_CORE_RES_VALID(mlxsw_core, MAX_CPU_POLICERS))
return -EIO;
max_cpu_policers = MLXSW_CORE_RES_GET(mlxsw_core, MAX_CPU_POLICERS);
ir_units = MLXSW_REG_QPCR_IR_UNITS_M;
for (i = 0; i < max_cpu_policers; i++) {
is_bytes = false;
switch (i) {
case MLXSW_REG_HTGT_TRAP_GROUP_SP_STP:
case MLXSW_REG_HTGT_TRAP_GROUP_SP_LACP:
case MLXSW_REG_HTGT_TRAP_GROUP_SP_LLDP:
case MLXSW_REG_HTGT_TRAP_GROUP_SP_OSPF:
rate = 128;
burst_size = 7;
break;
case MLXSW_REG_HTGT_TRAP_GROUP_SP_IGMP:
rate = 16 * 1024;
burst_size = 10;
break;
case MLXSW_REG_HTGT_TRAP_GROUP_SP_BGP_IPV4:
case MLXSW_REG_HTGT_TRAP_GROUP_SP_ARP:
case MLXSW_REG_HTGT_TRAP_GROUP_SP_DHCP:
case MLXSW_REG_HTGT_TRAP_GROUP_SP_ARP_MISS:
case MLXSW_REG_HTGT_TRAP_GROUP_SP_ROUTER_EXP:
case MLXSW_REG_HTGT_TRAP_GROUP_SP_REMOTE_ROUTE:
rate = 1024;
burst_size = 7;
break;
case MLXSW_REG_HTGT_TRAP_GROUP_SP_IP2ME:
is_bytes = true;
rate = 4 * 1024;
burst_size = 4;
break;
default:
continue;
}
mlxsw_reg_qpcr_pack(qpcr_pl, i, ir_units, is_bytes, rate,
burst_size);
err = mlxsw_reg_write(mlxsw_core, MLXSW_REG(qpcr), qpcr_pl);
if (err)
return err;
}
return 0;
}
static int mlxsw_sp_trap_groups_set(struct mlxsw_core *mlxsw_core)
{
char htgt_pl[MLXSW_REG_HTGT_LEN];
enum mlxsw_reg_htgt_trap_group i;
int max_cpu_policers;
int max_trap_groups;
u8 priority, tc;
u16 policer_id;
int err;
if (!MLXSW_CORE_RES_VALID(mlxsw_core, MAX_TRAP_GROUPS))
return -EIO;
max_trap_groups = MLXSW_CORE_RES_GET(mlxsw_core, MAX_TRAP_GROUPS);
max_cpu_policers = MLXSW_CORE_RES_GET(mlxsw_core, MAX_CPU_POLICERS);
for (i = 0; i < max_trap_groups; i++) {
policer_id = i;
switch (i) {
case MLXSW_REG_HTGT_TRAP_GROUP_SP_STP:
case MLXSW_REG_HTGT_TRAP_GROUP_SP_LACP:
case MLXSW_REG_HTGT_TRAP_GROUP_SP_LLDP:
case MLXSW_REG_HTGT_TRAP_GROUP_SP_OSPF:
priority = 5;
tc = 5;
break;
case MLXSW_REG_HTGT_TRAP_GROUP_SP_BGP_IPV4:
case MLXSW_REG_HTGT_TRAP_GROUP_SP_DHCP:
priority = 4;
tc = 4;
break;
case MLXSW_REG_HTGT_TRAP_GROUP_SP_IGMP:
case MLXSW_REG_HTGT_TRAP_GROUP_SP_IP2ME:
priority = 3;
tc = 3;
break;
case MLXSW_REG_HTGT_TRAP_GROUP_SP_ARP:
priority = 2;
tc = 2;
break;
case MLXSW_REG_HTGT_TRAP_GROUP_SP_ARP_MISS:
case MLXSW_REG_HTGT_TRAP_GROUP_SP_ROUTER_EXP:
case MLXSW_REG_HTGT_TRAP_GROUP_SP_REMOTE_ROUTE:
priority = 1;
tc = 1;
break;
case MLXSW_REG_HTGT_TRAP_GROUP_SP_EVENT:
priority = MLXSW_REG_HTGT_DEFAULT_PRIORITY;
tc = MLXSW_REG_HTGT_DEFAULT_TC;
policer_id = MLXSW_REG_HTGT_INVALID_POLICER;
break;
default:
continue;
}
if (max_cpu_policers <= policer_id &&
policer_id != MLXSW_REG_HTGT_INVALID_POLICER)
return -EIO;
mlxsw_reg_htgt_pack(htgt_pl, i, policer_id, priority, tc);
err = mlxsw_reg_write(mlxsw_core, MLXSW_REG(htgt), htgt_pl);
if (err)
return err;
}
return 0;
}
static int mlxsw_sp_traps_init(struct mlxsw_sp *mlxsw_sp)
{
int i;
int err;
err = mlxsw_sp_cpu_policers_set(mlxsw_sp->core);
if (err)
return err;
err = mlxsw_sp_trap_groups_set(mlxsw_sp->core);
if (err)
return err;
for (i = 0; i < ARRAY_SIZE(mlxsw_sp_listener); i++) {
err = mlxsw_core_trap_register(mlxsw_sp->core,
&mlxsw_sp_listener[i],
mlxsw_sp);
if (err)
goto err_listener_register;
}
return 0;
err_listener_register:
for (i--; i >= 0; i--) {
mlxsw_core_trap_unregister(mlxsw_sp->core,
&mlxsw_sp_listener[i],
mlxsw_sp);
}
return err;
}
static void mlxsw_sp_traps_fini(struct mlxsw_sp *mlxsw_sp)
{
int i;
for (i = 0; i < ARRAY_SIZE(mlxsw_sp_listener); i++) {
mlxsw_core_trap_unregister(mlxsw_sp->core,
&mlxsw_sp_listener[i],
mlxsw_sp);
}
}
static int __mlxsw_sp_flood_init(struct mlxsw_core *mlxsw_core,
enum mlxsw_reg_sfgc_type type,
enum mlxsw_reg_sfgc_bridge_type bridge_type)
{
enum mlxsw_flood_table_type table_type;
enum mlxsw_sp_flood_table flood_table;
char sfgc_pl[MLXSW_REG_SFGC_LEN];
if (bridge_type == MLXSW_REG_SFGC_BRIDGE_TYPE_VFID)
table_type = MLXSW_REG_SFGC_TABLE_TYPE_FID;
else
table_type = MLXSW_REG_SFGC_TABLE_TYPE_FID_OFFEST;
switch (type) {
case MLXSW_REG_SFGC_TYPE_UNKNOWN_UNICAST:
flood_table = MLXSW_SP_FLOOD_TABLE_UC;
break;
case MLXSW_REG_SFGC_TYPE_UNREGISTERED_MULTICAST_IPV4:
flood_table = MLXSW_SP_FLOOD_TABLE_MC;
break;
default:
flood_table = MLXSW_SP_FLOOD_TABLE_BC;
}
mlxsw_reg_sfgc_pack(sfgc_pl, type, bridge_type, table_type,
flood_table);
return mlxsw_reg_write(mlxsw_core, MLXSW_REG(sfgc), sfgc_pl);
}
static int mlxsw_sp_flood_init(struct mlxsw_sp *mlxsw_sp)
{
int type, err;
for (type = 0; type < MLXSW_REG_SFGC_TYPE_MAX; type++) {
if (type == MLXSW_REG_SFGC_TYPE_RESERVED)
continue;
err = __mlxsw_sp_flood_init(mlxsw_sp->core, type,
MLXSW_REG_SFGC_BRIDGE_TYPE_VFID);
if (err)
return err;
err = __mlxsw_sp_flood_init(mlxsw_sp->core, type,
MLXSW_REG_SFGC_BRIDGE_TYPE_1Q_FID);
if (err)
return err;
}
return 0;
}
static int mlxsw_sp_lag_init(struct mlxsw_sp *mlxsw_sp)
{
char slcr_pl[MLXSW_REG_SLCR_LEN];
int err;
mlxsw_reg_slcr_pack(slcr_pl, MLXSW_REG_SLCR_LAG_HASH_SMAC |
MLXSW_REG_SLCR_LAG_HASH_DMAC |
MLXSW_REG_SLCR_LAG_HASH_ETHERTYPE |
MLXSW_REG_SLCR_LAG_HASH_VLANID |
MLXSW_REG_SLCR_LAG_HASH_SIP |
MLXSW_REG_SLCR_LAG_HASH_DIP |
MLXSW_REG_SLCR_LAG_HASH_SPORT |
MLXSW_REG_SLCR_LAG_HASH_DPORT |
MLXSW_REG_SLCR_LAG_HASH_IPPROTO);
err = mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(slcr), slcr_pl);
if (err)
return err;
if (!MLXSW_CORE_RES_VALID(mlxsw_sp->core, MAX_LAG) ||
!MLXSW_CORE_RES_VALID(mlxsw_sp->core, MAX_LAG_MEMBERS))
return -EIO;
mlxsw_sp->lags = kcalloc(MLXSW_CORE_RES_GET(mlxsw_sp->core, MAX_LAG),
sizeof(struct mlxsw_sp_upper),
GFP_KERNEL);
if (!mlxsw_sp->lags)
return -ENOMEM;
return 0;
}
static void mlxsw_sp_lag_fini(struct mlxsw_sp *mlxsw_sp)
{
kfree(mlxsw_sp->lags);
}
static int mlxsw_sp_basic_trap_groups_set(struct mlxsw_core *mlxsw_core)
{
char htgt_pl[MLXSW_REG_HTGT_LEN];
mlxsw_reg_htgt_pack(htgt_pl, MLXSW_REG_HTGT_TRAP_GROUP_EMAD,
MLXSW_REG_HTGT_INVALID_POLICER,
MLXSW_REG_HTGT_DEFAULT_PRIORITY,
MLXSW_REG_HTGT_DEFAULT_TC);
return mlxsw_reg_write(mlxsw_core, MLXSW_REG(htgt), htgt_pl);
}
static int mlxsw_sp_dummy_fid_init(struct mlxsw_sp *mlxsw_sp)
{
return mlxsw_sp_vfid_op(mlxsw_sp, MLXSW_SP_DUMMY_FID, true);
}
static void mlxsw_sp_dummy_fid_fini(struct mlxsw_sp *mlxsw_sp)
{
mlxsw_sp_vfid_op(mlxsw_sp, MLXSW_SP_DUMMY_FID, false);
}
static int mlxsw_sp_init(struct mlxsw_core *mlxsw_core,
const struct mlxsw_bus_info *mlxsw_bus_info)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_core_driver_priv(mlxsw_core);
int err;
mlxsw_sp->core = mlxsw_core;
mlxsw_sp->bus_info = mlxsw_bus_info;
INIT_LIST_HEAD(&mlxsw_sp->fids);
INIT_LIST_HEAD(&mlxsw_sp->vfids.list);
INIT_LIST_HEAD(&mlxsw_sp->br_mids.list);
err = mlxsw_sp_base_mac_get(mlxsw_sp);
if (err) {
dev_err(mlxsw_sp->bus_info->dev, "Failed to get base mac\n");
return err;
}
err = mlxsw_sp_traps_init(mlxsw_sp);
if (err) {
dev_err(mlxsw_sp->bus_info->dev, "Failed to set traps\n");
return err;
}
err = mlxsw_sp_flood_init(mlxsw_sp);
if (err) {
dev_err(mlxsw_sp->bus_info->dev, "Failed to initialize flood tables\n");
goto err_flood_init;
}
err = mlxsw_sp_buffers_init(mlxsw_sp);
if (err) {
dev_err(mlxsw_sp->bus_info->dev, "Failed to initialize buffers\n");
goto err_buffers_init;
}
err = mlxsw_sp_lag_init(mlxsw_sp);
if (err) {
dev_err(mlxsw_sp->bus_info->dev, "Failed to initialize LAG\n");
goto err_lag_init;
}
err = mlxsw_sp_switchdev_init(mlxsw_sp);
if (err) {
dev_err(mlxsw_sp->bus_info->dev, "Failed to initialize switchdev\n");
goto err_switchdev_init;
}
err = mlxsw_sp_router_init(mlxsw_sp);
if (err) {
dev_err(mlxsw_sp->bus_info->dev, "Failed to initialize router\n");
goto err_router_init;
}
err = mlxsw_sp_span_init(mlxsw_sp);
if (err) {
dev_err(mlxsw_sp->bus_info->dev, "Failed to init span system\n");
goto err_span_init;
}
err = mlxsw_sp_acl_init(mlxsw_sp);
if (err) {
dev_err(mlxsw_sp->bus_info->dev, "Failed to initialize ACL\n");
goto err_acl_init;
}
err = mlxsw_sp_counter_pool_init(mlxsw_sp);
if (err) {
dev_err(mlxsw_sp->bus_info->dev, "Failed to init counter pool\n");
goto err_counter_pool_init;
}
err = mlxsw_sp_dpipe_init(mlxsw_sp);
if (err) {
dev_err(mlxsw_sp->bus_info->dev, "Failed to init pipeline debug\n");
goto err_dpipe_init;
}
err = mlxsw_sp_dummy_fid_init(mlxsw_sp);
if (err) {
dev_err(mlxsw_sp->bus_info->dev, "Failed to init dummy FID\n");
goto err_dummy_fid_init;
}
err = mlxsw_sp_ports_create(mlxsw_sp);
if (err) {
dev_err(mlxsw_sp->bus_info->dev, "Failed to create ports\n");
goto err_ports_create;
}
return 0;
err_ports_create:
mlxsw_sp_dummy_fid_fini(mlxsw_sp);
err_dummy_fid_init:
mlxsw_sp_dpipe_fini(mlxsw_sp);
err_dpipe_init:
mlxsw_sp_counter_pool_fini(mlxsw_sp);
err_counter_pool_init:
mlxsw_sp_acl_fini(mlxsw_sp);
err_acl_init:
mlxsw_sp_span_fini(mlxsw_sp);
err_span_init:
mlxsw_sp_router_fini(mlxsw_sp);
err_router_init:
mlxsw_sp_switchdev_fini(mlxsw_sp);
err_switchdev_init:
mlxsw_sp_lag_fini(mlxsw_sp);
err_lag_init:
mlxsw_sp_buffers_fini(mlxsw_sp);
err_buffers_init:
err_flood_init:
mlxsw_sp_traps_fini(mlxsw_sp);
return err;
}
static void mlxsw_sp_fini(struct mlxsw_core *mlxsw_core)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_core_driver_priv(mlxsw_core);
mlxsw_sp_ports_remove(mlxsw_sp);
mlxsw_sp_dummy_fid_fini(mlxsw_sp);
mlxsw_sp_dpipe_fini(mlxsw_sp);
mlxsw_sp_counter_pool_fini(mlxsw_sp);
mlxsw_sp_acl_fini(mlxsw_sp);
mlxsw_sp_span_fini(mlxsw_sp);
mlxsw_sp_router_fini(mlxsw_sp);
mlxsw_sp_switchdev_fini(mlxsw_sp);
mlxsw_sp_lag_fini(mlxsw_sp);
mlxsw_sp_buffers_fini(mlxsw_sp);
mlxsw_sp_traps_fini(mlxsw_sp);
WARN_ON(!list_empty(&mlxsw_sp->vfids.list));
WARN_ON(!list_empty(&mlxsw_sp->fids));
}
bool mlxsw_sp_port_dev_check(const struct net_device *dev)
{
return dev->netdev_ops == &mlxsw_sp_port_netdev_ops;
}
static int mlxsw_sp_lower_dev_walk(struct net_device *lower_dev, void *data)
{
struct mlxsw_sp_port **p_mlxsw_sp_port = data;
int ret = 0;
if (mlxsw_sp_port_dev_check(lower_dev)) {
*p_mlxsw_sp_port = netdev_priv(lower_dev);
ret = 1;
}
return ret;
}
static struct mlxsw_sp_port *mlxsw_sp_port_dev_lower_find(struct net_device *dev)
{
struct mlxsw_sp_port *mlxsw_sp_port;
if (mlxsw_sp_port_dev_check(dev))
return netdev_priv(dev);
mlxsw_sp_port = NULL;
netdev_walk_all_lower_dev(dev, mlxsw_sp_lower_dev_walk, &mlxsw_sp_port);
return mlxsw_sp_port;
}
struct mlxsw_sp *mlxsw_sp_lower_get(struct net_device *dev)
{
struct mlxsw_sp_port *mlxsw_sp_port;
mlxsw_sp_port = mlxsw_sp_port_dev_lower_find(dev);
return mlxsw_sp_port ? mlxsw_sp_port->mlxsw_sp : NULL;
}
static struct mlxsw_sp_port *mlxsw_sp_port_dev_lower_find_rcu(struct net_device *dev)
{
struct mlxsw_sp_port *mlxsw_sp_port;
if (mlxsw_sp_port_dev_check(dev))
return netdev_priv(dev);
mlxsw_sp_port = NULL;
netdev_walk_all_lower_dev_rcu(dev, mlxsw_sp_lower_dev_walk,
&mlxsw_sp_port);
return mlxsw_sp_port;
}
struct mlxsw_sp_port *mlxsw_sp_port_lower_dev_hold(struct net_device *dev)
{
struct mlxsw_sp_port *mlxsw_sp_port;
rcu_read_lock();
mlxsw_sp_port = mlxsw_sp_port_dev_lower_find_rcu(dev);
if (mlxsw_sp_port)
dev_hold(mlxsw_sp_port->dev);
rcu_read_unlock();
return mlxsw_sp_port;
}
void mlxsw_sp_port_dev_put(struct mlxsw_sp_port *mlxsw_sp_port)
{
dev_put(mlxsw_sp_port->dev);
}
static bool mlxsw_sp_lag_port_fid_member(struct mlxsw_sp_port *lag_port,
u16 fid)
{
if (mlxsw_sp_fid_is_vfid(fid))
return mlxsw_sp_port_vport_find_by_fid(lag_port, fid);
else
return test_bit(fid, lag_port->active_vlans);
}
static bool mlxsw_sp_port_fdb_should_flush(struct mlxsw_sp_port *mlxsw_sp_port,
u16 fid)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
u8 local_port = mlxsw_sp_port->local_port;
u16 lag_id = mlxsw_sp_port->lag_id;
u64 max_lag_members;
int i, count = 0;
if (!mlxsw_sp_port->lagged)
return true;
max_lag_members = MLXSW_CORE_RES_GET(mlxsw_sp->core,
MAX_LAG_MEMBERS);
for (i = 0; i < max_lag_members; i++) {
struct mlxsw_sp_port *lag_port;
lag_port = mlxsw_sp_port_lagged_get(mlxsw_sp, lag_id, i);
if (!lag_port || lag_port->local_port == local_port)
continue;
if (mlxsw_sp_lag_port_fid_member(lag_port, fid))
count++;
}
return !count;
}
static int
mlxsw_sp_port_fdb_flush_by_port_fid(const struct mlxsw_sp_port *mlxsw_sp_port,
u16 fid)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
char sfdf_pl[MLXSW_REG_SFDF_LEN];
mlxsw_reg_sfdf_pack(sfdf_pl, MLXSW_REG_SFDF_FLUSH_PER_PORT_AND_FID);
mlxsw_reg_sfdf_fid_set(sfdf_pl, fid);
mlxsw_reg_sfdf_port_fid_system_port_set(sfdf_pl,
mlxsw_sp_port->local_port);
netdev_dbg(mlxsw_sp_port->dev, "FDB flushed using Port=%d, FID=%d\n",
mlxsw_sp_port->local_port, fid);
return mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(sfdf), sfdf_pl);
}
static int
mlxsw_sp_port_fdb_flush_by_lag_id_fid(const struct mlxsw_sp_port *mlxsw_sp_port,
u16 fid)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
char sfdf_pl[MLXSW_REG_SFDF_LEN];
mlxsw_reg_sfdf_pack(sfdf_pl, MLXSW_REG_SFDF_FLUSH_PER_LAG_AND_FID);
mlxsw_reg_sfdf_fid_set(sfdf_pl, fid);
mlxsw_reg_sfdf_lag_fid_lag_id_set(sfdf_pl, mlxsw_sp_port->lag_id);
netdev_dbg(mlxsw_sp_port->dev, "FDB flushed using LAG ID=%d, FID=%d\n",
mlxsw_sp_port->lag_id, fid);
return mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(sfdf), sfdf_pl);
}
int mlxsw_sp_port_fdb_flush(struct mlxsw_sp_port *mlxsw_sp_port, u16 fid)
{
if (!mlxsw_sp_port_fdb_should_flush(mlxsw_sp_port, fid))
return 0;
if (mlxsw_sp_port->lagged)
return mlxsw_sp_port_fdb_flush_by_lag_id_fid(mlxsw_sp_port,
fid);
else
return mlxsw_sp_port_fdb_flush_by_port_fid(mlxsw_sp_port, fid);
}
static void mlxsw_sp_master_bridge_gone_sync(struct mlxsw_sp *mlxsw_sp)
{
struct mlxsw_sp_fid *f, *tmp;
list_for_each_entry_safe(f, tmp, &mlxsw_sp->fids, list)
if (--f->ref_count == 0)
mlxsw_sp_fid_destroy(mlxsw_sp, f);
else
WARN_ON_ONCE(1);
}
static bool mlxsw_sp_master_bridge_check(struct mlxsw_sp *mlxsw_sp,
struct net_device *br_dev)
{
return !mlxsw_sp->master_bridge.dev ||
mlxsw_sp->master_bridge.dev == br_dev;
}
static void mlxsw_sp_master_bridge_inc(struct mlxsw_sp *mlxsw_sp,
struct net_device *br_dev)
{
mlxsw_sp->master_bridge.dev = br_dev;
mlxsw_sp->master_bridge.ref_count++;
}
static void mlxsw_sp_master_bridge_dec(struct mlxsw_sp *mlxsw_sp)
{
if (--mlxsw_sp->master_bridge.ref_count == 0) {
mlxsw_sp->master_bridge.dev = NULL;
mlxsw_sp_master_bridge_gone_sync(mlxsw_sp);
}
}
static int mlxsw_sp_port_bridge_join(struct mlxsw_sp_port *mlxsw_sp_port,
struct net_device *br_dev)
{
struct net_device *dev = mlxsw_sp_port->dev;
int err;
err = mlxsw_sp_port_kill_vid(dev, 0, 1);
if (err)
return err;
mlxsw_sp_master_bridge_inc(mlxsw_sp_port->mlxsw_sp, br_dev);
mlxsw_sp_port->learning = 1;
mlxsw_sp_port->learning_sync = 1;
mlxsw_sp_port->uc_flood = 1;
mlxsw_sp_port->mc_flood = 1;
mlxsw_sp_port->mc_router = 0;
mlxsw_sp_port->mc_disabled = 1;
mlxsw_sp_port->bridged = 1;
return 0;
}
static void mlxsw_sp_port_bridge_leave(struct mlxsw_sp_port *mlxsw_sp_port)
{
struct net_device *dev = mlxsw_sp_port->dev;
mlxsw_sp_port_pvid_set(mlxsw_sp_port, 1);
mlxsw_sp_master_bridge_dec(mlxsw_sp_port->mlxsw_sp);
mlxsw_sp_port->learning = 0;
mlxsw_sp_port->learning_sync = 0;
mlxsw_sp_port->uc_flood = 0;
mlxsw_sp_port->mc_flood = 0;
mlxsw_sp_port->mc_router = 0;
mlxsw_sp_port->bridged = 0;
mlxsw_sp_port_add_vid(dev, 0, 1);
}
static int mlxsw_sp_lag_create(struct mlxsw_sp *mlxsw_sp, u16 lag_id)
{
char sldr_pl[MLXSW_REG_SLDR_LEN];
mlxsw_reg_sldr_lag_create_pack(sldr_pl, lag_id);
return mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(sldr), sldr_pl);
}
static int mlxsw_sp_lag_destroy(struct mlxsw_sp *mlxsw_sp, u16 lag_id)
{
char sldr_pl[MLXSW_REG_SLDR_LEN];
mlxsw_reg_sldr_lag_destroy_pack(sldr_pl, lag_id);
return mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(sldr), sldr_pl);
}
static int mlxsw_sp_lag_col_port_add(struct mlxsw_sp_port *mlxsw_sp_port,
u16 lag_id, u8 port_index)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
char slcor_pl[MLXSW_REG_SLCOR_LEN];
mlxsw_reg_slcor_port_add_pack(slcor_pl, mlxsw_sp_port->local_port,
lag_id, port_index);
return mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(slcor), slcor_pl);
}
static int mlxsw_sp_lag_col_port_remove(struct mlxsw_sp_port *mlxsw_sp_port,
u16 lag_id)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
char slcor_pl[MLXSW_REG_SLCOR_LEN];
mlxsw_reg_slcor_port_remove_pack(slcor_pl, mlxsw_sp_port->local_port,
lag_id);
return mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(slcor), slcor_pl);
}
static int mlxsw_sp_lag_col_port_enable(struct mlxsw_sp_port *mlxsw_sp_port,
u16 lag_id)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
char slcor_pl[MLXSW_REG_SLCOR_LEN];
mlxsw_reg_slcor_col_enable_pack(slcor_pl, mlxsw_sp_port->local_port,
lag_id);
return mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(slcor), slcor_pl);
}
static int mlxsw_sp_lag_col_port_disable(struct mlxsw_sp_port *mlxsw_sp_port,
u16 lag_id)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
char slcor_pl[MLXSW_REG_SLCOR_LEN];
mlxsw_reg_slcor_col_disable_pack(slcor_pl, mlxsw_sp_port->local_port,
lag_id);
return mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(slcor), slcor_pl);
}
static int mlxsw_sp_lag_index_get(struct mlxsw_sp *mlxsw_sp,
struct net_device *lag_dev,
u16 *p_lag_id)
{
struct mlxsw_sp_upper *lag;
int free_lag_id = -1;
u64 max_lag;
int i;
max_lag = MLXSW_CORE_RES_GET(mlxsw_sp->core, MAX_LAG);
for (i = 0; i < max_lag; i++) {
lag = mlxsw_sp_lag_get(mlxsw_sp, i);
if (lag->ref_count) {
if (lag->dev == lag_dev) {
*p_lag_id = i;
return 0;
}
} else if (free_lag_id < 0) {
free_lag_id = i;
}
}
if (free_lag_id < 0)
return -EBUSY;
*p_lag_id = free_lag_id;
return 0;
}
static bool
mlxsw_sp_master_lag_check(struct mlxsw_sp *mlxsw_sp,
struct net_device *lag_dev,
struct netdev_lag_upper_info *lag_upper_info)
{
u16 lag_id;
if (mlxsw_sp_lag_index_get(mlxsw_sp, lag_dev, &lag_id) != 0)
return false;
if (lag_upper_info->tx_type != NETDEV_LAG_TX_TYPE_HASH)
return false;
return true;
}
static int mlxsw_sp_port_lag_index_get(struct mlxsw_sp *mlxsw_sp,
u16 lag_id, u8 *p_port_index)
{
u64 max_lag_members;
int i;
max_lag_members = MLXSW_CORE_RES_GET(mlxsw_sp->core,
MAX_LAG_MEMBERS);
for (i = 0; i < max_lag_members; i++) {
if (!mlxsw_sp_port_lagged_get(mlxsw_sp, lag_id, i)) {
*p_port_index = i;
return 0;
}
}
return -EBUSY;
}
static void
mlxsw_sp_port_pvid_vport_lag_join(struct mlxsw_sp_port *mlxsw_sp_port,
struct net_device *lag_dev, u16 lag_id)
{
struct mlxsw_sp_port *mlxsw_sp_vport;
struct mlxsw_sp_fid *f;
mlxsw_sp_vport = mlxsw_sp_port_vport_find(mlxsw_sp_port, 1);
if (WARN_ON(!mlxsw_sp_vport))
return;
f = mlxsw_sp_vport_fid_get(mlxsw_sp_vport);
if (f)
f->leave(mlxsw_sp_vport);
mlxsw_sp_vport->lag_id = lag_id;
mlxsw_sp_vport->lagged = 1;
mlxsw_sp_vport->dev = lag_dev;
}
static void
mlxsw_sp_port_pvid_vport_lag_leave(struct mlxsw_sp_port *mlxsw_sp_port)
{
struct mlxsw_sp_port *mlxsw_sp_vport;
struct mlxsw_sp_fid *f;
mlxsw_sp_vport = mlxsw_sp_port_vport_find(mlxsw_sp_port, 1);
if (WARN_ON(!mlxsw_sp_vport))
return;
f = mlxsw_sp_vport_fid_get(mlxsw_sp_vport);
if (f)
f->leave(mlxsw_sp_vport);
mlxsw_sp_vport->dev = mlxsw_sp_port->dev;
mlxsw_sp_vport->lagged = 0;
}
static int mlxsw_sp_port_lag_join(struct mlxsw_sp_port *mlxsw_sp_port,
struct net_device *lag_dev)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
struct mlxsw_sp_upper *lag;
u16 lag_id;
u8 port_index;
int err;
err = mlxsw_sp_lag_index_get(mlxsw_sp, lag_dev, &lag_id);
if (err)
return err;
lag = mlxsw_sp_lag_get(mlxsw_sp, lag_id);
if (!lag->ref_count) {
err = mlxsw_sp_lag_create(mlxsw_sp, lag_id);
if (err)
return err;
lag->dev = lag_dev;
}
err = mlxsw_sp_port_lag_index_get(mlxsw_sp, lag_id, &port_index);
if (err)
return err;
err = mlxsw_sp_lag_col_port_add(mlxsw_sp_port, lag_id, port_index);
if (err)
goto err_col_port_add;
err = mlxsw_sp_lag_col_port_enable(mlxsw_sp_port, lag_id);
if (err)
goto err_col_port_enable;
mlxsw_core_lag_mapping_set(mlxsw_sp->core, lag_id, port_index,
mlxsw_sp_port->local_port);
mlxsw_sp_port->lag_id = lag_id;
mlxsw_sp_port->lagged = 1;
lag->ref_count++;
mlxsw_sp_port_pvid_vport_lag_join(mlxsw_sp_port, lag_dev, lag_id);
return 0;
err_col_port_enable:
mlxsw_sp_lag_col_port_remove(mlxsw_sp_port, lag_id);
err_col_port_add:
if (!lag->ref_count)
mlxsw_sp_lag_destroy(mlxsw_sp, lag_id);
return err;
}
static void mlxsw_sp_port_lag_leave(struct mlxsw_sp_port *mlxsw_sp_port,
struct net_device *lag_dev)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
u16 lag_id = mlxsw_sp_port->lag_id;
struct mlxsw_sp_upper *lag;
if (!mlxsw_sp_port->lagged)
return;
lag = mlxsw_sp_lag_get(mlxsw_sp, lag_id);
WARN_ON(lag->ref_count == 0);
mlxsw_sp_lag_col_port_disable(mlxsw_sp_port, lag_id);
mlxsw_sp_lag_col_port_remove(mlxsw_sp_port, lag_id);
if (mlxsw_sp_port->bridged) {
mlxsw_sp_port_active_vlans_del(mlxsw_sp_port);
mlxsw_sp_port_bridge_leave(mlxsw_sp_port);
}
if (lag->ref_count == 1)
mlxsw_sp_lag_destroy(mlxsw_sp, lag_id);
mlxsw_core_lag_mapping_clear(mlxsw_sp->core, lag_id,
mlxsw_sp_port->local_port);
mlxsw_sp_port->lagged = 0;
lag->ref_count--;
mlxsw_sp_port_pvid_vport_lag_leave(mlxsw_sp_port);
}
static int mlxsw_sp_lag_dist_port_add(struct mlxsw_sp_port *mlxsw_sp_port,
u16 lag_id)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
char sldr_pl[MLXSW_REG_SLDR_LEN];
mlxsw_reg_sldr_lag_add_port_pack(sldr_pl, lag_id,
mlxsw_sp_port->local_port);
return mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(sldr), sldr_pl);
}
static int mlxsw_sp_lag_dist_port_remove(struct mlxsw_sp_port *mlxsw_sp_port,
u16 lag_id)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
char sldr_pl[MLXSW_REG_SLDR_LEN];
mlxsw_reg_sldr_lag_remove_port_pack(sldr_pl, lag_id,
mlxsw_sp_port->local_port);
return mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(sldr), sldr_pl);
}
static int mlxsw_sp_port_lag_tx_en_set(struct mlxsw_sp_port *mlxsw_sp_port,
bool lag_tx_enabled)
{
if (lag_tx_enabled)
return mlxsw_sp_lag_dist_port_add(mlxsw_sp_port,
mlxsw_sp_port->lag_id);
else
return mlxsw_sp_lag_dist_port_remove(mlxsw_sp_port,
mlxsw_sp_port->lag_id);
}
static int mlxsw_sp_port_lag_changed(struct mlxsw_sp_port *mlxsw_sp_port,
struct netdev_lag_lower_state_info *info)
{
return mlxsw_sp_port_lag_tx_en_set(mlxsw_sp_port, info->tx_enabled);
}
static int mlxsw_sp_port_vlan_link(struct mlxsw_sp_port *mlxsw_sp_port,
struct net_device *vlan_dev)
{
struct mlxsw_sp_port *mlxsw_sp_vport;
u16 vid = vlan_dev_vlan_id(vlan_dev);
mlxsw_sp_vport = mlxsw_sp_port_vport_find(mlxsw_sp_port, vid);
if (WARN_ON(!mlxsw_sp_vport))
return -EINVAL;
mlxsw_sp_vport->dev = vlan_dev;
return 0;
}
static void mlxsw_sp_port_vlan_unlink(struct mlxsw_sp_port *mlxsw_sp_port,
struct net_device *vlan_dev)
{
struct mlxsw_sp_port *mlxsw_sp_vport;
u16 vid = vlan_dev_vlan_id(vlan_dev);
mlxsw_sp_vport = mlxsw_sp_port_vport_find(mlxsw_sp_port, vid);
if (WARN_ON(!mlxsw_sp_vport))
return;
mlxsw_sp_vport->dev = mlxsw_sp_port->dev;
}
static int mlxsw_sp_port_stp_set(struct mlxsw_sp_port *mlxsw_sp_port,
bool enable)
{
struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
enum mlxsw_reg_spms_state spms_state;
char *spms_pl;
u16 vid;
int err;
spms_state = enable ? MLXSW_REG_SPMS_STATE_FORWARDING :
MLXSW_REG_SPMS_STATE_DISCARDING;
spms_pl = kmalloc(MLXSW_REG_SPMS_LEN, GFP_KERNEL);
if (!spms_pl)
return -ENOMEM;
mlxsw_reg_spms_pack(spms_pl, mlxsw_sp_port->local_port);
for (vid = 0; vid < VLAN_N_VID; vid++)
mlxsw_reg_spms_vid_pack(spms_pl, vid, spms_state);
err = mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(spms), spms_pl);
kfree(spms_pl);
return err;
}
static int mlxsw_sp_port_ovs_join(struct mlxsw_sp_port *mlxsw_sp_port)
{
int err;
err = mlxsw_sp_port_stp_set(mlxsw_sp_port, true);
if (err)
return err;
err = mlxsw_sp_port_vlan_set(mlxsw_sp_port, 2, VLAN_N_VID - 1,
true, false);
if (err)
goto err_port_vlan_set;
return 0;
err_port_vlan_set:
mlxsw_sp_port_stp_set(mlxsw_sp_port, false);
return err;
}
static void mlxsw_sp_port_ovs_leave(struct mlxsw_sp_port *mlxsw_sp_port)
{
mlxsw_sp_port_vlan_set(mlxsw_sp_port, 2, VLAN_N_VID - 1,
false, false);
mlxsw_sp_port_stp_set(mlxsw_sp_port, false);
}
static int mlxsw_sp_netdevice_port_upper_event(struct net_device *dev,
unsigned long event, void *ptr)
{
struct netdev_notifier_changeupper_info *info;
struct mlxsw_sp_port *mlxsw_sp_port;
struct net_device *upper_dev;
struct mlxsw_sp *mlxsw_sp;
int err = 0;
mlxsw_sp_port = netdev_priv(dev);
mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
info = ptr;
switch (event) {
case NETDEV_PRECHANGEUPPER:
upper_dev = info->upper_dev;
if (!is_vlan_dev(upper_dev) &&
!netif_is_lag_master(upper_dev) &&
!netif_is_bridge_master(upper_dev) &&
!netif_is_ovs_master(upper_dev))
return -EINVAL;
if (!info->linking)
break;
if (netif_is_bridge_master(upper_dev) &&
!mlxsw_sp_master_bridge_check(mlxsw_sp, upper_dev))
return -EINVAL;
if (netif_is_lag_master(upper_dev) &&
!mlxsw_sp_master_lag_check(mlxsw_sp, upper_dev,
info->upper_info))
return -EINVAL;
if (netif_is_lag_master(upper_dev) && vlan_uses_dev(dev))
return -EINVAL;
if (netif_is_lag_port(dev) && is_vlan_dev(upper_dev) &&
!netif_is_lag_master(vlan_dev_real_dev(upper_dev)))
return -EINVAL;
if (netif_is_ovs_master(upper_dev) && vlan_uses_dev(dev))
return -EINVAL;
if (netif_is_ovs_port(dev) && is_vlan_dev(upper_dev))
return -EINVAL;
break;
case NETDEV_CHANGEUPPER:
upper_dev = info->upper_dev;
if (is_vlan_dev(upper_dev)) {
if (info->linking)
err = mlxsw_sp_port_vlan_link(mlxsw_sp_port,
upper_dev);
else
mlxsw_sp_port_vlan_unlink(mlxsw_sp_port,
upper_dev);
} else if (netif_is_bridge_master(upper_dev)) {
if (info->linking)
err = mlxsw_sp_port_bridge_join(mlxsw_sp_port,
upper_dev);
else
mlxsw_sp_port_bridge_leave(mlxsw_sp_port);
} else if (netif_is_lag_master(upper_dev)) {
if (info->linking)
err = mlxsw_sp_port_lag_join(mlxsw_sp_port,
upper_dev);
else
mlxsw_sp_port_lag_leave(mlxsw_sp_port,
upper_dev);
} else if (netif_is_ovs_master(upper_dev)) {
if (info->linking)
err = mlxsw_sp_port_ovs_join(mlxsw_sp_port);
else
mlxsw_sp_port_ovs_leave(mlxsw_sp_port);
} else {
err = -EINVAL;
WARN_ON(1);
}
break;
}
return err;
}
static int mlxsw_sp_netdevice_port_lower_event(struct net_device *dev,
unsigned long event, void *ptr)
{
struct netdev_notifier_changelowerstate_info *info;
struct mlxsw_sp_port *mlxsw_sp_port;
int err;
mlxsw_sp_port = netdev_priv(dev);
info = ptr;
switch (event) {
case NETDEV_CHANGELOWERSTATE:
if (netif_is_lag_port(dev) && mlxsw_sp_port->lagged) {
err = mlxsw_sp_port_lag_changed(mlxsw_sp_port,
info->lower_state_info);
if (err)
netdev_err(dev, "Failed to reflect link aggregation lower state change\n");
}
break;
}
return 0;
}
static int mlxsw_sp_netdevice_port_event(struct net_device *dev,
unsigned long event, void *ptr)
{
switch (event) {
case NETDEV_PRECHANGEUPPER:
case NETDEV_CHANGEUPPER:
return mlxsw_sp_netdevice_port_upper_event(dev, event, ptr);
case NETDEV_CHANGELOWERSTATE:
return mlxsw_sp_netdevice_port_lower_event(dev, event, ptr);
}
return 0;
}
static int mlxsw_sp_netdevice_lag_event(struct net_device *lag_dev,
unsigned long event, void *ptr)
{
struct net_device *dev;
struct list_head *iter;
int ret;
netdev_for_each_lower_dev(lag_dev, dev, iter) {
if (mlxsw_sp_port_dev_check(dev)) {
ret = mlxsw_sp_netdevice_port_event(dev, event, ptr);
if (ret)
return ret;
}
}
return 0;
}
static int mlxsw_sp_master_bridge_vlan_link(struct mlxsw_sp *mlxsw_sp,
struct net_device *vlan_dev)
{
u16 fid = vlan_dev_vlan_id(vlan_dev);
struct mlxsw_sp_fid *f;
f = mlxsw_sp_fid_find(mlxsw_sp, fid);
if (!f) {
f = mlxsw_sp_fid_create(mlxsw_sp, fid);
if (IS_ERR(f))
return PTR_ERR(f);
}
f->ref_count++;
return 0;
}
static void mlxsw_sp_master_bridge_vlan_unlink(struct mlxsw_sp *mlxsw_sp,
struct net_device *vlan_dev)
{
u16 fid = vlan_dev_vlan_id(vlan_dev);
struct mlxsw_sp_fid *f;
f = mlxsw_sp_fid_find(mlxsw_sp, fid);
if (f && f->rif)
mlxsw_sp_rif_bridge_destroy(mlxsw_sp, f->rif);
if (f && --f->ref_count == 0)
mlxsw_sp_fid_destroy(mlxsw_sp, f);
}
static int mlxsw_sp_netdevice_bridge_event(struct net_device *br_dev,
unsigned long event, void *ptr)
{
struct netdev_notifier_changeupper_info *info;
struct net_device *upper_dev;
struct mlxsw_sp *mlxsw_sp;
int err = 0;
mlxsw_sp = mlxsw_sp_lower_get(br_dev);
if (!mlxsw_sp)
return 0;
info = ptr;
switch (event) {
case NETDEV_PRECHANGEUPPER:
upper_dev = info->upper_dev;
if (!is_vlan_dev(upper_dev))
return -EINVAL;
if (is_vlan_dev(upper_dev) &&
br_dev != mlxsw_sp->master_bridge.dev)
return -EINVAL;
break;
case NETDEV_CHANGEUPPER:
upper_dev = info->upper_dev;
if (is_vlan_dev(upper_dev)) {
if (info->linking)
err = mlxsw_sp_master_bridge_vlan_link(mlxsw_sp,
upper_dev);
else
mlxsw_sp_master_bridge_vlan_unlink(mlxsw_sp,
upper_dev);
} else {
err = -EINVAL;
WARN_ON(1);
}
break;
}
return err;
}
static u16 mlxsw_sp_avail_vfid_get(const struct mlxsw_sp *mlxsw_sp)
{
return find_first_zero_bit(mlxsw_sp->vfids.mapped,
MLXSW_SP_VFID_MAX);
}
static int mlxsw_sp_vfid_op(struct mlxsw_sp *mlxsw_sp, u16 fid, bool create)
{
char sfmr_pl[MLXSW_REG_SFMR_LEN];
mlxsw_reg_sfmr_pack(sfmr_pl, !create, fid, 0);
return mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(sfmr), sfmr_pl);
}
static struct mlxsw_sp_fid *mlxsw_sp_vfid_create(struct mlxsw_sp *mlxsw_sp,
struct net_device *br_dev)
{
struct device *dev = mlxsw_sp->bus_info->dev;
struct mlxsw_sp_fid *f;
u16 vfid, fid;
int err;
vfid = mlxsw_sp_avail_vfid_get(mlxsw_sp);
if (vfid == MLXSW_SP_VFID_MAX) {
dev_err(dev, "No available vFIDs\n");
return ERR_PTR(-ERANGE);
}
fid = mlxsw_sp_vfid_to_fid(vfid);
err = mlxsw_sp_vfid_op(mlxsw_sp, fid, true);
if (err) {
dev_err(dev, "Failed to create FID=%d\n", fid);
return ERR_PTR(err);
}
f = kzalloc(sizeof(*f), GFP_KERNEL);
if (!f)
goto err_allocate_vfid;
f->leave = mlxsw_sp_vport_vfid_leave;
f->fid = fid;
f->dev = br_dev;
list_add(&f->list, &mlxsw_sp->vfids.list);
set_bit(vfid, mlxsw_sp->vfids.mapped);
return f;
err_allocate_vfid:
mlxsw_sp_vfid_op(mlxsw_sp, fid, false);
return ERR_PTR(-ENOMEM);
}
static void mlxsw_sp_vfid_destroy(struct mlxsw_sp *mlxsw_sp,
struct mlxsw_sp_fid *f)
{
u16 vfid = mlxsw_sp_fid_to_vfid(f->fid);
u16 fid = f->fid;
clear_bit(vfid, mlxsw_sp->vfids.mapped);
list_del(&f->list);
if (f->rif)
mlxsw_sp_rif_bridge_destroy(mlxsw_sp, f->rif);
kfree(f);
mlxsw_sp_vfid_op(mlxsw_sp, fid, false);
}
static int mlxsw_sp_vport_fid_map(struct mlxsw_sp_port *mlxsw_sp_vport, u16 fid,
bool valid)
{
enum mlxsw_reg_svfa_mt mt = MLXSW_REG_SVFA_MT_PORT_VID_TO_FID;
u16 vid = mlxsw_sp_vport_vid_get(mlxsw_sp_vport);
return mlxsw_sp_port_vid_to_fid_set(mlxsw_sp_vport, mt, valid, fid,
vid);
}
static int mlxsw_sp_vport_vfid_join(struct mlxsw_sp_port *mlxsw_sp_vport,
struct net_device *br_dev)
{
struct mlxsw_sp_fid *f;
int err;
f = mlxsw_sp_vfid_find(mlxsw_sp_vport->mlxsw_sp, br_dev);
if (!f) {
f = mlxsw_sp_vfid_create(mlxsw_sp_vport->mlxsw_sp, br_dev);
if (IS_ERR(f))
return PTR_ERR(f);
}
err = mlxsw_sp_vport_flood_set(mlxsw_sp_vport, f->fid, true);
if (err)
goto err_vport_flood_set;
err = mlxsw_sp_vport_fid_map(mlxsw_sp_vport, f->fid, true);
if (err)
goto err_vport_fid_map;
mlxsw_sp_vport_fid_set(mlxsw_sp_vport, f);
f->ref_count++;
netdev_dbg(mlxsw_sp_vport->dev, "Joined FID=%d\n", f->fid);
return 0;
err_vport_fid_map:
mlxsw_sp_vport_flood_set(mlxsw_sp_vport, f->fid, false);
err_vport_flood_set:
if (!f->ref_count)
mlxsw_sp_vfid_destroy(mlxsw_sp_vport->mlxsw_sp, f);
return err;
}
static void mlxsw_sp_vport_vfid_leave(struct mlxsw_sp_port *mlxsw_sp_vport)
{
struct mlxsw_sp_fid *f = mlxsw_sp_vport_fid_get(mlxsw_sp_vport);
netdev_dbg(mlxsw_sp_vport->dev, "Left FID=%d\n", f->fid);
mlxsw_sp_vport_fid_map(mlxsw_sp_vport, f->fid, false);
mlxsw_sp_vport_flood_set(mlxsw_sp_vport, f->fid, false);
mlxsw_sp_port_fdb_flush(mlxsw_sp_vport, f->fid);
mlxsw_sp_vport_fid_set(mlxsw_sp_vport, NULL);
if (--f->ref_count == 0)
mlxsw_sp_vfid_destroy(mlxsw_sp_vport->mlxsw_sp, f);
}
static int mlxsw_sp_vport_bridge_join(struct mlxsw_sp_port *mlxsw_sp_vport,
struct net_device *br_dev)
{
struct mlxsw_sp_fid *f = mlxsw_sp_vport_fid_get(mlxsw_sp_vport);
u16 vid = mlxsw_sp_vport_vid_get(mlxsw_sp_vport);
struct net_device *dev = mlxsw_sp_vport->dev;
int err;
if (f && !WARN_ON(!f->leave))
f->leave(mlxsw_sp_vport);
err = mlxsw_sp_vport_vfid_join(mlxsw_sp_vport, br_dev);
if (err) {
netdev_err(dev, "Failed to join vFID\n");
return err;
}
err = mlxsw_sp_port_vid_learning_set(mlxsw_sp_vport, vid, true);
if (err) {
netdev_err(dev, "Failed to enable learning\n");
goto err_port_vid_learning_set;
}
mlxsw_sp_vport->learning = 1;
mlxsw_sp_vport->learning_sync = 1;
mlxsw_sp_vport->uc_flood = 1;
mlxsw_sp_vport->mc_flood = 1;
mlxsw_sp_vport->mc_router = 0;
mlxsw_sp_vport->mc_disabled = 1;
mlxsw_sp_vport->bridged = 1;
return 0;
err_port_vid_learning_set:
mlxsw_sp_vport_vfid_leave(mlxsw_sp_vport);
return err;
}
static void mlxsw_sp_vport_bridge_leave(struct mlxsw_sp_port *mlxsw_sp_vport)
{
u16 vid = mlxsw_sp_vport_vid_get(mlxsw_sp_vport);
mlxsw_sp_port_vid_learning_set(mlxsw_sp_vport, vid, false);
mlxsw_sp_vport_vfid_leave(mlxsw_sp_vport);
mlxsw_sp_vport->learning = 0;
mlxsw_sp_vport->learning_sync = 0;
mlxsw_sp_vport->uc_flood = 0;
mlxsw_sp_vport->mc_flood = 0;
mlxsw_sp_vport->mc_router = 0;
mlxsw_sp_vport->bridged = 0;
}
static bool
mlxsw_sp_port_master_bridge_check(const struct mlxsw_sp_port *mlxsw_sp_port,
const struct net_device *br_dev)
{
struct mlxsw_sp_port *mlxsw_sp_vport;
list_for_each_entry(mlxsw_sp_vport, &mlxsw_sp_port->vports_list,
vport.list) {
struct net_device *dev = mlxsw_sp_vport_dev_get(mlxsw_sp_vport);
if (dev && dev == br_dev)
return false;
}
return true;
}
static int mlxsw_sp_netdevice_vport_event(struct net_device *dev,
unsigned long event, void *ptr,
u16 vid)
{
struct mlxsw_sp_port *mlxsw_sp_port = netdev_priv(dev);
struct netdev_notifier_changeupper_info *info = ptr;
struct mlxsw_sp_port *mlxsw_sp_vport;
struct net_device *upper_dev;
int err = 0;
mlxsw_sp_vport = mlxsw_sp_port_vport_find(mlxsw_sp_port, vid);
if (!mlxsw_sp_vport)
return 0;
switch (event) {
case NETDEV_PRECHANGEUPPER:
upper_dev = info->upper_dev;
if (!netif_is_bridge_master(upper_dev))
return -EINVAL;
if (!info->linking)
break;
if (netif_is_bridge_master(upper_dev) &&
!mlxsw_sp_port_master_bridge_check(mlxsw_sp_port,
upper_dev))
return -EINVAL;
break;
case NETDEV_CHANGEUPPER:
upper_dev = info->upper_dev;
if (netif_is_bridge_master(upper_dev)) {
if (info->linking)
err = mlxsw_sp_vport_bridge_join(mlxsw_sp_vport,
upper_dev);
else
mlxsw_sp_vport_bridge_leave(mlxsw_sp_vport);
} else {
err = -EINVAL;
WARN_ON(1);
}
break;
}
return err;
}
static int mlxsw_sp_netdevice_lag_vport_event(struct net_device *lag_dev,
unsigned long event, void *ptr,
u16 vid)
{
struct net_device *dev;
struct list_head *iter;
int ret;
netdev_for_each_lower_dev(lag_dev, dev, iter) {
if (mlxsw_sp_port_dev_check(dev)) {
ret = mlxsw_sp_netdevice_vport_event(dev, event, ptr,
vid);
if (ret)
return ret;
}
}
return 0;
}
static int mlxsw_sp_netdevice_vlan_event(struct net_device *vlan_dev,
unsigned long event, void *ptr)
{
struct net_device *real_dev = vlan_dev_real_dev(vlan_dev);
u16 vid = vlan_dev_vlan_id(vlan_dev);
if (mlxsw_sp_port_dev_check(real_dev))
return mlxsw_sp_netdevice_vport_event(real_dev, event, ptr,
vid);
else if (netif_is_lag_master(real_dev))
return mlxsw_sp_netdevice_lag_vport_event(real_dev, event, ptr,
vid);
return 0;
}
static bool mlxsw_sp_is_vrf_event(unsigned long event, void *ptr)
{
struct netdev_notifier_changeupper_info *info = ptr;
if (event != NETDEV_PRECHANGEUPPER && event != NETDEV_CHANGEUPPER)
return false;
return netif_is_l3_master(info->upper_dev);
}
static int mlxsw_sp_netdevice_event(struct notifier_block *unused,
unsigned long event, void *ptr)
{
struct net_device *dev = netdev_notifier_info_to_dev(ptr);
int err = 0;
if (event == NETDEV_CHANGEADDR || event == NETDEV_CHANGEMTU)
err = mlxsw_sp_netdevice_router_port_event(dev);
else if (mlxsw_sp_is_vrf_event(event, ptr))
err = mlxsw_sp_netdevice_vrf_event(dev, event, ptr);
else if (mlxsw_sp_port_dev_check(dev))
err = mlxsw_sp_netdevice_port_event(dev, event, ptr);
else if (netif_is_lag_master(dev))
err = mlxsw_sp_netdevice_lag_event(dev, event, ptr);
else if (netif_is_bridge_master(dev))
err = mlxsw_sp_netdevice_bridge_event(dev, event, ptr);
else if (is_vlan_dev(dev))
err = mlxsw_sp_netdevice_vlan_event(dev, event, ptr);
return notifier_from_errno(err);
}
static int __init mlxsw_sp_module_init(void)
{
int err;
register_netdevice_notifier(&mlxsw_sp_netdevice_nb);
register_inetaddr_notifier(&mlxsw_sp_inetaddr_nb);
register_netevent_notifier(&mlxsw_sp_router_netevent_nb);
err = mlxsw_core_driver_register(&mlxsw_sp_driver);
if (err)
goto err_core_driver_register;
err = mlxsw_pci_driver_register(&mlxsw_sp_pci_driver);
if (err)
goto err_pci_driver_register;
return 0;
err_pci_driver_register:
mlxsw_core_driver_unregister(&mlxsw_sp_driver);
err_core_driver_register:
unregister_netevent_notifier(&mlxsw_sp_router_netevent_nb);
unregister_inetaddr_notifier(&mlxsw_sp_inetaddr_nb);
unregister_netdevice_notifier(&mlxsw_sp_netdevice_nb);
return err;
}
static void __exit mlxsw_sp_module_exit(void)
{
mlxsw_pci_driver_unregister(&mlxsw_sp_pci_driver);
mlxsw_core_driver_unregister(&mlxsw_sp_driver);
unregister_netevent_notifier(&mlxsw_sp_router_netevent_nb);
unregister_inetaddr_notifier(&mlxsw_sp_inetaddr_nb);
unregister_netdevice_notifier(&mlxsw_sp_netdevice_nb);
}
