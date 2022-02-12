static ssize_t
get_a_bus_req(struct device *dev, struct device_attribute *attr, char *buf)
{
char *next;
unsigned size, t;
struct ci_hdrc *ci = dev_get_drvdata(dev);
next = buf;
size = PAGE_SIZE;
t = scnprintf(next, size, "%d\n", ci->fsm.a_bus_req);
size -= t;
next += t;
return PAGE_SIZE - size;
}
static ssize_t
set_a_bus_req(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct ci_hdrc *ci = dev_get_drvdata(dev);
if (count > 2)
return -1;
mutex_lock(&ci->fsm.lock);
if (buf[0] == '0') {
ci->fsm.a_bus_req = 0;
} else if (buf[0] == '1') {
if (ci->fsm.a_bus_drop) {
mutex_unlock(&ci->fsm.lock);
return count;
}
ci->fsm.a_bus_req = 1;
}
ci_otg_queue_work(ci);
mutex_unlock(&ci->fsm.lock);
return count;
}
static ssize_t
get_a_bus_drop(struct device *dev, struct device_attribute *attr, char *buf)
{
char *next;
unsigned size, t;
struct ci_hdrc *ci = dev_get_drvdata(dev);
next = buf;
size = PAGE_SIZE;
t = scnprintf(next, size, "%d\n", ci->fsm.a_bus_drop);
size -= t;
next += t;
return PAGE_SIZE - size;
}
static ssize_t
set_a_bus_drop(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct ci_hdrc *ci = dev_get_drvdata(dev);
if (count > 2)
return -1;
mutex_lock(&ci->fsm.lock);
if (buf[0] == '0') {
ci->fsm.a_bus_drop = 0;
} else if (buf[0] == '1') {
ci->fsm.a_bus_drop = 1;
ci->fsm.a_bus_req = 0;
}
ci_otg_queue_work(ci);
mutex_unlock(&ci->fsm.lock);
return count;
}
static ssize_t
get_b_bus_req(struct device *dev, struct device_attribute *attr, char *buf)
{
char *next;
unsigned size, t;
struct ci_hdrc *ci = dev_get_drvdata(dev);
next = buf;
size = PAGE_SIZE;
t = scnprintf(next, size, "%d\n", ci->fsm.b_bus_req);
size -= t;
next += t;
return PAGE_SIZE - size;
}
static ssize_t
set_b_bus_req(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct ci_hdrc *ci = dev_get_drvdata(dev);
if (count > 2)
return -1;
mutex_lock(&ci->fsm.lock);
if (buf[0] == '0')
ci->fsm.b_bus_req = 0;
else if (buf[0] == '1')
ci->fsm.b_bus_req = 1;
ci_otg_queue_work(ci);
mutex_unlock(&ci->fsm.lock);
return count;
}
static ssize_t
set_a_clr_err(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct ci_hdrc *ci = dev_get_drvdata(dev);
if (count > 2)
return -1;
mutex_lock(&ci->fsm.lock);
if (buf[0] == '1')
ci->fsm.a_clr_err = 1;
ci_otg_queue_work(ci);
mutex_unlock(&ci->fsm.lock);
return count;
}
static void ci_otg_add_timer(struct ci_hdrc *ci, enum otg_fsm_timer t)
{
unsigned long flags, timer_sec, timer_nsec;
if (t >= NUM_OTG_FSM_TIMERS)
return;
spin_lock_irqsave(&ci->lock, flags);
timer_sec = otg_timer_ms[t] / MSEC_PER_SEC;
timer_nsec = (otg_timer_ms[t] % MSEC_PER_SEC) * NSEC_PER_MSEC;
ci->hr_timeouts[t] = ktime_add(ktime_get(),
ktime_set(timer_sec, timer_nsec));
ci->enabled_otg_timer_bits |= (1 << t);
if ((ci->next_otg_timer == NUM_OTG_FSM_TIMERS) ||
(ci->hr_timeouts[ci->next_otg_timer].tv64 >
ci->hr_timeouts[t].tv64)) {
ci->next_otg_timer = t;
hrtimer_start_range_ns(&ci->otg_fsm_hrtimer,
ci->hr_timeouts[t], NSEC_PER_MSEC,
HRTIMER_MODE_ABS);
}
spin_unlock_irqrestore(&ci->lock, flags);
}
static void ci_otg_del_timer(struct ci_hdrc *ci, enum otg_fsm_timer t)
{
unsigned long flags, enabled_timer_bits;
enum otg_fsm_timer cur_timer, next_timer = NUM_OTG_FSM_TIMERS;
if ((t >= NUM_OTG_FSM_TIMERS) ||
!(ci->enabled_otg_timer_bits & (1 << t)))
return;
spin_lock_irqsave(&ci->lock, flags);
ci->enabled_otg_timer_bits &= ~(1 << t);
if (ci->next_otg_timer == t) {
if (ci->enabled_otg_timer_bits == 0) {
hrtimer_cancel(&ci->otg_fsm_hrtimer);
ci->next_otg_timer = NUM_OTG_FSM_TIMERS;
} else {
enabled_timer_bits = ci->enabled_otg_timer_bits;
for_each_set_bit(cur_timer, &enabled_timer_bits,
NUM_OTG_FSM_TIMERS) {
if ((next_timer == NUM_OTG_FSM_TIMERS) ||
(ci->hr_timeouts[next_timer].tv64 <
ci->hr_timeouts[cur_timer].tv64))
next_timer = cur_timer;
}
}
}
if (next_timer != NUM_OTG_FSM_TIMERS) {
ci->next_otg_timer = next_timer;
hrtimer_start_range_ns(&ci->otg_fsm_hrtimer,
ci->hr_timeouts[next_timer], NSEC_PER_MSEC,
HRTIMER_MODE_ABS);
}
spin_unlock_irqrestore(&ci->lock, flags);
}
static int a_wait_vrise_tmout(struct ci_hdrc *ci)
{
ci->fsm.a_wait_vrise_tmout = 1;
return 0;
}
static int a_wait_vfall_tmout(struct ci_hdrc *ci)
{
ci->fsm.a_wait_vfall_tmout = 1;
return 0;
}
static int a_wait_bcon_tmout(struct ci_hdrc *ci)
{
ci->fsm.a_wait_bcon_tmout = 1;
return 0;
}
static int a_aidl_bdis_tmout(struct ci_hdrc *ci)
{
ci->fsm.a_aidl_bdis_tmout = 1;
return 0;
}
static int b_ase0_brst_tmout(struct ci_hdrc *ci)
{
ci->fsm.b_ase0_brst_tmout = 1;
return 0;
}
static int a_bidl_adis_tmout(struct ci_hdrc *ci)
{
ci->fsm.a_bidl_adis_tmout = 1;
return 0;
}
static int b_se0_srp_tmout(struct ci_hdrc *ci)
{
ci->fsm.b_se0_srp = 1;
return 0;
}
static int b_srp_fail_tmout(struct ci_hdrc *ci)
{
ci->fsm.b_srp_done = 1;
return 1;
}
static int b_data_pls_tmout(struct ci_hdrc *ci)
{
ci->fsm.b_srp_done = 1;
ci->fsm.b_bus_req = 0;
if (ci->fsm.power_up)
ci->fsm.power_up = 0;
hw_write_otgsc(ci, OTGSC_HABA, 0);
pm_runtime_put(ci->dev);
return 0;
}
static int b_ssend_srp_tmout(struct ci_hdrc *ci)
{
ci->fsm.b_ssend_srp = 1;
if (ci->fsm.otg->state == OTG_STATE_B_IDLE)
return 0;
else
return 1;
}
static enum hrtimer_restart ci_otg_hrtimer_func(struct hrtimer *t)
{
struct ci_hdrc *ci = container_of(t, struct ci_hdrc, otg_fsm_hrtimer);
ktime_t now, *timeout;
unsigned long enabled_timer_bits;
unsigned long flags;
enum otg_fsm_timer cur_timer, next_timer = NUM_OTG_FSM_TIMERS;
int ret = -EINVAL;
spin_lock_irqsave(&ci->lock, flags);
enabled_timer_bits = ci->enabled_otg_timer_bits;
ci->next_otg_timer = NUM_OTG_FSM_TIMERS;
now = ktime_get();
for_each_set_bit(cur_timer, &enabled_timer_bits, NUM_OTG_FSM_TIMERS) {
if (now.tv64 >= ci->hr_timeouts[cur_timer].tv64) {
ci->enabled_otg_timer_bits &= ~(1 << cur_timer);
if (otg_timer_handlers[cur_timer])
ret = otg_timer_handlers[cur_timer](ci);
} else {
if ((next_timer == NUM_OTG_FSM_TIMERS) ||
(ci->hr_timeouts[cur_timer].tv64 <
ci->hr_timeouts[next_timer].tv64))
next_timer = cur_timer;
}
}
if (next_timer < NUM_OTG_FSM_TIMERS) {
timeout = &ci->hr_timeouts[next_timer];
hrtimer_start_range_ns(&ci->otg_fsm_hrtimer, *timeout,
NSEC_PER_MSEC, HRTIMER_MODE_ABS);
ci->next_otg_timer = next_timer;
}
spin_unlock_irqrestore(&ci->lock, flags);
if (!ret)
ci_otg_queue_work(ci);
return HRTIMER_NORESTART;
}
static int ci_otg_init_timers(struct ci_hdrc *ci)
{
hrtimer_init(&ci->otg_fsm_hrtimer, CLOCK_MONOTONIC, HRTIMER_MODE_ABS);
ci->otg_fsm_hrtimer.function = ci_otg_hrtimer_func;
return 0;
}
static void ci_otg_fsm_add_timer(struct otg_fsm *fsm, enum otg_fsm_timer t)
{
struct ci_hdrc *ci = container_of(fsm, struct ci_hdrc, fsm);
if (t < NUM_OTG_FSM_TIMERS)
ci_otg_add_timer(ci, t);
return;
}
static void ci_otg_fsm_del_timer(struct otg_fsm *fsm, enum otg_fsm_timer t)
{
struct ci_hdrc *ci = container_of(fsm, struct ci_hdrc, fsm);
if (t < NUM_OTG_FSM_TIMERS)
ci_otg_del_timer(ci, t);
return;
}
static void ci_otg_drv_vbus(struct otg_fsm *fsm, int on)
{
int ret;
struct ci_hdrc *ci = container_of(fsm, struct ci_hdrc, fsm);
if (on) {
hw_write(ci, OP_PORTSC, PORTSC_W1C_BITS | PORTSC_PP,
PORTSC_PP);
if (ci->platdata->reg_vbus) {
ret = regulator_enable(ci->platdata->reg_vbus);
if (ret) {
dev_err(ci->dev,
"Failed to enable vbus regulator, ret=%d\n",
ret);
return;
}
}
hw_write_otgsc(ci, OTGSC_DPIE, 0);
fsm->a_srp_det = 0;
fsm->power_up = 0;
} else {
if (ci->platdata->reg_vbus)
regulator_disable(ci->platdata->reg_vbus);
fsm->a_bus_drop = 1;
fsm->a_bus_req = 0;
}
}
static void ci_otg_loc_conn(struct otg_fsm *fsm, int on)
{
struct ci_hdrc *ci = container_of(fsm, struct ci_hdrc, fsm);
if (on)
hw_write(ci, OP_USBCMD, USBCMD_RS, USBCMD_RS);
else
hw_write(ci, OP_USBCMD, USBCMD_RS, 0);
}
static void ci_otg_loc_sof(struct otg_fsm *fsm, int on)
{
struct ci_hdrc *ci = container_of(fsm, struct ci_hdrc, fsm);
if (on)
hw_write(ci, OP_PORTSC, PORTSC_W1C_BITS | PORTSC_FPR,
PORTSC_FPR);
else
hw_write(ci, OP_PORTSC, PORTSC_W1C_BITS | PORTSC_SUSP,
PORTSC_SUSP);
}
static void ci_otg_start_pulse(struct otg_fsm *fsm)
{
struct ci_hdrc *ci = container_of(fsm, struct ci_hdrc, fsm);
hw_write_otgsc(ci, OTGSC_HADP, OTGSC_HADP);
pm_runtime_get(ci->dev);
ci_otg_add_timer(ci, B_DATA_PLS);
}
static int ci_otg_start_host(struct otg_fsm *fsm, int on)
{
struct ci_hdrc *ci = container_of(fsm, struct ci_hdrc, fsm);
if (on) {
ci_role_stop(ci);
ci_role_start(ci, CI_ROLE_HOST);
} else {
ci_role_stop(ci);
hw_device_reset(ci);
ci_role_start(ci, CI_ROLE_GADGET);
}
return 0;
}
static int ci_otg_start_gadget(struct otg_fsm *fsm, int on)
{
struct ci_hdrc *ci = container_of(fsm, struct ci_hdrc, fsm);
if (on)
usb_gadget_vbus_connect(&ci->gadget);
else
usb_gadget_vbus_disconnect(&ci->gadget);
return 0;
}
int ci_otg_fsm_work(struct ci_hdrc *ci)
{
if (ci->fsm.id && !(ci->driver) &&
ci->fsm.otg->state < OTG_STATE_A_IDLE)
return 0;
pm_runtime_get_sync(ci->dev);
if (otg_statemachine(&ci->fsm)) {
if (ci->fsm.otg->state == OTG_STATE_A_IDLE) {
if ((ci->fsm.id) || (ci->id_event) ||
(ci->fsm.power_up)) {
ci_otg_queue_work(ci);
} else {
hw_write(ci, OP_PORTSC, PORTSC_W1C_BITS |
PORTSC_PP, 0);
hw_write_otgsc(ci, OTGSC_DPIS, OTGSC_DPIS);
hw_write_otgsc(ci, OTGSC_DPIE, OTGSC_DPIE);
}
if (ci->id_event)
ci->id_event = false;
} else if (ci->fsm.otg->state == OTG_STATE_B_IDLE) {
if (ci->fsm.b_sess_vld) {
ci->fsm.power_up = 0;
ci_otg_queue_work(ci);
}
} else if (ci->fsm.otg->state == OTG_STATE_A_HOST) {
pm_runtime_mark_last_busy(ci->dev);
pm_runtime_put_autosuspend(ci->dev);
return 0;
}
}
pm_runtime_put_sync(ci->dev);
return 0;
}
static void ci_otg_fsm_event(struct ci_hdrc *ci)
{
u32 intr_sts, otg_bsess_vld, port_conn;
struct otg_fsm *fsm = &ci->fsm;
intr_sts = hw_read_intr_status(ci);
otg_bsess_vld = hw_read_otgsc(ci, OTGSC_BSV);
port_conn = hw_read(ci, OP_PORTSC, PORTSC_CCS);
switch (ci->fsm.otg->state) {
case OTG_STATE_A_WAIT_BCON:
if (port_conn) {
fsm->b_conn = 1;
fsm->a_bus_req = 1;
ci_otg_queue_work(ci);
}
break;
case OTG_STATE_B_IDLE:
if (otg_bsess_vld && (intr_sts & USBi_PCI) && port_conn) {
fsm->b_sess_vld = 1;
ci_otg_queue_work(ci);
}
break;
case OTG_STATE_B_PERIPHERAL:
if ((intr_sts & USBi_SLI) && port_conn && otg_bsess_vld) {
fsm->a_bus_suspend = 1;
ci_otg_queue_work(ci);
} else if (intr_sts & USBi_PCI) {
if (fsm->a_bus_suspend == 1)
fsm->a_bus_suspend = 0;
}
break;
case OTG_STATE_B_HOST:
if ((intr_sts & USBi_PCI) && !port_conn) {
fsm->a_conn = 0;
fsm->b_bus_req = 0;
ci_otg_queue_work(ci);
}
break;
case OTG_STATE_A_PERIPHERAL:
if (intr_sts & USBi_SLI) {
fsm->b_bus_suspend = 1;
ci_otg_add_timer(ci, A_BIDL_ADIS);
}
if (intr_sts & USBi_URI)
ci_otg_del_timer(ci, A_BIDL_ADIS);
if (intr_sts & USBi_PCI) {
if (fsm->b_bus_suspend == 1) {
ci_otg_del_timer(ci, A_BIDL_ADIS);
fsm->b_bus_suspend = 0;
}
}
break;
case OTG_STATE_A_SUSPEND:
if ((intr_sts & USBi_PCI) && !port_conn) {
fsm->b_conn = 0;
if (ci->driver) {
ci->gadget.is_a_peripheral = 1;
}
ci_otg_queue_work(ci);
}
break;
case OTG_STATE_A_HOST:
if ((intr_sts & USBi_PCI) && !port_conn) {
fsm->b_conn = 0;
ci_otg_queue_work(ci);
}
break;
case OTG_STATE_B_WAIT_ACON:
if ((intr_sts & USBi_PCI) && port_conn) {
fsm->a_conn = 1;
ci_otg_queue_work(ci);
}
break;
default:
break;
}
}
irqreturn_t ci_otg_fsm_irq(struct ci_hdrc *ci)
{
irqreturn_t retval = IRQ_NONE;
u32 otgsc, otg_int_src = 0;
struct otg_fsm *fsm = &ci->fsm;
otgsc = hw_read_otgsc(ci, ~0);
otg_int_src = otgsc & OTGSC_INT_STATUS_BITS & (otgsc >> 8);
fsm->id = (otgsc & OTGSC_ID) ? 1 : 0;
if (otg_int_src) {
if (otg_int_src & OTGSC_DPIS) {
hw_write_otgsc(ci, OTGSC_DPIS, OTGSC_DPIS);
fsm->a_srp_det = 1;
fsm->a_bus_drop = 0;
} else if (otg_int_src & OTGSC_IDIS) {
hw_write_otgsc(ci, OTGSC_IDIS, OTGSC_IDIS);
if (fsm->id == 0) {
fsm->a_bus_drop = 0;
fsm->a_bus_req = 1;
ci->id_event = true;
}
} else if (otg_int_src & OTGSC_BSVIS) {
hw_write_otgsc(ci, OTGSC_BSVIS, OTGSC_BSVIS);
if (otgsc & OTGSC_BSV) {
fsm->b_sess_vld = 1;
ci_otg_del_timer(ci, B_SSEND_SRP);
ci_otg_del_timer(ci, B_SRP_FAIL);
fsm->b_ssend_srp = 0;
} else {
fsm->b_sess_vld = 0;
if (fsm->id)
ci_otg_add_timer(ci, B_SSEND_SRP);
}
} else if (otg_int_src & OTGSC_AVVIS) {
hw_write_otgsc(ci, OTGSC_AVVIS, OTGSC_AVVIS);
if (otgsc & OTGSC_AVV) {
fsm->a_vbus_vld = 1;
} else {
fsm->a_vbus_vld = 0;
fsm->b_conn = 0;
}
}
ci_otg_queue_work(ci);
return IRQ_HANDLED;
}
ci_otg_fsm_event(ci);
return retval;
}
void ci_hdrc_otg_fsm_start(struct ci_hdrc *ci)
{
ci_otg_queue_work(ci);
}
int ci_hdrc_otg_fsm_init(struct ci_hdrc *ci)
{
int retval = 0;
if (ci->phy)
ci->otg.phy = ci->phy;
else
ci->otg.usb_phy = ci->usb_phy;
ci->otg.gadget = &ci->gadget;
ci->fsm.otg = &ci->otg;
ci->fsm.power_up = 1;
ci->fsm.id = hw_read_otgsc(ci, OTGSC_ID) ? 1 : 0;
ci->fsm.otg->state = OTG_STATE_UNDEFINED;
ci->fsm.ops = &ci_otg_ops;
mutex_init(&ci->fsm.lock);
retval = ci_otg_init_timers(ci);
if (retval) {
dev_err(ci->dev, "Couldn't init OTG timers\n");
return retval;
}
ci->enabled_otg_timer_bits = 0;
ci->next_otg_timer = NUM_OTG_FSM_TIMERS;
retval = sysfs_create_group(&ci->dev->kobj, &inputs_attr_group);
if (retval < 0) {
dev_dbg(ci->dev,
"Can't register sysfs attr group: %d\n", retval);
return retval;
}
hw_write_otgsc(ci, OTGSC_AVVIE, OTGSC_AVVIE);
if (ci->fsm.id) {
ci->fsm.b_ssend_srp =
hw_read_otgsc(ci, OTGSC_BSV) ? 0 : 1;
ci->fsm.b_sess_vld =
hw_read_otgsc(ci, OTGSC_BSV) ? 1 : 0;
hw_write_otgsc(ci, OTGSC_BSVIE, OTGSC_BSVIE);
}
return 0;
}
void ci_hdrc_otg_fsm_remove(struct ci_hdrc *ci)
{
sysfs_remove_group(&ci->dev->kobj, &inputs_attr_group);
}
