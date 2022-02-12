static int has_hid(struct acpi_device *dev, const char *hid)
{
struct acpi_hardware_id *id;
list_for_each_entry(id, &dev->pnp.ids, list)
if (!strcmp(hid, id->id))
return 1;
return 0;
}
static inline int is_itpm(struct acpi_device *dev)
{
return has_hid(dev, "INTC0102");
}
static inline int is_itpm(struct acpi_device *dev)
{
return 0;
}
static int wait_startup(struct tpm_chip *chip, int l)
{
unsigned long stop = jiffies + chip->vendor.timeout_a;
do {
if (ioread8(chip->vendor.iobase + TPM_ACCESS(l)) &
TPM_ACCESS_VALID)
return 0;
msleep(TPM_TIMEOUT);
} while (time_before(jiffies, stop));
return -1;
}
static int check_locality(struct tpm_chip *chip, int l)
{
if ((ioread8(chip->vendor.iobase + TPM_ACCESS(l)) &
(TPM_ACCESS_ACTIVE_LOCALITY | TPM_ACCESS_VALID)) ==
(TPM_ACCESS_ACTIVE_LOCALITY | TPM_ACCESS_VALID))
return chip->vendor.locality = l;
return -1;
}
static void release_locality(struct tpm_chip *chip, int l, int force)
{
if (force || (ioread8(chip->vendor.iobase + TPM_ACCESS(l)) &
(TPM_ACCESS_REQUEST_PENDING | TPM_ACCESS_VALID)) ==
(TPM_ACCESS_REQUEST_PENDING | TPM_ACCESS_VALID))
iowrite8(TPM_ACCESS_ACTIVE_LOCALITY,
chip->vendor.iobase + TPM_ACCESS(l));
}
static int request_locality(struct tpm_chip *chip, int l)
{
unsigned long stop, timeout;
long rc;
if (check_locality(chip, l) >= 0)
return l;
iowrite8(TPM_ACCESS_REQUEST_USE,
chip->vendor.iobase + TPM_ACCESS(l));
stop = jiffies + chip->vendor.timeout_a;
if (chip->vendor.irq) {
again:
timeout = stop - jiffies;
if ((long)timeout <= 0)
return -1;
rc = wait_event_interruptible_timeout(chip->vendor.int_queue,
(check_locality
(chip, l) >= 0),
timeout);
if (rc > 0)
return l;
if (rc == -ERESTARTSYS && freezing(current)) {
clear_thread_flag(TIF_SIGPENDING);
goto again;
}
} else {
do {
if (check_locality(chip, l) >= 0)
return l;
msleep(TPM_TIMEOUT);
}
while (time_before(jiffies, stop));
}
return -1;
}
static u8 tpm_tis_status(struct tpm_chip *chip)
{
return ioread8(chip->vendor.iobase +
TPM_STS(chip->vendor.locality));
}
static void tpm_tis_ready(struct tpm_chip *chip)
{
iowrite8(TPM_STS_COMMAND_READY,
chip->vendor.iobase + TPM_STS(chip->vendor.locality));
}
static int get_burstcount(struct tpm_chip *chip)
{
unsigned long stop;
int burstcnt;
stop = jiffies + chip->vendor.timeout_d;
do {
burstcnt = ioread8(chip->vendor.iobase +
TPM_STS(chip->vendor.locality) + 1);
burstcnt += ioread8(chip->vendor.iobase +
TPM_STS(chip->vendor.locality) +
2) << 8;
if (burstcnt)
return burstcnt;
msleep(TPM_TIMEOUT);
} while (time_before(jiffies, stop));
return -EBUSY;
}
static int recv_data(struct tpm_chip *chip, u8 *buf, size_t count)
{
int size = 0, burstcnt;
while (size < count &&
wait_for_tpm_stat(chip,
TPM_STS_DATA_AVAIL | TPM_STS_VALID,
chip->vendor.timeout_c,
&chip->vendor.read_queue, true)
== 0) {
burstcnt = get_burstcount(chip);
for (; burstcnt > 0 && size < count; burstcnt--)
buf[size++] = ioread8(chip->vendor.iobase +
TPM_DATA_FIFO(chip->vendor.
locality));
}
return size;
}
static int tpm_tis_recv(struct tpm_chip *chip, u8 *buf, size_t count)
{
int size = 0;
int expected, status;
if (count < TPM_HEADER_SIZE) {
size = -EIO;
goto out;
}
if ((size =
recv_data(chip, buf, TPM_HEADER_SIZE)) < TPM_HEADER_SIZE) {
dev_err(chip->pdev, "Unable to read header\n");
goto out;
}
expected = be32_to_cpu(*(__be32 *) (buf + 2));
if (expected > count) {
size = -EIO;
goto out;
}
if ((size +=
recv_data(chip, &buf[TPM_HEADER_SIZE],
expected - TPM_HEADER_SIZE)) < expected) {
dev_err(chip->pdev, "Unable to read remainder of result\n");
size = -ETIME;
goto out;
}
wait_for_tpm_stat(chip, TPM_STS_VALID, chip->vendor.timeout_c,
&chip->vendor.int_queue, false);
status = tpm_tis_status(chip);
if (status & TPM_STS_DATA_AVAIL) {
dev_err(chip->pdev, "Error left over data\n");
size = -EIO;
goto out;
}
out:
tpm_tis_ready(chip);
release_locality(chip, chip->vendor.locality, 0);
return size;
}
static int tpm_tis_send_data(struct tpm_chip *chip, u8 *buf, size_t len)
{
int rc, status, burstcnt;
size_t count = 0;
if (request_locality(chip, 0) < 0)
return -EBUSY;
status = tpm_tis_status(chip);
if ((status & TPM_STS_COMMAND_READY) == 0) {
tpm_tis_ready(chip);
if (wait_for_tpm_stat
(chip, TPM_STS_COMMAND_READY, chip->vendor.timeout_b,
&chip->vendor.int_queue, false) < 0) {
rc = -ETIME;
goto out_err;
}
}
while (count < len - 1) {
burstcnt = get_burstcount(chip);
for (; burstcnt > 0 && count < len - 1; burstcnt--) {
iowrite8(buf[count], chip->vendor.iobase +
TPM_DATA_FIFO(chip->vendor.locality));
count++;
}
wait_for_tpm_stat(chip, TPM_STS_VALID, chip->vendor.timeout_c,
&chip->vendor.int_queue, false);
status = tpm_tis_status(chip);
if (!itpm && (status & TPM_STS_DATA_EXPECT) == 0) {
rc = -EIO;
goto out_err;
}
}
iowrite8(buf[count],
chip->vendor.iobase + TPM_DATA_FIFO(chip->vendor.locality));
wait_for_tpm_stat(chip, TPM_STS_VALID, chip->vendor.timeout_c,
&chip->vendor.int_queue, false);
status = tpm_tis_status(chip);
if ((status & TPM_STS_DATA_EXPECT) != 0) {
rc = -EIO;
goto out_err;
}
return 0;
out_err:
tpm_tis_ready(chip);
release_locality(chip, chip->vendor.locality, 0);
return rc;
}
static void disable_interrupts(struct tpm_chip *chip)
{
u32 intmask;
intmask =
ioread32(chip->vendor.iobase +
TPM_INT_ENABLE(chip->vendor.locality));
intmask &= ~TPM_GLOBAL_INT_ENABLE;
iowrite32(intmask,
chip->vendor.iobase +
TPM_INT_ENABLE(chip->vendor.locality));
devm_free_irq(chip->pdev, chip->vendor.irq, chip);
chip->vendor.irq = 0;
}
static int tpm_tis_send_main(struct tpm_chip *chip, u8 *buf, size_t len)
{
int rc;
u32 ordinal;
unsigned long dur;
rc = tpm_tis_send_data(chip, buf, len);
if (rc < 0)
return rc;
iowrite8(TPM_STS_GO,
chip->vendor.iobase + TPM_STS(chip->vendor.locality));
if (chip->vendor.irq) {
ordinal = be32_to_cpu(*((__be32 *) (buf + 6)));
if (chip->flags & TPM_CHIP_FLAG_TPM2)
dur = tpm2_calc_ordinal_duration(chip, ordinal);
else
dur = tpm_calc_ordinal_duration(chip, ordinal);
if (wait_for_tpm_stat
(chip, TPM_STS_DATA_AVAIL | TPM_STS_VALID, dur,
&chip->vendor.read_queue, false) < 0) {
rc = -ETIME;
goto out_err;
}
}
return len;
out_err:
tpm_tis_ready(chip);
release_locality(chip, chip->vendor.locality, 0);
return rc;
}
static int tpm_tis_send(struct tpm_chip *chip, u8 *buf, size_t len)
{
int rc, irq;
struct priv_data *priv = chip->vendor.priv;
if (!chip->vendor.irq || priv->irq_tested)
return tpm_tis_send_main(chip, buf, len);
irq = chip->vendor.irq;
chip->vendor.irq = 0;
rc = tpm_tis_send_main(chip, buf, len);
chip->vendor.irq = irq;
if (!priv->irq_tested)
msleep(1);
if (!priv->irq_tested)
disable_interrupts(chip);
priv->irq_tested = true;
return rc;
}
static bool tpm_tis_update_timeouts(struct tpm_chip *chip,
unsigned long *timeout_cap)
{
int i;
u32 did_vid;
did_vid = ioread32(chip->vendor.iobase + TPM_DID_VID(0));
for (i = 0; i != ARRAY_SIZE(vendor_timeout_overrides); i++) {
if (vendor_timeout_overrides[i].did_vid != did_vid)
continue;
memcpy(timeout_cap, vendor_timeout_overrides[i].timeout_us,
sizeof(vendor_timeout_overrides[i].timeout_us));
return true;
}
return false;
}
static int probe_itpm(struct tpm_chip *chip)
{
int rc = 0;
u8 cmd_getticks[] = {
0x00, 0xc1, 0x00, 0x00, 0x00, 0x0a,
0x00, 0x00, 0x00, 0xf1
};
size_t len = sizeof(cmd_getticks);
bool rem_itpm = itpm;
u16 vendor = ioread16(chip->vendor.iobase + TPM_DID_VID(0));
if (vendor != TPM_VID_INTEL)
return 0;
itpm = false;
rc = tpm_tis_send_data(chip, cmd_getticks, len);
if (rc == 0)
goto out;
tpm_tis_ready(chip);
release_locality(chip, chip->vendor.locality, 0);
itpm = true;
rc = tpm_tis_send_data(chip, cmd_getticks, len);
if (rc == 0) {
dev_info(chip->pdev, "Detected an iTPM.\n");
rc = 1;
} else
rc = -EFAULT;
out:
itpm = rem_itpm;
tpm_tis_ready(chip);
release_locality(chip, chip->vendor.locality, 0);
return rc;
}
static bool tpm_tis_req_canceled(struct tpm_chip *chip, u8 status)
{
switch (chip->vendor.manufacturer_id) {
case TPM_VID_WINBOND:
return ((status == TPM_STS_VALID) ||
(status == (TPM_STS_VALID | TPM_STS_COMMAND_READY)));
case TPM_VID_STM:
return (status == (TPM_STS_VALID | TPM_STS_COMMAND_READY));
default:
return (status == TPM_STS_COMMAND_READY);
}
}
static irqreturn_t tis_int_handler(int dummy, void *dev_id)
{
struct tpm_chip *chip = dev_id;
u32 interrupt;
int i;
interrupt = ioread32(chip->vendor.iobase +
TPM_INT_STATUS(chip->vendor.locality));
if (interrupt == 0)
return IRQ_NONE;
((struct priv_data *)chip->vendor.priv)->irq_tested = true;
if (interrupt & TPM_INTF_DATA_AVAIL_INT)
wake_up_interruptible(&chip->vendor.read_queue);
if (interrupt & TPM_INTF_LOCALITY_CHANGE_INT)
for (i = 0; i < 5; i++)
if (check_locality(chip, i) >= 0)
break;
if (interrupt &
(TPM_INTF_LOCALITY_CHANGE_INT | TPM_INTF_STS_VALID_INT |
TPM_INTF_CMD_READY_INT))
wake_up_interruptible(&chip->vendor.int_queue);
iowrite32(interrupt,
chip->vendor.iobase +
TPM_INT_STATUS(chip->vendor.locality));
ioread32(chip->vendor.iobase + TPM_INT_STATUS(chip->vendor.locality));
return IRQ_HANDLED;
}
static int tpm_tis_probe_irq_single(struct tpm_chip *chip, u32 intmask,
int flags, int irq)
{
struct priv_data *priv = chip->vendor.priv;
u8 original_int_vec;
if (devm_request_irq(chip->pdev, irq, tis_int_handler, flags,
chip->devname, chip) != 0) {
dev_info(chip->pdev, "Unable to request irq: %d for probe\n",
irq);
return -1;
}
chip->vendor.irq = irq;
original_int_vec = ioread8(chip->vendor.iobase +
TPM_INT_VECTOR(chip->vendor.locality));
iowrite8(irq,
chip->vendor.iobase + TPM_INT_VECTOR(chip->vendor.locality));
iowrite32(ioread32(chip->vendor.iobase +
TPM_INT_STATUS(chip->vendor.locality)),
chip->vendor.iobase + TPM_INT_STATUS(chip->vendor.locality));
iowrite32(intmask | TPM_GLOBAL_INT_ENABLE,
chip->vendor.iobase + TPM_INT_ENABLE(chip->vendor.locality));
priv->irq_tested = false;
if (chip->flags & TPM_CHIP_FLAG_TPM2)
tpm2_gen_interrupt(chip);
else
tpm_gen_interrupt(chip);
if (!chip->vendor.irq) {
iowrite8(original_int_vec,
chip->vendor.iobase +
TPM_INT_VECTOR(chip->vendor.locality));
return 1;
}
return 0;
}
static void tpm_tis_probe_irq(struct tpm_chip *chip, u32 intmask)
{
u8 original_int_vec;
int i;
original_int_vec = ioread8(chip->vendor.iobase +
TPM_INT_VECTOR(chip->vendor.locality));
if (!original_int_vec) {
if (IS_ENABLED(CONFIG_X86))
for (i = 3; i <= 15; i++)
if (!tpm_tis_probe_irq_single(chip, intmask, 0,
i))
return;
} else if (!tpm_tis_probe_irq_single(chip, intmask, 0,
original_int_vec))
return;
}
static void tpm_tis_remove(struct tpm_chip *chip)
{
if (chip->flags & TPM_CHIP_FLAG_TPM2)
tpm2_shutdown(chip, TPM2_SU_CLEAR);
iowrite32(~TPM_GLOBAL_INT_ENABLE &
ioread32(chip->vendor.iobase +
TPM_INT_ENABLE(chip->vendor.
locality)),
chip->vendor.iobase +
TPM_INT_ENABLE(chip->vendor.locality));
release_locality(chip, chip->vendor.locality, 1);
}
static int tpm_tis_init(struct device *dev, struct tpm_info *tpm_info,
acpi_handle acpi_dev_handle)
{
u32 vendor, intfcaps, intmask;
int rc, probe;
struct tpm_chip *chip;
struct priv_data *priv;
priv = devm_kzalloc(dev, sizeof(struct priv_data), GFP_KERNEL);
if (priv == NULL)
return -ENOMEM;
chip = tpmm_chip_alloc(dev, &tpm_tis);
if (IS_ERR(chip))
return PTR_ERR(chip);
chip->vendor.priv = priv;
#ifdef CONFIG_ACPI
chip->acpi_dev_handle = acpi_dev_handle;
#endif
chip->vendor.iobase = devm_ioremap_resource(dev, &tpm_info->res);
if (IS_ERR(chip->vendor.iobase))
return PTR_ERR(chip->vendor.iobase);
chip->vendor.timeout_a = TIS_TIMEOUT_A_MAX;
chip->vendor.timeout_b = TIS_TIMEOUT_B_MAX;
chip->vendor.timeout_c = TIS_TIMEOUT_C_MAX;
chip->vendor.timeout_d = TIS_TIMEOUT_D_MAX;
if (wait_startup(chip, 0) != 0) {
rc = -ENODEV;
goto out_err;
}
intmask = ioread32(chip->vendor.iobase +
TPM_INT_ENABLE(chip->vendor.locality));
intmask |= TPM_INTF_CMD_READY_INT | TPM_INTF_LOCALITY_CHANGE_INT |
TPM_INTF_DATA_AVAIL_INT | TPM_INTF_STS_VALID_INT;
intmask &= ~TPM_GLOBAL_INT_ENABLE;
iowrite32(intmask,
chip->vendor.iobase + TPM_INT_ENABLE(chip->vendor.locality));
if (request_locality(chip, 0) != 0) {
rc = -ENODEV;
goto out_err;
}
rc = tpm2_probe(chip);
if (rc)
goto out_err;
vendor = ioread32(chip->vendor.iobase + TPM_DID_VID(0));
chip->vendor.manufacturer_id = vendor;
dev_info(dev, "%s TPM (device-id 0x%X, rev-id %d)\n",
(chip->flags & TPM_CHIP_FLAG_TPM2) ? "2.0" : "1.2",
vendor >> 16, ioread8(chip->vendor.iobase + TPM_RID(0)));
if (!itpm) {
probe = probe_itpm(chip);
if (probe < 0) {
rc = -ENODEV;
goto out_err;
}
itpm = !!probe;
}
if (itpm)
dev_info(dev, "Intel iTPM workaround enabled\n");
intfcaps =
ioread32(chip->vendor.iobase +
TPM_INTF_CAPS(chip->vendor.locality));
dev_dbg(dev, "TPM interface capabilities (0x%x):\n",
intfcaps);
if (intfcaps & TPM_INTF_BURST_COUNT_STATIC)
dev_dbg(dev, "\tBurst Count Static\n");
if (intfcaps & TPM_INTF_CMD_READY_INT)
dev_dbg(dev, "\tCommand Ready Int Support\n");
if (intfcaps & TPM_INTF_INT_EDGE_FALLING)
dev_dbg(dev, "\tInterrupt Edge Falling\n");
if (intfcaps & TPM_INTF_INT_EDGE_RISING)
dev_dbg(dev, "\tInterrupt Edge Rising\n");
if (intfcaps & TPM_INTF_INT_LEVEL_LOW)
dev_dbg(dev, "\tInterrupt Level Low\n");
if (intfcaps & TPM_INTF_INT_LEVEL_HIGH)
dev_dbg(dev, "\tInterrupt Level High\n");
if (intfcaps & TPM_INTF_LOCALITY_CHANGE_INT)
dev_dbg(dev, "\tLocality Change Int Support\n");
if (intfcaps & TPM_INTF_STS_VALID_INT)
dev_dbg(dev, "\tSts Valid Int Support\n");
if (intfcaps & TPM_INTF_DATA_AVAIL_INT)
dev_dbg(dev, "\tData Avail Int Support\n");
if (tpm_get_timeouts(chip)) {
dev_err(dev, "Could not get TPM timeouts and durations\n");
rc = -ENODEV;
goto out_err;
}
init_waitqueue_head(&chip->vendor.read_queue);
init_waitqueue_head(&chip->vendor.int_queue);
if (interrupts && tpm_info->irq != -1) {
if (tpm_info->irq) {
tpm_tis_probe_irq_single(chip, intmask, IRQF_SHARED,
tpm_info->irq);
if (!chip->vendor.irq)
dev_err(chip->pdev, FW_BUG
"TPM interrupt not working, polling instead\n");
} else
tpm_tis_probe_irq(chip, intmask);
}
if (chip->flags & TPM_CHIP_FLAG_TPM2) {
rc = tpm2_do_selftest(chip);
if (rc == TPM2_RC_INITIALIZE) {
dev_warn(dev, "Firmware has not started TPM\n");
rc = tpm2_startup(chip, TPM2_SU_CLEAR);
if (!rc)
rc = tpm2_do_selftest(chip);
}
if (rc) {
dev_err(dev, "TPM self test failed\n");
if (rc > 0)
rc = -ENODEV;
goto out_err;
}
} else {
if (tpm_do_selftest(chip)) {
dev_err(dev, "TPM self test failed\n");
rc = -ENODEV;
goto out_err;
}
}
return tpm_chip_register(chip);
out_err:
tpm_tis_remove(chip);
return rc;
}
static void tpm_tis_reenable_interrupts(struct tpm_chip *chip)
{
u32 intmask;
iowrite8(chip->vendor.irq, chip->vendor.iobase +
TPM_INT_VECTOR(chip->vendor.locality));
intmask =
ioread32(chip->vendor.iobase +
TPM_INT_ENABLE(chip->vendor.locality));
intmask |= TPM_INTF_CMD_READY_INT
| TPM_INTF_LOCALITY_CHANGE_INT | TPM_INTF_DATA_AVAIL_INT
| TPM_INTF_STS_VALID_INT | TPM_GLOBAL_INT_ENABLE;
iowrite32(intmask,
chip->vendor.iobase + TPM_INT_ENABLE(chip->vendor.locality));
}
static int tpm_tis_resume(struct device *dev)
{
struct tpm_chip *chip = dev_get_drvdata(dev);
int ret;
if (chip->vendor.irq)
tpm_tis_reenable_interrupts(chip);
ret = tpm_pm_resume(dev);
if (ret)
return ret;
if (!(chip->flags & TPM_CHIP_FLAG_TPM2))
tpm_do_selftest(chip);
return 0;
}
static int tpm_tis_pnp_init(struct pnp_dev *pnp_dev,
const struct pnp_device_id *pnp_id)
{
struct tpm_info tpm_info = {};
acpi_handle acpi_dev_handle = NULL;
struct resource *res;
res = pnp_get_resource(pnp_dev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
tpm_info.res = *res;
if (pnp_irq_valid(pnp_dev, 0))
tpm_info.irq = pnp_irq(pnp_dev, 0);
else
tpm_info.irq = -1;
if (pnp_acpi_device(pnp_dev)) {
if (is_itpm(pnp_acpi_device(pnp_dev)))
itpm = true;
acpi_dev_handle = ACPI_HANDLE(&pnp_dev->dev);
}
return tpm_tis_init(&pnp_dev->dev, &tpm_info, acpi_dev_handle);
}
static void tpm_tis_pnp_remove(struct pnp_dev *dev)
{
struct tpm_chip *chip = pnp_get_drvdata(dev);
tpm_chip_unregister(chip);
tpm_tis_remove(chip);
}
static int tpm_check_resource(struct acpi_resource *ares, void *data)
{
struct tpm_info *tpm_info = (struct tpm_info *) data;
struct resource res;
if (acpi_dev_resource_interrupt(ares, 0, &res))
tpm_info->irq = res.start;
else if (acpi_dev_resource_memory(ares, &res)) {
tpm_info->res = res;
tpm_info->res.name = NULL;
}
return 1;
}
static int tpm_tis_acpi_init(struct acpi_device *acpi_dev)
{
struct acpi_table_tpm2 *tbl;
acpi_status st;
struct list_head resources;
struct tpm_info tpm_info = {};
int ret;
st = acpi_get_table(ACPI_SIG_TPM2, 1,
(struct acpi_table_header **) &tbl);
if (ACPI_FAILURE(st) || tbl->header.length < sizeof(*tbl)) {
dev_err(&acpi_dev->dev,
FW_BUG "failed to get TPM2 ACPI table\n");
return -EINVAL;
}
if (tbl->start_method != ACPI_TPM2_MEMORY_MAPPED)
return -ENODEV;
INIT_LIST_HEAD(&resources);
tpm_info.irq = -1;
ret = acpi_dev_get_resources(acpi_dev, &resources, tpm_check_resource,
&tpm_info);
if (ret < 0)
return ret;
acpi_dev_free_resource_list(&resources);
if (resource_type(&tpm_info.res) != IORESOURCE_MEM) {
dev_err(&acpi_dev->dev,
FW_BUG "TPM2 ACPI table does not define a memory resource\n");
return -EINVAL;
}
if (is_itpm(acpi_dev))
itpm = true;
return tpm_tis_init(&acpi_dev->dev, &tpm_info, acpi_dev->handle);
}
static int tpm_tis_acpi_remove(struct acpi_device *dev)
{
struct tpm_chip *chip = dev_get_drvdata(&dev->dev);
tpm_chip_unregister(chip);
tpm_tis_remove(chip);
return 0;
}
static int tpm_tis_plat_probe(struct platform_device *pdev)
{
struct tpm_info tpm_info = {};
struct resource *res;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (res == NULL) {
dev_err(&pdev->dev, "no memory resource defined\n");
return -ENODEV;
}
tpm_info.res = *res;
res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (res) {
tpm_info.irq = res->start;
} else {
if (pdev == force_pdev)
tpm_info.irq = -1;
else
tpm_info.irq = 0;
}
return tpm_tis_init(&pdev->dev, &tpm_info, NULL);
}
static int tpm_tis_plat_remove(struct platform_device *pdev)
{
struct tpm_chip *chip = dev_get_drvdata(&pdev->dev);
tpm_chip_unregister(chip);
tpm_tis_remove(chip);
return 0;
}
static int tpm_tis_force_device(void)
{
struct platform_device *pdev;
static const struct resource x86_resources[] = {
{
.start = 0xFED40000,
.end = 0xFED40000 + TIS_MEM_LEN - 1,
.flags = IORESOURCE_MEM,
},
};
if (!force)
return 0;
pdev = platform_device_register_simple("tpm_tis", -1, x86_resources,
ARRAY_SIZE(x86_resources));
if (IS_ERR(pdev))
return PTR_ERR(pdev);
force_pdev = pdev;
return 0;
}
static int __init init_tis(void)
{
int rc;
rc = tpm_tis_force_device();
if (rc)
goto err_force;
rc = platform_driver_register(&tis_drv);
if (rc)
goto err_platform;
#ifdef CONFIG_ACPI
rc = acpi_bus_register_driver(&tis_acpi_driver);
if (rc)
goto err_acpi;
#endif
if (IS_ENABLED(CONFIG_PNP)) {
rc = pnp_register_driver(&tis_pnp_driver);
if (rc)
goto err_pnp;
}
return 0;
err_pnp:
#ifdef CONFIG_ACPI
acpi_bus_unregister_driver(&tis_acpi_driver);
err_acpi:
#endif
platform_device_unregister(force_pdev);
err_platform:
if (force_pdev)
platform_device_unregister(force_pdev);
err_force:
return rc;
}
static void __exit cleanup_tis(void)
{
pnp_unregister_driver(&tis_pnp_driver);
#ifdef CONFIG_ACPI
acpi_bus_unregister_driver(&tis_acpi_driver);
#endif
platform_driver_unregister(&tis_drv);
if (force_pdev)
platform_device_unregister(force_pdev);
}
