static int key_get_type_from_user(char *type,
const char __user *_type,
unsigned len)
{
int ret;
ret = strncpy_from_user(type, _type, len);
if (ret < 0)
return ret;
if (ret == 0 || ret >= len)
return -EINVAL;
if (type[0] == '.')
return -EPERM;
type[len - 1] = '\0';
return 0;
}
long keyctl_get_keyring_ID(key_serial_t id, int create)
{
key_ref_t key_ref;
unsigned long lflags;
long ret;
lflags = create ? KEY_LOOKUP_CREATE : 0;
key_ref = lookup_user_key(id, lflags, KEY_NEED_SEARCH);
if (IS_ERR(key_ref)) {
ret = PTR_ERR(key_ref);
goto error;
}
ret = key_ref_to_ptr(key_ref)->serial;
key_ref_put(key_ref);
error:
return ret;
}
long keyctl_join_session_keyring(const char __user *_name)
{
char *name;
long ret;
name = NULL;
if (_name) {
name = strndup_user(_name, PAGE_SIZE);
if (IS_ERR(name)) {
ret = PTR_ERR(name);
goto error;
}
}
ret = join_session_keyring(name);
kfree(name);
error:
return ret;
}
long keyctl_update_key(key_serial_t id,
const void __user *_payload,
size_t plen)
{
key_ref_t key_ref;
void *payload;
long ret;
ret = -EINVAL;
if (plen > PAGE_SIZE)
goto error;
payload = NULL;
if (_payload) {
ret = -ENOMEM;
payload = kmalloc(plen, GFP_KERNEL);
if (!payload)
goto error;
ret = -EFAULT;
if (copy_from_user(payload, _payload, plen) != 0)
goto error2;
}
key_ref = lookup_user_key(id, 0, KEY_NEED_WRITE);
if (IS_ERR(key_ref)) {
ret = PTR_ERR(key_ref);
goto error2;
}
ret = key_update(key_ref, payload, plen);
key_ref_put(key_ref);
error2:
kfree(payload);
error:
return ret;
}
long keyctl_revoke_key(key_serial_t id)
{
key_ref_t key_ref;
long ret;
key_ref = lookup_user_key(id, 0, KEY_NEED_WRITE);
if (IS_ERR(key_ref)) {
ret = PTR_ERR(key_ref);
if (ret != -EACCES)
goto error;
key_ref = lookup_user_key(id, 0, KEY_NEED_SETATTR);
if (IS_ERR(key_ref)) {
ret = PTR_ERR(key_ref);
goto error;
}
}
key_revoke(key_ref_to_ptr(key_ref));
ret = 0;
key_ref_put(key_ref);
error:
return ret;
}
long keyctl_invalidate_key(key_serial_t id)
{
key_ref_t key_ref;
long ret;
kenter("%d", id);
key_ref = lookup_user_key(id, 0, KEY_NEED_SEARCH);
if (IS_ERR(key_ref)) {
ret = PTR_ERR(key_ref);
goto error;
}
key_invalidate(key_ref_to_ptr(key_ref));
ret = 0;
key_ref_put(key_ref);
error:
kleave(" = %ld", ret);
return ret;
}
long keyctl_keyring_clear(key_serial_t ringid)
{
key_ref_t keyring_ref;
long ret;
keyring_ref = lookup_user_key(ringid, KEY_LOOKUP_CREATE, KEY_NEED_WRITE);
if (IS_ERR(keyring_ref)) {
ret = PTR_ERR(keyring_ref);
if (capable(CAP_SYS_ADMIN)) {
keyring_ref = lookup_user_key(ringid, 0, 0);
if (IS_ERR(keyring_ref))
goto error;
if (test_bit(KEY_FLAG_ROOT_CAN_CLEAR,
&key_ref_to_ptr(keyring_ref)->flags))
goto clear;
goto error_put;
}
goto error;
}
clear:
ret = keyring_clear(key_ref_to_ptr(keyring_ref));
error_put:
key_ref_put(keyring_ref);
error:
return ret;
}
long keyctl_keyring_link(key_serial_t id, key_serial_t ringid)
{
key_ref_t keyring_ref, key_ref;
long ret;
keyring_ref = lookup_user_key(ringid, KEY_LOOKUP_CREATE, KEY_NEED_WRITE);
if (IS_ERR(keyring_ref)) {
ret = PTR_ERR(keyring_ref);
goto error;
}
key_ref = lookup_user_key(id, KEY_LOOKUP_CREATE, KEY_NEED_LINK);
if (IS_ERR(key_ref)) {
ret = PTR_ERR(key_ref);
goto error2;
}
ret = key_link(key_ref_to_ptr(keyring_ref), key_ref_to_ptr(key_ref));
key_ref_put(key_ref);
error2:
key_ref_put(keyring_ref);
error:
return ret;
}
long keyctl_keyring_unlink(key_serial_t id, key_serial_t ringid)
{
key_ref_t keyring_ref, key_ref;
long ret;
keyring_ref = lookup_user_key(ringid, 0, KEY_NEED_WRITE);
if (IS_ERR(keyring_ref)) {
ret = PTR_ERR(keyring_ref);
goto error;
}
key_ref = lookup_user_key(id, KEY_LOOKUP_FOR_UNLINK, 0);
if (IS_ERR(key_ref)) {
ret = PTR_ERR(key_ref);
goto error2;
}
ret = key_unlink(key_ref_to_ptr(keyring_ref), key_ref_to_ptr(key_ref));
key_ref_put(key_ref);
error2:
key_ref_put(keyring_ref);
error:
return ret;
}
long keyctl_describe_key(key_serial_t keyid,
char __user *buffer,
size_t buflen)
{
struct key *key, *instkey;
key_ref_t key_ref;
char *tmpbuf;
long ret;
key_ref = lookup_user_key(keyid, KEY_LOOKUP_PARTIAL, KEY_NEED_VIEW);
if (IS_ERR(key_ref)) {
if (PTR_ERR(key_ref) == -EACCES) {
instkey = key_get_instantiation_authkey(keyid);
if (!IS_ERR(instkey)) {
key_put(instkey);
key_ref = lookup_user_key(keyid,
KEY_LOOKUP_PARTIAL,
0);
if (!IS_ERR(key_ref))
goto okay;
}
}
ret = PTR_ERR(key_ref);
goto error;
}
okay:
ret = -ENOMEM;
tmpbuf = kmalloc(PAGE_SIZE, GFP_KERNEL);
if (!tmpbuf)
goto error2;
key = key_ref_to_ptr(key_ref);
ret = snprintf(tmpbuf, PAGE_SIZE - 1,
"%s;%d;%d;%08x;%s",
key->type->name,
from_kuid_munged(current_user_ns(), key->uid),
from_kgid_munged(current_user_ns(), key->gid),
key->perm,
key->description ?: "");
if (ret > PAGE_SIZE - 1)
ret = PAGE_SIZE - 1;
tmpbuf[ret] = 0;
ret++;
if (buffer && buflen > 0) {
if (buflen > ret)
buflen = ret;
if (copy_to_user(buffer, tmpbuf, buflen) != 0)
ret = -EFAULT;
}
kfree(tmpbuf);
error2:
key_ref_put(key_ref);
error:
return ret;
}
long keyctl_keyring_search(key_serial_t ringid,
const char __user *_type,
const char __user *_description,
key_serial_t destringid)
{
struct key_type *ktype;
key_ref_t keyring_ref, key_ref, dest_ref;
char type[32], *description;
long ret;
ret = key_get_type_from_user(type, _type, sizeof(type));
if (ret < 0)
goto error;
description = strndup_user(_description, PAGE_SIZE);
if (IS_ERR(description)) {
ret = PTR_ERR(description);
goto error;
}
keyring_ref = lookup_user_key(ringid, 0, KEY_NEED_SEARCH);
if (IS_ERR(keyring_ref)) {
ret = PTR_ERR(keyring_ref);
goto error2;
}
dest_ref = NULL;
if (destringid) {
dest_ref = lookup_user_key(destringid, KEY_LOOKUP_CREATE,
KEY_NEED_WRITE);
if (IS_ERR(dest_ref)) {
ret = PTR_ERR(dest_ref);
goto error3;
}
}
ktype = key_type_lookup(type);
if (IS_ERR(ktype)) {
ret = PTR_ERR(ktype);
goto error4;
}
key_ref = keyring_search(keyring_ref, ktype, description);
if (IS_ERR(key_ref)) {
ret = PTR_ERR(key_ref);
if (ret == -EAGAIN)
ret = -ENOKEY;
goto error5;
}
if (dest_ref) {
ret = key_permission(key_ref, KEY_NEED_LINK);
if (ret < 0)
goto error6;
ret = key_link(key_ref_to_ptr(dest_ref), key_ref_to_ptr(key_ref));
if (ret < 0)
goto error6;
}
ret = key_ref_to_ptr(key_ref)->serial;
error6:
key_ref_put(key_ref);
error5:
key_type_put(ktype);
error4:
key_ref_put(dest_ref);
error3:
key_ref_put(keyring_ref);
error2:
kfree(description);
error:
return ret;
}
long keyctl_read_key(key_serial_t keyid, char __user *buffer, size_t buflen)
{
struct key *key;
key_ref_t key_ref;
long ret;
key_ref = lookup_user_key(keyid, 0, 0);
if (IS_ERR(key_ref)) {
ret = -ENOKEY;
goto error;
}
key = key_ref_to_ptr(key_ref);
ret = key_permission(key_ref, KEY_NEED_READ);
if (ret == 0)
goto can_read_key;
if (ret != -EACCES)
goto error;
if (!is_key_possessed(key_ref)) {
ret = -EACCES;
goto error2;
}
can_read_key:
ret = key_validate(key);
if (ret == 0) {
ret = -EOPNOTSUPP;
if (key->type->read) {
down_read(&key->sem);
ret = key->type->read(key, buffer, buflen);
up_read(&key->sem);
}
}
error2:
key_put(key);
error:
return ret;
}
long keyctl_chown_key(key_serial_t id, uid_t user, gid_t group)
{
struct key_user *newowner, *zapowner = NULL;
struct key *key;
key_ref_t key_ref;
long ret;
kuid_t uid;
kgid_t gid;
uid = make_kuid(current_user_ns(), user);
gid = make_kgid(current_user_ns(), group);
ret = -EINVAL;
if ((user != (uid_t) -1) && !uid_valid(uid))
goto error;
if ((group != (gid_t) -1) && !gid_valid(gid))
goto error;
ret = 0;
if (user == (uid_t) -1 && group == (gid_t) -1)
goto error;
key_ref = lookup_user_key(id, KEY_LOOKUP_CREATE | KEY_LOOKUP_PARTIAL,
KEY_NEED_SETATTR);
if (IS_ERR(key_ref)) {
ret = PTR_ERR(key_ref);
goto error;
}
key = key_ref_to_ptr(key_ref);
ret = -EACCES;
down_write(&key->sem);
if (!capable(CAP_SYS_ADMIN)) {
if (user != (uid_t) -1 && !uid_eq(key->uid, uid))
goto error_put;
if (group != (gid_t) -1 && !gid_eq(gid, key->gid) && !in_group_p(gid))
goto error_put;
}
if (user != (uid_t) -1 && !uid_eq(uid, key->uid)) {
ret = -ENOMEM;
newowner = key_user_lookup(uid);
if (!newowner)
goto error_put;
if (test_bit(KEY_FLAG_IN_QUOTA, &key->flags)) {
unsigned maxkeys = uid_eq(uid, GLOBAL_ROOT_UID) ?
key_quota_root_maxkeys : key_quota_maxkeys;
unsigned maxbytes = uid_eq(uid, GLOBAL_ROOT_UID) ?
key_quota_root_maxbytes : key_quota_maxbytes;
spin_lock(&newowner->lock);
if (newowner->qnkeys + 1 >= maxkeys ||
newowner->qnbytes + key->quotalen >= maxbytes ||
newowner->qnbytes + key->quotalen <
newowner->qnbytes)
goto quota_overrun;
newowner->qnkeys++;
newowner->qnbytes += key->quotalen;
spin_unlock(&newowner->lock);
spin_lock(&key->user->lock);
key->user->qnkeys--;
key->user->qnbytes -= key->quotalen;
spin_unlock(&key->user->lock);
}
atomic_dec(&key->user->nkeys);
atomic_inc(&newowner->nkeys);
if (test_bit(KEY_FLAG_INSTANTIATED, &key->flags)) {
atomic_dec(&key->user->nikeys);
atomic_inc(&newowner->nikeys);
}
zapowner = key->user;
key->user = newowner;
key->uid = uid;
}
if (group != (gid_t) -1)
key->gid = gid;
ret = 0;
error_put:
up_write(&key->sem);
key_put(key);
if (zapowner)
key_user_put(zapowner);
error:
return ret;
quota_overrun:
spin_unlock(&newowner->lock);
zapowner = newowner;
ret = -EDQUOT;
goto error_put;
}
long keyctl_setperm_key(key_serial_t id, key_perm_t perm)
{
struct key *key;
key_ref_t key_ref;
long ret;
ret = -EINVAL;
if (perm & ~(KEY_POS_ALL | KEY_USR_ALL | KEY_GRP_ALL | KEY_OTH_ALL))
goto error;
key_ref = lookup_user_key(id, KEY_LOOKUP_CREATE | KEY_LOOKUP_PARTIAL,
KEY_NEED_SETATTR);
if (IS_ERR(key_ref)) {
ret = PTR_ERR(key_ref);
goto error;
}
key = key_ref_to_ptr(key_ref);
ret = -EACCES;
down_write(&key->sem);
if (capable(CAP_SYS_ADMIN) || uid_eq(key->uid, current_fsuid())) {
key->perm = perm;
ret = 0;
}
up_write(&key->sem);
key_put(key);
error:
return ret;
}
static long get_instantiation_keyring(key_serial_t ringid,
struct request_key_auth *rka,
struct key **_dest_keyring)
{
key_ref_t dkref;
*_dest_keyring = NULL;
if (ringid == 0)
return 0;
if (ringid > 0) {
dkref = lookup_user_key(ringid, KEY_LOOKUP_CREATE, KEY_NEED_WRITE);
if (IS_ERR(dkref))
return PTR_ERR(dkref);
*_dest_keyring = key_ref_to_ptr(dkref);
return 0;
}
if (ringid == KEY_SPEC_REQKEY_AUTH_KEY)
return -EINVAL;
if (ringid >= KEY_SPEC_REQUESTOR_KEYRING) {
*_dest_keyring = key_get(rka->dest_keyring);
return 0;
}
return -ENOKEY;
}
static int keyctl_change_reqkey_auth(struct key *key)
{
struct cred *new;
new = prepare_creds();
if (!new)
return -ENOMEM;
key_put(new->request_key_auth);
new->request_key_auth = key_get(key);
return commit_creds(new);
}
static long copy_from_user_iovec(void *buffer, const struct iovec *iov,
unsigned ioc)
{
for (; ioc > 0; ioc--) {
if (copy_from_user(buffer, iov->iov_base, iov->iov_len) != 0)
return -EFAULT;
buffer += iov->iov_len;
iov++;
}
return 0;
}
long keyctl_instantiate_key_common(key_serial_t id,
const struct iovec *payload_iov,
unsigned ioc,
size_t plen,
key_serial_t ringid)
{
const struct cred *cred = current_cred();
struct request_key_auth *rka;
struct key *instkey, *dest_keyring;
void *payload;
long ret;
bool vm = false;
kenter("%d,,%zu,%d", id, plen, ringid);
ret = -EINVAL;
if (plen > 1024 * 1024 - 1)
goto error;
ret = -EPERM;
instkey = cred->request_key_auth;
if (!instkey)
goto error;
rka = instkey->payload.data;
if (rka->target_key->serial != id)
goto error;
payload = NULL;
if (payload_iov) {
ret = -ENOMEM;
payload = kmalloc(plen, GFP_KERNEL);
if (!payload) {
if (plen <= PAGE_SIZE)
goto error;
vm = true;
payload = vmalloc(plen);
if (!payload)
goto error;
}
ret = copy_from_user_iovec(payload, payload_iov, ioc);
if (ret < 0)
goto error2;
}
ret = get_instantiation_keyring(ringid, rka, &dest_keyring);
if (ret < 0)
goto error2;
ret = key_instantiate_and_link(rka->target_key, payload, plen,
dest_keyring, instkey);
key_put(dest_keyring);
if (ret == 0)
keyctl_change_reqkey_auth(NULL);
error2:
if (!vm)
kfree(payload);
else
vfree(payload);
error:
return ret;
}
long keyctl_instantiate_key(key_serial_t id,
const void __user *_payload,
size_t plen,
key_serial_t ringid)
{
if (_payload && plen) {
struct iovec iov[1] = {
[0].iov_base = (void __user *)_payload,
[0].iov_len = plen
};
return keyctl_instantiate_key_common(id, iov, 1, plen, ringid);
}
return keyctl_instantiate_key_common(id, NULL, 0, 0, ringid);
}
long keyctl_instantiate_key_iov(key_serial_t id,
const struct iovec __user *_payload_iov,
unsigned ioc,
key_serial_t ringid)
{
struct iovec iovstack[UIO_FASTIOV], *iov = iovstack;
long ret;
if (!_payload_iov || !ioc)
goto no_payload;
ret = rw_copy_check_uvector(WRITE, _payload_iov, ioc,
ARRAY_SIZE(iovstack), iovstack, &iov);
if (ret < 0)
goto err;
if (ret == 0)
goto no_payload_free;
ret = keyctl_instantiate_key_common(id, iov, ioc, ret, ringid);
err:
if (iov != iovstack)
kfree(iov);
return ret;
no_payload_free:
if (iov != iovstack)
kfree(iov);
no_payload:
return keyctl_instantiate_key_common(id, NULL, 0, 0, ringid);
}
long keyctl_negate_key(key_serial_t id, unsigned timeout, key_serial_t ringid)
{
return keyctl_reject_key(id, timeout, ENOKEY, ringid);
}
long keyctl_reject_key(key_serial_t id, unsigned timeout, unsigned error,
key_serial_t ringid)
{
const struct cred *cred = current_cred();
struct request_key_auth *rka;
struct key *instkey, *dest_keyring;
long ret;
kenter("%d,%u,%u,%d", id, timeout, error, ringid);
if (error <= 0 ||
error >= MAX_ERRNO ||
error == ERESTARTSYS ||
error == ERESTARTNOINTR ||
error == ERESTARTNOHAND ||
error == ERESTART_RESTARTBLOCK)
return -EINVAL;
ret = -EPERM;
instkey = cred->request_key_auth;
if (!instkey)
goto error;
rka = instkey->payload.data;
if (rka->target_key->serial != id)
goto error;
ret = get_instantiation_keyring(ringid, rka, &dest_keyring);
if (ret < 0)
goto error;
ret = key_reject_and_link(rka->target_key, timeout, error,
dest_keyring, instkey);
key_put(dest_keyring);
if (ret == 0)
keyctl_change_reqkey_auth(NULL);
error:
return ret;
}
long keyctl_set_reqkey_keyring(int reqkey_defl)
{
struct cred *new;
int ret, old_setting;
old_setting = current_cred_xxx(jit_keyring);
if (reqkey_defl == KEY_REQKEY_DEFL_NO_CHANGE)
return old_setting;
new = prepare_creds();
if (!new)
return -ENOMEM;
switch (reqkey_defl) {
case KEY_REQKEY_DEFL_THREAD_KEYRING:
ret = install_thread_keyring_to_cred(new);
if (ret < 0)
goto error;
goto set;
case KEY_REQKEY_DEFL_PROCESS_KEYRING:
ret = install_process_keyring_to_cred(new);
if (ret < 0) {
if (ret != -EEXIST)
goto error;
ret = 0;
}
goto set;
case KEY_REQKEY_DEFL_DEFAULT:
case KEY_REQKEY_DEFL_SESSION_KEYRING:
case KEY_REQKEY_DEFL_USER_KEYRING:
case KEY_REQKEY_DEFL_USER_SESSION_KEYRING:
case KEY_REQKEY_DEFL_REQUESTOR_KEYRING:
goto set;
case KEY_REQKEY_DEFL_NO_CHANGE:
case KEY_REQKEY_DEFL_GROUP_KEYRING:
default:
ret = -EINVAL;
goto error;
}
set:
new->jit_keyring = reqkey_defl;
commit_creds(new);
return old_setting;
error:
abort_creds(new);
return ret;
}
long keyctl_set_timeout(key_serial_t id, unsigned timeout)
{
struct key *key, *instkey;
key_ref_t key_ref;
long ret;
key_ref = lookup_user_key(id, KEY_LOOKUP_CREATE | KEY_LOOKUP_PARTIAL,
KEY_NEED_SETATTR);
if (IS_ERR(key_ref)) {
if (PTR_ERR(key_ref) == -EACCES) {
instkey = key_get_instantiation_authkey(id);
if (!IS_ERR(instkey)) {
key_put(instkey);
key_ref = lookup_user_key(id,
KEY_LOOKUP_PARTIAL,
0);
if (!IS_ERR(key_ref))
goto okay;
}
}
ret = PTR_ERR(key_ref);
goto error;
}
okay:
key = key_ref_to_ptr(key_ref);
key_set_timeout(key, timeout);
key_put(key);
ret = 0;
error:
return ret;
}
long keyctl_assume_authority(key_serial_t id)
{
struct key *authkey;
long ret;
ret = -EINVAL;
if (id < 0)
goto error;
if (id == 0) {
ret = keyctl_change_reqkey_auth(NULL);
goto error;
}
authkey = key_get_instantiation_authkey(id);
if (IS_ERR(authkey)) {
ret = PTR_ERR(authkey);
goto error;
}
ret = keyctl_change_reqkey_auth(authkey);
if (ret < 0)
goto error;
key_put(authkey);
ret = authkey->serial;
error:
return ret;
}
long keyctl_get_security(key_serial_t keyid,
char __user *buffer,
size_t buflen)
{
struct key *key, *instkey;
key_ref_t key_ref;
char *context;
long ret;
key_ref = lookup_user_key(keyid, KEY_LOOKUP_PARTIAL, KEY_NEED_VIEW);
if (IS_ERR(key_ref)) {
if (PTR_ERR(key_ref) != -EACCES)
return PTR_ERR(key_ref);
instkey = key_get_instantiation_authkey(keyid);
if (IS_ERR(instkey))
return PTR_ERR(instkey);
key_put(instkey);
key_ref = lookup_user_key(keyid, KEY_LOOKUP_PARTIAL, 0);
if (IS_ERR(key_ref))
return PTR_ERR(key_ref);
}
key = key_ref_to_ptr(key_ref);
ret = security_key_getsecurity(key, &context);
if (ret == 0) {
ret = 1;
if (buffer && buflen > 0 &&
copy_to_user(buffer, "", 1) != 0)
ret = -EFAULT;
} else if (ret > 0) {
if (buffer && buflen > 0) {
if (buflen > ret)
buflen = ret;
if (copy_to_user(buffer, context, buflen) != 0)
ret = -EFAULT;
}
kfree(context);
}
key_ref_put(key_ref);
return ret;
}
long keyctl_session_to_parent(void)
{
struct task_struct *me, *parent;
const struct cred *mycred, *pcred;
struct callback_head *newwork, *oldwork;
key_ref_t keyring_r;
struct cred *cred;
int ret;
keyring_r = lookup_user_key(KEY_SPEC_SESSION_KEYRING, 0, KEY_NEED_LINK);
if (IS_ERR(keyring_r))
return PTR_ERR(keyring_r);
ret = -ENOMEM;
cred = cred_alloc_blank();
if (!cred)
goto error_keyring;
newwork = &cred->rcu;
cred->session_keyring = key_ref_to_ptr(keyring_r);
keyring_r = NULL;
init_task_work(newwork, key_change_session_keyring);
me = current;
rcu_read_lock();
write_lock_irq(&tasklist_lock);
ret = -EPERM;
oldwork = NULL;
parent = me->real_parent;
if (parent->pid <= 1 || !parent->mm)
goto unlock;
if (!thread_group_empty(parent))
goto unlock;
mycred = current_cred();
pcred = __task_cred(parent);
if (mycred == pcred ||
mycred->session_keyring == pcred->session_keyring) {
ret = 0;
goto unlock;
}
if (!uid_eq(pcred->uid, mycred->euid) ||
!uid_eq(pcred->euid, mycred->euid) ||
!uid_eq(pcred->suid, mycred->euid) ||
!gid_eq(pcred->gid, mycred->egid) ||
!gid_eq(pcred->egid, mycred->egid) ||
!gid_eq(pcred->sgid, mycred->egid))
goto unlock;
if ((pcred->session_keyring &&
!uid_eq(pcred->session_keyring->uid, mycred->euid)) ||
!uid_eq(mycred->session_keyring->uid, mycred->euid))
goto unlock;
oldwork = task_work_cancel(parent, key_change_session_keyring);
ret = task_work_add(parent, newwork, true);
if (!ret)
newwork = NULL;
unlock:
write_unlock_irq(&tasklist_lock);
rcu_read_unlock();
if (oldwork)
put_cred(container_of(oldwork, struct cred, rcu));
if (newwork)
put_cred(cred);
return ret;
error_keyring:
key_ref_put(keyring_r);
return ret;
}
