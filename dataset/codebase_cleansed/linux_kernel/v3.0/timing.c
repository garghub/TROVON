void kvmppc_init_timing_stats(struct kvm_vcpu *vcpu)
{
int i;
mutex_lock(&vcpu->arch.exit_timing_lock);
vcpu->arch.last_exit_type = 0xDEAD;
for (i = 0; i < __NUMBER_OF_KVM_EXIT_TYPES; i++) {
vcpu->arch.timing_count_type[i] = 0;
vcpu->arch.timing_max_duration[i] = 0;
vcpu->arch.timing_min_duration[i] = 0xFFFFFFFF;
vcpu->arch.timing_sum_duration[i] = 0;
vcpu->arch.timing_sum_quad_duration[i] = 0;
}
vcpu->arch.timing_last_exit = 0;
vcpu->arch.timing_exit.tv64 = 0;
vcpu->arch.timing_last_enter.tv64 = 0;
mutex_unlock(&vcpu->arch.exit_timing_lock);
}
static void add_exit_timing(struct kvm_vcpu *vcpu, u64 duration, int type)
{
u64 old;
do_div(duration, tb_ticks_per_usec);
if (unlikely(duration > 0xFFFFFFFF)) {
printk(KERN_ERR"%s - duration too big -> overflow"
" duration %lld type %d exit #%d\n",
__func__, duration, type,
vcpu->arch.timing_count_type[type]);
return;
}
mutex_lock(&vcpu->arch.exit_timing_lock);
vcpu->arch.timing_count_type[type]++;
old = vcpu->arch.timing_sum_duration[type];
vcpu->arch.timing_sum_duration[type] += duration;
if (unlikely(old > vcpu->arch.timing_sum_duration[type])) {
printk(KERN_ERR"%s - wrap adding sum of durations"
" old %lld new %lld type %d exit # of type %d\n",
__func__, old, vcpu->arch.timing_sum_duration[type],
type, vcpu->arch.timing_count_type[type]);
}
old = vcpu->arch.timing_sum_quad_duration[type];
vcpu->arch.timing_sum_quad_duration[type] += (duration*duration);
if (unlikely(old > vcpu->arch.timing_sum_quad_duration[type])) {
printk(KERN_ERR"%s - wrap adding sum of squared durations"
" old %lld new %lld type %d exit # of type %d\n",
__func__, old,
vcpu->arch.timing_sum_quad_duration[type],
type, vcpu->arch.timing_count_type[type]);
}
if (unlikely(duration < vcpu->arch.timing_min_duration[type]))
vcpu->arch.timing_min_duration[type] = duration;
if (unlikely(duration > vcpu->arch.timing_max_duration[type]))
vcpu->arch.timing_max_duration[type] = duration;
mutex_unlock(&vcpu->arch.exit_timing_lock);
}
void kvmppc_update_timing_stats(struct kvm_vcpu *vcpu)
{
u64 exit = vcpu->arch.timing_last_exit;
u64 enter = vcpu->arch.timing_last_enter.tv64;
vcpu->arch.timing_last_exit = vcpu->arch.timing_exit.tv64;
if (unlikely(vcpu->arch.last_exit_type == 0xDEAD || exit == 0))
return;
add_exit_timing(vcpu, (enter - exit), vcpu->arch.last_exit_type);
add_exit_timing(vcpu, (vcpu->arch.timing_last_exit - enter),
TIMEINGUEST);
}
static int kvmppc_exit_timing_show(struct seq_file *m, void *private)
{
struct kvm_vcpu *vcpu = m->private;
int i;
u64 min, max, sum, sum_quad;
seq_printf(m, "%s", "type count min max sum sum_squared\n");
for (i = 0; i < __NUMBER_OF_KVM_EXIT_TYPES; i++) {
min = vcpu->arch.timing_min_duration[i];
do_div(min, tb_ticks_per_usec);
max = vcpu->arch.timing_max_duration[i];
do_div(max, tb_ticks_per_usec);
sum = vcpu->arch.timing_sum_duration[i];
do_div(sum, tb_ticks_per_usec);
sum_quad = vcpu->arch.timing_sum_quad_duration[i];
do_div(sum_quad, tb_ticks_per_usec);
seq_printf(m, "%12s %10d %10lld %10lld %20lld %20lld\n",
kvm_exit_names[i],
vcpu->arch.timing_count_type[i],
min,
max,
sum,
sum_quad);
}
return 0;
}
static ssize_t kvmppc_exit_timing_write(struct file *file,
const char __user *user_buf,
size_t count, loff_t *ppos)
{
int err = -EINVAL;
char c;
if (count > 1) {
goto done;
}
if (get_user(c, user_buf)) {
err = -EFAULT;
goto done;
}
if (c == 'c') {
struct seq_file *seqf = file->private_data;
struct kvm_vcpu *vcpu = seqf->private;
mutex_lock(&seqf->lock);
kvmppc_init_timing_stats(vcpu);
mutex_unlock(&seqf->lock);
err = count;
}
done:
return err;
}
static int kvmppc_exit_timing_open(struct inode *inode, struct file *file)
{
return single_open(file, kvmppc_exit_timing_show, inode->i_private);
}
void kvmppc_create_vcpu_debugfs(struct kvm_vcpu *vcpu, unsigned int id)
{
static char dbg_fname[50];
struct dentry *debugfs_file;
snprintf(dbg_fname, sizeof(dbg_fname), "vm%u_vcpu%u_timing",
current->pid, id);
debugfs_file = debugfs_create_file(dbg_fname, 0666,
kvm_debugfs_dir, vcpu,
&kvmppc_exit_timing_fops);
if (!debugfs_file) {
printk(KERN_ERR"%s: error creating debugfs file %s\n",
__func__, dbg_fname);
return;
}
vcpu->arch.debugfs_exit_timing = debugfs_file;
}
void kvmppc_remove_vcpu_debugfs(struct kvm_vcpu *vcpu)
{
if (vcpu->arch.debugfs_exit_timing) {
debugfs_remove(vcpu->arch.debugfs_exit_timing);
vcpu->arch.debugfs_exit_timing = NULL;
}
}
