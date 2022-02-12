void notrace prom_write(const char *buf, unsigned int n)
{
unsigned int dest_len;
unsigned long flags;
char *dest;
dest = console_write_buf;
raw_spin_lock_irqsave(&console_write_lock, flags);
dest_len = 0;
while (n-- != 0) {
char ch = *buf++;
if (ch == '\n') {
*dest++ = '\r';
dest_len++;
}
*dest++ = ch;
dest_len++;
if (dest_len >= CONSOLE_WRITE_BUF_SIZE - 1) {
prom_console_write_buf(console_write_buf, dest_len);
dest = console_write_buf;
dest_len = 0;
}
}
if (dest_len)
prom_console_write_buf(console_write_buf, dest_len);
raw_spin_unlock_irqrestore(&console_write_lock, flags);
}
void notrace prom_printf(const char *fmt, ...)
{
va_list args;
int i;
va_start(args, fmt);
i = vscnprintf(ppbuf, sizeof(ppbuf), fmt, args);
va_end(args);
prom_write(ppbuf, i);
}
