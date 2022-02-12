static __le32 *cx88_risc_field(__le32 *rp, struct scatterlist *sglist,
unsigned int offset, u32 sync_line,
unsigned int bpl, unsigned int padding,
unsigned int lines, unsigned int lpi, bool jump)
{
struct scatterlist *sg;
unsigned int line, todo, sol;
if (jump) {
(*rp++) = cpu_to_le32(RISC_JUMP);
(*rp++) = 0;
}
if (sync_line != NO_SYNC_LINE)
*(rp++) = cpu_to_le32(RISC_RESYNC | sync_line);
sg = sglist;
for (line = 0; line < lines; line++) {
while (offset && offset >= sg_dma_len(sg)) {
offset -= sg_dma_len(sg);
sg = sg_next(sg);
}
if (lpi && line > 0 && !(line % lpi))
sol = RISC_SOL | RISC_IRQ1 | RISC_CNT_INC;
else
sol = RISC_SOL;
if (bpl <= sg_dma_len(sg) - offset) {
*(rp++) = cpu_to_le32(RISC_WRITE | sol |
RISC_EOL | bpl);
*(rp++) = cpu_to_le32(sg_dma_address(sg) + offset);
offset += bpl;
} else {
todo = bpl;
*(rp++) = cpu_to_le32(RISC_WRITE | sol |
(sg_dma_len(sg) - offset));
*(rp++) = cpu_to_le32(sg_dma_address(sg) + offset);
todo -= (sg_dma_len(sg) - offset);
offset = 0;
sg = sg_next(sg);
while (todo > sg_dma_len(sg)) {
*(rp++) = cpu_to_le32(RISC_WRITE |
sg_dma_len(sg));
*(rp++) = cpu_to_le32(sg_dma_address(sg));
todo -= sg_dma_len(sg);
sg = sg_next(sg);
}
*(rp++) = cpu_to_le32(RISC_WRITE | RISC_EOL | todo);
*(rp++) = cpu_to_le32(sg_dma_address(sg));
offset += todo;
}
offset += padding;
}
return rp;
}
int cx88_risc_buffer(struct pci_dev *pci, struct cx88_riscmem *risc,
struct scatterlist *sglist,
unsigned int top_offset, unsigned int bottom_offset,
unsigned int bpl, unsigned int padding, unsigned int lines)
{
u32 instructions, fields;
__le32 *rp;
fields = 0;
if (top_offset != UNSET)
fields++;
if (bottom_offset != UNSET)
fields++;
instructions = fields * (1 + ((bpl + padding) * lines) /
PAGE_SIZE + lines);
instructions += 4;
risc->size = instructions * 8;
risc->dma = 0;
risc->cpu = pci_zalloc_consistent(pci, risc->size, &risc->dma);
if (!risc->cpu)
return -ENOMEM;
rp = risc->cpu;
if (top_offset != UNSET)
rp = cx88_risc_field(rp, sglist, top_offset, 0,
bpl, padding, lines, 0, true);
if (bottom_offset != UNSET)
rp = cx88_risc_field(rp, sglist, bottom_offset, 0x200,
bpl, padding, lines, 0,
top_offset == UNSET);
risc->jmp = rp;
WARN_ON((risc->jmp - risc->cpu + 2) * sizeof(*risc->cpu) > risc->size);
return 0;
}
int cx88_risc_databuffer(struct pci_dev *pci, struct cx88_riscmem *risc,
struct scatterlist *sglist, unsigned int bpl,
unsigned int lines, unsigned int lpi)
{
u32 instructions;
__le32 *rp;
instructions = 1 + (bpl * lines) / PAGE_SIZE + lines;
instructions += 3;
risc->size = instructions * 8;
risc->dma = 0;
risc->cpu = pci_zalloc_consistent(pci, risc->size, &risc->dma);
if (!risc->cpu)
return -ENOMEM;
rp = risc->cpu;
rp = cx88_risc_field(rp, sglist, 0, NO_SYNC_LINE, bpl, 0,
lines, lpi, !lpi);
risc->jmp = rp;
WARN_ON((risc->jmp - risc->cpu + 2) * sizeof(*risc->cpu) > risc->size);
return 0;
}
int cx88_sram_channel_setup(struct cx88_core *core,
const struct sram_channel *ch,
unsigned int bpl, u32 risc)
{
unsigned int i, lines;
u32 cdt;
bpl = (bpl + 7) & ~7;
cdt = ch->cdt;
lines = ch->fifo_size / bpl;
if (lines > 6)
lines = 6;
WARN_ON(lines < 2);
for (i = 0; i < lines; i++)
cx_write(cdt + 16 * i, ch->fifo_start + bpl * i);
cx_write(ch->cmds_start + 0, risc);
cx_write(ch->cmds_start + 4, cdt);
cx_write(ch->cmds_start + 8, (lines * 16) >> 3);
cx_write(ch->cmds_start + 12, ch->ctrl_start);
cx_write(ch->cmds_start + 16, 64 >> 2);
for (i = 20; i < 64; i += 4)
cx_write(ch->cmds_start + i, 0);
cx_write(ch->ptr1_reg, ch->fifo_start);
cx_write(ch->ptr2_reg, cdt);
cx_write(ch->cnt1_reg, (bpl >> 3) - 1);
cx_write(ch->cnt2_reg, (lines * 16) >> 3);
dprintk(2, "sram setup %s: bpl=%d lines=%d\n", ch->name, bpl, lines);
return 0;
}
static int cx88_risc_decode(u32 risc)
{
static const char * const instr[16] = {
[RISC_SYNC >> 28] = "sync",
[RISC_WRITE >> 28] = "write",
[RISC_WRITEC >> 28] = "writec",
[RISC_READ >> 28] = "read",
[RISC_READC >> 28] = "readc",
[RISC_JUMP >> 28] = "jump",
[RISC_SKIP >> 28] = "skip",
[RISC_WRITERM >> 28] = "writerm",
[RISC_WRITECM >> 28] = "writecm",
[RISC_WRITECR >> 28] = "writecr",
};
static int const incr[16] = {
[RISC_WRITE >> 28] = 2,
[RISC_JUMP >> 28] = 2,
[RISC_WRITERM >> 28] = 3,
[RISC_WRITECM >> 28] = 3,
[RISC_WRITECR >> 28] = 4,
};
static const char * const bits[] = {
"12", "13", "14", "resync",
"cnt0", "cnt1", "18", "19",
"20", "21", "22", "23",
"irq1", "irq2", "eol", "sol",
};
int i;
dprintk0("0x%08x [ %s", risc,
instr[risc >> 28] ? instr[risc >> 28] : "INVALID");
for (i = ARRAY_SIZE(bits) - 1; i >= 0; i--)
if (risc & (1 << (i + 12)))
pr_cont(" %s", bits[i]);
pr_cont(" count=%d ]\n", risc & 0xfff);
return incr[risc >> 28] ? incr[risc >> 28] : 1;
}
void cx88_sram_channel_dump(struct cx88_core *core,
const struct sram_channel *ch)
{
static const char * const name[] = {
"initial risc",
"cdt base",
"cdt size",
"iq base",
"iq size",
"risc pc",
"iq wr ptr",
"iq rd ptr",
"cdt current",
"pci target",
"line / byte",
};
u32 risc;
unsigned int i, j, n;
dprintk0("%s - dma channel status dump\n", ch->name);
for (i = 0; i < ARRAY_SIZE(name); i++)
dprintk0(" cmds: %-12s: 0x%08x\n",
name[i], cx_read(ch->cmds_start + 4 * i));
for (n = 1, i = 0; i < 4; i++) {
risc = cx_read(ch->cmds_start + 4 * (i + 11));
pr_cont(" risc%d: ", i);
if (--n)
pr_cont("0x%08x [ arg #%d ]\n", risc, n);
else
n = cx88_risc_decode(risc);
}
for (i = 0; i < 16; i += n) {
risc = cx_read(ch->ctrl_start + 4 * i);
dprintk0(" iq %x: ", i);
n = cx88_risc_decode(risc);
for (j = 1; j < n; j++) {
risc = cx_read(ch->ctrl_start + 4 * (i + j));
pr_cont(" iq %x: 0x%08x [ arg #%d ]\n",
i + j, risc, j);
}
}
dprintk0("fifo: 0x%08x -> 0x%x\n",
ch->fifo_start, ch->fifo_start + ch->fifo_size);
dprintk0("ctrl: 0x%08x -> 0x%x\n",
ch->ctrl_start, ch->ctrl_start + 6 * 16);
dprintk0(" ptr1_reg: 0x%08x\n", cx_read(ch->ptr1_reg));
dprintk0(" ptr2_reg: 0x%08x\n", cx_read(ch->ptr2_reg));
dprintk0(" cnt1_reg: 0x%08x\n", cx_read(ch->cnt1_reg));
dprintk0(" cnt2_reg: 0x%08x\n", cx_read(ch->cnt2_reg));
}
void cx88_print_irqbits(const char *tag, const char *strings[],
int len, u32 bits, u32 mask)
{
unsigned int i;
dprintk0("%s [0x%x]", tag, bits);
for (i = 0; i < len; i++) {
if (!(bits & (1 << i)))
continue;
if (strings[i])
pr_cont(" %s", strings[i]);
else
pr_cont(" %d", i);
if (!(mask & (1 << i)))
continue;
pr_cont("*");
}
pr_cont("\n");
}
int cx88_core_irq(struct cx88_core *core, u32 status)
{
int handled = 0;
if (status & PCI_INT_IR_SMPINT) {
cx88_ir_irq(core);
handled++;
}
if (!handled)
cx88_print_irqbits("irq pci",
cx88_pci_irqs, ARRAY_SIZE(cx88_pci_irqs),
status, core->pci_irqmask);
return handled;
}
void cx88_wakeup(struct cx88_core *core,
struct cx88_dmaqueue *q, u32 count)
{
struct cx88_buffer *buf;
buf = list_entry(q->active.next,
struct cx88_buffer, list);
buf->vb.vb2_buf.timestamp = ktime_get_ns();
buf->vb.field = core->field;
buf->vb.sequence = q->count++;
list_del(&buf->list);
vb2_buffer_done(&buf->vb.vb2_buf, VB2_BUF_STATE_DONE);
}
void cx88_shutdown(struct cx88_core *core)
{
cx_write(MO_DEV_CNTRL2, 0);
cx_write(MO_VID_DMACNTRL, 0x0);
cx_write(MO_AUD_DMACNTRL, 0x0);
cx_write(MO_TS_DMACNTRL, 0x0);
cx_write(MO_VIP_DMACNTRL, 0x0);
cx_write(MO_GPHST_DMACNTRL, 0x0);
cx_write(MO_PCI_INTMSK, 0x0);
cx_write(MO_VID_INTMSK, 0x0);
cx_write(MO_AUD_INTMSK, 0x0);
cx_write(MO_TS_INTMSK, 0x0);
cx_write(MO_VIP_INTMSK, 0x0);
cx_write(MO_GPHST_INTMSK, 0x0);
cx_write(VID_CAPTURE_CONTROL, 0);
}
int cx88_reset(struct cx88_core *core)
{
dprintk(1, "");
cx88_shutdown(core);
cx_write(MO_VID_INTSTAT, 0xFFFFFFFF);
cx_write(MO_PCI_INTSTAT, 0xFFFFFFFF);
cx_write(MO_INT1_STAT, 0xFFFFFFFF);
msleep(100);
cx88_sram_channel_setup(core, &cx88_sram_channels[SRAM_CH21],
720 * 4, 0);
cx88_sram_channel_setup(core, &cx88_sram_channels[SRAM_CH22], 128, 0);
cx88_sram_channel_setup(core, &cx88_sram_channels[SRAM_CH23], 128, 0);
cx88_sram_channel_setup(core, &cx88_sram_channels[SRAM_CH24], 128, 0);
cx88_sram_channel_setup(core, &cx88_sram_channels[SRAM_CH25], 128, 0);
cx88_sram_channel_setup(core, &cx88_sram_channels[SRAM_CH26], 128, 0);
cx88_sram_channel_setup(core, &cx88_sram_channels[SRAM_CH28],
188 * 4, 0);
cx88_sram_channel_setup(core, &cx88_sram_channels[SRAM_CH27], 128, 0);
cx_write(MO_INPUT_FORMAT, ((1 << 13) |
(1 << 12) |
(1 << 11) |
(0 << 10) |
(0 << 9) |
(7)));
cx_andor(MO_COLOR_CTRL, 0x4000, 0x4000);
cx_write(MO_PDMA_STHRSH, 0x0807);
cx_write(MO_PDMA_DTHRSH, 0x0807);
cx_write(MO_AGC_SYNC_TIP1, 0x0380000F);
cx_write(MO_AGC_BACK_VBI, 0x00E00555);
cx_write(MO_VID_INTSTAT, 0xFFFFFFFF);
cx_write(MO_PCI_INTSTAT, 0xFFFFFFFF);
cx_write(MO_INT1_STAT, 0xFFFFFFFF);
cx_write(MO_SRST_IO, 0);
usleep_range(10000, 20000);
cx_write(MO_SRST_IO, 1);
return 0;
}
static inline unsigned int norm_swidth(v4l2_std_id norm)
{
return (norm & (V4L2_STD_MN & ~V4L2_STD_PAL_Nc)) ? 754 : 922;
}
static inline unsigned int norm_hdelay(v4l2_std_id norm)
{
return (norm & (V4L2_STD_MN & ~V4L2_STD_PAL_Nc)) ? 135 : 186;
}
static inline unsigned int norm_vdelay(v4l2_std_id norm)
{
return (norm & V4L2_STD_625_50) ? 0x24 : 0x18;
}
static inline unsigned int norm_fsc8(v4l2_std_id norm)
{
if (norm & V4L2_STD_PAL_M)
return 28604892;
if (norm & (V4L2_STD_PAL_Nc))
return 28656448;
if (norm & V4L2_STD_NTSC)
return 28636360;
return 35468950;
}
static inline unsigned int norm_htotal(v4l2_std_id norm)
{
unsigned int fsc4 = norm_fsc8(norm) / 2;
return (norm & V4L2_STD_625_50) ?
((fsc4 + 312) / 625 + 12) / 25 :
((fsc4 + 262) / 525 * 1001 + 15000) / 30000;
}
static inline unsigned int norm_vbipack(v4l2_std_id norm)
{
return (norm & V4L2_STD_625_50) ? 511 : 400;
}
int cx88_set_scale(struct cx88_core *core, unsigned int width,
unsigned int height, enum v4l2_field field)
{
unsigned int swidth = norm_swidth(core->tvnorm);
unsigned int sheight = norm_maxh(core->tvnorm);
u32 value;
dprintk(1, "set_scale: %dx%d [%s%s,%s]\n", width, height,
V4L2_FIELD_HAS_TOP(field) ? "T" : "",
V4L2_FIELD_HAS_BOTTOM(field) ? "B" : "",
v4l2_norm_to_name(core->tvnorm));
if (!V4L2_FIELD_HAS_BOTH(field))
height *= 2;
value = (width * norm_hdelay(core->tvnorm)) / swidth;
value &= 0x3fe;
cx_write(MO_HDELAY_EVEN, value);
cx_write(MO_HDELAY_ODD, value);
dprintk(1, "set_scale: hdelay 0x%04x (width %d)\n", value, swidth);
value = (swidth * 4096 / width) - 4096;
cx_write(MO_HSCALE_EVEN, value);
cx_write(MO_HSCALE_ODD, value);
dprintk(1, "set_scale: hscale 0x%04x\n", value);
cx_write(MO_HACTIVE_EVEN, width);
cx_write(MO_HACTIVE_ODD, width);
dprintk(1, "set_scale: hactive 0x%04x\n", width);
cx_write(MO_VDELAY_EVEN, norm_vdelay(core->tvnorm));
cx_write(MO_VDELAY_ODD, norm_vdelay(core->tvnorm));
dprintk(1, "set_scale: vdelay 0x%04x\n", norm_vdelay(core->tvnorm));
value = (0x10000 - (sheight * 512 / height - 512)) & 0x1fff;
cx_write(MO_VSCALE_EVEN, value);
cx_write(MO_VSCALE_ODD, value);
dprintk(1, "set_scale: vscale 0x%04x\n", value);
cx_write(MO_VACTIVE_EVEN, sheight);
cx_write(MO_VACTIVE_ODD, sheight);
dprintk(1, "set_scale: vactive 0x%04x\n", sheight);
value = 0;
value |= (1 << 19);
if (core->tvnorm & V4L2_STD_SECAM) {
value |= (1 << 15);
value |= (1 << 16);
}
if (INPUT(core->input).type == CX88_VMUX_SVIDEO)
value |= (1 << 13) | (1 << 5);
if (field == V4L2_FIELD_INTERLACED)
value |= (1 << 3);
if (width < 385)
value |= (1 << 0);
if (width < 193)
value |= (1 << 1);
if (nocomb)
value |= (3 << 5);
cx_andor(MO_FILTER_EVEN, 0x7ffc7f, value);
cx_andor(MO_FILTER_ODD, 0x7ffc7f, value);
dprintk(1, "set_scale: filter 0x%04x\n", value);
return 0;
}
static int set_pll(struct cx88_core *core, int prescale, u32 ofreq)
{
static const u32 pre[] = { 0, 0, 0, 3, 2, 1 };
u64 pll;
u32 reg;
int i;
if (prescale < 2)
prescale = 2;
if (prescale > 5)
prescale = 5;
pll = ofreq * 8 * prescale * (u64)(1 << 20);
do_div(pll, xtal);
reg = (pll & 0x3ffffff) | (pre[prescale] << 26);
if (((reg >> 20) & 0x3f) < 14) {
pr_err("pll out of range\n");
return -1;
}
dprintk(1, "set_pll: MO_PLL_REG 0x%08x [old=0x%08x,freq=%d]\n",
reg, cx_read(MO_PLL_REG), ofreq);
cx_write(MO_PLL_REG, reg);
for (i = 0; i < 100; i++) {
reg = cx_read(MO_DEVICE_STATUS);
if (reg & (1 << 2)) {
dprintk(1, "pll locked [pre=%d,ofreq=%d]\n",
prescale, ofreq);
return 0;
}
dprintk(1, "pll not locked yet, waiting ...\n");
usleep_range(10000, 20000);
}
dprintk(1, "pll NOT locked [pre=%d,ofreq=%d]\n", prescale, ofreq);
return -1;
}
int cx88_start_audio_dma(struct cx88_core *core)
{
int bpl = cx88_sram_channels[SRAM_CH25].fifo_size / 4;
int rds_bpl = cx88_sram_channels[SRAM_CH27].fifo_size / AUD_RDS_LINES;
if (cx_read(MO_AUD_DMACNTRL) & 0x10)
return 0;
cx88_sram_channel_setup(core, &cx88_sram_channels[SRAM_CH25], bpl, 0);
cx88_sram_channel_setup(core, &cx88_sram_channels[SRAM_CH26], bpl, 0);
cx88_sram_channel_setup(core, &cx88_sram_channels[SRAM_CH27],
rds_bpl, 0);
cx_write(MO_AUDD_LNGTH, bpl);
cx_write(MO_AUDR_LNGTH, rds_bpl);
cx_write(MO_AUD_DMACNTRL, 0x0007);
return 0;
}
int cx88_stop_audio_dma(struct cx88_core *core)
{
if (cx_read(MO_AUD_DMACNTRL) & 0x10)
return 0;
cx_write(MO_AUD_DMACNTRL, 0x0000);
return 0;
}
static int set_tvaudio(struct cx88_core *core)
{
v4l2_std_id norm = core->tvnorm;
if (INPUT(core->input).type != CX88_VMUX_TELEVISION &&
INPUT(core->input).type != CX88_VMUX_CABLE)
return 0;
if (V4L2_STD_PAL_BG & norm) {
core->tvaudio = WW_BG;
} else if (V4L2_STD_PAL_DK & norm) {
core->tvaudio = WW_DK;
} else if (V4L2_STD_PAL_I & norm) {
core->tvaudio = WW_I;
} else if (V4L2_STD_SECAM_L & norm) {
core->tvaudio = WW_L;
} else if ((V4L2_STD_SECAM_B | V4L2_STD_SECAM_G | V4L2_STD_SECAM_H) &
norm) {
core->tvaudio = WW_BG;
} else if (V4L2_STD_SECAM_DK & norm) {
core->tvaudio = WW_DK;
} else if ((V4L2_STD_NTSC_M & norm) ||
(V4L2_STD_PAL_M & norm)) {
core->tvaudio = WW_BTSC;
} else if (V4L2_STD_NTSC_M_JP & norm) {
core->tvaudio = WW_EIAJ;
} else {
pr_info("tvaudio support needs work for this tv norm [%s], sorry\n",
v4l2_norm_to_name(core->tvnorm));
core->tvaudio = WW_NONE;
return 0;
}
cx_andor(MO_AFECFG_IO, 0x1f, 0x0);
cx88_set_tvaudio(core);
cx88_start_audio_dma(core);
return 0;
}
int cx88_set_tvnorm(struct cx88_core *core, v4l2_std_id norm)
{
u32 fsc8;
u32 adc_clock;
u32 vdec_clock;
u32 step_db, step_dr;
u64 tmp64;
u32 bdelay, agcdelay, htotal;
u32 cxiformat, cxoformat;
if (norm == core->tvnorm)
return 0;
if (core->v4ldev && (vb2_is_busy(&core->v4ldev->vb2_vidq) ||
vb2_is_busy(&core->v4ldev->vb2_vbiq)))
return -EBUSY;
if (core->dvbdev && vb2_is_busy(&core->dvbdev->vb2_mpegq))
return -EBUSY;
core->tvnorm = norm;
fsc8 = norm_fsc8(norm);
adc_clock = xtal;
vdec_clock = fsc8;
step_db = fsc8;
step_dr = fsc8;
if (norm & V4L2_STD_NTSC_M_JP) {
cxiformat = VideoFormatNTSCJapan;
cxoformat = 0x181f0008;
} else if (norm & V4L2_STD_NTSC_443) {
cxiformat = VideoFormatNTSC443;
cxoformat = 0x181f0008;
} else if (norm & V4L2_STD_PAL_M) {
cxiformat = VideoFormatPALM;
cxoformat = 0x1c1f0008;
} else if (norm & V4L2_STD_PAL_N) {
cxiformat = VideoFormatPALN;
cxoformat = 0x1c1f0008;
} else if (norm & V4L2_STD_PAL_Nc) {
cxiformat = VideoFormatPALNC;
cxoformat = 0x1c1f0008;
} else if (norm & V4L2_STD_PAL_60) {
cxiformat = VideoFormatPAL60;
cxoformat = 0x181f0008;
} else if (norm & V4L2_STD_NTSC) {
cxiformat = VideoFormatNTSC;
cxoformat = 0x181f0008;
} else if (norm & V4L2_STD_SECAM) {
step_db = 4250000 * 8;
step_dr = 4406250 * 8;
cxiformat = VideoFormatSECAM;
cxoformat = 0x181f0008;
} else {
cxiformat = VideoFormatPAL;
cxoformat = 0x181f0008;
}
dprintk(1, "set_tvnorm: \"%s\" fsc8=%d adc=%d vdec=%d db/dr=%d/%d\n",
v4l2_norm_to_name(core->tvnorm), fsc8, adc_clock, vdec_clock,
step_db, step_dr);
set_pll(core, 2, vdec_clock);
dprintk(1, "set_tvnorm: MO_INPUT_FORMAT 0x%08x [old=0x%08x]\n",
cxiformat, cx_read(MO_INPUT_FORMAT) & 0x0f);
cx_andor(MO_INPUT_FORMAT, 0x40f,
norm & V4L2_STD_SECAM ? cxiformat : cxiformat | 0x400);
dprintk(1, "set_tvnorm: MO_OUTPUT_FORMAT 0x%08x [old=0x%08x]\n",
cxoformat, cx_read(MO_OUTPUT_FORMAT));
cx_write(MO_OUTPUT_FORMAT, cxoformat);
tmp64 = adc_clock * (u64)(1 << 17);
do_div(tmp64, vdec_clock);
dprintk(1, "set_tvnorm: MO_SCONV_REG 0x%08x [old=0x%08x]\n",
(u32)tmp64, cx_read(MO_SCONV_REG));
cx_write(MO_SCONV_REG, (u32)tmp64);
tmp64 = step_db * (u64)(1 << 22);
do_div(tmp64, vdec_clock);
dprintk(1, "set_tvnorm: MO_SUB_STEP 0x%08x [old=0x%08x]\n",
(u32)tmp64, cx_read(MO_SUB_STEP));
cx_write(MO_SUB_STEP, (u32)tmp64);
tmp64 = step_dr * (u64)(1 << 22);
do_div(tmp64, vdec_clock);
dprintk(1, "set_tvnorm: MO_SUB_STEP_DR 0x%08x [old=0x%08x]\n",
(u32)tmp64, cx_read(MO_SUB_STEP_DR));
cx_write(MO_SUB_STEP_DR, (u32)tmp64);
bdelay = vdec_clock * 65 / 20000000 + 21;
agcdelay = vdec_clock * 68 / 20000000 + 15;
dprintk(1,
"set_tvnorm: MO_AGC_BURST 0x%08x [old=0x%08x,bdelay=%d,agcdelay=%d]\n",
(bdelay << 8) | agcdelay, cx_read(MO_AGC_BURST),
bdelay, agcdelay);
cx_write(MO_AGC_BURST, (bdelay << 8) | agcdelay);
tmp64 = norm_htotal(norm) * (u64)vdec_clock;
do_div(tmp64, fsc8);
htotal = (u32)tmp64;
dprintk(1,
"set_tvnorm: MO_HTOTAL 0x%08x [old=0x%08x,htotal=%d]\n",
htotal, cx_read(MO_HTOTAL), (u32)tmp64);
cx_andor(MO_HTOTAL, 0x07ff, htotal);
cx_write(MO_VBI_PACKET, (10 << 11) | norm_vbipack(norm));
cx88_set_scale(core, 320, 240, V4L2_FIELD_INTERLACED);
set_tvaudio(core);
call_all(core, video, s_std, norm);
v4l2_ctrl_grab(core->chroma_agc, cxiformat == VideoFormatSECAM);
return 0;
}
void cx88_vdev_init(struct cx88_core *core,
struct pci_dev *pci,
struct video_device *vfd,
const struct video_device *template_,
const char *type)
{
*vfd = *template_;
vfd->v4l2_dev = &core->v4l2_dev;
vfd->dev_parent = &pci->dev;
vfd->release = video_device_release_empty;
vfd->lock = &core->lock;
snprintf(vfd->name, sizeof(vfd->name), "%s %s (%s)",
core->name, type, core->board.name);
}
struct cx88_core *cx88_core_get(struct pci_dev *pci)
{
struct cx88_core *core;
mutex_lock(&devlist);
list_for_each_entry(core, &cx88_devlist, devlist) {
if (pci->bus->number != core->pci_bus)
continue;
if (PCI_SLOT(pci->devfn) != core->pci_slot)
continue;
if (cx88_get_resources(core, pci) != 0) {
mutex_unlock(&devlist);
return NULL;
}
atomic_inc(&core->refcount);
mutex_unlock(&devlist);
return core;
}
core = cx88_core_create(pci, cx88_devcount);
if (core) {
cx88_devcount++;
list_add_tail(&core->devlist, &cx88_devlist);
}
mutex_unlock(&devlist);
return core;
}
void cx88_core_put(struct cx88_core *core, struct pci_dev *pci)
{
release_mem_region(pci_resource_start(pci, 0),
pci_resource_len(pci, 0));
if (!atomic_dec_and_test(&core->refcount))
return;
mutex_lock(&devlist);
cx88_ir_fini(core);
if (core->i2c_rc == 0) {
if (core->i2c_rtc)
i2c_unregister_device(core->i2c_rtc);
i2c_del_adapter(&core->i2c_adap);
}
list_del(&core->devlist);
iounmap(core->lmmio);
cx88_devcount--;
mutex_unlock(&devlist);
v4l2_ctrl_handler_free(&core->video_hdl);
v4l2_ctrl_handler_free(&core->audio_hdl);
v4l2_device_unregister(&core->v4l2_dev);
kfree(core);
}
