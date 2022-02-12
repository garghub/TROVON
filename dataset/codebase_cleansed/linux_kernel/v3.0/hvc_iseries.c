static void hvlog(char *fmt, ...)
{
int i;
unsigned long flags;
va_list args;
static char buf[256];
spin_lock_irqsave(&consoleloglock, flags);
va_start(args, fmt);
i = vscnprintf(buf, sizeof(buf) - 1, fmt, args);
va_end(args);
buf[i++] = '\r';
HvCall_writeLogBuffer(buf, i);
spin_unlock_irqrestore(&consoleloglock, flags);
}
static void init_data_event(struct viocharlpevent *viochar, HvLpIndex lp)
{
struct HvLpEvent *hev = &viochar->event;
memset(viochar, 0, sizeof(struct viocharlpevent));
hev->flags = HV_LP_EVENT_VALID | HV_LP_EVENT_DEFERRED_ACK |
HV_LP_EVENT_INT;
hev->xType = HvLpEvent_Type_VirtualIo;
hev->xSubtype = viomajorsubtype_chario | viochardata;
hev->xSourceLp = HvLpConfig_getLpIndex();
hev->xTargetLp = lp;
hev->xSizeMinus1 = sizeof(struct viocharlpevent);
hev->xSourceInstanceId = viopath_sourceinst(lp);
hev->xTargetInstanceId = viopath_targetinst(lp);
}
static int get_chars(uint32_t vtermno, char *buf, int count)
{
struct port_info *pi;
int n = 0;
unsigned long flags;
if (vtermno >= VTTY_PORTS)
return -EINVAL;
if (count == 0)
return 0;
pi = &port_info[vtermno];
spin_lock_irqsave(&consolelock, flags);
if (pi->in_end == 0)
goto done;
n = pi->in_end - pi->in_start;
if (n > count)
n = count;
memcpy(buf, &pi->in_buf[pi->in_start], n);
pi->in_start += n;
if (pi->in_start == pi->in_end) {
pi->in_start = 0;
pi->in_end = 0;
}
done:
spin_unlock_irqrestore(&consolelock, flags);
return n;
}
static int put_chars(uint32_t vtermno, const char *buf, int count)
{
struct viocharlpevent *viochar;
struct port_info *pi;
HvLpEvent_Rc hvrc;
unsigned long flags;
int sent = 0;
if (vtermno >= VTTY_PORTS)
return -EINVAL;
pi = &port_info[vtermno];
spin_lock_irqsave(&consolelock, flags);
if (viochar_is_console(pi) && !viopath_isactive(pi->lp)) {
HvCall_writeLogBuffer(buf, count);
sent = count;
goto done;
}
viochar = vio_get_event_buffer(viomajorsubtype_chario);
if (viochar == NULL) {
hvlog("\n\rviocons: Can't get viochar buffer.");
goto done;
}
while ((count > 0) && ((pi->seq - pi->ack) < VIOCHAR_WINDOW)) {
int len;
len = (count > VIOCHAR_MAX_DATA) ? VIOCHAR_MAX_DATA : count;
if (viochar_is_console(pi))
HvCall_writeLogBuffer(buf, len);
init_data_event(viochar, pi->lp);
viochar->len = len;
viochar->event.xCorrelationToken = pi->seq++;
viochar->event.xSizeMinus1 =
offsetof(struct viocharlpevent, data) + len;
memcpy(viochar->data, buf, len);
hvrc = HvCallEvent_signalLpEvent(&viochar->event);
if (hvrc)
hvlog("\n\rerror sending event! return code %d\n\r",
(int)hvrc);
sent += len;
count -= len;
buf += len;
}
vio_free_event_buffer(viomajorsubtype_chario, viochar);
done:
spin_unlock_irqrestore(&consolelock, flags);
return sent;
}
static int __devinit hvc_vio_probe(struct vio_dev *vdev,
const struct vio_device_id *id)
{
struct hvc_struct *hp;
struct port_info *pi;
if (!vdev || !id)
return -EPERM;
if (vdev->unit_address >= VTTY_PORTS)
return -ENODEV;
pi = &port_info[vdev->unit_address];
hp = hvc_alloc(vdev->unit_address, vdev->irq, &hvc_get_put_ops,
VIOCHAR_MAX_DATA);
if (IS_ERR(hp))
return PTR_ERR(hp);
pi->hp = hp;
dev_set_drvdata(&vdev->dev, pi);
return 0;
}
static int __devexit hvc_vio_remove(struct vio_dev *vdev)
{
struct port_info *pi = dev_get_drvdata(&vdev->dev);
struct hvc_struct *hp = pi->hp;
return hvc_remove(hp);
}
static void hvc_open_event(struct HvLpEvent *event)
{
unsigned long flags;
struct viocharlpevent *cevent = (struct viocharlpevent *)event;
u8 port = cevent->virtual_device;
struct port_info *pi;
int reject = 0;
if (hvlpevent_is_ack(event)) {
if (port >= VTTY_PORTS)
return;
spin_lock_irqsave(&consolelock, flags);
pi = &port_info[port];
if (event->xRc == HvLpEvent_Rc_Good) {
pi->seq = pi->ack = 0;
pi->lp = event->xTargetLp;
}
spin_unlock_irqrestore(&consolelock, flags);
if (event->xRc != HvLpEvent_Rc_Good)
printk(KERN_WARNING
"hvc: handle_open_event: event->xRc == (%d).\n",
event->xRc);
if (event->xCorrelationToken != 0) {
atomic_t *aptr= (atomic_t *)event->xCorrelationToken;
atomic_set(aptr, 1);
} else
printk(KERN_WARNING
"hvc: weird...got open ack without atomic\n");
return;
}
if (!hvlpevent_need_ack(event)) {
printk(KERN_WARNING "hvc: viocharopen without ack bit!\n");
return;
}
spin_lock_irqsave(&consolelock, flags);
if (port >= VTTY_PORTS) {
event->xRc = HvLpEvent_Rc_SubtypeError;
cevent->subtype_result_code = viorc_openRejected;
reject = 1;
} else {
pi = &port_info[port];
if ((pi->lp != HvLpIndexInvalid) &&
(pi->lp != event->xSourceLp)) {
event->xRc = HvLpEvent_Rc_SubtypeError;
cevent->subtype_result_code = viorc_openRejected;
reject = 2;
} else {
pi->lp = event->xSourceLp;
event->xRc = HvLpEvent_Rc_Good;
cevent->subtype_result_code = viorc_good;
pi->seq = pi->ack = 0;
}
}
spin_unlock_irqrestore(&consolelock, flags);
if (reject == 1)
printk(KERN_WARNING "hvc: open rejected: bad virtual tty.\n");
else if (reject == 2)
printk(KERN_WARNING "hvc: open rejected: console in exclusive "
"use by another partition.\n");
HvCallEvent_ackLpEvent(event);
}
static void hvc_close_event(struct HvLpEvent *event)
{
unsigned long flags;
struct viocharlpevent *cevent = (struct viocharlpevent *)event;
u8 port = cevent->virtual_device;
if (!hvlpevent_is_int(event)) {
printk(KERN_WARNING
"hvc: got unexpected close acknowledgement\n");
return;
}
if (port >= VTTY_PORTS) {
printk(KERN_WARNING
"hvc: close message from invalid virtual device.\n");
return;
}
spin_lock_irqsave(&consolelock, flags);
if (port_info[port].lp == event->xSourceLp)
port_info[port].lp = HvLpIndexInvalid;
spin_unlock_irqrestore(&consolelock, flags);
}
static void hvc_data_event(struct HvLpEvent *event)
{
unsigned long flags;
struct viocharlpevent *cevent = (struct viocharlpevent *)event;
struct port_info *pi;
int n;
u8 port = cevent->virtual_device;
if (port >= VTTY_PORTS) {
printk(KERN_WARNING "hvc: data on invalid virtual device %d\n",
port);
return;
}
if (cevent->len == 0)
return;
pi = &port_info[port];
if (pi->lp != event->xSourceLp)
return;
spin_lock_irqsave(&consolelock, flags);
n = IN_BUF_SIZE - pi->in_end;
if (n > cevent->len)
n = cevent->len;
if (n > 0) {
memcpy(&pi->in_buf[pi->in_end], cevent->data, n);
pi->in_end += n;
}
spin_unlock_irqrestore(&consolelock, flags);
if (n == 0)
printk(KERN_WARNING "hvc: input buffer overflow\n");
}
static void hvc_ack_event(struct HvLpEvent *event)
{
struct viocharlpevent *cevent = (struct viocharlpevent *)event;
unsigned long flags;
u8 port = cevent->virtual_device;
if (port >= VTTY_PORTS) {
printk(KERN_WARNING "hvc: data on invalid virtual device\n");
return;
}
spin_lock_irqsave(&consolelock, flags);
port_info[port].ack = event->xCorrelationToken;
spin_unlock_irqrestore(&consolelock, flags);
}
static void hvc_config_event(struct HvLpEvent *event)
{
struct viocharlpevent *cevent = (struct viocharlpevent *)event;
if (cevent->data[0] == 0x01)
printk(KERN_INFO "hvc: window resized to %d: %d: %d: %d\n",
cevent->data[1], cevent->data[2],
cevent->data[3], cevent->data[4]);
else
printk(KERN_WARNING "hvc: unknown config event\n");
}
static void hvc_handle_event(struct HvLpEvent *event)
{
int charminor;
if (event == NULL)
return;
charminor = event->xSubtype & VIOMINOR_SUBTYPE_MASK;
switch (charminor) {
case viocharopen:
hvc_open_event(event);
break;
case viocharclose:
hvc_close_event(event);
break;
case viochardata:
hvc_data_event(event);
break;
case viocharack:
hvc_ack_event(event);
break;
case viocharconfig:
hvc_config_event(event);
break;
default:
if (hvlpevent_is_int(event) && hvlpevent_need_ack(event)) {
event->xRc = HvLpEvent_Rc_InvalidSubtype;
HvCallEvent_ackLpEvent(event);
}
}
}
static int __init send_open(HvLpIndex remoteLp, void *sem)
{
return HvCallEvent_signalLpEventFast(remoteLp,
HvLpEvent_Type_VirtualIo,
viomajorsubtype_chario | viocharopen,
HvLpEvent_AckInd_DoAck, HvLpEvent_AckType_ImmediateAck,
viopath_sourceinst(remoteLp),
viopath_targetinst(remoteLp),
(u64)(unsigned long)sem, VIOVERSION << 16,
0, 0, 0, 0);
}
static int __init hvc_vio_init(void)
{
atomic_t wait_flag;
int rc;
if (!firmware_has_feature(FW_FEATURE_ISERIES))
return -EIO;
rc = viopath_open(HvLpConfig_getPrimaryLpIndex(),
viomajorsubtype_chario, VIOCHAR_WINDOW + 2);
if (rc)
printk(KERN_WARNING "hvc: error opening to primary %d\n", rc);
if (viopath_hostLp == HvLpIndexInvalid)
vio_set_hostlp();
if ((viopath_hostLp != HvLpIndexInvalid) &&
(viopath_hostLp != HvLpConfig_getPrimaryLpIndex())) {
printk(KERN_INFO "hvc: open path to hosting (%d)\n",
viopath_hostLp);
rc = viopath_open(viopath_hostLp, viomajorsubtype_chario,
VIOCHAR_WINDOW + 2);
if (rc)
printk(KERN_WARNING
"error opening to partition %d: %d\n",
viopath_hostLp, rc);
}
if (vio_setHandler(viomajorsubtype_chario, hvc_handle_event) < 0)
printk(KERN_WARNING
"hvc: error seting handler for console events!\n");
atomic_set(&wait_flag, 0);
if ((viopath_isactive(viopath_hostLp)) &&
(send_open(viopath_hostLp, &wait_flag) == 0)) {
printk(KERN_INFO "hvc: hosting partition %d\n", viopath_hostLp);
while (atomic_read(&wait_flag) == 0)
mb();
atomic_set(&wait_flag, 0);
}
if ((!viopath_isactive(port_info[0].lp)) &&
(viopath_isactive(HvLpConfig_getPrimaryLpIndex())) &&
(send_open(HvLpConfig_getPrimaryLpIndex(), &wait_flag) == 0)) {
printk(KERN_INFO "hvc: opening console to primary partition\n");
while (atomic_read(&wait_flag) == 0)
mb();
}
rc = vio_register_driver(&hvc_vio_driver);
return rc;
}
static void __exit hvc_vio_exit(void)
{
vio_unregister_driver(&hvc_vio_driver);
}
static int __init hvc_find_vtys(void)
{
struct device_node *vty;
int num_found = 0;
for (vty = of_find_node_by_name(NULL, "vty"); vty != NULL;
vty = of_find_node_by_name(vty, "vty")) {
const uint32_t *vtermno;
if ((num_found >= MAX_NR_HVC_CONSOLES) ||
(num_found >= VTTY_PORTS)) {
of_node_put(vty);
break;
}
vtermno = of_get_property(vty, "reg", NULL);
if (!vtermno)
continue;
if (!of_device_is_compatible(vty, "IBM,iSeries-vty"))
continue;
if (num_found == 0)
add_preferred_console("hvc", 0, NULL);
hvc_instantiate(*vtermno, num_found, &hvc_get_put_ops);
++num_found;
}
return num_found;
}
