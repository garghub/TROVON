static int emulator_check_intercept(struct x86_emulate_ctxt *ctxt,
enum x86_intercept intercept,
enum x86_intercept_stage stage)
{
struct x86_instruction_info info = {
.intercept = intercept,
.rep_prefix = ctxt->decode.rep_prefix,
.modrm_mod = ctxt->decode.modrm_mod,
.modrm_reg = ctxt->decode.modrm_reg,
.modrm_rm = ctxt->decode.modrm_rm,
.src_val = ctxt->decode.src.val64,
.src_bytes = ctxt->decode.src.bytes,
.dst_bytes = ctxt->decode.dst.bytes,
.ad_bytes = ctxt->decode.ad_bytes,
.next_rip = ctxt->eip,
};
return ctxt->ops->intercept(ctxt, &info, stage);
}
static inline unsigned long ad_mask(struct decode_cache *c)
{
return (1UL << (c->ad_bytes << 3)) - 1;
}
static inline unsigned long
address_mask(struct decode_cache *c, unsigned long reg)
{
if (c->ad_bytes == sizeof(unsigned long))
return reg;
else
return reg & ad_mask(c);
}
static inline unsigned long
register_address(struct decode_cache *c, unsigned long reg)
{
return address_mask(c, reg);
}
static inline void
register_address_increment(struct decode_cache *c, unsigned long *reg, int inc)
{
if (c->ad_bytes == sizeof(unsigned long))
*reg += inc;
else
*reg = (*reg & ~ad_mask(c)) | ((*reg + inc) & ad_mask(c));
}
static inline void jmp_rel(struct decode_cache *c, int rel)
{
register_address_increment(c, &c->eip, rel);
}
static u32 desc_limit_scaled(struct desc_struct *desc)
{
u32 limit = get_desc_limit(desc);
return desc->g ? (limit << 12) | 0xfff : limit;
}
static void set_seg_override(struct decode_cache *c, int seg)
{
c->has_seg_override = true;
c->seg_override = seg;
}
static unsigned long seg_base(struct x86_emulate_ctxt *ctxt,
struct x86_emulate_ops *ops, int seg)
{
if (ctxt->mode == X86EMUL_MODE_PROT64 && seg < VCPU_SREG_FS)
return 0;
return ops->get_cached_segment_base(ctxt, seg);
}
static unsigned seg_override(struct x86_emulate_ctxt *ctxt,
struct decode_cache *c)
{
if (!c->has_seg_override)
return 0;
return c->seg_override;
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
struct decode_cache *c = &ctxt->decode;
struct desc_struct desc;
bool usable;
ulong la;
u32 lim;
u16 sel;
unsigned cpl, rpl;
la = seg_base(ctxt, ctxt->ops, addr.seg) + addr.ea;
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
if (fetch ? ctxt->mode != X86EMUL_MODE_PROT64 : c->ad_bytes != 8)
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
static int do_fetch_insn_byte(struct x86_emulate_ctxt *ctxt,
struct x86_emulate_ops *ops,
unsigned long eip, u8 *dest)
{
struct fetch_cache *fc = &ctxt->decode.fetch;
int rc;
int size, cur_size;
if (eip == fc->end) {
unsigned long linear;
struct segmented_address addr = { .seg=VCPU_SREG_CS, .ea=eip};
cur_size = fc->end - fc->start;
size = min(15UL - cur_size, PAGE_SIZE - offset_in_page(eip));
rc = __linearize(ctxt, addr, size, false, true, &linear);
if (rc != X86EMUL_CONTINUE)
return rc;
rc = ops->fetch(ctxt, linear, fc->data + cur_size,
size, &ctxt->exception);
if (rc != X86EMUL_CONTINUE)
return rc;
fc->end += size;
}
*dest = fc->data[eip - fc->start];
return X86EMUL_CONTINUE;
}
static int do_insn_fetch(struct x86_emulate_ctxt *ctxt,
struct x86_emulate_ops *ops,
unsigned long eip, void *dest, unsigned size)
{
int rc;
if (eip + size - ctxt->eip > 15)
return X86EMUL_UNHANDLEABLE;
while (size--) {
rc = do_fetch_insn_byte(ctxt, ops, eip++, dest++);
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
struct operand *op,
struct decode_cache *c,
int inhibit_bytereg)
{
unsigned reg = c->modrm_reg;
int highbyte_regs = c->rex_prefix == 0;
if (!(c->d & ModRM))
reg = (c->b & 7) | ((c->rex_prefix & 1) << 3);
if (c->d & Sse) {
op->type = OP_XMM;
op->bytes = 16;
op->addr.xmm = reg;
read_sse_reg(ctxt, &op->vec_val, reg);
return;
}
op->type = OP_REG;
if ((c->d & ByteOp) && !inhibit_bytereg) {
op->addr.reg = decode_register(reg, c->regs, highbyte_regs);
op->bytes = 1;
} else {
op->addr.reg = decode_register(reg, c->regs, 0);
op->bytes = c->op_bytes;
}
fetch_register_operand(op);
op->orig_val = op->val;
}
static int decode_modrm(struct x86_emulate_ctxt *ctxt,
struct x86_emulate_ops *ops,
struct operand *op)
{
struct decode_cache *c = &ctxt->decode;
u8 sib;
int index_reg = 0, base_reg = 0, scale;
int rc = X86EMUL_CONTINUE;
ulong modrm_ea = 0;
if (c->rex_prefix) {
c->modrm_reg = (c->rex_prefix & 4) << 1;
index_reg = (c->rex_prefix & 2) << 2;
c->modrm_rm = base_reg = (c->rex_prefix & 1) << 3;
}
c->modrm = insn_fetch(u8, 1, c->eip);
c->modrm_mod |= (c->modrm & 0xc0) >> 6;
c->modrm_reg |= (c->modrm & 0x38) >> 3;
c->modrm_rm |= (c->modrm & 0x07);
c->modrm_seg = VCPU_SREG_DS;
if (c->modrm_mod == 3) {
op->type = OP_REG;
op->bytes = (c->d & ByteOp) ? 1 : c->op_bytes;
op->addr.reg = decode_register(c->modrm_rm,
c->regs, c->d & ByteOp);
if (c->d & Sse) {
op->type = OP_XMM;
op->bytes = 16;
op->addr.xmm = c->modrm_rm;
read_sse_reg(ctxt, &op->vec_val, c->modrm_rm);
return rc;
}
fetch_register_operand(op);
return rc;
}
op->type = OP_MEM;
if (c->ad_bytes == 2) {
unsigned bx = c->regs[VCPU_REGS_RBX];
unsigned bp = c->regs[VCPU_REGS_RBP];
unsigned si = c->regs[VCPU_REGS_RSI];
unsigned di = c->regs[VCPU_REGS_RDI];
switch (c->modrm_mod) {
case 0:
if (c->modrm_rm == 6)
modrm_ea += insn_fetch(u16, 2, c->eip);
break;
case 1:
modrm_ea += insn_fetch(s8, 1, c->eip);
break;
case 2:
modrm_ea += insn_fetch(u16, 2, c->eip);
break;
}
switch (c->modrm_rm) {
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
if (c->modrm_mod != 0)
modrm_ea += bp;
break;
case 7:
modrm_ea += bx;
break;
}
if (c->modrm_rm == 2 || c->modrm_rm == 3 ||
(c->modrm_rm == 6 && c->modrm_mod != 0))
c->modrm_seg = VCPU_SREG_SS;
modrm_ea = (u16)modrm_ea;
} else {
if ((c->modrm_rm & 7) == 4) {
sib = insn_fetch(u8, 1, c->eip);
index_reg |= (sib >> 3) & 7;
base_reg |= sib & 7;
scale = sib >> 6;
if ((base_reg & 7) == 5 && c->modrm_mod == 0)
modrm_ea += insn_fetch(s32, 4, c->eip);
else
modrm_ea += c->regs[base_reg];
if (index_reg != 4)
modrm_ea += c->regs[index_reg] << scale;
} else if ((c->modrm_rm & 7) == 5 && c->modrm_mod == 0) {
if (ctxt->mode == X86EMUL_MODE_PROT64)
c->rip_relative = 1;
} else
modrm_ea += c->regs[c->modrm_rm];
switch (c->modrm_mod) {
case 0:
if (c->modrm_rm == 5)
modrm_ea += insn_fetch(s32, 4, c->eip);
break;
case 1:
modrm_ea += insn_fetch(s8, 1, c->eip);
break;
case 2:
modrm_ea += insn_fetch(s32, 4, c->eip);
break;
}
}
op->addr.mem.ea = modrm_ea;
done:
return rc;
}
static int decode_abs(struct x86_emulate_ctxt *ctxt,
struct x86_emulate_ops *ops,
struct operand *op)
{
struct decode_cache *c = &ctxt->decode;
int rc = X86EMUL_CONTINUE;
op->type = OP_MEM;
switch (c->ad_bytes) {
case 2:
op->addr.mem.ea = insn_fetch(u16, 2, c->eip);
break;
case 4:
op->addr.mem.ea = insn_fetch(u32, 4, c->eip);
break;
case 8:
op->addr.mem.ea = insn_fetch(u64, 8, c->eip);
break;
}
done:
return rc;
}
static void fetch_bit_operand(struct decode_cache *c)
{
long sv = 0, mask;
if (c->dst.type == OP_MEM && c->src.type == OP_REG) {
mask = ~(c->dst.bytes * 8 - 1);
if (c->src.bytes == 2)
sv = (s16)c->src.val & (s16)mask;
else if (c->src.bytes == 4)
sv = (s32)c->src.val & (s32)mask;
c->dst.addr.mem.ea += (sv >> 3);
}
c->src.val &= (c->dst.bytes << 3) - 1;
}
static int read_emulated(struct x86_emulate_ctxt *ctxt,
struct x86_emulate_ops *ops,
unsigned long addr, void *dest, unsigned size)
{
int rc;
struct read_cache *mc = &ctxt->decode.mem_read;
while (size) {
int n = min(size, 8u);
size -= n;
if (mc->pos < mc->end)
goto read_cached;
rc = ops->read_emulated(ctxt, addr, mc->data + mc->end, n,
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
return read_emulated(ctxt, ctxt->ops, linear, data, size);
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
struct x86_emulate_ops *ops,
unsigned int size, unsigned short port,
void *dest)
{
struct read_cache *rc = &ctxt->decode.io_read;
if (rc->pos == rc->end) {
struct decode_cache *c = &ctxt->decode;
unsigned int in_page, n;
unsigned int count = c->rep_prefix ?
address_mask(c, c->regs[VCPU_REGS_RCX]) : 1;
in_page = (ctxt->eflags & EFLG_DF) ?
offset_in_page(c->regs[VCPU_REGS_RDI]) :
PAGE_SIZE - offset_in_page(c->regs[VCPU_REGS_RDI]);
n = min(min(in_page, (unsigned int)sizeof(rc->data)) / size,
count);
if (n == 0)
n = 1;
rc->pos = rc->end = 0;
if (!ops->pio_in_emulated(ctxt, size, port, rc->data, n))
return 0;
rc->end = n * size;
}
memcpy(dest, rc->data + rc->pos, size);
rc->pos += size;
return 1;
}
static void get_descriptor_table_ptr(struct x86_emulate_ctxt *ctxt,
struct x86_emulate_ops *ops,
u16 selector, struct desc_ptr *dt)
{
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
struct x86_emulate_ops *ops,
u16 selector, struct desc_struct *desc)
{
struct desc_ptr dt;
u16 index = selector >> 3;
int ret;
ulong addr;
get_descriptor_table_ptr(ctxt, ops, selector, &dt);
if (dt.size < index * 8 + 7)
return emulate_gp(ctxt, selector & 0xfffc);
addr = dt.address + index * 8;
ret = ops->read_std(ctxt, addr, desc, sizeof *desc, &ctxt->exception);
return ret;
}
static int write_segment_descriptor(struct x86_emulate_ctxt *ctxt,
struct x86_emulate_ops *ops,
u16 selector, struct desc_struct *desc)
{
struct desc_ptr dt;
u16 index = selector >> 3;
ulong addr;
int ret;
get_descriptor_table_ptr(ctxt, ops, selector, &dt);
if (dt.size < index * 8 + 7)
return emulate_gp(ctxt, selector & 0xfffc);
addr = dt.address + index * 8;
ret = ops->write_std(ctxt, addr, desc, sizeof *desc, &ctxt->exception);
return ret;
}
static int load_segment_descriptor(struct x86_emulate_ctxt *ctxt,
struct x86_emulate_ops *ops,
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
goto load;
}
if ((seg == VCPU_SREG_CS || seg == VCPU_SREG_SS || seg == VCPU_SREG_TR)
&& null_selector)
goto exception;
if (seg == VCPU_SREG_TR && (selector & (1 << 2)))
goto exception;
if (null_selector)
goto load;
ret = read_segment_descriptor(ctxt, ops, selector, &seg_desc);
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
cpl = ops->cpl(ctxt);
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
ret = write_segment_descriptor(ctxt, ops, selector, &seg_desc);
if (ret != X86EMUL_CONTINUE)
return ret;
}
load:
ops->set_segment(ctxt, selector, &seg_desc, 0, seg);
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
struct decode_cache *c = &ctxt->decode;
switch (c->dst.type) {
case OP_REG:
write_register_operand(&c->dst);
break;
case OP_MEM:
if (c->lock_prefix)
rc = segmented_cmpxchg(ctxt,
c->dst.addr.mem,
&c->dst.orig_val,
&c->dst.val,
c->dst.bytes);
else
rc = segmented_write(ctxt,
c->dst.addr.mem,
&c->dst.val,
c->dst.bytes);
if (rc != X86EMUL_CONTINUE)
return rc;
break;
case OP_XMM:
write_sse_reg(ctxt, &c->dst.vec_val, c->dst.addr.xmm);
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
struct decode_cache *c = &ctxt->decode;
struct segmented_address addr;
register_address_increment(c, &c->regs[VCPU_REGS_RSP], -c->op_bytes);
addr.ea = register_address(c, c->regs[VCPU_REGS_RSP]);
addr.seg = VCPU_SREG_SS;
c->dst.type = OP_NONE;
return segmented_write(ctxt, addr, &c->src.val, c->op_bytes);
}
static int emulate_pop(struct x86_emulate_ctxt *ctxt,
void *dest, int len)
{
struct decode_cache *c = &ctxt->decode;
int rc;
struct segmented_address addr;
addr.ea = register_address(c, c->regs[VCPU_REGS_RSP]);
addr.seg = VCPU_SREG_SS;
rc = segmented_read(ctxt, addr, dest, len);
if (rc != X86EMUL_CONTINUE)
return rc;
register_address_increment(c, &c->regs[VCPU_REGS_RSP], len);
return rc;
}
static int em_pop(struct x86_emulate_ctxt *ctxt)
{
struct decode_cache *c = &ctxt->decode;
return emulate_pop(ctxt, &c->dst.val, c->op_bytes);
}
static int emulate_popf(struct x86_emulate_ctxt *ctxt,
struct x86_emulate_ops *ops,
void *dest, int len)
{
int rc;
unsigned long val, change_mask;
int iopl = (ctxt->eflags & X86_EFLAGS_IOPL) >> IOPL_SHIFT;
int cpl = ops->cpl(ctxt);
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
struct decode_cache *c = &ctxt->decode;
c->dst.type = OP_REG;
c->dst.addr.reg = &ctxt->eflags;
c->dst.bytes = c->op_bytes;
return emulate_popf(ctxt, ctxt->ops, &c->dst.val, c->op_bytes);
}
static int emulate_push_sreg(struct x86_emulate_ctxt *ctxt,
struct x86_emulate_ops *ops, int seg)
{
struct decode_cache *c = &ctxt->decode;
c->src.val = get_segment_selector(ctxt, seg);
return em_push(ctxt);
}
static int emulate_pop_sreg(struct x86_emulate_ctxt *ctxt,
struct x86_emulate_ops *ops, int seg)
{
struct decode_cache *c = &ctxt->decode;
unsigned long selector;
int rc;
rc = emulate_pop(ctxt, &selector, c->op_bytes);
if (rc != X86EMUL_CONTINUE)
return rc;
rc = load_segment_descriptor(ctxt, ops, (u16)selector, seg);
return rc;
}
static int em_pusha(struct x86_emulate_ctxt *ctxt)
{
struct decode_cache *c = &ctxt->decode;
unsigned long old_esp = c->regs[VCPU_REGS_RSP];
int rc = X86EMUL_CONTINUE;
int reg = VCPU_REGS_RAX;
while (reg <= VCPU_REGS_RDI) {
(reg == VCPU_REGS_RSP) ?
(c->src.val = old_esp) : (c->src.val = c->regs[reg]);
rc = em_push(ctxt);
if (rc != X86EMUL_CONTINUE)
return rc;
++reg;
}
return rc;
}
static int em_pushf(struct x86_emulate_ctxt *ctxt)
{
struct decode_cache *c = &ctxt->decode;
c->src.val = (unsigned long)ctxt->eflags;
return em_push(ctxt);
}
static int em_popa(struct x86_emulate_ctxt *ctxt)
{
struct decode_cache *c = &ctxt->decode;
int rc = X86EMUL_CONTINUE;
int reg = VCPU_REGS_RDI;
while (reg >= VCPU_REGS_RAX) {
if (reg == VCPU_REGS_RSP) {
register_address_increment(c, &c->regs[VCPU_REGS_RSP],
c->op_bytes);
--reg;
}
rc = emulate_pop(ctxt, &c->regs[reg], c->op_bytes);
if (rc != X86EMUL_CONTINUE)
break;
--reg;
}
return rc;
}
int emulate_int_real(struct x86_emulate_ctxt *ctxt,
struct x86_emulate_ops *ops, int irq)
{
struct decode_cache *c = &ctxt->decode;
int rc;
struct desc_ptr dt;
gva_t cs_addr;
gva_t eip_addr;
u16 cs, eip;
c->src.val = ctxt->eflags;
rc = em_push(ctxt);
if (rc != X86EMUL_CONTINUE)
return rc;
ctxt->eflags &= ~(EFLG_IF | EFLG_TF | EFLG_AC);
c->src.val = get_segment_selector(ctxt, VCPU_SREG_CS);
rc = em_push(ctxt);
if (rc != X86EMUL_CONTINUE)
return rc;
c->src.val = c->eip;
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
rc = load_segment_descriptor(ctxt, ops, cs, VCPU_SREG_CS);
if (rc != X86EMUL_CONTINUE)
return rc;
c->eip = eip;
return rc;
}
static int emulate_int(struct x86_emulate_ctxt *ctxt,
struct x86_emulate_ops *ops, int irq)
{
switch(ctxt->mode) {
case X86EMUL_MODE_REAL:
return emulate_int_real(ctxt, ops, irq);
case X86EMUL_MODE_VM86:
case X86EMUL_MODE_PROT16:
case X86EMUL_MODE_PROT32:
case X86EMUL_MODE_PROT64:
default:
return X86EMUL_UNHANDLEABLE;
}
}
static int emulate_iret_real(struct x86_emulate_ctxt *ctxt,
struct x86_emulate_ops *ops)
{
struct decode_cache *c = &ctxt->decode;
int rc = X86EMUL_CONTINUE;
unsigned long temp_eip = 0;
unsigned long temp_eflags = 0;
unsigned long cs = 0;
unsigned long mask = EFLG_CF | EFLG_PF | EFLG_AF | EFLG_ZF | EFLG_SF | EFLG_TF |
EFLG_IF | EFLG_DF | EFLG_OF | EFLG_IOPL | EFLG_NT | EFLG_RF |
EFLG_AC | EFLG_ID | (1 << 1);
unsigned long vm86_mask = EFLG_VM | EFLG_VIF | EFLG_VIP;
rc = emulate_pop(ctxt, &temp_eip, c->op_bytes);
if (rc != X86EMUL_CONTINUE)
return rc;
if (temp_eip & ~0xffff)
return emulate_gp(ctxt, 0);
rc = emulate_pop(ctxt, &cs, c->op_bytes);
if (rc != X86EMUL_CONTINUE)
return rc;
rc = emulate_pop(ctxt, &temp_eflags, c->op_bytes);
if (rc != X86EMUL_CONTINUE)
return rc;
rc = load_segment_descriptor(ctxt, ops, (u16)cs, VCPU_SREG_CS);
if (rc != X86EMUL_CONTINUE)
return rc;
c->eip = temp_eip;
if (c->op_bytes == 4)
ctxt->eflags = ((temp_eflags & mask) | (ctxt->eflags & vm86_mask));
else if (c->op_bytes == 2) {
ctxt->eflags &= ~0xffff;
ctxt->eflags |= temp_eflags;
}
ctxt->eflags &= ~EFLG_RESERVED_ZEROS_MASK;
ctxt->eflags |= EFLG_RESERVED_ONE_MASK;
return rc;
}
static inline int emulate_iret(struct x86_emulate_ctxt *ctxt,
struct x86_emulate_ops* ops)
{
switch(ctxt->mode) {
case X86EMUL_MODE_REAL:
return emulate_iret_real(ctxt, ops);
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
struct decode_cache *c = &ctxt->decode;
int rc;
unsigned short sel;
memcpy(&sel, c->src.valptr + c->op_bytes, 2);
rc = load_segment_descriptor(ctxt, ctxt->ops, sel, VCPU_SREG_CS);
if (rc != X86EMUL_CONTINUE)
return rc;
c->eip = 0;
memcpy(&c->eip, c->src.valptr, c->op_bytes);
return X86EMUL_CONTINUE;
}
static int em_grp1a(struct x86_emulate_ctxt *ctxt)
{
struct decode_cache *c = &ctxt->decode;
return emulate_pop(ctxt, &c->dst.val, c->dst.bytes);
}
static int em_grp2(struct x86_emulate_ctxt *ctxt)
{
struct decode_cache *c = &ctxt->decode;
switch (c->modrm_reg) {
case 0:
emulate_2op_SrcB("rol", c->src, c->dst, ctxt->eflags);
break;
case 1:
emulate_2op_SrcB("ror", c->src, c->dst, ctxt->eflags);
break;
case 2:
emulate_2op_SrcB("rcl", c->src, c->dst, ctxt->eflags);
break;
case 3:
emulate_2op_SrcB("rcr", c->src, c->dst, ctxt->eflags);
break;
case 4:
case 6:
emulate_2op_SrcB("sal", c->src, c->dst, ctxt->eflags);
break;
case 5:
emulate_2op_SrcB("shr", c->src, c->dst, ctxt->eflags);
break;
case 7:
emulate_2op_SrcB("sar", c->src, c->dst, ctxt->eflags);
break;
}
return X86EMUL_CONTINUE;
}
static int em_grp3(struct x86_emulate_ctxt *ctxt)
{
struct decode_cache *c = &ctxt->decode;
unsigned long *rax = &c->regs[VCPU_REGS_RAX];
unsigned long *rdx = &c->regs[VCPU_REGS_RDX];
u8 de = 0;
switch (c->modrm_reg) {
case 0 ... 1:
emulate_2op_SrcV("test", c->src, c->dst, ctxt->eflags);
break;
case 2:
c->dst.val = ~c->dst.val;
break;
case 3:
emulate_1op("neg", c->dst, ctxt->eflags);
break;
case 4:
emulate_1op_rax_rdx("mul", c->src, *rax, *rdx, ctxt->eflags);
break;
case 5:
emulate_1op_rax_rdx("imul", c->src, *rax, *rdx, ctxt->eflags);
break;
case 6:
emulate_1op_rax_rdx_ex("div", c->src, *rax, *rdx,
ctxt->eflags, de);
break;
case 7:
emulate_1op_rax_rdx_ex("idiv", c->src, *rax, *rdx,
ctxt->eflags, de);
break;
default:
return X86EMUL_UNHANDLEABLE;
}
if (de)
return emulate_de(ctxt);
return X86EMUL_CONTINUE;
}
static int em_grp45(struct x86_emulate_ctxt *ctxt)
{
struct decode_cache *c = &ctxt->decode;
int rc = X86EMUL_CONTINUE;
switch (c->modrm_reg) {
case 0:
emulate_1op("inc", c->dst, ctxt->eflags);
break;
case 1:
emulate_1op("dec", c->dst, ctxt->eflags);
break;
case 2: {
long int old_eip;
old_eip = c->eip;
c->eip = c->src.val;
c->src.val = old_eip;
rc = em_push(ctxt);
break;
}
case 4:
c->eip = c->src.val;
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
static int em_grp9(struct x86_emulate_ctxt *ctxt)
{
struct decode_cache *c = &ctxt->decode;
u64 old = c->dst.orig_val64;
if (((u32) (old >> 0) != (u32) c->regs[VCPU_REGS_RAX]) ||
((u32) (old >> 32) != (u32) c->regs[VCPU_REGS_RDX])) {
c->regs[VCPU_REGS_RAX] = (u32) (old >> 0);
c->regs[VCPU_REGS_RDX] = (u32) (old >> 32);
ctxt->eflags &= ~EFLG_ZF;
} else {
c->dst.val64 = ((u64)c->regs[VCPU_REGS_RCX] << 32) |
(u32) c->regs[VCPU_REGS_RBX];
ctxt->eflags |= EFLG_ZF;
}
return X86EMUL_CONTINUE;
}
static int emulate_ret_far(struct x86_emulate_ctxt *ctxt,
struct x86_emulate_ops *ops)
{
struct decode_cache *c = &ctxt->decode;
int rc;
unsigned long cs;
rc = emulate_pop(ctxt, &c->eip, c->op_bytes);
if (rc != X86EMUL_CONTINUE)
return rc;
if (c->op_bytes == 4)
c->eip = (u32)c->eip;
rc = emulate_pop(ctxt, &cs, c->op_bytes);
if (rc != X86EMUL_CONTINUE)
return rc;
rc = load_segment_descriptor(ctxt, ops, (u16)cs, VCPU_SREG_CS);
return rc;
}
static int emulate_load_segment(struct x86_emulate_ctxt *ctxt,
struct x86_emulate_ops *ops, int seg)
{
struct decode_cache *c = &ctxt->decode;
unsigned short sel;
int rc;
memcpy(&sel, c->src.valptr + c->op_bytes, 2);
rc = load_segment_descriptor(ctxt, ops, sel, seg);
if (rc != X86EMUL_CONTINUE)
return rc;
c->dst.val = c->src.val;
return rc;
}
static inline void
setup_syscalls_segments(struct x86_emulate_ctxt *ctxt,
struct x86_emulate_ops *ops, struct desc_struct *cs,
struct desc_struct *ss)
{
u16 selector;
memset(cs, 0, sizeof(struct desc_struct));
ops->get_segment(ctxt, &selector, cs, NULL, VCPU_SREG_CS);
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
static int
emulate_syscall(struct x86_emulate_ctxt *ctxt, struct x86_emulate_ops *ops)
{
struct decode_cache *c = &ctxt->decode;
struct desc_struct cs, ss;
u64 msr_data;
u16 cs_sel, ss_sel;
u64 efer = 0;
if (ctxt->mode == X86EMUL_MODE_REAL ||
ctxt->mode == X86EMUL_MODE_VM86)
return emulate_ud(ctxt);
ops->get_msr(ctxt, MSR_EFER, &efer);
setup_syscalls_segments(ctxt, ops, &cs, &ss);
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
c->regs[VCPU_REGS_RCX] = c->eip;
if (efer & EFER_LMA) {
#ifdef CONFIG_X86_64
c->regs[VCPU_REGS_R11] = ctxt->eflags & ~EFLG_RF;
ops->get_msr(ctxt,
ctxt->mode == X86EMUL_MODE_PROT64 ?
MSR_LSTAR : MSR_CSTAR, &msr_data);
c->eip = msr_data;
ops->get_msr(ctxt, MSR_SYSCALL_MASK, &msr_data);
ctxt->eflags &= ~(msr_data | EFLG_RF);
#endif
} else {
ops->get_msr(ctxt, MSR_STAR, &msr_data);
c->eip = (u32)msr_data;
ctxt->eflags &= ~(EFLG_VM | EFLG_IF | EFLG_RF);
}
return X86EMUL_CONTINUE;
}
static int
emulate_sysenter(struct x86_emulate_ctxt *ctxt, struct x86_emulate_ops *ops)
{
struct decode_cache *c = &ctxt->decode;
struct desc_struct cs, ss;
u64 msr_data;
u16 cs_sel, ss_sel;
u64 efer = 0;
ctxt->ops->get_msr(ctxt, MSR_EFER, &efer);
if (ctxt->mode == X86EMUL_MODE_REAL)
return emulate_gp(ctxt, 0);
if (ctxt->mode == X86EMUL_MODE_PROT64)
return emulate_ud(ctxt);
setup_syscalls_segments(ctxt, ops, &cs, &ss);
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
c->eip = msr_data;
ops->get_msr(ctxt, MSR_IA32_SYSENTER_ESP, &msr_data);
c->regs[VCPU_REGS_RSP] = msr_data;
return X86EMUL_CONTINUE;
}
static int
emulate_sysexit(struct x86_emulate_ctxt *ctxt, struct x86_emulate_ops *ops)
{
struct decode_cache *c = &ctxt->decode;
struct desc_struct cs, ss;
u64 msr_data;
int usermode;
u16 cs_sel, ss_sel;
if (ctxt->mode == X86EMUL_MODE_REAL ||
ctxt->mode == X86EMUL_MODE_VM86)
return emulate_gp(ctxt, 0);
setup_syscalls_segments(ctxt, ops, &cs, &ss);
if ((c->rex_prefix & 0x8) != 0x0)
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
c->eip = c->regs[VCPU_REGS_RDX];
c->regs[VCPU_REGS_RSP] = c->regs[VCPU_REGS_RCX];
return X86EMUL_CONTINUE;
}
static bool emulator_bad_iopl(struct x86_emulate_ctxt *ctxt,
struct x86_emulate_ops *ops)
{
int iopl;
if (ctxt->mode == X86EMUL_MODE_REAL)
return false;
if (ctxt->mode == X86EMUL_MODE_VM86)
return true;
iopl = (ctxt->eflags & X86_EFLAGS_IOPL) >> IOPL_SHIFT;
return ops->cpl(ctxt) > iopl;
}
static bool emulator_io_port_access_allowed(struct x86_emulate_ctxt *ctxt,
struct x86_emulate_ops *ops,
u16 port, u16 len)
{
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
struct x86_emulate_ops *ops,
u16 port, u16 len)
{
if (ctxt->perm_ok)
return true;
if (emulator_bad_iopl(ctxt, ops))
if (!emulator_io_port_access_allowed(ctxt, ops, port, len))
return false;
ctxt->perm_ok = true;
return true;
}
static void save_state_to_tss16(struct x86_emulate_ctxt *ctxt,
struct x86_emulate_ops *ops,
struct tss_segment_16 *tss)
{
struct decode_cache *c = &ctxt->decode;
tss->ip = c->eip;
tss->flag = ctxt->eflags;
tss->ax = c->regs[VCPU_REGS_RAX];
tss->cx = c->regs[VCPU_REGS_RCX];
tss->dx = c->regs[VCPU_REGS_RDX];
tss->bx = c->regs[VCPU_REGS_RBX];
tss->sp = c->regs[VCPU_REGS_RSP];
tss->bp = c->regs[VCPU_REGS_RBP];
tss->si = c->regs[VCPU_REGS_RSI];
tss->di = c->regs[VCPU_REGS_RDI];
tss->es = get_segment_selector(ctxt, VCPU_SREG_ES);
tss->cs = get_segment_selector(ctxt, VCPU_SREG_CS);
tss->ss = get_segment_selector(ctxt, VCPU_SREG_SS);
tss->ds = get_segment_selector(ctxt, VCPU_SREG_DS);
tss->ldt = get_segment_selector(ctxt, VCPU_SREG_LDTR);
}
static int load_state_from_tss16(struct x86_emulate_ctxt *ctxt,
struct x86_emulate_ops *ops,
struct tss_segment_16 *tss)
{
struct decode_cache *c = &ctxt->decode;
int ret;
c->eip = tss->ip;
ctxt->eflags = tss->flag | 2;
c->regs[VCPU_REGS_RAX] = tss->ax;
c->regs[VCPU_REGS_RCX] = tss->cx;
c->regs[VCPU_REGS_RDX] = tss->dx;
c->regs[VCPU_REGS_RBX] = tss->bx;
c->regs[VCPU_REGS_RSP] = tss->sp;
c->regs[VCPU_REGS_RBP] = tss->bp;
c->regs[VCPU_REGS_RSI] = tss->si;
c->regs[VCPU_REGS_RDI] = tss->di;
set_segment_selector(ctxt, tss->ldt, VCPU_SREG_LDTR);
set_segment_selector(ctxt, tss->es, VCPU_SREG_ES);
set_segment_selector(ctxt, tss->cs, VCPU_SREG_CS);
set_segment_selector(ctxt, tss->ss, VCPU_SREG_SS);
set_segment_selector(ctxt, tss->ds, VCPU_SREG_DS);
ret = load_segment_descriptor(ctxt, ops, tss->ldt, VCPU_SREG_LDTR);
if (ret != X86EMUL_CONTINUE)
return ret;
ret = load_segment_descriptor(ctxt, ops, tss->es, VCPU_SREG_ES);
if (ret != X86EMUL_CONTINUE)
return ret;
ret = load_segment_descriptor(ctxt, ops, tss->cs, VCPU_SREG_CS);
if (ret != X86EMUL_CONTINUE)
return ret;
ret = load_segment_descriptor(ctxt, ops, tss->ss, VCPU_SREG_SS);
if (ret != X86EMUL_CONTINUE)
return ret;
ret = load_segment_descriptor(ctxt, ops, tss->ds, VCPU_SREG_DS);
if (ret != X86EMUL_CONTINUE)
return ret;
return X86EMUL_CONTINUE;
}
static int task_switch_16(struct x86_emulate_ctxt *ctxt,
struct x86_emulate_ops *ops,
u16 tss_selector, u16 old_tss_sel,
ulong old_tss_base, struct desc_struct *new_desc)
{
struct tss_segment_16 tss_seg;
int ret;
u32 new_tss_base = get_desc_base(new_desc);
ret = ops->read_std(ctxt, old_tss_base, &tss_seg, sizeof tss_seg,
&ctxt->exception);
if (ret != X86EMUL_CONTINUE)
return ret;
save_state_to_tss16(ctxt, ops, &tss_seg);
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
return load_state_from_tss16(ctxt, ops, &tss_seg);
}
static void save_state_to_tss32(struct x86_emulate_ctxt *ctxt,
struct x86_emulate_ops *ops,
struct tss_segment_32 *tss)
{
struct decode_cache *c = &ctxt->decode;
tss->cr3 = ops->get_cr(ctxt, 3);
tss->eip = c->eip;
tss->eflags = ctxt->eflags;
tss->eax = c->regs[VCPU_REGS_RAX];
tss->ecx = c->regs[VCPU_REGS_RCX];
tss->edx = c->regs[VCPU_REGS_RDX];
tss->ebx = c->regs[VCPU_REGS_RBX];
tss->esp = c->regs[VCPU_REGS_RSP];
tss->ebp = c->regs[VCPU_REGS_RBP];
tss->esi = c->regs[VCPU_REGS_RSI];
tss->edi = c->regs[VCPU_REGS_RDI];
tss->es = get_segment_selector(ctxt, VCPU_SREG_ES);
tss->cs = get_segment_selector(ctxt, VCPU_SREG_CS);
tss->ss = get_segment_selector(ctxt, VCPU_SREG_SS);
tss->ds = get_segment_selector(ctxt, VCPU_SREG_DS);
tss->fs = get_segment_selector(ctxt, VCPU_SREG_FS);
tss->gs = get_segment_selector(ctxt, VCPU_SREG_GS);
tss->ldt_selector = get_segment_selector(ctxt, VCPU_SREG_LDTR);
}
static int load_state_from_tss32(struct x86_emulate_ctxt *ctxt,
struct x86_emulate_ops *ops,
struct tss_segment_32 *tss)
{
struct decode_cache *c = &ctxt->decode;
int ret;
if (ops->set_cr(ctxt, 3, tss->cr3))
return emulate_gp(ctxt, 0);
c->eip = tss->eip;
ctxt->eflags = tss->eflags | 2;
c->regs[VCPU_REGS_RAX] = tss->eax;
c->regs[VCPU_REGS_RCX] = tss->ecx;
c->regs[VCPU_REGS_RDX] = tss->edx;
c->regs[VCPU_REGS_RBX] = tss->ebx;
c->regs[VCPU_REGS_RSP] = tss->esp;
c->regs[VCPU_REGS_RBP] = tss->ebp;
c->regs[VCPU_REGS_RSI] = tss->esi;
c->regs[VCPU_REGS_RDI] = tss->edi;
set_segment_selector(ctxt, tss->ldt_selector, VCPU_SREG_LDTR);
set_segment_selector(ctxt, tss->es, VCPU_SREG_ES);
set_segment_selector(ctxt, tss->cs, VCPU_SREG_CS);
set_segment_selector(ctxt, tss->ss, VCPU_SREG_SS);
set_segment_selector(ctxt, tss->ds, VCPU_SREG_DS);
set_segment_selector(ctxt, tss->fs, VCPU_SREG_FS);
set_segment_selector(ctxt, tss->gs, VCPU_SREG_GS);
ret = load_segment_descriptor(ctxt, ops, tss->ldt_selector, VCPU_SREG_LDTR);
if (ret != X86EMUL_CONTINUE)
return ret;
ret = load_segment_descriptor(ctxt, ops, tss->es, VCPU_SREG_ES);
if (ret != X86EMUL_CONTINUE)
return ret;
ret = load_segment_descriptor(ctxt, ops, tss->cs, VCPU_SREG_CS);
if (ret != X86EMUL_CONTINUE)
return ret;
ret = load_segment_descriptor(ctxt, ops, tss->ss, VCPU_SREG_SS);
if (ret != X86EMUL_CONTINUE)
return ret;
ret = load_segment_descriptor(ctxt, ops, tss->ds, VCPU_SREG_DS);
if (ret != X86EMUL_CONTINUE)
return ret;
ret = load_segment_descriptor(ctxt, ops, tss->fs, VCPU_SREG_FS);
if (ret != X86EMUL_CONTINUE)
return ret;
ret = load_segment_descriptor(ctxt, ops, tss->gs, VCPU_SREG_GS);
if (ret != X86EMUL_CONTINUE)
return ret;
return X86EMUL_CONTINUE;
}
static int task_switch_32(struct x86_emulate_ctxt *ctxt,
struct x86_emulate_ops *ops,
u16 tss_selector, u16 old_tss_sel,
ulong old_tss_base, struct desc_struct *new_desc)
{
struct tss_segment_32 tss_seg;
int ret;
u32 new_tss_base = get_desc_base(new_desc);
ret = ops->read_std(ctxt, old_tss_base, &tss_seg, sizeof tss_seg,
&ctxt->exception);
if (ret != X86EMUL_CONTINUE)
return ret;
save_state_to_tss32(ctxt, ops, &tss_seg);
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
return load_state_from_tss32(ctxt, ops, &tss_seg);
}
static int emulator_do_task_switch(struct x86_emulate_ctxt *ctxt,
struct x86_emulate_ops *ops,
u16 tss_selector, int reason,
bool has_error_code, u32 error_code)
{
struct desc_struct curr_tss_desc, next_tss_desc;
int ret;
u16 old_tss_sel = get_segment_selector(ctxt, VCPU_SREG_TR);
ulong old_tss_base =
ops->get_cached_segment_base(ctxt, VCPU_SREG_TR);
u32 desc_limit;
ret = read_segment_descriptor(ctxt, ops, tss_selector, &next_tss_desc);
if (ret != X86EMUL_CONTINUE)
return ret;
ret = read_segment_descriptor(ctxt, ops, old_tss_sel, &curr_tss_desc);
if (ret != X86EMUL_CONTINUE)
return ret;
if (reason != TASK_SWITCH_IRET) {
if ((tss_selector & 3) > next_tss_desc.dpl ||
ops->cpl(ctxt) > next_tss_desc.dpl)
return emulate_gp(ctxt, 0);
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
write_segment_descriptor(ctxt, ops, old_tss_sel,
&curr_tss_desc);
}
if (reason == TASK_SWITCH_IRET)
ctxt->eflags = ctxt->eflags & ~X86_EFLAGS_NT;
if (reason != TASK_SWITCH_CALL && reason != TASK_SWITCH_GATE)
old_tss_sel = 0xffff;
if (next_tss_desc.type & 8)
ret = task_switch_32(ctxt, ops, tss_selector, old_tss_sel,
old_tss_base, &next_tss_desc);
else
ret = task_switch_16(ctxt, ops, tss_selector, old_tss_sel,
old_tss_base, &next_tss_desc);
if (ret != X86EMUL_CONTINUE)
return ret;
if (reason == TASK_SWITCH_CALL || reason == TASK_SWITCH_GATE)
ctxt->eflags = ctxt->eflags | X86_EFLAGS_NT;
if (reason != TASK_SWITCH_IRET) {
next_tss_desc.type |= (1 << 1);
write_segment_descriptor(ctxt, ops, tss_selector,
&next_tss_desc);
}
ops->set_cr(ctxt, 0, ops->get_cr(ctxt, 0) | X86_CR0_TS);
ops->set_segment(ctxt, tss_selector, &next_tss_desc, 0, VCPU_SREG_TR);
if (has_error_code) {
struct decode_cache *c = &ctxt->decode;
c->op_bytes = c->ad_bytes = (next_tss_desc.type & 8) ? 4 : 2;
c->lock_prefix = 0;
c->src.val = (unsigned long) error_code;
ret = em_push(ctxt);
}
return ret;
}
int emulator_task_switch(struct x86_emulate_ctxt *ctxt,
u16 tss_selector, int reason,
bool has_error_code, u32 error_code)
{
struct x86_emulate_ops *ops = ctxt->ops;
struct decode_cache *c = &ctxt->decode;
int rc;
c->eip = ctxt->eip;
c->dst.type = OP_NONE;
rc = emulator_do_task_switch(ctxt, ops, tss_selector, reason,
has_error_code, error_code);
if (rc == X86EMUL_CONTINUE)
ctxt->eip = c->eip;
return (rc == X86EMUL_UNHANDLEABLE) ? EMULATION_FAILED : EMULATION_OK;
}
static void string_addr_inc(struct x86_emulate_ctxt *ctxt, unsigned seg,
int reg, struct operand *op)
{
struct decode_cache *c = &ctxt->decode;
int df = (ctxt->eflags & EFLG_DF) ? -1 : 1;
register_address_increment(c, &c->regs[reg], df * op->bytes);
op->addr.mem.ea = register_address(c, c->regs[reg]);
op->addr.mem.seg = seg;
}
static int em_das(struct x86_emulate_ctxt *ctxt)
{
struct decode_cache *c = &ctxt->decode;
u8 al, old_al;
bool af, cf, old_cf;
cf = ctxt->eflags & X86_EFLAGS_CF;
al = c->dst.val;
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
c->dst.val = al;
c->src.type = OP_IMM;
c->src.val = 0;
c->src.bytes = 1;
emulate_2op_SrcV("or", c->src, c->dst, ctxt->eflags);
ctxt->eflags &= ~(X86_EFLAGS_AF | X86_EFLAGS_CF);
if (cf)
ctxt->eflags |= X86_EFLAGS_CF;
if (af)
ctxt->eflags |= X86_EFLAGS_AF;
return X86EMUL_CONTINUE;
}
static int em_call_far(struct x86_emulate_ctxt *ctxt)
{
struct decode_cache *c = &ctxt->decode;
u16 sel, old_cs;
ulong old_eip;
int rc;
old_cs = get_segment_selector(ctxt, VCPU_SREG_CS);
old_eip = c->eip;
memcpy(&sel, c->src.valptr + c->op_bytes, 2);
if (load_segment_descriptor(ctxt, ctxt->ops, sel, VCPU_SREG_CS))
return X86EMUL_CONTINUE;
c->eip = 0;
memcpy(&c->eip, c->src.valptr, c->op_bytes);
c->src.val = old_cs;
rc = em_push(ctxt);
if (rc != X86EMUL_CONTINUE)
return rc;
c->src.val = old_eip;
return em_push(ctxt);
}
static int em_ret_near_imm(struct x86_emulate_ctxt *ctxt)
{
struct decode_cache *c = &ctxt->decode;
int rc;
c->dst.type = OP_REG;
c->dst.addr.reg = &c->eip;
c->dst.bytes = c->op_bytes;
rc = emulate_pop(ctxt, &c->dst.val, c->op_bytes);
if (rc != X86EMUL_CONTINUE)
return rc;
register_address_increment(c, &c->regs[VCPU_REGS_RSP], c->src.val);
return X86EMUL_CONTINUE;
}
static int em_add(struct x86_emulate_ctxt *ctxt)
{
struct decode_cache *c = &ctxt->decode;
emulate_2op_SrcV("add", c->src, c->dst, ctxt->eflags);
return X86EMUL_CONTINUE;
}
static int em_or(struct x86_emulate_ctxt *ctxt)
{
struct decode_cache *c = &ctxt->decode;
emulate_2op_SrcV("or", c->src, c->dst, ctxt->eflags);
return X86EMUL_CONTINUE;
}
static int em_adc(struct x86_emulate_ctxt *ctxt)
{
struct decode_cache *c = &ctxt->decode;
emulate_2op_SrcV("adc", c->src, c->dst, ctxt->eflags);
return X86EMUL_CONTINUE;
}
static int em_sbb(struct x86_emulate_ctxt *ctxt)
{
struct decode_cache *c = &ctxt->decode;
emulate_2op_SrcV("sbb", c->src, c->dst, ctxt->eflags);
return X86EMUL_CONTINUE;
}
static int em_and(struct x86_emulate_ctxt *ctxt)
{
struct decode_cache *c = &ctxt->decode;
emulate_2op_SrcV("and", c->src, c->dst, ctxt->eflags);
return X86EMUL_CONTINUE;
}
static int em_sub(struct x86_emulate_ctxt *ctxt)
{
struct decode_cache *c = &ctxt->decode;
emulate_2op_SrcV("sub", c->src, c->dst, ctxt->eflags);
return X86EMUL_CONTINUE;
}
static int em_xor(struct x86_emulate_ctxt *ctxt)
{
struct decode_cache *c = &ctxt->decode;
emulate_2op_SrcV("xor", c->src, c->dst, ctxt->eflags);
return X86EMUL_CONTINUE;
}
static int em_cmp(struct x86_emulate_ctxt *ctxt)
{
struct decode_cache *c = &ctxt->decode;
emulate_2op_SrcV("cmp", c->src, c->dst, ctxt->eflags);
c->dst.type = OP_NONE;
return X86EMUL_CONTINUE;
}
static int em_imul(struct x86_emulate_ctxt *ctxt)
{
struct decode_cache *c = &ctxt->decode;
emulate_2op_SrcV_nobyte("imul", c->src, c->dst, ctxt->eflags);
return X86EMUL_CONTINUE;
}
static int em_imul_3op(struct x86_emulate_ctxt *ctxt)
{
struct decode_cache *c = &ctxt->decode;
c->dst.val = c->src2.val;
return em_imul(ctxt);
}
static int em_cwd(struct x86_emulate_ctxt *ctxt)
{
struct decode_cache *c = &ctxt->decode;
c->dst.type = OP_REG;
c->dst.bytes = c->src.bytes;
c->dst.addr.reg = &c->regs[VCPU_REGS_RDX];
c->dst.val = ~((c->src.val >> (c->src.bytes * 8 - 1)) - 1);
return X86EMUL_CONTINUE;
}
static int em_rdtsc(struct x86_emulate_ctxt *ctxt)
{
struct decode_cache *c = &ctxt->decode;
u64 tsc = 0;
ctxt->ops->get_msr(ctxt, MSR_IA32_TSC, &tsc);
c->regs[VCPU_REGS_RAX] = (u32)tsc;
c->regs[VCPU_REGS_RDX] = tsc >> 32;
return X86EMUL_CONTINUE;
}
static int em_mov(struct x86_emulate_ctxt *ctxt)
{
struct decode_cache *c = &ctxt->decode;
c->dst.val = c->src.val;
return X86EMUL_CONTINUE;
}
static int em_movdqu(struct x86_emulate_ctxt *ctxt)
{
struct decode_cache *c = &ctxt->decode;
memcpy(&c->dst.vec_val, &c->src.vec_val, c->op_bytes);
return X86EMUL_CONTINUE;
}
static int em_invlpg(struct x86_emulate_ctxt *ctxt)
{
struct decode_cache *c = &ctxt->decode;
int rc;
ulong linear;
rc = linearize(ctxt, c->src.addr.mem, 1, false, &linear);
if (rc == X86EMUL_CONTINUE)
ctxt->ops->invlpg(ctxt, linear);
c->dst.type = OP_NONE;
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
struct decode_cache *c = &ctxt->decode;
int rc;
if (c->modrm_mod != 3 || c->modrm_rm != 1)
return X86EMUL_UNHANDLEABLE;
rc = ctxt->ops->fix_hypercall(ctxt);
if (rc != X86EMUL_CONTINUE)
return rc;
c->eip = ctxt->eip;
c->dst.type = OP_NONE;
return X86EMUL_CONTINUE;
}
static int em_lgdt(struct x86_emulate_ctxt *ctxt)
{
struct decode_cache *c = &ctxt->decode;
struct desc_ptr desc_ptr;
int rc;
rc = read_descriptor(ctxt, c->src.addr.mem,
&desc_ptr.size, &desc_ptr.address,
c->op_bytes);
if (rc != X86EMUL_CONTINUE)
return rc;
ctxt->ops->set_gdt(ctxt, &desc_ptr);
c->dst.type = OP_NONE;
return X86EMUL_CONTINUE;
}
static int em_vmmcall(struct x86_emulate_ctxt *ctxt)
{
struct decode_cache *c = &ctxt->decode;
int rc;
rc = ctxt->ops->fix_hypercall(ctxt);
c->dst.type = OP_NONE;
return rc;
}
static int em_lidt(struct x86_emulate_ctxt *ctxt)
{
struct decode_cache *c = &ctxt->decode;
struct desc_ptr desc_ptr;
int rc;
rc = read_descriptor(ctxt, c->src.addr.mem,
&desc_ptr.size, &desc_ptr.address,
c->op_bytes);
if (rc != X86EMUL_CONTINUE)
return rc;
ctxt->ops->set_idt(ctxt, &desc_ptr);
c->dst.type = OP_NONE;
return X86EMUL_CONTINUE;
}
static int em_smsw(struct x86_emulate_ctxt *ctxt)
{
struct decode_cache *c = &ctxt->decode;
c->dst.bytes = 2;
c->dst.val = ctxt->ops->get_cr(ctxt, 0);
return X86EMUL_CONTINUE;
}
static int em_lmsw(struct x86_emulate_ctxt *ctxt)
{
struct decode_cache *c = &ctxt->decode;
ctxt->ops->set_cr(ctxt, 0, (ctxt->ops->get_cr(ctxt, 0) & ~0x0eul)
| (c->src.val & 0x0f));
c->dst.type = OP_NONE;
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
struct decode_cache *c = &ctxt->decode;
if (!valid_cr(c->modrm_reg))
return emulate_ud(ctxt);
return X86EMUL_CONTINUE;
}
static int check_cr_write(struct x86_emulate_ctxt *ctxt)
{
struct decode_cache *c = &ctxt->decode;
u64 new_val = c->src.val64;
int cr = c->modrm_reg;
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
u64 cr4;
cr4 = ctxt->ops->get_cr(ctxt, 4);
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
struct decode_cache *c = &ctxt->decode;
int dr = c->modrm_reg;
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
struct decode_cache *c = &ctxt->decode;
u64 new_val = c->src.val64;
int dr = c->modrm_reg;
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
u64 rax = ctxt->decode.regs[VCPU_REGS_RAX];
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
u64 rcx = ctxt->decode.regs[VCPU_REGS_RCX];
if ((!(cr4 & X86_CR4_PCE) && ctxt->ops->cpl(ctxt)) ||
(rcx > 3))
return emulate_gp(ctxt, 0);
return X86EMUL_CONTINUE;
}
static int check_perm_in(struct x86_emulate_ctxt *ctxt)
{
struct decode_cache *c = &ctxt->decode;
c->dst.bytes = min(c->dst.bytes, 4u);
if (!emulator_io_permited(ctxt, ctxt->ops, c->src.val, c->dst.bytes))
return emulate_gp(ctxt, 0);
return X86EMUL_CONTINUE;
}
static int check_perm_out(struct x86_emulate_ctxt *ctxt)
{
struct decode_cache *c = &ctxt->decode;
c->src.bytes = min(c->src.bytes, 4u);
if (!emulator_io_permited(ctxt, ctxt->ops, c->dst.val, c->src.bytes))
return emulate_gp(ctxt, 0);
return X86EMUL_CONTINUE;
}
static unsigned imm_size(struct decode_cache *c)
{
unsigned size;
size = (c->d & ByteOp) ? 1 : c->op_bytes;
if (size == 8)
size = 4;
return size;
}
static int decode_imm(struct x86_emulate_ctxt *ctxt, struct operand *op,
unsigned size, bool sign_extension)
{
struct decode_cache *c = &ctxt->decode;
struct x86_emulate_ops *ops = ctxt->ops;
int rc = X86EMUL_CONTINUE;
op->type = OP_IMM;
op->bytes = size;
op->addr.mem.ea = c->eip;
switch (op->bytes) {
case 1:
op->val = insn_fetch(s8, 1, c->eip);
break;
case 2:
op->val = insn_fetch(s16, 2, c->eip);
break;
case 4:
op->val = insn_fetch(s32, 4, c->eip);
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
int
x86_decode_insn(struct x86_emulate_ctxt *ctxt, void *insn, int insn_len)
{
struct x86_emulate_ops *ops = ctxt->ops;
struct decode_cache *c = &ctxt->decode;
int rc = X86EMUL_CONTINUE;
int mode = ctxt->mode;
int def_op_bytes, def_ad_bytes, goffset, simd_prefix;
bool op_prefix = false;
struct opcode opcode;
struct operand memop = { .type = OP_NONE }, *memopp = NULL;
c->eip = ctxt->eip;
c->fetch.start = c->eip;
c->fetch.end = c->fetch.start + insn_len;
if (insn_len > 0)
memcpy(c->fetch.data, insn, insn_len);
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
return -1;
}
c->op_bytes = def_op_bytes;
c->ad_bytes = def_ad_bytes;
for (;;) {
switch (c->b = insn_fetch(u8, 1, c->eip)) {
case 0x66:
op_prefix = true;
c->op_bytes = def_op_bytes ^ 6;
break;
case 0x67:
if (mode == X86EMUL_MODE_PROT64)
c->ad_bytes = def_ad_bytes ^ 12;
else
c->ad_bytes = def_ad_bytes ^ 6;
break;
case 0x26:
case 0x2e:
case 0x36:
case 0x3e:
set_seg_override(c, (c->b >> 3) & 3);
break;
case 0x64:
case 0x65:
set_seg_override(c, c->b & 7);
break;
case 0x40 ... 0x4f:
if (mode != X86EMUL_MODE_PROT64)
goto done_prefixes;
c->rex_prefix = c->b;
continue;
case 0xf0:
c->lock_prefix = 1;
break;
case 0xf2:
case 0xf3:
c->rep_prefix = c->b;
break;
default:
goto done_prefixes;
}
c->rex_prefix = 0;
}
done_prefixes:
if (c->rex_prefix & 8)
c->op_bytes = 8;
opcode = opcode_table[c->b];
if (c->b == 0x0f) {
c->twobyte = 1;
c->b = insn_fetch(u8, 1, c->eip);
opcode = twobyte_table[c->b];
}
c->d = opcode.flags;
while (c->d & GroupMask) {
switch (c->d & GroupMask) {
case Group:
c->modrm = insn_fetch(u8, 1, c->eip);
--c->eip;
goffset = (c->modrm >> 3) & 7;
opcode = opcode.u.group[goffset];
break;
case GroupDual:
c->modrm = insn_fetch(u8, 1, c->eip);
--c->eip;
goffset = (c->modrm >> 3) & 7;
if ((c->modrm >> 6) == 3)
opcode = opcode.u.gdual->mod3[goffset];
else
opcode = opcode.u.gdual->mod012[goffset];
break;
case RMExt:
goffset = c->modrm & 7;
opcode = opcode.u.group[goffset];
break;
case Prefix:
if (c->rep_prefix && op_prefix)
return X86EMUL_UNHANDLEABLE;
simd_prefix = op_prefix ? 0x66 : c->rep_prefix;
switch (simd_prefix) {
case 0x00: opcode = opcode.u.gprefix->pfx_no; break;
case 0x66: opcode = opcode.u.gprefix->pfx_66; break;
case 0xf2: opcode = opcode.u.gprefix->pfx_f2; break;
case 0xf3: opcode = opcode.u.gprefix->pfx_f3; break;
}
break;
default:
return X86EMUL_UNHANDLEABLE;
}
c->d &= ~GroupMask;
c->d |= opcode.flags;
}
c->execute = opcode.u.execute;
c->check_perm = opcode.check_perm;
c->intercept = opcode.intercept;
if (c->d == 0 || (c->d & Undefined))
return -1;
if (!(c->d & VendorSpecific) && ctxt->only_vendor_specific_insn)
return -1;
if (mode == X86EMUL_MODE_PROT64 && (c->d & Stack))
c->op_bytes = 8;
if (c->d & Op3264) {
if (mode == X86EMUL_MODE_PROT64)
c->op_bytes = 8;
else
c->op_bytes = 4;
}
if (c->d & Sse)
c->op_bytes = 16;
if (c->d & ModRM) {
rc = decode_modrm(ctxt, ops, &memop);
if (!c->has_seg_override)
set_seg_override(c, c->modrm_seg);
} else if (c->d & MemAbs)
rc = decode_abs(ctxt, ops, &memop);
if (rc != X86EMUL_CONTINUE)
goto done;
if (!c->has_seg_override)
set_seg_override(c, VCPU_SREG_DS);
memop.addr.mem.seg = seg_override(ctxt, c);
if (memop.type == OP_MEM && c->ad_bytes != 8)
memop.addr.mem.ea = (u32)memop.addr.mem.ea;
switch (c->d & SrcMask) {
case SrcNone:
break;
case SrcReg:
decode_register_operand(ctxt, &c->src, c, 0);
break;
case SrcMem16:
memop.bytes = 2;
goto srcmem_common;
case SrcMem32:
memop.bytes = 4;
goto srcmem_common;
case SrcMem:
memop.bytes = (c->d & ByteOp) ? 1 :
c->op_bytes;
srcmem_common:
c->src = memop;
memopp = &c->src;
break;
case SrcImmU16:
rc = decode_imm(ctxt, &c->src, 2, false);
break;
case SrcImm:
rc = decode_imm(ctxt, &c->src, imm_size(c), true);
break;
case SrcImmU:
rc = decode_imm(ctxt, &c->src, imm_size(c), false);
break;
case SrcImmByte:
rc = decode_imm(ctxt, &c->src, 1, true);
break;
case SrcImmUByte:
rc = decode_imm(ctxt, &c->src, 1, false);
break;
case SrcAcc:
c->src.type = OP_REG;
c->src.bytes = (c->d & ByteOp) ? 1 : c->op_bytes;
c->src.addr.reg = &c->regs[VCPU_REGS_RAX];
fetch_register_operand(&c->src);
break;
case SrcOne:
c->src.bytes = 1;
c->src.val = 1;
break;
case SrcSI:
c->src.type = OP_MEM;
c->src.bytes = (c->d & ByteOp) ? 1 : c->op_bytes;
c->src.addr.mem.ea =
register_address(c, c->regs[VCPU_REGS_RSI]);
c->src.addr.mem.seg = seg_override(ctxt, c);
c->src.val = 0;
break;
case SrcImmFAddr:
c->src.type = OP_IMM;
c->src.addr.mem.ea = c->eip;
c->src.bytes = c->op_bytes + 2;
insn_fetch_arr(c->src.valptr, c->src.bytes, c->eip);
break;
case SrcMemFAddr:
memop.bytes = c->op_bytes + 2;
goto srcmem_common;
break;
case SrcDX:
c->src.type = OP_REG;
c->src.bytes = 2;
c->src.addr.reg = &c->regs[VCPU_REGS_RDX];
fetch_register_operand(&c->src);
break;
}
if (rc != X86EMUL_CONTINUE)
goto done;
switch (c->d & Src2Mask) {
case Src2None:
break;
case Src2CL:
c->src2.bytes = 1;
c->src2.val = c->regs[VCPU_REGS_RCX] & 0x8;
break;
case Src2ImmByte:
rc = decode_imm(ctxt, &c->src2, 1, true);
break;
case Src2One:
c->src2.bytes = 1;
c->src2.val = 1;
break;
case Src2Imm:
rc = decode_imm(ctxt, &c->src2, imm_size(c), true);
break;
}
if (rc != X86EMUL_CONTINUE)
goto done;
switch (c->d & DstMask) {
case DstReg:
decode_register_operand(ctxt, &c->dst, c,
c->twobyte && (c->b == 0xb6 || c->b == 0xb7));
break;
case DstImmUByte:
c->dst.type = OP_IMM;
c->dst.addr.mem.ea = c->eip;
c->dst.bytes = 1;
c->dst.val = insn_fetch(u8, 1, c->eip);
break;
case DstMem:
case DstMem64:
c->dst = memop;
memopp = &c->dst;
if ((c->d & DstMask) == DstMem64)
c->dst.bytes = 8;
else
c->dst.bytes = (c->d & ByteOp) ? 1 : c->op_bytes;
if (c->d & BitOp)
fetch_bit_operand(c);
c->dst.orig_val = c->dst.val;
break;
case DstAcc:
c->dst.type = OP_REG;
c->dst.bytes = (c->d & ByteOp) ? 1 : c->op_bytes;
c->dst.addr.reg = &c->regs[VCPU_REGS_RAX];
fetch_register_operand(&c->dst);
c->dst.orig_val = c->dst.val;
break;
case DstDI:
c->dst.type = OP_MEM;
c->dst.bytes = (c->d & ByteOp) ? 1 : c->op_bytes;
c->dst.addr.mem.ea =
register_address(c, c->regs[VCPU_REGS_RDI]);
c->dst.addr.mem.seg = VCPU_SREG_ES;
c->dst.val = 0;
break;
case DstDX:
c->dst.type = OP_REG;
c->dst.bytes = 2;
c->dst.addr.reg = &c->regs[VCPU_REGS_RDX];
fetch_register_operand(&c->dst);
break;
case ImplicitOps:
default:
c->dst.type = OP_NONE;
break;
}
done:
if (memopp && memopp->type == OP_MEM && c->rip_relative)
memopp->addr.mem.ea += c->eip;
return (rc == X86EMUL_UNHANDLEABLE) ? EMULATION_FAILED : EMULATION_OK;
}
static bool string_insn_completed(struct x86_emulate_ctxt *ctxt)
{
struct decode_cache *c = &ctxt->decode;
if (((c->b == 0xa6) || (c->b == 0xa7) ||
(c->b == 0xae) || (c->b == 0xaf))
&& (((c->rep_prefix == REPE_PREFIX) &&
((ctxt->eflags & EFLG_ZF) == 0))
|| ((c->rep_prefix == REPNE_PREFIX) &&
((ctxt->eflags & EFLG_ZF) == EFLG_ZF))))
return true;
return false;
}
int
x86_emulate_insn(struct x86_emulate_ctxt *ctxt)
{
struct x86_emulate_ops *ops = ctxt->ops;
u64 msr_data;
struct decode_cache *c = &ctxt->decode;
int rc = X86EMUL_CONTINUE;
int saved_dst_type = c->dst.type;
int irq;
ctxt->decode.mem_read.pos = 0;
if (ctxt->mode == X86EMUL_MODE_PROT64 && (c->d & No64)) {
rc = emulate_ud(ctxt);
goto done;
}
if (c->lock_prefix && (!(c->d & Lock) || c->dst.type != OP_MEM)) {
rc = emulate_ud(ctxt);
goto done;
}
if ((c->d & SrcMask) == SrcMemFAddr && c->src.type != OP_MEM) {
rc = emulate_ud(ctxt);
goto done;
}
if ((c->d & Sse)
&& ((ops->get_cr(ctxt, 0) & X86_CR0_EM)
|| !(ops->get_cr(ctxt, 4) & X86_CR4_OSFXSR))) {
rc = emulate_ud(ctxt);
goto done;
}
if ((c->d & Sse) && (ops->get_cr(ctxt, 0) & X86_CR0_TS)) {
rc = emulate_nm(ctxt);
goto done;
}
if (unlikely(ctxt->guest_mode) && c->intercept) {
rc = emulator_check_intercept(ctxt, c->intercept,
X86_ICPT_PRE_EXCEPT);
if (rc != X86EMUL_CONTINUE)
goto done;
}
if ((c->d & Priv) && ops->cpl(ctxt)) {
rc = emulate_gp(ctxt, 0);
goto done;
}
if ((c->d & Prot) && !(ctxt->mode & X86EMUL_MODE_PROT)) {
rc = emulate_ud(ctxt);
goto done;
}
if (c->check_perm) {
rc = c->check_perm(ctxt);
if (rc != X86EMUL_CONTINUE)
goto done;
}
if (unlikely(ctxt->guest_mode) && c->intercept) {
rc = emulator_check_intercept(ctxt, c->intercept,
X86_ICPT_POST_EXCEPT);
if (rc != X86EMUL_CONTINUE)
goto done;
}
if (c->rep_prefix && (c->d & String)) {
if (address_mask(c, c->regs[VCPU_REGS_RCX]) == 0) {
ctxt->eip = c->eip;
goto done;
}
}
if ((c->src.type == OP_MEM) && !(c->d & NoAccess)) {
rc = segmented_read(ctxt, c->src.addr.mem,
c->src.valptr, c->src.bytes);
if (rc != X86EMUL_CONTINUE)
goto done;
c->src.orig_val64 = c->src.val64;
}
if (c->src2.type == OP_MEM) {
rc = segmented_read(ctxt, c->src2.addr.mem,
&c->src2.val, c->src2.bytes);
if (rc != X86EMUL_CONTINUE)
goto done;
}
if ((c->d & DstMask) == ImplicitOps)
goto special_insn;
if ((c->dst.type == OP_MEM) && !(c->d & Mov)) {
rc = segmented_read(ctxt, c->dst.addr.mem,
&c->dst.val, c->dst.bytes);
if (rc != X86EMUL_CONTINUE)
goto done;
}
c->dst.orig_val = c->dst.val;
special_insn:
if (unlikely(ctxt->guest_mode) && c->intercept) {
rc = emulator_check_intercept(ctxt, c->intercept,
X86_ICPT_POST_MEMACCESS);
if (rc != X86EMUL_CONTINUE)
goto done;
}
if (c->execute) {
rc = c->execute(ctxt);
if (rc != X86EMUL_CONTINUE)
goto done;
goto writeback;
}
if (c->twobyte)
goto twobyte_insn;
switch (c->b) {
case 0x06:
rc = emulate_push_sreg(ctxt, ops, VCPU_SREG_ES);
break;
case 0x07:
rc = emulate_pop_sreg(ctxt, ops, VCPU_SREG_ES);
break;
case 0x0e:
rc = emulate_push_sreg(ctxt, ops, VCPU_SREG_CS);
break;
case 0x16:
rc = emulate_push_sreg(ctxt, ops, VCPU_SREG_SS);
break;
case 0x17:
rc = emulate_pop_sreg(ctxt, ops, VCPU_SREG_SS);
break;
case 0x1e:
rc = emulate_push_sreg(ctxt, ops, VCPU_SREG_DS);
break;
case 0x1f:
rc = emulate_pop_sreg(ctxt, ops, VCPU_SREG_DS);
break;
case 0x40 ... 0x47:
emulate_1op("inc", c->dst, ctxt->eflags);
break;
case 0x48 ... 0x4f:
emulate_1op("dec", c->dst, ctxt->eflags);
break;
case 0x63:
if (ctxt->mode != X86EMUL_MODE_PROT64)
goto cannot_emulate;
c->dst.val = (s32) c->src.val;
break;
case 0x6c:
case 0x6d:
c->src.val = c->regs[VCPU_REGS_RDX];
goto do_io_in;
case 0x6e:
case 0x6f:
c->dst.val = c->regs[VCPU_REGS_RDX];
goto do_io_out;
break;
case 0x70 ... 0x7f:
if (test_cc(c->b, ctxt->eflags))
jmp_rel(c, c->src.val);
break;
case 0x84 ... 0x85:
test:
emulate_2op_SrcV("test", c->src, c->dst, ctxt->eflags);
break;
case 0x86 ... 0x87:
xchg:
c->src.val = c->dst.val;
write_register_operand(&c->src);
c->dst.val = c->src.orig_val;
c->lock_prefix = 1;
break;
case 0x8c:
if (c->modrm_reg > VCPU_SREG_GS) {
rc = emulate_ud(ctxt);
goto done;
}
c->dst.val = get_segment_selector(ctxt, c->modrm_reg);
break;
case 0x8d:
c->dst.val = c->src.addr.mem.ea;
break;
case 0x8e: {
uint16_t sel;
sel = c->src.val;
if (c->modrm_reg == VCPU_SREG_CS ||
c->modrm_reg > VCPU_SREG_GS) {
rc = emulate_ud(ctxt);
goto done;
}
if (c->modrm_reg == VCPU_SREG_SS)
ctxt->interruptibility = KVM_X86_SHADOW_INT_MOV_SS;
rc = load_segment_descriptor(ctxt, ops, sel, c->modrm_reg);
c->dst.type = OP_NONE;
break;
}
case 0x8f:
rc = em_grp1a(ctxt);
break;
case 0x90 ... 0x97:
if (c->dst.addr.reg == &c->regs[VCPU_REGS_RAX])
break;
goto xchg;
case 0x98:
switch (c->op_bytes) {
case 2: c->dst.val = (s8)c->dst.val; break;
case 4: c->dst.val = (s16)c->dst.val; break;
case 8: c->dst.val = (s32)c->dst.val; break;
}
break;
case 0xa8 ... 0xa9:
goto test;
case 0xc0 ... 0xc1:
rc = em_grp2(ctxt);
break;
case 0xc3:
c->dst.type = OP_REG;
c->dst.addr.reg = &c->eip;
c->dst.bytes = c->op_bytes;
rc = em_pop(ctxt);
break;
case 0xc4:
rc = emulate_load_segment(ctxt, ops, VCPU_SREG_ES);
break;
case 0xc5:
rc = emulate_load_segment(ctxt, ops, VCPU_SREG_DS);
break;
case 0xcb:
rc = emulate_ret_far(ctxt, ops);
break;
case 0xcc:
irq = 3;
goto do_interrupt;
case 0xcd:
irq = c->src.val;
do_interrupt:
rc = emulate_int(ctxt, ops, irq);
break;
case 0xce:
if (ctxt->eflags & EFLG_OF) {
irq = 4;
goto do_interrupt;
}
break;
case 0xcf:
rc = emulate_iret(ctxt, ops);
break;
case 0xd0 ... 0xd1:
rc = em_grp2(ctxt);
break;
case 0xd2 ... 0xd3:
c->src.val = c->regs[VCPU_REGS_RCX];
rc = em_grp2(ctxt);
break;
case 0xe0 ... 0xe2:
register_address_increment(c, &c->regs[VCPU_REGS_RCX], -1);
if (address_mask(c, c->regs[VCPU_REGS_RCX]) != 0 &&
(c->b == 0xe2 || test_cc(c->b ^ 0x5, ctxt->eflags)))
jmp_rel(c, c->src.val);
break;
case 0xe3:
if (address_mask(c, c->regs[VCPU_REGS_RCX]) == 0)
jmp_rel(c, c->src.val);
break;
case 0xe4:
case 0xe5:
goto do_io_in;
case 0xe6:
case 0xe7:
goto do_io_out;
case 0xe8: {
long int rel = c->src.val;
c->src.val = (unsigned long) c->eip;
jmp_rel(c, rel);
rc = em_push(ctxt);
break;
}
case 0xe9:
goto jmp;
case 0xea:
rc = em_jmp_far(ctxt);
break;
case 0xeb:
jmp:
jmp_rel(c, c->src.val);
c->dst.type = OP_NONE;
break;
case 0xec:
case 0xed:
do_io_in:
if (!pio_in_emulated(ctxt, ops, c->dst.bytes, c->src.val,
&c->dst.val))
goto done;
break;
case 0xee:
case 0xef:
do_io_out:
ops->pio_out_emulated(ctxt, c->src.bytes, c->dst.val,
&c->src.val, 1);
c->dst.type = OP_NONE;
break;
case 0xf4:
ctxt->ops->halt(ctxt);
break;
case 0xf5:
ctxt->eflags ^= EFLG_CF;
break;
case 0xf6 ... 0xf7:
rc = em_grp3(ctxt);
break;
case 0xf8:
ctxt->eflags &= ~EFLG_CF;
break;
case 0xf9:
ctxt->eflags |= EFLG_CF;
break;
case 0xfa:
if (emulator_bad_iopl(ctxt, ops)) {
rc = emulate_gp(ctxt, 0);
goto done;
} else
ctxt->eflags &= ~X86_EFLAGS_IF;
break;
case 0xfb:
if (emulator_bad_iopl(ctxt, ops)) {
rc = emulate_gp(ctxt, 0);
goto done;
} else {
ctxt->interruptibility = KVM_X86_SHADOW_INT_STI;
ctxt->eflags |= X86_EFLAGS_IF;
}
break;
case 0xfc:
ctxt->eflags &= ~EFLG_DF;
break;
case 0xfd:
ctxt->eflags |= EFLG_DF;
break;
case 0xfe:
rc = em_grp45(ctxt);
break;
case 0xff:
rc = em_grp45(ctxt);
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
c->dst.type = saved_dst_type;
if ((c->d & SrcMask) == SrcSI)
string_addr_inc(ctxt, seg_override(ctxt, c),
VCPU_REGS_RSI, &c->src);
if ((c->d & DstMask) == DstDI)
string_addr_inc(ctxt, VCPU_SREG_ES, VCPU_REGS_RDI,
&c->dst);
if (c->rep_prefix && (c->d & String)) {
struct read_cache *r = &ctxt->decode.io_read;
register_address_increment(c, &c->regs[VCPU_REGS_RCX], -1);
if (!string_insn_completed(ctxt)) {
if ((r->end != 0 || c->regs[VCPU_REGS_RCX] & 0x3ff) &&
(r->end == 0 || r->end != r->pos)) {
ctxt->decode.mem_read.end = 0;
return EMULATION_RESTART;
}
goto done;
}
}
ctxt->eip = c->eip;
done:
if (rc == X86EMUL_PROPAGATE_FAULT)
ctxt->have_exception = true;
if (rc == X86EMUL_INTERCEPTED)
return EMULATION_INTERCEPTED;
return (rc == X86EMUL_UNHANDLEABLE) ? EMULATION_FAILED : EMULATION_OK;
twobyte_insn:
switch (c->b) {
case 0x05:
rc = emulate_syscall(ctxt, ops);
break;
case 0x06:
rc = em_clts(ctxt);
break;
case 0x09:
(ctxt->ops->wbinvd)(ctxt);
break;
case 0x08:
case 0x0d:
case 0x18:
break;
case 0x20:
c->dst.val = ops->get_cr(ctxt, c->modrm_reg);
break;
case 0x21:
ops->get_dr(ctxt, c->modrm_reg, &c->dst.val);
break;
case 0x22:
if (ops->set_cr(ctxt, c->modrm_reg, c->src.val)) {
emulate_gp(ctxt, 0);
rc = X86EMUL_PROPAGATE_FAULT;
goto done;
}
c->dst.type = OP_NONE;
break;
case 0x23:
if (ops->set_dr(ctxt, c->modrm_reg, c->src.val &
((ctxt->mode == X86EMUL_MODE_PROT64) ?
~0ULL : ~0U)) < 0) {
emulate_gp(ctxt, 0);
rc = X86EMUL_PROPAGATE_FAULT;
goto done;
}
c->dst.type = OP_NONE;
break;
case 0x30:
msr_data = (u32)c->regs[VCPU_REGS_RAX]
| ((u64)c->regs[VCPU_REGS_RDX] << 32);
if (ops->set_msr(ctxt, c->regs[VCPU_REGS_RCX], msr_data)) {
emulate_gp(ctxt, 0);
rc = X86EMUL_PROPAGATE_FAULT;
goto done;
}
rc = X86EMUL_CONTINUE;
break;
case 0x32:
if (ops->get_msr(ctxt, c->regs[VCPU_REGS_RCX], &msr_data)) {
emulate_gp(ctxt, 0);
rc = X86EMUL_PROPAGATE_FAULT;
goto done;
} else {
c->regs[VCPU_REGS_RAX] = (u32)msr_data;
c->regs[VCPU_REGS_RDX] = msr_data >> 32;
}
rc = X86EMUL_CONTINUE;
break;
case 0x34:
rc = emulate_sysenter(ctxt, ops);
break;
case 0x35:
rc = emulate_sysexit(ctxt, ops);
break;
case 0x40 ... 0x4f:
c->dst.val = c->dst.orig_val = c->src.val;
if (!test_cc(c->b, ctxt->eflags))
c->dst.type = OP_NONE;
break;
case 0x80 ... 0x8f:
if (test_cc(c->b, ctxt->eflags))
jmp_rel(c, c->src.val);
break;
case 0x90 ... 0x9f:
c->dst.val = test_cc(c->b, ctxt->eflags);
break;
case 0xa0:
rc = emulate_push_sreg(ctxt, ops, VCPU_SREG_FS);
break;
case 0xa1:
rc = emulate_pop_sreg(ctxt, ops, VCPU_SREG_FS);
break;
case 0xa3:
bt:
c->dst.type = OP_NONE;
c->src.val &= (c->dst.bytes << 3) - 1;
emulate_2op_SrcV_nobyte("bt", c->src, c->dst, ctxt->eflags);
break;
case 0xa4:
case 0xa5:
emulate_2op_cl("shld", c->src2, c->src, c->dst, ctxt->eflags);
break;
case 0xa8:
rc = emulate_push_sreg(ctxt, ops, VCPU_SREG_GS);
break;
case 0xa9:
rc = emulate_pop_sreg(ctxt, ops, VCPU_SREG_GS);
break;
case 0xab:
bts:
emulate_2op_SrcV_nobyte("bts", c->src, c->dst, ctxt->eflags);
break;
case 0xac:
case 0xad:
emulate_2op_cl("shrd", c->src2, c->src, c->dst, ctxt->eflags);
break;
case 0xae:
break;
case 0xb0 ... 0xb1:
c->src.orig_val = c->src.val;
c->src.val = c->regs[VCPU_REGS_RAX];
emulate_2op_SrcV("cmp", c->src, c->dst, ctxt->eflags);
if (ctxt->eflags & EFLG_ZF) {
c->dst.val = c->src.orig_val;
} else {
c->dst.type = OP_REG;
c->dst.addr.reg = (unsigned long *)&c->regs[VCPU_REGS_RAX];
}
break;
case 0xb2:
rc = emulate_load_segment(ctxt, ops, VCPU_SREG_SS);
break;
case 0xb3:
btr:
emulate_2op_SrcV_nobyte("btr", c->src, c->dst, ctxt->eflags);
break;
case 0xb4:
rc = emulate_load_segment(ctxt, ops, VCPU_SREG_FS);
break;
case 0xb5:
rc = emulate_load_segment(ctxt, ops, VCPU_SREG_GS);
break;
case 0xb6 ... 0xb7:
c->dst.bytes = c->op_bytes;
c->dst.val = (c->d & ByteOp) ? (u8) c->src.val
: (u16) c->src.val;
break;
case 0xba:
switch (c->modrm_reg & 3) {
case 0:
goto bt;
case 1:
goto bts;
case 2:
goto btr;
case 3:
goto btc;
}
break;
case 0xbb:
btc:
emulate_2op_SrcV_nobyte("btc", c->src, c->dst, ctxt->eflags);
break;
case 0xbc: {
u8 zf;
__asm__ ("bsf %2, %0; setz %1"
: "=r"(c->dst.val), "=q"(zf)
: "r"(c->src.val));
ctxt->eflags &= ~X86_EFLAGS_ZF;
if (zf) {
ctxt->eflags |= X86_EFLAGS_ZF;
c->dst.type = OP_NONE;
}
break;
}
case 0xbd: {
u8 zf;
__asm__ ("bsr %2, %0; setz %1"
: "=r"(c->dst.val), "=q"(zf)
: "r"(c->src.val));
ctxt->eflags &= ~X86_EFLAGS_ZF;
if (zf) {
ctxt->eflags |= X86_EFLAGS_ZF;
c->dst.type = OP_NONE;
}
break;
}
case 0xbe ... 0xbf:
c->dst.bytes = c->op_bytes;
c->dst.val = (c->d & ByteOp) ? (s8) c->src.val :
(s16) c->src.val;
break;
case 0xc0 ... 0xc1:
emulate_2op_SrcV("add", c->src, c->dst, ctxt->eflags);
c->src.val = c->dst.orig_val;
write_register_operand(&c->src);
break;
case 0xc3:
c->dst.bytes = c->op_bytes;
c->dst.val = (c->op_bytes == 4) ? (u32) c->src.val :
(u64) c->src.val;
break;
case 0xc7:
rc = em_grp9(ctxt);
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
