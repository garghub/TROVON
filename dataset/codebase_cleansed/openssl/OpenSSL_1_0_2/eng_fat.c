int ENGINE_set_default(ENGINE *e, unsigned int flags)
{
if ((flags & ENGINE_METHOD_CIPHERS) && !ENGINE_set_default_ciphers(e))
return 0;
if ((flags & ENGINE_METHOD_DIGESTS) && !ENGINE_set_default_digests(e))
return 0;
#ifndef OPENSSL_NO_RSA
if ((flags & ENGINE_METHOD_RSA) && !ENGINE_set_default_RSA(e))
return 0;
#endif
#ifndef OPENSSL_NO_DSA
if ((flags & ENGINE_METHOD_DSA) && !ENGINE_set_default_DSA(e))
return 0;
#endif
#ifndef OPENSSL_NO_DH
if ((flags & ENGINE_METHOD_DH) && !ENGINE_set_default_DH(e))
return 0;
#endif
#ifndef OPENSSL_NO_ECDH
if ((flags & ENGINE_METHOD_ECDH) && !ENGINE_set_default_ECDH(e))
return 0;
#endif
#ifndef OPENSSL_NO_ECDSA
if ((flags & ENGINE_METHOD_ECDSA) && !ENGINE_set_default_ECDSA(e))
return 0;
#endif
if ((flags & ENGINE_METHOD_RAND) && !ENGINE_set_default_RAND(e))
return 0;
if ((flags & ENGINE_METHOD_PKEY_METHS)
&& !ENGINE_set_default_pkey_meths(e))
return 0;
if ((flags & ENGINE_METHOD_PKEY_ASN1_METHS)
&& !ENGINE_set_default_pkey_asn1_meths(e))
return 0;
return 1;
}
static int int_def_cb(const char *alg, int len, void *arg)
{
unsigned int *pflags = arg;
if (!strncmp(alg, "ALL", len))
*pflags |= ENGINE_METHOD_ALL;
else if (!strncmp(alg, "RSA", len))
*pflags |= ENGINE_METHOD_RSA;
else if (!strncmp(alg, "DSA", len))
*pflags |= ENGINE_METHOD_DSA;
else if (!strncmp(alg, "ECDH", len))
*pflags |= ENGINE_METHOD_ECDH;
else if (!strncmp(alg, "ECDSA", len))
*pflags |= ENGINE_METHOD_ECDSA;
else if (!strncmp(alg, "DH", len))
*pflags |= ENGINE_METHOD_DH;
else if (!strncmp(alg, "RAND", len))
*pflags |= ENGINE_METHOD_RAND;
else if (!strncmp(alg, "CIPHERS", len))
*pflags |= ENGINE_METHOD_CIPHERS;
else if (!strncmp(alg, "DIGESTS", len))
*pflags |= ENGINE_METHOD_DIGESTS;
else if (!strncmp(alg, "PKEY", len))
*pflags |= ENGINE_METHOD_PKEY_METHS | ENGINE_METHOD_PKEY_ASN1_METHS;
else if (!strncmp(alg, "PKEY_CRYPTO", len))
*pflags |= ENGINE_METHOD_PKEY_METHS;
else if (!strncmp(alg, "PKEY_ASN1", len))
*pflags |= ENGINE_METHOD_PKEY_ASN1_METHS;
else
return 0;
return 1;
}
int ENGINE_set_default_string(ENGINE *e, const char *def_list)
{
unsigned int flags = 0;
if (!CONF_parse_list(def_list, ',', 1, int_def_cb, &flags)) {
ENGINEerr(ENGINE_F_ENGINE_SET_DEFAULT_STRING,
ENGINE_R_INVALID_STRING);
ERR_add_error_data(2, "str=", def_list);
return 0;
}
return ENGINE_set_default(e, flags);
}
int ENGINE_register_complete(ENGINE *e)
{
ENGINE_register_ciphers(e);
ENGINE_register_digests(e);
#ifndef OPENSSL_NO_RSA
ENGINE_register_RSA(e);
#endif
#ifndef OPENSSL_NO_DSA
ENGINE_register_DSA(e);
#endif
#ifndef OPENSSL_NO_DH
ENGINE_register_DH(e);
#endif
#ifndef OPENSSL_NO_ECDH
ENGINE_register_ECDH(e);
#endif
#ifndef OPENSSL_NO_ECDSA
ENGINE_register_ECDSA(e);
#endif
ENGINE_register_RAND(e);
ENGINE_register_pkey_meths(e);
return 1;
}
int ENGINE_register_all_complete(void)
{
ENGINE *e;
for (e = ENGINE_get_first(); e; e = ENGINE_get_next(e))
if (!(e->flags & ENGINE_FLAGS_NO_REGISTER_ALL))
ENGINE_register_complete(e);
return 1;
}
