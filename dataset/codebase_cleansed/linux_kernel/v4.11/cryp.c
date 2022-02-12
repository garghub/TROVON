void cryp_wait_until_done(struct cryp_device_data *device_data)
{
while (cryp_is_logic_busy(device_data))
cpu_relax();
}
int cryp_check(struct cryp_device_data *device_data)
{
int peripheralid2 = 0;
if (NULL == device_data)
return -EINVAL;
peripheralid2 = readl_relaxed(&device_data->base->periphId2);
if (peripheralid2 != CRYP_PERIPHERAL_ID2_DB8500)
return -EPERM;
if ((CRYP_PERIPHERAL_ID0 ==
readl_relaxed(&device_data->base->periphId0))
&& (CRYP_PERIPHERAL_ID1 ==
readl_relaxed(&device_data->base->periphId1))
&& (CRYP_PERIPHERAL_ID3 ==
readl_relaxed(&device_data->base->periphId3))
&& (CRYP_PCELL_ID0 ==
readl_relaxed(&device_data->base->pcellId0))
&& (CRYP_PCELL_ID1 ==
readl_relaxed(&device_data->base->pcellId1))
&& (CRYP_PCELL_ID2 ==
readl_relaxed(&device_data->base->pcellId2))
&& (CRYP_PCELL_ID3 ==
readl_relaxed(&device_data->base->pcellId3))) {
return 0;
}
return -EPERM;
}
void cryp_activity(struct cryp_device_data *device_data,
enum cryp_crypen cryp_crypen)
{
CRYP_PUT_BITS(&device_data->base->cr,
cryp_crypen,
CRYP_CR_CRYPEN_POS,
CRYP_CR_CRYPEN_MASK);
}
void cryp_flush_inoutfifo(struct cryp_device_data *device_data)
{
cryp_activity(device_data, CRYP_CRYPEN_DISABLE);
cryp_wait_until_done(device_data);
CRYP_SET_BITS(&device_data->base->cr, CRYP_CR_FFLUSH_MASK);
while (readl_relaxed(&device_data->base->sr) !=
CRYP_SR_INFIFO_READY_MASK)
cpu_relax();
}
int cryp_set_configuration(struct cryp_device_data *device_data,
struct cryp_config *cryp_config,
u32 *control_register)
{
u32 cr_for_kse;
if (NULL == device_data || NULL == cryp_config)
return -EINVAL;
*control_register |= (cryp_config->keysize << CRYP_CR_KEYSIZE_POS);
if ((CRYP_ALGORITHM_DECRYPT == cryp_config->algodir) &&
((CRYP_ALGO_AES_ECB == cryp_config->algomode) ||
(CRYP_ALGO_AES_CBC == cryp_config->algomode))) {
cr_for_kse = *control_register;
cr_for_kse |= ((CRYP_ALGORITHM_ENCRYPT << CRYP_CR_ALGODIR_POS) |
(CRYP_ALGO_AES_ECB << CRYP_CR_ALGOMODE_POS) |
(CRYP_CRYPEN_ENABLE << CRYP_CR_CRYPEN_POS) |
(KSE_ENABLED << CRYP_CR_KSE_POS));
writel_relaxed(cr_for_kse, &device_data->base->cr);
cryp_wait_until_done(device_data);
}
*control_register |=
((cryp_config->algomode << CRYP_CR_ALGOMODE_POS) |
(cryp_config->algodir << CRYP_CR_ALGODIR_POS));
return 0;
}
int cryp_configure_protection(struct cryp_device_data *device_data,
struct cryp_protection_config *p_protect_config)
{
if (NULL == p_protect_config)
return -EINVAL;
CRYP_WRITE_BIT(&device_data->base->cr,
(u32) p_protect_config->secure_access,
CRYP_CR_SECURE_MASK);
CRYP_PUT_BITS(&device_data->base->cr,
p_protect_config->privilege_access,
CRYP_CR_PRLG_POS,
CRYP_CR_PRLG_MASK);
return 0;
}
int cryp_is_logic_busy(struct cryp_device_data *device_data)
{
return CRYP_TEST_BITS(&device_data->base->sr,
CRYP_SR_BUSY_MASK);
}
void cryp_configure_for_dma(struct cryp_device_data *device_data,
enum cryp_dma_req_type dma_req)
{
CRYP_SET_BITS(&device_data->base->dmacr,
(u32) dma_req);
}
int cryp_configure_key_values(struct cryp_device_data *device_data,
enum cryp_key_reg_index key_reg_index,
struct cryp_key_value key_value)
{
while (cryp_is_logic_busy(device_data))
cpu_relax();
switch (key_reg_index) {
case CRYP_KEY_REG_1:
writel_relaxed(key_value.key_value_left,
&device_data->base->key_1_l);
writel_relaxed(key_value.key_value_right,
&device_data->base->key_1_r);
break;
case CRYP_KEY_REG_2:
writel_relaxed(key_value.key_value_left,
&device_data->base->key_2_l);
writel_relaxed(key_value.key_value_right,
&device_data->base->key_2_r);
break;
case CRYP_KEY_REG_3:
writel_relaxed(key_value.key_value_left,
&device_data->base->key_3_l);
writel_relaxed(key_value.key_value_right,
&device_data->base->key_3_r);
break;
case CRYP_KEY_REG_4:
writel_relaxed(key_value.key_value_left,
&device_data->base->key_4_l);
writel_relaxed(key_value.key_value_right,
&device_data->base->key_4_r);
break;
default:
return -EINVAL;
}
return 0;
}
int cryp_configure_init_vector(struct cryp_device_data *device_data,
enum cryp_init_vector_index
init_vector_index,
struct cryp_init_vector_value
init_vector_value)
{
while (cryp_is_logic_busy(device_data))
cpu_relax();
switch (init_vector_index) {
case CRYP_INIT_VECTOR_INDEX_0:
writel_relaxed(init_vector_value.init_value_left,
&device_data->base->init_vect_0_l);
writel_relaxed(init_vector_value.init_value_right,
&device_data->base->init_vect_0_r);
break;
case CRYP_INIT_VECTOR_INDEX_1:
writel_relaxed(init_vector_value.init_value_left,
&device_data->base->init_vect_1_l);
writel_relaxed(init_vector_value.init_value_right,
&device_data->base->init_vect_1_r);
break;
default:
return -EINVAL;
}
return 0;
}
void cryp_save_device_context(struct cryp_device_data *device_data,
struct cryp_device_context *ctx,
int cryp_mode)
{
enum cryp_algo_mode algomode;
struct cryp_register __iomem *src_reg = device_data->base;
struct cryp_config *config =
(struct cryp_config *)device_data->current_ctx;
cryp_activity(device_data, CRYP_CRYPEN_DISABLE);
cryp_wait_until_done(device_data);
if (cryp_mode == CRYP_MODE_DMA)
cryp_configure_for_dma(device_data, CRYP_DMA_DISABLE_BOTH);
if (CRYP_TEST_BITS(&src_reg->sr, CRYP_SR_IFEM_MASK) == 0)
ctx->din = readl_relaxed(&src_reg->din);
ctx->cr = readl_relaxed(&src_reg->cr) & CRYP_CR_CONTEXT_SAVE_MASK;
switch (config->keysize) {
case CRYP_KEY_SIZE_256:
ctx->key_4_l = readl_relaxed(&src_reg->key_4_l);
ctx->key_4_r = readl_relaxed(&src_reg->key_4_r);
case CRYP_KEY_SIZE_192:
ctx->key_3_l = readl_relaxed(&src_reg->key_3_l);
ctx->key_3_r = readl_relaxed(&src_reg->key_3_r);
case CRYP_KEY_SIZE_128:
ctx->key_2_l = readl_relaxed(&src_reg->key_2_l);
ctx->key_2_r = readl_relaxed(&src_reg->key_2_r);
default:
ctx->key_1_l = readl_relaxed(&src_reg->key_1_l);
ctx->key_1_r = readl_relaxed(&src_reg->key_1_r);
}
algomode = ((ctx->cr & CRYP_CR_ALGOMODE_MASK) >> CRYP_CR_ALGOMODE_POS);
if (algomode == CRYP_ALGO_TDES_CBC ||
algomode == CRYP_ALGO_DES_CBC ||
algomode == CRYP_ALGO_AES_CBC) {
ctx->init_vect_0_l = readl_relaxed(&src_reg->init_vect_0_l);
ctx->init_vect_0_r = readl_relaxed(&src_reg->init_vect_0_r);
ctx->init_vect_1_l = readl_relaxed(&src_reg->init_vect_1_l);
ctx->init_vect_1_r = readl_relaxed(&src_reg->init_vect_1_r);
}
}
void cryp_restore_device_context(struct cryp_device_data *device_data,
struct cryp_device_context *ctx)
{
struct cryp_register __iomem *reg = device_data->base;
struct cryp_config *config =
(struct cryp_config *)device_data->current_ctx;
switch (config->keysize) {
case CRYP_KEY_SIZE_256:
writel_relaxed(ctx->key_4_l, &reg->key_4_l);
writel_relaxed(ctx->key_4_r, &reg->key_4_r);
case CRYP_KEY_SIZE_192:
writel_relaxed(ctx->key_3_l, &reg->key_3_l);
writel_relaxed(ctx->key_3_r, &reg->key_3_r);
case CRYP_KEY_SIZE_128:
writel_relaxed(ctx->key_2_l, &reg->key_2_l);
writel_relaxed(ctx->key_2_r, &reg->key_2_r);
default:
writel_relaxed(ctx->key_1_l, &reg->key_1_l);
writel_relaxed(ctx->key_1_r, &reg->key_1_r);
}
if (config->algomode == CRYP_ALGO_TDES_CBC ||
config->algomode == CRYP_ALGO_DES_CBC ||
config->algomode == CRYP_ALGO_AES_CBC) {
writel_relaxed(ctx->init_vect_0_l, &reg->init_vect_0_l);
writel_relaxed(ctx->init_vect_0_r, &reg->init_vect_0_r);
writel_relaxed(ctx->init_vect_1_l, &reg->init_vect_1_l);
writel_relaxed(ctx->init_vect_1_r, &reg->init_vect_1_r);
}
}
