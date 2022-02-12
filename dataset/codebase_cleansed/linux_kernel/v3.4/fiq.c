static int fiq_def_op(void *ref, int relinquish)
{
if (!relinquish)
set_fiq_handler(&no_fiq_insn, sizeof(no_fiq_insn));
return 0;
}
int show_fiq_list(struct seq_file *p, int prec)
{
if (current_fiq != &default_owner)
seq_printf(p, "%*s: %s\n", prec, "FIQ",
current_fiq->name);
return 0;
}
void set_fiq_handler(void *start, unsigned int length)
{
#if defined(CONFIG_CPU_USE_DOMAINS)
memcpy((void *)0xffff001c, start, length);
#else
memcpy(vectors_page + 0x1c, start, length);
#endif
flush_icache_range(0xffff001c, 0xffff001c + length);
if (!vectors_high())
flush_icache_range(0x1c, 0x1c + length);
}
int claim_fiq(struct fiq_handler *f)
{
int ret = 0;
if (current_fiq) {
ret = -EBUSY;
if (current_fiq->fiq_op != NULL)
ret = current_fiq->fiq_op(current_fiq->dev_id, 1);
}
if (!ret) {
f->next = current_fiq;
current_fiq = f;
}
return ret;
}
void release_fiq(struct fiq_handler *f)
{
if (current_fiq != f) {
printk(KERN_ERR "%s FIQ trying to release %s FIQ\n",
f->name, current_fiq->name);
dump_stack();
return;
}
do
current_fiq = current_fiq->next;
while (current_fiq->fiq_op(current_fiq->dev_id, 0));
}
void enable_fiq(int fiq)
{
enable_irq(fiq + FIQ_START);
}
void disable_fiq(int fiq)
{
disable_irq(fiq + FIQ_START);
}
void __init init_FIQ(void)
{
no_fiq_insn = *(unsigned long *)0xffff001c;
}
