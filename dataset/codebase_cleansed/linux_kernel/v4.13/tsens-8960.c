static int suspend_8960(struct tsens_device *tmdev)
{
int ret;
unsigned int mask;
struct regmap *map = tmdev->map;
ret = regmap_read(map, THRESHOLD_ADDR, &tmdev->ctx.threshold);
if (ret)
return ret;
ret = regmap_read(map, CNTL_ADDR, &tmdev->ctx.control);
if (ret)
return ret;
if (tmdev->num_sensors > 1)
mask = SLP_CLK_ENA | EN;
else
mask = SLP_CLK_ENA_8660 | EN;
ret = regmap_update_bits(map, CNTL_ADDR, mask, 0);
if (ret)
return ret;
return 0;
}
static int resume_8960(struct tsens_device *tmdev)
{
int ret;
struct regmap *map = tmdev->map;
ret = regmap_update_bits(map, CNTL_ADDR, SW_RST, SW_RST);
if (ret)
return ret;
if (tmdev->num_sensors > 1) {
ret = regmap_update_bits(map, CONFIG_ADDR, CONFIG_MASK, CONFIG);
if (ret)
return ret;
}
ret = regmap_write(map, THRESHOLD_ADDR, tmdev->ctx.threshold);
if (ret)
return ret;
ret = regmap_write(map, CNTL_ADDR, tmdev->ctx.control);
if (ret)
return ret;
return 0;
}
static int enable_8960(struct tsens_device *tmdev, int id)
{
int ret;
u32 reg, mask;
ret = regmap_read(tmdev->map, CNTL_ADDR, &reg);
if (ret)
return ret;
mask = BIT(id + SENSOR0_SHIFT);
ret = regmap_write(tmdev->map, CNTL_ADDR, reg | SW_RST);
if (ret)
return ret;
if (tmdev->num_sensors > 1)
reg |= mask | SLP_CLK_ENA | EN;
else
reg |= mask | SLP_CLK_ENA_8660 | EN;
ret = regmap_write(tmdev->map, CNTL_ADDR, reg);
if (ret)
return ret;
return 0;
}
static void disable_8960(struct tsens_device *tmdev)
{
int ret;
u32 reg_cntl;
u32 mask;
mask = GENMASK(tmdev->num_sensors - 1, 0);
mask <<= SENSOR0_SHIFT;
mask |= EN;
ret = regmap_read(tmdev->map, CNTL_ADDR, &reg_cntl);
if (ret)
return;
reg_cntl &= ~mask;
if (tmdev->num_sensors > 1)
reg_cntl &= ~SLP_CLK_ENA;
else
reg_cntl &= ~SLP_CLK_ENA_8660;
regmap_write(tmdev->map, CNTL_ADDR, reg_cntl);
}
static int init_8960(struct tsens_device *tmdev)
{
int ret, i;
u32 reg_cntl;
tmdev->map = dev_get_regmap(tmdev->dev, NULL);
if (!tmdev->map)
return -ENODEV;
for (i = 0; i < tmdev->num_sensors; i++) {
if (i >= 5)
tmdev->sensor[i].status = S0_STATUS_ADDR + 40;
tmdev->sensor[i].status += i * 4;
}
reg_cntl = SW_RST;
ret = regmap_update_bits(tmdev->map, CNTL_ADDR, SW_RST, reg_cntl);
if (ret)
return ret;
if (tmdev->num_sensors > 1) {
reg_cntl |= SLP_CLK_ENA | (MEASURE_PERIOD << 18);
reg_cntl &= ~SW_RST;
ret = regmap_update_bits(tmdev->map, CONFIG_ADDR,
CONFIG_MASK, CONFIG);
} else {
reg_cntl |= SLP_CLK_ENA_8660 | (MEASURE_PERIOD << 16);
reg_cntl &= ~CONFIG_MASK_8660;
reg_cntl |= CONFIG_8660 << CONFIG_SHIFT_8660;
}
reg_cntl |= GENMASK(tmdev->num_sensors - 1, 0) << SENSOR0_SHIFT;
ret = regmap_write(tmdev->map, CNTL_ADDR, reg_cntl);
if (ret)
return ret;
reg_cntl |= EN;
ret = regmap_write(tmdev->map, CNTL_ADDR, reg_cntl);
if (ret)
return ret;
return 0;
}
static int calibrate_8960(struct tsens_device *tmdev)
{
int i;
char *data;
ssize_t num_read = tmdev->num_sensors;
struct tsens_sensor *s = tmdev->sensor;
data = qfprom_read(tmdev->dev, "calib");
if (IS_ERR(data))
data = qfprom_read(tmdev->dev, "calib_backup");
if (IS_ERR(data))
return PTR_ERR(data);
for (i = 0; i < num_read; i++, s++)
s->offset = data[i];
return 0;
}
static inline int code_to_mdegC(u32 adc_code, const struct tsens_sensor *s)
{
int slope, offset;
slope = thermal_zone_get_slope(s->tzd);
offset = CAL_MDEGC - slope * s->offset;
return adc_code * slope + offset;
}
static int get_temp_8960(struct tsens_device *tmdev, int id, int *temp)
{
int ret;
u32 code, trdy;
const struct tsens_sensor *s = &tmdev->sensor[id];
unsigned long timeout;
timeout = jiffies + usecs_to_jiffies(TIMEOUT_US);
do {
ret = regmap_read(tmdev->map, INT_STATUS_ADDR, &trdy);
if (ret)
return ret;
if (!(trdy & TRDY_MASK))
continue;
ret = regmap_read(tmdev->map, s->status, &code);
if (ret)
return ret;
*temp = code_to_mdegC(code, s);
return 0;
} while (time_before(jiffies, timeout));
return -ETIMEDOUT;
}
