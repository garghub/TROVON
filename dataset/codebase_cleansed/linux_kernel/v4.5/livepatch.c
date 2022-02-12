int klp_write_module_reloc(struct module *mod, unsigned long type,
unsigned long loc, unsigned long value)
{
size_t size = 4;
unsigned long val;
unsigned long core = (unsigned long)mod->core_layout.base;
unsigned long core_size = mod->core_layout.size;
switch (type) {
case R_X86_64_NONE:
return 0;
case R_X86_64_64:
val = value;
size = 8;
break;
case R_X86_64_32:
val = (u32)value;
break;
case R_X86_64_32S:
val = (s32)value;
break;
case R_X86_64_PC32:
val = (u32)(value - loc);
break;
default:
return -EINVAL;
}
if (loc < core || loc >= core + core_size)
return -EINVAL;
return probe_kernel_write((void *)loc, &val, size);
}
