int nx_hcall_sync(struct nx_crypto_ctx *nx_ctx,
struct vio_pfo_op *op,
u32 may_sleep)
{
int rc, retries = 10;
struct vio_dev *viodev = nx_driver.viodev;
atomic_inc(&(nx_ctx->stats->sync_ops));
do {
rc = vio_h_cop_sync(viodev, op);
} while (rc == -EBUSY && !may_sleep && retries--);
if (rc) {
dev_dbg(&viodev->dev, "vio_h_cop_sync failed: rc: %d "
"hcall rc: %ld\n", rc, op->hcall_err);
atomic_inc(&(nx_ctx->stats->errors));
atomic_set(&(nx_ctx->stats->last_error), op->hcall_err);
atomic_set(&(nx_ctx->stats->last_error_pid), current->pid);
}
return rc;
}
struct nx_sg *nx_build_sg_list(struct nx_sg *sg_head,
u8 *start_addr,
unsigned int *len,
u32 sgmax)
{
unsigned int sg_len = 0;
struct nx_sg *sg;
u64 sg_addr = (u64)start_addr;
u64 end_addr;
if (is_vmalloc_addr(start_addr))
sg_addr = page_to_phys(vmalloc_to_page(start_addr))
+ offset_in_page(sg_addr);
else
sg_addr = __pa(sg_addr);
end_addr = sg_addr + *len;
for (sg = sg_head; sg_len < *len; sg++) {
u64 next_page;
sg->addr = sg_addr;
sg_addr = min_t(u64, NX_PAGE_NUM(sg_addr + NX_PAGE_SIZE),
end_addr);
next_page = (sg->addr & PAGE_MASK) + PAGE_SIZE;
sg->len = min_t(u64, sg_addr, next_page) - sg->addr;
sg_len += sg->len;
if (sg_addr >= next_page &&
is_vmalloc_addr(start_addr + sg_len)) {
sg_addr = page_to_phys(vmalloc_to_page(
start_addr + sg_len));
end_addr = sg_addr + *len - sg_len;
}
if ((sg - sg_head) == sgmax) {
pr_err("nx: scatter/gather list overflow, pid: %d\n",
current->pid);
sg++;
break;
}
}
*len = sg_len;
return sg;
}
struct nx_sg *nx_walk_and_build(struct nx_sg *nx_dst,
unsigned int sglen,
struct scatterlist *sg_src,
unsigned int start,
unsigned int *src_len)
{
struct scatter_walk walk;
struct nx_sg *nx_sg = nx_dst;
unsigned int n, offset = 0, len = *src_len;
char *dst;
for (;;) {
scatterwalk_start(&walk, sg_src);
if (start < offset + sg_src->length)
break;
offset += sg_src->length;
sg_src = sg_next(sg_src);
}
scatterwalk_advance(&walk, start - offset);
while (len && (nx_sg - nx_dst) < sglen) {
n = scatterwalk_clamp(&walk, len);
if (!n) {
scatterwalk_start(&walk, sg_next(walk.sg));
n = scatterwalk_clamp(&walk, len);
}
dst = scatterwalk_map(&walk);
nx_sg = nx_build_sg_list(nx_sg, dst, &n, sglen - (nx_sg - nx_dst));
len -= n;
scatterwalk_unmap(dst);
scatterwalk_advance(&walk, n);
scatterwalk_done(&walk, SCATTERWALK_FROM_SG, len);
}
*src_len -= len;
return nx_sg;
}
static long int trim_sg_list(struct nx_sg *sg,
struct nx_sg *end,
unsigned int delta,
unsigned int *nbytes)
{
long int oplen;
long int data_back;
unsigned int is_delta = delta;
while (delta && end > sg) {
struct nx_sg *last = end - 1;
if (last->len > delta) {
last->len -= delta;
delta = 0;
} else {
end--;
delta -= last->len;
}
}
oplen = (sg - end) * sizeof(struct nx_sg);
if (is_delta) {
data_back = (abs(oplen) / AES_BLOCK_SIZE) * sg->len;
data_back = *nbytes - (data_back & ~(AES_BLOCK_SIZE - 1));
*nbytes -= data_back;
}
return oplen;
}
int nx_build_sg_lists(struct nx_crypto_ctx *nx_ctx,
struct blkcipher_desc *desc,
struct scatterlist *dst,
struct scatterlist *src,
unsigned int *nbytes,
unsigned int offset,
u8 *iv)
{
unsigned int delta = 0;
unsigned int total = *nbytes;
struct nx_sg *nx_insg = nx_ctx->in_sg;
struct nx_sg *nx_outsg = nx_ctx->out_sg;
unsigned int max_sg_len;
max_sg_len = min_t(u64, nx_ctx->ap->sglen,
nx_driver.of.max_sg_len/sizeof(struct nx_sg));
max_sg_len = min_t(u64, max_sg_len,
nx_ctx->ap->databytelen/NX_PAGE_SIZE);
if (iv)
memcpy(iv, desc->info, AES_BLOCK_SIZE);
*nbytes = min_t(u64, *nbytes, nx_ctx->ap->databytelen);
nx_outsg = nx_walk_and_build(nx_outsg, max_sg_len, dst,
offset, nbytes);
nx_insg = nx_walk_and_build(nx_insg, max_sg_len, src,
offset, nbytes);
if (*nbytes < total)
delta = *nbytes - (*nbytes & ~(AES_BLOCK_SIZE - 1));
nx_ctx->op.inlen = trim_sg_list(nx_ctx->in_sg, nx_insg, delta, nbytes);
nx_ctx->op.outlen = trim_sg_list(nx_ctx->out_sg, nx_outsg, delta, nbytes);
return 0;
}
void nx_ctx_init(struct nx_crypto_ctx *nx_ctx, unsigned int function)
{
spin_lock_init(&nx_ctx->lock);
memset(nx_ctx->kmem, 0, nx_ctx->kmem_len);
nx_ctx->csbcpb->csb.valid |= NX_CSB_VALID_BIT;
nx_ctx->op.flags = function;
nx_ctx->op.csbcpb = __pa(nx_ctx->csbcpb);
nx_ctx->op.in = __pa(nx_ctx->in_sg);
nx_ctx->op.out = __pa(nx_ctx->out_sg);
if (nx_ctx->csbcpb_aead) {
nx_ctx->csbcpb_aead->csb.valid |= NX_CSB_VALID_BIT;
nx_ctx->op_aead.flags = function;
nx_ctx->op_aead.csbcpb = __pa(nx_ctx->csbcpb_aead);
nx_ctx->op_aead.in = __pa(nx_ctx->in_sg);
nx_ctx->op_aead.out = __pa(nx_ctx->out_sg);
}
}
static void nx_of_update_status(struct device *dev,
struct property *p,
struct nx_of *props)
{
if (!strncmp(p->value, "okay", p->length)) {
props->status = NX_WAITING;
props->flags |= NX_OF_FLAG_STATUS_SET;
} else {
dev_info(dev, "%s: status '%s' is not 'okay'\n", __func__,
(char *)p->value);
}
}
static void nx_of_update_sglen(struct device *dev,
struct property *p,
struct nx_of *props)
{
if (p->length != sizeof(props->max_sg_len)) {
dev_err(dev, "%s: unexpected format for "
"ibm,max-sg-len property\n", __func__);
dev_dbg(dev, "%s: ibm,max-sg-len is %d bytes "
"long, expected %zd bytes\n", __func__,
p->length, sizeof(props->max_sg_len));
return;
}
props->max_sg_len = *(u32 *)p->value;
props->flags |= NX_OF_FLAG_MAXSGLEN_SET;
}
static void nx_of_update_msc(struct device *dev,
struct property *p,
struct nx_of *props)
{
struct msc_triplet *trip;
struct max_sync_cop *msc;
unsigned int bytes_so_far, i, lenp;
msc = (struct max_sync_cop *)p->value;
lenp = p->length;
bytes_so_far = 0;
while ((bytes_so_far + sizeof(struct max_sync_cop)) <= lenp) {
bytes_so_far += sizeof(struct max_sync_cop);
trip = msc->trip;
for (i = 0;
((bytes_so_far + sizeof(struct msc_triplet)) <= lenp) &&
i < msc->triplets;
i++) {
if (msc->fc >= NX_MAX_FC || msc->mode >= NX_MAX_MODE) {
dev_err(dev, "unknown function code/mode "
"combo: %d/%d (ignored)\n", msc->fc,
msc->mode);
goto next_loop;
}
if (!trip->sglen || trip->databytelen < NX_PAGE_SIZE) {
dev_warn(dev, "bogus sglen/databytelen: "
"%u/%u (ignored)\n", trip->sglen,
trip->databytelen);
goto next_loop;
}
switch (trip->keybitlen) {
case 128:
case 160:
props->ap[msc->fc][msc->mode][0].databytelen =
trip->databytelen;
props->ap[msc->fc][msc->mode][0].sglen =
trip->sglen;
break;
case 192:
props->ap[msc->fc][msc->mode][1].databytelen =
trip->databytelen;
props->ap[msc->fc][msc->mode][1].sglen =
trip->sglen;
break;
case 256:
if (msc->fc == NX_FC_AES) {
props->ap[msc->fc][msc->mode][2].
databytelen = trip->databytelen;
props->ap[msc->fc][msc->mode][2].sglen =
trip->sglen;
} else if (msc->fc == NX_FC_AES_HMAC ||
msc->fc == NX_FC_SHA) {
props->ap[msc->fc][msc->mode][1].
databytelen = trip->databytelen;
props->ap[msc->fc][msc->mode][1].sglen =
trip->sglen;
} else {
dev_warn(dev, "unknown function "
"code/key bit len combo"
": (%u/256)\n", msc->fc);
}
break;
case 512:
props->ap[msc->fc][msc->mode][2].databytelen =
trip->databytelen;
props->ap[msc->fc][msc->mode][2].sglen =
trip->sglen;
break;
default:
dev_warn(dev, "unknown function code/key bit "
"len combo: (%u/%u)\n", msc->fc,
trip->keybitlen);
break;
}
next_loop:
bytes_so_far += sizeof(struct msc_triplet);
trip++;
}
msc = (struct max_sync_cop *)trip;
}
props->flags |= NX_OF_FLAG_MAXSYNCCOP_SET;
}
static void nx_of_init(struct device *dev, struct nx_of *props)
{
struct device_node *base_node = dev->of_node;
struct property *p;
p = of_find_property(base_node, "status", NULL);
if (!p)
dev_info(dev, "%s: property 'status' not found\n", __func__);
else
nx_of_update_status(dev, p, props);
p = of_find_property(base_node, "ibm,max-sg-len", NULL);
if (!p)
dev_info(dev, "%s: property 'ibm,max-sg-len' not found\n",
__func__);
else
nx_of_update_sglen(dev, p, props);
p = of_find_property(base_node, "ibm,max-sync-cop", NULL);
if (!p)
dev_info(dev, "%s: property 'ibm,max-sync-cop' not found\n",
__func__);
else
nx_of_update_msc(dev, p, props);
}
static bool nx_check_prop(struct device *dev, u32 fc, u32 mode, int slot)
{
struct alg_props *props = &nx_driver.of.ap[fc][mode][slot];
if (!props->sglen || props->databytelen < NX_PAGE_SIZE) {
if (dev)
dev_warn(dev, "bogus sglen/databytelen for %u/%u/%u: "
"%u/%u (ignored)\n", fc, mode, slot,
props->sglen, props->databytelen);
return false;
}
return true;
}
static bool nx_check_props(struct device *dev, u32 fc, u32 mode)
{
int i;
for (i = 0; i < 3; i++)
if (!nx_check_prop(dev, fc, mode, i))
return false;
return true;
}
static int nx_register_alg(struct crypto_alg *alg, u32 fc, u32 mode)
{
return nx_check_props(&nx_driver.viodev->dev, fc, mode) ?
crypto_register_alg(alg) : 0;
}
static int nx_register_aead(struct aead_alg *alg, u32 fc, u32 mode)
{
return nx_check_props(&nx_driver.viodev->dev, fc, mode) ?
crypto_register_aead(alg) : 0;
}
static int nx_register_shash(struct shash_alg *alg, u32 fc, u32 mode, int slot)
{
return (slot >= 0 ? nx_check_prop(&nx_driver.viodev->dev,
fc, mode, slot) :
nx_check_props(&nx_driver.viodev->dev, fc, mode)) ?
crypto_register_shash(alg) : 0;
}
static void nx_unregister_alg(struct crypto_alg *alg, u32 fc, u32 mode)
{
if (nx_check_props(NULL, fc, mode))
crypto_unregister_alg(alg);
}
static void nx_unregister_aead(struct aead_alg *alg, u32 fc, u32 mode)
{
if (nx_check_props(NULL, fc, mode))
crypto_unregister_aead(alg);
}
static void nx_unregister_shash(struct shash_alg *alg, u32 fc, u32 mode,
int slot)
{
if (slot >= 0 ? nx_check_prop(NULL, fc, mode, slot) :
nx_check_props(NULL, fc, mode))
crypto_unregister_shash(alg);
}
static int nx_register_algs(void)
{
int rc = -1;
if (nx_driver.of.flags != NX_OF_FLAG_MASK_READY)
goto out;
memset(&nx_driver.stats, 0, sizeof(struct nx_stats));
rc = NX_DEBUGFS_INIT(&nx_driver);
if (rc)
goto out;
nx_driver.of.status = NX_OKAY;
rc = nx_register_alg(&nx_ecb_aes_alg, NX_FC_AES, NX_MODE_AES_ECB);
if (rc)
goto out;
rc = nx_register_alg(&nx_cbc_aes_alg, NX_FC_AES, NX_MODE_AES_CBC);
if (rc)
goto out_unreg_ecb;
rc = nx_register_alg(&nx_ctr3686_aes_alg, NX_FC_AES, NX_MODE_AES_CTR);
if (rc)
goto out_unreg_cbc;
rc = nx_register_aead(&nx_gcm_aes_alg, NX_FC_AES, NX_MODE_AES_GCM);
if (rc)
goto out_unreg_ctr3686;
rc = nx_register_aead(&nx_gcm4106_aes_alg, NX_FC_AES, NX_MODE_AES_GCM);
if (rc)
goto out_unreg_gcm;
rc = nx_register_aead(&nx_ccm_aes_alg, NX_FC_AES, NX_MODE_AES_CCM);
if (rc)
goto out_unreg_gcm4106;
rc = nx_register_aead(&nx_ccm4309_aes_alg, NX_FC_AES, NX_MODE_AES_CCM);
if (rc)
goto out_unreg_ccm;
rc = nx_register_shash(&nx_shash_sha256_alg, NX_FC_SHA, NX_MODE_SHA,
NX_PROPS_SHA256);
if (rc)
goto out_unreg_ccm4309;
rc = nx_register_shash(&nx_shash_sha512_alg, NX_FC_SHA, NX_MODE_SHA,
NX_PROPS_SHA512);
if (rc)
goto out_unreg_s256;
rc = nx_register_shash(&nx_shash_aes_xcbc_alg,
NX_FC_AES, NX_MODE_AES_XCBC_MAC, -1);
if (rc)
goto out_unreg_s512;
goto out;
out_unreg_s512:
nx_unregister_shash(&nx_shash_sha512_alg, NX_FC_SHA, NX_MODE_SHA,
NX_PROPS_SHA512);
out_unreg_s256:
nx_unregister_shash(&nx_shash_sha256_alg, NX_FC_SHA, NX_MODE_SHA,
NX_PROPS_SHA256);
out_unreg_ccm4309:
nx_unregister_aead(&nx_ccm4309_aes_alg, NX_FC_AES, NX_MODE_AES_CCM);
out_unreg_ccm:
nx_unregister_aead(&nx_ccm_aes_alg, NX_FC_AES, NX_MODE_AES_CCM);
out_unreg_gcm4106:
nx_unregister_aead(&nx_gcm4106_aes_alg, NX_FC_AES, NX_MODE_AES_GCM);
out_unreg_gcm:
nx_unregister_aead(&nx_gcm_aes_alg, NX_FC_AES, NX_MODE_AES_GCM);
out_unreg_ctr3686:
nx_unregister_alg(&nx_ctr3686_aes_alg, NX_FC_AES, NX_MODE_AES_CTR);
out_unreg_cbc:
nx_unregister_alg(&nx_cbc_aes_alg, NX_FC_AES, NX_MODE_AES_CBC);
out_unreg_ecb:
nx_unregister_alg(&nx_ecb_aes_alg, NX_FC_AES, NX_MODE_AES_ECB);
out:
return rc;
}
static int nx_crypto_ctx_init(struct nx_crypto_ctx *nx_ctx, u32 fc, u32 mode)
{
if (nx_driver.of.status != NX_OKAY) {
pr_err("Attempt to initialize NX crypto context while device "
"is not available!\n");
return -ENODEV;
}
if (mode == NX_MODE_AES_GCM || mode == NX_MODE_AES_CCM)
nx_ctx->kmem_len = (5 * NX_PAGE_SIZE) +
sizeof(struct nx_csbcpb);
else
nx_ctx->kmem_len = (4 * NX_PAGE_SIZE) +
sizeof(struct nx_csbcpb);
nx_ctx->kmem = kmalloc(nx_ctx->kmem_len, GFP_KERNEL);
if (!nx_ctx->kmem)
return -ENOMEM;
nx_ctx->csbcpb = (struct nx_csbcpb *)(round_up((u64)nx_ctx->kmem,
(u64)NX_PAGE_SIZE));
nx_ctx->in_sg = (struct nx_sg *)((u8 *)nx_ctx->csbcpb + NX_PAGE_SIZE);
nx_ctx->out_sg = (struct nx_sg *)((u8 *)nx_ctx->in_sg + NX_PAGE_SIZE);
if (mode == NX_MODE_AES_GCM || mode == NX_MODE_AES_CCM)
nx_ctx->csbcpb_aead =
(struct nx_csbcpb *)((u8 *)nx_ctx->out_sg +
NX_PAGE_SIZE);
nx_ctx->stats = &nx_driver.stats;
memcpy(nx_ctx->props, nx_driver.of.ap[fc][mode],
sizeof(struct alg_props) * 3);
return 0;
}
int nx_crypto_ctx_aes_ccm_init(struct crypto_aead *tfm)
{
crypto_aead_set_reqsize(tfm, sizeof(struct nx_ccm_rctx));
return nx_crypto_ctx_init(crypto_aead_ctx(tfm), NX_FC_AES,
NX_MODE_AES_CCM);
}
int nx_crypto_ctx_aes_gcm_init(struct crypto_aead *tfm)
{
crypto_aead_set_reqsize(tfm, sizeof(struct nx_gcm_rctx));
return nx_crypto_ctx_init(crypto_aead_ctx(tfm), NX_FC_AES,
NX_MODE_AES_GCM);
}
int nx_crypto_ctx_aes_ctr_init(struct crypto_tfm *tfm)
{
return nx_crypto_ctx_init(crypto_tfm_ctx(tfm), NX_FC_AES,
NX_MODE_AES_CTR);
}
int nx_crypto_ctx_aes_cbc_init(struct crypto_tfm *tfm)
{
return nx_crypto_ctx_init(crypto_tfm_ctx(tfm), NX_FC_AES,
NX_MODE_AES_CBC);
}
int nx_crypto_ctx_aes_ecb_init(struct crypto_tfm *tfm)
{
return nx_crypto_ctx_init(crypto_tfm_ctx(tfm), NX_FC_AES,
NX_MODE_AES_ECB);
}
int nx_crypto_ctx_sha_init(struct crypto_tfm *tfm)
{
return nx_crypto_ctx_init(crypto_tfm_ctx(tfm), NX_FC_SHA, NX_MODE_SHA);
}
int nx_crypto_ctx_aes_xcbc_init(struct crypto_tfm *tfm)
{
return nx_crypto_ctx_init(crypto_tfm_ctx(tfm), NX_FC_AES,
NX_MODE_AES_XCBC_MAC);
}
void nx_crypto_ctx_exit(struct crypto_tfm *tfm)
{
struct nx_crypto_ctx *nx_ctx = crypto_tfm_ctx(tfm);
kzfree(nx_ctx->kmem);
nx_ctx->csbcpb = NULL;
nx_ctx->csbcpb_aead = NULL;
nx_ctx->in_sg = NULL;
nx_ctx->out_sg = NULL;
}
void nx_crypto_ctx_aead_exit(struct crypto_aead *tfm)
{
struct nx_crypto_ctx *nx_ctx = crypto_aead_ctx(tfm);
kzfree(nx_ctx->kmem);
}
static int nx_probe(struct vio_dev *viodev, const struct vio_device_id *id)
{
dev_dbg(&viodev->dev, "driver probed: %s resource id: 0x%x\n",
viodev->name, viodev->resource_id);
if (nx_driver.viodev) {
dev_err(&viodev->dev, "%s: Attempt to register more than one "
"instance of the hardware\n", __func__);
return -EINVAL;
}
nx_driver.viodev = viodev;
nx_of_init(&viodev->dev, &nx_driver.of);
return nx_register_algs();
}
static int nx_remove(struct vio_dev *viodev)
{
dev_dbg(&viodev->dev, "entering nx_remove for UA 0x%x\n",
viodev->unit_address);
if (nx_driver.of.status == NX_OKAY) {
NX_DEBUGFS_FINI(&nx_driver);
nx_unregister_shash(&nx_shash_aes_xcbc_alg,
NX_FC_AES, NX_MODE_AES_XCBC_MAC, -1);
nx_unregister_shash(&nx_shash_sha512_alg,
NX_FC_SHA, NX_MODE_SHA, NX_PROPS_SHA256);
nx_unregister_shash(&nx_shash_sha256_alg,
NX_FC_SHA, NX_MODE_SHA, NX_PROPS_SHA512);
nx_unregister_aead(&nx_ccm4309_aes_alg,
NX_FC_AES, NX_MODE_AES_CCM);
nx_unregister_aead(&nx_ccm_aes_alg, NX_FC_AES, NX_MODE_AES_CCM);
nx_unregister_aead(&nx_gcm4106_aes_alg,
NX_FC_AES, NX_MODE_AES_GCM);
nx_unregister_aead(&nx_gcm_aes_alg,
NX_FC_AES, NX_MODE_AES_GCM);
nx_unregister_alg(&nx_ctr3686_aes_alg,
NX_FC_AES, NX_MODE_AES_CTR);
nx_unregister_alg(&nx_cbc_aes_alg, NX_FC_AES, NX_MODE_AES_CBC);
nx_unregister_alg(&nx_ecb_aes_alg, NX_FC_AES, NX_MODE_AES_ECB);
}
return 0;
}
static int __init nx_init(void)
{
return vio_register_driver(&nx_driver.viodriver);
}
static void __exit nx_fini(void)
{
vio_unregister_driver(&nx_driver.viodriver);
}
