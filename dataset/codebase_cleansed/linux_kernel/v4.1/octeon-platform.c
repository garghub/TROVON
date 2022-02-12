static int __init octeon_rng_device_init(void)
{
struct platform_device *pd;
int ret = 0;
struct resource rng_resources[] = {
{
.flags = IORESOURCE_MEM,
.start = XKPHYS_TO_PHYS(CVMX_RNM_CTL_STATUS),
.end = XKPHYS_TO_PHYS(CVMX_RNM_CTL_STATUS) + 0xf
}, {
.flags = IORESOURCE_MEM,
.start = cvmx_build_io_address(8, 0),
.end = cvmx_build_io_address(8, 0) + 0x7
}
};
pd = platform_device_alloc("octeon_rng", -1);
if (!pd) {
ret = -ENOMEM;
goto out;
}
ret = platform_device_add_resources(pd, rng_resources,
ARRAY_SIZE(rng_resources));
if (ret)
goto fail;
ret = platform_device_add(pd);
if (ret)
goto fail;
return ret;
fail:
platform_device_put(pd);
out:
return ret;
}
static void octeon2_usb_clocks_start(struct device *dev)
{
u64 div;
union cvmx_uctlx_if_ena if_ena;
union cvmx_uctlx_clk_rst_ctl clk_rst_ctl;
union cvmx_uctlx_uphy_ctl_status uphy_ctl_status;
union cvmx_uctlx_uphy_portx_ctl_status port_ctl_status;
int i;
unsigned long io_clk_64_to_ns;
u32 clock_rate = 12000000;
bool is_crystal_clock = false;
mutex_lock(&octeon2_usb_clocks_mutex);
octeon2_usb_clock_start_cnt++;
if (octeon2_usb_clock_start_cnt != 1)
goto exit;
io_clk_64_to_ns = 64000000000ull / octeon_get_io_clock_rate();
if (dev->of_node) {
struct device_node *uctl_node;
const char *clock_type;
uctl_node = of_get_parent(dev->of_node);
if (!uctl_node) {
dev_err(dev, "No UCTL device node\n");
goto exit;
}
i = of_property_read_u32(uctl_node,
"refclk-frequency", &clock_rate);
if (i) {
dev_err(dev, "No UCTL \"refclk-frequency\"\n");
goto exit;
}
i = of_property_read_string(uctl_node,
"refclk-type", &clock_type);
if (!i && strcmp("crystal", clock_type) == 0)
is_crystal_clock = true;
}
if_ena.u64 = 0;
if_ena.s.en = 1;
cvmx_write_csr(CVMX_UCTLX_IF_ENA(0), if_ena.u64);
clk_rst_ctl.u64 = cvmx_read_csr(CVMX_UCTLX_CLK_RST_CTL(0));
if (clk_rst_ctl.s.hrst)
goto end_clock;
clk_rst_ctl.s.p_por = 1;
clk_rst_ctl.s.hrst = 0;
clk_rst_ctl.s.p_prst = 0;
clk_rst_ctl.s.h_clkdiv_rst = 0;
clk_rst_ctl.s.o_clkdiv_rst = 0;
clk_rst_ctl.s.h_clkdiv_en = 0;
clk_rst_ctl.s.o_clkdiv_en = 0;
cvmx_write_csr(CVMX_UCTLX_CLK_RST_CTL(0), clk_rst_ctl.u64);
clk_rst_ctl.s.p_refclk_sel = is_crystal_clock ? 0 : 1;
switch (clock_rate) {
default:
pr_err("Invalid UCTL clock rate of %u, using 12000000 instead\n",
clock_rate);
case 12000000:
clk_rst_ctl.s.p_refclk_div = 0;
break;
case 24000000:
clk_rst_ctl.s.p_refclk_div = 1;
break;
case 48000000:
clk_rst_ctl.s.p_refclk_div = 2;
break;
}
cvmx_write_csr(CVMX_UCTLX_CLK_RST_CTL(0), clk_rst_ctl.u64);
div = octeon_get_io_clock_rate() / 130000000ull;
switch (div) {
case 0:
div = 1;
break;
case 1:
case 2:
case 3:
case 4:
break;
case 5:
div = 4;
break;
case 6:
case 7:
div = 6;
break;
case 8:
case 9:
case 10:
case 11:
div = 8;
break;
default:
div = 12;
break;
}
clk_rst_ctl.s.h_div = div;
cvmx_write_csr(CVMX_UCTLX_CLK_RST_CTL(0), clk_rst_ctl.u64);
clk_rst_ctl.u64 = cvmx_read_csr(CVMX_UCTLX_CLK_RST_CTL(0));
clk_rst_ctl.s.h_clkdiv_en = 1;
cvmx_write_csr(CVMX_UCTLX_CLK_RST_CTL(0), clk_rst_ctl.u64);
clk_rst_ctl.s.h_clkdiv_rst = 1;
cvmx_write_csr(CVMX_UCTLX_CLK_RST_CTL(0), clk_rst_ctl.u64);
ndelay(io_clk_64_to_ns);
clk_rst_ctl.s.p_por = 0;
cvmx_write_csr(CVMX_UCTLX_CLK_RST_CTL(0), clk_rst_ctl.u64);
mdelay(1);
uphy_ctl_status.u64 = cvmx_read_csr(CVMX_UCTLX_UPHY_CTL_STATUS(0));
uphy_ctl_status.s.ate_reset = 1;
cvmx_write_csr(CVMX_UCTLX_UPHY_CTL_STATUS(0), uphy_ctl_status.u64);
ndelay(10);
uphy_ctl_status.s.ate_reset = 0;
cvmx_write_csr(CVMX_UCTLX_UPHY_CTL_STATUS(0), uphy_ctl_status.u64);
ndelay(20);
clk_rst_ctl.s.o_clkdiv_rst = 1;
cvmx_write_csr(CVMX_UCTLX_CLK_RST_CTL(0), clk_rst_ctl.u64);
clk_rst_ctl.s.o_clkdiv_en = 1;
cvmx_write_csr(CVMX_UCTLX_CLK_RST_CTL(0), clk_rst_ctl.u64);
ndelay(io_clk_64_to_ns);
clk_rst_ctl.s.p_prst = 1;
cvmx_write_csr(CVMX_UCTLX_CLK_RST_CTL(0), clk_rst_ctl.u64);
udelay(1);
clk_rst_ctl.s.hrst = 1;
cvmx_write_csr(CVMX_UCTLX_CLK_RST_CTL(0), clk_rst_ctl.u64);
end_clock:
for (i = 0; i <= 1; i++) {
port_ctl_status.u64 =
cvmx_read_csr(CVMX_UCTLX_UPHY_PORTX_CTL_STATUS(i, 0));
port_ctl_status.s.txvreftune = 15;
port_ctl_status.s.txrisetune = 1;
port_ctl_status.s.txpreemphasistune = 1;
cvmx_write_csr(CVMX_UCTLX_UPHY_PORTX_CTL_STATUS(i, 0),
port_ctl_status.u64);
}
cvmx_write_csr(CVMX_UCTLX_EHCI_FLA(0), 0x20ull);
exit:
mutex_unlock(&octeon2_usb_clocks_mutex);
}
static void octeon2_usb_clocks_stop(void)
{
mutex_lock(&octeon2_usb_clocks_mutex);
octeon2_usb_clock_start_cnt--;
mutex_unlock(&octeon2_usb_clocks_mutex);
}
static int octeon_ehci_power_on(struct platform_device *pdev)
{
octeon2_usb_clocks_start(&pdev->dev);
return 0;
}
static void octeon_ehci_power_off(struct platform_device *pdev)
{
octeon2_usb_clocks_stop();
}
static void __init octeon_ehci_hw_start(struct device *dev)
{
union cvmx_uctlx_ehci_ctl ehci_ctl;
octeon2_usb_clocks_start(dev);
ehci_ctl.u64 = cvmx_read_csr(CVMX_UCTLX_EHCI_CTL(0));
ehci_ctl.s.ehci_64b_addr_en = 1;
ehci_ctl.s.l2c_addr_msb = 0;
#ifdef __BIG_ENDIAN
ehci_ctl.s.l2c_buff_emod = 1;
ehci_ctl.s.l2c_desc_emod = 1;
#else
ehci_ctl.s.l2c_buff_emod = 0;
ehci_ctl.s.l2c_desc_emod = 0;
ehci_ctl.s.inv_reg_a2 = 1;
#endif
cvmx_write_csr(CVMX_UCTLX_EHCI_CTL(0), ehci_ctl.u64);
octeon2_usb_clocks_stop();
}
static int __init octeon_ehci_device_init(void)
{
struct platform_device *pd;
struct device_node *ehci_node;
int ret = 0;
ehci_node = of_find_node_by_name(NULL, "ehci");
if (!ehci_node)
return 0;
pd = of_find_device_by_node(ehci_node);
if (!pd)
return 0;
pd->dev.platform_data = &octeon_ehci_pdata;
octeon_ehci_hw_start(&pd->dev);
return ret;
}
static int octeon_ohci_power_on(struct platform_device *pdev)
{
octeon2_usb_clocks_start(&pdev->dev);
return 0;
}
static void octeon_ohci_power_off(struct platform_device *pdev)
{
octeon2_usb_clocks_stop();
}
static void __init octeon_ohci_hw_start(struct device *dev)
{
union cvmx_uctlx_ohci_ctl ohci_ctl;
octeon2_usb_clocks_start(dev);
ohci_ctl.u64 = cvmx_read_csr(CVMX_UCTLX_OHCI_CTL(0));
ohci_ctl.s.l2c_addr_msb = 0;
#ifdef __BIG_ENDIAN
ohci_ctl.s.l2c_buff_emod = 1;
ohci_ctl.s.l2c_desc_emod = 1;
#else
ohci_ctl.s.l2c_buff_emod = 0;
ohci_ctl.s.l2c_desc_emod = 0;
ohci_ctl.s.inv_reg_a2 = 1;
#endif
cvmx_write_csr(CVMX_UCTLX_OHCI_CTL(0), ohci_ctl.u64);
octeon2_usb_clocks_stop();
}
static int __init octeon_ohci_device_init(void)
{
struct platform_device *pd;
struct device_node *ohci_node;
int ret = 0;
ohci_node = of_find_node_by_name(NULL, "ohci");
if (!ohci_node)
return 0;
pd = of_find_device_by_node(ohci_node);
if (!pd)
return 0;
pd->dev.platform_data = &octeon_ohci_pdata;
octeon_ohci_hw_start(&pd->dev);
return ret;
}
static bool __init octeon_has_88e1145(void)
{
return !OCTEON_IS_MODEL(OCTEON_CN52XX) &&
!OCTEON_IS_MODEL(OCTEON_CN6XXX) &&
!OCTEON_IS_MODEL(OCTEON_CN56XX);
}
static void __init octeon_fdt_set_phy(int eth, int phy_addr)
{
const __be32 *phy_handle;
const __be32 *alt_phy_handle;
const __be32 *reg;
u32 phandle;
int phy;
int alt_phy;
const char *p;
int current_len;
char new_name[20];
phy_handle = fdt_getprop(initial_boot_params, eth, "phy-handle", NULL);
if (!phy_handle)
return;
phandle = be32_to_cpup(phy_handle);
phy = fdt_node_offset_by_phandle(initial_boot_params, phandle);
alt_phy_handle = fdt_getprop(initial_boot_params, eth, "cavium,alt-phy-handle", NULL);
if (alt_phy_handle) {
u32 alt_phandle = be32_to_cpup(alt_phy_handle);
alt_phy = fdt_node_offset_by_phandle(initial_boot_params, alt_phandle);
} else {
alt_phy = -1;
}
if (phy_addr < 0 || phy < 0) {
fdt_nop_property(initial_boot_params, eth, "phy-handle");
fdt_nop_property(initial_boot_params, eth, "cavium,alt-phy-handle");
if (phy >= 0)
fdt_nop_node(initial_boot_params, phy);
if (alt_phy >= 0)
fdt_nop_node(initial_boot_params, alt_phy);
return;
}
if (phy_addr >= 256 && alt_phy > 0) {
const struct fdt_property *phy_prop;
struct fdt_property *alt_prop;
u32 phy_handle_name;
phy_prop = fdt_get_property(initial_boot_params, eth, "phy-handle", NULL);
phy_handle_name = phy_prop->nameoff;
fdt_nop_node(initial_boot_params, phy);
fdt_nop_property(initial_boot_params, eth, "phy-handle");
alt_prop = fdt_get_property_w(initial_boot_params, eth, "cavium,alt-phy-handle", NULL);
alt_prop->nameoff = phy_handle_name;
phy = alt_phy;
}
phy_addr &= 0xff;
if (octeon_has_88e1145()) {
fdt_nop_property(initial_boot_params, phy, "marvell,reg-init");
memset(new_name, 0, sizeof(new_name));
strcpy(new_name, "marvell,88e1145");
p = fdt_getprop(initial_boot_params, phy, "compatible",
&current_len);
if (p && current_len >= strlen(new_name))
fdt_setprop_inplace(initial_boot_params, phy,
"compatible", new_name, current_len);
}
reg = fdt_getprop(initial_boot_params, phy, "reg", NULL);
if (phy_addr == be32_to_cpup(reg))
return;
fdt_setprop_inplace_cell(initial_boot_params, phy, "reg", phy_addr);
snprintf(new_name, sizeof(new_name), "ethernet-phy@%x", phy_addr);
p = fdt_get_name(initial_boot_params, phy, &current_len);
if (p && current_len == strlen(new_name))
fdt_set_name(initial_boot_params, phy, new_name);
else
pr_err("Error: could not rename ethernet phy: <%s>", p);
}
static void __init octeon_fdt_set_mac_addr(int n, u64 *pmac)
{
u8 new_mac[6];
u64 mac = *pmac;
int r;
new_mac[0] = (mac >> 40) & 0xff;
new_mac[1] = (mac >> 32) & 0xff;
new_mac[2] = (mac >> 24) & 0xff;
new_mac[3] = (mac >> 16) & 0xff;
new_mac[4] = (mac >> 8) & 0xff;
new_mac[5] = mac & 0xff;
r = fdt_setprop_inplace(initial_boot_params, n, "local-mac-address",
new_mac, sizeof(new_mac));
if (r) {
pr_err("Setting \"local-mac-address\" failed %d", r);
return;
}
*pmac = mac + 1;
}
static void __init octeon_fdt_rm_ethernet(int node)
{
const __be32 *phy_handle;
phy_handle = fdt_getprop(initial_boot_params, node, "phy-handle", NULL);
if (phy_handle) {
u32 ph = be32_to_cpup(phy_handle);
int p = fdt_node_offset_by_phandle(initial_boot_params, ph);
if (p >= 0)
fdt_nop_node(initial_boot_params, p);
}
fdt_nop_node(initial_boot_params, node);
}
static void __init octeon_fdt_pip_port(int iface, int i, int p, int max, u64 *pmac)
{
char name_buffer[20];
int eth;
int phy_addr;
int ipd_port;
snprintf(name_buffer, sizeof(name_buffer), "ethernet@%x", p);
eth = fdt_subnode_offset(initial_boot_params, iface, name_buffer);
if (eth < 0)
return;
if (p > max) {
pr_debug("Deleting port %x:%x\n", i, p);
octeon_fdt_rm_ethernet(eth);
return;
}
if (OCTEON_IS_MODEL(OCTEON_CN68XX))
ipd_port = (0x100 * i) + (0x10 * p) + 0x800;
else
ipd_port = 16 * i + p;
phy_addr = cvmx_helper_board_get_mii_address(ipd_port);
octeon_fdt_set_phy(eth, phy_addr);
octeon_fdt_set_mac_addr(eth, pmac);
}
static void __init octeon_fdt_pip_iface(int pip, int idx, u64 *pmac)
{
char name_buffer[20];
int iface;
int p;
int count = 0;
snprintf(name_buffer, sizeof(name_buffer), "interface@%d", idx);
iface = fdt_subnode_offset(initial_boot_params, pip, name_buffer);
if (iface < 0)
return;
if (cvmx_helper_interface_enumerate(idx) == 0)
count = cvmx_helper_ports_on_interface(idx);
for (p = 0; p < 16; p++)
octeon_fdt_pip_port(iface, idx, p, count - 1, pmac);
}
int __init octeon_prune_device_tree(void)
{
int i, max_port, uart_mask;
const char *pip_path;
const char *alias_prop;
char name_buffer[20];
int aliases;
u64 mac_addr_base;
if (fdt_check_header(initial_boot_params))
panic("Corrupt Device Tree.");
aliases = fdt_path_offset(initial_boot_params, "/aliases");
if (aliases < 0) {
pr_err("Error: No /aliases node in device tree.");
return -EINVAL;
}
mac_addr_base =
((octeon_bootinfo->mac_addr_base[0] & 0xffull)) << 40 |
((octeon_bootinfo->mac_addr_base[1] & 0xffull)) << 32 |
((octeon_bootinfo->mac_addr_base[2] & 0xffull)) << 24 |
((octeon_bootinfo->mac_addr_base[3] & 0xffull)) << 16 |
((octeon_bootinfo->mac_addr_base[4] & 0xffull)) << 8 |
(octeon_bootinfo->mac_addr_base[5] & 0xffull);
if (OCTEON_IS_MODEL(OCTEON_CN52XX) || OCTEON_IS_MODEL(OCTEON_CN63XX))
max_port = 2;
else if (OCTEON_IS_MODEL(OCTEON_CN56XX) || OCTEON_IS_MODEL(OCTEON_CN68XX))
max_port = 1;
else
max_port = 0;
if (octeon_bootinfo->board_type == CVMX_BOARD_TYPE_NIC10E)
max_port = 0;
for (i = 0; i < 2; i++) {
int mgmt;
snprintf(name_buffer, sizeof(name_buffer),
"mix%d", i);
alias_prop = fdt_getprop(initial_boot_params, aliases,
name_buffer, NULL);
if (alias_prop) {
mgmt = fdt_path_offset(initial_boot_params, alias_prop);
if (mgmt < 0)
continue;
if (i >= max_port) {
pr_debug("Deleting mix%d\n", i);
octeon_fdt_rm_ethernet(mgmt);
fdt_nop_property(initial_boot_params, aliases,
name_buffer);
} else {
int phy_addr = cvmx_helper_board_get_mii_address(CVMX_HELPER_BOARD_MGMT_IPD_PORT + i);
octeon_fdt_set_phy(mgmt, phy_addr);
octeon_fdt_set_mac_addr(mgmt, &mac_addr_base);
}
}
}
pip_path = fdt_getprop(initial_boot_params, aliases, "pip", NULL);
if (pip_path) {
int pip = fdt_path_offset(initial_boot_params, pip_path);
if (pip >= 0)
for (i = 0; i <= 4; i++)
octeon_fdt_pip_iface(pip, i, &mac_addr_base);
}
if (OCTEON_IS_MODEL(OCTEON_CN52XX) ||
OCTEON_IS_MODEL(OCTEON_CN63XX) ||
OCTEON_IS_MODEL(OCTEON_CN68XX) ||
OCTEON_IS_MODEL(OCTEON_CN56XX))
max_port = 2;
else
max_port = 1;
for (i = 0; i < 2; i++) {
int i2c;
snprintf(name_buffer, sizeof(name_buffer),
"twsi%d", i);
alias_prop = fdt_getprop(initial_boot_params, aliases,
name_buffer, NULL);
if (alias_prop) {
i2c = fdt_path_offset(initial_boot_params, alias_prop);
if (i2c < 0)
continue;
if (i >= max_port) {
pr_debug("Deleting twsi%d\n", i);
fdt_nop_node(initial_boot_params, i2c);
fdt_nop_property(initial_boot_params, aliases,
name_buffer);
}
}
}
if (OCTEON_IS_MODEL(OCTEON_CN68XX))
max_port = 4;
else if (OCTEON_IS_MODEL(OCTEON_CN52XX) ||
OCTEON_IS_MODEL(OCTEON_CN63XX) ||
OCTEON_IS_MODEL(OCTEON_CN56XX))
max_port = 2;
else
max_port = 1;
for (i = 0; i < 2; i++) {
int i2c;
snprintf(name_buffer, sizeof(name_buffer),
"smi%d", i);
alias_prop = fdt_getprop(initial_boot_params, aliases,
name_buffer, NULL);
if (alias_prop) {
i2c = fdt_path_offset(initial_boot_params, alias_prop);
if (i2c < 0)
continue;
if (i >= max_port) {
pr_debug("Deleting smi%d\n", i);
fdt_nop_node(initial_boot_params, i2c);
fdt_nop_property(initial_boot_params, aliases,
name_buffer);
}
}
}
uart_mask = 3;
if (OCTEON_IS_MODEL(OCTEON_CN52XX))
uart_mask |= 4;
for (i = 0; i < 3; i++) {
int uart;
snprintf(name_buffer, sizeof(name_buffer),
"uart%d", i);
alias_prop = fdt_getprop(initial_boot_params, aliases,
name_buffer, NULL);
if (alias_prop) {
uart = fdt_path_offset(initial_boot_params, alias_prop);
if (uart_mask & (1 << i)) {
__be32 f;
f = cpu_to_be32(octeon_get_io_clock_rate());
fdt_setprop_inplace(initial_boot_params,
uart, "clock-frequency",
&f, sizeof(f));
continue;
}
pr_debug("Deleting uart%d\n", i);
fdt_nop_node(initial_boot_params, uart);
fdt_nop_property(initial_boot_params, aliases,
name_buffer);
}
}
alias_prop = fdt_getprop(initial_boot_params, aliases,
"cf0", NULL);
if (alias_prop) {
union cvmx_mio_boot_reg_cfgx mio_boot_reg_cfg;
unsigned long base_ptr, region_base, region_size;
unsigned long region1_base = 0;
unsigned long region1_size = 0;
int cs, bootbus;
bool is_16bit = false;
bool is_true_ide = false;
__be32 new_reg[6];
__be32 *ranges;
int len;
int cf = fdt_path_offset(initial_boot_params, alias_prop);
base_ptr = 0;
if (octeon_bootinfo->major_version == 1
&& octeon_bootinfo->minor_version >= 1) {
if (octeon_bootinfo->compact_flash_common_base_addr)
base_ptr = octeon_bootinfo->compact_flash_common_base_addr;
} else {
base_ptr = 0x1d000800;
}
if (!base_ptr)
goto no_cf;
for (cs = 0; cs < 8; cs++) {
mio_boot_reg_cfg.u64 = cvmx_read_csr(CVMX_MIO_BOOT_REG_CFGX(cs));
region_base = mio_boot_reg_cfg.s.base << 16;
region_size = (mio_boot_reg_cfg.s.size + 1) << 16;
if (mio_boot_reg_cfg.s.en && base_ptr >= region_base
&& base_ptr < region_base + region_size) {
is_16bit = mio_boot_reg_cfg.s.width;
break;
}
}
if (cs >= 7) {
goto no_cf;
}
if (!(base_ptr & 0xfffful)) {
mio_boot_reg_cfg.u64 =
cvmx_read_csr(CVMX_MIO_BOOT_REG_CFGX(cs + 1));
region1_base = mio_boot_reg_cfg.s.base << 16;
region1_size = (mio_boot_reg_cfg.s.size + 1) << 16;
if (!mio_boot_reg_cfg.s.en)
goto no_cf;
is_true_ide = true;
} else {
fdt_nop_property(initial_boot_params, cf, "cavium,true-ide");
fdt_nop_property(initial_boot_params, cf, "cavium,dma-engine-handle");
if (!is_16bit) {
__be32 width = cpu_to_be32(8);
fdt_setprop_inplace(initial_boot_params, cf,
"cavium,bus-width", &width, sizeof(width));
}
}
new_reg[0] = cpu_to_be32(cs);
new_reg[1] = cpu_to_be32(0);
new_reg[2] = cpu_to_be32(0x10000);
new_reg[3] = cpu_to_be32(cs + 1);
new_reg[4] = cpu_to_be32(0);
new_reg[5] = cpu_to_be32(0x10000);
fdt_setprop_inplace(initial_boot_params, cf,
"reg", new_reg, sizeof(new_reg));
bootbus = fdt_parent_offset(initial_boot_params, cf);
if (bootbus < 0)
goto no_cf;
ranges = fdt_getprop_w(initial_boot_params, bootbus, "ranges", &len);
if (!ranges || len < (5 * 8 * sizeof(__be32)))
goto no_cf;
ranges[(cs * 5) + 2] = cpu_to_be32(region_base >> 32);
ranges[(cs * 5) + 3] = cpu_to_be32(region_base & 0xffffffff);
ranges[(cs * 5) + 4] = cpu_to_be32(region_size);
if (is_true_ide) {
cs++;
ranges[(cs * 5) + 2] = cpu_to_be32(region1_base >> 32);
ranges[(cs * 5) + 3] = cpu_to_be32(region1_base & 0xffffffff);
ranges[(cs * 5) + 4] = cpu_to_be32(region1_size);
}
goto end_cf;
no_cf:
fdt_nop_node(initial_boot_params, cf);
end_cf:
;
}
alias_prop = fdt_getprop(initial_boot_params, aliases,
"led0", NULL);
if (alias_prop) {
union cvmx_mio_boot_reg_cfgx mio_boot_reg_cfg;
unsigned long base_ptr, region_base, region_size;
int cs, bootbus;
__be32 new_reg[6];
__be32 *ranges;
int len;
int led = fdt_path_offset(initial_boot_params, alias_prop);
base_ptr = octeon_bootinfo->led_display_base_addr;
if (base_ptr == 0)
goto no_led;
for (cs = 0; cs < 8; cs++) {
mio_boot_reg_cfg.u64 = cvmx_read_csr(CVMX_MIO_BOOT_REG_CFGX(cs));
region_base = mio_boot_reg_cfg.s.base << 16;
region_size = (mio_boot_reg_cfg.s.size + 1) << 16;
if (mio_boot_reg_cfg.s.en && base_ptr >= region_base
&& base_ptr < region_base + region_size)
break;
}
if (cs > 7)
goto no_led;
new_reg[0] = cpu_to_be32(cs);
new_reg[1] = cpu_to_be32(0x20);
new_reg[2] = cpu_to_be32(0x20);
new_reg[3] = cpu_to_be32(cs);
new_reg[4] = cpu_to_be32(0);
new_reg[5] = cpu_to_be32(0x20);
fdt_setprop_inplace(initial_boot_params, led,
"reg", new_reg, sizeof(new_reg));
bootbus = fdt_parent_offset(initial_boot_params, led);
if (bootbus < 0)
goto no_led;
ranges = fdt_getprop_w(initial_boot_params, bootbus, "ranges", &len);
if (!ranges || len < (5 * 8 * sizeof(__be32)))
goto no_led;
ranges[(cs * 5) + 2] = cpu_to_be32(region_base >> 32);
ranges[(cs * 5) + 3] = cpu_to_be32(region_base & 0xffffffff);
ranges[(cs * 5) + 4] = cpu_to_be32(region_size);
goto end_led;
no_led:
fdt_nop_node(initial_boot_params, led);
end_led:
;
}
alias_prop = fdt_getprop(initial_boot_params, aliases,
"uctl", NULL);
if (alias_prop) {
int uctl = fdt_path_offset(initial_boot_params, alias_prop);
if (uctl >= 0 && (!OCTEON_IS_MODEL(OCTEON_CN6XXX) ||
octeon_bootinfo->board_type == CVMX_BOARD_TYPE_NIC2E)) {
pr_debug("Deleting uctl\n");
fdt_nop_node(initial_boot_params, uctl);
fdt_nop_property(initial_boot_params, aliases, "uctl");
} else if (octeon_bootinfo->board_type == CVMX_BOARD_TYPE_NIC10E ||
octeon_bootinfo->board_type == CVMX_BOARD_TYPE_NIC4E) {
fdt_nop_property(initial_boot_params, uctl, "refclk-type");
}
}
alias_prop = fdt_getprop(initial_boot_params, aliases,
"usbn", NULL);
if (alias_prop) {
int usbn = fdt_path_offset(initial_boot_params, alias_prop);
if (usbn >= 0 && (current_cpu_type() == CPU_CAVIUM_OCTEON2 ||
!octeon_has_feature(OCTEON_FEATURE_USB))) {
pr_debug("Deleting usbn\n");
fdt_nop_node(initial_boot_params, usbn);
fdt_nop_property(initial_boot_params, aliases, "usbn");
} else {
__be32 new_f[1];
enum cvmx_helper_board_usb_clock_types c;
c = __cvmx_helper_board_usb_get_clock_type();
switch (c) {
case USB_CLOCK_TYPE_REF_48:
new_f[0] = cpu_to_be32(48000000);
fdt_setprop_inplace(initial_boot_params, usbn,
"refclk-frequency", new_f, sizeof(new_f));
case USB_CLOCK_TYPE_REF_12:
fdt_nop_property(initial_boot_params, usbn, "refclk-type");
break;
default:
break;
}
}
}
if (octeon_bootinfo->board_type != CVMX_BOARD_TYPE_CUST_DSR1000N) {
int dsr1000n_leds = fdt_path_offset(initial_boot_params,
"/dsr1000n-leds");
if (dsr1000n_leds >= 0)
fdt_nop_node(initial_boot_params, dsr1000n_leds);
}
return 0;
}
static int __init octeon_publish_devices(void)
{
return of_platform_bus_probe(NULL, octeon_ids, NULL);
}
