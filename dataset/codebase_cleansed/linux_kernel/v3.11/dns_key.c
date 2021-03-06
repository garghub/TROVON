static int
dns_resolver_instantiate(struct key *key, struct key_preparsed_payload *prep)
{
struct user_key_payload *upayload;
unsigned long derrno;
int ret;
size_t datalen = prep->datalen, result_len = 0;
const char *data = prep->data, *end, *opt;
kenter("%%%d,%s,'%*.*s',%zu",
key->serial, key->description,
(int)datalen, (int)datalen, data, datalen);
if (datalen <= 1 || !data || data[datalen - 1] != '\0')
return -EINVAL;
datalen--;
end = data + datalen;
opt = memchr(data, '#', datalen);
if (!opt) {
kdebug("no options");
result_len = datalen;
} else {
const char *next_opt;
result_len = opt - data;
opt++;
kdebug("options: '%s'", opt);
do {
const char *eq;
int opt_len, opt_nlen, opt_vlen, tmp;
next_opt = memchr(opt, '#', end - opt) ?: end;
opt_len = next_opt - opt;
if (!opt_len) {
printk(KERN_WARNING
"Empty option to dns_resolver key %d\n",
key->serial);
return -EINVAL;
}
eq = memchr(opt, '=', opt_len) ?: end;
opt_nlen = eq - opt;
eq++;
opt_vlen = next_opt - eq;
tmp = opt_vlen >= 0 ? opt_vlen : 0;
kdebug("option '%*.*s' val '%*.*s'",
opt_nlen, opt_nlen, opt, tmp, tmp, eq);
if (opt_nlen == sizeof(DNS_ERRORNO_OPTION) - 1 &&
memcmp(opt, DNS_ERRORNO_OPTION, opt_nlen) == 0) {
kdebug("dns error number option");
if (opt_vlen <= 0)
goto bad_option_value;
ret = kstrtoul(eq, 10, &derrno);
if (ret < 0)
goto bad_option_value;
if (derrno < 1 || derrno > 511)
goto bad_option_value;
kdebug("dns error no. = %lu", derrno);
key->type_data.x[0] = -derrno;
continue;
}
bad_option_value:
printk(KERN_WARNING
"Option '%*.*s' to dns_resolver key %d:"
" bad/missing value\n",
opt_nlen, opt_nlen, opt, key->serial);
return -EINVAL;
} while (opt = next_opt + 1, opt < end);
}
if (key->type_data.x[0]) {
kleave(" = 0 [h_error %ld]", key->type_data.x[0]);
return 0;
}
kdebug("store result");
ret = key_payload_reserve(key, result_len);
if (ret < 0)
return -EINVAL;
upayload = kmalloc(sizeof(*upayload) + result_len + 1, GFP_KERNEL);
if (!upayload) {
kleave(" = -ENOMEM");
return -ENOMEM;
}
upayload->datalen = result_len;
memcpy(upayload->data, data, result_len);
upayload->data[result_len] = '\0';
rcu_assign_pointer(key->payload.data, upayload);
kleave(" = 0");
return 0;
}
static int
dns_resolver_match(const struct key *key, const void *description)
{
int slen, dlen, ret = 0;
const char *src = key->description, *dsp = description;
kenter("%s,%s", src, dsp);
if (!src || !dsp)
goto no_match;
if (strcasecmp(src, dsp) == 0)
goto matched;
slen = strlen(src);
dlen = strlen(dsp);
if (slen <= 0 || dlen <= 0)
goto no_match;
if (src[slen - 1] == '.')
slen--;
if (dsp[dlen - 1] == '.')
dlen--;
if (slen != dlen || strncasecmp(src, dsp, slen) != 0)
goto no_match;
matched:
ret = 1;
no_match:
kleave(" = %d", ret);
return ret;
}
static void dns_resolver_describe(const struct key *key, struct seq_file *m)
{
int err = key->type_data.x[0];
seq_puts(m, key->description);
if (key_is_instantiated(key)) {
if (err)
seq_printf(m, ": %d", err);
else
seq_printf(m, ": %u", key->datalen);
}
}
static long dns_resolver_read(const struct key *key,
char __user *buffer, size_t buflen)
{
if (key->type_data.x[0])
return key->type_data.x[0];
return user_read(key, buffer, buflen);
}
static int __init init_dns_resolver(void)
{
struct cred *cred;
struct key *keyring;
int ret;
cred = prepare_kernel_cred(NULL);
if (!cred)
return -ENOMEM;
keyring = keyring_alloc(".dns_resolver",
GLOBAL_ROOT_UID, GLOBAL_ROOT_GID, cred,
(KEY_POS_ALL & ~KEY_POS_SETATTR) |
KEY_USR_VIEW | KEY_USR_READ,
KEY_ALLOC_NOT_IN_QUOTA, NULL);
if (IS_ERR(keyring)) {
ret = PTR_ERR(keyring);
goto failed_put_cred;
}
ret = register_key_type(&key_type_dns_resolver);
if (ret < 0)
goto failed_put_key;
set_bit(KEY_FLAG_ROOT_CAN_CLEAR, &keyring->flags);
cred->thread_keyring = keyring;
cred->jit_keyring = KEY_REQKEY_DEFL_THREAD_KEYRING;
dns_resolver_cache = cred;
kdebug("DNS resolver keyring: %d\n", key_serial(keyring));
return 0;
failed_put_key:
key_put(keyring);
failed_put_cred:
put_cred(cred);
return ret;
}
static void __exit exit_dns_resolver(void)
{
key_revoke(dns_resolver_cache->thread_keyring);
unregister_key_type(&key_type_dns_resolver);
put_cred(dns_resolver_cache);
}
