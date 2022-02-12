static int key_create_persistent_register(struct user_namespace *ns)
{
struct key *reg = keyring_alloc(".persistent_register",
KUIDT_INIT(0), KGIDT_INIT(0),
current_cred(),
((KEY_POS_ALL & ~KEY_POS_SETATTR) |
KEY_USR_VIEW | KEY_USR_READ),
KEY_ALLOC_NOT_IN_QUOTA, NULL);
if (IS_ERR(reg))
return PTR_ERR(reg);
ns->persistent_keyring_register = reg;
return 0;
}
static key_ref_t key_create_persistent(struct user_namespace *ns, kuid_t uid,
struct keyring_index_key *index_key)
{
struct key *persistent;
key_ref_t reg_ref, persistent_ref;
if (!ns->persistent_keyring_register) {
long err = key_create_persistent_register(ns);
if (err < 0)
return ERR_PTR(err);
} else {
reg_ref = make_key_ref(ns->persistent_keyring_register, true);
persistent_ref = find_key_to_update(reg_ref, index_key);
if (persistent_ref)
return persistent_ref;
}
persistent = keyring_alloc(index_key->description,
uid, INVALID_GID, current_cred(),
((KEY_POS_ALL & ~KEY_POS_SETATTR) |
KEY_USR_VIEW | KEY_USR_READ),
KEY_ALLOC_NOT_IN_QUOTA,
ns->persistent_keyring_register);
if (IS_ERR(persistent))
return ERR_CAST(persistent);
return make_key_ref(persistent, true);
}
static long key_get_persistent(struct user_namespace *ns, kuid_t uid,
key_ref_t dest_ref)
{
struct keyring_index_key index_key;
struct key *persistent;
key_ref_t reg_ref, persistent_ref;
char buf[32];
long ret;
index_key.type = &key_type_keyring;
index_key.description = buf;
index_key.desc_len = sprintf(buf, "_persistent.%u", from_kuid(ns, uid));
if (ns->persistent_keyring_register) {
reg_ref = make_key_ref(ns->persistent_keyring_register, true);
down_read(&ns->persistent_keyring_register_sem);
persistent_ref = find_key_to_update(reg_ref, &index_key);
up_read(&ns->persistent_keyring_register_sem);
if (persistent_ref)
goto found;
}
down_write(&ns->persistent_keyring_register_sem);
persistent_ref = key_create_persistent(ns, uid, &index_key);
up_write(&ns->persistent_keyring_register_sem);
if (!IS_ERR(persistent_ref))
goto found;
return PTR_ERR(persistent_ref);
found:
ret = key_task_permission(persistent_ref, current_cred(), KEY_LINK);
if (ret == 0) {
persistent = key_ref_to_ptr(persistent_ref);
ret = key_link(key_ref_to_ptr(dest_ref), persistent);
if (ret == 0) {
key_set_timeout(persistent, persistent_keyring_expiry);
ret = persistent->serial;
}
}
key_ref_put(persistent_ref);
return ret;
}
long keyctl_get_persistent(uid_t _uid, key_serial_t destid)
{
struct user_namespace *ns = current_user_ns();
key_ref_t dest_ref;
kuid_t uid;
long ret;
if (_uid == (uid_t)-1) {
uid = current_uid();
} else {
uid = make_kuid(ns, _uid);
if (!uid_valid(uid))
return -EINVAL;
if (!uid_eq(uid, current_uid()) &&
!uid_eq(uid, current_euid()) &&
!ns_capable(ns, CAP_SETUID))
return -EPERM;
}
dest_ref = lookup_user_key(destid, KEY_LOOKUP_CREATE, KEY_WRITE);
if (IS_ERR(dest_ref))
return PTR_ERR(dest_ref);
if (key_ref_to_ptr(dest_ref)->type != &key_type_keyring) {
ret = -ENOTDIR;
goto out_put_dest;
}
ret = key_get_persistent(ns, uid, dest_ref);
out_put_dest:
key_ref_put(dest_ref);
return ret;
}
