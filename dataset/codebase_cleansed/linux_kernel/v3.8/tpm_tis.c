static int is_itpm(struct pnp_dev *dev)
{
struct acpi_device *acpi = pnp_acpi_device(dev);
struct acpi_hardware_id *id;
list_for_each_entry(id, &acpi->pnp.ids, list) {
if (!strcmp("INTC0102", id->id))
return 1;
}
return 0;
}
static inline int is_itpm(struct pnp_dev *dev)
{
return 0;
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
&chip->vendor.read_queue)
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
dev_err(chip->dev, "Unable to read header\n");
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
dev_err(chip->dev, "Unable to read remainder of result\n");
size = -ETIME;
goto out;
}
wait_for_tpm_stat(chip, TPM_STS_VALID, chip->vendor.timeout_c,
&chip->vendor.int_queue);
status = tpm_tis_status(chip);
if (status & TPM_STS_DATA_AVAIL) {
dev_err(chip->dev, "Error left over data\n");
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
&chip->vendor.int_queue) < 0) {
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
&chip->vendor.int_queue);
status = tpm_tis_status(chip);
if (!itpm && (status & TPM_STS_DATA_EXPECT) == 0) {
rc = -EIO;
goto out_err;
}
}
iowrite8(buf[count],
chip->vendor.iobase + TPM_DATA_FIFO(chip->vendor.locality));
wait_for_tpm_stat(chip, TPM_STS_VALID, chip->vendor.timeout_c,
&chip->vendor.int_queue);
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
static int tpm_tis_send(struct tpm_chip *chip, u8 *buf, size_t len)
{
int rc;
u32 ordinal;
rc = tpm_tis_send_data(chip, buf, len);
if (rc < 0)
return rc;
iowrite8(TPM_STS_GO,
chip->vendor.iobase + TPM_STS(chip->vendor.locality));
if (chip->vendor.irq) {
ordinal = be32_to_cpu(*((__be32 *) (buf + 6)));
if (wait_for_tpm_stat
(chip, TPM_STS_DATA_AVAIL | TPM_STS_VALID,
tpm_calc_ordinal_duration(chip, ordinal),
&chip->vendor.read_queue) < 0) {
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
itpm = 0;
rc = tpm_tis_send_data(chip, cmd_getticks, len);
if (rc == 0)
goto out;
tpm_tis_ready(chip);
release_locality(chip, chip->vendor.locality, 0);
itpm = 1;
rc = tpm_tis_send_data(chip, cmd_getticks, len);
if (rc == 0) {
dev_info(chip->dev, "Detected an iTPM.\n");
rc = 1;
} else
rc = -EFAULT;
out:
itpm = rem_itpm;
tpm_tis_ready(chip);
release_locality(chip, chip->vendor.locality, 0);
return rc;
}
static irqreturn_t tis_int_probe(int irq, void *dev_id)
{
struct tpm_chip *chip = dev_id;
u32 interrupt;
interrupt = ioread32(chip->vendor.iobase +
TPM_INT_STATUS(chip->vendor.locality));
if (interrupt == 0)
return IRQ_NONE;
chip->vendor.probed_irq = irq;
iowrite32(interrupt,
chip->vendor.iobase +
TPM_INT_STATUS(chip->vendor.locality));
return IRQ_HANDLED;
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
static int tpm_tis_init(struct device *dev, resource_size_t start,
resource_size_t len, unsigned int irq)
{
u32 vendor, intfcaps, intmask;
int rc, i, irq_s, irq_e, probe;
struct tpm_chip *chip;
if (!(chip = tpm_register_hardware(dev, &tpm_tis)))
return -ENODEV;
chip->vendor.iobase = ioremap(start, len);
if (!chip->vendor.iobase) {
rc = -EIO;
goto out_err;
}
chip->vendor.timeout_a = msecs_to_jiffies(TIS_SHORT_TIMEOUT);
chip->vendor.timeout_b = msecs_to_jiffies(TIS_LONG_TIMEOUT);
chip->vendor.timeout_c = msecs_to_jiffies(TIS_SHORT_TIMEOUT);
chip->vendor.timeout_d = msecs_to_jiffies(TIS_SHORT_TIMEOUT);
if (request_locality(chip, 0) != 0) {
rc = -ENODEV;
goto out_err;
}
vendor = ioread32(chip->vendor.iobase + TPM_DID_VID(0));
dev_info(dev,
"1.2 TPM (device-id 0x%X, rev-id %d)\n",
vendor >> 16, ioread8(chip->vendor.iobase + TPM_RID(0)));
if (!itpm) {
probe = probe_itpm(chip);
if (probe < 0) {
rc = -ENODEV;
goto out_err;
}
itpm = (probe == 0) ? 0 : 1;
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
if (tpm_do_selftest(chip)) {
dev_err(dev, "TPM self test failed\n");
rc = -ENODEV;
goto out_err;
}
init_waitqueue_head(&chip->vendor.read_queue);
init_waitqueue_head(&chip->vendor.int_queue);
intmask =
ioread32(chip->vendor.iobase +
TPM_INT_ENABLE(chip->vendor.locality));
intmask |= TPM_INTF_CMD_READY_INT
| TPM_INTF_LOCALITY_CHANGE_INT | TPM_INTF_DATA_AVAIL_INT
| TPM_INTF_STS_VALID_INT;
iowrite32(intmask,
chip->vendor.iobase +
TPM_INT_ENABLE(chip->vendor.locality));
if (interrupts)
chip->vendor.irq = irq;
if (interrupts && !chip->vendor.irq) {
irq_s =
ioread8(chip->vendor.iobase +
TPM_INT_VECTOR(chip->vendor.locality));
if (irq_s) {
irq_e = irq_s;
} else {
irq_s = 3;
irq_e = 15;
}
for (i = irq_s; i <= irq_e && chip->vendor.irq == 0; i++) {
iowrite8(i, chip->vendor.iobase +
TPM_INT_VECTOR(chip->vendor.locality));
if (request_irq
(i, tis_int_probe, IRQF_SHARED,
chip->vendor.miscdev.name, chip) != 0) {
dev_info(chip->dev,
"Unable to request irq: %d for probe\n",
i);
continue;
}
iowrite32(ioread32
(chip->vendor.iobase +
TPM_INT_STATUS(chip->vendor.locality)),
chip->vendor.iobase +
TPM_INT_STATUS(chip->vendor.locality));
iowrite32(intmask | TPM_GLOBAL_INT_ENABLE,
chip->vendor.iobase +
TPM_INT_ENABLE(chip->vendor.locality));
chip->vendor.probed_irq = 0;
tpm_gen_interrupt(chip);
chip->vendor.irq = chip->vendor.probed_irq;
iowrite32(ioread32
(chip->vendor.iobase +
TPM_INT_STATUS(chip->vendor.locality)),
chip->vendor.iobase +
TPM_INT_STATUS(chip->vendor.locality));
iowrite32(intmask,
chip->vendor.iobase +
TPM_INT_ENABLE(chip->vendor.locality));
free_irq(i, chip);
}
}
if (chip->vendor.irq) {
iowrite8(chip->vendor.irq,
chip->vendor.iobase +
TPM_INT_VECTOR(chip->vendor.locality));
if (request_irq
(chip->vendor.irq, tis_int_handler, IRQF_SHARED,
chip->vendor.miscdev.name, chip) != 0) {
dev_info(chip->dev,
"Unable to request irq: %d for use\n",
chip->vendor.irq);
chip->vendor.irq = 0;
} else {
iowrite32(ioread32
(chip->vendor.iobase +
TPM_INT_STATUS(chip->vendor.locality)),
chip->vendor.iobase +
TPM_INT_STATUS(chip->vendor.locality));
iowrite32(intmask | TPM_GLOBAL_INT_ENABLE,
chip->vendor.iobase +
TPM_INT_ENABLE(chip->vendor.locality));
}
}
INIT_LIST_HEAD(&chip->vendor.list);
mutex_lock(&tis_lock);
list_add(&chip->vendor.list, &tis_chips);
mutex_unlock(&tis_lock);
return 0;
out_err:
if (chip->vendor.iobase)
iounmap(chip->vendor.iobase);
tpm_remove_hardware(chip->dev);
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
static int tpm_tis_pnp_init(struct pnp_dev *pnp_dev,
const struct pnp_device_id *pnp_id)
{
resource_size_t start, len;
unsigned int irq = 0;
start = pnp_mem_start(pnp_dev, 0);
len = pnp_mem_len(pnp_dev, 0);
if (pnp_irq_valid(pnp_dev, 0))
irq = pnp_irq(pnp_dev, 0);
else
interrupts = 0;
if (is_itpm(pnp_dev))
itpm = 1;
return tpm_tis_init(&pnp_dev->dev, start, len, irq);
}
static int tpm_tis_pnp_suspend(struct pnp_dev *dev, pm_message_t msg)
{
return tpm_pm_suspend(&dev->dev);
}
static int tpm_tis_pnp_resume(struct pnp_dev *dev)
{
struct tpm_chip *chip = pnp_get_drvdata(dev);
int ret;
if (chip->vendor.irq)
tpm_tis_reenable_interrupts(chip);
ret = tpm_pm_resume(&dev->dev);
if (!ret)
tpm_do_selftest(chip);
return ret;
}
static void tpm_tis_pnp_remove(struct pnp_dev *dev)
{
struct tpm_chip *chip = pnp_get_drvdata(dev);
tpm_dev_vendor_release(chip);
kfree(chip);
}
static int tpm_tis_resume(struct device *dev)
{
struct tpm_chip *chip = dev_get_drvdata(dev);
if (chip->vendor.irq)
tpm_tis_reenable_interrupts(chip);
return tpm_pm_resume(dev);
}
static int __init init_tis(void)
{
int rc;
#ifdef CONFIG_PNP
if (!force)
return pnp_register_driver(&tis_pnp_driver);
#endif
rc = platform_driver_register(&tis_drv);
if (rc < 0)
return rc;
if (IS_ERR(pdev=platform_device_register_simple("tpm_tis", -1, NULL, 0)))
return PTR_ERR(pdev);
if((rc=tpm_tis_init(&pdev->dev, TIS_MEM_BASE, TIS_MEM_LEN, 0)) != 0) {
platform_device_unregister(pdev);
platform_driver_unregister(&tis_drv);
}
return rc;
}
static void __exit cleanup_tis(void)
{
struct tpm_vendor_specific *i, *j;
struct tpm_chip *chip;
mutex_lock(&tis_lock);
list_for_each_entry_safe(i, j, &tis_chips, list) {
chip = to_tpm_chip(i);
tpm_remove_hardware(chip->dev);
iowrite32(~TPM_GLOBAL_INT_ENABLE &
ioread32(chip->vendor.iobase +
TPM_INT_ENABLE(chip->vendor.
locality)),
chip->vendor.iobase +
TPM_INT_ENABLE(chip->vendor.locality));
release_locality(chip, chip->vendor.locality, 1);
if (chip->vendor.irq)
free_irq(chip->vendor.irq, chip);
iounmap(i->iobase);
list_del(&i->list);
}
mutex_unlock(&tis_lock);
#ifdef CONFIG_PNP
if (!force) {
pnp_unregister_driver(&tis_pnp_driver);
return;
}
#endif
platform_device_unregister(pdev);
platform_driver_unregister(&tis_drv);
}
