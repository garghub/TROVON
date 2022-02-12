static void __tape_34xx_medium_sense(struct tape_request *request)
{
struct tape_device *device = request->device;
unsigned char *sense;
if (request->rc == 0) {
sense = request->cpdata;
if (sense[0] & SENSE_INTERVENTION_REQUIRED)
tape_med_state_set(device, MS_UNLOADED);
else
tape_med_state_set(device, MS_LOADED);
if (sense[1] & SENSE_WRITE_PROTECT)
device->tape_generic_status |= GMT_WR_PROT(~0);
else
device->tape_generic_status &= ~GMT_WR_PROT(~0);
} else
DBF_EVENT(4, "tape_34xx: medium sense failed with rc=%d\n",
request->rc);
tape_free_request(request);
}
static int tape_34xx_medium_sense(struct tape_device *device)
{
struct tape_request *request;
int rc;
request = tape_alloc_request(1, 32);
if (IS_ERR(request)) {
DBF_EXCEPTION(6, "MSEN fail\n");
return PTR_ERR(request);
}
request->op = TO_MSEN;
tape_ccw_end(request->cpaddr, SENSE, 32, request->cpdata);
rc = tape_do_io_interruptible(device, request);
__tape_34xx_medium_sense(request);
return rc;
}
static void tape_34xx_medium_sense_async(struct tape_device *device)
{
struct tape_request *request;
request = tape_alloc_request(1, 32);
if (IS_ERR(request)) {
DBF_EXCEPTION(6, "MSEN fail\n");
return;
}
request->op = TO_MSEN;
tape_ccw_end(request->cpaddr, SENSE, 32, request->cpdata);
request->callback = (void *) __tape_34xx_medium_sense;
request->callback_data = NULL;
tape_do_io_async(device, request);
}
static void
tape_34xx_work_handler(struct work_struct *work)
{
struct tape_34xx_work *p =
container_of(work, struct tape_34xx_work, work);
struct tape_device *device = p->device;
switch(p->op) {
case TO_MSEN:
tape_34xx_medium_sense_async(device);
break;
default:
DBF_EVENT(3, "T34XX: internal error: unknown work\n");
}
tape_put_device(device);
kfree(p);
}
static int
tape_34xx_schedule_work(struct tape_device *device, enum tape_op op)
{
struct tape_34xx_work *p;
if ((p = kzalloc(sizeof(*p), GFP_ATOMIC)) == NULL)
return -ENOMEM;
INIT_WORK(&p->work, tape_34xx_work_handler);
p->device = tape_get_device(device);
p->op = op;
schedule_work(&p->work);
return 0;
}
static inline int
tape_34xx_done(struct tape_request *request)
{
DBF_EVENT(6, "%s done\n", tape_op_verbose[request->op]);
switch (request->op) {
case TO_DSE:
case TO_RUN:
case TO_WRI:
case TO_WTM:
case TO_ASSIGN:
case TO_UNASSIGN:
tape_34xx_delete_sbid_from(request->device, 0);
break;
default:
;
}
return TAPE_IO_SUCCESS;
}
static inline int
tape_34xx_erp_failed(struct tape_request *request, int rc)
{
DBF_EVENT(3, "Error recovery failed for %s (RC=%d)\n",
tape_op_verbose[request->op], rc);
return rc;
}
static inline int
tape_34xx_erp_succeeded(struct tape_request *request)
{
DBF_EVENT(3, "Error Recovery successful for %s\n",
tape_op_verbose[request->op]);
return tape_34xx_done(request);
}
static inline int
tape_34xx_erp_retry(struct tape_request *request)
{
DBF_EVENT(3, "xerp retr %s\n", tape_op_verbose[request->op]);
return TAPE_IO_RETRY;
}
static int
tape_34xx_unsolicited_irq(struct tape_device *device, struct irb *irb)
{
if (irb->scsw.cmd.dstat == 0x85) {
DBF_EVENT(6, "xuud med\n");
tape_34xx_delete_sbid_from(device, 0);
tape_34xx_schedule_work(device, TO_MSEN);
} else {
DBF_EVENT(3, "unsol.irq! dev end: %08x\n", device->cdev_id);
tape_dump_sense_dbf(device, NULL, irb);
}
return TAPE_IO_SUCCESS;
}
static int
tape_34xx_erp_read_opposite(struct tape_device *device,
struct tape_request *request)
{
if (request->op == TO_RFO) {
tape_std_read_backward(device, request);
return tape_34xx_erp_retry(request);
}
return tape_34xx_erp_failed(request, -EIO);
}
static int
tape_34xx_erp_bug(struct tape_device *device, struct tape_request *request,
struct irb *irb, int no)
{
if (request->op != TO_ASSIGN) {
dev_err(&device->cdev->dev, "An unexpected condition %d "
"occurred in tape error recovery\n", no);
tape_dump_sense_dbf(device, request, irb);
}
return tape_34xx_erp_failed(request, -EIO);
}
static int
tape_34xx_erp_overrun(struct tape_device *device, struct tape_request *request,
struct irb *irb)
{
if (irb->ecw[3] == 0x40) {
dev_warn (&device->cdev->dev, "A data overrun occurred between"
" the control unit and tape unit\n");
return tape_34xx_erp_failed(request, -EIO);
}
return tape_34xx_erp_bug(device, request, irb, -1);
}
static int
tape_34xx_erp_sequence(struct tape_device *device,
struct tape_request *request, struct irb *irb)
{
if (irb->ecw[3] == 0x41) {
dev_warn (&device->cdev->dev, "The block ID sequence on the "
"tape is incorrect\n");
return tape_34xx_erp_failed(request, -EIO);
}
return tape_34xx_erp_bug(device, request, irb, -2);
}
static int
tape_34xx_unit_check(struct tape_device *device, struct tape_request *request,
struct irb *irb)
{
int inhibit_cu_recovery;
__u8* sense;
inhibit_cu_recovery = (*device->modeset_byte & 0x80) ? 1 : 0;
sense = irb->ecw;
if (
sense[0] & SENSE_COMMAND_REJECT &&
sense[1] & SENSE_WRITE_PROTECT
) {
if (
request->op == TO_DSE ||
request->op == TO_WRI ||
request->op == TO_WTM
) {
return tape_34xx_erp_failed(request, -EACCES);
} else {
return tape_34xx_erp_bug(device, request, irb, -3);
}
}
if ((
sense[0] == SENSE_DATA_CHECK ||
sense[0] == SENSE_EQUIPMENT_CHECK ||
sense[0] == SENSE_EQUIPMENT_CHECK + SENSE_DEFERRED_UNIT_CHECK
) && (
sense[1] == SENSE_DRIVE_ONLINE ||
sense[1] == SENSE_BEGINNING_OF_TAPE + SENSE_WRITE_MODE
)) {
switch (request->op) {
case TO_FSF:
case TO_FSB:
return tape_34xx_erp_failed(request, -ENOSPC);
case TO_BSB:
return tape_34xx_erp_retry(request);
case TO_LBL:
tape_34xx_delete_sbid_from(device, 0);
return tape_34xx_erp_failed(request, -EIO);
case TO_RFO:
return tape_34xx_erp_failed(request, 0);
case TO_WRI:
return tape_34xx_erp_failed(request, -ENOSPC);
default:
return tape_34xx_erp_failed(request, 0);
}
}
if (sense[0] & SENSE_BUS_OUT_CHECK)
return tape_34xx_erp_retry(request);
if (sense[0] & SENSE_DATA_CHECK) {
switch (sense[3]) {
case 0x23:
if ((sense[2] & SENSE_TAPE_SYNC_MODE) ||
inhibit_cu_recovery)
return tape_34xx_erp_bug(device, request,
irb, -4);
dev_warn (&device->cdev->dev, "A read error occurred "
"that cannot be recovered\n");
return tape_34xx_erp_failed(request, -EIO);
case 0x25:
if ((sense[2] & SENSE_TAPE_SYNC_MODE) ||
inhibit_cu_recovery)
return tape_34xx_erp_bug(device, request,
irb, -5);
dev_warn (&device->cdev->dev, "A write error on the "
"tape cannot be recovered\n");
return tape_34xx_erp_failed(request, -EIO);
case 0x26:
return tape_34xx_erp_read_opposite(device, request);
case 0x28:
dev_warn (&device->cdev->dev, "Writing the ID-mark "
"failed\n");
return tape_34xx_erp_failed(request, -EIO);
case 0x31:
dev_warn (&device->cdev->dev, "Reading the tape beyond"
" the end of the recorded area failed\n");
return tape_34xx_erp_failed(request, -ENOSPC);
case 0x41:
dev_warn (&device->cdev->dev, "The tape contains an "
"incorrect block ID sequence\n");
return tape_34xx_erp_failed(request, -EIO);
default:
if (device->cdev->id.driver_info == tape_3480)
return tape_34xx_erp_bug(device, request,
irb, -6);
}
}
if (sense[0] & SENSE_OVERRUN)
return tape_34xx_erp_overrun(device, request, irb);
if (sense[1] & SENSE_RECORD_SEQUENCE_ERR)
return tape_34xx_erp_sequence(device, request, irb);
switch (sense[3]) {
case 0x00:
return TAPE_IO_SUCCESS;
case 0x21:
return tape_34xx_erp_retry(request);
case 0x22:
dev_warn (&device->cdev->dev, "A path equipment check occurred"
" for the tape device\n");
return tape_34xx_erp_failed(request, -EIO);
case 0x24:
return tape_34xx_erp_succeeded(request);
case 0x27:
return tape_34xx_erp_retry(request);
case 0x29:
return tape_34xx_erp_failed(request, -EIO);
case 0x2a:
return tape_34xx_erp_retry(request);
case 0x2b:
if (request->op == TO_RUN) {
tape_med_state_set(device, MS_UNLOADED);
return tape_34xx_erp_succeeded(request);
}
return tape_34xx_erp_bug(device, request, irb, sense[3]);
case 0x2c:
return tape_34xx_erp_failed(request, -EIO);
case 0x2d:
if (request->op == TO_DSE)
return tape_34xx_erp_failed(request, -EIO);
return tape_34xx_erp_bug(device, request, irb, sense[3]);
case 0x2e:
dev_warn (&device->cdev->dev, "The tape unit cannot process "
"the tape format\n");
return tape_34xx_erp_failed(request, -EMEDIUMTYPE);
case 0x30:
dev_warn (&device->cdev->dev, "The tape medium is write-"
"protected\n");
return tape_34xx_erp_failed(request, -EACCES);
case 0x32:
dev_warn (&device->cdev->dev, "The tape does not have the "
"required tape tension\n");
return tape_34xx_erp_failed(request, -EIO);
case 0x33:
dev_warn (&device->cdev->dev, "The tape unit failed to load"
" the cartridge\n");
tape_34xx_delete_sbid_from(device, 0);
return tape_34xx_erp_failed(request, -EIO);
case 0x34:
dev_warn (&device->cdev->dev, "Automatic unloading of the tape"
" cartridge failed\n");
if (request->op == TO_RUN)
return tape_34xx_erp_failed(request, -EIO);
return tape_34xx_erp_bug(device, request, irb, sense[3]);
case 0x35:
dev_warn (&device->cdev->dev, "An equipment check has occurred"
" on the tape unit\n");
return tape_34xx_erp_failed(request, -EIO);
case 0x36:
if (device->cdev->id.driver_info == tape_3490)
return tape_34xx_erp_failed(request, -EIO);
return tape_34xx_erp_bug(device, request, irb, sense[3]);
case 0x37:
dev_warn (&device->cdev->dev, "The tape information states an"
" incorrect length\n");
return tape_34xx_erp_failed(request, -EIO);
case 0x38:
if (request->op==TO_WRI ||
request->op==TO_DSE ||
request->op==TO_WTM)
return tape_34xx_erp_failed(request, -ENOSPC);
return tape_34xx_erp_failed(request, -EIO);
case 0x39:
return tape_34xx_erp_failed(request, -EIO);
case 0x3a:
dev_warn (&device->cdev->dev, "The tape unit is not ready\n");
return tape_34xx_erp_failed(request, -EIO);
case 0x3b:
dev_warn (&device->cdev->dev, "The tape medium has been "
"rewound or unloaded manually\n");
tape_34xx_delete_sbid_from(device, 0);
return tape_34xx_erp_failed(request, -EIO);
case 0x42:
dev_warn (&device->cdev->dev, "The tape subsystem is running "
"in degraded mode\n");
return tape_34xx_erp_retry(request);
case 0x43:
tape_34xx_delete_sbid_from(device, 0);
tape_med_state_set(device, MS_UNLOADED);
if (sense[1] & SENSE_DRIVE_ONLINE) {
switch(request->op) {
case TO_ASSIGN:
case TO_UNASSIGN:
case TO_DIS:
case TO_NOP:
return tape_34xx_done(request);
break;
default:
break;
}
}
return tape_34xx_erp_failed(request, -ENOMEDIUM);
case 0x44:
if (request->op != TO_BLOCK && request->op != TO_LBL)
return tape_34xx_erp_bug(device, request,
irb, sense[3]);
return tape_34xx_erp_failed(request, -EIO);
case 0x45:
dev_warn (&device->cdev->dev, "The tape unit is already "
"assigned\n");
return tape_34xx_erp_failed(request, -EIO);
case 0x46:
dev_warn (&device->cdev->dev, "The tape unit is not online\n");
return tape_34xx_erp_failed(request, -EIO);
case 0x47:
dev_warn (&device->cdev->dev, "The control unit has fenced "
"access to the tape volume\n");
tape_34xx_delete_sbid_from(device, 0);
return tape_34xx_erp_failed(request, -EIO);
case 0x48:
return tape_34xx_erp_retry(request);
case 0x49:
dev_warn (&device->cdev->dev, "A parity error occurred on the "
"tape bus\n");
return tape_34xx_erp_failed(request, -EIO);
case 0x4a:
dev_warn (&device->cdev->dev, "I/O error recovery failed on "
"the tape control unit\n");
return tape_34xx_erp_failed(request, -EIO);
case 0x4b:
dev_warn (&device->cdev->dev, "The tape unit requires a "
"firmware update\n");
return tape_34xx_erp_failed(request, -EIO);
case 0x4c:
return tape_34xx_erp_retry(request);
case 0x4d:
if (device->cdev->id.driver_info == tape_3490)
return tape_34xx_erp_retry(request);
return tape_34xx_erp_bug(device, request, irb, sense[3]);
case 0x4e:
if (device->cdev->id.driver_info == tape_3490) {
dev_warn (&device->cdev->dev, "The maximum block size"
" for buffered mode is exceeded\n");
return tape_34xx_erp_failed(request, -ENOBUFS);
}
return tape_34xx_erp_bug(device, request, irb, sense[3]);
case 0x50:
return tape_34xx_erp_retry(request);
case 0x51:
return tape_34xx_erp_retry(request);
case 0x52:
if (request->op == TO_RUN) {
tape_med_state_set(device, MS_UNLOADED);
tape_34xx_delete_sbid_from(device, 0);
return tape_34xx_erp_succeeded(request);
}
return tape_34xx_erp_bug(device, request, irb, sense[3]);
case 0x53:
return tape_34xx_erp_retry(request);
case 0x54:
return tape_34xx_erp_retry(request);
case 0x55:
dev_warn (&device->cdev->dev, "A channel interface error cannot be"
" recovered\n");
return tape_34xx_erp_failed(request, -EIO);
case 0x56:
dev_warn (&device->cdev->dev, "A channel protocol error "
"occurred\n");
return tape_34xx_erp_failed(request, -EIO);
case 0x57:
return tape_34xx_erp_retry(request);
case 0x5a:
dev_warn (&device->cdev->dev, "The tape unit does not support "
"the tape length\n");
return tape_34xx_erp_failed(request, -EIO);
case 0x5b:
if (sense[1] & SENSE_BEGINNING_OF_TAPE)
return tape_34xx_erp_retry(request);
dev_warn (&device->cdev->dev, "The tape unit does not support"
" format 3480 XF\n");
return tape_34xx_erp_failed(request, -EIO);
case 0x5c:
dev_warn (&device->cdev->dev, "The tape unit does not support tape "
"format 3480-2 XF\n");
return tape_34xx_erp_failed(request, -EIO);
case 0x5d:
dev_warn (&device->cdev->dev, "The tape unit does not support"
" the current tape length\n");
return tape_34xx_erp_failed(request, -EMEDIUMTYPE);
case 0x5e:
dev_warn (&device->cdev->dev, "The tape unit does not support"
" the compaction algorithm\n");
return tape_34xx_erp_failed(request, -EMEDIUMTYPE);
case 0x23:
case 0x25:
case 0x26:
case 0x28:
case 0x31:
case 0x40:
case 0x41:
default:
return tape_34xx_erp_bug(device, request, irb, sense[3]);
}
}
static int
tape_34xx_irq(struct tape_device *device, struct tape_request *request,
struct irb *irb)
{
if (request == NULL)
return tape_34xx_unsolicited_irq(device, irb);
if ((irb->scsw.cmd.dstat & DEV_STAT_UNIT_EXCEP) &&
(irb->scsw.cmd.dstat & DEV_STAT_DEV_END) &&
(request->op == TO_WRI)) {
return tape_34xx_erp_failed(request, -ENOSPC);
}
if (irb->scsw.cmd.dstat & DEV_STAT_UNIT_CHECK)
return tape_34xx_unit_check(device, request, irb);
if (irb->scsw.cmd.dstat & DEV_STAT_DEV_END) {
if (irb->scsw.cmd.dstat & DEV_STAT_UNIT_EXCEP) {
if (request->op == TO_BSB || request->op == TO_FSB)
request->rescnt++;
else
DBF_EVENT(5, "Unit Exception!\n");
}
return tape_34xx_done(request);
}
DBF_EVENT(6, "xunknownirq\n");
tape_dump_sense_dbf(device, request, irb);
return TAPE_IO_STOP;
}
static int
tape_34xx_ioctl(struct tape_device *device, unsigned int cmd, unsigned long arg)
{
if (cmd == TAPE390_DISPLAY) {
struct display_struct disp;
if (copy_from_user(&disp, (char __user *) arg, sizeof(disp)) != 0)
return -EFAULT;
return tape_std_display(device, &disp);
} else
return -EINVAL;
}
static inline void
tape_34xx_append_new_sbid(struct tape_34xx_block_id bid, struct list_head *l)
{
struct tape_34xx_sbid * new_sbid;
new_sbid = kmalloc(sizeof(*new_sbid), GFP_ATOMIC);
if (!new_sbid)
return;
new_sbid->bid = bid;
list_add(&new_sbid->list, l);
}
static void
tape_34xx_add_sbid(struct tape_device *device, struct tape_34xx_block_id bid)
{
struct list_head * sbid_list;
struct tape_34xx_sbid * sbid;
struct list_head * l;
sbid_list = (struct list_head *) device->discdata;
if (!sbid_list || (bid.segment < 2 && bid.wrap == 0))
return;
list_for_each(l, sbid_list) {
sbid = list_entry(l, struct tape_34xx_sbid, list);
if (
(sbid->bid.segment == bid.segment) &&
(sbid->bid.wrap == bid.wrap)
) {
if (bid.block < sbid->bid.block)
sbid->bid = bid;
else return;
break;
}
if (bid.block < sbid->bid.block) {
tape_34xx_append_new_sbid(bid, l->prev);
break;
}
}
if (l == sbid_list)
tape_34xx_append_new_sbid(bid, l->prev);
DBF_LH(4, "Current list is:\n");
list_for_each(l, sbid_list) {
sbid = list_entry(l, struct tape_34xx_sbid, list);
DBF_LH(4, "%d:%03d@%05d\n",
sbid->bid.wrap,
sbid->bid.segment,
sbid->bid.block
);
}
}
static void
tape_34xx_delete_sbid_from(struct tape_device *device, int from)
{
struct list_head * sbid_list;
struct tape_34xx_sbid * sbid;
struct list_head * l;
struct list_head * n;
sbid_list = (struct list_head *) device->discdata;
if (!sbid_list)
return;
list_for_each_safe(l, n, sbid_list) {
sbid = list_entry(l, struct tape_34xx_sbid, list);
if (sbid->bid.block >= from) {
DBF_LH(4, "Delete sbid %d:%03d@%05d\n",
sbid->bid.wrap,
sbid->bid.segment,
sbid->bid.block
);
list_del(l);
kfree(sbid);
}
}
}
static void
tape_34xx_merge_sbid(
struct tape_device * device,
struct tape_34xx_block_id * bid
) {
struct tape_34xx_sbid * sbid;
struct tape_34xx_sbid * sbid_to_use;
struct list_head * sbid_list;
struct list_head * l;
sbid_list = (struct list_head *) device->discdata;
bid->wrap = 0;
bid->segment = 1;
if (!sbid_list || list_empty(sbid_list))
return;
sbid_to_use = NULL;
list_for_each(l, sbid_list) {
sbid = list_entry(l, struct tape_34xx_sbid, list);
if (sbid->bid.block >= bid->block)
break;
sbid_to_use = sbid;
}
if (sbid_to_use) {
bid->wrap = sbid_to_use->bid.wrap;
bid->segment = sbid_to_use->bid.segment;
DBF_LH(4, "Use %d:%03d@%05d for %05d\n",
sbid_to_use->bid.wrap,
sbid_to_use->bid.segment,
sbid_to_use->bid.block,
bid->block
);
}
}
static int
tape_34xx_setup_device(struct tape_device * device)
{
int rc;
struct list_head * discdata;
DBF_EVENT(6, "34xx device setup\n");
if ((rc = tape_std_assign(device)) == 0) {
if ((rc = tape_34xx_medium_sense(device)) != 0) {
DBF_LH(3, "34xx medium sense returned %d\n", rc);
}
}
discdata = kmalloc(sizeof(struct list_head), GFP_KERNEL);
if (discdata) {
INIT_LIST_HEAD(discdata);
device->discdata = discdata;
}
return rc;
}
static void
tape_34xx_cleanup_device(struct tape_device *device)
{
tape_std_unassign(device);
if (device->discdata) {
tape_34xx_delete_sbid_from(device, 0);
kfree(device->discdata);
device->discdata = NULL;
}
}
static int
tape_34xx_mttell(struct tape_device *device, int mt_count)
{
struct {
struct tape_34xx_block_id cbid;
struct tape_34xx_block_id dbid;
} __attribute__ ((packed)) block_id;
int rc;
rc = tape_std_read_block_id(device, (__u64 *) &block_id);
if (rc)
return rc;
tape_34xx_add_sbid(device, block_id.cbid);
return block_id.cbid.block;
}
static int
tape_34xx_mtseek(struct tape_device *device, int mt_count)
{
struct tape_request *request;
struct tape_34xx_block_id * bid;
if (mt_count > 0x3fffff) {
DBF_EXCEPTION(6, "xsee parm\n");
return -EINVAL;
}
request = tape_alloc_request(3, 4);
if (IS_ERR(request))
return PTR_ERR(request);
request->op = TO_LBL;
bid = (struct tape_34xx_block_id *) request->cpdata;
bid->format = (*device->modeset_byte & 0x08) ?
TAPE34XX_FMT_3480_XF : TAPE34XX_FMT_3480;
bid->block = mt_count;
tape_34xx_merge_sbid(device, bid);
tape_ccw_cc(request->cpaddr, MODE_SET_DB, 1, device->modeset_byte);
tape_ccw_cc(request->cpaddr + 1, LOCATE, 4, request->cpdata);
tape_ccw_end(request->cpaddr + 2, NOP, 0, NULL);
return tape_do_io_free(device, request);
}
static int
tape_34xx_online(struct ccw_device *cdev)
{
return tape_generic_online(
dev_get_drvdata(&cdev->dev),
&tape_discipline_34xx
);
}
static int
tape_34xx_init (void)
{
int rc;
TAPE_DBF_AREA = debug_register ( "tape_34xx", 2, 2, 4*sizeof(long));
debug_register_view(TAPE_DBF_AREA, &debug_sprintf_view);
#ifdef DBF_LIKE_HELL
debug_set_level(TAPE_DBF_AREA, 6);
#endif
DBF_EVENT(3, "34xx init\n");
rc = ccw_driver_register(&tape_34xx_driver);
if (rc)
DBF_EVENT(3, "34xx init failed\n");
else
DBF_EVENT(3, "34xx registered\n");
return rc;
}
static void
tape_34xx_exit(void)
{
ccw_driver_unregister(&tape_34xx_driver);
debug_unregister(TAPE_DBF_AREA);
}
