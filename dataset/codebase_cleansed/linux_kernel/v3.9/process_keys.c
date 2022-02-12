int install_user_keyrings(void)
{
struct user_struct *user;
const struct cred *cred;
struct key *uid_keyring, *session_keyring;
key_perm_t user_keyring_perm;
char buf[20];
int ret;
uid_t uid;
user_keyring_perm = (KEY_POS_ALL & ~KEY_POS_SETATTR) | KEY_USR_ALL;
cred = current_cred();
user = cred->user;
uid = from_kuid(cred->user_ns, user->uid);
kenter("%p{%u}", user, uid);
if (user->uid_keyring && user->session_keyring) {
kleave(" = 0 [exist]");
return 0;
}
mutex_lock(&key_user_keyring_mutex);
ret = 0;
if (!user->uid_keyring) {
sprintf(buf, "_uid.%u", uid);
uid_keyring = find_keyring_by_name(buf, true);
if (IS_ERR(uid_keyring)) {
uid_keyring = keyring_alloc(buf, user->uid, INVALID_GID,
cred, user_keyring_perm,
KEY_ALLOC_IN_QUOTA, NULL);
if (IS_ERR(uid_keyring)) {
ret = PTR_ERR(uid_keyring);
goto error;
}
}
sprintf(buf, "_uid_ses.%u", uid);
session_keyring = find_keyring_by_name(buf, true);
if (IS_ERR(session_keyring)) {
session_keyring =
keyring_alloc(buf, user->uid, INVALID_GID,
cred, user_keyring_perm,
KEY_ALLOC_IN_QUOTA, NULL);
if (IS_ERR(session_keyring)) {
ret = PTR_ERR(session_keyring);
goto error_release;
}
ret = key_link(session_keyring, uid_keyring);
if (ret < 0)
goto error_release_both;
}
user->uid_keyring = uid_keyring;
user->session_keyring = session_keyring;
}
mutex_unlock(&key_user_keyring_mutex);
kleave(" = 0");
return 0;
error_release_both:
key_put(session_keyring);
error_release:
key_put(uid_keyring);
error:
mutex_unlock(&key_user_keyring_mutex);
kleave(" = %d", ret);
return ret;
}
int install_thread_keyring_to_cred(struct cred *new)
{
struct key *keyring;
keyring = keyring_alloc("_tid", new->uid, new->gid, new,
KEY_POS_ALL | KEY_USR_VIEW,
KEY_ALLOC_QUOTA_OVERRUN, NULL);
if (IS_ERR(keyring))
return PTR_ERR(keyring);
new->thread_keyring = keyring;
return 0;
}
static int install_thread_keyring(void)
{
struct cred *new;
int ret;
new = prepare_creds();
if (!new)
return -ENOMEM;
BUG_ON(new->thread_keyring);
ret = install_thread_keyring_to_cred(new);
if (ret < 0) {
abort_creds(new);
return ret;
}
return commit_creds(new);
}
int install_process_keyring_to_cred(struct cred *new)
{
struct key *keyring;
if (new->process_keyring)
return -EEXIST;
keyring = keyring_alloc("_pid", new->uid, new->gid, new,
KEY_POS_ALL | KEY_USR_VIEW,
KEY_ALLOC_QUOTA_OVERRUN, NULL);
if (IS_ERR(keyring))
return PTR_ERR(keyring);
new->process_keyring = keyring;
return 0;
}
static int install_process_keyring(void)
{
struct cred *new;
int ret;
new = prepare_creds();
if (!new)
return -ENOMEM;
ret = install_process_keyring_to_cred(new);
if (ret < 0) {
abort_creds(new);
return ret != -EEXIST ? ret : 0;
}
return commit_creds(new);
}
int install_session_keyring_to_cred(struct cred *cred, struct key *keyring)
{
unsigned long flags;
struct key *old;
might_sleep();
if (!keyring) {
flags = KEY_ALLOC_QUOTA_OVERRUN;
if (cred->session_keyring)
flags = KEY_ALLOC_IN_QUOTA;
keyring = keyring_alloc("_ses", cred->uid, cred->gid, cred,
KEY_POS_ALL | KEY_USR_VIEW | KEY_USR_READ,
flags, NULL);
if (IS_ERR(keyring))
return PTR_ERR(keyring);
} else {
atomic_inc(&keyring->usage);
}
old = cred->session_keyring;
rcu_assign_pointer(cred->session_keyring, keyring);
if (old)
key_put(old);
return 0;
}
static int install_session_keyring(struct key *keyring)
{
struct cred *new;
int ret;
new = prepare_creds();
if (!new)
return -ENOMEM;
ret = install_session_keyring_to_cred(new, keyring);
if (ret < 0) {
abort_creds(new);
return ret;
}
return commit_creds(new);
}
void key_fsuid_changed(struct task_struct *tsk)
{
BUG_ON(!tsk->cred);
if (tsk->cred->thread_keyring) {
down_write(&tsk->cred->thread_keyring->sem);
tsk->cred->thread_keyring->uid = tsk->cred->fsuid;
up_write(&tsk->cred->thread_keyring->sem);
}
}
void key_fsgid_changed(struct task_struct *tsk)
{
BUG_ON(!tsk->cred);
if (tsk->cred->thread_keyring) {
down_write(&tsk->cred->thread_keyring->sem);
tsk->cred->thread_keyring->gid = tsk->cred->fsgid;
up_write(&tsk->cred->thread_keyring->sem);
}
}
key_ref_t search_my_process_keyrings(struct key_type *type,
const void *description,
key_match_func_t match,
bool no_state_check,
const struct cred *cred)
{
key_ref_t key_ref, ret, err;
key_ref = NULL;
ret = NULL;
err = ERR_PTR(-EAGAIN);
if (cred->thread_keyring) {
key_ref = keyring_search_aux(
make_key_ref(cred->thread_keyring, 1),
cred, type, description, match, no_state_check);
if (!IS_ERR(key_ref))
goto found;
switch (PTR_ERR(key_ref)) {
case -EAGAIN:
case -ENOKEY:
ret = key_ref;
break;
default:
err = key_ref;
break;
}
}
if (cred->process_keyring) {
key_ref = keyring_search_aux(
make_key_ref(cred->process_keyring, 1),
cred, type, description, match, no_state_check);
if (!IS_ERR(key_ref))
goto found;
switch (PTR_ERR(key_ref)) {
case -EAGAIN:
if (ret)
break;
case -ENOKEY:
ret = key_ref;
break;
default:
err = key_ref;
break;
}
}
if (cred->session_keyring) {
rcu_read_lock();
key_ref = keyring_search_aux(
make_key_ref(rcu_dereference(cred->session_keyring), 1),
cred, type, description, match, no_state_check);
rcu_read_unlock();
if (!IS_ERR(key_ref))
goto found;
switch (PTR_ERR(key_ref)) {
case -EAGAIN:
if (ret)
break;
case -ENOKEY:
ret = key_ref;
break;
default:
err = key_ref;
break;
}
}
else if (cred->user->session_keyring) {
key_ref = keyring_search_aux(
make_key_ref(cred->user->session_keyring, 1),
cred, type, description, match, no_state_check);
if (!IS_ERR(key_ref))
goto found;
switch (PTR_ERR(key_ref)) {
case -EAGAIN:
if (ret)
break;
case -ENOKEY:
ret = key_ref;
break;
default:
err = key_ref;
break;
}
}
key_ref = ret ? ret : err;
found:
return key_ref;
}
key_ref_t search_process_keyrings(struct key_type *type,
const void *description,
key_match_func_t match,
const struct cred *cred)
{
struct request_key_auth *rka;
key_ref_t key_ref, ret = ERR_PTR(-EACCES), err;
might_sleep();
key_ref = search_my_process_keyrings(type, description, match,
false, cred);
if (!IS_ERR(key_ref))
goto found;
err = key_ref;
if (cred->request_key_auth &&
cred == current_cred() &&
type != &key_type_request_key_auth
) {
down_read(&cred->request_key_auth->sem);
if (key_validate(cred->request_key_auth) == 0) {
rka = cred->request_key_auth->payload.data;
key_ref = search_process_keyrings(type, description,
match, rka->cred);
up_read(&cred->request_key_auth->sem);
if (!IS_ERR(key_ref))
goto found;
ret = key_ref;
} else {
up_read(&cred->request_key_auth->sem);
}
}
if (err == ERR_PTR(-ENOKEY) || ret == ERR_PTR(-ENOKEY))
key_ref = ERR_PTR(-ENOKEY);
else if (err == ERR_PTR(-EACCES))
key_ref = ret;
else
key_ref = err;
found:
return key_ref;
}
int lookup_user_key_possessed(const struct key *key, const void *target)
{
return key == target;
}
key_ref_t lookup_user_key(key_serial_t id, unsigned long lflags,
key_perm_t perm)
{
struct request_key_auth *rka;
const struct cred *cred;
struct key *key;
key_ref_t key_ref, skey_ref;
int ret;
try_again:
cred = get_current_cred();
key_ref = ERR_PTR(-ENOKEY);
switch (id) {
case KEY_SPEC_THREAD_KEYRING:
if (!cred->thread_keyring) {
if (!(lflags & KEY_LOOKUP_CREATE))
goto error;
ret = install_thread_keyring();
if (ret < 0) {
key_ref = ERR_PTR(ret);
goto error;
}
goto reget_creds;
}
key = cred->thread_keyring;
atomic_inc(&key->usage);
key_ref = make_key_ref(key, 1);
break;
case KEY_SPEC_PROCESS_KEYRING:
if (!cred->process_keyring) {
if (!(lflags & KEY_LOOKUP_CREATE))
goto error;
ret = install_process_keyring();
if (ret < 0) {
key_ref = ERR_PTR(ret);
goto error;
}
goto reget_creds;
}
key = cred->process_keyring;
atomic_inc(&key->usage);
key_ref = make_key_ref(key, 1);
break;
case KEY_SPEC_SESSION_KEYRING:
if (!cred->session_keyring) {
ret = install_user_keyrings();
if (ret < 0)
goto error;
if (lflags & KEY_LOOKUP_CREATE)
ret = join_session_keyring(NULL);
else
ret = install_session_keyring(
cred->user->session_keyring);
if (ret < 0)
goto error;
goto reget_creds;
} else if (cred->session_keyring ==
cred->user->session_keyring &&
lflags & KEY_LOOKUP_CREATE) {
ret = join_session_keyring(NULL);
if (ret < 0)
goto error;
goto reget_creds;
}
rcu_read_lock();
key = rcu_dereference(cred->session_keyring);
atomic_inc(&key->usage);
rcu_read_unlock();
key_ref = make_key_ref(key, 1);
break;
case KEY_SPEC_USER_KEYRING:
if (!cred->user->uid_keyring) {
ret = install_user_keyrings();
if (ret < 0)
goto error;
}
key = cred->user->uid_keyring;
atomic_inc(&key->usage);
key_ref = make_key_ref(key, 1);
break;
case KEY_SPEC_USER_SESSION_KEYRING:
if (!cred->user->session_keyring) {
ret = install_user_keyrings();
if (ret < 0)
goto error;
}
key = cred->user->session_keyring;
atomic_inc(&key->usage);
key_ref = make_key_ref(key, 1);
break;
case KEY_SPEC_GROUP_KEYRING:
key_ref = ERR_PTR(-EINVAL);
goto error;
case KEY_SPEC_REQKEY_AUTH_KEY:
key = cred->request_key_auth;
if (!key)
goto error;
atomic_inc(&key->usage);
key_ref = make_key_ref(key, 1);
break;
case KEY_SPEC_REQUESTOR_KEYRING:
if (!cred->request_key_auth)
goto error;
down_read(&cred->request_key_auth->sem);
if (test_bit(KEY_FLAG_REVOKED,
&cred->request_key_auth->flags)) {
key_ref = ERR_PTR(-EKEYREVOKED);
key = NULL;
} else {
rka = cred->request_key_auth->payload.data;
key = rka->dest_keyring;
atomic_inc(&key->usage);
}
up_read(&cred->request_key_auth->sem);
if (!key)
goto error;
key_ref = make_key_ref(key, 1);
break;
default:
key_ref = ERR_PTR(-EINVAL);
if (id < 1)
goto error;
key = key_lookup(id);
if (IS_ERR(key)) {
key_ref = ERR_CAST(key);
goto error;
}
key_ref = make_key_ref(key, 0);
skey_ref = search_process_keyrings(key->type, key,
lookup_user_key_possessed,
cred);
if (!IS_ERR(skey_ref)) {
key_put(key);
key_ref = skey_ref;
}
break;
}
if (lflags & KEY_LOOKUP_FOR_UNLINK) {
ret = 0;
goto error;
}
if (!(lflags & KEY_LOOKUP_PARTIAL)) {
ret = wait_for_key_construction(key, true);
switch (ret) {
case -ERESTARTSYS:
goto invalid_key;
default:
if (perm)
goto invalid_key;
case 0:
break;
}
} else if (perm) {
ret = key_validate(key);
if (ret < 0)
goto invalid_key;
}
ret = -EIO;
if (!(lflags & KEY_LOOKUP_PARTIAL) &&
!test_bit(KEY_FLAG_INSTANTIATED, &key->flags))
goto invalid_key;
ret = key_task_permission(key_ref, cred, perm);
if (ret < 0)
goto invalid_key;
key->last_used_at = current_kernel_time().tv_sec;
error:
put_cred(cred);
return key_ref;
invalid_key:
key_ref_put(key_ref);
key_ref = ERR_PTR(ret);
goto error;
reget_creds:
put_cred(cred);
goto try_again;
}
long join_session_keyring(const char *name)
{
const struct cred *old;
struct cred *new;
struct key *keyring;
long ret, serial;
new = prepare_creds();
if (!new)
return -ENOMEM;
old = current_cred();
if (!name) {
ret = install_session_keyring_to_cred(new, NULL);
if (ret < 0)
goto error;
serial = new->session_keyring->serial;
ret = commit_creds(new);
if (ret == 0)
ret = serial;
goto okay;
}
mutex_lock(&key_session_mutex);
keyring = find_keyring_by_name(name, false);
if (PTR_ERR(keyring) == -ENOKEY) {
keyring = keyring_alloc(
name, old->uid, old->gid, old,
KEY_POS_ALL | KEY_USR_VIEW | KEY_USR_READ | KEY_USR_LINK,
KEY_ALLOC_IN_QUOTA, NULL);
if (IS_ERR(keyring)) {
ret = PTR_ERR(keyring);
goto error2;
}
} else if (IS_ERR(keyring)) {
ret = PTR_ERR(keyring);
goto error2;
} else if (keyring == new->session_keyring) {
ret = 0;
goto error2;
}
ret = install_session_keyring_to_cred(new, keyring);
if (ret < 0)
goto error2;
commit_creds(new);
mutex_unlock(&key_session_mutex);
ret = keyring->serial;
key_put(keyring);
okay:
return ret;
error2:
mutex_unlock(&key_session_mutex);
error:
abort_creds(new);
return ret;
}
void key_change_session_keyring(struct callback_head *twork)
{
const struct cred *old = current_cred();
struct cred *new = container_of(twork, struct cred, rcu);
if (unlikely(current->flags & PF_EXITING)) {
put_cred(new);
return;
}
new-> uid = old-> uid;
new-> euid = old-> euid;
new-> suid = old-> suid;
new->fsuid = old->fsuid;
new-> gid = old-> gid;
new-> egid = old-> egid;
new-> sgid = old-> sgid;
new->fsgid = old->fsgid;
new->user = get_uid(old->user);
new->user_ns = get_user_ns(old->user_ns);
new->group_info = get_group_info(old->group_info);
new->securebits = old->securebits;
new->cap_inheritable = old->cap_inheritable;
new->cap_permitted = old->cap_permitted;
new->cap_effective = old->cap_effective;
new->cap_bset = old->cap_bset;
new->jit_keyring = old->jit_keyring;
new->thread_keyring = key_get(old->thread_keyring);
new->process_keyring = key_get(old->process_keyring);
security_transfer_creds(new, old);
commit_creds(new);
}
