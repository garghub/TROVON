int patch_instruction(unsigned int *addr, unsigned int instr)
{
int err;
__put_user_size(instr, addr, 4, err);
if (err)
return err;
asm ("dcbst 0, %0; sync; icbi 0,%0; sync; isync" : : "r" (addr));
return 0;
}
int patch_branch(unsigned int *addr, unsigned long target, int flags)
{
return patch_instruction(addr, create_branch(addr, target, flags));
}
unsigned int create_branch(const unsigned int *addr,
unsigned long target, int flags)
{
unsigned int instruction;
long offset;
offset = target;
if (! (flags & BRANCH_ABSOLUTE))
offset = offset - (unsigned long)addr;
if (offset < -0x2000000 || offset > 0x1fffffc || offset & 0x3)
return 0;
instruction = 0x48000000 | (flags & 0x3) | (offset & 0x03FFFFFC);
return instruction;
}
unsigned int create_cond_branch(const unsigned int *addr,
unsigned long target, int flags)
{
unsigned int instruction;
long offset;
offset = target;
if (! (flags & BRANCH_ABSOLUTE))
offset = offset - (unsigned long)addr;
if (offset < -0x8000 || offset > 0x7FFF || offset & 0x3)
return 0;
instruction = 0x40000000 | (flags & 0x3FF0003) | (offset & 0xFFFC);
return instruction;
}
static unsigned int branch_opcode(unsigned int instr)
{
return (instr >> 26) & 0x3F;
}
static int instr_is_branch_iform(unsigned int instr)
{
return branch_opcode(instr) == 18;
}
static int instr_is_branch_bform(unsigned int instr)
{
return branch_opcode(instr) == 16;
}
int instr_is_relative_branch(unsigned int instr)
{
if (instr & BRANCH_ABSOLUTE)
return 0;
return instr_is_branch_iform(instr) || instr_is_branch_bform(instr);
}
static unsigned long branch_iform_target(const unsigned int *instr)
{
signed long imm;
imm = *instr & 0x3FFFFFC;
if (imm & 0x2000000)
imm -= 0x4000000;
if ((*instr & BRANCH_ABSOLUTE) == 0)
imm += (unsigned long)instr;
return (unsigned long)imm;
}
static unsigned long branch_bform_target(const unsigned int *instr)
{
signed long imm;
imm = *instr & 0xFFFC;
if (imm & 0x8000)
imm -= 0x10000;
if ((*instr & BRANCH_ABSOLUTE) == 0)
imm += (unsigned long)instr;
return (unsigned long)imm;
}
unsigned long branch_target(const unsigned int *instr)
{
if (instr_is_branch_iform(*instr))
return branch_iform_target(instr);
else if (instr_is_branch_bform(*instr))
return branch_bform_target(instr);
return 0;
}
int instr_is_branch_to_addr(const unsigned int *instr, unsigned long addr)
{
if (instr_is_branch_iform(*instr) || instr_is_branch_bform(*instr))
return branch_target(instr) == addr;
return 0;
}
unsigned int translate_branch(const unsigned int *dest, const unsigned int *src)
{
unsigned long target;
target = branch_target(src);
if (instr_is_branch_iform(*src))
return create_branch(dest, target, *src);
else if (instr_is_branch_bform(*src))
return create_cond_branch(dest, target, *src);
return 0;
}
void __patch_exception(int exc, unsigned long addr)
{
extern unsigned int interrupt_base_book3e;
unsigned int *ibase = &interrupt_base_book3e;
patch_branch(ibase + (exc / 4) + 1, addr, 0);
}
static void __init test_trampoline(void)
{
asm ("nop;\n");
}
static void __init test_branch_iform(void)
{
unsigned int instr;
unsigned long addr;
addr = (unsigned long)&instr;
check(instr_is_branch_iform(0x48000000));
check(instr_is_branch_iform(0x4bffffff));
check(!instr_is_branch_iform(0xcbffffff));
check(!instr_is_branch_iform(0x7bffffff));
check(instr_is_branch_iform(0x48000001));
check(instr_is_branch_iform(0x4bfffffd));
check(instr_is_branch_iform(0x4bff00fd));
check(!instr_is_branch_iform(0x7bfffffd));
instr = 0x48000103;
check(instr_is_branch_to_addr(&instr, 0x100));
instr = 0x480420ff;
check(instr_is_branch_to_addr(&instr, 0x420fc));
instr = 0x49fffffc;
check(instr_is_branch_to_addr(&instr, addr + 0x1FFFFFC));
instr = 0x4bfffffc;
check(instr_is_branch_to_addr(&instr, addr - 4));
instr = 0x4a000000;
check(instr_is_branch_to_addr(&instr, addr - 0x2000000));
instr = create_branch(&instr, addr, BRANCH_SET_LINK);
check(instr_is_branch_to_addr(&instr, addr));
instr = create_branch(&instr, addr - 0x100, BRANCH_SET_LINK);
check(instr_is_branch_to_addr(&instr, addr - 0x100));
instr = create_branch(&instr, addr + 0x100, 0);
check(instr_is_branch_to_addr(&instr, addr + 0x100));
instr = create_branch(&instr, addr - 0x2000000, BRANCH_SET_LINK);
check(instr_is_branch_to_addr(&instr, addr - 0x2000000));
instr = create_branch(&instr, addr - 0x2000004, BRANCH_SET_LINK);
check(instr == 0);
instr = create_branch(&instr, addr + 0x2000000, BRANCH_SET_LINK);
check(instr == 0);
instr = create_branch(&instr, addr + 3, BRANCH_SET_LINK);
check(instr == 0);
instr = create_branch(&instr, addr, 0xFFFFFFFC);
check(instr_is_branch_to_addr(&instr, addr));
check(instr == 0x48000000);
}
static void __init test_create_function_call(void)
{
unsigned int *iptr;
unsigned long dest;
iptr = (unsigned int *)ppc_function_entry(test_trampoline);
dest = ppc_function_entry(test_create_function_call);
patch_instruction(iptr, create_branch(iptr, dest, BRANCH_SET_LINK));
check(instr_is_branch_to_addr(iptr, dest));
}
static void __init test_branch_bform(void)
{
unsigned long addr;
unsigned int *iptr, instr, flags;
iptr = &instr;
addr = (unsigned long)iptr;
check(instr_is_branch_bform(0x40000000));
check(instr_is_branch_bform(0x43ffffff));
check(!instr_is_branch_bform(0xc3ffffff));
check(!instr_is_branch_bform(0x7bffffff));
instr = 0x43ff0103;
check(instr_is_branch_to_addr(&instr, 0x100));
instr = 0x43ff20ff;
check(instr_is_branch_to_addr(&instr, 0x20fc));
instr = 0x43ff7ffc;
check(instr_is_branch_to_addr(&instr, addr + 0x7FFC));
instr = 0x43fffffc;
check(instr_is_branch_to_addr(&instr, addr - 4));
instr = 0x43ff8000;
check(instr_is_branch_to_addr(&instr, addr - 0x8000));
flags = 0x3ff000 | BRANCH_SET_LINK;
instr = create_cond_branch(iptr, addr, flags);
check(instr_is_branch_to_addr(&instr, addr));
instr = create_cond_branch(iptr, addr - 0x100, flags);
check(instr_is_branch_to_addr(&instr, addr - 0x100));
instr = create_cond_branch(iptr, addr + 0x100, flags);
check(instr_is_branch_to_addr(&instr, addr + 0x100));
instr = create_cond_branch(iptr, addr - 0x8000, flags);
check(instr_is_branch_to_addr(&instr, addr - 0x8000));
instr = create_cond_branch(iptr, addr - 0x8004, flags);
check(instr == 0);
instr = create_cond_branch(iptr, addr + 0x8000, flags);
check(instr == 0);
instr = create_cond_branch(iptr, addr + 3, flags);
check(instr == 0);
instr = create_cond_branch(iptr, addr, 0xFFFFFFFC);
check(instr_is_branch_to_addr(&instr, addr));
check(instr == 0x43FF0000);
}
static void __init test_translate_branch(void)
{
unsigned long addr;
unsigned int *p, *q;
void *buf;
buf = vmalloc(PAGE_ALIGN(0x2000000 + 1));
check(buf);
if (!buf)
return;
p = buf;
addr = (unsigned long)p;
patch_branch(p, addr, 0);
check(instr_is_branch_to_addr(p, addr));
q = p + 1;
patch_instruction(q, translate_branch(q, p));
check(instr_is_branch_to_addr(q, addr));
p = buf;
addr = (unsigned long)p;
patch_branch(p, addr, 0);
q = buf + 0x2000000;
patch_instruction(q, translate_branch(q, p));
check(instr_is_branch_to_addr(p, addr));
check(instr_is_branch_to_addr(q, addr));
check(*q == 0x4a000000);
p = buf + 0x2000000;
addr = (unsigned long)p;
patch_branch(p, addr, 0);
q = buf + 4;
patch_instruction(q, translate_branch(q, p));
check(instr_is_branch_to_addr(p, addr));
check(instr_is_branch_to_addr(q, addr));
check(*q == 0x49fffffc);
p = buf;
addr = 0x1000000 + (unsigned long)buf;
patch_branch(p, addr, BRANCH_SET_LINK);
q = buf + 0x1400000;
patch_instruction(q, translate_branch(q, p));
check(instr_is_branch_to_addr(p, addr));
check(instr_is_branch_to_addr(q, addr));
p = buf + 0x1000000;
addr = 0x2000000 + (unsigned long)buf;
patch_branch(p, addr, 0);
q = buf + 4;
patch_instruction(q, translate_branch(q, p));
check(instr_is_branch_to_addr(p, addr));
check(instr_is_branch_to_addr(q, addr));
p = buf;
addr = (unsigned long)p;
patch_instruction(p, create_cond_branch(p, addr, 0));
check(instr_is_branch_to_addr(p, addr));
q = p + 1;
patch_instruction(q, translate_branch(q, p));
check(instr_is_branch_to_addr(q, addr));
p = buf;
addr = (unsigned long)p;
patch_instruction(p, create_cond_branch(p, addr, 0xFFFFFFFC));
q = buf + 0x8000;
patch_instruction(q, translate_branch(q, p));
check(instr_is_branch_to_addr(p, addr));
check(instr_is_branch_to_addr(q, addr));
check(*q == 0x43ff8000);
p = buf + 0x8000;
addr = (unsigned long)p;
patch_instruction(p, create_cond_branch(p, addr, 0xFFFFFFFC));
q = buf + 4;
patch_instruction(q, translate_branch(q, p));
check(instr_is_branch_to_addr(p, addr));
check(instr_is_branch_to_addr(q, addr));
check(*q == 0x43ff7ffc);
p = buf;
addr = 0x3000 + (unsigned long)buf;
patch_instruction(p, create_cond_branch(p, addr, BRANCH_SET_LINK));
q = buf + 0x5000;
patch_instruction(q, translate_branch(q, p));
check(instr_is_branch_to_addr(p, addr));
check(instr_is_branch_to_addr(q, addr));
p = buf + 0x2000;
addr = 0x4000 + (unsigned long)buf;
patch_instruction(p, create_cond_branch(p, addr, 0));
q = buf + 4;
patch_instruction(q, translate_branch(q, p));
check(instr_is_branch_to_addr(p, addr));
check(instr_is_branch_to_addr(q, addr));
vfree(buf);
}
static int __init test_code_patching(void)
{
printk(KERN_DEBUG "Running code patching self-tests ...\n");
test_branch_iform();
test_branch_bform();
test_create_function_call();
test_translate_branch();
return 0;
}
