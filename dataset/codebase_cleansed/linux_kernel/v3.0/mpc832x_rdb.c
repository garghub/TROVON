static int __init of_fsl_spi_probe(char *type, char *compatible, u32 sysclk,
struct spi_board_info *board_infos,
unsigned int num_board_infos,
void (*cs_control)(struct spi_device *dev,
bool on))
{
struct device_node *np;
unsigned int i = 0;
for_each_compatible_node(np, type, compatible) {
int ret;
unsigned int j;
const void *prop;
struct resource res[2];
struct platform_device *pdev;
struct fsl_spi_platform_data pdata = {
.cs_control = cs_control,
};
memset(res, 0, sizeof(res));
pdata.sysclk = sysclk;
prop = of_get_property(np, "reg", NULL);
if (!prop)
goto err;
pdata.bus_num = *(u32 *)prop;
prop = of_get_property(np, "cell-index", NULL);
if (prop)
i = *(u32 *)prop;
prop = of_get_property(np, "mode", NULL);
if (prop && !strcmp(prop, "cpu-qe"))
pdata.flags = SPI_QE_CPU_MODE;
for (j = 0; j < num_board_infos; j++) {
if (board_infos[j].bus_num == pdata.bus_num)
pdata.max_chipselect++;
}
if (!pdata.max_chipselect)
continue;
ret = of_address_to_resource(np, 0, &res[0]);
if (ret)
goto err;
ret = of_irq_to_resource(np, 0, &res[1]);
if (ret == NO_IRQ)
goto err;
pdev = platform_device_alloc("mpc83xx_spi", i);
if (!pdev)
goto err;
ret = platform_device_add_data(pdev, &pdata, sizeof(pdata));
if (ret)
goto unreg;
ret = platform_device_add_resources(pdev, res,
ARRAY_SIZE(res));
if (ret)
goto unreg;
ret = platform_device_add(pdev);
if (ret)
goto unreg;
goto next;
unreg:
platform_device_del(pdev);
err:
pr_err("%s: registration failed\n", np->full_name);
next:
i++;
}
return i;
}
static int __init fsl_spi_init(struct spi_board_info *board_infos,
unsigned int num_board_infos,
void (*cs_control)(struct spi_device *spi,
bool on))
{
u32 sysclk = -1;
int ret;
sysclk = get_brgfreq();
if (sysclk == -1) {
sysclk = fsl_get_sys_freq();
if (sysclk == -1)
return -ENODEV;
}
ret = of_fsl_spi_probe(NULL, "fsl,spi", sysclk, board_infos,
num_board_infos, cs_control);
if (!ret)
of_fsl_spi_probe("spi", "fsl_spi", sysclk, board_infos,
num_board_infos, cs_control);
return spi_register_board_info(board_infos, num_board_infos);
}
static void mpc83xx_spi_cs_control(struct spi_device *spi, bool on)
{
pr_debug("%s %d %d\n", __func__, spi->chip_select, on);
par_io_data_set(3, 13, on);
}
static int __init mpc832x_spi_init(void)
{
par_io_config_pin(3, 0, 3, 0, 1, 0);
par_io_config_pin(3, 1, 3, 0, 1, 0);
par_io_config_pin(3, 2, 3, 0, 1, 0);
par_io_config_pin(3, 3, 2, 0, 1, 0);
par_io_config_pin(3, 13, 1, 0, 0, 0);
par_io_config_pin(3, 14, 2, 0, 0, 0);
par_io_config_pin(3, 15, 2, 0, 0, 0);
if (of_find_compatible_node(NULL, NULL, "mmc-spi-slot"))
return 0;
return fsl_spi_init(&mpc832x_spi_boardinfo, 1, mpc83xx_spi_cs_control);
}
static void __init mpc832x_rdb_setup_arch(void)
{
#if defined(CONFIG_PCI) || defined(CONFIG_QUICC_ENGINE)
struct device_node *np;
#endif
if (ppc_md.progress)
ppc_md.progress("mpc832x_rdb_setup_arch()", 0);
#ifdef CONFIG_PCI
for_each_compatible_node(np, "pci", "fsl,mpc8349-pci")
mpc83xx_add_bridge(np);
#endif
#ifdef CONFIG_QUICC_ENGINE
qe_reset();
if ((np = of_find_node_by_name(NULL, "par_io")) != NULL) {
par_io_init(np);
of_node_put(np);
for (np = NULL; (np = of_find_node_by_name(np, "ucc")) != NULL;)
par_io_of_config(np);
}
#endif
}
static int __init mpc832x_declare_of_platform_devices(void)
{
of_platform_bus_probe(NULL, mpc832x_ids, NULL);
return 0;
}
static void __init mpc832x_rdb_init_IRQ(void)
{
struct device_node *np;
np = of_find_node_by_type(NULL, "ipic");
if (!np)
return;
ipic_init(np, 0);
ipic_set_default_priority();
of_node_put(np);
#ifdef CONFIG_QUICC_ENGINE
np = of_find_compatible_node(NULL, NULL, "fsl,qe-ic");
if (!np) {
np = of_find_node_by_type(NULL, "qeic");
if (!np)
return;
}
qe_ic_init(np, 0, qe_ic_cascade_low_ipic, qe_ic_cascade_high_ipic);
of_node_put(np);
#endif
}
static int __init mpc832x_rdb_probe(void)
{
unsigned long root = of_get_flat_dt_root();
return of_flat_dt_is_compatible(root, "MPC832xRDB");
}
