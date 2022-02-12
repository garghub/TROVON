int user_preparse(struct key_preparsed_payload *prep)
{
struct user_key_payload *upayload;
size_t datalen = prep->datalen;
if (datalen <= 0 || datalen > 32767 || !prep->data)
return -EINVAL;
upayload = kmalloc(sizeof(*upayload) + datalen, GFP_KERNEL);
if (!upayload)
return -ENOMEM;
prep->quotalen = datalen;
prep->payload.data[0] = upayload;
upayload->datalen = datalen;
memcpy(upayload->data, prep->data, datalen);
return 0;
}
void user_free_preparse(struct key_preparsed_payload *prep)
{
kfree(prep->payload.data[0]);
}
int user_update(struct key *key, struct key_preparsed_payload *prep)
{
struct user_key_payload *zap = NULL;
int ret;
ret = key_payload_reserve(key, prep->datalen);
if (ret < 0)
return ret;
key->expiry = prep->expiry;
if (!test_bit(KEY_FLAG_NEGATIVE, &key->flags))
zap = rcu_dereference_key(key);
rcu_assign_keypointer(key, prep->payload.data[0]);
prep->payload.data[0] = NULL;
if (zap)
kfree_rcu(zap, rcu);
return ret;
}
void user_revoke(struct key *key)
{
struct user_key_payload *upayload = key->payload.data[0];
key_payload_reserve(key, 0);
if (upayload) {
rcu_assign_keypointer(key, NULL);
kfree_rcu(upayload, rcu);
}
}
void user_destroy(struct key *key)
{
struct user_key_payload *upayload = key->payload.data[0];
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
const struct user_key_payload *upayload;
long ret;
upayload = user_key_payload(key);
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
