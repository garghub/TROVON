static inline void __iomem *
qla4_8xxx_pci_base_offsetfset(struct scsi_qla_host *ha, unsigned long off)
{
if ((off < ha->first_page_group_end) &&
(off >= ha->first_page_group_start))
return (void __iomem *)(ha->nx_pcibase + off);
return NULL;
}
static void
qla4_8xxx_crb_addr_transform_setup(void)
{
qla4_8xxx_crb_addr_transform(XDMA);
qla4_8xxx_crb_addr_transform(TIMR);
qla4_8xxx_crb_addr_transform(SRE);
qla4_8xxx_crb_addr_transform(SQN3);
qla4_8xxx_crb_addr_transform(SQN2);
qla4_8xxx_crb_addr_transform(SQN1);
qla4_8xxx_crb_addr_transform(SQN0);
qla4_8xxx_crb_addr_transform(SQS3);
qla4_8xxx_crb_addr_transform(SQS2);
qla4_8xxx_crb_addr_transform(SQS1);
qla4_8xxx_crb_addr_transform(SQS0);
qla4_8xxx_crb_addr_transform(RPMX7);
qla4_8xxx_crb_addr_transform(RPMX6);
qla4_8xxx_crb_addr_transform(RPMX5);
qla4_8xxx_crb_addr_transform(RPMX4);
qla4_8xxx_crb_addr_transform(RPMX3);
qla4_8xxx_crb_addr_transform(RPMX2);
qla4_8xxx_crb_addr_transform(RPMX1);
qla4_8xxx_crb_addr_transform(RPMX0);
qla4_8xxx_crb_addr_transform(ROMUSB);
qla4_8xxx_crb_addr_transform(SN);
qla4_8xxx_crb_addr_transform(QMN);
qla4_8xxx_crb_addr_transform(QMS);
qla4_8xxx_crb_addr_transform(PGNI);
qla4_8xxx_crb_addr_transform(PGND);
qla4_8xxx_crb_addr_transform(PGN3);
qla4_8xxx_crb_addr_transform(PGN2);
qla4_8xxx_crb_addr_transform(PGN1);
qla4_8xxx_crb_addr_transform(PGN0);
qla4_8xxx_crb_addr_transform(PGSI);
qla4_8xxx_crb_addr_transform(PGSD);
qla4_8xxx_crb_addr_transform(PGS3);
qla4_8xxx_crb_addr_transform(PGS2);
qla4_8xxx_crb_addr_transform(PGS1);
qla4_8xxx_crb_addr_transform(PGS0);
qla4_8xxx_crb_addr_transform(PS);
qla4_8xxx_crb_addr_transform(PH);
qla4_8xxx_crb_addr_transform(NIU);
qla4_8xxx_crb_addr_transform(I2Q);
qla4_8xxx_crb_addr_transform(EG);
qla4_8xxx_crb_addr_transform(MN);
qla4_8xxx_crb_addr_transform(MS);
qla4_8xxx_crb_addr_transform(CAS2);
qla4_8xxx_crb_addr_transform(CAS1);
qla4_8xxx_crb_addr_transform(CAS0);
qla4_8xxx_crb_addr_transform(CAM);
qla4_8xxx_crb_addr_transform(C2C1);
qla4_8xxx_crb_addr_transform(C2C0);
qla4_8xxx_crb_addr_transform(SMB);
qla4_8xxx_crb_addr_transform(OCM0);
qla4_8xxx_crb_addr_transform(I2C0);
qla4_8xxx_crb_table_initialized = 1;
}
static void
qla4_8xxx_pci_set_crbwindow_2M(struct scsi_qla_host *ha, ulong *off)
{
u32 win_read;
ha->crb_win = CRB_HI(*off);
writel(ha->crb_win,
(void __iomem *)(CRB_WINDOW_2M + ha->nx_pcibase));
win_read = readl((void __iomem *)(CRB_WINDOW_2M + ha->nx_pcibase));
if (win_read != ha->crb_win) {
DEBUG2(ql4_printk(KERN_INFO, ha,
"%s: Written crbwin (0x%x) != Read crbwin (0x%x),"
" off=0x%lx\n", __func__, ha->crb_win, win_read, *off));
}
*off = (*off & MASK(16)) + CRB_INDIRECT_2M + ha->nx_pcibase;
}
void
qla4_8xxx_wr_32(struct scsi_qla_host *ha, ulong off, u32 data)
{
unsigned long flags = 0;
int rv;
rv = qla4_8xxx_pci_get_crb_addr_2M(ha, &off);
BUG_ON(rv == -1);
if (rv == 1) {
write_lock_irqsave(&ha->hw_lock, flags);
qla4_8xxx_crb_win_lock(ha);
qla4_8xxx_pci_set_crbwindow_2M(ha, &off);
}
writel(data, (void __iomem *)off);
if (rv == 1) {
qla4_8xxx_crb_win_unlock(ha);
write_unlock_irqrestore(&ha->hw_lock, flags);
}
}
int
qla4_8xxx_rd_32(struct scsi_qla_host *ha, ulong off)
{
unsigned long flags = 0;
int rv;
u32 data;
rv = qla4_8xxx_pci_get_crb_addr_2M(ha, &off);
BUG_ON(rv == -1);
if (rv == 1) {
write_lock_irqsave(&ha->hw_lock, flags);
qla4_8xxx_crb_win_lock(ha);
qla4_8xxx_pci_set_crbwindow_2M(ha, &off);
}
data = readl((void __iomem *)off);
if (rv == 1) {
qla4_8xxx_crb_win_unlock(ha);
write_unlock_irqrestore(&ha->hw_lock, flags);
}
return data;
}
int qla4_8xxx_crb_win_lock(struct scsi_qla_host *ha)
{
int i;
int done = 0, timeout = 0;
while (!done) {
done = qla4_8xxx_rd_32(ha, QLA82XX_PCIE_REG(PCIE_SEM7_LOCK));
if (done == 1)
break;
if (timeout >= CRB_WIN_LOCK_TIMEOUT)
return -1;
timeout++;
if (!in_interrupt())
schedule();
else {
for (i = 0; i < 20; i++)
cpu_relax();
}
}
qla4_8xxx_wr_32(ha, QLA82XX_CRB_WIN_LOCK_ID, ha->func_num);
return 0;
}
void qla4_8xxx_crb_win_unlock(struct scsi_qla_host *ha)
{
qla4_8xxx_rd_32(ha, QLA82XX_PCIE_REG(PCIE_SEM7_UNLOCK));
}
int qla4_8xxx_idc_lock(struct scsi_qla_host *ha)
{
int i;
int done = 0, timeout = 0;
while (!done) {
done = qla4_8xxx_rd_32(ha, QLA82XX_PCIE_REG(PCIE_SEM5_LOCK));
if (done == 1)
break;
if (timeout >= IDC_LOCK_TIMEOUT)
return -1;
timeout++;
if (!in_interrupt())
schedule();
else {
for (i = 0; i < 20; i++)
cpu_relax();
}
}
return 0;
}
void qla4_8xxx_idc_unlock(struct scsi_qla_host *ha)
{
qla4_8xxx_rd_32(ha, QLA82XX_PCIE_REG(PCIE_SEM5_UNLOCK));
}
int
qla4_8xxx_pci_get_crb_addr_2M(struct scsi_qla_host *ha, ulong *off)
{
struct crb_128M_2M_sub_block_map *m;
if (*off >= QLA82XX_CRB_MAX)
return -1;
if (*off >= QLA82XX_PCI_CAMQM && (*off < QLA82XX_PCI_CAMQM_2M_END)) {
*off = (*off - QLA82XX_PCI_CAMQM) +
QLA82XX_PCI_CAMQM_2M_BASE + ha->nx_pcibase;
return 0;
}
if (*off < QLA82XX_PCI_CRBSPACE)
return -1;
*off -= QLA82XX_PCI_CRBSPACE;
m = &crb_128M_2M_map[CRB_BLK(*off)].sub_block[CRB_SUBBLK(*off)];
if (m->valid && (m->start_128M <= *off) && (m->end_128M > *off)) {
*off = *off + m->start_2M - m->start_128M + ha->nx_pcibase;
return 0;
}
return 1;
}
static unsigned long
qla4_8xxx_pci_mem_bound_check(struct scsi_qla_host *ha,
unsigned long long addr, int size)
{
if (!QLA82XX_ADDR_IN_RANGE(addr, QLA82XX_ADDR_DDR_NET,
QLA82XX_ADDR_DDR_NET_MAX) ||
!QLA82XX_ADDR_IN_RANGE(addr + size - 1,
QLA82XX_ADDR_DDR_NET, QLA82XX_ADDR_DDR_NET_MAX) ||
((size != 1) && (size != 2) && (size != 4) && (size != 8))) {
return 0;
}
return 1;
}
static unsigned long
qla4_8xxx_pci_set_window(struct scsi_qla_host *ha, unsigned long long addr)
{
int window;
u32 win_read;
if (QLA82XX_ADDR_IN_RANGE(addr, QLA82XX_ADDR_DDR_NET,
QLA82XX_ADDR_DDR_NET_MAX)) {
window = MN_WIN(addr);
ha->ddr_mn_window = window;
qla4_8xxx_wr_32(ha, ha->mn_win_crb |
QLA82XX_PCI_CRBSPACE, window);
win_read = qla4_8xxx_rd_32(ha, ha->mn_win_crb |
QLA82XX_PCI_CRBSPACE);
if ((win_read << 17) != window) {
ql4_printk(KERN_WARNING, ha,
"%s: Written MNwin (0x%x) != Read MNwin (0x%x)\n",
__func__, window, win_read);
}
addr = GET_MEM_OFFS_2M(addr) + QLA82XX_PCI_DDR_NET;
} else if (QLA82XX_ADDR_IN_RANGE(addr, QLA82XX_ADDR_OCM0,
QLA82XX_ADDR_OCM0_MAX)) {
unsigned int temp1;
if ((addr & 0x00ff800) == 0xff800) {
printk("%s: QM access not handled.\n", __func__);
addr = -1UL;
}
window = OCM_WIN(addr);
ha->ddr_mn_window = window;
qla4_8xxx_wr_32(ha, ha->mn_win_crb |
QLA82XX_PCI_CRBSPACE, window);
win_read = qla4_8xxx_rd_32(ha, ha->mn_win_crb |
QLA82XX_PCI_CRBSPACE);
temp1 = ((window & 0x1FF) << 7) |
((window & 0x0FFFE0000) >> 17);
if (win_read != temp1) {
printk("%s: Written OCMwin (0x%x) != Read"
" OCMwin (0x%x)\n", __func__, temp1, win_read);
}
addr = GET_MEM_OFFS_2M(addr) + QLA82XX_PCI_OCM0_2M;
} else if (QLA82XX_ADDR_IN_RANGE(addr, QLA82XX_ADDR_QDR_NET,
QLA82XX_P3_ADDR_QDR_NET_MAX)) {
window = MS_WIN(addr);
ha->qdr_sn_window = window;
qla4_8xxx_wr_32(ha, ha->ms_win_crb |
QLA82XX_PCI_CRBSPACE, window);
win_read = qla4_8xxx_rd_32(ha,
ha->ms_win_crb | QLA82XX_PCI_CRBSPACE);
if (win_read != window) {
printk("%s: Written MSwin (0x%x) != Read "
"MSwin (0x%x)\n", __func__, window, win_read);
}
addr = GET_MEM_OFFS_2M(addr) + QLA82XX_PCI_QDR_NET;
} else {
if ((qla4_8xxx_pci_set_window_warning_count++ < 8) ||
(qla4_8xxx_pci_set_window_warning_count%64 == 0)) {
printk("%s: Warning:%s Unknown address range!\n",
__func__, DRIVER_NAME);
}
addr = -1UL;
}
return addr;
}
static int qla4_8xxx_pci_is_same_window(struct scsi_qla_host *ha,
unsigned long long addr)
{
int window;
unsigned long long qdr_max;
qdr_max = QLA82XX_P3_ADDR_QDR_NET_MAX;
if (QLA82XX_ADDR_IN_RANGE(addr, QLA82XX_ADDR_DDR_NET,
QLA82XX_ADDR_DDR_NET_MAX)) {
BUG();
} else if (QLA82XX_ADDR_IN_RANGE(addr, QLA82XX_ADDR_OCM0,
QLA82XX_ADDR_OCM0_MAX)) {
return 1;
} else if (QLA82XX_ADDR_IN_RANGE(addr, QLA82XX_ADDR_OCM1,
QLA82XX_ADDR_OCM1_MAX)) {
return 1;
} else if (QLA82XX_ADDR_IN_RANGE(addr, QLA82XX_ADDR_QDR_NET,
qdr_max)) {
window = ((addr - QLA82XX_ADDR_QDR_NET) >> 22) & 0x3f;
if (ha->qdr_sn_window == window)
return 1;
}
return 0;
}
static inline __u64 readq(const volatile void __iomem *addr)
{
const volatile u32 __iomem *p = addr;
u32 low, high;
low = readl(p);
high = readl(p + 1);
return low + ((u64)high << 32);
}
static inline void writeq(__u64 val, volatile void __iomem *addr)
{
writel(val, addr);
writel(val >> 32, addr+4);
}
static int qla4_8xxx_pci_mem_read_direct(struct scsi_qla_host *ha,
u64 off, void *data, int size)
{
unsigned long flags;
void __iomem *addr;
int ret = 0;
u64 start;
void __iomem *mem_ptr = NULL;
unsigned long mem_base;
unsigned long mem_page;
write_lock_irqsave(&ha->hw_lock, flags);
start = qla4_8xxx_pci_set_window(ha, off);
if ((start == -1UL) ||
(qla4_8xxx_pci_is_same_window(ha, off + size - 1) == 0)) {
write_unlock_irqrestore(&ha->hw_lock, flags);
printk(KERN_ERR"%s out of bound pci memory access. "
"offset is 0x%llx\n", DRIVER_NAME, off);
return -1;
}
addr = qla4_8xxx_pci_base_offsetfset(ha, start);
if (!addr) {
write_unlock_irqrestore(&ha->hw_lock, flags);
mem_base = pci_resource_start(ha->pdev, 0);
mem_page = start & PAGE_MASK;
if (mem_page != ((start + size - 1) & PAGE_MASK))
mem_ptr = ioremap(mem_base + mem_page, PAGE_SIZE * 2);
else
mem_ptr = ioremap(mem_base + mem_page, PAGE_SIZE);
if (mem_ptr == NULL) {
*(u8 *)data = 0;
return -1;
}
addr = mem_ptr;
addr += start & (PAGE_SIZE - 1);
write_lock_irqsave(&ha->hw_lock, flags);
}
switch (size) {
case 1:
*(u8 *)data = readb(addr);
break;
case 2:
*(u16 *)data = readw(addr);
break;
case 4:
*(u32 *)data = readl(addr);
break;
case 8:
*(u64 *)data = readq(addr);
break;
default:
ret = -1;
break;
}
write_unlock_irqrestore(&ha->hw_lock, flags);
if (mem_ptr)
iounmap(mem_ptr);
return ret;
}
static int
qla4_8xxx_pci_mem_write_direct(struct scsi_qla_host *ha, u64 off,
void *data, int size)
{
unsigned long flags;
void __iomem *addr;
int ret = 0;
u64 start;
void __iomem *mem_ptr = NULL;
unsigned long mem_base;
unsigned long mem_page;
write_lock_irqsave(&ha->hw_lock, flags);
start = qla4_8xxx_pci_set_window(ha, off);
if ((start == -1UL) ||
(qla4_8xxx_pci_is_same_window(ha, off + size - 1) == 0)) {
write_unlock_irqrestore(&ha->hw_lock, flags);
printk(KERN_ERR"%s out of bound pci memory access. "
"offset is 0x%llx\n", DRIVER_NAME, off);
return -1;
}
addr = qla4_8xxx_pci_base_offsetfset(ha, start);
if (!addr) {
write_unlock_irqrestore(&ha->hw_lock, flags);
mem_base = pci_resource_start(ha->pdev, 0);
mem_page = start & PAGE_MASK;
if (mem_page != ((start + size - 1) & PAGE_MASK))
mem_ptr = ioremap(mem_base + mem_page, PAGE_SIZE*2);
else
mem_ptr = ioremap(mem_base + mem_page, PAGE_SIZE);
if (mem_ptr == NULL)
return -1;
addr = mem_ptr;
addr += start & (PAGE_SIZE - 1);
write_lock_irqsave(&ha->hw_lock, flags);
}
switch (size) {
case 1:
writeb(*(u8 *)data, addr);
break;
case 2:
writew(*(u16 *)data, addr);
break;
case 4:
writel(*(u32 *)data, addr);
break;
case 8:
writeq(*(u64 *)data, addr);
break;
default:
ret = -1;
break;
}
write_unlock_irqrestore(&ha->hw_lock, flags);
if (mem_ptr)
iounmap(mem_ptr);
return ret;
}
static unsigned long
qla4_8xxx_decode_crb_addr(unsigned long addr)
{
int i;
unsigned long base_addr, offset, pci_base;
if (!qla4_8xxx_crb_table_initialized)
qla4_8xxx_crb_addr_transform_setup();
pci_base = ADDR_ERROR;
base_addr = addr & 0xfff00000;
offset = addr & 0x000fffff;
for (i = 0; i < MAX_CRB_XFORM; i++) {
if (crb_addr_xform[i] == base_addr) {
pci_base = i << 20;
break;
}
}
if (pci_base == ADDR_ERROR)
return pci_base;
else
return pci_base + offset;
}
static int
qla4_8xxx_rom_lock(struct scsi_qla_host *ha)
{
int i;
int done = 0, timeout = 0;
while (!done) {
done = qla4_8xxx_rd_32(ha, QLA82XX_PCIE_REG(PCIE_SEM2_LOCK));
if (done == 1)
break;
if (timeout >= qla4_8xxx_rom_lock_timeout) {
ql4_printk(KERN_WARNING, ha,
"%s: Failed to acquire rom lock", __func__);
return -1;
}
timeout++;
if (!in_interrupt())
schedule();
else {
for (i = 0; i < 20; i++)
cpu_relax();
}
}
qla4_8xxx_wr_32(ha, QLA82XX_ROM_LOCK_ID, ROM_LOCK_DRIVER);
return 0;
}
static void
qla4_8xxx_rom_unlock(struct scsi_qla_host *ha)
{
qla4_8xxx_rd_32(ha, QLA82XX_PCIE_REG(PCIE_SEM2_UNLOCK));
}
static int
qla4_8xxx_wait_rom_done(struct scsi_qla_host *ha)
{
long timeout = 0;
long done = 0 ;
while (done == 0) {
done = qla4_8xxx_rd_32(ha, QLA82XX_ROMUSB_GLB_STATUS);
done &= 2;
timeout++;
if (timeout >= rom_max_timeout) {
printk("%s: Timeout reached waiting for rom done",
DRIVER_NAME);
return -1;
}
}
return 0;
}
static int
qla4_8xxx_do_rom_fast_read(struct scsi_qla_host *ha, int addr, int *valp)
{
qla4_8xxx_wr_32(ha, QLA82XX_ROMUSB_ROM_ADDRESS, addr);
qla4_8xxx_wr_32(ha, QLA82XX_ROMUSB_ROM_DUMMY_BYTE_CNT, 0);
qla4_8xxx_wr_32(ha, QLA82XX_ROMUSB_ROM_ABYTE_CNT, 3);
qla4_8xxx_wr_32(ha, QLA82XX_ROMUSB_ROM_INSTR_OPCODE, 0xb);
if (qla4_8xxx_wait_rom_done(ha)) {
printk("%s: Error waiting for rom done\n", DRIVER_NAME);
return -1;
}
qla4_8xxx_wr_32(ha, QLA82XX_ROMUSB_ROM_DUMMY_BYTE_CNT, 0);
udelay(10);
qla4_8xxx_wr_32(ha, QLA82XX_ROMUSB_ROM_ABYTE_CNT, 0);
*valp = qla4_8xxx_rd_32(ha, QLA82XX_ROMUSB_ROM_RDATA);
return 0;
}
static int
qla4_8xxx_rom_fast_read(struct scsi_qla_host *ha, int addr, int *valp)
{
int ret, loops = 0;
while ((qla4_8xxx_rom_lock(ha) != 0) && (loops < 50000)) {
udelay(100);
loops++;
}
if (loops >= 50000) {
printk("%s: qla4_8xxx_rom_lock failed\n", DRIVER_NAME);
return -1;
}
ret = qla4_8xxx_do_rom_fast_read(ha, addr, valp);
qla4_8xxx_rom_unlock(ha);
return ret;
}
static int
qla4_8xxx_pinit_from_rom(struct scsi_qla_host *ha, int verbose)
{
int addr, val;
int i ;
struct crb_addr_pair *buf;
unsigned long off;
unsigned offset, n;
struct crb_addr_pair {
long addr;
long data;
};
qla4_8xxx_rom_lock(ha);
qla4_8xxx_wr_32(ha, QLA82XX_CRB_I2Q + 0x10, 0x0);
qla4_8xxx_wr_32(ha, QLA82XX_CRB_I2Q + 0x14, 0x0);
qla4_8xxx_wr_32(ha, QLA82XX_CRB_I2Q + 0x18, 0x0);
qla4_8xxx_wr_32(ha, QLA82XX_CRB_I2Q + 0x1c, 0x0);
qla4_8xxx_wr_32(ha, QLA82XX_CRB_I2Q + 0x20, 0x0);
qla4_8xxx_wr_32(ha, QLA82XX_CRB_I2Q + 0x24, 0x0);
qla4_8xxx_wr_32(ha, QLA82XX_CRB_NIU + 0x40, 0xff);
qla4_8xxx_wr_32(ha, QLA82XX_CRB_NIU + 0x70000, 0x00);
qla4_8xxx_wr_32(ha, QLA82XX_CRB_NIU + 0x80000, 0x00);
qla4_8xxx_wr_32(ha, QLA82XX_CRB_NIU + 0x90000, 0x00);
qla4_8xxx_wr_32(ha, QLA82XX_CRB_NIU + 0xa0000, 0x00);
qla4_8xxx_wr_32(ha, QLA82XX_CRB_NIU + 0xb0000, 0x00);
val = qla4_8xxx_rd_32(ha, QLA82XX_CRB_SRE + 0x1000);
qla4_8xxx_wr_32(ha, QLA82XX_CRB_SRE + 0x1000, val & (~(0x1)));
qla4_8xxx_wr_32(ha, QLA82XX_CRB_EPG + 0x1300, 0x1);
qla4_8xxx_wr_32(ha, QLA82XX_CRB_TIMER + 0x0, 0x0);
qla4_8xxx_wr_32(ha, QLA82XX_CRB_TIMER + 0x8, 0x0);
qla4_8xxx_wr_32(ha, QLA82XX_CRB_TIMER + 0x10, 0x0);
qla4_8xxx_wr_32(ha, QLA82XX_CRB_TIMER + 0x18, 0x0);
qla4_8xxx_wr_32(ha, QLA82XX_CRB_TIMER + 0x100, 0x0);
qla4_8xxx_wr_32(ha, QLA82XX_CRB_TIMER + 0x200, 0x0);
qla4_8xxx_wr_32(ha, QLA82XX_CRB_PEG_NET_0 + 0x3c, 1);
qla4_8xxx_wr_32(ha, QLA82XX_CRB_PEG_NET_1 + 0x3c, 1);
qla4_8xxx_wr_32(ha, QLA82XX_CRB_PEG_NET_2 + 0x3c, 1);
qla4_8xxx_wr_32(ha, QLA82XX_CRB_PEG_NET_3 + 0x3c, 1);
qla4_8xxx_wr_32(ha, QLA82XX_CRB_PEG_NET_4 + 0x3c, 1);
msleep(5);
if (test_bit(DPC_RESET_HA, &ha->dpc_flags))
qla4_8xxx_wr_32(ha, QLA82XX_ROMUSB_GLB_SW_RESET, 0xfeffffff);
else
qla4_8xxx_wr_32(ha, QLA82XX_ROMUSB_GLB_SW_RESET, 0xffffffff);
val = qla4_8xxx_rd_32(ha, QLA82XX_CRB_QDR_NET + 0xe4);
val |= (1 << 1);
qla4_8xxx_wr_32(ha, QLA82XX_CRB_QDR_NET + 0xe4, val);
msleep(20);
val = qla4_8xxx_rd_32(ha, QLA82XX_CRB_QDR_NET + 0xe4);
val &= ~(1 << 1);
qla4_8xxx_wr_32(ha, QLA82XX_CRB_QDR_NET + 0xe4, val);
msleep(20);
qla4_8xxx_rom_unlock(ha);
if (qla4_8xxx_rom_fast_read(ha, 0, &n) != 0 || n != 0xcafecafeUL ||
qla4_8xxx_rom_fast_read(ha, 4, &n) != 0) {
ql4_printk(KERN_WARNING, ha,
"[ERROR] Reading crb_init area: n: %08x\n", n);
return -1;
}
offset = n & 0xffffU;
n = (n >> 16) & 0xffffU;
if (n >= 1024) {
ql4_printk(KERN_WARNING, ha,
"%s: %s:n=0x%x [ERROR] Card flash not initialized.\n",
DRIVER_NAME, __func__, n);
return -1;
}
ql4_printk(KERN_INFO, ha,
"%s: %d CRB init values found in ROM.\n", DRIVER_NAME, n);
buf = kmalloc(n * sizeof(struct crb_addr_pair), GFP_KERNEL);
if (buf == NULL) {
ql4_printk(KERN_WARNING, ha,
"%s: [ERROR] Unable to malloc memory.\n", DRIVER_NAME);
return -1;
}
for (i = 0; i < n; i++) {
if (qla4_8xxx_rom_fast_read(ha, 8*i + 4*offset, &val) != 0 ||
qla4_8xxx_rom_fast_read(ha, 8*i + 4*offset + 4, &addr) !=
0) {
kfree(buf);
return -1;
}
buf[i].addr = addr;
buf[i].data = val;
}
for (i = 0; i < n; i++) {
off = qla4_8xxx_decode_crb_addr((unsigned long)buf[i].addr) +
QLA82XX_PCI_CRBSPACE;
if (off & 0x1) {
DEBUG2(ql4_printk(KERN_WARNING, ha,
"Skip CRB init replay for offset = 0x%lx\n", off));
continue;
}
if (off == QLA82XX_CAM_RAM(0x1fc))
continue;
if (off == (ROMUSB_GLB + 0xbc))
continue;
if (off == (ROMUSB_GLB + 0xc8))
continue;
if (off == QLA82XX_PCIE_REG(PCIE_SETUP_FUNCTION))
continue;
if (off == QLA82XX_PCIE_REG(PCIE_SETUP_FUNCTION2))
continue;
if ((off & 0x0ff00000) == QLA82XX_CRB_SMB)
continue;
if ((off & 0x0ff00000) == QLA82XX_CRB_DDR_NET)
continue;
if (off == ADDR_ERROR) {
ql4_printk(KERN_WARNING, ha,
"%s: [ERROR] Unknown addr: 0x%08lx\n",
DRIVER_NAME, buf[i].addr);
continue;
}
qla4_8xxx_wr_32(ha, off, buf[i].data);
if (off == QLA82XX_ROMUSB_GLB_SW_RESET)
msleep(1000);
msleep(1);
}
kfree(buf);
qla4_8xxx_wr_32(ha, QLA82XX_CRB_PEG_NET_D+0xec, 0x1e);
qla4_8xxx_wr_32(ha, QLA82XX_CRB_PEG_NET_D+0x4c, 8);
qla4_8xxx_wr_32(ha, QLA82XX_CRB_PEG_NET_I+0x4c, 8);
qla4_8xxx_wr_32(ha, QLA82XX_CRB_PEG_NET_0+0x8, 0);
qla4_8xxx_wr_32(ha, QLA82XX_CRB_PEG_NET_0+0xc, 0);
qla4_8xxx_wr_32(ha, QLA82XX_CRB_PEG_NET_1+0x8, 0);
qla4_8xxx_wr_32(ha, QLA82XX_CRB_PEG_NET_1+0xc, 0);
qla4_8xxx_wr_32(ha, QLA82XX_CRB_PEG_NET_2+0x8, 0);
qla4_8xxx_wr_32(ha, QLA82XX_CRB_PEG_NET_2+0xc, 0);
qla4_8xxx_wr_32(ha, QLA82XX_CRB_PEG_NET_3+0x8, 0);
qla4_8xxx_wr_32(ha, QLA82XX_CRB_PEG_NET_3+0xc, 0);
return 0;
}
static int
qla4_8xxx_load_from_flash(struct scsi_qla_host *ha, uint32_t image_start)
{
int i, rval = 0;
long size = 0;
long flashaddr, memaddr;
u64 data;
u32 high, low;
flashaddr = memaddr = ha->hw.flt_region_bootload;
size = (image_start - flashaddr) / 8;
DEBUG2(printk("scsi%ld: %s: bootldr=0x%lx, fw_image=0x%x\n",
ha->host_no, __func__, flashaddr, image_start));
for (i = 0; i < size; i++) {
if ((qla4_8xxx_rom_fast_read(ha, flashaddr, (int *)&low)) ||
(qla4_8xxx_rom_fast_read(ha, flashaddr + 4,
(int *)&high))) {
rval = -1;
goto exit_load_from_flash;
}
data = ((u64)high << 32) | low ;
rval = qla4_8xxx_pci_mem_write_2M(ha, memaddr, &data, 8);
if (rval)
goto exit_load_from_flash;
flashaddr += 8;
memaddr += 8;
if (i % 0x1000 == 0)
msleep(1);
}
udelay(100);
read_lock(&ha->hw_lock);
qla4_8xxx_wr_32(ha, QLA82XX_CRB_PEG_NET_0 + 0x18, 0x1020);
qla4_8xxx_wr_32(ha, QLA82XX_ROMUSB_GLB_SW_RESET, 0x80001e);
read_unlock(&ha->hw_lock);
exit_load_from_flash:
return rval;
}
static int qla4_8xxx_load_fw(struct scsi_qla_host *ha, uint32_t image_start)
{
u32 rst;
qla4_8xxx_wr_32(ha, CRB_CMDPEG_STATE, 0);
if (qla4_8xxx_pinit_from_rom(ha, 0) != QLA_SUCCESS) {
printk(KERN_WARNING "%s: Error during CRB Initialization\n",
__func__);
return QLA_ERROR;
}
udelay(500);
rst = qla4_8xxx_rd_32(ha, QLA82XX_ROMUSB_GLB_SW_RESET);
rst &= ~(1 << 28);
qla4_8xxx_wr_32(ha, QLA82XX_ROMUSB_GLB_SW_RESET, rst);
if (qla4_8xxx_load_from_flash(ha, image_start)) {
printk("%s: Error trying to load fw from flash!\n", __func__);
return QLA_ERROR;
}
return QLA_SUCCESS;
}
int
qla4_8xxx_pci_mem_read_2M(struct scsi_qla_host *ha,
u64 off, void *data, int size)
{
int i, j = 0, k, start, end, loop, sz[2], off0[2];
int shift_amount;
uint32_t temp;
uint64_t off8, val, mem_crb, word[2] = {0, 0};
if (off >= QLA82XX_ADDR_QDR_NET && off <= QLA82XX_P3_ADDR_QDR_NET_MAX)
mem_crb = QLA82XX_CRB_QDR_NET;
else {
mem_crb = QLA82XX_CRB_DDR_NET;
if (qla4_8xxx_pci_mem_bound_check(ha, off, size) == 0)
return qla4_8xxx_pci_mem_read_direct(ha,
off, data, size);
}
off8 = off & 0xfffffff0;
off0[0] = off & 0xf;
sz[0] = (size < (16 - off0[0])) ? size : (16 - off0[0]);
shift_amount = 4;
loop = ((off0[0] + size - 1) >> shift_amount) + 1;
off0[1] = 0;
sz[1] = size - sz[0];
for (i = 0; i < loop; i++) {
temp = off8 + (i << shift_amount);
qla4_8xxx_wr_32(ha, mem_crb + MIU_TEST_AGT_ADDR_LO, temp);
temp = 0;
qla4_8xxx_wr_32(ha, mem_crb + MIU_TEST_AGT_ADDR_HI, temp);
temp = MIU_TA_CTL_ENABLE;
qla4_8xxx_wr_32(ha, mem_crb + MIU_TEST_AGT_CTRL, temp);
temp = MIU_TA_CTL_START | MIU_TA_CTL_ENABLE;
qla4_8xxx_wr_32(ha, mem_crb + MIU_TEST_AGT_CTRL, temp);
for (j = 0; j < MAX_CTL_CHECK; j++) {
temp = qla4_8xxx_rd_32(ha, mem_crb + MIU_TEST_AGT_CTRL);
if ((temp & MIU_TA_CTL_BUSY) == 0)
break;
}
if (j >= MAX_CTL_CHECK) {
if (printk_ratelimit())
ql4_printk(KERN_ERR, ha,
"failed to read through agent\n");
break;
}
start = off0[i] >> 2;
end = (off0[i] + sz[i] - 1) >> 2;
for (k = start; k <= end; k++) {
temp = qla4_8xxx_rd_32(ha,
mem_crb + MIU_TEST_AGT_RDDATA(k));
word[i] |= ((uint64_t)temp << (32 * (k & 1)));
}
}
if (j >= MAX_CTL_CHECK)
return -1;
if ((off0[0] & 7) == 0) {
val = word[0];
} else {
val = ((word[0] >> (off0[0] * 8)) & (~(~0ULL << (sz[0] * 8)))) |
((word[1] & (~(~0ULL << (sz[1] * 8)))) << (sz[0] * 8));
}
switch (size) {
case 1:
*(uint8_t *)data = val;
break;
case 2:
*(uint16_t *)data = val;
break;
case 4:
*(uint32_t *)data = val;
break;
case 8:
*(uint64_t *)data = val;
break;
}
return 0;
}
int
qla4_8xxx_pci_mem_write_2M(struct scsi_qla_host *ha,
u64 off, void *data, int size)
{
int i, j, ret = 0, loop, sz[2], off0;
int scale, shift_amount, startword;
uint32_t temp;
uint64_t off8, mem_crb, tmpw, word[2] = {0, 0};
if (off >= QLA82XX_ADDR_QDR_NET && off <= QLA82XX_P3_ADDR_QDR_NET_MAX)
mem_crb = QLA82XX_CRB_QDR_NET;
else {
mem_crb = QLA82XX_CRB_DDR_NET;
if (qla4_8xxx_pci_mem_bound_check(ha, off, size) == 0)
return qla4_8xxx_pci_mem_write_direct(ha,
off, data, size);
}
off0 = off & 0x7;
sz[0] = (size < (8 - off0)) ? size : (8 - off0);
sz[1] = size - sz[0];
off8 = off & 0xfffffff0;
loop = (((off & 0xf) + size - 1) >> 4) + 1;
shift_amount = 4;
scale = 2;
startword = (off & 0xf)/8;
for (i = 0; i < loop; i++) {
if (qla4_8xxx_pci_mem_read_2M(ha, off8 +
(i << shift_amount), &word[i * scale], 8))
return -1;
}
switch (size) {
case 1:
tmpw = *((uint8_t *)data);
break;
case 2:
tmpw = *((uint16_t *)data);
break;
case 4:
tmpw = *((uint32_t *)data);
break;
case 8:
default:
tmpw = *((uint64_t *)data);
break;
}
if (sz[0] == 8)
word[startword] = tmpw;
else {
word[startword] &=
~((~(~0ULL << (sz[0] * 8))) << (off0 * 8));
word[startword] |= tmpw << (off0 * 8);
}
if (sz[1] != 0) {
word[startword+1] &= ~(~0ULL << (sz[1] * 8));
word[startword+1] |= tmpw >> (sz[0] * 8);
}
for (i = 0; i < loop; i++) {
temp = off8 + (i << shift_amount);
qla4_8xxx_wr_32(ha, mem_crb+MIU_TEST_AGT_ADDR_LO, temp);
temp = 0;
qla4_8xxx_wr_32(ha, mem_crb+MIU_TEST_AGT_ADDR_HI, temp);
temp = word[i * scale] & 0xffffffff;
qla4_8xxx_wr_32(ha, mem_crb+MIU_TEST_AGT_WRDATA_LO, temp);
temp = (word[i * scale] >> 32) & 0xffffffff;
qla4_8xxx_wr_32(ha, mem_crb+MIU_TEST_AGT_WRDATA_HI, temp);
temp = word[i*scale + 1] & 0xffffffff;
qla4_8xxx_wr_32(ha, mem_crb + MIU_TEST_AGT_WRDATA_UPPER_LO,
temp);
temp = (word[i*scale + 1] >> 32) & 0xffffffff;
qla4_8xxx_wr_32(ha, mem_crb + MIU_TEST_AGT_WRDATA_UPPER_HI,
temp);
temp = MIU_TA_CTL_ENABLE | MIU_TA_CTL_WRITE;
qla4_8xxx_wr_32(ha, mem_crb+MIU_TEST_AGT_CTRL, temp);
temp = MIU_TA_CTL_START | MIU_TA_CTL_ENABLE | MIU_TA_CTL_WRITE;
qla4_8xxx_wr_32(ha, mem_crb+MIU_TEST_AGT_CTRL, temp);
for (j = 0; j < MAX_CTL_CHECK; j++) {
temp = qla4_8xxx_rd_32(ha, mem_crb + MIU_TEST_AGT_CTRL);
if ((temp & MIU_TA_CTL_BUSY) == 0)
break;
}
if (j >= MAX_CTL_CHECK) {
if (printk_ratelimit())
ql4_printk(KERN_ERR, ha,
"failed to write through agent\n");
ret = -1;
break;
}
}
return ret;
}
static int qla4_8xxx_cmdpeg_ready(struct scsi_qla_host *ha, int pegtune_val)
{
u32 val = 0;
int retries = 60;
if (!pegtune_val) {
do {
val = qla4_8xxx_rd_32(ha, CRB_CMDPEG_STATE);
if ((val == PHAN_INITIALIZE_COMPLETE) ||
(val == PHAN_INITIALIZE_ACK))
return 0;
set_current_state(TASK_UNINTERRUPTIBLE);
schedule_timeout(500);
} while (--retries);
if (!retries) {
pegtune_val = qla4_8xxx_rd_32(ha,
QLA82XX_ROMUSB_GLB_PEGTUNE_DONE);
printk(KERN_WARNING "%s: init failed, "
"pegtune_val = %x\n", __func__, pegtune_val);
return -1;
}
}
return 0;
}
static int qla4_8xxx_rcvpeg_ready(struct scsi_qla_host *ha)
{
uint32_t state = 0;
int loops = 0;
read_lock(&ha->hw_lock);
state = qla4_8xxx_rd_32(ha, CRB_RCVPEG_STATE);
read_unlock(&ha->hw_lock);
while ((state != PHAN_PEG_RCV_INITIALIZED) && (loops < 30000)) {
udelay(100);
read_lock(&ha->hw_lock);
state = qla4_8xxx_rd_32(ha, CRB_RCVPEG_STATE);
read_unlock(&ha->hw_lock);
loops++;
}
if (loops >= 30000) {
DEBUG2(ql4_printk(KERN_INFO, ha,
"Receive Peg initialization not complete: 0x%x.\n", state));
return QLA_ERROR;
}
return QLA_SUCCESS;
}
void
qla4_8xxx_set_drv_active(struct scsi_qla_host *ha)
{
uint32_t drv_active;
drv_active = qla4_8xxx_rd_32(ha, QLA82XX_CRB_DRV_ACTIVE);
drv_active |= (1 << (ha->func_num * 4));
qla4_8xxx_wr_32(ha, QLA82XX_CRB_DRV_ACTIVE, drv_active);
}
void
qla4_8xxx_clear_drv_active(struct scsi_qla_host *ha)
{
uint32_t drv_active;
drv_active = qla4_8xxx_rd_32(ha, QLA82XX_CRB_DRV_ACTIVE);
drv_active &= ~(1 << (ha->func_num * 4));
qla4_8xxx_wr_32(ha, QLA82XX_CRB_DRV_ACTIVE, drv_active);
}
static inline int
qla4_8xxx_need_reset(struct scsi_qla_host *ha)
{
uint32_t drv_state, drv_active;
int rval;
drv_active = qla4_8xxx_rd_32(ha, QLA82XX_CRB_DRV_ACTIVE);
drv_state = qla4_8xxx_rd_32(ha, QLA82XX_CRB_DRV_STATE);
rval = drv_state & (1 << (ha->func_num * 4));
if ((test_bit(AF_EEH_BUSY, &ha->flags)) && drv_active)
rval = 1;
return rval;
}
static inline void
qla4_8xxx_set_rst_ready(struct scsi_qla_host *ha)
{
uint32_t drv_state;
drv_state = qla4_8xxx_rd_32(ha, QLA82XX_CRB_DRV_STATE);
drv_state |= (1 << (ha->func_num * 4));
qla4_8xxx_wr_32(ha, QLA82XX_CRB_DRV_STATE, drv_state);
}
static inline void
qla4_8xxx_clear_rst_ready(struct scsi_qla_host *ha)
{
uint32_t drv_state;
drv_state = qla4_8xxx_rd_32(ha, QLA82XX_CRB_DRV_STATE);
drv_state &= ~(1 << (ha->func_num * 4));
qla4_8xxx_wr_32(ha, QLA82XX_CRB_DRV_STATE, drv_state);
}
static inline void
qla4_8xxx_set_qsnt_ready(struct scsi_qla_host *ha)
{
uint32_t qsnt_state;
qsnt_state = qla4_8xxx_rd_32(ha, QLA82XX_CRB_DRV_STATE);
qsnt_state |= (2 << (ha->func_num * 4));
qla4_8xxx_wr_32(ha, QLA82XX_CRB_DRV_STATE, qsnt_state);
}
static int
qla4_8xxx_start_firmware(struct scsi_qla_host *ha, uint32_t image_start)
{
int pcie_cap;
uint16_t lnk;
qla4_8xxx_wr_32(ha, CRB_DMA_SHIFT, 0x55555555);
qla4_8xxx_wr_32(ha, CRB_CMDPEG_STATE, 0);
qla4_8xxx_wr_32(ha, CRB_RCVPEG_STATE, 0);
qla4_8xxx_wr_32(ha, QLA82XX_PEG_HALT_STATUS1, 0);
qla4_8xxx_wr_32(ha, QLA82XX_PEG_HALT_STATUS2, 0);
if (qla4_8xxx_load_fw(ha, image_start) != QLA_SUCCESS) {
printk("%s: Error trying to start fw!\n", __func__);
return QLA_ERROR;
}
if (qla4_8xxx_cmdpeg_ready(ha, 0) != QLA_SUCCESS) {
printk("%s: Error during card handshake!\n", __func__);
return QLA_ERROR;
}
pcie_cap = pci_find_capability(ha->pdev, PCI_CAP_ID_EXP);
pci_read_config_word(ha->pdev, pcie_cap + PCI_EXP_LNKSTA, &lnk);
ha->link_width = (lnk >> 4) & 0x3f;
return qla4_8xxx_rcvpeg_ready(ha);
}
static int
qla4_8xxx_try_start_fw(struct scsi_qla_host *ha)
{
int rval = QLA_ERROR;
ql4_printk(KERN_INFO, ha,
"FW: Retrieving flash offsets from FLT/FDT ...\n");
rval = qla4_8xxx_get_flash_info(ha);
if (rval != QLA_SUCCESS)
return rval;
ql4_printk(KERN_INFO, ha,
"FW: Attempting to load firmware from flash...\n");
rval = qla4_8xxx_start_firmware(ha, ha->hw.flt_region_fw);
if (rval != QLA_SUCCESS) {
ql4_printk(KERN_ERR, ha, "FW: Load firmware from flash"
" FAILED...\n");
return rval;
}
return rval;
}
static void qla4_8xxx_rom_lock_recovery(struct scsi_qla_host *ha)
{
if (qla4_8xxx_rom_lock(ha)) {
dev_info(&ha->pdev->dev, "Resetting rom_lock\n");
}
qla4_8xxx_rom_unlock(ha);
}
static int
qla4_8xxx_device_bootstrap(struct scsi_qla_host *ha)
{
int rval = QLA_ERROR;
int i, timeout;
uint32_t old_count, count;
int need_reset = 0, peg_stuck = 1;
need_reset = qla4_8xxx_need_reset(ha);
old_count = qla4_8xxx_rd_32(ha, QLA82XX_PEG_ALIVE_COUNTER);
for (i = 0; i < 10; i++) {
timeout = msleep_interruptible(200);
if (timeout) {
qla4_8xxx_wr_32(ha, QLA82XX_CRB_DEV_STATE,
QLA82XX_DEV_FAILED);
return rval;
}
count = qla4_8xxx_rd_32(ha, QLA82XX_PEG_ALIVE_COUNTER);
if (count != old_count)
peg_stuck = 0;
}
if (need_reset) {
if (peg_stuck)
qla4_8xxx_rom_lock_recovery(ha);
goto dev_initialize;
} else {
if (peg_stuck) {
qla4_8xxx_rom_lock_recovery(ha);
goto dev_initialize;
} else {
rval = QLA_SUCCESS;
goto dev_ready;
}
}
dev_initialize:
ql4_printk(KERN_INFO, ha, "HW State: INITIALIZING\n");
qla4_8xxx_wr_32(ha, QLA82XX_CRB_DEV_STATE, QLA82XX_DEV_INITIALIZING);
qla4_8xxx_wr_32(ha, QLA82XX_CRB_DRV_IDC_VERSION, QLA82XX_IDC_VERSION);
qla4_8xxx_idc_unlock(ha);
rval = qla4_8xxx_try_start_fw(ha);
qla4_8xxx_idc_lock(ha);
if (rval != QLA_SUCCESS) {
ql4_printk(KERN_INFO, ha, "HW State: FAILED\n");
qla4_8xxx_clear_drv_active(ha);
qla4_8xxx_wr_32(ha, QLA82XX_CRB_DEV_STATE, QLA82XX_DEV_FAILED);
return rval;
}
dev_ready:
ql4_printk(KERN_INFO, ha, "HW State: READY\n");
qla4_8xxx_wr_32(ha, QLA82XX_CRB_DEV_STATE, QLA82XX_DEV_READY);
return rval;
}
static void
qla4_8xxx_need_reset_handler(struct scsi_qla_host *ha)
{
uint32_t dev_state, drv_state, drv_active;
unsigned long reset_timeout;
ql4_printk(KERN_INFO, ha,
"Performing ISP error recovery\n");
if (test_and_clear_bit(AF_ONLINE, &ha->flags)) {
qla4_8xxx_idc_unlock(ha);
ha->isp_ops->disable_intrs(ha);
qla4_8xxx_idc_lock(ha);
}
qla4_8xxx_set_rst_ready(ha);
reset_timeout = jiffies + (ha->nx_reset_timeout * HZ);
drv_state = qla4_8xxx_rd_32(ha, QLA82XX_CRB_DRV_STATE);
drv_active = qla4_8xxx_rd_32(ha, QLA82XX_CRB_DRV_ACTIVE);
ql4_printk(KERN_INFO, ha,
"%s(%ld): drv_state = 0x%x, drv_active = 0x%x\n",
__func__, ha->host_no, drv_state, drv_active);
while (drv_state != drv_active) {
if (time_after_eq(jiffies, reset_timeout)) {
printk("%s: RESET TIMEOUT!\n", DRIVER_NAME);
break;
}
qla4_8xxx_idc_unlock(ha);
msleep(1000);
qla4_8xxx_idc_lock(ha);
drv_state = qla4_8xxx_rd_32(ha, QLA82XX_CRB_DRV_STATE);
drv_active = qla4_8xxx_rd_32(ha, QLA82XX_CRB_DRV_ACTIVE);
}
dev_state = qla4_8xxx_rd_32(ha, QLA82XX_CRB_DEV_STATE);
ql4_printk(KERN_INFO, ha, "3:Device state is 0x%x = %s\n", dev_state,
dev_state < MAX_STATES ? qdev_state[dev_state] : "Unknown");
if (dev_state != QLA82XX_DEV_INITIALIZING) {
ql4_printk(KERN_INFO, ha, "HW State: COLD/RE-INIT\n");
qla4_8xxx_wr_32(ha, QLA82XX_CRB_DEV_STATE, QLA82XX_DEV_COLD);
}
}
void
qla4_8xxx_need_qsnt_handler(struct scsi_qla_host *ha)
{
qla4_8xxx_idc_lock(ha);
qla4_8xxx_set_qsnt_ready(ha);
qla4_8xxx_idc_unlock(ha);
}
int qla4_8xxx_device_state_handler(struct scsi_qla_host *ha)
{
uint32_t dev_state;
int rval = QLA_SUCCESS;
unsigned long dev_init_timeout;
if (!test_bit(AF_INIT_DONE, &ha->flags))
qla4_8xxx_set_drv_active(ha);
dev_state = qla4_8xxx_rd_32(ha, QLA82XX_CRB_DEV_STATE);
ql4_printk(KERN_INFO, ha, "1:Device state is 0x%x = %s\n", dev_state,
dev_state < MAX_STATES ? qdev_state[dev_state] : "Unknown");
dev_init_timeout = jiffies + (ha->nx_dev_init_timeout * HZ);
while (1) {
qla4_8xxx_idc_lock(ha);
if (time_after_eq(jiffies, dev_init_timeout)) {
ql4_printk(KERN_WARNING, ha, "Device init failed!\n");
qla4_8xxx_wr_32(ha, QLA82XX_CRB_DEV_STATE,
QLA82XX_DEV_FAILED);
}
dev_state = qla4_8xxx_rd_32(ha, QLA82XX_CRB_DEV_STATE);
ql4_printk(KERN_INFO, ha,
"2:Device state is 0x%x = %s\n", dev_state,
dev_state < MAX_STATES ? qdev_state[dev_state] : "Unknown");
switch (dev_state) {
case QLA82XX_DEV_READY:
qla4_8xxx_idc_unlock(ha);
goto exit;
case QLA82XX_DEV_COLD:
rval = qla4_8xxx_device_bootstrap(ha);
qla4_8xxx_idc_unlock(ha);
goto exit;
case QLA82XX_DEV_INITIALIZING:
qla4_8xxx_idc_unlock(ha);
msleep(1000);
break;
case QLA82XX_DEV_NEED_RESET:
if (!ql4xdontresethba) {
qla4_8xxx_need_reset_handler(ha);
dev_init_timeout = jiffies +
(ha->nx_dev_init_timeout * HZ);
}
qla4_8xxx_idc_unlock(ha);
break;
case QLA82XX_DEV_NEED_QUIESCENT:
qla4_8xxx_idc_unlock(ha);
qla4_8xxx_need_qsnt_handler(ha);
qla4_8xxx_idc_lock(ha);
case QLA82XX_DEV_QUIESCENT:
qla4_8xxx_idc_unlock(ha);
msleep(1000);
break;
case QLA82XX_DEV_FAILED:
qla4_8xxx_idc_unlock(ha);
qla4xxx_dead_adapter_cleanup(ha);
rval = QLA_ERROR;
goto exit;
default:
qla4_8xxx_idc_unlock(ha);
qla4xxx_dead_adapter_cleanup(ha);
rval = QLA_ERROR;
goto exit;
}
}
exit:
return rval;
}
int qla4_8xxx_load_risc(struct scsi_qla_host *ha)
{
int retval;
retval = qla4_8xxx_device_state_handler(ha);
if (retval == QLA_SUCCESS && !test_bit(AF_INIT_DONE, &ha->flags))
retval = qla4xxx_request_irqs(ha);
return retval;
}
static inline uint32_t
flash_conf_addr(struct ql82xx_hw_data *hw, uint32_t faddr)
{
return hw->flash_conf_off | faddr;
}
static inline uint32_t
flash_data_addr(struct ql82xx_hw_data *hw, uint32_t faddr)
{
return hw->flash_data_off | faddr;
}
static uint32_t *
qla4_8xxx_read_flash_data(struct scsi_qla_host *ha, uint32_t *dwptr,
uint32_t faddr, uint32_t length)
{
uint32_t i;
uint32_t val;
int loops = 0;
while ((qla4_8xxx_rom_lock(ha) != 0) && (loops < 50000)) {
udelay(100);
cond_resched();
loops++;
}
if (loops >= 50000) {
ql4_printk(KERN_WARNING, ha, "ROM lock failed\n");
return dwptr;
}
for (i = 0; i < length/4; i++, faddr += 4) {
if (qla4_8xxx_do_rom_fast_read(ha, faddr, &val)) {
ql4_printk(KERN_WARNING, ha,
"Do ROM fast read failed\n");
goto done_read;
}
dwptr[i] = __constant_cpu_to_le32(val);
}
done_read:
qla4_8xxx_rom_unlock(ha);
return dwptr;
}
static uint8_t *
qla4_8xxx_read_optrom_data(struct scsi_qla_host *ha, uint8_t *buf,
uint32_t offset, uint32_t length)
{
qla4_8xxx_read_flash_data(ha, (uint32_t *)buf, offset, length);
return buf;
}
static int
qla4_8xxx_find_flt_start(struct scsi_qla_host *ha, uint32_t *start)
{
const char *loc, *locations[] = { "DEF", "PCI" };
loc = locations[0];
*start = FA_FLASH_LAYOUT_ADDR_82;
DEBUG2(ql4_printk(KERN_INFO, ha, "FLTL[%s] = 0x%x.\n", loc, *start));
return QLA_SUCCESS;
}
static void
qla4_8xxx_get_flt_info(struct scsi_qla_host *ha, uint32_t flt_addr)
{
const char *loc, *locations[] = { "DEF", "FLT" };
uint16_t *wptr;
uint16_t cnt, chksum;
uint32_t start;
struct qla_flt_header *flt;
struct qla_flt_region *region;
struct ql82xx_hw_data *hw = &ha->hw;
hw->flt_region_flt = flt_addr;
wptr = (uint16_t *)ha->request_ring;
flt = (struct qla_flt_header *)ha->request_ring;
region = (struct qla_flt_region *)&flt[1];
qla4_8xxx_read_optrom_data(ha, (uint8_t *)ha->request_ring,
flt_addr << 2, OPTROM_BURST_SIZE);
if (*wptr == __constant_cpu_to_le16(0xffff))
goto no_flash_data;
if (flt->version != __constant_cpu_to_le16(1)) {
DEBUG2(ql4_printk(KERN_INFO, ha, "Unsupported FLT detected: "
"version=0x%x length=0x%x checksum=0x%x.\n",
le16_to_cpu(flt->version), le16_to_cpu(flt->length),
le16_to_cpu(flt->checksum)));
goto no_flash_data;
}
cnt = (sizeof(struct qla_flt_header) + le16_to_cpu(flt->length)) >> 1;
for (chksum = 0; cnt; cnt--)
chksum += le16_to_cpu(*wptr++);
if (chksum) {
DEBUG2(ql4_printk(KERN_INFO, ha, "Inconsistent FLT detected: "
"version=0x%x length=0x%x checksum=0x%x.\n",
le16_to_cpu(flt->version), le16_to_cpu(flt->length),
chksum));
goto no_flash_data;
}
loc = locations[1];
cnt = le16_to_cpu(flt->length) / sizeof(struct qla_flt_region);
for ( ; cnt; cnt--, region++) {
start = le32_to_cpu(region->start) >> 2;
DEBUG3(ql4_printk(KERN_DEBUG, ha, "FLT[%02x]: start=0x%x "
"end=0x%x size=0x%x.\n", le32_to_cpu(region->code), start,
le32_to_cpu(region->end) >> 2, le32_to_cpu(region->size)));
switch (le32_to_cpu(region->code) & 0xff) {
case FLT_REG_FDT:
hw->flt_region_fdt = start;
break;
case FLT_REG_BOOT_CODE_82:
hw->flt_region_boot = start;
break;
case FLT_REG_FW_82:
case FLT_REG_FW_82_1:
hw->flt_region_fw = start;
break;
case FLT_REG_BOOTLOAD_82:
hw->flt_region_bootload = start;
break;
case FLT_REG_ISCSI_PARAM:
hw->flt_iscsi_param = start;
break;
case FLT_REG_ISCSI_CHAP:
hw->flt_region_chap = start;
hw->flt_chap_size = le32_to_cpu(region->size);
break;
}
}
goto done;
no_flash_data:
loc = locations[0];
hw->flt_region_fdt = FA_FLASH_DESCR_ADDR_82;
hw->flt_region_boot = FA_BOOT_CODE_ADDR_82;
hw->flt_region_bootload = FA_BOOT_LOAD_ADDR_82;
hw->flt_region_fw = FA_RISC_CODE_ADDR_82;
hw->flt_region_chap = FA_FLASH_ISCSI_CHAP;
hw->flt_chap_size = FA_FLASH_CHAP_SIZE;
done:
DEBUG2(ql4_printk(KERN_INFO, ha, "FLT[%s]: flt=0x%x fdt=0x%x "
"boot=0x%x bootload=0x%x fw=0x%x\n", loc, hw->flt_region_flt,
hw->flt_region_fdt, hw->flt_region_boot, hw->flt_region_bootload,
hw->flt_region_fw));
}
static void
qla4_8xxx_get_fdt_info(struct scsi_qla_host *ha)
{
#define FLASH_BLK_SIZE_4K 0x1000
#define FLASH_BLK_SIZE_32K 0x8000
#define FLASH_BLK_SIZE_64K 0x10000
const char *loc, *locations[] = { "MID", "FDT" };
uint16_t cnt, chksum;
uint16_t *wptr;
struct qla_fdt_layout *fdt;
uint16_t mid = 0;
uint16_t fid = 0;
struct ql82xx_hw_data *hw = &ha->hw;
hw->flash_conf_off = FARX_ACCESS_FLASH_CONF;
hw->flash_data_off = FARX_ACCESS_FLASH_DATA;
wptr = (uint16_t *)ha->request_ring;
fdt = (struct qla_fdt_layout *)ha->request_ring;
qla4_8xxx_read_optrom_data(ha, (uint8_t *)ha->request_ring,
hw->flt_region_fdt << 2, OPTROM_BURST_SIZE);
if (*wptr == __constant_cpu_to_le16(0xffff))
goto no_flash_data;
if (fdt->sig[0] != 'Q' || fdt->sig[1] != 'L' || fdt->sig[2] != 'I' ||
fdt->sig[3] != 'D')
goto no_flash_data;
for (cnt = 0, chksum = 0; cnt < sizeof(struct qla_fdt_layout) >> 1;
cnt++)
chksum += le16_to_cpu(*wptr++);
if (chksum) {
DEBUG2(ql4_printk(KERN_INFO, ha, "Inconsistent FDT detected: "
"checksum=0x%x id=%c version=0x%x.\n", chksum, fdt->sig[0],
le16_to_cpu(fdt->version)));
goto no_flash_data;
}
loc = locations[1];
mid = le16_to_cpu(fdt->man_id);
fid = le16_to_cpu(fdt->id);
hw->fdt_wrt_disable = fdt->wrt_disable_bits;
hw->fdt_erase_cmd = flash_conf_addr(hw, 0x0300 | fdt->erase_cmd);
hw->fdt_block_size = le32_to_cpu(fdt->block_size);
if (fdt->unprotect_sec_cmd) {
hw->fdt_unprotect_sec_cmd = flash_conf_addr(hw, 0x0300 |
fdt->unprotect_sec_cmd);
hw->fdt_protect_sec_cmd = fdt->protect_sec_cmd ?
flash_conf_addr(hw, 0x0300 | fdt->protect_sec_cmd) :
flash_conf_addr(hw, 0x0336);
}
goto done;
no_flash_data:
loc = locations[0];
hw->fdt_block_size = FLASH_BLK_SIZE_64K;
done:
DEBUG2(ql4_printk(KERN_INFO, ha, "FDT[%s]: (0x%x/0x%x) erase=0x%x "
"pro=%x upro=%x wrtd=0x%x blk=0x%x.\n", loc, mid, fid,
hw->fdt_erase_cmd, hw->fdt_protect_sec_cmd,
hw->fdt_unprotect_sec_cmd, hw->fdt_wrt_disable,
hw->fdt_block_size));
}
static void
qla4_8xxx_get_idc_param(struct scsi_qla_host *ha)
{
#define QLA82XX_IDC_PARAM_ADDR 0x003e885c
uint32_t *wptr;
if (!is_qla8022(ha))
return;
wptr = (uint32_t *)ha->request_ring;
qla4_8xxx_read_optrom_data(ha, (uint8_t *)ha->request_ring,
QLA82XX_IDC_PARAM_ADDR , 8);
if (*wptr == __constant_cpu_to_le32(0xffffffff)) {
ha->nx_dev_init_timeout = ROM_DEV_INIT_TIMEOUT;
ha->nx_reset_timeout = ROM_DRV_RESET_ACK_TIMEOUT;
} else {
ha->nx_dev_init_timeout = le32_to_cpu(*wptr++);
ha->nx_reset_timeout = le32_to_cpu(*wptr);
}
DEBUG2(ql4_printk(KERN_DEBUG, ha,
"ha->nx_dev_init_timeout = %d\n", ha->nx_dev_init_timeout));
DEBUG2(ql4_printk(KERN_DEBUG, ha,
"ha->nx_reset_timeout = %d\n", ha->nx_reset_timeout));
return;
}
int
qla4_8xxx_get_flash_info(struct scsi_qla_host *ha)
{
int ret;
uint32_t flt_addr;
ret = qla4_8xxx_find_flt_start(ha, &flt_addr);
if (ret != QLA_SUCCESS)
return ret;
qla4_8xxx_get_flt_info(ha, flt_addr);
qla4_8xxx_get_fdt_info(ha);
qla4_8xxx_get_idc_param(ha);
return QLA_SUCCESS;
}
int
qla4_8xxx_stop_firmware(struct scsi_qla_host *ha)
{
int status;
uint32_t mbox_cmd[MBOX_REG_COUNT];
uint32_t mbox_sts[MBOX_REG_COUNT];
memset(&mbox_cmd, 0, sizeof(mbox_cmd));
memset(&mbox_sts, 0, sizeof(mbox_sts));
mbox_cmd[0] = MBOX_CMD_STOP_FW;
status = qla4xxx_mailbox_command(ha, MBOX_REG_COUNT, 1,
&mbox_cmd[0], &mbox_sts[0]);
DEBUG2(printk("scsi%ld: %s: status = %d\n", ha->host_no,
__func__, status));
return status;
}
int
qla4_8xxx_isp_reset(struct scsi_qla_host *ha)
{
int rval;
uint32_t dev_state;
qla4_8xxx_idc_lock(ha);
dev_state = qla4_8xxx_rd_32(ha, QLA82XX_CRB_DEV_STATE);
if (dev_state == QLA82XX_DEV_READY) {
ql4_printk(KERN_INFO, ha, "HW State: NEED RESET\n");
qla4_8xxx_wr_32(ha, QLA82XX_CRB_DEV_STATE,
QLA82XX_DEV_NEED_RESET);
} else
ql4_printk(KERN_INFO, ha, "HW State: DEVICE INITIALIZING\n");
qla4_8xxx_idc_unlock(ha);
rval = qla4_8xxx_device_state_handler(ha);
qla4_8xxx_idc_lock(ha);
qla4_8xxx_clear_rst_ready(ha);
qla4_8xxx_idc_unlock(ha);
if (rval == QLA_SUCCESS)
clear_bit(AF_FW_RECOVERY, &ha->flags);
return rval;
}
int qla4_8xxx_get_sys_info(struct scsi_qla_host *ha)
{
uint32_t mbox_cmd[MBOX_REG_COUNT];
uint32_t mbox_sts[MBOX_REG_COUNT];
struct mbx_sys_info *sys_info;
dma_addr_t sys_info_dma;
int status = QLA_ERROR;
sys_info = dma_alloc_coherent(&ha->pdev->dev, sizeof(*sys_info),
&sys_info_dma, GFP_KERNEL);
if (sys_info == NULL) {
DEBUG2(printk("scsi%ld: %s: Unable to allocate dma buffer.\n",
ha->host_no, __func__));
return status;
}
memset(sys_info, 0, sizeof(*sys_info));
memset(&mbox_cmd, 0, sizeof(mbox_cmd));
memset(&mbox_sts, 0, sizeof(mbox_sts));
mbox_cmd[0] = MBOX_CMD_GET_SYS_INFO;
mbox_cmd[1] = LSDW(sys_info_dma);
mbox_cmd[2] = MSDW(sys_info_dma);
mbox_cmd[4] = sizeof(*sys_info);
if (qla4xxx_mailbox_command(ha, MBOX_REG_COUNT, 6, &mbox_cmd[0],
&mbox_sts[0]) != QLA_SUCCESS) {
DEBUG2(printk("scsi%ld: %s: GET_SYS_INFO failed\n",
ha->host_no, __func__));
goto exit_validate_mac82;
}
if (mbox_sts[4] < offsetof(struct mbx_sys_info, reserved)) {
DEBUG2(printk("scsi%ld: %s: GET_SYS_INFO data receive"
" error (%x)\n", ha->host_no, __func__, mbox_sts[4]));
goto exit_validate_mac82;
}
ha->port_num = sys_info->port_num;
memcpy(ha->my_mac, &sys_info->mac_addr[0],
min(sizeof(ha->my_mac), sizeof(sys_info->mac_addr)));
memcpy(ha->serial_number, &sys_info->serial_number,
min(sizeof(ha->serial_number), sizeof(sys_info->serial_number)));
memcpy(ha->model_name, &sys_info->board_id_str,
min(sizeof(ha->model_name), sizeof(sys_info->board_id_str)));
ha->phy_port_cnt = sys_info->phys_port_cnt;
ha->phy_port_num = sys_info->port_num;
ha->iscsi_pci_func_cnt = sys_info->iscsi_pci_func_cnt;
DEBUG2(printk("scsi%ld: %s: "
"mac %02x:%02x:%02x:%02x:%02x:%02x "
"serial %s\n", ha->host_no, __func__,
ha->my_mac[0], ha->my_mac[1], ha->my_mac[2],
ha->my_mac[3], ha->my_mac[4], ha->my_mac[5],
ha->serial_number));
status = QLA_SUCCESS;
exit_validate_mac82:
dma_free_coherent(&ha->pdev->dev, sizeof(*sys_info), sys_info,
sys_info_dma);
return status;
}
static int
qla4_8xxx_mbx_intr_enable(struct scsi_qla_host *ha)
{
uint32_t mbox_cmd[MBOX_REG_COUNT];
uint32_t mbox_sts[MBOX_REG_COUNT];
DEBUG2(ql4_printk(KERN_INFO, ha, "%s\n", __func__));
memset(&mbox_cmd, 0, sizeof(mbox_cmd));
memset(&mbox_sts, 0, sizeof(mbox_sts));
mbox_cmd[0] = MBOX_CMD_ENABLE_INTRS;
mbox_cmd[1] = INTR_ENABLE;
if (qla4xxx_mailbox_command(ha, MBOX_REG_COUNT, 1, &mbox_cmd[0],
&mbox_sts[0]) != QLA_SUCCESS) {
DEBUG2(ql4_printk(KERN_INFO, ha,
"%s: MBOX_CMD_ENABLE_INTRS failed (0x%04x)\n",
__func__, mbox_sts[0]));
return QLA_ERROR;
}
return QLA_SUCCESS;
}
static int
qla4_8xxx_mbx_intr_disable(struct scsi_qla_host *ha)
{
uint32_t mbox_cmd[MBOX_REG_COUNT];
uint32_t mbox_sts[MBOX_REG_COUNT];
DEBUG2(ql4_printk(KERN_INFO, ha, "%s\n", __func__));
memset(&mbox_cmd, 0, sizeof(mbox_cmd));
memset(&mbox_sts, 0, sizeof(mbox_sts));
mbox_cmd[0] = MBOX_CMD_ENABLE_INTRS;
mbox_cmd[1] = INTR_DISABLE;
if (qla4xxx_mailbox_command(ha, MBOX_REG_COUNT, 1, &mbox_cmd[0],
&mbox_sts[0]) != QLA_SUCCESS) {
DEBUG2(ql4_printk(KERN_INFO, ha,
"%s: MBOX_CMD_ENABLE_INTRS failed (0x%04x)\n",
__func__, mbox_sts[0]));
return QLA_ERROR;
}
return QLA_SUCCESS;
}
void
qla4_8xxx_enable_intrs(struct scsi_qla_host *ha)
{
qla4_8xxx_mbx_intr_enable(ha);
spin_lock_irq(&ha->hardware_lock);
qla4_8xxx_wr_32(ha, ha->nx_legacy_intr.tgt_mask_reg, 0xfbff);
spin_unlock_irq(&ha->hardware_lock);
set_bit(AF_INTERRUPTS_ON, &ha->flags);
}
void
qla4_8xxx_disable_intrs(struct scsi_qla_host *ha)
{
if (test_and_clear_bit(AF_INTERRUPTS_ON, &ha->flags))
qla4_8xxx_mbx_intr_disable(ha);
spin_lock_irq(&ha->hardware_lock);
qla4_8xxx_wr_32(ha, ha->nx_legacy_intr.tgt_mask_reg, 0x0400);
spin_unlock_irq(&ha->hardware_lock);
}
void
qla4_8xxx_disable_msix(struct scsi_qla_host *ha)
{
int i;
struct ql4_msix_entry *qentry;
for (i = 0; i < QLA_MSIX_ENTRIES; i++) {
qentry = &ha->msix_entries[qla4_8xxx_msix_entries[i].index];
if (qentry->have_irq) {
free_irq(qentry->msix_vector, ha);
DEBUG2(ql4_printk(KERN_INFO, ha, "%s: %s\n",
__func__, qla4_8xxx_msix_entries[i].name));
}
}
pci_disable_msix(ha->pdev);
clear_bit(AF_MSIX_ENABLED, &ha->flags);
}
int
qla4_8xxx_enable_msix(struct scsi_qla_host *ha)
{
int i, ret;
struct msix_entry entries[QLA_MSIX_ENTRIES];
struct ql4_msix_entry *qentry;
for (i = 0; i < QLA_MSIX_ENTRIES; i++)
entries[i].entry = qla4_8xxx_msix_entries[i].entry;
ret = pci_enable_msix(ha->pdev, entries, ARRAY_SIZE(entries));
if (ret) {
ql4_printk(KERN_WARNING, ha,
"MSI-X: Failed to enable support -- %d/%d\n",
QLA_MSIX_ENTRIES, ret);
goto msix_out;
}
set_bit(AF_MSIX_ENABLED, &ha->flags);
for (i = 0; i < QLA_MSIX_ENTRIES; i++) {
qentry = &ha->msix_entries[qla4_8xxx_msix_entries[i].index];
qentry->msix_vector = entries[i].vector;
qentry->msix_entry = entries[i].entry;
qentry->have_irq = 0;
ret = request_irq(qentry->msix_vector,
qla4_8xxx_msix_entries[i].handler, 0,
qla4_8xxx_msix_entries[i].name, ha);
if (ret) {
ql4_printk(KERN_WARNING, ha,
"MSI-X: Unable to register handler -- %x/%d.\n",
qla4_8xxx_msix_entries[i].index, ret);
qla4_8xxx_disable_msix(ha);
goto msix_out;
}
qentry->have_irq = 1;
DEBUG2(ql4_printk(KERN_INFO, ha, "%s: %s\n",
__func__, qla4_8xxx_msix_entries[i].name));
}
msix_out:
return ret;
}
