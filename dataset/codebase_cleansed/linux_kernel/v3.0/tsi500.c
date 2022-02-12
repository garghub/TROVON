static int
tsi500_route_add_entry(struct rio_mport *mport, u16 destid, u8 hopcount, u16 table, u16 route_destid, u8 route_port)
{
int i;
u32 offset = 0x10000 + 0xa00 + ((route_destid / 2)&~0x3);
u32 result;
if (table == 0xff) {
rio_mport_read_config_32(mport, destid, hopcount, offset, &result);
result &= ~(0xf << (4*(route_destid & 0x7)));
for (i=0;i<4;i++)
rio_mport_write_config_32(mport, destid, hopcount, offset + (0x20000*i), result | (route_port << (4*(route_destid & 0x7))));
}
else {
rio_mport_read_config_32(mport, destid, hopcount, offset + (0x20000*table), &result);
result &= ~(0xf << (4*(route_destid & 0x7)));
rio_mport_write_config_32(mport, destid, hopcount, offset + (0x20000*table), result | (route_port << (4*(route_destid & 0x7))));
}
return 0;
}
static int
tsi500_route_get_entry(struct rio_mport *mport, u16 destid, u8 hopcount, u16 table, u16 route_destid, u8 *route_port)
{
int ret = 0;
u32 offset = 0x10000 + 0xa00 + ((route_destid / 2)&~0x3);
u32 result;
if (table == 0xff)
rio_mport_read_config_32(mport, destid, hopcount, offset, &result);
else
rio_mport_read_config_32(mport, destid, hopcount, offset + (0x20000*table), &result);
result &= 0xf << (4*(route_destid & 0x7));
*route_port = result >> (4*(route_destid & 0x7));
if (*route_port > 3)
ret = -1;
return ret;
}
static int tsi500_switch_init(struct rio_dev *rdev, int do_enum)
{
pr_debug("RIO: %s for %s\n", __func__, rio_name(rdev));
rdev->rswitch->add_entry = tsi500_route_add_entry;
rdev->rswitch->get_entry = tsi500_route_get_entry;
rdev->rswitch->clr_table = NULL;
rdev->rswitch->set_domain = NULL;
rdev->rswitch->get_domain = NULL;
rdev->rswitch->em_init = NULL;
rdev->rswitch->em_handle = NULL;
return 0;
}
