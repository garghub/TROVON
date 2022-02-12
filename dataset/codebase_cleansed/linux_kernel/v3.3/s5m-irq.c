static inline struct s5m_irq_data *
irq_to_s5m8767_irq(struct s5m87xx_dev *s5m87xx, int irq)
{
return &s5m8767_irqs[irq - s5m87xx->irq_base];
}
static void s5m8767_irq_lock(struct irq_data *data)
{
struct s5m87xx_dev *s5m87xx = irq_data_get_irq_chip_data(data);
mutex_lock(&s5m87xx->irqlock);
}
static void s5m8767_irq_sync_unlock(struct irq_data *data)
{
struct s5m87xx_dev *s5m87xx = irq_data_get_irq_chip_data(data);
int i;
for (i = 0; i < ARRAY_SIZE(s5m87xx->irq_masks_cur); i++) {
if (s5m87xx->irq_masks_cur[i] != s5m87xx->irq_masks_cache[i]) {
s5m87xx->irq_masks_cache[i] = s5m87xx->irq_masks_cur[i];
s5m_reg_write(s5m87xx, S5M8767_REG_INT1M + i,
s5m87xx->irq_masks_cur[i]);
}
}
mutex_unlock(&s5m87xx->irqlock);
}
static void s5m8767_irq_unmask(struct irq_data *data)
{
struct s5m87xx_dev *s5m87xx = irq_data_get_irq_chip_data(data);
struct s5m_irq_data *irq_data = irq_to_s5m8767_irq(s5m87xx,
data->irq);
s5m87xx->irq_masks_cur[irq_data->reg - 1] &= ~irq_data->mask;
}
static void s5m8767_irq_mask(struct irq_data *data)
{
struct s5m87xx_dev *s5m87xx = irq_data_get_irq_chip_data(data);
struct s5m_irq_data *irq_data = irq_to_s5m8767_irq(s5m87xx,
data->irq);
s5m87xx->irq_masks_cur[irq_data->reg - 1] |= irq_data->mask;
}
static inline struct s5m_irq_data *
irq_to_s5m8763_irq(struct s5m87xx_dev *s5m87xx, int irq)
{
return &s5m8763_irqs[irq - s5m87xx->irq_base];
}
static void s5m8763_irq_lock(struct irq_data *data)
{
struct s5m87xx_dev *s5m87xx = irq_data_get_irq_chip_data(data);
mutex_lock(&s5m87xx->irqlock);
}
static void s5m8763_irq_sync_unlock(struct irq_data *data)
{
struct s5m87xx_dev *s5m87xx = irq_data_get_irq_chip_data(data);
int i;
for (i = 0; i < ARRAY_SIZE(s5m87xx->irq_masks_cur); i++) {
if (s5m87xx->irq_masks_cur[i] != s5m87xx->irq_masks_cache[i]) {
s5m87xx->irq_masks_cache[i] = s5m87xx->irq_masks_cur[i];
s5m_reg_write(s5m87xx, S5M8763_REG_IRQM1 + i,
s5m87xx->irq_masks_cur[i]);
}
}
mutex_unlock(&s5m87xx->irqlock);
}
static void s5m8763_irq_unmask(struct irq_data *data)
{
struct s5m87xx_dev *s5m87xx = irq_data_get_irq_chip_data(data);
struct s5m_irq_data *irq_data = irq_to_s5m8763_irq(s5m87xx,
data->irq);
s5m87xx->irq_masks_cur[irq_data->reg - 1] &= ~irq_data->mask;
}
static void s5m8763_irq_mask(struct irq_data *data)
{
struct s5m87xx_dev *s5m87xx = irq_data_get_irq_chip_data(data);
struct s5m_irq_data *irq_data = irq_to_s5m8763_irq(s5m87xx,
data->irq);
s5m87xx->irq_masks_cur[irq_data->reg - 1] |= irq_data->mask;
}
static irqreturn_t s5m8767_irq_thread(int irq, void *data)
{
struct s5m87xx_dev *s5m87xx = data;
u8 irq_reg[NUM_IRQ_REGS-1];
int ret;
int i;
ret = s5m_bulk_read(s5m87xx, S5M8767_REG_INT1,
NUM_IRQ_REGS - 1, irq_reg);
if (ret < 0) {
dev_err(s5m87xx->dev, "Failed to read interrupt register: %d\n",
ret);
return IRQ_NONE;
}
for (i = 0; i < NUM_IRQ_REGS - 1; i++)
irq_reg[i] &= ~s5m87xx->irq_masks_cur[i];
for (i = 0; i < S5M8767_IRQ_NR; i++) {
if (irq_reg[s5m8767_irqs[i].reg - 1] & s5m8767_irqs[i].mask)
handle_nested_irq(s5m87xx->irq_base + i);
}
return IRQ_HANDLED;
}
static irqreturn_t s5m8763_irq_thread(int irq, void *data)
{
struct s5m87xx_dev *s5m87xx = data;
u8 irq_reg[NUM_IRQ_REGS];
int ret;
int i;
ret = s5m_bulk_read(s5m87xx, S5M8763_REG_IRQ1,
NUM_IRQ_REGS, irq_reg);
if (ret < 0) {
dev_err(s5m87xx->dev, "Failed to read interrupt register: %d\n",
ret);
return IRQ_NONE;
}
for (i = 0; i < NUM_IRQ_REGS; i++)
irq_reg[i] &= ~s5m87xx->irq_masks_cur[i];
for (i = 0; i < S5M8763_IRQ_NR; i++) {
if (irq_reg[s5m8763_irqs[i].reg - 1] & s5m8763_irqs[i].mask)
handle_nested_irq(s5m87xx->irq_base + i);
}
return IRQ_HANDLED;
}
int s5m_irq_resume(struct s5m87xx_dev *s5m87xx)
{
if (s5m87xx->irq && s5m87xx->irq_base){
switch (s5m87xx->device_type) {
case S5M8763X:
s5m8763_irq_thread(s5m87xx->irq_base, s5m87xx);
break;
case S5M8767X:
s5m8767_irq_thread(s5m87xx->irq_base, s5m87xx);
break;
default:
break;
}
}
return 0;
}
int s5m_irq_init(struct s5m87xx_dev *s5m87xx)
{
int i;
int cur_irq;
int ret = 0;
int type = s5m87xx->device_type;
if (!s5m87xx->irq) {
dev_warn(s5m87xx->dev,
"No interrupt specified, no interrupts\n");
s5m87xx->irq_base = 0;
return 0;
}
if (!s5m87xx->irq_base) {
dev_err(s5m87xx->dev,
"No interrupt base specified, no interrupts\n");
return 0;
}
mutex_init(&s5m87xx->irqlock);
switch (type) {
case S5M8763X:
for (i = 0; i < NUM_IRQ_REGS; i++) {
s5m87xx->irq_masks_cur[i] = 0xff;
s5m87xx->irq_masks_cache[i] = 0xff;
s5m_reg_write(s5m87xx, S5M8763_REG_IRQM1 + i,
0xff);
}
s5m_reg_write(s5m87xx, S5M8763_REG_STATUSM1, 0xff);
s5m_reg_write(s5m87xx, S5M8763_REG_STATUSM2, 0xff);
for (i = 0; i < S5M8763_IRQ_NR; i++) {
cur_irq = i + s5m87xx->irq_base;
irq_set_chip_data(cur_irq, s5m87xx);
irq_set_chip_and_handler(cur_irq, &s5m8763_irq_chip,
handle_edge_irq);
irq_set_nested_thread(cur_irq, 1);
#ifdef CONFIG_ARM
set_irq_flags(cur_irq, IRQF_VALID);
#else
irq_set_noprobe(cur_irq);
#endif
}
ret = request_threaded_irq(s5m87xx->irq, NULL,
s5m8763_irq_thread,
IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
"s5m87xx-irq", s5m87xx);
if (ret) {
dev_err(s5m87xx->dev, "Failed to request IRQ %d: %d\n",
s5m87xx->irq, ret);
return ret;
}
break;
case S5M8767X:
for (i = 0; i < NUM_IRQ_REGS - 1; i++) {
s5m87xx->irq_masks_cur[i] = 0xff;
s5m87xx->irq_masks_cache[i] = 0xff;
s5m_reg_write(s5m87xx, S5M8767_REG_INT1M + i,
0xff);
}
for (i = 0; i < S5M8767_IRQ_NR; i++) {
cur_irq = i + s5m87xx->irq_base;
irq_set_chip_data(cur_irq, s5m87xx);
if (ret) {
dev_err(s5m87xx->dev,
"Failed to irq_set_chip_data %d: %d\n",
s5m87xx->irq, ret);
return ret;
}
irq_set_chip_and_handler(cur_irq, &s5m8767_irq_chip,
handle_edge_irq);
irq_set_nested_thread(cur_irq, 1);
#ifdef CONFIG_ARM
set_irq_flags(cur_irq, IRQF_VALID);
#else
irq_set_noprobe(cur_irq);
#endif
}
ret = request_threaded_irq(s5m87xx->irq, NULL,
s5m8767_irq_thread,
IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
"s5m87xx-irq", s5m87xx);
if (ret) {
dev_err(s5m87xx->dev, "Failed to request IRQ %d: %d\n",
s5m87xx->irq, ret);
return ret;
}
break;
default:
break;
}
if (!s5m87xx->ono)
return 0;
switch (type) {
case S5M8763X:
ret = request_threaded_irq(s5m87xx->ono, NULL,
s5m8763_irq_thread,
IRQF_TRIGGER_FALLING |
IRQF_TRIGGER_RISING |
IRQF_ONESHOT, "s5m87xx-ono",
s5m87xx);
break;
case S5M8767X:
ret = request_threaded_irq(s5m87xx->ono, NULL,
s5m8767_irq_thread,
IRQF_TRIGGER_FALLING |
IRQF_TRIGGER_RISING |
IRQF_ONESHOT, "s5m87xx-ono", s5m87xx);
break;
default:
break;
}
if (ret)
dev_err(s5m87xx->dev, "Failed to request IRQ %d: %d\n",
s5m87xx->ono, ret);
return 0;
}
void s5m_irq_exit(struct s5m87xx_dev *s5m87xx)
{
if (s5m87xx->ono)
free_irq(s5m87xx->ono, s5m87xx);
if (s5m87xx->irq)
free_irq(s5m87xx->irq, s5m87xx);
}
