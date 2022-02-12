static void mm_outsw(unsigned long addr, void *buf, u32 len)
{
unsigned short *bp = (unsigned short *)buf;
for (; len > 0; len--, bp++)
*(volatile u16 *)addr = bswap(*bp);
}
static void mm_insw(unsigned long addr, void *buf, u32 len)
{
unsigned short *bp = (unsigned short *)buf;
for (; len > 0; len--, bp++)
*bp = bswap(*(volatile u16 *)addr);
}
static void h8300_input_data(ide_drive_t *drive, struct ide_cmd *cmd,
void *buf, unsigned int len)
{
mm_insw(drive->hwif->io_ports.data_addr, buf, (len + 1) / 2);
}
static void h8300_output_data(ide_drive_t *drive, struct ide_cmd *cmd,
void *buf, unsigned int len)
{
mm_outsw(drive->hwif->io_ports.data_addr, buf, (len + 1) / 2);
}
static inline void hw_setup(struct ide_hw *hw)
{
int i;
memset(hw, 0, sizeof(*hw));
for (i = 0; i <= 7; i++)
hw->io_ports_array[i] = CONFIG_H8300_IDE_BASE + H8300_IDE_GAP*i;
hw->io_ports.ctl_addr = CONFIG_H8300_IDE_ALT;
hw->irq = EXT_IRQ0 + CONFIG_H8300_IDE_IRQ;
}
static int __init h8300_ide_init(void)
{
struct ide_hw hw, *hws[] = { &hw };
printk(KERN_INFO DRV_NAME ": H8/300 generic IDE interface\n");
if (!request_region(CONFIG_H8300_IDE_BASE, H8300_IDE_GAP*8, "ide-h8300"))
goto out_busy;
if (!request_region(CONFIG_H8300_IDE_ALT, H8300_IDE_GAP, "ide-h8300")) {
release_region(CONFIG_H8300_IDE_BASE, H8300_IDE_GAP*8);
goto out_busy;
}
hw_setup(&hw);
return ide_host_add(&h8300_port_info, hws, 1, NULL);
out_busy:
printk(KERN_ERR "ide-h8300: IDE I/F resource already used.\n");
return -EBUSY;
}
