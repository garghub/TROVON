int rsa_get_n(void *context, size_t hdrlen, unsigned char tag,
const void *value, size_t vlen)
{
struct rsa_key *key = context;
key->n = mpi_read_raw_data(value, vlen);
if (!key->n)
return -ENOMEM;
if (fips_enabled && (mpi_get_size(key->n) != 256 ||
mpi_get_size(key->n) != 384)) {
pr_err("RSA: key size not allowed in FIPS mode\n");
mpi_free(key->n);
key->n = NULL;
return -EINVAL;
}
return 0;
}
int rsa_get_e(void *context, size_t hdrlen, unsigned char tag,
const void *value, size_t vlen)
{
struct rsa_key *key = context;
key->e = mpi_read_raw_data(value, vlen);
if (!key->e)
return -ENOMEM;
return 0;
}
int rsa_get_d(void *context, size_t hdrlen, unsigned char tag,
const void *value, size_t vlen)
{
struct rsa_key *key = context;
key->d = mpi_read_raw_data(value, vlen);
if (!key->d)
return -ENOMEM;
if (fips_enabled && (mpi_get_size(key->d) != 256 ||
mpi_get_size(key->d) != 384)) {
pr_err("RSA: key size not allowed in FIPS mode\n");
mpi_free(key->d);
key->d = NULL;
return -EINVAL;
}
return 0;
}
static void free_mpis(struct rsa_key *key)
{
mpi_free(key->n);
mpi_free(key->e);
mpi_free(key->d);
key->n = NULL;
key->e = NULL;
key->d = NULL;
}
void rsa_free_key(struct rsa_key *key)
{
free_mpis(key);
}
int rsa_parse_key(struct rsa_key *rsa_key, const void *key,
unsigned int key_len)
{
int ret;
free_mpis(rsa_key);
ret = asn1_ber_decoder(&rsakey_decoder, rsa_key, key, key_len);
if (ret < 0)
goto error;
return 0;
error:
free_mpis(rsa_key);
return ret;
}
