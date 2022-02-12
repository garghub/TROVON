static inline void __iomem *brcm_sata_pcb_base(struct brcm_sata_port *port)
{
struct brcm_sata_phy *priv = port->phy_priv;
u32 size = 0;
switch (priv->version) {
case BRCM_SATA_PHY_STB_28NM:
case BRCM_SATA_PHY_IPROC_NS2:
size = SATA_PCB_REG_28NM_SPACE_SIZE;
break;
case BRCM_SATA_PHY_STB_40NM:
size = SATA_PCB_REG_40NM_SPACE_SIZE;
break;
default:
dev_err(priv->dev, "invalid phy version\n");
break;
}
return priv->phy_base + (port->portnum * size);
}
static inline void __iomem *brcm_sata_ctrl_base(struct brcm_sata_port *port)
{
struct brcm_sata_phy *priv = port->phy_priv;
u32 size = 0;
switch (priv->version) {
case BRCM_SATA_PHY_IPROC_NS2:
size = SATA_PHY_CTRL_REG_28NM_SPACE_SIZE;
break;
default:
dev_err(priv->dev, "invalid phy version\n");
break;
}
return priv->ctrl_base + (port->portnum * size);
}
static void brcm_sata_phy_wr(void __iomem *pcb_base, u32 bank,
u32 ofs, u32 msk, u32 value)
{
u32 tmp;
writel(bank, pcb_base + SATA_PCB_BANK_OFFSET);
tmp = readl(pcb_base + SATA_PCB_REG_OFFSET(ofs));
tmp = (tmp & msk) | value;
writel(tmp, pcb_base + SATA_PCB_REG_OFFSET(ofs));
}
static u32 brcm_sata_phy_rd(void __iomem *pcb_base, u32 bank, u32 ofs)
{
writel(bank, pcb_base + SATA_PCB_BANK_OFFSET);
return readl(pcb_base + SATA_PCB_REG_OFFSET(ofs));
}
static int brcm_stb_sata_init(struct brcm_sata_port *port)
{
void __iomem *base = brcm_sata_pcb_base(port);
struct brcm_sata_phy *priv = port->phy_priv;
u32 tmp;
tmp = TXPMD_CONTROL1_TX_SSC_EN_FRC_VAL | TXPMD_CONTROL1_TX_SSC_EN_FRC;
brcm_sata_phy_wr(base, TXPMD_REG_BANK, TXPMD_CONTROL1, ~tmp, tmp);
brcm_sata_phy_wr(base, TXPMD_REG_BANK, TXPMD_TX_FREQ_CTRL_CONTROL2,
~TXPMD_TX_FREQ_CTRL_CONTROL2_FMIN_MASK,
STB_FMIN_VAL_DEFAULT);
if (port->ssc_en) {
dev_info(priv->dev, "enabling SSC on port%d\n", port->portnum);
tmp = STB_FMAX_VAL_SSC;
} else {
tmp = STB_FMAX_VAL_DEFAULT;
}
brcm_sata_phy_wr(base, TXPMD_REG_BANK, TXPMD_TX_FREQ_CTRL_CONTROL3,
~TXPMD_TX_FREQ_CTRL_CONTROL3_FMAX_MASK, tmp);
return 0;
}
static int brcm_ns2_sata_init(struct brcm_sata_port *port)
{
int try;
unsigned int val;
void __iomem *base = brcm_sata_pcb_base(port);
void __iomem *ctrl_base = brcm_sata_ctrl_base(port);
struct device *dev = port->phy_priv->dev;
val = 0x0;
val |= (0xc << OOB_CTRL1_BURST_MAX_SHIFT);
val |= (0x4 << OOB_CTRL1_BURST_MIN_SHIFT);
val |= (0x9 << OOB_CTRL1_WAKE_IDLE_MAX_SHIFT);
val |= (0x3 << OOB_CTRL1_WAKE_IDLE_MIN_SHIFT);
brcm_sata_phy_wr(base, OOB_REG_BANK, OOB_CTRL1, 0x0, val);
val = 0x0;
val |= (0x1b << OOB_CTRL2_RESET_IDLE_MAX_SHIFT);
val |= (0x2 << OOB_CTRL2_BURST_CNT_SHIFT);
val |= (0x9 << OOB_CTRL2_RESET_IDLE_MIN_SHIFT);
brcm_sata_phy_wr(base, OOB_REG_BANK, OOB_CTRL2, 0x0, val);
val = NS2_PLL1_ACTRL2_MAGIC;
brcm_sata_phy_wr(base, PLL1_REG_BANK, PLL1_ACTRL2, 0x0, val);
val = NS2_PLL1_ACTRL3_MAGIC;
brcm_sata_phy_wr(base, PLL1_REG_BANK, PLL1_ACTRL3, 0x0, val);
val = NS2_PLL1_ACTRL4_MAGIC;
brcm_sata_phy_wr(base, PLL1_REG_BANK, PLL1_ACTRL4, 0x0, val);
brcm_sata_phy_wr(base, BLOCK0_REG_BANK, BLOCK0_SPARE,
~BLOCK0_SPARE_OOB_CLK_SEL_MASK,
BLOCK0_SPARE_OOB_CLK_SEL_REFBY2);
writel(PHY_CTRL_1_RESET, ctrl_base + PHY_CTRL_1);
mdelay(1);
writel(0x0, ctrl_base + PHY_CTRL_1);
mdelay(1);
try = 50;
while (try) {
val = brcm_sata_phy_rd(base, BLOCK0_REG_BANK,
BLOCK0_XGXSSTATUS);
if (val & BLOCK0_XGXSSTATUS_PLL_LOCK)
break;
msleep(20);
try--;
}
if (!try) {
dev_err(dev, "port%d PLL did not lock\n", port->portnum);
return -ETIMEDOUT;
}
dev_dbg(dev, "port%d initialized\n", port->portnum);
return 0;
}
static int brcm_nsp_sata_init(struct brcm_sata_port *port)
{
struct brcm_sata_phy *priv = port->phy_priv;
struct device *dev = port->phy_priv->dev;
void __iomem *base = priv->phy_base;
unsigned int oob_bank;
unsigned int val, try;
if (port->portnum == 0)
oob_bank = OOB_REG_BANK;
else if (port->portnum == 1)
oob_bank = OOB1_REG_BANK;
else
return -EINVAL;
val = 0x0;
val |= (0x0f << OOB_CTRL1_BURST_MAX_SHIFT);
val |= (0x06 << OOB_CTRL1_BURST_MIN_SHIFT);
val |= (0x0f << OOB_CTRL1_WAKE_IDLE_MAX_SHIFT);
val |= (0x06 << OOB_CTRL1_WAKE_IDLE_MIN_SHIFT);
brcm_sata_phy_wr(base, oob_bank, OOB_CTRL1, 0x0, val);
val = 0x0;
val |= (0x2e << OOB_CTRL2_RESET_IDLE_MAX_SHIFT);
val |= (0x02 << OOB_CTRL2_BURST_CNT_SHIFT);
val |= (0x16 << OOB_CTRL2_RESET_IDLE_MIN_SHIFT);
brcm_sata_phy_wr(base, oob_bank, OOB_CTRL2, 0x0, val);
brcm_sata_phy_wr(base, PLL_REG_BANK_0, PLL_ACTRL2,
~(PLL_ACTRL2_SELDIV_MASK << PLL_ACTRL2_SELDIV_SHIFT),
0x0c << PLL_ACTRL2_SELDIV_SHIFT);
brcm_sata_phy_wr(base, PLL_REG_BANK_0, PLL_CAP_CONTROL,
0xff0, 0x4f0);
val = PLLCONTROL_0_FREQ_DET_RESTART | PLLCONTROL_0_FREQ_MONITOR;
brcm_sata_phy_wr(base, PLL_REG_BANK_0, PLL_REG_BANK_0_PLLCONTROL_0,
~val, val);
val = PLLCONTROL_0_SEQ_START;
brcm_sata_phy_wr(base, PLL_REG_BANK_0, PLL_REG_BANK_0_PLLCONTROL_0,
~val, 0);
mdelay(10);
brcm_sata_phy_wr(base, PLL_REG_BANK_0, PLL_REG_BANK_0_PLLCONTROL_0,
~val, val);
try = 50;
while (--try) {
val = brcm_sata_phy_rd(base, BLOCK0_REG_BANK,
BLOCK0_XGXSSTATUS);
if (val & BLOCK0_XGXSSTATUS_PLL_LOCK)
break;
msleep(20);
}
if (!try) {
dev_err(dev, "port%d PLL did not lock\n", port->portnum);
return -ETIMEDOUT;
}
dev_dbg(dev, "port%d initialized\n", port->portnum);
return 0;
}
static int brcm_sr_sata_init(struct brcm_sata_port *port)
{
struct brcm_sata_phy *priv = port->phy_priv;
struct device *dev = port->phy_priv->dev;
void __iomem *base = priv->phy_base;
unsigned int val, try;
val = SR_PLL1_ACTRL2_MAGIC;
brcm_sata_phy_wr(base, PLL1_REG_BANK, PLL1_ACTRL2, 0x0, val);
val = SR_PLL1_ACTRL3_MAGIC;
brcm_sata_phy_wr(base, PLL1_REG_BANK, PLL1_ACTRL3, 0x0, val);
val = SR_PLL1_ACTRL4_MAGIC;
brcm_sata_phy_wr(base, PLL1_REG_BANK, PLL1_ACTRL4, 0x0, val);
val = SR_PLL0_ACTRL6_MAGIC;
brcm_sata_phy_wr(base, PLL_REG_BANK_0, PLL_ACTRL6, 0x0, val);
try = 50;
do {
val = brcm_sata_phy_rd(base, BLOCK0_REG_BANK,
BLOCK0_XGXSSTATUS);
if (val & BLOCK0_XGXSSTATUS_PLL_LOCK)
break;
msleep(20);
try--;
} while (try);
if ((val & BLOCK0_XGXSSTATUS_PLL_LOCK) == 0) {
dev_err(dev, "port%d PLL did not lock\n", port->portnum);
return -ETIMEDOUT;
}
brcm_sata_phy_wr(base, TX_REG_BANK, TX_ACTRL0,
~TX_ACTRL0_TXPOL_FLIP, TX_ACTRL0_TXPOL_FLIP);
val = ((0xc << OOB_CTRL1_BURST_MAX_SHIFT) |
(0x4 << OOB_CTRL1_BURST_MIN_SHIFT) |
(0x8 << OOB_CTRL1_WAKE_IDLE_MAX_SHIFT) |
(0x3 << OOB_CTRL1_WAKE_IDLE_MIN_SHIFT));
brcm_sata_phy_wr(base, OOB_REG_BANK, OOB_CTRL1, 0x0, val);
val = ((0x1b << OOB_CTRL2_RESET_IDLE_MAX_SHIFT) |
(0x2 << OOB_CTRL2_BURST_CNT_SHIFT) |
(0x9 << OOB_CTRL2_RESET_IDLE_MIN_SHIFT));
brcm_sata_phy_wr(base, OOB_REG_BANK, OOB_CTRL2, 0x0, val);
return 0;
}
static int brcm_sata_phy_init(struct phy *phy)
{
int rc;
struct brcm_sata_port *port = phy_get_drvdata(phy);
switch (port->phy_priv->version) {
case BRCM_SATA_PHY_STB_28NM:
case BRCM_SATA_PHY_STB_40NM:
rc = brcm_stb_sata_init(port);
break;
case BRCM_SATA_PHY_IPROC_NS2:
rc = brcm_ns2_sata_init(port);
break;
case BRCM_SATA_PHY_IPROC_NSP:
rc = brcm_nsp_sata_init(port);
break;
case BRCM_SATA_PHY_IPROC_SR:
rc = brcm_sr_sata_init(port);
break;
default:
rc = -ENODEV;
}
return rc;
}
static int brcm_sata_phy_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *dn = dev->of_node, *child;
const struct of_device_id *of_id;
struct brcm_sata_phy *priv;
struct resource *res;
struct phy_provider *provider;
int ret, count = 0;
if (of_get_child_count(dn) == 0)
return -ENODEV;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
dev_set_drvdata(dev, priv);
priv->dev = dev;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "phy");
priv->phy_base = devm_ioremap_resource(dev, res);
if (IS_ERR(priv->phy_base))
return PTR_ERR(priv->phy_base);
of_id = of_match_node(brcm_sata_phy_of_match, dn);
if (of_id)
priv->version = (enum brcm_sata_phy_version)of_id->data;
else
priv->version = BRCM_SATA_PHY_STB_28NM;
if (priv->version == BRCM_SATA_PHY_IPROC_NS2) {
res = platform_get_resource_byname(pdev, IORESOURCE_MEM,
"phy-ctrl");
priv->ctrl_base = devm_ioremap_resource(dev, res);
if (IS_ERR(priv->ctrl_base))
return PTR_ERR(priv->ctrl_base);
}
for_each_available_child_of_node(dn, child) {
unsigned int id;
struct brcm_sata_port *port;
if (of_property_read_u32(child, "reg", &id)) {
dev_err(dev, "missing reg property in node %s\n",
child->name);
ret = -EINVAL;
goto put_child;
}
if (id >= MAX_PORTS) {
dev_err(dev, "invalid reg: %u\n", id);
ret = -EINVAL;
goto put_child;
}
if (priv->phys[id].phy) {
dev_err(dev, "already registered port %u\n", id);
ret = -EINVAL;
goto put_child;
}
port = &priv->phys[id];
port->portnum = id;
port->phy_priv = priv;
port->phy = devm_phy_create(dev, child, &phy_ops);
port->ssc_en = of_property_read_bool(child, "brcm,enable-ssc");
if (IS_ERR(port->phy)) {
dev_err(dev, "failed to create PHY\n");
ret = PTR_ERR(port->phy);
goto put_child;
}
phy_set_drvdata(port->phy, port);
count++;
}
provider = devm_of_phy_provider_register(dev, of_phy_simple_xlate);
if (IS_ERR(provider)) {
dev_err(dev, "could not register PHY provider\n");
return PTR_ERR(provider);
}
dev_info(dev, "registered %d port(s)\n", count);
return 0;
put_child:
of_node_put(child);
return ret;
}
