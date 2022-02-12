void sdioh_sdio_set_host_pm_flags(int flag)
{
if (sdio_set_host_pm_flags(gInstance->func[1], flag))
printk(KERN_ERR "%s: Failed to set pm_flags 0x%08x\n",\
__func__, (unsigned int)flag);
}
static int sdioh_sdmmc_card_enablefuncs(sdioh_info_t *sd)
{
int err_ret;
u32 fbraddr;
u8 func;
sd_trace(("%s\n", __func__));
sd->com_cis_ptr = sdioh_sdmmc_get_cisaddr(sd, SDIOD_CCCR_CISPTR_0);
sd->func_cis_ptr[0] = sd->com_cis_ptr;
sd_info(("%s: Card's Common CIS Ptr = 0x%x\n", __func__,
sd->com_cis_ptr));
for (fbraddr = SDIOD_FBR_STARTADDR, func = 1;
func <= sd->num_funcs; func++, fbraddr += SDIOD_FBR_SIZE) {
sd->func_cis_ptr[func] =
sdioh_sdmmc_get_cisaddr(sd, SDIOD_FBR_CISPTR_0 + fbraddr);
sd_info(("%s: Function %d CIS Ptr = 0x%x\n", __func__, func,
sd->func_cis_ptr[func]));
}
sd->func_cis_ptr[0] = sd->com_cis_ptr;
sd_info(("%s: Card's Common CIS Ptr = 0x%x\n", __func__,
sd->com_cis_ptr));
sdio_claim_host(gInstance->func[1]);
err_ret = sdio_enable_func(gInstance->func[1]);
sdio_release_host(gInstance->func[1]);
if (err_ret) {
sd_err(("bcmsdh_sdmmc: Failed to enable F1 Err: 0x%08x",
err_ret));
}
return false;
}
sdioh_info_t *sdioh_attach(void *bar0, uint irq)
{
sdioh_info_t *sd;
int err_ret;
sd_trace(("%s\n", __func__));
if (gInstance == NULL) {
sd_err(("%s: SDIO Device not present\n", __func__));
return NULL;
}
sd = kzalloc(sizeof(sdioh_info_t), GFP_ATOMIC);
if (sd == NULL) {
sd_err(("sdioh_attach: out of memory\n"));
return NULL;
}
if (sdioh_sdmmc_osinit(sd) != 0) {
sd_err(("%s:sdioh_sdmmc_osinit() failed\n", __func__));
kfree(sd);
return NULL;
}
sd->num_funcs = 2;
sd->sd_blockmode = true;
sd->use_client_ints = true;
sd->client_block_size[0] = 64;
gInstance->sd = sd;
sdio_claim_host(gInstance->func[1]);
sd->client_block_size[1] = 64;
err_ret = sdio_set_block_size(gInstance->func[1], 64);
if (err_ret)
sd_err(("bcmsdh_sdmmc: Failed to set F1 blocksize\n"));
sdio_release_host(gInstance->func[1]);
if (gInstance->func[2]) {
sdio_claim_host(gInstance->func[2]);
sd->client_block_size[2] = sd_f2_blocksize;
err_ret =
sdio_set_block_size(gInstance->func[2], sd_f2_blocksize);
if (err_ret)
sd_err(("bcmsdh_sdmmc: Failed to set F2 blocksize "
"to %d\n", sd_f2_blocksize));
sdio_release_host(gInstance->func[2]);
}
sdioh_sdmmc_card_enablefuncs(sd);
sd_trace(("%s: Done\n", __func__));
return sd;
}
extern SDIOH_API_RC sdioh_detach(sdioh_info_t *sd)
{
sd_trace(("%s\n", __func__));
if (sd) {
sdio_claim_host(gInstance->func[2]);
sdio_disable_func(gInstance->func[2]);
sdio_release_host(gInstance->func[2]);
sdio_claim_host(gInstance->func[1]);
sdio_disable_func(gInstance->func[1]);
sdio_release_host(gInstance->func[1]);
sdioh_sdmmc_osfree(sd);
kfree(sd);
}
return SDIOH_API_RC_SUCCESS;
}
extern SDIOH_API_RC sdioh_enable_func_intr(void)
{
u8 reg;
int err;
if (gInstance->func[0]) {
sdio_claim_host(gInstance->func[0]);
reg = sdio_readb(gInstance->func[0], SDIOD_CCCR_INTEN, &err);
if (err) {
sd_err(("%s: error for read SDIO_CCCR_IENx : 0x%x\n",
__func__, err));
sdio_release_host(gInstance->func[0]);
return SDIOH_API_RC_FAIL;
}
reg |=
(INTR_CTL_FUNC1_EN | INTR_CTL_FUNC2_EN |
INTR_CTL_MASTER_EN);
sdio_writeb(gInstance->func[0], reg, SDIOD_CCCR_INTEN, &err);
sdio_release_host(gInstance->func[0]);
if (err) {
sd_err(("%s: error for write SDIO_CCCR_IENx : 0x%x\n",
__func__, err));
return SDIOH_API_RC_FAIL;
}
}
return SDIOH_API_RC_SUCCESS;
}
extern SDIOH_API_RC sdioh_disable_func_intr(void)
{
u8 reg;
int err;
if (gInstance->func[0]) {
sdio_claim_host(gInstance->func[0]);
reg = sdio_readb(gInstance->func[0], SDIOD_CCCR_INTEN, &err);
if (err) {
sd_err(("%s: error for read SDIO_CCCR_IENx : 0x%x\n",
__func__, err));
sdio_release_host(gInstance->func[0]);
return SDIOH_API_RC_FAIL;
}
reg &= ~(INTR_CTL_FUNC1_EN | INTR_CTL_FUNC2_EN);
if (!(reg & 0xFE))
reg = 0;
sdio_writeb(gInstance->func[0], reg, SDIOD_CCCR_INTEN, &err);
sdio_release_host(gInstance->func[0]);
if (err) {
sd_err(("%s: error for write SDIO_CCCR_IENx : 0x%x\n",
__func__, err));
return SDIOH_API_RC_FAIL;
}
}
return SDIOH_API_RC_SUCCESS;
}
extern SDIOH_API_RC
sdioh_interrupt_register(sdioh_info_t *sd, sdioh_cb_fn_t fn, void *argh)
{
sd_trace(("%s: Entering\n", __func__));
if (fn == NULL) {
sd_err(("%s: interrupt handler is NULL, not registering\n",
__func__));
return SDIOH_API_RC_FAIL;
}
#if !defined(OOB_INTR_ONLY)
sd->intr_handler = fn;
sd->intr_handler_arg = argh;
sd->intr_handler_valid = true;
if (gInstance->func[2]) {
sdio_claim_host(gInstance->func[2]);
sdio_claim_irq(gInstance->func[2], IRQHandlerF2);
sdio_release_host(gInstance->func[2]);
}
if (gInstance->func[1]) {
sdio_claim_host(gInstance->func[1]);
sdio_claim_irq(gInstance->func[1], IRQHandler);
sdio_release_host(gInstance->func[1]);
}
#elif defined(HW_OOB)
sdioh_enable_func_intr();
#endif
return SDIOH_API_RC_SUCCESS;
}
extern SDIOH_API_RC sdioh_interrupt_deregister(sdioh_info_t *sd)
{
sd_trace(("%s: Entering\n", __func__));
#if !defined(OOB_INTR_ONLY)
if (gInstance->func[1]) {
sdio_claim_host(gInstance->func[1]);
sdio_release_irq(gInstance->func[1]);
sdio_release_host(gInstance->func[1]);
}
if (gInstance->func[2]) {
sdio_claim_host(gInstance->func[2]);
sdio_release_irq(gInstance->func[2]);
sdio_release_host(gInstance->func[2]);
}
sd->intr_handler_valid = false;
sd->intr_handler = NULL;
sd->intr_handler_arg = NULL;
#elif defined(HW_OOB)
sdioh_disable_func_intr();
#endif
return SDIOH_API_RC_SUCCESS;
}
extern SDIOH_API_RC sdioh_interrupt_query(sdioh_info_t *sd, bool *onoff)
{
sd_trace(("%s: Entering\n", __func__));
*onoff = sd->client_intr_enabled;
return SDIOH_API_RC_SUCCESS;
}
extern bool sdioh_interrupt_pending(sdioh_info_t *sd)
{
return 0;
}
uint sdioh_query_iofnum(sdioh_info_t *sd)
{
return sd->num_funcs;
}
int
sdioh_iovar_op(sdioh_info_t *si, const char *name,
void *params, int plen, void *arg, int len, bool set)
{
const bcm_iovar_t *vi = NULL;
int bcmerror = 0;
int val_size;
s32 int_val = 0;
bool bool_val;
u32 actionid;
ASSERT(name);
ASSERT(len >= 0);
ASSERT(set || (arg && len));
ASSERT(!set || (!params && !plen));
sd_trace(("%s: Enter (%s %s)\n", __func__, (set ? "set" : "get"),
name));
vi = bcm_iovar_lookup(sdioh_iovars, name);
if (vi == NULL) {
bcmerror = -ENOTSUPP;
goto exit;
}
bcmerror = bcm_iovar_lencheck(vi, arg, len, set);
if (bcmerror != 0)
goto exit;
if (params == NULL) {
params = arg;
plen = len;
}
if (vi->type == IOVT_VOID)
val_size = 0;
else if (vi->type == IOVT_BUFFER)
val_size = len;
else
val_size = sizeof(int);
if (plen >= (int)sizeof(int_val))
memcpy(&int_val, params, sizeof(int_val));
bool_val = (int_val != 0) ? true : false;
actionid = set ? IOV_SVAL(vi->varid) : IOV_GVAL(vi->varid);
switch (actionid) {
case IOV_GVAL(IOV_MSGLEVEL):
int_val = (s32) sd_msglevel;
memcpy(arg, &int_val, val_size);
break;
case IOV_SVAL(IOV_MSGLEVEL):
sd_msglevel = int_val;
break;
case IOV_GVAL(IOV_BLOCKMODE):
int_val = (s32) si->sd_blockmode;
memcpy(arg, &int_val, val_size);
break;
case IOV_SVAL(IOV_BLOCKMODE):
si->sd_blockmode = (bool) int_val;
break;
case IOV_GVAL(IOV_BLOCKSIZE):
if ((u32) int_val > si->num_funcs) {
bcmerror = -EINVAL;
break;
}
int_val = (s32) si->client_block_size[int_val];
memcpy(arg, &int_val, val_size);
break;
case IOV_SVAL(IOV_BLOCKSIZE):
{
uint func = ((u32) int_val >> 16);
uint blksize = (u16) int_val;
uint maxsize;
if (func > si->num_funcs) {
bcmerror = -EINVAL;
break;
}
switch (func) {
case 0:
maxsize = 32;
break;
case 1:
maxsize = BLOCK_SIZE_4318;
break;
case 2:
maxsize = BLOCK_SIZE_4328;
break;
default:
maxsize = 0;
}
if (blksize > maxsize) {
bcmerror = -EINVAL;
break;
}
if (!blksize)
blksize = maxsize;
si->client_block_size[func] = blksize;
break;
}
case IOV_GVAL(IOV_RXCHAIN):
int_val = false;
memcpy(arg, &int_val, val_size);
break;
case IOV_GVAL(IOV_DMA):
int_val = (s32) si->sd_use_dma;
memcpy(arg, &int_val, val_size);
break;
case IOV_SVAL(IOV_DMA):
si->sd_use_dma = (bool) int_val;
break;
case IOV_GVAL(IOV_USEINTS):
int_val = (s32) si->use_client_ints;
memcpy(arg, &int_val, val_size);
break;
case IOV_SVAL(IOV_USEINTS):
si->use_client_ints = (bool) int_val;
if (si->use_client_ints)
si->intmask |= CLIENT_INTR;
else
si->intmask &= ~CLIENT_INTR;
break;
case IOV_GVAL(IOV_DIVISOR):
int_val = (u32) sd_divisor;
memcpy(arg, &int_val, val_size);
break;
case IOV_SVAL(IOV_DIVISOR):
sd_divisor = int_val;
break;
case IOV_GVAL(IOV_POWER):
int_val = (u32) sd_power;
memcpy(arg, &int_val, val_size);
break;
case IOV_SVAL(IOV_POWER):
sd_power = int_val;
break;
case IOV_GVAL(IOV_CLOCK):
int_val = (u32) sd_clock;
memcpy(arg, &int_val, val_size);
break;
case IOV_SVAL(IOV_CLOCK):
sd_clock = int_val;
break;
case IOV_GVAL(IOV_SDMODE):
int_val = (u32) sd_sdmode;
memcpy(arg, &int_val, val_size);
break;
case IOV_SVAL(IOV_SDMODE):
sd_sdmode = int_val;
break;
case IOV_GVAL(IOV_HISPEED):
int_val = (u32) sd_hiok;
memcpy(arg, &int_val, val_size);
break;
case IOV_SVAL(IOV_HISPEED):
sd_hiok = int_val;
break;
case IOV_GVAL(IOV_NUMINTS):
int_val = (s32) si->intrcount;
memcpy(arg, &int_val, val_size);
break;
case IOV_GVAL(IOV_NUMLOCALINTS):
int_val = (s32) 0;
memcpy(arg, &int_val, val_size);
break;
case IOV_GVAL(IOV_HOSTREG):
{
sdreg_t *sd_ptr = (sdreg_t *) params;
if (sd_ptr->offset < SD_SysAddr
|| sd_ptr->offset > SD_MaxCurCap) {
sd_err(("%s: bad offset 0x%x\n", __func__,
sd_ptr->offset));
bcmerror = -EINVAL;
break;
}
sd_trace(("%s: rreg%d at offset %d\n", __func__,
(sd_ptr->offset & 1) ? 8
: ((sd_ptr->offset & 2) ? 16 : 32),
sd_ptr->offset));
if (sd_ptr->offset & 1)
int_val = 8;
else if (sd_ptr->offset & 2)
int_val = 16;
else
int_val = 32;
memcpy(arg, &int_val, sizeof(int_val));
break;
}
case IOV_SVAL(IOV_HOSTREG):
{
sdreg_t *sd_ptr = (sdreg_t *) params;
if (sd_ptr->offset < SD_SysAddr
|| sd_ptr->offset > SD_MaxCurCap) {
sd_err(("%s: bad offset 0x%x\n", __func__,
sd_ptr->offset));
bcmerror = -EINVAL;
break;
}
sd_trace(("%s: wreg%d value 0x%08x at offset %d\n",
__func__, sd_ptr->value,
(sd_ptr->offset & 1) ? 8
: ((sd_ptr->offset & 2) ? 16 : 32),
sd_ptr->offset));
break;
}
case IOV_GVAL(IOV_DEVREG):
{
sdreg_t *sd_ptr = (sdreg_t *) params;
u8 data = 0;
if (sdioh_cfg_read
(si, sd_ptr->func, sd_ptr->offset, &data)) {
bcmerror = -EIO;
break;
}
int_val = (int)data;
memcpy(arg, &int_val, sizeof(int_val));
break;
}
case IOV_SVAL(IOV_DEVREG):
{
sdreg_t *sd_ptr = (sdreg_t *) params;
u8 data = (u8) sd_ptr->value;
if (sdioh_cfg_write
(si, sd_ptr->func, sd_ptr->offset, &data)) {
bcmerror = -EIO;
break;
}
break;
}
default:
bcmerror = -ENOTSUPP;
break;
}
exit:
return bcmerror;
}
SDIOH_API_RC sdioh_enable_hw_oob_intr(sdioh_info_t *sd, bool enable)
{
SDIOH_API_RC status;
u8 data;
if (enable)
data = 3;
else
data = 4;
data |= 4;
status = sdioh_request_byte(sd, SDIOH_WRITE, 0, 0xf2, &data);
return status;
}
extern SDIOH_API_RC
sdioh_cfg_read(sdioh_info_t *sd, uint fnc_num, u32 addr, u8 *data)
{
SDIOH_API_RC status;
status = sdioh_request_byte(sd, SDIOH_READ, fnc_num, addr, data);
return status;
}
extern SDIOH_API_RC
sdioh_cfg_write(sdioh_info_t *sd, uint fnc_num, u32 addr, u8 *data)
{
SDIOH_API_RC status;
status = sdioh_request_byte(sd, SDIOH_WRITE, fnc_num, addr, data);
return status;
}
static int sdioh_sdmmc_get_cisaddr(sdioh_info_t *sd, u32 regaddr)
{
int i;
u32 scratch, regdata;
u8 *ptr = (u8 *)&scratch;
for (i = 0; i < 3; i++) {
if ((sdioh_sdmmc_card_regread(sd, 0, regaddr, 1, &regdata)) !=
SUCCESS)
sd_err(("%s: Can't read!\n", __func__));
*ptr++ = (u8) regdata;
regaddr++;
}
scratch = le32_to_cpu(scratch);
scratch &= 0x0001FFFF;
return scratch;
}
extern SDIOH_API_RC
sdioh_cis_read(sdioh_info_t *sd, uint func, u8 *cisd, u32 length)
{
u32 count;
int offset;
u32 foo;
u8 *cis = cisd;
sd_trace(("%s: Func = %d\n", __func__, func));
if (!sd->func_cis_ptr[func]) {
memset(cis, 0, length);
sd_err(("%s: no func_cis_ptr[%d]\n", __func__, func));
return SDIOH_API_RC_FAIL;
}
sd_err(("%s: func_cis_ptr[%d]=0x%04x\n", __func__, func,
sd->func_cis_ptr[func]));
for (count = 0; count < length; count++) {
offset = sd->func_cis_ptr[func] + count;
if (sdioh_sdmmc_card_regread(sd, 0, offset, 1, &foo) < 0) {
sd_err(("%s: regread failed: Can't read CIS\n",
__func__));
return SDIOH_API_RC_FAIL;
}
*cis = (u8) (foo & 0xff);
cis++;
}
return SDIOH_API_RC_SUCCESS;
}
extern SDIOH_API_RC
sdioh_request_byte(sdioh_info_t *sd, uint rw, uint func, uint regaddr,
u8 *byte)
{
int err_ret;
sd_info(("%s: rw=%d, func=%d, addr=0x%05x\n", __func__, rw, func,
regaddr));
DHD_PM_RESUME_WAIT(sdioh_request_byte_wait);
DHD_PM_RESUME_RETURN_ERROR(SDIOH_API_RC_FAIL);
if (rw) {
if (func == 0) {
if (regaddr == SDIOD_CCCR_IOEN) {
if (gInstance->func[2]) {
sdio_claim_host(gInstance->func[2]);
if (*byte & SDIO_FUNC_ENABLE_2) {
err_ret =
sdio_enable_func
(gInstance->func[2]);
if (err_ret)
sd_err(("bcmsdh_sdmmc: enable F2 failed:%d",
err_ret));
} else {
err_ret =
sdio_disable_func
(gInstance->func[2]);
if (err_ret)
sd_err(("bcmsdh_sdmmc: Disab F2 failed:%d",
err_ret));
}
sdio_release_host(gInstance->func[2]);
}
}
#if defined(MMC_SDIO_ABORT)
else if (regaddr == SDIOD_CCCR_IOABORT) {
sdio_claim_host(gInstance->func[func]);
sdio_writeb(gInstance->func[func], *byte,
regaddr, &err_ret);
sdio_release_host(gInstance->func[func]);
}
#endif
else if (regaddr < 0xF0) {
sd_err(("bcmsdh_sdmmc: F0 Wr:0x%02x: write "
"disallowed\n", regaddr));
} else {
sdio_claim_host(gInstance->func[func]);
sdio_f0_writeb(gInstance->func[func], *byte,
regaddr, &err_ret);
sdio_release_host(gInstance->func[func]);
}
} else {
sdio_claim_host(gInstance->func[func]);
sdio_writeb(gInstance->func[func], *byte, regaddr,
&err_ret);
sdio_release_host(gInstance->func[func]);
}
} else {
sdio_claim_host(gInstance->func[func]);
if (func == 0) {
*byte =
sdio_f0_readb(gInstance->func[func], regaddr,
&err_ret);
} else {
*byte =
sdio_readb(gInstance->func[func], regaddr,
&err_ret);
}
sdio_release_host(gInstance->func[func]);
}
if (err_ret)
sd_err(("bcmsdh_sdmmc: Failed to %s byte F%d:@0x%05x=%02x, "
"Err: %d\n", rw ? "Write" : "Read", func, regaddr,
*byte, err_ret));
return ((err_ret == 0) ? SDIOH_API_RC_SUCCESS : SDIOH_API_RC_FAIL);
}
extern SDIOH_API_RC
sdioh_request_word(sdioh_info_t *sd, uint cmd_type, uint rw, uint func,
uint addr, u32 *word, uint nbytes)
{
int err_ret = SDIOH_API_RC_FAIL;
if (func == 0) {
sd_err(("%s: Only CMD52 allowed to F0.\n", __func__));
return SDIOH_API_RC_FAIL;
}
sd_info(("%s: cmd_type=%d, rw=%d, func=%d, addr=0x%05x, nbytes=%d\n",
__func__, cmd_type, rw, func, addr, nbytes));
DHD_PM_RESUME_WAIT(sdioh_request_word_wait);
DHD_PM_RESUME_RETURN_ERROR(SDIOH_API_RC_FAIL);
sdio_claim_host(gInstance->func[func]);
if (rw) {
if (nbytes == 4) {
sdio_writel(gInstance->func[func], *word, addr,
&err_ret);
} else if (nbytes == 2) {
sdio_writew(gInstance->func[func], (*word & 0xFFFF),
addr, &err_ret);
} else {
sd_err(("%s: Invalid nbytes: %d\n", __func__, nbytes));
}
} else {
if (nbytes == 4) {
*word =
sdio_readl(gInstance->func[func], addr, &err_ret);
} else if (nbytes == 2) {
*word =
sdio_readw(gInstance->func[func], addr,
&err_ret) & 0xFFFF;
} else {
sd_err(("%s: Invalid nbytes: %d\n", __func__, nbytes));
}
}
sdio_release_host(gInstance->func[func]);
if (err_ret) {
sd_err(("bcmsdh_sdmmc: Failed to %s word, Err: 0x%08x",
rw ? "Write" : "Read", err_ret));
}
return ((err_ret == 0) ? SDIOH_API_RC_SUCCESS : SDIOH_API_RC_FAIL);
}
static SDIOH_API_RC
sdioh_request_packet(sdioh_info_t *sd, uint fix_inc, uint write, uint func,
uint addr, struct sk_buff *pkt)
{
bool fifo = (fix_inc == SDIOH_DATA_FIX);
u32 SGCount = 0;
int err_ret = 0;
struct sk_buff *pnext;
sd_trace(("%s: Enter\n", __func__));
ASSERT(pkt);
DHD_PM_RESUME_WAIT(sdioh_request_packet_wait);
DHD_PM_RESUME_RETURN_ERROR(SDIOH_API_RC_FAIL);
sdio_claim_host(gInstance->func[func]);
for (pnext = pkt; pnext; pnext = pnext->next) {
uint pkt_len = pnext->len;
pkt_len += 3;
pkt_len &= 0xFFFFFFFC;
#ifdef CONFIG_MMC_MSM7X00A
if ((pkt_len % 64) == 32) {
sd_trace(("%s: Rounding up TX packet +=32\n",
__func__));
pkt_len += 32;
}
#endif
ASSERT(((u32) (pkt->data) & DMA_ALIGN_MASK) == 0);
if ((write) && (!fifo)) {
err_ret = sdio_memcpy_toio(gInstance->func[func], addr,
((u8 *) (pnext->data)),
pkt_len);
} else if (write) {
err_ret = sdio_memcpy_toio(gInstance->func[func], addr,
((u8 *) (pnext->data)),
pkt_len);
} else if (fifo) {
err_ret = sdio_readsb(gInstance->func[func],
((u8 *) (pnext->data)),
addr, pkt_len);
} else {
err_ret = sdio_memcpy_fromio(gInstance->func[func],
((u8 *) (pnext->data)),
addr, pkt_len);
}
if (err_ret) {
sd_err(("%s: %s FAILED %p[%d], addr=0x%05x, pkt_len=%d,"
"ERR=0x%08x\n", __func__,
(write) ? "TX" : "RX",
pnext, SGCount, addr, pkt_len, err_ret));
} else {
sd_trace(("%s: %s xfr'd %p[%d], addr=0x%05x, len=%d\n",
__func__,
(write) ? "TX" : "RX",
pnext, SGCount, addr, pkt_len));
}
if (!fifo)
addr += pkt_len;
SGCount++;
}
sdio_release_host(gInstance->func[func]);
sd_trace(("%s: Exit\n", __func__));
return ((err_ret == 0) ? SDIOH_API_RC_SUCCESS : SDIOH_API_RC_FAIL);
}
extern SDIOH_API_RC
sdioh_request_buffer(sdioh_info_t *sd, uint pio_dma, uint fix_inc, uint write,
uint func, uint addr, uint reg_width, uint buflen_u,
u8 *buffer, struct sk_buff *pkt)
{
SDIOH_API_RC Status;
struct sk_buff *mypkt = NULL;
sd_trace(("%s: Enter\n", __func__));
DHD_PM_RESUME_WAIT(sdioh_request_buffer_wait);
DHD_PM_RESUME_RETURN_ERROR(SDIOH_API_RC_FAIL);
if (pkt == NULL) {
sd_data(("%s: Creating new %s Packet, len=%d\n",
__func__, write ? "TX" : "RX", buflen_u));
mypkt = bcm_pkt_buf_get_skb(buflen_u);
if (!mypkt) {
sd_err(("%s: bcm_pkt_buf_get_skb failed: len %d\n",
__func__, buflen_u));
return SDIOH_API_RC_FAIL;
}
if (write)
memcpy(mypkt->data, buffer, buflen_u);
Status =
sdioh_request_packet(sd, fix_inc, write, func, addr, mypkt);
if (!write)
memcpy(buffer, mypkt->data, buflen_u);
bcm_pkt_buf_free_skb(mypkt);
} else if (((u32) (pkt->data) & DMA_ALIGN_MASK) != 0) {
ASSERT(pkt->next == NULL);
sd_data(("%s: Creating aligned %s Packet, len=%d\n",
__func__, write ? "TX" : "RX", pkt->len));
mypkt = bcm_pkt_buf_get_skb(pkt->len);
if (!mypkt) {
sd_err(("%s: bcm_pkt_buf_get_skb failed: len %d\n",
__func__, pkt->len));
return SDIOH_API_RC_FAIL;
}
if (write)
memcpy(mypkt->data, pkt->data, pkt->len);
Status =
sdioh_request_packet(sd, fix_inc, write, func, addr, mypkt);
if (!write)
memcpy(pkt->data, mypkt->data, mypkt->len);
bcm_pkt_buf_free_skb(mypkt);
} else {
sd_data(("%s: Aligned %s Packet, direct DMA\n",
__func__, write ? "Tx" : "Rx"));
Status =
sdioh_request_packet(sd, fix_inc, write, func, addr, pkt);
}
return Status;
}
extern int sdioh_abort(sdioh_info_t *sd, uint func)
{
#if defined(MMC_SDIO_ABORT)
char t_func = (char)func;
#endif
sd_trace(("%s: Enter\n", __func__));
#if defined(MMC_SDIO_ABORT)
sdioh_request_byte(sd, SD_IO_OP_WRITE, SDIO_FUNC_0, SDIOD_CCCR_IOABORT,
&t_func);
#endif
sd_trace(("%s: Exit\n", __func__));
return SDIOH_API_RC_SUCCESS;
}
int sdioh_sdio_reset(sdioh_info_t *si)
{
sd_trace(("%s: Enter\n", __func__));
sd_trace(("%s: Exit\n", __func__));
return SDIOH_API_RC_SUCCESS;
}
void sdioh_sdmmc_devintr_off(sdioh_info_t *sd)
{
sd_trace(("%s: %d\n", __func__, sd->use_client_ints));
sd->intmask &= ~CLIENT_INTR;
}
void sdioh_sdmmc_devintr_on(sdioh_info_t *sd)
{
sd_trace(("%s: %d\n", __func__, sd->use_client_ints));
sd->intmask |= CLIENT_INTR;
}
int
sdioh_sdmmc_card_regread(sdioh_info_t *sd, int func, u32 regaddr,
int regsize, u32 *data)
{
if ((func == 0) || (regsize == 1)) {
u8 temp = 0;
sdioh_request_byte(sd, SDIOH_READ, func, regaddr, &temp);
*data = temp;
*data &= 0xff;
sd_data(("%s: byte read data=0x%02x\n", __func__, *data));
} else {
sdioh_request_word(sd, 0, SDIOH_READ, func, regaddr, data,
regsize);
if (regsize == 2)
*data &= 0xffff;
sd_data(("%s: word read data=0x%08x\n", __func__, *data));
}
return SUCCESS;
}
static void IRQHandler(struct sdio_func *func)
{
sdioh_info_t *sd;
sd_trace(("bcmsdh_sdmmc: ***IRQHandler\n"));
sd = gInstance->sd;
ASSERT(sd != NULL);
sdio_release_host(gInstance->func[0]);
if (sd->use_client_ints) {
sd->intrcount++;
ASSERT(sd->intr_handler);
ASSERT(sd->intr_handler_arg);
(sd->intr_handler) (sd->intr_handler_arg);
} else {
sd_err(("bcmsdh_sdmmc: ***IRQHandler\n"));
sd_err(("%s: Not ready for intr: enabled %d, handler %p\n",
__func__, sd->client_intr_enabled, sd->intr_handler));
}
sdio_claim_host(gInstance->func[0]);
}
static void IRQHandlerF2(struct sdio_func *func)
{
sdioh_info_t *sd;
sd_trace(("bcmsdh_sdmmc: ***IRQHandlerF2\n"));
sd = gInstance->sd;
ASSERT(sd != NULL);
}
static int
sdioh_sdmmc_card_regwrite(sdioh_info_t *sd, int func, u32 regaddr,
int regsize, u32 data)
{
if ((func == 0) || (regsize == 1)) {
u8 temp;
temp = data & 0xff;
sdioh_request_byte(sd, SDIOH_READ, func, regaddr, &temp);
sd_data(("%s: byte write data=0x%02x\n", __func__, data));
} else {
if (regsize == 2)
data &= 0xffff;
sdioh_request_word(sd, 0, SDIOH_READ, func, regaddr, &data,
regsize);
sd_data(("%s: word write data=0x%08x\n", __func__, data));
}
return SUCCESS;
}
int sdioh_start(sdioh_info_t *si, int stage)
{
return 0;
}
int sdioh_stop(sdioh_info_t *si)
{
return 0;
}
