void memcons_putc(char c)
{
char *new_output_pos;
*memcons.output_pos = c;
wmb();
new_output_pos = memcons.output_pos + 1;
if (new_output_pos >= memcons.output_end)
new_output_pos = memcons.output_start;
memcons.output_pos = new_output_pos;
}
int memcons_getc_poll(void)
{
char c;
char *new_input_pos;
if (*memcons.input_pos) {
c = *memcons.input_pos;
new_input_pos = memcons.input_pos + 1;
if (new_input_pos >= memcons.input_end)
new_input_pos = memcons.input_start;
else if (*new_input_pos == '\0')
new_input_pos = memcons.input_start;
*memcons.input_pos = '\0';
wmb();
memcons.input_pos = new_input_pos;
return c;
}
return -1;
}
int memcons_getc(void)
{
int c;
while (1) {
c = memcons_getc_poll();
if (c == -1)
cpu_relax();
else
break;
}
return c;
}
void udbg_init_memcons(void)
{
udbg_putc = memcons_putc;
udbg_getc = memcons_getc;
udbg_getc_poll = memcons_getc_poll;
}
