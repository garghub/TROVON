static u16 rio_destid_alloc(struct rio_net *net)
{
int destid;
struct rio_id_table *idtab = (struct rio_id_table *)net->enum_data;
spin_lock(&idtab->lock);
destid = find_first_zero_bit(idtab->table, idtab->max);
if (destid < idtab->max) {
set_bit(destid, idtab->table);
destid += idtab->start;
} else
destid = RIO_INVALID_DESTID;
spin_unlock(&idtab->lock);
return (u16)destid;
}
static int rio_destid_reserve(struct rio_net *net, u16 destid)
{
int oldbit;
struct rio_id_table *idtab = (struct rio_id_table *)net->enum_data;
destid -= idtab->start;
spin_lock(&idtab->lock);
oldbit = test_and_set_bit(destid, idtab->table);
spin_unlock(&idtab->lock);
return oldbit;
}
static void rio_destid_free(struct rio_net *net, u16 destid)
{
struct rio_id_table *idtab = (struct rio_id_table *)net->enum_data;
destid -= idtab->start;
spin_lock(&idtab->lock);
clear_bit(destid, idtab->table);
spin_unlock(&idtab->lock);
}
static u16 rio_destid_first(struct rio_net *net)
{
int destid;
struct rio_id_table *idtab = (struct rio_id_table *)net->enum_data;
spin_lock(&idtab->lock);
destid = find_first_bit(idtab->table, idtab->max);
if (destid >= idtab->max)
destid = RIO_INVALID_DESTID;
else
destid += idtab->start;
spin_unlock(&idtab->lock);
return (u16)destid;
}
static u16 rio_destid_next(struct rio_net *net, u16 from)
{
int destid;
struct rio_id_table *idtab = (struct rio_id_table *)net->enum_data;
spin_lock(&idtab->lock);
destid = find_next_bit(idtab->table, idtab->max, from);
if (destid >= idtab->max)
destid = RIO_INVALID_DESTID;
else
destid += idtab->start;
spin_unlock(&idtab->lock);
return (u16)destid;
}
static u16 rio_get_device_id(struct rio_mport *port, u16 destid, u8 hopcount)
{
u32 result;
rio_mport_read_config_32(port, destid, hopcount, RIO_DID_CSR, &result);
return RIO_GET_DID(port->sys_size, result);
}
static void rio_set_device_id(struct rio_mport *port, u16 destid, u8 hopcount, u16 did)
{
rio_mport_write_config_32(port, destid, hopcount, RIO_DID_CSR,
RIO_SET_DID(port->sys_size, did));
}
static int rio_clear_locks(struct rio_net *net)
{
struct rio_mport *port = net->hport;
struct rio_dev *rdev;
u32 result;
int ret = 0;
rio_local_write_config_32(port, RIO_HOST_DID_LOCK_CSR,
port->host_deviceid);
rio_local_read_config_32(port, RIO_HOST_DID_LOCK_CSR, &result);
if ((result & 0xffff) != 0xffff) {
printk(KERN_INFO
"RIO: badness when releasing host lock on master port, result %8.8x\n",
result);
ret = -EINVAL;
}
list_for_each_entry(rdev, &net->devices, net_list) {
rio_write_config_32(rdev, RIO_HOST_DID_LOCK_CSR,
port->host_deviceid);
rio_read_config_32(rdev, RIO_HOST_DID_LOCK_CSR, &result);
if ((result & 0xffff) != 0xffff) {
printk(KERN_INFO
"RIO: badness when releasing host lock on vid %4.4x did %4.4x\n",
rdev->vid, rdev->did);
ret = -EINVAL;
}
rio_read_config_32(rdev,
rdev->phys_efptr + RIO_PORT_GEN_CTL_CSR,
&result);
result |= RIO_PORT_GEN_DISCOVERED | RIO_PORT_GEN_MASTER;
rio_write_config_32(rdev,
rdev->phys_efptr + RIO_PORT_GEN_CTL_CSR,
result);
}
return ret;
}
static int rio_enum_host(struct rio_mport *port)
{
u32 result;
rio_local_write_config_32(port, RIO_HOST_DID_LOCK_CSR,
port->host_deviceid);
rio_local_read_config_32(port, RIO_HOST_DID_LOCK_CSR, &result);
if ((result & 0xffff) != port->host_deviceid)
return -1;
rio_local_set_device_id(port, port->host_deviceid);
return 0;
}
static int rio_device_has_destid(struct rio_mport *port, int src_ops,
int dst_ops)
{
u32 mask = RIO_OPS_READ | RIO_OPS_WRITE | RIO_OPS_ATOMIC_TST_SWP | RIO_OPS_ATOMIC_INC | RIO_OPS_ATOMIC_DEC | RIO_OPS_ATOMIC_SET | RIO_OPS_ATOMIC_CLR;
return !!((src_ops | dst_ops) & mask);
}
static void rio_release_dev(struct device *dev)
{
struct rio_dev *rdev;
rdev = to_rio_dev(dev);
kfree(rdev);
}
static int rio_is_switch(struct rio_dev *rdev)
{
if (rdev->pef & RIO_PEF_SWITCH)
return 1;
return 0;
}
static struct rio_dev *rio_setup_device(struct rio_net *net,
struct rio_mport *port, u16 destid,
u8 hopcount, int do_enum)
{
int ret = 0;
struct rio_dev *rdev;
struct rio_switch *rswitch = NULL;
int result, rdid;
size_t size;
u32 swpinfo = 0;
size = sizeof(struct rio_dev);
if (rio_mport_read_config_32(port, destid, hopcount,
RIO_PEF_CAR, &result))
return NULL;
if (result & (RIO_PEF_SWITCH | RIO_PEF_MULTIPORT)) {
rio_mport_read_config_32(port, destid, hopcount,
RIO_SWP_INFO_CAR, &swpinfo);
if (result & RIO_PEF_SWITCH) {
size += (RIO_GET_TOTAL_PORTS(swpinfo) *
sizeof(rswitch->nextdev[0])) + sizeof(*rswitch);
}
}
rdev = kzalloc(size, GFP_KERNEL);
if (!rdev)
return NULL;
rdev->net = net;
rdev->pef = result;
rdev->swpinfo = swpinfo;
rio_mport_read_config_32(port, destid, hopcount, RIO_DEV_ID_CAR,
&result);
rdev->did = result >> 16;
rdev->vid = result & 0xffff;
rio_mport_read_config_32(port, destid, hopcount, RIO_DEV_INFO_CAR,
&rdev->device_rev);
rio_mport_read_config_32(port, destid, hopcount, RIO_ASM_ID_CAR,
&result);
rdev->asm_did = result >> 16;
rdev->asm_vid = result & 0xffff;
rio_mport_read_config_32(port, destid, hopcount, RIO_ASM_INFO_CAR,
&result);
rdev->asm_rev = result >> 16;
if (rdev->pef & RIO_PEF_EXT_FEATURES) {
rdev->efptr = result & 0xffff;
rdev->phys_efptr = rio_mport_get_physefb(port, 0, destid,
hopcount);
rdev->em_efptr = rio_mport_get_feature(port, 0, destid,
hopcount, RIO_EFB_ERR_MGMNT);
}
rio_mport_read_config_32(port, destid, hopcount, RIO_SRC_OPS_CAR,
&rdev->src_ops);
rio_mport_read_config_32(port, destid, hopcount, RIO_DST_OPS_CAR,
&rdev->dst_ops);
if (do_enum) {
if (next_comptag >= 0x10000) {
pr_err("RIO: Component Tag Counter Overflow\n");
goto cleanup;
}
rio_mport_write_config_32(port, destid, hopcount,
RIO_COMPONENT_TAG_CSR, next_comptag);
rdev->comp_tag = next_comptag++;
rdev->do_enum = true;
} else {
rio_mport_read_config_32(port, destid, hopcount,
RIO_COMPONENT_TAG_CSR,
&rdev->comp_tag);
}
if (rio_device_has_destid(port, rdev->src_ops, rdev->dst_ops)) {
if (do_enum) {
rio_set_device_id(port, destid, hopcount, next_destid);
rdev->destid = next_destid;
next_destid = rio_destid_alloc(net);
} else
rdev->destid = rio_get_device_id(port, destid, hopcount);
rdev->hopcount = 0xff;
} else {
rdev->destid = destid;
rdev->hopcount = hopcount;
}
if (rio_is_switch(rdev)) {
rswitch = rdev->rswitch;
rswitch->port_ok = 0;
spin_lock_init(&rswitch->lock);
rswitch->route_table = kzalloc(sizeof(u8)*
RIO_MAX_ROUTE_ENTRIES(port->sys_size),
GFP_KERNEL);
if (!rswitch->route_table)
goto cleanup;
for (rdid = 0; rdid < RIO_MAX_ROUTE_ENTRIES(port->sys_size);
rdid++)
rswitch->route_table[rdid] = RIO_INVALID_ROUTE;
dev_set_name(&rdev->dev, "%02x:s:%04x", rdev->net->id,
rdev->comp_tag & RIO_CTAG_UDEVID);
if (do_enum)
rio_route_clr_table(rdev, RIO_GLOBAL_TABLE, 0);
} else {
if (do_enum)
rio_enable_rx_tx_port(port, 0, destid, hopcount, 0);
dev_set_name(&rdev->dev, "%02x:e:%04x", rdev->net->id,
rdev->comp_tag & RIO_CTAG_UDEVID);
}
rdev->dev.parent = &net->dev;
rio_attach_device(rdev);
rdev->dev.release = rio_release_dev;
rdev->dma_mask = DMA_BIT_MASK(32);
rdev->dev.dma_mask = &rdev->dma_mask;
rdev->dev.coherent_dma_mask = DMA_BIT_MASK(32);
if (rdev->dst_ops & RIO_DST_OPS_DOORBELL)
rio_init_dbell_res(&rdev->riores[RIO_DOORBELL_RESOURCE],
0, 0xffff);
ret = rio_add_device(rdev);
if (ret)
goto cleanup;
rio_dev_get(rdev);
return rdev;
cleanup:
if (rswitch)
kfree(rswitch->route_table);
kfree(rdev);
return NULL;
}
static int
rio_sport_is_active(struct rio_mport *port, u16 destid, u8 hopcount, int sport)
{
u32 result = 0;
u32 ext_ftr_ptr;
ext_ftr_ptr = rio_mport_get_efb(port, 0, destid, hopcount, 0);
while (ext_ftr_ptr) {
rio_mport_read_config_32(port, destid, hopcount,
ext_ftr_ptr, &result);
result = RIO_GET_BLOCK_ID(result);
if ((result == RIO_EFB_SER_EP_FREE_ID) ||
(result == RIO_EFB_SER_EP_FREE_ID_V13P) ||
(result == RIO_EFB_SER_EP_FREC_ID))
break;
ext_ftr_ptr = rio_mport_get_efb(port, 0, destid, hopcount,
ext_ftr_ptr);
}
if (ext_ftr_ptr)
rio_mport_read_config_32(port, destid, hopcount,
ext_ftr_ptr +
RIO_PORT_N_ERR_STS_CSR(sport),
&result);
return result & RIO_PORT_N_ERR_STS_PORT_OK;
}
static u16 rio_get_host_deviceid_lock(struct rio_mport *port, u8 hopcount)
{
u32 result;
rio_mport_read_config_32(port, RIO_ANY_DESTID(port->sys_size), hopcount,
RIO_HOST_DID_LOCK_CSR, &result);
return (u16) (result & 0xffff);
}
static int rio_enum_peer(struct rio_net *net, struct rio_mport *port,
u8 hopcount, struct rio_dev *prev, int prev_port)
{
struct rio_dev *rdev;
u32 regval;
int tmp;
if (rio_mport_chk_dev_access(port,
RIO_ANY_DESTID(port->sys_size), hopcount)) {
pr_debug("RIO: device access check failed\n");
return -1;
}
if (rio_get_host_deviceid_lock(port, hopcount) == port->host_deviceid) {
pr_debug("RIO: PE already discovered by this host\n");
rio_mport_read_config_32(port, RIO_ANY_DESTID(port->sys_size),
hopcount, RIO_COMPONENT_TAG_CSR, &regval);
if (regval) {
rdev = rio_get_comptag((regval & 0xffff), NULL);
if (rdev && prev && rio_is_switch(prev)) {
pr_debug("RIO: redundant path to %s\n",
rio_name(rdev));
prev->rswitch->nextdev[prev_port] = rdev;
}
}
return 0;
}
rio_mport_write_config_32(port, RIO_ANY_DESTID(port->sys_size),
hopcount,
RIO_HOST_DID_LOCK_CSR, port->host_deviceid);
while ((tmp = rio_get_host_deviceid_lock(port, hopcount))
< port->host_deviceid) {
mdelay(1);
rio_mport_write_config_32(port, RIO_ANY_DESTID(port->sys_size),
hopcount,
RIO_HOST_DID_LOCK_CSR,
port->host_deviceid);
}
if (rio_get_host_deviceid_lock(port, hopcount) > port->host_deviceid) {
pr_debug(
"RIO: PE locked by a higher priority host...retreating\n");
return -1;
}
rdev = rio_setup_device(net, port, RIO_ANY_DESTID(port->sys_size),
hopcount, 1);
if (rdev) {
rdev->prev = prev;
if (prev && rio_is_switch(prev))
prev->rswitch->nextdev[prev_port] = rdev;
} else
return -1;
if (rio_is_switch(rdev)) {
int sw_destid;
int cur_destid;
int sw_inport;
u16 destid;
int port_num;
sw_inport = RIO_GET_PORT_NUM(rdev->swpinfo);
rio_route_add_entry(rdev, RIO_GLOBAL_TABLE,
port->host_deviceid, sw_inport, 0);
rdev->rswitch->route_table[port->host_deviceid] = sw_inport;
destid = rio_destid_first(net);
while (destid != RIO_INVALID_DESTID && destid < next_destid) {
if (destid != port->host_deviceid) {
rio_route_add_entry(rdev, RIO_GLOBAL_TABLE,
destid, sw_inport, 0);
rdev->rswitch->route_table[destid] = sw_inport;
}
destid = rio_destid_next(net, destid + 1);
}
pr_debug(
"RIO: found %s (vid %4.4x did %4.4x) with %d ports\n",
rio_name(rdev), rdev->vid, rdev->did,
RIO_GET_TOTAL_PORTS(rdev->swpinfo));
sw_destid = next_destid;
for (port_num = 0;
port_num < RIO_GET_TOTAL_PORTS(rdev->swpinfo);
port_num++) {
if (sw_inport == port_num) {
rio_enable_rx_tx_port(port, 0,
RIO_ANY_DESTID(port->sys_size),
hopcount, port_num);
rdev->rswitch->port_ok |= (1 << port_num);
continue;
}
cur_destid = next_destid;
if (rio_sport_is_active
(port, RIO_ANY_DESTID(port->sys_size), hopcount,
port_num)) {
pr_debug(
"RIO: scanning device on port %d\n",
port_num);
rio_enable_rx_tx_port(port, 0,
RIO_ANY_DESTID(port->sys_size),
hopcount, port_num);
rdev->rswitch->port_ok |= (1 << port_num);
rio_route_add_entry(rdev, RIO_GLOBAL_TABLE,
RIO_ANY_DESTID(port->sys_size),
port_num, 0);
if (rio_enum_peer(net, port, hopcount + 1,
rdev, port_num) < 0)
return -1;
destid = rio_destid_next(net, cur_destid + 1);
if (destid != RIO_INVALID_DESTID) {
for (destid = cur_destid;
destid < next_destid;) {
if (destid != port->host_deviceid) {
rio_route_add_entry(rdev,
RIO_GLOBAL_TABLE,
destid,
port_num,
0);
rdev->rswitch->
route_table[destid] =
port_num;
}
destid = rio_destid_next(net,
destid + 1);
}
}
} else {
if (rdev->em_efptr)
rio_set_port_lockout(rdev, port_num, 1);
rdev->rswitch->port_ok &= ~(1 << port_num);
}
}
if ((rdev->src_ops & RIO_SRC_OPS_PORT_WRITE) &&
(rdev->em_efptr)) {
rio_write_config_32(rdev,
rdev->em_efptr + RIO_EM_PW_TGT_DEVID,
(port->host_deviceid << 16) |
(port->sys_size << 15));
}
rio_init_em(rdev);
if (next_destid == sw_destid)
next_destid = rio_destid_alloc(net);
rdev->destid = sw_destid;
} else
pr_debug("RIO: found %s (vid %4.4x did %4.4x)\n",
rio_name(rdev), rdev->vid, rdev->did);
return 0;
}
static int rio_enum_complete(struct rio_mport *port)
{
u32 regval;
rio_local_read_config_32(port, port->phys_efptr + RIO_PORT_GEN_CTL_CSR,
&regval);
return (regval & RIO_PORT_GEN_DISCOVERED) ? 1 : 0;
}
static int
rio_disc_peer(struct rio_net *net, struct rio_mport *port, u16 destid,
u8 hopcount, struct rio_dev *prev, int prev_port)
{
u8 port_num, route_port;
struct rio_dev *rdev;
u16 ndestid;
if ((rdev = rio_setup_device(net, port, destid, hopcount, 0))) {
rdev->prev = prev;
if (prev && rio_is_switch(prev))
prev->rswitch->nextdev[prev_port] = rdev;
} else
return -1;
if (rio_is_switch(rdev)) {
rdev->destid = destid;
pr_debug(
"RIO: found %s (vid %4.4x did %4.4x) with %d ports\n",
rio_name(rdev), rdev->vid, rdev->did,
RIO_GET_TOTAL_PORTS(rdev->swpinfo));
for (port_num = 0;
port_num < RIO_GET_TOTAL_PORTS(rdev->swpinfo);
port_num++) {
if (RIO_GET_PORT_NUM(rdev->swpinfo) == port_num)
continue;
if (rio_sport_is_active
(port, destid, hopcount, port_num)) {
pr_debug(
"RIO: scanning device on port %d\n",
port_num);
rio_lock_device(port, destid, hopcount, 1000);
for (ndestid = 0;
ndestid < RIO_ANY_DESTID(port->sys_size);
ndestid++) {
rio_route_get_entry(rdev,
RIO_GLOBAL_TABLE,
ndestid,
&route_port, 0);
if (route_port == port_num)
break;
}
if (ndestid == RIO_ANY_DESTID(port->sys_size))
continue;
rio_unlock_device(port, destid, hopcount);
if (rio_disc_peer(net, port, ndestid,
hopcount + 1, rdev, port_num) < 0)
return -1;
}
}
} else
pr_debug("RIO: found %s (vid %4.4x did %4.4x)\n",
rio_name(rdev), rdev->vid, rdev->did);
return 0;
}
static int rio_mport_is_active(struct rio_mport *port)
{
u32 result = 0;
u32 ext_ftr_ptr;
int *entry = rio_mport_phys_table;
do {
if ((ext_ftr_ptr =
rio_mport_get_feature(port, 1, 0, 0, *entry)))
break;
} while (*++entry >= 0);
if (ext_ftr_ptr)
rio_local_read_config_32(port,
ext_ftr_ptr +
RIO_PORT_N_ERR_STS_CSR(port->index),
&result);
return result & RIO_PORT_N_ERR_STS_PORT_OK;
}
static void rio_scan_release_net(struct rio_net *net)
{
pr_debug("RIO-SCAN: %s: net_%d\n", __func__, net->id);
kfree(net->enum_data);
}
static void rio_scan_release_dev(struct device *dev)
{
struct rio_net *net;
net = to_rio_net(dev);
pr_debug("RIO-SCAN: %s: net_%d\n", __func__, net->id);
kfree(net);
}
static struct rio_net *rio_scan_alloc_net(struct rio_mport *mport,
int do_enum, u16 start)
{
struct rio_net *net;
net = rio_alloc_net(mport);
if (net && do_enum) {
struct rio_id_table *idtab;
size_t size;
size = sizeof(struct rio_id_table) +
BITS_TO_LONGS(
RIO_MAX_ROUTE_ENTRIES(mport->sys_size)
) * sizeof(long);
idtab = kzalloc(size, GFP_KERNEL);
if (idtab == NULL) {
pr_err("RIO: failed to allocate destID table\n");
rio_free_net(net);
net = NULL;
} else {
net->enum_data = idtab;
net->release = rio_scan_release_net;
idtab->start = start;
idtab->max = RIO_MAX_ROUTE_ENTRIES(mport->sys_size);
spin_lock_init(&idtab->lock);
}
}
if (net) {
net->id = mport->id;
net->hport = mport;
dev_set_name(&net->dev, "rnet_%d", net->id);
net->dev.parent = &mport->dev;
net->dev.release = rio_scan_release_dev;
rio_add_net(net);
}
return net;
}
static void rio_update_route_tables(struct rio_net *net)
{
struct rio_dev *rdev, *swrdev;
struct rio_switch *rswitch;
u8 sport;
u16 destid;
list_for_each_entry(rdev, &net->devices, net_list) {
destid = rdev->destid;
list_for_each_entry(rswitch, &net->switches, node) {
if (rio_is_switch(rdev) && (rdev->rswitch == rswitch))
continue;
if (RIO_INVALID_ROUTE == rswitch->route_table[destid]) {
swrdev = sw_to_rio_dev(rswitch);
if (swrdev->destid == destid)
continue;
sport = RIO_GET_PORT_NUM(swrdev->swpinfo);
rio_route_add_entry(swrdev, RIO_GLOBAL_TABLE,
destid, sport, 0);
rswitch->route_table[destid] = sport;
}
}
}
}
static void rio_init_em(struct rio_dev *rdev)
{
if (rio_is_switch(rdev) && (rdev->em_efptr) &&
rdev->rswitch->ops && rdev->rswitch->ops->em_init) {
rdev->rswitch->ops->em_init(rdev);
}
}
static int rio_enum_mport(struct rio_mport *mport, u32 flags)
{
struct rio_net *net = NULL;
int rc = 0;
printk(KERN_INFO "RIO: enumerate master port %d, %s\n", mport->id,
mport->name);
if (mport->nnode.next || mport->nnode.prev)
return -EBUSY;
if (rio_enum_host(mport) < 0) {
printk(KERN_INFO
"RIO: master port %d device has been enumerated by a remote host\n",
mport->id);
rc = -EBUSY;
goto out;
}
if (rio_mport_is_active(mport)) {
net = rio_scan_alloc_net(mport, 1, 0);
if (!net) {
printk(KERN_ERR "RIO: failed to allocate new net\n");
rc = -ENOMEM;
goto out;
}
rio_destid_reserve(net, mport->host_deviceid);
rio_enable_rx_tx_port(mport, 1, 0, 0, 0);
rio_local_write_config_32(mport, RIO_COMPONENT_TAG_CSR,
next_comptag++);
next_destid = rio_destid_alloc(net);
if (rio_enum_peer(net, mport, 0, NULL, 0) < 0) {
printk(KERN_INFO
"RIO: master port %d device has lost enumeration to a remote host\n",
mport->id);
rio_clear_locks(net);
rc = -EBUSY;
goto out;
}
rio_destid_free(net, next_destid);
rio_update_route_tables(net);
rio_clear_locks(net);
rio_pw_enable(mport, 1);
} else {
printk(KERN_INFO "RIO: master port %d link inactive\n",
mport->id);
rc = -EINVAL;
}
out:
return rc;
}
static void rio_build_route_tables(struct rio_net *net)
{
struct rio_switch *rswitch;
struct rio_dev *rdev;
int i;
u8 sport;
list_for_each_entry(rswitch, &net->switches, node) {
rdev = sw_to_rio_dev(rswitch);
rio_lock_device(net->hport, rdev->destid,
rdev->hopcount, 1000);
for (i = 0;
i < RIO_MAX_ROUTE_ENTRIES(net->hport->sys_size);
i++) {
if (rio_route_get_entry(rdev, RIO_GLOBAL_TABLE,
i, &sport, 0) < 0)
continue;
rswitch->route_table[i] = sport;
}
rio_unlock_device(net->hport, rdev->destid, rdev->hopcount);
}
}
static int rio_disc_mport(struct rio_mport *mport, u32 flags)
{
struct rio_net *net = NULL;
unsigned long to_end;
printk(KERN_INFO "RIO: discover master port %d, %s\n", mport->id,
mport->name);
if (rio_mport_is_active(mport)) {
if (rio_enum_complete(mport))
goto enum_done;
else if (flags & RIO_SCAN_ENUM_NO_WAIT)
return -EAGAIN;
pr_debug("RIO: wait for enumeration to complete...\n");
to_end = jiffies + CONFIG_RAPIDIO_DISC_TIMEOUT * HZ;
while (time_before(jiffies, to_end)) {
if (rio_enum_complete(mport))
goto enum_done;
msleep(10);
}
pr_debug("RIO: discovery timeout on mport %d %s\n",
mport->id, mport->name);
goto bail;
enum_done:
pr_debug("RIO: ... enumeration done\n");
net = rio_scan_alloc_net(mport, 0, 0);
if (!net) {
printk(KERN_ERR "RIO: Failed to allocate new net\n");
goto bail;
}
rio_local_read_config_32(mport, RIO_DID_CSR,
&mport->host_deviceid);
mport->host_deviceid = RIO_GET_DID(mport->sys_size,
mport->host_deviceid);
if (rio_disc_peer(net, mport, RIO_ANY_DESTID(mport->sys_size),
0, NULL, 0) < 0) {
printk(KERN_INFO
"RIO: master port %d device has failed discovery\n",
mport->id);
goto bail;
}
rio_build_route_tables(net);
}
return 0;
bail:
return -EBUSY;
}
static int __init rio_basic_attach(void)
{
if (rio_register_scan(RIO_MPORT_ANY, &rio_scan_ops))
return -EIO;
if (scan)
rio_init_mports();
return 0;
}
