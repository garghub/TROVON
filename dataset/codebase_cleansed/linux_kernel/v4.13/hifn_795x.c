static inline u32 hifn_read_0(struct hifn_device *dev, u32 reg)
{
return readl(dev->bar[0] + reg);
}
static inline u32 hifn_read_1(struct hifn_device *dev, u32 reg)
{
return readl(dev->bar[1] + reg);
}
static inline void hifn_write_0(struct hifn_device *dev, u32 reg, u32 val)
{
writel((__force u32)cpu_to_le32(val), dev->bar[0] + reg);
}
static inline void hifn_write_1(struct hifn_device *dev, u32 reg, u32 val)
{
writel((__force u32)cpu_to_le32(val), dev->bar[1] + reg);
}
static void hifn_wait_puc(struct hifn_device *dev)
{
int i;
u32 ret;
for (i = 10000; i > 0; --i) {
ret = hifn_read_0(dev, HIFN_0_PUCTRL);
if (!(ret & HIFN_PUCTRL_RESET))
break;
udelay(1);
}
if (!i)
dev_err(&dev->pdev->dev, "Failed to reset PUC unit.\n");
}
static void hifn_reset_puc(struct hifn_device *dev)
{
hifn_write_0(dev, HIFN_0_PUCTRL, HIFN_PUCTRL_DMAENA);
hifn_wait_puc(dev);
}
static void hifn_stop_device(struct hifn_device *dev)
{
hifn_write_1(dev, HIFN_1_DMA_CSR,
HIFN_DMACSR_D_CTRL_DIS | HIFN_DMACSR_R_CTRL_DIS |
HIFN_DMACSR_S_CTRL_DIS | HIFN_DMACSR_C_CTRL_DIS);
hifn_write_0(dev, HIFN_0_PUIER, 0);
hifn_write_1(dev, HIFN_1_DMA_IER, 0);
}
static void hifn_reset_dma(struct hifn_device *dev, int full)
{
hifn_stop_device(dev);
hifn_write_1(dev, HIFN_1_DMA_CNFG, HIFN_DMACNFG_MSTRESET |
HIFN_DMACNFG_DMARESET | HIFN_DMACNFG_MODE);
mdelay(1);
if (full) {
hifn_write_1(dev, HIFN_1_DMA_CNFG, HIFN_DMACNFG_MODE);
mdelay(1);
} else {
hifn_write_1(dev, HIFN_1_DMA_CNFG, HIFN_DMACNFG_MODE |
HIFN_DMACNFG_MSTRESET);
hifn_reset_puc(dev);
}
hifn_write_1(dev, HIFN_1_DMA_CNFG, HIFN_DMACNFG_MSTRESET |
HIFN_DMACNFG_DMARESET | HIFN_DMACNFG_MODE);
hifn_reset_puc(dev);
}
static u32 hifn_next_signature(u32 a, u_int cnt)
{
int i;
u32 v;
for (i = 0; i < cnt; i++) {
v = a & 0x80080125;
v ^= v >> 16;
v ^= v >> 8;
v ^= v >> 4;
v ^= v >> 2;
v ^= v >> 1;
a = (v & 1) ^ (a << 1);
}
return a;
}
static int hifn_rng_data_present(struct hwrng *rng, int wait)
{
struct hifn_device *dev = (struct hifn_device *)rng->priv;
s64 nsec;
nsec = ktime_to_ns(ktime_sub(ktime_get(), dev->rngtime));
nsec -= dev->rng_wait_time;
if (nsec <= 0)
return 1;
if (!wait)
return 0;
ndelay(nsec);
return 1;
}
static int hifn_rng_data_read(struct hwrng *rng, u32 *data)
{
struct hifn_device *dev = (struct hifn_device *)rng->priv;
*data = hifn_read_1(dev, HIFN_1_RNG_DATA);
dev->rngtime = ktime_get();
return 4;
}
static int hifn_register_rng(struct hifn_device *dev)
{
dev->rng_wait_time = DIV_ROUND_UP_ULL(NSEC_PER_SEC,
dev->pk_clk_freq) * 256;
dev->rng.name = dev->name;
dev->rng.data_present = hifn_rng_data_present,
dev->rng.data_read = hifn_rng_data_read,
dev->rng.priv = (unsigned long)dev;
return hwrng_register(&dev->rng);
}
static void hifn_unregister_rng(struct hifn_device *dev)
{
hwrng_unregister(&dev->rng);
}
static int hifn_init_pubrng(struct hifn_device *dev)
{
int i;
hifn_write_1(dev, HIFN_1_PUB_RESET, hifn_read_1(dev, HIFN_1_PUB_RESET) |
HIFN_PUBRST_RESET);
for (i = 100; i > 0; --i) {
mdelay(1);
if ((hifn_read_1(dev, HIFN_1_PUB_RESET) & HIFN_PUBRST_RESET) == 0)
break;
}
if (!i) {
dev_err(&dev->pdev->dev, "Failed to initialise public key engine.\n");
} else {
hifn_write_1(dev, HIFN_1_PUB_IEN, HIFN_PUBIEN_DONE);
dev->dmareg |= HIFN_DMAIER_PUBDONE;
hifn_write_1(dev, HIFN_1_DMA_IER, dev->dmareg);
dev_dbg(&dev->pdev->dev, "Public key engine has been successfully initialised.\n");
}
hifn_write_1(dev, HIFN_1_RNG_CONFIG,
hifn_read_1(dev, HIFN_1_RNG_CONFIG) | HIFN_RNGCFG_ENA);
dev_dbg(&dev->pdev->dev, "RNG engine has been successfully initialised.\n");
#ifdef CONFIG_CRYPTO_DEV_HIFN_795X_RNG
hifn_read_1(dev, HIFN_1_RNG_DATA);
dev->rngtime = ktime_get();
#endif
return 0;
}
static int hifn_enable_crypto(struct hifn_device *dev)
{
u32 dmacfg, addr;
char *offtbl = NULL;
int i;
for (i = 0; i < ARRAY_SIZE(pci2id); i++) {
if (pci2id[i].pci_vendor == dev->pdev->vendor &&
pci2id[i].pci_prod == dev->pdev->device) {
offtbl = pci2id[i].card_id;
break;
}
}
if (!offtbl) {
dev_err(&dev->pdev->dev, "Unknown card!\n");
return -ENODEV;
}
dmacfg = hifn_read_1(dev, HIFN_1_DMA_CNFG);
hifn_write_1(dev, HIFN_1_DMA_CNFG,
HIFN_DMACNFG_UNLOCK | HIFN_DMACNFG_MSTRESET |
HIFN_DMACNFG_DMARESET | HIFN_DMACNFG_MODE);
mdelay(1);
addr = hifn_read_1(dev, HIFN_1_UNLOCK_SECRET1);
mdelay(1);
hifn_write_1(dev, HIFN_1_UNLOCK_SECRET2, 0);
mdelay(1);
for (i = 0; i < 12; ++i) {
addr = hifn_next_signature(addr, offtbl[i] + 0x101);
hifn_write_1(dev, HIFN_1_UNLOCK_SECRET2, addr);
mdelay(1);
}
hifn_write_1(dev, HIFN_1_DMA_CNFG, dmacfg);
dev_dbg(&dev->pdev->dev, "%s %s.\n", dev->name, pci_name(dev->pdev));
return 0;
}
static void hifn_init_dma(struct hifn_device *dev)
{
struct hifn_dma *dma = (struct hifn_dma *)dev->desc_virt;
u32 dptr = dev->desc_dma;
int i;
for (i = 0; i < HIFN_D_CMD_RSIZE; ++i)
dma->cmdr[i].p = __cpu_to_le32(dptr +
offsetof(struct hifn_dma, command_bufs[i][0]));
for (i = 0; i < HIFN_D_RES_RSIZE; ++i)
dma->resr[i].p = __cpu_to_le32(dptr +
offsetof(struct hifn_dma, result_bufs[i][0]));
dma->cmdr[HIFN_D_CMD_RSIZE].p = __cpu_to_le32(dptr +
offsetof(struct hifn_dma, cmdr[0]));
dma->srcr[HIFN_D_SRC_RSIZE].p = __cpu_to_le32(dptr +
offsetof(struct hifn_dma, srcr[0]));
dma->dstr[HIFN_D_DST_RSIZE].p = __cpu_to_le32(dptr +
offsetof(struct hifn_dma, dstr[0]));
dma->resr[HIFN_D_RES_RSIZE].p = __cpu_to_le32(dptr +
offsetof(struct hifn_dma, resr[0]));
dma->cmdu = dma->srcu = dma->dstu = dma->resu = 0;
dma->cmdi = dma->srci = dma->dsti = dma->resi = 0;
dma->cmdk = dma->srck = dma->dstk = dma->resk = 0;
}
static void hifn_init_pll(struct hifn_device *dev)
{
unsigned int freq, m;
u32 pllcfg;
pllcfg = HIFN_1_PLL | HIFN_PLL_RESERVED_1;
if (strncmp(hifn_pll_ref, "ext", 3) == 0)
pllcfg |= HIFN_PLL_REF_CLK_PLL;
else
pllcfg |= HIFN_PLL_REF_CLK_HBI;
if (hifn_pll_ref[3] != '\0')
freq = simple_strtoul(hifn_pll_ref + 3, NULL, 10);
else {
freq = 66;
dev_info(&dev->pdev->dev, "assuming %uMHz clock speed, override with hifn_pll_ref=%.3s<frequency>\n",
freq, hifn_pll_ref);
}
m = HIFN_PLL_FCK_MAX / freq;
pllcfg |= (m / 2 - 1) << HIFN_PLL_ND_SHIFT;
if (m <= 8)
pllcfg |= HIFN_PLL_IS_1_8;
else
pllcfg |= HIFN_PLL_IS_9_12;
hifn_write_1(dev, HIFN_1_PLL, pllcfg |
HIFN_PLL_PK_CLK_HBI | HIFN_PLL_PE_CLK_HBI | HIFN_PLL_BP);
mdelay(10);
hifn_write_1(dev, HIFN_1_PLL, pllcfg |
HIFN_PLL_PK_CLK_HBI | HIFN_PLL_PE_CLK_HBI);
hifn_write_1(dev, HIFN_1_PLL, pllcfg |
HIFN_PLL_PK_CLK_PLL | HIFN_PLL_PE_CLK_PLL);
dev->pk_clk_freq = 1000000 * (freq + 1) * m / 2;
}
static void hifn_init_registers(struct hifn_device *dev)
{
u32 dptr = dev->desc_dma;
hifn_write_0(dev, HIFN_0_PUCTRL, HIFN_PUCTRL_DMAENA);
hifn_write_0(dev, HIFN_0_FIFOCNFG, HIFN_FIFOCNFG_THRESHOLD);
hifn_write_0(dev, HIFN_0_PUIER, HIFN_PUIER_DSTOVER);
hifn_write_1(dev, HIFN_1_DMA_CRAR, dptr +
offsetof(struct hifn_dma, cmdr[0]));
hifn_write_1(dev, HIFN_1_DMA_SRAR, dptr +
offsetof(struct hifn_dma, srcr[0]));
hifn_write_1(dev, HIFN_1_DMA_DRAR, dptr +
offsetof(struct hifn_dma, dstr[0]));
hifn_write_1(dev, HIFN_1_DMA_RRAR, dptr +
offsetof(struct hifn_dma, resr[0]));
mdelay(2);
#if 0
hifn_write_1(dev, HIFN_1_DMA_CSR,
HIFN_DMACSR_D_CTRL_DIS | HIFN_DMACSR_R_CTRL_DIS |
HIFN_DMACSR_S_CTRL_DIS | HIFN_DMACSR_C_CTRL_DIS |
HIFN_DMACSR_D_ABORT | HIFN_DMACSR_D_DONE | HIFN_DMACSR_D_LAST |
HIFN_DMACSR_D_WAIT | HIFN_DMACSR_D_OVER |
HIFN_DMACSR_R_ABORT | HIFN_DMACSR_R_DONE | HIFN_DMACSR_R_LAST |
HIFN_DMACSR_R_WAIT | HIFN_DMACSR_R_OVER |
HIFN_DMACSR_S_ABORT | HIFN_DMACSR_S_DONE | HIFN_DMACSR_S_LAST |
HIFN_DMACSR_S_WAIT |
HIFN_DMACSR_C_ABORT | HIFN_DMACSR_C_DONE | HIFN_DMACSR_C_LAST |
HIFN_DMACSR_C_WAIT |
HIFN_DMACSR_ENGINE |
HIFN_DMACSR_PUBDONE);
#else
hifn_write_1(dev, HIFN_1_DMA_CSR,
HIFN_DMACSR_C_CTRL_ENA | HIFN_DMACSR_S_CTRL_ENA |
HIFN_DMACSR_D_CTRL_ENA | HIFN_DMACSR_R_CTRL_ENA |
HIFN_DMACSR_D_ABORT | HIFN_DMACSR_D_DONE | HIFN_DMACSR_D_LAST |
HIFN_DMACSR_D_WAIT | HIFN_DMACSR_D_OVER |
HIFN_DMACSR_R_ABORT | HIFN_DMACSR_R_DONE | HIFN_DMACSR_R_LAST |
HIFN_DMACSR_R_WAIT | HIFN_DMACSR_R_OVER |
HIFN_DMACSR_S_ABORT | HIFN_DMACSR_S_DONE | HIFN_DMACSR_S_LAST |
HIFN_DMACSR_S_WAIT |
HIFN_DMACSR_C_ABORT | HIFN_DMACSR_C_DONE | HIFN_DMACSR_C_LAST |
HIFN_DMACSR_C_WAIT |
HIFN_DMACSR_ENGINE |
HIFN_DMACSR_PUBDONE);
#endif
hifn_read_1(dev, HIFN_1_DMA_CSR);
dev->dmareg |= HIFN_DMAIER_R_DONE | HIFN_DMAIER_C_ABORT |
HIFN_DMAIER_D_OVER | HIFN_DMAIER_R_OVER |
HIFN_DMAIER_S_ABORT | HIFN_DMAIER_D_ABORT | HIFN_DMAIER_R_ABORT |
HIFN_DMAIER_ENGINE;
dev->dmareg &= ~HIFN_DMAIER_C_WAIT;
hifn_write_1(dev, HIFN_1_DMA_IER, dev->dmareg);
hifn_read_1(dev, HIFN_1_DMA_IER);
#if 0
hifn_write_0(dev, HIFN_0_PUCNFG, HIFN_PUCNFG_ENCCNFG |
HIFN_PUCNFG_DRFR_128 | HIFN_PUCNFG_TCALLPHASES |
HIFN_PUCNFG_TCDRVTOTEM | HIFN_PUCNFG_BUS32 |
HIFN_PUCNFG_DRAM);
#else
hifn_write_0(dev, HIFN_0_PUCNFG, 0x10342);
#endif
hifn_init_pll(dev);
hifn_write_0(dev, HIFN_0_PUISR, HIFN_PUISR_DSTOVER);
hifn_write_1(dev, HIFN_1_DMA_CNFG, HIFN_DMACNFG_MSTRESET |
HIFN_DMACNFG_DMARESET | HIFN_DMACNFG_MODE | HIFN_DMACNFG_LAST |
((HIFN_POLL_FREQUENCY << 16 ) & HIFN_DMACNFG_POLLFREQ) |
((HIFN_POLL_SCALAR << 8) & HIFN_DMACNFG_POLLINVAL));
}
static int hifn_setup_base_command(struct hifn_device *dev, u8 *buf,
unsigned dlen, unsigned slen, u16 mask, u8 snum)
{
struct hifn_base_command *base_cmd;
u8 *buf_pos = buf;
base_cmd = (struct hifn_base_command *)buf_pos;
base_cmd->masks = __cpu_to_le16(mask);
base_cmd->total_source_count =
__cpu_to_le16(slen & HIFN_BASE_CMD_LENMASK_LO);
base_cmd->total_dest_count =
__cpu_to_le16(dlen & HIFN_BASE_CMD_LENMASK_LO);
dlen >>= 16;
slen >>= 16;
base_cmd->session_num = __cpu_to_le16(snum |
((slen << HIFN_BASE_CMD_SRCLEN_S) & HIFN_BASE_CMD_SRCLEN_M) |
((dlen << HIFN_BASE_CMD_DSTLEN_S) & HIFN_BASE_CMD_DSTLEN_M));
return sizeof(struct hifn_base_command);
}
static int hifn_setup_crypto_command(struct hifn_device *dev,
u8 *buf, unsigned dlen, unsigned slen,
u8 *key, int keylen, u8 *iv, int ivsize, u16 mode)
{
struct hifn_dma *dma = (struct hifn_dma *)dev->desc_virt;
struct hifn_crypt_command *cry_cmd;
u8 *buf_pos = buf;
u16 cmd_len;
cry_cmd = (struct hifn_crypt_command *)buf_pos;
cry_cmd->source_count = __cpu_to_le16(dlen & 0xffff);
dlen >>= 16;
cry_cmd->masks = __cpu_to_le16(mode |
((dlen << HIFN_CRYPT_CMD_SRCLEN_S) &
HIFN_CRYPT_CMD_SRCLEN_M));
cry_cmd->header_skip = 0;
cry_cmd->reserved = 0;
buf_pos += sizeof(struct hifn_crypt_command);
dma->cmdu++;
if (dma->cmdu > 1) {
dev->dmareg |= HIFN_DMAIER_C_WAIT;
hifn_write_1(dev, HIFN_1_DMA_IER, dev->dmareg);
}
if (keylen) {
memcpy(buf_pos, key, keylen);
buf_pos += keylen;
}
if (ivsize) {
memcpy(buf_pos, iv, ivsize);
buf_pos += ivsize;
}
cmd_len = buf_pos - buf;
return cmd_len;
}
static int hifn_setup_cmd_desc(struct hifn_device *dev,
struct hifn_context *ctx, struct hifn_request_context *rctx,
void *priv, unsigned int nbytes)
{
struct hifn_dma *dma = (struct hifn_dma *)dev->desc_virt;
int cmd_len, sa_idx;
u8 *buf, *buf_pos;
u16 mask;
sa_idx = dma->cmdi;
buf_pos = buf = dma->command_bufs[dma->cmdi];
mask = 0;
switch (rctx->op) {
case ACRYPTO_OP_DECRYPT:
mask = HIFN_BASE_CMD_CRYPT | HIFN_BASE_CMD_DECODE;
break;
case ACRYPTO_OP_ENCRYPT:
mask = HIFN_BASE_CMD_CRYPT;
break;
case ACRYPTO_OP_HMAC:
mask = HIFN_BASE_CMD_MAC;
break;
default:
goto err_out;
}
buf_pos += hifn_setup_base_command(dev, buf_pos, nbytes,
nbytes, mask, dev->snum);
if (rctx->op == ACRYPTO_OP_ENCRYPT || rctx->op == ACRYPTO_OP_DECRYPT) {
u16 md = 0;
if (ctx->keysize)
md |= HIFN_CRYPT_CMD_NEW_KEY;
if (rctx->iv && rctx->mode != ACRYPTO_MODE_ECB)
md |= HIFN_CRYPT_CMD_NEW_IV;
switch (rctx->mode) {
case ACRYPTO_MODE_ECB:
md |= HIFN_CRYPT_CMD_MODE_ECB;
break;
case ACRYPTO_MODE_CBC:
md |= HIFN_CRYPT_CMD_MODE_CBC;
break;
case ACRYPTO_MODE_CFB:
md |= HIFN_CRYPT_CMD_MODE_CFB;
break;
case ACRYPTO_MODE_OFB:
md |= HIFN_CRYPT_CMD_MODE_OFB;
break;
default:
goto err_out;
}
switch (rctx->type) {
case ACRYPTO_TYPE_AES_128:
if (ctx->keysize != 16)
goto err_out;
md |= HIFN_CRYPT_CMD_KSZ_128 |
HIFN_CRYPT_CMD_ALG_AES;
break;
case ACRYPTO_TYPE_AES_192:
if (ctx->keysize != 24)
goto err_out;
md |= HIFN_CRYPT_CMD_KSZ_192 |
HIFN_CRYPT_CMD_ALG_AES;
break;
case ACRYPTO_TYPE_AES_256:
if (ctx->keysize != 32)
goto err_out;
md |= HIFN_CRYPT_CMD_KSZ_256 |
HIFN_CRYPT_CMD_ALG_AES;
break;
case ACRYPTO_TYPE_3DES:
if (ctx->keysize != 24)
goto err_out;
md |= HIFN_CRYPT_CMD_ALG_3DES;
break;
case ACRYPTO_TYPE_DES:
if (ctx->keysize != 8)
goto err_out;
md |= HIFN_CRYPT_CMD_ALG_DES;
break;
default:
goto err_out;
}
buf_pos += hifn_setup_crypto_command(dev, buf_pos,
nbytes, nbytes, ctx->key, ctx->keysize,
rctx->iv, rctx->ivsize, md);
}
dev->sa[sa_idx] = priv;
dev->started++;
cmd_len = buf_pos - buf;
dma->cmdr[dma->cmdi].l = __cpu_to_le32(cmd_len | HIFN_D_VALID |
HIFN_D_LAST | HIFN_D_MASKDONEIRQ);
if (++dma->cmdi == HIFN_D_CMD_RSIZE) {
dma->cmdr[dma->cmdi].l = __cpu_to_le32(
HIFN_D_VALID | HIFN_D_LAST |
HIFN_D_MASKDONEIRQ | HIFN_D_JUMP);
dma->cmdi = 0;
} else {
dma->cmdr[dma->cmdi - 1].l |= __cpu_to_le32(HIFN_D_VALID);
}
if (!(dev->flags & HIFN_FLAG_CMD_BUSY)) {
hifn_write_1(dev, HIFN_1_DMA_CSR, HIFN_DMACSR_C_CTRL_ENA);
dev->flags |= HIFN_FLAG_CMD_BUSY;
}
return 0;
err_out:
return -EINVAL;
}
static int hifn_setup_src_desc(struct hifn_device *dev, struct page *page,
unsigned int offset, unsigned int size, int last)
{
struct hifn_dma *dma = (struct hifn_dma *)dev->desc_virt;
int idx;
dma_addr_t addr;
addr = pci_map_page(dev->pdev, page, offset, size, PCI_DMA_TODEVICE);
idx = dma->srci;
dma->srcr[idx].p = __cpu_to_le32(addr);
dma->srcr[idx].l = __cpu_to_le32(size | HIFN_D_VALID |
HIFN_D_MASKDONEIRQ | (last ? HIFN_D_LAST : 0));
if (++idx == HIFN_D_SRC_RSIZE) {
dma->srcr[idx].l = __cpu_to_le32(HIFN_D_VALID |
HIFN_D_JUMP | HIFN_D_MASKDONEIRQ |
(last ? HIFN_D_LAST : 0));
idx = 0;
}
dma->srci = idx;
dma->srcu++;
if (!(dev->flags & HIFN_FLAG_SRC_BUSY)) {
hifn_write_1(dev, HIFN_1_DMA_CSR, HIFN_DMACSR_S_CTRL_ENA);
dev->flags |= HIFN_FLAG_SRC_BUSY;
}
return size;
}
static void hifn_setup_res_desc(struct hifn_device *dev)
{
struct hifn_dma *dma = (struct hifn_dma *)dev->desc_virt;
dma->resr[dma->resi].l = __cpu_to_le32(HIFN_USED_RESULT |
HIFN_D_VALID | HIFN_D_LAST);
if (++dma->resi == HIFN_D_RES_RSIZE) {
dma->resr[HIFN_D_RES_RSIZE].l = __cpu_to_le32(HIFN_D_VALID |
HIFN_D_JUMP | HIFN_D_MASKDONEIRQ | HIFN_D_LAST);
dma->resi = 0;
}
dma->resu++;
if (!(dev->flags & HIFN_FLAG_RES_BUSY)) {
hifn_write_1(dev, HIFN_1_DMA_CSR, HIFN_DMACSR_R_CTRL_ENA);
dev->flags |= HIFN_FLAG_RES_BUSY;
}
}
static void hifn_setup_dst_desc(struct hifn_device *dev, struct page *page,
unsigned offset, unsigned size, int last)
{
struct hifn_dma *dma = (struct hifn_dma *)dev->desc_virt;
int idx;
dma_addr_t addr;
addr = pci_map_page(dev->pdev, page, offset, size, PCI_DMA_FROMDEVICE);
idx = dma->dsti;
dma->dstr[idx].p = __cpu_to_le32(addr);
dma->dstr[idx].l = __cpu_to_le32(size | HIFN_D_VALID |
HIFN_D_MASKDONEIRQ | (last ? HIFN_D_LAST : 0));
if (++idx == HIFN_D_DST_RSIZE) {
dma->dstr[idx].l = __cpu_to_le32(HIFN_D_VALID |
HIFN_D_JUMP | HIFN_D_MASKDONEIRQ |
(last ? HIFN_D_LAST : 0));
idx = 0;
}
dma->dsti = idx;
dma->dstu++;
if (!(dev->flags & HIFN_FLAG_DST_BUSY)) {
hifn_write_1(dev, HIFN_1_DMA_CSR, HIFN_DMACSR_D_CTRL_ENA);
dev->flags |= HIFN_FLAG_DST_BUSY;
}
}
static int hifn_setup_dma(struct hifn_device *dev,
struct hifn_context *ctx, struct hifn_request_context *rctx,
struct scatterlist *src, struct scatterlist *dst,
unsigned int nbytes, void *priv)
{
struct scatterlist *t;
struct page *spage, *dpage;
unsigned int soff, doff;
unsigned int n, len;
n = nbytes;
while (n) {
spage = sg_page(src);
soff = src->offset;
len = min(src->length, n);
hifn_setup_src_desc(dev, spage, soff, len, n - len == 0);
src++;
n -= len;
}
t = &rctx->walk.cache[0];
n = nbytes;
while (n) {
if (t->length && rctx->walk.flags & ASYNC_FLAGS_MISALIGNED) {
BUG_ON(!sg_page(t));
dpage = sg_page(t);
doff = 0;
len = t->length;
} else {
BUG_ON(!sg_page(dst));
dpage = sg_page(dst);
doff = dst->offset;
len = dst->length;
}
len = min(len, n);
hifn_setup_dst_desc(dev, dpage, doff, len, n - len == 0);
dst++;
t++;
n -= len;
}
hifn_setup_cmd_desc(dev, ctx, rctx, priv, nbytes);
hifn_setup_res_desc(dev);
return 0;
}
static int hifn_cipher_walk_init(struct hifn_cipher_walk *w,
int num, gfp_t gfp_flags)
{
int i;
num = min(ASYNC_SCATTERLIST_CACHE, num);
sg_init_table(w->cache, num);
w->num = 0;
for (i = 0; i < num; ++i) {
struct page *page = alloc_page(gfp_flags);
struct scatterlist *s;
if (!page)
break;
s = &w->cache[i];
sg_set_page(s, page, PAGE_SIZE, 0);
w->num++;
}
return i;
}
static void hifn_cipher_walk_exit(struct hifn_cipher_walk *w)
{
int i;
for (i = 0; i < w->num; ++i) {
struct scatterlist *s = &w->cache[i];
__free_page(sg_page(s));
s->length = 0;
}
w->num = 0;
}
static int ablkcipher_add(unsigned int *drestp, struct scatterlist *dst,
unsigned int size, unsigned int *nbytesp)
{
unsigned int copy, drest = *drestp, nbytes = *nbytesp;
int idx = 0;
if (drest < size || size > nbytes)
return -EINVAL;
while (size) {
copy = min3(drest, size, dst->length);
size -= copy;
drest -= copy;
nbytes -= copy;
pr_debug("%s: copy: %u, size: %u, drest: %u, nbytes: %u.\n",
__func__, copy, size, drest, nbytes);
dst++;
idx++;
}
*nbytesp = nbytes;
*drestp = drest;
return idx;
}
static int hifn_cipher_walk(struct ablkcipher_request *req,
struct hifn_cipher_walk *w)
{
struct scatterlist *dst, *t;
unsigned int nbytes = req->nbytes, offset, copy, diff;
int idx, tidx, err;
tidx = idx = 0;
offset = 0;
while (nbytes) {
if (idx >= w->num && (w->flags & ASYNC_FLAGS_MISALIGNED))
return -EINVAL;
dst = &req->dst[idx];
pr_debug("\n%s: dlen: %u, doff: %u, offset: %u, nbytes: %u.\n",
__func__, dst->length, dst->offset, offset, nbytes);
if (!IS_ALIGNED(dst->offset, HIFN_D_DST_DALIGN) ||
!IS_ALIGNED(dst->length, HIFN_D_DST_DALIGN) ||
offset) {
unsigned slen = min(dst->length - offset, nbytes);
unsigned dlen = PAGE_SIZE;
t = &w->cache[idx];
err = ablkcipher_add(&dlen, dst, slen, &nbytes);
if (err < 0)
return err;
idx += err;
copy = slen & ~(HIFN_D_DST_DALIGN - 1);
diff = slen & (HIFN_D_DST_DALIGN - 1);
if (dlen < nbytes) {
nbytes += diff;
pr_err("%s: dlen: %u, nbytes: %u, slen: %u, offset: %u.\n",
__func__, dlen, nbytes, slen, offset);
pr_err("%s: please contact author to fix this "
"issue, generally you should not catch "
"this path under any condition but who "
"knows how did you use crypto code.\n"
"Thank you.\n", __func__);
BUG();
} else {
copy += diff + nbytes;
dst = &req->dst[idx];
err = ablkcipher_add(&dlen, dst, nbytes, &nbytes);
if (err < 0)
return err;
idx += err;
}
t->length = copy;
t->offset = offset;
} else {
nbytes -= min(dst->length, nbytes);
idx++;
}
tidx++;
}
return tidx;
}
static int hifn_setup_session(struct ablkcipher_request *req)
{
struct hifn_context *ctx = crypto_tfm_ctx(req->base.tfm);
struct hifn_request_context *rctx = ablkcipher_request_ctx(req);
struct hifn_device *dev = ctx->dev;
unsigned long dlen, flags;
unsigned int nbytes = req->nbytes, idx = 0;
int err = -EINVAL, sg_num;
struct scatterlist *dst;
if (rctx->iv && !rctx->ivsize && rctx->mode != ACRYPTO_MODE_ECB)
goto err_out_exit;
rctx->walk.flags = 0;
while (nbytes) {
dst = &req->dst[idx];
dlen = min(dst->length, nbytes);
if (!IS_ALIGNED(dst->offset, HIFN_D_DST_DALIGN) ||
!IS_ALIGNED(dlen, HIFN_D_DST_DALIGN))
rctx->walk.flags |= ASYNC_FLAGS_MISALIGNED;
nbytes -= dlen;
idx++;
}
if (rctx->walk.flags & ASYNC_FLAGS_MISALIGNED) {
err = hifn_cipher_walk_init(&rctx->walk, idx, GFP_ATOMIC);
if (err < 0)
return err;
}
sg_num = hifn_cipher_walk(req, &rctx->walk);
if (sg_num < 0) {
err = sg_num;
goto err_out_exit;
}
spin_lock_irqsave(&dev->lock, flags);
if (dev->started + sg_num > HIFN_QUEUE_LENGTH) {
err = -EAGAIN;
goto err_out;
}
err = hifn_setup_dma(dev, ctx, rctx, req->src, req->dst, req->nbytes, req);
if (err)
goto err_out;
dev->snum++;
dev->active = HIFN_DEFAULT_ACTIVE_NUM;
spin_unlock_irqrestore(&dev->lock, flags);
return 0;
err_out:
spin_unlock_irqrestore(&dev->lock, flags);
err_out_exit:
if (err) {
dev_info(&dev->pdev->dev, "iv: %p [%d], key: %p [%d], mode: %u, op: %u, "
"type: %u, err: %d.\n",
rctx->iv, rctx->ivsize,
ctx->key, ctx->keysize,
rctx->mode, rctx->op, rctx->type, err);
}
return err;
}
static int hifn_start_device(struct hifn_device *dev)
{
int err;
dev->started = dev->active = 0;
hifn_reset_dma(dev, 1);
err = hifn_enable_crypto(dev);
if (err)
return err;
hifn_reset_puc(dev);
hifn_init_dma(dev);
hifn_init_registers(dev);
hifn_init_pubrng(dev);
return 0;
}
static int ablkcipher_get(void *saddr, unsigned int *srestp, unsigned int offset,
struct scatterlist *dst, unsigned int size, unsigned int *nbytesp)
{
unsigned int srest = *srestp, nbytes = *nbytesp, copy;
void *daddr;
int idx = 0;
if (srest < size || size > nbytes)
return -EINVAL;
while (size) {
copy = min3(srest, dst->length, size);
daddr = kmap_atomic(sg_page(dst));
memcpy(daddr + dst->offset + offset, saddr, copy);
kunmap_atomic(daddr);
nbytes -= copy;
size -= copy;
srest -= copy;
saddr += copy;
offset = 0;
pr_debug("%s: copy: %u, size: %u, srest: %u, nbytes: %u.\n",
__func__, copy, size, srest, nbytes);
dst++;
idx++;
}
*nbytesp = nbytes;
*srestp = srest;
return idx;
}
static inline void hifn_complete_sa(struct hifn_device *dev, int i)
{
unsigned long flags;
spin_lock_irqsave(&dev->lock, flags);
dev->sa[i] = NULL;
dev->started--;
if (dev->started < 0)
dev_info(&dev->pdev->dev, "%s: started: %d.\n", __func__,
dev->started);
spin_unlock_irqrestore(&dev->lock, flags);
BUG_ON(dev->started < 0);
}
static void hifn_process_ready(struct ablkcipher_request *req, int error)
{
struct hifn_request_context *rctx = ablkcipher_request_ctx(req);
if (rctx->walk.flags & ASYNC_FLAGS_MISALIGNED) {
unsigned int nbytes = req->nbytes;
int idx = 0, err;
struct scatterlist *dst, *t;
void *saddr;
while (nbytes) {
t = &rctx->walk.cache[idx];
dst = &req->dst[idx];
pr_debug("\n%s: sg_page(t): %p, t->length: %u, "
"sg_page(dst): %p, dst->length: %u, "
"nbytes: %u.\n",
__func__, sg_page(t), t->length,
sg_page(dst), dst->length, nbytes);
if (!t->length) {
nbytes -= min(dst->length, nbytes);
idx++;
continue;
}
saddr = kmap_atomic(sg_page(t));
err = ablkcipher_get(saddr, &t->length, t->offset,
dst, nbytes, &nbytes);
if (err < 0) {
kunmap_atomic(saddr);
break;
}
idx += err;
kunmap_atomic(saddr);
}
hifn_cipher_walk_exit(&rctx->walk);
}
req->base.complete(&req->base, error);
}
static void hifn_clear_rings(struct hifn_device *dev, int error)
{
struct hifn_dma *dma = (struct hifn_dma *)dev->desc_virt;
int i, u;
dev_dbg(&dev->pdev->dev, "ring cleanup 1: i: %d.%d.%d.%d, u: %d.%d.%d.%d, "
"k: %d.%d.%d.%d.\n",
dma->cmdi, dma->srci, dma->dsti, dma->resi,
dma->cmdu, dma->srcu, dma->dstu, dma->resu,
dma->cmdk, dma->srck, dma->dstk, dma->resk);
i = dma->resk; u = dma->resu;
while (u != 0) {
if (dma->resr[i].l & __cpu_to_le32(HIFN_D_VALID))
break;
if (dev->sa[i]) {
dev->success++;
dev->reset = 0;
hifn_process_ready(dev->sa[i], error);
hifn_complete_sa(dev, i);
}
if (++i == HIFN_D_RES_RSIZE)
i = 0;
u--;
}
dma->resk = i; dma->resu = u;
i = dma->srck; u = dma->srcu;
while (u != 0) {
if (dma->srcr[i].l & __cpu_to_le32(HIFN_D_VALID))
break;
if (++i == HIFN_D_SRC_RSIZE)
i = 0;
u--;
}
dma->srck = i; dma->srcu = u;
i = dma->cmdk; u = dma->cmdu;
while (u != 0) {
if (dma->cmdr[i].l & __cpu_to_le32(HIFN_D_VALID))
break;
if (++i == HIFN_D_CMD_RSIZE)
i = 0;
u--;
}
dma->cmdk = i; dma->cmdu = u;
i = dma->dstk; u = dma->dstu;
while (u != 0) {
if (dma->dstr[i].l & __cpu_to_le32(HIFN_D_VALID))
break;
if (++i == HIFN_D_DST_RSIZE)
i = 0;
u--;
}
dma->dstk = i; dma->dstu = u;
dev_dbg(&dev->pdev->dev, "ring cleanup 2: i: %d.%d.%d.%d, u: %d.%d.%d.%d, "
"k: %d.%d.%d.%d.\n",
dma->cmdi, dma->srci, dma->dsti, dma->resi,
dma->cmdu, dma->srcu, dma->dstu, dma->resu,
dma->cmdk, dma->srck, dma->dstk, dma->resk);
}
static void hifn_work(struct work_struct *work)
{
struct delayed_work *dw = to_delayed_work(work);
struct hifn_device *dev = container_of(dw, struct hifn_device, work);
unsigned long flags;
int reset = 0;
u32 r = 0;
spin_lock_irqsave(&dev->lock, flags);
if (dev->active == 0) {
struct hifn_dma *dma = (struct hifn_dma *)dev->desc_virt;
if (dma->cmdu == 0 && (dev->flags & HIFN_FLAG_CMD_BUSY)) {
dev->flags &= ~HIFN_FLAG_CMD_BUSY;
r |= HIFN_DMACSR_C_CTRL_DIS;
}
if (dma->srcu == 0 && (dev->flags & HIFN_FLAG_SRC_BUSY)) {
dev->flags &= ~HIFN_FLAG_SRC_BUSY;
r |= HIFN_DMACSR_S_CTRL_DIS;
}
if (dma->dstu == 0 && (dev->flags & HIFN_FLAG_DST_BUSY)) {
dev->flags &= ~HIFN_FLAG_DST_BUSY;
r |= HIFN_DMACSR_D_CTRL_DIS;
}
if (dma->resu == 0 && (dev->flags & HIFN_FLAG_RES_BUSY)) {
dev->flags &= ~HIFN_FLAG_RES_BUSY;
r |= HIFN_DMACSR_R_CTRL_DIS;
}
if (r)
hifn_write_1(dev, HIFN_1_DMA_CSR, r);
} else
dev->active--;
if ((dev->prev_success == dev->success) && dev->started)
reset = 1;
dev->prev_success = dev->success;
spin_unlock_irqrestore(&dev->lock, flags);
if (reset) {
if (++dev->reset >= 5) {
int i;
struct hifn_dma *dma = (struct hifn_dma *)dev->desc_virt;
dev_info(&dev->pdev->dev,
"r: %08x, active: %d, started: %d, "
"success: %lu: qlen: %u/%u, reset: %d.\n",
r, dev->active, dev->started,
dev->success, dev->queue.qlen, dev->queue.max_qlen,
reset);
dev_info(&dev->pdev->dev, "%s: res: ", __func__);
for (i = 0; i < HIFN_D_RES_RSIZE; ++i) {
pr_info("%x.%p ", dma->resr[i].l, dev->sa[i]);
if (dev->sa[i]) {
hifn_process_ready(dev->sa[i], -ENODEV);
hifn_complete_sa(dev, i);
}
}
pr_info("\n");
hifn_reset_dma(dev, 1);
hifn_stop_device(dev);
hifn_start_device(dev);
dev->reset = 0;
}
tasklet_schedule(&dev->tasklet);
}
schedule_delayed_work(&dev->work, HZ);
}
static irqreturn_t hifn_interrupt(int irq, void *data)
{
struct hifn_device *dev = (struct hifn_device *)data;
struct hifn_dma *dma = (struct hifn_dma *)dev->desc_virt;
u32 dmacsr, restart;
dmacsr = hifn_read_1(dev, HIFN_1_DMA_CSR);
dev_dbg(&dev->pdev->dev, "1 dmacsr: %08x, dmareg: %08x, res: %08x [%d], "
"i: %d.%d.%d.%d, u: %d.%d.%d.%d.\n",
dmacsr, dev->dmareg, dmacsr & dev->dmareg, dma->cmdi,
dma->cmdi, dma->srci, dma->dsti, dma->resi,
dma->cmdu, dma->srcu, dma->dstu, dma->resu);
if ((dmacsr & dev->dmareg) == 0)
return IRQ_NONE;
hifn_write_1(dev, HIFN_1_DMA_CSR, dmacsr & dev->dmareg);
if (dmacsr & HIFN_DMACSR_ENGINE)
hifn_write_0(dev, HIFN_0_PUISR, hifn_read_0(dev, HIFN_0_PUISR));
if (dmacsr & HIFN_DMACSR_PUBDONE)
hifn_write_1(dev, HIFN_1_PUB_STATUS,
hifn_read_1(dev, HIFN_1_PUB_STATUS) | HIFN_PUBSTS_DONE);
restart = dmacsr & (HIFN_DMACSR_R_OVER | HIFN_DMACSR_D_OVER);
if (restart) {
u32 puisr = hifn_read_0(dev, HIFN_0_PUISR);
dev_warn(&dev->pdev->dev, "overflow: r: %d, d: %d, puisr: %08x, d: %u.\n",
!!(dmacsr & HIFN_DMACSR_R_OVER),
!!(dmacsr & HIFN_DMACSR_D_OVER),
puisr, !!(puisr & HIFN_PUISR_DSTOVER));
if (!!(puisr & HIFN_PUISR_DSTOVER))
hifn_write_0(dev, HIFN_0_PUISR, HIFN_PUISR_DSTOVER);
hifn_write_1(dev, HIFN_1_DMA_CSR, dmacsr & (HIFN_DMACSR_R_OVER |
HIFN_DMACSR_D_OVER));
}
restart = dmacsr & (HIFN_DMACSR_C_ABORT | HIFN_DMACSR_S_ABORT |
HIFN_DMACSR_D_ABORT | HIFN_DMACSR_R_ABORT);
if (restart) {
dev_warn(&dev->pdev->dev, "abort: c: %d, s: %d, d: %d, r: %d.\n",
!!(dmacsr & HIFN_DMACSR_C_ABORT),
!!(dmacsr & HIFN_DMACSR_S_ABORT),
!!(dmacsr & HIFN_DMACSR_D_ABORT),
!!(dmacsr & HIFN_DMACSR_R_ABORT));
hifn_reset_dma(dev, 1);
hifn_init_dma(dev);
hifn_init_registers(dev);
}
if ((dmacsr & HIFN_DMACSR_C_WAIT) && (dma->cmdu == 0)) {
dev_dbg(&dev->pdev->dev, "wait on command.\n");
dev->dmareg &= ~(HIFN_DMAIER_C_WAIT);
hifn_write_1(dev, HIFN_1_DMA_IER, dev->dmareg);
}
tasklet_schedule(&dev->tasklet);
return IRQ_HANDLED;
}
static void hifn_flush(struct hifn_device *dev)
{
unsigned long flags;
struct crypto_async_request *async_req;
struct ablkcipher_request *req;
struct hifn_dma *dma = (struct hifn_dma *)dev->desc_virt;
int i;
for (i = 0; i < HIFN_D_RES_RSIZE; ++i) {
struct hifn_desc *d = &dma->resr[i];
if (dev->sa[i]) {
hifn_process_ready(dev->sa[i],
(d->l & __cpu_to_le32(HIFN_D_VALID)) ? -ENODEV : 0);
hifn_complete_sa(dev, i);
}
}
spin_lock_irqsave(&dev->lock, flags);
while ((async_req = crypto_dequeue_request(&dev->queue))) {
req = ablkcipher_request_cast(async_req);
spin_unlock_irqrestore(&dev->lock, flags);
hifn_process_ready(req, -ENODEV);
spin_lock_irqsave(&dev->lock, flags);
}
spin_unlock_irqrestore(&dev->lock, flags);
}
static int hifn_setkey(struct crypto_ablkcipher *cipher, const u8 *key,
unsigned int len)
{
struct crypto_tfm *tfm = crypto_ablkcipher_tfm(cipher);
struct hifn_context *ctx = crypto_tfm_ctx(tfm);
struct hifn_device *dev = ctx->dev;
if (len > HIFN_MAX_CRYPT_KEY_LENGTH) {
crypto_ablkcipher_set_flags(cipher, CRYPTO_TFM_RES_BAD_KEY_LEN);
return -1;
}
if (len == HIFN_DES_KEY_LENGTH) {
u32 tmp[DES_EXPKEY_WORDS];
int ret = des_ekey(tmp, key);
if (unlikely(ret == 0) && (tfm->crt_flags & CRYPTO_TFM_REQ_WEAK_KEY)) {
tfm->crt_flags |= CRYPTO_TFM_RES_WEAK_KEY;
return -EINVAL;
}
}
dev->flags &= ~HIFN_FLAG_OLD_KEY;
memcpy(ctx->key, key, len);
ctx->keysize = len;
return 0;
}
static int hifn_handle_req(struct ablkcipher_request *req)
{
struct hifn_context *ctx = crypto_tfm_ctx(req->base.tfm);
struct hifn_device *dev = ctx->dev;
int err = -EAGAIN;
if (dev->started + DIV_ROUND_UP(req->nbytes, PAGE_SIZE) <= HIFN_QUEUE_LENGTH)
err = hifn_setup_session(req);
if (err == -EAGAIN) {
unsigned long flags;
spin_lock_irqsave(&dev->lock, flags);
err = ablkcipher_enqueue_request(&dev->queue, req);
spin_unlock_irqrestore(&dev->lock, flags);
}
return err;
}
static int hifn_setup_crypto_req(struct ablkcipher_request *req, u8 op,
u8 type, u8 mode)
{
struct hifn_context *ctx = crypto_tfm_ctx(req->base.tfm);
struct hifn_request_context *rctx = ablkcipher_request_ctx(req);
unsigned ivsize;
ivsize = crypto_ablkcipher_ivsize(crypto_ablkcipher_reqtfm(req));
if (req->info && mode != ACRYPTO_MODE_ECB) {
if (type == ACRYPTO_TYPE_AES_128)
ivsize = HIFN_AES_IV_LENGTH;
else if (type == ACRYPTO_TYPE_DES)
ivsize = HIFN_DES_KEY_LENGTH;
else if (type == ACRYPTO_TYPE_3DES)
ivsize = HIFN_3DES_KEY_LENGTH;
}
if (ctx->keysize != 16 && type == ACRYPTO_TYPE_AES_128) {
if (ctx->keysize == 24)
type = ACRYPTO_TYPE_AES_192;
else if (ctx->keysize == 32)
type = ACRYPTO_TYPE_AES_256;
}
rctx->op = op;
rctx->mode = mode;
rctx->type = type;
rctx->iv = req->info;
rctx->ivsize = ivsize;
return hifn_handle_req(req);
}
static int hifn_process_queue(struct hifn_device *dev)
{
struct crypto_async_request *async_req, *backlog;
struct ablkcipher_request *req;
unsigned long flags;
int err = 0;
while (dev->started < HIFN_QUEUE_LENGTH) {
spin_lock_irqsave(&dev->lock, flags);
backlog = crypto_get_backlog(&dev->queue);
async_req = crypto_dequeue_request(&dev->queue);
spin_unlock_irqrestore(&dev->lock, flags);
if (!async_req)
break;
if (backlog)
backlog->complete(backlog, -EINPROGRESS);
req = ablkcipher_request_cast(async_req);
err = hifn_handle_req(req);
if (err)
break;
}
return err;
}
static int hifn_setup_crypto(struct ablkcipher_request *req, u8 op,
u8 type, u8 mode)
{
int err;
struct hifn_context *ctx = crypto_tfm_ctx(req->base.tfm);
struct hifn_device *dev = ctx->dev;
err = hifn_setup_crypto_req(req, op, type, mode);
if (err)
return err;
if (dev->started < HIFN_QUEUE_LENGTH && dev->queue.qlen)
hifn_process_queue(dev);
return -EINPROGRESS;
}
static inline int hifn_encrypt_aes_ecb(struct ablkcipher_request *req)
{
return hifn_setup_crypto(req, ACRYPTO_OP_ENCRYPT,
ACRYPTO_TYPE_AES_128, ACRYPTO_MODE_ECB);
}
static inline int hifn_encrypt_aes_cbc(struct ablkcipher_request *req)
{
return hifn_setup_crypto(req, ACRYPTO_OP_ENCRYPT,
ACRYPTO_TYPE_AES_128, ACRYPTO_MODE_CBC);
}
static inline int hifn_encrypt_aes_cfb(struct ablkcipher_request *req)
{
return hifn_setup_crypto(req, ACRYPTO_OP_ENCRYPT,
ACRYPTO_TYPE_AES_128, ACRYPTO_MODE_CFB);
}
static inline int hifn_encrypt_aes_ofb(struct ablkcipher_request *req)
{
return hifn_setup_crypto(req, ACRYPTO_OP_ENCRYPT,
ACRYPTO_TYPE_AES_128, ACRYPTO_MODE_OFB);
}
static inline int hifn_decrypt_aes_ecb(struct ablkcipher_request *req)
{
return hifn_setup_crypto(req, ACRYPTO_OP_DECRYPT,
ACRYPTO_TYPE_AES_128, ACRYPTO_MODE_ECB);
}
static inline int hifn_decrypt_aes_cbc(struct ablkcipher_request *req)
{
return hifn_setup_crypto(req, ACRYPTO_OP_DECRYPT,
ACRYPTO_TYPE_AES_128, ACRYPTO_MODE_CBC);
}
static inline int hifn_decrypt_aes_cfb(struct ablkcipher_request *req)
{
return hifn_setup_crypto(req, ACRYPTO_OP_DECRYPT,
ACRYPTO_TYPE_AES_128, ACRYPTO_MODE_CFB);
}
static inline int hifn_decrypt_aes_ofb(struct ablkcipher_request *req)
{
return hifn_setup_crypto(req, ACRYPTO_OP_DECRYPT,
ACRYPTO_TYPE_AES_128, ACRYPTO_MODE_OFB);
}
static inline int hifn_encrypt_des_ecb(struct ablkcipher_request *req)
{
return hifn_setup_crypto(req, ACRYPTO_OP_ENCRYPT,
ACRYPTO_TYPE_DES, ACRYPTO_MODE_ECB);
}
static inline int hifn_encrypt_des_cbc(struct ablkcipher_request *req)
{
return hifn_setup_crypto(req, ACRYPTO_OP_ENCRYPT,
ACRYPTO_TYPE_DES, ACRYPTO_MODE_CBC);
}
static inline int hifn_encrypt_des_cfb(struct ablkcipher_request *req)
{
return hifn_setup_crypto(req, ACRYPTO_OP_ENCRYPT,
ACRYPTO_TYPE_DES, ACRYPTO_MODE_CFB);
}
static inline int hifn_encrypt_des_ofb(struct ablkcipher_request *req)
{
return hifn_setup_crypto(req, ACRYPTO_OP_ENCRYPT,
ACRYPTO_TYPE_DES, ACRYPTO_MODE_OFB);
}
static inline int hifn_decrypt_des_ecb(struct ablkcipher_request *req)
{
return hifn_setup_crypto(req, ACRYPTO_OP_DECRYPT,
ACRYPTO_TYPE_DES, ACRYPTO_MODE_ECB);
}
static inline int hifn_decrypt_des_cbc(struct ablkcipher_request *req)
{
return hifn_setup_crypto(req, ACRYPTO_OP_DECRYPT,
ACRYPTO_TYPE_DES, ACRYPTO_MODE_CBC);
}
static inline int hifn_decrypt_des_cfb(struct ablkcipher_request *req)
{
return hifn_setup_crypto(req, ACRYPTO_OP_DECRYPT,
ACRYPTO_TYPE_DES, ACRYPTO_MODE_CFB);
}
static inline int hifn_decrypt_des_ofb(struct ablkcipher_request *req)
{
return hifn_setup_crypto(req, ACRYPTO_OP_DECRYPT,
ACRYPTO_TYPE_DES, ACRYPTO_MODE_OFB);
}
static inline int hifn_encrypt_3des_ecb(struct ablkcipher_request *req)
{
return hifn_setup_crypto(req, ACRYPTO_OP_ENCRYPT,
ACRYPTO_TYPE_3DES, ACRYPTO_MODE_ECB);
}
static inline int hifn_encrypt_3des_cbc(struct ablkcipher_request *req)
{
return hifn_setup_crypto(req, ACRYPTO_OP_ENCRYPT,
ACRYPTO_TYPE_3DES, ACRYPTO_MODE_CBC);
}
static inline int hifn_encrypt_3des_cfb(struct ablkcipher_request *req)
{
return hifn_setup_crypto(req, ACRYPTO_OP_ENCRYPT,
ACRYPTO_TYPE_3DES, ACRYPTO_MODE_CFB);
}
static inline int hifn_encrypt_3des_ofb(struct ablkcipher_request *req)
{
return hifn_setup_crypto(req, ACRYPTO_OP_ENCRYPT,
ACRYPTO_TYPE_3DES, ACRYPTO_MODE_OFB);
}
static inline int hifn_decrypt_3des_ecb(struct ablkcipher_request *req)
{
return hifn_setup_crypto(req, ACRYPTO_OP_DECRYPT,
ACRYPTO_TYPE_3DES, ACRYPTO_MODE_ECB);
}
static inline int hifn_decrypt_3des_cbc(struct ablkcipher_request *req)
{
return hifn_setup_crypto(req, ACRYPTO_OP_DECRYPT,
ACRYPTO_TYPE_3DES, ACRYPTO_MODE_CBC);
}
static inline int hifn_decrypt_3des_cfb(struct ablkcipher_request *req)
{
return hifn_setup_crypto(req, ACRYPTO_OP_DECRYPT,
ACRYPTO_TYPE_3DES, ACRYPTO_MODE_CFB);
}
static inline int hifn_decrypt_3des_ofb(struct ablkcipher_request *req)
{
return hifn_setup_crypto(req, ACRYPTO_OP_DECRYPT,
ACRYPTO_TYPE_3DES, ACRYPTO_MODE_OFB);
}
static int hifn_cra_init(struct crypto_tfm *tfm)
{
struct crypto_alg *alg = tfm->__crt_alg;
struct hifn_crypto_alg *ha = crypto_alg_to_hifn(alg);
struct hifn_context *ctx = crypto_tfm_ctx(tfm);
ctx->dev = ha->dev;
tfm->crt_ablkcipher.reqsize = sizeof(struct hifn_request_context);
return 0;
}
static int hifn_alg_alloc(struct hifn_device *dev, struct hifn_alg_template *t)
{
struct hifn_crypto_alg *alg;
int err;
alg = kzalloc(sizeof(*alg), GFP_KERNEL);
if (!alg)
return -ENOMEM;
snprintf(alg->alg.cra_name, CRYPTO_MAX_ALG_NAME, "%s", t->name);
snprintf(alg->alg.cra_driver_name, CRYPTO_MAX_ALG_NAME, "%s-%s",
t->drv_name, dev->name);
alg->alg.cra_priority = 300;
alg->alg.cra_flags = CRYPTO_ALG_TYPE_ABLKCIPHER |
CRYPTO_ALG_KERN_DRIVER_ONLY | CRYPTO_ALG_ASYNC;
alg->alg.cra_blocksize = t->bsize;
alg->alg.cra_ctxsize = sizeof(struct hifn_context);
alg->alg.cra_alignmask = 0;
alg->alg.cra_type = &crypto_ablkcipher_type;
alg->alg.cra_module = THIS_MODULE;
alg->alg.cra_u.ablkcipher = t->ablkcipher;
alg->alg.cra_init = hifn_cra_init;
alg->dev = dev;
list_add_tail(&alg->entry, &dev->alg_list);
err = crypto_register_alg(&alg->alg);
if (err) {
list_del(&alg->entry);
kfree(alg);
}
return err;
}
static void hifn_unregister_alg(struct hifn_device *dev)
{
struct hifn_crypto_alg *a, *n;
list_for_each_entry_safe(a, n, &dev->alg_list, entry) {
list_del(&a->entry);
crypto_unregister_alg(&a->alg);
kfree(a);
}
}
static int hifn_register_alg(struct hifn_device *dev)
{
int i, err;
for (i = 0; i < ARRAY_SIZE(hifn_alg_templates); ++i) {
err = hifn_alg_alloc(dev, &hifn_alg_templates[i]);
if (err)
goto err_out_exit;
}
return 0;
err_out_exit:
hifn_unregister_alg(dev);
return err;
}
static void hifn_tasklet_callback(unsigned long data)
{
struct hifn_device *dev = (struct hifn_device *)data;
hifn_clear_rings(dev, 0);
if (dev->started < HIFN_QUEUE_LENGTH && dev->queue.qlen)
hifn_process_queue(dev);
}
static int hifn_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
int err, i;
struct hifn_device *dev;
char name[8];
err = pci_enable_device(pdev);
if (err)
return err;
pci_set_master(pdev);
err = pci_set_dma_mask(pdev, DMA_BIT_MASK(32));
if (err)
goto err_out_disable_pci_device;
snprintf(name, sizeof(name), "hifn%d",
atomic_inc_return(&hifn_dev_number) - 1);
err = pci_request_regions(pdev, name);
if (err)
goto err_out_disable_pci_device;
if (pci_resource_len(pdev, 0) < HIFN_BAR0_SIZE ||
pci_resource_len(pdev, 1) < HIFN_BAR1_SIZE ||
pci_resource_len(pdev, 2) < HIFN_BAR2_SIZE) {
dev_err(&pdev->dev, "Broken hardware - I/O regions are too small.\n");
err = -ENODEV;
goto err_out_free_regions;
}
dev = kzalloc(sizeof(struct hifn_device) + sizeof(struct crypto_alg),
GFP_KERNEL);
if (!dev) {
err = -ENOMEM;
goto err_out_free_regions;
}
INIT_LIST_HEAD(&dev->alg_list);
snprintf(dev->name, sizeof(dev->name), "%s", name);
spin_lock_init(&dev->lock);
for (i = 0; i < 3; ++i) {
unsigned long addr, size;
addr = pci_resource_start(pdev, i);
size = pci_resource_len(pdev, i);
dev->bar[i] = ioremap_nocache(addr, size);
if (!dev->bar[i]) {
err = -ENOMEM;
goto err_out_unmap_bars;
}
}
dev->desc_virt = pci_zalloc_consistent(pdev, sizeof(struct hifn_dma),
&dev->desc_dma);
if (!dev->desc_virt) {
dev_err(&pdev->dev, "Failed to allocate descriptor rings.\n");
err = -ENOMEM;
goto err_out_unmap_bars;
}
dev->pdev = pdev;
dev->irq = pdev->irq;
for (i = 0; i < HIFN_D_RES_RSIZE; ++i)
dev->sa[i] = NULL;
pci_set_drvdata(pdev, dev);
tasklet_init(&dev->tasklet, hifn_tasklet_callback, (unsigned long)dev);
crypto_init_queue(&dev->queue, 1);
err = request_irq(dev->irq, hifn_interrupt, IRQF_SHARED, dev->name, dev);
if (err) {
dev_err(&pdev->dev, "Failed to request IRQ%d: err: %d.\n",
dev->irq, err);
dev->irq = 0;
goto err_out_free_desc;
}
err = hifn_start_device(dev);
if (err)
goto err_out_free_irq;
err = hifn_register_rng(dev);
if (err)
goto err_out_stop_device;
err = hifn_register_alg(dev);
if (err)
goto err_out_unregister_rng;
INIT_DELAYED_WORK(&dev->work, hifn_work);
schedule_delayed_work(&dev->work, HZ);
dev_dbg(&pdev->dev, "HIFN crypto accelerator card at %s has been "
"successfully registered as %s.\n",
pci_name(pdev), dev->name);
return 0;
err_out_unregister_rng:
hifn_unregister_rng(dev);
err_out_stop_device:
hifn_reset_dma(dev, 1);
hifn_stop_device(dev);
err_out_free_irq:
free_irq(dev->irq, dev);
tasklet_kill(&dev->tasklet);
err_out_free_desc:
pci_free_consistent(pdev, sizeof(struct hifn_dma),
dev->desc_virt, dev->desc_dma);
err_out_unmap_bars:
for (i = 0; i < 3; ++i)
if (dev->bar[i])
iounmap(dev->bar[i]);
err_out_free_regions:
pci_release_regions(pdev);
err_out_disable_pci_device:
pci_disable_device(pdev);
return err;
}
static void hifn_remove(struct pci_dev *pdev)
{
int i;
struct hifn_device *dev;
dev = pci_get_drvdata(pdev);
if (dev) {
cancel_delayed_work_sync(&dev->work);
hifn_unregister_rng(dev);
hifn_unregister_alg(dev);
hifn_reset_dma(dev, 1);
hifn_stop_device(dev);
free_irq(dev->irq, dev);
tasklet_kill(&dev->tasklet);
hifn_flush(dev);
pci_free_consistent(pdev, sizeof(struct hifn_dma),
dev->desc_virt, dev->desc_dma);
for (i = 0; i < 3; ++i)
if (dev->bar[i])
iounmap(dev->bar[i]);
kfree(dev);
}
pci_release_regions(pdev);
pci_disable_device(pdev);
}
static int __init hifn_init(void)
{
unsigned int freq;
int err;
BUILD_BUG_ON(sizeof(dma_addr_t) != 4);
if (strncmp(hifn_pll_ref, "ext", 3) &&
strncmp(hifn_pll_ref, "pci", 3)) {
pr_err("hifn795x: invalid hifn_pll_ref clock, must be pci or ext");
return -EINVAL;
}
if (hifn_pll_ref[3] != '\0') {
freq = simple_strtoul(hifn_pll_ref + 3, NULL, 10);
if (freq < 20 || freq > 100) {
pr_err("hifn795x: invalid hifn_pll_ref frequency, must"
"be in the range of 20-100");
return -EINVAL;
}
}
err = pci_register_driver(&hifn_pci_driver);
if (err < 0) {
pr_err("Failed to register PCI driver for %s device.\n",
hifn_pci_driver.name);
return -ENODEV;
}
pr_info("Driver for HIFN 795x crypto accelerator chip "
"has been successfully registered.\n");
return 0;
}
static void __exit hifn_fini(void)
{
pci_unregister_driver(&hifn_pci_driver);
pr_info("Driver for HIFN 795x crypto accelerator chip "
"has been successfully unregistered.\n");
}
