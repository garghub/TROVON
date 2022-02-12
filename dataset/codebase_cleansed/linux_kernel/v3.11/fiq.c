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
void *base = vectors_page;
unsigned offset = FIQ_OFFSET;
memcpy(base + offset, start, length);
if (!cache_is_vipt_nonaliasing())
flush_icache_range((unsigned long)base + offset, offset +
length);
flush_icache_range(0xffff0000 + offset, 0xffff0000 + offset + length);
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
enable_irq(fiq + fiq_start);
}
void disable_fiq(int fiq)
{
disable_irq(fiq + fiq_start);
}
void __init init_FIQ(int start)
{
unsigned offset = FIQ_OFFSET;
no_fiq_insn = *(unsigned long *)(0xffff0000 + offset);
fiq_start = start;
}
