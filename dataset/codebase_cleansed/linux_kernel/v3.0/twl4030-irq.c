static int twl4030_irq_thread(void *data)
{
long irq = (long)data;
static unsigned i2c_errors;
static const unsigned max_i2c_errors = 100;
current->flags |= PF_NOFREEZE;
while (!kthread_should_stop()) {
int ret;
int module_irq;
u8 pih_isr;
wait_for_completion_interruptible(&irq_event);
ret = twl_i2c_read_u8(TWL4030_MODULE_PIH, &pih_isr,
REG_PIH_ISR_P1);
if (ret) {
pr_warning("twl4030: I2C error %d reading PIH ISR\n",
ret);
if (++i2c_errors >= max_i2c_errors) {
printk(KERN_ERR "Maximum I2C error count"
" exceeded. Terminating %s.\n",
__func__);
break;
}
complete(&irq_event);
continue;
}
local_irq_disable();
for (module_irq = twl4030_irq_base;
pih_isr;
pih_isr >>= 1, module_irq++) {
if (pih_isr & 0x1)
generic_handle_irq(module_irq);
}
local_irq_enable();
enable_irq(irq);
}
return 0;
}
static irqreturn_t handle_twl4030_pih(int irq, void *devid)
{
disable_irq_nosync(irq);
complete(devid);
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
static void twl4030_sih_do_mask(struct work_struct *work)
{
struct sih_agent *agent;
const struct sih *sih;
union {
u8 bytes[4];
u32 word;
} imr;
int status;
agent = container_of(work, struct sih_agent, mask_work);
spin_lock_irq(&sih_agent_lock);
if (agent->imr_change_pending) {
sih = agent->sih;
imr.word = cpu_to_le32(agent->imr << 8);
agent->imr_change_pending = false;
} else
sih = NULL;
spin_unlock_irq(&sih_agent_lock);
if (!sih)
return;
status = twl_i2c_write(sih->module, imr.bytes,
sih->mask[irq_line].imr_offset, sih->bytes_ixr);
if (status)
pr_err("twl4030: %s, %s --> %d\n", __func__,
"write", status);
}
static void twl4030_sih_do_edge(struct work_struct *work)
{
struct sih_agent *agent;
const struct sih *sih;
u8 bytes[6];
u32 edge_change;
int status;
agent = container_of(work, struct sih_agent, edge_work);
spin_lock_irq(&sih_agent_lock);
edge_change = agent->edge_change;
agent->edge_change = 0;
sih = edge_change ? agent->sih : NULL;
spin_unlock_irq(&sih_agent_lock);
if (!sih)
return;
status = twl_i2c_read(sih->module, bytes + 1,
sih->edr_offset, sih->bytes_edr);
if (status) {
pr_err("twl4030: %s, %s --> %d\n", __func__,
"read", status);
return;
}
while (edge_change) {
int i = fls(edge_change) - 1;
struct irq_data *idata = irq_get_irq_data(i + agent->irq_base);
int byte = 1 + (i >> 2);
int off = (i & 0x3) * 2;
unsigned int type;
bytes[byte] &= ~(0x03 << off);
type = irqd_get_trigger_type(idata);
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
static void twl4030_sih_mask(struct irq_data *data)
{
struct sih_agent *sih = irq_data_get_irq_chip_data(data);
unsigned long flags;
spin_lock_irqsave(&sih_agent_lock, flags);
sih->imr |= BIT(data->irq - sih->irq_base);
sih->imr_change_pending = true;
queue_work(wq, &sih->mask_work);
spin_unlock_irqrestore(&sih_agent_lock, flags);
}
static void twl4030_sih_unmask(struct irq_data *data)
{
struct sih_agent *sih = irq_data_get_irq_chip_data(data);
unsigned long flags;
spin_lock_irqsave(&sih_agent_lock, flags);
sih->imr &= ~BIT(data->irq - sih->irq_base);
sih->imr_change_pending = true;
queue_work(wq, &sih->mask_work);
spin_unlock_irqrestore(&sih_agent_lock, flags);
}
static int twl4030_sih_set_type(struct irq_data *data, unsigned trigger)
{
struct sih_agent *sih = irq_data_get_irq_chip_data(data);
unsigned long flags;
if (trigger & ~(IRQ_TYPE_EDGE_FALLING | IRQ_TYPE_EDGE_RISING))
return -EINVAL;
spin_lock_irqsave(&sih_agent_lock, flags);
if (irqd_get_trigger_type(data) != trigger) {
sih->edge_change |= BIT(data->irq - sih->irq_base);
queue_work(wq, &sih->edge_work);
}
spin_unlock_irqrestore(&sih_agent_lock, flags);
return 0;
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
static void handle_twl4030_sih(unsigned irq, struct irq_desc *desc)
{
struct sih_agent *agent = irq_get_handler_data(irq);
const struct sih *sih = agent->sih;
int isr;
local_irq_enable();
isr = sih_read_isr(sih);
local_irq_disable();
if (isr < 0) {
pr_err("twl4030: %s SIH, read ISR error %d\n",
sih->name, isr);
return;
}
while (isr) {
irq = fls(isr);
irq--;
isr &= ~BIT(irq);
if (irq < sih->bits)
generic_handle_irq(agent->irq_base + irq);
else
pr_err("twl4030: %s SIH, invalid ISR bit %d\n",
sih->name, irq);
}
}
int twl4030_sih_setup(int module)
{
int sih_mod;
const struct sih *sih = NULL;
struct sih_agent *agent;
int i, irq;
int status = -EINVAL;
unsigned irq_base = twl4030_irq_next;
for (sih_mod = 0, sih = sih_modules;
sih_mod < nr_sih_modules;
sih_mod++, sih++) {
if (sih->module == module && sih->set_cor) {
if (!WARN((irq_base + sih->bits) > NR_IRQS,
"irq %d for %s too big\n",
irq_base + sih->bits,
sih->name))
status = 0;
break;
}
}
if (status < 0)
return status;
agent = kzalloc(sizeof *agent, GFP_KERNEL);
if (!agent)
return -ENOMEM;
status = 0;
agent->irq_base = irq_base;
agent->sih = sih;
agent->imr = ~0;
INIT_WORK(&agent->mask_work, twl4030_sih_do_mask);
INIT_WORK(&agent->edge_work, twl4030_sih_do_edge);
for (i = 0; i < sih->bits; i++) {
irq = irq_base + i;
irq_set_chip_and_handler(irq, &twl4030_sih_irq_chip,
handle_edge_irq);
irq_set_chip_data(irq, agent);
activate_irq(irq);
}
status = irq_base;
twl4030_irq_next += i;
irq = sih_mod + twl4030_irq_base;
irq_set_handler_data(irq, agent);
irq_set_chained_handler(irq, handle_twl4030_sih);
pr_info("twl4030: %s (irq %d) chaining IRQs %d..%d\n", sih->name,
irq, irq_base, twl4030_irq_next - 1);
return status;
}
int twl4030_init_irq(int irq_num, unsigned irq_base, unsigned irq_end)
{
static struct irq_chip twl4030_irq_chip;
int status;
int i;
struct task_struct *task;
status = twl4030_init_sih_modules(twl_irq_line);
if (status < 0)
return status;
wq = create_singlethread_workqueue("twl4030-irqchip");
if (!wq) {
pr_err("twl4030: workqueue FAIL\n");
return -ESRCH;
}
twl4030_irq_base = irq_base;
twl4030_irq_chip = dummy_irq_chip;
twl4030_irq_chip.name = "twl4030";
twl4030_sih_irq_chip.irq_ack = dummy_irq_chip.irq_ack;
for (i = irq_base; i < irq_end; i++) {
irq_set_chip_and_handler(i, &twl4030_irq_chip,
handle_simple_irq);
activate_irq(i);
}
twl4030_irq_next = i;
pr_info("twl4030: %s (irq %d) chaining IRQs %d..%d\n", "PIH",
irq_num, irq_base, twl4030_irq_next - 1);
status = twl4030_sih_setup(TWL4030_MODULE_INT);
if (status < 0) {
pr_err("twl4030: sih_setup PWR INT --> %d\n", status);
goto fail;
}
init_completion(&irq_event);
status = request_irq(irq_num, handle_twl4030_pih, IRQF_DISABLED,
"TWL4030-PIH", &irq_event);
if (status < 0) {
pr_err("twl4030: could not claim irq%d: %d\n", irq_num, status);
goto fail_rqirq;
}
task = kthread_run(twl4030_irq_thread, (void *)(long)irq_num,
"twl4030-irq");
if (IS_ERR(task)) {
pr_err("twl4030: could not create irq %d thread!\n", irq_num);
status = PTR_ERR(task);
goto fail_kthread;
}
return status;
fail_kthread:
free_irq(irq_num, &irq_event);
fail_rqirq:
fail:
for (i = irq_base; i < irq_end; i++)
irq_set_chip_and_handler(i, NULL, NULL);
destroy_workqueue(wq);
wq = NULL;
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
