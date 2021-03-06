static struct nfp_insn_meta *
nfp_bpf_goto_meta(struct nfp_prog *nfp_prog, struct nfp_insn_meta *meta,
unsigned int insn_idx, unsigned int n_insns)
{
unsigned int forward, backward, i;
backward = meta->n - insn_idx;
forward = insn_idx - meta->n;
if (min(forward, backward) > n_insns - insn_idx - 1) {
backward = n_insns - insn_idx - 1;
meta = nfp_prog_last_meta(nfp_prog);
}
if (min(forward, backward) > insn_idx && backward > insn_idx) {
forward = insn_idx;
meta = nfp_prog_first_meta(nfp_prog);
}
if (forward < backward)
for (i = 0; i < forward; i++)
meta = nfp_meta_next(meta);
else
for (i = 0; i < backward; i++)
meta = nfp_meta_prev(meta);
return meta;
}
static int
nfp_bpf_check_exit(struct nfp_prog *nfp_prog,
const struct bpf_verifier_env *env)
{
const struct bpf_reg_state *reg0 = &env->cur_state.regs[0];
if (nfp_prog->act == NN_ACT_XDP)
return 0;
if (reg0->type != CONST_IMM) {
pr_info("unsupported exit state: %d, imm: %llx\n",
reg0->type, reg0->imm);
return -EINVAL;
}
if (nfp_prog->act != NN_ACT_DIRECT &&
reg0->imm != 0 && (reg0->imm & ~0U) != ~0U) {
pr_info("unsupported exit state: %d, imm: %llx\n",
reg0->type, reg0->imm);
return -EINVAL;
}
if (nfp_prog->act == NN_ACT_DIRECT && reg0->imm <= TC_ACT_REDIRECT &&
reg0->imm != TC_ACT_SHOT && reg0->imm != TC_ACT_STOLEN &&
reg0->imm != TC_ACT_QUEUED) {
pr_info("unsupported exit state: %d, imm: %llx\n",
reg0->type, reg0->imm);
return -EINVAL;
}
return 0;
}
static int
nfp_bpf_check_ctx_ptr(struct nfp_prog *nfp_prog,
const struct bpf_verifier_env *env, u8 reg)
{
if (env->cur_state.regs[reg].type != PTR_TO_CTX)
return -EINVAL;
return 0;
}
static int
nfp_verify_insn(struct bpf_verifier_env *env, int insn_idx, int prev_insn_idx)
{
struct nfp_bpf_analyzer_priv *priv = env->analyzer_priv;
struct nfp_insn_meta *meta = priv->meta;
meta = nfp_bpf_goto_meta(priv->prog, meta, insn_idx, env->prog->len);
priv->meta = meta;
if (meta->insn.src_reg == BPF_REG_10 ||
meta->insn.dst_reg == BPF_REG_10) {
pr_err("stack not yet supported\n");
return -EINVAL;
}
if (meta->insn.src_reg >= MAX_BPF_REG ||
meta->insn.dst_reg >= MAX_BPF_REG) {
pr_err("program uses extended registers - jit hardening?\n");
return -EINVAL;
}
if (meta->insn.code == (BPF_JMP | BPF_EXIT))
return nfp_bpf_check_exit(priv->prog, env);
if ((meta->insn.code & ~BPF_SIZE_MASK) == (BPF_LDX | BPF_MEM))
return nfp_bpf_check_ctx_ptr(priv->prog, env,
meta->insn.src_reg);
if ((meta->insn.code & ~BPF_SIZE_MASK) == (BPF_STX | BPF_MEM))
return nfp_bpf_check_ctx_ptr(priv->prog, env,
meta->insn.dst_reg);
return 0;
}
int nfp_prog_verify(struct nfp_prog *nfp_prog, struct bpf_prog *prog)
{
struct nfp_bpf_analyzer_priv *priv;
int ret;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->prog = nfp_prog;
priv->meta = nfp_prog_first_meta(nfp_prog);
ret = bpf_analyzer(prog, &nfp_bpf_analyzer_ops, priv);
kfree(priv);
return ret;
}
