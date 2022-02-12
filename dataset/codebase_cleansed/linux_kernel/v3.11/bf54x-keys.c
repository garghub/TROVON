static inline int bfin_kpad_find_key(struct bf54x_kpad *bf54x_kpad,
struct input_dev *input, u16 keyident)
{
u16 i;
for (i = 0; i < input->keycodemax; i++)
if (bf54x_kpad->keycode[i + input->keycodemax] == keyident)
return bf54x_kpad->keycode[i];
return -1;
}
static inline void bfin_keycodecpy(unsigned short *keycode,
const unsigned int *pdata_kc,
unsigned short keymapsize)
{
unsigned int i;
for (i = 0; i < keymapsize; i++) {
keycode[i] = pdata_kc[i] & 0xffff;
keycode[i + keymapsize] = pdata_kc[i] >> 16;
}
}
static inline u16 bfin_kpad_get_prescale(u32 timescale)
{
u32 sclk = get_sclk();
return ((((sclk / 1000) * timescale) / 1024) - 1);
}
static inline u16 bfin_kpad_get_keypressed(struct bf54x_kpad *bf54x_kpad)
{
return (bfin_read_KPAD_STAT() & KPAD_PRESSED);
}
static inline void bfin_kpad_clear_irq(void)
{
bfin_write_KPAD_STAT(0xFFFF);
bfin_write_KPAD_ROWCOL(0xFFFF);
}
static void bfin_kpad_timer(unsigned long data)
{
struct platform_device *pdev = (struct platform_device *) data;
struct bf54x_kpad *bf54x_kpad = platform_get_drvdata(pdev);
if (bfin_kpad_get_keypressed(bf54x_kpad)) {
mod_timer(&bf54x_kpad->timer,
jiffies + bf54x_kpad->keyup_test_jiffies);
return;
}
input_report_key(bf54x_kpad->input, bf54x_kpad->lastkey, 0);
input_sync(bf54x_kpad->input);
bfin_kpad_clear_irq();
enable_irq(bf54x_kpad->irq);
}
static irqreturn_t bfin_kpad_isr(int irq, void *dev_id)
{
struct platform_device *pdev = dev_id;
struct bf54x_kpad *bf54x_kpad = platform_get_drvdata(pdev);
struct input_dev *input = bf54x_kpad->input;
int key;
u16 rowcol = bfin_read_KPAD_ROWCOL();
key = bfin_kpad_find_key(bf54x_kpad, input, rowcol);
input_report_key(input, key, 1);
input_sync(input);
if (bfin_kpad_get_keypressed(bf54x_kpad)) {
disable_irq_nosync(bf54x_kpad->irq);
bf54x_kpad->lastkey = key;
mod_timer(&bf54x_kpad->timer,
jiffies + bf54x_kpad->keyup_test_jiffies);
} else {
input_report_key(input, key, 0);
input_sync(input);
bfin_kpad_clear_irq();
}
return IRQ_HANDLED;
}
static int bfin_kpad_probe(struct platform_device *pdev)
{
struct bf54x_kpad *bf54x_kpad;
struct bfin_kpad_platform_data *pdata = pdev->dev.platform_data;
struct input_dev *input;
int i, error;
if (!pdata->rows || !pdata->cols || !pdata->keymap) {
dev_err(&pdev->dev, "no rows, cols or keymap from pdata\n");
return -EINVAL;
}
if (!pdata->keymapsize ||
pdata->keymapsize > (pdata->rows * pdata->cols)) {
dev_err(&pdev->dev, "invalid keymapsize\n");
return -EINVAL;
}
bf54x_kpad = kzalloc(sizeof(struct bf54x_kpad), GFP_KERNEL);
if (!bf54x_kpad)
return -ENOMEM;
platform_set_drvdata(pdev, bf54x_kpad);
bf54x_kpad->keycode = kmalloc(pdata->keymapsize *
sizeof(unsigned short) * 2, GFP_KERNEL);
if (!bf54x_kpad->keycode) {
error = -ENOMEM;
goto out;
}
if (!pdata->debounce_time || pdata->debounce_time > MAX_MULT ||
!pdata->coldrive_time || pdata->coldrive_time > MAX_MULT) {
dev_warn(&pdev->dev,
"invalid platform debounce/columndrive time\n");
bfin_write_KPAD_MSEL(0xFF0);
} else {
bfin_write_KPAD_MSEL(
((pdata->debounce_time / TIME_SCALE)
& DBON_SCALE) |
(((pdata->coldrive_time / TIME_SCALE) << 8)
& COLDRV_SCALE));
}
if (!pdata->keyup_test_interval)
bf54x_kpad->keyup_test_jiffies = msecs_to_jiffies(50);
else
bf54x_kpad->keyup_test_jiffies =
msecs_to_jiffies(pdata->keyup_test_interval);
if (peripheral_request_list((u16 *)&per_rows[MAX_RC - pdata->rows],
DRV_NAME)) {
dev_err(&pdev->dev, "requesting peripherals failed\n");
error = -EFAULT;
goto out0;
}
if (peripheral_request_list((u16 *)&per_cols[MAX_RC - pdata->cols],
DRV_NAME)) {
dev_err(&pdev->dev, "requesting peripherals failed\n");
error = -EFAULT;
goto out1;
}
bf54x_kpad->irq = platform_get_irq(pdev, 0);
if (bf54x_kpad->irq < 0) {
error = -ENODEV;
goto out2;
}
error = request_irq(bf54x_kpad->irq, bfin_kpad_isr,
0, DRV_NAME, pdev);
if (error) {
dev_err(&pdev->dev, "unable to claim irq %d\n",
bf54x_kpad->irq);
goto out2;
}
input = input_allocate_device();
if (!input) {
error = -ENOMEM;
goto out3;
}
bf54x_kpad->input = input;
input->name = pdev->name;
input->phys = "bf54x-keys/input0";
input->dev.parent = &pdev->dev;
input_set_drvdata(input, bf54x_kpad);
input->id.bustype = BUS_HOST;
input->id.vendor = 0x0001;
input->id.product = 0x0001;
input->id.version = 0x0100;
input->keycodesize = sizeof(unsigned short);
input->keycodemax = pdata->keymapsize;
input->keycode = bf54x_kpad->keycode;
bfin_keycodecpy(bf54x_kpad->keycode, pdata->keymap, pdata->keymapsize);
__set_bit(EV_KEY, input->evbit);
if (pdata->repeat)
__set_bit(EV_REP, input->evbit);
for (i = 0; i < input->keycodemax; i++)
__set_bit(bf54x_kpad->keycode[i] & KEY_MAX, input->keybit);
__clear_bit(KEY_RESERVED, input->keybit);
error = input_register_device(input);
if (error) {
dev_err(&pdev->dev, "unable to register input device\n");
goto out4;
}
setup_timer(&bf54x_kpad->timer, bfin_kpad_timer, (unsigned long) pdev);
bfin_write_KPAD_PRESCALE(bfin_kpad_get_prescale(TIME_SCALE));
bfin_write_KPAD_CTL((((pdata->cols - 1) << 13) & KPAD_COLEN) |
(((pdata->rows - 1) << 10) & KPAD_ROWEN) |
(2 & KPAD_IRQMODE));
bfin_write_KPAD_CTL(bfin_read_KPAD_CTL() | KPAD_EN);
device_init_wakeup(&pdev->dev, 1);
return 0;
out4:
input_free_device(input);
out3:
free_irq(bf54x_kpad->irq, pdev);
out2:
peripheral_free_list((u16 *)&per_cols[MAX_RC - pdata->cols]);
out1:
peripheral_free_list((u16 *)&per_rows[MAX_RC - pdata->rows]);
out0:
kfree(bf54x_kpad->keycode);
out:
kfree(bf54x_kpad);
return error;
}
static int bfin_kpad_remove(struct platform_device *pdev)
{
struct bfin_kpad_platform_data *pdata = pdev->dev.platform_data;
struct bf54x_kpad *bf54x_kpad = platform_get_drvdata(pdev);
del_timer_sync(&bf54x_kpad->timer);
free_irq(bf54x_kpad->irq, pdev);
input_unregister_device(bf54x_kpad->input);
peripheral_free_list((u16 *)&per_rows[MAX_RC - pdata->rows]);
peripheral_free_list((u16 *)&per_cols[MAX_RC - pdata->cols]);
kfree(bf54x_kpad->keycode);
kfree(bf54x_kpad);
return 0;
}
static int bfin_kpad_suspend(struct platform_device *pdev, pm_message_t state)
{
struct bf54x_kpad *bf54x_kpad = platform_get_drvdata(pdev);
bf54x_kpad->kpad_msel = bfin_read_KPAD_MSEL();
bf54x_kpad->kpad_prescale = bfin_read_KPAD_PRESCALE();
bf54x_kpad->kpad_ctl = bfin_read_KPAD_CTL();
if (device_may_wakeup(&pdev->dev))
enable_irq_wake(bf54x_kpad->irq);
return 0;
}
static int bfin_kpad_resume(struct platform_device *pdev)
{
struct bf54x_kpad *bf54x_kpad = platform_get_drvdata(pdev);
bfin_write_KPAD_MSEL(bf54x_kpad->kpad_msel);
bfin_write_KPAD_PRESCALE(bf54x_kpad->kpad_prescale);
bfin_write_KPAD_CTL(bf54x_kpad->kpad_ctl);
if (device_may_wakeup(&pdev->dev))
disable_irq_wake(bf54x_kpad->irq);
return 0;
}
