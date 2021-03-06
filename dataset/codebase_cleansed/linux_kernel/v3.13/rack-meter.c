static inline cputime64_t get_cpu_idle_time(unsigned int cpu)
{
u64 retval;
retval = kcpustat_cpu(cpu).cpustat[CPUTIME_IDLE] +
kcpustat_cpu(cpu).cpustat[CPUTIME_IOWAIT];
if (rackmeter_ignore_nice)
retval += kcpustat_cpu(cpu).cpustat[CPUTIME_NICE];
return retval;
}
static void rackmeter_setup_i2s(struct rackmeter *rm)
{
struct macio_chip *macio = rm->mdev->bus->chip;
pmac_call_feature(PMAC_FTR_WRITE_GPIO, NULL, RACKMETER_MAGIC_GPIO, 5);
pmac_call_feature(PMAC_FTR_SOUND_CHIP_ENABLE, rm->i2s, 0, 1);
MACIO_BIS(KEYLARGO_FCR1, KL1_I2S0_ENABLE);
MACIO_BIC(KEYLARGO_FCR1, KL1_I2S0_CLK_ENABLE_BIT);
(void)MACIO_IN32(KEYLARGO_FCR1);
udelay(10);
out_le32(rm->i2s_regs + 0x10, 0x01fa0000);
(void)in_le32(rm->i2s_regs + 0x10);
udelay(10);
MACIO_BIS(KEYLARGO_FCR1, KL1_I2S0_CELL_ENABLE |
KL1_I2S0_CLK_ENABLE_BIT);
(void)MACIO_IN32(KEYLARGO_FCR1);
udelay(10);
}
static void rackmeter_set_default_pattern(struct rackmeter *rm)
{
int i;
for (i = 0; i < 16; i++) {
if (i < 8)
rm->ubuf[i] = (i & 1) * 255;
else
rm->ubuf[i] = ((~i) & 1) * 255;
}
}
static void rackmeter_do_pause(struct rackmeter *rm, int pause)
{
struct rackmeter_dma *rdma = rm->dma_buf_v;
pr_debug("rackmeter: %s\n", pause ? "paused" : "started");
rm->paused = pause;
if (pause) {
DBDMA_DO_STOP(rm->dma_regs);
return;
}
memset(rdma->buf1, 0, SAMPLE_COUNT & sizeof(u32));
memset(rdma->buf2, 0, SAMPLE_COUNT & sizeof(u32));
rm->dma_buf_v->mark = 0;
mb();
out_le32(&rm->dma_regs->cmdptr_hi, 0);
out_le32(&rm->dma_regs->cmdptr, rm->dma_buf_p);
out_le32(&rm->dma_regs->control, (RUN << 16) | RUN);
}
static void rackmeter_setup_dbdma(struct rackmeter *rm)
{
struct rackmeter_dma *db = rm->dma_buf_v;
struct dbdma_cmd *cmd = db->cmd;
DBDMA_DO_RESET(rm->dma_regs);
pr_debug("rackmeter: mark offset=0x%zx\n",
offsetof(struct rackmeter_dma, mark));
pr_debug("rackmeter: buf1 offset=0x%zx\n",
offsetof(struct rackmeter_dma, buf1));
pr_debug("rackmeter: buf2 offset=0x%zx\n",
offsetof(struct rackmeter_dma, buf2));
memset(cmd, 0, 4 * sizeof(struct dbdma_cmd));
st_le16(&cmd->req_count, 4);
st_le16(&cmd->command, STORE_WORD | INTR_ALWAYS | KEY_SYSTEM);
st_le32(&cmd->phy_addr, rm->dma_buf_p +
offsetof(struct rackmeter_dma, mark));
st_le32(&cmd->cmd_dep, 0x02000000);
cmd++;
st_le16(&cmd->req_count, SAMPLE_COUNT * 4);
st_le16(&cmd->command, OUTPUT_MORE);
st_le32(&cmd->phy_addr, rm->dma_buf_p +
offsetof(struct rackmeter_dma, buf1));
cmd++;
st_le16(&cmd->req_count, 4);
st_le16(&cmd->command, STORE_WORD | INTR_ALWAYS | KEY_SYSTEM);
st_le32(&cmd->phy_addr, rm->dma_buf_p +
offsetof(struct rackmeter_dma, mark));
st_le32(&cmd->cmd_dep, 0x01000000);
cmd++;
st_le16(&cmd->req_count, SAMPLE_COUNT * 4);
st_le16(&cmd->command, OUTPUT_MORE | BR_ALWAYS);
st_le32(&cmd->phy_addr, rm->dma_buf_p +
offsetof(struct rackmeter_dma, buf2));
st_le32(&cmd->cmd_dep, rm->dma_buf_p);
rackmeter_do_pause(rm, 0);
}
static void rackmeter_do_timer(struct work_struct *work)
{
struct rackmeter_cpu *rcpu =
container_of(work, struct rackmeter_cpu, sniffer.work);
struct rackmeter *rm = rcpu->rm;
unsigned int cpu = smp_processor_id();
cputime64_t cur_jiffies, total_idle_ticks;
unsigned int total_ticks, idle_ticks;
int i, offset, load, cumm, pause;
cur_jiffies = jiffies64_to_cputime64(get_jiffies_64());
total_ticks = (unsigned int) (cur_jiffies - rcpu->prev_wall);
rcpu->prev_wall = cur_jiffies;
total_idle_ticks = get_cpu_idle_time(cpu);
idle_ticks = (unsigned int) (total_idle_ticks - rcpu->prev_idle);
rcpu->prev_idle = total_idle_ticks;
load = (9 * (total_ticks - idle_ticks)) / total_ticks;
offset = cpu << 3;
cumm = 0;
for (i = 0; i < 8; i++) {
u8 ub = (load > i) ? 0xff : 0;
rm->ubuf[i + offset] = ub;
cumm |= ub;
}
rcpu->zero = (cumm == 0);
pause = (rm->cpu[0].zero && rm->cpu[1].zero);
if (pause != rm->paused) {
mutex_lock(&rm->sem);
pause = (rm->cpu[0].zero && rm->cpu[1].zero);
rackmeter_do_pause(rm, pause);
mutex_unlock(&rm->sem);
}
schedule_delayed_work_on(cpu, &rcpu->sniffer,
msecs_to_jiffies(CPU_SAMPLING_RATE));
}
static void rackmeter_init_cpu_sniffer(struct rackmeter *rm)
{
unsigned int cpu;
rm->cpu[0].rm = rm;
INIT_DELAYED_WORK(&rm->cpu[0].sniffer, rackmeter_do_timer);
rm->cpu[1].rm = rm;
INIT_DELAYED_WORK(&rm->cpu[1].sniffer, rackmeter_do_timer);
for_each_online_cpu(cpu) {
struct rackmeter_cpu *rcpu;
if (cpu > 1)
continue;
rcpu = &rm->cpu[cpu];
rcpu->prev_idle = get_cpu_idle_time(cpu);
rcpu->prev_wall = jiffies64_to_cputime64(get_jiffies_64());
schedule_delayed_work_on(cpu, &rm->cpu[cpu].sniffer,
msecs_to_jiffies(CPU_SAMPLING_RATE));
}
}
static void rackmeter_stop_cpu_sniffer(struct rackmeter *rm)
{
cancel_delayed_work_sync(&rm->cpu[0].sniffer);
cancel_delayed_work_sync(&rm->cpu[1].sniffer);
}
static int rackmeter_setup(struct rackmeter *rm)
{
pr_debug("rackmeter: setting up i2s..\n");
rackmeter_setup_i2s(rm);
pr_debug("rackmeter: setting up default pattern..\n");
rackmeter_set_default_pattern(rm);
pr_debug("rackmeter: setting up dbdma..\n");
rackmeter_setup_dbdma(rm);
pr_debug("rackmeter: start CPU measurements..\n");
rackmeter_init_cpu_sniffer(rm);
printk(KERN_INFO "RackMeter initialized\n");
return 0;
}
static u32 rackmeter_calc_sample(struct rackmeter *rm, unsigned int index)
{
int led;
u32 sample = 0;
for (led = 0; led < 16; led++) {
sample >>= 1;
sample |= ((rm->ubuf[led] >= 0x80) << 15);
}
return (sample << 17) | (sample >> 15);
}
static irqreturn_t rackmeter_irq(int irq, void *arg)
{
struct rackmeter *rm = arg;
struct rackmeter_dma *db = rm->dma_buf_v;
unsigned int mark, i;
u32 *buf;
(void)in_le32(&rm->dma_regs->status);
rmb();
mark = db->mark;
if (mark != 1 && mark != 2) {
printk(KERN_WARNING "rackmeter: Incorrect DMA mark 0x%08x\n",
mark);
if (++rm->stale_irq > 3) {
printk(KERN_ERR "rackmeter: Too many errors,"
" stopping DMA\n");
DBDMA_DO_RESET(rm->dma_regs);
}
return IRQ_HANDLED;
}
buf = mark == 1 ? db->buf1 : db->buf2;
for (i = 0; i < SAMPLE_COUNT; i++)
buf[i] = rackmeter_calc_sample(rm, i);
return IRQ_HANDLED;
}
static int rackmeter_probe(struct macio_dev* mdev,
const struct of_device_id *match)
{
struct device_node *i2s = NULL, *np = NULL;
struct rackmeter *rm = NULL;
struct resource ri2s, rdma;
int rc = -ENODEV;
pr_debug("rackmeter_probe()\n");
while ((i2s = of_get_next_child(mdev->ofdev.dev.of_node, i2s)) != NULL)
if (strcmp(i2s->name, "i2s-a") == 0)
break;
if (i2s == NULL) {
pr_debug(" i2s-a child not found\n");
goto bail;
}
while ((np = of_get_next_child(i2s, np)) != NULL) {
if (strcmp(np->name, "lightshow") == 0)
break;
if ((strcmp(np->name, "sound") == 0) &&
of_get_property(np, "virtual", NULL) != NULL)
break;
}
if (np == NULL) {
pr_debug(" lightshow or sound+virtual child not found\n");
goto bail;
}
rm = kzalloc(sizeof(struct rackmeter), GFP_KERNEL);
if (rm == NULL) {
printk(KERN_ERR "rackmeter: failed to allocate memory !\n");
rc = -ENOMEM;
goto bail_release;
}
rm->mdev = mdev;
rm->i2s = i2s;
mutex_init(&rm->sem);
dev_set_drvdata(&mdev->ofdev.dev, rm);
#if 0
if (macio_resource_count(mdev) < 2 || macio_irq_count(mdev) < 2) {
printk(KERN_ERR
"rackmeter: found match but lacks resources: %s"
" (%d resources, %d interrupts)\n",
mdev->ofdev.node->full_name);
rc = -ENXIO;
goto bail_free;
}
if (macio_request_resources(mdev, "rackmeter")) {
printk(KERN_ERR
"rackmeter: failed to request resources: %s\n",
mdev->ofdev.node->full_name);
rc = -EBUSY;
goto bail_free;
}
rm->irq = macio_irq(mdev, 1);
#else
rm->irq = irq_of_parse_and_map(i2s, 1);
if (rm->irq == NO_IRQ ||
of_address_to_resource(i2s, 0, &ri2s) ||
of_address_to_resource(i2s, 1, &rdma)) {
printk(KERN_ERR
"rackmeter: found match but lacks resources: %s",
mdev->ofdev.dev.of_node->full_name);
rc = -ENXIO;
goto bail_free;
}
#endif
pr_debug(" i2s @0x%08x\n", (unsigned int)ri2s.start);
pr_debug(" dma @0x%08x\n", (unsigned int)rdma.start);
pr_debug(" irq %d\n", rm->irq);
rm->ubuf = (u8 *)__get_free_page(GFP_KERNEL);
if (rm->ubuf == NULL) {
printk(KERN_ERR
"rackmeter: failed to allocate samples page !\n");
rc = -ENOMEM;
goto bail_release;
}
rm->dma_buf_v = dma_alloc_coherent(&macio_get_pci_dev(mdev)->dev,
sizeof(struct rackmeter_dma),
&rm->dma_buf_p, GFP_KERNEL);
if (rm->dma_buf_v == NULL) {
printk(KERN_ERR
"rackmeter: failed to allocate dma buffer !\n");
rc = -ENOMEM;
goto bail_free_samples;
}
#if 0
rm->i2s_regs = ioremap(macio_resource_start(mdev, 0), 0x1000);
#else
rm->i2s_regs = ioremap(ri2s.start, 0x1000);
#endif
if (rm->i2s_regs == NULL) {
printk(KERN_ERR
"rackmeter: failed to map i2s registers !\n");
rc = -ENXIO;
goto bail_free_dma;
}
#if 0
rm->dma_regs = ioremap(macio_resource_start(mdev, 1), 0x100);
#else
rm->dma_regs = ioremap(rdma.start, 0x100);
#endif
if (rm->dma_regs == NULL) {
printk(KERN_ERR
"rackmeter: failed to map dma registers !\n");
rc = -ENXIO;
goto bail_unmap_i2s;
}
rc = rackmeter_setup(rm);
if (rc) {
printk(KERN_ERR
"rackmeter: failed to initialize !\n");
rc = -ENXIO;
goto bail_unmap_dma;
}
rc = request_irq(rm->irq, rackmeter_irq, 0, "rackmeter", rm);
if (rc != 0) {
printk(KERN_ERR
"rackmeter: failed to request interrupt !\n");
goto bail_stop_dma;
}
of_node_put(np);
return 0;
bail_stop_dma:
DBDMA_DO_RESET(rm->dma_regs);
bail_unmap_dma:
iounmap(rm->dma_regs);
bail_unmap_i2s:
iounmap(rm->i2s_regs);
bail_free_dma:
dma_free_coherent(&macio_get_pci_dev(mdev)->dev,
sizeof(struct rackmeter_dma),
rm->dma_buf_v, rm->dma_buf_p);
bail_free_samples:
free_page((unsigned long)rm->ubuf);
bail_release:
#if 0
macio_release_resources(mdev);
#endif
bail_free:
kfree(rm);
bail:
of_node_put(i2s);
of_node_put(np);
dev_set_drvdata(&mdev->ofdev.dev, NULL);
return rc;
}
static int rackmeter_remove(struct macio_dev* mdev)
{
struct rackmeter *rm = dev_get_drvdata(&mdev->ofdev.dev);
rackmeter_stop_cpu_sniffer(rm);
dev_set_drvdata(&mdev->ofdev.dev, NULL);
DBDMA_DO_RESET(rm->dma_regs);
free_irq(rm->irq, rm);
iounmap(rm->dma_regs);
iounmap(rm->i2s_regs);
dma_free_coherent(&macio_get_pci_dev(mdev)->dev,
sizeof(struct rackmeter_dma),
rm->dma_buf_v, rm->dma_buf_p);
free_page((unsigned long)rm->ubuf);
#if 0
macio_release_resources(mdev);
#endif
kfree(rm);
return 0;
}
static int rackmeter_shutdown(struct macio_dev* mdev)
{
struct rackmeter *rm = dev_get_drvdata(&mdev->ofdev.dev);
if (rm == NULL)
return -ENODEV;
rackmeter_stop_cpu_sniffer(rm);
DBDMA_DO_RESET(rm->dma_regs);
return 0;
}
static int __init rackmeter_init(void)
{
pr_debug("rackmeter_init()\n");
return macio_register_driver(&rackmeter_driver);
}
static void __exit rackmeter_exit(void)
{
pr_debug("rackmeter_exit()\n");
macio_unregister_driver(&rackmeter_driver);
}
