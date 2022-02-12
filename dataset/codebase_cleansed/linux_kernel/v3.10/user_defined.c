int user_instantiate(struct key *key, struct key_preparsed_payload *prep)
{
struct user_key_payload *upayload;
size_t datalen = prep->datalen;
int ret;
ret = -EINVAL;
if (datalen <= 0 || datalen > 32767 || !prep->data)
goto error;
ret = key_payload_reserve(key, datalen);
if (ret < 0)
goto error;
ret = -ENOMEM;
upayload = kmalloc(sizeof(*upayload) + datalen, GFP_KERNEL);
if (!upayload)
goto error;
upayload->datalen = datalen;
memcpy(upayload->data, prep->data, datalen);
rcu_assign_keypointer(key, upayload);
ret = 0;
error:
return ret;
}
int user_update(struct key *key, struct key_preparsed_payload *prep)
{
struct user_key_payload *upayload, *zap;
size_t datalen = prep->datalen;
int ret;
ret = -EINVAL;
if (datalen <= 0 || datalen > 32767 || !prep->data)
goto error;
ret = -ENOMEM;
upayload = kmalloc(sizeof(*upayload) + datalen, GFP_KERNEL);
if (!upayload)
goto error;
upayload->datalen = datalen;
memcpy(upayload->data, prep->data, datalen);
zap = upayload;
ret = key_payload_reserve(key, datalen);
if (ret == 0) {
zap = key->payload.data;
rcu_assign_keypointer(key, upayload);
key->expiry = 0;
}
if (zap)
kfree_rcu(zap, rcu);
error:
return ret;
}
int user_match(const struct key *key, const void *description)
{
return strcmp(key->description, description) == 0;
}
void user_revoke(struct key *key)
{
struct user_key_payload *upayload = key->payload.data;
key_payload_reserve(key, 0);
if (upayload) {
rcu_assign_keypointer(key, NULL);
kfree_rcu(upayload, rcu);
}
}
void user_destroy(struct key *key)
{
struct user_key_payload *upayload = key->payload.data;
kfree(upayload);
}
void user_describe(const struct key *key, struct seq_file *m)
{
seq_puts(m, key->description);
if (key_is_instantiated(key))
seq_printf(m, ": %u", key->datalen);
}
long user_read(const struct key *key, char __user *buffer, size_t buflen)
{
struct user_key_payload *upayload;
long ret;
upayload = rcu_dereference_key(key);
ret = upayload->datalen;
if (buffer && buflen > 0) {
if (buflen > upayload->datalen)
buflen = upayload->datalen;
if (copy_to_user(buffer, upayload->data, buflen) != 0)
ret = -EFAULT;
}
return ret;
}
static int logon_vet_description(const char *desc)
{
char *p;
p = strchr(desc, ':');
if (!p)
return -EINVAL;
if (p == desc)
return -EINVAL;
return 0;
}
