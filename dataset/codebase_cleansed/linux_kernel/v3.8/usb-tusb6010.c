static int tusb_set_async_mode(unsigned sysclk_ps)
{
struct gpmc_device_timings dev_t;
struct gpmc_timings t;
unsigned t_acsnh_advnh = sysclk_ps + 3000;
memset(&dev_t, 0, sizeof(dev_t));
dev_t.mux = true;
dev_t.t_ceasu = 8 * 1000;
dev_t.t_avdasu = t_acsnh_advnh - 7000;
dev_t.t_ce_avd = 1000;
dev_t.t_avdp_r = t_acsnh_advnh;
dev_t.t_oeasu = t_acsnh_advnh + 1000;
dev_t.t_oe = 300;
dev_t.t_cez_r = 7000;
dev_t.t_cez_w = dev_t.t_cez_r;
dev_t.t_avdp_w = t_acsnh_advnh;
dev_t.t_weasu = t_acsnh_advnh + 1000;
dev_t.t_wpl = 300;
dev_t.cyc_aavdh_we = 1;
gpmc_calc_timings(&t, &dev_t);
return gpmc_cs_set_timings(async_cs, &t);
}
static int tusb_set_sync_mode(unsigned sysclk_ps)
{
struct gpmc_device_timings dev_t;
struct gpmc_timings t;
unsigned t_scsnh_advnh = sysclk_ps + 3000;
memset(&dev_t, 0, sizeof(dev_t));
dev_t.mux = true;
dev_t.sync_read = true;
dev_t.sync_write = true;
dev_t.clk = 11100;
dev_t.t_bacc = 1000;
dev_t.t_ces = 1000;
dev_t.t_ceasu = 8 * 1000;
dev_t.t_avdasu = t_scsnh_advnh - 7000;
dev_t.t_ce_avd = 1000;
dev_t.t_avdp_r = t_scsnh_advnh;
dev_t.cyc_aavdh_oe = 3;
dev_t.cyc_oe = 5;
dev_t.t_ce_rdyz = 7000;
dev_t.t_avdp_w = t_scsnh_advnh;
dev_t.cyc_aavdh_we = 3;
dev_t.cyc_wpl = 6;
dev_t.t_ce_rdyz = 7000;
gpmc_calc_timings(&t, &dev_t);
return gpmc_cs_set_timings(sync_cs, &t);
}
int tusb6010_platform_retime(unsigned is_refclk)
{
static const char error[] =
KERN_ERR "tusb6010 %s retime error %d\n";
unsigned sysclk_ps;
int status;
if (!refclk_psec)
return -ENODEV;
sysclk_ps = is_refclk ? refclk_psec : TUSB6010_OSCCLK_60;
status = tusb_set_async_mode(sysclk_ps);
if (status < 0) {
printk(error, "async", status);
goto done;
}
status = tusb_set_sync_mode(sysclk_ps);
if (status < 0)
printk(error, "sync", status);
done:
return status;
}
int __init
tusb6010_setup_interface(struct musb_hdrc_platform_data *data,
unsigned ps_refclk, unsigned waitpin,
unsigned async, unsigned sync,
unsigned irq, unsigned dmachan)
{
int status;
static char error[] __initdata =
KERN_ERR "tusb6010 init error %d, %d\n";
status = gpmc_cs_request(async, SZ_16M, (unsigned long *)
&tusb_resources[0].start);
if (status < 0) {
printk(error, 1, status);
return status;
}
tusb_resources[0].end = tusb_resources[0].start + 0x9ff;
async_cs = async;
gpmc_cs_write_reg(async, GPMC_CS_CONFIG1,
GPMC_CONFIG1_PAGE_LEN(2)
| GPMC_CONFIG1_WAIT_READ_MON
| GPMC_CONFIG1_WAIT_WRITE_MON
| GPMC_CONFIG1_WAIT_PIN_SEL(waitpin)
| GPMC_CONFIG1_READTYPE_ASYNC
| GPMC_CONFIG1_WRITETYPE_ASYNC
| GPMC_CONFIG1_DEVICESIZE_16
| GPMC_CONFIG1_DEVICETYPE_NOR
| GPMC_CONFIG1_MUXADDDATA);
status = gpmc_cs_request(sync, SZ_16M, (unsigned long *)
&tusb_resources[1].start);
if (status < 0) {
printk(error, 2, status);
return status;
}
tusb_resources[1].end = tusb_resources[1].start + 0x9ff;
sync_cs = sync;
gpmc_cs_write_reg(sync, GPMC_CS_CONFIG1,
GPMC_CONFIG1_READMULTIPLE_SUPP
| GPMC_CONFIG1_READTYPE_SYNC
| GPMC_CONFIG1_WRITEMULTIPLE_SUPP
| GPMC_CONFIG1_WRITETYPE_SYNC
| GPMC_CONFIG1_PAGE_LEN(2)
| GPMC_CONFIG1_WAIT_READ_MON
| GPMC_CONFIG1_WAIT_WRITE_MON
| GPMC_CONFIG1_WAIT_PIN_SEL(waitpin)
| GPMC_CONFIG1_DEVICESIZE_16
| GPMC_CONFIG1_DEVICETYPE_NOR
| GPMC_CONFIG1_MUXADDDATA
);
status = gpio_request_one(irq, GPIOF_IN, "TUSB6010 irq");
if (status < 0) {
printk(error, 3, status);
return status;
}
tusb_resources[2].start = gpio_to_irq(irq);
if (!ps_refclk) {
printk(error, 4, status);
return -ENODEV;
}
refclk_psec = ps_refclk;
status = tusb6010_platform_retime(1);
if (status < 0) {
printk(error, 5, status);
return status;
}
if (!data) {
printk(error, 6, status);
return -ENODEV;
}
tusb_device.dev.platform_data = data;
if (!dmachan)
tusb_device.dev.dma_mask = NULL;
else {
if (dmachan & (1 << 0))
omap_mux_init_signal("sys_ndmareq0", 0);
if (dmachan & (1 << 1))
omap_mux_init_signal("sys_ndmareq1", 0);
if (dmachan & (1 << 2))
omap_mux_init_signal("sys_ndmareq2", 0);
if (dmachan & (1 << 3))
omap_mux_init_signal("sys_ndmareq3", 0);
if (dmachan & (1 << 4))
omap_mux_init_signal("sys_ndmareq4", 0);
if (dmachan & (1 << 5))
omap_mux_init_signal("sys_ndmareq5", 0);
}
status = platform_device_register(&tusb_device);
if (status < 0) {
printk(error, 7, status);
return status;
}
return 0;
}
