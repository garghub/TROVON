int mod_verify_sig(const void *mod, unsigned long *_modlen)
{
struct module_signature ms;
size_t modlen = *_modlen, sig_len;
pr_devel("==>%s(,%zu)\n", __func__, modlen);
if (modlen <= sizeof(ms))
return -EBADMSG;
memcpy(&ms, mod + (modlen - sizeof(ms)), sizeof(ms));
modlen -= sizeof(ms);
sig_len = be32_to_cpu(ms.sig_len);
if (sig_len >= modlen)
return -EBADMSG;
modlen -= sig_len;
*_modlen = modlen;
if (ms.id_type != PKEY_ID_PKCS7) {
pr_err("Module is not signed with expected PKCS#7 message\n");
return -ENOPKG;
}
if (ms.algo != 0 ||
ms.hash != 0 ||
ms.signer_len != 0 ||
ms.key_id_len != 0 ||
ms.__pad[0] != 0 ||
ms.__pad[1] != 0 ||
ms.__pad[2] != 0) {
pr_err("PKCS#7 signature info has unexpected non-zero params\n");
return -EBADMSG;
}
return verify_pkcs7_signature(mod, modlen, mod + modlen, sig_len,
NULL, VERIFYING_MODULE_SIGNATURE,
NULL, NULL);
}
