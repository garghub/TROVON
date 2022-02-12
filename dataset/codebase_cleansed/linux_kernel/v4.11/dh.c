static int do_dh(MPI result, MPI base, MPI xa, MPI p)
{
return mpi_powm(result, base, xa, p);
}
static ssize_t mpi_from_key(key_serial_t keyid, size_t maxlen, MPI *mpi)
{
struct key *key;
key_ref_t key_ref;
long status;
ssize_t ret;
key_ref = lookup_user_key(keyid, 0, KEY_NEED_READ);
if (IS_ERR(key_ref)) {
ret = -ENOKEY;
goto error;
}
key = key_ref_to_ptr(key_ref);
ret = -EOPNOTSUPP;
if (key->type == &key_type_user) {
down_read(&key->sem);
status = key_validate(key);
if (status == 0) {
const struct user_key_payload *payload;
payload = user_key_payload_locked(key);
if (maxlen == 0) {
*mpi = NULL;
ret = payload->datalen;
} else if (payload->datalen <= maxlen) {
*mpi = mpi_read_raw_data(payload->data,
payload->datalen);
if (*mpi)
ret = payload->datalen;
} else {
ret = -EINVAL;
}
}
up_read(&key->sem);
}
key_put(key);
error:
return ret;
}
long keyctl_dh_compute(struct keyctl_dh_params __user *params,
char __user *buffer, size_t buflen,
void __user *reserved)
{
long ret;
MPI base, private, prime, result;
unsigned nbytes;
struct keyctl_dh_params pcopy;
uint8_t *kbuf;
ssize_t keylen;
size_t resultlen;
if (!params || (!buffer && buflen)) {
ret = -EINVAL;
goto out;
}
if (copy_from_user(&pcopy, params, sizeof(pcopy)) != 0) {
ret = -EFAULT;
goto out;
}
if (reserved) {
ret = -EINVAL;
goto out;
}
keylen = mpi_from_key(pcopy.prime, buflen, &prime);
if (keylen < 0 || !prime) {
ret = keylen;
goto out;
}
resultlen = keylen;
keylen = mpi_from_key(pcopy.base, SIZE_MAX, &base);
if (keylen < 0 || !base) {
ret = keylen;
goto error1;
}
keylen = mpi_from_key(pcopy.private, SIZE_MAX, &private);
if (keylen < 0 || !private) {
ret = keylen;
goto error2;
}
result = mpi_alloc(0);
if (!result) {
ret = -ENOMEM;
goto error3;
}
kbuf = kmalloc(resultlen, GFP_KERNEL);
if (!kbuf) {
ret = -ENOMEM;
goto error4;
}
ret = do_dh(result, base, private, prime);
if (ret)
goto error5;
ret = mpi_read_buffer(result, kbuf, resultlen, &nbytes, NULL);
if (ret != 0)
goto error5;
ret = nbytes;
if (copy_to_user(buffer, kbuf, nbytes) != 0)
ret = -EFAULT;
error5:
kfree(kbuf);
error4:
mpi_free(result);
error3:
mpi_free(private);
error2:
mpi_free(base);
error1:
mpi_free(prime);
out:
return ret;
}
