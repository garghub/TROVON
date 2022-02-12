static void klp_transition_work_fn(struct work_struct *work)
{
mutex_lock(&klp_mutex);
if (klp_transition_patch)
klp_try_complete_transition();
mutex_unlock(&klp_mutex);
}
static void klp_sync(struct work_struct *work)
{
}
static void klp_synchronize_transition(void)
{
schedule_on_each_cpu(klp_sync);
}
static void klp_complete_transition(void)
{
struct klp_object *obj;
struct klp_func *func;
struct task_struct *g, *task;
unsigned int cpu;
bool immediate_func = false;
if (klp_target_state == KLP_UNPATCHED) {
klp_unpatch_objects(klp_transition_patch);
klp_synchronize_transition();
}
if (klp_transition_patch->immediate)
goto done;
klp_for_each_object(klp_transition_patch, obj) {
klp_for_each_func(obj, func) {
func->transition = false;
if (func->immediate)
immediate_func = true;
}
}
if (klp_target_state == KLP_UNPATCHED && !immediate_func)
module_put(klp_transition_patch->mod);
if (klp_target_state == KLP_PATCHED)
klp_synchronize_transition();
read_lock(&tasklist_lock);
for_each_process_thread(g, task) {
WARN_ON_ONCE(test_tsk_thread_flag(task, TIF_PATCH_PENDING));
task->patch_state = KLP_UNDEFINED;
}
read_unlock(&tasklist_lock);
for_each_possible_cpu(cpu) {
task = idle_task(cpu);
WARN_ON_ONCE(test_tsk_thread_flag(task, TIF_PATCH_PENDING));
task->patch_state = KLP_UNDEFINED;
}
done:
klp_target_state = KLP_UNDEFINED;
klp_transition_patch = NULL;
}
void klp_cancel_transition(void)
{
if (WARN_ON_ONCE(klp_target_state != KLP_PATCHED))
return;
klp_target_state = KLP_UNPATCHED;
klp_complete_transition();
}
void klp_update_patch_state(struct task_struct *task)
{
preempt_disable_notrace();
if (test_and_clear_tsk_thread_flag(task, TIF_PATCH_PENDING))
task->patch_state = READ_ONCE(klp_target_state);
preempt_enable_notrace();
}
static int klp_check_stack_func(struct klp_func *func,
struct stack_trace *trace)
{
unsigned long func_addr, func_size, address;
struct klp_ops *ops;
int i;
if (func->immediate)
return 0;
for (i = 0; i < trace->nr_entries; i++) {
address = trace->entries[i];
if (klp_target_state == KLP_UNPATCHED) {
func_addr = (unsigned long)func->new_func;
func_size = func->new_size;
} else {
ops = klp_find_ops(func->old_addr);
if (list_is_singular(&ops->func_stack)) {
func_addr = func->old_addr;
func_size = func->old_size;
} else {
struct klp_func *prev;
prev = list_next_entry(func, stack_node);
func_addr = (unsigned long)prev->new_func;
func_size = prev->new_size;
}
}
if (address >= func_addr && address < func_addr + func_size)
return -EAGAIN;
}
return 0;
}
static int klp_check_stack(struct task_struct *task, char *err_buf)
{
static unsigned long entries[MAX_STACK_ENTRIES];
struct stack_trace trace;
struct klp_object *obj;
struct klp_func *func;
int ret;
trace.skip = 0;
trace.nr_entries = 0;
trace.max_entries = MAX_STACK_ENTRIES;
trace.entries = entries;
ret = save_stack_trace_tsk_reliable(task, &trace);
WARN_ON_ONCE(ret == -ENOSYS);
if (ret) {
snprintf(err_buf, STACK_ERR_BUF_SIZE,
"%s: %s:%d has an unreliable stack\n",
__func__, task->comm, task->pid);
return ret;
}
klp_for_each_object(klp_transition_patch, obj) {
if (!obj->patched)
continue;
klp_for_each_func(obj, func) {
ret = klp_check_stack_func(func, &trace);
if (ret) {
snprintf(err_buf, STACK_ERR_BUF_SIZE,
"%s: %s:%d is sleeping on function %s\n",
__func__, task->comm, task->pid,
func->old_name);
return ret;
}
}
}
return 0;
}
static bool klp_try_switch_task(struct task_struct *task)
{
struct rq *rq;
struct rq_flags flags;
int ret;
bool success = false;
char err_buf[STACK_ERR_BUF_SIZE];
err_buf[0] = '\0';
if (task->patch_state == klp_target_state)
return true;
if (!klp_have_reliable_stack())
return false;
rq = task_rq_lock(task, &flags);
if (task_running(rq, task) && task != current) {
snprintf(err_buf, STACK_ERR_BUF_SIZE,
"%s: %s:%d is running\n", __func__, task->comm,
task->pid);
goto done;
}
ret = klp_check_stack(task, err_buf);
if (ret)
goto done;
success = true;
clear_tsk_thread_flag(task, TIF_PATCH_PENDING);
task->patch_state = klp_target_state;
done:
task_rq_unlock(rq, task, &flags);
if (err_buf[0] != '\0')
pr_debug("%s", err_buf);
return success;
}
void klp_try_complete_transition(void)
{
unsigned int cpu;
struct task_struct *g, *task;
bool complete = true;
WARN_ON_ONCE(klp_target_state == KLP_UNDEFINED);
if (klp_transition_patch->immediate)
goto success;
read_lock(&tasklist_lock);
for_each_process_thread(g, task)
if (!klp_try_switch_task(task))
complete = false;
read_unlock(&tasklist_lock);
get_online_cpus();
for_each_possible_cpu(cpu) {
task = idle_task(cpu);
if (cpu_online(cpu)) {
if (!klp_try_switch_task(task))
complete = false;
} else if (task->patch_state != klp_target_state) {
clear_tsk_thread_flag(task, TIF_PATCH_PENDING);
task->patch_state = klp_target_state;
}
}
put_online_cpus();
if (!complete) {
schedule_delayed_work(&klp_transition_work,
round_jiffies_relative(HZ));
return;
}
success:
pr_notice("'%s': %s complete\n", klp_transition_patch->mod->name,
klp_target_state == KLP_PATCHED ? "patching" : "unpatching");
klp_complete_transition();
}
void klp_start_transition(void)
{
struct task_struct *g, *task;
unsigned int cpu;
WARN_ON_ONCE(klp_target_state == KLP_UNDEFINED);
pr_notice("'%s': %s...\n", klp_transition_patch->mod->name,
klp_target_state == KLP_PATCHED ? "patching" : "unpatching");
if (klp_transition_patch->immediate)
return;
read_lock(&tasklist_lock);
for_each_process_thread(g, task)
if (task->patch_state != klp_target_state)
set_tsk_thread_flag(task, TIF_PATCH_PENDING);
read_unlock(&tasklist_lock);
for_each_possible_cpu(cpu) {
task = idle_task(cpu);
if (task->patch_state != klp_target_state)
set_tsk_thread_flag(task, TIF_PATCH_PENDING);
}
}
void klp_init_transition(struct klp_patch *patch, int state)
{
struct task_struct *g, *task;
unsigned int cpu;
struct klp_object *obj;
struct klp_func *func;
int initial_state = !state;
WARN_ON_ONCE(klp_target_state != KLP_UNDEFINED);
klp_transition_patch = patch;
klp_target_state = state;
if (patch->immediate)
return;
read_lock(&tasklist_lock);
for_each_process_thread(g, task) {
WARN_ON_ONCE(task->patch_state != KLP_UNDEFINED);
task->patch_state = initial_state;
}
read_unlock(&tasklist_lock);
for_each_possible_cpu(cpu) {
task = idle_task(cpu);
WARN_ON_ONCE(task->patch_state != KLP_UNDEFINED);
task->patch_state = initial_state;
}
smp_wmb();
klp_for_each_object(patch, obj)
klp_for_each_func(obj, func)
func->transition = true;
}
void klp_reverse_transition(void)
{
unsigned int cpu;
struct task_struct *g, *task;
klp_transition_patch->enabled = !klp_transition_patch->enabled;
klp_target_state = !klp_target_state;
read_lock(&tasklist_lock);
for_each_process_thread(g, task)
clear_tsk_thread_flag(task, TIF_PATCH_PENDING);
read_unlock(&tasklist_lock);
for_each_possible_cpu(cpu)
clear_tsk_thread_flag(idle_task(cpu), TIF_PATCH_PENDING);
klp_synchronize_transition();
klp_start_transition();
}
void klp_copy_process(struct task_struct *child)
{
child->patch_state = current->patch_state;
}
