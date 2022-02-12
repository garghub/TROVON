int __rxe_do_task(struct rxe_task *task)
{
int ret;
while ((ret = task->func(task->arg)) == 0)
;
task->ret = ret;
return ret;
}
void rxe_do_task(unsigned long data)
{
int cont;
int ret;
unsigned long flags;
struct rxe_task *task = (struct rxe_task *)data;
spin_lock_irqsave(&task->state_lock, flags);
switch (task->state) {
case TASK_STATE_START:
task->state = TASK_STATE_BUSY;
spin_unlock_irqrestore(&task->state_lock, flags);
break;
case TASK_STATE_BUSY:
task->state = TASK_STATE_ARMED;
case TASK_STATE_ARMED:
spin_unlock_irqrestore(&task->state_lock, flags);
return;
default:
spin_unlock_irqrestore(&task->state_lock, flags);
pr_warn("bad state = %d in rxe_do_task\n", task->state);
return;
}
do {
cont = 0;
ret = task->func(task->arg);
spin_lock_irqsave(&task->state_lock, flags);
switch (task->state) {
case TASK_STATE_BUSY:
if (ret)
task->state = TASK_STATE_START;
else
cont = 1;
break;
case TASK_STATE_ARMED:
task->state = TASK_STATE_BUSY;
cont = 1;
break;
default:
pr_warn("bad state = %d in rxe_do_task\n",
task->state);
}
spin_unlock_irqrestore(&task->state_lock, flags);
} while (cont);
task->ret = ret;
}
int rxe_init_task(void *obj, struct rxe_task *task,
void *arg, int (*func)(void *), char *name)
{
task->obj = obj;
task->arg = arg;
task->func = func;
snprintf(task->name, sizeof(task->name), "%s", name);
task->destroyed = false;
tasklet_init(&task->tasklet, rxe_do_task, (unsigned long)task);
task->state = TASK_STATE_START;
spin_lock_init(&task->state_lock);
return 0;
}
void rxe_cleanup_task(struct rxe_task *task)
{
unsigned long flags;
bool idle;
task->destroyed = true;
do {
spin_lock_irqsave(&task->state_lock, flags);
idle = (task->state == TASK_STATE_START);
spin_unlock_irqrestore(&task->state_lock, flags);
} while (!idle);
tasklet_kill(&task->tasklet);
}
void rxe_run_task(struct rxe_task *task, int sched)
{
if (task->destroyed)
return;
if (sched)
tasklet_schedule(&task->tasklet);
else
rxe_do_task((unsigned long)task);
}
void rxe_disable_task(struct rxe_task *task)
{
tasklet_disable(&task->tasklet);
}
void rxe_enable_task(struct rxe_task *task)
{
tasklet_enable(&task->tasklet);
}
