int libcfs_kkuc_msg_put(struct file *filp, void *payload)
{
struct kuc_hdr *kuch = (struct kuc_hdr *)payload;
ssize_t count = kuch->kuc_msglen;
loff_t offset = 0;
mm_segment_t fs;
int rc = -ENOSYS;
if (filp == NULL || IS_ERR(filp))
return -EBADF;
if (kuch->kuc_magic != KUC_MAGIC) {
CERROR("KernelComm: bad magic %x\n", kuch->kuc_magic);
return -ENOSYS;
}
fs = get_fs();
set_fs(KERNEL_DS);
while (count > 0) {
rc = vfs_write(filp, (void __force __user *)payload,
count, &offset);
if (rc < 0)
break;
count -= rc;
payload += rc;
rc = 0;
}
set_fs(fs);
if (rc < 0)
CWARN("message send failed (%d)\n", rc);
else
CDEBUG(D_KUC, "Sent message rc=%d, fp=%p\n", rc, filp);
return rc;
}
int libcfs_kkuc_group_add(struct file *filp, int uid, int group, __u32 data)
{
struct kkuc_reg *reg;
if (group > KUC_GRP_MAX) {
CDEBUG(D_WARNING, "Kernelcomm: bad group %d\n", group);
return -EINVAL;
}
if (filp == NULL)
return -EBADF;
reg = kmalloc(sizeof(*reg), 0);
if (reg == NULL)
return -ENOMEM;
reg->kr_fp = filp;
reg->kr_uid = uid;
reg->kr_data = data;
down_write(&kg_sem);
if (kkuc_groups[group].next == NULL)
INIT_LIST_HEAD(&kkuc_groups[group]);
list_add(&reg->kr_chain, &kkuc_groups[group]);
up_write(&kg_sem);
CDEBUG(D_KUC, "Added uid=%d fp=%p to group %d\n", uid, filp, group);
return 0;
}
int libcfs_kkuc_group_rem(int uid, int group)
{
struct kkuc_reg *reg, *next;
if (kkuc_groups[group].next == NULL)
return 0;
if (uid == 0) {
struct kuc_hdr lh;
lh.kuc_magic = KUC_MAGIC;
lh.kuc_transport = KUC_TRANSPORT_GENERIC;
lh.kuc_msgtype = KUC_MSG_SHUTDOWN;
lh.kuc_msglen = sizeof(lh);
libcfs_kkuc_group_put(group, &lh);
}
down_write(&kg_sem);
list_for_each_entry_safe(reg, next, &kkuc_groups[group], kr_chain) {
if ((uid == 0) || (uid == reg->kr_uid)) {
list_del(&reg->kr_chain);
CDEBUG(D_KUC, "Removed uid=%d fp=%p from group %d\n",
reg->kr_uid, reg->kr_fp, group);
if (reg->kr_fp != NULL)
fput(reg->kr_fp);
kfree(reg);
}
}
up_write(&kg_sem);
return 0;
}
int libcfs_kkuc_group_put(int group, void *payload)
{
struct kkuc_reg *reg;
int rc = 0;
int one_success = 0;
down_read(&kg_sem);
list_for_each_entry(reg, &kkuc_groups[group], kr_chain) {
if (reg->kr_fp != NULL) {
rc = libcfs_kkuc_msg_put(reg->kr_fp, payload);
if (rc == 0)
one_success = 1;
else if (rc == -EPIPE) {
fput(reg->kr_fp);
reg->kr_fp = NULL;
}
}
}
up_read(&kg_sem);
if (one_success)
rc = 0;
return rc;
}
int libcfs_kkuc_group_foreach(int group, libcfs_kkuc_cb_t cb_func,
void *cb_arg)
{
struct kkuc_reg *reg;
int rc = 0;
if (group > KUC_GRP_MAX) {
CDEBUG(D_WARNING, "Kernelcomm: bad group %d\n", group);
return -EINVAL;
}
if (kkuc_groups[group].next == NULL)
return 0;
down_read(&kg_sem);
list_for_each_entry(reg, &kkuc_groups[group], kr_chain) {
if (reg->kr_fp != NULL)
rc = cb_func(reg->kr_data, cb_arg);
}
up_read(&kg_sem);
return rc;
}
