int __percpu_init_rwsem(struct percpu_rw_semaphore *sem,
const char *name, struct lock_class_key *rwsem_key)
{
sem->read_count = alloc_percpu(int);
if (unlikely(!sem->read_count))
return -ENOMEM;
rcu_sync_init(&sem->rss, RCU_SCHED_SYNC);
__init_rwsem(&sem->rw_sem, name, rwsem_key);
init_waitqueue_head(&sem->writer);
sem->readers_block = 0;
return 0;
}
void percpu_free_rwsem(struct percpu_rw_semaphore *sem)
{
if (!sem->read_count)
return;
rcu_sync_dtor(&sem->rss);
free_percpu(sem->read_count);
sem->read_count = NULL;
}
int __percpu_down_read(struct percpu_rw_semaphore *sem, int try)
{
smp_mb();
if (likely(!smp_load_acquire(&sem->readers_block)))
return 1;
__percpu_up_read(sem);
if (try)
return 0;
preempt_enable_no_resched();
__down_read(&sem->rw_sem);
this_cpu_inc(*sem->read_count);
__up_read(&sem->rw_sem);
preempt_disable();
return 1;
}
void __percpu_up_read(struct percpu_rw_semaphore *sem)
{
smp_mb();
__this_cpu_dec(*sem->read_count);
wake_up(&sem->writer);
}
static bool readers_active_check(struct percpu_rw_semaphore *sem)
{
if (per_cpu_sum(*sem->read_count) != 0)
return false;
smp_mb();
return true;
}
void percpu_down_write(struct percpu_rw_semaphore *sem)
{
rcu_sync_enter(&sem->rss);
down_write(&sem->rw_sem);
WRITE_ONCE(sem->readers_block, 1);
smp_mb();
wait_event(sem->writer, readers_active_check(sem));
}
void percpu_up_write(struct percpu_rw_semaphore *sem)
{
smp_store_release(&sem->readers_block, 0);
up_write(&sem->rw_sem);
rcu_sync_exit(&sem->rss);
}
