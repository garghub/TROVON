static void print_summary(uint32_t status, uint32_t l2_err,
uint32_t memio_err)
{
printk("Bus watcher error counters: %08x %08x\n", l2_err, memio_err);
printk("\nLast recorded signature:\n");
printk("Request %02x from %d, answered by %d with Dcode %d\n",
(unsigned int)(G_SCD_BERR_TID(status) & 0x3f),
(int)(G_SCD_BERR_TID(status) >> 6),
(int)G_SCD_BERR_RID(status),
(int)G_SCD_BERR_DCODE(status));
}
void check_bus_watcher(void)
{
u32 status, l2_err, memio_err;
#ifdef CONFIG_SB1_PASS_1_WORKAROUNDS
status = csr_in32(IOADDR(A_SCD_BUS_ERR_STATUS));
#elif defined(CONFIG_SIBYTE_BCM112X) || defined(CONFIG_SIBYTE_SB1250)
status = csr_in32(IOADDR(A_SCD_BUS_ERR_STATUS_DEBUG));
#elif defined(CONFIG_SIBYTE_BCM1x55) || defined(CONFIG_SIBYTE_BCM1x80)
status = csr_in32(IOADDR(A_BCM1480_BUS_ERR_STATUS_DEBUG));
#else
#error bus watcher being built for unknown Sibyte SOC!
#endif
if (!(status & 0x7fffffff)) {
printk("Using last values reaped by bus watcher driver\n");
status = bw_stats.status;
l2_err = bw_stats.l2_err;
memio_err = bw_stats.memio_err;
} else {
l2_err = csr_in32(IOADDR(A_BUS_L2_ERRORS));
memio_err = csr_in32(IOADDR(A_BUS_MEM_IO_ERRORS));
}
if (status & ~(1UL << 31))
print_summary(status, l2_err, memio_err);
else
printk("Bus watcher indicates no error\n");
}
static int bw_proc_show(struct seq_file *m, void *v)
{
struct bw_stats_struct *stats = m->private;
seq_puts(m, "SiByte Bus Watcher statistics\n");
seq_puts(m, "-----------------------------\n");
seq_printf(m, "L2-d-cor %8ld\nL2-d-bad %8ld\n",
stats->l2_cor_d, stats->l2_bad_d);
seq_printf(m, "L2-t-cor %8ld\nL2-t-bad %8ld\n",
stats->l2_cor_t, stats->l2_bad_t);
seq_printf(m, "MC-d-cor %8ld\nMC-d-bad %8ld\n",
stats->mem_cor_d, stats->mem_bad_d);
seq_printf(m, "IO-err %8ld\n", stats->bus_error);
seq_puts(m, "\nLast recorded signature:\n");
seq_printf(m, "Request %02x from %d, answered by %d with Dcode %d\n",
(unsigned int)(G_SCD_BERR_TID(stats->status) & 0x3f),
(int)(G_SCD_BERR_TID(stats->status) >> 6),
(int)G_SCD_BERR_RID(stats->status),
(int)G_SCD_BERR_DCODE(stats->status));
if (stats->status & M_SCD_BERR_MULTERRS)
seq_puts(m, "Multiple errors observed since last check.\n");
if (stats->status_printed) {
seq_puts(m, "(no change since last printing)\n");
} else {
stats->status_printed = 1;
}
return 0;
}
static int bw_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, bw_proc_show, PDE_DATA(inode));
}
static void create_proc_decoder(struct bw_stats_struct *stats)
{
struct proc_dir_entry *ent;
ent = proc_create_data("bus_watcher", S_IWUSR | S_IRUGO, NULL,
&bw_proc_fops, stats);
if (!ent) {
printk(KERN_INFO "Unable to initialize bus_watcher /proc entry\n");
return;
}
}
static irqreturn_t sibyte_bw_int(int irq, void *data)
{
struct bw_stats_struct *stats = data;
unsigned long cntr;
#ifdef CONFIG_SIBYTE_BW_TRACE
int i;
#endif
#ifdef CONFIG_SIBYTE_BW_TRACE
csr_out32(M_SCD_TRACE_CFG_FREEZE, IOADDR(A_SCD_TRACE_CFG));
csr_out32(M_SCD_TRACE_CFG_START_READ, IOADDR(A_SCD_TRACE_CFG));
for (i=0; i<256*6; i++)
printk("%016llx\n",
(long long)__raw_readq(IOADDR(A_SCD_TRACE_READ)));
csr_out32(M_SCD_TRACE_CFG_RESET, IOADDR(A_SCD_TRACE_CFG));
csr_out32(M_SCD_TRACE_CFG_START, IOADDR(A_SCD_TRACE_CFG));
#endif
stats->status = csr_in32(IOADDR(A_SCD_BUS_ERR_STATUS));
stats->status_printed = 0;
stats->l2_err = cntr = csr_in32(IOADDR(A_BUS_L2_ERRORS));
stats->l2_cor_d += G_SCD_L2ECC_CORR_D(cntr);
stats->l2_bad_d += G_SCD_L2ECC_BAD_D(cntr);
stats->l2_cor_t += G_SCD_L2ECC_CORR_T(cntr);
stats->l2_bad_t += G_SCD_L2ECC_BAD_T(cntr);
csr_out32(0, IOADDR(A_BUS_L2_ERRORS));
stats->memio_err = cntr = csr_in32(IOADDR(A_BUS_MEM_IO_ERRORS));
stats->mem_cor_d += G_SCD_MEM_ECC_CORR(cntr);
stats->mem_bad_d += G_SCD_MEM_ECC_BAD(cntr);
stats->bus_error += G_SCD_MEM_BUSERR(cntr);
csr_out32(0, IOADDR(A_BUS_MEM_IO_ERRORS));
return IRQ_HANDLED;
}
int __init sibyte_bus_watcher(void)
{
memset(&bw_stats, 0, sizeof(struct bw_stats_struct));
bw_stats.status_printed = 1;
if (request_irq(K_INT_BAD_ECC, sibyte_bw_int, 0, "Bus watcher", &bw_stats)) {
printk("Failed to register bus watcher BAD_ECC irq\n");
return -1;
}
if (request_irq(K_INT_COR_ECC, sibyte_bw_int, 0, "Bus watcher", &bw_stats)) {
free_irq(K_INT_BAD_ECC, &bw_stats);
printk("Failed to register bus watcher COR_ECC irq\n");
return -1;
}
if (request_irq(K_INT_IO_BUS, sibyte_bw_int, 0, "Bus watcher", &bw_stats)) {
free_irq(K_INT_BAD_ECC, &bw_stats);
free_irq(K_INT_COR_ECC, &bw_stats);
printk("Failed to register bus watcher IO_BUS irq\n");
return -1;
}
#ifdef CONFIG_PROC_FS
create_proc_decoder(&bw_stats);
#endif
#ifdef CONFIG_SIBYTE_BW_TRACE
csr_out32((M_SCD_TRSEQ_ASAMPLE | M_SCD_TRSEQ_DSAMPLE |
K_SCD_TRSEQ_TRIGGER_ALL),
IOADDR(A_SCD_TRACE_SEQUENCE_0));
csr_out32(M_SCD_TRACE_CFG_RESET, IOADDR(A_SCD_TRACE_CFG));
csr_out32(M_SCD_TRACE_CFG_START, IOADDR(A_SCD_TRACE_CFG));
#endif
return 0;
}
