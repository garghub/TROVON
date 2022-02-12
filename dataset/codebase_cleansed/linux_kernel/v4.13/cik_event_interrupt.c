static bool cik_event_interrupt_isr(struct kfd_dev *dev,
const uint32_t *ih_ring_entry)
{
unsigned int pasid;
const struct cik_ih_ring_entry *ihre =
(const struct cik_ih_ring_entry *)ih_ring_entry;
pasid = (ihre->ring_id & 0xffff0000) >> 16;
return (pasid != 0) &&
(ihre->source_id == CIK_INTSRC_CP_END_OF_PIPE ||
ihre->source_id == CIK_INTSRC_SQ_INTERRUPT_MSG ||
ihre->source_id == CIK_INTSRC_CP_BAD_OPCODE);
}
static void cik_event_interrupt_wq(struct kfd_dev *dev,
const uint32_t *ih_ring_entry)
{
unsigned int pasid;
const struct cik_ih_ring_entry *ihre =
(const struct cik_ih_ring_entry *)ih_ring_entry;
pasid = (ihre->ring_id & 0xffff0000) >> 16;
if (pasid == 0)
return;
if (ihre->source_id == CIK_INTSRC_CP_END_OF_PIPE)
kfd_signal_event_interrupt(pasid, 0, 0);
else if (ihre->source_id == CIK_INTSRC_SQ_INTERRUPT_MSG)
kfd_signal_event_interrupt(pasid, ihre->data & 0xFF, 8);
else if (ihre->source_id == CIK_INTSRC_CP_BAD_OPCODE)
kfd_signal_hw_exception_event(pasid);
}
