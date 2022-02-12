int integrity_digsig_verify(const unsigned int id, const char *sig, int siglen,
const char *digest, int digestlen)
{
if (id >= INTEGRITY_KEYRING_MAX)
return -EINVAL;
if (!keyring[id]) {
keyring[id] =
request_key(&key_type_keyring, keyring_name[id], NULL);
if (IS_ERR(keyring[id])) {
int err = PTR_ERR(keyring[id]);
pr_err("no %s keyring: %d\n", keyring_name[id], err);
keyring[id] = NULL;
return err;
}
}
switch (sig[0]) {
case 1:
return digsig_verify(keyring[id], sig, siglen,
digest, digestlen);
case 2:
return asymmetric_verify(keyring[id], sig, siglen,
digest, digestlen);
}
return -EOPNOTSUPP;
}
