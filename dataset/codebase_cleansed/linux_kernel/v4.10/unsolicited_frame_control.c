void sci_unsolicited_frame_control_construct(struct isci_host *ihost)
{
struct sci_unsolicited_frame_control *uf_control = &ihost->uf_control;
struct sci_unsolicited_frame *uf;
dma_addr_t dma = ihost->ufi_dma;
void *virt = ihost->ufi_buf;
int i;
uf_control->headers.physical_address = dma + SCI_UFI_BUF_SIZE;
uf_control->headers.array = virt + SCI_UFI_BUF_SIZE;
uf_control->address_table.physical_address = dma + SCI_UFI_BUF_SIZE + SCI_UFI_HDR_SIZE;
uf_control->address_table.array = virt + SCI_UFI_BUF_SIZE + SCI_UFI_HDR_SIZE;
uf_control->get = 0;
for (i = 0; i < SCU_MAX_UNSOLICITED_FRAMES; i++) {
uf = &uf_control->buffers.array[i];
uf_control->address_table.array[i] = dma;
uf->buffer = virt;
uf->header = &uf_control->headers.array[i];
uf->state = UNSOLICITED_FRAME_EMPTY;
virt += SCU_UNSOLICITED_FRAME_BUFFER_SIZE;
dma += SCU_UNSOLICITED_FRAME_BUFFER_SIZE;
}
}
enum sci_status sci_unsolicited_frame_control_get_header(struct sci_unsolicited_frame_control *uf_control,
u32 frame_index,
void **frame_header)
{
if (frame_index < SCU_MAX_UNSOLICITED_FRAMES) {
*frame_header = &uf_control->buffers.array[frame_index].header->data;
return SCI_SUCCESS;
}
return SCI_FAILURE_INVALID_PARAMETER_VALUE;
}
enum sci_status sci_unsolicited_frame_control_get_buffer(struct sci_unsolicited_frame_control *uf_control,
u32 frame_index,
void **frame_buffer)
{
if (frame_index < SCU_MAX_UNSOLICITED_FRAMES) {
*frame_buffer = uf_control->buffers.array[frame_index].buffer;
return SCI_SUCCESS;
}
return SCI_FAILURE_INVALID_PARAMETER_VALUE;
}
bool sci_unsolicited_frame_control_release_frame(struct sci_unsolicited_frame_control *uf_control,
u32 frame_index)
{
u32 frame_get;
u32 frame_cycle;
frame_get = uf_control->get & (SCU_MAX_UNSOLICITED_FRAMES - 1);
frame_cycle = uf_control->get & SCU_MAX_UNSOLICITED_FRAMES;
while (lower_32_bits(uf_control->address_table.array[frame_get]) == 0 &&
upper_32_bits(uf_control->address_table.array[frame_get]) == 0 &&
frame_get < SCU_MAX_UNSOLICITED_FRAMES)
frame_get++;
BUG_ON(frame_get >= SCU_MAX_UNSOLICITED_FRAMES);
if (frame_index >= SCU_MAX_UNSOLICITED_FRAMES)
return false;
uf_control->buffers.array[frame_index].state = UNSOLICITED_FRAME_RELEASED;
if (frame_get != frame_index) {
return false;
}
while (uf_control->buffers.array[frame_get].state == UNSOLICITED_FRAME_RELEASED) {
uf_control->buffers.array[frame_get].state = UNSOLICITED_FRAME_EMPTY;
if (frame_get+1 == SCU_MAX_UNSOLICITED_FRAMES-1) {
frame_cycle ^= SCU_MAX_UNSOLICITED_FRAMES;
frame_get = 0;
} else
frame_get++;
}
uf_control->get = SCU_UFQGP_GEN_BIT(ENABLE_BIT) | frame_cycle | frame_get;
return true;
}
