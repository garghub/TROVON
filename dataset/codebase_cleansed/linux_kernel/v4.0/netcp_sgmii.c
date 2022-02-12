static void sgmii_write_reg(void __iomem *base, int reg, u32 val)
{
writel(val, base + reg);
}
static u32 sgmii_read_reg(void __iomem *base, int reg)
{
return readl(base + reg);
}
static void sgmii_write_reg_bit(void __iomem *base, int reg, u32 val)
{
writel((readl(base + reg) | val), base + reg);
}
int netcp_sgmii_reset(void __iomem *sgmii_ofs, int port)
{
sgmii_write_reg_bit(sgmii_ofs, SGMII_SRESET_REG(port), 0x1);
while (sgmii_read_reg(sgmii_ofs, SGMII_SRESET_REG(port)) != 0x0)
;
return 0;
}
int netcp_sgmii_get_port_link(void __iomem *sgmii_ofs, int port)
{
u32 status = 0, link = 0;
status = sgmii_read_reg(sgmii_ofs, SGMII_STATUS_REG(port));
if ((status & SGMII_REG_STATUS_LINK) != 0)
link = 1;
return link;
}
int netcp_sgmii_config(void __iomem *sgmii_ofs, int port, u32 interface)
{
unsigned int i, status, mask;
u32 mr_adv_ability;
u32 control;
switch (interface) {
case SGMII_LINK_MAC_MAC_AUTONEG:
mr_adv_ability = 0x9801;
control = 0x21;
break;
case SGMII_LINK_MAC_PHY:
case SGMII_LINK_MAC_PHY_NO_MDIO:
mr_adv_ability = 1;
control = 1;
break;
case SGMII_LINK_MAC_MAC_FORCED:
mr_adv_ability = 0x9801;
control = 0x20;
break;
case SGMII_LINK_MAC_FIBER:
mr_adv_ability = 0x20;
control = 0x1;
break;
default:
WARN_ONCE(1, "Invalid sgmii interface: %d\n", interface);
return -EINVAL;
}
sgmii_write_reg(sgmii_ofs, SGMII_CTL_REG(port), 0);
for (i = 0; i < 1000; i++) {
usleep_range(1000, 2000);
status = sgmii_read_reg(sgmii_ofs, SGMII_STATUS_REG(port));
if ((status & SGMII_REG_STATUS_LOCK) != 0)
break;
}
if ((status & SGMII_REG_STATUS_LOCK) == 0)
pr_err("serdes PLL not locked\n");
sgmii_write_reg(sgmii_ofs, SGMII_MRADV_REG(port), mr_adv_ability);
sgmii_write_reg(sgmii_ofs, SGMII_CTL_REG(port), control);
mask = SGMII_REG_STATUS_LINK;
if (control & SGMII_REG_CONTROL_AUTONEG)
mask |= SGMII_REG_STATUS_AUTONEG;
for (i = 0; i < 1000; i++) {
usleep_range(200, 500);
status = sgmii_read_reg(sgmii_ofs, SGMII_STATUS_REG(port));
if ((status & mask) == mask)
break;
}
return 0;
}
