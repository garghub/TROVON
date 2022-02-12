static int save_return_addr(struct stackframe *frame, void *d)
{
struct return_address_data *data = d;
if (!data->level) {
data->addr = (void *)frame->pc;
return 1;
} else {
--data->level;
return 0;
}
}
void *return_address(unsigned int level)
{
struct return_address_data data;
struct stackframe frame;
data.level = level + 2;
data.addr = NULL;
frame.fp = (unsigned long)__builtin_frame_address(0);
frame.sp = current_stack_pointer;
frame.pc = (unsigned long)return_address;
walk_stackframe(&frame, save_return_addr, &data);
if (!data.level)
return data.addr;
else
return NULL;
}
