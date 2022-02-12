int pkcs7_validate_trust_one(struct pkcs7_message *pkcs7,
struct pkcs7_signed_info *sinfo,
struct key *trust_keyring)
{
struct public_key_signature *sig = &sinfo->sig;
struct x509_certificate *x509, *last = NULL, *p;
struct key *key;
bool trusted;
int ret;
kenter(",%u,", sinfo->index);
for (x509 = sinfo->signer; x509; x509 = x509->signer) {
if (x509->seen) {
if (x509->verified) {
trusted = x509->trusted;
goto verified;
}
kleave(" = -ENOKEY [cached]");
return -ENOKEY;
}
x509->seen = true;
key = x509_request_asymmetric_key(trust_keyring, x509->subject,
x509->fingerprint);
if (!IS_ERR(key))
goto matched;
if (key == ERR_PTR(-ENOMEM))
return -ENOMEM;
if (x509->next == x509) {
kleave(" = -ENOKEY [unknown self-signed]");
return -ENOKEY;
}
might_sleep();
last = x509;
sig = &last->sig;
}
if (!last || !last->issuer || !last->authority) {
kleave(" = -ENOKEY [no backref]");
return -ENOKEY;
}
key = x509_request_asymmetric_key(trust_keyring, last->issuer,
last->authority);
if (IS_ERR(key))
return PTR_ERR(key) == -ENOMEM ? -ENOMEM : -ENOKEY;
x509 = last;
matched:
ret = verify_signature(key, sig);
trusted = test_bit(KEY_FLAG_TRUSTED, &key->flags);
key_put(key);
if (ret < 0) {
if (ret == -ENOMEM)
return ret;
kleave(" = -EKEYREJECTED [verify %d]", ret);
return -EKEYREJECTED;
}
verified:
x509->verified = true;
for (p = sinfo->signer; p != x509; p = p->signer) {
p->verified = true;
p->trusted = trusted;
}
sinfo->trusted = trusted;
kleave(" = 0");
return 0;
}
int pkcs7_validate_trust(struct pkcs7_message *pkcs7,
struct key *trust_keyring,
bool *_trusted)
{
struct pkcs7_signed_info *sinfo;
struct x509_certificate *p;
int cached_ret = 0, ret;
for (p = pkcs7->certs; p; p = p->next)
p->seen = false;
for (sinfo = pkcs7->signed_infos; sinfo; sinfo = sinfo->next) {
ret = pkcs7_validate_trust_one(pkcs7, sinfo, trust_keyring);
if (ret < 0) {
if (ret == -ENOPKG) {
cached_ret = -ENOPKG;
} else if (ret == -ENOKEY) {
if (cached_ret == 0)
cached_ret = -ENOKEY;
} else {
return ret;
}
}
*_trusted |= sinfo->trusted;
}
return cached_ret;
}
