void arch_jump_label_transform(struct jump_entry *entry,
enum jump_label_type type)
{
u32 *addr = (u32 *)(unsigned long)entry->code;
if (type == JUMP_LABEL_JMP)
patch_branch(addr, entry->target, 0);
else
patch_instruction(addr, PPC_INST_NOP);
}
