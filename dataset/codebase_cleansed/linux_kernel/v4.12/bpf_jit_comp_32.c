static inline bool is_simm13(unsigned int value)
{
return value + 0x1000 < 0x2000;
}
void bpf_jit_compile(struct bpf_prog *fp)
{
unsigned int cleanup_addr, proglen, oldproglen = 0;
u32 temp[8], *prog, *func, seen = 0, pass;
const struct sock_filter *filter = fp->insns;
int i, flen = fp->len, pc_ret0 = -1;
unsigned int *addrs;
void *image;
if (!bpf_jit_enable)
return;
addrs = kmalloc(flen * sizeof(*addrs), GFP_KERNEL);
if (addrs == NULL)
return;
for (proglen = 0, i = 0; i < flen; i++) {
proglen += 64;
addrs[i] = proglen;
}
cleanup_addr = proglen;
image = NULL;
for (pass = 0; pass < 10; pass++) {
u8 seen_or_pass0 = (pass == 0) ? (SEEN_XREG | SEEN_DATAREF | SEEN_MEM) : seen;
proglen = 0;
prog = temp;
if (seen_or_pass0) {
if (seen_or_pass0 & SEEN_MEM) {
unsigned int sz = BASE_STACKFRAME;
sz += BPF_MEMWORDS * sizeof(u32);
emit_alloc_stack(sz);
}
if (seen_or_pass0 & SEEN_XREG)
emit_clear(r_X);
if (seen_or_pass0 & SEEN_DATAREF) {
emit_load32(r_SKB, struct sk_buff, len, r_HEADLEN);
emit_load32(r_SKB, struct sk_buff, data_len, r_TMP);
emit_sub(r_HEADLEN, r_TMP, r_HEADLEN);
emit_loadptr(r_SKB, struct sk_buff, data, r_SKB_DATA);
}
}
emit_reg_move(O7, r_saved_O7);
if (bpf_needs_clear_a(&filter[0]))
emit_clear(r_A);
for (i = 0; i < flen; i++) {
unsigned int K = filter[i].k;
unsigned int t_offset;
unsigned int f_offset;
u32 t_op, f_op;
u16 code = bpf_anc_helper(&filter[i]);
int ilen;
switch (code) {
case BPF_ALU | BPF_ADD | BPF_X:
emit_alu_X(ADD);
break;
case BPF_ALU | BPF_ADD | BPF_K:
emit_alu_K(ADD, K);
break;
case BPF_ALU | BPF_SUB | BPF_X:
emit_alu_X(SUB);
break;
case BPF_ALU | BPF_SUB | BPF_K:
emit_alu_K(SUB, K);
break;
case BPF_ALU | BPF_AND | BPF_X:
emit_alu_X(AND);
break;
case BPF_ALU | BPF_AND | BPF_K:
emit_alu_K(AND, K);
break;
case BPF_ALU | BPF_OR | BPF_X:
emit_alu_X(OR);
break;
case BPF_ALU | BPF_OR | BPF_K:
emit_alu_K(OR, K);
break;
case BPF_ANC | SKF_AD_ALU_XOR_X:
case BPF_ALU | BPF_XOR | BPF_X:
emit_alu_X(XOR);
break;
case BPF_ALU | BPF_XOR | BPF_K:
emit_alu_K(XOR, K);
break;
case BPF_ALU | BPF_LSH | BPF_X:
emit_alu_X(SLL);
break;
case BPF_ALU | BPF_LSH | BPF_K:
emit_alu_K(SLL, K);
break;
case BPF_ALU | BPF_RSH | BPF_X:
emit_alu_X(SRL);
break;
case BPF_ALU | BPF_RSH | BPF_K:
emit_alu_K(SRL, K);
break;
case BPF_ALU | BPF_MUL | BPF_X:
emit_alu_X(MUL);
break;
case BPF_ALU | BPF_MUL | BPF_K:
emit_alu_K(MUL, K);
break;
case BPF_ALU | BPF_DIV | BPF_K:
if (K == 1)
break;
emit_write_y(G0);
emit_nop();
emit_nop();
emit_nop();
emit_alu_K(DIV, K);
break;
case BPF_ALU | BPF_DIV | BPF_X:
emit_cmpi(r_X, 0);
if (pc_ret0 > 0) {
t_offset = addrs[pc_ret0 - 1];
emit_branch(BE, t_offset + 20);
emit_nop();
} else {
emit_branch_off(BNE, 16);
emit_nop();
emit_jump(cleanup_addr + 20);
emit_clear(r_A);
}
emit_write_y(G0);
emit_nop();
emit_nop();
emit_nop();
emit_alu_X(DIV);
break;
case BPF_ALU | BPF_NEG:
emit_neg();
break;
case BPF_RET | BPF_K:
if (!K) {
if (pc_ret0 == -1)
pc_ret0 = i;
emit_clear(r_A);
} else {
emit_loadimm(K, r_A);
}
case BPF_RET | BPF_A:
if (seen_or_pass0) {
if (i != flen - 1) {
emit_jump(cleanup_addr);
emit_nop();
break;
}
if (seen_or_pass0 & SEEN_MEM) {
unsigned int sz = BASE_STACKFRAME;
sz += BPF_MEMWORDS * sizeof(u32);
emit_release_stack(sz);
}
}
emit_jmpl(r_saved_O7, 8, G0);
emit_reg_move(r_A, O0);
break;
case BPF_MISC | BPF_TAX:
seen |= SEEN_XREG;
emit_reg_move(r_A, r_X);
break;
case BPF_MISC | BPF_TXA:
seen |= SEEN_XREG;
emit_reg_move(r_X, r_A);
break;
case BPF_ANC | SKF_AD_CPU:
emit_load_cpu(r_A);
break;
case BPF_ANC | SKF_AD_PROTOCOL:
emit_skb_load16(protocol, r_A);
break;
case BPF_ANC | SKF_AD_PKTTYPE:
__emit_skb_load8(__pkt_type_offset, r_A);
emit_andi(r_A, PKT_TYPE_MAX, r_A);
emit_alu_K(SRL, 5);
break;
case BPF_ANC | SKF_AD_IFINDEX:
emit_skb_loadptr(dev, r_A);
emit_cmpi(r_A, 0);
emit_branch(BE_PTR, cleanup_addr + 4);
emit_nop();
emit_load32(r_A, struct net_device, ifindex, r_A);
break;
case BPF_ANC | SKF_AD_MARK:
emit_skb_load32(mark, r_A);
break;
case BPF_ANC | SKF_AD_QUEUE:
emit_skb_load16(queue_mapping, r_A);
break;
case BPF_ANC | SKF_AD_HATYPE:
emit_skb_loadptr(dev, r_A);
emit_cmpi(r_A, 0);
emit_branch(BE_PTR, cleanup_addr + 4);
emit_nop();
emit_load16(r_A, struct net_device, type, r_A);
break;
case BPF_ANC | SKF_AD_RXHASH:
emit_skb_load32(hash, r_A);
break;
case BPF_ANC | SKF_AD_VLAN_TAG:
case BPF_ANC | SKF_AD_VLAN_TAG_PRESENT:
emit_skb_load16(vlan_tci, r_A);
if (code != (BPF_ANC | SKF_AD_VLAN_TAG)) {
emit_alu_K(SRL, 12);
emit_andi(r_A, 1, r_A);
} else {
emit_loadimm(~VLAN_TAG_PRESENT, r_TMP);
emit_and(r_A, r_TMP, r_A);
}
break;
case BPF_LD | BPF_W | BPF_LEN:
emit_skb_load32(len, r_A);
break;
case BPF_LDX | BPF_W | BPF_LEN:
emit_skb_load32(len, r_X);
break;
case BPF_LD | BPF_IMM:
emit_loadimm(K, r_A);
break;
case BPF_LDX | BPF_IMM:
emit_loadimm(K, r_X);
break;
case BPF_LD | BPF_MEM:
seen |= SEEN_MEM;
emit_ldmem(K * 4, r_A);
break;
case BPF_LDX | BPF_MEM:
seen |= SEEN_MEM | SEEN_XREG;
emit_ldmem(K * 4, r_X);
break;
case BPF_ST:
seen |= SEEN_MEM;
emit_stmem(K * 4, r_A);
break;
case BPF_STX:
seen |= SEEN_MEM | SEEN_XREG;
emit_stmem(K * 4, r_X);
break;
#define CHOOSE_LOAD_FUNC(K, func) \
((int)K < 0 ? ((int)K >= SKF_LL_OFF ? func##_negative_offset : func) : func##_positive_offset)
case BPF_LD | BPF_W | BPF_ABS:
func = CHOOSE_LOAD_FUNC(K, bpf_jit_load_word);
common_load: seen |= SEEN_DATAREF;
emit_loadimm(K, r_OFF);
emit_call(func);
break;
case BPF_LD | BPF_H | BPF_ABS:
func = CHOOSE_LOAD_FUNC(K, bpf_jit_load_half);
goto common_load;
case BPF_LD | BPF_B | BPF_ABS:
func = CHOOSE_LOAD_FUNC(K, bpf_jit_load_byte);
goto common_load;
case BPF_LDX | BPF_B | BPF_MSH:
func = CHOOSE_LOAD_FUNC(K, bpf_jit_load_byte_msh);
goto common_load;
case BPF_LD | BPF_W | BPF_IND:
func = bpf_jit_load_word;
common_load_ind: seen |= SEEN_DATAREF | SEEN_XREG;
if (K) {
if (is_simm13(K)) {
emit_addi(r_X, K, r_OFF);
} else {
emit_loadimm(K, r_TMP);
emit_add(r_X, r_TMP, r_OFF);
}
} else {
emit_reg_move(r_X, r_OFF);
}
emit_call(func);
break;
case BPF_LD | BPF_H | BPF_IND:
func = bpf_jit_load_half;
goto common_load_ind;
case BPF_LD | BPF_B | BPF_IND:
func = bpf_jit_load_byte;
goto common_load_ind;
case BPF_JMP | BPF_JA:
emit_jump(addrs[i + K]);
emit_nop();
break;
#define COND_SEL(CODE, TOP, FOP) \
case CODE: \
t_op = TOP; \
f_op = FOP; \
goto cond_branch
COND_SEL(BPF_JMP | BPF_JGT | BPF_K, BGU, BLEU);
COND_SEL(BPF_JMP | BPF_JGE | BPF_K, BGEU, BLU);
COND_SEL(BPF_JMP | BPF_JEQ | BPF_K, BE, BNE);
COND_SEL(BPF_JMP | BPF_JSET | BPF_K, BNE, BE);
COND_SEL(BPF_JMP | BPF_JGT | BPF_X, BGU, BLEU);
COND_SEL(BPF_JMP | BPF_JGE | BPF_X, BGEU, BLU);
COND_SEL(BPF_JMP | BPF_JEQ | BPF_X, BE, BNE);
COND_SEL(BPF_JMP | BPF_JSET | BPF_X, BNE, BE);
cond_branch: f_offset = addrs[i + filter[i].jf];
t_offset = addrs[i + filter[i].jt];
if (filter[i].jt == filter[i].jf) {
emit_jump(t_offset);
emit_nop();
break;
}
switch (code) {
case BPF_JMP | BPF_JGT | BPF_X:
case BPF_JMP | BPF_JGE | BPF_X:
case BPF_JMP | BPF_JEQ | BPF_X:
seen |= SEEN_XREG;
emit_cmp(r_A, r_X);
break;
case BPF_JMP | BPF_JSET | BPF_X:
seen |= SEEN_XREG;
emit_btst(r_A, r_X);
break;
case BPF_JMP | BPF_JEQ | BPF_K:
case BPF_JMP | BPF_JGT | BPF_K:
case BPF_JMP | BPF_JGE | BPF_K:
if (is_simm13(K)) {
emit_cmpi(r_A, K);
} else {
emit_loadimm(K, r_TMP);
emit_cmp(r_A, r_TMP);
}
break;
case BPF_JMP | BPF_JSET | BPF_K:
if (is_simm13(K)) {
emit_btsti(r_A, K);
} else {
emit_loadimm(K, r_TMP);
emit_btst(r_A, r_TMP);
}
break;
}
if (filter[i].jt != 0) {
if (filter[i].jf)
t_offset += 8;
emit_branch(t_op, t_offset);
emit_nop();
if (filter[i].jf) {
emit_jump(f_offset);
emit_nop();
}
break;
}
emit_branch(f_op, f_offset);
emit_nop();
break;
default:
goto out;
}
ilen = (void *) prog - (void *) temp;
if (image) {
if (unlikely(proglen + ilen > oldproglen)) {
pr_err("bpb_jit_compile fatal error\n");
kfree(addrs);
module_memfree(image);
return;
}
memcpy(image + proglen, temp, ilen);
}
proglen += ilen;
addrs[i] = proglen;
prog = temp;
}
cleanup_addr = proglen - 8;
if (seen_or_pass0 & SEEN_MEM)
cleanup_addr -= 4;
if (image) {
if (proglen != oldproglen)
pr_err("bpb_jit_compile proglen=%u != oldproglen=%u\n",
proglen, oldproglen);
break;
}
if (proglen == oldproglen) {
image = module_alloc(proglen);
if (!image)
goto out;
}
oldproglen = proglen;
}
if (bpf_jit_enable > 1)
bpf_jit_dump(flen, proglen, pass + 1, image);
if (image) {
fp->bpf_func = (void *)image;
fp->jited = 1;
}
out:
kfree(addrs);
return;
}
void bpf_jit_free(struct bpf_prog *fp)
{
if (fp->jited)
module_memfree(fp->bpf_func);
bpf_prog_unlock_free(fp);
}
