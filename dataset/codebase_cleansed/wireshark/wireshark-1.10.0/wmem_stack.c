void *
wmem_stack_peek(const wmem_stack_t *stack)
{
wmem_slist_frame_t *frame;
frame = wmem_slist_front(stack);
g_assert(frame);
return wmem_slist_frame_data(frame);
}
void *
wmem_stack_pop(wmem_stack_t *stack)
{
void *data;
data = wmem_stack_peek(stack);
wmem_slist_remove(stack, data);
return data;
}
void
wmem_stack_push(wmem_stack_t *stack, void *data)
{
wmem_slist_prepend(stack, data);
}
