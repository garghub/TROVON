int mantis_dma_exit(struct mantis_pci *mantis)
{
if (mantis->buf_cpu) {
dprintk(MANTIS_ERROR, 1,
"DMA=0x%lx cpu=0x%p size=%d",
(unsigned long) mantis->buf_dma,
mantis->buf_cpu,
MANTIS_BUF_SIZE);
pci_free_consistent(mantis->pdev, MANTIS_BUF_SIZE,
mantis->buf_cpu, mantis->buf_dma);
mantis->buf_cpu = NULL;
}
if (mantis->risc_cpu) {
dprintk(MANTIS_ERROR, 1,
"RISC=0x%lx cpu=0x%p size=%lx",
(unsigned long) mantis->risc_dma,
mantis->risc_cpu,
MANTIS_RISC_SIZE);
pci_free_consistent(mantis->pdev, MANTIS_RISC_SIZE,
mantis->risc_cpu, mantis->risc_dma);
mantis->risc_cpu = NULL;
}
return 0;
}
static inline int mantis_alloc_buffers(struct mantis_pci *mantis)
{
if (!mantis->buf_cpu) {
mantis->buf_cpu = pci_alloc_consistent(mantis->pdev,
MANTIS_BUF_SIZE,
&mantis->buf_dma);
if (!mantis->buf_cpu) {
dprintk(MANTIS_ERROR, 1,
"DMA buffer allocation failed");
goto err;
}
dprintk(MANTIS_ERROR, 1,
"DMA=0x%lx cpu=0x%p size=%d",
(unsigned long) mantis->buf_dma,
mantis->buf_cpu, MANTIS_BUF_SIZE);
}
if (!mantis->risc_cpu) {
mantis->risc_cpu = pci_alloc_consistent(mantis->pdev,
MANTIS_RISC_SIZE,
&mantis->risc_dma);
if (!mantis->risc_cpu) {
dprintk(MANTIS_ERROR, 1,
"RISC program allocation failed");
mantis_dma_exit(mantis);
goto err;
}
dprintk(MANTIS_ERROR, 1,
"RISC=0x%lx cpu=0x%p size=%lx",
(unsigned long) mantis->risc_dma,
mantis->risc_cpu, MANTIS_RISC_SIZE);
}
return 0;
err:
dprintk(MANTIS_ERROR, 1, "Out of memory (?) .....");
return -ENOMEM;
}
static inline int mantis_calc_lines(struct mantis_pci *mantis)
{
mantis->line_bytes = MANTIS_BLOCK_BYTES;
mantis->line_count = MANTIS_BLOCK_COUNT;
while (mantis->line_bytes > 4095) {
mantis->line_bytes >>= 1;
mantis->line_count <<= 1;
}
dprintk(MANTIS_DEBUG, 1, "Mantis RISC block bytes=[%d], line bytes=[%d], line count=[%d]",
MANTIS_BLOCK_BYTES, mantis->line_bytes, mantis->line_count);
if (mantis->line_count > 255) {
dprintk(MANTIS_ERROR, 1, "Buffer size error");
return -EINVAL;
}
return 0;
}
int mantis_dma_init(struct mantis_pci *mantis)
{
int err = 0;
dprintk(MANTIS_DEBUG, 1, "Mantis DMA init");
if (mantis_alloc_buffers(mantis) < 0) {
dprintk(MANTIS_ERROR, 1, "Error allocating DMA buffer");
mmwrite(0, MANTIS_DMA_CTL);
goto err;
}
err = mantis_calc_lines(mantis);
if (err < 0) {
dprintk(MANTIS_ERROR, 1, "Mantis calc lines failed");
goto err;
}
return 0;
err:
return err;
}
static inline void mantis_risc_program(struct mantis_pci *mantis)
{
u32 buf_pos = 0;
u32 line;
dprintk(MANTIS_DEBUG, 1, "Mantis create RISC program");
RISC_FLUSH();
dprintk(MANTIS_DEBUG, 1, "risc len lines %u, bytes per line %u",
mantis->line_count, mantis->line_bytes);
for (line = 0; line < mantis->line_count; line++) {
dprintk(MANTIS_DEBUG, 1, "RISC PROG line=[%d]", line);
if (!(buf_pos % MANTIS_BLOCK_BYTES)) {
RISC_INSTR(RISC_WRITE |
RISC_IRQ |
RISC_STATUS(((buf_pos / MANTIS_BLOCK_BYTES) +
(MANTIS_BLOCK_COUNT - 1)) %
MANTIS_BLOCK_COUNT) |
mantis->line_bytes);
} else {
RISC_INSTR(RISC_WRITE | mantis->line_bytes);
}
RISC_INSTR(mantis->buf_dma + buf_pos);
buf_pos += mantis->line_bytes;
}
RISC_INSTR(RISC_JUMP);
RISC_INSTR(mantis->risc_dma);
}
void mantis_dma_start(struct mantis_pci *mantis)
{
dprintk(MANTIS_DEBUG, 1, "Mantis Start DMA engine");
mantis_risc_program(mantis);
mmwrite(mantis->risc_dma, MANTIS_RISC_START);
mmwrite(mmread(MANTIS_GPIF_ADDR) | MANTIS_GPIF_HIFRDWRN, MANTIS_GPIF_ADDR);
mmwrite(0, MANTIS_DMA_CTL);
mantis->last_block = mantis->finished_block = 0;
mmwrite(mmread(MANTIS_INT_MASK) | MANTIS_INT_RISCI, MANTIS_INT_MASK);
mmwrite(MANTIS_FIFO_EN | MANTIS_DCAP_EN
| MANTIS_RISC_EN, MANTIS_DMA_CTL);
}
void mantis_dma_stop(struct mantis_pci *mantis)
{
u32 stat = 0, mask = 0;
stat = mmread(MANTIS_INT_STAT);
mask = mmread(MANTIS_INT_MASK);
dprintk(MANTIS_DEBUG, 1, "Mantis Stop DMA engine");
mmwrite((mmread(MANTIS_GPIF_ADDR) & (~(MANTIS_GPIF_HIFRDWRN))), MANTIS_GPIF_ADDR);
mmwrite((mmread(MANTIS_DMA_CTL) & ~(MANTIS_FIFO_EN |
MANTIS_DCAP_EN |
MANTIS_RISC_EN)), MANTIS_DMA_CTL);
mmwrite(mmread(MANTIS_INT_STAT), MANTIS_INT_STAT);
mmwrite(mmread(MANTIS_INT_MASK) & ~(MANTIS_INT_RISCI |
MANTIS_INT_RISCEN), MANTIS_INT_MASK);
}
void mantis_dma_xfer(unsigned long data)
{
struct mantis_pci *mantis = (struct mantis_pci *) data;
struct mantis_hwconfig *config = mantis->hwconfig;
while (mantis->last_block != mantis->finished_block) {
dprintk(MANTIS_DEBUG, 1, "last block=[%d] finished block=[%d]",
mantis->last_block, mantis->finished_block);
(config->ts_size ? dvb_dmx_swfilter_204 : dvb_dmx_swfilter)
(&mantis->demux, &mantis->buf_cpu[mantis->last_block * MANTIS_BLOCK_BYTES], MANTIS_BLOCK_BYTES);
mantis->last_block = (mantis->last_block + 1) % MANTIS_BLOCK_COUNT;
}
}
