static int show_irq_affinity(int type, struct seq_file *m)
{
struct irq_desc *desc = irq_to_desc((long)m->private);
const struct cpumask *mask;
switch (type) {
case AFFINITY:
case AFFINITY_LIST:
mask = desc->irq_common_data.affinity;
#ifdef CONFIG_GENERIC_PENDING_IRQ
if (irqd_is_setaffinity_pending(&desc->irq_data))
mask = desc->pending_mask;
#endif
break;
case EFFECTIVE:
case EFFECTIVE_LIST:
#ifdef CONFIG_GENERIC_IRQ_EFFECTIVE_AFF_MASK
mask = irq_data_get_effective_affinity_mask(&desc->irq_data);
break;
#endif
default:
return -EINVAL;
}
switch (type) {
case AFFINITY_LIST:
case EFFECTIVE_LIST:
seq_printf(m, "%*pbl\n", cpumask_pr_args(mask));
break;
case AFFINITY:
case EFFECTIVE:
seq_printf(m, "%*pb\n", cpumask_pr_args(mask));
break;
}
return 0;
}
static int irq_affinity_hint_proc_show(struct seq_file *m, void *v)
{
struct irq_desc *desc = irq_to_desc((long)m->private);
unsigned long flags;
cpumask_var_t mask;
if (!zalloc_cpumask_var(&mask, GFP_KERNEL))
return -ENOMEM;
raw_spin_lock_irqsave(&desc->lock, flags);
if (desc->affinity_hint)
cpumask_copy(mask, desc->affinity_hint);
raw_spin_unlock_irqrestore(&desc->lock, flags);
seq_printf(m, "%*pb\n", cpumask_pr_args(mask));
free_cpumask_var(mask);
return 0;
}
static int irq_affinity_proc_show(struct seq_file *m, void *v)
{
return show_irq_affinity(AFFINITY, m);
}
static int irq_affinity_list_proc_show(struct seq_file *m, void *v)
{
return show_irq_affinity(AFFINITY_LIST, m);
}
static ssize_t write_irq_affinity(int type, struct file *file,
const char __user *buffer, size_t count, loff_t *pos)
{
unsigned int irq = (int)(long)PDE_DATA(file_inode(file));
cpumask_var_t new_value;
int err;
if (!irq_can_set_affinity_usr(irq) || no_irq_affinity)
return -EIO;
if (!alloc_cpumask_var(&new_value, GFP_KERNEL))
return -ENOMEM;
if (type)
err = cpumask_parselist_user(buffer, count, new_value);
else
err = cpumask_parse_user(buffer, count, new_value);
if (err)
goto free_cpumask;
if (!is_affinity_mask_valid(new_value)) {
err = -EINVAL;
goto free_cpumask;
}
if (!cpumask_intersects(new_value, cpu_online_mask)) {
err = irq_select_affinity_usr(irq) ? -EINVAL : count;
} else {
irq_set_affinity(irq, new_value);
err = count;
}
free_cpumask:
free_cpumask_var(new_value);
return err;
}
static ssize_t irq_affinity_proc_write(struct file *file,
const char __user *buffer, size_t count, loff_t *pos)
{
return write_irq_affinity(0, file, buffer, count, pos);
}
static ssize_t irq_affinity_list_proc_write(struct file *file,
const char __user *buffer, size_t count, loff_t *pos)
{
return write_irq_affinity(1, file, buffer, count, pos);
}
static int irq_affinity_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, irq_affinity_proc_show, PDE_DATA(inode));
}
static int irq_affinity_list_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, irq_affinity_list_proc_show, PDE_DATA(inode));
}
static int irq_affinity_hint_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, irq_affinity_hint_proc_show, PDE_DATA(inode));
}
static int irq_effective_aff_proc_show(struct seq_file *m, void *v)
{
return show_irq_affinity(EFFECTIVE, m);
}
static int irq_effective_aff_list_proc_show(struct seq_file *m, void *v)
{
return show_irq_affinity(EFFECTIVE_LIST, m);
}
static int irq_effective_aff_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, irq_effective_aff_proc_show, PDE_DATA(inode));
}
static int irq_effective_aff_list_proc_open(struct inode *inode,
struct file *file)
{
return single_open(file, irq_effective_aff_list_proc_show,
PDE_DATA(inode));
}
static int default_affinity_show(struct seq_file *m, void *v)
{
seq_printf(m, "%*pb\n", cpumask_pr_args(irq_default_affinity));
return 0;
}
static ssize_t default_affinity_write(struct file *file,
const char __user *buffer, size_t count, loff_t *ppos)
{
cpumask_var_t new_value;
int err;
if (!alloc_cpumask_var(&new_value, GFP_KERNEL))
return -ENOMEM;
err = cpumask_parse_user(buffer, count, new_value);
if (err)
goto out;
if (!is_affinity_mask_valid(new_value)) {
err = -EINVAL;
goto out;
}
if (!cpumask_intersects(new_value, cpu_online_mask)) {
err = -EINVAL;
goto out;
}
cpumask_copy(irq_default_affinity, new_value);
err = count;
out:
free_cpumask_var(new_value);
return err;
}
static int default_affinity_open(struct inode *inode, struct file *file)
{
return single_open(file, default_affinity_show, PDE_DATA(inode));
}
static int irq_node_proc_show(struct seq_file *m, void *v)
{
struct irq_desc *desc = irq_to_desc((long) m->private);
seq_printf(m, "%d\n", irq_desc_get_node(desc));
return 0;
}
static int irq_node_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, irq_node_proc_show, PDE_DATA(inode));
}
static int irq_spurious_proc_show(struct seq_file *m, void *v)
{
struct irq_desc *desc = irq_to_desc((long) m->private);
seq_printf(m, "count %u\n" "unhandled %u\n" "last_unhandled %u ms\n",
desc->irq_count, desc->irqs_unhandled,
jiffies_to_msecs(desc->last_unhandled));
return 0;
}
static int irq_spurious_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, irq_spurious_proc_show, PDE_DATA(inode));
}
static int name_unique(unsigned int irq, struct irqaction *new_action)
{
struct irq_desc *desc = irq_to_desc(irq);
struct irqaction *action;
unsigned long flags;
int ret = 1;
raw_spin_lock_irqsave(&desc->lock, flags);
for_each_action_of_desc(desc, action) {
if ((action != new_action) && action->name &&
!strcmp(new_action->name, action->name)) {
ret = 0;
break;
}
}
raw_spin_unlock_irqrestore(&desc->lock, flags);
return ret;
}
void register_handler_proc(unsigned int irq, struct irqaction *action)
{
char name [MAX_NAMELEN];
struct irq_desc *desc = irq_to_desc(irq);
if (!desc->dir || action->dir || !action->name ||
!name_unique(irq, action))
return;
snprintf(name, MAX_NAMELEN, "%s", action->name);
action->dir = proc_mkdir(name, desc->dir);
}
void register_irq_proc(unsigned int irq, struct irq_desc *desc)
{
static DEFINE_MUTEX(register_lock);
void __maybe_unused *irqp = (void *)(unsigned long) irq;
char name [MAX_NAMELEN];
if (!root_irq_dir || (desc->irq_data.chip == &no_irq_chip))
return;
mutex_lock(&register_lock);
if (desc->dir)
goto out_unlock;
sprintf(name, "%d", irq);
desc->dir = proc_mkdir(name, root_irq_dir);
if (!desc->dir)
goto out_unlock;
#ifdef CONFIG_SMP
proc_create_data("smp_affinity", 0644, desc->dir,
&irq_affinity_proc_fops, irqp);
proc_create_data("affinity_hint", 0444, desc->dir,
&irq_affinity_hint_proc_fops, irqp);
proc_create_data("smp_affinity_list", 0644, desc->dir,
&irq_affinity_list_proc_fops, irqp);
proc_create_data("node", 0444, desc->dir,
&irq_node_proc_fops, irqp);
# ifdef CONFIG_GENERIC_IRQ_EFFECTIVE_AFF_MASK
proc_create_data("effective_affinity", 0444, desc->dir,
&irq_effective_aff_proc_fops, irqp);
proc_create_data("effective_affinity_list", 0444, desc->dir,
&irq_effective_aff_list_proc_fops, irqp);
# endif
#endif
proc_create_data("spurious", 0444, desc->dir,
&irq_spurious_proc_fops, (void *)(long)irq);
out_unlock:
mutex_unlock(&register_lock);
}
void unregister_irq_proc(unsigned int irq, struct irq_desc *desc)
{
char name [MAX_NAMELEN];
if (!root_irq_dir || !desc->dir)
return;
#ifdef CONFIG_SMP
remove_proc_entry("smp_affinity", desc->dir);
remove_proc_entry("affinity_hint", desc->dir);
remove_proc_entry("smp_affinity_list", desc->dir);
remove_proc_entry("node", desc->dir);
# ifdef CONFIG_GENERIC_IRQ_EFFECTIVE_AFF_MASK
remove_proc_entry("effective_affinity", desc->dir);
remove_proc_entry("effective_affinity_list", desc->dir);
# endif
#endif
remove_proc_entry("spurious", desc->dir);
sprintf(name, "%u", irq);
remove_proc_entry(name, root_irq_dir);
}
void unregister_handler_proc(unsigned int irq, struct irqaction *action)
{
proc_remove(action->dir);
}
static void register_default_affinity_proc(void)
{
#ifdef CONFIG_SMP
proc_create("irq/default_smp_affinity", 0644, NULL,
&default_affinity_proc_fops);
#endif
}
void init_irq_proc(void)
{
unsigned int irq;
struct irq_desc *desc;
root_irq_dir = proc_mkdir("irq", NULL);
if (!root_irq_dir)
return;
register_default_affinity_proc();
for_each_irq_desc(irq, desc)
register_irq_proc(irq, desc);
}
int __weak arch_show_interrupts(struct seq_file *p, int prec)
{
return 0;
}
int show_interrupts(struct seq_file *p, void *v)
{
static int prec;
unsigned long flags, any_count = 0;
int i = *(loff_t *) v, j;
struct irqaction *action;
struct irq_desc *desc;
if (i > ACTUAL_NR_IRQS)
return 0;
if (i == ACTUAL_NR_IRQS)
return arch_show_interrupts(p, prec);
if (i == 0) {
for (prec = 3, j = 1000; prec < 10 && j <= nr_irqs; ++prec)
j *= 10;
seq_printf(p, "%*s", prec + 8, "");
for_each_online_cpu(j)
seq_printf(p, "CPU%-8d", j);
seq_putc(p, '\n');
}
irq_lock_sparse();
desc = irq_to_desc(i);
if (!desc)
goto outsparse;
raw_spin_lock_irqsave(&desc->lock, flags);
for_each_online_cpu(j)
any_count |= kstat_irqs_cpu(i, j);
action = desc->action;
if ((!action || irq_desc_is_chained(desc)) && !any_count)
goto out;
seq_printf(p, "%*d: ", prec, i);
for_each_online_cpu(j)
seq_printf(p, "%10u ", kstat_irqs_cpu(i, j));
if (desc->irq_data.chip) {
if (desc->irq_data.chip->irq_print_chip)
desc->irq_data.chip->irq_print_chip(&desc->irq_data, p);
else if (desc->irq_data.chip->name)
seq_printf(p, " %8s", desc->irq_data.chip->name);
else
seq_printf(p, " %8s", "-");
} else {
seq_printf(p, " %8s", "None");
}
if (desc->irq_data.domain)
seq_printf(p, " %*d", prec, (int) desc->irq_data.hwirq);
else
seq_printf(p, " %*s", prec, "");
#ifdef CONFIG_GENERIC_IRQ_SHOW_LEVEL
seq_printf(p, " %-8s", irqd_is_level_type(&desc->irq_data) ? "Level" : "Edge");
#endif
if (desc->name)
seq_printf(p, "-%-8s", desc->name);
if (action) {
seq_printf(p, " %s", action->name);
while ((action = action->next) != NULL)
seq_printf(p, ", %s", action->name);
}
seq_putc(p, '\n');
out:
raw_spin_unlock_irqrestore(&desc->lock, flags);
outsparse:
irq_unlock_sparse();
return 0;
}
