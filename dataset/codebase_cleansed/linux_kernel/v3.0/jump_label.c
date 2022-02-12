static int __arch_jump_label_transform(void *data)
{
struct insn_args *args = data;
int rc;
rc = probe_kernel_write(args->target, args->insn, args->size);
WARN_ON_ONCE(rc < 0);
return 0;
}
void arch_jump_label_transform(struct jump_entry *entry,
enum jump_label_type type)
{
struct insn_args args;
struct insn insn;
if (type == JUMP_LABEL_ENABLE) {
insn.opcode = 0xc0f4;
insn.offset = (entry->target - entry->code) >> 1;
} else {
insn.opcode = 0xc004;
insn.offset = 0;
}
args.target = (void *) entry->code;
args.insn = &insn;
args.size = JUMP_LABEL_NOP_SIZE;
stop_machine(__arch_jump_label_transform, &args, NULL);
}
