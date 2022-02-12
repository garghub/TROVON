static int buddha_test_irq(ide_hwif_t *hwif)
{
unsigned char ch;
ch = z_readb(hwif->io_ports.irq_addr);
if (!(ch & 0x80))
return 0;
return 1;
}
static void xsurf_clear_irq(ide_drive_t *drive)
{
z_writeb(0, drive->hwif->io_ports.irq_addr);
}
static void __init buddha_setup_ports(struct ide_hw *hw, unsigned long base,
unsigned long ctl, unsigned long irq_port)
{
int i;
memset(hw, 0, sizeof(*hw));
hw->io_ports.data_addr = base;
for (i = 1; i < 8; i++)
hw->io_ports_array[i] = base + 2 + i * 4;
hw->io_ports.ctl_addr = ctl;
hw->io_ports.irq_addr = irq_port;
hw->irq = IRQ_AMIGA_PORTS;
}
static int __init buddha_init(void)
{
struct zorro_dev *z = NULL;
u_long buddha_board = 0;
BuddhaType type;
int buddha_num_hwifs, i;
while ((z = zorro_find_device(ZORRO_WILDCARD, z))) {
unsigned long board;
struct ide_hw hw[MAX_NUM_HWIFS], *hws[MAX_NUM_HWIFS];
struct ide_port_info d = buddha_port_info;
if (z->id == ZORRO_PROD_INDIVIDUAL_COMPUTERS_BUDDHA) {
buddha_num_hwifs = BUDDHA_NUM_HWIFS;
type=BOARD_BUDDHA;
} else if (z->id == ZORRO_PROD_INDIVIDUAL_COMPUTERS_CATWEASEL) {
buddha_num_hwifs = CATWEASEL_NUM_HWIFS;
type=BOARD_CATWEASEL;
} else if (z->id == ZORRO_PROD_INDIVIDUAL_COMPUTERS_X_SURF) {
buddha_num_hwifs = XSURF_NUM_HWIFS;
type=BOARD_XSURF;
d.port_ops = &xsurf_port_ops;
} else
continue;
board = z->resource.start;
if(type != BOARD_XSURF) {
if (!request_mem_region(board+BUDDHA_BASE1, 0x800, "IDE"))
continue;
} else {
if (!request_mem_region(board+XSURF_BASE1, 0x1000, "IDE"))
continue;
if (!request_mem_region(board+XSURF_BASE2, 0x1000, "IDE"))
goto fail_base2;
if (!request_mem_region(board+XSURF_IRQ1, 0x8, "IDE")) {
release_mem_region(board+XSURF_BASE2, 0x1000);
fail_base2:
release_mem_region(board+XSURF_BASE1, 0x1000);
continue;
}
}
buddha_board = (unsigned long)ZTWO_VADDR(board);
if (type != BOARD_XSURF)
z_writeb(0, buddha_board+BUDDHA_IRQ_MR);
printk(KERN_INFO "ide: %s IDE controller\n",
buddha_board_name[type]);
for (i = 0; i < buddha_num_hwifs; i++) {
unsigned long base, ctl, irq_port;
if (type != BOARD_XSURF) {
base = buddha_board + buddha_bases[i];
ctl = base + BUDDHA_CONTROL;
irq_port = buddha_board + buddha_irqports[i];
} else {
base = buddha_board + xsurf_bases[i];
ctl = 0;
irq_port = buddha_board + xsurf_irqports[i];
}
buddha_setup_ports(&hw[i], base, ctl, irq_port);
hws[i] = &hw[i];
}
ide_host_add(&d, hws, i, NULL);
}
return 0;
}
