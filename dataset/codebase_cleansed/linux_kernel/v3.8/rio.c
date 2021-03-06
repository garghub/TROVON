u16 rio_local_get_device_id(struct rio_mport *port)
{
u32 result;
rio_local_read_config_32(port, RIO_DID_CSR, &result);
return (RIO_GET_DID(port->sys_size, result));
}
int rio_request_inb_mbox(struct rio_mport *mport,
void *dev_id,
int mbox,
int entries,
void (*minb) (struct rio_mport * mport, void *dev_id, int mbox,
int slot))
{
int rc = -ENOSYS;
struct resource *res;
if (mport->ops->open_inb_mbox == NULL)
goto out;
res = kmalloc(sizeof(struct resource), GFP_KERNEL);
if (res) {
rio_init_mbox_res(res, mbox, mbox);
if ((rc =
request_resource(&mport->riores[RIO_INB_MBOX_RESOURCE],
res)) < 0) {
kfree(res);
goto out;
}
mport->inb_msg[mbox].res = res;
mport->inb_msg[mbox].mcback = minb;
rc = mport->ops->open_inb_mbox(mport, dev_id, mbox, entries);
} else
rc = -ENOMEM;
out:
return rc;
}
int rio_release_inb_mbox(struct rio_mport *mport, int mbox)
{
if (mport->ops->close_inb_mbox) {
mport->ops->close_inb_mbox(mport, mbox);
return release_resource(mport->inb_msg[mbox].res);
} else
return -ENOSYS;
}
int rio_request_outb_mbox(struct rio_mport *mport,
void *dev_id,
int mbox,
int entries,
void (*moutb) (struct rio_mport * mport, void *dev_id, int mbox, int slot))
{
int rc = -ENOSYS;
struct resource *res;
if (mport->ops->open_outb_mbox == NULL)
goto out;
res = kmalloc(sizeof(struct resource), GFP_KERNEL);
if (res) {
rio_init_mbox_res(res, mbox, mbox);
if ((rc =
request_resource(&mport->riores[RIO_OUTB_MBOX_RESOURCE],
res)) < 0) {
kfree(res);
goto out;
}
mport->outb_msg[mbox].res = res;
mport->outb_msg[mbox].mcback = moutb;
rc = mport->ops->open_outb_mbox(mport, dev_id, mbox, entries);
} else
rc = -ENOMEM;
out:
return rc;
}
int rio_release_outb_mbox(struct rio_mport *mport, int mbox)
{
if (mport->ops->close_outb_mbox) {
mport->ops->close_outb_mbox(mport, mbox);
return release_resource(mport->outb_msg[mbox].res);
} else
return -ENOSYS;
}
static int
rio_setup_inb_dbell(struct rio_mport *mport, void *dev_id, struct resource *res,
void (*dinb) (struct rio_mport * mport, void *dev_id, u16 src, u16 dst,
u16 info))
{
int rc = 0;
struct rio_dbell *dbell;
if (!(dbell = kmalloc(sizeof(struct rio_dbell), GFP_KERNEL))) {
rc = -ENOMEM;
goto out;
}
dbell->res = res;
dbell->dinb = dinb;
dbell->dev_id = dev_id;
list_add_tail(&dbell->node, &mport->dbells);
out:
return rc;
}
int rio_request_inb_dbell(struct rio_mport *mport,
void *dev_id,
u16 start,
u16 end,
void (*dinb) (struct rio_mport * mport, void *dev_id, u16 src,
u16 dst, u16 info))
{
int rc = 0;
struct resource *res = kmalloc(sizeof(struct resource), GFP_KERNEL);
if (res) {
rio_init_dbell_res(res, start, end);
if ((rc =
request_resource(&mport->riores[RIO_DOORBELL_RESOURCE],
res)) < 0) {
kfree(res);
goto out;
}
rc = rio_setup_inb_dbell(mport, dev_id, res, dinb);
} else
rc = -ENOMEM;
out:
return rc;
}
int rio_release_inb_dbell(struct rio_mport *mport, u16 start, u16 end)
{
int rc = 0, found = 0;
struct rio_dbell *dbell;
list_for_each_entry(dbell, &mport->dbells, node) {
if ((dbell->res->start == start) && (dbell->res->end == end)) {
found = 1;
break;
}
}
if (!found) {
rc = -EINVAL;
goto out;
}
list_del(&dbell->node);
rc = release_resource(dbell->res);
kfree(dbell);
out:
return rc;
}
struct resource *rio_request_outb_dbell(struct rio_dev *rdev, u16 start,
u16 end)
{
struct resource *res = kmalloc(sizeof(struct resource), GFP_KERNEL);
if (res) {
rio_init_dbell_res(res, start, end);
if (request_resource(&rdev->riores[RIO_DOORBELL_RESOURCE], res)
< 0) {
kfree(res);
res = NULL;
}
}
return res;
}
int rio_release_outb_dbell(struct rio_dev *rdev, struct resource *res)
{
int rc = release_resource(res);
kfree(res);
return rc;
}
int rio_request_inb_pwrite(struct rio_dev *rdev,
int (*pwcback)(struct rio_dev *rdev, union rio_pw_msg *msg, int step))
{
int rc = 0;
spin_lock(&rio_global_list_lock);
if (rdev->pwcback != NULL)
rc = -ENOMEM;
else
rdev->pwcback = pwcback;
spin_unlock(&rio_global_list_lock);
return rc;
}
int rio_release_inb_pwrite(struct rio_dev *rdev)
{
int rc = -ENOMEM;
spin_lock(&rio_global_list_lock);
if (rdev->pwcback) {
rdev->pwcback = NULL;
rc = 0;
}
spin_unlock(&rio_global_list_lock);
return rc;
}
int rio_map_inb_region(struct rio_mport *mport, dma_addr_t local,
u64 rbase, u32 size, u32 rflags)
{
int rc = 0;
unsigned long flags;
if (!mport->ops->map_inb)
return -1;
spin_lock_irqsave(&rio_mmap_lock, flags);
rc = mport->ops->map_inb(mport, local, rbase, size, rflags);
spin_unlock_irqrestore(&rio_mmap_lock, flags);
return rc;
}
void rio_unmap_inb_region(struct rio_mport *mport, dma_addr_t lstart)
{
unsigned long flags;
if (!mport->ops->unmap_inb)
return;
spin_lock_irqsave(&rio_mmap_lock, flags);
mport->ops->unmap_inb(mport, lstart);
spin_unlock_irqrestore(&rio_mmap_lock, flags);
}
u32
rio_mport_get_physefb(struct rio_mport *port, int local,
u16 destid, u8 hopcount)
{
u32 ext_ftr_ptr;
u32 ftr_header;
ext_ftr_ptr = rio_mport_get_efb(port, local, destid, hopcount, 0);
while (ext_ftr_ptr) {
if (local)
rio_local_read_config_32(port, ext_ftr_ptr,
&ftr_header);
else
rio_mport_read_config_32(port, destid, hopcount,
ext_ftr_ptr, &ftr_header);
ftr_header = RIO_GET_BLOCK_ID(ftr_header);
switch (ftr_header) {
case RIO_EFB_SER_EP_ID_V13P:
case RIO_EFB_SER_EP_REC_ID_V13P:
case RIO_EFB_SER_EP_FREE_ID_V13P:
case RIO_EFB_SER_EP_ID:
case RIO_EFB_SER_EP_REC_ID:
case RIO_EFB_SER_EP_FREE_ID:
case RIO_EFB_SER_EP_FREC_ID:
return ext_ftr_ptr;
default:
break;
}
ext_ftr_ptr = rio_mport_get_efb(port, local, destid,
hopcount, ext_ftr_ptr);
}
return ext_ftr_ptr;
}
struct rio_dev *rio_get_comptag(u32 comp_tag, struct rio_dev *from)
{
struct list_head *n;
struct rio_dev *rdev;
spin_lock(&rio_global_list_lock);
n = from ? from->global_list.next : rio_devices.next;
while (n && (n != &rio_devices)) {
rdev = rio_dev_g(n);
if (rdev->comp_tag == comp_tag)
goto exit;
n = n->next;
}
rdev = NULL;
exit:
spin_unlock(&rio_global_list_lock);
return rdev;
}
int rio_set_port_lockout(struct rio_dev *rdev, u32 pnum, int lock)
{
u32 regval;
rio_read_config_32(rdev,
rdev->phys_efptr + RIO_PORT_N_CTL_CSR(pnum),
&regval);
if (lock)
regval |= RIO_PORT_N_CTL_LOCKOUT;
else
regval &= ~RIO_PORT_N_CTL_LOCKOUT;
rio_write_config_32(rdev,
rdev->phys_efptr + RIO_PORT_N_CTL_CSR(pnum),
regval);
return 0;
}
static int
rio_chk_dev_route(struct rio_dev *rdev, struct rio_dev **nrdev, int *npnum)
{
u32 result;
int p_port, rc = -EIO;
struct rio_dev *prev = NULL;
while (rdev->prev && (rdev->prev->pef & RIO_PEF_SWITCH)) {
if (!rio_read_config_32(rdev->prev, RIO_DEV_ID_CAR, &result)) {
prev = rdev->prev;
break;
}
rdev = rdev->prev;
}
if (prev == NULL)
goto err_out;
p_port = prev->rswitch->route_table[rdev->destid];
if (p_port != RIO_INVALID_ROUTE) {
pr_debug("RIO: link failed on [%s]-P%d\n",
rio_name(prev), p_port);
*nrdev = prev;
*npnum = p_port;
rc = 0;
} else
pr_debug("RIO: failed to trace route to %s\n", rio_name(rdev));
err_out:
return rc;
}
int
rio_mport_chk_dev_access(struct rio_mport *mport, u16 destid, u8 hopcount)
{
int i = 0;
u32 tmp;
while (rio_mport_read_config_32(mport, destid, hopcount,
RIO_DEV_ID_CAR, &tmp)) {
i++;
if (i == RIO_MAX_CHK_RETRY)
return -EIO;
mdelay(1);
}
return 0;
}
static int rio_chk_dev_access(struct rio_dev *rdev)
{
return rio_mport_chk_dev_access(rdev->net->hport,
rdev->destid, rdev->hopcount);
}
static int
rio_get_input_status(struct rio_dev *rdev, int pnum, u32 *lnkresp)
{
u32 regval;
int checkcount;
if (lnkresp) {
rio_read_config_32(rdev,
rdev->phys_efptr + RIO_PORT_N_MNT_RSP_CSR(pnum),
&regval);
udelay(50);
}
rio_write_config_32(rdev,
rdev->phys_efptr + RIO_PORT_N_MNT_REQ_CSR(pnum),
RIO_MNT_REQ_CMD_IS);
if (lnkresp == NULL)
return 0;
checkcount = 3;
while (checkcount--) {
udelay(50);
rio_read_config_32(rdev,
rdev->phys_efptr + RIO_PORT_N_MNT_RSP_CSR(pnum),
&regval);
if (regval & RIO_PORT_N_MNT_RSP_RVAL) {
*lnkresp = regval;
return 0;
}
}
return -EIO;
}
static int rio_clr_err_stopped(struct rio_dev *rdev, u32 pnum, u32 err_status)
{
struct rio_dev *nextdev = rdev->rswitch->nextdev[pnum];
u32 regval;
u32 far_ackid, far_linkstat, near_ackid;
if (err_status == 0)
rio_read_config_32(rdev,
rdev->phys_efptr + RIO_PORT_N_ERR_STS_CSR(pnum),
&err_status);
if (err_status & RIO_PORT_N_ERR_STS_PW_OUT_ES) {
pr_debug("RIO_EM: servicing Output Error-Stopped state\n");
if (rio_get_input_status(rdev, pnum, &regval)) {
pr_debug("RIO_EM: Input-status response timeout\n");
goto rd_err;
}
pr_debug("RIO_EM: SP%d Input-status response=0x%08x\n",
pnum, regval);
far_ackid = (regval & RIO_PORT_N_MNT_RSP_ASTAT) >> 5;
far_linkstat = regval & RIO_PORT_N_MNT_RSP_LSTAT;
rio_read_config_32(rdev,
rdev->phys_efptr + RIO_PORT_N_ACK_STS_CSR(pnum),
&regval);
pr_debug("RIO_EM: SP%d_ACK_STS_CSR=0x%08x\n", pnum, regval);
near_ackid = (regval & RIO_PORT_N_ACK_INBOUND) >> 24;
pr_debug("RIO_EM: SP%d far_ackID=0x%02x far_linkstat=0x%02x" \
" near_ackID=0x%02x\n",
pnum, far_ackid, far_linkstat, near_ackid);
if ((far_ackid != ((regval & RIO_PORT_N_ACK_OUTSTAND) >> 8)) ||
(far_ackid != (regval & RIO_PORT_N_ACK_OUTBOUND))) {
rio_write_config_32(rdev,
rdev->phys_efptr + RIO_PORT_N_ACK_STS_CSR(pnum),
(near_ackid << 24) |
(far_ackid << 8) | far_ackid);
far_ackid++;
if (nextdev)
rio_write_config_32(nextdev,
nextdev->phys_efptr +
RIO_PORT_N_ACK_STS_CSR(RIO_GET_PORT_NUM(nextdev->swpinfo)),
(far_ackid << 24) |
(near_ackid << 8) | near_ackid);
else
pr_debug("RIO_EM: Invalid nextdev pointer (NULL)\n");
}
rd_err:
rio_read_config_32(rdev,
rdev->phys_efptr + RIO_PORT_N_ERR_STS_CSR(pnum),
&err_status);
pr_debug("RIO_EM: SP%d_ERR_STS_CSR=0x%08x\n", pnum, err_status);
}
if ((err_status & RIO_PORT_N_ERR_STS_PW_INP_ES) && nextdev) {
pr_debug("RIO_EM: servicing Input Error-Stopped state\n");
rio_get_input_status(nextdev,
RIO_GET_PORT_NUM(nextdev->swpinfo), NULL);
udelay(50);
rio_read_config_32(rdev,
rdev->phys_efptr + RIO_PORT_N_ERR_STS_CSR(pnum),
&err_status);
pr_debug("RIO_EM: SP%d_ERR_STS_CSR=0x%08x\n", pnum, err_status);
}
return (err_status & (RIO_PORT_N_ERR_STS_PW_OUT_ES |
RIO_PORT_N_ERR_STS_PW_INP_ES)) ? 1 : 0;
}
int rio_inb_pwrite_handler(union rio_pw_msg *pw_msg)
{
struct rio_dev *rdev;
u32 err_status, em_perrdet, em_ltlerrdet;
int rc, portnum;
rdev = rio_get_comptag((pw_msg->em.comptag & RIO_CTAG_UDEVID), NULL);
if (rdev == NULL) {
pr_debug("RIO: %s No matching device for CTag 0x%08x\n",
__func__, pw_msg->em.comptag);
return -EIO;
}
pr_debug("RIO: Port-Write message from %s\n", rio_name(rdev));
#ifdef DEBUG_PW
{
u32 i;
for (i = 0; i < RIO_PW_MSG_SIZE/sizeof(u32);) {
pr_debug("0x%02x: %08x %08x %08x %08x\n",
i*4, pw_msg->raw[i], pw_msg->raw[i + 1],
pw_msg->raw[i + 2], pw_msg->raw[i + 3]);
i += 4;
}
}
#endif
if (rdev->pwcback != NULL) {
rc = rdev->pwcback(rdev, pw_msg, 0);
if (rc == 0)
return 0;
}
portnum = pw_msg->em.is_port & 0xFF;
if (rio_chk_dev_access(rdev)) {
pr_debug("RIO: device access failed - get link partner\n");
if (rio_chk_dev_route(rdev, &rdev, &portnum)) {
pr_err("RIO: Route trace for %s failed\n",
rio_name(rdev));
return -EIO;
}
pw_msg = NULL;
}
if (!(rdev->pef & RIO_PEF_SWITCH))
return 0;
if (rdev->phys_efptr == 0) {
pr_err("RIO_PW: Bad switch initialization for %s\n",
rio_name(rdev));
return 0;
}
if (rdev->rswitch->em_handle)
rdev->rswitch->em_handle(rdev, portnum);
rio_read_config_32(rdev,
rdev->phys_efptr + RIO_PORT_N_ERR_STS_CSR(portnum),
&err_status);
pr_debug("RIO_PW: SP%d_ERR_STS_CSR=0x%08x\n", portnum, err_status);
if (err_status & RIO_PORT_N_ERR_STS_PORT_OK) {
if (!(rdev->rswitch->port_ok & (1 << portnum))) {
rdev->rswitch->port_ok |= (1 << portnum);
rio_set_port_lockout(rdev, portnum, 0);
pr_debug("RIO_PW: Device Insertion on [%s]-P%d\n",
rio_name(rdev), portnum);
}
if (err_status & (RIO_PORT_N_ERR_STS_PW_OUT_ES |
RIO_PORT_N_ERR_STS_PW_INP_ES)) {
if (rio_clr_err_stopped(rdev, portnum, err_status))
rio_clr_err_stopped(rdev, portnum, 0);
}
} else {
if (rdev->rswitch->port_ok & (1 << portnum)) {
rdev->rswitch->port_ok &= ~(1 << portnum);
rio_set_port_lockout(rdev, portnum, 1);
rio_write_config_32(rdev,
rdev->phys_efptr +
RIO_PORT_N_ACK_STS_CSR(portnum),
RIO_PORT_N_ACK_CLEAR);
pr_debug("RIO_PW: Device Extraction on [%s]-P%d\n",
rio_name(rdev), portnum);
}
}
rio_read_config_32(rdev,
rdev->em_efptr + RIO_EM_PN_ERR_DETECT(portnum), &em_perrdet);
if (em_perrdet) {
pr_debug("RIO_PW: RIO_EM_P%d_ERR_DETECT=0x%08x\n",
portnum, em_perrdet);
rio_write_config_32(rdev,
rdev->em_efptr + RIO_EM_PN_ERR_DETECT(portnum), 0);
}
rio_read_config_32(rdev,
rdev->em_efptr + RIO_EM_LTL_ERR_DETECT, &em_ltlerrdet);
if (em_ltlerrdet) {
pr_debug("RIO_PW: RIO_EM_LTL_ERR_DETECT=0x%08x\n",
em_ltlerrdet);
rio_write_config_32(rdev,
rdev->em_efptr + RIO_EM_LTL_ERR_DETECT, 0);
}
rio_write_config_32(rdev,
rdev->phys_efptr + RIO_PORT_N_ERR_STS_CSR(portnum),
err_status);
return 0;
}
u32
rio_mport_get_efb(struct rio_mport *port, int local, u16 destid,
u8 hopcount, u32 from)
{
u32 reg_val;
if (from == 0) {
if (local)
rio_local_read_config_32(port, RIO_ASM_INFO_CAR,
&reg_val);
else
rio_mport_read_config_32(port, destid, hopcount,
RIO_ASM_INFO_CAR, &reg_val);
return reg_val & RIO_EXT_FTR_PTR_MASK;
} else {
if (local)
rio_local_read_config_32(port, from, &reg_val);
else
rio_mport_read_config_32(port, destid, hopcount,
from, &reg_val);
return RIO_GET_BLOCK_ID(reg_val);
}
}
u32
rio_mport_get_feature(struct rio_mport * port, int local, u16 destid,
u8 hopcount, int ftr)
{
u32 asm_info, ext_ftr_ptr, ftr_header;
if (local)
rio_local_read_config_32(port, RIO_ASM_INFO_CAR, &asm_info);
else
rio_mport_read_config_32(port, destid, hopcount,
RIO_ASM_INFO_CAR, &asm_info);
ext_ftr_ptr = asm_info & RIO_EXT_FTR_PTR_MASK;
while (ext_ftr_ptr) {
if (local)
rio_local_read_config_32(port, ext_ftr_ptr,
&ftr_header);
else
rio_mport_read_config_32(port, destid, hopcount,
ext_ftr_ptr, &ftr_header);
if (RIO_GET_BLOCK_ID(ftr_header) == ftr)
return ext_ftr_ptr;
if (!(ext_ftr_ptr = RIO_GET_BLOCK_PTR(ftr_header)))
break;
}
return 0;
}
struct rio_dev *rio_get_asm(u16 vid, u16 did,
u16 asm_vid, u16 asm_did, struct rio_dev *from)
{
struct list_head *n;
struct rio_dev *rdev;
WARN_ON(in_interrupt());
spin_lock(&rio_global_list_lock);
n = from ? from->global_list.next : rio_devices.next;
while (n && (n != &rio_devices)) {
rdev = rio_dev_g(n);
if ((vid == RIO_ANY_ID || rdev->vid == vid) &&
(did == RIO_ANY_ID || rdev->did == did) &&
(asm_vid == RIO_ANY_ID || rdev->asm_vid == asm_vid) &&
(asm_did == RIO_ANY_ID || rdev->asm_did == asm_did))
goto exit;
n = n->next;
}
rdev = NULL;
exit:
rio_dev_put(from);
rdev = rio_dev_get(rdev);
spin_unlock(&rio_global_list_lock);
return rdev;
}
struct rio_dev *rio_get_device(u16 vid, u16 did, struct rio_dev *from)
{
return rio_get_asm(vid, did, RIO_ANY_ID, RIO_ANY_ID, from);
}
int rio_std_route_add_entry(struct rio_mport *mport, u16 destid, u8 hopcount,
u16 table, u16 route_destid, u8 route_port)
{
if (table == RIO_GLOBAL_TABLE) {
rio_mport_write_config_32(mport, destid, hopcount,
RIO_STD_RTE_CONF_DESTID_SEL_CSR,
(u32)route_destid);
rio_mport_write_config_32(mport, destid, hopcount,
RIO_STD_RTE_CONF_PORT_SEL_CSR,
(u32)route_port);
}
udelay(10);
return 0;
}
int rio_std_route_get_entry(struct rio_mport *mport, u16 destid, u8 hopcount,
u16 table, u16 route_destid, u8 *route_port)
{
u32 result;
if (table == RIO_GLOBAL_TABLE) {
rio_mport_write_config_32(mport, destid, hopcount,
RIO_STD_RTE_CONF_DESTID_SEL_CSR, route_destid);
rio_mport_read_config_32(mport, destid, hopcount,
RIO_STD_RTE_CONF_PORT_SEL_CSR, &result);
*route_port = (u8)result;
}
return 0;
}
int rio_std_route_clr_table(struct rio_mport *mport, u16 destid, u8 hopcount,
u16 table)
{
u32 max_destid = 0xff;
u32 i, pef, id_inc = 1, ext_cfg = 0;
u32 port_sel = RIO_INVALID_ROUTE;
if (table == RIO_GLOBAL_TABLE) {
rio_mport_read_config_32(mport, destid, hopcount,
RIO_PEF_CAR, &pef);
if (mport->sys_size) {
rio_mport_read_config_32(mport, destid, hopcount,
RIO_SWITCH_RT_LIMIT,
&max_destid);
max_destid &= RIO_RT_MAX_DESTID;
}
if (pef & RIO_PEF_EXT_RT) {
ext_cfg = 0x80000000;
id_inc = 4;
port_sel = (RIO_INVALID_ROUTE << 24) |
(RIO_INVALID_ROUTE << 16) |
(RIO_INVALID_ROUTE << 8) |
RIO_INVALID_ROUTE;
}
for (i = 0; i <= max_destid;) {
rio_mport_write_config_32(mport, destid, hopcount,
RIO_STD_RTE_CONF_DESTID_SEL_CSR,
ext_cfg | i);
rio_mport_write_config_32(mport, destid, hopcount,
RIO_STD_RTE_CONF_PORT_SEL_CSR,
port_sel);
i += id_inc;
}
}
udelay(10);
return 0;
}
static bool rio_chan_filter(struct dma_chan *chan, void *arg)
{
struct rio_dev *rdev = arg;
return (rdev->net->hport ==
container_of(chan->device, struct rio_mport, dma));
}
struct dma_chan *rio_request_dma(struct rio_dev *rdev)
{
dma_cap_mask_t mask;
struct dma_chan *dchan;
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
dchan = dma_request_channel(mask, rio_chan_filter, rdev);
return dchan;
}
void rio_release_dma(struct dma_chan *dchan)
{
dma_release_channel(dchan);
}
struct dma_async_tx_descriptor *rio_dma_prep_slave_sg(struct rio_dev *rdev,
struct dma_chan *dchan, struct rio_dma_data *data,
enum dma_transfer_direction direction, unsigned long flags)
{
struct dma_async_tx_descriptor *txd = NULL;
struct rio_dma_ext rio_ext;
if (dchan->device->device_prep_slave_sg == NULL) {
pr_err("%s: prep_rio_sg == NULL\n", __func__);
return NULL;
}
rio_ext.destid = rdev->destid;
rio_ext.rio_addr_u = data->rio_addr_u;
rio_ext.rio_addr = data->rio_addr;
rio_ext.wr_type = data->wr_type;
txd = dmaengine_prep_rio_sg(dchan, data->sg, data->sg_len,
direction, flags, &rio_ext);
return txd;
}
static void rio_fixup_device(struct rio_dev *dev)
{
}
static int rio_init(void)
{
struct rio_dev *dev = NULL;
while ((dev = rio_get_device(RIO_ANY_ID, RIO_ANY_ID, dev)) != NULL) {
rio_fixup_device(dev);
}
return 0;
}
static void disc_work_handler(struct work_struct *_work)
{
struct rio_disc_work *work;
work = container_of(_work, struct rio_disc_work, work);
pr_debug("RIO: discovery work for mport %d %s\n",
work->mport->id, work->mport->name);
rio_disc_mport(work->mport);
}
int rio_init_mports(void)
{
struct rio_mport *port;
struct rio_disc_work *work;
int n = 0;
if (!next_portid)
return -ENODEV;
list_for_each_entry(port, &rio_mports, node) {
if (port->host_deviceid >= 0)
rio_enum_mport(port);
else
n++;
}
if (!n)
goto no_disc;
rio_wq = alloc_workqueue("riodisc", 0, 0);
if (!rio_wq) {
pr_err("RIO: unable allocate rio_wq\n");
goto no_disc;
}
work = kcalloc(n, sizeof *work, GFP_KERNEL);
if (!work) {
pr_err("RIO: no memory for work struct\n");
destroy_workqueue(rio_wq);
goto no_disc;
}
n = 0;
list_for_each_entry(port, &rio_mports, node) {
if (port->host_deviceid < 0) {
work[n].mport = port;
INIT_WORK(&work[n].work, disc_work_handler);
queue_work(rio_wq, &work[n].work);
n++;
}
}
flush_workqueue(rio_wq);
pr_debug("RIO: destroy discovery workqueue\n");
destroy_workqueue(rio_wq);
kfree(work);
no_disc:
rio_init();
return 0;
}
static int rio_get_hdid(int index)
{
if (!hdids[0] || hdids[0] <= index || index >= RIO_MAX_MPORTS)
return -1;
return hdids[index + 1];
}
static int rio_hdid_setup(char *str)
{
(void)get_options(str, ARRAY_SIZE(hdids), hdids);
return 1;
}
int rio_register_mport(struct rio_mport *port)
{
if (next_portid >= RIO_MAX_MPORTS) {
pr_err("RIO: reached specified max number of mports\n");
return 1;
}
port->id = next_portid++;
port->host_deviceid = rio_get_hdid(port->id);
list_add_tail(&port->node, &rio_mports);
return 0;
}
