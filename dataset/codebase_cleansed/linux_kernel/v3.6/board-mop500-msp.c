int msp13_i2s_init(void)
{
int retval = 0;
unsigned long flags;
spin_lock_irqsave(&msp_rxtx_lock, flags);
if (msp_rxtx_ref == 0 && !(IS_ERR(msp1_p) || IS_ERR(msp1_def))) {
retval = pinctrl_select_state(msp1_p, msp1_def);
if (retval)
pr_err("could not set MSP1 defstate\n");
}
if (!retval)
msp_rxtx_ref++;
spin_unlock_irqrestore(&msp_rxtx_lock, flags);
return retval;
}
int msp13_i2s_exit(void)
{
int retval = 0;
unsigned long flags;
spin_lock_irqsave(&msp_rxtx_lock, flags);
WARN_ON(!msp_rxtx_ref);
msp_rxtx_ref--;
if (msp_rxtx_ref == 0 && !(IS_ERR(msp1_p) || IS_ERR(msp1_sleep))) {
retval = pinctrl_select_state(msp1_p, msp1_sleep);
if (retval)
pr_err("could not set MSP1 sleepstate\n");
}
spin_unlock_irqrestore(&msp_rxtx_lock, flags);
return retval;
}
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
int mop500_msp_init(struct device *parent)
{
struct platform_device *msp1;
pr_info("%s: Register platform-device 'snd-soc-mop500'.\n", __func__);
platform_device_register(&snd_soc_mop500);
pr_info("Initialize MSP I2S-devices.\n");
db8500_add_msp_i2s(parent, 0, U8500_MSP0_BASE, IRQ_DB8500_MSP0,
&msp0_platform_data);
msp1 = db8500_add_msp_i2s(parent, 1, U8500_MSP1_BASE, IRQ_DB8500_MSP1,
&msp1_platform_data);
db8500_add_msp_i2s(parent, 2, U8500_MSP2_BASE, IRQ_DB8500_MSP2,
&msp2_platform_data);
db8500_add_msp_i2s(parent, 3, U8500_MSP3_BASE, IRQ_DB8500_MSP1,
&msp3_platform_data);
if (msp1) {
msp1_p = pinctrl_get(&msp1->dev);
if (IS_ERR(msp1_p))
dev_err(&msp1->dev, "could not get MSP1 pinctrl\n");
else {
msp1_def = pinctrl_lookup_state(msp1_p,
PINCTRL_STATE_DEFAULT);
if (IS_ERR(msp1_def)) {
dev_err(&msp1->dev,
"could not get MSP1 defstate\n");
}
msp1_sleep = pinctrl_lookup_state(msp1_p,
PINCTRL_STATE_SLEEP);
if (IS_ERR(msp1_sleep))
dev_err(&msp1->dev,
"could not get MSP1 idlestate\n");
}
}
pr_info("%s: Register platform-device 'ux500-pcm'\n", __func__);
platform_device_register(&ux500_pcm);
return 0;
}
