static void audit_cb(struct audit_buffer *ab, void *va)\r\n{\r\nstruct common_audit_data *sa = va;\r\nif (sa->aad->iface.target) {\r\nstruct aa_profile *name = sa->aad->iface.target;\r\naudit_log_format(ab, " name=");\r\naudit_log_untrustedstring(ab, name->base.hname);\r\n}\r\nif (sa->aad->iface.pos)\r\naudit_log_format(ab, " offset=%ld", sa->aad->iface.pos);\r\n}\r\nstatic int audit_iface(struct aa_profile *new, const char *name,\r\nconst char *info, struct aa_ext *e, int error)\r\n{\r\nstruct aa_profile *profile = __aa_current_profile();\r\nstruct common_audit_data sa;\r\nstruct apparmor_audit_data aad = {0,};\r\nsa.type = LSM_AUDIT_DATA_NONE;\r\nsa.aad = &aad;\r\nif (e)\r\naad.iface.pos = e->pos - e->start;\r\naad.iface.target = new;\r\naad.name = name;\r\naad.info = info;\r\naad.error = error;\r\nreturn aa_audit(AUDIT_APPARMOR_STATUS, profile, GFP_KERNEL, &sa,\r\naudit_cb);\r\n}\r\nstatic bool inbounds(struct aa_ext *e, size_t size)\r\n{\r\nreturn (size <= e->end - e->pos);\r\n}\r\nstatic size_t unpack_u16_chunk(struct aa_ext *e, char **chunk)\r\n{\r\nsize_t size = 0;\r\nif (!inbounds(e, sizeof(u16)))\r\nreturn 0;\r\nsize = le16_to_cpu(get_unaligned((u16 *) e->pos));\r\ne->pos += sizeof(u16);\r\nif (!inbounds(e, size))\r\nreturn 0;\r\n*chunk = e->pos;\r\ne->pos += size;\r\nreturn size;\r\n}\r\nstatic bool unpack_X(struct aa_ext *e, enum aa_code code)\r\n{\r\nif (!inbounds(e, 1))\r\nreturn 0;\r\nif (*(u8 *) e->pos != code)\r\nreturn 0;\r\ne->pos++;\r\nreturn 1;\r\n}\r\nstatic bool unpack_nameX(struct aa_ext *e, enum aa_code code, const char *name)\r\n{\r\nvoid *pos = e->pos;\r\nif (unpack_X(e, AA_NAME)) {\r\nchar *tag = NULL;\r\nsize_t size = unpack_u16_chunk(e, &tag);\r\nif (name && (!size || strcmp(name, tag)))\r\ngoto fail;\r\n} else if (name) {\r\ngoto fail;\r\n}\r\nif (unpack_X(e, code))\r\nreturn 1;\r\nfail:\r\ne->pos = pos;\r\nreturn 0;\r\n}\r\nstatic bool unpack_u32(struct aa_ext *e, u32 *data, const char *name)\r\n{\r\nif (unpack_nameX(e, AA_U32, name)) {\r\nif (!inbounds(e, sizeof(u32)))\r\nreturn 0;\r\nif (data)\r\n*data = le32_to_cpu(get_unaligned((u32 *) e->pos));\r\ne->pos += sizeof(u32);\r\nreturn 1;\r\n}\r\nreturn 0;\r\n}\r\nstatic bool unpack_u64(struct aa_ext *e, u64 *data, const char *name)\r\n{\r\nif (unpack_nameX(e, AA_U64, name)) {\r\nif (!inbounds(e, sizeof(u64)))\r\nreturn 0;\r\nif (data)\r\n*data = le64_to_cpu(get_unaligned((u64 *) e->pos));\r\ne->pos += sizeof(u64);\r\nreturn 1;\r\n}\r\nreturn 0;\r\n}\r\nstatic size_t unpack_array(struct aa_ext *e, const char *name)\r\n{\r\nif (unpack_nameX(e, AA_ARRAY, name)) {\r\nint size;\r\nif (!inbounds(e, sizeof(u16)))\r\nreturn 0;\r\nsize = (int)le16_to_cpu(get_unaligned((u16 *) e->pos));\r\ne->pos += sizeof(u16);\r\nreturn size;\r\n}\r\nreturn 0;\r\n}\r\nstatic size_t unpack_blob(struct aa_ext *e, char **blob, const char *name)\r\n{\r\nif (unpack_nameX(e, AA_BLOB, name)) {\r\nu32 size;\r\nif (!inbounds(e, sizeof(u32)))\r\nreturn 0;\r\nsize = le32_to_cpu(get_unaligned((u32 *) e->pos));\r\ne->pos += sizeof(u32);\r\nif (inbounds(e, (size_t) size)) {\r\n*blob = e->pos;\r\ne->pos += size;\r\nreturn size;\r\n}\r\n}\r\nreturn 0;\r\n}\r\nstatic int unpack_str(struct aa_ext *e, const char **string, const char *name)\r\n{\r\nchar *src_str;\r\nsize_t size = 0;\r\nvoid *pos = e->pos;\r\n*string = NULL;\r\nif (unpack_nameX(e, AA_STRING, name)) {\r\nsize = unpack_u16_chunk(e, &src_str);\r\nif (size) {\r\nif (src_str[size - 1] != 0)\r\ngoto fail;\r\n*string = src_str;\r\n}\r\n}\r\nreturn size;\r\nfail:\r\ne->pos = pos;\r\nreturn 0;\r\n}\r\nstatic int unpack_strdup(struct aa_ext *e, char **string, const char *name)\r\n{\r\nconst char *tmp;\r\nvoid *pos = e->pos;\r\nint res = unpack_str(e, &tmp, name);\r\n*string = NULL;\r\nif (!res)\r\nreturn 0;\r\n*string = kmemdup(tmp, res, GFP_KERNEL);\r\nif (!*string) {\r\ne->pos = pos;\r\nreturn 0;\r\n}\r\nreturn res;\r\n}\r\nstatic bool verify_accept(struct aa_dfa *dfa, int flags)\r\n{\r\nint i;\r\nfor (i = 0; i < dfa->tables[YYTD_ID_ACCEPT]->td_lolen; i++) {\r\nint mode = ACCEPT_TABLE(dfa)[i];\r\nif (mode & ~DFA_VALID_PERM_MASK)\r\nreturn 0;\r\nif (ACCEPT_TABLE2(dfa)[i] & ~DFA_VALID_PERM2_MASK)\r\nreturn 0;\r\n}\r\nreturn 1;\r\n}\r\nstatic struct aa_dfa *unpack_dfa(struct aa_ext *e)\r\n{\r\nchar *blob = NULL;\r\nsize_t size;\r\nstruct aa_dfa *dfa = NULL;\r\nsize = unpack_blob(e, &blob, "aadfa");\r\nif (size) {\r\nsize_t sz = blob - (char *) e->start -\r\n((e->pos - e->start) & 7);\r\nsize_t pad = ALIGN(sz, 8) - sz;\r\nint flags = TO_ACCEPT1_FLAG(YYTD_DATA32) |\r\nTO_ACCEPT2_FLAG(YYTD_DATA32);\r\nif (aa_g_paranoid_load)\r\nflags |= DFA_FLAG_VERIFY_STATES;\r\ndfa = aa_dfa_unpack(blob + pad, size - pad, flags);\r\nif (IS_ERR(dfa))\r\nreturn dfa;\r\nif (!verify_accept(dfa, flags))\r\ngoto fail;\r\n}\r\nreturn dfa;\r\nfail:\r\naa_put_dfa(dfa);\r\nreturn ERR_PTR(-EPROTO);\r\n}\r\nstatic bool unpack_trans_table(struct aa_ext *e, struct aa_profile *profile)\r\n{\r\nvoid *pos = e->pos;\r\nif (unpack_nameX(e, AA_STRUCT, "xtable")) {\r\nint i, size;\r\nsize = unpack_array(e, NULL);\r\nif (size > 16 - 4)\r\ngoto fail;\r\nprofile->file.trans.table = kzalloc(sizeof(char *) * size,\r\nGFP_KERNEL);\r\nif (!profile->file.trans.table)\r\ngoto fail;\r\nprofile->file.trans.size = size;\r\nfor (i = 0; i < size; i++) {\r\nchar *str;\r\nint c, j, size2 = unpack_strdup(e, &str, NULL);\r\nif (!size2)\r\ngoto fail;\r\nprofile->file.trans.table[i] = str;\r\nif (isspace(*str))\r\ngoto fail;\r\nfor (c = j = 0; j < size2 - 2; j++) {\r\nif (!str[j])\r\nc++;\r\n}\r\nif (*str == ':') {\r\nif (c != 1)\r\ngoto fail;\r\nif (!str[1])\r\ngoto fail;\r\n} else if (c)\r\ngoto fail;\r\n}\r\nif (!unpack_nameX(e, AA_ARRAYEND, NULL))\r\ngoto fail;\r\nif (!unpack_nameX(e, AA_STRUCTEND, NULL))\r\ngoto fail;\r\n}\r\nreturn 1;\r\nfail:\r\naa_free_domain_entries(&profile->file.trans);\r\ne->pos = pos;\r\nreturn 0;\r\n}\r\nstatic bool unpack_rlimits(struct aa_ext *e, struct aa_profile *profile)\r\n{\r\nvoid *pos = e->pos;\r\nif (unpack_nameX(e, AA_STRUCT, "rlimits")) {\r\nint i, size;\r\nu32 tmp = 0;\r\nif (!unpack_u32(e, &tmp, NULL))\r\ngoto fail;\r\nprofile->rlimits.mask = tmp;\r\nsize = unpack_array(e, NULL);\r\nif (size > RLIM_NLIMITS)\r\ngoto fail;\r\nfor (i = 0; i < size; i++) {\r\nu64 tmp2 = 0;\r\nint a = aa_map_resource(i);\r\nif (!unpack_u64(e, &tmp2, NULL))\r\ngoto fail;\r\nprofile->rlimits.limits[a].rlim_max = tmp2;\r\n}\r\nif (!unpack_nameX(e, AA_ARRAYEND, NULL))\r\ngoto fail;\r\nif (!unpack_nameX(e, AA_STRUCTEND, NULL))\r\ngoto fail;\r\n}\r\nreturn 1;\r\nfail:\r\ne->pos = pos;\r\nreturn 0;\r\n}\r\nstatic struct aa_profile *unpack_profile(struct aa_ext *e)\r\n{\r\nstruct aa_profile *profile = NULL;\r\nconst char *name = NULL;\r\nint i, error = -EPROTO;\r\nkernel_cap_t tmpcap;\r\nu32 tmp;\r\nif (!unpack_nameX(e, AA_STRUCT, "profile"))\r\ngoto fail;\r\nif (!unpack_str(e, &name, NULL))\r\ngoto fail;\r\nprofile = aa_alloc_profile(name);\r\nif (!profile)\r\nreturn ERR_PTR(-ENOMEM);\r\n(void) unpack_str(e, &profile->rename, "rename");\r\n(void) unpack_str(e, &profile->attach, "attach");\r\nprofile->xmatch = unpack_dfa(e);\r\nif (IS_ERR(profile->xmatch)) {\r\nerror = PTR_ERR(profile->xmatch);\r\nprofile->xmatch = NULL;\r\ngoto fail;\r\n}\r\nif (profile->xmatch) {\r\nif (!unpack_u32(e, &tmp, NULL))\r\ngoto fail;\r\nprofile->xmatch_len = tmp;\r\n}\r\nif (!unpack_nameX(e, AA_STRUCT, "flags"))\r\ngoto fail;\r\nif (!unpack_u32(e, &tmp, NULL))\r\ngoto fail;\r\nif (tmp & PACKED_FLAG_HAT)\r\nprofile->flags |= PFLAG_HAT;\r\nif (!unpack_u32(e, &tmp, NULL))\r\ngoto fail;\r\nif (tmp == PACKED_MODE_COMPLAIN)\r\nprofile->mode = APPARMOR_COMPLAIN;\r\nelse if (tmp == PACKED_MODE_KILL)\r\nprofile->mode = APPARMOR_KILL;\r\nelse if (tmp == PACKED_MODE_UNCONFINED)\r\nprofile->mode = APPARMOR_UNCONFINED;\r\nif (!unpack_u32(e, &tmp, NULL))\r\ngoto fail;\r\nif (tmp)\r\nprofile->audit = AUDIT_ALL;\r\nif (!unpack_nameX(e, AA_STRUCTEND, NULL))\r\ngoto fail;\r\nif (unpack_u32(e, &profile->path_flags, "path_flags"))\r\nprofile->path_flags |= profile->flags & PFLAG_MEDIATE_DELETED;\r\nelse\r\nprofile->path_flags = PFLAG_MEDIATE_DELETED;\r\nif (!unpack_u32(e, &(profile->caps.allow.cap[0]), NULL))\r\ngoto fail;\r\nif (!unpack_u32(e, &(profile->caps.audit.cap[0]), NULL))\r\ngoto fail;\r\nif (!unpack_u32(e, &(profile->caps.quiet.cap[0]), NULL))\r\ngoto fail;\r\nif (!unpack_u32(e, &tmpcap.cap[0], NULL))\r\ngoto fail;\r\nif (unpack_nameX(e, AA_STRUCT, "caps64")) {\r\nif (!unpack_u32(e, &(profile->caps.allow.cap[1]), NULL))\r\ngoto fail;\r\nif (!unpack_u32(e, &(profile->caps.audit.cap[1]), NULL))\r\ngoto fail;\r\nif (!unpack_u32(e, &(profile->caps.quiet.cap[1]), NULL))\r\ngoto fail;\r\nif (!unpack_u32(e, &(tmpcap.cap[1]), NULL))\r\ngoto fail;\r\nif (!unpack_nameX(e, AA_STRUCTEND, NULL))\r\ngoto fail;\r\n}\r\nif (unpack_nameX(e, AA_STRUCT, "capsx")) {\r\nif (!unpack_u32(e, &(profile->caps.extended.cap[0]), NULL))\r\ngoto fail;\r\nif (!unpack_u32(e, &(profile->caps.extended.cap[1]), NULL))\r\ngoto fail;\r\nif (!unpack_nameX(e, AA_STRUCTEND, NULL))\r\ngoto fail;\r\n}\r\nif (!unpack_rlimits(e, profile))\r\ngoto fail;\r\nif (unpack_nameX(e, AA_STRUCT, "policydb")) {\r\nprofile->policy.dfa = unpack_dfa(e);\r\nif (IS_ERR(profile->policy.dfa)) {\r\nerror = PTR_ERR(profile->policy.dfa);\r\nprofile->policy.dfa = NULL;\r\ngoto fail;\r\n}\r\nif (!unpack_u32(e, &profile->policy.start[0], "start"))\r\nprofile->policy.start[0] = DFA_START;\r\nfor (i = AA_CLASS_FILE; i <= AA_CLASS_LAST; i++) {\r\nprofile->policy.start[i] =\r\naa_dfa_next(profile->policy.dfa,\r\nprofile->policy.start[0],\r\ni);\r\n}\r\nif (!unpack_nameX(e, AA_STRUCTEND, NULL))\r\ngoto fail;\r\n}\r\nprofile->file.dfa = unpack_dfa(e);\r\nif (IS_ERR(profile->file.dfa)) {\r\nerror = PTR_ERR(profile->file.dfa);\r\nprofile->file.dfa = NULL;\r\ngoto fail;\r\n}\r\nif (!unpack_u32(e, &profile->file.start, "dfa_start"))\r\nprofile->file.start = DFA_START;\r\nif (!unpack_trans_table(e, profile))\r\ngoto fail;\r\nif (!unpack_nameX(e, AA_STRUCTEND, NULL))\r\ngoto fail;\r\nreturn profile;\r\nfail:\r\nif (profile)\r\nname = NULL;\r\nelse if (!name)\r\nname = "unknown";\r\naudit_iface(profile, name, "failed to unpack profile", e, error);\r\naa_free_profile(profile);\r\nreturn ERR_PTR(error);\r\n}\r\nstatic int verify_header(struct aa_ext *e, int required, const char **ns)\r\n{\r\nint error = -EPROTONOSUPPORT;\r\nconst char *name = NULL;\r\n*ns = NULL;\r\nif (!unpack_u32(e, &e->version, "version")) {\r\nif (required) {\r\naudit_iface(NULL, NULL, "invalid profile format", e,\r\nerror);\r\nreturn error;\r\n}\r\nif (e->version != 5) {\r\naudit_iface(NULL, NULL, "unsupported interface version",\r\ne, error);\r\nreturn error;\r\n}\r\n}\r\nif (unpack_str(e, &name, "namespace")) {\r\nif (*ns && strcmp(*ns, name))\r\naudit_iface(NULL, NULL, "invalid ns change", e, error);\r\nelse if (!*ns)\r\n*ns = name;\r\n}\r\nreturn 0;\r\n}\r\nstatic bool verify_xindex(int xindex, int table_size)\r\n{\r\nint index, xtype;\r\nxtype = xindex & AA_X_TYPE_MASK;\r\nindex = xindex & AA_X_INDEX_MASK;\r\nif (xtype == AA_X_TABLE && index > table_size)\r\nreturn 0;\r\nreturn 1;\r\n}\r\nstatic bool verify_dfa_xindex(struct aa_dfa *dfa, int table_size)\r\n{\r\nint i;\r\nfor (i = 0; i < dfa->tables[YYTD_ID_ACCEPT]->td_lolen; i++) {\r\nif (!verify_xindex(dfa_user_xindex(dfa, i), table_size))\r\nreturn 0;\r\nif (!verify_xindex(dfa_other_xindex(dfa, i), table_size))\r\nreturn 0;\r\n}\r\nreturn 1;\r\n}\r\nstatic int verify_profile(struct aa_profile *profile)\r\n{\r\nif (aa_g_paranoid_load) {\r\nif (profile->file.dfa &&\r\n!verify_dfa_xindex(profile->file.dfa,\r\nprofile->file.trans.size)) {\r\naudit_iface(profile, NULL, "Invalid named transition",\r\nNULL, -EPROTO);\r\nreturn -EPROTO;\r\n}\r\n}\r\nreturn 0;\r\n}\r\nvoid aa_load_ent_free(struct aa_load_ent *ent)\r\n{\r\nif (ent) {\r\naa_put_profile(ent->rename);\r\naa_put_profile(ent->old);\r\naa_put_profile(ent->new);\r\nkzfree(ent);\r\n}\r\n}\r\nstruct aa_load_ent *aa_load_ent_alloc(void)\r\n{\r\nstruct aa_load_ent *ent = kzalloc(sizeof(*ent), GFP_KERNEL);\r\nif (ent)\r\nINIT_LIST_HEAD(&ent->list);\r\nreturn ent;\r\n}\r\nint aa_unpack(void *udata, size_t size, struct list_head *lh, const char **ns)\r\n{\r\nstruct aa_load_ent *tmp, *ent;\r\nstruct aa_profile *profile = NULL;\r\nint error;\r\nstruct aa_ext e = {\r\n.start = udata,\r\n.end = udata + size,\r\n.pos = udata,\r\n};\r\n*ns = NULL;\r\nwhile (e.pos < e.end) {\r\nvoid *start;\r\nerror = verify_header(&e, e.pos == e.start, ns);\r\nif (error)\r\ngoto fail;\r\nstart = e.pos;\r\nprofile = unpack_profile(&e);\r\nif (IS_ERR(profile)) {\r\nerror = PTR_ERR(profile);\r\ngoto fail;\r\n}\r\nerror = verify_profile(profile);\r\nif (error)\r\ngoto fail_profile;\r\nerror = aa_calc_profile_hash(profile, e.version, start,\r\ne.pos - start);\r\nif (error)\r\ngoto fail_profile;\r\nent = aa_load_ent_alloc();\r\nif (!ent) {\r\nerror = -ENOMEM;\r\ngoto fail_profile;\r\n}\r\nent->new = profile;\r\nlist_add_tail(&ent->list, lh);\r\n}\r\nreturn 0;\r\nfail_profile:\r\naa_put_profile(profile);\r\nfail:\r\nlist_for_each_entry_safe(ent, tmp, lh, list) {\r\nlist_del_init(&ent->list);\r\naa_load_ent_free(ent);\r\n}\r\nreturn error;\r\n}
