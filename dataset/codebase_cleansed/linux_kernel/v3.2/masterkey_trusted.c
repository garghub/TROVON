struct key *request_trusted_key(const char *trusted_desc,
u8 **master_key, size_t *master_keylen)
{
struct trusted_key_payload *tpayload;
struct key *tkey;
tkey = request_key(&key_type_trusted, trusted_desc, NULL);
if (IS_ERR(tkey))
goto error;
down_read(&tkey->sem);
tpayload = rcu_dereference(tkey->payload.data);
*master_key = tpayload->key;
*master_keylen = tpayload->key_len;
error:
return tkey;
}
