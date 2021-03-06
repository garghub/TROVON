static int
mptfc_block_error_handler(struct scsi_cmnd *SCpnt,
int (*func)(struct scsi_cmnd *SCpnt),
const char *caller)
{
MPT_SCSI_HOST *hd;
struct scsi_device *sdev = SCpnt->device;
struct Scsi_Host *shost = sdev->host;
struct fc_rport *rport = starget_to_rport(scsi_target(sdev));
unsigned long flags;
int ready;
MPT_ADAPTER *ioc;
int loops = 40;
hd = shost_priv(SCpnt->device->host);
ioc = hd->ioc;
spin_lock_irqsave(shost->host_lock, flags);
while ((ready = fc_remote_port_chkready(rport) >> 16) == DID_IMM_RETRY
|| (loops > 0 && ioc->active == 0)) {
spin_unlock_irqrestore(shost->host_lock, flags);
dfcprintk (ioc, printk(MYIOC_s_DEBUG_FMT
"mptfc_block_error_handler.%d: %d:%llu, port status is "
"%x, active flag %d, deferring %s recovery.\n",
ioc->name, ioc->sh->host_no,
SCpnt->device->id, SCpnt->device->lun,
ready, ioc->active, caller));
msleep(1000);
spin_lock_irqsave(shost->host_lock, flags);
loops --;
}
spin_unlock_irqrestore(shost->host_lock, flags);
if (ready == DID_NO_CONNECT || !SCpnt->device->hostdata
|| ioc->active == 0) {
dfcprintk (ioc, printk(MYIOC_s_DEBUG_FMT
"%s.%d: %d:%llu, failing recovery, "
"port state %x, active %d, vdevice %p.\n", caller,
ioc->name, ioc->sh->host_no,
SCpnt->device->id, SCpnt->device->lun, ready,
ioc->active, SCpnt->device->hostdata));
return FAILED;
}
dfcprintk (ioc, printk(MYIOC_s_DEBUG_FMT
"%s.%d: %d:%llu, executing recovery.\n", caller,
ioc->name, ioc->sh->host_no,
SCpnt->device->id, SCpnt->device->lun));
return (*func)(SCpnt);
}
static int
mptfc_abort(struct scsi_cmnd *SCpnt)
{
return
mptfc_block_error_handler(SCpnt, mptscsih_abort, __func__);
}
static int
mptfc_dev_reset(struct scsi_cmnd *SCpnt)
{
return
mptfc_block_error_handler(SCpnt, mptscsih_dev_reset, __func__);
}
static int
mptfc_bus_reset(struct scsi_cmnd *SCpnt)
{
return
mptfc_block_error_handler(SCpnt, mptscsih_bus_reset, __func__);
}
static void
mptfc_set_rport_loss_tmo(struct fc_rport *rport, uint32_t timeout)
{
if (timeout > 0)
rport->dev_loss_tmo = timeout;
else
rport->dev_loss_tmo = mptfc_dev_loss_tmo;
}
static int
mptfc_FcDevPage0_cmp_func(const void *a, const void *b)
{
FCDevicePage0_t **aa = (FCDevicePage0_t **)a;
FCDevicePage0_t **bb = (FCDevicePage0_t **)b;
if ((*aa)->CurrentBus == (*bb)->CurrentBus) {
if ((*aa)->CurrentTargetID == (*bb)->CurrentTargetID)
return 0;
if ((*aa)->CurrentTargetID < (*bb)->CurrentTargetID)
return -1;
return 1;
}
if ((*aa)->CurrentBus < (*bb)->CurrentBus)
return -1;
return 1;
}
static int
mptfc_GetFcDevPage0(MPT_ADAPTER *ioc, int ioc_port,
void(*func)(MPT_ADAPTER *ioc,int channel, FCDevicePage0_t *arg))
{
ConfigPageHeader_t hdr;
CONFIGPARMS cfg;
FCDevicePage0_t *ppage0_alloc, *fc;
dma_addr_t page0_dma;
int data_sz;
int ii;
FCDevicePage0_t *p0_array=NULL, *p_p0;
FCDevicePage0_t **pp0_array=NULL, **p_pp0;
int rc = -ENOMEM;
U32 port_id = 0xffffff;
int num_targ = 0;
int max_bus = ioc->facts.MaxBuses;
int max_targ;
max_targ = (ioc->facts.MaxDevices == 0) ? 256 : ioc->facts.MaxDevices;
data_sz = sizeof(FCDevicePage0_t) * max_bus * max_targ;
p_p0 = p0_array = kzalloc(data_sz, GFP_KERNEL);
if (!p0_array)
goto out;
data_sz = sizeof(FCDevicePage0_t *) * max_bus * max_targ;
p_pp0 = pp0_array = kzalloc(data_sz, GFP_KERNEL);
if (!pp0_array)
goto out;
do {
hdr.PageVersion = 0;
hdr.PageLength = 0;
hdr.PageNumber = 0;
hdr.PageType = MPI_CONFIG_PAGETYPE_FC_DEVICE;
cfg.cfghdr.hdr = &hdr;
cfg.physAddr = -1;
cfg.action = MPI_CONFIG_ACTION_PAGE_HEADER;
cfg.dir = 0;
cfg.pageAddr = port_id;
cfg.timeout = 0;
if ((rc = mpt_config(ioc, &cfg)) != 0)
break;
if (hdr.PageLength <= 0)
break;
data_sz = hdr.PageLength * 4;
ppage0_alloc = pci_alloc_consistent(ioc->pcidev, data_sz,
&page0_dma);
rc = -ENOMEM;
if (!ppage0_alloc)
break;
cfg.physAddr = page0_dma;
cfg.action = MPI_CONFIG_ACTION_PAGE_READ_CURRENT;
if ((rc = mpt_config(ioc, &cfg)) == 0) {
ppage0_alloc->PortIdentifier =
le32_to_cpu(ppage0_alloc->PortIdentifier);
ppage0_alloc->WWNN.Low =
le32_to_cpu(ppage0_alloc->WWNN.Low);
ppage0_alloc->WWNN.High =
le32_to_cpu(ppage0_alloc->WWNN.High);
ppage0_alloc->WWPN.Low =
le32_to_cpu(ppage0_alloc->WWPN.Low);
ppage0_alloc->WWPN.High =
le32_to_cpu(ppage0_alloc->WWPN.High);
ppage0_alloc->BBCredit =
le16_to_cpu(ppage0_alloc->BBCredit);
ppage0_alloc->MaxRxFrameSize =
le16_to_cpu(ppage0_alloc->MaxRxFrameSize);
port_id = ppage0_alloc->PortIdentifier;
num_targ++;
*p_p0 = *ppage0_alloc;
*p_pp0++ = p_p0++;
}
pci_free_consistent(ioc->pcidev, data_sz,
(u8 *) ppage0_alloc, page0_dma);
if (rc != 0)
break;
} while (port_id <= 0xff0000);
if (num_targ) {
if (num_targ > 1)
sort (pp0_array, num_targ, sizeof(FCDevicePage0_t *),
mptfc_FcDevPage0_cmp_func, NULL);
for (ii = 0; ii < num_targ; ii++) {
fc = *(pp0_array+ii);
func(ioc, ioc_port, fc);
}
}
out:
kfree(pp0_array);
kfree(p0_array);
return rc;
}
static int
mptfc_generate_rport_ids(FCDevicePage0_t *pg0, struct fc_rport_identifiers *rid)
{
if (pg0->Flags & (MPI_FC_DEVICE_PAGE0_FLAGS_PLOGI_INVALID |
MPI_FC_DEVICE_PAGE0_FLAGS_PRLI_INVALID))
return -1;
if (!(pg0->Flags & MPI_FC_DEVICE_PAGE0_FLAGS_TARGETID_BUS_VALID))
return -1;
if (!(pg0->Protocol & MPI_FC_DEVICE_PAGE0_PROT_FCP_TARGET))
return -1;
rid->node_name = ((u64)pg0->WWNN.High) << 32 | (u64)pg0->WWNN.Low;
rid->port_name = ((u64)pg0->WWPN.High) << 32 | (u64)pg0->WWPN.Low;
rid->port_id = pg0->PortIdentifier;
rid->roles = FC_RPORT_ROLE_UNKNOWN;
return 0;
}
static void
mptfc_register_dev(MPT_ADAPTER *ioc, int channel, FCDevicePage0_t *pg0)
{
struct fc_rport_identifiers rport_ids;
struct fc_rport *rport;
struct mptfc_rport_info *ri;
int new_ri = 1;
u64 pn, nn;
VirtTarget *vtarget;
u32 roles = FC_RPORT_ROLE_UNKNOWN;
if (mptfc_generate_rport_ids(pg0, &rport_ids) < 0)
return;
roles |= FC_RPORT_ROLE_FCP_TARGET;
if (pg0->Protocol & MPI_FC_DEVICE_PAGE0_PROT_FCP_INITIATOR)
roles |= FC_RPORT_ROLE_FCP_INITIATOR;
list_for_each_entry(ri, &ioc->fc_rports, list) {
pn = (u64)ri->pg0.WWPN.High << 32 | (u64)ri->pg0.WWPN.Low;
if (pn == rport_ids.port_name) {
list_move_tail(&ri->list, &ioc->fc_rports);
new_ri = 0;
break;
}
}
if (new_ri) {
ri = kzalloc(sizeof(struct mptfc_rport_info), GFP_KERNEL);
if (!ri)
return;
list_add_tail(&ri->list, &ioc->fc_rports);
}
ri->pg0 = *pg0;
ri->flags &= ~MPT_RPORT_INFO_FLAGS_MISSING;
if (!(ri->flags & MPT_RPORT_INFO_FLAGS_REGISTERED)) {
ri->flags |= MPT_RPORT_INFO_FLAGS_REGISTERED;
rport = fc_remote_port_add(ioc->sh, channel, &rport_ids);
if (rport) {
ri->rport = rport;
if (new_ri)
rport->dev_loss_tmo = mptfc_dev_loss_tmo;
if (ri->starget) {
vtarget = ri->starget->hostdata;
if (vtarget) {
vtarget->id = pg0->CurrentTargetID;
vtarget->channel = pg0->CurrentBus;
vtarget->deleted = 0;
}
}
*((struct mptfc_rport_info **)rport->dd_data) = ri;
fc_remote_port_rolechg(rport,roles);
pn = (u64)ri->pg0.WWPN.High << 32 | (u64)ri->pg0.WWPN.Low;
nn = (u64)ri->pg0.WWNN.High << 32 | (u64)ri->pg0.WWNN.Low;
dfcprintk (ioc, printk(MYIOC_s_DEBUG_FMT
"mptfc_reg_dev.%d: %x, %llx / %llx, tid %d, "
"rport tid %d, tmo %d\n",
ioc->name,
ioc->sh->host_no,
pg0->PortIdentifier,
(unsigned long long)nn,
(unsigned long long)pn,
pg0->CurrentTargetID,
ri->rport->scsi_target_id,
ri->rport->dev_loss_tmo));
} else {
list_del(&ri->list);
kfree(ri);
ri = NULL;
}
}
}
static void
mptfc_target_destroy(struct scsi_target *starget)
{
struct fc_rport *rport;
struct mptfc_rport_info *ri;
rport = starget_to_rport(starget);
if (rport) {
ri = *((struct mptfc_rport_info **)rport->dd_data);
if (ri)
ri->starget = NULL;
}
kfree(starget->hostdata);
starget->hostdata = NULL;
}
static int
mptfc_target_alloc(struct scsi_target *starget)
{
VirtTarget *vtarget;
struct fc_rport *rport;
struct mptfc_rport_info *ri;
int rc;
vtarget = kzalloc(sizeof(VirtTarget), GFP_KERNEL);
if (!vtarget)
return -ENOMEM;
starget->hostdata = vtarget;
rc = -ENODEV;
rport = starget_to_rport(starget);
if (rport) {
ri = *((struct mptfc_rport_info **)rport->dd_data);
if (ri) {
vtarget->id = ri->pg0.CurrentTargetID;
vtarget->channel = ri->pg0.CurrentBus;
ri->starget = starget;
rc = 0;
}
}
if (rc != 0) {
kfree(vtarget);
starget->hostdata = NULL;
}
return rc;
}
static void
mptfc_dump_lun_info(MPT_ADAPTER *ioc, struct fc_rport *rport, struct scsi_device *sdev,
VirtTarget *vtarget)
{
u64 nn, pn;
struct mptfc_rport_info *ri;
ri = *((struct mptfc_rport_info **)rport->dd_data);
pn = (u64)ri->pg0.WWPN.High << 32 | (u64)ri->pg0.WWPN.Low;
nn = (u64)ri->pg0.WWNN.High << 32 | (u64)ri->pg0.WWNN.Low;
dfcprintk (ioc, printk(MYIOC_s_DEBUG_FMT
"mptfc_slv_alloc.%d: num_luns %d, sdev.id %d, "
"CurrentTargetID %d, %x %llx %llx\n",
ioc->name,
sdev->host->host_no,
vtarget->num_luns,
sdev->id, ri->pg0.CurrentTargetID,
ri->pg0.PortIdentifier,
(unsigned long long)pn,
(unsigned long long)nn));
}
static int
mptfc_slave_alloc(struct scsi_device *sdev)
{
MPT_SCSI_HOST *hd;
VirtTarget *vtarget;
VirtDevice *vdevice;
struct scsi_target *starget;
struct fc_rport *rport;
MPT_ADAPTER *ioc;
starget = scsi_target(sdev);
rport = starget_to_rport(starget);
if (!rport || fc_remote_port_chkready(rport))
return -ENXIO;
hd = shost_priv(sdev->host);
ioc = hd->ioc;
vdevice = kzalloc(sizeof(VirtDevice), GFP_KERNEL);
if (!vdevice) {
printk(MYIOC_s_ERR_FMT "slave_alloc kmalloc(%zd) FAILED!\n",
ioc->name, sizeof(VirtDevice));
return -ENOMEM;
}
sdev->hostdata = vdevice;
vtarget = starget->hostdata;
if (vtarget->num_luns == 0) {
vtarget->ioc_id = ioc->id;
vtarget->tflags = MPT_TARGET_FLAGS_Q_YES;
}
vdevice->vtarget = vtarget;
vdevice->lun = sdev->lun;
vtarget->num_luns++;
mptfc_dump_lun_info(ioc, rport, sdev, vtarget);
return 0;
}
static int
mptfc_qcmd(struct Scsi_Host *shost, struct scsi_cmnd *SCpnt)
{
struct mptfc_rport_info *ri;
struct fc_rport *rport = starget_to_rport(scsi_target(SCpnt->device));
int err;
VirtDevice *vdevice = SCpnt->device->hostdata;
if (!vdevice || !vdevice->vtarget) {
SCpnt->result = DID_NO_CONNECT << 16;
SCpnt->scsi_done(SCpnt);
return 0;
}
err = fc_remote_port_chkready(rport);
if (unlikely(err)) {
SCpnt->result = err;
SCpnt->scsi_done(SCpnt);
return 0;
}
ri = *((struct mptfc_rport_info **)rport->dd_data);
if (unlikely(!ri)) {
SCpnt->result = DID_IMM_RETRY << 16;
SCpnt->scsi_done(SCpnt);
return 0;
}
return mptscsih_qcmd(SCpnt);
}
static void
mptfc_display_port_link_speed(MPT_ADAPTER *ioc, int portnum, FCPortPage0_t *pp0dest)
{
u8 old_speed, new_speed, state;
char *old, *new;
if (portnum >= 2)
return;
old_speed = ioc->fc_link_speed[portnum];
new_speed = pp0dest->CurrentSpeed;
state = pp0dest->PortState;
if (state != MPI_FCPORTPAGE0_PORTSTATE_OFFLINE &&
new_speed != MPI_FCPORTPAGE0_CURRENT_SPEED_UKNOWN) {
old = old_speed == MPI_FCPORTPAGE0_CURRENT_SPEED_1GBIT ? "1 Gbps" :
old_speed == MPI_FCPORTPAGE0_CURRENT_SPEED_2GBIT ? "2 Gbps" :
old_speed == MPI_FCPORTPAGE0_CURRENT_SPEED_4GBIT ? "4 Gbps" :
"Unknown";
new = new_speed == MPI_FCPORTPAGE0_CURRENT_SPEED_1GBIT ? "1 Gbps" :
new_speed == MPI_FCPORTPAGE0_CURRENT_SPEED_2GBIT ? "2 Gbps" :
new_speed == MPI_FCPORTPAGE0_CURRENT_SPEED_4GBIT ? "4 Gbps" :
"Unknown";
if (old_speed == 0)
printk(MYIOC_s_NOTE_FMT
"FC Link Established, Speed = %s\n",
ioc->name, new);
else if (old_speed != new_speed)
printk(MYIOC_s_WARN_FMT
"FC Link Speed Change, Old Speed = %s, New Speed = %s\n",
ioc->name, old, new);
ioc->fc_link_speed[portnum] = new_speed;
}
}
static int
mptfc_GetFcPortPage0(MPT_ADAPTER *ioc, int portnum)
{
ConfigPageHeader_t hdr;
CONFIGPARMS cfg;
FCPortPage0_t *ppage0_alloc;
FCPortPage0_t *pp0dest;
dma_addr_t page0_dma;
int data_sz;
int copy_sz;
int rc;
int count = 400;
if (portnum > 1)
return -EINVAL;
hdr.PageVersion = 0;
hdr.PageLength = 0;
hdr.PageNumber = 0;
hdr.PageType = MPI_CONFIG_PAGETYPE_FC_PORT;
cfg.cfghdr.hdr = &hdr;
cfg.physAddr = -1;
cfg.action = MPI_CONFIG_ACTION_PAGE_HEADER;
cfg.dir = 0;
cfg.pageAddr = portnum;
cfg.timeout = 0;
if ((rc = mpt_config(ioc, &cfg)) != 0)
return rc;
if (hdr.PageLength == 0)
return 0;
data_sz = hdr.PageLength * 4;
rc = -ENOMEM;
ppage0_alloc = (FCPortPage0_t *) pci_alloc_consistent(ioc->pcidev, data_sz, &page0_dma);
if (ppage0_alloc) {
try_again:
memset((u8 *)ppage0_alloc, 0, data_sz);
cfg.physAddr = page0_dma;
cfg.action = MPI_CONFIG_ACTION_PAGE_READ_CURRENT;
if ((rc = mpt_config(ioc, &cfg)) == 0) {
pp0dest = &ioc->fc_port_page0[portnum];
copy_sz = min_t(int, sizeof(FCPortPage0_t), data_sz);
memcpy(pp0dest, ppage0_alloc, copy_sz);
pp0dest->Flags = le32_to_cpu(pp0dest->Flags);
pp0dest->PortIdentifier = le32_to_cpu(pp0dest->PortIdentifier);
pp0dest->WWNN.Low = le32_to_cpu(pp0dest->WWNN.Low);
pp0dest->WWNN.High = le32_to_cpu(pp0dest->WWNN.High);
pp0dest->WWPN.Low = le32_to_cpu(pp0dest->WWPN.Low);
pp0dest->WWPN.High = le32_to_cpu(pp0dest->WWPN.High);
pp0dest->SupportedServiceClass = le32_to_cpu(pp0dest->SupportedServiceClass);
pp0dest->SupportedSpeeds = le32_to_cpu(pp0dest->SupportedSpeeds);
pp0dest->CurrentSpeed = le32_to_cpu(pp0dest->CurrentSpeed);
pp0dest->MaxFrameSize = le32_to_cpu(pp0dest->MaxFrameSize);
pp0dest->FabricWWNN.Low = le32_to_cpu(pp0dest->FabricWWNN.Low);
pp0dest->FabricWWNN.High = le32_to_cpu(pp0dest->FabricWWNN.High);
pp0dest->FabricWWPN.Low = le32_to_cpu(pp0dest->FabricWWPN.Low);
pp0dest->FabricWWPN.High = le32_to_cpu(pp0dest->FabricWWPN.High);
pp0dest->DiscoveredPortsCount = le32_to_cpu(pp0dest->DiscoveredPortsCount);
pp0dest->MaxInitiators = le32_to_cpu(pp0dest->MaxInitiators);
if ((pp0dest->PortState == MPI_FCPORTPAGE0_PORTSTATE_UNKNOWN) ||
(pp0dest->PortState == MPI_FCPORTPAGE0_PORTSTATE_ONLINE &&
(pp0dest->Flags & MPI_FCPORTPAGE0_FLAGS_ATTACH_TYPE_MASK)
== MPI_FCPORTPAGE0_FLAGS_ATTACH_NO_INIT)) {
if (count-- > 0) {
msleep(100);
goto try_again;
}
printk(MYIOC_s_INFO_FMT "Firmware discovery not"
" complete.\n",
ioc->name);
}
mptfc_display_port_link_speed(ioc, portnum, pp0dest);
}
pci_free_consistent(ioc->pcidev, data_sz, (u8 *) ppage0_alloc, page0_dma);
}
return rc;
}
static int
mptfc_WriteFcPortPage1(MPT_ADAPTER *ioc, int portnum)
{
ConfigPageHeader_t hdr;
CONFIGPARMS cfg;
int rc;
if (portnum > 1)
return -EINVAL;
if (!(ioc->fc_data.fc_port_page1[portnum].data))
return -EINVAL;
hdr.PageVersion = 0;
hdr.PageLength = 0;
hdr.PageNumber = 1;
hdr.PageType = MPI_CONFIG_PAGETYPE_FC_PORT;
cfg.cfghdr.hdr = &hdr;
cfg.physAddr = -1;
cfg.action = MPI_CONFIG_ACTION_PAGE_HEADER;
cfg.dir = 0;
cfg.pageAddr = portnum;
cfg.timeout = 0;
if ((rc = mpt_config(ioc, &cfg)) != 0)
return rc;
if (hdr.PageLength == 0)
return -ENODEV;
if (hdr.PageLength*4 != ioc->fc_data.fc_port_page1[portnum].pg_sz)
return -EINVAL;
cfg.physAddr = ioc->fc_data.fc_port_page1[portnum].dma;
cfg.action = MPI_CONFIG_ACTION_PAGE_WRITE_CURRENT;
cfg.dir = 1;
rc = mpt_config(ioc, &cfg);
return rc;
}
static int
mptfc_GetFcPortPage1(MPT_ADAPTER *ioc, int portnum)
{
ConfigPageHeader_t hdr;
CONFIGPARMS cfg;
FCPortPage1_t *page1_alloc;
dma_addr_t page1_dma;
int data_sz;
int rc;
if (portnum > 1)
return -EINVAL;
hdr.PageVersion = 0;
hdr.PageLength = 0;
hdr.PageNumber = 1;
hdr.PageType = MPI_CONFIG_PAGETYPE_FC_PORT;
cfg.cfghdr.hdr = &hdr;
cfg.physAddr = -1;
cfg.action = MPI_CONFIG_ACTION_PAGE_HEADER;
cfg.dir = 0;
cfg.pageAddr = portnum;
cfg.timeout = 0;
if ((rc = mpt_config(ioc, &cfg)) != 0)
return rc;
if (hdr.PageLength == 0)
return -ENODEV;
start_over:
if (ioc->fc_data.fc_port_page1[portnum].data == NULL) {
data_sz = hdr.PageLength * 4;
if (data_sz < sizeof(FCPortPage1_t))
data_sz = sizeof(FCPortPage1_t);
page1_alloc = (FCPortPage1_t *) pci_alloc_consistent(ioc->pcidev,
data_sz,
&page1_dma);
if (!page1_alloc)
return -ENOMEM;
}
else {
page1_alloc = ioc->fc_data.fc_port_page1[portnum].data;
page1_dma = ioc->fc_data.fc_port_page1[portnum].dma;
data_sz = ioc->fc_data.fc_port_page1[portnum].pg_sz;
if (hdr.PageLength * 4 > data_sz) {
ioc->fc_data.fc_port_page1[portnum].data = NULL;
pci_free_consistent(ioc->pcidev, data_sz, (u8 *)
page1_alloc, page1_dma);
goto start_over;
}
}
memset(page1_alloc,0,data_sz);
cfg.physAddr = page1_dma;
cfg.action = MPI_CONFIG_ACTION_PAGE_READ_CURRENT;
if ((rc = mpt_config(ioc, &cfg)) == 0) {
ioc->fc_data.fc_port_page1[portnum].data = page1_alloc;
ioc->fc_data.fc_port_page1[portnum].pg_sz = data_sz;
ioc->fc_data.fc_port_page1[portnum].dma = page1_dma;
}
else {
ioc->fc_data.fc_port_page1[portnum].data = NULL;
pci_free_consistent(ioc->pcidev, data_sz, (u8 *)
page1_alloc, page1_dma);
}
return rc;
}
static void
mptfc_SetFcPortPage1_defaults(MPT_ADAPTER *ioc)
{
int ii;
FCPortPage1_t *pp1;
#define MPTFC_FW_DEVICE_TIMEOUT (1)
#define MPTFC_FW_IO_PEND_TIMEOUT (1)
#define ON_FLAGS (MPI_FCPORTPAGE1_FLAGS_IMMEDIATE_ERROR_REPLY)
#define OFF_FLAGS (MPI_FCPORTPAGE1_FLAGS_VERBOSE_RESCAN_EVENTS)
for (ii=0; ii<ioc->facts.NumberOfPorts; ii++) {
if (mptfc_GetFcPortPage1(ioc, ii) != 0)
continue;
pp1 = ioc->fc_data.fc_port_page1[ii].data;
if ((pp1->InitiatorDeviceTimeout == MPTFC_FW_DEVICE_TIMEOUT)
&& (pp1->InitiatorIoPendTimeout == MPTFC_FW_IO_PEND_TIMEOUT)
&& ((pp1->Flags & ON_FLAGS) == ON_FLAGS)
&& ((pp1->Flags & OFF_FLAGS) == 0))
continue;
pp1->InitiatorDeviceTimeout = MPTFC_FW_DEVICE_TIMEOUT;
pp1->InitiatorIoPendTimeout = MPTFC_FW_IO_PEND_TIMEOUT;
pp1->Flags &= ~OFF_FLAGS;
pp1->Flags |= ON_FLAGS;
mptfc_WriteFcPortPage1(ioc, ii);
}
}
static void
mptfc_init_host_attr(MPT_ADAPTER *ioc,int portnum)
{
unsigned class = 0;
unsigned cos = 0;
unsigned speed;
unsigned port_type;
unsigned port_state;
FCPortPage0_t *pp0;
struct Scsi_Host *sh;
char *sn;
if (portnum != 0)
return;
pp0 = &ioc->fc_port_page0[portnum];
sh = ioc->sh;
sn = fc_host_symbolic_name(sh);
snprintf(sn, FC_SYMBOLIC_NAME_SIZE, "%s %s%08xh",
ioc->prod_name,
MPT_FW_REV_MAGIC_ID_STRING,
ioc->facts.FWVersion.Word);
fc_host_tgtid_bind_type(sh) = FC_TGTID_BIND_BY_WWPN;
fc_host_maxframe_size(sh) = pp0->MaxFrameSize;
fc_host_node_name(sh) =
(u64)pp0->WWNN.High << 32 | (u64)pp0->WWNN.Low;
fc_host_port_name(sh) =
(u64)pp0->WWPN.High << 32 | (u64)pp0->WWPN.Low;
fc_host_port_id(sh) = pp0->PortIdentifier;
class = pp0->SupportedServiceClass;
if (class & MPI_FCPORTPAGE0_SUPPORT_CLASS_1)
cos |= FC_COS_CLASS1;
if (class & MPI_FCPORTPAGE0_SUPPORT_CLASS_2)
cos |= FC_COS_CLASS2;
if (class & MPI_FCPORTPAGE0_SUPPORT_CLASS_3)
cos |= FC_COS_CLASS3;
fc_host_supported_classes(sh) = cos;
if (pp0->CurrentSpeed == MPI_FCPORTPAGE0_CURRENT_SPEED_1GBIT)
speed = FC_PORTSPEED_1GBIT;
else if (pp0->CurrentSpeed == MPI_FCPORTPAGE0_CURRENT_SPEED_2GBIT)
speed = FC_PORTSPEED_2GBIT;
else if (pp0->CurrentSpeed == MPI_FCPORTPAGE0_CURRENT_SPEED_4GBIT)
speed = FC_PORTSPEED_4GBIT;
else if (pp0->CurrentSpeed == MPI_FCPORTPAGE0_CURRENT_SPEED_10GBIT)
speed = FC_PORTSPEED_10GBIT;
else
speed = FC_PORTSPEED_UNKNOWN;
fc_host_speed(sh) = speed;
speed = 0;
if (pp0->SupportedSpeeds & MPI_FCPORTPAGE0_SUPPORT_1GBIT_SPEED)
speed |= FC_PORTSPEED_1GBIT;
if (pp0->SupportedSpeeds & MPI_FCPORTPAGE0_SUPPORT_2GBIT_SPEED)
speed |= FC_PORTSPEED_2GBIT;
if (pp0->SupportedSpeeds & MPI_FCPORTPAGE0_SUPPORT_4GBIT_SPEED)
speed |= FC_PORTSPEED_4GBIT;
if (pp0->SupportedSpeeds & MPI_FCPORTPAGE0_SUPPORT_10GBIT_SPEED)
speed |= FC_PORTSPEED_10GBIT;
fc_host_supported_speeds(sh) = speed;
port_state = FC_PORTSTATE_UNKNOWN;
if (pp0->PortState == MPI_FCPORTPAGE0_PORTSTATE_ONLINE)
port_state = FC_PORTSTATE_ONLINE;
else if (pp0->PortState == MPI_FCPORTPAGE0_PORTSTATE_OFFLINE)
port_state = FC_PORTSTATE_LINKDOWN;
fc_host_port_state(sh) = port_state;
port_type = FC_PORTTYPE_UNKNOWN;
if (pp0->Flags & MPI_FCPORTPAGE0_FLAGS_ATTACH_POINT_TO_POINT)
port_type = FC_PORTTYPE_PTP;
else if (pp0->Flags & MPI_FCPORTPAGE0_FLAGS_ATTACH_PRIVATE_LOOP)
port_type = FC_PORTTYPE_LPORT;
else if (pp0->Flags & MPI_FCPORTPAGE0_FLAGS_ATTACH_PUBLIC_LOOP)
port_type = FC_PORTTYPE_NLPORT;
else if (pp0->Flags & MPI_FCPORTPAGE0_FLAGS_ATTACH_FABRIC_DIRECT)
port_type = FC_PORTTYPE_NPORT;
fc_host_port_type(sh) = port_type;
fc_host_fabric_name(sh) =
(pp0->Flags & MPI_FCPORTPAGE0_FLAGS_FABRIC_WWN_VALID) ?
(u64) pp0->FabricWWNN.High << 32 | (u64) pp0->FabricWWPN.Low :
(u64)pp0->WWNN.High << 32 | (u64)pp0->WWNN.Low;
}
static void
mptfc_link_status_change(struct work_struct *work)
{
MPT_ADAPTER *ioc =
container_of(work, MPT_ADAPTER, fc_rescan_work);
int ii;
for (ii=0; ii < ioc->facts.NumberOfPorts; ii++)
(void) mptfc_GetFcPortPage0(ioc, ii);
}
static void
mptfc_setup_reset(struct work_struct *work)
{
MPT_ADAPTER *ioc =
container_of(work, MPT_ADAPTER, fc_setup_reset_work);
u64 pn;
struct mptfc_rport_info *ri;
struct scsi_target *starget;
VirtTarget *vtarget;
list_for_each_entry(ri, &ioc->fc_rports, list) {
if (ri->flags & MPT_RPORT_INFO_FLAGS_REGISTERED) {
ri->flags &= ~MPT_RPORT_INFO_FLAGS_REGISTERED;
fc_remote_port_delete(ri->rport);
ri->rport = NULL;
starget = ri->starget;
if (starget) {
vtarget = starget->hostdata;
if (vtarget)
vtarget->deleted = 1;
}
pn = (u64)ri->pg0.WWPN.High << 32 |
(u64)ri->pg0.WWPN.Low;
dfcprintk (ioc, printk(MYIOC_s_DEBUG_FMT
"mptfc_setup_reset.%d: %llx deleted\n",
ioc->name,
ioc->sh->host_no,
(unsigned long long)pn));
}
}
}
static void
mptfc_rescan_devices(struct work_struct *work)
{
MPT_ADAPTER *ioc =
container_of(work, MPT_ADAPTER, fc_rescan_work);
int ii;
u64 pn;
struct mptfc_rport_info *ri;
struct scsi_target *starget;
VirtTarget *vtarget;
list_for_each_entry(ri, &ioc->fc_rports, list) {
if (ri->flags & MPT_RPORT_INFO_FLAGS_REGISTERED) {
ri->flags |= MPT_RPORT_INFO_FLAGS_MISSING;
}
}
for (ii=0; ii < ioc->facts.NumberOfPorts; ii++) {
(void) mptfc_GetFcPortPage0(ioc, ii);
mptfc_init_host_attr(ioc, ii);
mptfc_GetFcDevPage0(ioc, ii, mptfc_register_dev);
}
list_for_each_entry(ri, &ioc->fc_rports, list) {
if (ri->flags & MPT_RPORT_INFO_FLAGS_MISSING) {
ri->flags &= ~(MPT_RPORT_INFO_FLAGS_REGISTERED|
MPT_RPORT_INFO_FLAGS_MISSING);
fc_remote_port_delete(ri->rport);
ri->rport = NULL;
starget = ri->starget;
if (starget) {
vtarget = starget->hostdata;
if (vtarget)
vtarget->deleted = 1;
}
pn = (u64)ri->pg0.WWPN.High << 32 |
(u64)ri->pg0.WWPN.Low;
dfcprintk (ioc, printk(MYIOC_s_DEBUG_FMT
"mptfc_rescan.%d: %llx deleted\n",
ioc->name,
ioc->sh->host_no,
(unsigned long long)pn));
}
}
}
static int
mptfc_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
struct Scsi_Host *sh;
MPT_SCSI_HOST *hd;
MPT_ADAPTER *ioc;
unsigned long flags;
int ii;
int numSGE = 0;
int scale;
int ioc_cap;
int error=0;
int r;
if ((r = mpt_attach(pdev,id)) != 0)
return r;
ioc = pci_get_drvdata(pdev);
ioc->DoneCtx = mptfcDoneCtx;
ioc->TaskCtx = mptfcTaskCtx;
ioc->InternalCtx = mptfcInternalCtx;
if (ioc->last_state != MPI_IOC_STATE_OPERATIONAL) {
printk(MYIOC_s_WARN_FMT
"Skipping because it's not operational!\n",
ioc->name);
error = -ENODEV;
goto out_mptfc_probe;
}
if (!ioc->active) {
printk(MYIOC_s_WARN_FMT "Skipping because it's disabled!\n",
ioc->name);
error = -ENODEV;
goto out_mptfc_probe;
}
ioc_cap = 0;
for (ii=0; ii < ioc->facts.NumberOfPorts; ii++) {
if (ioc->pfacts[ii].ProtocolFlags &
MPI_PORTFACTS_PROTOCOL_INITIATOR)
ioc_cap ++;
}
if (!ioc_cap) {
printk(MYIOC_s_WARN_FMT
"Skipping ioc=%p because SCSI Initiator mode is NOT enabled!\n",
ioc->name, ioc);
return 0;
}
sh = scsi_host_alloc(&mptfc_driver_template, sizeof(MPT_SCSI_HOST));
if (!sh) {
printk(MYIOC_s_WARN_FMT
"Unable to register controller with SCSI subsystem\n",
ioc->name);
error = -1;
goto out_mptfc_probe;
}
spin_lock_init(&ioc->fc_rescan_work_lock);
INIT_WORK(&ioc->fc_rescan_work, mptfc_rescan_devices);
INIT_WORK(&ioc->fc_setup_reset_work, mptfc_setup_reset);
INIT_WORK(&ioc->fc_lsc_work, mptfc_link_status_change);
spin_lock_irqsave(&ioc->FreeQlock, flags);
ioc->sh = sh;
sh->io_port = 0;
sh->n_io_port = 0;
sh->irq = 0;
sh->max_cmd_len = 16;
sh->max_id = ioc->pfacts->MaxDevices;
sh->max_lun = max_lun;
sh->unique_id = ioc->id;
scale = ioc->req_sz/ioc->SGE_size;
if (ioc->sg_addr_size == sizeof(u64)) {
numSGE = (scale - 1) *
(ioc->facts.MaxChainDepth-1) + scale +
(ioc->req_sz - 60) / ioc->SGE_size;
} else {
numSGE = 1 + (scale - 1) *
(ioc->facts.MaxChainDepth-1) + scale +
(ioc->req_sz - 64) / ioc->SGE_size;
}
if (numSGE < sh->sg_tablesize) {
dprintk(ioc, printk(MYIOC_s_DEBUG_FMT
"Resetting sg_tablesize to %d from %d\n",
ioc->name, numSGE, sh->sg_tablesize));
sh->sg_tablesize = numSGE;
}
spin_unlock_irqrestore(&ioc->FreeQlock, flags);
hd = shost_priv(sh);
hd->ioc = ioc;
ioc->ScsiLookup = kcalloc(ioc->req_depth, sizeof(void *), GFP_ATOMIC);
if (!ioc->ScsiLookup) {
error = -ENOMEM;
goto out_mptfc_probe;
}
spin_lock_init(&ioc->scsi_lookup_lock);
dprintk(ioc, printk(MYIOC_s_DEBUG_FMT "ScsiLookup @ %p\n",
ioc->name, ioc->ScsiLookup));
hd->last_queue_full = 0;
sh->transportt = mptfc_transport_template;
error = scsi_add_host (sh, &ioc->pcidev->dev);
if(error) {
dprintk(ioc, printk(MYIOC_s_ERR_FMT
"scsi_add_host failed\n", ioc->name));
goto out_mptfc_probe;
}
snprintf(ioc->fc_rescan_work_q_name, sizeof(ioc->fc_rescan_work_q_name),
"mptfc_wq_%d", sh->host_no);
ioc->fc_rescan_work_q =
alloc_ordered_workqueue(ioc->fc_rescan_work_q_name,
WQ_MEM_RECLAIM);
if (!ioc->fc_rescan_work_q) {
error = -ENOMEM;
goto out_mptfc_host;
}
for (ii=0; ii < ioc->facts.NumberOfPorts; ii++) {
(void) mptfc_GetFcPortPage0(ioc, ii);
}
mptfc_SetFcPortPage1_defaults(ioc);
queue_work(ioc->fc_rescan_work_q, &ioc->fc_rescan_work);
flush_workqueue(ioc->fc_rescan_work_q);
return 0;
out_mptfc_host:
scsi_remove_host(sh);
out_mptfc_probe:
mptscsih_remove(pdev);
return error;
}
static int
mptfc_event_process(MPT_ADAPTER *ioc, EventNotificationReply_t *pEvReply)
{
MPT_SCSI_HOST *hd;
u8 event = le32_to_cpu(pEvReply->Event) & 0xFF;
unsigned long flags;
int rc=1;
if (ioc->bus_type != FC)
return 0;
devtverboseprintk(ioc, printk(MYIOC_s_DEBUG_FMT "MPT event (=%02Xh) routed to SCSI host driver!\n",
ioc->name, event));
if (ioc->sh == NULL ||
((hd = shost_priv(ioc->sh)) == NULL))
return 1;
switch (event) {
case MPI_EVENT_RESCAN:
spin_lock_irqsave(&ioc->fc_rescan_work_lock, flags);
if (ioc->fc_rescan_work_q) {
queue_work(ioc->fc_rescan_work_q,
&ioc->fc_rescan_work);
}
spin_unlock_irqrestore(&ioc->fc_rescan_work_lock, flags);
break;
case MPI_EVENT_LINK_STATUS_CHANGE:
spin_lock_irqsave(&ioc->fc_rescan_work_lock, flags);
if (ioc->fc_rescan_work_q) {
queue_work(ioc->fc_rescan_work_q,
&ioc->fc_lsc_work);
}
spin_unlock_irqrestore(&ioc->fc_rescan_work_lock, flags);
break;
default:
rc = mptscsih_event_process(ioc,pEvReply);
break;
}
return rc;
}
static int
mptfc_ioc_reset(MPT_ADAPTER *ioc, int reset_phase)
{
int rc;
unsigned long flags;
rc = mptscsih_ioc_reset(ioc,reset_phase);
if ((ioc->bus_type != FC) || (!rc))
return rc;
dtmprintk(ioc, printk(MYIOC_s_DEBUG_FMT
": IOC %s_reset routed to FC host driver!\n",ioc->name,
reset_phase==MPT_IOC_SETUP_RESET ? "setup" : (
reset_phase==MPT_IOC_PRE_RESET ? "pre" : "post")));
if (reset_phase == MPT_IOC_SETUP_RESET) {
spin_lock_irqsave(&ioc->fc_rescan_work_lock, flags);
if (ioc->fc_rescan_work_q) {
queue_work(ioc->fc_rescan_work_q,
&ioc->fc_setup_reset_work);
}
spin_unlock_irqrestore(&ioc->fc_rescan_work_lock, flags);
}
else if (reset_phase == MPT_IOC_PRE_RESET) {
}
else {
mptfc_SetFcPortPage1_defaults(ioc);
spin_lock_irqsave(&ioc->fc_rescan_work_lock, flags);
if (ioc->fc_rescan_work_q) {
queue_work(ioc->fc_rescan_work_q,
&ioc->fc_rescan_work);
}
spin_unlock_irqrestore(&ioc->fc_rescan_work_lock, flags);
}
return 1;
}
static int __init
mptfc_init(void)
{
int error;
show_mptmod_ver(my_NAME, my_VERSION);
if (mptfc_dev_loss_tmo <= 0)
mptfc_dev_loss_tmo = MPTFC_DEV_LOSS_TMO;
mptfc_transport_template =
fc_attach_transport(&mptfc_transport_functions);
if (!mptfc_transport_template)
return -ENODEV;
mptfcDoneCtx = mpt_register(mptscsih_io_done, MPTFC_DRIVER,
"mptscsih_scandv_complete");
mptfcTaskCtx = mpt_register(mptscsih_taskmgmt_complete, MPTFC_DRIVER,
"mptscsih_scandv_complete");
mptfcInternalCtx = mpt_register(mptscsih_scandv_complete, MPTFC_DRIVER,
"mptscsih_scandv_complete");
mpt_event_register(mptfcDoneCtx, mptfc_event_process);
mpt_reset_register(mptfcDoneCtx, mptfc_ioc_reset);
error = pci_register_driver(&mptfc_driver);
if (error)
fc_release_transport(mptfc_transport_template);
return error;
}
static void mptfc_remove(struct pci_dev *pdev)
{
MPT_ADAPTER *ioc = pci_get_drvdata(pdev);
struct mptfc_rport_info *p, *n;
struct workqueue_struct *work_q;
unsigned long flags;
int ii;
if ((work_q=ioc->fc_rescan_work_q)) {
spin_lock_irqsave(&ioc->fc_rescan_work_lock, flags);
ioc->fc_rescan_work_q = NULL;
spin_unlock_irqrestore(&ioc->fc_rescan_work_lock, flags);
destroy_workqueue(work_q);
}
fc_remove_host(ioc->sh);
list_for_each_entry_safe(p, n, &ioc->fc_rports, list) {
list_del(&p->list);
kfree(p);
}
for (ii=0; ii<ioc->facts.NumberOfPorts; ii++) {
if (ioc->fc_data.fc_port_page1[ii].data) {
pci_free_consistent(ioc->pcidev,
ioc->fc_data.fc_port_page1[ii].pg_sz,
(u8 *) ioc->fc_data.fc_port_page1[ii].data,
ioc->fc_data.fc_port_page1[ii].dma);
ioc->fc_data.fc_port_page1[ii].data = NULL;
}
}
scsi_remove_host(ioc->sh);
mptscsih_remove(pdev);
}
static void __exit
mptfc_exit(void)
{
pci_unregister_driver(&mptfc_driver);
fc_release_transport(mptfc_transport_template);
mpt_reset_deregister(mptfcDoneCtx);
mpt_event_deregister(mptfcDoneCtx);
mpt_deregister(mptfcInternalCtx);
mpt_deregister(mptfcTaskCtx);
mpt_deregister(mptfcDoneCtx);
}
