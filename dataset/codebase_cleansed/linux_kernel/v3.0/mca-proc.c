static int get_mca_info_helper(struct mca_device *mca_dev, char *page, int len)
{
int j;
for(j=0; j<8; j++)
len += sprintf(page+len, "%02x ",
mca_dev ? mca_dev->pos[j] : 0xff);
len += sprintf(page+len, " %s\n", mca_dev ? mca_dev->name : "");
return len;
}
static int get_mca_info(char *page, char **start, off_t off,
int count, int *eof, void *data)
{
int i, len = 0;
if(MCA_bus) {
struct mca_device *mca_dev;
for(i=0; i<MCA_MAX_SLOT_NR; i++) {
mca_dev = mca_find_device_by_slot(i);
len += sprintf(page+len, "Slot %d: ", i+1);
len = get_mca_info_helper(mca_dev, page, len);
}
mca_dev = mca_find_device_by_slot(MCA_INTEGVIDEO);
len += sprintf(page+len, "Video : ");
len = get_mca_info_helper(mca_dev, page, len);
mca_dev = mca_find_device_by_slot(MCA_INTEGSCSI);
len += sprintf(page+len, "SCSI : ");
len = get_mca_info_helper(mca_dev, page, len);
mca_dev = mca_find_device_by_slot(MCA_MOTHERBOARD);
len += sprintf(page+len, "Planar: ");
len = get_mca_info_helper(mca_dev, page, len);
} else {
}
if (len <= off+count) *eof = 1;
*start = page + off;
len -= off;
if (len>count) len = count;
if (len<0) len = 0;
return len;
}
static int mca_default_procfn(char* buf, struct mca_device *mca_dev)
{
int len = 0, i;
int slot = mca_dev->slot;
if(slot < MCA_MAX_SLOT_NR) {
len += sprintf(buf+len, "Slot: %d\n", slot+1);
} else if(slot == MCA_INTEGSCSI) {
len += sprintf(buf+len, "Integrated SCSI Adapter\n");
} else if(slot == MCA_INTEGVIDEO) {
len += sprintf(buf+len, "Integrated Video Adapter\n");
} else if(slot == MCA_MOTHERBOARD) {
len += sprintf(buf+len, "Motherboard\n");
}
if (mca_dev->name[0]) {
len += sprintf(buf+len, "Adapter Name: %s\n",
mca_dev->name);
} else {
len += sprintf(buf+len, "Adapter Name: Unknown\n");
}
len += sprintf(buf+len, "Id: %02x%02x\n",
mca_dev->pos[1], mca_dev->pos[0]);
len += sprintf(buf+len, "Enabled: %s\nPOS: ",
mca_device_status(mca_dev) == MCA_ADAPTER_NORMAL ?
"Yes" : "No");
for(i=0; i<8; i++) {
len += sprintf(buf+len, "%02x ", mca_dev->pos[i]);
}
len += sprintf(buf+len, "\nDriver Installed: %s",
mca_device_claimed(mca_dev) ? "Yes" : "No");
buf[len++] = '\n';
buf[len] = 0;
return len;
}
static int get_mca_machine_info(char* page, char **start, off_t off,
int count, int *eof, void *data)
{
int len = 0;
len += sprintf(page+len, "Model Id: 0x%x\n", machine_id);
len += sprintf(page+len, "Submodel Id: 0x%x\n", machine_submodel_id);
len += sprintf(page+len, "BIOS Revision: 0x%x\n", BIOS_revision);
if (len <= off+count) *eof = 1;
*start = page + off;
len -= off;
if (len>count) len = count;
if (len<0) len = 0;
return len;
}
static int mca_read_proc(char *page, char **start, off_t off,
int count, int *eof, void *data)
{
struct mca_device *mca_dev = (struct mca_device *)data;
int len = 0;
len = mca_default_procfn(page, mca_dev);
if(mca_dev->procfn) {
len += mca_dev->procfn(page+len, mca_dev->slot,
mca_dev->proc_dev);
}
if (len <= off+count) *eof = 1;
*start = page + off;
len -= off;
if (len>count) len = count;
if (len<0) len = 0;
return len;
}
void __init mca_do_proc_init(void)
{
int i;
struct proc_dir_entry *proc_mca;
struct proc_dir_entry* node = NULL;
struct mca_device *mca_dev;
proc_mca = proc_mkdir("mca", NULL);
create_proc_read_entry("pos",0,proc_mca,get_mca_info,NULL);
create_proc_read_entry("machine",0,proc_mca,get_mca_machine_info,NULL);
for(i = 0; i < MCA_NUMADAPTERS; i++) {
enum MCA_AdapterStatus status;
mca_dev = mca_find_device_by_slot(i);
if(!mca_dev)
continue;
mca_dev->procfn = NULL;
if(i < MCA_MAX_SLOT_NR) sprintf(mca_dev->procname,"slot%d", i+1);
else if(i == MCA_INTEGVIDEO) sprintf(mca_dev->procname,"video");
else if(i == MCA_INTEGSCSI) sprintf(mca_dev->procname,"scsi");
else if(i == MCA_MOTHERBOARD) sprintf(mca_dev->procname,"planar");
status = mca_device_status(mca_dev);
if (status != MCA_ADAPTER_NORMAL &&
status != MCA_ADAPTER_DISABLED)
continue;
node = create_proc_read_entry(mca_dev->procname, 0, proc_mca,
mca_read_proc, (void *)mca_dev);
if(node == NULL) {
printk("Failed to allocate memory for MCA proc-entries!");
return;
}
}
}
void mca_set_adapter_procfn(int slot, MCA_ProcFn procfn, void* proc_dev)
{
struct mca_device *mca_dev = mca_find_device_by_slot(slot);
if(!mca_dev)
return;
mca_dev->procfn = procfn;
mca_dev->proc_dev = proc_dev;
}
