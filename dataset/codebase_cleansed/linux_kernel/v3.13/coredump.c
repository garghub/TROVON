static ssize_t do_coredump_read(int num, struct spu_context *ctx, void *buffer,
size_t size, loff_t *off)
{
u64 data;
int ret;
if (spufs_coredump_read[num].read)
return spufs_coredump_read[num].read(ctx, buffer, size, off);
data = spufs_coredump_read[num].get(ctx);
ret = snprintf(buffer, size, "0x%.16llx", data);
if (ret >= size)
return size;
return ++ret;
}
static int spufs_ctx_note_size(struct spu_context *ctx, int dfd)
{
int i, sz, total = 0;
char *name;
char fullname[80];
for (i = 0; spufs_coredump_read[i].name != NULL; i++) {
name = spufs_coredump_read[i].name;
sz = spufs_coredump_read[i].size;
sprintf(fullname, "SPU/%d/%s", dfd, name);
total += sizeof(struct elf_note);
total += roundup(strlen(fullname) + 1, 4);
total += roundup(sz, 4);
}
return total;
}
static int match_context(const void *v, struct file *file, unsigned fd)
{
struct spu_context *ctx;
if (file->f_op != &spufs_context_fops)
return 0;
ctx = SPUFS_I(file_inode(file))->i_ctx;
if (ctx->flags & SPU_CREATE_NOSCHED)
return 0;
return fd + 1;
}
static struct spu_context *coredump_next_context(int *fd)
{
struct file *file;
int n = iterate_fd(current->files, *fd, match_context, NULL);
if (!n)
return NULL;
*fd = n - 1;
file = fcheck(*fd);
return SPUFS_I(file_inode(file))->i_ctx;
}
int spufs_coredump_extra_notes_size(void)
{
struct spu_context *ctx;
int size = 0, rc, fd;
fd = 0;
while ((ctx = coredump_next_context(&fd)) != NULL) {
rc = spu_acquire_saved(ctx);
if (rc)
break;
rc = spufs_ctx_note_size(ctx, fd);
spu_release_saved(ctx);
if (rc < 0)
break;
size += rc;
fd++;
}
return size;
}
static int spufs_arch_write_note(struct spu_context *ctx, int i,
struct coredump_params *cprm, int dfd)
{
loff_t pos = 0;
int sz, rc, total = 0;
const int bufsz = PAGE_SIZE;
char *name;
char fullname[80], *buf;
struct elf_note en;
buf = (void *)get_zeroed_page(GFP_KERNEL);
if (!buf)
return -ENOMEM;
name = spufs_coredump_read[i].name;
sz = spufs_coredump_read[i].size;
sprintf(fullname, "SPU/%d/%s", dfd, name);
en.n_namesz = strlen(fullname) + 1;
en.n_descsz = sz;
en.n_type = NT_SPU;
if (!dump_emit(cprm, &en, sizeof(en)))
goto Eio;
if (!dump_emit(cprm, fullname, en.n_namesz))
goto Eio;
if (!dump_align(cprm, 4))
goto Eio;
do {
rc = do_coredump_read(i, ctx, buf, bufsz, &pos);
if (rc > 0) {
if (!dump_emit(cprm, buf, rc))
goto Eio;
total += rc;
}
} while (rc == bufsz && total < sz);
if (rc < 0)
goto out;
if (!dump_skip(cprm,
roundup(cprm->written - total + sz, 4) - cprm->written))
goto Eio;
out:
free_page((unsigned long)buf);
return rc;
Eio:
free_page((unsigned long)buf);
return -EIO;
}
int spufs_coredump_extra_notes_write(struct coredump_params *cprm)
{
struct spu_context *ctx;
int fd, j, rc;
fd = 0;
while ((ctx = coredump_next_context(&fd)) != NULL) {
rc = spu_acquire_saved(ctx);
if (rc)
return rc;
for (j = 0; spufs_coredump_read[j].name != NULL; j++) {
rc = spufs_arch_write_note(ctx, j, cprm, fd);
if (rc) {
spu_release_saved(ctx);
return rc;
}
}
spu_release_saved(ctx);
fd++;
}
return 0;
}
