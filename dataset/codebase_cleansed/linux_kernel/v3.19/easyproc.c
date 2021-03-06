static struct proc_dir_entry *
createProcDir(char *name, struct proc_dir_entry *parent)
{
struct proc_dir_entry *p = proc_mkdir_mode(name, S_IFDIR, parent);
if (p == NULL)
ERRDRV("failed to create /proc directory %s", name);
return p;
}
static int proc_open_driver(struct inode *inode, struct file *file)
{
return single_open(file, seq_show_driver, PDE_DATA(inode));
}
static int proc_open_device(struct inode *inode, struct file *file)
{
return single_open(file, seq_show_device, PDE_DATA(inode));
}
static int proc_open_device_property(struct inode *inode, struct file *file)
{
return single_open(file, seq_show_device_property, PDE_DATA(inode));
}
void visor_easyproc_InitDriver(struct easyproc_driver_info *pdriver,
char *procId,
void (*show_driver_info)(struct seq_file *),
void (*show_device_info)(struct seq_file *,
void *))
{
memset(pdriver, 0, sizeof(struct easyproc_driver_info));
pdriver->ProcId = procId;
if (pdriver->ProcId == NULL)
ERRDRV("ProcId cannot be NULL (trouble ahead)!");
pdriver->Show_driver_info = show_driver_info;
pdriver->Show_device_info = show_device_info;
if (pdriver->ProcDir == NULL)
pdriver->ProcDir = createProcDir(pdriver->ProcId, NULL);
if ((pdriver->ProcDir != NULL) && (pdriver->ProcDriverDir == NULL))
pdriver->ProcDriverDir = createProcDir("driver",
pdriver->ProcDir);
if ((pdriver->ProcDir != NULL) && (pdriver->ProcDeviceDir == NULL))
pdriver->ProcDeviceDir = createProcDir("device",
pdriver->ProcDir);
if ((pdriver->ProcDriverDir != NULL) &&
(pdriver->ProcDriverDiagFile == NULL)) {
pdriver->ProcDriverDiagFile =
proc_create_data("diag", 0,
pdriver->ProcDriverDir,
&proc_fops_driver, pdriver);
if (pdriver->ProcDriverDiagFile == NULL)
ERRDRV("failed to register /proc/%s/driver/diag entry",
pdriver->ProcId);
}
}
void visor_easyproc_InitDriverEx(struct easyproc_driver_info *pdriver,
char *procId,
void (*show_driver_info)(struct seq_file *),
void (*show_device_info)(struct seq_file *,
void *),
void (*write_driver_info)(char *buf,
size_t count,
loff_t *ppos),
void (*write_device_info)(char *buf,
size_t count,
loff_t *ppos,
void *p))
{
visor_easyproc_InitDriver(pdriver, procId,
show_driver_info, show_device_info);
pdriver->Write_driver_info = write_driver_info;
pdriver->Write_device_info = write_device_info;
}
void visor_easyproc_DeInitDriver(struct easyproc_driver_info *pdriver)
{
if (pdriver->ProcDriverDiagFile != NULL) {
remove_proc_entry("diag", pdriver->ProcDriverDir);
pdriver->ProcDriverDiagFile = NULL;
}
if (pdriver->ProcDriverDir != NULL) {
remove_proc_entry("driver", pdriver->ProcDir);
pdriver->ProcDriverDir = NULL;
}
if (pdriver->ProcDeviceDir != NULL) {
remove_proc_entry("device", pdriver->ProcDir);
pdriver->ProcDeviceDir = NULL;
}
if (pdriver->ProcDir != NULL) {
remove_proc_entry(pdriver->ProcId, NULL);
pdriver->ProcDir = NULL;
}
pdriver->ProcId = NULL;
pdriver->Show_driver_info = NULL;
pdriver->Show_device_info = NULL;
pdriver->Write_driver_info = NULL;
pdriver->Write_device_info = NULL;
}
void visor_easyproc_InitDevice(struct easyproc_driver_info *pdriver,
struct easyproc_device_info *p, int devno,
void *devdata)
{
if ((pdriver->ProcDeviceDir != NULL) && (p->procDevicexDir == NULL)) {
char s[29];
sprintf(s, "%d", devno);
p->procDevicexDir = createProcDir(s, pdriver->ProcDeviceDir);
p->devno = devno;
}
p->devdata = devdata;
p->pdriver = pdriver;
p->devno = devno;
if ((p->procDevicexDir != NULL) && (p->procDevicexDiagFile == NULL)) {
p->procDevicexDiagFile =
proc_create_data("diag", 0, p->procDevicexDir,
&proc_fops_device, p);
if (p->procDevicexDiagFile == NULL)
ERRDEVX(devno, "failed to register /proc/%s/device/%d/diag entry",
pdriver->ProcId, devno
);
}
memset(&(p->device_property_info[0]), 0,
sizeof(p->device_property_info));
}
void visor_easyproc_CreateDeviceProperty(struct easyproc_device_info *p,
void (*show_property_info)
(struct seq_file *, void *),
char *property_name)
{
size_t i;
struct easyproc_device_property_info *px = NULL;
if (p->procDevicexDir == NULL) {
ERRDRV("state error");
return;
}
for (i = 0; i < ARRAY_SIZE(p->device_property_info); i++) {
if (p->device_property_info[i].procEntry == NULL) {
px = &(p->device_property_info[i]);
break;
}
}
if (!px) {
ERRDEVX(p->devno, "too many device properties");
return;
}
px->devdata = p->devdata;
px->pdriver = p->pdriver;
px->procEntry = proc_create_data(property_name, 0, p->procDevicexDir,
&proc_fops_device_property, px);
if (strlen(property_name)+1 > sizeof(px->property_name)) {
ERRDEVX(p->devno, "device property name %s too long",
property_name);
return;
}
strcpy(px->property_name, property_name);
if (px->procEntry == NULL) {
ERRDEVX(p->devno,
"failed to register /proc/%s/device/%d/%s entry",
p->pdriver->ProcId, p->devno, property_name);
return;
}
px->show_device_property_info = show_property_info;
}
void visor_easyproc_DeInitDevice(struct easyproc_driver_info *pdriver,
struct easyproc_device_info *p, int devno)
{
size_t i;
for (i = 0; i < ARRAY_SIZE(p->device_property_info); i++) {
if (p->device_property_info[i].procEntry != NULL) {
struct easyproc_device_property_info *px =
&(p->device_property_info[i]);
remove_proc_entry(px->property_name, p->procDevicexDir);
px->procEntry = NULL;
}
}
if (p->procDevicexDiagFile != NULL) {
remove_proc_entry("diag", p->procDevicexDir);
p->procDevicexDiagFile = NULL;
}
if (p->procDevicexDir != NULL) {
char s[29];
sprintf(s, "%d", devno);
remove_proc_entry(s, pdriver->ProcDeviceDir);
p->procDevicexDir = NULL;
}
p->devdata = NULL;
p->pdriver = NULL;
}
static int seq_show_driver(struct seq_file *seq, void *offset)
{
struct easyproc_driver_info *p =
(struct easyproc_driver_info *)(seq->private);
if (!p)
return 0;
(*(p->Show_driver_info))(seq);
return 0;
}
static int seq_show_device(struct seq_file *seq, void *offset)
{
struct easyproc_device_info *p =
(struct easyproc_device_info *)(seq->private);
if ((!p) || (!(p->pdriver)))
return 0;
(*(p->pdriver->Show_device_info))(seq, p->devdata);
return 0;
}
static int seq_show_device_property(struct seq_file *seq, void *offset)
{
struct easyproc_device_property_info *p =
(struct easyproc_device_property_info *)(seq->private);
if ((!p) || (!(p->show_device_property_info)))
return 0;
(*(p->show_device_property_info))(seq, p->devdata);
return 0;
}
static ssize_t proc_write_driver(struct file *file, const char __user *buffer,
size_t count, loff_t *ppos)
{
struct seq_file *seq = (struct seq_file *)file->private_data;
struct easyproc_driver_info *p = NULL;
char local_buf[256];
if (seq == NULL)
return 0;
p = (struct easyproc_driver_info *)(seq->private);
if ((!p) || (!(p->Write_driver_info)))
return 0;
if (count >= sizeof(local_buf))
return -ENOMEM;
if (copy_from_user(local_buf, buffer, count))
return -EFAULT;
local_buf[count] = '\0';
(*(p->Write_driver_info))(local_buf, count, ppos);
return count;
}
static ssize_t proc_write_device(struct file *file, const char __user *buffer,
size_t count, loff_t *ppos)
{
struct seq_file *seq = (struct seq_file *)file->private_data;
struct easyproc_device_info *p = NULL;
char local_buf[256];
if (seq == NULL)
return 0;
p = (struct easyproc_device_info *)(seq->private);
if ((!p) || (!(p->pdriver)) || (!(p->pdriver->Write_device_info)))
return 0;
if (count >= sizeof(local_buf))
return -ENOMEM;
if (copy_from_user(local_buf, buffer, count))
return -EFAULT;
local_buf[count] = '\0';
(*(p->pdriver->Write_device_info))(local_buf, count, ppos, p->devdata);
return count;
}
