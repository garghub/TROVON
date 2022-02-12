static int led_init(struct cphy *cphy)
{
cphy_mdio_write(cphy, MDIO_MMD_PCS, 0x8304, 0xdddd);
return 0;
}
static int led_link(struct cphy *cphy, u32 do_enable)
{
u32 led = 0;
#define LINK_ENABLE_BIT 0x1
cphy_mdio_read(cphy, MDIO_MMD_PMAPMD, MDIO_CTRL2, &led);
if (do_enable & LINK_ENABLE_BIT) {
led |= LINK_ENABLE_BIT;
cphy_mdio_write(cphy, MDIO_MMD_PMAPMD, MDIO_CTRL2, led);
} else {
led &= ~LINK_ENABLE_BIT;
cphy_mdio_write(cphy, MDIO_MMD_PMAPMD, MDIO_CTRL2, led);
}
return 0;
}
static int mv88x201x_reset(struct cphy *cphy, int wait)
{
return 0;
}
static int mv88x201x_interrupt_enable(struct cphy *cphy)
{
cphy_mdio_write(cphy, MDIO_MMD_PMAPMD, MDIO_PMA_LASI_CTRL,
MDIO_PMA_LASI_LSALARM);
if (t1_is_asic(cphy->adapter)) {
u32 elmer;
t1_tpi_read(cphy->adapter, A_ELMER0_INT_ENABLE, &elmer);
elmer |= ELMER0_GP_BIT6;
t1_tpi_write(cphy->adapter, A_ELMER0_INT_ENABLE, elmer);
}
return 0;
}
static int mv88x201x_interrupt_disable(struct cphy *cphy)
{
cphy_mdio_write(cphy, MDIO_MMD_PMAPMD, MDIO_PMA_LASI_CTRL, 0x0);
if (t1_is_asic(cphy->adapter)) {
u32 elmer;
t1_tpi_read(cphy->adapter, A_ELMER0_INT_ENABLE, &elmer);
elmer &= ~ELMER0_GP_BIT6;
t1_tpi_write(cphy->adapter, A_ELMER0_INT_ENABLE, elmer);
}
return 0;
}
static int mv88x201x_interrupt_clear(struct cphy *cphy)
{
u32 elmer;
u32 val;
#ifdef MV88x2010_LINK_STATUS_BUGS
cphy_mdio_read(cphy, MDIO_MMD_PMAPMD, MDIO_PMA_LASI_RXSTAT, &val);
cphy_mdio_read(cphy, MDIO_MMD_PMAPMD, MDIO_PMA_LASI_TXSTAT, &val);
cphy_mdio_read(cphy, MDIO_MMD_PMAPMD, MDIO_PMA_LASI_STAT, &val);
cphy_mdio_read(cphy, MDIO_MMD_PMAPMD, MDIO_STAT1, &val);
#endif
cphy_mdio_read(cphy, MDIO_MMD_PMAPMD, MDIO_STAT1, &val);
cphy_mdio_read(cphy, MDIO_MMD_PMAPMD, MDIO_PMA_LASI_STAT, &val);
#ifdef MV88x2010_LINK_STATUS_BUGS
cphy_mdio_read(cphy, MDIO_MMD_PMAPMD, MDIO_PMA_LASI_RXSTAT, &val);
cphy_mdio_read(cphy, MDIO_MMD_PMAPMD, MDIO_PMA_LASI_TXSTAT, &val);
#endif
if (t1_is_asic(cphy->adapter)) {
t1_tpi_read(cphy->adapter, A_ELMER0_INT_CAUSE, &elmer);
elmer |= ELMER0_GP_BIT6;
t1_tpi_write(cphy->adapter, A_ELMER0_INT_CAUSE, elmer);
}
return 0;
}
static int mv88x201x_interrupt_handler(struct cphy *cphy)
{
mv88x201x_interrupt_clear(cphy);
return cphy_cause_link_change;
}
static int mv88x201x_set_loopback(struct cphy *cphy, int on)
{
return 0;
}
static int mv88x201x_get_link_status(struct cphy *cphy, int *link_ok,
int *speed, int *duplex, int *fc)
{
u32 val = 0;
if (link_ok) {
cphy_mdio_read(cphy, MDIO_MMD_PMAPMD, MDIO_STAT1, &val);
val &= MDIO_STAT1_LSTATUS;
*link_ok = (val == MDIO_STAT1_LSTATUS);
led_link(cphy, *link_ok);
}
if (speed)
*speed = SPEED_10000;
if (duplex)
*duplex = DUPLEX_FULL;
if (fc)
*fc = PAUSE_RX | PAUSE_TX;
return 0;
}
static void mv88x201x_destroy(struct cphy *cphy)
{
kfree(cphy);
}
static struct cphy *mv88x201x_phy_create(struct net_device *dev, int phy_addr,
const struct mdio_ops *mdio_ops)
{
u32 val;
struct cphy *cphy = kzalloc(sizeof(*cphy), GFP_KERNEL);
if (!cphy)
return NULL;
cphy_init(cphy, dev, phy_addr, &mv88x201x_ops, mdio_ops);
cphy_mdio_read(cphy, MDIO_MMD_PCS, 0x8300, &val);
cphy_mdio_write(cphy, MDIO_MMD_PCS, 0x8300, val | 1);
cphy_mdio_read(cphy, MDIO_MMD_PMAPMD, MDIO_STAT2, &val);
cphy_mdio_read(cphy, MDIO_MMD_PCS, MDIO_STAT2, &val);
led_init(cphy);
return cphy;
}
static int mv88x201x_phy_reset(adapter_t *adapter)
{
u32 val;
t1_tpi_read(adapter, A_ELMER0_GPO, &val);
val &= ~4;
t1_tpi_write(adapter, A_ELMER0_GPO, val);
msleep(100);
t1_tpi_write(adapter, A_ELMER0_GPO, val | 4);
msleep(1000);
t1_tpi_read(adapter, A_ELMER0_GPO, &val);
val |= 0x8000;
t1_tpi_write(adapter, A_ELMER0_GPO, val);
udelay(100);
return 0;
}
