static int gs_read_register(struct spi_device *spi, u16 addr, u16 *value)
{
int ret;
u16 buf_addr = (0x8000 | (0x0FFF & addr));
u16 buf_value = 0;
struct spi_message msg;
struct spi_transfer tx[] = {
{
.tx_buf = &buf_addr,
.len = 2,
.delay_usecs = 1,
}, {
.rx_buf = &buf_value,
.len = 2,
.delay_usecs = 1,
},
};
spi_message_init(&msg);
spi_message_add_tail(&tx[0], &msg);
spi_message_add_tail(&tx[1], &msg);
ret = spi_sync(spi, &msg);
*value = buf_value;
return ret;
}
static int gs_write_register(struct spi_device *spi, u16 addr, u16 value)
{
int ret;
u16 buf_addr = addr;
u16 buf_value = value;
struct spi_message msg;
struct spi_transfer tx[] = {
{
.tx_buf = &buf_addr,
.len = 2,
.delay_usecs = 1,
}, {
.tx_buf = &buf_value,
.len = 2,
.delay_usecs = 1,
},
};
spi_message_init(&msg);
spi_message_add_tail(&tx[0], &msg);
spi_message_add_tail(&tx[1], &msg);
ret = spi_sync(spi, &msg);
return ret;
}
static int gs_g_register(struct v4l2_subdev *sd,
struct v4l2_dbg_register *reg)
{
struct spi_device *spi = v4l2_get_subdevdata(sd);
u16 val;
int ret;
ret = gs_read_register(spi, reg->reg & 0xFFFF, &val);
reg->val = val;
reg->size = 2;
return ret;
}
static int gs_s_register(struct v4l2_subdev *sd,
const struct v4l2_dbg_register *reg)
{
struct spi_device *spi = v4l2_get_subdevdata(sd);
return gs_write_register(spi, reg->reg & 0xFFFF, reg->val & 0xFFFF);
}
static int gs_status_format(u16 status, struct v4l2_dv_timings *timings)
{
int std = (status & MASK_STD_STATUS) >> 5;
int i;
for (i = 0; i < ARRAY_SIZE(reg_fmt); i++) {
if (reg_fmt[i].reg_value == std) {
*timings = reg_fmt[i].format;
return 0;
}
}
return -ERANGE;
}
static u16 get_register_timings(struct v4l2_dv_timings *timings)
{
int i;
for (i = 0; i < ARRAY_SIZE(reg_fmt); i++) {
if (v4l2_match_dv_timings(timings, &reg_fmt[i].format, 0,
false))
return reg_fmt[i].reg_value | MASK_FORCE_STD;
}
return 0x0;
}
static inline struct gs *to_gs(struct v4l2_subdev *sd)
{
return container_of(sd, struct gs, sd);
}
static int gs_s_dv_timings(struct v4l2_subdev *sd,
struct v4l2_dv_timings *timings)
{
struct gs *gs = to_gs(sd);
int reg_value;
reg_value = get_register_timings(timings);
if (reg_value == 0x0)
return -EINVAL;
gs->current_timings = *timings;
return 0;
}
static int gs_g_dv_timings(struct v4l2_subdev *sd,
struct v4l2_dv_timings *timings)
{
struct gs *gs = to_gs(sd);
*timings = gs->current_timings;
return 0;
}
static int gs_query_dv_timings(struct v4l2_subdev *sd,
struct v4l2_dv_timings *timings)
{
struct gs *gs = to_gs(sd);
struct v4l2_dv_timings fmt;
u16 reg_value, i;
int ret;
if (gs->enabled)
return -EBUSY;
for (i = 0; i < 4; i++) {
gs_read_register(gs->pdev, REG_LINES_PER_FRAME + i, &reg_value);
if (reg_value)
break;
}
if (i >= 4)
return -ENOLINK;
gs_read_register(gs->pdev, REG_STATUS, &reg_value);
if (!(reg_value & MASK_H_LOCK) || !(reg_value & MASK_V_LOCK))
return -ENOLCK;
if (!(reg_value & MASK_STD_LOCK))
return -ERANGE;
ret = gs_status_format(reg_value, &fmt);
if (ret < 0)
return ret;
*timings = fmt;
return 0;
}
static int gs_enum_dv_timings(struct v4l2_subdev *sd,
struct v4l2_enum_dv_timings *timings)
{
if (timings->index >= ARRAY_SIZE(fmt_cap))
return -EINVAL;
if (timings->pad != 0)
return -EINVAL;
timings->timings = fmt_cap[timings->index];
return 0;
}
static int gs_s_stream(struct v4l2_subdev *sd, int enable)
{
struct gs *gs = to_gs(sd);
int reg_value;
if (gs->enabled == enable)
return 0;
gs->enabled = enable;
if (enable) {
reg_value = get_register_timings(&gs->current_timings);
return gs_write_register(gs->pdev, REG_FORCE_FMT, reg_value);
}
return gs_write_register(gs->pdev, REG_FORCE_FMT, 0x0);
}
static int gs_g_input_status(struct v4l2_subdev *sd, u32 *status)
{
struct gs *gs = to_gs(sd);
u16 reg_value, i;
int ret;
for (i = 0; i < 4; i++) {
ret = gs_read_register(gs->pdev,
REG_LINES_PER_FRAME + i, &reg_value);
if (reg_value)
break;
if (ret) {
*status = V4L2_IN_ST_NO_POWER;
return ret;
}
}
if (i >= 4)
*status |= V4L2_IN_ST_NO_SIGNAL;
ret = gs_read_register(gs->pdev, REG_STATUS, &reg_value);
if (!(reg_value & MASK_H_LOCK))
*status |= V4L2_IN_ST_NO_H_LOCK;
if (!(reg_value & MASK_V_LOCK))
*status |= V4L2_IN_ST_NO_V_LOCK;
if (!(reg_value & MASK_STD_LOCK))
*status |= V4L2_IN_ST_NO_STD_LOCK;
return ret;
}
static int gs_dv_timings_cap(struct v4l2_subdev *sd,
struct v4l2_dv_timings_cap *cap)
{
if (cap->pad != 0)
return -EINVAL;
*cap = gs_timings_cap;
return 0;
}
static int gs_probe(struct spi_device *spi)
{
int ret;
struct gs *gs;
struct v4l2_subdev *sd;
gs = devm_kzalloc(&spi->dev, sizeof(struct gs), GFP_KERNEL);
if (!gs)
return -ENOMEM;
gs->pdev = spi;
sd = &gs->sd;
spi->mode = SPI_MODE_0;
spi->irq = -1;
spi->max_speed_hz = 10000000;
spi->bits_per_word = 16;
ret = spi_setup(spi);
v4l2_spi_subdev_init(sd, spi, &gs_ops);
gs->current_timings = reg_fmt[0].format;
gs->enabled = 0;
gs_write_register(spi, 0x0, 0x300);
return ret;
}
static int gs_remove(struct spi_device *spi)
{
struct v4l2_subdev *sd = spi_get_drvdata(spi);
v4l2_device_unregister_subdev(sd);
return 0;
}
