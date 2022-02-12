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
