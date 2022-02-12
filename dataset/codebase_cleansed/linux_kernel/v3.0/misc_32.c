void
prom_reboot(char *bcommand)
{
unsigned long flags;
spin_lock_irqsave(&prom_lock, flags);
(*(romvec->pv_reboot))(bcommand);
restore_current();
spin_unlock_irqrestore(&prom_lock, flags);
}
void
prom_feval(char *fstring)
{
unsigned long flags;
if(!fstring || fstring[0] == 0)
return;
spin_lock_irqsave(&prom_lock, flags);
if(prom_vers == PROM_V0)
(*(romvec->pv_fortheval.v0_eval))(strlen(fstring), fstring);
else
(*(romvec->pv_fortheval.v2_eval))(fstring);
restore_current();
spin_unlock_irqrestore(&prom_lock, flags);
}
void
prom_cmdline(void)
{
unsigned long flags;
spin_lock_irqsave(&prom_lock, flags);
(*(romvec->pv_abort))();
restore_current();
spin_unlock_irqrestore(&prom_lock, flags);
set_auxio(AUXIO_LED, 0);
}
void __noreturn
prom_halt(void)
{
unsigned long flags;
again:
spin_lock_irqsave(&prom_lock, flags);
(*(romvec->pv_halt))();
restore_current();
spin_unlock_irqrestore(&prom_lock, flags);
goto again;
}
void
prom_setsync(sfunc_t funcp)
{
if(!funcp) return;
*romvec->pv_synchook = funcp;
}
unsigned char
prom_get_idprom(char *idbuf, int num_bytes)
{
int len;
len = prom_getproplen(prom_root_node, "idprom");
if((len>num_bytes) || (len==-1)) return 0xff;
if(!prom_getproperty(prom_root_node, "idprom", idbuf, num_bytes))
return idbuf[0];
return 0xff;
}
int
prom_version(void)
{
return romvec->pv_romvers;
}
int
prom_getrev(void)
{
return prom_rev;
}
int
prom_getprev(void)
{
return prom_prev;
}
