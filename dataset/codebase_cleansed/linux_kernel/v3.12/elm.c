static void elm_write_reg(struct elm_info *info, int offset, u32 val)
{
writel(val, info->elm_base + offset);
}
static u32 elm_read_reg(struct elm_info *info, int offset)
{
return readl(info->elm_base + offset);
}
int elm_config(struct device *dev, enum bch_ecc bch_type)
{
u32 reg_val;
struct elm_info *info = dev_get_drvdata(dev);
if (!info) {
dev_err(dev, "Unable to configure elm - device not probed?\n");
return -ENODEV;
}
reg_val = (bch_type & ECC_BCH_LEVEL_MASK) | (ELM_ECC_SIZE << 16);
elm_write_reg(info, ELM_LOCATION_CONFIG, reg_val);
info->bch_type = bch_type;
return 0;
}
static void elm_configure_page_mode(struct elm_info *info, int index,
bool enable)
{
u32 reg_val;
reg_val = elm_read_reg(info, ELM_PAGE_CTRL);
if (enable)
reg_val |= BIT(index);
else
reg_val &= ~BIT(index);
elm_write_reg(info, ELM_PAGE_CTRL, reg_val);
}
static void elm_load_syndrome(struct elm_info *info,
struct elm_errorvec *err_vec, u8 *ecc)
{
int i, offset;
u32 val;
for (i = 0; i < ERROR_VECTOR_MAX; i++) {
if (err_vec[i].error_reported) {
elm_configure_page_mode(info, i, true);
offset = ELM_SYNDROME_FRAGMENT_0 +
SYNDROME_FRAGMENT_REG_SIZE * i;
if (info->bch_type) {
val = cpu_to_be32(*(u32 *) &ecc[9]);
elm_write_reg(info, offset, val);
offset += 4;
val = cpu_to_be32(*(u32 *) &ecc[5]);
elm_write_reg(info, offset, val);
offset += 4;
val = cpu_to_be32(*(u32 *) &ecc[1]);
elm_write_reg(info, offset, val);
offset += 4;
val = ecc[0];
elm_write_reg(info, offset, val);
} else {
val = (cpu_to_be32(*(u32 *) &ecc[3]) >> 4) |
((ecc[2] & 0xf) << 28);
elm_write_reg(info, offset, val);
offset += 4;
val = cpu_to_be32(*(u32 *) &ecc[0]) >> 12;
elm_write_reg(info, offset, val);
}
}
ecc += info->bch_type ? BCH8_SIZE : BCH4_SIZE;
}
}
static void elm_start_processing(struct elm_info *info,
struct elm_errorvec *err_vec)
{
int i, offset;
u32 reg_val;
for (i = 0; i < ERROR_VECTOR_MAX; i++) {
if (err_vec[i].error_reported) {
offset = ELM_SYNDROME_FRAGMENT_6 +
SYNDROME_FRAGMENT_REG_SIZE * i;
reg_val = elm_read_reg(info, offset);
reg_val |= ELM_SYNDROME_VALID;
elm_write_reg(info, offset, reg_val);
}
}
}
static void elm_error_correction(struct elm_info *info,
struct elm_errorvec *err_vec)
{
int i, j, errors = 0;
int offset;
u32 reg_val;
for (i = 0; i < ERROR_VECTOR_MAX; i++) {
if (err_vec[i].error_reported) {
offset = ELM_LOCATION_STATUS + ERROR_LOCATION_SIZE * i;
reg_val = elm_read_reg(info, offset);
if (reg_val & ECC_CORRECTABLE_MASK) {
offset = ELM_ERROR_LOCATION_0 +
ERROR_LOCATION_SIZE * i;
err_vec[i].error_count = reg_val &
ECC_NB_ERRORS_MASK;
for (j = 0; j < err_vec[i].error_count; j++) {
reg_val = elm_read_reg(info, offset);
err_vec[i].error_loc[j] = reg_val &
ECC_ERROR_LOCATION_MASK;
offset += 4;
}
errors += err_vec[i].error_count;
} else {
err_vec[i].error_uncorrectable = true;
}
elm_write_reg(info, ELM_IRQSTATUS, BIT(i));
elm_configure_page_mode(info, i, false);
}
}
}
void elm_decode_bch_error_page(struct device *dev, u8 *ecc_calc,
struct elm_errorvec *err_vec)
{
struct elm_info *info = dev_get_drvdata(dev);
u32 reg_val;
reg_val = elm_read_reg(info, ELM_IRQSTATUS);
elm_write_reg(info, ELM_IRQSTATUS, reg_val & INTR_STATUS_PAGE_VALID);
elm_write_reg(info, ELM_IRQENABLE, INTR_EN_PAGE_MASK);
elm_load_syndrome(info, err_vec, ecc_calc);
elm_start_processing(info, err_vec);
wait_for_completion(&info->elm_completion);
reg_val = elm_read_reg(info, ELM_IRQENABLE);
elm_write_reg(info, ELM_IRQENABLE, reg_val & ~INTR_EN_PAGE_MASK);
elm_error_correction(info, err_vec);
}
static irqreturn_t elm_isr(int this_irq, void *dev_id)
{
u32 reg_val;
struct elm_info *info = dev_id;
reg_val = elm_read_reg(info, ELM_IRQSTATUS);
if (reg_val & INTR_STATUS_PAGE_VALID) {
elm_write_reg(info, ELM_IRQSTATUS,
reg_val & INTR_STATUS_PAGE_VALID);
complete(&info->elm_completion);
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static int elm_probe(struct platform_device *pdev)
{
int ret = 0;
struct resource *res, *irq;
struct elm_info *info;
info = devm_kzalloc(&pdev->dev, sizeof(*info), GFP_KERNEL);
if (!info) {
dev_err(&pdev->dev, "failed to allocate memory\n");
return -ENOMEM;
}
info->dev = &pdev->dev;
irq = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!irq) {
dev_err(&pdev->dev, "no irq resource defined\n");
return -ENODEV;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
info->elm_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(info->elm_base))
return PTR_ERR(info->elm_base);
ret = devm_request_irq(&pdev->dev, irq->start, elm_isr, 0,
pdev->name, info);
if (ret) {
dev_err(&pdev->dev, "failure requesting irq %i\n", irq->start);
return ret;
}
pm_runtime_enable(&pdev->dev);
if (pm_runtime_get_sync(&pdev->dev)) {
ret = -EINVAL;
pm_runtime_disable(&pdev->dev);
dev_err(&pdev->dev, "can't enable clock\n");
return ret;
}
init_completion(&info->elm_completion);
INIT_LIST_HEAD(&info->list);
list_add(&info->list, &elm_devices);
platform_set_drvdata(pdev, info);
return ret;
}
static int elm_remove(struct platform_device *pdev)
{
pm_runtime_put_sync(&pdev->dev);
pm_runtime_disable(&pdev->dev);
return 0;
}
static int elm_context_save(struct elm_info *info)
{
struct elm_registers *regs = &info->elm_regs;
enum bch_ecc bch_type = info->bch_type;
u32 offset = 0, i;
regs->elm_irqenable = elm_read_reg(info, ELM_IRQENABLE);
regs->elm_sysconfig = elm_read_reg(info, ELM_SYSCONFIG);
regs->elm_location_config = elm_read_reg(info, ELM_LOCATION_CONFIG);
regs->elm_page_ctrl = elm_read_reg(info, ELM_PAGE_CTRL);
for (i = 0; i < ERROR_VECTOR_MAX; i++) {
offset = i * SYNDROME_FRAGMENT_REG_SIZE;
switch (bch_type) {
case BCH8_ECC:
regs->elm_syndrome_fragment_3[i] = elm_read_reg(info,
ELM_SYNDROME_FRAGMENT_3 + offset);
regs->elm_syndrome_fragment_2[i] = elm_read_reg(info,
ELM_SYNDROME_FRAGMENT_2 + offset);
case BCH4_ECC:
regs->elm_syndrome_fragment_1[i] = elm_read_reg(info,
ELM_SYNDROME_FRAGMENT_1 + offset);
regs->elm_syndrome_fragment_0[i] = elm_read_reg(info,
ELM_SYNDROME_FRAGMENT_0 + offset);
default:
return -EINVAL;
}
regs->elm_syndrome_fragment_6[i] = elm_read_reg(info,
ELM_SYNDROME_FRAGMENT_6 + offset);
}
return 0;
}
static int elm_context_restore(struct elm_info *info)
{
struct elm_registers *regs = &info->elm_regs;
enum bch_ecc bch_type = info->bch_type;
u32 offset = 0, i;
elm_write_reg(info, ELM_IRQENABLE, regs->elm_irqenable);
elm_write_reg(info, ELM_SYSCONFIG, regs->elm_sysconfig);
elm_write_reg(info, ELM_LOCATION_CONFIG, regs->elm_location_config);
elm_write_reg(info, ELM_PAGE_CTRL, regs->elm_page_ctrl);
for (i = 0; i < ERROR_VECTOR_MAX; i++) {
offset = i * SYNDROME_FRAGMENT_REG_SIZE;
switch (bch_type) {
case BCH8_ECC:
elm_write_reg(info, ELM_SYNDROME_FRAGMENT_3 + offset,
regs->elm_syndrome_fragment_3[i]);
elm_write_reg(info, ELM_SYNDROME_FRAGMENT_2 + offset,
regs->elm_syndrome_fragment_2[i]);
case BCH4_ECC:
elm_write_reg(info, ELM_SYNDROME_FRAGMENT_1 + offset,
regs->elm_syndrome_fragment_1[i]);
elm_write_reg(info, ELM_SYNDROME_FRAGMENT_0 + offset,
regs->elm_syndrome_fragment_0[i]);
default:
return -EINVAL;
}
elm_write_reg(info, ELM_SYNDROME_FRAGMENT_6 + offset,
regs->elm_syndrome_fragment_6[i] &
ELM_SYNDROME_VALID);
}
return 0;
}
static int elm_suspend(struct device *dev)
{
struct elm_info *info = dev_get_drvdata(dev);
elm_context_save(info);
pm_runtime_put_sync(dev);
return 0;
}
static int elm_resume(struct device *dev)
{
struct elm_info *info = dev_get_drvdata(dev);
pm_runtime_get_sync(dev);
elm_context_restore(info);
return 0;
}
