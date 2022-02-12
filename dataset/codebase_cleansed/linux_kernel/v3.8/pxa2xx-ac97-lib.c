unsigned short pxa2xx_ac97_read(struct snd_ac97 *ac97, unsigned short reg)
{
unsigned short val = -1;
volatile u32 *reg_addr;
mutex_lock(&car_mutex);
if (cpu_is_pxa25x() && reg == AC97_GPIO_STATUS)
reg_addr = ac97->num ? &SMC_REG_BASE : &PMC_REG_BASE;
else
reg_addr = ac97->num ? &SAC_REG_BASE : &PAC_REG_BASE;
reg_addr += (reg >> 1);
GSR = GSR_CDONE | GSR_SDONE;
gsr_bits = 0;
val = *reg_addr;
if (reg == AC97_GPIO_STATUS)
goto out;
if (wait_event_timeout(gsr_wq, (GSR | gsr_bits) & GSR_SDONE, 1) <= 0 &&
!((GSR | gsr_bits) & GSR_SDONE)) {
printk(KERN_ERR "%s: read error (ac97_reg=%d GSR=%#lx)\n",
__func__, reg, GSR | gsr_bits);
val = -1;
goto out;
}
GSR = GSR_CDONE | GSR_SDONE;
gsr_bits = 0;
val = *reg_addr;
wait_event_timeout(gsr_wq, (GSR | gsr_bits) & GSR_SDONE, 1);
out: mutex_unlock(&car_mutex);
return val;
}
void pxa2xx_ac97_write(struct snd_ac97 *ac97, unsigned short reg,
unsigned short val)
{
volatile u32 *reg_addr;
mutex_lock(&car_mutex);
if (cpu_is_pxa25x() && reg == AC97_GPIO_STATUS)
reg_addr = ac97->num ? &SMC_REG_BASE : &PMC_REG_BASE;
else
reg_addr = ac97->num ? &SAC_REG_BASE : &PAC_REG_BASE;
reg_addr += (reg >> 1);
GSR = GSR_CDONE | GSR_SDONE;
gsr_bits = 0;
*reg_addr = val;
if (wait_event_timeout(gsr_wq, (GSR | gsr_bits) & GSR_CDONE, 1) <= 0 &&
!((GSR | gsr_bits) & GSR_CDONE))
printk(KERN_ERR "%s: write error (ac97_reg=%d GSR=%#lx)\n",
__func__, reg, GSR | gsr_bits);
mutex_unlock(&car_mutex);
}
static inline void pxa_ac97_warm_pxa25x(void)
{
gsr_bits = 0;
GCR |= GCR_WARM_RST | GCR_PRIRDY_IEN | GCR_SECRDY_IEN;
wait_event_timeout(gsr_wq, gsr_bits & (GSR_PCR | GSR_SCR), 1);
}
static inline void pxa_ac97_cold_pxa25x(void)
{
GCR &= GCR_COLD_RST;
GCR &= ~GCR_COLD_RST;
gsr_bits = 0;
GCR = GCR_COLD_RST;
GCR |= GCR_CDONE_IE|GCR_SDONE_IE;
wait_event_timeout(gsr_wq, gsr_bits & (GSR_PCR | GSR_SCR), 1);
}
static inline void pxa_ac97_warm_pxa27x(void)
{
gsr_bits = 0;
pxa27x_assert_ac97reset(reset_gpio, 1);
udelay(10);
GCR |= GCR_WARM_RST;
pxa27x_assert_ac97reset(reset_gpio, 0);
udelay(500);
}
static inline void pxa_ac97_cold_pxa27x(void)
{
unsigned int timeout;
GCR &= GCR_COLD_RST;
GCR &= ~GCR_COLD_RST;
gsr_bits = 0;
clk_enable(ac97conf_clk);
udelay(5);
clk_disable(ac97conf_clk);
GCR = GCR_COLD_RST | GCR_WARM_RST;
timeout = 100;
while (!((GSR | gsr_bits) & (GSR_PCR | GSR_SCR)) && timeout--)
mdelay(1);
}
static inline void pxa_ac97_warm_pxa3xx(void)
{
int timeout = 100;
gsr_bits = 0;
GCR |= GCR_WARM_RST;
while (!((GSR | gsr_bits) & (GSR_PCR | GSR_SCR)) && timeout--)
mdelay(1);
}
static inline void pxa_ac97_cold_pxa3xx(void)
{
int timeout = 1000;
GCR = 0;
GCR = GCR_CLKBPB;
udelay(100);
GCR = 0;
GCR &= GCR_COLD_RST;
GCR &= ~GCR_COLD_RST;
gsr_bits = 0;
GCR &= ~(GCR_PRIRDY_IEN|GCR_SECRDY_IEN);
GCR = GCR_WARM_RST | GCR_COLD_RST;
while (!(GSR & (GSR_PCR | GSR_SCR)) && timeout--)
mdelay(10);
}
bool pxa2xx_ac97_try_warm_reset(struct snd_ac97 *ac97)
{
unsigned long gsr;
#ifdef CONFIG_PXA25x
if (cpu_is_pxa25x())
pxa_ac97_warm_pxa25x();
else
#endif
#ifdef CONFIG_PXA27x
if (cpu_is_pxa27x())
pxa_ac97_warm_pxa27x();
else
#endif
#ifdef CONFIG_PXA3xx
if (cpu_is_pxa3xx())
pxa_ac97_warm_pxa3xx();
else
#endif
BUG();
gsr = GSR | gsr_bits;
if (!(gsr & (GSR_PCR | GSR_SCR))) {
printk(KERN_INFO "%s: warm reset timeout (GSR=%#lx)\n",
__func__, gsr);
return false;
}
return true;
}
bool pxa2xx_ac97_try_cold_reset(struct snd_ac97 *ac97)
{
unsigned long gsr;
#ifdef CONFIG_PXA25x
if (cpu_is_pxa25x())
pxa_ac97_cold_pxa25x();
else
#endif
#ifdef CONFIG_PXA27x
if (cpu_is_pxa27x())
pxa_ac97_cold_pxa27x();
else
#endif
#ifdef CONFIG_PXA3xx
if (cpu_is_pxa3xx())
pxa_ac97_cold_pxa3xx();
else
#endif
BUG();
gsr = GSR | gsr_bits;
if (!(gsr & (GSR_PCR | GSR_SCR))) {
printk(KERN_INFO "%s: cold reset timeout (GSR=%#lx)\n",
__func__, gsr);
return false;
}
return true;
}
void pxa2xx_ac97_finish_reset(struct snd_ac97 *ac97)
{
GCR &= ~(GCR_PRIRDY_IEN|GCR_SECRDY_IEN);
GCR |= GCR_SDONE_IE|GCR_CDONE_IE;
}
static irqreturn_t pxa2xx_ac97_irq(int irq, void *dev_id)
{
long status;
status = GSR;
if (status) {
GSR = status;
gsr_bits |= status;
wake_up(&gsr_wq);
if (cpu_is_pxa27x()) {
MISR = MISR_EOC;
PISR = PISR_EOC;
MCSR = MCSR_EOC;
}
return IRQ_HANDLED;
}
return IRQ_NONE;
}
int pxa2xx_ac97_hw_suspend(void)
{
GCR |= GCR_ACLINK_OFF;
clk_disable(ac97_clk);
return 0;
}
int pxa2xx_ac97_hw_resume(void)
{
clk_enable(ac97_clk);
return 0;
}
int pxa2xx_ac97_hw_probe(struct platform_device *dev)
{
int ret;
pxa2xx_audio_ops_t *pdata = dev->dev.platform_data;
if (pdata) {
switch (pdata->reset_gpio) {
case 95:
case 113:
reset_gpio = pdata->reset_gpio;
break;
case 0:
reset_gpio = 113;
break;
case -1:
break;
default:
dev_err(&dev->dev, "Invalid reset GPIO %d\n",
pdata->reset_gpio);
}
} else {
if (cpu_is_pxa27x())
reset_gpio = 113;
}
if (cpu_is_pxa27x()) {
ret = gpio_request_one(reset_gpio, GPIOF_OUT_INIT_HIGH,
"pxa27x ac97 reset");
if (ret < 0) {
pr_err("%s: gpio_request_one() failed: %d\n",
__func__, ret);
goto err_conf;
}
pxa27x_assert_ac97reset(reset_gpio, 0);
ac97conf_clk = clk_get(&dev->dev, "AC97CONFCLK");
if (IS_ERR(ac97conf_clk)) {
ret = PTR_ERR(ac97conf_clk);
ac97conf_clk = NULL;
goto err_conf;
}
}
ac97_clk = clk_get(&dev->dev, "AC97CLK");
if (IS_ERR(ac97_clk)) {
ret = PTR_ERR(ac97_clk);
ac97_clk = NULL;
goto err_clk;
}
ret = clk_enable(ac97_clk);
if (ret)
goto err_clk2;
ret = request_irq(IRQ_AC97, pxa2xx_ac97_irq, 0, "AC97", NULL);
if (ret < 0)
goto err_irq;
return 0;
err_irq:
GCR |= GCR_ACLINK_OFF;
err_clk2:
clk_put(ac97_clk);
ac97_clk = NULL;
err_clk:
if (ac97conf_clk) {
clk_put(ac97conf_clk);
ac97conf_clk = NULL;
}
err_conf:
return ret;
}
void pxa2xx_ac97_hw_remove(struct platform_device *dev)
{
if (cpu_is_pxa27x())
gpio_free(reset_gpio);
GCR |= GCR_ACLINK_OFF;
free_irq(IRQ_AC97, NULL);
if (ac97conf_clk) {
clk_put(ac97conf_clk);
ac97conf_clk = NULL;
}
clk_disable(ac97_clk);
clk_put(ac97_clk);
ac97_clk = NULL;
}
