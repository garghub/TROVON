int key_task_permission(const key_ref_t key_ref, const struct cred *cred,
key_perm_t perm)
{
struct key *key;
key_perm_t kperm;
int ret;
key = key_ref_to_ptr(key_ref);
if (key->user->user_ns != cred->user_ns)
goto use_other_perms;
if (key->uid == cred->fsuid) {
kperm = key->perm >> 16;
goto use_these_perms;
}
if (key->gid != -1 && key->perm & KEY_GRP_ALL) {
if (key->gid == cred->fsgid) {
kperm = key->perm >> 8;
goto use_these_perms;
}
ret = groups_search(cred->group_info,
make_kgid(current_user_ns(), key->gid));
if (ret) {
kperm = key->perm >> 8;
goto use_these_perms;
}
}
use_other_perms:
kperm = key->perm;
use_these_perms:
if (is_key_possessed(key_ref))
kperm |= key->perm >> 24;
kperm = kperm & perm & KEY_ALL;
if (kperm != perm)
return -EACCES;
return security_key_permission(key_ref, cred, perm);
}
int key_validate(const struct key *key)
{
unsigned long flags = key->flags;
if (flags & (1 << KEY_FLAG_INVALIDATED))
return -ENOKEY;
if (flags & ((1 << KEY_FLAG_REVOKED) |
(1 << KEY_FLAG_DEAD)))
return -EKEYREVOKED;
if (key->expiry) {
struct timespec now = current_kernel_time();
if (now.tv_sec >= key->expiry)
return -EKEYEXPIRED;
}
return 0;
}
