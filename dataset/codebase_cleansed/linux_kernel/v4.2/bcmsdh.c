static irqreturn_t brcmf_sdiod_oob_irqhandler(int irq, void *dev_id)
{
struct brcmf_bus *bus_if = dev_get_drvdata(dev_id);
struct brcmf_sdio_dev *sdiodev = bus_if->bus_priv.sdio;
brcmf_dbg(INTR, "OOB intr triggered\n");
if (sdiodev->irq_en) {
disable_irq_nosync(irq);
sdiodev->irq_en = false;
}
brcmf_sdio_isr(sdiodev->bus);
return IRQ_HANDLED;
}
static void brcmf_sdiod_ib_irqhandler(struct sdio_func *func)
{
struct brcmf_bus *bus_if = dev_get_drvdata(&func->dev);
struct brcmf_sdio_dev *sdiodev = bus_if->bus_priv.sdio;
brcmf_dbg(INTR, "IB intr triggered\n");
brcmf_sdio_isr(sdiodev->bus);
}
static void brcmf_sdiod_dummy_irqhandler(struct sdio_func *func)
{
}
int brcmf_sdiod_intr_register(struct brcmf_sdio_dev *sdiodev)
{
int ret = 0;
u8 data;
u32 addr, gpiocontrol;
unsigned long flags;
if ((sdiodev->pdata) && (sdiodev->pdata->oob_irq_supported)) {
brcmf_dbg(SDIO, "Enter, register OOB IRQ %d\n",
sdiodev->pdata->oob_irq_nr);
ret = request_irq(sdiodev->pdata->oob_irq_nr,
brcmf_sdiod_oob_irqhandler,
sdiodev->pdata->oob_irq_flags,
"brcmf_oob_intr",
&sdiodev->func[1]->dev);
if (ret != 0) {
brcmf_err("request_irq failed %d\n", ret);
return ret;
}
sdiodev->oob_irq_requested = true;
spin_lock_init(&sdiodev->irq_en_lock);
spin_lock_irqsave(&sdiodev->irq_en_lock, flags);
sdiodev->irq_en = true;
spin_unlock_irqrestore(&sdiodev->irq_en_lock, flags);
ret = enable_irq_wake(sdiodev->pdata->oob_irq_nr);
if (ret != 0) {
brcmf_err("enable_irq_wake failed %d\n", ret);
return ret;
}
sdiodev->irq_wake = true;
sdio_claim_host(sdiodev->func[1]);
if (sdiodev->bus_if->chip == BRCM_CC_43362_CHIP_ID) {
addr = CORE_CC_REG(SI_ENUM_BASE, gpiocontrol);
gpiocontrol = brcmf_sdiod_regrl(sdiodev, addr, &ret);
gpiocontrol |= 0x2;
brcmf_sdiod_regwl(sdiodev, addr, gpiocontrol, &ret);
brcmf_sdiod_regwb(sdiodev, SBSDIO_GPIO_SELECT, 0xf,
&ret);
brcmf_sdiod_regwb(sdiodev, SBSDIO_GPIO_OUT, 0, &ret);
brcmf_sdiod_regwb(sdiodev, SBSDIO_GPIO_EN, 0x2, &ret);
}
data = brcmf_sdiod_regrb(sdiodev, SDIO_CCCR_IENx, &ret);
data |= 1 << SDIO_FUNC_1 | 1 << SDIO_FUNC_2 | 1;
brcmf_sdiod_regwb(sdiodev, SDIO_CCCR_IENx, data, &ret);
data = SDIO_SEPINT_MASK | SDIO_SEPINT_OE;
if (sdiodev->pdata->oob_irq_flags & IRQF_TRIGGER_HIGH)
data |= SDIO_SEPINT_ACT_HI;
brcmf_sdiod_regwb(sdiodev, SDIO_CCCR_BRCM_SEPINT, data, &ret);
sdio_release_host(sdiodev->func[1]);
} else {
brcmf_dbg(SDIO, "Entering\n");
sdio_claim_host(sdiodev->func[1]);
sdio_claim_irq(sdiodev->func[1], brcmf_sdiod_ib_irqhandler);
sdio_claim_irq(sdiodev->func[2], brcmf_sdiod_dummy_irqhandler);
sdio_release_host(sdiodev->func[1]);
}
return 0;
}
int brcmf_sdiod_intr_unregister(struct brcmf_sdio_dev *sdiodev)
{
brcmf_dbg(SDIO, "Entering\n");
if ((sdiodev->pdata) && (sdiodev->pdata->oob_irq_supported)) {
sdio_claim_host(sdiodev->func[1]);
brcmf_sdiod_regwb(sdiodev, SDIO_CCCR_BRCM_SEPINT, 0, NULL);
brcmf_sdiod_regwb(sdiodev, SDIO_CCCR_IENx, 0, NULL);
sdio_release_host(sdiodev->func[1]);
if (sdiodev->oob_irq_requested) {
sdiodev->oob_irq_requested = false;
if (sdiodev->irq_wake) {
disable_irq_wake(sdiodev->pdata->oob_irq_nr);
sdiodev->irq_wake = false;
}
free_irq(sdiodev->pdata->oob_irq_nr,
&sdiodev->func[1]->dev);
sdiodev->irq_en = false;
}
} else {
sdio_claim_host(sdiodev->func[1]);
sdio_release_irq(sdiodev->func[2]);
sdio_release_irq(sdiodev->func[1]);
sdio_release_host(sdiodev->func[1]);
}
return 0;
}
void brcmf_sdiod_change_state(struct brcmf_sdio_dev *sdiodev,
enum brcmf_sdiod_state state)
{
if (sdiodev->state == BRCMF_SDIOD_NOMEDIUM ||
state == sdiodev->state)
return;
brcmf_dbg(TRACE, "%d -> %d\n", sdiodev->state, state);
switch (sdiodev->state) {
case BRCMF_SDIOD_DATA:
brcmf_bus_change_state(sdiodev->bus_if, BRCMF_BUS_DOWN);
break;
case BRCMF_SDIOD_DOWN:
if (state == BRCMF_SDIOD_DATA)
brcmf_bus_change_state(sdiodev->bus_if, BRCMF_BUS_UP);
break;
default:
break;
}
sdiodev->state = state;
}
static inline int brcmf_sdiod_f0_writeb(struct sdio_func *func,
uint regaddr, u8 byte)
{
int err_ret;
if ((regaddr == SDIO_CCCR_ABORT) ||
(regaddr == SDIO_CCCR_IENx))
sdio_writeb(func, byte, regaddr, &err_ret);
else
sdio_f0_writeb(func, byte, regaddr, &err_ret);
return err_ret;
}
static int brcmf_sdiod_request_data(struct brcmf_sdio_dev *sdiodev, u8 fn,
u32 addr, u8 regsz, void *data, bool write)
{
struct sdio_func *func;
int ret;
brcmf_dbg(SDIO, "rw=%d, func=%d, addr=0x%05x, nbytes=%d\n",
write, fn, addr, regsz);
if (WARN_ON(regsz > 1 && !fn))
return -EINVAL;
func = sdiodev->func[fn];
switch (regsz) {
case sizeof(u8):
if (write) {
if (fn)
sdio_writeb(func, *(u8 *)data, addr, &ret);
else
ret = brcmf_sdiod_f0_writeb(func, addr,
*(u8 *)data);
} else {
if (fn)
*(u8 *)data = sdio_readb(func, addr, &ret);
else
*(u8 *)data = sdio_f0_readb(func, addr, &ret);
}
break;
case sizeof(u16):
if (write)
sdio_writew(func, *(u16 *)data, addr, &ret);
else
*(u16 *)data = sdio_readw(func, addr, &ret);
break;
case sizeof(u32):
if (write)
sdio_writel(func, *(u32 *)data, addr, &ret);
else
*(u32 *)data = sdio_readl(func, addr, &ret);
break;
default:
brcmf_err("invalid size: %d\n", regsz);
break;
}
if (ret)
brcmf_dbg(SDIO, "failed to %s data F%d@0x%05x, err: %d\n",
write ? "write" : "read", fn, addr, ret);
return ret;
}
static int brcmf_sdiod_regrw_helper(struct brcmf_sdio_dev *sdiodev, u32 addr,
u8 regsz, void *data, bool write)
{
u8 func;
s32 retry = 0;
int ret;
if (sdiodev->state == BRCMF_SDIOD_NOMEDIUM)
return -ENOMEDIUM;
if ((addr & ~REG_F0_REG_MASK) == 0)
func = SDIO_FUNC_0;
else
func = SDIO_FUNC_1;
do {
if (!write)
memset(data, 0, regsz);
if (retry)
usleep_range(1000, 2000);
ret = brcmf_sdiod_request_data(sdiodev, func, addr, regsz,
data, write);
} while (ret != 0 && ret != -ENOMEDIUM &&
retry++ < SDIOH_API_ACCESS_RETRY_LIMIT);
if (ret == -ENOMEDIUM)
brcmf_sdiod_change_state(sdiodev, BRCMF_SDIOD_NOMEDIUM);
else if (ret != 0) {
if (addr != SBSDIO_FUNC1_SLEEPCSR)
brcmf_err("failed to %s data F%d@0x%05x, err: %d\n",
write ? "write" : "read", func, addr, ret);
else
brcmf_dbg(SDIO, "failed to %s data F%d@0x%05x, err: %d\n",
write ? "write" : "read", func, addr, ret);
}
return ret;
}
static int
brcmf_sdiod_set_sbaddr_window(struct brcmf_sdio_dev *sdiodev, u32 address)
{
int err = 0, i;
u8 addr[3];
if (sdiodev->state == BRCMF_SDIOD_NOMEDIUM)
return -ENOMEDIUM;
addr[0] = (address >> 8) & SBSDIO_SBADDRLOW_MASK;
addr[1] = (address >> 16) & SBSDIO_SBADDRMID_MASK;
addr[2] = (address >> 24) & SBSDIO_SBADDRHIGH_MASK;
for (i = 0; i < 3; i++) {
err = brcmf_sdiod_regrw_helper(sdiodev,
SBSDIO_FUNC1_SBADDRLOW + i,
sizeof(u8), &addr[i], true);
if (err) {
brcmf_err("failed at addr: 0x%0x\n",
SBSDIO_FUNC1_SBADDRLOW + i);
break;
}
}
return err;
}
static int
brcmf_sdiod_addrprep(struct brcmf_sdio_dev *sdiodev, uint width, u32 *addr)
{
uint bar0 = *addr & ~SBSDIO_SB_OFT_ADDR_MASK;
int err = 0;
if (bar0 != sdiodev->sbwad) {
err = brcmf_sdiod_set_sbaddr_window(sdiodev, bar0);
if (err)
return err;
sdiodev->sbwad = bar0;
}
*addr &= SBSDIO_SB_OFT_ADDR_MASK;
if (width == 4)
*addr |= SBSDIO_SB_ACCESS_2_4B_FLAG;
return 0;
}
u8 brcmf_sdiod_regrb(struct brcmf_sdio_dev *sdiodev, u32 addr, int *ret)
{
u8 data;
int retval;
brcmf_dbg(SDIO, "addr:0x%08x\n", addr);
retval = brcmf_sdiod_regrw_helper(sdiodev, addr, sizeof(data), &data,
false);
brcmf_dbg(SDIO, "data:0x%02x\n", data);
if (ret)
*ret = retval;
return data;
}
u32 brcmf_sdiod_regrl(struct brcmf_sdio_dev *sdiodev, u32 addr, int *ret)
{
u32 data;
int retval;
brcmf_dbg(SDIO, "addr:0x%08x\n", addr);
retval = brcmf_sdiod_addrprep(sdiodev, sizeof(data), &addr);
if (retval)
goto done;
retval = brcmf_sdiod_regrw_helper(sdiodev, addr, sizeof(data), &data,
false);
brcmf_dbg(SDIO, "data:0x%08x\n", data);
done:
if (ret)
*ret = retval;
return data;
}
void brcmf_sdiod_regwb(struct brcmf_sdio_dev *sdiodev, u32 addr,
u8 data, int *ret)
{
int retval;
brcmf_dbg(SDIO, "addr:0x%08x, data:0x%02x\n", addr, data);
retval = brcmf_sdiod_regrw_helper(sdiodev, addr, sizeof(data), &data,
true);
if (ret)
*ret = retval;
}
void brcmf_sdiod_regwl(struct brcmf_sdio_dev *sdiodev, u32 addr,
u32 data, int *ret)
{
int retval;
brcmf_dbg(SDIO, "addr:0x%08x, data:0x%08x\n", addr, data);
retval = brcmf_sdiod_addrprep(sdiodev, sizeof(data), &addr);
if (retval)
goto done;
retval = brcmf_sdiod_regrw_helper(sdiodev, addr, sizeof(data), &data,
true);
done:
if (ret)
*ret = retval;
}
static int brcmf_sdiod_buffrw(struct brcmf_sdio_dev *sdiodev, uint fn,
bool write, u32 addr, struct sk_buff *pkt)
{
unsigned int req_sz;
int err;
req_sz = pkt->len + 3;
req_sz &= (uint)~3;
if (write)
err = sdio_memcpy_toio(sdiodev->func[fn], addr,
((u8 *)(pkt->data)), req_sz);
else if (fn == 1)
err = sdio_memcpy_fromio(sdiodev->func[fn], ((u8 *)(pkt->data)),
addr, req_sz);
else
err = sdio_readsb(sdiodev->func[fn], ((u8 *)(pkt->data)), addr,
req_sz);
if (err == -ENOMEDIUM)
brcmf_sdiod_change_state(sdiodev, BRCMF_SDIOD_NOMEDIUM);
return err;
}
static int brcmf_sdiod_sglist_rw(struct brcmf_sdio_dev *sdiodev, uint fn,
bool write, u32 addr,
struct sk_buff_head *pktlist)
{
unsigned int req_sz, func_blk_sz, sg_cnt, sg_data_sz, pkt_offset;
unsigned int max_req_sz, orig_offset, dst_offset;
unsigned short max_seg_cnt, seg_sz;
unsigned char *pkt_data, *orig_data, *dst_data;
struct sk_buff *pkt_next = NULL, *local_pkt_next;
struct sk_buff_head local_list, *target_list;
struct mmc_request mmc_req;
struct mmc_command mmc_cmd;
struct mmc_data mmc_dat;
struct scatterlist *sgl;
int ret = 0;
if (!pktlist->qlen)
return -EINVAL;
target_list = pktlist;
__skb_queue_head_init(&local_list);
if (sdiodev->pdata && sdiodev->pdata->broken_sg_support && !write) {
req_sz = 0;
skb_queue_walk(pktlist, pkt_next)
req_sz += pkt_next->len;
req_sz = ALIGN(req_sz, sdiodev->func[fn]->cur_blksize);
while (req_sz > PAGE_SIZE) {
pkt_next = brcmu_pkt_buf_get_skb(PAGE_SIZE);
if (pkt_next == NULL) {
ret = -ENOMEM;
goto exit;
}
__skb_queue_tail(&local_list, pkt_next);
req_sz -= PAGE_SIZE;
}
pkt_next = brcmu_pkt_buf_get_skb(req_sz);
if (pkt_next == NULL) {
ret = -ENOMEM;
goto exit;
}
__skb_queue_tail(&local_list, pkt_next);
target_list = &local_list;
}
func_blk_sz = sdiodev->func[fn]->cur_blksize;
max_req_sz = sdiodev->max_request_size;
max_seg_cnt = min_t(unsigned short, sdiodev->max_segment_count,
target_list->qlen);
seg_sz = target_list->qlen;
pkt_offset = 0;
pkt_next = target_list->next;
memset(&mmc_req, 0, sizeof(struct mmc_request));
memset(&mmc_cmd, 0, sizeof(struct mmc_command));
memset(&mmc_dat, 0, sizeof(struct mmc_data));
mmc_dat.sg = sdiodev->sgtable.sgl;
mmc_dat.blksz = func_blk_sz;
mmc_dat.flags = write ? MMC_DATA_WRITE : MMC_DATA_READ;
mmc_cmd.opcode = SD_IO_RW_EXTENDED;
mmc_cmd.arg = write ? 1<<31 : 0;
mmc_cmd.arg |= (fn & 0x7) << 28;
mmc_cmd.arg |= 1<<27;
mmc_cmd.arg |= (fn == 1) ? 1<<26 : 0;
mmc_cmd.flags = MMC_RSP_SPI_R5 | MMC_RSP_R5 | MMC_CMD_ADTC;
mmc_req.cmd = &mmc_cmd;
mmc_req.data = &mmc_dat;
while (seg_sz) {
req_sz = 0;
sg_cnt = 0;
sgl = sdiodev->sgtable.sgl;
while (pkt_next != (struct sk_buff *)target_list) {
pkt_data = pkt_next->data + pkt_offset;
sg_data_sz = pkt_next->len - pkt_offset;
if (sg_data_sz > sdiodev->max_segment_size)
sg_data_sz = sdiodev->max_segment_size;
if (sg_data_sz > max_req_sz - req_sz)
sg_data_sz = max_req_sz - req_sz;
sg_set_buf(sgl, pkt_data, sg_data_sz);
sg_cnt++;
sgl = sg_next(sgl);
req_sz += sg_data_sz;
pkt_offset += sg_data_sz;
if (pkt_offset == pkt_next->len) {
pkt_offset = 0;
pkt_next = pkt_next->next;
}
if (req_sz >= max_req_sz || sg_cnt >= max_seg_cnt)
break;
}
seg_sz -= sg_cnt;
if (req_sz % func_blk_sz != 0) {
brcmf_err("sg request length %u is not %u aligned\n",
req_sz, func_blk_sz);
ret = -ENOTBLK;
goto exit;
}
mmc_dat.sg_len = sg_cnt;
mmc_dat.blocks = req_sz / func_blk_sz;
mmc_cmd.arg |= (addr & 0x1FFFF) << 9;
mmc_cmd.arg |= mmc_dat.blocks & 0x1FF;
if (fn == 1)
addr += req_sz;
mmc_set_data_timeout(&mmc_dat, sdiodev->func[fn]->card);
mmc_wait_for_req(sdiodev->func[fn]->card->host, &mmc_req);
ret = mmc_cmd.error ? mmc_cmd.error : mmc_dat.error;
if (ret == -ENOMEDIUM) {
brcmf_sdiod_change_state(sdiodev, BRCMF_SDIOD_NOMEDIUM);
break;
} else if (ret != 0) {
brcmf_err("CMD53 sg block %s failed %d\n",
write ? "write" : "read", ret);
ret = -EIO;
break;
}
}
if (sdiodev->pdata && sdiodev->pdata->broken_sg_support && !write) {
local_pkt_next = local_list.next;
orig_offset = 0;
skb_queue_walk(pktlist, pkt_next) {
dst_offset = 0;
do {
req_sz = local_pkt_next->len - orig_offset;
req_sz = min_t(uint, pkt_next->len - dst_offset,
req_sz);
orig_data = local_pkt_next->data + orig_offset;
dst_data = pkt_next->data + dst_offset;
memcpy(dst_data, orig_data, req_sz);
orig_offset += req_sz;
dst_offset += req_sz;
if (orig_offset == local_pkt_next->len) {
orig_offset = 0;
local_pkt_next = local_pkt_next->next;
}
if (dst_offset == pkt_next->len)
break;
} while (!skb_queue_empty(&local_list));
}
}
exit:
sg_init_table(sdiodev->sgtable.sgl, sdiodev->sgtable.orig_nents);
while ((pkt_next = __skb_dequeue(&local_list)) != NULL)
brcmu_pkt_buf_free_skb(pkt_next);
return ret;
}
int brcmf_sdiod_recv_buf(struct brcmf_sdio_dev *sdiodev, u8 *buf, uint nbytes)
{
struct sk_buff *mypkt;
int err;
mypkt = brcmu_pkt_buf_get_skb(nbytes);
if (!mypkt) {
brcmf_err("brcmu_pkt_buf_get_skb failed: len %d\n",
nbytes);
return -EIO;
}
err = brcmf_sdiod_recv_pkt(sdiodev, mypkt);
if (!err)
memcpy(buf, mypkt->data, nbytes);
brcmu_pkt_buf_free_skb(mypkt);
return err;
}
int brcmf_sdiod_recv_pkt(struct brcmf_sdio_dev *sdiodev, struct sk_buff *pkt)
{
u32 addr = sdiodev->sbwad;
int err = 0;
brcmf_dbg(SDIO, "addr = 0x%x, size = %d\n", addr, pkt->len);
err = brcmf_sdiod_addrprep(sdiodev, 4, &addr);
if (err)
goto done;
err = brcmf_sdiod_buffrw(sdiodev, SDIO_FUNC_2, false, addr, pkt);
done:
return err;
}
int brcmf_sdiod_recv_chain(struct brcmf_sdio_dev *sdiodev,
struct sk_buff_head *pktq, uint totlen)
{
struct sk_buff *glom_skb;
struct sk_buff *skb;
u32 addr = sdiodev->sbwad;
int err = 0;
brcmf_dbg(SDIO, "addr = 0x%x, size = %d\n",
addr, pktq->qlen);
err = brcmf_sdiod_addrprep(sdiodev, 4, &addr);
if (err)
goto done;
if (pktq->qlen == 1)
err = brcmf_sdiod_buffrw(sdiodev, SDIO_FUNC_2, false, addr,
pktq->next);
else if (!sdiodev->sg_support) {
glom_skb = brcmu_pkt_buf_get_skb(totlen);
if (!glom_skb)
return -ENOMEM;
err = brcmf_sdiod_buffrw(sdiodev, SDIO_FUNC_2, false, addr,
glom_skb);
if (err)
goto done;
skb_queue_walk(pktq, skb) {
memcpy(skb->data, glom_skb->data, skb->len);
skb_pull(glom_skb, skb->len);
}
} else
err = brcmf_sdiod_sglist_rw(sdiodev, SDIO_FUNC_2, false, addr,
pktq);
done:
return err;
}
int brcmf_sdiod_send_buf(struct brcmf_sdio_dev *sdiodev, u8 *buf, uint nbytes)
{
struct sk_buff *mypkt;
u32 addr = sdiodev->sbwad;
int err;
mypkt = brcmu_pkt_buf_get_skb(nbytes);
if (!mypkt) {
brcmf_err("brcmu_pkt_buf_get_skb failed: len %d\n",
nbytes);
return -EIO;
}
memcpy(mypkt->data, buf, nbytes);
err = brcmf_sdiod_addrprep(sdiodev, 4, &addr);
if (!err)
err = brcmf_sdiod_buffrw(sdiodev, SDIO_FUNC_2, true, addr,
mypkt);
brcmu_pkt_buf_free_skb(mypkt);
return err;
}
int brcmf_sdiod_send_pkt(struct brcmf_sdio_dev *sdiodev,
struct sk_buff_head *pktq)
{
struct sk_buff *skb;
u32 addr = sdiodev->sbwad;
int err;
brcmf_dbg(SDIO, "addr = 0x%x, size = %d\n", addr, pktq->qlen);
err = brcmf_sdiod_addrprep(sdiodev, 4, &addr);
if (err)
return err;
if (pktq->qlen == 1 || !sdiodev->sg_support)
skb_queue_walk(pktq, skb) {
err = brcmf_sdiod_buffrw(sdiodev, SDIO_FUNC_2, true,
addr, skb);
if (err)
break;
}
else
err = brcmf_sdiod_sglist_rw(sdiodev, SDIO_FUNC_2, true, addr,
pktq);
return err;
}
int
brcmf_sdiod_ramrw(struct brcmf_sdio_dev *sdiodev, bool write, u32 address,
u8 *data, uint size)
{
int bcmerror = 0;
struct sk_buff *pkt;
u32 sdaddr;
uint dsize;
dsize = min_t(uint, SBSDIO_SB_OFT_ADDR_LIMIT, size);
pkt = dev_alloc_skb(dsize);
if (!pkt) {
brcmf_err("dev_alloc_skb failed: len %d\n", dsize);
return -EIO;
}
pkt->priority = 0;
sdaddr = address & SBSDIO_SB_OFT_ADDR_MASK;
if ((sdaddr + size) & SBSDIO_SBWINDOW_MASK)
dsize = (SBSDIO_SB_OFT_ADDR_LIMIT - sdaddr);
else
dsize = size;
sdio_claim_host(sdiodev->func[1]);
while (size) {
bcmerror = brcmf_sdiod_set_sbaddr_window(sdiodev, address);
if (bcmerror)
break;
brcmf_dbg(SDIO, "%s %d bytes at offset 0x%08x in window 0x%08x\n",
write ? "write" : "read", dsize,
sdaddr, address & SBSDIO_SBWINDOW_MASK);
sdaddr &= SBSDIO_SB_OFT_ADDR_MASK;
sdaddr |= SBSDIO_SB_ACCESS_2_4B_FLAG;
skb_put(pkt, dsize);
if (write)
memcpy(pkt->data, data, dsize);
bcmerror = brcmf_sdiod_buffrw(sdiodev, SDIO_FUNC_1, write,
sdaddr, pkt);
if (bcmerror) {
brcmf_err("membytes transfer failed\n");
break;
}
if (!write)
memcpy(data, pkt->data, dsize);
skb_trim(pkt, 0);
size -= dsize;
if (size) {
data += dsize;
address += dsize;
sdaddr = 0;
dsize = min_t(uint, SBSDIO_SB_OFT_ADDR_LIMIT, size);
}
}
dev_kfree_skb(pkt);
if (brcmf_sdiod_set_sbaddr_window(sdiodev, sdiodev->sbwad))
brcmf_err("FAILED to set window back to 0x%x\n",
sdiodev->sbwad);
sdio_release_host(sdiodev->func[1]);
return bcmerror;
}
int brcmf_sdiod_abort(struct brcmf_sdio_dev *sdiodev, uint fn)
{
char t_func = (char)fn;
brcmf_dbg(SDIO, "Enter\n");
brcmf_sdiod_request_data(sdiodev, SDIO_FUNC_0, SDIO_CCCR_ABORT,
sizeof(t_func), &t_func, true);
brcmf_dbg(SDIO, "Exit\n");
return 0;
}
static void brcmf_sdiod_sgtable_alloc(struct brcmf_sdio_dev *sdiodev)
{
uint nents;
int err;
if (!sdiodev->sg_support)
return;
nents = max_t(uint, BRCMF_DEFAULT_RXGLOM_SIZE, brcmf_sdiod_txglomsz);
nents += (nents >> 4) + 1;
WARN_ON(nents > sdiodev->max_segment_count);
brcmf_dbg(TRACE, "nents=%d\n", nents);
err = sg_alloc_table(&sdiodev->sgtable, nents, GFP_KERNEL);
if (err < 0) {
brcmf_err("allocation failed: disable scatter-gather");
sdiodev->sg_support = false;
}
sdiodev->txglomsz = brcmf_sdiod_txglomsz;
}
static int brcmf_sdiod_freezer_attach(struct brcmf_sdio_dev *sdiodev)
{
sdiodev->freezer = kzalloc(sizeof(*sdiodev->freezer), GFP_KERNEL);
if (!sdiodev->freezer)
return -ENOMEM;
atomic_set(&sdiodev->freezer->thread_count, 0);
atomic_set(&sdiodev->freezer->freezing, 0);
init_waitqueue_head(&sdiodev->freezer->thread_freeze);
init_completion(&sdiodev->freezer->resumed);
return 0;
}
static void brcmf_sdiod_freezer_detach(struct brcmf_sdio_dev *sdiodev)
{
if (sdiodev->freezer) {
WARN_ON(atomic_read(&sdiodev->freezer->freezing));
kfree(sdiodev->freezer);
}
}
static int brcmf_sdiod_freezer_on(struct brcmf_sdio_dev *sdiodev)
{
atomic_t *expect = &sdiodev->freezer->thread_count;
int res = 0;
sdiodev->freezer->frozen_count = 0;
reinit_completion(&sdiodev->freezer->resumed);
atomic_set(&sdiodev->freezer->freezing, 1);
brcmf_sdio_trigger_dpc(sdiodev->bus);
wait_event(sdiodev->freezer->thread_freeze,
atomic_read(expect) == sdiodev->freezer->frozen_count);
sdio_claim_host(sdiodev->func[1]);
res = brcmf_sdio_sleep(sdiodev->bus, true);
sdio_release_host(sdiodev->func[1]);
return res;
}
static void brcmf_sdiod_freezer_off(struct brcmf_sdio_dev *sdiodev)
{
sdio_claim_host(sdiodev->func[1]);
brcmf_sdio_sleep(sdiodev->bus, false);
sdio_release_host(sdiodev->func[1]);
atomic_set(&sdiodev->freezer->freezing, 0);
complete_all(&sdiodev->freezer->resumed);
}
bool brcmf_sdiod_freezing(struct brcmf_sdio_dev *sdiodev)
{
return atomic_read(&sdiodev->freezer->freezing);
}
void brcmf_sdiod_try_freeze(struct brcmf_sdio_dev *sdiodev)
{
if (!brcmf_sdiod_freezing(sdiodev))
return;
sdiodev->freezer->frozen_count++;
wake_up(&sdiodev->freezer->thread_freeze);
wait_for_completion(&sdiodev->freezer->resumed);
}
void brcmf_sdiod_freezer_count(struct brcmf_sdio_dev *sdiodev)
{
atomic_inc(&sdiodev->freezer->thread_count);
}
void brcmf_sdiod_freezer_uncount(struct brcmf_sdio_dev *sdiodev)
{
atomic_dec(&sdiodev->freezer->thread_count);
}
static int brcmf_sdiod_freezer_attach(struct brcmf_sdio_dev *sdiodev)
{
return 0;
}
static void brcmf_sdiod_freezer_detach(struct brcmf_sdio_dev *sdiodev)
{
}
static int brcmf_sdiod_remove(struct brcmf_sdio_dev *sdiodev)
{
sdiodev->state = BRCMF_SDIOD_DOWN;
if (sdiodev->bus) {
brcmf_sdio_remove(sdiodev->bus);
sdiodev->bus = NULL;
}
brcmf_sdiod_freezer_detach(sdiodev);
sdio_claim_host(sdiodev->func[2]);
sdio_disable_func(sdiodev->func[2]);
sdio_release_host(sdiodev->func[2]);
sdio_claim_host(sdiodev->func[1]);
sdio_disable_func(sdiodev->func[1]);
sdio_release_host(sdiodev->func[1]);
sg_free_table(&sdiodev->sgtable);
sdiodev->sbwad = 0;
pm_runtime_allow(sdiodev->func[1]->card->host->parent);
return 0;
}
static void brcmf_sdiod_host_fixup(struct mmc_host *host)
{
pm_runtime_forbid(host->parent);
host->caps |= MMC_CAP_NONREMOVABLE;
}
static int brcmf_sdiod_probe(struct brcmf_sdio_dev *sdiodev)
{
struct sdio_func *func;
struct mmc_host *host;
uint max_blocks;
int ret = 0;
sdiodev->num_funcs = 2;
sdio_claim_host(sdiodev->func[1]);
ret = sdio_set_block_size(sdiodev->func[1], SDIO_FUNC1_BLOCKSIZE);
if (ret) {
brcmf_err("Failed to set F1 blocksize\n");
sdio_release_host(sdiodev->func[1]);
goto out;
}
ret = sdio_set_block_size(sdiodev->func[2], SDIO_FUNC2_BLOCKSIZE);
if (ret) {
brcmf_err("Failed to set F2 blocksize\n");
sdio_release_host(sdiodev->func[1]);
goto out;
}
sdiodev->func[2]->enable_timeout = SDIO_WAIT_F2RDY;
ret = sdio_enable_func(sdiodev->func[1]);
sdio_release_host(sdiodev->func[1]);
if (ret) {
brcmf_err("Failed to enable F1: err=%d\n", ret);
goto out;
}
func = sdiodev->func[2];
host = func->card->host;
sdiodev->sg_support = host->max_segs > 1;
max_blocks = min_t(uint, host->max_blk_count, 511u);
sdiodev->max_request_size = min_t(uint, host->max_req_size,
max_blocks * func->cur_blksize);
sdiodev->max_segment_count = min_t(uint, host->max_segs,
SG_MAX_SINGLE_ALLOC);
sdiodev->max_segment_size = host->max_seg_size;
brcmf_sdiod_sgtable_alloc(sdiodev);
ret = brcmf_sdiod_freezer_attach(sdiodev);
if (ret)
goto out;
sdiodev->bus = brcmf_sdio_probe(sdiodev);
if (!sdiodev->bus) {
ret = -ENODEV;
goto out;
}
brcmf_sdiod_host_fixup(host);
out:
if (ret)
brcmf_sdiod_remove(sdiodev);
return ret;
}
static void brcmf_sdiod_acpi_set_power_manageable(struct device *dev,
int val)
{
#if IS_ENABLED(CONFIG_ACPI)
struct acpi_device *adev;
adev = ACPI_COMPANION(dev);
if (adev)
adev->flags.power_manageable = 0;
#endif
}
static int brcmf_ops_sdio_probe(struct sdio_func *func,
const struct sdio_device_id *id)
{
int err;
struct brcmf_sdio_dev *sdiodev;
struct brcmf_bus *bus_if;
struct device *dev;
brcmf_dbg(SDIO, "Enter\n");
brcmf_dbg(SDIO, "Class=%x\n", func->class);
brcmf_dbg(SDIO, "sdio vendor ID: 0x%04x\n", func->vendor);
brcmf_dbg(SDIO, "sdio device ID: 0x%04x\n", func->device);
brcmf_dbg(SDIO, "Function#: %d\n", func->num);
dev = &func->dev;
brcmf_sdiod_acpi_set_power_manageable(dev, 0);
if (func->num == 1)
return 0;
if (func->num != 2)
return -ENODEV;
bus_if = kzalloc(sizeof(struct brcmf_bus), GFP_KERNEL);
if (!bus_if)
return -ENOMEM;
sdiodev = kzalloc(sizeof(struct brcmf_sdio_dev), GFP_KERNEL);
if (!sdiodev) {
kfree(bus_if);
return -ENOMEM;
}
sdiodev->func[0] = kmemdup(func, sizeof(*func), GFP_KERNEL);
sdiodev->func[0]->num = 0;
sdiodev->func[1] = func->card->sdio_func[0];
sdiodev->func[2] = func;
sdiodev->bus_if = bus_if;
bus_if->bus_priv.sdio = sdiodev;
bus_if->proto_type = BRCMF_PROTO_BCDC;
dev_set_drvdata(&func->dev, bus_if);
dev_set_drvdata(&sdiodev->func[1]->dev, bus_if);
sdiodev->dev = &sdiodev->func[1]->dev;
sdiodev->pdata = brcmfmac_sdio_pdata;
if (!sdiodev->pdata)
brcmf_of_probe(sdiodev);
#ifdef CONFIG_PM_SLEEP
if ((sdio_get_host_pm_caps(sdiodev->func[1]) & MMC_PM_KEEP_POWER) &&
((sdio_get_host_pm_caps(sdiodev->func[1]) & MMC_PM_WAKE_SDIO_IRQ) ||
(sdiodev->pdata && sdiodev->pdata->oob_irq_supported)))
bus_if->wowl_supported = true;
#endif
brcmf_sdiod_change_state(sdiodev, BRCMF_SDIOD_DOWN);
brcmf_dbg(SDIO, "F2 found, calling brcmf_sdiod_probe...\n");
err = brcmf_sdiod_probe(sdiodev);
if (err) {
brcmf_err("F2 error, probe failed %d...\n", err);
goto fail;
}
brcmf_dbg(SDIO, "F2 init completed...\n");
return 0;
fail:
dev_set_drvdata(&func->dev, NULL);
dev_set_drvdata(&sdiodev->func[1]->dev, NULL);
kfree(sdiodev->func[0]);
kfree(sdiodev);
kfree(bus_if);
return err;
}
static void brcmf_ops_sdio_remove(struct sdio_func *func)
{
struct brcmf_bus *bus_if;
struct brcmf_sdio_dev *sdiodev;
brcmf_dbg(SDIO, "Enter\n");
brcmf_dbg(SDIO, "sdio vendor ID: 0x%04x\n", func->vendor);
brcmf_dbg(SDIO, "sdio device ID: 0x%04x\n", func->device);
brcmf_dbg(SDIO, "Function: %d\n", func->num);
if (func->num != 1)
return;
bus_if = dev_get_drvdata(&func->dev);
if (bus_if) {
sdiodev = bus_if->bus_priv.sdio;
brcmf_sdiod_remove(sdiodev);
dev_set_drvdata(&sdiodev->func[1]->dev, NULL);
dev_set_drvdata(&sdiodev->func[2]->dev, NULL);
kfree(bus_if);
kfree(sdiodev->func[0]);
kfree(sdiodev);
}
brcmf_dbg(SDIO, "Exit\n");
}
void brcmf_sdio_wowl_config(struct device *dev, bool enabled)
{
struct brcmf_bus *bus_if = dev_get_drvdata(dev);
struct brcmf_sdio_dev *sdiodev = bus_if->bus_priv.sdio;
brcmf_dbg(SDIO, "Configuring WOWL, enabled=%d\n", enabled);
sdiodev->wowl_enabled = enabled;
}
static int brcmf_ops_sdio_suspend(struct device *dev)
{
struct sdio_func *func;
struct brcmf_bus *bus_if;
struct brcmf_sdio_dev *sdiodev;
mmc_pm_flag_t sdio_flags;
func = container_of(dev, struct sdio_func, dev);
brcmf_dbg(SDIO, "Enter: F%d\n", func->num);
if (func->num != SDIO_FUNC_1)
return 0;
bus_if = dev_get_drvdata(dev);
sdiodev = bus_if->bus_priv.sdio;
brcmf_sdiod_freezer_on(sdiodev);
brcmf_sdio_wd_timer(sdiodev->bus, 0);
sdio_flags = MMC_PM_KEEP_POWER;
if (sdiodev->wowl_enabled) {
if (sdiodev->pdata->oob_irq_supported)
enable_irq_wake(sdiodev->pdata->oob_irq_nr);
else
sdio_flags |= MMC_PM_WAKE_SDIO_IRQ;
}
if (sdio_set_host_pm_flags(sdiodev->func[1], sdio_flags))
brcmf_err("Failed to set pm_flags %x\n", sdio_flags);
return 0;
}
static int brcmf_ops_sdio_resume(struct device *dev)
{
struct brcmf_bus *bus_if = dev_get_drvdata(dev);
struct brcmf_sdio_dev *sdiodev = bus_if->bus_priv.sdio;
struct sdio_func *func = container_of(dev, struct sdio_func, dev);
brcmf_dbg(SDIO, "Enter: F%d\n", func->num);
if (func->num != SDIO_FUNC_2)
return 0;
brcmf_sdiod_freezer_off(sdiodev);
return 0;
}
static int __init brcmf_sdio_pd_probe(struct platform_device *pdev)
{
brcmf_dbg(SDIO, "Enter\n");
brcmfmac_sdio_pdata = dev_get_platdata(&pdev->dev);
if (brcmfmac_sdio_pdata->power_on)
brcmfmac_sdio_pdata->power_on();
return 0;
}
static int brcmf_sdio_pd_remove(struct platform_device *pdev)
{
brcmf_dbg(SDIO, "Enter\n");
if (brcmfmac_sdio_pdata->power_off)
brcmfmac_sdio_pdata->power_off();
sdio_unregister_driver(&brcmf_sdmmc_driver);
return 0;
}
void brcmf_sdio_register(void)
{
int ret;
ret = sdio_register_driver(&brcmf_sdmmc_driver);
if (ret)
brcmf_err("sdio_register_driver failed: %d\n", ret);
}
void brcmf_sdio_exit(void)
{
brcmf_dbg(SDIO, "Enter\n");
if (brcmfmac_sdio_pdata)
platform_driver_unregister(&brcmf_sdio_pd);
else
sdio_unregister_driver(&brcmf_sdmmc_driver);
}
void __init brcmf_sdio_init(void)
{
int ret;
brcmf_dbg(SDIO, "Enter\n");
ret = platform_driver_probe(&brcmf_sdio_pd, brcmf_sdio_pd_probe);
if (ret == -ENODEV)
brcmf_dbg(SDIO, "No platform data available.\n");
}
