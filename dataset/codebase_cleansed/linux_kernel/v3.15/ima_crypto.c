int ima_init_crypto(void)
{
long rc;
ima_shash_tfm = crypto_alloc_shash(hash_algo_name[ima_hash_algo], 0, 0);
if (IS_ERR(ima_shash_tfm)) {
rc = PTR_ERR(ima_shash_tfm);
pr_err("Can not allocate %s (reason: %ld)\n",
hash_algo_name[ima_hash_algo], rc);
return rc;
}
return 0;
}
static struct crypto_shash *ima_alloc_tfm(enum hash_algo algo)
{
struct crypto_shash *tfm = ima_shash_tfm;
int rc;
if (algo != ima_hash_algo && algo < HASH_ALGO__LAST) {
tfm = crypto_alloc_shash(hash_algo_name[algo], 0, 0);
if (IS_ERR(tfm)) {
rc = PTR_ERR(tfm);
pr_err("Can not allocate %s (reason: %d)\n",
hash_algo_name[algo], rc);
}
}
return tfm;
}
static void ima_free_tfm(struct crypto_shash *tfm)
{
if (tfm != ima_shash_tfm)
crypto_free_shash(tfm);
}
static int ima_calc_file_hash_tfm(struct file *file,
struct ima_digest_data *hash,
struct crypto_shash *tfm)
{
loff_t i_size, offset = 0;
char *rbuf;
int rc, read = 0;
struct {
struct shash_desc shash;
char ctx[crypto_shash_descsize(tfm)];
} desc;
desc.shash.tfm = tfm;
desc.shash.flags = 0;
hash->length = crypto_shash_digestsize(tfm);
rc = crypto_shash_init(&desc.shash);
if (rc != 0)
return rc;
i_size = i_size_read(file_inode(file));
if (i_size == 0)
goto out;
rbuf = kzalloc(PAGE_SIZE, GFP_KERNEL);
if (!rbuf)
return -ENOMEM;
if (!(file->f_mode & FMODE_READ)) {
file->f_mode |= FMODE_READ;
read = 1;
}
while (offset < i_size) {
int rbuf_len;
rbuf_len = kernel_read(file, offset, rbuf, PAGE_SIZE);
if (rbuf_len < 0) {
rc = rbuf_len;
break;
}
if (rbuf_len == 0)
break;
offset += rbuf_len;
rc = crypto_shash_update(&desc.shash, rbuf, rbuf_len);
if (rc)
break;
}
if (read)
file->f_mode &= ~FMODE_READ;
kfree(rbuf);
out:
if (!rc)
rc = crypto_shash_final(&desc.shash, hash->digest);
return rc;
}
int ima_calc_file_hash(struct file *file, struct ima_digest_data *hash)
{
struct crypto_shash *tfm;
int rc;
tfm = ima_alloc_tfm(hash->algo);
if (IS_ERR(tfm))
return PTR_ERR(tfm);
rc = ima_calc_file_hash_tfm(file, hash, tfm);
ima_free_tfm(tfm);
return rc;
}
static int ima_calc_field_array_hash_tfm(struct ima_field_data *field_data,
struct ima_template_desc *td,
int num_fields,
struct ima_digest_data *hash,
struct crypto_shash *tfm)
{
struct {
struct shash_desc shash;
char ctx[crypto_shash_descsize(tfm)];
} desc;
int rc, i;
desc.shash.tfm = tfm;
desc.shash.flags = 0;
hash->length = crypto_shash_digestsize(tfm);
rc = crypto_shash_init(&desc.shash);
if (rc != 0)
return rc;
for (i = 0; i < num_fields; i++) {
u8 buffer[IMA_EVENT_NAME_LEN_MAX + 1] = { 0 };
u8 *data_to_hash = field_data[i].data;
u32 datalen = field_data[i].len;
if (strcmp(td->name, IMA_TEMPLATE_IMA_NAME) != 0) {
rc = crypto_shash_update(&desc.shash,
(const u8 *) &field_data[i].len,
sizeof(field_data[i].len));
if (rc)
break;
} else if (strcmp(td->fields[i]->field_id, "n") == 0) {
memcpy(buffer, data_to_hash, datalen);
data_to_hash = buffer;
datalen = IMA_EVENT_NAME_LEN_MAX + 1;
}
rc = crypto_shash_update(&desc.shash, data_to_hash, datalen);
if (rc)
break;
}
if (!rc)
rc = crypto_shash_final(&desc.shash, hash->digest);
return rc;
}
int ima_calc_field_array_hash(struct ima_field_data *field_data,
struct ima_template_desc *desc, int num_fields,
struct ima_digest_data *hash)
{
struct crypto_shash *tfm;
int rc;
tfm = ima_alloc_tfm(hash->algo);
if (IS_ERR(tfm))
return PTR_ERR(tfm);
rc = ima_calc_field_array_hash_tfm(field_data, desc, num_fields,
hash, tfm);
ima_free_tfm(tfm);
return rc;
}
static void __init ima_pcrread(int idx, u8 *pcr)
{
if (!ima_used_chip)
return;
if (tpm_pcr_read(TPM_ANY_NUM, idx, pcr) != 0)
pr_err("Error Communicating to TPM chip\n");
}
static int __init ima_calc_boot_aggregate_tfm(char *digest,
struct crypto_shash *tfm)
{
u8 pcr_i[TPM_DIGEST_SIZE];
int rc, i;
struct {
struct shash_desc shash;
char ctx[crypto_shash_descsize(tfm)];
} desc;
desc.shash.tfm = tfm;
desc.shash.flags = 0;
rc = crypto_shash_init(&desc.shash);
if (rc != 0)
return rc;
for (i = TPM_PCR0; i < TPM_PCR8; i++) {
ima_pcrread(i, pcr_i);
rc = crypto_shash_update(&desc.shash, pcr_i, TPM_DIGEST_SIZE);
}
if (!rc)
crypto_shash_final(&desc.shash, digest);
return rc;
}
int __init ima_calc_boot_aggregate(struct ima_digest_data *hash)
{
struct crypto_shash *tfm;
int rc;
tfm = ima_alloc_tfm(hash->algo);
if (IS_ERR(tfm))
return PTR_ERR(tfm);
hash->length = crypto_shash_digestsize(tfm);
rc = ima_calc_boot_aggregate_tfm(hash->digest, tfm);
ima_free_tfm(tfm);
return rc;
}
