struct ldlm_resource *lock_res_and_lock(struct ldlm_lock *lock)
{
spin_lock(&lock->l_lock);
lock_res(lock->l_resource);
lock->l_flags |= LDLM_FL_RES_LOCKED;
return lock->l_resource;
}
void unlock_res_and_lock(struct ldlm_lock *lock)
{
lock->l_flags &= ~LDLM_FL_RES_LOCKED;
unlock_res(lock->l_resource);
spin_unlock(&lock->l_lock);
}
