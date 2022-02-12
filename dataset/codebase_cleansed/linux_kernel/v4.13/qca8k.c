static void
qca8k_split_addr(u32 regaddr, u16 *r1, u16 *r2, u16 *page)
{
regaddr >>= 1;
*r1 = regaddr & 0x1e;
regaddr >>= 5;
*r2 = regaddr & 0x7;
regaddr >>= 3;
*page = regaddr & 0x3ff;
}
static u32
qca8k_mii_read32(struct mii_bus *bus, int phy_id, u32 regnum)
{
u32 val;
int ret;
ret = bus->read(bus, phy_id, regnum);
if (ret >= 0) {
val = ret;
ret = bus->read(bus, phy_id, regnum + 1);
val |= ret << 16;
}
if (ret < 0) {
dev_err_ratelimited(&bus->dev,
"failed to read qca8k 32bit register\n");
return ret;
}
return val;
}
static void
qca8k_mii_write32(struct mii_bus *bus, int phy_id, u32 regnum, u32 val)
{
u16 lo, hi;
int ret;
lo = val & 0xffff;
hi = (u16)(val >> 16);
ret = bus->write(bus, phy_id, regnum, lo);
if (ret >= 0)
ret = bus->write(bus, phy_id, regnum + 1, hi);
if (ret < 0)
dev_err_ratelimited(&bus->dev,
"failed to write qca8k 32bit register\n");
}
static void
qca8k_set_page(struct mii_bus *bus, u16 page)
{
if (page == qca8k_current_page)
return;
if (bus->write(bus, 0x18, 0, page) < 0)
dev_err_ratelimited(&bus->dev,
"failed to set qca8k page\n");
qca8k_current_page = page;
}
static u32
qca8k_read(struct qca8k_priv *priv, u32 reg)
{
u16 r1, r2, page;
u32 val;
qca8k_split_addr(reg, &r1, &r2, &page);
mutex_lock_nested(&priv->bus->mdio_lock, MDIO_MUTEX_NESTED);
qca8k_set_page(priv->bus, page);
val = qca8k_mii_read32(priv->bus, 0x10 | r2, r1);
mutex_unlock(&priv->bus->mdio_lock);
return val;
}
static void
qca8k_write(struct qca8k_priv *priv, u32 reg, u32 val)
{
u16 r1, r2, page;
qca8k_split_addr(reg, &r1, &r2, &page);
mutex_lock_nested(&priv->bus->mdio_lock, MDIO_MUTEX_NESTED);
qca8k_set_page(priv->bus, page);
qca8k_mii_write32(priv->bus, 0x10 | r2, r1, val);
mutex_unlock(&priv->bus->mdio_lock);
}
static u32
qca8k_rmw(struct qca8k_priv *priv, u32 reg, u32 mask, u32 val)
{
u16 r1, r2, page;
u32 ret;
qca8k_split_addr(reg, &r1, &r2, &page);
mutex_lock_nested(&priv->bus->mdio_lock, MDIO_MUTEX_NESTED);
qca8k_set_page(priv->bus, page);
ret = qca8k_mii_read32(priv->bus, 0x10 | r2, r1);
ret &= ~mask;
ret |= val;
qca8k_mii_write32(priv->bus, 0x10 | r2, r1, ret);
mutex_unlock(&priv->bus->mdio_lock);
return ret;
}
static void
qca8k_reg_set(struct qca8k_priv *priv, u32 reg, u32 val)
{
qca8k_rmw(priv, reg, 0, val);
}
static void
qca8k_reg_clear(struct qca8k_priv *priv, u32 reg, u32 val)
{
qca8k_rmw(priv, reg, val, 0);
}
static int
qca8k_regmap_read(void *ctx, uint32_t reg, uint32_t *val)
{
struct qca8k_priv *priv = (struct qca8k_priv *)ctx;
*val = qca8k_read(priv, reg);
return 0;
}
static int
qca8k_regmap_write(void *ctx, uint32_t reg, uint32_t val)
{
struct qca8k_priv *priv = (struct qca8k_priv *)ctx;
qca8k_write(priv, reg, val);
return 0;
}
static int
qca8k_busy_wait(struct qca8k_priv *priv, u32 reg, u32 mask)
{
unsigned long timeout;
timeout = jiffies + msecs_to_jiffies(20);
do {
u32 val = qca8k_read(priv, reg);
int busy = val & mask;
if (!busy)
break;
cond_resched();
} while (!time_after_eq(jiffies, timeout));
return time_after_eq(jiffies, timeout);
}
static void
qca8k_fdb_read(struct qca8k_priv *priv, struct qca8k_fdb *fdb)
{
u32 reg[4];
int i;
for (i = 0; i < 4; i++)
reg[i] = qca8k_read(priv, QCA8K_REG_ATU_DATA0 + (i * 4));
fdb->vid = (reg[2] >> QCA8K_ATU_VID_S) & QCA8K_ATU_VID_M;
fdb->aging = reg[2] & QCA8K_ATU_STATUS_M;
fdb->port_mask = (reg[1] >> QCA8K_ATU_PORT_S) & QCA8K_ATU_PORT_M;
fdb->mac[0] = (reg[1] >> QCA8K_ATU_ADDR0_S) & 0xff;
fdb->mac[1] = reg[1] & 0xff;
fdb->mac[2] = (reg[0] >> QCA8K_ATU_ADDR2_S) & 0xff;
fdb->mac[3] = (reg[0] >> QCA8K_ATU_ADDR3_S) & 0xff;
fdb->mac[4] = (reg[0] >> QCA8K_ATU_ADDR4_S) & 0xff;
fdb->mac[5] = reg[0] & 0xff;
}
static void
qca8k_fdb_write(struct qca8k_priv *priv, u16 vid, u8 port_mask, const u8 *mac,
u8 aging)
{
u32 reg[3] = { 0 };
int i;
reg[2] = (vid & QCA8K_ATU_VID_M) << QCA8K_ATU_VID_S;
reg[2] |= aging & QCA8K_ATU_STATUS_M;
reg[1] = (port_mask & QCA8K_ATU_PORT_M) << QCA8K_ATU_PORT_S;
reg[1] |= mac[0] << QCA8K_ATU_ADDR0_S;
reg[1] |= mac[1];
reg[0] |= mac[2] << QCA8K_ATU_ADDR2_S;
reg[0] |= mac[3] << QCA8K_ATU_ADDR3_S;
reg[0] |= mac[4] << QCA8K_ATU_ADDR4_S;
reg[0] |= mac[5];
for (i = 0; i < 3; i++)
qca8k_write(priv, QCA8K_REG_ATU_DATA0 + (i * 4), reg[i]);
}
static int
qca8k_fdb_access(struct qca8k_priv *priv, enum qca8k_fdb_cmd cmd, int port)
{
u32 reg;
reg = QCA8K_ATU_FUNC_BUSY;
reg |= cmd;
if (port >= 0) {
reg |= QCA8K_ATU_FUNC_PORT_EN;
reg |= (port & QCA8K_ATU_FUNC_PORT_M) << QCA8K_ATU_FUNC_PORT_S;
}
qca8k_write(priv, QCA8K_REG_ATU_FUNC, reg);
if (qca8k_busy_wait(priv, QCA8K_REG_ATU_FUNC, QCA8K_ATU_FUNC_BUSY))
return -1;
if (cmd == QCA8K_FDB_LOAD) {
reg = qca8k_read(priv, QCA8K_REG_ATU_FUNC);
if (reg & QCA8K_ATU_FUNC_FULL)
return -1;
}
return 0;
}
static int
qca8k_fdb_next(struct qca8k_priv *priv, struct qca8k_fdb *fdb, int port)
{
int ret;
qca8k_fdb_write(priv, fdb->vid, fdb->port_mask, fdb->mac, fdb->aging);
ret = qca8k_fdb_access(priv, QCA8K_FDB_NEXT, port);
if (ret >= 0)
qca8k_fdb_read(priv, fdb);
return ret;
}
static int
qca8k_fdb_add(struct qca8k_priv *priv, const u8 *mac, u16 port_mask,
u16 vid, u8 aging)
{
int ret;
mutex_lock(&priv->reg_mutex);
qca8k_fdb_write(priv, vid, port_mask, mac, aging);
ret = qca8k_fdb_access(priv, QCA8K_FDB_LOAD, -1);
mutex_unlock(&priv->reg_mutex);
return ret;
}
static int
qca8k_fdb_del(struct qca8k_priv *priv, const u8 *mac, u16 port_mask, u16 vid)
{
int ret;
mutex_lock(&priv->reg_mutex);
qca8k_fdb_write(priv, vid, port_mask, mac, 0);
ret = qca8k_fdb_access(priv, QCA8K_FDB_PURGE, -1);
mutex_unlock(&priv->reg_mutex);
return ret;
}
static void
qca8k_fdb_flush(struct qca8k_priv *priv)
{
mutex_lock(&priv->reg_mutex);
qca8k_fdb_access(priv, QCA8K_FDB_FLUSH, -1);
mutex_unlock(&priv->reg_mutex);
}
static void
qca8k_mib_init(struct qca8k_priv *priv)
{
mutex_lock(&priv->reg_mutex);
qca8k_reg_set(priv, QCA8K_REG_MIB, QCA8K_MIB_FLUSH | QCA8K_MIB_BUSY);
qca8k_busy_wait(priv, QCA8K_REG_MIB, QCA8K_MIB_BUSY);
qca8k_reg_set(priv, QCA8K_REG_MIB, QCA8K_MIB_CPU_KEEP);
qca8k_write(priv, QCA8K_REG_MODULE_EN, QCA8K_MODULE_EN_MIB);
mutex_unlock(&priv->reg_mutex);
}
static int
qca8k_set_pad_ctrl(struct qca8k_priv *priv, int port, int mode)
{
u32 reg;
switch (port) {
case 0:
reg = QCA8K_REG_PORT0_PAD_CTRL;
break;
case 6:
reg = QCA8K_REG_PORT6_PAD_CTRL;
break;
default:
pr_err("Can't set PAD_CTRL on port %d\n", port);
return -EINVAL;
}
switch (mode) {
case PHY_INTERFACE_MODE_RGMII:
qca8k_write(priv, reg,
QCA8K_PORT_PAD_RGMII_EN |
QCA8K_PORT_PAD_RGMII_TX_DELAY(3) |
QCA8K_PORT_PAD_RGMII_RX_DELAY(3));
qca8k_write(priv, QCA8K_REG_PORT5_PAD_CTRL,
QCA8K_PORT_PAD_RGMII_RX_DELAY_EN);
break;
case PHY_INTERFACE_MODE_SGMII:
qca8k_write(priv, reg, QCA8K_PORT_PAD_SGMII_EN);
break;
default:
pr_err("xMII mode %d not supported\n", mode);
return -EINVAL;
}
return 0;
}
static void
qca8k_port_set_status(struct qca8k_priv *priv, int port, int enable)
{
u32 mask = QCA8K_PORT_STATUS_TXMAC;
if ((port > 0) && (port < 6))
mask |= QCA8K_PORT_STATUS_LINK_AUTO;
if (enable)
qca8k_reg_set(priv, QCA8K_REG_PORT_STATUS(port), mask);
else
qca8k_reg_clear(priv, QCA8K_REG_PORT_STATUS(port), mask);
}
static int
qca8k_setup(struct dsa_switch *ds)
{
struct qca8k_priv *priv = (struct qca8k_priv *)ds->priv;
int ret, i, phy_mode = -1;
if (!dsa_is_cpu_port(ds, 0)) {
pr_err("port 0 is not the CPU port\n");
return -EINVAL;
}
mutex_init(&priv->reg_mutex);
priv->regmap = devm_regmap_init(ds->dev, NULL, priv,
&qca8k_regmap_config);
if (IS_ERR(priv->regmap))
pr_warn("regmap initialization failed");
phy_mode = of_get_phy_mode(ds->dst->cpu_dp->dn);
if (phy_mode < 0) {
pr_err("Can't find phy-mode for master device\n");
return phy_mode;
}
ret = qca8k_set_pad_ctrl(priv, QCA8K_CPU_PORT, phy_mode);
if (ret < 0)
return ret;
qca8k_reg_set(priv, QCA8K_REG_GLOBAL_FW_CTRL0,
QCA8K_GLOBAL_FW_CTRL0_CPU_PORT_EN);
qca8k_port_set_status(priv, QCA8K_CPU_PORT, 1);
priv->port_sts[QCA8K_CPU_PORT].enabled = 1;
qca8k_mib_init(priv);
qca8k_write(priv, QCA8K_REG_PORT_HDR_CTRL(QCA8K_CPU_PORT),
QCA8K_PORT_HDR_CTRL_ALL << QCA8K_PORT_HDR_CTRL_TX_S |
QCA8K_PORT_HDR_CTRL_ALL << QCA8K_PORT_HDR_CTRL_RX_S);
for (i = 0; i < QCA8K_NUM_PORTS; i++)
qca8k_rmw(priv, QCA8K_PORT_LOOKUP_CTRL(i),
QCA8K_PORT_LOOKUP_MEMBER, 0);
for (i = 1; i < QCA8K_NUM_PORTS; i++)
if (ds->enabled_port_mask & BIT(i))
qca8k_port_set_status(priv, i, 0);
qca8k_write(priv, QCA8K_REG_GLOBAL_FW_CTRL1,
BIT(0) << QCA8K_GLOBAL_FW_CTRL1_IGMP_DP_S |
BIT(0) << QCA8K_GLOBAL_FW_CTRL1_BC_DP_S |
BIT(0) << QCA8K_GLOBAL_FW_CTRL1_MC_DP_S |
BIT(0) << QCA8K_GLOBAL_FW_CTRL1_UC_DP_S);
for (i = 0; i < DSA_MAX_PORTS; i++) {
if (dsa_is_cpu_port(ds, i)) {
qca8k_rmw(priv, QCA8K_PORT_LOOKUP_CTRL(QCA8K_CPU_PORT),
QCA8K_PORT_LOOKUP_MEMBER,
ds->enabled_port_mask);
}
if (ds->enabled_port_mask & BIT(i)) {
int shift = 16 * (i % 2);
qca8k_rmw(priv, QCA8K_PORT_LOOKUP_CTRL(i),
QCA8K_PORT_LOOKUP_MEMBER,
BIT(QCA8K_CPU_PORT));
qca8k_reg_set(priv, QCA8K_PORT_LOOKUP_CTRL(i),
QCA8K_PORT_LOOKUP_LEARN);
qca8k_rmw(priv, QCA8K_EGRESS_VLAN(i),
0xffff << shift, 1 << shift);
qca8k_write(priv, QCA8K_REG_PORT_VLAN_CTRL0(i),
QCA8K_PORT_VLAN_CVID(1) |
QCA8K_PORT_VLAN_SVID(1));
}
}
qca8k_fdb_flush(priv);
return 0;
}
static int
qca8k_phy_read(struct dsa_switch *ds, int phy, int regnum)
{
struct qca8k_priv *priv = (struct qca8k_priv *)ds->priv;
return mdiobus_read(priv->bus, phy, regnum);
}
static int
qca8k_phy_write(struct dsa_switch *ds, int phy, int regnum, u16 val)
{
struct qca8k_priv *priv = (struct qca8k_priv *)ds->priv;
return mdiobus_write(priv->bus, phy, regnum, val);
}
static void
qca8k_get_strings(struct dsa_switch *ds, int port, uint8_t *data)
{
int i;
for (i = 0; i < ARRAY_SIZE(ar8327_mib); i++)
strncpy(data + i * ETH_GSTRING_LEN, ar8327_mib[i].name,
ETH_GSTRING_LEN);
}
static void
qca8k_get_ethtool_stats(struct dsa_switch *ds, int port,
uint64_t *data)
{
struct qca8k_priv *priv = (struct qca8k_priv *)ds->priv;
const struct qca8k_mib_desc *mib;
u32 reg, i;
u64 hi;
for (i = 0; i < ARRAY_SIZE(ar8327_mib); i++) {
mib = &ar8327_mib[i];
reg = QCA8K_PORT_MIB_COUNTER(port) + mib->offset;
data[i] = qca8k_read(priv, reg);
if (mib->size == 2) {
hi = qca8k_read(priv, reg + 4);
data[i] |= hi << 32;
}
}
}
static int
qca8k_get_sset_count(struct dsa_switch *ds)
{
return ARRAY_SIZE(ar8327_mib);
}
static void
qca8k_eee_enable_set(struct dsa_switch *ds, int port, bool enable)
{
struct qca8k_priv *priv = (struct qca8k_priv *)ds->priv;
u32 lpi_en = QCA8K_REG_EEE_CTRL_LPI_EN(port);
u32 reg;
mutex_lock(&priv->reg_mutex);
reg = qca8k_read(priv, QCA8K_REG_EEE_CTRL);
if (enable)
reg |= lpi_en;
else
reg &= ~lpi_en;
qca8k_write(priv, QCA8K_REG_EEE_CTRL, reg);
mutex_unlock(&priv->reg_mutex);
}
static int
qca8k_eee_init(struct dsa_switch *ds, int port,
struct phy_device *phy)
{
struct qca8k_priv *priv = (struct qca8k_priv *)ds->priv;
struct ethtool_eee *p = &priv->port_sts[port].eee;
int ret;
p->supported = (SUPPORTED_1000baseT_Full | SUPPORTED_100baseT_Full);
ret = phy_init_eee(phy, 0);
if (ret)
return ret;
qca8k_eee_enable_set(ds, port, true);
return 0;
}
static int
qca8k_set_eee(struct dsa_switch *ds, int port,
struct phy_device *phydev,
struct ethtool_eee *e)
{
struct qca8k_priv *priv = (struct qca8k_priv *)ds->priv;
struct ethtool_eee *p = &priv->port_sts[port].eee;
int ret = 0;
p->eee_enabled = e->eee_enabled;
if (e->eee_enabled) {
p->eee_enabled = qca8k_eee_init(ds, port, phydev);
if (!p->eee_enabled)
ret = -EOPNOTSUPP;
}
qca8k_eee_enable_set(ds, port, p->eee_enabled);
return ret;
}
static int
qca8k_get_eee(struct dsa_switch *ds, int port,
struct ethtool_eee *e)
{
struct qca8k_priv *priv = (struct qca8k_priv *)ds->priv;
struct ethtool_eee *p = &priv->port_sts[port].eee;
struct net_device *netdev = ds->ports[port].netdev;
int ret;
ret = phy_ethtool_get_eee(netdev->phydev, p);
if (!ret)
e->eee_active =
!!(p->supported & p->advertised & p->lp_advertised);
else
e->eee_active = 0;
e->eee_enabled = p->eee_enabled;
return ret;
}
static void
qca8k_port_stp_state_set(struct dsa_switch *ds, int port, u8 state)
{
struct qca8k_priv *priv = (struct qca8k_priv *)ds->priv;
u32 stp_state;
switch (state) {
case BR_STATE_DISABLED:
stp_state = QCA8K_PORT_LOOKUP_STATE_DISABLED;
break;
case BR_STATE_BLOCKING:
stp_state = QCA8K_PORT_LOOKUP_STATE_BLOCKING;
break;
case BR_STATE_LISTENING:
stp_state = QCA8K_PORT_LOOKUP_STATE_LISTENING;
break;
case BR_STATE_LEARNING:
stp_state = QCA8K_PORT_LOOKUP_STATE_LEARNING;
break;
case BR_STATE_FORWARDING:
default:
stp_state = QCA8K_PORT_LOOKUP_STATE_FORWARD;
break;
}
qca8k_rmw(priv, QCA8K_PORT_LOOKUP_CTRL(port),
QCA8K_PORT_LOOKUP_STATE_MASK, stp_state);
}
static int
qca8k_port_bridge_join(struct dsa_switch *ds, int port, struct net_device *br)
{
struct qca8k_priv *priv = (struct qca8k_priv *)ds->priv;
int port_mask = BIT(QCA8K_CPU_PORT);
int i;
for (i = 1; i < QCA8K_NUM_PORTS; i++) {
if (ds->ports[i].bridge_dev != br)
continue;
qca8k_reg_set(priv,
QCA8K_PORT_LOOKUP_CTRL(i),
BIT(port));
if (i != port)
port_mask |= BIT(i);
}
qca8k_rmw(priv, QCA8K_PORT_LOOKUP_CTRL(port),
QCA8K_PORT_LOOKUP_MEMBER, port_mask);
return 0;
}
static void
qca8k_port_bridge_leave(struct dsa_switch *ds, int port, struct net_device *br)
{
struct qca8k_priv *priv = (struct qca8k_priv *)ds->priv;
int i;
for (i = 1; i < QCA8K_NUM_PORTS; i++) {
if (ds->ports[i].bridge_dev != br)
continue;
qca8k_reg_clear(priv,
QCA8K_PORT_LOOKUP_CTRL(i),
BIT(port));
}
qca8k_rmw(priv, QCA8K_PORT_LOOKUP_CTRL(port),
QCA8K_PORT_LOOKUP_MEMBER, BIT(QCA8K_CPU_PORT));
}
static int
qca8k_port_enable(struct dsa_switch *ds, int port,
struct phy_device *phy)
{
struct qca8k_priv *priv = (struct qca8k_priv *)ds->priv;
qca8k_port_set_status(priv, port, 1);
priv->port_sts[port].enabled = 1;
return 0;
}
static void
qca8k_port_disable(struct dsa_switch *ds, int port,
struct phy_device *phy)
{
struct qca8k_priv *priv = (struct qca8k_priv *)ds->priv;
qca8k_port_set_status(priv, port, 0);
priv->port_sts[port].enabled = 0;
}
static int
qca8k_port_fdb_insert(struct qca8k_priv *priv, const u8 *addr,
u16 port_mask, u16 vid)
{
if (!vid)
vid = 1;
return qca8k_fdb_add(priv, addr, port_mask, vid,
QCA8K_ATU_STATUS_STATIC);
}
static int
qca8k_port_fdb_prepare(struct dsa_switch *ds, int port,
const struct switchdev_obj_port_fdb *fdb,
struct switchdev_trans *trans)
{
struct qca8k_priv *priv = (struct qca8k_priv *)ds->priv;
return qca8k_port_fdb_insert(priv, fdb->addr, 0, fdb->vid);
}
static void
qca8k_port_fdb_add(struct dsa_switch *ds, int port,
const struct switchdev_obj_port_fdb *fdb,
struct switchdev_trans *trans)
{
struct qca8k_priv *priv = (struct qca8k_priv *)ds->priv;
u16 port_mask = BIT(port);
qca8k_port_fdb_insert(priv, fdb->addr, port_mask, fdb->vid);
}
static int
qca8k_port_fdb_del(struct dsa_switch *ds, int port,
const struct switchdev_obj_port_fdb *fdb)
{
struct qca8k_priv *priv = (struct qca8k_priv *)ds->priv;
u16 port_mask = BIT(port);
u16 vid = fdb->vid;
if (!vid)
vid = 1;
return qca8k_fdb_del(priv, fdb->addr, port_mask, vid);
}
static int
qca8k_port_fdb_dump(struct dsa_switch *ds, int port,
struct switchdev_obj_port_fdb *fdb,
switchdev_obj_dump_cb_t *cb)
{
struct qca8k_priv *priv = (struct qca8k_priv *)ds->priv;
struct qca8k_fdb _fdb = { 0 };
int cnt = QCA8K_NUM_FDB_RECORDS;
int ret = 0;
mutex_lock(&priv->reg_mutex);
while (cnt-- && !qca8k_fdb_next(priv, &_fdb, port)) {
if (!_fdb.aging)
break;
ether_addr_copy(fdb->addr, _fdb.mac);
fdb->vid = _fdb.vid;
if (_fdb.aging == QCA8K_ATU_STATUS_STATIC)
fdb->ndm_state = NUD_NOARP;
else
fdb->ndm_state = NUD_REACHABLE;
ret = cb(&fdb->obj);
if (ret)
break;
}
mutex_unlock(&priv->reg_mutex);
return 0;
}
static enum dsa_tag_protocol
qca8k_get_tag_protocol(struct dsa_switch *ds)
{
return DSA_TAG_PROTO_QCA;
}
static int
qca8k_sw_probe(struct mdio_device *mdiodev)
{
struct qca8k_priv *priv;
u32 id;
priv = devm_kzalloc(&mdiodev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->bus = mdiodev->bus;
id = qca8k_read(priv, QCA8K_REG_MASK_CTRL);
id >>= QCA8K_MASK_CTRL_ID_S;
id &= QCA8K_MASK_CTRL_ID_M;
if (id != QCA8K_ID_QCA8337)
return -ENODEV;
priv->ds = dsa_switch_alloc(&mdiodev->dev, DSA_MAX_PORTS);
if (!priv->ds)
return -ENOMEM;
priv->ds->priv = priv;
priv->ds->ops = &qca8k_switch_ops;
mutex_init(&priv->reg_mutex);
dev_set_drvdata(&mdiodev->dev, priv);
return dsa_register_switch(priv->ds);
}
static void
qca8k_sw_remove(struct mdio_device *mdiodev)
{
struct qca8k_priv *priv = dev_get_drvdata(&mdiodev->dev);
int i;
for (i = 0; i < QCA8K_NUM_PORTS; i++)
qca8k_port_set_status(priv, i, 0);
dsa_unregister_switch(priv->ds);
}
static void
qca8k_set_pm(struct qca8k_priv *priv, int enable)
{
int i;
for (i = 0; i < QCA8K_NUM_PORTS; i++) {
if (!priv->port_sts[i].enabled)
continue;
qca8k_port_set_status(priv, i, enable);
}
}
static int qca8k_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct qca8k_priv *priv = platform_get_drvdata(pdev);
qca8k_set_pm(priv, 0);
return dsa_switch_suspend(priv->ds);
}
static int qca8k_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct qca8k_priv *priv = platform_get_drvdata(pdev);
qca8k_set_pm(priv, 1);
return dsa_switch_resume(priv->ds);
}
