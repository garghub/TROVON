int __percpu_init_rwsem(struct percpu_rw_semaphore *brw,
const char *name, struct lock_class_key *rwsem_key)
{
brw->fast_read_ctr = alloc_percpu(int);
if (unlikely(!brw->fast_read_ctr))
return -ENOMEM;
__init_rwsem(&brw->rw_sem, name, rwsem_key);
atomic_set(&brw->write_ctr, 0);
atomic_set(&brw->slow_read_ctr, 0);
init_waitqueue_head(&brw->write_waitq);
return 0;
}
void percpu_free_rwsem(struct percpu_rw_semaphore *brw)
{
free_percpu(brw->fast_read_ctr);
brw->fast_read_ctr = NULL;
}
static bool update_fast_ctr(struct percpu_rw_semaphore *brw, unsigned int val)
{
bool success = false;
preempt_disable();
if (likely(!atomic_read(&brw->write_ctr))) {
__this_cpu_add(*brw->fast_read_ctr, val);
success = true;
}
preempt_enable();
return success;
}
void percpu_down_read(struct percpu_rw_semaphore *brw)
{
might_sleep();
if (likely(update_fast_ctr(brw, +1))) {
rwsem_acquire_read(&brw->rw_sem.dep_map, 0, 0, _RET_IP_);
return;
}
down_read(&brw->rw_sem);
atomic_inc(&brw->slow_read_ctr);
__up_read(&brw->rw_sem);
}
int percpu_down_read_trylock(struct percpu_rw_semaphore *brw)
{
if (unlikely(!update_fast_ctr(brw, +1))) {
if (!__down_read_trylock(&brw->rw_sem))
return 0;
atomic_inc(&brw->slow_read_ctr);
__up_read(&brw->rw_sem);
}
rwsem_acquire_read(&brw->rw_sem.dep_map, 0, 1, _RET_IP_);
return 1;
}
void percpu_up_read(struct percpu_rw_semaphore *brw)
{
rwsem_release(&brw->rw_sem.dep_map, 1, _RET_IP_);
if (likely(update_fast_ctr(brw, -1)))
return;
if (atomic_dec_and_test(&brw->slow_read_ctr))
wake_up_all(&brw->write_waitq);
}
static int clear_fast_ctr(struct percpu_rw_semaphore *brw)
{
unsigned int sum = 0;
int cpu;
for_each_possible_cpu(cpu) {
sum += per_cpu(*brw->fast_read_ctr, cpu);
per_cpu(*brw->fast_read_ctr, cpu) = 0;
}
return sum;
}
void percpu_down_write(struct percpu_rw_semaphore *brw)
{
atomic_inc(&brw->write_ctr);
synchronize_sched_expedited();
down_write(&brw->rw_sem);
atomic_add(clear_fast_ctr(brw), &brw->slow_read_ctr);
wait_event(brw->write_waitq, !atomic_read(&brw->slow_read_ctr));
}
void percpu_up_write(struct percpu_rw_semaphore *brw)
{
up_write(&brw->rw_sem);
synchronize_sched_expedited();
atomic_dec(&brw->write_ctr);
}
