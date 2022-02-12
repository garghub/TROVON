static void public_key_describe(const struct key *asymmetric_key,
struct seq_file *m)
{
struct public_key *key = asymmetric_key->payload.data[asym_crypto];
if (key)
seq_printf(m, "%s.%s",
pkey_id_type_name[key->id_type], key->algo->name);
}
void public_key_destroy(void *payload)
{
struct public_key *key = payload;
int i;
if (key) {
for (i = 0; i < ARRAY_SIZE(key->mpi); i++)
mpi_free(key->mpi[i]);
kfree(key);
}
}
int public_key_verify_signature(const struct public_key *pk,
const struct public_key_signature *sig)
{
const struct public_key_algorithm *algo;
BUG_ON(!pk);
BUG_ON(!pk->mpi[0]);
BUG_ON(!pk->mpi[1]);
BUG_ON(!sig);
BUG_ON(!sig->digest);
BUG_ON(!sig->mpi[0]);
algo = pk->algo;
if (!algo) {
if (pk->pkey_algo >= PKEY_ALGO__LAST)
return -ENOPKG;
algo = pkey_algo[pk->pkey_algo];
if (!algo)
return -ENOPKG;
}
if (!algo->verify_signature)
return -ENOTSUPP;
if (sig->nr_mpi != algo->n_sig_mpi) {
pr_debug("Signature has %u MPI not %u\n",
sig->nr_mpi, algo->n_sig_mpi);
return -EINVAL;
}
return algo->verify_signature(pk, sig);
}
static int public_key_verify_signature_2(const struct key *key,
const struct public_key_signature *sig)
{
const struct public_key *pk = key->payload.data[asym_crypto];
return public_key_verify_signature(pk, sig);
}
