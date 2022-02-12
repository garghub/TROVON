struct ldlm_resource *lock_res_and_lock(struct ldlm_lock *lock)\r\n__acquires(&lock->l_lock\r\nvoid unlock_res_and_lock(struct ldlm_lock *lock)\r\n__releases(&lock->l_resource->lr_lock
