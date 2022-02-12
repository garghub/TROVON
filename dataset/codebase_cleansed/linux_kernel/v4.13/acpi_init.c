static int __init register_acpi_resource(void)
{
request_region(SBX00_ACPI_IO_BASE, SBX00_ACPI_IO_SIZE, "acpi");
return 0;
}
static void pmio_write_index(u16 index, u8 reg, u8 value)
{
outb(reg, index);
outb(value, index + 1);
}
static u8 pmio_read_index(u16 index, u8 reg)
{
outb(reg, index);
return inb(index + 1);
}
void pm_iowrite(u8 reg, u8 value)
{
pmio_write_index(PM_INDEX, reg, value);
}
u8 pm_ioread(u8 reg)
{
return pmio_read_index(PM_INDEX, reg);
}
void pm2_iowrite(u8 reg, u8 value)
{
pmio_write_index(PM2_INDEX, reg, value);
}
u8 pm2_ioread(u8 reg)
{
return pmio_read_index(PM2_INDEX, reg);
}
static void acpi_hw_clear_status(void)
{
u16 value;
value = inw(ACPI_PM_EVT_BLK);
value |= (1 << 8 | 1 << 15);
outw(value, ACPI_PM_EVT_BLK);
outl(inl(ACPI_GPE0_BLK), ACPI_GPE0_BLK);
}
void acpi_registers_setup(void)
{
u32 value;
pm_iowrite(0x20, ACPI_PM_EVT_BLK & 0xff);
pm_iowrite(0x21, ACPI_PM_EVT_BLK >> 8);
pm_iowrite(0x22, ACPI_PM_CNT_BLK & 0xff);
pm_iowrite(0x23, ACPI_PM_CNT_BLK >> 8);
pm_iowrite(0x28, ACPI_GPE0_BLK & 0xff);
pm_iowrite(0x29, ACPI_GPE0_BLK >> 8);
pm_iowrite(0x2e, ACPI_END & 0xff);
pm_iowrite(0x2f, ACPI_END >> 8);
pm_iowrite(0x0e, 1 << 3);
outw(1, ACPI_PM_CNT_BLK);
pm_iowrite(0x10, pm_ioread(0x10) | 1);
value = inl(ACPI_GPE0_BLK + 4);
outl(value | (1 << 14) | (1 << 22), ACPI_GPE0_BLK + 4);
pm_iowrite(0x8d, pm_ioread(0x8d) & (~(1 << 1)));
pm_iowrite(0x94, pm_ioread(0x94) | (1 << 3));
pm_iowrite(0x33, pm_ioread(0x33) & (~(3 << 4)));
pm_iowrite(0x3d, pm_ioread(0x3d) & (~(3 << 2)));
pm_iowrite(0x37, pm_ioread(0x37) & (~(1 << 6)));
pm_iowrite(0x7c, pm_ioread(0x7c) | (1 << 6));
value = pm2_ioread(0xf6);
value |= ((1 << 7) | (1 << 3));
pm2_iowrite(0xf6, value);
value = pm2_ioread(0xf8);
value |= ((1 << 5) | (1 << 1));
pm2_iowrite(0xf8, value);
}
int __init sbx00_acpi_init(void)
{
register_acpi_resource();
acpi_registers_setup();
acpi_hw_clear_status();
return 0;
}
