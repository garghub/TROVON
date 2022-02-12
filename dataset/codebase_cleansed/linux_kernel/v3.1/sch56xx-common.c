static inline int superio_inb(int base, int reg)
{
outb(reg, base);
return inb(base + 1);
}
static inline int superio_enter(int base)
{
if (!request_muxed_region(base, 2, "sch56xx")) {
pr_err("I/O address 0x%04x already in use\n", base);
return -EBUSY;
}
outb(SIO_UNLOCK_KEY, base);
return 0;
}
static inline void superio_select(int base, int ld)
{
outb(SIO_REG_LDSEL, base);
outb(ld, base + 1);
}
static inline void superio_exit(int base)
{
outb(SIO_LOCK_KEY, base);
release_region(base, 2);
}
static int sch56xx_send_cmd(u16 addr, u8 cmd, u16 reg, u8 v)
{
u8 val;
int i;
const int max_busy_polls = 64;
const int max_lazy_polls = 32;
val = inb(addr + 1);
outb(val, addr + 1);
outb(0x00, addr + 2);
outb(0x80, addr + 3);
outb(cmd, addr + 4);
outb(0x01, addr + 5);
outb(0x04, addr + 2);
if (cmd == SCH56XX_CMD_WRITE)
outb(v, addr + 4);
outb(reg & 0xff, addr + 6);
outb(reg >> 8, addr + 7);
outb(0x01, addr);
for (i = 0; i < max_busy_polls + max_lazy_polls; i++) {
if (i >= max_busy_polls)
msleep(1);
val = inb(addr + 8);
if (val)
outb(val, addr + 8);
if (val & 0x01)
break;
}
if (i == max_busy_polls + max_lazy_polls) {
pr_err("Max retries exceeded reading virtual "
"register 0x%04hx (%d)\n", reg, 1);
return -EIO;
}
for (i = 0; i < max_busy_polls; i++) {
val = inb(addr + 1);
if (val == 0x01)
break;
if (i == 0)
pr_warn("EC reports: 0x%02x reading virtual register "
"0x%04hx\n", (unsigned int)val, reg);
}
if (i == max_busy_polls) {
pr_err("Max retries exceeded reading virtual "
"register 0x%04hx (%d)\n", reg, 2);
return -EIO;
}
if (cmd == SCH56XX_CMD_READ)
return inb(addr + 4);
return 0;
}
int sch56xx_read_virtual_reg(u16 addr, u16 reg)
{
return sch56xx_send_cmd(addr, SCH56XX_CMD_READ, reg, 0);
}
int sch56xx_write_virtual_reg(u16 addr, u16 reg, u8 val)
{
return sch56xx_send_cmd(addr, SCH56XX_CMD_WRITE, reg, val);
}
int sch56xx_read_virtual_reg16(u16 addr, u16 reg)
{
int lsb, msb;
lsb = sch56xx_read_virtual_reg(addr, reg);
if (lsb < 0)
return lsb;
msb = sch56xx_read_virtual_reg(addr, reg + 1);
if (msb < 0)
return msb;
return lsb | (msb << 8);
}
int sch56xx_read_virtual_reg12(u16 addr, u16 msb_reg, u16 lsn_reg,
int high_nibble)
{
int msb, lsn;
msb = sch56xx_read_virtual_reg(addr, msb_reg);
if (msb < 0)
return msb;
lsn = sch56xx_read_virtual_reg(addr, lsn_reg);
if (lsn < 0)
return lsn;
if (high_nibble)
return (msb << 4) | (lsn >> 4);
else
return (msb << 4) | (lsn & 0x0f);
}
static int __init sch56xx_find(int sioaddr, unsigned short *address,
const char **name)
{
u8 devid;
int err;
err = superio_enter(sioaddr);
if (err)
return err;
devid = superio_inb(sioaddr, SIO_REG_DEVID);
switch (devid) {
case SIO_SCH5627_ID:
*name = "sch5627";
break;
case SIO_SCH5636_ID:
*name = "sch5636";
break;
default:
pr_debug("Unsupported device id: 0x%02x\n",
(unsigned int)devid);
err = -ENODEV;
goto exit;
}
superio_select(sioaddr, SIO_SCH56XX_LD_EM);
if (!(superio_inb(sioaddr, SIO_REG_ENABLE) & 0x01)) {
pr_warn("Device not activated\n");
err = -ENODEV;
goto exit;
}
*address = superio_inb(sioaddr, SIO_REG_ADDR) |
superio_inb(sioaddr, SIO_REG_ADDR + 1) << 8;
if (*address == 0) {
pr_warn("Base address not set\n");
err = -ENODEV;
goto exit;
}
exit:
superio_exit(sioaddr);
return err;
}
static int __init sch56xx_device_add(unsigned short address, const char *name)
{
struct resource res = {
.start = address,
.end = address + REGION_LENGTH - 1,
.flags = IORESOURCE_IO,
};
int err;
sch56xx_pdev = platform_device_alloc(name, address);
if (!sch56xx_pdev)
return -ENOMEM;
res.name = sch56xx_pdev->name;
err = acpi_check_resource_conflict(&res);
if (err)
goto exit_device_put;
err = platform_device_add_resources(sch56xx_pdev, &res, 1);
if (err) {
pr_err("Device resource addition failed\n");
goto exit_device_put;
}
err = platform_device_add(sch56xx_pdev);
if (err) {
pr_err("Device addition failed\n");
goto exit_device_put;
}
return 0;
exit_device_put:
platform_device_put(sch56xx_pdev);
return err;
}
static int __init sch56xx_init(void)
{
int err;
unsigned short address;
const char *name;
err = sch56xx_find(0x4e, &address, &name);
if (err)
err = sch56xx_find(0x2e, &address, &name);
if (err)
return err;
return sch56xx_device_add(address, name);
}
static void __exit sch56xx_exit(void)
{
platform_device_unregister(sch56xx_pdev);
}
