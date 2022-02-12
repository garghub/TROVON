static int nfsd_inject_set(void *op_ptr, u64 val)
{
struct nfsd_fault_inject_op *op = op_ptr;
if (val == 0)
printk(KERN_INFO "NFSD Fault Injection: %s (all)", op->file);
else
printk(KERN_INFO "NFSD Fault Injection: %s (n = %llu)", op->file, val);
op->func(val);
return 0;
}
static int nfsd_inject_get(void *data, u64 *val)
{
return 0;
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
