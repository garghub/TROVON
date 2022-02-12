static int proc_viotape_show(struct seq_file *m, void *v)
{
int i;
seq_printf(m, "viotape driver version " VIOTAPE_VERSION "\n");
for (i = 0; i < viotape_numdev; i++) {
seq_printf(m, "viotape device %d is iSeries resource %10.10s"
"type %4.4s, model %3.3s\n",
i, viotape_unitinfo[i].rsrcname,
viotape_unitinfo[i].type,
viotape_unitinfo[i].model);
}
return 0;
}
static int proc_viotape_open(struct inode *inode, struct file *file)
{
return single_open(file, proc_viotape_show, NULL);
}
void get_dev_info(struct inode *ino, struct viot_devinfo_struct *devi)
{
devi->devno = iminor(ino) & 0x1F;
devi->mode = (iminor(ino) & 0x60) >> 5;
devi->rewind = (iminor(ino) & 0x80) == 0;
}
static void clear_op_struct_pool(void)
{
while (op_struct_list) {
struct op_struct *toFree = op_struct_list;
op_struct_list = op_struct_list->next;
kfree(toFree);
}
}
static int add_op_structs(int structs)
{
int i;
for (i = 0; i < structs; ++i) {
struct op_struct *new_struct =
kmalloc(sizeof(*new_struct), GFP_KERNEL);
if (!new_struct) {
clear_op_struct_pool();
return -ENOMEM;
}
new_struct->next = op_struct_list;
op_struct_list = new_struct;
}
return 0;
}
static struct op_struct *get_op_struct(void)
{
struct op_struct *retval;
unsigned long flags;
spin_lock_irqsave(&op_struct_list_lock, flags);
retval = op_struct_list;
if (retval)
op_struct_list = retval->next;
spin_unlock_irqrestore(&op_struct_list_lock, flags);
if (retval) {
memset(retval, 0, sizeof(*retval));
init_completion(&retval->com);
}
return retval;
}
static void free_op_struct(struct op_struct *op_struct)
{
unsigned long flags;
spin_lock_irqsave(&op_struct_list_lock, flags);
op_struct->next = op_struct_list;
op_struct_list = op_struct;
spin_unlock_irqrestore(&op_struct_list_lock, flags);
}
int tape_rc_to_errno(int tape_rc, char *operation, int tapeno)
{
const struct vio_error_entry *err;
if (tape_rc == 0)
return 0;
err = vio_lookup_rc(viotape_err_table, tape_rc);
printk(VIOTAPE_KERN_WARN "error(%s) 0x%04x on Device %d (%-10s): %s\n",
operation, tape_rc, tapeno,
viotape_unitinfo[tapeno].rsrcname, err->msg);
return -err->errno;
}
static ssize_t viotap_write(struct file *file, const char *buf,
size_t count, loff_t * ppos)
{
HvLpEvent_Rc hvrc;
unsigned short flags = file->f_flags;
int noblock = ((flags & O_NONBLOCK) != 0);
ssize_t ret;
struct viot_devinfo_struct devi;
struct op_struct *op = get_op_struct();
if (op == NULL)
return -ENOMEM;
get_dev_info(file->f_path.dentry->d_inode, &devi);
if (noblock) {
if (down_trylock(&reqSem)) {
ret = -EWOULDBLOCK;
goto free_op;
}
} else
down(&reqSem);
op->dev = tape_device[devi.devno];
op->buffer = dma_alloc_coherent(op->dev, count, &op->dmaaddr,
GFP_ATOMIC);
if (op->buffer == NULL) {
printk(VIOTAPE_KERN_WARN
"error allocating dma buffer for len %ld\n",
count);
ret = -EFAULT;
goto up_sem;
}
if (copy_from_user(op->buffer, buf, count)) {
printk(VIOTAPE_KERN_WARN "tape: error on copy from user\n");
ret = -EFAULT;
goto free_dma;
}
op->non_blocking = noblock;
init_completion(&op->com);
op->count = count;
hvrc = HvCallEvent_signalLpEventFast(viopath_hostLp,
HvLpEvent_Type_VirtualIo,
viomajorsubtype_tape | viotapewrite,
HvLpEvent_AckInd_DoAck, HvLpEvent_AckType_ImmediateAck,
viopath_sourceinst(viopath_hostLp),
viopath_targetinst(viopath_hostLp),
(u64)(unsigned long)op, VIOVERSION << 16,
((u64)devi.devno << 48) | op->dmaaddr, count, 0, 0);
if (hvrc != HvLpEvent_Rc_Good) {
printk(VIOTAPE_KERN_WARN "hv error on op %d\n",
(int)hvrc);
ret = -EIO;
goto free_dma;
}
if (noblock)
return count;
wait_for_completion(&op->com);
if (op->rc)
ret = tape_rc_to_errno(op->rc, "write", devi.devno);
else {
chg_state(devi.devno, VIOT_WRITING, file);
ret = op->count;
}
free_dma:
dma_free_coherent(op->dev, count, op->buffer, op->dmaaddr);
up_sem:
up(&reqSem);
free_op:
free_op_struct(op);
return ret;
}
static ssize_t viotap_read(struct file *file, char *buf, size_t count,
loff_t *ptr)
{
HvLpEvent_Rc hvrc;
unsigned short flags = file->f_flags;
struct op_struct *op = get_op_struct();
int noblock = ((flags & O_NONBLOCK) != 0);
ssize_t ret;
struct viot_devinfo_struct devi;
if (op == NULL)
return -ENOMEM;
get_dev_info(file->f_path.dentry->d_inode, &devi);
if (noblock) {
if (down_trylock(&reqSem)) {
ret = -EWOULDBLOCK;
goto free_op;
}
} else
down(&reqSem);
chg_state(devi.devno, VIOT_READING, file);
op->dev = tape_device[devi.devno];
op->buffer = dma_alloc_coherent(op->dev, count, &op->dmaaddr,
GFP_ATOMIC);
if (op->buffer == NULL) {
ret = -EFAULT;
goto up_sem;
}
op->count = count;
init_completion(&op->com);
hvrc = HvCallEvent_signalLpEventFast(viopath_hostLp,
HvLpEvent_Type_VirtualIo,
viomajorsubtype_tape | viotaperead,
HvLpEvent_AckInd_DoAck, HvLpEvent_AckType_ImmediateAck,
viopath_sourceinst(viopath_hostLp),
viopath_targetinst(viopath_hostLp),
(u64)(unsigned long)op, VIOVERSION << 16,
((u64)devi.devno << 48) | op->dmaaddr, count, 0, 0);
if (hvrc != HvLpEvent_Rc_Good) {
printk(VIOTAPE_KERN_WARN "tape hv error on op %d\n",
(int)hvrc);
ret = -EIO;
goto free_dma;
}
wait_for_completion(&op->com);
if (op->rc)
ret = tape_rc_to_errno(op->rc, "read", devi.devno);
else {
ret = op->count;
if (ret && copy_to_user(buf, op->buffer, ret)) {
printk(VIOTAPE_KERN_WARN "error on copy_to_user\n");
ret = -EFAULT;
}
}
free_dma:
dma_free_coherent(op->dev, count, op->buffer, op->dmaaddr);
up_sem:
up(&reqSem);
free_op:
free_op_struct(op);
return ret;
}
static int viotap_ioctl(struct inode *inode, struct file *file,
unsigned int cmd, unsigned long arg)
{
HvLpEvent_Rc hvrc;
int ret;
struct viot_devinfo_struct devi;
struct mtop mtc;
u32 myOp;
struct op_struct *op = get_op_struct();
if (op == NULL)
return -ENOMEM;
get_dev_info(file->f_path.dentry->d_inode, &devi);
down(&reqSem);
ret = -EINVAL;
switch (cmd) {
case MTIOCTOP:
ret = -EFAULT;
if (inode == NULL)
memcpy(&mtc, (void *) arg, sizeof(struct mtop));
else if (copy_from_user((char *)&mtc, (char *)arg,
sizeof(struct mtop)))
goto free_op;
ret = -EIO;
switch (mtc.mt_op) {
case MTRESET:
myOp = VIOTAPOP_RESET;
break;
case MTFSF:
myOp = VIOTAPOP_FSF;
break;
case MTBSF:
myOp = VIOTAPOP_BSF;
break;
case MTFSR:
myOp = VIOTAPOP_FSR;
break;
case MTBSR:
myOp = VIOTAPOP_BSR;
break;
case MTWEOF:
myOp = VIOTAPOP_WEOF;
break;
case MTREW:
myOp = VIOTAPOP_REW;
break;
case MTNOP:
myOp = VIOTAPOP_NOP;
break;
case MTEOM:
myOp = VIOTAPOP_EOM;
break;
case MTERASE:
myOp = VIOTAPOP_ERASE;
break;
case MTSETBLK:
myOp = VIOTAPOP_SETBLK;
break;
case MTSETDENSITY:
myOp = VIOTAPOP_SETDENSITY;
break;
case MTTELL:
myOp = VIOTAPOP_GETPOS;
break;
case MTSEEK:
myOp = VIOTAPOP_SETPOS;
break;
case MTSETPART:
myOp = VIOTAPOP_SETPART;
break;
case MTOFFL:
myOp = VIOTAPOP_UNLOAD;
break;
default:
printk(VIOTAPE_KERN_WARN "MTIOCTOP called "
"with invalid op 0x%x\n", mtc.mt_op);
goto free_op;
}
switch (mtc.mt_op) {
case MTFSF:
case MTBSF:
case MTFSR:
case MTBSR:
case MTTELL:
case MTSEEK:
case MTREW:
chg_state(devi.devno, VIOT_IDLE, file);
}
init_completion(&op->com);
hvrc = HvCallEvent_signalLpEventFast(viopath_hostLp,
HvLpEvent_Type_VirtualIo,
viomajorsubtype_tape | viotapeop,
HvLpEvent_AckInd_DoAck,
HvLpEvent_AckType_ImmediateAck,
viopath_sourceinst(viopath_hostLp),
viopath_targetinst(viopath_hostLp),
(u64)(unsigned long)op,
VIOVERSION << 16,
((u64)devi.devno << 48), 0,
(((u64)myOp) << 32) | mtc.mt_count, 0);
if (hvrc != HvLpEvent_Rc_Good) {
printk(VIOTAPE_KERN_WARN "hv error on op %d\n",
(int)hvrc);
goto free_op;
}
wait_for_completion(&op->com);
ret = tape_rc_to_errno(op->rc, "tape operation", devi.devno);
goto free_op;
case MTIOCGET:
ret = -EIO;
init_completion(&op->com);
hvrc = HvCallEvent_signalLpEventFast(viopath_hostLp,
HvLpEvent_Type_VirtualIo,
viomajorsubtype_tape | viotapegetstatus,
HvLpEvent_AckInd_DoAck,
HvLpEvent_AckType_ImmediateAck,
viopath_sourceinst(viopath_hostLp),
viopath_targetinst(viopath_hostLp),
(u64)(unsigned long)op, VIOVERSION << 16,
((u64)devi.devno << 48), 0, 0, 0);
if (hvrc != HvLpEvent_Rc_Good) {
printk(VIOTAPE_KERN_WARN "hv error on op %d\n",
(int)hvrc);
goto free_op;
}
wait_for_completion(&op->com);
ret = tape_rc_to_errno(op->rc, "get status", devi.devno);
free_op_struct(op);
up(&reqSem);
if ((ret == 0) && copy_to_user((void *)arg,
&viomtget[devi.devno],
sizeof(viomtget[0])))
ret = -EFAULT;
return ret;
case MTIOCPOS:
printk(VIOTAPE_KERN_WARN "Got an (unsupported) MTIOCPOS\n");
break;
default:
printk(VIOTAPE_KERN_WARN "got an unsupported ioctl 0x%0x\n",
cmd);
break;
}
free_op:
free_op_struct(op);
up(&reqSem);
return ret;
}
static long viotap_unlocked_ioctl(struct file *file,
unsigned int cmd, unsigned long arg)
{
long rc;
mutex_lock(&proc_viotape_mutex);
rc = viotap_ioctl(file->f_path.dentry->d_inode, file, cmd, arg);
mutex_unlock(&proc_viotape_mutex);
return rc;
}
static int viotap_open(struct inode *inode, struct file *file)
{
HvLpEvent_Rc hvrc;
struct viot_devinfo_struct devi;
int ret;
struct op_struct *op = get_op_struct();
if (op == NULL)
return -ENOMEM;
mutex_lock(&proc_viotape_mutex);
get_dev_info(file->f_path.dentry->d_inode, &devi);
if ((devi.devno >= viotape_numdev) || (devi.mode)) {
ret = -ENODEV;
goto free_op;
}
init_completion(&op->com);
hvrc = HvCallEvent_signalLpEventFast(viopath_hostLp,
HvLpEvent_Type_VirtualIo,
viomajorsubtype_tape | viotapeopen,
HvLpEvent_AckInd_DoAck, HvLpEvent_AckType_ImmediateAck,
viopath_sourceinst(viopath_hostLp),
viopath_targetinst(viopath_hostLp),
(u64)(unsigned long)op, VIOVERSION << 16,
((u64)devi.devno << 48), 0, 0, 0);
if (hvrc != 0) {
printk(VIOTAPE_KERN_WARN "bad rc on signalLpEvent %d\n",
(int) hvrc);
ret = -EIO;
goto free_op;
}
wait_for_completion(&op->com);
ret = tape_rc_to_errno(op->rc, "open", devi.devno);
free_op:
free_op_struct(op);
mutex_unlock(&proc_viotape_mutex);
return ret;
}
static int viotap_release(struct inode *inode, struct file *file)
{
HvLpEvent_Rc hvrc;
struct viot_devinfo_struct devi;
int ret = 0;
struct op_struct *op = get_op_struct();
if (op == NULL)
return -ENOMEM;
init_completion(&op->com);
get_dev_info(file->f_path.dentry->d_inode, &devi);
if (devi.devno >= viotape_numdev) {
ret = -ENODEV;
goto free_op;
}
chg_state(devi.devno, VIOT_IDLE, file);
if (devi.rewind) {
hvrc = HvCallEvent_signalLpEventFast(viopath_hostLp,
HvLpEvent_Type_VirtualIo,
viomajorsubtype_tape | viotapeop,
HvLpEvent_AckInd_DoAck,
HvLpEvent_AckType_ImmediateAck,
viopath_sourceinst(viopath_hostLp),
viopath_targetinst(viopath_hostLp),
(u64)(unsigned long)op, VIOVERSION << 16,
((u64)devi.devno << 48), 0,
((u64)VIOTAPOP_REW) << 32, 0);
wait_for_completion(&op->com);
tape_rc_to_errno(op->rc, "rewind", devi.devno);
}
hvrc = HvCallEvent_signalLpEventFast(viopath_hostLp,
HvLpEvent_Type_VirtualIo,
viomajorsubtype_tape | viotapeclose,
HvLpEvent_AckInd_DoAck, HvLpEvent_AckType_ImmediateAck,
viopath_sourceinst(viopath_hostLp),
viopath_targetinst(viopath_hostLp),
(u64)(unsigned long)op, VIOVERSION << 16,
((u64)devi.devno << 48), 0, 0, 0);
if (hvrc != 0) {
printk(VIOTAPE_KERN_WARN "bad rc on signalLpEvent %d\n",
(int) hvrc);
ret = -EIO;
goto free_op;
}
wait_for_completion(&op->com);
if (op->rc)
printk(VIOTAPE_KERN_WARN "close failed\n");
free_op:
free_op_struct(op);
return ret;
}
static void vioHandleTapeEvent(struct HvLpEvent *event)
{
int tapeminor;
struct op_struct *op;
struct viotapelpevent *tevent = (struct viotapelpevent *)event;
if (event == NULL) {
if (!viopath_isactive(viopath_hostLp)) {
}
return;
}
tapeminor = event->xSubtype & VIOMINOR_SUBTYPE_MASK;
op = (struct op_struct *)event->xCorrelationToken;
switch (tapeminor) {
case viotapeopen:
case viotapeclose:
op->rc = tevent->sub_type_result;
complete(&op->com);
break;
case viotaperead:
op->rc = tevent->sub_type_result;
op->count = tevent->len;
complete(&op->com);
break;
case viotapewrite:
if (op->non_blocking) {
dma_free_coherent(op->dev, op->count,
op->buffer, op->dmaaddr);
free_op_struct(op);
up(&reqSem);
} else {
op->rc = tevent->sub_type_result;
op->count = tevent->len;
complete(&op->com);
}
break;
case viotapeop:
case viotapegetpos:
case viotapesetpos:
case viotapegetstatus:
if (op) {
op->count = tevent->u.op.count;
op->rc = tevent->sub_type_result;
if (!op->non_blocking)
complete(&op->com);
}
break;
default:
printk(VIOTAPE_KERN_WARN "weird ack\n");
}
}
static int viotape_probe(struct vio_dev *vdev, const struct vio_device_id *id)
{
int i = vdev->unit_address;
int j;
struct device_node *node = vdev->dev.of_node;
if (i >= VIOTAPE_MAX_TAPE)
return -ENODEV;
if (!node)
return -ENODEV;
if (i >= viotape_numdev)
viotape_numdev = i + 1;
tape_device[i] = &vdev->dev;
viotape_unitinfo[i].rsrcname = of_get_property(node,
"linux,vio_rsrcname", NULL);
viotape_unitinfo[i].type = of_get_property(node, "linux,vio_type",
NULL);
viotape_unitinfo[i].model = of_get_property(node, "linux,vio_model",
NULL);
state[i].cur_part = 0;
for (j = 0; j < MAX_PARTITIONS; ++j)
state[i].part_stat_rwi[j] = VIOT_IDLE;
device_create(tape_class, NULL, MKDEV(VIOTAPE_MAJOR, i), NULL,
"iseries!vt%d", i);
device_create(tape_class, NULL, MKDEV(VIOTAPE_MAJOR, i | 0x80), NULL,
"iseries!nvt%d", i);
printk(VIOTAPE_KERN_INFO "tape iseries/vt%d is iSeries "
"resource %10.10s type %4.4s, model %3.3s\n",
i, viotape_unitinfo[i].rsrcname,
viotape_unitinfo[i].type, viotape_unitinfo[i].model);
return 0;
}
static int viotape_remove(struct vio_dev *vdev)
{
int i = vdev->unit_address;
device_destroy(tape_class, MKDEV(VIOTAPE_MAJOR, i | 0x80));
device_destroy(tape_class, MKDEV(VIOTAPE_MAJOR, i));
return 0;
}
int __init viotap_init(void)
{
int ret;
if (!firmware_has_feature(FW_FEATURE_ISERIES))
return -ENODEV;
op_struct_list = NULL;
if ((ret = add_op_structs(VIOTAPE_MAXREQ)) < 0) {
printk(VIOTAPE_KERN_WARN "couldn't allocate op structs\n");
return ret;
}
spin_lock_init(&op_struct_list_lock);
sema_init(&reqSem, VIOTAPE_MAXREQ);
if (viopath_hostLp == HvLpIndexInvalid) {
vio_set_hostlp();
if (viopath_hostLp == HvLpIndexInvalid) {
ret = -ENODEV;
goto clear_op;
}
}
ret = viopath_open(viopath_hostLp, viomajorsubtype_tape,
VIOTAPE_MAXREQ + 2);
if (ret) {
printk(VIOTAPE_KERN_WARN
"error on viopath_open to hostlp %d\n", ret);
ret = -EIO;
goto clear_op;
}
printk(VIOTAPE_KERN_INFO "vers " VIOTAPE_VERSION
", hosting partition %d\n", viopath_hostLp);
vio_setHandler(viomajorsubtype_tape, vioHandleTapeEvent);
ret = register_chrdev(VIOTAPE_MAJOR, "viotape", &viotap_fops);
if (ret < 0) {
printk(VIOTAPE_KERN_WARN "Error registering viotape device\n");
goto clear_handler;
}
tape_class = class_create(THIS_MODULE, "tape");
if (IS_ERR(tape_class)) {
printk(VIOTAPE_KERN_WARN "Unable to allocat class\n");
ret = PTR_ERR(tape_class);
goto unreg_chrdev;
}
ret = vio_register_driver(&viotape_driver);
if (ret)
goto unreg_class;
proc_create("iSeries/viotape", S_IFREG|S_IRUGO, NULL,
&proc_viotape_operations);
return 0;
unreg_class:
class_destroy(tape_class);
unreg_chrdev:
unregister_chrdev(VIOTAPE_MAJOR, "viotape");
clear_handler:
vio_clearHandler(viomajorsubtype_tape);
viopath_close(viopath_hostLp, viomajorsubtype_tape, VIOTAPE_MAXREQ + 2);
clear_op:
clear_op_struct_pool();
return ret;
}
static int chg_state(int index, unsigned char new_state, struct file *file)
{
unsigned char *cur_state =
&state[index].part_stat_rwi[state[index].cur_part];
int rc = 0;
if (*cur_state == new_state)
return 0;
if (*cur_state == VIOT_WRITING) {
struct mtop write_eof = { MTWEOF, 1 };
rc = viotap_ioctl(NULL, file, MTIOCTOP,
(unsigned long)&write_eof);
}
*cur_state = new_state;
return rc;
}
static void __exit viotap_exit(void)
{
remove_proc_entry("iSeries/viotape", NULL);
vio_unregister_driver(&viotape_driver);
class_destroy(tape_class);
unregister_chrdev(VIOTAPE_MAJOR, "viotape");
viopath_close(viopath_hostLp, viomajorsubtype_tape, VIOTAPE_MAXREQ + 2);
vio_clearHandler(viomajorsubtype_tape);
clear_op_struct_pool();
}
