static bool __init omap3xxx_hwmod_is_hs_ip_block_usable(struct device_node *bus,
const char *dev_name)
{
struct device_node *node;
bool available;
if (!bus)
return omap_type() == OMAP2_DEVICE_TYPE_GP;
node = of_get_child_by_name(bus, dev_name);
available = of_device_is_available(node);
of_node_put(node);
return available;
}
int __init omap3xxx_hwmod_init(void)
{
int r;
struct omap_hwmod_ocp_if **h = NULL, **h_gp = NULL, **h_sham = NULL;
struct omap_hwmod_ocp_if **h_aes = NULL;
struct device_node *bus = NULL;
unsigned int rev;
omap_hwmod_init();
r = omap_hwmod_register_links(omap3xxx_hwmod_ocp_ifs);
if (r < 0)
return r;
rev = omap_rev();
if (rev == OMAP3430_REV_ES1_0 || rev == OMAP3430_REV_ES2_0 ||
rev == OMAP3430_REV_ES2_1 || rev == OMAP3430_REV_ES3_0 ||
rev == OMAP3430_REV_ES3_1 || rev == OMAP3430_REV_ES3_1_2) {
h = omap34xx_hwmod_ocp_ifs;
h_gp = omap34xx_gp_hwmod_ocp_ifs;
h_sham = omap34xx_sham_hwmod_ocp_ifs;
h_aes = omap34xx_aes_hwmod_ocp_ifs;
} else if (rev == AM35XX_REV_ES1_0 || rev == AM35XX_REV_ES1_1) {
h = am35xx_hwmod_ocp_ifs;
h_gp = am35xx_gp_hwmod_ocp_ifs;
h_sham = am35xx_sham_hwmod_ocp_ifs;
h_aes = am35xx_aes_hwmod_ocp_ifs;
} else if (rev == OMAP3630_REV_ES1_0 || rev == OMAP3630_REV_ES1_1 ||
rev == OMAP3630_REV_ES1_2) {
h = omap36xx_hwmod_ocp_ifs;
h_gp = omap36xx_gp_hwmod_ocp_ifs;
h_sham = omap36xx_sham_hwmod_ocp_ifs;
h_aes = omap36xx_aes_hwmod_ocp_ifs;
} else {
WARN(1, "OMAP3 hwmod family init: unknown chip type\n");
return -EINVAL;
}
r = omap_hwmod_register_links(h);
if (r < 0)
return r;
if (h_gp && omap_type() == OMAP2_DEVICE_TYPE_GP) {
r = omap_hwmod_register_links(h_gp);
if (r < 0)
return r;
}
bus = of_find_node_by_name(NULL, "ocp");
if (h_sham && omap3xxx_hwmod_is_hs_ip_block_usable(bus, "sham")) {
r = omap_hwmod_register_links(h_sham);
if (r < 0) {
of_node_put(bus);
return r;
}
}
if (h_aes && omap3xxx_hwmod_is_hs_ip_block_usable(bus, "aes")) {
r = omap_hwmod_register_links(h_aes);
if (r < 0) {
of_node_put(bus);
return r;
}
}
of_node_put(bus);
h = NULL;
if (rev == OMAP3430_REV_ES1_0) {
h = omap3430es1_hwmod_ocp_ifs;
} else if (rev == OMAP3430_REV_ES2_0 || rev == OMAP3430_REV_ES2_1 ||
rev == OMAP3430_REV_ES3_0 || rev == OMAP3430_REV_ES3_1 ||
rev == OMAP3430_REV_ES3_1_2) {
h = omap3430es2plus_hwmod_ocp_ifs;
}
if (h) {
r = omap_hwmod_register_links(h);
if (r < 0)
return r;
}
h = NULL;
if (rev == OMAP3430_REV_ES1_0 || rev == OMAP3430_REV_ES2_0 ||
rev == OMAP3430_REV_ES2_1) {
h = omap3430_pre_es3_hwmod_ocp_ifs;
} else if (rev == OMAP3430_REV_ES3_0 || rev == OMAP3430_REV_ES3_1 ||
rev == OMAP3430_REV_ES3_1_2) {
h = omap3430_es3plus_hwmod_ocp_ifs;
}
if (h)
r = omap_hwmod_register_links(h);
if (r < 0)
return r;
r = omap_hwmod_register_links(omap3xxx_dss_hwmod_ocp_ifs);
return r;
}
