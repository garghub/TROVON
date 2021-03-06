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
.src_bytes = ctxt->src.bytes,
.dst_bytes = ctxt->dst.bytes,
.ad_bytes = ctxt->ad_bytes,
.next_rip = ctxt->eip,
};
return ctxt->ops->intercept(ctxt, &info, stage);
}
static inline unsigned long ad_mask(struct x86_emulate_ctxt *ctxt)
{
return (1UL << (ctxt->ad_bytes << 3)) - 1;
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
register_address(struct x86_emulate_ctxt *ctxt, unsigned long reg)
{
return address_mask(ctxt, reg);
}
static inline void
register_address_increment(struct x86_emulate_ctxt *ctxt, unsigned long *reg, int inc)
{
if (ctxt->ad_bytes == sizeof(unsigned long))
*reg += inc;
else
*reg = (*reg & ~ad_mask(ctxt)) | ((*reg + inc) & ad_mask(ctxt));
}
static inline void jmp_rel(struct x86_emulate_ctxt *ctxt, int rel)
{
register_address_increment(ctxt, &ctxt->_eip, rel);
}
static u32 desc_limit_scaled(struct desc_struct *desc)
{
u32 limit = get_desc_limit(desc);
return desc->g ? (limit << 12) | 0xfff : limit;
}
static void set_seg_override(struct x86_emulate_ctxt *ctxt, int seg)
{
ctxt->has_seg_override = true;
ctxt->seg_override = seg;
}
static unsigned long seg_base(struct x86_emulate_ctxt *ctxt, int seg)
{
if (ctxt->mode == X86EMUL_MODE_PROT64 && seg < VCPU_SREG_FS)
return 0;
return ctxt->ops->get_cached_segment_base(ctxt, seg);
}
static unsigned seg_override(struct x86_emulate_ctxt *ctxt)
{
if (!ctxt->has_seg_override)
return 0;
return ctxt->seg_override;
}
static int emulate_exception(struct x86_emulate_ctxt *ctxt, int vec,
u32 error, bool valid)
{
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
static int __linearize(struct x86_emulate_ctxt *ctxt,
struct segmented_address addr,
unsigned size, bool write, bool fetch,
ulong *linear)
{
struct desc_struct desc;
bool usable;
ulong la;
u32 lim;
u16 sel;
unsigned cpl, rpl;
la = seg_base(ctxt, addr.seg) + addr.ea;
switch (ctxt->mode) {
case X86EMUL_MODE_REAL:
break;
case X86EMUL_MODE_PROT64:
if (((signed long)la << 16) >> 16 != la)
return emulate_gp(ctxt, 0);
break;
default:
usable = ctxt->ops->get_segment(ctxt, &sel, &desc, NULL,
addr.seg);
if (!usable)
goto bad;
if (((desc.type & 8) || !(desc.type & 2)) && write)
goto bad;
if (!fetch && (desc.type & 8) && !(desc.type & 2))
goto bad;
lim = desc_limit_scaled(&desc);
if ((desc.type & 8) || !(desc.type & 4)) {
if (addr.ea > lim || (u32)(addr.ea + size - 1) > lim)
goto bad;
} else {
if (addr.ea <= lim || (u32)(addr.ea + size - 1) <= lim)
goto bad;
lim = desc.d ? 0xffffffff : 0xffff;
if (addr.ea > lim || (u32)(addr.ea + size - 1) > lim)
goto bad;
}
cpl = ctxt->ops->cpl(ctxt);
rpl = sel & 3;
cpl = max(cpl, rpl);
if (!(desc.type & 8)) {
if (cpl > desc.dpl)
goto bad;
} else if ((desc.type & 8) && !(desc.type & 4)) {
if (cpl != desc.dpl)
goto bad;
} else if ((desc.type & 8) && (desc.type & 4)) {
if (cpl < desc.dpl)
goto bad;
}
break;
}
if (fetch ? ctxt->mode != X86EMUL_MODE_PROT64 : ctxt->ad_bytes != 8)
la &= (u32)-1;
*linear = la;
return X86EMUL_CONTINUE;
bad:
if (addr.seg == VCPU_SREG_SS)
return emulate_ss(ctxt, addr.seg);
else
return emulate_gp(ctxt, addr.seg);
}
static int linearize(struct x86_emulate_ctxt *ctxt,
struct segmented_address addr,
unsigned size, bool write,
ulong *linear)
{
return __linearize(ctxt, addr, size, write, false, linear);
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
static int do_insn_fetch_byte(struct x86_emulate_ctxt *ctxt, u8 *dest)
{
struct fetch_cache *fc = &ctxt->fetch;
int rc;
int size, cur_size;
if (ctxt->_eip == fc->end) {
unsigned long linear;
struct segmented_address addr = { .seg = VCPU_SREG_CS,
.ea = ctxt->_eip };
cur_size = fc->end - fc->start;
size = min(15UL - cur_size,
PAGE_SIZE - offset_in_page(ctxt->_eip));
rc = __linearize(ctxt, addr, size, false, true, &linear);
if (unlikely(rc != X86EMUL_CONTINUE))
return rc;
rc = ctxt->ops->fetch(ctxt, linear, fc->data + cur_size,
size, &ctxt->exception);
if (unlikely(rc != X86EMUL_CONTINUE))
return rc;
fc->end += size;
}
*dest = fc->data[ctxt->_eip - fc->start];
ctxt->_eip++;
return X86EMUL_CONTINUE;
}
static int do_insn_fetch(struct x86_emulate_ctxt *ctxt,
void *dest, unsigned size)
{
int rc;
if (unlikely(ctxt->_eip + size - ctxt->eip > 15))
return X86EMUL_UNHANDLEABLE;
while (size--) {
rc = do_insn_fetch_byte(ctxt, dest++);
if (rc != X86EMUL_CONTINUE)
return rc;
}
return X86EMUL_CONTINUE;
}
static void *decode_register(u8 modrm_reg, unsigned long *regs,
int highbyte_regs)
{
void *p;
p = &regs[modrm_reg];
if (highbyte_regs && modrm_reg >= 4 && modrm_reg < 8)
p = (unsigned char *)&regs[modrm_reg & 3] + 1;
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
static int test_cc(unsigned int condition, unsigned int flags)
{
int rc = 0;
switch ((condition & 15) >> 1) {
case 0:
rc |= (flags & EFLG_OF);
break;
case 1:
rc |= (flags & EFLG_CF);
break;
case 2:
rc |= (flags & EFLG_ZF);
break;
case 3:
rc |= (flags & (EFLG_CF|EFLG_ZF));
break;
case 4:
rc |= (flags & EFLG_SF);
break;
case 5:
rc |= (flags & EFLG_PF);
break;
case 7:
rc |= (flags & EFLG_ZF);
case 6:
rc |= (!(flags & EFLG_SF) != !(flags & EFLG_OF));
break;
}
return (!!rc ^ (condition & 1));
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
case 0: asm("movdqu %%xmm0, %0" : "=m"(*data)); break;
case 1: asm("movdqu %%xmm1, %0" : "=m"(*data)); break;
case 2: asm("movdqu %%xmm2, %0" : "=m"(*data)); break;
case 3: asm("movdqu %%xmm3, %0" : "=m"(*data)); break;
case 4: asm("movdqu %%xmm4, %0" : "=m"(*data)); break;
case 5: asm("movdqu %%xmm5, %0" : "=m"(*data)); break;
case 6: asm("movdqu %%xmm6, %0" : "=m"(*data)); break;
case 7: asm("movdqu %%xmm7, %0" : "=m"(*data)); break;
#ifdef CONFIG_X86_64
case 8: asm("movdqu %%xmm8, %0" : "=m"(*data)); break;
case 9: asm("movdqu %%xmm9, %0" : "=m"(*data)); break;
case 10: asm("movdqu %%xmm10, %0" : "=m"(*data)); break;
case 11: asm("movdqu %%xmm11, %0" : "=m"(*data)); break;
case 12: asm("movdqu %%xmm12, %0" : "=m"(*data)); break;
case 13: asm("movdqu %%xmm13, %0" : "=m"(*data)); break;
case 14: asm("movdqu %%xmm14, %0" : "=m"(*data)); break;
case 15: asm("movdqu %%xmm15, %0" : "=m"(*data)); break;
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
case 0: asm("movdqu %0, %%xmm0" : : "m"(*data)); break;
case 1: asm("movdqu %0, %%xmm1" : : "m"(*data)); break;
case 2: asm("movdqu %0, %%xmm2" : : "m"(*data)); break;
case 3: asm("movdqu %0, %%xmm3" : : "m"(*data)); break;
case 4: asm("movdqu %0, %%xmm4" : : "m"(*data)); break;
case 5: asm("movdqu %0, %%xmm5" : : "m"(*data)); break;
case 6: asm("movdqu %0, %%xmm6" : : "m"(*data)); break;
case 7: asm("movdqu %0, %%xmm7" : : "m"(*data)); break;
#ifdef CONFIG_X86_64
case 8: asm("movdqu %0, %%xmm8" : : "m"(*data)); break;
case 9: asm("movdqu %0, %%xmm9" : : "m"(*data)); break;
case 10: asm("movdqu %0, %%xmm10" : : "m"(*data)); break;
case 11: asm("movdqu %0, %%xmm11" : : "m"(*data)); break;
case 12: asm("movdqu %0, %%xmm12" : : "m"(*data)); break;
case 13: asm("movdqu %0, %%xmm13" : : "m"(*data)); break;
case 14: asm("movdqu %0, %%xmm14" : : "m"(*data)); break;
case 15: asm("movdqu %0, %%xmm15" : : "m"(*data)); break;
#endif
default: BUG();
}
ctxt->ops->put_fpu(ctxt);
}
static void decode_register_operand(struct x86_emulate_ctxt *ctxt,
struct operand *op)
{
unsigned reg = ctxt->modrm_reg;
int highbyte_regs = ctxt->rex_prefix == 0;
if (!(ctxt->d & ModRM))
reg = (ctxt->b & 7) | ((ctxt->rex_prefix & 1) << 3);
if (ctxt->d & Sse) {
op->type = OP_XMM;
op->bytes = 16;
op->addr.xmm = reg;
read_sse_reg(ctxt, &op->vec_val, reg);
return;
}
op->type = OP_REG;
if (ctxt->d & ByteOp) {
op->addr.reg = decode_register(reg, ctxt->regs, highbyte_regs);
op->bytes = 1;
} else {
op->addr.reg = decode_register(reg, ctxt->regs, 0);
op->bytes = ctxt->op_bytes;
}
fetch_register_operand(op);
op->orig_val = op->val;
}
static int decode_modrm(struct x86_emulate_ctxt *ctxt,
struct operand *op)
{
u8 sib;
int index_reg = 0, base_reg = 0, scale;
int rc = X86EMUL_CONTINUE;
ulong modrm_ea = 0;
if (ctxt->rex_prefix) {
ctxt->modrm_reg = (ctxt->rex_prefix & 4) << 1;
index_reg = (ctxt->rex_prefix & 2) << 2;
ctxt->modrm_rm = base_reg = (ctxt->rex_prefix & 1) << 3;
}
ctxt->modrm = insn_fetch(u8, ctxt);
ctxt->modrm_mod |= (ctxt->modrm & 0xc0) >> 6;
ctxt->modrm_reg |= (ctxt->modrm & 0x38) >> 3;
ctxt->modrm_rm |= (ctxt->modrm & 0x07);
ctxt->modrm_seg = VCPU_SREG_DS;
if (ctxt->modrm_mod == 3) {
op->type = OP_REG;
op->bytes = (ctxt->d & ByteOp) ? 1 : ctxt->op_bytes;
op->addr.reg = decode_register(ctxt->modrm_rm,
ctxt->regs, ctxt->d & ByteOp);
if (ctxt->d & Sse) {
op->type = OP_XMM;
op->bytes = 16;
op->addr.xmm = ctxt->modrm_rm;
read_sse_reg(ctxt, &op->vec_val, ctxt->modrm_rm);
return rc;
}
fetch_register_operand(op);
return rc;
}
op->type = OP_MEM;
if (ctxt->ad_bytes == 2) {
unsigned bx = ctxt->regs[VCPU_REGS_RBX];
unsigned bp = ctxt->regs[VCPU_REGS_RBP];
unsigned si = ctxt->regs[VCPU_REGS_RSI];
unsigned di = ctxt->regs[VCPU_REGS_RDI];
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
else
modrm_ea += ctxt->regs[base_reg];
if (index_reg != 4)
modrm_ea += ctxt->regs[index_reg] << scale;
} else if ((ctxt->modrm_rm & 7) == 5 && ctxt->modrm_mod == 0) {
if (ctxt->mode == X86EMUL_MODE_PROT64)
ctxt->rip_relative = 1;
} else
modrm_ea += ctxt->regs[ctxt->modrm_rm];
switch (ctxt->modrm_mod) {
case 0:
if (ctxt->modrm_rm == 5)
modrm_ea += insn_fetch(s32, ctxt);
break;
case 1:
modrm_ea += insn_fetch(s8, ctxt);
break;
case 2:
modrm_ea += insn_fetch(s32, ctxt);
break;
}
}
op->addr.mem.ea = modrm_ea;
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
mask = ~(ctxt->dst.bytes * 8 - 1);
if (ctxt->src.bytes == 2)
sv = (s16)ctxt->src.val & (s16)mask;
else if (ctxt->src.bytes == 4)
sv = (s32)ctxt->src.val & (s32)mask;
ctxt->dst.addr.mem.ea += (sv >> 3);
}
ctxt->src.val &= (ctxt->dst.bytes << 3) - 1;
}
static int read_emulated(struct x86_emulate_ctxt *ctxt,
unsigned long addr, void *dest, unsigned size)
{
int rc;
struct read_cache *mc = &ctxt->mem_read;
while (size) {
int n = min(size, 8u);
size -= n;
if (mc->pos < mc->end)
goto read_cached;
rc = ctxt->ops->read_emulated(ctxt, addr, mc->data + mc->end, n,
&ctxt->exception);
if (rc != X86EMUL_CONTINUE)
return rc;
mc->end += n;
read_cached:
memcpy(dest, mc->data + mc->pos, n);
mc->pos += n;
dest += n;
addr += n;
}
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
address_mask(ctxt, ctxt->regs[VCPU_REGS_RCX]) : 1;
in_page = (ctxt->eflags & EFLG_DF) ?
offset_in_page(ctxt->regs[VCPU_REGS_RDI]) :
PAGE_SIZE - offset_in_page(ctxt->regs[VCPU_REGS_RDI]);
n = min(min(in_page, (unsigned int)sizeof(rc->data)) / size,
count);
if (n == 0)
n = 1;
rc->pos = rc->end = 0;
if (!ctxt->ops->pio_in_emulated(ctxt, size, port, rc->data, n))
return 0;
rc->end = n * size;
}
memcpy(dest, rc->data + rc->pos, size);
rc->pos += size;
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
struct x86_emulate_ops *ops = ctxt->ops;
if (selector & 1 << 2) {
struct desc_struct desc;
u16 sel;
memset (dt, 0, sizeof *dt);
if (!ops->get_segment(ctxt, &sel, &desc, NULL, VCPU_SREG_LDTR))
return;
dt->size = desc_limit_scaled(&desc);
dt->address = get_desc_base(&desc);
} else
ops->get_gdt(ctxt, dt);
}
static int read_segment_descriptor(struct x86_emulate_ctxt *ctxt,
u16 selector, struct desc_struct *desc)
{
struct desc_ptr dt;
u16 index = selector >> 3;
ulong addr;
get_descriptor_table_ptr(ctxt, selector, &dt);
if (dt.size < index * 8 + 7)
return emulate_gp(ctxt, selector & 0xfffc);
addr = dt.address + index * 8;
return ctxt->ops->read_std(ctxt, addr, desc, sizeof *desc,
&ctxt->exception);
}
static int write_segment_descriptor(struct x86_emulate_ctxt *ctxt,
u16 selector, struct desc_struct *desc)
{
struct desc_ptr dt;
u16 index = selector >> 3;
ulong addr;
get_descriptor_table_ptr(ctxt, selector, &dt);
if (dt.size < index * 8 + 7)
return emulate_gp(ctxt, selector & 0xfffc);
addr = dt.address + index * 8;
return ctxt->ops->write_std(ctxt, addr, desc, sizeof *desc,
&ctxt->exception);
}
static int load_segment_descriptor(struct x86_emulate_ctxt *ctxt,
u16 selector, int seg)
{
struct desc_struct seg_desc;
u8 dpl, rpl, cpl;
unsigned err_vec = GP_VECTOR;
u32 err_code = 0;
bool null_selector = !(selector & ~0x3);
int ret;
memset(&seg_desc, 0, sizeof seg_desc);
if ((seg <= VCPU_SREG_GS && ctxt->mode == X86EMUL_MODE_VM86)
|| ctxt->mode == X86EMUL_MODE_REAL) {
set_desc_base(&seg_desc, selector << 4);
set_desc_limit(&seg_desc, 0xffff);
seg_desc.type = 3;
seg_desc.p = 1;
seg_desc.s = 1;
if (ctxt->mode == X86EMUL_MODE_VM86)
seg_desc.dpl = 3;
goto load;
}
if ((seg == VCPU_SREG_CS || seg == VCPU_SREG_SS || seg == VCPU_SREG_TR)
&& null_selector)
goto exception;
if (seg == VCPU_SREG_TR && (selector & (1 << 2)))
goto exception;
if (null_selector)
goto load;
ret = read_segment_descriptor(ctxt, selector, &seg_desc);
if (ret != X86EMUL_CONTINUE)
return ret;
err_code = selector & 0xfffc;
err_vec = GP_VECTOR;
if (seg <= VCPU_SREG_GS && !seg_desc.s)
goto exception;
if (!seg_desc.p) {
err_vec = (seg == VCPU_SREG_SS) ? SS_VECTOR : NP_VECTOR;
goto exception;
}
rpl = selector & 3;
dpl = seg_desc.dpl;
cpl = ctxt->ops->cpl(ctxt);
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
selector = (selector & 0xfffc) | cpl;
break;
case VCPU_SREG_TR:
if (seg_desc.s || (seg_desc.type != 1 && seg_desc.type != 9))
goto exception;
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
seg_desc.type |= 1;
ret = write_segment_descriptor(ctxt, selector, &seg_desc);
if (ret != X86EMUL_CONTINUE)
return ret;
}
load:
ctxt->ops->set_segment(ctxt, selector, &seg_desc, 0, seg);
return X86EMUL_CONTINUE;
exception:
emulate_exception(ctxt, err_vec, err_code, true);
return X86EMUL_PROPAGATE_FAULT;
}
static void write_register_operand(struct operand *op)
{
switch (op->bytes) {
case 1:
*(u8 *)op->addr.reg = (u8)op->val;
break;
case 2:
*(u16 *)op->addr.reg = (u16)op->val;
break;
case 4:
*op->addr.reg = (u32)op->val;
break;
case 8:
*op->addr.reg = op->val;
break;
}
}
static int writeback(struct x86_emulate_ctxt *ctxt)
{
int rc;
switch (ctxt->dst.type) {
case OP_REG:
write_register_operand(&ctxt->dst);
break;
case OP_MEM:
if (ctxt->lock_prefix)
rc = segmented_cmpxchg(ctxt,
ctxt->dst.addr.mem,
&ctxt->dst.orig_val,
&ctxt->dst.val,
ctxt->dst.bytes);
else
rc = segmented_write(ctxt,
ctxt->dst.addr.mem,
&ctxt->dst.val,
ctxt->dst.bytes);
if (rc != X86EMUL_CONTINUE)
return rc;
break;
case OP_XMM:
write_sse_reg(ctxt, &ctxt->dst.vec_val, ctxt->dst.addr.xmm);
break;
case OP_NONE:
break;
default:
break;
}
return X86EMUL_CONTINUE;
}
static int em_push(struct x86_emulate_ctxt *ctxt)
{
struct segmented_address addr;
register_address_increment(ctxt, &ctxt->regs[VCPU_REGS_RSP], -ctxt->op_bytes);
addr.ea = register_address(ctxt, ctxt->regs[VCPU_REGS_RSP]);
addr.seg = VCPU_SREG_SS;
ctxt->dst.type = OP_NONE;
return segmented_write(ctxt, addr, &ctxt->src.val, ctxt->op_bytes);
}
static int emulate_pop(struct x86_emulate_ctxt *ctxt,
void *dest, int len)
{
int rc;
struct segmented_address addr;
addr.ea = register_address(ctxt, ctxt->regs[VCPU_REGS_RSP]);
addr.seg = VCPU_SREG_SS;
rc = segmented_read(ctxt, addr, dest, len);
if (rc != X86EMUL_CONTINUE)
return rc;
register_address_increment(ctxt, &ctxt->regs[VCPU_REGS_RSP], len);
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
int iopl = (ctxt->eflags & X86_EFLAGS_IOPL) >> IOPL_SHIFT;
int cpl = ctxt->ops->cpl(ctxt);
rc = emulate_pop(ctxt, &val, len);
if (rc != X86EMUL_CONTINUE)
return rc;
change_mask = EFLG_CF | EFLG_PF | EFLG_AF | EFLG_ZF | EFLG_SF | EFLG_OF
| EFLG_TF | EFLG_DF | EFLG_NT | EFLG_RF | EFLG_AC | EFLG_ID;
switch(ctxt->mode) {
case X86EMUL_MODE_PROT64:
case X86EMUL_MODE_PROT32:
case X86EMUL_MODE_PROT16:
if (cpl == 0)
change_mask |= EFLG_IOPL;
if (cpl <= iopl)
change_mask |= EFLG_IF;
break;
case X86EMUL_MODE_VM86:
if (iopl < 3)
return emulate_gp(ctxt, 0);
change_mask |= EFLG_IF;
break;
default:
change_mask |= (EFLG_IOPL | EFLG_IF);
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
static int em_push_sreg(struct x86_emulate_ctxt *ctxt)
{
int seg = ctxt->src2.val;
ctxt->src.val = get_segment_selector(ctxt, seg);
return em_push(ctxt);
}
static int em_pop_sreg(struct x86_emulate_ctxt *ctxt)
{
int seg = ctxt->src2.val;
unsigned long selector;
int rc;
rc = emulate_pop(ctxt, &selector, ctxt->op_bytes);
if (rc != X86EMUL_CONTINUE)
return rc;
rc = load_segment_descriptor(ctxt, (u16)selector, seg);
return rc;
}
static int em_pusha(struct x86_emulate_ctxt *ctxt)
{
unsigned long old_esp = ctxt->regs[VCPU_REGS_RSP];
int rc = X86EMUL_CONTINUE;
int reg = VCPU_REGS_RAX;
while (reg <= VCPU_REGS_RDI) {
(reg == VCPU_REGS_RSP) ?
(ctxt->src.val = old_esp) : (ctxt->src.val = ctxt->regs[reg]);
rc = em_push(ctxt);
if (rc != X86EMUL_CONTINUE)
return rc;
++reg;
}
return rc;
}
static int em_pushf(struct x86_emulate_ctxt *ctxt)
{
ctxt->src.val = (unsigned long)ctxt->eflags;
return em_push(ctxt);
}
static int em_popa(struct x86_emulate_ctxt *ctxt)
{
int rc = X86EMUL_CONTINUE;
int reg = VCPU_REGS_RDI;
while (reg >= VCPU_REGS_RAX) {
if (reg == VCPU_REGS_RSP) {
register_address_increment(ctxt, &ctxt->regs[VCPU_REGS_RSP],
ctxt->op_bytes);
--reg;
}
rc = emulate_pop(ctxt, &ctxt->regs[reg], ctxt->op_bytes);
if (rc != X86EMUL_CONTINUE)
break;
--reg;
}
return rc;
}
int emulate_int_real(struct x86_emulate_ctxt *ctxt, int irq)
{
struct x86_emulate_ops *ops = ctxt->ops;
int rc;
struct desc_ptr dt;
gva_t cs_addr;
gva_t eip_addr;
u16 cs, eip;
ctxt->src.val = ctxt->eflags;
rc = em_push(ctxt);
if (rc != X86EMUL_CONTINUE)
return rc;
ctxt->eflags &= ~(EFLG_IF | EFLG_TF | EFLG_AC);
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
static int emulate_int(struct x86_emulate_ctxt *ctxt, int irq)
{
switch(ctxt->mode) {
case X86EMUL_MODE_REAL:
return emulate_int_real(ctxt, irq);
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
unsigned long mask = EFLG_CF | EFLG_PF | EFLG_AF | EFLG_ZF | EFLG_SF | EFLG_TF |
EFLG_IF | EFLG_DF | EFLG_OF | EFLG_IOPL | EFLG_NT | EFLG_RF |
EFLG_AC | EFLG_ID | (1 << 1);
unsigned long vm86_mask = EFLG_VM | EFLG_VIF | EFLG_VIP;
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
ctxt->eflags |= EFLG_RESERVED_ONE_MASK;
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
unsigned short sel;
memcpy(&sel, ctxt->src.valptr + ctxt->op_bytes, 2);
rc = load_segment_descriptor(ctxt, sel, VCPU_SREG_CS);
if (rc != X86EMUL_CONTINUE)
return rc;
ctxt->_eip = 0;
memcpy(&ctxt->_eip, ctxt->src.valptr, ctxt->op_bytes);
return X86EMUL_CONTINUE;
}
static int em_grp2(struct x86_emulate_ctxt *ctxt)
{
switch (ctxt->modrm_reg) {
case 0:
emulate_2op_SrcB(ctxt, "rol");
break;
case 1:
emulate_2op_SrcB(ctxt, "ror");
break;
case 2:
emulate_2op_SrcB(ctxt, "rcl");
break;
case 3:
emulate_2op_SrcB(ctxt, "rcr");
break;
case 4:
case 6:
emulate_2op_SrcB(ctxt, "sal");
break;
case 5:
emulate_2op_SrcB(ctxt, "shr");
break;
case 7:
emulate_2op_SrcB(ctxt, "sar");
break;
}
return X86EMUL_CONTINUE;
}
static int em_not(struct x86_emulate_ctxt *ctxt)
{
ctxt->dst.val = ~ctxt->dst.val;
return X86EMUL_CONTINUE;
}
static int em_neg(struct x86_emulate_ctxt *ctxt)
{
emulate_1op(ctxt, "neg");
return X86EMUL_CONTINUE;
}
static int em_mul_ex(struct x86_emulate_ctxt *ctxt)
{
u8 ex = 0;
emulate_1op_rax_rdx(ctxt, "mul", ex);
return X86EMUL_CONTINUE;
}
static int em_imul_ex(struct x86_emulate_ctxt *ctxt)
{
u8 ex = 0;
emulate_1op_rax_rdx(ctxt, "imul", ex);
return X86EMUL_CONTINUE;
}
static int em_div_ex(struct x86_emulate_ctxt *ctxt)
{
u8 de = 0;
emulate_1op_rax_rdx(ctxt, "div", de);
if (de)
return emulate_de(ctxt);
return X86EMUL_CONTINUE;
}
static int em_idiv_ex(struct x86_emulate_ctxt *ctxt)
{
u8 de = 0;
emulate_1op_rax_rdx(ctxt, "idiv", de);
if (de)
return emulate_de(ctxt);
return X86EMUL_CONTINUE;
}
static int em_grp45(struct x86_emulate_ctxt *ctxt)
{
int rc = X86EMUL_CONTINUE;
switch (ctxt->modrm_reg) {
case 0:
emulate_1op(ctxt, "inc");
break;
case 1:
emulate_1op(ctxt, "dec");
break;
case 2: {
long int old_eip;
old_eip = ctxt->_eip;
ctxt->_eip = ctxt->src.val;
ctxt->src.val = old_eip;
rc = em_push(ctxt);
break;
}
case 4:
ctxt->_eip = ctxt->src.val;
break;
case 5:
rc = em_jmp_far(ctxt);
break;
case 6:
rc = em_push(ctxt);
break;
}
return rc;
}
static int em_cmpxchg8b(struct x86_emulate_ctxt *ctxt)
{
u64 old = ctxt->dst.orig_val64;
if (((u32) (old >> 0) != (u32) ctxt->regs[VCPU_REGS_RAX]) ||
((u32) (old >> 32) != (u32) ctxt->regs[VCPU_REGS_RDX])) {
ctxt->regs[VCPU_REGS_RAX] = (u32) (old >> 0);
ctxt->regs[VCPU_REGS_RDX] = (u32) (old >> 32);
ctxt->eflags &= ~EFLG_ZF;
} else {
ctxt->dst.val64 = ((u64)ctxt->regs[VCPU_REGS_RCX] << 32) |
(u32) ctxt->regs[VCPU_REGS_RBX];
ctxt->eflags |= EFLG_ZF;
}
return X86EMUL_CONTINUE;
}
static int em_ret(struct x86_emulate_ctxt *ctxt)
{
ctxt->dst.type = OP_REG;
ctxt->dst.addr.reg = &ctxt->_eip;
ctxt->dst.bytes = ctxt->op_bytes;
return em_pop(ctxt);
}
static int em_ret_far(struct x86_emulate_ctxt *ctxt)
{
int rc;
unsigned long cs;
rc = emulate_pop(ctxt, &ctxt->_eip, ctxt->op_bytes);
if (rc != X86EMUL_CONTINUE)
return rc;
if (ctxt->op_bytes == 4)
ctxt->_eip = (u32)ctxt->_eip;
rc = emulate_pop(ctxt, &cs, ctxt->op_bytes);
if (rc != X86EMUL_CONTINUE)
return rc;
rc = load_segment_descriptor(ctxt, (u16)cs, VCPU_SREG_CS);
return rc;
}
static int em_cmpxchg(struct x86_emulate_ctxt *ctxt)
{
ctxt->src.orig_val = ctxt->src.val;
ctxt->src.val = ctxt->regs[VCPU_REGS_RAX];
emulate_2op_SrcV(ctxt, "cmp");
if (ctxt->eflags & EFLG_ZF) {
ctxt->dst.val = ctxt->src.orig_val;
} else {
ctxt->dst.type = OP_REG;
ctxt->dst.addr.reg = (unsigned long *)&ctxt->regs[VCPU_REGS_RAX];
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
static void
setup_syscalls_segments(struct x86_emulate_ctxt *ctxt,
struct desc_struct *cs, struct desc_struct *ss)
{
u16 selector;
memset(cs, 0, sizeof(struct desc_struct));
ctxt->ops->get_segment(ctxt, &selector, cs, NULL, VCPU_SREG_CS);
memset(ss, 0, sizeof(struct desc_struct));
cs->l = 0;
set_desc_base(cs, 0);
cs->g = 1;
set_desc_limit(cs, 0xfffff);
cs->type = 0x0b;
cs->s = 1;
cs->dpl = 0;
cs->p = 1;
cs->d = 1;
set_desc_base(ss, 0);
set_desc_limit(ss, 0xfffff);
ss->g = 1;
ss->s = 1;
ss->type = 0x03;
ss->d = 1;
ss->dpl = 0;
ss->p = 1;
}
static bool vendor_intel(struct x86_emulate_ctxt *ctxt)
{
u32 eax, ebx, ecx, edx;
eax = ecx = 0;
return ctxt->ops->get_cpuid(ctxt, &eax, &ebx, &ecx, &edx)
&& ebx == X86EMUL_CPUID_VENDOR_GenuineIntel_ebx
&& ecx == X86EMUL_CPUID_VENDOR_GenuineIntel_ecx
&& edx == X86EMUL_CPUID_VENDOR_GenuineIntel_edx;
}
static bool em_syscall_is_enabled(struct x86_emulate_ctxt *ctxt)
{
struct x86_emulate_ops *ops = ctxt->ops;
u32 eax, ebx, ecx, edx;
if (ctxt->mode == X86EMUL_MODE_PROT64)
return true;
eax = 0x00000000;
ecx = 0x00000000;
if (ops->get_cpuid(ctxt, &eax, &ebx, &ecx, &edx)) {
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
}
return false;
}
static int em_syscall(struct x86_emulate_ctxt *ctxt)
{
struct x86_emulate_ops *ops = ctxt->ops;
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
ctxt->regs[VCPU_REGS_RCX] = ctxt->_eip;
if (efer & EFER_LMA) {
#ifdef CONFIG_X86_64
ctxt->regs[VCPU_REGS_R11] = ctxt->eflags & ~EFLG_RF;
ops->get_msr(ctxt,
ctxt->mode == X86EMUL_MODE_PROT64 ?
MSR_LSTAR : MSR_CSTAR, &msr_data);
ctxt->_eip = msr_data;
ops->get_msr(ctxt, MSR_SYSCALL_MASK, &msr_data);
ctxt->eflags &= ~(msr_data | EFLG_RF);
#endif
} else {
ops->get_msr(ctxt, MSR_STAR, &msr_data);
ctxt->_eip = (u32)msr_data;
ctxt->eflags &= ~(EFLG_VM | EFLG_IF | EFLG_RF);
}
return X86EMUL_CONTINUE;
}
static int em_sysenter(struct x86_emulate_ctxt *ctxt)
{
struct x86_emulate_ops *ops = ctxt->ops;
struct desc_struct cs, ss;
u64 msr_data;
u16 cs_sel, ss_sel;
u64 efer = 0;
ops->get_msr(ctxt, MSR_EFER, &efer);
if (ctxt->mode == X86EMUL_MODE_REAL)
return emulate_gp(ctxt, 0);
if ((ctxt->mode == X86EMUL_MODE_PROT32) && (efer & EFER_LMA)
&& !vendor_intel(ctxt))
return emulate_ud(ctxt);
if (ctxt->mode == X86EMUL_MODE_PROT64)
return emulate_ud(ctxt);
setup_syscalls_segments(ctxt, &cs, &ss);
ops->get_msr(ctxt, MSR_IA32_SYSENTER_CS, &msr_data);
switch (ctxt->mode) {
case X86EMUL_MODE_PROT32:
if ((msr_data & 0xfffc) == 0x0)
return emulate_gp(ctxt, 0);
break;
case X86EMUL_MODE_PROT64:
if (msr_data == 0x0)
return emulate_gp(ctxt, 0);
break;
}
ctxt->eflags &= ~(EFLG_VM | EFLG_IF | EFLG_RF);
cs_sel = (u16)msr_data;
cs_sel &= ~SELECTOR_RPL_MASK;
ss_sel = cs_sel + 8;
ss_sel &= ~SELECTOR_RPL_MASK;
if (ctxt->mode == X86EMUL_MODE_PROT64 || (efer & EFER_LMA)) {
cs.d = 0;
cs.l = 1;
}
ops->set_segment(ctxt, cs_sel, &cs, 0, VCPU_SREG_CS);
ops->set_segment(ctxt, ss_sel, &ss, 0, VCPU_SREG_SS);
ops->get_msr(ctxt, MSR_IA32_SYSENTER_EIP, &msr_data);
ctxt->_eip = msr_data;
ops->get_msr(ctxt, MSR_IA32_SYSENTER_ESP, &msr_data);
ctxt->regs[VCPU_REGS_RSP] = msr_data;
return X86EMUL_CONTINUE;
}
static int em_sysexit(struct x86_emulate_ctxt *ctxt)
{
struct x86_emulate_ops *ops = ctxt->ops;
struct desc_struct cs, ss;
u64 msr_data;
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
cs.dpl = 3;
ss.dpl = 3;
ops->get_msr(ctxt, MSR_IA32_SYSENTER_CS, &msr_data);
switch (usermode) {
case X86EMUL_MODE_PROT32:
cs_sel = (u16)(msr_data + 16);
if ((msr_data & 0xfffc) == 0x0)
return emulate_gp(ctxt, 0);
ss_sel = (u16)(msr_data + 24);
break;
case X86EMUL_MODE_PROT64:
cs_sel = (u16)(msr_data + 32);
if (msr_data == 0x0)
return emulate_gp(ctxt, 0);
ss_sel = cs_sel + 8;
cs.d = 0;
cs.l = 1;
break;
}
cs_sel |= SELECTOR_RPL_MASK;
ss_sel |= SELECTOR_RPL_MASK;
ops->set_segment(ctxt, cs_sel, &cs, 0, VCPU_SREG_CS);
ops->set_segment(ctxt, ss_sel, &ss, 0, VCPU_SREG_SS);
ctxt->_eip = ctxt->regs[VCPU_REGS_RDX];
ctxt->regs[VCPU_REGS_RSP] = ctxt->regs[VCPU_REGS_RCX];
return X86EMUL_CONTINUE;
}
static bool emulator_bad_iopl(struct x86_emulate_ctxt *ctxt)
{
int iopl;
if (ctxt->mode == X86EMUL_MODE_REAL)
return false;
if (ctxt->mode == X86EMUL_MODE_VM86)
return true;
iopl = (ctxt->eflags & X86_EFLAGS_IOPL) >> IOPL_SHIFT;
return ctxt->ops->cpl(ctxt) > iopl;
}
static bool emulator_io_port_access_allowed(struct x86_emulate_ctxt *ctxt,
u16 port, u16 len)
{
struct x86_emulate_ops *ops = ctxt->ops;
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
static void save_state_to_tss16(struct x86_emulate_ctxt *ctxt,
struct tss_segment_16 *tss)
{
tss->ip = ctxt->_eip;
tss->flag = ctxt->eflags;
tss->ax = ctxt->regs[VCPU_REGS_RAX];
tss->cx = ctxt->regs[VCPU_REGS_RCX];
tss->dx = ctxt->regs[VCPU_REGS_RDX];
tss->bx = ctxt->regs[VCPU_REGS_RBX];
tss->sp = ctxt->regs[VCPU_REGS_RSP];
tss->bp = ctxt->regs[VCPU_REGS_RBP];
tss->si = ctxt->regs[VCPU_REGS_RSI];
tss->di = ctxt->regs[VCPU_REGS_RDI];
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
ctxt->_eip = tss->ip;
ctxt->eflags = tss->flag | 2;
ctxt->regs[VCPU_REGS_RAX] = tss->ax;
ctxt->regs[VCPU_REGS_RCX] = tss->cx;
ctxt->regs[VCPU_REGS_RDX] = tss->dx;
ctxt->regs[VCPU_REGS_RBX] = tss->bx;
ctxt->regs[VCPU_REGS_RSP] = tss->sp;
ctxt->regs[VCPU_REGS_RBP] = tss->bp;
ctxt->regs[VCPU_REGS_RSI] = tss->si;
ctxt->regs[VCPU_REGS_RDI] = tss->di;
set_segment_selector(ctxt, tss->ldt, VCPU_SREG_LDTR);
set_segment_selector(ctxt, tss->es, VCPU_SREG_ES);
set_segment_selector(ctxt, tss->cs, VCPU_SREG_CS);
set_segment_selector(ctxt, tss->ss, VCPU_SREG_SS);
set_segment_selector(ctxt, tss->ds, VCPU_SREG_DS);
ret = load_segment_descriptor(ctxt, tss->ldt, VCPU_SREG_LDTR);
if (ret != X86EMUL_CONTINUE)
return ret;
ret = load_segment_descriptor(ctxt, tss->es, VCPU_SREG_ES);
if (ret != X86EMUL_CONTINUE)
return ret;
ret = load_segment_descriptor(ctxt, tss->cs, VCPU_SREG_CS);
if (ret != X86EMUL_CONTINUE)
return ret;
ret = load_segment_descriptor(ctxt, tss->ss, VCPU_SREG_SS);
if (ret != X86EMUL_CONTINUE)
return ret;
ret = load_segment_descriptor(ctxt, tss->ds, VCPU_SREG_DS);
if (ret != X86EMUL_CONTINUE)
return ret;
return X86EMUL_CONTINUE;
}
static int task_switch_16(struct x86_emulate_ctxt *ctxt,
u16 tss_selector, u16 old_tss_sel,
ulong old_tss_base, struct desc_struct *new_desc)
{
struct x86_emulate_ops *ops = ctxt->ops;
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
tss->cr3 = ctxt->ops->get_cr(ctxt, 3);
tss->eip = ctxt->_eip;
tss->eflags = ctxt->eflags;
tss->eax = ctxt->regs[VCPU_REGS_RAX];
tss->ecx = ctxt->regs[VCPU_REGS_RCX];
tss->edx = ctxt->regs[VCPU_REGS_RDX];
tss->ebx = ctxt->regs[VCPU_REGS_RBX];
tss->esp = ctxt->regs[VCPU_REGS_RSP];
tss->ebp = ctxt->regs[VCPU_REGS_RBP];
tss->esi = ctxt->regs[VCPU_REGS_RSI];
tss->edi = ctxt->regs[VCPU_REGS_RDI];
tss->es = get_segment_selector(ctxt, VCPU_SREG_ES);
tss->cs = get_segment_selector(ctxt, VCPU_SREG_CS);
tss->ss = get_segment_selector(ctxt, VCPU_SREG_SS);
tss->ds = get_segment_selector(ctxt, VCPU_SREG_DS);
tss->fs = get_segment_selector(ctxt, VCPU_SREG_FS);
tss->gs = get_segment_selector(ctxt, VCPU_SREG_GS);
tss->ldt_selector = get_segment_selector(ctxt, VCPU_SREG_LDTR);
}
static int load_state_from_tss32(struct x86_emulate_ctxt *ctxt,
struct tss_segment_32 *tss)
{
int ret;
if (ctxt->ops->set_cr(ctxt, 3, tss->cr3))
return emulate_gp(ctxt, 0);
ctxt->_eip = tss->eip;
ctxt->eflags = tss->eflags | 2;
ctxt->regs[VCPU_REGS_RAX] = tss->eax;
ctxt->regs[VCPU_REGS_RCX] = tss->ecx;
ctxt->regs[VCPU_REGS_RDX] = tss->edx;
ctxt->regs[VCPU_REGS_RBX] = tss->ebx;
ctxt->regs[VCPU_REGS_RSP] = tss->esp;
ctxt->regs[VCPU_REGS_RBP] = tss->ebp;
ctxt->regs[VCPU_REGS_RSI] = tss->esi;
ctxt->regs[VCPU_REGS_RDI] = tss->edi;
set_segment_selector(ctxt, tss->ldt_selector, VCPU_SREG_LDTR);
set_segment_selector(ctxt, tss->es, VCPU_SREG_ES);
set_segment_selector(ctxt, tss->cs, VCPU_SREG_CS);
set_segment_selector(ctxt, tss->ss, VCPU_SREG_SS);
set_segment_selector(ctxt, tss->ds, VCPU_SREG_DS);
set_segment_selector(ctxt, tss->fs, VCPU_SREG_FS);
set_segment_selector(ctxt, tss->gs, VCPU_SREG_GS);
if (ctxt->eflags & X86_EFLAGS_VM)
ctxt->mode = X86EMUL_MODE_VM86;
else
ctxt->mode = X86EMUL_MODE_PROT32;
ctxt->ops->set_rflags(ctxt, ctxt->eflags);
ret = load_segment_descriptor(ctxt, tss->ldt_selector, VCPU_SREG_LDTR);
if (ret != X86EMUL_CONTINUE)
return ret;
ret = load_segment_descriptor(ctxt, tss->es, VCPU_SREG_ES);
if (ret != X86EMUL_CONTINUE)
return ret;
ret = load_segment_descriptor(ctxt, tss->cs, VCPU_SREG_CS);
if (ret != X86EMUL_CONTINUE)
return ret;
ret = load_segment_descriptor(ctxt, tss->ss, VCPU_SREG_SS);
if (ret != X86EMUL_CONTINUE)
return ret;
ret = load_segment_descriptor(ctxt, tss->ds, VCPU_SREG_DS);
if (ret != X86EMUL_CONTINUE)
return ret;
ret = load_segment_descriptor(ctxt, tss->fs, VCPU_SREG_FS);
if (ret != X86EMUL_CONTINUE)
return ret;
ret = load_segment_descriptor(ctxt, tss->gs, VCPU_SREG_GS);
if (ret != X86EMUL_CONTINUE)
return ret;
return X86EMUL_CONTINUE;
}
static int task_switch_32(struct x86_emulate_ctxt *ctxt,
u16 tss_selector, u16 old_tss_sel,
ulong old_tss_base, struct desc_struct *new_desc)
{
struct x86_emulate_ops *ops = ctxt->ops;
struct tss_segment_32 tss_seg;
int ret;
u32 new_tss_base = get_desc_base(new_desc);
ret = ops->read_std(ctxt, old_tss_base, &tss_seg, sizeof tss_seg,
&ctxt->exception);
if (ret != X86EMUL_CONTINUE)
return ret;
save_state_to_tss32(ctxt, &tss_seg);
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
return load_state_from_tss32(ctxt, &tss_seg);
}
static int emulator_do_task_switch(struct x86_emulate_ctxt *ctxt,
u16 tss_selector, int idt_index, int reason,
bool has_error_code, u32 error_code)
{
struct x86_emulate_ops *ops = ctxt->ops;
struct desc_struct curr_tss_desc, next_tss_desc;
int ret;
u16 old_tss_sel = get_segment_selector(ctxt, VCPU_SREG_TR);
ulong old_tss_base =
ops->get_cached_segment_base(ctxt, VCPU_SREG_TR);
u32 desc_limit;
ret = read_segment_descriptor(ctxt, tss_selector, &next_tss_desc);
if (ret != X86EMUL_CONTINUE)
return ret;
ret = read_segment_descriptor(ctxt, old_tss_sel, &curr_tss_desc);
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
} else if (reason != TASK_SWITCH_IRET) {
int dpl = next_tss_desc.dpl;
if ((tss_selector & 3) > dpl || ops->cpl(ctxt) > dpl)
return emulate_gp(ctxt, tss_selector);
}
desc_limit = desc_limit_scaled(&next_tss_desc);
if (!next_tss_desc.p ||
((desc_limit < 0x67 && (next_tss_desc.type & 8)) ||
desc_limit < 0x2b)) {
emulate_ts(ctxt, tss_selector & 0xfffc);
return X86EMUL_PROPAGATE_FAULT;
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
return ret;
}
int emulator_task_switch(struct x86_emulate_ctxt *ctxt,
u16 tss_selector, int idt_index, int reason,
bool has_error_code, u32 error_code)
{
int rc;
ctxt->_eip = ctxt->eip;
ctxt->dst.type = OP_NONE;
rc = emulator_do_task_switch(ctxt, tss_selector, idt_index, reason,
has_error_code, error_code);
if (rc == X86EMUL_CONTINUE)
ctxt->eip = ctxt->_eip;
return (rc == X86EMUL_UNHANDLEABLE) ? EMULATION_FAILED : EMULATION_OK;
}
static void string_addr_inc(struct x86_emulate_ctxt *ctxt, unsigned seg,
int reg, struct operand *op)
{
int df = (ctxt->eflags & EFLG_DF) ? -1 : 1;
register_address_increment(ctxt, &ctxt->regs[reg], df * op->bytes);
op->addr.mem.ea = register_address(ctxt, ctxt->regs[reg]);
op->addr.mem.seg = seg;
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
emulate_2op_SrcV(ctxt, "or");
ctxt->eflags &= ~(X86_EFLAGS_AF | X86_EFLAGS_CF);
if (cf)
ctxt->eflags |= X86_EFLAGS_CF;
if (af)
ctxt->eflags |= X86_EFLAGS_AF;
return X86EMUL_CONTINUE;
}
static int em_call(struct x86_emulate_ctxt *ctxt)
{
long rel = ctxt->src.val;
ctxt->src.val = (unsigned long)ctxt->_eip;
jmp_rel(ctxt, rel);
return em_push(ctxt);
}
static int em_call_far(struct x86_emulate_ctxt *ctxt)
{
u16 sel, old_cs;
ulong old_eip;
int rc;
old_cs = get_segment_selector(ctxt, VCPU_SREG_CS);
old_eip = ctxt->_eip;
memcpy(&sel, ctxt->src.valptr + ctxt->op_bytes, 2);
if (load_segment_descriptor(ctxt, sel, VCPU_SREG_CS))
return X86EMUL_CONTINUE;
ctxt->_eip = 0;
memcpy(&ctxt->_eip, ctxt->src.valptr, ctxt->op_bytes);
ctxt->src.val = old_cs;
rc = em_push(ctxt);
if (rc != X86EMUL_CONTINUE)
return rc;
ctxt->src.val = old_eip;
return em_push(ctxt);
}
static int em_ret_near_imm(struct x86_emulate_ctxt *ctxt)
{
int rc;
ctxt->dst.type = OP_REG;
ctxt->dst.addr.reg = &ctxt->_eip;
ctxt->dst.bytes = ctxt->op_bytes;
rc = emulate_pop(ctxt, &ctxt->dst.val, ctxt->op_bytes);
if (rc != X86EMUL_CONTINUE)
return rc;
register_address_increment(ctxt, &ctxt->regs[VCPU_REGS_RSP], ctxt->src.val);
return X86EMUL_CONTINUE;
}
static int em_add(struct x86_emulate_ctxt *ctxt)
{
emulate_2op_SrcV(ctxt, "add");
return X86EMUL_CONTINUE;
}
static int em_or(struct x86_emulate_ctxt *ctxt)
{
emulate_2op_SrcV(ctxt, "or");
return X86EMUL_CONTINUE;
}
static int em_adc(struct x86_emulate_ctxt *ctxt)
{
emulate_2op_SrcV(ctxt, "adc");
return X86EMUL_CONTINUE;
}
static int em_sbb(struct x86_emulate_ctxt *ctxt)
{
emulate_2op_SrcV(ctxt, "sbb");
return X86EMUL_CONTINUE;
}
static int em_and(struct x86_emulate_ctxt *ctxt)
{
emulate_2op_SrcV(ctxt, "and");
return X86EMUL_CONTINUE;
}
static int em_sub(struct x86_emulate_ctxt *ctxt)
{
emulate_2op_SrcV(ctxt, "sub");
return X86EMUL_CONTINUE;
}
static int em_xor(struct x86_emulate_ctxt *ctxt)
{
emulate_2op_SrcV(ctxt, "xor");
return X86EMUL_CONTINUE;
}
static int em_cmp(struct x86_emulate_ctxt *ctxt)
{
emulate_2op_SrcV(ctxt, "cmp");
ctxt->dst.type = OP_NONE;
return X86EMUL_CONTINUE;
}
static int em_test(struct x86_emulate_ctxt *ctxt)
{
emulate_2op_SrcV(ctxt, "test");
ctxt->dst.type = OP_NONE;
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
static int em_imul(struct x86_emulate_ctxt *ctxt)
{
emulate_2op_SrcV_nobyte(ctxt, "imul");
return X86EMUL_CONTINUE;
}
static int em_imul_3op(struct x86_emulate_ctxt *ctxt)
{
ctxt->dst.val = ctxt->src2.val;
return em_imul(ctxt);
}
static int em_cwd(struct x86_emulate_ctxt *ctxt)
{
ctxt->dst.type = OP_REG;
ctxt->dst.bytes = ctxt->src.bytes;
ctxt->dst.addr.reg = &ctxt->regs[VCPU_REGS_RDX];
ctxt->dst.val = ~((ctxt->src.val >> (ctxt->src.bytes * 8 - 1)) - 1);
return X86EMUL_CONTINUE;
}
static int em_rdtsc(struct x86_emulate_ctxt *ctxt)
{
u64 tsc = 0;
ctxt->ops->get_msr(ctxt, MSR_IA32_TSC, &tsc);
ctxt->regs[VCPU_REGS_RAX] = (u32)tsc;
ctxt->regs[VCPU_REGS_RDX] = tsc >> 32;
return X86EMUL_CONTINUE;
}
static int em_rdpmc(struct x86_emulate_ctxt *ctxt)
{
u64 pmc;
if (ctxt->ops->read_pmc(ctxt, ctxt->regs[VCPU_REGS_RCX], &pmc))
return emulate_gp(ctxt, 0);
ctxt->regs[VCPU_REGS_RAX] = (u32)pmc;
ctxt->regs[VCPU_REGS_RDX] = pmc >> 32;
return X86EMUL_CONTINUE;
}
static int em_mov(struct x86_emulate_ctxt *ctxt)
{
ctxt->dst.val = ctxt->src.val;
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
msr_data = (u32)ctxt->regs[VCPU_REGS_RAX]
| ((u64)ctxt->regs[VCPU_REGS_RDX] << 32);
if (ctxt->ops->set_msr(ctxt, ctxt->regs[VCPU_REGS_RCX], msr_data))
return emulate_gp(ctxt, 0);
return X86EMUL_CONTINUE;
}
static int em_rdmsr(struct x86_emulate_ctxt *ctxt)
{
u64 msr_data;
if (ctxt->ops->get_msr(ctxt, ctxt->regs[VCPU_REGS_RCX], &msr_data))
return emulate_gp(ctxt, 0);
ctxt->regs[VCPU_REGS_RAX] = (u32)msr_data;
ctxt->regs[VCPU_REGS_RDX] = msr_data >> 32;
return X86EMUL_CONTINUE;
}
static int em_mov_rm_sreg(struct x86_emulate_ctxt *ctxt)
{
if (ctxt->modrm_reg > VCPU_SREG_GS)
return emulate_ud(ctxt);
ctxt->dst.val = get_segment_selector(ctxt, ctxt->modrm_reg);
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
static int em_movdqu(struct x86_emulate_ctxt *ctxt)
{
memcpy(&ctxt->dst.vec_val, &ctxt->src.vec_val, ctxt->op_bytes);
return X86EMUL_CONTINUE;
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
static int em_vmcall(struct x86_emulate_ctxt *ctxt)
{
int rc;
if (ctxt->modrm_mod != 3 || ctxt->modrm_rm != 1)
return X86EMUL_UNHANDLEABLE;
rc = ctxt->ops->fix_hypercall(ctxt);
if (rc != X86EMUL_CONTINUE)
return rc;
ctxt->_eip = ctxt->eip;
ctxt->dst.type = OP_NONE;
return X86EMUL_CONTINUE;
}
static int em_lgdt(struct x86_emulate_ctxt *ctxt)
{
struct desc_ptr desc_ptr;
int rc;
rc = read_descriptor(ctxt, ctxt->src.addr.mem,
&desc_ptr.size, &desc_ptr.address,
ctxt->op_bytes);
if (rc != X86EMUL_CONTINUE)
return rc;
ctxt->ops->set_gdt(ctxt, &desc_ptr);
ctxt->dst.type = OP_NONE;
return X86EMUL_CONTINUE;
}
static int em_vmmcall(struct x86_emulate_ctxt *ctxt)
{
int rc;
rc = ctxt->ops->fix_hypercall(ctxt);
ctxt->dst.type = OP_NONE;
return rc;
}
static int em_lidt(struct x86_emulate_ctxt *ctxt)
{
struct desc_ptr desc_ptr;
int rc;
rc = read_descriptor(ctxt, ctxt->src.addr.mem,
&desc_ptr.size, &desc_ptr.address,
ctxt->op_bytes);
if (rc != X86EMUL_CONTINUE)
return rc;
ctxt->ops->set_idt(ctxt, &desc_ptr);
ctxt->dst.type = OP_NONE;
return X86EMUL_CONTINUE;
}
static int em_smsw(struct x86_emulate_ctxt *ctxt)
{
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
register_address_increment(ctxt, &ctxt->regs[VCPU_REGS_RCX], -1);
if ((address_mask(ctxt, ctxt->regs[VCPU_REGS_RCX]) != 0) &&
(ctxt->b == 0xe2 || test_cc(ctxt->b ^ 0x5, ctxt->eflags)))
jmp_rel(ctxt, ctxt->src.val);
return X86EMUL_CONTINUE;
}
static int em_jcxz(struct x86_emulate_ctxt *ctxt)
{
if (address_mask(ctxt, ctxt->regs[VCPU_REGS_RCX]) == 0)
jmp_rel(ctxt, ctxt->src.val);
return X86EMUL_CONTINUE;
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
static int em_bt(struct x86_emulate_ctxt *ctxt)
{
ctxt->dst.type = OP_NONE;
ctxt->src.val &= (ctxt->dst.bytes << 3) - 1;
emulate_2op_SrcV_nobyte(ctxt, "bt");
return X86EMUL_CONTINUE;
}
static int em_bts(struct x86_emulate_ctxt *ctxt)
{
emulate_2op_SrcV_nobyte(ctxt, "bts");
return X86EMUL_CONTINUE;
}
static int em_btr(struct x86_emulate_ctxt *ctxt)
{
emulate_2op_SrcV_nobyte(ctxt, "btr");
return X86EMUL_CONTINUE;
}
static int em_btc(struct x86_emulate_ctxt *ctxt)
{
emulate_2op_SrcV_nobyte(ctxt, "btc");
return X86EMUL_CONTINUE;
}
static int em_bsf(struct x86_emulate_ctxt *ctxt)
{
u8 zf;
__asm__ ("bsf %2, %0; setz %1"
: "=r"(ctxt->dst.val), "=q"(zf)
: "r"(ctxt->src.val));
ctxt->eflags &= ~X86_EFLAGS_ZF;
if (zf) {
ctxt->eflags |= X86_EFLAGS_ZF;
ctxt->dst.type = OP_NONE;
}
return X86EMUL_CONTINUE;
}
static int em_bsr(struct x86_emulate_ctxt *ctxt)
{
u8 zf;
__asm__ ("bsr %2, %0; setz %1"
: "=r"(ctxt->dst.val), "=q"(zf)
: "r"(ctxt->src.val));
ctxt->eflags &= ~X86_EFLAGS_ZF;
if (zf) {
ctxt->eflags |= X86_EFLAGS_ZF;
ctxt->dst.type = OP_NONE;
}
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
rsvd = CR3_L_MODE_RESERVED_BITS;
else if (ctxt->ops->get_cr(ctxt, 4) & X86_CR4_PAE)
rsvd = CR3_PAE_RESERVED_BITS;
else if (ctxt->ops->get_cr(ctxt, 0) & X86_CR0_PG)
rsvd = CR3_NONPAE_RESERVED_BITS;
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
if (check_dr7_gd(ctxt))
return emulate_db(ctxt);
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
u64 rax = ctxt->regs[VCPU_REGS_RAX];
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
u64 rcx = ctxt->regs[VCPU_REGS_RCX];
if ((!(cr4 & X86_CR4_PCE) && ctxt->ops->cpl(ctxt)) ||
(rcx > 3))
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
if ((ctxt->d & BitOp) && op == &ctxt->dst)
fetch_bit_operand(ctxt);
op->orig_val = op->val;
break;
case OpMem64:
ctxt->memop.bytes = 8;
goto mem_common;
case OpAcc:
op->type = OP_REG;
op->bytes = (ctxt->d & ByteOp) ? 1 : ctxt->op_bytes;
op->addr.reg = &ctxt->regs[VCPU_REGS_RAX];
fetch_register_operand(op);
op->orig_val = op->val;
break;
case OpDI:
op->type = OP_MEM;
op->bytes = (ctxt->d & ByteOp) ? 1 : ctxt->op_bytes;
op->addr.mem.ea =
register_address(ctxt, ctxt->regs[VCPU_REGS_RDI]);
op->addr.mem.seg = VCPU_SREG_ES;
op->val = 0;
break;
case OpDX:
op->type = OP_REG;
op->bytes = 2;
op->addr.reg = &ctxt->regs[VCPU_REGS_RDX];
fetch_register_operand(op);
break;
case OpCL:
op->bytes = 1;
op->val = ctxt->regs[VCPU_REGS_RCX] & 0xff;
break;
case OpImmByte:
rc = decode_imm(ctxt, op, 1, true);
break;
case OpOne:
op->bytes = 1;
op->val = 1;
break;
case OpImm:
rc = decode_imm(ctxt, op, imm_size(ctxt), true);
break;
case OpMem8:
ctxt->memop.bytes = 1;
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
register_address(ctxt, ctxt->regs[VCPU_REGS_RSI]);
op->addr.mem.seg = seg_override(ctxt);
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
op->val = VCPU_SREG_ES;
break;
case OpCS:
op->val = VCPU_SREG_CS;
break;
case OpSS:
op->val = VCPU_SREG_SS;
break;
case OpDS:
op->val = VCPU_SREG_DS;
break;
case OpFS:
op->val = VCPU_SREG_FS;
break;
case OpGS:
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
struct opcode opcode;
ctxt->memop.type = OP_NONE;
ctxt->memopp = NULL;
ctxt->_eip = ctxt->eip;
ctxt->fetch.start = ctxt->_eip;
ctxt->fetch.end = ctxt->fetch.start + insn_len;
if (insn_len > 0)
memcpy(ctxt->fetch.data, insn, insn_len);
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
set_seg_override(ctxt, (ctxt->b >> 3) & 3);
break;
case 0x64:
case 0x65:
set_seg_override(ctxt, ctxt->b & 7);
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
ctxt->twobyte = 1;
ctxt->b = insn_fetch(u8, ctxt);
opcode = twobyte_table[ctxt->b];
}
ctxt->d = opcode.flags;
while (ctxt->d & GroupMask) {
switch (ctxt->d & GroupMask) {
case Group:
ctxt->modrm = insn_fetch(u8, ctxt);
--ctxt->_eip;
goffset = (ctxt->modrm >> 3) & 7;
opcode = opcode.u.group[goffset];
break;
case GroupDual:
ctxt->modrm = insn_fetch(u8, ctxt);
--ctxt->_eip;
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
default:
return EMULATION_FAILED;
}
ctxt->d &= ~(u64)GroupMask;
ctxt->d |= opcode.flags;
}
ctxt->execute = opcode.u.execute;
ctxt->check_perm = opcode.check_perm;
ctxt->intercept = opcode.intercept;
if (ctxt->d == 0 || (ctxt->d & Undefined))
return EMULATION_FAILED;
if (!(ctxt->d & VendorSpecific) && ctxt->only_vendor_specific_insn)
return EMULATION_FAILED;
if (mode == X86EMUL_MODE_PROT64 && (ctxt->d & Stack))
ctxt->op_bytes = 8;
if (ctxt->d & Op3264) {
if (mode == X86EMUL_MODE_PROT64)
ctxt->op_bytes = 8;
else
ctxt->op_bytes = 4;
}
if (ctxt->d & Sse)
ctxt->op_bytes = 16;
if (ctxt->d & ModRM) {
rc = decode_modrm(ctxt, &ctxt->memop);
if (!ctxt->has_seg_override)
set_seg_override(ctxt, ctxt->modrm_seg);
} else if (ctxt->d & MemAbs)
rc = decode_abs(ctxt, &ctxt->memop);
if (rc != X86EMUL_CONTINUE)
goto done;
if (!ctxt->has_seg_override)
set_seg_override(ctxt, VCPU_SREG_DS);
ctxt->memop.addr.mem.seg = seg_override(ctxt);
if (ctxt->memop.type == OP_MEM && ctxt->ad_bytes != 8)
ctxt->memop.addr.mem.ea = (u32)ctxt->memop.addr.mem.ea;
rc = decode_operand(ctxt, &ctxt->src, (ctxt->d >> SrcShift) & OpMask);
if (rc != X86EMUL_CONTINUE)
goto done;
rc = decode_operand(ctxt, &ctxt->src2, (ctxt->d >> Src2Shift) & OpMask);
if (rc != X86EMUL_CONTINUE)
goto done;
rc = decode_operand(ctxt, &ctxt->dst, (ctxt->d >> DstShift) & OpMask);
done:
if (ctxt->memopp && ctxt->memopp->type == OP_MEM && ctxt->rip_relative)
ctxt->memopp->addr.mem.ea += ctxt->_eip;
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
((ctxt->eflags & EFLG_ZF) == 0))
|| ((ctxt->rep_prefix == REPNE_PREFIX) &&
((ctxt->eflags & EFLG_ZF) == EFLG_ZF))))
return true;
return false;
}
int x86_emulate_insn(struct x86_emulate_ctxt *ctxt)
{
struct x86_emulate_ops *ops = ctxt->ops;
int rc = X86EMUL_CONTINUE;
int saved_dst_type = ctxt->dst.type;
ctxt->mem_read.pos = 0;
if (ctxt->mode == X86EMUL_MODE_PROT64 && (ctxt->d & No64)) {
rc = emulate_ud(ctxt);
goto done;
}
if (ctxt->lock_prefix && (!(ctxt->d & Lock) || ctxt->dst.type != OP_MEM)) {
rc = emulate_ud(ctxt);
goto done;
}
if ((ctxt->d & SrcMask) == SrcMemFAddr && ctxt->src.type != OP_MEM) {
rc = emulate_ud(ctxt);
goto done;
}
if ((ctxt->d & Sse)
&& ((ops->get_cr(ctxt, 0) & X86_CR0_EM)
|| !(ops->get_cr(ctxt, 4) & X86_CR4_OSFXSR))) {
rc = emulate_ud(ctxt);
goto done;
}
if ((ctxt->d & Sse) && (ops->get_cr(ctxt, 0) & X86_CR0_TS)) {
rc = emulate_nm(ctxt);
goto done;
}
if (unlikely(ctxt->guest_mode) && ctxt->intercept) {
rc = emulator_check_intercept(ctxt, ctxt->intercept,
X86_ICPT_PRE_EXCEPT);
if (rc != X86EMUL_CONTINUE)
goto done;
}
if ((ctxt->d & Priv) && ops->cpl(ctxt)) {
rc = emulate_gp(ctxt, 0);
goto done;
}
if ((ctxt->d & Prot) && !(ctxt->mode & X86EMUL_MODE_PROT)) {
rc = emulate_ud(ctxt);
goto done;
}
if (ctxt->check_perm) {
rc = ctxt->check_perm(ctxt);
if (rc != X86EMUL_CONTINUE)
goto done;
}
if (unlikely(ctxt->guest_mode) && ctxt->intercept) {
rc = emulator_check_intercept(ctxt, ctxt->intercept,
X86_ICPT_POST_EXCEPT);
if (rc != X86EMUL_CONTINUE)
goto done;
}
if (ctxt->rep_prefix && (ctxt->d & String)) {
if (address_mask(ctxt, ctxt->regs[VCPU_REGS_RCX]) == 0) {
ctxt->eip = ctxt->_eip;
goto done;
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
if (rc != X86EMUL_CONTINUE)
goto done;
}
ctxt->dst.orig_val = ctxt->dst.val;
special_insn:
if (unlikely(ctxt->guest_mode) && ctxt->intercept) {
rc = emulator_check_intercept(ctxt, ctxt->intercept,
X86_ICPT_POST_MEMACCESS);
if (rc != X86EMUL_CONTINUE)
goto done;
}
if (ctxt->execute) {
rc = ctxt->execute(ctxt);
if (rc != X86EMUL_CONTINUE)
goto done;
goto writeback;
}
if (ctxt->twobyte)
goto twobyte_insn;
switch (ctxt->b) {
case 0x40 ... 0x47:
emulate_1op(ctxt, "inc");
break;
case 0x48 ... 0x4f:
emulate_1op(ctxt, "dec");
break;
case 0x63:
if (ctxt->mode != X86EMUL_MODE_PROT64)
goto cannot_emulate;
ctxt->dst.val = (s32) ctxt->src.val;
break;
case 0x70 ... 0x7f:
if (test_cc(ctxt->b, ctxt->eflags))
jmp_rel(ctxt, ctxt->src.val);
break;
case 0x8d:
ctxt->dst.val = ctxt->src.addr.mem.ea;
break;
case 0x90 ... 0x97:
if (ctxt->dst.addr.reg == &ctxt->regs[VCPU_REGS_RAX])
break;
rc = em_xchg(ctxt);
break;
case 0x98:
switch (ctxt->op_bytes) {
case 2: ctxt->dst.val = (s8)ctxt->dst.val; break;
case 4: ctxt->dst.val = (s16)ctxt->dst.val; break;
case 8: ctxt->dst.val = (s32)ctxt->dst.val; break;
}
break;
case 0xc0 ... 0xc1:
rc = em_grp2(ctxt);
break;
case 0xcc:
rc = emulate_int(ctxt, 3);
break;
case 0xcd:
rc = emulate_int(ctxt, ctxt->src.val);
break;
case 0xce:
if (ctxt->eflags & EFLG_OF)
rc = emulate_int(ctxt, 4);
break;
case 0xd0 ... 0xd1:
rc = em_grp2(ctxt);
break;
case 0xd2 ... 0xd3:
ctxt->src.val = ctxt->regs[VCPU_REGS_RCX];
rc = em_grp2(ctxt);
break;
case 0xe9:
case 0xeb:
jmp_rel(ctxt, ctxt->src.val);
ctxt->dst.type = OP_NONE;
break;
case 0xf4:
ctxt->ops->halt(ctxt);
break;
case 0xf5:
ctxt->eflags ^= EFLG_CF;
break;
case 0xf8:
ctxt->eflags &= ~EFLG_CF;
break;
case 0xf9:
ctxt->eflags |= EFLG_CF;
break;
case 0xfc:
ctxt->eflags &= ~EFLG_DF;
break;
case 0xfd:
ctxt->eflags |= EFLG_DF;
break;
default:
goto cannot_emulate;
}
if (rc != X86EMUL_CONTINUE)
goto done;
writeback:
rc = writeback(ctxt);
if (rc != X86EMUL_CONTINUE)
goto done;
ctxt->dst.type = saved_dst_type;
if ((ctxt->d & SrcMask) == SrcSI)
string_addr_inc(ctxt, seg_override(ctxt),
VCPU_REGS_RSI, &ctxt->src);
if ((ctxt->d & DstMask) == DstDI)
string_addr_inc(ctxt, VCPU_SREG_ES, VCPU_REGS_RDI,
&ctxt->dst);
if (ctxt->rep_prefix && (ctxt->d & String)) {
struct read_cache *r = &ctxt->io_read;
register_address_increment(ctxt, &ctxt->regs[VCPU_REGS_RCX], -1);
if (!string_insn_completed(ctxt)) {
if ((r->end != 0 || ctxt->regs[VCPU_REGS_RCX] & 0x3ff) &&
(r->end == 0 || r->end != r->pos)) {
ctxt->mem_read.end = 0;
return EMULATION_RESTART;
}
goto done;
}
}
ctxt->eip = ctxt->_eip;
done:
if (rc == X86EMUL_PROPAGATE_FAULT)
ctxt->have_exception = true;
if (rc == X86EMUL_INTERCEPTED)
return EMULATION_INTERCEPTED;
return (rc == X86EMUL_UNHANDLEABLE) ? EMULATION_FAILED : EMULATION_OK;
twobyte_insn:
switch (ctxt->b) {
case 0x09:
(ctxt->ops->wbinvd)(ctxt);
break;
case 0x08:
case 0x0d:
case 0x18:
break;
case 0x20:
ctxt->dst.val = ops->get_cr(ctxt, ctxt->modrm_reg);
break;
case 0x21:
ops->get_dr(ctxt, ctxt->modrm_reg, &ctxt->dst.val);
break;
case 0x40 ... 0x4f:
ctxt->dst.val = ctxt->dst.orig_val = ctxt->src.val;
if (!test_cc(ctxt->b, ctxt->eflags))
ctxt->dst.type = OP_NONE;
break;
case 0x80 ... 0x8f:
if (test_cc(ctxt->b, ctxt->eflags))
jmp_rel(ctxt, ctxt->src.val);
break;
case 0x90 ... 0x9f:
ctxt->dst.val = test_cc(ctxt->b, ctxt->eflags);
break;
case 0xa4:
case 0xa5:
emulate_2op_cl(ctxt, "shld");
break;
case 0xac:
case 0xad:
emulate_2op_cl(ctxt, "shrd");
break;
case 0xae:
break;
case 0xb6 ... 0xb7:
ctxt->dst.bytes = ctxt->op_bytes;
ctxt->dst.val = (ctxt->d & ByteOp) ? (u8) ctxt->src.val
: (u16) ctxt->src.val;
break;
case 0xbe ... 0xbf:
ctxt->dst.bytes = ctxt->op_bytes;
ctxt->dst.val = (ctxt->d & ByteOp) ? (s8) ctxt->src.val :
(s16) ctxt->src.val;
break;
case 0xc0 ... 0xc1:
emulate_2op_SrcV(ctxt, "add");
ctxt->src.val = ctxt->dst.orig_val;
write_register_operand(&ctxt->src);
break;
case 0xc3:
ctxt->dst.bytes = ctxt->op_bytes;
ctxt->dst.val = (ctxt->op_bytes == 4) ? (u32) ctxt->src.val :
(u64) ctxt->src.val;
break;
default:
goto cannot_emulate;
}
if (rc != X86EMUL_CONTINUE)
goto done;
goto writeback;
cannot_emulate:
return EMULATION_FAILED;
}
