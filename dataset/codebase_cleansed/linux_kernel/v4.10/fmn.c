static irqreturn_t fmn_message_handler(int irq, void *data)
{
struct fmn_message_handler *hndlr;
int bucket, rv;
int size = 0, code = 0, src_stnid = 0;
struct nlm_fmn_msg msg;
uint32_t mflags, bkt_status;
mflags = nlm_cop2_enable_irqsave();
nlm_fmn_setup_intr(irq, 0);
while (1) {
bkt_status = (nlm_read_c2_status0() >> 24) & 0xff;
if (bkt_status == 0xff)
break;
for (bucket = 0; bucket < 8; bucket++) {
if (bkt_status & (1 << bucket))
continue;
rv = nlm_fmn_receive(bucket, &size, &code, &src_stnid,
&msg);
if (rv != 0)
continue;
hndlr = &msg_handlers[src_stnid];
if (hndlr->action == NULL)
pr_warn("No msgring handler for stnid %d\n",
src_stnid);
else {
nlm_cop2_disable_irqrestore(mflags);
hndlr->action(bucket, src_stnid, size, code,
&msg, hndlr->arg);
mflags = nlm_cop2_enable_irqsave();
}
}
};
nlm_fmn_setup_intr(irq, (1 << nlm_threads_per_core) - 1);
nlm_cop2_disable_irqrestore(mflags);
return IRQ_HANDLED;
}
void xlr_percpu_fmn_init(void)
{
struct xlr_fmn_info *cpu_fmn_info;
int *bucket_sizes;
uint32_t flags;
int id;
BUG_ON(nlm_thread_id() != 0);
id = nlm_core_id();
bucket_sizes = xlr_board_fmn_config.bucket_size;
cpu_fmn_info = &xlr_board_fmn_config.cpu[id];
flags = nlm_cop2_enable_irqsave();
nlm_write_c2_bucksize(0, bucket_sizes[id * 8 + 0]);
nlm_write_c2_bucksize(1, bucket_sizes[id * 8 + 1]);
nlm_write_c2_bucksize(2, bucket_sizes[id * 8 + 2]);
nlm_write_c2_bucksize(3, bucket_sizes[id * 8 + 3]);
nlm_write_c2_bucksize(4, bucket_sizes[id * 8 + 4]);
nlm_write_c2_bucksize(5, bucket_sizes[id * 8 + 5]);
nlm_write_c2_bucksize(6, bucket_sizes[id * 8 + 6]);
nlm_write_c2_bucksize(7, bucket_sizes[id * 8 + 7]);
COP2_CC_INIT_CPU_DEST(0, cpu_fmn_info->credit_config);
COP2_CC_INIT_CPU_DEST(1, cpu_fmn_info->credit_config);
COP2_CC_INIT_CPU_DEST(2, cpu_fmn_info->credit_config);
COP2_CC_INIT_CPU_DEST(3, cpu_fmn_info->credit_config);
COP2_CC_INIT_CPU_DEST(4, cpu_fmn_info->credit_config);
COP2_CC_INIT_CPU_DEST(5, cpu_fmn_info->credit_config);
COP2_CC_INIT_CPU_DEST(6, cpu_fmn_info->credit_config);
COP2_CC_INIT_CPU_DEST(7, cpu_fmn_info->credit_config);
COP2_CC_INIT_CPU_DEST(8, cpu_fmn_info->credit_config);
COP2_CC_INIT_CPU_DEST(9, cpu_fmn_info->credit_config);
COP2_CC_INIT_CPU_DEST(10, cpu_fmn_info->credit_config);
COP2_CC_INIT_CPU_DEST(11, cpu_fmn_info->credit_config);
COP2_CC_INIT_CPU_DEST(12, cpu_fmn_info->credit_config);
COP2_CC_INIT_CPU_DEST(13, cpu_fmn_info->credit_config);
COP2_CC_INIT_CPU_DEST(14, cpu_fmn_info->credit_config);
COP2_CC_INIT_CPU_DEST(15, cpu_fmn_info->credit_config);
nlm_fmn_setup_intr(IRQ_FMN, (1 << nlm_threads_per_core) - 1);
nlm_cop2_disable_irqrestore(flags);
}
int nlm_register_fmn_handler(int start_stnid, int end_stnid,
void (*action)(int, int, int, int, struct nlm_fmn_msg *, void *),
void *arg)
{
int sstnid;
for (sstnid = start_stnid; sstnid <= end_stnid; sstnid++) {
msg_handlers[sstnid].arg = arg;
smp_wmb();
msg_handlers[sstnid].action = action;
}
pr_debug("Registered FMN msg handler for stnid %d-%d\n",
start_stnid, end_stnid);
return 0;
}
void nlm_setup_fmn_irq(void)
{
uint32_t flags;
setup_irq(IRQ_FMN, &fmn_irqaction);
flags = nlm_cop2_enable_irqsave();
nlm_fmn_setup_intr(IRQ_FMN, (1 << nlm_threads_per_core) - 1);
nlm_cop2_disable_irqrestore(flags);
}
