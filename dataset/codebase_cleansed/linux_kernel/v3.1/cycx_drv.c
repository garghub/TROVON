static int __init cycx_drv_init(void)
{
pr_info("%s v%u.%u %s\n",
fullname, MOD_VERSION, MOD_RELEASE, copyright);
return 0;
}
static void cycx_drv_cleanup(void)
{
}
int cycx_setup(struct cycx_hw *hw, void *cfm, u32 len, unsigned long dpmbase)
{
int err;
if (!get_option_index(cycx_2x_irq_options, hw->irq)) {
pr_err("IRQ %d is invalid!\n", hw->irq);
return -EINVAL;
}
if (!dpmbase) {
pr_err("you must specify the dpm address!\n");
return -EINVAL;
} else if (!get_option_index(cyc2x_dpmbase_options, dpmbase)) {
pr_err("memory address 0x%lX is invalid!\n", dpmbase);
return -EINVAL;
}
hw->dpmbase = ioremap(dpmbase, CYCX_WINDOWSIZE);
hw->dpmsize = CYCX_WINDOWSIZE;
if (!detect_cyc2x(hw->dpmbase)) {
pr_err("adapter Cyclom 2X not found at address 0x%lX!\n",
dpmbase);
return -EINVAL;
}
pr_info("found Cyclom 2X card at address 0x%lX\n", dpmbase);
err = load_cyc2x(hw, cfm, len);
if (err)
cycx_down(hw);
return err;
}
int cycx_down(struct cycx_hw *hw)
{
iounmap(hw->dpmbase);
return 0;
}
static void cycx_inten(struct cycx_hw *hw)
{
writeb(0, hw->dpmbase);
}
void cycx_intr(struct cycx_hw *hw)
{
writew(0, hw->dpmbase + GEN_CYCX_INTR);
}
int cycx_exec(void __iomem *addr)
{
u16 i = 0;
while (readw(addr)) {
udelay(1000);
if (++i > 50)
return -1;
}
return 0;
}
int cycx_peek(struct cycx_hw *hw, u32 addr, void *buf, u32 len)
{
if (len == 1)
*(u8*)buf = readb(hw->dpmbase + addr);
else
memcpy_fromio(buf, hw->dpmbase + addr, len);
return 0;
}
int cycx_poke(struct cycx_hw *hw, u32 addr, void *buf, u32 len)
{
if (len == 1)
writeb(*(u8*)buf, hw->dpmbase + addr);
else
memcpy_toio(hw->dpmbase + addr, buf, len);
return 0;
}
static int memory_exists(void __iomem *addr)
{
int tries = 0;
for (; tries < 3 ; tries++) {
writew(TEST_PATTERN, addr + 0x10);
if (readw(addr + 0x10) == TEST_PATTERN)
if (readw(addr + 0x10) == TEST_PATTERN)
return 1;
msleep_interruptible(1 * 1000);
}
return 0;
}
static void reset_load(void __iomem *addr, u8 *buffer, u32 cnt)
{
void __iomem *pt_code = addr + RESET_OFFSET;
u16 i;
for (i = 0 ; i < cnt ; i++) {
writeb(*buffer++, pt_code++);
}
}
static int buffer_load(void __iomem *addr, u8 *buffer, u32 cnt)
{
memcpy_toio(addr + DATA_OFFSET, buffer, cnt);
writew(GEN_BOOT_DAT, addr + CMD_OFFSET);
return wait_cyc(addr);
}
static void cycx_start(void __iomem *addr)
{
writeb(0xea, addr + 0x30);
writeb(0x00, addr + 0x31);
writeb(0xc4, addr + 0x32);
writeb(0x00, addr + 0x33);
writeb(0x00, addr + 0x34);
writew(GEN_START, addr + CMD_OFFSET);
}
static void cycx_reset_boot(void __iomem *addr, u8 *code, u32 len)
{
void __iomem *pt_start = addr + START_OFFSET;
writeb(0xea, pt_start++);
writeb(0x00, pt_start++);
writeb(0xfc, pt_start++);
writeb(0x00, pt_start++);
writeb(0xf0, pt_start);
reset_load(addr, code, len);
writeb(0, addr + START_CPU);
msleep_interruptible(1 * 1000);
}
static int cycx_data_boot(void __iomem *addr, u8 *code, u32 len)
{
void __iomem *pt_boot_cmd = addr + CMD_OFFSET;
u32 i;
writew(CFM_LOAD_BUFSZ, pt_boot_cmd + sizeof(u16));
writew(GEN_DEFPAR, pt_boot_cmd);
if (wait_cyc(addr) < 0)
return -1;
writew(0, pt_boot_cmd + sizeof(u16));
writew(0x4000, pt_boot_cmd + 2 * sizeof(u16));
writew(GEN_SET_SEG, pt_boot_cmd);
if (wait_cyc(addr) < 0)
return -1;
for (i = 0 ; i < len ; i += CFM_LOAD_BUFSZ)
if (buffer_load(addr, code + i,
min_t(u32, CFM_LOAD_BUFSZ, (len - i))) < 0) {
pr_err("Error !!\n");
return -1;
}
return 0;
}
static int cycx_code_boot(void __iomem *addr, u8 *code, u32 len)
{
void __iomem *pt_boot_cmd = addr + CMD_OFFSET;
u32 i;
writew(CFM_LOAD_BUFSZ, pt_boot_cmd + sizeof(u16));
writew(GEN_DEFPAR, pt_boot_cmd);
if (wait_cyc(addr) < 0)
return -1;
writew(0x0000, pt_boot_cmd + sizeof(u16));
writew(0xc400, pt_boot_cmd + 2 * sizeof(u16));
writew(GEN_SET_SEG, pt_boot_cmd);
if (wait_cyc(addr) < 0)
return -1;
for (i = 0 ; i < len ; i += CFM_LOAD_BUFSZ)
if (buffer_load(addr, code + i,
min_t(u32, CFM_LOAD_BUFSZ, (len - i)))) {
pr_err("Error !!\n");
return -1;
}
return 0;
}
static int load_cyc2x(struct cycx_hw *hw, struct cycx_firmware *cfm, u32 len)
{
int i, j;
struct cycx_fw_header *img_hdr;
u8 *reset_image,
*data_image,
*code_image;
void __iomem *pt_cycld = hw->dpmbase + 0x400;
u16 cksum;
pr_info("firmware signature=\"%s\"\n", cfm->signature);
if (strcmp(cfm->signature, CFM_SIGNATURE)) {
pr_err("load_cyc2x: not Cyclom-2X firmware!\n");
return -EINVAL;
}
pr_info("firmware version=%u\n", cfm->version);
if (cfm->version != CFM_VERSION) {
pr_err("%s: firmware format %u rejected! Expecting %u.\n",
__func__, cfm->version, CFM_VERSION);
return -EINVAL;
}
cksum = checksum((u8*)&cfm->info, sizeof(struct cycx_fw_info) +
cfm->info.codesize);
if (cksum != cfm->checksum) {
pr_err("%s: firmware corrupted!\n", __func__);
pr_err(" cdsize = 0x%x (expected 0x%lx)\n",
len - (int)sizeof(struct cycx_firmware) - 1,
cfm->info.codesize);
pr_err(" chksum = 0x%x (expected 0x%x)\n",
cksum, cfm->checksum);
return -EINVAL;
}
img_hdr = (struct cycx_fw_header *)&cfm->image;
#ifdef FIRMWARE_DEBUG
pr_info("%s: image sizes\n", __func__);
pr_info(" reset=%lu\n", img_hdr->reset_size);
pr_info(" data=%lu\n", img_hdr->data_size);
pr_info(" code=%lu\n", img_hdr->code_size);
#endif
reset_image = ((u8 *)img_hdr) + sizeof(struct cycx_fw_header);
data_image = reset_image + img_hdr->reset_size;
code_image = data_image + img_hdr->data_size;
pr_info("loading firmware %s (ID=%u)...\n",
cfm->descr[0] ? cfm->descr : "unknown firmware",
cfm->info.codeid);
for (i = 0 ; i < 5 ; i++) {
if (!reset_cyc2x(hw->dpmbase)) {
pr_err("dpm problem or board not found\n");
return -EINVAL;
}
cycx_reset_boot(hw->dpmbase, reset_image, img_hdr->reset_size);
writew(GEN_POWER_ON, pt_cycld);
msleep_interruptible(1 * 1000);
for (j = 0 ; j < 3 ; j++)
if (!readw(pt_cycld))
goto reset_loaded;
else
msleep_interruptible(1 * 1000);
}
pr_err("reset not started\n");
return -EINVAL;
reset_loaded:
if (cycx_data_boot(hw->dpmbase, data_image, img_hdr->data_size)) {
pr_err("cannot load data file\n");
return -EINVAL;
}
if (cycx_code_boot(hw->dpmbase, code_image, img_hdr->code_size)) {
pr_err("cannot load code file\n");
return -EINVAL;
}
cycx_bootcfg(hw);
cycx_start(hw->dpmbase);
msleep_interruptible(7 * 1000);
pr_info("firmware loaded!\n");
cycx_inten(hw);
return 0;
}
static void cycx_bootcfg(struct cycx_hw *hw)
{
writeb(FIXED_BUFFERS, hw->dpmbase + CONF_OFFSET);
}
static int detect_cyc2x(void __iomem *addr)
{
reset_cyc2x(addr);
return memory_exists(addr);
}
static int get_option_index(const long *optlist, long optval)
{
int i = 1;
for (; i <= optlist[0]; ++i)
if (optlist[i] == optval)
return i;
return 0;
}
static int reset_cyc2x(void __iomem *addr)
{
writeb(0, addr + RST_ENABLE);
msleep_interruptible(2 * 1000);
writeb(0, addr + RST_DISABLE);
msleep_interruptible(2 * 1000);
return memory_exists(addr);
}
static u16 checksum(u8 *buf, u32 len)
{
u16 crc = 0;
u16 mask, flag;
for (; len; --len, ++buf)
for (mask = 0x80; mask; mask >>= 1) {
flag = (crc & 0x8000);
crc <<= 1;
crc |= ((*buf & mask) ? 1 : 0);
if (flag)
crc ^= 0x1021;
}
return crc;
}
