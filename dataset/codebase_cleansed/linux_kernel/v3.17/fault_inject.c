static ssize_t fault_inject_read(struct file *file, char __user *buf,
size_t len, loff_t *ppos)
{
static u64 val;
char read_buf[25];
size_t size;
loff_t pos = *ppos;
struct nfsd_fault_inject_op *op = file_inode(file)->i_private;
if (!pos)
val = op->get();
size = scnprintf(read_buf, sizeof(read_buf), "%llu\n", val);
return simple_read_from_buffer(buf, len, ppos, read_buf, size);
}
static ssize_t fault_inject_write(struct file *file, const char __user *buf,
size_t len, loff_t *ppos)
{
char write_buf[INET6_ADDRSTRLEN];
size_t size = min(sizeof(write_buf) - 1, len);
struct net *net = current->nsproxy->net_ns;
struct sockaddr_storage sa;
struct nfsd_fault_inject_op *op = file_inode(file)->i_private;
u64 val;
char *nl;
if (copy_from_user(write_buf, buf, size))
return -EFAULT;
write_buf[size] = '\0';
nl = strchr(write_buf, '\n');
if (nl) {
size = nl - write_buf;
*nl = '\0';
}
size = rpc_pton(net, write_buf, size, (struct sockaddr *)&sa, sizeof(sa));
if (size > 0) {
val = op->set_clnt(&sa, size);
if (val)
pr_info("NFSD [%s]: Client %s had %llu state object(s)\n",
op->file, write_buf, val);
} else {
val = simple_strtoll(write_buf, NULL, 0);
if (val == 0)
pr_info("NFSD Fault Injection: %s (all)", op->file);
else
pr_info("NFSD Fault Injection: %s (n = %llu)",
op->file, val);
val = op->set_val(val);
pr_info("NFSD: %s: found %llu", op->file, val);
}
return len;
}
void nfsd_fault_inject_cleanup(void)
{
debugfs_remove_recursive(debug_dir);
}
int nfsd_fault_inject_init(void)
{
unsigned int i;
struct nfsd_fault_inject_op *op;
umode_t mode = S_IFREG | S_IRUSR | S_IWUSR;
debug_dir = debugfs_create_dir("nfsd", NULL);
if (!debug_dir)
goto fail;
for (i = 0; i < NUM_INJECT_OPS; i++) {
op = &inject_ops[i];
if (!debugfs_create_file(op->file, mode, debug_dir, op, &fops_nfsd))
goto fail;
}
return 0;
fail:
nfsd_fault_inject_cleanup();
return -ENOMEM;
}
