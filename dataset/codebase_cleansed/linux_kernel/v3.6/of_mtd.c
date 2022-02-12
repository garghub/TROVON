int of_get_nand_ecc_mode(struct device_node *np)
{
const char *pm;
int err, i;
err = of_property_read_string(np, "nand-ecc-mode", &pm);
if (err < 0)
return err;
for (i = 0; i < ARRAY_SIZE(nand_ecc_modes); i++)
if (!strcasecmp(pm, nand_ecc_modes[i]))
return i;
return -ENODEV;
}
int of_get_nand_bus_width(struct device_node *np)
{
u32 val;
if (of_property_read_u32(np, "nand-bus-width", &val))
return 8;
switch(val) {
case 8:
case 16:
return val;
default:
return -EIO;
}
}
bool of_get_nand_on_flash_bbt(struct device_node *np)
{
return of_property_read_bool(np, "nand-on-flash-bbt");
}
