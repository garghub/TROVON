static void diag_ftp_handler(struct ext_code extirq,
unsigned int param32,
unsigned long param64)
{
if ((extirq.subcode >> 8) != 8)
return;
inc_irq_stat(IRQEXT_FTP);
diag_ftp_subcode = extirq.subcode & 0xffU;
complete(&diag_ftp_rx_complete);
}
static int diag_ftp_2c4(struct diag_ftp_ldfpl *fpl,
enum hmcdrv_ftp_cmdid cmd)
{
int rc;
diag_stat_inc(DIAG_STAT_X2C4);
asm volatile(
" diag %[addr],%[cmd],0x2c4\n"
"0: j 2f\n"
"1: la %[rc],%[err]\n"
"2:\n"
EX_TABLE(0b, 1b)
: [rc] "=d" (rc), "+m" (*fpl)
: [cmd] "0" (cmd), [addr] "d" (virt_to_phys(fpl)),
[err] "i" (DIAG_FTP_RET_EPERM)
: "cc");
switch (rc) {
case DIAG_FTP_RET_OK:
return 0;
case DIAG_FTP_RET_EBUSY:
return -EBUSY;
case DIAG_FTP_RET_EPERM:
return -EPERM;
case DIAG_FTP_RET_EIO:
default:
return -EIO;
}
}
ssize_t diag_ftp_cmd(const struct hmcdrv_ftp_cmdspec *ftp, size_t *fsize)
{
struct diag_ftp_ldfpl *ldfpl;
ssize_t len;
#ifdef DEBUG
unsigned long start_jiffies;
pr_debug("starting DIAG X'2C4' on '%s', requesting %zd bytes\n",
ftp->fname, ftp->len);
start_jiffies = jiffies;
#endif
init_completion(&diag_ftp_rx_complete);
ldfpl = (void *) get_zeroed_page(GFP_KERNEL | GFP_DMA);
if (!ldfpl) {
len = -ENOMEM;
goto out;
}
len = strlcpy(ldfpl->fident, ftp->fname, sizeof(ldfpl->fident));
if (len >= HMCDRV_FTP_FIDENT_MAX) {
len = -EINVAL;
goto out_free;
}
ldfpl->transferred = 0;
ldfpl->fsize = 0;
ldfpl->offset = ftp->ofs;
ldfpl->buflen = ftp->len;
ldfpl->bufaddr = virt_to_phys(ftp->buf);
len = diag_ftp_2c4(ldfpl, ftp->id);
if (len)
goto out_free;
wait_for_completion(&diag_ftp_rx_complete);
#ifdef DEBUG
pr_debug("completed DIAG X'2C4' after %lu ms\n",
(jiffies - start_jiffies) * 1000 / HZ);
pr_debug("status of DIAG X'2C4' is %u, with %lld/%lld bytes\n",
diag_ftp_subcode, ldfpl->transferred, ldfpl->fsize);
#endif
switch (diag_ftp_subcode) {
case DIAG_FTP_STAT_OK:
len = ldfpl->transferred;
if (fsize)
*fsize = ldfpl->fsize;
break;
case DIAG_FTP_STAT_LDNPERM:
len = -EPERM;
break;
case DIAG_FTP_STAT_LDRUNS:
len = -EBUSY;
break;
case DIAG_FTP_STAT_LDFAIL:
len = -ENOENT;
break;
default:
len = -EIO;
break;
}
out_free:
free_page((unsigned long) ldfpl);
out:
return len;
}
int diag_ftp_startup(void)
{
int rc;
rc = register_external_irq(EXT_IRQ_CP_SERVICE, diag_ftp_handler);
if (rc)
return rc;
irq_subclass_register(IRQ_SUBCLASS_SERVICE_SIGNAL);
return 0;
}
void diag_ftp_shutdown(void)
{
irq_subclass_unregister(IRQ_SUBCLASS_SERVICE_SIGNAL);
unregister_external_irq(EXT_IRQ_CP_SERVICE, diag_ftp_handler);
}
