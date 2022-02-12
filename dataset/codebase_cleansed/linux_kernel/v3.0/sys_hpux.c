unsigned long hpux_brk(unsigned long addr)
{
return sys_brk(addr + PAGE_SIZE);
}
int hpux_sbrk(void)
{
return -ENOSYS;
}
int hpux_nice(int priority_change)
{
return -ENOSYS;
}
int hpux_ptrace(void)
{
return -ENOSYS;
}
int hpux_wait(int __user *stat_loc)
{
return sys_waitpid(-1, stat_loc, 0);
}
int hpux_setpgrp(void)
{
return sys_setpgid(0,0);
}
int hpux_setpgrp3(void)
{
return hpux_setpgrp();
}
int hpux_sysconf(int which)
{
switch (which) {
case _SC_CPU_VERSION:
return CPU_PA_RISC1_1;
case _SC_OPEN_MAX:
return INT_MAX;
default:
return -EINVAL;
}
}
static int hpux_ustat(dev_t dev, struct hpux_ustat __user *ubuf)
{
struct super_block *s;
struct hpux_ustat tmp;
struct kstatfs sbuf;
int err = -EINVAL;
s = user_get_super(dev);
if (s == NULL)
goto out;
err = statfs_by_dentry(s->s_root, &sbuf);
drop_super(s);
if (err)
goto out;
memset(&tmp,0,sizeof(tmp));
tmp.f_tfree = (int32_t)sbuf.f_bfree;
tmp.f_tinode = (u_int32_t)sbuf.f_ffree;
tmp.f_blksize = (u_int32_t)sbuf.f_bsize;
err = copy_to_user(ubuf, &tmp, sizeof(tmp)) ? -EFAULT : 0;
out:
return err;
}
static int do_statfs_hpux(struct kstatfs *st, struct hpux_statfs __user *p)
{
struct hpux_statfs buf;
memset(&buf, 0, sizeof(buf));
buf.f_type = st->f_type;
buf.f_bsize = st->f_bsize;
buf.f_blocks = st->f_blocks;
buf.f_bfree = st->f_bfree;
buf.f_bavail = st->f_bavail;
buf.f_files = st->f_files;
buf.f_ffree = st->f_ffree;
buf.f_fsid[0] = st->f_fsid.val[0];
buf.f_fsid[1] = st->f_fsid.val[1];
if (copy_to_user(p, &buf, sizeof(buf)))
return -EFAULT;
return 0;
}
asmlinkage long hpux_statfs(const char __user *pathname,
struct hpux_statfs __user *buf)
{
struct kstatfs st;
int error = user_statfs(pathname, &st);
if (!error)
error = do_statfs_hpux(&st, buf);
return error;
}
asmlinkage long hpux_fstatfs(unsigned int fd, struct hpux_statfs __user * buf)
{
struct kstatfs st;
int error = fd_statfs(fd, &st);
if (!error)
error = do_statfs_hpux(&st, buf);
return error;
}
static int hpux_uname(struct hpux_utsname __user *name)
{
int error;
if (!name)
return -EFAULT;
if (!access_ok(VERIFY_WRITE,name,sizeof(struct hpux_utsname)))
return -EFAULT;
down_read(&uts_sem);
error = __copy_to_user(&name->sysname, &utsname()->sysname,
HPUX_UTSLEN - 1);
error |= __put_user(0, name->sysname + HPUX_UTSLEN - 1);
error |= __copy_to_user(&name->nodename, &utsname()->nodename,
HPUX_UTSLEN - 1);
error |= __put_user(0, name->nodename + HPUX_UTSLEN - 1);
error |= __copy_to_user(&name->release, &utsname()->release,
HPUX_UTSLEN - 1);
error |= __put_user(0, name->release + HPUX_UTSLEN - 1);
error |= __copy_to_user(&name->version, &utsname()->version,
HPUX_UTSLEN - 1);
error |= __put_user(0, name->version + HPUX_UTSLEN - 1);
error |= __copy_to_user(&name->machine, &utsname()->machine,
HPUX_UTSLEN - 1);
error |= __put_user(0, name->machine + HPUX_UTSLEN - 1);
up_read(&uts_sem);
#if 0
error |= __put_user(0,name->idnumber);
error |= __put_user(0,name->idnumber+HPUX_SNLEN-1);
#endif
error = error ? -EFAULT : 0;
return error;
}
int hpux_utssys(char __user *ubuf, int n, int type)
{
int len;
int error;
switch( type ) {
case 0:
return hpux_uname((struct hpux_utsname __user *)ubuf);
break ;
case 1:
return -EFAULT ;
break ;
case 2:
return hpux_ustat(new_decode_dev(n),
(struct hpux_ustat __user *)ubuf);
break;
case 3:
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
if ( n <= 0 )
return -EINVAL ;
len = (n <= __NEW_UTS_LEN) ? n : __NEW_UTS_LEN ;
return sys_sethostname(ubuf, len);
break ;
case 4:
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
if ( n <= 0 )
return -EINVAL ;
len = (n <= __NEW_UTS_LEN) ? n : __NEW_UTS_LEN ;
return sys_sethostname(ubuf, len);
break ;
case 5:
if ( n <= 0 )
return -EINVAL ;
return sys_gethostname(ubuf, n);
break ;
case 6:
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
if ( n <= 0 )
return -EINVAL ;
len = (n <= __NEW_UTS_LEN) ? n : __NEW_UTS_LEN ;
down_write(&uts_sem);
error = -EFAULT;
if (!copy_from_user(utsname()->sysname, ubuf, len)) {
utsname()->sysname[len] = 0;
error = 0;
}
up_write(&uts_sem);
return error;
break ;
case 7:
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
if ( n <= 0 )
return -EINVAL ;
len = (n <= __NEW_UTS_LEN) ? n : __NEW_UTS_LEN ;
down_write(&uts_sem);
error = -EFAULT;
if (!copy_from_user(utsname()->release, ubuf, len)) {
utsname()->release[len] = 0;
error = 0;
}
up_write(&uts_sem);
return error;
break ;
default:
return -EFAULT ;
}
}
int hpux_getdomainname(char __user *name, int len)
{
int nlen;
int err = -EFAULT;
down_read(&uts_sem);
nlen = strlen(utsname()->domainname) + 1;
if (nlen < len)
len = nlen;
if(len > __NEW_UTS_LEN)
goto done;
if(copy_to_user(name, utsname()->domainname, len))
goto done;
err = 0;
done:
up_read(&uts_sem);
return err;
}
int hpux_pipe(int *kstack_fildes)
{
return do_pipe_flags(kstack_fildes, 0);
}
int hpux_lockf(int fildes, int function, off_t size)
{
return 0;
}
int hpux_sysfs(int opcode, unsigned long arg1, unsigned long arg2)
{
char *fsname = NULL;
int len = 0;
int fstype;
printk(KERN_DEBUG "in hpux_sysfs\n");
printk(KERN_DEBUG "hpux_sysfs called with opcode = %d\n", opcode);
printk(KERN_DEBUG "hpux_sysfs called with arg1='%lx'\n", arg1);
if ( opcode == 1 ) {
char __user *user_fsname = (char __user *)arg1;
len = strlen_user(user_fsname);
printk(KERN_DEBUG "len of arg1 = %d\n", len);
if (len == 0)
return 0;
fsname = kmalloc(len, GFP_KERNEL);
if (!fsname) {
printk(KERN_DEBUG "failed to kmalloc fsname\n");
return 0;
}
if (copy_from_user(fsname, user_fsname, len)) {
printk(KERN_DEBUG "failed to copy_from_user fsname\n");
kfree(fsname);
return 0;
}
fsname[len] = '\0';
printk(KERN_DEBUG "that is '%s' as (char *)\n", fsname);
if ( !strcmp(fsname, "hfs") ) {
fstype = 0;
} else {
fstype = 0;
}
kfree(fsname);
printk(KERN_DEBUG "returning fstype=%d\n", fstype);
return fstype;
}
return 0;
}
int
hpux_unimplemented(unsigned long arg1,unsigned long arg2,unsigned long arg3,
unsigned long arg4,unsigned long arg5,unsigned long arg6,
unsigned long arg7,unsigned long sc_num)
{
const char *name = NULL;
if ( sc_num <= syscall_names_max && sc_num >= 0 ) {
name = syscall_names[sc_num];
}
if ( name ) {
printk(KERN_DEBUG "Unimplemented HP-UX syscall emulation. Syscall #%lu (%s)\n",
sc_num, name);
} else {
printk(KERN_DEBUG "Unimplemented unknown HP-UX syscall emulation. Syscall #%lu\n",
sc_num);
}
printk(KERN_DEBUG " Args: %lx %lx %lx %lx %lx %lx %lx\n",
arg1, arg2, arg3, arg4, arg5, arg6, arg7);
return -ENOSYS;
}
