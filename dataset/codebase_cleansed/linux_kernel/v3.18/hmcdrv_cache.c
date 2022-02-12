static ssize_t hmcdrv_cache_get(const struct hmcdrv_ftp_cmdspec *ftp)
{
loff_t pos;
ssize_t len;
if ((ftp->id != hmcdrv_cache_file.id) ||
strcmp(hmcdrv_cache_file.fname, ftp->fname))
return -1;
if (ftp->ofs >= hmcdrv_cache_file.fsize)
return 0;
if ((hmcdrv_cache_file.ofs < 0) ||
time_after(jiffies, hmcdrv_cache_file.timeout))
return -1;
len = hmcdrv_cache_file.fsize - ftp->ofs;
if (len > ftp->len)
len = ftp->len;
pos = ftp->ofs - hmcdrv_cache_file.ofs;
if ((pos >= 0) &&
((pos + len) <= hmcdrv_cache_file.len)) {
memcpy(ftp->buf,
hmcdrv_cache_file.content + pos,
len);
pr_debug("using cached content of '%s', returning %zd/%zd bytes\n",
hmcdrv_cache_file.fname, len,
hmcdrv_cache_file.fsize);
return len;
}
return -1;
}
static ssize_t hmcdrv_cache_do(const struct hmcdrv_ftp_cmdspec *ftp,
hmcdrv_cache_ftpfunc func)
{
ssize_t len;
if ((ftp->len > 0) && (hmcdrv_cache_file.len >= ftp->len)) {
struct hmcdrv_ftp_cmdspec cftp = *ftp;
cftp.buf = hmcdrv_cache_file.content;
cftp.len = hmcdrv_cache_file.len;
len = func(&cftp, &hmcdrv_cache_file.fsize);
if (len > 0) {
pr_debug("caching %zd bytes content for '%s'\n",
len, ftp->fname);
if (len > ftp->len)
len = ftp->len;
hmcdrv_cache_file.ofs = ftp->ofs;
hmcdrv_cache_file.timeout = jiffies +
HMCDRV_CACHE_TIMEOUT * HZ;
memcpy(ftp->buf, hmcdrv_cache_file.content, len);
}
} else {
len = func(ftp, &hmcdrv_cache_file.fsize);
hmcdrv_cache_file.ofs = -1;
}
if (len > 0) {
strlcpy(hmcdrv_cache_file.fname, ftp->fname,
HMCDRV_FTP_FIDENT_MAX);
hmcdrv_cache_file.id = ftp->id;
pr_debug("caching cmd %d, file size %zu for '%s'\n",
ftp->id, hmcdrv_cache_file.fsize, ftp->fname);
}
return len;
}
ssize_t hmcdrv_cache_cmd(const struct hmcdrv_ftp_cmdspec *ftp,
hmcdrv_cache_ftpfunc func)
{
ssize_t len;
if ((ftp->id == HMCDRV_FTP_DIR) ||
(ftp->id == HMCDRV_FTP_NLIST) ||
(ftp->id == HMCDRV_FTP_GET)) {
len = hmcdrv_cache_get(ftp);
if (len >= 0)
return len;
len = hmcdrv_cache_do(ftp, func);
if (len >= 0)
return len;
} else {
len = func(ftp, NULL);
}
hmcdrv_cache_file.id = HMCDRV_FTP_NOOP;
hmcdrv_cache_file.fsize = LLONG_MAX;
hmcdrv_cache_file.ofs = -1;
return len;
}
int hmcdrv_cache_startup(size_t cachesize)
{
if (cachesize > 0) {
hmcdrv_cache_order = get_order(cachesize);
hmcdrv_cache_file.content =
(void *) __get_free_pages(GFP_KERNEL | GFP_DMA,
hmcdrv_cache_order);
if (!hmcdrv_cache_file.content) {
pr_err("Allocating the requested cache size of %zu bytes failed\n",
cachesize);
return -ENOMEM;
}
pr_debug("content cache enabled, size is %zu bytes\n",
cachesize);
}
hmcdrv_cache_file.len = cachesize;
return 0;
}
void hmcdrv_cache_shutdown(void)
{
if (hmcdrv_cache_file.content) {
free_pages((unsigned long) hmcdrv_cache_file.content,
hmcdrv_cache_order);
hmcdrv_cache_file.content = NULL;
}
hmcdrv_cache_file.id = HMCDRV_FTP_NOOP;
hmcdrv_cache_file.fsize = LLONG_MAX;
hmcdrv_cache_file.ofs = -1;
hmcdrv_cache_file.len = 0;
}
