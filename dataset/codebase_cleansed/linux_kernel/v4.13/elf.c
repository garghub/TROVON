int elf_check_arch(const struct elf32_hdr *x)
{
if (x->e_machine != EM_UNICORE)
return 0;
if (x->e_entry & 3)
return 0;
return 1;
}
void elf_set_personality(const struct elf32_hdr *x)
{
unsigned int personality = PER_LINUX;
set_personality(personality);
}
