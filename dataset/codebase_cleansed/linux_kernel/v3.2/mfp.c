void mfp_set_groupf(struct device *dev)
{
unsigned long mfpen;
const char *dev_id;
BUG_ON(!dev);
mutex_lock(&mfp_mutex);
dev_id = dev_name(dev);
mfpen = __raw_readl(REG_MFSEL);
if (strcmp(dev_id, "nuc900-emc") == 0)
mfpen |= GPSELF;
else
mfpen &= ~GPSELF;
__raw_writel(mfpen, REG_MFSEL);
mutex_unlock(&mfp_mutex);
}
void mfp_set_groupc(struct device *dev)
{
unsigned long mfpen;
const char *dev_id;
BUG_ON(!dev);
mutex_lock(&mfp_mutex);
dev_id = dev_name(dev);
mfpen = __raw_readl(REG_MFSEL);
if (strcmp(dev_id, "nuc900-lcd") == 0)
mfpen |= GPSELC;
else if (strcmp(dev_id, "nuc900-kpi") == 0) {
mfpen &= (~GPSELC);
mfpen |= ENKPI;
} else if (strcmp(dev_id, "nuc900-nand") == 0) {
mfpen &= (~GPSELC);
mfpen |= ENNAND;
} else
mfpen &= (~GPSELC);
__raw_writel(mfpen, REG_MFSEL);
mutex_unlock(&mfp_mutex);
}
void mfp_set_groupi(struct device *dev)
{
unsigned long mfpen;
const char *dev_id;
BUG_ON(!dev);
mutex_lock(&mfp_mutex);
dev_id = dev_name(dev);
mfpen = __raw_readl(REG_MFSEL);
mfpen &= ~GPSELEI1;
if (strcmp(dev_id, "nuc900-wdog") == 0)
mfpen |= GPSELEI1;
else if (strcmp(dev_id, "nuc900-atapi") == 0)
mfpen |= GPSELEI0;
else if (strcmp(dev_id, "nuc900-keypad") == 0)
mfpen &= ~GPSELEI0;
__raw_writel(mfpen, REG_MFSEL);
mutex_unlock(&mfp_mutex);
}
void mfp_set_groupg(struct device *dev, const char *subname)
{
unsigned long mfpen;
const char *dev_id;
BUG_ON((!dev) && (!subname));
mutex_lock(&mfp_mutex);
if (subname != NULL)
dev_id = subname;
else
dev_id = dev_name(dev);
mfpen = __raw_readl(REG_MFSEL);
if (strcmp(dev_id, "nuc900-spi") == 0) {
mfpen &= ~(GPIOG0TO1 | GPIOG2TO3);
mfpen |= ENSPI;
} else if (strcmp(dev_id, "nuc900-i2c0") == 0) {
mfpen &= ~(GPIOG0TO1);
mfpen |= ENI2C0;
} else if (strcmp(dev_id, "nuc900-i2c1") == 0) {
mfpen &= ~(GPIOG2TO3);
mfpen |= ENI2C1;
} else if (strcmp(dev_id, "nuc900-audio") == 0) {
mfpen &= ~(GPIOG22TO23);
mfpen |= ENAC97;
} else if (strcmp(dev_id, "nuc900-mmc-port1") == 0) {
mfpen &= ~(GPIOG18TO20);
mfpen |= (ENSD1 | 0x01);
} else {
mfpen &= ~(GPIOG0TO1 | GPIOG2TO3);
}
__raw_writel(mfpen, REG_MFSEL);
mutex_unlock(&mfp_mutex);
}
void mfp_set_groupd(struct device *dev, const char *subname)
{
unsigned long mfpen;
const char *dev_id;
BUG_ON((!dev) && (!subname));
mutex_lock(&mfp_mutex);
if (subname != NULL)
dev_id = subname;
else
dev_id = dev_name(dev);
mfpen = __raw_readl(REG_MFSEL);
if (strcmp(dev_id, "nuc900-mmc-port0") == 0) {
mfpen &= ~GPSELD;
mfpen |= ENSD0;
} else
mfpen &= (~GPSELD);
__raw_writel(mfpen, REG_MFSEL);
mutex_unlock(&mfp_mutex);
}
