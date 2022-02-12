static inline u32 split_key_len(u32 hash)
{
static const u8 mdpadlen[] = { 16, 20, 32, 32, 64, 64 };
u32 idx;
idx = (hash & OP_ALG_ALGSEL_SUBMASK) >> OP_ALG_ALGSEL_SHIFT;
return (u32)(mdpadlen[idx] * 2);
}
static inline u32 split_key_pad_len(u32 hash)
{
return ALIGN(split_key_len(hash), 16);
}
void split_key_done(struct device *dev, u32 *desc, u32 err,
void *context)
{
struct split_key_result *res = context;
#ifdef DEBUG
dev_err(dev, "%s %d: err 0x%x\n", __func__, __LINE__, err);
#endif
if (err)
caam_jr_strstatus(dev, err);
res->err = err;
complete(&res->completion);
}
int gen_split_key(struct device *jrdev, u8 *key_out,
struct alginfo * const adata, const u8 *key_in, u32 keylen,
int max_keylen)
{
u32 *desc;
struct split_key_result result;
dma_addr_t dma_addr_in, dma_addr_out;
int ret = -ENOMEM;
adata->keylen = split_key_len(adata->algtype & OP_ALG_ALGSEL_MASK);
adata->keylen_pad = split_key_pad_len(adata->algtype &
OP_ALG_ALGSEL_MASK);
#ifdef DEBUG
dev_err(jrdev, "split keylen %d split keylen padded %d\n",
adata->keylen, adata->keylen_pad);
print_hex_dump(KERN_ERR, "ctx.key@" __stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, key_in, keylen, 1);
#endif
if (adata->keylen_pad > max_keylen)
return -EINVAL;
desc = kmalloc(CAAM_CMD_SZ * 6 + CAAM_PTR_SZ * 2, GFP_KERNEL | GFP_DMA);
if (!desc) {
dev_err(jrdev, "unable to allocate key input memory\n");
return ret;
}
dma_addr_in = dma_map_single(jrdev, (void *)key_in, keylen,
DMA_TO_DEVICE);
if (dma_mapping_error(jrdev, dma_addr_in)) {
dev_err(jrdev, "unable to map key input memory\n");
goto out_free;
}
dma_addr_out = dma_map_single(jrdev, key_out, adata->keylen_pad,
DMA_FROM_DEVICE);
if (dma_mapping_error(jrdev, dma_addr_out)) {
dev_err(jrdev, "unable to map key output memory\n");
goto out_unmap_in;
}
init_job_desc(desc, 0);
append_key(desc, dma_addr_in, keylen, CLASS_2 | KEY_DEST_CLASS_REG);
append_operation(desc, (adata->algtype & OP_ALG_ALGSEL_MASK) |
OP_ALG_AAI_HMAC | OP_TYPE_CLASS2_ALG | OP_ALG_DECRYPT |
OP_ALG_AS_INIT);
append_fifo_load_as_imm(desc, NULL, 0, LDST_CLASS_2_CCB |
FIFOLD_TYPE_MSG | FIFOLD_TYPE_LAST2);
append_fifo_store(desc, dma_addr_out, adata->keylen,
LDST_CLASS_2_CCB | FIFOST_TYPE_SPLIT_KEK);
#ifdef DEBUG
print_hex_dump(KERN_ERR, "ctx.key@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, key_in, keylen, 1);
print_hex_dump(KERN_ERR, "jobdesc@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, desc, desc_bytes(desc), 1);
#endif
result.err = 0;
init_completion(&result.completion);
ret = caam_jr_enqueue(jrdev, desc, split_key_done, &result);
if (!ret) {
wait_for_completion_interruptible(&result.completion);
ret = result.err;
#ifdef DEBUG
print_hex_dump(KERN_ERR, "ctx.key@"__stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, key_out,
adata->keylen_pad, 1);
#endif
}
dma_unmap_single(jrdev, dma_addr_out, adata->keylen_pad,
DMA_FROM_DEVICE);
out_unmap_in:
dma_unmap_single(jrdev, dma_addr_in, keylen, DMA_TO_DEVICE);
out_free:
kfree(desc);
return ret;
}
