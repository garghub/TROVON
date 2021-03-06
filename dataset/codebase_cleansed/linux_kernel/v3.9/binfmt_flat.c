static int flat_core_dump(struct coredump_params *cprm)
{
printk("Process %s:%d received signr %d and should have core dumped\n",
current->comm, current->pid, (int) cprm->siginfo->si_signo);
return(1);
}
static unsigned long create_flat_tables(
unsigned long pp,
struct linux_binprm * bprm)
{
unsigned long *argv,*envp;
unsigned long * sp;
char * p = (char*)pp;
int argc = bprm->argc;
int envc = bprm->envc;
char uninitialized_var(dummy);
sp = (unsigned long *)p;
sp -= (envc + argc + 2) + 1 + (flat_argvp_envp_on_stack() ? 2 : 0);
sp = (unsigned long *) ((unsigned long)sp & -FLAT_STACK_ALIGN);
argv = sp + 1 + (flat_argvp_envp_on_stack() ? 2 : 0);
envp = argv + (argc + 1);
if (flat_argvp_envp_on_stack()) {
put_user((unsigned long) envp, sp + 2);
put_user((unsigned long) argv, sp + 1);
}
put_user(argc, sp);
current->mm->arg_start = (unsigned long) p;
while (argc-->0) {
put_user((unsigned long) p, argv++);
do {
get_user(dummy, p); p++;
} while (dummy);
}
put_user((unsigned long) NULL, argv);
current->mm->arg_end = current->mm->env_start = (unsigned long) p;
while (envc-->0) {
put_user((unsigned long)p, envp); envp++;
do {
get_user(dummy, p); p++;
} while (dummy);
}
put_user((unsigned long) NULL, envp);
current->mm->env_end = (unsigned long) p;
return (unsigned long)sp;
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
DBG_FLT("decompress_exec(offset=%x,buf=%x,len=%x)\n",(int)offset, (int)dst, (int)len);
memset(&strm, 0, sizeof(strm));
strm.workspace = kmalloc(zlib_inflate_workspacesize(), GFP_KERNEL);
if (strm.workspace == NULL) {
DBG_FLT("binfmt_flat: no memory for decompress workspace\n");
return -ENOMEM;
}
buf = kmalloc(LBUFSIZE, GFP_KERNEL);
if (buf == NULL) {
DBG_FLT("binfmt_flat: no memory for read buffer\n");
retval = -ENOMEM;
goto out_free;
}
fpos = offset;
ret = bprm->file->f_op->read(bprm->file, buf, LBUFSIZE, &fpos);
strm.next_in = buf;
strm.avail_in = ret;
strm.total_in = 0;
retval = -ENOEXEC;
if (ret < 10) {
DBG_FLT("binfmt_flat: file too small?\n");
goto out_free_buf;
}
if ((buf[0] != 037) || ((buf[1] != 0213) && (buf[1] != 0236))) {
DBG_FLT("binfmt_flat: unknown compression magic?\n");
goto out_free_buf;
}
if (buf[2] != 8) {
DBG_FLT("binfmt_flat: unknown compression method?\n");
goto out_free_buf;
}
if ((buf[3] & ENCRYPTED) || (buf[3] & CONTINUATION) ||
(buf[3] & RESERVED)) {
DBG_FLT("binfmt_flat: unknown flags?\n");
goto out_free_buf;
}
ret = 10;
if (buf[3] & EXTRA_FIELD) {
ret += 2 + buf[10] + (buf[11] << 8);
if (unlikely(LBUFSIZE <= ret)) {
DBG_FLT("binfmt_flat: buffer overflow (EXTRA)?\n");
goto out_free_buf;
}
}
if (buf[3] & ORIG_NAME) {
while (ret < LBUFSIZE && buf[ret++] != 0)
;
if (unlikely(LBUFSIZE == ret)) {
DBG_FLT("binfmt_flat: buffer overflow (ORIG_NAME)?\n");
goto out_free_buf;
}
}
if (buf[3] & COMMENT) {
while (ret < LBUFSIZE && buf[ret++] != 0)
;
if (unlikely(LBUFSIZE == ret)) {
DBG_FLT("binfmt_flat: buffer overflow (COMMENT)?\n");
goto out_free_buf;
}
}
strm.next_in += ret;
strm.avail_in -= ret;
strm.next_out = dst;
strm.avail_out = len;
strm.total_out = 0;
if (zlib_inflateInit2(&strm, -MAX_WBITS) != Z_OK) {
DBG_FLT("binfmt_flat: zlib init failed?\n");
goto out_free_buf;
}
while ((ret = zlib_inflate(&strm, Z_NO_FLUSH)) == Z_OK) {
ret = bprm->file->f_op->read(bprm->file, buf, LBUFSIZE, &fpos);
if (ret <= 0)
break;
len -= ret;
strm.next_in = buf;
strm.avail_in = ret;
strm.total_in = 0;
}
if (ret < 0) {
DBG_FLT("binfmt_flat: decompression failed (%d), %s\n",
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
printk("BINFMT_FLAT: reference 0x%x to shared library %d",
(unsigned) r, id);
goto failed;
}
if (curid != id) {
if (internalp) {
printk("BINFMT_FLAT: reloc address 0x%x not in same module "
"(%d != %d)", (unsigned) r, curid, id);
goto failed;
} else if ( ! p->lib_list[id].loaded &&
IS_ERR_VALUE(load_flat_shared_library(id, p))) {
printk("BINFMT_FLAT: failed to load library %d", id);
goto failed;
}
if (p->lib_list[id].build_date && p->lib_list[curid].build_date &&
p->lib_list[curid].build_date < p->lib_list[id].build_date) {
printk("BINFMT_FLAT: library %d is younger than %d", id, curid);
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
printk("BINFMT_FLAT: reloc outside program 0x%x (0 - 0x%x/0x%x)",
(int) r,(int)(start_brk-start_data+text_len),(int)text_len);
goto failed;
}
if (r < text_len)
addr = r + start_code;
else
addr = r - text_len + start_data;
return(addr);
failed:
printk(", killing %s!\n", current->comm);
send_sig(SIGSEGV, current, 0);
return RELOC_FAILED;
}
void old_reloc(unsigned long rl)
{
#ifdef DEBUG
char *segment[] = { "TEXT", "DATA", "BSS", "*UNKNOWN*" };
#endif
flat_v2_reloc_t r;
unsigned long *ptr;
r.value = rl;
#if defined(CONFIG_COLDFIRE)
ptr = (unsigned long *) (current->mm->start_code + r.reloc.offset);
#else
ptr = (unsigned long *) (current->mm->start_data + r.reloc.offset);
#endif
#ifdef DEBUG
printk("Relocation of variable at DATASEG+%x "
"(address %p, currently %x) into segment %s\n",
r.reloc.offset, ptr, (int)*ptr, segment[r.reloc.type]);
#endif
switch (r.reloc.type) {
case OLD_FLAT_RELOC_TYPE_TEXT:
*ptr += current->mm->start_code;
break;
case OLD_FLAT_RELOC_TYPE_DATA:
*ptr += current->mm->start_data;
break;
case OLD_FLAT_RELOC_TYPE_BSS:
*ptr += current->mm->end_data;
break;
default:
printk("BINFMT_FLAT: Unknown relocation type=%x\n", r.reloc.type);
break;
}
#ifdef DEBUG
printk("Relocation became %x\n", (int)*ptr);
#endif
}
static int load_flat_file(struct linux_binprm * bprm,
struct lib_info *libinfo, int id, unsigned long *extra_stack)
{
struct flat_hdr * hdr;
unsigned long textpos = 0, datapos = 0, result;
unsigned long realdatastart = 0;
unsigned long text_len, data_len, bss_len, stack_len, flags;
unsigned long len, memp = 0;
unsigned long memp_size, extra, rlim;
unsigned long *reloc = 0, *rp;
struct inode *inode;
int i, rev, relocs = 0;
loff_t fpos;
unsigned long start_code, end_code;
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
if (strncmp(hdr->magic, "bFLT", 4)) {
ret = -ENOEXEC;
goto err;
}
if (flags & FLAT_FLAG_KTRACE)
printk("BINFMT_FLAT: Loading file: %s\n", bprm->filename);
if (rev != FLAT_VERSION && rev != OLD_FLAT_VERSION) {
printk("BINFMT_FLAT: bad flat file version 0x%x (supported "
"0x%lx and 0x%lx)\n",
rev, FLAT_VERSION, OLD_FLAT_VERSION);
ret = -ENOEXEC;
goto err;
}
if (rev == OLD_FLAT_VERSION && id != 0) {
printk("BINFMT_FLAT: shared libraries are not available before rev 0x%x\n",
(int) FLAT_VERSION);
ret = -ENOEXEC;
goto err;
}
if (rev == OLD_FLAT_VERSION && flat_old_ram_flag(flags))
flags = FLAT_FLAG_RAM;
#ifndef CONFIG_BINFMT_ZFLAT
if (flags & (FLAT_FLAG_GZIP|FLAT_FLAG_GZDATA)) {
printk("Support for ZFLAT executables is not enabled.\n");
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
result = flush_old_exec(bprm);
if (result) {
ret = result;
goto err;
}
set_personality(PER_LINUX_32BIT);
setup_new_exec(bprm);
}
extra = max_t(unsigned long, bss_len + stack_len,
relocs * sizeof(unsigned long));
if ((flags & (FLAT_FLAG_RAM|FLAT_FLAG_GZIP)) == 0) {
DBG_FLT("BINFMT_FLAT: ROM mapping of file (we hope)\n");
textpos = vm_mmap(bprm->file, 0, text_len, PROT_READ|PROT_EXEC,
MAP_PRIVATE|MAP_EXECUTABLE, 0);
if (!textpos || IS_ERR_VALUE(textpos)) {
if (!textpos)
textpos = (unsigned long) -ENOMEM;
printk("Unable to mmap process text, errno %d\n", (int)-textpos);
ret = textpos;
goto err;
}
len = data_len + extra + MAX_SHARED_LIBS * sizeof(unsigned long);
len = PAGE_ALIGN(len);
realdatastart = vm_mmap(0, 0, len,
PROT_READ|PROT_WRITE|PROT_EXEC, MAP_PRIVATE, 0);
if (realdatastart == 0 || IS_ERR_VALUE(realdatastart)) {
if (!realdatastart)
realdatastart = (unsigned long) -ENOMEM;
printk("Unable to allocate RAM for process data, errno %d\n",
(int)-realdatastart);
vm_munmap(textpos, text_len);
ret = realdatastart;
goto err;
}
datapos = ALIGN(realdatastart +
MAX_SHARED_LIBS * sizeof(unsigned long),
FLAT_DATA_ALIGN);
DBG_FLT("BINFMT_FLAT: Allocated data+bss+stack (%d bytes): %x\n",
(int)(data_len + bss_len + stack_len), (int)datapos);
fpos = ntohl(hdr->data_start);
#ifdef CONFIG_BINFMT_ZFLAT
if (flags & FLAT_FLAG_GZDATA) {
result = decompress_exec(bprm, fpos, (char *) datapos,
data_len + (relocs * sizeof(unsigned long)), 0);
} else
#endif
{
result = bprm->file->f_op->read(bprm->file, (char *) datapos,
data_len + (relocs * sizeof(unsigned long)), &fpos);
}
if (IS_ERR_VALUE(result)) {
printk("Unable to read data+bss, errno %d\n", (int)-result);
vm_munmap(textpos, text_len);
vm_munmap(realdatastart, len);
ret = result;
goto err;
}
reloc = (unsigned long *) (datapos+(ntohl(hdr->reloc_start)-text_len));
memp = realdatastart;
memp_size = len;
} else {
len = text_len + data_len + extra + MAX_SHARED_LIBS * sizeof(unsigned long);
len = PAGE_ALIGN(len);
textpos = vm_mmap(0, 0, len,
PROT_READ | PROT_EXEC | PROT_WRITE, MAP_PRIVATE, 0);
if (!textpos || IS_ERR_VALUE(textpos)) {
if (!textpos)
textpos = (unsigned long) -ENOMEM;
printk("Unable to allocate RAM for process text/data, errno %d\n",
(int)-textpos);
ret = textpos;
goto err;
}
realdatastart = textpos + ntohl(hdr->data_start);
datapos = ALIGN(realdatastart +
MAX_SHARED_LIBS * sizeof(unsigned long),
FLAT_DATA_ALIGN);
reloc = (unsigned long *)
(datapos + (ntohl(hdr->reloc_start) - text_len));
memp = textpos;
memp_size = len;
#ifdef CONFIG_BINFMT_ZFLAT
if (flags & FLAT_FLAG_GZIP) {
result = decompress_exec(bprm, sizeof (struct flat_hdr),
(((char *) textpos) + sizeof (struct flat_hdr)),
(text_len + data_len + (relocs * sizeof(unsigned long))
- sizeof (struct flat_hdr)),
0);
memmove((void *) datapos, (void *) realdatastart,
data_len + (relocs * sizeof(unsigned long)));
} else if (flags & FLAT_FLAG_GZDATA) {
fpos = 0;
result = bprm->file->f_op->read(bprm->file,
(char *) textpos, text_len, &fpos);
if (!IS_ERR_VALUE(result))
result = decompress_exec(bprm, text_len, (char *) datapos,
data_len + (relocs * sizeof(unsigned long)), 0);
}
else
#endif
{
fpos = 0;
result = bprm->file->f_op->read(bprm->file,
(char *) textpos, text_len, &fpos);
if (!IS_ERR_VALUE(result)) {
fpos = ntohl(hdr->data_start);
result = bprm->file->f_op->read(bprm->file, (char *) datapos,
data_len + (relocs * sizeof(unsigned long)), &fpos);
}
}
if (IS_ERR_VALUE(result)) {
printk("Unable to read code+data+bss, errno %d\n",(int)-result);
vm_munmap(textpos, text_len + data_len + extra +
MAX_SHARED_LIBS * sizeof(unsigned long));
ret = result;
goto err;
}
}
if (flags & FLAT_FLAG_KTRACE)
printk("Mapping is %x, Entry point is %x, data_start is %x\n",
(int)textpos, 0x00ffffff&ntohl(hdr->entry), ntohl(hdr->data_start));
start_code = textpos + sizeof (struct flat_hdr);
end_code = textpos + text_len;
if (id == 0) {
current->mm->start_code = start_code;
current->mm->end_code = end_code;
current->mm->start_data = datapos;
current->mm->end_data = datapos + data_len;
current->mm->start_brk = datapos + data_len + bss_len;
current->mm->brk = (current->mm->start_brk + 3) & ~3;
current->mm->context.end_brk = memp + memp_size - stack_len;
}
if (flags & FLAT_FLAG_KTRACE)
printk("%s %s: TEXT=%x-%x DATA=%x-%x BSS=%x-%x\n",
id ? "Lib" : "Load", bprm->filename,
(int) start_code, (int) end_code,
(int) datapos,
(int) (datapos + data_len),
(int) (datapos + data_len),
(int) (((datapos + data_len + bss_len) + 3) & ~3));
text_len -= sizeof(struct flat_hdr);
libinfo->lib_list[id].start_code = start_code;
libinfo->lib_list[id].start_data = datapos;
libinfo->lib_list[id].start_brk = datapos + data_len + bss_len;
libinfo->lib_list[id].text_len = text_len;
libinfo->lib_list[id].loaded = 1;
libinfo->lib_list[id].entry = (0x00ffffff & ntohl(hdr->entry)) + textpos;
libinfo->lib_list[id].build_date = ntohl(hdr->build_date);
if (flags & FLAT_FLAG_GOTPIC) {
for (rp = (unsigned long *)datapos; *rp != 0xffffffff; rp++) {
unsigned long addr;
if (*rp) {
addr = calc_reloc(*rp, libinfo, id, 0);
if (addr == RELOC_FAILED) {
ret = -ENOEXEC;
goto err;
}
*rp = addr;
}
}
}
if (rev > OLD_FLAT_VERSION) {
unsigned long persistent = 0;
for (i=0; i < relocs; i++) {
unsigned long addr, relval;
relval = ntohl(reloc[i]);
if (flat_set_persistent (relval, &persistent))
continue;
addr = flat_get_relocate_addr(relval);
rp = (unsigned long *) calc_reloc(addr, libinfo, id, 1);
if (rp == (unsigned long *)RELOC_FAILED) {
ret = -ENOEXEC;
goto err;
}
addr = flat_get_addr_from_rp(rp, relval, flags,
&persistent);
if (addr != 0) {
if ((flags & FLAT_FLAG_GOTPIC) == 0)
addr = ntohl(addr);
addr = calc_reloc(addr, libinfo, id, 0);
if (addr == RELOC_FAILED) {
ret = -ENOEXEC;
goto err;
}
flat_put_addr_at_rp(rp, addr, relval);
}
}
} else {
for (i=0; i < relocs; i++)
old_reloc(ntohl(reloc[i]));
}
flush_icache_range(start_code, end_code);
memset((void*)(datapos + data_len), 0, bss_len +
(memp + memp_size - stack_len -
libinfo->lib_list[id].start_brk) +
stack_len);
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
if (!IS_ERR_VALUE(res))
res = load_flat_file(&bprm, libs, id, NULL);
abort_creds(bprm.cred);
out:
allow_write_access(bprm.file);
fput(bprm.file);
return(res);
}
static int load_flat_binary(struct linux_binprm * bprm)
{
struct lib_info libinfo;
struct pt_regs *regs = current_pt_regs();
unsigned long p = bprm->p;
unsigned long stack_len;
unsigned long start_addr;
unsigned long *sp;
int res;
int i, j;
memset(&libinfo, 0, sizeof(libinfo));
#define TOP_OF_ARGS (PAGE_SIZE * MAX_ARG_PAGES - sizeof(void *))
stack_len = TOP_OF_ARGS - bprm->p;
stack_len += (bprm->argc + 1) * sizeof(char *);
stack_len += (bprm->envc + 1) * sizeof(char *);
stack_len += FLAT_STACK_ALIGN - 1;
res = load_flat_file(bprm, &libinfo, 0, &stack_len);
if (IS_ERR_VALUE(res))
return res;
for (i=0; i<MAX_SHARED_LIBS; i++)
if (libinfo.lib_list[i].loaded)
for (j=0; j<MAX_SHARED_LIBS; j++)
(-(j+1))[(unsigned long *)(libinfo.lib_list[i].start_data)] =
(libinfo.lib_list[j].loaded)?
libinfo.lib_list[j].start_data:UNLOADED_LIB;
install_exec_creds(bprm);
set_binfmt(&flat_format);
p = ((current->mm->context.end_brk + stack_len + 3) & ~3) - 4;
DBG_FLT("p=%x\n", (int)p);
for (i = TOP_OF_ARGS - 1; i >= bprm->p; i--)
* (char *) --p =
((char *) page_address(bprm->page[i/PAGE_SIZE]))[i % PAGE_SIZE];
sp = (unsigned long *) create_flat_tables(p, bprm);
start_addr = libinfo.lib_list[0].entry;
#ifdef CONFIG_BINFMT_SHARED_FLAT
for (i = MAX_SHARED_LIBS-1; i>0; i--) {
if (libinfo.lib_list[i].loaded) {
--sp; put_user(start_addr, sp);
start_addr = libinfo.lib_list[i].entry;
}
}
#endif
current->mm->start_stack = (unsigned long )sp;
#ifdef FLAT_PLAT_INIT
FLAT_PLAT_INIT(regs);
#endif
DBG_FLT("start_thread(regs=0x%x, entry=0x%x, start_stack=0x%x)\n",
(int)regs, (int)start_addr, (int)current->mm->start_stack);
start_thread(regs, start_addr, current->mm->start_stack);
return 0;
}
static int __init init_flat_binfmt(void)
{
register_binfmt(&flat_format);
return 0;
}
