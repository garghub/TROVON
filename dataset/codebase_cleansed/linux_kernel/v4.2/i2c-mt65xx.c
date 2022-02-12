static int mtk_i2c_clock_enable(struct mtk_i2c *i2c)
{
int ret;
ret = clk_prepare_enable(i2c->clk_dma);
if (ret)
return ret;
ret = clk_prepare_enable(i2c->clk_main);
if (ret)
goto err_main;
if (i2c->have_pmic) {
ret = clk_prepare_enable(i2c->clk_pmic);
if (ret)
goto err_pmic;
}
return 0;
err_pmic:
clk_disable_unprepare(i2c->clk_main);
err_main:
clk_disable_unprepare(i2c->clk_dma);
return ret;
}
static void mtk_i2c_clock_disable(struct mtk_i2c *i2c)
{
if (i2c->have_pmic)
clk_disable_unprepare(i2c->clk_pmic);
clk_disable_unprepare(i2c->clk_main);
clk_disable_unprepare(i2c->clk_dma);
}
static void mtk_i2c_init_hw(struct mtk_i2c *i2c)
{
u16 control_reg;
writew(I2C_SOFT_RST, i2c->base + OFFSET_SOFTRESET);
if (i2c->use_push_pull)
writew(I2C_IO_CONFIG_PUSH_PULL, i2c->base + OFFSET_IO_CONFIG);
else
writew(I2C_IO_CONFIG_OPEN_DRAIN, i2c->base + OFFSET_IO_CONFIG);
if (i2c->dev_comp->dcm)
writew(I2C_DCM_DISABLE, i2c->base + OFFSET_DCM_EN);
writew(i2c->timing_reg, i2c->base + OFFSET_TIMING);
writew(i2c->high_speed_reg, i2c->base + OFFSET_HS);
if (i2c->have_pmic)
writew(I2C_CONTROL_WRAPPER, i2c->base + OFFSET_PATH_DIR);
control_reg = I2C_CONTROL_ACKERR_DET_EN |
I2C_CONTROL_CLK_EXT_EN | I2C_CONTROL_DMA_EN;
writew(control_reg, i2c->base + OFFSET_CONTROL);
writew(I2C_DELAY_LEN, i2c->base + OFFSET_DELAY_LEN);
}
static int mtk_i2c_set_speed(struct mtk_i2c *i2c, unsigned int parent_clk,
unsigned int clock_div)
{
unsigned int clk_src;
unsigned int step_cnt;
unsigned int sample_cnt;
unsigned int max_step_cnt;
unsigned int target_speed;
unsigned int base_sample_cnt = MAX_SAMPLE_CNT_DIV;
unsigned int base_step_cnt;
unsigned int opt_div;
unsigned int best_mul;
unsigned int cnt_mul;
clk_src = parent_clk / clock_div;
target_speed = i2c->speed_hz;
if (target_speed > MAX_HS_MODE_SPEED)
target_speed = MAX_HS_MODE_SPEED;
if (target_speed > MAX_FS_MODE_SPEED)
max_step_cnt = MAX_HS_STEP_CNT_DIV;
else
max_step_cnt = MAX_STEP_CNT_DIV;
base_step_cnt = max_step_cnt;
opt_div = DIV_ROUND_UP(clk_src >> 1, target_speed);
best_mul = MAX_SAMPLE_CNT_DIV * max_step_cnt;
for (sample_cnt = 1; sample_cnt <= MAX_SAMPLE_CNT_DIV; sample_cnt++) {
step_cnt = DIV_ROUND_UP(opt_div, sample_cnt);
cnt_mul = step_cnt * sample_cnt;
if (step_cnt > max_step_cnt)
continue;
if (cnt_mul < best_mul) {
best_mul = cnt_mul;
base_sample_cnt = sample_cnt;
base_step_cnt = step_cnt;
if (best_mul == opt_div)
break;
}
}
sample_cnt = base_sample_cnt;
step_cnt = base_step_cnt;
if ((clk_src / (2 * sample_cnt * step_cnt)) > target_speed) {
dev_dbg(i2c->dev, "Unsupported speed (%uhz)\n", target_speed);
return -EINVAL;
}
step_cnt--;
sample_cnt--;
if (target_speed > MAX_FS_MODE_SPEED) {
i2c->timing_reg = I2C_FS_TIME_INIT_VALUE;
i2c->high_speed_reg = I2C_TIME_DEFAULT_VALUE |
(sample_cnt << 12) | (step_cnt << 8);
} else {
i2c->timing_reg = (sample_cnt << 8) | (step_cnt << 0);
i2c->high_speed_reg = I2C_TIME_CLR_VALUE;
}
return 0;
}
static int mtk_i2c_do_transfer(struct mtk_i2c *i2c, struct i2c_msg *msgs,
int num, int left_num)
{
u16 addr_reg;
u16 start_reg;
u16 control_reg;
u16 restart_flag = 0;
dma_addr_t rpaddr = 0;
dma_addr_t wpaddr = 0;
int ret;
i2c->irq_stat = 0;
if (i2c->dev_comp->auto_restart)
restart_flag = I2C_RS_TRANSFER;
reinit_completion(&i2c->msg_complete);
control_reg = readw(i2c->base + OFFSET_CONTROL) &
~(I2C_CONTROL_DIR_CHANGE | I2C_CONTROL_RS);
if ((i2c->speed_hz > 400000) || (left_num >= 1))
control_reg |= I2C_CONTROL_RS;
if (i2c->op == I2C_MASTER_WRRD)
control_reg |= I2C_CONTROL_DIR_CHANGE | I2C_CONTROL_RS;
writew(control_reg, i2c->base + OFFSET_CONTROL);
if (i2c->speed_hz <= 100000)
writew(I2C_ST_START_CON, i2c->base + OFFSET_EXT_CONF);
else
writew(I2C_FS_START_CON, i2c->base + OFFSET_EXT_CONF);
addr_reg = msgs->addr << 1;
if (i2c->op == I2C_MASTER_RD)
addr_reg |= 0x1;
writew(addr_reg, i2c->base + OFFSET_SLAVE_ADDR);
writew(restart_flag | I2C_HS_NACKERR | I2C_ACKERR |
I2C_TRANSAC_COMP, i2c->base + OFFSET_INTR_STAT);
writew(I2C_FIFO_ADDR_CLR, i2c->base + OFFSET_FIFO_ADDR_CLR);
writew(restart_flag | I2C_HS_NACKERR | I2C_ACKERR |
I2C_TRANSAC_COMP, i2c->base + OFFSET_INTR_MASK);
if (i2c->op == I2C_MASTER_WRRD) {
writew(msgs->len | ((msgs + 1)->len) << 8,
i2c->base + OFFSET_TRANSFER_LEN);
writew(I2C_WRRD_TRANAC_VALUE, i2c->base + OFFSET_TRANSAC_LEN);
} else {
writew(msgs->len, i2c->base + OFFSET_TRANSFER_LEN);
writew(num, i2c->base + OFFSET_TRANSAC_LEN);
}
if (i2c->op == I2C_MASTER_RD) {
writel(I2C_DMA_INT_FLAG_NONE, i2c->pdmabase + OFFSET_INT_FLAG);
writel(I2C_DMA_CON_RX, i2c->pdmabase + OFFSET_CON);
rpaddr = dma_map_single(i2c->dev, msgs->buf,
msgs->len, DMA_FROM_DEVICE);
if (dma_mapping_error(i2c->dev, rpaddr))
return -ENOMEM;
writel((u32)rpaddr, i2c->pdmabase + OFFSET_RX_MEM_ADDR);
writel(msgs->len, i2c->pdmabase + OFFSET_RX_LEN);
} else if (i2c->op == I2C_MASTER_WR) {
writel(I2C_DMA_INT_FLAG_NONE, i2c->pdmabase + OFFSET_INT_FLAG);
writel(I2C_DMA_CON_TX, i2c->pdmabase + OFFSET_CON);
wpaddr = dma_map_single(i2c->dev, msgs->buf,
msgs->len, DMA_TO_DEVICE);
if (dma_mapping_error(i2c->dev, wpaddr))
return -ENOMEM;
writel((u32)wpaddr, i2c->pdmabase + OFFSET_TX_MEM_ADDR);
writel(msgs->len, i2c->pdmabase + OFFSET_TX_LEN);
} else {
writel(I2C_DMA_CLR_FLAG, i2c->pdmabase + OFFSET_INT_FLAG);
writel(I2C_DMA_CLR_FLAG, i2c->pdmabase + OFFSET_CON);
wpaddr = dma_map_single(i2c->dev, msgs->buf,
msgs->len, DMA_TO_DEVICE);
if (dma_mapping_error(i2c->dev, wpaddr))
return -ENOMEM;
rpaddr = dma_map_single(i2c->dev, (msgs + 1)->buf,
(msgs + 1)->len,
DMA_FROM_DEVICE);
if (dma_mapping_error(i2c->dev, rpaddr)) {
dma_unmap_single(i2c->dev, wpaddr,
msgs->len, DMA_TO_DEVICE);
return -ENOMEM;
}
writel((u32)wpaddr, i2c->pdmabase + OFFSET_TX_MEM_ADDR);
writel((u32)rpaddr, i2c->pdmabase + OFFSET_RX_MEM_ADDR);
writel(msgs->len, i2c->pdmabase + OFFSET_TX_LEN);
writel((msgs + 1)->len, i2c->pdmabase + OFFSET_RX_LEN);
}
writel(I2C_DMA_START_EN, i2c->pdmabase + OFFSET_EN);
if (!i2c->dev_comp->auto_restart) {
start_reg = I2C_TRANSAC_START;
} else {
start_reg = I2C_TRANSAC_START | I2C_RS_MUL_TRIG;
if (left_num >= 1)
start_reg |= I2C_RS_MUL_CNFG;
}
writew(start_reg, i2c->base + OFFSET_START);
ret = wait_for_completion_timeout(&i2c->msg_complete,
i2c->adap.timeout);
writew(~(restart_flag | I2C_HS_NACKERR | I2C_ACKERR |
I2C_TRANSAC_COMP), i2c->base + OFFSET_INTR_MASK);
if (i2c->op == I2C_MASTER_WR) {
dma_unmap_single(i2c->dev, wpaddr,
msgs->len, DMA_TO_DEVICE);
} else if (i2c->op == I2C_MASTER_RD) {
dma_unmap_single(i2c->dev, rpaddr,
msgs->len, DMA_FROM_DEVICE);
} else {
dma_unmap_single(i2c->dev, wpaddr, msgs->len,
DMA_TO_DEVICE);
dma_unmap_single(i2c->dev, rpaddr, (msgs + 1)->len,
DMA_FROM_DEVICE);
}
if (ret == 0) {
dev_dbg(i2c->dev, "addr: %x, transfer timeout\n", msgs->addr);
mtk_i2c_init_hw(i2c);
return -ETIMEDOUT;
}
completion_done(&i2c->msg_complete);
if (i2c->irq_stat & (I2C_HS_NACKERR | I2C_ACKERR)) {
dev_dbg(i2c->dev, "addr: %x, transfer ACK error\n", msgs->addr);
mtk_i2c_init_hw(i2c);
return -ENXIO;
}
return 0;
}
static int mtk_i2c_transfer(struct i2c_adapter *adap,
struct i2c_msg msgs[], int num)
{
int ret;
int left_num = num;
struct mtk_i2c *i2c = i2c_get_adapdata(adap);
ret = mtk_i2c_clock_enable(i2c);
if (ret)
return ret;
while (left_num--) {
if (!msgs->buf) {
dev_dbg(i2c->dev, "data buffer is NULL.\n");
ret = -EINVAL;
goto err_exit;
}
if (msgs->flags & I2C_M_RD)
i2c->op = I2C_MASTER_RD;
else
i2c->op = I2C_MASTER_WR;
if (!i2c->dev_comp->auto_restart) {
if (num > 1) {
i2c->op = I2C_MASTER_WRRD;
left_num--;
}
}
ret = mtk_i2c_do_transfer(i2c, msgs, num, left_num);
if (ret < 0)
goto err_exit;
msgs++;
}
ret = num;
err_exit:
mtk_i2c_clock_disable(i2c);
return ret;
}
static irqreturn_t mtk_i2c_irq(int irqno, void *dev_id)
{
struct mtk_i2c *i2c = dev_id;
u16 restart_flag = 0;
if (i2c->dev_comp->auto_restart)
restart_flag = I2C_RS_TRANSFER;
i2c->irq_stat = readw(i2c->base + OFFSET_INTR_STAT);
writew(restart_flag | I2C_HS_NACKERR | I2C_ACKERR
| I2C_TRANSAC_COMP, i2c->base + OFFSET_INTR_STAT);
complete(&i2c->msg_complete);
return IRQ_HANDLED;
}
static u32 mtk_i2c_functionality(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
}
static int mtk_i2c_parse_dt(struct device_node *np, struct mtk_i2c *i2c,
unsigned int *clk_src_div)
{
int ret;
ret = of_property_read_u32(np, "clock-frequency", &i2c->speed_hz);
if (ret < 0)
i2c->speed_hz = I2C_DEFAULT_SPEED;
ret = of_property_read_u32(np, "clock-div", clk_src_div);
if (ret < 0)
return ret;
if (*clk_src_div == 0)
return -EINVAL;
i2c->have_pmic = of_property_read_bool(np, "mediatek,have-pmic");
i2c->use_push_pull =
of_property_read_bool(np, "mediatek,use-push-pull");
return 0;
}
static int mtk_i2c_probe(struct platform_device *pdev)
{
const struct of_device_id *of_id;
int ret = 0;
struct mtk_i2c *i2c;
struct clk *clk;
unsigned int clk_src_div;
struct resource *res;
int irq;
i2c = devm_kzalloc(&pdev->dev, sizeof(*i2c), GFP_KERNEL);
if (!i2c)
return -ENOMEM;
ret = mtk_i2c_parse_dt(pdev->dev.of_node, i2c, &clk_src_div);
if (ret)
return -EINVAL;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
i2c->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(i2c->base))
return PTR_ERR(i2c->base);
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
i2c->pdmabase = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(i2c->pdmabase))
return PTR_ERR(i2c->pdmabase);
irq = platform_get_irq(pdev, 0);
if (irq <= 0)
return irq;
init_completion(&i2c->msg_complete);
of_id = of_match_node(mtk_i2c_of_match, pdev->dev.of_node);
if (!of_id)
return -EINVAL;
i2c->dev_comp = of_id->data;
i2c->adap.dev.of_node = pdev->dev.of_node;
i2c->dev = &pdev->dev;
i2c->adap.dev.parent = &pdev->dev;
i2c->adap.owner = THIS_MODULE;
i2c->adap.algo = &mtk_i2c_algorithm;
i2c->adap.quirks = i2c->dev_comp->quirks;
i2c->adap.timeout = 2 * HZ;
i2c->adap.retries = 1;
if (i2c->have_pmic && !i2c->dev_comp->pmic_i2c)
return -EINVAL;
i2c->clk_main = devm_clk_get(&pdev->dev, "main");
if (IS_ERR(i2c->clk_main)) {
dev_err(&pdev->dev, "cannot get main clock\n");
return PTR_ERR(i2c->clk_main);
}
i2c->clk_dma = devm_clk_get(&pdev->dev, "dma");
if (IS_ERR(i2c->clk_dma)) {
dev_err(&pdev->dev, "cannot get dma clock\n");
return PTR_ERR(i2c->clk_dma);
}
clk = i2c->clk_main;
if (i2c->have_pmic) {
i2c->clk_pmic = devm_clk_get(&pdev->dev, "pmic");
if (IS_ERR(i2c->clk_pmic)) {
dev_err(&pdev->dev, "cannot get pmic clock\n");
return PTR_ERR(i2c->clk_pmic);
}
clk = i2c->clk_pmic;
}
strlcpy(i2c->adap.name, I2C_DRV_NAME, sizeof(i2c->adap.name));
ret = mtk_i2c_set_speed(i2c, clk_get_rate(clk), clk_src_div);
if (ret) {
dev_err(&pdev->dev, "Failed to set the speed.\n");
return -EINVAL;
}
ret = mtk_i2c_clock_enable(i2c);
if (ret) {
dev_err(&pdev->dev, "clock enable failed!\n");
return ret;
}
mtk_i2c_init_hw(i2c);
mtk_i2c_clock_disable(i2c);
ret = devm_request_irq(&pdev->dev, irq, mtk_i2c_irq,
IRQF_TRIGGER_NONE, I2C_DRV_NAME, i2c);
if (ret < 0) {
dev_err(&pdev->dev,
"Request I2C IRQ %d fail\n", irq);
return ret;
}
i2c_set_adapdata(&i2c->adap, i2c);
ret = i2c_add_adapter(&i2c->adap);
if (ret) {
dev_err(&pdev->dev, "Failed to add i2c bus to i2c core\n");
return ret;
}
platform_set_drvdata(pdev, i2c);
return 0;
}
static int mtk_i2c_remove(struct platform_device *pdev)
{
struct mtk_i2c *i2c = platform_get_drvdata(pdev);
i2c_del_adapter(&i2c->adap);
return 0;
}
