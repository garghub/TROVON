int of_get_phy_mode(struct device_node *np)
{
const char *pm;
int err, i;
err = of_property_read_string(np, "phy-mode", &pm);
if (err < 0)
return err;
for (i = 0; i < ARRAY_SIZE(phy_modes); i++)
if (!strcasecmp(pm, phy_modes[i]))
return i;
return -ENODEV;
}
const void *of_get_mac_address(struct device_node *np)
{
struct property *pp;
pp = of_find_property(np, "mac-address", NULL);
if (pp && (pp->length == 6) && is_valid_ether_addr(pp->value))
return pp->value;
pp = of_find_property(np, "local-mac-address", NULL);
if (pp && (pp->length == 6) && is_valid_ether_addr(pp->value))
return pp->value;
pp = of_find_property(np, "address", NULL);
if (pp && (pp->length == 6) && is_valid_ether_addr(pp->value))
return pp->value;
return NULL;
}
