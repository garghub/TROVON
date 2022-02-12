static int
idtg2_route_add_entry(struct rio_mport *mport, u16 destid, u8 hopcount,
u16 table, u16 route_destid, u8 route_port)
{
if (table == RIO_GLOBAL_TABLE)
table = 0;
else
table++;
if (route_port == RIO_INVALID_ROUTE)
route_port = IDT_DEFAULT_ROUTE;
rio_mport_write_config_32(mport, destid, hopcount,
LOCAL_RTE_CONF_DESTID_SEL, table);
rio_mport_write_config_32(mport, destid, hopcount,
RIO_STD_RTE_CONF_DESTID_SEL_CSR,
(u32)route_destid);
rio_mport_write_config_32(mport, destid, hopcount,
RIO_STD_RTE_CONF_PORT_SEL_CSR,
(u32)route_port);
udelay(10);
return 0;
}
static int
idtg2_route_get_entry(struct rio_mport *mport, u16 destid, u8 hopcount,
u16 table, u16 route_destid, u8 *route_port)
{
u32 result;
if (table == RIO_GLOBAL_TABLE)
table = 0;
else
table++;
rio_mport_write_config_32(mport, destid, hopcount,
LOCAL_RTE_CONF_DESTID_SEL, table);
rio_mport_write_config_32(mport, destid, hopcount,
RIO_STD_RTE_CONF_DESTID_SEL_CSR,
route_destid);
rio_mport_read_config_32(mport, destid, hopcount,
RIO_STD_RTE_CONF_PORT_SEL_CSR, &result);
if (IDT_DEFAULT_ROUTE == (u8)result || IDT_NO_ROUTE == (u8)result)
*route_port = RIO_INVALID_ROUTE;
else
*route_port = (u8)result;
return 0;
}
static int
idtg2_route_clr_table(struct rio_mport *mport, u16 destid, u8 hopcount,
u16 table)
{
u32 i;
if (table == RIO_GLOBAL_TABLE)
table = 0;
else
table++;
rio_mport_write_config_32(mport, destid, hopcount,
LOCAL_RTE_CONF_DESTID_SEL, table);
for (i = RIO_STD_RTE_CONF_EXTCFGEN;
i <= (RIO_STD_RTE_CONF_EXTCFGEN | 0xff);) {
rio_mport_write_config_32(mport, destid, hopcount,
RIO_STD_RTE_CONF_DESTID_SEL_CSR, i);
rio_mport_write_config_32(mport, destid, hopcount,
RIO_STD_RTE_CONF_PORT_SEL_CSR,
(IDT_DEFAULT_ROUTE << 24) | (IDT_DEFAULT_ROUTE << 16) |
(IDT_DEFAULT_ROUTE << 8) | IDT_DEFAULT_ROUTE);
i += 4;
}
return 0;
}
static int
idtg2_set_domain(struct rio_mport *mport, u16 destid, u8 hopcount,
u8 sw_domain)
{
rio_mport_write_config_32(mport, destid, hopcount,
IDT_RIO_DOMAIN, (u32)sw_domain);
return 0;
}
static int
idtg2_get_domain(struct rio_mport *mport, u16 destid, u8 hopcount,
u8 *sw_domain)
{
u32 regval;
rio_mport_read_config_32(mport, destid, hopcount,
IDT_RIO_DOMAIN, &regval);
*sw_domain = (u8)(regval & 0xff);
return 0;
}
static int
idtg2_em_init(struct rio_dev *rdev)
{
u32 regval;
int i, tmp;
pr_debug("RIO: %s [%d:%d]\n", __func__, rdev->destid, rdev->hopcount);
rio_write_config_32(rdev, IDT_PW_INFO_CSR, 0x0000e000);
rio_write_config_32(rdev, IDT_LT_ERR_REPORT_EN,
REM_LTL_ERR_ILLTRAN | REM_LTL_ERR_UNSOLR |
REM_LTL_ERR_UNSUPTR);
rio_read_config_32(rdev, IDT_DEV_CTRL_1, &regval);
rio_write_config_32(rdev, IDT_DEV_CTRL_1,
regval | IDT_DEV_CTRL_1_GENPW | IDT_DEV_CTRL_1_PRSTBEH);
rio_write_config_32(rdev, IDT_PORT_ERR_REPORT_EN_BC, 0x807e8037);
rio_write_config_32(rdev, IDT_PORT_ISERR_REPORT_EN_BC,
IDT_PORT_INIT_TX_ACQUIRED);
tmp = RIO_GET_TOTAL_PORTS(rdev->swpinfo);
for (i = 0; i < tmp; i++) {
rio_read_config_32(rdev, IDT_PORT_OPS(i), &regval);
rio_write_config_32(rdev,
IDT_PORT_OPS(i), regval | IDT_PORT_OPS_GENPW |
IDT_PORT_OPS_PL_ELOG |
IDT_PORT_OPS_LL_ELOG |
IDT_PORT_OPS_LT_ELOG);
}
rio_write_config_32(rdev, IDT_ERR_CAP, IDT_ERR_CAP_LOG_OVERWR);
rio_write_config_32(rdev, IDT_LANE_ERR_REPORT_EN_BC, 0);
tmp = (rdev->did == RIO_DID_IDTCPS1848) ? 48 : 16;
for (i = 0; i < tmp; i++) {
rio_read_config_32(rdev, IDT_LANE_CTRL(i), &regval);
rio_write_config_32(rdev, IDT_LANE_CTRL(i),
regval | IDT_LANE_CTRL_GENPW);
}
rio_write_config_32(rdev, IDT_AUX_PORT_ERR_CAP_EN, 0);
rio_write_config_32(rdev, IDT_AUX_ERR_REPORT_EN, 0);
rio_write_config_32(rdev, IDT_JTAG_CTRL, 0);
rio_read_config_32(rdev, IDT_I2C_MCTRL, &regval);
rio_write_config_32(rdev, IDT_I2C_MCTRL, regval & ~IDT_I2C_MCTRL_GENPW);
rio_write_config_32(rdev, IDT_CFGBLK_ERR_CAPTURE_EN, 0);
rio_read_config_32(rdev, IDT_CFGBLK_ERR_REPORT, &regval);
rio_write_config_32(rdev, IDT_CFGBLK_ERR_REPORT,
regval & ~IDT_CFGBLK_ERR_REPORT_GENPW);
rio_write_config_32(rdev,
rdev->phys_efptr + RIO_PORT_LINKTO_CTL_CSR, 0x8e << 8);
return 0;
}
static int
idtg2_em_handler(struct rio_dev *rdev, u8 portnum)
{
u32 regval, em_perrdet, em_ltlerrdet;
rio_read_config_32(rdev,
rdev->em_efptr + RIO_EM_LTL_ERR_DETECT, &em_ltlerrdet);
if (em_ltlerrdet) {
if (em_ltlerrdet & REM_LTL_ERR_IMPSPEC) {
rio_read_config_32(rdev,
IDT_ISLTL_ADDRESS_CAP, &regval);
pr_debug("RIO: %s Implementation Specific LTL errors" \
" 0x%x @(0x%x)\n",
rio_name(rdev), em_ltlerrdet, regval);
rio_write_config_32(rdev, IDT_ISLTL_ADDRESS_CAP, 0);
}
}
rio_read_config_32(rdev,
rdev->em_efptr + RIO_EM_PN_ERR_DETECT(portnum), &em_perrdet);
if (em_perrdet) {
if (em_perrdet & REM_PED_IMPL_SPEC) {
rio_read_config_32(rdev,
IDT_PORT_ISERR_DET(portnum), &regval);
pr_debug("RIO: %s Implementation Specific Port" \
" errors 0x%x\n", rio_name(rdev), regval);
rio_write_config_32(rdev,
IDT_PORT_ISERR_DET(portnum), 0);
}
}
return 0;
}
static ssize_t
idtg2_show_errlog(struct device *dev, struct device_attribute *attr, char *buf)
{
struct rio_dev *rdev = to_rio_dev(dev);
ssize_t len = 0;
u32 regval;
while (!rio_read_config_32(rdev, IDT_ERR_RD, &regval)) {
if (!regval)
break;
len += snprintf(buf + len, PAGE_SIZE - len,
"%08x\n", regval);
if (len >= (PAGE_SIZE - 10))
break;
}
return len;
}
static int idtg2_sysfs(struct rio_dev *rdev, bool create)
{
struct device *dev = &rdev->dev;
int err = 0;
if (create) {
err = device_create_file(dev, &dev_attr_errlog);
if (err)
dev_err(dev, "Unable create sysfs errlog file\n");
} else
device_remove_file(dev, &dev_attr_errlog);
return err;
}
static int idtg2_probe(struct rio_dev *rdev, const struct rio_device_id *id)
{
pr_debug("RIO: %s for %s\n", __func__, rio_name(rdev));
spin_lock(&rdev->rswitch->lock);
if (rdev->rswitch->ops) {
spin_unlock(&rdev->rswitch->lock);
return -EINVAL;
}
rdev->rswitch->ops = &idtg2_switch_ops;
if (rdev->do_enum) {
rio_write_config_32(rdev,
RIO_STD_RTE_DEFAULT_PORT, IDT_NO_ROUTE);
}
spin_unlock(&rdev->rswitch->lock);
idtg2_sysfs(rdev, true);
return 0;
}
static void idtg2_remove(struct rio_dev *rdev)
{
pr_debug("RIO: %s for %s\n", __func__, rio_name(rdev));
spin_lock(&rdev->rswitch->lock);
if (rdev->rswitch->ops != &idtg2_switch_ops) {
spin_unlock(&rdev->rswitch->lock);
return;
}
rdev->rswitch->ops = NULL;
spin_unlock(&rdev->rswitch->lock);
idtg2_sysfs(rdev, false);
}
static int __init idtg2_init(void)
{
return rio_register_driver(&idtg2_driver);
}
static void __exit idtg2_exit(void)
{
pr_debug("RIO: %s\n", __func__);
rio_unregister_driver(&idtg2_driver);
pr_debug("RIO: %s done\n", __func__);
}
