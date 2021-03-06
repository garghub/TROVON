static int t1_wait_op_done(adapter_t *adapter, int reg, u32 mask, int polarity,
int attempts, int delay)
{
while (1) {
u32 val = readl(adapter->regs + reg) & mask;
if (!!val == polarity)
return 0;
if (--attempts == 0)
return 1;
if (delay)
udelay(delay);
}
}
int __t1_tpi_write(adapter_t *adapter, u32 addr, u32 value)
{
int tpi_busy;
writel(addr, adapter->regs + A_TPI_ADDR);
writel(value, adapter->regs + A_TPI_WR_DATA);
writel(F_TPIWR, adapter->regs + A_TPI_CSR);
tpi_busy = t1_wait_op_done(adapter, A_TPI_CSR, F_TPIRDY, 1,
TPI_ATTEMPTS, 3);
if (tpi_busy)
pr_alert("%s: TPI write to 0x%x failed\n",
adapter->name, addr);
return tpi_busy;
}
int t1_tpi_write(adapter_t *adapter, u32 addr, u32 value)
{
int ret;
spin_lock(&adapter->tpi_lock);
ret = __t1_tpi_write(adapter, addr, value);
spin_unlock(&adapter->tpi_lock);
return ret;
}
int __t1_tpi_read(adapter_t *adapter, u32 addr, u32 *valp)
{
int tpi_busy;
writel(addr, adapter->regs + A_TPI_ADDR);
writel(0, adapter->regs + A_TPI_CSR);
tpi_busy = t1_wait_op_done(adapter, A_TPI_CSR, F_TPIRDY, 1,
TPI_ATTEMPTS, 3);
if (tpi_busy)
pr_alert("%s: TPI read from 0x%x failed\n",
adapter->name, addr);
else
*valp = readl(adapter->regs + A_TPI_RD_DATA);
return tpi_busy;
}
int t1_tpi_read(adapter_t *adapter, u32 addr, u32 *valp)
{
int ret;
spin_lock(&adapter->tpi_lock);
ret = __t1_tpi_read(adapter, addr, valp);
spin_unlock(&adapter->tpi_lock);
return ret;
}
static void t1_tpi_par(adapter_t *adapter, u32 value)
{
writel(V_TPIPAR(value), adapter->regs + A_TPI_PAR);
}
void t1_link_changed(adapter_t *adapter, int port_id)
{
int link_ok, speed, duplex, fc;
struct cphy *phy = adapter->port[port_id].phy;
struct link_config *lc = &adapter->port[port_id].link_config;
phy->ops->get_link_status(phy, &link_ok, &speed, &duplex, &fc);
lc->speed = speed < 0 ? SPEED_INVALID : speed;
lc->duplex = duplex < 0 ? DUPLEX_INVALID : duplex;
if (!(lc->requested_fc & PAUSE_AUTONEG))
fc = lc->requested_fc & (PAUSE_RX | PAUSE_TX);
if (link_ok && speed >= 0 && lc->autoneg == AUTONEG_ENABLE) {
struct cmac *mac = adapter->port[port_id].mac;
mac->ops->set_speed_duplex_fc(mac, speed, duplex, fc);
lc->fc = (unsigned char)fc;
}
t1_link_negotiated(adapter, port_id, link_ok, speed, duplex, fc);
}
static int t1_pci_intr_handler(adapter_t *adapter)
{
u32 pcix_cause;
pci_read_config_dword(adapter->pdev, A_PCICFG_INTR_CAUSE, &pcix_cause);
if (pcix_cause) {
pci_write_config_dword(adapter->pdev, A_PCICFG_INTR_CAUSE,
pcix_cause);
t1_fatal_err(adapter);
}
return 0;
}
static int fpga_phy_intr_handler(adapter_t *adapter)
{
int p;
u32 cause = readl(adapter->regs + FPGA_GMAC_ADDR_INTERRUPT_CAUSE);
for_each_port(adapter, p)
if (cause & (1 << p)) {
struct cphy *phy = adapter->port[p].phy;
int phy_cause = phy->ops->interrupt_handler(phy);
if (phy_cause & cphy_cause_link_change)
t1_link_changed(adapter, p);
}
writel(cause, adapter->regs + FPGA_GMAC_ADDR_INTERRUPT_CAUSE);
return 0;
}
static int fpga_slow_intr(adapter_t *adapter)
{
u32 cause = readl(adapter->regs + A_PL_CAUSE);
cause &= ~F_PL_INTR_SGE_DATA;
if (cause & F_PL_INTR_SGE_ERR)
t1_sge_intr_error_handler(adapter->sge);
if (cause & FPGA_PCIX_INTERRUPT_GMAC)
fpga_phy_intr_handler(adapter);
if (cause & FPGA_PCIX_INTERRUPT_TP) {
u32 tp_cause = readl(adapter->regs + FPGA_TP_ADDR_INTERRUPT_CAUSE);
writel(tp_cause, adapter->regs + FPGA_TP_ADDR_INTERRUPT_CAUSE);
}
if (cause & FPGA_PCIX_INTERRUPT_PCIX)
t1_pci_intr_handler(adapter);
if (cause)
writel(cause, adapter->regs + A_PL_CAUSE);
return cause != 0;
}
static int mi1_wait_until_ready(adapter_t *adapter, int mi1_reg)
{
int attempts = 100, busy;
do {
u32 val;
__t1_tpi_read(adapter, mi1_reg, &val);
busy = val & F_MI1_OP_BUSY;
if (busy)
udelay(10);
} while (busy && --attempts);
if (busy)
pr_alert("%s: MDIO operation timed out\n", adapter->name);
return busy;
}
static void mi1_mdio_init(adapter_t *adapter, const struct board_info *bi)
{
u32 clkdiv = bi->clock_elmer0 / (2 * bi->mdio_mdc) - 1;
u32 val = F_MI1_PREAMBLE_ENABLE | V_MI1_MDI_INVERT(bi->mdio_mdiinv) |
V_MI1_MDI_ENABLE(bi->mdio_mdien) | V_MI1_CLK_DIV(clkdiv);
if (!(bi->caps & SUPPORTED_10000baseT_Full))
val |= V_MI1_SOF(1);
t1_tpi_write(adapter, A_ELMER0_PORT0_MI1_CFG, val);
}
static int mi1_mdio_read(struct net_device *dev, int phy_addr, int mmd_addr,
u16 reg_addr)
{
struct adapter *adapter = dev->ml_priv;
u32 addr = V_MI1_REG_ADDR(reg_addr) | V_MI1_PHY_ADDR(phy_addr);
unsigned int val;
spin_lock(&adapter->tpi_lock);
__t1_tpi_write(adapter, A_ELMER0_PORT0_MI1_ADDR, addr);
__t1_tpi_write(adapter,
A_ELMER0_PORT0_MI1_OP, MI1_OP_DIRECT_READ);
mi1_wait_until_ready(adapter, A_ELMER0_PORT0_MI1_OP);
__t1_tpi_read(adapter, A_ELMER0_PORT0_MI1_DATA, &val);
spin_unlock(&adapter->tpi_lock);
return val;
}
static int mi1_mdio_write(struct net_device *dev, int phy_addr, int mmd_addr,
u16 reg_addr, u16 val)
{
struct adapter *adapter = dev->ml_priv;
u32 addr = V_MI1_REG_ADDR(reg_addr) | V_MI1_PHY_ADDR(phy_addr);
spin_lock(&adapter->tpi_lock);
__t1_tpi_write(adapter, A_ELMER0_PORT0_MI1_ADDR, addr);
__t1_tpi_write(adapter, A_ELMER0_PORT0_MI1_DATA, val);
__t1_tpi_write(adapter,
A_ELMER0_PORT0_MI1_OP, MI1_OP_DIRECT_WRITE);
mi1_wait_until_ready(adapter, A_ELMER0_PORT0_MI1_OP);
spin_unlock(&adapter->tpi_lock);
return 0;
}
static int mi1_mdio_ext_read(struct net_device *dev, int phy_addr, int mmd_addr,
u16 reg_addr)
{
struct adapter *adapter = dev->ml_priv;
u32 addr = V_MI1_REG_ADDR(mmd_addr) | V_MI1_PHY_ADDR(phy_addr);
unsigned int val;
spin_lock(&adapter->tpi_lock);
__t1_tpi_write(adapter, A_ELMER0_PORT0_MI1_ADDR, addr);
__t1_tpi_write(adapter, A_ELMER0_PORT0_MI1_DATA, reg_addr);
__t1_tpi_write(adapter, A_ELMER0_PORT0_MI1_OP,
MI1_OP_INDIRECT_ADDRESS);
mi1_wait_until_ready(adapter, A_ELMER0_PORT0_MI1_OP);
__t1_tpi_write(adapter,
A_ELMER0_PORT0_MI1_OP, MI1_OP_INDIRECT_READ);
mi1_wait_until_ready(adapter, A_ELMER0_PORT0_MI1_OP);
__t1_tpi_read(adapter, A_ELMER0_PORT0_MI1_DATA, &val);
spin_unlock(&adapter->tpi_lock);
return val;
}
static int mi1_mdio_ext_write(struct net_device *dev, int phy_addr,
int mmd_addr, u16 reg_addr, u16 val)
{
struct adapter *adapter = dev->ml_priv;
u32 addr = V_MI1_REG_ADDR(mmd_addr) | V_MI1_PHY_ADDR(phy_addr);
spin_lock(&adapter->tpi_lock);
__t1_tpi_write(adapter, A_ELMER0_PORT0_MI1_ADDR, addr);
__t1_tpi_write(adapter, A_ELMER0_PORT0_MI1_DATA, reg_addr);
__t1_tpi_write(adapter, A_ELMER0_PORT0_MI1_OP,
MI1_OP_INDIRECT_ADDRESS);
mi1_wait_until_ready(adapter, A_ELMER0_PORT0_MI1_OP);
__t1_tpi_write(adapter, A_ELMER0_PORT0_MI1_DATA, val);
__t1_tpi_write(adapter, A_ELMER0_PORT0_MI1_OP, MI1_OP_INDIRECT_WRITE);
mi1_wait_until_ready(adapter, A_ELMER0_PORT0_MI1_OP);
spin_unlock(&adapter->tpi_lock);
return 0;
}
const struct board_info *t1_get_board_info(unsigned int board_id)
{
return board_id < ARRAY_SIZE(t1_board) ? &t1_board[board_id] : NULL;
}
int t1_seeprom_read(adapter_t *adapter, u32 addr, __le32 *data)
{
int i = EEPROM_MAX_POLL;
u16 val;
u32 v;
if (addr >= EEPROMSIZE || (addr & 3))
return -EINVAL;
pci_write_config_word(adapter->pdev, A_PCICFG_VPD_ADDR, (u16)addr);
do {
udelay(50);
pci_read_config_word(adapter->pdev, A_PCICFG_VPD_ADDR, &val);
} while (!(val & F_VPD_OP_FLAG) && --i);
if (!(val & F_VPD_OP_FLAG)) {
pr_err("%s: reading EEPROM address 0x%x failed\n",
adapter->name, addr);
return -EIO;
}
pci_read_config_dword(adapter->pdev, A_PCICFG_VPD_DATA, &v);
*data = cpu_to_le32(v);
return 0;
}
static int t1_eeprom_vpd_get(adapter_t *adapter, struct chelsio_vpd_t *vpd)
{
int addr, ret = 0;
for (addr = 0; !ret && addr < sizeof(*vpd); addr += sizeof(u32))
ret = t1_seeprom_read(adapter, addr,
(__le32 *)((u8 *)vpd + addr));
return ret;
}
static int vpd_macaddress_get(adapter_t *adapter, int index, u8 mac_addr[])
{
struct chelsio_vpd_t vpd;
if (t1_eeprom_vpd_get(adapter, &vpd))
return 1;
memcpy(mac_addr, vpd.mac_base_address, 5);
mac_addr[5] = vpd.mac_base_address[5] + index;
return 0;
}
int t1_link_start(struct cphy *phy, struct cmac *mac, struct link_config *lc)
{
unsigned int fc = lc->requested_fc & (PAUSE_RX | PAUSE_TX);
if (lc->supported & SUPPORTED_Autoneg) {
lc->advertising &= ~(ADVERTISED_ASYM_PAUSE | ADVERTISED_PAUSE);
if (fc) {
if (fc == ((PAUSE_RX | PAUSE_TX) &
(mac->adapter->params.nports < 2)))
lc->advertising |= ADVERTISED_PAUSE;
else {
lc->advertising |= ADVERTISED_ASYM_PAUSE;
if (fc == PAUSE_RX)
lc->advertising |= ADVERTISED_PAUSE;
}
}
phy->ops->advertise(phy, lc->advertising);
if (lc->autoneg == AUTONEG_DISABLE) {
lc->speed = lc->requested_speed;
lc->duplex = lc->requested_duplex;
lc->fc = (unsigned char)fc;
mac->ops->set_speed_duplex_fc(mac, lc->speed,
lc->duplex, fc);
phy->state = PHY_AUTONEG_RDY;
phy->ops->set_speed_duplex(phy, lc->speed, lc->duplex);
phy->ops->reset(phy, 0);
} else {
phy->state = PHY_AUTONEG_EN;
phy->ops->autoneg_enable(phy);
}
} else {
phy->state = PHY_AUTONEG_RDY;
mac->ops->set_speed_duplex_fc(mac, -1, -1, fc);
lc->fc = (unsigned char)fc;
phy->ops->reset(phy, 0);
}
return 0;
}
int t1_elmer0_ext_intr_handler(adapter_t *adapter)
{
struct cphy *phy;
int phy_cause;
u32 cause;
t1_tpi_read(adapter, A_ELMER0_INT_CAUSE, &cause);
switch (board_info(adapter)->board) {
#ifdef CONFIG_CHELSIO_T1_1G
case CHBT_BOARD_CHT204:
case CHBT_BOARD_CHT204E:
case CHBT_BOARD_CHN204:
case CHBT_BOARD_CHT204V: {
int i, port_bit;
for_each_port(adapter, i) {
port_bit = i + 1;
if (!(cause & (1 << port_bit)))
continue;
phy = adapter->port[i].phy;
phy_cause = phy->ops->interrupt_handler(phy);
if (phy_cause & cphy_cause_link_change)
t1_link_changed(adapter, i);
}
break;
}
case CHBT_BOARD_CHT101:
if (cause & ELMER0_GP_BIT1) {
phy = adapter->port[0].phy;
phy_cause = phy->ops->interrupt_handler(phy);
if (phy_cause & cphy_cause_link_change)
t1_link_changed(adapter, 0);
}
break;
case CHBT_BOARD_7500: {
int p;
for_each_port(adapter, p) {
phy = adapter->port[p].phy;
phy_cause = phy->ops->interrupt_handler(phy);
if (phy_cause & cphy_cause_link_change)
t1_link_changed(adapter, p);
}
break;
}
#endif
case CHBT_BOARD_CHT210:
case CHBT_BOARD_N210:
case CHBT_BOARD_N110:
if (cause & ELMER0_GP_BIT6) {
phy = adapter->port[0].phy;
phy_cause = phy->ops->interrupt_handler(phy);
if (phy_cause & cphy_cause_link_change)
t1_link_changed(adapter, 0);
}
break;
case CHBT_BOARD_8000:
case CHBT_BOARD_CHT110:
if (netif_msg_intr(adapter))
dev_dbg(&adapter->pdev->dev,
"External interrupt cause 0x%x\n", cause);
if (cause & ELMER0_GP_BIT1) {
struct cmac *mac = adapter->port[0].mac;
mac->ops->interrupt_handler(mac);
}
if (cause & ELMER0_GP_BIT5) {
u32 mod_detect;
t1_tpi_read(adapter,
A_ELMER0_GPI_STAT, &mod_detect);
if (netif_msg_link(adapter))
dev_info(&adapter->pdev->dev, "XPAK %s\n",
mod_detect ? "removed" : "inserted");
}
break;
}
t1_tpi_write(adapter, A_ELMER0_INT_CAUSE, cause);
return 0;
}
void t1_interrupts_enable(adapter_t *adapter)
{
unsigned int i;
adapter->slow_intr_mask = F_PL_INTR_SGE_ERR | F_PL_INTR_TP;
t1_sge_intr_enable(adapter->sge);
t1_tp_intr_enable(adapter->tp);
if (adapter->espi) {
adapter->slow_intr_mask |= F_PL_INTR_ESPI;
t1_espi_intr_enable(adapter->espi);
}
for_each_port(adapter, i) {
adapter->port[i].mac->ops->interrupt_enable(adapter->port[i].mac);
adapter->port[i].phy->ops->interrupt_enable(adapter->port[i].phy);
}
if (t1_is_asic(adapter)) {
u32 pl_intr = readl(adapter->regs + A_PL_ENABLE);
pci_write_config_dword(adapter->pdev, A_PCICFG_INTR_ENABLE,
0xffffffff);
adapter->slow_intr_mask |= F_PL_INTR_EXT | F_PL_INTR_PCIX;
pl_intr |= F_PL_INTR_EXT | F_PL_INTR_PCIX;
writel(pl_intr, adapter->regs + A_PL_ENABLE);
}
}
void t1_interrupts_disable(adapter_t* adapter)
{
unsigned int i;
t1_sge_intr_disable(adapter->sge);
t1_tp_intr_disable(adapter->tp);
if (adapter->espi)
t1_espi_intr_disable(adapter->espi);
for_each_port(adapter, i) {
adapter->port[i].mac->ops->interrupt_disable(adapter->port[i].mac);
adapter->port[i].phy->ops->interrupt_disable(adapter->port[i].phy);
}
if (t1_is_asic(adapter))
writel(0, adapter->regs + A_PL_ENABLE);
pci_write_config_dword(adapter->pdev, A_PCICFG_INTR_ENABLE, 0);
adapter->slow_intr_mask = 0;
}
void t1_interrupts_clear(adapter_t* adapter)
{
unsigned int i;
t1_sge_intr_clear(adapter->sge);
t1_tp_intr_clear(adapter->tp);
if (adapter->espi)
t1_espi_intr_clear(adapter->espi);
for_each_port(adapter, i) {
adapter->port[i].mac->ops->interrupt_clear(adapter->port[i].mac);
adapter->port[i].phy->ops->interrupt_clear(adapter->port[i].phy);
}
if (t1_is_asic(adapter)) {
u32 pl_intr = readl(adapter->regs + A_PL_CAUSE);
writel(pl_intr | F_PL_INTR_EXT | F_PL_INTR_PCIX,
adapter->regs + A_PL_CAUSE);
}
pci_write_config_dword(adapter->pdev, A_PCICFG_INTR_CAUSE, 0xffffffff);
}
static int asic_slow_intr(adapter_t *adapter)
{
u32 cause = readl(adapter->regs + A_PL_CAUSE);
cause &= adapter->slow_intr_mask;
if (!cause)
return 0;
if (cause & F_PL_INTR_SGE_ERR)
t1_sge_intr_error_handler(adapter->sge);
if (cause & F_PL_INTR_TP)
t1_tp_intr_handler(adapter->tp);
if (cause & F_PL_INTR_ESPI)
t1_espi_intr_handler(adapter->espi);
if (cause & F_PL_INTR_PCIX)
t1_pci_intr_handler(adapter);
if (cause & F_PL_INTR_EXT)
t1_elmer0_ext_intr(adapter);
writel(cause, adapter->regs + A_PL_CAUSE);
readl(adapter->regs + A_PL_CAUSE);
return 1;
}
int t1_slow_intr_handler(adapter_t *adapter)
{
#ifdef CONFIG_CHELSIO_T1_1G
if (!t1_is_asic(adapter))
return fpga_slow_intr(adapter);
#endif
return asic_slow_intr(adapter);
}
static void power_sequence_xpak(adapter_t* adapter)
{
u32 mod_detect;
u32 gpo;
t1_tpi_read(adapter, A_ELMER0_GPI_STAT, &mod_detect);
if (!(ELMER0_GP_BIT5 & mod_detect)) {
t1_tpi_read(adapter, A_ELMER0_GPO, &gpo);
gpo |= ELMER0_GP_BIT18;
t1_tpi_write(adapter, A_ELMER0_GPO, gpo);
}
}
int __devinit t1_get_board_rev(adapter_t *adapter, const struct board_info *bi,
struct adapter_params *p)
{
p->chip_version = bi->chip_term;
p->is_asic = (p->chip_version != CHBT_TERM_FPGA);
if (p->chip_version == CHBT_TERM_T1 ||
p->chip_version == CHBT_TERM_T2 ||
p->chip_version == CHBT_TERM_FPGA) {
u32 val = readl(adapter->regs + A_TP_PC_CONFIG);
val = G_TP_PC_REV(val);
if (val == 2)
p->chip_revision = TERM_T1B;
else if (val == 3)
p->chip_revision = TERM_T2;
else
return -1;
} else
return -1;
return 0;
}
static int board_init(adapter_t *adapter, const struct board_info *bi)
{
switch (bi->board) {
case CHBT_BOARD_8000:
case CHBT_BOARD_N110:
case CHBT_BOARD_N210:
case CHBT_BOARD_CHT210:
t1_tpi_par(adapter, 0xf);
t1_tpi_write(adapter, A_ELMER0_GPO, 0x800);
break;
case CHBT_BOARD_CHT110:
t1_tpi_par(adapter, 0xf);
t1_tpi_write(adapter, A_ELMER0_GPO, 0x1800);
power_sequence_xpak(adapter);
break;
#ifdef CONFIG_CHELSIO_T1_1G
case CHBT_BOARD_CHT204E:
case CHBT_BOARD_CHT204:
case CHBT_BOARD_CHT204V:
case CHBT_BOARD_CHN204:
t1_tpi_par(adapter, 0xf);
t1_tpi_write(adapter, A_ELMER0_GPO, 0x804);
break;
case CHBT_BOARD_CHT101:
case CHBT_BOARD_7500:
t1_tpi_par(adapter, 0xf);
t1_tpi_write(adapter, A_ELMER0_GPO, 0x1804);
break;
#endif
}
return 0;
}
int t1_init_hw_modules(adapter_t *adapter)
{
int err = -EIO;
const struct board_info *bi = board_info(adapter);
if (!bi->clock_mc4) {
u32 val = readl(adapter->regs + A_MC4_CFG);
writel(val | F_READY | F_MC4_SLOW, adapter->regs + A_MC4_CFG);
writel(F_M_BUS_ENABLE | F_TCAM_RESET,
adapter->regs + A_MC5_CONFIG);
}
if (adapter->espi && t1_espi_init(adapter->espi, bi->chip_mac,
bi->espi_nports))
goto out_err;
if (t1_tp_reset(adapter->tp, &adapter->params.tp, bi->clock_core))
goto out_err;
err = t1_sge_configure(adapter->sge, &adapter->params.sge);
if (err)
goto out_err;
err = 0;
out_err:
return err;
}
static void __devinit get_pci_mode(adapter_t *adapter, struct chelsio_pci_params *p)
{
static const unsigned short speed_map[] = { 33, 66, 100, 133 };
u32 pci_mode;
pci_read_config_dword(adapter->pdev, A_PCICFG_MODE, &pci_mode);
p->speed = speed_map[G_PCI_MODE_CLK(pci_mode)];
p->width = (pci_mode & F_PCI_MODE_64BIT) ? 64 : 32;
p->is_pcix = (pci_mode & F_PCI_MODE_PCIX) != 0;
}
void t1_free_sw_modules(adapter_t *adapter)
{
unsigned int i;
for_each_port(adapter, i) {
struct cmac *mac = adapter->port[i].mac;
struct cphy *phy = adapter->port[i].phy;
if (mac)
mac->ops->destroy(mac);
if (phy)
phy->ops->destroy(phy);
}
if (adapter->sge)
t1_sge_destroy(adapter->sge);
if (adapter->tp)
t1_tp_destroy(adapter->tp);
if (adapter->espi)
t1_espi_destroy(adapter->espi);
}
static void __devinit init_link_config(struct link_config *lc,
const struct board_info *bi)
{
lc->supported = bi->caps;
lc->requested_speed = lc->speed = SPEED_INVALID;
lc->requested_duplex = lc->duplex = DUPLEX_INVALID;
lc->requested_fc = lc->fc = PAUSE_RX | PAUSE_TX;
if (lc->supported & SUPPORTED_Autoneg) {
lc->advertising = lc->supported;
lc->autoneg = AUTONEG_ENABLE;
lc->requested_fc |= PAUSE_AUTONEG;
} else {
lc->advertising = 0;
lc->autoneg = AUTONEG_DISABLE;
}
}
int __devinit t1_init_sw_modules(adapter_t *adapter,
const struct board_info *bi)
{
unsigned int i;
adapter->params.brd_info = bi;
adapter->params.nports = bi->port_number;
adapter->params.stats_update_period = bi->gmac->stats_update_period;
adapter->sge = t1_sge_create(adapter, &adapter->params.sge);
if (!adapter->sge) {
pr_err("%s: SGE initialization failed\n",
adapter->name);
goto error;
}
if (bi->espi_nports && !(adapter->espi = t1_espi_create(adapter))) {
pr_err("%s: ESPI initialization failed\n",
adapter->name);
goto error;
}
adapter->tp = t1_tp_create(adapter, &adapter->params.tp);
if (!adapter->tp) {
pr_err("%s: TP initialization failed\n",
adapter->name);
goto error;
}
board_init(adapter, bi);
bi->mdio_ops->init(adapter, bi);
if (bi->gphy->reset)
bi->gphy->reset(adapter);
if (bi->gmac->reset)
bi->gmac->reset(adapter);
for_each_port(adapter, i) {
u8 hw_addr[6];
struct cmac *mac;
int phy_addr = bi->mdio_phybaseaddr + i;
adapter->port[i].phy = bi->gphy->create(adapter->port[i].dev,
phy_addr, bi->mdio_ops);
if (!adapter->port[i].phy) {
pr_err("%s: PHY %d initialization failed\n",
adapter->name, i);
goto error;
}
adapter->port[i].mac = mac = bi->gmac->create(adapter, i);
if (!mac) {
pr_err("%s: MAC %d initialization failed\n",
adapter->name, i);
goto error;
}
if (!t1_is_asic(adapter) || bi->chip_mac == CHBT_MAC_DUMMY)
mac->ops->macaddress_get(mac, hw_addr);
else if (vpd_macaddress_get(adapter, i, hw_addr)) {
pr_err("%s: could not read MAC address from VPD ROM\n",
adapter->port[i].dev->name);
goto error;
}
memcpy(adapter->port[i].dev->dev_addr, hw_addr, ETH_ALEN);
init_link_config(&adapter->port[i].link_config, bi);
}
get_pci_mode(adapter, &adapter->params.pci);
t1_interrupts_clear(adapter);
return 0;
error:
t1_free_sw_modules(adapter);
return -1;
}
