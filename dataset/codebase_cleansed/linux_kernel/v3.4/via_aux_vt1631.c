void via_aux_vt1631_probe(struct via_aux_bus *bus)
{
struct via_aux_drv drv = {
.bus = bus,
.addr = 0x38,
.name = name};
const u8 id[] = {0x06, 0x11, 0x91, 0x31}, len = ARRAY_SIZE(id);
u8 tmp[len];
if (!via_aux_read(&drv, 0x00, tmp, len) || memcmp(id, tmp, len))
return;
printk(KERN_INFO "viafb: Found %s\n", name);
via_aux_add(&drv);
}
