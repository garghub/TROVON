void init_rsa_pub_desc(u32 *desc, struct rsa_pub_pdb *pdb)
{
init_job_desc_pdb(desc, 0, sizeof(*pdb));
append_cmd(desc, pdb->sgf);
append_ptr(desc, pdb->f_dma);
append_ptr(desc, pdb->g_dma);
append_ptr(desc, pdb->n_dma);
append_ptr(desc, pdb->e_dma);
append_cmd(desc, pdb->f_len);
append_operation(desc, OP_TYPE_UNI_PROTOCOL | OP_PCLID_RSAENC_PUBKEY);
}
void init_rsa_priv_f1_desc(u32 *desc, struct rsa_priv_f1_pdb *pdb)
{
init_job_desc_pdb(desc, 0, sizeof(*pdb));
append_cmd(desc, pdb->sgf);
append_ptr(desc, pdb->g_dma);
append_ptr(desc, pdb->f_dma);
append_ptr(desc, pdb->n_dma);
append_ptr(desc, pdb->d_dma);
append_operation(desc, OP_TYPE_UNI_PROTOCOL | OP_PCLID_RSADEC_PRVKEY |
RSA_PRIV_KEY_FRM_1);
}
