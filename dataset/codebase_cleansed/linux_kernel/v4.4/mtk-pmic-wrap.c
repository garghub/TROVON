static inline int pwrap_is_mt8135(struct pmic_wrapper *wrp)
{
return wrp->type == PWRAP_MT8135;
}
static inline int pwrap_is_mt8173(struct pmic_wrapper *wrp)
{
return wrp->type == PWRAP_MT8173;
}
static u32 pwrap_readl(struct pmic_wrapper *wrp, enum pwrap_regs reg)
{
return readl(wrp->base + wrp->regs[reg]);
}
static void pwrap_writel(struct pmic_wrapper *wrp, u32 val, enum pwrap_regs reg)
{
writel(val, wrp->base + wrp->regs[reg]);
}
static bool pwrap_is_fsm_idle(struct pmic_wrapper *wrp)
{
u32 val = pwrap_readl(wrp, PWRAP_WACS2_RDATA);
return PWRAP_GET_WACS_FSM(val) == PWRAP_WACS_FSM_IDLE;
}
static bool pwrap_is_fsm_vldclr(struct pmic_wrapper *wrp)
{
u32 val = pwrap_readl(wrp, PWRAP_WACS2_RDATA);
return PWRAP_GET_WACS_FSM(val) == PWRAP_WACS_FSM_WFVLDCLR;
}
static bool pwrap_is_sync_idle(struct pmic_wrapper *wrp)
{
return pwrap_readl(wrp, PWRAP_WACS2_RDATA) & PWRAP_STATE_SYNC_IDLE0;
}
static bool pwrap_is_fsm_idle_and_sync_idle(struct pmic_wrapper *wrp)
{
u32 val = pwrap_readl(wrp, PWRAP_WACS2_RDATA);
return (PWRAP_GET_WACS_FSM(val) == PWRAP_WACS_FSM_IDLE) &&
(val & PWRAP_STATE_SYNC_IDLE0);
}
static int pwrap_wait_for_state(struct pmic_wrapper *wrp,
bool (*fp)(struct pmic_wrapper *))
{
unsigned long timeout;
timeout = jiffies + usecs_to_jiffies(255);
do {
if (time_after(jiffies, timeout))
return fp(wrp) ? 0 : -ETIMEDOUT;
if (fp(wrp))
return 0;
} while (1);
}
static int pwrap_write(struct pmic_wrapper *wrp, u32 adr, u32 wdata)
{
int ret;
ret = pwrap_wait_for_state(wrp, pwrap_is_fsm_idle);
if (ret)
return ret;
pwrap_writel(wrp, (1 << 31) | ((adr >> 1) << 16) | wdata,
PWRAP_WACS2_CMD);
return 0;
}
static int pwrap_read(struct pmic_wrapper *wrp, u32 adr, u32 *rdata)
{
int ret;
ret = pwrap_wait_for_state(wrp, pwrap_is_fsm_idle);
if (ret)
return ret;
pwrap_writel(wrp, (adr >> 1) << 16, PWRAP_WACS2_CMD);
ret = pwrap_wait_for_state(wrp, pwrap_is_fsm_vldclr);
if (ret)
return ret;
*rdata = PWRAP_GET_WACS_RDATA(pwrap_readl(wrp, PWRAP_WACS2_RDATA));
pwrap_writel(wrp, 1, PWRAP_WACS2_VLDCLR);
return 0;
}
static int pwrap_regmap_read(void *context, u32 adr, u32 *rdata)
{
return pwrap_read(context, adr, rdata);
}
static int pwrap_regmap_write(void *context, u32 adr, u32 wdata)
{
return pwrap_write(context, adr, wdata);
}
static int pwrap_reset_spislave(struct pmic_wrapper *wrp)
{
int ret, i;
pwrap_writel(wrp, 0, PWRAP_HIPRIO_ARB_EN);
pwrap_writel(wrp, 0, PWRAP_WRAP_EN);
pwrap_writel(wrp, 1, PWRAP_MUX_SEL);
pwrap_writel(wrp, 1, PWRAP_MAN_EN);
pwrap_writel(wrp, 0, PWRAP_DIO_EN);
pwrap_writel(wrp, PWRAP_MAN_CMD_SPI_WRITE | PWRAP_MAN_CMD_OP_CSL,
PWRAP_MAN_CMD);
pwrap_writel(wrp, PWRAP_MAN_CMD_SPI_WRITE | PWRAP_MAN_CMD_OP_OUTS,
PWRAP_MAN_CMD);
pwrap_writel(wrp, PWRAP_MAN_CMD_SPI_WRITE | PWRAP_MAN_CMD_OP_CSH,
PWRAP_MAN_CMD);
for (i = 0; i < 4; i++)
pwrap_writel(wrp, PWRAP_MAN_CMD_SPI_WRITE | PWRAP_MAN_CMD_OP_OUTS,
PWRAP_MAN_CMD);
ret = pwrap_wait_for_state(wrp, pwrap_is_sync_idle);
if (ret) {
dev_err(wrp->dev, "%s fail, ret=%d\n", __func__, ret);
return ret;
}
pwrap_writel(wrp, 0, PWRAP_MAN_EN);
pwrap_writel(wrp, 0, PWRAP_MUX_SEL);
return 0;
}
static int pwrap_init_sidly(struct pmic_wrapper *wrp)
{
u32 rdata;
u32 i;
u32 pass = 0;
signed char dly[16] = {
-1, 0, 1, 0, 2, -1, 1, 1, 3, -1, -1, -1, 3, -1, 2, 1
};
for (i = 0; i < 4; i++) {
pwrap_writel(wrp, i, PWRAP_SIDLY);
pwrap_read(wrp, PWRAP_DEW_READ_TEST, &rdata);
if (rdata == PWRAP_DEW_READ_TEST_VAL) {
dev_dbg(wrp->dev, "[Read Test] pass, SIDLY=%x\n", i);
pass |= 1 << i;
}
}
if (dly[pass] < 0) {
dev_err(wrp->dev, "sidly pass range 0x%x not continuous\n",
pass);
return -EIO;
}
pwrap_writel(wrp, dly[pass], PWRAP_SIDLY);
return 0;
}
static int pwrap_init_reg_clock(struct pmic_wrapper *wrp)
{
if (pwrap_is_mt8135(wrp)) {
pwrap_writel(wrp, 0x4, PWRAP_CSHEXT);
pwrap_writel(wrp, 0x0, PWRAP_CSHEXT_WRITE);
pwrap_writel(wrp, 0x4, PWRAP_CSHEXT_READ);
pwrap_writel(wrp, 0x0, PWRAP_CSLEXT_START);
pwrap_writel(wrp, 0x0, PWRAP_CSLEXT_END);
} else {
pwrap_writel(wrp, 0x0, PWRAP_CSHEXT_WRITE);
pwrap_writel(wrp, 0x4, PWRAP_CSHEXT_READ);
pwrap_writel(wrp, 0x2, PWRAP_CSLEXT_START);
pwrap_writel(wrp, 0x2, PWRAP_CSLEXT_END);
}
return 0;
}
static bool pwrap_is_cipher_ready(struct pmic_wrapper *wrp)
{
return pwrap_readl(wrp, PWRAP_CIPHER_RDY) & 1;
}
static bool pwrap_is_pmic_cipher_ready(struct pmic_wrapper *wrp)
{
u32 rdata;
int ret;
ret = pwrap_read(wrp, PWRAP_DEW_CIPHER_RDY, &rdata);
if (ret)
return 0;
return rdata == 1;
}
static int pwrap_init_cipher(struct pmic_wrapper *wrp)
{
int ret;
u32 rdata;
pwrap_writel(wrp, 0x1, PWRAP_CIPHER_SWRST);
pwrap_writel(wrp, 0x0, PWRAP_CIPHER_SWRST);
pwrap_writel(wrp, 0x1, PWRAP_CIPHER_KEY_SEL);
pwrap_writel(wrp, 0x2, PWRAP_CIPHER_IV_SEL);
if (pwrap_is_mt8135(wrp)) {
pwrap_writel(wrp, 1, PWRAP_CIPHER_LOAD);
pwrap_writel(wrp, 1, PWRAP_CIPHER_START);
} else {
pwrap_writel(wrp, 1, PWRAP_CIPHER_EN);
}
pwrap_write(wrp, PWRAP_DEW_CIPHER_SWRST, 0x1);
pwrap_write(wrp, PWRAP_DEW_CIPHER_SWRST, 0x0);
pwrap_write(wrp, PWRAP_DEW_CIPHER_KEY_SEL, 0x1);
pwrap_write(wrp, PWRAP_DEW_CIPHER_IV_SEL, 0x2);
pwrap_write(wrp, PWRAP_DEW_CIPHER_LOAD, 0x1);
pwrap_write(wrp, PWRAP_DEW_CIPHER_START, 0x1);
ret = pwrap_wait_for_state(wrp, pwrap_is_cipher_ready);
if (ret) {
dev_err(wrp->dev, "cipher data ready@AP fail, ret=%d\n", ret);
return ret;
}
ret = pwrap_wait_for_state(wrp, pwrap_is_pmic_cipher_ready);
if (ret) {
dev_err(wrp->dev, "timeout waiting for cipher data ready@PMIC\n");
return ret;
}
pwrap_write(wrp, PWRAP_DEW_CIPHER_MODE, 0x1);
ret = pwrap_wait_for_state(wrp, pwrap_is_fsm_idle_and_sync_idle);
if (ret) {
dev_err(wrp->dev, "cipher mode idle fail, ret=%d\n", ret);
return ret;
}
pwrap_writel(wrp, 1, PWRAP_CIPHER_MODE);
if (pwrap_write(wrp, PWRAP_DEW_WRITE_TEST, PWRAP_DEW_WRITE_TEST_VAL) ||
pwrap_read(wrp, PWRAP_DEW_WRITE_TEST, &rdata) ||
(rdata != PWRAP_DEW_WRITE_TEST_VAL)) {
dev_err(wrp->dev, "rdata=0x%04X\n", rdata);
return -EFAULT;
}
return 0;
}
static int pwrap_init(struct pmic_wrapper *wrp)
{
int ret;
u32 rdata;
reset_control_reset(wrp->rstc);
if (wrp->rstc_bridge)
reset_control_reset(wrp->rstc_bridge);
if (pwrap_is_mt8173(wrp)) {
pwrap_writel(wrp, 3, PWRAP_DCM_EN);
pwrap_writel(wrp, 0, PWRAP_DCM_DBC_PRD);
}
ret = pwrap_reset_spislave(wrp);
if (ret)
return ret;
pwrap_writel(wrp, 1, PWRAP_WRAP_EN);
pwrap_writel(wrp, wrp->arb_en_all, PWRAP_HIPRIO_ARB_EN);
pwrap_writel(wrp, 1, PWRAP_WACS2_EN);
ret = pwrap_init_reg_clock(wrp);
if (ret)
return ret;
ret = pwrap_init_sidly(wrp);
if (ret)
return ret;
pwrap_write(wrp, PWRAP_DEW_DIO_EN, 1);
ret = pwrap_wait_for_state(wrp, pwrap_is_fsm_idle_and_sync_idle);
if (ret) {
dev_err(wrp->dev, "%s fail, ret=%d\n", __func__, ret);
return ret;
}
pwrap_writel(wrp, 1, PWRAP_DIO_EN);
pwrap_read(wrp, PWRAP_DEW_READ_TEST, &rdata);
if (rdata != PWRAP_DEW_READ_TEST_VAL) {
dev_err(wrp->dev, "Read test failed after switch to DIO mode: 0x%04x != 0x%04x\n",
PWRAP_DEW_READ_TEST_VAL, rdata);
return -EFAULT;
}
ret = pwrap_init_cipher(wrp);
if (ret)
return ret;
if (pwrap_write(wrp, PWRAP_DEW_CRC_EN, 0x1))
return -EFAULT;
pwrap_writel(wrp, 0x1, PWRAP_CRC_EN);
pwrap_writel(wrp, 0x0, PWRAP_SIG_MODE);
pwrap_writel(wrp, PWRAP_DEW_CRC_VAL, PWRAP_SIG_ADR);
pwrap_writel(wrp, wrp->arb_en_all, PWRAP_HIPRIO_ARB_EN);
if (pwrap_is_mt8135(wrp))
pwrap_writel(wrp, 0x7, PWRAP_RRARB_EN);
pwrap_writel(wrp, 0x1, PWRAP_WACS0_EN);
pwrap_writel(wrp, 0x1, PWRAP_WACS1_EN);
pwrap_writel(wrp, 0x1, PWRAP_WACS2_EN);
pwrap_writel(wrp, 0x5, PWRAP_STAUPD_PRD);
pwrap_writel(wrp, 0xff, PWRAP_STAUPD_GRPEN);
if (pwrap_is_mt8135(wrp)) {
pwrap_writel(wrp, 0x1, PWRAP_EVENT_IN_EN);
pwrap_writel(wrp, 0xffff, PWRAP_EVENT_DST_EN);
writel(0x7f, wrp->bridge_base + PWRAP_MT8135_BRIDGE_IORD_ARB_EN);
writel(0x1, wrp->bridge_base + PWRAP_MT8135_BRIDGE_WACS3_EN);
writel(0x1, wrp->bridge_base + PWRAP_MT8135_BRIDGE_WACS4_EN);
writel(0x1, wrp->bridge_base + PWRAP_MT8135_BRIDGE_WDT_UNIT);
writel(0xffff, wrp->bridge_base + PWRAP_MT8135_BRIDGE_WDT_SRC_EN);
writel(0x1, wrp->bridge_base + PWRAP_MT8135_BRIDGE_TIMER_EN);
writel(0x7ff, wrp->bridge_base + PWRAP_MT8135_BRIDGE_INT_EN);
if (pwrap_write(wrp, PWRAP_DEW_EVENT_OUT_EN, 0x1) ||
pwrap_write(wrp, PWRAP_DEW_EVENT_SRC_EN, 0xffff)) {
dev_err(wrp->dev, "enable dewrap fail\n");
return -EFAULT;
}
} else {
if (pwrap_write(wrp, PWRAP_DEW_EVENT_OUT_EN, 0x1) ||
pwrap_write(wrp, PWRAP_DEW_EVENT_SRC_EN, 0xffff)) {
dev_err(wrp->dev, "enable dewrap fail\n");
return -EFAULT;
}
}
pwrap_writel(wrp, 1, PWRAP_INIT_DONE2);
pwrap_writel(wrp, 1, PWRAP_INIT_DONE0);
pwrap_writel(wrp, 1, PWRAP_INIT_DONE1);
if (pwrap_is_mt8135(wrp)) {
writel(1, wrp->bridge_base + PWRAP_MT8135_BRIDGE_INIT_DONE3);
writel(1, wrp->bridge_base + PWRAP_MT8135_BRIDGE_INIT_DONE4);
}
return 0;
}
static irqreturn_t pwrap_interrupt(int irqno, void *dev_id)
{
u32 rdata;
struct pmic_wrapper *wrp = dev_id;
rdata = pwrap_readl(wrp, PWRAP_INT_FLG);
dev_err(wrp->dev, "unexpected interrupt int=0x%x\n", rdata);
pwrap_writel(wrp, 0xffffffff, PWRAP_INT_CLR);
return IRQ_HANDLED;
}
static int pwrap_probe(struct platform_device *pdev)
{
int ret, irq;
struct pmic_wrapper *wrp;
struct device_node *np = pdev->dev.of_node;
const struct of_device_id *of_id =
of_match_device(of_pwrap_match_tbl, &pdev->dev);
const struct pmic_wrapper_type *type;
struct resource *res;
wrp = devm_kzalloc(&pdev->dev, sizeof(*wrp), GFP_KERNEL);
if (!wrp)
return -ENOMEM;
platform_set_drvdata(pdev, wrp);
type = of_id->data;
wrp->regs = type->regs;
wrp->type = type->type;
wrp->arb_en_all = type->arb_en_all;
wrp->dev = &pdev->dev;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "pwrap");
wrp->base = devm_ioremap_resource(wrp->dev, res);
if (IS_ERR(wrp->base))
return PTR_ERR(wrp->base);
wrp->rstc = devm_reset_control_get(wrp->dev, "pwrap");
if (IS_ERR(wrp->rstc)) {
ret = PTR_ERR(wrp->rstc);
dev_dbg(wrp->dev, "cannot get pwrap reset: %d\n", ret);
return ret;
}
if (pwrap_is_mt8135(wrp)) {
res = platform_get_resource_byname(pdev, IORESOURCE_MEM,
"pwrap-bridge");
wrp->bridge_base = devm_ioremap_resource(wrp->dev, res);
if (IS_ERR(wrp->bridge_base))
return PTR_ERR(wrp->bridge_base);
wrp->rstc_bridge = devm_reset_control_get(wrp->dev, "pwrap-bridge");
if (IS_ERR(wrp->rstc_bridge)) {
ret = PTR_ERR(wrp->rstc_bridge);
dev_dbg(wrp->dev, "cannot get pwrap-bridge reset: %d\n", ret);
return ret;
}
}
wrp->clk_spi = devm_clk_get(wrp->dev, "spi");
if (IS_ERR(wrp->clk_spi)) {
dev_dbg(wrp->dev, "failed to get clock: %ld\n", PTR_ERR(wrp->clk_spi));
return PTR_ERR(wrp->clk_spi);
}
wrp->clk_wrap = devm_clk_get(wrp->dev, "wrap");
if (IS_ERR(wrp->clk_wrap)) {
dev_dbg(wrp->dev, "failed to get clock: %ld\n", PTR_ERR(wrp->clk_wrap));
return PTR_ERR(wrp->clk_wrap);
}
ret = clk_prepare_enable(wrp->clk_spi);
if (ret)
return ret;
ret = clk_prepare_enable(wrp->clk_wrap);
if (ret)
goto err_out1;
pwrap_writel(wrp, 1, PWRAP_DCM_EN);
pwrap_writel(wrp, 0, PWRAP_DCM_DBC_PRD);
if (!pwrap_readl(wrp, PWRAP_INIT_DONE2)) {
ret = pwrap_init(wrp);
if (ret) {
dev_dbg(wrp->dev, "init failed with %d\n", ret);
goto err_out2;
}
}
if (!(pwrap_readl(wrp, PWRAP_WACS2_RDATA) & PWRAP_STATE_INIT_DONE0)) {
dev_dbg(wrp->dev, "initialization isn't finished\n");
return -ENODEV;
}
pwrap_writel(wrp, 0xf, PWRAP_WDT_UNIT);
pwrap_writel(wrp, 0xffffffff, PWRAP_WDT_SRC_EN);
pwrap_writel(wrp, 0x1, PWRAP_TIMER_EN);
pwrap_writel(wrp, ~((1 << 31) | (1 << 1)), PWRAP_INT_EN);
irq = platform_get_irq(pdev, 0);
ret = devm_request_irq(wrp->dev, irq, pwrap_interrupt, IRQF_TRIGGER_HIGH,
"mt-pmic-pwrap", wrp);
if (ret)
goto err_out2;
wrp->regmap = devm_regmap_init(wrp->dev, NULL, wrp, &pwrap_regmap_config);
if (IS_ERR(wrp->regmap))
return PTR_ERR(wrp->regmap);
ret = of_platform_populate(np, NULL, NULL, wrp->dev);
if (ret) {
dev_dbg(wrp->dev, "failed to create child devices at %s\n",
np->full_name);
goto err_out2;
}
return 0;
err_out2:
clk_disable_unprepare(wrp->clk_wrap);
err_out1:
clk_disable_unprepare(wrp->clk_spi);
return ret;
}
