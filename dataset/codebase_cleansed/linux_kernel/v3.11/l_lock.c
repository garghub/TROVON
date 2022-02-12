struct ldlm_resource *lock_res_and_lock(struct ldlm_lock *lock)
{
if (!lock->l_ns_srv)
spin_lock(&lock->l_lock);
lock_res(lock->l_resource);
lock->l_res_locked = 1;
return lock->l_resource;
}
void unlock_res_and_lock(struct ldlm_lock *lock)
{
lock->l_res_locked = 0;
unlock_res(lock->l_resource);
if (!lock->l_ns_srv)
spin_unlock(&lock->l_lock);
}
