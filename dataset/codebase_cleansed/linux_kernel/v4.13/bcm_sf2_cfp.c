static inline unsigned int bcm_sf2_get_num_udf_slices(const u8 *layout)
{
unsigned int i, count = 0;
for (i = 0; i < UDF_NUM_SLICES; i++) {
if (layout[i] != 0)
count++;
}
return count;
}
static void bcm_sf2_cfp_udf_set(struct bcm_sf2_priv *priv,
unsigned int slice_num,
const u8 *layout)
{
u32 offset = CORE_UDF_0_A_0_8_PORT_0 + slice_num * UDF_SLICE_OFFSET;
unsigned int i;
for (i = 0; i < UDF_NUM_SLICES; i++)
core_writel(priv, layout[i], offset + i * 4);
}
static int bcm_sf2_cfp_op(struct bcm_sf2_priv *priv, unsigned int op)
{
unsigned int timeout = 1000;
u32 reg;
reg = core_readl(priv, CORE_CFP_ACC);
reg &= ~(OP_SEL_MASK | RAM_SEL_MASK);
reg |= OP_STR_DONE | op;
core_writel(priv, reg, CORE_CFP_ACC);
do {
reg = core_readl(priv, CORE_CFP_ACC);
if (!(reg & OP_STR_DONE))
break;
cpu_relax();
} while (timeout--);
if (!timeout)
return -ETIMEDOUT;
return 0;
}
static inline void bcm_sf2_cfp_rule_addr_set(struct bcm_sf2_priv *priv,
unsigned int addr)
{
u32 reg;
WARN_ON(addr >= priv->num_cfp_rules);
reg = core_readl(priv, CORE_CFP_ACC);
reg &= ~(XCESS_ADDR_MASK << XCESS_ADDR_SHIFT);
reg |= addr << XCESS_ADDR_SHIFT;
core_writel(priv, reg, CORE_CFP_ACC);
}
static inline unsigned int bcm_sf2_cfp_rule_size(struct bcm_sf2_priv *priv)
{
return priv->num_cfp_rules - 1;
}
static int bcm_sf2_cfp_rule_set(struct dsa_switch *ds, int port,
struct ethtool_rx_flow_spec *fs)
{
struct bcm_sf2_priv *priv = bcm_sf2_to_priv(ds);
struct ethtool_tcpip4_spec *v4_spec;
const struct cfp_udf_layout *layout;
unsigned int slice_num, rule_index;
unsigned int queue_num, port_num;
u8 ip_proto, ip_frag;
u8 num_udf;
u32 reg;
int ret;
if ((fs->flow_type & FLOW_EXT) &&
(fs->m_ext.vlan_etype || fs->m_ext.data[1]))
return -EINVAL;
if (fs->location != RX_CLS_LOC_ANY &&
test_bit(fs->location, priv->cfp.used))
return -EBUSY;
if (fs->location != RX_CLS_LOC_ANY &&
fs->location > bcm_sf2_cfp_rule_size(priv))
return -EINVAL;
ip_frag = be32_to_cpu(fs->m_ext.data[0]);
port_num = fs->ring_cookie / 8;
if (fs->ring_cookie == RX_CLS_FLOW_DISC ||
!(BIT(port_num) & ds->enabled_port_mask) ||
port_num >= priv->hw_params.num_ports)
return -EINVAL;
switch (fs->flow_type & ~FLOW_EXT) {
case TCP_V4_FLOW:
ip_proto = IPPROTO_TCP;
v4_spec = &fs->h_u.tcp_ip4_spec;
break;
case UDP_V4_FLOW:
ip_proto = IPPROTO_UDP;
v4_spec = &fs->h_u.udp_ip4_spec;
break;
default:
return -EINVAL;
}
slice_num = 1;
layout = &udf_tcpip4_layout;
num_udf = bcm_sf2_get_num_udf_slices(layout->slices);
bcm_sf2_cfp_udf_set(priv, slice_num, layout->slices);
core_writel(priv, BIT(port), CORE_CFP_DATA_PORT(7));
core_writel(priv, v4_spec->tos << 16 | ip_proto << 8 | ip_frag << 7,
CORE_CFP_DATA_PORT(6));
core_writel(priv, GENMASK(num_udf - 1, 0) << 24, CORE_CFP_DATA_PORT(5));
core_writel(priv, 0, CORE_CFP_DATA_PORT(4));
core_writel(priv, be16_to_cpu(v4_spec->pdst) >> 8,
CORE_CFP_DATA_PORT(3));
reg = (be16_to_cpu(v4_spec->pdst) & 0xff) << 24 |
(u32)be16_to_cpu(v4_spec->psrc) << 8 |
(be32_to_cpu(v4_spec->ip4dst) & 0x0000ff00) >> 8;
core_writel(priv, reg, CORE_CFP_DATA_PORT(2));
reg = (u32)(be32_to_cpu(v4_spec->ip4dst) & 0xff) << 24 |
(u32)(be32_to_cpu(v4_spec->ip4dst) >> 16) << 8 |
(be32_to_cpu(v4_spec->ip4src) & 0x0000ff00) >> 8;
core_writel(priv, reg, CORE_CFP_DATA_PORT(1));
reg = (u32)(be32_to_cpu(v4_spec->ip4src) & 0xff) << 24 |
(u32)(be32_to_cpu(v4_spec->ip4src) >> 16) << 8 |
SLICE_NUM(slice_num) | SLICE_VALID;
core_writel(priv, reg, CORE_CFP_DATA_PORT(0));
core_writel(priv, 0xff, CORE_CFP_MASK_PORT(7));
core_writel(priv, layout->mask_value, CORE_CFP_MASK_PORT(6));
core_writel(priv, GENMASK(num_udf - 1, 0) << 24, CORE_CFP_MASK_PORT(5));
core_writel(priv, 0, CORE_CFP_MASK_PORT(4));
core_writel(priv, 0xff, CORE_CFP_MASK_PORT(3));
core_writel(priv, 0xffffffff, CORE_CFP_MASK_PORT(2));
core_writel(priv, 0xffffffff, CORE_CFP_MASK_PORT(1));
core_writel(priv, 0xffffff0f, CORE_CFP_MASK_PORT(0));
if (fs->location == RX_CLS_LOC_ANY)
rule_index = find_first_zero_bit(priv->cfp.used,
bcm_sf2_cfp_rule_size(priv));
else
rule_index = fs->location;
bcm_sf2_cfp_rule_addr_set(priv, rule_index);
ret = bcm_sf2_cfp_op(priv, OP_SEL_WRITE | TCAM_SEL);
if (ret) {
pr_err("TCAM entry at addr %d failed\n", rule_index);
return ret;
}
queue_num = fs->ring_cookie % 8;
if (port_num >= 7)
port_num -= 1;
reg = CHANGE_FWRD_MAP_IB_REP_ARL | BIT(port_num + DST_MAP_IB_SHIFT) |
CHANGE_TC | queue_num << NEW_TC_SHIFT;
core_writel(priv, reg, CORE_ACT_POL_DATA0);
core_writel(priv, rule_index << CHAIN_ID_SHIFT,
CORE_ACT_POL_DATA1);
core_writel(priv, 0, CORE_ACT_POL_DATA2);
ret = bcm_sf2_cfp_op(priv, OP_SEL_WRITE | ACT_POL_RAM);
if (ret) {
pr_err("Policer entry at %d failed\n", rule_index);
return ret;
}
core_writel(priv, POLICER_MODE_DISABLE, CORE_RATE_METER0);
ret = bcm_sf2_cfp_op(priv, OP_SEL_WRITE | RATE_METER_RAM);
if (ret) {
pr_err("Meter entry at %d failed\n", rule_index);
return ret;
}
reg = core_readl(priv, CORE_CFP_CTL_REG);
reg |= BIT(port);
core_writel(priv, reg, CORE_CFP_CTL_REG);
set_bit(rule_index, priv->cfp.used);
fs->location = rule_index;
return 0;
}
static int bcm_sf2_cfp_rule_del(struct bcm_sf2_priv *priv, int port,
u32 loc)
{
int ret;
u32 reg;
if (!test_bit(loc, priv->cfp.used) || loc == 0)
return -EINVAL;
bcm_sf2_cfp_rule_addr_set(priv, loc);
ret = bcm_sf2_cfp_op(priv, OP_SEL_READ | TCAM_SEL);
if (ret)
return ret;
reg = core_readl(priv, CORE_CFP_DATA_PORT(0));
reg &= ~SLICE_VALID;
core_writel(priv, reg, CORE_CFP_DATA_PORT(0));
ret = bcm_sf2_cfp_op(priv, OP_SEL_WRITE | TCAM_SEL);
if (ret)
return ret;
clear_bit(loc, priv->cfp.used);
return 0;
}
static void bcm_sf2_invert_masks(struct ethtool_rx_flow_spec *flow)
{
unsigned int i;
for (i = 0; i < sizeof(flow->m_u); i++)
flow->m_u.hdata[i] ^= 0xff;
flow->m_ext.vlan_etype ^= cpu_to_be16(~0);
flow->m_ext.vlan_tci ^= cpu_to_be16(~0);
flow->m_ext.data[0] ^= cpu_to_be32(~0);
flow->m_ext.data[1] ^= cpu_to_be32(~0);
}
static int bcm_sf2_cfp_rule_get(struct bcm_sf2_priv *priv, int port,
struct ethtool_rxnfc *nfc, bool search)
{
struct ethtool_tcpip4_spec *v4_spec;
unsigned int queue_num;
u16 src_dst_port;
u32 reg, ipv4;
int ret;
if (!search) {
bcm_sf2_cfp_rule_addr_set(priv, nfc->fs.location);
ret = bcm_sf2_cfp_op(priv, OP_SEL_READ | ACT_POL_RAM);
if (ret)
return ret;
reg = core_readl(priv, CORE_ACT_POL_DATA0);
ret = bcm_sf2_cfp_op(priv, OP_SEL_READ | TCAM_SEL);
if (ret)
return ret;
} else {
reg = core_readl(priv, CORE_ACT_POL_DATA0);
}
nfc->fs.ring_cookie = fls((reg >> DST_MAP_IB_SHIFT) &
DST_MAP_IB_MASK) - 1;
if (nfc->fs.ring_cookie >= 6)
nfc->fs.ring_cookie++;
nfc->fs.ring_cookie *= 8;
queue_num = (reg >> NEW_TC_SHIFT) & NEW_TC_MASK;
nfc->fs.ring_cookie += queue_num;
reg = core_readl(priv, CORE_CFP_DATA_PORT(6));
switch ((reg & IPPROTO_MASK) >> IPPROTO_SHIFT) {
case IPPROTO_TCP:
nfc->fs.flow_type = TCP_V4_FLOW;
v4_spec = &nfc->fs.h_u.tcp_ip4_spec;
break;
case IPPROTO_UDP:
nfc->fs.flow_type = UDP_V4_FLOW;
v4_spec = &nfc->fs.h_u.udp_ip4_spec;
break;
default:
if (search)
core_readl(priv, CORE_CFP_DATA_PORT(7));
return -EINVAL;
}
v4_spec->tos = (reg >> 16) & IPPROTO_MASK;
nfc->fs.m_ext.data[0] = cpu_to_be32((reg >> 7) & 1);
reg = core_readl(priv, CORE_CFP_DATA_PORT(3));
src_dst_port = reg << 8;
reg = core_readl(priv, CORE_CFP_DATA_PORT(2));
src_dst_port |= (reg >> 24);
v4_spec->pdst = cpu_to_be16(src_dst_port);
nfc->fs.m_u.tcp_ip4_spec.pdst = cpu_to_be16(~0);
v4_spec->psrc = cpu_to_be16((u16)(reg >> 8));
nfc->fs.m_u.tcp_ip4_spec.psrc = cpu_to_be16(~0);
ipv4 = (reg & 0xff) << 8;
reg = core_readl(priv, CORE_CFP_DATA_PORT(1));
ipv4 |= ((reg >> 8) & 0xffff) << 16;
ipv4 |= (reg >> 24) & 0xff;
v4_spec->ip4dst = cpu_to_be32(ipv4);
nfc->fs.m_u.tcp_ip4_spec.ip4dst = cpu_to_be32(~0);
ipv4 = (reg & 0xff) << 8;
reg = core_readl(priv, CORE_CFP_DATA_PORT(0));
if (!(reg & SLICE_VALID))
return -EINVAL;
ipv4 |= (reg >> 24) & 0xff;
ipv4 |= ((reg >> 8) & 0xffff) << 16;
v4_spec->ip4src = cpu_to_be32(ipv4);
nfc->fs.m_u.tcp_ip4_spec.ip4src = cpu_to_be32(~0);
reg = core_readl(priv, CORE_CFP_DATA_PORT(7));
if (!(reg & 1 << port))
return -EINVAL;
bcm_sf2_invert_masks(&nfc->fs);
nfc->data = bcm_sf2_cfp_rule_size(priv);
return 0;
}
static int bcm_sf2_cfp_rule_get_all(struct bcm_sf2_priv *priv,
int port, struct ethtool_rxnfc *nfc,
u32 *rule_locs)
{
unsigned int index = 1, rules_cnt = 0;
int ret;
u32 reg;
reg = core_readl(priv, CORE_CFP_ACC);
reg &= ~(XCESS_ADDR_MASK << XCESS_ADDR_SHIFT);
reg |= index << XCESS_ADDR_SHIFT;
reg &= ~(OP_SEL_MASK | RAM_SEL_MASK);
reg |= OP_SEL_SEARCH | TCAM_SEL | OP_STR_DONE;
core_writel(priv, reg, CORE_CFP_ACC);
do {
reg = core_readl(priv, CORE_CFP_ACC);
index = reg >> XCESS_ADDR_SHIFT;
index &= XCESS_ADDR_MASK;
if (reg & SEARCH_STS) {
ret = bcm_sf2_cfp_rule_get(priv, port, nfc, true);
if (ret)
continue;
rule_locs[rules_cnt] = index;
rules_cnt++;
}
if (!(reg & OP_STR_DONE))
break;
} while (index < priv->num_cfp_rules);
nfc->data = bcm_sf2_cfp_rule_size(priv);
nfc->rule_cnt = rules_cnt;
return 0;
}
int bcm_sf2_get_rxnfc(struct dsa_switch *ds, int port,
struct ethtool_rxnfc *nfc, u32 *rule_locs)
{
struct bcm_sf2_priv *priv = bcm_sf2_to_priv(ds);
int ret = 0;
mutex_lock(&priv->cfp.lock);
switch (nfc->cmd) {
case ETHTOOL_GRXCLSRLCNT:
nfc->rule_cnt = bitmap_weight(priv->cfp.used,
priv->num_cfp_rules) - 1;
nfc->data |= RX_CLS_LOC_SPECIAL;
break;
case ETHTOOL_GRXCLSRULE:
ret = bcm_sf2_cfp_rule_get(priv, port, nfc, false);
break;
case ETHTOOL_GRXCLSRLALL:
ret = bcm_sf2_cfp_rule_get_all(priv, port, nfc, rule_locs);
break;
default:
ret = -EOPNOTSUPP;
break;
}
mutex_unlock(&priv->cfp.lock);
return ret;
}
int bcm_sf2_set_rxnfc(struct dsa_switch *ds, int port,
struct ethtool_rxnfc *nfc)
{
struct bcm_sf2_priv *priv = bcm_sf2_to_priv(ds);
int ret = 0;
mutex_lock(&priv->cfp.lock);
switch (nfc->cmd) {
case ETHTOOL_SRXCLSRLINS:
ret = bcm_sf2_cfp_rule_set(ds, port, &nfc->fs);
break;
case ETHTOOL_SRXCLSRLDEL:
ret = bcm_sf2_cfp_rule_del(priv, port, nfc->fs.location);
break;
default:
ret = -EOPNOTSUPP;
break;
}
mutex_unlock(&priv->cfp.lock);
return ret;
}
int bcm_sf2_cfp_rst(struct bcm_sf2_priv *priv)
{
unsigned int timeout = 1000;
u32 reg;
reg = core_readl(priv, CORE_CFP_ACC);
reg |= TCAM_RESET;
core_writel(priv, reg, CORE_CFP_ACC);
do {
reg = core_readl(priv, CORE_CFP_ACC);
if (!(reg & TCAM_RESET))
break;
cpu_relax();
} while (timeout--);
if (!timeout)
return -ETIMEDOUT;
return 0;
}
