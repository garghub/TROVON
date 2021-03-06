static void agp_3_5_dev_list_insert(struct list_head *head, struct list_head *new)
{
struct agp_3_5_dev *cur, *n = list_entry(new, struct agp_3_5_dev, list);
struct list_head *pos;
list_for_each(pos, head) {
cur = list_entry(pos, struct agp_3_5_dev, list);
if (cur->maxbw > n->maxbw)
break;
}
list_add_tail(new, pos);
}
static void agp_3_5_dev_list_sort(struct agp_3_5_dev *list, unsigned int ndevs)
{
struct agp_3_5_dev *cur;
struct pci_dev *dev;
struct list_head *pos, *tmp, *head = &list->list, *start = head->next;
u32 nistat;
INIT_LIST_HEAD(head);
for (pos=start; pos!=head; ) {
cur = list_entry(pos, struct agp_3_5_dev, list);
dev = cur->dev;
pci_read_config_dword(dev, cur->capndx+AGPNISTAT, &nistat);
cur->maxbw = (nistat >> 16) & 0xff;
tmp = pos;
pos = pos->next;
agp_3_5_dev_list_insert(head, tmp);
}
}
static int agp_3_5_isochronous_node_enable(struct agp_bridge_data *bridge,
struct agp_3_5_dev *dev_list, unsigned int ndevs)
{
struct isoch_data {
u32 maxbw;
u32 n;
u32 y;
u32 l;
u32 rq;
struct agp_3_5_dev *dev;
};
struct pci_dev *td = bridge->dev, *dev;
struct list_head *head = &dev_list->list, *pos;
struct agp_3_5_dev *cur;
struct isoch_data *master, target;
unsigned int cdev = 0;
u32 mnistat, tnistat, tstatus, mcmd;
u16 tnicmd, mnicmd;
u8 mcapndx;
u32 tot_bw = 0, tot_n = 0, tot_rq = 0, y_max, rq_isoch, rq_async;
u32 step, rem, rem_isoch, rem_async;
int ret = 0;
if ((master = kmalloc(ndevs * sizeof(*master), GFP_KERNEL)) == NULL) {
ret = -ENOMEM;
goto get_out;
}
agp_3_5_dev_list_sort(dev_list, ndevs);
pci_read_config_dword(td, bridge->capndx+AGPNISTAT, &tnistat);
pci_read_config_dword(td, bridge->capndx+AGPSTAT, &tstatus);
target.maxbw = (tnistat >> 16) & 0xff;
target.n = (tnistat >> 8) & 0xff;
target.y = (tnistat >> 6) & 0x3;
target.l = (tnistat >> 3) & 0x7;
target.rq = (tstatus >> 24) & 0xff;
y_max = target.y;
list_for_each(pos, head) {
cur = list_entry(pos, struct agp_3_5_dev, list);
dev = cur->dev;
mcapndx = cur->capndx;
pci_read_config_dword(dev, cur->capndx+AGPNISTAT, &mnistat);
master[cdev].maxbw = (mnistat >> 16) & 0xff;
master[cdev].n = (mnistat >> 8) & 0xff;
master[cdev].y = (mnistat >> 6) & 0x3;
master[cdev].dev = cur;
tot_bw += master[cdev].maxbw;
y_max = max(y_max, master[cdev].y);
cdev++;
}
if (tot_bw > target.maxbw) {
dev_err(&td->dev, "isochronous bandwidth required "
"by AGP 3.0 devices exceeds that which is supported by "
"the AGP 3.0 bridge!\n");
ret = -ENODEV;
goto free_and_exit;
}
target.y = y_max;
pci_read_config_word(td, bridge->capndx+AGPNICMD, &tnicmd);
tnicmd &= ~(0x3 << 6);
tnicmd |= target.y << 6;
pci_write_config_word(td, bridge->capndx+AGPNICMD, tnicmd);
pci_read_config_dword(td, bridge->capndx+AGPNISTAT, &tnistat);
target.n = (tnistat >> 8) & 0xff;
for (cdev=0; cdev<ndevs; cdev++) {
master[cdev].y = target.y;
master[cdev].n = master[cdev].maxbw / (master[cdev].y + 1);
tot_n += master[cdev].n;
}
if (tot_n > target.n) {
dev_err(&td->dev, "number of isochronous "
"transactions per period required by AGP 3.0 devices "
"exceeds that which is supported by the AGP 3.0 "
"bridge!\n");
ret = -ENODEV;
goto free_and_exit;
}
rem = target.n - tot_n;
for (cdev=0; cdev<ndevs; cdev++) {
master[cdev].rq = master[cdev].n;
if (master[cdev].y > 0x1)
master[cdev].rq *= (1 << (master[cdev].y - 1));
tot_rq += master[cdev].rq;
}
master[ndevs-1].n += rem;
rq_isoch = (target.y > 0x1) ? target.n * (1 << (target.y - 1)) : target.n;
rq_async = target.rq - rq_isoch;
if (tot_rq > rq_isoch) {
dev_err(&td->dev, "number of request queue slots "
"required by the isochronous bandwidth requested by "
"AGP 3.0 devices exceeds the number provided by the "
"AGP 3.0 bridge!\n");
ret = -ENODEV;
goto free_and_exit;
}
step = rq_async / ndevs;
rem_async = step + (rq_async % ndevs);
rem_isoch = rq_isoch - tot_rq;
for (cdev=0; cdev<ndevs; cdev++) {
cur = master[cdev].dev;
dev = cur->dev;
mcapndx = cur->capndx;
master[cdev].rq += (cdev == ndevs - 1)
? (rem_async + rem_isoch) : step;
pci_read_config_word(dev, cur->capndx+AGPNICMD, &mnicmd);
pci_read_config_dword(dev, cur->capndx+AGPCMD, &mcmd);
mnicmd &= ~(0xff << 8);
mnicmd &= ~(0x3 << 6);
mcmd &= ~(0xff << 24);
mnicmd |= master[cdev].n << 8;
mnicmd |= master[cdev].y << 6;
mcmd |= master[cdev].rq << 24;
pci_write_config_dword(dev, cur->capndx+AGPCMD, mcmd);
pci_write_config_word(dev, cur->capndx+AGPNICMD, mnicmd);
}
free_and_exit:
kfree(master);
get_out:
return ret;
}
static void agp_3_5_nonisochronous_node_enable(struct agp_bridge_data *bridge,
struct agp_3_5_dev *dev_list, unsigned int ndevs)
{
struct agp_3_5_dev *cur;
struct list_head *head = &dev_list->list, *pos;
u32 tstatus, mcmd;
u32 trq, mrq, rem;
unsigned int cdev = 0;
pci_read_config_dword(bridge->dev, bridge->capndx+AGPSTAT, &tstatus);
trq = (tstatus >> 24) & 0xff;
mrq = trq / ndevs;
rem = mrq + (trq % ndevs);
for (pos=head->next; cdev<ndevs; cdev++, pos=pos->next) {
cur = list_entry(pos, struct agp_3_5_dev, list);
pci_read_config_dword(cur->dev, cur->capndx+AGPCMD, &mcmd);
mcmd &= ~(0xff << 24);
mcmd |= ((cdev == ndevs - 1) ? rem : mrq) << 24;
pci_write_config_dword(cur->dev, cur->capndx+AGPCMD, mcmd);
}
}
int agp_3_5_enable(struct agp_bridge_data *bridge)
{
struct pci_dev *td = bridge->dev, *dev = NULL;
u8 mcapndx;
u32 isoch, arqsz;
u32 tstatus, mstatus, ncapid;
u32 mmajor;
u16 mpstat;
struct agp_3_5_dev *dev_list, *cur;
struct list_head *head, *pos;
unsigned int ndevs = 0;
int ret = 0;
pci_read_config_dword(td, bridge->capndx+AGPSTAT, &tstatus);
isoch = (tstatus >> 17) & 0x1;
if (isoch == 0)
return -ENODEV;
arqsz = (tstatus >> 13) & 0x7;
if ((dev_list = kmalloc(sizeof(*dev_list), GFP_KERNEL)) == NULL) {
ret = -ENOMEM;
goto get_out;
}
head = &dev_list->list;
INIT_LIST_HEAD(head);
for_each_pci_dev(dev) {
mcapndx = pci_find_capability(dev, PCI_CAP_ID_AGP);
if (mcapndx == 0)
continue;
switch ((dev->class >>8) & 0xff00) {
case 0x0600:
continue;
case 0x0001:
if (mcapndx != 0) {
dev_info(&td->dev, "wacky, found unclassified AGP device %s [%04x/%04x]\n",
pci_name(dev),
dev->vendor, dev->device);
}
continue;
case 0x0300:
case 0x0400:
if ((cur = kmalloc(sizeof(*cur), GFP_KERNEL)) == NULL) {
ret = -ENOMEM;
goto free_and_exit;
}
cur->dev = dev;
pos = &cur->list;
list_add(pos, head);
ndevs++;
continue;
default:
continue;
}
}
list_for_each(pos, head) {
cur = list_entry(pos, struct agp_3_5_dev, list);
dev = cur->dev;
pci_read_config_word(dev, PCI_STATUS, &mpstat);
if ((mpstat & PCI_STATUS_CAP_LIST) == 0)
continue;
pci_read_config_byte(dev, PCI_CAPABILITY_LIST, &mcapndx);
if (mcapndx != 0) {
do {
pci_read_config_dword(dev, mcapndx, &ncapid);
if ((ncapid & 0xff) != 2)
mcapndx = (ncapid >> 8) & 0xff;
}
while (((ncapid & 0xff) != 2) && (mcapndx != 0));
}
if (mcapndx == 0) {
dev_err(&td->dev, "woah! Non-AGP device %s on "
"secondary bus of AGP 3.5 bridge!\n",
pci_name(dev));
ret = -ENODEV;
goto free_and_exit;
}
mmajor = (ncapid >> AGP_MAJOR_VERSION_SHIFT) & 0xf;
if (mmajor < 3) {
dev_err(&td->dev, "woah! AGP 2.0 device %s on "
"secondary bus of AGP 3.5 bridge operating "
"with AGP 3.0 electricals!\n", pci_name(dev));
ret = -ENODEV;
goto free_and_exit;
}
cur->capndx = mcapndx;
pci_read_config_dword(dev, cur->capndx+AGPSTAT, &mstatus);
if (((mstatus >> 3) & 0x1) == 0) {
dev_err(&td->dev, "woah! AGP 3.x device %s not "
"operating in AGP 3.x mode on secondary bus "
"of AGP 3.5 bridge operating with AGP 3.0 "
"electricals!\n", pci_name(dev));
ret = -ENODEV;
goto free_and_exit;
}
}
if (isoch) {
ret = agp_3_5_isochronous_node_enable(bridge, dev_list, ndevs);
if (ret) {
dev_info(&td->dev, "something bad happened setting "
"up isochronous xfers; falling back to "
"non-isochronous xfer mode\n");
} else {
goto free_and_exit;
}
}
agp_3_5_nonisochronous_node_enable(bridge, dev_list, ndevs);
free_and_exit:
for (pos=head->next; pos!=head; ) {
cur = list_entry(pos, struct agp_3_5_dev, list);
pos = pos->next;
kfree(cur);
}
kfree(dev_list);
get_out:
return ret;
}
