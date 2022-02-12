static void rsa_io_unmap(struct device *dev, struct rsa_edesc *edesc,
struct akcipher_request *req)
{
dma_unmap_sg(dev, req->dst, edesc->dst_nents, DMA_FROM_DEVICE);
dma_unmap_sg(dev, req->src, edesc->src_nents, DMA_TO_DEVICE);
if (edesc->sec4_sg_bytes)
dma_unmap_single(dev, edesc->sec4_sg_dma, edesc->sec4_sg_bytes,
DMA_TO_DEVICE);
}
static void rsa_pub_unmap(struct device *dev, struct rsa_edesc *edesc,
struct akcipher_request *req)
{
struct crypto_akcipher *tfm = crypto_akcipher_reqtfm(req);
struct caam_rsa_ctx *ctx = akcipher_tfm_ctx(tfm);
struct caam_rsa_key *key = &ctx->key;
struct rsa_pub_pdb *pdb = &edesc->pdb.pub;
dma_unmap_single(dev, pdb->n_dma, key->n_sz, DMA_TO_DEVICE);
dma_unmap_single(dev, pdb->e_dma, key->e_sz, DMA_TO_DEVICE);
}
static void rsa_priv_f1_unmap(struct device *dev, struct rsa_edesc *edesc,
struct akcipher_request *req)
{
struct crypto_akcipher *tfm = crypto_akcipher_reqtfm(req);
struct caam_rsa_ctx *ctx = akcipher_tfm_ctx(tfm);
struct caam_rsa_key *key = &ctx->key;
struct rsa_priv_f1_pdb *pdb = &edesc->pdb.priv_f1;
dma_unmap_single(dev, pdb->n_dma, key->n_sz, DMA_TO_DEVICE);
dma_unmap_single(dev, pdb->d_dma, key->d_sz, DMA_TO_DEVICE);
}
static void rsa_pub_done(struct device *dev, u32 *desc, u32 err, void *context)
{
struct akcipher_request *req = context;
struct rsa_edesc *edesc;
if (err)
caam_jr_strstatus(dev, err);
edesc = container_of(desc, struct rsa_edesc, hw_desc[0]);
rsa_pub_unmap(dev, edesc, req);
rsa_io_unmap(dev, edesc, req);
kfree(edesc);
akcipher_request_complete(req, err);
}
static void rsa_priv_f1_done(struct device *dev, u32 *desc, u32 err,
void *context)
{
struct akcipher_request *req = context;
struct rsa_edesc *edesc;
if (err)
caam_jr_strstatus(dev, err);
edesc = container_of(desc, struct rsa_edesc, hw_desc[0]);
rsa_priv_f1_unmap(dev, edesc, req);
rsa_io_unmap(dev, edesc, req);
kfree(edesc);
akcipher_request_complete(req, err);
}
static struct rsa_edesc *rsa_edesc_alloc(struct akcipher_request *req,
size_t desclen)
{
struct crypto_akcipher *tfm = crypto_akcipher_reqtfm(req);
struct caam_rsa_ctx *ctx = akcipher_tfm_ctx(tfm);
struct device *dev = ctx->dev;
struct rsa_edesc *edesc;
gfp_t flags = (req->base.flags & (CRYPTO_TFM_REQ_MAY_BACKLOG |
CRYPTO_TFM_REQ_MAY_SLEEP)) ? GFP_KERNEL : GFP_ATOMIC;
int sgc;
int sec4_sg_index, sec4_sg_len = 0, sec4_sg_bytes;
int src_nents, dst_nents;
src_nents = sg_nents_for_len(req->src, req->src_len);
dst_nents = sg_nents_for_len(req->dst, req->dst_len);
if (src_nents > 1)
sec4_sg_len = src_nents;
if (dst_nents > 1)
sec4_sg_len += dst_nents;
sec4_sg_bytes = sec4_sg_len * sizeof(struct sec4_sg_entry);
edesc = kzalloc(sizeof(*edesc) + desclen + sec4_sg_bytes,
GFP_DMA | flags);
if (!edesc)
return ERR_PTR(-ENOMEM);
sgc = dma_map_sg(dev, req->src, src_nents, DMA_TO_DEVICE);
if (unlikely(!sgc)) {
dev_err(dev, "unable to map source\n");
goto src_fail;
}
sgc = dma_map_sg(dev, req->dst, dst_nents, DMA_FROM_DEVICE);
if (unlikely(!sgc)) {
dev_err(dev, "unable to map destination\n");
goto dst_fail;
}
edesc->sec4_sg = (void *)edesc + sizeof(*edesc) + desclen;
sec4_sg_index = 0;
if (src_nents > 1) {
sg_to_sec4_sg_last(req->src, src_nents, edesc->sec4_sg, 0);
sec4_sg_index += src_nents;
}
if (dst_nents > 1)
sg_to_sec4_sg_last(req->dst, dst_nents,
edesc->sec4_sg + sec4_sg_index, 0);
edesc->src_nents = src_nents;
edesc->dst_nents = dst_nents;
if (!sec4_sg_bytes)
return edesc;
edesc->sec4_sg_dma = dma_map_single(dev, edesc->sec4_sg,
sec4_sg_bytes, DMA_TO_DEVICE);
if (dma_mapping_error(dev, edesc->sec4_sg_dma)) {
dev_err(dev, "unable to map S/G table\n");
goto sec4_sg_fail;
}
edesc->sec4_sg_bytes = sec4_sg_bytes;
return edesc;
sec4_sg_fail:
dma_unmap_sg(dev, req->dst, dst_nents, DMA_FROM_DEVICE);
dst_fail:
dma_unmap_sg(dev, req->src, src_nents, DMA_TO_DEVICE);
src_fail:
kfree(edesc);
return ERR_PTR(-ENOMEM);
}
static int set_rsa_pub_pdb(struct akcipher_request *req,
struct rsa_edesc *edesc)
{
struct crypto_akcipher *tfm = crypto_akcipher_reqtfm(req);
struct caam_rsa_ctx *ctx = akcipher_tfm_ctx(tfm);
struct caam_rsa_key *key = &ctx->key;
struct device *dev = ctx->dev;
struct rsa_pub_pdb *pdb = &edesc->pdb.pub;
int sec4_sg_index = 0;
pdb->n_dma = dma_map_single(dev, key->n, key->n_sz, DMA_TO_DEVICE);
if (dma_mapping_error(dev, pdb->n_dma)) {
dev_err(dev, "Unable to map RSA modulus memory\n");
return -ENOMEM;
}
pdb->e_dma = dma_map_single(dev, key->e, key->e_sz, DMA_TO_DEVICE);
if (dma_mapping_error(dev, pdb->e_dma)) {
dev_err(dev, "Unable to map RSA public exponent memory\n");
dma_unmap_single(dev, pdb->n_dma, key->n_sz, DMA_TO_DEVICE);
return -ENOMEM;
}
if (edesc->src_nents > 1) {
pdb->sgf |= RSA_PDB_SGF_F;
pdb->f_dma = edesc->sec4_sg_dma;
sec4_sg_index += edesc->src_nents;
} else {
pdb->f_dma = sg_dma_address(req->src);
}
if (edesc->dst_nents > 1) {
pdb->sgf |= RSA_PDB_SGF_G;
pdb->g_dma = edesc->sec4_sg_dma +
sec4_sg_index * sizeof(struct sec4_sg_entry);
} else {
pdb->g_dma = sg_dma_address(req->dst);
}
pdb->sgf |= (key->e_sz << RSA_PDB_E_SHIFT) | key->n_sz;
pdb->f_len = req->src_len;
return 0;
}
static int set_rsa_priv_f1_pdb(struct akcipher_request *req,
struct rsa_edesc *edesc)
{
struct crypto_akcipher *tfm = crypto_akcipher_reqtfm(req);
struct caam_rsa_ctx *ctx = akcipher_tfm_ctx(tfm);
struct caam_rsa_key *key = &ctx->key;
struct device *dev = ctx->dev;
struct rsa_priv_f1_pdb *pdb = &edesc->pdb.priv_f1;
int sec4_sg_index = 0;
pdb->n_dma = dma_map_single(dev, key->n, key->n_sz, DMA_TO_DEVICE);
if (dma_mapping_error(dev, pdb->n_dma)) {
dev_err(dev, "Unable to map modulus memory\n");
return -ENOMEM;
}
pdb->d_dma = dma_map_single(dev, key->d, key->d_sz, DMA_TO_DEVICE);
if (dma_mapping_error(dev, pdb->d_dma)) {
dev_err(dev, "Unable to map RSA private exponent memory\n");
dma_unmap_single(dev, pdb->n_dma, key->n_sz, DMA_TO_DEVICE);
return -ENOMEM;
}
if (edesc->src_nents > 1) {
pdb->sgf |= RSA_PRIV_PDB_SGF_G;
pdb->g_dma = edesc->sec4_sg_dma;
sec4_sg_index += edesc->src_nents;
} else {
pdb->g_dma = sg_dma_address(req->src);
}
if (edesc->dst_nents > 1) {
pdb->sgf |= RSA_PRIV_PDB_SGF_F;
pdb->f_dma = edesc->sec4_sg_dma +
sec4_sg_index * sizeof(struct sec4_sg_entry);
} else {
pdb->f_dma = sg_dma_address(req->dst);
}
pdb->sgf |= (key->d_sz << RSA_PDB_D_SHIFT) | key->n_sz;
return 0;
}
static int caam_rsa_enc(struct akcipher_request *req)
{
struct crypto_akcipher *tfm = crypto_akcipher_reqtfm(req);
struct caam_rsa_ctx *ctx = akcipher_tfm_ctx(tfm);
struct caam_rsa_key *key = &ctx->key;
struct device *jrdev = ctx->dev;
struct rsa_edesc *edesc;
int ret;
if (unlikely(!key->n || !key->e))
return -EINVAL;
if (req->dst_len < key->n_sz) {
req->dst_len = key->n_sz;
dev_err(jrdev, "Output buffer length less than parameter n\n");
return -EOVERFLOW;
}
edesc = rsa_edesc_alloc(req, DESC_RSA_PUB_LEN);
if (IS_ERR(edesc))
return PTR_ERR(edesc);
ret = set_rsa_pub_pdb(req, edesc);
if (ret)
goto init_fail;
init_rsa_pub_desc(edesc->hw_desc, &edesc->pdb.pub);
ret = caam_jr_enqueue(jrdev, edesc->hw_desc, rsa_pub_done, req);
if (!ret)
return -EINPROGRESS;
rsa_pub_unmap(jrdev, edesc, req);
init_fail:
rsa_io_unmap(jrdev, edesc, req);
kfree(edesc);
return ret;
}
static int caam_rsa_dec(struct akcipher_request *req)
{
struct crypto_akcipher *tfm = crypto_akcipher_reqtfm(req);
struct caam_rsa_ctx *ctx = akcipher_tfm_ctx(tfm);
struct caam_rsa_key *key = &ctx->key;
struct device *jrdev = ctx->dev;
struct rsa_edesc *edesc;
int ret;
if (unlikely(!key->n || !key->d))
return -EINVAL;
if (req->dst_len < key->n_sz) {
req->dst_len = key->n_sz;
dev_err(jrdev, "Output buffer length less than parameter n\n");
return -EOVERFLOW;
}
edesc = rsa_edesc_alloc(req, DESC_RSA_PRIV_F1_LEN);
if (IS_ERR(edesc))
return PTR_ERR(edesc);
ret = set_rsa_priv_f1_pdb(req, edesc);
if (ret)
goto init_fail;
init_rsa_priv_f1_desc(edesc->hw_desc, &edesc->pdb.priv_f1);
ret = caam_jr_enqueue(jrdev, edesc->hw_desc, rsa_priv_f1_done, req);
if (!ret)
return -EINPROGRESS;
rsa_priv_f1_unmap(jrdev, edesc, req);
init_fail:
rsa_io_unmap(jrdev, edesc, req);
kfree(edesc);
return ret;
}
static void caam_rsa_free_key(struct caam_rsa_key *key)
{
kzfree(key->d);
kfree(key->e);
kfree(key->n);
key->d = NULL;
key->e = NULL;
key->n = NULL;
key->d_sz = 0;
key->e_sz = 0;
key->n_sz = 0;
}
static inline u8 *caam_read_raw_data(const u8 *buf, size_t *nbytes)
{
u8 *val;
while (!*buf && *nbytes) {
buf++;
(*nbytes)--;
}
val = kzalloc(*nbytes, GFP_DMA | GFP_KERNEL);
if (!val)
return NULL;
memcpy(val, buf, *nbytes);
return val;
}
static int caam_rsa_check_key_length(unsigned int len)
{
if (len > 4096)
return -EINVAL;
return 0;
}
static int caam_rsa_set_pub_key(struct crypto_akcipher *tfm, const void *key,
unsigned int keylen)
{
struct caam_rsa_ctx *ctx = akcipher_tfm_ctx(tfm);
struct rsa_key raw_key = {0};
struct caam_rsa_key *rsa_key = &ctx->key;
int ret;
caam_rsa_free_key(rsa_key);
ret = rsa_parse_pub_key(&raw_key, key, keylen);
if (ret)
return ret;
rsa_key->e = kzalloc(raw_key.e_sz, GFP_DMA | GFP_KERNEL);
if (!rsa_key->e)
goto err;
rsa_key->n = caam_read_raw_data(raw_key.n, &raw_key.n_sz);
if (!rsa_key->n)
goto err;
if (caam_rsa_check_key_length(raw_key.n_sz << 3)) {
caam_rsa_free_key(rsa_key);
return -EINVAL;
}
rsa_key->e_sz = raw_key.e_sz;
rsa_key->n_sz = raw_key.n_sz;
memcpy(rsa_key->e, raw_key.e, raw_key.e_sz);
return 0;
err:
caam_rsa_free_key(rsa_key);
return -ENOMEM;
}
static int caam_rsa_set_priv_key(struct crypto_akcipher *tfm, const void *key,
unsigned int keylen)
{
struct caam_rsa_ctx *ctx = akcipher_tfm_ctx(tfm);
struct rsa_key raw_key = {0};
struct caam_rsa_key *rsa_key = &ctx->key;
int ret;
caam_rsa_free_key(rsa_key);
ret = rsa_parse_priv_key(&raw_key, key, keylen);
if (ret)
return ret;
rsa_key->d = kzalloc(raw_key.d_sz, GFP_DMA | GFP_KERNEL);
if (!rsa_key->d)
goto err;
rsa_key->e = kzalloc(raw_key.e_sz, GFP_DMA | GFP_KERNEL);
if (!rsa_key->e)
goto err;
rsa_key->n = caam_read_raw_data(raw_key.n, &raw_key.n_sz);
if (!rsa_key->n)
goto err;
if (caam_rsa_check_key_length(raw_key.n_sz << 3)) {
caam_rsa_free_key(rsa_key);
return -EINVAL;
}
rsa_key->d_sz = raw_key.d_sz;
rsa_key->e_sz = raw_key.e_sz;
rsa_key->n_sz = raw_key.n_sz;
memcpy(rsa_key->d, raw_key.d, raw_key.d_sz);
memcpy(rsa_key->e, raw_key.e, raw_key.e_sz);
return 0;
err:
caam_rsa_free_key(rsa_key);
return -ENOMEM;
}
static int caam_rsa_max_size(struct crypto_akcipher *tfm)
{
struct caam_rsa_ctx *ctx = akcipher_tfm_ctx(tfm);
struct caam_rsa_key *key = &ctx->key;
return (key->n) ? key->n_sz : -EINVAL;
}
static int caam_rsa_init_tfm(struct crypto_akcipher *tfm)
{
struct caam_rsa_ctx *ctx = akcipher_tfm_ctx(tfm);
ctx->dev = caam_jr_alloc();
if (IS_ERR(ctx->dev)) {
dev_err(ctx->dev, "Job Ring Device allocation for transform failed\n");
return PTR_ERR(ctx->dev);
}
return 0;
}
static void caam_rsa_exit_tfm(struct crypto_akcipher *tfm)
{
struct caam_rsa_ctx *ctx = akcipher_tfm_ctx(tfm);
struct caam_rsa_key *key = &ctx->key;
caam_rsa_free_key(key);
caam_jr_free(ctx->dev);
}
static int __init caam_pkc_init(void)
{
struct device_node *dev_node;
struct platform_device *pdev;
struct device *ctrldev;
struct caam_drv_private *priv;
u32 cha_inst, pk_inst;
int err;
dev_node = of_find_compatible_node(NULL, NULL, "fsl,sec-v4.0");
if (!dev_node) {
dev_node = of_find_compatible_node(NULL, NULL, "fsl,sec4.0");
if (!dev_node)
return -ENODEV;
}
pdev = of_find_device_by_node(dev_node);
if (!pdev) {
of_node_put(dev_node);
return -ENODEV;
}
ctrldev = &pdev->dev;
priv = dev_get_drvdata(ctrldev);
of_node_put(dev_node);
if (!priv)
return -ENODEV;
cha_inst = rd_reg32(&priv->ctrl->perfmon.cha_num_ls);
pk_inst = (cha_inst & CHA_ID_LS_PK_MASK) >> CHA_ID_LS_PK_SHIFT;
if (!pk_inst)
return -ENODEV;
err = crypto_register_akcipher(&caam_rsa);
if (err)
dev_warn(ctrldev, "%s alg registration failed\n",
caam_rsa.base.cra_driver_name);
else
dev_info(ctrldev, "caam pkc algorithms registered in /proc/crypto\n");
return err;
}
static void __exit caam_pkc_exit(void)
{
crypto_unregister_akcipher(&caam_rsa);
}
