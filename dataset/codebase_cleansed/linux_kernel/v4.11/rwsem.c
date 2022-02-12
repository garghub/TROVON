void __sched down_read(struct rw_semaphore *sem)
{
might_sleep();
rwsem_acquire_read(&sem->dep_map, 0, 0, _RET_IP_);
LOCK_CONTENDED(sem, __down_read_trylock, __down_read);
rwsem_set_reader_owned(sem);
}
int down_read_trylock(struct rw_semaphore *sem)
{
int ret = __down_read_trylock(sem);
if (ret == 1) {
rwsem_acquire_read(&sem->dep_map, 0, 1, _RET_IP_);
rwsem_set_reader_owned(sem);
}
return ret;
}
void __sched down_write(struct rw_semaphore *sem)
{
might_sleep();
rwsem_acquire(&sem->dep_map, 0, 0, _RET_IP_);
LOCK_CONTENDED(sem, __down_write_trylock, __down_write);
rwsem_set_owner(sem);
}
int __sched down_write_killable(struct rw_semaphore *sem)
{
might_sleep();
rwsem_acquire(&sem->dep_map, 0, 0, _RET_IP_);
if (LOCK_CONTENDED_RETURN(sem, __down_write_trylock, __down_write_killable)) {
rwsem_release(&sem->dep_map, 1, _RET_IP_);
return -EINTR;
}
rwsem_set_owner(sem);
return 0;
}
int down_write_trylock(struct rw_semaphore *sem)
{
int ret = __down_write_trylock(sem);
if (ret == 1) {
rwsem_acquire(&sem->dep_map, 0, 1, _RET_IP_);
rwsem_set_owner(sem);
}
return ret;
}
void up_read(struct rw_semaphore *sem)
{
rwsem_release(&sem->dep_map, 1, _RET_IP_);
__up_read(sem);
}
void up_write(struct rw_semaphore *sem)
{
rwsem_release(&sem->dep_map, 1, _RET_IP_);
rwsem_clear_owner(sem);
__up_write(sem);
}
void downgrade_write(struct rw_semaphore *sem)
{
rwsem_set_reader_owned(sem);
__downgrade_write(sem);
}
void down_read_nested(struct rw_semaphore *sem, int subclass)
{
might_sleep();
rwsem_acquire_read(&sem->dep_map, subclass, 0, _RET_IP_);
LOCK_CONTENDED(sem, __down_read_trylock, __down_read);
rwsem_set_reader_owned(sem);
}
void _down_write_nest_lock(struct rw_semaphore *sem, struct lockdep_map *nest)
{
might_sleep();
rwsem_acquire_nest(&sem->dep_map, 0, 0, nest, _RET_IP_);
LOCK_CONTENDED(sem, __down_write_trylock, __down_write);
rwsem_set_owner(sem);
}
void down_read_non_owner(struct rw_semaphore *sem)
{
might_sleep();
__down_read(sem);
}
void down_write_nested(struct rw_semaphore *sem, int subclass)
{
might_sleep();
rwsem_acquire(&sem->dep_map, subclass, 0, _RET_IP_);
LOCK_CONTENDED(sem, __down_write_trylock, __down_write);
rwsem_set_owner(sem);
}
int __sched down_write_killable_nested(struct rw_semaphore *sem, int subclass)
{
might_sleep();
rwsem_acquire(&sem->dep_map, subclass, 0, _RET_IP_);
if (LOCK_CONTENDED_RETURN(sem, __down_write_trylock, __down_write_killable)) {
rwsem_release(&sem->dep_map, 1, _RET_IP_);
return -EINTR;
}
rwsem_set_owner(sem);
return 0;
}
void up_read_non_owner(struct rw_semaphore *sem)
{
__up_read(sem);
}
