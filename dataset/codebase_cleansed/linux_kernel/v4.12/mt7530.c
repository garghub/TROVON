static int
mt7623_trgmii_write(struct mt7530_priv *priv, u32 reg, u32 val)
{
int ret;
ret = regmap_write(priv->ethernet, TRGMII_BASE(reg), val);
if (ret < 0)
dev_err(priv->dev,
"failed to priv write register\n");
return ret;
}
static u32
mt7623_trgmii_read(struct mt7530_priv *priv, u32 reg)
{
int ret;
u32 val;
ret = regmap_read(priv->ethernet, TRGMII_BASE(reg), &val);
if (ret < 0) {
dev_err(priv->dev,
"failed to priv read register\n");
return ret;
}
return val;
}
static void
mt7623_trgmii_rmw(struct mt7530_priv *priv, u32 reg,
u32 mask, u32 set)
{
u32 val;
val = mt7623_trgmii_read(priv, reg);
val &= ~mask;
val |= set;
mt7623_trgmii_write(priv, reg, val);
}
static void
mt7623_trgmii_set(struct mt7530_priv *priv, u32 reg, u32 val)
{
mt7623_trgmii_rmw(priv, reg, 0, val);
}
static void
mt7623_trgmii_clear(struct mt7530_priv *priv, u32 reg, u32 val)
{
mt7623_trgmii_rmw(priv, reg, val, 0);
}
static int
core_read_mmd_indirect(struct mt7530_priv *priv, int prtad, int devad)
{
struct mii_bus *bus = priv->bus;
int value, ret;
ret = bus->write(bus, 0, MII_MMD_CTRL, devad);
if (ret < 0)
goto err;
ret = bus->write(bus, 0, MII_MMD_DATA, prtad);
if (ret < 0)
goto err;
ret = bus->write(bus, 0, MII_MMD_CTRL, (devad | MII_MMD_CTRL_NOINCR));
if (ret < 0)
goto err;
value = bus->read(bus, 0, MII_MMD_DATA);
return value;
err:
dev_err(&bus->dev, "failed to read mmd register\n");
return ret;
}
static int
core_write_mmd_indirect(struct mt7530_priv *priv, int prtad,
int devad, u32 data)
{
struct mii_bus *bus = priv->bus;
int ret;
ret = bus->write(bus, 0, MII_MMD_CTRL, devad);
if (ret < 0)
goto err;
ret = bus->write(bus, 0, MII_MMD_DATA, prtad);
if (ret < 0)
goto err;
ret = bus->write(bus, 0, MII_MMD_CTRL, (devad | MII_MMD_CTRL_NOINCR));
if (ret < 0)
goto err;
ret = bus->write(bus, 0, MII_MMD_DATA, data);
err:
if (ret < 0)
dev_err(&bus->dev,
"failed to write mmd register\n");
return ret;
}
static void
core_write(struct mt7530_priv *priv, u32 reg, u32 val)
{
struct mii_bus *bus = priv->bus;
mutex_lock_nested(&bus->mdio_lock, MDIO_MUTEX_NESTED);
core_write_mmd_indirect(priv, reg, MDIO_MMD_VEND2, val);
mutex_unlock(&bus->mdio_lock);
}
static void
core_rmw(struct mt7530_priv *priv, u32 reg, u32 mask, u32 set)
{
struct mii_bus *bus = priv->bus;
u32 val;
mutex_lock_nested(&bus->mdio_lock, MDIO_MUTEX_NESTED);
val = core_read_mmd_indirect(priv, reg, MDIO_MMD_VEND2);
val &= ~mask;
val |= set;
core_write_mmd_indirect(priv, reg, MDIO_MMD_VEND2, val);
mutex_unlock(&bus->mdio_lock);
}
static void
core_set(struct mt7530_priv *priv, u32 reg, u32 val)
{
core_rmw(priv, reg, 0, val);
}
static void
core_clear(struct mt7530_priv *priv, u32 reg, u32 val)
{
core_rmw(priv, reg, val, 0);
}
static int
mt7530_mii_write(struct mt7530_priv *priv, u32 reg, u32 val)
{
struct mii_bus *bus = priv->bus;
u16 page, r, lo, hi;
int ret;
page = (reg >> 6) & 0x3ff;
r = (reg >> 2) & 0xf;
lo = val & 0xffff;
hi = val >> 16;
ret = bus->write(bus, 0x1f, 0x1f, page);
if (ret < 0)
goto err;
ret = bus->write(bus, 0x1f, r, lo);
if (ret < 0)
goto err;
ret = bus->write(bus, 0x1f, 0x10, hi);
err:
if (ret < 0)
dev_err(&bus->dev,
"failed to write mt7530 register\n");
return ret;
}
static u32
mt7530_mii_read(struct mt7530_priv *priv, u32 reg)
{
struct mii_bus *bus = priv->bus;
u16 page, r, lo, hi;
int ret;
page = (reg >> 6) & 0x3ff;
r = (reg >> 2) & 0xf;
ret = bus->write(bus, 0x1f, 0x1f, page);
if (ret < 0) {
dev_err(&bus->dev,
"failed to read mt7530 register\n");
return ret;
}
lo = bus->read(bus, 0x1f, r);
hi = bus->read(bus, 0x1f, 0x10);
return (hi << 16) | (lo & 0xffff);
}
static void
mt7530_write(struct mt7530_priv *priv, u32 reg, u32 val)
{
struct mii_bus *bus = priv->bus;
mutex_lock_nested(&bus->mdio_lock, MDIO_MUTEX_NESTED);
mt7530_mii_write(priv, reg, val);
mutex_unlock(&bus->mdio_lock);
}
static u32
_mt7530_read(struct mt7530_dummy_poll *p)
{
struct mii_bus *bus = p->priv->bus;
u32 val;
mutex_lock_nested(&bus->mdio_lock, MDIO_MUTEX_NESTED);
val = mt7530_mii_read(p->priv, p->reg);
mutex_unlock(&bus->mdio_lock);
return val;
}
static u32
mt7530_read(struct mt7530_priv *priv, u32 reg)
{
struct mt7530_dummy_poll p;
INIT_MT7530_DUMMY_POLL(&p, priv, reg);
return _mt7530_read(&p);
}
static void
mt7530_rmw(struct mt7530_priv *priv, u32 reg,
u32 mask, u32 set)
{
struct mii_bus *bus = priv->bus;
u32 val;
mutex_lock_nested(&bus->mdio_lock, MDIO_MUTEX_NESTED);
val = mt7530_mii_read(priv, reg);
val &= ~mask;
val |= set;
mt7530_mii_write(priv, reg, val);
mutex_unlock(&bus->mdio_lock);
}
static void
mt7530_set(struct mt7530_priv *priv, u32 reg, u32 val)
{
mt7530_rmw(priv, reg, 0, val);
}
static void
mt7530_clear(struct mt7530_priv *priv, u32 reg, u32 val)
{
mt7530_rmw(priv, reg, val, 0);
}
static int
mt7530_fdb_cmd(struct mt7530_priv *priv, enum mt7530_fdb_cmd cmd, u32 *rsp)
{
u32 val;
int ret;
struct mt7530_dummy_poll p;
val = ATC_BUSY | ATC_MAT(0) | cmd;
mt7530_write(priv, MT7530_ATC, val);
INIT_MT7530_DUMMY_POLL(&p, priv, MT7530_ATC);
ret = readx_poll_timeout(_mt7530_read, &p, val,
!(val & ATC_BUSY), 20, 20000);
if (ret < 0) {
dev_err(priv->dev, "reset timeout\n");
return ret;
}
val = mt7530_read(priv, MT7530_ATC);
if ((cmd == MT7530_FDB_READ) && (val & ATC_INVALID))
return -EINVAL;
if (rsp)
*rsp = val;
return 0;
}
static void
mt7530_fdb_read(struct mt7530_priv *priv, struct mt7530_fdb *fdb)
{
u32 reg[3];
int i;
for (i = 0; i < 3; i++) {
reg[i] = mt7530_read(priv, MT7530_TSRA1 + (i * 4));
dev_dbg(priv->dev, "%s(%d) reg[%d]=0x%x\n",
__func__, __LINE__, i, reg[i]);
}
fdb->vid = (reg[1] >> CVID) & CVID_MASK;
fdb->aging = (reg[2] >> AGE_TIMER) & AGE_TIMER_MASK;
fdb->port_mask = (reg[2] >> PORT_MAP) & PORT_MAP_MASK;
fdb->mac[0] = (reg[0] >> MAC_BYTE_0) & MAC_BYTE_MASK;
fdb->mac[1] = (reg[0] >> MAC_BYTE_1) & MAC_BYTE_MASK;
fdb->mac[2] = (reg[0] >> MAC_BYTE_2) & MAC_BYTE_MASK;
fdb->mac[3] = (reg[0] >> MAC_BYTE_3) & MAC_BYTE_MASK;
fdb->mac[4] = (reg[1] >> MAC_BYTE_4) & MAC_BYTE_MASK;
fdb->mac[5] = (reg[1] >> MAC_BYTE_5) & MAC_BYTE_MASK;
fdb->noarp = ((reg[2] >> ENT_STATUS) & ENT_STATUS_MASK) == STATIC_ENT;
}
static void
mt7530_fdb_write(struct mt7530_priv *priv, u16 vid,
u8 port_mask, const u8 *mac,
u8 aging, u8 type)
{
u32 reg[3] = { 0 };
int i;
reg[1] |= vid & CVID_MASK;
reg[2] |= (aging & AGE_TIMER_MASK) << AGE_TIMER;
reg[2] |= (port_mask & PORT_MAP_MASK) << PORT_MAP;
reg[2] |= (type & ENT_STATUS_MASK) << ENT_STATUS;
reg[1] |= mac[5] << MAC_BYTE_5;
reg[1] |= mac[4] << MAC_BYTE_4;
reg[0] |= mac[3] << MAC_BYTE_3;
reg[0] |= mac[2] << MAC_BYTE_2;
reg[0] |= mac[1] << MAC_BYTE_1;
reg[0] |= mac[0] << MAC_BYTE_0;
for (i = 0; i < 3; i++)
mt7530_write(priv, MT7530_ATA1 + (i * 4), reg[i]);
}
static int
mt7530_pad_clk_setup(struct dsa_switch *ds, int mode)
{
struct mt7530_priv *priv = ds->priv;
u32 ncpo1, ssc_delta, trgint, i;
switch (mode) {
case PHY_INTERFACE_MODE_RGMII:
trgint = 0;
ncpo1 = 0x0c80;
ssc_delta = 0x87;
break;
case PHY_INTERFACE_MODE_TRGMII:
trgint = 1;
ncpo1 = 0x1400;
ssc_delta = 0x57;
break;
default:
dev_err(priv->dev, "xMII mode %d not supported\n", mode);
return -EINVAL;
}
mt7530_rmw(priv, MT7530_P6ECR, P6_INTF_MODE_MASK,
P6_INTF_MODE(trgint));
for (i = 0 ; i < NUM_TRGMII_CTRL ; i++)
mt7530_write(priv, MT7530_TRGMII_TD_ODT(i),
TD_DM_DRVP(8) | TD_DM_DRVN(8));
if (!trgint) {
core_clear(priv, CORE_TRGMII_GSW_CLK_CG, REG_GSWCK_EN);
core_write_mmd_indirect(priv,
CORE_GSWPLL_GRP1,
MDIO_MMD_VEND2,
0);
core_write(priv, CORE_GSWPLL_GRP2,
RG_GSWPLL_POSDIV_500M(1) |
RG_GSWPLL_FBKDIV_500M(25));
core_write(priv, CORE_GSWPLL_GRP1,
RG_GSWPLL_EN_PRE |
RG_GSWPLL_POSDIV_200M(2) |
RG_GSWPLL_FBKDIV_200M(32));
core_set(priv, CORE_TRGMII_GSW_CLK_CG, REG_GSWCK_EN);
}
core_set(priv, CORE_TRGMII_GSW_CLK_CG, REG_GSWCK_EN);
core_write(priv, CORE_PLL_GROUP5, RG_LCDDS_PCW_NCPO1(ncpo1));
core_write(priv, CORE_PLL_GROUP6, RG_LCDDS_PCW_NCPO0(0));
core_write(priv, CORE_PLL_GROUP10, RG_LCDDS_SSC_DELTA(ssc_delta));
core_write(priv, CORE_PLL_GROUP11, RG_LCDDS_SSC_DELTA1(ssc_delta));
core_write(priv, CORE_PLL_GROUP4,
RG_SYSPLL_DDSFBK_EN | RG_SYSPLL_BIAS_EN |
RG_SYSPLL_BIAS_LPF_EN);
core_write(priv, CORE_PLL_GROUP2,
RG_SYSPLL_EN_NORMAL | RG_SYSPLL_VODEN |
RG_SYSPLL_POSDIV(1));
core_write(priv, CORE_PLL_GROUP7,
RG_LCDDS_PCW_NCPO_CHG | RG_LCCDS_C(3) |
RG_LCDDS_PWDB | RG_LCDDS_ISO_EN);
core_set(priv, CORE_TRGMII_GSW_CLK_CG,
REG_GSWCK_EN | REG_TRGMIICK_EN);
if (!trgint)
for (i = 0 ; i < NUM_TRGMII_CTRL; i++)
mt7530_rmw(priv, MT7530_TRGMII_RD(i),
RD_TAP_MASK, RD_TAP(16));
else
mt7623_trgmii_set(priv, GSW_INTF_MODE, INTF_MODE_TRGMII);
return 0;
}
static int
mt7623_pad_clk_setup(struct dsa_switch *ds)
{
struct mt7530_priv *priv = ds->priv;
int i;
for (i = 0 ; i < NUM_TRGMII_CTRL; i++)
mt7623_trgmii_write(priv, GSW_TRGMII_TD_ODT(i),
TD_DM_DRVP(8) | TD_DM_DRVN(8));
mt7623_trgmii_set(priv, GSW_TRGMII_RCK_CTRL, RX_RST | RXC_DQSISEL);
mt7623_trgmii_clear(priv, GSW_TRGMII_RCK_CTRL, RX_RST);
return 0;
}
static void
mt7530_mib_reset(struct dsa_switch *ds)
{
struct mt7530_priv *priv = ds->priv;
mt7530_write(priv, MT7530_MIB_CCR, CCR_MIB_FLUSH);
mt7530_write(priv, MT7530_MIB_CCR, CCR_MIB_ACTIVATE);
}
static void
mt7530_port_set_status(struct mt7530_priv *priv, int port, int enable)
{
u32 mask = PMCR_TX_EN | PMCR_RX_EN;
if (enable)
mt7530_set(priv, MT7530_PMCR_P(port), mask);
else
mt7530_clear(priv, MT7530_PMCR_P(port), mask);
}
static int mt7530_phy_read(struct dsa_switch *ds, int port, int regnum)
{
struct mt7530_priv *priv = ds->priv;
return mdiobus_read_nested(priv->bus, port, regnum);
}
int mt7530_phy_write(struct dsa_switch *ds, int port, int regnum, u16 val)
{
struct mt7530_priv *priv = ds->priv;
return mdiobus_write_nested(priv->bus, port, regnum, val);
}
static void
mt7530_get_strings(struct dsa_switch *ds, int port, uint8_t *data)
{
int i;
for (i = 0; i < ARRAY_SIZE(mt7530_mib); i++)
strncpy(data + i * ETH_GSTRING_LEN, mt7530_mib[i].name,
ETH_GSTRING_LEN);
}
static void
mt7530_get_ethtool_stats(struct dsa_switch *ds, int port,
uint64_t *data)
{
struct mt7530_priv *priv = ds->priv;
const struct mt7530_mib_desc *mib;
u32 reg, i;
u64 hi;
for (i = 0; i < ARRAY_SIZE(mt7530_mib); i++) {
mib = &mt7530_mib[i];
reg = MT7530_PORT_MIB_COUNTER(port) + mib->offset;
data[i] = mt7530_read(priv, reg);
if (mib->size == 2) {
hi = mt7530_read(priv, reg + 4);
data[i] |= hi << 32;
}
}
}
static int
mt7530_get_sset_count(struct dsa_switch *ds)
{
return ARRAY_SIZE(mt7530_mib);
}
static void mt7530_adjust_link(struct dsa_switch *ds, int port,
struct phy_device *phydev)
{
struct mt7530_priv *priv = ds->priv;
if (phy_is_pseudo_fixed_link(phydev)) {
dev_dbg(priv->dev, "phy-mode for master device = %x\n",
phydev->interface);
mt7530_pad_clk_setup(ds, phydev->interface);
mt7623_pad_clk_setup(ds);
}
}
static int
mt7530_cpu_port_enable(struct mt7530_priv *priv,
int port)
{
mt7530_write(priv, MT7530_PVC_P(port),
PORT_SPEC_TAG);
mt7530_write(priv, MT7530_PMCR_P(port), PMCR_CPUP_LINK);
mt7530_set(priv, MT7530_PSC_P(port), SA_DIS);
mt7530_set(priv, MT7530_MFC, UNU_FFP(BIT(port)));
mt7530_write(priv, MT7530_PCR_P(port),
PCR_MATRIX(priv->ds->enabled_port_mask));
return 0;
}
static int
mt7530_port_enable(struct dsa_switch *ds, int port,
struct phy_device *phy)
{
struct mt7530_priv *priv = ds->priv;
mutex_lock(&priv->reg_mutex);
mt7530_write(priv, MT7530_PMCR_P(port), PMCR_USERP_LINK);
priv->ports[port].pm |= PCR_MATRIX(BIT(MT7530_CPU_PORT));
priv->ports[port].enable = true;
mt7530_rmw(priv, MT7530_PCR_P(port), PCR_MATRIX_MASK,
priv->ports[port].pm);
mt7530_port_set_status(priv, port, 1);
mutex_unlock(&priv->reg_mutex);
return 0;
}
static void
mt7530_port_disable(struct dsa_switch *ds, int port,
struct phy_device *phy)
{
struct mt7530_priv *priv = ds->priv;
mutex_lock(&priv->reg_mutex);
priv->ports[port].enable = false;
mt7530_rmw(priv, MT7530_PCR_P(port), PCR_MATRIX_MASK,
PCR_MATRIX_CLR);
mt7530_port_set_status(priv, port, 0);
mutex_unlock(&priv->reg_mutex);
}
static void
mt7530_stp_state_set(struct dsa_switch *ds, int port, u8 state)
{
struct mt7530_priv *priv = ds->priv;
u32 stp_state;
switch (state) {
case BR_STATE_DISABLED:
stp_state = MT7530_STP_DISABLED;
break;
case BR_STATE_BLOCKING:
stp_state = MT7530_STP_BLOCKING;
break;
case BR_STATE_LISTENING:
stp_state = MT7530_STP_LISTENING;
break;
case BR_STATE_LEARNING:
stp_state = MT7530_STP_LEARNING;
break;
case BR_STATE_FORWARDING:
default:
stp_state = MT7530_STP_FORWARDING;
break;
}
mt7530_rmw(priv, MT7530_SSP_P(port), FID_PST_MASK, stp_state);
}
static int
mt7530_port_bridge_join(struct dsa_switch *ds, int port,
struct net_device *bridge)
{
struct mt7530_priv *priv = ds->priv;
u32 port_bitmap = BIT(MT7530_CPU_PORT);
int i;
mutex_lock(&priv->reg_mutex);
for (i = 0; i < MT7530_NUM_PORTS; i++) {
if (ds->enabled_port_mask & BIT(i) && i != port) {
if (ds->ports[i].bridge_dev != bridge)
continue;
if (priv->ports[i].enable)
mt7530_set(priv, MT7530_PCR_P(i),
PCR_MATRIX(BIT(port)));
priv->ports[i].pm |= PCR_MATRIX(BIT(port));
port_bitmap |= BIT(i);
}
}
if (priv->ports[port].enable)
mt7530_rmw(priv, MT7530_PCR_P(port),
PCR_MATRIX_MASK, PCR_MATRIX(port_bitmap));
priv->ports[port].pm |= PCR_MATRIX(port_bitmap);
mutex_unlock(&priv->reg_mutex);
return 0;
}
static void
mt7530_port_bridge_leave(struct dsa_switch *ds, int port,
struct net_device *bridge)
{
struct mt7530_priv *priv = ds->priv;
int i;
mutex_lock(&priv->reg_mutex);
for (i = 0; i < MT7530_NUM_PORTS; i++) {
if (ds->enabled_port_mask & BIT(i) && i != port) {
if (ds->ports[i].bridge_dev != bridge)
continue;
if (priv->ports[i].enable)
mt7530_clear(priv, MT7530_PCR_P(i),
PCR_MATRIX(BIT(port)));
priv->ports[i].pm &= ~PCR_MATRIX(BIT(port));
}
}
if (priv->ports[port].enable)
mt7530_rmw(priv, MT7530_PCR_P(port), PCR_MATRIX_MASK,
PCR_MATRIX(BIT(MT7530_CPU_PORT)));
priv->ports[port].pm = PCR_MATRIX(BIT(MT7530_CPU_PORT));
mutex_unlock(&priv->reg_mutex);
}
static int
mt7530_port_fdb_prepare(struct dsa_switch *ds, int port,
const struct switchdev_obj_port_fdb *fdb,
struct switchdev_trans *trans)
{
struct mt7530_priv *priv = ds->priv;
int ret;
mutex_lock(&priv->reg_mutex);
mt7530_fdb_write(priv, fdb->vid, 0, fdb->addr, -1, STATIC_ENT);
ret = mt7530_fdb_cmd(priv, MT7530_FDB_WRITE, 0);
mutex_unlock(&priv->reg_mutex);
return ret;
}
static void
mt7530_port_fdb_add(struct dsa_switch *ds, int port,
const struct switchdev_obj_port_fdb *fdb,
struct switchdev_trans *trans)
{
struct mt7530_priv *priv = ds->priv;
u8 port_mask = BIT(port);
mutex_lock(&priv->reg_mutex);
mt7530_fdb_write(priv, fdb->vid, port_mask, fdb->addr, -1, STATIC_ENT);
mt7530_fdb_cmd(priv, MT7530_FDB_WRITE, 0);
mutex_unlock(&priv->reg_mutex);
}
static int
mt7530_port_fdb_del(struct dsa_switch *ds, int port,
const struct switchdev_obj_port_fdb *fdb)
{
struct mt7530_priv *priv = ds->priv;
int ret;
u8 port_mask = BIT(port);
mutex_lock(&priv->reg_mutex);
mt7530_fdb_write(priv, fdb->vid, port_mask, fdb->addr, -1, STATIC_EMP);
ret = mt7530_fdb_cmd(priv, MT7530_FDB_WRITE, 0);
mutex_unlock(&priv->reg_mutex);
return ret;
}
static int
mt7530_port_fdb_dump(struct dsa_switch *ds, int port,
struct switchdev_obj_port_fdb *fdb,
int (*cb)(struct switchdev_obj *obj))
{
struct mt7530_priv *priv = ds->priv;
struct mt7530_fdb _fdb = { 0 };
int cnt = MT7530_NUM_FDB_RECORDS;
int ret = 0;
u32 rsp = 0;
mutex_lock(&priv->reg_mutex);
ret = mt7530_fdb_cmd(priv, MT7530_FDB_START, &rsp);
if (ret < 0)
goto err;
do {
if (rsp & ATC_SRCH_HIT) {
mt7530_fdb_read(priv, &_fdb);
if (_fdb.port_mask & BIT(port)) {
ether_addr_copy(fdb->addr, _fdb.mac);
fdb->vid = _fdb.vid;
fdb->ndm_state = _fdb.noarp ?
NUD_NOARP : NUD_REACHABLE;
ret = cb(&fdb->obj);
if (ret < 0)
break;
}
}
} while (--cnt &&
!(rsp & ATC_SRCH_END) &&
!mt7530_fdb_cmd(priv, MT7530_FDB_NEXT, &rsp));
err:
mutex_unlock(&priv->reg_mutex);
return 0;
}
static enum dsa_tag_protocol
mtk_get_tag_protocol(struct dsa_switch *ds)
{
struct mt7530_priv *priv = ds->priv;
if (!dsa_is_cpu_port(ds, MT7530_CPU_PORT)) {
dev_warn(priv->dev,
"port not matched with tagging CPU port\n");
return DSA_TAG_PROTO_NONE;
} else {
return DSA_TAG_PROTO_MTK;
}
}
static int
mt7530_setup(struct dsa_switch *ds)
{
struct mt7530_priv *priv = ds->priv;
int ret, i;
u32 id, val;
struct device_node *dn;
struct mt7530_dummy_poll p;
dn = ds->master_netdev->dev.of_node->parent;
priv->ethernet = syscon_node_to_regmap(dn);
if (IS_ERR(priv->ethernet))
return PTR_ERR(priv->ethernet);
regulator_set_voltage(priv->core_pwr, 1000000, 1000000);
ret = regulator_enable(priv->core_pwr);
if (ret < 0) {
dev_err(priv->dev,
"Failed to enable core power: %d\n", ret);
return ret;
}
regulator_set_voltage(priv->io_pwr, 3300000, 3300000);
ret = regulator_enable(priv->io_pwr);
if (ret < 0) {
dev_err(priv->dev, "Failed to enable io pwr: %d\n",
ret);
return ret;
}
if (priv->mcm) {
reset_control_assert(priv->rstc);
usleep_range(1000, 1100);
reset_control_deassert(priv->rstc);
} else {
gpiod_set_value_cansleep(priv->reset, 0);
usleep_range(1000, 1100);
gpiod_set_value_cansleep(priv->reset, 1);
}
INIT_MT7530_DUMMY_POLL(&p, priv, MT7530_HWTRAP);
ret = readx_poll_timeout(_mt7530_read, &p, val, val != 0,
20, 1000000);
if (ret < 0) {
dev_err(priv->dev, "reset timeout\n");
return ret;
}
id = mt7530_read(priv, MT7530_CREV);
id >>= CHIP_NAME_SHIFT;
if (id != MT7530_ID) {
dev_err(priv->dev, "chip %x can't be supported\n", id);
return -ENODEV;
}
mt7530_write(priv, MT7530_SYS_CTRL,
SYS_CTRL_PHY_RST | SYS_CTRL_SW_RST |
SYS_CTRL_REG_RST);
val = mt7530_read(priv, MT7530_MHWTRAP);
val &= ~MHWTRAP_P6_DIS & ~MHWTRAP_PHY_ACCESS;
val |= MHWTRAP_MANUAL;
mt7530_write(priv, MT7530_MHWTRAP, val);
mt7530_mib_reset(ds);
mt7530_clear(priv, MT7530_MFC, UNU_FFP_MASK);
for (i = 0; i < MT7530_NUM_PORTS; i++) {
mt7530_rmw(priv, MT7530_PCR_P(i), PCR_MATRIX_MASK,
PCR_MATRIX_CLR);
if (dsa_is_cpu_port(ds, i))
mt7530_cpu_port_enable(priv, i);
else
mt7530_port_disable(ds, i, NULL);
}
ret = mt7530_fdb_cmd(priv, MT7530_FDB_FLUSH, 0);
if (ret < 0)
return ret;
return 0;
}
static int
mt7530_probe(struct mdio_device *mdiodev)
{
struct mt7530_priv *priv;
struct device_node *dn;
dn = mdiodev->dev.of_node;
priv = devm_kzalloc(&mdiodev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->ds = dsa_switch_alloc(&mdiodev->dev, DSA_MAX_PORTS);
if (!priv->ds)
return -ENOMEM;
priv->mcm = of_property_read_bool(dn, "mediatek,mcm");
if (priv->mcm) {
dev_info(&mdiodev->dev, "MT7530 adapts as multi-chip module\n");
priv->rstc = devm_reset_control_get(&mdiodev->dev, "mcm");
if (IS_ERR(priv->rstc)) {
dev_err(&mdiodev->dev, "Couldn't get our reset line\n");
return PTR_ERR(priv->rstc);
}
}
priv->core_pwr = devm_regulator_get(&mdiodev->dev, "core");
if (IS_ERR(priv->core_pwr))
return PTR_ERR(priv->core_pwr);
priv->io_pwr = devm_regulator_get(&mdiodev->dev, "io");
if (IS_ERR(priv->io_pwr))
return PTR_ERR(priv->io_pwr);
if (!priv->mcm) {
priv->reset = devm_gpiod_get_optional(&mdiodev->dev, "reset",
GPIOD_OUT_LOW);
if (IS_ERR(priv->reset)) {
dev_err(&mdiodev->dev, "Couldn't get our reset line\n");
return PTR_ERR(priv->reset);
}
}
priv->bus = mdiodev->bus;
priv->dev = &mdiodev->dev;
priv->ds->priv = priv;
priv->ds->ops = &mt7530_switch_ops;
mutex_init(&priv->reg_mutex);
dev_set_drvdata(&mdiodev->dev, priv);
return dsa_register_switch(priv->ds, &mdiodev->dev);
}
static void
mt7530_remove(struct mdio_device *mdiodev)
{
struct mt7530_priv *priv = dev_get_drvdata(&mdiodev->dev);
int ret = 0;
ret = regulator_disable(priv->core_pwr);
if (ret < 0)
dev_err(priv->dev,
"Failed to disable core power: %d\n", ret);
ret = regulator_disable(priv->io_pwr);
if (ret < 0)
dev_err(priv->dev, "Failed to disable io pwr: %d\n",
ret);
dsa_unregister_switch(priv->ds);
mutex_destroy(&priv->reg_mutex);
}
