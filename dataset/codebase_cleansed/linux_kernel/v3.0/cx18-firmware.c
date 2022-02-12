static int load_cpu_fw_direct(const char *fn, u8 __iomem *mem, struct cx18 *cx)
{
const struct firmware *fw = NULL;
int i, j;
unsigned size;
u32 __iomem *dst = (u32 __iomem *)mem;
const u32 *src;
if (request_firmware(&fw, fn, &cx->pci_dev->dev)) {
CX18_ERR("Unable to open firmware %s\n", fn);
CX18_ERR("Did you put the firmware in the hotplug firmware directory?\n");
return -ENOMEM;
}
src = (const u32 *)fw->data;
for (i = 0; i < fw->size; i += 4096) {
cx18_setup_page(cx, i);
for (j = i; j < fw->size && j < i + 4096; j += 4) {
cx18_raw_writel(cx, *src, dst);
if (cx18_raw_readl(cx, dst) != *src) {
CX18_ERR("Mismatch at offset %x\n", i);
release_firmware(fw);
cx18_setup_page(cx, 0);
return -EIO;
}
dst++;
src++;
}
}
if (!test_bit(CX18_F_I_LOADED_FW, &cx->i_flags))
CX18_INFO("loaded %s firmware (%zd bytes)\n", fn, fw->size);
size = fw->size;
release_firmware(fw);
cx18_setup_page(cx, SCB_OFFSET);
return size;
}
static int load_apu_fw_direct(const char *fn, u8 __iomem *dst, struct cx18 *cx,
u32 *entry_addr)
{
const struct firmware *fw = NULL;
int i, j;
unsigned size;
const u32 *src;
struct cx18_apu_rom_seghdr seghdr;
const u8 *vers;
u32 offset = 0;
u32 apu_version = 0;
int sz;
if (request_firmware(&fw, fn, &cx->pci_dev->dev)) {
CX18_ERR("unable to open firmware %s\n", fn);
CX18_ERR("did you put the firmware in the hotplug firmware directory?\n");
cx18_setup_page(cx, 0);
return -ENOMEM;
}
*entry_addr = 0;
src = (const u32 *)fw->data;
vers = fw->data + sizeof(seghdr);
sz = fw->size;
apu_version = (vers[0] << 24) | (vers[4] << 16) | vers[32];
while (offset + sizeof(seghdr) < fw->size) {
memcpy(&seghdr, src + offset / 4, sizeof(seghdr));
offset += sizeof(seghdr);
if (seghdr.sync1 != APU_ROM_SYNC1 ||
seghdr.sync2 != APU_ROM_SYNC2) {
offset += seghdr.size;
continue;
}
CX18_DEBUG_INFO("load segment %x-%x\n", seghdr.addr,
seghdr.addr + seghdr.size - 1);
if (*entry_addr == 0)
*entry_addr = seghdr.addr;
if (offset + seghdr.size > sz)
break;
for (i = 0; i < seghdr.size; i += 4096) {
cx18_setup_page(cx, seghdr.addr + i);
for (j = i; j < seghdr.size && j < i + 4096; j += 4) {
cx18_raw_writel(cx, src[(offset + j) / 4],
dst + seghdr.addr + j);
if (cx18_raw_readl(cx, dst + seghdr.addr + j)
!= src[(offset + j) / 4]) {
CX18_ERR("Mismatch at offset %x\n",
offset + j);
release_firmware(fw);
cx18_setup_page(cx, 0);
return -EIO;
}
}
}
offset += seghdr.size;
}
if (!test_bit(CX18_F_I_LOADED_FW, &cx->i_flags))
CX18_INFO("loaded %s firmware V%08x (%zd bytes)\n",
fn, apu_version, fw->size);
size = fw->size;
release_firmware(fw);
cx18_setup_page(cx, 0);
return size;
}
void cx18_halt_firmware(struct cx18 *cx)
{
CX18_DEBUG_INFO("Preparing for firmware halt.\n");
cx18_write_reg_expect(cx, 0x000F000F, CX18_PROC_SOFT_RESET,
0x0000000F, 0x000F000F);
cx18_write_reg_expect(cx, 0x00020002, CX18_ADEC_CONTROL,
0x00000002, 0x00020002);
}
void cx18_init_power(struct cx18 *cx, int lowpwr)
{
cx18_write_reg(cx, 0x00000008, CX18_PLL_POWER_DOWN);
cx18_write_reg_expect(cx, 0x00020000, CX18_ADEC_CONTROL,
0x00000000, 0x00020002);
cx18_write_reg(cx, lowpwr ? 0xD : 0x11, CX18_FAST_CLOCK_PLL_INT);
cx18_write_reg(cx, lowpwr ? 0x1EFBF37 : 0x038E3D7,
CX18_FAST_CLOCK_PLL_FRAC);
cx18_write_reg(cx, 2, CX18_FAST_CLOCK_PLL_POST);
cx18_write_reg(cx, 1, CX18_FAST_CLOCK_PLL_PRESCALE);
cx18_write_reg(cx, 4, CX18_FAST_CLOCK_PLL_ADJUST_BANDWIDTH);
cx18_write_reg(cx, lowpwr ? 0xD : 0xC, CX18_SLOW_CLOCK_PLL_INT);
cx18_write_reg(cx, lowpwr ? 0x30C344 : 0x124927F,
CX18_SLOW_CLOCK_PLL_FRAC);
cx18_write_reg(cx, 3, CX18_SLOW_CLOCK_PLL_POST);
cx18_write_reg(cx, 0xF, CX18_MPEG_CLOCK_PLL_INT);
cx18_write_reg(cx, 0x2BE2FE, CX18_MPEG_CLOCK_PLL_FRAC);
cx18_write_reg(cx, 8, CX18_MPEG_CLOCK_PLL_POST);
if (lowpwr) {
cx18_write_reg_expect(cx, 0xFFFF0020, CX18_CLOCK_SELECT1,
0x00000020, 0xFFFFFFFF);
cx18_write_reg_expect(cx, 0xFFFF0004, CX18_CLOCK_SELECT2,
0x00000004, 0xFFFFFFFF);
} else {
cx18_write_reg_expect(cx, 0x00060004, CX18_CLOCK_SELECT1,
0x00000004, 0x00060006);
cx18_write_reg_expect(cx, 0x00060006, CX18_CLOCK_SELECT2,
0x00000006, 0x00060006);
}
cx18_write_reg_expect(cx, 0xFFFF0002, CX18_HALF_CLOCK_SELECT1,
0x00000002, 0xFFFFFFFF);
cx18_write_reg_expect(cx, 0xFFFF0104, CX18_HALF_CLOCK_SELECT2,
0x00000104, 0xFFFFFFFF);
cx18_write_reg_expect(cx, 0xFFFF9026, CX18_CLOCK_ENABLE1,
0x00009026, 0xFFFFFFFF);
cx18_write_reg_expect(cx, 0xFFFF3105, CX18_CLOCK_ENABLE2,
0x00003105, 0xFFFFFFFF);
}
void cx18_init_memory(struct cx18 *cx)
{
cx18_msleep_timeout(10, 0);
cx18_write_reg_expect(cx, 0x00010000, CX18_DDR_SOFT_RESET,
0x00000000, 0x00010001);
cx18_msleep_timeout(10, 0);
cx18_write_reg(cx, cx->card->ddr.chip_config, CX18_DDR_CHIP_CONFIG);
cx18_msleep_timeout(10, 0);
cx18_write_reg(cx, cx->card->ddr.refresh, CX18_DDR_REFRESH);
cx18_write_reg(cx, cx->card->ddr.timing1, CX18_DDR_TIMING1);
cx18_write_reg(cx, cx->card->ddr.timing2, CX18_DDR_TIMING2);
cx18_msleep_timeout(10, 0);
cx18_write_reg(cx, cx->card->ddr.tune_lane, CX18_DDR_TUNE_LANE);
cx18_write_reg(cx, cx->card->ddr.initial_emrs, CX18_DDR_INITIAL_EMRS);
cx18_msleep_timeout(10, 0);
cx18_write_reg_expect(cx, 0x00020000, CX18_DDR_SOFT_RESET,
0x00000000, 0x00020002);
cx18_msleep_timeout(10, 0);
cx18_write_reg(cx, 0x00000010, CX18_DDR_POWER_REG);
cx18_write_reg_expect(cx, 0x00010001, CX18_REG_BUS_TIMEOUT_EN,
0x00000001, 0x00010001);
cx18_write_reg(cx, 0x48, CX18_DDR_MB_PER_ROW_7);
cx18_write_reg(cx, 0xE0000, CX18_DDR_BASE_63_ADDR);
cx18_write_reg(cx, 0x00000101, CX18_WMB_CLIENT02);
cx18_write_reg(cx, 0x00000101, CX18_WMB_CLIENT09);
cx18_write_reg(cx, 0x00000101, CX18_WMB_CLIENT05);
cx18_write_reg(cx, 0x00000101, CX18_WMB_CLIENT06);
cx18_write_reg(cx, 0x00000101, CX18_WMB_CLIENT07);
cx18_write_reg(cx, 0x00000101, CX18_WMB_CLIENT10);
cx18_write_reg(cx, 0x00000101, CX18_WMB_CLIENT12);
cx18_write_reg(cx, 0x00000101, CX18_WMB_CLIENT13);
cx18_write_reg(cx, 0x00000101, CX18_WMB_CLIENT11);
cx18_write_reg(cx, 0x00000101, CX18_WMB_CLIENT14);
}
int cx18_firmware_init(struct cx18 *cx)
{
u32 fw_entry_addr;
int sz, retries;
u32 api_args[MAX_MB_ARGUMENTS];
cx18_write_reg(cx, 0x5, CX18_DSP0_INTERRUPT_MASK);
cx18_write_reg_expect(cx, 0x000F000F, CX18_PROC_SOFT_RESET,
0x0000000F, 0x000F000F);
cx18_msleep_timeout(1, 0);
if ((cx18_read_reg(cx, CX18_PROC_SOFT_RESET) & 8) == 0) {
CX18_ERR("%s: couldn't stop CPU to load firmware\n", __func__);
return -EIO;
}
cx18_sw1_irq_enable(cx, IRQ_CPU_TO_EPU | IRQ_APU_TO_EPU);
cx18_sw2_irq_enable(cx, IRQ_CPU_TO_EPU_ACK | IRQ_APU_TO_EPU_ACK);
sz = load_cpu_fw_direct("v4l-cx23418-cpu.fw", cx->enc_mem, cx);
if (sz <= 0)
return sz;
cx18_init_scb(cx);
fw_entry_addr = 0;
sz = load_apu_fw_direct("v4l-cx23418-apu.fw", cx->enc_mem, cx,
&fw_entry_addr);
if (sz <= 0)
return sz;
cx18_write_reg_expect(cx, 0x00080000, CX18_PROC_SOFT_RESET,
0x00000000, 0x00080008);
for (retries = 0;
retries < 50 && (cx18_read_reg(cx, CX18_PROC_SOFT_RESET) & 1) == 1;
retries++)
cx18_msleep_timeout(10, 0);
cx18_msleep_timeout(200, 0);
if (retries == 50 &&
(cx18_read_reg(cx, CX18_PROC_SOFT_RESET) & 1) == 1) {
CX18_ERR("Could not start the CPU\n");
return -EIO;
}
cx18_sw2_irq_disable_cpu(cx, IRQ_CPU_TO_EPU_ACK | IRQ_APU_TO_EPU_ACK);
sz = cx18_vapi_result(cx, api_args, CX18_CPU_DEBUG_PEEK32, 1, 0);
if (sz < 0)
return sz;
cx18_write_reg_expect(cx, 0x14001400, 0xc78110, 0x00001400, 0x14001400);
return 0;
}
