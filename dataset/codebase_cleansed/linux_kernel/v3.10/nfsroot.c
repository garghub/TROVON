static int __init nfs_root_debug(char *__unused)
{
nfs_debug |= NFSDBG_ROOT | NFSDBG_MOUNT;
return 1;
}
static int __init nfs_root_setup(char *line)
{
ROOT_DEV = Root_NFS;
if (line[0] == '/' || line[0] == ',' || (line[0] >= '0' && line[0] <= '9')) {
strlcpy(nfs_root_parms, line, sizeof(nfs_root_parms));
} else {
size_t n = strlen(line) + sizeof(NFS_ROOT) - 1;
if (n >= sizeof(nfs_root_parms))
line[sizeof(nfs_root_parms) - sizeof(NFS_ROOT) - 2] = '\0';
sprintf(nfs_root_parms, NFS_ROOT, line);
}
root_server_addr = root_nfs_parse_addr(nfs_root_parms);
return 1;
}
static int __init root_nfs_copy(char *dest, const char *src,
const size_t destlen)
{
if (strlcpy(dest, src, destlen) > destlen)
return -1;
return 0;
}
static int __init root_nfs_cat(char *dest, const char *src,
const size_t destlen)
{
size_t len = strlen(dest);
if (len && dest[len - 1] != ',')
if (strlcat(dest, ",", destlen) > destlen)
return -1;
if (strlcat(dest, src, destlen) > destlen)
return -1;
return 0;
}
static int __init root_nfs_parse_options(char *incoming, char *exppath,
const size_t exppathlen)
{
char *p;
p = strsep(&incoming, ",");
if (*p != '\0' && strcmp(p, "default") != 0)
if (root_nfs_copy(exppath, p, exppathlen))
return -1;
if (incoming != NULL && *incoming != '\0')
if (root_nfs_cat(nfs_root_options, incoming,
sizeof(nfs_root_options)))
return -1;
return 0;
}
static int __init root_nfs_data(char *cmdline)
{
char mand_options[sizeof("nolock,addr=") + INET_ADDRSTRLEN + 1];
int len, retval = -1;
char *tmp = NULL;
const size_t tmplen = sizeof(nfs_export_path);
tmp = kzalloc(tmplen, GFP_KERNEL);
if (tmp == NULL)
goto out_nomem;
strcpy(tmp, NFS_ROOT);
if (root_server_path[0] != '\0') {
dprintk("Root-NFS: DHCPv4 option 17: %s\n",
root_server_path);
if (root_nfs_parse_options(root_server_path, tmp, tmplen))
goto out_optionstoolong;
}
if (cmdline[0] != '\0') {
dprintk("Root-NFS: nfsroot=%s\n", cmdline);
if (root_nfs_parse_options(cmdline, tmp, tmplen))
goto out_optionstoolong;
}
snprintf(mand_options, sizeof(mand_options), "nolock,addr=%pI4",
&servaddr);
if (root_nfs_cat(nfs_root_options, mand_options,
sizeof(nfs_root_options)))
goto out_optionstoolong;
len = snprintf(nfs_export_path, sizeof(nfs_export_path),
tmp, utsname()->nodename);
if (len > (int)sizeof(nfs_export_path))
goto out_devnametoolong;
len = snprintf(nfs_root_device, sizeof(nfs_root_device),
"%pI4:%s", &servaddr, nfs_export_path);
if (len > (int)sizeof(nfs_root_device))
goto out_devnametoolong;
retval = 0;
out:
kfree(tmp);
return retval;
out_nomem:
printk(KERN_ERR "Root-NFS: could not allocate memory\n");
goto out;
out_optionstoolong:
printk(KERN_ERR "Root-NFS: mount options string too long\n");
goto out;
out_devnametoolong:
printk(KERN_ERR "Root-NFS: root device name too long.\n");
goto out;
}
int __init nfs_root_data(char **root_device, char **root_data)
{
servaddr = root_server_addr;
if (servaddr == htonl(INADDR_NONE)) {
printk(KERN_ERR "Root-NFS: no NFS server address\n");
return -1;
}
if (root_nfs_data(nfs_root_parms) < 0)
return -1;
*root_device = nfs_root_device;
*root_data = nfs_root_options;
return 0;
}
