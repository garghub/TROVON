static void free_cdesc(struct cryptocop_dma_desc *cdesc)
{
DEBUG(printk("free_cdesc: cdesc 0x%p, from_pool=%d\n", cdesc, cdesc->from_pool));
kfree(cdesc->free_buf);
if (cdesc->from_pool) {
unsigned long int flags;
spin_lock_irqsave(&descr_pool_lock, flags);
cdesc->next = descr_pool_free_list;
descr_pool_free_list = cdesc;
++descr_pool_no_free;
spin_unlock_irqrestore(&descr_pool_lock, flags);
} else {
kfree(cdesc);
}
}
static struct cryptocop_dma_desc *alloc_cdesc(int alloc_flag)
{
int use_pool = (alloc_flag & GFP_ATOMIC) ? 1 : 0;
struct cryptocop_dma_desc *cdesc;
if (use_pool) {
unsigned long int flags;
spin_lock_irqsave(&descr_pool_lock, flags);
if (!descr_pool_free_list) {
spin_unlock_irqrestore(&descr_pool_lock, flags);
DEBUG_API(printk("alloc_cdesc: pool is empty\n"));
return NULL;
}
cdesc = descr_pool_free_list;
descr_pool_free_list = descr_pool_free_list->next;
--descr_pool_no_free;
spin_unlock_irqrestore(&descr_pool_lock, flags);
cdesc->from_pool = 1;
} else {
cdesc = kmalloc(sizeof(struct cryptocop_dma_desc), alloc_flag);
if (!cdesc) {
DEBUG_API(printk("alloc_cdesc: kmalloc\n"));
return NULL;
}
cdesc->from_pool = 0;
}
cdesc->dma_descr = (dma_descr_data*)(((unsigned long int)cdesc + offsetof(struct cryptocop_dma_desc, dma_descr_buf) + DESCR_ALLOC_PAD) & ~0x0000001F);
cdesc->next = NULL;
cdesc->free_buf = NULL;
cdesc->dma_descr->out_eop = 0;
cdesc->dma_descr->in_eop = 0;
cdesc->dma_descr->intr = 0;
cdesc->dma_descr->eol = 0;
cdesc->dma_descr->wait = 0;
cdesc->dma_descr->buf = NULL;
cdesc->dma_descr->after = NULL;
DEBUG_API(printk("alloc_cdesc: return 0x%p, cdesc->dma_descr=0x%p, from_pool=%d\n", cdesc, cdesc->dma_descr, cdesc->from_pool));
return cdesc;
}
static void setup_descr_chain(struct cryptocop_dma_desc *cd)
{
DEBUG(printk("setup_descr_chain: entering\n"));
while (cd) {
if (cd->next) {
cd->dma_descr->next = (dma_descr_data*)virt_to_phys(cd->next->dma_descr);
} else {
cd->dma_descr->next = NULL;
}
cd = cd->next;
}
DEBUG(printk("setup_descr_chain: exit\n"));
}
static int create_pad_descriptor(struct cryptocop_tfrm_ctx *tc, struct cryptocop_dma_desc **pad_desc, int alloc_flag)
{
struct cryptocop_dma_desc *cdesc = NULL;
int error = 0;
struct strcop_meta_out mo = {
.ciphsel = src_none,
.hashsel = src_none,
.csumsel = src_none
};
char *pad;
size_t plen;
DEBUG(printk("create_pad_descriptor: start.\n"));
DEBUG(printk("create_pad_descriptor: setting up padding.\n"));
cdesc = alloc_cdesc(alloc_flag);
if (!cdesc){
DEBUG_API(printk("create_pad_descriptor: alloc pad desc\n"));
goto error_cleanup;
}
switch (tc->unit_no) {
case src_md5:
error = create_md5_pad(alloc_flag, tc->consumed, &pad, &plen);
if (error){
DEBUG_API(printk("create_pad_descriptor: create_md5_pad_failed\n"));
goto error_cleanup;
}
cdesc->free_buf = pad;
mo.hashsel = src_dma;
mo.hashconf = tc->hash_conf;
mo.hashmode = tc->hash_mode;
break;
case src_sha1:
error = create_sha1_pad(alloc_flag, tc->consumed, &pad, &plen);
if (error){
DEBUG_API(printk("create_pad_descriptor: create_sha1_pad_failed\n"));
goto error_cleanup;
}
cdesc->free_buf = pad;
mo.hashsel = src_dma;
mo.hashconf = tc->hash_conf;
mo.hashmode = tc->hash_mode;
break;
case src_csum:
if (tc->consumed % tc->blocklength){
pad = (char*)csum_zero_pad;
plen = 1;
} else {
pad = (char*)cdesc;
plen = 0;
}
mo.csumsel = src_dma;
break;
}
cdesc->dma_descr->wait = 1;
cdesc->dma_descr->out_eop = 1;
cdesc->dma_descr->buf = (char*)virt_to_phys((char*)pad);
cdesc->dma_descr->after = cdesc->dma_descr->buf + plen;
cdesc->dma_descr->md = REG_TYPE_CONV(unsigned short int, struct strcop_meta_out, mo);
*pad_desc = cdesc;
return 0;
error_cleanup:
if (cdesc) free_cdesc(cdesc);
return -1;
}
static int setup_key_dl_desc(struct cryptocop_tfrm_ctx *tc, struct cryptocop_dma_desc **kd, int alloc_flag)
{
struct cryptocop_dma_desc *key_desc = alloc_cdesc(alloc_flag);
struct strcop_meta_out mo = {0};
DEBUG(printk("setup_key_dl_desc\n"));
if (!key_desc) {
DEBUG_API(printk("setup_key_dl_desc: failed descriptor allocation.\n"));
return -ENOMEM;
}
if ((tc->tctx->init.alg == cryptocop_alg_aes) && (tc->tcfg->flags & CRYPTOCOP_DECRYPT)) {
if (!tc->tctx->dec_key_set){
get_aes_decrypt_key(tc->tctx->dec_key, tc->tctx->init.key, tc->tctx->init.keylen);
tc->tctx->dec_key_set = 1;
}
key_desc->dma_descr->buf = (char*)virt_to_phys(tc->tctx->dec_key);
key_desc->dma_descr->after = key_desc->dma_descr->buf + tc->tctx->init.keylen/8;
} else {
key_desc->dma_descr->buf = (char*)virt_to_phys(tc->tctx->init.key);
key_desc->dma_descr->after = key_desc->dma_descr->buf + tc->tctx->init.keylen/8;
}
mo.dlkey = 1;
switch (tc->tctx->init.keylen) {
case 64:
mo.decrypt = 0;
mo.hashmode = 0;
break;
case 128:
mo.decrypt = 0;
mo.hashmode = 1;
break;
case 192:
mo.decrypt = 1;
mo.hashmode = 0;
break;
case 256:
mo.decrypt = 1;
mo.hashmode = 1;
break;
default:
break;
}
mo.ciphsel = mo.hashsel = mo.csumsel = src_none;
key_desc->dma_descr->md = REG_TYPE_CONV(unsigned short int, struct strcop_meta_out, mo);
key_desc->dma_descr->out_eop = 1;
key_desc->dma_descr->wait = 1;
key_desc->dma_descr->intr = 0;
*kd = key_desc;
return 0;
}
static int setup_cipher_iv_desc(struct cryptocop_tfrm_ctx *tc, struct cryptocop_dma_desc **id, int alloc_flag)
{
struct cryptocop_dma_desc *iv_desc = alloc_cdesc(alloc_flag);
struct strcop_meta_out mo = {0};
DEBUG(printk("setup_cipher_iv_desc\n"));
if (!iv_desc) {
DEBUG_API(printk("setup_cipher_iv_desc: failed CBC IV descriptor allocation.\n"));
return -ENOMEM;
}
iv_desc->dma_descr->buf = (char*)virt_to_phys(tc->tcfg->iv);
iv_desc->dma_descr->after = iv_desc->dma_descr->buf + tc->blocklength;
mo.hashsel = mo.csumsel = src_none;
mo.ciphsel = src_dma;
mo.ciphconf = tc->ciph_conf;
mo.cbcmode = tc->cbcmode;
iv_desc->dma_descr->md = REG_TYPE_CONV(unsigned short int, struct strcop_meta_out, mo);
iv_desc->dma_descr->out_eop = 0;
iv_desc->dma_descr->wait = 1;
iv_desc->dma_descr->intr = 0;
*id = iv_desc;
return 0;
}
static int create_input_descriptors(struct cryptocop_operation *operation, struct cryptocop_tfrm_ctx *tc, struct cryptocop_dma_desc **id, int alloc_flag)
{
int err = 0;
struct cryptocop_dma_desc head = {0};
struct cryptocop_dma_desc *outdesc = &head;
size_t iov_offset = 0;
size_t out_ix = 0;
int outiov_ix = 0;
struct strcop_meta_in mi = {0};
size_t out_length = tc->produced;
int rem_length;
int dlength;
assert(out_length != 0);
if (((tc->produced + tc->tcfg->inject_ix) > operation->tfrm_op.outlen) || (tc->produced && (operation->tfrm_op.outlen == 0))) {
DEBUG_API(printk("create_input_descriptors: operation outdata too small\n"));
return -EINVAL;
}
while ((outiov_ix < operation->tfrm_op.outcount) && ((out_ix + operation->tfrm_op.outdata[outiov_ix].iov_len) <= tc->tcfg->inject_ix)){
out_ix += operation->tfrm_op.outdata[outiov_ix].iov_len;
outiov_ix++;
}
if (outiov_ix >= operation->tfrm_op.outcount){
DEBUG_API(printk("create_input_descriptors: operation outdata too small\n"));
return -EINVAL;
}
iov_offset = tc->tcfg->inject_ix - out_ix;
mi.dmasel = tc->unit_no;
while ((out_length > 0) && (outiov_ix < operation->tfrm_op.outcount)) {
outdesc->next = alloc_cdesc(alloc_flag);
if (!outdesc->next) {
DEBUG_API(printk("create_input_descriptors: alloc_cdesc\n"));
err = -ENOMEM;
goto error_cleanup;
}
outdesc = outdesc->next;
rem_length = operation->tfrm_op.outdata[outiov_ix].iov_len - iov_offset;
dlength = (out_length < rem_length) ? out_length : rem_length;
DEBUG(printk("create_input_descriptors:\n"
"outiov_ix=%d, rem_length=%d, dlength=%d\n"
"iov_offset=%d, outdata[outiov_ix].iov_len=%d\n"
"outcount=%d, outiov_ix=%d\n",
outiov_ix, rem_length, dlength, iov_offset, operation->tfrm_op.outdata[outiov_ix].iov_len, operation->tfrm_op.outcount, outiov_ix));
outdesc->dma_descr->buf = (char*)virt_to_phys(operation->tfrm_op.outdata[outiov_ix].iov_base + iov_offset);
outdesc->dma_descr->after = outdesc->dma_descr->buf + dlength;
outdesc->dma_descr->md = REG_TYPE_CONV(unsigned short int, struct strcop_meta_in, mi);
out_length -= dlength;
iov_offset += dlength;
if (iov_offset >= operation->tfrm_op.outdata[outiov_ix].iov_len) {
iov_offset = 0;
++outiov_ix;
}
}
if (out_length > 0){
DEBUG_API(printk("create_input_descriptors: not enough room for output, %d remained\n", out_length));
err = -EINVAL;
goto error_cleanup;
}
mi.sync = 1;
outdesc->dma_descr->md = REG_TYPE_CONV(unsigned short int, struct strcop_meta_in, mi);
*id = head.next;
return 0;
error_cleanup:
while (head.next) {
outdesc = head.next->next;
free_cdesc(head.next);
head.next = outdesc;
}
return err;
}
static int create_output_descriptors(struct cryptocop_operation *operation, int *iniov_ix, int *iniov_offset, size_t desc_len, struct cryptocop_dma_desc **current_out_cdesc, struct strcop_meta_out *meta_out, int alloc_flag)
{
while (desc_len != 0) {
struct cryptocop_dma_desc *cdesc;
int rem_length = operation->tfrm_op.indata[*iniov_ix].iov_len - *iniov_offset;
int dlength = (desc_len < rem_length) ? desc_len : rem_length;
cdesc = alloc_cdesc(alloc_flag);
if (!cdesc) {
DEBUG_API(printk("create_output_descriptors: alloc_cdesc\n"));
return -ENOMEM;
}
(*current_out_cdesc)->next = cdesc;
(*current_out_cdesc) = cdesc;
cdesc->free_buf = NULL;
cdesc->dma_descr->buf = (char*)virt_to_phys(operation->tfrm_op.indata[*iniov_ix].iov_base + *iniov_offset);
cdesc->dma_descr->after = cdesc->dma_descr->buf + dlength;
assert(desc_len >= dlength);
desc_len -= dlength;
*iniov_offset += dlength;
if (*iniov_offset >= operation->tfrm_op.indata[*iniov_ix].iov_len) {
*iniov_offset = 0;
++(*iniov_ix);
if (*iniov_ix > operation->tfrm_op.incount) {
DEBUG_API(printk("create_output_descriptors: not enough indata in operation."));
return -EINVAL;
}
}
cdesc->dma_descr->md = REG_TYPE_CONV(unsigned short int, struct strcop_meta_out, (*meta_out));
}
(*current_out_cdesc)->dma_descr->wait = 1;
return 0;
}
static int append_input_descriptors(struct cryptocop_operation *operation, struct cryptocop_dma_desc **current_in_cdesc, struct cryptocop_dma_desc **current_out_cdesc, struct cryptocop_tfrm_ctx *tc, int alloc_flag)
{
DEBUG(printk("append_input_descriptors, tc=0x%p, unit_no=%d\n", tc, tc->unit_no));
if (tc->tcfg) {
int failed = 0;
struct cryptocop_dma_desc *idescs = NULL;
DEBUG(printk("append_input_descriptors: pushing output, consumed %d produced %d bytes.\n", tc->consumed, tc->produced));
if (tc->pad_descs) {
DEBUG(printk("append_input_descriptors: append pad descriptors to DMA out list.\n"));
while (tc->pad_descs) {
DEBUG(printk("append descriptor 0x%p\n", tc->pad_descs));
(*current_out_cdesc)->next = tc->pad_descs;
tc->pad_descs = tc->pad_descs->next;
(*current_out_cdesc) = (*current_out_cdesc)->next;
}
}
if (tc->unit_no == src_dma){
struct strcop_meta_in mi = {.sync = 0, .dmasel = src_dma};
unsigned int start_ix = tc->start_ix;
while (start_ix){
unsigned int desclen = start_ix < MEM2MEM_DISCARD_BUF_LENGTH ? start_ix : MEM2MEM_DISCARD_BUF_LENGTH;
(*current_in_cdesc)->next = alloc_cdesc(alloc_flag);
if (!(*current_in_cdesc)->next){
DEBUG_API(printk("append_input_descriptors: alloc_cdesc mem2mem discard failed\n"));
return -ENOMEM;
}
(*current_in_cdesc) = (*current_in_cdesc)->next;
(*current_in_cdesc)->dma_descr->buf = (char*)virt_to_phys(mem2mem_discard_buf);
(*current_in_cdesc)->dma_descr->after = (*current_in_cdesc)->dma_descr->buf + desclen;
(*current_in_cdesc)->dma_descr->md = REG_TYPE_CONV(unsigned short int, struct strcop_meta_in, mi);
start_ix -= desclen;
}
mi.sync = 1;
(*current_in_cdesc)->dma_descr->md = REG_TYPE_CONV(unsigned short int, struct strcop_meta_in, mi);
}
failed = create_input_descriptors(operation, tc, &idescs, alloc_flag);
if (failed){
DEBUG_API(printk("append_input_descriptors: output descriptor setup failed\n"));
return failed;
}
DEBUG(printk("append_input_descriptors: append output descriptors to DMA in list.\n"));
while (idescs) {
DEBUG(printk("append descriptor 0x%p\n", idescs));
(*current_in_cdesc)->next = idescs;
idescs = idescs->next;
(*current_in_cdesc) = (*current_in_cdesc)->next;
}
}
return 0;
}
static int cryptocop_setup_dma_list(struct cryptocop_operation *operation, struct cryptocop_int_operation **int_op, int alloc_flag)
{
struct cryptocop_session *sess;
struct cryptocop_transform_ctx *tctx;
struct cryptocop_tfrm_ctx digest_ctx = {
.previous_src = src_none,
.current_src = src_none,
.start_ix = 0,
.requires_padding = 1,
.strict_block_length = 0,
.hash_conf = 0,
.hash_mode = 0,
.ciph_conf = 0,
.cbcmode = 0,
.decrypt = 0,
.consumed = 0,
.produced = 0,
.pad_descs = NULL,
.active = 0,
.done = 0,
.prev_src = NULL,
.curr_src = NULL,
.tcfg = NULL};
struct cryptocop_tfrm_ctx cipher_ctx = {
.previous_src = src_none,
.current_src = src_none,
.start_ix = 0,
.requires_padding = 0,
.strict_block_length = 1,
.hash_conf = 0,
.hash_mode = 0,
.ciph_conf = 0,
.cbcmode = 0,
.decrypt = 0,
.consumed = 0,
.produced = 0,
.pad_descs = NULL,
.active = 0,
.done = 0,
.prev_src = NULL,
.curr_src = NULL,
.tcfg = NULL};
struct cryptocop_tfrm_ctx csum_ctx = {
.previous_src = src_none,
.current_src = src_none,
.start_ix = 0,
.blocklength = 2,
.requires_padding = 1,
.strict_block_length = 0,
.hash_conf = 0,
.hash_mode = 0,
.ciph_conf = 0,
.cbcmode = 0,
.decrypt = 0,
.consumed = 0,
.produced = 0,
.pad_descs = NULL,
.active = 0,
.done = 0,
.tcfg = NULL,
.prev_src = NULL,
.curr_src = NULL,
.unit_no = src_csum};
struct cryptocop_tfrm_cfg *tcfg = operation->tfrm_op.tfrm_cfg;
unsigned int indata_ix = 0;
int iniov_ix = 0;
int iniov_offset = 0;
struct cryptocop_desc *odsc;
int failed = 0;
struct cryptocop_dma_desc out_cdesc_head = {0};
struct cryptocop_dma_desc in_cdesc_head = {0};
struct cryptocop_dma_desc *current_out_cdesc = &out_cdesc_head;
struct cryptocop_dma_desc *current_in_cdesc = &in_cdesc_head;
struct cryptocop_tfrm_ctx *output_tc = NULL;
void *iop_alloc_ptr;
assert(operation != NULL);
assert(int_op != NULL);
DEBUG(printk("cryptocop_setup_dma_list: start\n"));
DEBUG(print_cryptocop_operation(operation));
sess = get_session(operation->sid);
if (!sess) {
DEBUG_API(printk("cryptocop_setup_dma_list: no session found for operation.\n"));
failed = -EINVAL;
goto error_cleanup;
}
iop_alloc_ptr = kmalloc(DESCR_ALLOC_PAD + sizeof(struct cryptocop_int_operation), alloc_flag);
if (!iop_alloc_ptr) {
DEBUG_API(printk("cryptocop_setup_dma_list: kmalloc cryptocop_int_operation\n"));
failed = -ENOMEM;
goto error_cleanup;
}
(*int_op) = (struct cryptocop_int_operation*)(((unsigned long int)(iop_alloc_ptr + DESCR_ALLOC_PAD + offsetof(struct cryptocop_int_operation, ctx_out)) & ~0x0000001F) - offsetof(struct cryptocop_int_operation, ctx_out));
DEBUG(memset((*int_op), 0xff, sizeof(struct cryptocop_int_operation)));
(*int_op)->alloc_ptr = iop_alloc_ptr;
DEBUG(printk("cryptocop_setup_dma_list: *int_op=0x%p, alloc_ptr=0x%p\n", *int_op, (*int_op)->alloc_ptr));
(*int_op)->sid = operation->sid;
(*int_op)->cdesc_out = NULL;
(*int_op)->cdesc_in = NULL;
(*int_op)->tdes_mode = cryptocop_3des_ede;
(*int_op)->csum_mode = cryptocop_csum_le;
(*int_op)->ddesc_out = NULL;
(*int_op)->ddesc_in = NULL;
if (!tcfg) {
DEBUG_API(printk("cryptocop_setup_dma_list: no configured transforms in operation.\n"));
failed = -EINVAL;
goto error_cleanup;
}
while (tcfg) {
tctx = get_transform_ctx(sess, tcfg->tid);
if (!tctx) {
DEBUG_API(printk("cryptocop_setup_dma_list: no transform id %d in session.\n", tcfg->tid));
failed = -EINVAL;
goto error_cleanup;
}
if (tcfg->inject_ix > operation->tfrm_op.outlen){
DEBUG_API(printk("cryptocop_setup_dma_list: transform id %d inject_ix (%d) > operation->tfrm_op.outlen(%d)", tcfg->tid, tcfg->inject_ix, operation->tfrm_op.outlen));
failed = -EINVAL;
goto error_cleanup;
}
switch (tctx->init.alg){
case cryptocop_alg_mem2mem:
if (cipher_ctx.tcfg != NULL){
DEBUG_API(printk("cryptocop_setup_dma_list: multiple ciphers in operation.\n"));
failed = -EINVAL;
goto error_cleanup;
}
cipher_ctx.cbcmode = 0;
cipher_ctx.decrypt = 0;
cipher_ctx.blocklength = 1;
cipher_ctx.ciph_conf = 0;
cipher_ctx.unit_no = src_dma;
cipher_ctx.tcfg = tcfg;
cipher_ctx.tctx = tctx;
break;
case cryptocop_alg_des:
case cryptocop_alg_3des:
case cryptocop_alg_aes:
if (cipher_ctx.tcfg != NULL){
DEBUG_API(printk("cryptocop_setup_dma_list: multiple ciphers in operation.\n"));
failed = -EINVAL;
goto error_cleanup;
}
cipher_ctx.tcfg = tcfg;
cipher_ctx.tctx = tctx;
if (cipher_ctx.tcfg->flags & CRYPTOCOP_DECRYPT){
cipher_ctx.decrypt = 1;
}
switch (tctx->init.cipher_mode) {
case cryptocop_cipher_mode_ecb:
cipher_ctx.cbcmode = 0;
break;
case cryptocop_cipher_mode_cbc:
cipher_ctx.cbcmode = 1;
break;
default:
DEBUG_API(printk("cryptocop_setup_dma_list: cipher_ctx, bad cipher mode==%d\n", tctx->init.cipher_mode));
failed = -EINVAL;
goto error_cleanup;
}
DEBUG(printk("cryptocop_setup_dma_list: cipher_ctx, set CBC mode==%d\n", cipher_ctx.cbcmode));
switch (tctx->init.alg){
case cryptocop_alg_des:
cipher_ctx.ciph_conf = 0;
cipher_ctx.unit_no = src_des;
cipher_ctx.blocklength = DES_BLOCK_LENGTH;
break;
case cryptocop_alg_3des:
cipher_ctx.ciph_conf = 1;
cipher_ctx.unit_no = src_des;
cipher_ctx.blocklength = DES_BLOCK_LENGTH;
break;
case cryptocop_alg_aes:
cipher_ctx.ciph_conf = 2;
cipher_ctx.unit_no = src_aes;
cipher_ctx.blocklength = AES_BLOCK_LENGTH;
break;
default:
panic("cryptocop_setup_dma_list: impossible algorithm %d\n", tctx->init.alg);
}
(*int_op)->tdes_mode = tctx->init.tdes_mode;
break;
case cryptocop_alg_md5:
case cryptocop_alg_sha1:
if (digest_ctx.tcfg != NULL){
DEBUG_API(printk("cryptocop_setup_dma_list: multiple digests in operation.\n"));
failed = -EINVAL;
goto error_cleanup;
}
digest_ctx.tcfg = tcfg;
digest_ctx.tctx = tctx;
digest_ctx.hash_mode = 0;
switch (tctx->init.alg){
case cryptocop_alg_md5:
digest_ctx.blocklength = MD5_BLOCK_LENGTH;
digest_ctx.unit_no = src_md5;
digest_ctx.hash_conf = 1;
break;
case cryptocop_alg_sha1:
digest_ctx.blocklength = SHA1_BLOCK_LENGTH;
digest_ctx.unit_no = src_sha1;
digest_ctx.hash_conf = 0;
break;
default:
panic("cryptocop_setup_dma_list: impossible digest algorithm\n");
}
break;
case cryptocop_alg_csum:
if (csum_ctx.tcfg != NULL){
DEBUG_API(printk("cryptocop_setup_dma_list: multiple checksums in operation.\n"));
failed = -EINVAL;
goto error_cleanup;
}
(*int_op)->csum_mode = tctx->init.csum_mode;
csum_ctx.tcfg = tcfg;
csum_ctx.tctx = tctx;
break;
default:
DEBUG_API(printk("cryptocop_setup_dma_list: invalid algorithm %d specified in tfrm %d.\n", tctx->init.alg, tcfg->tid));
failed = -EINVAL;
goto error_cleanup;
}
tcfg = tcfg->next;
}
if (cipher_ctx.tcfg && (cipher_ctx.tctx->init.alg != cryptocop_alg_mem2mem)){
struct cryptocop_dma_desc *key_desc = NULL;
failed = setup_key_dl_desc(&cipher_ctx, &key_desc, alloc_flag);
if (failed) {
DEBUG_API(printk("cryptocop_setup_dma_list: setup key dl\n"));
goto error_cleanup;
}
current_out_cdesc->next = key_desc;
current_out_cdesc = key_desc;
indata_ix += (unsigned int)(key_desc->dma_descr->after - key_desc->dma_descr->buf);
if ((cipher_ctx.tctx->init.cipher_mode == cryptocop_cipher_mode_cbc) && (cipher_ctx.tcfg->flags & CRYPTOCOP_EXPLICIT_IV)) {
struct cryptocop_dma_desc *iv_desc = NULL;
DEBUG(printk("cryptocop_setup_dma_list: setup cipher CBC IV descriptor.\n"));
failed = setup_cipher_iv_desc(&cipher_ctx, &iv_desc, alloc_flag);
if (failed) {
DEBUG_API(printk("cryptocop_setup_dma_list: CBC IV descriptor.\n"));
goto error_cleanup;
}
current_out_cdesc->next = iv_desc;
current_out_cdesc = iv_desc;
indata_ix += (unsigned int)(iv_desc->dma_descr->after - iv_desc->dma_descr->buf);
}
}
odsc = operation->tfrm_op.desc;
while (odsc) {
struct cryptocop_desc_cfg *dcfg = odsc->cfg;
struct strcop_meta_out meta_out = {0};
size_t desc_len = odsc->length;
int active_count, eop_needed_count;
output_tc = NULL;
DEBUG(printk("cryptocop_setup_dma_list: parsing an operation descriptor\n"));
while (dcfg) {
struct cryptocop_tfrm_ctx *tc = NULL;
DEBUG(printk("cryptocop_setup_dma_list: parsing an operation descriptor configuration.\n"));
if (digest_ctx.tcfg && (digest_ctx.tcfg->tid == dcfg->tid)){
tc = &digest_ctx;
} else if (cipher_ctx.tcfg && (cipher_ctx.tcfg->tid == dcfg->tid)){
tc = &cipher_ctx;
} else if (csum_ctx.tcfg && (csum_ctx.tcfg->tid == dcfg->tid)){
tc = &csum_ctx;
}
if (!tc) {
DEBUG_API(printk("cryptocop_setup_dma_list: invalid transform %d specified in descriptor.\n", dcfg->tid));
failed = -EINVAL;
goto error_cleanup;
}
if (tc->done) {
DEBUG_API(printk("cryptocop_setup_dma_list: completed transform %d reused.\n", dcfg->tid));
failed = -EINVAL;
goto error_cleanup;
}
if (!tc->active) {
tc->start_ix = indata_ix;
tc->active = 1;
}
tc->previous_src = tc->current_src;
tc->prev_src = tc->curr_src;
switch (dcfg->src){
case cryptocop_source_dma:
tc->current_src = src_dma;
break;
case cryptocop_source_des:
tc->current_src = src_des;
break;
case cryptocop_source_3des:
tc->current_src = src_des;
break;
case cryptocop_source_aes:
tc->current_src = src_aes;
break;
case cryptocop_source_md5:
case cryptocop_source_sha1:
case cryptocop_source_csum:
case cryptocop_source_none:
default:
DEBUG_API(printk("cryptocop_setup_dma_list: bad unit source configured %d.\n", dcfg->src));
failed = -EINVAL;
goto error_cleanup;
}
if (tc->current_src != src_dma) {
if (digest_ctx.unit_no == tc->current_src){
tc->curr_src = &digest_ctx;
} else if (cipher_ctx.unit_no == tc->current_src){
tc->curr_src = &cipher_ctx;
} else if (csum_ctx.unit_no == tc->current_src){
tc->curr_src = &csum_ctx;
}
if ((tc->curr_src == tc) && (tc->unit_no != src_dma)){
DEBUG_API(printk("cryptocop_setup_dma_list: unit %d configured to source from itself.\n", tc->unit_no));
failed = -EINVAL;
goto error_cleanup;
}
} else {
tc->curr_src = NULL;
}
DEBUG(printk("cryptocop_setup_dma_list: tc->active=%d tc->unit_no=%d tc->current_src=%d tc->previous_src=%d, tc->curr_src=0x%p, tc->prev_srv=0x%p\n", tc->active, tc->unit_no, tc->current_src, tc->previous_src, tc->curr_src, tc->prev_src));
if (tc->active && (tc->current_src != tc->previous_src)) {
if (((tc->prev_src != NULL) && (tc->prev_src->consumed % tc->prev_src->blocklength)) ||
((tc->curr_src != NULL) && (tc->curr_src->consumed % tc->curr_src->blocklength)))
{
DEBUG_API(printk("cryptocop_setup_dma_list: can only disconnect from or connect to a unit on a multiple of the blocklength, old: cons=%d, prod=%d, block=%d, new: cons=%d prod=%d, block=%d.\n", tc->prev_src ? tc->prev_src->consumed : INT_MIN, tc->prev_src ? tc->prev_src->produced : INT_MIN, tc->prev_src ? tc->prev_src->blocklength : INT_MIN, tc->curr_src ? tc->curr_src->consumed : INT_MIN, tc->curr_src ? tc->curr_src->produced : INT_MIN, tc->curr_src ? tc->curr_src->blocklength : INT_MIN));
failed = -EINVAL;
goto error_cleanup;
}
}
if (dcfg->last) {
tc->done = 1;
}
dcfg = dcfg->next;
}
DEBUG(printk("cryptocop_setup_dma_list: parsing operation descriptor configuration complete.\n"));
if (cipher_ctx.active && (cipher_ctx.curr_src != NULL) && !cipher_ctx.curr_src->active){
DEBUG_API(printk("cryptocop_setup_dma_list: cipher source from inactive unit %d\n", cipher_ctx.curr_src->unit_no));
failed = -EINVAL;
goto error_cleanup;
}
if (digest_ctx.active && (digest_ctx.curr_src != NULL) && !digest_ctx.curr_src->active){
DEBUG_API(printk("cryptocop_setup_dma_list: digest source from inactive unit %d\n", digest_ctx.curr_src->unit_no));
failed = -EINVAL;
goto error_cleanup;
}
if (csum_ctx.active && (csum_ctx.curr_src != NULL) && !csum_ctx.curr_src->active){
DEBUG_API(printk("cryptocop_setup_dma_list: cipher source from inactive unit %d\n", csum_ctx.curr_src->unit_no));
failed = -EINVAL;
goto error_cleanup;
}
DEBUG(printk("cryptocop_setup_dma_list: desc->length=%d, desc_len=%d.\n", odsc->length, desc_len));
if (csum_ctx.active) {
csum_ctx.consumed += desc_len;
if (csum_ctx.done) {
csum_ctx.produced = 2;
}
DEBUG(printk("cryptocop_setup_dma_list: csum_ctx producing: consumed=%d, produced=%d, blocklength=%d.\n", csum_ctx.consumed, csum_ctx.produced, csum_ctx.blocklength));
}
if (digest_ctx.active) {
digest_ctx.consumed += desc_len;
if (digest_ctx.done) {
if (digest_ctx.unit_no == src_md5) {
digest_ctx.produced = MD5_STATE_LENGTH;
} else {
digest_ctx.produced = SHA1_STATE_LENGTH;
}
}
DEBUG(printk("cryptocop_setup_dma_list: digest_ctx producing: consumed=%d, produced=%d, blocklength=%d.\n", digest_ctx.consumed, digest_ctx.produced, digest_ctx.blocklength));
}
if (cipher_ctx.active) {
assert(cipher_ctx.current_src == src_dma);
cipher_ctx.consumed += desc_len;
cipher_ctx.produced = cipher_ctx.blocklength * (cipher_ctx.consumed / cipher_ctx.blocklength);
if (cipher_ctx.cbcmode && !(cipher_ctx.tcfg->flags & CRYPTOCOP_EXPLICIT_IV) && cipher_ctx.produced){
cipher_ctx.produced -= cipher_ctx.blocklength;
}
DEBUG(printk("cryptocop_setup_dma_list: cipher_ctx producing: consumed=%d, produced=%d, blocklength=%d.\n", cipher_ctx.consumed, cipher_ctx.produced, cipher_ctx.blocklength));
}
active_count = 0;
eop_needed_count = 0;
if (cipher_ctx.active) {
++active_count;
if (cipher_ctx.unit_no == src_dma){
meta_out.ciphsel = src_none;
} else {
meta_out.ciphsel = cipher_ctx.current_src;
}
meta_out.ciphconf = cipher_ctx.ciph_conf;
meta_out.cbcmode = cipher_ctx.cbcmode;
meta_out.decrypt = cipher_ctx.decrypt;
DEBUG(printk("set ciphsel=%d ciphconf=%d cbcmode=%d decrypt=%d\n", meta_out.ciphsel, meta_out.ciphconf, meta_out.cbcmode, meta_out.decrypt));
if (cipher_ctx.done) ++eop_needed_count;
} else {
meta_out.ciphsel = src_none;
}
if (digest_ctx.active) {
++active_count;
meta_out.hashsel = digest_ctx.current_src;
meta_out.hashconf = digest_ctx.hash_conf;
meta_out.hashmode = 0;
DEBUG(printk("set hashsel=%d hashconf=%d hashmode=%d\n", meta_out.hashsel, meta_out.hashconf, meta_out.hashmode));
if (digest_ctx.done) {
assert(digest_ctx.pad_descs == NULL);
failed = create_pad_descriptor(&digest_ctx, &digest_ctx.pad_descs, alloc_flag);
if (failed) {
DEBUG_API(printk("cryptocop_setup_dma_list: failed digest pad creation.\n"));
goto error_cleanup;
}
}
} else {
meta_out.hashsel = src_none;
}
if (csum_ctx.active) {
++active_count;
meta_out.csumsel = csum_ctx.current_src;
if (csum_ctx.done) {
assert(csum_ctx.pad_descs == NULL);
failed = create_pad_descriptor(&csum_ctx, &csum_ctx.pad_descs, alloc_flag);
if (failed) {
DEBUG_API(printk("cryptocop_setup_dma_list: failed csum pad creation.\n"));
goto error_cleanup;
}
}
} else {
meta_out.csumsel = src_none;
}
DEBUG(printk("cryptocop_setup_dma_list: %d eop needed, %d active units\n", eop_needed_count, active_count));
failed = create_output_descriptors(operation, &iniov_ix, &iniov_offset, desc_len, &current_out_cdesc, &meta_out, alloc_flag);
if (failed) {
DEBUG_API(printk("cryptocop_setup_dma_list: create_output_descriptors %d\n", failed));
goto error_cleanup;
}
assert(active_count >= eop_needed_count);
assert((eop_needed_count == 0) || (eop_needed_count == 1));
if (eop_needed_count) {
if (active_count > 1) {
struct cryptocop_dma_desc *ed = alloc_cdesc(alloc_flag);
struct strcop_meta_out ed_mo = {0};
if (!ed) {
DEBUG_API(printk("cryptocop_setup_dma_list: alloc EOP descriptor for cipher\n"));
failed = -ENOMEM;
goto error_cleanup;
}
assert(cipher_ctx.active && cipher_ctx.done);
if (cipher_ctx.unit_no == src_dma){
ed_mo.ciphsel = src_none;
} else {
ed_mo.ciphsel = cipher_ctx.current_src;
}
ed_mo.ciphconf = cipher_ctx.ciph_conf;
ed_mo.cbcmode = cipher_ctx.cbcmode;
ed_mo.decrypt = cipher_ctx.decrypt;
ed->free_buf = NULL;
ed->dma_descr->wait = 1;
ed->dma_descr->out_eop = 1;
ed->dma_descr->buf = (char*)virt_to_phys(&ed);
ed->dma_descr->after = ed->dma_descr->buf;
ed->dma_descr->md = REG_TYPE_CONV(unsigned short int, struct strcop_meta_out, ed_mo);
current_out_cdesc->next = ed;
current_out_cdesc = ed;
} else {
current_out_cdesc->dma_descr->out_eop = 1;
}
}
if (cipher_ctx.done && cipher_ctx.active) cipher_ctx.active = 0;
if (digest_ctx.done && digest_ctx.active) digest_ctx.active = 0;
if (csum_ctx.done && csum_ctx.active) csum_ctx.active = 0;
indata_ix += odsc->length;
odsc = odsc->next;
}
DEBUG(printk("cryptocop_setup_dma_list: done parsing operation descriptors\n"));
if (cipher_ctx.tcfg && (cipher_ctx.active || !cipher_ctx.done)){
DEBUG_API(printk("cryptocop_setup_dma_list: cipher operation not terminated.\n"));
failed = -EINVAL;
goto error_cleanup;
}
if (digest_ctx.tcfg && (digest_ctx.active || !digest_ctx.done)){
DEBUG_API(printk("cryptocop_setup_dma_list: digest operation not terminated.\n"));
failed = -EINVAL;
goto error_cleanup;
}
if (csum_ctx.tcfg && (csum_ctx.active || !csum_ctx.done)){
DEBUG_API(printk("cryptocop_setup_dma_list: csum operation not terminated.\n"));
failed = -EINVAL;
goto error_cleanup;
}
failed = append_input_descriptors(operation, &current_in_cdesc, &current_out_cdesc, &cipher_ctx, alloc_flag);
if (failed){
DEBUG_API(printk("cryptocop_setup_dma_list: append_input_descriptors cipher_ctx %d\n", failed));
goto error_cleanup;
}
failed = append_input_descriptors(operation, &current_in_cdesc, &current_out_cdesc, &digest_ctx, alloc_flag);
if (failed){
DEBUG_API(printk("cryptocop_setup_dma_list: append_input_descriptors cipher_ctx %d\n", failed));
goto error_cleanup;
}
failed = append_input_descriptors(operation, &current_in_cdesc, &current_out_cdesc, &csum_ctx, alloc_flag);
if (failed){
DEBUG_API(printk("cryptocop_setup_dma_list: append_input_descriptors cipher_ctx %d\n", failed));
goto error_cleanup;
}
DEBUG(printk("cryptocop_setup_dma_list: int_op=0x%p, *int_op=0x%p\n", int_op, *int_op));
(*int_op)->cdesc_out = out_cdesc_head.next;
(*int_op)->cdesc_in = in_cdesc_head.next;
DEBUG(printk("cryptocop_setup_dma_list: out_cdesc_head=0x%p in_cdesc_head=0x%p\n", (*int_op)->cdesc_out, (*int_op)->cdesc_in));
setup_descr_chain(out_cdesc_head.next);
setup_descr_chain(in_cdesc_head.next);
current_in_cdesc->dma_descr->intr = 1;
current_in_cdesc->dma_descr->eol = 1;
current_out_cdesc->dma_descr->eol = 1;
(*int_op)->ctx_out.next = NULL;
(*int_op)->ctx_out.eol = 1;
(*int_op)->ctx_out.intr = 0;
(*int_op)->ctx_out.store_mode = 0;
(*int_op)->ctx_out.en = 0;
(*int_op)->ctx_out.dis = 0;
(*int_op)->ctx_out.md0 = 0;
(*int_op)->ctx_out.md1 = 0;
(*int_op)->ctx_out.md2 = 0;
(*int_op)->ctx_out.md3 = 0;
(*int_op)->ctx_out.md4 = 0;
(*int_op)->ctx_out.saved_data = (dma_descr_data*)virt_to_phys((*int_op)->cdesc_out->dma_descr);
(*int_op)->ctx_out.saved_data_buf = (*int_op)->cdesc_out->dma_descr->buf;
(*int_op)->ctx_in.next = NULL;
(*int_op)->ctx_in.eol = 1;
(*int_op)->ctx_in.intr = 0;
(*int_op)->ctx_in.store_mode = 0;
(*int_op)->ctx_in.en = 0;
(*int_op)->ctx_in.dis = 0;
(*int_op)->ctx_in.md0 = 0;
(*int_op)->ctx_in.md1 = 0;
(*int_op)->ctx_in.md2 = 0;
(*int_op)->ctx_in.md3 = 0;
(*int_op)->ctx_in.md4 = 0;
(*int_op)->ctx_in.saved_data = (dma_descr_data*)virt_to_phys((*int_op)->cdesc_in->dma_descr);
(*int_op)->ctx_in.saved_data_buf = (*int_op)->cdesc_in->dma_descr->buf;
DEBUG(printk("cryptocop_setup_dma_list: done\n"));
return 0;
error_cleanup:
{
struct cryptocop_dma_desc *tmp_cdesc;
while (digest_ctx.pad_descs){
tmp_cdesc = digest_ctx.pad_descs->next;
free_cdesc(digest_ctx.pad_descs);
digest_ctx.pad_descs = tmp_cdesc;
}
while (csum_ctx.pad_descs){
tmp_cdesc = csum_ctx.pad_descs->next;
free_cdesc(csum_ctx.pad_descs);
csum_ctx.pad_descs = tmp_cdesc;
}
assert(cipher_ctx.pad_descs == NULL);
if (*int_op != NULL) delete_internal_operation(*int_op);
}
DEBUG_API(printk("cryptocop_setup_dma_list: done with error %d\n", failed));
return failed;
}
static void delete_internal_operation(struct cryptocop_int_operation *iop)
{
void *ptr = iop->alloc_ptr;
struct cryptocop_dma_desc *cd = iop->cdesc_out;
struct cryptocop_dma_desc *next;
DEBUG(printk("delete_internal_operation: iop=0x%p, alloc_ptr=0x%p\n", iop, ptr));
while (cd) {
next = cd->next;
free_cdesc(cd);
cd = next;
}
cd = iop->cdesc_in;
while (cd) {
next = cd->next;
free_cdesc(cd);
cd = next;
}
kfree(ptr);
}
static int create_md5_pad(int alloc_flag, unsigned long long hashed_length, char **pad, size_t *pad_length)
{
size_t padlen = MD5_BLOCK_LENGTH - (hashed_length % MD5_BLOCK_LENGTH);
unsigned char *p;
int i;
unsigned long long int bit_length = hashed_length << 3;
if (padlen < MD5_MIN_PAD_LENGTH) padlen += MD5_BLOCK_LENGTH;
p = kzalloc(padlen, alloc_flag);
if (!p) return -ENOMEM;
*p = 0x80;
DEBUG(printk("create_md5_pad: hashed_length=%lld bits == %lld bytes\n", bit_length, hashed_length));
i = padlen - MD5_PAD_LENGTH_FIELD_LENGTH;
while (bit_length != 0){
p[i++] = bit_length % 0x100;
bit_length >>= 8;
}
*pad = (char*)p;
*pad_length = padlen;
return 0;
}
static int create_sha1_pad(int alloc_flag, unsigned long long hashed_length, char **pad, size_t *pad_length)
{
size_t padlen = SHA1_BLOCK_LENGTH - (hashed_length % SHA1_BLOCK_LENGTH);
unsigned char *p;
int i;
unsigned long long int bit_length = hashed_length << 3;
if (padlen < SHA1_MIN_PAD_LENGTH) padlen += SHA1_BLOCK_LENGTH;
p = kzalloc(padlen, alloc_flag);
if (!p) return -ENOMEM;
*p = 0x80;
DEBUG(printk("create_sha1_pad: hashed_length=%lld bits == %lld bytes\n", bit_length, hashed_length));
i = padlen - 1;
while (bit_length != 0){
p[i--] = bit_length % 0x100;
bit_length >>= 8;
}
*pad = (char*)p;
*pad_length = padlen;
return 0;
}
static int transform_ok(struct cryptocop_transform_init *tinit)
{
switch (tinit->alg){
case cryptocop_alg_csum:
switch (tinit->csum_mode){
case cryptocop_csum_le:
case cryptocop_csum_be:
break;
default:
DEBUG_API(printk("transform_ok: Bad mode set for csum transform\n"));
return -EINVAL;
}
case cryptocop_alg_mem2mem:
case cryptocop_alg_md5:
case cryptocop_alg_sha1:
if (tinit->keylen != 0) {
DEBUG_API(printk("transform_ok: non-zero keylength, %d, for a digest/csum algorithm\n", tinit->keylen));
return -EINVAL;
}
break;
case cryptocop_alg_des:
if (tinit->keylen != 64) {
DEBUG_API(printk("transform_ok: keylen %d invalid for DES\n", tinit->keylen));
return -EINVAL;
}
break;
case cryptocop_alg_3des:
if (tinit->keylen != 192) {
DEBUG_API(printk("transform_ok: keylen %d invalid for 3DES\n", tinit->keylen));
return -EINVAL;
}
break;
case cryptocop_alg_aes:
if (tinit->keylen != 128 && tinit->keylen != 192 && tinit->keylen != 256) {
DEBUG_API(printk("transform_ok: keylen %d invalid for AES\n", tinit->keylen));
return -EINVAL;
}
break;
case cryptocop_no_alg:
default:
DEBUG_API(printk("transform_ok: no such algorithm %d\n", tinit->alg));
return -EINVAL;
}
switch (tinit->alg){
case cryptocop_alg_des:
case cryptocop_alg_3des:
case cryptocop_alg_aes:
if (tinit->cipher_mode != cryptocop_cipher_mode_ecb && tinit->cipher_mode != cryptocop_cipher_mode_cbc) return -EINVAL;
default:
break;
}
return 0;
}
int cryptocop_new_session(cryptocop_session_id *sid, struct cryptocop_transform_init *tinit, int alloc_flag)
{
struct cryptocop_session *sess;
struct cryptocop_transform_init *tfrm_in = tinit;
struct cryptocop_transform_init *tmp_in;
int no_tfrms = 0;
int i;
unsigned long int flags;
init_stream_coprocessor();
while (tfrm_in){
int err;
++no_tfrms;
if ((err = transform_ok(tfrm_in))) {
DEBUG_API(printk("cryptocop_new_session, bad transform\n"));
return err;
}
tfrm_in = tfrm_in->next;
}
if (0 == no_tfrms) {
DEBUG_API(printk("cryptocop_new_session, no transforms specified\n"));
return -EINVAL;
}
sess = kmalloc(sizeof(struct cryptocop_session), alloc_flag);
if (!sess){
DEBUG_API(printk("cryptocop_new_session, kmalloc cryptocop_session\n"));
return -ENOMEM;
}
sess->tfrm_ctx = kmalloc(no_tfrms * sizeof(struct cryptocop_transform_ctx), alloc_flag);
if (!sess->tfrm_ctx) {
DEBUG_API(printk("cryptocop_new_session, kmalloc cryptocop_transform_ctx\n"));
kfree(sess);
return -ENOMEM;
}
tfrm_in = tinit;
for (i = 0; i < no_tfrms; i++){
tmp_in = tfrm_in->next;
while (tmp_in){
if (tmp_in->tid == tfrm_in->tid) {
DEBUG_API(printk("cryptocop_new_session, duplicate transform ids\n"));
kfree(sess->tfrm_ctx);
kfree(sess);
return -EINVAL;
}
tmp_in = tmp_in->next;
}
memcpy(&sess->tfrm_ctx[i].init, tfrm_in, sizeof(struct cryptocop_transform_init));
sess->tfrm_ctx[i].dec_key_set = 0;
sess->tfrm_ctx[i].next = &sess->tfrm_ctx[i] + 1;
tfrm_in = tfrm_in->next;
}
sess->tfrm_ctx[i-1].next = NULL;
spin_lock_irqsave(&cryptocop_sessions_lock, flags);
sess->sid = next_sid;
next_sid++;
if (next_sid == 0) next_sid = 1;
sess->next = cryptocop_sessions;
cryptocop_sessions = sess;
spin_unlock_irqrestore(&cryptocop_sessions_lock, flags);
*sid = sess->sid;
return 0;
}
int cryptocop_free_session(cryptocop_session_id sid)
{
struct cryptocop_transform_ctx *tc;
struct cryptocop_session *sess = NULL;
struct cryptocop_session *psess = NULL;
unsigned long int flags;
int i;
LIST_HEAD(remove_list);
struct list_head *node, *tmp;
struct cryptocop_prio_job *pj;
DEBUG(printk("cryptocop_free_session: sid=%lld\n", sid));
spin_lock_irqsave(&cryptocop_sessions_lock, flags);
sess = cryptocop_sessions;
while (sess && sess->sid != sid){
psess = sess;
sess = sess->next;
}
if (sess){
if (psess){
psess->next = sess->next;
} else {
cryptocop_sessions = sess->next;
}
}
spin_unlock_irqrestore(&cryptocop_sessions_lock, flags);
if (!sess) return -EINVAL;
spin_lock_irqsave(&cryptocop_job_queue_lock, flags);
for (i = 0; i < cryptocop_prio_no_prios; i++){
if (!list_empty(&(cryptocop_job_queues[i].jobs))){
list_for_each_safe(node, tmp, &(cryptocop_job_queues[i].jobs)) {
pj = list_entry(node, struct cryptocop_prio_job, node);
if (pj->oper->sid == sid) {
list_move_tail(node, &remove_list);
}
}
}
}
spin_unlock_irqrestore(&cryptocop_job_queue_lock, flags);
list_for_each_safe(node, tmp, &remove_list) {
list_del(node);
pj = list_entry(node, struct cryptocop_prio_job, node);
pj->oper->operation_status = -EAGAIN;
DEBUG(printk("cryptocop_free_session: pj=0x%p, pj->oper=0x%p, pj->iop=0x%p\n", pj, pj->oper, pj->iop));
pj->oper->cb(pj->oper, pj->oper->cb_data);
delete_internal_operation(pj->iop);
kfree(pj);
}
tc = sess->tfrm_ctx;
while (tc){
DEBUG(printk("cryptocop_free_session: memset keys, tfrm id=%d\n", tc->init.tid));
memset(tc->init.key, 0xff, CRYPTOCOP_MAX_KEY_LENGTH);
memset(tc->dec_key, 0xff, CRYPTOCOP_MAX_KEY_LENGTH);
tc = tc->next;
}
kfree(sess->tfrm_ctx);
kfree(sess);
return 0;
}
static struct cryptocop_session *get_session(cryptocop_session_id sid)
{
struct cryptocop_session *sess;
unsigned long int flags;
spin_lock_irqsave(&cryptocop_sessions_lock, flags);
sess = cryptocop_sessions;
while (sess && (sess->sid != sid)){
sess = sess->next;
}
spin_unlock_irqrestore(&cryptocop_sessions_lock, flags);
return sess;
}
static struct cryptocop_transform_ctx *get_transform_ctx(struct cryptocop_session *sess, cryptocop_tfrm_id tid)
{
struct cryptocop_transform_ctx *tc = sess->tfrm_ctx;
DEBUG(printk("get_transform_ctx, sess=0x%p, tid=%d\n", sess, tid));
assert(sess != NULL);
while (tc && tc->init.tid != tid){
DEBUG(printk("tc=0x%p, tc->next=0x%p\n", tc, tc->next));
tc = tc->next;
}
DEBUG(printk("get_transform_ctx, returning tc=0x%p\n", tc));
return tc;
}
static u32 aes_ks_subword(const u32 w)
{
u8 bytes[4];
*(u32*)(&bytes[0]) = w;
bytes[0] = aes_sbox[bytes[0]];
bytes[1] = aes_sbox[bytes[1]];
bytes[2] = aes_sbox[bytes[2]];
bytes[3] = aes_sbox[bytes[3]];
return *(u32*)(&bytes[0]);
}
static void get_aes_decrypt_key(unsigned char *dec_key, const unsigned char *key, unsigned int keylength)
{
u32 temp;
u32 w_ring[8];
u8 w_last_ix;
int i;
u8 nr, nk;
switch (keylength){
case 128:
nk = 4;
nr = 10;
break;
case 192:
nk = 6;
nr = 12;
break;
case 256:
nk = 8;
nr = 14;
break;
default:
panic("stream co-processor: bad aes key length in get_aes_decrypt_key\n");
};
for (i = 0; i < nk; i+=1) {
w_ring[i] = be32_to_cpu(*(u32*)&key[4*i]);
}
i = (int)nk;
w_last_ix = i - 1;
while (i < (4 * (nr + 2))) {
temp = w_ring[w_last_ix];
if (!(i % nk)) {
temp = (temp << 8) | (temp >> 24);
temp = aes_ks_subword(temp);
temp ^= round_constant[i/nk - 1];
} else if ((nk > 6) && ((i % nk) == 4)) {
temp = aes_ks_subword(temp);
}
w_last_ix = (w_last_ix + 1) % nk;
temp ^= w_ring[w_last_ix];
w_ring[w_last_ix] = temp;
if (i >= (4 * nr)) {
*(u32*)dec_key = cpu_to_be32(temp);
dec_key += 4;
}
++i;
}
}
int cryptocop_job_queue_insert_csum(struct cryptocop_operation *operation)
{
return cryptocop_job_queue_insert(cryptocop_prio_kernel_csum, operation);
}
int cryptocop_job_queue_insert_crypto(struct cryptocop_operation *operation)
{
return cryptocop_job_queue_insert(cryptocop_prio_kernel, operation);
}
int cryptocop_job_queue_insert_user_job(struct cryptocop_operation *operation)
{
return cryptocop_job_queue_insert(cryptocop_prio_user, operation);
}
static int cryptocop_job_queue_insert(cryptocop_queue_priority prio, struct cryptocop_operation *operation)
{
int ret;
struct cryptocop_prio_job *pj = NULL;
unsigned long int flags;
DEBUG(printk("cryptocop_job_queue_insert(%d, 0x%p)\n", prio, operation));
if (!operation || !operation->cb){
DEBUG_API(printk("cryptocop_job_queue_insert oper=0x%p, NULL operation or callback\n", operation));
return -EINVAL;
}
if ((ret = cryptocop_job_setup(&pj, operation)) != 0){
DEBUG_API(printk("cryptocop_job_queue_insert: job setup failed\n"));
return ret;
}
assert(pj != NULL);
spin_lock_irqsave(&cryptocop_job_queue_lock, flags);
list_add_tail(&pj->node, &cryptocop_job_queues[prio].jobs);
spin_unlock_irqrestore(&cryptocop_job_queue_lock, flags);
cryptocop_start_job();
return 0;
}
static void cryptocop_do_tasklet(unsigned long unused)
{
struct list_head *node;
struct cryptocop_prio_job *pj = NULL;
unsigned long flags;
DEBUG(printk("cryptocop_do_tasklet: entering\n"));
do {
spin_lock_irqsave(&cryptocop_completed_jobs_lock, flags);
if (!list_empty(&cryptocop_completed_jobs)){
node = cryptocop_completed_jobs.next;
list_del(node);
pj = list_entry(node, struct cryptocop_prio_job, node);
} else {
pj = NULL;
}
spin_unlock_irqrestore(&cryptocop_completed_jobs_lock, flags);
if (pj) {
assert(pj->oper != NULL);
DEBUG(printk("cryptocop_do_tasklet: callback 0x%p, data 0x%p\n", pj->oper->cb, pj->oper->cb_data));
pj->oper->operation_status = 0;
pj->oper->cb(pj->oper, pj->oper->cb_data);
delete_internal_operation(pj->iop);
kfree(pj);
}
} while (pj != NULL);
DEBUG(printk("cryptocop_do_tasklet: exiting\n"));
}
static irqreturn_t
dma_done_interrupt(int irq, void *dev_id)
{
struct cryptocop_prio_job *done_job;
reg_dma_rw_ack_intr ack_intr = {
.data = 1,
};
REG_WR(dma, IN_DMA_INST, rw_ack_intr, ack_intr);
DEBUG(printk("cryptocop DMA done\n"));
spin_lock(&running_job_lock);
if (cryptocop_running_job == NULL){
printk("stream co-processor got interrupt when not busy\n");
spin_unlock(&running_job_lock);
return IRQ_HANDLED;
}
done_job = cryptocop_running_job;
cryptocop_running_job = NULL;
spin_unlock(&running_job_lock);
if (!spin_trylock(&cryptocop_process_lock)){
DEBUG(printk("cryptocop irq handler, not starting a job\n"));
} else {
cryptocop_start_job();
spin_unlock(&cryptocop_process_lock);
}
done_job->oper->operation_status = 0;
if (done_job->oper->fast_callback){
done_job->oper->cb(done_job->oper, done_job->oper->cb_data);
delete_internal_operation(done_job->iop);
kfree(done_job);
} else {
spin_lock(&cryptocop_completed_jobs_lock);
list_add_tail(&(done_job->node), &cryptocop_completed_jobs);
spin_unlock(&cryptocop_completed_jobs_lock);
tasklet_schedule(&cryptocop_tasklet);
}
DEBUG(printk("cryptocop leave irq handler\n"));
return IRQ_HANDLED;
}
static int init_cryptocop(void)
{
unsigned long flags;
reg_dma_rw_cfg dma_cfg = {.en = 1};
reg_dma_rw_intr_mask intr_mask_in = {.data = regk_dma_yes};
reg_dma_rw_ack_intr ack_intr = {.data = 1,.in_eop = 1 };
reg_strcop_rw_cfg strcop_cfg = {
.ipend = regk_strcop_little,
.td1 = regk_strcop_e,
.td2 = regk_strcop_d,
.td3 = regk_strcop_e,
.ignore_sync = 0,
.en = 1
};
if (request_irq(DMA_IRQ, dma_done_interrupt, 0,
"stream co-processor DMA", NULL))
panic("request_irq stream co-processor irq dma9");
(void)crisv32_request_dma(OUT_DMA, "strcop", DMA_PANIC_ON_ERROR,
0, dma_strp);
(void)crisv32_request_dma(IN_DMA, "strcop", DMA_PANIC_ON_ERROR,
0, dma_strp);
local_irq_save(flags);
strcop_cfg.en = 0;
REG_WR(strcop, regi_strcop, rw_cfg, strcop_cfg);
strcop_cfg.en = 1;
REG_WR(strcop, regi_strcop, rw_cfg, strcop_cfg);
REG_WR(dma, IN_DMA_INST, rw_cfg, dma_cfg);
REG_WR(dma, OUT_DMA_INST, rw_cfg, dma_cfg);
DMA_WR_CMD(OUT_DMA_INST, regk_dma_set_w_size4);
DMA_WR_CMD(IN_DMA_INST, regk_dma_set_w_size4);
REG_WR(dma, IN_DMA_INST, rw_intr_mask, intr_mask_in);
REG_WR(dma, IN_DMA_INST, rw_ack_intr, ack_intr);
local_irq_restore(flags);
return 0;
}
static void release_cryptocop(void)
{
unsigned long flags;
reg_dma_rw_cfg dma_cfg = {.en = 0};
reg_dma_rw_intr_mask intr_mask_in = {0};
reg_dma_rw_ack_intr ack_intr = {.data = 1,.in_eop = 1 };
local_irq_save(flags);
REG_WR(dma, IN_DMA_INST, rw_ack_intr, ack_intr);
REG_WR(dma, IN_DMA_INST, rw_cfg, dma_cfg);
REG_WR(dma, OUT_DMA_INST, rw_cfg, dma_cfg);
REG_WR(dma, IN_DMA_INST, rw_intr_mask, intr_mask_in);
local_irq_restore(flags);
free_irq(DMA_IRQ, NULL);
(void)crisv32_free_dma(OUT_DMA);
(void)crisv32_free_dma(IN_DMA);
}
static int cryptocop_job_queue_init(void)
{
int i;
INIT_LIST_HEAD(&cryptocop_completed_jobs);
for (i = 0; i < cryptocop_prio_no_prios; i++){
cryptocop_job_queues[i].prio = (cryptocop_queue_priority)i;
INIT_LIST_HEAD(&cryptocop_job_queues[i].jobs);
}
return 0;
}
static void cryptocop_job_queue_close(void)
{
struct list_head *node, *tmp;
struct cryptocop_prio_job *pj = NULL;
unsigned long int process_flags, flags;
int i;
spin_lock_irqsave(&cryptocop_process_lock, process_flags);
for (i = 0; i < cryptocop_prio_no_prios; i++){
if (!list_empty(&(cryptocop_job_queues[i].jobs))){
list_for_each_safe(node, tmp, &(cryptocop_job_queues[i].jobs)) {
pj = list_entry(node, struct cryptocop_prio_job, node);
list_del(node);
DEBUG(printk("cryptocop_job_queue_close: callback 0x%p, data 0x%p\n", pj->oper->cb, pj->oper->cb_data));
pj->oper->operation_status = -EINTR;
pj->oper->cb(pj->oper, pj->oper->cb_data);
delete_internal_operation(pj->iop);
kfree(pj);
}
}
}
spin_unlock_irqrestore(&cryptocop_process_lock, process_flags);
spin_lock_irqsave(&running_job_lock, flags);
if (cryptocop_running_job){
reg_strcop_rw_cfg rw_cfg;
reg_dma_rw_cfg dma_out_cfg, dma_in_cfg;
dma_out_cfg = REG_RD(dma, OUT_DMA_INST, rw_cfg);
dma_out_cfg.en = regk_dma_no;
REG_WR(dma, OUT_DMA_INST, rw_cfg, dma_out_cfg);
dma_in_cfg = REG_RD(dma, IN_DMA_INST, rw_cfg);
dma_in_cfg.en = regk_dma_no;
REG_WR(dma, IN_DMA_INST, rw_cfg, dma_in_cfg);
rw_cfg = REG_RD(strcop, regi_strcop, rw_cfg);
rw_cfg.en = 0;
REG_WR(strcop, regi_strcop, rw_cfg, rw_cfg);
pj = cryptocop_running_job;
cryptocop_running_job = NULL;
DEBUG(printk("cryptocop_job_queue_close: callback 0x%p, data 0x%p\n", pj->oper->cb, pj->oper->cb_data));
pj->oper->operation_status = -EINTR;
pj->oper->cb(pj->oper, pj->oper->cb_data);
delete_internal_operation(pj->iop);
kfree(pj);
}
spin_unlock_irqrestore(&running_job_lock, flags);
spin_lock_irqsave(&cryptocop_completed_jobs_lock, flags);
list_for_each_safe(node, tmp, &cryptocop_completed_jobs) {
pj = list_entry(node, struct cryptocop_prio_job, node);
list_del(node);
DEBUG(printk("cryptocop_job_queue_close: callback 0x%p, data 0x%p\n", pj->oper->cb, pj->oper->cb_data));
pj->oper->operation_status = -EINTR;
pj->oper->cb(pj->oper, pj->oper->cb_data);
delete_internal_operation(pj->iop);
kfree(pj);
}
spin_unlock_irqrestore(&cryptocop_completed_jobs_lock, flags);
}
static void cryptocop_start_job(void)
{
int i;
struct cryptocop_prio_job *pj;
unsigned long int flags;
unsigned long int running_job_flags;
reg_strcop_rw_cfg rw_cfg = {.en = 1, .ignore_sync = 0};
DEBUG(printk("cryptocop_start_job: entering\n"));
spin_lock_irqsave(&running_job_lock, running_job_flags);
if (cryptocop_running_job != NULL){
DEBUG(printk("cryptocop_start_job: already running, exit\n"));
spin_unlock_irqrestore(&running_job_lock, running_job_flags);
return;
}
spin_lock_irqsave(&cryptocop_job_queue_lock, flags);
for (i = cryptocop_prio_kernel_csum; (i < cryptocop_prio_no_prios) && list_empty(&cryptocop_job_queues[i].jobs); i++);
if (i == cryptocop_prio_no_prios) {
spin_unlock_irqrestore(&cryptocop_job_queue_lock, flags);
spin_unlock_irqrestore(&running_job_lock, running_job_flags);
DEBUG(printk("cryptocop_start_job: no jobs to run\n"));
return;
}
DEBUG(printk("starting job for prio %d\n", i));
pj = list_entry(cryptocop_job_queues[i].jobs.next, struct cryptocop_prio_job, node);
list_del(&pj->node);
spin_unlock_irqrestore(&cryptocop_job_queue_lock, flags);
cryptocop_running_job = pj;
switch (pj->iop->tdes_mode){
case cryptocop_3des_eee:
rw_cfg.td1 = regk_strcop_e;
rw_cfg.td2 = regk_strcop_e;
rw_cfg.td3 = regk_strcop_e;
break;
case cryptocop_3des_eed:
rw_cfg.td1 = regk_strcop_e;
rw_cfg.td2 = regk_strcop_e;
rw_cfg.td3 = regk_strcop_d;
break;
case cryptocop_3des_ede:
rw_cfg.td1 = regk_strcop_e;
rw_cfg.td2 = regk_strcop_d;
rw_cfg.td3 = regk_strcop_e;
break;
case cryptocop_3des_edd:
rw_cfg.td1 = regk_strcop_e;
rw_cfg.td2 = regk_strcop_d;
rw_cfg.td3 = regk_strcop_d;
break;
case cryptocop_3des_dee:
rw_cfg.td1 = regk_strcop_d;
rw_cfg.td2 = regk_strcop_e;
rw_cfg.td3 = regk_strcop_e;
break;
case cryptocop_3des_ded:
rw_cfg.td1 = regk_strcop_d;
rw_cfg.td2 = regk_strcop_e;
rw_cfg.td3 = regk_strcop_d;
break;
case cryptocop_3des_dde:
rw_cfg.td1 = regk_strcop_d;
rw_cfg.td2 = regk_strcop_d;
rw_cfg.td3 = regk_strcop_e;
break;
case cryptocop_3des_ddd:
rw_cfg.td1 = regk_strcop_d;
rw_cfg.td2 = regk_strcop_d;
rw_cfg.td3 = regk_strcop_d;
break;
default:
DEBUG(printk("cryptocop_setup_dma_list: bad 3DES mode\n"));
}
switch (pj->iop->csum_mode){
case cryptocop_csum_le:
rw_cfg.ipend = regk_strcop_little;
break;
case cryptocop_csum_be:
rw_cfg.ipend = regk_strcop_big;
break;
default:
DEBUG(printk("cryptocop_setup_dma_list: bad checksum mode\n"));
}
REG_WR(strcop, regi_strcop, rw_cfg, rw_cfg);
DEBUG(printk("cryptocop_start_job: starting DMA, new cryptocop_running_job=0x%p\n"
"ctx_in: 0x%p, phys: 0x%p\n"
"ctx_out: 0x%p, phys: 0x%p\n",
pj,
&pj->iop->ctx_in, (char*)virt_to_phys(&pj->iop->ctx_in),
&pj->iop->ctx_out, (char*)virt_to_phys(&pj->iop->ctx_out)));
flush_dma_context(&pj->iop->ctx_in);
DMA_START_CONTEXT(IN_DMA_INST, virt_to_phys(&pj->iop->ctx_in));
DMA_START_CONTEXT(OUT_DMA_INST, virt_to_phys(&pj->iop->ctx_out));
spin_unlock_irqrestore(&running_job_lock, running_job_flags);
DEBUG(printk("cryptocop_start_job: exiting\n"));
}
static int cryptocop_job_setup(struct cryptocop_prio_job **pj, struct cryptocop_operation *operation)
{
int err;
int alloc_flag = operation->in_interrupt ? GFP_ATOMIC : GFP_KERNEL;
void *iop_alloc_ptr = NULL;
*pj = kmalloc(sizeof (struct cryptocop_prio_job), alloc_flag);
if (!*pj) return -ENOMEM;
DEBUG(printk("cryptocop_job_setup: operation=0x%p\n", operation));
(*pj)->oper = operation;
DEBUG(printk("cryptocop_job_setup, cb=0x%p cb_data=0x%p\n", (*pj)->oper->cb, (*pj)->oper->cb_data));
if (operation->use_dmalists) {
DEBUG(print_user_dma_lists(&operation->list_op));
if (!operation->list_op.inlist || !operation->list_op.outlist || !operation->list_op.out_data_buf || !operation->list_op.in_data_buf){
DEBUG_API(printk("cryptocop_job_setup: bad indata (use_dmalists)\n"));
kfree(*pj);
return -EINVAL;
}
iop_alloc_ptr = kmalloc(DESCR_ALLOC_PAD + sizeof(struct cryptocop_int_operation), alloc_flag);
if (!iop_alloc_ptr) {
DEBUG_API(printk("cryptocop_job_setup: kmalloc cryptocop_int_operation\n"));
kfree(*pj);
return -ENOMEM;
}
(*pj)->iop = (struct cryptocop_int_operation*)(((unsigned long int)(iop_alloc_ptr + DESCR_ALLOC_PAD + offsetof(struct cryptocop_int_operation, ctx_out)) & ~0x0000001F) - offsetof(struct cryptocop_int_operation, ctx_out));
DEBUG(memset((*pj)->iop, 0xff, sizeof(struct cryptocop_int_operation)));
(*pj)->iop->alloc_ptr = iop_alloc_ptr;
(*pj)->iop->sid = operation->sid;
(*pj)->iop->cdesc_out = NULL;
(*pj)->iop->cdesc_in = NULL;
(*pj)->iop->tdes_mode = operation->list_op.tdes_mode;
(*pj)->iop->csum_mode = operation->list_op.csum_mode;
(*pj)->iop->ddesc_out = operation->list_op.outlist;
(*pj)->iop->ddesc_in = operation->list_op.inlist;
(*pj)->iop->ctx_out.next = NULL;
(*pj)->iop->ctx_out.eol = 1;
(*pj)->iop->ctx_out.saved_data = operation->list_op.outlist;
(*pj)->iop->ctx_out.saved_data_buf = operation->list_op.out_data_buf;
(*pj)->iop->ctx_in.next = NULL;
(*pj)->iop->ctx_in.eol = 1;
(*pj)->iop->ctx_in.saved_data = operation->list_op.inlist;
(*pj)->iop->ctx_in.saved_data_buf = operation->list_op.in_data_buf;
} else {
if ((err = cryptocop_setup_dma_list(operation, &(*pj)->iop, alloc_flag))) {
DEBUG_API(printk("cryptocop_job_setup: cryptocop_setup_dma_list failed %d\n", err));
kfree(*pj);
return err;
}
}
DEBUG(print_dma_descriptors((*pj)->iop));
DEBUG(printk("cryptocop_job_setup, DMA list setup successful\n"));
return 0;
}
static int cryptocop_open(struct inode *inode, struct file *filp)
{
int p = iminor(inode);
if (p != CRYPTOCOP_MINOR) return -EINVAL;
filp->private_data = NULL;
return 0;
}
static int cryptocop_release(struct inode *inode, struct file *filp)
{
struct cryptocop_private *dev = filp->private_data;
struct cryptocop_private *dev_next;
while (dev){
dev_next = dev->next;
if (dev->sid != CRYPTOCOP_SESSION_ID_NONE) {
(void)cryptocop_free_session(dev->sid);
}
kfree(dev);
dev = dev_next;
}
return 0;
}
static int cryptocop_ioctl_close_session(struct inode *inode, struct file *filp,
unsigned int cmd, unsigned long arg)
{
struct cryptocop_private *dev = filp->private_data;
struct cryptocop_private *prev_dev = NULL;
struct strcop_session_op *sess_op = (struct strcop_session_op *)arg;
struct strcop_session_op sop;
int err;
DEBUG(printk("cryptocop_ioctl_close_session\n"));
if (!access_ok(VERIFY_READ, sess_op, sizeof(struct strcop_session_op)))
return -EFAULT;
err = copy_from_user(&sop, sess_op, sizeof(struct strcop_session_op));
if (err) return -EFAULT;
while (dev && (dev->sid != sop.ses_id)) {
prev_dev = dev;
dev = dev->next;
}
if (dev){
if (prev_dev){
prev_dev->next = dev->next;
} else {
filp->private_data = dev->next;
}
err = cryptocop_free_session(dev->sid);
if (err) return -EFAULT;
} else {
DEBUG_API(printk("cryptocop_ioctl_close_session: session %lld not found\n", sop.ses_id));
return -EINVAL;
}
return 0;
}
static void ioctl_process_job_callback(struct cryptocop_operation *op, void*cb_data)
{
struct ioctl_job_cb_ctx *jc = (struct ioctl_job_cb_ctx *)cb_data;
DEBUG(printk("ioctl_process_job_callback: op=0x%p, cb_data=0x%p\n", op, cb_data));
jc->processed = 1;
wake_up(&cryptocop_ioc_process_wq);
}
static size_t first_cfg_change_ix(struct strcop_crypto_op *crp_op)
{
size_t ch_ix = 0;
if (crp_op->do_cipher) ch_ix = crp_op->cipher_start;
if (crp_op->do_digest && (crp_op->digest_start < ch_ix)) ch_ix = crp_op->digest_start;
if (crp_op->do_csum && (crp_op->csum_start < ch_ix)) ch_ix = crp_op->csum_start;
DEBUG(printk("first_cfg_change_ix: ix=%d\n", ch_ix));
return ch_ix;
}
static size_t next_cfg_change_ix(struct strcop_crypto_op *crp_op, size_t ix)
{
size_t ch_ix = INT_MAX;
size_t tmp_ix = 0;
if (crp_op->do_cipher && ((crp_op->cipher_start + crp_op->cipher_len) > ix)){
if (crp_op->cipher_start > ix) {
ch_ix = crp_op->cipher_start;
} else {
ch_ix = crp_op->cipher_start + crp_op->cipher_len;
}
}
if (crp_op->do_digest && ((crp_op->digest_start + crp_op->digest_len) > ix)){
if (crp_op->digest_start > ix) {
tmp_ix = crp_op->digest_start;
} else {
tmp_ix = crp_op->digest_start + crp_op->digest_len;
}
if (tmp_ix < ch_ix) ch_ix = tmp_ix;
}
if (crp_op->do_csum && ((crp_op->csum_start + crp_op->csum_len) > ix)){
if (crp_op->csum_start > ix) {
tmp_ix = crp_op->csum_start;
} else {
tmp_ix = crp_op->csum_start + crp_op->csum_len;
}
if (tmp_ix < ch_ix) ch_ix = tmp_ix;
}
if (ch_ix == INT_MAX) ch_ix = ix;
DEBUG(printk("next_cfg_change_ix prev ix=%d, next ix=%d\n", ix, ch_ix));
return ch_ix;
}
static int map_pages_to_iovec(struct iovec *iov, int iovlen, int *iovix, struct page **pages, int nopages, int *pageix, int *pageoffset, int map_length )
{
int tmplen;
assert(iov != NULL);
assert(iovix != NULL);
assert(pages != NULL);
assert(pageix != NULL);
assert(pageoffset != NULL);
DEBUG(printk("map_pages_to_iovec, map_length=%d, iovlen=%d, *iovix=%d, nopages=%d, *pageix=%d, *pageoffset=%d\n", map_length, iovlen, *iovix, nopages, *pageix, *pageoffset));
while (map_length > 0){
DEBUG(printk("map_pages_to_iovec, map_length=%d, iovlen=%d, *iovix=%d, nopages=%d, *pageix=%d, *pageoffset=%d\n", map_length, iovlen, *iovix, nopages, *pageix, *pageoffset));
if (*iovix >= iovlen){
DEBUG_API(printk("map_page_to_iovec: *iovix=%d >= iovlen=%d\n", *iovix, iovlen));
return 0;
}
if (*pageix >= nopages){
DEBUG_API(printk("map_page_to_iovec: *pageix=%d >= nopages=%d\n", *pageix, nopages));
return 0;
}
iov[*iovix].iov_base = (unsigned char*)page_address(pages[*pageix]) + *pageoffset;
tmplen = PAGE_SIZE - *pageoffset;
if (tmplen < map_length){
(*pageoffset) = 0;
(*pageix)++;
} else {
tmplen = map_length;
(*pageoffset) += map_length;
}
DEBUG(printk("mapping %d bytes from page %d (or %d) to iovec %d\n", tmplen, *pageix, *pageix-1, *iovix));
iov[*iovix].iov_len = tmplen;
map_length -= tmplen;
(*iovix)++;
}
DEBUG(printk("map_page_to_iovec, exit, *iovix=%d\n", *iovix));
return -1;
}
static int cryptocop_ioctl_process(struct inode *inode, struct file *filp, unsigned int cmd, unsigned long arg)
{
int i;
struct cryptocop_private *dev = filp->private_data;
struct strcop_crypto_op *crp_oper = (struct strcop_crypto_op *)arg;
struct strcop_crypto_op oper = {0};
int err = 0;
struct cryptocop_operation *cop = NULL;
struct ioctl_job_cb_ctx *jc = NULL;
struct page **inpages = NULL;
struct page **outpages = NULL;
int noinpages = 0;
int nooutpages = 0;
struct cryptocop_desc descs[5];
struct cryptocop_desc_cfg dcfgs[5*3];
int desc_ix = 0;
int dcfg_ix = 0;
struct cryptocop_tfrm_cfg ciph_tcfg = {0};
struct cryptocop_tfrm_cfg digest_tcfg = {0};
struct cryptocop_tfrm_cfg csum_tcfg = {0};
unsigned char *digest_result = NULL;
int digest_length = 0;
int cblocklen = 0;
unsigned char csum_result[CSUM_BLOCK_LENGTH];
struct cryptocop_session *sess;
int iovlen = 0;
int iovix = 0;
int pageix = 0;
int pageoffset = 0;
size_t prev_ix = 0;
size_t next_ix;
int cipher_active, digest_active, csum_active;
int end_digest, end_csum;
int digest_done = 0;
int cipher_done = 0;
int csum_done = 0;
DEBUG(printk("cryptocop_ioctl_process\n"));
if (!access_ok(VERIFY_WRITE, crp_oper, sizeof(struct strcop_crypto_op))){
DEBUG_API(printk("cryptocop_ioctl_process: !access_ok crp_oper!\n"));
return -EFAULT;
}
if (copy_from_user(&oper, crp_oper, sizeof(struct strcop_crypto_op))) {
DEBUG_API(printk("cryptocop_ioctl_process: copy_from_user\n"));
return -EFAULT;
}
DEBUG(print_strcop_crypto_op(&oper));
while (dev && dev->sid != oper.ses_id) dev = dev->next;
if (!dev){
DEBUG_API(printk("cryptocop_ioctl_process: session %lld not found\n", oper.ses_id));
return -EINVAL;
}
if (((oper.indata + oper.inlen) < oper.indata) || ((oper.cipher_outdata + oper.cipher_outlen) < oper.cipher_outdata)){
DEBUG_API(printk("cryptocop_ioctl_process: user buffers wrapped around, bad user!\n"));
return -EINVAL;
}
if (!access_ok(VERIFY_WRITE, oper.cipher_outdata, oper.cipher_outlen)){
DEBUG_API(printk("cryptocop_ioctl_process: !access_ok out data!\n"));
return -EFAULT;
}
if (!access_ok(VERIFY_READ, oper.indata, oper.inlen)){
DEBUG_API(printk("cryptocop_ioctl_process: !access_ok in data!\n"));
return -EFAULT;
}
cop = kmalloc(sizeof(struct cryptocop_operation), GFP_KERNEL);
if (!cop) {
DEBUG_API(printk("cryptocop_ioctl_process: kmalloc\n"));
return -ENOMEM;
}
jc = kmalloc(sizeof(struct ioctl_job_cb_ctx), GFP_KERNEL);
if (!jc) {
DEBUG_API(printk("cryptocop_ioctl_process: kmalloc\n"));
err = -ENOMEM;
goto error_cleanup;
}
jc->processed = 0;
cop->cb_data = jc;
cop->cb = ioctl_process_job_callback;
cop->operation_status = 0;
cop->use_dmalists = 0;
cop->in_interrupt = 0;
cop->fast_callback = 0;
cop->tfrm_op.tfrm_cfg = NULL;
cop->tfrm_op.desc = NULL;
cop->tfrm_op.indata = NULL;
cop->tfrm_op.incount = 0;
cop->tfrm_op.inlen = 0;
cop->tfrm_op.outdata = NULL;
cop->tfrm_op.outcount = 0;
cop->tfrm_op.outlen = 0;
sess = get_session(oper.ses_id);
if (!sess){
DEBUG_API(printk("cryptocop_ioctl_process: bad session id.\n"));
kfree(cop);
kfree(jc);
return -EINVAL;
}
if (oper.do_cipher) {
unsigned int cipher_outlen = 0;
struct cryptocop_transform_ctx *tc = get_transform_ctx(sess, CRYPTOCOP_IOCTL_CIPHER_TID);
if (!tc) {
DEBUG_API(printk("cryptocop_ioctl_process: no cipher transform in session.\n"));
err = -EINVAL;
goto error_cleanup;
}
ciph_tcfg.tid = CRYPTOCOP_IOCTL_CIPHER_TID;
ciph_tcfg.inject_ix = 0;
ciph_tcfg.flags = 0;
if ((oper.cipher_start < 0) || (oper.cipher_len <= 0) || (oper.cipher_start > oper.inlen) || ((oper.cipher_start + oper.cipher_len) > oper.inlen)){
DEBUG_API(printk("cryptocop_ioctl_process: bad cipher length\n"));
kfree(cop);
kfree(jc);
return -EINVAL;
}
cblocklen = tc->init.alg == cryptocop_alg_aes ? AES_BLOCK_LENGTH : DES_BLOCK_LENGTH;
if (oper.cipher_len % cblocklen) {
kfree(cop);
kfree(jc);
DEBUG_API(printk("cryptocop_ioctl_process: cipher inlength not multiple of block length.\n"));
return -EINVAL;
}
cipher_outlen = oper.cipher_len;
if (tc->init.cipher_mode == cryptocop_cipher_mode_cbc){
if (oper.cipher_explicit) {
ciph_tcfg.flags |= CRYPTOCOP_EXPLICIT_IV;
memcpy(ciph_tcfg.iv, oper.cipher_iv, cblocklen);
} else {
cipher_outlen = oper.cipher_len - cblocklen;
}
} else {
if (oper.cipher_explicit){
kfree(cop);
kfree(jc);
DEBUG_API(printk("cryptocop_ioctl_process: explicit_iv when not CBC mode\n"));
return -EINVAL;
}
}
if (oper.cipher_outlen != cipher_outlen) {
kfree(cop);
kfree(jc);
DEBUG_API(printk("cryptocop_ioctl_process: cipher_outlen incorrect, should be %d not %d.\n", cipher_outlen, oper.cipher_outlen));
return -EINVAL;
}
if (oper.decrypt){
ciph_tcfg.flags |= CRYPTOCOP_DECRYPT;
} else {
ciph_tcfg.flags |= CRYPTOCOP_ENCRYPT;
}
ciph_tcfg.next = cop->tfrm_op.tfrm_cfg;
cop->tfrm_op.tfrm_cfg = &ciph_tcfg;
}
if (oper.do_digest){
struct cryptocop_transform_ctx *tc = get_transform_ctx(sess, CRYPTOCOP_IOCTL_DIGEST_TID);
if (!tc) {
DEBUG_API(printk("cryptocop_ioctl_process: no digest transform in session.\n"));
err = -EINVAL;
goto error_cleanup;
}
digest_length = tc->init.alg == cryptocop_alg_md5 ? 16 : 20;
digest_result = kmalloc(digest_length, GFP_KERNEL);
if (!digest_result) {
DEBUG_API(printk("cryptocop_ioctl_process: kmalloc digest_result\n"));
err = -EINVAL;
goto error_cleanup;
}
DEBUG(memset(digest_result, 0xff, digest_length));
digest_tcfg.tid = CRYPTOCOP_IOCTL_DIGEST_TID;
digest_tcfg.inject_ix = 0;
ciph_tcfg.inject_ix += digest_length;
if ((oper.digest_start < 0) || (oper.digest_len <= 0) || (oper.digest_start > oper.inlen) || ((oper.digest_start + oper.digest_len) > oper.inlen)){
DEBUG_API(printk("cryptocop_ioctl_process: bad digest length\n"));
err = -EINVAL;
goto error_cleanup;
}
digest_tcfg.next = cop->tfrm_op.tfrm_cfg;
cop->tfrm_op.tfrm_cfg = &digest_tcfg;
}
if (oper.do_csum){
csum_tcfg.tid = CRYPTOCOP_IOCTL_CSUM_TID;
csum_tcfg.inject_ix = digest_length;
ciph_tcfg.inject_ix += 2;
if ((oper.csum_start < 0) || (oper.csum_len <= 0) || (oper.csum_start > oper.inlen) || ((oper.csum_start + oper.csum_len) > oper.inlen)){
DEBUG_API(printk("cryptocop_ioctl_process: bad csum length\n"));
kfree(cop);
kfree(jc);
return -EINVAL;
}
csum_tcfg.next = cop->tfrm_op.tfrm_cfg;
cop->tfrm_op.tfrm_cfg = &csum_tcfg;
}
prev_ix = first_cfg_change_ix(&oper);
if (prev_ix > oper.inlen) {
DEBUG_API(printk("cryptocop_ioctl_process: length mismatch\n"));
nooutpages = noinpages = 0;
err = -EINVAL;
goto error_cleanup;
}
DEBUG(printk("cryptocop_ioctl_process: inlen=%d, cipher_outlen=%d\n", oper.inlen, oper.cipher_outlen));
noinpages = (((unsigned long int)(oper.indata + prev_ix) & ~PAGE_MASK) + oper.inlen - 1 - prev_ix + ~PAGE_MASK) >> PAGE_SHIFT;
DEBUG(printk("cryptocop_ioctl_process: noinpages=%d\n", noinpages));
inpages = kmalloc(noinpages * sizeof(struct page*), GFP_KERNEL);
if (!inpages){
DEBUG_API(printk("cryptocop_ioctl_process: kmalloc inpages\n"));
nooutpages = noinpages = 0;
err = -ENOMEM;
goto error_cleanup;
}
if (oper.do_cipher){
nooutpages = (((unsigned long int)oper.cipher_outdata & ~PAGE_MASK) + oper.cipher_outlen - 1 + ~PAGE_MASK) >> PAGE_SHIFT;
DEBUG(printk("cryptocop_ioctl_process: nooutpages=%d\n", nooutpages));
outpages = kmalloc(nooutpages * sizeof(struct page*), GFP_KERNEL);
if (!outpages){
DEBUG_API(printk("cryptocop_ioctl_process: kmalloc outpages\n"));
nooutpages = noinpages = 0;
err = -ENOMEM;
goto error_cleanup;
}
}
down_read(&current->mm->mmap_sem);
err = get_user_pages(current,
current->mm,
(unsigned long int)(oper.indata + prev_ix),
noinpages,
0,
0,
inpages,
NULL);
if (err < 0) {
up_read(&current->mm->mmap_sem);
nooutpages = noinpages = 0;
DEBUG_API(printk("cryptocop_ioctl_process: get_user_pages indata\n"));
goto error_cleanup;
}
noinpages = err;
if (oper.do_cipher){
err = get_user_pages(current,
current->mm,
(unsigned long int)oper.cipher_outdata,
nooutpages,
1,
0,
outpages,
NULL);
up_read(&current->mm->mmap_sem);
if (err < 0) {
nooutpages = 0;
DEBUG_API(printk("cryptocop_ioctl_process: get_user_pages outdata\n"));
goto error_cleanup;
}
nooutpages = err;
} else {
up_read(&current->mm->mmap_sem);
}
cop->tfrm_op.indata = kmalloc((noinpages) * sizeof(struct iovec), GFP_KERNEL);
cop->tfrm_op.outdata = kmalloc((6 + nooutpages) * sizeof(struct iovec), GFP_KERNEL);
if (!cop->tfrm_op.indata || !cop->tfrm_op.outdata) {
DEBUG_API(printk("cryptocop_ioctl_process: kmalloc iovecs\n"));
err = -ENOMEM;
goto error_cleanup;
}
cop->tfrm_op.inlen = oper.inlen - prev_ix;
cop->tfrm_op.outlen = 0;
if (oper.do_cipher) cop->tfrm_op.outlen += oper.cipher_outlen;
if (oper.do_digest) cop->tfrm_op.outlen += digest_length;
if (oper.do_csum) cop->tfrm_op.outlen += 2;
cop->tfrm_op.incount = noinpages;
if (noinpages > 1){
size_t tmplen = cop->tfrm_op.inlen;
cop->tfrm_op.indata[0].iov_len = PAGE_SIZE - ((unsigned long int)(oper.indata + prev_ix) & ~PAGE_MASK);
cop->tfrm_op.indata[0].iov_base = (unsigned char*)page_address(inpages[0]) + ((unsigned long int)(oper.indata + prev_ix) & ~PAGE_MASK);
tmplen -= cop->tfrm_op.indata[0].iov_len;
for (i = 1; i<noinpages; i++){
cop->tfrm_op.indata[i].iov_len = tmplen < PAGE_SIZE ? tmplen : PAGE_SIZE;
cop->tfrm_op.indata[i].iov_base = (unsigned char*)page_address(inpages[i]);
tmplen -= PAGE_SIZE;
}
} else {
cop->tfrm_op.indata[0].iov_len = oper.inlen - prev_ix;
cop->tfrm_op.indata[0].iov_base = (unsigned char*)page_address(inpages[0]) + ((unsigned long int)(oper.indata + prev_ix) & ~PAGE_MASK);
}
iovlen = nooutpages + 6;
pageoffset = oper.do_cipher ? ((unsigned long int)oper.cipher_outdata & ~PAGE_MASK) : 0;
next_ix = next_cfg_change_ix(&oper, prev_ix);
if (prev_ix == next_ix){
DEBUG_API(printk("cryptocop_ioctl_process: length configuration broken.\n"));
err = -EINVAL;
goto error_cleanup;
}
while (prev_ix != next_ix){
end_digest = end_csum = cipher_active = digest_active = csum_active = 0;
descs[desc_ix].cfg = NULL;
descs[desc_ix].length = next_ix - prev_ix;
if (oper.do_cipher && (oper.cipher_start < next_ix) && (prev_ix < (oper.cipher_start + oper.cipher_len))) {
dcfgs[dcfg_ix].tid = CRYPTOCOP_IOCTL_CIPHER_TID;
dcfgs[dcfg_ix].src = cryptocop_source_dma;
cipher_active = 1;
if (next_ix == (oper.cipher_start + oper.cipher_len)){
cipher_done = 1;
dcfgs[dcfg_ix].last = 1;
} else {
dcfgs[dcfg_ix].last = 0;
}
dcfgs[dcfg_ix].next = descs[desc_ix].cfg;
descs[desc_ix].cfg = &dcfgs[dcfg_ix];
++dcfg_ix;
}
if (oper.do_digest && (oper.digest_start < next_ix) && (prev_ix < (oper.digest_start + oper.digest_len))) {
digest_active = 1;
dcfgs[dcfg_ix].tid = CRYPTOCOP_IOCTL_DIGEST_TID;
dcfgs[dcfg_ix].src = cryptocop_source_dma;
if (next_ix == (oper.digest_start + oper.digest_len)){
assert(!digest_done);
digest_done = 1;
dcfgs[dcfg_ix].last = 1;
} else {
dcfgs[dcfg_ix].last = 0;
}
dcfgs[dcfg_ix].next = descs[desc_ix].cfg;
descs[desc_ix].cfg = &dcfgs[dcfg_ix];
++dcfg_ix;
}
if (oper.do_csum && (oper.csum_start < next_ix) && (prev_ix < (oper.csum_start + oper.csum_len))){
csum_active = 1;
dcfgs[dcfg_ix].tid = CRYPTOCOP_IOCTL_CSUM_TID;
dcfgs[dcfg_ix].src = cryptocop_source_dma;
if (next_ix == (oper.csum_start + oper.csum_len)){
csum_done = 1;
dcfgs[dcfg_ix].last = 1;
} else {
dcfgs[dcfg_ix].last = 0;
}
dcfgs[dcfg_ix].next = descs[desc_ix].cfg;
descs[desc_ix].cfg = &dcfgs[dcfg_ix];
++dcfg_ix;
}
if (!descs[desc_ix].cfg){
DEBUG_API(printk("cryptocop_ioctl_process: data segment %d (%d to %d) had no active transforms\n", desc_ix, prev_ix, next_ix));
err = -EINVAL;
goto error_cleanup;
}
descs[desc_ix].next = &(descs[desc_ix]) + 1;
++desc_ix;
prev_ix = next_ix;
next_ix = next_cfg_change_ix(&oper, prev_ix);
}
if (desc_ix > 0){
descs[desc_ix-1].next = NULL;
} else {
descs[0].next = NULL;
}
if (oper.do_digest) {
DEBUG(printk("cryptocop_ioctl_process: mapping %d byte digest output to iovec %d\n", digest_length, iovix));
cop->tfrm_op.outdata[iovix].iov_base = digest_result;
cop->tfrm_op.outdata[iovix].iov_len = digest_length;
++iovix;
}
if (oper.do_csum) {
DEBUG(printk("cryptocop_ioctl_process: mapping 2 byte csum output to iovec %d\n", iovix));
cop->tfrm_op.outdata[iovix].iov_base = csum_result;
cop->tfrm_op.outdata[iovix].iov_len = 2;
++iovix;
}
if (oper.do_cipher) {
if (!map_pages_to_iovec(cop->tfrm_op.outdata, iovlen, &iovix, outpages, nooutpages, &pageix, &pageoffset, oper.cipher_outlen)){
DEBUG_API(printk("cryptocop_ioctl_process: failed to map pages to iovec.\n"));
err = -ENOSYS;
goto error_cleanup;
}
}
DEBUG(printk("cryptocop_ioctl_process: setting cop->tfrm_op.outcount %d\n", iovix));
cop->tfrm_op.outcount = iovix;
assert(iovix <= (nooutpages + 6));
cop->sid = oper.ses_id;
cop->tfrm_op.desc = &descs[0];
DEBUG(printk("cryptocop_ioctl_process: inserting job, cb_data=0x%p\n", cop->cb_data));
if ((err = cryptocop_job_queue_insert_user_job(cop)) != 0) {
DEBUG_API(printk("cryptocop_ioctl_process: insert job %d\n", err));
err = -EINVAL;
goto error_cleanup;
}
DEBUG(printk("cryptocop_ioctl_process: begin wait for result\n"));
wait_event(cryptocop_ioc_process_wq, (jc->processed != 0));
DEBUG(printk("cryptocop_ioctl_process: end wait for result\n"));
if (!jc->processed){
printk(KERN_WARNING "cryptocop_ioctl_process: job not processed at completion\n");
err = -EIO;
goto error_cleanup;
}
DEBUG(printk("cryptocop_ioctl_process: operation_status = %d\n", cop->operation_status));
if (cop->operation_status == 0){
if (oper.do_digest){
DEBUG(printk("cryptocop_ioctl_process: copy %d bytes digest to user\n", digest_length));
err = copy_to_user((unsigned char*)crp_oper + offsetof(struct strcop_crypto_op, digest), digest_result, digest_length);
if (0 != err){
DEBUG_API(printk("cryptocop_ioctl_process: copy_to_user, digest length %d, err %d\n", digest_length, err));
err = -EFAULT;
goto error_cleanup;
}
}
if (oper.do_csum){
DEBUG(printk("cryptocop_ioctl_process: copy 2 bytes checksum to user\n"));
err = copy_to_user((unsigned char*)crp_oper + offsetof(struct strcop_crypto_op, csum), csum_result, 2);
if (0 != err){
DEBUG_API(printk("cryptocop_ioctl_process: copy_to_user, csum, err %d\n", err));
err = -EFAULT;
goto error_cleanup;
}
}
err = 0;
} else {
DEBUG(printk("cryptocop_ioctl_process: returning err = operation_status = %d\n", cop->operation_status));
err = cop->operation_status;
}
error_cleanup:
for (i = 0; i < noinpages; i++){
put_page(inpages[i]);
}
for (i = 0; i < nooutpages; i++){
int spdl_err;
spdl_err = set_page_dirty_lock(outpages[i]);
DEBUG(if (spdl_err < 0)printk("cryptocop_ioctl_process: set_page_dirty_lock returned %d\n", spdl_err));
}
for (i = 0; i < nooutpages; i++){
put_page(outpages[i]);
}
kfree(digest_result);
kfree(inpages);
kfree(outpages);
if (cop){
kfree(cop->tfrm_op.indata);
kfree(cop->tfrm_op.outdata);
kfree(cop);
}
kfree(jc);
DEBUG(print_lock_status());
return err;
}
static int cryptocop_ioctl_create_session(struct inode *inode, struct file *filp, unsigned int cmd, unsigned long arg)
{
cryptocop_session_id sid;
int err;
struct cryptocop_private *dev;
struct strcop_session_op *sess_op = (struct strcop_session_op *)arg;
struct strcop_session_op sop;
struct cryptocop_transform_init *tis = NULL;
struct cryptocop_transform_init ti_cipher = {0};
struct cryptocop_transform_init ti_digest = {0};
struct cryptocop_transform_init ti_csum = {0};
if (!access_ok(VERIFY_WRITE, sess_op, sizeof(struct strcop_session_op)))
return -EFAULT;
err = copy_from_user(&sop, sess_op, sizeof(struct strcop_session_op));
if (err) return -EFAULT;
if (sop.cipher != cryptocop_cipher_none) {
if (!access_ok(VERIFY_READ, sop.key, sop.keylen)) return -EFAULT;
}
DEBUG(printk("cryptocop_ioctl_create_session, sess_op:\n"));
DEBUG(printk("\tcipher:%d\n"
"\tcipher_mode:%d\n"
"\tdigest:%d\n"
"\tcsum:%d\n",
(int)sop.cipher,
(int)sop.cmode,
(int)sop.digest,
(int)sop.csum));
if (sop.cipher != cryptocop_cipher_none){
switch (sop.cipher){
case cryptocop_cipher_des:
ti_cipher.alg = cryptocop_alg_des;
break;
case cryptocop_cipher_3des:
ti_cipher.alg = cryptocop_alg_3des;
break;
case cryptocop_cipher_aes:
ti_cipher.alg = cryptocop_alg_aes;
break;
default:
DEBUG_API(printk("create session, bad cipher algorithm %d\n", sop.cipher));
return -EINVAL;
};
DEBUG(printk("setting cipher transform %d\n", ti_cipher.alg));
copy_from_user(ti_cipher.key, sop.key, sop.keylen/8);
ti_cipher.keylen = sop.keylen;
switch (sop.cmode){
case cryptocop_cipher_mode_cbc:
case cryptocop_cipher_mode_ecb:
ti_cipher.cipher_mode = sop.cmode;
break;
default:
DEBUG_API(printk("create session, bad cipher mode %d\n", sop.cmode));
return -EINVAL;
}
DEBUG(printk("cryptocop_ioctl_create_session: setting CBC mode %d\n", ti_cipher.cipher_mode));
switch (sop.des3_mode){
case cryptocop_3des_eee:
case cryptocop_3des_eed:
case cryptocop_3des_ede:
case cryptocop_3des_edd:
case cryptocop_3des_dee:
case cryptocop_3des_ded:
case cryptocop_3des_dde:
case cryptocop_3des_ddd:
ti_cipher.tdes_mode = sop.des3_mode;
break;
default:
DEBUG_API(printk("create session, bad 3DES mode %d\n", sop.des3_mode));
return -EINVAL;
}
ti_cipher.tid = CRYPTOCOP_IOCTL_CIPHER_TID;
ti_cipher.next = tis;
tis = &ti_cipher;
}
if (sop.digest != cryptocop_digest_none){
DEBUG(printk("setting digest transform\n"));
switch (sop.digest){
case cryptocop_digest_md5:
ti_digest.alg = cryptocop_alg_md5;
break;
case cryptocop_digest_sha1:
ti_digest.alg = cryptocop_alg_sha1;
break;
default:
DEBUG_API(printk("create session, bad digest algorithm %d\n", sop.digest));
return -EINVAL;
}
ti_digest.tid = CRYPTOCOP_IOCTL_DIGEST_TID;
ti_digest.next = tis;
tis = &ti_digest;
}
if (sop.csum != cryptocop_csum_none){
DEBUG(printk("setting csum transform\n"));
switch (sop.csum){
case cryptocop_csum_le:
case cryptocop_csum_be:
ti_csum.csum_mode = sop.csum;
break;
default:
DEBUG_API(printk("create session, bad checksum algorithm %d\n", sop.csum));
return -EINVAL;
}
ti_csum.alg = cryptocop_alg_csum;
ti_csum.tid = CRYPTOCOP_IOCTL_CSUM_TID;
ti_csum.next = tis;
tis = &ti_csum;
}
dev = kmalloc(sizeof(struct cryptocop_private), GFP_KERNEL);
if (!dev){
DEBUG_API(printk("create session, alloc dev\n"));
return -ENOMEM;
}
err = cryptocop_new_session(&sid, tis, GFP_KERNEL);
DEBUG({ if (err) printk("create session, cryptocop_new_session %d\n", err);});
if (err) {
kfree(dev);
return err;
}
sess_op->ses_id = sid;
dev->sid = sid;
dev->next = filp->private_data;
filp->private_data = dev;
return 0;
}
static long cryptocop_ioctl_unlocked(struct inode *inode,
struct file *filp, unsigned int cmd, unsigned long arg)
{
int err = 0;
if (_IOC_TYPE(cmd) != ETRAXCRYPTOCOP_IOCTYPE) {
DEBUG_API(printk("cryptocop_ioctl: wrong type\n"));
return -ENOTTY;
}
if (_IOC_NR(cmd) > CRYPTOCOP_IO_MAXNR){
return -ENOTTY;
}
if (_IOC_DIR(cmd) & _IOC_READ)
err = !access_ok(VERIFY_WRITE, (void *)arg, _IOC_SIZE(cmd));
else if (_IOC_DIR(cmd) & _IOC_WRITE)
err = !access_ok(VERIFY_READ, (void *)arg, _IOC_SIZE(cmd));
if (err) return -EFAULT;
switch (cmd) {
case CRYPTOCOP_IO_CREATE_SESSION:
return cryptocop_ioctl_create_session(inode, filp, cmd, arg);
case CRYPTOCOP_IO_CLOSE_SESSION:
return cryptocop_ioctl_close_session(inode, filp, cmd, arg);
case CRYPTOCOP_IO_PROCESS_OP:
return cryptocop_ioctl_process(inode, filp, cmd, arg);
default:
DEBUG_API(printk("cryptocop_ioctl: unknown command\n"));
return -ENOTTY;
}
return 0;
}
static long
cryptocop_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
long ret;
mutex_lock(&cryptocop_mutex);
ret = cryptocop_ioctl_unlocked(file_inode(filp), filp, cmd, arg);
mutex_unlock(&cryptocop_mutex);
return ret;
}
static void print_dma_descriptors(struct cryptocop_int_operation *iop)
{
struct cryptocop_dma_desc *cdesc_out = iop->cdesc_out;
struct cryptocop_dma_desc *cdesc_in = iop->cdesc_in;
int i;
printk("print_dma_descriptors start\n");
printk("iop:\n");
printk("\tsid: 0x%lld\n", iop->sid);
printk("\tcdesc_out: 0x%p\n", iop->cdesc_out);
printk("\tcdesc_in: 0x%p\n", iop->cdesc_in);
printk("\tddesc_out: 0x%p\n", iop->ddesc_out);
printk("\tddesc_in: 0x%p\n", iop->ddesc_in);
printk("\niop->ctx_out: 0x%p phys: 0x%p\n", &iop->ctx_out, (char*)virt_to_phys(&iop->ctx_out));
printk("\tnext: 0x%p\n"
"\tsaved_data: 0x%p\n"
"\tsaved_data_buf: 0x%p\n",
iop->ctx_out.next,
iop->ctx_out.saved_data,
iop->ctx_out.saved_data_buf);
printk("\niop->ctx_in: 0x%p phys: 0x%p\n", &iop->ctx_in, (char*)virt_to_phys(&iop->ctx_in));
printk("\tnext: 0x%p\n"
"\tsaved_data: 0x%p\n"
"\tsaved_data_buf: 0x%p\n",
iop->ctx_in.next,
iop->ctx_in.saved_data,
iop->ctx_in.saved_data_buf);
i = 0;
while (cdesc_out) {
dma_descr_data *td;
printk("cdesc_out %d, desc=0x%p\n", i, cdesc_out->dma_descr);
printk("\n\tvirt_to_phys(desc): 0x%p\n", (char*)virt_to_phys(cdesc_out->dma_descr));
td = cdesc_out->dma_descr;
printk("\n\tbuf: 0x%p\n"
"\tafter: 0x%p\n"
"\tmd: 0x%04x\n"
"\tnext: 0x%p\n",
td->buf,
td->after,
td->md,
td->next);
printk("flags:\n"
"\twait:\t%d\n"
"\teol:\t%d\n"
"\touteop:\t%d\n"
"\tineop:\t%d\n"
"\tintr:\t%d\n",
td->wait,
td->eol,
td->out_eop,
td->in_eop,
td->intr);
cdesc_out = cdesc_out->next;
i++;
}
i = 0;
while (cdesc_in) {
dma_descr_data *td;
printk("cdesc_in %d, desc=0x%p\n", i, cdesc_in->dma_descr);
printk("\n\tvirt_to_phys(desc): 0x%p\n", (char*)virt_to_phys(cdesc_in->dma_descr));
td = cdesc_in->dma_descr;
printk("\n\tbuf: 0x%p\n"
"\tafter: 0x%p\n"
"\tmd: 0x%04x\n"
"\tnext: 0x%p\n",
td->buf,
td->after,
td->md,
td->next);
printk("flags:\n"
"\twait:\t%d\n"
"\teol:\t%d\n"
"\touteop:\t%d\n"
"\tineop:\t%d\n"
"\tintr:\t%d\n",
td->wait,
td->eol,
td->out_eop,
td->in_eop,
td->intr);
cdesc_in = cdesc_in->next;
i++;
}
printk("print_dma_descriptors end\n");
}
static void print_strcop_crypto_op(struct strcop_crypto_op *cop)
{
printk("print_strcop_crypto_op, 0x%p\n", cop);
printk("indata=0x%p\n"
"inlen=%d\n"
"do_cipher=%d\n"
"decrypt=%d\n"
"cipher_explicit=%d\n"
"cipher_start=%d\n"
"cipher_len=%d\n"
"outdata=0x%p\n"
"outlen=%d\n",
cop->indata,
cop->inlen,
cop->do_cipher,
cop->decrypt,
cop->cipher_explicit,
cop->cipher_start,
cop->cipher_len,
cop->cipher_outdata,
cop->cipher_outlen);
printk("do_digest=%d\n"
"digest_start=%d\n"
"digest_len=%d\n",
cop->do_digest,
cop->digest_start,
cop->digest_len);
printk("do_csum=%d\n"
"csum_start=%d\n"
"csum_len=%d\n",
cop->do_csum,
cop->csum_start,
cop->csum_len);
}
static void print_cryptocop_operation(struct cryptocop_operation *cop)
{
struct cryptocop_desc *d;
struct cryptocop_tfrm_cfg *tc;
struct cryptocop_desc_cfg *dc;
int i;
printk("print_cryptocop_operation, cop=0x%p\n\n", cop);
printk("sid: %lld\n", cop->sid);
printk("operation_status=%d\n"
"use_dmalists=%d\n"
"in_interrupt=%d\n"
"fast_callback=%d\n",
cop->operation_status,
cop->use_dmalists,
cop->in_interrupt,
cop->fast_callback);
if (cop->use_dmalists){
print_user_dma_lists(&cop->list_op);
} else {
printk("cop->tfrm_op\n"
"tfrm_cfg=0x%p\n"
"desc=0x%p\n"
"indata=0x%p\n"
"incount=%d\n"
"inlen=%d\n"
"outdata=0x%p\n"
"outcount=%d\n"
"outlen=%d\n\n",
cop->tfrm_op.tfrm_cfg,
cop->tfrm_op.desc,
cop->tfrm_op.indata,
cop->tfrm_op.incount,
cop->tfrm_op.inlen,
cop->tfrm_op.outdata,
cop->tfrm_op.outcount,
cop->tfrm_op.outlen);
tc = cop->tfrm_op.tfrm_cfg;
while (tc){
printk("tfrm_cfg, 0x%p\n"
"tid=%d\n"
"flags=%d\n"
"inject_ix=%d\n"
"next=0x%p\n",
tc,
tc->tid,
tc->flags,
tc->inject_ix,
tc->next);
tc = tc->next;
}
d = cop->tfrm_op.desc;
while (d){
printk("\n======================desc, 0x%p\n"
"length=%d\n"
"cfg=0x%p\n"
"next=0x%p\n",
d,
d->length,
d->cfg,
d->next);
dc = d->cfg;
while (dc){
printk("=========desc_cfg, 0x%p\n"
"tid=%d\n"
"src=%d\n"
"last=%d\n"
"next=0x%p\n",
dc,
dc->tid,
dc->src,
dc->last,
dc->next);
dc = dc->next;
}
d = d->next;
}
printk("\n====iniov\n");
for (i = 0; i < cop->tfrm_op.incount; i++){
printk("indata[%d]\n"
"base=0x%p\n"
"len=%d\n",
i,
cop->tfrm_op.indata[i].iov_base,
cop->tfrm_op.indata[i].iov_len);
}
printk("\n====outiov\n");
for (i = 0; i < cop->tfrm_op.outcount; i++){
printk("outdata[%d]\n"
"base=0x%p\n"
"len=%d\n",
i,
cop->tfrm_op.outdata[i].iov_base,
cop->tfrm_op.outdata[i].iov_len);
}
}
printk("------------end print_cryptocop_operation\n");
}
static void print_user_dma_lists(struct cryptocop_dma_list_operation *dma_op)
{
dma_descr_data *dd;
int i;
printk("print_user_dma_lists, dma_op=0x%p\n", dma_op);
printk("out_data_buf = 0x%p, phys_to_virt(out_data_buf) = 0x%p\n", dma_op->out_data_buf, phys_to_virt((unsigned long int)dma_op->out_data_buf));
printk("in_data_buf = 0x%p, phys_to_virt(in_data_buf) = 0x%p\n", dma_op->in_data_buf, phys_to_virt((unsigned long int)dma_op->in_data_buf));
printk("##############outlist\n");
dd = phys_to_virt((unsigned long int)dma_op->outlist);
i = 0;
while (dd != NULL) {
printk("#%d phys_to_virt(desc) 0x%p\n", i, dd);
printk("\n\tbuf: 0x%p\n"
"\tafter: 0x%p\n"
"\tmd: 0x%04x\n"
"\tnext: 0x%p\n",
dd->buf,
dd->after,
dd->md,
dd->next);
printk("flags:\n"
"\twait:\t%d\n"
"\teol:\t%d\n"
"\touteop:\t%d\n"
"\tineop:\t%d\n"
"\tintr:\t%d\n",
dd->wait,
dd->eol,
dd->out_eop,
dd->in_eop,
dd->intr);
if (dd->eol)
dd = NULL;
else
dd = phys_to_virt((unsigned long int)dd->next);
++i;
}
printk("##############inlist\n");
dd = phys_to_virt((unsigned long int)dma_op->inlist);
i = 0;
while (dd != NULL) {
printk("#%d phys_to_virt(desc) 0x%p\n", i, dd);
printk("\n\tbuf: 0x%p\n"
"\tafter: 0x%p\n"
"\tmd: 0x%04x\n"
"\tnext: 0x%p\n",
dd->buf,
dd->after,
dd->md,
dd->next);
printk("flags:\n"
"\twait:\t%d\n"
"\teol:\t%d\n"
"\touteop:\t%d\n"
"\tineop:\t%d\n"
"\tintr:\t%d\n",
dd->wait,
dd->eol,
dd->out_eop,
dd->in_eop,
dd->intr);
if (dd->eol)
dd = NULL;
else
dd = phys_to_virt((unsigned long int)dd->next);
++i;
}
}
static void print_lock_status(void)
{
printk("**********************print_lock_status\n");
printk("cryptocop_completed_jobs_lock %d\n", spin_is_locked(&cryptocop_completed_jobs_lock));
printk("cryptocop_job_queue_lock %d\n", spin_is_locked(&cryptocop_job_queue_lock));
printk("descr_pool_lock %d\n", spin_is_locked(&descr_pool_lock));
printk("cryptocop_sessions_lock %d\n", spin_is_locked(cryptocop_sessions_lock));
printk("running_job_lock %d\n", spin_is_locked(running_job_lock));
printk("cryptocop_process_lock %d\n", spin_is_locked(cryptocop_process_lock));
}
static int init_stream_coprocessor(void)
{
int err;
int i;
static int initialized = 0;
if (initialized)
return 0;
initialized = 1;
printk("ETRAX FS stream co-processor driver v0.01, (c) 2003 Axis Communications AB\n");
err = register_chrdev(CRYPTOCOP_MAJOR, cryptocop_name, &cryptocop_fops);
if (err < 0) {
printk(KERN_ERR "stream co-processor: could not get major number.\n");
return err;
}
err = init_cryptocop();
if (err) {
(void)unregister_chrdev(CRYPTOCOP_MAJOR, cryptocop_name);
return err;
}
err = cryptocop_job_queue_init();
if (err) {
release_cryptocop();
(void)unregister_chrdev(CRYPTOCOP_MAJOR, cryptocop_name);
return err;
}
for (i = 0; i < CRYPTOCOP_DESCRIPTOR_POOL_SIZE - 1; i++) {
descr_pool[i].from_pool = 1;
descr_pool[i].next = &descr_pool[i + 1];
}
descr_pool[i].from_pool = 1;
descr_pool[i].next = NULL;
descr_pool_free_list = &descr_pool[0];
descr_pool_no_free = CRYPTOCOP_DESCRIPTOR_POOL_SIZE;
spin_lock_init(&cryptocop_completed_jobs_lock);
spin_lock_init(&cryptocop_job_queue_lock);
spin_lock_init(&descr_pool_lock);
spin_lock_init(&cryptocop_sessions_lock);
spin_lock_init(&running_job_lock);
spin_lock_init(&cryptocop_process_lock);
cryptocop_sessions = NULL;
next_sid = 1;
cryptocop_running_job = NULL;
printk("stream co-processor: init done.\n");
return 0;
}
static void __exit exit_stream_coprocessor(void)
{
release_cryptocop();
cryptocop_job_queue_close();
}
