static int pkcs7_view_content(void *ctx, const void *data, size_t len,
size_t asn1hdrlen)
{
struct key_preparsed_payload *prep = ctx;
const void *saved_prep_data;
size_t saved_prep_datalen;
int ret;
saved_prep_data = prep->data;
saved_prep_datalen = prep->datalen;
prep->data = data;
prep->datalen = len;
ret = user_preparse(prep);
prep->data = saved_prep_data;
prep->datalen = saved_prep_datalen;
return ret;
}
static int pkcs7_preparse(struct key_preparsed_payload *prep)
{
enum key_being_used_for usage = pkcs7_usage;
if (usage >= NR__KEY_BEING_USED_FOR) {
pr_err("Invalid usage type %d\n", usage);
return -EINVAL;
}
return verify_pkcs7_signature(NULL, 0,
prep->data, prep->datalen,
(void *)1UL, usage,
pkcs7_view_content, prep);
}
static int __init pkcs7_key_init(void)
{
return register_key_type(&key_type_pkcs7);
}
static void __exit pkcs7_key_cleanup(void)
{
unregister_key_type(&key_type_pkcs7);
}
