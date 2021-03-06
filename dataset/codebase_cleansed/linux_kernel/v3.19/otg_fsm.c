static struct ci_otg_fsm_timer *otg_timer_initializer
(struct ci_hdrc *ci, void (*function)(void *, unsigned long),
unsigned long expires, unsigned long data)
{
struct ci_otg_fsm_timer *timer;
timer = devm_kzalloc(ci->dev, sizeof(struct ci_otg_fsm_timer),
GFP_KERNEL);
if (!timer)
return NULL;
timer->function = function;
timer->expires = expires;
timer->data = data;
return timer;
}
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
static void ci_otg_add_timer(struct ci_hdrc *ci, enum ci_otg_fsm_timer_index t)
{
struct ci_otg_fsm_timer *tmp_timer;
struct ci_otg_fsm_timer *timer = ci->fsm_timer->timer_list[t];
struct list_head *active_timers = &ci->fsm_timer->active_timers;
if (t >= NUM_CI_OTG_FSM_TIMERS)
return;
list_for_each_entry(tmp_timer, active_timers, list)
if (tmp_timer == timer) {
timer->count = timer->expires;
return;
}
timer->count = timer->expires;
list_add_tail(&timer->list, active_timers);
if (!(hw_read_otgsc(ci, OTGSC_1MSIE)))
hw_write_otgsc(ci, OTGSC_1MSIE, OTGSC_1MSIE);
}
static void ci_otg_del_timer(struct ci_hdrc *ci, enum ci_otg_fsm_timer_index t)
{
struct ci_otg_fsm_timer *tmp_timer, *del_tmp;
struct ci_otg_fsm_timer *timer = ci->fsm_timer->timer_list[t];
struct list_head *active_timers = &ci->fsm_timer->active_timers;
if (t >= NUM_CI_OTG_FSM_TIMERS)
return;
list_for_each_entry_safe(tmp_timer, del_tmp, active_timers, list)
if (tmp_timer == timer)
list_del(&timer->list);
if (list_empty(active_timers))
hw_write_otgsc(ci, OTGSC_1MSIE, 0);
}
static inline int ci_otg_tick_timer(struct ci_hdrc *ci)
{
struct ci_otg_fsm_timer *tmp_timer, *del_tmp;
struct list_head *active_timers = &ci->fsm_timer->active_timers;
int expired = 0;
list_for_each_entry_safe(tmp_timer, del_tmp, active_timers, list) {
tmp_timer->count--;
if (!tmp_timer->count) {
list_del(&tmp_timer->list);
tmp_timer->function(ci, tmp_timer->data);
expired = 1;
}
}
if ((expired == 1) && list_empty(active_timers))
hw_write_otgsc(ci, OTGSC_1MSIE, 0);
return expired;
}
static void set_tmout(void *ptr, unsigned long indicator)
{
*(int *)indicator = 1;
}
static void set_tmout_and_fsm(void *ptr, unsigned long indicator)
{
struct ci_hdrc *ci = (struct ci_hdrc *)ptr;
set_tmout(ci, indicator);
ci_otg_queue_work(ci);
}
static void a_wait_vfall_tmout_func(void *ptr, unsigned long indicator)
{
struct ci_hdrc *ci = (struct ci_hdrc *)ptr;
set_tmout(ci, indicator);
hw_write(ci, OP_PORTSC, PORTSC_W1C_BITS | PORTSC_PP, 0);
hw_write_otgsc(ci, OTGSC_DPIS, OTGSC_DPIS);
hw_write_otgsc(ci, OTGSC_DPIE, OTGSC_DPIE);
ci_otg_queue_work(ci);
}
static void b_ase0_brst_tmout_func(void *ptr, unsigned long indicator)
{
struct ci_hdrc *ci = (struct ci_hdrc *)ptr;
set_tmout(ci, indicator);
if (!hw_read_otgsc(ci, OTGSC_BSV))
ci->fsm.b_sess_vld = 0;
ci_otg_queue_work(ci);
}
static void b_ssend_srp_tmout_func(void *ptr, unsigned long indicator)
{
struct ci_hdrc *ci = (struct ci_hdrc *)ptr;
set_tmout(ci, indicator);
if (ci->fsm.otg->state == OTG_STATE_B_IDLE)
ci_otg_queue_work(ci);
}
static void b_sess_vld_tmout_func(void *ptr, unsigned long indicator)
{
struct ci_hdrc *ci = (struct ci_hdrc *)ptr;
if (!(hw_read_otgsc(ci, OTGSC_BSV))) {
ci->fsm.b_sess_vld = 0;
ci_otg_add_timer(ci, B_SSEND_SRP);
ci_otg_queue_work(ci);
}
}
static void b_data_pulse_end(void *ptr, unsigned long indicator)
{
struct ci_hdrc *ci = (struct ci_hdrc *)ptr;
ci->fsm.b_srp_done = 1;
ci->fsm.b_bus_req = 0;
if (ci->fsm.power_up)
ci->fsm.power_up = 0;
hw_write_otgsc(ci, OTGSC_HABA, 0);
ci_otg_queue_work(ci);
}
static int ci_otg_init_timers(struct ci_hdrc *ci)
{
struct otg_fsm *fsm = &ci->fsm;
ci->fsm_timer->timer_list[A_WAIT_VRISE] =
otg_timer_initializer(ci, &set_tmout_and_fsm, TA_WAIT_VRISE,
(unsigned long)&fsm->a_wait_vrise_tmout);
if (ci->fsm_timer->timer_list[A_WAIT_VRISE] == NULL)
return -ENOMEM;
ci->fsm_timer->timer_list[A_WAIT_VFALL] =
otg_timer_initializer(ci, &a_wait_vfall_tmout_func,
TA_WAIT_VFALL, (unsigned long)&fsm->a_wait_vfall_tmout);
if (ci->fsm_timer->timer_list[A_WAIT_VFALL] == NULL)
return -ENOMEM;
ci->fsm_timer->timer_list[A_WAIT_BCON] =
otg_timer_initializer(ci, &set_tmout_and_fsm, TA_WAIT_BCON,
(unsigned long)&fsm->a_wait_bcon_tmout);
if (ci->fsm_timer->timer_list[A_WAIT_BCON] == NULL)
return -ENOMEM;
ci->fsm_timer->timer_list[A_AIDL_BDIS] =
otg_timer_initializer(ci, &set_tmout_and_fsm, TA_AIDL_BDIS,
(unsigned long)&fsm->a_aidl_bdis_tmout);
if (ci->fsm_timer->timer_list[A_AIDL_BDIS] == NULL)
return -ENOMEM;
ci->fsm_timer->timer_list[A_BIDL_ADIS] =
otg_timer_initializer(ci, &set_tmout_and_fsm, TA_BIDL_ADIS,
(unsigned long)&fsm->a_bidl_adis_tmout);
if (ci->fsm_timer->timer_list[A_BIDL_ADIS] == NULL)
return -ENOMEM;
ci->fsm_timer->timer_list[B_ASE0_BRST] =
otg_timer_initializer(ci, &b_ase0_brst_tmout_func, TB_ASE0_BRST,
(unsigned long)&fsm->b_ase0_brst_tmout);
if (ci->fsm_timer->timer_list[B_ASE0_BRST] == NULL)
return -ENOMEM;
ci->fsm_timer->timer_list[B_SE0_SRP] =
otg_timer_initializer(ci, &set_tmout_and_fsm, TB_SE0_SRP,
(unsigned long)&fsm->b_se0_srp);
if (ci->fsm_timer->timer_list[B_SE0_SRP] == NULL)
return -ENOMEM;
ci->fsm_timer->timer_list[B_SSEND_SRP] =
otg_timer_initializer(ci, &b_ssend_srp_tmout_func, TB_SSEND_SRP,
(unsigned long)&fsm->b_ssend_srp);
if (ci->fsm_timer->timer_list[B_SSEND_SRP] == NULL)
return -ENOMEM;
ci->fsm_timer->timer_list[B_SRP_FAIL] =
otg_timer_initializer(ci, &set_tmout, TB_SRP_FAIL,
(unsigned long)&fsm->b_srp_done);
if (ci->fsm_timer->timer_list[B_SRP_FAIL] == NULL)
return -ENOMEM;
ci->fsm_timer->timer_list[B_DATA_PLS] =
otg_timer_initializer(ci, &b_data_pulse_end, TB_DATA_PLS, 0);
if (ci->fsm_timer->timer_list[B_DATA_PLS] == NULL)
return -ENOMEM;
ci->fsm_timer->timer_list[B_SESS_VLD] = otg_timer_initializer(ci,
&b_sess_vld_tmout_func, TB_SESS_VLD, 0);
if (ci->fsm_timer->timer_list[B_SESS_VLD] == NULL)
return -ENOMEM;
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
ci_otg_add_timer(ci, B_DATA_PLS);
}
static int ci_otg_start_host(struct otg_fsm *fsm, int on)
{
struct ci_hdrc *ci = container_of(fsm, struct ci_hdrc, fsm);
mutex_unlock(&fsm->lock);
if (on) {
ci_role_stop(ci);
ci_role_start(ci, CI_ROLE_HOST);
} else {
ci_role_stop(ci);
hw_device_reset(ci);
ci_role_start(ci, CI_ROLE_GADGET);
}
mutex_lock(&fsm->lock);
return 0;
}
static int ci_otg_start_gadget(struct otg_fsm *fsm, int on)
{
struct ci_hdrc *ci = container_of(fsm, struct ci_hdrc, fsm);
mutex_unlock(&fsm->lock);
if (on)
usb_gadget_vbus_connect(&ci->gadget);
else
usb_gadget_vbus_disconnect(&ci->gadget);
mutex_lock(&fsm->lock);
return 0;
}
int ci_otg_fsm_work(struct ci_hdrc *ci)
{
if (ci->fsm.id && !(ci->driver) &&
ci->fsm.otg->state < OTG_STATE_A_IDLE)
return 0;
if (otg_statemachine(&ci->fsm)) {
if (ci->fsm.otg->state == OTG_STATE_A_IDLE) {
if ((ci->fsm.id) || (ci->id_event) ||
(ci->fsm.power_up))
ci_otg_queue_work(ci);
if (ci->id_event)
ci->id_event = false;
} else if (ci->fsm.otg->state == OTG_STATE_B_IDLE) {
if (ci->fsm.b_sess_vld) {
ci->fsm.power_up = 0;
ci_otg_queue_work(ci);
}
}
}
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
ci_otg_add_timer(ci, B_SESS_VLD);
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
if (otg_int_src & OTGSC_1MSIS) {
hw_write_otgsc(ci, OTGSC_1MSIS, OTGSC_1MSIS);
retval = ci_otg_tick_timer(ci);
return IRQ_HANDLED;
} else if (otg_int_src & OTGSC_DPIS) {
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
ci->fsm_timer = devm_kzalloc(ci->dev,
sizeof(struct ci_otg_fsm_timer_list), GFP_KERNEL);
if (!ci->fsm_timer)
return -ENOMEM;
INIT_LIST_HEAD(&ci->fsm_timer->active_timers);
retval = ci_otg_init_timers(ci);
if (retval) {
dev_err(ci->dev, "Couldn't init OTG timers\n");
return retval;
}
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
