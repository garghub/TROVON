static __le32 *tw68_risc_field(__le32 *rp, struct scatterlist *sglist,
unsigned int offset, u32 sync_line,
unsigned int bpl, unsigned int padding,
unsigned int lines, bool jump)
{
struct scatterlist *sg;
unsigned int line, todo, done;
if (jump) {
*(rp++) = cpu_to_le32(RISC_JUMP);
*(rp++) = 0;
}
if (sync_line == 1)
*(rp++) = cpu_to_le32(RISC_SYNCO);
else
*(rp++) = cpu_to_le32(RISC_SYNCE);
*(rp++) = 0;
sg = sglist;
for (line = 0; line < lines; line++) {
while (offset && offset >= sg_dma_len(sg)) {
offset -= sg_dma_len(sg);
sg = sg_next(sg);
}
if (bpl <= sg_dma_len(sg) - offset) {
*(rp++) = cpu_to_le32(RISC_LINESTART |
bpl);
*(rp++) = cpu_to_le32(sg_dma_address(sg) + offset);
offset += bpl;
} else {
todo = bpl;
done = (sg_dma_len(sg) - offset);
*(rp++) = cpu_to_le32(RISC_LINESTART |
(7 << 24) |
done);
*(rp++) = cpu_to_le32(sg_dma_address(sg) + offset);
todo -= done;
sg = sg_next(sg);
while (todo > sg_dma_len(sg)) {
*(rp++) = cpu_to_le32(RISC_INLINE |
(done << 12) |
sg_dma_len(sg));
*(rp++) = cpu_to_le32(sg_dma_address(sg));
todo -= sg_dma_len(sg);
sg = sg_next(sg);
done += sg_dma_len(sg);
}
if (todo) {
*(rp++) = cpu_to_le32(RISC_INLINE |
(done << 12) |
todo);
*(rp++) = cpu_to_le32(sg_dma_address(sg));
}
offset = todo;
}
offset += padding;
}
return rp;
}
int tw68_risc_buffer(struct pci_dev *pci,
struct tw68_buf *buf,
struct scatterlist *sglist,
unsigned int top_offset,
unsigned int bottom_offset,
unsigned int bpl,
unsigned int padding,
unsigned int lines)
{
u32 instructions, fields;
__le32 *rp;
fields = 0;
if (UNSET != top_offset)
fields++;
if (UNSET != bottom_offset)
fields++;
instructions = fields * (1 + (((bpl + padding) * lines) /
PAGE_SIZE) + lines) + 4;
buf->size = instructions * 8;
buf->cpu = pci_alloc_consistent(pci, buf->size, &buf->dma);
if (buf->cpu == NULL)
return -ENOMEM;
rp = buf->cpu;
if (UNSET != top_offset)
rp = tw68_risc_field(rp, sglist, top_offset, 1,
bpl, padding, lines, true);
if (UNSET != bottom_offset)
rp = tw68_risc_field(rp, sglist, bottom_offset, 2,
bpl, padding, lines, top_offset == UNSET);
buf->jmp = rp;
buf->cpu[1] = cpu_to_le32(buf->dma + 8);
BUG_ON((buf->jmp - buf->cpu + 2) * sizeof(buf->cpu[0]) > buf->size);
return 0;
}
