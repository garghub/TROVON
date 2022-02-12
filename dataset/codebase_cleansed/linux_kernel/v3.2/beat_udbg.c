static void udbg_putc_beat(char c)
{
unsigned long rc;
if (c == '\n')
udbg_putc_beat('\r');
rc = beat_put_term_char(celleb_vtermno, 1, (uint64_t)c << 56, 0);
}
static int udbg_getc_poll_beat(void)
{
char ch, *buf = (char *)inbuf;
int i;
long rc;
if (inbuflen == 0) {
inbuflen = 0;
rc = beat_get_term_char(celleb_vtermno, &inbuflen,
inbuf+0, inbuf+1);
if (rc != 0)
inbuflen = 0;
}
if (inbuflen <= 0 || inbuflen > 16) {
inbuflen = 0;
return -1;
}
ch = buf[0];
for (i = 1; i < inbuflen; i++)
buf[i-1] = buf[i];
inbuflen--;
return ch;
}
static int udbg_getc_beat(void)
{
int ch;
for (;;) {
ch = udbg_getc_poll_beat();
if (ch == -1) {
volatile unsigned long delay;
for (delay = 0; delay < 2000000; delay++)
;
} else {
return ch;
}
}
}
void __init udbg_init_debug_beat(void)
{
udbg_putc = udbg_putc_beat;
udbg_getc = udbg_getc_beat;
udbg_getc_poll = udbg_getc_poll_beat;
}
