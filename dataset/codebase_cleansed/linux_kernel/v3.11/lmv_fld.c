int lmv_fld_lookup(struct lmv_obd *lmv,
const struct lu_fid *fid,
mdsno_t *mds)
{
int rc;
ENTRY;
LASSERTF((fid_seq_in_fldb(fid_seq(fid)) ||
fid_seq_is_local_file(fid_seq(fid))) &&
fid_is_sane(fid), DFID" is insane!\n", PFID(fid));
rc = fld_client_lookup(&lmv->lmv_fld, fid_seq(fid), mds,
LU_SEQ_RANGE_MDT, NULL);
if (rc) {
CERROR("Error while looking for mds number. Seq "LPX64
", err = %d\n", fid_seq(fid), rc);
RETURN(rc);
}
CDEBUG(D_INODE, "FLD lookup got mds #%x for fid="DFID"\n",
*mds, PFID(fid));
if (*mds >= lmv->desc.ld_tgt_count) {
CERROR("FLD lookup got invalid mds #%x (max: %x) "
"for fid="DFID"\n", *mds, lmv->desc.ld_tgt_count,
PFID(fid));
rc = -EINVAL;
}
RETURN(rc);
}
