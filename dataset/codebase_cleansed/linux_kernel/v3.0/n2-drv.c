static int n2rng_hv_err_trans(unsigned long hv_err)
{
switch (hv_err) {
case HV_EOK:
return 0;
case HV_EWOULDBLOCK:
return -EAGAIN;
case HV_ENOACCESS:
return -EPERM;
case HV_EIO:
return -EIO;
case HV_EBUSY:
return -EBUSY;
case HV_EBADALIGN:
case HV_ENORADDR:
return -EFAULT;
default:
return -EINVAL;
}
}
static unsigned long n2rng_generic_read_control_v2(unsigned long ra,
unsigned long unit)
{
unsigned long hv_err, state, ticks, watchdog_delta, watchdog_status;
int block = 0, busy = 0;
while (1) {
hv_err = sun4v_rng_ctl_read_v2(ra, unit, &state,
&ticks,
&watchdog_delta,
&watchdog_status);
if (hv_err == HV_EOK)
break;
if (hv_err == HV_EBUSY) {
if (++busy >= N2RNG_BUSY_LIMIT)
break;
udelay(1);
} else if (hv_err == HV_EWOULDBLOCK) {
if (++block >= N2RNG_BLOCK_LIMIT)
break;
__delay(ticks);
} else
break;
}
return hv_err;
}
static unsigned long n2rng_control_settle_v2(struct n2rng *np, int unit)
{
unsigned long ra = __pa(&np->scratch_control[0]);
return n2rng_generic_read_control_v2(ra, unit);
}
static unsigned long n2rng_write_ctl_one(struct n2rng *np, int unit,
unsigned long state,
unsigned long control_ra,
unsigned long watchdog_timeout,
unsigned long *ticks)
{
unsigned long hv_err;
if (np->hvapi_major == 1) {
hv_err = sun4v_rng_ctl_write_v1(control_ra, state,
watchdog_timeout, ticks);
} else {
hv_err = sun4v_rng_ctl_write_v2(control_ra, state,
watchdog_timeout, unit);
if (hv_err == HV_EOK)
hv_err = n2rng_control_settle_v2(np, unit);
*ticks = N2RNG_ACCUM_CYCLES_DEFAULT;
}
return hv_err;
}
static int n2rng_generic_read_data(unsigned long data_ra)
{
unsigned long ticks, hv_err;
int block = 0, hcheck = 0;
while (1) {
hv_err = sun4v_rng_data_read(data_ra, &ticks);
if (hv_err == HV_EOK)
return 0;
if (hv_err == HV_EWOULDBLOCK) {
if (++block >= N2RNG_BLOCK_LIMIT)
return -EWOULDBLOCK;
__delay(ticks);
} else if (hv_err == HV_ENOACCESS) {
return -EPERM;
} else if (hv_err == HV_EIO) {
if (++hcheck >= N2RNG_HCHECK_LIMIT)
return -EIO;
udelay(10000);
} else
return -ENODEV;
}
}
static unsigned long n2rng_read_diag_data_one(struct n2rng *np,
unsigned long unit,
unsigned long data_ra,
unsigned long data_len,
unsigned long *ticks)
{
unsigned long hv_err;
if (np->hvapi_major == 1) {
hv_err = sun4v_rng_data_read_diag_v1(data_ra, data_len, ticks);
} else {
hv_err = sun4v_rng_data_read_diag_v2(data_ra, data_len,
unit, ticks);
if (!*ticks)
*ticks = N2RNG_ACCUM_CYCLES_DEFAULT;
}
return hv_err;
}
static int n2rng_generic_read_diag_data(struct n2rng *np,
unsigned long unit,
unsigned long data_ra,
unsigned long data_len)
{
unsigned long ticks, hv_err;
int block = 0;
while (1) {
hv_err = n2rng_read_diag_data_one(np, unit,
data_ra, data_len,
&ticks);
if (hv_err == HV_EOK)
return 0;
if (hv_err == HV_EWOULDBLOCK) {
if (++block >= N2RNG_BLOCK_LIMIT)
return -EWOULDBLOCK;
__delay(ticks);
} else if (hv_err == HV_ENOACCESS) {
return -EPERM;
} else if (hv_err == HV_EIO) {
return -EIO;
} else
return -ENODEV;
}
}
static int n2rng_generic_write_control(struct n2rng *np,
unsigned long control_ra,
unsigned long unit,
unsigned long state)
{
unsigned long hv_err, ticks;
int block = 0, busy = 0;
while (1) {
hv_err = n2rng_write_ctl_one(np, unit, state, control_ra,
np->wd_timeo, &ticks);
if (hv_err == HV_EOK)
return 0;
if (hv_err == HV_EWOULDBLOCK) {
if (++block >= N2RNG_BLOCK_LIMIT)
return -EWOULDBLOCK;
__delay(ticks);
} else if (hv_err == HV_EBUSY) {
if (++busy >= N2RNG_BUSY_LIMIT)
return -EBUSY;
udelay(1);
} else
return -ENODEV;
}
}
static int n2rng_try_read_ctl(struct n2rng *np)
{
unsigned long hv_err;
unsigned long x;
if (np->hvapi_major == 1) {
hv_err = sun4v_rng_get_diag_ctl();
} else {
hv_err = sun4v_rng_ctl_read_v2(0UL, ~0UL, &x, &x, &x, &x);
switch (hv_err) {
case HV_EWOULDBLOCK:
case HV_ENOACCESS:
break;
default:
hv_err = HV_EOK;
break;
}
}
return n2rng_hv_err_trans(hv_err);
}
static void n2rng_control_swstate_init(struct n2rng *np)
{
int i;
np->flags |= N2RNG_FLAG_CONTROL;
np->health_check_sec = N2RNG_HEALTH_CHECK_SEC_DEFAULT;
np->accum_cycles = N2RNG_ACCUM_CYCLES_DEFAULT;
np->wd_timeo = N2RNG_WD_TIMEO_DEFAULT;
for (i = 0; i < np->num_units; i++) {
struct n2rng_unit *up = &np->units[i];
up->control[0] = CONTROL_DEFAULT_0;
up->control[1] = CONTROL_DEFAULT_1;
up->control[2] = CONTROL_DEFAULT_2;
up->control[3] = CONTROL_DEFAULT_3;
}
np->hv_state = HV_RNG_STATE_UNCONFIGURED;
}
static int n2rng_grab_diag_control(struct n2rng *np)
{
int i, busy_count, err = -ENODEV;
busy_count = 0;
for (i = 0; i < 100; i++) {
err = n2rng_try_read_ctl(np);
if (err != -EAGAIN)
break;
if (++busy_count > 100) {
dev_err(&np->op->dev,
"Grab diag control timeout.\n");
return -ENODEV;
}
udelay(1);
}
return err;
}
static int n2rng_init_control(struct n2rng *np)
{
int err = n2rng_grab_diag_control(np);
if (err == -EPERM)
return 0;
if (err)
return err;
n2rng_control_swstate_init(np);
return 0;
}
static int n2rng_data_read(struct hwrng *rng, u32 *data)
{
struct n2rng *np = (struct n2rng *) rng->priv;
unsigned long ra = __pa(&np->test_data);
int len;
if (!(np->flags & N2RNG_FLAG_READY)) {
len = 0;
} else if (np->flags & N2RNG_FLAG_BUFFER_VALID) {
np->flags &= ~N2RNG_FLAG_BUFFER_VALID;
*data = np->buffer;
len = 4;
} else {
int err = n2rng_generic_read_data(ra);
if (!err) {
np->buffer = np->test_data >> 32;
*data = np->test_data & 0xffffffff;
len = 4;
} else {
dev_err(&np->op->dev, "RNG error, restesting\n");
np->flags &= ~N2RNG_FLAG_READY;
if (!(np->flags & N2RNG_FLAG_SHUTDOWN))
schedule_delayed_work(&np->work, 0);
len = 0;
}
}
return len;
}
static int n2rng_guest_check(struct n2rng *np)
{
unsigned long ra = __pa(&np->test_data);
return n2rng_generic_read_data(ra);
}
static int n2rng_entropy_diag_read(struct n2rng *np, unsigned long unit,
u64 *pre_control, u64 pre_state,
u64 *buffer, unsigned long buf_len,
u64 *post_control, u64 post_state)
{
unsigned long post_ctl_ra = __pa(post_control);
unsigned long pre_ctl_ra = __pa(pre_control);
unsigned long buffer_ra = __pa(buffer);
int err;
err = n2rng_generic_write_control(np, pre_ctl_ra, unit, pre_state);
if (err)
return err;
err = n2rng_generic_read_diag_data(np, unit,
buffer_ra, buf_len);
(void) n2rng_generic_write_control(np, post_ctl_ra, unit,
post_state);
return err;
}
static u64 advance_polynomial(u64 poly, u64 val, int count)
{
int i;
for (i = 0; i < count; i++) {
int highbit_set = ((s64)val < 0);
val <<= 1;
if (highbit_set)
val ^= poly;
}
return val;
}
static int n2rng_test_buffer_find(struct n2rng *np, u64 val)
{
int i, count = 0;
for (i = 1; i < SELFTEST_BUFFER_WORDS; i++) {
if (np->test_buffer[i] == val)
count++;
}
return count;
}
static void n2rng_dump_test_buffer(struct n2rng *np)
{
int i;
for (i = 0; i < SELFTEST_BUFFER_WORDS; i++)
dev_err(&np->op->dev, "Test buffer slot %d [0x%016llx]\n",
i, np->test_buffer[i]);
}
static int n2rng_check_selftest_buffer(struct n2rng *np, unsigned long unit)
{
u64 val = SELFTEST_VAL;
int err, matches, limit;
matches = 0;
for (limit = 0; limit < SELFTEST_LOOPS_MAX; limit++) {
matches += n2rng_test_buffer_find(np, val);
if (matches >= SELFTEST_MATCH_GOAL)
break;
val = advance_polynomial(SELFTEST_POLY, val, 1);
}
err = 0;
if (limit >= SELFTEST_LOOPS_MAX) {
err = -ENODEV;
dev_err(&np->op->dev, "Selftest failed on unit %lu\n", unit);
n2rng_dump_test_buffer(np);
} else
dev_info(&np->op->dev, "Selftest passed on unit %lu\n", unit);
return err;
}
static int n2rng_control_selftest(struct n2rng *np, unsigned long unit)
{
int err;
np->test_control[0] = (0x2 << RNG_CTL_ASEL_SHIFT);
np->test_control[1] = (0x2 << RNG_CTL_ASEL_SHIFT);
np->test_control[2] = (0x2 << RNG_CTL_ASEL_SHIFT);
np->test_control[3] = ((0x2 << RNG_CTL_ASEL_SHIFT) |
RNG_CTL_LFSR |
((SELFTEST_TICKS - 2) << RNG_CTL_WAIT_SHIFT));
err = n2rng_entropy_diag_read(np, unit, np->test_control,
HV_RNG_STATE_HEALTHCHECK,
np->test_buffer,
sizeof(np->test_buffer),
&np->units[unit].control[0],
np->hv_state);
if (err)
return err;
return n2rng_check_selftest_buffer(np, unit);
}
static int n2rng_control_check(struct n2rng *np)
{
int i;
for (i = 0; i < np->num_units; i++) {
int err = n2rng_control_selftest(np, i);
if (err)
return err;
}
return 0;
}
static int n2rng_control_configure_units(struct n2rng *np)
{
int unit, err;
err = 0;
for (unit = 0; unit < np->num_units; unit++) {
struct n2rng_unit *up = &np->units[unit];
unsigned long ctl_ra = __pa(&up->control[0]);
int esrc;
u64 base;
base = ((np->accum_cycles << RNG_CTL_WAIT_SHIFT) |
(2 << RNG_CTL_ASEL_SHIFT) |
RNG_CTL_LFSR);
for (esrc = 0; esrc < 3; esrc++)
up->control[esrc] = base |
(esrc << RNG_CTL_VCO_SHIFT) |
(RNG_CTL_ES1 << esrc);
up->control[3] = base |
(RNG_CTL_ES1 | RNG_CTL_ES2 | RNG_CTL_ES3);
err = n2rng_generic_write_control(np, ctl_ra, unit,
HV_RNG_STATE_CONFIGURED);
if (err)
break;
}
return err;
}
static void n2rng_work(struct work_struct *work)
{
struct n2rng *np = container_of(work, struct n2rng, work.work);
int err = 0;
if (!(np->flags & N2RNG_FLAG_CONTROL)) {
err = n2rng_guest_check(np);
} else {
preempt_disable();
err = n2rng_control_check(np);
preempt_enable();
if (!err)
err = n2rng_control_configure_units(np);
}
if (!err) {
np->flags |= N2RNG_FLAG_READY;
dev_info(&np->op->dev, "RNG ready\n");
}
if (err && !(np->flags & N2RNG_FLAG_SHUTDOWN))
schedule_delayed_work(&np->work, HZ * 2);
}
static void __devinit n2rng_driver_version(void)
{
static int n2rng_version_printed;
if (n2rng_version_printed++ == 0)
pr_info("%s", version);
}
static int __devinit n2rng_probe(struct platform_device *op)
{
const struct of_device_id *match;
int victoria_falls;
int err = -ENOMEM;
struct n2rng *np;
match = of_match_device(n2rng_match, &op->dev);
if (!match)
return -EINVAL;
victoria_falls = (match->data != NULL);
n2rng_driver_version();
np = kzalloc(sizeof(*np), GFP_KERNEL);
if (!np)
goto out;
np->op = op;
INIT_DELAYED_WORK(&np->work, n2rng_work);
if (victoria_falls)
np->flags |= N2RNG_FLAG_VF;
err = -ENODEV;
np->hvapi_major = 2;
if (sun4v_hvapi_register(HV_GRP_RNG,
np->hvapi_major,
&np->hvapi_minor)) {
np->hvapi_major = 1;
if (sun4v_hvapi_register(HV_GRP_RNG,
np->hvapi_major,
&np->hvapi_minor)) {
dev_err(&op->dev, "Cannot register suitable "
"HVAPI version.\n");
goto out_free;
}
}
if (np->flags & N2RNG_FLAG_VF) {
if (np->hvapi_major < 2) {
dev_err(&op->dev, "VF RNG requires HVAPI major "
"version 2 or later, got %lu\n",
np->hvapi_major);
goto out_hvapi_unregister;
}
np->num_units = of_getintprop_default(op->dev.of_node,
"rng-#units", 0);
if (!np->num_units) {
dev_err(&op->dev, "VF RNG lacks rng-#units property\n");
goto out_hvapi_unregister;
}
} else
np->num_units = 1;
dev_info(&op->dev, "Registered RNG HVAPI major %lu minor %lu\n",
np->hvapi_major, np->hvapi_minor);
np->units = kzalloc(sizeof(struct n2rng_unit) * np->num_units,
GFP_KERNEL);
err = -ENOMEM;
if (!np->units)
goto out_hvapi_unregister;
err = n2rng_init_control(np);
if (err)
goto out_free_units;
dev_info(&op->dev, "Found %s RNG, units: %d\n",
((np->flags & N2RNG_FLAG_VF) ?
"Victoria Falls" : "Niagara2"),
np->num_units);
np->hwrng.name = "n2rng";
np->hwrng.data_read = n2rng_data_read;
np->hwrng.priv = (unsigned long) np;
err = hwrng_register(&np->hwrng);
if (err)
goto out_free_units;
dev_set_drvdata(&op->dev, np);
schedule_delayed_work(&np->work, 0);
return 0;
out_free_units:
kfree(np->units);
np->units = NULL;
out_hvapi_unregister:
sun4v_hvapi_unregister(HV_GRP_RNG);
out_free:
kfree(np);
out:
return err;
}
static int __devexit n2rng_remove(struct platform_device *op)
{
struct n2rng *np = dev_get_drvdata(&op->dev);
np->flags |= N2RNG_FLAG_SHUTDOWN;
cancel_delayed_work_sync(&np->work);
hwrng_unregister(&np->hwrng);
sun4v_hvapi_unregister(HV_GRP_RNG);
kfree(np->units);
np->units = NULL;
kfree(np);
dev_set_drvdata(&op->dev, NULL);
return 0;
}
static int __init n2rng_init(void)
{
return platform_driver_register(&n2rng_driver);
}
static void __exit n2rng_exit(void)
{
platform_driver_unregister(&n2rng_driver);
}
