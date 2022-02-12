static void public_key_describe(const struct key *asymmetric_key,
struct seq_file *m)
{
struct public_key *key = asymmetric_key->payload.data;
if (key)
seq_printf(m, "%s.%s",
pkey_id_type[key->id_type], key->algo->name);
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
static int public_key_verify_signature(const struct key *key,
const struct public_key_signature *sig)
{
const struct public_key *pk = key->payload.data;
if (!pk->algo->verify_signature)
return -ENOTSUPP;
if (sig->nr_mpi != pk->algo->n_sig_mpi) {
pr_debug("Signature has %u MPI not %u\n",
sig->nr_mpi, pk->algo->n_sig_mpi);
return -EINVAL;
}
return pk->algo->verify_signature(pk, sig);
}
