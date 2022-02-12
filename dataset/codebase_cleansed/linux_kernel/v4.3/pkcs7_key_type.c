static int pkcs7_preparse(struct key_preparsed_payload *prep)
{
enum key_being_used_for usage = pkcs7_usage;
struct pkcs7_message *pkcs7;
const void *data, *saved_prep_data;
size_t datalen, saved_prep_datalen;
bool trusted;
int ret;
kenter("");
if (usage >= NR__KEY_BEING_USED_FOR) {
pr_err("Invalid usage type %d\n", usage);
return -EINVAL;
}
saved_prep_data = prep->data;
saved_prep_datalen = prep->datalen;
pkcs7 = pkcs7_parse_message(saved_prep_data, saved_prep_datalen);
if (IS_ERR(pkcs7)) {
ret = PTR_ERR(pkcs7);
goto error;
}
ret = pkcs7_verify(pkcs7, usage);
if (ret < 0)
goto error_free;
ret = pkcs7_validate_trust(pkcs7, system_trusted_keyring, &trusted);
if (ret < 0)
goto error_free;
if (!trusted)
pr_warn("PKCS#7 message doesn't chain back to a trusted key\n");
ret = pkcs7_get_content_data(pkcs7, &data, &datalen, false);
if (ret < 0)
goto error_free;
prep->data = data;
prep->datalen = datalen;
ret = user_preparse(prep);
prep->data = saved_prep_data;
prep->datalen = saved_prep_datalen;
error_free:
pkcs7_free_message(pkcs7);
error:
kleave(" = %d", ret);
return ret;
}
static int __init pkcs7_key_init(void)
{
return register_key_type(&key_type_pkcs7);
}
static void __exit pkcs7_key_cleanup(void)
{
unregister_key_type(&key_type_pkcs7);
}
