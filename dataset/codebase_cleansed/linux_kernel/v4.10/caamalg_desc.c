static inline void aead_append_src_dst(u32 *desc, u32 msg_type)
{
append_seq_fifo_store(desc, 0, FIFOST_TYPE_MESSAGE_DATA | KEY_VLF);
append_seq_fifo_load(desc, 0, FIFOLD_CLASS_BOTH |
KEY_VLF | msg_type | FIFOLD_TYPE_LASTBOTH);
}
static inline void append_dec_op1(u32 *desc, u32 type)
{
u32 *jump_cmd, *uncond_jump_cmd;
if ((type & OP_ALG_ALGSEL_MASK) != OP_ALG_ALGSEL_AES) {
append_operation(desc, type | OP_ALG_AS_INITFINAL |
OP_ALG_DECRYPT);
return;
}
jump_cmd = append_jump(desc, JUMP_TEST_ALL | JUMP_COND_SHRD);
append_operation(desc, type | OP_ALG_AS_INITFINAL |
OP_ALG_DECRYPT);
uncond_jump_cmd = append_jump(desc, JUMP_TEST_ALL);
set_jump_tgt_here(desc, jump_cmd);
append_operation(desc, type | OP_ALG_AS_INITFINAL |
OP_ALG_DECRYPT | OP_ALG_AAI_DK);
set_jump_tgt_here(desc, uncond_jump_cmd);
}
void cnstr_shdsc_aead_null_encap(u32 * const desc, struct alginfo *adata,
unsigned int icvsize)
{
u32 *key_jump_cmd, *read_move_cmd, *write_move_cmd;
init_sh_desc(desc, HDR_SHARE_SERIAL);
key_jump_cmd = append_jump(desc, JUMP_JSL | JUMP_TEST_ALL |
JUMP_COND_SHRD);
if (adata->key_inline)
append_key_as_imm(desc, adata->key_virt, adata->keylen_pad,
adata->keylen, CLASS_2 | KEY_DEST_MDHA_SPLIT |
KEY_ENC);
else
append_key(desc, adata->key_dma, adata->keylen, CLASS_2 |
KEY_DEST_MDHA_SPLIT | KEY_ENC);
set_jump_tgt_here(desc, key_jump_cmd);
append_math_sub(desc, REG3, SEQINLEN, REG0, CAAM_CMD_SZ);
append_math_add(desc, VARSEQINLEN, ZERO, REG3, CAAM_CMD_SZ);
append_math_add(desc, VARSEQOUTLEN, ZERO, REG3, CAAM_CMD_SZ);
read_move_cmd = append_move(desc, MOVE_SRC_DESCBUF |
MOVE_DEST_MATH3 |
(0x6 << MOVE_LEN_SHIFT));
write_move_cmd = append_move(desc, MOVE_SRC_MATH3 |
MOVE_DEST_DESCBUF |
MOVE_WAITCOMP |
(0x8 << MOVE_LEN_SHIFT));
append_operation(desc, adata->algtype | OP_ALG_AS_INITFINAL |
OP_ALG_ENCRYPT);
aead_append_src_dst(desc, FIFOLD_TYPE_MSG | FIFOLD_TYPE_FLUSH1);
set_move_tgt_here(desc, read_move_cmd);
set_move_tgt_here(desc, write_move_cmd);
append_cmd(desc, CMD_LOAD | DISABLE_AUTO_INFO_FIFO);
append_move(desc, MOVE_SRC_INFIFO_CL | MOVE_DEST_OUTFIFO |
MOVE_AUX_LS);
append_seq_store(desc, icvsize, LDST_CLASS_2_CCB |
LDST_SRCDST_BYTE_CONTEXT);
#ifdef DEBUG
print_hex_dump(KERN_ERR,
"aead null enc shdesc@" __stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, desc, desc_bytes(desc), 1);
#endif
}
void cnstr_shdsc_aead_null_decap(u32 * const desc, struct alginfo *adata,
unsigned int icvsize)
{
u32 *key_jump_cmd, *read_move_cmd, *write_move_cmd, *jump_cmd;
init_sh_desc(desc, HDR_SHARE_SERIAL);
key_jump_cmd = append_jump(desc, JUMP_JSL | JUMP_TEST_ALL |
JUMP_COND_SHRD);
if (adata->key_inline)
append_key_as_imm(desc, adata->key_virt, adata->keylen_pad,
adata->keylen, CLASS_2 |
KEY_DEST_MDHA_SPLIT | KEY_ENC);
else
append_key(desc, adata->key_dma, adata->keylen, CLASS_2 |
KEY_DEST_MDHA_SPLIT | KEY_ENC);
set_jump_tgt_here(desc, key_jump_cmd);
append_operation(desc, adata->algtype | OP_ALG_AS_INITFINAL |
OP_ALG_DECRYPT | OP_ALG_ICV_ON);
append_math_sub(desc, REG2, SEQOUTLEN, REG0, CAAM_CMD_SZ);
append_math_add(desc, VARSEQINLEN, ZERO, REG2, CAAM_CMD_SZ);
append_math_add(desc, VARSEQOUTLEN, ZERO, REG2, CAAM_CMD_SZ);
read_move_cmd = append_move(desc, MOVE_SRC_DESCBUF |
MOVE_DEST_MATH2 |
(0x6 << MOVE_LEN_SHIFT));
write_move_cmd = append_move(desc, MOVE_SRC_MATH2 |
MOVE_DEST_DESCBUF |
MOVE_WAITCOMP |
(0x8 << MOVE_LEN_SHIFT));
aead_append_src_dst(desc, FIFOLD_TYPE_MSG | FIFOLD_TYPE_FLUSH1);
jump_cmd = append_jump(desc, JUMP_TEST_ALL);
set_jump_tgt_here(desc, jump_cmd);
set_move_tgt_here(desc, read_move_cmd);
set_move_tgt_here(desc, write_move_cmd);
append_cmd(desc, CMD_LOAD | DISABLE_AUTO_INFO_FIFO);
append_move(desc, MOVE_SRC_INFIFO_CL | MOVE_DEST_OUTFIFO |
MOVE_AUX_LS);
append_cmd(desc, CMD_LOAD | ENABLE_AUTO_INFO_FIFO);
append_seq_fifo_load(desc, icvsize, FIFOLD_CLASS_CLASS2 |
FIFOLD_TYPE_LAST2 | FIFOLD_TYPE_ICV);
#ifdef DEBUG
print_hex_dump(KERN_ERR,
"aead null dec shdesc@" __stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, desc, desc_bytes(desc), 1);
#endif
}
static void init_sh_desc_key_aead(u32 * const desc,
struct alginfo * const cdata,
struct alginfo * const adata,
const bool is_rfc3686, u32 *nonce)
{
u32 *key_jump_cmd;
unsigned int enckeylen = cdata->keylen;
init_sh_desc(desc, HDR_SHARE_SERIAL | HDR_SAVECTX);
key_jump_cmd = append_jump(desc, JUMP_JSL | JUMP_TEST_ALL |
JUMP_COND_SHRD);
if (is_rfc3686)
enckeylen -= CTR_RFC3686_NONCE_SIZE;
if (adata->key_inline)
append_key_as_imm(desc, adata->key_virt, adata->keylen_pad,
adata->keylen, CLASS_2 |
KEY_DEST_MDHA_SPLIT | KEY_ENC);
else
append_key(desc, adata->key_dma, adata->keylen, CLASS_2 |
KEY_DEST_MDHA_SPLIT | KEY_ENC);
if (cdata->key_inline)
append_key_as_imm(desc, cdata->key_virt, enckeylen,
enckeylen, CLASS_1 | KEY_DEST_CLASS_REG);
else
append_key(desc, cdata->key_dma, enckeylen, CLASS_1 |
KEY_DEST_CLASS_REG);
if (is_rfc3686) {
append_load_as_imm(desc, nonce, CTR_RFC3686_NONCE_SIZE,
LDST_CLASS_IND_CCB |
LDST_SRCDST_BYTE_OUTFIFO | LDST_IMM);
append_move(desc,
MOVE_SRC_OUTFIFO |
MOVE_DEST_CLASS1CTX |
(16 << MOVE_OFFSET_SHIFT) |
(CTR_RFC3686_NONCE_SIZE << MOVE_LEN_SHIFT));
}
set_jump_tgt_here(desc, key_jump_cmd);
}
void cnstr_shdsc_aead_encap(u32 * const desc, struct alginfo *cdata,
struct alginfo *adata, unsigned int icvsize,
const bool is_rfc3686, u32 *nonce,
const u32 ctx1_iv_off)
{
init_sh_desc_key_aead(desc, cdata, adata, is_rfc3686, nonce);
append_operation(desc, adata->algtype | OP_ALG_AS_INITFINAL |
OP_ALG_ENCRYPT);
append_math_add(desc, VARSEQINLEN, ZERO, REG3, CAAM_CMD_SZ);
append_math_add(desc, VARSEQOUTLEN, ZERO, REG3, CAAM_CMD_SZ);
append_seq_fifo_store(desc, 0, FIFOST_TYPE_SKIP | FIFOLDST_VLF);
append_seq_fifo_load(desc, 0, FIFOLD_CLASS_CLASS2 | FIFOLD_TYPE_MSG |
FIFOLDST_VLF);
if (is_rfc3686)
append_load_imm_be32(desc, 1, LDST_IMM | LDST_CLASS_1_CCB |
LDST_SRCDST_BYTE_CONTEXT |
((ctx1_iv_off + CTR_RFC3686_IV_SIZE) <<
LDST_OFFSET_SHIFT));
append_operation(desc, cdata->algtype | OP_ALG_AS_INITFINAL |
OP_ALG_ENCRYPT);
append_math_add(desc, VARSEQINLEN, SEQINLEN, REG0, CAAM_CMD_SZ);
append_math_add(desc, VARSEQOUTLEN, SEQINLEN, REG0, CAAM_CMD_SZ);
aead_append_src_dst(desc, FIFOLD_TYPE_MSG1OUT2);
append_seq_store(desc, icvsize, LDST_CLASS_2_CCB |
LDST_SRCDST_BYTE_CONTEXT);
#ifdef DEBUG
print_hex_dump(KERN_ERR, "aead enc shdesc@" __stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, desc, desc_bytes(desc), 1);
#endif
}
void cnstr_shdsc_aead_decap(u32 * const desc, struct alginfo *cdata,
struct alginfo *adata, unsigned int ivsize,
unsigned int icvsize, const bool geniv,
const bool is_rfc3686, u32 *nonce,
const u32 ctx1_iv_off)
{
init_sh_desc_key_aead(desc, cdata, adata, is_rfc3686, nonce);
append_operation(desc, adata->algtype | OP_ALG_AS_INITFINAL |
OP_ALG_DECRYPT | OP_ALG_ICV_ON);
append_math_add(desc, VARSEQINLEN, ZERO, REG3, CAAM_CMD_SZ);
if (geniv)
append_math_add_imm_u32(desc, VARSEQOUTLEN, REG3, IMM, ivsize);
else
append_math_add(desc, VARSEQOUTLEN, ZERO, REG3, CAAM_CMD_SZ);
append_seq_fifo_store(desc, 0, FIFOST_TYPE_SKIP | FIFOLDST_VLF);
append_seq_fifo_load(desc, 0, FIFOLD_CLASS_CLASS2 | FIFOLD_TYPE_MSG |
KEY_VLF);
if (geniv) {
append_seq_load(desc, ivsize, LDST_CLASS_1_CCB |
LDST_SRCDST_BYTE_CONTEXT |
(ctx1_iv_off << LDST_OFFSET_SHIFT));
append_move(desc, MOVE_SRC_CLASS1CTX | MOVE_DEST_CLASS2INFIFO |
(ctx1_iv_off << MOVE_OFFSET_SHIFT) | ivsize);
}
if (is_rfc3686)
append_load_imm_be32(desc, 1, LDST_IMM | LDST_CLASS_1_CCB |
LDST_SRCDST_BYTE_CONTEXT |
((ctx1_iv_off + CTR_RFC3686_IV_SIZE) <<
LDST_OFFSET_SHIFT));
if (ctx1_iv_off)
append_operation(desc, cdata->algtype | OP_ALG_AS_INITFINAL |
OP_ALG_DECRYPT);
else
append_dec_op1(desc, cdata->algtype);
append_math_add(desc, VARSEQINLEN, SEQOUTLEN, REG0, CAAM_CMD_SZ);
append_math_add(desc, VARSEQOUTLEN, SEQOUTLEN, REG0, CAAM_CMD_SZ);
aead_append_src_dst(desc, FIFOLD_TYPE_MSG);
append_seq_fifo_load(desc, icvsize, FIFOLD_CLASS_CLASS2 |
FIFOLD_TYPE_LAST2 | FIFOLD_TYPE_ICV);
#ifdef DEBUG
print_hex_dump(KERN_ERR, "aead dec shdesc@" __stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, desc, desc_bytes(desc), 1);
#endif
}
void cnstr_shdsc_aead_givencap(u32 * const desc, struct alginfo *cdata,
struct alginfo *adata, unsigned int ivsize,
unsigned int icvsize, const bool is_rfc3686,
u32 *nonce, const u32 ctx1_iv_off)
{
u32 geniv, moveiv;
init_sh_desc_key_aead(desc, cdata, adata, is_rfc3686, nonce);
if (is_rfc3686)
goto copy_iv;
geniv = NFIFOENTRY_STYPE_PAD | NFIFOENTRY_DEST_DECO |
NFIFOENTRY_DTYPE_MSG | NFIFOENTRY_LC1 |
NFIFOENTRY_PTYPE_RND | (ivsize << NFIFOENTRY_DLEN_SHIFT);
append_load_imm_u32(desc, geniv, LDST_CLASS_IND_CCB |
LDST_SRCDST_WORD_INFO_FIFO | LDST_IMM);
append_cmd(desc, CMD_LOAD | DISABLE_AUTO_INFO_FIFO);
append_move(desc, MOVE_WAITCOMP |
MOVE_SRC_INFIFO | MOVE_DEST_CLASS1CTX |
(ctx1_iv_off << MOVE_OFFSET_SHIFT) |
(ivsize << MOVE_LEN_SHIFT));
append_cmd(desc, CMD_LOAD | ENABLE_AUTO_INFO_FIFO);
copy_iv:
append_move(desc, MOVE_SRC_CLASS1CTX | MOVE_DEST_OUTFIFO |
(ctx1_iv_off << MOVE_OFFSET_SHIFT) |
(ivsize << MOVE_LEN_SHIFT));
append_operation(desc, adata->algtype | OP_ALG_AS_INITFINAL |
OP_ALG_ENCRYPT);
append_math_add(desc, VARSEQINLEN, ZERO, REG3, CAAM_CMD_SZ);
append_math_add(desc, VARSEQOUTLEN, ZERO, REG3, CAAM_CMD_SZ);
append_seq_fifo_store(desc, 0, FIFOST_TYPE_SKIP | FIFOLDST_VLF);
append_seq_fifo_load(desc, 0, FIFOLD_CLASS_CLASS2 | FIFOLD_TYPE_MSG |
KEY_VLF);
moveiv = NFIFOENTRY_STYPE_OFIFO | NFIFOENTRY_DEST_CLASS2 |
NFIFOENTRY_DTYPE_MSG | (ivsize << NFIFOENTRY_DLEN_SHIFT);
append_load_imm_u32(desc, moveiv, LDST_CLASS_IND_CCB |
LDST_SRCDST_WORD_INFO_FIFO | LDST_IMM);
append_load_imm_u32(desc, ivsize, LDST_CLASS_2_CCB |
LDST_SRCDST_WORD_DATASZ_REG | LDST_IMM);
if (is_rfc3686)
append_load_imm_be32(desc, 1, LDST_IMM | LDST_CLASS_1_CCB |
LDST_SRCDST_BYTE_CONTEXT |
((ctx1_iv_off + CTR_RFC3686_IV_SIZE) <<
LDST_OFFSET_SHIFT));
append_operation(desc, cdata->algtype | OP_ALG_AS_INITFINAL |
OP_ALG_ENCRYPT);
append_math_add(desc, VARSEQOUTLEN, SEQINLEN, REG0, CAAM_CMD_SZ);
append_seq_fifo_load(desc, ivsize,
FIFOLD_CLASS_SKIP);
append_math_add(desc, VARSEQINLEN, SEQINLEN, REG0, CAAM_CMD_SZ);
append_seq_fifo_load(desc, 0, FIFOLD_CLASS_BOTH | KEY_VLF |
FIFOLD_TYPE_MSG1OUT2 | FIFOLD_TYPE_LASTBOTH);
append_seq_fifo_store(desc, 0, FIFOST_TYPE_MESSAGE_DATA | KEY_VLF);
append_seq_store(desc, icvsize, LDST_CLASS_2_CCB |
LDST_SRCDST_BYTE_CONTEXT);
#ifdef DEBUG
print_hex_dump(KERN_ERR,
"aead givenc shdesc@" __stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, desc, desc_bytes(desc), 1);
#endif
}
void cnstr_shdsc_gcm_encap(u32 * const desc, struct alginfo *cdata,
unsigned int icvsize)
{
u32 *key_jump_cmd, *zero_payload_jump_cmd, *zero_assoc_jump_cmd1,
*zero_assoc_jump_cmd2;
init_sh_desc(desc, HDR_SHARE_SERIAL);
key_jump_cmd = append_jump(desc, JUMP_JSL | JUMP_TEST_ALL |
JUMP_COND_SHRD | JUMP_COND_SELF);
if (cdata->key_inline)
append_key_as_imm(desc, cdata->key_virt, cdata->keylen,
cdata->keylen, CLASS_1 | KEY_DEST_CLASS_REG);
else
append_key(desc, cdata->key_dma, cdata->keylen, CLASS_1 |
KEY_DEST_CLASS_REG);
set_jump_tgt_here(desc, key_jump_cmd);
append_operation(desc, cdata->algtype | OP_ALG_AS_INITFINAL |
OP_ALG_ENCRYPT);
append_math_sub(desc, VARSEQOUTLEN, SEQINLEN, REG0, CAAM_CMD_SZ);
zero_assoc_jump_cmd2 = append_jump(desc, JUMP_TEST_ALL |
JUMP_COND_MATH_Z);
append_math_add(desc, VARSEQINLEN, ZERO, REG3, CAAM_CMD_SZ);
zero_assoc_jump_cmd1 = append_jump(desc, JUMP_TEST_ALL |
JUMP_COND_MATH_Z);
append_math_add(desc, VARSEQOUTLEN, ZERO, REG3, CAAM_CMD_SZ);
append_seq_fifo_store(desc, 0, FIFOST_TYPE_SKIP | FIFOLDST_VLF);
append_math_sub(desc, VARSEQOUTLEN, SEQINLEN, REG3, CAAM_CMD_SZ);
zero_payload_jump_cmd = append_jump(desc, JUMP_TEST_ALL |
JUMP_COND_MATH_Z);
append_seq_fifo_load(desc, 0, FIFOLD_CLASS_CLASS1 | FIFOLDST_VLF |
FIFOLD_TYPE_AAD | FIFOLD_TYPE_FLUSH1);
set_jump_tgt_here(desc, zero_assoc_jump_cmd1);
append_math_sub(desc, VARSEQINLEN, SEQINLEN, REG0, CAAM_CMD_SZ);
append_seq_fifo_store(desc, 0, FIFOST_TYPE_MESSAGE_DATA | FIFOLDST_VLF);
append_seq_fifo_load(desc, 0, FIFOLD_CLASS_CLASS1 | FIFOLDST_VLF |
FIFOLD_TYPE_MSG | FIFOLD_TYPE_LAST1);
append_jump(desc, JUMP_TEST_ALL | 2);
set_jump_tgt_here(desc, zero_payload_jump_cmd);
append_seq_fifo_load(desc, 0, FIFOLD_CLASS_CLASS1 | FIFOLDST_VLF |
FIFOLD_TYPE_AAD | FIFOLD_TYPE_LAST1);
set_jump_tgt_here(desc, zero_assoc_jump_cmd2);
append_seq_store(desc, icvsize, LDST_CLASS_1_CCB |
LDST_SRCDST_BYTE_CONTEXT);
#ifdef DEBUG
print_hex_dump(KERN_ERR, "gcm enc shdesc@" __stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, desc, desc_bytes(desc), 1);
#endif
}
void cnstr_shdsc_gcm_decap(u32 * const desc, struct alginfo *cdata,
unsigned int icvsize)
{
u32 *key_jump_cmd, *zero_payload_jump_cmd, *zero_assoc_jump_cmd1;
init_sh_desc(desc, HDR_SHARE_SERIAL);
key_jump_cmd = append_jump(desc, JUMP_JSL |
JUMP_TEST_ALL | JUMP_COND_SHRD |
JUMP_COND_SELF);
if (cdata->key_inline)
append_key_as_imm(desc, cdata->key_virt, cdata->keylen,
cdata->keylen, CLASS_1 | KEY_DEST_CLASS_REG);
else
append_key(desc, cdata->key_dma, cdata->keylen, CLASS_1 |
KEY_DEST_CLASS_REG);
set_jump_tgt_here(desc, key_jump_cmd);
append_operation(desc, cdata->algtype | OP_ALG_AS_INITFINAL |
OP_ALG_DECRYPT | OP_ALG_ICV_ON);
append_math_add(desc, VARSEQINLEN, ZERO, REG3, CAAM_CMD_SZ);
zero_assoc_jump_cmd1 = append_jump(desc, JUMP_TEST_ALL |
JUMP_COND_MATH_Z);
append_math_add(desc, VARSEQOUTLEN, ZERO, REG3, CAAM_CMD_SZ);
append_seq_fifo_store(desc, 0, FIFOST_TYPE_SKIP | FIFOLDST_VLF);
append_seq_fifo_load(desc, 0, FIFOLD_CLASS_CLASS1 | FIFOLDST_VLF |
FIFOLD_TYPE_AAD | FIFOLD_TYPE_FLUSH1);
set_jump_tgt_here(desc, zero_assoc_jump_cmd1);
append_math_sub(desc, VARSEQINLEN, SEQOUTLEN, REG0, CAAM_CMD_SZ);
zero_payload_jump_cmd = append_jump(desc, JUMP_TEST_ALL |
JUMP_COND_MATH_Z);
append_math_sub(desc, VARSEQOUTLEN, SEQOUTLEN, REG0, CAAM_CMD_SZ);
append_seq_fifo_store(desc, 0, FIFOST_TYPE_MESSAGE_DATA | FIFOLDST_VLF);
append_seq_fifo_load(desc, 0, FIFOLD_CLASS_CLASS1 | FIFOLDST_VLF |
FIFOLD_TYPE_MSG | FIFOLD_TYPE_FLUSH1);
set_jump_tgt_here(desc, zero_payload_jump_cmd);
append_seq_fifo_load(desc, icvsize, FIFOLD_CLASS_CLASS1 |
FIFOLD_TYPE_ICV | FIFOLD_TYPE_LAST1);
#ifdef DEBUG
print_hex_dump(KERN_ERR, "gcm dec shdesc@" __stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, desc, desc_bytes(desc), 1);
#endif
}
void cnstr_shdsc_rfc4106_encap(u32 * const desc, struct alginfo *cdata,
unsigned int icvsize)
{
u32 *key_jump_cmd;
init_sh_desc(desc, HDR_SHARE_SERIAL);
key_jump_cmd = append_jump(desc, JUMP_JSL | JUMP_TEST_ALL |
JUMP_COND_SHRD);
if (cdata->key_inline)
append_key_as_imm(desc, cdata->key_virt, cdata->keylen,
cdata->keylen, CLASS_1 | KEY_DEST_CLASS_REG);
else
append_key(desc, cdata->key_dma, cdata->keylen, CLASS_1 |
KEY_DEST_CLASS_REG);
set_jump_tgt_here(desc, key_jump_cmd);
append_operation(desc, cdata->algtype | OP_ALG_AS_INITFINAL |
OP_ALG_ENCRYPT);
append_math_sub_imm_u32(desc, VARSEQINLEN, REG3, IMM, 8);
append_math_add(desc, VARSEQOUTLEN, ZERO, REG3, CAAM_CMD_SZ);
append_seq_fifo_load(desc, 0, FIFOLD_CLASS_CLASS1 | FIFOLDST_VLF |
FIFOLD_TYPE_AAD | FIFOLD_TYPE_FLUSH1);
append_seq_fifo_load(desc, 8, FIFOLD_CLASS_SKIP);
append_math_sub(desc, VARSEQINLEN, SEQINLEN, REG0, CAAM_CMD_SZ);
append_seq_fifo_load(desc, 0, FIFOLD_CLASS_CLASS1 | FIFOLD_TYPE_MSG);
append_seq_fifo_store(desc, 0, FIFOST_TYPE_SKIP | FIFOLDST_VLF);
append_math_sub(desc, VARSEQOUTLEN, VARSEQINLEN, REG0, CAAM_CMD_SZ);
append_seq_fifo_store(desc, 0, FIFOST_TYPE_MESSAGE_DATA | FIFOLDST_VLF);
append_seq_fifo_load(desc, 0, FIFOLD_CLASS_CLASS1 | FIFOLDST_VLF |
FIFOLD_TYPE_MSG | FIFOLD_TYPE_LAST1);
append_seq_store(desc, icvsize, LDST_CLASS_1_CCB |
LDST_SRCDST_BYTE_CONTEXT);
#ifdef DEBUG
print_hex_dump(KERN_ERR,
"rfc4106 enc shdesc@" __stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, desc, desc_bytes(desc), 1);
#endif
}
void cnstr_shdsc_rfc4106_decap(u32 * const desc, struct alginfo *cdata,
unsigned int icvsize)
{
u32 *key_jump_cmd;
init_sh_desc(desc, HDR_SHARE_SERIAL);
key_jump_cmd = append_jump(desc, JUMP_JSL | JUMP_TEST_ALL |
JUMP_COND_SHRD);
if (cdata->key_inline)
append_key_as_imm(desc, cdata->key_virt, cdata->keylen,
cdata->keylen, CLASS_1 |
KEY_DEST_CLASS_REG);
else
append_key(desc, cdata->key_dma, cdata->keylen, CLASS_1 |
KEY_DEST_CLASS_REG);
set_jump_tgt_here(desc, key_jump_cmd);
append_operation(desc, cdata->algtype | OP_ALG_AS_INITFINAL |
OP_ALG_DECRYPT | OP_ALG_ICV_ON);
append_math_sub_imm_u32(desc, VARSEQINLEN, REG3, IMM, 8);
append_math_add(desc, VARSEQOUTLEN, ZERO, REG3, CAAM_CMD_SZ);
append_seq_fifo_load(desc, 0, FIFOLD_CLASS_CLASS1 | FIFOLDST_VLF |
FIFOLD_TYPE_AAD | FIFOLD_TYPE_FLUSH1);
append_seq_fifo_load(desc, 8, FIFOLD_CLASS_SKIP);
append_math_sub(desc, VARSEQINLEN, SEQOUTLEN, REG3, CAAM_CMD_SZ);
append_seq_fifo_load(desc, 0, FIFOLD_CLASS_CLASS1 | FIFOLD_TYPE_MSG);
append_seq_fifo_store(desc, 0, FIFOST_TYPE_SKIP | FIFOLDST_VLF);
append_math_sub(desc, VARSEQOUTLEN, SEQOUTLEN, REG0, CAAM_CMD_SZ);
append_seq_fifo_store(desc, 0, FIFOST_TYPE_MESSAGE_DATA | FIFOLDST_VLF);
append_seq_fifo_load(desc, 0, FIFOLD_CLASS_CLASS1 | FIFOLDST_VLF |
FIFOLD_TYPE_MSG | FIFOLD_TYPE_FLUSH1);
append_seq_fifo_load(desc, icvsize, FIFOLD_CLASS_CLASS1 |
FIFOLD_TYPE_ICV | FIFOLD_TYPE_LAST1);
#ifdef DEBUG
print_hex_dump(KERN_ERR,
"rfc4106 dec shdesc@" __stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, desc, desc_bytes(desc), 1);
#endif
}
void cnstr_shdsc_rfc4543_encap(u32 * const desc, struct alginfo *cdata,
unsigned int icvsize)
{
u32 *key_jump_cmd, *read_move_cmd, *write_move_cmd;
init_sh_desc(desc, HDR_SHARE_SERIAL);
key_jump_cmd = append_jump(desc, JUMP_JSL | JUMP_TEST_ALL |
JUMP_COND_SHRD);
if (cdata->key_inline)
append_key_as_imm(desc, cdata->key_virt, cdata->keylen,
cdata->keylen, CLASS_1 | KEY_DEST_CLASS_REG);
else
append_key(desc, cdata->key_dma, cdata->keylen, CLASS_1 |
KEY_DEST_CLASS_REG);
set_jump_tgt_here(desc, key_jump_cmd);
append_operation(desc, cdata->algtype | OP_ALG_AS_INITFINAL |
OP_ALG_ENCRYPT);
append_math_sub(desc, REG3, SEQINLEN, REG0, CAAM_CMD_SZ);
read_move_cmd = append_move(desc, MOVE_SRC_DESCBUF | MOVE_DEST_MATH3 |
(0x6 << MOVE_LEN_SHIFT));
write_move_cmd = append_move(desc, MOVE_SRC_MATH3 | MOVE_DEST_DESCBUF |
(0x8 << MOVE_LEN_SHIFT));
append_math_sub(desc, VARSEQINLEN, SEQINLEN, REG0, CAAM_CMD_SZ);
append_math_sub(desc, VARSEQOUTLEN, SEQINLEN, REG0, CAAM_CMD_SZ);
aead_append_src_dst(desc, FIFOLD_TYPE_AAD);
set_move_tgt_here(desc, read_move_cmd);
set_move_tgt_here(desc, write_move_cmd);
append_cmd(desc, CMD_LOAD | DISABLE_AUTO_INFO_FIFO);
append_move(desc, MOVE_SRC_INFIFO_CL | MOVE_DEST_OUTFIFO);
append_seq_store(desc, icvsize, LDST_CLASS_1_CCB |
LDST_SRCDST_BYTE_CONTEXT);
#ifdef DEBUG
print_hex_dump(KERN_ERR,
"rfc4543 enc shdesc@" __stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, desc, desc_bytes(desc), 1);
#endif
}
void cnstr_shdsc_rfc4543_decap(u32 * const desc, struct alginfo *cdata,
unsigned int icvsize)
{
u32 *key_jump_cmd, *read_move_cmd, *write_move_cmd;
init_sh_desc(desc, HDR_SHARE_SERIAL);
key_jump_cmd = append_jump(desc, JUMP_JSL | JUMP_TEST_ALL |
JUMP_COND_SHRD);
if (cdata->key_inline)
append_key_as_imm(desc, cdata->key_virt, cdata->keylen,
cdata->keylen, CLASS_1 | KEY_DEST_CLASS_REG);
else
append_key(desc, cdata->key_dma, cdata->keylen, CLASS_1 |
KEY_DEST_CLASS_REG);
set_jump_tgt_here(desc, key_jump_cmd);
append_operation(desc, cdata->algtype | OP_ALG_AS_INITFINAL |
OP_ALG_DECRYPT | OP_ALG_ICV_ON);
append_math_sub(desc, REG3, SEQOUTLEN, REG0, CAAM_CMD_SZ);
read_move_cmd = append_move(desc, MOVE_SRC_DESCBUF | MOVE_DEST_MATH3 |
(0x6 << MOVE_LEN_SHIFT));
write_move_cmd = append_move(desc, MOVE_SRC_MATH3 | MOVE_DEST_DESCBUF |
(0x8 << MOVE_LEN_SHIFT));
append_math_sub(desc, VARSEQINLEN, SEQOUTLEN, REG0, CAAM_CMD_SZ);
append_math_sub(desc, VARSEQOUTLEN, SEQOUTLEN, REG0, CAAM_CMD_SZ);
append_seq_fifo_store(desc, 0, FIFOST_TYPE_MESSAGE_DATA | FIFOLDST_VLF);
append_seq_fifo_load(desc, 0, FIFOLD_CLASS_BOTH | FIFOLDST_VLF |
FIFOLD_TYPE_AAD | FIFOLD_TYPE_LAST2FLUSH1);
set_move_tgt_here(desc, read_move_cmd);
set_move_tgt_here(desc, write_move_cmd);
append_cmd(desc, CMD_LOAD | DISABLE_AUTO_INFO_FIFO);
append_move(desc, MOVE_SRC_INFIFO_CL | MOVE_DEST_OUTFIFO);
append_cmd(desc, CMD_LOAD | ENABLE_AUTO_INFO_FIFO);
append_seq_fifo_load(desc, icvsize, FIFOLD_CLASS_CLASS1 |
FIFOLD_TYPE_ICV | FIFOLD_TYPE_LAST1);
#ifdef DEBUG
print_hex_dump(KERN_ERR,
"rfc4543 dec shdesc@" __stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, desc, desc_bytes(desc), 1);
#endif
}
static inline void ablkcipher_append_src_dst(u32 *desc)
{
append_math_add(desc, VARSEQOUTLEN, SEQINLEN, REG0, CAAM_CMD_SZ);
append_math_add(desc, VARSEQINLEN, SEQINLEN, REG0, CAAM_CMD_SZ);
append_seq_fifo_load(desc, 0, FIFOLD_CLASS_CLASS1 |
KEY_VLF | FIFOLD_TYPE_MSG | FIFOLD_TYPE_LAST1);
append_seq_fifo_store(desc, 0, FIFOST_TYPE_MESSAGE_DATA | KEY_VLF);
}
void cnstr_shdsc_ablkcipher_encap(u32 * const desc, struct alginfo *cdata,
unsigned int ivsize, const bool is_rfc3686,
const u32 ctx1_iv_off)
{
u32 *key_jump_cmd;
init_sh_desc(desc, HDR_SHARE_SERIAL | HDR_SAVECTX);
key_jump_cmd = append_jump(desc, JUMP_JSL | JUMP_TEST_ALL |
JUMP_COND_SHRD);
append_key_as_imm(desc, cdata->key_virt, cdata->keylen,
cdata->keylen, CLASS_1 | KEY_DEST_CLASS_REG);
if (is_rfc3686) {
u8 *nonce = cdata->key_virt + cdata->keylen;
append_load_as_imm(desc, nonce, CTR_RFC3686_NONCE_SIZE,
LDST_CLASS_IND_CCB |
LDST_SRCDST_BYTE_OUTFIFO | LDST_IMM);
append_move(desc, MOVE_WAITCOMP | MOVE_SRC_OUTFIFO |
MOVE_DEST_CLASS1CTX | (16 << MOVE_OFFSET_SHIFT) |
(CTR_RFC3686_NONCE_SIZE << MOVE_LEN_SHIFT));
}
set_jump_tgt_here(desc, key_jump_cmd);
append_seq_load(desc, ivsize, LDST_SRCDST_BYTE_CONTEXT |
LDST_CLASS_1_CCB | (ctx1_iv_off << LDST_OFFSET_SHIFT));
if (is_rfc3686)
append_load_imm_be32(desc, 1, LDST_IMM | LDST_CLASS_1_CCB |
LDST_SRCDST_BYTE_CONTEXT |
((ctx1_iv_off + CTR_RFC3686_IV_SIZE) <<
LDST_OFFSET_SHIFT));
append_operation(desc, cdata->algtype | OP_ALG_AS_INITFINAL |
OP_ALG_ENCRYPT);
ablkcipher_append_src_dst(desc);
#ifdef DEBUG
print_hex_dump(KERN_ERR,
"ablkcipher enc shdesc@" __stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, desc, desc_bytes(desc), 1);
#endif
}
void cnstr_shdsc_ablkcipher_decap(u32 * const desc, struct alginfo *cdata,
unsigned int ivsize, const bool is_rfc3686,
const u32 ctx1_iv_off)
{
u32 *key_jump_cmd;
init_sh_desc(desc, HDR_SHARE_SERIAL | HDR_SAVECTX);
key_jump_cmd = append_jump(desc, JUMP_JSL | JUMP_TEST_ALL |
JUMP_COND_SHRD);
append_key_as_imm(desc, cdata->key_virt, cdata->keylen,
cdata->keylen, CLASS_1 | KEY_DEST_CLASS_REG);
if (is_rfc3686) {
u8 *nonce = cdata->key_virt + cdata->keylen;
append_load_as_imm(desc, nonce, CTR_RFC3686_NONCE_SIZE,
LDST_CLASS_IND_CCB |
LDST_SRCDST_BYTE_OUTFIFO | LDST_IMM);
append_move(desc, MOVE_WAITCOMP | MOVE_SRC_OUTFIFO |
MOVE_DEST_CLASS1CTX | (16 << MOVE_OFFSET_SHIFT) |
(CTR_RFC3686_NONCE_SIZE << MOVE_LEN_SHIFT));
}
set_jump_tgt_here(desc, key_jump_cmd);
append_seq_load(desc, ivsize, LDST_SRCDST_BYTE_CONTEXT |
LDST_CLASS_1_CCB | (ctx1_iv_off << LDST_OFFSET_SHIFT));
if (is_rfc3686)
append_load_imm_be32(desc, 1, LDST_IMM | LDST_CLASS_1_CCB |
LDST_SRCDST_BYTE_CONTEXT |
((ctx1_iv_off + CTR_RFC3686_IV_SIZE) <<
LDST_OFFSET_SHIFT));
if (ctx1_iv_off)
append_operation(desc, cdata->algtype | OP_ALG_AS_INITFINAL |
OP_ALG_DECRYPT);
else
append_dec_op1(desc, cdata->algtype);
ablkcipher_append_src_dst(desc);
#ifdef DEBUG
print_hex_dump(KERN_ERR,
"ablkcipher dec shdesc@" __stringify(__LINE__)": ",
DUMP_PREFIX_ADDRESS, 16, 4, desc, desc_bytes(desc), 1);
#endif
}
void cnstr_shdsc_ablkcipher_givencap(u32 * const desc, struct alginfo *cdata,
unsigned int ivsize, const bool is_rfc3686,
const u32 ctx1_iv_off)
{
u32 *key_jump_cmd, geniv;
init_sh_desc(desc, HDR_SHARE_SERIAL | HDR_SAVECTX);
key_jump_cmd = append_jump(desc, JUMP_JSL | JUMP_TEST_ALL |
JUMP_COND_SHRD);
append_key_as_imm(desc, cdata->key_virt, cdata->keylen,
cdata->keylen, CLASS_1 | KEY_DEST_CLASS_REG);
if (is_rfc3686) {
u8 *nonce = cdata->key_virt + cdata->keylen;
append_load_as_imm(desc, nonce, CTR_RFC3686_NONCE_SIZE,
LDST_CLASS_IND_CCB |
LDST_SRCDST_BYTE_OUTFIFO | LDST_IMM);
append_move(desc, MOVE_WAITCOMP | MOVE_SRC_OUTFIFO |
MOVE_DEST_CLASS1CTX | (16 << MOVE_OFFSET_SHIFT) |
(CTR_RFC3686_NONCE_SIZE << MOVE_LEN_SHIFT));
}
set_jump_tgt_here(desc, key_jump_cmd);
geniv = NFIFOENTRY_STYPE_PAD | NFIFOENTRY_DEST_DECO |
NFIFOENTRY_DTYPE_MSG | NFIFOENTRY_LC1 | NFIFOENTRY_PTYPE_RND |
(ivsize << NFIFOENTRY_DLEN_SHIFT);
append_load_imm_u32(desc, geniv, LDST_CLASS_IND_CCB |
LDST_SRCDST_WORD_INFO_FIFO | LDST_IMM);
append_cmd(desc, CMD_LOAD | DISABLE_AUTO_INFO_FIFO);
append_move(desc, MOVE_WAITCOMP | MOVE_SRC_INFIFO |
MOVE_DEST_CLASS1CTX | (ivsize << MOVE_LEN_SHIFT) |
(ctx1_iv_off << MOVE_OFFSET_SHIFT));
append_cmd(desc, CMD_LOAD | ENABLE_AUTO_INFO_FIFO);
append_seq_store(desc, ivsize, LDST_SRCDST_BYTE_CONTEXT |
LDST_CLASS_1_CCB | (ctx1_iv_off << LDST_OFFSET_SHIFT));
if (is_rfc3686)
append_load_imm_be32(desc, 1, LDST_IMM | LDST_CLASS_1_CCB |
LDST_SRCDST_BYTE_CONTEXT |
((ctx1_iv_off + CTR_RFC3686_IV_SIZE) <<
LDST_OFFSET_SHIFT));
if (ctx1_iv_off)
append_jump(desc, JUMP_JSL | JUMP_TEST_ALL | JUMP_COND_NCP |
(1 << JUMP_OFFSET_SHIFT));
append_operation(desc, cdata->algtype | OP_ALG_AS_INITFINAL |
OP_ALG_ENCRYPT);
ablkcipher_append_src_dst(desc);
#ifdef DEBUG
print_hex_dump(KERN_ERR,
"ablkcipher givenc shdesc@" __stringify(__LINE__) ": ",
DUMP_PREFIX_ADDRESS, 16, 4, desc, desc_bytes(desc), 1);
#endif
}
void cnstr_shdsc_xts_ablkcipher_encap(u32 * const desc, struct alginfo *cdata)
{
__be64 sector_size = cpu_to_be64(512);
u32 *key_jump_cmd;
init_sh_desc(desc, HDR_SHARE_SERIAL | HDR_SAVECTX);
key_jump_cmd = append_jump(desc, JUMP_JSL | JUMP_TEST_ALL |
JUMP_COND_SHRD);
append_key_as_imm(desc, cdata->key_virt, cdata->keylen,
cdata->keylen, CLASS_1 | KEY_DEST_CLASS_REG);
append_load_as_imm(desc, (void *)&sector_size, 8, LDST_CLASS_1_CCB |
LDST_SRCDST_BYTE_CONTEXT |
(0x28 << LDST_OFFSET_SHIFT));
set_jump_tgt_here(desc, key_jump_cmd);
append_seq_load(desc, 8, LDST_SRCDST_BYTE_CONTEXT | LDST_CLASS_1_CCB |
(0x20 << LDST_OFFSET_SHIFT));
append_seq_fifo_load(desc, 8, FIFOLD_CLASS_SKIP);
append_operation(desc, cdata->algtype | OP_ALG_AS_INITFINAL |
OP_ALG_ENCRYPT);
ablkcipher_append_src_dst(desc);
#ifdef DEBUG
print_hex_dump(KERN_ERR,
"xts ablkcipher enc shdesc@" __stringify(__LINE__) ": ",
DUMP_PREFIX_ADDRESS, 16, 4, desc, desc_bytes(desc), 1);
#endif
}
void cnstr_shdsc_xts_ablkcipher_decap(u32 * const desc, struct alginfo *cdata)
{
__be64 sector_size = cpu_to_be64(512);
u32 *key_jump_cmd;
init_sh_desc(desc, HDR_SHARE_SERIAL | HDR_SAVECTX);
key_jump_cmd = append_jump(desc, JUMP_JSL | JUMP_TEST_ALL |
JUMP_COND_SHRD);
append_key_as_imm(desc, cdata->key_virt, cdata->keylen,
cdata->keylen, CLASS_1 | KEY_DEST_CLASS_REG);
append_load_as_imm(desc, (void *)&sector_size, 8, LDST_CLASS_1_CCB |
LDST_SRCDST_BYTE_CONTEXT |
(0x28 << LDST_OFFSET_SHIFT));
set_jump_tgt_here(desc, key_jump_cmd);
append_seq_load(desc, 8, LDST_SRCDST_BYTE_CONTEXT | LDST_CLASS_1_CCB |
(0x20 << LDST_OFFSET_SHIFT));
append_seq_fifo_load(desc, 8, FIFOLD_CLASS_SKIP);
append_dec_op1(desc, cdata->algtype);
ablkcipher_append_src_dst(desc);
#ifdef DEBUG
print_hex_dump(KERN_ERR,
"xts ablkcipher dec shdesc@" __stringify(__LINE__) ": ",
DUMP_PREFIX_ADDRESS, 16, 4, desc, desc_bytes(desc), 1);
#endif
}
