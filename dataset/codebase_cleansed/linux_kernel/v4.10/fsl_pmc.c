static int pmc_suspend_enter(suspend_state_t state)
{
int ret;
setbits32(&pmc_regs->pmcsr, PMCSR_SLP);
ret = spin_event_timeout((in_be32(&pmc_regs->pmcsr) & PMCSR_SLP) == 0,
10000, 10) ? 0 : -ETIMEDOUT;
if (ret)
dev_err(pmc_dev, "tired waiting for SLP bit to clear\n");
return ret;
}
static int pmc_suspend_valid(suspend_state_t state)
{
if (state != PM_SUSPEND_STANDBY)
return 0;
return 1;
}
static int pmc_probe(struct platform_device *ofdev)
{
pmc_regs = of_iomap(ofdev->dev.of_node, 0);
if (!pmc_regs)
return -ENOMEM;
pmc_dev = &ofdev->dev;
suspend_set_ops(&pmc_suspend_ops);
return 0;
}
