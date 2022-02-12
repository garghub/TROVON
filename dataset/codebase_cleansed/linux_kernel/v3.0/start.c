void xmon_map_scc(void)
{
}
int xmon_write(const void *ptr, int nb)
{
return udbg_write(ptr, nb);
}
int xmon_readchar(void)
{
if (udbg_getc)
return udbg_getc();
return -1;
}
int xmon_read_poll(void)
{
if (udbg_getc_poll)
return udbg_getc_poll();
return -1;
}
