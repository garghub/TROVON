static int flat_core_dump(struct coredump_params *cprm)
{
pr_warn("Process %s:%d received signr %d and should have core dumped\n",
current->comm, current->pid, cprm->siginfo->si_signo);
return 1;
}
static int create_flat_tables(struct linux_binprm *bprm, unsigned long arg_start)
{
char __user *p;
unsigned long __user *sp;
long i, len;
p = (char __user *)arg_start;
sp = (unsigned long __user *)current->mm->start_stack;
sp -= bprm->envc + 1;
sp -= bprm->argc + 1;
sp -= flat_argvp_envp_on_stack() ? 2 : 0;
sp -= 1;
current->mm->start_stack = (unsigned long)sp & -FLAT_STACK_ALIGN;
sp = (unsigned long __user *)current->mm->start_stack;
__put_user(bprm->argc, sp++);
if (flat_argvp_envp_on_stack()) {
unsigned long argv, envp;
argv = (unsigned long)(sp + 2);
envp = (unsigned long)(sp + 2 + bprm->argc + 1);
__put_user(argv, sp++);
__put_user(envp, sp++);
}
current->mm->arg_start = (unsigned long)p;
for (i = bprm->argc; i > 0; i--) {
__put_user((unsigned long)p, sp++);
len = strnlen_user(p, MAX_ARG_STRLEN);
if (!len || len > MAX_ARG_STRLEN)
return -EINVAL;
p += len;
}
__put_user(0, sp++);
current->mm->arg_end = (unsigned long)p;
current->mm->env_start = (unsigned long) p;
for (i = bprm->envc; i > 0; i--) {
__put_user((unsigned long)p, sp++);
len = strnlen_user(p, MAX_ARG_STRLEN);
if (!len || len > MAX_ARG_STRLEN)
return -EINVAL;
p += len;
}
__put_user(0, sp++);
current->mm->env_end = (unsigned long)p;
return 0;
}
static int decompress_exec(
struct linux_binprm *bprm,
unsigned long offset,
char *dst,
long len,
int fd)
{
unsigned char *buf;
z_stream strm;
loff_t fpos;
int ret, retval;
pr_debug("decompress_exec(offset=%lx,buf=%p,len=%lx)\n", offset, dst, len);
memset(&strm, 0, sizeof(strm));
strm.workspace = kmalloc(zlib_inflate_workspacesize(), GFP_KERNEL);
if (strm.workspace == NULL) {
pr_debug("no memory for decompress workspace\n");
return -ENOMEM;
}
buf = kmalloc(LBUFSIZE, GFP_KERNEL);
if (buf == NULL) {
pr_debug("no memory for read buffer\n");
retval = -ENOMEM;
goto out_free;
}
fpos = offset;
ret = kernel_read(bprm->file, offset, buf, LBUFSIZE);
strm.next_in = buf;
strm.avail_in = ret;
strm.total_in = 0;
fpos += ret;
retval = -ENOEXEC;
if (ret < 10) {
pr_debug("file too small?\n");
goto out_free_buf;
}
if ((buf[0] != 037) || ((buf[1] != 0213) && (buf[1] != 0236))) {
pr_debug("unknown compression magic?\n");
goto out_free_buf;
}
if (buf[2] != 8) {
pr_debug("unknown compression method?\n");
goto out_free_buf;
}
if ((buf[3] & ENCRYPTED) || (buf[3] & CONTINUATION) ||
(buf[3] & RESERVED)) {
pr_debug("unknown flags?\n");
goto out_free_buf;
}
ret = 10;
if (buf[3] & EXTRA_FIELD) {
ret += 2 + buf[10] + (buf[11] << 8);
if (unlikely(ret >= LBUFSIZE)) {
pr_debug("buffer overflow (EXTRA)?\n");
goto out_free_buf;
}
}
if (buf[3] & ORIG_NAME) {
while (ret < LBUFSIZE && buf[ret++] != 0)
;
if (unlikely(ret == LBUFSIZE)) {
pr_debug("buffer overflow (ORIG_NAME)?\n");
goto out_free_buf;
}
}
if (buf[3] & COMMENT) {
while (ret < LBUFSIZE && buf[ret++] != 0)
;
if (unlikely(ret == LBUFSIZE)) {
pr_debug("buffer overflow (COMMENT)?\n");
goto out_free_buf;
}
}
strm.next_in += ret;
strm.avail_in -= ret;
strm.next_out = dst;
strm.avail_out = len;
strm.total_out = 0;
if (zlib_inflateInit2(&strm, -MAX_WBITS) != Z_OK) {
pr_debug("zlib init failed?\n");
goto out_free_buf;
}
while ((ret = zlib_inflate(&strm, Z_NO_FLUSH)) == Z_OK) {
ret = kernel_read(bprm->file, fpos, buf, LBUFSIZE);
if (ret <= 0)
break;
len -= ret;
strm.next_in = buf;
strm.avail_in = ret;
strm.total_in = 0;
fpos += ret;
}
if (ret < 0) {
pr_debug("decompression failed (%d), %s\n",
ret, strm.msg);
goto out_zlib;
}
retval = 0;
out_zlib:
zlib_inflateEnd(&strm);
out_free_buf:
kfree(buf);
out_free:
kfree(strm.workspace);
return retval;
}
static unsigned long
calc_reloc(unsigned long r, struct lib_info *p, int curid, int internalp)
{
unsigned long addr;
int id;
unsigned long start_brk;
unsigned long start_data;
unsigned long text_len;
unsigned long start_code;
#ifdef CONFIG_BINFMT_SHARED_FLAT
if (r == 0)
id = curid;
else {
id = (r >> 24) & 0xff;
r &= 0x00ffffff;
}
if (id >= MAX_SHARED_LIBS) {
pr_err("reference 0x%lx to shared library %d", r, id);
goto failed;
}
if (curid != id) {
if (internalp) {
pr_err("reloc address 0x%lx not in same module "
"(%d != %d)", r, curid, id);
goto failed;
} else if (!p->lib_list[id].loaded &&
load_flat_shared_library(id, p) < 0) {
pr_err("failed to load library %d", id);
goto failed;
}
if (p->lib_list[id].build_date && p->lib_list[curid].build_date &&
p->lib_list[curid].build_date < p->lib_list[id].build_date) {
pr_err("library %d is younger than %d", id, curid);
goto failed;
}
}
#else
id = 0;
#endif
start_brk = p->lib_list[id].start_brk;
start_data = p->lib_list[id].start_data;
start_code = p->lib_list[id].start_code;
text_len = p->lib_list[id].text_len;
if (!flat_reloc_valid(r, start_brk - start_data + text_len)) {
pr_err("reloc outside program 0x%lx (0 - 0x%lx/0x%lx)",
r, start_brk-start_data+text_len, text_len);
goto failed;
}
if (r < text_len)
addr = r + start_code;
else
addr = r - text_len + start_data;
return addr;
failed:
pr_cont(", killing %s!\n", current->comm);
send_sig(SIGSEGV, current, 0);
return RELOC_FAILED;
}
static void old_reloc(unsigned long rl)
{
static const char *segment[] = { "TEXT", "DATA", "BSS", "*UNKNOWN*" };
flat_v2_reloc_t r;
unsigned long __user *ptr;
unsigned long val;
r.value = rl;
#if defined(CONFIG_COLDFIRE)
ptr = (unsigned long __user *)(current->mm->start_code + r.reloc.offset);
#else
ptr = (unsigned long __user *)(current->mm->start_data + r.reloc.offset);
#endif
get_user(val, ptr);
pr_debug("Relocation of variable at DATASEG+%x "
"(address %p, currently %lx) into segment %s\n",
r.reloc.offset, ptr, val, segment[r.reloc.type]);
switch (r.reloc.type) {
case OLD_FLAT_RELOC_TYPE_TEXT:
val += current->mm->start_code;
break;
case OLD_FLAT_RELOC_TYPE_DATA:
val += current->mm->start_data;
break;
case OLD_FLAT_RELOC_TYPE_BSS:
val += current->mm->end_data;
break;
default:
pr_err("Unknown relocation type=%x\n", r.reloc.type);
break;
}
put_user(val, ptr);
pr_debug("Relocation became %lx\n", val);
}
static int load_flat_file(struct linux_binprm *bprm,
struct lib_info *libinfo, int id, unsigned long *extra_stack)
{
struct flat_hdr *hdr;
unsigned long textpos, datapos, realdatastart;
u32 text_len, data_len, bss_len, stack_len, full_data, flags;
unsigned long len, memp, memp_size, extra, rlim;
u32 __user *reloc, *rp;
struct inode *inode;
int i, rev, relocs;
loff_t fpos;
unsigned long start_code, end_code;
ssize_t result;
int ret;
hdr = ((struct flat_hdr *) bprm->buf);
inode = file_inode(bprm->file);
text_len = ntohl(hdr->data_start);
data_len = ntohl(hdr->data_end) - ntohl(hdr->data_start);
bss_len = ntohl(hdr->bss_end) - ntohl(hdr->data_end);
stack_len = ntohl(hdr->stack_size);
if (extra_stack) {
stack_len += *extra_stack;
*extra_stack = stack_len;
}
relocs = ntohl(hdr->reloc_count);
flags = ntohl(hdr->flags);
rev = ntohl(hdr->rev);
full_data = data_len + relocs * sizeof(unsigned long);
if (strncmp(hdr->magic, "bFLT", 4)) {
ret = -ENOEXEC;
goto err;
}
if (flags & FLAT_FLAG_KTRACE)
pr_info("Loading file: %s\n", bprm->filename);
if (rev != FLAT_VERSION && rev != OLD_FLAT_VERSION) {
pr_err("bad flat file version 0x%x (supported 0x%lx and 0x%lx)\n",
rev, FLAT_VERSION, OLD_FLAT_VERSION);
ret = -ENOEXEC;
goto err;
}
if (rev == OLD_FLAT_VERSION && id != 0) {
pr_err("shared libraries are not available before rev 0x%lx\n",
FLAT_VERSION);
ret = -ENOEXEC;
goto err;
}
if ((text_len | data_len | bss_len | stack_len | full_data) >> 28) {
pr_err("bad header\n");
ret = -ENOEXEC;
goto err;
}
if (rev == OLD_FLAT_VERSION && flat_old_ram_flag(flags))
flags = FLAT_FLAG_RAM;
#ifndef CONFIG_BINFMT_ZFLAT
if (flags & (FLAT_FLAG_GZIP|FLAT_FLAG_GZDATA)) {
pr_err("Support for ZFLAT executables is not enabled.\n");
ret = -ENOEXEC;
goto err;
}
#endif
rlim = rlimit(RLIMIT_DATA);
if (rlim >= RLIM_INFINITY)
rlim = ~0;
if (data_len + bss_len > rlim) {
ret = -ENOMEM;
goto err;
}
if (id == 0) {
ret = flush_old_exec(bprm);
if (ret)
goto err;
set_personality(PER_LINUX_32BIT);
setup_new_exec(bprm);
}
extra = max_t(unsigned long, bss_len + stack_len,
relocs * sizeof(unsigned long));
if (!IS_ENABLED(CONFIG_MMU) && !(flags & (FLAT_FLAG_RAM|FLAT_FLAG_GZIP))) {
pr_debug("ROM mapping of file (we hope)\n");
textpos = vm_mmap(bprm->file, 0, text_len, PROT_READ|PROT_EXEC,
MAP_PRIVATE|MAP_EXECUTABLE, 0);
if (!textpos || IS_ERR_VALUE(textpos)) {
ret = textpos;
if (!textpos)
ret = -ENOMEM;
pr_err("Unable to mmap process text, errno %d\n", ret);
goto err;
}
len = data_len + extra + MAX_SHARED_LIBS * sizeof(unsigned long);
len = PAGE_ALIGN(len);
realdatastart = vm_mmap(NULL, 0, len,
PROT_READ|PROT_WRITE|PROT_EXEC, MAP_PRIVATE, 0);
if (realdatastart == 0 || IS_ERR_VALUE(realdatastart)) {
ret = realdatastart;
if (!realdatastart)
ret = -ENOMEM;
pr_err("Unable to allocate RAM for process data, "
"errno %d\n", ret);
vm_munmap(textpos, text_len);
goto err;
}
datapos = ALIGN(realdatastart +
MAX_SHARED_LIBS * sizeof(unsigned long),
FLAT_DATA_ALIGN);
pr_debug("Allocated data+bss+stack (%u bytes): %lx\n",
data_len + bss_len + stack_len, datapos);
fpos = ntohl(hdr->data_start);
#ifdef CONFIG_BINFMT_ZFLAT
if (flags & FLAT_FLAG_GZDATA) {
result = decompress_exec(bprm, fpos, (char *)datapos,
full_data, 0);
} else
#endif
{
result = read_code(bprm->file, datapos, fpos,
full_data);
}
if (IS_ERR_VALUE(result)) {
ret = result;
pr_err("Unable to read data+bss, errno %d\n", ret);
vm_munmap(textpos, text_len);
vm_munmap(realdatastart, len);
goto err;
}
reloc = (u32 __user *)
(datapos + (ntohl(hdr->reloc_start) - text_len));
memp = realdatastart;
memp_size = len;
} else {
len = text_len + data_len + extra + MAX_SHARED_LIBS * sizeof(u32);
len = PAGE_ALIGN(len);
textpos = vm_mmap(NULL, 0, len,
PROT_READ | PROT_EXEC | PROT_WRITE, MAP_PRIVATE, 0);
if (!textpos || IS_ERR_VALUE(textpos)) {
ret = textpos;
if (!textpos)
ret = -ENOMEM;
pr_err("Unable to allocate RAM for process text/data, "
"errno %d\n", ret);
goto err;
}
realdatastart = textpos + ntohl(hdr->data_start);
datapos = ALIGN(realdatastart +
MAX_SHARED_LIBS * sizeof(u32),
FLAT_DATA_ALIGN);
reloc = (u32 __user *)
(datapos + (ntohl(hdr->reloc_start) - text_len));
memp = textpos;
memp_size = len;
#ifdef CONFIG_BINFMT_ZFLAT
if (flags & FLAT_FLAG_GZIP) {
#ifndef CONFIG_MMU
result = decompress_exec(bprm, sizeof(struct flat_hdr),
(((char *)textpos) + sizeof(struct flat_hdr)),
(text_len + full_data
- sizeof(struct flat_hdr)),
0);
memmove((void *) datapos, (void *) realdatastart,
full_data);
#else
long unz_text_len = text_len - sizeof(struct flat_hdr);
long unz_len = unz_text_len + full_data;
char *unz_data = vmalloc(unz_len);
if (!unz_data) {
result = -ENOMEM;
} else {
result = decompress_exec(bprm, sizeof(struct flat_hdr),
unz_data, unz_len, 0);
if (result == 0 &&
(copy_to_user((void __user *)textpos + sizeof(struct flat_hdr),
unz_data, unz_text_len) ||
copy_to_user((void __user *)datapos,
unz_data + unz_text_len, full_data)))
result = -EFAULT;
vfree(unz_data);
}
#endif
} else if (flags & FLAT_FLAG_GZDATA) {
result = read_code(bprm->file, textpos, 0, text_len);
if (!IS_ERR_VALUE(result)) {
#ifndef CONFIG_MMU
result = decompress_exec(bprm, text_len, (char *) datapos,
full_data, 0);
#else
char *unz_data = vmalloc(full_data);
if (!unz_data) {
result = -ENOMEM;
} else {
result = decompress_exec(bprm, text_len,
unz_data, full_data, 0);
if (result == 0 &&
copy_to_user((void __user *)datapos,
unz_data, full_data))
result = -EFAULT;
vfree(unz_data);
}
#endif
}
} else
#endif
{
result = read_code(bprm->file, textpos, 0, text_len);
if (!IS_ERR_VALUE(result))
result = read_code(bprm->file, datapos,
ntohl(hdr->data_start),
full_data);
}
if (IS_ERR_VALUE(result)) {
ret = result;
pr_err("Unable to read code+data+bss, errno %d\n", ret);
vm_munmap(textpos, text_len + data_len + extra +
MAX_SHARED_LIBS * sizeof(u32));
goto err;
}
}
start_code = textpos + sizeof(struct flat_hdr);
end_code = textpos + text_len;
text_len -= sizeof(struct flat_hdr);
if (id == 0) {
current->mm->start_code = start_code;
current->mm->end_code = end_code;
current->mm->start_data = datapos;
current->mm->end_data = datapos + data_len;
current->mm->start_brk = datapos + data_len + bss_len;
current->mm->brk = (current->mm->start_brk + 3) & ~3;
#ifndef CONFIG_MMU
current->mm->context.end_brk = memp + memp_size - stack_len;
#endif
}
if (flags & FLAT_FLAG_KTRACE) {
pr_info("Mapping is %lx, Entry point is %x, data_start is %x\n",
textpos, 0x00ffffff&ntohl(hdr->entry), ntohl(hdr->data_start));
pr_info("%s %s: TEXT=%lx-%lx DATA=%lx-%lx BSS=%lx-%lx\n",
id ? "Lib" : "Load", bprm->filename,
start_code, end_code, datapos, datapos + data_len,
datapos + data_len, (datapos + data_len + bss_len + 3) & ~3);
}
libinfo->lib_list[id].start_code = start_code;
libinfo->lib_list[id].start_data = datapos;
libinfo->lib_list[id].start_brk = datapos + data_len + bss_len;
libinfo->lib_list[id].text_len = text_len;
libinfo->lib_list[id].loaded = 1;
libinfo->lib_list[id].entry = (0x00ffffff & ntohl(hdr->entry)) + textpos;
libinfo->lib_list[id].build_date = ntohl(hdr->build_date);
if (flags & FLAT_FLAG_GOTPIC) {
for (rp = (u32 __user *)datapos; ; rp++) {
u32 addr, rp_val;
if (get_user(rp_val, rp))
return -EFAULT;
if (rp_val == 0xffffffff)
break;
if (rp_val) {
addr = calc_reloc(rp_val, libinfo, id, 0);
if (addr == RELOC_FAILED) {
ret = -ENOEXEC;
goto err;
}
if (put_user(addr, rp))
return -EFAULT;
}
}
}
if (rev > OLD_FLAT_VERSION) {
u32 __maybe_unused persistent = 0;
for (i = 0; i < relocs; i++) {
u32 addr, relval;
if (get_user(relval, reloc + i))
return -EFAULT;
relval = ntohl(relval);
if (flat_set_persistent(relval, &persistent))
continue;
addr = flat_get_relocate_addr(relval);
rp = (u32 __user *)calc_reloc(addr, libinfo, id, 1);
if (rp == (u32 __user *)RELOC_FAILED) {
ret = -ENOEXEC;
goto err;
}
ret = flat_get_addr_from_rp(rp, relval, flags,
&addr, &persistent);
if (unlikely(ret))
goto err;
if (addr != 0) {
if ((flags & FLAT_FLAG_GOTPIC) == 0)
addr = ntohl(addr);
addr = calc_reloc(addr, libinfo, id, 0);
if (addr == RELOC_FAILED) {
ret = -ENOEXEC;
goto err;
}
ret = flat_put_addr_at_rp(rp, addr, relval);
if (unlikely(ret))
goto err;
}
}
} else {
for (i = 0; i < relocs; i++) {
u32 relval;
if (get_user(relval, reloc + i))
return -EFAULT;
relval = ntohl(relval);
old_reloc(relval);
}
}
flush_icache_range(start_code, end_code);
if (clear_user((void __user *)(datapos + data_len), bss_len +
(memp + memp_size - stack_len -
libinfo->lib_list[id].start_brk) +
stack_len))
return -EFAULT;
return 0;
err:
return ret;
}
static int load_flat_shared_library(int id, struct lib_info *libs)
{
struct linux_binprm bprm;
int res;
char buf[16];
memset(&bprm, 0, sizeof(bprm));
sprintf(buf, "/lib/lib%d.so", id);
bprm.filename = buf;
bprm.file = open_exec(bprm.filename);
res = PTR_ERR(bprm.file);
if (IS_ERR(bprm.file))
return res;
bprm.cred = prepare_exec_creds();
res = -ENOMEM;
if (!bprm.cred)
goto out;
bprm.cred_prepared = 1;
res = prepare_binprm(&bprm);
if (!res)
res = load_flat_file(&bprm, libs, id, NULL);
abort_creds(bprm.cred);
out:
allow_write_access(bprm.file);
fput(bprm.file);
return res;
}
static int load_flat_binary(struct linux_binprm *bprm)
{
struct lib_info libinfo;
struct pt_regs *regs = current_pt_regs();
unsigned long stack_len = 0;
unsigned long start_addr;
int res;
int i, j;
memset(&libinfo, 0, sizeof(libinfo));
#ifndef CONFIG_MMU
stack_len += PAGE_SIZE * MAX_ARG_PAGES - bprm->p;
#endif
stack_len += (bprm->argc + 1) * sizeof(char *);
stack_len += (bprm->envc + 1) * sizeof(char *);
stack_len = ALIGN(stack_len, FLAT_STACK_ALIGN);
res = load_flat_file(bprm, &libinfo, 0, &stack_len);
if (res < 0)
return res;
for (i = 0; i < MAX_SHARED_LIBS; i++) {
if (!libinfo.lib_list[i].loaded)
continue;
for (j = 0; j < MAX_SHARED_LIBS; j++) {
unsigned long val = libinfo.lib_list[j].loaded ?
libinfo.lib_list[j].start_data : UNLOADED_LIB;
unsigned long __user *p = (unsigned long __user *)
libinfo.lib_list[i].start_data;
p -= j + 1;
if (put_user(val, p))
return -EFAULT;
}
}
install_exec_creds(bprm);
set_binfmt(&flat_format);
#ifdef CONFIG_MMU
res = setup_arg_pages(bprm, STACK_TOP, EXSTACK_DEFAULT);
if (!res)
res = create_flat_tables(bprm, bprm->p);
#else
current->mm->start_stack =
((current->mm->context.end_brk + stack_len + 3) & ~3) - 4;
pr_debug("sp=%lx\n", current->mm->start_stack);
res = transfer_args_to_stack(bprm, &current->mm->start_stack);
if (!res)
res = create_flat_tables(bprm, current->mm->start_stack);
#endif
if (res)
return res;
start_addr = libinfo.lib_list[0].entry;
#ifdef CONFIG_BINFMT_SHARED_FLAT
for (i = MAX_SHARED_LIBS-1; i > 0; i--) {
if (libinfo.lib_list[i].loaded) {
unsigned long __user *sp;
current->mm->start_stack -= sizeof(unsigned long);
sp = (unsigned long __user *)current->mm->start_stack;
__put_user(start_addr, sp);
start_addr = libinfo.lib_list[i].entry;
}
}
#endif
#ifdef FLAT_PLAT_INIT
FLAT_PLAT_INIT(regs);
#endif
pr_debug("start_thread(regs=0x%p, entry=0x%lx, start_stack=0x%lx)\n",
regs, start_addr, current->mm->start_stack);
start_thread(regs, start_addr, current->mm->start_stack);
return 0;
}
static int __init init_flat_binfmt(void)
{
register_binfmt(&flat_format);
return 0;
}
