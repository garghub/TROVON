static struct platform_device *db8500_add_msp_i2s(struct device *parent,
int id,
resource_size_t base, int irq,
struct msp_i2s_platform_data *pdata)
{
struct platform_device *pdev;
struct resource res[] = {
DEFINE_RES_MEM(base, SZ_4K),
DEFINE_RES_IRQ(irq),
};
pr_info("Register platform-device 'ux500-msp-i2s', id %d, irq %d\n",
id, irq);
pdev = platform_device_register_resndata(parent, "ux500-msp-i2s", id,
res, ARRAY_SIZE(res),
pdata, sizeof(*pdata));
if (!pdev) {
pr_err("Failed to register platform-device 'ux500-msp-i2s.%d'!\n",
id);
return NULL;
}
return pdev;
}
void mop500_audio_init(struct device *parent)
{
pr_info("%s: Register platform-device 'snd-soc-mop500'.\n", __func__);
platform_device_register(&snd_soc_mop500);
pr_info("Initialize MSP I2S-devices.\n");
db8500_add_msp_i2s(parent, 0, U8500_MSP0_BASE, IRQ_DB8500_MSP0,
&msp0_platform_data);
db8500_add_msp_i2s(parent, 1, U8500_MSP1_BASE, IRQ_DB8500_MSP1,
&msp1_platform_data);
db8500_add_msp_i2s(parent, 2, U8500_MSP2_BASE, IRQ_DB8500_MSP2,
&msp2_platform_data);
db8500_add_msp_i2s(parent, 3, U8500_MSP3_BASE, IRQ_DB8500_MSP1,
&msp3_platform_data);
}
