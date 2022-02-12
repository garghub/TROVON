static inline int cpsw_ale_get_field(u32 *ale_entry, u32 start, u32 bits)
{
int idx;
idx = start / 32;
start -= idx * 32;
idx = 2 - idx;
return (ale_entry[idx] >> start) & BITMASK(bits);
}
static inline void cpsw_ale_set_field(u32 *ale_entry, u32 start, u32 bits,
u32 value)
{
int idx;
value &= BITMASK(bits);
idx = start / 32;
start -= idx * 32;
idx = 2 - idx;
ale_entry[idx] &= ~(BITMASK(bits) << start);
ale_entry[idx] |= (value << start);
}
static inline void cpsw_ale_get_addr(u32 *ale_entry, u8 *addr)
{
int i;
for (i = 0; i < 6; i++)
addr[i] = cpsw_ale_get_field(ale_entry, 40 - 8*i, 8);
}
static inline void cpsw_ale_set_addr(u32 *ale_entry, u8 *addr)
{
int i;
for (i = 0; i < 6; i++)
cpsw_ale_set_field(ale_entry, 40 - 8*i, 8, addr[i]);
}
static int cpsw_ale_read(struct cpsw_ale *ale, int idx, u32 *ale_entry)
{
int i;
WARN_ON(idx > ale->params.ale_entries);
__raw_writel(idx, ale->params.ale_regs + ALE_TABLE_CONTROL);
for (i = 0; i < ALE_ENTRY_WORDS; i++)
ale_entry[i] = __raw_readl(ale->params.ale_regs +
ALE_TABLE + 4 * i);
return idx;
}
static int cpsw_ale_write(struct cpsw_ale *ale, int idx, u32 *ale_entry)
{
int i;
WARN_ON(idx > ale->params.ale_entries);
for (i = 0; i < ALE_ENTRY_WORDS; i++)
__raw_writel(ale_entry[i], ale->params.ale_regs +
ALE_TABLE + 4 * i);
__raw_writel(idx | ALE_TABLE_WRITE, ale->params.ale_regs +
ALE_TABLE_CONTROL);
return idx;
}
int cpsw_ale_match_addr(struct cpsw_ale *ale, u8 *addr, u16 vid)
{
u32 ale_entry[ALE_ENTRY_WORDS];
int type, idx;
for (idx = 0; idx < ale->params.ale_entries; idx++) {
u8 entry_addr[6];
cpsw_ale_read(ale, idx, ale_entry);
type = cpsw_ale_get_entry_type(ale_entry);
if (type != ALE_TYPE_ADDR && type != ALE_TYPE_VLAN_ADDR)
continue;
if (cpsw_ale_get_vlan_id(ale_entry) != vid)
continue;
cpsw_ale_get_addr(ale_entry, entry_addr);
if (ether_addr_equal(entry_addr, addr))
return idx;
}
return -ENOENT;
}
int cpsw_ale_match_vlan(struct cpsw_ale *ale, u16 vid)
{
u32 ale_entry[ALE_ENTRY_WORDS];
int type, idx;
for (idx = 0; idx < ale->params.ale_entries; idx++) {
cpsw_ale_read(ale, idx, ale_entry);
type = cpsw_ale_get_entry_type(ale_entry);
if (type != ALE_TYPE_VLAN)
continue;
if (cpsw_ale_get_vlan_id(ale_entry) == vid)
return idx;
}
return -ENOENT;
}
static int cpsw_ale_match_free(struct cpsw_ale *ale)
{
u32 ale_entry[ALE_ENTRY_WORDS];
int type, idx;
for (idx = 0; idx < ale->params.ale_entries; idx++) {
cpsw_ale_read(ale, idx, ale_entry);
type = cpsw_ale_get_entry_type(ale_entry);
if (type == ALE_TYPE_FREE)
return idx;
}
return -ENOENT;
}
static int cpsw_ale_find_ageable(struct cpsw_ale *ale)
{
u32 ale_entry[ALE_ENTRY_WORDS];
int type, idx;
for (idx = 0; idx < ale->params.ale_entries; idx++) {
cpsw_ale_read(ale, idx, ale_entry);
type = cpsw_ale_get_entry_type(ale_entry);
if (type != ALE_TYPE_ADDR && type != ALE_TYPE_VLAN_ADDR)
continue;
if (cpsw_ale_get_mcast(ale_entry))
continue;
type = cpsw_ale_get_ucast_type(ale_entry);
if (type != ALE_UCAST_PERSISTANT &&
type != ALE_UCAST_OUI)
return idx;
}
return -ENOENT;
}
static void cpsw_ale_flush_mcast(struct cpsw_ale *ale, u32 *ale_entry,
int port_mask)
{
int mask;
mask = cpsw_ale_get_port_mask(ale_entry);
if ((mask & port_mask) == 0)
return;
mask &= ~port_mask;
if (mask)
cpsw_ale_set_port_mask(ale_entry, mask);
else
cpsw_ale_set_entry_type(ale_entry, ALE_TYPE_FREE);
}
int cpsw_ale_flush_multicast(struct cpsw_ale *ale, int port_mask)
{
u32 ale_entry[ALE_ENTRY_WORDS];
int ret, idx;
for (idx = 0; idx < ale->params.ale_entries; idx++) {
cpsw_ale_read(ale, idx, ale_entry);
ret = cpsw_ale_get_entry_type(ale_entry);
if (ret != ALE_TYPE_ADDR && ret != ALE_TYPE_VLAN_ADDR)
continue;
if (cpsw_ale_get_mcast(ale_entry)) {
u8 addr[6];
cpsw_ale_get_addr(ale_entry, addr);
if (!is_broadcast_ether_addr(addr))
cpsw_ale_flush_mcast(ale, ale_entry, port_mask);
}
cpsw_ale_write(ale, idx, ale_entry);
}
return 0;
}
static void cpsw_ale_flush_ucast(struct cpsw_ale *ale, u32 *ale_entry,
int port_mask)
{
int port;
port = cpsw_ale_get_port_num(ale_entry);
if ((BIT(port) & port_mask) == 0)
return;
cpsw_ale_set_entry_type(ale_entry, ALE_TYPE_FREE);
}
int cpsw_ale_flush(struct cpsw_ale *ale, int port_mask)
{
u32 ale_entry[ALE_ENTRY_WORDS];
int ret, idx;
for (idx = 0; idx < ale->params.ale_entries; idx++) {
cpsw_ale_read(ale, idx, ale_entry);
ret = cpsw_ale_get_entry_type(ale_entry);
if (ret != ALE_TYPE_ADDR && ret != ALE_TYPE_VLAN_ADDR)
continue;
if (cpsw_ale_get_mcast(ale_entry))
cpsw_ale_flush_mcast(ale, ale_entry, port_mask);
else
cpsw_ale_flush_ucast(ale, ale_entry, port_mask);
cpsw_ale_write(ale, idx, ale_entry);
}
return 0;
}
static inline void cpsw_ale_set_vlan_entry_type(u32 *ale_entry,
int flags, u16 vid)
{
if (flags & ALE_VLAN) {
cpsw_ale_set_entry_type(ale_entry, ALE_TYPE_VLAN_ADDR);
cpsw_ale_set_vlan_id(ale_entry, vid);
} else {
cpsw_ale_set_entry_type(ale_entry, ALE_TYPE_ADDR);
}
}
int cpsw_ale_add_ucast(struct cpsw_ale *ale, u8 *addr, int port,
int flags, u16 vid)
{
u32 ale_entry[ALE_ENTRY_WORDS] = {0, 0, 0};
int idx;
cpsw_ale_set_vlan_entry_type(ale_entry, flags, vid);
cpsw_ale_set_addr(ale_entry, addr);
cpsw_ale_set_ucast_type(ale_entry, ALE_UCAST_PERSISTANT);
cpsw_ale_set_secure(ale_entry, (flags & ALE_SECURE) ? 1 : 0);
cpsw_ale_set_blocked(ale_entry, (flags & ALE_BLOCKED) ? 1 : 0);
cpsw_ale_set_port_num(ale_entry, port);
idx = cpsw_ale_match_addr(ale, addr, (flags & ALE_VLAN) ? vid : 0);
if (idx < 0)
idx = cpsw_ale_match_free(ale);
if (idx < 0)
idx = cpsw_ale_find_ageable(ale);
if (idx < 0)
return -ENOMEM;
cpsw_ale_write(ale, idx, ale_entry);
return 0;
}
int cpsw_ale_del_ucast(struct cpsw_ale *ale, u8 *addr, int port,
int flags, u16 vid)
{
u32 ale_entry[ALE_ENTRY_WORDS] = {0, 0, 0};
int idx;
idx = cpsw_ale_match_addr(ale, addr, (flags & ALE_VLAN) ? vid : 0);
if (idx < 0)
return -ENOENT;
cpsw_ale_set_entry_type(ale_entry, ALE_TYPE_FREE);
cpsw_ale_write(ale, idx, ale_entry);
return 0;
}
int cpsw_ale_add_mcast(struct cpsw_ale *ale, u8 *addr, int port_mask,
int flags, u16 vid, int mcast_state)
{
u32 ale_entry[ALE_ENTRY_WORDS] = {0, 0, 0};
int idx, mask;
idx = cpsw_ale_match_addr(ale, addr, (flags & ALE_VLAN) ? vid : 0);
if (idx >= 0)
cpsw_ale_read(ale, idx, ale_entry);
cpsw_ale_set_vlan_entry_type(ale_entry, flags, vid);
cpsw_ale_set_addr(ale_entry, addr);
cpsw_ale_set_super(ale_entry, (flags & ALE_BLOCKED) ? 1 : 0);
cpsw_ale_set_mcast_state(ale_entry, mcast_state);
mask = cpsw_ale_get_port_mask(ale_entry);
port_mask |= mask;
cpsw_ale_set_port_mask(ale_entry, port_mask);
if (idx < 0)
idx = cpsw_ale_match_free(ale);
if (idx < 0)
idx = cpsw_ale_find_ageable(ale);
if (idx < 0)
return -ENOMEM;
cpsw_ale_write(ale, idx, ale_entry);
return 0;
}
int cpsw_ale_del_mcast(struct cpsw_ale *ale, u8 *addr, int port_mask,
int flags, u16 vid)
{
u32 ale_entry[ALE_ENTRY_WORDS] = {0, 0, 0};
int idx;
idx = cpsw_ale_match_addr(ale, addr, (flags & ALE_VLAN) ? vid : 0);
if (idx < 0)
return -EINVAL;
cpsw_ale_read(ale, idx, ale_entry);
if (port_mask)
cpsw_ale_set_port_mask(ale_entry, port_mask);
else
cpsw_ale_set_entry_type(ale_entry, ALE_TYPE_FREE);
cpsw_ale_write(ale, idx, ale_entry);
return 0;
}
int cpsw_ale_add_vlan(struct cpsw_ale *ale, u16 vid, int port, int untag,
int reg_mcast, int unreg_mcast)
{
u32 ale_entry[ALE_ENTRY_WORDS] = {0, 0, 0};
int idx;
idx = cpsw_ale_match_vlan(ale, vid);
if (idx >= 0)
cpsw_ale_read(ale, idx, ale_entry);
cpsw_ale_set_entry_type(ale_entry, ALE_TYPE_VLAN);
cpsw_ale_set_vlan_id(ale_entry, vid);
cpsw_ale_set_vlan_untag_force(ale_entry, untag);
cpsw_ale_set_vlan_reg_mcast(ale_entry, reg_mcast);
cpsw_ale_set_vlan_unreg_mcast(ale_entry, unreg_mcast);
cpsw_ale_set_vlan_member_list(ale_entry, port);
if (idx < 0)
idx = cpsw_ale_match_free(ale);
if (idx < 0)
idx = cpsw_ale_find_ageable(ale);
if (idx < 0)
return -ENOMEM;
cpsw_ale_write(ale, idx, ale_entry);
return 0;
}
int cpsw_ale_del_vlan(struct cpsw_ale *ale, u16 vid, int port_mask)
{
u32 ale_entry[ALE_ENTRY_WORDS] = {0, 0, 0};
int idx;
idx = cpsw_ale_match_vlan(ale, vid);
if (idx < 0)
return -ENOENT;
cpsw_ale_read(ale, idx, ale_entry);
if (port_mask)
cpsw_ale_set_vlan_member_list(ale_entry, port_mask);
else
cpsw_ale_set_entry_type(ale_entry, ALE_TYPE_FREE);
cpsw_ale_write(ale, idx, ale_entry);
return 0;
}
void cpsw_ale_set_allmulti(struct cpsw_ale *ale, int allmulti)
{
u32 ale_entry[ALE_ENTRY_WORDS];
int type, idx;
int unreg_mcast = 0;
if (ale->allmulti == allmulti)
return;
ale->allmulti = allmulti;
for (idx = 0; idx < ale->params.ale_entries; idx++) {
cpsw_ale_read(ale, idx, ale_entry);
type = cpsw_ale_get_entry_type(ale_entry);
if (type != ALE_TYPE_VLAN)
continue;
unreg_mcast = cpsw_ale_get_vlan_unreg_mcast(ale_entry);
if (allmulti)
unreg_mcast |= 1;
else
unreg_mcast &= ~1;
cpsw_ale_set_vlan_unreg_mcast(ale_entry, unreg_mcast);
cpsw_ale_write(ale, idx, ale_entry);
}
}
int cpsw_ale_control_set(struct cpsw_ale *ale, int port, int control,
int value)
{
const struct ale_control_info *info;
int offset, shift;
u32 tmp, mask;
if (control < 0 || control >= ARRAY_SIZE(ale_controls))
return -EINVAL;
info = &ale_controls[control];
if (info->port_offset == 0 && info->port_shift == 0)
port = 0;
if (port < 0 || port > ale->params.ale_ports)
return -EINVAL;
mask = BITMASK(info->bits);
if (value & ~mask)
return -EINVAL;
offset = info->offset + (port * info->port_offset);
shift = info->shift + (port * info->port_shift);
tmp = __raw_readl(ale->params.ale_regs + offset);
tmp = (tmp & ~(mask << shift)) | (value << shift);
__raw_writel(tmp, ale->params.ale_regs + offset);
return 0;
}
int cpsw_ale_control_get(struct cpsw_ale *ale, int port, int control)
{
const struct ale_control_info *info;
int offset, shift;
u32 tmp;
if (control < 0 || control >= ARRAY_SIZE(ale_controls))
return -EINVAL;
info = &ale_controls[control];
if (info->port_offset == 0 && info->port_shift == 0)
port = 0;
if (port < 0 || port > ale->params.ale_ports)
return -EINVAL;
offset = info->offset + (port * info->port_offset);
shift = info->shift + (port * info->port_shift);
tmp = __raw_readl(ale->params.ale_regs + offset) >> shift;
return tmp & BITMASK(info->bits);
}
static void cpsw_ale_timer(unsigned long arg)
{
struct cpsw_ale *ale = (struct cpsw_ale *)arg;
cpsw_ale_control_set(ale, 0, ALE_AGEOUT, 1);
if (ale->ageout) {
ale->timer.expires = jiffies + ale->ageout;
add_timer(&ale->timer);
}
}
int cpsw_ale_set_ageout(struct cpsw_ale *ale, int ageout)
{
del_timer_sync(&ale->timer);
ale->ageout = ageout * HZ;
if (ale->ageout) {
ale->timer.expires = jiffies + ale->ageout;
add_timer(&ale->timer);
}
return 0;
}
void cpsw_ale_start(struct cpsw_ale *ale)
{
u32 rev;
rev = __raw_readl(ale->params.ale_regs + ALE_IDVER);
dev_dbg(ale->params.dev, "initialized cpsw ale revision %d.%d\n",
ALE_VERSION_MAJOR(rev), ALE_VERSION_MINOR(rev));
cpsw_ale_control_set(ale, 0, ALE_ENABLE, 1);
cpsw_ale_control_set(ale, 0, ALE_CLEAR, 1);
init_timer(&ale->timer);
ale->timer.data = (unsigned long)ale;
ale->timer.function = cpsw_ale_timer;
if (ale->ageout) {
ale->timer.expires = jiffies + ale->ageout;
add_timer(&ale->timer);
}
}
void cpsw_ale_stop(struct cpsw_ale *ale)
{
del_timer_sync(&ale->timer);
}
struct cpsw_ale *cpsw_ale_create(struct cpsw_ale_params *params)
{
struct cpsw_ale *ale;
ale = kzalloc(sizeof(*ale), GFP_KERNEL);
if (!ale)
return NULL;
ale->params = *params;
ale->ageout = ale->params.ale_ageout * HZ;
return ale;
}
int cpsw_ale_destroy(struct cpsw_ale *ale)
{
if (!ale)
return -EINVAL;
cpsw_ale_control_set(ale, 0, ALE_ENABLE, 0);
kfree(ale);
return 0;
}
void cpsw_ale_dump(struct cpsw_ale *ale, u32 *data)
{
int i;
for (i = 0; i < ale->params.ale_entries; i++) {
cpsw_ale_read(ale, i, data);
data += ALE_ENTRY_WORDS;
}
}
