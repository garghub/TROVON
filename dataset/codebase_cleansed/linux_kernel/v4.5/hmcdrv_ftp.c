static enum hmcdrv_ftp_cmdid hmcdrv_ftp_cmd_getid(const char *cmd, int len)
{
struct hmcdrv_ftp_cmd_desc {
const char *str;
enum hmcdrv_ftp_cmdid cmd;
};
static const struct hmcdrv_ftp_cmd_desc ftpcmds[7] = {
{.str = "get",
.cmd = HMCDRV_FTP_GET},
{.str = "dir",
.cmd = HMCDRV_FTP_DIR},
{.str = "delete",
.cmd = HMCDRV_FTP_DELETE},
{.str = "nls",
.cmd = HMCDRV_FTP_NLIST},
{.str = "put",
.cmd = HMCDRV_FTP_PUT},
{.str = "append",
.cmd = HMCDRV_FTP_APPEND},
{.str = NULL}
};
const struct hmcdrv_ftp_cmd_desc *pdesc;
u16 crc = 0xffffU;
if (len == 0)
return HMCDRV_FTP_NOOP;
crc = crc16(crc, cmd, len);
pdesc = ftpcmds + (crc % ARRAY_SIZE(ftpcmds));
pr_debug("FTP command '%s' has CRC 0x%04x, at table pos. %lu\n",
cmd, crc, (crc % ARRAY_SIZE(ftpcmds)));
if (!pdesc->str || strncmp(pdesc->str, cmd, len))
return HMCDRV_FTP_NOOP;
pr_debug("FTP command '%s' found, with ID %d\n",
pdesc->str, pdesc->cmd);
return pdesc->cmd;
}
static int hmcdrv_ftp_parse(char *cmd, struct hmcdrv_ftp_cmdspec *ftp)
{
char *start;
int argc = 0;
ftp->id = HMCDRV_FTP_NOOP;
ftp->fname = NULL;
while (*cmd != '\0') {
while (isspace(*cmd))
++cmd;
if (*cmd == '\0')
break;
start = cmd;
switch (argc) {
case 0:
while ((*cmd != '\0') && !isspace(*cmd))
++cmd;
ftp->id = hmcdrv_ftp_cmd_getid(start, cmd - start);
break;
case 1:
while ((*cmd != '\0') && !iscntrl(*cmd))
++cmd;
ftp->fname = start;
default:
*cmd = '\0';
break;
}
++argc;
}
if (!ftp->fname || (ftp->id == HMCDRV_FTP_NOOP))
return -EINVAL;
return 0;
}
ssize_t hmcdrv_ftp_do(const struct hmcdrv_ftp_cmdspec *ftp)
{
ssize_t len;
mutex_lock(&hmcdrv_ftp_mutex);
if (hmcdrv_ftp_funcs && hmcdrv_ftp_refcnt) {
pr_debug("starting transfer, cmd %d for '%s' at %lld with %zd bytes\n",
ftp->id, ftp->fname, (long long) ftp->ofs, ftp->len);
len = hmcdrv_cache_cmd(ftp, hmcdrv_ftp_funcs->transfer);
} else {
len = -ENXIO;
}
mutex_unlock(&hmcdrv_ftp_mutex);
return len;
}
int hmcdrv_ftp_probe(void)
{
int rc;
struct hmcdrv_ftp_cmdspec ftp = {
.id = HMCDRV_FTP_NOOP,
.ofs = 0,
.fname = "",
.len = PAGE_SIZE
};
ftp.buf = (void *) get_zeroed_page(GFP_KERNEL | GFP_DMA);
if (!ftp.buf)
return -ENOMEM;
rc = hmcdrv_ftp_startup();
if (rc)
goto out;
rc = hmcdrv_ftp_do(&ftp);
hmcdrv_ftp_shutdown();
switch (rc) {
case -ENOENT:
case -EBUSY:
rc = 0;
break;
default:
if (rc > 0)
rc = 0;
break;
}
out:
free_page((unsigned long) ftp.buf);
return rc;
}
ssize_t hmcdrv_ftp_cmd(char __kernel *cmd, loff_t offset,
char __user *buf, size_t len)
{
int order;
struct hmcdrv_ftp_cmdspec ftp = {.len = len, .ofs = offset};
ssize_t retlen = hmcdrv_ftp_parse(cmd, &ftp);
if (retlen)
return retlen;
order = get_order(ftp.len);
ftp.buf = (void *) __get_free_pages(GFP_KERNEL | GFP_DMA, order);
if (!ftp.buf)
return -ENOMEM;
switch (ftp.id) {
case HMCDRV_FTP_DIR:
case HMCDRV_FTP_NLIST:
case HMCDRV_FTP_GET:
retlen = hmcdrv_ftp_do(&ftp);
if ((retlen >= 0) &&
copy_to_user(buf, ftp.buf, retlen))
retlen = -EFAULT;
break;
case HMCDRV_FTP_PUT:
case HMCDRV_FTP_APPEND:
if (!copy_from_user(ftp.buf, buf, ftp.len))
retlen = hmcdrv_ftp_do(&ftp);
else
retlen = -EFAULT;
break;
case HMCDRV_FTP_DELETE:
retlen = hmcdrv_ftp_do(&ftp);
break;
default:
retlen = -EOPNOTSUPP;
break;
}
free_pages((unsigned long) ftp.buf, order);
return retlen;
}
int hmcdrv_ftp_startup(void)
{
static const struct hmcdrv_ftp_ops hmcdrv_ftp_zvm = {
.startup = diag_ftp_startup,
.shutdown = diag_ftp_shutdown,
.transfer = diag_ftp_cmd
};
static const struct hmcdrv_ftp_ops hmcdrv_ftp_lpar = {
.startup = sclp_ftp_startup,
.shutdown = sclp_ftp_shutdown,
.transfer = sclp_ftp_cmd
};
int rc = 0;
mutex_lock(&hmcdrv_ftp_mutex);
if (hmcdrv_ftp_refcnt == 0) {
if (MACHINE_IS_VM)
hmcdrv_ftp_funcs = &hmcdrv_ftp_zvm;
else if (MACHINE_IS_LPAR || MACHINE_IS_KVM)
hmcdrv_ftp_funcs = &hmcdrv_ftp_lpar;
else
rc = -EOPNOTSUPP;
if (hmcdrv_ftp_funcs)
rc = hmcdrv_ftp_funcs->startup();
}
if (!rc)
++hmcdrv_ftp_refcnt;
mutex_unlock(&hmcdrv_ftp_mutex);
return rc;
}
void hmcdrv_ftp_shutdown(void)
{
mutex_lock(&hmcdrv_ftp_mutex);
--hmcdrv_ftp_refcnt;
if ((hmcdrv_ftp_refcnt == 0) && hmcdrv_ftp_funcs)
hmcdrv_ftp_funcs->shutdown();
mutex_unlock(&hmcdrv_ftp_mutex);
}
