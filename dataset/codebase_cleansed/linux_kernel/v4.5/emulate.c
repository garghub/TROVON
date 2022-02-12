static ulong reg_read(struct x86_emulate_ctxt *ctxt, unsigned nr)
{
if (!(ctxt->regs_valid & (1 << nr))) {
ctxt->regs_valid |= 1 << nr;
ctxt->_regs[nr] = ctxt->ops->read_gpr(ctxt, nr);
}
return ctxt->_regs[nr];
}
static ulong *reg_write(struct x86_emulate_ctxt *ctxt, unsigned nr)
{
ctxt->regs_valid |= 1 << nr;
ctxt->regs_dirty |= 1 << nr;
return &ctxt->_regs[nr];
}
static ulong *reg_rmw(struct x86_emulate_ctxt *ctxt, unsigned nr)
{
reg_read(ctxt, nr);
return reg_write(ctxt, nr);
}
static void writeback_registers(struct x86_emulate_ctxt *ctxt)
{
unsigned reg;
for_each_set_bit(reg, (ulong *)&ctxt->regs_dirty, 16)
ctxt->ops->write_gpr(ctxt, reg, ctxt->_regs[reg]);
}
static void invalidate_registers(struct x86_emulate_ctxt *ctxt)
{
ctxt->regs_dirty = 0;
ctxt->regs_valid = 0;
}
static int emulator_check_intercept(struct x86_emulate_ctxt *ctxt,
enum x86_intercept intercept,
enum x86_intercept_stage stage)
{
struct x86_instruction_info info = {
.intercept = intercept,
.rep_prefix = ctxt->rep_prefix,
.modrm_mod = ctxt->modrm_mod,
.modrm_reg = ctxt->modrm_reg,
.modrm_rm = ctxt->modrm_rm,
.src_val = ctxt->src.val64,
.dst_val = ctxt->dst.val64,
.src_bytes = ctxt->src.bytes,
.dst_bytes = ctxt->dst.bytes,
.ad_bytes = ctxt->ad_bytes,
.next_rip = ctxt->eip,
};
return ctxt->ops->intercept(ctxt, &info, stage);
}
static void assign_masked(ulong *dest, ulong src, ulong mask)
{
*dest = (*dest & ~mask) | (src & mask);
}
static void assign_register(unsigned long *reg, u64 val, int bytes)
{
switch (bytes) {
case 1:
*(u8 *)reg = (u8)val;
break;
case 2:
*(u16 *)reg = (u16)val;
break;
case 4:
*reg = (u32)val;
break;
case 8:
*reg = val;
break;
}
}
static inline unsigned long ad_mask(struct x86_emulate_ctxt *ctxt)
{
return (1UL << (ctxt->ad_bytes << 3)) - 1;
}
static ulong stack_mask(struct x86_emulate_ctxt *ctxt)
{
u16 sel;
struct desc_struct ss;
if (ctxt->mode == X86EMUL_MODE_PROT64)
return ~0UL;
ctxt->ops->get_segment(ctxt, &sel, &ss, NULL, VCPU_SREG_SS);
return ~0U >> ((ss.d ^ 1) * 16);
}
static int stack_size(struct x86_emulate_ctxt *ctxt)
{
return (__fls(stack_mask(ctxt)) + 1) >> 3;
}
static inline unsigned long
address_mask(struct x86_emulate_ctxt *ctxt, unsigned long reg)
{
if (ctxt->ad_bytes == sizeof(unsigned long))
return reg;
else
return reg & ad_mask(ctxt);
}
static inline unsigned long
register_address(struct x86_emulate_ctxt *ctxt, int reg)
{
return address_mask(ctxt, reg_read(ctxt, reg));
}
static void masked_increment(ulong *reg, ulong mask, int inc)
{
assign_masked(reg, *reg + inc, mask);
}
static inline void
register_address_increment(struct x86_emulate_ctxt *ctxt, int reg, int inc)
{
ulong *preg = reg_rmw(ctxt, reg);
assign_register(preg, *preg + inc, ctxt->ad_bytes);
}
static void rsp_increment(struct x86_emulate_ctxt *ctxt, int inc)
{
masked_increment(reg_rmw(ctxt, VCPU_REGS_RSP), stack_mask(ctxt), inc);
}
static u32 desc_limit_scaled(struct desc_struct *desc)
{
u32 limit = get_desc_limit(desc);
return desc->g ? (limit << 12) | 0xfff : limit;
}
static unsigned long seg_base(struct x86_emulate_ctxt *ctxt, int seg)
{
if (ctxt->mode == X86EMUL_MODE_PROT64 && seg < VCPU_SREG_FS)
return 0;
return ctxt->ops->get_cached_segment_base(ctxt, seg);
}
static int emulate_exception(struct x86_emulate_ctxt *ctxt, int vec,
u32 error, bool valid)
{
WARN_ON(vec > 0x1f);
ctxt->exception.vector = vec;
ctxt->exception.error_code = error;
ctxt->exception.error_code_valid = valid;
return X86EMUL_PROPAGATE_FAULT;
}
static int emulate_db(struct x86_emulate_ctxt *ctxt)
{
return emulate_exception(ctxt, DB_VECTOR, 0, false);
}
static int emulate_gp(struct x86_emulate_ctxt *ctxt, int err)
{
return emulate_exception(ctxt, GP_VECTOR, err, true);
}
static int emulate_ss(struct x86_emulate_ctxt *ctxt, int err)
{
return emulate_exception(ctxt, SS_VECTOR, err, true);
}
static int emulate_ud(struct x86_emulate_ctxt *ctxt)
{
return emulate_exception(ctxt, UD_VECTOR, 0, false);
}
static int emulate_ts(struct x86_emulate_ctxt *ctxt, int err)
{
return emulate_exception(ctxt, TS_VECTOR, err, true);
}
static int emulate_de(struct x86_emulate_ctxt *ctxt)
{
return emulate_exception(ctxt, DE_VECTOR, 0, false);
}
static int emulate_nm(struct x86_emulate_ctxt *ctxt)
{
return emulate_exception(ctxt, NM_VECTOR, 0, false);
}
static u16 get_segment_selector(struct x86_emulate_ctxt *ctxt, unsigned seg)
{
u16 selector;
struct desc_struct desc;
ctxt->ops->get_segment(ctxt, &selector, &desc, NULL, seg);
return selector;
}
static void set_segment_selector(struct x86_emulate_ctxt *ctxt, u16 selector,
unsigned seg)
{
u16 dummy;
u32 base3;
struct desc_struct desc;
ctxt->ops->get_segment(ctxt, &dummy, &desc, &base3, seg);
ctxt->ops->set_segment(ctxt, selector, &desc, base3, seg);
}
static bool insn_aligned(struct x86_emulate_ctxt *ctxt, unsigned size)
{
if (likely(size < 16))
return false;
if (ctxt->d & Aligned)
return true;
else if (ctxt->d & Unaligned)
return false;
else if (ctxt->d & Avx)
return false;
else
return true;
}
static __always_inline int __linearize(struct x86_emulate_ctxt *ctxt,
struct segmented_address addr,
unsigned *max_size, unsigned size,
bool write, bool fetch,
enum x86emul_mode mode, ulong *linear)
{
struct desc_struct desc;
bool usable;
ulong la;
u32 lim;
u16 sel;
la = seg_base(ctxt, addr.seg) + addr.ea;
*max_size = 0;
switch (mode) {
case X86EMUL_MODE_PROT64:
*linear = la;
if (is_noncanonical_address(la))
goto bad;
*max_size = min_t(u64, ~0u, (1ull << 48) - la);
if (size > *max_size)
goto bad;
break;
default:
*linear = la = (u32)la;
usable = ctxt->ops->get_segment(ctxt, &sel, &desc, NULL,
addr.seg);
if (!usable)
goto bad;
if ((((ctxt->mode != X86EMUL_MODE_REAL) && (desc.type & 8))
|| !(desc.type & 2)) && write)
goto bad;
if (!fetch && (desc.type & 8) && !(desc.type & 2))
goto bad;
lim = desc_limit_scaled(&desc);
if (!(desc.type & 8) && (desc.type & 4)) {
if (addr.ea <= lim)
goto bad;
lim = desc.d ? 0xffffffff : 0xffff;
}
if (addr.ea > lim)
goto bad;
if (lim == 0xffffffff)
*max_size = ~0u;
else {
*max_size = (u64)lim + 1 - addr.ea;
if (size > *max_size)
goto bad;
}
break;
}
if (insn_aligned(ctxt, size) && ((la & (size - 1)) != 0))
return emulate_gp(ctxt, 0);
return X86EMUL_CONTINUE;
bad:
if (addr.seg == VCPU_SREG_SS)
return emulate_ss(ctxt, 0);
else
return emulate_gp(ctxt, 0);
}
static int linearize(struct x86_emulate_ctxt *ctxt,
struct segmented_address addr,
unsigned size, bool write,
ulong *linear)
{
unsigned max_size;
return __linearize(ctxt, addr, &max_size, size, write, false,
ctxt->mode, linear);
}
static inline int assign_eip(struct x86_emulate_ctxt *ctxt, ulong dst,
enum x86emul_mode mode)
{
ulong linear;
int rc;
unsigned max_size;
struct segmented_address addr = { .seg = VCPU_SREG_CS,
.ea = dst };
if (ctxt->op_bytes != sizeof(unsigned long))
addr.ea = dst & ((1UL << (ctxt->op_bytes << 3)) - 1);
rc = __linearize(ctxt, addr, &max_size, 1, false, true, mode, &linear);
if (rc == X86EMUL_CONTINUE)
ctxt->_eip = addr.ea;
return rc;
}
static inline int assign_eip_near(struct x86_emulate_ctxt *ctxt, ulong dst)
{
return assign_eip(ctxt, dst, ctxt->mode);
}
static int assign_eip_far(struct x86_emulate_ctxt *ctxt, ulong dst,
const struct desc_struct *cs_desc)
{
enum x86emul_mode mode = ctxt->mode;
int rc;
#ifdef CONFIG_X86_64
if (ctxt->mode >= X86EMUL_MODE_PROT16) {
if (cs_desc->l) {
u64 efer = 0;
ctxt->ops->get_msr(ctxt, MSR_EFER, &efer);
if (efer & EFER_LMA)
mode = X86EMUL_MODE_PROT64;
} else
mode = X86EMUL_MODE_PROT32;
}
#endif
if (mode == X86EMUL_MODE_PROT16 || mode == X86EMUL_MODE_PROT32)
mode = cs_desc->d ? X86EMUL_MODE_PROT32 : X86EMUL_MODE_PROT16;
rc = assign_eip(ctxt, dst, mode);
if (rc == X86EMUL_CONTINUE)
ctxt->mode = mode;
return rc;
}
static inline int jmp_rel(struct x86_emulate_ctxt *ctxt, int rel)
{
return assign_eip_near(ctxt, ctxt->_eip + rel);
}
static int segmented_read_std(struct x86_emulate_ctxt *ctxt,
struct segmented_address addr,
void *data,
unsigned size)
{
int rc;
ulong linear;
rc = linearize(ctxt, addr, size, false, &linear);
if (rc != X86EMUL_CONTINUE)
return rc;
return ctxt->ops->read_std(ctxt, linear, data, size, &ctxt->exception);
}
static int __do_insn_fetch_bytes(struct x86_emulate_ctxt *ctxt, int op_size)
{
int rc;
unsigned size, max_size;
unsigned long linear;
int cur_size = ctxt->fetch.end - ctxt->fetch.data;
struct segmented_address addr = { .seg = VCPU_SREG_CS,
.ea = ctxt->eip + cur_size };
rc = __linearize(ctxt, addr, &max_size, 0, false, true, ctxt->mode,
&linear);
if (unlikely(rc != X86EMUL_CONTINUE))
return rc;
size = min_t(unsigned, 15UL ^ cur_size, max_size);
size = min_t(unsigned, size, PAGE_SIZE - offset_in_page(linear));
if (unlikely(size < op_size))
return emulate_gp(ctxt, 0);
rc = ctxt->ops->fetch(ctxt, linear, ctxt->fetch.end,
size, &ctxt->exception);
if (unlikely(rc != X86EMUL_CONTINUE))
return rc;
ctxt->fetch.end += size;
return X86EMUL_CONTINUE;
}
static __always_inline int do_insn_fetch_bytes(struct x86_emulate_ctxt *ctxt,
unsigned size)
{
unsigned done_size = ctxt->fetch.end - ctxt->fetch.ptr;
if (unlikely(done_size < size))
return __do_insn_fetch_bytes(ctxt, size - done_size);
else
return X86EMUL_CONTINUE;
}
static void *decode_register(struct x86_emulate_ctxt *ctxt, u8 modrm_reg,
int byteop)
{
void *p;
int highbyte_regs = (ctxt->rex_prefix == 0) && byteop;
if (highbyte_regs && modrm_reg >= 4 && modrm_reg < 8)
p = (unsigned char *)reg_rmw(ctxt, modrm_reg & 3) + 1;
else
p = reg_rmw(ctxt, modrm_reg);
return p;
}
static int read_descriptor(struct x86_emulate_ctxt *ctxt,
struct segmented_address addr,
u16 *size, unsigned long *address, int op_bytes)
{
int rc;
if (op_bytes == 2)
op_bytes = 3;
*address = 0;
rc = segmented_read_std(ctxt, addr, size, 2);
if (rc != X86EMUL_CONTINUE)
return rc;
addr.ea += 2;
rc = segmented_read_std(ctxt, addr, address, op_bytes);
return rc;
}
static int em_bsf_c(struct x86_emulate_ctxt *ctxt)
{
if (ctxt->src.val == 0)
ctxt->dst.type = OP_NONE;
return fastop(ctxt, em_bsf);
}
static int em_bsr_c(struct x86_emulate_ctxt *ctxt)
{
if (ctxt->src.val == 0)
ctxt->dst.type = OP_NONE;
return fastop(ctxt, em_bsr);
}
static u8 test_cc(unsigned int condition, unsigned long flags)
{
u8 rc;
void (*fop)(void) = (void *)em_setcc + 4 * (condition & 0xf);
flags = (flags & EFLAGS_MASK) | X86_EFLAGS_IF;
asm("push %[flags]; popf; call *%[fastop]"
: "=a"(rc) : [fastop]"r"(fop), [flags]"r"(flags));
return rc;
}
static void fetch_register_operand(struct operand *op)
{
switch (op->bytes) {
case 1:
op->val = *(u8 *)op->addr.reg;
break;
case 2:
op->val = *(u16 *)op->addr.reg;
break;
case 4:
op->val = *(u32 *)op->addr.reg;
break;
case 8:
op->val = *(u64 *)op->addr.reg;
break;
}
}
static void read_sse_reg(struct x86_emulate_ctxt *ctxt, sse128_t *data, int reg)
{
ctxt->ops->get_fpu(ctxt);
switch (reg) {
case 0: asm("movdqa %%xmm0, %0" : "=m"(*data)); break;
case 1: asm("movdqa %%xmm1, %0" : "=m"(*data)); break;
case 2: asm("movdqa %%xmm2, %0" : "=m"(*data)); break;
case 3: asm("movdqa %%xmm3, %0" : "=m"(*data)); break;
case 4: asm("movdqa %%xmm4, %0" : "=m"(*data)); break;
case 5: asm("movdqa %%xmm5, %0" : "=m"(*data)); break;
case 6: asm("movdqa %%xmm6, %0" : "=m"(*data)); break;
case 7: asm("movdqa %%xmm7, %0" : "=m"(*data)); break;
#ifdef CONFIG_X86_64
case 8: asm("movdqa %%xmm8, %0" : "=m"(*data)); break;
case 9: asm("movdqa %%xmm9, %0" : "=m"(*data)); break;
case 10: asm("movdqa %%xmm10, %0" : "=m"(*data)); break;
case 11: asm("movdqa %%xmm11, %0" : "=m"(*data)); break;
case 12: asm("movdqa %%xmm12, %0" : "=m"(*data)); break;
case 13: asm("movdqa %%xmm13, %0" : "=m"(*data)); break;
case 14: asm("movdqa %%xmm14, %0" : "=m"(*data)); break;
case 15: asm("movdqa %%xmm15, %0" : "=m"(*data)); break;
#endif
default: BUG();
}
ctxt->ops->put_fpu(ctxt);
}
static void write_sse_reg(struct x86_emulate_ctxt *ctxt, sse128_t *data,
int reg)
{
ctxt->ops->get_fpu(ctxt);
switch (reg) {
case 0: asm("movdqa %0, %%xmm0" : : "m"(*data)); break;
case 1: asm("movdqa %0, %%xmm1" : : "m"(*data)); break;
case 2: asm("movdqa %0, %%xmm2" : : "m"(*data)); break;
case 3: asm("movdqa %0, %%xmm3" : : "m"(*data)); break;
case 4: asm("movdqa %0, %%xmm4" : : "m"(*data)); break;
case 5: asm("movdqa %0, %%xmm5" : : "m"(*data)); break;
case 6: asm("movdqa %0, %%xmm6" : : "m"(*data)); break;
case 7: asm("movdqa %0, %%xmm7" : : "m"(*data)); break;
#ifdef CONFIG_X86_64
case 8: asm("movdqa %0, %%xmm8" : : "m"(*data)); break;
case 9: asm("movdqa %0, %%xmm9" : : "m"(*data)); break;
case 10: asm("movdqa %0, %%xmm10" : : "m"(*data)); break;
case 11: asm("movdqa %0, %%xmm11" : : "m"(*data)); break;
case 12: asm("movdqa %0, %%xmm12" : : "m"(*data)); break;
case 13: asm("movdqa %0, %%xmm13" : : "m"(*data)); break;
case 14: asm("movdqa %0, %%xmm14" : : "m"(*data)); break;
case 15: asm("movdqa %0, %%xmm15" : : "m"(*data)); break;
#endif
default: BUG();
}
ctxt->ops->put_fpu(ctxt);
}
static void read_mmx_reg(struct x86_emulate_ctxt *ctxt, u64 *data, int reg)
{
ctxt->ops->get_fpu(ctxt);
switch (reg) {
case 0: asm("movq %%mm0, %0" : "=m"(*data)); break;
case 1: asm("movq %%mm1, %0" : "=m"(*data)); break;
case 2: asm("movq %%mm2, %0" : "=m"(*data)); break;
case 3: asm("movq %%mm3, %0" : "=m"(*data)); break;
case 4: asm("movq %%mm4, %0" : "=m"(*data)); break;
case 5: asm("movq %%mm5, %0" : "=m"(*data)); break;
case 6: asm("movq %%mm6, %0" : "=m"(*data)); break;
case 7: asm("movq %%mm7, %0" : "=m"(*data)); break;
default: BUG();
}
ctxt->ops->put_fpu(ctxt);
}
static void write_mmx_reg(struct x86_emulate_ctxt *ctxt, u64 *data, int reg)
{
ctxt->ops->get_fpu(ctxt);
switch (reg) {
case 0: asm("movq %0, %%mm0" : : "m"(*data)); break;
case 1: asm("movq %0, %%mm1" : : "m"(*data)); break;
case 2: asm("movq %0, %%mm2" : : "m"(*data)); break;
case 3: asm("movq %0, %%mm3" : : "m"(*data)); break;
case 4: asm("movq %0, %%mm4" : : "m"(*data)); break;
case 5: asm("movq %0, %%mm5" : : "m"(*data)); break;
case 6: asm("movq %0, %%mm6" : : "m"(*data)); break;
case 7: asm("movq %0, %%mm7" : : "m"(*data)); break;
default: BUG();
}
ctxt->ops->put_fpu(ctxt);
}
static int em_fninit(struct x86_emulate_ctxt *ctxt)
{
if (ctxt->ops->get_cr(ctxt, 0) & (X86_CR0_TS | X86_CR0_EM))
return emulate_nm(ctxt);
ctxt->ops->get_fpu(ctxt);
asm volatile("fninit");
ctxt->ops->put_fpu(ctxt);
return X86EMUL_CONTINUE;
}
static int em_fnstcw(struct x86_emulate_ctxt *ctxt)
{
u16 fcw;
if (ctxt->ops->get_cr(ctxt, 0) & (X86_CR0_TS | X86_CR0_EM))
return emulate_nm(ctxt);
ctxt->ops->get_fpu(ctxt);
asm volatile("fnstcw %0": "+m"(fcw));
ctxt->ops->put_fpu(ctxt);
ctxt->dst.val = fcw;
return X86EMUL_CONTINUE;
}
static int em_fnstsw(struct x86_emulate_ctxt *ctxt)
{
u16 fsw;
if (ctxt->ops->get_cr(ctxt, 0) & (X86_CR0_TS | X86_CR0_EM))
return emulate_nm(ctxt);
ctxt->ops->get_fpu(ctxt);
asm volatile("fnstsw %0": "+m"(fsw));
ctxt->ops->put_fpu(ctxt);
ctxt->dst.val = fsw;
return X86EMUL_CONTINUE;
}
static void decode_register_operand(struct x86_emulate_ctxt *ctxt,
struct operand *op)
{
unsigned reg = ctxt->modrm_reg;
if (!(ctxt->d & ModRM))
reg = (ctxt->b & 7) | ((ctxt->rex_prefix & 1) << 3);
if (ctxt->d & Sse) {
op->type = OP_XMM;
op->bytes = 16;
op->addr.xmm = reg;
read_sse_reg(ctxt, &op->vec_val, reg);
return;
}
if (ctxt->d & Mmx) {
reg &= 7;
op->type = OP_MM;
op->bytes = 8;
op->addr.mm = reg;
return;
}
op->type = OP_REG;
op->bytes = (ctxt->d & ByteOp) ? 1 : ctxt->op_bytes;
op->addr.reg = decode_register(ctxt, reg, ctxt->d & ByteOp);
fetch_register_operand(op);
op->orig_val = op->val;
}
static void adjust_modrm_seg(struct x86_emulate_ctxt *ctxt, int base_reg)
{
if (base_reg == VCPU_REGS_RSP || base_reg == VCPU_REGS_RBP)
ctxt->modrm_seg = VCPU_SREG_SS;
}
static int decode_modrm(struct x86_emulate_ctxt *ctxt,
struct operand *op)
{
u8 sib;
int index_reg, base_reg, scale;
int rc = X86EMUL_CONTINUE;
ulong modrm_ea = 0;
ctxt->modrm_reg = ((ctxt->rex_prefix << 1) & 8);
index_reg = (ctxt->rex_prefix << 2) & 8;
base_reg = (ctxt->rex_prefix << 3) & 8;
ctxt->modrm_mod = (ctxt->modrm & 0xc0) >> 6;
ctxt->modrm_reg |= (ctxt->modrm & 0x38) >> 3;
ctxt->modrm_rm = base_reg | (ctxt->modrm & 0x07);
ctxt->modrm_seg = VCPU_SREG_DS;
if (ctxt->modrm_mod == 3 || (ctxt->d & NoMod)) {
op->type = OP_REG;
op->bytes = (ctxt->d & ByteOp) ? 1 : ctxt->op_bytes;
op->addr.reg = decode_register(ctxt, ctxt->modrm_rm,
ctxt->d & ByteOp);
if (ctxt->d & Sse) {
op->type = OP_XMM;
op->bytes = 16;
op->addr.xmm = ctxt->modrm_rm;
read_sse_reg(ctxt, &op->vec_val, ctxt->modrm_rm);
return rc;
}
if (ctxt->d & Mmx) {
op->type = OP_MM;
op->bytes = 8;
op->addr.mm = ctxt->modrm_rm & 7;
return rc;
}
fetch_register_operand(op);
return rc;
}
op->type = OP_MEM;
if (ctxt->ad_bytes == 2) {
unsigned bx = reg_read(ctxt, VCPU_REGS_RBX);
unsigned bp = reg_read(ctxt, VCPU_REGS_RBP);
unsigned si = reg_read(ctxt, VCPU_REGS_RSI);
unsigned di = reg_read(ctxt, VCPU_REGS_RDI);
switch (ctxt->modrm_mod) {
case 0:
if (ctxt->modrm_rm == 6)
modrm_ea += insn_fetch(u16, ctxt);
break;
case 1:
modrm_ea += insn_fetch(s8, ctxt);
break;
case 2:
modrm_ea += insn_fetch(u16, ctxt);
break;
}
switch (ctxt->modrm_rm) {
case 0:
modrm_ea += bx + si;
break;
case 1:
modrm_ea += bx + di;
break;
case 2:
modrm_ea += bp + si;
break;
case 3:
modrm_ea += bp + di;
break;
case 4:
modrm_ea += si;
break;
case 5:
modrm_ea += di;
break;
case 6:
if (ctxt->modrm_mod != 0)
modrm_ea += bp;
break;
case 7:
modrm_ea += bx;
break;
}
if (ctxt->modrm_rm == 2 || ctxt->modrm_rm == 3 ||
(ctxt->modrm_rm == 6 && ctxt->modrm_mod != 0))
ctxt->modrm_seg = VCPU_SREG_SS;
modrm_ea = (u16)modrm_ea;
} else {
if ((ctxt->modrm_rm & 7) == 4) {
sib = insn_fetch(u8, ctxt);
index_reg |= (sib >> 3) & 7;
base_reg |= sib & 7;
scale = sib >> 6;
if ((base_reg & 7) == 5 && ctxt->modrm_mod == 0)
modrm_ea += insn_fetch(s32, ctxt);
else {
modrm_ea += reg_read(ctxt, base_reg);
adjust_modrm_seg(ctxt, base_reg);
if ((ctxt->d & IncSP) &&
base_reg == VCPU_REGS_RSP)
modrm_ea += ctxt->op_bytes;
}
if (index_reg != 4)
modrm_ea += reg_read(ctxt, index_reg) << scale;
} else if ((ctxt->modrm_rm & 7) == 5 && ctxt->modrm_mod == 0) {
modrm_ea += insn_fetch(s32, ctxt);
if (ctxt->mode == X86EMUL_MODE_PROT64)
ctxt->rip_relative = 1;
} else {
base_reg = ctxt->modrm_rm;
modrm_ea += reg_read(ctxt, base_reg);
adjust_modrm_seg(ctxt, base_reg);
}
switch (ctxt->modrm_mod) {
case 1:
modrm_ea += insn_fetch(s8, ctxt);
break;
case 2:
modrm_ea += insn_fetch(s32, ctxt);
break;
}
}
op->addr.mem.ea = modrm_ea;
if (ctxt->ad_bytes != 8)
ctxt->memop.addr.mem.ea = (u32)ctxt->memop.addr.mem.ea;
done:
return rc;
}
static int decode_abs(struct x86_emulate_ctxt *ctxt,
struct operand *op)
{
int rc = X86EMUL_CONTINUE;
op->type = OP_MEM;
switch (ctxt->ad_bytes) {
case 2:
op->addr.mem.ea = insn_fetch(u16, ctxt);
break;
case 4:
op->addr.mem.ea = insn_fetch(u32, ctxt);
break;
case 8:
op->addr.mem.ea = insn_fetch(u64, ctxt);
break;
}
done:
return rc;
}
static void fetch_bit_operand(struct x86_emulate_ctxt *ctxt)
{
long sv = 0, mask;
if (ctxt->dst.type == OP_MEM && ctxt->src.type == OP_REG) {
mask = ~((long)ctxt->dst.bytes * 8 - 1);
if (ctxt->src.bytes == 2)
sv = (s16)ctxt->src.val & (s16)mask;
else if (ctxt->src.bytes == 4)
sv = (s32)ctxt->src.val & (s32)mask;
else
sv = (s64)ctxt->src.val & (s64)mask;
ctxt->dst.addr.mem.ea = address_mask(ctxt,
ctxt->dst.addr.mem.ea + (sv >> 3));
}
ctxt->src.val &= (ctxt->dst.bytes << 3) - 1;
}
static int read_emulated(struct x86_emulate_ctxt *ctxt,
unsigned long addr, void *dest, unsigned size)
{
int rc;
struct read_cache *mc = &ctxt->mem_read;
if (mc->pos < mc->end)
goto read_cached;
WARN_ON((mc->end + size) >= sizeof(mc->data));
rc = ctxt->ops->read_emulated(ctxt, addr, mc->data + mc->end, size,
&ctxt->exception);
if (rc != X86EMUL_CONTINUE)
return rc;
mc->end += size;
read_cached:
memcpy(dest, mc->data + mc->pos, size);
mc->pos += size;
return X86EMUL_CONTINUE;
}
static int segmented_read(struct x86_emulate_ctxt *ctxt,
struct segmented_address addr,
void *data,
unsigned size)
{
int rc;
ulong linear;
rc = linearize(ctxt, addr, size, false, &linear);
if (rc != X86EMUL_CONTINUE)
return rc;
return read_emulated(ctxt, linear, data, size);
}
static int segmented_write(struct x86_emulate_ctxt *ctxt,
struct segmented_address addr,
const void *data,
unsigned size)
{
int rc;
ulong linear;
rc = linearize(ctxt, addr, size, true, &linear);
if (rc != X86EMUL_CONTINUE)
return rc;
return ctxt->ops->write_emulated(ctxt, linear, data, size,
&ctxt->exception);
}
static int segmented_cmpxchg(struct x86_emulate_ctxt *ctxt,
struct segmented_address addr,
const void *orig_data, const void *data,
unsigned size)
{
int rc;
ulong linear;
rc = linearize(ctxt, addr, size, true, &linear);
if (rc != X86EMUL_CONTINUE)
return rc;
return ctxt->ops->cmpxchg_emulated(ctxt, linear, orig_data, data,
size, &ctxt->exception);
}
static int pio_in_emulated(struct x86_emulate_ctxt *ctxt,
unsigned int size, unsigned short port,
void *dest)
{
struct read_cache *rc = &ctxt->io_read;
if (rc->pos == rc->end) {
unsigned int in_page, n;
unsigned int count = ctxt->rep_prefix ?
address_mask(ctxt, reg_read(ctxt, VCPU_REGS_RCX)) : 1;
in_page = (ctxt->eflags & X86_EFLAGS_DF) ?
offset_in_page(reg_read(ctxt, VCPU_REGS_RDI)) :
PAGE_SIZE - offset_in_page(reg_read(ctxt, VCPU_REGS_RDI));
n = min3(in_page, (unsigned int)sizeof(rc->data) / size, count);
if (n == 0)
n = 1;
rc->pos = rc->end = 0;
if (!ctxt->ops->pio_in_emulated(ctxt, size, port, rc->data, n))
return 0;
rc->end = n * size;
}
if (ctxt->rep_prefix && (ctxt->d & String) &&
!(ctxt->eflags & X86_EFLAGS_DF)) {
ctxt->dst.data = rc->data + rc->pos;
ctxt->dst.type = OP_MEM_STR;
ctxt->dst.count = (rc->end - rc->pos) / size;
rc->pos = rc->end;
} else {
memcpy(dest, rc->data + rc->pos, size);
rc->pos += size;
}
return 1;
}
static int read_interrupt_descriptor(struct x86_emulate_ctxt *ctxt,
u16 index, struct desc_struct *desc)
{
struct desc_ptr dt;
ulong addr;
ctxt->ops->get_idt(ctxt, &dt);
if (dt.size < index * 8 + 7)
return emulate_gp(ctxt, index << 3 | 0x2);
addr = dt.address + index * 8;
return ctxt->ops->read_std(ctxt, addr, desc, sizeof *desc,
&ctxt->exception);
}
static void get_descriptor_table_ptr(struct x86_emulate_ctxt *ctxt,
u16 selector, struct desc_ptr *dt)
{
const struct x86_emulate_ops *ops = ctxt->ops;
u32 base3 = 0;
if (selector & 1 << 2) {
struct desc_struct desc;
u16 sel;
memset (dt, 0, sizeof *dt);
if (!ops->get_segment(ctxt, &sel, &desc, &base3,
VCPU_SREG_LDTR))
return;
dt->size = desc_limit_scaled(&desc);
dt->address = get_desc_base(&desc) | ((u64)base3 << 32);
} else
ops->get_gdt(ctxt, dt);
}
static int get_descriptor_ptr(struct x86_emulate_ctxt *ctxt,
u16 selector, ulong *desc_addr_p)
{
struct desc_ptr dt;
u16 index = selector >> 3;
ulong addr;
get_descriptor_table_ptr(ctxt, selector, &dt);
if (dt.size < index * 8 + 7)
return emulate_gp(ctxt, selector & 0xfffc);
addr = dt.address + index * 8;
#ifdef CONFIG_X86_64
if (addr >> 32 != 0) {
u64 efer = 0;
ctxt->ops->get_msr(ctxt, MSR_EFER, &efer);
if (!(efer & EFER_LMA))
addr &= (u32)-1;
}
#endif
*desc_addr_p = addr;
return X86EMUL_CONTINUE;
}
static int read_segment_descriptor(struct x86_emulate_ctxt *ctxt,
u16 selector, struct desc_struct *desc,
ulong *desc_addr_p)
{
int rc;
rc = get_descriptor_ptr(ctxt, selector, desc_addr_p);
if (rc != X86EMUL_CONTINUE)
return rc;
return ctxt->ops->read_std(ctxt, *desc_addr_p, desc, sizeof(*desc),
&ctxt->exception);
}
static int write_segment_descriptor(struct x86_emulate_ctxt *ctxt,
u16 selector, struct desc_struct *desc)
{
int rc;
ulong addr;
rc = get_descriptor_ptr(ctxt, selector, &addr);
if (rc != X86EMUL_CONTINUE)
return rc;
return ctxt->ops->write_std(ctxt, addr, desc, sizeof *desc,
&ctxt->exception);
}
static int __load_segment_descriptor(struct x86_emulate_ctxt *ctxt,
u16 selector, int seg, u8 cpl,
enum x86_transfer_type transfer,
struct desc_struct *desc)
{
struct desc_struct seg_desc, old_desc;
u8 dpl, rpl;
unsigned err_vec = GP_VECTOR;
u32 err_code = 0;
bool null_selector = !(selector & ~0x3);
ulong desc_addr;
int ret;
u16 dummy;
u32 base3 = 0;
memset(&seg_desc, 0, sizeof seg_desc);
if (ctxt->mode == X86EMUL_MODE_REAL) {
ctxt->ops->get_segment(ctxt, &dummy, &seg_desc, NULL, seg);
set_desc_base(&seg_desc, selector << 4);
goto load;
} else if (seg <= VCPU_SREG_GS && ctxt->mode == X86EMUL_MODE_VM86) {
set_desc_base(&seg_desc, selector << 4);
set_desc_limit(&seg_desc, 0xffff);
seg_desc.type = 3;
seg_desc.p = 1;
seg_desc.s = 1;
seg_desc.dpl = 3;
goto load;
}
rpl = selector & 3;
if ((seg == VCPU_SREG_CS
|| (seg == VCPU_SREG_SS
&& (ctxt->mode != X86EMUL_MODE_PROT64 || rpl != cpl))
|| seg == VCPU_SREG_TR)
&& null_selector)
goto exception;
if (seg == VCPU_SREG_TR && (selector & (1 << 2)))
goto exception;
if (null_selector)
goto load;
ret = read_segment_descriptor(ctxt, selector, &seg_desc, &desc_addr);
if (ret != X86EMUL_CONTINUE)
return ret;
err_code = selector & 0xfffc;
err_vec = (transfer == X86_TRANSFER_TASK_SWITCH) ? TS_VECTOR :
GP_VECTOR;
if (seg <= VCPU_SREG_GS && !seg_desc.s) {
if (transfer == X86_TRANSFER_CALL_JMP)
return X86EMUL_UNHANDLEABLE;
goto exception;
}
if (!seg_desc.p) {
err_vec = (seg == VCPU_SREG_SS) ? SS_VECTOR : NP_VECTOR;
goto exception;
}
dpl = seg_desc.dpl;
switch (seg) {
case VCPU_SREG_SS:
if (rpl != cpl || (seg_desc.type & 0xa) != 0x2 || dpl != cpl)
goto exception;
break;
case VCPU_SREG_CS:
if (!(seg_desc.type & 8))
goto exception;
if (seg_desc.type & 4) {
if (dpl > cpl)
goto exception;
} else {
if (rpl > cpl || dpl != cpl)
goto exception;
}
if (seg_desc.d && seg_desc.l) {
u64 efer = 0;
ctxt->ops->get_msr(ctxt, MSR_EFER, &efer);
if (efer & EFER_LMA)
goto exception;
}
selector = (selector & 0xfffc) | cpl;
break;
case VCPU_SREG_TR:
if (seg_desc.s || (seg_desc.type != 1 && seg_desc.type != 9))
goto exception;
old_desc = seg_desc;
seg_desc.type |= 2;
ret = ctxt->ops->cmpxchg_emulated(ctxt, desc_addr, &old_desc, &seg_desc,
sizeof(seg_desc), &ctxt->exception);
if (ret != X86EMUL_CONTINUE)
return ret;
break;
case VCPU_SREG_LDTR:
if (seg_desc.s || seg_desc.type != 2)
goto exception;
break;
default:
if ((seg_desc.type & 0xa) == 0x8 ||
(((seg_desc.type & 0xc) != 0xc) &&
(rpl > dpl && cpl > dpl)))
goto exception;
break;
}
if (seg_desc.s) {
if (!(seg_desc.type & 1)) {
seg_desc.type |= 1;
ret = write_segment_descriptor(ctxt, selector,
&seg_desc);
if (ret != X86EMUL_CONTINUE)
return ret;
}
} else if (ctxt->mode == X86EMUL_MODE_PROT64) {
ret = ctxt->ops->read_std(ctxt, desc_addr+8, &base3,
sizeof(base3), &ctxt->exception);
if (ret != X86EMUL_CONTINUE)
return ret;
if (is_noncanonical_address(get_desc_base(&seg_desc) |
((u64)base3 << 32)))
return emulate_gp(ctxt, 0);
}
load:
ctxt->ops->set_segment(ctxt, selector, &seg_desc, base3, seg);
if (desc)
*desc = seg_desc;
return X86EMUL_CONTINUE;
exception:
return emulate_exception(ctxt, err_vec, err_code, true);
}
static int load_segment_descriptor(struct x86_emulate_ctxt *ctxt,
u16 selector, int seg)
{
u8 cpl = ctxt->ops->cpl(ctxt);
return __load_segment_descriptor(ctxt, selector, seg, cpl,
X86_TRANSFER_NONE, NULL);
}
static void write_register_operand(struct operand *op)
{
return assign_register(op->addr.reg, op->val, op->bytes);
}
static int writeback(struct x86_emulate_ctxt *ctxt, struct operand *op)
{
switch (op->type) {
case OP_REG:
write_register_operand(op);
break;
case OP_MEM:
if (ctxt->lock_prefix)
return segmented_cmpxchg(ctxt,
op->addr.mem,
&op->orig_val,
&op->val,
op->bytes);
else
return segmented_write(ctxt,
op->addr.mem,
&op->val,
op->bytes);
break;
case OP_MEM_STR:
return segmented_write(ctxt,
op->addr.mem,
op->data,
op->bytes * op->count);
break;
case OP_XMM:
write_sse_reg(ctxt, &op->vec_val, op->addr.xmm);
break;
case OP_MM:
write_mmx_reg(ctxt, &op->mm_val, op->addr.mm);
break;
case OP_NONE:
break;
default:
break;
}
return X86EMUL_CONTINUE;
}
static int push(struct x86_emulate_ctxt *ctxt, void *data, int bytes)
{
struct segmented_address addr;
rsp_increment(ctxt, -bytes);
addr.ea = reg_read(ctxt, VCPU_REGS_RSP) & stack_mask(ctxt);
addr.seg = VCPU_SREG_SS;
return segmented_write(ctxt, addr, data, bytes);
}
static int em_push(struct x86_emulate_ctxt *ctxt)
{
ctxt->dst.type = OP_NONE;
return push(ctxt, &ctxt->src.val, ctxt->op_bytes);
}
static int emulate_pop(struct x86_emulate_ctxt *ctxt,
void *dest, int len)
{
int rc;
struct segmented_address addr;
addr.ea = reg_read(ctxt, VCPU_REGS_RSP) & stack_mask(ctxt);
addr.seg = VCPU_SREG_SS;
rc = segmented_read(ctxt, addr, dest, len);
if (rc != X86EMUL_CONTINUE)
return rc;
rsp_increment(ctxt, len);
return rc;
}
static int em_pop(struct x86_emulate_ctxt *ctxt)
{
return emulate_pop(ctxt, &ctxt->dst.val, ctxt->op_bytes);
}
static int emulate_popf(struct x86_emulate_ctxt *ctxt,
void *dest, int len)
{
int rc;
unsigned long val, change_mask;
int iopl = (ctxt->eflags & X86_EFLAGS_IOPL) >> X86_EFLAGS_IOPL_BIT;
int cpl = ctxt->ops->cpl(ctxt);
rc = emulate_pop(ctxt, &val, len);
if (rc != X86EMUL_CONTINUE)
return rc;
change_mask = X86_EFLAGS_CF | X86_EFLAGS_PF | X86_EFLAGS_AF |
X86_EFLAGS_ZF | X86_EFLAGS_SF | X86_EFLAGS_OF |
X86_EFLAGS_TF | X86_EFLAGS_DF | X86_EFLAGS_NT |
X86_EFLAGS_AC | X86_EFLAGS_ID;
switch(ctxt->mode) {
case X86EMUL_MODE_PROT64:
case X86EMUL_MODE_PROT32:
case X86EMUL_MODE_PROT16:
if (cpl == 0)
change_mask |= X86_EFLAGS_IOPL;
if (cpl <= iopl)
change_mask |= X86_EFLAGS_IF;
break;
case X86EMUL_MODE_VM86:
if (iopl < 3)
return emulate_gp(ctxt, 0);
change_mask |= X86_EFLAGS_IF;
break;
default:
change_mask |= (X86_EFLAGS_IOPL | X86_EFLAGS_IF);
break;
}
*(unsigned long *)dest =
(ctxt->eflags & ~change_mask) | (val & change_mask);
return rc;
}
static int em_popf(struct x86_emulate_ctxt *ctxt)
{
ctxt->dst.type = OP_REG;
ctxt->dst.addr.reg = &ctxt->eflags;
ctxt->dst.bytes = ctxt->op_bytes;
return emulate_popf(ctxt, &ctxt->dst.val, ctxt->op_bytes);
}
static int em_enter(struct x86_emulate_ctxt *ctxt)
{
int rc;
unsigned frame_size = ctxt->src.val;
unsigned nesting_level = ctxt->src2.val & 31;
ulong rbp;
if (nesting_level)
return X86EMUL_UNHANDLEABLE;
rbp = reg_read(ctxt, VCPU_REGS_RBP);
rc = push(ctxt, &rbp, stack_size(ctxt));
if (rc != X86EMUL_CONTINUE)
return rc;
assign_masked(reg_rmw(ctxt, VCPU_REGS_RBP), reg_read(ctxt, VCPU_REGS_RSP),
stack_mask(ctxt));
assign_masked(reg_rmw(ctxt, VCPU_REGS_RSP),
reg_read(ctxt, VCPU_REGS_RSP) - frame_size,
stack_mask(ctxt));
return X86EMUL_CONTINUE;
}
static int em_leave(struct x86_emulate_ctxt *ctxt)
{
assign_masked(reg_rmw(ctxt, VCPU_REGS_RSP), reg_read(ctxt, VCPU_REGS_RBP),
stack_mask(ctxt));
return emulate_pop(ctxt, reg_rmw(ctxt, VCPU_REGS_RBP), ctxt->op_bytes);
}
static int em_push_sreg(struct x86_emulate_ctxt *ctxt)
{
int seg = ctxt->src2.val;
ctxt->src.val = get_segment_selector(ctxt, seg);
if (ctxt->op_bytes == 4) {
rsp_increment(ctxt, -2);
ctxt->op_bytes = 2;
}
return em_push(ctxt);
}
static int em_pop_sreg(struct x86_emulate_ctxt *ctxt)
{
int seg = ctxt->src2.val;
unsigned long selector;
int rc;
rc = emulate_pop(ctxt, &selector, 2);
if (rc != X86EMUL_CONTINUE)
return rc;
if (ctxt->modrm_reg == VCPU_SREG_SS)
ctxt->interruptibility = KVM_X86_SHADOW_INT_MOV_SS;
if (ctxt->op_bytes > 2)
rsp_increment(ctxt, ctxt->op_bytes - 2);
rc = load_segment_descriptor(ctxt, (u16)selector, seg);
return rc;
}
static int em_pusha(struct x86_emulate_ctxt *ctxt)
{
unsigned long old_esp = reg_read(ctxt, VCPU_REGS_RSP);
int rc = X86EMUL_CONTINUE;
int reg = VCPU_REGS_RAX;
while (reg <= VCPU_REGS_RDI) {
(reg == VCPU_REGS_RSP) ?
(ctxt->src.val = old_esp) : (ctxt->src.val = reg_read(ctxt, reg));
rc = em_push(ctxt);
if (rc != X86EMUL_CONTINUE)
return rc;
++reg;
}
return rc;
}
static int em_pushf(struct x86_emulate_ctxt *ctxt)
{
ctxt->src.val = (unsigned long)ctxt->eflags & ~X86_EFLAGS_VM;
return em_push(ctxt);
}
static int em_popa(struct x86_emulate_ctxt *ctxt)
{
int rc = X86EMUL_CONTINUE;
int reg = VCPU_REGS_RDI;
u32 val;
while (reg >= VCPU_REGS_RAX) {
if (reg == VCPU_REGS_RSP) {
rsp_increment(ctxt, ctxt->op_bytes);
--reg;
}
rc = emulate_pop(ctxt, &val, ctxt->op_bytes);
if (rc != X86EMUL_CONTINUE)
break;
assign_register(reg_rmw(ctxt, reg), val, ctxt->op_bytes);
--reg;
}
return rc;
}
static int __emulate_int_real(struct x86_emulate_ctxt *ctxt, int irq)
{
const struct x86_emulate_ops *ops = ctxt->ops;
int rc;
struct desc_ptr dt;
gva_t cs_addr;
gva_t eip_addr;
u16 cs, eip;
ctxt->src.val = ctxt->eflags;
rc = em_push(ctxt);
if (rc != X86EMUL_CONTINUE)
return rc;
ctxt->eflags &= ~(X86_EFLAGS_IF | X86_EFLAGS_TF | X86_EFLAGS_AC);
ctxt->src.val = get_segment_selector(ctxt, VCPU_SREG_CS);
rc = em_push(ctxt);
if (rc != X86EMUL_CONTINUE)
return rc;
ctxt->src.val = ctxt->_eip;
rc = em_push(ctxt);
if (rc != X86EMUL_CONTINUE)
return rc;
ops->get_idt(ctxt, &dt);
eip_addr = dt.address + (irq << 2);
cs_addr = dt.address + (irq << 2) + 2;
rc = ops->read_std(ctxt, cs_addr, &cs, 2, &ctxt->exception);
if (rc != X86EMUL_CONTINUE)
return rc;
rc = ops->read_std(ctxt, eip_addr, &eip, 2, &ctxt->exception);
if (rc != X86EMUL_CONTINUE)
return rc;
rc = load_segment_descriptor(ctxt, cs, VCPU_SREG_CS);
if (rc != X86EMUL_CONTINUE)
return rc;
ctxt->_eip = eip;
return rc;
}
int emulate_int_real(struct x86_emulate_ctxt *ctxt, int irq)
{
int rc;
invalidate_registers(ctxt);
rc = __emulate_int_real(ctxt, irq);
if (rc == X86EMUL_CONTINUE)
writeback_registers(ctxt);
return rc;
}
static int emulate_int(struct x86_emulate_ctxt *ctxt, int irq)
{
switch(ctxt->mode) {
case X86EMUL_MODE_REAL:
return __emulate_int_real(ctxt, irq);
case X86EMUL_MODE_VM86:
case X86EMUL_MODE_PROT16:
case X86EMUL_MODE_PROT32:
case X86EMUL_MODE_PROT64:
default:
return X86EMUL_UNHANDLEABLE;
}
}
static int emulate_iret_real(struct x86_emulate_ctxt *ctxt)
{
int rc = X86EMUL_CONTINUE;
unsigned long temp_eip = 0;
unsigned long temp_eflags = 0;
unsigned long cs = 0;
unsigned long mask = X86_EFLAGS_CF | X86_EFLAGS_PF | X86_EFLAGS_AF |
X86_EFLAGS_ZF | X86_EFLAGS_SF | X86_EFLAGS_TF |
X86_EFLAGS_IF | X86_EFLAGS_DF | X86_EFLAGS_OF |
X86_EFLAGS_IOPL | X86_EFLAGS_NT | X86_EFLAGS_RF |
X86_EFLAGS_AC | X86_EFLAGS_ID |
X86_EFLAGS_FIXED;
unsigned long vm86_mask = X86_EFLAGS_VM | X86_EFLAGS_VIF |
X86_EFLAGS_VIP;
rc = emulate_pop(ctxt, &temp_eip, ctxt->op_bytes);
if (rc != X86EMUL_CONTINUE)
return rc;
if (temp_eip & ~0xffff)
return emulate_gp(ctxt, 0);
rc = emulate_pop(ctxt, &cs, ctxt->op_bytes);
if (rc != X86EMUL_CONTINUE)
return rc;
rc = emulate_pop(ctxt, &temp_eflags, ctxt->op_bytes);
if (rc != X86EMUL_CONTINUE)
return rc;
rc = load_segment_descriptor(ctxt, (u16)cs, VCPU_SREG_CS);
if (rc != X86EMUL_CONTINUE)
return rc;
ctxt->_eip = temp_eip;
if (ctxt->op_bytes == 4)
ctxt->eflags = ((temp_eflags & mask) | (ctxt->eflags & vm86_mask));
else if (ctxt->op_bytes == 2) {
ctxt->eflags &= ~0xffff;
ctxt->eflags |= temp_eflags;
}
ctxt->eflags &= ~EFLG_RESERVED_ZEROS_MASK;
ctxt->eflags |= X86_EFLAGS_FIXED;
ctxt->ops->set_nmi_mask(ctxt, false);
return rc;
}
static int em_iret(struct x86_emulate_ctxt *ctxt)
{
switch(ctxt->mode) {
case X86EMUL_MODE_REAL:
return emulate_iret_real(ctxt);
case X86EMUL_MODE_VM86:
case X86EMUL_MODE_PROT16:
case X86EMUL_MODE_PROT32:
case X86EMUL_MODE_PROT64:
default:
return X86EMUL_UNHANDLEABLE;
}
}
static int em_jmp_far(struct x86_emulate_ctxt *ctxt)
{
int rc;
unsigned short sel, old_sel;
struct desc_struct old_desc, new_desc;
const struct x86_emulate_ops *ops = ctxt->ops;
u8 cpl = ctxt->ops->cpl(ctxt);
if (ctxt->mode == X86EMUL_MODE_PROT64)
ops->get_segment(ctxt, &old_sel, &old_desc, NULL,
VCPU_SREG_CS);
memcpy(&sel, ctxt->src.valptr + ctxt->op_bytes, 2);
rc = __load_segment_descriptor(ctxt, sel, VCPU_SREG_CS, cpl,
X86_TRANSFER_CALL_JMP,
&new_desc);
if (rc != X86EMUL_CONTINUE)
return rc;
rc = assign_eip_far(ctxt, ctxt->src.val, &new_desc);
if (rc != X86EMUL_CONTINUE) {
WARN_ON(ctxt->mode != X86EMUL_MODE_PROT64);
ops->set_segment(ctxt, old_sel, &old_desc, 0, VCPU_SREG_CS);
return rc;
}
return rc;
}
static int em_jmp_abs(struct x86_emulate_ctxt *ctxt)
{
return assign_eip_near(ctxt, ctxt->src.val);
}
static int em_call_near_abs(struct x86_emulate_ctxt *ctxt)
{
int rc;
long int old_eip;
old_eip = ctxt->_eip;
rc = assign_eip_near(ctxt, ctxt->src.val);
if (rc != X86EMUL_CONTINUE)
return rc;
ctxt->src.val = old_eip;
rc = em_push(ctxt);
return rc;
}
static int em_cmpxchg8b(struct x86_emulate_ctxt *ctxt)
{
u64 old = ctxt->dst.orig_val64;
if (ctxt->dst.bytes == 16)
return X86EMUL_UNHANDLEABLE;
if (((u32) (old >> 0) != (u32) reg_read(ctxt, VCPU_REGS_RAX)) ||
((u32) (old >> 32) != (u32) reg_read(ctxt, VCPU_REGS_RDX))) {
*reg_write(ctxt, VCPU_REGS_RAX) = (u32) (old >> 0);
*reg_write(ctxt, VCPU_REGS_RDX) = (u32) (old >> 32);
ctxt->eflags &= ~X86_EFLAGS_ZF;
} else {
ctxt->dst.val64 = ((u64)reg_read(ctxt, VCPU_REGS_RCX) << 32) |
(u32) reg_read(ctxt, VCPU_REGS_RBX);
ctxt->eflags |= X86_EFLAGS_ZF;
}
return X86EMUL_CONTINUE;
}
static int em_ret(struct x86_emulate_ctxt *ctxt)
{
int rc;
unsigned long eip;
rc = emulate_pop(ctxt, &eip, ctxt->op_bytes);
if (rc != X86EMUL_CONTINUE)
return rc;
return assign_eip_near(ctxt, eip);
}
static int em_ret_far(struct x86_emulate_ctxt *ctxt)
{
int rc;
unsigned long eip, cs;
u16 old_cs;
int cpl = ctxt->ops->cpl(ctxt);
struct desc_struct old_desc, new_desc;
const struct x86_emulate_ops *ops = ctxt->ops;
if (ctxt->mode == X86EMUL_MODE_PROT64)
ops->get_segment(ctxt, &old_cs, &old_desc, NULL,
VCPU_SREG_CS);
rc = emulate_pop(ctxt, &eip, ctxt->op_bytes);
if (rc != X86EMUL_CONTINUE)
return rc;
rc = emulate_pop(ctxt, &cs, ctxt->op_bytes);
if (rc != X86EMUL_CONTINUE)
return rc;
if (ctxt->mode >= X86EMUL_MODE_PROT16 && (cs & 3) > cpl)
return X86EMUL_UNHANDLEABLE;
rc = __load_segment_descriptor(ctxt, (u16)cs, VCPU_SREG_CS, cpl,
X86_TRANSFER_RET,
&new_desc);
if (rc != X86EMUL_CONTINUE)
return rc;
rc = assign_eip_far(ctxt, eip, &new_desc);
if (rc != X86EMUL_CONTINUE) {
WARN_ON(ctxt->mode != X86EMUL_MODE_PROT64);
ops->set_segment(ctxt, old_cs, &old_desc, 0, VCPU_SREG_CS);
}
return rc;
}
static int em_ret_far_imm(struct x86_emulate_ctxt *ctxt)
{
int rc;
rc = em_ret_far(ctxt);
if (rc != X86EMUL_CONTINUE)
return rc;
rsp_increment(ctxt, ctxt->src.val);
return X86EMUL_CONTINUE;
}
static int em_cmpxchg(struct x86_emulate_ctxt *ctxt)
{
ctxt->dst.orig_val = ctxt->dst.val;
ctxt->dst.val = reg_read(ctxt, VCPU_REGS_RAX);
ctxt->src.orig_val = ctxt->src.val;
ctxt->src.val = ctxt->dst.orig_val;
fastop(ctxt, em_cmp);
if (ctxt->eflags & X86_EFLAGS_ZF) {
ctxt->src.type = OP_NONE;
ctxt->dst.val = ctxt->src.orig_val;
} else {
ctxt->src.type = OP_REG;
ctxt->src.addr.reg = reg_rmw(ctxt, VCPU_REGS_RAX);
ctxt->src.val = ctxt->dst.orig_val;
ctxt->dst.val = ctxt->dst.orig_val;
}
return X86EMUL_CONTINUE;
}
static int em_lseg(struct x86_emulate_ctxt *ctxt)
{
int seg = ctxt->src2.val;
unsigned short sel;
int rc;
memcpy(&sel, ctxt->src.valptr + ctxt->op_bytes, 2);
rc = load_segment_descriptor(ctxt, sel, seg);
if (rc != X86EMUL_CONTINUE)
return rc;
ctxt->dst.val = ctxt->src.val;
return rc;
}
static int emulator_has_longmode(struct x86_emulate_ctxt *ctxt)
{
u32 eax, ebx, ecx, edx;
eax = 0x80000001;
ecx = 0;
ctxt->ops->get_cpuid(ctxt, &eax, &ebx, &ecx, &edx);
return edx & bit(X86_FEATURE_LM);
}
static void rsm_set_desc_flags(struct desc_struct *desc, u32 flags)
{
desc->g = (flags >> 23) & 1;
desc->d = (flags >> 22) & 1;
desc->l = (flags >> 21) & 1;
desc->avl = (flags >> 20) & 1;
desc->p = (flags >> 15) & 1;
desc->dpl = (flags >> 13) & 3;
desc->s = (flags >> 12) & 1;
desc->type = (flags >> 8) & 15;
}
static int rsm_load_seg_32(struct x86_emulate_ctxt *ctxt, u64 smbase, int n)
{
struct desc_struct desc;
int offset;
u16 selector;
selector = GET_SMSTATE(u32, smbase, 0x7fa8 + n * 4);
if (n < 3)
offset = 0x7f84 + n * 12;
else
offset = 0x7f2c + (n - 3) * 12;
set_desc_base(&desc, GET_SMSTATE(u32, smbase, offset + 8));
set_desc_limit(&desc, GET_SMSTATE(u32, smbase, offset + 4));
rsm_set_desc_flags(&desc, GET_SMSTATE(u32, smbase, offset));
ctxt->ops->set_segment(ctxt, selector, &desc, 0, n);
return X86EMUL_CONTINUE;
}
static int rsm_load_seg_64(struct x86_emulate_ctxt *ctxt, u64 smbase, int n)
{
struct desc_struct desc;
int offset;
u16 selector;
u32 base3;
offset = 0x7e00 + n * 16;
selector = GET_SMSTATE(u16, smbase, offset);
rsm_set_desc_flags(&desc, GET_SMSTATE(u16, smbase, offset + 2) << 8);
set_desc_limit(&desc, GET_SMSTATE(u32, smbase, offset + 4));
set_desc_base(&desc, GET_SMSTATE(u32, smbase, offset + 8));
base3 = GET_SMSTATE(u32, smbase, offset + 12);
ctxt->ops->set_segment(ctxt, selector, &desc, base3, n);
return X86EMUL_CONTINUE;
}
static int rsm_enter_protected_mode(struct x86_emulate_ctxt *ctxt,
u64 cr0, u64 cr4)
{
int bad;
bad = ctxt->ops->set_cr(ctxt, 4, cr4 & ~X86_CR4_PCIDE);
if (bad)
return X86EMUL_UNHANDLEABLE;
bad = ctxt->ops->set_cr(ctxt, 0, cr0);
if (bad)
return X86EMUL_UNHANDLEABLE;
if (cr4 & X86_CR4_PCIDE) {
bad = ctxt->ops->set_cr(ctxt, 4, cr4);
if (bad)
return X86EMUL_UNHANDLEABLE;
}
return X86EMUL_CONTINUE;
}
static int rsm_load_state_32(struct x86_emulate_ctxt *ctxt, u64 smbase)
{
struct desc_struct desc;
struct desc_ptr dt;
u16 selector;
u32 val, cr0, cr4;
int i;
cr0 = GET_SMSTATE(u32, smbase, 0x7ffc);
ctxt->ops->set_cr(ctxt, 3, GET_SMSTATE(u32, smbase, 0x7ff8));
ctxt->eflags = GET_SMSTATE(u32, smbase, 0x7ff4) | X86_EFLAGS_FIXED;
ctxt->_eip = GET_SMSTATE(u32, smbase, 0x7ff0);
for (i = 0; i < 8; i++)
*reg_write(ctxt, i) = GET_SMSTATE(u32, smbase, 0x7fd0 + i * 4);
val = GET_SMSTATE(u32, smbase, 0x7fcc);
ctxt->ops->set_dr(ctxt, 6, (val & DR6_VOLATILE) | DR6_FIXED_1);
val = GET_SMSTATE(u32, smbase, 0x7fc8);
ctxt->ops->set_dr(ctxt, 7, (val & DR7_VOLATILE) | DR7_FIXED_1);
selector = GET_SMSTATE(u32, smbase, 0x7fc4);
set_desc_base(&desc, GET_SMSTATE(u32, smbase, 0x7f64));
set_desc_limit(&desc, GET_SMSTATE(u32, smbase, 0x7f60));
rsm_set_desc_flags(&desc, GET_SMSTATE(u32, smbase, 0x7f5c));
ctxt->ops->set_segment(ctxt, selector, &desc, 0, VCPU_SREG_TR);
selector = GET_SMSTATE(u32, smbase, 0x7fc0);
set_desc_base(&desc, GET_SMSTATE(u32, smbase, 0x7f80));
set_desc_limit(&desc, GET_SMSTATE(u32, smbase, 0x7f7c));
rsm_set_desc_flags(&desc, GET_SMSTATE(u32, smbase, 0x7f78));
ctxt->ops->set_segment(ctxt, selector, &desc, 0, VCPU_SREG_LDTR);
dt.address = GET_SMSTATE(u32, smbase, 0x7f74);
dt.size = GET_SMSTATE(u32, smbase, 0x7f70);
ctxt->ops->set_gdt(ctxt, &dt);
dt.address = GET_SMSTATE(u32, smbase, 0x7f58);
dt.size = GET_SMSTATE(u32, smbase, 0x7f54);
ctxt->ops->set_idt(ctxt, &dt);
for (i = 0; i < 6; i++) {
int r = rsm_load_seg_32(ctxt, smbase, i);
if (r != X86EMUL_CONTINUE)
return r;
}
cr4 = GET_SMSTATE(u32, smbase, 0x7f14);
ctxt->ops->set_smbase(ctxt, GET_SMSTATE(u32, smbase, 0x7ef8));
return rsm_enter_protected_mode(ctxt, cr0, cr4);
}
static int rsm_load_state_64(struct x86_emulate_ctxt *ctxt, u64 smbase)
{
struct desc_struct desc;
struct desc_ptr dt;
u64 val, cr0, cr4;
u32 base3;
u16 selector;
int i, r;
for (i = 0; i < 16; i++)
*reg_write(ctxt, i) = GET_SMSTATE(u64, smbase, 0x7ff8 - i * 8);
ctxt->_eip = GET_SMSTATE(u64, smbase, 0x7f78);
ctxt->eflags = GET_SMSTATE(u32, smbase, 0x7f70) | X86_EFLAGS_FIXED;
val = GET_SMSTATE(u32, smbase, 0x7f68);
ctxt->ops->set_dr(ctxt, 6, (val & DR6_VOLATILE) | DR6_FIXED_1);
val = GET_SMSTATE(u32, smbase, 0x7f60);
ctxt->ops->set_dr(ctxt, 7, (val & DR7_VOLATILE) | DR7_FIXED_1);
cr0 = GET_SMSTATE(u64, smbase, 0x7f58);
ctxt->ops->set_cr(ctxt, 3, GET_SMSTATE(u64, smbase, 0x7f50));
cr4 = GET_SMSTATE(u64, smbase, 0x7f48);
ctxt->ops->set_smbase(ctxt, GET_SMSTATE(u32, smbase, 0x7f00));
val = GET_SMSTATE(u64, smbase, 0x7ed0);
ctxt->ops->set_msr(ctxt, MSR_EFER, val & ~EFER_LMA);
selector = GET_SMSTATE(u32, smbase, 0x7e90);
rsm_set_desc_flags(&desc, GET_SMSTATE(u32, smbase, 0x7e92) << 8);
set_desc_limit(&desc, GET_SMSTATE(u32, smbase, 0x7e94));
set_desc_base(&desc, GET_SMSTATE(u32, smbase, 0x7e98));
base3 = GET_SMSTATE(u32, smbase, 0x7e9c);
ctxt->ops->set_segment(ctxt, selector, &desc, base3, VCPU_SREG_TR);
dt.size = GET_SMSTATE(u32, smbase, 0x7e84);
dt.address = GET_SMSTATE(u64, smbase, 0x7e88);
ctxt->ops->set_idt(ctxt, &dt);
selector = GET_SMSTATE(u32, smbase, 0x7e70);
rsm_set_desc_flags(&desc, GET_SMSTATE(u32, smbase, 0x7e72) << 8);
set_desc_limit(&desc, GET_SMSTATE(u32, smbase, 0x7e74));
set_desc_base(&desc, GET_SMSTATE(u32, smbase, 0x7e78));
base3 = GET_SMSTATE(u32, smbase, 0x7e7c);
ctxt->ops->set_segment(ctxt, selector, &desc, base3, VCPU_SREG_LDTR);
dt.size = GET_SMSTATE(u32, smbase, 0x7e64);
dt.address = GET_SMSTATE(u64, smbase, 0x7e68);
ctxt->ops->set_gdt(ctxt, &dt);
r = rsm_enter_protected_mode(ctxt, cr0, cr4);
if (r != X86EMUL_CONTINUE)
return r;
for (i = 0; i < 6; i++) {
r = rsm_load_seg_64(ctxt, smbase, i);
if (r != X86EMUL_CONTINUE)
return r;
}
return X86EMUL_CONTINUE;
}
static int em_rsm(struct x86_emulate_ctxt *ctxt)
{
unsigned long cr0, cr4, efer;
u64 smbase;
int ret;
if ((ctxt->emul_flags & X86EMUL_SMM_MASK) == 0)
return emulate_ud(ctxt);
cr4 = ctxt->ops->get_cr(ctxt, 4);
if (emulator_has_longmode(ctxt)) {
struct desc_struct cs_desc;
if (cr4 & X86_CR4_PCIDE) {
ctxt->ops->set_cr(ctxt, 4, cr4 & ~X86_CR4_PCIDE);
cr4 &= ~X86_CR4_PCIDE;
}
memset(&cs_desc, 0, sizeof(cs_desc));
cs_desc.type = 0xb;
cs_desc.s = cs_desc.g = cs_desc.p = 1;
ctxt->ops->set_segment(ctxt, 0, &cs_desc, 0, VCPU_SREG_CS);
}
cr0 = ctxt->ops->get_cr(ctxt, 0);
if (cr0 & X86_CR0_PE)
ctxt->ops->set_cr(ctxt, 0, cr0 & ~(X86_CR0_PG | X86_CR0_PE));
if (cr4 & X86_CR4_PAE)
ctxt->ops->set_cr(ctxt, 4, cr4 & ~X86_CR4_PAE);
efer = 0;
ctxt->ops->set_msr(ctxt, MSR_EFER, efer);
smbase = ctxt->ops->get_smbase(ctxt);
if (emulator_has_longmode(ctxt))
ret = rsm_load_state_64(ctxt, smbase + 0x8000);
else
ret = rsm_load_state_32(ctxt, smbase + 0x8000);
if (ret != X86EMUL_CONTINUE) {
return X86EMUL_UNHANDLEABLE;
}
if ((ctxt->emul_flags & X86EMUL_SMM_INSIDE_NMI_MASK) == 0)
ctxt->ops->set_nmi_mask(ctxt, false);
ctxt->emul_flags &= ~X86EMUL_SMM_INSIDE_NMI_MASK;
ctxt->emul_flags &= ~X86EMUL_SMM_MASK;
return X86EMUL_CONTINUE;
}
static void
setup_syscalls_segments(struct x86_emulate_ctxt *ctxt,
struct desc_struct *cs, struct desc_struct *ss)
{
cs->l = 0;
set_desc_base(cs, 0);
cs->g = 1;
set_desc_limit(cs, 0xfffff);
cs->type = 0x0b;
cs->s = 1;
cs->dpl = 0;
cs->p = 1;
cs->d = 1;
cs->avl = 0;
set_desc_base(ss, 0);
set_desc_limit(ss, 0xfffff);
ss->g = 1;
ss->s = 1;
ss->type = 0x03;
ss->d = 1;
ss->dpl = 0;
ss->p = 1;
ss->l = 0;
ss->avl = 0;
}
static bool vendor_intel(struct x86_emulate_ctxt *ctxt)
{
u32 eax, ebx, ecx, edx;
eax = ecx = 0;
ctxt->ops->get_cpuid(ctxt, &eax, &ebx, &ecx, &edx);
return ebx == X86EMUL_CPUID_VENDOR_GenuineIntel_ebx
&& ecx == X86EMUL_CPUID_VENDOR_GenuineIntel_ecx
&& edx == X86EMUL_CPUID_VENDOR_GenuineIntel_edx;
}
static bool em_syscall_is_enabled(struct x86_emulate_ctxt *ctxt)
{
const struct x86_emulate_ops *ops = ctxt->ops;
u32 eax, ebx, ecx, edx;
if (ctxt->mode == X86EMUL_MODE_PROT64)
return true;
eax = 0x00000000;
ecx = 0x00000000;
ops->get_cpuid(ctxt, &eax, &ebx, &ecx, &edx);
if (ebx == X86EMUL_CPUID_VENDOR_GenuineIntel_ebx &&
ecx == X86EMUL_CPUID_VENDOR_GenuineIntel_ecx &&
edx == X86EMUL_CPUID_VENDOR_GenuineIntel_edx)
return false;
if (ebx == X86EMUL_CPUID_VENDOR_AuthenticAMD_ebx &&
ecx == X86EMUL_CPUID_VENDOR_AuthenticAMD_ecx &&
edx == X86EMUL_CPUID_VENDOR_AuthenticAMD_edx)
return true;
if (ebx == X86EMUL_CPUID_VENDOR_AMDisbetterI_ebx &&
ecx == X86EMUL_CPUID_VENDOR_AMDisbetterI_ecx &&
edx == X86EMUL_CPUID_VENDOR_AMDisbetterI_edx)
return true;
return false;
}
static int em_syscall(struct x86_emulate_ctxt *ctxt)
{
const struct x86_emulate_ops *ops = ctxt->ops;
struct desc_struct cs, ss;
u64 msr_data;
u16 cs_sel, ss_sel;
u64 efer = 0;
if (ctxt->mode == X86EMUL_MODE_REAL ||
ctxt->mode == X86EMUL_MODE_VM86)
return emulate_ud(ctxt);
if (!(em_syscall_is_enabled(ctxt)))
return emulate_ud(ctxt);
ops->get_msr(ctxt, MSR_EFER, &efer);
setup_syscalls_segments(ctxt, &cs, &ss);
if (!(efer & EFER_SCE))
return emulate_ud(ctxt);
ops->get_msr(ctxt, MSR_STAR, &msr_data);
msr_data >>= 32;
cs_sel = (u16)(msr_data & 0xfffc);
ss_sel = (u16)(msr_data + 8);
if (efer & EFER_LMA) {
cs.d = 0;
cs.l = 1;
}
ops->set_segment(ctxt, cs_sel, &cs, 0, VCPU_SREG_CS);
ops->set_segment(ctxt, ss_sel, &ss, 0, VCPU_SREG_SS);
*reg_write(ctxt, VCPU_REGS_RCX) = ctxt->_eip;
if (efer & EFER_LMA) {
#ifdef CONFIG_X86_64
*reg_write(ctxt, VCPU_REGS_R11) = ctxt->eflags;
ops->get_msr(ctxt,
ctxt->mode == X86EMUL_MODE_PROT64 ?
MSR_LSTAR : MSR_CSTAR, &msr_data);
ctxt->_eip = msr_data;
ops->get_msr(ctxt, MSR_SYSCALL_MASK, &msr_data);
ctxt->eflags &= ~msr_data;
ctxt->eflags |= X86_EFLAGS_FIXED;
#endif
} else {
ops->get_msr(ctxt, MSR_STAR, &msr_data);
ctxt->_eip = (u32)msr_data;
ctxt->eflags &= ~(X86_EFLAGS_VM | X86_EFLAGS_IF);
}
return X86EMUL_CONTINUE;
}
static int em_sysenter(struct x86_emulate_ctxt *ctxt)
{
const struct x86_emulate_ops *ops = ctxt->ops;
struct desc_struct cs, ss;
u64 msr_data;
u16 cs_sel, ss_sel;
u64 efer = 0;
ops->get_msr(ctxt, MSR_EFER, &efer);
if (ctxt->mode == X86EMUL_MODE_REAL)
return emulate_gp(ctxt, 0);
if ((ctxt->mode != X86EMUL_MODE_PROT64) && (efer & EFER_LMA)
&& !vendor_intel(ctxt))
return emulate_ud(ctxt);
if (ctxt->mode == X86EMUL_MODE_PROT64)
return X86EMUL_UNHANDLEABLE;
setup_syscalls_segments(ctxt, &cs, &ss);
ops->get_msr(ctxt, MSR_IA32_SYSENTER_CS, &msr_data);
if ((msr_data & 0xfffc) == 0x0)
return emulate_gp(ctxt, 0);
ctxt->eflags &= ~(X86_EFLAGS_VM | X86_EFLAGS_IF);
cs_sel = (u16)msr_data & ~SEGMENT_RPL_MASK;
ss_sel = cs_sel + 8;
if (efer & EFER_LMA) {
cs.d = 0;
cs.l = 1;
}
ops->set_segment(ctxt, cs_sel, &cs, 0, VCPU_SREG_CS);
ops->set_segment(ctxt, ss_sel, &ss, 0, VCPU_SREG_SS);
ops->get_msr(ctxt, MSR_IA32_SYSENTER_EIP, &msr_data);
ctxt->_eip = (efer & EFER_LMA) ? msr_data : (u32)msr_data;
ops->get_msr(ctxt, MSR_IA32_SYSENTER_ESP, &msr_data);
*reg_write(ctxt, VCPU_REGS_RSP) = (efer & EFER_LMA) ? msr_data :
(u32)msr_data;
return X86EMUL_CONTINUE;
}
static int em_sysexit(struct x86_emulate_ctxt *ctxt)
{
const struct x86_emulate_ops *ops = ctxt->ops;
struct desc_struct cs, ss;
u64 msr_data, rcx, rdx;
int usermode;
u16 cs_sel = 0, ss_sel = 0;
if (ctxt->mode == X86EMUL_MODE_REAL ||
ctxt->mode == X86EMUL_MODE_VM86)
return emulate_gp(ctxt, 0);
setup_syscalls_segments(ctxt, &cs, &ss);
if ((ctxt->rex_prefix & 0x8) != 0x0)
usermode = X86EMUL_MODE_PROT64;
else
usermode = X86EMUL_MODE_PROT32;
rcx = reg_read(ctxt, VCPU_REGS_RCX);
rdx = reg_read(ctxt, VCPU_REGS_RDX);
cs.dpl = 3;
ss.dpl = 3;
ops->get_msr(ctxt, MSR_IA32_SYSENTER_CS, &msr_data);
switch (usermode) {
case X86EMUL_MODE_PROT32:
cs_sel = (u16)(msr_data + 16);
if ((msr_data & 0xfffc) == 0x0)
return emulate_gp(ctxt, 0);
ss_sel = (u16)(msr_data + 24);
rcx = (u32)rcx;
rdx = (u32)rdx;
break;
case X86EMUL_MODE_PROT64:
cs_sel = (u16)(msr_data + 32);
if (msr_data == 0x0)
return emulate_gp(ctxt, 0);
ss_sel = cs_sel + 8;
cs.d = 0;
cs.l = 1;
if (is_noncanonical_address(rcx) ||
is_noncanonical_address(rdx))
return emulate_gp(ctxt, 0);
break;
}
cs_sel |= SEGMENT_RPL_MASK;
ss_sel |= SEGMENT_RPL_MASK;
ops->set_segment(ctxt, cs_sel, &cs, 0, VCPU_SREG_CS);
ops->set_segment(ctxt, ss_sel, &ss, 0, VCPU_SREG_SS);
ctxt->_eip = rdx;
*reg_write(ctxt, VCPU_REGS_RSP) = rcx;
return X86EMUL_CONTINUE;
}
static bool emulator_bad_iopl(struct x86_emulate_ctxt *ctxt)
{
int iopl;
if (ctxt->mode == X86EMUL_MODE_REAL)
return false;
if (ctxt->mode == X86EMUL_MODE_VM86)
return true;
iopl = (ctxt->eflags & X86_EFLAGS_IOPL) >> X86_EFLAGS_IOPL_BIT;
return ctxt->ops->cpl(ctxt) > iopl;
}
static bool emulator_io_port_access_allowed(struct x86_emulate_ctxt *ctxt,
u16 port, u16 len)
{
const struct x86_emulate_ops *ops = ctxt->ops;
struct desc_struct tr_seg;
u32 base3;
int r;
u16 tr, io_bitmap_ptr, perm, bit_idx = port & 0x7;
unsigned mask = (1 << len) - 1;
unsigned long base;
ops->get_segment(ctxt, &tr, &tr_seg, &base3, VCPU_SREG_TR);
if (!tr_seg.p)
return false;
if (desc_limit_scaled(&tr_seg) < 103)
return false;
base = get_desc_base(&tr_seg);
#ifdef CONFIG_X86_64
base |= ((u64)base3) << 32;
#endif
r = ops->read_std(ctxt, base + 102, &io_bitmap_ptr, 2, NULL);
if (r != X86EMUL_CONTINUE)
return false;
if (io_bitmap_ptr + port/8 > desc_limit_scaled(&tr_seg))
return false;
r = ops->read_std(ctxt, base + io_bitmap_ptr + port/8, &perm, 2, NULL);
if (r != X86EMUL_CONTINUE)
return false;
if ((perm >> bit_idx) & mask)
return false;
return true;
}
static bool emulator_io_permited(struct x86_emulate_ctxt *ctxt,
u16 port, u16 len)
{
if (ctxt->perm_ok)
return true;
if (emulator_bad_iopl(ctxt))
if (!emulator_io_port_access_allowed(ctxt, port, len))
return false;
ctxt->perm_ok = true;
return true;
}
static void string_registers_quirk(struct x86_emulate_ctxt *ctxt)
{
#ifdef CONFIG_X86_64
if (ctxt->ad_bytes != 4 || !vendor_intel(ctxt))
return;
*reg_write(ctxt, VCPU_REGS_RCX) = 0;
switch (ctxt->b) {
case 0xa4:
case 0xa5:
*reg_rmw(ctxt, VCPU_REGS_RSI) &= (u32)-1;
case 0xaa:
case 0xab:
*reg_rmw(ctxt, VCPU_REGS_RDI) &= (u32)-1;
}
#endif
}
static void save_state_to_tss16(struct x86_emulate_ctxt *ctxt,
struct tss_segment_16 *tss)
{
tss->ip = ctxt->_eip;
tss->flag = ctxt->eflags;
tss->ax = reg_read(ctxt, VCPU_REGS_RAX);
tss->cx = reg_read(ctxt, VCPU_REGS_RCX);
tss->dx = reg_read(ctxt, VCPU_REGS_RDX);
tss->bx = reg_read(ctxt, VCPU_REGS_RBX);
tss->sp = reg_read(ctxt, VCPU_REGS_RSP);
tss->bp = reg_read(ctxt, VCPU_REGS_RBP);
tss->si = reg_read(ctxt, VCPU_REGS_RSI);
tss->di = reg_read(ctxt, VCPU_REGS_RDI);
tss->es = get_segment_selector(ctxt, VCPU_SREG_ES);
tss->cs = get_segment_selector(ctxt, VCPU_SREG_CS);
tss->ss = get_segment_selector(ctxt, VCPU_SREG_SS);
tss->ds = get_segment_selector(ctxt, VCPU_SREG_DS);
tss->ldt = get_segment_selector(ctxt, VCPU_SREG_LDTR);
}
static int load_state_from_tss16(struct x86_emulate_ctxt *ctxt,
struct tss_segment_16 *tss)
{
int ret;
u8 cpl;
ctxt->_eip = tss->ip;
ctxt->eflags = tss->flag | 2;
*reg_write(ctxt, VCPU_REGS_RAX) = tss->ax;
*reg_write(ctxt, VCPU_REGS_RCX) = tss->cx;
*reg_write(ctxt, VCPU_REGS_RDX) = tss->dx;
*reg_write(ctxt, VCPU_REGS_RBX) = tss->bx;
*reg_write(ctxt, VCPU_REGS_RSP) = tss->sp;
*reg_write(ctxt, VCPU_REGS_RBP) = tss->bp;
*reg_write(ctxt, VCPU_REGS_RSI) = tss->si;
*reg_write(ctxt, VCPU_REGS_RDI) = tss->di;
set_segment_selector(ctxt, tss->ldt, VCPU_SREG_LDTR);
set_segment_selector(ctxt, tss->es, VCPU_SREG_ES);
set_segment_selector(ctxt, tss->cs, VCPU_SREG_CS);
set_segment_selector(ctxt, tss->ss, VCPU_SREG_SS);
set_segment_selector(ctxt, tss->ds, VCPU_SREG_DS);
cpl = tss->cs & 3;
ret = __load_segment_descriptor(ctxt, tss->ldt, VCPU_SREG_LDTR, cpl,
X86_TRANSFER_TASK_SWITCH, NULL);
if (ret != X86EMUL_CONTINUE)
return ret;
ret = __load_segment_descriptor(ctxt, tss->es, VCPU_SREG_ES, cpl,
X86_TRANSFER_TASK_SWITCH, NULL);
if (ret != X86EMUL_CONTINUE)
return ret;
ret = __load_segment_descriptor(ctxt, tss->cs, VCPU_SREG_CS, cpl,
X86_TRANSFER_TASK_SWITCH, NULL);
if (ret != X86EMUL_CONTINUE)
return ret;
ret = __load_segment_descriptor(ctxt, tss->ss, VCPU_SREG_SS, cpl,
X86_TRANSFER_TASK_SWITCH, NULL);
if (ret != X86EMUL_CONTINUE)
return ret;
ret = __load_segment_descriptor(ctxt, tss->ds, VCPU_SREG_DS, cpl,
X86_TRANSFER_TASK_SWITCH, NULL);
if (ret != X86EMUL_CONTINUE)
return ret;
return X86EMUL_CONTINUE;
}
static int task_switch_16(struct x86_emulate_ctxt *ctxt,
u16 tss_selector, u16 old_tss_sel,
ulong old_tss_base, struct desc_struct *new_desc)
{
const struct x86_emulate_ops *ops = ctxt->ops;
struct tss_segment_16 tss_seg;
int ret;
u32 new_tss_base = get_desc_base(new_desc);
ret = ops->read_std(ctxt, old_tss_base, &tss_seg, sizeof tss_seg,
&ctxt->exception);
if (ret != X86EMUL_CONTINUE)
return ret;
save_state_to_tss16(ctxt, &tss_seg);
ret = ops->write_std(ctxt, old_tss_base, &tss_seg, sizeof tss_seg,
&ctxt->exception);
if (ret != X86EMUL_CONTINUE)
return ret;
ret = ops->read_std(ctxt, new_tss_base, &tss_seg, sizeof tss_seg,
&ctxt->exception);
if (ret != X86EMUL_CONTINUE)
return ret;
if (old_tss_sel != 0xffff) {
tss_seg.prev_task_link = old_tss_sel;
ret = ops->write_std(ctxt, new_tss_base,
&tss_seg.prev_task_link,
sizeof tss_seg.prev_task_link,
&ctxt->exception);
if (ret != X86EMUL_CONTINUE)
return ret;
}
return load_state_from_tss16(ctxt, &tss_seg);
}
static void save_state_to_tss32(struct x86_emulate_ctxt *ctxt,
struct tss_segment_32 *tss)
{
tss->eip = ctxt->_eip;
tss->eflags = ctxt->eflags;
tss->eax = reg_read(ctxt, VCPU_REGS_RAX);
tss->ecx = reg_read(ctxt, VCPU_REGS_RCX);
tss->edx = reg_read(ctxt, VCPU_REGS_RDX);
tss->ebx = reg_read(ctxt, VCPU_REGS_RBX);
tss->esp = reg_read(ctxt, VCPU_REGS_RSP);
tss->ebp = reg_read(ctxt, VCPU_REGS_RBP);
tss->esi = reg_read(ctxt, VCPU_REGS_RSI);
tss->edi = reg_read(ctxt, VCPU_REGS_RDI);
tss->es = get_segment_selector(ctxt, VCPU_SREG_ES);
tss->cs = get_segment_selector(ctxt, VCPU_SREG_CS);
tss->ss = get_segment_selector(ctxt, VCPU_SREG_SS);
tss->ds = get_segment_selector(ctxt, VCPU_SREG_DS);
tss->fs = get_segment_selector(ctxt, VCPU_SREG_FS);
tss->gs = get_segment_selector(ctxt, VCPU_SREG_GS);
}
static int load_state_from_tss32(struct x86_emulate_ctxt *ctxt,
struct tss_segment_32 *tss)
{
int ret;
u8 cpl;
if (ctxt->ops->set_cr(ctxt, 3, tss->cr3))
return emulate_gp(ctxt, 0);
ctxt->_eip = tss->eip;
ctxt->eflags = tss->eflags | 2;
*reg_write(ctxt, VCPU_REGS_RAX) = tss->eax;
*reg_write(ctxt, VCPU_REGS_RCX) = tss->ecx;
*reg_write(ctxt, VCPU_REGS_RDX) = tss->edx;
*reg_write(ctxt, VCPU_REGS_RBX) = tss->ebx;
*reg_write(ctxt, VCPU_REGS_RSP) = tss->esp;
*reg_write(ctxt, VCPU_REGS_RBP) = tss->ebp;
*reg_write(ctxt, VCPU_REGS_RSI) = tss->esi;
*reg_write(ctxt, VCPU_REGS_RDI) = tss->edi;
set_segment_selector(ctxt, tss->ldt_selector, VCPU_SREG_LDTR);
set_segment_selector(ctxt, tss->es, VCPU_SREG_ES);
set_segment_selector(ctxt, tss->cs, VCPU_SREG_CS);
set_segment_selector(ctxt, tss->ss, VCPU_SREG_SS);
set_segment_selector(ctxt, tss->ds, VCPU_SREG_DS);
set_segment_selector(ctxt, tss->fs, VCPU_SREG_FS);
set_segment_selector(ctxt, tss->gs, VCPU_SREG_GS);
if (ctxt->eflags & X86_EFLAGS_VM) {
ctxt->mode = X86EMUL_MODE_VM86;
cpl = 3;
} else {
ctxt->mode = X86EMUL_MODE_PROT32;
cpl = tss->cs & 3;
}
ret = __load_segment_descriptor(ctxt, tss->ldt_selector, VCPU_SREG_LDTR,
cpl, X86_TRANSFER_TASK_SWITCH, NULL);
if (ret != X86EMUL_CONTINUE)
return ret;
ret = __load_segment_descriptor(ctxt, tss->es, VCPU_SREG_ES, cpl,
X86_TRANSFER_TASK_SWITCH, NULL);
if (ret != X86EMUL_CONTINUE)
return ret;
ret = __load_segment_descriptor(ctxt, tss->cs, VCPU_SREG_CS, cpl,
X86_TRANSFER_TASK_SWITCH, NULL);
if (ret != X86EMUL_CONTINUE)
return ret;
ret = __load_segment_descriptor(ctxt, tss->ss, VCPU_SREG_SS, cpl,
X86_TRANSFER_TASK_SWITCH, NULL);
if (ret != X86EMUL_CONTINUE)
return ret;
ret = __load_segment_descriptor(ctxt, tss->ds, VCPU_SREG_DS, cpl,
X86_TRANSFER_TASK_SWITCH, NULL);
if (ret != X86EMUL_CONTINUE)
return ret;
ret = __load_segment_descriptor(ctxt, tss->fs, VCPU_SREG_FS, cpl,
X86_TRANSFER_TASK_SWITCH, NULL);
if (ret != X86EMUL_CONTINUE)
return ret;
ret = __load_segment_descriptor(ctxt, tss->gs, VCPU_SREG_GS, cpl,
X86_TRANSFER_TASK_SWITCH, NULL);
return ret;
}
static int task_switch_32(struct x86_emulate_ctxt *ctxt,
u16 tss_selector, u16 old_tss_sel,
ulong old_tss_base, struct desc_struct *new_desc)
{
const struct x86_emulate_ops *ops = ctxt->ops;
struct tss_segment_32 tss_seg;
int ret;
u32 new_tss_base = get_desc_base(new_desc);
u32 eip_offset = offsetof(struct tss_segment_32, eip);
u32 ldt_sel_offset = offsetof(struct tss_segment_32, ldt_selector);
ret = ops->read_std(ctxt, old_tss_base, &tss_seg, sizeof tss_seg,
&ctxt->exception);
if (ret != X86EMUL_CONTINUE)
return ret;
save_state_to_tss32(ctxt, &tss_seg);
ret = ops->write_std(ctxt, old_tss_base + eip_offset, &tss_seg.eip,
ldt_sel_offset - eip_offset, &ctxt->exception);
if (ret != X86EMUL_CONTINUE)
return ret;
ret = ops->read_std(ctxt, new_tss_base, &tss_seg, sizeof tss_seg,
&ctxt->exception);
if (ret != X86EMUL_CONTINUE)
return ret;
if (old_tss_sel != 0xffff) {
tss_seg.prev_task_link = old_tss_sel;
ret = ops->write_std(ctxt, new_tss_base,
&tss_seg.prev_task_link,
sizeof tss_seg.prev_task_link,
&ctxt->exception);
if (ret != X86EMUL_CONTINUE)
return ret;
}
return load_state_from_tss32(ctxt, &tss_seg);
}
static int emulator_do_task_switch(struct x86_emulate_ctxt *ctxt,
u16 tss_selector, int idt_index, int reason,
bool has_error_code, u32 error_code)
{
const struct x86_emulate_ops *ops = ctxt->ops;
struct desc_struct curr_tss_desc, next_tss_desc;
int ret;
u16 old_tss_sel = get_segment_selector(ctxt, VCPU_SREG_TR);
ulong old_tss_base =
ops->get_cached_segment_base(ctxt, VCPU_SREG_TR);
u32 desc_limit;
ulong desc_addr, dr7;
ret = read_segment_descriptor(ctxt, tss_selector, &next_tss_desc, &desc_addr);
if (ret != X86EMUL_CONTINUE)
return ret;
ret = read_segment_descriptor(ctxt, old_tss_sel, &curr_tss_desc, &desc_addr);
if (ret != X86EMUL_CONTINUE)
return ret;
if (reason == TASK_SWITCH_GATE) {
if (idt_index != -1) {
struct desc_struct task_gate_desc;
int dpl;
ret = read_interrupt_descriptor(ctxt, idt_index,
&task_gate_desc);
if (ret != X86EMUL_CONTINUE)
return ret;
dpl = task_gate_desc.dpl;
if ((tss_selector & 3) > dpl || ops->cpl(ctxt) > dpl)
return emulate_gp(ctxt, (idt_index << 3) | 0x2);
}
}
desc_limit = desc_limit_scaled(&next_tss_desc);
if (!next_tss_desc.p ||
((desc_limit < 0x67 && (next_tss_desc.type & 8)) ||
desc_limit < 0x2b)) {
return emulate_ts(ctxt, tss_selector & 0xfffc);
}
if (reason == TASK_SWITCH_IRET || reason == TASK_SWITCH_JMP) {
curr_tss_desc.type &= ~(1 << 1);
write_segment_descriptor(ctxt, old_tss_sel, &curr_tss_desc);
}
if (reason == TASK_SWITCH_IRET)
ctxt->eflags = ctxt->eflags & ~X86_EFLAGS_NT;
if (reason != TASK_SWITCH_CALL && reason != TASK_SWITCH_GATE)
old_tss_sel = 0xffff;
if (next_tss_desc.type & 8)
ret = task_switch_32(ctxt, tss_selector, old_tss_sel,
old_tss_base, &next_tss_desc);
else
ret = task_switch_16(ctxt, tss_selector, old_tss_sel,
old_tss_base, &next_tss_desc);
if (ret != X86EMUL_CONTINUE)
return ret;
if (reason == TASK_SWITCH_CALL || reason == TASK_SWITCH_GATE)
ctxt->eflags = ctxt->eflags | X86_EFLAGS_NT;
if (reason != TASK_SWITCH_IRET) {
next_tss_desc.type |= (1 << 1);
write_segment_descriptor(ctxt, tss_selector, &next_tss_desc);
}
ops->set_cr(ctxt, 0, ops->get_cr(ctxt, 0) | X86_CR0_TS);
ops->set_segment(ctxt, tss_selector, &next_tss_desc, 0, VCPU_SREG_TR);
if (has_error_code) {
ctxt->op_bytes = ctxt->ad_bytes = (next_tss_desc.type & 8) ? 4 : 2;
ctxt->lock_prefix = 0;
ctxt->src.val = (unsigned long) error_code;
ret = em_push(ctxt);
}
ops->get_dr(ctxt, 7, &dr7);
ops->set_dr(ctxt, 7, dr7 & ~(DR_LOCAL_ENABLE_MASK | DR_LOCAL_SLOWDOWN));
return ret;
}
int emulator_task_switch(struct x86_emulate_ctxt *ctxt,
u16 tss_selector, int idt_index, int reason,
bool has_error_code, u32 error_code)
{
int rc;
invalidate_registers(ctxt);
ctxt->_eip = ctxt->eip;
ctxt->dst.type = OP_NONE;
rc = emulator_do_task_switch(ctxt, tss_selector, idt_index, reason,
has_error_code, error_code);
if (rc == X86EMUL_CONTINUE) {
ctxt->eip = ctxt->_eip;
writeback_registers(ctxt);
}
return (rc == X86EMUL_UNHANDLEABLE) ? EMULATION_FAILED : EMULATION_OK;
}
static void string_addr_inc(struct x86_emulate_ctxt *ctxt, int reg,
struct operand *op)
{
int df = (ctxt->eflags & X86_EFLAGS_DF) ? -op->count : op->count;
register_address_increment(ctxt, reg, df * op->bytes);
op->addr.mem.ea = register_address(ctxt, reg);
}
static int em_das(struct x86_emulate_ctxt *ctxt)
{
u8 al, old_al;
bool af, cf, old_cf;
cf = ctxt->eflags & X86_EFLAGS_CF;
al = ctxt->dst.val;
old_al = al;
old_cf = cf;
cf = false;
af = ctxt->eflags & X86_EFLAGS_AF;
if ((al & 0x0f) > 9 || af) {
al -= 6;
cf = old_cf | (al >= 250);
af = true;
} else {
af = false;
}
if (old_al > 0x99 || old_cf) {
al -= 0x60;
cf = true;
}
ctxt->dst.val = al;
ctxt->src.type = OP_IMM;
ctxt->src.val = 0;
ctxt->src.bytes = 1;
fastop(ctxt, em_or);
ctxt->eflags &= ~(X86_EFLAGS_AF | X86_EFLAGS_CF);
if (cf)
ctxt->eflags |= X86_EFLAGS_CF;
if (af)
ctxt->eflags |= X86_EFLAGS_AF;
return X86EMUL_CONTINUE;
}
static int em_aam(struct x86_emulate_ctxt *ctxt)
{
u8 al, ah;
if (ctxt->src.val == 0)
return emulate_de(ctxt);
al = ctxt->dst.val & 0xff;
ah = al / ctxt->src.val;
al %= ctxt->src.val;
ctxt->dst.val = (ctxt->dst.val & 0xffff0000) | al | (ah << 8);
ctxt->src.type = OP_IMM;
ctxt->src.val = 0;
ctxt->src.bytes = 1;
fastop(ctxt, em_or);
return X86EMUL_CONTINUE;
}
static int em_aad(struct x86_emulate_ctxt *ctxt)
{
u8 al = ctxt->dst.val & 0xff;
u8 ah = (ctxt->dst.val >> 8) & 0xff;
al = (al + (ah * ctxt->src.val)) & 0xff;
ctxt->dst.val = (ctxt->dst.val & 0xffff0000) | al;
ctxt->src.type = OP_IMM;
ctxt->src.val = 0;
ctxt->src.bytes = 1;
fastop(ctxt, em_or);
return X86EMUL_CONTINUE;
}
static int em_call(struct x86_emulate_ctxt *ctxt)
{
int rc;
long rel = ctxt->src.val;
ctxt->src.val = (unsigned long)ctxt->_eip;
rc = jmp_rel(ctxt, rel);
if (rc != X86EMUL_CONTINUE)
return rc;
return em_push(ctxt);
}
static int em_call_far(struct x86_emulate_ctxt *ctxt)
{
u16 sel, old_cs;
ulong old_eip;
int rc;
struct desc_struct old_desc, new_desc;
const struct x86_emulate_ops *ops = ctxt->ops;
int cpl = ctxt->ops->cpl(ctxt);
enum x86emul_mode prev_mode = ctxt->mode;
old_eip = ctxt->_eip;
ops->get_segment(ctxt, &old_cs, &old_desc, NULL, VCPU_SREG_CS);
memcpy(&sel, ctxt->src.valptr + ctxt->op_bytes, 2);
rc = __load_segment_descriptor(ctxt, sel, VCPU_SREG_CS, cpl,
X86_TRANSFER_CALL_JMP, &new_desc);
if (rc != X86EMUL_CONTINUE)
return rc;
rc = assign_eip_far(ctxt, ctxt->src.val, &new_desc);
if (rc != X86EMUL_CONTINUE)
goto fail;
ctxt->src.val = old_cs;
rc = em_push(ctxt);
if (rc != X86EMUL_CONTINUE)
goto fail;
ctxt->src.val = old_eip;
rc = em_push(ctxt);
if (rc != X86EMUL_CONTINUE) {
pr_warn_once("faulting far call emulation tainted memory\n");
goto fail;
}
return rc;
fail:
ops->set_segment(ctxt, old_cs, &old_desc, 0, VCPU_SREG_CS);
ctxt->mode = prev_mode;
return rc;
}
static int em_ret_near_imm(struct x86_emulate_ctxt *ctxt)
{
int rc;
unsigned long eip;
rc = emulate_pop(ctxt, &eip, ctxt->op_bytes);
if (rc != X86EMUL_CONTINUE)
return rc;
rc = assign_eip_near(ctxt, eip);
if (rc != X86EMUL_CONTINUE)
return rc;
rsp_increment(ctxt, ctxt->src.val);
return X86EMUL_CONTINUE;
}
static int em_xchg(struct x86_emulate_ctxt *ctxt)
{
ctxt->src.val = ctxt->dst.val;
write_register_operand(&ctxt->src);
ctxt->dst.val = ctxt->src.orig_val;
ctxt->lock_prefix = 1;
return X86EMUL_CONTINUE;
}
static int em_imul_3op(struct x86_emulate_ctxt *ctxt)
{
ctxt->dst.val = ctxt->src2.val;
return fastop(ctxt, em_imul);
}
static int em_cwd(struct x86_emulate_ctxt *ctxt)
{
ctxt->dst.type = OP_REG;
ctxt->dst.bytes = ctxt->src.bytes;
ctxt->dst.addr.reg = reg_rmw(ctxt, VCPU_REGS_RDX);
ctxt->dst.val = ~((ctxt->src.val >> (ctxt->src.bytes * 8 - 1)) - 1);
return X86EMUL_CONTINUE;
}
static int em_rdtsc(struct x86_emulate_ctxt *ctxt)
{
u64 tsc = 0;
ctxt->ops->get_msr(ctxt, MSR_IA32_TSC, &tsc);
*reg_write(ctxt, VCPU_REGS_RAX) = (u32)tsc;
*reg_write(ctxt, VCPU_REGS_RDX) = tsc >> 32;
return X86EMUL_CONTINUE;
}
static int em_rdpmc(struct x86_emulate_ctxt *ctxt)
{
u64 pmc;
if (ctxt->ops->read_pmc(ctxt, reg_read(ctxt, VCPU_REGS_RCX), &pmc))
return emulate_gp(ctxt, 0);
*reg_write(ctxt, VCPU_REGS_RAX) = (u32)pmc;
*reg_write(ctxt, VCPU_REGS_RDX) = pmc >> 32;
return X86EMUL_CONTINUE;
}
static int em_mov(struct x86_emulate_ctxt *ctxt)
{
memcpy(ctxt->dst.valptr, ctxt->src.valptr, sizeof(ctxt->src.valptr));
return X86EMUL_CONTINUE;
}
static int em_movbe(struct x86_emulate_ctxt *ctxt)
{
u32 ebx, ecx, edx, eax = 1;
u16 tmp;
ctxt->ops->get_cpuid(ctxt, &eax, &ebx, &ecx, &edx);
if (!(ecx & FFL(MOVBE)))
return emulate_ud(ctxt);
switch (ctxt->op_bytes) {
case 2:
tmp = (u16)ctxt->src.val;
ctxt->dst.val &= ~0xffffUL;
ctxt->dst.val |= (unsigned long)swab16(tmp);
break;
case 4:
ctxt->dst.val = swab32((u32)ctxt->src.val);
break;
case 8:
ctxt->dst.val = swab64(ctxt->src.val);
break;
default:
BUG();
}
return X86EMUL_CONTINUE;
}
static int em_cr_write(struct x86_emulate_ctxt *ctxt)
{
if (ctxt->ops->set_cr(ctxt, ctxt->modrm_reg, ctxt->src.val))
return emulate_gp(ctxt, 0);
ctxt->dst.type = OP_NONE;
return X86EMUL_CONTINUE;
}
static int em_dr_write(struct x86_emulate_ctxt *ctxt)
{
unsigned long val;
if (ctxt->mode == X86EMUL_MODE_PROT64)
val = ctxt->src.val & ~0ULL;
else
val = ctxt->src.val & ~0U;
if (ctxt->ops->set_dr(ctxt, ctxt->modrm_reg, val) < 0)
return emulate_gp(ctxt, 0);
ctxt->dst.type = OP_NONE;
return X86EMUL_CONTINUE;
}
static int em_wrmsr(struct x86_emulate_ctxt *ctxt)
{
u64 msr_data;
msr_data = (u32)reg_read(ctxt, VCPU_REGS_RAX)
| ((u64)reg_read(ctxt, VCPU_REGS_RDX) << 32);
if (ctxt->ops->set_msr(ctxt, reg_read(ctxt, VCPU_REGS_RCX), msr_data))
return emulate_gp(ctxt, 0);
return X86EMUL_CONTINUE;
}
static int em_rdmsr(struct x86_emulate_ctxt *ctxt)
{
u64 msr_data;
if (ctxt->ops->get_msr(ctxt, reg_read(ctxt, VCPU_REGS_RCX), &msr_data))
return emulate_gp(ctxt, 0);
*reg_write(ctxt, VCPU_REGS_RAX) = (u32)msr_data;
*reg_write(ctxt, VCPU_REGS_RDX) = msr_data >> 32;
return X86EMUL_CONTINUE;
}
static int em_mov_rm_sreg(struct x86_emulate_ctxt *ctxt)
{
if (ctxt->modrm_reg > VCPU_SREG_GS)
return emulate_ud(ctxt);
ctxt->dst.val = get_segment_selector(ctxt, ctxt->modrm_reg);
if (ctxt->dst.bytes == 4 && ctxt->dst.type == OP_MEM)
ctxt->dst.bytes = 2;
return X86EMUL_CONTINUE;
}
static int em_mov_sreg_rm(struct x86_emulate_ctxt *ctxt)
{
u16 sel = ctxt->src.val;
if (ctxt->modrm_reg == VCPU_SREG_CS || ctxt->modrm_reg > VCPU_SREG_GS)
return emulate_ud(ctxt);
if (ctxt->modrm_reg == VCPU_SREG_SS)
ctxt->interruptibility = KVM_X86_SHADOW_INT_MOV_SS;
ctxt->dst.type = OP_NONE;
return load_segment_descriptor(ctxt, sel, ctxt->modrm_reg);
}
static int em_lldt(struct x86_emulate_ctxt *ctxt)
{
u16 sel = ctxt->src.val;
ctxt->dst.type = OP_NONE;
return load_segment_descriptor(ctxt, sel, VCPU_SREG_LDTR);
}
static int em_ltr(struct x86_emulate_ctxt *ctxt)
{
u16 sel = ctxt->src.val;
ctxt->dst.type = OP_NONE;
return load_segment_descriptor(ctxt, sel, VCPU_SREG_TR);
}
static int em_invlpg(struct x86_emulate_ctxt *ctxt)
{
int rc;
ulong linear;
rc = linearize(ctxt, ctxt->src.addr.mem, 1, false, &linear);
if (rc == X86EMUL_CONTINUE)
ctxt->ops->invlpg(ctxt, linear);
ctxt->dst.type = OP_NONE;
return X86EMUL_CONTINUE;
}
static int em_clts(struct x86_emulate_ctxt *ctxt)
{
ulong cr0;
cr0 = ctxt->ops->get_cr(ctxt, 0);
cr0 &= ~X86_CR0_TS;
ctxt->ops->set_cr(ctxt, 0, cr0);
return X86EMUL_CONTINUE;
}
static int em_hypercall(struct x86_emulate_ctxt *ctxt)
{
int rc = ctxt->ops->fix_hypercall(ctxt);
if (rc != X86EMUL_CONTINUE)
return rc;
ctxt->_eip = ctxt->eip;
ctxt->dst.type = OP_NONE;
return X86EMUL_CONTINUE;
}
static int emulate_store_desc_ptr(struct x86_emulate_ctxt *ctxt,
void (*get)(struct x86_emulate_ctxt *ctxt,
struct desc_ptr *ptr))
{
struct desc_ptr desc_ptr;
if (ctxt->mode == X86EMUL_MODE_PROT64)
ctxt->op_bytes = 8;
get(ctxt, &desc_ptr);
if (ctxt->op_bytes == 2) {
ctxt->op_bytes = 4;
desc_ptr.address &= 0x00ffffff;
}
ctxt->dst.type = OP_NONE;
return segmented_write(ctxt, ctxt->dst.addr.mem,
&desc_ptr, 2 + ctxt->op_bytes);
}
static int em_sgdt(struct x86_emulate_ctxt *ctxt)
{
return emulate_store_desc_ptr(ctxt, ctxt->ops->get_gdt);
}
static int em_sidt(struct x86_emulate_ctxt *ctxt)
{
return emulate_store_desc_ptr(ctxt, ctxt->ops->get_idt);
}
static int em_lgdt_lidt(struct x86_emulate_ctxt *ctxt, bool lgdt)
{
struct desc_ptr desc_ptr;
int rc;
if (ctxt->mode == X86EMUL_MODE_PROT64)
ctxt->op_bytes = 8;
rc = read_descriptor(ctxt, ctxt->src.addr.mem,
&desc_ptr.size, &desc_ptr.address,
ctxt->op_bytes);
if (rc != X86EMUL_CONTINUE)
return rc;
if (ctxt->mode == X86EMUL_MODE_PROT64 &&
is_noncanonical_address(desc_ptr.address))
return emulate_gp(ctxt, 0);
if (lgdt)
ctxt->ops->set_gdt(ctxt, &desc_ptr);
else
ctxt->ops->set_idt(ctxt, &desc_ptr);
ctxt->dst.type = OP_NONE;
return X86EMUL_CONTINUE;
}
static int em_lgdt(struct x86_emulate_ctxt *ctxt)
{
return em_lgdt_lidt(ctxt, true);
}
static int em_lidt(struct x86_emulate_ctxt *ctxt)
{
return em_lgdt_lidt(ctxt, false);
}
static int em_smsw(struct x86_emulate_ctxt *ctxt)
{
if (ctxt->dst.type == OP_MEM)
ctxt->dst.bytes = 2;
ctxt->dst.val = ctxt->ops->get_cr(ctxt, 0);
return X86EMUL_CONTINUE;
}
static int em_lmsw(struct x86_emulate_ctxt *ctxt)
{
ctxt->ops->set_cr(ctxt, 0, (ctxt->ops->get_cr(ctxt, 0) & ~0x0eul)
| (ctxt->src.val & 0x0f));
ctxt->dst.type = OP_NONE;
return X86EMUL_CONTINUE;
}
static int em_loop(struct x86_emulate_ctxt *ctxt)
{
int rc = X86EMUL_CONTINUE;
register_address_increment(ctxt, VCPU_REGS_RCX, -1);
if ((address_mask(ctxt, reg_read(ctxt, VCPU_REGS_RCX)) != 0) &&
(ctxt->b == 0xe2 || test_cc(ctxt->b ^ 0x5, ctxt->eflags)))
rc = jmp_rel(ctxt, ctxt->src.val);
return rc;
}
static int em_jcxz(struct x86_emulate_ctxt *ctxt)
{
int rc = X86EMUL_CONTINUE;
if (address_mask(ctxt, reg_read(ctxt, VCPU_REGS_RCX)) == 0)
rc = jmp_rel(ctxt, ctxt->src.val);
return rc;
}
static int em_in(struct x86_emulate_ctxt *ctxt)
{
if (!pio_in_emulated(ctxt, ctxt->dst.bytes, ctxt->src.val,
&ctxt->dst.val))
return X86EMUL_IO_NEEDED;
return X86EMUL_CONTINUE;
}
static int em_out(struct x86_emulate_ctxt *ctxt)
{
ctxt->ops->pio_out_emulated(ctxt, ctxt->src.bytes, ctxt->dst.val,
&ctxt->src.val, 1);
ctxt->dst.type = OP_NONE;
return X86EMUL_CONTINUE;
}
static int em_cli(struct x86_emulate_ctxt *ctxt)
{
if (emulator_bad_iopl(ctxt))
return emulate_gp(ctxt, 0);
ctxt->eflags &= ~X86_EFLAGS_IF;
return X86EMUL_CONTINUE;
}
static int em_sti(struct x86_emulate_ctxt *ctxt)
{
if (emulator_bad_iopl(ctxt))
return emulate_gp(ctxt, 0);
ctxt->interruptibility = KVM_X86_SHADOW_INT_STI;
ctxt->eflags |= X86_EFLAGS_IF;
return X86EMUL_CONTINUE;
}
static int em_cpuid(struct x86_emulate_ctxt *ctxt)
{
u32 eax, ebx, ecx, edx;
eax = reg_read(ctxt, VCPU_REGS_RAX);
ecx = reg_read(ctxt, VCPU_REGS_RCX);
ctxt->ops->get_cpuid(ctxt, &eax, &ebx, &ecx, &edx);
*reg_write(ctxt, VCPU_REGS_RAX) = eax;
*reg_write(ctxt, VCPU_REGS_RBX) = ebx;
*reg_write(ctxt, VCPU_REGS_RCX) = ecx;
*reg_write(ctxt, VCPU_REGS_RDX) = edx;
return X86EMUL_CONTINUE;
}
static int em_sahf(struct x86_emulate_ctxt *ctxt)
{
u32 flags;
flags = X86_EFLAGS_CF | X86_EFLAGS_PF | X86_EFLAGS_AF | X86_EFLAGS_ZF |
X86_EFLAGS_SF;
flags &= *reg_rmw(ctxt, VCPU_REGS_RAX) >> 8;
ctxt->eflags &= ~0xffUL;
ctxt->eflags |= flags | X86_EFLAGS_FIXED;
return X86EMUL_CONTINUE;
}
static int em_lahf(struct x86_emulate_ctxt *ctxt)
{
*reg_rmw(ctxt, VCPU_REGS_RAX) &= ~0xff00UL;
*reg_rmw(ctxt, VCPU_REGS_RAX) |= (ctxt->eflags & 0xff) << 8;
return X86EMUL_CONTINUE;
}
static int em_bswap(struct x86_emulate_ctxt *ctxt)
{
switch (ctxt->op_bytes) {
#ifdef CONFIG_X86_64
case 8:
asm("bswap %0" : "+r"(ctxt->dst.val));
break;
#endif
default:
asm("bswap %0" : "+r"(*(u32 *)&ctxt->dst.val));
break;
}
return X86EMUL_CONTINUE;
}
static int em_clflush(struct x86_emulate_ctxt *ctxt)
{
return X86EMUL_CONTINUE;
}
static int em_movsxd(struct x86_emulate_ctxt *ctxt)
{
ctxt->dst.val = (s32) ctxt->src.val;
return X86EMUL_CONTINUE;
}
static bool valid_cr(int nr)
{
switch (nr) {
case 0:
case 2 ... 4:
case 8:
return true;
default:
return false;
}
}
static int check_cr_read(struct x86_emulate_ctxt *ctxt)
{
if (!valid_cr(ctxt->modrm_reg))
return emulate_ud(ctxt);
return X86EMUL_CONTINUE;
}
static int check_cr_write(struct x86_emulate_ctxt *ctxt)
{
u64 new_val = ctxt->src.val64;
int cr = ctxt->modrm_reg;
u64 efer = 0;
static u64 cr_reserved_bits[] = {
0xffffffff00000000ULL,
0, 0, 0,
CR4_RESERVED_BITS,
0, 0, 0,
CR8_RESERVED_BITS,
};
if (!valid_cr(cr))
return emulate_ud(ctxt);
if (new_val & cr_reserved_bits[cr])
return emulate_gp(ctxt, 0);
switch (cr) {
case 0: {
u64 cr4;
if (((new_val & X86_CR0_PG) && !(new_val & X86_CR0_PE)) ||
((new_val & X86_CR0_NW) && !(new_val & X86_CR0_CD)))
return emulate_gp(ctxt, 0);
cr4 = ctxt->ops->get_cr(ctxt, 4);
ctxt->ops->get_msr(ctxt, MSR_EFER, &efer);
if ((new_val & X86_CR0_PG) && (efer & EFER_LME) &&
!(cr4 & X86_CR4_PAE))
return emulate_gp(ctxt, 0);
break;
}
case 3: {
u64 rsvd = 0;
ctxt->ops->get_msr(ctxt, MSR_EFER, &efer);
if (efer & EFER_LMA)
rsvd = CR3_L_MODE_RESERVED_BITS & ~CR3_PCID_INVD;
if (new_val & rsvd)
return emulate_gp(ctxt, 0);
break;
}
case 4: {
ctxt->ops->get_msr(ctxt, MSR_EFER, &efer);
if ((efer & EFER_LMA) && !(new_val & X86_CR4_PAE))
return emulate_gp(ctxt, 0);
break;
}
}
return X86EMUL_CONTINUE;
}
static int check_dr7_gd(struct x86_emulate_ctxt *ctxt)
{
unsigned long dr7;
ctxt->ops->get_dr(ctxt, 7, &dr7);
return dr7 & (1 << 13);
}
static int check_dr_read(struct x86_emulate_ctxt *ctxt)
{
int dr = ctxt->modrm_reg;
u64 cr4;
if (dr > 7)
return emulate_ud(ctxt);
cr4 = ctxt->ops->get_cr(ctxt, 4);
if ((cr4 & X86_CR4_DE) && (dr == 4 || dr == 5))
return emulate_ud(ctxt);
if (check_dr7_gd(ctxt)) {
ulong dr6;
ctxt->ops->get_dr(ctxt, 6, &dr6);
dr6 &= ~15;
dr6 |= DR6_BD | DR6_RTM;
ctxt->ops->set_dr(ctxt, 6, dr6);
return emulate_db(ctxt);
}
return X86EMUL_CONTINUE;
}
static int check_dr_write(struct x86_emulate_ctxt *ctxt)
{
u64 new_val = ctxt->src.val64;
int dr = ctxt->modrm_reg;
if ((dr == 6 || dr == 7) && (new_val & 0xffffffff00000000ULL))
return emulate_gp(ctxt, 0);
return check_dr_read(ctxt);
}
static int check_svme(struct x86_emulate_ctxt *ctxt)
{
u64 efer;
ctxt->ops->get_msr(ctxt, MSR_EFER, &efer);
if (!(efer & EFER_SVME))
return emulate_ud(ctxt);
return X86EMUL_CONTINUE;
}
static int check_svme_pa(struct x86_emulate_ctxt *ctxt)
{
u64 rax = reg_read(ctxt, VCPU_REGS_RAX);
if (rax & 0xffff000000000000ULL)
return emulate_gp(ctxt, 0);
return check_svme(ctxt);
}
static int check_rdtsc(struct x86_emulate_ctxt *ctxt)
{
u64 cr4 = ctxt->ops->get_cr(ctxt, 4);
if (cr4 & X86_CR4_TSD && ctxt->ops->cpl(ctxt))
return emulate_ud(ctxt);
return X86EMUL_CONTINUE;
}
static int check_rdpmc(struct x86_emulate_ctxt *ctxt)
{
u64 cr4 = ctxt->ops->get_cr(ctxt, 4);
u64 rcx = reg_read(ctxt, VCPU_REGS_RCX);
if ((!(cr4 & X86_CR4_PCE) && ctxt->ops->cpl(ctxt)) ||
ctxt->ops->check_pmc(ctxt, rcx))
return emulate_gp(ctxt, 0);
return X86EMUL_CONTINUE;
}
static int check_perm_in(struct x86_emulate_ctxt *ctxt)
{
ctxt->dst.bytes = min(ctxt->dst.bytes, 4u);
if (!emulator_io_permited(ctxt, ctxt->src.val, ctxt->dst.bytes))
return emulate_gp(ctxt, 0);
return X86EMUL_CONTINUE;
}
static int check_perm_out(struct x86_emulate_ctxt *ctxt)
{
ctxt->src.bytes = min(ctxt->src.bytes, 4u);
if (!emulator_io_permited(ctxt, ctxt->dst.val, ctxt->src.bytes))
return emulate_gp(ctxt, 0);
return X86EMUL_CONTINUE;
}
static unsigned imm_size(struct x86_emulate_ctxt *ctxt)
{
unsigned size;
size = (ctxt->d & ByteOp) ? 1 : ctxt->op_bytes;
if (size == 8)
size = 4;
return size;
}
static int decode_imm(struct x86_emulate_ctxt *ctxt, struct operand *op,
unsigned size, bool sign_extension)
{
int rc = X86EMUL_CONTINUE;
op->type = OP_IMM;
op->bytes = size;
op->addr.mem.ea = ctxt->_eip;
switch (op->bytes) {
case 1:
op->val = insn_fetch(s8, ctxt);
break;
case 2:
op->val = insn_fetch(s16, ctxt);
break;
case 4:
op->val = insn_fetch(s32, ctxt);
break;
case 8:
op->val = insn_fetch(s64, ctxt);
break;
}
if (!sign_extension) {
switch (op->bytes) {
case 1:
op->val &= 0xff;
break;
case 2:
op->val &= 0xffff;
break;
case 4:
op->val &= 0xffffffff;
break;
}
}
done:
return rc;
}
static int decode_operand(struct x86_emulate_ctxt *ctxt, struct operand *op,
unsigned d)
{
int rc = X86EMUL_CONTINUE;
switch (d) {
case OpReg:
decode_register_operand(ctxt, op);
break;
case OpImmUByte:
rc = decode_imm(ctxt, op, 1, false);
break;
case OpMem:
ctxt->memop.bytes = (ctxt->d & ByteOp) ? 1 : ctxt->op_bytes;
mem_common:
*op = ctxt->memop;
ctxt->memopp = op;
if (ctxt->d & BitOp)
fetch_bit_operand(ctxt);
op->orig_val = op->val;
break;
case OpMem64:
ctxt->memop.bytes = (ctxt->op_bytes == 8) ? 16 : 8;
goto mem_common;
case OpAcc:
op->type = OP_REG;
op->bytes = (ctxt->d & ByteOp) ? 1 : ctxt->op_bytes;
op->addr.reg = reg_rmw(ctxt, VCPU_REGS_RAX);
fetch_register_operand(op);
op->orig_val = op->val;
break;
case OpAccLo:
op->type = OP_REG;
op->bytes = (ctxt->d & ByteOp) ? 2 : ctxt->op_bytes;
op->addr.reg = reg_rmw(ctxt, VCPU_REGS_RAX);
fetch_register_operand(op);
op->orig_val = op->val;
break;
case OpAccHi:
if (ctxt->d & ByteOp) {
op->type = OP_NONE;
break;
}
op->type = OP_REG;
op->bytes = ctxt->op_bytes;
op->addr.reg = reg_rmw(ctxt, VCPU_REGS_RDX);
fetch_register_operand(op);
op->orig_val = op->val;
break;
case OpDI:
op->type = OP_MEM;
op->bytes = (ctxt->d & ByteOp) ? 1 : ctxt->op_bytes;
op->addr.mem.ea =
register_address(ctxt, VCPU_REGS_RDI);
op->addr.mem.seg = VCPU_SREG_ES;
op->val = 0;
op->count = 1;
break;
case OpDX:
op->type = OP_REG;
op->bytes = 2;
op->addr.reg = reg_rmw(ctxt, VCPU_REGS_RDX);
fetch_register_operand(op);
break;
case OpCL:
op->type = OP_IMM;
op->bytes = 1;
op->val = reg_read(ctxt, VCPU_REGS_RCX) & 0xff;
break;
case OpImmByte:
rc = decode_imm(ctxt, op, 1, true);
break;
case OpOne:
op->type = OP_IMM;
op->bytes = 1;
op->val = 1;
break;
case OpImm:
rc = decode_imm(ctxt, op, imm_size(ctxt), true);
break;
case OpImm64:
rc = decode_imm(ctxt, op, ctxt->op_bytes, true);
break;
case OpMem8:
ctxt->memop.bytes = 1;
if (ctxt->memop.type == OP_REG) {
ctxt->memop.addr.reg = decode_register(ctxt,
ctxt->modrm_rm, true);
fetch_register_operand(&ctxt->memop);
}
goto mem_common;
case OpMem16:
ctxt->memop.bytes = 2;
goto mem_common;
case OpMem32:
ctxt->memop.bytes = 4;
goto mem_common;
case OpImmU16:
rc = decode_imm(ctxt, op, 2, false);
break;
case OpImmU:
rc = decode_imm(ctxt, op, imm_size(ctxt), false);
break;
case OpSI:
op->type = OP_MEM;
op->bytes = (ctxt->d & ByteOp) ? 1 : ctxt->op_bytes;
op->addr.mem.ea =
register_address(ctxt, VCPU_REGS_RSI);
op->addr.mem.seg = ctxt->seg_override;
op->val = 0;
op->count = 1;
break;
case OpXLat:
op->type = OP_MEM;
op->bytes = (ctxt->d & ByteOp) ? 1 : ctxt->op_bytes;
op->addr.mem.ea =
address_mask(ctxt,
reg_read(ctxt, VCPU_REGS_RBX) +
(reg_read(ctxt, VCPU_REGS_RAX) & 0xff));
op->addr.mem.seg = ctxt->seg_override;
op->val = 0;
break;
case OpImmFAddr:
op->type = OP_IMM;
op->addr.mem.ea = ctxt->_eip;
op->bytes = ctxt->op_bytes + 2;
insn_fetch_arr(op->valptr, op->bytes, ctxt);
break;
case OpMemFAddr:
ctxt->memop.bytes = ctxt->op_bytes + 2;
goto mem_common;
case OpES:
op->type = OP_IMM;
op->val = VCPU_SREG_ES;
break;
case OpCS:
op->type = OP_IMM;
op->val = VCPU_SREG_CS;
break;
case OpSS:
op->type = OP_IMM;
op->val = VCPU_SREG_SS;
break;
case OpDS:
op->type = OP_IMM;
op->val = VCPU_SREG_DS;
break;
case OpFS:
op->type = OP_IMM;
op->val = VCPU_SREG_FS;
break;
case OpGS:
op->type = OP_IMM;
op->val = VCPU_SREG_GS;
break;
case OpImplicit:
default:
op->type = OP_NONE;
break;
}
done:
return rc;
}
int x86_decode_insn(struct x86_emulate_ctxt *ctxt, void *insn, int insn_len)
{
int rc = X86EMUL_CONTINUE;
int mode = ctxt->mode;
int def_op_bytes, def_ad_bytes, goffset, simd_prefix;
bool op_prefix = false;
bool has_seg_override = false;
struct opcode opcode;
ctxt->memop.type = OP_NONE;
ctxt->memopp = NULL;
ctxt->_eip = ctxt->eip;
ctxt->fetch.ptr = ctxt->fetch.data;
ctxt->fetch.end = ctxt->fetch.data + insn_len;
ctxt->opcode_len = 1;
if (insn_len > 0)
memcpy(ctxt->fetch.data, insn, insn_len);
else {
rc = __do_insn_fetch_bytes(ctxt, 1);
if (rc != X86EMUL_CONTINUE)
return rc;
}
switch (mode) {
case X86EMUL_MODE_REAL:
case X86EMUL_MODE_VM86:
case X86EMUL_MODE_PROT16:
def_op_bytes = def_ad_bytes = 2;
break;
case X86EMUL_MODE_PROT32:
def_op_bytes = def_ad_bytes = 4;
break;
#ifdef CONFIG_X86_64
case X86EMUL_MODE_PROT64:
def_op_bytes = 4;
def_ad_bytes = 8;
break;
#endif
default:
return EMULATION_FAILED;
}
ctxt->op_bytes = def_op_bytes;
ctxt->ad_bytes = def_ad_bytes;
for (;;) {
switch (ctxt->b = insn_fetch(u8, ctxt)) {
case 0x66:
op_prefix = true;
ctxt->op_bytes = def_op_bytes ^ 6;
break;
case 0x67:
if (mode == X86EMUL_MODE_PROT64)
ctxt->ad_bytes = def_ad_bytes ^ 12;
else
ctxt->ad_bytes = def_ad_bytes ^ 6;
break;
case 0x26:
case 0x2e:
case 0x36:
case 0x3e:
has_seg_override = true;
ctxt->seg_override = (ctxt->b >> 3) & 3;
break;
case 0x64:
case 0x65:
has_seg_override = true;
ctxt->seg_override = ctxt->b & 7;
break;
case 0x40 ... 0x4f:
if (mode != X86EMUL_MODE_PROT64)
goto done_prefixes;
ctxt->rex_prefix = ctxt->b;
continue;
case 0xf0:
ctxt->lock_prefix = 1;
break;
case 0xf2:
case 0xf3:
ctxt->rep_prefix = ctxt->b;
break;
default:
goto done_prefixes;
}
ctxt->rex_prefix = 0;
}
done_prefixes:
if (ctxt->rex_prefix & 8)
ctxt->op_bytes = 8;
opcode = opcode_table[ctxt->b];
if (ctxt->b == 0x0f) {
ctxt->opcode_len = 2;
ctxt->b = insn_fetch(u8, ctxt);
opcode = twobyte_table[ctxt->b];
if (ctxt->b == 0x38) {
ctxt->opcode_len = 3;
ctxt->b = insn_fetch(u8, ctxt);
opcode = opcode_map_0f_38[ctxt->b];
}
}
ctxt->d = opcode.flags;
if (ctxt->d & ModRM)
ctxt->modrm = insn_fetch(u8, ctxt);
if (ctxt->opcode_len == 1 && (ctxt->b == 0xc5 || ctxt->b == 0xc4) &&
(mode == X86EMUL_MODE_PROT64 || (ctxt->modrm & 0xc0) == 0xc0)) {
ctxt->d = NotImpl;
}
while (ctxt->d & GroupMask) {
switch (ctxt->d & GroupMask) {
case Group:
goffset = (ctxt->modrm >> 3) & 7;
opcode = opcode.u.group[goffset];
break;
case GroupDual:
goffset = (ctxt->modrm >> 3) & 7;
if ((ctxt->modrm >> 6) == 3)
opcode = opcode.u.gdual->mod3[goffset];
else
opcode = opcode.u.gdual->mod012[goffset];
break;
case RMExt:
goffset = ctxt->modrm & 7;
opcode = opcode.u.group[goffset];
break;
case Prefix:
if (ctxt->rep_prefix && op_prefix)
return EMULATION_FAILED;
simd_prefix = op_prefix ? 0x66 : ctxt->rep_prefix;
switch (simd_prefix) {
case 0x00: opcode = opcode.u.gprefix->pfx_no; break;
case 0x66: opcode = opcode.u.gprefix->pfx_66; break;
case 0xf2: opcode = opcode.u.gprefix->pfx_f2; break;
case 0xf3: opcode = opcode.u.gprefix->pfx_f3; break;
}
break;
case Escape:
if (ctxt->modrm > 0xbf)
opcode = opcode.u.esc->high[ctxt->modrm - 0xc0];
else
opcode = opcode.u.esc->op[(ctxt->modrm >> 3) & 7];
break;
case InstrDual:
if ((ctxt->modrm >> 6) == 3)
opcode = opcode.u.idual->mod3;
else
opcode = opcode.u.idual->mod012;
break;
case ModeDual:
if (ctxt->mode == X86EMUL_MODE_PROT64)
opcode = opcode.u.mdual->mode64;
else
opcode = opcode.u.mdual->mode32;
break;
default:
return EMULATION_FAILED;
}
ctxt->d &= ~(u64)GroupMask;
ctxt->d |= opcode.flags;
}
if (ctxt->d == 0)
return EMULATION_FAILED;
ctxt->execute = opcode.u.execute;
if (unlikely(ctxt->ud) && likely(!(ctxt->d & EmulateOnUD)))
return EMULATION_FAILED;
if (unlikely(ctxt->d &
(NotImpl|Stack|Op3264|Sse|Mmx|Intercept|CheckPerm|NearBranch|
No16))) {
ctxt->check_perm = opcode.check_perm;
ctxt->intercept = opcode.intercept;
if (ctxt->d & NotImpl)
return EMULATION_FAILED;
if (mode == X86EMUL_MODE_PROT64) {
if (ctxt->op_bytes == 4 && (ctxt->d & Stack))
ctxt->op_bytes = 8;
else if (ctxt->d & NearBranch)
ctxt->op_bytes = 8;
}
if (ctxt->d & Op3264) {
if (mode == X86EMUL_MODE_PROT64)
ctxt->op_bytes = 8;
else
ctxt->op_bytes = 4;
}
if ((ctxt->d & No16) && ctxt->op_bytes == 2)
ctxt->op_bytes = 4;
if (ctxt->d & Sse)
ctxt->op_bytes = 16;
else if (ctxt->d & Mmx)
ctxt->op_bytes = 8;
}
if (ctxt->d & ModRM) {
rc = decode_modrm(ctxt, &ctxt->memop);
if (!has_seg_override) {
has_seg_override = true;
ctxt->seg_override = ctxt->modrm_seg;
}
} else if (ctxt->d & MemAbs)
rc = decode_abs(ctxt, &ctxt->memop);
if (rc != X86EMUL_CONTINUE)
goto done;
if (!has_seg_override)
ctxt->seg_override = VCPU_SREG_DS;
ctxt->memop.addr.mem.seg = ctxt->seg_override;
rc = decode_operand(ctxt, &ctxt->src, (ctxt->d >> SrcShift) & OpMask);
if (rc != X86EMUL_CONTINUE)
goto done;
rc = decode_operand(ctxt, &ctxt->src2, (ctxt->d >> Src2Shift) & OpMask);
if (rc != X86EMUL_CONTINUE)
goto done;
rc = decode_operand(ctxt, &ctxt->dst, (ctxt->d >> DstShift) & OpMask);
if (ctxt->rip_relative)
ctxt->memopp->addr.mem.ea = address_mask(ctxt,
ctxt->memopp->addr.mem.ea + ctxt->_eip);
done:
return (rc != X86EMUL_CONTINUE) ? EMULATION_FAILED : EMULATION_OK;
}
bool x86_page_table_writing_insn(struct x86_emulate_ctxt *ctxt)
{
return ctxt->d & PageTable;
}
static bool string_insn_completed(struct x86_emulate_ctxt *ctxt)
{
if (((ctxt->b == 0xa6) || (ctxt->b == 0xa7) ||
(ctxt->b == 0xae) || (ctxt->b == 0xaf))
&& (((ctxt->rep_prefix == REPE_PREFIX) &&
((ctxt->eflags & X86_EFLAGS_ZF) == 0))
|| ((ctxt->rep_prefix == REPNE_PREFIX) &&
((ctxt->eflags & X86_EFLAGS_ZF) == X86_EFLAGS_ZF))))
return true;
return false;
}
static int flush_pending_x87_faults(struct x86_emulate_ctxt *ctxt)
{
bool fault = false;
ctxt->ops->get_fpu(ctxt);
asm volatile("1: fwait \n\t"
"2: \n\t"
".pushsection .fixup,\"ax\" \n\t"
"3: \n\t"
"movb $1, %[fault] \n\t"
"jmp 2b \n\t"
".popsection \n\t"
_ASM_EXTABLE(1b, 3b)
: [fault]"+qm"(fault));
ctxt->ops->put_fpu(ctxt);
if (unlikely(fault))
return emulate_exception(ctxt, MF_VECTOR, 0, false);
return X86EMUL_CONTINUE;
}
static void fetch_possible_mmx_operand(struct x86_emulate_ctxt *ctxt,
struct operand *op)
{
if (op->type == OP_MM)
read_mmx_reg(ctxt, &op->mm_val, op->addr.mm);
}
static int fastop(struct x86_emulate_ctxt *ctxt, void (*fop)(struct fastop *))
{
ulong flags = (ctxt->eflags & EFLAGS_MASK) | X86_EFLAGS_IF;
if (!(ctxt->d & ByteOp))
fop += __ffs(ctxt->dst.bytes) * FASTOP_SIZE;
asm("push %[flags]; popf; call *%[fastop]; pushf; pop %[flags]\n"
: "+a"(ctxt->dst.val), "+d"(ctxt->src.val), [flags]"+D"(flags),
[fastop]"+S"(fop)
: "c"(ctxt->src2.val));
ctxt->eflags = (ctxt->eflags & ~EFLAGS_MASK) | (flags & EFLAGS_MASK);
if (!fop)
return emulate_de(ctxt);
return X86EMUL_CONTINUE;
}
void init_decode_cache(struct x86_emulate_ctxt *ctxt)
{
memset(&ctxt->rip_relative, 0,
(void *)&ctxt->modrm - (void *)&ctxt->rip_relative);
ctxt->io_read.pos = 0;
ctxt->io_read.end = 0;
ctxt->mem_read.end = 0;
}
int x86_emulate_insn(struct x86_emulate_ctxt *ctxt)
{
const struct x86_emulate_ops *ops = ctxt->ops;
int rc = X86EMUL_CONTINUE;
int saved_dst_type = ctxt->dst.type;
ctxt->mem_read.pos = 0;
if (ctxt->lock_prefix && (!(ctxt->d & Lock) || ctxt->dst.type != OP_MEM)) {
rc = emulate_ud(ctxt);
goto done;
}
if ((ctxt->d & SrcMask) == SrcMemFAddr && ctxt->src.type != OP_MEM) {
rc = emulate_ud(ctxt);
goto done;
}
if (unlikely(ctxt->d &
(No64|Undefined|Sse|Mmx|Intercept|CheckPerm|Priv|Prot|String))) {
if ((ctxt->mode == X86EMUL_MODE_PROT64 && (ctxt->d & No64)) ||
(ctxt->d & Undefined)) {
rc = emulate_ud(ctxt);
goto done;
}
if (((ctxt->d & (Sse|Mmx)) && ((ops->get_cr(ctxt, 0) & X86_CR0_EM)))
|| ((ctxt->d & Sse) && !(ops->get_cr(ctxt, 4) & X86_CR4_OSFXSR))) {
rc = emulate_ud(ctxt);
goto done;
}
if ((ctxt->d & (Sse|Mmx)) && (ops->get_cr(ctxt, 0) & X86_CR0_TS)) {
rc = emulate_nm(ctxt);
goto done;
}
if (ctxt->d & Mmx) {
rc = flush_pending_x87_faults(ctxt);
if (rc != X86EMUL_CONTINUE)
goto done;
fetch_possible_mmx_operand(ctxt, &ctxt->src);
fetch_possible_mmx_operand(ctxt, &ctxt->src2);
if (!(ctxt->d & Mov))
fetch_possible_mmx_operand(ctxt, &ctxt->dst);
}
if (unlikely(ctxt->emul_flags & X86EMUL_GUEST_MASK) && ctxt->intercept) {
rc = emulator_check_intercept(ctxt, ctxt->intercept,
X86_ICPT_PRE_EXCEPT);
if (rc != X86EMUL_CONTINUE)
goto done;
}
if ((ctxt->d & Prot) && ctxt->mode < X86EMUL_MODE_PROT16) {
rc = emulate_ud(ctxt);
goto done;
}
if ((ctxt->d & Priv) && ops->cpl(ctxt)) {
if (ctxt->d & PrivUD)
rc = emulate_ud(ctxt);
else
rc = emulate_gp(ctxt, 0);
goto done;
}
if (ctxt->d & CheckPerm) {
rc = ctxt->check_perm(ctxt);
if (rc != X86EMUL_CONTINUE)
goto done;
}
if (unlikely(ctxt->emul_flags & X86EMUL_GUEST_MASK) && (ctxt->d & Intercept)) {
rc = emulator_check_intercept(ctxt, ctxt->intercept,
X86_ICPT_POST_EXCEPT);
if (rc != X86EMUL_CONTINUE)
goto done;
}
if (ctxt->rep_prefix && (ctxt->d & String)) {
if (address_mask(ctxt, reg_read(ctxt, VCPU_REGS_RCX)) == 0) {
string_registers_quirk(ctxt);
ctxt->eip = ctxt->_eip;
ctxt->eflags &= ~X86_EFLAGS_RF;
goto done;
}
}
}
if ((ctxt->src.type == OP_MEM) && !(ctxt->d & NoAccess)) {
rc = segmented_read(ctxt, ctxt->src.addr.mem,
ctxt->src.valptr, ctxt->src.bytes);
if (rc != X86EMUL_CONTINUE)
goto done;
ctxt->src.orig_val64 = ctxt->src.val64;
}
if (ctxt->src2.type == OP_MEM) {
rc = segmented_read(ctxt, ctxt->src2.addr.mem,
&ctxt->src2.val, ctxt->src2.bytes);
if (rc != X86EMUL_CONTINUE)
goto done;
}
if ((ctxt->d & DstMask) == ImplicitOps)
goto special_insn;
if ((ctxt->dst.type == OP_MEM) && !(ctxt->d & Mov)) {
rc = segmented_read(ctxt, ctxt->dst.addr.mem,
&ctxt->dst.val, ctxt->dst.bytes);
if (rc != X86EMUL_CONTINUE) {
if (!(ctxt->d & NoWrite) &&
rc == X86EMUL_PROPAGATE_FAULT &&
ctxt->exception.vector == PF_VECTOR)
ctxt->exception.error_code |= PFERR_WRITE_MASK;
goto done;
}
}
ctxt->dst.orig_val64 = ctxt->dst.val64;
special_insn:
if (unlikely(ctxt->emul_flags & X86EMUL_GUEST_MASK) && (ctxt->d & Intercept)) {
rc = emulator_check_intercept(ctxt, ctxt->intercept,
X86_ICPT_POST_MEMACCESS);
if (rc != X86EMUL_CONTINUE)
goto done;
}
if (ctxt->rep_prefix && (ctxt->d & String))
ctxt->eflags |= X86_EFLAGS_RF;
else
ctxt->eflags &= ~X86_EFLAGS_RF;
if (ctxt->execute) {
if (ctxt->d & Fastop) {
void (*fop)(struct fastop *) = (void *)ctxt->execute;
rc = fastop(ctxt, fop);
if (rc != X86EMUL_CONTINUE)
goto done;
goto writeback;
}
rc = ctxt->execute(ctxt);
if (rc != X86EMUL_CONTINUE)
goto done;
goto writeback;
}
if (ctxt->opcode_len == 2)
goto twobyte_insn;
else if (ctxt->opcode_len == 3)
goto threebyte_insn;
switch (ctxt->b) {
case 0x70 ... 0x7f:
if (test_cc(ctxt->b, ctxt->eflags))
rc = jmp_rel(ctxt, ctxt->src.val);
break;
case 0x8d:
ctxt->dst.val = ctxt->src.addr.mem.ea;
break;
case 0x90 ... 0x97:
if (ctxt->dst.addr.reg == reg_rmw(ctxt, VCPU_REGS_RAX))
ctxt->dst.type = OP_NONE;
else
rc = em_xchg(ctxt);
break;
case 0x98:
switch (ctxt->op_bytes) {
case 2: ctxt->dst.val = (s8)ctxt->dst.val; break;
case 4: ctxt->dst.val = (s16)ctxt->dst.val; break;
case 8: ctxt->dst.val = (s32)ctxt->dst.val; break;
}
break;
case 0xcc:
rc = emulate_int(ctxt, 3);
break;
case 0xcd:
rc = emulate_int(ctxt, ctxt->src.val);
break;
case 0xce:
if (ctxt->eflags & X86_EFLAGS_OF)
rc = emulate_int(ctxt, 4);
break;
case 0xe9:
case 0xeb:
rc = jmp_rel(ctxt, ctxt->src.val);
ctxt->dst.type = OP_NONE;
break;
case 0xf4:
ctxt->ops->halt(ctxt);
break;
case 0xf5:
ctxt->eflags ^= X86_EFLAGS_CF;
break;
case 0xf8:
ctxt->eflags &= ~X86_EFLAGS_CF;
break;
case 0xf9:
ctxt->eflags |= X86_EFLAGS_CF;
break;
case 0xfc:
ctxt->eflags &= ~X86_EFLAGS_DF;
break;
case 0xfd:
ctxt->eflags |= X86_EFLAGS_DF;
break;
default:
goto cannot_emulate;
}
if (rc != X86EMUL_CONTINUE)
goto done;
writeback:
if (ctxt->d & SrcWrite) {
BUG_ON(ctxt->src.type == OP_MEM || ctxt->src.type == OP_MEM_STR);
rc = writeback(ctxt, &ctxt->src);
if (rc != X86EMUL_CONTINUE)
goto done;
}
if (!(ctxt->d & NoWrite)) {
rc = writeback(ctxt, &ctxt->dst);
if (rc != X86EMUL_CONTINUE)
goto done;
}
ctxt->dst.type = saved_dst_type;
if ((ctxt->d & SrcMask) == SrcSI)
string_addr_inc(ctxt, VCPU_REGS_RSI, &ctxt->src);
if ((ctxt->d & DstMask) == DstDI)
string_addr_inc(ctxt, VCPU_REGS_RDI, &ctxt->dst);
if (ctxt->rep_prefix && (ctxt->d & String)) {
unsigned int count;
struct read_cache *r = &ctxt->io_read;
if ((ctxt->d & SrcMask) == SrcSI)
count = ctxt->src.count;
else
count = ctxt->dst.count;
register_address_increment(ctxt, VCPU_REGS_RCX, -count);
if (!string_insn_completed(ctxt)) {
if ((r->end != 0 || reg_read(ctxt, VCPU_REGS_RCX) & 0x3ff) &&
(r->end == 0 || r->end != r->pos)) {
ctxt->mem_read.end = 0;
writeback_registers(ctxt);
return EMULATION_RESTART;
}
goto done;
}
ctxt->eflags &= ~X86_EFLAGS_RF;
}
ctxt->eip = ctxt->_eip;
done:
if (rc == X86EMUL_PROPAGATE_FAULT) {
WARN_ON(ctxt->exception.vector > 0x1f);
ctxt->have_exception = true;
}
if (rc == X86EMUL_INTERCEPTED)
return EMULATION_INTERCEPTED;
if (rc == X86EMUL_CONTINUE)
writeback_registers(ctxt);
return (rc == X86EMUL_UNHANDLEABLE) ? EMULATION_FAILED : EMULATION_OK;
twobyte_insn:
switch (ctxt->b) {
case 0x09:
(ctxt->ops->wbinvd)(ctxt);
break;
case 0x08:
case 0x0d:
case 0x18:
case 0x1f:
break;
case 0x20:
ctxt->dst.val = ops->get_cr(ctxt, ctxt->modrm_reg);
break;
case 0x21:
ops->get_dr(ctxt, ctxt->modrm_reg, &ctxt->dst.val);
break;
case 0x40 ... 0x4f:
if (test_cc(ctxt->b, ctxt->eflags))
ctxt->dst.val = ctxt->src.val;
else if (ctxt->op_bytes != 4)
ctxt->dst.type = OP_NONE;
break;
case 0x80 ... 0x8f:
if (test_cc(ctxt->b, ctxt->eflags))
rc = jmp_rel(ctxt, ctxt->src.val);
break;
case 0x90 ... 0x9f:
ctxt->dst.val = test_cc(ctxt->b, ctxt->eflags);
break;
case 0xb6 ... 0xb7:
ctxt->dst.bytes = ctxt->op_bytes;
ctxt->dst.val = (ctxt->src.bytes == 1) ? (u8) ctxt->src.val
: (u16) ctxt->src.val;
break;
case 0xbe ... 0xbf:
ctxt->dst.bytes = ctxt->op_bytes;
ctxt->dst.val = (ctxt->src.bytes == 1) ? (s8) ctxt->src.val :
(s16) ctxt->src.val;
break;
default:
goto cannot_emulate;
}
threebyte_insn:
if (rc != X86EMUL_CONTINUE)
goto done;
goto writeback;
cannot_emulate:
return EMULATION_FAILED;
}
void emulator_invalidate_register_cache(struct x86_emulate_ctxt *ctxt)
{
invalidate_registers(ctxt);
}
void emulator_writeback_register_cache(struct x86_emulate_ctxt *ctxt)
{
writeback_registers(ctxt);
}
