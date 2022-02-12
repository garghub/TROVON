static int lan9303_read(struct regmap *regmap, unsigned int offset, u32 *reg)
{
int ret, i;
for (i = 0; i < 5; i++) {
ret = regmap_read(regmap, offset, reg);
if (!ret)
return 0;
if (ret != -EAGAIN)
break;
msleep(500);
}
return -EIO;
}
static int lan9303_virt_phy_reg_read(struct lan9303 *chip, int regnum)
{
int ret;
u32 val;
if (regnum > MII_EXPANSION)
return -EINVAL;
ret = lan9303_read(chip->regmap, LAN9303_VIRT_PHY_BASE + regnum, &val);
if (ret)
return ret;
return val & 0xffff;
}
static int lan9303_virt_phy_reg_write(struct lan9303 *chip, int regnum, u16 val)
{
if (regnum > MII_EXPANSION)
return -EINVAL;
return regmap_write(chip->regmap, LAN9303_VIRT_PHY_BASE + regnum, val);
}
static int lan9303_port_phy_reg_wait_for_completion(struct lan9303 *chip)
{
int ret, i;
u32 reg;
for (i = 0; i < 25; i++) {
ret = lan9303_read(chip->regmap, LAN9303_PMI_ACCESS, &reg);
if (ret) {
dev_err(chip->dev,
"Failed to read pmi access status: %d\n", ret);
return ret;
}
if (!(reg & LAN9303_PMI_ACCESS_MII_BUSY))
return 0;
msleep(1);
}
return -EIO;
}
static int lan9303_port_phy_reg_read(struct lan9303 *chip, int addr, int regnum)
{
int ret;
u32 val;
val = LAN9303_PMI_ACCESS_PHY_ADDR(addr);
val |= LAN9303_PMI_ACCESS_MIIRINDA(regnum);
mutex_lock(&chip->indirect_mutex);
ret = lan9303_port_phy_reg_wait_for_completion(chip);
if (ret)
goto on_error;
ret = regmap_write(chip->regmap, LAN9303_PMI_ACCESS, val);
if (ret)
goto on_error;
ret = lan9303_port_phy_reg_wait_for_completion(chip);
if (ret)
goto on_error;
ret = lan9303_read(chip->regmap, LAN9303_PMI_DATA, &val);
if (ret)
goto on_error;
mutex_unlock(&chip->indirect_mutex);
return val & 0xffff;
on_error:
mutex_unlock(&chip->indirect_mutex);
return ret;
}
static int lan9303_phy_reg_write(struct lan9303 *chip, int addr, int regnum,
unsigned int val)
{
int ret;
u32 reg;
reg = LAN9303_PMI_ACCESS_PHY_ADDR(addr);
reg |= LAN9303_PMI_ACCESS_MIIRINDA(regnum);
reg |= LAN9303_PMI_ACCESS_MII_WRITE;
mutex_lock(&chip->indirect_mutex);
ret = lan9303_port_phy_reg_wait_for_completion(chip);
if (ret)
goto on_error;
ret = regmap_write(chip->regmap, LAN9303_PMI_DATA, val);
if (ret)
goto on_error;
ret = regmap_write(chip->regmap, LAN9303_PMI_ACCESS, reg);
on_error:
mutex_unlock(&chip->indirect_mutex);
return ret;
}
static int lan9303_switch_wait_for_completion(struct lan9303 *chip)
{
int ret, i;
u32 reg;
for (i = 0; i < 25; i++) {
ret = lan9303_read(chip->regmap, LAN9303_SWITCH_CSR_CMD, &reg);
if (ret) {
dev_err(chip->dev,
"Failed to read csr command status: %d\n", ret);
return ret;
}
if (!(reg & LAN9303_SWITCH_CSR_CMD_BUSY))
return 0;
msleep(1);
}
return -EIO;
}
static int lan9303_write_switch_reg(struct lan9303 *chip, u16 regnum, u32 val)
{
u32 reg;
int ret;
reg = regnum;
reg |= LAN9303_SWITCH_CSR_CMD_LANES;
reg |= LAN9303_SWITCH_CSR_CMD_BUSY;
mutex_lock(&chip->indirect_mutex);
ret = lan9303_switch_wait_for_completion(chip);
if (ret)
goto on_error;
ret = regmap_write(chip->regmap, LAN9303_SWITCH_CSR_DATA, val);
if (ret) {
dev_err(chip->dev, "Failed to write csr data reg: %d\n", ret);
goto on_error;
}
ret = regmap_write(chip->regmap, LAN9303_SWITCH_CSR_CMD, reg);
if (ret)
dev_err(chip->dev, "Failed to write csr command reg: %d\n",
ret);
on_error:
mutex_unlock(&chip->indirect_mutex);
return ret;
}
static int lan9303_read_switch_reg(struct lan9303 *chip, u16 regnum, u32 *val)
{
u32 reg;
int ret;
reg = regnum;
reg |= LAN9303_SWITCH_CSR_CMD_LANES;
reg |= LAN9303_SWITCH_CSR_CMD_RW;
reg |= LAN9303_SWITCH_CSR_CMD_BUSY;
mutex_lock(&chip->indirect_mutex);
ret = lan9303_switch_wait_for_completion(chip);
if (ret)
goto on_error;
ret = regmap_write(chip->regmap, LAN9303_SWITCH_CSR_CMD, reg);
if (ret) {
dev_err(chip->dev, "Failed to write csr command reg: %d\n",
ret);
goto on_error;
}
ret = lan9303_switch_wait_for_completion(chip);
if (ret)
goto on_error;
ret = lan9303_read(chip->regmap, LAN9303_SWITCH_CSR_DATA, val);
if (ret)
dev_err(chip->dev, "Failed to read csr data reg: %d\n", ret);
on_error:
mutex_unlock(&chip->indirect_mutex);
return ret;
}
static int lan9303_detect_phy_setup(struct lan9303 *chip)
{
int reg;
reg = lan9303_port_phy_reg_read(chip, 3, MII_LAN911X_SPECIAL_MODES);
if (reg < 0) {
dev_err(chip->dev, "Failed to detect phy config: %d\n", reg);
return reg;
}
if (reg != 0)
chip->phy_addr_sel_strap = 1;
else
chip->phy_addr_sel_strap = 0;
dev_dbg(chip->dev, "Phy setup '%s' detected\n",
chip->phy_addr_sel_strap ? "1-2-3" : "0-1-2");
return 0;
}
static int lan9303_disable_packet_processing(struct lan9303 *chip,
unsigned int port)
{
int ret;
ret = lan9303_write_switch_reg(chip, LAN9303_MAC_RX_CFG_OFFS + port,
LAN9303_MAC_RX_CFG_X_REJECT_MAC_TYPES);
if (ret)
return ret;
return lan9303_write_switch_reg(chip, LAN9303_MAC_TX_CFG_OFFS + port,
LAN9303_MAC_TX_CFG_X_TX_IFG_CONFIG_DEFAULT |
LAN9303_MAC_TX_CFG_X_TX_PAD_ENABLE);
}
static int lan9303_enable_packet_processing(struct lan9303 *chip,
unsigned int port)
{
int ret;
ret = lan9303_write_switch_reg(chip, LAN9303_MAC_RX_CFG_OFFS + port,
LAN9303_MAC_RX_CFG_X_REJECT_MAC_TYPES |
LAN9303_MAC_RX_CFG_X_RX_ENABLE);
if (ret)
return ret;
return lan9303_write_switch_reg(chip, LAN9303_MAC_TX_CFG_OFFS + port,
LAN9303_MAC_TX_CFG_X_TX_IFG_CONFIG_DEFAULT |
LAN9303_MAC_TX_CFG_X_TX_PAD_ENABLE |
LAN9303_MAC_TX_CFG_X_TX_ENABLE);
}
static int lan9303_separate_ports(struct lan9303 *chip)
{
int ret;
ret = lan9303_write_switch_reg(chip, LAN9303_SWE_PORT_MIRROR,
LAN9303_SWE_PORT_MIRROR_SNIFFER_PORT0 |
LAN9303_SWE_PORT_MIRROR_MIRRORED_PORT1 |
LAN9303_SWE_PORT_MIRROR_MIRRORED_PORT2 |
LAN9303_SWE_PORT_MIRROR_ENABLE_RX_MIRRORING |
LAN9303_SWE_PORT_MIRROR_SNIFF_ALL);
if (ret)
return ret;
ret = lan9303_write_switch_reg(chip, LAN9303_SWE_INGRESS_PORT_TYPE,
0x03);
if (ret)
return ret;
ret = lan9303_write_switch_reg(chip, LAN9303_BM_EGRSS_PORT_TYPE,
LAN9303_BM_EGRSS_PORT_TYPE_SPECIAL_TAG_PORT0);
if (ret)
return ret;
return lan9303_write_switch_reg(chip, LAN9303_SWE_PORT_STATE,
LAN9303_SWE_PORT_STATE_FORWARDING_PORT0 |
LAN9303_SWE_PORT_STATE_BLOCKING_PORT1 |
LAN9303_SWE_PORT_STATE_BLOCKING_PORT2);
}
static int lan9303_handle_reset(struct lan9303 *chip)
{
if (!chip->reset_gpio)
return 0;
if (chip->reset_duration != 0)
msleep(chip->reset_duration);
gpiod_set_value_cansleep(chip->reset_gpio, 0);
return 0;
}
static int lan9303_disable_processing(struct lan9303 *chip)
{
int ret;
ret = lan9303_disable_packet_processing(chip, LAN9303_PORT_0_OFFSET);
if (ret)
return ret;
ret = lan9303_disable_packet_processing(chip, LAN9303_PORT_1_OFFSET);
if (ret)
return ret;
return lan9303_disable_packet_processing(chip, LAN9303_PORT_2_OFFSET);
}
static int lan9303_check_device(struct lan9303 *chip)
{
int ret;
u32 reg;
ret = lan9303_read(chip->regmap, LAN9303_CHIP_REV, &reg);
if (ret) {
dev_err(chip->dev, "failed to read chip revision register: %d\n",
ret);
if (!chip->reset_gpio) {
dev_dbg(chip->dev,
"hint: maybe failed due to missing reset GPIO\n");
}
return ret;
}
if ((reg >> 16) != LAN9303_CHIP_ID) {
dev_err(chip->dev, "expecting LAN9303 chip, but found: %X\n",
reg >> 16);
return ret;
}
ret = lan9303_disable_processing(chip);
if (ret)
dev_warn(chip->dev, "failed to disable switching %d\n", ret);
dev_info(chip->dev, "Found LAN9303 rev. %u\n", reg & 0xffff);
ret = lan9303_detect_phy_setup(chip);
if (ret) {
dev_err(chip->dev,
"failed to discover phy bootstrap setup: %d\n", ret);
return ret;
}
return 0;
}
static enum dsa_tag_protocol lan9303_get_tag_protocol(struct dsa_switch *ds)
{
return DSA_TAG_PROTO_LAN9303;
}
static int lan9303_setup(struct dsa_switch *ds)
{
struct lan9303 *chip = ds->priv;
int ret;
if (!dsa_is_cpu_port(ds, 0)) {
dev_err(chip->dev, "port 0 is not the CPU port\n");
return -EINVAL;
}
ret = lan9303_separate_ports(chip);
if (ret)
dev_err(chip->dev, "failed to separate ports %d\n", ret);
ret = lan9303_enable_packet_processing(chip, LAN9303_PORT_0_OFFSET);
if (ret)
dev_err(chip->dev, "failed to re-enable switching %d\n", ret);
return 0;
}
static void lan9303_get_strings(struct dsa_switch *ds, int port, uint8_t *data)
{
unsigned int u;
for (u = 0; u < ARRAY_SIZE(lan9303_mib); u++) {
strncpy(data + u * ETH_GSTRING_LEN, lan9303_mib[u].name,
ETH_GSTRING_LEN);
}
}
static void lan9303_get_ethtool_stats(struct dsa_switch *ds, int port,
uint64_t *data)
{
struct lan9303 *chip = ds->priv;
u32 reg;
unsigned int u, poff;
int ret;
poff = port * 0x400;
for (u = 0; u < ARRAY_SIZE(lan9303_mib); u++) {
ret = lan9303_read_switch_reg(chip,
lan9303_mib[u].offset + poff,
&reg);
if (ret)
dev_warn(chip->dev, "Reading status reg %u failed\n",
lan9303_mib[u].offset + poff);
data[u] = reg;
}
}
static int lan9303_get_sset_count(struct dsa_switch *ds)
{
return ARRAY_SIZE(lan9303_mib);
}
static int lan9303_phy_read(struct dsa_switch *ds, int phy, int regnum)
{
struct lan9303 *chip = ds->priv;
int phy_base = chip->phy_addr_sel_strap;
if (phy == phy_base)
return lan9303_virt_phy_reg_read(chip, regnum);
if (phy > phy_base + 2)
return -ENODEV;
return lan9303_port_phy_reg_read(chip, phy, regnum);
}
static int lan9303_phy_write(struct dsa_switch *ds, int phy, int regnum,
u16 val)
{
struct lan9303 *chip = ds->priv;
int phy_base = chip->phy_addr_sel_strap;
if (phy == phy_base)
return lan9303_virt_phy_reg_write(chip, regnum, val);
if (phy > phy_base + 2)
return -ENODEV;
return lan9303_phy_reg_write(chip, phy, regnum, val);
}
static int lan9303_port_enable(struct dsa_switch *ds, int port,
struct phy_device *phy)
{
struct lan9303 *chip = ds->priv;
switch (port) {
case 1:
return lan9303_enable_packet_processing(chip,
LAN9303_PORT_1_OFFSET);
case 2:
return lan9303_enable_packet_processing(chip,
LAN9303_PORT_2_OFFSET);
default:
dev_dbg(chip->dev,
"Error: request to power up invalid port %d\n", port);
}
return -ENODEV;
}
static void lan9303_port_disable(struct dsa_switch *ds, int port,
struct phy_device *phy)
{
struct lan9303 *chip = ds->priv;
switch (port) {
case 1:
lan9303_disable_packet_processing(chip, LAN9303_PORT_1_OFFSET);
lan9303_phy_reg_write(chip, chip->phy_addr_sel_strap + 1,
MII_BMCR, BMCR_PDOWN);
break;
case 2:
lan9303_disable_packet_processing(chip, LAN9303_PORT_2_OFFSET);
lan9303_phy_reg_write(chip, chip->phy_addr_sel_strap + 2,
MII_BMCR, BMCR_PDOWN);
break;
default:
dev_dbg(chip->dev,
"Error: request to power down invalid port %d\n", port);
}
}
static int lan9303_register_switch(struct lan9303 *chip)
{
chip->ds = dsa_switch_alloc(chip->dev, DSA_MAX_PORTS);
if (!chip->ds)
return -ENOMEM;
chip->ds->priv = chip;
chip->ds->ops = &lan9303_switch_ops;
chip->ds->phys_mii_mask = chip->phy_addr_sel_strap ? 0xe : 0x7;
return dsa_register_switch(chip->ds, chip->dev);
}
static void lan9303_probe_reset_gpio(struct lan9303 *chip,
struct device_node *np)
{
chip->reset_gpio = devm_gpiod_get_optional(chip->dev, "reset",
GPIOD_OUT_LOW);
if (!chip->reset_gpio) {
dev_dbg(chip->dev, "No reset GPIO defined\n");
return;
}
chip->reset_duration = 200;
if (np) {
of_property_read_u32(np, "reset-duration",
&chip->reset_duration);
} else {
dev_dbg(chip->dev, "reset duration defaults to 200 ms\n");
}
if (chip->reset_duration > 1000)
chip->reset_duration = 1000;
}
int lan9303_probe(struct lan9303 *chip, struct device_node *np)
{
int ret;
mutex_init(&chip->indirect_mutex);
lan9303_probe_reset_gpio(chip, np);
ret = lan9303_handle_reset(chip);
if (ret)
return ret;
ret = lan9303_check_device(chip);
if (ret)
return ret;
ret = lan9303_register_switch(chip);
if (ret) {
dev_dbg(chip->dev, "Failed to register switch: %d\n", ret);
return ret;
}
return 0;
}
int lan9303_remove(struct lan9303 *chip)
{
int rc;
rc = lan9303_disable_processing(chip);
if (rc != 0)
dev_warn(chip->dev, "shutting down failed\n");
dsa_unregister_switch(chip->ds);
gpiod_set_value_cansleep(chip->reset_gpio, 1);
gpiod_unexport(chip->reset_gpio);
return 0;
}
