void *return_address(unsigned int depth)
{
struct dwarf_frame *frame;
unsigned long ra;
int i;
for (i = 0, frame = NULL, ra = 0; i <= depth; i++) {
struct dwarf_frame *tmp;
tmp = dwarf_unwind_stack(ra, frame);
if (!tmp)
return NULL;
if (frame)
dwarf_free_frame(frame);
frame = tmp;
if (!frame || !frame->return_addr)
break;
ra = frame->return_addr;
}
WARN_ON(i != depth + 1);
if (frame)
dwarf_free_frame(frame);
return (void *)ra;
}
void *return_address(unsigned int depth)
{
return NULL;
}
