int dns_query(const char *type, const char *name, size_t namelen,
const char *options, char **_result, time_t *_expiry)
{
struct key *rkey;
struct user_key_payload *upayload;
const struct cred *saved_cred;
size_t typelen, desclen;
char *desc, *cp;
int ret, len;
kenter("%s,%*.*s,%zu,%s",
type, (int)namelen, (int)namelen, name, namelen, options);
if (!name || namelen == 0 || !_result)
return -EINVAL;
typelen = 0;
desclen = 0;
if (type) {
typelen = strlen(type);
if (typelen < 1)
return -EINVAL;
desclen += typelen + 1;
}
if (!namelen)
namelen = strnlen(name, 256);
if (namelen < 3 || namelen > 255)
return -EINVAL;
desclen += namelen + 1;
desc = kmalloc(desclen, GFP_KERNEL);
if (!desc)
return -ENOMEM;
cp = desc;
if (type) {
memcpy(cp, type, typelen);
cp += typelen;
*cp++ = ':';
}
memcpy(cp, name, namelen);
cp += namelen;
*cp = '\0';
if (!options)
options = "";
kdebug("call request_key(,%s,%s)", desc, options);
saved_cred = override_creds(dns_resolver_cache);
rkey = request_key(&key_type_dns_resolver, desc, options);
revert_creds(saved_cred);
kfree(desc);
if (IS_ERR(rkey)) {
ret = PTR_ERR(rkey);
goto out;
}
down_read(&rkey->sem);
rkey->perm |= KEY_USR_VIEW;
ret = key_validate(rkey);
if (ret < 0)
goto put;
ret = rkey->type_data.x[0];
if (ret)
goto put;
upayload = rcu_dereference_protected(rkey->payload.data,
lockdep_is_held(&rkey->sem));
len = upayload->datalen;
ret = -ENOMEM;
*_result = kmalloc(len + 1, GFP_KERNEL);
if (!*_result)
goto put;
memcpy(*_result, upayload->data, len);
(*_result)[len] = '\0';
if (_expiry)
*_expiry = rkey->expiry;
ret = len;
put:
up_read(&rkey->sem);
key_put(rkey);
out:
kleave(" = %d", ret);
return ret;
}
