static const struct exception_table_entry *check_exception_ranges(unsigned long addr)
{
if ((addr >= (unsigned long)&copy_user_memcpy) &&
(addr <= (unsigned long)&copy_user_memcpy_end))
return &__copy_user_fixup_ex;
return NULL;
}
static int cmp_ex_search(const void *key, const void *elt)
{
const struct exception_table_entry *_elt = elt;
unsigned long _key = *(unsigned long *)key;
if (_key > _elt->insn)
return 1;
if (_key < _elt->insn)
return -1;
return 0;
}
const struct exception_table_entry *
search_extable(const struct exception_table_entry *base,
const size_t num,
unsigned long value)
{
const struct exception_table_entry *mid;
mid = check_exception_ranges(value);
if (mid)
return mid;
return bsearch(&value, base, num,
sizeof(struct exception_table_entry), cmp_ex_search);
}
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
