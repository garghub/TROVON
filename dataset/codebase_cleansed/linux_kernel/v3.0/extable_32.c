int fixup_exception(struct pt_regs *regs)
{
const struct exception_table_entry *fixup;
fixup = search_exception_tables(regs->pc);
if (fixup) {
regs->pc = fixup->fixup;
return 1;
}
return 0;
}
