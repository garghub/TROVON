static int init_desc(struct hash_desc *desc)
{
int rc;
desc->tfm = crypto_alloc_hash(ima_hash, 0, CRYPTO_ALG_ASYNC);
if (IS_ERR(desc->tfm)) {
pr_info("IMA: failed to load %s transform: %ld\n",
ima_hash, PTR_ERR(desc->tfm));
rc = PTR_ERR(desc->tfm);
return rc;
}
desc->flags = 0;
rc = crypto_hash_init(desc);
if (rc)
crypto_free_hash(desc->tfm);
return rc;
}
int ima_calc_hash(struct file *file, char *digest)
{
struct hash_desc desc;
struct scatterlist sg[1];
loff_t i_size, offset = 0;
char *rbuf;
int rc, read = 0;
rc = init_desc(&desc);
if (rc != 0)
return rc;
rbuf = kzalloc(PAGE_SIZE, GFP_KERNEL);
if (!rbuf) {
rc = -ENOMEM;
goto out;
}
if (!(file->f_mode & FMODE_READ)) {
file->f_mode |= FMODE_READ;
read = 1;
}
i_size = i_size_read(file->f_dentry->d_inode);
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
sg_init_one(sg, rbuf, rbuf_len);
rc = crypto_hash_update(&desc, sg, rbuf_len);
if (rc)
break;
}
kfree(rbuf);
if (!rc)
rc = crypto_hash_final(&desc, digest);
if (read)
file->f_mode &= ~FMODE_READ;
out:
crypto_free_hash(desc.tfm);
return rc;
}
int ima_calc_template_hash(int template_len, void *template, char *digest)
{
struct hash_desc desc;
struct scatterlist sg[1];
int rc;
rc = init_desc(&desc);
if (rc != 0)
return rc;
sg_init_one(sg, template, template_len);
rc = crypto_hash_update(&desc, sg, template_len);
if (!rc)
rc = crypto_hash_final(&desc, digest);
crypto_free_hash(desc.tfm);
return rc;
}
static void __init ima_pcrread(int idx, u8 *pcr)
{
if (!ima_used_chip)
return;
if (tpm_pcr_read(TPM_ANY_NUM, idx, pcr) != 0)
pr_err("IMA: Error Communicating to TPM chip\n");
}
int __init ima_calc_boot_aggregate(char *digest)
{
struct hash_desc desc;
struct scatterlist sg;
u8 pcr_i[IMA_DIGEST_SIZE];
int rc, i;
rc = init_desc(&desc);
if (rc != 0)
return rc;
for (i = TPM_PCR0; i < TPM_PCR8; i++) {
ima_pcrread(i, pcr_i);
sg_init_one(&sg, pcr_i, IMA_DIGEST_SIZE);
rc = crypto_hash_update(&desc, &sg, IMA_DIGEST_SIZE);
}
if (!rc)
crypto_hash_final(&desc, digest);
crypto_free_hash(desc.tfm);
return rc;
}
