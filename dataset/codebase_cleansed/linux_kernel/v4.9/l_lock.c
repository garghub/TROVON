struct ldlm_resource *lock_res_and_lock(struct ldlm_lock *lock)
__acquires(&lock->l_lock
void unlock_res_and_lock(struct ldlm_lock *lock)
__releases(&lock->l_resource->lr_lock
