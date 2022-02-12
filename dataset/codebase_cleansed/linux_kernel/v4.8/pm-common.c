void s3c_pm_do_save(struct sleep_save *ptr, int count)
{
for (; count > 0; count--, ptr++) {
ptr->val = readl_relaxed(ptr->reg);
S3C_PMDBG("saved %p value %08lx\n", ptr->reg, ptr->val);
}
}
void s3c_pm_do_restore(const struct sleep_save *ptr, int count)
{
for (; count > 0; count--, ptr++) {
pr_debug("restore %p (restore %08lx, was %08x)\n",
ptr->reg, ptr->val, readl_relaxed(ptr->reg));
writel_relaxed(ptr->val, ptr->reg);
}
}
void s3c_pm_do_restore_core(const struct sleep_save *ptr, int count)
{
for (; count > 0; count--, ptr++)
writel_relaxed(ptr->val, ptr->reg);
}
