static irqreturn_t handle_twl4030_pih(int irq, void *devid)
{
irqreturn_t ret;
u8 pih_isr;
ret = twl_i2c_read_u8(TWL_MODULE_PIH, &pih_isr,
REG_PIH_ISR_P1);
if (ret) {
pr_warning("twl4030: I2C error %d reading PIH ISR\n", ret);
return IRQ_NONE;
}
while (pih_isr) {
unsigned long pending = __ffs(pih_isr);
unsigned int irq;
pih_isr &= ~BIT(pending);
irq = pending + twl4030_irq_base;
handle_nested_irq(irq);
}
return IRQ_HANDLED;
}
static int twl4030_init_sih_modules(unsigned line)
{
const struct sih *sih;
u8 buf[4];
int i;
int status;
if (line > 1)
return -EINVAL;
irq_line = line;
memset(buf, 0xff, sizeof buf);
sih = sih_modules;
for (i = 0; i < nr_sih_modules; i++, sih++) {
if (!sih->bytes_ixr)
continue;
if (sih->irq_lines <= line)
continue;
status = twl_i2c_write(sih->module, buf,
sih->mask[line].imr_offset, sih->bytes_ixr);
if (status < 0)
pr_err("twl4030: err %d initializing %s %s\n",
status, sih->name, "IMR");
if (sih->set_cor) {
status = twl_i2c_write_u8(sih->module,
TWL4030_SIH_CTRL_COR_MASK,
sih->control_offset);
if (status < 0)
pr_err("twl4030: err %d initializing %s %s\n",
status, sih->name, "SIH_CTRL");
}
}
sih = sih_modules;
for (i = 0; i < nr_sih_modules; i++, sih++) {
u8 rxbuf[4];
int j;
if (!sih->bytes_ixr)
continue;
if (sih->irq_lines <= line)
continue;
for (j = 0; j < 2; j++) {
status = twl_i2c_read(sih->module, rxbuf,
sih->mask[line].isr_offset, sih->bytes_ixr);
if (status < 0)
pr_err("twl4030: err %d initializing %s %s\n",
status, sih->name, "ISR");
if (!sih->set_cor)
status = twl_i2c_write(sih->module, buf,
sih->mask[line].isr_offset,
sih->bytes_ixr);
}
}
return 0;
}
static inline void activate_irq(int irq)
{
#ifdef CONFIG_ARM
set_irq_flags(irq, IRQF_VALID);
#else
irq_set_noprobe(irq);
#endif
}
static void twl4030_sih_mask(struct irq_data *data)
{
struct sih_agent *agent = irq_data_get_irq_chip_data(data);
agent->imr |= BIT(data->irq - agent->irq_base);
agent->imr_change_pending = true;
}
static void twl4030_sih_unmask(struct irq_data *data)
{
struct sih_agent *agent = irq_data_get_irq_chip_data(data);
agent->imr &= ~BIT(data->irq - agent->irq_base);
agent->imr_change_pending = true;
}
static int twl4030_sih_set_type(struct irq_data *data, unsigned trigger)
{
struct sih_agent *agent = irq_data_get_irq_chip_data(data);
if (trigger & ~(IRQ_TYPE_EDGE_FALLING | IRQ_TYPE_EDGE_RISING))
return -EINVAL;
if (irqd_get_trigger_type(data) != trigger)
agent->edge_change |= BIT(data->irq - agent->irq_base);
return 0;
}
static void twl4030_sih_bus_lock(struct irq_data *data)
{
struct sih_agent *agent = irq_data_get_irq_chip_data(data);
mutex_lock(&agent->irq_lock);
}
static void twl4030_sih_bus_sync_unlock(struct irq_data *data)
{
struct sih_agent *agent = irq_data_get_irq_chip_data(data);
const struct sih *sih = agent->sih;
int status;
if (agent->imr_change_pending) {
union {
u32 word;
u8 bytes[4];
} imr;
imr.word = cpu_to_le32(agent->imr);
agent->imr_change_pending = false;
status = twl_i2c_write(sih->module, imr.bytes,
sih->mask[irq_line].imr_offset,
sih->bytes_ixr);
if (status)
pr_err("twl4030: %s, %s --> %d\n", __func__,
"write", status);
}
if (agent->edge_change) {
u32 edge_change;
u8 bytes[6];
edge_change = agent->edge_change;
agent->edge_change = 0;
status = twl_i2c_read(sih->module, bytes,
sih->edr_offset, sih->bytes_edr);
if (status) {
pr_err("twl4030: %s, %s --> %d\n", __func__,
"read", status);
return;
}
while (edge_change) {
int i = fls(edge_change) - 1;
int byte = i >> 2;
int off = (i & 0x3) * 2;
unsigned int type;
bytes[byte] &= ~(0x03 << off);
type = irq_get_trigger_type(i + agent->irq_base);
if (type & IRQ_TYPE_EDGE_RISING)
bytes[byte] |= BIT(off + 1);
if (type & IRQ_TYPE_EDGE_FALLING)
bytes[byte] |= BIT(off + 0);
edge_change &= ~BIT(i);
}
status = twl_i2c_write(sih->module, bytes,
sih->edr_offset, sih->bytes_edr);
if (status)
pr_err("twl4030: %s, %s --> %d\n", __func__,
"write", status);
}
mutex_unlock(&agent->irq_lock);
}
static inline int sih_read_isr(const struct sih *sih)
{
int status;
union {
u8 bytes[4];
u32 word;
} isr;
isr.word = 0;
status = twl_i2c_read(sih->module, isr.bytes,
sih->mask[irq_line].isr_offset, sih->bytes_ixr);
return (status < 0) ? status : le32_to_cpu(isr.word);
}
static irqreturn_t handle_twl4030_sih(int irq, void *data)
{
struct sih_agent *agent = irq_get_handler_data(irq);
const struct sih *sih = agent->sih;
int isr;
isr = sih_read_isr(sih);
if (isr < 0) {
pr_err("twl4030: %s SIH, read ISR error %d\n",
sih->name, isr);
return IRQ_HANDLED;
}
while (isr) {
irq = fls(isr);
irq--;
isr &= ~BIT(irq);
if (irq < sih->bits)
handle_nested_irq(agent->irq_base + irq);
else
pr_err("twl4030: %s SIH, invalid ISR bit %d\n",
sih->name, irq);
}
return IRQ_HANDLED;
}
int twl4030_sih_setup(struct device *dev, int module, int irq_base)
{
int sih_mod;
const struct sih *sih = NULL;
struct sih_agent *agent;
int i, irq;
int status = -EINVAL;
for (sih_mod = 0, sih = sih_modules; sih_mod < nr_sih_modules;
sih_mod++, sih++) {
if (sih->module == module && sih->set_cor) {
status = 0;
break;
}
}
if (status < 0)
return status;
agent = kzalloc(sizeof *agent, GFP_KERNEL);
if (!agent)
return -ENOMEM;
agent->irq_base = irq_base;
agent->sih = sih;
agent->imr = ~0;
mutex_init(&agent->irq_lock);
for (i = 0; i < sih->bits; i++) {
irq = irq_base + i;
irq_set_chip_data(irq, agent);
irq_set_chip_and_handler(irq, &twl4030_sih_irq_chip,
handle_edge_irq);
irq_set_nested_thread(irq, 1);
activate_irq(irq);
}
irq = sih_mod + twl4030_irq_base;
irq_set_handler_data(irq, agent);
agent->irq_name = kasprintf(GFP_KERNEL, "twl4030_%s", sih->name);
status = request_threaded_irq(irq, NULL, handle_twl4030_sih,
IRQF_EARLY_RESUME,
agent->irq_name ?: sih->name, NULL);
dev_info(dev, "%s (irq %d) chaining IRQs %d..%d\n", sih->name,
irq, irq_base, irq_base + i - 1);
return status < 0 ? status : irq_base;
}
int twl4030_init_irq(struct device *dev, int irq_num)
{
static struct irq_chip twl4030_irq_chip;
int status, i;
int irq_base, irq_end, nr_irqs;
struct device_node *node = dev->of_node;
nr_irqs = TWL4030_PWR_NR_IRQS + TWL4030_CORE_NR_IRQS;
irq_base = irq_alloc_descs(-1, 0, nr_irqs, 0);
if (IS_ERR_VALUE(irq_base)) {
dev_err(dev, "Fail to allocate IRQ descs\n");
return irq_base;
}
irq_domain_add_legacy(node, nr_irqs, irq_base, 0,
&irq_domain_simple_ops, NULL);
irq_end = irq_base + TWL4030_CORE_NR_IRQS;
status = twl4030_init_sih_modules(twl_irq_line);
if (status < 0)
return status;
twl4030_irq_base = irq_base;
twl4030_irq_chip = dummy_irq_chip;
twl4030_irq_chip.name = "twl4030";
twl4030_sih_irq_chip.irq_ack = dummy_irq_chip.irq_ack;
for (i = irq_base; i < irq_end; i++) {
irq_set_chip_and_handler(i, &twl4030_irq_chip,
handle_simple_irq);
irq_set_nested_thread(i, 1);
activate_irq(i);
}
dev_info(dev, "%s (irq %d) chaining IRQs %d..%d\n", "PIH",
irq_num, irq_base, irq_end);
status = twl4030_sih_setup(dev, TWL4030_MODULE_INT, irq_end);
if (status < 0) {
dev_err(dev, "sih_setup PWR INT --> %d\n", status);
goto fail;
}
status = request_threaded_irq(irq_num, NULL, handle_twl4030_pih,
IRQF_ONESHOT,
"TWL4030-PIH", NULL);
if (status < 0) {
dev_err(dev, "could not claim irq%d: %d\n", irq_num, status);
goto fail_rqirq;
}
enable_irq_wake(irq_num);
return irq_base;
fail_rqirq:
fail:
for (i = irq_base; i < irq_end; i++) {
irq_set_nested_thread(i, 0);
irq_set_chip_and_handler(i, NULL, NULL);
}
return status;
}
int twl4030_exit_irq(void)
{
if (twl4030_irq_base) {
pr_err("twl4030: can't yet clean up IRQs?\n");
return -ENOSYS;
}
return 0;
}
int twl4030_init_chip_irq(const char *chip)
{
if (!strcmp(chip, "twl5031")) {
sih_modules = sih_modules_twl5031;
nr_sih_modules = ARRAY_SIZE(sih_modules_twl5031);
} else {
sih_modules = sih_modules_twl4030;
nr_sih_modules = ARRAY_SIZE(sih_modules_twl4030);
}
return 0;
}
