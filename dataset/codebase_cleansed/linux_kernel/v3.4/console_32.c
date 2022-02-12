static int prom_nbputchar(const char *buf)
{
unsigned long flags;
int i = -1;
spin_lock_irqsave(&prom_lock, flags);
switch(prom_vers) {
case PROM_V0:
if ((*(romvec->pv_nbputchar))(*buf))
i = 1;
break;
case PROM_V2:
case PROM_V3:
if ((*(romvec->pv_v2devops).v2_dev_write)(*romvec->pv_v2bootargs.fd_stdout,
buf, 0x1) == 1)
i = 1;
break;
default:
break;
}
restore_current();
spin_unlock_irqrestore(&prom_lock, flags);
return i;
}
void prom_console_write_buf(const char *buf, int len)
{
while (len) {
int n = prom_nbputchar(buf);
if (n < 0)
continue;
len--;
buf++;
}
}
