static u32 _fsl_readl_be(const unsigned __iomem *p)
{
return in_be32(p);
}
static u32 _fsl_readl_le(const unsigned __iomem *p)
{
return in_le32(p);
}
static void _fsl_writel_be(u32 v, unsigned __iomem *p)
{
out_be32(p, v);
}
static void _fsl_writel_le(u32 v, unsigned __iomem *p)
{
out_le32(p, v);
}
int write_ulpi(u8 addr, u8 data)
{
u32 temp;
temp = 0x60000000 | (addr << 16) | data;
fsl_writel(temp, &usb_dr_regs->ulpiview);
return 0;
}
void fsl_otg_chrg_vbus(struct otg_fsm *fsm, int on)
{
u32 tmp;
tmp = fsl_readl(&usb_dr_regs->otgsc) & ~OTGSC_INTSTS_MASK;
if (on)
tmp = (tmp & ~OTGSC_CTRL_VBUS_DISCHARGE) |
OTGSC_CTRL_VBUS_CHARGE;
else
tmp &= ~OTGSC_CTRL_VBUS_CHARGE;
fsl_writel(tmp, &usb_dr_regs->otgsc);
}
void fsl_otg_dischrg_vbus(int on)
{
u32 tmp;
tmp = fsl_readl(&usb_dr_regs->otgsc) & ~OTGSC_INTSTS_MASK;
if (on)
tmp = (tmp & ~OTGSC_CTRL_VBUS_CHARGE) |
OTGSC_CTRL_VBUS_DISCHARGE;
else
tmp &= ~OTGSC_CTRL_VBUS_DISCHARGE;
fsl_writel(tmp, &usb_dr_regs->otgsc);
}
void fsl_otg_drv_vbus(struct otg_fsm *fsm, int on)
{
u32 tmp;
if (on) {
tmp = fsl_readl(&usb_dr_regs->portsc) & ~PORTSC_W1C_BITS;
fsl_writel(tmp | PORTSC_PORT_POWER, &usb_dr_regs->portsc);
} else {
tmp = fsl_readl(&usb_dr_regs->portsc) &
~PORTSC_W1C_BITS & ~PORTSC_PORT_POWER;
fsl_writel(tmp, &usb_dr_regs->portsc);
}
}
void fsl_otg_loc_conn(struct otg_fsm *fsm, int on)
{
u32 tmp;
tmp = fsl_readl(&usb_dr_regs->otgsc) & ~OTGSC_INTSTS_MASK;
if (on)
tmp |= OTGSC_CTRL_DATA_PULSING;
else
tmp &= ~OTGSC_CTRL_DATA_PULSING;
fsl_writel(tmp, &usb_dr_regs->otgsc);
}
void fsl_otg_loc_sof(struct otg_fsm *fsm, int on)
{
u32 tmp;
tmp = fsl_readl(&fsl_otg_dev->dr_mem_map->portsc) & ~PORTSC_W1C_BITS;
if (on)
tmp |= PORTSC_PORT_FORCE_RESUME;
else
tmp |= PORTSC_PORT_SUSPEND;
fsl_writel(tmp, &fsl_otg_dev->dr_mem_map->portsc);
}
void fsl_otg_start_pulse(struct otg_fsm *fsm)
{
u32 tmp;
srp_wait_done = 0;
#ifdef HA_DATA_PULSE
tmp = fsl_readl(&usb_dr_regs->otgsc) & ~OTGSC_INTSTS_MASK;
tmp |= OTGSC_HA_DATA_PULSE;
fsl_writel(tmp, &usb_dr_regs->otgsc);
#else
fsl_otg_loc_conn(1);
#endif
fsl_otg_add_timer(fsm, b_data_pulse_tmr);
}
void b_data_pulse_end(unsigned long foo)
{
#ifdef HA_DATA_PULSE
#else
fsl_otg_loc_conn(0);
#endif
fsl_otg_pulse_vbus();
}
void fsl_otg_pulse_vbus(void)
{
srp_wait_done = 0;
fsl_otg_chrg_vbus(&fsl_otg_dev->fsm, 1);
fsl_otg_add_timer(&fsl_otg_dev->fsm, b_vbus_pulse_tmr);
}
void b_vbus_pulse_end(unsigned long foo)
{
fsl_otg_chrg_vbus(&fsl_otg_dev->fsm, 0);
fsl_otg_dischrg_vbus(1);
fsl_otg_add_timer(&fsl_otg_dev->fsm, b_srp_wait_tmr);
}
void b_srp_end(unsigned long foo)
{
fsl_otg_dischrg_vbus(0);
srp_wait_done = 1;
if ((fsl_otg_dev->phy.otg->state == OTG_STATE_B_SRP_INIT) &&
fsl_otg_dev->fsm.b_sess_vld)
fsl_otg_dev->fsm.b_srp_done = 1;
}
void a_wait_enum(unsigned long foo)
{
VDBG("a_wait_enum timeout\n");
if (!fsl_otg_dev->phy.otg->host->b_hnp_enable)
fsl_otg_add_timer(&fsl_otg_dev->fsm, a_wait_enum_tmr);
else
otg_statemachine(&fsl_otg_dev->fsm);
}
void set_tmout(unsigned long indicator)
{
*(int *)indicator = 1;
}
int fsl_otg_init_timers(struct otg_fsm *fsm)
{
a_wait_vrise_tmr = otg_timer_initializer(&set_tmout, TA_WAIT_VRISE,
(unsigned long)&fsm->a_wait_vrise_tmout);
if (!a_wait_vrise_tmr)
return -ENOMEM;
a_wait_bcon_tmr = otg_timer_initializer(&set_tmout, TA_WAIT_BCON,
(unsigned long)&fsm->a_wait_bcon_tmout);
if (!a_wait_bcon_tmr)
return -ENOMEM;
a_aidl_bdis_tmr = otg_timer_initializer(&set_tmout, TA_AIDL_BDIS,
(unsigned long)&fsm->a_aidl_bdis_tmout);
if (!a_aidl_bdis_tmr)
return -ENOMEM;
b_ase0_brst_tmr = otg_timer_initializer(&set_tmout, TB_ASE0_BRST,
(unsigned long)&fsm->b_ase0_brst_tmout);
if (!b_ase0_brst_tmr)
return -ENOMEM;
b_se0_srp_tmr = otg_timer_initializer(&set_tmout, TB_SE0_SRP,
(unsigned long)&fsm->b_se0_srp);
if (!b_se0_srp_tmr)
return -ENOMEM;
b_srp_fail_tmr = otg_timer_initializer(&set_tmout, TB_SRP_FAIL,
(unsigned long)&fsm->b_srp_done);
if (!b_srp_fail_tmr)
return -ENOMEM;
a_wait_enum_tmr = otg_timer_initializer(&a_wait_enum, 10,
(unsigned long)&fsm);
if (!a_wait_enum_tmr)
return -ENOMEM;
b_srp_wait_tmr = otg_timer_initializer(&b_srp_end, TB_SRP_WAIT, 0);
if (!b_srp_wait_tmr)
return -ENOMEM;
b_data_pulse_tmr = otg_timer_initializer(&b_data_pulse_end,
TB_DATA_PLS, 0);
if (!b_data_pulse_tmr)
return -ENOMEM;
b_vbus_pulse_tmr = otg_timer_initializer(&b_vbus_pulse_end,
TB_VBUS_PLS, 0);
if (!b_vbus_pulse_tmr)
return -ENOMEM;
return 0;
}
void fsl_otg_uninit_timers(void)
{
kfree(a_wait_vrise_tmr);
kfree(a_wait_bcon_tmr);
kfree(a_aidl_bdis_tmr);
kfree(b_ase0_brst_tmr);
kfree(b_se0_srp_tmr);
kfree(b_srp_fail_tmr);
kfree(a_wait_enum_tmr);
kfree(b_srp_wait_tmr);
kfree(b_data_pulse_tmr);
kfree(b_vbus_pulse_tmr);
}
static struct fsl_otg_timer *fsl_otg_get_timer(enum otg_fsm_timer t)
{
struct fsl_otg_timer *timer;
switch (t) {
case A_WAIT_VRISE:
timer = a_wait_vrise_tmr;
break;
case A_WAIT_BCON:
timer = a_wait_vrise_tmr;
break;
case A_AIDL_BDIS:
timer = a_wait_vrise_tmr;
break;
case B_ASE0_BRST:
timer = a_wait_vrise_tmr;
break;
case B_SE0_SRP:
timer = a_wait_vrise_tmr;
break;
case B_SRP_FAIL:
timer = a_wait_vrise_tmr;
break;
case A_WAIT_ENUM:
timer = a_wait_vrise_tmr;
break;
default:
timer = NULL;
}
return timer;
}
void fsl_otg_add_timer(struct otg_fsm *fsm, void *gtimer)
{
struct fsl_otg_timer *timer = gtimer;
struct fsl_otg_timer *tmp_timer;
list_for_each_entry(tmp_timer, &active_timers, list)
if (tmp_timer == timer) {
timer->count = timer->expires;
return;
}
timer->count = timer->expires;
list_add_tail(&timer->list, &active_timers);
}
static void fsl_otg_fsm_add_timer(struct otg_fsm *fsm, enum otg_fsm_timer t)
{
struct fsl_otg_timer *timer;
timer = fsl_otg_get_timer(t);
if (!timer)
return;
fsl_otg_add_timer(fsm, timer);
}
void fsl_otg_del_timer(struct otg_fsm *fsm, void *gtimer)
{
struct fsl_otg_timer *timer = gtimer;
struct fsl_otg_timer *tmp_timer, *del_tmp;
list_for_each_entry_safe(tmp_timer, del_tmp, &active_timers, list)
if (tmp_timer == timer)
list_del(&timer->list);
}
static void fsl_otg_fsm_del_timer(struct otg_fsm *fsm, enum otg_fsm_timer t)
{
struct fsl_otg_timer *timer;
timer = fsl_otg_get_timer(t);
if (!timer)
return;
fsl_otg_del_timer(fsm, timer);
}
void otg_reset_controller(void)
{
u32 command;
command = fsl_readl(&usb_dr_regs->usbcmd);
command |= (1 << 1);
fsl_writel(command, &usb_dr_regs->usbcmd);
while (fsl_readl(&usb_dr_regs->usbcmd) & (1 << 1))
;
}
int fsl_otg_start_host(struct otg_fsm *fsm, int on)
{
struct usb_otg *otg = fsm->otg;
struct device *dev;
struct fsl_otg *otg_dev =
container_of(otg->usb_phy, struct fsl_otg, phy);
u32 retval = 0;
if (!otg->host)
return -ENODEV;
dev = otg->host->controller;
fsm->a_vbus_vld =
!!(fsl_readl(&usb_dr_regs->otgsc) & OTGSC_STS_A_VBUS_VALID);
if (on) {
if (otg_dev->host_working)
goto end;
else {
otg_reset_controller();
VDBG("host on......\n");
if (dev->driver->pm && dev->driver->pm->resume) {
retval = dev->driver->pm->resume(dev);
if (fsm->id) {
fsl_otg_drv_vbus(fsm, 1);
write_ulpi(0x0c, 0x20);
}
}
otg_dev->host_working = 1;
}
} else {
if (!otg_dev->host_working)
goto end;
else {
VDBG("host off......\n");
if (dev && dev->driver) {
if (dev->driver->pm && dev->driver->pm->suspend)
retval = dev->driver->pm->suspend(dev);
if (fsm->id)
fsl_otg_drv_vbus(fsm, 0);
}
otg_dev->host_working = 0;
}
}
end:
return retval;
}
int fsl_otg_start_gadget(struct otg_fsm *fsm, int on)
{
struct usb_otg *otg = fsm->otg;
struct device *dev;
if (!otg->gadget || !otg->gadget->dev.parent)
return -ENODEV;
VDBG("gadget %s\n", on ? "on" : "off");
dev = otg->gadget->dev.parent;
if (on) {
if (dev->driver->resume)
dev->driver->resume(dev);
} else {
if (dev->driver->suspend)
dev->driver->suspend(dev, otg_suspend_state);
}
return 0;
}
static int fsl_otg_set_host(struct usb_otg *otg, struct usb_bus *host)
{
struct fsl_otg *otg_dev;
if (!otg)
return -ENODEV;
otg_dev = container_of(otg->usb_phy, struct fsl_otg, phy);
if (otg_dev != fsl_otg_dev)
return -ENODEV;
otg->host = host;
otg_dev->fsm.a_bus_drop = 0;
otg_dev->fsm.a_bus_req = 1;
if (host) {
VDBG("host off......\n");
otg->host->otg_port = fsl_otg_initdata.otg_port;
otg->host->is_b_host = otg_dev->fsm.id;
otg_dev->host_working = 1;
schedule_delayed_work(&otg_dev->otg_event, 100);
return 0;
} else {
if (!(fsl_readl(&otg_dev->dr_mem_map->otgsc) &
OTGSC_STS_USB_ID)) {
struct otg_fsm *fsm = &otg_dev->fsm;
otg->state = OTG_STATE_UNDEFINED;
fsm->protocol = PROTO_UNDEF;
}
}
otg_dev->host_working = 0;
otg_statemachine(&otg_dev->fsm);
return 0;
}
static int fsl_otg_set_peripheral(struct usb_otg *otg,
struct usb_gadget *gadget)
{
struct fsl_otg *otg_dev;
if (!otg)
return -ENODEV;
otg_dev = container_of(otg->usb_phy, struct fsl_otg, phy);
VDBG("otg_dev 0x%x\n", (int)otg_dev);
VDBG("fsl_otg_dev 0x%x\n", (int)fsl_otg_dev);
if (otg_dev != fsl_otg_dev)
return -ENODEV;
if (!gadget) {
if (!otg->default_a)
otg->gadget->ops->vbus_draw(otg->gadget, 0);
usb_gadget_vbus_disconnect(otg->gadget);
otg->gadget = 0;
otg_dev->fsm.b_bus_req = 0;
otg_statemachine(&otg_dev->fsm);
return 0;
}
otg->gadget = gadget;
otg->gadget->is_a_peripheral = !otg_dev->fsm.id;
otg_dev->fsm.b_bus_req = 1;
pr_debug("ID pin=%d\n", otg_dev->fsm.id);
if (otg_dev->fsm.id == 1) {
fsl_otg_start_host(&otg_dev->fsm, 0);
otg_drv_vbus(&otg_dev->fsm, 0);
fsl_otg_start_gadget(&otg_dev->fsm, 1);
}
return 0;
}
static void fsl_otg_event(struct work_struct *work)
{
struct fsl_otg *og = container_of(work, struct fsl_otg, otg_event.work);
struct otg_fsm *fsm = &og->fsm;
if (fsm->id) {
fsl_otg_start_host(fsm, 0);
otg_drv_vbus(fsm, 0);
fsl_otg_start_gadget(fsm, 1);
}
}
static int fsl_otg_start_srp(struct usb_otg *otg)
{
struct fsl_otg *otg_dev;
if (!otg || otg->state != OTG_STATE_B_IDLE)
return -ENODEV;
otg_dev = container_of(otg->usb_phy, struct fsl_otg, phy);
if (otg_dev != fsl_otg_dev)
return -ENODEV;
otg_dev->fsm.b_bus_req = 1;
otg_statemachine(&otg_dev->fsm);
return 0;
}
static int fsl_otg_start_hnp(struct usb_otg *otg)
{
struct fsl_otg *otg_dev;
if (!otg)
return -ENODEV;
otg_dev = container_of(otg->usb_phy, struct fsl_otg, phy);
if (otg_dev != fsl_otg_dev)
return -ENODEV;
pr_debug("start_hnp...\n");
otg_dev->fsm.a_bus_req = 0;
otg_statemachine(&otg_dev->fsm);
return 0;
}
irqreturn_t fsl_otg_isr(int irq, void *dev_id)
{
struct otg_fsm *fsm = &((struct fsl_otg *)dev_id)->fsm;
struct usb_otg *otg = ((struct fsl_otg *)dev_id)->phy.otg;
u32 otg_int_src, otg_sc;
otg_sc = fsl_readl(&usb_dr_regs->otgsc);
otg_int_src = otg_sc & OTGSC_INTSTS_MASK & (otg_sc >> 8);
fsl_writel(otg_sc, &usb_dr_regs->otgsc);
fsm->id = (otg_sc & OTGSC_STS_USB_ID) ? 1 : 0;
otg->default_a = (fsm->id == 0);
if (otg_int_src) {
if (otg_int_src & OTGSC_INTSTS_USB_ID) {
fsm->id = (otg_sc & OTGSC_STS_USB_ID) ? 1 : 0;
otg->default_a = (fsm->id == 0);
if (fsm->id)
fsm->b_conn = 0;
else
fsm->a_conn = 0;
if (otg->host)
otg->host->is_b_host = fsm->id;
if (otg->gadget)
otg->gadget->is_a_peripheral = !fsm->id;
VDBG("ID int (ID is %d)\n", fsm->id);
if (fsm->id) {
schedule_delayed_work(
&((struct fsl_otg *)dev_id)->otg_event,
100);
} else {
cancel_delayed_work(&
((struct fsl_otg *)dev_id)->
otg_event);
fsl_otg_start_gadget(fsm, 0);
otg_drv_vbus(fsm, 1);
fsl_otg_start_host(fsm, 1);
}
return IRQ_HANDLED;
}
}
return IRQ_NONE;
}
static int fsl_otg_conf(struct platform_device *pdev)
{
struct fsl_otg *fsl_otg_tc;
int status;
if (fsl_otg_dev)
return 0;
fsl_otg_tc = kzalloc(sizeof(struct fsl_otg), GFP_KERNEL);
if (!fsl_otg_tc)
return -ENOMEM;
fsl_otg_tc->phy.otg = kzalloc(sizeof(struct usb_otg), GFP_KERNEL);
if (!fsl_otg_tc->phy.otg) {
kfree(fsl_otg_tc);
return -ENOMEM;
}
INIT_DELAYED_WORK(&fsl_otg_tc->otg_event, fsl_otg_event);
INIT_LIST_HEAD(&active_timers);
status = fsl_otg_init_timers(&fsl_otg_tc->fsm);
if (status) {
pr_info("Couldn't init OTG timers\n");
goto err;
}
mutex_init(&fsl_otg_tc->fsm.lock);
fsl_otg_tc->fsm.ops = &fsl_otg_ops;
fsl_otg_tc->phy.label = DRIVER_DESC;
fsl_otg_tc->phy.dev = &pdev->dev;
fsl_otg_tc->phy.otg->usb_phy = &fsl_otg_tc->phy;
fsl_otg_tc->phy.otg->set_host = fsl_otg_set_host;
fsl_otg_tc->phy.otg->set_peripheral = fsl_otg_set_peripheral;
fsl_otg_tc->phy.otg->start_hnp = fsl_otg_start_hnp;
fsl_otg_tc->phy.otg->start_srp = fsl_otg_start_srp;
fsl_otg_dev = fsl_otg_tc;
status = usb_add_phy(&fsl_otg_tc->phy, USB_PHY_TYPE_USB2);
if (status) {
pr_warn(FSL_OTG_NAME ": unable to register OTG transceiver.\n");
goto err;
}
return 0;
err:
fsl_otg_uninit_timers();
kfree(fsl_otg_tc->phy.otg);
kfree(fsl_otg_tc);
return status;
}
int usb_otg_start(struct platform_device *pdev)
{
struct fsl_otg *p_otg;
struct usb_phy *otg_trans = usb_get_phy(USB_PHY_TYPE_USB2);
struct otg_fsm *fsm;
int status;
struct resource *res;
u32 temp;
struct fsl_usb2_platform_data *pdata = dev_get_platdata(&pdev->dev);
p_otg = container_of(otg_trans, struct fsl_otg, phy);
fsm = &p_otg->fsm;
SET_OTG_STATE(otg_trans, OTG_STATE_UNDEFINED);
fsm->otg = p_otg->phy.otg;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENXIO;
usb_dr_regs = ioremap(res->start, sizeof(struct usb_dr_mmap));
p_otg->dr_mem_map = (struct usb_dr_mmap *)usb_dr_regs;
pdata->regs = (void *)usb_dr_regs;
if (pdata->init && pdata->init(pdev) != 0)
return -EINVAL;
if (pdata->big_endian_mmio) {
_fsl_readl = _fsl_readl_be;
_fsl_writel = _fsl_writel_be;
} else {
_fsl_readl = _fsl_readl_le;
_fsl_writel = _fsl_writel_le;
}
p_otg->irq = platform_get_irq(pdev, 0);
status = request_irq(p_otg->irq, fsl_otg_isr,
IRQF_SHARED, driver_name, p_otg);
if (status) {
dev_dbg(p_otg->phy.dev, "can't get IRQ %d, error %d\n",
p_otg->irq, status);
iounmap(p_otg->dr_mem_map);
kfree(p_otg->phy.otg);
kfree(p_otg);
return status;
}
temp = fsl_readl(&p_otg->dr_mem_map->usbcmd);
temp &= ~USB_CMD_RUN_STOP;
fsl_writel(temp, &p_otg->dr_mem_map->usbcmd);
temp = fsl_readl(&p_otg->dr_mem_map->usbcmd);
temp |= USB_CMD_CTRL_RESET;
fsl_writel(temp, &p_otg->dr_mem_map->usbcmd);
while (fsl_readl(&p_otg->dr_mem_map->usbcmd) & USB_CMD_CTRL_RESET)
;
temp = USB_MODE_STREAM_DISABLE | (pdata->es ? USB_MODE_ES : 0);
fsl_writel(temp, &p_otg->dr_mem_map->usbmode);
temp = fsl_readl(&p_otg->dr_mem_map->portsc);
temp &= ~(PORTSC_PHY_TYPE_SEL | PORTSC_PTW);
switch (pdata->phy_mode) {
case FSL_USB2_PHY_ULPI:
temp |= PORTSC_PTS_ULPI;
break;
case FSL_USB2_PHY_UTMI_WIDE:
temp |= PORTSC_PTW_16BIT;
case FSL_USB2_PHY_UTMI:
temp |= PORTSC_PTS_UTMI;
default:
break;
}
fsl_writel(temp, &p_otg->dr_mem_map->portsc);
if (pdata->have_sysif_regs) {
temp = __raw_readl(&p_otg->dr_mem_map->control);
temp |= USB_CTRL_IOENB;
__raw_writel(temp, &p_otg->dr_mem_map->control);
}
temp = fsl_readl(&p_otg->dr_mem_map->otgsc);
temp &= ~OTGSC_INTERRUPT_ENABLE_BITS_MASK;
temp |= OTGSC_INTERRUPT_STATUS_BITS_MASK | OTGSC_CTRL_VBUS_DISCHARGE;
fsl_writel(temp, &p_otg->dr_mem_map->otgsc);
if (fsl_readl(&p_otg->dr_mem_map->otgsc) & OTGSC_STS_USB_ID) {
p_otg->phy.otg->state = OTG_STATE_UNDEFINED;
p_otg->fsm.id = 1;
} else {
p_otg->phy.otg->state = OTG_STATE_A_IDLE;
p_otg->fsm.id = 0;
}
pr_debug("initial ID pin=%d\n", p_otg->fsm.id);
temp = fsl_readl(&p_otg->dr_mem_map->otgsc);
temp |= OTGSC_INTR_USB_ID_EN;
temp &= ~(OTGSC_CTRL_VBUS_DISCHARGE | OTGSC_INTR_1MS_TIMER_EN);
fsl_writel(temp, &p_otg->dr_mem_map->otgsc);
return 0;
}
static int show_fsl_usb2_otg_state(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct otg_fsm *fsm = &fsl_otg_dev->fsm;
char *next = buf;
unsigned size = PAGE_SIZE;
int t;
mutex_lock(&fsm->lock);
t = scnprintf(next, size,
DRIVER_DESC "\n" "fsl_usb2_otg version: %s\n\n",
DRIVER_VERSION);
size -= t;
next += t;
t = scnprintf(next, size,
"OTGSC: 0x%08x\n"
"PORTSC: 0x%08x\n"
"USBMODE: 0x%08x\n"
"USBCMD: 0x%08x\n"
"USBSTS: 0x%08x\n"
"USBINTR: 0x%08x\n",
fsl_readl(&usb_dr_regs->otgsc),
fsl_readl(&usb_dr_regs->portsc),
fsl_readl(&usb_dr_regs->usbmode),
fsl_readl(&usb_dr_regs->usbcmd),
fsl_readl(&usb_dr_regs->usbsts),
fsl_readl(&usb_dr_regs->usbintr));
size -= t;
next += t;
t = scnprintf(next, size,
"OTG state: %s\n\n",
usb_otg_state_string(fsl_otg_dev->phy.otg->state));
size -= t;
next += t;
t = scnprintf(next, size,
"a_bus_req: %d\n"
"b_bus_req: %d\n"
"a_bus_resume: %d\n"
"a_bus_suspend: %d\n"
"a_conn: %d\n"
"a_sess_vld: %d\n"
"a_srp_det: %d\n"
"a_vbus_vld: %d\n"
"b_bus_resume: %d\n"
"b_bus_suspend: %d\n"
"b_conn: %d\n"
"b_se0_srp: %d\n"
"b_ssend_srp: %d\n"
"b_sess_vld: %d\n"
"id: %d\n",
fsm->a_bus_req,
fsm->b_bus_req,
fsm->a_bus_resume,
fsm->a_bus_suspend,
fsm->a_conn,
fsm->a_sess_vld,
fsm->a_srp_det,
fsm->a_vbus_vld,
fsm->b_bus_resume,
fsm->b_bus_suspend,
fsm->b_conn,
fsm->b_se0_srp,
fsm->b_ssend_srp,
fsm->b_sess_vld,
fsm->id);
size -= t;
next += t;
mutex_unlock(&fsm->lock);
return PAGE_SIZE - size;
}
static long fsl_otg_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
u32 retval = 0;
switch (cmd) {
case GET_OTG_STATUS:
retval = fsl_otg_dev->host_working;
break;
case SET_A_SUSPEND_REQ:
fsl_otg_dev->fsm.a_suspend_req_inf = arg;
break;
case SET_A_BUS_DROP:
fsl_otg_dev->fsm.a_bus_drop = arg;
break;
case SET_A_BUS_REQ:
fsl_otg_dev->fsm.a_bus_req = arg;
break;
case SET_B_BUS_REQ:
fsl_otg_dev->fsm.b_bus_req = arg;
break;
default:
break;
}
otg_statemachine(&fsl_otg_dev->fsm);
return retval;
}
static int fsl_otg_open(struct inode *inode, struct file *file)
{
return 0;
}
static int fsl_otg_release(struct inode *inode, struct file *file)
{
return 0;
}
static int fsl_otg_probe(struct platform_device *pdev)
{
int ret;
if (!dev_get_platdata(&pdev->dev))
return -ENODEV;
ret = fsl_otg_conf(pdev);
if (ret) {
dev_err(&pdev->dev, "Couldn't configure OTG module\n");
return ret;
}
ret = usb_otg_start(pdev);
if (ret) {
dev_err(&pdev->dev, "Can't init FSL OTG device\n");
return ret;
}
ret = register_chrdev(FSL_OTG_MAJOR, FSL_OTG_NAME, &otg_fops);
if (ret) {
dev_err(&pdev->dev, "unable to register FSL OTG device\n");
return ret;
}
ret = device_create_file(&pdev->dev, &dev_attr_fsl_usb2_otg_state);
if (ret)
dev_warn(&pdev->dev, "Can't register sysfs attribute\n");
return ret;
}
static int fsl_otg_remove(struct platform_device *pdev)
{
struct fsl_usb2_platform_data *pdata = dev_get_platdata(&pdev->dev);
usb_remove_phy(&fsl_otg_dev->phy);
free_irq(fsl_otg_dev->irq, fsl_otg_dev);
iounmap((void *)usb_dr_regs);
fsl_otg_uninit_timers();
kfree(fsl_otg_dev->phy.otg);
kfree(fsl_otg_dev);
device_remove_file(&pdev->dev, &dev_attr_fsl_usb2_otg_state);
unregister_chrdev(FSL_OTG_MAJOR, FSL_OTG_NAME);
if (pdata->exit)
pdata->exit(pdev);
return 0;
}
