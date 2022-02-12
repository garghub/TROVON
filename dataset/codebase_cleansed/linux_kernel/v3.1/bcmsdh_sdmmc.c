static int brcmf_sdioh_enablefuncs(struct sdioh_info *sd)
{
int err_ret;
u32 fbraddr;
u8 func;
sd_trace(("%s\n", __func__));
sd->com_cis_ptr = brcmf_sdioh_get_cisaddr(sd, SDIO_CCCR_CIS);
sd->func_cis_ptr[0] = sd->com_cis_ptr;
sd_info(("%s: Card's Common CIS Ptr = 0x%x\n", __func__,
sd->com_cis_ptr));
for (fbraddr = SDIO_FBR_BASE(1), func = 1;
func <= sd->num_funcs; func++, fbraddr += SDIOD_FBR_SIZE) {
sd->func_cis_ptr[func] =
brcmf_sdioh_get_cisaddr(sd, SDIO_FBR_CIS + fbraddr);
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
sd_err(("brcmf_sdioh_enablefuncs: Failed to enable F1 "
"Err: 0x%08x\n", err_ret));
}
return false;
}
struct sdioh_info *brcmf_sdioh_attach(void *bar0, uint irq)
{
struct sdioh_info *sd;
int err_ret;
sd_trace(("%s\n", __func__));
if (gInstance == NULL) {
sd_err(("%s: SDIO Device not present\n", __func__));
return NULL;
}
sd = kzalloc(sizeof(struct sdioh_info), GFP_ATOMIC);
if (sd == NULL) {
sd_err(("sdioh_attach: out of memory\n"));
return NULL;
}
if (brcmf_sdioh_osinit(sd) != 0) {
sd_err(("%s:sdioh_sdmmc_osinit() failed\n", __func__));
kfree(sd);
return NULL;
}
sd->num_funcs = 2;
sd->use_client_ints = true;
sd->client_block_size[0] = 64;
gInstance->sd = sd;
sdio_claim_host(gInstance->func[1]);
sd->client_block_size[1] = 64;
err_ret = sdio_set_block_size(gInstance->func[1], 64);
if (err_ret)
sd_err(("brcmf_sdioh_attach: Failed to set F1 blocksize\n"));
sdio_release_host(gInstance->func[1]);
if (gInstance->func[2]) {
sdio_claim_host(gInstance->func[2]);
sd->client_block_size[2] = sd_f2_blocksize;
err_ret =
sdio_set_block_size(gInstance->func[2], sd_f2_blocksize);
if (err_ret)
sd_err(("brcmf_sdioh_attach: Failed to set F2 blocksize"
" to %d\n", sd_f2_blocksize));
sdio_release_host(gInstance->func[2]);
}
brcmf_sdioh_enablefuncs(sd);
sd_trace(("%s: Done\n", __func__));
return sd;
}
extern int brcmf_sdioh_detach(struct sdioh_info *sd)
{
sd_trace(("%s\n", __func__));
if (sd) {
sdio_claim_host(gInstance->func[2]);
sdio_disable_func(gInstance->func[2]);
sdio_release_host(gInstance->func[2]);
sdio_claim_host(gInstance->func[1]);
sdio_disable_func(gInstance->func[1]);
sdio_release_host(gInstance->func[1]);
brcmf_sdioh_osfree(sd);
kfree(sd);
}
return 0;
}
extern int
brcmf_sdioh_interrupt_register(struct sdioh_info *sd, void (*fn)(void *),
void *argh)
{
sd_trace(("%s: Entering\n", __func__));
if (fn == NULL) {
sd_err(("%s: interrupt handler is NULL, not registering\n",
__func__));
return -EINVAL;
}
sd->intr_handler = fn;
sd->intr_handler_arg = argh;
sd->intr_handler_valid = true;
if (gInstance->func[2]) {
sdio_claim_host(gInstance->func[2]);
sdio_claim_irq(gInstance->func[2], brcmf_sdioh_irqhandler_f2);
sdio_release_host(gInstance->func[2]);
}
if (gInstance->func[1]) {
sdio_claim_host(gInstance->func[1]);
sdio_claim_irq(gInstance->func[1], brcmf_sdioh_irqhandler);
sdio_release_host(gInstance->func[1]);
}
return 0;
}
extern int brcmf_sdioh_interrupt_deregister(struct sdioh_info *sd)
{
sd_trace(("%s: Entering\n", __func__));
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
return 0;
}
int
brcmf_sdioh_iovar_op(struct sdioh_info *si, const char *name,
void *params, int plen, void *arg, int len, bool set)
{
const struct brcmu_iovar *vi = NULL;
int bcmerror = 0;
int val_size;
s32 int_val = 0;
bool bool_val;
u32 actionid;
if (name == NULL || len <= 0)
return -EINVAL;
if (set && (params || plen))
return -EINVAL;
if (!set && !(arg && len))
return -EINVAL;
sd_trace(("%s: Enter (%s %s)\n", __func__, (set ? "set" : "get"),
name));
vi = brcmu_iovar_lookup(sdioh_iovars, name);
if (vi == NULL) {
bcmerror = -ENOTSUPP;
goto exit;
}
bcmerror = brcmu_iovar_lencheck(vi, arg, len, set);
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
case IOV_GVAL(IOV_NUMINTS):
int_val = (s32) si->intrcount;
memcpy(arg, &int_val, val_size);
break;
case IOV_GVAL(IOV_DEVREG):
{
struct brcmf_sdreg *sd_ptr =
(struct brcmf_sdreg *) params;
u8 data = 0;
if (brcmf_sdioh_cfg_read
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
struct brcmf_sdreg *sd_ptr =
(struct brcmf_sdreg *) params;
u8 data = (u8) sd_ptr->value;
if (brcmf_sdioh_cfg_write
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
extern int
brcmf_sdioh_cfg_read(struct sdioh_info *sd, uint fnc_num, u32 addr, u8 *data)
{
int status;
status = brcmf_sdioh_request_byte(sd, SDIOH_READ, fnc_num, addr, data);
return status;
}
extern int
brcmf_sdioh_cfg_write(struct sdioh_info *sd, uint fnc_num, u32 addr, u8 *data)
{
int status;
status = brcmf_sdioh_request_byte(sd, SDIOH_WRITE, fnc_num, addr, data);
return status;
}
static int brcmf_sdioh_get_cisaddr(struct sdioh_info *sd, u32 regaddr)
{
int i;
u32 scratch, regdata;
u8 *ptr = (u8 *)&scratch;
for (i = 0; i < 3; i++) {
if ((brcmf_sdioh_card_regread(sd, 0, regaddr, 1, &regdata)) !=
SUCCESS)
sd_err(("%s: Can't read!\n", __func__));
*ptr++ = (u8) regdata;
regaddr++;
}
scratch = le32_to_cpu(scratch);
scratch &= 0x0001FFFF;
return scratch;
}
extern int
brcmf_sdioh_cis_read(struct sdioh_info *sd, uint func, u8 *cisd, u32 length)
{
u32 count;
int offset;
u32 foo;
u8 *cis = cisd;
sd_trace(("%s: Func = %d\n", __func__, func));
if (!sd->func_cis_ptr[func]) {
memset(cis, 0, length);
sd_err(("%s: no func_cis_ptr[%d]\n", __func__, func));
return -ENOTSUPP;
}
sd_err(("%s: func_cis_ptr[%d]=0x%04x\n", __func__, func,
sd->func_cis_ptr[func]));
for (count = 0; count < length; count++) {
offset = sd->func_cis_ptr[func] + count;
if (brcmf_sdioh_card_regread(sd, 0, offset, 1, &foo) < 0) {
sd_err(("%s: regread failed: Can't read CIS\n",
__func__));
return -EIO;
}
*cis = (u8) (foo & 0xff);
cis++;
}
return 0;
}
extern int
brcmf_sdioh_request_byte(struct sdioh_info *sd, uint rw, uint func,
uint regaddr, u8 *byte)
{
int err_ret;
sd_info(("%s: rw=%d, func=%d, addr=0x%05x\n", __func__, rw, func,
regaddr));
BRCMF_PM_RESUME_WAIT(sdioh_request_byte_wait);
BRCMF_PM_RESUME_RETURN_ERROR(-EIO);
if (rw) {
if (func == 0) {
if (regaddr == SDIO_CCCR_IOEx) {
if (gInstance->func[2]) {
sdio_claim_host(gInstance->func[2]);
if (*byte & SDIO_FUNC_ENABLE_2) {
err_ret =
sdio_enable_func
(gInstance->func[2]);
if (err_ret)
sd_err(("request_byte: "
"enable F2 "
"failed:%d\n",
err_ret));
} else {
err_ret =
sdio_disable_func
(gInstance->func[2]);
if (err_ret)
sd_err(("request_byte: "
"Disab F2 "
"failed:%d\n",
err_ret));
}
sdio_release_host(gInstance->func[2]);
}
}
else if (regaddr == SDIO_CCCR_ABORT) {
sdio_claim_host(gInstance->func[func]);
sdio_writeb(gInstance->func[func], *byte,
regaddr, &err_ret);
sdio_release_host(gInstance->func[func]);
} else if (regaddr < 0xF0) {
sd_err(("brcmf: F0 Wr:0x%02x: write "
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
sd_err(("brcmf: Failed to %s byte F%d:@0x%05x=%02x, "
"Err: %d\n", rw ? "Write" : "Read", func, regaddr,
*byte, err_ret));
return err_ret;
}
extern int
brcmf_sdioh_request_word(struct sdioh_info *sd, uint cmd_type, uint rw,
uint func, uint addr, u32 *word, uint nbytes)
{
int err_ret = -EIO;
if (func == 0) {
sd_err(("%s: Only CMD52 allowed to F0.\n", __func__));
return -EINVAL;
}
sd_info(("%s: cmd_type=%d, rw=%d, func=%d, addr=0x%05x, nbytes=%d\n",
__func__, cmd_type, rw, func, addr, nbytes));
BRCMF_PM_RESUME_WAIT(sdioh_request_word_wait);
BRCMF_PM_RESUME_RETURN_ERROR(-EIO);
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
sd_err(("brcmf: Failed to %s word, Err: 0x%08x\n",
rw ? "Write" : "Read", err_ret));
}
return err_ret;
}
static int
brcmf_sdioh_request_packet(struct sdioh_info *sd, uint fix_inc, uint write,
uint func, uint addr, struct sk_buff *pkt)
{
bool fifo = (fix_inc == SDIOH_DATA_FIX);
u32 SGCount = 0;
int err_ret = 0;
struct sk_buff *pnext;
sd_trace(("%s: Enter\n", __func__));
BRCMF_PM_RESUME_WAIT(sdioh_request_packet_wait);
BRCMF_PM_RESUME_RETURN_ERROR(-EIO);
sdio_claim_host(gInstance->func[func]);
for (pnext = pkt; pnext; pnext = pnext->next) {
uint pkt_len = pnext->len;
pkt_len += 3;
pkt_len &= 0xFFFFFFFC;
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
return err_ret;
}
extern int
brcmf_sdioh_request_buffer(struct sdioh_info *sd, uint pio_dma, uint fix_inc,
uint write, uint func, uint addr, uint reg_width,
uint buflen_u, u8 *buffer, struct sk_buff *pkt)
{
int Status;
struct sk_buff *mypkt = NULL;
sd_trace(("%s: Enter\n", __func__));
BRCMF_PM_RESUME_WAIT(sdioh_request_buffer_wait);
BRCMF_PM_RESUME_RETURN_ERROR(-EIO);
if (pkt == NULL) {
sd_data(("%s: Creating new %s Packet, len=%d\n",
__func__, write ? "TX" : "RX", buflen_u));
mypkt = brcmu_pkt_buf_get_skb(buflen_u);
if (!mypkt) {
sd_err(("%s: brcmu_pkt_buf_get_skb failed: len %d\n",
__func__, buflen_u));
return -EIO;
}
if (write)
memcpy(mypkt->data, buffer, buflen_u);
Status = brcmf_sdioh_request_packet(sd, fix_inc, write, func,
addr, mypkt);
if (!write)
memcpy(buffer, mypkt->data, buflen_u);
brcmu_pkt_buf_free_skb(mypkt);
} else if (((ulong) (pkt->data) & DMA_ALIGN_MASK) != 0) {
sd_data(("%s: Creating aligned %s Packet, len=%d\n",
__func__, write ? "TX" : "RX", pkt->len));
mypkt = brcmu_pkt_buf_get_skb(pkt->len);
if (!mypkt) {
sd_err(("%s: brcmu_pkt_buf_get_skb failed: len %d\n",
__func__, pkt->len));
return -EIO;
}
if (write)
memcpy(mypkt->data, pkt->data, pkt->len);
Status = brcmf_sdioh_request_packet(sd, fix_inc, write, func,
addr, mypkt);
if (!write)
memcpy(pkt->data, mypkt->data, mypkt->len);
brcmu_pkt_buf_free_skb(mypkt);
} else {
sd_data(("%s: Aligned %s Packet, direct DMA\n",
__func__, write ? "Tx" : "Rx"));
Status = brcmf_sdioh_request_packet(sd, fix_inc, write, func,
addr, pkt);
}
return Status;
}
extern int brcmf_sdioh_abort(struct sdioh_info *sd, uint func)
{
char t_func = (char)func;
sd_trace(("%s: Enter\n", __func__));
brcmf_sdioh_request_byte(sd, SDIOH_WRITE, SDIO_FUNC_0, SDIO_CCCR_ABORT,
&t_func);
sd_trace(("%s: Exit\n", __func__));
return 0;
}
void brcmf_sdioh_dev_intr_off(struct sdioh_info *sd)
{
sd_trace(("%s: %d\n", __func__, sd->use_client_ints));
sd->intmask &= ~CLIENT_INTR;
}
void brcmf_sdioh_dev_intr_on(struct sdioh_info *sd)
{
sd_trace(("%s: %d\n", __func__, sd->use_client_ints));
sd->intmask |= CLIENT_INTR;
}
int
brcmf_sdioh_card_regread(struct sdioh_info *sd, int func, u32 regaddr,
int regsize, u32 *data)
{
if ((func == 0) || (regsize == 1)) {
u8 temp = 0;
brcmf_sdioh_request_byte(sd, SDIOH_READ, func, regaddr, &temp);
*data = temp;
*data &= 0xff;
sd_data(("%s: byte read data=0x%02x\n", __func__, *data));
} else {
brcmf_sdioh_request_word(sd, 0, SDIOH_READ, func, regaddr, data,
regsize);
if (regsize == 2)
*data &= 0xffff;
sd_data(("%s: word read data=0x%08x\n", __func__, *data));
}
return SUCCESS;
}
static void brcmf_sdioh_irqhandler(struct sdio_func *func)
{
struct sdioh_info *sd;
sd_trace(("brcmf: ***IRQHandler\n"));
sd = gInstance->sd;
sdio_release_host(gInstance->func[0]);
if (sd->use_client_ints) {
sd->intrcount++;
(sd->intr_handler) (sd->intr_handler_arg);
} else {
sd_err(("brcmf: ***IRQHandler\n"));
sd_err(("%s: Not ready for intr: enabled %d, handler %p\n",
__func__, sd->client_intr_enabled, sd->intr_handler));
}
sdio_claim_host(gInstance->func[0]);
}
static void brcmf_sdioh_irqhandler_f2(struct sdio_func *func)
{
struct sdioh_info *sd;
sd_trace(("brcmf: ***IRQHandlerF2\n"));
sd = gInstance->sd;
}
static int brcmf_ops_sdio_probe(struct sdio_func *func,
const struct sdio_device_id *id)
{
int ret = 0;
static struct sdio_func sdio_func_0;
sd_trace(("sdio_probe: %s Enter\n", __func__));
sd_trace(("sdio_probe: func->class=%x\n", func->class));
sd_trace(("sdio_vendor: 0x%04x\n", func->vendor));
sd_trace(("sdio_device: 0x%04x\n", func->device));
sd_trace(("Function#: 0x%04x\n", func->num));
if (func->num == 1) {
sdio_func_0.num = 0;
sdio_func_0.card = func->card;
gInstance->func[0] = &sdio_func_0;
if (func->device == 0x4) {
gInstance->func[2] = NULL;
sd_trace(("NIC found, calling brcmf_sdio_probe...\n"));
ret = brcmf_sdio_probe(&sdmmc_dev);
}
}
gInstance->func[func->num] = func;
if (func->num == 2) {
brcmf_cfg80211_sdio_func(func);
sd_trace(("F2 found, calling brcmf_sdio_probe...\n"));
ret = brcmf_sdio_probe(&sdmmc_dev);
}
return ret;
}
static void brcmf_ops_sdio_remove(struct sdio_func *func)
{
sd_trace(("%s Enter\n", __func__));
sd_info(("func->class=%x\n", func->class));
sd_info(("sdio_vendor: 0x%04x\n", func->vendor));
sd_info(("sdio_device: 0x%04x\n", func->device));
sd_info(("Function#: 0x%04x\n", func->num));
if (func->num == 2) {
sd_trace(("F2 found, calling brcmf_sdio_remove...\n"));
brcmf_sdio_remove(&sdmmc_dev);
}
}
static int brcmf_sdio_suspend(struct device *dev)
{
mmc_pm_flag_t sdio_flags;
int ret = 0;
sd_trace(("%s\n", __func__));
sdio_flags = sdio_get_host_pm_caps(gInstance->func[1]);
if (!(sdio_flags & MMC_PM_KEEP_POWER)) {
sd_err(("Host can't keep power while suspended\n"));
return -EINVAL;
}
ret = sdio_set_host_pm_flags(gInstance->func[1], MMC_PM_KEEP_POWER);
if (ret) {
sd_err(("Failed to set pm_flags\n"));
return ret;
}
brcmf_sdio_wdtmr_enable(false);
return ret;
}
static int brcmf_sdio_resume(struct device *dev)
{
brcmf_sdio_wdtmr_enable(true);
return 0;
}
int brcmf_sdioh_osinit(struct sdioh_info *sd)
{
struct sdos_info *sdos;
sdos = kmalloc(sizeof(struct sdos_info), GFP_ATOMIC);
sd->sdos_info = (void *)sdos;
if (sdos == NULL)
return -ENOMEM;
sdos->sd = sd;
spin_lock_init(&sdos->lock);
return 0;
}
void brcmf_sdioh_osfree(struct sdioh_info *sd)
{
struct sdos_info *sdos;
sdos = (struct sdos_info *)sd->sdos_info;
kfree(sdos);
}
int brcmf_sdioh_interrupt_set(struct sdioh_info *sd, bool enable)
{
unsigned long flags;
struct sdos_info *sdos;
sd_trace(("%s: %s\n", __func__, enable ? "Enabling" : "Disabling"));
sdos = (struct sdos_info *)sd->sdos_info;
if (enable && !(sd->intr_handler && sd->intr_handler_arg)) {
sd_err(("%s: no handler registered, will not enable\n",
__func__));
return -EINVAL;
}
spin_lock_irqsave(&sdos->lock, flags);
sd->client_intr_enabled = enable;
if (enable)
brcmf_sdioh_dev_intr_on(sd);
else
brcmf_sdioh_dev_intr_off(sd);
spin_unlock_irqrestore(&sdos->lock, flags);
return 0;
}
int brcmf_sdio_function_init(void)
{
int error = 0;
sd_trace(("brcmf_sdio_function_init: %s Enter\n", __func__));
gInstance = kzalloc(sizeof(struct brcmf_sdmmc_instance), GFP_KERNEL);
if (!gInstance)
return -ENOMEM;
memset(&sdmmc_dev, 0, sizeof(sdmmc_dev));
error = sdio_register_driver(&brcmf_sdmmc_driver);
return error;
}
void brcmf_sdio_function_cleanup(void)
{
sd_trace(("%s Enter\n", __func__));
sdio_unregister_driver(&brcmf_sdmmc_driver);
kfree(gInstance);
}
