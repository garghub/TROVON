static int request_key_auth_instantiate(struct key *key,
struct key_preparsed_payload *prep)
{
key->payload.data = (struct request_key_auth *)prep->data;
return 0;
}
static void request_key_auth_describe(const struct key *key,
struct seq_file *m)
{
struct request_key_auth *rka = key->payload.data;
seq_puts(m, "key:");
seq_puts(m, key->description);
if (key_is_instantiated(key))
seq_printf(m, " pid:%d ci:%zu", rka->pid, rka->callout_len);
}
static long request_key_auth_read(const struct key *key,
char __user *buffer, size_t buflen)
{
struct request_key_auth *rka = key->payload.data;
size_t datalen;
long ret;
datalen = rka->callout_len;
ret = datalen;
if (buffer && buflen > 0) {
if (buflen > datalen)
buflen = datalen;
if (copy_to_user(buffer, rka->callout_info, buflen) != 0)
ret = -EFAULT;
}
return ret;
}
static void request_key_auth_revoke(struct key *key)
{
struct request_key_auth *rka = key->payload.data;
kenter("{%d}", key->serial);
if (rka->cred) {
put_cred(rka->cred);
rka->cred = NULL;
}
}
static void request_key_auth_destroy(struct key *key)
{
struct request_key_auth *rka = key->payload.data;
kenter("{%d}", key->serial);
if (rka->cred) {
put_cred(rka->cred);
rka->cred = NULL;
}
key_put(rka->target_key);
key_put(rka->dest_keyring);
kfree(rka->callout_info);
kfree(rka);
}
struct key *request_key_auth_new(struct key *target, const void *callout_info,
size_t callout_len, struct key *dest_keyring)
{
struct request_key_auth *rka, *irka;
const struct cred *cred = current->cred;
struct key *authkey = NULL;
char desc[20];
int ret;
kenter("%d,", target->serial);
rka = kmalloc(sizeof(*rka), GFP_KERNEL);
if (!rka) {
kleave(" = -ENOMEM");
return ERR_PTR(-ENOMEM);
}
rka->callout_info = kmalloc(callout_len, GFP_KERNEL);
if (!rka->callout_info) {
kleave(" = -ENOMEM");
kfree(rka);
return ERR_PTR(-ENOMEM);
}
if (cred->request_key_auth) {
down_read(&cred->request_key_auth->sem);
if (test_bit(KEY_FLAG_REVOKED, &cred->request_key_auth->flags))
goto auth_key_revoked;
irka = cred->request_key_auth->payload.data;
rka->cred = get_cred(irka->cred);
rka->pid = irka->pid;
up_read(&cred->request_key_auth->sem);
}
else {
rka->cred = get_cred(cred);
rka->pid = current->pid;
}
rka->target_key = key_get(target);
rka->dest_keyring = key_get(dest_keyring);
memcpy(rka->callout_info, callout_info, callout_len);
rka->callout_len = callout_len;
sprintf(desc, "%x", target->serial);
authkey = key_alloc(&key_type_request_key_auth, desc,
cred->fsuid, cred->fsgid, cred,
KEY_POS_VIEW | KEY_POS_READ | KEY_POS_SEARCH |
KEY_USR_VIEW, KEY_ALLOC_NOT_IN_QUOTA);
if (IS_ERR(authkey)) {
ret = PTR_ERR(authkey);
goto error_alloc;
}
ret = key_instantiate_and_link(authkey, rka, 0, NULL, NULL);
if (ret < 0)
goto error_inst;
kleave(" = {%d,%d}", authkey->serial, atomic_read(&authkey->usage));
return authkey;
auth_key_revoked:
up_read(&cred->request_key_auth->sem);
kfree(rka->callout_info);
kfree(rka);
kleave("= -EKEYREVOKED");
return ERR_PTR(-EKEYREVOKED);
error_inst:
key_revoke(authkey);
key_put(authkey);
error_alloc:
key_put(rka->target_key);
key_put(rka->dest_keyring);
kfree(rka->callout_info);
kfree(rka);
kleave("= %d", ret);
return ERR_PTR(ret);
}
struct key *key_get_instantiation_authkey(key_serial_t target_id)
{
char description[16];
struct keyring_search_context ctx = {
.index_key.type = &key_type_request_key_auth,
.index_key.description = description,
.cred = current_cred(),
.match = user_match,
.match_data = description,
.flags = KEYRING_SEARCH_LOOKUP_DIRECT,
};
struct key *authkey;
key_ref_t authkey_ref;
sprintf(description, "%x", target_id);
authkey_ref = search_process_keyrings(&ctx);
if (IS_ERR(authkey_ref)) {
authkey = ERR_CAST(authkey_ref);
if (authkey == ERR_PTR(-EAGAIN))
authkey = ERR_PTR(-ENOKEY);
goto error;
}
authkey = key_ref_to_ptr(authkey_ref);
if (test_bit(KEY_FLAG_REVOKED, &authkey->flags)) {
key_put(authkey);
authkey = ERR_PTR(-EKEYREVOKED);
}
error:
return authkey;
}
