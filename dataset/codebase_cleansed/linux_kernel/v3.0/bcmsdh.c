void bcmsdh_enable_hw_oob_intr(bcmsdh_info_t *sdh, bool enable)
{
sdioh_enable_hw_oob_intr(sdh->sdioh, enable);
}
bcmsdh_info_t *bcmsdh_attach(void *cfghdl, void **regsva, uint irq)
{
bcmsdh_info_t *bcmsdh;
bcmsdh = kzalloc(sizeof(bcmsdh_info_t), GFP_ATOMIC);
if (bcmsdh == NULL) {
BCMSDH_ERROR(("bcmsdh_attach: out of memory"));
return NULL;
}
l_bcmsdh = bcmsdh;
bcmsdh->sdioh = sdioh_attach(cfghdl, irq);
if (!bcmsdh->sdioh) {
bcmsdh_detach(bcmsdh);
return NULL;
}
bcmsdh->init_success = true;
*regsva = (u32 *) SI_ENUM_BASE;
bcmsdh->sbwad = SI_ENUM_BASE;
return bcmsdh;
}
int bcmsdh_detach(void *sdh)
{
bcmsdh_info_t *bcmsdh = (bcmsdh_info_t *) sdh;
if (bcmsdh != NULL) {
if (bcmsdh->sdioh) {
sdioh_detach(bcmsdh->sdioh);
bcmsdh->sdioh = NULL;
}
kfree(bcmsdh);
}
l_bcmsdh = NULL;
return 0;
}
int
bcmsdh_iovar_op(void *sdh, const char *name,
void *params, int plen, void *arg, int len, bool set)
{
bcmsdh_info_t *bcmsdh = (bcmsdh_info_t *) sdh;
return sdioh_iovar_op(bcmsdh->sdioh, name, params, plen, arg, len, set);
}
bool bcmsdh_intr_query(void *sdh)
{
bcmsdh_info_t *bcmsdh = (bcmsdh_info_t *) sdh;
SDIOH_API_RC status;
bool on;
ASSERT(bcmsdh);
status = sdioh_interrupt_query(bcmsdh->sdioh, &on);
if (SDIOH_API_SUCCESS(status))
return false;
else
return on;
}
int bcmsdh_intr_enable(void *sdh)
{
bcmsdh_info_t *bcmsdh = (bcmsdh_info_t *) sdh;
SDIOH_API_RC status;
ASSERT(bcmsdh);
status = sdioh_interrupt_set(bcmsdh->sdioh, true);
return SDIOH_API_SUCCESS(status) ? 0 : -EIO;
}
int bcmsdh_intr_disable(void *sdh)
{
bcmsdh_info_t *bcmsdh = (bcmsdh_info_t *) sdh;
SDIOH_API_RC status;
ASSERT(bcmsdh);
status = sdioh_interrupt_set(bcmsdh->sdioh, false);
return SDIOH_API_SUCCESS(status) ? 0 : -EIO;
}
int bcmsdh_intr_reg(void *sdh, bcmsdh_cb_fn_t fn, void *argh)
{
bcmsdh_info_t *bcmsdh = (bcmsdh_info_t *) sdh;
SDIOH_API_RC status;
ASSERT(bcmsdh);
status = sdioh_interrupt_register(bcmsdh->sdioh, fn, argh);
return SDIOH_API_SUCCESS(status) ? 0 : -EIO;
}
int bcmsdh_intr_dereg(void *sdh)
{
bcmsdh_info_t *bcmsdh = (bcmsdh_info_t *) sdh;
SDIOH_API_RC status;
ASSERT(bcmsdh);
status = sdioh_interrupt_deregister(bcmsdh->sdioh);
return SDIOH_API_SUCCESS(status) ? 0 : -EIO;
}
bool bcmsdh_intr_pending(void *sdh)
{
bcmsdh_info_t *bcmsdh = (bcmsdh_info_t *) sdh;
ASSERT(sdh);
return sdioh_interrupt_pending(bcmsdh->sdioh);
}
int bcmsdh_devremove_reg(void *sdh, bcmsdh_cb_fn_t fn, void *argh)
{
ASSERT(sdh);
return -ENOTSUPP;
}
u8 bcmsdh_cfg_read(void *sdh, uint fnc_num, u32 addr, int *err)
{
bcmsdh_info_t *bcmsdh = (bcmsdh_info_t *) sdh;
SDIOH_API_RC status;
#ifdef SDIOH_API_ACCESS_RETRY_LIMIT
s32 retry = 0;
#endif
u8 data = 0;
if (!bcmsdh)
bcmsdh = l_bcmsdh;
ASSERT(bcmsdh->init_success);
#ifdef SDIOH_API_ACCESS_RETRY_LIMIT
do {
if (retry)
udelay(1000);
#endif
status =
sdioh_cfg_read(bcmsdh->sdioh, fnc_num, addr,
(u8 *) &data);
#ifdef SDIOH_API_ACCESS_RETRY_LIMIT
} while (!SDIOH_API_SUCCESS(status)
&& (retry++ < SDIOH_API_ACCESS_RETRY_LIMIT));
#endif
if (err)
*err = (SDIOH_API_SUCCESS(status) ? 0 : -EIO);
BCMSDH_INFO(("%s:fun = %d, addr = 0x%x, u8data = 0x%x\n",
__func__, fnc_num, addr, data));
return data;
}
void
bcmsdh_cfg_write(void *sdh, uint fnc_num, u32 addr, u8 data, int *err)
{
bcmsdh_info_t *bcmsdh = (bcmsdh_info_t *) sdh;
SDIOH_API_RC status;
#ifdef SDIOH_API_ACCESS_RETRY_LIMIT
s32 retry = 0;
#endif
if (!bcmsdh)
bcmsdh = l_bcmsdh;
ASSERT(bcmsdh->init_success);
#ifdef SDIOH_API_ACCESS_RETRY_LIMIT
do {
if (retry)
udelay(1000);
#endif
status =
sdioh_cfg_write(bcmsdh->sdioh, fnc_num, addr,
(u8 *) &data);
#ifdef SDIOH_API_ACCESS_RETRY_LIMIT
} while (!SDIOH_API_SUCCESS(status)
&& (retry++ < SDIOH_API_ACCESS_RETRY_LIMIT));
#endif
if (err)
*err = SDIOH_API_SUCCESS(status) ? 0 : -EIO;
BCMSDH_INFO(("%s:fun = %d, addr = 0x%x, u8data = 0x%x\n",
__func__, fnc_num, addr, data));
}
u32 bcmsdh_cfg_read_word(void *sdh, uint fnc_num, u32 addr, int *err)
{
bcmsdh_info_t *bcmsdh = (bcmsdh_info_t *) sdh;
SDIOH_API_RC status;
u32 data = 0;
if (!bcmsdh)
bcmsdh = l_bcmsdh;
ASSERT(bcmsdh->init_success);
status =
sdioh_request_word(bcmsdh->sdioh, SDIOH_CMD_TYPE_NORMAL, SDIOH_READ,
fnc_num, addr, &data, 4);
if (err)
*err = (SDIOH_API_SUCCESS(status) ? 0 : -EIO);
BCMSDH_INFO(("%s:fun = %d, addr = 0x%x, u32data = 0x%x\n",
__func__, fnc_num, addr, data));
return data;
}
void
bcmsdh_cfg_write_word(void *sdh, uint fnc_num, u32 addr, u32 data,
int *err)
{
bcmsdh_info_t *bcmsdh = (bcmsdh_info_t *) sdh;
SDIOH_API_RC status;
if (!bcmsdh)
bcmsdh = l_bcmsdh;
ASSERT(bcmsdh->init_success);
status =
sdioh_request_word(bcmsdh->sdioh, SDIOH_CMD_TYPE_NORMAL,
SDIOH_WRITE, fnc_num, addr, &data, 4);
if (err)
*err = (SDIOH_API_SUCCESS(status) ? 0 : -EIO);
BCMSDH_INFO(("%s:fun = %d, addr = 0x%x, u32data = 0x%x\n",
__func__, fnc_num, addr, data));
}
int bcmsdh_cis_read(void *sdh, uint func, u8 * cis, uint length)
{
bcmsdh_info_t *bcmsdh = (bcmsdh_info_t *) sdh;
SDIOH_API_RC status;
u8 *tmp_buf, *tmp_ptr;
u8 *ptr;
bool ascii = func & ~0xf;
func &= 0x7;
if (!bcmsdh)
bcmsdh = l_bcmsdh;
ASSERT(bcmsdh->init_success);
ASSERT(cis);
ASSERT(length <= SBSDIO_CIS_SIZE_LIMIT);
status = sdioh_cis_read(bcmsdh->sdioh, func, cis, length);
if (ascii) {
tmp_buf = kmalloc(length, GFP_ATOMIC);
if (tmp_buf == NULL) {
BCMSDH_ERROR(("%s: out of memory\n", __func__));
return -ENOMEM;
}
memcpy(tmp_buf, cis, length);
for (tmp_ptr = tmp_buf, ptr = cis; ptr < (cis + length - 4);
tmp_ptr++) {
ptr += sprintf((char *)ptr, "%.2x ", *tmp_ptr & 0xff);
if ((((tmp_ptr - tmp_buf) + 1) & 0xf) == 0)
ptr += sprintf((char *)ptr, "\n");
}
kfree(tmp_buf);
}
return SDIOH_API_SUCCESS(status) ? 0 : -EIO;
}
static int bcmsdhsdio_set_sbaddr_window(void *sdh, u32 address)
{
int err = 0;
bcmsdh_info_t *bcmsdh = (bcmsdh_info_t *) sdh;
bcmsdh_cfg_write(bcmsdh, SDIO_FUNC_1, SBSDIO_FUNC1_SBADDRLOW,
(address >> 8) & SBSDIO_SBADDRLOW_MASK, &err);
if (!err)
bcmsdh_cfg_write(bcmsdh, SDIO_FUNC_1, SBSDIO_FUNC1_SBADDRMID,
(address >> 16) & SBSDIO_SBADDRMID_MASK, &err);
if (!err)
bcmsdh_cfg_write(bcmsdh, SDIO_FUNC_1, SBSDIO_FUNC1_SBADDRHIGH,
(address >> 24) & SBSDIO_SBADDRHIGH_MASK,
&err);
return err;
}
u32 bcmsdh_reg_read(void *sdh, u32 addr, uint size)
{
bcmsdh_info_t *bcmsdh = (bcmsdh_info_t *) sdh;
SDIOH_API_RC status;
u32 word = 0;
uint bar0 = addr & ~SBSDIO_SB_OFT_ADDR_MASK;
BCMSDH_INFO(("%s:fun = 1, addr = 0x%x, ", __func__, addr));
if (!bcmsdh)
bcmsdh = l_bcmsdh;
ASSERT(bcmsdh->init_success);
if (bar0 != bcmsdh->sbwad) {
if (bcmsdhsdio_set_sbaddr_window(bcmsdh, bar0))
return 0xFFFFFFFF;
bcmsdh->sbwad = bar0;
}
addr &= SBSDIO_SB_OFT_ADDR_MASK;
if (size == 4)
addr |= SBSDIO_SB_ACCESS_2_4B_FLAG;
status = sdioh_request_word(bcmsdh->sdioh, SDIOH_CMD_TYPE_NORMAL,
SDIOH_READ, SDIO_FUNC_1, addr, &word, size);
bcmsdh->regfail = !(SDIOH_API_SUCCESS(status));
BCMSDH_INFO(("u32data = 0x%x\n", word));
if (SDIOH_API_SUCCESS(status)) {
switch (size) {
case sizeof(u8):
return word & 0xff;
case sizeof(u16):
return word & 0xffff;
case sizeof(u32):
return word;
default:
bcmsdh->regfail = true;
}
}
BCMSDH_ERROR(("%s: error reading addr 0x%04x size %d\n", __func__,
addr, size));
return 0xFFFFFFFF;
}
u32 bcmsdh_reg_write(void *sdh, u32 addr, uint size, u32 data)
{
bcmsdh_info_t *bcmsdh = (bcmsdh_info_t *) sdh;
SDIOH_API_RC status;
uint bar0 = addr & ~SBSDIO_SB_OFT_ADDR_MASK;
int err = 0;
BCMSDH_INFO(("%s:fun = 1, addr = 0x%x, uint%ddata = 0x%x\n",
__func__, addr, size * 8, data));
if (!bcmsdh)
bcmsdh = l_bcmsdh;
ASSERT(bcmsdh->init_success);
if (bar0 != bcmsdh->sbwad) {
err = bcmsdhsdio_set_sbaddr_window(bcmsdh, bar0);
if (err)
return err;
bcmsdh->sbwad = bar0;
}
addr &= SBSDIO_SB_OFT_ADDR_MASK;
if (size == 4)
addr |= SBSDIO_SB_ACCESS_2_4B_FLAG;
status =
sdioh_request_word(bcmsdh->sdioh, SDIOH_CMD_TYPE_NORMAL,
SDIOH_WRITE, SDIO_FUNC_1, addr, &data, size);
bcmsdh->regfail = !(SDIOH_API_SUCCESS(status));
if (SDIOH_API_SUCCESS(status))
return 0;
BCMSDH_ERROR(("%s: error writing 0x%08x to addr 0x%04x size %d\n",
__func__, data, addr, size));
return 0xFFFFFFFF;
}
bool bcmsdh_regfail(void *sdh)
{
return ((bcmsdh_info_t *) sdh)->regfail;
}
int
bcmsdh_recv_buf(void *sdh, u32 addr, uint fn, uint flags,
u8 *buf, uint nbytes, struct sk_buff *pkt,
bcmsdh_cmplt_fn_t complete, void *handle)
{
bcmsdh_info_t *bcmsdh = (bcmsdh_info_t *) sdh;
SDIOH_API_RC status;
uint incr_fix;
uint width;
uint bar0 = addr & ~SBSDIO_SB_OFT_ADDR_MASK;
int err = 0;
ASSERT(bcmsdh);
ASSERT(bcmsdh->init_success);
BCMSDH_INFO(("%s:fun = %d, addr = 0x%x, size = %d\n",
__func__, fn, addr, nbytes));
ASSERT(!(flags & SDIO_REQ_ASYNC));
if (flags & SDIO_REQ_ASYNC)
return -ENOTSUPP;
if (bar0 != bcmsdh->sbwad) {
err = bcmsdhsdio_set_sbaddr_window(bcmsdh, bar0);
if (err)
return err;
bcmsdh->sbwad = bar0;
}
addr &= SBSDIO_SB_OFT_ADDR_MASK;
incr_fix = (flags & SDIO_REQ_FIXED) ? SDIOH_DATA_FIX : SDIOH_DATA_INC;
width = (flags & SDIO_REQ_4BYTE) ? 4 : 2;
if (width == 4)
addr |= SBSDIO_SB_ACCESS_2_4B_FLAG;
status = sdioh_request_buffer(bcmsdh->sdioh, SDIOH_DATA_PIO, incr_fix,
SDIOH_READ, fn, addr, width, nbytes, buf,
pkt);
return SDIOH_API_SUCCESS(status) ? 0 : -EIO;
}
int
bcmsdh_send_buf(void *sdh, u32 addr, uint fn, uint flags,
u8 *buf, uint nbytes, void *pkt,
bcmsdh_cmplt_fn_t complete, void *handle)
{
bcmsdh_info_t *bcmsdh = (bcmsdh_info_t *) sdh;
SDIOH_API_RC status;
uint incr_fix;
uint width;
uint bar0 = addr & ~SBSDIO_SB_OFT_ADDR_MASK;
int err = 0;
ASSERT(bcmsdh);
ASSERT(bcmsdh->init_success);
BCMSDH_INFO(("%s:fun = %d, addr = 0x%x, size = %d\n",
__func__, fn, addr, nbytes));
ASSERT(!(flags & SDIO_REQ_ASYNC));
if (flags & SDIO_REQ_ASYNC)
return -ENOTSUPP;
if (bar0 != bcmsdh->sbwad) {
err = bcmsdhsdio_set_sbaddr_window(bcmsdh, bar0);
if (err)
return err;
bcmsdh->sbwad = bar0;
}
addr &= SBSDIO_SB_OFT_ADDR_MASK;
incr_fix = (flags & SDIO_REQ_FIXED) ? SDIOH_DATA_FIX : SDIOH_DATA_INC;
width = (flags & SDIO_REQ_4BYTE) ? 4 : 2;
if (width == 4)
addr |= SBSDIO_SB_ACCESS_2_4B_FLAG;
status = sdioh_request_buffer(bcmsdh->sdioh, SDIOH_DATA_PIO, incr_fix,
SDIOH_WRITE, fn, addr, width, nbytes, buf,
pkt);
return SDIOH_API_SUCCESS(status) ? 0 : -EIO;
}
int bcmsdh_rwdata(void *sdh, uint rw, u32 addr, u8 *buf, uint nbytes)
{
bcmsdh_info_t *bcmsdh = (bcmsdh_info_t *) sdh;
SDIOH_API_RC status;
ASSERT(bcmsdh);
ASSERT(bcmsdh->init_success);
ASSERT((addr & SBSDIO_SBWINDOW_MASK) == 0);
addr &= SBSDIO_SB_OFT_ADDR_MASK;
addr |= SBSDIO_SB_ACCESS_2_4B_FLAG;
status =
sdioh_request_buffer(bcmsdh->sdioh, SDIOH_DATA_PIO, SDIOH_DATA_INC,
(rw ? SDIOH_WRITE : SDIOH_READ), SDIO_FUNC_1,
addr, 4, nbytes, buf, NULL);
return SDIOH_API_SUCCESS(status) ? 0 : -EIO;
}
int bcmsdh_abort(void *sdh, uint fn)
{
bcmsdh_info_t *bcmsdh = (bcmsdh_info_t *) sdh;
return sdioh_abort(bcmsdh->sdioh, fn);
}
int bcmsdh_start(void *sdh, int stage)
{
bcmsdh_info_t *bcmsdh = (bcmsdh_info_t *) sdh;
return sdioh_start(bcmsdh->sdioh, stage);
}
int bcmsdh_stop(void *sdh)
{
bcmsdh_info_t *bcmsdh = (bcmsdh_info_t *) sdh;
return sdioh_stop(bcmsdh->sdioh);
}
int bcmsdh_query_device(void *sdh)
{
bcmsdh_info_t *bcmsdh = (bcmsdh_info_t *) sdh;
bcmsdh->vendevid = (PCI_VENDOR_ID_BROADCOM << 16) | 0;
return bcmsdh->vendevid;
}
uint bcmsdh_query_iofnum(void *sdh)
{
bcmsdh_info_t *bcmsdh = (bcmsdh_info_t *) sdh;
if (!bcmsdh)
bcmsdh = l_bcmsdh;
return sdioh_query_iofnum(bcmsdh->sdioh);
}
int bcmsdh_reset(bcmsdh_info_t *sdh)
{
bcmsdh_info_t *bcmsdh = (bcmsdh_info_t *) sdh;
return sdioh_sdio_reset(bcmsdh->sdioh);
}
void *bcmsdh_get_sdioh(bcmsdh_info_t *sdh)
{
ASSERT(sdh);
return sdh->sdioh;
}
u32 bcmsdh_get_dstatus(void *sdh)
{
return 0;
}
u32 bcmsdh_cur_sbwad(void *sdh)
{
bcmsdh_info_t *bcmsdh = (bcmsdh_info_t *) sdh;
if (!bcmsdh)
bcmsdh = l_bcmsdh;
return bcmsdh->sbwad;
}
void bcmsdh_chipinfo(void *sdh, u32 chip, u32 chiprev)
{
return;
}
