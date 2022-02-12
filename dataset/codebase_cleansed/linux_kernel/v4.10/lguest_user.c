static int getreg_setup(struct lg_cpu *cpu, const unsigned long __user *input)
{
unsigned long which;
if (get_user(which, input) != 0)
return -EFAULT;
cpu->reg_read = lguest_arch_regptr(cpu, which, true);
if (!cpu->reg_read)
return -ENOENT;
return sizeof(unsigned long) * 2;
}
static int setreg(struct lg_cpu *cpu, const unsigned long __user *input)
{
unsigned long which, value, *reg;
if (get_user(which, input) != 0)
return -EFAULT;
input++;
if (get_user(value, input) != 0)
return -EFAULT;
reg = lguest_arch_regptr(cpu, which, false);
if (!reg)
return -ENOENT;
*reg = value;
return sizeof(unsigned long) * 3;
}
static int user_send_irq(struct lg_cpu *cpu, const unsigned long __user *input)
{
unsigned long irq;
if (get_user(irq, input) != 0)
return -EFAULT;
if (irq >= LGUEST_IRQS)
return -EINVAL;
set_interrupt(cpu, irq);
return 0;
}
static int trap(struct lg_cpu *cpu, const unsigned long __user *input)
{
unsigned long trapnum;
if (get_user(trapnum, input) != 0)
return -EFAULT;
if (!deliver_trap(cpu, trapnum))
return -EINVAL;
return 0;
}
static ssize_t read(struct file *file, char __user *user, size_t size,loff_t*o)
{
struct lguest *lg = file->private_data;
struct lg_cpu *cpu;
unsigned int cpu_id = *o;
if (!lg)
return -EINVAL;
if (cpu_id >= lg->nr_cpus)
return -EINVAL;
cpu = &lg->cpus[cpu_id];
if (current != cpu->tsk)
return -EPERM;
if (lg->dead) {
size_t len;
if (IS_ERR(lg->dead))
return PTR_ERR(lg->dead);
len = min(size, strlen(lg->dead)+1);
if (copy_to_user(user, lg->dead, len) != 0)
return -EFAULT;
return len;
}
if (cpu->pending.trap)
cpu->pending.trap = 0;
return run_guest(cpu, (unsigned long __user *)user);
}
static int lg_cpu_start(struct lg_cpu *cpu, unsigned id, unsigned long start_ip)
{
if (id >= ARRAY_SIZE(cpu->lg->cpus))
return -EINVAL;
cpu->id = id;
cpu->lg = container_of(cpu, struct lguest, cpus[id]);
cpu->lg->nr_cpus++;
init_clockdev(cpu);
cpu->regs_page = get_zeroed_page(GFP_KERNEL);
if (!cpu->regs_page)
return -ENOMEM;
cpu->regs = (void *)cpu->regs_page + PAGE_SIZE - sizeof(*cpu->regs);
lguest_arch_setup_regs(cpu, start_ip);
cpu->tsk = current;
cpu->mm = get_task_mm(cpu->tsk);
cpu->last_pages = NULL;
return 0;
}
static int initialize(struct file *file, const unsigned long __user *input)
{
struct lguest *lg;
int err;
unsigned long args[4];
mutex_lock(&lguest_lock);
if (file->private_data) {
err = -EBUSY;
goto unlock;
}
if (copy_from_user(args, input, sizeof(args)) != 0) {
err = -EFAULT;
goto unlock;
}
lg = kzalloc(sizeof(*lg), GFP_KERNEL);
if (!lg) {
err = -ENOMEM;
goto unlock;
}
lg->mem_base = (void __user *)args[0];
lg->pfn_limit = args[1];
lg->device_limit = args[3];
err = lg_cpu_start(&lg->cpus[0], 0, args[2]);
if (err)
goto free_lg;
err = init_guest_pagetable(lg);
if (err)
goto free_regs;
file->private_data = lg;
mutex_unlock(&lguest_lock);
return sizeof(args);
free_regs:
free_page(lg->cpus[0].regs_page);
free_lg:
kfree(lg);
unlock:
mutex_unlock(&lguest_lock);
return err;
}
static ssize_t write(struct file *file, const char __user *in,
size_t size, loff_t *off)
{
struct lguest *lg = file->private_data;
const unsigned long __user *input = (const unsigned long __user *)in;
unsigned long req;
struct lg_cpu *uninitialized_var(cpu);
unsigned int cpu_id = *off;
if (get_user(req, input) != 0)
return -EFAULT;
input++;
if (req != LHREQ_INITIALIZE) {
if (!lg || (cpu_id >= lg->nr_cpus))
return -EINVAL;
cpu = &lg->cpus[cpu_id];
if (lg->dead)
return -ENOENT;
}
switch (req) {
case LHREQ_INITIALIZE:
return initialize(file, input);
case LHREQ_IRQ:
return user_send_irq(cpu, input);
case LHREQ_GETREG:
return getreg_setup(cpu, input);
case LHREQ_SETREG:
return setreg(cpu, input);
case LHREQ_TRAP:
return trap(cpu, input);
default:
return -EINVAL;
}
}
static int open(struct inode *inode, struct file *file)
{
file->private_data = NULL;
return 0;
}
static int close(struct inode *inode, struct file *file)
{
struct lguest *lg = file->private_data;
unsigned int i;
if (!lg)
return 0;
mutex_lock(&lguest_lock);
free_guest_pagetable(lg);
for (i = 0; i < lg->nr_cpus; i++) {
hrtimer_cancel(&lg->cpus[i].hrt);
free_page(lg->cpus[i].regs_page);
mmput(lg->cpus[i].mm);
}
if (!IS_ERR(lg->dead))
kfree(lg->dead);
kfree(lg);
mutex_unlock(&lguest_lock);
return 0;
}
int __init lguest_device_init(void)
{
return misc_register(&lguest_dev);
}
void __exit lguest_device_remove(void)
{
misc_deregister(&lguest_dev);
}
