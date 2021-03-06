void ubifs_compress(const void *in_buf, int in_len, void *out_buf, int *out_len,
int *compr_type)
{
int err;
struct ubifs_compressor *compr = ubifs_compressors[*compr_type];
if (*compr_type == UBIFS_COMPR_NONE)
goto no_compr;
if (in_len < UBIFS_MIN_COMPR_LEN)
goto no_compr;
if (compr->comp_mutex)
mutex_lock(compr->comp_mutex);
err = crypto_comp_compress(compr->cc, in_buf, in_len, out_buf,
(unsigned int *)out_len);
if (compr->comp_mutex)
mutex_unlock(compr->comp_mutex);
if (unlikely(err)) {
ubifs_warn("cannot compress %d bytes, compressor %s, error %d, leave data uncompressed",
in_len, compr->name, err);
goto no_compr;
}
if (in_len - *out_len < UBIFS_MIN_COMPRESS_DIFF)
goto no_compr;
return;
no_compr:
memcpy(out_buf, in_buf, in_len);
*out_len = in_len;
*compr_type = UBIFS_COMPR_NONE;
}
int ubifs_decompress(const void *in_buf, int in_len, void *out_buf,
int *out_len, int compr_type)
{
int err;
struct ubifs_compressor *compr;
if (unlikely(compr_type < 0 || compr_type >= UBIFS_COMPR_TYPES_CNT)) {
ubifs_err("invalid compression type %d", compr_type);
return -EINVAL;
}
compr = ubifs_compressors[compr_type];
if (unlikely(!compr->capi_name)) {
ubifs_err("%s compression is not compiled in", compr->name);
return -EINVAL;
}
if (compr_type == UBIFS_COMPR_NONE) {
memcpy(out_buf, in_buf, in_len);
*out_len = in_len;
return 0;
}
if (compr->decomp_mutex)
mutex_lock(compr->decomp_mutex);
err = crypto_comp_decompress(compr->cc, in_buf, in_len, out_buf,
(unsigned int *)out_len);
if (compr->decomp_mutex)
mutex_unlock(compr->decomp_mutex);
if (err)
ubifs_err("cannot decompress %d bytes, compressor %s, error %d",
in_len, compr->name, err);
return err;
}
static int __init compr_init(struct ubifs_compressor *compr)
{
if (compr->capi_name) {
compr->cc = crypto_alloc_comp(compr->capi_name, 0, 0);
if (IS_ERR(compr->cc)) {
ubifs_err("cannot initialize compressor %s, error %ld",
compr->name, PTR_ERR(compr->cc));
return PTR_ERR(compr->cc);
}
}
ubifs_compressors[compr->compr_type] = compr;
return 0;
}
static void compr_exit(struct ubifs_compressor *compr)
{
if (compr->capi_name)
crypto_free_comp(compr->cc);
return;
}
int __init ubifs_compressors_init(void)
{
int err;
err = compr_init(&lzo_compr);
if (err)
return err;
err = compr_init(&zlib_compr);
if (err)
goto out_lzo;
ubifs_compressors[UBIFS_COMPR_NONE] = &none_compr;
return 0;
out_lzo:
compr_exit(&lzo_compr);
return err;
}
void ubifs_compressors_exit(void)
{
compr_exit(&lzo_compr);
compr_exit(&zlib_compr);
}
