static int
tsi57x_route_add_entry(struct rio_mport *mport, u16 destid, u8 hopcount,
u16 table, u16 route_destid, u8 route_port)
{
if (table == RIO_GLOBAL_TABLE) {
rio_mport_write_config_32(mport, destid, hopcount,
SPBC_ROUTE_CFG_DESTID, route_destid);
rio_mport_write_config_32(mport, destid, hopcount,
SPBC_ROUTE_CFG_PORT, route_port);
} else {
rio_mport_write_config_32(mport, destid, hopcount,
SPP_ROUTE_CFG_DESTID(table), route_destid);
rio_mport_write_config_32(mport, destid, hopcount,
SPP_ROUTE_CFG_PORT(table), route_port);
}
udelay(10);
return 0;
}
static int
tsi57x_route_get_entry(struct rio_mport *mport, u16 destid, u8 hopcount,
u16 table, u16 route_destid, u8 *route_port)
{
int ret = 0;
u32 result;
if (table == RIO_GLOBAL_TABLE) {
rio_mport_read_config_32(mport, destid, hopcount,
RIO_SWP_INFO_CAR, &result);
table = (result & RIO_SWP_INFO_PORT_NUM_MASK);
}
rio_mport_write_config_32(mport, destid, hopcount,
SPP_ROUTE_CFG_DESTID(table), route_destid);
rio_mport_read_config_32(mport, destid, hopcount,
SPP_ROUTE_CFG_PORT(table), &result);
*route_port = (u8)result;
if (*route_port > 15)
ret = -1;
return ret;
}
static int
tsi57x_route_clr_table(struct rio_mport *mport, u16 destid, u8 hopcount,
u16 table)
{
u32 route_idx;
u32 lut_size;
lut_size = (mport->sys_size) ? 0x1ff : 0xff;
if (table == RIO_GLOBAL_TABLE) {
rio_mport_write_config_32(mport, destid, hopcount,
SPBC_ROUTE_CFG_DESTID, 0x80000000);
for (route_idx = 0; route_idx <= lut_size; route_idx++)
rio_mport_write_config_32(mport, destid, hopcount,
SPBC_ROUTE_CFG_PORT,
RIO_INVALID_ROUTE);
} else {
rio_mport_write_config_32(mport, destid, hopcount,
SPP_ROUTE_CFG_DESTID(table), 0x80000000);
for (route_idx = 0; route_idx <= lut_size; route_idx++)
rio_mport_write_config_32(mport, destid, hopcount,
SPP_ROUTE_CFG_PORT(table) , RIO_INVALID_ROUTE);
}
return 0;
}
static int
tsi57x_set_domain(struct rio_mport *mport, u16 destid, u8 hopcount,
u8 sw_domain)
{
u32 regval;
rio_mport_read_config_32(mport, destid, hopcount,
TSI578_SP_MODE_GLBL, &regval);
rio_mport_write_config_32(mport, destid, hopcount, TSI578_SP_MODE_GLBL,
regval & ~TSI578_SP_MODE_LUT_512);
rio_mport_write_config_32(mport, destid, hopcount,
TSI578_GLBL_ROUTE_BASE,
(u32)(sw_domain << 24));
return 0;
}
static int
tsi57x_get_domain(struct rio_mport *mport, u16 destid, u8 hopcount,
u8 *sw_domain)
{
u32 regval;
rio_mport_read_config_32(mport, destid, hopcount,
TSI578_GLBL_ROUTE_BASE, &regval);
*sw_domain = (u8)(regval >> 24);
return 0;
}
static int
tsi57x_em_init(struct rio_dev *rdev)
{
u32 regval;
int portnum;
pr_debug("TSI578 %s [%d:%d]\n", __func__, rdev->destid, rdev->hopcount);
for (portnum = 0;
portnum < RIO_GET_TOTAL_PORTS(rdev->swpinfo); portnum++) {
rio_read_config_32(rdev,
TSI578_SP_MODE(portnum), &regval);
rio_write_config_32(rdev,
TSI578_SP_MODE(portnum),
regval & ~TSI578_SP_MODE_PW_DIS);
rio_read_config_32(rdev,
rdev->phys_efptr +
RIO_PORT_N_ERR_STS_CSR(portnum),
&regval);
rio_write_config_32(rdev,
rdev->phys_efptr +
RIO_PORT_N_ERR_STS_CSR(portnum),
regval & 0x07120214);
rio_read_config_32(rdev,
TSI578_SP_INT_STATUS(portnum), &regval);
rio_write_config_32(rdev,
TSI578_SP_INT_STATUS(portnum),
regval & 0x000700bd);
rio_read_config_32(rdev,
TSI578_SP_CTL_INDEP(portnum), &regval);
rio_write_config_32(rdev,
TSI578_SP_CTL_INDEP(portnum),
regval | 0x000b0000);
rio_read_config_32(rdev,
rdev->phys_efptr + RIO_PORT_N_CTL_CSR(portnum),
&regval);
if ((regval & RIO_PORT_N_CTL_PWIDTH) == RIO_PORT_N_CTL_PWIDTH_4)
portnum++;
}
rio_write_config_32(rdev,
rdev->phys_efptr + RIO_PORT_LINKTO_CTL_CSR, 0x9a << 8);
return 0;
}
static int
tsi57x_em_handler(struct rio_dev *rdev, u8 portnum)
{
struct rio_mport *mport = rdev->net->hport;
u32 intstat, err_status;
int sendcount, checkcount;
u8 route_port;
u32 regval;
rio_read_config_32(rdev,
rdev->phys_efptr + RIO_PORT_N_ERR_STS_CSR(portnum),
&err_status);
if ((err_status & RIO_PORT_N_ERR_STS_PORT_OK) &&
(err_status & (RIO_PORT_N_ERR_STS_PW_OUT_ES |
RIO_PORT_N_ERR_STS_PW_INP_ES))) {
rio_read_config_32(rdev,
rdev->phys_efptr + RIO_PORT_N_CTL_CSR(portnum),
&regval);
if (!(regval & RIO_PORT_N_CTL_LOCKOUT)) {
rio_write_config_32(rdev,
rdev->phys_efptr + RIO_PORT_N_CTL_CSR(portnum),
regval | RIO_PORT_N_CTL_LOCKOUT);
udelay(50);
rio_write_config_32(rdev,
rdev->phys_efptr + RIO_PORT_N_CTL_CSR(portnum),
regval);
}
rio_read_config_32(rdev,
rdev->phys_efptr + RIO_PORT_N_MNT_RSP_CSR(portnum),
&regval);
sendcount = 3;
while (sendcount) {
rio_write_config_32(rdev,
TSI578_SP_CS_TX(portnum), 0x40fc8000);
checkcount = 3;
while (checkcount--) {
udelay(50);
rio_read_config_32(rdev,
rdev->phys_efptr +
RIO_PORT_N_MNT_RSP_CSR(portnum),
&regval);
if (regval & RIO_PORT_N_MNT_RSP_RVAL)
goto exit_es;
}
sendcount--;
}
}
exit_es:
rio_read_config_32(rdev, TSI578_SP_INT_STATUS(portnum), &intstat);
pr_debug("TSI578[%x:%x] SP%d_INT_STATUS=0x%08x\n",
rdev->destid, rdev->hopcount, portnum, intstat);
if (intstat & 0x10000) {
rio_read_config_32(rdev,
TSI578_SP_LUT_PEINF(portnum), &regval);
regval = (mport->sys_size) ? (regval >> 16) : (regval >> 24);
route_port = rdev->rswitch->route_table[regval];
pr_debug("RIO: TSI578[%s] P%d LUT Parity Error (destID=%d)\n",
rio_name(rdev), portnum, regval);
tsi57x_route_add_entry(mport, rdev->destid, rdev->hopcount,
RIO_GLOBAL_TABLE, regval, route_port);
}
rio_write_config_32(rdev, TSI578_SP_INT_STATUS(portnum),
intstat & 0x000700bd);
return 0;
}
static int tsi57x_probe(struct rio_dev *rdev, const struct rio_device_id *id)
{
pr_debug("RIO: %s for %s\n", __func__, rio_name(rdev));
spin_lock(&rdev->rswitch->lock);
if (rdev->rswitch->ops) {
spin_unlock(&rdev->rswitch->lock);
return -EINVAL;
}
rdev->rswitch->ops = &tsi57x_switch_ops;
if (rdev->do_enum) {
rio_write_config_32(rdev, RIO_STD_RTE_DEFAULT_PORT,
RIO_INVALID_ROUTE);
}
spin_unlock(&rdev->rswitch->lock);
return 0;
}
static void tsi57x_remove(struct rio_dev *rdev)
{
pr_debug("RIO: %s for %s\n", __func__, rio_name(rdev));
spin_lock(&rdev->rswitch->lock);
if (rdev->rswitch->ops != &tsi57x_switch_ops) {
spin_unlock(&rdev->rswitch->lock);
return;
}
rdev->rswitch->ops = NULL;
spin_unlock(&rdev->rswitch->lock);
}
static int __init tsi57x_init(void)
{
return rio_register_driver(&tsi57x_driver);
}
static void __exit tsi57x_exit(void)
{
rio_unregister_driver(&tsi57x_driver);
}
