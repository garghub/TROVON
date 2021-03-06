static int __init cio_debug_init(void)
{
cio_debug_msg_id = debug_register("cio_msg", 16, 1, 16 * sizeof(long));
if (!cio_debug_msg_id)
goto out_unregister;
debug_register_view(cio_debug_msg_id, &debug_sprintf_view);
debug_set_level(cio_debug_msg_id, 2);
cio_debug_trace_id = debug_register("cio_trace", 16, 1, 16);
if (!cio_debug_trace_id)
goto out_unregister;
debug_register_view(cio_debug_trace_id, &debug_hex_ascii_view);
debug_set_level(cio_debug_trace_id, 2);
cio_debug_crw_id = debug_register("cio_crw", 16, 1, 16 * sizeof(long));
if (!cio_debug_crw_id)
goto out_unregister;
debug_register_view(cio_debug_crw_id, &debug_sprintf_view);
debug_set_level(cio_debug_crw_id, 4);
return 0;
out_unregister:
if (cio_debug_msg_id)
debug_unregister(cio_debug_msg_id);
if (cio_debug_trace_id)
debug_unregister(cio_debug_trace_id);
if (cio_debug_crw_id)
debug_unregister(cio_debug_crw_id);
return -1;
}
int cio_set_options(struct subchannel *sch, int flags)
{
struct io_subchannel_private *priv = to_io_private(sch);
priv->options.suspend = (flags & DOIO_ALLOW_SUSPEND) != 0;
priv->options.prefetch = (flags & DOIO_DENY_PREFETCH) != 0;
priv->options.inter = (flags & DOIO_SUPPRESS_INTER) != 0;
return 0;
}
static int
cio_start_handle_notoper(struct subchannel *sch, __u8 lpm)
{
char dbf_text[15];
if (lpm != 0)
sch->lpm &= ~lpm;
else
sch->lpm = 0;
CIO_MSG_EVENT(2, "cio_start: 'not oper' status for "
"subchannel 0.%x.%04x!\n", sch->schid.ssid,
sch->schid.sch_no);
if (cio_update_schib(sch))
return -ENODEV;
sprintf(dbf_text, "no%s", dev_name(&sch->dev));
CIO_TRACE_EVENT(0, dbf_text);
CIO_HEX_EVENT(0, &sch->schib, sizeof (struct schib));
return (sch->lpm ? -EACCES : -ENODEV);
}
int
cio_start_key (struct subchannel *sch,
struct ccw1 * cpa,
__u8 lpm,
__u8 key)
{
struct io_subchannel_private *priv = to_io_private(sch);
union orb *orb = &priv->orb;
int ccode;
CIO_TRACE_EVENT(5, "stIO");
CIO_TRACE_EVENT(5, dev_name(&sch->dev));
memset(orb, 0, sizeof(union orb));
orb->cmd.intparm = (u32)(addr_t)sch;
orb->cmd.fmt = 1;
orb->cmd.pfch = priv->options.prefetch == 0;
orb->cmd.spnd = priv->options.suspend;
orb->cmd.ssic = priv->options.suspend && priv->options.inter;
orb->cmd.lpm = (lpm != 0) ? lpm : sch->lpm;
#ifdef CONFIG_64BIT
orb->cmd.c64 = 1;
orb->cmd.i2k = 0;
#endif
orb->cmd.key = key >> 4;
orb->cmd.cpa = (__u32) __pa(cpa);
ccode = ssch(sch->schid, orb);
CIO_HEX_EVENT(5, &ccode, sizeof(ccode));
switch (ccode) {
case 0:
sch->schib.scsw.cmd.actl |= SCSW_ACTL_START_PEND;
return 0;
case 1:
case 2:
return -EBUSY;
case 3:
return cio_start_handle_notoper(sch, lpm);
default:
return ccode;
}
}
int
cio_start (struct subchannel *sch, struct ccw1 *cpa, __u8 lpm)
{
return cio_start_key(sch, cpa, lpm, PAGE_DEFAULT_KEY);
}
int
cio_resume (struct subchannel *sch)
{
int ccode;
CIO_TRACE_EVENT(4, "resIO");
CIO_TRACE_EVENT(4, dev_name(&sch->dev));
ccode = rsch (sch->schid);
CIO_HEX_EVENT(4, &ccode, sizeof(ccode));
switch (ccode) {
case 0:
sch->schib.scsw.cmd.actl |= SCSW_ACTL_RESUME_PEND;
return 0;
case 1:
return -EBUSY;
case 2:
return -EINVAL;
default:
return -ENODEV;
}
}
int
cio_halt(struct subchannel *sch)
{
int ccode;
if (!sch)
return -ENODEV;
CIO_TRACE_EVENT(2, "haltIO");
CIO_TRACE_EVENT(2, dev_name(&sch->dev));
ccode = hsch (sch->schid);
CIO_HEX_EVENT(2, &ccode, sizeof(ccode));
switch (ccode) {
case 0:
sch->schib.scsw.cmd.actl |= SCSW_ACTL_HALT_PEND;
return 0;
case 1:
case 2:
return -EBUSY;
default:
return -ENODEV;
}
}
int
cio_clear(struct subchannel *sch)
{
int ccode;
if (!sch)
return -ENODEV;
CIO_TRACE_EVENT(2, "clearIO");
CIO_TRACE_EVENT(2, dev_name(&sch->dev));
ccode = csch (sch->schid);
CIO_HEX_EVENT(2, &ccode, sizeof(ccode));
switch (ccode) {
case 0:
sch->schib.scsw.cmd.actl |= SCSW_ACTL_CLEAR_PEND;
return 0;
default:
return -ENODEV;
}
}
int
cio_cancel (struct subchannel *sch)
{
int ccode;
if (!sch)
return -ENODEV;
CIO_TRACE_EVENT(2, "cancelIO");
CIO_TRACE_EVENT(2, dev_name(&sch->dev));
ccode = xsch (sch->schid);
CIO_HEX_EVENT(2, &ccode, sizeof(ccode));
switch (ccode) {
case 0:
if (cio_update_schib(sch))
return -ENODEV;
return 0;
case 1:
return -EBUSY;
case 2:
return -EINVAL;
default:
return -ENODEV;
}
}
static void cio_apply_config(struct subchannel *sch, struct schib *schib)
{
schib->pmcw.intparm = sch->config.intparm;
schib->pmcw.mbi = sch->config.mbi;
schib->pmcw.isc = sch->config.isc;
schib->pmcw.ena = sch->config.ena;
schib->pmcw.mme = sch->config.mme;
schib->pmcw.mp = sch->config.mp;
schib->pmcw.csense = sch->config.csense;
schib->pmcw.mbfc = sch->config.mbfc;
if (sch->config.mbfc)
schib->mba = sch->config.mba;
}
static int cio_check_config(struct subchannel *sch, struct schib *schib)
{
return (schib->pmcw.intparm == sch->config.intparm) &&
(schib->pmcw.mbi == sch->config.mbi) &&
(schib->pmcw.isc == sch->config.isc) &&
(schib->pmcw.ena == sch->config.ena) &&
(schib->pmcw.mme == sch->config.mme) &&
(schib->pmcw.mp == sch->config.mp) &&
(schib->pmcw.csense == sch->config.csense) &&
(schib->pmcw.mbfc == sch->config.mbfc) &&
(!sch->config.mbfc || (schib->mba == sch->config.mba));
}
int cio_commit_config(struct subchannel *sch)
{
struct schib schib;
int ccode, retry, ret = 0;
if (stsch_err(sch->schid, &schib) || !css_sch_is_valid(&schib))
return -ENODEV;
for (retry = 0; retry < 5; retry++) {
cio_apply_config(sch, &schib);
ccode = msch_err(sch->schid, &schib);
if (ccode < 0)
return ccode;
switch (ccode) {
case 0:
if (stsch_err(sch->schid, &schib) ||
!css_sch_is_valid(&schib))
return -ENODEV;
if (cio_check_config(sch, &schib)) {
memcpy(&sch->schib, &schib, sizeof(schib));
return 0;
}
ret = -EAGAIN;
break;
case 1:
return -EBUSY;
case 2:
udelay(100);
ret = -EBUSY;
break;
case 3:
return -ENODEV;
}
}
return ret;
}
int cio_update_schib(struct subchannel *sch)
{
struct schib schib;
if (stsch_err(sch->schid, &schib) || !css_sch_is_valid(&schib))
return -ENODEV;
memcpy(&sch->schib, &schib, sizeof(schib));
return 0;
}
int cio_enable_subchannel(struct subchannel *sch, u32 intparm)
{
int retry;
int ret;
CIO_TRACE_EVENT(2, "ensch");
CIO_TRACE_EVENT(2, dev_name(&sch->dev));
if (sch_is_pseudo_sch(sch))
return -EINVAL;
if (cio_update_schib(sch))
return -ENODEV;
sch->config.ena = 1;
sch->config.isc = sch->isc;
sch->config.intparm = intparm;
for (retry = 0; retry < 3; retry++) {
ret = cio_commit_config(sch);
if (ret == -EIO) {
sch->config.csense = 0;
} else if (ret == -EBUSY) {
struct irb irb;
if (tsch(sch->schid, &irb) != 0)
break;
} else
break;
}
CIO_HEX_EVENT(2, &ret, sizeof(ret));
return ret;
}
int cio_disable_subchannel(struct subchannel *sch)
{
int retry;
int ret;
CIO_TRACE_EVENT(2, "dissch");
CIO_TRACE_EVENT(2, dev_name(&sch->dev));
if (sch_is_pseudo_sch(sch))
return 0;
if (cio_update_schib(sch))
return -ENODEV;
sch->config.ena = 0;
for (retry = 0; retry < 3; retry++) {
ret = cio_commit_config(sch);
if (ret == -EBUSY) {
struct irb irb;
if (tsch(sch->schid, &irb) != 0)
break;
} else
break;
}
CIO_HEX_EVENT(2, &ret, sizeof(ret));
return ret;
}
int cio_create_sch_lock(struct subchannel *sch)
{
sch->lock = kmalloc(sizeof(spinlock_t), GFP_KERNEL);
if (!sch->lock)
return -ENOMEM;
spin_lock_init(sch->lock);
return 0;
}
static int cio_check_devno_blacklisted(struct subchannel *sch)
{
if (is_blacklisted(sch->schid.ssid, sch->schib.pmcw.dev)) {
CIO_MSG_EVENT(6, "Blacklisted device detected "
"at devno %04X, subchannel set %x\n",
sch->schib.pmcw.dev, sch->schid.ssid);
return -ENODEV;
}
return 0;
}
static int cio_validate_io_subchannel(struct subchannel *sch)
{
if (!css_sch_is_valid(&sch->schib))
return -ENODEV;
return cio_check_devno_blacklisted(sch);
}
static int cio_validate_msg_subchannel(struct subchannel *sch)
{
if (!css_sch_is_valid(&sch->schib))
return -ENODEV;
return cio_check_devno_blacklisted(sch);
}
int cio_validate_subchannel(struct subchannel *sch, struct subchannel_id schid)
{
char dbf_txt[15];
int ccode;
int err;
sprintf(dbf_txt, "valsch%x", schid.sch_no);
CIO_TRACE_EVENT(4, dbf_txt);
memset(sch, 0, sizeof(struct subchannel));
sch->schid = schid;
if (cio_is_console(schid)) {
sch->lock = cio_get_console_lock();
} else {
err = cio_create_sch_lock(sch);
if (err)
goto out;
}
mutex_init(&sch->reg_mutex);
ccode = stsch_err (schid, &sch->schib);
if (ccode) {
err = (ccode == 3) ? -ENXIO : ccode;
goto out;
}
sch->st = sch->schib.pmcw.st;
switch (sch->st) {
case SUBCHANNEL_TYPE_IO:
err = cio_validate_io_subchannel(sch);
break;
case SUBCHANNEL_TYPE_MSG:
err = cio_validate_msg_subchannel(sch);
break;
default:
err = 0;
}
if (err)
goto out;
CIO_MSG_EVENT(4, "Subchannel 0.%x.%04x reports subchannel type %04X\n",
sch->schid.ssid, sch->schid.sch_no, sch->st);
return 0;
out:
if (!cio_is_console(schid))
kfree(sch->lock);
sch->lock = NULL;
return err;
}
void __irq_entry do_IRQ(struct pt_regs *regs)
{
struct tpi_info *tpi_info;
struct subchannel *sch;
struct irb *irb;
struct pt_regs *old_regs;
old_regs = set_irq_regs(regs);
irq_enter();
__this_cpu_write(s390_idle.nohz_delay, 1);
if (S390_lowcore.int_clock >= S390_lowcore.clock_comparator)
clock_comparator_work();
tpi_info = (struct tpi_info *)&S390_lowcore.subchannel_id;
irb = (struct irb *)&S390_lowcore.irb;
do {
kstat_cpu(smp_processor_id()).irqs[IO_INTERRUPT]++;
if (tpi_info->adapter_IO) {
do_adapter_IO(tpi_info->isc);
continue;
}
sch = (struct subchannel *)(unsigned long)tpi_info->intparm;
if (!sch) {
kstat_cpu(smp_processor_id()).irqs[IOINT_CIO]++;
tsch(tpi_info->schid, irb);
continue;
}
spin_lock(sch->lock);
if (tsch(tpi_info->schid, irb) == 0) {
memcpy (&sch->schib.scsw, &irb->scsw,
sizeof (irb->scsw));
if (sch->driver && sch->driver->irq)
sch->driver->irq(sch);
else
kstat_cpu(smp_processor_id()).irqs[IOINT_CIO]++;
} else
kstat_cpu(smp_processor_id()).irqs[IOINT_CIO]++;
spin_unlock(sch->lock);
} while (MACHINE_IS_LPAR && tpi(NULL) != 0);
irq_exit();
set_irq_regs(old_regs);
}
static void cio_tsch(struct subchannel *sch)
{
struct irb *irb;
int irq_context;
irb = (struct irb *)&S390_lowcore.irb;
if (tsch(sch->schid, irb) != 0)
return;
memcpy(&sch->schib.scsw, &irb->scsw, sizeof(union scsw));
irq_context = in_interrupt();
if (!irq_context) {
local_bh_disable();
irq_enter();
}
if (sch->driver && sch->driver->irq)
sch->driver->irq(sch);
else
kstat_cpu(smp_processor_id()).irqs[IOINT_CIO]++;
if (!irq_context) {
irq_exit();
_local_bh_enable();
}
}
void *cio_get_console_priv(void)
{
return &console_priv;
}
void wait_cons_dev(void)
{
if (!console_subchannel_in_use)
return;
while (1) {
cio_tsch(&console_subchannel);
if (console_subchannel.schib.scsw.cmd.actl == 0)
break;
udelay_simple(100);
}
}
static int
cio_test_for_console(struct subchannel_id schid, void *data)
{
if (stsch_err(schid, &console_subchannel.schib) != 0)
return -ENXIO;
if ((console_subchannel.schib.pmcw.st == SUBCHANNEL_TYPE_IO) &&
console_subchannel.schib.pmcw.dnv &&
(console_subchannel.schib.pmcw.dev == console_devno)) {
console_irq = schid.sch_no;
return 1;
}
return 0;
}
static int
cio_get_console_sch_no(void)
{
struct subchannel_id schid;
init_subchannel_id(&schid);
if (console_irq != -1) {
schid.sch_no = console_irq;
if (stsch_err(schid, &console_subchannel.schib) != 0 ||
(console_subchannel.schib.pmcw.st != SUBCHANNEL_TYPE_IO) ||
!console_subchannel.schib.pmcw.dnv)
return -1;
console_devno = console_subchannel.schib.pmcw.dev;
} else if (console_devno != -1) {
for_each_subchannel(cio_test_for_console, NULL);
if (console_irq == -1)
return -1;
} else {
return -1;
}
return console_irq;
}
struct subchannel *
cio_probe_console(void)
{
int sch_no, ret;
struct subchannel_id schid;
if (xchg(&console_subchannel_in_use, 1) != 0)
return ERR_PTR(-EBUSY);
sch_no = cio_get_console_sch_no();
if (sch_no == -1) {
console_subchannel_in_use = 0;
pr_warning("No CCW console was found\n");
return ERR_PTR(-ENODEV);
}
memset(&console_subchannel, 0, sizeof(struct subchannel));
init_subchannel_id(&schid);
schid.sch_no = sch_no;
ret = cio_validate_subchannel(&console_subchannel, schid);
if (ret) {
console_subchannel_in_use = 0;
return ERR_PTR(-ENODEV);
}
isc_register(CONSOLE_ISC);
console_subchannel.config.isc = CONSOLE_ISC;
console_subchannel.config.intparm = (u32)(addr_t)&console_subchannel;
ret = cio_commit_config(&console_subchannel);
if (ret) {
isc_unregister(CONSOLE_ISC);
console_subchannel_in_use = 0;
return ERR_PTR(ret);
}
return &console_subchannel;
}
void
cio_release_console(void)
{
console_subchannel.config.intparm = 0;
cio_commit_config(&console_subchannel);
isc_unregister(CONSOLE_ISC);
console_subchannel_in_use = 0;
}
int
cio_is_console(struct subchannel_id schid)
{
if (!console_subchannel_in_use)
return 0;
return schid_equal(&schid, &console_subchannel.schid);
}
struct subchannel *
cio_get_console_subchannel(void)
{
if (!console_subchannel_in_use)
return NULL;
return &console_subchannel;
}
static int
__disable_subchannel_easy(struct subchannel_id schid, struct schib *schib)
{
int retry, cc;
cc = 0;
for (retry=0;retry<3;retry++) {
schib->pmcw.ena = 0;
cc = msch_err(schid, schib);
if (cc)
return (cc==3?-ENODEV:-EBUSY);
if (stsch_err(schid, schib) || !css_sch_is_valid(schib))
return -ENODEV;
if (!schib->pmcw.ena)
return 0;
}
return -EBUSY;
}
static int
__clear_io_subchannel_easy(struct subchannel_id schid)
{
int retry;
if (csch(schid))
return -ENODEV;
for (retry=0;retry<20;retry++) {
struct tpi_info ti;
if (tpi(&ti)) {
tsch(ti.schid, (struct irb *)&S390_lowcore.irb);
if (schid_equal(&ti.schid, &schid))
return 0;
}
udelay_simple(100);
}
return -EBUSY;
}
static void __clear_chsc_subchannel_easy(void)
{
udelay_simple(100);
}
static void cio_reset_pgm_check_handler(void)
{
pgm_check_occured = 1;
}
static int stsch_reset(struct subchannel_id schid, struct schib *addr)
{
int rc;
pgm_check_occured = 0;
s390_base_pgm_handler_fn = cio_reset_pgm_check_handler;
rc = stsch_err(schid, addr);
s390_base_pgm_handler_fn = NULL;
barrier();
if (pgm_check_occured)
return -EIO;
else
return rc;
}
static int __shutdown_subchannel_easy(struct subchannel_id schid, void *data)
{
struct schib schib;
if (stsch_reset(schid, &schib))
return -ENXIO;
if (!schib.pmcw.ena)
return 0;
switch(__disable_subchannel_easy(schid, &schib)) {
case 0:
case -ENODEV:
break;
default:
switch (schib.pmcw.st) {
case SUBCHANNEL_TYPE_IO:
if (__clear_io_subchannel_easy(schid))
goto out;
break;
case SUBCHANNEL_TYPE_CHSC:
__clear_chsc_subchannel_easy();
break;
default:
break;
}
stsch_err(schid, &schib);
__disable_subchannel_easy(schid, &schib);
}
out:
return 0;
}
static void s390_reset_chpids_mcck_handler(void)
{
struct crw crw;
struct mci *mci;
mci = (struct mci *)&S390_lowcore.mcck_interruption_code;
if (!mci->cp)
return;
while (stcrw(&crw) == 0) {
if (crw.slct && crw.rsc == CRW_RSC_CPATH)
atomic_dec(&chpid_reset_count);
}
}
static void css_reset(void)
{
int i, ret;
unsigned long long timeout;
struct chp_id chpid;
for_each_subchannel(__shutdown_subchannel_easy, NULL);
s390_base_mcck_handler_fn = s390_reset_chpids_mcck_handler;
__ctl_set_bit(14, 28);
local_mcck_enable();
chp_id_init(&chpid);
for (i = 0; i <= __MAX_CHPID; i++) {
chpid.id = i;
ret = rchp(chpid);
if ((ret == 0) || (ret == 2))
atomic_inc(&chpid_reset_count);
}
timeout = get_clock() + (RCHP_TIMEOUT << 12);
while (atomic_read(&chpid_reset_count) != 0) {
if (get_clock() > timeout)
break;
cpu_relax();
}
local_mcck_disable();
__ctl_clear_bit(14, 28);
s390_base_mcck_handler_fn = NULL;
}
static int __init init_css_reset_call(void)
{
atomic_set(&chpid_reset_count, 0);
register_reset_call(&css_reset_call);
return 0;
}
static int __reipl_subchannel_match(struct subchannel_id schid, void *data)
{
struct schib schib;
struct sch_match_id *match_id = data;
if (stsch_reset(schid, &schib))
return -ENXIO;
if ((schib.pmcw.st == SUBCHANNEL_TYPE_IO) && schib.pmcw.dnv &&
(schib.pmcw.dev == match_id->devid.devno) &&
(schid.ssid == match_id->devid.ssid)) {
match_id->schid = schid;
match_id->rc = 0;
return 1;
}
return 0;
}
static int reipl_find_schid(struct ccw_dev_id *devid,
struct subchannel_id *schid)
{
struct sch_match_id match_id;
match_id.devid = *devid;
match_id.rc = -ENODEV;
for_each_subchannel(__reipl_subchannel_match, &match_id);
if (match_id.rc == 0)
*schid = match_id.schid;
return match_id.rc;
}
void reipl_ccw_dev(struct ccw_dev_id *devid)
{
struct subchannel_id uninitialized_var(schid);
s390_reset_system(NULL, NULL);
if (reipl_find_schid(devid, &schid) != 0)
panic("IPL Device not found\n");
do_reipl_asm(*((__u32*)&schid));
}
int __init cio_get_iplinfo(struct cio_iplinfo *iplinfo)
{
struct subchannel_id schid;
struct schib schib;
schid = *(struct subchannel_id *)&S390_lowcore.subchannel_id;
if (!schid.one)
return -ENODEV;
if (stsch_err(schid, &schib))
return -ENODEV;
if (schib.pmcw.st != SUBCHANNEL_TYPE_IO)
return -ENODEV;
if (!schib.pmcw.dnv)
return -ENODEV;
iplinfo->devno = schib.pmcw.dev;
iplinfo->is_qdio = schib.pmcw.qf;
return 0;
}
int cio_tm_start_key(struct subchannel *sch, struct tcw *tcw, u8 lpm, u8 key)
{
int cc;
union orb *orb = &to_io_private(sch)->orb;
memset(orb, 0, sizeof(union orb));
orb->tm.intparm = (u32) (addr_t) sch;
orb->tm.key = key >> 4;
orb->tm.b = 1;
orb->tm.lpm = lpm ? lpm : sch->lpm;
orb->tm.tcw = (u32) (addr_t) tcw;
cc = ssch(sch->schid, orb);
switch (cc) {
case 0:
return 0;
case 1:
case 2:
return -EBUSY;
default:
return cio_start_handle_notoper(sch, lpm);
}
}
int cio_tm_intrg(struct subchannel *sch)
{
int cc;
if (!to_io_private(sch)->orb.tm.b)
return -EINVAL;
cc = xsch(sch->schid);
switch (cc) {
case 0:
case 2:
return 0;
case 1:
return -EBUSY;
default:
return -ENODEV;
}
}
