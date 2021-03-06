void fhci_dbg_isr(struct fhci_hcd *fhci, int usb_er)
{
int i;
if (usb_er == -1) {
fhci->usb_irq_stat[12]++;
return;
}
for (i = 0; i < 12; ++i) {
if (usb_er & (1 << i))
fhci->usb_irq_stat[i]++;
}
}
static int fhci_dfs_regs_show(struct seq_file *s, void *v)
{
struct fhci_hcd *fhci = s->private;
struct qe_usb_ctlr __iomem *regs = fhci->regs;
seq_printf(s,
"mode: 0x%x\n" "addr: 0x%x\n"
"command: 0x%x\n" "ep0: 0x%x\n"
"event: 0x%x\n" "mask: 0x%x\n"
"status: 0x%x\n" "SOF timer: %d\n"
"frame number: %d\n"
"lines status: 0x%x\n",
in_8(&regs->usb_usmod), in_8(&regs->usb_usadr),
in_8(&regs->usb_uscom), in_be16(&regs->usb_usep[0]),
in_be16(&regs->usb_usber), in_be16(&regs->usb_usbmr),
in_8(&regs->usb_usbs), in_be16(&regs->usb_ussft),
in_be16(&regs->usb_usfrn),
fhci_ioports_check_bus_state(fhci));
return 0;
}
static int fhci_dfs_irq_stat_show(struct seq_file *s, void *v)
{
struct fhci_hcd *fhci = s->private;
int *usb_irq_stat = fhci->usb_irq_stat;
seq_printf(s,
"RXB: %d\n" "TXB: %d\n" "BSY: %d\n"
"SOF: %d\n" "TXE0: %d\n" "TXE1: %d\n"
"TXE2: %d\n" "TXE3: %d\n" "IDLE: %d\n"
"RESET: %d\n" "SFT: %d\n" "MSF: %d\n"
"IDLE_ONLY: %d\n",
usb_irq_stat[0], usb_irq_stat[1], usb_irq_stat[2],
usb_irq_stat[3], usb_irq_stat[4], usb_irq_stat[5],
usb_irq_stat[6], usb_irq_stat[7], usb_irq_stat[8],
usb_irq_stat[9], usb_irq_stat[10], usb_irq_stat[11],
usb_irq_stat[12]);
return 0;
}
static int fhci_dfs_regs_open(struct inode *inode, struct file *file)
{
return single_open(file, fhci_dfs_regs_show, inode->i_private);
}
static int fhci_dfs_irq_stat_open(struct inode *inode, struct file *file)
{
return single_open(file, fhci_dfs_irq_stat_show, inode->i_private);
}
void fhci_dfs_create(struct fhci_hcd *fhci)
{
struct device *dev = fhci_to_hcd(fhci)->self.controller;
fhci->dfs_root = debugfs_create_dir(dev_name(dev), usb_debug_root);
if (!fhci->dfs_root) {
WARN_ON(1);
return;
}
fhci->dfs_regs = debugfs_create_file("regs", S_IFREG | S_IRUGO,
fhci->dfs_root, fhci, &fhci_dfs_regs_fops);
fhci->dfs_irq_stat = debugfs_create_file("irq_stat",
S_IFREG | S_IRUGO, fhci->dfs_root, fhci,
&fhci_dfs_irq_stat_fops);
WARN_ON(!fhci->dfs_regs || !fhci->dfs_irq_stat);
}
void fhci_dfs_destroy(struct fhci_hcd *fhci)
{
if (!fhci->dfs_root)
return;
debugfs_remove(fhci->dfs_irq_stat);
debugfs_remove(fhci->dfs_regs);
debugfs_remove(fhci->dfs_root);
}
