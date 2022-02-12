void speakup_start_ttys(void)
{
int i;
for (i = 0; i < MAX_NR_CONSOLES; i++) {
if (speakup_console[i] && speakup_console[i]->tty_stopped)
continue;
if ((vc_cons[i].d) && (vc_cons[i].d->port.tty))
start_tty(vc_cons[i].d->port.tty);
}
}
static void speakup_stop_ttys(void)
{
int i;
for (i = 0; i < MAX_NR_CONSOLES; i++)
if ((vc_cons[i].d && (vc_cons[i].d->port.tty)))
stop_tty(vc_cons[i].d->port.tty);
}
static int synth_buffer_free(void)
{
int chars_free;
if (buff_in >= buff_out)
chars_free = SYNTH_BUF_SIZE - (buff_in - buff_out);
else
chars_free = buff_out - buff_in;
return chars_free;
}
int synth_buffer_empty(void)
{
return (buff_in == buff_out);
}
void synth_buffer_add(u16 ch)
{
if (!synth->alive) {
return;
}
if (synth_buffer_free() <= 100) {
synth_start();
speakup_stop_ttys();
}
if (synth_buffer_free() <= 1)
return;
*buff_in++ = ch;
if (buff_in > buffer_end)
buff_in = synth_buffer;
}
u16 synth_buffer_getc(void)
{
u16 ch;
if (buff_out == buff_in)
return 0;
ch = *buff_out++;
if (buff_out > buffer_end)
buff_out = synth_buffer;
return ch;
}
u16 synth_buffer_peek(void)
{
if (buff_out == buff_in)
return 0;
return *buff_out;
}
void synth_buffer_skip_nonlatin1(void)
{
while (buff_out != buff_in) {
if (*buff_out < 0x100)
return;
buff_out++;
if (buff_out > buffer_end)
buff_out = synth_buffer;
}
}
void synth_buffer_clear(void)
{
buff_in = synth_buffer;
buff_out = synth_buffer;
}
