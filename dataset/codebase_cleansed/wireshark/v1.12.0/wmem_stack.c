void *
wmem_stack_peek(const wmem_stack_t *stack)
{
wmem_list_frame_t *frame;
frame = wmem_list_head(stack);
g_assert(frame);
return wmem_list_frame_data(frame);
}
void *
wmem_stack_pop(wmem_stack_t *stack)
{
void *data;
data = wmem_stack_peek(stack);
wmem_list_remove(stack, data);
return data;
}
