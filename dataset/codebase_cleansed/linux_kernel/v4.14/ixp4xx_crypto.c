static inline dma_addr_t crypt_virt2phys(struct crypt_ctl *virt)\r\n{\r\nreturn crypt_phys + (virt - crypt_virt) * sizeof(struct crypt_ctl);\r\n}\r\nstatic inline struct crypt_ctl *crypt_phys2virt(dma_addr_t phys)\r\n{\r\nreturn crypt_virt + (phys - crypt_phys) / sizeof(struct crypt_ctl);\r\n}\r\nstatic inline u32 cipher_cfg_enc(struct crypto_tfm *tfm)\r\n{\r\nreturn container_of(tfm->__crt_alg, struct ixp_alg,crypto)->cfg_enc;\r\n}\r\nstatic inline u32 cipher_cfg_dec(struct crypto_tfm *tfm)\r\n{\r\nreturn container_of(tfm->__crt_alg, struct ixp_alg,crypto)->cfg_dec;\r\n}\r\nstatic inline const struct ix_hash_algo *ix_hash(struct crypto_tfm *tfm)\r\n{\r\nreturn container_of(tfm->__crt_alg, struct ixp_alg, crypto)->hash;\r\n}\r\nstatic int setup_crypt_desc(void)\r\n{\r\nstruct device *dev = &pdev->dev;\r\nBUILD_BUG_ON(sizeof(struct crypt_ctl) != 64);\r\ncrypt_virt = dma_alloc_coherent(dev,\r\nNPE_QLEN * sizeof(struct crypt_ctl),\r\n&crypt_phys, GFP_ATOMIC);\r\nif (!crypt_virt)\r\nreturn -ENOMEM;\r\nmemset(crypt_virt, 0, NPE_QLEN * sizeof(struct crypt_ctl));\r\nreturn 0;\r\n}\r\nstatic struct crypt_ctl *get_crypt_desc(void)\r\n{\r\nint i;\r\nstatic int idx = 0;\r\nunsigned long flags;\r\nspin_lock_irqsave(&desc_lock, flags);\r\nif (unlikely(!crypt_virt))\r\nsetup_crypt_desc();\r\nif (unlikely(!crypt_virt)) {\r\nspin_unlock_irqrestore(&desc_lock, flags);\r\nreturn NULL;\r\n}\r\ni = idx;\r\nif (crypt_virt[i].ctl_flags == CTL_FLAG_UNUSED) {\r\nif (++idx >= NPE_QLEN)\r\nidx = 0;\r\ncrypt_virt[i].ctl_flags = CTL_FLAG_USED;\r\nspin_unlock_irqrestore(&desc_lock, flags);\r\nreturn crypt_virt +i;\r\n} else {\r\nspin_unlock_irqrestore(&desc_lock, flags);\r\nreturn NULL;\r\n}\r\n}\r\nstatic struct crypt_ctl *get_crypt_desc_emerg(void)\r\n{\r\nint i;\r\nstatic int idx = NPE_QLEN;\r\nstruct crypt_ctl *desc;\r\nunsigned long flags;\r\ndesc = get_crypt_desc();\r\nif (desc)\r\nreturn desc;\r\nif (unlikely(!crypt_virt))\r\nreturn NULL;\r\nspin_lock_irqsave(&emerg_lock, flags);\r\ni = idx;\r\nif (crypt_virt[i].ctl_flags == CTL_FLAG_UNUSED) {\r\nif (++idx >= NPE_QLEN_TOTAL)\r\nidx = NPE_QLEN;\r\ncrypt_virt[i].ctl_flags = CTL_FLAG_USED;\r\nspin_unlock_irqrestore(&emerg_lock, flags);\r\nreturn crypt_virt +i;\r\n} else {\r\nspin_unlock_irqrestore(&emerg_lock, flags);\r\nreturn NULL;\r\n}\r\n}\r\nstatic void free_buf_chain(struct device *dev, struct buffer_desc *buf,u32 phys)\r\n{\r\nwhile (buf) {\r\nstruct buffer_desc *buf1;\r\nu32 phys1;\r\nbuf1 = buf->next;\r\nphys1 = buf->phys_next;\r\ndma_unmap_single(dev, buf->phys_next, buf->buf_len, buf->dir);\r\ndma_pool_free(buffer_pool, buf, phys);\r\nbuf = buf1;\r\nphys = phys1;\r\n}\r\n}\r\nstatic void finish_scattered_hmac(struct crypt_ctl *crypt)\r\n{\r\nstruct aead_request *req = crypt->data.aead_req;\r\nstruct aead_ctx *req_ctx = aead_request_ctx(req);\r\nstruct crypto_aead *tfm = crypto_aead_reqtfm(req);\r\nint authsize = crypto_aead_authsize(tfm);\r\nint decryptlen = req->assoclen + req->cryptlen - authsize;\r\nif (req_ctx->encrypt) {\r\nscatterwalk_map_and_copy(req_ctx->hmac_virt,\r\nreq->dst, decryptlen, authsize, 1);\r\n}\r\ndma_pool_free(buffer_pool, req_ctx->hmac_virt, crypt->icv_rev_aes);\r\n}\r\nstatic void one_packet(dma_addr_t phys)\r\n{\r\nstruct device *dev = &pdev->dev;\r\nstruct crypt_ctl *crypt;\r\nstruct ixp_ctx *ctx;\r\nint failed;\r\nfailed = phys & 0x1 ? -EBADMSG : 0;\r\nphys &= ~0x3;\r\ncrypt = crypt_phys2virt(phys);\r\nswitch (crypt->ctl_flags & CTL_FLAG_MASK) {\r\ncase CTL_FLAG_PERFORM_AEAD: {\r\nstruct aead_request *req = crypt->data.aead_req;\r\nstruct aead_ctx *req_ctx = aead_request_ctx(req);\r\nfree_buf_chain(dev, req_ctx->src, crypt->src_buf);\r\nfree_buf_chain(dev, req_ctx->dst, crypt->dst_buf);\r\nif (req_ctx->hmac_virt) {\r\nfinish_scattered_hmac(crypt);\r\n}\r\nreq->base.complete(&req->base, failed);\r\nbreak;\r\n}\r\ncase CTL_FLAG_PERFORM_ABLK: {\r\nstruct ablkcipher_request *req = crypt->data.ablk_req;\r\nstruct ablk_ctx *req_ctx = ablkcipher_request_ctx(req);\r\nif (req_ctx->dst) {\r\nfree_buf_chain(dev, req_ctx->dst, crypt->dst_buf);\r\n}\r\nfree_buf_chain(dev, req_ctx->src, crypt->src_buf);\r\nreq->base.complete(&req->base, failed);\r\nbreak;\r\n}\r\ncase CTL_FLAG_GEN_ICV:\r\nctx = crypto_tfm_ctx(crypt->data.tfm);\r\ndma_pool_free(ctx_pool, crypt->regist_ptr,\r\ncrypt->regist_buf->phys_addr);\r\ndma_pool_free(buffer_pool, crypt->regist_buf, crypt->src_buf);\r\nif (atomic_dec_and_test(&ctx->configuring))\r\ncomplete(&ctx->completion);\r\nbreak;\r\ncase CTL_FLAG_GEN_REVAES:\r\nctx = crypto_tfm_ctx(crypt->data.tfm);\r\n*(u32*)ctx->decrypt.npe_ctx &= cpu_to_be32(~CIPH_ENCR);\r\nif (atomic_dec_and_test(&ctx->configuring))\r\ncomplete(&ctx->completion);\r\nbreak;\r\ndefault:\r\nBUG();\r\n}\r\ncrypt->ctl_flags = CTL_FLAG_UNUSED;\r\n}\r\nstatic void irqhandler(void *_unused)\r\n{\r\ntasklet_schedule(&crypto_done_tasklet);\r\n}\r\nstatic void crypto_done_action(unsigned long arg)\r\n{\r\nint i;\r\nfor(i=0; i<4; i++) {\r\ndma_addr_t phys = qmgr_get_entry(RECV_QID);\r\nif (!phys)\r\nreturn;\r\none_packet(phys);\r\n}\r\ntasklet_schedule(&crypto_done_tasklet);\r\n}\r\nstatic int init_ixp_crypto(struct device *dev)\r\n{\r\nint ret = -ENODEV;\r\nu32 msg[2] = { 0, 0 };\r\nif (! ( ~(*IXP4XX_EXP_CFG2) & (IXP4XX_FEATURE_HASH |\r\nIXP4XX_FEATURE_AES | IXP4XX_FEATURE_DES))) {\r\nprintk(KERN_ERR "ixp_crypto: No HW crypto available\n");\r\nreturn ret;\r\n}\r\nnpe_c = npe_request(NPE_ID);\r\nif (!npe_c)\r\nreturn ret;\r\nif (!npe_running(npe_c)) {\r\nret = npe_load_firmware(npe_c, npe_name(npe_c), dev);\r\nif (ret)\r\ngoto npe_release;\r\nif (npe_recv_message(npe_c, msg, "STATUS_MSG"))\r\ngoto npe_error;\r\n} else {\r\nif (npe_send_message(npe_c, msg, "STATUS_MSG"))\r\ngoto npe_error;\r\nif (npe_recv_message(npe_c, msg, "STATUS_MSG"))\r\ngoto npe_error;\r\n}\r\nswitch ((msg[1]>>16) & 0xff) {\r\ncase 3:\r\nprintk(KERN_WARNING "Firmware of %s lacks AES support\n",\r\nnpe_name(npe_c));\r\nsupport_aes = 0;\r\nbreak;\r\ncase 4:\r\ncase 5:\r\nsupport_aes = 1;\r\nbreak;\r\ndefault:\r\nprintk(KERN_ERR "Firmware of %s lacks crypto support\n",\r\nnpe_name(npe_c));\r\nret = -ENODEV;\r\ngoto npe_release;\r\n}\r\nBUILD_BUG_ON(SHA1_DIGEST_SIZE > sizeof(struct buffer_desc));\r\nbuffer_pool = dma_pool_create("buffer", dev,\r\nsizeof(struct buffer_desc), 32, 0);\r\nret = -ENOMEM;\r\nif (!buffer_pool) {\r\ngoto err;\r\n}\r\nctx_pool = dma_pool_create("context", dev,\r\nNPE_CTX_LEN, 16, 0);\r\nif (!ctx_pool) {\r\ngoto err;\r\n}\r\nret = qmgr_request_queue(SEND_QID, NPE_QLEN_TOTAL, 0, 0,\r\n"ixp_crypto:out", NULL);\r\nif (ret)\r\ngoto err;\r\nret = qmgr_request_queue(RECV_QID, NPE_QLEN, 0, 0,\r\n"ixp_crypto:in", NULL);\r\nif (ret) {\r\nqmgr_release_queue(SEND_QID);\r\ngoto err;\r\n}\r\nqmgr_set_irq(RECV_QID, QUEUE_IRQ_SRC_NOT_EMPTY, irqhandler, NULL);\r\ntasklet_init(&crypto_done_tasklet, crypto_done_action, 0);\r\nqmgr_enable_irq(RECV_QID);\r\nreturn 0;\r\nnpe_error:\r\nprintk(KERN_ERR "%s not responding\n", npe_name(npe_c));\r\nret = -EIO;\r\nerr:\r\ndma_pool_destroy(ctx_pool);\r\ndma_pool_destroy(buffer_pool);\r\nnpe_release:\r\nnpe_release(npe_c);\r\nreturn ret;\r\n}\r\nstatic void release_ixp_crypto(struct device *dev)\r\n{\r\nqmgr_disable_irq(RECV_QID);\r\ntasklet_kill(&crypto_done_tasklet);\r\nqmgr_release_queue(SEND_QID);\r\nqmgr_release_queue(RECV_QID);\r\ndma_pool_destroy(ctx_pool);\r\ndma_pool_destroy(buffer_pool);\r\nnpe_release(npe_c);\r\nif (crypt_virt) {\r\ndma_free_coherent(dev,\r\nNPE_QLEN_TOTAL * sizeof( struct crypt_ctl),\r\ncrypt_virt, crypt_phys);\r\n}\r\nreturn;\r\n}\r\nstatic void reset_sa_dir(struct ix_sa_dir *dir)\r\n{\r\nmemset(dir->npe_ctx, 0, NPE_CTX_LEN);\r\ndir->npe_ctx_idx = 0;\r\ndir->npe_mode = 0;\r\n}\r\nstatic int init_sa_dir(struct ix_sa_dir *dir)\r\n{\r\ndir->npe_ctx = dma_pool_alloc(ctx_pool, GFP_KERNEL, &dir->npe_ctx_phys);\r\nif (!dir->npe_ctx) {\r\nreturn -ENOMEM;\r\n}\r\nreset_sa_dir(dir);\r\nreturn 0;\r\n}\r\nstatic void free_sa_dir(struct ix_sa_dir *dir)\r\n{\r\nmemset(dir->npe_ctx, 0, NPE_CTX_LEN);\r\ndma_pool_free(ctx_pool, dir->npe_ctx, dir->npe_ctx_phys);\r\n}\r\nstatic int init_tfm(struct crypto_tfm *tfm)\r\n{\r\nstruct ixp_ctx *ctx = crypto_tfm_ctx(tfm);\r\nint ret;\r\natomic_set(&ctx->configuring, 0);\r\nret = init_sa_dir(&ctx->encrypt);\r\nif (ret)\r\nreturn ret;\r\nret = init_sa_dir(&ctx->decrypt);\r\nif (ret) {\r\nfree_sa_dir(&ctx->encrypt);\r\n}\r\nreturn ret;\r\n}\r\nstatic int init_tfm_ablk(struct crypto_tfm *tfm)\r\n{\r\ntfm->crt_ablkcipher.reqsize = sizeof(struct ablk_ctx);\r\nreturn init_tfm(tfm);\r\n}\r\nstatic int init_tfm_aead(struct crypto_aead *tfm)\r\n{\r\ncrypto_aead_set_reqsize(tfm, sizeof(struct aead_ctx));\r\nreturn init_tfm(crypto_aead_tfm(tfm));\r\n}\r\nstatic void exit_tfm(struct crypto_tfm *tfm)\r\n{\r\nstruct ixp_ctx *ctx = crypto_tfm_ctx(tfm);\r\nfree_sa_dir(&ctx->encrypt);\r\nfree_sa_dir(&ctx->decrypt);\r\n}\r\nstatic void exit_tfm_aead(struct crypto_aead *tfm)\r\n{\r\nexit_tfm(crypto_aead_tfm(tfm));\r\n}\r\nstatic int register_chain_var(struct crypto_tfm *tfm, u8 xpad, u32 target,\r\nint init_len, u32 ctx_addr, const u8 *key, int key_len)\r\n{\r\nstruct ixp_ctx *ctx = crypto_tfm_ctx(tfm);\r\nstruct crypt_ctl *crypt;\r\nstruct buffer_desc *buf;\r\nint i;\r\nu8 *pad;\r\nu32 pad_phys, buf_phys;\r\nBUILD_BUG_ON(NPE_CTX_LEN < HMAC_PAD_BLOCKLEN);\r\npad = dma_pool_alloc(ctx_pool, GFP_KERNEL, &pad_phys);\r\nif (!pad)\r\nreturn -ENOMEM;\r\nbuf = dma_pool_alloc(buffer_pool, GFP_KERNEL, &buf_phys);\r\nif (!buf) {\r\ndma_pool_free(ctx_pool, pad, pad_phys);\r\nreturn -ENOMEM;\r\n}\r\ncrypt = get_crypt_desc_emerg();\r\nif (!crypt) {\r\ndma_pool_free(ctx_pool, pad, pad_phys);\r\ndma_pool_free(buffer_pool, buf, buf_phys);\r\nreturn -EAGAIN;\r\n}\r\nmemcpy(pad, key, key_len);\r\nmemset(pad + key_len, 0, HMAC_PAD_BLOCKLEN - key_len);\r\nfor (i = 0; i < HMAC_PAD_BLOCKLEN; i++) {\r\npad[i] ^= xpad;\r\n}\r\ncrypt->data.tfm = tfm;\r\ncrypt->regist_ptr = pad;\r\ncrypt->regist_buf = buf;\r\ncrypt->auth_offs = 0;\r\ncrypt->auth_len = HMAC_PAD_BLOCKLEN;\r\ncrypt->crypto_ctx = ctx_addr;\r\ncrypt->src_buf = buf_phys;\r\ncrypt->icv_rev_aes = target;\r\ncrypt->mode = NPE_OP_HASH_GEN_ICV;\r\ncrypt->init_len = init_len;\r\ncrypt->ctl_flags |= CTL_FLAG_GEN_ICV;\r\nbuf->next = 0;\r\nbuf->buf_len = HMAC_PAD_BLOCKLEN;\r\nbuf->pkt_len = 0;\r\nbuf->phys_addr = pad_phys;\r\natomic_inc(&ctx->configuring);\r\nqmgr_put_entry(SEND_QID, crypt_virt2phys(crypt));\r\nBUG_ON(qmgr_stat_overflow(SEND_QID));\r\nreturn 0;\r\n}\r\nstatic int setup_auth(struct crypto_tfm *tfm, int encrypt, unsigned authsize,\r\nconst u8 *key, int key_len, unsigned digest_len)\r\n{\r\nu32 itarget, otarget, npe_ctx_addr;\r\nunsigned char *cinfo;\r\nint init_len, ret = 0;\r\nu32 cfgword;\r\nstruct ix_sa_dir *dir;\r\nstruct ixp_ctx *ctx = crypto_tfm_ctx(tfm);\r\nconst struct ix_hash_algo *algo;\r\ndir = encrypt ? &ctx->encrypt : &ctx->decrypt;\r\ncinfo = dir->npe_ctx + dir->npe_ctx_idx;\r\nalgo = ix_hash(tfm);\r\ncfgword = algo->cfgword | ( authsize << 6);\r\n#ifndef __ARMEB__\r\ncfgword ^= 0xAA000000;\r\n#endif\r\n*(u32*)cinfo = cpu_to_be32(cfgword);\r\ncinfo += sizeof(cfgword);\r\nmemcpy(cinfo, algo->icv, digest_len);\r\ncinfo += digest_len;\r\nitarget = dir->npe_ctx_phys + dir->npe_ctx_idx\r\n+ sizeof(algo->cfgword);\r\notarget = itarget + digest_len;\r\ninit_len = cinfo - (dir->npe_ctx + dir->npe_ctx_idx);\r\nnpe_ctx_addr = dir->npe_ctx_phys + dir->npe_ctx_idx;\r\ndir->npe_ctx_idx += init_len;\r\ndir->npe_mode |= NPE_OP_HASH_ENABLE;\r\nif (!encrypt)\r\ndir->npe_mode |= NPE_OP_HASH_VERIFY;\r\nret = register_chain_var(tfm, HMAC_OPAD_VALUE, otarget,\r\ninit_len, npe_ctx_addr, key, key_len);\r\nif (ret)\r\nreturn ret;\r\nreturn register_chain_var(tfm, HMAC_IPAD_VALUE, itarget,\r\ninit_len, npe_ctx_addr, key, key_len);\r\n}\r\nstatic int gen_rev_aes_key(struct crypto_tfm *tfm)\r\n{\r\nstruct crypt_ctl *crypt;\r\nstruct ixp_ctx *ctx = crypto_tfm_ctx(tfm);\r\nstruct ix_sa_dir *dir = &ctx->decrypt;\r\ncrypt = get_crypt_desc_emerg();\r\nif (!crypt) {\r\nreturn -EAGAIN;\r\n}\r\n*(u32*)dir->npe_ctx |= cpu_to_be32(CIPH_ENCR);\r\ncrypt->data.tfm = tfm;\r\ncrypt->crypt_offs = 0;\r\ncrypt->crypt_len = AES_BLOCK128;\r\ncrypt->src_buf = 0;\r\ncrypt->crypto_ctx = dir->npe_ctx_phys;\r\ncrypt->icv_rev_aes = dir->npe_ctx_phys + sizeof(u32);\r\ncrypt->mode = NPE_OP_ENC_GEN_KEY;\r\ncrypt->init_len = dir->npe_ctx_idx;\r\ncrypt->ctl_flags |= CTL_FLAG_GEN_REVAES;\r\natomic_inc(&ctx->configuring);\r\nqmgr_put_entry(SEND_QID, crypt_virt2phys(crypt));\r\nBUG_ON(qmgr_stat_overflow(SEND_QID));\r\nreturn 0;\r\n}\r\nstatic int setup_cipher(struct crypto_tfm *tfm, int encrypt,\r\nconst u8 *key, int key_len)\r\n{\r\nu8 *cinfo;\r\nu32 cipher_cfg;\r\nu32 keylen_cfg = 0;\r\nstruct ix_sa_dir *dir;\r\nstruct ixp_ctx *ctx = crypto_tfm_ctx(tfm);\r\nu32 *flags = &tfm->crt_flags;\r\ndir = encrypt ? &ctx->encrypt : &ctx->decrypt;\r\ncinfo = dir->npe_ctx;\r\nif (encrypt) {\r\ncipher_cfg = cipher_cfg_enc(tfm);\r\ndir->npe_mode |= NPE_OP_CRYPT_ENCRYPT;\r\n} else {\r\ncipher_cfg = cipher_cfg_dec(tfm);\r\n}\r\nif (cipher_cfg & MOD_AES) {\r\nswitch (key_len) {\r\ncase 16: keylen_cfg = MOD_AES128; break;\r\ncase 24: keylen_cfg = MOD_AES192; break;\r\ncase 32: keylen_cfg = MOD_AES256; break;\r\ndefault:\r\n*flags |= CRYPTO_TFM_RES_BAD_KEY_LEN;\r\nreturn -EINVAL;\r\n}\r\ncipher_cfg |= keylen_cfg;\r\n} else if (cipher_cfg & MOD_3DES) {\r\nconst u32 *K = (const u32 *)key;\r\nif (unlikely(!((K[0] ^ K[2]) | (K[1] ^ K[3])) ||\r\n!((K[2] ^ K[4]) | (K[3] ^ K[5]))))\r\n{\r\n*flags |= CRYPTO_TFM_RES_BAD_KEY_SCHED;\r\nreturn -EINVAL;\r\n}\r\n} else {\r\nu32 tmp[DES_EXPKEY_WORDS];\r\nif (des_ekey(tmp, key) == 0) {\r\n*flags |= CRYPTO_TFM_RES_WEAK_KEY;\r\n}\r\n}\r\n*(u32*)cinfo = cpu_to_be32(cipher_cfg);\r\ncinfo += sizeof(cipher_cfg);\r\nmemcpy(cinfo, key, key_len);\r\nif (key_len < DES3_EDE_KEY_SIZE && !(cipher_cfg & MOD_AES)) {\r\nmemset(cinfo + key_len, 0, DES3_EDE_KEY_SIZE -key_len);\r\nkey_len = DES3_EDE_KEY_SIZE;\r\n}\r\ndir->npe_ctx_idx = sizeof(cipher_cfg) + key_len;\r\ndir->npe_mode |= NPE_OP_CRYPT_ENABLE;\r\nif ((cipher_cfg & MOD_AES) && !encrypt) {\r\nreturn gen_rev_aes_key(tfm);\r\n}\r\nreturn 0;\r\n}\r\nstatic struct buffer_desc *chainup_buffers(struct device *dev,\r\nstruct scatterlist *sg, unsigned nbytes,\r\nstruct buffer_desc *buf, gfp_t flags,\r\nenum dma_data_direction dir)\r\n{\r\nfor (; nbytes > 0; sg = sg_next(sg)) {\r\nunsigned len = min(nbytes, sg->length);\r\nstruct buffer_desc *next_buf;\r\nu32 next_buf_phys;\r\nvoid *ptr;\r\nnbytes -= len;\r\nptr = sg_virt(sg);\r\nnext_buf = dma_pool_alloc(buffer_pool, flags, &next_buf_phys);\r\nif (!next_buf) {\r\nbuf = NULL;\r\nbreak;\r\n}\r\nsg_dma_address(sg) = dma_map_single(dev, ptr, len, dir);\r\nbuf->next = next_buf;\r\nbuf->phys_next = next_buf_phys;\r\nbuf = next_buf;\r\nbuf->phys_addr = sg_dma_address(sg);\r\nbuf->buf_len = len;\r\nbuf->dir = dir;\r\n}\r\nbuf->next = NULL;\r\nbuf->phys_next = 0;\r\nreturn buf;\r\n}\r\nstatic int ablk_setkey(struct crypto_ablkcipher *tfm, const u8 *key,\r\nunsigned int key_len)\r\n{\r\nstruct ixp_ctx *ctx = crypto_ablkcipher_ctx(tfm);\r\nu32 *flags = &tfm->base.crt_flags;\r\nint ret;\r\ninit_completion(&ctx->completion);\r\natomic_inc(&ctx->configuring);\r\nreset_sa_dir(&ctx->encrypt);\r\nreset_sa_dir(&ctx->decrypt);\r\nctx->encrypt.npe_mode = NPE_OP_HMAC_DISABLE;\r\nctx->decrypt.npe_mode = NPE_OP_HMAC_DISABLE;\r\nret = setup_cipher(&tfm->base, 0, key, key_len);\r\nif (ret)\r\ngoto out;\r\nret = setup_cipher(&tfm->base, 1, key, key_len);\r\nif (ret)\r\ngoto out;\r\nif (*flags & CRYPTO_TFM_RES_WEAK_KEY) {\r\nif (*flags & CRYPTO_TFM_REQ_WEAK_KEY) {\r\nret = -EINVAL;\r\n} else {\r\n*flags &= ~CRYPTO_TFM_RES_WEAK_KEY;\r\n}\r\n}\r\nout:\r\nif (!atomic_dec_and_test(&ctx->configuring))\r\nwait_for_completion(&ctx->completion);\r\nreturn ret;\r\n}\r\nstatic int ablk_rfc3686_setkey(struct crypto_ablkcipher *tfm, const u8 *key,\r\nunsigned int key_len)\r\n{\r\nstruct ixp_ctx *ctx = crypto_ablkcipher_ctx(tfm);\r\nif (key_len < CTR_RFC3686_NONCE_SIZE)\r\nreturn -EINVAL;\r\nmemcpy(ctx->nonce, key + (key_len - CTR_RFC3686_NONCE_SIZE),\r\nCTR_RFC3686_NONCE_SIZE);\r\nkey_len -= CTR_RFC3686_NONCE_SIZE;\r\nreturn ablk_setkey(tfm, key, key_len);\r\n}\r\nstatic int ablk_perform(struct ablkcipher_request *req, int encrypt)\r\n{\r\nstruct crypto_ablkcipher *tfm = crypto_ablkcipher_reqtfm(req);\r\nstruct ixp_ctx *ctx = crypto_ablkcipher_ctx(tfm);\r\nunsigned ivsize = crypto_ablkcipher_ivsize(tfm);\r\nstruct ix_sa_dir *dir;\r\nstruct crypt_ctl *crypt;\r\nunsigned int nbytes = req->nbytes;\r\nenum dma_data_direction src_direction = DMA_BIDIRECTIONAL;\r\nstruct ablk_ctx *req_ctx = ablkcipher_request_ctx(req);\r\nstruct buffer_desc src_hook;\r\nstruct device *dev = &pdev->dev;\r\ngfp_t flags = req->base.flags & CRYPTO_TFM_REQ_MAY_SLEEP ?\r\nGFP_KERNEL : GFP_ATOMIC;\r\nif (qmgr_stat_full(SEND_QID))\r\nreturn -EAGAIN;\r\nif (atomic_read(&ctx->configuring))\r\nreturn -EAGAIN;\r\ndir = encrypt ? &ctx->encrypt : &ctx->decrypt;\r\ncrypt = get_crypt_desc();\r\nif (!crypt)\r\nreturn -ENOMEM;\r\ncrypt->data.ablk_req = req;\r\ncrypt->crypto_ctx = dir->npe_ctx_phys;\r\ncrypt->mode = dir->npe_mode;\r\ncrypt->init_len = dir->npe_ctx_idx;\r\ncrypt->crypt_offs = 0;\r\ncrypt->crypt_len = nbytes;\r\nBUG_ON(ivsize && !req->info);\r\nmemcpy(crypt->iv, req->info, ivsize);\r\nif (req->src != req->dst) {\r\nstruct buffer_desc dst_hook;\r\ncrypt->mode |= NPE_OP_NOT_IN_PLACE;\r\nreq_ctx->dst = NULL;\r\nif (!chainup_buffers(dev, req->dst, nbytes, &dst_hook,\r\nflags, DMA_FROM_DEVICE))\r\ngoto free_buf_dest;\r\nsrc_direction = DMA_TO_DEVICE;\r\nreq_ctx->dst = dst_hook.next;\r\ncrypt->dst_buf = dst_hook.phys_next;\r\n} else {\r\nreq_ctx->dst = NULL;\r\n}\r\nreq_ctx->src = NULL;\r\nif (!chainup_buffers(dev, req->src, nbytes, &src_hook,\r\nflags, src_direction))\r\ngoto free_buf_src;\r\nreq_ctx->src = src_hook.next;\r\ncrypt->src_buf = src_hook.phys_next;\r\ncrypt->ctl_flags |= CTL_FLAG_PERFORM_ABLK;\r\nqmgr_put_entry(SEND_QID, crypt_virt2phys(crypt));\r\nBUG_ON(qmgr_stat_overflow(SEND_QID));\r\nreturn -EINPROGRESS;\r\nfree_buf_src:\r\nfree_buf_chain(dev, req_ctx->src, crypt->src_buf);\r\nfree_buf_dest:\r\nif (req->src != req->dst) {\r\nfree_buf_chain(dev, req_ctx->dst, crypt->dst_buf);\r\n}\r\ncrypt->ctl_flags = CTL_FLAG_UNUSED;\r\nreturn -ENOMEM;\r\n}\r\nstatic int ablk_encrypt(struct ablkcipher_request *req)\r\n{\r\nreturn ablk_perform(req, 1);\r\n}\r\nstatic int ablk_decrypt(struct ablkcipher_request *req)\r\n{\r\nreturn ablk_perform(req, 0);\r\n}\r\nstatic int ablk_rfc3686_crypt(struct ablkcipher_request *req)\r\n{\r\nstruct crypto_ablkcipher *tfm = crypto_ablkcipher_reqtfm(req);\r\nstruct ixp_ctx *ctx = crypto_ablkcipher_ctx(tfm);\r\nu8 iv[CTR_RFC3686_BLOCK_SIZE];\r\nu8 *info = req->info;\r\nint ret;\r\nmemcpy(iv, ctx->nonce, CTR_RFC3686_NONCE_SIZE);\r\nmemcpy(iv + CTR_RFC3686_NONCE_SIZE, info, CTR_RFC3686_IV_SIZE);\r\n*(__be32 *)(iv + CTR_RFC3686_NONCE_SIZE + CTR_RFC3686_IV_SIZE) =\r\ncpu_to_be32(1);\r\nreq->info = iv;\r\nret = ablk_perform(req, 1);\r\nreq->info = info;\r\nreturn ret;\r\n}\r\nstatic int aead_perform(struct aead_request *req, int encrypt,\r\nint cryptoffset, int eff_cryptlen, u8 *iv)\r\n{\r\nstruct crypto_aead *tfm = crypto_aead_reqtfm(req);\r\nstruct ixp_ctx *ctx = crypto_aead_ctx(tfm);\r\nunsigned ivsize = crypto_aead_ivsize(tfm);\r\nunsigned authsize = crypto_aead_authsize(tfm);\r\nstruct ix_sa_dir *dir;\r\nstruct crypt_ctl *crypt;\r\nunsigned int cryptlen;\r\nstruct buffer_desc *buf, src_hook;\r\nstruct aead_ctx *req_ctx = aead_request_ctx(req);\r\nstruct device *dev = &pdev->dev;\r\ngfp_t flags = req->base.flags & CRYPTO_TFM_REQ_MAY_SLEEP ?\r\nGFP_KERNEL : GFP_ATOMIC;\r\nenum dma_data_direction src_direction = DMA_BIDIRECTIONAL;\r\nunsigned int lastlen;\r\nif (qmgr_stat_full(SEND_QID))\r\nreturn -EAGAIN;\r\nif (atomic_read(&ctx->configuring))\r\nreturn -EAGAIN;\r\nif (encrypt) {\r\ndir = &ctx->encrypt;\r\ncryptlen = req->cryptlen;\r\n} else {\r\ndir = &ctx->decrypt;\r\ncryptlen = req->cryptlen -authsize;\r\neff_cryptlen -= authsize;\r\n}\r\ncrypt = get_crypt_desc();\r\nif (!crypt)\r\nreturn -ENOMEM;\r\ncrypt->data.aead_req = req;\r\ncrypt->crypto_ctx = dir->npe_ctx_phys;\r\ncrypt->mode = dir->npe_mode;\r\ncrypt->init_len = dir->npe_ctx_idx;\r\ncrypt->crypt_offs = cryptoffset;\r\ncrypt->crypt_len = eff_cryptlen;\r\ncrypt->auth_offs = 0;\r\ncrypt->auth_len = req->assoclen + cryptlen;\r\nBUG_ON(ivsize && !req->iv);\r\nmemcpy(crypt->iv, req->iv, ivsize);\r\nbuf = chainup_buffers(dev, req->src, crypt->auth_len,\r\n&src_hook, flags, src_direction);\r\nreq_ctx->src = src_hook.next;\r\ncrypt->src_buf = src_hook.phys_next;\r\nif (!buf)\r\ngoto free_buf_src;\r\nlastlen = buf->buf_len;\r\nif (lastlen >= authsize)\r\ncrypt->icv_rev_aes = buf->phys_addr +\r\nbuf->buf_len - authsize;\r\nreq_ctx->dst = NULL;\r\nif (req->src != req->dst) {\r\nstruct buffer_desc dst_hook;\r\ncrypt->mode |= NPE_OP_NOT_IN_PLACE;\r\nsrc_direction = DMA_TO_DEVICE;\r\nbuf = chainup_buffers(dev, req->dst, crypt->auth_len,\r\n&dst_hook, flags, DMA_FROM_DEVICE);\r\nreq_ctx->dst = dst_hook.next;\r\ncrypt->dst_buf = dst_hook.phys_next;\r\nif (!buf)\r\ngoto free_buf_dst;\r\nif (encrypt) {\r\nlastlen = buf->buf_len;\r\nif (lastlen >= authsize)\r\ncrypt->icv_rev_aes = buf->phys_addr +\r\nbuf->buf_len - authsize;\r\n}\r\n}\r\nif (unlikely(lastlen < authsize)) {\r\nreq_ctx->hmac_virt = dma_pool_alloc(buffer_pool, flags,\r\n&crypt->icv_rev_aes);\r\nif (unlikely(!req_ctx->hmac_virt))\r\ngoto free_buf_dst;\r\nif (!encrypt) {\r\nscatterwalk_map_and_copy(req_ctx->hmac_virt,\r\nreq->src, cryptlen, authsize, 0);\r\n}\r\nreq_ctx->encrypt = encrypt;\r\n} else {\r\nreq_ctx->hmac_virt = NULL;\r\n}\r\ncrypt->ctl_flags |= CTL_FLAG_PERFORM_AEAD;\r\nqmgr_put_entry(SEND_QID, crypt_virt2phys(crypt));\r\nBUG_ON(qmgr_stat_overflow(SEND_QID));\r\nreturn -EINPROGRESS;\r\nfree_buf_dst:\r\nfree_buf_chain(dev, req_ctx->dst, crypt->dst_buf);\r\nfree_buf_src:\r\nfree_buf_chain(dev, req_ctx->src, crypt->src_buf);\r\ncrypt->ctl_flags = CTL_FLAG_UNUSED;\r\nreturn -ENOMEM;\r\n}\r\nstatic int aead_setup(struct crypto_aead *tfm, unsigned int authsize)\r\n{\r\nstruct ixp_ctx *ctx = crypto_aead_ctx(tfm);\r\nu32 *flags = &tfm->base.crt_flags;\r\nunsigned digest_len = crypto_aead_maxauthsize(tfm);\r\nint ret;\r\nif (!ctx->enckey_len && !ctx->authkey_len)\r\nreturn 0;\r\ninit_completion(&ctx->completion);\r\natomic_inc(&ctx->configuring);\r\nreset_sa_dir(&ctx->encrypt);\r\nreset_sa_dir(&ctx->decrypt);\r\nret = setup_cipher(&tfm->base, 0, ctx->enckey, ctx->enckey_len);\r\nif (ret)\r\ngoto out;\r\nret = setup_cipher(&tfm->base, 1, ctx->enckey, ctx->enckey_len);\r\nif (ret)\r\ngoto out;\r\nret = setup_auth(&tfm->base, 0, authsize, ctx->authkey,\r\nctx->authkey_len, digest_len);\r\nif (ret)\r\ngoto out;\r\nret = setup_auth(&tfm->base, 1, authsize, ctx->authkey,\r\nctx->authkey_len, digest_len);\r\nif (ret)\r\ngoto out;\r\nif (*flags & CRYPTO_TFM_RES_WEAK_KEY) {\r\nif (*flags & CRYPTO_TFM_REQ_WEAK_KEY) {\r\nret = -EINVAL;\r\ngoto out;\r\n} else {\r\n*flags &= ~CRYPTO_TFM_RES_WEAK_KEY;\r\n}\r\n}\r\nout:\r\nif (!atomic_dec_and_test(&ctx->configuring))\r\nwait_for_completion(&ctx->completion);\r\nreturn ret;\r\n}\r\nstatic int aead_setauthsize(struct crypto_aead *tfm, unsigned int authsize)\r\n{\r\nint max = crypto_aead_maxauthsize(tfm) >> 2;\r\nif ((authsize>>2) < 1 || (authsize>>2) > max || (authsize & 3))\r\nreturn -EINVAL;\r\nreturn aead_setup(tfm, authsize);\r\n}\r\nstatic int aead_setkey(struct crypto_aead *tfm, const u8 *key,\r\nunsigned int keylen)\r\n{\r\nstruct ixp_ctx *ctx = crypto_aead_ctx(tfm);\r\nstruct crypto_authenc_keys keys;\r\nif (crypto_authenc_extractkeys(&keys, key, keylen) != 0)\r\ngoto badkey;\r\nif (keys.authkeylen > sizeof(ctx->authkey))\r\ngoto badkey;\r\nif (keys.enckeylen > sizeof(ctx->enckey))\r\ngoto badkey;\r\nmemcpy(ctx->authkey, keys.authkey, keys.authkeylen);\r\nmemcpy(ctx->enckey, keys.enckey, keys.enckeylen);\r\nctx->authkey_len = keys.authkeylen;\r\nctx->enckey_len = keys.enckeylen;\r\nreturn aead_setup(tfm, crypto_aead_authsize(tfm));\r\nbadkey:\r\ncrypto_aead_set_flags(tfm, CRYPTO_TFM_RES_BAD_KEY_LEN);\r\nreturn -EINVAL;\r\n}\r\nstatic int aead_encrypt(struct aead_request *req)\r\n{\r\nreturn aead_perform(req, 1, req->assoclen, req->cryptlen, req->iv);\r\n}\r\nstatic int aead_decrypt(struct aead_request *req)\r\n{\r\nreturn aead_perform(req, 0, req->assoclen, req->cryptlen, req->iv);\r\n}\r\nstatic int __init ixp_module_init(void)\r\n{\r\nint num = ARRAY_SIZE(ixp4xx_algos);\r\nint i, err;\r\npdev = platform_device_register_full(&ixp_dev_info);\r\nif (IS_ERR(pdev))\r\nreturn PTR_ERR(pdev);\r\nspin_lock_init(&desc_lock);\r\nspin_lock_init(&emerg_lock);\r\nerr = init_ixp_crypto(&pdev->dev);\r\nif (err) {\r\nplatform_device_unregister(pdev);\r\nreturn err;\r\n}\r\nfor (i=0; i< num; i++) {\r\nstruct crypto_alg *cra = &ixp4xx_algos[i].crypto;\r\nif (snprintf(cra->cra_driver_name, CRYPTO_MAX_ALG_NAME,\r\n"%s"IXP_POSTFIX, cra->cra_name) >=\r\nCRYPTO_MAX_ALG_NAME)\r\n{\r\ncontinue;\r\n}\r\nif (!support_aes && (ixp4xx_algos[i].cfg_enc & MOD_AES)) {\r\ncontinue;\r\n}\r\ncra->cra_type = &crypto_ablkcipher_type;\r\ncra->cra_flags = CRYPTO_ALG_TYPE_ABLKCIPHER |\r\nCRYPTO_ALG_KERN_DRIVER_ONLY |\r\nCRYPTO_ALG_ASYNC;\r\nif (!cra->cra_ablkcipher.setkey)\r\ncra->cra_ablkcipher.setkey = ablk_setkey;\r\nif (!cra->cra_ablkcipher.encrypt)\r\ncra->cra_ablkcipher.encrypt = ablk_encrypt;\r\nif (!cra->cra_ablkcipher.decrypt)\r\ncra->cra_ablkcipher.decrypt = ablk_decrypt;\r\ncra->cra_init = init_tfm_ablk;\r\ncra->cra_ctxsize = sizeof(struct ixp_ctx);\r\ncra->cra_module = THIS_MODULE;\r\ncra->cra_alignmask = 3;\r\ncra->cra_priority = 300;\r\ncra->cra_exit = exit_tfm;\r\nif (crypto_register_alg(cra))\r\nprintk(KERN_ERR "Failed to register '%s'\n",\r\ncra->cra_name);\r\nelse\r\nixp4xx_algos[i].registered = 1;\r\n}\r\nfor (i = 0; i < ARRAY_SIZE(ixp4xx_aeads); i++) {\r\nstruct aead_alg *cra = &ixp4xx_aeads[i].crypto;\r\nif (snprintf(cra->base.cra_driver_name, CRYPTO_MAX_ALG_NAME,\r\n"%s"IXP_POSTFIX, cra->base.cra_name) >=\r\nCRYPTO_MAX_ALG_NAME)\r\ncontinue;\r\nif (!support_aes && (ixp4xx_algos[i].cfg_enc & MOD_AES))\r\ncontinue;\r\ncra->base.cra_flags = CRYPTO_ALG_KERN_DRIVER_ONLY |\r\nCRYPTO_ALG_ASYNC;\r\ncra->setkey = aead_setkey;\r\ncra->setauthsize = aead_setauthsize;\r\ncra->encrypt = aead_encrypt;\r\ncra->decrypt = aead_decrypt;\r\ncra->init = init_tfm_aead;\r\ncra->exit = exit_tfm_aead;\r\ncra->base.cra_ctxsize = sizeof(struct ixp_ctx);\r\ncra->base.cra_module = THIS_MODULE;\r\ncra->base.cra_alignmask = 3;\r\ncra->base.cra_priority = 300;\r\nif (crypto_register_aead(cra))\r\nprintk(KERN_ERR "Failed to register '%s'\n",\r\ncra->base.cra_driver_name);\r\nelse\r\nixp4xx_aeads[i].registered = 1;\r\n}\r\nreturn 0;\r\n}\r\nstatic void __exit ixp_module_exit(void)\r\n{\r\nint num = ARRAY_SIZE(ixp4xx_algos);\r\nint i;\r\nfor (i = 0; i < ARRAY_SIZE(ixp4xx_aeads); i++) {\r\nif (ixp4xx_aeads[i].registered)\r\ncrypto_unregister_aead(&ixp4xx_aeads[i].crypto);\r\n}\r\nfor (i=0; i< num; i++) {\r\nif (ixp4xx_algos[i].registered)\r\ncrypto_unregister_alg(&ixp4xx_algos[i].crypto);\r\n}\r\nrelease_ixp_crypto(&pdev->dev);\r\nplatform_device_unregister(pdev);\r\n}
