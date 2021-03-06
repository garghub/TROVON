static int diag8_noresponse(int cmdlen)
{
register unsigned long reg2 asm ("2") = (addr_t) cpcmd_buf;
register unsigned long reg3 asm ("3") = cmdlen;
asm volatile(
" sam31\n"
" diag %1,%0,0x8\n"
" sam64\n"
: "+d" (reg3) : "d" (reg2) : "cc");
return reg3;
}
static int diag8_response(int cmdlen, char *response, int *rlen)
{
register unsigned long reg2 asm ("2") = (addr_t) cpcmd_buf;
register unsigned long reg3 asm ("3") = (addr_t) response;
register unsigned long reg4 asm ("4") = cmdlen | 0x40000000L;
register unsigned long reg5 asm ("5") = *rlen;
asm volatile(
" sam31\n"
" diag %2,%0,0x8\n"
" sam64\n"
" brc 8,1f\n"
" agr %1,%4\n"
"1:\n"
: "+d" (reg4), "+d" (reg5)
: "d" (reg2), "d" (reg3), "d" (*rlen) : "cc");
*rlen = reg5;
return reg4;
}
int __cpcmd(const char *cmd, char *response, int rlen, int *response_code)
{
int cmdlen;
int rc;
int response_len;
cmdlen = strlen(cmd);
BUG_ON(cmdlen > 240);
memcpy(cpcmd_buf, cmd, cmdlen);
ASCEBC(cpcmd_buf, cmdlen);
diag_stat_inc(DIAG_STAT_X008);
if (response) {
memset(response, 0, rlen);
response_len = rlen;
rc = diag8_response(cmdlen, response, &rlen);
EBCASC(response, response_len);
} else {
rc = diag8_noresponse(cmdlen);
}
if (response_code)
*response_code = rc;
return rlen;
}
int cpcmd(const char *cmd, char *response, int rlen, int *response_code)
{
char *lowbuf;
int len;
unsigned long flags;
if ((virt_to_phys(response) != (unsigned long) response) ||
(((unsigned long)response + rlen) >> 31)) {
lowbuf = kmalloc(rlen, GFP_KERNEL | GFP_DMA);
if (!lowbuf) {
pr_warning("The cpcmd kernel function failed to "
"allocate a response buffer\n");
return -ENOMEM;
}
spin_lock_irqsave(&cpcmd_lock, flags);
len = __cpcmd(cmd, lowbuf, rlen, response_code);
spin_unlock_irqrestore(&cpcmd_lock, flags);
memcpy(response, lowbuf, rlen);
kfree(lowbuf);
} else {
spin_lock_irqsave(&cpcmd_lock, flags);
len = __cpcmd(cmd, response, rlen, response_code);
spin_unlock_irqrestore(&cpcmd_lock, flags);
}
return len;
}
