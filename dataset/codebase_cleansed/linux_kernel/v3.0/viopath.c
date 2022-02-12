static int proc_viopath_show(struct seq_file *m, void *v)
{
char *buf;
u16 vlanMap;
dma_addr_t handle;
HvLpEvent_Rc hvrc;
DECLARE_COMPLETION_ONSTACK(done);
struct device_node *node;
const char *sysid;
buf = kzalloc(HW_PAGE_SIZE, GFP_KERNEL);
if (!buf)
return 0;
handle = iseries_hv_map(buf, HW_PAGE_SIZE, DMA_FROM_DEVICE);
hvrc = HvCallEvent_signalLpEventFast(viopath_hostLp,
HvLpEvent_Type_VirtualIo,
viomajorsubtype_config | vioconfigget,
HvLpEvent_AckInd_DoAck, HvLpEvent_AckType_ImmediateAck,
viopath_sourceinst(viopath_hostLp),
viopath_targetinst(viopath_hostLp),
(u64)(unsigned long)&done, VIOVERSION << 16,
((u64)handle) << 32, HW_PAGE_SIZE, 0, 0);
if (hvrc != HvLpEvent_Rc_Good)
printk(VIOPATH_KERN_WARN "hv error on op %d\n", (int)hvrc);
wait_for_completion(&done);
vlanMap = HvLpConfig_getVirtualLanIndexMap();
buf[HW_PAGE_SIZE-1] = '\0';
seq_printf(m, "%s", buf);
iseries_hv_unmap(handle, HW_PAGE_SIZE, DMA_FROM_DEVICE);
kfree(buf);
seq_printf(m, "AVAILABLE_VETH=%x\n", vlanMap);
node = of_find_node_by_path("/");
sysid = NULL;
if (node != NULL)
sysid = of_get_property(node, "system-id", NULL);
if (sysid == NULL)
seq_printf(m, "SRLNBR=<UNKNOWN>\n");
else
seq_printf(m, "SRLNBR=%s\n", sysid + 4);
of_node_put(node);
return 0;
}
static int proc_viopath_open(struct inode *inode, struct file *file)
{
return single_open(file, proc_viopath_show, NULL);
}
static int __init vio_proc_init(void)
{
if (!firmware_has_feature(FW_FEATURE_ISERIES))
return 0;
proc_create("iSeries/config", 0, NULL, &proc_viopath_operations);
return 0;
}
int viopath_isactive(HvLpIndex lp)
{
if (lp == HvLpIndexInvalid)
return 0;
if (lp < HVMAXARCHITECTEDLPS)
return viopathStatus[lp].isActive;
else
return 0;
}
HvLpInstanceId viopath_sourceinst(HvLpIndex lp)
{
return viopathStatus[lp].mSourceInst;
}
HvLpInstanceId viopath_targetinst(HvLpIndex lp)
{
return viopathStatus[lp].mTargetInst;
}
static void sendMonMsg(HvLpIndex remoteLp)
{
HvLpEvent_Rc hvrc;
viopathStatus[remoteLp].mSourceInst =
HvCallEvent_getSourceLpInstanceId(remoteLp,
HvLpEvent_Type_VirtualIo);
viopathStatus[remoteLp].mTargetInst =
HvCallEvent_getTargetLpInstanceId(remoteLp,
HvLpEvent_Type_VirtualIo);
vio_setHandler(viomajorsubtype_monitor, handleMonitorEvent);
hvrc = HvCallEvent_signalLpEventFast(remoteLp, HvLpEvent_Type_VirtualIo,
viomajorsubtype_monitor, HvLpEvent_AckInd_DoAck,
HvLpEvent_AckType_DeferredAck,
viopathStatus[remoteLp].mSourceInst,
viopathStatus[remoteLp].mTargetInst,
viomonseq++, 0, 0, 0, 0, 0);
if (hvrc == HvLpEvent_Rc_Good)
viopathStatus[remoteLp].isActive = 1;
else {
printk(VIOPATH_KERN_WARN "could not connect to partition %d\n",
remoteLp);
viopathStatus[remoteLp].isActive = 0;
}
}
static void handleMonitorEvent(struct HvLpEvent *event)
{
HvLpIndex remoteLp;
int i;
if (!event)
return;
if (hvlpevent_is_int(event)) {
remoteLp = event->xSourceLp;
if (!viopathStatus[remoteLp].isActive)
sendMonMsg(remoteLp);
return;
}
remoteLp = event->xTargetLp;
if ((event->xSourceInstanceId != viopathStatus[remoteLp].mSourceInst) ||
(event->xTargetInstanceId != viopathStatus[remoteLp].mTargetInst)) {
printk(VIOPATH_KERN_WARN "ignoring ack....mismatched instances\n");
return;
}
printk(VIOPATH_KERN_WARN "partition %d ended\n", remoteLp);
viopathStatus[remoteLp].isActive = 0;
for (i = 0; i < VIO_MAX_SUBTYPES; i++) {
if (vio_handler[i] != NULL)
(*vio_handler[i])(NULL);
}
}
int vio_setHandler(int subtype, vio_event_handler_t *beh)
{
subtype = subtype >> VIOMAJOR_SUBTYPE_SHIFT;
if ((subtype < 0) || (subtype >= VIO_MAX_SUBTYPES))
return -EINVAL;
if (vio_handler[subtype] != NULL)
return -EBUSY;
vio_handler[subtype] = beh;
return 0;
}
int vio_clearHandler(int subtype)
{
subtype = subtype >> VIOMAJOR_SUBTYPE_SHIFT;
if ((subtype < 0) || (subtype >= VIO_MAX_SUBTYPES))
return -EINVAL;
if (vio_handler[subtype] == NULL)
return -EAGAIN;
vio_handler[subtype] = NULL;
return 0;
}
static void handleConfig(struct HvLpEvent *event)
{
if (!event)
return;
if (hvlpevent_is_int(event)) {
printk(VIOPATH_KERN_WARN
"unexpected config request from partition %d",
event->xSourceLp);
if (hvlpevent_need_ack(event)) {
event->xRc = HvLpEvent_Rc_InvalidSubtype;
HvCallEvent_ackLpEvent(event);
}
return;
}
complete((struct completion *)event->xCorrelationToken);
}
void vio_set_hostlp(void)
{
if (viopath_hostLp != HvLpIndexInvalid)
return;
viopath_ourLp = HvLpConfig_getLpIndex();
viopath_hostLp = HvLpConfig_getHostingLpIndex(viopath_ourLp);
if (viopath_hostLp != HvLpIndexInvalid)
vio_setHandler(viomajorsubtype_config, handleConfig);
}
static void vio_handleEvent(struct HvLpEvent *event)
{
HvLpIndex remoteLp;
int subtype = (event->xSubtype & VIOMAJOR_SUBTYPE_MASK)
>> VIOMAJOR_SUBTYPE_SHIFT;
if (hvlpevent_is_int(event)) {
remoteLp = event->xSourceLp;
if (viopathStatus[remoteLp].isActive
&& (event->xSourceInstanceId !=
viopathStatus[remoteLp].mTargetInst)) {
printk(VIOPATH_KERN_WARN
"message from invalid partition. "
"int msg rcvd, source inst (%d) doesn't match (%d)\n",
viopathStatus[remoteLp].mTargetInst,
event->xSourceInstanceId);
return;
}
if (viopathStatus[remoteLp].isActive
&& (event->xTargetInstanceId !=
viopathStatus[remoteLp].mSourceInst)) {
printk(VIOPATH_KERN_WARN
"message from invalid partition. "
"int msg rcvd, target inst (%d) doesn't match (%d)\n",
viopathStatus[remoteLp].mSourceInst,
event->xTargetInstanceId);
return;
}
} else {
remoteLp = event->xTargetLp;
if (event->xSourceInstanceId !=
viopathStatus[remoteLp].mSourceInst) {
printk(VIOPATH_KERN_WARN
"message from invalid partition. "
"ack msg rcvd, source inst (%d) doesn't match (%d)\n",
viopathStatus[remoteLp].mSourceInst,
event->xSourceInstanceId);
return;
}
if (event->xTargetInstanceId !=
viopathStatus[remoteLp].mTargetInst) {
printk(VIOPATH_KERN_WARN
"message from invalid partition. "
"viopath: ack msg rcvd, target inst (%d) doesn't match (%d)\n",
viopathStatus[remoteLp].mTargetInst,
event->xTargetInstanceId);
return;
}
}
if (vio_handler[subtype] == NULL) {
printk(VIOPATH_KERN_WARN
"unexpected virtual io event subtype %d from partition %d\n",
event->xSubtype, remoteLp);
if (hvlpevent_is_int(event) && hvlpevent_need_ack(event)) {
event->xRc = HvLpEvent_Rc_InvalidSubtype;
HvCallEvent_ackLpEvent(event);
}
return;
}
(*vio_handler[subtype])(event);
}
static void viopath_donealloc(void *parm, int number)
{
struct alloc_parms *parmsp = parm;
parmsp->number = number;
if (parmsp->used_wait_atomic)
atomic_set(&parmsp->wait_atomic, 0);
else
complete(&parmsp->done);
}
static int allocateEvents(HvLpIndex remoteLp, int numEvents)
{
struct alloc_parms parms;
if (system_state != SYSTEM_RUNNING) {
parms.used_wait_atomic = 1;
atomic_set(&parms.wait_atomic, 1);
} else {
parms.used_wait_atomic = 0;
init_completion(&parms.done);
}
mf_allocate_lp_events(remoteLp, HvLpEvent_Type_VirtualIo, 250,
numEvents, &viopath_donealloc, &parms);
if (system_state != SYSTEM_RUNNING) {
while (atomic_read(&parms.wait_atomic))
mb();
} else
wait_for_completion(&parms.done);
return parms.number;
}
int viopath_open(HvLpIndex remoteLp, int subtype, int numReq)
{
int i;
unsigned long flags;
int tempNumAllocated;
if ((remoteLp >= HVMAXARCHITECTEDLPS) || (remoteLp == HvLpIndexInvalid))
return -EINVAL;
subtype = subtype >> VIOMAJOR_SUBTYPE_SHIFT;
if ((subtype < 0) || (subtype >= VIO_MAX_SUBTYPES))
return -EINVAL;
spin_lock_irqsave(&statuslock, flags);
if (!event_buffer_initialised) {
for (i = 0; i < VIO_MAX_SUBTYPES; i++)
atomic_set(&event_buffer_available[i], 1);
event_buffer_initialised = 1;
}
viopathStatus[remoteLp].users[subtype]++;
if (!viopathStatus[remoteLp].isOpen) {
viopathStatus[remoteLp].isOpen = 1;
HvCallEvent_openLpEventPath(remoteLp, HvLpEvent_Type_VirtualIo);
spin_unlock_irqrestore(&statuslock, flags);
tempNumAllocated = allocateEvents(remoteLp, 1);
spin_lock_irqsave(&statuslock, flags);
viopathStatus[remoteLp].numberAllocated += tempNumAllocated;
if (viopathStatus[remoteLp].numberAllocated == 0) {
HvCallEvent_closeLpEventPath(remoteLp,
HvLpEvent_Type_VirtualIo);
spin_unlock_irqrestore(&statuslock, flags);
return -ENOMEM;
}
viopathStatus[remoteLp].mSourceInst =
HvCallEvent_getSourceLpInstanceId(remoteLp,
HvLpEvent_Type_VirtualIo);
viopathStatus[remoteLp].mTargetInst =
HvCallEvent_getTargetLpInstanceId(remoteLp,
HvLpEvent_Type_VirtualIo);
HvLpEvent_registerHandler(HvLpEvent_Type_VirtualIo,
&vio_handleEvent);
sendMonMsg(remoteLp);
printk(VIOPATH_KERN_INFO "opening connection to partition %d, "
"setting sinst %d, tinst %d\n",
remoteLp, viopathStatus[remoteLp].mSourceInst,
viopathStatus[remoteLp].mTargetInst);
}
spin_unlock_irqrestore(&statuslock, flags);
tempNumAllocated = allocateEvents(remoteLp, numReq);
spin_lock_irqsave(&statuslock, flags);
viopathStatus[remoteLp].numberAllocated += tempNumAllocated;
spin_unlock_irqrestore(&statuslock, flags);
return 0;
}
int viopath_close(HvLpIndex remoteLp, int subtype, int numReq)
{
unsigned long flags;
int i;
int numOpen;
struct alloc_parms parms;
if ((remoteLp >= HVMAXARCHITECTEDLPS) || (remoteLp == HvLpIndexInvalid))
return -EINVAL;
subtype = subtype >> VIOMAJOR_SUBTYPE_SHIFT;
if ((subtype < 0) || (subtype >= VIO_MAX_SUBTYPES))
return -EINVAL;
spin_lock_irqsave(&statuslock, flags);
if (viopathStatus[remoteLp].users[subtype] > 0)
viopathStatus[remoteLp].users[subtype]--;
spin_unlock_irqrestore(&statuslock, flags);
parms.used_wait_atomic = 0;
init_completion(&parms.done);
mf_deallocate_lp_events(remoteLp, HvLpEvent_Type_VirtualIo,
numReq, &viopath_donealloc, &parms);
wait_for_completion(&parms.done);
spin_lock_irqsave(&statuslock, flags);
for (i = 0, numOpen = 0; i < VIO_MAX_SUBTYPES; i++)
numOpen += viopathStatus[remoteLp].users[i];
if ((viopathStatus[remoteLp].isOpen) && (numOpen == 0)) {
printk(VIOPATH_KERN_INFO "closing connection to partition %d\n",
remoteLp);
HvCallEvent_closeLpEventPath(remoteLp,
HvLpEvent_Type_VirtualIo);
viopathStatus[remoteLp].isOpen = 0;
viopathStatus[remoteLp].isActive = 0;
for (i = 0; i < VIO_MAX_SUBTYPES; i++)
atomic_set(&event_buffer_available[i], 0);
event_buffer_initialised = 0;
}
spin_unlock_irqrestore(&statuslock, flags);
return 0;
}
void *vio_get_event_buffer(int subtype)
{
subtype = subtype >> VIOMAJOR_SUBTYPE_SHIFT;
if ((subtype < 0) || (subtype >= VIO_MAX_SUBTYPES))
return NULL;
if (atomic_dec_if_positive(&event_buffer_available[subtype]) == 0)
return &event_buffer[subtype * 256];
else
return NULL;
}
void vio_free_event_buffer(int subtype, void *buffer)
{
subtype = subtype >> VIOMAJOR_SUBTYPE_SHIFT;
if ((subtype < 0) || (subtype >= VIO_MAX_SUBTYPES)) {
printk(VIOPATH_KERN_WARN
"unexpected subtype %d freeing event buffer\n", subtype);
return;
}
if (atomic_read(&event_buffer_available[subtype]) != 0) {
printk(VIOPATH_KERN_WARN
"freeing unallocated event buffer, subtype %d\n",
subtype);
return;
}
if (buffer != &event_buffer[subtype * 256]) {
printk(VIOPATH_KERN_WARN
"freeing invalid event buffer, subtype %d\n", subtype);
}
atomic_set(&event_buffer_available[subtype], 1);
}
const struct vio_error_entry *vio_lookup_rc(
const struct vio_error_entry *local_table, u16 rc)
{
const struct vio_error_entry *cur;
if (!rc)
return &vio_no_error;
if (local_table)
for (cur = local_table; cur->rc; ++cur)
if (cur->rc == rc)
return cur;
for (cur = vio_default_errors; cur->rc; ++cur)
if (cur->rc == rc)
return cur;
return &vio_unknown_error;
}
