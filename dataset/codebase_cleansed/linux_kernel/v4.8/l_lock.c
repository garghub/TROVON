struct ldlm_resource *lock_res_and_lock(struct ldlm_lock *lock)
{
spin_lock(&lock->l_lock);
lock_res(lock->l_resource);
ldlm_set_res_locked(lock);
return lock->l_resource;
}
void unlock_res_and_lock(struct ldlm_lock *lock)
{
ldlm_clear_res_locked(lock);
unlock_res(lock->l_resource);
spin_unlock(&lock->l_lock);
}
