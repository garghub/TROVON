int klp_write_module_reloc(struct module *mod, unsigned long type,
unsigned long loc, unsigned long value)
{
int ret, numpages, size = 4;
bool readonly;
unsigned long val;
unsigned long core = (unsigned long)mod->module_core;
unsigned long core_ro_size = mod->core_ro_size;
unsigned long core_size = mod->core_size;
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
if (loc < core + core_ro_size)
readonly = true;
else
readonly = false;
numpages = ((loc & PAGE_MASK) == ((loc + size) & PAGE_MASK)) ? 1 : 2;
if (readonly)
set_memory_rw(loc & PAGE_MASK, numpages);
ret = probe_kernel_write((void *)loc, &val, size);
if (readonly)
set_memory_ro(loc & PAGE_MASK, numpages);
return ret;
}
