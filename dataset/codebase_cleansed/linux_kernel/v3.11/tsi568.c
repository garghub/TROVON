static int
tsi568_route_add_entry(struct rio_mport *mport, u16 destid, u8 hopcount,
u16 table, u16 route_destid, u8 route_port)
{
if (table == RIO_GLOBAL_TABLE) {
rio_mport_write_config_32(mport, destid, hopcount,
SPBC_ROUTE_CFG_DESTID, route_destid);
rio_mport_write_config_32(mport, destid, hopcount,
SPBC_ROUTE_CFG_PORT, route_port);
} else {
rio_mport_write_config_32(mport, destid, hopcount,
SPP_ROUTE_CFG_DESTID(table),
route_destid);
rio_mport_write_config_32(mport, destid, hopcount,
SPP_ROUTE_CFG_PORT(table), route_port);
}
udelay(10);
return 0;
}
static int
tsi568_route_get_entry(struct rio_mport *mport, u16 destid, u8 hopcount,
u16 table, u16 route_destid, u8 *route_port)
{
int ret = 0;
u32 result;
if (table == RIO_GLOBAL_TABLE) {
rio_mport_write_config_32(mport, destid, hopcount,
SPBC_ROUTE_CFG_DESTID, route_destid);
rio_mport_read_config_32(mport, destid, hopcount,
SPBC_ROUTE_CFG_PORT, &result);
} else {
rio_mport_write_config_32(mport, destid, hopcount,
SPP_ROUTE_CFG_DESTID(table),
route_destid);
rio_mport_read_config_32(mport, destid, hopcount,
SPP_ROUTE_CFG_PORT(table), &result);
}
*route_port = result;
if (*route_port > 15)
ret = -1;
return ret;
}
static int
tsi568_route_clr_table(struct rio_mport *mport, u16 destid, u8 hopcount,
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
SPP_ROUTE_CFG_DESTID(table),
0x80000000);
for (route_idx = 0; route_idx <= lut_size; route_idx++)
rio_mport_write_config_32(mport, destid, hopcount,
SPP_ROUTE_CFG_PORT(table),
RIO_INVALID_ROUTE);
}
return 0;
}
static int
tsi568_em_init(struct rio_dev *rdev)
{
u32 regval;
int portnum;
pr_debug("TSI568 %s [%d:%d]\n", __func__, rdev->destid, rdev->hopcount);
for (portnum = 0;
portnum < RIO_GET_TOTAL_PORTS(rdev->swpinfo); portnum++) {
rio_read_config_32(rdev, TSI568_SP_MODE(portnum), &regval);
rio_write_config_32(rdev, TSI568_SP_MODE(portnum),
regval | TSI568_SP_MODE_PW_DIS);
}
return 0;
}
static int tsi568_probe(struct rio_dev *rdev, const struct rio_device_id *id)
{
pr_debug("RIO: %s for %s\n", __func__, rio_name(rdev));
spin_lock(&rdev->rswitch->lock);
if (rdev->rswitch->ops) {
spin_unlock(&rdev->rswitch->lock);
return -EINVAL;
}
rdev->rswitch->ops = &tsi568_switch_ops;
spin_unlock(&rdev->rswitch->lock);
return 0;
}
static void tsi568_remove(struct rio_dev *rdev)
{
pr_debug("RIO: %s for %s\n", __func__, rio_name(rdev));
spin_lock(&rdev->rswitch->lock);
if (rdev->rswitch->ops != &tsi568_switch_ops) {
spin_unlock(&rdev->rswitch->lock);
return;
}
rdev->rswitch->ops = NULL;
spin_unlock(&rdev->rswitch->lock);
}
static int __init tsi568_init(void)
{
return rio_register_driver(&tsi568_driver);
}
static void __exit tsi568_exit(void)
{
rio_unregister_driver(&tsi568_driver);
}
