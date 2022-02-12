int fixup_exception(struct pt_regs *regs)
{
const struct exception_table_entry *fixup;
fixup = search_exception_tables(exception_epc(regs));
if (fixup) {
regs->cp0_epc = fixup->nextinsn;
return 1;
}
return 0;
}
