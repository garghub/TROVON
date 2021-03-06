static int reply(struct ib_smp *smp)
{
smp->method = IB_MGMT_METHOD_GET_RESP;
if (smp->mgmt_class == IB_MGMT_CLASS_SUBN_DIRECTED_ROUTE)
smp->status |= IB_SMP_DIRECTION;
return IB_MAD_RESULT_SUCCESS | IB_MAD_RESULT_REPLY;
}
static int recv_subn_get_nodedescription(struct ib_smp *smp,
struct ib_device *ibdev)
{
if (smp->attr_mod)
smp->status |= IB_SMP_INVALID_FIELD;
memcpy(smp->data, ibdev->node_desc, sizeof(smp->data));
return reply(smp);
}
static int recv_subn_get_nodeinfo(struct ib_smp *smp,
struct ib_device *ibdev, u8 port)
{
struct nodeinfo *nip = (struct nodeinfo *)&smp->data;
struct ipath_devdata *dd = to_idev(ibdev)->dd;
u32 vendor, majrev, minrev;
if (smp->attr_mod || (dd->ipath_guid == 0))
smp->status |= IB_SMP_INVALID_FIELD;
nip->base_version = 1;
nip->class_version = 1;
nip->node_type = 1;
nip->num_ports = ibdev->phys_port_cnt;
nip->sys_guid = to_idev(ibdev)->sys_image_guid;
nip->node_guid = dd->ipath_guid;
nip->port_guid = dd->ipath_guid;
nip->partition_cap = cpu_to_be16(ipath_get_npkeys(dd));
nip->device_id = cpu_to_be16(dd->ipath_deviceid);
majrev = dd->ipath_majrev;
minrev = dd->ipath_minrev;
nip->revision = cpu_to_be32((majrev << 16) | minrev);
nip->local_port_num = port;
vendor = dd->ipath_vendorid;
nip->vendor_id[0] = IPATH_SRC_OUI_1;
nip->vendor_id[1] = IPATH_SRC_OUI_2;
nip->vendor_id[2] = IPATH_SRC_OUI_3;
return reply(smp);
}
static int recv_subn_get_guidinfo(struct ib_smp *smp,
struct ib_device *ibdev)
{
u32 startgx = 8 * be32_to_cpu(smp->attr_mod);
__be64 *p = (__be64 *) smp->data;
memset(smp->data, 0, sizeof(smp->data));
if (startgx == 0) {
__be64 g = to_idev(ibdev)->dd->ipath_guid;
if (g == 0)
smp->status |= IB_SMP_INVALID_FIELD;
else
*p = g;
} else
smp->status |= IB_SMP_INVALID_FIELD;
return reply(smp);
}
static void set_link_width_enabled(struct ipath_devdata *dd, u32 w)
{
(void) dd->ipath_f_set_ib_cfg(dd, IPATH_IB_CFG_LWID_ENB, w);
}
static void set_link_speed_enabled(struct ipath_devdata *dd, u32 s)
{
(void) dd->ipath_f_set_ib_cfg(dd, IPATH_IB_CFG_SPD_ENB, s);
}
static int get_overrunthreshold(struct ipath_devdata *dd)
{
return (dd->ipath_ibcctrl >>
INFINIPATH_IBCC_OVERRUNTHRESHOLD_SHIFT) &
INFINIPATH_IBCC_OVERRUNTHRESHOLD_MASK;
}
static int set_overrunthreshold(struct ipath_devdata *dd, unsigned n)
{
unsigned v;
v = (dd->ipath_ibcctrl >> INFINIPATH_IBCC_OVERRUNTHRESHOLD_SHIFT) &
INFINIPATH_IBCC_OVERRUNTHRESHOLD_MASK;
if (v != n) {
dd->ipath_ibcctrl &=
~(INFINIPATH_IBCC_OVERRUNTHRESHOLD_MASK <<
INFINIPATH_IBCC_OVERRUNTHRESHOLD_SHIFT);
dd->ipath_ibcctrl |=
(u64) n << INFINIPATH_IBCC_OVERRUNTHRESHOLD_SHIFT;
ipath_write_kreg(dd, dd->ipath_kregs->kr_ibcctrl,
dd->ipath_ibcctrl);
}
return 0;
}
static int get_phyerrthreshold(struct ipath_devdata *dd)
{
return (dd->ipath_ibcctrl >>
INFINIPATH_IBCC_PHYERRTHRESHOLD_SHIFT) &
INFINIPATH_IBCC_PHYERRTHRESHOLD_MASK;
}
static int set_phyerrthreshold(struct ipath_devdata *dd, unsigned n)
{
unsigned v;
v = (dd->ipath_ibcctrl >> INFINIPATH_IBCC_PHYERRTHRESHOLD_SHIFT) &
INFINIPATH_IBCC_PHYERRTHRESHOLD_MASK;
if (v != n) {
dd->ipath_ibcctrl &=
~(INFINIPATH_IBCC_PHYERRTHRESHOLD_MASK <<
INFINIPATH_IBCC_PHYERRTHRESHOLD_SHIFT);
dd->ipath_ibcctrl |=
(u64) n << INFINIPATH_IBCC_PHYERRTHRESHOLD_SHIFT;
ipath_write_kreg(dd, dd->ipath_kregs->kr_ibcctrl,
dd->ipath_ibcctrl);
}
return 0;
}
static int get_linkdowndefaultstate(struct ipath_devdata *dd)
{
return !!(dd->ipath_ibcctrl & INFINIPATH_IBCC_LINKDOWNDEFAULTSTATE);
}
static int recv_subn_get_portinfo(struct ib_smp *smp,
struct ib_device *ibdev, u8 port)
{
struct ipath_ibdev *dev;
struct ipath_devdata *dd;
struct ib_port_info *pip = (struct ib_port_info *)smp->data;
u16 lid;
u8 ibcstat;
u8 mtu;
int ret;
if (be32_to_cpu(smp->attr_mod) > ibdev->phys_port_cnt) {
smp->status |= IB_SMP_INVALID_FIELD;
ret = reply(smp);
goto bail;
}
dev = to_idev(ibdev);
dd = dev->dd;
memset(smp->data, 0, sizeof(smp->data));
if (smp->method == IB_MGMT_METHOD_SET || dev->mkey == smp->mkey ||
dev->mkeyprot == 0)
pip->mkey = dev->mkey;
pip->gid_prefix = dev->gid_prefix;
lid = dd->ipath_lid;
pip->lid = lid ? cpu_to_be16(lid) : IB_LID_PERMISSIVE;
pip->sm_lid = cpu_to_be16(dev->sm_lid);
pip->cap_mask = cpu_to_be32(dev->port_cap_flags);
pip->mkey_lease_period = cpu_to_be16(dev->mkey_lease_period);
pip->local_port_num = port;
pip->link_width_enabled = dd->ipath_link_width_enabled;
pip->link_width_supported = dd->ipath_link_width_supported;
pip->link_width_active = dd->ipath_link_width_active;
pip->linkspeed_portstate = dd->ipath_link_speed_supported << 4;
ibcstat = dd->ipath_lastibcstat;
pip->linkspeed_portstate |= ipath_ib_linkstate(dd, ibcstat) + 1;
pip->portphysstate_linkdown =
(ipath_cvt_physportstate[ibcstat & dd->ibcs_lts_mask] << 4) |
(get_linkdowndefaultstate(dd) ? 1 : 2);
pip->mkeyprot_resv_lmc = (dev->mkeyprot << 6) | dd->ipath_lmc;
pip->linkspeedactive_enabled = (dd->ipath_link_speed_active << 4) |
dd->ipath_link_speed_enabled;
switch (dd->ipath_ibmtu) {
case 4096:
mtu = IB_MTU_4096;
break;
case 2048:
mtu = IB_MTU_2048;
break;
case 1024:
mtu = IB_MTU_1024;
break;
case 512:
mtu = IB_MTU_512;
break;
case 256:
mtu = IB_MTU_256;
break;
default:
mtu = IB_MTU_2048;
break;
}
pip->neighbormtu_mastersmsl = (mtu << 4) | dev->sm_sl;
pip->vlcap_inittype = 0x10;
pip->vl_high_limit = dev->vl_high_limit;
pip->inittypereply_mtucap = ipath_mtu4096 ? IB_MTU_4096 : IB_MTU_2048;
pip->operationalvl_pei_peo_fpi_fpo = 0x10;
pip->mkey_violations = cpu_to_be16(dev->mkey_violations);
pip->pkey_violations =
cpu_to_be16((ipath_get_cr_errpkey(dd) -
dev->z_pkey_violations) & 0xFFFF);
pip->qkey_violations = cpu_to_be16(dev->qkey_violations);
pip->guid_cap = 1;
pip->clientrereg_resv_subnetto = dev->subnet_timeout;
pip->resv_resptimevalue = 3;
pip->localphyerrors_overrunerrors =
(get_phyerrthreshold(dd) << 4) |
get_overrunthreshold(dd);
if (dev->port_cap_flags & IB_PORT_LINK_LATENCY_SUP) {
u32 v;
v = dd->ipath_f_get_ib_cfg(dd, IPATH_IB_CFG_LINKLATENCY);
pip->link_roundtrip_latency[0] = v >> 16;
pip->link_roundtrip_latency[1] = v >> 8;
pip->link_roundtrip_latency[2] = v;
}
ret = reply(smp);
bail:
return ret;
}
static int get_pkeys(struct ipath_devdata *dd, u16 * pkeys)
{
struct ipath_portdata *pd = dd->ipath_pd[0];
memcpy(pkeys, pd->port_pkeys, sizeof(pd->port_pkeys));
return 0;
}
static int recv_subn_get_pkeytable(struct ib_smp *smp,
struct ib_device *ibdev)
{
u32 startpx = 32 * (be32_to_cpu(smp->attr_mod) & 0xffff);
u16 *p = (u16 *) smp->data;
__be16 *q = (__be16 *) smp->data;
memset(smp->data, 0, sizeof(smp->data));
if (startpx == 0) {
struct ipath_ibdev *dev = to_idev(ibdev);
unsigned i, n = ipath_get_npkeys(dev->dd);
get_pkeys(dev->dd, p);
for (i = 0; i < n; i++)
q[i] = cpu_to_be16(p[i]);
} else
smp->status |= IB_SMP_INVALID_FIELD;
return reply(smp);
}
static int recv_subn_set_guidinfo(struct ib_smp *smp,
struct ib_device *ibdev)
{
return recv_subn_get_guidinfo(smp, ibdev);
}
static int set_linkdowndefaultstate(struct ipath_devdata *dd, int sleep)
{
if (sleep)
dd->ipath_ibcctrl |= INFINIPATH_IBCC_LINKDOWNDEFAULTSTATE;
else
dd->ipath_ibcctrl &= ~INFINIPATH_IBCC_LINKDOWNDEFAULTSTATE;
ipath_write_kreg(dd, dd->ipath_kregs->kr_ibcctrl,
dd->ipath_ibcctrl);
return 0;
}
static int recv_subn_set_portinfo(struct ib_smp *smp,
struct ib_device *ibdev, u8 port)
{
struct ib_port_info *pip = (struct ib_port_info *)smp->data;
struct ib_event event;
struct ipath_ibdev *dev;
struct ipath_devdata *dd;
char clientrereg = 0;
u16 lid, smlid;
u8 lwe;
u8 lse;
u8 state;
u16 lstate;
u32 mtu;
int ret, ore;
if (be32_to_cpu(smp->attr_mod) > ibdev->phys_port_cnt)
goto err;
dev = to_idev(ibdev);
dd = dev->dd;
event.device = ibdev;
event.element.port_num = port;
dev->mkey = pip->mkey;
dev->gid_prefix = pip->gid_prefix;
dev->mkey_lease_period = be16_to_cpu(pip->mkey_lease_period);
lid = be16_to_cpu(pip->lid);
if (dd->ipath_lid != lid ||
dd->ipath_lmc != (pip->mkeyprot_resv_lmc & 7)) {
if (lid == 0 || lid >= IPATH_MULTICAST_LID_BASE)
goto err;
ipath_set_lid(dd, lid, pip->mkeyprot_resv_lmc & 7);
event.event = IB_EVENT_LID_CHANGE;
ib_dispatch_event(&event);
}
smlid = be16_to_cpu(pip->sm_lid);
if (smlid != dev->sm_lid) {
if (smlid == 0 || smlid >= IPATH_MULTICAST_LID_BASE)
goto err;
dev->sm_lid = smlid;
event.event = IB_EVENT_SM_CHANGE;
ib_dispatch_event(&event);
}
lwe = pip->link_width_enabled;
if (lwe) {
if (lwe == 0xFF)
lwe = dd->ipath_link_width_supported;
else if (lwe >= 16 || (lwe & ~dd->ipath_link_width_supported))
goto err;
set_link_width_enabled(dd, lwe);
}
lse = pip->linkspeedactive_enabled & 0xF;
if (lse) {
if (lse == 15)
lse = dd->ipath_link_speed_supported;
else if (lse >= 8 || (lse & ~dd->ipath_link_speed_supported))
goto err;
set_link_speed_enabled(dd, lse);
}
switch (pip->portphysstate_linkdown & 0xF) {
case 0:
break;
case 1:
if (set_linkdowndefaultstate(dd, 1))
goto err;
break;
case 2:
if (set_linkdowndefaultstate(dd, 0))
goto err;
break;
default:
goto err;
}
dev->mkeyprot = pip->mkeyprot_resv_lmc >> 6;
dev->vl_high_limit = pip->vl_high_limit;
switch ((pip->neighbormtu_mastersmsl >> 4) & 0xF) {
case IB_MTU_256:
mtu = 256;
break;
case IB_MTU_512:
mtu = 512;
break;
case IB_MTU_1024:
mtu = 1024;
break;
case IB_MTU_2048:
mtu = 2048;
break;
case IB_MTU_4096:
if (!ipath_mtu4096)
goto err;
mtu = 4096;
break;
default:
goto err;
}
ipath_set_mtu(dd, mtu);
dev->sm_sl = pip->neighbormtu_mastersmsl & 0xF;
if (((pip->operationalvl_pei_peo_fpi_fpo >> 4) & 0xF) > 1)
goto err;
if (pip->mkey_violations == 0)
dev->mkey_violations = 0;
if (pip->pkey_violations == 0)
dev->z_pkey_violations = ipath_get_cr_errpkey(dd);
if (pip->qkey_violations == 0)
dev->qkey_violations = 0;
ore = pip->localphyerrors_overrunerrors;
if (set_phyerrthreshold(dd, (ore >> 4) & 0xF))
goto err;
if (set_overrunthreshold(dd, (ore & 0xF)))
goto err;
dev->subnet_timeout = pip->clientrereg_resv_subnetto & 0x1F;
if (pip->clientrereg_resv_subnetto & 0x80) {
clientrereg = 1;
event.event = IB_EVENT_CLIENT_REREGISTER;
ib_dispatch_event(&event);
}
state = pip->linkspeed_portstate & 0xF;
lstate = (pip->portphysstate_linkdown >> 4) & 0xF;
if (lstate && !(state == IB_PORT_DOWN || state == IB_PORT_NOP))
goto err;
switch (state) {
case IB_PORT_NOP:
if (lstate == 0)
break;
case IB_PORT_DOWN:
if (lstate == 0)
lstate = IPATH_IB_LINKDOWN_ONLY;
else if (lstate == 1)
lstate = IPATH_IB_LINKDOWN_SLEEP;
else if (lstate == 2)
lstate = IPATH_IB_LINKDOWN;
else if (lstate == 3)
lstate = IPATH_IB_LINKDOWN_DISABLE;
else
goto err;
ipath_set_linkstate(dd, lstate);
if (lstate == IPATH_IB_LINKDOWN_DISABLE) {
ret = IB_MAD_RESULT_SUCCESS | IB_MAD_RESULT_CONSUMED;
goto done;
}
ipath_wait_linkstate(dd, IPATH_LINKINIT | IPATH_LINKARMED |
IPATH_LINKACTIVE, 1000);
break;
case IB_PORT_ARMED:
ipath_set_linkstate(dd, IPATH_IB_LINKARM);
break;
case IB_PORT_ACTIVE:
ipath_set_linkstate(dd, IPATH_IB_LINKACTIVE);
break;
default:
goto err;
}
ret = recv_subn_get_portinfo(smp, ibdev, port);
if (clientrereg)
pip->clientrereg_resv_subnetto |= 0x80;
goto done;
err:
smp->status |= IB_SMP_INVALID_FIELD;
ret = recv_subn_get_portinfo(smp, ibdev, port);
done:
return ret;
}
static int rm_pkey(struct ipath_devdata *dd, u16 key)
{
int i;
int ret;
for (i = 0; i < ARRAY_SIZE(dd->ipath_pkeys); i++) {
if (dd->ipath_pkeys[i] != key)
continue;
if (atomic_dec_and_test(&dd->ipath_pkeyrefs[i])) {
dd->ipath_pkeys[i] = 0;
ret = 1;
goto bail;
}
break;
}
ret = 0;
bail:
return ret;
}
static int add_pkey(struct ipath_devdata *dd, u16 key)
{
int i;
u16 lkey = key & 0x7FFF;
int any = 0;
int ret;
if (lkey == 0x7FFF) {
ret = 0;
goto bail;
}
for (i = 0; i < ARRAY_SIZE(dd->ipath_pkeys); i++) {
if (!dd->ipath_pkeys[i]) {
any++;
continue;
}
if (dd->ipath_pkeys[i] == key) {
if (atomic_inc_return(&dd->ipath_pkeyrefs[i]) > 1) {
ret = 0;
goto bail;
}
atomic_dec(&dd->ipath_pkeyrefs[i]);
any++;
}
if ((dd->ipath_pkeys[i] & 0x7FFF) == lkey) {
ret = -EEXIST;
goto bail;
}
}
if (!any) {
ret = -EBUSY;
goto bail;
}
for (i = 0; i < ARRAY_SIZE(dd->ipath_pkeys); i++) {
if (!dd->ipath_pkeys[i] &&
atomic_inc_return(&dd->ipath_pkeyrefs[i]) == 1) {
ipath_stats.sps_pkeys[i] = lkey;
dd->ipath_pkeys[i] = key;
ret = 1;
goto bail;
}
}
ret = -EBUSY;
bail:
return ret;
}
static int set_pkeys(struct ipath_devdata *dd, u16 *pkeys, u8 port)
{
struct ipath_portdata *pd;
int i;
int changed = 0;
pd = dd->ipath_pd[0];
for (i = 0; i < ARRAY_SIZE(pd->port_pkeys); i++) {
u16 key = pkeys[i];
u16 okey = pd->port_pkeys[i];
if (key == okey)
continue;
if (okey & 0x7FFF)
changed |= rm_pkey(dd, okey);
if (key & 0x7FFF) {
int ret = add_pkey(dd, key);
if (ret < 0)
key = 0;
else
changed |= ret;
}
pd->port_pkeys[i] = key;
}
if (changed) {
u64 pkey;
struct ib_event event;
pkey = (u64) dd->ipath_pkeys[0] |
((u64) dd->ipath_pkeys[1] << 16) |
((u64) dd->ipath_pkeys[2] << 32) |
((u64) dd->ipath_pkeys[3] << 48);
ipath_cdbg(VERBOSE, "p0 new pkey reg %llx\n",
(unsigned long long) pkey);
ipath_write_kreg(dd, dd->ipath_kregs->kr_partitionkey,
pkey);
event.event = IB_EVENT_PKEY_CHANGE;
event.device = &dd->verbs_dev->ibdev;
event.element.port_num = port;
ib_dispatch_event(&event);
}
return 0;
}
static int recv_subn_set_pkeytable(struct ib_smp *smp,
struct ib_device *ibdev, u8 port)
{
u32 startpx = 32 * (be32_to_cpu(smp->attr_mod) & 0xffff);
__be16 *p = (__be16 *) smp->data;
u16 *q = (u16 *) smp->data;
struct ipath_ibdev *dev = to_idev(ibdev);
unsigned i, n = ipath_get_npkeys(dev->dd);
for (i = 0; i < n; i++)
q[i] = be16_to_cpu(p[i]);
if (startpx != 0 || set_pkeys(dev->dd, q, port) != 0)
smp->status |= IB_SMP_INVALID_FIELD;
return recv_subn_get_pkeytable(smp, ibdev);
}
static int recv_pma_get_classportinfo(struct ib_pma_mad *pmp)
{
struct ib_class_port_info *p =
(struct ib_class_port_info *)pmp->data;
memset(pmp->data, 0, sizeof(pmp->data));
if (pmp->mad_hdr.attr_mod != 0)
pmp->mad_hdr.status |= IB_SMP_INVALID_FIELD;
p->capability_mask = cpu_to_be16(1 << 8);
p->base_version = 1;
p->class_version = 1;
p->resp_time_value = 18;
return reply((struct ib_smp *) pmp);
}
static int recv_pma_get_portsamplescontrol(struct ib_pma_mad *pmp,
struct ib_device *ibdev, u8 port)
{
struct ib_pma_portsamplescontrol *p =
(struct ib_pma_portsamplescontrol *)pmp->data;
struct ipath_ibdev *dev = to_idev(ibdev);
struct ipath_cregs const *crp = dev->dd->ipath_cregs;
unsigned long flags;
u8 port_select = p->port_select;
memset(pmp->data, 0, sizeof(pmp->data));
p->port_select = port_select;
if (pmp->mad_hdr.attr_mod != 0 ||
(port_select != port && port_select != 0xFF))
pmp->mad_hdr.status |= IB_SMP_INVALID_FIELD;
if (crp->cr_psstat)
p->tick = dev->dd->ipath_link_speed_active - 1;
else
p->tick = 250;
p->counter_width = 4;
p->counter_mask0_9 = COUNTER_MASK0_9;
spin_lock_irqsave(&dev->pending_lock, flags);
if (crp->cr_psstat)
p->sample_status = ipath_read_creg32(dev->dd, crp->cr_psstat);
else
p->sample_status = dev->pma_sample_status;
p->sample_start = cpu_to_be32(dev->pma_sample_start);
p->sample_interval = cpu_to_be32(dev->pma_sample_interval);
p->tag = cpu_to_be16(dev->pma_tag);
p->counter_select[0] = dev->pma_counter_select[0];
p->counter_select[1] = dev->pma_counter_select[1];
p->counter_select[2] = dev->pma_counter_select[2];
p->counter_select[3] = dev->pma_counter_select[3];
p->counter_select[4] = dev->pma_counter_select[4];
spin_unlock_irqrestore(&dev->pending_lock, flags);
return reply((struct ib_smp *) pmp);
}
static int recv_pma_set_portsamplescontrol(struct ib_pma_mad *pmp,
struct ib_device *ibdev, u8 port)
{
struct ib_pma_portsamplescontrol *p =
(struct ib_pma_portsamplescontrol *)pmp->data;
struct ipath_ibdev *dev = to_idev(ibdev);
struct ipath_cregs const *crp = dev->dd->ipath_cregs;
unsigned long flags;
u8 status;
int ret;
if (pmp->mad_hdr.attr_mod != 0 ||
(p->port_select != port && p->port_select != 0xFF)) {
pmp->mad_hdr.status |= IB_SMP_INVALID_FIELD;
ret = reply((struct ib_smp *) pmp);
goto bail;
}
spin_lock_irqsave(&dev->pending_lock, flags);
if (crp->cr_psstat)
status = ipath_read_creg32(dev->dd, crp->cr_psstat);
else
status = dev->pma_sample_status;
if (status == IB_PMA_SAMPLE_STATUS_DONE) {
dev->pma_sample_start = be32_to_cpu(p->sample_start);
dev->pma_sample_interval = be32_to_cpu(p->sample_interval);
dev->pma_tag = be16_to_cpu(p->tag);
dev->pma_counter_select[0] = p->counter_select[0];
dev->pma_counter_select[1] = p->counter_select[1];
dev->pma_counter_select[2] = p->counter_select[2];
dev->pma_counter_select[3] = p->counter_select[3];
dev->pma_counter_select[4] = p->counter_select[4];
if (crp->cr_psstat) {
ipath_write_creg(dev->dd, crp->cr_psinterval,
dev->pma_sample_interval);
ipath_write_creg(dev->dd, crp->cr_psstart,
dev->pma_sample_start);
} else
dev->pma_sample_status = IB_PMA_SAMPLE_STATUS_STARTED;
}
spin_unlock_irqrestore(&dev->pending_lock, flags);
ret = recv_pma_get_portsamplescontrol(pmp, ibdev, port);
bail:
return ret;
}
static u64 get_counter(struct ipath_ibdev *dev,
struct ipath_cregs const *crp,
__be16 sel)
{
u64 ret;
switch (sel) {
case IB_PMA_PORT_XMIT_DATA:
ret = (crp->cr_psxmitdatacount) ?
ipath_read_creg32(dev->dd, crp->cr_psxmitdatacount) :
dev->ipath_sword;
break;
case IB_PMA_PORT_RCV_DATA:
ret = (crp->cr_psrcvdatacount) ?
ipath_read_creg32(dev->dd, crp->cr_psrcvdatacount) :
dev->ipath_rword;
break;
case IB_PMA_PORT_XMIT_PKTS:
ret = (crp->cr_psxmitpktscount) ?
ipath_read_creg32(dev->dd, crp->cr_psxmitpktscount) :
dev->ipath_spkts;
break;
case IB_PMA_PORT_RCV_PKTS:
ret = (crp->cr_psrcvpktscount) ?
ipath_read_creg32(dev->dd, crp->cr_psrcvpktscount) :
dev->ipath_rpkts;
break;
case IB_PMA_PORT_XMIT_WAIT:
ret = (crp->cr_psxmitwaitcount) ?
ipath_read_creg32(dev->dd, crp->cr_psxmitwaitcount) :
dev->ipath_xmit_wait;
break;
default:
ret = 0;
}
return ret;
}
static int recv_pma_get_portsamplesresult(struct ib_pma_mad *pmp,
struct ib_device *ibdev)
{
struct ib_pma_portsamplesresult *p =
(struct ib_pma_portsamplesresult *)pmp->data;
struct ipath_ibdev *dev = to_idev(ibdev);
struct ipath_cregs const *crp = dev->dd->ipath_cregs;
u8 status;
int i;
memset(pmp->data, 0, sizeof(pmp->data));
p->tag = cpu_to_be16(dev->pma_tag);
if (crp->cr_psstat)
status = ipath_read_creg32(dev->dd, crp->cr_psstat);
else
status = dev->pma_sample_status;
p->sample_status = cpu_to_be16(status);
for (i = 0; i < ARRAY_SIZE(dev->pma_counter_select); i++)
p->counter[i] = (status != IB_PMA_SAMPLE_STATUS_DONE) ? 0 :
cpu_to_be32(
get_counter(dev, crp, dev->pma_counter_select[i]));
return reply((struct ib_smp *) pmp);
}
static int recv_pma_get_portsamplesresult_ext(struct ib_pma_mad *pmp,
struct ib_device *ibdev)
{
struct ib_pma_portsamplesresult_ext *p =
(struct ib_pma_portsamplesresult_ext *)pmp->data;
struct ipath_ibdev *dev = to_idev(ibdev);
struct ipath_cregs const *crp = dev->dd->ipath_cregs;
u8 status;
int i;
memset(pmp->data, 0, sizeof(pmp->data));
p->tag = cpu_to_be16(dev->pma_tag);
if (crp->cr_psstat)
status = ipath_read_creg32(dev->dd, crp->cr_psstat);
else
status = dev->pma_sample_status;
p->sample_status = cpu_to_be16(status);
p->extended_width = cpu_to_be32(0x80000000);
for (i = 0; i < ARRAY_SIZE(dev->pma_counter_select); i++)
p->counter[i] = (status != IB_PMA_SAMPLE_STATUS_DONE) ? 0 :
cpu_to_be64(
get_counter(dev, crp, dev->pma_counter_select[i]));
return reply((struct ib_smp *) pmp);
}
static int recv_pma_get_portcounters(struct ib_pma_mad *pmp,
struct ib_device *ibdev, u8 port)
{
struct ib_pma_portcounters *p = (struct ib_pma_portcounters *)
pmp->data;
struct ipath_ibdev *dev = to_idev(ibdev);
struct ipath_verbs_counters cntrs;
u8 port_select = p->port_select;
ipath_get_counters(dev->dd, &cntrs);
cntrs.symbol_error_counter -= dev->z_symbol_error_counter;
cntrs.link_error_recovery_counter -=
dev->z_link_error_recovery_counter;
cntrs.link_downed_counter -= dev->z_link_downed_counter;
cntrs.port_rcv_errors += dev->rcv_errors;
cntrs.port_rcv_errors -= dev->z_port_rcv_errors;
cntrs.port_rcv_remphys_errors -= dev->z_port_rcv_remphys_errors;
cntrs.port_xmit_discards -= dev->z_port_xmit_discards;
cntrs.port_xmit_data -= dev->z_port_xmit_data;
cntrs.port_rcv_data -= dev->z_port_rcv_data;
cntrs.port_xmit_packets -= dev->z_port_xmit_packets;
cntrs.port_rcv_packets -= dev->z_port_rcv_packets;
cntrs.local_link_integrity_errors -=
dev->z_local_link_integrity_errors;
cntrs.excessive_buffer_overrun_errors -=
dev->z_excessive_buffer_overrun_errors;
cntrs.vl15_dropped -= dev->z_vl15_dropped;
cntrs.vl15_dropped += dev->n_vl15_dropped;
memset(pmp->data, 0, sizeof(pmp->data));
p->port_select = port_select;
if (pmp->mad_hdr.attr_mod != 0 ||
(port_select != port && port_select != 0xFF))
pmp->mad_hdr.status |= IB_SMP_INVALID_FIELD;
if (cntrs.symbol_error_counter > 0xFFFFUL)
p->symbol_error_counter = cpu_to_be16(0xFFFF);
else
p->symbol_error_counter =
cpu_to_be16((u16)cntrs.symbol_error_counter);
if (cntrs.link_error_recovery_counter > 0xFFUL)
p->link_error_recovery_counter = 0xFF;
else
p->link_error_recovery_counter =
(u8)cntrs.link_error_recovery_counter;
if (cntrs.link_downed_counter > 0xFFUL)
p->link_downed_counter = 0xFF;
else
p->link_downed_counter = (u8)cntrs.link_downed_counter;
if (cntrs.port_rcv_errors > 0xFFFFUL)
p->port_rcv_errors = cpu_to_be16(0xFFFF);
else
p->port_rcv_errors =
cpu_to_be16((u16) cntrs.port_rcv_errors);
if (cntrs.port_rcv_remphys_errors > 0xFFFFUL)
p->port_rcv_remphys_errors = cpu_to_be16(0xFFFF);
else
p->port_rcv_remphys_errors =
cpu_to_be16((u16)cntrs.port_rcv_remphys_errors);
if (cntrs.port_xmit_discards > 0xFFFFUL)
p->port_xmit_discards = cpu_to_be16(0xFFFF);
else
p->port_xmit_discards =
cpu_to_be16((u16)cntrs.port_xmit_discards);
if (cntrs.local_link_integrity_errors > 0xFUL)
cntrs.local_link_integrity_errors = 0xFUL;
if (cntrs.excessive_buffer_overrun_errors > 0xFUL)
cntrs.excessive_buffer_overrun_errors = 0xFUL;
p->link_overrun_errors = (cntrs.local_link_integrity_errors << 4) |
cntrs.excessive_buffer_overrun_errors;
if (cntrs.vl15_dropped > 0xFFFFUL)
p->vl15_dropped = cpu_to_be16(0xFFFF);
else
p->vl15_dropped = cpu_to_be16((u16)cntrs.vl15_dropped);
if (cntrs.port_xmit_data > 0xFFFFFFFFUL)
p->port_xmit_data = cpu_to_be32(0xFFFFFFFF);
else
p->port_xmit_data = cpu_to_be32((u32)cntrs.port_xmit_data);
if (cntrs.port_rcv_data > 0xFFFFFFFFUL)
p->port_rcv_data = cpu_to_be32(0xFFFFFFFF);
else
p->port_rcv_data = cpu_to_be32((u32)cntrs.port_rcv_data);
if (cntrs.port_xmit_packets > 0xFFFFFFFFUL)
p->port_xmit_packets = cpu_to_be32(0xFFFFFFFF);
else
p->port_xmit_packets =
cpu_to_be32((u32)cntrs.port_xmit_packets);
if (cntrs.port_rcv_packets > 0xFFFFFFFFUL)
p->port_rcv_packets = cpu_to_be32(0xFFFFFFFF);
else
p->port_rcv_packets =
cpu_to_be32((u32) cntrs.port_rcv_packets);
return reply((struct ib_smp *) pmp);
}
static int recv_pma_get_portcounters_ext(struct ib_pma_mad *pmp,
struct ib_device *ibdev, u8 port)
{
struct ib_pma_portcounters_ext *p =
(struct ib_pma_portcounters_ext *)pmp->data;
struct ipath_ibdev *dev = to_idev(ibdev);
u64 swords, rwords, spkts, rpkts, xwait;
u8 port_select = p->port_select;
ipath_snapshot_counters(dev->dd, &swords, &rwords, &spkts,
&rpkts, &xwait);
swords -= dev->z_port_xmit_data;
rwords -= dev->z_port_rcv_data;
spkts -= dev->z_port_xmit_packets;
rpkts -= dev->z_port_rcv_packets;
memset(pmp->data, 0, sizeof(pmp->data));
p->port_select = port_select;
if (pmp->mad_hdr.attr_mod != 0 ||
(port_select != port && port_select != 0xFF))
pmp->mad_hdr.status |= IB_SMP_INVALID_FIELD;
p->port_xmit_data = cpu_to_be64(swords);
p->port_rcv_data = cpu_to_be64(rwords);
p->port_xmit_packets = cpu_to_be64(spkts);
p->port_rcv_packets = cpu_to_be64(rpkts);
p->port_unicast_xmit_packets = cpu_to_be64(dev->n_unicast_xmit);
p->port_unicast_rcv_packets = cpu_to_be64(dev->n_unicast_rcv);
p->port_multicast_xmit_packets = cpu_to_be64(dev->n_multicast_xmit);
p->port_multicast_rcv_packets = cpu_to_be64(dev->n_multicast_rcv);
return reply((struct ib_smp *) pmp);
}
static int recv_pma_set_portcounters(struct ib_pma_mad *pmp,
struct ib_device *ibdev, u8 port)
{
struct ib_pma_portcounters *p = (struct ib_pma_portcounters *)
pmp->data;
struct ipath_ibdev *dev = to_idev(ibdev);
struct ipath_verbs_counters cntrs;
ipath_get_counters(dev->dd, &cntrs);
if (p->counter_select & IB_PMA_SEL_SYMBOL_ERROR)
dev->z_symbol_error_counter = cntrs.symbol_error_counter;
if (p->counter_select & IB_PMA_SEL_LINK_ERROR_RECOVERY)
dev->z_link_error_recovery_counter =
cntrs.link_error_recovery_counter;
if (p->counter_select & IB_PMA_SEL_LINK_DOWNED)
dev->z_link_downed_counter = cntrs.link_downed_counter;
if (p->counter_select & IB_PMA_SEL_PORT_RCV_ERRORS)
dev->z_port_rcv_errors =
cntrs.port_rcv_errors + dev->rcv_errors;
if (p->counter_select & IB_PMA_SEL_PORT_RCV_REMPHYS_ERRORS)
dev->z_port_rcv_remphys_errors =
cntrs.port_rcv_remphys_errors;
if (p->counter_select & IB_PMA_SEL_PORT_XMIT_DISCARDS)
dev->z_port_xmit_discards = cntrs.port_xmit_discards;
if (p->counter_select & IB_PMA_SEL_LOCAL_LINK_INTEGRITY_ERRORS)
dev->z_local_link_integrity_errors =
cntrs.local_link_integrity_errors;
if (p->counter_select & IB_PMA_SEL_EXCESSIVE_BUFFER_OVERRUNS)
dev->z_excessive_buffer_overrun_errors =
cntrs.excessive_buffer_overrun_errors;
if (p->counter_select & IB_PMA_SEL_PORT_VL15_DROPPED) {
dev->n_vl15_dropped = 0;
dev->z_vl15_dropped = cntrs.vl15_dropped;
}
if (p->counter_select & IB_PMA_SEL_PORT_XMIT_DATA)
dev->z_port_xmit_data = cntrs.port_xmit_data;
if (p->counter_select & IB_PMA_SEL_PORT_RCV_DATA)
dev->z_port_rcv_data = cntrs.port_rcv_data;
if (p->counter_select & IB_PMA_SEL_PORT_XMIT_PACKETS)
dev->z_port_xmit_packets = cntrs.port_xmit_packets;
if (p->counter_select & IB_PMA_SEL_PORT_RCV_PACKETS)
dev->z_port_rcv_packets = cntrs.port_rcv_packets;
return recv_pma_get_portcounters(pmp, ibdev, port);
}
static int recv_pma_set_portcounters_ext(struct ib_pma_mad *pmp,
struct ib_device *ibdev, u8 port)
{
struct ib_pma_portcounters *p = (struct ib_pma_portcounters *)
pmp->data;
struct ipath_ibdev *dev = to_idev(ibdev);
u64 swords, rwords, spkts, rpkts, xwait;
ipath_snapshot_counters(dev->dd, &swords, &rwords, &spkts,
&rpkts, &xwait);
if (p->counter_select & IB_PMA_SELX_PORT_XMIT_DATA)
dev->z_port_xmit_data = swords;
if (p->counter_select & IB_PMA_SELX_PORT_RCV_DATA)
dev->z_port_rcv_data = rwords;
if (p->counter_select & IB_PMA_SELX_PORT_XMIT_PACKETS)
dev->z_port_xmit_packets = spkts;
if (p->counter_select & IB_PMA_SELX_PORT_RCV_PACKETS)
dev->z_port_rcv_packets = rpkts;
if (p->counter_select & IB_PMA_SELX_PORT_UNI_XMIT_PACKETS)
dev->n_unicast_xmit = 0;
if (p->counter_select & IB_PMA_SELX_PORT_UNI_RCV_PACKETS)
dev->n_unicast_rcv = 0;
if (p->counter_select & IB_PMA_SELX_PORT_MULTI_XMIT_PACKETS)
dev->n_multicast_xmit = 0;
if (p->counter_select & IB_PMA_SELX_PORT_MULTI_RCV_PACKETS)
dev->n_multicast_rcv = 0;
return recv_pma_get_portcounters_ext(pmp, ibdev, port);
}
static int process_subn(struct ib_device *ibdev, int mad_flags,
u8 port_num, struct ib_mad *in_mad,
struct ib_mad *out_mad)
{
struct ib_smp *smp = (struct ib_smp *)out_mad;
struct ipath_ibdev *dev = to_idev(ibdev);
int ret;
*out_mad = *in_mad;
if (smp->class_version != 1) {
smp->status |= IB_SMP_UNSUP_VERSION;
ret = reply(smp);
goto bail;
}
if (dev->mkey_lease_timeout &&
time_after_eq(jiffies, dev->mkey_lease_timeout)) {
dev->mkey_lease_timeout = 0;
dev->mkeyprot = 0;
}
if ((mad_flags & IB_MAD_IGNORE_MKEY) == 0 && dev->mkey != 0 &&
dev->mkey != smp->mkey &&
(smp->method == IB_MGMT_METHOD_SET ||
(smp->method == IB_MGMT_METHOD_GET &&
dev->mkeyprot >= 2))) {
if (dev->mkey_violations != 0xFFFF)
++dev->mkey_violations;
if (dev->mkey_lease_timeout ||
dev->mkey_lease_period == 0) {
ret = IB_MAD_RESULT_SUCCESS |
IB_MAD_RESULT_CONSUMED;
goto bail;
}
dev->mkey_lease_timeout = jiffies +
dev->mkey_lease_period * HZ;
ret = IB_MAD_RESULT_SUCCESS | IB_MAD_RESULT_CONSUMED;
goto bail;
} else if (dev->mkey_lease_timeout)
dev->mkey_lease_timeout = 0;
switch (smp->method) {
case IB_MGMT_METHOD_GET:
switch (smp->attr_id) {
case IB_SMP_ATTR_NODE_DESC:
ret = recv_subn_get_nodedescription(smp, ibdev);
goto bail;
case IB_SMP_ATTR_NODE_INFO:
ret = recv_subn_get_nodeinfo(smp, ibdev, port_num);
goto bail;
case IB_SMP_ATTR_GUID_INFO:
ret = recv_subn_get_guidinfo(smp, ibdev);
goto bail;
case IB_SMP_ATTR_PORT_INFO:
ret = recv_subn_get_portinfo(smp, ibdev, port_num);
goto bail;
case IB_SMP_ATTR_PKEY_TABLE:
ret = recv_subn_get_pkeytable(smp, ibdev);
goto bail;
case IB_SMP_ATTR_SM_INFO:
if (dev->port_cap_flags & IB_PORT_SM_DISABLED) {
ret = IB_MAD_RESULT_SUCCESS |
IB_MAD_RESULT_CONSUMED;
goto bail;
}
if (dev->port_cap_flags & IB_PORT_SM) {
ret = IB_MAD_RESULT_SUCCESS;
goto bail;
}
default:
smp->status |= IB_SMP_UNSUP_METH_ATTR;
ret = reply(smp);
goto bail;
}
case IB_MGMT_METHOD_SET:
switch (smp->attr_id) {
case IB_SMP_ATTR_GUID_INFO:
ret = recv_subn_set_guidinfo(smp, ibdev);
goto bail;
case IB_SMP_ATTR_PORT_INFO:
ret = recv_subn_set_portinfo(smp, ibdev, port_num);
goto bail;
case IB_SMP_ATTR_PKEY_TABLE:
ret = recv_subn_set_pkeytable(smp, ibdev, port_num);
goto bail;
case IB_SMP_ATTR_SM_INFO:
if (dev->port_cap_flags & IB_PORT_SM_DISABLED) {
ret = IB_MAD_RESULT_SUCCESS |
IB_MAD_RESULT_CONSUMED;
goto bail;
}
if (dev->port_cap_flags & IB_PORT_SM) {
ret = IB_MAD_RESULT_SUCCESS;
goto bail;
}
default:
smp->status |= IB_SMP_UNSUP_METH_ATTR;
ret = reply(smp);
goto bail;
}
case IB_MGMT_METHOD_TRAP:
case IB_MGMT_METHOD_REPORT:
case IB_MGMT_METHOD_REPORT_RESP:
case IB_MGMT_METHOD_TRAP_REPRESS:
case IB_MGMT_METHOD_GET_RESP:
ret = IB_MAD_RESULT_SUCCESS;
goto bail;
default:
smp->status |= IB_SMP_UNSUP_METHOD;
ret = reply(smp);
}
bail:
return ret;
}
static int process_perf(struct ib_device *ibdev, u8 port_num,
struct ib_mad *in_mad,
struct ib_mad *out_mad)
{
struct ib_pma_mad *pmp = (struct ib_pma_mad *)out_mad;
int ret;
*out_mad = *in_mad;
if (pmp->mad_hdr.class_version != 1) {
pmp->mad_hdr.status |= IB_SMP_UNSUP_VERSION;
ret = reply((struct ib_smp *) pmp);
goto bail;
}
switch (pmp->mad_hdr.method) {
case IB_MGMT_METHOD_GET:
switch (pmp->mad_hdr.attr_id) {
case IB_PMA_CLASS_PORT_INFO:
ret = recv_pma_get_classportinfo(pmp);
goto bail;
case IB_PMA_PORT_SAMPLES_CONTROL:
ret = recv_pma_get_portsamplescontrol(pmp, ibdev,
port_num);
goto bail;
case IB_PMA_PORT_SAMPLES_RESULT:
ret = recv_pma_get_portsamplesresult(pmp, ibdev);
goto bail;
case IB_PMA_PORT_SAMPLES_RESULT_EXT:
ret = recv_pma_get_portsamplesresult_ext(pmp,
ibdev);
goto bail;
case IB_PMA_PORT_COUNTERS:
ret = recv_pma_get_portcounters(pmp, ibdev,
port_num);
goto bail;
case IB_PMA_PORT_COUNTERS_EXT:
ret = recv_pma_get_portcounters_ext(pmp, ibdev,
port_num);
goto bail;
default:
pmp->mad_hdr.status |= IB_SMP_UNSUP_METH_ATTR;
ret = reply((struct ib_smp *) pmp);
goto bail;
}
case IB_MGMT_METHOD_SET:
switch (pmp->mad_hdr.attr_id) {
case IB_PMA_PORT_SAMPLES_CONTROL:
ret = recv_pma_set_portsamplescontrol(pmp, ibdev,
port_num);
goto bail;
case IB_PMA_PORT_COUNTERS:
ret = recv_pma_set_portcounters(pmp, ibdev,
port_num);
goto bail;
case IB_PMA_PORT_COUNTERS_EXT:
ret = recv_pma_set_portcounters_ext(pmp, ibdev,
port_num);
goto bail;
default:
pmp->mad_hdr.status |= IB_SMP_UNSUP_METH_ATTR;
ret = reply((struct ib_smp *) pmp);
goto bail;
}
case IB_MGMT_METHOD_GET_RESP:
ret = IB_MAD_RESULT_SUCCESS;
goto bail;
default:
pmp->mad_hdr.status |= IB_SMP_UNSUP_METHOD;
ret = reply((struct ib_smp *) pmp);
}
bail:
return ret;
}
int ipath_process_mad(struct ib_device *ibdev, int mad_flags, u8 port_num,
struct ib_wc *in_wc, struct ib_grh *in_grh,
struct ib_mad *in_mad, struct ib_mad *out_mad)
{
int ret;
switch (in_mad->mad_hdr.mgmt_class) {
case IB_MGMT_CLASS_SUBN_DIRECTED_ROUTE:
case IB_MGMT_CLASS_SUBN_LID_ROUTED:
ret = process_subn(ibdev, mad_flags, port_num,
in_mad, out_mad);
goto bail;
case IB_MGMT_CLASS_PERF_MGMT:
ret = process_perf(ibdev, port_num, in_mad, out_mad);
goto bail;
default:
ret = IB_MAD_RESULT_SUCCESS;
}
bail:
return ret;
}
