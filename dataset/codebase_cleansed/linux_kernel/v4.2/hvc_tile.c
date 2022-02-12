static int __init sim_console(char *str)
{
use_sim_console = 1;
return 0;
}
int tile_console_write(const char *buf, int count)
{
if (unlikely(use_sim_console)) {
int i;
for (i = 0; i < count; ++i)
__insn_mtspr(SPR_SIM_CONTROL, SIM_CONTROL_PUTC |
(buf[i] << _SIM_CONTROL_OPERATOR_BITS));
__insn_mtspr(SPR_SIM_CONTROL, SIM_CONTROL_PUTC |
(SIM_PUTC_FLUSH_BINARY <<
_SIM_CONTROL_OPERATOR_BITS));
return 0;
} else {
return hv_console_write((HV_VirtAddr)buf, count) ?: -EAGAIN;
}
}
static int hvc_tile_put_chars(uint32_t vt, const char *buf, int count)
{
return tile_console_write(buf, count);
}
static int hvc_tile_get_chars(uint32_t vt, char *buf, int count)
{
int i, c;
for (i = 0; i < count; ++i) {
c = hv_console_read_if_ready();
if (c < 0)
break;
buf[i] = c;
}
return i;
}
static int hvc_tile_notifier_add_irq(struct hvc_struct *hp, int irq)
{
int rc;
int cpu = raw_smp_processor_id();
HV_Coord coord = { .x = cpu_x(cpu), .y = cpu_y(cpu) };
rc = notifier_add_irq(hp, irq);
if (rc)
return rc;
if (hv_console_set_ipi(KERNEL_PL, irq, coord) < 0)
notifier_del_irq(hp, irq);
return 0;
}
static void hvc_tile_notifier_del_irq(struct hvc_struct *hp, int irq)
{
HV_Coord coord = { 0, 0 };
hv_console_set_ipi(KERNEL_PL, -1, coord);
notifier_del_irq(hp, irq);
}
static void hvc_tile_notifier_hangup_irq(struct hvc_struct *hp, int irq)
{
hvc_tile_notifier_del_irq(hp, irq);
}
static int hvc_tile_probe(struct platform_device *pdev)
{
struct hvc_struct *hp;
int tile_hvc_irq;
tile_hvc_irq = irq_alloc_hwirq(-1);
if (!tile_hvc_irq)
return -ENXIO;
tile_irq_activate(tile_hvc_irq, TILE_IRQ_PERCPU);
hp = hvc_alloc(0, tile_hvc_irq, &hvc_tile_get_put_ops, 128);
if (IS_ERR(hp)) {
irq_free_hwirq(tile_hvc_irq);
return PTR_ERR(hp);
}
dev_set_drvdata(&pdev->dev, hp);
return 0;
}
static int hvc_tile_remove(struct platform_device *pdev)
{
int rc;
struct hvc_struct *hp = dev_get_drvdata(&pdev->dev);
rc = hvc_remove(hp);
if (rc == 0)
irq_free_hwirq(hp->data);
return rc;
}
static void hvc_tile_shutdown(struct platform_device *pdev)
{
struct hvc_struct *hp = dev_get_drvdata(&pdev->dev);
hvc_tile_notifier_del_irq(hp, hp->data);
}
static int __init hvc_tile_console_init(void)
{
hvc_instantiate(0, 0, &hvc_tile_get_put_ops);
add_preferred_console("hvc", 0, NULL);
return 0;
}
static int __init hvc_tile_init(void)
{
#ifndef __tilegx__
struct hvc_struct *hp;
hp = hvc_alloc(0, 0, &hvc_tile_get_put_ops, 128);
return PTR_ERR_OR_ZERO(hp);
#else
platform_device_register(&hvc_tile_pdev);
return platform_driver_register(&hvc_tile_driver);
#endif
}
