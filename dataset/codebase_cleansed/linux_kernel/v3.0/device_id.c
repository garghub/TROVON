static int diag210_to_senseid(struct senseid *senseid, struct diag210 *diag)
{
static struct {
int class, type, cu_type;
} vm_devices[] = {
{ 0x08, 0x01, 0x3480 },
{ 0x08, 0x02, 0x3430 },
{ 0x08, 0x10, 0x3420 },
{ 0x08, 0x42, 0x3424 },
{ 0x08, 0x44, 0x9348 },
{ 0x08, 0x81, 0x3490 },
{ 0x08, 0x82, 0x3422 },
{ 0x10, 0x41, 0x1403 },
{ 0x10, 0x42, 0x3211 },
{ 0x10, 0x43, 0x3203 },
{ 0x10, 0x45, 0x3800 },
{ 0x10, 0x47, 0x3262 },
{ 0x10, 0x48, 0x3820 },
{ 0x10, 0x49, 0x3800 },
{ 0x10, 0x4a, 0x4245 },
{ 0x10, 0x4b, 0x4248 },
{ 0x10, 0x4d, 0x3800 },
{ 0x10, 0x4e, 0x3820 },
{ 0x10, 0x4f, 0x3820 },
{ 0x10, 0x82, 0x2540 },
{ 0x10, 0x84, 0x3525 },
{ 0x20, 0x81, 0x2501 },
{ 0x20, 0x82, 0x2540 },
{ 0x20, 0x84, 0x3505 },
{ 0x40, 0x01, 0x3278 },
{ 0x40, 0x04, 0x3277 },
{ 0x40, 0x80, 0x2250 },
{ 0x40, 0xc0, 0x5080 },
{ 0x80, 0x00, 0x3215 },
};
int i;
if (diag->vrdcvcla == 0x02 && diag->vrdcvtyp == 0x20) {
senseid->cu_type = 0x3088;
senseid->cu_model = 0x60;
senseid->reserved = 0xff;
return 0;
}
for (i = 0; i < ARRAY_SIZE(vm_devices); i++) {
if (diag->vrdcvcla == vm_devices[i].class &&
diag->vrdcvtyp == vm_devices[i].type) {
senseid->cu_type = vm_devices[i].cu_type;
senseid->reserved = 0xff;
return 0;
}
}
return -ENODEV;
}
static int diag210_get_dev_info(struct ccw_device *cdev)
{
struct ccw_dev_id *dev_id = &cdev->private->dev_id;
struct senseid *senseid = &cdev->private->senseid;
struct diag210 diag_data;
int rc;
if (dev_id->ssid != 0)
return -ENODEV;
memset(&diag_data, 0, sizeof(diag_data));
diag_data.vrdcdvno = dev_id->devno;
diag_data.vrdclen = sizeof(diag_data);
rc = diag210(&diag_data);
CIO_TRACE_EVENT(4, "diag210");
CIO_HEX_EVENT(4, &rc, sizeof(rc));
CIO_HEX_EVENT(4, &diag_data, sizeof(diag_data));
if (rc != 0 && rc != 2)
goto err_failed;
if (diag210_to_senseid(senseid, &diag_data))
goto err_unknown;
return 0;
err_unknown:
CIO_MSG_EVENT(0, "snsid: device 0.%x.%04x: unknown diag210 data\n",
dev_id->ssid, dev_id->devno);
return -ENODEV;
err_failed:
CIO_MSG_EVENT(0, "snsid: device 0.%x.%04x: diag210 failed (rc=%d)\n",
dev_id->ssid, dev_id->devno, rc);
return -ENODEV;
}
static void snsid_init(struct ccw_device *cdev)
{
cdev->private->flags.esid = 0;
memset(&cdev->private->senseid, 0, sizeof(cdev->private->senseid));
cdev->private->senseid.cu_type = 0xffff;
}
static int snsid_check(struct ccw_device *cdev, void *data)
{
struct cmd_scsw *scsw = &cdev->private->irb.scsw.cmd;
int len = sizeof(struct senseid) - scsw->count;
if (len < SENSE_ID_MIN_LEN)
goto out_restart;
if (cdev->private->senseid.cu_type == 0xffff)
goto out_restart;
if (cdev->private->senseid.reserved != 0xff)
return -EOPNOTSUPP;
if (len > SENSE_ID_BASIC_LEN)
cdev->private->flags.esid = 1;
return 0;
out_restart:
snsid_init(cdev);
return -EAGAIN;
}
static void snsid_callback(struct ccw_device *cdev, void *data, int rc)
{
struct ccw_dev_id *id = &cdev->private->dev_id;
struct senseid *senseid = &cdev->private->senseid;
int vm = 0;
if (rc && MACHINE_IS_VM) {
snsid_init(cdev);
if (diag210_get_dev_info(cdev) == 0) {
rc = 0;
vm = 1;
}
}
CIO_MSG_EVENT(2, "snsid: device 0.%x.%04x: rc=%d %04x/%02x "
"%04x/%02x%s\n", id->ssid, id->devno, rc,
senseid->cu_type, senseid->cu_model, senseid->dev_type,
senseid->dev_model, vm ? " (diag210)" : "");
ccw_device_sense_id_done(cdev, rc);
}
void ccw_device_sense_id_start(struct ccw_device *cdev)
{
struct subchannel *sch = to_subchannel(cdev->dev.parent);
struct ccw_request *req = &cdev->private->req;
struct ccw1 *cp = cdev->private->iccws;
CIO_TRACE_EVENT(4, "snsid");
CIO_HEX_EVENT(4, &cdev->private->dev_id, sizeof(cdev->private->dev_id));
snsid_init(cdev);
cp->cmd_code = CCW_CMD_SENSE_ID;
cp->cda = (u32) (addr_t) &cdev->private->senseid;
cp->count = sizeof(struct senseid);
cp->flags = CCW_FLAG_SLI;
memset(req, 0, sizeof(*req));
req->cp = cp;
req->timeout = SENSE_ID_TIMEOUT;
req->maxretries = SENSE_ID_RETRIES;
req->lpm = sch->schib.pmcw.pam & sch->opm;
req->check = snsid_check;
req->callback = snsid_callback;
ccw_request_start(cdev);
}
