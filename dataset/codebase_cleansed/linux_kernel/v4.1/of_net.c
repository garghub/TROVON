int of_get_phy_mode(struct device_node *np)
{
const char *pm;
int err, i;
err = of_property_read_string(np, "phy-mode", &pm);
if (err < 0)
err = of_property_read_string(np, "phy-connection-type", &pm);
if (err < 0)
return err;
for (i = 0; i < PHY_INTERFACE_MODE_MAX; i++)
if (!strcasecmp(pm, phy_modes(i)))
return i;
return -ENODEV;
}
static const void *of_get_mac_addr(struct device_node *np, const char *name)
{
struct property *pp = of_find_property(np, name, NULL);
if (pp && pp->length == ETH_ALEN && is_valid_ether_addr(pp->value))
return pp->value;
return NULL;
}
const void *of_get_mac_address(struct device_node *np)
{
const void *addr;
addr = of_get_mac_addr(np, "mac-address");
if (addr)
return addr;
addr = of_get_mac_addr(np, "local-mac-address");
if (addr)
return addr;
return of_get_mac_addr(np, "address");
}
